#pragma once

#include "Logger.h"
#include "PartFactory.h"
#include "Matrix.h"
#include <map>
#include "Calculation.h"
#include <iostream>

namespace RoboticArm {
	
// Singleton
	class ArmCreator
	{
	private:
		// x-structors
		ArmCreator();
		~ArmCreator();

		// member variables for instancing
		static bool instanceFlag;
		static ArmCreator* single;

		// Other member vars
		Matrix EffectorPosition = Matrix(0,0,0,0);
		Calculation* calc = Calculation::getInstance();
		
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
		void calcEffectorPosition();
		void printEffectorMatrix();

	};

}