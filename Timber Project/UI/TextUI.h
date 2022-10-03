#pragma once
#include "SFML/Graphics.hpp"
#include "UI.h"
#include "../Utils.h"

using namespace sf;

class TextUI : public UI
{
protected:
	Text text;

	String initString;
	Origins origin;
public:
	TextUI(const Font& font, int size, const Color& color = Color::White);
	virtual ~TextUI();

	virtual void Init();
	virtual void Release();
	virtual void Update(float dt) {}
	virtual void Draw(RenderWindow& window);
	virtual void SetPosition(const Vector2f	pos);
	virtual void SetOrigin(Origins origin);
	virtual void SetColor(const Color& color);

	void SetCharSize(int charSize);
	void SetString(const String& string);
	void SetInitString(const String& string);
	void SetFont(const Font& font);
};
