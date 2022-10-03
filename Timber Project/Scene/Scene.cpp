#include "Scene.h"
#include "../Manager/ResourceMgr.h"
#include "../SpriteObject/SpriteObj.h"
#include "ModeScene.h"
#include "CharacterScene.h"

Scene::Scene(RenderWindow& window)
	:window(window), isSceneEnd(false)
{
	resourceMgr = ResourceMgr::GetInstance();
}

Scene::~Scene()
{
}

void Scene::SetCharacterScene(vector<Characters> vec)
{
}

void Scene::Init()
{
	bgm.setLoop(true);
	bgm.play();
}

void Scene::Release()
{
}

void Scene::Update()
{
}

void Scene::Draw(RenderWindow& window)
{
	
}

void Scene::BgmEnd()
{
	bgm.stop();
}

Modes Scene::GetMode() const
{
	return Modes::single;
}

vector<Characters> Scene::GetCharacters()
{
	return vector<Characters>();
}

void Scene::SetSceneEnd(bool isSceneEnd)
{
	this->isSceneEnd = isSceneEnd;
}

bool Scene::GetSceneEnd()
{
	return isSceneEnd;
}
