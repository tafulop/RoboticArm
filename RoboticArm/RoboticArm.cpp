// RoboticArm.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Logger.h"


int main()
{
	
	Logger* log;
	log = Logger::getInstance();
	log->printToDisplay("hello");

	return 0;
}

