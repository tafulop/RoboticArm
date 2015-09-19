#pragma once

#include <iostream>

namespace RoboticArm {

	static class Settings
	{

	private:
		Settings();
		~Settings();

		static std::string logFilePath;

	public:

		static std::string getLogFilePath();

	};

}