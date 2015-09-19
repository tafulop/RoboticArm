#include "PartFactory.h"

using namespace RoboticArm;

bool PartFactory::instanceFlag = false;
PartFactory* PartFactory::factory = nullptr;


PartFactory::PartFactory()
{
	count = 0;
	id = 0;
	log = Logger::getInstance();
}


PartFactory::~PartFactory()
{
	instanceFlag = false;
}

PartFactory* PartFactory::getInstance()
{
	if (!instanceFlag)
	{
		factory = new PartFactory();
		instanceFlag = true;
		return factory;
	}
	else
	{
		return factory;
	}

}

Joint * PartFactory::CreateJoint(float mass, float radialForceLimit, float axialForceLimt)
{
	if (radialForceLimit > 0 && axialForceLimt > 0 && mass > 0)
	{
		count++;

		log->printLine("Joint has been created with the following parameters:", Logger::logTarget::BOTH);
		log->printLine("ID:	\t\t" + std::to_string(this->id), Logger::logTarget::BOTH);
		log->printLine("Mass:	\t\t" + std::to_string(mass), Logger::logTarget::BOTH);
		log->printLine("Radial limit:	\t" + std::to_string(radialForceLimit), Logger::logTarget::BOTH);
		log->printLine("Axial limit:	\t" + std::to_string(axialForceLimt), Logger::logTarget::BOTH);
		log->printLine("", Logger::logTarget::BOTH);


		return new Joint(this->id++, mass, radialForceLimit, axialForceLimt);
	}
	else
	{
		return nullptr;
	}
}

ArmPart * PartFactory::CreateArmPart(float mass, float length)
{
	if (length > 0 && mass> 0) 
	{
		count++;
		log->printLine("ArmPart has been created with the following parameters:", Logger::logTarget::BOTH);
		log->printLine("ID:	\t\t"	+ std::to_string(this->id), Logger::logTarget::BOTH);
		log->printLine("Mass:	\t\t"	+ std::to_string(mass), Logger::logTarget::BOTH);
		log->printLine("Length: \t\t"+ std::to_string(length), Logger::logTarget::BOTH);
		log->printLine("", Logger::logTarget::BOTH);

		return new ArmPart(this->id++, mass, length);
	}
	else
	{
		return nullptr;
	}
}

Effector * PartFactory::CreateEffector(float mass)
{
	if (mass > 0)
	{
		count++;
		
		log->printLine("Effector has been created with the following parameters:", Logger::logTarget::BOTH);
		log->printLine("ID: \t\t\t" + std::to_string(id), Logger::logTarget::BOTH);
		log->printLine("Mass: \t\t\t" + std::to_string(mass), Logger::logTarget::BOTH);
		log->printLine("", Logger::logTarget::BOTH);

		return new Effector(this->id++, mass);
	}
	else
	{
		return nullptr;
	}
}

Body * RoboticArm::PartFactory::CreateBody(float mass)
{
	if (mass > 0) {
		count++;

		log->printLine("Body has been created with the following parameters:", Logger::logTarget::BOTH);
		log->printLine("ID: \t\t\t" + std::to_string(id), Logger::logTarget::BOTH);
		log->printLine("Mass: \t\t\t" + std::to_string(mass), Logger::logTarget::BOTH);
		log->printLine("", Logger::logTarget::BOTH);

		return new Body(this->id++, mass);
	}
	return nullptr;
}

int PartFactory::GetNumberOfParts()
{
	return count;
}
	

