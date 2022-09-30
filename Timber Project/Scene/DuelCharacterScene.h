#pragma once
#include "Scene.h"

class Background;

enum class Characters
{
	Red,
	Green,
	Yellow,
};

class DuelCharacterScene : public Scene
{
protected:
	vector<Characters> characters;
	vector<SpriteObj*> player1;
	vector<SpriteObj*> player2;
	Background* background;

	DuelCharacterScene(const DuelCharacterScene&);
public:
	DuelCharacterScene(RenderWindow& window);
	virtual ~DuelCharacterScene();

	virtual void Init();
	virtual void Release();
	virtual void Update();
	virtual void Draw(RenderWindow& window);

	vector<Characters> GetCharacters();
};
