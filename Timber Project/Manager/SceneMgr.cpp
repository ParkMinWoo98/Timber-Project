#include "SceneMgr.h"
#include "../Scene/StartScene.h"
#include "../Scene/ModeScene.h"
#include "../Scene/CharacterScene.h"
#include "../Scene/PlayScene.h"

SceneMgr::SceneMgr()
	:currentScene(Scenes::start)
{
	sceneList.push_back(new StartScene)
}

SceneMgr::~SceneMgr()
{
}
