#pragma once
#include "Part.h"
namespace RoboticArm {

	class Effector :
		public Part
	{
		friend class PartFactory;

	private:
		Effector(int id, float mass);
	public:
		//Effector();
		~Effector();
	};

}