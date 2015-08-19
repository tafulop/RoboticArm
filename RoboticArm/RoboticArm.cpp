// RoboticArm.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Logger.h"
#include "Part.h"
#include "Joint.h"

int Part::count = 0;

int main()
{
	// Logger test
	Logger* log;
	log = Logger::getInstance();
	log->printToDisplay("Program started...");


	// part test
	Joint tJoint(11.5f,55.6f);
	log->printToDisplay("Number of parts: " + std::to_string(tJoint.getNumberOfParts()));

	Joint tJoint2(-11.5f, -55.6f);
	log->printToDisplay("Number of parts: " + std::to_string(tJoint.getNumberOfParts()));
	tJoint2.isAxialOutOfLimit(25);

	Joint tJoint3(0, 0);
	log->printToDisplay("Number of parts: " + std::to_string(tJoint.getNumberOfParts()));

	


	//std::cout << Part::getNumberOfParts();

	return 0;
}

