// RoboticArmCmd.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "..\RoboticArm\Logger.h"
#include "..\RoboticArm\PartFactory.h"


int main()
{
    
	using namespace RoboticArm;

	// Logger test
	Logger* log;
	log = Logger::getInstance();
	log->enableLogging(Logger::CONSOLE);
	log->printTime(Logger::CONSOLE);
	log->printLine(" Program started...", Logger::CONSOLE);
	log->lineFeed(1, Logger::CONSOLE);


	// Partfactory 
	// TO-DO: use exception to check if returned pointer is not nullptr
	PartFactory* factory;
	factory = PartFactory::getInstance();

	// BODY
	Body* b = factory->CreateBody(1234);

	// JOINT
	Joint* j1 = factory->CreateJoint(1, 2, 3);

	// EFFECTOR
	Effector* e1 = factory->CreateEffector(123);

	// ARMPART
	ArmPart* a1 = factory->CreateArmPart(143.6f, 16.7f);

	// NUMBER OF CREATED PARTS
	log->printLine("Number of parts: " + std::to_string(factory->GetNumberOfParts()), Logger::CONSOLE);

	// prevent auto-exiting
	system("pause");

	return 0;
}

