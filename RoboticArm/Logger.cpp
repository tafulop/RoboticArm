#include "Logger.h"

using namespace RoboticArm;

bool Logger::instanceFlag = false;
Logger* Logger::single = nullptr;
bool Logger::consoleLogging = false;
bool Logger::fileLogging = false;

Logger::Logger()
{
	logFile.open("E:\RoboticArm_log.txt", std::ios::out | std::ios::trunc);
}

Logger::~Logger()
{
	instanceFlag = false;
	logFile.close();
}

Logger* Logger::getInstance()
{
	if (!instanceFlag)
	{
		single = new Logger();
		instanceFlag = true;
		return single;
	}
	else
	{
		return single;
	}

}


// Print methods

void Logger::printLine(int number, Logger::logTarget target)
{
	if (Logger::consoleLogging == true && target == CONSOLE)
	{
		std::cout << number << std::endl;
	}

	if (Logger::fileLogging == true && target == FILE)
	{
		logFile << number << std::endl;
	}

	if (Logger::fileLogging == true && Logger::consoleLogging == true
		&& target == Logger::BOTH) 
	{
		std::cout << number << std::endl;
		logFile << number << std::endl;
	}
}

void RoboticArm::Logger::printLine(std::string text, Logger::logTarget target)
{
	if (Logger::consoleLogging == true && target == CONSOLE)
	{
		std::cout << text << std::endl;
	}

	if (Logger::fileLogging == true && target == FILE)
	{
		logFile << text << std::endl;
	}

	if (Logger::fileLogging == true && Logger::consoleLogging == true
		&& target == Logger::BOTH)
	{
		std::cout << text << std::endl;
		logFile << text << std::endl;
	}
}

// Linefeed

void Logger::lineFeed(int numOfNewLines, logTarget target)
{
	// return if newlines value is invalid
	if(numOfNewLines < 0)return;

	int i = 0;

	switch (target)
	{
	case CONSOLE:		for (i = 0; i < numOfNewLines; i++) {
							printLine("", target);
							};
	}
	
}

void Logger::enableLogging(Logger::logTarget target)
{
	switch (target) 
	{
		case Logger::logTarget::FILE:	Logger::fileLogging = true;
										break;

		case Logger::logTarget::CONSOLE:	Logger::consoleLogging = true;
											break;

		case Logger::logTarget::BOTH:	Logger::fileLogging = true;
										Logger::consoleLogging = true;
										break;

		default: break;
	}							
}

void Logger::disableLogging(Logger::logTarget target)
{
	Logger::consoleLogging = false;
}

int RoboticArm::Logger::multi(int a, int b)
{
	return a *b;
}