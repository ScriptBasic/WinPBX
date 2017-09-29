' ########################################################################################
' Microsoft Windows
' File: mfreadwrite.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%MFREADWRITE_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "mfobjects.inc"
#INCLUDE ONCE "mfidl.inc"

'#if (WINVER >= _WIN32_WINNT_WIN7)

$CLSID_MFReadWriteClassFactory = GUID$("{48e2ed0f-98c2-4a37-bed5-166312ddd83f}")

' ########################################################################################
' IMFReadWriteClassFactory interface
' IID = E7FE2E12-661C-40DA-92F9-4F002AB67627
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMFReadWriteClassFactory_INTERFACE_DEFINED)
    %IMFReadWriteClassFactory_INTERFACE_DEFINED = 1

$IID_IMFReadWriteClassFactory = GUID$("{E7FE2E12-661C-40DA-92F9-4F002AB67627}")

INTERFACE IMFReadWriteClassFactory $IID_IMFReadWriteClassFactory

   INHERIT IUnknown

   ' =====================================================================================
   METHOD CreateInstanceFromURL ( _                     ' VTable offset = 12
     BYREF clsid AS GUID _                              ' __in  REFCLSID clsid
   , BYREF pwszURL AS WSTRINGZ _                        ' __in  LPCWSTR pwszURL
   , BYVAL pAttributes AS IMFAttributes _               ' __in_opt IMFAttributes *pAttributes
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppvObject AS IUnknown _                      ' __out LPVOID *ppvObject
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateInstanceFromObject ( _                  ' VTable offset = 16
     BYREF clsid AS GUID _                              ' __in  REFCLSID clsid
   , BYVAL punkObject AS IUnknown _                     ' __in IUnknown *punkObject
   , BYVAL pAttributes AS IMFAttributes _               ' __in_opt IMFAttributes *pAttributes
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppvObject AS IUnknown _                      ' __out LPVOID *ppvObject
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMFReadWriteClassFactory_INTERFACE_DEFINED__ */

$CLSID_MFSourceReader = GUID$("{1777133c-0881-411b-a577-ad545f0714c4}")

DECLARE FUNCTION MFCreateSourceReaderFromURL IMPORT "Mfreadwrite.dll" ALIAS "MFCreateSourceReaderFromURL" ( _
   BYREF pwszURL AS WSTRINGZ _                          ' __in LPCWSTR pwszURL
 , BYVAL pAttributes AS IMFAttributes _                 ' __in_opt IMFAttributes *pAttributes
 , BYREF ppSourceReader AS IMFSourceReader _            ' __out IMFSourceReader **ppSourceReader
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION MFCreateSourceReaderFromByteStream IMPORT "Mfreadwrite.dll" ALIAS "MFCreateSourceReaderFromByteStream" ( _
   BYVAL pByteStream AS IMFByteStream _                 ' __in IMFByteStream *pByteStream
 , BYVAL pAttributes AS IMFAttributes _                 ' __in_opt IMFAttributes *pAttributes
 , BYREF ppSourceReader AS IMFSourceReader _            ' __out IMFSourceReader **ppSourceReader
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION MFCreateSourceReaderFromMediaSource IMPORT "Mfreadwrite.dll" ALIAS "MFCreateSourceReaderFromMediaSource" ( _
   BYVAL pMediaSource AS IMFMediaSource _               ' __in IMFMediaSource *pMediaSource
 , BYVAL pAttributes AS IMFAttributes _                 ' __in_opt IMFAttributes *pAttributes
 , BYREF ppSourceReader AS IMFSourceReader _            ' __out IMFSourceReader **ppSourceReader
 ) AS LONG                                              ' HRESULT

$MF_SOURCE_READER_ASYNC_CALLBACK = GUID$("{1e3dbeac-bb43-4c35-b507-cd644464c965}")
$MF_SOURCE_READER_D3D_MANAGER = GUID$("{ec822da2-e1e9-4b29-a0d8-563c719f5269}")
$MF_SOURCE_READER_DISABLE_DXVA = GUID$("{aa456cfd-3943-4a1e-a77d-1838c0ea2e35}")
$MF_SOURCE_READER_MEDIASOURCE_CONFIG = GUID$("{9085abeb-0354-48f9-abb5-200df838c68e}")
$MF_SOURCE_READER_MEDIASOURCE_CHARACTERISTICS = GUID$("{6d23f5c8-c5d7-4a9b-9971-5d11f8bca880}")
$MF_SOURCE_READER_ENABLE_VIDEO_PROCESSING = GUID$("{fb394f3d-ccf1-42ee-bbb3-f9b845d5681d}")
$MF_SOURCE_READER_DISCONNECT_MEDIASOURCE_ON_SHUTDOWN = GUID$("{56b67165-219e-456d-a22e-2d3004c7fe56}")

' enum MF_SOURCE_READER_FLAG
%MF_SOURCE_READERF_ERROR                   = &H1???
%MF_SOURCE_READERF_ENDOFSTREAM             = &H2???
%MF_SOURCE_READERF_NEWSTREAM               = &H4???
%MF_SOURCE_READERF_NATIVEMEDIATYPECHANGED  = &H10???
%MF_SOURCE_READERF_CURRENTMEDIATYPECHANGED = &H20???
%MF_SOURCE_READERF_STREAMTICK              = &H100???

' enum MF_SOURCE_READER_CONTROL_FLAG
%MF_SOURCE_READER_CONTROLF_DRAIN           = &H1???

' enum __MIDL___MIDL_itf_mfreadwrite_0000_0001_0001
%MF_SOURCE_READER_INVALID_STREAM_INDEX     = &Hffffffff???
%MF_SOURCE_READER_ALL_STREAMS              = &Hfffffffe???
%MF_SOURCE_READER_ANY_STREAM               = &Hfffffffe???
%MF_SOURCE_READER_FIRST_AUDIO_STREAM       = &Hfffffffd???
%MF_SOURCE_READER_FIRST_VIDEO_STREAM       = &Hfffffffc???
%MF_SOURCE_READER_MEDIASOURCE              = &Hffffffff???

' ########################################################################################
' IMFSourceReader interface
' IID = 70ae66f2-c809-4e4f-8915-bdcb406b7993
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMFSourceReader_INTERFACE_DEFINED)
    %IMFSourceReader_INTERFACE_DEFINED = 1

$IID_IMFSourceReader = GUID$("{70ae66f2-c809-4e4f-8915-bdcb406b7993}")

INTERFACE IMFSourceReader $IID_IMFSourceReader

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetStreamSelection ( _                        ' VTable offset = 12
     BYVAL dwStreamIndex AS DWORD _                     ' __in DWORD dwStreamIndex
   , BYREF pfSelected AS LONG _                         ' __out BOOL *pfSelected
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetStreamSelection ( _                        ' VTable offset = 16
     BYVAL dwStreamIndex AS DWORD _                     ' __in DWORD dwStreamIndex
   , BYVAL fSelected AS LONG _                          ' __in BOOL fSelected
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetNativeMediaType ( _                        ' VTable offset = 20
     BYVAL dwStreamIndex AS DWORD _                     ' __in DWORD dwStreamIndex
   , BYVAL dwMediaTypeIndex AS DWORD _                  ' __in DWORD dwMediaTypeIndex
   , BYREF ppMediaType AS IMFMediaType _                ' __out IMFMediaType **ppMediaType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCurrentMediaType ( _                       ' VTable offset = 24
     BYVAL dwStreamIndex AS DWORD _                     ' __in DWORD dwStreamIndex
   , BYREF ppMediaType AS IMFMediaType _                ' __out IMFMediaType **ppMediaType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetCurrentMediaType ( _                       ' VTable offset = 28
     BYVAL dwStreamIndex AS DWORD _                     ' __in DWORD dwStreamIndex
   , BYREF pdwReserved AS DWORD _                       ' __reserved DWORD *pdwReserved
   , BYVAL pMediaType AS IMFMediaType _                 ' __in IMFMediaType *pMediaType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetCurrentPosition ( _                        ' VTable offset = 32
     BYREF guidTimeFormat AS GUID _                     ' __in REFGUID guidTimeFormat
   , BYREF varPosition AS PROPVARIANT _                 ' __in REFPROPVARIANT varPosition
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ReadSample ( _                                ' VTable offset = 36
     BYVAL dwStreamIndex AS DWORD _                     ' __in DWORD dwStreamIndex
   , BYVAL dwControlFlags AS DWORD _                    ' __in DWORD dwControlFlags
   , OPTIONAL BYREF pdwActualStreamIndex AS DWORD _     ' __out_opt DWORD *pdwActualStreamIndex
   , OPTIONAL BYREF pdwStreamFlags AS DWORD _           ' __out_opt DWORD *pdwStreamFlags
   , OPTIONAL BYREF pllTimestamp AS QUAD _              ' __out_opt LONGLONG *pllTimestamp
   , OPTIONAL BYREF ppSample AS IMFSample _             ' __out_opt IMFSample **ppSample
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Flush ( _                                     ' VTable offset = 40
     BYVAL dwStreamIndex AS DWORD _                     ' __in DWORD dwStreamIndex
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetServiceForStream ( _                       ' VTable offset = 44
     BYVAL dwStreamIndex AS DWORD _                     ' __in DWORD dwStreamIndex
   , BYREF guidService AS GUID _                        ' __in REFGUID guidService
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppvObject AS IUnknown _                      ' __out LPVOID *ppvObject
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPresentationAttribute ( _                  ' VTable offset = 48
     BYVAL dwStreamIndex AS DWORD _                     ' __in DWORD dwStreamIndex
   , BYREF guidAttribute AS GUID _                      ' __in REFGUID guidAttribute
   , BYREF pvarAttribute AS PROPVARIANT _               ' __out PROPVARIANT *pvarAttribute
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMFSourceReader_INTERFACE_DEFINED__ */

' ########################################################################################
' IMFSourceReaderCallback interface
' IID = deec8d99-fa1d-4d82-84c2-2c8969944867
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMFSourceReaderCallback_INTERFACE_DEFINED)
    %IMFSourceReaderCallback_INTERFACE_DEFINED = 1

$IID_IMFSourceReaderCallback = GUID$("{deec8d99-fa1d-4d82-84c2-2c8969944867}")

INTERFACE IMFSourceReaderCallback $IID_IMFSourceReaderCallback

   INHERIT IUnknown

   ' =====================================================================================
   METHOD OnReadSample ( _                              ' VTable offset = 12
     BYVAL hrStatus AS LONG _                           ' __in HRESULT hrStatus
   , BYVAL dwStreamIndex AS DWORD _                     ' __in DWORD dwStreamIndex
   , BYVAL dwStreamFlags AS DWORD _                     ' __in DWORD dwStreamFlags
   , BYVAL llTimestamp AS QUAD _                        ' __in LONGLONG llTimestamp
   , OPTIONAL BYREF pSample AS IMFSample _              ' __in_opt IMFSample *pSample
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnFlush ( _                                   ' VTable offset = 16
     BYVAL dwStreamIndex AS DWORD _                     ' __in DWORD dwStreamIndex
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnEvent ( _                                   ' VTable offset = 20
     BYVAL dwStreamIndex AS DWORD _                     ' __in DWORD dwStreamIndex
   , BYVAL pEvent AS IMFMediaEvent _                    ' __in IMFMediaEvent *pEvent
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMFSourceReaderCallback_INTERFACE_DEFINED__ */

$CLSID_MFSinkWriter = GUID$("{a3bbfb17-8273-4e52-9e0e-9739dc887990}")

DECLARE FUNCTION MFCreateSinkWriterFromURL IMPORT "Mfreadwrite.dll" ALIAS "MFCreateSinkWriterFromURL" ( _
   BYREF pwszOutputURL AS WSTRINGZ _                    ' __in_opt LPCWSTR pwszOutputURL
 , BYVAL pByteStream AS IMFByteStream _                 ' __in_opt IMFByteStream *pByteStream
 , BYVAL pAttributes AS IMFAttributes _                 ' __in_opt IMFAttributes *pAttributes
 , BYREF ppSinkWriter AS IMFSinkWriter _                ' __out IMFSinkWriter **ppSinkWriter
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION MFCreateSinkWriterFromMediaSink IMPORT "Mfreadwrite.dll" ALIAS "MFCreateSinkWriterFromMediaSink" ( _
   BYVAL pMediaSink AS IMFMediaSink _                   ' __in IMFMediaSink *pMediaSink
 , BYVAL pAttributes AS IMFAttributes _                 ' __in_opt IMFAttributes *pAttributes
 , BYREF ppSinkWriter AS IMFSinkWriter _                ' __out IMFSinkWriter **ppSinkWriter
 ) AS LONG                                              ' HRESULT

$MF_SINK_WRITER_ASYNC_CALLBACK = GUID$("{48cb183e-7b0b-46f4-822e-5e1d2dda4354}")
$MF_SINK_WRITER_DISABLE_THROTTLING = GUID$("{08b845d8-2b74-4afe-9d53-be16d2d5ae4f}")

' enum __MIDL___MIDL_itf_mfreadwrite_0000_0003_0001
%MF_SINK_WRITER_INVALID_STREAM_INDEX = &Hffffffff???
%MF_SINK_WRITER_ALL_STREAMS          = &Hfffffffe???
%MF_SINK_WRITER_MEDIASINK            = &Hffffffff???

' // Size = 112 bytes
TYPE MF_SINK_WRITER_STATISTICS QWORD FILL
   cb                                 AS DWORD   ' DWORD
   llLastTimestampReceived            AS QUAD    ' LONGLONG
   llLastTimestampEncoded             AS QUAD    ' LONGLONG
   llLastTimestampProcessed           AS QUAD    ' LONGLONG
   llLastStreamTickReceived           AS QUAD    ' LONGLONG
   llLastSinkSampleRequest            AS QUAD    ' LONGLONG
   qwNumSamplesReceived               AS QUAD    ' QWORD
   qwNumSamplesEncoded                AS QUAD    ' QWORD
   qwNumSamplesProcessed              AS QUAD    ' QWORD
   qwNumStreamTicksReceived           AS QUAD    ' QWORD
   dwByteCountQueued                  AS DWORD   ' DWORD
   qwByteCountProcessed               AS QUAD    ' QWORD
   dwNumOutstandingSinkSampleRequests AS DWORD   ' DWORD
   dwAverageSampleRateReceived        AS DWORD   ' DWORD
   dwAverageSampleRateEncoded         AS DWORD   ' DWORD
   dwAverageSampleRateProcessed       AS DWORD   ' DWORD
END TYPE

' ########################################################################################
' IMFSinkWriter interface
' IID = 3137f1cd-fe5e-4805-a5d8-fb477448cb3d
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMFSinkWriter_INTERFACE_DEFINED)
    %IMFSinkWriter_INTERFACE_DEFINED = 1

$IID_IMFSinkWriter = GUID$("{3137f1cd-fe5e-4805-a5d8-fb477448cb3d}")

INTERFACE IMFSinkWriter $IID_IMFSinkWriter

   INHERIT IUnknown

   ' =====================================================================================
   METHOD AddStream ( _                                 ' VTable offset = 12
     BYVAL pTargetMediaType AS IMFMediaType _           ' __in IMFMediaType *pTargetMediaType
   , BYREF pdwStreamIndex AS DWORD _                    ' __out DWORD *pdwStreamIndex
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetInputMediaType ( _                         ' VTable offset = 16
     BYVAL dwStreamIndex AS DWORD _                     ' __in DWORD dwStreamIndex
   , BYVAL pInputMediaType AS IMFMediaType _            ' __in IMFMediaType *pInputMediaType
   , OPTIONAL BYVAL pEncodingParameters AS IMFAttributes _ ' __in_opt IMFAttributes *pEncodingParameters
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD BeginWriting ( _                              ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD WriteSample ( _                               ' VTable offset = 24
     BYVAL dwStreamIndex AS DWORD _                     ' __in DWORD dwStreamIndex
   , BYVAL pSample AS IMFSample _                       ' __in IMFSample *pSample
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SendStreamTick ( _                            ' VTable offset = 28
     BYVAL dwStreamIndex AS DWORD _                     ' __in DWORD dwStreamIndex
   , BYVAL llTimestamp AS QUAD _                        ' __in LONGLONG llTimestamp
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD PlaceMarker ( _                               ' VTable offset = 32
     BYVAL dwStreamIndex AS DWORD _                     ' __in DWORD dwStreamIndex
   , BYVAL pvContext AS DWORD _                         ' __in LPVOID pvContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD NotifyEndOfSegment ( _                        ' VTable offset = 36
     BYVAL dwStreamIndex AS DWORD _                     ' __in DWORD dwStreamIndex
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Flush ( _                                     ' VTable offset = 40
     BYVAL dwStreamIndex AS DWORD _                     ' __in DWORD dwStreamIndex
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Finalize ( _                                  ' VTable offset = 44
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetServiceForStream ( _                       ' VTable offset = 48
     BYVAL dwStreamIndex AS DWORD _                     ' __in DWORD dwStreamIndex
   , BYREF guidService AS GUID _                        ' __in REFGUID guidService
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppvObject AS DWORD _                         ' __out LPVOID *ppvObject
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetStatistics ( _                             ' VTable offset = 52
     BYVAL dwStreamIndex AS DWORD _                     ' __in DWORD dwStreamIndex
   , BYREF pStats AS MF_SINK_WRITER_STATISTICS _        ' __out MF_SINK_WRITER_STATISTICS *pStats
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMFSinkWriter_INTERFACE_DEFINED__ */

' ########################################################################################
' IMFSinkWriterCallback interface
' IID = 666f76de-33d2-41b9-a458-29ed0a972c58
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMFSinkWriterCallback_INTERFACE_DEFINED)
    %IMFSinkWriterCallback_INTERFACE_DEFINED = 1

$IID_IMFSinkWriterCallback = GUID$("{666f76de-33d2-41b9-a458-29ed0a972c58}")

INTERFACE IMFSinkWriterCallback $IID_IMFSinkWriterCallback

   INHERIT IUnknown

   ' =====================================================================================
   METHOD OnFinalize ( _                                ' VTable offset = 12
     BYVAL hrStatus AS LONG _                           ' __in HRESULT hrStatus
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnMarker ( _                                  ' VTable offset = 16
     BYVAL dwStreamIndex AS DWORD _                     ' __in DWORD dwStreamIndex
   , BYVAL pvContext AS DWORD _                         ' __in LPVOID pvContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMFSinkWriterCallback_INTERFACE_DEFINED__ */

$MF_READWRITE_DISABLE_CONVERTERS = GUID$("{98d5b065-1374-4847-8d5d-31520fee7156}")
$MF_READWRITE_ENABLE_HARDWARE_TRANSFORMS = GUID$("{a634a91c-822b-41b9-a494-4de4643612b0}")

'#endif // (WINVER >= _WIN32_WINNT_WIN7)
