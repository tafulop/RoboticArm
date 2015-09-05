#include "Effector.h"

using namespace RoboticArm;

Effector::Effector(int id, float mass)
{
	this->mass = mass;
	this->id = id;
}

Effector::~Effector()
{

}
