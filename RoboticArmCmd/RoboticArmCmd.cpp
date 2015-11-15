// RoboticArmCmd.cpp : Defines the entry point for the console application

#include "stdafx.h"
#include "ArmRunner.h"
#include "Calculation.h"
#include "InverseKinematics.h"


int main()
{
	using namespace RoboticArm;

	// Initializing...
	ArmRunner* AR = ArmRunner::getInstance();
	AR->log->enableLogging(Logger::BOTH);
	AR->log->printProgramStart(Logger::BOTH);

	// Creating robotic arm
	AR->initialize();
	AR->operate();
//	PartContainer* PC = PartContainer::getInstance();

	// prevent from auto-exiting
	system("pause");

	return 0;
}

