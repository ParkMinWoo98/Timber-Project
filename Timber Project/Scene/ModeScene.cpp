#include "ModeScene.h"
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "../Manager/ResourceMgr.h"
#include "../SpriteObject/Background.h"
#include "../SpriteObject/Button.h"
#include "../Manager/InputMgr.h"

ModeScene::ModeScene(RenderWindow& window)
	:Scene(window), mode(Modes::single)
{
	bgm.setBuffer(*resourceMgr->GetSoundBuffer("sound/game_bgm_mode.wav"));
	background = new Background(*resourceMgr->GetTexture("graphics/background_mode.jpg"));
	buttons.push_back(new Button(*resourceMgr->GetTexture("graphics/1p.png"), Vector2f(this->window.getSize().x * 0.25, 500)));
	buttons.push_back(new Button(*resourceMgr->GetTexture("graphics/2p.png"), Vector2f(this->window.getSize().x * 0.75, 500)));
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
	Scene::Init();
	buttons[0]->ButtonEffect();
}

void ModeScene::Release()
{
}

void ModeScene::Update()
{
	if (InputMgr::GetKeyDown(Keyboard::Key::Left) && mode == Modes::duel)
	{
		buttons[0]->ButtonEffect();
		buttons[1]->EndEffect();
		mode = Modes::single;
	}
	if (InputMgr::GetKeyDown(Keyboard::Key::Right) && mode == Modes::single)
	{
		buttons[1]->ButtonEffect();
		buttons[0]->EndEffect();
		mode = Modes::duel;
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
