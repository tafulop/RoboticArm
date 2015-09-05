#pragma once

#include <iostream>
#include <string>

// logger implements singleton design pattern
namespace RoboticArm {
	
	class Logger
	{
	private:
		static bool consoleLogging;
		static bool instanceFlag;
		static Logger *single;
		Logger();
		~Logger();

	public:
		const enum logTarget { CONSOLE, FILE };
		static Logger* getInstance();
		void printToDisplay(std::string text)
		{
			if (Logger::consoleLogging == false)return;
			std::cout << text << std::endl;
		}
		void printToDisplay(int number);
		void lineFeed(int numOfNewLines, logTarget target);
		void enableConsoleLogging();
		void disableConsoleLogging();

		int multi(int, int);

	};

}