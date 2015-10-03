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
		joints.insert(std::make_pair<std::string, Joint*>(std::string("J1"), factory->CreateJoint(1.1f, 100, 100)));
		joints.insert(std::make_pair<std::string, Joint*>(std::string("J2"), factory->CreateJoint(1.1f, 100, 100)));
		joints.insert(std::make_pair<std::string, Joint*>(std::string("J3"), factory->CreateJoint(1.1f, 100, 100)));
		joints.insert(std::make_pair<std::string, Joint*>(std::string("J4"), factory->CreateJoint(1.1f, 100, 100)));
		joints.insert(std::make_pair<std::string, Joint*>(std::string("J5"), factory->CreateJoint(1.1f, 100, 100)));

	}
	void ArmCreator::createArmParts()
	{
		armParts.insert(std::make_pair<std::string, ArmPart*>(std::string("L23"), factory->CreateArmPart(123.45f, 4234.3f)));
		armParts.insert(std::make_pair<std::string, ArmPart*>(std::string("L34"), factory->CreateArmPart(123.45f, 4234.3f)));
		armParts.insert(std::make_pair<std::string, ArmPart*>(std::string("L45"), factory->CreateArmPart(123.45f, 4234.3f)));
		armParts.insert(std::make_pair<std::string, ArmPart*>(std::string("L5E"), factory->CreateArmPart(123.45f, 4234.3f)));
	}
	void ArmCreator::setCoordinates()
	{
		jointCoordinates.insert(std::pair<std::string, Matrix>(std::string("B"), Matrix(10.3f, 45, 456.0f, 54)));
		jointCoordinates.insert(std::pair<std::string, Matrix>(std::string("E"), Matrix(10.3f, 45, 456.0f, 54)));
		jointCoordinates.insert(std::pair<std::string, Matrix>(std::string("J1"), Matrix(10.3f, 45, 456.0f, 54)));
		jointCoordinates.insert(std::pair<std::string, Matrix>(std::string("J2"), Matrix(10.3f, 45, 456.0f, 54)));

	}
	void ArmCreator::createRoboticArm()
	{
		createJoints();
		createArmParts();
		setCoordinates();
	}

	// Calculations
	void ArmCreator::calcEffectorPosition()
	{
		calc->calculateEffectorPosition(&joints, &EffectorPosition);
		
	}

	void printEffectorMatrix() {
		EffectorPosition.printData(Logger::BOTH);
	}

	
}