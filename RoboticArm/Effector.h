#pragma once
#include "Part.h"
namespace RoboticArm {

	class Effector :
		public Part
	{
		friend class PartFactory;

	private:
		Effector(int id, std::string name, float mass);
	public:
		//Effector();
		~Effector();
		void printPartData(Logger::logTarget target);
	};

}