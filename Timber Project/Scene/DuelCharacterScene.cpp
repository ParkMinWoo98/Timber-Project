#include "DuelCharacterScene.h"
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "../Manager/ResourceMgr.h"
#include "../SpriteObject/Background.h"
#include "../SpriteObject/Button.h"
#include "../Manager/InputMgr.h"
#include "../SpriteObject/Background.h"

DuelCharacterScene::DuelCharacterScene(RenderWindow& window)
	:Scene(window)
{
	bgm.setBuffer(*resourceMgr->GetSoundBuffer("char scene start bgm"));
	background = new Background(*resourceMgr->GetTexture("char scene start background"));
	player1.push_back(new Background(*resourceMgr->GetTexture("char 1"), Vector2f(this->window.getSize().x * 0.25, 500)));
	player1.push_back(new Background(*resourceMgr->GetTexture("char 2"), Vector2f(this->window.getSize().x * 0.25, 500)));
	player1.push_back(new Background(*resourceMgr->GetTexture("char 3"), Vector2f(this->window.getSize().x * 0.25, 500)));
	player2.push_back(new Background(*resourceMgr->GetTexture("char 1"), Vector2f(this->window.getSize().x * 0.75, 500)));
	player2.push_back(new Background(*resourceMgr->GetTexture("char 2"), Vector2f(this->window.getSize().x * 0.75, 500)));
	player2.push_back(new Background(*resourceMgr->GetTexture("char 3"), Vector2f(this->window.getSize().x * 0.75, 500)));
	for (int i = 0; i < 2; ++i)
	{
		characters.push_back(Characters::Red);
	}
}

DuelCharacterScene::~DuelCharacterScene()
{
	if (background != nullptr)
		delete background;
	background = nullptr;
	for (auto player : player1)
	{
		delete player;
	}
	for (auto player : player2)
	{
		delete player;
	}
}

void DuelCharacterScene::Init()
{
}

void DuelCharacterScene::Update()
{
	if (InputMgr::GetKeyDown(Keyboard::Key::A) && characters[0] != Characters::Red)
	{
		characters[0] = (Characters)((int)characters[0] - 1);
	}
	if (InputMgr::GetKeyDown(Keyboard::Key::D) && characters[0] != Characters::Yellow)
	{
		characters[0] = (Characters)((int)characters[0] + 1);
	}
	if (InputMgr::GetKeyDown(Keyboard::Key::Left) && characters[1] != Characters::Red)
	{
		characters[1] = (Characters)((int)characters[1] - 1);
	}
	if (InputMgr::GetKeyDown(Keyboard::Key::Right) && characters[1] != Characters::Yellow)
	{
		characters[1] = (Characters)((int)characters[1] + 1);
	}
}

void DuelCharacterScene::Draw(RenderWindow& window)
{
	
}

vector<Button*> DuelCharacterScene::GetCharacters()
{
	return buttons;
}
