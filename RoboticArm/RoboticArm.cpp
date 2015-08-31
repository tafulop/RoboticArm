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

	//log->disableConsoleLogging();
	log->printToDisplay("test");

	

	// Partfactory
	PartFactory* factory;
	factory = PartFactory::getInstance();

	// get joint via partfactory
	Joint* j1 = factory->CreateJoint(0, 11.1, 11, 11);

	if (j1 == nullptr)log->printToDisplay("Joint can not be created.");
	

	// get armpart
	//ArmPart* a1 = factory->CreateArmPart(10, 14.5, 16.7);

	log->printToDisplay(factory->GetNumberOfParts());
	//std::cout << Part::getNumberOfParts();

	return 0;
}

