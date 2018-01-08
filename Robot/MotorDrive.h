#ifndef __MotorDrive_H_
#define __MotorDrive_H_

#include "Node.h"

namespace BT
{
	class MotorDrive : public Node
	{
	public:
		MotorDrive();
		MotorDrive(std::string name);
		~MotorDrive();

		void Tick();
	};

}

#endif