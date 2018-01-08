#ifndef __bumpercheck_H_
#define __bumpercheck_H_

#pragma once
#include "Node.h"

namespace BT {
	class BumperCheck :
		public Node
	{
	public:
		BumperCheck();
		BumperCheck(std::string name);

		~BumperCheck();
		int BumperPin = -1;
		void Tick();
	};
}

#endif