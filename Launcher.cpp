/*
 * Launcher.cpp
 *
 *  Created on: Feb 6, 2016
 *      Author: Developer
 */

#include "Launcher.hpp"

Launcher::Launcher() {

	fire=false;
	Buttons = new Joystick(1);
	JS= new Joystick(0);
	launchWheel = new CANTalon(5);
	lAct = new Talon(0);
	puncher = new Solenoid(2);
	spike = new Relay(0);
	//position = new Solenoid(2);
	Stopwatch = new Timer();

}

void Launcher::Auto(){

}

void Launcher::Feeder(){
	if(Buttons->GetRawButton(9)){
		spike->Set(Relay::Value::kForward);

	}else if(Buttons->GetRawButton(10)){
		spike->Set(Relay::Value::kReverse);
	}else{
		spike->Set(Relay::Value::kOff);
	}


}

void Launcher:: Act(){
printf("Linear Act\n\n");
lAct->Set(-Buttons->GetRawAxis(1));
}


void Launcher::TeleOp(){

	fire=JS->GetRawButton(2);

	Feeder();
	Act();



	if(fire && Buttons->GetRawButton(1)){
		launchWheel->Set(-1.0);
		Stopwatch->Start();
		printf("Hey the wheels are running\n");
		printf("%f\n\n", Stopwatch->Get());

		if(Stopwatch->Get() > 1){
		puncher->Set(true);
		printf("Hey the puncher activated");

		}
		Wait(0.001);
	}else if(fire && !(Buttons->GetRawButton(1))) {
				launchWheel->Set(-0.65);
				Stopwatch->Start();

				if(Stopwatch->Get() > 1){
				puncher->Set(true);
				printf("Hey the puncher activated");

				}
				Wait(0.001);
	}else{
		Stopwatch->Reset();
        puncher->Set(false);
        Wait(0.001);
		launchWheel->Set(0);
        Wait(0.001);
	}


}



Launcher::~Launcher(){

}


