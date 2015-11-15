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
	if (!instanceFlag)	{
		factory = new PartFactory();
		instanceFlag = true;
		return factory;
	}	else	{
		return factory;
	}
}

Joint PartFactory::CreateJoint(std::string name, float mass, float radialForceLimit, float axialForceLimt)
{
	if (radialForceLimit > 0 && axialForceLimt > 0 && mass > 0 && name.empty() == false)	{
		count++;
		return Joint(this->id++, name, mass, radialForceLimit, axialForceLimt);
	}	else	{
		throw - 1;
	}
}

ArmPart PartFactory::CreateArmPart(std::string name, float mass, float length)
{
	if (length > 0 && mass> 0 && name.empty() == false) {
		count++;
		return ArmPart(this->id++, name, mass, length);
	}	else	{
		throw - 1;
	}
}

Effector PartFactory::CreateEffector(std::string name, float mass)
{
	if (mass > 0 && name.empty() == false)	{
		count++;
		return Effector(this->id++, name, mass);

	}	else	{
		throw - 1;
	}
}

Body RoboticArm::PartFactory::CreateBody(std::string name, float mass)
{
	if (mass > 0 && name.empty() == false) {
		count++;
		return Body(this->id++, name, mass);

	} else {
		throw -1;
	}
}

int PartFactory::GetNumberOfParts()
{
	return count;
}
	

