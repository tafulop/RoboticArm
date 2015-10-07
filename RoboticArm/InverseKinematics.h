#pragma once
#include "Calculation.h"
#include "Matrix.h"
#include "PartContainer.h"

namespace RoboticArm {

	class InverseKinematics : public Calculation
	{
	private:
		Matrix effectorWorldCoordinates;

	protected:	
		PartContainer* PC = PartContainer::getInstance();

	public:
		InverseKinematics();
		~InverseKinematics();

		void initJoints();
		void calcEffectorPosition();

		Matrix DenavitHartenbergTrans(Matrix* jointMatrix, float qi, float alfa, float di, float ai);
	};

}