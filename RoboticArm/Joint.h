#pragma once

#include "Logger.h"
#include "Part.h"

namespace RoboticArm {

	class Joint : public Part
	{

		friend class PartFactory;

	private:
		float maxRadialForce;
		float maxAxialForce;
		float angle;
		Logger* log;
		Joint(int id, float mass, float maxRadialForce, float maxAxialForce);


	public:

		// default de/constructor
		//Joint();
		~Joint();



		bool isAxialOutOfLimit(float force);
		bool isRadialOutOfLimit(float force);
	};

}
