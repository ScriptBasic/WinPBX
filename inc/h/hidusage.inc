' ########################################################################################
' Microsoft Windows
' File: hidusage.inc
' Contents: Public Definitions of HID USAGES.
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%HIDUSAGE_INC = 1

'//
'// Usage Pages
'//

'typedef USHORT USAGE, *PUSAGE;

%HID_USAGE_PAGE_UNDEFINED     = &H00??
%HID_USAGE_PAGE_GENERIC       = &H01??
%HID_USAGE_PAGE_SIMULATION    = &H02??
%HID_USAGE_PAGE_VR            = &H03??
%HID_USAGE_PAGE_SPORT         = &H04??
%HID_USAGE_PAGE_GAME          = &H05??
%HID_USAGE_PAGE_KEYBOARD      = &H07??
%HID_USAGE_PAGE_LED           = &H08??
%HID_USAGE_PAGE_BUTTON        = &H09??
%HID_USAGE_PAGE_ORDINAL       = &H0A??
%HID_USAGE_PAGE_TELEPHONY     = &H0B??
%HID_USAGE_PAGE_CONSUMER      = &H0C??
%HID_USAGE_PAGE_DIGITIZER     = &H0D??
%HID_USAGE_PAGE_UNICODE       = &H10??
%HID_USAGE_PAGE_ALPHANUMERIC  = &H14??

'//
'// Microsoft Vendor Specific Usage Pages
'//
%HID_USAGE_PAGE_MICROSOFT_BLUETOOTH_HANDSFREE = &HFFF3??   ' ((USAGE) 0xFFF3)

'//
'// Usages from Generic Desktop Page (0x01)
'//

%HID_USAGE_GENERIC_POINTER      = &H01??
%HID_USAGE_GENERIC_MOUSE        = &H02??
%HID_USAGE_GENERIC_JOYSTICK     = &H04??
%HID_USAGE_GENERIC_GAMEPAD      = &H05??
%HID_USAGE_GENERIC_KEYBOARD     = &H06??
%HID_USAGE_GENERIC_KEYPAD       = &H07??
%HID_USAGE_GENERIC_SYSTEM_CTL   = &H80??

%HID_USAGE_GENERIC_X                        = &H30??
%HID_USAGE_GENERIC_Y                        = &H31??
%HID_USAGE_GENERIC_Z                        = &H32??
%HID_USAGE_GENERIC_RX                       = &H33??
%HID_USAGE_GENERIC_RY                       = &H34??
%HID_USAGE_GENERIC_RZ                       = &H35??
%HID_USAGE_GENERIC_SLIDER                   = &H36??
%HID_USAGE_GENERIC_DIAL                     = &H37??
%HID_USAGE_GENERIC_WHEEL                    = &H38??
%HID_USAGE_GENERIC_HATSWITCH                = &H39??
%HID_USAGE_GENERIC_COUNTED_BUFFER           = &H3A??
%HID_USAGE_GENERIC_BYTE_COUNT               = &H3B??
%HID_USAGE_GENERIC_MOTION_WAKEUP            = &H3C??
%HID_USAGE_GENERIC_VX                       = &H40??
%HID_USAGE_GENERIC_VY                       = &H41??
%HID_USAGE_GENERIC_VZ                       = &H42??
%HID_USAGE_GENERIC_VBRX                     = &H43??
%HID_USAGE_GENERIC_VBRY                     = &H44??
%HID_USAGE_GENERIC_VBRZ                     = &H45??
%HID_USAGE_GENERIC_VNO                      = &H46??
%HID_USAGE_GENERIC_SYSCTL_POWER             = &H81??
%HID_USAGE_GENERIC_SYSCTL_SLEEP             = &H82??
%HID_USAGE_GENERIC_SYSCTL_WAKE              = &H83??
%HID_USAGE_GENERIC_SYSCTL_CONTEXT_MENU      = &H84??
%HID_USAGE_GENERIC_SYSCTL_MAIN_MENU         = &H85??
%HID_USAGE_GENERIC_SYSCTL_APP_MENU          = &H86??
%HID_USAGE_GENERIC_SYSCTL_HELP_MENU         = &H87??
%HID_USAGE_GENERIC_SYSCTL_MENU_EXIT         = &H88??
%HID_USAGE_GENERIC_SYSCTL_MENU_SELECT       = &H89??
%HID_USAGE_GENERIC_SYSCTL_MENU_RIGHT        = &H8A??
%HID_USAGE_GENERIC_SYSCTL_MENU_LEFT         = &H8B??
%HID_USAGE_GENERIC_SYSCTL_MENU_UP           = &H8C??
%HID_USAGE_GENERIC_SYSCTL_MENU_DOWN         = &H8D??

'//
'// Usages from Simulation Controls Page (0x02)
'//

%HID_USAGE_SIMULATION_RUDDER                = &HBA??
%HID_USAGE_SIMULATION_THROTTLE              = &HBB??

'//
'// Virtual Reality Controls Page (0x03)
'//


'//
'// Sport Controls Page (0x04)
'//


'//
'// Game Controls Page (0x05)
'//


'//
'// Keyboard/Keypad Page (0x07)
'//

'        // Error "keys"
%HID_USAGE_KEYBOARD_NOEVENT     = &H00??
%HID_USAGE_KEYBOARD_ROLLOVER    = &H01??
%HID_USAGE_KEYBOARD_POSTFAIL    = &H02??
%HID_USAGE_KEYBOARD_UNDEFINED   = &H03??

'        // Letters
%HID_USAGE_KEYBOARD_aA          = &H04??
%HID_USAGE_KEYBOARD_zZ          = &H1D??
'        // Numbers
%HID_USAGE_KEYBOARD_ONE         = &H1E??
%HID_USAGE_KEYBOARD_ZERO        = &H27??
'        // Modifier Keys
%HID_USAGE_KEYBOARD_LCTRL       = &HE0??
%HID_USAGE_KEYBOARD_LSHFT       = &HE1??
%HID_USAGE_KEYBOARD_LALT        = &HE2??
%HID_USAGE_KEYBOARD_LGUI        = &HE3??
%HID_USAGE_KEYBOARD_RCTRL       = &HE4??
%HID_USAGE_KEYBOARD_RSHFT       = &HE5??
%HID_USAGE_KEYBOARD_RALT        = &HE6??
%HID_USAGE_KEYBOARD_RGUI        = &HE7??
%HID_USAGE_KEYBOARD_SCROLL_LOCK = &H47??
%HID_USAGE_KEYBOARD_NUM_LOCK    = &H53??
%HID_USAGE_KEYBOARD_CAPS_LOCK   = &H39??
'        // Funtion keys
%HID_USAGE_KEYBOARD_F1          = &H3A??
%HID_USAGE_KEYBOARD_F12         = &H45??

%HID_USAGE_KEYBOARD_RETURN      = &H28??
%HID_USAGE_KEYBOARD_ESCAPE      = &H29??
%HID_USAGE_KEYBOARD_DELETE      = &H2A??

%HID_USAGE_KEYBOARD_PRINT_SCREEN = &H46??

'// and hundreds more...

'//
'// LED Page (0x08)
'//

%HID_USAGE_LED_NUM_LOCK               = &H01??
%HID_USAGE_LED_CAPS_LOCK              = &H02??
%HID_USAGE_LED_SCROLL_LOCK            = &H03??
%HID_USAGE_LED_COMPOSE                = &H04??
%HID_USAGE_LED_KANA                   = &H05??
%HID_USAGE_LED_POWER                  = &H06??
%HID_USAGE_LED_SHIFT                  = &H07??
%HID_USAGE_LED_DO_NOT_DISTURB         = &H08??
%HID_USAGE_LED_MUTE                   = &H09??
%HID_USAGE_LED_TONE_ENABLE            = &H0A??
%HID_USAGE_LED_HIGH_CUT_FILTER        = &H0B??
%HID_USAGE_LED_LOW_CUT_FILTER         = &H0C??
%HID_USAGE_LED_EQUALIZER_ENABLE       = &H0D??
%HID_USAGE_LED_SOUND_FIELD_ON         = &H0E??
%HID_USAGE_LED_SURROUND_FIELD_ON      = &H0F??
%HID_USAGE_LED_REPEAT                 = &H10??
%HID_USAGE_LED_STEREO                 = &H11??
%HID_USAGE_LED_SAMPLING_RATE_DETECT   = &H12??
%HID_USAGE_LED_SPINNING               = &H13??
%HID_USAGE_LED_CAV                    = &H14??
%HID_USAGE_LED_CLV                    = &H15??
%HID_USAGE_LED_RECORDING_FORMAT_DET   = &H16??
%HID_USAGE_LED_OFF_HOOK               = &H17??
%HID_USAGE_LED_RING                   = &H18??
%HID_USAGE_LED_MESSAGE_WAITING        = &H19??
%HID_USAGE_LED_DATA_MODE              = &H1A??
%HID_USAGE_LED_BATTERY_OPERATION      = &H1B??
%HID_USAGE_LED_BATTERY_OK             = &H1C??
%HID_USAGE_LED_BATTERY_LOW            = &H1D??
%HID_USAGE_LED_SPEAKER                = &H1E??
%HID_USAGE_LED_HEAD_SET               = &H1F??
%HID_USAGE_LED_HOLD                   = &H20??
%HID_USAGE_LED_MICROPHONE             = &H21??
%HID_USAGE_LED_COVERAGE               = &H22??
%HID_USAGE_LED_NIGHT_MODE             = &H23??
%HID_USAGE_LED_SEND_CALLS             = &H24??
%HID_USAGE_LED_CALL_PICKUP            = &H25??
%HID_USAGE_LED_CONFERENCE             = &H26??
%HID_USAGE_LED_STAND_BY               = &H27??
%HID_USAGE_LED_CAMERA_ON              = &H28??
%HID_USAGE_LED_CAMERA_OFF             = &H29??
%HID_USAGE_LED_ON_LINE                = &H2A??
%HID_USAGE_LED_OFF_LINE               = &H2B??
%HID_USAGE_LED_BUSY                   = &H2C??
%HID_USAGE_LED_READY                  = &H2D??
%HID_USAGE_LED_PAPER_OUT              = &H2E??
%HID_USAGE_LED_PAPER_JAM              = &H2F??
%HID_USAGE_LED_REMOTE                 = &H30??
%HID_USAGE_LED_FORWARD                = &H31??
%HID_USAGE_LED_REVERSE                = &H32??
%HID_USAGE_LED_STOP                   = &H33??
%HID_USAGE_LED_REWIND                 = &H34??
%HID_USAGE_LED_FAST_FORWARD           = &H35??
%HID_USAGE_LED_PLAY                   = &H36??
%HID_USAGE_LED_PAUSE                  = &H37??
%HID_USAGE_LED_RECORD                 = &H38??
%HID_USAGE_LED_ERROR                  = &H39??
%HID_USAGE_LED_SELECTED_INDICATOR     = &H3A??
%HID_USAGE_LED_IN_USE_INDICATOR       = &H3B??
%HID_USAGE_LED_MULTI_MODE_INDICATOR   = &H3C??
%HID_USAGE_LED_INDICATOR_ON           = &H3D??
%HID_USAGE_LED_INDICATOR_FLASH        = &H3E??
%HID_USAGE_LED_INDICATOR_SLOW_BLINK   = &H3F??
%HID_USAGE_LED_INDICATOR_FAST_BLINK   = &H40??
%HID_USAGE_LED_INDICATOR_OFF          = &H41??
%HID_USAGE_LED_FLASH_ON_TIME          = &H42??
%HID_USAGE_LED_SLOW_BLINK_ON_TIME     = &H43??
%HID_USAGE_LED_SLOW_BLINK_OFF_TIME    = &H44??
%HID_USAGE_LED_FAST_BLINK_ON_TIME     = &H45??
%HID_USAGE_LED_FAST_BLINK_OFF_TIME    = &H46??
%HID_USAGE_LED_INDICATOR_COLOR        = &H47??
%HID_USAGE_LED_RED                    = &H48??
%HID_USAGE_LED_GREEN                  = &H49??
%HID_USAGE_LED_AMBER                  = &H4A??
%HID_USAGE_LED_GENERIC_INDICATOR      = &H4B??

'//
'//  Button Page (0x09)
'//
'//  There is no need to label these usages.
'//


'//
'//  Ordinal Page (0x0A)
'//
'//  There is no need to label these usages.
'//


'//
'//  Telephony Device Page (0x0B)
'//

%HID_USAGE_TELEPHONY_PHONE                  = &H01??
%HID_USAGE_TELEPHONY_ANSWERING_MACHINE      = &H02??
%HID_USAGE_TELEPHONY_MESSAGE_CONTROLS       = &H03??
%HID_USAGE_TELEPHONY_HANDSET                = &H04??
%HID_USAGE_TELEPHONY_HEADSET                = &H05??
%HID_USAGE_TELEPHONY_KEYPAD                 = &H06??
%HID_USAGE_TELEPHONY_PROGRAMMABLE_BUTTON    = &H07??
%HID_USAGE_TELEPHONY_REDIAL                 = &H24??
%HID_USAGE_TELEPHONY_TRANSFER               = &H25??
%HID_USAGE_TELEPHONY_DROP                   = &H26??
%HID_USAGE_TELEPHONY_LINE                   = &H2A??
%HID_USAGE_TELEPHONY_RING_ENABLE            = &H2D??
%HID_USAGE_TELEPHONY_SEND                   = &H31??
%HID_USAGE_TELEPHONY_KEYPAD_0               = &HB0??
%HID_USAGE_TELEPHONY_KEYPAD_D               = &HBF??
%HID_USAGE_TELEPHONY_HOST_AVAILABLE         = &HF1??


'//
'// Microsoft Bluetooth Handsfree Page (0xFFF3)
'//
%HID_USAGE_MS_BTH_HF_DIALNUMBER             = &H21??
%HID_USAGE_MS_BTH_HF_DIALMEMORY             = &H22??


'//
'// and others...
'//

%HID_USAGE_CONSUMERCTRL                     = &H01??
%HID_USAGE_DIGITIZER_PEN                    = &H02??
%HID_USAGE_DIGITIZER_IN_RANGE               = &H32??
%HID_USAGE_DIGITIZER_TIP_SWITCH             = &H42??
%HID_USAGE_DIGITIZER_BARREL_SWITCH          = &H44??
