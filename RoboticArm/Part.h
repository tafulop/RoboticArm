#pragma once

#include <iostream>
#include "Logger.h"

static const std::string TYPE_ARMPART = "ArmPart";
static const std::string TYPE_BODY = "Body";
static const std::string TYPE_EFFECTOR = "Effector";
static const std::string TYPE_JOINT = "Joint";


namespace RoboticArm {
	class Part
	{

	protected:

		std::string type;
		int id;
		float mass;
		int position;
		std::string name;
		Logger* log = Logger::getInstance();

		Part();
		virtual ~Part();

	public:
		
		std::string getType();
		bool isTypeOf(std::string);
		std::string getName();

		// constructor increments the count member variable
		

	};

}