/*
 * windows-specific implementation of the XBoxGamePad extension.
 * Add any platform-specific functionality here.
 */
/*
 * NOTE: This file was originally written by the extension builder, but will not
 * be overwritten (unless --force is specified) and is intended to be modified.
 */
#include "XBoxGamePad_internal.h"
#include <windows.h>
#include <XInput.h>
#include "s3eEdk.h"
#include <stdio.h>

//#pragma comment(lib, "XInput.lib")

XINPUT_STATE _controllerState[4];
bool _isConnected[4] = {false,false,false,false};

s3eResult XBoxGamePadInit_platform()
{
    // Add any platform-specific initialisation code here
    return S3E_RESULT_SUCCESS;
}

void XBoxGamePadTerminate_platform()
{
    // Add any platform-specific termination code here
}

s3eResult XBoxPadInit_platform()
{
    for (int n=0 ; n<4; n++ )
    {
        ZeroMemory(&_controllerState[n], sizeof(XINPUT_STATE));
        _isConnected[n] = false;
    }
    return S3E_RESULT_SUCCESS;
}

s3eResult XBoxPadUpdate_platform()
{
    for (int n=0 ; n<4; n++ )
   {
       ZeroMemory(&_controllerState[n], sizeof(XINPUT_STATE));
        DWORD result = XInputGetState(n, &_controllerState[n]);
        if(result == ERROR_SUCCESS)
        {
            _isConnected[n] = true;
        }
        else
        {
            _isConnected[n] = false;
        }
    }
    return S3E_RESULT_SUCCESS;
}

bool XBoxPadIsConnected_platform(int controller)
{
    return _isConnected[controller];
}

bool XBoxPadVibrate_platform(int controller, int leftVal, int rightVal)
{
    if(!_isConnected[controller])
        return false;
    XINPUT_VIBRATION Vibration;
    ZeroMemory(&Vibration, sizeof(XINPUT_VIBRATION));
    Vibration.wLeftMotorSpeed = leftVal;
    Vibration.wRightMotorSpeed = rightVal;
    XInputSetState(controller, &Vibration);
    return true;
}

double XBoxPadXAxisL_platform(int controller)
{
    if(!_isConnected[controller])
        return 0;
    int thumb = _controllerState[controller].Gamepad.sThumbLX;
    if(abs(thumb) < XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE)
        return 0;
    double normalized = thumb/32768.0;
    return normalized;
}

double XBoxPadYAxisL_platform(int controller)
{
    if(!_isConnected[controller])
        return 0;
    int thumb = _controllerState[controller].Gamepad.sThumbLX;
    if(abs(thumb) < XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE)
        return 0;
    double normalized = thumb/32768.0;
    return normalized;
}

double XBoxPadXAxisR_platform(int controller)
{
    if(!_isConnected[controller])
        return 0;
    int thumb = _controllerState[controller].Gamepad.sThumbRX;
    if(abs(thumb) < XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE)
        return 0;
    double normalized = thumb/32768.0;
    return normalized;
}

double XBoxPadYAxisR_platform(int controller)
{
    if(!_isConnected[controller])
        return 0;
    int thumb = _controllerState[controller].Gamepad.sThumbRY;
    if(abs(thumb) < XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE)
        return 0;
    double normalized = thumb/32768.0;
    return normalized;
}

double XBoxPadXDPad_platform(int controller)
{
    if(_controllerState[controller].Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_LEFT)
        return -1.0;
    if(_controllerState[controller].Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_RIGHT)
        return 1.0;
    return 0.0;
}

double XBoxPadYDPad_platform(int controller)
{
    if(_controllerState[controller].Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_UP)
        return 1.0;
    if(_controllerState[controller].Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_DOWN)
        return -1.0;
    return 0.0;
}

bool XBoxPadAButton_platform(int controller)
{
    if(!_isConnected[controller])
        return false;
    return (_controllerState[controller].Gamepad.wButtons & XINPUT_GAMEPAD_A);
}

bool XBoxPadBButton_platform(int controller)
{
    if(!_isConnected[controller])
        return false;
    return (_controllerState[controller].Gamepad.wButtons & XINPUT_GAMEPAD_B);
}

bool XBoxPadXButton_platform(int controller)
{
    if(!_isConnected[controller])
        return false;
    return (_controllerState[controller].Gamepad.wButtons & XINPUT_GAMEPAD_X);
}

bool XBoxPadYButton_platform(int controller)
{
    if(!_isConnected[controller])
        return 0;
    return (_controllerState[controller].Gamepad.wButtons & XINPUT_GAMEPAD_Y);
}

bool XBoxPadLeftShoulder_platform(int controller)
{
    if(!_isConnected[controller])
        return 0;
    return (_controllerState[controller].Gamepad.wButtons & XINPUT_GAMEPAD_LEFT_SHOULDER);
}

bool XBoxPadRightShoulder_platform(int controller)
{
    if(!_isConnected[controller])
        return 0;
    return (_controllerState[controller].Gamepad.wButtons & XINPUT_GAMEPAD_RIGHT_SHOULDER);
}

bool XBoxPadStartButton_platform(int controller)
{
    if(!_isConnected[controller])
        return 0;
    return (_controllerState[controller].Gamepad.wButtons & XINPUT_GAMEPAD_START);
}

bool XBoxPadBackButton_platform(int controller)
{
    if(!_isConnected[controller])
        return 0;
    return (_controllerState[controller].Gamepad.wButtons & XINPUT_GAMEPAD_BACK);
}

bool XBoxPadLeftThumb_platform(int controller)
{
    if(!_isConnected[controller])
        return 0;
    return (_controllerState[controller].Gamepad.wButtons & XINPUT_GAMEPAD_LEFT_THUMB);
}

bool XBoxPadRightThumb_platform(int controller)
{
    if(!_isConnected[controller])
        return 0;
    return (_controllerState[controller].Gamepad.wButtons & XINPUT_GAMEPAD_RIGHT_THUMB);
}

double XBoxPadRightTrigger_platform(int controller)
{
    if(!_isConnected[controller])
        return 0;
    return _controllerState[controller].Gamepad.bRightTrigger/255.0;
}

double XBoxPadLeftTrigger_platform(int controller)
{
    if(!_isConnected[controller])
        return 0;
    return _controllerState[controller].Gamepad.bLeftTrigger/255.0;
}
