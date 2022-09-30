#include "StartScene.h"
#include "../Manager/ResourceMgr.h"
#include "../SpriteObject/Background.h"

StartScene::StartScene()
	:Scene()
{
	bgm.setBuffer(*resourceMgr->GetSoundBuffer("start scene start bgm"));
	objList.push_back(new Background(*resourceMgr->GetTexture("start scene background")));
}

StartScene::~StartScene()
{
}

void StartScene::Init()
{

}

void StartScene::Release()
{
}

void StartScene::Update(float dt)
{
}

void StartScene::Draw(RenderWindow& window)
{
	for (auto elem : objList)
		elem->Draw(window);
}