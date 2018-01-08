#include "UltraEars.h"

#include <wiringPi.h>
#include <boost/interprocess/shared_memory_object.hpp>
#include <boost/interprocess/mapped_region.hpp>

#include <iostream>

using namespace BT;

UltraEars::UltraEars()
{
	Status = Idle;
	Name = "n/a";
}

BT::UltraEars::UltraEars(std::string name, int minimumDistance, char* SharedMemory)
{
	Status = Idle;
	Name = name;
	MinimumDistance = minimumDistance;
	sharedMemory = SharedMemory;
}

UltraEars::~UltraEars()
{

}

void BT::UltraEars::Tick()
{
	std::cout << Name << " Tick\n";

	using namespace boost::interprocess;

	shared_memory_object shm(open_only, sharedMemory, read_write);

	//Set size 
	shm.truncate(sizeof(int));

	//Map the whole shared memory in this process
	mapped_region region(shm, read_only);

	std::cout << Name << " Tick2\n";

	int *i2 = static_cast<int*>(region.get_address());
	std::cout << "Distance: " << *i2 << "\n";

	int pwm = 1024;
	if (*i2 < (MinimumDistance * 2))
	{
		double percentage = ((MinimumDistance * 2) - *i2) *100 / MinimumDistance;
		pwm = pwm * (100 - percentage) / 100;

		if (pwm > 1024)
			pwm = 1024;

		if (pwm < 500)
			pwm = 500;

		pwmWrite(18, pwm);

		std::cout << "PWM: " << pwm << "\n";
	}
	else
		pwmWrite(18, pwm);

	if (*i2 < MinimumDistance)
		Status = NodeState::Failure;
	else
		Status = NodeState::Success;
}
