#include "PartFactory.h"

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
		return new Joint(this->id++, mass, radialForceLimit, axialForceLimt);
	}
	else
	{
		return nullptr;
	}
}

ArmPart * PartFactory::CreateArmPart(float mass, float length)
{
	if (length > 0) 
	{
		count++;
		log->printToDisplay("ArmPart has been created with following parameters:");
		log->printToDisplay("Id:	\t\t"	+ std::to_string(this->id));
		log->printToDisplay("Mass:	\t\t"	+ std::to_string(mass));
		log->printToDisplay("Length: \t\t"+ std::to_string(length));
		log->printToDisplay("");

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
		log->printToDisplay("Effector has been created. Mass: " + std::to_string(mass));
		return new Effector(mass);
	}
	else
	{
		return nullptr;
	}
}

int PartFactory::GetNumberOfParts()
{
	return count;
}
	

