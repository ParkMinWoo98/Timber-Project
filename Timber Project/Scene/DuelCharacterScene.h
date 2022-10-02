#pragma once
#include "CharacterScene.h"

class Background;

class DuelCharacterScene : public CharacterScene
{
protected:
	vector<SpriteObj*> player1;
	vector<SpriteObj*> player2;

	vector<bool> selected;

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
