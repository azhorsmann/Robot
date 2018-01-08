#ifndef __Drive_H_
#define __Drive_H_

#pragma once
#include "Node.h"

namespace BT
{
	class Drive :
		public Node
	{
	public:
		Drive();
		Drive(std::string name);
		~Drive();

		void Tick();
		int Motor1Pin1 = -1;
		int Motor1Pin2 = -1;
		int Motor2Pin1 = -1;
		int Motor2Pin2 = -1;
		int TicksToDrive = -1;
		bool Rewerse = false;

	private:
		bool running;
		int ticksDriven;
	};

}

#endif