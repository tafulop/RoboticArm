// RoboticArm.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Logger.h"
#include "PartFactory.h"


int main()
{
	// Logger test
	Logger* log;
	log = Logger::getInstance();
	log->enableConsoleLogging();
	log->printToDisplay("Program started...");
	log->lineFeed(1,Logger::CONSOLE);
	
	// Partfactory 
	// TO-DO: use exception to check if returned pointer is not nullptr
	PartFactory* factory;
	factory = PartFactory::getInstance();

	// JOINT
	Joint* j1 = factory->CreateJoint(1,2,3);

	// EFFECTOR
	Effector* e1 = factory->CreateEffector(123);

	// ARMPART
	ArmPart* a1 = factory->CreateArmPart(14.5, 16.7);

	// NUMBER OF CREATED PARTS
	log->printToDisplay("Number of parts: " + std::to_string(factory->GetNumberOfParts()));
	

	return 0;
}

