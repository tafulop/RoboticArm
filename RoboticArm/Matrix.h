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
	Matrix(float x, float y, float z, float h);
	~Matrix();

	// methods
	void DHTransformation(float qi, float alfa, float di, float ai);
	void printData();
};

