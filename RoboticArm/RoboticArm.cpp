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
	log->printToDisplay("Program started...");

	// Partfactory
	PartFactory* factory;
	factory = PartFactory::getInstance();

	// get joint via partfactory
	Joint* j1 = factory->CreateJoint(-11, 11);

	if (j1 == nullptr)log->printToDisplay("Joint can not be created.");
	
	try
	{
		if (j1->isAxialOutOfLimit(10) == true) {
		log->printToDisplay("NOK");
		}
	}
	catch(int e)
	{
		log->printToDisplay("nullptr");
	}


	//std::cout << Part::getNumberOfParts();

	return 0;
}

