#include "Logger.h"

using namespace RoboticArm;

bool Logger::instanceFlag = false;
Logger* Logger::single = nullptr;
bool Logger::consoleLogging = false;
bool Logger::fileLogging = false;

Logger::Logger()
{
	instanceFlag = true;
	logFile.open("E:\\RoboticArmLog2.txt" , std::ios::out | std::ios::trunc);
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

	if (target == Logger::BOTH) 
	{
		if (Logger::consoleLogging == true)std::cout << number << std::endl;
		if (Logger::fileLogging == true)logFile << number << std::endl;
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

	if (target == Logger::BOTH)
	{
		if(Logger::consoleLogging == true)std::cout << text << std::endl;
		if(Logger::fileLogging == true)logFile << text << std::endl;
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
	switch (target)
	{
	case Logger::logTarget::FILE:	Logger::fileLogging = false;
		break;

	case Logger::logTarget::CONSOLE:	Logger::consoleLogging = false;
		break;

	case Logger::logTarget::BOTH:	Logger::fileLogging = false;
		Logger::consoleLogging = false;
		break;

	default: break;
	}
}

bool RoboticArm::Logger::isLoggingEnabled(logTarget target)
{
	switch (target) 
	{

	case BOTH:	if (consoleLogging == true && fileLogging == true)return true;

		break;

	case FILE:	if (fileLogging == true)return true;

		break;

	case CONSOLE: if (consoleLogging == true)return true;

		break;

	default: break;
	
	}
	
	return false;

}
