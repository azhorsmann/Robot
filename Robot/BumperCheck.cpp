#include "BumperCheck.h"
#include <stdio.h>
#include <iostream>
#include <wiringPi.h>

using namespace BT;

BumperCheck::BumperCheck()
{
}

BT::BumperCheck::BumperCheck(std::string name)
{
	Name = name;
	Status = Idle;
	//_tree = T;
}


BumperCheck::~BumperCheck()
{

}

void BT::BumperCheck::Tick()
{
	int bump = digitalRead(BumperPin);

	if (bump)
	{
		std::cout << Name << " BUMP!!! \n";
		Status = Failure;
		//_tree.TreeStorage[Name + "_BUMP", "true"];
	}
	else
	{
		std::cout << Name << " Free \n";
		Status = Success;
	}
}
