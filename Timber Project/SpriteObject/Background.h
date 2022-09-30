#pragma once
#include "SpriteObj.h"

class Background : public SpriteObj
{
protected:
	Background(const Background&);
	Background& operator=(const Background&);
public:
	Background(const Texture& tex, const Vector2f& pos = Vector2f());
	virtual ~Background();

	virtual void Draw(RenderWindow& window);
};

