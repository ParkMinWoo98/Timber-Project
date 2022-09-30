#include "Background.h"

Background::Background(const Texture& tex, const Vector2f& pos = Vector2f())
	:SpriteObj(tex, pos)
{
}

void Background::Draw(RenderWindow& window)
{
	SpriteObj::Draw(window);
}
