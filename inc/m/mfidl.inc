' ########################################################################################
' Microsoft Windows
' File: mfidl.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%MFIDL_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "mfobjects.inc"
#INCLUDE ONCE "mftransform.inc"

#INCLUDE ONCE "windef.inc"

' enum MFSESSION_SETTOPOLOGY_FLAGS
%MFSESSION_SETTOPOLOGY_IMMEDIATE     = &H1
%MFSESSION_SETTOPOLOGY_NORESOLUTION  = &H2
%MFSESSION_SETTOPOLOGY_CLEAR_CURRENT = &H4

' enum MFSESSION_GETFULLTOPOLOGY_FLAGS
%MFSESSION_GETFULLTOPOLOGY_CURRENT   = &H1

' enum MFPMPSESSION_CREATION_FLAGS
%MFPMPSESSION_UNPROTECTED_PROCESS    = &H1

'typedef unsigned __int64 TOPOID;

' ########################################################################################
' Interface name = IMFMediaSession
' IID = 90377834-21D0-4DEE-8214-BA2E3E6C1127
' Inherited interface = IMFMediaEventGenerator
' ########################################################################################

#IF NOT %DEF(%IMFMediaSession_INTERFACE_DEFINED)
    %IMFMediaSession_INTERFACE_DEFINED = 1

$IID_IMFMediaSession = GUID$("{90377834-21D0-4DEE-8214-BA2E3E6C1127}")

INTERFACE IMFMediaSession $IID_IMFMediaSession

   INHERIT IUnknown

   ' =====================================================================================
   ' IMFMediaEventGenerator methods
   ' =====================================================================================
   METHOD GetEvent ( _                                  ' VTable offset = 12
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF ppEvent AS IMFMediaEvent _                   ' __out IMFMediaEvent **ppEvent
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD BeginGetEvent ( _                             ' VTable offset = 16
     BYVAL pCallback AS IMFAsyncCallback _              ' __in IMFAsyncCallback *pCallback
   , BYVAL punkState AS IUnknown _                      ' __in IUnknown *punkState
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EndGetEvent ( _                               ' VTable offset = 20
     BYVAL pResult AS IMFAsyncResult _                  ' __in IMFAsyncResult *pResult
   , BYREF ppEvent AS IMFMediaEvent _                   ' __out IMFMediaEvent **ppEvent
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD QueueEvent ( _                                ' VTable offset = 24
     BYVAL met AS DWORD _                               ' __in MediaEventType met
   , BYREF guidExtendedType AS GUID _                   ' __in REFGUID guidExtendedType
   , BYVAL hrStatus AS LONG _                           ' __in HRESULT hrStatus
   , BYREF pvValue AS PROPVARIANT _                     ' __in const PROPVARIANT *pvValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IMFMediaSession methods
   ' =====================================================================================
   METHOD SetTopology ( _                               ' VTable offset = 28
     BYVAL dwSetTopologyFlags AS DWORD _                ' __in DWORD dwSetTopologyFlags
   , BYVAL pTopology AS IMFTopology _                   ' __in IMFTopology *pTopology
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ClearTopologies ( _                           ' VTable offset = 32
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Start ( _                                     ' VTable offset = 36
     BYREF pguidTimeFormat AS GUID _                    ' __in const GUID *pguidTimeFormat
   , BYREF pvarStartPosition AS PROPVARIANT _           ' __in const PROPVARIANT *pvarStartPosition
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Pause ( _                                     ' VTable offset = 40
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Stop ( _                                      ' VTable offset = 44
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Close ( _                                     ' VTable offset = 48
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Shutdown ( _                                  ' VTable offset = 52
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetClock ( _                                  ' VTable offset = 56
     BYREF ppClock AS IMFClock _                        ' __out IMFClock **ppClock
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSessionCapabilities ( _                    ' VTable offset = 60
     BYREF pdwCaps AS DWORD _                           ' __out DWORD *pdwCaps
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFullTopology ( _                           ' VTable offset = 64
     BYVAL dwGetFullTopologyFlags AS DWORD _            ' __in DWORD dwGetFullTopologyFlags
   , BYVAL TopoId AS QUAD _                             ' __in TOPOID TopoId
   , BYREF ppFullTopology AS IMFTopology _              ' __out IMFTopology **ppFullTopology
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMFMediaSession_INTERFACE_DEFINED__ */


$MF_SESSION_TOPOLOADER = GUID$("{1E83D482-1F1C-4571-8405-88F4B2181F71}")
$MF_SESSION_GLOBAL_TIME = GUID$("{1E83D482-1F1C-4571-8405-88F4B2181F72}")
$MF_SESSION_QUALITY_MANAGER = GUID$("{1E83D482-1F1C-4571-8405-88F4B2181F73}")
$MF_SESSION_CONTENT_PROTECTION_MANAGER = GUID$("{1E83D482-1F1C-4571-8405-88F4B2181F74}")
$MF_SESSION_SERVER_CONTEXT = GUID$("{AFE5B291-50FA-46E8-B9BE-0C0C3CE4B3A5}")
$MF_SESSION_REMOTE_SOURCE_MODE = GUID$("{F4033EF4-9BB3-4378-941F-85A0856BC244}")
$MF_SESSION_APPROX_EVENT_OCCURRENCE_TIME = GUID$("{190E852F-6238-42D1-B5AF-69EA338EF850}")
$MF_PMP_SERVER_CONTEXT = GUID$("{2F00C910-D2CF-4278-8B6A-D077FAC3A25F}")


DECLARE FUNCTION MFCreateMediaSession IMPORT "mf.dll" ALIAS "MFCreateMediaSession" ( _
   BYVAL pConfiguration AS IMFAttributes _              ' __in  IMFAttributes* pConfiguration
 , BYREF ppMediaSession AS IMFMediaSession _            ' __out IMFMediaSession** ppMediaSession
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION MFCreatePMPMediaSession IMPORT "mf.dll" ALIAS "MFCreatePMPMediaSession" ( _
   BYVAL dwCreationFlags AS DWORD _                     ' __in  DWORD dwCreationFlags
 , BYVAL pConfiguration AS IMFAttributes _              ' __in  IMFAttributes *pConfiguration
 , BYREF ppMediaSession AS IMFMediaSession _            ' __out IMFMediaSession** ppMediaSession
 , BYREF ppEnablerActivate AS IMFActivate _             ' __out IMFActivate **ppEnablerActivate
 ) AS LONG                                              ' HRESULT

' enum MF_OBJECT_TYPE
%MF_OBJECT_MEDIASOURCE = 0
%MF_OBJECT_BYTESTREAM  = %MF_OBJECT_MEDIASOURCE + 1
%MF_OBJECT_INVALID     = %MF_OBJECT_BYTESTREAM  + 1

' enum __MIDL___MIDL_itf_mfidl_0000_0001_0001
%MF_RESOLUTION_MEDIASOURCE                                           = &H1???
%MF_RESOLUTION_BYTESTREAM                                            = &H2???
%MF_RESOLUTION_CONTENT_DOES_NOT_HAVE_TO_MATCH_EXTENSION_OR_MIME_TYPE = &H10???
%MF_RESOLUTION_KEEP_BYTE_STREAM_ALIVE_ON_FAIL                        = &H20???
%MF_RESOLUTION_READ                                                  = &H10000???
%MF_RESOLUTION_WRITE                                                 = &H20000???

' enum MF_CONNECT_METHOD
%MF_CONNECT_DIRECT             = 0???
%MF_CONNECT_ALLOW_CONVERTER    = &H1???
%MF_CONNECT_ALLOW_DECODER      = &H3???
%MF_CONNECT_AS_OPTIONAL        = &H10000???
%MF_CONNECT_AS_OPTIONAL_BRANCH = &H20000???

' enum MF_TOPOLOGY_RESOLUTION_STATUS_FLAGS
%MF_TOPOLOGY_RESOLUTION_SUCCEEDED            = 0???
%MF_OPTIONAL_NODE_REJECTED_MEDIA_TYPE        = &H1???
%MF_OPTIONAL_NODE_REJECTED_PROTECTED_PROCESS = &H2???


' ########################################################################################
' Interface name = IMFSourceResolver
' IID = FBE5A32D-A497-4b61-BB85-97B1A848A6E3
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMFSourceResolver_INTERFACE_DEFINED)
    %IMFSourceResolver_INTERFACE_DEFINED = 1

$IID_IMFSourceResolver = GUID$("{FBE5A32D-A497-4b61-BB85-97B1A848A6E3}")

INTERFACE IMFSourceResolver $IID_IMFSourceResolver

   INHERIT IUnknown

   ' =====================================================================================
   METHOD CreateObjectFromURL ( _                       ' VTable offset = 12
     BYREF pwszURL AS WSTRINGZ _                        ' __in LPCWSTR pwszURL
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYVAL pProps AS IPropertyStore _                   ' __in IPropertyStore *pProps
   , BYREF pObjectType AS LONG _                        ' __out MF_OBJECT_TYPE *pObjectType
   , BYREF ppObject AS IUnknown _                       ' __out IUnknown **ppObject
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateObjectFromByteStream ( _                ' VTable offset = 16
     BYVAL pByteStream AS IMFByteStream _               ' __in IMFByteStream *pByteStream
   , BYREF pwszURL AS WSTRINGZ _                        ' __in LPCWSTR pwszURL
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYVAL pProps AS IPropertyStore _                   ' __in IPropertyStore *pProps
   , BYREF pObjectType AS LONG _                        ' __out MF_OBJECT_TYPE *pObjectType
   , BYREF ppObject AS IUnknown _                       ' __out IUnknown **ppObject
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD BeginCreateObjectFromURL ( _                  ' VTable offset = 20
     BYREF pwszURL AS WSTRINGZ _                        ' __in LPCWSTR pwszURL
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYVAL pProps AS IPropertyStore _                   ' __in IPropertyStore *pProps
   , BYREF ppIUnknownCancelCookie AS IUnknown _         ' __out IUnknown **ppIUnknownCancelCookie
   , BYVAL pCallback AS IMFAsyncCallback _              ' __in IMFAsyncCallback *pCallback
   , BYVAL punkState AS IUnknown _                      ' __in IUnknown *punkState
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EndCreateObjectFromURL ( _                    ' VTable offset = 24
     BYVAL pResult AS IMFAsyncResult _                  ' __in IMFAsyncResult *pResult
   , BYREF pObjectType AS LONG _                        ' __out MF_OBJECT_TYPE *pObjectType
   , BYREF ppObject AS IUnknown _                       ' __out IUnknown **ppObject
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD BeginCreateObjectFromByteStream ( _           ' VTable offset = 28
     BYVAL pByteStream AS IMFByteStream _               ' __in IMFByteStream *pByteStream
   , BYREF pwszURL AS WSTRINGZ _                        ' __in LPCWSTR pwszURL
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYVAL pProps AS IPropertyStore _                   ' __in IPropertyStore *pProps
   , BYREF ppIUnknownCancelCookie AS IUnknown _         ' __out IUnknown **ppIUnknownCancelCookie
   , BYVAL pCallback AS IMFAsyncCallback _              ' __in IMFAsyncCallback *pCallback
   , BYVAL punkState AS IUnknown _                      ' __in IUnknown *punkState
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EndCreateObjectFromByteStream ( _             ' VTable offset = 32
     BYVAL pResult AS IMFAsyncResult _                  ' __in IMFAsyncResult *pResult
   , BYREF pObjectType AS LONG _                        ' __out MF_OBJECT_TYPE *pObjectType
   , BYREF ppObject AS IUnknown _                       ' __out IUnknown **ppObject
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CancelObjectCreation ( _                      ' VTable offset = 36
     BYVAL pIUnknownCancelCookie AS IUnknown _          ' __in IUnknown *pIUnknownCancelCookie
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMFSourceResolver_INTERFACE_DEFINED__ */


DECLARE FUNCTION MFCreateSourceResolver IMPORT "mf.dll" ALIAS "MFCreateSourceResolver" ( _
   BYREF ppISourceResolver AS IMFSourceResolver _       ' __out IMFSourceResolver **ppISourceResolver
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION CreatePropertyStore IMPORT "mfplat.dll" ALIAS "CreatePropertyStore" ( _
   BYREF ppStore AS IPropertyStore _                    ' __out IPropertyStore **ppStore
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION MFGetSupportedSchemes IMPORT "mf.dll" ALIAS "MFGetSupportedSchemes" ( _
   BYREF pPropVarSchemeArray AS PROPVARIANT _           ' __out PROPVARIANT* pPropVarSchemeArray
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION MFGetSupportedMimeTypes IMPORT "mf.dll" ALIAS "MFGetSupportedMimeTypes" ( _
   BYREF pPropVarMimeTypeArray AS PROPVARIANT _         ' __out PROPVARIANT* pPropVarMimeTypeArray
 ) AS LONG                                              ' HRESULT

'static const PROPERTYKEY MFPKEY_SourceOpenMonitor = { { 0x074d4637, 0xb5ae, 0x465d, 0xaf, 0x17, 0x1a, 0x53, 0x8d, 0x28, 0x59, 0xdd}, 0x02 };
'static const PROPERTYKEY MFPKEY_ASFMediaSource_ApproxSeek = { { 0xb4cd270f, 0x244d, 0x4969, 0xbb, 0x92, 0x3f, 0x0f, 0xb8, 0x31, 0x6f, 0x10}, 0x01 };

MACRO MFPKEY_SourceOpenMonitor = GUID$("{074D4637-B5AE-465D-AF17-1A538D2859DD}") & MKDWD$(&H02)
MACRO MFPKEY_ASFMediaSource_ApproxSeek = GUID$("{B4CD270F-244D-4969-BB92-3F0FB8316F10}") & MKDWD$(&H01)

'#if (WINVER >= _WIN32_WINNT_WIN7)
MACRO MFPKEY_ASFMediaSource_IterativeSeekIfNoIndex = GUID$("{170b65dc-4a4e-4407a-ac22-577f50e4a37c}") & MKDWD$(&H01)
MACRO MFPKEY_ASFMediaSource_IterativeSeek_Max_Count = GUID$("{170b65dc-4a4e-4407a-ac22-577f50e4a37c}") & MKDWD$(&H02)
MACRO MFPKEY_ASFMediaSource_IterativeSeek_Tolerance_In_MilliSecond = GUID$("{170b65dc-4a4e-4407a-ac22-577f50e4a37c}") & MKDWD$(&H03)
MACRO MFPKEY_Content_DLNA_Profile_ID = GUID$("{cfa31b45-525d-4998-bb44-3f7d81542fa4}") & MKDWD$(&H01)
MACRO MFPKEY_MediaSource_DisableReadAhead = GUID$("{26366c14-c5bf-4c76-887b-9f1754db5f09}") & MKDWD$(&H01)
'#endif // (WINVER >= _WIN32_WINNT_WIN7)

' enum _MFMEDIASOURCE_CHARACTERISTICS
%MFMEDIASOURCE_IS_LIVE                    = &H1
%MFMEDIASOURCE_CAN_SEEK                   = &H2
%MFMEDIASOURCE_CAN_PAUSE                  = &H4
%MFMEDIASOURCE_HAS_SLOW_SEEK              = &H8
%MFMEDIASOURCE_HAS_MULTIPLE_PRESENTATIONS = &H10
%MFMEDIASOURCE_CAN_SKIPFORWARD            = &H20
%MFMEDIASOURCE_CAN_SKIPBACKWARD           = &H40

'#if (WINVER >= _WIN32_WINNT_WIN7)
$MF_TIME_FORMAT_ENTRY_RELATIVE = GUID$("{4399f178-46d3-4504-afda-20d32e9ba360}")
'#endif // (WINVER >= _WIN32_WINNT_WIN7)

' ########################################################################################
' Interface name = IMFMediaSource
' IID = 279A808D-AEC7-40C8-9C6B-A6B492C78A66
' Inherited interface = IMFMediaEventGenerator
' ########################################################################################

#IF NOT %DEF(%IMFMediaSource_INTERFACE_DEFINED)
    %IMFMediaSource_INTERFACE_DEFINED = 1

$IID_IMFMediaSource = GUID$("{279A808D-AEC7-40C8-9C6B-A6B492C78A66}")

INTERFACE IMFMediaSource $IID_IMFMediaSource

   INHERIT IUnknown

   ' =====================================================================================
   ' IMFMediaEventGenerator methods
   ' =====================================================================================
   METHOD GetEvent ( _                                  ' VTable offset = 12
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF ppEvent AS IMFMediaEvent _                   ' __out IMFMediaEvent **ppEvent
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD BeginGetEvent ( _                             ' VTable offset = 16
     BYVAL pCallback AS IMFAsyncCallback _              ' __in IMFAsyncCallback *pCallback
   , BYVAL punkState AS IUnknown _                      ' __in IUnknown *punkState
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EndGetEvent ( _                               ' VTable offset = 20
     BYVAL pResult AS IMFAsyncResult _                  ' __in IMFAsyncResult *pResult
   , BYREF ppEvent AS IMFMediaEvent _                   ' __out IMFMediaEvent **ppEvent
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD QueueEvent ( _                                ' VTable offset = 24
     BYVAL met AS DWORD _                               ' __in MediaEventType met
   , BYREF guidExtendedType AS GUID _                   ' __in REFGUID guidExtendedType
   , BYVAL hrStatus AS LONG _                           ' __in HRESULT hrStatus
   , BYREF pvValue AS PROPVARIANT _                     ' __in const PROPVARIANT *pvValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IMFMediaSource methods
   ' =====================================================================================
   METHOD GetCharacteristics ( _                        ' VTable offset = 28
     BYREF pdwCharacteristics AS DWORD _                ' __out DWORD *pdwCharacteristics
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreatePresentationDescriptor ( _              ' VTable offset = 32
     BYREF ppPresentationDescriptor AS IMFPresentationDescriptor _ ' __out IMFPresentationDescriptor **ppPresentationDescriptor
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Start ( _                                     ' VTable offset = 36
     BYVAL pPresentationDescriptor AS IMFPresentationDescriptor _ ' __in IMFPresentationDescriptor *pPresentationDescriptor
   , BYREF pguidTimeFormat AS GUID _                    ' __in const GUID *pguidTimeFormat
   , BYREF pvarStartPosition AS PROPVARIANT _           ' __in const PROPVARIANT *pvarStartPosition
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Stop ( _                                      ' VTable offset = 40
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Pause ( _                                     ' VTable offset = 44
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Shutdown ( _                                  ' VTable offset = 48
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMFMediaSource_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IMFMediaStream
' IID = D182108F-4EC6-443F-AA42-A71106EC825F
' Inherited interface = IMFMediaEventGenerator
' ########################################################################################

#IF NOT %DEF(%IMFMediaStream_INTERFACE_DEFINED)
    %IMFMediaStream_INTERFACE_DEFINED = 1

$IID_IMFMediaStream = GUID$("{D182108F-4EC6-443F-AA42-A71106EC825F}")

INTERFACE IMFMediaStream $IID_IMFMediaStream

   INHERIT IUnknown

   ' =====================================================================================
   ' IMFMediaEventGenerator methods
   ' =====================================================================================
   METHOD GetEvent ( _                                  ' VTable offset = 12
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF ppEvent AS IMFMediaEvent _                   ' __out IMFMediaEvent **ppEvent
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD BeginGetEvent ( _                             ' VTable offset = 16
     BYVAL pCallback AS IMFAsyncCallback _              ' __in IMFAsyncCallback *pCallback
   , BYVAL punkState AS IUnknown _                      ' __in IUnknown *punkState
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EndGetEvent ( _                               ' VTable offset = 20
     BYVAL pResult AS IMFAsyncResult _                  ' __in IMFAsyncResult *pResult
   , BYREF ppEvent AS IMFMediaEvent _                   ' __out IMFMediaEvent **ppEvent
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD QueueEvent ( _                                ' VTable offset = 24
     BYVAL met AS DWORD _                               ' __in MediaEventType met
   , BYREF guidExtendedType AS GUID _                   ' __in REFGUID guidExtendedType
   , BYVAL hrStatus AS LONG _                           ' __in HRESULT hrStatus
   , BYREF pvValue AS PROPVARIANT _                     ' __in const PROPVARIANT *pvValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IMFMediaStream methods
   ' =====================================================================================
   METHOD GetMediaSource ( _                            ' VTable offset = 28
     BYREF ppMediaSource AS IMFMediaSource _            ' __out IMFMediaSource **ppMediaSource
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetStreamDescriptor ( _                       ' VTable offset = 32
     BYREF ppStreamDescriptor AS IMFStreamDescriptor _  ' __out IMFStreamDescriptor **ppStreamDescriptor
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RequestSample ( _                             ' VTable offset = 36
     BYVAL pToken AS IUnknown _                         ' __in IUnknown *pToken
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMFMediaStream_INTERFACE_DEFINED__ */


%MEDIASINK_FIXED_STREAMS               = &H00000001???
%MEDIASINK_CANNOT_MATCH_CLOCK          = &H00000002???
%MEDIASINK_RATELESS                    = &H00000004???
%MEDIASINK_CLOCK_REQUIRED              = &H00000008???
%MEDIASINK_CAN_PREROLL                 = &H00000010???
%MEDIASINK_REQUIRE_REFERENCE_MEDIATYPE = &H00000020???


' ########################################################################################
' Interface name = IMFMediaSink
' IID = 6EF2A660-47C0-4666-B13D-CBB717F2FA2C
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMFMediaSink_INTERFACE_DEFINED)
    %IMFMediaSink_INTERFACE_DEFINED = 1

$IID_IMFMediaSink = GUID$("{6EF2A660-47C0-4666-B13D-CBB717F2FA2C}")

INTERFACE IMFMediaSink $IID_IMFMediaSink

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetCharacteristics ( _                        ' VTable offset = 12
     BYREF pdwCharacteristics AS DWORD _                ' __out DWORD *pdwCharacteristics
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddStreamSink ( _                             ' VTable offset = 16
     BYVAL dwStreamSinkIdentifier AS DWORD _            ' __in DWORD dwStreamSinkIdentifier
   , BYVAL pMediaType AS IMFMediaType _                 ' __in IMFMediaType *pMediaType
   , BYREF ppStreamSink AS IMFStreamSink _              ' __out IMFStreamSink **ppStreamSink
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RemoveStreamSink ( _                          ' VTable offset = 20
     BYVAL dwStreamSinkIdentifier AS DWORD _            ' __in DWORD dwStreamSinkIdentifier
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetStreamSinkCount ( _                        ' VTable offset = 24
     BYREF pcStreamSinkCount AS DWORD _                 ' __out DWORD *pcStreamSinkCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetStreamSinkByIndex ( _                      ' VTable offset = 28
     BYVAL dwIndex AS DWORD _                           ' __in DWORD dwIndex
   , BYREF ppStreamSink AS IMFStreamSink _              ' __out IMFStreamSink **ppStreamSink
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetStreamSinkById ( _                         ' VTable offset = 32
     BYVAL dwStreamSinkIdentifier AS DWORD _            ' __in DWORD dwStreamSinkIdentifier
   , BYREF ppStreamSink AS IMFStreamSink _              ' __out IMFStreamSink **ppStreamSink
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPresentationClock ( _                      ' VTable offset = 36
     BYVAL pPresentationClock AS IMFPresentationClock _ ' __in IMFPresentationClock *pPresentationClock
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPresentationClock ( _                      ' VTable offset = 40
     BYREF ppPresentationClock AS IMFPresentationClock _ ' __out IMFPresentationClock **ppPresentationClock
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Shutdown ( _                                  ' VTable offset = 44
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMFMediaSink_INTERFACE_DEFINED__ */


' enum MFSTREAMSINK_MARKER_TYPE
%MFSTREAMSINK_MARKER_DEFAULT      = 0
%MFSTREAMSINK_MARKER_ENDOFSEGMENT = %MFSTREAMSINK_MARKER_DEFAULT      + 1
%MFSTREAMSINK_MARKER_TICK         = %MFSTREAMSINK_MARKER_ENDOFSEGMENT + 1
%MFSTREAMSINK_MARKER_EVENT        = %MFSTREAMSINK_MARKER_TICK         + 1


' ########################################################################################
' Interface name = IMFStreamSink
' IID = 0A97B3CF-8E7C-4A3D-8F8C-0C843DC247FB
' Inherited interface = IMFMediaEventGenerator
' ########################################################################################

#IF NOT %DEF(%IMFStreamSink_INTERFACE_DEFINED)
    %IMFStreamSink_INTERFACE_DEFINED = 1

$IID_IMFStreamSink = GUID$("{0A97B3CF-8E7C-4A3D-8F8C-0C843DC247FB}")

INTERFACE IMFStreamSink $IID_IMFStreamSink

   INHERIT IUnknown

   ' =====================================================================================
   ' IMFMediaEventGenerator methods
   ' =====================================================================================
   METHOD GetEvent ( _                                  ' VTable offset = 12
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF ppEvent AS IMFMediaEvent _                   ' __out IMFMediaEvent **ppEvent
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD BeginGetEvent ( _                             ' VTable offset = 16
     BYVAL pCallback AS IMFAsyncCallback _              ' __in IMFAsyncCallback *pCallback
   , BYVAL punkState AS IUnknown _                      ' __in IUnknown *punkState
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EndGetEvent ( _                               ' VTable offset = 20
     BYVAL pResult AS IMFAsyncResult _                  ' __in IMFAsyncResult *pResult
   , BYREF ppEvent AS IMFMediaEvent _                   ' __out IMFMediaEvent **ppEvent
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD QueueEvent ( _                                ' VTable offset = 24
     BYVAL met AS DWORD _                               ' __in MediaEventType met
   , BYREF guidExtendedType AS GUID _                   ' __in REFGUID guidExtendedType
   , BYVAL hrStatus AS LONG _                           ' __in HRESULT hrStatus
   , BYREF pvValue AS PROPVARIANT _                     ' __in const PROPVARIANT *pvValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IMFStreamSink methods
   ' =====================================================================================
   METHOD GetMediaSink ( _                              ' VTable offset = 28
     BYREF ppMediaSink AS IMFMediaSink _                ' __out IMFMediaSink **ppMediaSink
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetIdentifier ( _                             ' VTable offset = 32
     BYREF pdwIdentifier AS DWORD _                     ' __out DWORD *pdwIdentifier
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMediaTypeHandler ( _                       ' VTable offset = 36
     BYREF ppHandler AS IMFMediaTypeHandler _           ' __out IMFMediaTypeHandler **ppHandler
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ProcessSample ( _                             ' VTable offset = 40
     BYVAL pSample AS IMFSample _                       ' __in IMFSample *pSample
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD PlaceMarker ( _                               ' VTable offset = 44
     BYVAL eMarkerType AS LONG _                        ' __in MFSTREAMSINK_MARKER_TYPE eMarkerType
   , BYREF pvarMarkerValue AS PROPVARIANT _             ' __in const PROPVARIANT *pvarMarkerValue
   , BYREF pvarContextValue AS PROPVARIANT _            ' __in const PROPVARIANT *pvarContextValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Flush ( _                                     ' VTable offset = 48
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMFStreamSink_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IMFVideoSampleAllocator
' IID = 86CBC910-E533-4751-8E3B-F19B5B806A03
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMFVideoSampleAllocator_INTERFACE_DEFINED)
    %IMFVideoSampleAllocator_INTERFACE_DEFINED = 1

$IID_IMFVideoSampleAllocator = GUID$("{86CBC910-E533-4751-8E3B-F19B5B806A03}")

INTERFACE IMFVideoSampleAllocator $IID_IMFVideoSampleAllocator

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetDirectXManager ( _                         ' VTable offset = 12
     BYVAL pManager AS IUnknown _                       ' __in IUnknown *pManager
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UninitializeSampleAllocator ( _               ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD InitializeSampleAllocator ( _                 ' VTable offset = 20
     BYVAL cRequestedFrames AS DWORD _                  ' __in DWORD cRequestedFrames
   , BYVAL pMediaType AS IMFMediaType _                 ' __in IMFMediaType *pMediaType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AllocateSample ( _                            ' VTable offset = 24
     BYREF ppSample AS IMFSample _                      ' __out IMFSample **ppSample
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMFVideoSampleAllocator_INTERFACE_DEFINED__ */

'#if (WINVER >= _WIN32_WINNT_WIN7)

' ########################################################################################
' Interface name = IMFVideoSampleAllocatorNotify
' IID = A792CDBE-C374-4e89-8335-278E7B9956A
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMFVideoSampleAllocatorNotify_INTERFACE_DEFINED)
    %IMFVideoSampleAllocatorNotify_INTERFACE_DEFINED = 1

$IID_IMFVideoSampleAllocatorNotify = GUID$("{A792CDBE-C374-4e89-8335-278E7B9956A4}")

INTERFACE IMFVideoSampleAllocatorNotify $IID_IMFVideoSampleAllocatorNotify

   INHERIT IUnknown

   ' =====================================================================================
   METHOD NotifyRelease ( _                             ' VTable offset = 12
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMFVideoSampleAllocatorNotify_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IMFVideoSampleAllocatorCallback
' IID = 992388B4-3372-4f67-8B6F-C84C071F4751
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMFVideoSampleAllocatorCallback_INTERFACE_DEFINED)
    %IMFVideoSampleAllocatorCallback_INTERFACE_DEFINED = 1

$IID_IMFVideoSampleAllocatorCallback = GUID$("{992388B4-3372-4f67-8B6F-C84C071F4751}")

INTERFACE IMFVideoSampleAllocatorCallback $IID_IMFVideoSampleAllocatorCallback

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetCallback ( _                               ' VTable offset = 12
     BYVAL pNotify AS IMFVideoSampleAllocatorNotify _   ' __in IMFVideoSampleAllocatorNotify *pNotify
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFreeSampleCount ( _                        ' VTable offset = 16
     BYREF plSamples AS DWORD _                         ' __out LONG *plSamples
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMFVideoSampleAllocatorCallback_INTERFACE_DEFINED__ */

'#endif // (WINVER >= _WIN32_WINNT_WIN7)

' ########################################################################################
' Interface name = IMFTopology
' IID = 83CF873A-F6DA-4BC8-823F-BACFD55DC433
' Inherited interface = IMFAttributes
' ########################################################################################

#IF NOT %DEF(%IMFTopology_INTERFACE_DEFINED)
    %IMFTopology_INTERFACE_DEFINED = 1

$IID_IMFTopology = GUID$("{83CF873A-F6DA-4BC8-823F-BACFD55DC433}")

INTERFACE IMFTopology $IID_IMFTopology

   INHERIT IUnknown

   ' =====================================================================================
   ' IMFAttributes methods
   ' =====================================================================================
   METHOD GetItem ( _                                   ' VTable offset = 12
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF pValue AS PROPVARIANT _                      ' __in_out PROPVARIANT *pValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetItemType ( _                               ' VTable offset = 16
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF pType AS LONG _                              ' __out MF_ATTRIBUTE_TYPE *pType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CompareItem ( _                               ' VTable offset = 20
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF Value AS PROPVARIANT _                       ' __in REFPROPVARIANT Value
   , BYREF pbResult AS LONG _                           ' __out BOOL *pbResult
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Compare ( _                                   ' VTable offset = 24
     BYVAL pTheirs AS IMFAttributes _                   ' __in IMFAttributes *pTheirs
   , BYVAL MatchType AS LONG _                          ' __in MF_ATTRIBUTES_MATCH_TYPE MatchType
   , BYREF pbResult AS LONG _                           ' __out BOOL *pbResult
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetUINT32 ( _                                 ' VTable offset = 28
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF punValue AS DWORD _                          ' __out UINT32 *punValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetUINT64 ( _                                 ' VTable offset = 32
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF punValue AS QUAD _                           ' __out UINT64 *punValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDouble ( _                                 ' VTable offset = 36
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF pfValue AS DOUBLE _                          ' __out double *pfValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetGUID ( _                                   ' VTable offset = 40
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF pguidValue AS GUID _                         ' __out GUID *pguidValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetStringLength ( _                           ' VTable offset = 44
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF pcchLength AS DWORD _                        ' __out UINT32 *pcchLength
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetString ( _                                 ' VTable offset = 48
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF pwszValue AS WSTRINGZ _                      ' __out LPWSTR pwszValue
   , BYVAL cchBufSize AS DWORD _                        ' __in UINT32 cchBufSize
   , BYREF pcchLength AS DWORD _                        ' __in_out UINT32 *pcchLength
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAllocatedString ( _                        ' VTable offset = 52
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF ppwszValue AS DWORD _                        ' __out LPWSTR *ppwszValue
   , BYREF pcchLength AS DWORD _                        ' __out UINT32 *pcchLength
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetBlobSize ( _                               ' VTable offset = 56
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF pcbBlobSize AS DWORD _                       ' __out UINT32 *pcbBlobSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetBlob ( _                                   ' VTable offset = 60
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYVAL pBuf AS DWORD _                              ' __out UINT8 *pBuf
   , BYVAL cbBufSize AS DWORD _                         ' __in UINT32 cbBufSize
   , BYREF pcbBlobSize AS DWORD _                       ' __in_out UINT32 *pcbBlobSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAllocatedBlob ( _                          ' VTable offset = 64
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYVAL ppBuf AS DWORD _                             ' __out UINT8 **ppBuf
   , BYREF pcbSize AS DWORD _                           ' __out UINT32 *pcbSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetUnknown ( _                                ' VTable offset = 68
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppv AS IUnknown _                            ' __out LPVOID *ppv
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetItem ( _                                   ' VTable offset = 72
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF Value AS PROPVARIANT _                       ' __out REFPROPVARIANT Value
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DeleteItem ( _                                ' VTable offset = 76
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DeleteAllItems ( _                            ' VTable offset = 80
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetUINT32 ( _                                 ' VTable offset = 84
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYVAL unValue AS DWORD _                           ' __in UINT32 unValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetUINT64 ( _                                 ' VTable offset = 88
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYVAL unValue AS QUAD _                            ' __in UINT64 unValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetDouble ( _                                 ' VTable offset = 92
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYVAL fValue AS DOUBLE _                           ' __in double fValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetGUID ( _                                   ' VTable offset = 96
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF guidValue AS GUID _                          ' __in REFGUID guidValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetString ( _                                 ' VTable offset = 100
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF wszValue AS WSTRINGZ _                       ' __in LPCWSTR wszValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetBlob ( _                                   ' VTable offset = 104
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYVAL pBuf AS DWORD _                              ' __in  const UINT8 *pBuf
   , BYVAL cbBufSize AS DWORD _                         ' __in UINT32 cbBufSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetUnknown ( _                                ' VTable offset = 108
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYVAL pUnknown AS IUnknown _                       ' __in IUnknown *pUnknown
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD LockStore ( _                                 ' VTable offset = 112
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UnlockStore ( _                               ' VTable offset = 116
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCount ( _                                  ' VTable offset = 120
     BYREF pcItems AS DWORD _                           ' __out UINT32 *pcItems
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetItemByIndex ( _                            ' VTable offset = 124
     BYVAL unIndex AS DWORD _                           ' __in UINT32 unIndex
   , BYREF pguidKey AS GUID _                           ' __out GUID *pguidKey
   , BYREF pValue AS PROPVARIANT _                      ' __in_out PROPVARIANT *pValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CopyAllItems ( _                              ' VTable offset = 128
     BYVAL pDest AS LONG _                              ' __in IMFAttributes *pDest
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IMFTopology methods
   ' =====================================================================================
   METHOD GetTopologyID ( _                             ' VTable offset = 132
     BYREF pID AS QUAD _                                ' __out TOPOID *pID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddNode ( _                                   ' VTable offset = 136
     BYVAL pNode AS IMFTopologyNode _                   ' __in IMFTopologyNode *pNode
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RemoveNode ( _                                ' VTable offset = 140
     BYVAL pNode AS IMFTopologyNode _                   ' __in IMFTopologyNode *pNode
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetNodeCount ( _                              ' VTable offset = 144
     BYREF pwNodes AS WORD _                            ' __out WORD *pwNodes
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetNode ( _                                   ' VTable offset = 148
     BYVAL wIndex AS WORD _                             ' __in WORD wIndex
   , BYREF ppNode AS IMFTopologyNode _                  ' __out IMFTopologyNode **ppNode
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clear ( _                                     ' VTable offset = 152
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CloneFrom ( _                                 ' VTable offset = 156
     BYVAL pTopology AS IMFTopology _                   ' __in IMFTopology *pTopology
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetNodeByID ( _                               ' VTable offset = 160
     BYVAL qwTopoNodeID AS QUAD _                       ' __in TOPOID qwTopoNodeID
   , BYREF ppNode AS IMFTopologyNode _                  ' __out IMFTopologyNode **ppNode
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSourceNodeCollection ( _                   ' VTable offset = 164
     BYREF ppCollection AS IMFCollection _              ' __out IMFCollection **ppCollection
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetOutputNodeCollection ( _                   ' VTable offset = 168
     BYREF ppCollection AS IMFCollection _              ' __out IMFCollection **ppCollection
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMFTopology_INTERFACE_DEFINED__ */


$MF_TOPOLOGY_PROJECTSTART      = GUID$("{7ED3F802-86BB-4B3F-B7E4-7CB43AFD4B80}")
$MF_TOPOLOGY_PROJECTSTOP       = GUID$("{7ED3F803-86BB-4B3F-B7E4-7CB43AFD4B80}")
$MF_TOPOLOGY_NO_MARKIN_MARKOUT = GUID$("{7ED3F804-86BB-4B3F-B7E4-7CB43AFD4B80}")

'#if (WINVER >= _WIN32_WINNT_WIN7)
' enum MFTOPOLOGY_DXVA_MODE
%MFTOPOLOGY_DXVA_DEFAULT = 0
%MFTOPOLOGY_DXVA_NONE    = 1
%MFTOPOLOGY_DXVA_FULL    = 2

$MF_TOPOLOGY_DXVA_MODE = GUID$("{1e8d34f6-f5ab-4e23-bb88-874aa3a1a74d}")
$MF_TOPOLOGY_STATIC_PLAYBACK_OPTIMIZATIONS = GUID$("{b86cac42-41a6-4b79-897a-1ab0e52b4a1b}")
$MF_TOPOLOGY_PLAYBACK_MAX_DIMS = GUID$("{5715cf19-5768-44aa-ad6e-8721f1b0f9bb}")

' enum MFTOPOLOGY_HARDWARE_MODE
%MFTOPOLOGY_HWMODE_SOFTWARE_ONLY = 0
%MFTOPOLOGY_HWMODE_USE_HARDWARE  = 1

$MF_TOPOLOGY_HARDWARE_MODE = GUID$("{d2d362fd-4e4f-4191-a579-c618b66706af}")
$MF_TOPOLOGY_PLAYBACK_FRAMERATE = GUID$("{c164737a-c2b1-4553-83bb-5a526072448f}")
$MF_TOPOLOGY_DYNAMIC_CHANGE_NOT_ALLOWED = GUID$("{d529950b-d484-4527-a9cd-b1909532b5b0}")
$MF_TOPOLOGY_ENUMERATE_SOURCE_TYPES = GUID$("{6248c36d-5d0b-4f40-a0bb-b0b305f77698}")
$MF_TOPOLOGY_START_TIME_ON_PRESENTATION_SWITCH = GUID$("{c8cc113f-7951-4548-aad6-9ed6202e62b3}")
'#endif // (WINVER >= _WIN32_WINNT_WIN7)

DECLARE FUNCTION MFCreateTopology IMPORT "mf.dll" ALIAS "MFCreateTopology" ( _
   BYREF ppTopo AS IMFTopology _                        ' __out IMFTopology ** ppTopo
 ) AS LONG                                              ' HRESULT

' enum MF_TOPOLOGY_TYPE
%MF_TOPOLOGY_OUTPUT_NODE       = 0???
%MF_TOPOLOGY_SOURCESTREAM_NODE = %MF_TOPOLOGY_OUTPUT_NODE       + 1
%MF_TOPOLOGY_TRANSFORM_NODE    = %MF_TOPOLOGY_SOURCESTREAM_NODE + 1
%MF_TOPOLOGY_TEE_NODE          = %MF_TOPOLOGY_TRANSFORM_NODE    + 1
%MF_TOPOLOGY_MAX               = &Hffffffff???


' ########################################################################################
' Interface name = IMFTopologyNode
' IID = 83CF873A-F6DA-4BC8-823F-BACFD55DC430
' Inherited interface = IMFAttributes
' ########################################################################################

#IF NOT %DEF(%IMFTopologyNode_INTERFACE_DEFINED)
    %IMFTopologyNode_INTERFACE_DEFINED = 1

$IID_IMFTopologyNode = GUID$("{83CF873A-F6DA-4BC8-823F-BACFD55DC430}")

INTERFACE IMFTopologyNode $IID_IMFTopologyNode

   INHERIT IUnknown

   ' =====================================================================================
   ' IMFAttributes methods
   ' =====================================================================================
   METHOD GetItem ( _                                   ' VTable offset = 12
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF pValue AS PROPVARIANT _                      ' __in_out PROPVARIANT *pValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetItemType ( _                               ' VTable offset = 16
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF pType AS LONG _                              ' __out MF_ATTRIBUTE_TYPE *pType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CompareItem ( _                               ' VTable offset = 20
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF Value AS PROPVARIANT _                       ' __in REFPROPVARIANT Value
   , BYREF pbResult AS LONG _                           ' __out BOOL *pbResult
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Compare ( _                                   ' VTable offset = 24
     BYVAL pTheirs AS IMFAttributes _                   ' __in IMFAttributes *pTheirs
   , BYVAL MatchType AS LONG _                          ' __in MF_ATTRIBUTES_MATCH_TYPE MatchType
   , BYREF pbResult AS LONG _                           ' __out BOOL *pbResult
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetUINT32 ( _                                 ' VTable offset = 28
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF punValue AS DWORD _                          ' __out UINT32 *punValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetUINT64 ( _                                 ' VTable offset = 32
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF punValue AS QUAD _                           ' __out UINT64 *punValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDouble ( _                                 ' VTable offset = 36
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF pfValue AS DOUBLE _                          ' __out double *pfValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetGUID ( _                                   ' VTable offset = 40
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF pguidValue AS GUID _                         ' __out GUID *pguidValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetStringLength ( _                           ' VTable offset = 44
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF pcchLength AS DWORD _                        ' __out UINT32 *pcchLength
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetString ( _                                 ' VTable offset = 48
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF pwszValue AS WSTRINGZ _                      ' __out LPWSTR pwszValue
   , BYVAL cchBufSize AS DWORD _                        ' __in UINT32 cchBufSize
   , BYREF pcchLength AS DWORD _                        ' __in_out UINT32 *pcchLength
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAllocatedString ( _                        ' VTable offset = 52
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF ppwszValue AS DWORD _                        ' __out LPWSTR *ppwszValue
   , BYREF pcchLength AS DWORD _                        ' __out UINT32 *pcchLength
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetBlobSize ( _                               ' VTable offset = 56
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF pcbBlobSize AS DWORD _                       ' __out UINT32 *pcbBlobSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetBlob ( _                                   ' VTable offset = 60
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYVAL pBuf AS DWORD _                              ' __out UINT8 *pBuf
   , BYVAL cbBufSize AS DWORD _                         ' __in UINT32 cbBufSize
   , BYREF pcbBlobSize AS DWORD _                       ' __in_out UINT32 *pcbBlobSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAllocatedBlob ( _                          ' VTable offset = 64
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYVAL ppBuf AS DWORD _                             ' __out UINT8 **ppBuf
   , BYREF pcbSize AS DWORD _                           ' __out UINT32 *pcbSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetUnknown ( _                                ' VTable offset = 68
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppv AS IUnknown _                            ' __out LPVOID *ppv
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetItem ( _                                   ' VTable offset = 72
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF Value AS PROPVARIANT _                       ' __out REFPROPVARIANT Value
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DeleteItem ( _                                ' VTable offset = 76
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DeleteAllItems ( _                            ' VTable offset = 80
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetUINT32 ( _                                 ' VTable offset = 84
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYVAL unValue AS DWORD _                           ' __in UINT32 unValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetUINT64 ( _                                 ' VTable offset = 88
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYVAL unValue AS QUAD _                            ' __in UINT64 unValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetDouble ( _                                 ' VTable offset = 92
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYVAL fValue AS DOUBLE _                           ' __in double fValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetGUID ( _                                   ' VTable offset = 96
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF guidValue AS GUID _                          ' __in REFGUID guidValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetString ( _                                 ' VTable offset = 100
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF wszValue AS WSTRINGZ _                       ' __in LPCWSTR wszValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetBlob ( _                                   ' VTable offset = 104
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYVAL pBuf AS DWORD _                              ' __in  const UINT8 *pBuf
   , BYVAL cbBufSize AS DWORD _                         ' __in UINT32 cbBufSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetUnknown ( _                                ' VTable offset = 108
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYVAL pUnknown AS IUnknown _                       ' __in IUnknown *pUnknown
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD LockStore ( _                                 ' VTable offset = 112
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UnlockStore ( _                               ' VTable offset = 116
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCount ( _                                  ' VTable offset = 120
     BYREF pcItems AS DWORD _                           ' __out UINT32 *pcItems
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetItemByIndex ( _                            ' VTable offset = 124
     BYVAL unIndex AS DWORD _                           ' __in UINT32 unIndex
   , BYREF pguidKey AS GUID _                           ' __out GUID *pguidKey
   , BYREF pValue AS PROPVARIANT _                      ' __in_out PROPVARIANT *pValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CopyAllItems ( _                              ' VTable offset = 128
     BYVAL pDest AS LONG _                              ' __in IMFAttributes *pDest
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IMFTopologyNode methods
   ' =====================================================================================
   METHOD SetObject ( _                                 ' VTable offset = 132
     BYVAL pObject AS IUnknown _                        ' __in IUnknown *pObject
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetObject ( _                                 ' VTable offset = 136
     BYREF ppObject AS IUnknown _                       ' __out IUnknown **ppObject
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetNodeType ( _                               ' VTable offset = 140
     BYREF pType AS LONG _                              ' __out MF_TOPOLOGY_TYPE *pType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTopoNodeID ( _                             ' VTable offset = 144
     BYREF pID AS QUAD _                                ' __out TOPOID *pID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetTopoNodeID ( _                             ' VTable offset = 148
     BYVAL ullTopoID AS QUAD _                          ' __in TOPOID ullTopoID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetInputCount ( _                             ' VTable offset = 152
     BYREF pcInputs AS DWORD _                          ' __out DWORD *pcInputs
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetOutputCount ( _                            ' VTable offset = 156
     BYREF pcOutputs AS DWORD _                         ' __out DWORD *pcOutputs
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ConnectOutput ( _                             ' VTable offset = 160
     BYVAL dwOutputIndex AS DWORD _                     ' __in DWORD dwOutputIndex
   , BYVAL pDownstreamNode AS IMFTopologyNode _         ' __in IMFTopologyNode *pDownstreamNode
   , BYVAL dwInputIndexOnDownstreamNode AS DWORD _      ' __in DWORD dwInputIndexOnDownstreamNode
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DisconnectOutput ( _                          ' VTable offset = 164
     BYVAL dwOutputIndex AS DWORD _                     ' __in DWORD dwOutputIndex
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetInput ( _                                  ' VTable offset = 168
     BYVAL dwInputIndex AS DWORD _                      ' __in DWORD dwInputIndex
   , BYREF ppUpstreamNode AS IMFTopologyNode _          ' __out IMFTopologyNode **ppUpstreamNode
   , BYREF pdwOutputIndexOnUpstreamNode AS DWORD _      ' __out DWORD *pdwOutputIndexOnUpstreamNode
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetOutput ( _                                 ' VTable offset = 172
     BYVAL dwOutputIndex AS DWORD _                     ' __in DWORD dwOutputIndex
   , BYREF ppDownstreamNode AS IMFTopologyNode _        ' __out IMFTopologyNode **ppDownstreamNode
   , BYREF pdwInputIndexOnDownstreamNode AS DWORD _     ' __out DWORD *pdwInputIndexOnDownstreamNode
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetOutputPrefType ( _                         ' VTable offset = 176
     BYVAL dwOutputIndex AS DWORD _                     ' __in DWORD dwOutputIndex
   , BYVAL pType AS IMFMediaType _                      ' __in IMFMediaType *pType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetOutputPrefType ( _                         ' VTable offset = 180
     BYVAL dwOutputIndex AS DWORD _                     ' __in DWORD dwOutputIndex
   , BYREF ppType AS IMFMediaType _                     ' __out IMFMediaType **ppType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetInputPrefType ( _                          ' VTable offset = 184
     BYVAL dwInputIndex AS DWORD _                      ' __in DWORD dwInputIndex
   , BYVAL pType AS IMFMediaType _                      ' __in IMFMediaType *pType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetInputPrefType ( _                          ' VTable offset = 188
     BYVAL dwInputIndex AS DWORD _                      ' __in DWORD dwInputIndex
   , BYREF ppType AS IMFMediaType _                     ' __out IMFMediaType **ppType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CloneFrom ( _                                 ' VTable offset = 192
     BYVAL pNode AS IMFTopologyNode _                   ' __in IMFTopologyNode *pNode
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMFTopologyNode_INTERFACE_DEFINED__ */


' enum MF_TOPONODE_FLUSH_MODE
%MF_TOPONODE_FLUSH_ALWAYS = 0
%MF_TOPONODE_FLUSH_SEEK   = %MF_TOPONODE_FLUSH_ALWAYS + 1
%MF_TOPONODE_FLUSH_NEVER  = %MF_TOPONODE_FLUSH_SEEK   + 1

$MF_TOPONODE_FLUSH = GUID$("{494BBCE8-B031-4E38-97C4-D5422DD618DC}")

' enum MF_TOPONODE_DRAIN_MODE
%MF_TOPONODE_DRAIN_DEFAULT = 0
%MF_TOPONODE_DRAIN_ALWAYS  = %MF_TOPONODE_DRAIN_DEFAULT + 1
%MF_TOPONODE_DRAIN_NEVER   = %MF_TOPONODE_DRAIN_ALWAYS  + 1

$MF_TOPONODE_DRAIN = GUID$("{494BBCE9-B031-4E38-97C4-D5422DD618DC}")
$MF_TOPONODE_D3DAWARE = GUID$("{494BBCED-B031-4E38-97C4-D5422DD618DC}")
$MF_TOPOLOGY_RESOLUTION_STATUS = GUID$("{494BBCDE-B031-4E38-97C4-D5422DD618DC}")
$MF_TOPONODE_ERRORCODE = GUID$("{494BBCEE-B031-4E38-97C4-D5422DD618DC}")
$MF_TOPONODE_CONNECT_METHOD = GUID$("{494BBCF1-B031-4E38-97C4-D5422DD618DC}")
$MF_TOPONODE_LOCKED = GUID$("{494BBCF7-B031-4E38-97C4-D5422DD618DC}")
$MF_TOPONODE_WORKQUEUE_ID = GUID$("{494BBCF8-B031-4E38-97C4-D5422DD618DC}")
$MF_TOPONODE_WORKQUEUE_MMCSS_CLASS = GUID$("{494BBCF9-B031-4E38-97C4-D5422DD618DC}")
$MF_TOPONODE_DECRYPTOR = GUID$("{494BBCFA-B031-4E38-97C4-D5422DD618DC}")
$MF_TOPONODE_DISCARDABLE = GUID$("{494BBCFB-B031-4E38-97C4-D5422DD618DC}")
$MF_TOPONODE_ERROR_MAJORTYPE = GUID$("{494BBCFD-B031-4E38-97C4-D5422DD618DC}")
$MF_TOPONODE_ERROR_SUBTYPE = GUID$("{494BBCFE-B031-4E38-97C4-D5422DD618DC}")
$MF_TOPONODE_WORKQUEUE_MMCSS_TASKID = GUID$("{494BBCFF-B031-4E38-97C4-D5422DD618DC}")
$MF_TOPONODE_MARKIN_HERE = GUID$("{494BBD00-B031-4E38-97C4-D5422DD618DC}")
$MF_TOPONODE_MARKOUT_HERE = GUID$("{494BBD01-B031-4E38-97C4-D5422DD618DC}")
$MF_TOPONODE_DECODER = GUID$("{494BBD02-B031-4E38-97C4-D5422DD618DC}")
$MF_TOPONODE_MEDIASTART = GUID$("{835C58EA-E075-4BC7-BCBA-4DE000DF9AE6}")
$MF_TOPONODE_MEDIASTOP = GUID$("{835C58EB-E075-4BC7-BCBA-4DE000DF9AE6}")
$MF_TOPONODE_SOURCE = GUID$("{835C58EC-E075-4BC7-BCBA-4DE000DF9AE6}")
$MF_TOPONODE_PRESENTATION_DESCRIPTOR = GUID$("{835C58ED-E075-4BC7-BCBA-4DE000DF9AE6}")
$MF_TOPONODE_STREAM_DESCRIPTOR = GUID$("{835C58EE-E075-4BC7-BCBA-4DE000DF9AE6}")
$MF_TOPONODE_SEQUENCE_ELEMENTID = GUID$("{835C58EF-E075-4BC7-BCBA-4DE000DF9AE6}")
$MF_TOPONODE_TRANSFORM_OBJECTID = GUID$("{88DCC0C9-293E-4E8B-9AEB-0AD64CC016B0}")
$MF_TOPONODE_STREAMID = GUID$("{14932F9B-9087-4BB4-8412-5167145CBE04}")
$MF_TOPONODE_NOSHUTDOWN_ON_REMOVE = GUID$("{14932F9C-9087-4BB4-8412-5167145CBE04}")
$MF_TOPONODE_RATELESS = GUID$("{14932F9D-9087-4BB4-8412-5167145CBE04}")
$MF_TOPONODE_DISABLE_PREROLL = GUID$("{14932F9E-9087-4BB4-8412-5167145CBE04}")
$MF_TOPONODE_PRIMARYOUTPUT = GUID$("{6304EF99-16B2-4EBE-9D67-E4C539B3A259}")

DECLARE FUNCTION MFCreateTopologyNode IMPORT "mf.dll" ALIAS "MFCreateTopologyNode" ( _
   BYVAL NodeType AS LONG _                             ' __in  MF_TOPOLOGY_TYPE NodeType
 , BYREF ppNode AS IMFTopologyNode _                    ' __out IMFTopologyNode ** ppNode
 ) AS LONG                                              ' HRESULT

'#if (WINVER >= _WIN32_WINNT_WIN7)
DECLARE FUNCTION MFGetTopoNodeCurrentType IMPORT "mf.dll" ALIAS "MFGetTopoNodeCurrentType" ( _
   BYVAL pNode AS IMFTopologyNode _                     ' __in IMFTopologyNode* pNode
 , BYVAL dwStreamIndex AS DWORD _                       ' __in DWORD dwStreamIndex
 , BYVAL fOutput AS LONG _                              ' __in BOOL fOutput
 , BYREF ppType AS IMFMediaType _                       ' __out IMFMediaType** ppType
 ) AS LONG                                              ' HRESULT
'#endif // (WINVER >= _WIN32_WINNT_WIN7)

' ########################################################################################
' Interface name = IMFGetService
' IID = FA993888-4383-415A-A930-DD472A8CF6F7
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMFGetService_INTERFACE_DEFINED)
    %IMFGetService_INTERFACE_DEFINED = 1

$IID_IMFGetService = GUID$("{FA993888-4383-415A-A930-DD472A8CF6F7}")

INTERFACE IMFGetService $IID_IMFGetService

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetItem ( _                                   ' VTable offset = 12
     BYREF guidService AS GUID _                        ' __in REFGUID guidService
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppvObject AS IUnknown _                      ' __out LPVOID *ppvObject
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMFGetService_INTERFACE_DEFINED__ */


DECLARE FUNCTION MFGetService IMPORT "mf.dll" ALIAS "MFGetService" ( _
   BYVAL punkObject AS IUnknown _                       ' __in  IUnknown* punkObject
 , BYREF guidService AS GUID _                          ' __in  REFGUID guidService
 , BYREF riid AS GUID _                                 ' __in  REFIID riid
 , BYREF ppvObject AS IUnknown _                        ' __out LPVOID* ppvObject
 ) AS LONG                                              ' HRESULT

'typedef LONGLONG MFTIME;

' enum MFCLOCK_CHARACTERISTICS_FLAGS
%MFCLOCK_CHARACTERISTICS_FLAG_FREQUENCY_10MHZ = &H2
%MFCLOCK_CHARACTERISTICS_FLAG_ALWAYS_RUNNING  = &H4
%MFCLOCK_CHARACTERISTICS_FLAG_IS_SYSTEM_CLOCK = &H8

' enum MFCLOCK_STATE
%MFCLOCK_STATE_INVALID = 0
%MFCLOCK_STATE_RUNNING = %MFCLOCK_STATE_INVALID + 1
%MFCLOCK_STATE_STOPPED = %MFCLOCK_STATE_RUNNING + 1
%MFCLOCK_STATE_PAUSED  = %MFCLOCK_STATE_STOPPED + 1

' enum MFCLOCK_RELATIONAL_FLAGS
%MFCLOCK_RELATIONAL_FLAG_JITTER_NEVER_AHEAD = &H1

' // Size = 48 bytes
TYPE MFCLOCK_PROPERTIES QWORD FILL
   qwCorrelationRate AS QUAD    ' unsigned __int64
   guidClockId       AS GUID    ' GUID
   dwClockFlags      AS DWORD   ' DWORD
   qwClockFrequency  AS QUAD    ' unsigned __int64
   dwClockTolerance  AS DWORD   ' DWORD
   dwClockJitter     AS DWORD   ' DWORD
END TYPE

%MFCLOCK_FREQUENCY_HNS     = 10000000
%MFCLOCK_TOLERANCE_UNKNOWN = 50000
%MFCLOCK_JITTER_ISR        = 1000
%MFCLOCK_JITTER_DPC        = 4000
%MFCLOCK_JITTER_PASSIVE    = 10000


' ########################################################################################
' Interface name = IMFClock
' IID = 2EB1E945-18B8-4139-9B1A-D5D584818530
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMFClock_INTERFACE_DEFINED)
    %IMFClock_INTERFACE_DEFINED = 1

$IID_IMFClock = GUID$("{2EB1E945-18B8-4139-9B1A-D5D584818530}")

INTERFACE IMFClock $IID_IMFClock

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetClockCharacteristics ( _                   ' VTable offset = 12
     BYREF pdwCharacteristics AS DWORD _                ' __out DWORD *pdwCharacteristics
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCorrelatedTime ( _                         ' VTable offset = 16
     BYVAL dwReserved AS DWORD _                        ' __in DWORD dwReserved
   , BYREF pllClockTime AS QUAD _                       ' __out LONGLONG *pllClockTime
   , BYREF phnsSystemTime AS QUAD _                     ' __out MFTIME *phnsSystemTime
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetContinuityKey ( _                          ' VTable offset = 20
     BYREF pdwContinuityKey AS DWORD _                  ' __out DWORD *pdwContinuityKey
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetState ( _                                  ' VTable offset = 24
     BYVAL dwReserved AS DWORD _                        ' __in DWORD dwReserved
   , BYREF peClockState AS LONG _                       ' __out MFCLOCK_STATE *peClockState
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetProperties ( _                             ' VTable offset = 28
     BYREF pClockProperties AS MFCLOCK_PROPERTIES _     ' __out MFCLOCK_PROPERTIES *pClockProperties
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMFClock_INTERFACE_DEFINED__ */


DECLARE FUNCTION MFGetSystemTime IMPORT "mfplat.dll" ALIAS "MFGetSystemTime" ( _
 ) AS QUAD                                              ' MFTIME

%PRESENTATION_CURRENT_POSITION = &H7fffffffffffffff&&

' ########################################################################################
' Interface name = IMFPresentationClock
' IID = 868CE85C-8EA9-4F55-AB82-B009A910A805
' Inherited interface = IMFClock
' ########################################################################################

#IF NOT %DEF(%IMFPresentationClock_INTERFACE_DEFINED)
    %IMFPresentationClock_INTERFACE_DEFINED = 1

$IID_IMFPresentationClock = GUID$("{868CE85C-8EA9-4F55-AB82-B009A910A805}")

INTERFACE IMFPresentationClock $IID_IMFPresentationClock

   INHERIT IUnknown

   ' =====================================================================================
   ' IMFClock methods
   ' =====================================================================================
   METHOD GetClockCharacteristics ( _                   ' VTable offset = 12
     BYREF pdwCharacteristics AS DWORD _                ' __out DWORD *pdwCharacteristics
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCorrelatedTime ( _                         ' VTable offset = 16
     BYVAL dwReserved AS DWORD _                        ' __in DWORD dwReserved
   , BYREF pllClockTime AS QUAD _                       ' __out LONGLONG *pllClockTime
   , BYREF phnsSystemTime AS QUAD _                     ' __out MFTIME *phnsSystemTime
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetContinuityKey ( _                          ' VTable offset = 20
     BYREF pdwContinuityKey AS DWORD _                  ' __out DWORD *pdwContinuityKey
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetState ( _                                  ' VTable offset = 24
     BYVAL dwReserved AS DWORD _                        ' __in DWORD dwReserved
   , BYREF peClockState AS LONG _                       ' __out MFCLOCK_STATE *peClockState
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetProperties ( _                             ' VTable offset = 28
     BYREF pClockProperties AS MFCLOCK_PROPERTIES _     ' __out MFCLOCK_PROPERTIES *pClockProperties
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IMFPresentationClock methods
   ' =====================================================================================
   METHOD SetTimeSource ( _                             ' VTable offset = 32
     BYVAL pTimeSource AS IMFPresentationTimeSource _   ' __in IMFPresentationTimeSource *pTimeSource
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTimeSource ( _                             ' VTable offset = 36
     BYREF ppTimeSource AS IMFPresentationTimeSource _  ' __out IMFPresentationTimeSource **ppTimeSource
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTime ( _                                   ' VTable offset = 40
     BYREF phnsClockTime AS QUAD _                      ' __out MFTIME *phnsClockTime
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddClockStateSink ( _                         ' VTable offset = 44
     BYVAL pStateSink AS IMFClockStateSink _            ' __in IMFClockStateSink *pStateSink
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RemoveClockStateSink ( _                      ' VTable offset = 48
     BYVAL pStateSink AS IMFClockStateSink _            ' __in IMFClockStateSink *pStateSink
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Start ( _                                     ' VTable offset = 52
     BYVAL llClockStartOffset AS QUAD _                 ' __in LONGLONG llClockStartOffset
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Stop ( _                                      ' VTable offset = 56
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Pause ( _                                     ' VTable offset = 60
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMFPresentationClock_INTERFACE_DEFINED__ */


DECLARE FUNCTION MFCreatePresentationClock IMPORT "mf.dll" ALIAS "MFCreatePresentationClock" ( _
   BYREF ppPresentationClock AS IMFPresentationClock _  ' __out IMFPresentationClock** ppPresentationClock
 ) AS LONG                                              ' HRESULT


' ########################################################################################
' Interface name = IMFPresentationTimeSource
' IID = 7FF12CCE-F76F-41C2-863B-1666C8E5E139
' Inherited interface = IMFClock
' ########################################################################################

#IF NOT %DEF(%IMFPresentationTimeSource_INTERFACE_DEFINED)
    %IMFPresentationTimeSource_INTERFACE_DEFINED = 1

$IID_IMFPresentationTimeSource = GUID$("{7FF12CCE-F76F-41C2-863B-1666C8E5E139}")

INTERFACE IMFPresentationTimeSource $IID_IMFPresentationTimeSource

   INHERIT IUnknown

   ' =====================================================================================
   ' IMFClock methods
   ' =====================================================================================
   METHOD GetClockCharacteristics ( _                   ' VTable offset = 12
     BYREF pdwCharacteristics AS DWORD _                ' __out DWORD *pdwCharacteristics
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCorrelatedTime ( _                         ' VTable offset = 16
     BYVAL dwReserved AS DWORD _                        ' __in DWORD dwReserved
   , BYREF pllClockTime AS QUAD _                       ' __out LONGLONG *pllClockTime
   , BYREF phnsSystemTime AS QUAD _                     ' __out MFTIME *phnsSystemTime
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetContinuityKey ( _                          ' VTable offset = 20
     BYREF pdwContinuityKey AS DWORD _                  ' __out DWORD *pdwContinuityKey
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetState ( _                                  ' VTable offset = 24
     BYVAL dwReserved AS DWORD _                        ' __in DWORD dwReserved
   , BYREF peClockState AS LONG _                       ' __out MFCLOCK_STATE *peClockState
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetProperties ( _                             ' VTable offset = 28
     BYREF pClockProperties AS MFCLOCK_PROPERTIES _     ' __out MFCLOCK_PROPERTIES *pClockProperties
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IMFPresentationClock methods
   ' =====================================================================================
   METHOD GetUnderlyingClock ( _                        ' VTable offset = 32
     BYREF ppClock AS IMFClock _                        ' __out IMFClock **ppClock
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMFPresentationTimeSource_INTERFACE_DEFINED__ */


DECLARE FUNCTION MFCreateSystemTimeSource IMPORT "mfplat.dll" ALIAS "MFCreateSystemTimeSource" ( _
   BYREF ppSystemTimeSource AS IMFPresentationTimeSource _ ' __out IMFPresentationTimeSource** ppSystemTimeSource
 ) AS LONG                                                 ' HRESULT


' ########################################################################################
' Interface name = IMFClockStateSink
' IID = F6696E82-74F7-4F3D-A178-8A5E09C3659F
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMFClockStateSink_INTERFACE_DEFINED)
    %IMFClockStateSink_INTERFACE_DEFINED = 1

$IID_IMFClockStateSink = GUID$("{F6696E82-74F7-4F3D-A178-8A5E09C3659F}")

INTERFACE IMFClockStateSink $IID_IMFClockStateSink

   INHERIT IUnknown

   ' =====================================================================================
   METHOD OnClockStart ( _                              ' VTable offset = 12
     BYVAL hnsSystemTime AS QUAD _                      ' __in MFTIME hnsSystemTime
   , BYVAL llClockStartOffset AS QUAD _                 ' __in LONGLONG llClockStartOffset
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnClockStop ( _                               ' VTable offset = 16
     BYVAL hnsSystemTime AS QUAD _                      ' __in MFTIME hnsSystemTime
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnClockPause ( _                              ' VTable offset = 20
     BYVAL hnsSystemTime AS QUAD _                      ' __in MFTIME hnsSystemTime
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnClockRestart ( _                            ' VTable offset = 24
     BYVAL hnsSystemTime AS QUAD _                      ' __in MFTIME hnsSystemTime
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnClockSetRate ( _                            ' VTable offset = 28
     BYVAL hnsSystemTime AS QUAD _                      ' __in MFTIME hnsSystemTime
   , BYVAL flRate AS SINGLE _                           ' __in float flRate
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMFClockStateSink_INTERFACE_DEFINED__ */


$MF_PD_PMPHOST_CONTEXT = GUID$("{6C990D31-BB8E-477A-8598-0D5D96FCD88A}")
$MF_PD_APP_CONTEXT = GUID$("{6C990D32-BB8E-477A-8598-0D5D96FCD88A}")
$MF_PD_DURATION = GUID$("{6C990D33-BB8E-477A-8598-0D5D96FCD88A}")
$MF_PD_TOTAL_FILE_SIZE = GUID$("{6C990D34-BB8E-477A-8598-0D5D96FCD88A}")
$MF_PD_AUDIO_ENCODING_BITRATE = GUID$("{6C990D35-BB8E-477A-8598-0D5D96FCD88A}")
$MF_PD_VIDEO_ENCODING_BITRATE = GUID$("{6C990D36-BB8E-477A-8598-0D5D96FCD88A}")
$MF_PD_MIME_TYPE = GUID$("{6C990D37-BB8E-477A-8598-0D5D96FCD88A}")
$MF_PD_LAST_MODIFIED_TIME = GUID$("{6C990D38-BB8E-477A-8598-0D5D96FCD88A}")
'#if (WINVER >= _WIN32_WINNT_WIN7)
$MF_PD_PLAYBACK_ELEMENT_ID = GUID$("{6c990d39-bb8e-477a-8598-0d5d96fcd88a}")
$MF_PD_PREFERRED_LANGUAGE = GUID$("{6c990d3A-bb8e-477a-8598-0d5d96fcd88a}")
$MF_PD_PLAYBACK_BOUNDARY_TIME = GUID$("{6c990d3b-bb8e-477a-8598-0d5d96fcd88a}")
$MF_PD_AUDIO_ISVARIABLEBITRATE = GUID$("{33026ee0-e387-4582-ae0a-34a2ad3baa18}")
'#endif // (WINVER >= _WIN32_WINNT_WIN7)


' ########################################################################################
' Interface name = IMFPresentationDescriptor
' IID = 03CB2711-24D7-4DB6-A17F-F3A7A479A536
' Inherited interface = IMFAttributes
' ########################################################################################

#IF NOT %DEF(%IMFPresentationDescriptor_INTERFACE_DEFINED)
    %IMFPresentationDescriptor_INTERFACE_DEFINED = 1

$IID_IMFPresentationDescriptor = GUID$("{03CB2711-24D7-4DB6-A17F-F3A7A479A536}")

INTERFACE IMFPresentationDescriptor $IID_IMFPresentationDescriptor

   INHERIT IUnknown

   ' =====================================================================================
   ' IMFAttributes methods
   ' =====================================================================================
   METHOD GetItem ( _                                   ' VTable offset = 12
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF pValue AS PROPVARIANT _                      ' __in_out PROPVARIANT *pValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetItemType ( _                               ' VTable offset = 16
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF pType AS LONG _                              ' __out MF_ATTRIBUTE_TYPE *pType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CompareItem ( _                               ' VTable offset = 20
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF Value AS PROPVARIANT _                       ' __in REFPROPVARIANT Value
   , BYREF pbResult AS LONG _                           ' __out BOOL *pbResult
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Compare ( _                                   ' VTable offset = 24
     BYVAL pTheirs AS IMFAttributes _                   ' __in IMFAttributes *pTheirs
   , BYVAL MatchType AS LONG _                          ' __in MF_ATTRIBUTES_MATCH_TYPE MatchType
   , BYREF pbResult AS LONG _                           ' __out BOOL *pbResult
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetUINT32 ( _                                 ' VTable offset = 28
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF punValue AS DWORD _                          ' __out UINT32 *punValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetUINT64 ( _                                 ' VTable offset = 32
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF punValue AS QUAD _                           ' __out UINT64 *punValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDouble ( _                                 ' VTable offset = 36
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF pfValue AS DOUBLE _                          ' __out double *pfValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetGUID ( _                                   ' VTable offset = 40
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF pguidValue AS GUID _                         ' __out GUID *pguidValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetStringLength ( _                           ' VTable offset = 44
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF pcchLength AS DWORD _                        ' __out UINT32 *pcchLength
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetString ( _                                 ' VTable offset = 48
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF pwszValue AS WSTRINGZ _                      ' __out LPWSTR pwszValue
   , BYVAL cchBufSize AS DWORD _                        ' __in UINT32 cchBufSize
   , BYREF pcchLength AS DWORD _                        ' __in_out UINT32 *pcchLength
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAllocatedString ( _                        ' VTable offset = 52
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF ppwszValue AS DWORD _                        ' __out LPWSTR *ppwszValue
   , BYREF pcchLength AS DWORD _                        ' __out UINT32 *pcchLength
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetBlobSize ( _                               ' VTable offset = 56
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF pcbBlobSize AS DWORD _                       ' __out UINT32 *pcbBlobSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetBlob ( _                                   ' VTable offset = 60
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYVAL pBuf AS DWORD _                              ' __out UINT8 *pBuf
   , BYVAL cbBufSize AS DWORD _                         ' __in UINT32 cbBufSize
   , BYREF pcbBlobSize AS DWORD _                       ' __in_out UINT32 *pcbBlobSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAllocatedBlob ( _                          ' VTable offset = 64
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYVAL ppBuf AS DWORD _                             ' __out UINT8 **ppBuf
   , BYREF pcbSize AS DWORD _                           ' __out UINT32 *pcbSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetUnknown ( _                                ' VTable offset = 68
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppv AS IUnknown _                            ' __out LPVOID *ppv
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetItem ( _                                   ' VTable offset = 72
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF Value AS PROPVARIANT _                       ' __out REFPROPVARIANT Value
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DeleteItem ( _                                ' VTable offset = 76
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DeleteAllItems ( _                            ' VTable offset = 80
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetUINT32 ( _                                 ' VTable offset = 84
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYVAL unValue AS DWORD _                           ' __in UINT32 unValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetUINT64 ( _                                 ' VTable offset = 88
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYVAL unValue AS QUAD _                            ' __in UINT64 unValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetDouble ( _                                 ' VTable offset = 92
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYVAL fValue AS DOUBLE _                           ' __in double fValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetGUID ( _                                   ' VTable offset = 96
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF guidValue AS GUID _                          ' __in REFGUID guidValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetString ( _                                 ' VTable offset = 100
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF wszValue AS WSTRINGZ _                       ' __in LPCWSTR wszValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetBlob ( _                                   ' VTable offset = 104
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYVAL pBuf AS DWORD _                              ' __in  const UINT8 *pBuf
   , BYVAL cbBufSize AS DWORD _                         ' __in UINT32 cbBufSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetUnknown ( _                                ' VTable offset = 108
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYVAL pUnknown AS IUnknown _                       ' __in IUnknown *pUnknown
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD LockStore ( _                                 ' VTable offset = 112
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UnlockStore ( _                               ' VTable offset = 116
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCount ( _                                  ' VTable offset = 120
     BYREF pcItems AS DWORD _                           ' __out UINT32 *pcItems
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetItemByIndex ( _                            ' VTable offset = 124
     BYVAL unIndex AS DWORD _                           ' __in UINT32 unIndex
   , BYREF pguidKey AS GUID _                           ' __out GUID *pguidKey
   , BYREF pValue AS PROPVARIANT _                      ' __in_out PROPVARIANT *pValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CopyAllItems ( _                              ' VTable offset = 128
     BYVAL pDest AS LONG _                              ' __in IMFAttributes *pDest
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IMFPresentationDescriptor methods
   ' =====================================================================================
   METHOD GetStreamDescriptorCount ( _                  ' VTable offset = 132
     BYREF pdwDescriptorCount AS DWORD _                ' __out DWORD *pdwDescriptorCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetStreamDescriptorByIndex ( _                ' VTable offset = 136
     BYVAL dwIndex AS DWORD _                           ' __in DWORD dwIndex
   , BYREF pfSelected AS LONG _                         ' __out BOOL *pfSelected
   , BYREF ppDescriptor AS IMFStreamDescriptor _        ' __out IMFStreamDescriptor **ppDescriptor
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SelectStream ( _                              ' VTable offset = 140
     BYVAL dwDescriptorIndex AS DWORD _                 ' __in DWORD dwDescriptorIndex
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DeselectStream ( _                            ' VTable offset = 144
     BYVAL dwDescriptorIndex AS DWORD _                 ' __in DWORD dwDescriptorIndex
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 148
     BYREF ppPresentationDescriptor AS IMFPresentationDescriptor _ ' __out IMFPresentationDescriptor **ppPresentationDescriptor
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMFPresentationDescriptor_INTERFACE_DEFINED__ */


DECLARE FUNCTION MFCreatePresentationDescriptor IMPORT "mfplat.dll" ALIAS "MFCreatePresentationDescriptor" ( _
   BYVAL cStreamDescriptors AS DWORD _                  ' __in DWORD cStreamDescriptors
 , BYREF apStreamDescriptors AS IMFStreamDescriptor _   ' __in_ecount_opt( cStreamDescriptors ) IMFStreamDescriptor** apStreamDescriptors
 , BYREF ppPresentationDescriptor AS IMFPresentationDescriptor _ ' __deref_out IMFPresentationDescriptor** ppPresentationDescriptor
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION MFRequireProtectedEnvironment IMPORT "mf.dll" ALIAS "MFRequireProtectedEnvironment" ( _
   BYVAL pPresentationDescriptor AS IMFPresentationDescriptor _ ' __in IMFPresentationDescriptor* pPresentationDescriptor
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION MFSerializePresentationDescriptor IMPORT "mfplat.dll" ALIAS "MFSerializePresentationDescriptor" ( _
   BYVAL pPD AS IMFPresentationDescriptor _             ' __in IMFPresentationDescriptor * pPD
 , BYREF pcbData AS DWORD _                             ' __out DWORD * pcbData
 , BYREF ppbData AS DWORD _                             ' __deref_out_bcount(*pcbData) BYTE ** ppbData
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION MFDeserializePresentationDescriptor IMPORT "mfplat.dll" ALIAS "MFDeserializePresentationDescriptor" ( _
   BYVAL cbData AS DWORD _                              ' __in DWORD cbData
 , BYVAL pbData AS BYTE PTR _                           ' __in_ecount( cbData ) BYTE * pbData
 , BYREF ppPD AS IMFPresentationDescriptor _            ' __deref_out IMFPresentationDescriptor ** ppPD
 ) AS LONG                                              ' HRESULT


$MF_SD_LANGUAGE  = GUID$("{00AF2180-BDC2-423C-ABCA-F503593BC121}")
$MF_SD_PROTECTED = GUID$("{00AF2181-BDC2-423C-ABCA-F503593BC121}")
$MF_SD_STREAM_NAME = GUID$("{4f1b099d-d314-41e5-a781-7fefaa4c501f}")
$MF_SD_MUTUALLY_EXCLUSIVE = GUID$("{023ef79c-388d-487f-ac17-696cd6e3c6f5}")


' ########################################################################################
' Interface name = IMFStreamDescriptor
' IID = 56C03D9C-9DBB-45F5-AB4B-D80F47C05938
' Inherited interface = IMFAttributes
' ########################################################################################

#IF NOT %DEF(%IMFStreamDescriptor_INTERFACE_DEFINED)
    %IMFStreamDescriptor_INTERFACE_DEFINED = 1

$IID_IMFStreamDescriptor = GUID$("{56C03D9C-9DBB-45F5-AB4B-D80F47C05938}")

INTERFACE IMFStreamDescriptor $IID_IMFStreamDescriptor

   INHERIT IUnknown

   ' =====================================================================================
   ' IMFAttributes methods
   ' =====================================================================================
   METHOD GetItem ( _                                   ' VTable offset = 12
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF pValue AS PROPVARIANT _                      ' __in_out PROPVARIANT *pValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetItemType ( _                               ' VTable offset = 16
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF pType AS LONG _                              ' __out MF_ATTRIBUTE_TYPE *pType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CompareItem ( _                               ' VTable offset = 20
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF Value AS PROPVARIANT _                       ' __in REFPROPVARIANT Value
   , BYREF pbResult AS LONG _                           ' __out BOOL *pbResult
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Compare ( _                                   ' VTable offset = 24
     BYVAL pTheirs AS IMFAttributes _                   ' __in IMFAttributes *pTheirs
   , BYVAL MatchType AS LONG _                          ' __in MF_ATTRIBUTES_MATCH_TYPE MatchType
   , BYREF pbResult AS LONG _                           ' __out BOOL *pbResult
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetUINT32 ( _                                 ' VTable offset = 28
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF punValue AS DWORD _                          ' __out UINT32 *punValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetUINT64 ( _                                 ' VTable offset = 32
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF punValue AS QUAD _                           ' __out UINT64 *punValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDouble ( _                                 ' VTable offset = 36
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF pfValue AS DOUBLE _                          ' __out double *pfValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetGUID ( _                                   ' VTable offset = 40
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF pguidValue AS GUID _                         ' __out GUID *pguidValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetStringLength ( _                           ' VTable offset = 44
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF pcchLength AS DWORD _                        ' __out UINT32 *pcchLength
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetString ( _                                 ' VTable offset = 48
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF pwszValue AS WSTRINGZ _                      ' __out LPWSTR pwszValue
   , BYVAL cchBufSize AS DWORD _                        ' __in UINT32 cchBufSize
   , BYREF pcchLength AS DWORD _                        ' __in_out UINT32 *pcchLength
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAllocatedString ( _                        ' VTable offset = 52
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF ppwszValue AS DWORD _                        ' __out LPWSTR *ppwszValue
   , BYREF pcchLength AS DWORD _                        ' __out UINT32 *pcchLength
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetBlobSize ( _                               ' VTable offset = 56
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF pcbBlobSize AS DWORD _                       ' __out UINT32 *pcbBlobSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetBlob ( _                                   ' VTable offset = 60
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYVAL pBuf AS DWORD _                              ' __out UINT8 *pBuf
   , BYVAL cbBufSize AS DWORD _                         ' __in UINT32 cbBufSize
   , BYREF pcbBlobSize AS DWORD _                       ' __in_out UINT32 *pcbBlobSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAllocatedBlob ( _                          ' VTable offset = 64
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYVAL ppBuf AS DWORD _                             ' __out UINT8 **ppBuf
   , BYREF pcbSize AS DWORD _                           ' __out UINT32 *pcbSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetUnknown ( _                                ' VTable offset = 68
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppv AS IUnknown _                            ' __out LPVOID *ppv
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetItem ( _                                   ' VTable offset = 72
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF Value AS PROPVARIANT _                       ' __out REFPROPVARIANT Value
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DeleteItem ( _                                ' VTable offset = 76
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DeleteAllItems ( _                            ' VTable offset = 80
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetUINT32 ( _                                 ' VTable offset = 84
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYVAL unValue AS DWORD _                           ' __in UINT32 unValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetUINT64 ( _                                 ' VTable offset = 88
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYVAL unValue AS QUAD _                            ' __in UINT64 unValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetDouble ( _                                 ' VTable offset = 92
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYVAL fValue AS DOUBLE _                           ' __in double fValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetGUID ( _                                   ' VTable offset = 96
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF guidValue AS GUID _                          ' __in REFGUID guidValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetString ( _                                 ' VTable offset = 100
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF wszValue AS WSTRINGZ _                       ' __in LPCWSTR wszValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetBlob ( _                                   ' VTable offset = 104
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYVAL pBuf AS DWORD _                              ' __in  const UINT8 *pBuf
   , BYVAL cbBufSize AS DWORD _                         ' __in UINT32 cbBufSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetUnknown ( _                                ' VTable offset = 108
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYVAL pUnknown AS IUnknown _                       ' __in IUnknown *pUnknown
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD LockStore ( _                                 ' VTable offset = 112
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UnlockStore ( _                               ' VTable offset = 116
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCount ( _                                  ' VTable offset = 120
     BYREF pcItems AS DWORD _                           ' __out UINT32 *pcItems
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetItemByIndex ( _                            ' VTable offset = 124
     BYVAL unIndex AS DWORD _                           ' __in UINT32 unIndex
   , BYREF pguidKey AS GUID _                           ' __out GUID *pguidKey
   , BYREF pValue AS PROPVARIANT _                      ' __in_out PROPVARIANT *pValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CopyAllItems ( _                              ' VTable offset = 128
     BYVAL pDest AS LONG _                              ' __in IMFAttributes *pDest
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IMFStreamDescriptor methods
   ' =====================================================================================
   METHOD GetStreamIdentifier ( _                       ' VTable offset = 132
     BYREF pdwStreamIdentifier AS DWORD _               ' __out DWORD *pdwStreamIdentifier
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMediaTypeHandler ( _                       ' VTable offset = 136
     BYREF ppMediaTypeHandler AS IMFMediaTypeHandler _  ' __out IMFMediaTypeHandler **ppMediaTypeHandler
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMFStreamDescriptor_INTERFACE_DEFINED__ */


DECLARE FUNCTION MFCreateStreamDescriptor IMPORT "mfplat.dll" ALIAS "MFCreateStreamDescriptor" ( _
   BYVAL dwStreamIdentifier AS DWORD _                  ' __in DWORD dwStreamIdentifier
 , BYVAL cMediaTypes AS DWORD _                         ' __in DWORD cMediaTypes
 , BYREF apMediaTypes AS IMFMediaType _                 ' __in_ecount(cMediaTypes) IMFMediaType** apMediaTypes
 , BYREF ppDescriptor AS IMFStreamDescriptor _          ' __out IMFStreamDescriptor** ppDescriptor
 ) AS LONG                                              ' HRESULT


' ########################################################################################
' Interface name = IMFMediaTypeHandler
' IID = E93DCF6C-4B07-4E1E-8123-AA16ED6EADF5
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMFMediaTypeHandler_INTERFACE_DEFINED)
    %IMFMediaTypeHandler_INTERFACE_DEFINED = 1

$IID_IMFMediaTypeHandler = GUID$("{E93DCF6C-4B07-4E1E-8123-AA16ED6EADF5}")

INTERFACE IMFMediaTypeHandler $IID_IMFMediaTypeHandler

   INHERIT IUnknown

   ' =====================================================================================
   METHOD IsMediaTypeSupported ( _                      ' VTable offset = 12
     BYVAL pMediaType AS IMFMediaType _                 ' __in IMFMediaType *pMediaType
   , BYREF ppMediaType AS IMFMediaType _                ' __out IMFMediaType **ppMediaType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMediaTypeCount ( _                         ' VTable offset = 16
     BYREF pdwTypeCount AS DWORD _                      ' __out DWORD *pdwTypeCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMediaTypeByIndex ( _                       ' VTable offset = 20
     BYVAL dwIndex AS DWORD _                           ' __in DWORD dwIndex
   , BYREF ppType AS IMFMediaType _                     ' __out IMFMediaType **ppType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetCurrentMediaType ( _                       ' VTable offset = 24
     BYVAL pMediaType AS IMFMediaType _                 ' __in IMFMediaType *pMediaType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCurrentMediaType ( _                       ' VTable offset = 28
     BYREF pMediaType AS IMFMediaType _                 ' __out IMFMediaType **ppMediaType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMajorType ( _                              ' VTable offset = 32
      BYREF pguidMajorType AS GUID _                    ' __out GUID *pguidMajorType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMFMediaTypeHandler_INTERFACE_DEFINED__ */


DECLARE FUNCTION MFCreateSimpleTypeHandler IMPORT "mf.dll" ALIAS "MFCreateSimpleTypeHandler" ( _
   BYREF ppHandler AS IMFMediaTypeHandler _             ' __out IMFMediaTypeHandler ** ppHandler
 ) AS LONG                                              ' HRESULT

' enum MFTIMER_FLAGS
%MFTIMER_RELATIVE = &H1


' ########################################################################################
' Interface name = IMFTimer
' IID = E56E4CBD-8F70-49D8-A0F8-EDB3D6AB9BF2
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMFTimer_INTERFACE_DEFINED)
    %IMFTimer_INTERFACE_DEFINED = 1

$IID_IMFTimer = GUID$("{E56E4CBD-8F70-49D8-A0F8-EDB3D6AB9BF2}")

INTERFACE IMFTimer $IID_IMFTimer

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetTimer ( _                                  ' VTable offset = 12
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYVAL llClockTime AS QUAD _                        ' __in LONGLONG llClockTime
   , BYVAL pCallback AS IMFAsyncCallback _              ' __in IMFAsyncCallback *pCallback
   , BYVAL punkState AS IUnknown _                      ' __in IUnknown *punkState
   , BYREF ppunkKey AS IUnknown _                       ' __out IUnknown **ppunkKey
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CancelTimer ( _                               ' VTable offset = 16
     BYVAL punkKey AS IUnknown _                        ' __in IUnknown *punkKey
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMFTimer_INTERFACE_DEFINED__ */


$MF_ACTIVATE_CUSTOM_VIDEO_MIXER_CLSID        = GUID$("{BA491360-BE50-451E-95AB-6D4ACCC7DAD8}")
$MF_ACTIVATE_CUSTOM_VIDEO_MIXER_ACTIVATE     = GUID$("{BA491361-BE50-451E-95AB-6D4ACCC7DAD8}")
$MF_ACTIVATE_CUSTOM_VIDEO_MIXER_FLAGS        = GUID$("{BA491362-BE50-451E-95AB-6D4ACCC7DAD8}")
$MF_ACTIVATE_CUSTOM_VIDEO_PRESENTER_CLSID    = GUID$("{BA491364-BE50-451E-95AB-6D4ACCC7DAD8}")
$MF_ACTIVATE_CUSTOM_VIDEO_PRESENTER_ACTIVATE = GUID$("{BA491365-BE50-451E-95AB-6D4ACCC7DAD8}")
$MF_ACTIVATE_CUSTOM_VIDEO_PRESENTER_FLAGS    = GUID$("{BA491366-BE50-451E-95AB-6D4ACCC7DAD8}")

' enum __MIDL___MIDL_itf_mfidl_0000_0019_0001
%MF_ACTIVATE_CUSTOM_MIXER_ALLOWFAIL = &H1

' enum __MIDL___MIDL_itf_mfidl_0000_0019_0002
%MF_ACTIVATE_CUSTOM_PRESENTER_ALLOWFAIL = &H1

$MF_ACTIVATE_MFT_LOCKED   = GUID$("{C1F6093C-7F65-4FBD-9E39-5FAEC3C4FBD7}")
$MF_ACTIVATE_VIDEO_WINDOW = GUID$("{9A2DBBDD-F57E-4162-82B9-6831377682D3}")

' enum MFSHUTDOWN_STATUS
%MFSHUTDOWN_INITIATED   = 0
%MFSHUTDOWN_COMPLETED   = %MFSHUTDOWN_INITIATED + 1


' ########################################################################################
' Interface name = IMFShutdown
' IID = 97EC2EA4-0E42-4937-97AC-9D6D328824E1
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMFShutdown_INTERFACE_DEFINED)
    %IMFShutdown_INTERFACE_DEFINED = 1

$IID_IMFShutdown = GUID$("{97EC2EA4-0E42-4937-97AC-9D6D328824E1}")

INTERFACE IMFShutdown $IID_IMFShutdown

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Shutdown ( _                                  ' VTable offset = 12
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetShutdownStatus ( _                         ' VTable offset = 16
     BYREF pStatus AS LONG _                            ' __out MFSHUTDOWN_STATUS *pStatus
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMFShutdown_INTERFACE_DEFINED__ */

DECLARE FUNCTION MFShutdownObject IMPORT "mf.dll" ALIAS "MFShutdownObject" ( _
   BYVAL pUnk AS IUnknown _                             ' __in IUnknown * pUnk
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION MFCreateAudioRenderer IMPORT "mf.dll" ALIAS "MFCreateAudioRenderer" ( _
   BYVAL pAudioAttributes AS IMFAttributes _            ' __in IMFAttributes* pAudioAttributes
 , BYREF ppSink AS IMFMediaSink _                       ' __out IMFMediaSink** ppSink
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION MFCreateAudioRendererActivate IMPORT "mf.dll" ALIAS "MFCreateAudioRendererActivate" ( _
   BYREF ppActivate AS IMFActivate _                    ' __out IMFActivate ** ppActivate
 ) AS LONG                                              ' HRESULT


$MF_AUDIO_RENDERER_ATTRIBUTE_FLAGS = GUID$("{EDE4B5E0-F805-4D6C-99B3-DB01BF95DFAB}")

%MF_AUDIO_RENDERER_ATTRIBUTE_FLAGS_CROSSPROCESS = &H00000001???
%MF_AUDIO_RENDERER_ATTRIBUTE_FLAGS_NOPERSIST    = &H00000002???

$MF_AUDIO_RENDERER_ATTRIBUTE_SESSION_ID = GUID$("{EDE4B5E3-F805-4D6C-99B3-DB01BF95DFAB}")
$MF_AUDIO_RENDERER_ATTRIBUTE_ENDPOINT_ID = GUID$("{B10AAEC3-EF71-4CC3-B873-05A9-A08B9F8E}")
$MF_AUDIO_RENDERER_ATTRIBUTE_ENDPOINT_ROLE = GUID$("{6BA644FF-27C5-4D02-9887-C28619FDB91B}")

DECLARE FUNCTION MFCreateVideoRendererActivate IMPORT "mf.dll" ALIAS "MFCreateVideoRendererActivate" ( _
   BYVAL hwndVideo AS DWORD _                           ' __in HWND hwndVideo
 , BYREF ppActivate AS IMFActivate _                    ' __out IMFActivate ** ppActivate
 ) AS LONG                                              ' HRESULT

'#if (WINVER >= _WIN32_WINNT_WIN7)
DECLARE FUNCTION MFCreateMPEG4MediaSink IMPORT "mf.dll" ALIAS "MFCreateMPEG4MediaSink" ( _
   BYVAL pIByteStream AS IMFByteStream _                ' __in IMFByteStream* pIByteStream
 , BYVAL pVideoMediaType AS IMFMediaType _              ' __in_opt IMFMediaType* pVideoMediaType
 , BYVAL pAudioMediaType AS IMFMediaType _              ' __in_opt IMFMediaType* pAudioMediaType
 , BYREF ppIMediaSink AS IMFMediaSink _                 ' __out IMFMediaSink** ppIMediaSink
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION MFCreate3GPMediaSink IMPORT "mf.dll" ALIAS "MFCreate3GPMediaSink" ( _
   BYVAL pIByteStream AS IMFByteStream _                ' __in IMFByteStream* pIByteStream
 , BYVAL pVideoMediaType AS IMFMediaType _              ' __in_opt IMFMediaType* pVideoMediaType
 , pAudioMediaType AS IMFMediaType _                    ' __in_opt IMFMediaType* pAudioMediaType
 , BYREF ppIMediaSink AS IMFMediaSink _                 ' __out IMFMediaSink** ppIMediaSink
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION MFCreateMP3MediaSink IMPORT "mf.dll" ALIAS "MFCreateMP3MediaSink" ( _
   BYVAL pTargetByteStream AS IMFByteStream _           ' __in IMFByteStream* pTargetByteStream
 , BYREF ppMediaSink AS IMFMediaSink _                  ' __out IMFMediaSink** ppMediaSink
 ) AS LONG                                              ' HRESULT
'#endif // (WINVER >= _WIN32_WINNT_WIN7)

' ########################################################################################
' Interface name = IMFTopoLoader
' IID = DE9A6157-F660-4643-B56A-DF9F7998C7CD
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMFTopoLoader_INTERFACE_DEFINED)
    %IMFTopoLoader_INTERFACE_DEFINED = 1

$IID_IMFTopoLoader = GUID$("{DE9A6157-F660-4643-B56A-DF9F7998C7CD}")

INTERFACE IMFTopoLoader $IID_IMFTopoLoader

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Load ( _                                      ' VTable offset = 12
     BYVAL pInputTopo AS IMFTopology _                  ' __in IMFTopology *pInputTopo
   , BYREF ppOutputTopo AS IMFTopology _                ' __out IMFTopology **ppOutputTopo
   , BYVAL pCurrentTopo AS IMFTopology _                ' __in IMFTopology *pCurrentTopo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMFTopoLoader_INTERFACE_DEFINED__ */


DECLARE FUNCTION MFCreateTopoLoader IMPORT "mf.dll" ALIAS "MFCreateTopoLoader" ( _
   BYREF ppObj AS IMFTopoLoader _                       ' __out IMFTopoLoader ** ppObj
 ) AS LONG                                              ' HRESULT


' ########################################################################################
' Interface name = IMFContentProtectionManager
' IID = ACF92459-6A61-42BD-B57C-B43E51203CB0"
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMFContentProtectionManager_INTERFACE_DEFINED)
    %IMFContentProtectionManager_INTERFACE_DEFINED = 1

$IID_IMFContentProtectionManager = GUID$("{ACF92459-6A61-42BD-B57C-B43E51203CB0}")

INTERFACE IMFContentProtectionManager $IID_IMFContentProtectionManager

   INHERIT IUnknown

   ' =====================================================================================
   METHOD BeginEnableContent ( _                        ' VTable offset = 12
     BYVAL pEnablerActivate AS IMFActivate _            ' __in IMFActivate *pEnablerActivate
   , BYVAL pTopo AS IMFTopology _                       ' __in IMFTopology *pTopo
   , BYVAL pCallback AS IMFAsyncCallback _              ' __in IMFAsyncCallback *pCallback
   , BYVAL punkState AS IUnknown _                      ' __in IUnknown *punkState
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EndEnableContent ( _                          ' VTable offset = 16
      BYVAL pResult AS IMFAsyncResult _                 ' __in IMFAsyncResult *pResult
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMFContentProtectionManager_INTERFACE_DEFINED__ */


' enum MF_URL_TRUST_STATUS
%MF_LICENSE_URL_UNTRUSTED = 0
%MF_LICENSE_URL_TRUSTED   = %MF_LICENSE_URL_UNTRUSTED + 1
%MF_LICENSE_URL_TAMPERED  = %MF_LICENSE_URL_TRUSTED + 1


' ########################################################################################
' Interface name = IMFContentEnabler
' IID = D3C4EF59-49CE-4381-9071-D5BCD044C770
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMFContentEnabler_INTERFACE_DEFINED)
    %IMFContentEnabler_INTERFACE_DEFINED = 1

$IID_IMFContentEnabler = GUID$("{D3C4EF59-49CE-4381-9071-D5BCD044C770}")

INTERFACE IMFContentEnabler $IID_IMFContentEnabler

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetEnableType ( _                             ' VTable offset = 12
     BYREF pType AS GUID _                              ' __out GUID *pType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetEnableURL ( _                              ' VTable offset = 16
     BYREF ppwszURL AS DWORD _                          ' __out (*pcchURL) LPWSTR *ppwszURL
   , BYREF pcchURL AS DWORD _                           ' __out DWORD *pcchURL
   , BYREF pTrustStatus AS LONG _                       ' __inout MF_URL_TRUST_STATUS *pTrustStatus
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetEnableData ( _                             ' VTable offset = 20
     BYREF ppbData AS DWORD _                           ' __out (*pcbData) BYTE **ppbData
   , BYREF pcbData AS DWORD _                           ' __out DWORD *pcbData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsAutomaticSupported ( _                      ' VTable offset = 24
     BYREF pfAutomatic AS LONG _                        ' __out BOOL *pfAutomatic
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AutomaticEnable ( _                           ' VTable offset = 28
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD MonitorEnable ( _                             ' VTable offset = 28
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Cancel ( _                                    ' VTable offset = 32
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMFContentEnabler_INTERFACE_DEFINED__ */


$MFENABLETYPE_WMDRMV1_LicenseAcquisition = GUID$("{4FF6EEAF-0B43-4797-9B85-ABF31815E7B0}")
$MFENABLETYPE_WMDRMV7_LicenseAcquisition = GUID$("{030306DF-4A06-4884-A097-EF6D22EC84A3}")
$MFENABLETYPE_WMDRMV7_Individualization = GUID$("{ACD2C84A-B303-4F65-BC2C-2C848D01A989}")
$MFENABLETYPE_MF_UpdateRevocationInformation = GUID$("{E558B0B5-B3C4-44A0-924C-50D178932385}")
$MFENABLETYPE_MF_UpdateUntrustedComponent = GUID$("{9879F3D6-CEE2-48E6-B573-9767AB172F16}")
$MFENABLETYPE_MF_RebootRequired = GUID$("{6D4D3D4B-0ECE-4652-8B3A-F2D24260D887}")


'//
'// Structs that contain information about revoked or unsigned binaries,
'// returned by the IMFContentEnabler::GetEnableData() method of
'// the Revocation content enabler
'//

#IF NOT %DEF(%MFRR_INFO_VERSION)
%MFRR_INFO_VERSION = 0
#ENDIF

'//
'// The values for MFRR_COMPONENT_HASH_INFO.ulReason
'//

%MF_USER_MODE_COMPONENT_LOAD        = &H00000001???
%MF_KERNEL_MODE_COMPONENT_LOAD      = &H00000002???
%MF_GRL_LOAD_FAILED                 = &H00000010???
%MF_INVALID_GRL_SIGNATURE           = &H00000020???
%MF_GRL_ABSENT                      = &H00001000???
%MF_COMPONENT_REVOKED               = &H00002000???
%MF_COMPONENT_INVALID_EKU           = &H00004000???
%MF_COMPONENT_CERT_REVOKED          = &H00008000???
%MF_COMPONENT_INVALID_ROOT          = &H00010000???
%MF_COMPONENT_HS_CERT_REVOKED       = &H00020000???
%MF_COMPONENT_LS_CERT_REVOKED       = &H00040000???
%MF_BOOT_DRIVER_VERIFICATION_FAILED = &H00100000???
%MF_TEST_SIGNED_COMPONENT_LOADING   = &H01000000???
%MF_MINCRYPT_FAILURE                = &H10000000???

'//
'// STR_HASH_LEN: Number of characters required to represent a SHA-1 hash
'// as a string of the form "0x5a3b53463b672a4f..."
'// Each byte of a SHA-1 hash takes two characters to represent, and
'// we add in two leading characters "0x" as well as the NULL terminator
'//

%SHA_HASH_LEN   = 20
%STR_HASH_LEN   = %SHA_HASH_LEN * 2 + 3

' // Size = 696 bytes
TYPE MFRR_COMPONENT_HASH_INFO BYTE
   ' // Reason for failure (revoked or unsigned or badly signed).
   ulReason        AS DWORD                        ' DWORD
   ' // Header hash of the component
   rgHeaderHash    AS WSTRINGZ * %STR_HASH_LEN     ' WCHAR
   ' // Hash of public key if one of the certificates
   ' // in the signing certificate chain is revoked
   rgPublicKeyHash AS WSTRINGZ * %STR_HASH_LEN     ' WCHAR
   ' // Component name (full path name)
   wszName         AS WSTRINGZ * %MAX_PATH         ' WCHAR
END TYPE

' // Size = 12 bytes
TYPE MFRR_COMPONENTS DWORD
   ' // Version number
   dwRRInfoVersion AS DWORD   ' DWORD
   ' // Number of components in list
   dwRRComponents  AS DWORD   ' DWORD
   ' // points to the end of this structure that has
   ' // allocated memory for the array of component info structures
   pRRComponents   AS MFRR_COMPONENT_HASH_INFO PTR  ' PMFRR_COMPONENT_HASH_INFO
END TYPE

'#pragma pack ( push )
'#pragma pack ( 1 )

' // Size = 5 bytes
TYPE ASF_FLAT_PICTURE BYTE
   ' // Direct mapped fields
   bPictureType AS BYTE    ' BYTE
   dwDataLen    AS DWORD   ' DWORD
END TYPE
MACRO ASFFlatPicture = ASF_FLAT_PICTURE
'#pragma pack ( pop )

'#pragma pack ( push )
'#pragma pack ( 1 )
' // size = 6 bytes
TYPE ASF_FLAT_SYNCHRONISED_LYRICS BYTE
   ' // Direct mapped fields
   bTimeStampFormat AS BYTE   ' BYTE
   bContentType     AS BYTE   ' BYTE
   dwLyricsLen      AS DWORD  ' DWORD
END TYPE
MACRO ASFFlatSynchronisedLyrics = ASF_FLAT_SYNCHRONISED_LYRICS
'#pragma pack ( pop )


' ########################################################################################
' Interface name = IMFMetadata
' IID = F88CFB8C-EF16-4991-B450-CB8C69E51704
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMFMetadata_INTERFACE_DEFINED)
    %IMFMetadata_INTERFACE_DEFINED = 1

$IID_IMFMetadata = GUID$("{F88CFB8C-EF16-4991-B450-CB8C69E51704}")

INTERFACE IMFMetadata $IID_IMFMetadata

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetLanguage ( _                               ' VTable offset = 12
     BYREF pwszRFC1766 AS WSTRINGZ _                    ' __in LPCWSTR pwszRFC1766
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetLanguage ( _                               ' VTable offset = 16
     BYREF ppwszRFC1766 AS DWORD _                      ' __out LPWSTR *ppwszRFC1766
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAllLanguages ( _                           ' VTable offset = 20
     BYREF ppvLanguages AS PROPVARIANT _                ' __out PROPVARIANT *ppvLanguages
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetProperty ( _                               ' VTable offset = 24
     BYREF pwszName AS WSTRINGZ _                       ' __in LPCWSTR pwszName
   , BYREF ppvValue AS PROPVARIANT _                    ' __in const PROPVARIANT *ppvValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetProperty ( _                               ' VTable offset = 28
     BYREF pwszName AS WSTRINGZ _                       ' __in LPCWSTR pwszName
   , BYREF ppvValue AS PROPVARIANT _                    ' __out PROPVARIANT *ppvValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DeleteProperty ( _                            ' VTable offset = 32
     BYREF pwszName AS WSTRINGZ _                       ' __in LPCWSTR pwszName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAllPropertyNames ( _                       ' VTable offset = 36
     BYREF ppvNames AS PROPVARIANT _                    ' __out PROPVARIANT *ppvNames
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMFMetadata_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IMFMetadataProvider
' IID = 56181D2D-E221-4ADB-B1C8-3CEE6A53F76F
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMFMetadataProvider_INTERFACE_DEFINED)
    %IMFMetadataProvider_INTERFACE_DEFINED = 1

$IID_IMFMetadataProvider = GUID$("{56181D2D-E221-4ADB-B1C8-3CEE6A53F76F}")

INTERFACE IMFMetadataProvider $IID_IMFMetadataProvider

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetMFMetadata ( _                             ' VTable offset = 12
     BYVAL pPresentationDescriptor AS IMFPresentationDescriptor _ ' __in IMFPresentationDescriptor *pPresentationDescriptor
   , BYVAL dwStreamIdentifier AS DWORD _                ' __in DWORD dwStreamIdentifier
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF ppMFMetadata AS IMFMetadata _                ' __out IMFMetadata **ppMFMetadata
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMFMetadataProvider_INTERFACE_DEFINED__ */


$MF_METADATA_PROVIDER_SERVICE = GUID$("{DB214084-58A4-4D2E-B84F-6F755B2F7A0D}")

' enum MFRATE_DIRECTION
%MFRATE_FORWARD   = 0
%MFRATE_REVERSE   = %MFRATE_FORWARD + 1


' ########################################################################################
' Interface name = IMFRateSupport
' IID = 0A9CCDBC-D797-4563-9667-94EC5D79292D
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMFRateSupport_INTERFACE_DEFINED)
    %IMFRateSupport_INTERFACE_DEFINED = 1

$IID_IMFRateSupport = GUID$("{0A9CCDBC-D797-4563-9667-94EC5D79292D}")

INTERFACE IMFRateSupport $IID_IMFRateSupport

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetSlowestRate ( _                            ' VTable offset = 12
     BYVAL eDirection AS LONG _                         ' __in MFRATE_DIRECTION eDirection
   , BYVAL fThin AS LONG _                              ' __in BOOL fThin
   , BYREF pflRate AS SINGLE _                          ' __out float *pflRate
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFastestRate ( _                            ' VTable offset = 16
     BYVAL eDirection AS LONG _                         ' __in MFRATE_DIRECTION eDirection
   , BYVAL fThin AS LONG _                              ' __in BOOL fThin
   , BYREF pflRate AS SINGLE _                          ' __out float *pflRate
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsRateSupported ( _                           ' VTable offset = 20
     BYVAL fThin AS LONG _                              ' __in BOOL fThin
   , BYVAL flRate AS SINGLE _                           ' __in float flRate
   , BYREF pflNearestSupportedRate AS SINGLE _          ' __inout float *pflNearestSupportedRate
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMFRateSupport_INTERFACE_DEFINED__ */


$MF_RATE_CONTROL_SERVICE = GUID$("{866FA297-B802-4BF8-9DC9-5E3B6A9F53C9}")


' ########################################################################################
' Interface name = IMFRateControl
' IID = 88DDCD21-03C3-4275-91ED-55EE3929328F
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMFRateControl_INTERFACE_DEFINED)
    %IMFRateControl_INTERFACE_DEFINED = 1

$IID_IMFRateControl = GUID$("{88DDCD21-03C3-4275-91ED-55EE3929328F}")

INTERFACE IMFRateControl $IID_IMFRateControl

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetRate ( _                                   ' VTable offset = 12
     BYVAL fThin AS LONG _                              ' __in BOOL fThin
   , BYVAL flRate AS SINGLE _                           ' __in float flRate
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRate ( _                                   ' VTable offset = 16
     BYREF pfThin AS LONG _                             ' __inout BOOL *pfThin
   , BYREF pflRate AS SINGLE _                          ' __inout float *pflRate
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMFRateControl_INTERFACE_DEFINED__ */

'#if (WINVER >= _WIN32_WINNT_WIN7)

' ########################################################################################
' Interface name = IMFTimecodeTranslate
' IID = ab9d8661-f7e8-4ef4-9861-89f334f94e74
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMFTimecodeTranslate_INTERFACE_DEFINED)
    %IMFTimecodeTranslate_INTERFACE_DEFINED = 1

$IID_IMFTimecodeTranslate = GUID$("{ab9d8661-f7e8-4ef4-9861-89f334f94e74}")

INTERFACE IMFTimecodeTranslate $IID_IMFTimecodeTranslate

   INHERIT IUnknown

   ' =====================================================================================
   METHOD BeginConvertTimecodeToHNS ( _                 ' VTable offset = 12
     BYREF pPropVarTimecode AS PROPVARIANT _            ' __in const PROPVARIANT *pPropVarTimecode
   , BYVAL pCallback AS IMFAsyncCallback _              ' __in IMFAsyncCallback *pCallback
   , BYVAL punkState AS IUnknown _                      ' __in IUnknown *punkState
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EndConvertTimecodeToHNS ( _                   ' VTable offset = 16
     BYVAL pResult AS IMFAsyncResult _                  ' __in IMFAsyncResult *pResult
   , BYREF phnsTime AS QUAD _                           ' __out MFTIME *phnsTime
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD BeginConvertHNSToTimecode ( _                 ' VTable offset = 20
     BYVAL hnsTime AS QUAD _                            ' __in MFTIME hnsTime
   , BYVAL pCallback AS IMFAsyncCallback _              ' __in IMFAsyncCallback *pCallback
   , BYREF punkState AS IUnknown _                      ' __in IUnknown *punkState
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EndConvertHNSToTimecode ( _                   ' VTable offset = 24
     BYVAL pResult AS IMFAsyncResult _                  ' __in IMFAsyncResult *pResult
   , BYREF pPropVarTimecode AS PROPVARIANT _            ' __out PROPVARIANT *pPropVarTimecode
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMFTimecodeTranslate_INTERFACE_DEFINED__ */

$MF_TIMECODE_SERVICE = GUID$("{a0d502a7-0eb3-4885-b1b9-9feb0d083454}")
'#endif // (WINVER >= _WIN32_WINNT_WIN7)


' ########################################################################################
' Interface name = IMFSimpleAudioVolume
' IID = 089EDF13-CF71-4338-8D13-9E569DBDC319
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMFSimpleAudioVolume_INTERFACE_DEFINED)
    %IMFSimpleAudioVolume_INTERFACE_DEFINED = 1

$IID_IMFSimpleAudioVolume = GUID$("{089EDF13-CF71-4338-8D13-9E569DBDC319}")

INTERFACE IMFSimpleAudioVolume $IID_IMFSimpleAudioVolume

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetMasterVolume ( _                           ' VTable offset = 12
     BYVAL fLevel AS SINGLE _                           ' __in float fLevel
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMasterVolume ( _                           ' VTable offset = 16
     BYREF pfLevel AS SINGLE _                          ' __out float *pfLevel
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetMute ( _                                   ' VTable offset = 20
     BYVAL bMute AS LONG _                              ' __in const BOOL bMute
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMute ( _                                   ' VTable offset = 24
     BYREF pbMute AS LONG _                             ' __out BOOL *pbMute
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMFSimpleAudioVolume_INTERFACE_DEFINED__ */


$MR_POLICY_VOLUME_SERVICE = GUID$("{1ABAA2AC-9D3B-47C6-AB48-C59506DE784D}")


' ########################################################################################
' Interface name = IMFAudioStreamVolume
' IID = 76B1BBDB-4EC8-4F36-B106-70A9316DF593
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMFAudioStreamVolume_INTERFACE_DEFINED)
    %IMFAudioStreamVolume_INTERFACE_DEFINED = 1

$IID_IMFAudioStreamVolume = GUID$("{76B1BBDB-4EC8-4F36-B106-70A9316DF593}")

INTERFACE IMFAudioStreamVolume $IID_IMFAudioStreamVolume

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
   , BYREF pfVolumes AS SINGLE _                        ' __in (dwCount) const float *pfVolumes
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAllVolumes ( _                             ' VTable offset = 28
     BYVAL dwCount AS DWORD _                           ' __in UINT32 dwCount
   , BYREF pfVolumes AS SINGLE _                        ' __out (dwCount) float *pfVolumes
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMFAudioStreamVolume_INTERFACE_DEFINED__ */


$MR_STREAM_VOLUME_SERVICE = GUID$("{F8B5FA2F-32EF-46F5-B172-1321212FB2C4}")


' ########################################################################################
' Interface name = IMFAudioPolicy
' IID = A0638C2B-6465-4395-9AE7-A321A9FD2856
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMFAudioPolicy_INTERFACE_DEFINED)
    %IMFAudioPolicy_INTERFACE_DEFINED = 1

$IID_IMFAudioPolicy = GUID$("{A0638C2B-6465-4395-9AE7-A321A9FD2856}")

INTERFACE IMFAudioPolicy $IID_IMFAudioPolicy

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetGroupingParam ( _                          ' VTable offset = 12
     BYREF rguidClass AS GUID _                         ' __in REFGUID rguidClass
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetGroupingParam ( _                          ' VTable offset = 16
     BYREF pguidClass AS GUID _                         ' __out GUID *pguidClass
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetDisplayName ( _                            ' VTable offset = 20
     BYREF pszName AS WSTRINGZ _                        ' __in LPCWSTR pszName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDisplayName ( _                            ' VTable offset = 24
     BYREF pszName AS DWORD _                           ' __out LPWSTR *pszName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetIconPath ( _                               ' VTable offset = 28
     BYREF pszPath AS WSTRINGZ _                        ' __in LPCWSTR pszPath
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetIconPath ( _                               ' VTable offset = 32
     BYREF pszPath AS DWORD _                           ' __out LPWSTR *pszPath
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMFAudioPolicy_INTERFACE_DEFINED__ */


$MR_AUDIO_POLICY_SERVICE = GUID$("{911FD737-6775-4AB0-A614-297862FDAC88}")


' ########################################################################################
' Interface name = IMFSampleGrabberSinkCallback
' IID = 8C7B80BF-EE42-4B59-B1DF-55668E1BDCA8
' Inherited interface = IMFClockStateSink
' ########################################################################################

#IF NOT %DEF(%IMFSampleGrabberSinkCallback_INTERFACE_DEFINED)
    %IMFSampleGrabberSinkCallback_INTERFACE_DEFINED = 1

$IID_IMFSampleGrabberSinkCallback = GUID$("{8C7B80BF-EE42-4B59-B1DF-55668E1BDCA8}")

INTERFACE IMFSampleGrabberSinkCallback $IID_IMFSampleGrabberSinkCallback

   INHERIT IUnknown

   ' =====================================================================================
   ' IMFClockStateSink methods
   ' =====================================================================================
   METHOD OnClockStart ( _                              ' VTable offset = 12
     BYVAL hnsSystemTime AS QUAD _                      ' __in MFTIME hnsSystemTime
   , BYVAL llClockStartOffset AS QUAD _                 ' __in LONGLONG llClockStartOffset
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnClockStop ( _                               ' VTable offset = 16
     BYVAL hnsSystemTime AS QUAD _                      ' __in MFTIME hnsSystemTime
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnClockPause ( _                              ' VTable offset = 20
     BYVAL hnsSystemTime AS QUAD _                      ' __in MFTIME hnsSystemTime
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnClockRestart ( _                            ' VTable offset = 24
     BYVAL hnsSystemTime AS QUAD _                      ' __in MFTIME hnsSystemTime
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnClockSetRate ( _                            ' VTable offset = 28
     BYVAL hnsSystemTime AS QUAD _                      ' __in MFTIME hnsSystemTime
   , BYVAL flRate AS SINGLE _                           ' __in float flRate
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IMFSampleGrabberSinkCallback methods
   ' =====================================================================================
   METHOD OnSetPresentationClock ( _                    ' VTable offset = 32
     BYVAL pPresentationClock AS IMFPresentationClock _ ' __in IMFPresentationClock *pPresentationClock
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnProcessSample ( _                           ' VTable offset = 36
     BYREF guidMajorMediaType AS GUID _                 ' __in REFGUID guidMajorMediaType
   , BYVAL dwSampleFlags AS DWORD _                     ' __in DWORD dwSampleFlags
   , BYVAL llSampleTime AS QUAD _                       ' __in LONGLONG llSampleTime
   , BYVAL llSampleDuration AS QUAD _                   ' __in LONGLONG llSampleDuration
   , BYVAL pSampleBuffer AS BYTE PTR _                  ' __in (dwSampleSize) const BYTE *pSampleBuffer
   , BYVAL dwSampleSize AS DWORD _                      ' __in DWORD dwSampleSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnShutdown ( _                                ' VTable offset = 42
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMFSampleGrabberSinkCallback_INTERFACE_DEFINED__ */


DECLARE FUNCTION MFCreateSampleGrabberSinkActivate IMPORT "mf.dll" ALIAS "MFCreateSampleGrabberSinkActivate" ( _
   BYVAL pIMFMediaType AS IMFMediaType _                ' __in IMFMediaType *pIMFMediaType
 , BYVAL pIMFSampleGrabberSinkCallback AS IMFSampleGrabberSinkCallback _ ' __in IMFSampleGrabberSinkCallback* pIMFSampleGrabberSinkCallback
 , BYREF ppIActivate AS IMFActivate _                   ' __out IMFActivate** ppIActivate
 ) AS LONG                                              ' HRESULT

$MF_SAMPLEGRABBERSINK_SAMPLE_TIME_OFFSET = GUID$("{62E3D776-8100-4E03-A6E8-BD3857AC9C47}")

'#if (WINVER >= _WIN32_WINNT_WIN7)
$MF_SAMPLEGRABBERSINK_IGNORE_CLOCK = GUID$("{0efda2c0-2b69-4e2e-ab8d-46dcbff7d25d}")

' ########################################################################################
' Interface name = IMFSampleGrabberSinkCallback2
' IID = ca86aa50-c46e-429e-ab27-16d6ac6844cb
' Inherited interface = IMFSampleGrabberSinkCallback
' ########################################################################################

#IF NOT %DEF(%IMFSampleGrabberSinkCallback2_INTERFACE_DEFINED)
    %IMFSampleGrabberSinkCallback2_INTERFACE_DEFINED = 1

$IID_IMFSampleGrabberSinkCallback2 = GUID$("{ca86aa50-c46e-429e-ab27-16d6ac6844cb}")

INTERFACE IMFSampleGrabberSinkCallback2 $IID_IMFSampleGrabberSinkCallback2

   INHERIT IUnknown

   ' =====================================================================================
   ' IMFClockStateSink methods
   ' =====================================================================================
   METHOD OnClockStart ( _                              ' VTable offset = 12
     BYVAL hnsSystemTime AS QUAD _                      ' __in MFTIME hnsSystemTime
   , BYVAL llClockStartOffset AS QUAD _                 ' __in LONGLONG llClockStartOffset
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnClockStop ( _                               ' VTable offset = 16
     BYVAL hnsSystemTime AS QUAD _                      ' __in MFTIME hnsSystemTime
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnClockPause ( _                              ' VTable offset = 20
     BYVAL hnsSystemTime AS QUAD _                      ' __in MFTIME hnsSystemTime
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnClockRestart ( _                            ' VTable offset = 24
     BYVAL hnsSystemTime AS QUAD _                      ' __in MFTIME hnsSystemTime
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnClockSetRate ( _                            ' VTable offset = 28
     BYVAL hnsSystemTime AS QUAD _                      ' __in MFTIME hnsSystemTime
   , BYVAL flRate AS SINGLE _                           ' __in float flRate
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IMFSampleGrabberSinkCallback methods
   ' =====================================================================================
   METHOD OnSetPresentationClock ( _                    ' VTable offset = 32
     BYVAL pPresentationClock AS IMFPresentationClock _ ' __in IMFPresentationClock *pPresentationClock
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnProcessSample ( _                           ' VTable offset = 36
     BYREF guidMajorMediaType AS GUID _                 ' __in REFGUID guidMajorMediaType
   , BYVAL dwSampleFlags AS DWORD _                     ' __in DWORD dwSampleFlags
   , BYVAL llSampleTime AS QUAD _                       ' __in LONGLONG llSampleTime
   , BYVAL llSampleDuration AS QUAD _                   ' __in LONGLONG llSampleDuration
   , BYVAL pSampleBuffer AS BYTE PTR _                  ' __in (dwSampleSize) const BYTE *pSampleBuffer
   , BYVAL dwSampleSize AS DWORD _                      ' __in DWORD dwSampleSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnShutdown ( _                                ' VTable offset = 42
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IMFSampleGrabberSinkCallback2 methods
   ' =====================================================================================
   METHOD OnProcessSampleEx ( _                         ' VTable offset = 46
     BYREF guidMajorMediaType AS GUID _                 ' __in REFGUID guidMajorMediaType
   , BYVAL dwSampleFlags AS DWORD _                     ' __in DWORD dwSampleFlags
   , BYVAL llSampleTime AS QUAD _                       ' __in LONGLONG llSampleTime
   , BYVAL llSampleDuration AS QUAD _                   ' __in LONGLONG llSampleDuration
   , BYVAL pSampleBuffer AS BYTE PTR _                  ' __in const BYTE *pSampleBuffer
   , BYVAL dwSampleSize AS DWORD _                      ' __in DWORD dwSampleSize
   , BYVAL pAttributes AS IMFAttributes _               ' __in IMFAttributes *pAttributes
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMFSampleGrabberSinkCallback2_INTERFACE_DEFINED__ */

$MF_QUALITY_SERVICES = GUID$("{B7E2BE11-2F96-4640-B52C-282365BDF16C}")


' ########################################################################################
' Interface name = IMFWorkQueueServices
' IID = 35FE1BB8-A3A9-40FE-BBEC-EB569C9CCCA3
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMFWorkQueueServices_INTERFACE_DEFINED)
    %IMFWorkQueueServices_INTERFACE_DEFINED = 1

$IID_IMFWorkQueueServices = GUID$("{35FE1BB8-A3A9-40FE-BBEC-EB569C9CCCA3}")

INTERFACE IMFWorkQueueServices $IID_IMFWorkQueueServices

   INHERIT IUnknown

   ' =====================================================================================
   METHOD BeginRegisterTopologyWorkQueuesWithMMCSS ( _  ' VTable offset = 12
     BYVAL pCallback AS IMFAsyncCallback _              ' __in IMFAsyncCallback *pCallback
   , BYVAL pState AS IUnknown _                         ' __in IUnknown *pState
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EndRegisterTopologyWorkQueuesWithMMCSS ( _    ' VTable offset = 16
     BYVAL pResult AS IMFAsyncResult _                  ' __in IMFAsyncResult *pResult
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD BeginUnregisterTopologyWorkQueuesWithMMCSS ( _  ' VTable offset = 20
     BYVAL pCallback AS IMFAsyncCallback _              ' __in IMFAsyncCallback *pCallback
   , BYVAL pState AS IUnknown _                         ' __in IUnknown *pState
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EndUnregisterTopologyWorkQueuesWithMMCSS ( _  ' VTable offset = 24
     BYVAL pResult AS IMFAsyncResult _                  ' __in IMFAsyncResult *pResult
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTopologyWorkQueueMMCSSClass ( _            ' VTable offset = 28
     BYVAL dwTopologyWorkQueueId AS DWORD _             ' __in DWORD dwTopologyWorkQueueId
   , BYREF pwszClass AS WSTRINGZ _                      ' __out (*pcchClass) LPWSTR pwszClass
   , BYREF pcchClass AS DWORD _                         ' __inout DWORD *pcchClass
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTopologyWorkQueueMMCSSTaskId ( _           ' VTable offset = 32
     BYVAL dwTopologyWorkQueueId AS DWORD _             ' __in DWORD dwTopologyWorkQueueId
   , BYREF pdwTaskId AS DWORD _                         ' __out DWORD *pdwTaskId
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD BeginRegisterPlatformWorkQueueWithMMCSS ( _   ' VTable offset = 36
     BYVAL dwPlatformWorkQueue AS DWORD _               ' __in DWORD dwPlatformWorkQueue
   , BYREF wszClass AS WSTRINGZ _                       ' __in LPCWSTR wszClass
   , BYVAL dwTaskId AS DWORD _                          ' __in DWORD dwTaskId
   , BYVAL pCallback AS IMFAsyncCallback _              ' __in IMFAsyncCallback *pCallback
   , BYVAL pState AS IUnknown _                         ' __in IUnknown *pState
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EndRegisterPlatformWorkQueueWithMMCSS ( _     ' VTable offset = 40
     BYVAL pResult AS IMFAsyncResult _                  ' __in IMFAsyncResult *pResult
   , BYREF pdwTaskId AS DWORD _                         ' __out DWORD *pdwTaskId
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD BeginUnregisterPlatformWorkQueueWithMMCSS ( _ ' VTable offset = 44
     BYVAL dwPlatformWorkQueue AS DWORD _               ' __in DWORD dwPlatformWorkQueue
   , BYVAL pCallback AS IMFAsyncCallback _              ' __in IMFAsyncCallback *pCallback
   , BYVAL pState AS IUnknown _                         ' __in IUnknown *pState
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EndUnregisterPlatformWorkQueueWithMMCSS ( _   ' VTable offset = 48
     BYVAL pResult AS IMFAsyncResult _                  ' __in IMFAsyncResult *pResult
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPlaftormWorkQueueMMCSSClass ( _            ' VTable offset = 52
     BYVAL dwPlatformWorkQueueId AS DWORD _             ' __in DWORD dwPlatformWorkQueueId
   , BYREF pwszClass AS WSTRINGZ _                      ' __out (*pcchClass) LPWSTR pwszClass
   , BYVAL pcchClass AS DWORD _                         ' __inout DWORD *pcchClass
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPlatformWorkQueueMMCSSTaskId ( _           ' VTable offset = 56
     BYVAL dwPlatformWorkQueueId AS DWORD _             ' __in DWORD dwPlatformWorkQueueId
   , BYREF pdwTaskId AS DWORD _                         ' __out DWORD *pdwTaskId
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMFWorkQueueServices_INTERFACE_DEFINED__ */

$MF_WORKQUEUE_SERVICES = GUID$("{8E37D489-41E0-413A-9068-287C886D8DDA}")

' enum MF_QUALITY_DROP_MODE
%MF_DROP_MODE_NONE = 0
%MF_DROP_MODE_1    = &H1
%MF_DROP_MODE_2    = &H2
%MF_DROP_MODE_3    = &H3
%MF_DROP_MODE_4    = &H4
%MF_DROP_MODE_5    = &H5
%MF_NUM_DROP_MODES = &H6

' enum MF_QUALITY_LEVEL
%MF_QUALITY_NORMAL         = 0
%MF_QUALITY_NORMAL_MINUS_1 = &H1
%MF_QUALITY_NORMAL_MINUS_2 = &H2
%MF_QUALITY_NORMAL_MINUS_3 = &H3
%MF_QUALITY_NORMAL_MINUS_4 = &H4
%MF_QUALITY_NORMAL_MINUS_5 = &H5
%MF_NUM_QUALITY_LEVELS     = &H6

'#if (WINVER >= _WIN32_WINNT_WIN7)
' enum MF_QUALITY_ADVISE_FLAGS
%MF_QUALITY_CANNOT_KEEP_UP = &H1
'#endif // (WINVER >= _WIN32_WINNT_WIN7)

' ########################################################################################
' Interface name = IMFQualityManager
' IID = 8D009D86-5B9F-4115-B1FC-9F80D52AB8AB
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMFQualityManager_INTERFACE_DEFINED)
    %IMFQualityManager_INTERFACE_DEFINED = 1

$IID_IMFQualityManager = GUID$("{8D009D86-5B9F-4115-B1FC-9F80D52AB8AB}")

INTERFACE IMFQualityManager $IID_IMFQualityManager

   INHERIT IUnknown

   ' =====================================================================================
   METHOD NotifyTopology ( _                            ' VTable offset = 12
     BYVAL pTopology AS IMFTopology _                   ' __in IMFTopology *pTopology
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD NotifyPresentationClock ( _                   ' VTable offset = 16
     BYVAL pClock AS IMFPresentationClock _             ' __in IMFPresentationClock *pClock
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD NotifyProcessInput ( _                        ' VTable offset = 20
     BYVAL pNode AS IMFTopologyNode _                   ' __in IMFTopologyNode *pNode
   , BYVAL lInputIndex AS LONG _                        ' __in long lInputIndex
   , BYVAL pSample AS IMFSample _                       ' __in IMFSample *pSample
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD NotifyProcessOutput ( _                       ' VTable offset = 24
     BYVAL pNode AS IMFTopologyNode _                   ' __in IMFTopologyNode *pNode
   , BYVAL lOutputIndex AS LONG _                       ' __in long lOutputIndex
   , BYVAL pSample AS IMFSample _                       ' __in IMFSample *pSample
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD NotifyQualityEvent ( _                        ' VTable offset = 28
     BYVAL pObject AS IUnknown _                        ' __in IUnknown *pObject
   , BYVAL pEvent AS IMFMediaEvent _                    ' __in IMFMediaEvent *pEvent
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Shutdown ( _                                  ' VTable offset = 32
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMFQualityManager_INTERFACE_DEFINED__ */

DECLARE FUNCTION MFCreateStandardQualityManager IMPORT "mf.dll" ALIAS "MFCreateStandardQualityManager" ( _
   BYREF ppQualityManager AS IMFQualityManager _        ' __out IMFQualityManager **ppQualityManager
 ) AS LONG                                              ' HRESULT

$MF_QUALITY_NOTIFY_PROCESSING_LATENCY = GUID$("{F6B44AF8-604D-46FE-A95D-45479B10C9BC}")
$MF_QUALITY_NOTIFY_SAMPLE_LAG = GUID$("{30D15206-ED2A-4760-BE17-EB4A9F12295C}")


' ########################################################################################
' Interface name = IMFQualityAdvise
' IID = EC15E2E9-E36B-4F7C-8758-77D452EF4CE7
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMFQualityAdvise_INTERFACE_DEFINED)
    %IMFQualityAdvise_INTERFACE_DEFINED = 1

$IID_IMFQualityAdvise = GUID$("{EC15E2E9-E36B-4F7C-8758-77D452EF4CE7}")

INTERFACE IMFQualityAdvise $IID_IMFQualityAdvise

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetDropMode ( _                               ' VTable offset = 12
     BYVAL eDropMode AS LONG _                          ' __in MF_QUALITY_DROP_MODE eDropMode
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetQualityLevel ( _                           ' VTable offset = 16
     BYVAL eQualityLevel AS LONG _                      ' __in MF_QUALITY_LEVEL eQualityLevel
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDropMode ( _                               ' VTable offset = 20
     BYVAL peDropMode AS LONG _                         ' __out MF_QUALITY_DROP_MODE *peDropMode
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetQualityLevel ( _                           ' VTable offset = 24
     BYVAL peQualityLevel AS LONG _                     ' __out MF_QUALITY_LEVEL *peQualityLevel
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DropTime ( _                                  ' VTable offset = 28
     BYVAL hnsAmountToDrop AS QUAD _                    ' __in LONGLONG hnsAmountToDrop
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMFQualityAdvise_INTERFACE_DEFINED__ */

'#if (WINVER >= _WIN32_WINNT_WIN7)

' ########################################################################################
' Interface name = IMFQualityAdvise2
' IID = F3706F0D-8EA2-4886-8000-7155E9EC2EAE
' Inherited interface = IMFQualityAdvise
' ########################################################################################

#IF NOT %DEF(%IMFQualityAdvise2_INTERFACE_DEFINED)
    %IMFQualityAdvise2_INTERFACE_DEFINED = 1

$IID_IMFQualityAdvise2 = GUID$("{F3706F0D-8EA2-4886-8000-7155E9EC2EAE}")

INTERFACE IMFQualityAdvise2 $IID_IMFQualityAdvise2

   INHERIT IUnknown

   ' =====================================================================================
   ' IMFQualityAdvise methods
   ' =====================================================================================
   METHOD SetDropMode ( _                               ' VTable offset = 12
     BYVAL eDropMode AS LONG _                          ' __in MF_QUALITY_DROP_MODE eDropMode
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetQualityLevel ( _                           ' VTable offset = 16
     BYVAL eQualityLevel AS LONG _                      ' __in MF_QUALITY_LEVEL eQualityLevel
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDropMode ( _                               ' VTable offset = 20
     BYVAL peDropMode AS LONG _                         ' __out MF_QUALITY_DROP_MODE *peDropMode
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetQualityLevel ( _                           ' VTable offset = 24
     BYVAL peQualityLevel AS LONG _                     ' __out MF_QUALITY_LEVEL *peQualityLevel
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DropTime ( _                                  ' VTable offset = 28
     BYVAL hnsAmountToDrop AS QUAD _                    ' __in LONGLONG hnsAmountToDrop
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IMFQualityAdvise2 methods
   ' =====================================================================================
   METHOD NotifyQualityEvent ( _                        ' VTable offset = 32
     BYVAL pEvent AS IMFMediaEvent _                    ' __in IMFMediaEvent *pEvent
   , BYREF pdwFlags AS DWORD _                          ' __out DWORD *pdwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMFQualityAdvise2_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IMFQualityAdviseLimits
' IID = dfcd8e4d-30b5-4567-acaa-8eb5b7853dc9
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMFQualityAdviseLimits_INTERFACE_DEFINED)
    %IMFQualityAdviseLimits_INTERFACE_DEFINED = 1

$IID_IMFQualityAdviseLimits = GUID$("{dfcd8e4d-30b5-4567-acaa-8eb5b7853dc9}")

INTERFACE IMFQualityAdviseLimits $IID_IMFQualityAdviseLimits

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetMaximumDropMode ( _                        ' VTable offset = 12
     BYREF peDropMode AS LONG _                         ' __out MF_QUALITY_DROP_MODE *peDropMode
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMinimumQualityLevel ( _                    ' VTable offset = 16
     BYREF peQualityLevel AS LONG _                     ' __out MF_QUALITY_LEVEL *peQualityLevel
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMFQualityAdviseLimits_INTERFACE_DEFINED__ */

'#endif // (WINVER >= _WIN32_WINNT_WIN7)

' ########################################################################################
' Interface name = IMFRealTimeClient
' IID = 2347D60B-3FB5-480C-8803-8DF3ADCD3EF0
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMFRealTimeClient_INTERFACE_DEFINED)
    %IMFRealTimeClient_INTERFACE_DEFINED = 1

$IID_IMFRealTimeClient = GUID$("{2347D60B-3FB5-480C-8803-8DF3ADCD3EF0}")

INTERFACE IMFRealTimeClient $IID_IMFRealTimeClient

   INHERIT IUnknown

   ' =====================================================================================
   METHOD RegisterThreads ( _                           ' VTable offset = 12
     BYVAL dwTaskIndex AS DWORD _                       ' __in DWORD dwTaskIndex
   , BYREF wszClass AS WSTRINGZ _                       ' __in LPCWSTR wszClass
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UnregisterThreads ( _                         ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetWorkQueue ( _                              ' VTable offset = 20
     BYVAL dwWorkQueueId AS DWORD _                     ' __in DWORD dwWorkQueueId
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMFRealTimeClient_INTERFACE_DEFINED__ */

'typedef DWORD MFSequencerElementId;

%MFSEQUENCER_INVALID_ELEMENT_ID = &Hffffffff???

' enum _MFSequencerTopologyFlags
%SequencerTopologyFlags_Last = &H1


' ########################################################################################
' Interface name = IMFSequencerSource
' IID = 197CD219-19CB-4DE1-A64C-ACF2EDCBE59E
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMFSequencerSource_INTERFACE_DEFINED)
    %IMFSequencerSource_INTERFACE_DEFINED = 1

$IID_IMFSequencerSource = GUID$("{197CD219-19CB-4DE1-A64C-ACF2EDCBE59E}")

INTERFACE IMFSequencerSource $IID_IMFSequencerSource

   INHERIT IUnknown

   ' =====================================================================================
   METHOD AppendTopology ( _                            ' VTable offset = 12
     BYVAL pTopology AS IMFTopology _                   ' __in IMFTopology *pTopology
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF pdwId AS DWORD _                             ' __out MFSequencerElementId *pdwId
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DeleteTopology ( _                            ' VTable offset = 16
     BYVAL dwId AS DWORD _                              ' __in MFSequencerElementId dwId
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPresentationContext ( _                    ' VTable offset = 20
     BYVAL pPD AS IMFPresentationDescriptor _           ' __in IMFPresentationDescriptor *pPD
   , BYREF pId AS DWORD _                               ' __out_opt MFSequencerElementId *pId
   , BYVAL ppTopology AS IMFTopology _                  ' __out_opt IMFTopology **ppTopology
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UpdateTopology ( _                            ' VTable offset = 24
     BYVAL dwId AS DWORD _                              ' __in MFSequencerElementId dwId
   , BYVAL pTopology AS IMFTopology _                   ' __in IMFTopology *pTopology
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UpdateTopologyFlags ( _                       ' VTable offset = 28
     BYVAL dwId AS DWORD _                              ' __in MFSequencerElementId dwId
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMFSequencerSource_INTERFACE_DEFINED__ */

$MF_TIME_FORMAT_SEGMENT_OFFSET = GUID$("{C8B8BE77-869C-431D-812E-169693F65A39}")

DECLARE FUNCTION MFCreateSequencerSource IMPORT "mf.dll" ALIAS "MFCreateSequencerSource" ( _
   BYVAL pReserved AS IUnknown _                        ' __in IUnknown *pReserved
 , BYREF ppSequencerSource AS IMFSequencerSource _      ' __out IMFSequencerSource **ppSequencerSource
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION MFCreateSequencerSegmentOffset IMPORT "mf.dll" ALIAS "MFCreateSequencerSegmentOffset" ( _
   BYVAL dwId AS DWORD _                                ' __in MFSequencerElementId dwId
 , BYVAL hnsOffset AS QUAD _                            ' __in MFTIME hnsOffset
 , BYREF pvarSegmentOffset AS PROPVARIANT _             ' __out PROPVARIANT *pvarSegmentOffset
 ) AS LONG                                              ' HRESULT

'#if (WINVER >= _WIN32_WINNT_WIN7)
DECLARE FUNCTION MFCreateAggregateSource IMPORT "mf.dll" ALIAS "MFCreateAggregateSource" ( _
   BYVAL pSourceCollection AS IMFCollection _           ' __in IMFCollection *pSourceCollection
 , BYREF ppAggSource AS IMFMediaSource _                ' __out IMFMediaSource **ppAggSource
 ) AS LONG                                              ' HRESULT
'#endif // (WINVER >= _WIN32_WINNT_WIN7)

' ########################################################################################
' Interface name = IMFMediaSourceTopologyProvider
' IID = 0E1D6009-C9F3-442D-8C51-A42D2D49452F
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMFMediaSourceTopologyProvider_INTERFACE_DEFINED)
    %IMFMediaSourceTopologyProvider_INTERFACE_DEFINED = 1

$IID_IMFMediaSourceTopologyProvider = GUID$("{0E1D6009-C9F3-442D-8C51-A42D2D49452F}")

INTERFACE IMFMediaSourceTopologyProvider $IID_IMFMediaSourceTopologyProvider

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetMediaSourceTopology ( _                    ' VTable offset = 12
     BYVAL pPresentationDescriptor AS IMFPresentationDescriptor _ ' __in IMFPresentationDescriptor *pPresentationDescriptor,
   , BYREF ppTopology AS IMFTopology _                  ' __out IMFTopology **ppTopology
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMFMediaSourceTopologyProvider_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IMFMediaSourcePresentationProvider
' IID = 0E1D600A-C9F3-442D-8C51-A42D2D49452F
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMFMediaSourcePresentationProvider_INTERFACE_DEFINED)
    %IMFMediaSourcePresentationProvider_INTERFACE_DEFINED = 1

$IID_IMFMediaSourcePresentationProvider = GUID$("{0E1D600A-C9F3-442D-8C51-A42D2D49452F}")

INTERFACE IMFMediaSourcePresentationProvider $IID_IMFMediaSourcePresentationProvider

   INHERIT IUnknown

   ' =====================================================================================
   METHOD ForceEndOfPresentation ( _                    ' VTable offset = 12
     BYVAL pPresentationDescriptor AS IMFPresentationDescriptor _ ' __in IMFPresentationDescriptor *pPresentationDescriptor
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMFMediaSourcePresentationProvider_INTERFACE_DEFINED__ */


$MF_SOURCE_PRESENTATION_PROVIDER_SERVICE = GUID$("{E002AADC-F4AF-4EE5-9847-053EDF840426}")

' // Size = 8 bytes
UNION MFTOPONODE_ATTRIBUTE_UPDATE_UNION
   u32 AS DWORD    ' UINT32
   u64 AS QUAD     ' UINT64
   d   AS DOUBLE   ' double
END UNION

' // Size = 40 bytes
TYPE MFTOPONODE_ATTRIBUTE_UPDATE QWORD FILL
   NodeId           AS QUAD   ' TOPOID
   guidAttributeKey AS GUID   ' GUID
   attrType         AS LONG   ' MF_ATTRIBUTE_TYPE
   MFTOPONODE_ATTRIBUTE_UPDATE_UNION
END TYPE


' ########################################################################################
' Interface name = IMFTopologyNodeAttributeEditor
' IID = 676AA6DD-238A-410D-BB99-65668D01605A
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMFTopologyNodeAttributeEditor_INTERFACE_DEFINED)
    %IMFTopologyNodeAttributeEditor_INTERFACE_DEFINED = 1

$IID_IMFTopologyNodeAttributeEditor = GUID$("{676AA6DD-238A-410D-BB99-65668D01605A}")

INTERFACE IMFTopologyNodeAttributeEditor $IID_IMFTopologyNodeAttributeEditor

   INHERIT IUnknown

   ' =====================================================================================
   METHOD UpdateNodeAttributes ( _                      ' VTable offset = 12
     BYVAL TopoId AS QUAD _                             ' __in TOPOID TopoId
   , BYVAL cUpdates AS DWORD _                          ' __in DWORD cUpdates
   , BYREF pUpdates AS MFTOPONODE_ATTRIBUTE_UPDATE _    ' __in (cUpdates) MFTOPONODE_ATTRIBUTE_UPDATE *pUpdates
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMFTopologyNodeAttributeEditor_INTERFACE_DEFINED__ */


$MF_TOPONODE_ATTRIBUTE_EDITOR_SERVICE = GUID$("{65656E1A-077F-4472-83EF-316F11D5087A}")

' // Size = 8 bytes
TYPE MF_LEAKY_BUCKET_PAIR DWORD
   dwBitrate      AS DWORD   ' DWORD
   msBufferWindow AS DWORD   ' DWORD
END TYPE

' // Size = 56 bytes
TYPE MFBYTESTREAM_BUFFERING_PARAMS   ' Must be 8 byte aligned
   cbTotalFileSize                AS QUAD                       ' QWORD
   cbPlayableDataSize             AS QUAD                       ' QWORD
   prgBuckets                     AS MF_LEAKY_BUCKET_PAIR PTR   ' MF_LEAKY_BUCKET_PAIR*
   cBuckets                       AS DWORD                      ' DWORD
   qwNetBufferingTime             AS QUAD                       ' QWORD
   qwExtraBufferingTimeDuringSeek AS QUAD                       ' QWORD
   qwPlayDuration                 AS QUAD                       ' QWORD
   dRate                          AS SINGLE                     ' float
   alignment__                    AS DWORD
END TYPE


' ########################################################################################
' Interface name = IMFByteStreamBuffering
' IID = 6D66D782-1D4F-4DB7-8C63-CB8C77F1EF5E
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMFByteStreamBuffering_INTERFACE_DEFINED)
    %IMFByteStreamBuffering_INTERFACE_DEFINED = 1

$IID_IMFByteStreamBuffering = GUID$("{6D66D782-1D4F-4DB7-8C63-CB8C77F1EF5E}")

INTERFACE IMFByteStreamBuffering $IID_IMFByteStreamBuffering

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetBufferingParams ( _                        ' VTable offset = 12
     BYREF pParams AS MFBYTESTREAM_BUFFERING_PARAMS _   ' __in MFBYTESTREAM_BUFFERING_PARAMS *pParams
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnableBuffering ( _                           ' VTable offset = 16
     BYVAL fEnable AS LONG _                            ' __in BOOL fEnable
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD StopBuffering ( _                             ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMFByteStreamBuffering_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IMFByteStreamCacheControl
' IID = F5042EA4-7A96-4a75-AA7B-2BE1EF7F88D5
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMFByteStreamCacheControl_INTERFACE_DEFINED)
    %IMFByteStreamCacheControl_INTERFACE_DEFINED = 1

$IID_IMFByteStreamCacheControl = GUID$("{F5042EA4-7A96-4a75-AA7B-2BE1EF7F88D5}")

INTERFACE IMFByteStreamCacheControl $IID_IMFByteStreamCacheControl

   INHERIT IUnknown

   ' =====================================================================================
   METHOD StopBackgroundTransfer ( _                    ' VTable offset = 12
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMFByteStreamCacheControl_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IMFNetCredential
' IID = 5B87EF6A-7ED8-434F-BA0E-184FAC1628D1
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMFNetCredential_INTERFACE_DEFINED)
    %IMFNetCredential_INTERFACE_DEFINED = 1

$IID_IMFNetCredential = GUID$("{5B87EF6A-7ED8-434F-BA0E-184FAC1628D1}")

INTERFACE IMFNetCredential $IID_IMFNetCredential

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetUser ( _                                   ' VTable offset = 12
     BYVAL pbData AS BYTE PTR _                         ' __in (cbData) BYTE *pbData
   , BYVAL cbData AS DWORD _                            ' __in DWORD cbData
   , BYVAL fDataIsEncrypted AS DWORD _                  ' __in BOOL fDataIsEncrypted
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPassword ( _                               ' VTable offset = 16
     BYVAL pbData AS BYTE PTR _                         ' __in (cbData) BYTE *pbData
   , BYVAL cbData AS DWORD _                            ' __in DWORD cbData
   , BYVAL fDataIsEncrypted AS LONG _                   ' __in BOOL fDataIsEncrypted
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetUser ( _                                   ' VTable offset = 20
     BYVAL pbData AS BYTE PTR _                         ' __out  BYTE *pbData
   , BYREF pcbData AS DWORD _                           ' __inout DWORD *pcbData
   , BYVAL fEncryptData AS LONG _                       ' __in BOOL fEncryptData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPassword ( _                               ' VTable offset = 24
     BYVAL pbData AS BYTE PTR _                         ' __out BYTE *pbData
   , BYREF pcbData AS DWORD _                           ' __inout DWORD *pcbData
   , BYVAL fEncryptData AS LONG _                       ' __in BOOL fEncryptData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD LoggedOnUser ( _                              ' VTable offset = 28
     BYVAL pfLoggedOnUser AS LONG _                     ' BOOL *pfLoggedOnUser
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMFNetCredential_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IMFNetCredentialManager
' IID = 5B87EF6B-7ED8-434F-BA0E-184FAC1628D1
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMFNetCredentialManager_INTERFACE_DEFINED)
    %IMFNetCredentialManager_INTERFACE_DEFINED = 1

' // Size = 32 bytes
TYPE MFNetCredentialManagerGetParam DWORD
   hrOp               AS LONG           ' HRESULT
   fAllowLoggedOnUser AS LONG           ' BOOL
   fClearTextPackage  AS LONG           ' BOOL
   pszUrl             AS WSTRINGZ PTR   ' LPCWSTR
   pszSite            AS WSTRINGZ PTR   ' LPCWSTR
   pszRealm           AS WSTRINGZ PTR   ' LPCWSTR
   pszPackage         AS WSTRINGZ PTR   ' LPCWSTR
   nRetries           AS LONG           ' LONG
END TYPE

$IID_IMFNetCredentialManager = GUID$("{5B87EF6B-7ED8-434F-BA0E-184FAC1628D1}")

INTERFACE IMFNetCredentialManager $IID_IMFNetCredentialManager

   INHERIT IUnknown

   ' =====================================================================================
   METHOD BeginGetCredentials ( _                       ' VTable offset = 12
     BYREF pParam AS MFNetCredentialManagerGetParam _   ' __in MFNetCredentialManagerGetParam *pParam
   , BYVAL pCallback AS IMFAsyncCallback _              ' __in IMFAsyncCallback *pCallback
   , BYVAL pState AS IUnknown _                         ' __in IUnknown *pState
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EndGetCredentials ( _                         ' VTable offset = 16
     BYVAL pResult AS IMFAsyncResult _                  ' __in IMFAsyncResult *pResult
   , BYREF ppCred AS IMFNetCredential _                 ' __out IMFNetCredential **ppCred
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetGood ( _                                   ' VTable offset = 16
     BYVAL pCred AS IMFNetCredential _                  ' __in IMFNetCredential *pCred
   , BYVAL fGood AS LONG _                              ' __in BOOL fGood
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMFNetCredentialManager_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IMFNetCredentialCache
' IID = 5B87EF6C-7ED8-434F-BA0E-184FAC1628D1
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMFNetCredentialCache_INTERFACE_DEFINED)
    %IMFNetCredentialCache_INTERFACE_DEFINED = 1

' enum MFNetCredentialRequirements
%REQUIRE_PROMPT = &H1

' enum MFNetCredentialOptions
%MFNET_CREDENTIAL_SAVE               = &H1
%MFNET_CREDENTIAL_DONT_CACHE         = &H2
%MFNET_CREDENTIAL_ALLOW_CLEAR_TEXT   = &H4

' enum MFNetAuthenticationFlags
%MFNET_AUTHENTICATION_PROXY          = &H1
%MFNET_AUTHENTICATION_CLEAR_TEXT     = &H2
%MFNET_AUTHENTICATION_LOGGED_ON_USER = &H4

$IID_IMFNetCredentialCache = GUID$("{5B87EF6C-7ED8-434F-BA0E-184FAC1628D1}")

INTERFACE IMFNetCredentialCache $IID_IMFNetCredentialCache

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetCredential ( _                             ' VTable offset = 12
     BYREF pszUrl AS WSTRINGZ _                         ' __in LPCWSTR pszUrl
   , BYREF pszRealm AS WSTRINGZ _                       ' __in LPCWSTR pszRealm
   , BYVAL dwAuthenticationFlags AS DWORD _             ' __in DWORD dwAuthenticationFlags
   , BYREF ppCred AS IMFNetCredential _                 ' __out IMFNetCredential **ppCred
   , BYREF pdwRequirementsFlags AS DWORD _              ' __out DWORD *pdwRequirementsFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetGood ( _                                   ' VTable offset = 16
     BYVAL pCred AS IMFNetCredential _                  ' __in IMFNetCredential *pCred
   , BYVAL fGood AS LONG _                              ' __in BOOL fGood
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetUserOptions ( _                            ' VTable offset = 20
     BYVAL pCred AS IMFNetCredential _                  ' __in IMFNetCredential *pCred
   , BYVAL dwOptionsFlags AS DWORD _                    ' __in DWORD dwOptionsFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMFNetCredentialCache_INTERFACE_DEFINED__ */


DECLARE FUNCTION MFCreateCredentialCache IMPORT "mf.dll" ALIAS "MFCreateCredentialCache" ( _
   BYREF ppCache AS IMFNetCredentialCache _             ' __out IMFNetCredentialCache ** ppCache
 ) AS LONG                                              ' HRESULT

'#if (WINVER >= _WIN32_WINNT_WIN7)

' ########################################################################################
' Interface name = IMFSSLCertificateManager
' IID = 61f7d887-1230-4a8b-aeba-8ad434d1a64d
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMFSSLCertificateManager_INTERFACE_DEFINED)
    %IMFSSLCertificateManager_INTERFACE_DEFINED = 1

$IID_IMFSSLCertificateManager = GUID$("{61f7d887-1230-4a8b-aeba-8ad434d1a64d}")

INTERFACE IMFSSLCertificateManager $IID_IMFSSLCertificateManager

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetClientCertificate ( _                      ' VTable offset = 12
     BYREF pszURL AS WSTRINGZ _                         ' __in LPCWSTR pszURL
   , BYREF ppbData AS DWORD _                           ' __out BYTE **ppbData
   , BYREF pcbData AS DWORD _                           ' __out DWORD *pcbData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD BeginGetClientCertificate ( _                 ' VTable offset = 16
     BYREF pszURL AS WSTRINGZ _                         ' __in LPCWSTR pszURL
   , BYVAL pCallback AS IMFAsyncCallback _              ' __in IMFAsyncCallback *pCallback
   , BYVAL pState AS IUnknown _                         ' __in IUnknown *pState
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EndGetClientCertificate ( _                   ' VTable offset = 20
     BYVAL pResult AS IMFAsyncResult _                  ' __in IMFAsyncResult *pResult
   , BYREF ppbData AS DWORD _                           ' __out BYTE **ppbData
   , BYREF pcbData AS DWORD _                           ' __out DWORD *pcbData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCertificatePolicy ( _                      ' VTable offset = 24
     BYREF pszURL AS WSTRINGZ _                         ' __in LPCWSTR pszURL
   , BYREF pfOverrideAutomaticCheck AS LONG _           ' __out BOOL *pfOverrideAutomaticCheck
   , BYREF pfClientCertificateAvailable AS LONG _       ' __out BOOL *pfClientCertificateAvailable
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnServerCertificate ( _                       ' VTable offset = 28
     BYREF pszURL AS WSTRINGZ _                         ' __in LPCWSTR pszURL
   , BYVAL pbData AS BYTE PTR _                         ' __in BYTE *pbData
   , BYVAL cbData AS DWORD _                            ' __in DWORD cbData
   , BYREF pfIsGood AS LONG _                           ' __out BOOL *pfIsGood
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMFSSLCertificateManager_INTERFACE_DEFINED__ */

$MFNETSOURCE_SSLCERTIFICATE_MANAGER = GUID$("{55e6cb27-e69b-4267-940c-2d7ec5bb8a0f}")
'#endif // (WINVER >= _WIN32_WINNT_WIN7)

' ########################################################################################
' Interface name = IMFSourceOpenMonitor
' IID = 059054B3-027C-494C-A27D-9113291CF87F
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMFSourceOpenMonitor_INTERFACE_DEFINED)
    %IMFSourceOpenMonitor_INTERFACE_DEFINED = 1

$IID_IMFSourceOpenMonitor = GUID$("{059054B3-027C-494C-A27D-9113291CF87F}")

INTERFACE IMFSourceOpenMonitor $IID_IMFSourceOpenMonitor

   INHERIT IUnknown

   ' =====================================================================================
   METHOD OnSourceEvent ( _                             ' VTable offset = 12
     BYVAL pEvent AS IMFMediaEvent _                    ' __in IMFMediaEvent *pEvent
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMFSourceOpenMonitor_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IMFNetProxyLocator
' IID = E9CD0383-A268-4BB4-82DE-658D53574D41
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMFNetProxyLocator_INTERFACE_DEFINED)
    %IMFNetProxyLocator_INTERFACE_DEFINED = 1

$IID_IMFNetProxyLocator = GUID$("{E9CD0383-A268-4BB4-82DE-658D53574D41}")

INTERFACE IMFNetProxyLocator $IID_IMFNetProxyLocator

   INHERIT IUnknown

   ' =====================================================================================
   METHOD FindFirstProxy ( _                            ' VTable offset = 12
     BYREF pszHost AS WSTRINGZ _                        ' __in LPCWSTR pszHost
   , BYREF pszUrl AS WSTRINGZ _                         ' __in LPCWSTR pszUrl
   , BYVAL fReserved AS LONG _                          ' __in BOOL fReserved
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD FindNextProxy ( _                             ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RegisterProxyResult ( _                       ' VTable offset = 20
     BYVAL hrOp AS LONG _                               ' __in HRESULT hrOp
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCurrentProxy ( _                           ' VTable offset = 24
     BYREF pszStr AS WSTRINGZ _                         ' __out LPWSTR pszStr
   , BYREF pcchStr AS DWORD _                           ' __inout DWORD *pcchStr
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 28
     BYREF ppProxyLocator AS IMFNetProxyLocator _       ' __out IMFNetProxyLocator **ppProxyLocator
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMFNetProxyLocator_INTERFACE_DEFINED__ */


DECLARE FUNCTION MFCreateProxyLocator IMPORT "mf.dll" ALIAS "MFCreateProxyLocator" ( _
   BYREF pszProtocol AS WSTRINGZ _                      ' __in LPCWSTR pszProtocol
 , BYVAL pProxyConfig AS IPropertyStore _               ' __in IPropertyStore* pProxyConfig
 , BYREF ppProxyLocator AS IMFNetProxyLocator _         ' __out IMFNetProxyLocator** ppProxyLocator
 ) AS LONG                                              ' HRESULT


' ########################################################################################
' Interface name = IMFNetProxyLocatorFactory
' IID = E9CD0384-A268-4BB4-82DE-658D53574D41
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMFNetProxyLocatorFactory_INTERFACE_DEFINED)
    %IMFNetProxyLocatorFactory_INTERFACE_DEFINED = 1

$IID_IMFNetProxyLocatorFactory = GUID$("{E9CD0384-A268-4BB4-82DE-658D53574D41}")

INTERFACE IMFNetProxyLocatorFactory $IID_IMFNetProxyLocatorFactory

   INHERIT IUnknown

   ' =====================================================================================
   METHOD CreateProxyLocator ( _                        ' VTable offset = 12
     BYREF pszProtocol AS WSTRINGZ _                    ' __in LPCWSTR pszProtocol
   , BYREF ppProxyLocator AS IMFNetProxyLocator _       ' __out IMFNetProxyLocator **ppProxyLocator
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMFNetProxyLocatorFactory_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IMFSaveJob
' IID = E9931663-80BF-4C6E-98AF-5DCF58747D1F
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMFSaveJob_INTERFACE_DEFINED)
    %IMFSaveJob_INTERFACE_DEFINED = 1

$IID_IMFSaveJob = GUID$("{E9931663-80BF-4C6E-98AF-5DCF58747D1F}")

INTERFACE IMFSaveJob $IID_IMFSaveJob

   INHERIT IUnknown

   ' =====================================================================================
   METHOD BeginSave ( _                                 ' VTable offset = 12
     BYVAL pStream AS IMFByteStream _                   ' __in IMFByteStream *pStream
   , BYVAL pCallback AS IMFAsyncCallback _              ' __in IMFAsyncCallback *pCallback
   , BYVAL pState AS IUnknown _                         ' __in IUnknown *pState
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EndSave ( _                                   ' VTable offset = 16
     BYVAL pResult AS IMFAsyncResult _                  ' __in IMFAsyncResult *pResult
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CancelSave ( _                                ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetProgress ( _                               ' VTable offset = 24
     BYREF pdwPercentComplete AS DWORD _                ' __out DWORD *pdwPercentComplete
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMFSaveJob_INTERFACE_DEFINED__ */


$MFNET_SAVEJOB_SERVICE = GUID$("{B85A587F-3D02-4E52-9565-55D3EC1E7FF7}")

' enum MFNETSOURCE_PROTOCOL_TYPE
%MFNETSOURCE_UNDEFINED = 0
%MFNETSOURCE_HTTP      = &H1
%MFNETSOURCE_RTSP      = &H2
%MFNETSOURCE_FILE      = &H3
%MFNETSOURCE_MULTICAST = &H4


' ########################################################################################
' Interface name = IMFNetSchemeHandlerConfig
' IID = 7BE19E73-C9BF-468A-AC5A-A5E8653BEC87
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMFNetSchemeHandlerConfig_INTERFACE_DEFINED)
    %IMFNetSchemeHandlerConfig_INTERFACE_DEFINED = 1

$IID_IMFNetSchemeHandlerConfig = GUID$("{7BE19E73-C9BF-468A-AC5A-A5E8653BEC87}")

INTERFACE IMFNetSchemeHandlerConfig $IID_IMFNetSchemeHandlerConfig

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetNumberOfSupportedProtocols ( _             ' VTable offset = 12
     BYREF pcProtocols AS DWORD _                       ' __out ULONG *pcProtocols
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSupportedProtocolType ( _                  ' VTable offset = 16
     BYVAL nProtocolIndex AS DWORD _                    ' __in ULONG nProtocolIndex
   , BYREF pnProtocolType AS LONG _                     ' __out MFNETSOURCE_PROTOCOL_TYPE *pnProtocolType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ResetProtocolRolloverSettings ( _             ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMFNetSchemeHandlerConfig_INTERFACE_DEFINED__ */


DECLARE FUNCTION MFCreateNetSchemePlugin IMPORT "mf.dll" ALIAS "MFCreateNetSchemePlugin" ( _
   BYREF riid AS GUID _                                 ' __in  REFIID riid
 , BYREF ppvHandler AS IUnknown _                       ' __out LPVOID *ppvHandler
 ) AS LONG                                              ' HRESULT

' enum MFNETSOURCE_TRANSPORT_TYPE
%MFNETSOURCE_UDP = 0
%MFNETSOURCE_TCP = %MFNETSOURCE_UDP + 1

' enum MFNETSOURCE_CACHE_STATE
%MFNETSOURCE_CACHE_UNAVAILABLE     = 0
%MFNETSOURCE_CACHE_ACTIVE_WRITING  = %MFNETSOURCE_CACHE_UNAVAILABLE    + 1
%MFNETSOURCE_CACHE_ACTIVE_COMPLETE = %MFNETSOURCE_CACHE_ACTIVE_WRITING + 1

' enum MFNETSOURCE_STATISTICS_IDS
%MFNETSOURCE_RECVPACKETS_ID              = 0
%MFNETSOURCE_LOSTPACKETS_ID              = %MFNETSOURCE_RECVPACKETS_ID              + 1
%MFNETSOURCE_RESENDSREQUESTED_ID         = %MFNETSOURCE_LOSTPACKETS_ID              + 1
%MFNETSOURCE_RESENDSRECEIVED_ID          = %MFNETSOURCE_RESENDSREQUESTED_ID         + 1
%MFNETSOURCE_RECOVEREDBYECCPACKETS_ID    = %MFNETSOURCE_RESENDSRECEIVED_ID          + 1
%MFNETSOURCE_RECOVEREDBYRTXPACKETS_ID    = %MFNETSOURCE_RECOVEREDBYECCPACKETS_ID    + 1
%MFNETSOURCE_OUTPACKETS_ID               = %MFNETSOURCE_RECOVEREDBYRTXPACKETS_ID    + 1
%MFNETSOURCE_RECVRATE_ID                 = %MFNETSOURCE_OUTPACKETS_ID               + 1
%MFNETSOURCE_AVGBANDWIDTHBPS_ID          = %MFNETSOURCE_RECVRATE_ID                 + 1
%MFNETSOURCE_BYTESRECEIVED_ID            = %MFNETSOURCE_AVGBANDWIDTHBPS_ID          + 1
%MFNETSOURCE_PROTOCOL_ID                 = %MFNETSOURCE_BYTESRECEIVED_ID            + 1
%MFNETSOURCE_TRANSPORT_ID                = %MFNETSOURCE_PROTOCOL_ID                 + 1
%MFNETSOURCE_CACHE_STATE_ID              = %MFNETSOURCE_TRANSPORT_ID                + 1
%MFNETSOURCE_LINKBANDWIDTH_ID            = %MFNETSOURCE_CACHE_STATE_ID              + 1
%MFNETSOURCE_CONTENTBITRATE_ID           = %MFNETSOURCE_LINKBANDWIDTH_ID            + 1
%MFNETSOURCE_SPEEDFACTOR_ID              = %MFNETSOURCE_CONTENTBITRATE_ID           + 1
%MFNETSOURCE_BUFFERSIZE_ID               = %MFNETSOURCE_SPEEDFACTOR_ID              + 1
%MFNETSOURCE_BUFFERPROGRESS_ID           = %MFNETSOURCE_BUFFERSIZE_ID               + 1
%MFNETSOURCE_LASTBWSWITCHTS_ID           = %MFNETSOURCE_BUFFERPROGRESS_ID           + 1
%MFNETSOURCE_SEEKRANGESTART_ID           = %MFNETSOURCE_LASTBWSWITCHTS_ID           + 1
%MFNETSOURCE_SEEKRANGEEND_ID             = %MFNETSOURCE_SEEKRANGESTART_ID           + 1
%MFNETSOURCE_BUFFERINGCOUNT_ID           = %MFNETSOURCE_SEEKRANGEEND_ID             + 1
%MFNETSOURCE_INCORRECTLYSIGNEDPACKETS_ID = %MFNETSOURCE_BUFFERINGCOUNT_ID           + 1
%MFNETSOURCE_SIGNEDSESSION_ID            = %MFNETSOURCE_INCORRECTLYSIGNEDPACKETS_ID + 1
%MFNETSOURCE_MAXBITRATE_ID               = %MFNETSOURCE_SIGNEDSESSION_ID            + 1
%MFNETSOURCE_RECEPTION_QUALITY_ID        = %MFNETSOURCE_MAXBITRATE_ID               + 1
%MFNETSOURCE_RECOVEREDPACKETS_ID         = %MFNETSOURCE_RECEPTION_QUALITY_ID        + 1
%MFNETSOURCE_VBR_ID                      = %MFNETSOURCE_RECOVEREDPACKETS_ID         + 1
%MFNETSOURCE_DOWNLOADPROGRESS_ID         = %MFNETSOURCE_VBR_ID                      + 1
%MFNETSOURCE_UNPREDEFINEDPROTOCOLNAME_ID = %MFNETSOURCE_DOWNLOADPROGRESS_ID         + 1

$MFNETSOURCE_STATISTICS_SERVICE = GUID$("{3CB1F275-0505-4C5D-AE71-0A556344EFA1}")
$MFNETSOURCE_STATISTICS = GUID$("{3CB1F274-0505-4C5D-AE71-0A556344EFA1}")
$MFNETSOURCE_BUFFERINGTIME = GUID$("{3CB1F276-0505-4C5D-AE71-0A556344EFA1}")
$MFNETSOURCE_ACCELERATEDSTREAMINGDURATION = GUID$("{3CB1F277-0505-4C5D-AE71-0A556344EFA1}")
$MFNETSOURCE_MAXUDPACCELERATEDSTREAMINGDURATION = GUID$("{4AAB2879-BBE1-4994-9FF0-5495BD250129}")
$MFNETSOURCE_MAXBUFFERTIMEMS = GUID$("{408B24E6-4038-4401-B5B2-FE701A9EBF10}")
$MFNETSOURCE_CONNECTIONBANDWIDTH = GUID$("{3CB1F278-0505-4C5D-AE71-0A556344EFA1}")
$MFNETSOURCE_CACHEENABLED = GUID$("{3CB1F279-0505-4C5D-AE71-0A556344EFA1}")
$MFNETSOURCE_AUTORECONNECTLIMIT = GUID$("{3CB1F27A-0505-4C5D-AE71-0A556344EFA1}")
$MFNETSOURCE_RESENDSENABLED = GUID$("{3CB1F27B-0505-4C5D-AE71-0A556344EFA1}")
$MFNETSOURCE_THINNINGENABLED = GUID$("{3CB1F27C-0505-4C5D-AE71-0A556344EFA1}")
$MFNETSOURCE_PROTOCOL = GUID$("{3CB1F27D-0505-4C5D-AE71-0A556344EFA1}")
$MFNETSOURCE_TRANSPORT = GUID$("{3CB1F27E-0505-4C5D-AE71-0A556344EFA1}")
'#if (WINVER >= _WIN32_WINNT_WIN7)
$MFNETSOURCE_PREVIEWMODEENABLED = GUID$("{3CB1F27F-0505-4C5D-AE71-0A556344EFA1}")
'#endif // (WINVER >= _WIN32_WINNT_WIN7)
$MFNETSOURCE_CREDENTIAL_MANAGER = GUID$("{3CB1F280-0505-4C5D-AE71-0A556344EFA1}")
$MFNETSOURCE_PPBANDWIDTH = GUID$("{3CB1F281-0505-4C5D-AE71-0A556344EFA1}")
$MFNETSOURCE_AUTORECONNECTPROGRESS = GUID$("{3CB1F282-0505-4C5D-AE71-0A556344EFA1}")
$MFNETSOURCE_PROXYLOCATORFACTORY = GUID$("{3CB1F283-0505-4C5D-AE71-0A556344EFA1}")
$MFNETSOURCE_BROWSERUSERAGENT = GUID$("{3CB1F28B-0505-4C5D-AE71-0A556344EFA1}")
$MFNETSOURCE_BROWSERWEBPAGE = GUID$("{3CB1F28C-0505-4C5D-AE71-0A556344EFA1}")
$MFNETSOURCE_PLAYERVERSION = GUID$("{3CB1F28D-0505-4C5D-AE71-0A556344EFA1}")
$MFNETSOURCE_PLAYERID = GUID$("{3CB1F28E-0505-4C5D-AE71-0A556344EFA1}")
$MFNETSOURCE_HOSTEXE = GUID$("{3CB1F28F-0505-4C5D-AE71-0A556344EFA1}")
$MFNETSOURCE_HOSTVERSION = GUID$("{3CB1F291-0505-4C5D-AE71-0A556344EFA1}")
$MFNETSOURCE_PLAYERUSERAGENT = GUID$("{3CB1F292-0505-4C5D-AE71-0A556344EFA1}")
'#if (WINVER >= _WIN32_WINNT_WIN7)
$MFNETSOURCE_CLIENTGUID = GUID$("{60A2C4A6-F197-4C14-A5BF-88830D2458AF}")
'#endif // (WINVER >= _WIN32_WINNT_WIN7)
$MFNETSOURCE_LOGURL = GUID$("{3CB1F293-0505-4C5D-AE71-0A556344EFA1}")
$MFNETSOURCE_ENABLE_UDP = GUID$("{3CB1F294-0505-4C5D-AE71-0A556344EFA1}")
$MFNETSOURCE_ENABLE_TCP = GUID$("{3CB1F295-0505-4C5D-AE71-0A556344EFA1}")
$MFNETSOURCE_ENABLE_RTSP = GUID$("{3CB1F298-0505-4C5D-AE71-0A556344EFA1}")
$MFNETSOURCE_ENABLE_HTTP = GUID$("{3CB1F299-0505-4C5D-AE71-0A556344EFA1}")
$MFNETSOURCE_ENABLE_STREAMING = GUID$("{3CB1F29C-0505-4C5D-AE71-0A556344EFA1}")
$MFNETSOURCE_ENABLE_DOWNLOAD = GUID$("{3CB1F29D-0505-4C5D-AE71-0A556344EFA1}")
$MFNETSOURCE_UDP_PORT_RANGE = GUID$("{3CB1F29A-0505-4C5D-AE71-0A556344EFA1}")
$MFNETSOURCE_PROXYINFO = GUID$("{3CB1F29B-0505-4C5D-AE71-0A556344EFA1}")
$MFNETSOURCE_DRMNET_LICENSE_REPRESENTATION = GUID$("{47EAE1BD-BDFE-42E2-82F3-54A48C17962D}")
$MFNETSOURCE_PROXYSETTINGS = GUID$("{3CB1F287-0505-4C5D-AE71-0A556344EFA1}")
$MFNETSOURCE_PROXYHOSTNAME = GUID$("{3CB1F284-0505-4C5D-AE71-0A556344EFA1}")
$MFNETSOURCE_PROXYPORT = GUID$("{3CB1F288-0505-4C5D-AE71-0A556344EFA1}")
$MFNETSOURCE_PROXYEXCEPTIONLIST = GUID$("{3CB1F285-0505-4C5D-AE71-0A556344EFA1}")
$MFNETSOURCE_PROXYBYPASSFORLOCAL = GUID$("{3CB1F286-0505-4C5D-AE71-0A556344EFA1}")
$MFNETSOURCE_PROXYRERUNAUTODETECTION = GUID$("{3CB1F289-0505-4C5D-AE71-0A556344EFA1}")
'#if (WINVER >= _WIN32_WINNT_WIN7)
$MFNETSOURCE_STREAM_LANGUAGE = GUID$("{9AB44318-F7CD-4F2D-8D6D-FA35B492CECB}")
$MFNETSOURCE_LOGPARAMS = GUID$("{64936AE8-9418-453A-8CDA-3E0A668B353B}")
'#endif // (WINVER >= _WIN32_WINNT_WIN7)

' enum MFNET_PROXYSETTINGS
%MFNET_PROXYSETTING_NONE    = 0
%MFNET_PROXYSETTING_MANUAL  = 1
%MFNET_PROXYSETTING_AUTO    = 2
%MFNET_PROXYSETTING_BROWSER = 3


' ########################################################################################
' Interface name = IMFSchemeHandler
' IID = 6D4C7B74-52A0-4BB7-B0DB-55F29F47A668
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMFSchemeHandler_INTERFACE_DEFINED)
    %IMFSchemeHandler_INTERFACE_DEFINED = 1

$IID_IMFSchemeHandler = GUID$("{6D4C7B74-52A0-4BB7-B0DB-55F29F47A668}")

INTERFACE IMFSchemeHandler $IID_IMFSchemeHandler

   INHERIT IUnknown

   ' =====================================================================================
   METHOD BeginCreateObject ( _                         ' VTable offset = 12
     BYREF pwszURL AS WSTRINGZ _                        ' __in LPCWSTR pwszURL
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYVAL pProps AS IPropertyStore _                   ' __in IPropertyStore *pProps
   , BYREF ppIUnknownCancelCookie AS IUnknown _         ' __out IUnknown **ppIUnknownCancelCookie
   , BYVAL pCallback AS IMFAsyncCallback _              ' __in IMFAsyncCallback *pCallback
   , BYVAL punkState AS IUnknown _                      ' __in IUnknown *punkState
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EndCreateObject ( _                           ' VTable offset = 16
     BYVAL pResult AS IMFAsyncResult _                  ' __in IMFAsyncResult *pResult
   , BYREF pObjectType AS LONG _                        ' __out MF_OBJECT_TYPE *pObjectType
   , BYREF ppObject AS IUnknown _                       ' __out IUnknown **ppObject
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CancelObjectCreation ( _                      ' VTable offset = 20
     BYVAL pIUnknownCancelCookie AS IUnknown _          ' __in IUnknown *pIUnknownCancelCookie
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMFSchemeHandler_INTERFACE_DEFINED__ */

'#if (WINVER >= _WIN32_WINNT_WIN7)
$MF_BYTESTREAMHANDLER_ACCEPTS_SHARE_WRITE = GUID$("{A6E1F733-3001-4915-8150-1558A2180EC8}")
'#endif // (WINVER >= _WIN32_WINNT_WIN7)

' ########################################################################################
' Interface name = IMFByteStreamHandler
' IID = BB420AA4-765B-4A1F-91FE-D6A8A143924C
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMFByteStreamHandler_INTERFACE_DEFINED)
    %IMFByteStreamHandler_INTERFACE_DEFINED = 1

$IID_IMFByteStreamHandler = GUID$("{BB420AA4-765B-4A1F-91FE-D6A8A143924C}")

INTERFACE IMFByteStreamHandler $IID_IMFByteStreamHandler

   INHERIT IUnknown

   ' =====================================================================================
   METHOD BeginCreateObject ( _                         ' VTable offset = 12
     BYVAL pByteStream AS IMFByteStream _               ' __in IMFByteStream *pByteStream
   , BYREF pwszURL AS WSTRINGZ _                        ' __in LPCWSTR pwszURL
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYVAL pProps AS IPropertyStore _                   ' __in IPropertyStore *pProps
   , BYREF ppIUnknownCancelCookie AS IUnknown _         ' __out IUnknown **ppIUnknownCancelCookie
   , BYVAL pCallback AS IMFAsyncCallback _              ' __in IMFAsyncCallback *pCallback
   , BYVAL punkState AS IUnknown _                      ' __in IUnknown *punkState
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EndCreateObject ( _                           ' VTable offset = 16
     BYVAL pResult AS IMFAsyncResult _                  ' __in IMFAsyncResult *pResult
   , BYREF pObjectType AS LONG _                        ' __out MF_OBJECT_TYPE *pObjectType
   , BYREF ppObject AS IUnknown _                       ' __out IUnknown **ppObject
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CancelObjectCreation ( _                      ' VTable offset = 20
     BYVAL pIUnknownCancelCookie AS IUnknown _          ' __in IUnknown *pIUnknownCancelCookie
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMaxNumberOfBytesRequiredForResolution ( _  ' VTable offset = 24
     BYREF pqwBytes AS QUAD _                           ' __out QWORD *pqwBytes
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMFByteStreamHandler_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IMFTrustedInput
' IID = 542612C4-A1B8-4632-B521-DE11EA64A0B0
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMFTrustedInput_INTERFACE_DEFINED)
    %IMFTrustedInput_INTERFACE_DEFINED = 1

$IID_IMFTrustedInput = GUID$("{542612C4-A1B8-4632-B521-DE11EA64A0B0}")

INTERFACE IMFTrustedInput $IID_IMFTrustedInput

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetInputTrustAuthority ( _                    ' VTable offset = 12
     BYVAL dwStreamID AS DWORD _                        ' __in DWORD dwStreamID
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppunkObject AS IUnknown _                    ' __out IUnknown **ppunkObject
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMFTrustedInput_INTERFACE_DEFINED__ */


' enum MFPOLICYMANAGER_ACTION
%PEACTION_NO        = 0
%PEACTION_PLAY      = 1
%PEACTION_COPY      = 2
%PEACTION_EXPORT    = 3
%PEACTION_EXTRACT   = 4
%PEACTION_RESERVED1 = 5
%PEACTION_RESERVED2 = 6
%PEACTION_RESERVED3 = 7
%PEACTION_LAST      = 7

' // Size = 12 bytes
TYPE MFINPUTTRUSTAUTHORITY_ACCESS_ACTION DWORD
   Action   AS LONG       ' MFPOLICYMANAGER_ACTION
   pbTicket AS BYTE PTR   ' BYTE *
   cbTicket AS DWORD      ' DWORD
END TYPE

MACRO MFINPUTTRUSTAUTHORITY_ACTION = MFINPUTTRUSTAUTHORITY_ACCESS_ACTION

' // Size = 40 bytes
TYPE MFINPUTTRUSTAUTHORITY_ACCESS_PARAMS DWORD
   dwSize             AS DWORD   ' DWORD
   dwVer              AS DWORD   ' DWORD
   cbSignatureOffset  AS DWORD   ' DWORD
   cbSignatureSize    AS DWORD   ' DWORD
   cbExtensionOffset  AS DWORD   ' DWORD
   cbExtensionSize    AS DWORD   ' DWORD
   cActions           AS DWORD   ' DWORD
   rgOutputActions(0) AS MFINPUTTRUSTAUTHORITY_ACCESS_ACTION
END TYPE


' ########################################################################################
' Interface name = IMFInputTrustAuthority
' IID = D19F8E98-B126-4446-890C-5DCB7AD71453
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMFInputTrustAuthority_INTERFACE_DEFINED)
    %IMFInputTrustAuthority_INTERFACE_DEFINED = 1

$IID_IMFInputTrustAuthority = GUID$("{D19F8E98-B126-4446-890C-5DCB7AD71453}")

INTERFACE IMFInputTrustAuthority $IID_IMFInputTrustAuthority

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetDecrypter ( _                              ' VTable offset = 12
     BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppv AS IUnknown _                            ' __out void **ppv
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RequestAccess ( _                             ' VTable offset = 16
     BYVAL Action AS LONG _                             ' __in MFPOLICYMANAGER_ACTION Action
   , BYREF ppContentEnablerActivate AS IMFActivate _    ' __out IMFActivate **ppContentEnablerActivate
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPolicy ( _                                 ' VTable offset = 20
     BYVAL Action AS LONG _                             ' __in MFPOLICYMANAGER_ACTION Action
   , BYREF ppPolicy AS IMFOutputPolicy _                ' __out IMFOutputPolicy **ppPolicy
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD BindAccess ( _                                ' VTable offset = 24
     BYREF pParam AS MFINPUTTRUSTAUTHORITY_ACCESS_PARAMS _ ' __in MFINPUTTRUSTAUTHORITY_ACCESS_PARAMS *pParam
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UpdateAccess ( _                              ' VTable offset = 28
     BYREF pParam AS MFINPUTTRUSTAUTHORITY_ACCESS_PARAMS _ ' __in MFINPUTTRUSTAUTHORITY_ACCESS_PARAMS *pParam
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reset ( _                                     ' VTable offset = 32
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMFInputTrustAuthority_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IMFTrustedOutput
' IID = D19F8E95-B126-4446-890C-5DCB7AD71453
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMFTrustedOutput_INTERFACE_DEFINED)
    %IMFTrustedOutput_INTERFACE_DEFINED = 1

$IID_IMFTrustedOutput = GUID$("{D19F8E95-B126-4446-890C-5DCB7AD71453}")

INTERFACE IMFTrustedOutput $IID_IMFTrustedOutput

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetOutputTrustAuthorityCount ( _              ' VTable offset = 12
     BYREF pcOutputTrustAuthorities AS DWORD _          ' __out  DWORD *pcOutputTrustAuthorities
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetOutputTrustAuthorityByIndex ( _            ' VTable offset = 16
     BYVAL dwIndex AS DWORD _                           ' __in DWORD dwIndex
   , BYREF ppauthority AS IMFOutputTrustAuthority _     ' __out IMFOutputTrustAuthority **ppauthority
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsFinal ( _                                   ' VTable offset = 20
     BYREF pfIsFinal AS LONG _                          ' __out BOOL *pfIsFinal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMFTrustedOutput_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IMFOutputTrustAuthority
' IID = D19F8E94-B126-4446-890C-5DCB7AD71453
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMFOutputTrustAuthority_INTERFACE_DEFINED)
    %IMFOutputTrustAuthority_INTERFACE_DEFINED = 1

$IID_IMFOutputTrustAuthority = GUID$("{D19F8E94-B126-4446-890C-5DCB7AD71453}")

INTERFACE IMFOutputTrustAuthority $IID_IMFOutputTrustAuthority

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetAction ( _                                 ' VTable offset = 12
     BYREF pAction AS LONG _                            ' __out MFPOLICYMANAGER_ACTION *pAction
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPolicy ( _                                 ' VTable offset = 16
     BYVAL ppPolicy AS IMFOutputPolicy _                ' __in IMFOutputPolicy **ppPolicy
   , BYVAL nPolicy AS DWORD _                           ' __in DWORD nPolicy
   , BYREF ppbTicket AS DWORD _                         ' __out BYTE **ppbTicket
   , BYREF pcbTicket AS DWORD _                         ' __out DWORD *pcbTicket
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMFOutputTrustAuthority_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IMFOutputPolicy
' IID = 7F00F10A-DAED-41AF-AB26-5FDFA4DFBA3C
' Inherited interface = IMFAttributes
' ########################################################################################

#IF NOT %DEF(%IMFOutputPolicy_INTERFACE_DEFINED)
    %IMFOutputPolicy_INTERFACE_DEFINED = 1

$IID_IMFOutputPolicy = GUID$("{7F00F10A-DAED-41AF-AB26-5FDFA4DFBA3C}")

INTERFACE IMFOutputPolicy $IID_IMFOutputPolicy

   INHERIT IUnknown

   ' =====================================================================================
   ' IMFAttributes methods
   ' =====================================================================================
   METHOD GetItem ( _                                   ' VTable offset = 12
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF pValue AS PROPVARIANT _                      ' __in_out PROPVARIANT *pValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetItemType ( _                               ' VTable offset = 16
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF pType AS LONG _                              ' __out MF_ATTRIBUTE_TYPE *pType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CompareItem ( _                               ' VTable offset = 20
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF Value AS PROPVARIANT _                       ' __in REFPROPVARIANT Value
   , BYREF pbResult AS LONG _                           ' __out BOOL *pbResult
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Compare ( _                                   ' VTable offset = 24
     BYVAL pTheirs AS IMFAttributes _                   ' __in IMFAttributes *pTheirs
   , BYVAL MatchType AS LONG _                          ' __in MF_ATTRIBUTES_MATCH_TYPE MatchType
   , BYREF pbResult AS LONG _                           ' __out BOOL *pbResult
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetUINT32 ( _                                 ' VTable offset = 28
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF punValue AS DWORD _                          ' __out UINT32 *punValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetUINT64 ( _                                 ' VTable offset = 32
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF punValue AS QUAD _                           ' __out UINT64 *punValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDouble ( _                                 ' VTable offset = 36
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF pfValue AS DOUBLE _                          ' __out double *pfValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetGUID ( _                                   ' VTable offset = 40
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF pguidValue AS GUID _                         ' __out GUID *pguidValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetStringLength ( _                           ' VTable offset = 44
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF pcchLength AS DWORD _                        ' __out UINT32 *pcchLength
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetString ( _                                 ' VTable offset = 48
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF pwszValue AS WSTRINGZ _                      ' __out LPWSTR pwszValue
   , BYVAL cchBufSize AS DWORD _                        ' __in UINT32 cchBufSize
   , BYREF pcchLength AS DWORD _                        ' __in_out UINT32 *pcchLength
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAllocatedString ( _                        ' VTable offset = 52
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF ppwszValue AS DWORD _                        ' __out LPWSTR *ppwszValue
   , BYREF pcchLength AS DWORD _                        ' __out UINT32 *pcchLength
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetBlobSize ( _                               ' VTable offset = 56
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF pcbBlobSize AS DWORD _                       ' __out UINT32 *pcbBlobSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetBlob ( _                                   ' VTable offset = 60
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYVAL pBuf AS DWORD _                              ' __out UINT8 *pBuf
   , BYVAL cbBufSize AS DWORD _                         ' __in UINT32 cbBufSize
   , BYREF pcbBlobSize AS DWORD _                       ' __in_out UINT32 *pcbBlobSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAllocatedBlob ( _                          ' VTable offset = 64
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYVAL ppBuf AS DWORD _                             ' __out UINT8 **ppBuf
   , BYREF pcbSize AS DWORD _                           ' __out UINT32 *pcbSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetUnknown ( _                                ' VTable offset = 68
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppv AS IUnknown _                            ' __out LPVOID *ppv
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetItem ( _                                   ' VTable offset = 72
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF Value AS PROPVARIANT _                       ' __out REFPROPVARIANT Value
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DeleteItem ( _                                ' VTable offset = 76
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DeleteAllItems ( _                            ' VTable offset = 80
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetUINT32 ( _                                 ' VTable offset = 84
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYVAL unValue AS DWORD _                           ' __in UINT32 unValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetUINT64 ( _                                 ' VTable offset = 88
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYVAL unValue AS QUAD _                            ' __in UINT64 unValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetDouble ( _                                 ' VTable offset = 92
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYVAL fValue AS DOUBLE _                           ' __in double fValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetGUID ( _                                   ' VTable offset = 96
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF guidValue AS GUID _                          ' __in REFGUID guidValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetString ( _                                 ' VTable offset = 100
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF wszValue AS WSTRINGZ _                       ' __in LPCWSTR wszValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetBlob ( _                                   ' VTable offset = 104
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYVAL pBuf AS DWORD _                              ' __in  const UINT8 *pBuf
   , BYVAL cbBufSize AS DWORD _                         ' __in UINT32 cbBufSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetUnknown ( _                                ' VTable offset = 108
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYVAL pUnknown AS IUnknown _                       ' __in IUnknown *pUnknown
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD LockStore ( _                                 ' VTable offset = 112
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UnlockStore ( _                               ' VTable offset = 116
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCount ( _                                  ' VTable offset = 120
     BYREF pcItems AS DWORD _                           ' __out UINT32 *pcItems
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetItemByIndex ( _                            ' VTable offset = 124
     BYVAL unIndex AS DWORD _                           ' __in UINT32 unIndex
   , BYREF pguidKey AS GUID _                           ' __out GUID *pguidKey
   , BYREF pValue AS PROPVARIANT _                      ' __in_out PROPVARIANT *pValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CopyAllItems ( _                              ' VTable offset = 128
     BYVAL pDest AS LONG _                              ' __in IMFAttributes *pDest
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IMFOutputPolicy methods
   ' =====================================================================================
   METHOD GenerateRequiredSchemas ( _                   ' VTable offset = 132
     BYVAL dwAttributes AS DWORD _                      ' __in DWORD dwAttributes
   , BYREF guidOutputSubType AS GUID _                  ' __in GUID guidOutputSubType
   , BYREF rgGuidProtectionSchemasSupported AS GUID _   ' __in GUID *rgGuidProtectionSchemasSupported
   , BYVAL cProtectionSchemasSupported AS DWORD _       ' __in DWORD cProtectionSchemasSupported
   , BYREF ppRequiredProtectionSchemas AS IMFCollection _ ' __out IMFCollection **ppRequiredProtectionSchemas
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetOriginatorID ( _                           ' VTable offset = 136
     BYREF pguidOriginatorID AS GUID _                  ' __out GUID *pguidOriginatorID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMinimumGRLVersion ( _                      ' VTable offset = 140
     BYREF pdwMinimumGRLVersion AS DWORD _              ' __out DWORD *pdwMinimumGRLVersion
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMFOutputPolicy_INTERFACE_DEFINED__ */


%MFOUTPUTATTRIBUTE_DIGITAL                   = &H00000001???
%MFOUTPUTATTRIBUTE_NONSTANDARDIMPLEMENTATION = &H00000002???
%MFOUTPUTATTRIBUTE_VIDEO                     = &H00000004???
%MFOUTPUTATTRIBUTE_COMPRESSED                = &H00000008???
%MFOUTPUTATTRIBUTE_SOFTWARE                  = &H00000010???
%MFOUTPUTATTRIBUTE_BUS                       = &H00000020???
%MFOUTPUTATTRIBUTE_BUSIMPLEMENTATION         = &H0000FF00???

$MFCONNECTOR_SPDIF = GUID$("{0B94A712-AD3E-4CEE-83CE-CE32E3DB6522}")

$MFCONNECTOR_UNKNOWN = GUID$("{AC3AEF5C-CE43-11D9-92DB-000BDB28FF98}")
$MFCONNECTOR_PCI = GUID$("{AC3AEF5D-CE43-11D9-92DB-000BDB28FF98}")
$MFCONNECTOR_PCIX = GUID$("{AC3AEF5E-CE43-11D9-92DB-000BDB28FF98}")
$MFCONNECTOR_PCI_Express = GUID$("{AC3AEF5F-CE43-11D9-92DB-000BDB28FF98}")
$MFCONNECTOR_AGP = GUID$("{AC3AEF60-CE43-11D9-92DB-000BDB28FF98}")

$MFCONNECTOR_VGA = GUID$("{57CD5968-CE47-11D9-92DB-000BDB28FF98}")
$MFCONNECTOR_SVIDEO = GUID$("{57CD5969-CE47-11D9-92DB-000BDB28FF98}")
$MFCONNECTOR_COMPOSITE = GUID$("{57CD596A-CE47-11D9-92DB-000BDB28FF98}")
$MFCONNECTOR_COMPONENT = GUID$("{57CD596B-CE47-11D9-92DB-000BDB28FF98}")
$MFCONNECTOR_DVI = GUID$("{57CD596C-CE47-11D9-92DB-000BDB28FF98}")
$MFCONNECTOR_HDMI = GUID$("{57CD596D-CE47-11D9-92DB-000BDB28FF98}")
$MFCONNECTOR_LVDS = GUID$("{57CD596E-CE47-11D9-92DB-000BDB28FF98}")
$MFCONNECTOR_D_JPN = GUID$("{57CD5970-CE47-11D9-92DB-000BDB28FF98}")
$MFCONNECTOR_SDI = GUID$("{57CD5971-CE47-11D9-92DB-000BDB28FF98}")
$MFCONNECTOR_DISPLAYPORT_EXTERNAL = GUID$("{57CD5972-CE47-11D9-92DB-000BDB28FF98}")
$MFCONNECTOR_DISPLAYPORT_EMBEDDED = GUID$("{57CD5973-CE47-11D9-92DB-000BDB28FF98}")
$MFCONNECTOR_UDI_EXTERNAL = GUID$("{57CD5974-CE47-11D9-92DB-000BDB28FF98}")
$MFCONNECTOR_UDI_EMBEDDED = GUID$("{57CD5975-CE47-11D9-92DB-000BDB28FF98}")


' ########################################################################################
' Interface name = IMFOutputSchema
' IID = 7BE0FC5B-ABD9-44FB-A5C8-F50136E71599
' Inherited interface = IMFAttributes
' ########################################################################################

#IF NOT %DEF(%IMFOutputSchema_INTERFACE_DEFINED)
    %IMFOutputSchema_INTERFACE_DEFINED = 1

$IID_IMFOutputSchema = GUID$("{7BE0FC5B-ABD9-44FB-A5C8-F50136E71599}")

INTERFACE IMFOutputSchema $IID_IMFOutputSchema

   INHERIT IUnknown

   ' =====================================================================================
   ' IMFAttributes methods
   ' =====================================================================================
   METHOD GetItem ( _                                   ' VTable offset = 12
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF pValue AS PROPVARIANT _                      ' __in_out PROPVARIANT *pValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetItemType ( _                               ' VTable offset = 16
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF pType AS LONG _                              ' __out MF_ATTRIBUTE_TYPE *pType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CompareItem ( _                               ' VTable offset = 20
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF Value AS PROPVARIANT _                       ' __in REFPROPVARIANT Value
   , BYREF pbResult AS LONG _                           ' __out BOOL *pbResult
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Compare ( _                                   ' VTable offset = 24
     BYVAL pTheirs AS IMFAttributes _                   ' __in IMFAttributes *pTheirs
   , BYVAL MatchType AS LONG _                          ' __in MF_ATTRIBUTES_MATCH_TYPE MatchType
   , BYREF pbResult AS LONG _                           ' __out BOOL *pbResult
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetUINT32 ( _                                 ' VTable offset = 28
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF punValue AS DWORD _                          ' __out UINT32 *punValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetUINT64 ( _                                 ' VTable offset = 32
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF punValue AS QUAD _                           ' __out UINT64 *punValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDouble ( _                                 ' VTable offset = 36
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF pfValue AS DOUBLE _                          ' __out double *pfValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetGUID ( _                                   ' VTable offset = 40
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF pguidValue AS GUID _                         ' __out GUID *pguidValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetStringLength ( _                           ' VTable offset = 44
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF pcchLength AS DWORD _                        ' __out UINT32 *pcchLength
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetString ( _                                 ' VTable offset = 48
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF pwszValue AS WSTRINGZ _                      ' __out LPWSTR pwszValue
   , BYVAL cchBufSize AS DWORD _                        ' __in UINT32 cchBufSize
   , BYREF pcchLength AS DWORD _                        ' __in_out UINT32 *pcchLength
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAllocatedString ( _                        ' VTable offset = 52
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF ppwszValue AS DWORD _                        ' __out LPWSTR *ppwszValue
   , BYREF pcchLength AS DWORD _                        ' __out UINT32 *pcchLength
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetBlobSize ( _                               ' VTable offset = 56
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF pcbBlobSize AS DWORD _                       ' __out UINT32 *pcbBlobSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetBlob ( _                                   ' VTable offset = 60
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYVAL pBuf AS DWORD _                              ' __out UINT8 *pBuf
   , BYVAL cbBufSize AS DWORD _                         ' __in UINT32 cbBufSize
   , BYREF pcbBlobSize AS DWORD _                       ' __in_out UINT32 *pcbBlobSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAllocatedBlob ( _                          ' VTable offset = 64
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYVAL ppBuf AS DWORD _                             ' __out UINT8 **ppBuf
   , BYREF pcbSize AS DWORD _                           ' __out UINT32 *pcbSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetUnknown ( _                                ' VTable offset = 68
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppv AS IUnknown _                            ' __out LPVOID *ppv
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetItem ( _                                   ' VTable offset = 72
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF Value AS PROPVARIANT _                       ' __out REFPROPVARIANT Value
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DeleteItem ( _                                ' VTable offset = 76
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DeleteAllItems ( _                            ' VTable offset = 80
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetUINT32 ( _                                 ' VTable offset = 84
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYVAL unValue AS DWORD _                           ' __in UINT32 unValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetUINT64 ( _                                 ' VTable offset = 88
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYVAL unValue AS QUAD _                            ' __in UINT64 unValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetDouble ( _                                 ' VTable offset = 92
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYVAL fValue AS DOUBLE _                           ' __in double fValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetGUID ( _                                   ' VTable offset = 96
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF guidValue AS GUID _                          ' __in REFGUID guidValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetString ( _                                 ' VTable offset = 100
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYREF wszValue AS WSTRINGZ _                       ' __in LPCWSTR wszValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetBlob ( _                                   ' VTable offset = 104
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYVAL pBuf AS DWORD _                              ' __in  const UINT8 *pBuf
   , BYVAL cbBufSize AS DWORD _                         ' __in UINT32 cbBufSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetUnknown ( _                                ' VTable offset = 108
     BYREF guidKey AS GUID _                            ' __in REFGUID guidKey
   , BYVAL pUnknown AS IUnknown _                       ' __in IUnknown *pUnknown
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD LockStore ( _                                 ' VTable offset = 112
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UnlockStore ( _                               ' VTable offset = 116
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCount ( _                                  ' VTable offset = 120
     BYREF pcItems AS DWORD _                           ' __out UINT32 *pcItems
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetItemByIndex ( _                            ' VTable offset = 124
     BYVAL unIndex AS DWORD _                           ' __in UINT32 unIndex
   , BYREF pguidKey AS GUID _                           ' __out GUID *pguidKey
   , BYREF pValue AS PROPVARIANT _                      ' __in_out PROPVARIANT *pValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CopyAllItems ( _                              ' VTable offset = 128
     BYVAL pDest AS LONG _                              ' __in IMFAttributes *pDest
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IMFOutputSchema methods
   ' =====================================================================================
   METHOD GetSchemaType ( _                             ' VTable offset = 132
     BYREF pguidSchemaType AS GUID _                    ' __out GUID *pguidSchemaType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetConfigurationData ( _                      ' VTable offset = 136
     BYREF pdwVal AS DWORD _                            ' __out DWORD *pdwVal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetOriginatorID ( _                           ' VTable offset = 140
     BYREF pguidOriginatorID AS GUID _                  ' __out GUID *pguidOriginatorID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMFOutputSchema_INTERFACE_DEFINED__ */

$MFPROTECTION_DISABLE = GUID$("{8CC6D81B-FEC6-4D8F-964B-CFBA0B0DAD0D}")
$MFPROTECTION_CONSTRICTVIDEO = GUID$("{193370CE-C5E4-4C3A-8A66-6959B4DA4442}")
$MFPROTECTION_CONSTRICTAUDIO = GUID$("{FFC99B44-DF48-4E16-8E66-096892C1578A}")
$MFPROTECTION_TRUSTEDAUDIODRIVERS = GUID$("{65BDF3D2-0168-4816-A533-55D47B027101}")
$MFPROTECTION_HDCP = GUID$("{AE7CC03D-C828-4021-ACB7-D578D27AAF13}")
$MFPROTECTION_CGMSA = GUID$("{E57E69E9-226B-4D31-B4E3-D3DB008736DD}")
$MFPROTECTION_ACP = GUID$("{C3FD11C6-F8B7-4D20-B008-1DB17D61F2DA}")
$MFPROTECTION_WMDRMOTA = GUID$("{A267A6A1-362E-47D0-8805-4628598A23E4}")
$MFPROTECTION_FFT = GUID$("{462A56B2-2866-4BB6-980D-6D8D9EDB1A8C}")

$MFPROTECTIONATTRIBUTE_CONSTRICTVIDEO_IMAGESIZE = GUID$("{080476FC-4B58-4D80-A790-E7297673161D}")
$MFPROTECTIONATTRIBUTE_HDCP_SRM = GUID$("{6F302107-3477-4468-8A08-EEF9DB10E20F}")

'#define MAKE_MFPROTECTIONDATA_DISABLE(Disable)  \
'    ((DWORD)(Disable ? 0x00000001 : 0))

MACRO MAKE_MFPROTECTIONDATA_DISABLE(nDisable) = IIF(nDisable = %TRUE, &H00000001???, 0)

'#define EXTRACT_MFPROTECTIONDATA_DISABLE_ON(Data) \
'    (0 != ((Data) & 0x00000001))

MACRO EXTRACT_MFPROTECTIONDATA_DISABLE_ON(nData) = (nData AND &H00000001???) <> 0

'#define EXTRACT_MFPROTECTIONDATA_DISABLE_RESERVED(Data) \
'    (((DWORD)((Data) & 0xFFFFFFFE)) >> 1)

MACRO FUNCTION EXTRACT_MFPROTECTIONDATA_DISABLE_RESERVED(nData)
   MACROTEMP dwData
   LOCAL dwData AS DWORD
   dwData = nData AND &HFFFFFFFE???
   RIGHT SHIFT dwData, 1
END MACRO = dwData

'#define MAKE_MFPROTECTIONDATA_CONSTRICTAUDIO(Level) \
'    ((DWORD)(Level))

MACRO MAKE_MFPROTECTIONDATA_CONSTRICTAUDIO (nLevel) = CDWD(nLevel)

'#define EXTRACT_MFPROTECTIONDATA_CONSTRICTAUDIO_LEVEL(Data) \
'    ((DWORD)((Data) & 0x000000FF))

MACRO EXTRACT_MFPROTECTIONDATA_CONSTRICTAUDIO_LEVEL(nData) = nData AND &H000000FF???

'#define EXTRACT_MFPROTECTIONDATA_CONSTRICTAUDIO_RESERVED(Data) \
'    (((DWORD)((Data) & 0xFFFFFF00)) >> 8)

MACRO FUNCTION EXTRACT_MFPROTECTIONDATA_CONSTRICTAUDIO_RESERVED(nData)
   MACROTEMP dwData
   LOCAL dwData AS DWORD
   dwData = nData AND &HFFFFFF00???
   RIGHT SHIFT dwData, 8
END MACRO = dwData

'#define MAKE_MFPROTECTIONDATA_TRUSTEDAUDIODRIVERS(TestCertificateEnable, DigitalOutputDisable, DrmLevel) \
'    (((DWORD)((TestCertificateEnable) ? 0x00020000 : 0)) | \
'     ((DWORD)((DigitalOutputDisable) ? 0x00010000 : 0)) | \
'     ((DWORD)(DrmLevel)))

MACRO FUNCTION MAKE_MFPROTECTIONDATA_TRUSTEDAUDIODRIVERS(TestCertificateEnable, DigitalOutputDisable, DrmLevel)
   MACROTEMP dwTestCertificateEnable, dwDigitalOutputDisable, dwDrmLevel
   dwTestCertificateEnable = IIF(TestCertificateEnable = %TRUE, &H00020000???, 0)
   dwTestCertificateEnable = IIF(DigitalOutputDisable = %TRUE, &H00010000???, 0)
   dwDrmLevel = DrmLevel
END MACRO = dwTestCertificateEnable OR dwTestCertificateEnable OR dwDrmLevel

'#define EXTRACT_MFPROTECTIONDATA_TRUSTEDAUDIODRIVERS_DRMLEVEL(Data) \
'    ((DWORD)((Data) & 0x0000FFFF))

MACRO EXTRACT_MFPROTECTIONDATA_TRUSTEDAUDIODRIVERS_DRMLEVEL(nData) = nData AND &H0000FFFF???

'#define EXTRACT_MFPROTECTIONDATA_TRUSTEDAUDIODRIVERS_DIGITALOUTPUTDISABLE(Data) \
'    (0 != ((Data) & 0x00010000))

MACRO EXTRACT_MFPROTECTIONDATA_TRUSTEDAUDIODRIVERS_DIGITALOUTPUTDISABLE(nData) = (nData AND &H00010000???) <> 0

'#define EXTRACT_MFPROTECTIONDATA_TRUSTEDAUDIODRIVERS_TESTCERTIFICATEENABLE(Data) \
'    (0 != ((Data) & 0x00020000))

MACRO EXTRACT_MFPROTECTIONDATA_TRUSTEDAUDIODRIVERS_TESTCERTIFICATEENABLE(nData) = (nData AND &H00020000???) <> 0

'#if (WINVER >= _WIN32_WINNT_WIN7)
#IF %WINVER >= &H0601
'#define EXTRACT_MFPROTECTIONDATA_TRUSTEDAUDIODRIVERS_COPYOK(Data) \
'    (0 != ((Data) & 0x00040000))
MACRO EXTRACT_MFPROTECTIONDATA_TRUSTEDAUDIODRIVERS_COPYOK(nData) = (nData AND &H00040000???) <> 0

'#define EXTRACT_MFPROTECTIONDATA_TRUSTEDAUDIODRIVERS_RESERVED(Data) \
'    (((DWORD)((Data) & 0xFFF80000)) >> 19)
MACRO FUNCTION EXTRACT_MFPROTECTIONDATA_TRUSTEDAUDIODRIVERS_RESERVED(nData)
   MACROTEMP dwData
   dwData = nData AND &HFFF80000???
   RIGHT SHIFT dwData, 19
END MACRO = dwData
#ELSE
'#define EXTRACT_MFPROTECTIONDATA_TRUSTEDAUDIODRIVERS_RESERVED(Data) \
'    (((DWORD)((Data) & 0xFFF80000)) >> 18)
MACRO FUNCTION EXTRACT_MFPROTECTIONDATA_TRUSTEDAUDIODRIVERS_RESERVED(nData)
   MACROTEMP dwData
   dwData = nData AND &HFFF80000???
   RIGHT SHIFT dwData, 18
END MACRO = dwData
#ENDIF   ' // (WINVER >= _WIN32_WINNT_WIN7)


' ########################################################################################
' Interface name = IMFSecureChannel
' IID = D0AE555D-3B12-4D97-B060-0990BC5AEB67
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMFSecureChannel_INTERFACE_DEFINED)
    %IMFSecureChannel_INTERFACE_DEFINED = 1

$IID_IMFSecureChannel = GUID$("{D0AE555D-3B12-4D97-B060-0990BC5AEB67}")

INTERFACE IMFSecureChannel $IID_IMFSecureChannel

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetCertificate ( _                            ' VTable offset = 12
     BYREF ppCert AS DWORD _                            ' __out BYTE **ppCert
   , BYREF pcbCert AS DWORD _                           ' __out DWORD *pcbCert
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetupSession ( _                              ' VTable offset = 16
     BYVAL pbEncryptedSessionKey AS BYTE PTR _          ' __in BYTE *pbEncryptedSessionKey
   , BYVAL cbSessionKey AS DWORD _                      ' __in DWORD cbSessionKey
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMFSecureChannel_INTERFACE_DEFINED__ */


' enum SAMPLE_PROTECTION_VERSION
%SAMPLE_PROTECTION_VERSION_NO         = 0
%SAMPLE_PROTECTION_VERSION_BASIC_LOKI = 1
%SAMPLE_PROTECTION_VERSION_SCATTER    = 2
%SAMPLE_PROTECTION_VERSION_RC4        = 3

$MF_SampleProtectionSalt = GUID$("{5403DEEE-B9EE-438F-AA83-3804997E569D}")


' ########################################################################################
' Interface name = IMFSampleProtection
' IID = 8E36395F-C7B9-43C4-A54D-512B4AF63C95
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMFSampleProtection_INTERFACE_DEFINED)
    %IMFSampleProtection_INTERFACE_DEFINED = 1

$IID_IMFSampleProtection = GUID$("{8E36395F-C7B9-43C4-A54D-512B4AF63C95}")

INTERFACE IMFSampleProtection $IID_IMFSampleProtection

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetInputProtectionVersion ( _                 ' VTable offset = 12
     BYREF pdwVersion AS DWORD _                        ' __out DWORD *pdwVersion
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetOutputProtectionVersion ( _                ' VTable offset = 16
     BYREF pdwVersion AS DWORD _                        ' __out DWORD *pdwVersion
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetProtectionCertificate ( _                  ' VTable offset = 20
     BYVAL dwVersion AS DWORD _                         ' __in DWORD dwVersion
   , BYREF ppCert AS DWORD _                            ' __out BYTE **ppCert
   , BYREF pcbCert AS DWORD _                           ' __out DWORD *pcbCert
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD InitOutputProtection ( _                      ' VTable offset = 24
     BYVAL dwVersion AS DWORD _                         ' __in DWORD dwVersion
   , BYVAL dwOutputId AS DWORD _                        ' __in DWORD dwOutputId
   , BYVAL pbCert AS BYTE PTR _                         ' __in BYTE *pbCert
   , BYVAL cbCert AS DWORD _                            ' __in DWORD cbCert
   , BYREF ppbSeed AS DWORD _                           ' __out BYTE **ppbSeed
   , BYREF pcbSeed AS DWORD _                           ' __out DWORD *pcbSeed
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD InitInputProtection ( _                       ' VTable offset = 28
     BYVAL dwVersion AS DWORD _                         ' __in DWORD dwVersion
   , BYVAL dwInputId AS DWORD _                         ' __in DWORD dwInputId
   , BYVAL pbSeed AS BYTE PTR _                         ' __in BYTE *pbSeed
   , BYVAL cbSeed AS DWORD _                            ' __in DWORD cbSeed
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMFSampleProtection_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IMFMediaSinkPreroll
' IID = 5DFD4B2A-7674-4110-A4E6-8A68FD5F3688
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMFMediaSinkPreroll_INTERFACE_DEFINED)
    %IMFMediaSinkPreroll_INTERFACE_DEFINED = 1

$IID_IMFMediaSinkPreroll = GUID$("{5DFD4B2A-7674-4110-A4E6-8A68FD5F3688}")

INTERFACE IMFMediaSinkPreroll $IID_IMFMediaSinkPreroll

   INHERIT IUnknown

   ' =====================================================================================
   METHOD NotifyPreroll ( _                             ' VTable offset = 12
     BYVAL hnsUpcomingStartTime AS QUAD _               ' __in MFTIME hnsUpcomingStartTime
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMFMediaSinkPreroll_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IMFFinalizableMediaSink
' IID = EAECB74A-9A50-42CE-9541-6A7F57AA4AD7
' Inherited interface = IMFMediaSink
' ########################################################################################

#IF NOT %DEF(%IMFFinalizableMediaSink_INTERFACE_DEFINED)
    %IMFFinalizableMediaSink_INTERFACE_DEFINED = 1

$IID_IMFFinalizableMediaSink = GUID$("{EAECB74A-9A50-42CE-9541-6A7F57AA4AD7}")

INTERFACE IMFFinalizableMediaSink $IID_IMFFinalizableMediaSink

   INHERIT IUnknown

   ' =====================================================================================
   ' IMFMediaSink methods
   ' =====================================================================================
   METHOD GetCharacteristics ( _                        ' VTable offset = 12
     BYREF pdwCharacteristics AS DWORD _                ' __out DWORD *pdwCharacteristics
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddStreamSink ( _                             ' VTable offset = 16
     BYVAL dwStreamSinkIdentifier AS DWORD _            ' __in DWORD dwStreamSinkIdentifier
   , BYVAL pMediaType AS IMFMediaType _                 ' __in IMFMediaType *pMediaType
   , BYREF ppStreamSink AS IMFStreamSink _              ' __out IMFStreamSink **ppStreamSink
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RemoveStreamSink ( _                          ' VTable offset = 20
     BYVAL dwStreamSinkIdentifier AS DWORD _            ' __in DWORD dwStreamSinkIdentifier
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetStreamSinkCount ( _                        ' VTable offset = 24
     BYREF pcStreamSinkCount AS DWORD _                 ' __out DWORD *pcStreamSinkCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetStreamSinkByIndex ( _                      ' VTable offset = 28
     BYVAL dwIndex AS DWORD _                           ' __in DWORD dwIndex
   , BYREF ppStreamSink AS IMFStreamSink _              ' __out IMFStreamSink **ppStreamSink
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetStreamSinkById ( _                         ' VTable offset = 32
     BYVAL dwStreamSinkIdentifier AS DWORD _            ' __in DWORD dwStreamSinkIdentifier
   , BYREF ppStreamSink AS IMFStreamSink _              ' __out IMFStreamSink **ppStreamSink
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPresentationClock ( _                      ' VTable offset = 36
     BYVAL pPresentationClock AS IMFPresentationClock _ ' __in IMFPresentationClock *pPresentationClock
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPresentationClock ( _                      ' VTable offset = 40
     BYREF ppPresentationClock AS IMFPresentationClock _ ' __out IMFPresentationClock **ppPresentationClock
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Shutdown ( _                                  ' VTable offset = 44
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IMFFinalizableMediaSink methods
   ' =====================================================================================
   METHOD BeginFinalize ( _                             ' VTable offset = 48
     BYVAL pCallback AS IMFAsyncCallback _              ' __in IMFAsyncCallback *pCallback
   , BYVAL punkState AS IUnknown _                      ' __in IUnknown *punkState
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EndFinalize ( _                               ' VTable offset = 52
     BYVAL pResult AS IMFAsyncResult _                  ' __in IMFAsyncResult *pResult
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMFFinalizableMediaSink_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IMFStreamingSinkConfig
' IID = 9DB7AA41-3CC5-40D4-8509-555804AD34CC
' Inherited interface = IUnknown
' ########################################################################################

'#if (WINVER >= _WIN32_WINNT_WIN7)

#IF NOT %DEF(%IMFStreamingSinkConfig_INTERFACE_DEFINED)
    %IMFStreamingSinkConfig_INTERFACE_DEFINED = 1

$IID_IMFStreamingSinkConfig = GUID$("{9DB7AA41-3CC5-40D4-8509-555804AD34CC}")

INTERFACE IMFStreamingSinkConfig $IID_IMFStreamingSinkConfig

   INHERIT IUnknown

   ' =====================================================================================
   METHOD StartStreaming ( _                            ' VTable offset = 12
     BYVAL fSeekOffsetIsByteOffset AS LONG _            ' __in BOOL fSeekOffsetIsByteOffset
   , BYVAL qwSeekOffset AS QUAD _                       ' __in QWORD qwSeekOffset
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMFStreamingSinkConfig_INTERFACE_DEFINED__ */

'#endif // (WINVER >= _WIN32_WINNT_WIN7)


' ########################################################################################
' Interface name = IMFRemoteProxy
' IID = 994E23AD-1CC2-493C-B9FA-46F1CB040FA4
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMFRemoteProxy_INTERFACE_DEFINED)
    %IMFRemoteProxy_INTERFACE_DEFINED = 1

$IID_IMFRemoteProxy = GUID$("{994E23AD-1CC2-493C-B9FA-46F1CB040FA4}")

INTERFACE IMFRemoteProxy $IID_IMFRemoteProxy

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetRemoteObject ( _                           ' VTable offset = 12
     BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppv AS IUnknown _                            ' __outvoid **ppv
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRemoteHost ( _                             ' VTable offset = 16
     BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppv AS IUnknown _                            ' __out void **ppv
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMFRemoteProxy_INTERFACE_DEFINED__ */


$MF_REMOTE_PROXY = GUID$("{2F00C90E-D2CF-4278-8B6A-D077FAC3A25F}")


' ########################################################################################
' Interface name = IMFObjectReferenceStream
' IID = 09EF5BE3-C8A7-469E-8B70-73BF25BB193F
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMFObjectReferenceStream_INTERFACE_DEFINED)
    %IMFObjectReferenceStream_INTERFACE_DEFINED = 1

$IID_IMFObjectReferenceStream = GUID$("{09EF5BE3-C8A7-469E-8B70-73BF25BB193F}")

INTERFACE IMFObjectReferenceStream $IID_IMFObjectReferenceStream

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SaveReference ( _                             ' VTable offset = 12
     BYREF riid AS GUID _                               ' __in REFIID riid
   , BYVAL pUnk AS IUnknown _                           ' __in IUnknown *pUnk
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD LoadReference ( _                             ' VTable offset = 16
     BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppv AS IUnknown _                            ' __out void **ppv
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMFObjectReferenceStream_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IMFPMPHost
' IID = 2CD2D921-C447-44A7-A13C-4ADABFC247E3
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMFPMPHost_INTERFACE_DEFINED)
    %IMFPMPHost_INTERFACE_DEFINED = 1

$IID_IMFPMPHost = GUID$("{2CD2D921-C447-44A7-A13C-4ADABFC247E3}")

INTERFACE IMFPMPHost $IID_IMFPMPHost

   INHERIT IUnknown

   ' =====================================================================================
   METHOD LockProcess ( _                               ' VTable offset = 12
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UnlockProcess ( _                             ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateObjectByCLSID ( _                       ' VTable offset = 20
     BYREF clsid AS GUID _                              ' __in REFCLSID clsid
   , BYVAL pStream AS IStream _                         ' __in IStream *pStream
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppv AS IUnknown _                            ' __out void **ppv
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMFPMPHost_INTERFACE_DEFINED__ */

'#if (WINVER >= _WIN32_WINNT_WIN7)
'EXTERN_C const GUID MF_PMP_SERVICE;
'#endif // (WINVER >= _WIN32_WINNT_WIN7)

' ########################################################################################
' Interface name = IMFPMPClient
' IID = 6C4E655D-EAD8-4421-B6B9-54DCDBBDF820
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMFPMPClient_INTERFACE_DEFINED)
    %IMFPMPClient_INTERFACE_DEFINED = 1

$IID_IMFPMPClient = GUID$("{6C4E655D-EAD8-4421-B6B9-54DCDBBDF820}")

INTERFACE IMFPMPClient $IID_IMFPMPClient

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetPMPHost ( _                                ' VTable offset = 12
     BYVAL pPMPHost AS IMFPMPHost _                     ' __in IMFPMPHost *pPMPHost
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMFPMPClient_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IMFPMPServer
' IID = 994E23AF-1CC2-493C-B9FA-46F1CB040FA4
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMFPMPServer_INTERFACE_DEFINED)
    %IMFPMPServer_INTERFACE_DEFINED = 1

$IID_IMFPMPServer = GUID$("{994E23AF-1CC2-493C-B9FA-46F1CB040FA4}")

INTERFACE IMFPMPServer $IID_IMFPMPServer

   INHERIT IUnknown

   ' =====================================================================================
   METHOD LockProcess ( _                               ' VTable offset = 12
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UnlockProcess ( _                             ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateObjectByCLSID ( _                       ' VTable offset = 20
     BYREF clsid AS GUID _                              ' __in REFCLSID clsid
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppObject AS IUnknown _                       ' __out void **ppObject
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMFPMPServer_INTERFACE_DEFINED__ */


DECLARE FUNCTION MFCreatePMPServer IMPORT "mf.dll" ALIAS "MFCreatePMPServer" ( _
   BYVAL dwCreationFlags AS DWORD _                     ' __in DWORD dwCreationFlags
 , BYVAL ppPMPServer AS IMFPMPServer _                  ' __in IMFPMPServer** ppPMPServer
 ) AS LONG                                              ' HRESULT


' ########################################################################################
' Interface name = IMFRemoteDesktopPlugin
' IID = 1CDE6309-CAE0-4940-907E-C1EC9C3D1D4A
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMFRemoteDesktopPlugin_INTERFACE_DEFINED)
    %IMFRemoteDesktopPlugin_INTERFACE_DEFINED = 1

$IID_IMFRemoteDesktopPlugin = GUID$("{1CDE6309-CAE0-4940-907E-C1EC9C3D1D4A}")

INTERFACE IMFRemoteDesktopPlugin $IID_IMFRemoteDesktopPlugin

   INHERIT IUnknown

   ' =====================================================================================
   METHOD UpdateTopology ( _                            ' VTable offset = 12
     BYREF pTopology AS IMFTopology _                   ' __inout IMFTopology *pTopology
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMFRemoteDesktopPlugin_INTERFACE_DEFINED__ */


DECLARE FUNCTION MFCreateRemoteDesktopPlugin IMPORT "mf.dll" ALIAS "MFCreateRemoteDesktopPlugin" ( _
   BYREF ppPlugin AS IMFRemoteDesktopPlugin _           ' __out IMFRemoteDesktopPlugin** ppPlugin
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION CreateNamedPropertyStore IMPORT "mf.dll" ALIAS "CreateNamedPropertyStore" ( _
   BYREF ppStore AS INamedPropertyStore _               ' __out INamedPropertyStore **ppStore
 ) AS LONG                                              ' HRESULT


' ########################################################################################
' Interface name = IMFSAMIStyle
' IID = A7E025DD-5303-4A62-89D6-E747E1EFAC73
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMFSAMIStyle_INTERFACE_DEFINED)
    %IMFSAMIStyle_INTERFACE_DEFINED = 1

$IID_IMFSAMIStyle = GUID$("{A7E025DD-5303-4A62-89D6-E747E1EFAC73}")

INTERFACE IMFSAMIStyle $IID_IMFSAMIStyle

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetStyleCount ( _                             ' VTable offset = 12
     BYREF pdwCount AS DWORD _                          ' __out DWORD *pdwCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetStyles ( _                                 ' VTable offset = 16
     BYREF pPropVarStyleArray AS PROPVARIANT _          ' __out PROPVARIANT *pPropVarStyleArray
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetSelectedStyle ( _                          ' VTable offset = 20
     BYREF pwszStyle AS WSTRINGZ _                      ' __in LPCWSTR pwszStyle
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSelectedStyle ( _                          ' VTable offset = 20
     BYREF ppwszStyle AS DWORD _                        ' __out LPWSTR *ppwszStyle
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMFSAMIStyle_INTERFACE_DEFINED__ */

$MF_SAMI_SERVICE = GUID$("{49A89AE7-B4D9-4EF2-AA5C-F65A3E05AE4E}")
$MF_PD_SAMI_STYLELIST = GUID$("{E0B73C7F-486D-484E-9872-4DE5192A7BF8}")
$MF_SD_SAMI_LANGUAGE = GUID$("{36FCB98A-6CD0-44CB-ACB9-A8F5600DD0BB}")

'#if (WINVER >= _WIN32_WINNT_WIN7)
DECLARE FUNCTION MFCreateSampleCopierMFT IMPORT "mf.dll" ALIAS "MFCreateSampleCopierMFT" ( _
   BYREF ppCopierMFT AS IMFTransform _                  ' __out IMFTransform** ppCopierMFT
 ) AS LONG                                              ' HRESULT

' ########################################################################################
' Interface name = IMFTranscodeProfile
' IID = 4ADFDBA3-7AB0-4953-A62B-461E7FF3DA1E
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMFTranscodeProfile_INTERFACE_DEFINED)
    %IMFTranscodeProfile_INTERFACE_DEFINED = 1

$IID_IMFTranscodeProfile = GUID$("{4ADFDBA3-7AB0-4953-A62B-461E7FF3DA1E}")

INTERFACE IMFTranscodeProfile $IID_IMFTranscodeProfile

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetAudioAttributes ( _                        ' VTable offset = 12
     BYVAL pAttrs AS IMFAttributes _                    ' __in_opt IMFAttributes *pAttrs
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAudioAttributes ( _                        ' VTable offset = 16
     BYREF ppAttrs AS IMFAttributes _                   ' __out_opt IMFAttributes **ppAttrs
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetVideoAttributes ( _                        ' VTable offset = 20
     BYVAL pAttrs AS IMFAttributes _                    ' __in_opt IMFAttributes *pAttrs
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetVideoAttributes ( _                        ' VTable offset = 24
     BYREF ppAttrs AS IMFAttributes _                   ' __out_opt IMFAttributes **ppAttrs
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetContainerAttributes ( _                    ' VTable offset = 28
     BYVAL pAttrs AS IMFAttributes _                    ' __in_opt IMFAttributes *pAttrs
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetContainerAttributes ( _                    ' VTable offset = 32
     BYREF ppAttrs AS IMFAttributes _                   ' __out_opt IMFAttributes **ppAttrs
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMFTranscodeProfile_INTERFACE_DEFINED__ */

$MF_TRANSCODE_CONTAINERTYPE = GUID$("{150ff23f-4abc-478b-ac4f-e1916fba1cca}")
$MFTranscodeContainerType_ASF = GUID$("{430f6f6e-b6bf-4fc1-a0bd-9ee46eee2afb}")
$MFTranscodeContainerType_MPEG4 = GUID$("{dc6cd05d-b9d0-40ef-bd35-fa622c1ab28a}")
$MFTranscodeContainerType_MP3 = GUID$("{e438b912-83f1-4de6-9e3a-9ffbc6dd24d1}")
$MFTranscodeContainerType_3GP = GUID$("{34c50167-4472-4f34-9ea0-c49fbacf037d}")
$MF_TRANSCODE_SKIP_METADATA_TRANSFER = GUID$("{4e4469ef-b571-4959-8f83-3dcfba33a393}")
$MF_TRANSCODE_TOPOLOGYMODE = GUID$("{3e3df610-394a-40b2-9dea-3bab650bebf2}")

' enum _MF_TRANSCODE_TOPOLOGYMODE_FLAGS
%MF_TRANSCODE_TOPOLOGYMODE_SOFTWARE_ONLY    = 0
%MF_TRANSCODE_TOPOLOGYMODE_HARDWARE_ALLOWED = 1

$MF_TRANSCODE_ADJUST_PROFILE = GUID$("{9c37c21b-060f-487c-a690-80d7f50d1c72}")

' enum _MF_TRANSCODE_ADJUST_PROFILE_FLAGS
%MF_TRANSCODE_ADJUST_PROFILE_DEFAULT               = 0
%MF_TRANSCODE_ADJUST_PROFILE_USE_SOURCE_ATTRIBUTES = 1

$MF_TRANSCODE_ENCODINGPROFILE = GUID$("{6947787c-f508-4ea9-b1e9-a1fe3a49fbc9}")
$MF_TRANSCODE_QUALITYVSSPEED = GUID$("{98332df8-03cd-476b-89fa-3f9e442dec9f}")
$MF_TRANSCODE_DONOT_INSERT_ENCODER = GUID$("{f45aa7ce-ab24-4012-a11b-dc8220201410}")

DECLARE FUNCTION MFCreateTranscodeProfile IMPORT "mf.dll" ALIAS "MFCreateTranscodeProfile" ( _
   BYREF ppTranscodeProfile AS IMFTranscodeProfile _    ' __out IMFTranscodeProfile** ppTranscodeProfile
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION MFCreateTranscodeTopology IMPORT "mf.dll" ALIAS "MFCreateTranscodeTopology" ( _
   BYVAL pSrc AS IMFMediaSource _                       ' __in IMFMediaSource* pSrc
 , BYREF pwszOutputFilePath AS WSTRINGZ _               ' __in LPCWSTR pwszOutputFilePath
 , BYVAL pProfile AS IMFTranscodeProfile _              ' __in IMFTranscodeProfile* pProfile
 , BYREF ppTranscodeTopo AS IMFTopology _               ' __out IMFTopology** ppTranscodeTopo
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION MFTranscodeGetAudioOutputAvailableTypes IMPORT "mf.dll" ALIAS "MFTranscodeGetAudioOutputAvailableTypes" ( _
   BYREF guidSubType AS GUID _                          ' __in REFGUID guidSubType
 , BYVAL dwMFTFlags AS DWORD _                          ' __in DWORD dwMFTFlags
 , BYVAL pCodecConfig AS IMFAttributes _                ' __in_opt IMFAttributes* pCodecConfig
 , BYREF ppAvailableTypes AS IMFCollection _            ' __out IMFCollection** ppAvailableTypes
 ) AS LONG                                              ' HRESULT

' // Size = 16 bytes
TYPE MF_TRANSCODE_SINK_INFO DWORD
   dwVideoStreamID AS DWORD       ' DWORD
   pVideoMediaType AS DWORD PTR   ' IMFMediaType *
   dwAudioStreamID AS DWORD       ' DWORD
   pAudioMediaType AS DWORD PTR   ' IMFMediaType *
END TYPE

' ########################################################################################
' Interface name = IMFTranscodeSinkInfoProvider
' IID = 8CFFCD2E-5A03-4A3A-AFF7-EDCD107C620E
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMFTranscodeSinkInfoProvider_INTERFACE_DEFINED)
    %IMFTranscodeSinkInfoProvider_INTERFACE_DEFINED = 1

$IID_IMFTranscodeSinkInfoProvider = GUID$("{8CFFCD2E-5A03-4A3A-AFF7-EDCD107C620E}")

INTERFACE IMFTranscodeSinkInfoProvider $IID_IMFTranscodeSinkInfoProvider

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetOutputFile ( _                             ' VTable offset = 12
     BYREF pwszFileName AS WSTRINGZ _                   ' __in LPCWSTR pwszFileName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetOutputByteStream ( _                       ' VTable offset = 16
     BYVAL pByteStreamActivate AS IMFActivate _         ' __in IMFActivate *pByteStreamActivate
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetProfile ( _                                ' VTable offset = 20
     BYVAL pProfile AS IMFTranscodeProfile _            ' __in IMFTranscodeProfile *pProfile
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSinkInfo ( _                               ' VTable offset = 24
     BYREF pSinkInfo AS MF_TRANSCODE_SINK_INFO _        ' __out MF_TRANSCODE_SINK_INFO *pSinkInfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMFTranscodeSinkInfoProvider_INTERFACE_DEFINED__ */

DECLARE FUNCTION MFCreateTranscodeSinkActivate IMPORT "mf.dll" ALIAS "MFCreateTranscodeSinkActivate" ( _
   BYREF ppActivate AS IMFActivate _                    ' __out IMFActivate** ppActivate
 ) AS LONG                                              ' HRESULT

' ########################################################################################
' Interface name = IMFFieldOfUseMFTUnlock
' IID = 508E71D3-EC66-4FC3-8775-B4B9ED6BA847
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMFFieldOfUseMFTUnlock_INTERFACE_DEFINED)
    %IMFFieldOfUseMFTUnlock_INTERFACE_DEFINED = 1

$IID_IMFFieldOfUseMFTUnlock = GUID$("{508E71D3-EC66-4FC3-8775-B4B9ED6BA847}")

INTERFACE IMFFieldOfUseMFTUnlock $IID_IMFFieldOfUseMFTUnlock

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Unlock ( _                                    ' VTable offset = 12
     BYVAL pUnkMFT AS IUnknown _                        ' __in_opt IUnknown *pUnkMFT
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMFFieldOfUseMFTUnlock_INTERFACE_DEFINED__ */

' // Size = 56 bytes
TYPE MFT_REGISTRATION_INFO DWORD
   clsid        AS GUID                         ' CLSID
   guidCategory AS GUID                         ' GUID
   uiFlags      AS DWORD                        ' UINT32
   pszName      AS WSTRINGZ PTR                 ' LPCWSTR
   cInTypes     AS DWORD                        ' DWORD
   pInTypes     AS MFT_REGISTER_TYPE_INFO PTR   ' MFT_REGISTER_TYPE_INFO *
   cOutTypes    AS DWORD                        ' DWORD
   pOutTypes    AS MFT_REGISTER_TYPE_INFO PTR   ' MFT_REGISTER_TYPE_INFO *
END TYPE

$MF_LOCAL_MFT_REGISTRATION_SERVICE = GUID$("{ddf5cf9c-4506-45aa-abf0-6d5d94dd1b4a}")

' ########################################################################################
' Interface name = IMFLocalMFTRegistration
' IID = 149C4D73-B4BE-4F8D-8B87-079E926B6ADD
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMFLocalMFTRegistration_INTERFACE_DEFINED)
    %IMFLocalMFTRegistration_INTERFACE_DEFINED = 1

$IID_IMFLocalMFTRegistration = GUID$("{149C4D73-B4BE-4F8D-8B87-079E926B6ADD}")

INTERFACE IMFLocalMFTRegistration $IID_IMFLocalMFTRegistration

   INHERIT IUnknown

   ' =====================================================================================
   METHOD RegisterMFTs ( _                              ' VTable offset = 12
     BYREF pMFTs AS MFT_REGISTRATION_INFO _             ' __in MFT_REGISTRATION_INFO *pMFTs
   , BYVAL cMFTs AS DWORD _                             ' __in DWORD cMFTs
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMFLocalMFTRegistration_INTERFACE_DEFINED__ */

DECLARE FUNCTION MFCreateMFByteStreamOnStream IMPORT "mf.dll" ALIAS "MFCreateMFByteStreamOnStream" ( _
   BYVAL pStream AS IStream _                           ' __in IStream* pStream
 , BYREF ppByteStream AS IMFByteStream _                ' __out IMFByteStream** ppByteStream
 ) AS LONG                                              ' HRESULT

$CLSID_UrlmonSchemePlugin = GUID$("{9ec4b4f9-3029-45ad-947b-344de2a249e2}")

DECLARE FUNCTION MFEnumDeviceSources IMPORT "mf.dll" ALIAS "MFEnumDeviceSources" ( _
   BYVAL pAttributes AS IMFAttributes _                 ' __in IMFAttributes* pAttributes
 , BYREF pppSourceActivate AS IMFActivate _             ' __out IMFActivate*** pppSourceActivate
 , BYREF pcSourceActivate AS DWORD _                    ' __out UINT32* pcSourceActivate
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION MFCreateDeviceSource IMPORT "mf.dll" ALIAS "MFCreateDeviceSource" ( _
   BYVAL pAttributes AS IMFAttributes _                 ' __in  IMFAttributes* pAttributes
 , BYREF ppSource AS IMFMediaSource _                   ' __out IMFMediaSource** ppSource
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION MFCreateDeviceSourceActivate IMPORT "mf.dll" ALIAS "MFCreateDeviceSourceActivate" ( _
   BYVAL pAttributes AS IMFAttributes _                 ' __in  IMFAttributes* pAttributes
 , BYREF ppActivate AS IMFActivate _                    ' __out IMFActivate** ppActivate
 ) AS LONG                                              ' HRESULT

$MF_DEVSOURCE_ATTRIBUTE_SOURCE_TYPE = GUID$("{c60ac5fe-252a-478f-a0ef-bc8fa5f7cad3}")
$MF_DEVSOURCE_ATTRIBUTE_SOURCE_TYPE_VIDCAP_HW_SOURCE = GUID$("{de7046ba-54d6-4487-a2a4-ec7c0d1bd163}")
$MF_DEVSOURCE_ATTRIBUTE_FRIENDLY_NAME = GUID$("{60d0e559-52f8-4fa2-bbce-acdb34a8ec01}")
$MF_DEVSOURCE_ATTRIBUTE_MEDIA_TYPE = GUID$("{56a819ca-0c78-4de4-a0a7-3ddaba0f24d4}")
$MF_DEVSOURCE_ATTRIBUTE_SOURCE_TYPE_VIDCAP_CATEGORY = GUID$("{77f0ae69-c3bd-4509-941d-467e4d24899e}")
$MF_DEVSOURCE_ATTRIBUTE_SOURCE_TYPE_VIDCAP_SYMBOLIC_LINK = GUID$("{58f0aad8-22bf-4f8a-bb3d-d2c4978c6e2f}")
$MF_DEVSOURCE_ATTRIBUTE_SOURCE_TYPE_VIDCAP_MAX_BUFFERS = GUID$("{7dd9b730-4f2d-41d5-8f95-0cc9a912ba26}")
$MF_DEVSOURCE_ATTRIBUTE_SOURCE_TYPE_AUDCAP_ENDPOINT_ID = GUID$("{30da9258-feb9-47a7-a453-763a7a8e1c5f}")
$MF_DEVSOURCE_ATTRIBUTE_SOURCE_TYPE_AUDCAP_ROLE = GUID$("{bc9d118e-8c67-4a18-85d4-12d300400552}")
$MF_DEVSOURCE_ATTRIBUTE_SOURCE_TYPE_AUDCAP_GUID = GUID$("{14dd9a1c-7cff-41be-b1b9-ba1ac6ecb571}")
$MF_DEVSOURCE_ATTRIBUTE_SOURCE_TYPE_VIDCAP_GUID = GUID$("{8ac3587a-4ae7-42d8-99e0-0a6013eef90f}")
$MFSampleExtension_DeviceTimestamp = GUID$("{8f3e35e7-2dcd-4887-8622-2a58baa652b0}")

'#endif // (WINVER >= _WIN32_WINNT_WIN7)
