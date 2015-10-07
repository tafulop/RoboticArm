#include "PartContainer.h"

namespace RoboticArm {

	bool PartContainer::instanceFlag = false;
	PartContainer* PartContainer::single = nullptr;

	

	PartContainer::PartContainer()
	{
	}

	PartContainer::~PartContainer()
	{
	}

	PartContainer* RoboticArm::PartContainer::getInstance()
	{
		if (PartContainer::instanceFlag == false) {
			PartContainer::single = new PartContainer();
			PartContainer::instanceFlag = true;
		}
		else {
			return PartContainer::single;
		}
	}

	void PartContainer::fillPTCL()
	{
		orderedPartList.emplace(orderedPartList.end(),"B");
		orderedPartList.emplace(orderedPartList.end(), "J1");
		orderedPartList.emplace(orderedPartList.end(), "L12");
		orderedPartList.emplace(orderedPartList.end(), "J2");
		orderedPartList.emplace(orderedPartList.end(), "L23");
		orderedPartList.emplace(orderedPartList.end(), "J3");
		orderedPartList.emplace(orderedPartList.end(), "L34");
		orderedPartList.emplace(orderedPartList.end(), "J4");
		orderedPartList.emplace(orderedPartList.end(), "L45");
		orderedPartList.emplace(orderedPartList.end(), "J5");
		orderedPartList.emplace(orderedPartList.end(), "L5E");
		orderedPartList.emplace(orderedPartList.end(), "E");

	}

	void PartContainer::createJoints()
	{
		joints.emplace(std::piecewise_construct, std::forward_as_tuple("J1"), std::forward_as_tuple(factory->CreateJoint("J1", 1,2,3)));
		joints.emplace(std::piecewise_construct, std::forward_as_tuple("J2"), std::forward_as_tuple(factory->CreateJoint("J2", 11, 2, 3)));
		joints.emplace(std::piecewise_construct, std::forward_as_tuple("J3"), std::forward_as_tuple(factory->CreateJoint("J3", 111, 2, 3)));
		joints.emplace(std::piecewise_construct, std::forward_as_tuple("J4"), std::forward_as_tuple(factory->CreateJoint("J4", 1111, 2, 3)));
		joints.emplace(std::piecewise_construct, std::forward_as_tuple("J5"), std::forward_as_tuple(factory->CreateJoint("J5", 11111, 2, 3)));
	}

	void PartContainer::createBodies()
	{
		bodies.emplace(std::piecewise_construct, std::forward_as_tuple("B"), std::forward_as_tuple(factory->CreateBody("B", 12)));
	}

	void PartContainer::createEffectors()
	{
		effectors.emplace(std::piecewise_construct, std::forward_as_tuple("E"), std::forward_as_tuple(factory->CreateEffector("E",345)));
	}

	void PartContainer::createArmParts()
	{
		armParts.emplace(std::piecewise_construct, std::forward_as_tuple("L12"), std::forward_as_tuple(factory->CreateArmPart("L12",1,2)));
		armParts.emplace(std::piecewise_construct, std::forward_as_tuple("L23"), std::forward_as_tuple(factory->CreateArmPart("L23", 1, 2)));
		armParts.emplace(std::piecewise_construct, std::forward_as_tuple("L34"), std::forward_as_tuple(factory->CreateArmPart("L34", 1, 2)));
		armParts.emplace(std::piecewise_construct, std::forward_as_tuple("L45"), std::forward_as_tuple(factory->CreateArmPart("L45", 1, 2)));
		armParts.emplace(std::piecewise_construct, std::forward_as_tuple("L5E"), std::forward_as_tuple(factory->CreateArmPart("L5E", 1, 2)));
	}

	void PartContainer::createAll()
	{
		createBodies();
		createJoints();
		createArmParts();
		createEffectors();
	}

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
				if (tempPtr->getType() == TYPE_JOINT)return dynamic_cast<Joint*>(tempPtr);
			}

			// if we tried to found it but failed
			return nullptr;
		
		}

	}

}