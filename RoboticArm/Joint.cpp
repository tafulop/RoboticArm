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

void Joint::setBonds(ArmPart* prev, ArmPart* next)
{
	log->printLine("Joint bonded to following parts:", Logger::BOTH);
	log->printLine("Joint name: \t\t" + this->name, Logger::BOTH);

	if (prev != nullptr) {
		this->prevArmPart = prev;
		log->printLine("Prev name: \t\t" + this->prevArmPart->getName(), Logger::BOTH);
	}

	if (next != nullptr) {
		this->nextArmPart = next;
		log->printLine("Next name: \t\t" + this->nextArmPart->getName(), Logger::BOTH);
	}
	log->printLine("", Logger::BOTH);
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


