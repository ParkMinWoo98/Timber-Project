#include "Scene.h"
#include "../Manager/ResourceMgr.h"
#include "../SpriteObject/Background.h"

Scene::Scene(RenderWindow& window)
	:window(window), isSceneEnd(false)
{
	resourceMgr = ResourceMgr::GetInstance();
}

Scene::~Scene()
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

void Scene::Update(float dt)
{
}

void Scene::Draw(RenderWindow& window)
{
	
}

bool Scene::GetSceneEnd()
{
	return isSceneEnd;
}
