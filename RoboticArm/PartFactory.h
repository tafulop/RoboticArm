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
	static bool instanceFlag;
	static PartFactory* factory;
	int count;
	int id;
	Logger* log;

	PartFactory();
	~PartFactory();

public:
	static PartFactory* getInstance();
	int GetNumberOfParts();
	
	Joint* CreateJoint(float mass, float radialForceLimit, float axialForceLimit);
	ArmPart* CreateArmPart(float mass, float length);
	Effector* CreateEffector(float mass);
	
};

