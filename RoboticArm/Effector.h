#pragma once
#include "Part.h"
class Effector :
	public Part
{
	friend class PartFactory;

private:
	Effector(float mass);
public:
	//Effector();
	~Effector();
};

