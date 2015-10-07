#include "Effector.h"

using namespace RoboticArm;

Effector::Effector(int id, std::string name, float mass)
{
	this->name = name;
	this->mass = mass;
	this->id = id;
	this->type = TYPE_EFFECTOR;

	log->printLine("Effector has been created with the following parameters:", Logger::logTarget::BOTH);
	this->printPartData(Logger::BOTH);
}

Effector::~Effector()
{
}

void RoboticArm::Effector::printPartData(Logger::logTarget target)
{
	log->printLine("Name: \t\t\t" + name, Logger::logTarget::BOTH);
	log->printLine("ID: \t\t\t" + std::to_string(id), Logger::logTarget::BOTH);
	log->printLine("Mass: \t\t\t" + std::to_string(mass), Logger::logTarget::BOTH);
	log->printLine("", Logger::logTarget::BOTH);
}
