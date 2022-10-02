#include "DuelPlayScene.h"
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "../Manager/ResourceMgr.h"
#include "../SpriteObject/Background.h"
#include "../SpriteObject/Bee.h"
#include "../SpriteObject/Cloud.h"
#include "../SpriteObject/Tree.h"
#include "../SpriteObject/Player.h"
#include "../Scene/ModeScene.h"
#include "../Scene/CharacterScene.h"
#include "../Manager/InputMgr.h"
#include "PlayScene.h"

DuelPlayScene::DuelPlayScene(RenderWindow& window, Time& dt)
	:PlayScene(window, dt)
{
	characters = { Characters::Red, Characters::Red };
	tree.push_back(new Tree(*resourceMgr->GetTexture("graphics/tree.png"), KeyModes::FirstPlayer, Vector2f(this->window.getSize().x * 0.25f, 910)));
	tree.push_back(new Tree(*resourceMgr->GetTexture("graphics/tree2.png"), KeyModes::SecondPlayer, Vector2f(this->window.getSize().x * 0.75f, 910)));
	player.push_back(new Player(GetCharacterTex(characters[0])));
	player.push_back(new Player(GetCharacterTex(characters[1]), KeyModes::SecondPlayer));
	for (int i = 0; i < 2; ++i)
	{
		player[i]->SetTreePtr(tree[i]);
		tree[i]->SetPlayerPtr(player[i]);
	}
	for (int i = 0; i < 2; ++i)
	{
		objList.push_back(tree[i]);
		objList.push_back(player[i]);
	}
}

DuelPlayScene::~DuelPlayScene()
{
}
