#ifndef __Turn_H_
#define __Turn_H_

#pragma once 
#include "Node.h"

namespace BT
{
	class Turn :
		public Node
	{
	public:
		Turn();
		Turn(std::string name);
		Turn(std::string name, int motor1Pin1, int motor1Pin2, int motor2Pin1, int motor2Pin2);
		~Turn();

		void Tick();
		int Motor1Pin1;
		int Motor1Pin2;
		int Motor2Pin1;
		int Motor2Pin2;
		bool Right;
	};
}

#endif