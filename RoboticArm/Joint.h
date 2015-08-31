#pragma once

#include "Logger.h"
#include "Part.h"

class Joint : public Part
{
private:
	float maxRadialForce;
	float maxAxialForce;
	float angle;
	Logger* log;


public:

	// default de/constructor
	//Joint();
	~Joint();

	Joint(float maxRadialForce, float maxAxialForce);

	bool isAxialOutOfLimit(float force);
	bool isRadialOutOfLimit(float force);
};

