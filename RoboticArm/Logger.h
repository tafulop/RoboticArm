#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <time.h>

// logger implements singleton design pattern

namespace RoboticArm {
	
	class Logger
	{
	private:
		// variables
		static bool consoleLogging;
		static bool fileLogging;
		static bool instanceFlag;
		static Logger *single;
		std::ofstream logFile;
		std::string logFileName;
		
		// methods
		Logger();
		~Logger();


	public:
		// variables
		const enum logTarget { CONSOLE, FILE, BOTH };

		// methods 
		static Logger* getInstance();
		void print(std::string text, logTarget target);
		void printLine(std::string text, logTarget target);
		void printLine(int number, logTarget target);
		void lineFeed(int numOfNewLines, logTarget target);
		void printTime(logTarget target);
		void enableLogging(logTarget target);
		void disableLogging(logTarget target);
		void printSeparator(logTarget target);
		bool isLoggingEnabled(logTarget target);
		void printProgramStart(logTarget target);

	};

}