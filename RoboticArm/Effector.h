#pragma once
#include "Part.h"
class Effector :
	public Part
{
	friend class PartFactory;

private:
	Effector(int id, float mass);
public:
	//Effector();
	~Effector();
};

