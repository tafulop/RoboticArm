#pragma once

#include <iostream>
#include "Logger.h"

namespace RoboticArm {
	class Part
	{

	protected:

		int id;
		float mass;
		int position;
		std::string name;
		Logger* log = Logger::getInstance();

		Part();
		virtual ~Part();

	public:

		// constructor increments the count member variable
		

	};

}