#pragma once
#include <list>
#include "../Scene/Scene.h"

using namespace std;

enum class Scenes
{
	start,
	mode,
	character,
	play,
};

class SceneMgr
{
private:
	list<Scene*> sceneList;

	Scenes currentScene;
public:
	SceneMgr();
	~SceneMgr();


};

