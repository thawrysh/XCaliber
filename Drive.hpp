#pragma once
#include "WPILib.h"
#include "XCaliberShared.hpp"

class Drive{
	private:
		CANTalon *RightRear;
		CANTalon *RightFront;
		CANTalon *LeftRear;
		CANTalon *LeftFront;

		Solenoid *lowBar;
		Solenoid *GearShifter;
		Joystick* Buttons;

		RobotDrive *SpeedBase;
		Encoder *leftEnc;
		Encoder *rightEnc;
		Timer *StopWatch;
		Joystick *JS;
		AnalogGyro *navX;
		double distance;
		double circum;

		bool Shift;



	public:

		void ObstacleOne();
		void Auto();
		void TeleOp();
		void AutoPeriodic();
		Drive();
		~Drive();

};
