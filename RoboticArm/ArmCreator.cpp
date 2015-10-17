#include "ArmCreator.h"

namespace RoboticArm {


	// **************************************
	// Singleton init and method definitions
	// **************************************

	bool ArmCreator::instanceFlag = false;
	ArmCreator* ArmCreator::single = nullptr;

	ArmCreator::ArmCreator()
	{
	}

	ArmCreator::~ArmCreator()
	{
	}

	void ArmCreator::fillOrderedPartList()
	{
		orderedPartList.emplace(orderedPartList.end(), "B");
		orderedPartList.emplace(orderedPartList.end(), "J1");
		orderedPartList.emplace(orderedPartList.end(), "L12");
		orderedPartList.emplace(orderedPartList.end(), "J2");
		orderedPartList.emplace(orderedPartList.end(), "L23");
		orderedPartList.emplace(orderedPartList.end(), "J3");
		orderedPartList.emplace(orderedPartList.end(), "L34");
		orderedPartList.emplace(orderedPartList.end(), "J4");
		orderedPartList.emplace(orderedPartList.end(), "L45");
		orderedPartList.emplace(orderedPartList.end(), "J5");
		orderedPartList.emplace(orderedPartList.end(), "L5E");
		orderedPartList.emplace(orderedPartList.end(), "E");
	}

	ArmCreator* ArmCreator::getInstance() {
		if (instanceFlag == false) {
			single = new ArmCreator();
			instanceFlag = true;
			return single;
		}
		else {
			return single;
		}
	}

	void ArmCreator::parseXML()
	{
	}

	void ArmCreator::createParts()
	{
		createArmParts();
		createJoints();
		createBody();
		createEffector();
		createBonds();
	}

	void ArmCreator::createBody()
	{
		PC->addBody("B",345);
	}

	void ArmCreator::createArmParts()
	{
		PC->addArmPart("L12", 12, 12);
		PC->addArmPart("L23", 23, 12);
		PC->addArmPart("L34", 34, 123);
		PC->addArmPart("L45", 45, 123);
		PC->addArmPart("L5E", 55, 123);
	}

	void ArmCreator::createJoints()
	{
		PC->addJoint("J1",1,2,3);
		PC->addJoint("J2", 2, 21, 35);
		PC->addJoint("J3", 3, 22, 36);
		PC->addJoint("J4", 4, 23, 37);
		PC->addJoint("J5", 5, 24, 38);
	}

	void ArmCreator::createEffector()
	{
		PC->addEffector("E", 666);
	}

	void ArmCreator::createBonds()
	{
		PC->setBonds(orderedPartList);
	}

}