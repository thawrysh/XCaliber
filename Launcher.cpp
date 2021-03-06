/*
 * Launcher.cpp
 *
 *  Created on: Feb 6, 2016
 *      Author: Developer
 */

#include "Launcher.hpp"
#include "XCaliberShared.hpp"
#define shortShot 13.91 //"14.81 is golden" -Shivang, incease by 2 degrees
#define longShot 11.56
#define autoShot 20
//old 22.8
//31.2
Launcher::Launcher() {

	fire=false;
	Buttons = new Joystick(1);
	JS= new Joystick(0);
	launchWheel = new CANTalon(5);
	lAct = new Talon(1);
	//old code  32.4 degrees
	//NEW BOT 30.7
	lFeedback = new AnalogPotentiometer(0, 30.7,0.0); //second number full range with base (0 degrees) at lowest point
	puncher = new Solenoid(2); //In competition it is 2
	spike = new Relay(0);
	launchStopwatch = new Timer();

}

void Launcher::Auto(){

	switch(AutoMode){
			case 2:
				if(overArching < 4){
					lAct->Set(1.0 * (lFeedback->Get() - autoShot));
					Wait(0.001);

				}else if(overArching >= 4 && overArching <5){

					launchWheel->Set(0.8);
					Wait(0.001);

				}else if(overArching >= 5 && overArching <8){

					puncher->Set(true);
					Wait(0.001);


				}else{
					launchWheel->Set(0);
					Wait(0.001);
					puncher->Set(false);

				}




				break;




	//while(lFeedback->Get() != autoShot){
		//lAct->Set(1.0 * (lFeedback->Get() - autoShot));
		//Wait(0.001);
					//printf("You have entered the second if=under\n\n");

		//if(overArching < 6){
		//printf("%f\n\n",overArching);
		//launchWheel->Set(0.85);
		//Wait(0.001);
//unique //speed

		//}else{

			//launchWheel->Set(0);
			//Wait(0.001);

		//}

		//if(overArching > 3 && overArching <=5 ){
			//puncher->Set(true);
			//Wait(0.001);
			//printf("Hey the puncher activated");

		//}else{
			//puncher->Set(false);
			//	}

	}
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
//}

void Launcher::Feeder(){
	if(Buttons->GetRawButton(9)){
		spike->Set(Relay::Value::kReverse);

	}else if(Buttons->GetRawButton(10)){
		spike->Set(Relay::Value::kForward);
	}else{
		spike->Set(Relay::Value::kOff);
	}


}

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

	}


}

double Launcher::LauncherSpeed(){
	if(Buttons->GetRawButton(1)){
			return 0.90;  // .95

		}else{
			return 0.75;
		}
}



void Launcher::TeleOp(){ //CHANGE FOR COMPETITION; REVERSE POLARITY OF MOTOR VALUES SO IT SHOOTS RIGHT WAY

	fire=JS->GetRawButton(2);

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

	}else if(Buttons->GetRawButton(3) && Buttons->GetRawButton(2)){
		puncher->Set(true);
		Wait(0.001);
	}else if(!fire && !Buttons->GetRawButton(2)){
		launchWheel->Set(0);
		Wait(0.001);
		puncher->Set(false);
		Wait(0.001);
		launchStopwatch->Reset();


	}


}



Launcher::~Launcher(){

}


