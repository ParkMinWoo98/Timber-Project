#include "SinglePlayScene.h"
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
#include "CharacterScene.h"

SinglePlayScene::SinglePlayScene(RenderWindow& window, Time& dt)
	:PlayScene(window, dt)
{
	characters = { Characters::Red };
	tree.push_back(new Tree(*resourceMgr->GetTexture("graphics/tree.png"), KeyModes::FirstPlayer, Vector2f(this->window.getSize().x * 0.5f, 910)));
	player.push_back(new Player(GetCharacterTex(characters[0])));
	tree[0]->SetPlayerPtr(player[0]);
	player[0]->SetTreePtr(tree[0]);
	objList.push_back(tree[0]);
	objList.push_back(player[0]);
}

SinglePlayScene::~SinglePlayScene()
{
}