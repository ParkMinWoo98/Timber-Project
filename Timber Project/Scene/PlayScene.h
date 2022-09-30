#pragma once
#include "Scene.h"
#include <Windows.h>
#include <vector>

class ModeScene;
enum class Characters;

class Player;
class Tree;

class PlayScene : public Scene
{
protected:
	list<SpriteObj*> objList;
	Modes currentMode;
	vector<Characters> characters;

	vector<Player*> player;
	vector<Tree*> tree;

	ModeScene& modeScene;

	Time& dt;
	float timer;
	float duration;
	bool isPause;

	Sound timeOutSound;

	PlayScene(const PlayScene&);
	PlayScene& operator=(const PlayScene&);
public:
	PlayScene(Modes mode, vector<Characters> characters, RenderWindow& window, Time& dt);
	virtual ~PlayScene();

	Texture& GetCharacterTex(Characters character);

	virtual void Init();
	virtual void Release();
	virtual void Update();
	virtual void Draw();

	void SetTimer(float duratino);
	bool isAllAlive() const;
};