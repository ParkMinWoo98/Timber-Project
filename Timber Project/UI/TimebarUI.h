#pragma once
#include "SFML/Graphics.hpp"
#include "UI.h"

using namespace sf;

class Player;

class TimebarUI : public UI
{
protected:
	RectangleShape timebar;

	Vector2f initTimebarSize;
	Player* playerPtr;
public:
	TimebarUI(const Vector2f& size = Vector2f(400, 80), const Color& color = Color::Red);
	virtual ~TimebarUI();

	virtual void Init();
	virtual void Release();
	virtual void Update(float dt);
	virtual void Draw(RenderWindow& window);
	virtual void SetPosition(const Vector2f	pos);
	virtual void SetColor(const Color& color);
	virtual Vector2f GetSize();

	void SetSize(const Vector2f size);
	void SetInitSize(const Vector2f size);
	void SetPlayerPtr(Player* player);
};

