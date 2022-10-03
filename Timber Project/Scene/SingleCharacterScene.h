#pragma once
#include "CharacterScene.h"

class SpriteObj;

class SingleCharacterScene : public CharacterScene
{
protected:
	vector<SpriteObj*> player;

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
