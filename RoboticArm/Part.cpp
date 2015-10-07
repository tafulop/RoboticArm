#include "Part.h"

 namespace RoboticArm{

	Part::Part()
	{

	}


	Part::~Part()
	{

	}

	std::string RoboticArm::Part::getType()
	{
		return this->type;
	}

	bool RoboticArm::Part::isTypeOf(std::string type)
	{
		if (this->type == type) {
			return true;
		}
		else {
			return false;
		}
	}

	std::string Part::getName()
	{
		return this->name;
	}


}