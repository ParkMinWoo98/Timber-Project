#include "Background.h"

Background::Background(const Texture& tex, const Vector2f& pos)
	:SpriteObj(tex, pos)
{
}

Background::~Background()
{
}

void Background::Draw(RenderWindow& window)
{
	SpriteObj::Draw(window);
}
