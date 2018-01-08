#ifndef __node_H_
#define __node_H_

//class Tree;
//#include "Tree.h"

#include <string>

namespace BT
{
	enum NodeState { Success, Failure, Running, Idle, Halted, Exit };
	enum NodeType { Action, Condition, Control };

	enum FailurePolicy { FailOnOne, FailOnAll };
	enum SuccessPolicy { SucceedOnOne, SucceedOnAll };

	class Node
	{
	protected:
		//Tree* T;

	public:
		Node(std::string name);
		Node();
		~Node();
		std::string Name;

		NodeState Status;
		
		virtual void Tick();
	};
}

#endif