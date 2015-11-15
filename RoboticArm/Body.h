#pragma once
#include "Part.h"
#include "Matrix.h"

namespace RoboticArm{

	class Body : public Part
	{
		friend class PartFactory;

	private:
		Body(int id, std::string name, float mass);
		Matrix position;

	public:
		~Body();
		void printPartData(Logger::logTarget target);
		Matrix* getPosition();
		void setPosition(float, float, float, float);
	};

}