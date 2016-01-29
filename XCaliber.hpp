#pragma once
#include "WPILib.h"
#include "Drive.hpp"



class XCaliber : public IterativeRobot{
private:
	//Task* Drive;



public:
	//XCaliber();
	//~XCaliber();
	void RobotInit();
	void AutonomousInit();
	void AutonomousPeriodic();
	void TeleopInit();
	void TeleopPeriodic();

};

START_ROBOT_CLASS(XCaliber);




