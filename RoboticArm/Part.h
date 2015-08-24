#pragma once

#include "PartFactory.h"

class Part : public PartFactory
{

private:
	
	int id;
	float mass;
	int position;

public:
	
	// constructor increments the count member variable
	Part();
	~Part();

	static int getNumberOfParts();
};

