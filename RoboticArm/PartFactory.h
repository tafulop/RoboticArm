#pragma once

#include <iostream>
#include "Joint.h"
#include "ArmPart.h"

// PartFactroy implements factory design pattern (singleton too)


class PartFactory
{
private:
	//std::string[2] = {"Joint", "ArmPart"};
	static bool instanceFlag;
	static PartFactory* factory;
	int count;

	PartFactory();
	~PartFactory();

public:
	static PartFactory* getInstance();
	Joint* CreateJoint(int id, float mass, float radialForceLimit, float RadialForceLimit);
	ArmPart* CreateArmPart(int id, float mass, float length);
	int GetNumberOfParts();
};

