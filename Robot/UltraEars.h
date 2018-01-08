#ifndef __ultraears_H_
#define __ultraears_H_

#pragma once
#include "Node.h"

namespace BT
{
	class UltraEars : public Node
	{
	private:
		char* sharedMemory;

	public:
		UltraEars();
		UltraEars(std::string name, int minimumDistance, char* SharedMemory);
		~UltraEars();

		void Tick();
		int MinimumDistance;
	};
}

#endif
