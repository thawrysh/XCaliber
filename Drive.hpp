#pragma once
#include "WPILib.h"
//#include "XCaliberShared.hpp"

class Drive{
private:
	CANTalon *RightRear;
	CANTalon *RightFront;
	CANTalon *LeftRear;
	CANTalon *LeftFront;

	RobotDrive *SpeedBase;
	Encoder*leftEnc;
	Encoder*rightEnc;
	Timer *StopWatch;
	Joystick *JS;
	double distance;

public:

	void Auto();
	void TeleOp();
	Drive();
	~Drive();



};



