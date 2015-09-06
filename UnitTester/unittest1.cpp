#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\RoboticArm\Logger.h"
#include "..\RoboticArm\PartFactory.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTester
{		
	TEST_CLASS(LoggerTest)
	{
	public:
		
		TEST_METHOD(getLoggerInstance)
		{
			// Get logger instance
			RoboticArm::Logger* l = RoboticArm::Logger::getInstance();
			Assert::IsNotNull(l);		
		}

		TEST_METHOD(printToFile) 
		{
			// Get logger instance
			RoboticArm::Logger* l = RoboticArm::Logger::getInstance();
			l->enableLogging(RoboticArm::Logger::FILE);
			l->printLine("teszt",RoboticArm::Logger::FILE);
		}

		TEST_METHOD(printToFileDenied)
		{
			// Get logger instance
			RoboticArm::Logger* l = RoboticArm::Logger::getInstance();
			//l->enableLogging(RoboticArm::Logger::FILE);
			l->printLine("teszt", RoboticArm::Logger::FILE);
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