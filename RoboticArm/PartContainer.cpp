#include "PartContainer.h"

namespace RoboticArm {

	// Initializing variables for singleton behavioral
	bool PartContainer::instanceFlag = false;
	PartContainer* PartContainer::single = nullptr;

	// X-scructor
	PartContainer::PartContainer(){}
	PartContainer::~PartContainer(){}

	// Creates one instance on the first function call, 
	// returns the one and only pointer for the PartContainer object
	PartContainer* RoboticArm::PartContainer::getInstance()
	{
		if (PartContainer::instanceFlag == false) {
			PartContainer::single = new PartContainer();
			PartContainer::instanceFlag = true;
			return PartContainer::single;
		}
		else {
			return PartContainer::single;
		}
	}

	// Fill the parts to be created ordered vector (list)
	void PartContainer::setBonds(std::vector<std::string> orderedList)
	{
		this->orderedPartList = orderedList;
	}

	void PartContainer::addJoint(std::string name, float mass, float maxRadialForce, float maxAxialForce)
	{
		// TO-DO: check if name is empty
		joints.emplace(std::piecewise_construct, std::forward_as_tuple(name), std::forward_as_tuple(factory->CreateJoint(name,mass,maxRadialForce,maxAxialForce)));
	}

	void PartContainer::addBody(std::string name, float mass)
	{
		bodies.emplace(std::piecewise_construct, std::forward_as_tuple(name), std::forward_as_tuple(factory->CreateBody(name, mass)));
	}

	void PartContainer::addEffector(std::string name, float mass)
	{
		effectors.emplace(std::piecewise_construct, std::forward_as_tuple(name), std::forward_as_tuple(factory->CreateEffector(name,mass)));
	}

	void PartContainer::addArmPart(std::string name, float mass, float length)
	{
		armParts.emplace(std::piecewise_construct, std::forward_as_tuple(name), std::forward_as_tuple(factory->CreateArmPart(name,mass,length)));
	}


	// Tries to find the part with the name passed in the one and only parameter. 
	// If part not found it will return null pointer.
	Part * PartContainer::findPart(std::string name)
	{
		if (name.empty() == true)return nullptr;

		std::unordered_map<std::string, Joint>::iterator j = joints.find(name);
		if (j != joints.end())return (Joint*)&j->second;

		std::unordered_map<std::string, ArmPart>::iterator a = armParts.find(name);
		if (a != armParts.end())return (ArmPart*)&a->second;

		std::unordered_map<std::string, Effector>::iterator e = effectors.find(name);
		if (e != effectors.end())return (Effector*)&e->second;

		std::unordered_map<std::string, Body>::iterator b = bodies.find(name);
		if (b != bodies.end())return (Body*)&b->second;

		return nullptr;
	}

	ArmPart* PartContainer::findArmPart(std::string partName, PartContainer::searchDirection sd)
	{
		if (sd == PartContainer::searchDirection::NEXT) {
			// find the given element
			std::vector<std::string>::iterator it = orderedPartList.begin();
			for (; it != orderedPartList.end(); it++) {
				if (*it == partName)break;
			}

			// if element not found
			if (it == orderedPartList.end())return nullptr;

			// if element found try to found the next one
			Part* tempPtr;
			for (it++; it != orderedPartList.end(); it++) {
				tempPtr = findPart(*it);
				if (tempPtr->getType() == TYPE_ARMPART)return dynamic_cast<ArmPart*>(tempPtr);
			}

			// if we tried to found it but failed
			return nullptr;
		
		}
		
		if (sd == PartContainer::searchDirection::PREVIOUS) {
			// find the given element
			std::vector<std::string>::reverse_iterator it = orderedPartList.rbegin();
			for (; it != orderedPartList.rend(); it++) {
				if (*it == partName)break;
			}

			// if element not found
			if (it == orderedPartList.rend())return nullptr;

			// if element found try to found the next one
			Part* tempPtr;
			for (it++; it != orderedPartList.rend(); it++) {
				tempPtr = findPart(*it);
				if (tempPtr->getType() == TYPE_ARMPART)return dynamic_cast<ArmPart*>(tempPtr);
			}

			// if we tried to found it but failed
			return nullptr;
		}

		// wrong seach parameter
		return nullptr;
	}


	Joint* PartContainer::findJoint(std::string partName, PartContainer::searchDirection sd)
	{
		if (sd == PartContainer::searchDirection::NEXT) {

			// find the given element
			std::vector<std::string>::iterator it = orderedPartList.begin();
			for (; it != orderedPartList.end(); it++) {
				if (*it == partName)break;
			}

			// if element not found
			if (it == orderedPartList.end())return nullptr;

			// if element found try to found the next one
			Part* tempPtr;
			for (it++; it != orderedPartList.end(); it++) {
				tempPtr = findPart(*it);
				if (tempPtr->getType() == TYPE_JOINT)return dynamic_cast<Joint*>(tempPtr);
			}

			// if we tried to found it but we failed
			return nullptr;

		}
		
		if (sd == PartContainer::searchDirection::PREVIOUS) {
			// find the given element
			std::vector<std::string>::reverse_iterator it = orderedPartList.rbegin();
			for (; it != orderedPartList.rend(); it++) {
				if (*it == partName)break;
			}

			// if element not found
			if (it == orderedPartList.rend())return nullptr;

			// if element found try to found the next one
			Part* tempPtr;
			for (it++; it != orderedPartList.rend(); it++) {
				tempPtr = findPart(*it);
				if (tempPtr->getType() == TYPE_JOINT)return dynamic_cast<Joint*>(tempPtr);
			}

			// if we tried to found it but failed
			return nullptr;
		
		}

		return nullptr;
	}

}