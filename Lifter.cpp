/*
 * Lifter.cpp
 *
 *  Created on: Feb 28, 2016
 *      Author: Developer
 */
#include "Lifter.hpp"
#include "WPILib.h"
#define upper .75
#define upperSlow .73
#define lower .22

Lifter::Lifter(){

	masterLifter = new CANTalon(21);
	masterLifter->Set(0);
	followerOne = new CANTalon(20);
	followerOne->Set(0);
	followerTwo = new CANTalon(22);
	followerTwo->Set(0);

	followerOne->SetControlMode(CANSpeedController::kFollower);
	followerOne->Set(21);
	followerTwo->SetControlMode(CANSpeedController::kFollower);
	followerTwo->Set(21);

	masterLifter->SetFeedbackDevice(CANTalon::AnalogPot); //analog pot
	masterLifter->ConfigPotentiometerTurns(10);

	masterLifter->ConfigLimitMode(CANSpeedController::kLimitMode_SoftPositionLimits);
	masterLifter->ConfigForwardLimit(900);
	masterLifter->ConfigReverseLimit(100);
	Buttons = new Joystick(1);
//	Limits = new AnalogPotentiometer(1); //second number full range with base (0 degrees) at lowest point
	LifterStopWatch = new Timer();

	//masterLifter->Set(1);


}

void Lifter::TeleOp(){

	masterLifter->Set(-1);
//	potOut =
	Wait(0.001);

//
//	printf("Voltage?: %f\n\n", Limits->Get());
//	printf("Potentiometer Reading: %f", potOut);


//	SmartDashboard::PutString("DB/String 0", "Auto Mode 1");
//
//
//	if(Buttons->GetRawButton(6)){
//		if(Limits->Get() > lower && Limits->Get() < upperSlow){
//			extend->Set(-(Buttons->GetRawAxis(1)));
//		}
//
//		if(Limits->Get() > upperSlow && Limits->Get() < upper){
//			extend->Set(-(Buttons->GetRawAxis(1)*0.25));
//		}
//
//		if(Limits->Get() > upper && Buttons->GetRawAxis(1) > 0){
//			extend->Set(-(Buttons->GetRawAxis(1)));
//		}
//
//		if(Limits->Get() < lower && Buttons->GetRawAxis(1) < 0){
//			extend->Set(-(Buttons->GetRawAxis(1)));
//		}
//
//
//		if(Buttons->GetRawAxis(1) == 0){
//			extend->Set(0);
//		}
//
//		//if(Limits->Get() < upperSlow && Limits->Get() > lower){
//			//extend->Set(-(Buttons->GetRawAxis(1)));
//		//}else if(Limits->Get() < upper && Limits->Get() > lower){
//			/*LifterStopWatch->Reset();
//			LifterStopWatch->Start();
//			if(LifterStopWatch->Get() < 0.5)
//			{
//				prop->Set(0.5);
//			}*/
//			//extend->Set(-(Buttons->GetRawAxis(1)*0.25));
//		//}else if(Limits->Get() > upper && Buttons->GetRawAxis(1) > 0){
//
//			//extend->Set(-(Buttons->GetRawAxis(1)));
//	}
//		else {
//			extend->Set(Buttons->GetRawAxis(1)*0);
//		}
//
//		if(Buttons->GetRawButton(7)){
//				prop->Set(1);
//			}else if(Buttons->GetRawButton(8)){
//				prop->Set(-1);
//			}else{
//				prop->Set(0);
//			}
	}

