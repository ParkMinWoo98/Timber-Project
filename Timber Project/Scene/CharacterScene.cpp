#include "CharacterScene.h"
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "../Manager/ResourceMgr.h"
#include "../SpriteObject/Background.h"
#include "../SpriteObject/Button.h"
#include "../Manager/InputMgr.h"
#include "../SpriteObject/Background.h"

CharacterScene::CharacterScene(RenderWindow& window)
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
}

CharacterScene::~CharacterScene()
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

void CharacterScene::Init()
{
}

void CharacterScene::Update()
{
	if (InputMgr::GetKeyDown(Keyboard::Key::Left) && charaters)
	{
		buttons[0]->ButtonEffect();
		buttons[1]->EndEffect();
	}
	if (InputMgr::GetKeyDown(Keyboard::Key::Right) && mode != Modes::duel)
	{
		buttons[1]->ButtonEffect();
		buttons[0]->EndEffect();
	}
	if (InputMgr::GetKeyDown(Keyboard::Key::Return))
	{
		buttons[(int)mode]->SelectedSoundEffect();
		isSceneEnd = true;
	}
}

void CharacterScene::Draw(RenderWindow& window)
{
}

vector<Button*> CharacterScene::GetCharacters()
{
	return buttons;
}
