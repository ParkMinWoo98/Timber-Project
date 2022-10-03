#pragma once
#include "PlayScene.h"
#include <Windows.h>
#include <vector>

class SinglePlayScene : public PlayScene
{
protected:
	SinglePlayScene(const SinglePlayScene&);
	SinglePlayScene& operator=(const SinglePlayScene&);
public:
	SinglePlayScene(RenderWindow& window, Time& dt);
	virtual ~SinglePlayScene();
};