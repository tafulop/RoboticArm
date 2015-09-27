#include "Settings.h"

namespace RoboticArm {

	// settings 
	std::string Settings::xmlFilePath = "D:\\config.xml";
	std::string Settings::logFilePath = "D:\\armlogs\\armlog.txt";
	std::string Settings::logSeparatorLine = "---------------------------------------------";


	// X-structors
	Settings::Settings()
	{
	}

	Settings::~Settings()
	{
	}

	// Log file handling
	std::string Settings::getLogFilePath()
	{
		return Settings::logFilePath;
	}

	// xml config
	std::string Settings::getConfigXMLData() {
		
		std::string fileData;
		std::ifstream file;
		
		file.open(Settings::xmlFilePath, std::ios::in);

		if (file.is_open() == false) {
			system("color 47");
			std::cout << "ERROR: xml file is invalid: " << "'" << Settings::xmlFilePath << "'" << std::endl;
		}
	
		std::stringstream buffer;
		buffer << file.rdbuf();

		return buffer.str();
	}



	std::string Settings::getLogSeparatorLine()
	{
		return Settings::logSeparatorLine;
	}


	// returns a matrix with filled coordinates
	// data read from config.xml
	/*Matrix Settings::getPositionMatrix(std::string partName)
	{
	//	rapidxml::xml_document<> doc;    // character type defaults to char
	//	doc.parse<0>(text);    // 0 means default parse flags
		return nullptr;
	}
	*/
}