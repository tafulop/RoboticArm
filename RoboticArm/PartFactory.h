#pragma once

#include <iostream>
#include "Joint.h"
#include "ArmPart.h"
#include "Effector.h"
#include "Logger.h"

// PartFactroy implements factory design pattern (singleton too)


class PartFactory
{
private:
	//std::string[2] = {"Joint", "ArmPart"};
	static bool instanceFlag;
	static PartFactory* factory;
	int count;
	int id;
	Logger* log;

	PartFactory();
	~PartFactory();

public:
	static PartFactory* getInstance();
	Joint* CreateJoint(float mass, float radialForceLimit, float RadialForceLimit);
	ArmPart* CreateArmPart(float mass, float length);
	Effector* CreateEffector(float mass);
	int GetNumberOfParts();
};

