#include "SingleCharacterScene.h"
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "../Manager/ResourceMgr.h"
#include "../SpriteObject/Background.h"
#include "../SpriteObject/Button.h"
#include "../Manager/InputMgr.h"
#include "../SpriteObject/Background.h"

SingleCharacterScene::SingleCharacterScene(RenderWindow& window)
	:Scene(window), characters(Characters::Red)
{
	bgm.setBuffer(*resourceMgr->GetSoundBuffer("char scene start bgm"));
	background = new Background(*resourceMgr->GetTexture("char scene start background"));
	player.push_back(new Background(*resourceMgr->GetTexture("char 1"), Vector2f(this->window.getSize().x * 0.25, 500)));
	player.push_back(new Background(*resourceMgr->GetTexture("char 2"), Vector2f(this->window.getSize().x * 0.25, 500)));
	player.push_back(new Background(*resourceMgr->GetTexture("char 3"), Vector2f(this->window.getSize().x * 0.25, 500)));
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
}

void SingleCharacterScene::Update()
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

void SingleCharacterScene::Draw(RenderWindow& window)
{
}

vector<Button*> SingleCharacterScene::GetCharacters()
{
	return buttons;
}
