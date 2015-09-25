#pragma once

#include <math.h>
#include <iostream>

class Matrix
{


private: 
	float coordinates[3]; 
	float hCoordinate;

public:

	// X-structors
	Matrix(int x, int y, int z, int h);
	~Matrix();

	// methods
	void DHTransformation(float qi, float alfa, float di, float ai);
	void printData();
};

