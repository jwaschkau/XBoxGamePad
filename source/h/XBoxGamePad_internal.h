/*
 * Internal header for the XBoxGamePad extension.
 *
 * This file should be used for any common function definitions etc that need to
 * be shared between the platform-dependent and platform-indepdendent parts of
 * this extension.
 */

/*
 * NOTE: This file was originally written by the extension builder, but will not
 * be overwritten (unless --force is specified) and is intended to be modified.
 */


#ifndef XBOXGAMEPAD_INTERNAL_H
#define XBOXGAMEPAD_INTERNAL_H

#include "s3eTypes.h"
#include "XBoxGamePad.h"
#include "XBoxGamePad_autodefs.h"


/**
 * Initialise the extension.  This is called once then the extension is first
 * accessed by s3eregister.  If this function returns S3E_RESULT_ERROR the
 * extension will be reported as not-existing on the device.
 */
s3eResult XBoxGamePadInit();

/**
 * Platform-specific initialisation, implemented on each platform
 */
s3eResult XBoxGamePadInit_platform();

/**
 * Terminate the extension.  This is called once on shutdown, but only if the
 * extension was loader and Init() was successful.
 */
void XBoxGamePadTerminate();

/**
 * Platform-specific termination, implemented on each platform
 */
void XBoxGamePadTerminate_platform();
s3eResult XBoxPadInit_platform();

s3eResult XBoxPadUpdate_platform();

bool XBoxPadIsConnected_platform(int controller);

bool XBoxPadVibrate_platform(int controller, int leftVal, int rightVal);

double XBoxPadXAxisL_platform(int controller);

double XBoxPadYAxisL_platform(int controller);

double XBoxPadXAxisR_platform(int controller);

double XBoxPadYAxisR_platform(int controller);

double XBoxPadXDPad_platform(int controller);

double XBoxPadYDPad_platform(int controller);

bool XBoxPadLeftThumb_platform(int controller);

bool XBoxPadRightThumb_platform(int controller);

bool XBoxPadAButton_platform(int controller);

bool XBoxPadBButton_platform(int controller);

bool XBoxPadXButton_platform(int controller);

bool XBoxPadYButton_platform(int controller);

bool XBoxPadLeftShoulder_platform(int controller);

bool XBoxPadRightShoulder_platform(int controller);

bool XBoxPadStartButton_platform(int controller);

bool XBoxPadBackButton_platform(int controller);

double XBoxPadLeftTrigger_platform(int controller);

double XBoxPadRightTrigger_platform(int controller);


#endif /* !XBOXGAMEPAD_INTERNAL_H */