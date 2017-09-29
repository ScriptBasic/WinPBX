' ########################################################################################
' Microsoft Windows
' File: il21Dec.inc
' Contents: Decoder related definitions and interfaces for ActiveMovie
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%IL21DEC_INC = 1

#INCLUDE ONCE "uuids.inc"

'//
'//  Some enum data types used as line 21 decoder params by the interface
'//
' enum _AM_LINE21_CCLEVEL {  // should we use TC1, TC2 in stead?
%AM_L21_CCLEVEL_TC2 = 0

' enum AM_LINE21_CCSERVICE {
%AM_L21_CCSERVICE_None       = 0
%AM_L21_CCSERVICE_Caption1   = 1
%AM_L21_CCSERVICE_Caption2   = 2
%AM_L21_CCSERVICE_Text1      = 3
%AM_L21_CCSERVICE_Text2      = 4
%AM_L21_CCSERVICE_XDS        = 5
%AM_L21_CCSERVICE_DefChannel = 10
%AM_L21_CCSERVICE_Invalid    = 11

' enum AM_LINE21_CCSTATE
%AM_L21_CCSTATE_Off = 0
%AM_L21_CCSTATE_On  = 1

' enum AM_LINE21_CCSTYLE
%AM_L21_CCSTYLE_None    = 0
%AM_L21_CCSTYLE_PopOn   = 1
%AM_L21_CCSTYLE_PaintOn = 2
%AM_L21_CCSTYLE_RollUp  = 3

' enum AM_LINE21_DRAWBGMODE
%AM_L21_DRAWBGMODE_Opaque      = 0
%AM_L21_DRAWBGMODE_Transparent = 1

'//
'//  Line 21 Decoder standard COM interface
'//

' ########################################################################################
' Interface name = IAMLine21Decoder
' IID = {6E8D4A21-310C-11D0-B79A-00AA003767A7}
' Inherited interface = IUnknown
' ########################################################################################

INTERFACE IAMLine21Decoder $IID_IAMLine21Decoder

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetDecoderLevel ( _                           ' VTable offset = 12
     BYREF lpLevel AS DWORD _                           ' __out AM_LINE21_CCLEVEL *lpLevel
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCurrentService ( _                         ' VTable offset = 16
     BYREF lpService AS DWORD _                         ' __out AM_LINE21_CCSERVICE *lpService
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetCurrentService ( _                         ' VTable offset = 20
     BYVAL Service AS DWORD _                           ' __in AM_LINE21_CCSERVICE Service
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetServiceState ( _                           ' VTable offset = 24
     BYREF lpState AS DWORD _                           ' __out AM_LINE21_CCSTATE *lpState
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetServiceState ( _                           ' VTable offset = 28
     BYVAL State AS DWORD _                             ' __in AM_LINE21_CCSTATE State
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetOutputFormat ( _                           ' VTable offset = 32
     BYREF lpbmih AS BITMAPINFOHEADER _                 ' __out LPBITMAPINFOHEADER lpbmih
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetOutputFormat ( _                           ' VTable offset = 36
     BYREF lpbmi AS BITMAPINFO _                        ' __out LPBITMAPINFO lpbmi
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetBackgroundColor ( _                        ' VTable offset = 40
     BYREF pdwPhysColor AS DWORD _                      ' __out DWORD *pdwPhysColor
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetBackgroundColor ( _                        ' VTable offset = 44
     BYVAL dwPhysColor AS DWORD _                       ' __in DWORD dwPhysColor
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRedrawAlways ( _                           ' VTable offset = 48
     BYREF lpbOption AS LONG _                          ' __out LPBOOL lpbOption
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetRedrawAlways ( _                           ' VTable offset = 52
     BYVAL bOption AS LONG _                            ' __in BOOL bOption
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDrawBackgroundMode ( _                     ' VTable offset = 56
     BYREF lpMode AS DWORD _                            ' __out AM_LINE21_DRAWBGMODE *lpMode
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetDrawBackgroundMode ( _                     ' VTable offset = 60
     BYVAL Mode AS DWORD _                              ' __in AM_LINE21_DRAWBGMODE Mode
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE
