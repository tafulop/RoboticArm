// RoboticArmCmd.cpp : Defines the entry point for the console application
//

#include "stdafx.h"
#include "..\RoboticArm\Logger.h"
#include "..\RoboticArm\PartFactory.h"
#include "..\RoboticArm\Settings.h"
#include "..\RoboticArm\Matrix.h"
#include <map>


int main()
{
	
	using namespace RoboticArm;

	// Initializing...
	Logger* log;
	log = Logger::getInstance();
	log->enableLogging(Logger::BOTH);

	PartFactory* factory;
	factory = PartFactory::getInstance();

	// Program start message
	log->printSeparator(Logger::BOTH);
	log->printTime(Logger::BOTH);
	log->printLine(" Program started...", Logger::BOTH);
	log->printSeparator(Logger::BOTH);	
	log->lineFeed(1, Logger::BOTH);

	// CREATE ARMPARTS
	std::map<std::string, ArmPart*> ArmParts;

	ArmParts.insert(std::make_pair<std::string,ArmPart*>(std::string("L23"), factory->CreateArmPart(123.45f, 4234.3f)));
	ArmParts.insert(std::make_pair<std::string, ArmPart*>(std::string("L34"), factory->CreateArmPart(123.45f, 4234.3f)));
	ArmParts.insert(std::make_pair<std::string, ArmPart*>(std::string("L45"), factory->CreateArmPart(123.45f, 4234.3f)));
	ArmParts.insert(std::make_pair<std::string, ArmPart*>(std::string("L5E"), factory->CreateArmPart(123.45f, 4234.3f)));

	log->printSeparator(Logger::BOTH);
	log->lineFeed(1, Logger::BOTH);

	// CREATE JOINTS
	std::map<std::string, Joint*> Joints;

	Joints.insert(std::make_pair<std::string, Joint*>(std::string("J1"), factory->CreateJoint(1.1f, 100, 100)));
	Joints.insert(std::make_pair<std::string, Joint*>(std::string("J2"), factory->CreateJoint(1.1f, 100, 100)));
	Joints.insert(std::make_pair<std::string, Joint*>(std::string("J3"), factory->CreateJoint(1.1f, 100, 100)));
	Joints.insert(std::make_pair<std::string, Joint*>(std::string("J4"), factory->CreateJoint(1.1f, 100, 100)));
	Joints.insert(std::make_pair<std::string, Joint*>(std::string("J5"), factory->CreateJoint(1.1f, 100, 100)));

	log->printSeparator(Logger::BOTH);
	log->lineFeed(1, Logger::BOTH);

	// EFFECTOR
	std::map<std::string, Effector*> Effector;

	Effector["E"] = factory->CreateEffector(40);

	log->printSeparator(Logger::BOTH);
	log->lineFeed(1, Logger::BOTH);

	// BODY
	std::map<std::string, Body*> Body;

	Body["B"] = factory->CreateBody(5000);

	log->printSeparator(Logger::BOTH);
	

	// NUMBER OF CREATED PARTS
	log->printLine("Number of created parts: " + std::to_string(factory->GetNumberOfParts()), Logger::CONSOLE);

	log->printSeparator(Logger::CONSOLE);
	log->lineFeed(1, Logger::CONSOLE);

	// ASSIGN MATRIXES TO PARTS
	std::map <std::string, Matrix>PartCoordinates;

	PartCoordinates.insert(std::pair<std::string, Matrix>(std::string("B"), Matrix(10.3f, 45, 456.0f, 54)));
	PartCoordinates.insert(std::pair<std::string, Matrix>(std::string("E"), Matrix(10.3f, 45, 456.0f, 54)));
	PartCoordinates.insert(std::pair<std::string, Matrix>(std::string("J1"), Matrix(10.3f, 45, 456.0f, 54)));
	PartCoordinates.insert(std::pair<std::string, Matrix>(std::string("J2"), Matrix(10.3f, 45, 456.0f, 54)));

	
	Settings::getConfigXMLData();


	// prevent auto-exiting
	system("pause");

	return 0;
}

