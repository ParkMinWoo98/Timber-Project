#include "Cloud.h"
#include "../Manager/ResourceMgr.h"

Cloud::Cloud()
	:MovingObj(*resourceMgr->GetTexture("cloud png"))
{
}

void Cloud::Init()
{
	vector<float> startVector = { 2000, -300 };
	vector<float> endVector = { -300, 2000 };
	auto index = Utils::Range(0, 2);
	MovingObj::Set({ 200, 400 }, { 100, 400 }, { startVector[index], 0 }, { endVector[index], 0 });
}
