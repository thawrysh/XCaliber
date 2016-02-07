#include "WPILib.h"
#include "XCaliberShared.hpp"
#include "XCaliber.hpp"
#include "XCaliberObjects.hpp"

int AutoMode;

// static void BeginDriveThread(){

//}

//XCaliber::XCaliber(){


//}

void XCaliber::RobotInit(){
	printf("What's up");

	AutoMode=0;
		initialize();
		c->Start();

}

void XCaliber::AutonomousInit(){

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
	myDrive->Auto();


}

void XCaliber::AutonomousPeriodic(){

}

void XCaliber::TeleopInit(){
	//define some values here; maybe reset encoders
}

void XCaliber::TeleopPeriodic(){
	myDrive->TeleOp();
	myLauncher->TeleOp();
}

//XCaliber::~XCaliber(){
//}

