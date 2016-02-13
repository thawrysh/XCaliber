#include "WPILib.h"
#include "Drive.hpp"
#include "XCaliberShared.hpp"


#define diameter 4
#define pi 3.14159265359

Drive::Drive(){

	LeftFront = new CANTalon(1);
	LeftRear = new CANTalon(3);
	RightFront = new CANTalon(2);
	RightRear = new CANTalon(4);
	GearShifter = new Solenoid(0);

	SpeedBase=new RobotDrive(LeftFront, LeftRear, RightFront, RightRear);
	SpeedBase -> SetInvertedMotor(RobotDrive::kFrontLeftMotor, true);
	SpeedBase -> SetInvertedMotor(RobotDrive::kFrontRightMotor, true);
	SpeedBase -> SetInvertedMotor(RobotDrive::kRearLeftMotor, true);
	SpeedBase -> SetInvertedMotor(RobotDrive::kRearRightMotor, true);





   JS = new Joystick(0);

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
	StopWatch->Start();

	switch(AutoMode){
		case 1:
			//while(abs(rightEnc->Get()) <= 256){
			rightEnc->Reset();
			//SpeedBase->SetLeftRightMotorOutputs(0.3,0.3);
			LeftFront->Set(0.3);
					LeftRear->Set(0.3);
					RightFront->Set(0.3);
					RightRear->Set(0.3);
				//using CANTalons allowed for aspeed control signature allowing me to use Set() still with Cantalons
				//SpeedBase->SetLeftRightMotorOutputs(0.8,0.85);
				//distance = rightEnc -> Count();
				//printf("distance: %f\n", rightEnc->Get());

			//}
			//SpeedBase->SetLeftRightMotorOutputs(0,0);
			//Wait(100);

			break;
		case 2:
			Wait(15);
			break;
		case 3:
			Wait(15);
			break;
		case 4:
			Wait(15);
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

void Drive::TeleOp(){
//SpeedBase->SetSafetyEnabled(true);
SpeedBase ->ArcadeDrive(JS, true);
Wait(0.005);

Shift = JS->GetRawButton(1);	// Shift - safety button

 if (Shift) {
 		// Engage pnuematic shifter
 		GearShifter->Set(true);
		printf("shift true\n");
	}
	else {
		// Disengage pnuematic shifter
	//	printf("shift false S1.7\n");
		GearShifter->Set(false);
	}
 	 	 	// distance = rightEnc->GetDistance();
// 			printf("distance: %f\n", distance);


}

Drive::~Drive(){
}
