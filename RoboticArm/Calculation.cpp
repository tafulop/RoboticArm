#include "Calculation.h"

namespace RoboticArm {

	// ***************************************
	// Singleton init and method definitions
	// ***************************************
	bool Calculation::instanceFlag = false;
	Calculation* Calculation::single = nullptr;

	// X-structors
	Calculation::Calculation()
	{
	}

	Calculation::~Calculation()
	{
	}

	Calculation * Calculation::getInstance()
	{
		if (instanceFlag == false) {
			instanceFlag = true;
			single = new Calculation();
			return single;
		}
		else {
			return single;
		}
	}


	// ***************************************
	// Normal methods
	// ***************************************

	// Sets the effector position matrix
	Matrix Calculation::calculateEffectorPosition()
	{
		return Matrix();
	}

}