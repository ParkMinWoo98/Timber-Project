#pragma once
#include "Scene.h"

enum class Modes
{
	single,
	duel,
};

class ModeScene : public Scene
{
protected:
	Modes mode;
public:
	virtual void Init();
	virtual void Release();
	virtual void Update(float dt);
	virtual void Draw(RenderWindow& window);
};

