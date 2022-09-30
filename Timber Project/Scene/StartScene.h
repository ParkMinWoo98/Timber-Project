#pragma once
#include "Scene.h"

class StartScene : public Scene
{
protected:
	StartScene(const StartScene&);
	StartScene& operator=(const StartScene&);
public:
	StartScene();
	virtual ~StartScene();

	virtual void Init();
	virtual void Release();
	virtual void Update(float dt);
	virtual void Draw(RenderWindow& window);
};

