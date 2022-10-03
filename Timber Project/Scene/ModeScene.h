#pragma once
#include "Scene.h"

class SpriteObj;
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
	SpriteObj* background;
	vector<Button*> buttons;

	ModeScene(const ModeScene&);
	ModeScene& operator=(const ModeScene&);
public:
	ModeScene(RenderWindow& window);
	virtual ~ModeScene();

	virtual void Init();
	virtual void Release();
	virtual void Update();
	virtual void Draw(RenderWindow& window);

	virtual Modes GetMode() const;
};

