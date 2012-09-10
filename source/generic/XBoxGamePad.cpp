/*
Generic implementation of the XBoxGamePad extension.
This file should perform any platform-indepedentent functionality
(e.g. error checking) before calling platform-dependent implementations.
*/

/*
 * NOTE: This file was originally written by the extension builder, but will not
 * be overwritten (unless --force is specified) and is intended to be modified.
 */


#include "XBoxGamePad_internal.h"
s3eResult XBoxGamePadInit()
{
    //Add any generic initialisation code here
    return XBoxGamePadInit_platform();
}

void XBoxGamePadTerminate()
{
    //Add any generic termination code here
    XBoxGamePadTerminate_platform();
}

s3eResult XBoxPadInit()
{
	return XBoxPadInit_platform();
}

s3eResult XBoxPadUpdate()
{
	return XBoxPadUpdate_platform();
}

bool XBoxPadIsConnected(int controller)
{
	return XBoxPadIsConnected_platform(controller);
}

bool XBoxPadVibrate(int controller, int leftVal, int rightVal)
{
	return XBoxPadVibrate_platform(controller, leftVal, rightVal);
}

double XBoxPadXAxisL(int controller)
{
	return XBoxPadXAxisL_platform(controller);
}

double XBoxPadYAxisL(int controller)
{
	return XBoxPadYAxisL_platform(controller);
}

double XBoxPadXAxisR(int controller)
{
	return XBoxPadXAxisR_platform(controller);
}

double XBoxPadYAxisR(int controller)
{
	return XBoxPadYAxisR_platform(controller);
}

double XBoxPadXDPad(int controller)
{
	return XBoxPadXDPad_platform(controller);
}

double XBoxPadYDPad(int controller)
{
	return XBoxPadYDPad_platform(controller);
}

bool XBoxPadLeftThumb(int controller)
{
	return XBoxPadLeftThumb_platform(controller);
}

bool XBoxPadRightThumb(int controller)
{
	return XBoxPadRightThumb_platform(controller);
}

bool XBoxPadAButton(int controller)
{
	return XBoxPadAButton_platform(controller);
}

bool XBoxPadBButton(int controller)
{
	return XBoxPadBButton_platform(controller);
}

bool XBoxPadXButton(int controller)
{
	return XBoxPadXButton_platform(controller);
}

bool XBoxPadYButton(int controller)
{
	return XBoxPadYButton_platform(controller);
}

bool XBoxPadLeftShoulder(int controller)
{
	return XBoxPadLeftShoulder_platform(controller);
}

bool XBoxPadRightShoulder(int controller)
{
	return XBoxPadRightShoulder_platform(controller);
}

bool XBoxPadStartButton(int controller)
{
	return XBoxPadStartButton_platform(controller);
}

bool XBoxPadBackButton(int controller)
{
	return XBoxPadBackButton_platform(controller);
}

double XBoxPadLeftTrigger(int controller)
{
	return XBoxPadLeftTrigger_platform(controller);
}

double XBoxPadRightTrigger(int controller)
{
	return XBoxPadRightTrigger_platform(controller);
}
