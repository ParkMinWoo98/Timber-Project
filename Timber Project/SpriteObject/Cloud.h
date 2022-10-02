#pragma once
#include "MovingObj.h"

class Cloud : public MovingObj
{
public:
	Cloud(const Texture& tex);
	virtual ~Cloud();

	virtual void Init() override;
};

