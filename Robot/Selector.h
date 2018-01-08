#ifndef __selector_H_
#define __selector_H_


#pragma once
#include "Composite.h"
#include <vector>

namespace BT
{
	class Selector :
		public CompositeNode
	{
	public:
		Selector(std::string name);
		Selector();
		~Selector();

		void Tick();
	};
}

#endif