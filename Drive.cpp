#include "WPILib.h"
#include "Drive.hpp"
#include "XCaliberShared.hpp"

#define diameter 4
#define pi 3.14159265359

Drive::Drive(){

	RightRear = new CANTalon(2);
	RightFront = new CANTalon(4);
	LeftRear = new CANTalon(1);
	LeftFront = new CANTalon(3);

	SpeedBase=new RobotDrive(LeftFront, LeftRear, RightFront, RightRear);
    JS = new Joystick(0);

    StopWatch = new Timer;

    distance=0;
    rightEnc = new Encoder(0, 1, true, Encoder::EncodingType::k4X);
    leftEnc = new Encoder(2, 3, true, Encoder::EncodingType::k4X);
	//rightEnc->SetMaxPeriod(0.1);
	rightEnc ->SetMinRate(10);
	rightEnc ->SetDistancePerPulse(diameter * pi / 256);
	//leftEnc->SetMaxPeriod(0.1);
	leftEnc ->SetMinRate(10);
	leftEnc ->SetDistancePerPulse(diameter * pi / 256);

}

void Drive::Auto(){
StopWatch->Start();

switch(AutoMode){
	case 1:
	    while(distance <= 15){
	    	//using CANTalons allowed for aspeed control signature allowing me to use Set() still with Cantalons
	    	SpeedBase->SetLeftRightMotorOutputs(0.8,0.85);
            distance = rightEnc -> GetDistance();
	    }
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
while(StopWatch->Get() < 15.0){
	Wait(.001);

}

}

void Drive::TeleOp(){

SpeedBase ->ArcadeDrive(JS, true);


}

Drive::~Drive(){
}
