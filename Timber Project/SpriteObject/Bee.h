#pragma once
#include "MovingObj.h"

class Bee : public MovingObj
{
public:
	Bee(const Texture& tex);
	virtual ~Bee();
	virtual void Init() override;
};

