#pragma once

#include "Logger.h"
#include "PartFactory.h"
#include "Matrix.h"
#include <map>

namespace RoboticArm {
	
	class ArmCreator
	{
	private:
		// x-structors
		ArmCreator();
		~ArmCreator();

		// member variables for instancing
		static bool instanceFlag;
		static ArmCreator* single;
		
		// common
		
		PartFactory* factory = PartFactory::getInstance();

		// Single parts
		Body* body;
		Effector* effector;
		
		// Multiple parts
		std::map<std::string, Joint*> joints;
		std::map<std::string, ArmPart*> armParts;
		std::map<std::string, Matrix> jointCoordinates;

		// creating methods
		void createJoints();
		void createArmParts();
		void setCoordinates();
		
	public:
		Logger* logger = Logger::getInstance();
		static ArmCreator* getInstance();
		void createRoboticArm();

	};

}