#pragma once

#include "Part.h"
#include "ArmPart.h"

namespace RoboticArm {

	class Joint : public Part
	{

		friend class PartFactory;

	private:
		float maxRadialForce;
		float maxAxialForce;
		float angle;
		ArmPart* nextArmPart;
		ArmPart* prevArmPart;
		Joint(int id, std::string name, float mass, float maxRadialForce, float maxAxialForce);
		

	public:
		~Joint();
		void printPartData(Logger::logTarget target);
		void setBonds(ArmPart* prev, ArmPart* next);
		bool isAxialOutOfLimit(float force);
		bool isRadialOutOfLimit(float force);
	};

}
