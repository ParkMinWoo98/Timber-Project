#include "SceneMgr.h"
#include "../Scene/StartScene.h"
#include "../Scene/ModeScene.h"
#include "../Scene/CharacterScene.h"
#include "../Scene/SinglePlayScene.h"
#include "../Scene/DuelPlayScene.h"

SceneMgr::SceneMgr(RenderWindow& window, Time& dt)
	:currentScene(Scenes::start), dt(dt)
{
	sceneList.push_back(new StartScene(window));
	sceneList.push_back(new ModeScene(window));
	sceneList.push_back(new CharacterScene(window));
	sceneList.push_back(new SinglePlayScene(window, dt));
	sceneList.push_back(new SinglePlayScene(window, dt));
}

SceneMgr::~SceneMgr()
{
}

void SceneMgr::Update()
{
	if (sceneList[(int)currentScene]->GetSceneEnd() == true)
	{
		currentScene = (Scenes)((int)currentScene + 1);
		sceneList[(int)currentScene]->Init();
	}
	sceneList[(int)currentScene]->Update();
}

void SceneMgr::Draw(RenderWindow& window)
{
	sceneList[(int)currentScene]->Draw(window);
}