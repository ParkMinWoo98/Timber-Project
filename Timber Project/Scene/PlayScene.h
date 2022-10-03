#pragma once
#include "Scene.h"
#include <Windows.h>
#include <vector>

enum class Characters;
class Player;
class Tree;
class UI;
class TextUI;
class ScoreTextUI;
class TimebarUI;

class PlayScene : public Scene
{
protected:
	list<SpriteObj*> objList;
	list<UI*> UIList;
	vector<Characters> characters;

	vector<Player*> player;
	vector<Tree*> tree;
	TextUI* messageText;
	vector<ScoreTextUI*> scoreTexts;
	vector<TimebarUI*> timebars;

	Time& dt;
	bool isPause;

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

	bool isAllAlive() const;
};
