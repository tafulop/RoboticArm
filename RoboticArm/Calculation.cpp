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
			single = new Calculation();
			instanceFlag = true;
			return single;
		}
		else {
			return single;
		}
	}


	// ***************************************
	// Normal methods
	// ***************************************

	// Calculates the effector position with Denavit-Hartenberg transformation
	Matrix Calculation::calculateEffectorPosition()
	{
		Body* b;
		Matrix* temp;
		Matrix result;
		Joint* j;
		ArmPart* a;
		
		std::string next = "B";

		// get body matrix
		b = dynamic_cast<Body*>(PC->findPart("B"));
		b->setPosition(1, 1, 1, 1);
		temp = b->getPosition();

		for (int i = 0; i < 5; i++) {

			// get next armpart and joint
			j = PC->findJoint(next, PartContainer::NEXT);
			a = PC->findArmPart(next, PartContainer::NEXT);

			if (i == 0) {
				result = DHT(temp, 1, 2, 3, 4);
			}
			else {
				result = DHT(&result, 1, 2, i, 4);
			}
		}

		return result;
	}

	/****************************************************************

	Denavit-Hartenberg matrix:

	cos(qi)		-sin(qi)cos(alfa)	sin(qi)sin(alfa)	ai*cos(qi)
	sin(qi)		cos(qi)cos(alfa)	-cos(qi)sin(alfa)	ai*sin(qi)
	0			sin(alfa)			cos(alfa)			di
	0			0					0					1


	>	x = x * cos(qi) + y * sin(qi)
	>	y = x * (-sin(qi)*cos(alfa) + y * cos(qi) * cos(alfa) + z * sin(alfa)
	>	z = x * sin(qi) * sin(alfa) - y * cos(qi) * sin(alfa) + z * cos(alfa)
	>	w = x * ai * cos(qi) + y * ai * sin(qi) + z * di + w

	******************************************************************/
	Matrix Calculation::DHT(Matrix* m, float qi, float alfa, float di, float ai)
	{
		float x, y, z, w, sinAlfa, cosAlfa, sinQi, cosQi;
		Matrix temp;

		x = m->getCoordinate("x");
		y = m->getCoordinate("y");
		z = m->getCoordinate("z");
		w = m->getCoordinate("w");

		sinQi = sin(qi);
		cosQi = cos(qi);
		sinAlfa = sin(alfa);
		cosAlfa = cos(alfa);

		temp.setCoordinate("x", x * cosQi + y * sinQi);
		temp.setCoordinate("y", x * sinQi * cosAlfa + y * cosQi * cosAlfa + z * sinAlfa);
		temp.setCoordinate("z", x * sinQi * sinAlfa - y * cosQi * sinAlfa + z * cosAlfa);
		temp.setCoordinate("w", x * ai * cosQi + y * sinQi + z * di + w);

		return temp;
	}

}