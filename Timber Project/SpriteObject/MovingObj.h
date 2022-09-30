#pragma once
#include "SpriteObj.h"

class MovingObj : public SpriteObj
{
protected:
	float speed;
	Vector2i speedRange;
	Vector2i yRange;

	Vector2f direction;

	Vector2f startPos;
	Vector2f endPos;

	MovingObj(const MovingObj&);
	MovingObj& operator=(const MovingObj&);
public:
	MovingObj(const Texture& tex, const Vector2f& pos = Vector2f());
	virtual ~MovingObj();

	void Set(Vector2i speedRange, Vector2i yRange, Vector2f startPos, Vector2f endPos);

	virtual void Init() override;
	virtual void Update(float dt) override;
};