#include "Button.h"
#include "../Manager/ResourceMgr.h"
#include "../Utils.h"

Button::Button(const Texture& tex, const Vector2f& pos)
	:SpriteObj(tex, pos)
{
	initSize = sprite.getScale();
	movingSound.setBuffer(*resourceMgr->GetSoundBuffer("sound/game_move_button.wav"));
	selectedSound.setBuffer(*resourceMgr->GetSoundBuffer("sound/game_click_button.wav"));
	Utils::SetOrigin(sprite, Origins::MC);
}

Button::~Button()
{
}

void Button::Init()
{
	EndEffect();
}

void Button::ButtonEffect()
{
	sprite.setScale(initSize * 1.2f);
	movingSound.play();
}

void Button::EndEffect()
{
	sprite.setScale(initSize);
}

void Button::SelectedSoundEffect()
{
	selectedSound.play();
}
