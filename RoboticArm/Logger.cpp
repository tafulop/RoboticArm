#include "Logger.h"
#include "Settings.h"

namespace RoboticArm{

	
		bool Logger::instanceFlag = false;
		Logger* Logger::single = nullptr;
		bool Logger::consoleLogging = false;
		bool Logger::fileLogging = false;
	

Logger::Logger()
{
	instanceFlag = true;
	
		logFile.open(Settings::getLogFilePath(),std::ios::out | std::ios::app);
		
		if (logFile.is_open() == false) {
			//system("color 47");
			std::cout << "ERROR: log file is invalid: " << "'" << Settings::getLogFilePath() << "'" << std::endl;
		}

		logFile.close();
}

Logger::~Logger()
{
	single = nullptr;
	instanceFlag = false;

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

void RoboticArm::Logger::print(std::string text, logTarget target)
{
	switch (target)
	{
	case CONSOLE: 
		std::cout << text;
		break;

	case FILE: 
		writeToLogFile(text);
		break;

	case BOTH:	
		std::cout << text;		
		writeToLogFile(text);
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
		writeToLogFile(std::to_string(number) + "\n");
	}

	if (target == Logger::BOTH) 
	{
		if (Logger::consoleLogging == true) { 
			std::cout << number << std::endl; 
		}
		if (Logger::fileLogging == true) writeToLogFile(std::to_string(number) + "\n");
	}
}

// Prints an error message and sets the console color to red.
void Logger::printError(std::string message, logTarget target)
{
	setConsoleColor("red");
	printLine("ERROR: " + message, target);
}

// Prints a warning message, sets the console color to yellow.
void Logger::printWarning(std::string message, logTarget target)
{
	setConsoleColor("yellow");
	printLine("WARNING: " + message, target);
}


// Prints one line into log target
void RoboticArm::Logger::printLine(std::string text, Logger::logTarget target)
{
	if (Logger::consoleLogging == true && target == CONSOLE)
	{
		std::cout << text << std::endl;
	}

	if (Logger::fileLogging == true && target == FILE)
	{
		writeToLogFile(text + "\n");
	}

	if (target == Logger::BOTH)
	{
		if (Logger::consoleLogging == true) { std::cout << text << std::endl; }
		if (Logger::fileLogging == true) { 
			writeToLogFile(text + "\n"); 
		}
	}
}

// Linefeed

void Logger::lineFeed(int numOfNewLines, logTarget target)
{
	// return if newlines value is invalid
	if(numOfNewLines < 1)return;

	int i = 0;

	for (i = 0; i < numOfNewLines; i++) {
		printLine("", target);
	};
		
}

void RoboticArm::Logger::printTime(logTarget target)
{
	struct tm currentTime;
	__time64_t long_time;
	errno_t err;
	std::string t;

	// Get time as 64-bit integer.
	_time64(&long_time);

	// Convert to local time.
	err = _localtime64_s(&currentTime, &long_time);
	if (err)
	{
		printf("Invalid argument to _localtime64_s.");
		exit(1);
	}

	int y, m, d, h, min, s;
	std::string y_s, m_s, d_s, h_s, min_s, s_s;

	// compensate year offset
	y = currentTime.tm_year + 1900;
	y_s = std::to_string(y);
	
	// handling leading zeros
	m = currentTime.tm_mon + 1;
	m_s = (m < 10 ? "0" + std::to_string(m) : std::to_string(m));
	
	d = currentTime.tm_mday;
	d_s = d < 10 ? "0" + std::to_string(d) : std::to_string(d);

	h = currentTime.tm_hour;
	h_s = h < 10 ? "0" + std::to_string(h) : std::to_string(h);

	min = currentTime.tm_min;
	min_s = min < 10 ? "0" + std::to_string(min) : std::to_string(min);

	s = currentTime.tm_sec;
	s_s = s < 10 ? "0" + std::to_string(s) : std::to_string(s);

	// convert time to a formatted string
	t.append(y_s + "-" + m_s + "-" + d_s + " ");
	t.append(h_s + ":" + min_s + ":" + s_s);

	// print to desired target
	Logger::print(t, target);
}



void Logger::enableLogging(Logger::logTarget target)
{
	switch (target) 
	{
		case Logger::logTarget::FILE:	
			Logger::fileLogging = true;
			break;

		case Logger::logTarget::CONSOLE:	
			Logger::consoleLogging = true;
			break;

		case Logger::logTarget::BOTH:	
			Logger::fileLogging = true;
			Logger::consoleLogging = true;
			break;

		default: break;
	}							
}

void Logger::disableLogging(Logger::logTarget target)
{
	switch (target)
	{
	case Logger::logTarget::FILE:	
		Logger::fileLogging = false;
		break;

	case Logger::logTarget::CONSOLE:	
		Logger::consoleLogging = false;
		break;

	case Logger::logTarget::BOTH:	
		Logger::fileLogging = false;
		Logger::consoleLogging = false;
		break;

	default: break;
	}
}

void Logger::printSeparator(logTarget target)
{
	printLine(Settings::getLogSeparatorLine(), target);
}

bool RoboticArm::Logger::isLoggingEnabled(logTarget target)
{
	switch (target) 
	{

	case BOTH:	
		if (consoleLogging == true && fileLogging == true)return true;
		break;

	case FILE:	
		if (fileLogging == true)return true;
		break;

	case CONSOLE: 
		if (consoleLogging == true)return true;
		break;

	default: 
		break;
	
	}
	
	return false;

}

void Logger::printProgramStart(logTarget target)
{
	// Program start message
	printSeparator(target);
	printTime(target);
	printLine(" Program started...", target);
	printSeparator(target);
	lineFeed(1, target);
}

// Sets the color of the console based on the given parameter and the previous console color.
// If console color ever sets to red, it can not be modified afterwards.
void Logger::setConsoleColor(std::string color)
{
	static std::string current = "normal";
	
	// return if console color is red
	if (current == "red")return;

	if (color == "red")
	{	
		current = "red";
		system("color 47");
	}
	else if (color == "yellow") {
		system("color 60");
	}
	else if(color == "normal"){
		system("color 07");
	}
}

void Logger::writeToLogFile(std::string text)
{
	logFile.open(Settings::getLogFilePath(), std::ios::out | std::ios::app);

	logFile << text;

	logFile.close();

}

}