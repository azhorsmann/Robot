#include "Drive.h"

#include <iostream>
#include <wiringPi.h>

using namespace BT;

Drive::Drive()
{
	Status = Idle;
	Name = "n/a";
	Motor1Pin1 = -1;
	Motor1Pin2 = -1;
	Motor2Pin1 = -1;
	Motor2Pin2 = -1;
	running = false;
}

BT::Drive::Drive(std::string name)
{
	running = false;
	Status = Idle;
	Name = name;
	Motor1Pin1 = -1;
	Motor1Pin2 = -1;
	Motor2Pin1 = -1;
	Motor2Pin2 = -1;
	Rewerse = false;
}


Drive::~Drive()
{

}

void BT::Drive::Tick()
{
	//Drive engines...
	if (Rewerse)
	{
		digitalWrite(Motor1Pin1, HIGH);
		digitalWrite(Motor1Pin2, LOW);

		digitalWrite(Motor2Pin1, HIGH);
		digitalWrite(Motor2Pin2, LOW);
	}
	else
	{
		digitalWrite(Motor1Pin1, LOW);
		digitalWrite(Motor1Pin2, HIGH);

		digitalWrite(Motor2Pin1, LOW);
		digitalWrite(Motor2Pin2, HIGH);
	}

	std::cout << Name << " -> Driving...\n";
	running = true;
	Status = NodeState::Running;
}
