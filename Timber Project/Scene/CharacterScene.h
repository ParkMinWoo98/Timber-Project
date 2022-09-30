#pragma once
#include "Scene.h"

class Background;

enum class Characters
{
	Red,
	Green,
	Yellow,
	none
};

class CharacterScene : public Scene
{
protected:
	vector<Characters> characters;
	vector<SpriteObj*> player1;
	vector<SpriteObj*> player2;
	Background* background;

	CharacterScene(const CharacterScene&);
public:
	CharacterScene(RenderWindow& window);
	virtual ~CharacterScene();

	virtual void Init();
	virtual void Release();
	virtual void Update();
	virtual void Draw(RenderWindow& window);

	vector<Characters> GetCharacters();
};
