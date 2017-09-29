' ########################################################################################
' Microsoft Windows
' File: dinput.inc
' Contents: DirectInput include file
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%DINPUT_INC = 1

#INCLUDE ONCE "windows.inc"
#INCLUDE ONCE "objbase.inc"

%DIRECTINPUT_HEADER_VERSION = &H0800
%DIRECTINPUT_VERSION        = %DIRECTINPUT_HEADER_VERSION

'/****************************************************************************
' *
' *      Class IDs
' *
' ****************************************************************************/

$CLSID_DirectInput              = GUID$("{25E609E0-B259-11CF-BFC7-444553540000}")
$CLSID_DirectInputDevice        = GUID$("{25E609E1-B259-11CF-BFC7-444553540000}")
$CLSID_DirectInput8             = GUID$("{25E609E4-B259-11CF-BFC7-444553540000}")
$CLSID_DirectInputDevice8       = GUID$("{25E609E5-B259-11CF-BFC7-444553540000}")

'/****************************************************************************
' *
' *      Interfaces
' *
' ****************************************************************************/

$IID_IDirectInput               = GUID$("{89521360-AA8A-11CF-BFC7-444553540000}")
$IID_IDirectInputA              = GUID$("{89521360-AA8A-11CF-BFC7-444553540000}")
$IID_IDirectInputW              = GUID$("{89521361-AA8A-11CF-BFC7-444553540000}")
$IID_IDirectInput2              = GUID$("{5944E662-AA8A-11CF-BFC7-444553540000}")
$IID_IDirectInput2A             = GUID$("{5944E662-AA8A-11CF-BFC7-444553540000}")
$IID_IDirectInput2W             = GUID$("{5944E663-AA8A-11CF-BFC7-444553540000}")
$IID_IDirectInput7              = GUID$("{9A4CB684-236D-11D3-8E9D-00C04F6844AE}")
$IID_IDirectInput7A             = GUID$("{9A4CB684-236D-11D3-8E9D-00C04F6844AE}")
$IID_IDirectInput7W             = GUID$("{9A4CB685-236D-11D3-8E9D-00C04F6844AE}")
$IID_IDirectInput8              = GUID$("{BF798030-483A-4DA2-AA99-5D64ED369700}")
$IID_IDirectInput8A             = GUID$("{BF798030-483A-4DA2-AA99-5D64ED369700}")
$IID_IDirectInput8W             = GUID$("{BF798031-483A-4DA2-AA99-5D64ED369700}")
$IID_IDirectInputDevice         = GUID$("{5944E680-C92E-11CF-BFC7-444553540000}")
$IID_IDirectInputDeviceA        = GUID$("{5944E680-C92E-11CF-BFC7-444553540000}")
$IID_IDirectInputDeviceW        = GUID$("{5944E681-C92E-11CF-BFC7-444553540000}")
$IID_IDirectInputDevice2        = GUID$("{5944E682-C92E-11CF-BFC7-444553540000}")
$IID_IDirectInputDevice2A       = GUID$("{5944E682-C92E-11CF-BFC7-444553540000}")
$IID_IDirectInputDevice2W       = GUID$("{5944E683-C92E-11CF-BFC7-444553540000}")
$IID_IDirectInputDevice7        = GUID$("{57D7C6BC-2356-11D3-8E9D-00C04F6844AE}")
$IID_IDirectInputDevice7A       = GUID$("{57D7C6BC-2356-11D3-8E9D-00C04F6844AE}")
$IID_IDirectInputDevice7W       = GUID$("{57D7C6BD-2356-11D3-8E9D-00C04F6844AE}")
$IID_IDirectInputDevice8        = GUID$("{54D41080-DC15-4833-A41B-748F73A38179}")
$IID_IDirectInputDevice8A       = GUID$("{54D41080-DC15-4833-A41B-748F73A38179}")
$IID_IDirectInputDevice8W       = GUID$("{54D41081-DC15-4833-A41B-748F73A38179}")
$IID_IDirectInputEffect         = GUID$("{E7E1F7C0-88D2-11D0-9AD0-00A0C9A06E35}")

'/****************************************************************************
' *
' *      Predefined object types
' *
' ****************************************************************************/

$GUID_XAxis                     = GUID$("{A36D02E0-C9F3-11CF-BFC7-444553540000}")
$GUID_YAxis                     = GUID$("{A36D02E1-C9F3-11CF-BFC7-444553540000}")
$GUID_ZAxis                     = GUID$("{A36D02E2-C9F3-11CF-BFC7-444553540000}")
$GUID_RxAxis                    = GUID$("{A36D02F4-C9F3-11CF-BFC7-444553540000}")
$GUID_RyAxis                    = GUID$("{A36D02F5-C9F3-11CF-BFC7-444553540000}")
$GUID_RzAxis                    = GUID$("{A36D02E3-C9F3-11CF-BFC7-444553540000}")
$GUID_Slider                    = GUID$("{A36D02E4-C9F3-11CF-BFC7-444553540000}")
$GUID_Button                    = GUID$("{A36D02F0-C9F3-11CF-BFC7-444553540000}")
$GUID_Key                       = GUID$("{55728220-D33C-11CF-BFC7-444553540000}")
$GUID_POV                       = GUID$("{A36D02F2-C9F3-11CF-BFC7-444553540000}")
$GUID_Unknown                   = GUID$("{A36D02F3-C9F3-11CF-BFC7-444553540000}")

'/****************************************************************************
' *
' *      Predefined product GUIDs
' *
' ****************************************************************************/

$GUID_SysMouse                  = GUID$("{6F1D2B60-D5A0-11CF-BFC7-444553540000}")
$GUID_SysKeyboard               = GUID$("{6F1D2B61-D5A0-11CF-BFC7-444553540000}")
$GUID_Joystick                  = GUID$("{6F1D2B70-D5A0-11CF-BFC7-444553540000}")
$GUID_SysMouseEm                = GUID$("{6F1D2B80-D5A0-11CF-BFC7-444553540000}")
$GUID_SysMouseEm2               = GUID$("{6F1D2B81-D5A0-11CF-BFC7-444553540000}")
$GUID_SysKeyboardEm             = GUID$("{6F1D2B82-D5A0-11CF-BFC7-444553540000}")
$GUID_SysKeyboardEm2            = GUID$("{6F1D2B83-D5A0-11CF-BFC7-444553540000}")

'/****************************************************************************
' *
' *      Predefined force feedback effects
' *
' ****************************************************************************/

$GUID_ConstantForce             = GUID$("{13541C20-8E33-11D0-9AD0-00A0C9A06E35}")
$GUID_RampForce                 = GUID$("{13541C21-8E33-11D0-9AD0-00A0C9A06E35}")
$GUID_Square                    = GUID$("{13541C22-8E33-11D0-9AD0-00A0C9A06E35}")
$GUID_Sine                      = GUID$("{13541C23-8E33-11D0-9AD0-00A0C9A06E35}")
$GUID_Triangle                  = GUID$("{13541C24-8E33-11D0-9AD0-00A0C9A06E35}")
$GUID_SawtoothUp                = GUID$("{13541C25-8E33-11D0-9AD0-00A0C9A06E35}")
$GUID_SawtoothDown              = GUID$("{13541C26-8E33-11D0-9AD0-00A0C9A06E35}")
$GUID_Spring                    = GUID$("{13541C27-8E33-11D0-9AD0-00A0C9A06E35}")
$GUID_Damper                    = GUID$("{13541C28-8E33-11D0-9AD0-00A0C9A06E35}")
$GUID_Inertia                   = GUID$("{13541C29-8E33-11D0-9AD0-00A0C9A06E35}")
$GUID_Friction                  = GUID$("{13541C2A-8E33-11D0-9AD0-00A0C9A06E35}")
$GUID_CustomForce               = GUID$("{13541C2B-8E33-11D0-9AD0-00A0C9A06E35}")

'/****************************************************************************
' *
' *      Interfaces and Structures...
' *
' ****************************************************************************/

'/****************************************************************************
' *
' *      IDirectInputEffect
' *
' ****************************************************************************/

%DIEFT_ALL                   = &H00000000???

%DIEFT_CONSTANTFORCE         = &H00000001???
%DIEFT_RAMPFORCE             = &H00000002???
%DIEFT_PERIODIC              = &H00000003???
%DIEFT_CONDITION             = &H00000004???
%DIEFT_CUSTOMFORCE           = &H00000005???
%DIEFT_HARDWARE              = &H000000FF???
%DIEFT_FFATTACK              = &H00000200???
%DIEFT_FFFADE                = &H00000400???
%DIEFT_SATURATION            = &H00000800???
%DIEFT_POSNEGCOEFFICIENTS    = &H00001000???
%DIEFT_POSNEGSATURATION      = &H00002000???
%DIEFT_DEADBAND              = &H00004000???
%DIEFT_STARTDELAY            = &H00008000???

'#define DIEFT_GETTYPE(n)            LOBYTE(n)
MACRO DIEFT_GETTYPE(n) = LO(BYTE, n)

%DI_DEGREES                  = 100
%DI_FFNOMINALMAX             = 10000
%DI_SECONDS                  = 1000000

' // Size = 4 bytes
TYPE DICONSTANTFORCE DWORD
   lMagnitude AS LONG   ' LONG
END TYPE

' // Size = 8 bytes
TYPE DIRAMPFORCE DWORD
   lStart AS LONG   ' LONG
   lEnd   AS LONG   ' LONG
END TYPE

' // Size = 16 bytes
TYPE DIPERIODIC DWORD
   dwMagnitude AS DWORD   ' DWORD
   lOffset     AS LONG    ' LONG
   dwPhase     AS DWORD   ' DWORD
   dwPeriod    AS DWORD   ' DWORD
END TYPE

' // Size = 24 bytes
TYPE DICONDITION DWORD
   lOffset              AS LONG    ' LONG
   lPositiveCoefficient AS LONG    ' LONG
   lNegativeCoefficient AS LONG    ' LONG
   dwPositiveSaturation AS DWORD   ' DWORD
   dwNegativeSaturation AS DWORD   ' DWORD
   lDeadBand            AS LONG    ' LONG
END TYPE

' // Size = 16 bytes
TYPE DICUSTOMFORCE DWORD
   cChannels      AS DWORD      ' DWORD
   dwSamplePeriod AS DWORD      ' DWORD
   cSamples       AS DWORD      ' DWORD
   rglForceData   AS LONG PTR   ' LPLONG
END TYPE

' // Size = 20 bytes
TYPE DIENVELOPE DWORD
   dwSize        AS DWORD   ' DWORD /* sizeof(DIENVELOPE)   */
   dwAttackLevel AS DWORD   ' DWORD
   dwAttackTime  AS DWORD   ' DWORD /* Microseconds         */
   dwFadeLevel   AS DWORD   ' DWORD
   dwFadeTime    AS DWORD   ' DWORD /* Microseconds         */
END TYPE

'/* This structure is defined for DirectX 5.0 compatibility */
' // Size = 52 bytes
TYPE DIEFFECT_DX5 DWORD
   dwSize                  AS DWORD       ' DWORD /* sizeof(DIEFFECT)     */
   dwFlags                 AS DWORD       ' DWORD /* DIEFF_*              */
   dwDuration              AS DWORD       ' DWORD /* Microseconds         */
   dwSamplePeriod          AS DWORD       ' DWORD /* Microseconds         */
   dwGain                  AS DWORD       ' DWORD
   dwTriggerButton         AS DWORD       ' DWORD /* or DIEB_NOTRIGGER    */
   dwTriggerRepeatInterval AS DWORD       ' DWORD /* Microseconds         */
   cAxes                   AS DWORD       ' DWORD /* Number of axes       */
   rgdwAxes                AS DWORD PTR   ' LPDWORD /* Array of axes        */
   rglDirection            AS LONG PTR    ' LPLONG /* Array of directions  */
   lpEnvelope              AS DWORD       ' LPDIENVELOPE /* Optional             */
   cbTypeSpecificParams    AS DWORD       ' DWORD /* Size of params       */
   lpvTypeSpecificParams   AS DWORD       ' LPVOID /* Pointer to params    */
END TYPE

' // Size = 56 bytes
TYPE DIEFFECT_DX6 DWORD
   dwSize                  AS DWORD       ' DWORD /* sizeof(DIEFFECT)     */
   dwFlags                 AS DWORD       ' DWORD /* DIEFF_*              */
   dwDuration              AS DWORD       ' DWORD /* Microseconds         */
   dwSamplePeriod          AS DWORD       ' DWORD /* Microseconds         */
   dwGain                  AS DWORD       ' DWORD
   dwTriggerButton         AS DWORD       ' DWORD /* or DIEB_NOTRIGGER    */
   dwTriggerRepeatInterval AS DWORD       ' DWORD /* Microseconds         */
   cAxes                   AS DWORD       ' DWORD /* Number of axes       */
   rgdwAxes                AS DWORD PTR   ' LPDWORD /* Array of axes        */
   rglDirection            AS LONG PTR    ' LPLONG /* Array of directions  */
   lpEnvelope              AS DWORD       ' LPDIENVELOPE /* Optional             */
   cbTypeSpecificParams    AS DWORD       ' DWORD /* Size of params       */
   lpvTypeSpecificParams   AS DWORD       ' DWORD /* Pointer to params    */
'#if(DIRECTINPUT_VERSION >= 0x0600)
   dwStartDelay            AS DWORD       ' DWORD /* Microseconds         */
'#endif /* DIRECTINPUT_VERSION >= 0x0600 */
END TYPE

MACRO DIEFFECT = DIEFFECT_DX6

' // Size = 284 bytes
TYPE DIFILEEFFECT DWORD
   dwSize         AS DWORD                ' DWORD
   GuidEffect     AS GUID                 ' GUID
   lpDiEffect     AS DWORD                ' LPCDIEFFECT
   szFriendlyName AS ASCIIZ * %MAX_PATH   ' CHAR[MAX_PATH]
END TYPE

%DIEFF_OBJECTIDS             = &H00000001???
%DIEFF_OBJECTOFFSETS         = &H00000002???
%DIEFF_CARTESIAN             = &H00000010???
%DIEFF_POLAR                 = &H00000020???
%DIEFF_SPHERICAL             = &H00000040???

%DIEP_DURATION               = &H00000001???
%DIEP_SAMPLEPERIOD           = &H00000002???
%DIEP_GAIN                   = &H00000004???
%DIEP_TRIGGERBUTTON          = &H00000008???
%DIEP_TRIGGERREPEATINTERVAL  = &H00000010???
%DIEP_AXES                   = &H00000020???
%DIEP_DIRECTION              = &H00000040???
%DIEP_ENVELOPE               = &H00000080???
%DIEP_TYPESPECIFICPARAMS     = &H00000100???
%DIEP_STARTDELAY             = &H00000200???
%DIEP_ALLPARAMS_DX5          = &H000001FF???
%DIEP_ALLPARAMS              = &H000003FF???
'%DIEP_ALLPARAMS              = &H000001FF???   ' // DirectInput < 6.0
%DIEP_START                  = &H20000000???
%DIEP_NORESTART              = &H40000000???
%DIEP_NODOWNLOAD             = &H80000000???
%DIEB_NOTRIGGER              = &HFFFFFFFF???

%DIES_SOLO                   = &H00000001???
%DIES_NODOWNLOAD             = &H80000000???

%DIEGES_PLAYING              = &H00000001???
%DIEGES_EMULATED             = &H00000002???

' // Size = 24 bytes
TYPE DIEFFESCAPE DWORD
   dwSize       AS DWORD   ' DWORD
   dwCommand    AS DWORD   ' DWORD
   lpvInBuffer  AS DWORD   ' LPVOID
   cbInBuffer   AS DWORD   ' DWORD
   lpvOutBuffer AS DWORD   ' LPVOID
   cbOutBuffer  AS DWORD   ' DWORD
END TYPE

' ########################################################################################
' IDirectInputEffect interface
' IID = E7E1F7C0-88D2-11D0-9AD0-00A0C9A06E35
' Inherited interface = IUnknown
' ########################################################################################

INTERFACE IDirectInputEffect $IID_IDirectInputEffect

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Initialize ( _                                ' VTable offset = 12
     BYVAL hinst AS DWORD _                             ' __in HINSTANCE hinst
   , BYVAL dwVersion AS DWORD _                         ' __in DWORD dwVersion
   , BYREF rguid AS GUID _                              ' __in REFGUID rguid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetEffectGuid ( _                             ' VTable offset = 16
     BYREF pguid AS GUID _                              ' __out LPGUID pguid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetParameters ( _                             ' VTable offset = 20
     BYREF pguid AS DIEFFECT _                          ' __out LPDIEFFECT peff
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetParameters ( _                             ' VTable offset = 24
     BYREF pguid AS DIEFFECT _                          ' __in LPDIEFFECT peff
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Start ( _                                     ' VTable offset = 28
     BYVAL dwIterations AS DWORD _                      ' __in DWORD dwIterations
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Stop ( _                                      ' VTable offset = 32
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetEffectStatus ( _                           ' VTable offset = 36
     BYREF pdwFlags AS DWORD _                          ' __out LPDWORD pdwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Download ( _                                  ' VTable offset = 40
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Unload ( _                                    ' VTable offset = 44
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Escape ( _                                    ' VTable offset = 48
     BYREF pesc AS DIEFFESCAPE _                        ' __in LPDIEFFESCAPE pesc
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE


'/****************************************************************************
' *
' *      IDirectInputDevice
' *
' ****************************************************************************/

%DIDEVTYPE_DEVICE            = 1
%DIDEVTYPE_MOUSE             = 2
%DIDEVTYPE_KEYBOARD          = 3
%DIDEVTYPE_JOYSTICK          = 4

%DI8DEVCLASS_ALL             = 0
%DI8DEVCLASS_DEVICE          = 1
%DI8DEVCLASS_POINTER         = 2
%DI8DEVCLASS_KEYBOARD        = 3
%DI8DEVCLASS_GAMECTRL        = 4

%DI8DEVTYPE_DEVICE           = &H11
%DI8DEVTYPE_MOUSE            = &H12
%DI8DEVTYPE_KEYBOARD         = &H13
%DI8DEVTYPE_JOYSTICK         = &H14
%DI8DEVTYPE_GAMEPAD          = &H15
%DI8DEVTYPE_DRIVING          = &H16
%DI8DEVTYPE_FLIGHT           = &H17
%DI8DEVTYPE_1STPERSON        = &H18
%DI8DEVTYPE_DEVICECTRL       = &H19
%DI8DEVTYPE_SCREENPOINTER    = &H1A
%DI8DEVTYPE_REMOTE           = &H1B
%DI8DEVTYPE_SUPPLEMENTAL     = &H1C

%DIDEVTYPE_HID               = &H00010000

%DIDEVTYPEMOUSE_UNKNOWN         = 1
%DIDEVTYPEMOUSE_TRADITIONAL     = 2
%DIDEVTYPEMOUSE_FINGERSTICK     = 3
%DIDEVTYPEMOUSE_TOUCHPAD        = 4
%DIDEVTYPEMOUSE_TRACKBALL       = 5

%DIDEVTYPEKEYBOARD_UNKNOWN      = 0
%DIDEVTYPEKEYBOARD_PCXT         = 1
%DIDEVTYPEKEYBOARD_OLIVETTI     = 2
%DIDEVTYPEKEYBOARD_PCAT         = 3
%DIDEVTYPEKEYBOARD_PCENH        = 4
%DIDEVTYPEKEYBOARD_NOKIA1050    = 5
%DIDEVTYPEKEYBOARD_NOKIA9140    = 6
%DIDEVTYPEKEYBOARD_NEC98        = 7
%DIDEVTYPEKEYBOARD_NEC98LAPTOP  = 8
%DIDEVTYPEKEYBOARD_NEC98106     = 9
%DIDEVTYPEKEYBOARD_JAPAN106     = 10
%DIDEVTYPEKEYBOARD_JAPANAX      = 11
%DIDEVTYPEKEYBOARD_J3100        = 12

%DIDEVTYPEJOYSTICK_UNKNOWN      = 1
%DIDEVTYPEJOYSTICK_TRADITIONAL  = 2
%DIDEVTYPEJOYSTICK_FLIGHTSTICK  = 3
%DIDEVTYPEJOYSTICK_GAMEPAD      = 4
%DIDEVTYPEJOYSTICK_RUDDER       = 5
%DIDEVTYPEJOYSTICK_WHEEL        = 6
%DIDEVTYPEJOYSTICK_HEADTRACKER  = 7

%DI8DEVTYPEMOUSE_UNKNOWN                    = 1
%DI8DEVTYPEMOUSE_TRADITIONAL                = 2
%DI8DEVTYPEMOUSE_FINGERSTICK                = 3
%DI8DEVTYPEMOUSE_TOUCHPAD                   = 4
%DI8DEVTYPEMOUSE_TRACKBALL                  = 5
%DI8DEVTYPEMOUSE_ABSOLUTE                   = 6

%DI8DEVTYPEKEYBOARD_UNKNOWN                 = 0
%DI8DEVTYPEKEYBOARD_PCXT                    = 1
%DI8DEVTYPEKEYBOARD_OLIVETTI                = 2
%DI8DEVTYPEKEYBOARD_PCAT                    = 3
%DI8DEVTYPEKEYBOARD_PCENH                   = 4
%DI8DEVTYPEKEYBOARD_NOKIA1050               = 5
%DI8DEVTYPEKEYBOARD_NOKIA9140               = 6
%DI8DEVTYPEKEYBOARD_NEC98                   = 7
%DI8DEVTYPEKEYBOARD_NEC98LAPTOP             = 8
%DI8DEVTYPEKEYBOARD_NEC98106                = 9
%DI8DEVTYPEKEYBOARD_JAPAN106                = 10
%DI8DEVTYPEKEYBOARD_JAPANAX                 = 11
%DI8DEVTYPEKEYBOARD_J3100                   = 12

%DI8DEVTYPE_LIMITEDGAMESUBTYPE              = 1

%DI8DEVTYPEJOYSTICK_LIMITED                 = %DI8DEVTYPE_LIMITEDGAMESUBTYPE
%DI8DEVTYPEJOYSTICK_STANDARD                = 2

%DI8DEVTYPEGAMEPAD_LIMITED                  = %DI8DEVTYPE_LIMITEDGAMESUBTYPE
%DI8DEVTYPEGAMEPAD_STANDARD                 = 2
%DI8DEVTYPEGAMEPAD_TILT                     = 3

%DI8DEVTYPEDRIVING_LIMITED                  = %DI8DEVTYPE_LIMITEDGAMESUBTYPE
%DI8DEVTYPEDRIVING_COMBINEDPEDALS           = 2
%DI8DEVTYPEDRIVING_DUALPEDALS               = 3
%DI8DEVTYPEDRIVING_THREEPEDALS              = 4
%DI8DEVTYPEDRIVING_HANDHELD                 = 5

%DI8DEVTYPEFLIGHT_LIMITED                   = %DI8DEVTYPE_LIMITEDGAMESUBTYPE
%DI8DEVTYPEFLIGHT_STICK                     = 2
%DI8DEVTYPEFLIGHT_YOKE                      = 3
%DI8DEVTYPEFLIGHT_RC                        = 4

%DI8DEVTYPE1STPERSON_LIMITED                = %DI8DEVTYPE_LIMITEDGAMESUBTYPE
%DI8DEVTYPE1STPERSON_UNKNOWN                = 2
%DI8DEVTYPE1STPERSON_SIXDOF                 = 3
%DI8DEVTYPE1STPERSON_SHOOTER                = 4

%DI8DEVTYPESCREENPTR_UNKNOWN                = 2
%DI8DEVTYPESCREENPTR_LIGHTGUN               = 3
%DI8DEVTYPESCREENPTR_LIGHTPEN               = 4
%DI8DEVTYPESCREENPTR_TOUCH                  = 5

%DI8DEVTYPEREMOTE_UNKNOWN                   = 2

%DI8DEVTYPEDEVICECTRL_UNKNOWN               = 2
%DI8DEVTYPEDEVICECTRL_COMMSSELECTION        = 3
%DI8DEVTYPEDEVICECTRL_COMMSSELECTION_HARDWIRED = 4

%DI8DEVTYPESUPPLEMENTAL_UNKNOWN             = 2
%DI8DEVTYPESUPPLEMENTAL_2NDHANDCONTROLLER   = 3
%DI8DEVTYPESUPPLEMENTAL_HEADTRACKER         = 4
%DI8DEVTYPESUPPLEMENTAL_HANDTRACKER         = 5
%DI8DEVTYPESUPPLEMENTAL_SHIFTSTICKGATE      = 6
%DI8DEVTYPESUPPLEMENTAL_SHIFTER             = 7
%DI8DEVTYPESUPPLEMENTAL_THROTTLE            = 8
%DI8DEVTYPESUPPLEMENTAL_SPLITTHROTTLE       = 9
%DI8DEVTYPESUPPLEMENTAL_COMBINEDPEDALS      = 10
%DI8DEVTYPESUPPLEMENTAL_DUALPEDALS          = 11
%DI8DEVTYPESUPPLEMENTAL_THREEPEDALS         = 12
%DI8DEVTYPESUPPLEMENTAL_RUDDERPEDALS        = 13

'#define GET_DIDEVICE_TYPE(dwDevType)    LOBYTE(dwDevType)
'#define GET_DIDEVICE_SUBTYPE(dwDevType) HIBYTE(dwDevType)
MACRO GET_DIDEVICE_TYPE(dwDevType) = LO(BYTE, dwDevType)
MACRO GET_DIDEVICE_SUBTYPE(dwDevType) = HI(BYTE, dwDevType)

'/* This structure is defined for DirectX 3.0 compatibility */
' // Size = 24 bytes
TYPE DIDEVCAPS_DX3 DWORD
   dwSize                AS DWORD   ' DWORD
   dwFlags               AS DWORD   ' DWORD
   dwDevType             AS DWORD   ' DWORD
   dwAxes                AS DWORD   ' DWORD
   dwButtons             AS DWORD   ' DWORD
   dwPOVs                AS DWORD   ' DWORD
END TYPE

' // Size = 44 bytes
TYPE DIDEVCAPS DWORD
   dwSize                AS DWORD   ' DWORD
   dwFlags               AS DWORD   ' DWORD
   dwDevType             AS DWORD   ' DWORD
   dwAxes                AS DWORD   ' DWORD
   dwButtons             AS DWORD   ' DWORD
   dwPOVs                AS DWORD   ' DWORD
'#if(DIRECTINPUT_VERSION >= 0x0500)
   dwFFSamplePeriod      AS DWORD   ' DWORD
   dwFFMinTimeResolution AS DWORD   ' DWORD
   dwFirmwareRevision    AS DWORD   ' DWORD
   dwHardwareRevision    AS DWORD   ' DWORD
   dwFFDriverVersion     AS DWORD   ' DWORD
'#endif /* DIRECTINPUT_VERSION >= 0x0500 */
END TYPE

%DIDC_ATTACHED           = &H00000001???
%DIDC_POLLEDDEVICE       = &H00000002???
%DIDC_EMULATED           = &H00000004???
%DIDC_POLLEDDATAFORMAT   = &H00000008???
%DIDC_FORCEFEEDBACK      = &H00000100???
%DIDC_FFATTACK           = &H00000200???
%DIDC_FFFADE             = &H00000400???
%DIDC_SATURATION         = &H00000800???
%DIDC_POSNEGCOEFFICIENTS = &H00001000???
%DIDC_POSNEGSATURATION   = &H00002000???
%DIDC_DEADBAND           = &H00004000???
%DIDC_STARTDELAY         = &H00008000???
%DIDC_ALIAS              = &H00010000???
%DIDC_PHANTOM            = &H00020000???
%DIDC_HIDDEN             = &H00040000???

%DIDFT_ALL               = &H00000000???

%DIDFT_RELAXIS           = &H00000001???
%DIDFT_ABSAXIS           = &H00000002???
%DIDFT_AXIS              = &H00000003???

%DIDFT_PSHBUTTON         = &H00000004???
%DIDFT_TGLBUTTON         = &H00000008???
%DIDFT_BUTTON            = &H0000000C???

%DIDFT_POV               = &H00000010???
%DIDFT_COLLECTION        = &H00000040???
%DIDFT_NODATA            = &H00000080???

%DIDFT_ANYINSTANCE       = &H00FFFF00???
%DIDFT_INSTANCEMASK      = %DIDFT_ANYINSTANCE

'%DIDFT_MAKEINSTANCE(n) ((WORD)(n) << 8)
FUNCTION DIDFT_MAKEINSTANCE (BYVAL n AS WORD) AS WORD
   SHIFT LEFT n, 8
   FUNCTION = n
END FUNCTION

'%DIDFT_GETTYPE(n)     LOBYTE(n)
MACRO DIDFT_GETTYPE(n) = LO(BYTE, n)

'%DIDFT_GETINSTANCE(n) LOWORD((n) >> 8)
FUNCTION DIDFT_GETINSTANCE (BYVAL n AS WORD) AS WORD
   SHIFT RIGHT n, 8
   FUNCTION = n
END FUNCTION


%DIDFT_FFACTUATOR        = &H01000000???
%DIDFT_FFEFFECTTRIGGER   = &H02000000???
%DIDFT_OUTPUT            = &H10000000???
%DIDFT_VENDORDEFINED     = &H04000000???
%DIDFT_ALIAS             = &H08000000???
%DIDFT_OPTIONAL          = &H80000000???   ' // Not included in Windows 7 Sdk

'%DIDFT_ENUMCOLLECTION(n) ((WORD)(n) << 8)
FUNCTION DIDFT_ENUMCOLLECTION (BYVAL n AS WORD) AS WORD
   SHIFT LEFT n, 8
   FUNCTION = n
END FUNCTION

%DIDFT_NOCOLLECTION      = &H00FFFF00???

' // Size = 16 bytes
TYPE DIOBJECTDATAFORMAT DWORD
   pguid   AS GUID PTR   ' const GUID *
   dwOfs   AS DWORD      ' DWORD
   dwType  AS DWORD      ' DWORD
   dwFlags AS DWORD      ' DWORD
END TYPE

' // Size = 24 bytes
TYPE DIDATAFORMAT DWORD
   dwSize     AS DWORD                    ' DWORD
   dwObjSize  AS DWORD                    ' DWORD
   dwFlags    AS DWORD                    ' DWORD
   dwDataSize AS DWORD                    ' DWORD
   dwNumObjs  AS DWORD                    ' DWORD
   rgodf      AS DIOBJECTDATAFORMAT PTR   ' LPDIOBJECTDATAFORMAT // Array of DIOBJECTDATAFORMAT structures
END TYPE

%DIDF_ABSAXIS          = &H00000001???
%DIDF_RELAXIS          = &H00000002???

'#ifdef __cplusplus
'extern "C" {
'#endif
'extern const DIDATAFORMAT c_dfDIMouse;

'#if(DIRECTINPUT_VERSION >= 0x0700)
'extern const DIDATAFORMAT c_dfDIMouse2;
'#endif /* DIRECTINPUT_VERSION >= 0x0700 */

'extern const DIDATAFORMAT c_dfDIKeyboard;

'#if(DIRECTINPUT_VERSION >= 0x0500)
'extern const DIDATAFORMAT c_dfDIJoystick;
'extern const DIDATAFORMAT c_dfDIJoystick2;
'#endif /* DIRECTINPUT_VERSION >= 0x0500 */

'#ifdef __cplusplus
'};
'#endif

' // Size = 4 bytes
UNION DIACTIONA_UNION DWORD
   lptszActionName AS ASCIIZ PTR   ' LPCSTR
   uResIdString    AS DWORD        ' UINT
END UNION

' // Size = 40 bytes
TYPE DIACTIONA DWORD
   uAppData        AS DWORD PTR   ' UINT_PTR
   dwSemantic      AS DWORD       ' DWORD
   dwFlags         AS DWORD       ' DWORD
   DIACTIONA_UNION
   guidInstance    AS GUID        ' GUID
   dwObjID         AS DWORD       ' DWORD
   dwHow           AS DWORD       ' DWORD
END TYPE

' // Size = 4 bytes
UNION DIACTIONW_UNION DWORD
   lptszActionName AS WSTRINGZ PTR   ' LPCWSTR
   uResIdString    AS DWORD          ' UINT
END UNION

' // Size = 40 bytes
TYPE DIACTIONW
   uAppData        AS DWORD PTR   ' UINT_PTR
   dwSemantic      AS DWORD       ' DWORD
   dwFlags         AS DWORD       ' DWORD
   DIACTIONW_UNION
   guidInstance    AS GUID        ' GUID
   dwObjID         AS DWORD       ' DWORD
   dwHow           AS DWORD       ' DWORD
END TYPE

#IF %DEF(%UNICODE)
   MACRO DIACTION = DIACTIONW
#ELSE
   MACRO DIACTION = DIACTIONA
#ENDIF

%DIA_FORCEFEEDBACK       = &H00000001???
%DIA_APPMAPPED           = &H00000002???
%DIA_APPNOMAP            = &H00000004???
%DIA_NORANGE             = &H00000008???
%DIA_APPFIXED            = &H00000010???

%DIAH_UNMAPPED           = &H00000000???
%DIAH_USERCONFIG         = &H00000001???
%DIAH_APPREQUESTED       = &H00000002???
%DIAH_HWAPP              = &H00000004???
%DIAH_HWDEFAULT          = &H00000008???
%DIAH_DEFAULT            = &H00000020???
%DIAH_ERROR              = &H80000000???

' // Size = 328 bytes
TYPE DIACTIONFORMATA DWORD
   dwSize        AS DWORD                ' DWORD
   dwActionSize  AS DWORD                ' DWORD
   dwDataSize    AS DWORD                ' DWORD
   dwNumActions  AS DWORD                ' DWORD
   rgoAction     AS DIACTIONA PTR        ' LPDIACTIONA // Array of DIACTIONA structures
   guidActionMap AS GUID                 ' GUID
   dwGenre       AS DWORD                ' DWORD
   dwBufferSize  AS DWORD                ' DWORD
   lAxisMin      AS LONG                 ' LONG
   lAxisMax      AS LONG                 ' LONG
   hInstString   AS DWORD                ' HINSTANCE
   ftTimeStamp   AS FILETIME             ' FILETIME
   dwCRC         AS DWORD                ' DWORD
   tszActionMap  AS ASCIIZ * %MAX_PATH   ' CHAR[MAX_PATH]
END TYPE

' // Size = 588 bytes
TYPE DIACTIONFORMATW DWORD
   dwSize        AS DWORD                   ' DWORD
   dwActionSize  AS DWORD                   ' DWORD
   dwDataSize    AS DWORD                   ' DWORD
   dwNumActions  AS DWORD                   ' DWORD
   rgoAction     AS DIACTIONW PTR           ' LPDIACTIONW // Array of DIACTIONW structures
   guidActionMap AS GUID                    ' GUID
   dwGenre       AS DWORD                   ' DWORD
   dwBufferSize  AS DWORD                   ' DWORD
   lAxisMin      AS LONG                    ' LONG
   lAxisMax      AS LONG                    ' LONG
   hInstString   AS DWORD                   ' HISNTANCE
   ftTimeStamp   AS FILETIME                ' FILETIME
   dwCRC         AS DWORD                   ' DWORD
   tszActionMap  AS WSTRINGZ * %MAX_PATH    ' WCHAR[MAX_PATH]
END TYPE

#IF %DEF(%UNICODE)
   MACRO DIACTIONFORMAT = DIACTIONFORMATW
#ELSE
   MACRO DIACTIONFORMAT = DIACTIONFORMATA
#ENDIF

%DIAFTS_NEWDEVICELOW     = &HFFFFFFFF???
%DIAFTS_NEWDEVICEHIGH    = &HFFFFFFFF???
%DIAFTS_UNUSEDDEVICELOW  = &H00000000???
%DIAFTS_UNUSEDDEVICEHIGH = &H00000000???

%DIDBAM_DEFAULT          = &H00000000???
%DIDBAM_PRESERVE         = &H00000001???
%DIDBAM_INITIALIZE       = &H00000002???
%DIDBAM_HWDEFAULTS       = &H00000004???

%DIDSAM_DEFAULT          = &H00000000???
%DIDSAM_NOUSER           = &H00000001???
%DIDSAM_FORCESAVE        = &H00000002???

%DICD_DEFAULT            = &H00000000???
%DICD_EDIT               = &H00000001???

'/*
' * The following definition is normally defined in d3dtypes.h
' */
'#ifndef D3DCOLOR_DEFINED
'typedef DWORD D3DCOLOR;
'#define D3DCOLOR_DEFINED
'#endif

' // Size = 36 bytes
TYPE DICOLORSET DWORD
   dwSize            AS DWORD   ' DWORD
   cTextFore         AS DWORD   ' D3DCOLOR
   cTextHighlight    AS DWORD   ' D3DCOLOR
   cCalloutLine      AS DWORD   ' D3DCOLOR
   cCalloutHighlight AS DWORD   ' D3DCOLOR
   cBorder           AS DWORD   ' D3DCOLOR
   cControlFill      AS DWORD   ' D3DCOLOR
   cHighlightFill    AS DWORD   ' D3DCOLOR
   cAreaFill         AS DWORD   ' D3DCOLOR
END TYPE

' // Size = 64 bytes
TYPE DICONFIGUREDEVICESPARAMSA DWORD
   dwSize         AS DWORD                 ' DWORD
   dwcUsers       AS DWORD                 ' DWORD
   lptszUserNames AS ASCIIZ PTR            ' LPSTR
   dwcFormats     AS DWORD                 ' DWORD
   lprgFormats    AS DIACTIONFORMATA PTR   ' LPDIACTIONFORMATA
   hwnd           AS DWORD                 ' DWORD
   dics           AS DICOLORSET            ' DICOLORSET
   lpUnkDDSTarget AS DWORD PTR             ' IUnknown FAR *
END TYPE

' // Size = 64 bytes
TYPE DICONFIGUREDEVICESPARAMSW DWORD
   dwSize         AS DWORD                 ' DWORD
   dwcUsers       AS DWORD                 ' DWORD
   lptszUserNames AS WSTRINGZ PTR          ' LPWSTR
   dwcFormats     AS DWORD                 ' DWORD
   lprgFormats    AS DIACTIONFORMATW PTR   ' LPDIACTIONFORMATW
   hwnd           AS DWORD                 ' DWORD
   dics           AS DICOLORSET            ' DICOLORSET
   lpUnkDDSTarget AS DWORD PTR             ' IUnknown FAR *
END TYPE

#IF %DEF(%UNICODE)
   MACRO DICONFIGUREDEVICESPARAMS = DICONFIGUREDEVICESPARAMSW
#ELSE
   MACRO DICONFIGUREDEVICESPARAMS = DICONFIGUREDEVICESPARAMSA
#ENDIF

%DIDIFT_CONFIGURATION = &H00000001???
%DIDIFT_OVERLAY       = &H00000002???

%DIDAL_CENTERED       = &H00000000???
%DIDAL_LEFTALIGNED    = &H00000001???
%DIDAL_RIGHTALIGNED   = &H00000002???
%DIDAL_MIDDLE         = &H00000000???
%DIDAL_TOPALIGNED     = &H00000004???
%DIDAL_BOTTOMALIGNED  = &H00000008???

' // Size = 352 bytes
TYPE DIDEVICEIMAGEINFOA DWORD
   tszImagePath       AS ASCIIZ * %MAX_PATH   ' CHAR[MAX_PATH]
   dwFlags            AS DWORD                ' DWORD
   ' // These are valid if DIDIFT_OVERLAY is present in dwFlags.
   dwViewID           AS DWORD                ' DWORD
   rcOverlay          AS RECT                 ' RECT
   dwObjID            AS DWORD                ' DWORD
   dwcValidPts        AS DWORD                ' DWORD
   rgptCalloutLine(4) AS POINT                ' POINT[5]
   rcCalloutRect      AS RECT                 ' RECT
   dwTextAlign        AS DWORD                ' DWORD
END TYPE

' // Size = 612 bytes
TYPE DIDEVICEIMAGEINFOW DWORD
   tszImagePath       AS WSTRINGZ * %MAX_PATH   ' WCHAR[MAX_PATH]
   dwFlags            AS DWORD                  ' DWORD
   ' // These are valid if DIDIFT_OVERLAY is present in dwFlags.
   dwViewID           AS DWORD                  ' DWORD
   rcOverlay          AS RECT                   ' RECT
   dwObjID            AS DWORD                  ' DWORD
   dwcValidPts        AS DWORD                  ' DWORD[5]
   rgptCalloutLine(4) AS POINT                  ' POINT
   rcCalloutRect      AS RECT                   ' RECT
   dwTextAlign        AS DWORD                  ' DWORD
END TYPE

#IF %DEF(%UNICODE)
   MACRO DIDEVICEIMAGEINFO = DIDEVICEIMAGEINFOW
#ELSE
   MACRO DIDEVICEIMAGEINFO = DIDEVICEIMAGEINFOA
#ENDIF

' // Size = 36 bytes
TYPE DIDEVICEIMAGEINFOHEADERA DWORD
   dwSize             AS DWORD                    ' DWORD
   dwSizeImageInfo    AS DWORD                    ' DWORD
   dwcViews           AS DWORD                    ' DWORD
   dwcButtons         AS DWORD                    ' DWORD
   dwcAxes            AS DWORD                    ' DWORD
   dwcPOVs            AS DWORD                    ' DWORD
   dwBufferSize       AS DWORD                    ' DWORD
   dwBufferUsed       AS DWORD                    ' DWORD
   lprgImageInfoArray AS DIDEVICEIMAGEINFOA PTR   ' LPDIDEVICEIMAGEINFOA
END TYPE

TYPE DIDEVICEIMAGEINFOHEADERW DWORD
   dwSize             AS DWORD                    ' DWORD
   dwSizeImageInfo    AS DWORD                    ' DWORD
   dwcViews           AS DWORD                    ' DWORD
   dwcButtons         AS DWORD                    ' DWORD
   dwcAxes            AS DWORD                    ' DWORD
   dwcPOVs            AS DWORD                    ' DWORD
   dwBufferSize       AS DWORD                    ' DWORD
   dwBufferUsed       AS DWORD                    ' DWORD
   lprgImageInfoArray AS DIDEVICEIMAGEINFOW PTR   ' LPDIDEVICEIMAGEINFOW
END TYPE

#IF %DEF(%UNICODE)
   MACRO DIDEVICEIMAGEINFOHEADER = DIDEVICEIMAGEINFOHEADERW
#ELSE
   MACRO DIDEVICEIMAGEINFOHEADER = DIDEVICEIMAGEINFOHEADERA
#ENDIF

'/* These structures are defined for DirectX 3.0 compatibility */

' // Size = 292 bytes
TYPE DIDEVICEOBJECTINSTANCE_DX3A DWORD
   dwSize              AS DWORD                ' DWORD
   guidType            AS GUID                 ' GUID
   dwOfs               AS DWORD                ' DWORD
   dwType              AS DWORD                ' DWORD
   dwFlags             AS DWORD                ' DWORD
   tszName             AS ASCIIZ * %MAX_PATH   ' CHAR[MAX_PATH]
END TYPE

' // Size = 552 bytes
TYPE DIDEVICEOBJECTINSTANCE_DX3W DWORD
   dwSize              AS DWORD                  ' DWORD
   guidType            AS GUID                   ' GUID
   dwOfs               AS DWORD                  ' DWORD
   dwType              AS DWORD                  ' DWORD
   dwFlags             AS DWORD                  ' DWORD
   tszName             AS WSTRINGZ * %MAX_PATH   ' WCHAR[MAX_PATH]
END TYPE

#IF %DEF(%UNICODE)
   MACRO DIDEVICEOBJECTINSTANCE_DX3 = DIDEVICEOBJECTINSTANCE_DX3W
#ELSE
   MACRO DIDEVICEOBJECTINSTANCE_DX3 = DIDEVICEOBJECTINSTANCE_DX3A
#ENDIF

' // Size = 316 bytes
TYPE DIDEVICEOBJECTINSTANCEA WORD
   dwSize              AS DWORD                ' DWORD
   guidType            AS GUID                 ' GUID
   dwOfs               AS DWORD                ' DWORD
   dwType              AS DWORD                ' DWORD
   dwFlags             AS DWORD                ' DWORD
   tszName             AS ASCIIZ * %MAX_PATH   ' CHAR[MAX_PATH]
'#if(DIRECTINPUT_VERSION >= 0x0500)
   dwFFMaxForce        AS DWORD                ' DWORD
   dwFFForceResolution AS DWORD                ' DWORD
   wCollectionNumber   AS WORD                 ' WORD
   wDesignatorIndex    AS WORD                 ' WORD
   wUsagePage          AS WORD                 ' WORD
   wUsage              AS WORD                 ' WORD
   dwDimension         AS DWORD                ' DWORD
   wExponent           AS WORD                 ' WORD
   wReportId           AS WORD                 ' WORD
'#endif /* DIRECTINPUT_VERSION >= 0x0500 */
END TYPE

' // Size = 576 bytes
TYPE DIDEVICEOBJECTINSTANCEW WORD
   dwSize              AS DWORD                  ' DWORD
   guidType            AS GUID                   ' GUID
   dwOfs               AS DWORD                  ' DWORD
   dwType              AS DWORD                  ' DWORD
   dwFlags             AS DWORD                  ' DWORD
   tszName             AS WSTRINGZ * %MAX_PATH   ' WCHAR[MAX_PATH]
'#if(DIRECTINPUT_VERSION >= 0x0500)
   dwFFMaxForce        AS DWORD                  ' DWORD
   dwFFForceResolution AS DWORD                  ' DWORD
   wCollectionNumber   AS WORD                   ' WORD
   wDesignatorIndex    AS WORD                   ' WORD
   wUsagePage          AS WORD                   ' WORD
   wUsage              AS WORD                   ' WORD
   dwDimension         AS DWORD                  ' DWORD
   wExponent           AS WORD                   ' WORD
   wReportId           AS WORD                   ' WORD
'#endif /* DIRECTINPUT_VERSION >= 0x0500 */
END TYPE

#IF %DEF(%UNICODE)
   MACRO DIDEVICEOBJECTINSTANCE = DIDEVICEOBJECTINSTANCEW
#ELSE
   MACRO DIDEVICEOBJECTINSTANCE = DIDEVICEOBJECTINSTANCEA
#ENDIF

%DIDOI_FFACTUATOR        = &H00000001???
%DIDOI_FFEFFECTTRIGGER   = &H00000002???
%DIDOI_POLLED            = &H00008000???
%DIDOI_ASPECTPOSITION    = &H00000100???
%DIDOI_ASPECTVELOCITY    = &H00000200???
%DIDOI_ASPECTACCEL       = &H00000300???
%DIDOI_ASPECTFORCE       = &H00000400???
%DIDOI_ASPECTMASK        = &H00000F00???
%DIDOI_GUIDISUSAGE       = &H00010000???

' // Size = 16 bytes
TYPE DIPROPHEADER DWORD
   dwSize       AS DWORD   ' DWORD
   dwHeaderSize AS DWORD   ' DWORD
   dwObj        AS DWORD   ' DWORD
   dwHow        AS DWORD   ' DWORD
END TYPE

%DIPH_DEVICE            = 0
%DIPH_BYOFFSET          = 1
%DIPH_BYID              = 2
%DIPH_BYUSAGE           = 3

'#define DIMAKEUSAGEDWORD(UsagePage, Usage) \
'                                (DWORD)MAKELONG(Usage, UsagePage)

' // Size = 20 bytes
TYPE DIPROPDWORD DWORD
   diph   AS DIPROPHEADER   ' DIPROPHEADER
   dwData AS DWORD          ' DWORD
END TYPE

' // Size = 20 bytes
TYPE DIPROPPOINTER DWORD
   diph  AS DIPROPHEADER   ' DIPROPHEADER
   uData AS DWORD          ' UINT_PTR
END TYPE

' // Size = 24 bytes
TYPE DIPROPRANGE DWORD
   diph AS DIPROPHEADER   ' DIPROPHEADER
   lMin AS LONG           ' LONG
   lMax AS LONG           ' LONG
END TYPE

%DIPROPRANGE_NOMIN       = &H80000000???
%DIPROPRANGE_NOMAX       = &H7FFFFFFF???

' // Size = 28 bytes
TYPE DIPROPCAL DWORD
   diph    AS DIPROPHEADER   ' DIPROPHEADER
   lMin    AS LONG           ' LONG
   lCenter AS LONG           ' LONG
   lMax    AS LONG           ' LONG
END TYPE

' // Size = 56 bytes
TYPE DIPROPCALPOV DWORD
   diph    AS DIPROPHEADER   ' DIPROPHEADER
   lMin(4) AS LONG           ' LONG[5]
   lMax(4) AS LONG           ' LONG[5]
END TYPE

' // Size = 552 bytes
TYPE DIPROPGUIDANDPATH DWORD
   diph      AS DIPROPHEADER           ' DIPROPHEADER
   guidClass AS GUID                   ' GUID
   wszPath   AS WSTRINGZ * %MAX_PATH   ' WCHAR[MAX_PATH]
END TYPE

' // Size = 536 bytes
TYPE DIPROPSTRING DWORD
   diph AS DIPROPHEADER           ' DIPROPHEADER
   wsz  AS WSTRINGZ * %MAX_PATH   ' WCHAR[MAX_PATH]
END TYPE

%MAXCPOINTSNUM        = 8

' // Size = 8 bytes
TYPE CPOINT DWORD
   lP    AS LONG    ' LONG  // raw value
   dwLog AS DWORD   ' DWORD // logical_value / max_logical_value * 10000
END TYPE

' // Size = 84 bytes
TYPE DIPROPCPOINTS DWORD
   diph         AS DIPROPHEADER       ' DIPROPHEADER
   dwCPointsNum AS DWORD              ' DWORD
   cp(%MAXCPOINTSNUM - 1) AS CPOINT   ' CPOINT[MAXCPOINTSNUM]
END TYPE

'#define MAKEDIPROP(prop)    (*(const GUID *)(prop))
'#define DIPROP_BUFFERSIZE       MAKEDIPROP(1)
'#define DIPROP_AXISMODE         MAKEDIPROP(2)

%DIPROPAXISMODE_ABS     = 0
%DIPROPAXISMODE_REL     = 1

'#define DIPROP_GRANULARITY      MAKEDIPROP(3)
'#define DIPROP_RANGE            MAKEDIPROP(4)
'#define DIPROP_DEADZONE         MAKEDIPROP(5)
'#define DIPROP_SATURATION       MAKEDIPROP(6)
'#define DIPROP_FFGAIN           MAKEDIPROP(7)
'#define DIPROP_FFLOAD           MAKEDIPROP(8)
'#define DIPROP_AUTOCENTER       MAKEDIPROP(9)

%DIPROPAUTOCENTER_OFF   = 0
%DIPROPAUTOCENTER_ON    = 1

'#define DIPROP_CALIBRATIONMODE  MAKEDIPROP(10)

%DIPROPCALIBRATIONMODE_COOKED   = 0
%DIPROPCALIBRATIONMODE_RAW      = 1

'#define DIPROP_CALIBRATION      MAKEDIPROP(11)
'#define DIPROP_GUIDANDPATH      MAKEDIPROP(12)
'#define DIPROP_INSTANCENAME     MAKEDIPROP(13)
'#define DIPROP_PRODUCTNAME      MAKEDIPROP(14)
'#define DIPROP_JOYSTICKID       MAKEDIPROP(15)
'#define DIPROP_GETPORTDISPLAYNAME       MAKEDIPROP(16)
'#define DIPROP_PHYSICALRANGE            MAKEDIPROP(18)
'#define DIPROP_LOGICALRANGE             MAKEDIPROP(19)
'#define DIPROP_KEYNAME                  MAKEDIPROP(20)
'#define DIPROP_CPOINTS                  MAKEDIPROP(21)
'#define DIPROP_APPDATA          MAKEDIPROP(22)
'#define DIPROP_SCANCODE         MAKEDIPROP(23)
'#define DIPROP_VIDPID           MAKEDIPROP(24)
'#define DIPROP_USERNAME         MAKEDIPROP(25)
'#define DIPROP_TYPENAME         MAKEDIPROP(26)

' // Size = 16 bytes
TYPE DIDEVICEOBJECTDATA_DX3 DWORD
   dwOfs       AS DWORD   ' DWORD
   dwData      AS DWORD   ' DWORD
   dwTimeStamp AS DWORD   ' DWORD
   dwSequence  AS DWORD   ' DWORD
END TYPE

' // Size = 20 bytes
TYPE DIDEVICEOBJECTDATA DWORD
   dwOfs       AS DWORD   ' DWORD
   dwData      AS DWORD   ' DWORD
   dwTimeStamp AS DWORD   ' DWORD
   dwSequence  AS DWORD   ' DWORD
'#if(DIRECTINPUT_VERSION >= 0x0800)
   uAppData    AS DWORD   ' UINT_PTR
'#endif /* DIRECTINPUT_VERSION >= 0x0800 */
END TYPE

%DIGDD_PEEK          = &H00000001???

'#define DISEQUENCE_COMPARE(dwSequence1, cmp, dwSequence2) \
'                        ((int)((dwSequence1) - (dwSequence2)) cmp 0)

%DISCL_EXCLUSIVE     = &H00000001???
%DISCL_NONEXCLUSIVE  = &H00000002???
%DISCL_FOREGROUND    = &H00000004???
%DISCL_BACKGROUND    = &H00000008???
%DISCL_NOWINKEY      = &H00000010???

' // Size = 560 bytes
TYPE DIDEVICEINSTANCE_DX3A DWORD
   dwSize          AS DWORD                ' DWORD
   guidInstance    AS GUID                 ' GUID
   guidProduct     AS GUID                 ' GUID
   dwDevType       AS DWORD                ' DWORD
   tszInstanceName AS ASCIIZ * %MAX_PATH   ' CHAR[MAX_PATH]
   tszProductName  AS ASCIIZ * %MAX_PATH   ' CHAR[MAX_PATH]
END TYPE

' // Size = 1080 bytes
TYPE DIDEVICEINSTANCE_DX3W
   dwSize          AS DWORD                  ' DWORD
   guidInstance    AS GUID                   ' GUID
   guidProduct     AS GUID                   ' GUID
   dwDevType       AS DWORD                  ' DWORD
   tszInstanceName AS WSTRINGZ * %MAX_PATH   ' WCHAR[MAX_PATH]
   tszProductName  AS WSTRINGZ * %MAX_PATH   ' WCHAR[MAX_PATH]
END TYPE

#IF %DEF(%UNICODE)
   MACRO DIDEVICEINSTANCE_DX3 = DIDEVICEINSTANCE_DX3W
#ELSE
   MACRO DIDEVICEINSTANCE_DX3 = DIDEVICEINSTANCE_DX3A
#ENDIF

' // Size = 580 bytes
TYPE DIDEVICEINSTANCEA WORD
   dwSize          AS DWORD                ' DWORD
   guidInstance    AS GUID                 ' GUID
   guidProduct     AS GUID                 ' GUID
   dwDevType       AS DWORD                ' DWORD
   tszInstanceName AS ASCIIZ * %MAX_PATH   ' CHAR[MAX_PATH]
   tszProductName  AS ASCIIZ * %MAX_PATH   ' CHAR[MAX_PATH]
'#if(DIRECTINPUT_VERSION >= 0x0500)
   guidFFDriver    AS GUID                 ' GUID
   wUsagePage      AS WORD                 ' WORD
   wUsage          AS WORD                 ' WORD
'#endif /* DIRECTINPUT_VERSION >= 0x0500 */
END TYPE

' // Size = 1100 bytes
TYPE DIDEVICEINSTANCEW WORD
   dwSize          AS DWORD                  ' DWORD
   guidInstance    AS GUID                   ' GUID
   guidProduct     AS GUID                   ' GUID
   dwDevType       AS DWORD                  ' DWORD
   tszInstanceName AS WSTRINGZ * %MAX_PATH   ' WCHAR[MAX_PATH]
   tszProductName  AS WSTRINGZ * %MAX_PATH   ' WCHAR[MAX_PATH]
   guidFFDriver    AS GUID                   ' GUID
   wUsagePage      AS WORD                   ' WORD
   wUsage          AS WORD                   ' WORD
END TYPE

#IF %DEF(%UNICODE)
   MACRO DIDEVICEINSTANCE = DIDEVICEINSTANCEW
#ELSE
   MACRO DIDEVICEINSTANCE = DIDEVICEINSTANCEA
#ENDIF

' ########################################################################################
' IDirectInputDeviceW interface
' IID = 5944E681-C92E-11CF-BFC7-444553540000
' Inherited interface = IUnknown
' ########################################################################################

INTERFACE IDirectInputDeviceW $IID_IDirectInputDeviceW

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetCapabilities ( _                           ' VTable offset = 12
     BYREF lpDIDevCaps AS DIDEVCAPS _                   ' __out LPDIDEVCAPS lpDIDevCaps
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumObjects ( _                               ' VTable offset = 16
     BYVAL lpCallback AS DWORD _                        ' __in LPDIENUMDEVICEOBJECTSCALLBACKW lpCallback
   , BYVAL pvRef AS DWORD _                             ' __in LPVOID pvRef
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetProperty ( _                               ' VTable offset = 20
     BYREF rguidProp AS GUID _                          ' __in  REFGUID rguidProp
   , BYREF pdiph AS DIPROPHEADER _                      ' __out LPDIPROPHEADER pdiph
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetProperty ( _                               ' VTable offset = 24
     BYREF rguidProp AS GUID _                          ' __in REFGUID rguidProp
   , BYREF pdiph AS DIPROPHEADER _                      ' __in LPDIPROPHEADER pdiph
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Acquire ( _                                   ' VTable offset = 28
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Unacquire ( _                                 ' VTable offset = 32
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDeviceState ( _                            ' VTable offset = 36
     BYVAL cbData AS DWORD _                            ' __in DWORD cbData
   , BYVAL lpvData AS DWORD _                           ' __in_out LPVOID lpvData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDeviceData ( _                             ' VTable offset = 40
     BYVAL cbObjectData AS DWORD _                      ' __in  DWORD cbObjectData
   , BYREF rgdod AS DIDEVICEOBJECTDATA _                ' __out LPDIDEVICEOBJECTDATA rgdod
   , BYREF pdwInOut AS DWORD _                          ' __out LPDWORD pdwInOut
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetDataFormat ( _                             ' VTable offset = 44
     BYREF lpdf AS DIDATAFORMAT _                       ' __in LPCDIDATAFORMAT lpdf
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetEventNotification ( _                      ' VTable offset = 48
     BYVAL hEvent AS DWORD _                            ' __in HANDLE hEvent
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetCooperativeLevel ( _                       ' VTable offset = 52
     BYVAL hwnd AS DWORD _                              ' __in HWND hwnd
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetObjectInfo ( _                             ' VTable offset = 56
     BYREF pdidoi AS DIDEVICEOBJECTINSTANCEW _          ' __out LPDIDEVICEOBJECTINSTANCEW pdidoi
   , BYVAL dwObj AS DWORD _                             ' __in DWORD dwObj
   , BYVAL dwHow AS DWORD _                             ' __in DWORD dwHow
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDeviceInfo ( _                             ' VTable offset = 60
     BYREF pdidi AS DIDEVICEINSTANCEW _                 ' __out LPDIDEVICEINSTANCEW pdidi
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RunControlPanel ( _                           ' VTable offset = 64
     BYVAL hwndOwner AS DWORD _                         ' __in HWND hwndOwner
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Initialize ( _                                ' VTable offset = 68
     BYVAL hinst AS DWORD _                             ' __in HINSTANCE hinst
   , BYVAL dwVersion AS DWORD _                         ' __in DWORD dwVersion
   , BYREF rguid AS GUID _                              ' __in REFGUID rguid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

' ########################################################################################
' IDirectInputDevice interface
' IID = 5944E680-C92E-11CF-BFC7-444553540000
' Inherited interface = IUnknown
' ########################################################################################

INTERFACE IDirectInputDevice $IID_IDirectInputDevice

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetCapabilities ( _                           ' VTable offset = 12
     BYREF lpDIDevCaps AS DIDEVCAPS _                   ' __out LPDIDEVCAPS lpDIDevCaps
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumObjects ( _                               ' VTable offset = 16
     BYVAL lpCallback AS DWORD _                        ' __in LPDIENUMDEVICEOBJECTSCALLBACKA lpCallback
   , BYVAL pvRef AS DWORD _                             ' __in LPVOID pvRef
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetProperty ( _                               ' VTable offset = 20
     BYREF rguidProp AS GUID _                          ' __in  REFGUID rguidProp
   , BYREF pdiph AS DIPROPHEADER _                      ' __out LPDIPROPHEADER pdiph
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetProperty ( _                               ' VTable offset = 24
     BYREF rguidProp AS GUID _                          ' __in REFGUID rguidProp
   , BYREF pdiph AS DIPROPHEADER _                      ' __in LPDIPROPHEADER pdiph
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Acquire ( _                                   ' VTable offset = 28
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Unacquire ( _                                 ' VTable offset = 32
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDeviceState ( _                            ' VTable offset = 36
     BYVAL cbData AS DWORD _                            ' __in DWORD cbData
   , BYVAL lpvData AS DWORD _                           ' __in_out LPVOID lpvData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDeviceData ( _                             ' VTable offset = 40
     BYVAL cbObjectData AS DWORD _                      ' __in  DWORD cbObjectData
   , BYREF rgdod AS DIDEVICEOBJECTDATA _                ' __out LPDIDEVICEOBJECTDATA rgdod
   , BYREF pdwInOut AS DWORD _                          ' __out LPDWORD pdwInOut
   , BYVAL dwFlags AS DWORD _                           ' __in  DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetDataFormat ( _                             ' VTable offset = 44
     BYREF lpdf AS DIDATAFORMAT _                       ' __in LPCDIDATAFORMAT lpdf
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetEventNotification ( _                      ' VTable offset = 48
     BYVAL hEvent AS DWORD _                            ' __in HANDLE hEvent
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetCooperativeLevel ( _                       ' VTable offset = 52
     BYVAL hwnd AS DWORD _                              ' __in HWND hwnd
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetObjectInfo ( _                             ' VTable offset = 56
     BYREF pdidoi AS DIDEVICEOBJECTINSTANCEA _          ' __out LPDIDEVICEOBJECTINSTANCEA pdidoi
   , BYVAL dwObj AS DWORD _                             ' __in  DWORD dwObj
   , BYVAL dwHow AS DWORD _                             ' __in  DWORD dwHow
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDeviceInfo ( _                             ' VTable offset = 60
     BYREF pdidi AS DIDEVICEINSTANCEA _                 ' __out LPDIDEVICEINSTANCEA pdidi
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RunControlPanel ( _                           ' VTable offset = 64
     BYVAL hwndOwner AS DWORD _                         ' __in HWND hwndOwner
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Initialize ( _                                ' VTable offset = 68
     BYVAL hinst AS DWORD _                             ' __in HINSTANCE hinst
   , BYVAL dwVersion AS DWORD _                         ' __in DWORD dwVersion
   , BYREF rguid AS GUID _                              ' __in REFGUID rguid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE


%DISFFC_RESET            = &H00000001???
%DISFFC_STOPALL          = &H00000002???
%DISFFC_PAUSE            = &H00000004???
%DISFFC_CONTINUE         = &H00000008???
%DISFFC_SETACTUATORSON   = &H00000010???
%DISFFC_SETACTUATORSOFF  = &H00000020???

%DIGFFS_EMPTY            = &H00000001???
%DIGFFS_STOPPED          = &H00000002???
%DIGFFS_PAUSED           = &H00000004???
%DIGFFS_ACTUATORSON      = &H00000010???
%DIGFFS_ACTUATORSOFF     = &H00000020???
%DIGFFS_POWERON          = &H00000040???
%DIGFFS_POWEROFF         = &H00000080???
%DIGFFS_SAFETYSWITCHON   = &H00000100???
%DIGFFS_SAFETYSWITCHOFF  = &H00000200???
%DIGFFS_USERFFSWITCHON   = &H00000400???
%DIGFFS_USERFFSWITCHOFF  = &H00000800???
%DIGFFS_DEVICELOST       = &H80000000???

' // Size = 292 bytes
TYPE DIEFFECTINFOA
   dwSize          AS DWORD                ' DWORD
   rguid           AS GUID                 ' GUID
   dwEffType       AS DWORD                ' DWORD
   dwStaticParams  AS DWORD                ' DWORD
   dwDynamicParams AS DWORD                ' DWORD
   tszName         AS ASCIIZ * %MAX_PATH   ' CHAR[MAX_PATH]
END TYPE

' // Size = 552 bytes
TYPE DIEFFECTINFOW DWORD
   dwSize          AS DWORD                  ' DWORD
   rguid           AS GUID                   ' GUID
   dwEffType       AS DWORD                  ' DWORD
   dwStaticParams  AS DWORD                  ' DWORD
   dwDynamicParams AS DWORD                  ' DWORD
   tszName         AS WSTRINGZ * %MAX_PATH   ' WCHAR[MAX_PATH]
END TYPE

#IF %DEF(%UNICODE)
   MACRO DIEFFECTINFO = DIEFFECTINFOW
#ELSE
   MACRO DIEFFECTINFO = DIEFFECTINFOA
#ENDIF

%DISDD_CONTINUE         = &H00000001???

' ########################################################################################
' IDirectInputDevice2W interface
' IID = 5944E683-C92E-11CF-BFC7-444553540000
' Inherited interface = IDirectInputDeviceW
' ########################################################################################

INTERFACE IDirectInputDevice2W $IID_IDirectInputDevice2W

   INHERIT IUnknown

   ' =====================================================================================
   ' IDirectInputDeviceW methods
   ' =====================================================================================
   METHOD GetCapabilities ( _                           ' VTable offset = 12
     BYREF lpDIDevCaps AS DIDEVCAPS _                   ' __out LPDIDEVCAPS lpDIDevCaps
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumObjects ( _                               ' VTable offset = 16
     BYVAL lpCallback AS DWORD _                        ' __in LPDIENUMDEVICEOBJECTSCALLBACKW lpCallback
   , BYVAL pvRef AS DWORD _                             ' __in LPVOID pvRef
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetProperty ( _                               ' VTable offset = 20
     BYREF rguidProp AS GUID _                          ' __in  REFGUID rguidProp
   , BYREF pdiph AS DIPROPHEADER _                      ' __out LPDIPROPHEADER pdiph
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetProperty ( _                               ' VTable offset = 24
     BYREF rguidProp AS GUID _                          ' __in REFGUID rguidProp
   , BYREF pdiph AS DIPROPHEADER _                      ' __in LPDIPROPHEADER pdiph
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Acquire ( _                                   ' VTable offset = 28
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Unacquire ( _                                 ' VTable offset = 32
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDeviceState ( _                            ' VTable offset = 36
     BYVAL cbData AS DWORD _                            ' __in DWORD cbData
   , BYVAL lpvData AS DWORD _                           ' __in_out LPVOID lpvData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDeviceData ( _                             ' VTable offset = 40
     BYVAL cbObjectData AS DWORD _                      ' __in  DWORD cbObjectData
   , BYREF rgdod AS DIDEVICEOBJECTDATA _                ' __out LPDIDEVICEOBJECTDATA rgdod
   , BYREF pdwInOut AS DWORD _                          ' __out LPDWORD pdwInOut
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetDataFormat ( _                             ' VTable offset = 44
     BYREF lpdf AS DIDATAFORMAT _                       ' __in LPCDIDATAFORMAT lpdf
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetEventNotification ( _                      ' VTable offset = 48
     BYVAL hEvent AS DWORD _                            ' __in HANDLE hEvent
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetCooperativeLevel ( _                       ' VTable offset = 52
     BYVAL hwnd AS DWORD _                              ' __in HWND hwnd
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetObjectInfo ( _                             ' VTable offset = 56
     BYREF pdidoi AS DIDEVICEOBJECTINSTANCEW _          ' __out LPDIDEVICEOBJECTINSTANCEW pdidoi
   , BYVAL dwObj AS DWORD _                             ' __in DWORD dwObj
   , BYVAL dwHow AS DWORD _                             ' __in DWORD dwHow
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDeviceInfo ( _                             ' VTable offset = 60
     BYREF pdidi AS DIDEVICEINSTANCEW _                 ' __out LPDIDEVICEINSTANCEW pdidi
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RunControlPanel ( _                           ' VTable offset = 64
     BYVAL hwndOwner AS DWORD _                         ' __in HWND hwndOwner
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Initialize ( _                                ' VTable offset = 68
     BYVAL hinst AS DWORD _                             ' __in HINSTANCE hinst
   , BYVAL dwVersion AS DWORD _                         ' __in DWORD dwVersion
   , BYREF rguid AS GUID _                              ' __in REFGUID rguid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IDirectInputDevice2W methods
   ' =====================================================================================
   METHOD CreateEffect ( _                              ' VTable offset = 72
     BYREF rguid AS GUID _                              ' __in  REFGUID rguid
   , BYREF lpeff AS DIEFFECT _                          ' __in  LPCDIEFFECT lpeff
   , BYREF ppdeff AS IDirectInputEffect _               ' __out LPDIRECTINPUTEFFECT * ppdeff
   , BYVAL punkOuter AS IUnknown _                      ' __in  LPUNKNOWN punkOuter
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumEffects ( _                               ' VTable offset = 76
     BYVAL lpCallback AS DWORD _                        ' __in LPDIENUMEFFECTSCALLBACKW lpCallback
   , BYVAL pvRef AS DWORD _                             ' __in LPVOID pvRef
   , BYVAL dwEffType AS DWORD _                         ' __in DWORD dwEffType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetEffectInfo ( _                             ' VTable offset = 80
     BYREF pdei AS DIEFFECTINFOW _                      ' __out LPDIEFFECTINFOW pdei
   , BYREF rguid AS GUID _                              ' __in  REFGUID rguid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetForceFeedbackState ( _                     ' VTable offset = 84
     BYREF pdwOut AS DWORD _                            ' __out LPDWORD pdwOut
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SendForceFeedbackCommand ( _                  ' VTable offset = 88
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumCreatedEffectObjects ( _                  ' VTable offset = 92
     BYVAL lpCallback AS DWORD _                        ' __in LPDIENUMCREATEDEFFECTOBJECTSCALLBACK lpCallback
   , BYVAL pvRef AS DWORD _                             ' __in LPVOID pvRef
   , BYVAL fl AS DWORD _                                ' __in DWORD fl
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Escape ( _                                    ' VTable offset = 96
     BYREF pesc AS DIEFFESCAPE _                        ' __in LPDIEFFESCAPE pesc
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Poll ( _                                      ' VTable offset = 100
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SendDeviceData ( _                            ' VTable offset = 104
     BYVAL cbObjectData AS DWORD _                      ' __in  DWORD cbObjectData
   , BYREF rgdod AS DIDEVICEOBJECTDATA _                ' __in  LPCDIDEVICEOBJECTDATA rgdod
   , BYREF pdwInOut AS DWORD _                          ' __out LPDWORD pdwInOut
   , BYVAL fl AS DWORD _                                ' __in  DWORD fl
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

' ########################################################################################
' IDirectInputDevice2 interface
' IID = 5944E682-C92E-11CF-BFC7-444553540000
' Inherited interface = IDirectInputDevice
' ########################################################################################

INTERFACE IDirectInputDevice2 $IID_IDirectInputDevice2A

   INHERIT IUnknown

   ' =====================================================================================
   ' IDirectInputDevice methods
   ' =====================================================================================
   METHOD GetCapabilities ( _                           ' VTable offset = 12
     BYREF lpDIDevCaps AS DIDEVCAPS _                   ' __out LPDIDEVCAPS lpDIDevCaps
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumObjects ( _                               ' VTable offset = 16
     BYVAL lpCallback AS DWORD _                        ' __in LPDIENUMDEVICEOBJECTSCALLBACKA lpCallback
   , BYVAL pvRef AS DWORD _                             ' __in LPVOID pvRef
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetProperty ( _                               ' VTable offset = 20
     BYREF rguidProp AS GUID _                          ' __in  REFGUID rguidProp
   , BYREF pdiph AS DIPROPHEADER _                      ' __out LPDIPROPHEADER pdiph
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetProperty ( _                               ' VTable offset = 24
     BYREF rguidProp AS GUID _                          ' __in REFGUID rguidProp
   , BYREF pdiph AS DIPROPHEADER _                      ' __in LPDIPROPHEADER pdiph
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Acquire ( _                                   ' VTable offset = 28
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Unacquire ( _                                 ' VTable offset = 32
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDeviceState ( _                            ' VTable offset = 36
     BYVAL cbData AS DWORD _                            ' __in DWORD cbData
   , BYVAL lpvData AS DWORD _                           ' __in_out LPVOID lpvData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDeviceData ( _                             ' VTable offset = 40
     BYVAL cbObjectData AS DWORD _                      ' __in  DWORD cbObjectData
   , BYREF rgdod AS DIDEVICEOBJECTDATA _                ' __out LPDIDEVICEOBJECTDATA rgdod
   , BYREF pdwInOut AS DWORD _                          ' __out LPDWORD pdwInOut
   , BYVAL dwFlags AS DWORD _                           ' __in  DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetDataFormat ( _                             ' VTable offset = 44
     BYREF lpdf AS DIDATAFORMAT _                       ' __in LPCDIDATAFORMAT lpdf
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetEventNotification ( _                      ' VTable offset = 48
     BYVAL hEvent AS DWORD _                            ' __in HANDLE hEvent
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetCooperativeLevel ( _                       ' VTable offset = 52
     BYVAL hwnd AS DWORD _                              ' __in HWND hwnd
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetObjectInfo ( _                             ' VTable offset = 56
     BYREF pdidoi AS DIDEVICEOBJECTINSTANCEA _          ' __out LPDIDEVICEOBJECTINSTANCEA pdidoi
   , BYVAL dwObj AS DWORD _                             ' __in  DWORD dwObj
   , BYVAL dwHow AS DWORD _                             ' __in  DWORD dwHow
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDeviceInfo ( _                             ' VTable offset = 60
     BYREF pdidi AS DIDEVICEINSTANCEA _                 ' __out LPDIDEVICEINSTANCEA pdidi
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RunControlPanel ( _                           ' VTable offset = 64
     BYVAL hwndOwner AS DWORD _                         ' __in HWND hwndOwner
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Initialize ( _                                ' VTable offset = 68
     BYVAL hinst AS DWORD _                             ' __in HINSTANCE hinst
   , BYVAL dwVersion AS DWORD _                         ' __in DWORD dwVersion
   , BYREF rguid AS GUID _                              ' __in REFGUID rguid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IDirectInputDevice2 methods
   ' =====================================================================================
   METHOD CreateEffect ( _                              ' VTable offset = 72
     BYREF rguid AS GUID _                              ' __in REFGUID rguid
   , BYREF lpeff AS DIEFFECT _                          ' __in LPCDIEFFECT lpeff
   , BYREF ppdeff AS IDirectInputEffect _               ' __in LPDIRECTINPUTEFFECT * ppdeff
   , BYVAL punkOuter AS IUnknown _                      ' __in LPUNKNOWN punkOuter
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumEffects ( _                               ' VTable offset = 76
     BYVAL lpCallback AS DWORD _                        ' __in LPDIENUMEFFECTSCALLBACK lpCallback
   , BYVAL pvRef AS DWORD _                             ' __in LPVOID pvRef
   , BYVAL dwEffType AS DWORD _                         ' __in DWORD dwEffType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetEffectInfo ( _                             ' VTable offset = 80
     BYREF pdei AS DIEFFECTINFOA _                      ' __out LPDIEFFECTINFOA pdei
   , BYREF rguid AS GUID _                              ' __in  REFGUID rguid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetForceFeedbackState ( _                     ' VTable offset = 84
     BYREF pdwOut AS DWORD _                            ' __out LPDWORD pdwOut
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SendForceFeedbackCommand ( _                  ' VTable offset = 88
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumCreatedEffectObjects ( _                  ' VTable offset = 92
     BYVAL lpCallback AS DWORD _                        ' __in LPDIENUMCREATEDEFFECTOBJECTSCALLBACK lpCallback
   , BYVAL pvRef AS DWORD _                             ' __in LPVOID pvRef
   , BYVAL fl AS DWORD _                                ' __in DWORD fl
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Escape ( _                                    ' VTable offset = 96
     BYREF pesc AS DIEFFESCAPE _                        ' __in LPDIEFFESCAPE pesc
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Poll ( _                                      ' VTable offset = 100
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SendDeviceData ( _                            ' VTable offset = 104
     BYVAL cbObjectData AS DWORD _                      ' __in  DWORD cbObjectData
   , BYREF rgdod AS DIDEVICEOBJECTDATA _                ' __in  LPCDIDEVICEOBJECTDATA rgdod
   , BYREF pdwInOut AS DWORD _                          ' __out LPDWORD pdwInOut
   , BYVAL fl AS DWORD _                                ' __in  DWORD fl
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE


%DIFEF_DEFAULT               = &H00000000???
%DIFEF_INCLUDENONSTANDARD    = &H00000001???
%DIFEF_MODIFYIFNEEDED        = &H00000010???

' ########################################################################################
' IDirectInputDevice7W interface
' IID = 57D7C6BD-2356-11D3-8E9D-00C04F6844AE
' Inherited interface = IDirectInputDeviceW
' ########################################################################################

INTERFACE IDirectInputDevice7W $IID_IDirectInputDevice7W

   INHERIT IUnknown

   ' =====================================================================================
   ' IDirectInputDeviceW methods
   ' =====================================================================================
   METHOD GetCapabilities ( _                           ' VTable offset = 12
     BYREF lpDIDevCaps AS DIDEVCAPS _                   ' __out LPDIDEVCAPS lpDIDevCaps
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumObjects ( _                               ' VTable offset = 16
     BYVAL lpCallback AS DWORD _                        ' __in LPDIENUMDEVICEOBJECTSCALLBACKW lpCallback
   , BYVAL pvRef AS DWORD _                             ' __in LPVOID pvRef
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetProperty ( _                               ' VTable offset = 20
     BYREF rguidProp AS GUID _                          ' __in  REFGUID rguidProp
   , BYREF pdiph AS DIPROPHEADER _                      ' __out LPDIPROPHEADER pdiph
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetProperty ( _                               ' VTable offset = 24
     BYREF rguidProp AS GUID _                          ' __in REFGUID rguidProp
   , BYREF pdiph AS DIPROPHEADER _                      ' __in LPDIPROPHEADER pdiph
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Acquire ( _                                   ' VTable offset = 28
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Unacquire ( _                                 ' VTable offset = 32
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDeviceState ( _                            ' VTable offset = 36
     BYVAL cbData AS DWORD _                            ' __in DWORD cbData
   , BYVAL lpvData AS DWORD _                           ' __in_out LPVOID lpvData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDeviceData ( _                             ' VTable offset = 40
     BYVAL cbObjectData AS DWORD _                      ' __in  DWORD cbObjectData
   , BYREF rgdod AS DIDEVICEOBJECTDATA _                ' __out LPDIDEVICEOBJECTDATA rgdod
   , BYREF pdwInOut AS DWORD _                          ' __out LPDWORD pdwInOut
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetDataFormat ( _                             ' VTable offset = 44
     BYREF lpdf AS DIDATAFORMAT _                       ' __in LPCDIDATAFORMAT lpdf
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetEventNotification ( _                      ' VTable offset = 48
     BYVAL hEvent AS DWORD _                            ' __in HANDLE hEvent
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetCooperativeLevel ( _                       ' VTable offset = 52
     BYVAL hwnd AS DWORD _                              ' __in HWND hwnd
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetObjectInfo ( _                             ' VTable offset = 56
     BYREF pdidoi AS DIDEVICEOBJECTINSTANCEW _          ' __out LPDIDEVICEOBJECTINSTANCEW pdidoi
   , BYVAL dwObj AS DWORD _                             ' __in DWORD dwObj
   , BYVAL dwHow AS DWORD _                             ' __in DWORD dwHow
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDeviceInfo ( _                             ' VTable offset = 60
     BYREF pdidi AS DIDEVICEINSTANCEW _                 ' __out LPDIDEVICEINSTANCEW pdidi
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RunControlPanel ( _                           ' VTable offset = 64
     BYVAL hwndOwner AS DWORD _                         ' __in HWND hwndOwner
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Initialize ( _                                ' VTable offset = 68
     BYVAL hinst AS DWORD _                             ' __in HINSTANCE hinst
   , BYVAL dwVersion AS DWORD _                         ' __in DWORD dwVersion
   , BYREF rguid AS GUID _                              ' __in REFGUID rguid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IDirectInputDevice2W methods
   ' =====================================================================================
   METHOD CreateEffect ( _                              ' VTable offset = 72
     BYREF rguid AS GUID _                              ' __in  REFGUID rguid
   , BYREF lpeff AS DIEFFECT _                          ' __in  LPCDIEFFECT lpeff
   , BYREF ppdeff AS IDirectInputEffect _               ' __out LPDIRECTINPUTEFFECT * ppdeff
   , BYVAL punkOuter AS IUnknown _                      ' __in  LPUNKNOWN punkOuter
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumEffects ( _                               ' VTable offset = 76
     BYVAL lpCallback AS DWORD _                        ' __in LPDIENUMEFFECTSCALLBACKW lpCallback
   , BYVAL pvRef AS DWORD _                             ' __in LPVOID pvRef
   , BYVAL dwEffType AS DWORD _                         ' __in DWORD dwEffType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetEffectInfo ( _                             ' VTable offset = 80
     BYREF pdei AS DIEFFECTINFOW _                      ' __out LPDIEFFECTINFOW pdei
   , BYREF rguid AS GUID _                              ' __in  REFGUID rguid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetForceFeedbackState ( _                     ' VTable offset = 84
     BYREF pdwOut AS DWORD _                            ' __out LPDWORD pdwOut
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SendForceFeedbackCommand ( _                  ' VTable offset = 88
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumCreatedEffectObjects ( _                  ' VTable offset = 92
     BYVAL lpCallback AS DWORD _                        ' __in LPDIENUMCREATEDEFFECTOBJECTSCALLBACK lpCallback
   , BYVAL pvRef AS DWORD _                             ' __in LPVOID pvRef
   , BYVAL fl AS DWORD _                                ' __in DWORD fl
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Escape ( _                                    ' VTable offset = 96
     BYREF pesc AS DIEFFESCAPE _                        ' __in LPDIEFFESCAPE pesc
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Poll ( _                                      ' VTable offset = 100
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SendDeviceData ( _                            ' VTable offset = 104
     BYVAL cbObjectData AS DWORD _                      ' __in  DWORD cbObjectData
   , BYREF rgdod AS DIDEVICEOBJECTDATA _                ' __in  LPCDIDEVICEOBJECTDATA rgdod
   , BYREF pdwInOut AS DWORD _                          ' __out LPDWORD pdwInOut
   , BYVAL fl AS DWORD _                                ' __in  DWORD fl
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IDirectInputDevice7W methods
   ' =====================================================================================
   METHOD EnumEffectsInFile ( _                         ' VTable offset = 108
     BYREF lpszFileName AS WSTRINGZ _                   ' __in LPCWSTR lpszFileName
   , BYVAL pec AS DWORD _                               ' __in LPENUMEFFECTSINFILECALLBACK pec
   , BYVAL pvRef AS DWORD _                             ' __in LPVOID pvRef
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD WriteEffectToFile ( _                         ' VTable offset = 112
     BYREF lpszFileName AS WSTRINGZ _                   ' __in LPCWSTR lpszFileName
   , BYVAL dwEntries AS DWORD _                         ' __in DWORD dwEntries
   , BYREF rgDiFileEft AS DIFILEEFFECT _                ' __in LPCDIFILEEFFECT rgDiFileEft
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

' ########################################################################################
' IDirectInputDevice7 interface
' IID = 57D7C6BC-2356-11D3-8E9D-00C04F6844AE
' Inherited interface = IDirectInputDevice
' ########################################################################################

INTERFACE IDirectInputDevice7 $IID_IDirectInputDevice7

   INHERIT IUnknown

   ' =====================================================================================
   ' IDirectInputDevice methods
   ' =====================================================================================
   METHOD GetCapabilities ( _                           ' VTable offset = 12
     BYREF lpDIDevCaps AS DIDEVCAPS _                   ' __out LPDIDEVCAPS lpDIDevCaps
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumObjects ( _                               ' VTable offset = 16
     BYVAL lpCallback AS DWORD _                        ' __in LPDIENUMDEVICEOBJECTSCALLBACKA lpCallback
   , BYVAL pvRef AS DWORD _                             ' __in LPVOID pvRef
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetProperty ( _                               ' VTable offset = 20
     BYREF rguidProp AS GUID _                          ' __in  REFGUID rguidProp
   , BYREF pdiph AS DIPROPHEADER _                      ' __out LPDIPROPHEADER pdiph
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetProperty ( _                               ' VTable offset = 24
     BYREF rguidProp AS GUID _                          ' __in REFGUID rguidProp
   , BYREF pdiph AS DIPROPHEADER _                      ' __in LPDIPROPHEADER pdiph
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Acquire ( _                                   ' VTable offset = 28
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Unacquire ( _                                 ' VTable offset = 32
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDeviceState ( _                            ' VTable offset = 36
     BYVAL cbData AS DWORD _                            ' __in DWORD cbData
   , BYVAL lpvData AS DWORD _                           ' __in_out LPVOID lpvData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDeviceData ( _                             ' VTable offset = 40
     BYVAL cbObjectData AS DWORD _                      ' __in  DWORD cbObjectData
   , BYREF rgdod AS DIDEVICEOBJECTDATA _                ' __out LPDIDEVICEOBJECTDATA rgdod
   , BYREF pdwInOut AS DWORD _                          ' __out LPDWORD pdwInOut
   , BYVAL dwFlags AS DWORD _                           ' __in  DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetDataFormat ( _                             ' VTable offset = 44
     BYREF lpdf AS DIDATAFORMAT _                       ' __in LPCDIDATAFORMAT lpdf
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetEventNotification ( _                      ' VTable offset = 48
     BYVAL hEvent AS DWORD _                            ' __in HANDLE hEvent
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetCooperativeLevel ( _                       ' VTable offset = 52
     BYVAL hwnd AS DWORD _                              ' __in HWND hwnd
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetObjectInfo ( _                             ' VTable offset = 56
     BYREF pdidoi AS DIDEVICEOBJECTINSTANCEA _          ' __out LPDIDEVICEOBJECTINSTANCEA pdidoi
   , BYVAL dwObj AS DWORD _                             ' __in  DWORD dwObj
   , BYVAL dwHow AS DWORD _                             ' __in  DWORD dwHow
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDeviceInfo ( _                             ' VTable offset = 60
     BYREF pdidi AS DIDEVICEINSTANCEA _                 ' __out LPDIDEVICEINSTANCEA pdidi
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RunControlPanel ( _                           ' VTable offset = 64
     BYVAL hwndOwner AS DWORD _                         ' __in HWND hwndOwner
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Initialize ( _                                ' VTable offset = 68
     BYVAL hinst AS DWORD _                             ' __in HINSTANCE hinst
   , BYVAL dwVersion AS DWORD _                         ' __in DWORD dwVersion
   , BYREF rguid AS GUID _                              ' __in REFGUID rguid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IDirectInputDevice2 methods
   ' =====================================================================================
   METHOD CreateEffect ( _                              ' VTable offset = 72
     BYREF rguid AS GUID _                              ' __in REFGUID rguid
   , BYREF lpeff AS DIEFFECT _                          ' __in LPCDIEFFECT lpeff
   , BYREF ppdeff AS IDirectInputEffect _               ' __in LPDIRECTINPUTEFFECT * ppdeff
   , BYVAL punkOuter AS IUnknown _                      ' __in LPUNKNOWN punkOuter
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumEffects ( _                               ' VTable offset = 76
     BYVAL lpCallback AS DWORD _                        ' __in LPDIENUMEFFECTSCALLBACK lpCallback
   , BYVAL pvRef AS DWORD _                             ' __in LPVOID pvRef
   , BYVAL dwEffType AS DWORD _                         ' __in DWORD dwEffType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetEffectInfo ( _                             ' VTable offset = 80
     BYREF pdei AS DIEFFECTINFOA _                      ' __out LPDIEFFECTINFOA pdei
   , BYREF rguid AS GUID _                              ' __in  REFGUID rguid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetForceFeedbackState ( _                     ' VTable offset = 84
     BYREF pdwOut AS DWORD _                            ' __out LPDWORD pdwOut
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SendForceFeedbackCommand ( _                  ' VTable offset = 88
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumCreatedEffectObjects ( _                  ' VTable offset = 92
     BYVAL lpCallback AS DWORD _                        ' __in LPDIENUMCREATEDEFFECTOBJECTSCALLBACK lpCallback
   , BYVAL pvRef AS DWORD _                             ' __in LPVOID pvRef
   , BYVAL fl AS DWORD _                                ' __in DWORD fl
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Escape ( _                                    ' VTable offset = 96
     BYREF pesc AS DIEFFESCAPE _                        ' __in LPDIEFFESCAPE pesc
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Poll ( _                                      ' VTable offset = 100
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SendDeviceData ( _                            ' VTable offset = 104
     BYVAL cbObjectData AS DWORD _                      ' __in  DWORD cbObjectData
   , BYREF rgdod AS DIDEVICEOBJECTDATA _                ' __in  LPCDIDEVICEOBJECTDATA rgdod
   , BYREF pdwInOut AS DWORD _                          ' __out LPDWORD pdwInOut
   , BYVAL fl AS DWORD _                                ' __in  DWORD fl
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IDirectInputDevice7A methods
   ' =====================================================================================
   METHOD EnumEffectsInFile ( _                         ' VTable offset = 108
     BYREF lpszFileName AS ASCIIZ _                     ' __in LPCSTR lpszFileName
   , BYVAL pec AS DWORD _                               ' __in LPENUMEFFECTSINFILECALLBACK pec
   , BYVAL pvRef AS DWORD _                             ' __in LPVOID pvRef
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD WriteEffectToFile ( _                         ' VTable offset = 112
     BYREF lpszFileName AS ASCIIZ _                     ' __in LPCSTR lpszFileName
   , BYVAL dwEntries AS DWORD _                         ' __in DWORD dwEntries
   , BYREF rgDiFileEft AS DIFILEEFFECT _                ' __in LPCDIFILEEFFECT rgDiFileEft
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

' ########################################################################################
' IDirectInputDevice8W interface
' IID = 54D41081-DC15-4833-A41B-748F73A38179
' Inherited interface = IDirectInputDeviceW
' ########################################################################################

INTERFACE IDirectInputDevice8W $IID_IDirectInputDevice8W

   INHERIT IUnknown

   ' =====================================================================================
   ' IDirectInputDeviceW methods
   ' =====================================================================================
   METHOD GetCapabilities ( _                           ' VTable offset = 12
     BYREF lpDIDevCaps AS DIDEVCAPS _                   ' __out LPDIDEVCAPS lpDIDevCaps
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumObjects ( _                               ' VTable offset = 16
     BYVAL lpCallback AS DWORD _                        ' __in LPDIENUMDEVICEOBJECTSCALLBACKW lpCallback
   , BYVAL pvRef AS DWORD _                             ' __in LPVOID pvRef
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetProperty ( _                               ' VTable offset = 20
     BYREF rguidProp AS GUID _                          ' __in  REFGUID rguidProp
   , BYREF pdiph AS DIPROPHEADER _                      ' __out LPDIPROPHEADER pdiph
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetProperty ( _                               ' VTable offset = 24
     BYREF rguidProp AS GUID _                          ' __in REFGUID rguidProp
   , BYREF pdiph AS DIPROPHEADER _                      ' __in LPDIPROPHEADER pdiph
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Acquire ( _                                   ' VTable offset = 28
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Unacquire ( _                                 ' VTable offset = 32
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDeviceState ( _                            ' VTable offset = 36
     BYVAL cbData AS DWORD _                            ' __in DWORD cbData
   , BYVAL lpvData AS DWORD _                           ' __in_out LPVOID lpvData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDeviceData ( _                             ' VTable offset = 40
     BYVAL cbObjectData AS DWORD _                      ' __in  DWORD cbObjectData
   , BYREF rgdod AS DIDEVICEOBJECTDATA _                ' __out LPDIDEVICEOBJECTDATA rgdod
   , BYREF pdwInOut AS DWORD _                          ' __out LPDWORD pdwInOut
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetDataFormat ( _                             ' VTable offset = 44
     BYREF lpdf AS DIDATAFORMAT _                       ' __in LPCDIDATAFORMAT lpdf
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetEventNotification ( _                      ' VTable offset = 48
     BYVAL hEvent AS DWORD _                            ' __in HANDLE hEvent
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetCooperativeLevel ( _                       ' VTable offset = 52
     BYVAL hwnd AS DWORD _                              ' __in HWND hwnd
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetObjectInfo ( _                             ' VTable offset = 56
     BYREF pdidoi AS DIDEVICEOBJECTINSTANCEW _          ' __out LPDIDEVICEOBJECTINSTANCEW pdidoi
   , BYVAL dwObj AS DWORD _                             ' __in DWORD dwObj
   , BYVAL dwHow AS DWORD _                             ' __in DWORD dwHow
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDeviceInfo ( _                             ' VTable offset = 60
     BYREF pdidi AS DIDEVICEINSTANCEW _                 ' __out LPDIDEVICEINSTANCEW pdidi
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RunControlPanel ( _                           ' VTable offset = 64
     BYVAL hwndOwner AS DWORD _                         ' __in HWND hwndOwner
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Initialize ( _                                ' VTable offset = 68
     BYVAL hinst AS DWORD _                             ' __in HINSTANCE hinst
   , BYVAL dwVersion AS DWORD _                         ' __in DWORD dwVersion
   , BYREF rguid AS GUID _                              ' __in REFGUID rguid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IDirectInputDevice2W methods
   ' =====================================================================================
   METHOD CreateEffect ( _                              ' VTable offset = 72
     BYREF rguid AS GUID _                              ' __in  REFGUID rguid
   , BYREF lpeff AS DIEFFECT _                          ' __in  LPCDIEFFECT lpeff
   , BYREF ppdeff AS IDirectInputEffect _               ' __out LPDIRECTINPUTEFFECT * ppdeff
   , BYVAL punkOuter AS IUnknown _                      ' __in  LPUNKNOWN punkOuter
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumEffects ( _                               ' VTable offset = 76
     BYVAL lpCallback AS DWORD _                        ' __in LPDIENUMEFFECTSCALLBACKW lpCallback
   , BYVAL pvRef AS DWORD _                             ' __in LPVOID pvRef
   , BYVAL dwEffType AS DWORD _                         ' __in DWORD dwEffType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetEffectInfo ( _                             ' VTable offset = 80
     BYREF pdei AS DIEFFECTINFOW _                      ' __out LPDIEFFECTINFOW pdei
   , BYREF rguid AS GUID _                              ' __in  REFGUID rguid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetForceFeedbackState ( _                     ' VTable offset = 84
     BYREF pdwOut AS DWORD _                            ' __out LPDWORD pdwOut
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SendForceFeedbackCommand ( _                  ' VTable offset = 88
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumCreatedEffectObjects ( _                  ' VTable offset = 92
     BYVAL lpCallback AS DWORD _                        ' __in LPDIENUMCREATEDEFFECTOBJECTSCALLBACK lpCallback
   , BYVAL pvRef AS DWORD _                             ' __in LPVOID pvRef
   , BYVAL fl AS DWORD _                                ' __in DWORD fl
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Escape ( _                                    ' VTable offset = 96
     BYREF pesc AS DIEFFESCAPE _                        ' __in LPDIEFFESCAPE pesc
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Poll ( _                                      ' VTable offset = 100
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SendDeviceData ( _                            ' VTable offset = 104
     BYVAL cbObjectData AS DWORD _                      ' __in  DWORD cbObjectData
   , BYREF rgdod AS DIDEVICEOBJECTDATA _                ' __in  LPCDIDEVICEOBJECTDATA rgdod
   , BYREF pdwInOut AS DWORD _                          ' __out LPDWORD pdwInOut
   , BYVAL fl AS DWORD _                                ' __in  DWORD fl
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IDirectInputDevice7W methods
   ' =====================================================================================
   METHOD EnumEffectsInFile ( _                         ' VTable offset = 108
     BYREF lpszFileName AS WSTRINGZ _                   ' __in LPCWSTR lpszFileName
   , BYVAL pec AS DWORD _                               ' __in LPENUMEFFECTSINFILECALLBACK pec
   , BYVAL pvRef AS DWORD _                             ' __in LPVOID pvRef
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD WriteEffectToFile ( _                         ' VTable offset = 112
     BYREF lpszFileName AS WSTRINGZ _                   ' __in LPCWSTR lpszFileName
   , BYVAL dwEntries AS DWORD _                         ' __in DWORD dwEntries
   , BYREF rgDiFileEft AS DIFILEEFFECT _                ' __in LPCDIFILEEFFECT rgDiFileEft
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IDirectInputDevice8W methods
   ' =====================================================================================
   METHOD BuildActionMap ( _                            ' VTable offset = 116
     BYREF lpdiaf AS DIACTIONFORMATW _                  ' __in LPDIACTIONFORMATW lpdiaf
   , BYREF lpszUserName AS WSTRINGZ _                   ' __in LPCWSTR lpszUserName
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetActionMap ( _                              ' VTable offset = 120
     BYREF lpdiActionFormat AS DIACTIONFORMATW _        ' __in LPCDIACTIONFORMATW lpdiActionFormat
   , BYREF lpszUserName AS WSTRINGZ _                   ' __in LPCWSTR lptszUserName
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetImageInfo ( _                              ' VTable offset = 124
     BYREF lpdiDevImageInfoHeader AS DIDEVICEIMAGEINFOHEADER _ ' __out LPDIDEVICEIMAGEINFOHEADER lpdiDevImageInfoHeader
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

' ########################################################################################
' IDirectInputDevice8 interface
' IID = 54D41080-DC15-4833-A41B-748F73A38179
' Inherited interface = IDirectInputDevice
' ########################################################################################

INTERFACE IDirectInputDevice8 $IID_IDirectInputDevice8

   INHERIT IUnknown

   ' =====================================================================================
   ' IDirectInputDevice methods
   ' =====================================================================================
   METHOD GetCapabilities ( _                           ' VTable offset = 12
     BYREF lpDIDevCaps AS DIDEVCAPS _                   ' __out LPDIDEVCAPS lpDIDevCaps
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumObjects ( _                               ' VTable offset = 16
     BYVAL lpCallback AS DWORD _                        ' __in LPDIENUMDEVICEOBJECTSCALLBACKA lpCallback
   , BYVAL pvRef AS DWORD _                             ' __in LPVOID pvRef
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetProperty ( _                               ' VTable offset = 20
     BYREF rguidProp AS GUID _                          ' __in  REFGUID rguidProp
   , BYREF pdiph AS DIPROPHEADER _                      ' __out LPDIPROPHEADER pdiph
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetProperty ( _                               ' VTable offset = 24
     BYREF rguidProp AS GUID _                          ' __in REFGUID rguidProp
   , BYREF pdiph AS DIPROPHEADER _                      ' __in LPDIPROPHEADER pdiph
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Acquire ( _                                   ' VTable offset = 28
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Unacquire ( _                                 ' VTable offset = 32
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDeviceState ( _                            ' VTable offset = 36
     BYVAL cbData AS DWORD _                            ' __in DWORD cbData
   , BYVAL lpvData AS DWORD _                           ' __in_out LPVOID lpvData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDeviceData ( _                             ' VTable offset = 40
     BYVAL cbObjectData AS DWORD _                      ' __in  DWORD cbObjectData
   , BYREF rgdod AS DIDEVICEOBJECTDATA _                ' __out LPDIDEVICEOBJECTDATA rgdod
   , BYREF pdwInOut AS DWORD _                          ' __out LPDWORD pdwInOut
   , BYVAL dwFlags AS DWORD _                           ' __in  DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetDataFormat ( _                             ' VTable offset = 44
     BYREF lpdf AS DIDATAFORMAT _                       ' __in LPCDIDATAFORMAT lpdf
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetEventNotification ( _                      ' VTable offset = 48
     BYVAL hEvent AS DWORD _                            ' __in HANDLE hEvent
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetCooperativeLevel ( _                       ' VTable offset = 52
     BYVAL hwnd AS DWORD _                              ' __in HWND hwnd
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetObjectInfo ( _                             ' VTable offset = 56
     BYREF pdidoi AS DIDEVICEOBJECTINSTANCEA _          ' __out LPDIDEVICEOBJECTINSTANCEA pdidoi
   , BYVAL dwObj AS DWORD _                             ' __in  DWORD dwObj
   , BYVAL dwHow AS DWORD _                             ' __in  DWORD dwHow
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDeviceInfo ( _                             ' VTable offset = 60
     BYREF pdidi AS DIDEVICEINSTANCEA _                 ' __out LPDIDEVICEINSTANCEA pdidi
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RunControlPanel ( _                           ' VTable offset = 64
     BYVAL hwndOwner AS DWORD _                         ' __in HWND hwndOwner
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Initialize ( _                                ' VTable offset = 68
     BYVAL hinst AS DWORD _                             ' __in HINSTANCE hinst
   , BYVAL dwVersion AS DWORD _                         ' __in DWORD dwVersion
   , BYREF rguid AS GUID _                              ' __in REFGUID rguid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IDirectInputDevice2 methods
   ' =====================================================================================
   METHOD CreateEffect ( _                              ' VTable offset = 72
     BYREF rguid AS GUID _                              ' __in REFGUID rguid
   , BYREF lpeff AS DIEFFECT _                          ' __in LPCDIEFFECT lpeff
   , BYREF ppdeff AS IDirectInputEffect _               ' __in LPDIRECTINPUTEFFECT * ppdeff
   , BYVAL punkOuter AS IUnknown _                      ' __in LPUNKNOWN punkOuter
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumEffects ( _                               ' VTable offset = 76
     BYVAL lpCallback AS DWORD _                        ' __in LPDIENUMEFFECTSCALLBACK lpCallback
   , BYVAL pvRef AS DWORD _                             ' __in LPVOID pvRef
   , BYVAL dwEffType AS DWORD _                         ' __in DWORD dwEffType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetEffectInfo ( _                             ' VTable offset = 80
     BYREF pdei AS DIEFFECTINFOA _                      ' __out LPDIEFFECTINFOA pdei
   , BYREF rguid AS GUID _                              ' __in  REFGUID rguid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetForceFeedbackState ( _                     ' VTable offset = 84
     BYREF pdwOut AS DWORD _                            ' __out LPDWORD pdwOut
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SendForceFeedbackCommand ( _                  ' VTable offset = 88
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumCreatedEffectObjects ( _                  ' VTable offset = 92
     BYVAL lpCallback AS DWORD _                        ' __in LPDIENUMCREATEDEFFECTOBJECTSCALLBACK lpCallback
   , BYVAL pvRef AS DWORD _                             ' __in LPVOID pvRef
   , BYVAL fl AS DWORD _                                ' __in DWORD fl
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Escape ( _                                    ' VTable offset = 96
     BYREF pesc AS DIEFFESCAPE _                        ' __in LPDIEFFESCAPE pesc
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Poll ( _                                      ' VTable offset = 100
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SendDeviceData ( _                            ' VTable offset = 104
     BYVAL cbObjectData AS DWORD _                      ' __in  DWORD cbObjectData
   , BYREF rgdod AS DIDEVICEOBJECTDATA _                ' __in  LPCDIDEVICEOBJECTDATA rgdod
   , BYREF pdwInOut AS DWORD _                          ' __out LPDWORD pdwInOut
   , BYVAL fl AS DWORD _                                ' __in  DWORD fl
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IDirectInputDevice7A methods
   ' =====================================================================================
   METHOD EnumEffectsInFile ( _                         ' VTable offset = 108
     BYREF lpszFileName AS ASCIIZ _                     ' __in LPCSTR lpszFileName
   , BYVAL pec AS DWORD _                               ' __in LPENUMEFFECTSINFILECALLBACK pec
   , BYVAL pvRef AS DWORD _                             ' __in LPVOID pvRef
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD WriteEffectToFile ( _                         ' VTable offset = 112
     BYREF lpszFileName AS ASCIIZ _                     ' __in LPCSTR lpszFileName
   , BYVAL dwEntries AS DWORD _                         ' __in DWORD dwEntries
   , BYREF rgDiFileEft AS DIFILEEFFECT _                ' __in LPCDIFILEEFFECT rgDiFileEft
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IDirectInputDevice8A methods
   ' =====================================================================================
   METHOD BuildActionMap ( _                            ' VTable offset = 116
     BYREF lpdiaf AS DIACTIONFORMATA _                  ' __in LPDIACTIONFORMATA lpdiaf
   , BYREF lpszUserName AS ASCIIZ _                     ' __in LPCSTR lpszUserName
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetActionMap ( _                              ' VTable offset = 120
     BYREF lpdiActionFormat AS DIACTIONFORMATA _        ' __in LPCDIACTIONFORMATA lpdiActionFormat
   , BYREF lpszUserName AS ASCIIZ _                     ' __in LPCSTR lptszUserName
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetImageInfo ( _                              ' VTable offset = 124
     BYREF lpdiDevImageInfoHeader AS DIDEVICEIMAGEINFOHEADER _ ' __out LPDIDEVICEIMAGEINFOHEADER lpdiDevImageInfoHeader
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE


'/****************************************************************************
' *
' *      Mouse
' *
' ****************************************************************************/

' // Size = 16 bytes
TYPE DIMOUSESTATE DWORD
   lX            AS LONG   ' LONG
   lY            AS LONG   ' LONG
   lZ            AS LONG   ' LONG
   rgbButtons(3) AS BYTE   ' BYTE[4]
END TYPE

' // Size = 20 bytes
TYPE DIMOUSESTATE2 DWORD
   lX            AS LONG   ' LONG
   lY            AS LONG   ' LONG
   lZ            AS LONG   ' LONG
   rgbButtons(7) AS BYTE   ' BYTE[8]
END TYPE

'#define DIMOFS_X        FIELD_OFFSET(DIMOUSESTATE, lX)
'#define DIMOFS_Y        FIELD_OFFSET(DIMOUSESTATE, lY)
'#define DIMOFS_Z        FIELD_OFFSET(DIMOUSESTATE, lZ)
'#define DIMOFS_BUTTON0 (FIELD_OFFSET(DIMOUSESTATE, rgbButtons) + 0)
'#define DIMOFS_BUTTON1 (FIELD_OFFSET(DIMOUSESTATE, rgbButtons) + 1)
'#define DIMOFS_BUTTON2 (FIELD_OFFSET(DIMOUSESTATE, rgbButtons) + 2)
'#define DIMOFS_BUTTON3 (FIELD_OFFSET(DIMOUSESTATE, rgbButtons) + 3)
'#define DIMOFS_BUTTON4 (FIELD_OFFSET(DIMOUSESTATE2, rgbButtons) + 4)
'#define DIMOFS_BUTTON5 (FIELD_OFFSET(DIMOUSESTATE2, rgbButtons) + 5)
'#define DIMOFS_BUTTON6 (FIELD_OFFSET(DIMOUSESTATE2, rgbButtons) + 6)
'#define DIMOFS_BUTTON7 (FIELD_OFFSET(DIMOUSESTATE2, rgbButtons) + 7)

%DIMOFS_X       = 0
%DIMOFS_Y       = 4
%DIMOFS_Z       = 8
%DIMOFS_BUTTON0 = 12
%DIMOFS_BUTTON1 = 13
%DIMOFS_BUTTON2 = 14
%DIMOFS_BUTTON3 = 15
%DIMOFS_BUTTON4 = 16
%DIMOFS_BUTTON5 = 17
%DIMOFS_BUTTON6 = 18
%DIMOFS_BUTTON7 = 19

'/****************************************************************************
' *
' *      Keyboard
' *
' ****************************************************************************/

'/****************************************************************************
' *
' *      DirectInput keyboard scan codes
' *
' ****************************************************************************/

%DIK_ESCAPE          = &H01?
%DIK_1               = &H02?
%DIK_2               = &H03?
%DIK_3               = &H04?
%DIK_4               = &H05?
%DIK_5               = &H06?
%DIK_6               = &H07?
%DIK_7               = &H08?
%DIK_8               = &H09?
%DIK_9               = &H0A?
%DIK_0               = &H0B?
%DIK_MINUS           = &H0C?   ' /* - on main keyboard */
%DIK_EQUALS          = &H0D?
%DIK_BACK            = &H0E?   ' /* backspace */
%DIK_TAB             = &H0F?
%DIK_Q               = &H10?
%DIK_W               = &H11?
%DIK_E               = &H12?
%DIK_R               = &H13?
%DIK_T               = &H14?
%DIK_Y               = &H15?
%DIK_U               = &H16?
%DIK_I               = &H17?
%DIK_O               = &H18?
%DIK_P               = &H19?
%DIK_LBRACKET        = &H1A?
%DIK_RBRACKET        = &H1B?
%DIK_RETURN          = &H1C?   ' /* Enter on main keyboard */
%DIK_LCONTROL        = &H1D?
%DIK_A               = &H1E?
%DIK_S               = &H1F?
%DIK_D               = &H20?
%DIK_F               = &H21?
%DIK_G               = &H22?
%DIK_H               = &H23?
%DIK_J               = &H24?
%DIK_K               = &H25?
%DIK_L               = &H26?
%DIK_SEMICOLON       = &H27?
%DIK_APOSTROPHE      = &H28?
%DIK_GRAVE           = &H29?   ' /* accent grave */
%DIK_LSHIFT          = &H2A?
%DIK_BACKSLASH       = &H2B?
%DIK_Z               = &H2C?
%DIK_X               = &H2D?
%DIK_C               = &H2E?
%DIK_V               = &H2F?
%DIK_B               = &H30?
%DIK_N               = &H31?
%DIK_M               = &H32?
%DIK_COMMA           = &H33?
%DIK_PERIOD          = &H34?   ' /* . on main keyboard */
%DIK_SLASH           = &H35?   ' /* / on main keyboard */
%DIK_RSHIFT          = &H36?
%DIK_MULTIPLY        = &H37?   ' /* * on numeric keypad */
%DIK_LMENU           = &H38?   ' /* left Alt */
%DIK_SPACE           = &H39?
%DIK_CAPITAL         = &H3A?
%DIK_F1              = &H3B?
%DIK_F2              = &H3C?
%DIK_F3              = &H3D?
%DIK_F4              = &H3E?
%DIK_F5              = &H3F?
%DIK_F6              = &H40?
%DIK_F7              = &H41?
%DIK_F8              = &H42?
%DIK_F9              = &H43?
%DIK_F10             = &H44?
%DIK_NUMLOCK         = &H45?
%DIK_SCROLL          = &H46?   ' /* Scroll Lock */
%DIK_NUMPAD7         = &H47?
%DIK_NUMPAD8         = &H48?
%DIK_NUMPAD9         = &H49?
%DIK_SUBTRACT        = &H4A?   ' /* - on numeric keypad */
%DIK_NUMPAD4         = &H4B?
%DIK_NUMPAD5         = &H4C?
%DIK_NUMPAD6         = &H4D?
%DIK_ADD             = &H4E?   ' /* + on numeric keypad */
%DIK_NUMPAD1         = &H4F?
%DIK_NUMPAD2         = &H50?
%DIK_NUMPAD3         = &H51?
%DIK_NUMPAD0         = &H52?
%DIK_DECIMAL         = &H53?   ' /* . on numeric keypad */
%DIK_OEM_102         = &H56?   ' /* <> or \| on RT 102-key keyboard (Non-U.S.) */
%DIK_F11             = &H57?
%DIK_F12             = &H58?
%DIK_F13             = &H64?   ' /*                     (NEC PC98) */
%DIK_F14             = &H65?   ' /*                     (NEC PC98) */
%DIK_F15             = &H66?   ' /*                     (NEC PC98) */
%DIK_KANA            = &H70?   ' /* (Japanese keyboard)            */
%DIK_ABNT_C1         = &H73?   ' /* /? on Brazilian keyboard */
%DIK_CONVERT         = &H79?   ' /* (Japanese keyboard)            */
%DIK_NOCONVERT       = &H7B?   ' /* (Japanese keyboard)            */
%DIK_YEN             = &H7D?   ' /* (Japanese keyboard)            */
%DIK_ABNT_C2         = &H7E?   ' /* Numpad . on Brazilian keyboard */
%DIK_NUMPADEQUALS    = &H8D?   ' /* = on numeric keypad (NEC PC98) */
%DIK_PREVTRACK       = &H90?   ' /* Previous Track (DIK_CIRCUMFLEX on Japanese keyboard) */
%DIK_AT              = &H91?   ' /*                     (NEC PC98) */
%DIK_COLON           = &H92?   ' /*                     (NEC PC98) */
%DIK_UNDERLINE       = &H93?   ' /*                     (NEC PC98) */
%DIK_KANJI           = &H94?   ' /* (Japanese keyboard)            */
%DIK_STOP            = &H95?   ' /*                     (NEC PC98) */
%DIK_AX              = &H96?   ' /*                     (Japan AX) */
%DIK_UNLABELED       = &H97?   ' /*                        (J3100) */
%DIK_NEXTTRACK       = &H99?   ' /* Next Track */
%DIK_NUMPADENTER     = &H9C?   ' /* Enter on numeric keypad */
%DIK_RCONTROL        = &H9D?
%DIK_MUTE            = &HA0?   ' /* Mute */
%DIK_CALCULATOR      = &HA1?   ' /* Calculator */
%DIK_PLAYPAUSE       = &HA2?   ' /* Play / Pause */
%DIK_MEDIASTOP       = &HA4?   ' /* Media Stop */
%DIK_VOLUMEDOWN      = &HAE?   ' /* Volume - */
%DIK_VOLUMEUP        = &HB0?   ' /* Volume + */
%DIK_WEBHOME         = &HB2?   ' /* Web home */
%DIK_NUMPADCOMMA     = &HB3?   ' /* , on numeric keypad (NEC PC98) */
%DIK_DIVIDE          = &HB5?   ' /* / on numeric keypad */
%DIK_SYSRQ           = &HB7?
%DIK_RMENU           = &HB8?   ' /* right Alt */
%DIK_PAUSE           = &HC5?   ' /* Pause */
%DIK_HOME            = &HC7?   ' /* Home on arrow keypad */
%DIK_UP              = &HC8?   ' /* UpArrow on arrow keypad */
%DIK_PRIOR           = &HC9?   ' /* PgUp on arrow keypad */
%DIK_LEFT            = &HCB?   ' /* LeftArrow on arrow keypad */
%DIK_RIGHT           = &HCD?   ' /* RightArrow on arrow keypad */
%DIK_END             = &HCF?   ' /* End on arrow keypad */
%DIK_DOWN            = &HD0?   ' /* DownArrow on arrow keypad */
%DIK_NEXT            = &HD1?   ' /* PgDn on arrow keypad */
%DIK_INSERT          = &HD2?   ' /* Insert on arrow keypad */
%DIK_DELETE          = &HD3?   ' /* Delete on arrow keypad */
%DIK_LWIN            = &HDB?   ' /* Left Windows key */
%DIK_RWIN            = &HDC?   ' /* Right Windows key */
%DIK_APPS            = &HDD?   ' /* AppMenu key */
%DIK_POWER           = &HDE?   ' /* System Power */
%DIK_SLEEP           = &HDF?   ' /* System Sleep */
%DIK_WAKE            = &HE3?   ' /* System Wake */
%DIK_WEBSEARCH       = &HE5?   ' /* Web Search */
%DIK_WEBFAVORITES    = &HE6?   ' /* Web Favorites */
%DIK_WEBREFRESH      = &HE7?   ' /* Web Refresh */
%DIK_WEBSTOP         = &HE8?   ' /* Web Stop */
%DIK_WEBFORWARD      = &HE9?   ' /* Web Forward */
%DIK_WEBBACK         = &HEA?   ' /* Web Back */
%DIK_MYCOMPUTER      = &HEB?   ' /* My Computer */
%DIK_MAIL            = &HEC?   ' /* Mail */
%DIK_MEDIASELECT     = &HED?   ' /* Media Select */

'/*
' *  Alternate names for keys, to facilitate transition from DOS.
' */

%DIK_BACKSPACE       = %DIK_BACK           ' /* backspace */
%DIK_NUMPADSTAR      = %DIK_MULTIPLY       ' /* * on numeric keypad */
%DIK_LALT            = %DIK_LMENU          ' /* left Alt */
%DIK_CAPSLOCK        = %DIK_CAPITAL        ' /* CapsLock */
%DIK_NUMPADMINUS     = %DIK_SUBTRACT       ' /* - on numeric keypad */
%DIK_NUMPADPLUS      = %DIK_ADD            ' /* + on numeric keypad */
%DIK_NUMPADPERIOD    = %DIK_DECIMAL        ' /* . on numeric keypad */
%DIK_NUMPADSLASH     = %DIK_DIVIDE         ' /* / on numeric keypad */
%DIK_RALT            = %DIK_RMENU          ' /* right Alt */
%DIK_UPARROW         = %DIK_UP             ' /* UpArrow on arrow keypad */
%DIK_PGUP            = %DIK_PRIOR          ' /* PgUp on arrow keypad */
%DIK_LEFTARROW       = %DIK_LEFT           ' /* LeftArrow on arrow keypad */
%DIK_RIGHTARROW      = %DIK_RIGHT          ' /* RightArrow on arrow keypad */
%DIK_DOWNARROW       = %DIK_DOWN           ' /* DownArrow on arrow keypad */
%DIK_PGDN            = %DIK_NEXT           ' /* PgDn on arrow keypad */

'/*
' *  Alternate names for keys originally not used on US keyboards.
' */
%DIK_CIRCUMFLEX      = %DIK_PREVTRACK      ' /* Japanese keyboard */


'/****************************************************************************
' *
' *      Joystick
' *
' ****************************************************************************/

' // Size = 80 bytes
TYPE DIJOYSTATE DWORD
   lX             AS LONG    ' LONG /* x-axis position              */
   lY             AS LONG    ' LONG /* y-axis position              */
   lZ             AS LONG    ' LONG /* z-axis position              */
   lRx            AS LONG    ' LONG /* x-axis rotation              */
   lRy            AS LONG    ' LONG /* y-axis rotation              */
   lRz            AS LONG    ' LONG /* z-axis rotation              */
   rglSlider(1)   AS LONG    ' LONG[2] /* extra axes positions      */
   rgdwPOV(3)     AS DWORD   ' DWORD[4] /* POV directions           */
   rgbButtons(31) AS BYTE    ' BYTE[32] /* 32 buttons               */
END TYPE

' // Size = 272 bytes
TYPE DIJOYSTATE2 DWORD
   lX              AS LONG    ' LONG /* x-axis position              */
   lY              AS LONG    ' LONG /* y-axis position              */
   lZ              AS LONG    ' LONG /* z-axis position              */
   lRx             AS LONG    ' LONG /* x-axis rotation              */
   lRy             AS LONG    ' LONG /* y-axis rotation              */
   lRz             AS LONG    ' LONG /* z-axis rotation              */
   rglSlider(1)    AS LONG    ' LONG[2] /* extra axes positions      */
   rgdwPOV(3)      AS DWORD   ' DWORD[4] /* POV directions           */
   rgbButtons(127) AS BYTE    ' BYTE[128] /* 128 buttons             */
   lVX             AS LONG    ' LONG /* x-axis velocity              */
   lVY             AS LONG    ' LONG /* y-axis velocity              */
   lVZ             AS LONG    ' LONG /* z-axis velocity              */
   lVRx            AS LONG    ' LONG /* x-axis angular velocity      */
   lVRy            AS LONG    ' LONG /* y-axis angular velocity      */
   lVRz            AS LONG    ' LONG /* z-axis angular velocity      */
   rglVSlider(1)   AS LONG    ' LONG[2] /* extra axes velocities     */
   lAX             AS LONG    ' LONG /* x-axis acceleration          */
   lAY             AS LONG    ' LONG /* y-axis acceleration          */
   lAZ             AS LONG    ' LONG /* z-axis acceleration          */
   lARx            AS LONG    ' LONG /* x-axis angular acceleration  */
   lARy            AS LONG    ' LONG /* y-axis angular acceleration  */
   lARz            AS LONG    ' LONG /* z-axis angular acceleration  */
   rglASlider(1)   AS LONG    ' LONG[2] /* extra axes accelerations  */
   lFX             AS LONG    ' LONG /* x-axis force                 */
   lFY             AS LONG    ' LONG /* y-axis force                 */
   lFZ             AS LONG    ' LONG /* z-axis force                 */
   lFRx            AS LONG    ' LONG /* x-axis torque                */
   lFRy            AS LONG    ' LONG /* y-axis torque                */
   lFRz            AS LONG    ' LONG /* z-axis torque                */
   rglFSlider(1)   AS LONG    ' LONG[2] /* extra axes forces         */
END TYPE

'#define DIJOFS_X            FIELD_OFFSET(DIJOYSTATE, lX)
'#define DIJOFS_Y            FIELD_OFFSET(DIJOYSTATE, lY)
'#define DIJOFS_Z            FIELD_OFFSET(DIJOYSTATE, lZ)
'#define DIJOFS_RX           FIELD_OFFSET(DIJOYSTATE, lRx)
'#define DIJOFS_RY           FIELD_OFFSET(DIJOYSTATE, lRy)
'#define DIJOFS_RZ           FIELD_OFFSET(DIJOYSTATE, lRz)

%DIJOFS_X  = 0
%DIJOFS_Y  = 4
%DIJOFS_Z  = 8
%DIJOFS_RX = 12
%DIJOFS_RY = 16
%DIJOFS_RZ = 20

'#define DIJOFS_SLIDER(n)   (FIELD_OFFSET(DIJOYSTATE, rglSlider) + \
'                                                        (n) * sizeof(LONG))
'#define DIJOFS_POV(n)      (FIELD_OFFSET(DIJOYSTATE, rgdwPOV) + \
'                                                        (n) * sizeof(DWORD))
'#define DIJOFS_BUTTON(n)   (FIELD_OFFSET(DIJOYSTATE, rgbButtons) + (n))

'#define DIJOFS_BUTTON0      DIJOFS_BUTTON(0)
'#define DIJOFS_BUTTON1      DIJOFS_BUTTON(1)
'#define DIJOFS_BUTTON2      DIJOFS_BUTTON(2)
'#define DIJOFS_BUTTON3      DIJOFS_BUTTON(3)
'#define DIJOFS_BUTTON4      DIJOFS_BUTTON(4)
'#define DIJOFS_BUTTON5      DIJOFS_BUTTON(5)
'#define DIJOFS_BUTTON6      DIJOFS_BUTTON(6)
'#define DIJOFS_BUTTON7      DIJOFS_BUTTON(7)
'#define DIJOFS_BUTTON8      DIJOFS_BUTTON(8)
'#define DIJOFS_BUTTON9      DIJOFS_BUTTON(9)
'#define DIJOFS_BUTTON10     DIJOFS_BUTTON(10)
'#define DIJOFS_BUTTON11     DIJOFS_BUTTON(11)
'#define DIJOFS_BUTTON12     DIJOFS_BUTTON(12)
'#define DIJOFS_BUTTON13     DIJOFS_BUTTON(13)
'#define DIJOFS_BUTTON14     DIJOFS_BUTTON(14)
'#define DIJOFS_BUTTON15     DIJOFS_BUTTON(15)
'#define DIJOFS_BUTTON16     DIJOFS_BUTTON(16)
'#define DIJOFS_BUTTON17     DIJOFS_BUTTON(17)
'#define DIJOFS_BUTTON18     DIJOFS_BUTTON(18)
'#define DIJOFS_BUTTON19     DIJOFS_BUTTON(19)
'#define DIJOFS_BUTTON20     DIJOFS_BUTTON(20)
'#define DIJOFS_BUTTON21     DIJOFS_BUTTON(21)
'#define DIJOFS_BUTTON22     DIJOFS_BUTTON(22)
'#define DIJOFS_BUTTON23     DIJOFS_BUTTON(23)
'#define DIJOFS_BUTTON24     DIJOFS_BUTTON(24)
'#define DIJOFS_BUTTON25     DIJOFS_BUTTON(25)
'#define DIJOFS_BUTTON26     DIJOFS_BUTTON(26)
'#define DIJOFS_BUTTON27     DIJOFS_BUTTON(27)
'#define DIJOFS_BUTTON28     DIJOFS_BUTTON(28)
'#define DIJOFS_BUTTON29     DIJOFS_BUTTON(29)
'#define DIJOFS_BUTTON30     DIJOFS_BUTTON(30)
'#define DIJOFS_BUTTON31     DIJOFS_BUTTON(31)

%DIJOFS_BUTTONB  = 48
%DIJOFS_BUTTON0  = %DIJOFS_BUTTONB + 0
%DIJOFS_BUTTON1  = %DIJOFS_BUTTONB + 1
%DIJOFS_BUTTON2  = %DIJOFS_BUTTONB + 2
%DIJOFS_BUTTON3  = %DIJOFS_BUTTONB + 3
%DIJOFS_BUTTON4  = %DIJOFS_BUTTONB + 4
%DIJOFS_BUTTON5  = %DIJOFS_BUTTONB + 5
%DIJOFS_BUTTON6  = %DIJOFS_BUTTONB + 6
%DIJOFS_BUTTON7  = %DIJOFS_BUTTONB + 7
%DIJOFS_BUTTON8  = %DIJOFS_BUTTONB + 8
%DIJOFS_BUTTON9  = %DIJOFS_BUTTONB + 9
%DIJOFS_BUTTON10 = %DIJOFS_BUTTONB + 10
%DIJOFS_BUTTON11 = %DIJOFS_BUTTONB + 11
%DIJOFS_BUTTON12 = %DIJOFS_BUTTONB + 12
%DIJOFS_BUTTON13 = %DIJOFS_BUTTONB + 13
%DIJOFS_BUTTON14 = %DIJOFS_BUTTONB + 14
%DIJOFS_BUTTON15 = %DIJOFS_BUTTONB + 15
%DIJOFS_BUTTON16 = %DIJOFS_BUTTONB + 16
%DIJOFS_BUTTON17 = %DIJOFS_BUTTONB + 17
%DIJOFS_BUTTON18 = %DIJOFS_BUTTONB + 18
%DIJOFS_BUTTON19 = %DIJOFS_BUTTONB + 19
%DIJOFS_BUTTON20 = %DIJOFS_BUTTONB + 20
%DIJOFS_BUTTON21 = %DIJOFS_BUTTONB + 21
%DIJOFS_BUTTON22 = %DIJOFS_BUTTONB + 22
%DIJOFS_BUTTON23 = %DIJOFS_BUTTONB + 23
%DIJOFS_BUTTON24 = %DIJOFS_BUTTONB + 24
%DIJOFS_BUTTON25 = %DIJOFS_BUTTONB + 25
%DIJOFS_BUTTON26 = %DIJOFS_BUTTONB + 26
%DIJOFS_BUTTON27 = %DIJOFS_BUTTONB + 27
%DIJOFS_BUTTON28 = %DIJOFS_BUTTONB + 28
%DIJOFS_BUTTON29 = %DIJOFS_BUTTONB + 29
%DIJOFS_BUTTON30 = %DIJOFS_BUTTONB + 30
%DIJOFS_BUTTON31 = %DIJOFS_BUTTONB + 31

'/****************************************************************************
' *
' *  IDirectInput
' *
' ****************************************************************************/

%DIENUM_STOP            = 0
%DIENUM_CONTINUE        = 1

%DIEDFL_ALLDEVICES           = &H00000000???
%DIEDFL_ATTACHEDONLY         = &H00000001???
%DIEDFL_FORCEFEEDBACK        = &H00000100???
%DIEDFL_INCLUDEALIASES       = &H00010000???
%DIEDFL_INCLUDEPHANTOMS      = &H00020000???
%DIEDFL_INCLUDEHIDDEN        = &H00040000???

%DIEDBS_MAPPEDPRI1           = &H00000001???
%DIEDBS_MAPPEDPRI2           = &H00000002???
%DIEDBS_RECENTDEVICE         = &H00000010???
%DIEDBS_NEWDEVICE            = &H00000020???

%DIEDBSFL_ATTACHEDONLY       = &H00000000???
%DIEDBSFL_THISUSER           = &H00000010???
%DIEDBSFL_FORCEFEEDBACK      = %DIEDFL_FORCEFEEDBACK
%DIEDBSFL_AVAILABLEDEVICES   = &H00001000???
%DIEDBSFL_MULTIMICEKEYBOARDS = &H00002000???
%DIEDBSFL_NONGAMINGDEVICES   = &H00004000???
%DIEDBSFL_VALID              = &H00007110???

' ########################################################################################
' IDirectInputW interface
' IID = 89521361-AA8A-11CF-BFC7-444553540000
' Inherited interface = IUnknown
' ########################################################################################

INTERFACE IDirectInputW $IID_IDirectInputW

   INHERIT IUnknown

   ' =====================================================================================
   METHOD CreateDevice ( _                              ' VTable offset = 12
     BYREF rguid AS GUID _                              ' __in  REFGUID rguid
   , BYREF lplpDirectInputDevice AS IDirectInputDeviceW _ ' __out LPDIRECTINPUTDEVICEW * lplpDirectInputDevice
   , BYVAL pUnkOuter AS IUnknown _                      ' __in  LPUNKNOWN pUnkOuter
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumDevices ( _                               ' VTable offset = 16
     BYVAL dwDevType AS DWORD _                         ' __in DWORD dwDevType
   , BYVAL lpCallback AS DWORD _                        ' __in LPDIENUMDEVICESCALLBACKW lpCallback
   , BYVAL pvRef AS DWORD _                             ' __in LPVOID pvRef
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDeviceStatus ( _                           ' VTable offset = 20
     BYREF rguidInstance AS GUID _                      ' __in REFGUID rguidInstance
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RunControlPanel ( _                           ' VTable offset = 24
     BYVAL hwndOwner AS DWORD _                         ' __in HWND hwndOwner
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Initialize ( _                                ' VTable offset = 28
     BYVAL hinst AS DWORD _                             ' __in HINSTANCE hinst
   , BYVAL dwVersion AS DWORD _                         ' __in DWORD dwVersion
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

' ########################################################################################
' IDirectInput interface
' IID = 89521360-AA8A-11CF-BFC7-444553540000
' Inherited interface = IUnknown
' ########################################################################################

INTERFACE IDirectInput $IID_IDirectInput

   INHERIT IUnknown

   ' =====================================================================================
   METHOD CreateDevice ( _                              ' VTable offset = 12
     BYREF rguid AS GUID _                              ' __in  REFGUID rguid
   , BYREF lplpDirectInputDevice AS IDirectInputDevice _ ' __out LPDIRECTINPUTDEVICEA * lplpDirectInputDevice
   , BYVAL pUnkOuter AS IUnknown _                      ' __in  LPUNKNOWN pUnkOuter
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumDevices ( _                               ' VTable offset = 16
     BYVAL dwDevType AS DWORD _                         ' __in DWORD dwDevType
   , BYVAL lpCallback AS DWORD _                        ' __in LPDIENUMDEVICESCALLBACKA lpCallback
   , BYVAL pvRef AS DWORD _                             ' __in LPVOID pvRef
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDeviceStatus ( _                           ' VTable offset = 20
     BYREF rguidInstance AS GUID _                      ' __in REFGUID rguidInstance
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RunControlPanel ( _                           ' VTable offset = 24
     BYVAL hwndOwner AS DWORD _                         ' __in HWND hwndOwner
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Initialize ( _                                ' VTable offset = 28
     BYVAL hinst AS DWORD _                             ' __in HINSTANCE hinst
   , BYVAL dwVersion AS DWORD _                         ' __in DWORD dwVersion
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

' ########################################################################################
' IDirectInput2W interface
' IID = 5944E663-AA8A-11CF-BFC7-444553540000
' Inherited interface = IDirectInputW
' ########################################################################################

INTERFACE IDirectInput2W $IID_IDirectInput2W

   INHERIT IUnknown

   ' =====================================================================================
   ' IDirectInputW mehods
   ' =====================================================================================
   METHOD CreateDevice ( _                              ' VTable offset = 12
     BYREF rguid AS GUID _                              ' __in  REFGUID rguid
   , BYREF lplpDirectInputDevice AS IDirectInputDeviceW _ ' __out LPDIRECTINPUTDEVICEW * lplpDirectInputDevice
   , BYVAL pUnkOuter AS IUnknown _                      ' __in  LPUNKNOWN pUnkOuter
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumDevices ( _                               ' VTable offset = 16
     BYVAL dwDevType AS DWORD _                         ' __in DWORD dwDevType
   , BYVAL lpCallback AS DWORD _                        ' __in LPDIENUMDEVICESCALLBACKW lpCallback
   , BYVAL pvRef AS DWORD _                             ' __in LPVOID pvRef
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDeviceStatus ( _                           ' VTable offset = 20
     BYREF rguidInstance AS GUID _                      ' __in REFGUID rguidInstance
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RunControlPanel ( _                           ' VTable offset = 24
     BYVAL hwndOwner AS DWORD _                         ' __in HWND hwndOwner
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Initialize ( _                                ' VTable offset = 28
     BYVAL hinst AS DWORD _                             ' __in HINSTANCE hinst
   , BYVAL dwVersion AS DWORD _                         ' __in DWORD dwVersion
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IDirectInput2W mehods
   ' =====================================================================================
   METHOD FindDevice ( _                                ' VTable offset = 32
     BYREF rguidClass AS GUID _                         ' __in  REFGUID rguidClass
   , BYREF ptszName AS WSTRINGZ _                       ' __in  LPCWSTR ptszName
   , BYREF pguidInstance AS GUID _                      ' __out LPGUID pguidInstance
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

' ########################################################################################
' IDirectInput2 interface
' IID = 5944E662-AA8A-11CF-BFC7-444553540000
' Inherited interface = IDirectInput
' ########################################################################################

INTERFACE IDirectInput2 $IID_IDirectInput2

   INHERIT IUnknown

   ' =====================================================================================
   ' IDirectInput mehods
   ' =====================================================================================
   METHOD CreateDevice ( _                              ' VTable offset = 12
     BYREF rguid AS GUID _                              ' __in  REFGUID rguid
   , BYREF lplpDirectInputDevice AS IDirectInputDevice _ ' __out LPDIRECTINPUTDEVICEA * lplpDirectInputDevice
   , BYVAL pUnkOuter AS IUnknown _                      ' __in  LPUNKNOWN pUnkOuter
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumDevices ( _                               ' VTable offset = 16
     BYVAL dwDevType AS DWORD _                         ' __in DWORD dwDevType
   , BYVAL lpCallback AS DWORD _                        ' __in LPDIENUMDEVICESCALLBACKA lpCallback
   , BYVAL pvRef AS DWORD _                             ' __in LPVOID pvRef
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDeviceStatus ( _                           ' VTable offset = 20
     BYREF rguidInstance AS GUID _                      ' __in REFGUID rguidInstance
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RunControlPanel ( _                           ' VTable offset = 24
     BYVAL hwndOwner AS DWORD _                         ' __in HWND hwndOwner
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Initialize ( _                                ' VTable offset = 28
     BYVAL hinst AS DWORD _                             ' __in HINSTANCE hinst
   , BYVAL dwVersion AS DWORD _                         ' __in DWORD dwVersion
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IDirectInput2 mehods
   ' =====================================================================================
   METHOD FindDevice ( _                                ' VTable offset = 32
     BYREF rguidClass AS GUID _                         ' __in  REFGUID rguidClass
   , BYREF ptszName AS ASCIIZ _                         ' __in  LPCSTR ptszName
   , BYREF pguidInstance AS GUID _                      ' __out LPGUID pguidInstance
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

' ########################################################################################
' IDirectInput8W interface
' IID = BF798031-483A-4DA2-AA99-5D64ED369700
' Inherited interface = IDirectInputW
' ########################################################################################

INTERFACE IDirectInput8W $IID_IDirectInput8W

   INHERIT IUnknown

   ' =====================================================================================
   ' IDirectInputW mehods
   ' =====================================================================================
   METHOD CreateDevice ( _                              ' VTable offset = 12
     BYREF rguid AS GUID _                              ' __in  REFGUID rguid
   , BYREF lplpDirectInputDevice AS IDirectInputDeviceW _ ' __out LPDIRECTINPUTDEVICEW * lplpDirectInputDevice
   , BYVAL pUnkOuter AS IUnknown _                      ' __in  LPUNKNOWN pUnkOuter
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumDevices ( _                               ' VTable offset = 16
     BYVAL dwDevType AS DWORD _                         ' __in DWORD dwDevType
   , BYVAL lpCallback AS DWORD _                        ' __in LPDIENUMDEVICESCALLBACKW lpCallback
   , BYVAL pvRef AS DWORD _                             ' __in LPVOID pvRef
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDeviceStatus ( _                           ' VTable offset = 20
     BYREF rguidInstance AS GUID _                      ' __in REFGUID rguidInstance
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RunControlPanel ( _                           ' VTable offset = 24
     BYVAL hwndOwner AS DWORD _                         ' __in HWND hwndOwner
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Initialize ( _                                ' VTable offset = 28
     BYVAL hinst AS DWORD _                             ' __in HINSTANCE hinst
   , BYVAL dwVersion AS DWORD _                         ' __in DWORD dwVersion
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IDirectInput2W mehods
   ' =====================================================================================
   METHOD FindDevice ( _                                ' VTable offset = 32
     BYREF rguidClass AS GUID _                         ' __in  REFGUID rguidClass
   , BYREF ptszName AS WSTRINGZ _                       ' __in  LPCWSTR ptszName
   , BYREF pguidInstance AS GUID _                      ' __out LPGUID pguidInstance
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IDirectInput8W mehods
   ' =====================================================================================
   METHOD EnumDevicesBySemantics ( _                    ' VTable offset = 36
     BYREF ptszUserName AS WSTRINGZ _                   ' __in LPCWSTR ptszUserName
   , BYREF lpdiActionFormat AS DIACTIONFORMATW _        ' __in LPDIACTIONFORMATW lpdiActionFormat
   , BYVAL lpCallback AS DWORD _                        ' __in LPDIENUMDEVICESBYSEMANTICSCBW lpCallback
   , BYVAL pvRef AS DWORD _                             ' __in LPVOID pvRef
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ConfigureDevices ( _                          ' VTable offset = 40
     BYVAL lpdiCallback AS DWORD _                      ' __in LPDICONFIGUREDEVICESCALLBACK lpdiCallback
   , BYREF lpdiCDParams AS DICONFIGUREDEVICESPARAMSW _  ' __in LPDICONFIGUREDEVICESPARAMSW lpdiCDParams
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYVAL pvRefData AS DWORD _                         ' __in LPVOID pvRefData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

' ########################################################################################
' IDirectInput8 interface
' IID = BF798030-483A-4DA2-AA99-5D64ED369700
' Inherited interface = IDirectInput
' ########################################################################################

INTERFACE IDirectInput8 $IID_IDirectInput8

   INHERIT IUnknown

   ' =====================================================================================
   ' IDirectInput mehods
   ' =====================================================================================
   METHOD CreateDevice ( _                              ' VTable offset = 12
     BYREF rguid AS GUID _                              ' __in  REFGUID rguid
   , BYREF lplpDirectInputDevice AS IDirectInputDevice _ ' __out LPDIRECTINPUTDEVICEA * lplpDirectInputDevice
   , BYVAL pUnkOuter AS IUnknown _                      ' __in  LPUNKNOWN pUnkOuter
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumDevices ( _                               ' VTable offset = 16
     BYVAL dwDevType AS DWORD _                         ' __in DWORD dwDevType
   , BYVAL lpCallback AS DWORD _                        ' __in LPDIENUMDEVICESCALLBACKA lpCallback
   , BYVAL pvRef AS DWORD _                             ' __in LPVOID pvRef
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDeviceStatus ( _                           ' VTable offset = 20
     BYREF rguidInstance AS GUID _                      ' __in REFGUID rguidInstance
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RunControlPanel ( _                           ' VTable offset = 24
     BYVAL hwndOwner AS DWORD _                         ' __in HWND hwndOwner
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Initialize ( _                                ' VTable offset = 28
     BYVAL hinst AS DWORD _                             ' __in HINSTANCE hinst
   , BYVAL dwVersion AS DWORD _                         ' __in DWORD dwVersion
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IDirectInput2 mehods
   ' =====================================================================================
   METHOD FindDevice ( _                                ' VTable offset = 32
     BYREF rguidClass AS GUID _                         ' __in  REFGUID rguidClass
   , BYREF ptszName AS ASCIIZ _                         ' __in  LPCSTR ptszName
   , BYREF pguidInstance AS GUID _                      ' __out LPGUID pguidInstance
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IDirectInput8 mehods
   ' =====================================================================================
   METHOD EnumDevicesBySemantics ( _                    ' VTable offset = 36
     BYREF ptszUserName AS ASCIIZ _                     ' __in LPCSTR ptszUserName
   , BYREF lpdiActionFormat AS DIACTIONFORMATA _        ' __in LPDIACTIONFORMATA lpdiActionFormat
   , BYVAL lpCallback AS DWORD _                        ' __in LPDIENUMDEVICESBYSEMANTICSCA lpCallback
   , BYVAL pvRef AS DWORD _                             ' __in LPVOID pvRef
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ConfigureDevices ( _                          ' VTable offset = 40
     BYVAL lpdiCallback AS DWORD _                      ' __in LPDICONFIGUREDEVICESCALLBACK lpdiCallback
   , BYREF lpdiCDParams AS DICONFIGUREDEVICESPARAMSA _  ' __in LPDICONFIGUREDEVICESPARAMSA lpdiCDParams
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYVAL pvRefData AS DWORD _                         ' __in LPVOID pvRefData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE


DECLARE FUNCTION DirectInputCreate IMPORT "DINPUT.DLL" ALIAS "DirectInputCreateA" ( _
   BYVAL hinst AS DWORD _                               ' __in  HINSTANCE hinst
 , BYVAL dwVersion AS DWORD _                           ' __in  DWORD dwVersion
 , BYREF ppDI AS IDirectInput _                         ' __out LPDIRECTINPUTA *ppDI
 , BYVAL punkOuter AS IUnknown _                        ' __in LPUNKNOWN punkOuter
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION DirectInputCreateW IMPORT "DINPUT.DLL" ALIAS "DirectInputCreateW" ( _
   BYVAL hinst AS DWORD _                               ' __in HINSTANCE hinst
 , BYVAL dwVersion AS DWORD _                           ' __in DWORD dwVersion
 , BYREF ppDI AS IDirectInputW _                        ' __out LPDIRECTINPUTW *ppDI
 , BYVAL punkOuter AS IUnknown _                        ' __in LPUNKNOWN punkOuter
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION DirectInputCreateEx IMPORT "DINPUT.DLL" ALIAS "DirectInputCreateEx" ( _
   BYVAL hinst AS DWORD _                               ' __in  HINSTANCE hinst
 , BYVAL dwVersion AS DWORD _                           ' __in  DWORD dwVersion
 , BYREF riidltf AS GUID _                              ' __in  REFIID riidltf
 , BYREF ppvOut AS ANY _                                ' __out LPVOID *ppvOut
 , BYVAL punkOuter AS IUnknown _                        ' __in  LPUNKNOWN punkOuter
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION DirectInput8Create IMPORT "DINPUT8.DLL" ALIAS "DirectInput8Create" ( _
   BYVAL hinst AS DWORD _                               ' __in  HINSTANCE hinst
 , BYVAL dwVersion AS DWORD _                           ' __in  DWORD dwVersion
 , BYREF riidltf AS GUID _                              ' __in  REFIID riidltf
 , BYREF ppvOut AS ANY _                                ' __out LPVOID *ppvOut
 , BYVAL punkOuter AS IUnknown _                        ' __in  LPUNKNOWN punkOuter
 ) AS LONG                                              ' HRESULT

'/****************************************************************************
' *
' *  Return Codes
' *
' ****************************************************************************/

'/*
' *  The operation completed successfully.
' */
%DI_OK                          = %S_OK

'/*
' *  The device exists but is not currently attached.
' */
%DI_NOTATTACHED                 = %S_FALSE

'/*
' *  The device buffer overflowed.  Some input was lost.
' */
%DI_BUFFEROVERFLOW              = %S_FALSE

'/*
' *  The change in device properties had no effect.
' */
%DI_PROPNOEFFECT                = %S_FALSE

'/*
' *  The operation had no effect.
' */
%DI_NOEFFECT                    = %S_FALSE

'/*
' *  The device is a polled device.  As a result, device buffering
' *  will not collect any data and event notifications will not be
' *  signalled until GetDeviceState is called.
' */
%DI_POLLEDDEVICE                = &H00000002&

'/*
' *  The parameters of the effect were successfully updated by
' *  IDirectInputEffect::SetParameters, but the effect was not
' *  downloaded because the device is not exclusively acquired
' *  or because the DIEP_NODOWNLOAD flag was passed.
' */
%DI_DOWNLOADSKIPPED              = &H00000003&

'/*
' *  The parameters of the effect were successfully updated by
' *  IDirectInputEffect::SetParameters, but in order to change
' *  the parameters, the effect needed to be restarted.
' */
%DI_EFFECTRESTARTED              = &H00000004&

'/*
' *  The parameters of the effect were successfully updated by
' *  IDirectInputEffect::SetParameters, but some of them were
' *  beyond the capabilities of the device and were truncated.
' */
%DI_TRUNCATED                    = &H00000008&

'/*
' *  The settings have been successfully applied but could not be
' *  persisted.
' */
%DI_SETTINGSNOTSAVED             = &H0000000B&

'/*
' *  Equal to DI_EFFECTRESTARTED | DI_TRUNCATED.
' */
%DI_TRUNCATEDANDRESTARTED        = &H0000000C&

'/*
' *  A SUCCESS code indicating that settings cannot be modified.
' */
%DI_WRITEPROTECT                 = &H00000013&

'/*
' *  The application requires a newer version of DirectInput.
' */
'#define DIERR_OLDDIRECTINPUTVERSION     \
'    MAKE_HRESULT(SEVERITY_ERROR, FACILITY_WIN32, ERROR_OLD_WIN_VERSION)
%DIERR_OLDDIRECTINPUTVERSION     = &H70000 + 1150  ' SEVERITY_ERROR_FACILITY_WIN32 or ERROR_OLD_WIN_VERSION

'/*
' *  The application was written for an unsupported prerelease version
' *  of DirectInput.
' */
'#define DIERR_BETADIRECTINPUTVERSION    \
'    MAKE_HRESULT(SEVERITY_ERROR, FACILITY_WIN32, ERROR_RMODE_APP)
%DIERR_BETADIRECTINPUTVERSION    = &H70000 +  1153  ' SEVERITY_ERROR_FACILITY_WIN32 or ERROR_RMODE_APP

'/*
' *  The object could not be created due to an incompatible driver version
' *  or mismatched or incomplete driver components.
' */
'#define DIERR_BADDRIVERVER              \
'    MAKE_HRESULT(SEVERITY_ERROR, FACILITY_WIN32, ERROR_BAD_DRIVER_LEVEL)
%DIERR_BADDRIVERVER              = &H70000 +  119  ' SEVERITY_ERROR_FACILITY_WIN32 or ERROR_BAD_DRIVER_LEVEL

'/*
' * The device or device instance or effect is not registered with DirectInput.
' */
%DIERR_DEVICENOTREG              = %REGDB_E_CLASSNOTREG

'/*
' * The requested object does not exist.
' */
'#define DIERR_NOTFOUND                  \
'    MAKE_HRESULT(SEVERITY_ERROR, FACILITY_WIN32, ERROR_FILE_NOT_FOUND)
%DIERR_NOTFOUND                  = &H70000 +  2  ' SEVERITY_ERROR_FACILITY_WIN32 or ERROR_FILE_NOT_FOUND

'/*
' * The requested object does not exist.
' */
'#define DIERR_OBJECTNOTFOUND            \
'    MAKE_HRESULT(SEVERITY_ERROR, FACILITY_WIN32, ERROR_FILE_NOT_FOUND)
%DIERR_OBJECTNOTFOUND            = &H70000 +  2  ' SEVERITY_ERROR_FACILITY_WIN32 or ERROR_FILE_NOT_FOUND

'/*
' * An invalid parameter was passed to the returning function,
' * or the object was not in a state that admitted the function
' * to be called.
' */
%DIERR_INVALIDPARAM              = %E_INVALIDARG

'/*
' * The specified interface is not supported by the object
' */
%DIERR_NOINTERFACE               = %E_NOINTERFACE

'/*
' * An undetermined error occured inside the DInput subsystem
' */
%DIERR_GENERIC                   = %E_FAIL

'/*
' * The DInput subsystem couldn't allocate sufficient memory to complete the
' * caller's request.
' */
%DIERR_OUTOFMEMORY               = %E_OUTOFMEMORY

'/*
' * The function called is not supported at this time
' */
%DIERR_UNSUPPORTED               = %E_NOTIMPL

'/*
' * This object has not been initialized
' */
'#define DIERR_NOTINITIALIZED            \
'    MAKE_HRESULT(SEVERITY_ERROR, FACILITY_WIN32, ERROR_NOT_READY)
%DIERR_NOTINITIALIZED            = &H70000 + 21  ' SEVERITY_ERROR_FACILITY_WIN32 or ERROR_NOT_READY

'/*
' * This object is already initialized
' */
'#define DIERR_ALREADYINITIALIZED        \
'    MAKE_HRESULT(SEVERITY_ERROR, FACILITY_WIN32, ERROR_ALREADY_INITIALIZED)
%DIERR_ALREADYINITIALIZED        = &H70000 + 1247  ' SEVERITY_ERROR_FACILITY_WIN32 or ERROR_ALREADY_INITIALIZED

'/*
' * This object does not support aggregation
' */
%DIERR_NOAGGREGATION             = %CLASS_E_NOAGGREGATION

'/*
' * Another app has a higher priority level, preventing this call from
' * succeeding.
' */
%DIERR_OTHERAPPHASPRIO           = %E_ACCESSDENIED

'/*
' * Access to the device has been lost.  It must be re-acquired.
' */
'#define DIERR_INPUTLOST                 \
'    MAKE_HRESULT(SEVERITY_ERROR, FACILITY_WIN32, ERROR_READ_FAULT)
%DIERR_INPUTLOST                 = &H70000 + 30  ' SEVERITY_ERROR_FACILITY_WIN32 or ERROR_READ_FAULT

'/*
' * The operation cannot be performed while the device is acquired.
' */
'#define DIERR_ACQUIRED                  \
'    MAKE_HRESULT(SEVERITY_ERROR, FACILITY_WIN32, ERROR_BUSY)
%DIERR_ACQUIRED                  = &H70000 + 170  ' SEVERITY_ERROR_FACILITY_WIN32 or ERROR_BUSY

'/*
' * The operation cannot be performed unless the device is acquired.
' */
'#define DIERR_NOTACQUIRED               \
'    MAKE_HRESULT(SEVERITY_ERROR, FACILITY_WIN32, ERROR_INVALID_ACCESS)
%DIERR_NOTACQUIRED               = &H70000 + 12  ' SEVERITY_ERROR_FACILITY_WIN32 or ERROR_INVALID_ACCESS

'/*
' * The specified property cannot be changed.
' */
%DIERR_READONLY                  = %E_ACCESSDENIED

'/*
' * The device already has an event notification associated with it.
' */
%DIERR_HANDLEEXISTS              = %E_ACCESSDENIED

'/*
' * Data is not yet available.
' */
%E_PENDING                       = &H8000000A&

'/*
' * Unable to IDirectInputJoyConfig_Acquire because the user
' * does not have sufficient privileges to change the joystick
' * configuration.
' */
%DIERR_INSUFFICIENTPRIVS         = &H80040200&

'/*
' * The device is full.
' */
%DIERR_DEVICEFULL                = &H80040201&

'/*
' * Not all the requested information fit into the buffer.
' */
%DIERR_MOREDATA                  = &H80040202&

'/*
' * The effect is not downloaded.
' */
%DIERR_NOTDOWNLOADED             = &H80040203&

'/*
' *  The device cannot be reinitialized because there are still effects
' *  attached to it.
' */
%DIERR_HASEFFECTS                = &H80040204&

'/*
' *  The operation cannot be performed unless the device is acquired
' *  in DISCL_EXCLUSIVE mode.
' */
%DIERR_NOTEXCLUSIVEACQUIRED      = &H80040205&

'/*
' *  The effect could not be downloaded because essential information
' *  is missing.  For example, no axes have been associated with the
' *  effect, or no type-specific information has been created.
' */
%DIERR_INCOMPLETEEFFECT          = &H80040206&

'/*
' *  Attempted to read buffered device data from a device that is
' *  not buffered.
' */
%DIERR_NOTBUFFERED               = &H80040207&

'/*
' *  An attempt was made to modify parameters of an effect while it is
' *  playing.  Not all hardware devices support altering the parameters
' *  of an effect while it is playing.
' */
%DIERR_EFFECTPLAYING             = &H80040208&

'/*
' *  The operation could not be completed because the device is not
' *  plugged in.
' */
%DIERR_UNPLUGGED                 = &H80040209&

'/*
' *  SendDeviceData failed because more information was requested
' *  to be sent than can be sent to the device.  Some devices have
' *  restrictions on how much data can be sent to them.  (For example,
' *  there might be a limit on the number of buttons that can be
' *  pressed at once.)
' */
%DIERR_REPORTFULL                = &H8004020A&


'/*
' *  A mapper file function failed because reading or writing the user or IHV
' *  settings file failed.
' */
%DIERR_MAPFILEFAIL               = &H8004020B&


'/*--- DINPUT Mapper Definitions: New for Dx8         ---*/


'/*--- Keyboard
'      Physical Keyboard Device       ---*/

%DIKEYBOARD_ESCAPE                       = &H81000401???
%DIKEYBOARD_1                            = &H81000402???
%DIKEYBOARD_2                            = &H81000403???
%DIKEYBOARD_3                            = &H81000404???
%DIKEYBOARD_4                            = &H81000405???
%DIKEYBOARD_5                            = &H81000406???
%DIKEYBOARD_6                            = &H81000407???
%DIKEYBOARD_7                            = &H81000408???
%DIKEYBOARD_8                            = &H81000409???
%DIKEYBOARD_9                            = &H8100040A???
%DIKEYBOARD_0                            = &H8100040B???
%DIKEYBOARD_MINUS                        = &H8100040C???    '  /* - on main keyboard */
%DIKEYBOARD_EQUALS                       = &H8100040D???
%DIKEYBOARD_BACK                         = &H8100040E???    '  /* backspace */
%DIKEYBOARD_TAB                          = &H8100040F???
%DIKEYBOARD_Q                            = &H81000410???
%DIKEYBOARD_W                            = &H81000411???
%DIKEYBOARD_E                            = &H81000412???
%DIKEYBOARD_R                            = &H81000413???
%DIKEYBOARD_T                            = &H81000414???
%DIKEYBOARD_Y                            = &H81000415???
%DIKEYBOARD_U                            = &H81000416???
%DIKEYBOARD_I                            = &H81000417???
%DIKEYBOARD_O                            = &H81000418???
%DIKEYBOARD_P                            = &H81000419???
%DIKEYBOARD_LBRACKET                     = &H8100041A???
%DIKEYBOARD_RBRACKET                     = &H8100041B???
%DIKEYBOARD_RETURN                       = &H8100041C???    '  /* Enter on main keyboard */
%DIKEYBOARD_LCONTROL                     = &H8100041D???
%DIKEYBOARD_A                            = &H8100041E???
%DIKEYBOARD_S                            = &H8100041F???
%DIKEYBOARD_D                            = &H81000420???
%DIKEYBOARD_F                            = &H81000421???
%DIKEYBOARD_G                            = &H81000422???
%DIKEYBOARD_H                            = &H81000423???
%DIKEYBOARD_J                            = &H81000424???
%DIKEYBOARD_K                            = &H81000425???
%DIKEYBOARD_L                            = &H81000426???
%DIKEYBOARD_SEMICOLON                    = &H81000427???
%DIKEYBOARD_APOSTROPHE                   = &H81000428???
%DIKEYBOARD_GRAVE                        = &H81000429???    '  /* accent grave */
%DIKEYBOARD_LSHIFT                       = &H8100042A???
%DIKEYBOARD_BACKSLASH                    = &H8100042B???
%DIKEYBOARD_Z                            = &H8100042C???
%DIKEYBOARD_X                            = &H8100042D???
%DIKEYBOARD_C                            = &H8100042E???
%DIKEYBOARD_V                            = &H8100042F???
%DIKEYBOARD_B                            = &H81000430???
%DIKEYBOARD_N                            = &H81000431???
%DIKEYBOARD_M                            = &H81000432???
%DIKEYBOARD_COMMA                        = &H81000433???
%DIKEYBOARD_PERIOD                       = &H81000434???    '  /* . on main keyboard */
%DIKEYBOARD_SLASH                        = &H81000435???    '  /* / on main keyboard */
%DIKEYBOARD_RSHIFT                       = &H81000436???
%DIKEYBOARD_MULTIPLY                     = &H81000437???    '  /* * on numeric keypad */
%DIKEYBOARD_LMENU                        = &H81000438???    '  /* left Alt */
%DIKEYBOARD_SPACE                        = &H81000439???
%DIKEYBOARD_CAPITAL                      = &H8100043A???
%DIKEYBOARD_F1                           = &H8100043B???
%DIKEYBOARD_F2                           = &H8100043C???
%DIKEYBOARD_F3                           = &H8100043D???
%DIKEYBOARD_F4                           = &H8100043E???
%DIKEYBOARD_F5                           = &H8100043F???
%DIKEYBOARD_F6                           = &H81000440???
%DIKEYBOARD_F7                           = &H81000441???
%DIKEYBOARD_F8                           = &H81000442???
%DIKEYBOARD_F9                           = &H81000443???
%DIKEYBOARD_F10                          = &H81000444???
%DIKEYBOARD_NUMLOCK                      = &H81000445???
%DIKEYBOARD_SCROLL                       = &H81000446???    '  /* Scroll Lock */
%DIKEYBOARD_NUMPAD7                      = &H81000447???
%DIKEYBOARD_NUMPAD8                      = &H81000448???
%DIKEYBOARD_NUMPAD9                      = &H81000449???
%DIKEYBOARD_SUBTRACT                     = &H8100044A???    '  /* - on numeric keypad */
%DIKEYBOARD_NUMPAD4                      = &H8100044B???
%DIKEYBOARD_NUMPAD5                      = &H8100044C???
%DIKEYBOARD_NUMPAD6                      = &H8100044D???
%DIKEYBOARD_ADD                          = &H8100044E???    '  /* + on numeric keypad */
%DIKEYBOARD_NUMPAD1                      = &H8100044F???
%DIKEYBOARD_NUMPAD2                      = &H81000450???
%DIKEYBOARD_NUMPAD3                      = &H81000451???
%DIKEYBOARD_NUMPAD0                      = &H81000452???
%DIKEYBOARD_DECIMAL                      = &H81000453???    '  /* . on numeric keypad */
%DIKEYBOARD_OEM_102                      = &H81000456???    '  /* <> or \| on RT 102-key keyboard (Non-U.S.) */
%DIKEYBOARD_F11                          = &H81000457???
%DIKEYBOARD_F12                          = &H81000458???
%DIKEYBOARD_F13                          = &H81000464???    '  /*                     (NEC PC98) */
%DIKEYBOARD_F14                          = &H81000465???    '  /*                     (NEC PC98) */
%DIKEYBOARD_F15                          = &H81000466???    '  /*                     (NEC PC98) */
%DIKEYBOARD_KANA                         = &H81000470???    '  /* (Japanese keyboard)            */
%DIKEYBOARD_ABNT_C1                      = &H81000473???    '  /* /? on Brazilian keyboard */
%DIKEYBOARD_CONVERT                      = &H81000479???    '  /* (Japanese keyboard)            */
%DIKEYBOARD_NOCONVERT                    = &H8100047B???    '  /* (Japanese keyboard)            */
%DIKEYBOARD_YEN                          = &H8100047D???    '  /* (Japanese keyboard)            */
%DIKEYBOARD_ABNT_C2                      = &H8100047E???    '  /* Numpad . on Brazilian keyboard */
%DIKEYBOARD_NUMPADEQUALS                 = &H8100048D???    '  /* = on numeric keypad (NEC PC98) */
%DIKEYBOARD_PREVTRACK                    = &H81000490???    '  /* Previous Track (DIK_CIRCUMFLEX on Japanese keyboard) */
%DIKEYBOARD_AT                           = &H81000491???    '  /*                     (NEC PC98) */
%DIKEYBOARD_COLON                        = &H81000492???    '  /*                     (NEC PC98) */
%DIKEYBOARD_UNDERLINE                    = &H81000493???    '  /*                     (NEC PC98) */
%DIKEYBOARD_KANJI                        = &H81000494???    '  /* (Japanese keyboard)            */
%DIKEYBOARD_STOP                         = &H81000495???    '  /*                     (NEC PC98) */
%DIKEYBOARD_AX                           = &H81000496???    '  /*                     (Japan AX) */
%DIKEYBOARD_UNLABELED                    = &H81000497???    '  /*                        (J3100) */
%DIKEYBOARD_NEXTTRACK                    = &H81000499???    '  /* Next Track */
%DIKEYBOARD_NUMPADENTER                  = &H8100049C???    '  /* Enter on numeric keypad */
%DIKEYBOARD_RCONTROL                     = &H8100049D???
%DIKEYBOARD_MUTE                         = &H810004A0???    '  /* Mute */
%DIKEYBOARD_CALCULATOR                   = &H810004A1???    '  /* Calculator */
%DIKEYBOARD_PLAYPAUSE                    = &H810004A2???    '  /* Play / Pause */
%DIKEYBOARD_MEDIASTOP                    = &H810004A4???    '  /* Media Stop */
%DIKEYBOARD_VOLUMEDOWN                   = &H810004AE???    '  /* Volume - */
%DIKEYBOARD_VOLUMEUP                     = &H810004B0???    '  /* Volume + */
%DIKEYBOARD_WEBHOME                      = &H810004B2???    '  /* Web home */
%DIKEYBOARD_NUMPADCOMMA                  = &H810004B3???    '  /* , on numeric keypad (NEC PC98) */
%DIKEYBOARD_DIVIDE                       = &H810004B5???    '  /* / on numeric keypad */
%DIKEYBOARD_SYSRQ                        = &H810004B7???
%DIKEYBOARD_RMENU                        = &H810004B8???    '  /* right Alt */
%DIKEYBOARD_PAUSE                        = &H810004C5???    '  /* Pause */
%DIKEYBOARD_HOME                         = &H810004C7???    '  /* Home on arrow keypad */
%DIKEYBOARD_UP                           = &H810004C8???    '  /* UpArrow on arrow keypad */
%DIKEYBOARD_PRIOR                        = &H810004C9???    '  /* PgUp on arrow keypad */
%DIKEYBOARD_LEFT                         = &H810004CB???    '  /* LeftArrow on arrow keypad */
%DIKEYBOARD_RIGHT                        = &H810004CD???    '  /* RightArrow on arrow keypad */
%DIKEYBOARD_END                          = &H810004CF???    '  /* End on arrow keypad */
%DIKEYBOARD_DOWN                         = &H810004D0???    '  /* DownArrow on arrow keypad */
%DIKEYBOARD_NEXT                         = &H810004D1???    '  /* PgDn on arrow keypad */
%DIKEYBOARD_INSERT                       = &H810004D2???    '  /* Insert on arrow keypad */
%DIKEYBOARD_DELETE                       = &H810004D3???    '  /* Delete on arrow keypad */
%DIKEYBOARD_LWIN                         = &H810004DB???    '  /* Left Windows key */
%DIKEYBOARD_RWIN                         = &H810004DC???    '  /* Right Windows key */
%DIKEYBOARD_APPS                         = &H810004DD???    '  /* AppMenu key */
%DIKEYBOARD_POWER                        = &H810004DE???    '  /* System Power */
%DIKEYBOARD_SLEEP                        = &H810004DF???    '  /* System Sleep */
%DIKEYBOARD_WAKE                         = &H810004E3???    '  /* System Wake */
%DIKEYBOARD_WEBSEARCH                    = &H810004E5???    '  /* Web Search */
%DIKEYBOARD_WEBFAVORITES                 = &H810004E6???    '  /* Web Favorites */
%DIKEYBOARD_WEBREFRESH                   = &H810004E7???    '  /* Web Refresh */
%DIKEYBOARD_WEBSTOP                      = &H810004E8???    '  /* Web Stop */
%DIKEYBOARD_WEBFORWARD                   = &H810004E9???    '  /* Web Forward */
%DIKEYBOARD_WEBBACK                      = &H810004EA???    '  /* Web Back */
%DIKEYBOARD_MYCOMPUTER                   = &H810004EB???    '  /* My Computer */
%DIKEYBOARD_MAIL                         = &H810004EC???    '  /* Mail */
%DIKEYBOARD_MEDIASELECT                  = &H810004ED???    '  /* Media Select */


'  /*--- MOUSE
'      Physical Mouse Device             ---*/

%DIMOUSE_XAXISAB                         = &H82000200??? OR %DIMOFS_X  '  /* X Axis-absolute: Some mice natively report absolute coordinates  */
%DIMOUSE_YAXISAB                         = &H82000200??? OR %DIMOFS_Y  '  /* Y Axis-absolute: Some mice natively report absolute coordinates */
%DIMOUSE_XAXIS                           = &H82000300??? OR %DIMOFS_X  '  /* X Axis */
%DIMOUSE_YAXIS                           = &H82000300??? OR %DIMOFS_Y  '  /* Y Axis */
%DIMOUSE_WHEEL                           = &H82000300??? OR %DIMOFS_Z  '  /* Z Axis */
%DIMOUSE_BUTTON0                         = &H82000400??? OR %DIMOFS_BUTTON0 '  /* Button 0 */
%DIMOUSE_BUTTON1                         = &H82000400??? OR %DIMOFS_BUTTON1 '  /* Button 1 */
%DIMOUSE_BUTTON2                         = &H82000400??? OR %DIMOFS_BUTTON2 '  /* Button 2 */
%DIMOUSE_BUTTON3                         = &H82000400??? OR %DIMOFS_BUTTON3 '  /* Button 3 */
%DIMOUSE_BUTTON4                         = &H82000400??? OR %DIMOFS_BUTTON4 '  /* Button 4 */
%DIMOUSE_BUTTON5                         = &H82000400??? OR %DIMOFS_BUTTON5 '  /* Button 5 */
%DIMOUSE_BUTTON6                         = &H82000400??? OR %DIMOFS_BUTTON6 '  /* Button 6 */
%DIMOUSE_BUTTON7                         = &H82000400??? OR %DIMOFS_BUTTON7 '  /* Button 7 */


''  /*--- VOICE
'      Physical Dplay Voice Device       ---*/

%DIVOICE_CHANNEL1                        = &H83000401???
%DIVOICE_CHANNEL2                        = &H83000402???
%DIVOICE_CHANNEL3                        = &H83000403???
%DIVOICE_CHANNEL4                        = &H83000404???
%DIVOICE_CHANNEL5                        = &H83000405???
%DIVOICE_CHANNEL6                        = &H83000406???
%DIVOICE_CHANNEL7                        = &H83000407???
%DIVOICE_CHANNEL8                        = &H83000408???
%DIVOICE_TEAM                            = &H83000409???
%DIVOICE_ALL                             = &H8300040A???
%DIVOICE_RECORDMUTE                      = &H8300040B???
%DIVOICE_PLAYBACKMUTE                    = &H8300040C???
%DIVOICE_TRANSMIT                        = &H8300040D???

%DIVOICE_VOICECOMMAND                    = &H83000410???


''  /*--- Driving Simulator - Racing
'      Vehicle control is primary objective  ---*/
%DIVIRTUAL_DRIVING_RACE                  = &H01000000???
%DIAXIS_DRIVINGR_STEER                   = &H01008A01??? '  /* Steering */
%DIAXIS_DRIVINGR_ACCELERATE              = &H01039202??? '  /* Accelerate */
%DIAXIS_DRIVINGR_BRAKE                   = &H01041203??? '  /* Brake-Axis */
%DIBUTTON_DRIVINGR_SHIFTUP               = &H01000C01??? '  /* Shift to next higher gear */
%DIBUTTON_DRIVINGR_SHIFTDOWN             = &H01000C02??? '  /* Shift to next lower gear */
%DIBUTTON_DRIVINGR_VIEW                  = &H01001C03??? '  /* Cycle through view options */
%DIBUTTON_DRIVINGR_MENU                  = &H010004FD??? '  /* Show menu options */
'  /*--- Priority 2 controls                            ---*/

%DIAXIS_DRIVINGR_ACCEL_AND_BRAKE         = &H01014A04??? '  /* Some devices combine accelerate and brake in a single axis */
%DIHATSWITCH_DRIVINGR_GLANCE             = &H01004601??? '  /* Look around */
%DIBUTTON_DRIVINGR_BRAKE                 = &H01004C04??? '  /* Brake-button */
%DIBUTTON_DRIVINGR_DASHBOARD             = &H01004405??? '  /* Select next dashboard option */
%DIBUTTON_DRIVINGR_AIDS                  = &H01004406??? '  /* Driver correction aids */
%DIBUTTON_DRIVINGR_MAP                   = &H01004407??? '  /* Display Driving Map */
%DIBUTTON_DRIVINGR_BOOST                 = &H01004408??? '  /* Turbo Boost */
%DIBUTTON_DRIVINGR_PIT                   = &H01004409??? '  /* Pit stop notification */
%DIBUTTON_DRIVINGR_ACCELERATE_LINK       = &H0103D4E0??? '  /* Fallback Accelerate button */
%DIBUTTON_DRIVINGR_STEER_LEFT_LINK       = &H0100CCE4??? '  /* Fallback Steer Left button */
%DIBUTTON_DRIVINGR_STEER_RIGHT_LINK      = &H0100CCEC??? '  /* Fallback Steer Right button */
%DIBUTTON_DRIVINGR_GLANCE_LEFT_LINK      = &H0107C4E4??? '  /* Fallback Glance Left button */
%DIBUTTON_DRIVINGR_GLANCE_RIGHT_LINK     = &H0107C4EC??? '  /* Fallback Glance Right button */
%DIBUTTON_DRIVINGR_DEVICE                = &H010044FE??? '  /* Show input device and controls */
%DIBUTTON_DRIVINGR_PAUSE                 = &H010044FC??? '  /* Start / Pause / Restart game */

'  /*--- Driving Simulator - Combat
'      Combat from within a vehicle is primary objective  ---*/
%DIVIRTUAL_DRIVING_COMBAT                = &H02000000???
%DIAXIS_DRIVINGC_STEER                   = &H02008A01??? '  /* Steering  */
%DIAXIS_DRIVINGC_ACCELERATE              = &H02039202??? '  /* Accelerate */
%DIAXIS_DRIVINGC_BRAKE                   = &H02041203??? '  /* Brake-axis */
%DIBUTTON_DRIVINGC_FIRE                  = &H02000C01??? '  /* Fire */
%DIBUTTON_DRIVINGC_WEAPONS               = &H02000C02??? '  /* Select next weapon */
%DIBUTTON_DRIVINGC_TARGET                = &H02000C03??? '  /* Select next available target */
%DIBUTTON_DRIVINGC_MENU                  = &H020004FD??? '  /* Show menu options */
'  /*--- Priority 2 controls                            ---*/

%DIAXIS_DRIVINGC_ACCEL_AND_BRAKE         = &H02014A04??? '  /* Some devices combine accelerate and brake in a single axis */
%DIHATSWITCH_DRIVINGC_GLANCE             = &H02004601??? '  /* Look around */
%DIBUTTON_DRIVINGC_SHIFTUP               = &H02004C04??? '  /* Shift to next higher gear */
%DIBUTTON_DRIVINGC_SHIFTDOWN             = &H02004C05??? '  /* Shift to next lower gear */
%DIBUTTON_DRIVINGC_DASHBOARD             = &H02004406??? '  /* Select next dashboard option */
%DIBUTTON_DRIVINGC_AIDS                  = &H02004407??? '  /* Driver correction aids */
%DIBUTTON_DRIVINGC_BRAKE                 = &H02004C08??? '  /* Brake-button */
%DIBUTTON_DRIVINGC_FIRESECONDARY         = &H02004C09??? '  /* Alternative fire button */
%DIBUTTON_DRIVINGC_ACCELERATE_LINK       = &H0203D4E0??? '  /* Fallback Accelerate button */
%DIBUTTON_DRIVINGC_STEER_LEFT_LINK       = &H0200CCE4??? '  /* Fallback Steer Left button */
%DIBUTTON_DRIVINGC_STEER_RIGHT_LINK      = &H0200CCEC??? '  /* Fallback Steer Right button */
%DIBUTTON_DRIVINGC_GLANCE_LEFT_LINK      = &H0207C4E4??? '  /* Fallback Glance Left button */
%DIBUTTON_DRIVINGC_GLANCE_RIGHT_LINK     = &H0207C4EC??? '  /* Fallback Glance Right button */
%DIBUTTON_DRIVINGC_DEVICE                = &H020044FE??? '  /* Show input device and controls */
%DIBUTTON_DRIVINGC_PAUSE                 = &H020044FC??? '  /* Start / Pause / Restart game */

'  /*--- Driving Simulator - Tank
'      Combat from withing a tank is primary objective  ---*/
%DIVIRTUAL_DRIVING_TANK                  = &H03000000???
%DIAXIS_DRIVINGT_STEER                   = &H03008A01??? '  /* Turn tank left / right */
%DIAXIS_DRIVINGT_BARREL                  = &H03010202??? '  /* Raise / lower barrel */
%DIAXIS_DRIVINGT_ACCELERATE              = &H03039203??? '  /* Accelerate */
%DIAXIS_DRIVINGT_ROTATE                  = &H03020204??? '  /* Turn barrel left / right */
%DIBUTTON_DRIVINGT_FIRE                  = &H03000C01??? '  /* Fire */
%DIBUTTON_DRIVINGT_WEAPONS               = &H03000C02??? '  /* Select next weapon */
%DIBUTTON_DRIVINGT_TARGET                = &H03000C03??? '  /* Selects next available target */
%DIBUTTON_DRIVINGT_MENU                  = &H030004FD??? '  /* Show menu options */
'  /*--- Priority 2 controls                            ---*/

%DIHATSWITCH_DRIVINGT_GLANCE             = &H03004601??? '  /* Look around */
%DIAXIS_DRIVINGT_BRAKE                   = &H03045205??? '  /* Brake-axis */
%DIAXIS_DRIVINGT_ACCEL_AND_BRAKE         = &H03014A06??? '  /* Some devices combine accelerate and brake in a single axis */
%DIBUTTON_DRIVINGT_VIEW                  = &H03005C04??? '  /* Cycle through view options */
%DIBUTTON_DRIVINGT_DASHBOARD             = &H03005C05??? '  /* Select next dashboard option */
%DIBUTTON_DRIVINGT_BRAKE                 = &H03004C06??? '  /* Brake-button */
%DIBUTTON_DRIVINGT_FIRESECONDARY         = &H03004C07??? '  /* Alternative fire button */
%DIBUTTON_DRIVINGT_ACCELERATE_LINK       = &H0303D4E0??? '  /* Fallback Accelerate button */
%DIBUTTON_DRIVINGT_STEER_LEFT_LINK       = &H0300CCE4??? '  /* Fallback Steer Left button */
%DIBUTTON_DRIVINGT_STEER_RIGHT_LINK      = &H0300CCEC??? '  /* Fallback Steer Right button */
%DIBUTTON_DRIVINGT_BARREL_UP_LINK        = &H030144E0??? '  /* Fallback Barrel up button */
%DIBUTTON_DRIVINGT_BARREL_DOWN_LINK      = &H030144E8??? '  /* Fallback Barrel down button */
%DIBUTTON_DRIVINGT_ROTATE_LEFT_LINK      = &H030244E4??? '  /* Fallback Rotate left button */
%DIBUTTON_DRIVINGT_ROTATE_RIGHT_LINK     = &H030244EC??? '  /* Fallback Rotate right button */
%DIBUTTON_DRIVINGT_GLANCE_LEFT_LINK      = &H0307C4E4??? '  /* Fallback Glance Left button */
%DIBUTTON_DRIVINGT_GLANCE_RIGHT_LINK     = &H0307C4EC??? '  /* Fallback Glance Right button */
%DIBUTTON_DRIVINGT_DEVICE                = &H030044FE??? '  /* Show input device and controls */
%DIBUTTON_DRIVINGT_PAUSE                 = &H030044FC??? '  /* Start / Pause / Restart game */

'  /*--- Flight Simulator - Civilian
'      Plane control is the primary objective  ---*/
%DIVIRTUAL_FLYING_CIVILIAN               = &H04000000???
%DIAXIS_FLYINGC_BANK                     = &H04008A01??? '  /* Roll ship left / right */
%DIAXIS_FLYINGC_PITCH                    = &H04010A02??? '  /* Nose up / down */
%DIAXIS_FLYINGC_THROTTLE                 = &H04039203??? '  /* Throttle */
%DIBUTTON_FLYINGC_VIEW                   = &H04002401??? '  /* Cycle through view options */
%DIBUTTON_FLYINGC_DISPLAY                = &H04002402??? '  /* Select next dashboard / heads up display option */
%DIBUTTON_FLYINGC_GEAR                   = &H04002C03??? '  /* Gear up / down */
%DIBUTTON_FLYINGC_MENU                   = &H040004FD??? '  /* Show menu options */
'  /*--- Priority 2 controls                            ---*/

%DIHATSWITCH_FLYINGC_GLANCE              = &H04004601??? '  /* Look around */
%DIAXIS_FLYINGC_BRAKE                    = &H04046A04??? '  /* Apply Brake */
%DIAXIS_FLYINGC_RUDDER                   = &H04025205??? '  /* Yaw ship left/right */
%DIAXIS_FLYINGC_FLAPS                    = &H04055A06??? '  /* Flaps */
%DIBUTTON_FLYINGC_FLAPSUP                = &H04006404??? '  /* Increment stepping up until fully retracted */
%DIBUTTON_FLYINGC_FLAPSDOWN              = &H04006405??? '  /* Decrement stepping down until fully extended */
%DIBUTTON_FLYINGC_BRAKE_LINK             = &H04046CE0??? '  /* Fallback brake button */
%DIBUTTON_FLYINGC_FASTER_LINK            = &H0403D4E0??? '  /* Fallback throttle up button */
%DIBUTTON_FLYINGC_SLOWER_LINK            = &H0403D4E8??? '  /* Fallback throttle down button */
%DIBUTTON_FLYINGC_GLANCE_LEFT_LINK       = &H0407C4E4??? '  /* Fallback Glance Left button */
%DIBUTTON_FLYINGC_GLANCE_RIGHT_LINK      = &H0407C4EC??? '  /* Fallback Glance Right button */
%DIBUTTON_FLYINGC_GLANCE_UP_LINK         = &H0407C4E0??? '  /* Fallback Glance Up button */
%DIBUTTON_FLYINGC_GLANCE_DOWN_LINK       = &H0407C4E8??? '  /* Fallback Glance Down button */
%DIBUTTON_FLYINGC_DEVICE                 = &H040044FE??? '  /* Show input device and controls */
%DIBUTTON_FLYINGC_PAUSE                  = &H040044FC??? '  /* Start / Pause / Restart game */

'  /*--- Flight Simulator - Military
'      Aerial combat is the primary objective  ---*/
%DIVIRTUAL_FLYING_MILITARY               = &H05000000???
%DIAXIS_FLYINGM_BANK                     = &H05008A01??? '  /* Bank - Roll ship left / right */
%DIAXIS_FLYINGM_PITCH                    = &H05010A02??? '  /* Pitch - Nose up / down */
%DIAXIS_FLYINGM_THROTTLE                 = &H05039203??? '  /* Throttle - faster / slower */
%DIBUTTON_FLYINGM_FIRE                   = &H05000C01??? '  /* Fire */
%DIBUTTON_FLYINGM_WEAPONS                = &H05000C02??? '  /* Select next weapon */
%DIBUTTON_FLYINGM_TARGET                 = &H05000C03??? '  /* Selects next available target */
%DIBUTTON_FLYINGM_MENU                   = &H050004FD??? '  /* Show menu options */
'  /*--- Priority 2 controls                            ---*/

%DIHATSWITCH_FLYINGM_GLANCE              = &H05004601??? '  /* Look around */
%DIBUTTON_FLYINGM_COUNTER                = &H05005C04??? '  /* Activate counter measures */
%DIAXIS_FLYINGM_RUDDER                   = &H05024A04??? '  /* Rudder - Yaw ship left/right */
%DIAXIS_FLYINGM_BRAKE                    = &H05046205??? '  /* Brake-axis */
%DIBUTTON_FLYINGM_VIEW                   = &H05006405??? '  /* Cycle through view options */
%DIBUTTON_FLYINGM_DISPLAY                = &H05006406??? '  /* Select next dashboard option */
%DIAXIS_FLYINGM_FLAPS                    = &H05055206??? '  /* Flaps */
%DIBUTTON_FLYINGM_FLAPSUP                = &H05005407??? '  /* Increment stepping up until fully retracted */
%DIBUTTON_FLYINGM_FLAPSDOWN              = &H05005408??? '  /* Decrement stepping down until fully extended */
%DIBUTTON_FLYINGM_FIRESECONDARY          = &H05004C09??? '  /* Alternative fire button */
%DIBUTTON_FLYINGM_GEAR                   = &H0500640A??? '  /* Gear up / down */
%DIBUTTON_FLYINGM_BRAKE_LINK             = &H050464E0??? '  /* Fallback brake button */
%DIBUTTON_FLYINGM_FASTER_LINK            = &H0503D4E0??? '  /* Fallback throttle up button */
%DIBUTTON_FLYINGM_SLOWER_LINK            = &H0503D4E8??? '  /* Fallback throttle down button */
%DIBUTTON_FLYINGM_GLANCE_LEFT_LINK       = &H0507C4E4??? '  /* Fallback Glance Left button */
%DIBUTTON_FLYINGM_GLANCE_RIGHT_LINK      = &H0507C4EC??? '  /* Fallback Glance Right button */
%DIBUTTON_FLYINGM_GLANCE_UP_LINK         = &H0507C4E0??? '  /* Fallback Glance Up button */
%DIBUTTON_FLYINGM_GLANCE_DOWN_LINK       = &H0507C4E8??? '  /* Fallback Glance Down button */
%DIBUTTON_FLYINGM_DEVICE                 = &H050044FE??? '  /* Show input device and controls */
%DIBUTTON_FLYINGM_PAUSE                  = &H050044FC??? '  /* Start / Pause / Restart game */

'  /*--- Flight Simulator - Combat Helicopter
'      Combat from helicopter is primary objective  ---*/
%DIVIRTUAL_FLYING_HELICOPTER             = &H06000000???
%DIAXIS_FLYINGH_BANK                     = &H06008A01??? '  /* Bank - Roll ship left / right */
%DIAXIS_FLYINGH_PITCH                    = &H06010A02??? '  /* Pitch - Nose up / down */
%DIAXIS_FLYINGH_COLLECTIVE               = &H06018A03??? '  /* Collective - Blade pitch/power */
%DIBUTTON_FLYINGH_FIRE                   = &H06001401??? '  /* Fire */
%DIBUTTON_FLYINGH_WEAPONS                = &H06001402??? '  /* Select next weapon */
%DIBUTTON_FLYINGH_TARGET                 = &H06001403??? '  /* Selects next available target */
%DIBUTTON_FLYINGH_MENU                   = &H060004FD??? '  /* Show menu options */
'  /*--- Priority 2 controls                            ---*/

%DIHATSWITCH_FLYINGH_GLANCE              = &H06004601??? '  /* Look around */
%DIAXIS_FLYINGH_TORQUE                   = &H06025A04??? '  /* Torque - Rotate ship around left / right axis */
%DIAXIS_FLYINGH_THROTTLE                 = &H0603DA05??? '  /* Throttle */
%DIBUTTON_FLYINGH_COUNTER                = &H06005404??? '  /* Activate counter measures */
%DIBUTTON_FLYINGH_VIEW                   = &H06006405??? '  /* Cycle through view options */
%DIBUTTON_FLYINGH_GEAR                   = &H06006406??? '  /* Gear up / down */
%DIBUTTON_FLYINGH_FIRESECONDARY          = &H06004C07??? '  /* Alternative fire button */
%DIBUTTON_FLYINGH_FASTER_LINK            = &H0603DCE0??? '  /* Fallback throttle up button */
%DIBUTTON_FLYINGH_SLOWER_LINK            = &H0603DCE8??? '  /* Fallback throttle down button */
%DIBUTTON_FLYINGH_GLANCE_LEFT_LINK       = &H0607C4E4??? '  /* Fallback Glance Left button */
%DIBUTTON_FLYINGH_GLANCE_RIGHT_LINK      = &H0607C4EC??? '  /* Fallback Glance Right button */
%DIBUTTON_FLYINGH_GLANCE_UP_LINK         = &H0607C4E0??? '  /* Fallback Glance Up button */
%DIBUTTON_FLYINGH_GLANCE_DOWN_LINK       = &H0607C4E8??? '  /* Fallback Glance Down button */
%DIBUTTON_FLYINGH_DEVICE                 = &H060044FE??? '  /* Show input device and controls */
%DIBUTTON_FLYINGH_PAUSE                  = &H060044FC??? '  /* Start / Pause / Restart game */

'  /*--- Space Simulator - Combat
'      Space Simulator with weapons  ---*/
%DIVIRTUAL_SPACESIM                      = &H07000000???
%DIAXIS_SPACESIM_LATERAL                 = &H07008201??? '  /* Move ship left / right */
%DIAXIS_SPACESIM_MOVE                    = &H07010202??? '  /* Move ship forward/backward */
%DIAXIS_SPACESIM_THROTTLE                = &H07038203??? '  /* Throttle - Engine speed */
%DIBUTTON_SPACESIM_FIRE                  = &H07000401??? '  /* Fire */
%DIBUTTON_SPACESIM_WEAPONS               = &H07000402??? '  /* Select next weapon */
%DIBUTTON_SPACESIM_TARGET                = &H07000403??? '  /* Selects next available target */
%DIBUTTON_SPACESIM_MENU                  = &H070004FD??? '  /* Show menu options */
'  /*--- Priority 2 controls                            ---*/

%DIHATSWITCH_SPACESIM_GLANCE             = &H07004601??? '  /* Look around */
%DIAXIS_SPACESIM_CLIMB                   = &H0701C204??? '  /* Climb - Pitch ship up/down */
%DIAXIS_SPACESIM_ROTATE                  = &H07024205??? '  /* Rotate - Turn ship left/right */
%DIBUTTON_SPACESIM_VIEW                  = &H07004404??? '  /* Cycle through view options */
%DIBUTTON_SPACESIM_DISPLAY               = &H07004405??? '  /* Select next dashboard / heads up display option */
%DIBUTTON_SPACESIM_RAISE                 = &H07004406??? '  /* Raise ship while maintaining current pitch */
%DIBUTTON_SPACESIM_LOWER                 = &H07004407??? '  /* Lower ship while maintaining current pitch */
%DIBUTTON_SPACESIM_GEAR                  = &H07004408??? '  /* Gear up / down */
%DIBUTTON_SPACESIM_FIRESECONDARY         = &H07004409??? '  /* Alternative fire button */
%DIBUTTON_SPACESIM_LEFT_LINK             = &H0700C4E4??? '  /* Fallback move left button */
%DIBUTTON_SPACESIM_RIGHT_LINK            = &H0700C4EC??? '  /* Fallback move right button */
%DIBUTTON_SPACESIM_FORWARD_LINK          = &H070144E0??? '  /* Fallback move forward button */
%DIBUTTON_SPACESIM_BACKWARD_LINK         = &H070144E8??? '  /* Fallback move backwards button */
%DIBUTTON_SPACESIM_FASTER_LINK           = &H0703C4E0??? '  /* Fallback throttle up button */
%DIBUTTON_SPACESIM_SLOWER_LINK           = &H0703C4E8??? '  /* Fallback throttle down button */
%DIBUTTON_SPACESIM_TURN_LEFT_LINK        = &H070244E4??? '  /* Fallback turn left button */
%DIBUTTON_SPACESIM_TURN_RIGHT_LINK       = &H070244EC??? '  /* Fallback turn right button */
%DIBUTTON_SPACESIM_GLANCE_LEFT_LINK      = &H0707C4E4??? '  /* Fallback Glance Left button */
%DIBUTTON_SPACESIM_GLANCE_RIGHT_LINK     = &H0707C4EC??? '  /* Fallback Glance Right button */
%DIBUTTON_SPACESIM_GLANCE_UP_LINK        = &H0707C4E0??? '  /* Fallback Glance Up button */
%DIBUTTON_SPACESIM_GLANCE_DOWN_LINK      = &H0707C4E8??? '  /* Fallback Glance Down button */
%DIBUTTON_SPACESIM_DEVICE                = &H070044FE??? '  /* Show input device and controls */
%DIBUTTON_SPACESIM_PAUSE                 = &H070044FC??? '  /* Start / Pause / Restart game */

'  /*--- Fighting - First Person
'      Hand to Hand combat is primary objective  ---*/
%DIVIRTUAL_FIGHTING_HAND2HAND            = &H08000000???
%DIAXIS_FIGHTINGH_LATERAL                = &H08008201??? '  /* Sidestep left/right */
%DIAXIS_FIGHTINGH_MOVE                   = &H08010202??? '  /* Move forward/backward */
%DIBUTTON_FIGHTINGH_PUNCH                = &H08000401??? '  /* Punch */
%DIBUTTON_FIGHTINGH_KICK                 = &H08000402??? '  /* Kick */
%DIBUTTON_FIGHTINGH_BLOCK                = &H08000403??? '  /* Block */
%DIBUTTON_FIGHTINGH_CROUCH               = &H08000404??? '  /* Crouch */
%DIBUTTON_FIGHTINGH_JUMP                 = &H08000405??? '  /* Jump */
%DIBUTTON_FIGHTINGH_SPECIAL1             = &H08000406??? '  /* Apply first special move */
%DIBUTTON_FIGHTINGH_SPECIAL2             = &H08000407??? '  /* Apply second special move */
%DIBUTTON_FIGHTINGH_MENU                 = &H080004FD??? '  /* Show menu options */
'  /*--- Priority 2 controls                            ---*/

%DIBUTTON_FIGHTINGH_SELECT               = &H08004408??? '  /* Select special move */
%DIHATSWITCH_FIGHTINGH_SLIDE             = &H08004601??? '  /* Look around */
%DIBUTTON_FIGHTINGH_DISPLAY              = &H08004409??? '  /* Shows next on-screen display option */
%DIAXIS_FIGHTINGH_ROTATE                 = &H08024203??? '  /* Rotate - Turn body left/right */
%DIBUTTON_FIGHTINGH_DODGE                = &H0800440A??? '  /* Dodge */
%DIBUTTON_FIGHTINGH_LEFT_LINK            = &H0800C4E4??? '  /* Fallback left sidestep button */
%DIBUTTON_FIGHTINGH_RIGHT_LINK           = &H0800C4EC??? '  /* Fallback right sidestep button */
%DIBUTTON_FIGHTINGH_FORWARD_LINK         = &H080144E0??? '  /* Fallback forward button */
%DIBUTTON_FIGHTINGH_BACKWARD_LINK        = &H080144E8??? '  /* Fallback backward button */
%DIBUTTON_FIGHTINGH_DEVICE               = &H080044FE??? '  /* Show input device and controls */
%DIBUTTON_FIGHTINGH_PAUSE                = &H080044FC??? '  /* Start / Pause / Restart game */

'  /*--- Fighting - First Person Shooting
'      Navigation and combat are primary objectives  ---*/
%DIVIRTUAL_FIGHTING_FPS                  = &H09000000???
%DIAXIS_FPS_ROTATE                       = &H09008201??? '  /* Rotate character left/right */
%DIAXIS_FPS_MOVE                         = &H09010202??? '  /* Move forward/backward */
%DIBUTTON_FPS_FIRE                       = &H09000401??? '  /* Fire */
%DIBUTTON_FPS_WEAPONS                    = &H09000402??? '  /* Select next weapon */
%DIBUTTON_FPS_APPLY                      = &H09000403??? '  /* Use item */
%DIBUTTON_FPS_SELECT                     = &H09000404??? '  /* Select next inventory item */
%DIBUTTON_FPS_CROUCH                     = &H09000405??? '  /* Crouch/ climb down/ swim down */
%DIBUTTON_FPS_JUMP                       = &H09000406??? '  /* Jump/ climb up/ swim up */
%DIAXIS_FPS_LOOKUPDOWN                   = &H09018203??? '  /* Look up / down  */
%DIBUTTON_FPS_STRAFE                     = &H09000407??? '  /* Enable strafing while active */
%DIBUTTON_FPS_MENU                       = &H090004FD??? '  /* Show menu options */
'  /*--- Priority 2 controls                            ---*/

%DIHATSWITCH_FPS_GLANCE                  = &H09004601??? '  /* Look around */
%DIBUTTON_FPS_DISPLAY                    = &H09004408??? '  /* Shows next on-screen display option/ map */
%DIAXIS_FPS_SIDESTEP                     = &H09024204??? '  /* Sidestep */
%DIBUTTON_FPS_DODGE                      = &H09004409??? '  /* Dodge */
%DIBUTTON_FPS_GLANCEL                    = &H0900440A??? '  /* Glance Left */
%DIBUTTON_FPS_GLANCER                    = &H0900440B??? '  /* Glance Right */
%DIBUTTON_FPS_FIRESECONDARY              = &H0900440C??? '  /* Alternative fire button */
%DIBUTTON_FPS_ROTATE_LEFT_LINK           = &H0900C4E4??? '  /* Fallback rotate left button */
%DIBUTTON_FPS_ROTATE_RIGHT_LINK          = &H0900C4EC??? '  /* Fallback rotate right button */
%DIBUTTON_FPS_FORWARD_LINK               = &H090144E0??? '  /* Fallback forward button */
%DIBUTTON_FPS_BACKWARD_LINK              = &H090144E8??? '  /* Fallback backward button */
%DIBUTTON_FPS_GLANCE_UP_LINK             = &H0901C4E0??? '  /* Fallback look up button */
%DIBUTTON_FPS_GLANCE_DOWN_LINK           = &H0901C4E8??? '  /* Fallback look down button */
%DIBUTTON_FPS_STEP_LEFT_LINK             = &H090244E4??? '  /* Fallback step left button */
%DIBUTTON_FPS_STEP_RIGHT_LINK            = &H090244EC??? '  /* Fallback step right button */
%DIBUTTON_FPS_DEVICE                     = &H090044FE??? '  /* Show input device and controls */
%DIBUTTON_FPS_PAUSE                      = &H090044FC??? '  /* Start / Pause / Restart game */

'  /*--- Fighting - Third Person action
'      Perspective of camera is behind the main character  ---*/
%DIVIRTUAL_FIGHTING_THIRDPERSON          = &H0A000000???
%DIAXIS_TPS_TURN                         = &H0A020201??? '  /* Turn left/right */
%DIAXIS_TPS_MOVE                         = &H0A010202??? '  /* Move forward/backward */
%DIBUTTON_TPS_RUN                        = &H0A000401??? '  /* Run or walk toggle switch */
%DIBUTTON_TPS_ACTION                     = &H0A000402??? '  /* Action Button */
%DIBUTTON_TPS_SELECT                     = &H0A000403??? '  /* Select next weapon */
%DIBUTTON_TPS_USE                        = &H0A000404??? '  /* Use inventory item currently selected */
%DIBUTTON_TPS_JUMP                       = &H0A000405??? '  /* Character Jumps */
%DIBUTTON_TPS_MENU                       = &H0A0004FD??? '  /* Show menu options */
'  /*--- Priority 2 controls                            ---*/

%DIHATSWITCH_TPS_GLANCE                  = &H0A004601??? '  /* Look around */
%DIBUTTON_TPS_VIEW                       = &H0A004406??? '  /* Select camera view */
%DIBUTTON_TPS_STEPLEFT                   = &H0A004407??? '  /* Character takes a left step */
%DIBUTTON_TPS_STEPRIGHT                  = &H0A004408??? '  /* Character takes a right step */
%DIAXIS_TPS_STEP                         = &H0A00C203??? '  /* Character steps left/right */
%DIBUTTON_TPS_DODGE                      = &H0A004409??? '  /* Character dodges or ducks */
%DIBUTTON_TPS_INVENTORY                  = &H0A00440A??? '  /* Cycle through inventory */
%DIBUTTON_TPS_TURN_LEFT_LINK             = &H0A0244E4??? '  /* Fallback turn left button */
%DIBUTTON_TPS_TURN_RIGHT_LINK            = &H0A0244EC??? '  /* Fallback turn right button */
%DIBUTTON_TPS_FORWARD_LINK               = &H0A0144E0??? '  /* Fallback forward button */
%DIBUTTON_TPS_BACKWARD_LINK              = &H0A0144E8??? '  /* Fallback backward button */
%DIBUTTON_TPS_GLANCE_UP_LINK             = &H0A07C4E0??? '  /* Fallback look up button */
%DIBUTTON_TPS_GLANCE_DOWN_LINK           = &H0A07C4E8??? '  /* Fallback look down button */
%DIBUTTON_TPS_GLANCE_LEFT_LINK           = &H0A07C4E4??? '  /* Fallback glance up button */
%DIBUTTON_TPS_GLANCE_RIGHT_LINK          = &H0A07C4EC??? '  /* Fallback glance right button */
%DIBUTTON_TPS_DEVICE                     = &H0A0044FE??? '  /* Show input device and controls */
%DIBUTTON_TPS_PAUSE                      = &H0A0044FC??? '  /* Start / Pause / Restart game */

'  /*--- Strategy - Role Playing
'      Navigation and problem solving are primary actions  ---*/
%DIVIRTUAL_STRATEGY_ROLEPLAYING          = &H0B000000???
%DIAXIS_STRATEGYR_LATERAL                = &H0B008201??? '  /* sidestep - left/right */
%DIAXIS_STRATEGYR_MOVE                   = &H0B010202??? '  /* move forward/backward */
%DIBUTTON_STRATEGYR_GET                  = &H0B000401??? '  /* Acquire item */
%DIBUTTON_STRATEGYR_APPLY                = &H0B000402??? '  /* Use selected item */
%DIBUTTON_STRATEGYR_SELECT               = &H0B000403??? '  /* Select nextitem */
%DIBUTTON_STRATEGYR_ATTACK               = &H0B000404??? '  /* Attack */
%DIBUTTON_STRATEGYR_CAST                 = &H0B000405??? '  /* Cast Spell */
%DIBUTTON_STRATEGYR_CROUCH               = &H0B000406??? '  /* Crouch */
%DIBUTTON_STRATEGYR_JUMP                 = &H0B000407??? '  /* Jump */
%DIBUTTON_STRATEGYR_MENU                 = &H0B0004FD??? '  /* Show menu options */
'  /*--- Priority 2 controls                            ---*/

%DIHATSWITCH_STRATEGYR_GLANCE            = &H0B004601??? '  /* Look around */
%DIBUTTON_STRATEGYR_MAP                  = &H0B004408??? '  /* Cycle through map options */
%DIBUTTON_STRATEGYR_DISPLAY              = &H0B004409??? '  /* Shows next on-screen display option */
%DIAXIS_STRATEGYR_ROTATE                 = &H0B024203??? '  /* Turn body left/right */
%DIBUTTON_STRATEGYR_LEFT_LINK            = &H0B00C4E4??? '  /* Fallback sidestep left button */
%DIBUTTON_STRATEGYR_RIGHT_LINK           = &H0B00C4EC??? '  /* Fallback sidestep right button */
%DIBUTTON_STRATEGYR_FORWARD_LINK         = &H0B0144E0??? '  /* Fallback move forward button */
%DIBUTTON_STRATEGYR_BACK_LINK            = &H0B0144E8??? '  /* Fallback move backward button */
%DIBUTTON_STRATEGYR_ROTATE_LEFT_LINK     = &H0B0244E4??? '  /* Fallback turn body left button */
%DIBUTTON_STRATEGYR_ROTATE_RIGHT_LINK    = &H0B0244EC??? '  /* Fallback turn body right button */
%DIBUTTON_STRATEGYR_DEVICE               = &H0B0044FE??? '  /* Show input device and controls */
%DIBUTTON_STRATEGYR_PAUSE                = &H0B0044FC??? '  /* Start / Pause / Restart game */

'  /*--- Strategy - Turn based
'      Navigation and problem solving are primary actions  ---*/
%DIVIRTUAL_STRATEGY_TURN                 = &H0C000000???
%DIAXIS_STRATEGYT_LATERAL                = &H0C008201??? '  /* Sidestep left/right */
%DIAXIS_STRATEGYT_MOVE                   = &H0C010202??? '  /* Move forward/backwards */
%DIBUTTON_STRATEGYT_SELECT               = &H0C000401??? '  /* Select unit or object */
%DIBUTTON_STRATEGYT_INSTRUCT             = &H0C000402??? '  /* Cycle through instructions */
%DIBUTTON_STRATEGYT_APPLY                = &H0C000403??? '  /* Apply selected instruction */
%DIBUTTON_STRATEGYT_TEAM                 = &H0C000404??? '  /* Select next team / cycle through all */
%DIBUTTON_STRATEGYT_TURN                 = &H0C000405??? '  /* Indicate turn over */
%DIBUTTON_STRATEGYT_MENU                 = &H0C0004FD??? '  /* Show menu options */
'  /*--- Priority 2 controls                            ---*/

%DIBUTTON_STRATEGYT_ZOOM                 = &H0C004406??? '  /* Zoom - in / out */
%DIBUTTON_STRATEGYT_MAP                  = &H0C004407??? '  /* cycle through map options */
%DIBUTTON_STRATEGYT_DISPLAY              = &H0C004408??? '  /* shows next on-screen display options */
%DIBUTTON_STRATEGYT_LEFT_LINK            = &H0C00C4E4??? '  /* Fallback sidestep left button */
%DIBUTTON_STRATEGYT_RIGHT_LINK           = &H0C00C4EC??? '  /* Fallback sidestep right button */
%DIBUTTON_STRATEGYT_FORWARD_LINK         = &H0C0144E0??? '  /* Fallback move forward button */
%DIBUTTON_STRATEGYT_BACK_LINK            = &H0C0144E8??? '  /* Fallback move back button */
%DIBUTTON_STRATEGYT_DEVICE               = &H0C0044FE??? '  /* Show input device and controls */
%DIBUTTON_STRATEGYT_PAUSE                = &H0C0044FC??? '  /* Start / Pause / Restart game */

'  /*--- Sports - Hunting
'      Hunting                ---*/
%DIVIRTUAL_SPORTS_HUNTING                = &H0D000000???
%DIAXIS_HUNTING_LATERAL                  = &H0D008201??? '  /* sidestep left/right */
%DIAXIS_HUNTING_MOVE                     = &H0D010202??? '  /* move forward/backwards */
%DIBUTTON_HUNTING_FIRE                   = &H0D000401??? '  /* Fire selected weapon */
%DIBUTTON_HUNTING_AIM                    = &H0D000402??? '  /* Select aim/move */
%DIBUTTON_HUNTING_WEAPON                 = &H0D000403??? '  /* Select next weapon */
%DIBUTTON_HUNTING_BINOCULAR              = &H0D000404??? '  /* Look through Binoculars */
%DIBUTTON_HUNTING_CALL                   = &H0D000405??? '  /* Make animal call */
%DIBUTTON_HUNTING_MAP                    = &H0D000406??? '  /* View Map */
%DIBUTTON_HUNTING_SPECIAL                = &H0D000407??? '  /* Special game operation */
%DIBUTTON_HUNTING_MENU                   = &H0D0004FD??? '  /* Show menu options */
'  /*--- Priority 2 controls                            ---*/

%DIHATSWITCH_HUNTING_GLANCE              = &H0D004601??? '  /* Look around */
%DIBUTTON_HUNTING_DISPLAY                = &H0D004408??? '  /* show next on-screen display option */
%DIAXIS_HUNTING_ROTATE                   = &H0D024203??? '  /* Turn body left/right */
%DIBUTTON_HUNTING_CROUCH                 = &H0D004409??? '  /* Crouch/ Climb / Swim down */
%DIBUTTON_HUNTING_JUMP                   = &H0D00440A??? '  /* Jump/ Climb up / Swim up */
%DIBUTTON_HUNTING_FIRESECONDARY          = &H0D00440B??? '  /* Alternative fire button */
%DIBUTTON_HUNTING_LEFT_LINK              = &H0D00C4E4??? '  /* Fallback sidestep left button */
%DIBUTTON_HUNTING_RIGHT_LINK             = &H0D00C4EC??? '  /* Fallback sidestep right button */
%DIBUTTON_HUNTING_FORWARD_LINK           = &H0D0144E0??? '  /* Fallback move forward button */
%DIBUTTON_HUNTING_BACK_LINK              = &H0D0144E8??? '  /* Fallback move back button */
%DIBUTTON_HUNTING_ROTATE_LEFT_LINK       = &H0D0244E4??? '  /* Fallback turn body left button */
%DIBUTTON_HUNTING_ROTATE_RIGHT_LINK      = &H0D0244EC??? '  /* Fallback turn body right button */
%DIBUTTON_HUNTING_DEVICE                 = &H0D0044FE??? '  /* Show input device and controls */
%DIBUTTON_HUNTING_PAUSE                  = &H0D0044FC??? '  /* Start / Pause / Restart game */

'  /*--- Sports - Fishing
'      Catching Fish is primary objective   ---*/
%DIVIRTUAL_SPORTS_FISHING                = &H0E000000???
%DIAXIS_FISHING_LATERAL                  = &H0E008201??? '  /* sidestep left/right */
%DIAXIS_FISHING_MOVE                     = &H0E010202??? '  /* move forward/backwards */
%DIBUTTON_FISHING_CAST                   = &H0E000401??? '  /* Cast line */
%DIBUTTON_FISHING_TYPE                   = &H0E000402??? '  /* Select cast type */
%DIBUTTON_FISHING_BINOCULAR              = &H0E000403??? '  /* Look through Binocular */
%DIBUTTON_FISHING_BAIT                   = &H0E000404??? '  /* Select type of Bait */
%DIBUTTON_FISHING_MAP                    = &H0E000405??? '  /* View Map */
%DIBUTTON_FISHING_MENU                   = &H0E0004FD??? '  /* Show menu options */
'  /*--- Priority 2 controls                            ---*/

%DIHATSWITCH_FISHING_GLANCE              = &H0E004601??? '  /* Look around */
%DIBUTTON_FISHING_DISPLAY                = &H0E004406??? '  /* Show next on-screen display option */
%DIAXIS_FISHING_ROTATE                   = &H0E024203??? '  /* Turn character left / right */
%DIBUTTON_FISHING_CROUCH                 = &H0E004407??? '  /* Crouch/ Climb / Swim down */
%DIBUTTON_FISHING_JUMP                   = &H0E004408??? '  /* Jump/ Climb up / Swim up */
%DIBUTTON_FISHING_LEFT_LINK              = &H0E00C4E4??? '  /* Fallback sidestep left button */
%DIBUTTON_FISHING_RIGHT_LINK             = &H0E00C4EC??? '  /* Fallback sidestep right button */
%DIBUTTON_FISHING_FORWARD_LINK           = &H0E0144E0??? '  /* Fallback move forward button */
%DIBUTTON_FISHING_BACK_LINK              = &H0E0144E8??? '  /* Fallback move back button */
%DIBUTTON_FISHING_ROTATE_LEFT_LINK       = &H0E0244E4??? '  /* Fallback turn body left button */
%DIBUTTON_FISHING_ROTATE_RIGHT_LINK      = &H0E0244EC??? '  /* Fallback turn body right button */
%DIBUTTON_FISHING_DEVICE                 = &H0E0044FE??? '  /* Show input device and controls */
%DIBUTTON_FISHING_PAUSE                  = &H0E0044FC??? '  /* Start / Pause / Restart game */

'  /*--- Sports - Baseball - Batting
'      Batter control is primary objective  ---*/
%DIVIRTUAL_SPORTS_BASEBALL_BAT           = &H0F000000???
%DIAXIS_BASEBALLB_LATERAL                = &H0F008201??? '  /* Aim left / right */
%DIAXIS_BASEBALLB_MOVE                   = &H0F010202??? '  /* Aim up / down */
%DIBUTTON_BASEBALLB_SELECT               = &H0F000401??? '  /* cycle through swing options */
%DIBUTTON_BASEBALLB_NORMAL               = &H0F000402??? '  /* normal swing */
%DIBUTTON_BASEBALLB_POWER                = &H0F000403??? '  /* swing for the fence */
%DIBUTTON_BASEBALLB_BUNT                 = &H0F000404??? '  /* bunt */
%DIBUTTON_BASEBALLB_STEAL                = &H0F000405??? '  /* Base runner attempts to steal a base */
%DIBUTTON_BASEBALLB_BURST                = &H0F000406??? '  /* Base runner invokes burst of speed */
%DIBUTTON_BASEBALLB_SLIDE                = &H0F000407??? '  /* Base runner slides into base */
%DIBUTTON_BASEBALLB_CONTACT              = &H0F000408??? '  /* Contact swing */
%DIBUTTON_BASEBALLB_MENU                 = &H0F0004FD??? '  /* Show menu options */
'  /*--- Priority 2 controls                            ---*/

%DIBUTTON_BASEBALLB_NOSTEAL              = &H0F004409??? '  /* Base runner goes back to a base */
%DIBUTTON_BASEBALLB_BOX                  = &H0F00440A??? '  /* Enter or exit batting box */
%DIBUTTON_BASEBALLB_LEFT_LINK            = &H0F00C4E4??? '  /* Fallback sidestep left button */
%DIBUTTON_BASEBALLB_RIGHT_LINK           = &H0F00C4EC??? '  /* Fallback sidestep right button */
%DIBUTTON_BASEBALLB_FORWARD_LINK         = &H0F0144E0??? '  /* Fallback move forward button */
%DIBUTTON_BASEBALLB_BACK_LINK            = &H0F0144E8??? '  /* Fallback move back button */
%DIBUTTON_BASEBALLB_DEVICE               = &H0F0044FE??? '  /* Show input device and controls */
%DIBUTTON_BASEBALLB_PAUSE                = &H0F0044FC??? '  /* Start / Pause / Restart game */

'  /*--- Sports - Baseball - Pitching
'      Pitcher control is primary objective   ---*/
%DIVIRTUAL_SPORTS_BASEBALL_PITCH         = &H10000000???
%DIAXIS_BASEBALLP_LATERAL                = &H10008201??? '  /* Aim left / right */
%DIAXIS_BASEBALLP_MOVE                   = &H10010202??? '  /* Aim up / down */
%DIBUTTON_BASEBALLP_SELECT               = &H10000401??? '  /* cycle through pitch selections */
%DIBUTTON_BASEBALLP_PITCH                = &H10000402??? '  /* throw pitch */
%DIBUTTON_BASEBALLP_BASE                 = &H10000403??? '  /* select base to throw to */
%DIBUTTON_BASEBALLP_THROW                = &H10000404??? '  /* throw to base */
%DIBUTTON_BASEBALLP_FAKE                 = &H10000405??? '  /* Fake a throw to a base */
%DIBUTTON_BASEBALLP_MENU                 = &H100004FD??? '  /* Show menu options */
'  /*--- Priority 2 controls                            ---*/

%DIBUTTON_BASEBALLP_WALK                 = &H10004406??? '  /* Throw intentional walk / pitch out */
%DIBUTTON_BASEBALLP_LOOK                 = &H10004407??? '  /* Look at runners on bases */
%DIBUTTON_BASEBALLP_LEFT_LINK            = &H1000C4E4??? '  /* Fallback sidestep left button */
%DIBUTTON_BASEBALLP_RIGHT_LINK           = &H1000C4EC??? '  /* Fallback sidestep right button */
%DIBUTTON_BASEBALLP_FORWARD_LINK         = &H100144E0??? '  /* Fallback move forward button */
%DIBUTTON_BASEBALLP_BACK_LINK            = &H100144E8??? '  /* Fallback move back button */
%DIBUTTON_BASEBALLP_DEVICE               = &H100044FE??? '  /* Show input device and controls */
%DIBUTTON_BASEBALLP_PAUSE                = &H100044FC??? '  /* Start / Pause / Restart game */

'  /*--- Sports - Baseball - Fielding
'      Fielder control is primary objective  ---*/
%DIVIRTUAL_SPORTS_BASEBALL_FIELD         = &H11000000???
%DIAXIS_BASEBALLF_LATERAL                = &H11008201??? '  /* Aim left / right */
%DIAXIS_BASEBALLF_MOVE                   = &H11010202??? '  /* Aim up / down */
%DIBUTTON_BASEBALLF_NEAREST              = &H11000401??? '  /* Switch to fielder nearest to the ball */
%DIBUTTON_BASEBALLF_THROW1               = &H11000402??? '  /* Make conservative throw */
%DIBUTTON_BASEBALLF_THROW2               = &H11000403??? '  /* Make aggressive throw */
%DIBUTTON_BASEBALLF_BURST                = &H11000404??? '  /* Invoke burst of speed */
%DIBUTTON_BASEBALLF_JUMP                 = &H11000405??? '  /* Jump to catch ball */
%DIBUTTON_BASEBALLF_DIVE                 = &H11000406??? '  /* Dive to catch ball */
%DIBUTTON_BASEBALLF_MENU                 = &H110004FD??? '  /* Show menu options */
'  /*--- Priority 2 controls                            ---*/

%DIBUTTON_BASEBALLF_SHIFTIN              = &H11004407??? '  /* Shift the infield positioning */
%DIBUTTON_BASEBALLF_SHIFTOUT             = &H11004408??? '  /* Shift the outfield positioning */
%DIBUTTON_BASEBALLF_AIM_LEFT_LINK        = &H1100C4E4??? '  /* Fallback aim left button */
%DIBUTTON_BASEBALLF_AIM_RIGHT_LINK       = &H1100C4EC??? '  /* Fallback aim right button */
%DIBUTTON_BASEBALLF_FORWARD_LINK         = &H110144E0??? '  /* Fallback move forward button */
%DIBUTTON_BASEBALLF_BACK_LINK            = &H110144E8??? '  /* Fallback move back button */
%DIBUTTON_BASEBALLF_DEVICE               = &H110044FE??? '  /* Show input device and controls */
%DIBUTTON_BASEBALLF_PAUSE                = &H110044FC??? '  /* Start / Pause / Restart game */

'  /*--- Sports - Basketball - Offense
'      Offense  ---*/
%DIVIRTUAL_SPORTS_BASKETBALL_OFFENSE     = &H12000000???
%DIAXIS_BBALLO_LATERAL                   = &H12008201??? '  /* left / right */
%DIAXIS_BBALLO_MOVE                      = &H12010202??? '  /* up / down */
%DIBUTTON_BBALLO_SHOOT                   = &H12000401??? '  /* shoot basket */
%DIBUTTON_BBALLO_DUNK                    = &H12000402??? '  /* dunk basket */
%DIBUTTON_BBALLO_PASS                    = &H12000403??? '  /* throw pass */
%DIBUTTON_BBALLO_FAKE                    = &H12000404??? '  /* fake shot or pass */
%DIBUTTON_BBALLO_SPECIAL                 = &H12000405??? '  /* apply special move */
%DIBUTTON_BBALLO_PLAYER                  = &H12000406??? '  /* select next player */
%DIBUTTON_BBALLO_BURST                   = &H12000407??? '  /* invoke burst */
%DIBUTTON_BBALLO_CALL                    = &H12000408??? '  /* call for ball / pass to me */
%DIBUTTON_BBALLO_MENU                    = &H120004FD??? '  /* Show menu options */
'  /*--- Priority 2 controls                            ---*/

%DIHATSWITCH_BBALLO_GLANCE               = &H12004601??? '  /* scroll view */
%DIBUTTON_BBALLO_SCREEN                  = &H12004409??? '  /* Call for screen */
%DIBUTTON_BBALLO_PLAY                    = &H1200440A??? '  /* Call for specific offensive play */
%DIBUTTON_BBALLO_JAB                     = &H1200440B??? '  /* Initiate fake drive to basket */
%DIBUTTON_BBALLO_POST                    = &H1200440C??? '  /* Perform post move */
%DIBUTTON_BBALLO_TIMEOUT                 = &H1200440D??? '  /* Time Out */
%DIBUTTON_BBALLO_SUBSTITUTE              = &H1200440E??? '  /* substitute one player for another */
%DIBUTTON_BBALLO_LEFT_LINK               = &H1200C4E4??? '  /* Fallback sidestep left button */
%DIBUTTON_BBALLO_RIGHT_LINK              = &H1200C4EC??? '  /* Fallback sidestep right button */
%DIBUTTON_BBALLO_FORWARD_LINK            = &H120144E0??? '  /* Fallback move forward button */
%DIBUTTON_BBALLO_BACK_LINK               = &H120144E8??? '  /* Fallback move back button */
%DIBUTTON_BBALLO_DEVICE                  = &H120044FE??? '  /* Show input device and controls */
%DIBUTTON_BBALLO_PAUSE                   = &H120044FC??? '  /* Start / Pause / Restart game */

'  /*--- Sports - Basketball - Defense
'      Defense  ---*/
%DIVIRTUAL_SPORTS_BASKETBALL_DEFENSE     = &H13000000???
%DIAXIS_BBALLD_LATERAL                   = &H13008201??? '  /* left / right */
%DIAXIS_BBALLD_MOVE                      = &H13010202??? '  /* up / down */
%DIBUTTON_BBALLD_JUMP                    = &H13000401??? '  /* jump to block shot */
%DIBUTTON_BBALLD_STEAL                   = &H13000402??? '  /* attempt to steal ball */
%DIBUTTON_BBALLD_FAKE                    = &H13000403??? '  /* fake block or steal */
%DIBUTTON_BBALLD_SPECIAL                 = &H13000404??? '  /* apply special move */
%DIBUTTON_BBALLD_PLAYER                  = &H13000405??? '  /* select next player */
%DIBUTTON_BBALLD_BURST                   = &H13000406??? '  /* invoke burst */
%DIBUTTON_BBALLD_PLAY                    = &H13000407??? '  /* call for specific defensive play */
%DIBUTTON_BBALLD_MENU                    = &H130004FD??? '  /* Show menu options */
'  /*--- Priority 2 controls                            ---*/

%DIHATSWITCH_BBALLD_GLANCE               = &H13004601??? '  /* scroll view */
%DIBUTTON_BBALLD_TIMEOUT                 = &H13004408??? '  /* Time Out */
%DIBUTTON_BBALLD_SUBSTITUTE              = &H13004409??? '  /* substitute one player for another */
%DIBUTTON_BBALLD_LEFT_LINK               = &H1300C4E4??? '  /* Fallback sidestep left button */
%DIBUTTON_BBALLD_RIGHT_LINK              = &H1300C4EC??? '  /* Fallback sidestep right button */
%DIBUTTON_BBALLD_FORWARD_LINK            = &H130144E0??? '  /* Fallback move forward button */
%DIBUTTON_BBALLD_BACK_LINK               = &H130144E8??? '  /* Fallback move back button */
%DIBUTTON_BBALLD_DEVICE                  = &H130044FE??? '  /* Show input device and controls */
%DIBUTTON_BBALLD_PAUSE                   = &H130044FC??? '  /* Start / Pause / Restart game */

'  /*--- Sports - Football - Play
'      Play selection  ---*/
%DIVIRTUAL_SPORTS_FOOTBALL_FIELD         = &H14000000???
%DIBUTTON_FOOTBALLP_PLAY                 = &H14000401??? '  /* cycle through available plays */
%DIBUTTON_FOOTBALLP_SELECT               = &H14000402??? '  /* select play */
%DIBUTTON_FOOTBALLP_HELP                 = &H14000403??? '  /* Bring up pop-up help */
%DIBUTTON_FOOTBALLP_MENU                 = &H140004FD??? '  /* Show menu options */
'  /*--- Priority 2 controls                            ---*/

%DIBUTTON_FOOTBALLP_DEVICE               = &H140044FE??? '  /* Show input device and controls */
%DIBUTTON_FOOTBALLP_PAUSE                = &H140044FC??? '  /* Start / Pause / Restart game */

'  /*--- Sports - Football - QB
'      Offense: Quarterback / Kicker  ---*/
%DIVIRTUAL_SPORTS_FOOTBALL_QBCK          = &H15000000???
%DIAXIS_FOOTBALLQ_LATERAL                = &H15008201??? '  /* Move / Aim: left / right */
%DIAXIS_FOOTBALLQ_MOVE                   = &H15010202??? '  /* Move / Aim: up / down */
%DIBUTTON_FOOTBALLQ_SELECT               = &H15000401??? '  /* Select */
%DIBUTTON_FOOTBALLQ_SNAP                 = &H15000402??? '  /* snap ball - start play */
%DIBUTTON_FOOTBALLQ_JUMP                 = &H15000403??? '  /* jump over defender */
%DIBUTTON_FOOTBALLQ_SLIDE                = &H15000404??? '  /* Dive/Slide */
%DIBUTTON_FOOTBALLQ_PASS                 = &H15000405??? '  /* throws pass to receiver */
%DIBUTTON_FOOTBALLQ_FAKE                 = &H15000406??? '  /* pump fake pass or fake kick */
%DIBUTTON_FOOTBALLQ_MENU                 = &H150004FD??? '  /* Show menu options */
'  /*--- Priority 2 controls                            ---*/

%DIBUTTON_FOOTBALLQ_FAKESNAP             = &H15004407??? '  /* Fake snap  */
%DIBUTTON_FOOTBALLQ_MOTION               = &H15004408??? '  /* Send receivers in motion */
%DIBUTTON_FOOTBALLQ_AUDIBLE              = &H15004409??? '  /* Change offensive play at line of scrimmage */
%DIBUTTON_FOOTBALLQ_LEFT_LINK            = &H1500C4E4??? '  /* Fallback sidestep left button */
%DIBUTTON_FOOTBALLQ_RIGHT_LINK           = &H1500C4EC??? '  /* Fallback sidestep right button */
%DIBUTTON_FOOTBALLQ_FORWARD_LINK         = &H150144E0??? '  /* Fallback move forward button */
%DIBUTTON_FOOTBALLQ_BACK_LINK            = &H150144E8??? '  /* Fallback move back button */
%DIBUTTON_FOOTBALLQ_DEVICE               = &H150044FE??? '  /* Show input device and controls */
%DIBUTTON_FOOTBALLQ_PAUSE                = &H150044FC??? '  /* Start / Pause / Restart game */

'  /*--- Sports - Football - Offense
'      Offense - Runner  ---*/
%DIVIRTUAL_SPORTS_FOOTBALL_OFFENSE       = &H16000000???
%DIAXIS_FOOTBALLO_LATERAL                = &H16008201??? '  /* Move / Aim: left / right */
%DIAXIS_FOOTBALLO_MOVE                   = &H16010202??? '  /* Move / Aim: up / down */
%DIBUTTON_FOOTBALLO_JUMP                 = &H16000401??? '  /* jump or hurdle over defender */
%DIBUTTON_FOOTBALLO_LEFTARM              = &H16000402??? '  /* holds out left arm */
%DIBUTTON_FOOTBALLO_RIGHTARM             = &H16000403??? '  /* holds out right arm */
%DIBUTTON_FOOTBALLO_THROW                = &H16000404??? '  /* throw pass or lateral ball to another runner */
%DIBUTTON_FOOTBALLO_SPIN                 = &H16000405??? '  /* Spin to avoid defenders */
%DIBUTTON_FOOTBALLO_MENU                 = &H160004FD??? '  /* Show menu options */
'  /*--- Priority 2 controls                            ---*/

%DIBUTTON_FOOTBALLO_JUKE                 = &H16004406??? '  /* Use special move to avoid defenders */
%DIBUTTON_FOOTBALLO_SHOULDER             = &H16004407??? '  /* Lower shoulder to run over defenders */
%DIBUTTON_FOOTBALLO_TURBO                = &H16004408??? '  /* Speed burst past defenders */
%DIBUTTON_FOOTBALLO_DIVE                 = &H16004409??? '  /* Dive over defenders */
%DIBUTTON_FOOTBALLO_ZOOM                 = &H1600440A??? '  /* Zoom view in / out */
%DIBUTTON_FOOTBALLO_SUBSTITUTE           = &H1600440B??? '  /* substitute one player for another */
%DIBUTTON_FOOTBALLO_LEFT_LINK            = &H1600C4E4??? '  /* Fallback sidestep left button */
%DIBUTTON_FOOTBALLO_RIGHT_LINK           = &H1600C4EC??? '  /* Fallback sidestep right button */
%DIBUTTON_FOOTBALLO_FORWARD_LINK         = &H160144E0??? '  /* Fallback move forward button */
%DIBUTTON_FOOTBALLO_BACK_LINK            = &H160144E8??? '  /* Fallback move back button */
%DIBUTTON_FOOTBALLO_DEVICE               = &H160044FE??? '  /* Show input device and controls */
%DIBUTTON_FOOTBALLO_PAUSE                = &H160044FC??? '  /* Start / Pause / Restart game */

'  /*--- Sports - Football - Defense
'      Defense     ---*/
%DIVIRTUAL_SPORTS_FOOTBALL_DEFENSE       = &H17000000???
%DIAXIS_FOOTBALLD_LATERAL                = &H17008201??? '  /* Move / Aim: left / right */
%DIAXIS_FOOTBALLD_MOVE                   = &H17010202??? '  /* Move / Aim: up / down */
%DIBUTTON_FOOTBALLD_PLAY                 = &H17000401??? '  /* cycle through available plays */
%DIBUTTON_FOOTBALLD_SELECT               = &H17000402??? '  /* select player closest to the ball */
%DIBUTTON_FOOTBALLD_JUMP                 = &H17000403??? '  /* jump to intercept or block */
%DIBUTTON_FOOTBALLD_TACKLE               = &H17000404??? '  /* tackler runner */
%DIBUTTON_FOOTBALLD_FAKE                 = &H17000405??? '  /* hold down to fake tackle or intercept */
%DIBUTTON_FOOTBALLD_SUPERTACKLE          = &H17000406??? '  /* Initiate special tackle */
%DIBUTTON_FOOTBALLD_MENU                 = &H170004FD??? '  /* Show menu options */
'  /*--- Priority 2 controls                            ---*/

%DIBUTTON_FOOTBALLD_SPIN                 = &H17004407??? '  /* Spin to beat offensive line */
%DIBUTTON_FOOTBALLD_SWIM                 = &H17004408??? '  /* Swim to beat the offensive line */
%DIBUTTON_FOOTBALLD_BULLRUSH             = &H17004409??? '  /* Bull rush the offensive line */
%DIBUTTON_FOOTBALLD_RIP                  = &H1700440A??? '  /* Rip the offensive line */
%DIBUTTON_FOOTBALLD_AUDIBLE              = &H1700440B??? '  /* Change defensive play at the line of scrimmage */
%DIBUTTON_FOOTBALLD_ZOOM                 = &H1700440C??? '  /* Zoom view in / out */
%DIBUTTON_FOOTBALLD_SUBSTITUTE           = &H1700440D??? '  /* substitute one player for another */
%DIBUTTON_FOOTBALLD_LEFT_LINK            = &H1700C4E4??? '  /* Fallback sidestep left button */
%DIBUTTON_FOOTBALLD_RIGHT_LINK           = &H1700C4EC??? '  /* Fallback sidestep right button */
%DIBUTTON_FOOTBALLD_FORWARD_LINK         = &H170144E0??? '  /* Fallback move forward button */
%DIBUTTON_FOOTBALLD_BACK_LINK            = &H170144E8??? '  /* Fallback move back button */
%DIBUTTON_FOOTBALLD_DEVICE               = &H170044FE??? '  /* Show input device and controls */
%DIBUTTON_FOOTBALLD_PAUSE                = &H170044FC??? '  /* Start / Pause / Restart game */

'  /*--- Sports - Golf
'                                ---*/
%DIVIRTUAL_SPORTS_GOLF                   = &H18000000???
%DIAXIS_GOLF_LATERAL                     = &H18008201??? '  /* Move / Aim: left / right */
%DIAXIS_GOLF_MOVE                        = &H18010202??? '  /* Move / Aim: up / down */
%DIBUTTON_GOLF_SWING                     = &H18000401??? '  /* swing club */
%DIBUTTON_GOLF_SELECT                    = &H18000402??? '  /* cycle between: club / swing strength / ball arc / ball spin */
%DIBUTTON_GOLF_UP                        = &H18000403??? '  /* increase selection */
%DIBUTTON_GOLF_DOWN                      = &H18000404??? '  /* decrease selection */
%DIBUTTON_GOLF_TERRAIN                   = &H18000405??? '  /* shows terrain detail */
%DIBUTTON_GOLF_FLYBY                     = &H18000406??? '  /* view the hole via a flyby */
%DIBUTTON_GOLF_MENU                      = &H180004FD??? '  /* Show menu options */
'  /*--- Priority 2 controls                            ---*/

%DIHATSWITCH_GOLF_SCROLL                 = &H18004601??? '  /* scroll view */
%DIBUTTON_GOLF_ZOOM                      = &H18004407??? '  /* Zoom view in / out */
%DIBUTTON_GOLF_TIMEOUT                   = &H18004408??? '  /* Call for time out */
%DIBUTTON_GOLF_SUBSTITUTE                = &H18004409??? '  /* substitute one player for another */
%DIBUTTON_GOLF_LEFT_LINK                 = &H1800C4E4??? '  /* Fallback sidestep left button */
%DIBUTTON_GOLF_RIGHT_LINK                = &H1800C4EC??? '  /* Fallback sidestep right button */
%DIBUTTON_GOLF_FORWARD_LINK              = &H180144E0??? '  /* Fallback move forward button */
%DIBUTTON_GOLF_BACK_LINK                 = &H180144E8??? '  /* Fallback move back button */
%DIBUTTON_GOLF_DEVICE                    = &H180044FE??? '  /* Show input device and controls */
%DIBUTTON_GOLF_PAUSE                     = &H180044FC??? '  /* Start / Pause / Restart game */

'  /*--- Sports - Hockey - Offense
'      Offense       ---*/
%DIVIRTUAL_SPORTS_HOCKEY_OFFENSE         = &H19000000???
%DIAXIS_HOCKEYO_LATERAL                  = &H19008201??? '  /* Move / Aim: left / right */
%DIAXIS_HOCKEYO_MOVE                     = &H19010202??? '  /* Move / Aim: up / down */
%DIBUTTON_HOCKEYO_SHOOT                  = &H19000401??? '  /* Shoot */
%DIBUTTON_HOCKEYO_PASS                   = &H19000402??? '  /* pass the puck */
%DIBUTTON_HOCKEYO_BURST                  = &H19000403??? '  /* invoke speed burst */
%DIBUTTON_HOCKEYO_SPECIAL                = &H19000404??? '  /* invoke special move */
%DIBUTTON_HOCKEYO_FAKE                   = &H19000405??? '  /* hold down to fake pass or kick */
%DIBUTTON_HOCKEYO_MENU                   = &H190004FD??? '  /* Show menu options */
'  /*--- Priority 2 controls                            ---*/

%DIHATSWITCH_HOCKEYO_SCROLL              = &H19004601??? '  /* scroll view */
%DIBUTTON_HOCKEYO_ZOOM                   = &H19004406??? '  /* Zoom view in / out */
%DIBUTTON_HOCKEYO_STRATEGY               = &H19004407??? '  /* Invoke coaching menu for strategy help */
%DIBUTTON_HOCKEYO_TIMEOUT                = &H19004408??? '  /* Call for time out */
%DIBUTTON_HOCKEYO_SUBSTITUTE             = &H19004409??? '  /* substitute one player for another */
%DIBUTTON_HOCKEYO_LEFT_LINK              = &H1900C4E4??? '  /* Fallback sidestep left button */
%DIBUTTON_HOCKEYO_RIGHT_LINK             = &H1900C4EC??? '  /* Fallback sidestep right button */
%DIBUTTON_HOCKEYO_FORWARD_LINK           = &H190144E0??? '  /* Fallback move forward button */
%DIBUTTON_HOCKEYO_BACK_LINK              = &H190144E8??? '  /* Fallback move back button */
%DIBUTTON_HOCKEYO_DEVICE                 = &H190044FE??? '  /* Show input device and controls */
%DIBUTTON_HOCKEYO_PAUSE                  = &H190044FC??? '  /* Start / Pause / Restart game */

'  /*--- Sports - Hockey - Defense
'      Defense       ---*/
%DIVIRTUAL_SPORTS_HOCKEY_DEFENSE         = &H1A000000???
%DIAXIS_HOCKEYD_LATERAL                  = &H1A008201??? '  /* Move / Aim: left / right */
%DIAXIS_HOCKEYD_MOVE                     = &H1A010202??? '  /* Move / Aim: up / down */
%DIBUTTON_HOCKEYD_PLAYER                 = &H1A000401??? '  /* control player closest to the puck */
%DIBUTTON_HOCKEYD_STEAL                  = &H1A000402??? '  /* attempt steal */
%DIBUTTON_HOCKEYD_BURST                  = &H1A000403??? '  /* speed burst or body check */
%DIBUTTON_HOCKEYD_BLOCK                  = &H1A000404??? '  /* block puck */
%DIBUTTON_HOCKEYD_FAKE                   = &H1A000405??? '  /* hold down to fake tackle or intercept */
%DIBUTTON_HOCKEYD_MENU                   = &H1A0004FD??? '  /* Show menu options */
'  /*--- Priority 2 controls                            ---*/

%DIHATSWITCH_HOCKEYD_SCROLL              = &H1A004601??? '  /* scroll view */
%DIBUTTON_HOCKEYD_ZOOM                   = &H1A004406??? '  /* Zoom view in / out */
%DIBUTTON_HOCKEYD_STRATEGY               = &H1A004407??? '  /* Invoke coaching menu for strategy help */
%DIBUTTON_HOCKEYD_TIMEOUT                = &H1A004408??? '  /* Call for time out */
%DIBUTTON_HOCKEYD_SUBSTITUTE             = &H1A004409??? '  /* substitute one player for another */
%DIBUTTON_HOCKEYD_LEFT_LINK              = &H1A00C4E4??? '  /* Fallback sidestep left button */
%DIBUTTON_HOCKEYD_RIGHT_LINK             = &H1A00C4EC??? '  /* Fallback sidestep right button */
%DIBUTTON_HOCKEYD_FORWARD_LINK           = &H1A0144E0??? '  /* Fallback move forward button */
%DIBUTTON_HOCKEYD_BACK_LINK              = &H1A0144E8??? '  /* Fallback move back button */
%DIBUTTON_HOCKEYD_DEVICE                 = &H1A0044FE??? '  /* Show input device and controls */
%DIBUTTON_HOCKEYD_PAUSE                  = &H1A0044FC??? '  /* Start / Pause / Restart game */

'  /*--- Sports - Hockey - Goalie
'      Goal tending  ---*/
%DIVIRTUAL_SPORTS_HOCKEY_GOALIE          = &H1B000000???
%DIAXIS_HOCKEYG_LATERAL                  = &H1B008201??? '  /* Move / Aim: left / right */
%DIAXIS_HOCKEYG_MOVE                     = &H1B010202??? '  /* Move / Aim: up / down */
%DIBUTTON_HOCKEYG_PASS                   = &H1B000401??? '  /* pass puck */
%DIBUTTON_HOCKEYG_POKE                   = &H1B000402??? '  /* poke / check / hack */
%DIBUTTON_HOCKEYG_STEAL                  = &H1B000403??? '  /* attempt steal */
%DIBUTTON_HOCKEYG_BLOCK                  = &H1B000404??? '  /* block puck */
%DIBUTTON_HOCKEYG_MENU                   = &H1B0004FD??? '  /* Show menu options */
'  /*--- Priority 2 controls                            ---*/

%DIHATSWITCH_HOCKEYG_SCROLL              = &H1B004601??? '  /* scroll view */
%DIBUTTON_HOCKEYG_ZOOM                   = &H1B004405??? '  /* Zoom view in / out */
%DIBUTTON_HOCKEYG_STRATEGY               = &H1B004406??? '  /* Invoke coaching menu for strategy help */
%DIBUTTON_HOCKEYG_TIMEOUT                = &H1B004407??? '  /* Call for time out */
%DIBUTTON_HOCKEYG_SUBSTITUTE             = &H1B004408??? '  /* substitute one player for another */
%DIBUTTON_HOCKEYG_LEFT_LINK              = &H1B00C4E4??? '  /* Fallback sidestep left button */
%DIBUTTON_HOCKEYG_RIGHT_LINK             = &H1B00C4EC??? '  /* Fallback sidestep right button */
%DIBUTTON_HOCKEYG_FORWARD_LINK           = &H1B0144E0??? '  /* Fallback move forward button */
%DIBUTTON_HOCKEYG_BACK_LINK              = &H1B0144E8??? '  /* Fallback move back button */
%DIBUTTON_HOCKEYG_DEVICE                 = &H1B0044FE??? '  /* Show input device and controls */
%DIBUTTON_HOCKEYG_PAUSE                  = &H1B0044FC??? '  /* Start / Pause / Restart game */

'  /*--- Sports - Mountain Biking
'                     ---*/
%DIVIRTUAL_SPORTS_BIKING_MOUNTAIN        = &H1C000000???
%DIAXIS_BIKINGM_TURN                     = &H1C008201??? '  /* left / right */
%DIAXIS_BIKINGM_PEDAL                    = &H1C010202??? '  /* Pedal faster / slower / brake */
%DIBUTTON_BIKINGM_JUMP                   = &H1C000401??? '  /* jump over obstacle */
%DIBUTTON_BIKINGM_CAMERA                 = &H1C000402??? '  /* switch camera view */
%DIBUTTON_BIKINGM_SPECIAL1               = &H1C000403??? '  /* perform first special move */
%DIBUTTON_BIKINGM_SELECT                 = &H1C000404??? '  /* Select */
%DIBUTTON_BIKINGM_SPECIAL2               = &H1C000405??? '  /* perform second special move */
%DIBUTTON_BIKINGM_MENU                   = &H1C0004FD??? '  /* Show menu options */
'  /*--- Priority 2 controls                            ---*/

%DIHATSWITCH_BIKINGM_SCROLL              = &H1C004601??? '  /* scroll view */
%DIBUTTON_BIKINGM_ZOOM                   = &H1C004406??? '  /* Zoom view in / out */
%DIAXIS_BIKINGM_BRAKE                    = &H1C044203??? '  /* Brake axis  */
%DIBUTTON_BIKINGM_LEFT_LINK              = &H1C00C4E4??? '  /* Fallback turn left button */
%DIBUTTON_BIKINGM_RIGHT_LINK             = &H1C00C4EC??? '  /* Fallback turn right button */
%DIBUTTON_BIKINGM_FASTER_LINK            = &H1C0144E0??? '  /* Fallback pedal faster button */
%DIBUTTON_BIKINGM_SLOWER_LINK            = &H1C0144E8??? '  /* Fallback pedal slower button */
%DIBUTTON_BIKINGM_BRAKE_BUTTON_LINK      = &H1C0444E8??? '  /* Fallback brake button */
%DIBUTTON_BIKINGM_DEVICE                 = &H1C0044FE??? '  /* Show input device and controls */
%DIBUTTON_BIKINGM_PAUSE                  = &H1C0044FC??? '  /* Start / Pause / Restart game */

'  /*--- Sports: Skiing / Snowboarding / Skateboarding
'        ---*/
%DIVIRTUAL_SPORTS_SKIING                 = &H1D000000???
%DIAXIS_SKIING_TURN                      = &H1D008201??? '  /* left / right */
%DIAXIS_SKIING_SPEED                     = &H1D010202??? '  /* faster / slower */
%DIBUTTON_SKIING_JUMP                    = &H1D000401??? '  /* Jump */
%DIBUTTON_SKIING_CROUCH                  = &H1D000402??? '  /* crouch down */
%DIBUTTON_SKIING_CAMERA                  = &H1D000403??? '  /* switch camera view */
%DIBUTTON_SKIING_SPECIAL1                = &H1D000404??? '  /* perform first special move */
%DIBUTTON_SKIING_SELECT                  = &H1D000405??? '  /* Select */
%DIBUTTON_SKIING_SPECIAL2                = &H1D000406??? '  /* perform second special move */
%DIBUTTON_SKIING_MENU                    = &H1D0004FD??? '  /* Show menu options */
'  /*--- Priority 2 controls                            ---*/

%DIHATSWITCH_SKIING_GLANCE               = &H1D004601??? '  /* scroll view */
%DIBUTTON_SKIING_ZOOM                    = &H1D004407??? '  /* Zoom view in / out */
%DIBUTTON_SKIING_LEFT_LINK               = &H1D00C4E4??? '  /* Fallback turn left button */
%DIBUTTON_SKIING_RIGHT_LINK              = &H1D00C4EC??? '  /* Fallback turn right button */
%DIBUTTON_SKIING_FASTER_LINK             = &H1D0144E0??? '  /* Fallback increase speed button */
%DIBUTTON_SKIING_SLOWER_LINK             = &H1D0144E8??? '  /* Fallback decrease speed button */
%DIBUTTON_SKIING_DEVICE                  = &H1D0044FE??? '  /* Show input device and controls */
%DIBUTTON_SKIING_PAUSE                   = &H1D0044FC??? '  /* Start / Pause / Restart game */

'  /*--- Sports - Soccer - Offense
'      Offense       ---*/
%DIVIRTUAL_SPORTS_SOCCER_OFFENSE         = &H1E000000???
%DIAXIS_SOCCERO_LATERAL                  = &H1E008201??? '  /* Move / Aim: left / right */
%DIAXIS_SOCCERO_MOVE                     = &H1E010202??? '  /* Move / Aim: up / down */
%DIAXIS_SOCCERO_BEND                     = &H1E018203??? '  /* Bend to soccer shot/pass */
%DIBUTTON_SOCCERO_SHOOT                  = &H1E000401??? '  /* Shoot the ball */
%DIBUTTON_SOCCERO_PASS                   = &H1E000402??? '  /* Pass  */
%DIBUTTON_SOCCERO_FAKE                   = &H1E000403??? '  /* Fake */
%DIBUTTON_SOCCERO_PLAYER                 = &H1E000404??? '  /* Select next player */
%DIBUTTON_SOCCERO_SPECIAL1               = &H1E000405??? '  /* Apply special move */
%DIBUTTON_SOCCERO_SELECT                 = &H1E000406??? '  /* Select special move */
%DIBUTTON_SOCCERO_MENU                   = &H1E0004FD??? '  /* Show menu options */
'  /*--- Priority 2 controls                            ---*/

%DIHATSWITCH_SOCCERO_GLANCE              = &H1E004601??? '  /* scroll view */
%DIBUTTON_SOCCERO_SUBSTITUTE             = &H1E004407??? '  /* Substitute one player for another */
%DIBUTTON_SOCCERO_SHOOTLOW               = &H1E004408??? '  /* Shoot the ball low */
%DIBUTTON_SOCCERO_SHOOTHIGH              = &H1E004409??? '  /* Shoot the ball high */
%DIBUTTON_SOCCERO_PASSTHRU               = &H1E00440A??? '  /* Make a thru pass */
%DIBUTTON_SOCCERO_SPRINT                 = &H1E00440B??? '  /* Sprint / turbo boost */
%DIBUTTON_SOCCERO_CONTROL                = &H1E00440C??? '  /* Obtain control of the ball */
%DIBUTTON_SOCCERO_HEAD                   = &H1E00440D??? '  /* Attempt to head the ball */
%DIBUTTON_SOCCERO_LEFT_LINK              = &H1E00C4E4??? '  /* Fallback sidestep left button */
%DIBUTTON_SOCCERO_RIGHT_LINK             = &H1E00C4EC??? '  /* Fallback sidestep right button */
%DIBUTTON_SOCCERO_FORWARD_LINK           = &H1E0144E0??? '  /* Fallback move forward button */
%DIBUTTON_SOCCERO_BACK_LINK              = &H1E0144E8??? '  /* Fallback move back button */
%DIBUTTON_SOCCERO_DEVICE                 = &H1E0044FE??? '  /* Show input device and controls */
%DIBUTTON_SOCCERO_PAUSE                  = &H1E0044FC??? '  /* Start / Pause / Restart game */

'  /*--- Sports - Soccer - Defense
'      Defense       ---*/
%DIVIRTUAL_SPORTS_SOCCER_DEFENSE         = &H1F000000???
%DIAXIS_SOCCERD_LATERAL                  = &H1F008201??? '  /* Move / Aim: left / right */
%DIAXIS_SOCCERD_MOVE                     = &H1F010202??? '  /* Move / Aim: up / down */
%DIBUTTON_SOCCERD_BLOCK                  = &H1F000401??? '  /* Attempt to block shot */
%DIBUTTON_SOCCERD_STEAL                  = &H1F000402??? '  /* Attempt to steal ball */
%DIBUTTON_SOCCERD_FAKE                   = &H1F000403??? '  /* Fake a block or a steal */
%DIBUTTON_SOCCERD_PLAYER                 = &H1F000404??? '  /* Select next player */
%DIBUTTON_SOCCERD_SPECIAL                = &H1F000405??? '  /* Apply special move */
%DIBUTTON_SOCCERD_SELECT                 = &H1F000406??? '  /* Select special move */
%DIBUTTON_SOCCERD_SLIDE                  = &H1F000407??? '  /* Attempt a slide tackle */
%DIBUTTON_SOCCERD_MENU                   = &H1F0004FD??? '  /* Show menu options */
'  /*--- Priority 2 controls                            ---*/

%DIHATSWITCH_SOCCERD_GLANCE              = &H1F004601??? '  /* scroll view */
%DIBUTTON_SOCCERD_FOUL                   = &H1F004408??? '  /* Initiate a foul / hard-foul */
%DIBUTTON_SOCCERD_HEAD                   = &H1F004409??? '  /* Attempt a Header */
%DIBUTTON_SOCCERD_CLEAR                  = &H1F00440A??? '  /* Attempt to clear the ball down the field */
%DIBUTTON_SOCCERD_GOALIECHARGE           = &H1F00440B??? '  /* Make the goalie charge out of the box */
%DIBUTTON_SOCCERD_SUBSTITUTE             = &H1F00440C??? '  /* Substitute one player for another */
%DIBUTTON_SOCCERD_LEFT_LINK              = &H1F00C4E4??? '  /* Fallback sidestep left button */
%DIBUTTON_SOCCERD_RIGHT_LINK             = &H1F00C4EC??? '  /* Fallback sidestep right button */
%DIBUTTON_SOCCERD_FORWARD_LINK           = &H1F0144E0??? '  /* Fallback move forward button */
%DIBUTTON_SOCCERD_BACK_LINK              = &H1F0144E8??? '  /* Fallback move back button */
%DIBUTTON_SOCCERD_DEVICE                 = &H1F0044FE??? '  /* Show input device and controls */
%DIBUTTON_SOCCERD_PAUSE                  = &H1F0044FC??? '  /* Start / Pause / Restart game */

'  /*--- Sports - Racquet
'      Tennis - Table-Tennis - Squash   ---*/
%DIVIRTUAL_SPORTS_RACQUET                = &H20000000???
%DIAXIS_RACQUET_LATERAL                  = &H20008201??? '  /* Move / Aim: left / right */
%DIAXIS_RACQUET_MOVE                     = &H20010202??? '  /* Move / Aim: up / down */
%DIBUTTON_RACQUET_SWING                  = &H20000401??? '  /* Swing racquet */
%DIBUTTON_RACQUET_BACKSWING              = &H20000402??? '  /* Swing backhand */
%DIBUTTON_RACQUET_SMASH                  = &H20000403??? '  /* Smash shot */
%DIBUTTON_RACQUET_SPECIAL                = &H20000404??? '  /* Special shot */
%DIBUTTON_RACQUET_SELECT                 = &H20000405??? '  /* Select special shot */
%DIBUTTON_RACQUET_MENU                   = &H200004FD??? '  /* Show menu options */
'  /*--- Priority 2 controls                            ---*/

%DIHATSWITCH_RACQUET_GLANCE              = &H20004601??? '  /* scroll view */
%DIBUTTON_RACQUET_TIMEOUT                = &H20004406??? '  /* Call for time out */
%DIBUTTON_RACQUET_SUBSTITUTE             = &H20004407??? '  /* Substitute one player for another */
%DIBUTTON_RACQUET_LEFT_LINK              = &H2000C4E4??? '  /* Fallback sidestep left button */
%DIBUTTON_RACQUET_RIGHT_LINK             = &H2000C4EC??? '  /* Fallback sidestep right button */
%DIBUTTON_RACQUET_FORWARD_LINK           = &H200144E0??? '  /* Fallback move forward button */
%DIBUTTON_RACQUET_BACK_LINK              = &H200144E8??? '  /* Fallback move back button */
%DIBUTTON_RACQUET_DEVICE                 = &H200044FE??? '  /* Show input device and controls */
%DIBUTTON_RACQUET_PAUSE                  = &H200044FC??? '  /* Start / Pause / Restart game */

'  /*--- Arcade- 2D
'      Side to Side movement        ---*/
%DIVIRTUAL_ARCADE_SIDE2SIDE              = &H21000000???
%DIAXIS_ARCADES_LATERAL                  = &H21008201??? '  /* left / right */
%DIAXIS_ARCADES_MOVE                     = &H21010202??? '  /* up / down */
%DIBUTTON_ARCADES_THROW                  = &H21000401??? '  /* throw object */
%DIBUTTON_ARCADES_CARRY                  = &H21000402??? '  /* carry object */
%DIBUTTON_ARCADES_ATTACK                 = &H21000403??? '  /* attack */
%DIBUTTON_ARCADES_SPECIAL                = &H21000404??? '  /* apply special move */
%DIBUTTON_ARCADES_SELECT                 = &H21000405??? '  /* select special move */
%DIBUTTON_ARCADES_MENU                   = &H210004FD??? '  /* Show menu options */
'  /*--- Priority 2 controls                            ---*/

%DIHATSWITCH_ARCADES_VIEW                = &H21004601??? '  /* scroll view left / right / up / down */
%DIBUTTON_ARCADES_LEFT_LINK              = &H2100C4E4??? '  /* Fallback sidestep left button */
%DIBUTTON_ARCADES_RIGHT_LINK             = &H2100C4EC??? '  /* Fallback sidestep right button */
%DIBUTTON_ARCADES_FORWARD_LINK           = &H210144E0??? '  /* Fallback move forward button */
%DIBUTTON_ARCADES_BACK_LINK              = &H210144E8??? '  /* Fallback move back button */
%DIBUTTON_ARCADES_VIEW_UP_LINK           = &H2107C4E0??? '  /* Fallback scroll view up button */
%DIBUTTON_ARCADES_VIEW_DOWN_LINK         = &H2107C4E8??? '  /* Fallback scroll view down button */
%DIBUTTON_ARCADES_VIEW_LEFT_LINK         = &H2107C4E4??? '  /* Fallback scroll view left button */
%DIBUTTON_ARCADES_VIEW_RIGHT_LINK        = &H2107C4EC??? '  /* Fallback scroll view right button */
%DIBUTTON_ARCADES_DEVICE                 = &H210044FE??? '  /* Show input device and controls */
%DIBUTTON_ARCADES_PAUSE                  = &H210044FC??? '  /* Start / Pause / Restart game */

'  /*--- Arcade - Platform Game
'      Character moves around on screen  ---*/
%DIVIRTUAL_ARCADE_PLATFORM               = &H22000000???
%DIAXIS_ARCADEP_LATERAL                  = &H22008201??? '  /* Left / right */
%DIAXIS_ARCADEP_MOVE                     = &H22010202??? '  /* Up / down */
%DIBUTTON_ARCADEP_JUMP                   = &H22000401??? '  /* Jump */
%DIBUTTON_ARCADEP_FIRE                   = &H22000402??? '  /* Fire */
%DIBUTTON_ARCADEP_CROUCH                 = &H22000403??? '  /* Crouch */
%DIBUTTON_ARCADEP_SPECIAL                = &H22000404??? '  /* Apply special move */
%DIBUTTON_ARCADEP_SELECT                 = &H22000405??? '  /* Select special move */
%DIBUTTON_ARCADEP_MENU                   = &H220004FD??? '  /* Show menu options */
'  /*--- Priority 2 controls                            ---*/

%DIHATSWITCH_ARCADEP_VIEW                = &H22004601??? '  /* Scroll view */
%DIBUTTON_ARCADEP_FIRESECONDARY          = &H22004406??? '  /* Alternative fire button */
%DIBUTTON_ARCADEP_LEFT_LINK              = &H2200C4E4??? '  /* Fallback sidestep left button */
%DIBUTTON_ARCADEP_RIGHT_LINK             = &H2200C4EC??? '  /* Fallback sidestep right button */
%DIBUTTON_ARCADEP_FORWARD_LINK           = &H220144E0??? '  /* Fallback move forward button */
%DIBUTTON_ARCADEP_BACK_LINK              = &H220144E8??? '  /* Fallback move back button */
%DIBUTTON_ARCADEP_VIEW_UP_LINK           = &H2207C4E0??? '  /* Fallback scroll view up button */
%DIBUTTON_ARCADEP_VIEW_DOWN_LINK         = &H2207C4E8??? '  /* Fallback scroll view down button */
%DIBUTTON_ARCADEP_VIEW_LEFT_LINK         = &H2207C4E4??? '  /* Fallback scroll view left button */
%DIBUTTON_ARCADEP_VIEW_RIGHT_LINK        = &H2207C4EC??? '  /* Fallback scroll view right button */
%DIBUTTON_ARCADEP_DEVICE                 = &H220044FE??? '  /* Show input device and controls */
%DIBUTTON_ARCADEP_PAUSE                  = &H220044FC??? '  /* Start / Pause / Restart game */

'  /*--- CAD - 2D Object Control
'      Controls to select and move objects in 2D  ---*/
%DIVIRTUAL_CAD_2DCONTROL                 = &H23000000???
%DIAXIS_2DCONTROL_LATERAL                = &H23008201??? '  /* Move view left / right */
%DIAXIS_2DCONTROL_MOVE                   = &H23010202??? '  /* Move view up / down */
%DIAXIS_2DCONTROL_INOUT                  = &H23018203??? '  /* Zoom - in / out */
%DIBUTTON_2DCONTROL_SELECT               = &H23000401??? '  /* Select Object */
%DIBUTTON_2DCONTROL_SPECIAL1             = &H23000402??? '  /* Do first special operation */
%DIBUTTON_2DCONTROL_SPECIAL              = &H23000403??? '  /* Select special operation */
%DIBUTTON_2DCONTROL_SPECIAL2             = &H23000404??? '  /* Do second special operation */
%DIBUTTON_2DCONTROL_MENU                 = &H230004FD??? '  /* Show menu options */
'  /*--- Priority 2 controls                            ---*/

%DIHATSWITCH_2DCONTROL_HATSWITCH         = &H23004601??? '  /* Hat switch */
%DIAXIS_2DCONTROL_ROTATEZ                = &H23024204??? '  /* Rotate view clockwise / counterclockwise */
%DIBUTTON_2DCONTROL_DISPLAY              = &H23004405??? '  /* Shows next on-screen display options */
%DIBUTTON_2DCONTROL_DEVICE               = &H230044FE??? '  /* Show input device and controls */
%DIBUTTON_2DCONTROL_PAUSE                = &H230044FC??? '  /* Start / Pause / Restart game */

'  /*--- CAD - 3D object control
'      Controls to select and move objects within a 3D environment  ---*/
%DIVIRTUAL_CAD_3DCONTROL                 = &H24000000???
%DIAXIS_3DCONTROL_LATERAL                = &H24008201??? '  /* Move view left / right */
%DIAXIS_3DCONTROL_MOVE                   = &H24010202??? '  /* Move view up / down */
%DIAXIS_3DCONTROL_INOUT                  = &H24018203??? '  /* Zoom - in / out */
%DIBUTTON_3DCONTROL_SELECT               = &H24000401??? '  /* Select Object */
%DIBUTTON_3DCONTROL_SPECIAL1             = &H24000402??? '  /* Do first special operation */
%DIBUTTON_3DCONTROL_SPECIAL              = &H24000403??? '  /* Select special operation */
%DIBUTTON_3DCONTROL_SPECIAL2             = &H24000404??? '  /* Do second special operation */
%DIBUTTON_3DCONTROL_MENU                 = &H240004FD??? '  /* Show menu options */
'  /*--- Priority 2 controls                            ---*/

%DIHATSWITCH_3DCONTROL_HATSWITCH         = &H24004601??? '  /* Hat switch */
%DIAXIS_3DCONTROL_ROTATEX                = &H24034204??? '  /* Rotate view forward or up / backward or down */
%DIAXIS_3DCONTROL_ROTATEY                = &H2402C205??? '  /* Rotate view clockwise / counterclockwise */
%DIAXIS_3DCONTROL_ROTATEZ                = &H24024206??? '  /* Rotate view left / right */
%DIBUTTON_3DCONTROL_DISPLAY              = &H24004405??? '  /* Show next on-screen display options */
%DIBUTTON_3DCONTROL_DEVICE               = &H240044FE??? '  /* Show input device and controls */
%DIBUTTON_3DCONTROL_PAUSE                = &H240044FC??? '  /* Start / Pause / Restart game */

'  /*--- CAD - 3D Navigation - Fly through
'      Controls for 3D modeling  ---*/
%DIVIRTUAL_CAD_FLYBY                     = &H25000000???
%DIAXIS_CADF_LATERAL                     = &H25008201??? '  /* move view left / right */
%DIAXIS_CADF_MOVE                        = &H25010202??? '  /* move view up / down */
%DIAXIS_CADF_INOUT                       = &H25018203??? '  /* in / out */
%DIBUTTON_CADF_SELECT                    = &H25000401??? '  /* Select Object */
%DIBUTTON_CADF_SPECIAL1                  = &H25000402??? '  /* do first special operation */
%DIBUTTON_CADF_SPECIAL                   = &H25000403??? '  /* Select special operation */
%DIBUTTON_CADF_SPECIAL2                  = &H25000404??? '  /* do second special operation */
%DIBUTTON_CADF_MENU                      = &H250004FD??? '  /* Show menu options */
'  /*--- Priority 2 controls                            ---*/

%DIHATSWITCH_CADF_HATSWITCH              = &H25004601??? '  /* Hat switch */
%DIAXIS_CADF_ROTATEX                     = &H25034204??? '  /* Rotate view forward or up / backward or down */
%DIAXIS_CADF_ROTATEY                     = &H2502C205??? '  /* Rotate view clockwise / counterclockwise */
%DIAXIS_CADF_ROTATEZ                     = &H25024206??? '  /* Rotate view left / right */
%DIBUTTON_CADF_DISPLAY                   = &H25004405??? '  /* shows next on-screen display options */
%DIBUTTON_CADF_DEVICE                    = &H250044FE??? '  /* Show input device and controls */
%DIBUTTON_CADF_PAUSE                     = &H250044FC??? '  /* Start / Pause / Restart game */

'  /*--- CAD - 3D Model Control
'      Controls for 3D modeling  ---*/
%DIVIRTUAL_CAD_MODEL                     = &H26000000???
%DIAXIS_CADM_LATERAL                     = &H26008201??? '  /* move view left / right */
%DIAXIS_CADM_MOVE                        = &H26010202??? '  /* move view up / down */
%DIAXIS_CADM_INOUT                       = &H26018203??? '  /* in / out */
%DIBUTTON_CADM_SELECT                    = &H26000401??? '  /* Select Object */
%DIBUTTON_CADM_SPECIAL1                  = &H26000402??? '  /* do first special operation */
%DIBUTTON_CADM_SPECIAL                   = &H26000403??? '  /* Select special operation */
%DIBUTTON_CADM_SPECIAL2                  = &H26000404??? '  /* do second special operation */
%DIBUTTON_CADM_MENU                      = &H260004FD??? '  /* Show menu options */
'  /*--- Priority 2 controls                            ---*/

%DIHATSWITCH_CADM_HATSWITCH              = &H26004601??? '  /* Hat switch */
%DIAXIS_CADM_ROTATEX                     = &H26034204??? '  /* Rotate view forward or up / backward or down */
%DIAXIS_CADM_ROTATEY                     = &H2602C205??? '  /* Rotate view clockwise / counterclockwise */
%DIAXIS_CADM_ROTATEZ                     = &H26024206??? '  /* Rotate view left / right */
%DIBUTTON_CADM_DISPLAY                   = &H26004405??? '  /* shows next on-screen display options */
%DIBUTTON_CADM_DEVICE                    = &H260044FE??? '  /* Show input device and controls */
%DIBUTTON_CADM_PAUSE                     = &H260044FC??? '  /* Start / Pause / Restart game */

'  /*--- Control - Media Equipment
'      Remote        ---*/
%DIVIRTUAL_REMOTE_CONTROL                = &H27000000???
%DIAXIS_REMOTE_SLIDER                    = &H27050201??? '  /* Slider for adjustment: volume / color / bass / etc */
%DIBUTTON_REMOTE_MUTE                    = &H27000401??? '  /* Set volume on current device to zero */
%DIBUTTON_REMOTE_SELECT                  = &H27000402??? '  /* Next/previous: channel/ track / chapter / picture / station */
%DIBUTTON_REMOTE_PLAY                    = &H27002403??? '  /* Start or pause entertainment on current device */
%DIBUTTON_REMOTE_CUE                     = &H27002404??? '  /* Move through current media */
%DIBUTTON_REMOTE_REVIEW                  = &H27002405??? '  /* Move through current media */
%DIBUTTON_REMOTE_CHANGE                  = &H27002406??? '  /* Select next device */
%DIBUTTON_REMOTE_RECORD                  = &H27002407??? '  /* Start recording the current media */
%DIBUTTON_REMOTE_MENU                    = &H270004FD??? '  /* Show menu options */
'  /*--- Priority 2 controls                            ---*/

%DIAXIS_REMOTE_SLIDER2                   = &H27054202??? '  /* Slider for adjustment: volume */
%DIBUTTON_REMOTE_TV                      = &H27005C08??? '  /* Select TV */
%DIBUTTON_REMOTE_CABLE                   = &H27005C09??? '  /* Select cable box */
%DIBUTTON_REMOTE_CD                      = &H27005C0A??? '  /* Select CD player */
%DIBUTTON_REMOTE_VCR                     = &H27005C0B??? '  /* Select VCR */
%DIBUTTON_REMOTE_TUNER                   = &H27005C0C??? '  /* Select tuner */
%DIBUTTON_REMOTE_DVD                     = &H27005C0D??? '  /* Select DVD player */
%DIBUTTON_REMOTE_ADJUST                  = &H27005C0E??? '  /* Enter device adjustment menu */
%DIBUTTON_REMOTE_DIGIT0                  = &H2700540F??? '  /* Digit 0 */
%DIBUTTON_REMOTE_DIGIT1                  = &H27005410??? '  /* Digit 1 */
%DIBUTTON_REMOTE_DIGIT2                  = &H27005411??? '  /* Digit 2 */
%DIBUTTON_REMOTE_DIGIT3                  = &H27005412??? '  /* Digit 3 */
%DIBUTTON_REMOTE_DIGIT4                  = &H27005413??? '  /* Digit 4 */
%DIBUTTON_REMOTE_DIGIT5                  = &H27005414??? '  /* Digit 5 */
%DIBUTTON_REMOTE_DIGIT6                  = &H27005415??? '  /* Digit 6 */
%DIBUTTON_REMOTE_DIGIT7                  = &H27005416??? '  /* Digit 7 */
%DIBUTTON_REMOTE_DIGIT8                  = &H27005417??? '  /* Digit 8 */
%DIBUTTON_REMOTE_DIGIT9                  = &H27005418??? '  /* Digit 9 */
%DIBUTTON_REMOTE_DEVICE                  = &H270044FE??? '  /* Show input device and controls */
%DIBUTTON_REMOTE_PAUSE                   = &H270044FC??? '  /* Start / Pause / Restart game */

'  /*--- Control- Web
'      Help or Browser            ---*/
%DIVIRTUAL_BROWSER_CONTROL               = &H28000000???
%DIAXIS_BROWSER_LATERAL                  = &H28008201??? '  /* Move on screen pointer */
%DIAXIS_BROWSER_MOVE                     = &H28010202??? '  /* Move on screen pointer */
%DIBUTTON_BROWSER_SELECT                 = &H28000401??? '  /* Select current item */
%DIAXIS_BROWSER_VIEW                     = &H28018203??? '  /* Move view up/down */
%DIBUTTON_BROWSER_REFRESH                = &H28000402??? '  /* Refresh */
%DIBUTTON_BROWSER_MENU                   = &H280004FD??? '  /* Show menu options */
'  /*--- Priority 2 controls                            ---*/

%DIBUTTON_BROWSER_SEARCH                 = &H28004403??? '  /* Use search tool */
%DIBUTTON_BROWSER_STOP                   = &H28004404??? '  /* Cease current update */
%DIBUTTON_BROWSER_HOME                   = &H28004405??? '  /* Go directly to "home" location */
%DIBUTTON_BROWSER_FAVORITES              = &H28004406??? '  /* Mark current site as favorite */
%DIBUTTON_BROWSER_NEXT                   = &H28004407??? '  /* Select Next page */
%DIBUTTON_BROWSER_PREVIOUS               = &H28004408??? '  /* Select Previous page */
%DIBUTTON_BROWSER_HISTORY                = &H28004409??? '  /* Show/Hide History */
%DIBUTTON_BROWSER_PRINT                  = &H2800440A??? '  /* Print current page */
%DIBUTTON_BROWSER_DEVICE                 = &H280044FE??? '  /* Show input device and controls */
%DIBUTTON_BROWSER_PAUSE                  = &H280044FC??? '  /* Start / Pause / Restart game */

'  /*--- Driving Simulator - Giant Walking Robot
'      Walking tank with weapons  ---*/
%DIVIRTUAL_DRIVING_MECHA                 = &H29000000???
%DIAXIS_MECHA_STEER                      = &H29008201??? '  /* Turns mecha left/right */
%DIAXIS_MECHA_TORSO                      = &H29010202??? '  /* Tilts torso forward/backward */
%DIAXIS_MECHA_ROTATE                     = &H29020203??? '  /* Turns torso left/right */
%DIAXIS_MECHA_THROTTLE                   = &H29038204??? '  /* Engine Speed */
%DIBUTTON_MECHA_FIRE                     = &H29000401??? '  /* Fire */
%DIBUTTON_MECHA_WEAPONS                  = &H29000402??? '  /* Select next weapon group */
%DIBUTTON_MECHA_TARGET                   = &H29000403??? '  /* Select closest enemy available target */
%DIBUTTON_MECHA_REVERSE                  = &H29000404??? '  /* Toggles throttle in/out of reverse */
%DIBUTTON_MECHA_ZOOM                     = &H29000405??? '  /* Zoom in/out targeting reticule */
%DIBUTTON_MECHA_JUMP                     = &H29000406??? '  /* Fires jump jets */
%DIBUTTON_MECHA_MENU                     = &H290004FD??? '  /* Show menu options */
'  /*--- Priority 2 controls                            ---*/

%DIBUTTON_MECHA_CENTER                   = &H29004407??? '  /* Center torso to legs */
%DIHATSWITCH_MECHA_GLANCE                = &H29004601??? '  /* Look around */
%DIBUTTON_MECHA_VIEW                     = &H29004408??? '  /* Cycle through view options */
%DIBUTTON_MECHA_FIRESECONDARY            = &H29004409??? '  /* Alternative fire button */
%DIBUTTON_MECHA_LEFT_LINK                = &H2900C4E4??? '  /* Fallback steer left button */
%DIBUTTON_MECHA_RIGHT_LINK               = &H2900C4EC??? '  /* Fallback steer right button */
%DIBUTTON_MECHA_FORWARD_LINK             = &H290144E0??? '  /* Fallback tilt torso forward button */
%DIBUTTON_MECHA_BACK_LINK                = &H290144E8??? '  /* Fallback tilt toroso backward button */
%DIBUTTON_MECHA_ROTATE_LEFT_LINK         = &H290244E4??? '  /* Fallback rotate toroso right button */
%DIBUTTON_MECHA_ROTATE_RIGHT_LINK        = &H290244EC??? '  /* Fallback rotate torso left button */
%DIBUTTON_MECHA_FASTER_LINK              = &H2903C4E0??? '  /* Fallback increase engine speed */
%DIBUTTON_MECHA_SLOWER_LINK              = &H2903C4E8??? '  /* Fallback decrease engine speed */
%DIBUTTON_MECHA_DEVICE                   = &H290044FE??? '  /* Show input device and controls */
%DIBUTTON_MECHA_PAUSE                    = &H290044FC??? '  /* Start / Pause / Restart game */

'  /*
' *  "ANY" semantics can be used as a last resort to get mappings for actions
' *  that match nothing in the chosen virtual genre.  These semantics will be
' *  mapped at a lower priority that virtual genre semantics.  Also, hardware
' *  vendors will not be able to provide sensible mappings for these unless
' *  they provide application specific mappings.
' */
%DIAXIS_ANY_X_1                          = &HFF00C201???
%DIAXIS_ANY_X_2                          = &HFF00C202???
%DIAXIS_ANY_Y_1                          = &HFF014201???
%DIAXIS_ANY_Y_2                          = &HFF014202???
%DIAXIS_ANY_Z_1                          = &HFF01C201???
%DIAXIS_ANY_Z_2                          = &HFF01C202???
%DIAXIS_ANY_R_1                          = &HFF024201???
%DIAXIS_ANY_R_2                          = &HFF024202???
%DIAXIS_ANY_U_1                          = &HFF02C201???
%DIAXIS_ANY_U_2                          = &HFF02C202???
%DIAXIS_ANY_V_1                          = &HFF034201???
%DIAXIS_ANY_V_2                          = &HFF034202???
%DIAXIS_ANY_A_1                          = &HFF03C201???
%DIAXIS_ANY_A_2                          = &HFF03C202???
%DIAXIS_ANY_B_1                          = &HFF044201???
%DIAXIS_ANY_B_2                          = &HFF044202???
%DIAXIS_ANY_C_1                          = &HFF04C201???
%DIAXIS_ANY_C_2                          = &HFF04C202???
%DIAXIS_ANY_S_1                          = &HFF054201???
%DIAXIS_ANY_S_2                          = &HFF054202???

%DIAXIS_ANY_1                            = &HFF004201???
%DIAXIS_ANY_2                            = &HFF004202???
%DIAXIS_ANY_3                            = &HFF004203???
%DIAXIS_ANY_4                            = &HFF004204???

%DIPOV_ANY_1                             = &HFF004601???
%DIPOV_ANY_2                             = &HFF004602???
%DIPOV_ANY_3                             = &HFF004603???
%DIPOV_ANY_4                             = &HFF004604???

'#define DIBUTTON_ANY(instance)                  ( 0xFF004400 | instance )
MACRO DIBUTTON_ANY(bInstance) = &HFF004400??? OR bInstance

'/****************************************************************************
' *
' *  Definitions for non-IDirectInput (VJoyD) features defined more recently
' *  than the current sdk files
' *
' ****************************************************************************/

'/****************************************************************************
' *
' *  Definitions for non-IDirectInput (VJoyD) features defined more recently
' *  than the current sdk files
' *
' ****************************************************************************/

'/*
' * Flag to indicate that the dwReserved2 field of the JOYINFOEX structure
' * contains mini-driver specific data to be passed by VJoyD to the mini-
' * driver instead of doing a poll.
' */
%JOY_PASSDRIVERDATA         = &H10000000???

'/*
' * Informs the joystick driver that the configuration has been changed
' * and should be reloaded from the registery.
' * dwFlags is reserved and should be set to zero
' */
'WINMMAPI MMRESULT WINAPI joyConfigChanged( DWORD dwFlags );
DECLARE FUNCTION joyConfigChanged IMPORT "WINMM.DLL" ALIAS "joyConfigChanged" ( _
   BYVAL dwFlags AS DWORD _                             ' DWORD dwFlags
 ) AS LONG                                              ' MMRESULT

'/*
' * Invoke the joystick control panel directly, using the passed window handle
' * as the parent of the dialog.  This API is only supported for compatibility
' * purposes; new applications should use the RunControlPanel method of a
' * device interface for a game controller.
' * The API is called by using the function pointer returned by
' * GetProcAddress( hCPL, TEXT("ShowJoyCPL") ) where hCPL is a HMODULE returned
' * by LoadLibrary( TEXT("joy.cpl") ).  The typedef is provided to allow
' * declaration and casting of an appropriately typed variable.
' */
'void WINAPI ShowJoyCPL( HWND hWnd );


'/*
' * Hardware Setting indicating that the device is a headtracker
' */
%JOY_HWS_ISHEADTRACKER       = &H02000000???

'/*
' * Hardware Setting indicating that the VxD is used to replace
' * the standard analog polling
' */
%JOY_HWS_ISGAMEPORTDRIVER    = &H04000000???

'/*
' * Hardware Setting indicating that the driver needs a standard
' * gameport in order to communicate with the device.
' */
%JOY_HWS_ISANALOGPORTDRIVER  = &H08000000???

'/*
' * Hardware Setting indicating that VJoyD should not load this
' * driver, it will be loaded externally and will register with
' * VJoyD of it's own accord.
' */
%JOY_HWS_AUTOLOAD            = &H10000000???

'/*
' * Hardware Setting indicating that the driver acquires any
' * resources needed without needing a devnode through VJoyD.
' */
%JOY_HWS_NODEVNODE           = &H20000000???


'/*
' * Hardware Setting indicating that the device is a gameport bus
' */
%JOY_HWS_ISGAMEPORTBUS       = &H80000000???
%JOY_HWS_GAMEPORTBUSBUSY     = &H00000001???

'/*
' * Usage Setting indicating that the settings are volatile and
' * should be removed if still present on a reboot.
' */
%JOY_US_VOLATILE             = &H00000008???

'/****************************************************************************
' *
' *  Definitions for non-IDirectInput (VJoyD) features defined more recently
' *  than the current ddk files
' *
' ****************************************************************************/

'#ifndef DIJ_RINGZERO

'#ifdef _INC_MMDDK
'#ifndef MMNOJOYDEV

'#ifndef __VJOYDXD_INCLUDED__
'#define __VJOYDXD_INCLUDED__
'/*
' * Poll type in which the do_other field of the JOYOEMPOLLDATA
' * structure contains mini-driver specific data passed from an app.
' */
'#define JOY_OEMPOLL_PASSDRIVERDATA  7
%JOY_OEMPOLL_PASSDRIVERDATA = 7

'#endif  /* __VJOYDXD_INCLUDED__ */

'#endif  /* not MMNOJOYDEV */
'#endif  /* _INC_MMDDK */

'#endif /* DIJ_RINGZERO */
