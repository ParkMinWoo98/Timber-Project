#pragma once
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "../Manager/ResourceMgr.h"
#include <list>

class SpriteObj;

using namespace sf;
using namespace std;

class Scene
{
protected:
	Sound bgm;

	RenderWindow& window;
	ResourceMgr* resourceMgr;
	bool isSceneEnd;

	Scene(const Scene&);
	Scene& operator=(const Scene&);
public:
	Scene(RenderWindow& window);
	virtual ~Scene();

	virtual void Init();
	virtual void Release();
	virtual void Update();
	virtual void Draw(RenderWindow& window);

	bool GetSceneEnd();
};

