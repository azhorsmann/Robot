#ifndef __sequence_H_
#define __sequence_H_

#pragma once
#include "Composite.h"

namespace BT
{
	class Sequence :
		public CompositeNode
	{
	public:
		Sequence(std::string name);
		Sequence();
		~Sequence();
		bool IgnoreRunning;

		void Tick();
	};
}

#endif