#pragma once
#include "PlayScene.h"
#include <Windows.h>
#include <vector>

class CharacterScene;
enum class Characters;

class Player;
class Tree;

class SinglePlayScene : public PlayScene
{
protected:
	SinglePlayScene(const SinglePlayScene&);
	SinglePlayScene& operator=(const SinglePlayScene&);
public:
	SinglePlayScene(RenderWindow& window, Time& dt);
	virtual ~SinglePlayScene();
};
