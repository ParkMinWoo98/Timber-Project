#include "PlayScene.h"
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "../Manager/ResourceMgr.h"
#include "../SpriteObject/SpriteObj.h"
#include "../SpriteObject/Bee.h"
#include "../SpriteObject/Cloud.h"
#include "../SpriteObject/Tree.h"
#include "../SpriteObject/Player.h"
#include "../Scene/ModeScene.h"
#include "../Scene/CharacterScene.h"
#include "../Manager/InputMgr.h"
#include "PlayScene.h"
#include "../UI/TextUI.h"

PlayScene::PlayScene(RenderWindow& window, Time& dt)
	:Scene(window), dt(dt), isPause(false)
{
	bgm.setBuffer(*resourceMgr->GetSoundBuffer("sound/game_bgm_play.wav"));
	objList.push_back(new SpriteObj(*resourceMgr->GetTexture("graphics/background_play.png")));
	for (int i = 0; i < 3; ++i)
	{
		objList.push_back(new Cloud(*resourceMgr->GetTexture("graphics/cloud.png")));
		objList.push_back(new Bee(*resourceMgr->GetTexture("graphics/bee.png")));
	}
	messageText = new TextUI(*resourceMgr->GetFont("fonts/KOMIKAP_.ttf"), 75);
	messageText->SetPosition(Vector2f(window.getSize().x * 0.5, window.getSize().y * 0.5));
	messageText->SetOrigin(Origins::MC);
	messageText->SetInitString("Press Enter to start!");
}

PlayScene::~PlayScene()
{
}

void PlayScene::SetCharacterScene(vector<Characters> vec)
{
	characters = vec;
}

Texture& PlayScene::GetCharacterTex(Characters character)
{
	switch (character)
	{
	case Characters::Red:
		return *resourceMgr->GetTexture("graphics/player1.png");
	case Characters::Green:
		return *resourceMgr->GetTexture("graphics/player2.png");
	case Characters::Yellow:
		return *resourceMgr->GetTexture("graphics/player3.png");
	}
}

void PlayScene::Init()
{
	Scene::Init();
	messageText->Init();
	for (int i = 0; i < player.size(); ++i)
	{
		player[i]->SetTexPlayer(GetCharacterTex(characters[i]));
	}
	for (auto obj : objList)
	{
		obj->Init();
	}
	for (auto UI : UIList)
	{
		UI->Init();
	}
}

void PlayScene::Release()
{
}

void PlayScene::Update()
{
	if (InputMgr::GetKeyDown(Keyboard::Key::Return))
	{
		if (isAllAlive())
		{
			isPause = !isPause;
		}
		else
		{
			Init();
			isPause = false;
		}
	}
	float deltaTime = isPause ? 0.f : dt.asSeconds();
	if (!isAllAlive())
	{
		for (auto p : player)
		{
			p->SetTimer(0.f);
		}
		isPause = true;
		messageText->SetString("Game Over!!\nPress Enter to start!");
	}
	// 타임바, 스코어텍스트

	if (!isPause)
	{
		for (auto obj : objList)
		{
			obj->Update(deltaTime);
		}
		for (auto UI : UIList)
		{
			UI->Update(deltaTime);
		}
	}
}

void PlayScene::Draw(RenderWindow& window)
{
	for (auto obj : objList)
	{
		obj->Draw(window);
	}
	for (auto UI : UIList)
	{
		UI->Draw(window);
	}
	if (isPause)
	{
		messageText->Draw(window);
	}
}

bool PlayScene::isAllAlive() const
{
	for (auto p : player)
	{
		if (p->TimeOut() || !p->GetAlive())
			return false;
	}
	return true;
}
