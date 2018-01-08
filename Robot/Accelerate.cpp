#include "Accelerate.h"

#include <iostream>
#include <wiringPi.h>


using namespace BT;


Accelerate::Accelerate()
{

}

BT::Accelerate::Accelerate(std::string name)
{
	Name = name;
	Status = NodeState::Idle;
}


Accelerate::~Accelerate()
{

}

void BT::Accelerate::Tick()
{
	std::cout << Name << " -> Tick\n";

	digitalWrite(5, LOW);
	digitalWrite(6, HIGH);

	digitalWrite(23, LOW);
	digitalWrite(24, HIGH);

	int range = 1024 / RepeaterParent->Count * RepeaterParent->Counter;
	if (range > 1024)
		range = 1024;
	

	pwmWrite(18, range);

	Status = NodeState::Success;
}
