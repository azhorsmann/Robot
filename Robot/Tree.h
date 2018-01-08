#ifndef __tree_H_
#define __tree_H_

#include "Sequence.h"

#include <map>
#include <string>

namespace BT {
	class Tree
	{
	public:
		Tree();
		~Tree();
		void Tick();
		Sequence* Child;
		std::map<std::string, std::string> TreeStorage;
	};
}

#endif