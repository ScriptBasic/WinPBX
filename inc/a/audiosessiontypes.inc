' ########################################################################################
' Microsoft Windows
' File: audiosessiontypes.inc
' Contents: Type definitions used by the audio session manager RPC/COM interfaces
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%AUDIOSESSIONTYPES_INC = 1

'//-------------------------------------------------------------------------
'// Description: AudioClient share mode
'//
'//     AUDCLNT_SHAREMODE_SHARED -    The device will be opened in shared mode and use the
'//                                   WAS format.
'//     AUDCLNT_SHAREMODE_EXCLUSIVE - The device will be opened in exclusive mode and use the
'//                                   application specified format.
'//

' AUDCLNT_SHAREMODE enum
MACRO AUDCLNT_SHAREMODE_ENUM = LONG
%AUDCLNT_SHAREMODE_SHARED    = 0
%AUDCLNT_SHAREMODE_EXCLUSIVE = 1

'//-------------------------------------------------------------------------
'// Description: AudioClient stream flags
'//
'// Can be a combination of AUDCLNT_STREAMFLAGS and AUDCLNT_SYSFXFLAGS:
'//
'// AUDCLNT_STREAMFLAGS (this group of flags uses the high word,
'// w/exception of high-bit which is reserved, 0x7FFF0000):
'//
'//     AUDCLNT_STREAMFLAGS_CROSSPROCESS - Audio policy control for this stream will be shared with
'//                                        with other process sessions that use the same audio session
'//                                        GUID.
'//     AUDCLNT_STREAMFLAGS_LOOPBACK -     Initializes a renderer endpoint for a loopback audio application.
'//                                        In this mode, a capture stream will be opened on the specified
'//                                        renderer endpoint. Shared mode and a renderer endpoint is required.
'//                                        Otherwise the IAudioClient::Initialize call will fail. If the
'//                                        initialize is successful, a capture stream will be available
'//                                        from the IAudioClient object.
'//
'//     AUDCLNT_STREAMFLAGS_EVENTCALLBACK - An exclusive mode client will supply an event handle that will be
'//                                         signaled when an IRP completes (or a waveRT buffer completes) telling
'//                                         it to fill the next buffer
'//
'//     AUDCLNT_STREAMFLAGS_NOPERSIST -    Session state will not be persisted
'//
'//     AUDCLNT_SESSIONFLAGS_EXPIREWHENUNOWNED -       Session expires when there are no streams and no owning
'//                                                    session controls.
'//
'//     AUDCLNT_SESSIONFLAGS_DISPLAY_HIDE -            Don't show volume control in the Volume Mixer.
'//
'//     AUDCLNT_SESSIONFLAGS_DISPLAY_HIDEWHENEXPIRED - Don't show volume control in the Volume Mixer after the
'//                                                    session expires.
'//
'// AUDCLNT_SYSFXFLAGS (these flags use low word 0x0000FFFF):
'//
'//     none defined currently
'//

%AUDCLNT_STREAMFLAGS_CROSSPROCESS             = &H00010000???
%AUDCLNT_STREAMFLAGS_LOOPBACK                 = &H00020000???
%AUDCLNT_STREAMFLAGS_EVENTCALLBACK            = &H00040000???
%AUDCLNT_STREAMFLAGS_NOPERSIST                = &H00080000???
%AUDCLNT_STREAMFLAGS_RATEADJUST               = &H00100000???
%AUDCLNT_SESSIONFLAGS_EXPIREWHENUNOWNED       = &H10000000???
%AUDCLNT_SESSIONFLAGS_DISPLAY_HIDE            = &H20000000???
%AUDCLNT_SESSIONFLAGS_DISPLAY_HIDEWHENEXPIRED = &H40000000???

'//-------------------------------------------------------------------------
'// Description: AudioSession State.
'//
'//      AudioSessionStateInactive - The session has no active audio streams.
'//      AudioSessionStateActive - The session has active audio streams.
'//      AudioSessionStateExpired - The session is dormant.

' AudioSessionState enum
MACRO AUDIOSESSIONSTATE_ENUM = LONG
%AudioSessionStateInactive = 0
%AudioSessionStateActive   = 1
%AudioSessionStateExpired  = 2
