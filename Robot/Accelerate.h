#ifndef __accelerate_H_
#define __accelerate_H_

#pragma once
#include "Repeater.h"

namespace BT {
	class Accelerate :
		public Node
	{
	public:
		Accelerate();
		Accelerate(std::string name);
		~Accelerate();

		void Tick();

		int PWMPin = -1;
		Repeater* RepeaterParent;

	};

}

#endif
