#pragma once

#include <iostream>
#include <unordered_map>
#include "AllParts.h"
#include "PartFactory.h"

namespace RoboticArm {
	
	class PartContainer
	{
	private:
		// Part creator factory
		PartFactory* factory = PartFactory::getInstance();

		// Parts
		std::unordered_map<std::string, Body> bodies;
		std::unordered_map<std::string, Effector> effectors;
		std::unordered_map<std::string, Joint> joints;
		std::unordered_map<std::string, ArmPart> armParts;

		// Partlist
		std::vector<std::string> orderedPartList;

		// singleton
		static bool instanceFlag;
		static PartContainer *single;
		PartContainer();

	public:
		const enum searchDirection {NEXT, PREVIOUS};
		~PartContainer();
		static PartContainer* getInstance();
		
		void setBonds(std::vector<std::string> orderedList);
		void addJoint(std::string name, float mass, float maxRadialForce, float maxAxialForce);
		void addBody(std::string name, float mass);
		void addEffector(std::string name, float mass);
		void addArmPart(std::string name, float mass, float length);
	
		// Find methods
		Part* findPart(std::string name);
		ArmPart* findArmPart(std::string partName, searchDirection sd);
		Joint* findJoint(std::string partName, searchDirection sd);

	};

}