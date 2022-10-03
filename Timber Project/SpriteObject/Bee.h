#pragma once
#include "MovingObj.h"

class Bee : public MovingObj
{
protected:
	Bee(const Bee&);
	Bee& operator=(const Bee&);
public:
	Bee(const Texture& tex);
	virtual ~Bee();
	virtual void Init() override;
};

