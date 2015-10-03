#pragma once
#include "Part.h"

namespace RoboticArm{

	class Body : public Part
	{
		friend class PartFactory;

	private:
		Body(int id, std::string name, float mass);

	public:
		~Body();
		void printPartData(Logger::logTarget target);
	};

}