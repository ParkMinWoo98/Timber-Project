#include "StartScene.h"
#include "../Manager/ResourceMgr.h"
#include "../SpriteObject/Background.h"
#include "../Manager/InputMgr.h"

StartScene::StartScene(RenderWindow& window)
	:Scene(window)
{
	bgm.setBuffer(*resourceMgr->GetSoundBuffer("start scene start bgm"));
	background = new Background(*resourceMgr->GetTexture("start scene background"));
}

StartScene::~StartScene()
{
	if (background != nullptr)
		delete background;
	background = nullptr;
}

void StartScene::Init()
{
}

void StartScene::Release()
{
}

void StartScene::Update()
{
	if (InputMgr::GetKeyDown(Keyboard::Key::Return))
		isSceneEnd = true;
}

void StartScene::Draw(RenderWindow& window)
{
	background->Draw(window);
}