#pragma once
#include "SpriteObj.h"

class EffectLog : public SpriteObj
{
protected:
	Vector2f velocity;
	float angularVelocity;
	float duration;
	float timer;
	bool active;
public:
	static const Vector2f Gravity;

	EffectLog(const Texture& tex, float duration);
	virtual ~EffectLog();

	void Fire(const Vector2f& v, float av);
	bool GetActive() const;

	virtual void Init() override;
	virtual void Release() override;
	virtual void Update(float dt) override;
	virtual void Draw(RenderWindow& window) override;
};

