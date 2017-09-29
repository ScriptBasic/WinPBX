' ########################################################################################
' Microsoft Windows
' File: AudioClient.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%AUDIOCLIENT_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "wtypes.inc"
#INCLUDE ONCE "unknwn.inc"
#INCLUDE ONCE "AudioSessionTypes.inc"
#INCLUDE ONCE "mmreg.inc"

'#if 0
'typedef /* [hidden][restricted] */ LONGLONG REFERENCE_TIME;
'#else
'#define _IKsControl_
'#include <ks.h>
'#include <ksmedia.h>
'#endif

' AUDCLNT_BUFFERFLAGS enum
MACRO AUDCLNT_BUFFERFLAGS_ENUM = DWORD
%AUDCLNT_BUFFERFLAGS_DATA_DISCONTINUITY = &H1
%AUDCLNT_BUFFERFLAGS_SILENT             = &H2
%AUDCLNT_BUFFERFLAGS_TIMESTAMP_ERROR    = &H4

' ########################################################################################
' Interface name = IAudioClient
' IID = 1CB9AD4C-DBFA-4C32-B178-C2F568A703B2
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IAudioClient_INTERFACE_DEFINED)
    %IAudioClient_INTERFACE_DEFINED = 1

$IID_IAudioClient = GUID$("{1CB9AD4C-DBFA-4C32-B178-C2F568A703B2}")

INTERFACE IAudioClient $IID_IAudioClient

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Initialize ( _                                ' VTable offset = 12
     BYVAL ShareMode AS AUDCLNT_SHAREMODE_ENUM _        ' __in AUDCLNT_SHAREMODE ShareMode
   , BYVAL StreamFlags AS DWORD _                       ' __in DWORD StreamFlags
   , BYVAL hnsBufferDuration AS QUAD _                  ' __in REFERENCE_TIME hnsBufferDuration
   , BYVAL hnsPeriodicity AS QUAD _                     ' __in REFERENCE_TIME hnsPeriodicity
   , BYREF pFormat AS WAVEFORMATEX _                    ' __in const WAVEFORMATEX *pFormat
   , BYREF AudioSessionGuid AS GUID _                   ' __in LPCGUID AudioSessionGuid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetBufferSize ( _                             ' VTable offset = 16
     BYREF pNumBufferFrames AS DWORD _                  ' __out UINT32 *pNumBufferFrames
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetStreamLatency ( _                          ' VTable offset = 20
     BYREF phnsLatency AS QUAD _                        ' __out REFERENCE_TIME *phnsLatency
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCurrentPadding ( _                         ' VTable offset = 24
     BYREF pNumPaddingFrames AS DWORD _                 ' __out UINT32 *pNumPaddingFrames
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsFormatSupported ( _                         ' VTable offset = 28
     BYVAL ShareMode AS AUDCLNT_SHAREMODE_ENUM _        ' __in AUDCLNT_SHAREMODE ShareMode
   , BYREF pFormat AS WAVEFORMATEX _                    ' __in const WAVEFORMATEX *pFormat
   , BYREF ppClosestMatch AS WAVEFORMATEX _             ' __out WAVEFORMATEX **ppClosestMatch
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMixFormat ( _                              ' VTable offset = 32
     BYREF ppDeviceFormat AS WAVEFORMATEX _             ' __out WAVEFORMATEX **ppDeviceFormat
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDevicePeriod ( _                           ' VTable offset = 36
     BYREF phnsDefaultDevicePeriod AS QUAD _            ' __out REFERENCE_TIME *phnsDefaultDevicePeriod,
   , BYREF phnsMinimumDevicePeriod AS QUAD _            ' __out REFERENCE_TIME *phnsMinimumDevicePeriod
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Start ( _                                     ' VTable offset = 40
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Stop ( _                                      ' VTable offset = 44
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reset ( _                                     ' VTable offset = 48
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetEventHandle ( _                            ' VTable offset = 52
     BYVAL eventHandle AS DWORD _                       ' __in HANDLE eventHandle
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetService ( _                                ' VTable offset = 56
     BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppv AS IUnknown _                            ' __out void **ppv
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAudioClient_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IAudioRenderClient
' IID = F294ACFC-3146-4483-A7BF-ADDCA7C260E2
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IAudioRenderClient_INTERFACE_DEFINED)
    %IAudioRenderClient_INTERFACE_DEFINED = 1

$IID_IAudioRenderClient = GUID$("{F294ACFC-3146-4483-A7BF-ADDCA7C260E2}")

INTERFACE IAudioRenderClient $IID_IAudioRenderClient

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetBuffer ( _                                 ' VTable offset = 12
     BYVAL NumFramesRequested AS DWORD _                ' __in UINT32 NumFramesRequested
   , BYREF ppData AS DWORD _                            ' __out BYTE **ppData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ReleaseBuffer ( _                             ' VTable offset = 16
     BYVAL NumFramesWritten AS DWORD _                  ' __in UINT32 NumFramesWritten
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAudioRenderClient_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IAudioCaptureClient
' IID = C8ADBD64-E71E-48a0-A4DE-185C395CD317
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IAudioCaptureClient_INTERFACE_DEFINED)
    %IAudioCaptureClient_INTERFACE_DEFINED = 1

$IID_IAudioCaptureClient = GUID$("{C8ADBD64-E71E-48a0-A4DE-185C395CD317}")

INTERFACE IAudioCaptureClient $IID_IAudioCaptureClient

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetBuffer ( _                                 ' VTable offset = 12
     BYREF ppData AS DWORD _                            ' __out BYTE **ppData
   , BYREF pNumFramesToRead AS DWORD _                  ' __out UINT32 *pNumFramesToRead
   , BYREF pdwFlags AS DWORD _                          ' __out DWORD *pdwFlags
   , BYREF pu64DevicePosition AS QUAD _                 ' __out UINT64 *pu64DevicePosition
   , BYREF pu64QPCPosition AS QUAD _                    ' __out UINT64 *pu64QPCPosition
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ReleaseBuffer ( _                             ' VTable offset = 16
     BYVAL NumFramesRead AS DWORD _                     ' __in UINT32 NumFramesRead
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetNextPacketSize ( _                         ' VTable offset = 20
     BYREF pNumFramesInNextPacket AS DWORD _            ' __out UINT32 *pNumFramesInNextPacket
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAudioCaptureClient_INTERFACE_DEFINED__ */


%AUDIOCLOCK_CHARACTERISTIC_FIXED_FREQ = &H00000001???


' ########################################################################################
' Interface name = IAudioClock
' IID = CD63314F-3FBA-4A1B-812C-EF96358728E7
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IAudioClock_INTERFACE_DEFINED)
    %IAudioClock_INTERFACE_DEFINED = 1

$IID_IAudioClock = GUID$("{CD63314F-3FBA-4A1B-812C-EF96358728E7}")

INTERFACE IAudioClock $IID_IAudioClock

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetFrequency ( _                              ' VTable offset = 12
     BYREF pu64Frequency AS QUAD _                      ' __out UINT64 *pu64Frequency
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPosition ( _                               ' VTable offset = 16
     BYREF pu64Position AS QUAD _                       ' __out UINT64 *pu64Position
   , BYREF pu64QPCPosition AS QUAD _                    ' __out UINT64 *pu64QPCPosition
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCharacteristics ( _                        ' VTable offset = 20
     BYREF pdwCharacteristics AS DWORD _                ' __out DWORD *pdwCharacteristics
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAudioClock_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IAudioClock2
' IID = 6f49ff73-6727-49ac-a008-d98cf5e70048
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IAudioClock2_INTERFACE_DEFINED)
    %IAudioClock2_INTERFACE_DEFINED = 1

$IID_IAudioClock2 = GUID$("{6f49ff73-6727-49ac-a008-d98cf5e70048}")

INTERFACE IAudioClock2 $IID_IAudioClock2

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetDevicePosition ( _                         ' VTable offset = 12
     BYREF DevicePosition AS QUAD _                     ' __out UINT64 *DevicePosition
   , BYREF QPCPosition AS QUAD _                        ' __out_opt UINT64 *QPCPosition
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAudioClock2_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IAudioClockAdjustment
' IID = f6e4c0a0-46d9-4fb8-be21-57a3ef2b626c
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IAudioClockAdjustment_INTERFACE_DEFINED)
    %IAudioClockAdjustment_INTERFACE_DEFINED = 1

$IID_IAudioClockAdjustment = GUID$("{f6e4c0a0-46d9-4fb8-be21-57a3ef2b626c}")

INTERFACE IAudioClockAdjustment $IID_IAudioClockAdjustment

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetSampleRate ( _                             ' VTable offset = 12
     BYVAL flSampleRate AS SINGLE _                     ' __in float flSampleRate
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAudioClockAdjustment_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = ISimpleAudioVolume
' IID = 87CE5498-68D6-44E5-9215-6DA47EF883D8
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ISimpleAudioVolume_INTERFACE_DEFINED)
    %ISimpleAudioVolume_INTERFACE_DEFINED = 1

$IID_ISimpleAudioVolume = GUID$("{87CE5498-68D6-44E5-9215-6DA47EF883D8}")

INTERFACE ISimpleAudioVolume $IID_ISimpleAudioVolume

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetMasterVolume ( _                           ' VTable offset = 12
     BYVAL fLevel AS SINGLE _                           ' __in float fLevel
   , BYREF EventContext AS GUID _                       ' __in LPCGUID EventContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMasterVolume ( _                           ' VTable offset = 16
     BYREF pfLevel AS SINGLE _                          ' __out float *pfLevel
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetMute ( _                                   ' VTable offset = 20
     BYVAL bMute AS LONG _                              ' __in const BOOL bMute
   , BYREF EventContext AS GUID _                       ' __in LPCGUID EventContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMute ( _                                   ' VTable offset = 24
     BYREF pbMute AS LONG _                             ' __out BOOL *pbMute
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISimpleAudioVolume_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IAudioStreamVolume
' IID = 93014887-242D-4068-8A15-CF5E93B90FE3
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IAudioStreamVolume_INTERFACE_DEFINED)
    %IAudioStreamVolume_INTERFACE_DEFINED = 1

$IID_IAudioStreamVolume = GUID$("{93014887-242D-4068-8A15-CF5E93B90FE3}")

INTERFACE IAudioStreamVolume $IID_IAudioStreamVolume

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetChannelCount ( _                           ' VTable offset = 12
     BYREF pdwCount AS DWORD _                          ' __out UINT32 *pdwCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetChannelVolume ( _                          ' VTable offset = 16
     BYVAL dwIndex AS DWORD _                           ' __in UINT32 dwIndex
   , BYVAL fLevel AS SINGLE _                           ' __in const float fLevel
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetChannelVolume ( _                          ' VTable offset = 20
     BYVAL dwIndex AS DWORD _                           ' __in UINT32 dwIndex
   , BYREF pfLevel AS SINGLE _                          ' __out float *pfLevel
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetAllVolumes ( _                             ' VTable offset = 24
     BYVAL dwCount AS DWORD _                           ' __in UINT32 dwCount
   , BYREF pfVolumes AS SINGLE _                        ' __in const float *pfVolumes
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAllVolumes ( _                             ' VTable offset = 28
     BYVAL dwCount AS DWORD _                           ' __in UINT32 dwCount
   , BYREF pfVolumes AS SINGLE _                        ' __out float *pfVolumes
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAudioStreamVolume_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IChannelAudioVolume
' IID = 1C158861-B533-4B30-B1CF-E853E51C59B8
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IChannelAudioVolume_INTERFACE_DEFINED)
    %IChannelAudioVolume_INTERFACE_DEFINED = 1

$IID_IChannelAudioVolume = GUID$("{1C158861-B533-4B30-B1CF-E853E51C59B8}")

INTERFACE IChannelAudioVolume $IID_IChannelAudioVolume

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetChannelCount ( _                           ' VTable offset = 12
     BYREF pdwCount AS DWORD _                          ' __out UINT32 *pdwCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetChannelVolume ( _                          ' VTable offset = 16
     BYVAL dwIndex AS DWORD _                           ' __in UINT32 dwIndex
   , BYVAL fLevel AS SINGLE _                           ' __in const float fLevel
   , BYREF EventContext AS GUID _                       ' __in LPCGUID EventContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetChannelVolume ( _                          ' VTable offset = 20
     BYVAL dwIndex AS DWORD _                           ' __in UINT32 dwIndex,
   , BYREF pfLevel AS SINGLE _                          ' __out float *pfLevel
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetAllVolumes ( _                             ' VTable offset = 24
     BYVAL dwCount AS DWORD _                           ' __in UINT32 dwCount
   , BYREF pfVolumes AS SINGLE _                        ' __in const float *pfVolumes
   , BYREF EventContext AS GUID _                       ' __in LPCGUID EventContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAllVolumes ( _                             ' VTable offset = 28
     BYVAL dwCount AS DWORD _                           ' __in UINT32 dwCount
   , BYREF pfVolumes AS SINGLE _                        ' __out float *pfVolumes
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IChannelAudioVolume_INTERFACE_DEFINED__ */


%FACILITY_AUDCLNT = &H889
'#define AUDCLNT_ERR(n) MAKE_HRESULT(SEVERITY_ERROR, FACILITY_AUDCLNT, n)
'#define AUDCLNT_SUCCESS(n) MAKE_SCODE(SEVERITY_SUCCESS, FACILITY_AUDCLNT, n)
MACRO AUDCLNT_ERR(n) = MAKE_HRESULT(%SEVERITY_ERROR, %FACILITY_AUDCLNT, n)
MACRO AUDCLNT_SUCCESS(n) = MAKE_SCODE(%SEVERITY_SUCCESS, %FACILITY_AUDCLNT, n)

%AUDCLNT_E_NOT_INITIALIZED              = &H88890001&   ' -2004287487 // AUDCLNT_ERR(0x001)
%AUDCLNT_E_ALREADY_INITIALIZED          = &H88890002&   ' -2004287486 // AUDCLNT_ERR(0x002)
%AUDCLNT_E_WRONG_ENDPOINT_TYPE          = &H88890003&   ' -2004287485 // AUDCLNT_ERR(0x003)
%AUDCLNT_E_DEVICE_INVALIDATED           = &H88890004&   ' -2004287484 // AUDCLNT_ERR(0x004)
%AUDCLNT_E_NOT_STOPPED                  = &H88890005&   ' -2004287483 // AUDCLNT_ERR(0x005)
%AUDCLNT_E_BUFFER_TOO_LARGE             = &H88890006&   ' -2004287482 // AUDCLNT_ERR(0x006)
%AUDCLNT_E_OUT_OF_ORDER                 = &H88890007&   ' -2004287481 // AUDCLNT_ERR(0x007)
%AUDCLNT_E_UNSUPPORTED_FORMAT           = &H88890008&   ' -2004287480 // AUDCLNT_ERR(0x008)
%AUDCLNT_E_INVALID_SIZE                 = &H88890009&   ' -2004287479 // AUDCLNT_ERR(0x009)
%AUDCLNT_E_DEVICE_IN_USE                = &H8889000A&   ' -2004287478 // AUDCLNT_ERR(0x00a)
%AUDCLNT_E_BUFFER_OPERATION_PENDING     = &H8889000B&   ' -2004287477 // AUDCLNT_ERR(0x00b)
%AUDCLNT_E_THREAD_NOT_REGISTERED        = &H8889000C&   ' -2004287476 // AUDCLNT_ERR(0x00c)
%AUDCLNT_E_EXCLUSIVE_MODE_NOT_ALLOWED   = &H8889000E&   ' -2004287474 // AUDCLNT_ERR(0x00e)
%AUDCLNT_E_ENDPOINT_CREATE_FAILED       = &H8889000F&   ' -2004287473 // AUDCLNT_ERR(0x00f)
%AUDCLNT_E_SERVICE_NOT_RUNNING          = &H88890010&   ' -2004287472 // AUDCLNT_ERR(0x010)
%AUDCLNT_E_EVENTHANDLE_NOT_EXPECTED     = &H88890011&   ' -2004287471 // AUDCLNT_ERR(0x011)
%AUDCLNT_E_EXCLUSIVE_MODE_ONLY          = &H88890012&   ' -2004287470 // AUDCLNT_ERR(0x012)
%AUDCLNT_E_BUFDURATION_PERIOD_NOT_EQUAL = &H88890013&   ' -2004287469 // AUDCLNT_ERR(0x013)
%AUDCLNT_E_EVENTHANDLE_NOT_SET          = &H88890014&   ' -2004287468 // AUDCLNT_ERR(0x014)
%AUDCLNT_E_INCORRECT_BUFFER_SIZE        = &H88890015&   ' -2004287467 // AUDCLNT_ERR(0x015)
%AUDCLNT_E_BUFFER_SIZE_ERROR            = &H88890016&   ' -2004287466 // AUDCLNT_ERR(0x016)
%AUDCLNT_E_CPUUSAGE_EXCEEDED            = &H88890017&   ' -2004287465 // AUDCLNT_ERR(0x017)
%AUDCLNT_E_BUFFER_ERROR                 = &H88890018&   ' -2004287464 // AUDCLNT_ERR(0x018)
%AUDCLNT_E_BUFFER_SIZE_NOT_ALIGNED      = &H88890019&   ' -2004287463 // AUDCLNT_ERR(0x019)
%AUDCLNT_E_INVALID_DEVICE_PERIOD        = &H88890020&   ' -2004287462 // AUDCLNT_ERR(0x020)

%AUDCLNT_S_BUFFER_EMPTY                 = &H08890001&   ' 143196161 // AUDCLNT_SUCCESS(0x001)
%AUDCLNT_S_THREAD_ALREADY_REGISTERED    = &H08890002&   ' 143196162 // AUDCLNT_SUCCESS(0x002)
%AUDCLNT_S_POSITION_STALLED             = &H08890003&   ' 143196163 // AUDCLNT_SUCCESS(0x003)
