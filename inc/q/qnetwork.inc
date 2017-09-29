' ########################################################################################
' Microsoft Windows
' File: qnetwork.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%QNETWORK_INC = 1

#INCLUDE ONCE "windows.inc"

$LIBID_QuartzNetTypeLib = GUID$("{56A868B1-0AD4-11CE-B03A-0020AF0BA770}")

$IID_IAMNetShowConfig   = GUID$("{FA2AA8F1-8B62-11D0-A520-000000000000}")

' ########################################################################################
' Interface name = IAMNetShowConfig
' IID = {FA2AA8F1-8B62-11D0-A520-000000000000}
' Inherited interface = IDispatch
' ########################################################################################

INTERFACE IAMNetShowConfig $IID_IAMNetShowConfig

   INHERIT IDispatch

   PROPERTY GET BufferingTime () AS DOUBLE
   PROPERTY SET BufferingTime (BYVAL BufferingTime AS DOUBLE)
   PROPERTY GET UseFixedUDPPort () AS INTEGER
   PROPERTY SET UseFixedUDPPort (BYVAL UseFixedUDPPort AS INTEGER)
   PROPERTY GET FixedUDPPort () AS LONG
   PROPERTY SET FixedUDPPort (BYVAL FixedUDPPort AS LONG)
   PROPERTY GET UseHTTPProxy () AS INTEGER
   PROPERTY SET UseHTTPProxy (BYVAL UseHTTPProxy AS INTEGER)
   PROPERTY GET EnableAutoProxy () AS INTEGER
   PROPERTY SET EnableAutoProxy (BYVAL EnableAutoProxy AS INTEGER)
   PROPERTY GET HTTPProxyHost () AS WSTRING
   PROPERTY SET HTTPProxyHost (BYVAL bstrHTTPProxyHost AS WSTRING)
   PROPERTY GET HTTPProxyPort () AS LONG
   PROPERTY SET HTTPProxyPort (BYVAL HTTPProxyPort AS LONG)
   PROPERTY GET EnableMulticast () AS INTEGER
   PROPERTY SET EnableMulticast (BYVAL EnableMulticast AS INTEGER)
   PROPERTY GET EnableUDP () AS INTEGER
   PROPERTY SET EnableUDP (BYVAL EnableUDP AS INTEGER)
   PROPERTY GET EnableTCP () AS INTEGER
   PROPERTY SET EnableTCP (BYVAL EnableTCP AS INTEGER)
   PROPERTY GET EnableHTTP () AS INTEGER
   PROPERTY SET EnableHTTP (BYVAL EnableHTTP AS INTEGER)

END INTERFACE

$IID_IAMChannelInfo   = GUID$("{FA2AA8F2-8B62-11D0-A520-000000000000}")

' ########################################################################################
' Interface name = IAMChannelInfo
' IID = {FA2AA8F2-8B62-11D0-A520-000000000000}
' Inherited interface = IDispatch
' ########################################################################################

INTERFACE IAMChannelInfo $IID_IAMChannelInfo

   INHERIT IDispatch

   PROPERTY GET ChannelName () AS WSTRING
   PROPERTY GET ChannelDescription () AS WSTRING
   PROPERTY GET ChannelURL () AS WSTRING
   PROPERTY GET ContactAddress () AS WSTRING
   PROPERTY GET ContactPhone () AS WSTRING
   PROPERTY GET ContactEmail () AS WSTRING

END INTERFACE


$IID_IAMNetworkStatus   = GUID$("{FA2AA8F3-8B62-11D0-A520-000000000000}")

' ########################################################################################
' Interface name = IAMNetworkStatus
' IID = {FA2AA8F3-8B62-11D0-A520-000000000000}
' Inherited interface = IDispatch
' ########################################################################################

INTERFACE IAMNetworkStatus $IID_IAMNetworkStatus

   INHERIT IDispatch

   PROPERTY GET ReceivedPackets () AS LONG
   PROPERTY GET RecoveredPackets () AS LONG
   PROPERTY GET LostPackets () AS LONG
   PROPERTY GET ReceptionQuality () AS LONG
   PROPERTY GET BufferingCount () AS LONG
   PROPERTY GET IsBroadcast () AS LONG
   PROPERTY GET BufferingProgress () AS LONG

END INTERFACE


' enum AMExtendedSeekingCapabilities
%AM_EXSEEK_CANSEEK = 1
%AM_EXSEEK_CANSCAN = 2
%AM_EXSEEK_MARKERSEEK = 4
%AM_EXSEEK_SCANWITHOUTCLOCK = 8
%AM_EXSEEK_NOSTANDARDREPAINT = 16
%AM_EXSEEK_BUFFERING = 32
%AM_EXSEEK_SENDS_VIDEOFRAMEREADY = 64

$IID_IAMExtendedSeeking   = GUID$("{FA2AA8F9-8B62-11D0-A520-000000000000}")

' ########################################################################################
' Interface name = IAMExtendedSeeking
' IID = {FA2AA8F9-8B62-11D0-A520-000000000000}
' Inherited interface = IDispatch
' ########################################################################################

INTERFACE IAMExtendedSeeking $IID_IAMExtendedSeeking

   INHERIT IDispatch

   PROPERTY GET ExSeekCapabilities () AS LONG
   PROPERTY GET MarkerCount () AS LONG
   PROPERTY GET CurrentMarker () AS LONG
   METHOD GetMarkerTime (BYVAL MarkerNum AS LONG, BYREF pMarkerTime AS DOUBLE)
   METHOD GetMarkerName (BYVAL MarkerNum AS LONG, BYREF pbstrMarkerName AS WSTRING)
   PROPERTY SET PlaybackSpeed (BYVAL Speed AS DOUBLE)
   PROPERTY GET PlaybackSpeed () AS DOUBLE

END INTERFACE


$IID_IAMNetShowExProps   = GUID$("{FA2AA8F5-8B62-11D0-A520-000000000000}")

' ########################################################################################
' Interface name = IAMNetShowExProps
' IID = {FA2AA8F5-8B62-11D0-A520-000000000000}
' Inherited interface = IDispatch
' ########################################################################################

INTERFACE IAMNetShowExProps $IID_IAMNetShowExProps

   INHERIT IDispatch

   PROPERTY GET SourceProtocol () AS LONG
   PROPERTY GET Bandwidth () AS LONG
   PROPERTY GET ErrorCorrection () AS WSTRING
   PROPERTY GET CodecCount () AS LONG
   METHOD GetCodecInstalled (BYVAL CodecNum AS LONG, BYREF pCodecInstalled AS INTEGER)
   METHOD GetCodecDescription (BYVAL CodecNum AS LONG, BYREF pbstrCodecDescription AS WSTRING)
   METHOD GetCodecURL (BYVAL CodecNum AS LONG, BYREF pbstrCodecURL AS WSTRING)
   PROPERTY GET CreationDate () AS DOUBLE
   PROPERTY GET SourceLink () AS WSTRING

END INTERFACE


$IID_IAMExtendedErrorInfo   = GUID$("{FA2AA8F6-8B62-11D0-A520-000000000000}")

' ########################################################################################
' Interface name = IAMExtendedErrorInfo
' IID = {FA2AA8F6-8B62-11D0-A520-000000000000}
' Inherited interface = IDispatch
' ########################################################################################

INTERFACE IAMExtendedErrorInfo $IID_IAMExtendedErrorInfo

   INHERIT IDispatch

   PROPERTY GET HasError () AS INTEGER
   PROPERTY GET ErrorDescription () AS WSTRING
   PROPERTY GET ErrorCode () AS LONG

END INTERFACE


$IID_IAMMediaContent   = GUID$("{FA2AA8F4-8B62-11D0-A520-000000000000}")

' ########################################################################################
' Interface name = IAMMediaContent
' IID = {FA2AA8F4-8B62-11D0-A520-000000000000}
' Inherited interface = IDispatch
' ########################################################################################

INTERFACE IAMMediaContent $IID_IAMMediaContent

   INHERIT IDispatch

   PROPERTY GET AuthorName () AS WSTRING
   PROPERTY GET Title () AS WSTRING
   PROPERTY GET Rating () AS WSTRING
   PROPERTY GET Description () AS WSTRING
   PROPERTY GET Copyright () AS WSTRING
   PROPERTY GET BaseURL () AS WSTRING
   PROPERTY GET LogoURL () AS WSTRING
   PROPERTY GET LogoIconURL () AS WSTRING
   PROPERTY GET WatermarkURL () AS WSTRING
   PROPERTY GET MoreInfoURL () AS WSTRING
   PROPERTY GET MoreInfoBannerImage () AS WSTRING
   PROPERTY GET MoreInfoBannerURL () AS WSTRING
   PROPERTY GET MoreInfoText () AS WSTRING

END INTERFACE


$IID_IAMMediaContent2   = GUID$("{CE8F78C1-74D9-11D2-B09D-00A0C9A81117}")

' ########################################################################################
' Interface name = IAMMediaContent2
' IID = {CE8F78C1-74D9-11D2-B09D-00A0C9A81117}
' Inherited interface = IDispatch
' ########################################################################################

INTERFACE IAMMediaContent2 $IID_IAMMediaContent2

   INHERIT IDispatch

   PROPERTY GET MediaParameter (BYVAL EntryNum AS LONG, BYVAL bstrName AS WSTRING) AS WSTRING
   PROPERTY GET MediaParameterName (BYVAL EntryNum AS LONG, BYVAL Index AS LONG) AS WSTRING
   PROPERTY GET PlaylistCount () AS LONG

END INTERFACE


$IID_IAMNetShowPreroll   = GUID$("{AAE7E4E2-6388-11D1-8D93-006097C9A2B2}")

' ########################################################################################
' Interface name = IAMNetShowPreroll
' IID = {AAE7E4E2-6388-11D1-8D93-006097C9A2B2}
' Inherited interface = IDispatch
' ########################################################################################

INTERFACE IAMNetShowPreroll $IID_IAMNetShowPreroll

   INHERIT IDispatch

   PROPERTY SET Preroll (BYVAL fPreroll AS INTEGER)
   PROPERTY GET Preroll () AS INTEGER

END INTERFACE


$IID_IDShowPlugin   = GUID$("{4746B7C8-700E-11D1-BECC-00C04FB6E937}")

' ########################################################################################
' Interface name = IDShowPlugin
' IID = {4746B7C8-700E-11D1-BECC-00C04FB6E937}
' Inherited interface = IUnknown
' ########################################################################################

INTERFACE IDShowPlugin $IID_IDShowPlugin

   INHERIT IAutomation

   PROPERTY GET URL () AS WSTRING
   PROPERTY GET UserAgent () AS WSTRING

END INTERFACE
