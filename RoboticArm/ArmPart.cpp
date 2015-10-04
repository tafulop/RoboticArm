#include "ArmPart.h"

using namespace RoboticArm;

ArmPart::~ArmPart()
{
}

void RoboticArm::ArmPart::printPartData(Logger::logTarget target)
{
	
	log->printLine("ID:	\t\t" + std::to_string(id), target);
	log->printLine("Name:	\t\t" + name, target);
	log->printLine("Mass:	\t\t" + std::to_string(mass), target);
	log->printLine("Length: \t\t" + std::to_string(length), target);
	log->printLine("", target);

}

std::string RoboticArm::ArmPart::getName()
{
	return this->name;
}

ArmPart::ArmPart(int id, std::string name, float mass, float length)
{
	this->length = length;
	this->id = id;
	this->name = name;
	this->mass = mass;

	log->printLine("ArmPart has been created with the following parameters:", Logger::BOTH);
	this->printPartData(Logger::BOTH);

}
