#include "PlayScene.h"
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "../Manager/ResourceMgr.h"
#include "../SpriteObject/Background.h"
#include "../SpriteObject/Bee.h"
#include "../SpriteObject/Cloud.h"
#include "../SpriteObject/Tree.h"
#include "../SpriteObject/Player.h"
#include "../Scene/ModeScene.h"
#include "../Scene/CharacterScene.h"
#include "../Manager/InputMgr.h"

PlayScene::PlayScene(Modes mode, vector<Characters> characters, RenderWindow& window, Time& dt)
	:Scene(window), currentMode(mode), dt(dt), isPause(false)
{
	bgm.setBuffer(*resourceMgr->GetSoundBuffer("play scene start bgm"));
	objList.push_back(new Background(*resourceMgr->GetTexture("play scene start background")));
	for (int i = 0; i < 3; ++i)
	{
		objList.push_back(new Cloud());
		objList.push_back(new Bee());
	}
	switch (currentMode)
	{
	case Modes::single: 
		{
			tree.push_back(new Tree(Vector2f(this->window.getSize().x * 0.5f, 910)));
			player.push_back(new Player(GetCharacterTex(characters[0])));
			tree[0]->SetPlayerPtr(player[0]);
			player[0]->SetTreePtr(tree[0]);
			objList.push_back(tree[0]);
			objList.push_back(player[0]);
		}
		break;
	case Modes::duel:
		{
			tree.push_back(new Tree(Vector2f(this->window.getSize().x * 0.25f, 910)));
			tree.push_back(new Tree(Vector2f(this->window.getSize().x * 0.75f, 910)));
			player.push_back(new Player(GetCharacterTex(characters[0])));
			player.push_back(new Player(GetCharacterTex(characters[1])));
			for (int i = 0; i < 2; ++i)
			{
				player[i]->SetTreePtr(tree[i]);
				tree[i]->SetPlayerPtr(player[i]);
			}
			for (int i = 0; i < 2; ++i)
			{
				objList.push_back(tree[i]);
				objList.push_back(player[i]);
			}
		}
		break;
	}
	timeOutSound.setBuffer(*resourceMgr->GetSoundBuffer("time out sound wav"));
}

PlayScene::~PlayScene()
{
}

Texture& PlayScene::GetCharacterTex(Characters character)
{
	switch (character)
	{
	case Characters::Red:
		return *resourceMgr->GetTexture("character1 png");
	case Characters::Green:
		return *resourceMgr->GetTexture("character2 png");
	case Characters::Yellow:
		return *resourceMgr->GetTexture("character3 png");
	}
}

void PlayScene::Init()
{
	Scene::Init();
	for (auto obj : objList)
	{
		obj->Init();
	}
	duration = 4.0f;
	timer = duration;
}

void PlayScene::Release()
{
}

void PlayScene::Update()
{
	float deltaTime = isPause ? 0.f : dt.asSeconds();
	if (InputMgr::GetKeyDown(Keyboard::Key::Return))
	{
		if (timer > 0.f && isAllAlive())
			isPause = !isPause;
		else
		{
			for (auto& go : objList)
				go->Init();
			for (auto t : tree)
			{
				t->ClearLog();
				t->UpdateBranches();
				t->SetCurrentBranch(Sides::None);
				// tree->init으로 되는지 확인하기

				// ui에서 score초기화
				timer = duration;
				//messageText.setString("Press Enter to start!");
				// Utils::SetOrigin(messageText, Origins::MC);
				isPause = false;
			}
		}
	}
	float deltaTime = isPause ? 0.f : dt.asSeconds();
	timer -= deltaTime;
	if (timer < 0.f || !isAllAlive())
	{
		if (!isPause && timer < 0.f)
		{
			timeOutSound.play();
			timer = 0.f;
			isPause = true;
			/*messageText.setString("Game Over!!");
			Utils::SetOrigin(messageText, Origins::MC);*/
		}
	}
	// 타임바, 스코어텍스트

	if (!isPause)
	{
		for (auto obj : objList)
		{
			obj->Update(deltaTime);
		}
	}
	for (auto p : player)
	{
		p->CheckDeath();
	}
}

void PlayScene::Draw()
{
	for (auto obj : objList)
	{
		obj->Draw(window);
	}
	if (isPause)
	{
		// 메시지
	}
	// 메시지 제외 ui 출력
}

void PlayScene::SetTimer(float duration)
{
	this->duration = duration;
}

bool PlayScene::isAllAlive() const
{
	for (auto p : player)
	{
		if (!p->GetAlive())
			return false;
	}
	return true;
}
