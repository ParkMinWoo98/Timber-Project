#pragma once
#include "MovingObj.h"

class Cloud : public MovingObj
{
public:
	Cloud();
	virtual ~Cloud();

	virtual void Init() override;
};

