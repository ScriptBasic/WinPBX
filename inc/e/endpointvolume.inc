' ########################################################################################
' Microsoft Windows
' File: endpointvolume.inc
' Contents: Master include file for DAO 3.6
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%ENDPOINTVOLUME_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "unknwn.inc"
#INCLUDE ONCE "devicetopology.inc"

' // Size = 32 bytes
TYPE AUDIO_VOLUME_NOTIFICATION_DATA DWORD
   guidEventContext    AS GUID     ' GUID
   bMuted              AS LONG     ' BOOL
   fMasterVolume       AS SINGLE   ' float
   nChannels           AS DWORD    ' UINT
   afChannelVolumes(0) AS SINGLE   ' float
END TYPE

%ENDPOINT_HARDWARE_SUPPORT_VOLUME = &H00000001???
%ENDPOINT_HARDWARE_SUPPORT_MUTE   = &H00000002???
%ENDPOINT_HARDWARE_SUPPORT_METER  = &H00000004???


' ########################################################################################
' Interface name = IAudioEndpointVolumeCallback
' IID = 657804FA-D6AD-4496-8A60-352752AF4F89
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IAudioEndpointVolumeCallback_INTERFACE_DEFINED)
    %IAudioEndpointVolumeCallback_INTERFACE_DEFINED = 1

$IID_IAudioEndpointVolumeCallback = GUID$("{657804FA-D6AD-4496-8A60-352752AF4F89}")

INTERFACE IAudioEndpointVolumeCallback $IID_IAudioEndpointVolumeCallback

   INHERIT IUnknown

   ' =====================================================================================
   METHOD OnNotify ( _                                  ' VTable offset = 12
     BYREF pNotify AS AUDIO_VOLUME_NOTIFICATION_DATA _  ' __in PAUDIO_VOLUME_NOTIFICATION_DATA pNotify
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAudioEndpointVolumeCallback_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IAudioEndpointVolume
' IID = 5CDF2C82-841E-4546-9722-0CF74078229A
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IAudioEndpointVolume_INTERFACE_DEFINED)
    %IAudioEndpointVolume_INTERFACE_DEFINED = 1

$IID_IAudioEndpointVolume = GUID$("{5CDF2C82-841E-4546-9722-0CF74078229A}")

INTERFACE IAudioEndpointVolume $IID_IAudioEndpointVolume

   INHERIT IUnknown

   ' =====================================================================================
   METHOD RegisterControlChangeNotify ( _               ' VTable offset = 12
     BYVAL pNotify AS IAudioEndpointVolumeCallback _    ' __in IAudioEndpointVolumeCallback *pNotify
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UnregisterControlChangeNotify ( _             ' VTable offset = 16
     BYVAL pNotify AS IAudioEndpointVolumeCallback _    ' __in IAudioEndpointVolumeCallback *pNotify
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetChannelCount ( _                           ' VTable offset = 20
     BYREF pnChannelCount AS DWORD _                    ' __out UINT *pnChannelCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetMasterVolumeLevel ( _                      ' VTable offset = 24
     BYVAL fLevelDB AS SINGLE _                         ' __in float fLevelDB
   , BYREF pguidEventContext AS GUID _                  ' __in LPCGUID pguidEventContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetMasterVolumeLevelScalar ( _                ' VTable offset = 28
     BYVAL fLevel AS SINGLE _                           ' __in float fLevel
   , BYREF pguidEventContext AS GUID _                  ' __in LPCGUID pguidEventContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMasterVolumeLevel ( _                      ' VTable offset = 32
     BYREF pfLevelDB AS SINGLE _                        ' __out float *pfLevelDB
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMasterVolumeLevelScalar ( _                ' VTable offset = 36
     BYREF pfLevel AS SINGLE _                          ' __out float *pfLevel
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetChannelVolumeLevel ( _                     ' VTable offset = 40
     BYVAL nChannel AS DWORD _                          ' __in UINT nChannel
   , BYVAL fLevelDB AS DWORD _                          ' __in float fLevelDB
   , BYREF pguidEventContext AS GUID _                  ' __in LPCGUID pguidEventContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetChannelVolumeLevelScalar ( _               ' VTable offset = 44
     BYVAL nChannel AS DWORD _                          ' __in UINT nChannel
   , BYVAL fLevel AS DWORD _                            ' __in float fLevel
   , BYREF pguidEventContext AS GUID _                  ' __in LPCGUID pguidEventContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetChannelVolumeLevel ( _                     ' VTable offset = 48
     BYVAL nChannel AS DWORD _                          ' __in UINT nChannel
   , BYREF pfLevelDB AS SINGLE _                        ' __out float *pfLevelDB
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetChannelVolumeLevelScalar ( _               ' VTable offset = 52
     BYVAL nChannel AS DWORD _                          ' __in UINT nChannel
   , BYREF pfLevel AS SINGLE _                          ' __out float *pfLevel
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetMute ( _                                   ' VTable offset = 56
     BYVAL bMute AS LONG _                              ' __in BOOL bMute
   , BYREF pguidEventContext AS GUID _                  ' __in LPCGUID pguidEventContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMute ( _                                   ' VTable offset = 60
     BYREF pbMute AS LONG _                             ' __out BOOL *pbMute
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetVolumeStepInfo ( _                         ' VTable offset = 64
     BYREF pnStep AS DWORD _                            ' __out UINT *pnStep
   , BYREF pnStepCount AS DWORD _                       ' __out UINT *pnStepCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD VolumeStepUp ( _                              ' VTable offset = 68
     BYREF pguidEventContext AS GUID _                  ' __in LPCGUID pguidEventContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD VolumeStepDown ( _                            ' VTable offset = 72
     BYREF pguidEventContext AS GUID _                  ' __in LPCGUID pguidEventContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD QueryHardwareSupport ( _                      ' VTable offset = 76
     BYVAL pdwHardwareSupportMask AS DWORD _            ' __out DWORD *pdwHardwareSupportMask
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetVolumeRange ( _                            ' VTable offset = 80
     BYREF pflVolumeMindB AS SINGLE _                   ' __out float *pflVolumeMindB
   , BYREF pflVolumeMaxdB AS SINGLE _                   ' __out float *pflVolumeMaxdB
   , BYREF pflVolumeIncrementdB AS SINGLE _             ' __out float *pflVolumeIncrementdB
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAudioEndpointVolume_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IAudioEndpointVolumeEx
' IID = 66E11784-F695-4F28-A505-A7080081A78F
' Inherited interface = IAudioEndpointVolume
' ########################################################################################

#IF NOT %DEF(%IAudioEndpointVolume_INTERFACE_DEFINED)
    %IAudioEndpointVolume_INTERFACE_DEFINED = 1

$IID_IAudioEndpointVolumeEx = GUID$("{66E11784-F695-4F28-A505-A7080081A78F}")

INTERFACE IAudioEndpointVolumeEx $IID_IAudioEndpointVolumeEx

   INHERIT IUnknown

   ' =====================================================================================
   ' IAudioEndpointVolume Methods
   ' =====================================================================================
   METHOD RegisterControlChangeNotify ( _               ' VTable offset = 12
     BYVAL pNotify AS IAudioEndpointVolumeCallback _    ' __in IAudioEndpointVolumeCallback *pNotify
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UnregisterControlChangeNotify ( _             ' VTable offset = 16
     BYVAL pNotify AS IAudioEndpointVolumeCallback _    ' __in IAudioEndpointVolumeCallback *pNotify
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetChannelCount ( _                           ' VTable offset = 20
     BYREF pnChannelCount AS DWORD _                    ' __out UINT *pnChannelCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetMasterVolumeLevel ( _                      ' VTable offset = 24
     BYVAL fLevelDB AS SINGLE _                         ' __in float fLevelDB
   , BYREF pguidEventContext AS GUID _                  ' __in LPCGUID pguidEventContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetMasterVolumeLevelScalar ( _                ' VTable offset = 28
     BYVAL fLevel AS SINGLE _                           ' __in float fLevel
   , BYREF pguidEventContext AS GUID _                  ' __in LPCGUID pguidEventContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMasterVolumeLevel ( _                      ' VTable offset = 32
     BYREF pfLevelDB AS SINGLE _                        ' __out float *pfLevelDB
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMasterVolumeLevelScalar ( _                ' VTable offset = 36
     BYREF pfLevel AS SINGLE _                          ' __out float *pfLevel
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetChannelVolumeLevel ( _                     ' VTable offset = 40
     BYVAL nChannel AS DWORD _                          ' __in UINT nChannel
   , BYVAL fLevelDB AS DWORD _                          ' __in float fLevelDB
   , BYREF pguidEventContext AS GUID _                  ' __in LPCGUID pguidEventContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetChannelVolumeLevelScalar ( _               ' VTable offset = 44
     BYVAL nChannel AS DWORD _                          ' __in UINT nChannel
   , BYVAL fLevel AS DWORD _                            ' __in float fLevel
   , BYREF pguidEventContext AS GUID _                  ' __in LPCGUID pguidEventContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetChannelVolumeLevel ( _                     ' VTable offset = 48
     BYVAL nChannel AS DWORD _                          ' __in UINT nChannel
   , BYREF pfLevelDB AS SINGLE _                        ' __out float *pfLevelDB
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetChannelVolumeLevelScalar ( _               ' VTable offset = 52
     BYVAL nChannel AS DWORD _                          ' __in UINT nChannel
   , BYREF pfLevel AS SINGLE _                          ' __out float *pfLevel
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetMute ( _                                   ' VTable offset = 56
     BYVAL bMute AS LONG _                              ' __in BOOL bMute
   , BYREF pguidEventContext AS GUID _                  ' __in LPCGUID pguidEventContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMute ( _                                   ' VTable offset = 60
     BYREF pbMute AS LONG _                             ' __out BOOL *pbMute
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetVolumeStepInfo ( _                         ' VTable offset = 64
     BYREF pnStep AS DWORD _                            ' __out UINT *pnStep
   , BYREF pnStepCount AS DWORD _                       ' __out UINT *pnStepCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD VolumeStepUp ( _                              ' VTable offset = 68
     BYREF pguidEventContext AS GUID _                  ' __in LPCGUID pguidEventContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD VolumeStepDown ( _                            ' VTable offset = 72
     BYREF pguidEventContext AS GUID _                  ' __in LPCGUID pguidEventContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD QueryHardwareSupport ( _                      ' VTable offset = 76
     BYVAL pdwHardwareSupportMask AS DWORD _            ' __out DWORD *pdwHardwareSupportMask
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetVolumeRange ( _                            ' VTable offset = 80
     BYREF pflVolumeMindB AS SINGLE _                   ' __out float *pflVolumeMindB
   , BYREF pflVolumeMaxdB AS SINGLE _                   ' __out float *pflVolumeMaxdB
   , BYREF pflVolumeIncrementdB AS SINGLE _             ' __out float *pflVolumeIncrementdB
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IAudioEndpointVolumeEx Method
   ' =====================================================================================
   METHOD GetVolumeRangeChannel ( _                     ' VTable offset = 84
     BYVAL iChannel AS DWORD _                          ' __in UINT iChannel
   , BYREF pflVolumeMindB AS SINGLE _                   ' __out  float *pflVolumeMindB
   , BYREF pflVolumeMaxdB AS SINGLE _                   ' __out  float *pflVolumeMaxdB
   , BYREF pflVolumeIncrementdB AS SINGLE _             ' __out  float *pflVolumeIncrementdB
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAudioEndpointVolumeEx_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IAudioMeterInformation
' IID = C02216F6-8C67-4B5B-9D00-D008E73E0064
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IAudioMeterInformation_INTERFACE_DEFINED)
    %IAudioMeterInformation_INTERFACE_DEFINED = 1

$IID_IAudioMeterInformation = GUID$("{C02216F6-8C67-4B5B-9D00-D008E73E0064}")

INTERFACE IAudioMeterInformation $IID_IAudioMeterInformation

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetPeakValue ( _                              ' VTable offset = 12
     BYREF pfPeak AS SINGLE _                           ' __out float *pfPeak
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMeteringChannelCount ( _                   ' VTable offset = 16
     BYREF pnChannelCount AS DWORD _                    ' __out UINT *pnChannelCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetChannelsPeakValues ( _                     ' VTable offset = 20
     BYVAL u32ChannelCount AS DWORD _                   ' __in UINT32 u32ChannelCount
   , BYREF afPeakValues AS SINGLE _                     ' __out float *afPeakValues
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD QueryHardwareSupport ( _                      ' VTable offset = 24
     BYREF pdwHardwareSupportMask AS DWORD _            ' __out DWORD *pdwHardwareSupportMask
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAudioMeterInformation_INTERFACE_DEFINED__ */
