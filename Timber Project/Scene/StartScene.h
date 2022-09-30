#pragma once
#include "Scene.h"

class Background;

class StartScene : public Scene
{
protected:
	Background* background;

	StartScene(const StartScene&);
	StartScene& operator=(const StartScene&);
public:
	StartScene(RenderWindow& window);
	virtual ~StartScene();

	virtual void Init();
	virtual void Release();
	virtual void Update();
	virtual void Draw(RenderWindow& window);
};

