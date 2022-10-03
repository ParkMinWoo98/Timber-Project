#include "SceneMgr.h"
#include "InputMgr.h"
#include "../Scene/StartScene.h"
#include "../Scene/ModeScene.h"
#include "../Scene/SingleCharacterScene.h"
#include "../Scene/SinglePlayScene.h"
#include "../Scene/DuelCharacterScene.h"
#include "../Scene/DuelPlayScene.h"

SceneMgr::SceneMgr(RenderWindow& window, Time& dt)
	:currentScene(Scenes::Start), dt(dt)
{
	sceneList.push_back(new StartScene(window));
	sceneList.push_back(new ModeScene(window));
	sceneList.push_back(new SingleCharacterScene(window));
	sceneList.push_back(new SinglePlayScene(window, dt));
	sceneList.push_back(new DuelCharacterScene(window));
	sceneList.push_back(new DuelPlayScene(window, dt));
}

SceneMgr::~SceneMgr()
{
}

void SceneMgr::Init()
{
	currentScene = Scenes::Start;
	sceneList[(int)currentScene]->Init();
}

void SceneMgr::Release()
{
}

void SceneMgr::Update()
{
	sceneList[(int)currentScene]->Update();
	if (sceneList[(int)currentScene]->GetSceneEnd())
	{
		sceneList[(int)currentScene]->SetSceneEnd(false);
		sceneList[(int)currentScene]->BgmEnd();
		if (currentScene == Scenes::Mode)
		{
			if (sceneList[(int)currentScene]->GetMode() == Modes::single)
				currentScene = Scenes::SingleCharacter;
			else if (sceneList[(int)currentScene]->GetMode() == Modes::duel)
				currentScene = Scenes::DuelCharacter;
		}
		else
		{
			currentScene = (Scenes)((int)currentScene + 1);
		}

		if (currentScene == Scenes::SinglePlay || currentScene == Scenes::DuelPlay)
			sceneList[(int)currentScene]->SetCharacterScene(sceneList[(int)currentScene - 1]->GetCharacters());
		sceneList[(int)currentScene]->Init();
	}
	if (InputMgr::GetKeyDown(Keyboard::Key::Escape))
	{
		sceneList[(int)currentScene]->BgmEnd();
		Init();
	}
}

void SceneMgr::Draw(RenderWindow& window)
{
	sceneList[(int)currentScene]->Draw(window);
}

Scenes SceneMgr::GetCurrentScene() const
{
	return currentScene;
}
