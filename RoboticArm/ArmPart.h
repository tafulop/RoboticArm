#pragma once
#include "Part.h"

namespace RoboticArm {

	class ArmPart : public Part
	{
		friend class PartFactory;

	private:
		float length;
		ArmPart(int id, std::string name, float mass, float length);

	public:	
		~ArmPart();
		void printPartData(Logger::logTarget target);
		std::string getName();

	};

}