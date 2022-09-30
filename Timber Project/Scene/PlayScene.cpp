#include "PlayScene.h"
#include "../Manager/ResourceMgr.h"
#include "../SpriteObject/Background.h"

PlayScene::PlayScene()
{
	bgm.setBuffer(*resourceMgr->GetSoundBuffer("play scene start bgm"));
	objList.push_back(new Background(*resourceMgr->GetTexture("play scene start background")));

}

PlayScene::~PlayScene()
{
}

void PlayScene::Init()
{
}

void PlayScene::Release()
{
}

void PlayScene::Update(float dt)
{
}

void PlayScene::Draw(RenderWindow& window)
{
}
