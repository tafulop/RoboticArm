#pragma once

#include "Matrix.h"
#include "PartContainer.h"

namespace RoboticArm{

	class Calculation
	{

	private:
		static Calculation* single;
		static bool instanceFlag;
		Logger* log = Logger::getInstance();
		PartContainer* PC = PartContainer::getInstance();


	public:
		Calculation();
		~Calculation();
		Calculation* getInstance();

		// Normal method declarations
		Matrix calculateEffectorPosition();
		
	};

}