#include "Joint.h"


Joint::~Joint()
{
}

Joint::Joint(int id, float mass, float maxRadialForce, float maxAxialForce)
{
	
	// get logger singleton
	this->log = Logger::getInstance();
	this->id = id;
	this->mass = mass;
	this->maxAxialForce = maxAxialForce;
	this->maxRadialForce = maxRadialForce;
}

bool Joint::isAxialOutOfLimit(float force)
{
	if (maxAxialForce <= force) 
	{
		return true;
	}
	else 
	{
		return false;
	}
}

bool Joint::isRadialOutOfLimit(float force)
{
	if (maxRadialForce <= force)
	{
		return true;
	}
	else
	{
		return false;
	}
}


