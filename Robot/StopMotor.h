#ifndef __stopmotor_H_
#define __stopmotor_H_

#pragma once
#include "Node.h"

namespace BT
{
	class StopMotor : public Node
	{
	public:
		StopMotor();
		StopMotor(std::string name);
		StopMotor(std::string name, int motor1Pin1, int motor1Pin2, int motor2Pin1, int motor2Pin2);
		~StopMotor();

		void Tick();
		int Motor1Pin1 = -1;
		int Motor1Pin2 = -1;
		int Motor2Pin1 = -1;
		int Motor2Pin2 = -1;

	};
}

#endif