#pragma once
#include "Scene.h"
#include <Windows.h>
#include <vector>

class CharacterScene;
enum class Characters;

class Player;
class Tree;

class DuelPlayScene : public Scene
{
protected:
	list<SpriteObj*> objList;
	vector<Characters> characters;

	vector<Player*> player;
	vector<Tree*> tree;

	CharacterScene& characterScene;

	Time& dt;
	float timer;
	float duration;
	bool isPause;

	Sound timeOutSound;

	DuelPlayScene(const DuelPlayScene&);
	DuelPlayScene& operator=(const DuelPlayScene&);
public:
	DuelPlayScene(RenderWindow& window, Time& dt);
	virtual ~DuelPlayScene();

	Texture& GetCharacterTex(Characters character);

	virtual void Init();
	virtual void Release();
	virtual void Update();
	virtual void Draw();

	void SetTimer(float duratino);
	bool isAllAlive() const;
};
