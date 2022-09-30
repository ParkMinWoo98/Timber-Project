#include "MovingObj.h"

MovingObj::MovingObj(const Texture& tex, const Vector2f& pos)
	:SpriteObj(tex, pos)
{
}

MovingObj::~MovingObj()
{
}

void MovingObj::Set(Vector2i speedRange, Vector2i yRange, Vector2f startPos, Vector2f endPos)
{
	this->speedRange = speedRange;
	this->yRange = yRange;
	this->startPos = startPos;
	this->endPos = endPos;
	direction = (endPos.x > startPos.x) ? Vector2f(1, 0) : Vector2f(-1, 0);

}

void MovingObj::Init()
{
	speed = (rand() % (speedRange.y - speedRange.x)) + speedRange.x;

	startPos.y = (rand() % (yRange.y - yRange.x)) + yRange.x;
	endPos.y = startPos.y;

	SetPosition(startPos);
}

void MovingObj::Update(float dt)
{
	Vector2f pos = GetPosition();
	float distanceX = endPos.x - pos.x;

	if (abs(distanceX) < 10)
		Init();
	Translate(direction * speed * dt);
}