#pragma once
#include "MovingObj.h"

class Bee : public MovingObj
{
public:
	Bee();
	virtual ~Bee();
	virtual void Init() override;
};

