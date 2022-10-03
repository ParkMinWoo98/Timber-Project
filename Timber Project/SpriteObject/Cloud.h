#pragma once
#include "MovingObj.h"

class Cloud : public MovingObj
{
protected:
	Cloud(const Cloud&);
	Cloud& operator=(const Cloud&);
public:
	Cloud(const Texture& tex);
	virtual ~Cloud();

	virtual void Init() override;
};

