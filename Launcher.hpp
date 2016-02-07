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
	CANTalon *launchWheel;
	Solenoid *puncher;
	//Solenoid *position;
	Joystick *driveStick;


public:

	void Auto();
	void TeleOp();
	Launcher();
	~Launcher();


};



#endif /* SRC_LAUNCHER_HPP_ */
