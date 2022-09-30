#include "Scene.h"
#include "../Manager/ResourceMgr.h"
#include "../SpriteObject/Background.h"

Scene::Scene()
{
	resourceMgr = ResourceMgr::GetInstance();
}

Scene::~Scene()
{
}
