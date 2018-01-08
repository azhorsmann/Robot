#include "Node.h"

#include <stdio.h>
#include <iostream>

using namespace BT;

BT::Node::Node(std::string name)
{
	Status = Idle;
	Name = name;
	//T = t;
}

Node::Node()
{
	Status = Idle;
	Name = "n/a";
}


Node::~Node()
{

}

void BT::Node::Tick()
{
	std::cout << "Node Tick: " << Name << '\n';
}


