#include "ArmPart.h"



ArmPart::~ArmPart()
{
}

ArmPart::ArmPart(int id, float mass, float length)
{
	this->length = length;
	this->id = id;
	this->mass = mass;
}
