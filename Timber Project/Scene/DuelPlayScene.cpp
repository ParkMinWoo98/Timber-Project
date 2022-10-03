#include "DuelPlayScene.h"
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "../Manager/ResourceMgr.h"
#include "../SpriteObject/Tree.h"
#include "../SpriteObject/Player.h"
#include "../Scene/ModeScene.h"
#include "../Scene/CharacterScene.h"
#include "../Manager/InputMgr.h"
#include "PlayScene.h"
#include "../UI/ScoreTextUI.h"
#include "../UI/TimebarUI.h"

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
		objList.push_back(tree[i]);
		objList.push_back(player[i]);
	}
	for (int i = 0; i < 2; ++i)
	{
		scoreTexts.push_back(new ScoreTextUI(*resourceMgr->GetFont("fonts/KOMIKAP_.ttf"), 100));
		timebars.push_back(new TimebarUI());
	}
	Vector2u size = window.getSize();
	for (int i = 0; i < 2; ++i)
	{
		scoreTexts[i]->SetPlayerPtr(player[i]);
		timebars[i]->SetPlayerPtr(player[i]);
		timebars[i]->SetPosition(Vector2f(tree[i]->GetPosition().x - timebars[i]->GetSize().x * 0.5f, size.y - 100));
		UIList.push_back(scoreTexts[i]);
		UIList.push_back(timebars[i]);
	}
	scoreTexts[0]->SetOrigin(Origins::TL);
	scoreTexts[0]->SetPosition(Vector2f(20, 20));
	scoreTexts[1]->SetOrigin(Origins::TR);
	scoreTexts[1]->SetPosition(Vector2f(size.x - 20, 20));
}

DuelPlayScene::~DuelPlayScene()
{
}
