/*
 * Lifter.hpp
 *
 *  Created on: Feb 28, 2016
 *      Author: Developer
 */

#include "WPILib.h"

#ifndef SRC_LIFTER_HPP_
#define SRC_LIFTER_HPP_

class Lifter{
private:

	CANTalon* masterLifter;
	CANTalon* followerOne;
	CANTalon* followerTwo;

	Joystick* Buttons;

	AnalogPotentiometer* Limits;
	Timer* LifterStopWatch;

public:

	void TeleOp();
	Lifter();
	~Lifter();

};

#endif /* SRC_LIFTER_HPP_ */
