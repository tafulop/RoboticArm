#include "Calculation.h"

namespace RoboticArm {

	bool Calculation::instanceFlag = false;
	Calculation* Calculation::single = nullptr;


	// X-structors
	Calculation::Calculation()
	{
	}

	Calculation::~Calculation()
	{
		single = nullptr;
		instanceFlag = false;
	}


	Calculation * Calculation::getInstance()
	{
		if (instanceFlag == false) {
			single = new Calculation();
			instanceFlag = true;
			return single;
		}
		else {
			return single;
		}
	}

	// Methods
	void RoboticArm::Calculation::calculateEffectorPosition(std::map<std::string, Joint*>* joints, Matrix * EffectorPosition, Body* body, std::vector<std::string> partList)
	{
		// return if joints map does not set
		if (joints->empty() == true) { 
			log->printLine("ERROR: Joint coordinates map is empty, nothing to calculate.", Logger::BOTH); 
			return;
		}

		// iterating trough parts
		for (std::vector<std::string>::iterator it = partList.begin(); it != partList.end(); ++it) {
			std::cout << "baszod: " << *it << std::endl;
		}
		

	}
}