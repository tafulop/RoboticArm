#pragma once

#include <iostream>

namespace RoboticArm {

	class Settings
	{

	private:
		Settings();
		~Settings();

		std::string logFilePath = "E:\arm_log.txt";

	public:

		std::string getLogFilePath();

	};

}