#pragma once
#include "WPILib.h"
#include "Drive.hpp"




class XCaliber : public IterativeRobot{
private:
	Joystick* Buttons;
	Timer* StopWatch;

public:
	XCaliber();
	void RobotInit();
	void AutonomousInit();
	//void AutonomousPeriodic();
	void TeleopInit();
	void TeleopPeriodic();
	void TeleopContinuous();
<<<<<<< Updated upstream
=======
	~XCaliber();
>>>>>>> Stashed changes

};

START_ROBOT_CLASS(XCaliber);




