#pragma once
#include "Scene.h"
#include <Windows.h>
#include <vector>

class CharacterScene;
enum class Characters;

class Player;
class Tree;

class SinglePlayScene : public Scene
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

	SinglePlayScene(const SinglePlayScene&);
	SinglePlayScene& operator=(const SinglePlayScene&);
public:
	SinglePlayScene(RenderWindow& window, Time& dt);
	virtual ~SinglePlayScene();

	Texture& GetCharacterTex(Characters character);

	void SetCharacter(CharacterScene& characterScene);

	virtual void Init();
	virtual void Release();
	virtual void Update();
	virtual void Draw();

	void SetTimer(float duratino);
	bool isAllAlive() const;
};
