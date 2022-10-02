#pragma once
#include "Scene.h"
#include <Windows.h>
#include <vector>

enum class Characters;

class Player;
class Tree;

class PlayScene : public Scene
{
protected:
	list<SpriteObj*> objList;
	vector<Characters> characters;

	vector<Player*> player;
	vector<Tree*> tree;

	Time& dt;
	float timer;
	float duration;
	bool isPause;

	Sound timeOutSound;

	PlayScene(const PlayScene&);
	PlayScene& operator=(const PlayScene&);
public:
	PlayScene(RenderWindow& window, Time& dt);
	virtual ~PlayScene();

	virtual void SetCharacterScene(vector<Characters> vec);
	Texture& GetCharacterTex(Characters character);

	virtual void Init();
	virtual void Release();
	virtual void Update();
	virtual void Draw(RenderWindow& window);

	void SetTimer(float duration);
	bool isAllAlive() const;
};
