#include "WPILib.h"
#include "XCaliberShared.hpp"
#include "XCaliber.hpp"
#include "XCaliberObjects.hpp"

int AutoMode;

// static void BeginDriveThread(){

//}

XCaliber::XCaliber(){
	AutoMode=0;
	initialize();

}

void XCaliber::robotInit(){


}

void XCaliber::autonomousInit(){

	if(SmartDashboard::GetBoolean("DB/Button 1", false)) {
		  	   AutoMode = 1;
			   SmartDashboard::PutString("DB/String 0", "Auto Mode 1");
		}
		 else if(SmartDashboard::GetBoolean("DB/Button 2", false)) {
			   AutoMode = 2;
			   SmartDashboard::PutString("DB/String 0", "Auto Mode 2");
		 }
		 else if(SmartDashboard::GetBoolean("DB/Button 3", false)) {
		  	   AutoMode = 3;
			   SmartDashboard::PutString("DB/String 0", "Auto Mode 3");
		 }
		   else {
			   AutoMode = 0;
			   SmartDashboard::PutString("DB/String 0", "Auto Mode 0");
	       }

}

void XCaliber::autonomousPeriodic(){
	myDrive->Auto();
}

void XCaliber::teleopInt(){
	//define some values here; maybe reset encoders
}

void XCaliber::teleopPeriodic(){
	myDrive->TeleOp();
}

XCaliber::~XCaliber(){
}
