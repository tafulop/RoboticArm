#pragma once

#include <iostream>

namespace RoboticArm {

	class Settings
	{

	private:
		Settings();
		~Settings();
		static std::string logFilePath;
		

	public:
		
		static std::string getLogFilePath();

	};

}