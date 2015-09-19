#pragma once
#include "Part.h"

namespace RoboticArm{

	class Body : public Part
	{
		friend class PartFactory;

	private:
		Body(int id, float mass);

	public:
		~Body();
	};

}