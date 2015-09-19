#include "Settings.h"

namespace RoboticArm {

	// settings 
	std::string Settings::logFilePath = "E:\\armlog.txt";


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

}