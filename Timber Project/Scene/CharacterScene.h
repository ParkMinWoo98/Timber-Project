#pragma once
#include "Scene.h"

class Background;

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
	Background* background;

	CharacterScene(const CharacterScene&);
public:
	CharacterScene(RenderWindow& window);
	virtual ~CharacterScene();

	virtual void Init();
	virtual void Release();
	virtual void Update();
	virtual void Draw(RenderWindow& window);

	virtual vector<Characters> GetCharacters();
};
