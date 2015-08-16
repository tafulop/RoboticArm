#include "Logger.h"


Logger::~Logger()
{
	instanceFlag = false;
}

void Logger::printToDisplay(std::string text)
{
	std::cout << text << std::endl;
}

bool Logger::instanceFlag = false;
Logger* Logger::single = nullptr;

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