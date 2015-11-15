#pragma once

#include <iostream>
#include <thread>
#include <stdio.h>
#include <zmq.h>
#include <string>
#include "Communication.h"


namespace RoboticArm {

	class Simulation
	{
	private:

		// singleton
		static bool intanceFlag;
		static Simulation* single;

		// Socket settings
		std::string socketIP = "valami";
		int port = 5556;

		// Delay between socket sendings
		int sendDelay = 1000;

		// ZMQ Socket
		void *context;
		void *publisher;
		int rc;

		// motors
		std::vector<char*> motors;

		// The communicator
		Communication* c;

		// Socket handler thread
		std::thread communicator;

		// Socket handler function
		void static Communicate();

		Simulation();
		~Simulation();
	
	public:
		void startSend();
		static Simulation* getInstance();
	};

}