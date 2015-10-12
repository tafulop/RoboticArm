#include "Matrix.h"

namespace RoboticArm {
/*	Matrix::Matrix()
	{
	}*/
	
	Matrix::Matrix()
	{
		x = 0;
		y = 0;
		z = 0;
		w = 0;
	}

	Matrix::Matrix(float x, float y, float z, float w)
	{
	}

	Matrix::~Matrix()
	{
	}

	/****************************************************************

	Denavit-Hartenberg matrix:

	cos(qi)		-sin(qi)cos(alfa)	sin(qi)sin(alfa)	ai*cos(qi)
	sin(qi)		cos(qi)cos(alfa)	-cos(qi)sin(alfa)	ai*sin(qi)
	0			sin(alfa)			cos(alfa)			di
	0			0					0					1


	>	x = x * cos(qi) + y * sin(qi)
	>	y = x * (-sin(qi)*cos(alfa) + y * cos(qi) * cos(alfa) + z * sin(alfa)
	>	z = x * sin(qi) * sin(alfa) - y * cos(qi) * sin(alfa) + z * cos(alfa)
	>	x * ai * cos(qi) + y * ai * sin(qi) + z * di + w

	******************************************************************/

	void Matrix::DHTransformation(float qi, float alfa, float di, float ai)
	{
	/*	
	
	float x, y, z, w, sinAlfa, cosAlfa, sinQi, cosQi;

		

		sinQi = sin(qi);
		cosQi = cos(qi);
		sinAlfa = sin(alfa);
		cosAlfa = cos(alfa);

		this->coordinates[0] = x * cosQi + y * sinQi;
		this->coordinates[1] = x * sinQi * cosAlfa + y * cosQi * cosAlfa + z * sinAlfa;
		this->coordinates[2] = x * sinQi * sinAlfa - y * cosQi * sinAlfa + z * cosAlfa;
		this->coordinates[3] = x * ai * cosQi + y * sinQi + z * di + w;
		
		*/

	}

	float Matrix::getCoordinate(std::string axis)
	{
		if (axis == "x")return this->x;
		if (axis == "y")return this->y;
		if (axis == "z")return this->z;
		if (axis == "w")return this->w;
		
		throw 404;
	}

	void Matrix::printData(Logger::logTarget target)
	{
		log->printLine("Matrix data: ", target);
		log->printLine("x: " + std::to_string(this->x), target);
		log->printLine("y: " + std::to_string(this->y), target);
		log->printLine("z: " + std::to_string(this->z), target);
		log->printLine("w: " + std::to_string(this->w), target);
	}

	void Matrix::setPosition(float x, float y, float z, float w)
	{
		this->x = x;
		this->y = y;
		this->z = z;
		this->w = w;
	}


}