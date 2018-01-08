#include "Sequence.h"
#include <stdio.h>
#include <iostream>

using namespace BT;

Sequence::Sequence(std::string name)
{
	Status = Idle;
	Name = name;
	IgnoreRunning = false;
}

Sequence::Sequence()
{
	Status = Idle;
	Name = "n/a";
	IgnoreRunning = false;
}

Sequence::~Sequence()
{
	Name = "";
	Status = Idle;
	IgnoreRunning = false;
}

void BT::Sequence::Tick()
{
	std::cout << "Tick: " << Name << '\n';

	int currentIndex = -1;

	if (!IgnoreRunning)
	{
		for (int i = 0; i < Children.size(); i++)
		{
			if (Children[i]->Status == NodeState::Running)
			{
				currentIndex = i;

				Children[i]->Tick();

				if (Children[i]->Status == NodeState::Running)
				{
					Status = NodeState::Running;
					return;
				}

				if (Children[i]->Status == NodeState::Failure)
				{
					Status = NodeState::Failure;
					_runningNode = nullptr;
					return;
				}

				if (Children[i]->Status == NodeState::Success)
				{
					Status = NodeState::Success;
					_runningNode = nullptr;
					break;
				}
			}
		}
	}


	for (int i = 0; i < Children.size(); i++)
	{
		if (currentIndex > -1 && currentIndex >= i)
			continue;

		std::cout << Name << " -> " << Children[i]->Name << " Tick" << '\n';

		Children[i]->Tick();
		Status = Children[i]->Status;

		if (Children[i]->Status == NodeState::Running)
		{
			_runningNode = Children[i];
			std::cout << Name << " Status: " << Status << '\n';
			return;
		}

		if (Children[i]->Status == NodeState::Failure)
		{
			_runningNode = nullptr;
			std::cout << Name << " Status: " << Status << '\n';
			return;
		}

		std::cout << Name << " -> " << Children[i]->Name << " Status: " << Children[i]->Status << '\n';
		std::cout << Name << " RunningNode: " << runningNode << '\n';
	}

	Status = NodeState::Success;
	std::cout << Name << " Status: " << Status << '\n';
	return;
}
