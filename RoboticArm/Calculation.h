#pragma once

#include "Matrix.h"
#include "PartContainer.h"
#include "Logger.h"

namespace RoboticArm{

	class Calculation
	{

	private:
		static Calculation* single;
		static bool instanceFlag;
		Logger* log = Logger::getInstance();
		PartContainer* PC = PartContainer::getInstance();
		Calculation();
		~Calculation();

	public:
		
		static Calculation* getInstance();

		// Normal method declarations
		Matrix calculateEffectorPosition();
		Matrix DHT(Matrix*, float, float, float, float);
		
	};

}