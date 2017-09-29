' ########################################################################################
' Microsoft Windows
' File: austream.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%AUSTREAM_INC = 1

#INCLUDE ONCE "windows.inc"
#INCLUDE ONCE "mmstream.inc"
#INCLUDE ONCE "mmsystem.inc"   ' // for WAVEFORMATEX

' ########################################################################################
' Interface name = IAudioMediaStream
' IID = {F7537560-A3BE-11D0-8212-00C04FC32C45}
' Inherited interface = IMediaStream
' ########################################################################################

#IF NOT %DEF(%IAudioMediaStream_INTERFACE_DEFINED)
    %IAudioMediaStream_INTERFACE_DEFINED = 1

$IID_IAudioMediaStream = GUID$("{F7537560-A3BE-11D0-8212-00C04FC32C45}")

INTERFACE IAudioMediaStream $IID_IAudioMediaStream

   INHERIT IUnknown

   ' =====================================================================================
   ' IMediaStream Methods
   ' =====================================================================================
   METHOD GetMultiMediaStream ( _                       ' VTable offset = 12
     BYREF ppMultiMediaStream AS IMultiMediaStream _    ' __out IMultiMediaStream **ppMultiMediaStream
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetInformation ( _                            ' VTable offset = 16
     BYREF pPurposeId AS GUID _                         ' __out MSPID *pPurposeId
   , BYREF pType AS STREAM_TYPE_ENUM _                  ' __out STREAM_TYPE *pType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetSameFormat ( _                             ' VTable offset = 20
     BYVAL pStreamThatHasDesiredFormat AS IMediaStream _  ' __in IMediaStream *pStreamThatHasDesiredFormat
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AllocateSample ( _                            ' VTable offset = 24
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF ppSample AS IStreamSample _                  ' __out IStreamSample **ppSample
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateSharedSample ( _                        ' VTable offset = 28
     BYVAL pExistingSample AS IStreamSample _           ' __in IStreamSample *pExistingSample
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF ppNewSample AS IStreamSample _               ' __out IStreamSample **ppNewSample
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SendEndOfStream ( _                           ' VTable offset = 32
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IAudioMediaStream Methods
   ' =====================================================================================
   METHOD GetFormat ( _                                 ' VTable offset = 36
     BYREF pWaveFormatCurrent AS WAVEFORMATEX _         ' __out WAVEFORMATEX *pWaveFormatCurrent
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetFormat ( _                                 ' VTable offset = 40
     BYREF lpWaveFormat AS WAVEFORMATEX _               ' __in const WAVEFORMATEX *lpWaveFormat
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateSample ( _                              ' VTable offset = 44
     BYVAL pAudioData AS IAudioData _                   ' __in IAudioData *pAudioData
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF ppSample AS IAudioStreamSample _             ' __out IAudioStreamSample **ppSample
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAudioMediaStream_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IAudioStreamSample
' IID = {345FEE00-ABA5-11D0-8212-00C04FC32C45}
' Inherited interface = IStreamSample
' ########################################################################################

#IF NOT %DEF(%IAudioStreamSample_INTERFACE_DEFINED)
    %IAudioStreamSample_INTERFACE_DEFINED = 1

$IID_IAudioStreamSample = GUID$("{345FEE00-ABA5-11D0-8212-00C04FC32C45}")

INTERFACE IAudioStreamSample $IID_IAudioStreamSample

   INHERIT IUnknown

   ' =====================================================================================
   ' IStreamSample Methods
   ' =====================================================================================
   METHOD GetMediaStream ( _                            ' VTable offset = 12
     BYREF ppMediaStream AS IMediaStream _              ' __out IMediaStream **ppMediaStream
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSampleTimes ( _                            ' VTable offset = 16
     BYREF pStartTime AS QUAD _                         ' __out STREAM_TIME *pStartTime
   , BYREF pEndTime AS QUAD _                           ' __out STREAM_TIME *pEndTime
   , BYREF pCurrentTime AS QUAD _                       ' __out STREAM_TIME *pCurrentTime
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetSampleTimes ( _                            ' VTable offset = 20
     BYVAL pStartTime AS QUAD _                         ' __in const STREAM_TIME *pStartTime
   , BYVAL pEndTime AS QUAD _                           ' __in const STREAM_TIME *pEndTime
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Update ( _                                    ' VTable offset = 24
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYVAL hEvent AS DWORD _                            ' __in HANDLE hEvent
   , BYVAL pfnAPC AS DWORD _                            ' __in PAPCFUNC pfnAPC
   , BYVAL dwAPCData AS DWORD _                         ' __in DWORD_PTR dwAPCData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CompletionStatus ( _                          ' VTable offset = 28
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYVAL dwMilliseconds AS DWORD _                    ' __in DWORD dwMilliseconds
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IAudioStreamSample Methods
   ' =====================================================================================
   METHOD GetAudioData ( _                              ' VTable offset = 32
     BYREF ppAudio AS IAudioData _                      ' __out IAudioData **ppAudio
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAudioStreamSample_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IMemoryData
' IID = {327FC560-AF60-11D0-8212-00C04FC32C45}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMemoryData_INTERFACE_DEFINED)
    %IMemoryData_INTERFACE_DEFINED = 1

$IID_IMemoryData = GUID$("{327FC560-AF60-11D0-8212-00C04FC32C45}")

INTERFACE IMemoryData $IID_IMemoryData

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetBuffer ( _                                 ' VTable offset = 12
     BYVAL cbSize AS DWORD _                            ' __in DWORD cbSize
   , BYVAL pbData AS BYTE PTR _                         ' __in BYTE *pbData
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetInfo ( _                                   ' VTable offset = 16
     BYREF pdwLength AS DWORD _                         ' __out DWORD *pdwLength
   , BYREF ppbData AS DWORD _                           ' __out BYTE **ppbData
   , BYREF pcbActualData AS DWORD _                     ' __out DWORD *pcbActualData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetActual ( _                                 ' VTable offset = 20
     BYVAL cbDataValid AS DWORD _                       ' __in DWORD cbDataValid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMemoryData_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IAudioData
' IID = {54C719C0-AF60-11D0-8212-00C04FC32C45}
' Inherited interface = IMemoryData
' ########################################################################################

#IF NOT %DEF(%IAudioData_INTERFACE_DEFINED)
    %IAudioData_INTERFACE_DEFINED = 1

$IID_IAudioData = GUID$("{54C719C0-AF60-11D0-8212-00C04FC32C45}")

INTERFACE IAudioData $IID_IAudioData

   INHERIT IUnknown

   ' =====================================================================================
   ' IMemoryData Methods
   ' =====================================================================================
   METHOD SetBuffer ( _                                 ' VTable offset = 12
     BYVAL cbSize AS DWORD _                            ' __in DWORD cbSize
   , BYVAL pbData AS BYTE PTR _                         ' __in BYTE *pbData
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetInfo ( _                                   ' VTable offset = 16
     BYREF pdwLength AS DWORD _                         ' __out DWORD *pdwLength
   , BYREF ppbData AS DWORD _                           ' __out BYTE **ppbData
   , BYREF pcbActualData AS DWORD _                     ' __out DWORD *pcbActualData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetActual ( _                                 ' VTable offset = 20
     BYVAL cbDataValid AS DWORD _                       ' __in DWORD cbDataValid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IAudioData Methods
   ' =====================================================================================
   METHOD GetFormat ( _                                 ' VTable offset = 36
     BYREF pWaveFormatCurrent AS WAVEFORMATEX _         ' __out WAVEFORMATEX *pWaveFormatCurrent
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetFormat ( _                                 ' VTable offset = 40
     BYREF lpWaveFormat AS WAVEFORMATEX _               ' __in const WAVEFORMATEX *lpWaveFormat
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAudioData_INTERFACE_DEFINED__ */
