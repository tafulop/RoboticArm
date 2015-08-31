#include "Logger.h"


Logger::~Logger()
{
	instanceFlag = false;
}

void Logger::printToDisplay(int number)
{
	if (Logger::consoleLogging == false)return;

	std::cout << "(int) " << number << std::endl;
}

void Logger::enableConsoleLogging()
{
	Logger::consoleLogging = true;
}

void Logger::disableConsoleLogging()
{
	Logger::consoleLogging = false;
}



bool Logger::instanceFlag = false;
Logger* Logger::single = nullptr;
bool Logger::consoleLogging = false;

Logger::Logger()
{
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