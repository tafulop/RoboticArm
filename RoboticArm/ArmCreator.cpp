#include "ArmCreator.h"

namespace RoboticArm {

	// set default values
	ArmCreator* ArmCreator::single = nullptr;
	bool ArmCreator::instanceFlag = false;

	// X-sructors
	ArmCreator::ArmCreator()
	{
	}

	ArmCreator::~ArmCreator()
	{
		single = nullptr;
		instanceFlag = false;
	}

	// Singleton instance query
	ArmCreator* RoboticArm::ArmCreator::getInstance()
	{
		if (!instanceFlag)
		{
			single = new ArmCreator();
			instanceFlag = true;
			return single;
		}
		else
		{
			return single;
		}
	}
	void ArmCreator::createJoints()
	{
		factory->CreateJoint("J1", 1122, 311, 345);
		factory->CreateJoint("J2", 1122, 311, 345);
		factory->CreateJoint("J3", 1122, 311, 345);
		factory->CreateJoint("J4", 1122, 311, 345);
		factory->CreateJoint("J5", 1122, 311, 345);

	}
	void ArmCreator::createArmParts()
	{
		factory->CreateArmPart("L12", 3344, 100);
		factory->CreateArmPart("L23", 3344, 100);
		factory->CreateArmPart("L34", 3344, 100);
		factory->CreateArmPart("L45", 3344, 100);
		factory->CreateArmPart("L5E", 3344, 100);

	}
	void ArmCreator::createBody()
	{
		factory->CreateBody("B", 123534);
	}
	void ArmCreator::createEffector()
	{
		factory->CreateEffector("E", 123);
	}

	void ArmCreator::setCoordinates()
	{
		
	}

	void ArmCreator::fillBondList()
	{
		std::string partlist[] = { "B", "J1", "L12", "J2", "L23", "J3", "L34", "J4", "L45", "J5", "L5E", "E", "\terminate" };
		
		for (int i = 0; partlist[i] != "\terminate"; i++) {
			bondList.emplace(bondList.end(), partlist[i]);
		}

	}
	void ArmCreator::createRoboticArm()
	{
		createJoints();
		createArmParts();
		setCoordinates();
		createBody();
		createEffector();
	}

	// Calculations
	void ArmCreator::calcEffectorPosition()
	{
		//calc->calculateEffectorPosition(&joints, &armParts, &body, &EffectorPosition);

	}

	void ArmCreator::printEffectorMatrix()
	{
		this->EffectorPosition.printData(Logger::BOTH);
	}

	void * ArmCreator::getPartByName(std::string name)
	{
		return factory->GetPartByName(name);
	}

}