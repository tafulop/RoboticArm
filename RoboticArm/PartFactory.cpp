#include "PartFactory.h"

bool PartFactory::instanceFlag = false;
PartFactory* PartFactory::factory = nullptr;


PartFactory::PartFactory()
{
	count = 0;
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

Joint * PartFactory::CreateJoint(int id, float mass, float radialForceLimit, float axialForceLimt)
{
	if (radialForceLimit > 0 && axialForceLimt > 0 && mass > 0)
	{
		count++;
		return new Joint(id, mass, radialForceLimit, axialForceLimt);
	}
	else
	{
		return nullptr;
	}
}

ArmPart * PartFactory::CreateArmPart(int id, float mass, float length)
{
	if (length > 0) 
	{
		count++;
		return new ArmPart(id, mass, length);
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
	

