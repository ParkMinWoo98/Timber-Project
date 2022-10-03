#include "CharacterScene.h"
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "../Manager/ResourceMgr.h"
#include "../SpriteObject/SpriteObj.h"
#include "../SpriteObject/Button.h"
#include "../Manager/InputMgr.h"

CharacterScene::CharacterScene(RenderWindow& window)
	:Scene(window)
{
	bgm.setBuffer(*resourceMgr->GetSoundBuffer("sound/game_bgm_character.wav"));
	background = new SpriteObj(*resourceMgr->GetTexture("graphics/background_character.jpg"));
}

CharacterScene::~CharacterScene()
{
	if (background != nullptr)
		delete background;
	background = nullptr;
}

void CharacterScene::Init()
{
	Scene::Init();
	for (auto& character : characters)
	{
		character = Characters::Red;
	}
}

void CharacterScene::Release()
{
}

void CharacterScene::Update()
{
}

void CharacterScene::Draw(RenderWindow& window)
{
}

vector<Characters> CharacterScene::GetCharacters()
{
	return characters;
}
