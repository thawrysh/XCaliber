/*
 * Camera.cpp
 *
 *  Created on: Mar 15, 2016
 *      Author: Developer
 */
#include "WPILib.h"
#include "Camera.hpp"
#include "camera2.h"  //comment for standard

//Image *frame;


Camera::Camera(){
	  JS = new Joystick(0);

	 CameraServer2::GetInstance()->StartAutomaticCapture("cam0");
     CameraServer2::GetInstance()->SetQuality(50);
     printf("Camera starting...");
	  //frame = NIVision->imageCreateImage(NIVision.ImageType.IMAGE_RGB, 0);
}

void Camera::TeleOp(){
	if(JS->GetRawButton(6) && ! btn_down){
		btn_down = TRUE;
		printf("Switch cam\n");
		if (front) {
			CameraServer2::GetInstance()->StartAutomaticCapture("cam0");
		} else {
			CameraServer2::GetInstance()->StartAutomaticCapture("cam1");
		}
		front = !front;
		//CameraServer2::GetInstance()->SetQuality(50);
	} else if (!JS->GetRawButton(6)) {
		btn_down = FALSE;
	}

}

