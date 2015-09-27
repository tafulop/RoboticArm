#pragma once

#include <iostream>
//#include "Matrix.h"
#include "../rapidxml/rapidxml.hpp"
#include <sstream>
#include <fstream>

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
		static std::string Settings::getConfigXMLData();
		static std::string getLogFilePath();
		static std::string getLogSeparatorLine();
		//static Matrix getPositionMatrix(std::string partName);
	};

}