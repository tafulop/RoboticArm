#include "Joint.h"


Joint::~Joint()
{
}

Joint::Joint(float maxAxialForce, float maxRadialForce)
{
	
	// get logger singleton
	this->log = Logger::getInstance();
	
	// zero and below are not accepted
	try
	{
		if (maxAxialForce > 0)
		{
			this->maxAxialForce = maxAxialForce;
			log->printToDisplay("Max axial force has been set to: " + std::to_string(maxAxialForce));
		}
		else
		{
			log->printToDisplay("Max axial force must be greater than zero.");
			throw 13;
		}
	}
	catch (std::string text)
	{
		log->printToDisplay(text);
	}


	// zero and below are not accepted
	if (maxRadialForce > 0)
	{
		this->maxRadialForce = maxRadialForce;
		log->printToDisplay("Max radial force has been set to: " + std::to_string(maxRadialForce));
	}
	else
	{
		log->printToDisplay("Max radial force must be greater than zero.");
	}
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


