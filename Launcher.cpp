/*
 * Launcher.cpp
 *
 *  Created on: Feb 6, 2016
 *      Author: Developer
 */

#include "Launcher.hpp"

Launcher::Launcher() {

	fire=false;
	driveStick= new Joystick(0);
	launchWheel = new CANTalon(5);
	puncher = new Solenoid(1);
	//position = new Solenoid(2);

}

void Launcher::Auto(){

}


void Launcher::TeleOp(){

	fire=driveStick->GetRawButton(2);

	if(fire){
		launchWheel->Set(1);
		Wait(1);
		puncher->Set(true);
		Wait(1);
	}else{
		puncher->Set(false);
		launchWheel->Set(0);
	}
	}



Launcher::~Launcher(){

}


