' ########################################################################################
' Microsoft Windows
' File: stireg.inc
' Contents: This module contains the STI registry entries
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%STIREG_INC = 1

'//
'// Registry keys and values
'//

$$REGSTR_VAL_TYPE_W            = "Type"$$
$$REGSTR_VAL_VENDOR_NAME_W     = "Vendor"$$
$$REGSTR_VAL_DEVICETYPE_W      = "DeviceType"$$
$$REGSTR_VAL_DEVICESUBTYPE_W   = "DeviceSubType"$$
$$REGSTR_VAL_DEV_NAME_W        = "DeviceName"$$
$$REGSTR_VAL_DRIVER_DESC_W     = "DriverDesc"$$
$$REGSTR_VAL_FRIENDLY_NAME_W   = "FriendlyName"$$
$$REGSTR_VAL_GENERIC_CAPS_W    = "Capabilities"$$
$$REGSTR_VAL_HARDWARE_W        = "HardwareConfig"$$
$REGSTR_VAL_HARDWARE           = "HardwareConfig"
$$REGSTR_VAL_DEVICE_NAME_W     = "DriverDesc"$$
$$REGSTR_VAL_DATA_W            = "DeviceData"$$
$$REGSTR_VAL_GUID_W            = "GUID"$$
$REGSTR_VAL_GUID               = "GUID"
$$REGSTR_VAL_LAUNCH_APPS_W     = "LaunchApplications"$$
$REGSTR_VAL_LAUNCH_APPS        = "LaunchApplications"
$$REGSTR_VAL_LAUNCHABLE_W      = "Launchable"$$
$REGSTR_VAL_LAUNCHABLE         = "Launchable"
'#if (_WIN32_WINNT >= 0x0600) // Windows Vista and later
$$REGSTR_VAL_SHUTDOWNDELAY_W   = "ShutdownIfUnusedDelay"$$
$REGSTR_VAL_SHUTDOWNDELAY      = "ShutdownIfUnusedDelay"
'#endif //#if (_WIN32_WINNT >= 0x0600)

'#if (_WIN32_WINNT >= 0x0501) // Windows XP and later
'//
'// CustomDeviceProperty names and values
'//
$$IS_DIGITAL_CAMERA_STR        = "IsDigitalCamera"$$
%IS_DIGITAL_CAMERA_VAL         = 1
$$SUPPORTS_MSCPLUS_STR         = "SupportsMSCPlus"$$
%SUPPORTS_MSCPLUS_VAL          = 1
'#endif //#if (_WIN32_WINNT >= 0x0501)

'//
'// Device instance value names
'//
$$STI_DEVICE_VALUE_TWAIN_NAME              = "TwainDS"$$
$$STI_DEVICE_VALUE_ISIS_NAME               = "ISISDriverName"$$
$$STI_DEVICE_VALUE_ICM_PROFILE             = "ICMProfile"$$
$$STI_DEVICE_VALUE_DEFAULT_LAUNCHAPP       = "DefaultLaunchApp"$$
$$STI_DEVICE_VALUE_TIMEOUT                 = "PollTimeout"$$
$$STI_DEVICE_VALUE_DISABLE_NOTIFICATIONS   = "DisableNotifications"$$
$$REGSTR_VAL_BAUDRATE                      = "BaudRate"$$

$STI_DEVICE_VALUE_TWAIN_NAME_A             = "TwainDS"
$STI_DEVICE_VALUE_ISIS_NAME_A              = "ISISDriverName"
$STI_DEVICE_VALUE_ICM_PROFILE_A            = "ICMProfile"
$STI_DEVICE_VALUE_DEFAULT_LAUNCHAPP_A      = "DefaultLaunchApp"
$STI_DEVICE_VALUE_TIMEOUT_A                = "PollTimeout"
$STI_DEVICE_VALUE_DISABLE_NOTIFICATIONS_A  = "DisableNotifications"
$REGSTR_VAL_BAUDRATE_A                     = "BaudRate"
