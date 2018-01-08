#include "MotorDrive.h"
#include <stdio.h>
#include <iostream>
#include <wiringPi.h>

using namespace BT;


MotorDrive::MotorDrive()
{
}

BT::MotorDrive::MotorDrive(std::string name)
{
	Name = name;
	Status = Idle;
}



MotorDrive::~MotorDrive()
{
}

void BT::MotorDrive::Tick()
{
}
