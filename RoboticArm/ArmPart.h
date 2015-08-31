#pragma once
#include "Part.h"
#include "Logger.h"

class ArmPart :	public Part
{
private:
	float length;


public:	~ArmPart();
		ArmPart(float length);

};

