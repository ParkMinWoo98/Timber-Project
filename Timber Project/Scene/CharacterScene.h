#pragma once
#include "Scene.h"

class SpriteObj;

enum class Characters
{
	Red,
	Green,
	Yellow,
};

class CharacterScene : public Scene
{
protected:
	vector<Characters> characters;
	SpriteObj* background;

	CharacterScene(const CharacterScene&);
	CharacterScene& operator=(const CharacterScene&);
public:
	CharacterScene(RenderWindow& window);
	virtual ~CharacterScene();

	virtual void Init();
	virtual void Release();
	virtual void Update();
	virtual void Draw(RenderWindow& window);

	virtual vector<Characters> GetCharacters();
};
