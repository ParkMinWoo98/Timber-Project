#pragma once
#include "Scene.h"

class PlayScene : public Scene
{
protected:
	PlayScene(const PlayScene&);
	PlayScene& operator=(const PlayScene&);
public:
	PlayScene();
	virtual ~PlayScene();

	virtual void Init();
	virtual void Release();
	virtual void Update(float dt);
	virtual void Draw(RenderWindow& window);
};