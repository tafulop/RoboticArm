#pragma once
#include "Calculation.h"
#include "Matrix.h"
#include "PartContainer.h"

namespace RoboticArm {

	class InverseKinematics : public Calculation
	{
	private:
		Matrix jointWorldCoordinates[5];
		Matrix effectorWorldCoordinates;
		Logger* log = Logger::getInstance();

	protected:	
		PartContainer* PC = PartContainer::getInstance();
		Matrix DenavitHartenbergTrans(Matrix* jointMatrix, float qi, float alfa, float di, float ai);

	public:
		InverseKinematics();
		~InverseKinematics();

		void initJoints();
		void calcEffectorPosition();

		
	};

}