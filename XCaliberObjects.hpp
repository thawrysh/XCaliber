/*
 * XCaliberObjects.hpp
 *
 *  Created on: Jan 24, 2016
 *      Author: Cameron
 */

#ifndef SRC_XCALIBEROBJECTS_HPP_
#define SRC_XCALIBEROBJECTS_HPP_

#include "WPILib.h"
#include "Drive.hpp"
#include "Launcher.hpp"
#include "Lifter.hpp"
#include "Camera.hpp"

Drive* myDrive;
Launcher* myLauncher;
Lifter* myLifter;
Camera* myCamera;
Compressor* c;

inline void initialize(){
	myDrive = new Drive();
	myLauncher=new Launcher();
	myLifter = new Lifter();
	myCamera = new Camera();
	c = new Compressor();
}

#endif /* SRC_XCALIBEROBJECTS_HPP_ */
