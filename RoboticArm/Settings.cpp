#include "Settings.h"

namespace RoboticArm {

	// settings 
	std::string Settings::logFilePath = "D:\\armlogs\\armlog.txt";
	std::string Settings::logSeparatorLine = "---------------------------------------------";

	Settings::Settings()
	{
	}


	Settings::~Settings()
	{
	}

	std::string Settings::getLogFilePath()
	{
		return Settings::logFilePath;
	}

	std::string Settings::getLogSeparatorLine()
	{
		return Settings::logSeparatorLine;
	}

}