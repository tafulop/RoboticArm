#include "Matrix.h"

namespace RoboticArm {


	// *************************************************//
	//													//
	//				X-tructors							//
	//													//
	// *************************************************//
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

	// *************************************************//
	//													//
	//			Data query methods						//
	//													//
	// *************************************************//
	float Matrix::getCoordinate(std::string axis)
	{
		
		if (axis == "x") { return this->x; }

		else if (axis == "y") { return this->y; }
		else if (axis == "z") { return this->z; }
		else if (axis == "w") { return this->w; }
		else {
			log->printWarning("Unkown axis: " + axis, Logger::BOTH);
			return 0;
		}
	
	}

	void Matrix::printData(Logger::logTarget target)
	{
		log->printLine("Matrix data: ", target);
		log->printLine("x: " + std::to_string(this->x), target);
		log->printLine("y: " + std::to_string(this->y), target);
		log->printLine("z: " + std::to_string(this->z), target);
		log->printLine("w: " + std::to_string(this->w), target);
	}


	// *************************************************//
	//													//
	//			Data manipulating methods				//
	//													//
	// *************************************************//
	void Matrix::setCoordinate(std::string axis, float value)
	{
		if (axis == "x") {
			this->x = value;
			this->inited = true;
		}
		else if (axis == "y") {
			this->y = value;
			this->inited = true;
		}
		else if (axis == "z") {
			this->z = value;
			this->inited = true;
		}
		else if (axis == "w") {
			this->w = value;
			this->inited = true;
		}
		else {
			log->printError("Invalid value laber for coordinate at matrix:", Logger::BOTH);
			this->printData(Logger::BOTH);
		}
	}

	
	void Matrix::setPosition(float x, float y, float z, float w)
	{
		this->inited = true;
		
		this->x = x;
		this->y = y;
		this->z = z;
		this->w = w;
	}

	bool Matrix::isInitialized()
	{
		return this->inited;
	}


}