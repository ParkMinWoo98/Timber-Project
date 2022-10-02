#pragma once
#include <vector>
#include "../Scene/Scene.h"
#include "SFML/Graphics.hpp"

using namespace std;

enum class Modes;
enum class Characters;

enum class Scenes
{
	Start,
	Mode,
	SingleCharacter,
	SinglePlay,
	DuelCharacter,
	DuelPlay,
};

class SceneMgr
{
private:
	vector<Scene*> sceneList;
	Time& dt;

	Scenes currentScene;
public:
	SceneMgr(RenderWindow& window, Time& dt);
	~SceneMgr();

	void Init();
	void Release();
	void Update();
	void Draw(RenderWindow& window);
};

