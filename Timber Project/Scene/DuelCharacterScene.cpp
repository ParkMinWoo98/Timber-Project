#include "DuelCharacterScene.h"
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "../Manager/ResourceMgr.h"
#include "../SpriteObject/SpriteObj.h"
#include "../Manager/InputMgr.h"

DuelCharacterScene::DuelCharacterScene(RenderWindow& window)
	:CharacterScene(window)
{
	player1.push_back(new SpriteObj(*resourceMgr->GetTexture("graphics/player1.png"), Vector2f(this->window.getSize().x * 0.25, 500)));
	player1.push_back(new SpriteObj(*resourceMgr->GetTexture("graphics/player2.png"), Vector2f(this->window.getSize().x * 0.25, 500)));
	player1.push_back(new SpriteObj(*resourceMgr->GetTexture("graphics/player3.png"), Vector2f(this->window.getSize().x * 0.25, 500)));
	player2.push_back(new SpriteObj(*resourceMgr->GetTexture("graphics/player1.png"), Vector2f(this->window.getSize().x * 0.75, 500)));
	player2.push_back(new SpriteObj(*resourceMgr->GetTexture("graphics/player2.png"), Vector2f(this->window.getSize().x * 0.75, 500)));
	player2.push_back(new SpriteObj(*resourceMgr->GetTexture("graphics/player3.png"), Vector2f(this->window.getSize().x * 0.75, 500)));
	for (auto p : player1)
	{
		p->SetOrigin(Origins::MC);
	}
	for (auto p : player2)
	{
		p->SetOrigin(Origins::MC);
	}
	for (int i = 0; i < 2; ++i)
	{
		characters.push_back(Characters::Red);
		selected.push_back(false);
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
	CharacterScene::Init();
	for (auto s : selected)
	{
		s = false;
	}
}

void DuelCharacterScene::Release()
{
}

void DuelCharacterScene::Update()
{
	if (!selected[0])
	{
		if (InputMgr::GetKeyDown(Keyboard::Key::A) && characters[0] != Characters::Red)
			characters[0] = (Characters)((int)characters[0] - 1);
		if (InputMgr::GetKeyDown(Keyboard::Key::D) && characters[0] != Characters::Yellow)
			characters[0] = (Characters)((int)characters[0] + 1);
		if (InputMgr::GetKeyDown(Keyboard::Key::Space))
			selected[0] = true;
	}
	if (!selected[1])
	{
		if (InputMgr::GetKeyDown(Keyboard::Key::Left) && characters[1] != Characters::Red)
			characters[1] = (Characters)((int)characters[1] - 1);
		if (InputMgr::GetKeyDown(Keyboard::Key::Right) && characters[1] != Characters::Yellow)
			characters[1] = (Characters)((int)characters[1] + 1);
		if (InputMgr::GetKeyDown(Keyboard::Key::Return))
			selected[1] = true;
	}
	if (selected[0] && selected[1])
		isSceneEnd = true;
}

void DuelCharacterScene::Draw(RenderWindow& window)
{
	background->Draw(window);
	player1[(int)characters[0]]->Draw(window);
	player2[(int)characters[1]]->Draw(window);
}

vector<Characters> DuelCharacterScene::GetCharacters()
{
	return characters;
}
