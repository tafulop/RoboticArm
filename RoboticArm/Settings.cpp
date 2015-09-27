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

/*	
// xml config
	void Settings::getConfigXMLData() {
		
		std::ifstream file;
		std::string line;
		rapidxml::xml_node<> * root_node;

		// open xml data file
		file.open(Settings::xmlFilePath, std::ios::in);

		// console turns red if file not found / inaccessible
		if (file.is_open() == false) {
			system("color 47");
			std::cout << "ERROR: xml file is invalid: " << "'" << Settings::xmlFilePath << "'" << std::endl;
		}
	
		// get file content line by line as a string
		while (getline(file, line)){
			Settings::xmlFileData.append(line);
		}

		// make the file data ready for rapidXML parser
		std::vector<char> xmlCopy(Settings::xmlFileData.begin(), Settings::xmlFileData.end());
		xmlCopy.push_back('\0');

		rapidxml::xml_document<> doc;
		doc.parse<0>(&xmlCopy[0]);

		root_node = doc.first_node("Part");

		for (rapidxml::xml_node<> * part_node = root_node->first_node("Home position"); part_node; part_node = part_node->next_sibling())
		{
			std::cout << part_node->value();
		}
		
	}
	
	*/



	std::string Settings::getLogSeparatorLine()
	{
		return Settings::logSeparatorLine;
	}


	// returns a matrix with filled coordinates
	/*Matrix Settings::getPositionMatrix(std::string partName)
	{
		// load XML data if empty
		if (Settings::xmlFileData.empty() == true)xmlFileData = getConfigXMLData();
	
		rapidxml::xml_document<> doc;

		char[Settings::xmlFileData.length()]

		doc.parse<0>(const_cast<char*>(xmlFileData));
		
		//	rapidxml::xml_document<> doc;    // character type defaults to char
	//	doc.parse<0>(text);    // 0 means default parse flags
		
	}*/
	
}