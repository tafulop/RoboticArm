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

Joint* PartFactory::CreateJoint(std::string name, float mass, float radialForceLimit, float axialForceLimt)
{
	if (radialForceLimit > 0 && axialForceLimt > 0 && mass > 0 && name.empty() == false)	{
		Joint temp = Joint(this->id++, name, mass, radialForceLimit, axialForceLimt);
		joints.emplace(std::piecewise_construct, std::forward_as_tuple(name), std::forward_as_tuple(temp));
		count++;
		return &joints.find(name)->second;
	}	else	{
		return nullptr;
	}
}

ArmPart* PartFactory::CreateArmPart(std::string name, float mass, float length)
{
	if (length > 0 && mass> 0 && name.empty() == false) {
		ArmPart temp = ArmPart(this->id++, name, mass, length);
		armParts.emplace(std::piecewise_construct, std::forward_as_tuple(name), std::forward_as_tuple(temp));
		count++;
		return &armParts.find(name)->second;
	}	else	{
		return nullptr;
	}
}

Effector* PartFactory::CreateEffector(std::string name, float mass)
{
	if (mass > 0 && name.empty() == false)	{
		
		Effector temp = Effector(this->id++, name, mass);
		effectors.emplace(std::piecewise_construct, std::forward_as_tuple(name), std::forward_as_tuple(temp));
		count++;
		return &effectors.find(name)->second;

	}	else	{
		return nullptr;
	}
}

Body* RoboticArm::PartFactory::CreateBody(std::string name, float mass)
{
	if (mass > 0 && name.empty() == false) {
		
		Body temp = Body(this->id++, name, mass);
		bodies.emplace(std::piecewise_construct, std::forward_as_tuple(name), std::forward_as_tuple(temp));
		count++;
		return &bodies.find(name)->second;

	} else {
		return nullptr;
	}
}

void * RoboticArm::PartFactory::GetPartByName(std::string name)
{
	if (name.empty() == true)return nullptr;
	
	std::map<std::string, Joint>::iterator j = joints.find(name);
	if (j != joints.end())return (Joint*)&j->second;

	std::map<std::string, ArmPart>::iterator a = armParts.find(name);
	if (a != armParts.end())return (ArmPart*)&a->second;

	std::map<std::string, Effector>::iterator e = effectors.find(name);
	if (e != effectors.end())return (Effector*)&e->second;

	std::map<std::string, Body>::iterator b = bodies.find(name);
	if (b != bodies.end())return (Body*)&b->second;

	return nullptr;
}

int PartFactory::GetNumberOfParts()
{
	return count;
}
	

