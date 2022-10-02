#pragma once
#include "PlayScene.h"
#include <Windows.h>
#include <vector>

class CharacterScene;
enum class Characters;

class Player;
class Tree;

class DuelPlayScene : public PlayScene
{
protected:
	DuelPlayScene(const DuelPlayScene&);
	DuelPlayScene& operator=(const DuelPlayScene&);
public:
	DuelPlayScene(RenderWindow& window, Time& dt);
	virtual ~DuelPlayScene();
};
