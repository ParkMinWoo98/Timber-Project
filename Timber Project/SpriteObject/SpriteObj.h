#pragma once
#include <SFML/Graphics.hpp>
#include "../Utils.h"

using namespace sf;
class SpriteObj
{
protected:
	Sprite sprite;
	SpriteObj(const SpriteObj& ref);
	SpriteObj& operator=(const SpriteObj& ref);
public:
	SpriteObj(const Vector2f& pos = Vector2f());
	virtual ~SpriteObj();

	virtual void Init() = 0;
	virtual void Release() = 0;

	virtual void Update(float dt);
	virtual void Draw(RenderWindow& window);

	void SetOrigin(Origins origin);
	Vector2f GetSize() const;

	Vector2f GetPosition() const;
	virtual void SetPosition(Vector2f pos);
	virtual void SetFlipX(bool flip);
	void Translate(Vector2f delta);
};

