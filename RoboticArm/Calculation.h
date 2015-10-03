#pragma once

#include  <map>
#include "Joint.h"
#include "Matrix.h"

namespace RoboticArm{

	class Calculation
	{

	private:
		// private methods
		Calculation();
		~Calculation();

		// private member variables
		static bool instanceFlag;
		static Calculation *single;
		Logger* log = Logger::getInstance();

	public:
		static Calculation* getInstance();
		void calculateEffectorPosition(std::map<std::string, Joint*>* joints, Matrix* EffectorPosition);
	
	};

}