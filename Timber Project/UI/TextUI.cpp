#include "TextUI.h"
#include "../Utils.h"

TextUI::TextUI(const Font& font, int size, const Color& color)
	:origin(Origins::MC)
{
	text.setFont(font);
	text.setCharacterSize(size);
	text.setFillColor(color);
}

TextUI::~TextUI()
{
}

void TextUI::Init()
{
	SetString(initString);
}

void TextUI::Release()
{
}

void TextUI::Draw(RenderWindow& window)
{
	window.draw(text);
}

void TextUI::SetPosition(const Vector2f pos)
{
	text.setPosition(pos);
	Utils::SetOrigin(text, origin);
}

void TextUI::SetOrigin(Origins origin)
{
	this->origin = origin;
	Utils::SetOrigin(text, origin);
}

void TextUI::SetColor(const Color& color)
{
	text.setFillColor(color);
}

void TextUI::SetCharSize(int charSize)
{
	text.setCharacterSize(charSize);
}

void TextUI::SetString(const String& string)
{
	text.setString(string);
	Utils::SetOrigin(text, origin);
}

void TextUI::SetInitString(const String& string)
{
	initString = string;
}

void TextUI::SetFont(const Font& font)
{
	text.setFont(font);
}
