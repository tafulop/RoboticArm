#pragma once

#include <iostream>
#include <string>

class Logger
{
private:
	static bool instanceFlag;
	static Logger *single;
	Logger();
	~Logger();

public:
	static Logger* getInstance();
	void printToDisplay(std::string text);
	void printToDisplay(int number);
};


