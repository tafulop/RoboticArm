#pragma once

#include <iostream>	// log file handling
#include <sstream>	// xml handling
#include <fstream>	// xml handling
#include <stdlib.h> // malloc, free,
#include "Matrix.h"
#include "../rapidxml/rapidxml.hpp"
#include <vector>


namespace RoboticArm {

	class Settings
	{

	private:
		Settings();
		~Settings();
		static std::string logFilePath;
		static std::string logSeparatorLine;
		static std::string xmlFilePath;
		static std::string xmlFileData;
		

	public:
		//static void Settings::getConfigXMLData();
		static std::string getLogFilePath();
		static std::string getLogSeparatorLine();
		//static Matrix getPositionMatrix(std::string partName);
	};

}