#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\RoboticArm\Logger.h"
#include "..\RoboticArm\PartFactory.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTester
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(MultiplyTest)
		{
			// TODO: Your test code here
			RoboticArm::PartFactory* factory = RoboticArm::PartFactory::getInstance();
			std::string a = "a";
			std::string b = "b";

			RoboticArm::Logger* l = RoboticArm::Logger::getInstance();


			int exp = 6;
			int act = l->multi(2, 3);
			Assert::AreEqual(exp, act, 0.1111);
			
		}

	};
}