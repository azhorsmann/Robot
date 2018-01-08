#include "StopMotor.h"
#include <wiringPi.h>

using namespace BT;


StopMotor::StopMotor()
{
	Name = "n/a";
	Motor1Pin1 = -1;
	Motor1Pin2 = -1;
	Motor2Pin1 = -1;
	Motor2Pin2 = -1;
	Status = Idle;
}

BT::StopMotor::StopMotor(std::string name)
{
	Name = name;
	Motor1Pin1 = -1;
	Motor1Pin2 = -1;
	Motor2Pin1 = -1;
	Motor2Pin2 = -1;
	Status = Idle;
}

BT::StopMotor::StopMotor(std::string name, int motor1Pin1, int motor1Pin2, int motor2Pin1, int motor2Pin2)
{
	Name = name;
	Motor1Pin1 = motor1Pin1;
	Motor1Pin2 = motor1Pin2;
	Motor2Pin1 = motor2Pin1;
	Motor2Pin2 = motor2Pin2;
	Status = Idle;
}


StopMotor::~StopMotor()
{
}

void BT::StopMotor::Tick()
{
	digitalWrite(Motor1Pin1, LOW);
	digitalWrite(Motor1Pin2, LOW);

	digitalWrite(Motor2Pin1, LOW);
	digitalWrite(Motor2Pin2, LOW);
	Status = Success;
}