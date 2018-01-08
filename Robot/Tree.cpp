#include <iostream>
#include <map>
#include <string>
#include "Tree.h"

using namespace BT;

Tree::Tree()
{

}


Tree::~Tree()
{
}

void BT::Tree::Tick()
{
	std::cout << "Tree tick" << '\n';
	Child->Tick();
}
