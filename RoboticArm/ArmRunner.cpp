#include "ArmRunner.h"

namespace RoboticArm {

	// set default values
	ArmRunner* ArmRunner::single = nullptr;
	bool ArmRunner::instanceFlag = false;

	// X-sructors
	ArmRunner::ArmRunner()
	{
	}

	ArmRunner::~ArmRunner()
	{
		single = nullptr;
		instanceFlag = false;
	}

	// Singleton instance query
	ArmRunner* ArmRunner::getInstance()
	{
		if (instanceFlag == false)
		{
			single = new ArmRunner();
			instanceFlag = true;
			return single;
		}
		else
		{
			return single;
		}
	}

	void ArmRunner::createArm()
	{
		partContainer->createAll();
		partContainer->fillPTCL();
	}

	void ArmRunner::calculate()
	{
		IK.calcEffectorPosition();
	}

}