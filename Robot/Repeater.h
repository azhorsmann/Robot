#ifndef __repeater_H_
#define __repeater_H_


#pragma once
#include "Node.h"

namespace BT
{
	class Repeater : public Node
	{
	public:
		Repeater();
		Repeater(std::string name);
		~Repeater();

		void Tick();

		Node* Child;

		int Count;

		int Counter;
		
	};

}

#endif