#pragma once

#include "Part.h"
#include "ArmPart.h"
#include "Matrix.h"

namespace RoboticArm {

	class Joint : public Part
	{

		friend class PartFactory;

	private:
		Matrix position;
		float maxRadialForce;
		float maxAxialForce;
		float angle;
		Joint(int id, std::string name, float mass, float maxRadialForce, float maxAxialForce);
		

	public:
		~Joint();
		void printPartData(Logger::logTarget target);
		bool isAxialOutOfLimit(float force);
		bool isRadialOutOfLimit(float force);
		bool setPosition(Matrix* position);
		void printPosition(Logger::logTarget target);
		Matrix* getPosition();
	};

}
