#pragma once

#include "Logger.h"
#include "PartContainer.h"
#include <iostream>
#include "InverseKinematics.h"


namespace RoboticArm {
	
// Singleton
	class ArmRunner
	{
	private:
		// member variables for instancing
		static bool instanceFlag;
		static ArmRunner* single;
		PartContainer* partContainer = PartContainer::getInstance();
		InverseKinematics IK;
		

	public:
		// x-structors
		ArmRunner();
		~ArmRunner();
		static ArmRunner* getInstance();
		Logger* log = Logger::getInstance();
		void createArm();
		void calculate();

			
	};

}