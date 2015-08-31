#pragma once

#include <iostream>
#include <string>

class Logger
{
private:
	static bool consoleLogging;
	static bool instanceFlag;
	static Logger *single;
	Logger();
	~Logger();

public:
	static Logger* getInstance();
	void printToDisplay(std::string text)
	{
		if (Logger::consoleLogging == false)return;
		std::cout << text << std::endl;
	}
	void printToDisplay(int number);
	void enableConsoleLogging();
	void disableConsoleLogging();
	
};
