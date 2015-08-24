#pragma once

#include <iostream>

// PartFactroy implements factory design pattern (singleton too)


class PartFactory
{
private:
	//std::string[2] = {"Joint", "ArmPart"};
	static bool instanceFlag;
	static PartFactory* factory;
	static int count;

	PartFactory();
	~PartFactory();

public:
	static PartFactory* getInstance();
	virtual PartFactory* GetPart(std::string name);
};

