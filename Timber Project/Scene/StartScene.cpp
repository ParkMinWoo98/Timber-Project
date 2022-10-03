#include "StartScene.h"
#include "../Manager/ResourceMgr.h"
#include "../SpriteObject/SpriteObj.h"
#include "../SpriteObject/Button.h"
#include "../Manager/InputMgr.h"

StartScene::StartScene(RenderWindow& window)
	:Scene(window)
{
	bgm.setBuffer(*resourceMgr->GetSoundBuffer("sound/game_bgm_start.wav"));
	background = new SpriteObj(*resourceMgr->GetTexture("graphics/background_start.jpg"));
	button = new Button(*resourceMgr->GetTexture("graphics/Press_to_Start.png"), Vector2f(window.getSize().x * 0.5f, window.getSize().y * 0.5f));
}

StartScene::~StartScene()
{
	if (background != nullptr)
		delete background;
	background = nullptr;
	if (button != nullptr)
		delete button;
	button = nullptr;
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
	{
		button->ButtonEffect();
		isSceneEnd = true;
	}
}

void StartScene::Draw(RenderWindow& window)
{
	background->Draw(window);
	button->Draw(window);
}