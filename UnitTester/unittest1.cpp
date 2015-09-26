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

		TEST_METHOD(createBody)
		{
			// Get factory
			RoboticArm::PartFactory* factory = RoboticArm::PartFactory::getInstance();

			// Create joint
			RoboticArm::Body* b = factory->CreateBody(131.0);
			Assert::IsNotNull(b);

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
namespace CalculationTester {

	TEST_CLASS(matrixTest) {
	
	/*	x: -1.407455
		y: 1.001131
		z: 5.659334
		w: 2.817591		*/

		TEST_METHOD(DenavitHartenbergTransformationTest) {

			using namespace RoboticArm;
			float x, y, z, w;
			Matrix m = Matrix(5, 3, 1, 1);
			m.DHTransformation(3.14f*0.75f, 0.5f * 3.14f, 0.4f, 0.2f);

			wchar_t message[200];

			x = m.getCoordinate("x");
			y = m.getCoordinate("y");
			z = m.getCoordinate("z");
			w = m.getCoordinate("w");

			_swprintf(message, L"Wrong value of x: %f Accepted: -1,407", x);
			if (x < -1.408 || x > -1.406)Assert::Fail(message, LINE_INFO()); // accepted value: -1.407
			
			_swprintf(message, L"Wrong value of y: %f Accepted: 1.001", y);
			if (y > 1.002 || y < 1.000)Assert::Fail(message, LINE_INFO());		// accepted: 1.001

			_swprintf(message, L"Wrong value of z: %f Accepted: 5.659", z);
			if (z > 5.660 || z < 5.658)Assert::Fail(message, LINE_INFO()); // 5.659
			
			_swprintf(message, L"Wrong value of w: %f Accepted: 2.817", w);
			if (w < 2.816 || w > 2.818)Assert::Fail(message, LINE_INFO()); // 2.817
		

		}
	
	};


}