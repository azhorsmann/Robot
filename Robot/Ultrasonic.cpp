/*
  Ultrasonic.cpp - Library for HC-SR04 Ultrasonic Ranging Module.library

  Created by ITead studio. Apr 20, 2010.
  iteadstudio.com
*/

#include <wiringPi.h>
#include "Ultrasonic.h"
#include <ctime>


Ultrasonic::Ultrasonic(int TP, int EP)
{
	pinMode(TP, OUTPUT);
	pinMode(EP, INPUT);
	Trig_pin = TP;
	Echo_pin = EP;
	initialize();
}

void Ultrasonic::initialize()
{
	digitalWrite(Trig_pin, HIGH);
	delay(1);
	digitalWrite(Trig_pin, LOW);
	delay(2000);
}

long Ultrasonic::Timing()
{
	struct timespec start, end;
	double soundSpeed = 17150;

	digitalWrite(Trig_pin, LOW);
	delayMicroseconds(2);
	digitalWrite(Trig_pin, HIGH);
	delayMicroseconds(10);
	digitalWrite(Trig_pin, LOW);

	while (digitalRead(Echo_pin) == 0)
	{
		clock_gettime(CLOCK_REALTIME, &start);
	}

	while (digitalRead(Echo_pin) == 1)
	{
		clock_gettime(CLOCK_REALTIME, &end);
	}

	double timespent = (end.tv_nsec - start.tv_nsec) / 1.0e9; // Convert nanoseconds to milliseconds

	duration = timespent * soundSpeed;

	//duration = pulseIn(Echo_pin,HIGH);

	return duration;
}


long Ultrasonic::Ranging(int sys)
{
	Timing();
	distacne_cm = duration;
	distance_inc = duration / 2.5;
	if (sys)
		return distacne_cm;
	else
		return distance_inc;
}