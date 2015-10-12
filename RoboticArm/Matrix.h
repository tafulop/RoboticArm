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

	public:

		// X-structors
		Matrix();
		Matrix(float x, float y, float z, float w);
		~Matrix();

		// methods
		void DHTransformation(float qi, float alfa, float di, float ai);
		float getCoordinate(std::string axis);
		void printData(Logger::logTarget target);
		void setPosition(float x, float y, float z, float w);
	};

}