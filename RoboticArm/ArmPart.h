#pragma once
#include "Part.h"
#include "Logger.h"

class ArmPart :	public Part
{
	friend class PartFactory;

private:
	float length;
	ArmPart(int id, float mass, float length);


public:	~ArmPart();
		

};

