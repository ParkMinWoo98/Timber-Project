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
#include "PlayScene.h"

PlayScene::PlayScene(RenderWindow& window, Time& dt)
	:Scene(window), dt(dt), isPause(false), duration(4.0f)
{
	bgm.setBuffer(*resourceMgr->GetSoundBuffer("sound/game_bgm_play.wav"));
	objList.push_back(new Background(*resourceMgr->GetTexture("graphics/background_play.png")));
	for (int i = 0; i < 3; ++i)
	{
		objList.push_back(new Cloud(*resourceMgr->GetTexture("graphics/cloud.png")));
		objList.push_back(new Bee(*resourceMgr->GetTexture("graphics/bee.png")));
	}
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
	for (int i = 0; i < player.size(); ++i)
	{
		player[i]->SetTexPlayer(GetCharacterTex(characters[i]));
		player[i]->SetTimer(duration);
	}
	for (auto obj : objList)
	{
		obj->Init();
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
			isPause = !isPause;
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
		/*messageText.setString("Game Over!!");
		Utils::SetOrigin(messageText, Origins::MC);*/
	}
	// 타임바, 스코어텍스트

	if (!isPause)
	{
		for (auto obj : objList)
		{
			obj->Update(deltaTime);
		}
	}
}

void PlayScene::Draw(RenderWindow& window)
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
		if (p->TimeOut() || !p->GetAlive())
			return false;
	}
	return true;
}
