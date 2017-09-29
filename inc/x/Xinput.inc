' ########################################################################################
' Microsoft Windows
' File: Xinput.inc
' Contents: XBOX controller APIs and constansts for the Windows platform.
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%XINPUT_INC = 1

#INCLUDE ONCE "windows.inc"

'// Current name of the DLL shipped in the same SDK as this header.
'// The name reflects the current version
'#define XINPUT_DLL_A  "xinput9_1_0.dll"
'#define XINPUT_DLL_W L"xinput9_1_0.dll"
'#ifdef UNICODE
'    #define XINPUT_DLL XINPUT_DLL_W
'#else
'    #define XINPUT_DLL XINPUT_DLL_A
'#endif

#IF NOT %DEF($XINPUT_DLL)
$XINPUT_DLL = "xinput9_1_0.dll"
#ENDIF

'//
'// Device types available in XINPUT_CAPABILITIES
'//
%XINPUT_DEVTYPE_GAMEPAD          = &H01?

'//
'// Device subtypes available in XINPUT_CAPABILITIES
'//
%XINPUT_DEVSUBTYPE_GAMEPAD       = &H01?

'//
'// Flags for XINPUT_CAPABILITIES
'//
%XINPUT_CAPS_VOICE_SUPPORTED     = &H0004??

'//
'// Constants for gamepad buttons
'//
%XINPUT_GAMEPAD_DPAD_UP          = &H0001??
%XINPUT_GAMEPAD_DPAD_DOWN        = &H0002??
%XINPUT_GAMEPAD_DPAD_LEFT        = &H0004??
%XINPUT_GAMEPAD_DPAD_RIGHT       = &H0008??
%XINPUT_GAMEPAD_START            = &H0010??
%XINPUT_GAMEPAD_BACK             = &H0020??
%XINPUT_GAMEPAD_LEFT_THUMB       = &H0040??
%XINPUT_GAMEPAD_RIGHT_THUMB      = &H0080??
%XINPUT_GAMEPAD_LEFT_SHOULDER    = &H0100??
%XINPUT_GAMEPAD_RIGHT_SHOULDER   = &H0200??
%XINPUT_GAMEPAD_A                = &H1000??
%XINPUT_GAMEPAD_B                = &H2000??
%XINPUT_GAMEPAD_X                = &H4000??
%XINPUT_GAMEPAD_Y                = &H8000??

'//
'// Gamepad thresholds
'//
%XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE  = 7849
%XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE = 8689
%XINPUT_GAMEPAD_TRIGGER_THRESHOLD    = 30

'//
'// Flags to pass to XInputGetCapabilities
'//
%XINPUT_FLAG_GAMEPAD             = &H00000001???


'//
'// Structures used by XInput APIs
'//
' // Size = 12 bytes
TYPE XINPUT_GAMEPAD BYTE
   wButtons      AS WORD      ' WORD
   bLeftTrigger  AS BYTE      ' BYTE
   bRightTrigger AS BYTE      ' BYTE
   sThumbLX      AS INTEGER   ' SHORT
   sThumbLY      AS INTEGER   ' SHORT
   sThumbRX      AS INTEGER   ' SHORT
   sThumbRY      AS INTEGER   ' SHORT
END TYPE

' // Size = 16 bytes
TYPE XINPUT_STATE DWORD
   dwPacketNumber AS DWORD   ' DWORD
   Gamepad        AS XINPUT_GAMEPAD
END TYPE

' // Size = 4 bytes
TYPE XINPUT_VIBRATION WORD
   wLeftMotorSpeed  AS WORD   ' WORD
   wRightMotorSpeed AS WORD   ' WORD
END TYPE

' // Size = 20 bytes
TYPE XINPUT_CAPABILITIES BYTE
   Type      AS BYTE   ' BYTE
   SubType   AS BYTE   ' BYTE
   Flags     AS WORD   ' WORD
   Gamepad   AS XINPUT_GAMEPAD
   Vibration AS XINPUT_VIBRATION
END TYPE

'//
'// XInput APIs
'//

DECLARE FUNCTION XInputGetState IMPORT $XINPUT_DLL ALIAS "XInputGetState" ( _
   BYVAL dwUserIndex AS DWORD _                         ' __in DWORD dwUserIndex // Index of the gamer associated with the device
 , BYREF pState AS XINPUT_STATE _                       ' __out XINPUT_STATE* pState // Receives the current state
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION XInputSetState IMPORT $XINPUT_DLL ALIAS "XInputSetState" ( _
   BYVAL dwUserIndex AS DWORD _                         ' __in DWORD dwUserIndex // Index of the gamer associated with the device
 , BYREF pVibration AS XINPUT_VIBRATION _               ' __in_out XINPUT_VIBRATION* pVibration // The vibration information to send to the controller
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION XInputGetCapabilities IMPORT $XINPUT_DLL ALIAS "XInputGetCapabilities" ( _
   BYVAL dwUserIndex AS DWORD _                         ' __in DWORD dwUserIndex // Index of the gamer associated with the device
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags // Input flags that identify the device type
 , BYREF pCapabilities AS XINPUT_CAPABILITIES _         ' __out XINPUT_CAPABILITIES* pCapabilities // Receives the capabilities
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION XInputGetDSoundAudioDeviceGuids IMPORT $XINPUT_DLL ALIAS "XInputGetDSoundAudioDeviceGuids" ( _
   BYVAL dwUserIndex AS DWORD _                         ' __in DWORD dwUserIndex // Index of the gamer associated with the device
 , BYREF pDSoundRenderGuid AS GUID _                    ' __out GUID* pDSoundRenderGuid  // DSound device ID for render
 , BYREF pDSoundCaptureGuid AS GUID _                   ' __out GUID* pDSoundCaptureGuid // DSound device ID for capture
 ) AS DWORD                                             ' DWORD
