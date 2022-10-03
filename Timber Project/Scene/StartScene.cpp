#include "StartScene.h"
#include "../Manager/ResourceMgr.h"
#include "../SpriteObject/SpriteObj.h"
#include "../Manager/InputMgr.h"

StartScene::StartScene(RenderWindow& window)
	:Scene(window)
{
	bgm.setBuffer(*resourceMgr->GetSoundBuffer("sound/game_bgm_start.wav"));
	background = new SpriteObj(*resourceMgr->GetTexture("graphics/background_start.jpg"));
}

StartScene::~StartScene()
{
	if (background != nullptr)
		delete background;
	background = nullptr;
}

void StartScene::Init()
{
	Scene::Init();
}

void StartScene::Release()
{
	Scene::Release();
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