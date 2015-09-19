#include "Settings.h"

namespace RoboticArm {

	Settings::Settings()
	{
	}


	Settings::~Settings()
	{
	}

	std::string Settings::getLogFilePath()
	{
		return this->logFilePath;
	}

}