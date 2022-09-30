#include "ModeScene.h"
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "../Manager/ResourceMgr.h"
#include "../SpriteObject/Background.h"
#include "../SpriteObject/Button.h"
#include "../Manager/InputMgr.h"

ModeScene::ModeScene(RenderWindow& window)
	:Scene(window), mode(Modes::none)
{
	bgm.setBuffer(*resourceMgr->GetSoundBuffer("mode scene start bgm"));
	background = new Background(*resourceMgr->GetTexture("mode scene start background"));
	buttons.push_back(new Button(*resourceMgr->GetTexture("mode scene button1"), Vector2f(this->window.getSize().x * 0.25, 500)));
	buttons.push_back(new Button(*resourceMgr->GetTexture("mode scene button1"), Vector2f(this->window.getSize().x * 0.75, 500)));
}

ModeScene::~ModeScene()
{
	if(background != nullptr)
		delete background;
	background = nullptr;
	for (auto button : buttons)
	{
		delete button;
	}
}

void ModeScene::Init()
{
}

void ModeScene::Release()
{
}

void ModeScene::Update()
{
	if (InputMgr::GetKeyDown(Keyboard::Key::Left) && mode != Modes::single)
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

void ModeScene::Draw(RenderWindow& window)
{
	background->Draw(window);
	for (auto button : buttons)
	{
		button->Draw(window);
	}
}

Modes ModeScene::GetMode() const
{
	return mode;
}
