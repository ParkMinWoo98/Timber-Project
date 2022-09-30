#pragma once
#include "Scene.h"

class Background;

enum class Characters
{
	Red,
	Green,
	Yellow,
};

class SingleCharacterScene : public Scene
{
protected:
	Characters characters;
	vector<SpriteObj*> player;
	Background* background;

	SingleCharacterScene(const SingleCharacterScene&);
public:
	SingleCharacterScene(RenderWindow& window);
	virtual ~SingleCharacterScene();

	virtual void Init();
	virtual void Release();
	virtual void Update();
	virtual void Draw(RenderWindow& window);

	vector<Characters> GetCharacters();
};
