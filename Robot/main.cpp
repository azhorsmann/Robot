#include "Tree.h"
#include "Selector.h"
#include "Sequence.h"
#include "BumperCheck.h"
#include "Drive.h"
#include "MotorDrive.h"
#include "StopMotor.h"
#include "Repeater.h"
#include "Turn.h"
#include "UltraEars.h"
#include "Accelerate.h"

 
#include <wiringPi.h>
#include <list>
#include <thread>
#include <ctime>
#include <stdio.h>
#include <iostream>
#include <string>



#define	M1Pin1	5
#define	M1Pin2	6

#define	M2Pin1	23
#define	M2Pin2	24

#define bumperPinLeft 17
#define bumperPinRight 27

using namespace BT;

int main(void)
{
	wiringPiSetupGpio();
	 
	//Startup ultrasound listener.
	//int listenPid = system("sudo /home/azh/projects/MortenListen2/bin/ARM/Debug/MortenListen2.out &");

	pinMode(18, PWM_OUTPUT);
	pwmSetClock(200);
	pwmWrite(18, 1024);

	pinMode(bumperPinLeft, INPUT);
	pinMode(bumperPinRight, INPUT);

	pinMode(M1Pin1, OUTPUT);
	pinMode(M1Pin2, OUTPUT);

	pinMode(M2Pin1, OUTPUT);
	pinMode(M2Pin2, OUTPUT);

	Tree tree;

	Sequence rootChild = Sequence("RootChild");

	Sequence health = Sequence("Health");
	
	Selector bumperRight = Selector("Bumper Right");

	BumperCheck rightBumper = BumperCheck("Right Bumper");
	rightBumper.BumperPin = bumperPinRight;

	bumperRight.Children.push_back(&rightBumper);

	Sequence avoidRight = Sequence("Avoid Right");

	StopMotor stopavoidRight1 = StopMotor("Stop-Avoid Right 1", M1Pin1, M1Pin2, M2Pin1, M2Pin2);

	Repeater repeatStopRight1 = Repeater("Repeat Stop 1");
	repeatStopRight1.Count = 4;

	repeatStopRight1.Child = &stopavoidRight1;

	avoidRight.Children.push_back(&repeatStopRight1);

	Repeater repeatBackRight = Repeater("Repeat Back Right");
	repeatBackRight.Count = 10;

	Drive backRobotRight = Drive("Back Robot Right");
	backRobotRight.Motor1Pin1 = M1Pin1;
	backRobotRight.Motor1Pin2 = M1Pin2;

	backRobotRight.Motor2Pin1 = M2Pin1;
	backRobotRight.Motor2Pin2 = M2Pin2;
	backRobotRight.Rewerse = true;

	repeatBackRight.Child = &backRobotRight;

	avoidRight.Children.push_back(&repeatBackRight);

	StopMotor stopavoidRight2 = StopMotor("Stop-Avoid Right 2", M1Pin1, M1Pin2, M2Pin1, M2Pin2);

	Repeater repeatStopRight2 = Repeater("Repeat Stop right 2");
	repeatStopRight2.Count = 4;

	repeatStopRight2.Child = &stopavoidRight2;

	avoidRight.Children.push_back(&repeatStopRight2);

	Repeater repeatTurnRight = Repeater("Repeat turn right");
	repeatTurnRight.Count = 18;

	Turn turnAvoidRight = Turn("Turn Avoid right", M1Pin1, M1Pin2, M2Pin1, M2Pin2);
	turnAvoidRight.Right = true;

	repeatTurnRight.Child = &turnAvoidRight;

	avoidRight.Children.push_back(&repeatTurnRight);

	StopMotor stopavoidRight3 = StopMotor("Stop-Avoid 3", M1Pin1, M1Pin2, M2Pin1, M2Pin2);

	avoidRight.Children.push_back(&stopavoidRight3);

	bumperRight.Children.push_back(&avoidRight);

	health.Children.push_back(&bumperRight);


	UltraEars ue = UltraEars("Listen", 25, "MortenListenMemoryRight");

	Selector earsRight = Selector("Ears Bumper Right");

	earsRight.Children.push_back(&ue);

	Sequence avoidEarsRight = Sequence("Avoid Right");

	StopMotor stopavoidEarsRight1 = StopMotor("Stop-Avoid Right 1", M1Pin1, M1Pin2, M2Pin1, M2Pin2);

	Repeater repeatStopEarsRight1 = Repeater("Repeat Stop 1");
	repeatStopEarsRight1.Count = 4;

	repeatStopEarsRight1.Child = &stopavoidEarsRight1;

	avoidEarsRight.Children.push_back(&repeatStopEarsRight1);

	Repeater repeatBackEarsRight = Repeater("Repeat Back Right");
	repeatBackEarsRight.Count = 10;

	Drive backRobotEarsRight = Drive("Back Robot Right");
	backRobotEarsRight.Motor1Pin1 = M1Pin1;
	backRobotEarsRight.Motor1Pin2 = M1Pin2;

	backRobotEarsRight.Motor2Pin1 = M2Pin1;
	backRobotEarsRight.Motor2Pin2 = M2Pin2;
	backRobotEarsRight.Rewerse = true;

	repeatBackEarsRight.Child = &backRobotEarsRight;

	avoidEarsRight.Children.push_back(&repeatBackEarsRight);

	StopMotor stopavoidEarsRight2 = StopMotor("Stop-Avoid Right 2", M1Pin1, M1Pin2, M2Pin1, M2Pin2);

	Repeater repeatStopEarsRight2 = Repeater("Repeat Stop right 2");
	repeatStopEarsRight2.Count = 4;

	repeatStopEarsRight2.Child = &stopavoidEarsRight2;

	avoidEarsRight.Children.push_back(&repeatStopEarsRight2);

	Repeater repeatTurnEarsRight = Repeater("Repeat turn right");
	repeatTurnEarsRight.Count = 18;

	Turn turnAvoidEarsRight = Turn("Turn Avoid right", M1Pin1, M1Pin2, M2Pin1, M2Pin2);
	turnAvoidEarsRight.Right = true;

	repeatTurnEarsRight.Child = &turnAvoidEarsRight;

	avoidEarsRight.Children.push_back(&repeatTurnEarsRight);

	StopMotor stopavoidEarsRight3 = StopMotor("Stop-Avoid 3", M1Pin1, M1Pin2, M2Pin1, M2Pin2);

	avoidEarsRight.Children.push_back(&stopavoidEarsRight3);

	earsRight.Children.push_back(&avoidEarsRight);

	health.Children.push_back(&earsRight);




	//Ears left
	UltraEars ueLeft = UltraEars("Listen", 30, "MortenListenMemoryLeft");

	Selector earsLeft = Selector("Bumper Left");

	earsLeft.Children.push_back(&ueLeft);

	Sequence avoidEarsLeft = Sequence("Avoid Left");

	StopMotor stopavoidEarsLeft1 = StopMotor("Stop-Avoid Left 1", M1Pin1, M1Pin2, M2Pin1, M2Pin2);

	Repeater repeatStopEarsLeft1 = Repeater("Repeat Stop 1");
	repeatStopEarsLeft1.Count = 4;

	repeatStopEarsLeft1.Child = &stopavoidEarsLeft1;

	avoidEarsLeft.Children.push_back(&repeatStopEarsLeft1);

	Repeater repeatBackEarsLeft = Repeater("Repeat Back Left");
	repeatBackEarsLeft.Count = 10;

	Drive backRobotEarsLeft = Drive("Back Robot Left");
	backRobotEarsLeft.Motor1Pin1 = M1Pin1;
	backRobotEarsLeft.Motor1Pin2 = M1Pin2;

	backRobotEarsLeft.Motor2Pin1 = M2Pin1;
	backRobotEarsLeft.Motor2Pin2 = M2Pin2;
	backRobotEarsLeft.Rewerse = true;

	repeatBackEarsLeft.Child = &backRobotEarsLeft;

	avoidEarsLeft.Children.push_back(&repeatBackEarsLeft);

	StopMotor stopavoidEarsLeft2 = StopMotor("Stop-Avoid Left 2", M1Pin1, M1Pin2, M2Pin1, M2Pin2);

	Repeater repeatStopEarsLeft2 = Repeater("Repeat Stop left 2");
	repeatStopEarsLeft2.Count = 4;

	repeatStopEarsLeft2.Child = &stopavoidEarsLeft2;

	avoidEarsLeft.Children.push_back(&repeatStopEarsLeft2);

	Repeater repeatTurnEarsLeft = Repeater("Repeat turn left");
	repeatTurnEarsLeft.Count = 18;

	Turn turnAvoidEarsLeft = Turn("Turn Avoid left", M1Pin1, M1Pin2, M2Pin1, M2Pin2);
	turnAvoidEarsLeft.Right = true;

	repeatTurnEarsLeft.Child = &turnAvoidEarsLeft;

	avoidEarsLeft.Children.push_back(&repeatTurnEarsLeft);

	StopMotor stopavoidEarsLeft3 = StopMotor("Stop-Avoid 3", M1Pin1, M1Pin2, M2Pin1, M2Pin2);

	avoidEarsLeft.Children.push_back(&stopavoidEarsLeft3);

	earsLeft.Children.push_back(&avoidEarsLeft);

	health.Children.push_back(&earsLeft);



	Selector bumperLeft = Selector("Bumper Left");

	BumperCheck leftBumper = BumperCheck("Left Bumper");
	leftBumper.BumperPin = bumperPinLeft;

	bumperLeft.Children.push_back(&leftBumper);

	Sequence avoidLeft = Sequence("Avoid");

	StopMotor stopavoidLeft1 = StopMotor("Stop-Avoid 1", M1Pin1, M1Pin2, M2Pin1, M2Pin2);

	Repeater repeatStopLeft1 = Repeater("Repeat Stop 1");
	repeatStopLeft1.Count = 4;

	repeatStopLeft1.Child = &stopavoidLeft1;

	avoidLeft.Children.push_back(&repeatStopLeft1);

	Repeater repeatBackLeft = Repeater("Repeat Back left");
	repeatBackLeft.Count = 10;

	Drive backRobotLeft = Drive("Back Robot left");
	backRobotLeft.Motor1Pin1 = M1Pin1;
	backRobotLeft.Motor1Pin2 = M1Pin2;

	backRobotLeft.Motor2Pin1 = M2Pin1;
	backRobotLeft.Motor2Pin2 = M2Pin2;
	backRobotLeft.Rewerse = true;

	repeatBackLeft.Child = &backRobotLeft;

	avoidLeft.Children.push_back(&repeatBackLeft);

	StopMotor stopavoidLeft2 = StopMotor("Stop-Avoid right 2", M1Pin1, M1Pin2, M2Pin1, M2Pin2);

	Repeater repeatStopLeft2 = Repeater("Repeat Stop right 2");
	repeatStopLeft2.Count = 4;

	repeatStopLeft2.Child = &stopavoidLeft2;

	avoidLeft.Children.push_back(&repeatStopLeft2);

	Repeater repeatTurnLeft = Repeater("Repeat turn right");
	repeatTurnLeft.Count = 18;

	Turn turnAvoidLeft = Turn("Turn Avoid left", M1Pin1, M1Pin2, M2Pin1, M2Pin2);
	turnAvoidLeft.Right = false;

	repeatTurnLeft.Child = &turnAvoidLeft;

	avoidLeft.Children.push_back(&repeatTurnLeft);

	StopMotor stopavoid3 = StopMotor("Stop-Avoid right 3", M1Pin1, M1Pin2, M2Pin1, M2Pin2);

	avoidLeft.Children.push_back(&stopavoid3);

	bumperLeft.Children.push_back(&avoidLeft);

	health.Children.push_back(&bumperLeft);

	rootChild.Children.push_back(&health);
	rootChild.IgnoreRunning = true;

	Sequence drive = Sequence("Drive");

	Repeater accelerateReapeter = Repeater("Accelerate Loop");
	accelerateReapeter.Count = 50;
	
	Accelerate accelrate = Accelerate("Accelerate");
	accelrate.RepeaterParent = &accelerateReapeter;

	accelerateReapeter.Child = &accelrate;

	drive.Children.push_back(&accelerateReapeter);


	Drive cruise = Drive("Cruise");
	cruise.Motor1Pin1 = M1Pin1;
	cruise.Motor1Pin2 = M1Pin2;
	cruise.Motor2Pin1 = M2Pin1;
	cruise.Motor2Pin2 = M2Pin2;

	drive.Children.push_back(&cruise);

	rootChild.Children.push_back(&drive);

	tree.Child = &rootChild;

	for (int i = 0;i<800;++i)
	{
		tree.Tick();
		std::cout << "main loop " << i << '\n';
		std::this_thread::sleep_for(std::chrono::milliseconds(50));
	}

	//Stop robot
	digitalWrite(M1Pin1, LOW);
	digitalWrite(M1Pin2, LOW);
	digitalWrite(M2Pin1, LOW);
	digitalWrite(M2Pin2, LOW);

	std::cout << "DONE\n";

	return 0;
}
