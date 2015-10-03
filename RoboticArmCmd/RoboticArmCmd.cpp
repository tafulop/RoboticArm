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
	AC->calcEffectorPosition();

	// prevent from auto-exiting
	system("pause");

	return 0;
}

