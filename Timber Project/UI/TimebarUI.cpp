#include "TimebarUI.h"
#include "../SpriteObject/Player.h"

TimebarUI::TimebarUI(const Vector2f& size, const Color& color)
	:initTimebarSize(size), playerPtr(nullptr)
{
	timebar.setFillColor(color);
}

TimebarUI::~TimebarUI()
{
}

void TimebarUI::Init()
{
	SetSize(initTimebarSize);
}

void TimebarUI::Release()
{
}

void TimebarUI::Update(float dt)
{
	float normTime = playerPtr->GetTimer() / playerPtr->GetDuration();
	SetSize({ normTime * initTimebarSize.x, initTimebarSize.y });
}

void TimebarUI::Draw(RenderWindow& window)
{
	window.draw(timebar);
}

void TimebarUI::SetColor(const Color& color)
{
	timebar.setFillColor(color);
}

void TimebarUI::SetPosition(const Vector2f pos)
{
	timebar.setPosition(pos);
}


Vector2f TimebarUI::GetSize()
{
	return initTimebarSize;
}

void TimebarUI::SetSize(const Vector2f size)
{
	timebar.setSize(size);
}

void TimebarUI::SetInitSize(const Vector2f size)
{
	initTimebarSize = size;
}

void TimebarUI::SetPlayerPtr(Player* player)
{
	playerPtr = player;
}
