#include "SpriteObj.h"

SpriteObj& SpriteObj::operator=(const SpriteObj& ref)
{
	return *this;
}

SpriteObj::SpriteObj(const Vector2f& pos)
{

	sprite.setTexture(*);
	sprite.setPosition(pos);
}

SpriteObj::~SpriteObj()
{
}

void SpriteObj::Init()
{
}

void SpriteObj::Release()
{
}

void SpriteObj::Update(float dt)
{
}

void SpriteObj::Draw(RenderWindow& window)
{
	window.draw(sprite);
}

void SpriteObj::SetOrigin(Origins origin)
{
	Utils::SetOrigin(sprite, origin);
}

Vector2f SpriteObj::GetSize() const
{
	FloatRect rect = sprite.getLocalBounds();
	return Vector2f(rect.width, rect.height);
}

Vector2f SpriteObj::GetPosition()
{
	return sprite.getPosition();
}

void SpriteObj::SetPosition(Vector2f pos)
{
	sprite.setPosition(pos);
}

void SpriteObj::SetFlipX(bool flip)
{
	Vector2f scale = sprite.getScale();
	scale.x = flip ? -abs(scale.x) : abs(scale.x);
	sprite.setScale(scale);
}

void SpriteObj::Translate(Vector2f delta)
{
	Vector2f pos = sprite.getPosition() + delta;
	sprite.setPosition(pos);
}
