' ########################################################################################
' Microsoft Windows
' File: MSCOMM32.inc
' Contents: Common includes for new style Win32 Access Control APIs
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

' ########################################################################################
' Library name: MSCommLib
' Version: 1.1, Locale ID = 0
' Documentation string: Microsoft Comm Control 6.0
' Path: C:\Software\OCXs\MSCOMM32.OCX
' Library GUID: {648A5603-2C6E-101B-82B6-000000000014}
' Help file: C:\Software\OCXs\COMM98.CHM
' ########################################################################################

#INCLUDE THIS ONCE
%MSCOMM32_INC = 1

$RTLKEY_MSCOMM = "4250E830-6AC2-11cf-8ADB-00AA00C00905"

' ========================================================================================
' ClsIDs (Class identifiers)
' ========================================================================================

$CLSID_MSComm = GUID$("{648A5600-2C6E-101B-82B6-000000000014}")

' ========================================================================================
' IIDs (Interface identifiers)
' ========================================================================================

$IID_DMSCommEvents = GUID$("{648A5602-2C6E-101B-82B6-000000000014}")
$IID_IMSComm = GUID$("{E6E17E90-DF38-11CF-8E74-00A0C90F26F8}")

' ========================================================================================
' HandshakingConstants enum
' IID: {4B4B0391-6897-11CF-953F-0020AFC28C3B}
' MS Comm Control Handshake Constants
' ========================================================================================

%NoHandshaking                                          = 0            ' &H0
%XonXoff                                                = 1            ' &H1
%RtsCts                                                 = 2            ' &H2
%XonXoffAndRtsCts                                       = 3            ' &H3

' ========================================================================================
' HandshakeConstants enum
' IID: {72F05B40-B530-101B-82B6-000000000014}
' MS Comm Control Handshake Constants
' ========================================================================================

%comNone                                                = 0            ' &H0
%comXOnXoff                                             = 1            ' &H1
%comRTS                                                 = 2            ' &H2
%comRTSXOnXOff                                          = 3            ' &H3

' ========================================================================================
' ErrorConstants enum
' IID: {7C4FC790-BE64-11CF-95DA-0020AFC28C3B}
' Error Constants
' ========================================================================================

%comInvalidPropertyValue                                = 380          ' &H17C
%comGetNotSupported                                     = 394          ' &H18A
%comSetNotSupported                                     = 383          ' &H17F
%comPortInvalid                                         = 8002         ' &H1F42
%comPortAlreadyOpen                                     = 8005         ' &H1F45
%comPortOpen                                            = 8000         ' &H1F40
%comNoOpen                                              = 8012         ' &H1F4C
%comSetCommStateFailed                                  = 8015         ' &H1F4F
%comPortNotOpen                                         = 8018         ' &H1F52
%comReadError                                           = 8020         ' &H1F54
%comDCBError                                            = 8021         ' &H1F55
%comBreak                                               = 1001         ' &H3E9
%comCTSTO                                               = 1002         ' &H3EA
%comDSRTO                                               = 1003         ' &H3EB
%comFrame                                               = 1004         ' &H3EC
%comOverrun                                             = 1006         ' &H3EE
%comCDTO                                                = 1007         ' &H3EF
%comRxOver                                              = 1008         ' &H3F0
%comRxParity                                            = 1009         ' &H3F1
%comTxFull                                              = 1010         ' &H3F2
%comDCB                                                 = 1011         ' &H3F3

' ========================================================================================
' CommEventConstants enum
' IID: {8E6EB360-C3B1-11CF-8E6B-00A0C90F26F8}
' Error constants.
' ========================================================================================

%comEventBreak                                          = 1001         ' &H3E9
%comEventCTSTO                                          = 1002         ' &H3EA
%comEventDSRTO                                          = 1003         ' &H3EB
%comEventFrame                                          = 1004         ' &H3EC
%comEventOverrun                                        = 1006         ' &H3EE
%comEventCDTO                                           = 1007         ' &H3EF
%comEventRxOver                                         = 1008         ' &H3F0
%comEventRxParity                                       = 1009         ' &H3F1
%comEventTxFull                                         = 1010         ' &H3F2
%comEventDCB                                            = 1011         ' &H3F3

' ========================================================================================
' OnCommConstants enum
' OnComm constants.
' ========================================================================================

%comEvSend                                              = 1            ' &H1
%comEvReceive                                           = 2            ' &H2
%comEvCTS                                               = 3            ' &H3
%comEvDSR                                               = 4            ' &H4
%comEvCD                                                = 5            ' &H5
%comEvRing                                              = 6            ' &H6
%comEvEOF                                               = 7            ' &H7

' ========================================================================================
' InputModeConstants enum
' InputMode Constants
' ========================================================================================

%comInputModeText                                       = 0            ' &H0
%comInputModeBinary                                     = 1            ' &H1

' ########################################################################################
' Interface name = IMSComm
' IID = {E6E17E90-DF38-11CF-8E74-00A0C90F26F8}
' Dispatch interface for Microsoft Comm Control
' Attributes = 4304 [&H10D0] [Hidden] [Dual] [Nonextensible] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IMSComm_INTERFACE_DEFINED)
    %IMSComm_INTERFACE_DEFINED = 1

INTERFACE IMSComm $IID_IMSComm

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY SET CDHolding <1> ( _                       ' VTable offset = 28
     BYVAL pfCDHolding AS INTEGER _                     ' __in VARIANT_BOOL pfCDHolding
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CDHolding <1> ( _                       ' VTable offset = 32
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pfCDHolding
   ' =====================================================================================
   PROPERTY SET CDTimeout <2> ( _                       ' VTable offset = 36
     BYVAL plCDTimeout AS LONG _                        ' __in long plCDTimeout
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CDTimeout <2> ( _                       ' VTable offset = 40
   ) AS LONG                                            ' __retval_out long* plCDTimeout
   ' =====================================================================================
   PROPERTY SET CommID <3> ( _                          ' VTable offset = 44
     BYVAL plCommID AS LONG _                           ' __in long plCommID
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CommID <3> ( _                          ' VTable offset = 48
   ) AS LONG                                            ' __retval_out long* plCommID
   ' =====================================================================================
   PROPERTY SET CommPort <4> ( _                        ' VTable offset = 52
     BYVAL psCommPort AS INTEGER _                      ' __in short psCommPort
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CommPort <4> ( _                        ' VTable offset = 56
   ) AS INTEGER                                         ' __retval_out short* psCommPort
   ' =====================================================================================
   PROPERTY SET CommPort_ <0> ( _                       ' VTable offset = 60
     BYVAL psCommPort AS INTEGER _                      ' __in short psCommPort
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CommPort_ <0> ( _                       ' VTable offset = 64
   ) AS INTEGER                                         ' __retval_out short* psCommPort
   ' =====================================================================================
   PROPERTY SET CTSHolding <5> ( _                      ' VTable offset = 68
     BYVAL pfCTSHolding AS INTEGER _                    ' __in VARIANT_BOOL pfCTSHolding
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CTSHolding <5> ( _                      ' VTable offset = 72
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pfCTSHolding
   ' =====================================================================================
   PROPERTY SET CTSTimeout <6> ( _                      ' VTable offset = 76
     BYVAL plCTSTimeout AS LONG _                       ' __in long plCTSTimeout
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CTSTimeout <6> ( _                      ' VTable offset = 80
   ) AS LONG                                            ' __retval_out long* plCTSTimeout
   ' =====================================================================================
   PROPERTY SET DSRHolding <7> ( _                      ' VTable offset = 84
     BYVAL pfDSRHolding AS INTEGER _                    ' __in VARIANT_BOOL pfDSRHolding
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DSRHolding <7> ( _                      ' VTable offset = 88
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pfDSRHolding
   ' =====================================================================================
   PROPERTY SET DSRTimeout <8> ( _                      ' VTable offset = 92
     BYVAL plDSRTimeout AS LONG _                       ' __in long plDSRTimeout
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DSRTimeout <8> ( _                      ' VTable offset = 96
   ) AS LONG                                            ' __retval_out long* plDSRTimeout
   ' =====================================================================================
   PROPERTY SET DTREnable <9> ( _                       ' VTable offset = 100
     BYVAL pfDTREnable AS INTEGER _                     ' __in VARIANT_BOOL pfDTREnable
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET DTREnable <9> ( _                       ' VTable offset = 104
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pfDTREnable
   ' =====================================================================================
   PROPERTY SET Handshaking <10> ( _                    ' VTable offset = 108
     BYVAL phandshake AS LONG _                         ' __in HandshakeConstants phandshake
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Handshaking <10> ( _                    ' VTable offset = 112
   ) AS LONG                                            ' __retval_out HandshakeConstants* phandshake
   ' =====================================================================================
   PROPERTY SET InBufferSize <11> ( _                   ' VTable offset = 116
     BYVAL psInBufferSize AS INTEGER _                  ' __in short psInBufferSize
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET InBufferSize <11> ( _                   ' VTable offset = 120
   ) AS INTEGER                                         ' __retval_out short* psInBufferSize
   ' =====================================================================================
   PROPERTY SET InBufferCount <12> ( _                  ' VTable offset = 124
     BYVAL psInBufferCount AS INTEGER _                 ' __in short psInBufferCount
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET InBufferCount <12> ( _                  ' VTable offset = 128
   ) AS INTEGER                                         ' __retval_out short* psInBufferCount
   ' =====================================================================================
   PROPERTY SET Break <13> ( _                          ' VTable offset = 132
     BYVAL pfBreak AS INTEGER _                         ' __in VARIANT_BOOL pfBreak
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Break <13> ( _                          ' VTable offset = 136
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pfBreak
   ' =====================================================================================
   PROPERTY SET InputLen <14> ( _                       ' VTable offset = 140
     BYVAL psInputLen AS INTEGER _                      ' __in short psInputLen
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET InputLen <14> ( _                       ' VTable offset = 144
   ) AS INTEGER                                         ' __retval_out short* psInputLen
   ' =====================================================================================
   PROPERTY SET Interval <15> ( _                       ' VTable offset = 148
     BYVAL plInterval AS LONG _                         ' __in long plInterval
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Interval <15> ( _                       ' VTable offset = 152
   ) AS LONG                                            ' __retval_out long* plInterval
   ' =====================================================================================
   PROPERTY SET NullDiscard <16> ( _                    ' VTable offset = 156
     BYVAL pfNullDiscard AS INTEGER _                   ' __in VARIANT_BOOL pfNullDiscard
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET NullDiscard <16> ( _                    ' VTable offset = 160
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pfNullDiscard
   ' =====================================================================================
   PROPERTY SET OutBufferSize <17> ( _                  ' VTable offset = 164
     BYVAL psOutBufferSize AS INTEGER _                 ' __in short psOutBufferSize
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET OutBufferSize <17> ( _                  ' VTable offset = 168
   ) AS INTEGER                                         ' __retval_out short* psOutBufferSize
   ' =====================================================================================
   PROPERTY SET OutBufferCount <18> ( _                 ' VTable offset = 172
     BYVAL psOutBufferCount AS INTEGER _                ' __in short psOutBufferCount
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET OutBufferCount <18> ( _                 ' VTable offset = 176
   ) AS INTEGER                                         ' __retval_out short* psOutBufferCount
   ' =====================================================================================
   PROPERTY SET ParityReplace <19> ( _                  ' VTable offset = 180
     BYVAL pbstrParityReplace AS WSTRING _              ' __in BSTR pbstrParityReplace
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET ParityReplace <19> ( _                  ' VTable offset = 184
   ) AS WSTRING                                         ' __retval_out BSTR* pbstrParityReplace
   ' =====================================================================================
   PROPERTY SET PortOpen <20> ( _                       ' VTable offset = 188
     BYVAL pfPortOpen AS INTEGER _                      ' __in VARIANT_BOOL pfPortOpen
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET PortOpen <20> ( _                       ' VTable offset = 192
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pfPortOpen
   ' =====================================================================================
   PROPERTY SET RThreshold <21> ( _                     ' VTable offset = 196
     BYVAL psRThreshold AS INTEGER _                    ' __in short psRThreshold
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET RThreshold <21> ( _                     ' VTable offset = 200
   ) AS INTEGER                                         ' __retval_out short* psRThreshold
   ' =====================================================================================
   PROPERTY SET RTSEnable <22> ( _                      ' VTable offset = 204
     BYVAL pfRTSEnable AS INTEGER _                     ' __in VARIANT_BOOL pfRTSEnable
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET RTSEnable <22> ( _                      ' VTable offset = 208
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pfRTSEnable
   ' =====================================================================================
   PROPERTY SET Settings <23> ( _                       ' VTable offset = 212
     BYVAL pbstrSettings AS WSTRING _                   ' __in BSTR pbstrSettings
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Settings <23> ( _                       ' VTable offset = 216
   ) AS WSTRING                                         ' __retval_out BSTR* pbstrSettings
   ' =====================================================================================
   PROPERTY SET SThreshold <24> ( _                     ' VTable offset = 220
     BYVAL psSThreshold AS INTEGER _                    ' __in short psSThreshold
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET SThreshold <24> ( _                     ' VTable offset = 224
   ) AS INTEGER                                         ' __retval_out short* psSThreshold
   ' =====================================================================================
   PROPERTY SET Output <25> ( _                         ' VTable offset = 228
     BYVAL pvarOutput AS VARIANT _                      ' __in VARIANT pvarOutput
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Output <25> ( _                         ' VTable offset = 232
   ) AS VARIANT                                         ' __retval_out VARIANT* pvarOutput
   ' =====================================================================================
   PROPERTY SET Input <26> ( _                          ' VTable offset = 236
     BYVAL pvarInput AS VARIANT _                       ' __in VARIANT pvarInput
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Input <26> ( _                          ' VTable offset = 240
   ) AS VARIANT                                         ' __retval_out VARIANT* pvarInput
   ' =====================================================================================
   PROPERTY SET CommEvent <27> ( _                      ' VTable offset = 244
     BYVAL psCommEvent AS INTEGER _                     ' __in short psCommEvent
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET CommEvent <27> ( _                      ' VTable offset = 248
   ) AS INTEGER                                         ' __retval_out short* psCommEvent
   ' =====================================================================================
   PROPERTY SET EOFEnable <28> ( _                      ' VTable offset = 252
     BYVAL pfEOFEnable AS INTEGER _                     ' __in VARIANT_BOOL pfEOFEnable
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET EOFEnable <28> ( _                      ' VTable offset = 256
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL* pfEOFEnable
   ' =====================================================================================
   PROPERTY SET InputMode <29> ( _                      ' VTable offset = 260
     BYVAL InputMode AS LONG _                          ' __in InputModeConstants InputMode
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET InputMode <29> ( _                      ' VTable offset = 264
   ) AS LONG                                            ' __retval_out InputModeConstants* InputMode
   ' =====================================================================================
   METHOD AboutBox <-552> ( _                           ' VTable offset = 268
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMSComm_INTERFACE_DEFINED__ */


' ########################################################################################
' Class CDMSCommEvents
' Interface name = DMSCommEvents
' IID = {648A5602-2C6E-101B-82B6-000000000014}
' Event interface for MSComm Control
' Attributes = 4112 [&H1010] [Hidden] [Dispatchable]
' ########################################################################################

'CLASS CDMSCommEvents GUID$("{07EDE659-40D9-4FC3-8C39-B8E3915233FE}") AS EVENT

'INTERFACE DMSCommEventsImpl GUID$("{648A5602-2C6E-101B-82B6-000000000014}") AS EVENT

'  INHERIT IDispatch

'   ' =====================================================================================
'   METHOD OnComm <1>

'     ' *** Insert your code here ***

'   END METHOD
'   ' =====================================================================================

'END INTERFACE

'END CLASS
