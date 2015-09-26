// RoboticArmCmd.cpp : Defines the entry point for the console application
//

#include "stdafx.h"
#include "..\RoboticArm\Logger.h"
#include "..\RoboticArm\PartFactory.h"
#include "..\RoboticArm\Settings.h"
#include "..\RoboticArm\Matrix.h"


int main()
{
	
    
	using namespace RoboticArm;

	// Logger test
	Logger* log;
	log = Logger::getInstance();
	log->enableLogging(Logger::BOTH);
	log->printTime(Logger::BOTH);
	log->printLine(" Program started...", Logger::BOTH);
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

	// Matrix test
	Matrix m = Matrix(5, 3, 1, 1);
	m.DHTransformation(3.14*0.75, 0.5 * 3.14, 0.4, 0.2);
	m.printData();

	// prevent auto-exiting
	system("pause");

	return 0;
}

