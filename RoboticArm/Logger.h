#pragma once

#include <iostream>
#include <string>

class Logger
{
private:
	static bool instanceFlag;
	static Logger *single;
	Logger();

public:
	static Logger* getInstance();
	void method();
	~Logger();
	void printToDisplay(std::string text);
};


