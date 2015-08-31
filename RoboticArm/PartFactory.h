#pragma once

#include <iostream>
#include "Joint.h"

// PartFactroy implements factory design pattern (singleton too)


class PartFactory
{
private:
	//std::string[2] = {"Joint", "ArmPart"};
	static bool instanceFlag;
	static PartFactory* factory;
	static int count;

	PartFactory();
	~PartFactory();

public:
	static PartFactory* getInstance();
	Joint* CreateJoint(float radialForceLimit, float RadialForceLimit);
};

