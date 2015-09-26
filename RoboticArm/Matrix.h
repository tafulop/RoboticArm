#pragma once

#include <math.h>
#include <iostream>
#include "Logger.h"

namespace RoboticArm {

	class Matrix
	{

	private:
		
		// variables
		float coordinates[3];
		float hCoordinate;
		Logger* log;

	public:

		// X-structors
		Matrix(float x, float y, float z, float h);
		~Matrix();

		// methods
		void DHTransformation(float qi, float alfa, float di, float ai);
		float getCoordinate(std::string axis);
		void printData(Logger::logTarget target);
	};

}