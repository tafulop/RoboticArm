#pragma once

#include "Logger.h"
#include <iostream>
#include "ArmCreator.h"
#include "Calculation.h"
#include <chrono>
#include <thread>

#include "Communication.h"
#include "Simulation.h"


namespace RoboticArm {
	
	class ArmRunner
	{
	private:
		// Singleton behavior member variables
		static bool instanceFlag;
		static ArmRunner* single;
		
		// Normal member variables
		Calculation* calc = Calculation::getInstance();
		Matrix effectorPosition;
		ArmCreator* AC = ArmCreator::getInstance();


	public:
		// x-structors
		ArmRunner();
		~ArmRunner();
		
		// Singleton behaviour
		static ArmRunner* getInstance();
		Logger* log = Logger::getInstance();

		// Normal methods
		void initialize();
		void operate();
	
	};

}