#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\RoboticArm\Logger.h"
#include "..\RoboticArm\PartFactory.h"

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

			// Singleton behavioral test
			//RoboticArm::PartFactory* factory2 = RoboticArm::PartFactory::getInstance();
			//Assert::AreEqual(*factory, *factory2);
		}

		TEST_METHOD(createJoint)
		{
			// Get factory
			RoboticArm::PartFactory* factory = RoboticArm::PartFactory::getInstance();

			// Create joint
			RoboticArm::Joint* j = factory->CreateJoint(131.0, 100.0, 200.0);
			Assert::IsNotNull(j);

		}

		TEST_METHOD(createJointDenied) {

			// Get factory
			RoboticArm::PartFactory* factory = RoboticArm::PartFactory::getInstance();

			// Mass below zero
			RoboticArm::Joint* j1 = factory->CreateJoint(-1, 100.0, 200.0);
			Assert::IsNull(j1);

		}

		TEST_METHOD(createArmPart)
		{
			// Get factory
			RoboticArm::PartFactory* factory = RoboticArm::PartFactory::getInstance();

			RoboticArm::ArmPart* a = factory->CreateArmPart(100.0, 200);
			Assert::IsNotNull(a);

		}


		TEST_METHOD(createArmPartDenied)
		{
			// Get factory
			RoboticArm::PartFactory* factory = RoboticArm::PartFactory::getInstance();

			RoboticArm::ArmPart* a = factory->CreateArmPart(-100.0, 200);
			Assert::IsNull(a);

		}

		TEST_METHOD(createEffector)
		{
			// Get factory
			RoboticArm::PartFactory* factory = RoboticArm::PartFactory::getInstance();

			RoboticArm::Effector* e = factory->CreateEffector(100);
			Assert::IsNotNull(e);

		}


		TEST_METHOD(createEffectorDenied)
		{
			// Get factory
			RoboticArm::PartFactory* factory = RoboticArm::PartFactory::getInstance();

			RoboticArm::Effector* e = factory->CreateEffector(-100.0);
			Assert::IsNull(e);

		}

	};
}