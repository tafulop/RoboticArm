#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\RoboticArm\Logger.h"
#include "..\RoboticArm\PartFactory.h"
#include "..\RoboticArm\Settings.h"
#include "..\RoboticArm\Matrix.h"
#include <stdio.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;


namespace UnitTester
{		
	TEST_CLASS(LoggerTest)
	{
	private:
		RoboticArm::Logger* l;
	
	public:
		

		// Must be the first test method
		TEST_METHOD(getLoggerInstance)
		{
			// Get logger instance
			this->l = RoboticArm::Logger::getInstance();
			Assert::IsNotNull(l);		
		}

		TEST_METHOD(singletonTest) {

			RoboticArm::Logger* l1 = RoboticArm::Logger::getInstance();
			RoboticArm::Logger* l2 = RoboticArm::Logger::getInstance();

			if (l1 != l2) {
				Assert::Fail();
			}
		}
		
		TEST_METHOD(defaultFileLogginStateCheck) 
		{
			Assert::IsFalse(l->isLoggingEnabled(RoboticArm::Logger::FILE));
		}

		TEST_METHOD(defaultConsoleLoggingStateCheck)
		{
			Assert::IsFalse(l->isLoggingEnabled(RoboticArm::Logger::CONSOLE));
		}

		TEST_METHOD(enableConsoleLoggingTest)
		{
			l->enableLogging(RoboticArm::Logger::CONSOLE);
			Assert::IsTrue(l->isLoggingEnabled(RoboticArm::Logger::CONSOLE));
			l->printTime(RoboticArm::Logger::CONSOLE);
		}

		TEST_METHOD(enableFileLoggingTest)
		{
			l->enableLogging(RoboticArm::Logger::FILE);
			Assert::IsTrue(l->isLoggingEnabled(RoboticArm::Logger::FILE));
		}

		TEST_METHOD(enableFileAndConsoleLoggingTest)
		{
			l->enableLogging(RoboticArm::Logger::BOTH);
			Assert::IsTrue(l->isLoggingEnabled(RoboticArm::Logger::BOTH));
		}

		TEST_METHOD(disableConsoleLoggingTest)
		{
			l->disableLogging(RoboticArm::Logger::CONSOLE);
			Assert::IsFalse(l->isLoggingEnabled(RoboticArm::Logger::CONSOLE));
		}

		TEST_METHOD(disableFileLoggingTest)
		{
			l->disableLogging(RoboticArm::Logger::FILE);
			Assert::IsFalse(l->isLoggingEnabled(RoboticArm::Logger::FILE));
		}

		TEST_METHOD(disableFileAndConsoleLoggingTest)
		{
			l->disableLogging(RoboticArm::Logger::BOTH);
			Assert::IsFalse(l->isLoggingEnabled(RoboticArm::Logger::BOTH));
		}

	};

	TEST_CLASS(PartFactoryTest)
	{
	public:

		TEST_METHOD(getPartFactoryInstance)
		{
			// Get instance
			RoboticArm::PartFactory* factory = RoboticArm::PartFactory::getInstance();
			Assert::IsNotNull(factory);

		}

		TEST_METHOD(singletonTest) 
		{
			
			RoboticArm::PartFactory* f1 = RoboticArm::PartFactory::getInstance();
			RoboticArm::PartFactory* f2 = RoboticArm::PartFactory::getInstance();

			if (f1 != f2) {
				Assert::Fail();
			}
		}

		

	};

	/*
	*	TEST SETTINGS PRESET VALUES
	*
	*/

	TEST_CLASS(SettingsTest)
	{
	public:
		TEST_METHOD(logFilePathTest) {
		
			if (RoboticArm::Settings::getLogFilePath() != "E:\\armlog.txt")
			{
				Assert::Fail();
			}
		
		}


	};

}