#include "ScoreTextUI.h"
#include "../SpriteObject/Player.h"

ScoreTextUI::ScoreTextUI(const Font& font, int size, const Color& color)
	:TextUI(font, size, color), playerPtr(nullptr)
{
}

ScoreTextUI::~ScoreTextUI()
{
}

void ScoreTextUI::Init()
{
}

void ScoreTextUI::Update(float dt)
{
	SetString("score = " + to_string(playerPtr->GetScore()));
}

void ScoreTextUI::SetPlayerPtr(Player* player)
{
	playerPtr = player;
}
