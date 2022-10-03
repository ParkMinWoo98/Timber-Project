#pragma once
#include "PlayScene.h"
#include <Windows.h>
#include <vector>

class DuelPlayScene : public PlayScene
{
protected:
	DuelPlayScene(const DuelPlayScene&);
	DuelPlayScene& operator=(const DuelPlayScene&);
public:
	DuelPlayScene(RenderWindow& window, Time& dt);
	virtual ~DuelPlayScene();
};
