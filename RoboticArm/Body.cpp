#include "Body.h"


namespace RoboticArm {

	RoboticArm::Body::Body(int id, float mass)
	{
		this->id = id;
		this->mass = mass;
	}

	RoboticArm::Body::~Body()
	{
	}

}