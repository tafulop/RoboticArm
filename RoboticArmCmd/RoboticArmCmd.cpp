// RoboticArmCmd.cpp : Defines the entry point for the console application

#include "stdafx.h"
#include "ArmCreator.h"
#include "Calculation.h"


int main()
{
	using namespace RoboticArm;

	// Initializing...
	ArmCreator* AC = ArmCreator::getInstance();
	AC->logger->enableLogging(Logger::BOTH);
	AC->logger->printProgramStart(Logger::BOTH);

	// generating robotic arm
	AC->createRoboticArm();

	// Calculation
/*	AC->calcEffectorPosition();
	AC->printEffectorMatrix();
	AC->calcEffectorPosition();*/

	AC->logger->printLine("Fuck you and your eyebrows!", Logger::BOTH);
	Part* v1 = (Part*)(AC->getPartByName("B"));
	Joint* j1 = dynamic_cast<Joint*>(v1);
	j1->printPartData(Logger::BOTH);

	// prevent from auto-exiting
	system("pause");

	return 0;
}

