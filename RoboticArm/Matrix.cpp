#include "Matrix.h"


Matrix::Matrix(int x, int y, int z, int h)
{
	this->coordinates[0] = x;
	this->coordinates[1] = y;
	this->coordinates[2] = z;
	this->coordinates[3] = h;
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
	this->coordinates[0] *= cos(qi) + this->coordinates[1] * sin(qi);
	this->coordinates[1] = coordinates[0] * -sin(qi)*cos(alfa) + coordinates[1] * cos(qi) * cos(alfa) + coordinates[2] * sin(alfa);
	this->coordinates[2] = coordinates[0] * sin(qi) * sin(alfa) - coordinates[1] * cos(qi) * sin(alfa) + coordinates[2] * cos(alfa);
}

void Matrix::printData()
{
	std::cout << "Matrix data:\n";
	std::cout << "x: " << coordinates[0] << std::endl;
	std::cout << "y: " << coordinates[1] << std::endl;
	std::cout << "z: " << coordinates[2] << std::endl;

}
