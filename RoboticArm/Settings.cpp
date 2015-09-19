#include "Settings.h"

namespace RoboticArm {

	Settings::Settings()
	{
		Settings::logFilePath = "E:\roboticarmlog.txt";
	}


	Settings::~Settings()
	{
	}

	std::string Settings::getLogFilePath()
	{
		return Settings::logFilePath;
	}

}