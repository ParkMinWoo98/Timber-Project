#include "SinglePlayScene.h"
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "../Manager/ResourceMgr.h"
#include "../SpriteObject/SpriteObj.h"
#include "../SpriteObject/Tree.h"
#include "../SpriteObject/Player.h"
#include "../Scene/ModeScene.h"
#include "../Scene/CharacterScene.h"
#include "../Manager/InputMgr.h"
#include "CharacterScene.h"
#include "../UI/ScoreTextUI.h"
#include "../UI/TimebarUI.h"

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
	scoreTexts.push_back(new ScoreTextUI(*resourceMgr->GetFont("fonts/KOMIKAP_.ttf"), 100));
	timebars.push_back(new TimebarUI());
	Vector2u size = window.getSize();
	scoreTexts[0]->SetPlayerPtr(player[0]);
	scoreTexts[0]->SetOrigin(Origins::TL);
	scoreTexts[0]->SetPosition(Vector2f(20, 20));
	timebars[0]->SetPlayerPtr(player[0]);
	timebars[0]->SetPosition(Vector2f(tree[0]->GetPosition().x - timebars[0]->GetSize().x * 0.5f, size.y - 100));
	UIList.push_back(scoreTexts[0]);
	UIList.push_back(timebars[0]);
}

SinglePlayScene::~SinglePlayScene()
{
}