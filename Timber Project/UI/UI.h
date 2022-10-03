#pragma once
#include "SFML/Graphics.hpp"

using namespace sf;

class UI
{
protected:
	UI(const UI&);
	UI& operator=(const UI&);
public:
	UI() {}
	virtual ~UI() {}

	virtual void Init() {}
	virtual void Release() {}
	virtual void Update(float dt) {}
	virtual void Draw(RenderWindow& window) {}
	virtual void SetPosition(const Vector2f	vec) {}
	virtual void SetColor(const Color& color) {}
	virtual Vector2f GetSize() { return Vector2f(); }
};