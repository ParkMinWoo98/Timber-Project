#pragma once
#include "Scene.h"
#include <Windows.h>

class Background;
class Button;

enum class Modes
{
	single,
	duel,
};

class ModeScene : public Scene
{
protected:
	Modes mode;
	Background* background;
	vector<Button*> buttons;

public:
	ModeScene(RenderWindow& window);
	virtual ~ModeScene();

	virtual void Init();
	virtual void Release();
	virtual void Update();
	virtual void Draw(RenderWindow& window);

	Modes GetMode() const;
};

