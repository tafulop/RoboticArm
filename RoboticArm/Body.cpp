#include "Body.h"


namespace RoboticArm {

	RoboticArm::Body::Body(int id, std::string name, float mass)
	{
		this->id = id;
		this->name = name;
		this->mass = mass;

		log->printLine("Body has been created with the following parameters:", Logger::logTarget::BOTH);
		this->printPartData(Logger::BOTH);
	}

	RoboticArm::Body::~Body()
	{
	}

	void Body::printPartData(Logger::logTarget target)
	{
		log->printLine("ID: \t\t\t" + std::to_string(id), target);
		log->printLine("Name: \t\t\t" + name, target);
		log->printLine("Mass: \t\t\t" + std::to_string(mass), target);
		log->printLine("", target);
	}

}