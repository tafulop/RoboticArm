#include "PartFactory.h"

bool PartFactory::instanceFlag = false;
PartFactory* PartFactory::factory = nullptr;


PartFactory::PartFactory()
{
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

Joint * PartFactory::CreateJoint(float radialForceLimit, float axialForceLimt)
{
	if (radialForceLimit > 0 && axialForceLimt > 0)
	{
		return new Joint(radialForceLimit, axialForceLimt);
	}
	else
	{
		return nullptr;
	}
}

ArmPart * PartFactory::CreateArmPart(float length)
{
	if (length > 0) 
	{
		return new ArmPart(length);
	}
	else
	{
		return nullptr;
	}
}
	

