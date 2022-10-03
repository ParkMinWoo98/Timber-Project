#include "SingleCharacterScene.h"
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "../Manager/ResourceMgr.h"
#include "../SpriteObject/SpriteObj.h"
#include "../SpriteObject/Button.h"
#include "../Manager/InputMgr.h"

SingleCharacterScene::SingleCharacterScene(RenderWindow& window)
	:CharacterScene(window)
{
	player.push_back(new SpriteObj(*resourceMgr->GetTexture("graphics/player1.png"), Vector2f(this->window.getSize().x * 0.5, 500)));
	player.push_back(new SpriteObj(*resourceMgr->GetTexture("graphics/player2.png"), Vector2f(this->window.getSize().x * 0.5, 500)));
	player.push_back(new SpriteObj(*resourceMgr->GetTexture("graphics/player3.png"), Vector2f(this->window.getSize().x * 0.5, 500)));
	for (auto p : player)
	{
		p->SetOrigin(Origins::MC);
	}
	characters.push_back(Characters::Red);
}

SingleCharacterScene::~SingleCharacterScene()
{
	if (background != nullptr)
		delete background;
	background = nullptr;
	for (auto p : player)
	{
		delete p;
	}
}

void SingleCharacterScene::Init()
{
	CharacterScene::Init();
}

void SingleCharacterScene::Release()
{
}

void SingleCharacterScene::Update()
{
	if (InputMgr::GetKeyDown(Keyboard::Key::A) && characters[0] != Characters::Red)
	{
		characters[0] = (Characters)((int)characters[0] - 1);
	}
	if (InputMgr::GetKeyDown(Keyboard::Key::D) && characters[0] != Characters::Yellow)
	{
		characters[0] = (Characters)((int)characters[0] + 1);
	}
	if (InputMgr::GetKeyDown(Keyboard::Key::Return))
		isSceneEnd = true;
}

void SingleCharacterScene::Draw(RenderWindow& window)
{
	background->Draw(window);
	player[(int)characters[0]]->Draw(window);
}

vector<Characters> SingleCharacterScene::GetCharacters()
{
	return characters;
}
