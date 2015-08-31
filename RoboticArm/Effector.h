#pragma once
#include "Part.h"
class Effector :
	public Part
{
	friend class PartFactory;

private:

public:
	Effector();
	~Effector();
};

