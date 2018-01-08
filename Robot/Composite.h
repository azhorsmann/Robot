#ifndef __composite_H_
#define __composite_H_

#include "Node.h"
#include <vector>

namespace BT 
{
	class CompositeNode : public Node
	{
	public:
		CompositeNode(std::string Name);
		CompositeNode();
		~CompositeNode();
		std::vector<Node*> Children;
		virtual void Tick();
		int runningNode = -1;
	protected:
		Node* _runningNode;
	};
}

#endif