#include "Selector.h"
#include <stdio.h>
#include <iostream>

using namespace BT;

Selector::Selector(std::string name)
{
	Status = Idle;
	Name = name;
	runningNode = -1;
}

Selector::Selector()
{
	Status = Idle;
	Name = "n/a";
	runningNode = -1;
}


Selector::~Selector()
{

}

void Selector::Tick()
{
	std::cout << "Selector->Tick: " << Name << " " << Status << " " << runningNode << '\n';

	if (Status == NodeState::Running && runningNode > -1)
	{
		//Return runnning if child is still running. TODO: Tick child and handle running in child
		if (Children[runningNode]->Status == NodeState::Running)
		{
			Children[runningNode]->Tick();

			if (Children[runningNode]->Status == NodeState::Running)
				return;
		}
	}

	std::cout << "Selector->Tick: " << Name << '\n';

	for(int i = 0; i < Children.size(); i++)
	{
		//Continue past previous running node.
		if (runningNode >= 0)
		{
			if (runningNode < i)
				continue;

			if (runningNode == i)
			{
				runningNode = -1;
				continue;
			}
		}

		Children[i]->Tick();
		Status = Children[i]->Status;
		std::cout << Name << "->" << Children[i]->Name << " " << Children[i]->Status << '\n';

		//First success and node return, not executing the rest og the child nodes.
		if (Children[i]->Status == 0)
			return;

		//If child is running, we wait for this node to complete
		if (Children[i]->Status == NodeState::Running)
		{
			runningNode = i;
			Status = NodeState::Running;
			return;
		}
	}

	//If where are here no child have exited with status success.
	Status = NodeState::Failure;
	std::cout << Name << " Status " << Status << '\n';
}
