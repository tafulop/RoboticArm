#include "Joint.h"

using namespace RoboticArm;

Joint::~Joint()
{
}

Joint::Joint(int id, std::string name, float mass, float maxRadialForce, float maxAxialForce)
{
	
	// get logger singleton
	this->log = Logger::getInstance();
	this->id = id;
	this->name = name;
	this->mass = mass;
	this->maxAxialForce = maxAxialForce;
	this->maxRadialForce = maxRadialForce;
	this->type = TYPE_JOINT;

	log->printLine("Joint has been created with the following parameters:", Logger::BOTH);
	this->printPartData(Logger::BOTH);

}

void Joint::printPartData(Logger::logTarget target) {

	log->printLine("ID:	\t\t" + std::to_string(this->id), target);
	log->printLine("Name:	\t\t" + name, target);
	log->printLine("Mass:	\t\t" + std::to_string(mass), target);
	log->printLine("Radial limit:	\t" + std::to_string(this->maxRadialForce), target);
	log->printLine("Axial limit:	\t" + std::to_string(this->maxAxialForce), target);
	log->printLine("", target);

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


