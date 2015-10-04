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
		std::vector<std::string> partsToCreate;

		// singleton
		static bool instanceFlag;
		static PartContainer *single;
		PartContainer();

	public:
		~PartContainer();
		static PartContainer* getInstance();
		void fillPTCL();
		void createJoints();
		void createBodies();
		void createEffectors();
		void createArmParts();
		void createAll();
		Part* findPart(std::string name);
		
		// Find methods
		bool findNextPart(std::string name, Joint** target);
		bool findNextPart(std::string name, ArmPart** target);
		bool findNextPart(std::string name, Effector** target);
		bool findNextPart(std::string name, Body** target);

		bool findPrevPart(std::string name, Joint** target);
		bool findPrevPart(std::string name, Body** target);
		bool findPrevPart(std::string name, Effector** target);
		bool findPrevPart(std::string name, ArmPart** target);
	};

}