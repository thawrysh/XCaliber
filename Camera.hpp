#include "WPILib.h"

#ifndef SRC_CAMERA_HPP_
#define SRC_CAMERA_HPP_

class Camera{
private:

	Joystick*JS;
	int btn_down = FALSE;
	int front = FALSE;

public:
	Camera();
	void TeleOp();

};



#endif /* SRC_CAMERA_HPP_ */
