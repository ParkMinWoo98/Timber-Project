#include "Branch.h"

Branch::Branch(Sprite& treeBody)
	:SpriteObj(*resourceMgr->GetTexture("branch png")), treeBody(treeBody), side(Sides::Left)
{
}

Branch::~Branch()
{
}

void Branch::Init()
{
	FloatRect rect = treeBody.getLocalBounds();
	Vector2f treeSize = { rect.width, rect.height };
	Vector2f branchSize = GetSize();
	sprite.setOrigin(-treeSize.x * 0.5f, branchSize.y * 0.5f);
	SetPosition(treeBody.getPosition());
}

void Branch::Draw(RenderWindow& window)
{
	if (side == Sides::None)
		return;
	SpriteObj::Draw(window);
}

void Branch::SetSide(Sides side)
{
	switch (side)
	{
	case Sides::Left:
		sprite.setScale(-1, 1);
		break;
	case Sides::Right:
		sprite.setScale(1, 1);
		break;
	}
	this->side = side;
}

Sides Branch::GetSide()
{
	return side;
}
