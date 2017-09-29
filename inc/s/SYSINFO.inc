' ########################################################################################
' Microsoft Windows
' File: SysInfo.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

' ########################################################################################
' Library name: SysInfoLib
' Version: 1.0, Locale ID = 0
' Documentation string: Microsoft SysInfo Control 6.0
' Path: C:\Software\OCXs\SYSINFO.OCX
' Library GUID: {6FBA474E-43AC-11CE-9A0E-00AA0062BB4C}
' Help file: C:\Software\OCXs\SysInf98.CHM
' ########################################################################################

#INCLUDE THIS ONCE
%SYSINFO_INC = 1

$RTLKEY = "E32E2733-1BC5-11d0-B8C3-00A0C90DCA10"

' ========================================================================================
' ClsIDs (Class identifiers)
' ========================================================================================

$CLSID_SysInfo = GUID$("{6FBA474B-43AC-11CE-9A0E-00AA0062BB4C}")

' ========================================================================================
' IIDs (Interface identifiers)
' ========================================================================================

$IID_DSysInfoEvents = GUID$("{6FBA474D-43AC-11CE-9A0E-00AA0062BB4C}")
$IID_ISysInfo = GUID$("{6FBA474C-43AC-11CE-9A0E-00AA0062BB4C}")

' ########################################################################################
' Interface name = ISysInfo
' IID = {6FBA474C-43AC-11CE-9A0E-00AA0062BB4C}
' Microsoft SysInfo Control
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%ISysInfo_INTERFACE_DEFINED)
    %ISysInfo_INTERFACE_DEFINED = 1

INTERFACE ISysInfo $IID_ISysInfo

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET ACStatus <1> ( _                        ' VTable offset = 28
   ) AS INTEGER                                         ' __out_retval short* piACStatus
   ' =====================================================================================
   PROPERTY GET BatteryFullTime <5> ( _                 ' VTable offset = 32
   ) AS LONG                                            ' __out_retval long* plBatteryFullTime
   ' =====================================================================================
   PROPERTY GET BatteryLifePercent <3> ( _              ' VTable offset = 36
   ) AS INTEGER                                         ' __out_retval short* psBatteryLifePercent
   ' =====================================================================================
   PROPERTY GET BatteryLifeTime <4> ( _                 ' VTable offset = 40
   ) AS LONG                                            ' __out_retval long* plBatteryLifeTime
   ' =====================================================================================
   PROPERTY GET BatteryStatus <2> ( _                   ' VTable offset = 44
   ) AS INTEGER                                         ' __out_retval short* psBatteryStatus
   ' =====================================================================================
   PROPERTY GET OSBuild <12> ( _                        ' VTable offset = 48
   ) AS INTEGER                                         ' __out_retval short* psOSBuild
   ' =====================================================================================
   PROPERTY GET OSPlatform <10> ( _                     ' VTable offset = 52
   ) AS INTEGER                                         ' __out_retval short* psOSPlatform
   ' =====================================================================================
   PROPERTY GET OSVersion <11> ( _                      ' VTable offset = 56
   ) AS SINGLE                                          ' __out_retval float* pfOSVersion
   ' =====================================================================================
   PROPERTY GET ScrollBarSize <13> ( _                  ' VTable offset = 60
   ) AS SINGLE                                          ' __out_retval float* pfScrollBarSize
   ' =====================================================================================
   PROPERTY GET WorkAreaHeight <8> ( _                  ' VTable offset = 64
   ) AS SINGLE                                          ' __out_retval float* pfWorkAreaHeight
   ' =====================================================================================
   PROPERTY GET WorkAreaLeft <7> ( _                    ' VTable offset = 68
   ) AS SINGLE                                          ' __out_retval float* pfWorkAreaLeft
   ' =====================================================================================
   PROPERTY GET WorkAreaTop <6> ( _                     ' VTable offset = 72
   ) AS SINGLE                                          ' __out_retval float* pfWorkAreaTop
   ' =====================================================================================
   PROPERTY GET WorkAreaWidth <9> ( _                   ' VTable offset = 76
   ) AS SINGLE                                          ' __out_retval float* pfWorkAreaWidth
   ' =====================================================================================
   METHOD AboutBox <-552> ( _                           ' VTable offset = 80
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISysInfo_INTERFACE_DEFINED__ */


' ########################################################################################
' Class CDSysInfoEvents
' Interface name = DSysInfoEvents
' IID = {6FBA474D-43AC-11CE-9A0E-00AA0062BB4C}
' Event interface for SysInfo controls
' Attributes = 4112 [&H1010] [Hidden] [Dispatchable]
' ########################################################################################

'CLASS CDSysInfoEvents GUID$("{0D708497-94C9-4459-8C69-06E722BB5A2C}") AS EVENT

'INTERFACE DSysInfoEventsImpl GUID$("{6FBA474D-43AC-11CE-9A0E-00AA0062BB4C}") AS EVENT

'  INHERIT IDispatch

'   ' =====================================================================================
'   METHOD ConfigChangeCancelled <18>

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD ConfigChanged <17> ( _
'     BYVAL OldConfigNum AS LONG _                       ' __in long OldConfigNum
'   , BYVAL NewConfigNum AS LONG _                       ' __in long NewConfigNum
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD DeviceArrival <10> ( _
'     BYVAL DeviceType AS LONG _                         ' __in long DeviceType
'   , BYVAL DeviceID AS LONG _                           ' __in long DeviceID
'   , BYVAL DeviceName AS WSTRING _                      ' __in BSTR DeviceName
'   , BYVAL DeviceData AS LONG _                         ' __in long DeviceData
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD DeviceOtherEvent <14> ( _
'     BYVAL DeviceType AS LONG _                         ' __in long DeviceType
'   , BYVAL EventName AS WSTRING _                       ' __in BSTR EventName
'   , BYVAL DataPointer AS LONG _                        ' __in long DataPointer
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD DeviceQueryRemove <13> ( _
'     BYVAL DeviceType AS LONG _                         ' __in long DeviceType
'   , BYVAL DeviceID AS LONG _                           ' __in long DeviceID
'   , BYVAL DeviceName AS WSTRING _                      ' __in BSTR DeviceName
'   , BYVAL DeviceData AS LONG _                         ' __in long DeviceData
'   , BYREF iCancel AS INTEGER _                         ' __out VARIANT_BOOL* Cancel
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD DeviceQueryRemoveFailed <11> ( _
'     BYVAL DeviceType AS LONG _                         ' __in long DeviceType
'   , BYVAL DeviceID AS LONG _                           ' __in long DeviceID
'   , BYVAL DeviceName AS WSTRING _                      ' __in BSTR DeviceName
'   , BYVAL DeviceData AS LONG _                         ' __in long DeviceData
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD DeviceRemoveComplete <15> ( _
'     BYVAL DeviceType AS LONG _                         ' __in long DeviceType
'   , BYVAL DeviceID AS LONG _                           ' __in long DeviceID
'   , BYVAL DeviceName AS WSTRING _                      ' __in BSTR DeviceName
'   , BYVAL DeviceData AS LONG _                         ' __in long DeviceData
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD DeviceRemovePending <12> ( _
'     BYVAL DeviceType AS LONG _                         ' __in long DeviceType
'   , BYVAL DeviceID AS LONG _                           ' __in long DeviceID
'   , BYVAL DeviceName AS WSTRING _                      ' __in BSTR DeviceName
'   , BYVAL DeviceData AS LONG _                         ' __in long DeviceData
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD DevModeChanged <9>

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD DisplayChanged <1>

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD PowerQuerySuspend <7> ( _
'     BYREF iCancel AS INTEGER _                         ' __out VARIANT_BOOL* Cancel
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD PowerResume <6>

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD PowerStatusChanged <8>

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD PowerSuspend <5>

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD QueryChangeConfig <16> ( _
'     BYREF iCancel AS INTEGER _                         ' __out VARIANT_BOOL* Cancel
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD SettingChanged <2> ( _
'     BYVAL iItem AS INTEGER _                           ' __in short Item
'   )                                                    ' void

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD SysColorsChanged <4>

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'   ' =====================================================================================
'   METHOD TimeChanged <3>

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'END INTERFACE

'END CLASS
