' ########################################################################################
' Microsoft Windows
' File: HighLevelMonitorConfigurationAPI.inc (Windows Vista)
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%HIGHLEVELMONITORCONFIGURATIONAPI_INC = 1

#INCLUDE ONCE "windows.inc"
#INCLUDE ONCE "PhysicalMonitorEnumerationAPI.inc"

'#pragma pack( push, 1  )

'/******************************************************************************
'    Flags
'******************************************************************************/
%MC_CAPS_NONE                                            = &H00000000???
%MC_CAPS_MONITOR_TECHNOLOGY_TYPE                         = &H00000001???
%MC_CAPS_BRIGHTNESS                                      = &H00000002???
%MC_CAPS_CONTRAST                                        = &H00000004???
%MC_CAPS_COLOR_TEMPERATURE                               = &H00000008???
%MC_CAPS_RED_GREEN_BLUE_GAIN                             = &H00000010???
%MC_CAPS_RED_GREEN_BLUE_DRIVE                            = &H00000020???
%MC_CAPS_DEGAUSS                                         = &H00000040???
%MC_CAPS_DISPLAY_AREA_POSITION                           = &H00000080???
%MC_CAPS_DISPLAY_AREA_SIZE                               = &H00000100???
%MC_CAPS_RESTORE_FACTORY_DEFAULTS                        = &H00000400???
%MC_CAPS_RESTORE_FACTORY_COLOR_DEFAULTS                  = &H00000800???
%MC_RESTORE_FACTORY_DEFAULTS_ENABLES_MONITOR_SETTINGS    = &H00001000???

%MC_SUPPORTED_COLOR_TEMPERATURE_NONE                     = &H00000000???
%MC_SUPPORTED_COLOR_TEMPERATURE_4000K                    = &H00000001???
%MC_SUPPORTED_COLOR_TEMPERATURE_5000K                    = &H00000002???
%MC_SUPPORTED_COLOR_TEMPERATURE_6500K                    = &H00000004???
%MC_SUPPORTED_COLOR_TEMPERATURE_7500K                    = &H00000008???
%MC_SUPPORTED_COLOR_TEMPERATURE_8200K                    = &H00000010???
%MC_SUPPORTED_COLOR_TEMPERATURE_9300K                    = &H00000020???
%MC_SUPPORTED_COLOR_TEMPERATURE_10000K                   = &H00000040???
%MC_SUPPORTED_COLOR_TEMPERATURE_11500K                   = &H00000080???

'/******************************************************************************
'    Enumerations
'******************************************************************************/

' enum _MC_DISPLAY_TECHNOLOGY_TYPE
%MC_SHADOW_MASK_CATHODE_RAY_TUBE    = 0
%MC_APERTURE_GRILL_CATHODE_RAY_TUBE = 1
%MC_THIN_FILM_TRANSISTOR            = 2
%MC_LIQUID_CRYSTAL_ON_SILICON       = 3
%MC_PLASMA                          = 4
%MC_ORGANIC_LIGHT_EMITTING_DIODE    = 5
%MC_ELECTROLUMINESCENT              = 6
%MC_MICROELECTROMECHANICAL          = 7
%MC_FIELD_EMISSION_DEVICE           = 8

' enum _MC_DRIVE_TYPE
%MC_RED_DRIVE   = 0
%MC_GREEN_DRIVE = 1
%MC_BLUE_DRIVE  = 2

' enum _MC_GAIN_TYPE
%MC_RED_GAIN   = 0
%MC_GREEN_GAIN = 1
%MC_BLUE_GAIN  = 2

' enum _MC_POSITION_TYPE
%MC_HORIZONTAL_POSITION = 0
%MC_VERTICAL_POSITION   = 1

' enum _MC_SIZE_TYPE
%MC_WIDTH  = 0
%MC_HEIGHT = 1

' enum _MC_COLOR_TEMPERATURE
%MC_COLOR_TEMPERATURE_UNKNOWN = 0
%MC_COLOR_TEMPERATURE_4000K   = 1
%MC_COLOR_TEMPERATURE_5000K   = 2
%MC_COLOR_TEMPERATURE_6500K   = 3
%MC_COLOR_TEMPERATURE_7500K   = 4
%MC_COLOR_TEMPERATURE_8200K   = 5
%MC_COLOR_TEMPERATURE_9300K   = 6
%MC_COLOR_TEMPERATURE_10000K  = 7
%MC_COLOR_TEMPERATURE_11500K  = 8

'/******************************************************************************
'    Monitor capability functions
'******************************************************************************/

DECLARE FUNCTION GetMonitorCapabilities IMPORT "dxva2.dll" ALIAS "GetMonitorCapabilities" ( _
   BYVAL hMonitor AS DWORD _                            ' __in  HANDLE hMonitor
 , BYREF pdwMonitorCapabilities AS DWORD _              ' __out LPDWORD pdwMonitorCapabilities
 , BYREF pdwSupportedColorTemperatures AS DWORD _       ' __out LPDWORD pdwSupportedColorTemperatures
 ) AS LONG                                              ' BOOL

'/******************************************************************************
'    Monitor setting persistence functions
'******************************************************************************/

DECLARE FUNCTION SaveCurrentMonitorSettings IMPORT "dxva2.dll" ALIAS "SaveCurrentMonitorSettings" ( _
   BYVAL hMonitor AS DWORD _                            ' __in HANDLE hMonitor
 ) AS LONG                                              ' BOOL

'/******************************************************************************
'    Monitor meta-data functions
'******************************************************************************/

DECLARE FUNCTION GetMonitorTechnologyType IMPORT "dxva2.dll" ALIAS "GetMonitorTechnologyType" ( _
   BYVAL hMonitor AS DWORD _                            ' __in HANDLE hMonitor
 , BYVAL pdtyDisplayTechnologyType AS LONG _            ' __in LPMC_DISPLAY_TECHNOLOGY_TYPE pdtyDisplayTechnologyType
 ) AS LONG                                              ' BOOL

'/******************************************************************************
'    Monitor image calibration functions
'******************************************************************************/

DECLARE FUNCTION GetMonitorBrightness IMPORT "dxva2.dll" ALIAS "GetMonitorBrightness" ( _
   BYVAL hMonitor AS DWORD _                            ' __in  HANDLE hMonitor
 , BYREF pdwMinimumBrightness AS DWORD _                ' __out LPDWORD pdwMinimumBrightness
 , BYREF pdwCurrentBrightness AS DWORD _                ' __out LPDWORD pdwCurrentBrightness
 , BYREF pdwMaximumBrightness AS DWORD _                ' __out LPDWORD pdwMaximumBrightness
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetMonitorContrast IMPORT "dxva2.dll" ALIAS "GetMonitorContrast" ( _
   BYVAL hMonitor AS DWORD _                            ' __in  HANDLE hMonitor
 , BYREF pdwMinimumContrast AS DWORD _                  ' __out LPDWORD pdwMinimumContrast
 , BYREF pdwCurrentContrast AS DWORD _                  ' __out LPDWORD pdwCurrentContrast
 , BYREF pdwMaximumContrast AS DWORD _                  ' __out LPDWORD pdwMaximumContrast
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetMonitorColorTemperature IMPORT "dxva2.dll" ALIAS "GetMonitorColorTemperature" ( _
   BYVAL hMonitor AS DWORD _                            ' __in  HANDLE hMonitor
 , BYREF pctCurrentColorTemperature AS DWORD _          ' __out LPMC_COLOR_TEMPERATURE pctCurrentColorTemperature
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetMonitorRedGreenOrBlueDrive IMPORT "dxva2.dll" ALIAS "GetMonitorRedGreenOrBlueDrive" ( _
   BYVAL hMonitor AS DWORD _                            ' __in  HANDLE hMonitor
 , BYREF pdwMinimumDrive AS DWORD _                     ' __out LPDWORD pdwMinimumDrive
 , BYREF pdwCurrentDrive AS DWORD _                     ' __out LPDWORD pdwCurrentDrive
 , BYREF pdwMaximumDrive AS DWORD _                     ' __out LPDWORD pdwMaximumDrive
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetMonitorRedGreenOrBlueGain IMPORT "dxva2.dll" ALIAS "GetMonitorRedGreenOrBlueGain" ( _
   BYVAL hMonitor AS DWORD _                            ' __in  HANDLE hMonitor
 , BYVAL gtGainType AS LONG _                           ' __in  MC_GAIN_TYPE gtGainType
 , BYREF pdwMinimumGain AS DWORD _                      ' __out LPDWORD pdwMinimumGain
 , BYREF pdwCurrentGain AS DWORD _                      ' __out LPDWORD pdwCurrentGain
 , BYREF pdwMaximumGain AS DWORD _                      ' __out LPDWORD pdwMaximumGain
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SetMonitorBrightness IMPORT "dxva2.dll" ALIAS "SetMonitorBrightness" ( _
   BYVAL hMonitor AS DWORD _                            ' __in HANDLE hMonitor
 , BYVAL dwNewBrightness AS DWORD _                     ' __in DWORD dwNewBrightness
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SetMonitorContrast IMPORT "dxva2.dll" ALIAS "SetMonitorContrast" ( _
   BYVAL hMonitor AS DWORD _                            ' __in HANDLE hMonitor
 , BYVAL dwNewContrast AS DWORD _                       ' __in DWORD dwNewContrast
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SetMonitorColorTemperature IMPORT "dxva2.dll" ALIAS "SetMonitorColorTemperature" ( _
   BYVAL hMonitor AS DWORD _                            ' __in HANDLE hMonitor
 , BYVAL ctCurrentColorTemperature AS LONG _            ' __in MC_COLOR_TEMPERATURE ctCurrentColorTemperature
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SetMonitorRedGreenOrBlueDrive IMPORT "dxva2.dll" ALIAS "SetMonitorRedGreenOrBlueDrive" ( _
   BYVAL hMonitor AS DWORD _                            ' __in HANDLE hMonitor
 , BYVAL dtDriveType AS LONG _                          ' __in MC_DRIVE_TYPE dtDriveType
 , BYVAL dwNewDrive AS DWORD _                          ' __in DWORD dwNewDrive
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SetMonitorRedGreenOrBlueGain IMPORT "dxva2.dll" ALIAS "SetMonitorRedGreenOrBlueGain" ( _
   BYVAL hMonitor AS DWORD _                            ' __in HANDLE hMonitor
 , BYVAL gtGainType AS LONG _                           ' __in MC_GAIN_TYPE gtGainType
 , BYVAL dwNewGain AS DWORD _                           ' __in DWORD dwNewGain
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION DegaussMonitor IMPORT "dxva2.dll" ALIAS "DegaussMonitor" ( _
   BYVAL hMonitor AS DWORD _                            ' __in HANDLE hMonitor
 ) AS LONG                                              ' BOOL

'/******************************************************************************
'    Monitor image size and position calibration functions
'******************************************************************************/

DECLARE FUNCTION GetMonitorDisplayAreaSize IMPORT "dxva2.dll" ALIAS "GetMonitorDisplayAreaSize" ( _
   BYVAL hMonitor AS DWORD _                            ' __in HANDLE hMonitor
 , BYVAL stSizeType AS LONG _                           ' __in MC_SIZE_TYPE stSizeType
 , BYREF pdwMinimumWidthOrHeight AS DWORD _             ' __out LPDWORD pdwMinimumWidthOrHeight
 , BYREF pdwCurrentWidthOrHeight AS DWORD _             ' __out LPDWORD pdwCurrentWidthOrHeight
 , BYREF pdwMaximumWidthOrHeight AS DWORD _             ' __out LPDWORD pdwMaximumWidthOrHeight
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetMonitorDisplayAreaPosition IMPORT "dxva2.dll" ALIAS "GetMonitorDisplayAreaPosition" ( _
   BYVAL hMonitor AS DWORD _                            ' __in HANDLE hMonitor
 , BYVAL ptPositionType AS LONG _                       ' __in MC_POSITION_TYPE ptPositionType
 , BYREF pdwMinimumPosition AS DWORD _                  ' __out LPDWORD pdwMinimumPosition
 , BYREF pdwCurrentPosition AS DWORD _                  ' __out LPDWORD pdwCurrentPosition
 , BYREF pdwMaximumPosition AS DWORD _                  ' __out LPDWORD pdwMaximumPosition
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SetMonitorDisplayAreaSize IMPORT "dxva2.dll" ALIAS "SetMonitorDisplayAreaSize" ( _
   BYVAL hMonitor AS DWORD _                            ' __in HANDLE hMonitor
 , BYVAL stSizeType AS LONG _                           ' __in MC_SIZE_TYPE stSizeType
 , BYVAL dwNewDisplayAreaWidthOrHeight AS DWORD _       ' __in DWORD dwNewDisplayAreaWidthOrHeight
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SetMonitorDisplayAreaPosition IMPORT "dxva2.dll" ALIAS "SetMonitorDisplayAreaPosition" ( _
   BYVAL hMonitor AS DWORD _                            ' __in HANDLE hMonitor
 , BYVAL ptPositionType AS LONG _                       ' __in MC_POSITION_TYPE ptPositionType
 , BYVAL dwNewPosition AS DWORD _                       ' __in DWORD dwNewPosition
 ) AS LONG                                              ' BOOL

'/******************************************************************************
'    Restore to defaults functions
'******************************************************************************/

DECLARE FUNCTION RestoreMonitorFactoryColorDefaults IMPORT "dxva2.dll" ALIAS "RestoreMonitorFactoryColorDefaults" ( _
   BYVAL hMonitor AS DWORD _                            ' __in HANDLE hMonitor
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION RestoreMonitorFactoryDefaults IMPORT "dxva2.dll" ALIAS "RestoreMonitorFactoryDefaults" ( _
   BYVAL hMonitor AS DWORD _                            ' __in HANDLE hMonitor
 ) AS LONG                                              ' BOOL

'#pragma pack( pop )
