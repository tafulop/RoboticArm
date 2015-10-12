#include "InverseKinematics.h"

namespace RoboticArm {

	InverseKinematics::InverseKinematics()
	{
	}

	InverseKinematics::~InverseKinematics()
	{
	}

	void InverseKinematics::initJoints()
	{
	/*	jointMatrixes[0].setPosition(123.2, 445.6, 337, 545);
		jointMatrixes[1].setPosition(453, 445.6, 337, 6);
		jointMatrixes[2].setPosition(25, 445.6, 337, 5455);
		jointMatrixes[3].setPosition(123.2, 354, 337, 45);
		jointMatrixes[4].setPosition(1236.2, 445.6, 337, 5455);*/
	}

	

	void InverseKinematics::calcEffectorPosition()
	{
		std::string next = "B";
		Joint* j;
		ArmPart* a;


		for (int i = 0; i < 5;i++) {
			
			// get next armpart and joint
			j = PC->findJoint(next, PartContainer::NEXT);
			a = PC->findArmPart(next, PartContainer::NEXT);

			// set jwc array
			this->jointWorldCoordinates[i] = DenavitHartenbergTrans(j->getPosition(), 1, 2, 3, 4);

			// get joint
			next = j->getName();
			j->printPartData(Logger::CONSOLE);
		}

		this->effectorWorldCoordinates = jointWorldCoordinates[4];
		effectorWorldCoordinates.printData(Logger::BOTH);

	}

	
	Matrix InverseKinematics::DenavitHartenbergTrans(Matrix* jointMatrix, float qi, float alfa, float di, float ai)
	{
		float x, y, z, w, sinAlfa, cosAlfa, sinQi, cosQi, nx, nz, ny, nw;
		Matrix temp;

		x = jointMatrix->getCoordinate("x");
		y = jointMatrix->getCoordinate("y");
		z = jointMatrix->getCoordinate("z");
		w = jointMatrix->getCoordinate("w");

		sinQi = sin(qi);
		cosQi = cos(qi);
		sinAlfa = sin(alfa);
		cosAlfa = cos(alfa);

		nx = x * cosQi + y * sinQi;
		ny = x * sinQi * cosAlfa + y * cosQi * cosAlfa + z * sinAlfa;
		nz = x * sinQi * sinAlfa - y * cosQi * sinAlfa + z * cosAlfa;
		nw = x * ai * cosQi + y * sinQi + z * di + w;

		temp.setPosition(nx, ny, nz, nw);

		return temp;
	}

}