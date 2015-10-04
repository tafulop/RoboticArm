// RoboticArmCmd.cpp : Defines the entry point for the console application

#include "stdafx.h"
#include "ArmRunner.h"
#include "Calculation.h"


int main()
{
	using namespace RoboticArm;

	// Initializing...
	ArmRunner* AR = ArmRunner::getInstance();
	AR->log->enableLogging(Logger::BOTH);
	AR->log->printProgramStart(Logger::BOTH);

	// Creating robotic arm
	AR->createArm();

	// Get container
	PartContainer* PC = PartContainer::getInstance();

	// "B" "J1" "L12" "E"

	PC->fillPTCL();
	ArmPart* l = nullptr;
	PC->findNextPart("J1", &l);
	l->printPartData(Logger::BOTH);

	Body* b = nullptr;
	PC->findPrevPart("J1", &b);
	b->printPartData(Logger::BOTH);



/*	Body* b = nullptr;
	if(PC->findPrevPart("J1", b))b->printPartData(Logger::BOTH);*/
	

	// prevent from auto-exiting
	system("pause");

	return 0;
}

