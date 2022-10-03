#pragma once
#include "TextUI.h"

class Player;

class ScoreTextUI : public TextUI
{
protected:
	Player* playerPtr;
public:
	ScoreTextUI(const Font& font, int size, const Color& color = Color::White);
	virtual ~ScoreTextUI();

	virtual void Init();
	virtual void Update(float dt);
	void SetPlayerPtr(Player* player);
};
