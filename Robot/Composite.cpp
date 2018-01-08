#include "Composite.h"

#include <iostream>


using namespace BT;

CompositeNode::CompositeNode(std::string name)
{
	Name = name;
	runningNode = -1;
}

BT::CompositeNode::CompositeNode()
{
	Status = Idle;
	Name = "n/a";
	runningNode = -1;
}


CompositeNode::~CompositeNode()
{
}

void BT::CompositeNode::Tick()
{
	std::cout << "Composite Tick: " << Name << '\n';

}

