#include "ArmPart.h"

using namespace RoboticArm;

ArmPart::~ArmPart()
{
}

ArmPart::ArmPart(int id, float mass, float length)
{
	this->length = length;
	this->id = id;
	this->mass = mass;
}
