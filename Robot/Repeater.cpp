#include "Repeater.h"
#include <stdio.h>
#include <iostream>

using namespace BT;

Repeater::Repeater()
{
	Name = "n/a";
	Status = Idle;
	Counter = 0;
}

BT::Repeater::Repeater(std::string name)
{
	Name = name;
	Status = Idle;
	Counter = 0;
}


Repeater::~Repeater()
{

}

void BT::Repeater::Tick()
{
	std::cout << Name << "->" << Counter << " - " << Count << "\n";

	while (Counter < Count) {
		Counter++;
		std::cout << Name << "->" << Child->Name << " Tick \n" ;

		Child->Tick();
		if (Child->Status == NodeState::Running || Child->Status == NodeState::Success)
			Status = NodeState::Running;
		else
			Status = Child->Status;
		
		std::cout << Name << "->" << Child->Name << " Status: " << Child->Status << "\n";
		return;
	}

	if (Counter >= Count) 
	{
		Counter = 0;
		Status = NodeState::Success;
	}
}

