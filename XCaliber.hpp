#pragma once
#include "WPILib.h"
#include "Drive.hpp"



class XCaliber : public IterativeRobot{
private:
	//Task* Drive;



public:
	XCaliber();
	~XCaliber();
	void robotInit();
	void autonomousInit();
	void autonomousPeriodic();
	void teleopInt();
	void teleopPeriodic();

};




