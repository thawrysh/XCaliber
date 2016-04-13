/*
 * Launcher.cpp
 *
 *  Created on: Feb 6, 2016
 *      Author: Developer
 */

#include "Launcher.hpp"
#include "XCaliberShared.hpp"
#define shortShot 24.81 //"14.81 is golden" -Shivang, incease by 2 degrees
#define longShot 11.56
//old 22.8
//31.2
Launcher::Launcher() {

	fire=false;
	Buttons = new Joystick(1);
	JS= new Joystick(0);
	launchWheel = new CANTalon(5);
<<<<<<< Updated upstream
	lAct = new Talon(0);
	puncher = new Solenoid(2);
	spike = new Relay(0);
	//position = new Solenoid(2);
	Stopwatch = new Timer();
=======
	lAct = new Talon(1);
	//old code  32.4 degrees
	//NEW BOT 30.7
	lFeedback = new AnalogPotentiometer(0, 30.7,0.0); //second number full range with base (0 degrees) at lowest point
	puncher = new Solenoid(3); //In competition it is 2
	spike = new Relay(0);
	launchStopwatch = new Timer();
>>>>>>> Stashed changes

}

void Launcher::Auto(){

	if(AutoCondition){
	spike->Set(Relay::Value::kForward);
	}



	//extern bool AutoCondition;
	/*		printf("AUTOCONDITIONAL: %d\n", AutoCondition);
			if(!AutoCondition){
				launchWheel->Set(-1);
			}else{
				printf("puncher true");
				puncher->Set(true);
				Wait(1);
				launchWheel->Set(0);
				puncher->Set(false);
		}
//				else{
//				launchWheel->Set(0);
//				puncher->Set(false);
//			}*/
}

void Launcher::Feeder(){
	if(Buttons->GetRawButton(9)){
		spike->Set(Relay::Value::kReverse);

	}else if(Buttons->GetRawButton(10)){
		spike->Set(Relay::Value::kForward);
	}else{
		spike->Set(Relay::Value::kOff);
	}


}

<<<<<<< Updated upstream
void Launcher::Feeder(){
	if(Buttons->GetRawButton(9)){
		spike->Set(Relay::Value::kForward);

	}else if(Buttons->GetRawButton(10)){
		spike->Set(Relay::Value::kReverse);
	}else{
		spike->Set(Relay::Value::kOff);
=======
void Launcher:: Act(){
	lAct->Set(Buttons->GetRawAxis(1));
	printf("Short Shot Value: %lf\n\n", lFeedback->Get()); //Use to find angle
	if(Buttons->GetRawButton(2)){
		launchWheel->Set(LauncherSpeed());
		if(Buttons->GetRawButton(4) && lFeedback->Get() != shortShot){
			lAct->Set(1.0 * (lFeedback->Get() - shortShot));
			//printf("You have entered the second if=under\n\n");
		}else if(!Buttons->GetRawButton(4) && lFeedback->Get() != longShot){
			lAct->Set(1.0 * (lFeedback->Get() - longShot));

		}else{
			lAct->Set(0);
			//printf("You have entered the else of the second\n\n");

		}

>>>>>>> Stashed changes
	}


}

<<<<<<< Updated upstream
void Launcher:: Act(){
printf("Linear Act\n\n");
lAct->Set(-Buttons->GetRawAxis(1));
}

=======
double Launcher::LauncherSpeed(){
	if(Buttons->GetRawButton(1)){
			return -1.0;  // .95
		}else{
			return -0.925;
		}
}


>>>>>>> Stashed changes

void Launcher::TeleOp(){ //CHANGE FOR COMPETITION; REVERSE POLARITY OF MOTOR VALUES SO IT SHOOTS RIGHT WAY

	fire=JS->GetRawButton(2);
<<<<<<< Updated upstream

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
=======

	if(!(Buttons->GetRawButton(6))){
		Act();
	}

	Feeder();

	//printf("L feedback: %f\n\n", lFeedback->Get()); //yellow & white are ground and 5V; blue is signal

	/*if(Buttons->GetRawButton(4)){

		if(Buttons->GetRawButton(1)){
			launchWheel->Set(1);
		}else{
			launchWheel->Set(0.85);
		}

		if(fire){
			puncher->Set(true);
		}else{
			puncher->Set(false);
		}


	}else*/

	 if(fire && !Buttons->GetRawButton(2)) {
		launchWheel->Set(LauncherSpeed());
		launchStopwatch->Start();

		if(launchStopwatch->Get() > 2){
			puncher->Set(true);
			printf("Hey the puncher activated");

		}
		Wait(0.001);
	    }else if(JS->GetRawButton(4)){

		launchWheel->Set(-0.9);
		Wait(0.001);

	}else if(fire && Buttons->GetRawButton(2)){
		puncher->Set(true);
		Wait(0.001);
	}else if(!fire && !Buttons->GetRawButton(2)){
		launchWheel->Set(0);
		Wait(0.001);
		puncher->Set(false);
		Wait(0.001);
		launchStopwatch->Reset();


>>>>>>> Stashed changes
	}


}



Launcher::~Launcher(){

}


