#pragma once

#include <math.h>
#include <iostream>
#include "Logger.h"

namespace RoboticArm {

	class Matrix
	{

	private:
		
		// default constructor -- needed for part - matrix map
		//;
		
		// variables
		float x, y, z, w;
		Logger* log = Logger::getInstance();
		bool inited = false;

	public:

		// X-structors
		Matrix();
		Matrix(float x, float y, float z, float w);
		~Matrix();

		// methods
		float getCoordinate(std::string axis);
		void setCoordinate(std::string axis, float value);
		void printData(Logger::logTarget target);
		void setPosition(float x, float y, float z, float w);
		bool isInitialized();
	};

}