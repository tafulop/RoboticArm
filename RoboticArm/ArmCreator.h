#pragma once

#include <iostream>
#include "PartContainer.h"

namespace RoboticArm {

	class ArmCreator
	{
	private:
		static bool instanceFlag;
		static ArmCreator* single;
		PartContainer* PC = PartContainer::getInstance();
		std::vector<std::string> orderedPartList;
		
		
		ArmCreator();
		~ArmCreator();

		void fillOrderedPartList();

		void createBody();
		void createArmParts();
		void createJoints();
		void createEffector();
		void createBonds();

		void parseXML();

	public:
		static ArmCreator* getInstance();

		void createParts();

	};

}