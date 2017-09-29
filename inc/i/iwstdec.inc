' ########################################################################################
' Microsoft Windows
' File: iwstdec.inc
' Contents: WST Decoder related definitions and interfaces for ActiveMovie
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%IWSTDEC_INC = 1

#INCLUDE ONCE "uuids.inc"

'//
'//  Some data types used as WST decoder parameters by the interface
'//
' // Size = 12 bytes
TYPE AM_WST_PAGE DWORD
   dwPageNr    AS DWORD      ' DWORD
   dwSubPageNr AS DWORD      ' DWORD
   pucPageData AS BYTE PTR   ' BYTE *
END TYPE

' enum AM_WST_LEVEL
%AM_WST_LEVEL_1_5 = 0

' enum AM_WST_SERVICE
%AM_WST_SERVICE_None    = 0
%AM_WST_SERVICE_Text    = 1
%AM_WST_SERVICE_IDS     = 2
%AM_WST_SERVICE_Invalid = 3

' enum AM_WST_STATE
%AM_WST_STATE_Off = 0
%AM_WST_STATE_On  = 1

' enum AM_WST_STYLE
%AM_WST_STYLE_None   = 0
%AM_WST_STYLE_Invers = 1

' enum AM_WST_DRAWBGMODE
%AM_WST_DRAWBGMODE_Opaque      = 0
%AM_WST_DRAWBGMODE_Transparent = 1


'//
'//  WST Decoder standard COM interface
'//

' ########################################################################################
' Interface name = IAMWstDecoder
' IID = {C056DE21-75C2-11D3-A184-00105AEF9F33}
' Inherited interface = IUnknown
' ########################################################################################

INTERFACE IAMWstDecoder $IID_IAMWstDecoder

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetDecoderLevel ( _                           ' VTable offset = 12
     BYREF lpLevel AS DWORD _                           ' __out AM_WST_LEVEL *lpLevel
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCurrentService ( _                         ' VTable offset = 16
     BYREF lpService AS DWORD _                         ' __out AM_WST_SERVICE *lpService
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetServiceState ( _                           ' VTable offset = 20
     BYREF lpState AS DWORD _                           ' __out AM_WST_STATE *lpState
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetServiceState ( _                           ' VTable offset = 24
     BYVAL State AS DWORD _                             ' __in AM_WST_STATE State
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetOutputFormat ( _                           ' VTable offset = 28
     BYREF lpbmih AS BITMAPINFOHEADER _                 ' __out LPBITMAPINFOHEADER lpbmih
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetOutputFormat ( _                           ' VTable offset = 32
     BYREF lpbmi AS BITMAPINFO _                        ' __in LPBITMAPINFO lpbmi
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetBackgroundColor ( _                        ' VTable offset = 36
     BYREF pdwPhysColor AS DWORD _                      ' __out DWORD *pdwPhysColor
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetBackgroundColor ( _                        ' VTable offset = 40
     BYVAL dwPhysColor AS DWORD _                       ' __in DWORD dwPhysColor
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRedrawAlways ( _                           ' VTable offset = 44
     BYREF lpbOption AS LONG _                          ' __out LPBOOL lpbOption
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetRedrawAlways ( _                           ' VTable offset = 48
     BYVAL bOption AS LONG _                            ' __in BOOL bOption
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDrawBackgroundMode ( _                     ' VTable offset = 52
     BYREF lpMode AS DWORD _                            ' __out AM_WST_DRAWBGMODE *lpMode
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetDrawBackgroundMode ( _                     ' VTable offset = 56
     BYVAL Mode AS DWORD _                              ' __in AM_WST_DRAWBGMODE Mode
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetAnswerMode ( _                             ' VTable offset = 60
     BYVAL bAnswer AS LONG _                            ' __in BOOL bAnswer
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAnswerMode ( _                             ' VTable offset = 64
     BYREF pbAnswer AS LONG _                           ' __out BOOL* pbAnswer
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetHoldPage ( _                               ' VTable offset = 68
     BYVAL bHoldPage AS LONG _                          ' __in BOOL bHoldPage
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetHoldPage ( _                               ' VTable offset = 72
     BYREF pbHoldPage AS LONG _                         ' __out BOOL* pbHoldPage
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCurrentPage ( _                            ' VTable offset = 76
     BYREF pWstPage AS DWORD _                          ' __out PAM_WST_PAGE pWstPage
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetCurrentPage ( _                            ' VTable offset = 80
     BYVAL WstPage AS DWORD _                           ' __in AM_WST_PAGE WstPage
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE
