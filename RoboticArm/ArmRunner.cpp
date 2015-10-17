#include "ArmRunner.h"

namespace RoboticArm {


	// ***********************************************
	// Singleton behavior settings and definitions
	// ***********************************************

	ArmRunner* ArmRunner::single = nullptr;
	bool ArmRunner::instanceFlag = false;

	// X-sructors
	ArmRunner::ArmRunner()
	{
	}

	ArmRunner::~ArmRunner()
	{
		single = nullptr;
		instanceFlag = false;
	}

	// Singleton instance query
	ArmRunner* ArmRunner::getInstance()
	{
		if (instanceFlag == false)
		{
			single = new ArmRunner();
			instanceFlag = true;
			return single;
		}
		else
		{
			return single;
		}
	}

	

	// ***********************************************
	// Normal method definitions
	// ***********************************************

	// Ask armcreator to create all necessary parts and set home position for them
	void ArmRunner::initialize()
	{
		AC->createParts();
	}

	void ArmRunner::operate()
	{
	}
	
	
	
	
	
	
	
	/*bool ArmRunner::setHomePosition()
	{
		Matrix home[5];
		home[0].setPosition(123, 546, 213, 1);
		home[1].setPosition(598, 456, 345, 1);
		home[2].setPosition(145, 346, 42, 1);
		home[3].setPosition(453, 836, 79, 1);
		home[4].setPosition(153, 768, 546, 1);

		// find the first joint
		Joint* j = PC->findJoint("B", PartContainer::NEXT);
		if (j == nullptr) { 
			log->printError("First joint can not be found after body named 'B'.", Logger::BOTH); 
			return false;
		}

		int i = 0;
		while (j != nullptr)
		{
			j->setPosition(&home[i++]);
			log->printLine("Position has been set for " + j->getName(), Logger::BOTH);
			//j->printPosition(Logger::CONSOLE);
			j = PC->findJoint(j->getName(), PartContainer::NEXT);
		}
		
		log->lineFeed(1, Logger::BOTH);
		log->printLine("All positions have been set for joints.", Logger::BOTH);
		log->lineFeed(1, Logger::BOTH);

		return true;
	}*/

}