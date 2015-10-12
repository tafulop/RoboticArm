#pragma once

#include  <map>
#include "Joint.h"
#include "Matrix.h"
#include "Body.h"
#include <vector>
#include "PartContainer.h"

namespace RoboticArm{

	class Calculation
	{

	private:
		Logger* log = Logger::getInstance();
		PartContainer* PC = PartContainer::getInstance();


	public:
		Calculation();
		~Calculation();

		void setHomePosition();
		
	};

}