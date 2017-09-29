' ########################################################################################
' Microsoft Windows
' File: FaxCom.inc
' Library name: FAXCOMLib
' Version: 1.0, Locale ID = 0
' Library GUID: {87099223-C7AF-11D0-B225-00C04FB6C2F5}
' Path: C:\Windows\system32\FXSCOM.dll
' Contents: FaxCom 1.0 Type Library
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%FAXCOM_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "oaidl.inc"
#INCLUDE ONCE "ocidl.inc"

' ========================================================================================
' ProgIDs (Program identifiers)
' ========================================================================================

$PROGID_FaxServer1 = "FaxServer.FaxServer.1"
$PROGID_FaxTiff1 = "FaxTiff.FaxTiff.1"

' ========================================================================================
' Version Independent ProgIDs (Program identifiers)
' ========================================================================================

$PROGID_FaxServer = "FaxServer.FaxServer"
$PROGID_FaxTiff = "FaxTiff.FaxTiff"

' ========================================================================================
' ClsIDs (Class identifiers)
' ========================================================================================

$CLSID_FaxDoc = GUID$("{FA21F4C6-5C4C-11D1-83CF-00C04FB6E984}")
$CLSID_FaxJob = GUID$("{55DABFD6-5C9E-11D1-B791-000000000000}")
$CLSID_FaxJobs = GUID$("{55DABFD4-5C9E-11D1-B791-000000000000}")
$CLSID_FaxPort = GUID$("{D73733CD-CC80-11D0-B225-00C04FB6C2F5}")
$CLSID_FaxPorts = GUID$("{D73733D6-CC80-11D0-B225-00C04FB6C2F5}")
$CLSID_FaxRoutingMethod = GUID$("{2199F5F4-CEFC-11D0-A341-0000F800E68D}")
$CLSID_FaxRoutingMethods = GUID$("{2199F5F6-CEFC-11D0-A341-0000F800E68D}")
$CLSID_FaxServer = GUID$("{D73733C8-CC80-11D0-B225-00C04FB6C2F5}")
$CLSID_FaxStatus = GUID$("{8B97E606-D054-11D0-B226-00C04FB6C2F5}")
$CLSID_FaxTiff = GUID$("{87099231-C7AF-11D0-B225-00C04FB6C2F5}")

' ========================================================================================
' IIDs (Interface identifiers)
' ========================================================================================

$IID_IFaxDoc = GUID$("{FA21F4C5-5C4C-11D1-83CF-00C04FB6E984}")
$IID_IFaxJob = GUID$("{55DABFD5-5C9E-11D1-B791-000000000000}")
$IID_IFaxJobs = GUID$("{55DABFD3-5C9E-11D1-B791-000000000000}")
$IID_IFaxPort = GUID$("{D73733CC-CC80-11D0-B225-00C04FB6C2F5}")
$IID_IFaxPorts = GUID$("{D73733D5-CC80-11D0-B225-00C04FB6C2F5}")
$IID_IFaxRoutingMethod = GUID$("{2199F5F3-CEFC-11D0-A341-0000F800E68D}")
$IID_IFaxRoutingMethods = GUID$("{2199F5F5-CEFC-11D0-A341-0000F800E68D}")
$IID_IFaxServer = GUID$("{D73733C7-CC80-11D0-B225-00C04FB6C2F5}")
$IID_IFaxStatus = GUID$("{8B97E605-D054-11D0-B226-00C04FB6C2F5}")
$IID_IFaxTiff = GUID$("{B19BB45F-B91C-11D1-83E1-00C04FB6E984}")

' ########################################################################################
' Interface name = IFaxTiff
' IID = {B19BB45F-B91C-11D1-83E1-00C04FB6E984}
' IFaxTiff Interface
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IFaxTiff_INTERFACE_DEFINED)
    %IFaxTiff_INTERFACE_DEFINED = 1

INTERFACE IFaxTiff $IID_IFaxTiff

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET ReceiveTime <1> ( _                     ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   PROPERTY GET Image <2> ( _                           ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   PROPERTY SET Image <2> ( _                           ' VTable offset = 36
     BYVAL pVal AS WSTRING _                            ' __in BSTR in pVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET RecipientName <3> ( _                   ' VTable offset = 40
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   PROPERTY GET SenderName <4> ( _                      ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   PROPERTY GET Routing <5> ( _                         ' VTable offset = 48
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   PROPERTY GET CallerId <6> ( _                        ' VTable offset = 52
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   PROPERTY GET Csid <7> ( _                            ' VTable offset = 56
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   PROPERTY GET Tsid <8> ( _                            ' VTable offset = 60
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   PROPERTY GET RecipientNumber <9> ( _                 ' VTable offset = 64
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   PROPERTY GET RawReceiveTime <10> ( _                 ' VTable offset = 68
   ) AS VARIANT                                         ' __retval_out VARIANT *pVal
   ' =====================================================================================
   PROPERTY GET TiffTagString <11> ( _                  ' VTable offset = 72
     BYVAL tagID AS WORD _                              ' __in WORD tagID
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IFaxTiff_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IFaxServer
' IID = {D73733C7-CC80-11D0-B225-00C04FB6C2F5}
' IFaxServer Interface
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IFaxServer_INTERFACE_DEFINED)
    %IFaxServer_INTERFACE_DEFINED = 1

INTERFACE IFaxServer $IID_IFaxServer

   INHERIT IDispatch

   ' =====================================================================================
   METHOD Connect <1> ( _                               ' VTable offset = 28
     BYVAL ServerName AS WSTRING _                      ' __in BSTR ServerName
   )                                                    ' void
   ' =====================================================================================
   METHOD Disconnect <2> ( _                            ' VTable offset = 32
   )                                                    ' void
   ' =====================================================================================
   METHOD GetPorts <3> ( _                              ' VTable offset = 36
   ) AS VARIANT                                         ' __retval_out VARIANT *retval
   ' =====================================================================================
   METHOD CreateDocument <4> ( _                        ' VTable offset = 40
     BYVAL FileName AS WSTRING _                        ' __in BSTR FileName
   ) AS VARIANT                                         ' __retval_out VARIANT *retval
   ' =====================================================================================
   METHOD GetJobs <5> ( _                               ' VTable offset = 44
   ) AS VARIANT                                         ' __retval_out VARIANT *retval
   ' =====================================================================================
   PROPERTY GET Retries <6> ( _                         ' VTable offset = 48
   ) AS LONG                                            ' __retval_out long *pVal
   ' =====================================================================================
   PROPERTY SET Retries <6> ( _                         ' VTable offset = 52
     BYVAL pVal AS LONG _                               ' __in long pVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET RetryDelay <7> ( _                      ' VTable offset = 56
   ) AS LONG                                            ' __retval_out long *pVal
   ' =====================================================================================
   PROPERTY SET RetryDelay <7> ( _                      ' VTable offset = 60
     BYVAL pVal AS LONG _                               ' __in long pVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DirtyDays <8> ( _                       ' VTable offset = 64
   ) AS LONG                                            ' __retval_out long *pVal
   ' =====================================================================================
   PROPERTY SET DirtyDays <8> ( _                       ' VTable offset = 68
     BYVAL pVal AS LONG _                               ' __in long pVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Branding <9> ( _                        ' VTable offset = 72
   ) AS LONG                                            ' __retval_out long *pVal
   ' =====================================================================================
   PROPERTY SET Branding <9> ( _                        ' VTable offset = 76
     BYVAL pVal AS LONG _                               ' __in long pVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET UseDeviceTsid <10> ( _                  ' VTable offset = 80
   ) AS LONG                                            ' __retval_out long *pVal
   ' =====================================================================================
   PROPERTY SET UseDeviceTsid <10> ( _                  ' VTable offset = 84
     BYVAL pVal AS LONG _                               ' __in long pVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ServerCoverpage <11> ( _                ' VTable offset = 88
   ) AS LONG                                            ' __retval_out long *pVal
   ' =====================================================================================
   PROPERTY SET ServerCoverpage <11> ( _                ' VTable offset = 92
     BYVAL pVal AS LONG _                               ' __in long pVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET PauseServerQueue <12> ( _               ' VTable offset = 96
   ) AS LONG                                            ' __retval_out long *pVal
   ' =====================================================================================
   PROPERTY SET PauseServerQueue <12> ( _               ' VTable offset = 100
     BYVAL pVal AS LONG _                               ' __in long pVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ArchiveOutboundFaxes <13> ( _           ' VTable offset = 104
   ) AS LONG                                            ' __retval_out long *pVal
   ' =====================================================================================
   PROPERTY SET ArchiveOutboundFaxes <13> ( _           ' VTable offset = 108
     BYVAL pVal AS LONG _                               ' __in long pVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ArchiveDirectory <14> ( _               ' VTable offset = 112
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   PROPERTY SET ArchiveDirectory <14> ( _               ' VTable offset = 116
     BYVAL pVal AS WSTRING _                            ' __in BSTR in pVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ServerMapiProfile <15> ( _              ' VTable offset = 120
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   PROPERTY SET ServerMapiProfile <15> ( _              ' VTable offset = 124
     BYVAL pVal AS WSTRING _                            ' __in BSTR in pVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DiscountRateStartHour <16> ( _          ' VTable offset = 128
   ) AS INTEGER                                         ' __retval_out short *pVal
   ' =====================================================================================
   PROPERTY SET DiscountRateStartHour <16> ( _          ' VTable offset = 132
     BYVAL pVal AS INTEGER _                            ' __in short pVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DiscountRateStartMinute <17> ( _        ' VTable offset = 136
   ) AS INTEGER                                         ' __retval_out short *pVal
   ' =====================================================================================
   PROPERTY SET DiscountRateStartMinute <17> ( _        ' VTable offset = 140
     BYVAL pVal AS INTEGER _                            ' __in short pVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DiscountRateEndHour <18> ( _            ' VTable offset = 144
   ) AS INTEGER                                         ' __retval_out short *pVal
   ' =====================================================================================
   PROPERTY SET DiscountRateEndHour <18> ( _            ' VTable offset = 148
     BYVAL pVal AS INTEGER _                            ' __in short pVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DiscountRateEndMinute <19> ( _          ' VTable offset = 152
   ) AS INTEGER                                         ' __retval_out short *pVal
   ' =====================================================================================
   PROPERTY SET DiscountRateEndMinute <19> ( _          ' VTable offset = 156
     BYVAL pVal AS INTEGER _                            ' __in short pVal
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IFaxServer_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IFaxPort
' IID = {D73733CC-CC80-11D0-B225-00C04FB6C2F5}
' IFaxPort Interface
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IFaxPort_INTERFACE_DEFINED)
    %IFaxPort_INTERFACE_DEFINED = 1

INTERFACE IFaxPort $IID_IFaxPort

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Name <1> ( _                            ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   PROPERTY GET DeviceId <2> ( _                        ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long *pVal
   ' =====================================================================================
   PROPERTY GET Rings <3> ( _                           ' VTable offset = 36
   ) AS LONG                                            ' __retval_out long *pVal
   ' =====================================================================================
   PROPERTY SET Rings <3> ( _                           ' VTable offset = 40
     BYVAL pVal AS LONG _                               ' __in long pVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Csid <4> ( _                            ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   PROPERTY SET Csid <4> ( _                            ' VTable offset = 48
     BYVAL pVal AS WSTRING _                            ' __in BSTR in pVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Tsid <5> ( _                            ' VTable offset = 52
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   PROPERTY SET Tsid <5> ( _                            ' VTable offset = 56
     BYVAL pVal AS WSTRING _                            ' __in BSTR in pVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Send <6> ( _                            ' VTable offset = 60
   ) AS LONG                                            ' __retval_out long *pVal
   ' =====================================================================================
   PROPERTY SET Send <6> ( _                            ' VTable offset = 64
     BYVAL pVal AS LONG _                               ' __in long pVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Receive <7> ( _                         ' VTable offset = 68
   ) AS LONG                                            ' __retval_out long *pVal
   ' =====================================================================================
   PROPERTY SET Receive <7> ( _                         ' VTable offset = 72
     BYVAL pVal AS LONG _                               ' __in long pVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Priority <8> ( _                        ' VTable offset = 76
   ) AS LONG                                            ' __retval_out long *pVal
   ' =====================================================================================
   PROPERTY SET Priority <8> ( _                        ' VTable offset = 80
     BYVAL pVal AS LONG _                               ' __in long pVal
   )                                                    ' void
   ' =====================================================================================
   METHOD GetRoutingMethods <9> ( _                     ' VTable offset = 84
   ) AS VARIANT                                         ' __retval_out VARIANT *retval
   ' =====================================================================================
   PROPERTY GET CanModify <10> ( _                      ' VTable offset = 88
   ) AS LONG                                            ' __retval_out long *pVal
   ' =====================================================================================
   METHOD GetStatus <11> ( _                            ' VTable offset = 92
   ) AS VARIANT                                         ' __retval_out VARIANT *retval
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IFaxPort_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IFaxPorts
' IID = {D73733D5-CC80-11D0-B225-00C04FB6C2F5}
' IFaxPorts Interface
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IFaxPorts_INTERFACE_DEFINED)
    %IFaxPorts_INTERFACE_DEFINED = 1

INTERFACE IFaxPorts $IID_IFaxPorts

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long *pVal
   ' =====================================================================================
   PROPERTY GET Item <2> ( _                            ' VTable offset = 32
     BYVAL Index AS LONG _                              ' __in long Index
   ) AS VARIANT                                         ' __retval_out VARIANT *pVal
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IFaxPorts_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IFaxRoutingMethod
' IID = {2199F5F3-CEFC-11D0-A341-0000F800E68D}
' IFaxRoutingMethod Interface
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IFaxRoutingMethod_INTERFACE_DEFINED)
    %IFaxRoutingMethod_INTERFACE_DEFINED = 1

INTERFACE IFaxRoutingMethod $IID_IFaxRoutingMethod

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET DeviceId <1> ( _                        ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long *pVal
   ' =====================================================================================
   PROPERTY GET Enable <2> ( _                          ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long *pVal
   ' =====================================================================================
   PROPERTY SET Enable <2> ( _                          ' VTable offset = 36
     BYVAL pVal AS LONG _                               ' __in long pVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DeviceName <3> ( _                      ' VTable offset = 40
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   PROPERTY GET Guid <4> ( _                            ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   PROPERTY GET FunctionName <5> ( _                    ' VTable offset = 48
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   PROPERTY GET ImageName <6> ( _                       ' VTable offset = 52
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   PROPERTY GET FriendlyName <7> ( _                    ' VTable offset = 56
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   PROPERTY GET ExtensionName <8> ( _                   ' VTable offset = 60
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   PROPERTY GET RoutingData <9> ( _                     ' VTable offset = 64
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IFaxRoutingMethod_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IFaxRoutingMethods
' IID = {2199F5F5-CEFC-11D0-A341-0000F800E68D}
' IFaxRoutingMethod Interface
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IFaxRoutingMethods_INTERFACE_DEFINED)
    %IFaxRoutingMethods_INTERFACE_DEFINED = 1

INTERFACE IFaxRoutingMethods $IID_IFaxRoutingMethods

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long *pVal
   ' =====================================================================================
   PROPERTY GET Item <2> ( _                            ' VTable offset = 32
     BYVAL Index AS LONG _                              ' __in long Index
   ) AS VARIANT                                         ' __retval_out VARIANT *pVal
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IFaxRoutingMethods_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IFaxStatus
' IID = {8B97E605-D054-11D0-B226-00C04FB6C2F5}
' IFaxStatus Interface
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IFaxStatus_INTERFACE_DEFINED)
    %IFaxStatus_INTERFACE_DEFINED = 1

INTERFACE IFaxStatus $IID_IFaxStatus

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET CallerId <1> ( _                        ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   PROPERTY GET Csid <2> ( _                            ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   PROPERTY GET CurrentPage <3> ( _                     ' VTable offset = 36
   ) AS LONG                                            ' __retval_out long *pVal
   ' =====================================================================================
   PROPERTY GET DeviceId <4> ( _                        ' VTable offset = 40
   ) AS LONG                                            ' __retval_out long *pVal
   ' =====================================================================================
   PROPERTY GET DeviceName <5> ( _                      ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   PROPERTY GET DocumentName <6> ( _                    ' VTable offset = 48
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   PROPERTY GET Send <8> ( _                            ' VTable offset = 52
   ) AS LONG                                            ' __retval_out long *pVal
   ' =====================================================================================
   PROPERTY GET Receive <9> ( _                         ' VTable offset = 56
   ) AS LONG                                            ' __retval_out long *pVal
   ' =====================================================================================
   PROPERTY GET Address <10> ( _                        ' VTable offset = 60
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   PROPERTY GET RoutingString <12> ( _                  ' VTable offset = 64
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   PROPERTY GET SenderName <13> ( _                     ' VTable offset = 68
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   PROPERTY GET RecipientName <14> ( _                  ' VTable offset = 72
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   PROPERTY GET DocumentSize <15> ( _                   ' VTable offset = 76
   ) AS LONG                                            ' __retval_out long *pVal
   ' =====================================================================================
   PROPERTY GET Description <16> ( _                    ' VTable offset = 80
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   PROPERTY GET PageCount <17> ( _                      ' VTable offset = 84
   ) AS LONG                                            ' __retval_out long *pVal
   ' =====================================================================================
   PROPERTY GET Tsid <18> ( _                           ' VTable offset = 88
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   PROPERTY GET StartTime <19> ( _                      ' VTable offset = 92
   ) AS DOUBLE                                          ' __retval_out DATE *pVal
   ' =====================================================================================
   PROPERTY GET SubmittedTime <20> ( _                  ' VTable offset = 96
   ) AS DOUBLE                                          ' __retval_out DATE *pVal
   ' =====================================================================================
   PROPERTY GET ElapsedTime <21> ( _                    ' VTable offset = 100
   ) AS DOUBLE                                          ' __retval_out DATE *pVal
   ' =====================================================================================
   METHOD Refresh <22> ( _                              ' VTable offset = 104
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IFaxStatus_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IFaxDoc
' IID = {FA21F4C5-5C4C-11D1-83CF-00C04FB6E984}
' IFaxDoc Interface
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IFaxDoc_INTERFACE_DEFINED)
    %IFaxDoc_INTERFACE_DEFINED = 1

INTERFACE IFaxDoc $IID_IFaxDoc

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET FileName <1> ( _                        ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   PROPERTY SET FileName <1> ( _                        ' VTable offset = 32
     BYVAL pVal AS WSTRING _                            ' __in BSTR in pVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CoverpageName <2> ( _                   ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   PROPERTY SET CoverpageName <2> ( _                   ' VTable offset = 40
     BYVAL pVal AS WSTRING _                            ' __in BSTR in pVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SendCoverpage <3> ( _                   ' VTable offset = 44
   ) AS LONG                                            ' __retval_out long *pVal
   ' =====================================================================================
   PROPERTY SET SendCoverpage <3> ( _                   ' VTable offset = 48
     BYVAL pVal AS LONG _                               ' __in long pVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ServerCoverpage <4> ( _                 ' VTable offset = 52
   ) AS LONG                                            ' __retval_out long *pVal
   ' =====================================================================================
   PROPERTY SET ServerCoverpage <4> ( _                 ' VTable offset = 56
     BYVAL pVal AS LONG _                               ' __in long pVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DiscountSend <5> ( _                    ' VTable offset = 60
   ) AS LONG                                            ' __retval_out long *pVal
   ' =====================================================================================
   PROPERTY SET DiscountSend <5> ( _                    ' VTable offset = 64
     BYVAL pVal AS LONG _                               ' __in long pVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET RecipientName <6> ( _                   ' VTable offset = 68
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   PROPERTY SET RecipientName <6> ( _                   ' VTable offset = 72
     BYVAL pVal AS WSTRING _                            ' __in BSTR in pVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET RecipientCompany <7> ( _                ' VTable offset = 76
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   PROPERTY SET RecipientCompany <7> ( _                ' VTable offset = 80
     BYVAL pVal AS WSTRING _                            ' __in BSTR in pVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET RecipientAddress <8> ( _                ' VTable offset = 84
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   PROPERTY SET RecipientAddress <8> ( _                ' VTable offset = 88
     BYVAL pVal AS WSTRING _                            ' __in BSTR in pVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET RecipientCity <9> ( _                   ' VTable offset = 92
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   PROPERTY SET RecipientCity <9> ( _                   ' VTable offset = 96
     BYVAL pVal AS WSTRING _                            ' __in BSTR in pVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET RecipientState <10> ( _                 ' VTable offset = 100
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   PROPERTY SET RecipientState <10> ( _                 ' VTable offset = 104
     BYVAL pVal AS WSTRING _                            ' __in BSTR in pVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET RecipientZip <11> ( _                   ' VTable offset = 108
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   PROPERTY SET RecipientZip <11> ( _                   ' VTable offset = 112
     BYVAL pVal AS WSTRING _                            ' __in BSTR in pVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET RecipientCountry <12> ( _               ' VTable offset = 116
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   PROPERTY SET RecipientCountry <12> ( _               ' VTable offset = 120
     BYVAL pVal AS WSTRING _                            ' __in BSTR in pVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET RecipientTitle <13> ( _                 ' VTable offset = 124
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   PROPERTY SET RecipientTitle <13> ( _                 ' VTable offset = 128
     BYVAL pVal AS WSTRING _                            ' __in BSTR in pVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET RecipientDepartment <14> ( _            ' VTable offset = 132
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   PROPERTY SET RecipientDepartment <14> ( _            ' VTable offset = 136
     BYVAL pVal AS WSTRING _                            ' __in BSTR in pVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET RecipientOffice <15> ( _                ' VTable offset = 140
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   PROPERTY SET RecipientOffice <15> ( _                ' VTable offset = 144
     BYVAL pVal AS WSTRING _                            ' __in BSTR in pVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET RecipientHomePhone <16> ( _             ' VTable offset = 148
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   PROPERTY SET RecipientHomePhone <16> ( _             ' VTable offset = 152
     BYVAL pVal AS WSTRING _                            ' __in BSTR in pVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET RecipientOfficePhone <17> ( _           ' VTable offset = 156
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   PROPERTY SET RecipientOfficePhone <17> ( _           ' VTable offset = 160
     BYVAL pVal AS WSTRING _                            ' __in BSTR in pVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SenderName <18> ( _                     ' VTable offset = 164
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   PROPERTY SET SenderName <18> ( _                     ' VTable offset = 168
     BYVAL pVal AS WSTRING _                            ' __in BSTR in pVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SenderCompany <19> ( _                  ' VTable offset = 172
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   PROPERTY SET SenderCompany <19> ( _                  ' VTable offset = 176
     BYVAL pVal AS WSTRING _                            ' __in BSTR in pVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SenderAddress <20> ( _                  ' VTable offset = 180
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   PROPERTY SET SenderAddress <20> ( _                  ' VTable offset = 184
     BYVAL pVal AS WSTRING _                            ' __in BSTR in pVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SenderTitle <21> ( _                    ' VTable offset = 188
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   PROPERTY SET SenderTitle <21> ( _                    ' VTable offset = 192
     BYVAL pVal AS WSTRING _                            ' __in BSTR in pVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SenderDepartment <22> ( _               ' VTable offset = 196
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   PROPERTY SET SenderDepartment <22> ( _               ' VTable offset = 200
     BYVAL pVal AS WSTRING _                            ' __in BSTR in pVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SenderOffice <23> ( _                   ' VTable offset = 204
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   PROPERTY SET SenderOffice <23> ( _                   ' VTable offset = 208
     BYVAL pVal AS WSTRING _                            ' __in BSTR in pVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SenderHomePhone <24> ( _                ' VTable offset = 212
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   PROPERTY SET SenderHomePhone <24> ( _                ' VTable offset = 216
     BYVAL pVal AS WSTRING _                            ' __in BSTR in pVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SenderOfficePhone <25> ( _              ' VTable offset = 220
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   PROPERTY SET SenderOfficePhone <25> ( _              ' VTable offset = 224
     BYVAL pVal AS WSTRING _                            ' __in BSTR in pVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CoverpageNote <26> ( _                  ' VTable offset = 228
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   PROPERTY SET CoverpageNote <26> ( _                  ' VTable offset = 232
     BYVAL pVal AS WSTRING _                            ' __in BSTR in pVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CoverpageSubject <27> ( _               ' VTable offset = 236
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   PROPERTY SET CoverpageSubject <27> ( _               ' VTable offset = 240
     BYVAL pVal AS WSTRING _                            ' __in BSTR in pVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Tsid <28> ( _                           ' VTable offset = 244
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   PROPERTY SET Tsid <28> ( _                           ' VTable offset = 248
     BYVAL pVal AS WSTRING _                            ' __in BSTR in pVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET BillingCode <29> ( _                    ' VTable offset = 252
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   PROPERTY SET BillingCode <29> ( _                    ' VTable offset = 256
     BYVAL pVal AS WSTRING _                            ' __in BSTR in pVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET EmailAddress <30> ( _                   ' VTable offset = 260
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   PROPERTY SET EmailAddress <30> ( _                   ' VTable offset = 264
     BYVAL pVal AS WSTRING _                            ' __in BSTR in pVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DisplayName <31> ( _                    ' VTable offset = 268
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   PROPERTY SET DisplayName <31> ( _                    ' VTable offset = 272
     BYVAL pVal AS WSTRING _                            ' __in BSTR in pVal
   )                                                    ' void
   ' =====================================================================================
   METHOD Send <32> ( _                                 ' VTable offset = 276
   ) AS LONG                                            ' __retval_out long *pVal
   ' =====================================================================================
   PROPERTY GET FaxNumber <33> ( _                      ' VTable offset = 280
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   PROPERTY SET FaxNumber <33> ( _                      ' VTable offset = 284
     BYVAL pVal AS WSTRING _                            ' __in BSTR in pVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY SET putref_ConnectionObject <34> ( _        ' VTable offset = 288
     BYVAL newVal AS IDispatch _                        ' __in *newVal IDispatch
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CallHandle <35> ( _                     ' VTable offset = 292
   ) AS LONG                                            ' __retval_out long *pVal
   ' =====================================================================================
   PROPERTY SET CallHandle <35> ( _                     ' VTable offset = 296
     BYVAL pVal AS LONG _                                       ' __in long pVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SenderFax <36> ( _                      ' VTable offset = 300
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   PROPERTY SET SenderFax <36> ( _                      ' VTable offset = 304
     BYVAL pVal AS WSTRING _                            ' __in BSTR in pVal
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IFaxDoc_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IFaxJobs
' IID = {55DABFD3-5C9E-11D1-B791-000000000000}
' IFaxJobs Interface
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IFaxJobs_INTERFACE_DEFINED)
    %IFaxJobs_INTERFACE_DEFINED = 1

INTERFACE IFaxJobs $IID_IFaxJobs

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Count <1> ( _                           ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long *pVal
   ' =====================================================================================
   PROPERTY GET Item <2> ( _                            ' VTable offset = 32
     BYVAL Index AS LONG _                              ' __in long Index
   ) AS VARIANT                                         ' __retval_out VARIANT *pVal
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IFaxJobs_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IFaxJob
' IID = {55DABFD5-5C9E-11D1-B791-000000000000}
' IFaxJob Interface
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IFaxJob_INTERFACE_DEFINED)
    %IFaxJob_INTERFACE_DEFINED = 1

INTERFACE IFaxJob $IID_IFaxJob

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET JobId <1> ( _                           ' VTable offset = 28
   ) AS LONG                                            ' __retval_out long *pVal
   ' =====================================================================================
   PROPERTY GET Type <2> ( _                            ' VTable offset = 32
   ) AS LONG                                            ' __retval_out long *pVal
   ' =====================================================================================
   PROPERTY GET UserName <3> ( _                        ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   PROPERTY GET QueueStatus <4> ( _                     ' VTable offset = 40
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   PROPERTY GET DeviceStatus <5> ( _                    ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   PROPERTY GET PageCount <6> ( _                       ' VTable offset = 48
   ) AS LONG                                            ' __retval_out long *pVal
   ' =====================================================================================
   PROPERTY GET FaxNumber <7> ( _                       ' VTable offset = 52
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   PROPERTY GET RecipientName <8> ( _                   ' VTable offset = 56
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   PROPERTY GET Tsid <9> ( _                            ' VTable offset = 60
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   PROPERTY GET SenderName <10> ( _                     ' VTable offset = 64
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   PROPERTY GET SenderCompany <11> ( _                  ' VTable offset = 68
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   PROPERTY GET SenderDept <12> ( _                     ' VTable offset = 72
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   PROPERTY GET BillingCode <13> ( _                    ' VTable offset = 76
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   PROPERTY GET DisplayName <14> ( _                    ' VTable offset = 80
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   PROPERTY GET DiscountSend <15> ( _                   ' VTable offset = 84
   ) AS LONG                                            ' __retval_out long *pVal
   ' =====================================================================================
   METHOD SetStatus <16> ( _                            ' VTable offset = 88
     BYVAL Command AS LONG _                            ' __in long Command
   )                                                    ' void
   ' =====================================================================================
   METHOD Refresh <17> ( _                              ' VTable offset = 92
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IFaxJob_INTERFACE_DEFINED__ */
