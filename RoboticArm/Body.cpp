#include "Body.h"


namespace RoboticArm {

	RoboticArm::Body::Body(int id, std::string name, float mass)
	{
		this->id = id;
		this->name = name;
		this->mass = mass;
		this->type = TYPE_BODY;

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

	Matrix* Body::getPosition() {
		return &this->position;
	}

	void Body::setPosition(float x, float y, float z, float w)
	{
		this->position.setPosition(x, y, z, w);
	}

}