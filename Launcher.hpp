/*
 * Launcher.hpp
 *
 *  Created on: Feb 6, 2016
 *      Author: Developer
 */

#include "WPILib.h"
#ifndef SRC_LAUNCHER_HPP_
#define SRC_LAUNCHER_HPP_

class Launcher{
private:

	bool fire;
	bool test;
	CANTalon *launchWheel;
	Talon *lAct;
	Solenoid *puncher;
	Relay *spike;
	//Solenoid *position;
	Joystick* JS;
	Timer* Stopwatch;
	Joystick* Buttons;


public:

	void Auto();
	void TeleOp();
	void Feeder();
	void Act();
	Launcher();
	~Launcher();


};



#endif /* SRC_LAUNCHER_HPP_ */
