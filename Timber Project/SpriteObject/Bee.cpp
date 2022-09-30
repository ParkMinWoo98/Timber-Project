#include "Bee.h"

Bee::Bee()
	:MovingObj(*resourceMgr->GetTexture("bee png"))
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
