#include "Joint.h"


Joint::~Joint()
{
}

Joint::Joint(float maxAxialForce, float maxRadialForce)
{
	
	// get logger singleton
	this->log = Logger::getInstance();
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


