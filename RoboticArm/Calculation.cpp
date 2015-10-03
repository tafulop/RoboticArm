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
	void RoboticArm::Calculation::calculateEffectorPosition(std::map<std::string, Joint*>* joints, Matrix * EffectorPosition)
	{
		// return if joints map does not set
		if (joints->empty()) { 
			log->printLine("ERROR: Joint coordinates map is empty, nothing to calculate.", Logger::BOTH); 
			return;
		}

		// iterating trough items
		for (std::map<std::string, Joint*>::iterator i = joints->begin(); i != joints->end(); ++i) {
			log->printLine(i->first, Logger::BOTH);
		
		}

	}
}