#include "EffectLog.h"

const Vector2f EffectLog::Gravity = Vector2f(0.f, 2000);

EffectLog::EffectLog(const Texture& tex, float duration)
	:SpriteObj(tex), duration(duration)
{
	SetOrigin(Origins::MC);
}

EffectLog::~EffectLog()
{
}

void EffectLog::Fire(const Vector2f& v, float av)
{
	active = true;
	timer = 0.f;
	velocity = v;
	angularVelocity = av;
}

bool EffectLog::GetActive() const
{
	return active;
}

void EffectLog::Init()
{
	SpriteObj::Init();
	SetOrigin(Origins::MC);
}

void EffectLog::Release()
{
	SpriteObj::Release();
}

void EffectLog::Update(float dt)
{
	SpriteObj::Update(dt);
	timer += dt;
	if (timer > duration)
	{
		active = false;
	}

	float angle = sprite.getRotation();
	angle += angularVelocity * dt;
	sprite.setRotation(angle);

	velocity += Gravity * dt;
	Vector2f delta = velocity * dt;
	Translate(delta);
}

void EffectLog::Draw(RenderWindow& window)
{
	SpriteObj::Draw(window);
}
