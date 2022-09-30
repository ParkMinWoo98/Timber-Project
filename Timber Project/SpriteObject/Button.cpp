#include "Button.h"
#include "../Manager/ResourceMgr.h"

Button::Button(const Texture& tex, const Vector2f& pos)
	:SpriteObj(tex, pos)
{
	movingSound.setBuffer(*resourceMgr->GetSoundBuffer("moving sound wav"));
	selectedSound.setBuffer(*resourceMgr->GetSoundBuffer("selected sound wav"));
}

Button::~Button()
{
}

void Button::ButtonEffect()
{
	sprite.scale(1.2, 1.2);
	movingSound.play();
}

void Button::EndEffect()
{
	sprite.scale(0.833, 0.833);
}

void Button::SelectedSoundEffect()
{
	selectedSound.play();
}
