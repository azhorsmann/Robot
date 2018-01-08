#include "Turn.h"
#include <wiringPi.h>

using namespace BT;

Turn::Turn()
{
	Status = Idle;
	Name = "n/a";
}

BT::Turn::Turn(std::string name)
{
	Status = Idle;
	Name = name;
}

BT::Turn::Turn(std::string name, int motor1Pin1, int motor1Pin2, int motor2Pin1, int motor2Pin2)
{
	Status = Idle;
	Name = name;
	Motor1Pin1 = motor1Pin1;
	Motor1Pin2 = motor1Pin2;
	Motor2Pin1 = motor2Pin1;
	Motor2Pin2 = motor2Pin2;
}


Turn::~Turn()
{
}

void BT::Turn::Tick()
{
	if (Right)
	{
		digitalWrite(Motor1Pin1, HIGH);
		digitalWrite(Motor1Pin2, LOW);

		digitalWrite(Motor2Pin1, LOW);
		digitalWrite(Motor2Pin2, HIGH);
	}
	else
	{
		digitalWrite(Motor1Pin1, LOW);
		digitalWrite(Motor1Pin2, HIGH);

		digitalWrite(Motor2Pin1, HIGH);
		digitalWrite(Motor2Pin2, LOW);
	}

	Status = NodeState::Success;
}
