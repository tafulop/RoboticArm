#pragma once

#include <iostream>

namespace RoboticArm {

	class Settings
	{

	private:
		Settings();
		~Settings();
		static std::string logFilePath;
		static std::string logSeparatorLine;
		

	public:
		
		static std::string getLogFilePath();
		static std::string getLogSeparatorLine();

	};

}