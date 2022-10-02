#include "Bee.h"

Bee::Bee(const Texture& tex)
	:MovingObj(tex)
{
}

Bee::~Bee()
{
}

void Bee::Init()
{
	MovingObj::Set({ 200, 400 }, { 500, 1000 }, { 2000, 0 }, { -100, 0 });
	MovingObj::Init();
}
