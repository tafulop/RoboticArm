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
		partsToCreate.emplace(partsToCreate.end(),"B");
		partsToCreate.emplace(partsToCreate.end(), "J1");
		partsToCreate.emplace(partsToCreate.end(), "L12");
		partsToCreate.emplace(partsToCreate.end(), "E");

	}

	void PartContainer::createJoints()
	{
		joints.emplace(std::piecewise_construct, std::forward_as_tuple("J1"), std::forward_as_tuple(factory->CreateJoint("J1", 1,2,3)));
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

	bool PartContainer::findNextPart(std::string name, Joint **target)
	{
		Joint* temp;
		for (std::vector<std::string>::iterator it = partsToCreate.begin(); it != partsToCreate.end(); it++) {
			if (*it == name) {
				if (++it != partsToCreate.end()) { 
					temp = dynamic_cast<Joint*>(findPart(*it));
					if (temp != nullptr) {
						*target = temp;
						return true;
					}
				}
			}
		}
		return false;
	}

	bool PartContainer::findNextPart(std::string name, ArmPart **target)
	{
		for (std::vector<std::string>::iterator it = partsToCreate.begin(); it != partsToCreate.end(); it++) {
			if (*it == name) {
				if (++it != partsToCreate.end()) {
					*target = dynamic_cast<ArmPart*>(findPart(*it));
					if (target != nullptr) {
						return true;
					}
				}
			}
		}
		return false;
	}

	bool PartContainer::findNextPart(std::string name, Effector **target)
	{
		Effector* temp;
		for (std::vector<std::string>::iterator it = partsToCreate.begin(); it != partsToCreate.end(); it++) {
			if (*it == name) {
				if (++it != partsToCreate.end()) {
					temp = dynamic_cast<Effector*>(findPart(*it));
					if (temp != nullptr) {
						*target = temp;
						return true;
					}
				}
			}
		}
		return false;
	}

	bool PartContainer::findNextPart(std::string name, Body  **target)
	{
		Body* temp;
		delete *target;

		for (std::vector<std::string>::iterator it = partsToCreate.begin(); it != partsToCreate.end(); it++) {
			if (*it == name) {
				if (++it != partsToCreate.end()) {
					temp = dynamic_cast<Body*>(findPart(*it));
					if (temp != nullptr) {
						*target = temp;
						return true;
					}
				}
			}
		}
		return false;
	}

	bool PartContainer::findPrevPart(std::string name, Joint **target)
	{
		Joint* temp;
		for (std::vector<std::string>::reverse_iterator it = partsToCreate.rbegin(); it != partsToCreate.rend(); it++) {
			if (*it == name) {
				if (++it != partsToCreate.rend()) {
					temp = dynamic_cast<Joint*>(findPart(*it));
					if (temp != nullptr) {
						*target = temp;
						return true;
					}
				}
			}
		}
		return false;
	}

	bool PartContainer::findPrevPart(std::string name, Body **target)
	{
		Body* temp;
		for (std::vector<std::string>::reverse_iterator it = partsToCreate.rbegin(); it != partsToCreate.rend(); it++) {
			if (*it == name) {
				if (++it != partsToCreate.rend()) {
					temp = dynamic_cast<Body*>(findPart(*it));
					if (temp != nullptr) {
						*target = temp;
						return true;
					}
				}
			}
		}
		return false;
	}

	bool PartContainer::findPrevPart(std::string name, Effector **target)
	{
		Effector* temp;
		for (std::vector<std::string>::reverse_iterator it = partsToCreate.rbegin(); it != partsToCreate.rend(); it++) {
			if (*it == name) {
				if (++it != partsToCreate.rend()) {
					temp = dynamic_cast<Effector*>(findPart(*it));
					if (temp != nullptr) {
						*target = temp;
						return true;
					}
				}
			}
		}
		return false;
	}

	bool PartContainer::findPrevPart(std::string name, ArmPart **target)
	{
		ArmPart* temp;
		for (std::vector<std::string>::reverse_iterator it = partsToCreate.rbegin(); it != partsToCreate.rend(); it++) {
			if (*it == name) {
				if (++it != partsToCreate.rend()) {
					temp = dynamic_cast<ArmPart*>(findPart(*it));
					if (temp != nullptr) {
						*target = temp;
						return true;
					}
				}
			}
		}
		return false;
	}

}