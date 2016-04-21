#include "WPILib.h"
#include "Drive.hpp"
#include "XCaliberShared.hpp"


#define diameter 4
#define pi 3.14159265359

//extern bool AutoCondition;
//extern double overArching;

Drive::Drive(){
	JS = new Joystick(0);
	Buttons = new Joystick(1);

	lowBar = new Solenoid(1);
	LeftFront = new CANTalon(2);
	LeftRear = new CANTalon(4);
	RightFront = new CANTalon(1);
	RightRear = new CANTalon(3);
	GearShifter = new Solenoid(0);

	SpeedBase=new RobotDrive(LeftFront, LeftRear, RightFront, RightRear);

	SpeedBase -> SetInvertedMotor(RobotDrive::kFrontLeftMotor, true);
	SpeedBase -> SetInvertedMotor(RobotDrive::kFrontRightMotor, true);
	SpeedBase -> SetInvertedMotor(RobotDrive::kRearLeftMotor, true);
	SpeedBase -> SetInvertedMotor(RobotDrive::kRearRightMotor, true);

	//navX = new AnalogGyro(0);
	//navX ->Calibrate();

    StopWatch = new Timer;

    distance=0;
    Shift = false;
    rightEnc = new Encoder(0, 1, false, Encoder::EncodingType::k4X);
    leftEnc = new Encoder(2, 3, false, Encoder::EncodingType::k4X);
	//rightEnc->SetMaxPeriod(0.1);
	rightEnc ->SetMinRate(10);
	circum = diameter * pi;
	rightEnc ->SetDistancePerPulse(circum / 256);

	//leftEnc->SetMaxPeriod(0.1);
	leftEnc ->SetMinRate(10);
	leftEnc ->SetDistancePerPulse(circum / 256);

}

void Drive::Auto(){

	switch(AutoMode){
		case 1:
			//while(abs(rightEnc->Get()) <= 256){
			//rightEnc->Reset();
			//printf("OVERARCHING: %f\n\n", overArching);
			//SpeedBase->SetLeftRightMotorOutputs(0.3,0.3);
				if(overArching < 3.0){
				LeftFront->Set(-1.0);
					LeftRear->Set(-1.0);
					RightFront->Set(1.0);
					RightRear->Set(1.0);
				}else if(overArching >= 3.0){

					LeftFront->Set(0);
					LeftRear->Set(0);
					RightFront->Set(0);
					RightRear->Set(0);
					//AutoCondition=true;
				}
				//using CANTalons allowed for aspeed control signature allowing me to use Set() still with Cantalons
				//SpeedBase->SetLeftRightMotorOutputs(0.8,0.85);
				//distance = rightEnc -> Count();
				//printf("distance: %f\n", rightEnc->Get());

			//}
			//SpeedBase->SetLeftRightMotorOutputs(0,0);
			//Wait(100);

			break;
		case 2:
			if(overArching < 2.5){
				LeftFront->Set(1.0);
				LeftRear->Set(1.0);
				RightFront->Set(-1.0);
				RightRear->Set(-1.0);
				Wait(0.001);
			}else if(overArching >= 2.5 && overArching <9){
				LeftFront->Set(0);
				LeftRear->Set(0);
				RightFront->Set(0);
				RightRear->Set(0);
				Wait(0.0001);
				AutoCondition=true;
			}else if(overArching >= 9 && overArching <= 11){
				LeftFront->Set(-1);
				LeftRear->Set(-1);
				RightFront->Set(1);
				RightRear->Set(1);
				Wait(0.0001);
				AutoCondition=false;
			}else {
				LeftFront->Set(0);
				LeftRear->Set(0);
				RightFront->Set(0);
				RightRear->Set(0);
				Wait(0.0001);
			}
			break;
		case 3:
			if(overArching < 3.0){

				LeftFront->Set(1.0);
				LeftRear->Set(1.0);
				RightFront->Set(-1.0);
				RightRear->Set(-1.0);

			}else if(overArching >= 3.0){

				LeftFront->Set(0);
				LeftRear->Set(0);
				RightFront->Set(0);
				RightRear->Set(0);
							}
		break;
		default:
			 printf("No Autonomous Chosen");
			 break;
	}

}


/*void Drive::AutoPeriodic(){
	printf("%i\n", rightEnc->GetRaw());
	if(abs(rightEnc->GetRaw()) > 256){
		//SpeedBase->SetLeftRightMotorOutputs(0,0);
		LeftFront->Set(0);
		LeftRear->Set(0);
		RightFront->Set(0);
		RightRear->Set(0);
	}
}*/

void Drive::ObstacleOne(){
	if(Buttons->GetRawButton(4)){
		lowBar->Set(true);
	}

}

void Drive::TeleOp(){

	SpeedBase ->ArcadeDrive(JS, true);


Wait(0.003);

Shift = JS->GetRawButton(1);	// Shift - safety button

 if (Shift) {
 		// Engage pnuematic shifter
 		GearShifter->Set(true);
		printf("shift true\n");
	}
	else {
		// Disengage pnuematic shifter
		GearShifter->Set(false);
	}

}

Drive::~Drive(){

}
