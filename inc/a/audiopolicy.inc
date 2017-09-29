' ########################################################################################
' Microsoft Windows (Windows 7)
' File: AudioPolicy.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%AUDIOPOLICY_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "oaidl.inc"
#INCLUDE ONCE "ocidl.inc"
#INCLUDE ONCE "propidl.inc"
#INCLUDE ONCE "AudioSessionTypes.inc"
#INCLUDE ONCE "AudioClient.inc"

' AudioSessionDisconnectReason enum
MACRO AUDIOSESSIONDISCONNECTREASON_ENUM = LONG
%DisconnectReasonDeviceRemoval         = 0
%DisconnectReasonServerShutdown        = %DisconnectReasonDeviceRemoval       + 1
%DisconnectReasonFormatChanged         = %DisconnectReasonServerShutdown      + 1
%DisconnectReasonSessionLogoff         = %DisconnectReasonFormatChanged       + 1
%DisconnectReasonSessionDisconnected   = %DisconnectReasonSessionLogoff       + 1
%DisconnectReasonExclusiveModeOverride = %DisconnectReasonSessionDisconnected + 1

' ########################################################################################
' Interface name = IAudioSessionEvents
' IID = 24918ACC-64B3-37C1-8CA9-74A66E9957A8
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IAudioSessionEvents_INTERFACE_DEFINED)
    %IAudioSessionEvents_INTERFACE_DEFINED = 1

$IID_IAudioSessionEvents = GUID$("{24918ACC-64B3-37C1-8CA9-74A66E9957A8}")

INTERFACE IAudioSessionEvents $IID_IAudioSessionEvents

   INHERIT IUnknown

   ' =====================================================================================
   METHOD OnDisplayNameChanged ( _                      ' VTable offset = 12
     BYREF NewDisplayName AS WSTRINGZ _                 ' __in LPCWSTR NewDisplayName
   , BYREF EventContext AS GUID _                       ' __in LPCGUID EventContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnIconPathChanged ( _                         ' VTable offset = 16
     BYREF NewIconPath AS WSTRINGZ _                    ' __in LPCWSTR NewIconPath
   , BYREF EventContext AS GUID _                       ' __in LPCGUID EventContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnSimpleVolumeChanged ( _                     ' VTable offset = 20
     BYVAL NewVolume AS SINGLE _                        ' __in float NewVolume
   , BYVAL NewMute AS LONG _                            ' __in BOOL NewMute
   , BYREF EventContext AS GUID _                       ' __in LPCGUID EventContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnChannelVolumeChanged ( _                    ' VTable offset = 24
     BYVAL ChannelCount AS DWORD _                      ' __in DWORD ChannelCount
   , BYREF NewChannelVolumeArray AS SINGLE _            ' __in ecount(ChannelCount) float NewChannelVolumeArray[  ]
   , BYVAL ChangedChannel AS DWORD _                    ' __in DWORD ChangedChannel
   , BYREF EventContext AS GUID _                       ' __in LPCGUID EventContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnGroupingParamChanged ( _                    ' VTable offset = 28
     BYREF NewGroupingParam AS GUID _                   ' __in LPCGUID NewGroupingParam
   , BYREF EventContext AS GUID _                       ' __in LPCGUID EventContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnStateChanged ( _                            ' VTable offset = 32
     BYVAL NewState AS LONG _                           ' __in AudioSessionState NewState
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnSessionDisconnected ( _                     ' VTable offset = 36
      BYVAL DisconnectReason AS AUDIOSESSIONDISCONNECTREASON_ENUM _ ' __in AudioSessionDisconnectReason DisconnectReason
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAudioSessionEvents_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IAudioSessionControl
' IID = F4B1A599-7266-4319-A8CA-E70ACB11E8CD
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IAudioSessionControl_INTERFACE_DEFINED)
    %IAudioSessionControl_INTERFACE_DEFINED = 1

$IID_IAudioSessionControl = GUID$("{F4B1A599-7266-4319-A8CA-E70ACB11E8CD}")


INTERFACE IAudioSessionControl $IID_IAudioSessionControl

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetState ( _                                  ' VTable offset = 12
     BYREF pRetVal AS LONG _                            ' __out AudioSessionState *pRetVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDisplayName ( _                            ' VTable offset = 16
     BYREF pRetVal AS DWORD _                           ' __out LPWSTR *pRetVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetDisplayName ( _                            ' VTable offset = 20
     BYREF Value AS WSTRINGZ _                          ' __in LPCWSTR Value
   , BYREF EventContext AS GUID _                       ' __in LPCGUID EventContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetIconPath ( _                               ' VTable offset = 24
     BYREF pRetVal AS DWORD _                           ' __out LPWSTR *pRetVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetIconPath ( _                               ' VTable offset = 28
     BYREF Value AS WSTRINGZ _                          ' __in LPCWSTR Value
   , BYREF EventContext AS GUID _                       ' __in LPCGUID EventContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetGroupingParam ( _                          ' VTable offset = 32
     BYREF pRetVal AS GUID _                            ' __out GUID *pRetVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetGroupingParam ( _                          ' VTable offset = 36
     BYREF Override AS GUID _                           ' __in LPCGUID Override
   , BYREF EventContext AS GUID _                       ' __in LPCGUID EventContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RegisterAudioSessionNotification ( _          ' VTable offset = 40
     BYVAL NewNotifications AS IAudioSessionEvents _    ' __in IAudioSessionEvents *NewNotifications
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UnregisterAudioSessionNotification ( _        ' VTable offset = 44
     BYVAL NewNotifications AS IAudioSessionEvents _    ' __in IAudioSessionEvents *NewNotifications
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAudioSessionControl_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IAudioSessionControl2
' IID = bfb7ff88-7239-4fc9-8fa2-07c950be9c6d
' Inherited interface = IAudioSessionControl
' ########################################################################################

#IF NOT %DEF(%IAudioSessionControl2_INTERFACE_DEFINED)
    %IAudioSessionControl2_INTERFACE_DEFINED = 1

$IID_IAudioSessionControl2 = GUID$("{bfb7ff88-7239-4fc9-8fa2-07c950be9c6d}")


INTERFACE IAudioSessionControl2 $IID_IAudioSessionControl2

   INHERIT IUnknown

   ' =====================================================================================
   ' IAudioSessionControl methods
   ' =====================================================================================
   METHOD GetState ( _                                  ' VTable offset = 12
     BYREF pRetVal AS LONG _                            ' __out AudioSessionState *pRetVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDisplayName ( _                            ' VTable offset = 16
     BYREF pRetVal AS DWORD _                           ' __out LPWSTR *pRetVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetDisplayName ( _                            ' VTable offset = 20
     BYREF Value AS WSTRINGZ _                           ' __in LPCWSTR Value
   , BYREF EventContext AS GUID _                       ' __in LPCGUID EventContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetIconPath ( _                               ' VTable offset = 24
     BYREF pRetVal AS DWORD _                            ' __out LPWSTR *pRetVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetIconPath ( _                               ' VTable offset = 28
     BYREF Value AS WSTRINGZ _                          ' __in LPCWSTR Value
   , BYREF EventContext AS GUID _                       ' __in LPCGUID EventContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetGroupingParam ( _                          ' VTable offset = 32
     BYREF pRetVal AS GUID _                            ' __out GUID *pRetVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetGroupingParam ( _                          ' VTable offset = 36
     BYREF Override AS GUID _                           ' __in LPCGUID Override
   , BYREF EventContext AS GUID _                       ' __in LPCGUID EventContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RegisterAudioSessionNotification ( _          ' VTable offset = 40
     BYVAL NewNotifications AS IAudioSessionEvents _    ' __in IAudioSessionEvents *NewNotifications
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UnregisterAudioSessionNotification ( _        ' VTable offset = 44
     BYVAL NewNotifications AS IAudioSessionEvents _    ' __in IAudioSessionEvents *NewNotifications
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IAudioSessionControl2 methods
   ' =====================================================================================
   METHOD GetSessionIdentifier ( _                      ' VTable offset = 48
     BYREF pRetVal AS DWORD _                           ' __out LPWSTR *pRetVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSessionInstanceIdentifier ( _              ' VTable offset = 52
     BYREF pRetVal AS DWORD _                           ' __out LPWSTR *pRetVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetProcessId ( _                              ' VTable offset = 56
     BYREF pRetVal AS DWORD _                           ' __out DWORD *pRetVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsSystemSoundsSession ( _                     ' VTable offset = 60
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetDuckingPreference ( _                      ' VTable offset = 64
     BYVAL optOut AS LONG _                             ' __in BOOL optOut
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAudioSessionControl2_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IAudioSessionManager
' IID = BFA971F1-4D5E-40BB-935E-967039BFBEE4
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IAudioSessionManager_INTERFACE_DEFINED)
    %IAudioSessionManager_INTERFACE_DEFINED = 1

$IID_IAudioSessionManager = GUID$("{BFA971F1-4D5E-40BB-935E-967039BFBEE4}")

INTERFACE IAudioSessionManager $IID_IAudioSessionManager

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetAudioSessionControl ( _                    ' VTable offset = 12
     BYREF AudioSessionGuid AS GUID _                   ' __in  LPCGUID AudioSessionGuid
   , BYVAL StreamFlags AS DWORD _                       ' __in  DWORD StreamFlags
   , BYREF SessionControl AS IAudioSessionControl _     ' __out IAudioSessionControl **SessionControl
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSimpleAudioVolume ( _                      ' VTable offset = 16
     BYREF AudioSessionGuid AS GUID _                   ' __in  LPCGUID AudioSessionGuid
   , BYVAL StreamFlags AS DWORD _                       ' __in  DWORD StreamFlags
   , BYREF AudioVolume AS ISimpleAudioVolume _          ' __out ISimpleAudioVolume **AudioVolume
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAudioSessionManager_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IAudioVolumeDuckNotification
' IID = C3B284D4-6D39-4359-B3CF-B56DDB3BB39C
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IAudioVolumeDuckNotification_INTERFACE_DEFINED)
    %IAudioVolumeDuckNotification_INTERFACE_DEFINED = 1

$IID_IAudioVolumeDuckNotification = GUID$("{C3B284D4-6D39-4359-B3CF-B56DDB3BB39C}")

INTERFACE IAudioVolumeDuckNotification $IID_IAudioVolumeDuckNotification

   INHERIT IUnknown

   ' =====================================================================================
   METHOD OnVolumeDuckNotification ( _                  ' VTable offset = 12
     BYREF sessionID AS WSTRINGZ _                      ' __in LPCWSTR sessionID
   , BYVAL countCommunicationSessions AS DWORD _        ' __in UINT32 countCommunicationSessions
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnVolumeUnduckNotification ( _                ' VTable offset = 16
     BYREF sessionID AS WSTRINGZ _                      ' __in LPCWSTR sessionID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAudioVolumeDuckNotification_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IAudioSessionNotification
' IID = 641DD20B-4D41-49CC-ABA3-174B9477BB08"
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IAudioSessionNotification_INTERFACE_DEFINED)
    %IAudioSessionNotification_INTERFACE_DEFINED = 1

$IID_IAudioSessionNotification = GUID$("{641DD20B-4D41-49CC-ABA3-174B9477BB08}")

INTERFACE IAudioSessionNotification $IID_IAudioSessionNotification

   INHERIT IUnknown

   ' =====================================================================================
   METHOD OnSessionCreated ( _                          ' VTable offset = 12
     BYVAL NewSession AS IAudioSessionControl _         ' __in IAudioSessionControl *NewSession
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAudioSessionNotification_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IAudioSessionEnumerator
' IID = E2F5BB11-0570-40CA-ACDD-3AA01277DEE8
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IAudioSessionEnumerator_INTERFACE_DEFINED)
    %IAudioSessionEnumerator_INTERFACE_DEFINED = 1

$IID_IAudioSessionEnumerator = GUID$("{E2F5BB11-0570-40CA-ACDD-3AA01277DEE8}")

INTERFACE IAudioSessionEnumerator $IID_IAudioSessionEnumerator

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetCount ( _                                  ' VTable offset = 12
     BYREF SessionCount AS LONG _                       ' __out int *SessionCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSession ( _                                ' VTable offset = 16
     BYVAL SessionCount AS LONG _                       ' __in int SessionCount
   , BYREF Session AS IAudioSessionControl _            ' __out IAudioSessionControl **Session
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAudioSessionEnumerator_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IAudioSessionManager2
' IID = 77AA99A0-1BD6-484F-8BC7-2C654C9A9B6F
' Inherited interface = IAudioSessionManager
' ########################################################################################

#IF NOT %DEF(%IAudioSessionManager2_INTERFACE_DEFINED)
    %IAudioSessionManager2_INTERFACE_DEFINED = 1

$IID_IAudioSessionManager2 = GUID$("{77AA99A0-1BD6-484F-8BC7-2C654C9A9B6F}")

INTERFACE IAudioSessionManager2 $IID_IAudioSessionManager2

   INHERIT IUnknown

   ' =====================================================================================
   ' IAudioSessionManager methods
   ' =====================================================================================
   METHOD GetAudioSessionControl ( _                    ' VTable offset = 12
     BYREF AudioSessionGuid AS GUID _                   ' __in  LPCGUID AudioSessionGuid
   , BYVAL StreamFlags AS DWORD _                       ' __in  DWORD StreamFlags
   , BYREF SessionControl AS IAudioSessionControl _     ' __out IAudioSessionControl **SessionControl
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSimpleAudioVolume ( _                      ' VTable offset = 16
     BYREF AudioSessionGuid AS GUID _                   ' __in  LPCGUID AudioSessionGuid
   , BYVAL StreamFlags AS DWORD _                       ' __in  DWORD StreamFlags
   , BYREF AudioVolume AS ISimpleAudioVolume _          ' __out ISimpleAudioVolume **AudioVolume
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IAudioSessionManager2 methods
   ' =====================================================================================
   METHOD GetSessionEnumerator ( _                      ' VTable offset = 20
     BYREF SessionEnum AS IAudioSessionEnumerator _     ' __retval_out IAudioSessionEnumerator **SessionEnum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RegisterSessionNotification ( _               ' VTable offset = 24
     BYVAL SessionNotification AS IAudioSessionNotification _ ' IAudioSessionNotification *SessionNotification
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UnregisterSessionNotification ( _             ' VTable offset = 28
     BYVAL SessionNotification AS IAudioSessionNotification _ ' IAudioSessionNotification *SessionNotification
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RegisterDuckNotification ( _                  ' VTable offset = 32
     BYREF sessionID AS WSTRINGZ _                      ' __in LPCWSTR sessionID
   , BYVAL duckNotification AS IAudioVolumeDuckNotification _ '__in  IAudioVolumeDuckNotification *duckNotification
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UnregisterDuckNotification ( _                ' VTable offset = 36
     BYVAL duckNotification AS IAudioVolumeDuckNotification _ '__in  IAudioVolumeDuckNotification *duckNotification
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAudioSessionManager2_INTERFACE_DEFINED__ */
