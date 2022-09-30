#pragma once
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include <list>

class SpriteObj;

using namespace sf;
using namespace std;

class Scene
{
protected:
	Sound bgm;
	list<SpriteObj*> objList;
public:
	Scene();
	virtual ~Scene();

	virtual void Init();
	virtual void Release();
	virtual void Update(float dt);
	virtual void Draw(RenderWindow& window);
};

