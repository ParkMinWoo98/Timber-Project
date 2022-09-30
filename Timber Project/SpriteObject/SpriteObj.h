#pragma once
#include <SFML/Graphics.hpp>
#include "../Utils.h"
#include "../Manager/ResourceMgr.h"
#include <vector>

using namespace sf;
using namespace std;

class SpriteObj
{
protected:
	Sprite sprite;
	ResourceMgr* resourceMgr;

	SpriteObj(const SpriteObj& ref);
	SpriteObj& operator=(const SpriteObj& ref);
public:
	SpriteObj(const Texture& tex, const Vector2f& pos = Vector2f());
	virtual ~SpriteObj();

	virtual void Init() {}
	virtual void Release() {};
	virtual void Update(float dt) {};
	virtual void Draw(RenderWindow& window);

	void SetOrigin(Origins origin);
	Vector2f GetSize() const;

	Vector2f GetPosition() const;
	virtual void SetPosition(const Vector2f& pos);
	virtual void SetFlipX(bool flip);
	void Translate(Vector2f delta);
};

