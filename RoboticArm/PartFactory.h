#pragma once

#include <iostream>
#include "Joint.h"
#include "ArmPart.h"
#include "Effector.h"
#include "Logger.h"
#include "Body.h"

// PartFactroy implements factory design pattern (singleton too)
namespace RoboticArm {

	class PartFactory
	{
	private:
		static bool instanceFlag;
		static PartFactory* factory;
		int count;
		int id;
		Part* partList[10];
		Logger* log;

		PartFactory();
		~PartFactory();

	public:
		static PartFactory* getInstance();
		int GetNumberOfParts();

		Joint* CreateJoint(float mass, float radialForceLimit, float axialForceLimit);
		ArmPart* CreateArmPart(float mass, float length);
		Effector* CreateEffector(float mass);
		Body* CreateBody(float mass);

	};

}
