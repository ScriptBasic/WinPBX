' ########################################################################################
' Microsoft Windows
' File: AMAudio.inc
' Contents: Audio related definitions and interfaces for ActiveMovie.
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%AMAUDIO_INC = 1

#INCLUDE ONCE "mmsystem.inc"
#INCLUDE ONCE "dsound.inc"

'// This is the interface the audio renderer supports to give the application
'// access to the direct sound object and the buffers it is using, to allow the
'// application to use things like the 3D features of Direct Sound for the
'// soundtrack of a movie being played with Active Movie.

' ########################################################################################
' Interface name = IAMDirectSound
' IID = {546F4260-D53E-11CF-B3F0-00AA003761C5}
' Inherited interface = IUnknown
' ########################################################################################

$IID_IAMDirectSound = GUID$("{546F4260-D53E-11CF-B3F0-00AA003761C5}")

INTERFACE IAMDirectSound $IID_IAMDirectSound

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetDirectSoundInterface ( _                   ' VTable offset = 12
     BYREF lplpds AS IDirectSound _                     ' __out LPDIRECTSOUND *lplpds
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPrimaryBufferInterface ( _                 ' VTable offset = 16
     BYREF lplpdsb AS IDirectSoundBuffer _              ' __out LPDIRECTSOUNDBUFFER *lplpdsb
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSecondaryBufferInterface ( _               ' VTable offset = 20
     BYREF lplpdsb AS IDirectSoundBuffer _              ' __out LPDIRECTSOUNDBUFFER *lplpdsb
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ReleaseDirectSoundInterface ( _               ' VTable offset = 24
     BYVAL lpds AS IDirectSound _                       ' __in LPDIRECTSOUND lpds
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ReleasePrimaryBufferInterface ( _             ' VTable offset = 28
     BYVAL lpdsb AS IDirectSoundBuffer _                ' __in LPDIRECTSOUNDBUFFER lpdsb
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ReleaseSecondaryBufferInterface ( _           ' VTable offset = 32
     BYVAL lpdsb AS IDirectSoundBuffer _                ' __in LPDIRECTSOUNDBUFFER lpdsb
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetFocusWindow ( _                            ' VTable offset = 36
     BYVAL hWnd AS DWORD _                              ' __in HWND hWnd
   , BYVAL bMixingOnOrOff AS LONG _                     ' __in BOOL bMixingOnOrOff
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFocusWindow ( _                            ' VTable offset = 40
     BYREF hWnd AS DWORD _                              ' __out HWND* hWnd
   , BYREF bMixingOnOrOff AS LONG _                     ' __out BOOL* bMixingOnOrOff
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE
