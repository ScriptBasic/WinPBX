' ########################################################################################
' Microsoft Windows
' File: effects.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%EFFECTS_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "oaidl.inc"
#INCLUDE ONCE "ocidl.inc"
#INCLUDE ONCE "wmp.inc"

'//=========================================================================
'//
'// Microsoft Windows Media Technologies
'// Copyright (C) Microsoft Corporation. All rights reserved.
'//
'//=========================================================================
%EFFECT_CANGOFULLSCREEN      = &H1
%EFFECT_HASPROPERTYPAGE      = &H2
%EFFECT_VARIABLEFREQSTEP     = &H4
%EFFECT_WINDOWEDONLY         = &H8
%EFFECT2_FULLSCREENEXCLUSIVE = &H10
%SA_BUFFER_SIZE              = 1024

'enum PlayerState
%stop_state  = 0
%pause_state = 1
%play_state  = 2

'//**********************************************************************
'// Define the minimum and maximum frequency ranges returned in our
'// TimedLevel frequency array (i.e. first index in TimedLevel.frequency
'// is at 20Hz and last is at 22050Hz).
'//**********************************************************************
'static const float kfltTimedLevelMaximumFrequency = 22050.0F;
'static const float kfltTimedLevelMinimumFrequency = 20.0F;
MACRO kfltTimedLevelMaximumFrequency = 22050.0!
MACRO kfltTimedLevelMinimumFrequency = 20.0!

'/*
' * FREQUENCY_INDEX() returns the index into TimedLevel.frequency[] where
' * the specified frequency is located in the power spectrum
' */
'#define FREQUENCY_INDEX(FREQ)\
'  (int)(((FREQ) - kfltTimedLevelMinimumFrequency) /\
'    (((kfltTimedLevelMaximumFrequency - kfltTimedLevelMinimumFrequency) / SA_BUFFER_SIZE)))

MACRO FREQUENCY_INDEX(FREQ) = CLNG((FREQ - kfltTimedLevelMinimumFrequency) \ ((kfltTimedLevelMaximumFrequency - kfltTimedLevelMinimumFrequency) \ %SA_BUFFER_SIZE))

' // Size = 4112 bytes
TYPE TimedLevel QWORD FILL
   frequency(1, 1023) AS BYTE   ' unsigned char frequency[ 2 ][ 1024 ];
   waveform (1, 1023) AS BYTE   ' unsigned char waveform[ 2 ][ 1024 ];
   state              AS LONG   ' int
   timeStamp          AS QUAD   ' hyper
END TYPE


' ########################################################################################
' Interface name = IWMPEffects
' IID = D3984C13-C3CB-48E2-8BE5-5168340B4F35
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IWMPEffects_INTERFACE_DEFINED)
    %IWMPEffects_INTERFACE_DEFINED = 1

$IID_IWMPEffects = GUID$("{D3984C13-C3CB-48E2-8BE5-5168340B4F35}")

INTERFACE IWMPEffects $IID_IWMPEffects

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Render ( _                                    ' VTable offset = 12
     BYREF pLevels AS TimedLevel _                      ' __in TimedLevel *pLevels
   , BYVAL hdc AS DWORD _                               ' __in HDC hdc
   , BYREF prc AS RECT _                                ' __in RECT *prc
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD MediaInfo ( _                                 ' VTable offset = 16
     BYVAL lChannelCount AS LONG _                      ' __in LONG lChannelCount
   , BYVAL lSampleRate AS LONG _                        ' __in LONG lSampleRate
   , BYVAL bstrTitle AS WSTRING _                       ' __in BSTR bstrTitle
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCapabilities ( _                           ' VTable offset = 20
     BYREF pdwCapabilities AS DWORD _                   ' __out DWORD *pdwCapabilities
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTitle ( _                                  ' VTable offset = 24
     BYREF bstrTitle AS WSTRING _                       ' __out BSTR *bstrTitle
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPresetTitle ( _                            ' VTable offset = 28
     BYVAL nPreset AS LONG _                            ' __in LONG nPreset
   , BYREF bstrPresetTitle AS WSTRING _                 ' __out BSTR *bstrPresetTitle
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPresetCount ( _                            ' VTable offset = 32
     BYREF pnPresetCount AS LONG _                      ' __out LONG *pnPresetCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetCurrentPreset ( _                          ' VTable offset = 36
     BYVAL nPreset AS LONG _                            ' __in LONG nPreset
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCurrentPreset ( _                          ' VTable offset = 40
     BYREF pnPreset AS LONG _                           ' __out LONG *pnPreset
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DisplayPropertyPage ( _                       ' VTable offset = 44
     BYVAL hwndOwner AS DWORD _                         ' __in HWND hwndOwner
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GoFullscreen ( _                              ' VTable offset = 48
     BYVAL fFullScreen AS LONG _                        ' __in BOOL fFullScreen
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RenderFullScreen ( _                          ' VTable offset = 52
     BYREF pLevels AS TimedLevel _                      ' __in TimedLevel *pLevels
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWMPEffects_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IWMPEffects2
' IID = 695386EC-AA3C-4618-A5E1-DD9A8B987632
' Inherited interface = IWMPEffects
' ########################################################################################

#IF NOT %DEF(%IWMPEffects2_INTERFACE_DEFINED)
    %IWMPEffects2_INTERFACE_DEFINED = 1

$IID_IWMPEffects2 = GUID$("{695386EC-AA3C-4618-A5E1-DD9A8B987632}")

INTERFACE IWMPEffects2 $IID_IWMPEffects2

   INHERIT IUnknown

   ' =====================================================================================
   ' IWMPEffects Methods
   ' =====================================================================================
   METHOD Render ( _                                    ' VTable offset = 12
     BYREF pLevels AS TimedLevel _                      ' __in TimedLevel *pLevels
   , BYVAL hdc AS DWORD _                               ' __in HDC hdc
   , BYREF prc AS RECT _                                ' __in RECT *prc
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD MediaInfo ( _                                 ' VTable offset = 16
     BYVAL lChannelCount AS LONG _                      ' __in LONG lChannelCount
   , BYVAL lSampleRate AS LONG _                        ' __in LONG lSampleRate
   , BYVAL bstrTitle AS WSTRING _                       ' __in BSTR bstrTitle
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCapabilities ( _                           ' VTable offset = 20
     BYREF pdwCapabilities AS DWORD _                   ' __out DWORD *pdwCapabilities
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTitle ( _                                  ' VTable offset = 24
     BYREF bstrTitle AS WSTRING _                       ' __out BSTR *bstrTitle
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPresetTitle ( _                            ' VTable offset = 28
     BYVAL nPreset AS LONG _                            ' __in LONG nPreset
   , BYREF bstrPresetTitle AS WSTRING _                 ' __out BSTR *bstrPresetTitle
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPresetCount ( _                            ' VTable offset = 32
     BYREF pnPresetCount AS LONG _                      ' __out LONG *pnPresetCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetCurrentPreset ( _                          ' VTable offset = 36
     BYVAL nPreset AS LONG _                            ' __in LONG nPreset
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCurrentPreset ( _                          ' VTable offset = 40
     BYREF pnPreset AS LONG _                           ' __out LONG *pnPreset
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DisplayPropertyPage ( _                       ' VTable offset = 44
     BYVAL hwndOwner AS DWORD _                         ' __in HWND hwndOwner
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GoFullscreen ( _                              ' VTable offset = 48
     BYVAL fFullScreen AS LONG _                        ' __in BOOL fFullScreen
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RenderFullScreen ( _                          ' VTable offset = 52
     BYREF pLevels AS TimedLevel _                      ' __in TimedLevel *pLevels
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IWMPEffects2 Methods
   ' =====================================================================================
   METHOD SetCore ( _                                   ' VTable offset = 56
     BYVAL pPlayer AS IWMPCore _                        ' __in IWMPCore *pPlayer
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Create ( _                                    ' VTable offset = 56
     BYVAL hwndParent AS DWORD _                        ' __in HWND hwndParent
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Destroy ( _                                   ' VTable offset = 60
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD NotifyNewMedia ( _                            ' VTable offset = 64
     BYVAL pMedia AS IWMPMedia _                        ' __in IWMPMedia *pMedia
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnWindowMessage ( _                           ' VTable offset = 68
     BYVAL msg AS DWORD _                               ' __in UINT msg
   , BYVAL WParam AS DWORD _                            ' __in WPARAM WParam
   , BYVAL LParam AS LONG _                             ' __in LPARAM LParam
   , BYREF plResultParam AS LONG _                      ' __in LRESULT *plResultParam
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RenderWindowed ( _                            ' VTable offset = 72
     BYREF pData AS TimedLevel _                        ' __in TimedLevel *pData
   , BYVAL fRequiredRender AS LONG _                    ' __in BOOL fRequiredRender
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWMPEffects2_INTERFACE_DEFINED__ */
