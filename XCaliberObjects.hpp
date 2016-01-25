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

Drive* myDrive;

inline void initialize(){
	myDrive = new Drive();
}



#endif /* SRC_XCALIBEROBJECTS_HPP_ */
