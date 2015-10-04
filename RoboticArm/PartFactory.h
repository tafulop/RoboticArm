#pragma once

#include <iostream>
#include "Joint.h"
#include "ArmPart.h"
#include "Effector.h"
#include "Logger.h"
#include "Body.h"
#include <iostream>
#include <map>

// PartFactroy implements factory design pattern (singleton too)
namespace RoboticArm {

	class PartFactory
	{
	private:
		// Factory instance variables
		static bool instanceFlag;
		static PartFactory* factory;
		//Logger::logTarget target = Logger::BOTH;
		
		// Variables for the created parts
		int count;
		int id;

		// Parts
		std::map<std::string, Body> bodies;
		std::map<std::string, Effector> effectors;
		std::map<std::string, Joint> joints;
		std::map<std::string, ArmPart> armParts;

		// Log part instancing
		Logger* log;

		// X-strutors
		PartFactory();
		~PartFactory();

	public:
		// Part factory instance methods
		static PartFactory* getInstance();
		int GetNumberOfParts();

		// Part creating methods
		Joint CreateJoint(std::string name, float mass, float radialForceLimit, float axialForceLimit);
		ArmPart CreateArmPart(std::string name, float mass, float length);
		Effector CreateEffector(std::string name, float mass);
		Body CreateBody(std::string name, float mass);
		Part* GetPartByName(std::string name);
		Joint * GetJointByName(std::string name);
		ArmPart * GetArmPartByName(std::string name);
		Effector* GetEffectorByName(std::string name);
		Body * GetBodyByName(std::string name);

	};

}
