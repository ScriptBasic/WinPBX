' ########################################################################################
' Microsoft Windows (Windows 7)
' File: AudioEngineEndpoint.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%AUDIOENGINEENDPOINT_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "oaidl.inc"
#INCLUDE ONCE "ocidl.inc"
#INCLUDE ONCE "propidl.inc"
#INCLUDE ONCE "audioapotypes.inc"
#INCLUDE ONCE "mmreg.inc"

' // Size = 64 bytes
TYPE AUDIO_ENDPOINT_EXCLUSIVE_CREATE_PARAMS   ' Must be 8 bytes aligned
   u32Size               AS DWORD          ' UINT32
   filler1               AS DWORD          ' // TO keep QWORD alignment
   hConnection           AS QUAD           ' LONGLONG
   bIsRtCapable          AS LONG           ' BOOL
   filler2               AS DWORD          ' // TO keep QWORD alignment
   hnsBufferDuration     AS QUAD           ' HNSTIME
   hnsPeriod             AS QUAD           ' HNSTIME
   u32LatencyCoefficient AS DWORD          ' UINT32
   wfxDeviceFormat       AS WAVEFORMATEX   ' WAVEFORMATEX
   filler3               AS WORD           ' // TO keep QWORD alignment
END TYPE

' // Size = 28 bytes
TYPE AUDIO_ENDPOINT_SHARED_CREATE_PARAMS DWORD
   u32Size         AS DWORD          ' UINT32
   u32TSSessionId  AS DWORD          ' UINT32
   wfxDeviceFormat AS WAVEFORMATEX   ' WAVEFORMATEX
END TYPE

' AE_POSITION_FLAGS enum
%POSITION_INVALID       = 0
%POSITION_DISCONTINUOUS = 1
%POSITION_CONTINUOUS    = 2
%POSITION_QPC_ERROR     = 4

' // Size = 40 bytes
TYPE AE_CURRENT_POSITION   ' Must be 8 bytes aligned
   u64DevicePosition  AS QUAD     ' UINT64
   u64StreamPosition  AS QUAD     ' UINT64
   u64PaddingFrames   AS QUAD     ' UINT64
   hnsQPCPosition     AS QUAD     ' HNSTIME
   f32FramesPerSecond AS SINGLE   ' FLOAT32
   Flag               AS LONG     ' AE_POSITION_FLAGS
END TYPE


' ########################################################################################
' Interface name = IAudioEndpoint
' IID = 30A99515-1527-4451-AF9F-00C5F0234DAF
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IAudioEndpoint_INTERFACE_DEFINED)
    %IAudioEndpoint_INTERFACE_DEFINED = 1

$IID_IAudioEndpoint = GUID$("{30A99515-1527-4451-AF9F-00C5F0234DAF}")

INTERFACE IAudioEndpoint $IID_IAudioEndpoint

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetFrameFormat ( _                            ' VTable offset = 12
     BYREF ppFormat AS WAVEFORMATEX _                   ' __out WAVEFORMATEX **ppFormat
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFramesPerPacket ( _                        ' VTable offset = 16
     BYREF pFramesPerPacket AS DWORD _                  ' __out UINT32 *pFramesPerPacket
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetLatency ( _                                ' VTable offset = 20
     BYREF pLatency AS QUAD _                           ' __out HNSTIME *pLatency
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetStreamFlags ( _                            ' VTable offset = 24
     BYVAL streamFlags AS DWORD _                       ' __in DWORD streamFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetEventHandle ( _                            ' VTable offset = 28
     BYVAL eventHandle AS DWORD _                       ' __in HANDLE eventHandle
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAudioEndpoint_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IAudioEndpointRT
' IID = DFD2005F-A6E5-4d39-A265-939ADA9FBB4D
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IAudioEndpointRT_INTERFACE_DEFINED)
    %IAudioEndpointRT_INTERFACE_DEFINED = 1

$IID_IAudioEndpointRT = GUID$("{DFD2005F-A6E5-4d39-A265-939ADA9FBB4D}")

INTERFACE IAudioEndpointRT $IID_IAudioEndpointRT

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetCurrentPadding ( _                         ' VTable offset = 12
     BYREF pPadding AS QUAD _                           ' __out HNSTIME *pPadding
   , BYREF pAeCurrentPosition AS AE_CURRENT_POSITION _  ' __out AE_CURRENT_POSITION *pAeCurrentPosition
   )                                                    ' void
   ' =====================================================================================
   METHOD ProcessingComplete ( _                        ' VTable offset = 16
   )                                                    ' void
   ' =====================================================================================
   METHOD SetPinInactive ( _                            ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPinActive ( _                              ' VTable offset = 24
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAudioEndpointRT_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IAudioInputEndpointRT
' IID = 8026AB61-92B2-43C1-A1DF-5C37EBD08D82
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IAudioInputEndpointRT_INTERFACE_DEFINED)
    %IAudioInputEndpointRT_INTERFACE_DEFINED = 1

$IID_IAudioInputEndpointRT = GUID$("{8026AB61-92B2-43C1-A1DF-5C37EBD08D82}")

INTERFACE IAudioInputEndpointRT $IID_IAudioInputEndpointRT

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetInputDataPointer ( _                            ' VTable offset = 12
     BYREF pConnectionProperty AS APO_CONNECTION_PROPERTY _  ' __in_out APO_CONNECTION_PROPERTY *pConnectionProperty
   , BYREF pAeTimeStamp AS AE_CURRENT_POSITION _             ' __in_out AE_CURRENT_POSITION *pAeTimeStamp
   )                                                         ' void
   ' =====================================================================================
   METHOD ReleaseInputDataPointer ( _                        ' VTable offset = 16
     BYVAL u32FrameCount AS DWORD _                          ' __in UINT32 u32FrameCount
   , BYVAL pDataPointer AS DWORD _                           ' __in UINT_PTR pDataPointer
   )                                                         ' void
   ' =====================================================================================
   METHOD PulseEndpoint ( _                                  ' VTable offset = 20
   )                                                         ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAudioInputEndpointRT_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IAudioOutputEndpointRT
' IID = 8FA906E4-C31C-4E31-932E-19A66385E9AA
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IAudioOutputEndpointRT_INTERFACE_DEFINED)
    %IAudioOutputEndpointRT_INTERFACE_DEFINED = 1

$IID_IAudioOutputEndpointRT = GUID$("{8FA906E4-C31C-4E31-932E-19A66385E9AA}")

INTERFACE IAudioOutputEndpointRT $IID_IAudioOutputEndpointRT

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetOutputDataPointer ( _                          ' VTable offset = 12
     BYVAL u32FrameCount AS DWORD _                         ' __in UINT32 u32FrameCount
   , BYREF pAeTimeStamp AS AE_CURRENT_POSITION _            ' __in AE_CURRENT_POSITION *pAeTimeStamp
   ) AS DWORD                                               ' UINT_PTR
   ' =====================================================================================
   METHOD ReleaseOutputDataPointer ( _                      ' VTable offset = 16
     BYREF pConnectionProperty AS APO_CONNECTION_PROPERTY _ ' __in const APO_CONNECTION_PROPERTY *pConnectionProperty
   )                                                        ' void
   ' =====================================================================================
   METHOD PulseEndpoint ( _                                 ' VTable offset = 20
   )                                                        ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAudioOutputEndpointRT_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IAudioDeviceEndpoint
' IID = D4952F5A-A0B2-4cc4-8B82-9358488DD8AC
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IAudioDeviceEndpoint_INTERFACE_DEFINED)
    %IAudioDeviceEndpoint_INTERFACE_DEFINED = 1

$IID_IAudioDeviceEndpoint = GUID$("{D4952F5A-A0B2-4cc4-8B82-9358488DD8AC}")

INTERFACE IAudioDeviceEndpoint $IID_IAudioDeviceEndpoint

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetBuffer ( _                                 ' VTable offset = 12
     BYVAL MaxPeriod AS QUAD _                          ' __in HNSTIME MaxPeriod
   , BYVAL u32LatencyCoefficient AS DWORD _             ' __in UINT32 u32LatencyCoefficient
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRTCaps ( _                                 ' VTable offset = 16
     BYREF pbIsRTCapable AS LONG _                      ' __out BOOL *pbIsRTCapable
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetEventDrivenCapable ( _                     ' VTable offset = 20
     BYREF pbisEventCapable AS LONG _                   ' __out BOOL *pbisEventCapable
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD WriteExclusiveModeParametersToSharedMemory ( _ ' VTable offset = 24
     BYVAL hTargetProcess AS DWORD _                    ' __in UINT_PTR hTargetProcess
   , BYVAL hnsPeriod AS QUAD _                          ' __in HNSTIME hnsPeriod
   , BYVAL hnsBufferDuration AS QUAD _                  ' __in HNSTIME hnsBufferDuration
   , BYVAL u32LatencyCoefficient AS DWORD _             ' __in UINT32 u32LatencyCoefficient
   , BYREF pu32SharedMemorySize AS DWORD _              ' __out UINT32 *pu32SharedMemorySize
   , BYREF phSharedMemory AS DWORD _                    ' __out UINT_PTR *phSharedMemory
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAudioDeviceEndpoint_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IAudioEndpointControl
' IID = C684B72A-6DF4-4774-BDF9-76B77509B653
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IAudioEndpointControl_INTERFACE_DEFINED)
    %IAudioEndpointControl_INTERFACE_DEFINED = 1

$IID_IAudioEndpointControl = GUID$("{C684B72A-6DF4-4774-BDF9-76B77509B653}")

INTERFACE IAudioEndpointControl $IID_IAudioEndpointControl

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Start ( _                                     ' VTable offset = 12
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reset ( _                                     ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Stop ( _                                      ' VTable offset = 18
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAudioEndpointControl_INTERFACE_DEFINED__ */
