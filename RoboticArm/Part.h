#pragma once
class Part
{

private:
	
	static int count;
	int id;
	float mass;
	int position;
	


public:
	
	// constructor increments the count member variable
	Part();
	~Part();

	static int getNumberOfParts();
};

