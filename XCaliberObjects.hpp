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


Drive* myDrive;
Launcher* myLauncher;
Compressor* c;

inline void initialize(){
	myDrive = new Drive();
	myLauncher=new Launcher();
	c = new Compressor();
	printf("What's up");

}



#endif /* SRC_XCALIBEROBJECTS_HPP_ */
