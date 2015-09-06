#pragma once

#include <iostream>
#include <fstream>
#include <string>


// logger implements singleton design pattern

namespace RoboticArm {
	
	class Logger
	{
	private:
		static bool consoleLogging;
		static bool fileLogging;
		static bool instanceFlag;
		static Logger *single;
		std::ofstream logFile;
		std::string logFileName;
		Logger();
		~Logger();


	public:
		const enum logTarget { CONSOLE, FILE, BOTH };
		static Logger* getInstance();
		void printLine(std::string text, logTarget target);
		void printLine(int number, logTarget target);
		void lineFeed(int numOfNewLines, logTarget target);
		void enableLogging(logTarget target);
		void disableLogging(logTarget target);
		bool isLoggingEnabled(logTarget target);

	};

}