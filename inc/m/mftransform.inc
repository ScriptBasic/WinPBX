' ########################################################################################
' Microsoft Windows
' File: mftransform.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%MFTRANSFORM_INC = 1

'/* header files for imported files */
#INCLUDE "mfobjects.inc"

' enum MFT_INPUT_DATA_BUFFER_FLAGS
%MFT_INPUT_DATA_BUFFER_PLACEHOLDER   = &Hffffffff???

' enum MFT_OUTPUT_DATA_BUFFER_FLAGS
%MFT_OUTPUT_DATA_BUFFER_INCOMPLETE    = &H1000000???
%MFT_OUTPUT_DATA_BUFFER_FORMAT_CHANGE = &H100???
%MFT_OUTPUT_DATA_BUFFER_STREAM_END    = &H200???
%MFT_OUTPUT_DATA_BUFFER_NO_SAMPLE     = &H300???

' enum MFT_INPUT_STATUS_FLAGS
%MFT_INPUT_STATUS_ACCEPT_DATA   = &H1???

' enum MFT_OUTPUT_STATUS_FLAGS
%MFT_OUTPUT_STATUS_SAMPLE_READY   = &H1???

' enum MFT_INPUT_STREAM_INFO_FLAGS
%MFT_INPUT_STREAM_WHOLE_SAMPLES            = &H1???
%MFT_INPUT_STREAM_SINGLE_SAMPLE_PER_BUFFER = &H2???
%MFT_INPUT_STREAM_FIXED_SAMPLE_SIZE        = &H4???
%MFT_INPUT_STREAM_HOLDS_BUFFERS            = &H8???
%MFT_INPUT_STREAM_DOES_NOT_ADDREF          = &H100???
%MFT_INPUT_STREAM_REMOVABLE                = &H200???
%MFT_INPUT_STREAM_OPTIONAL                 = &H400???
%MFT_INPUT_STREAM_PROCESSES_IN_PLACE       = &H800???

' enum MFT_OUTPUT_STREAM_INFO_FLAGS
%MFT_OUTPUT_STREAM_WHOLE_SAMPLES            = &H1???
%MFT_OUTPUT_STREAM_SINGLE_SAMPLE_PER_BUFFER = &H2???
%MFT_OUTPUT_STREAM_FIXED_SAMPLE_SIZE        = &H4???
%MFT_OUTPUT_STREAM_DISCARDABLE              = &H8???
%MFT_OUTPUT_STREAM_OPTIONAL                 = &H10???
%MFT_OUTPUT_STREAM_PROVIDES_SAMPLES         = &H100???
%MFT_OUTPUT_STREAM_CAN_PROVIDE_SAMPLES      = &H200???
%MFT_OUTPUT_STREAM_LAZY_READ                = &H400???
%MFT_OUTPUT_STREAM_REMOVABLE                = &H800

' enum MFT_SET_TYPE_FLAGS
%MFT_SET_TYPE_TEST_ONLY   = &H1???

' enum MFT_PROCESS_OUTPUT_FLAGS
%MFT_PROCESS_OUTPUT_DISCARD_WHEN_NO_BUFFER   = &H1???

' enum MFT_PROCESS_OUTPUT_STATUS
%MFT_PROCESS_OUTPUT_STATUS_NEW_STREAMS   = &H100???

' enum MFT_DRAIN_TYPE
%MFT_DRAIN_PRODUCE_TAILS   = 0
%MFT_DRAIN_NO_TAILS        = &H1

%MFT_STREAMS_UNLIMITED       = &HFFFFFFFF???
'%MFT_OUTPUT_BOUND_LOWER_UNBOUNDED MINLONGLONG
'%MFT_OUTPUT_BOUND_UPPER_UNBOUNDED MAXLONGLONG

' enum MFT_MESSAGE_TYPE
%MFT_MESSAGE_COMMAND_FLUSH          = 0???
%MFT_MESSAGE_COMMAND_DRAIN          = &H1???
%MFT_MESSAGE_DROP_SAMPLES           = &H3???
%MFT_MESSAGE_SET_D3D_MANAGER        = &H2???
%MFT_MESSAGE_DROP_SAMPLES           = &H3???
%MFT_MESSAGE_NOTIFY_BEGIN_STREAMING = &H10000000???
%MFT_MESSAGE_NOTIFY_END_STREAMING   = &H10000001???
%MFT_MESSAGE_NOTIFY_END_OF_STREAM   = &H10000002???
%MFT_MESSAGE_NOTIFY_START_OF_STREAM = &H10000003???
%MFT_MESSAGE_COMMAND_MARKER         = &H20000000???

' // Size = 24 bytes
TYPE MFT_INPUT_STREAM_INFO   ' Must be 8 byte aligned
   hnsMaxLatency  AS QUAD    ' LONGLONG
   dwFlags        AS DWORD   ' DWORD
   cbSize         AS DWORD   ' DWORD
   cbMaxLookahead AS DWORD   ' DWORD
   cbAlignment    AS DWORD   ' DWORD
END TYPE

' // Size = 12 bytes
TYPE MFT_OUTPUT_STREAM_INFO DWORD
   dwFlags     AS DWORD   ' DWORD
   cbSize      AS DWORD   ' DWORD
   cbAlignment AS DWORD   ' DWORD
END TYPE

' // Size = 16 bytes
TYPE MFT_OUTPUT_DATA_BUFFER DWORD
   dwStreamID AS DWORD       ' DWORD
   pSample    AS DWORD PTR   ' IMFSample *
   dwStatus   AS DWORD       ' DWORD
   pEvents    AS DWORD PTR   ' IMFCollection *
END TYPE

'typedef struct _MFT_OUTPUT_DATA_BUFFER *PMFT_OUTPUT_DATA_BUFFER;


' ########################################################################################
' Interface name = IMFTransform
' IID = BF94C121-5B05-4E6F-8000-BA598961414D
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMFTransform_INTERFACE_DEFINED)
    %IMFTransform_INTERFACE_DEFINED = 1

$IID_IMFTransform = GUID$("{BF94C121-5B05-4E6F-8000-BA598961414D}")

INTERFACE IMFTransform $IID_IMFTransform

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetStreamLimits ( _                           ' VTable offset = 12
     BYREF pdwInputMinimum AS DWORD _                   ' __out DWORD *pdwInputMinimum
   , BYREF pdwInputMaximum AS DWORD _                   ' __out DWORD *pdwInputMaximum
   , BYREF pdwOutputMinimum AS DWORD _                  ' __out DWORD *pdwOutputMinimum
   , BYREF pdwOutputMaximum AS DWORD _                  ' __out DWORD *pdwOutputMaximum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetStreamCount ( _                            ' VTable offset = 16
     BYREF pcInputStreams AS DWORD _                    ' __out DWORD *pcInputStreams
   , BYREF pcOutputStreams AS DWORD _                   ' __out DWORD *pcOutputStreams
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetStreamIDs ( _                              ' VTable offset = 20
     BYVAL dwInputIDArraySize AS DWORD _                ' __in  DWORD dwInputIDArraySize
   , BYREF pdwInputIDs AS DWORD _                       ' __out DWORD *pdwInputIDs
   , BYVAL dwOutputIDArraySize AS DWORD _               ' __in  DWORD dwOutputIDArraySize
   , BYREF pdwOutputIDs AS DWORD _                      ' __out DWORD *pdwOutputIDs
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetInputStreamInfo ( _                        ' VTable offset = 24
     BYVAL dwInputStreamID AS DWORD _                   ' __in  DWORD dwInputStreamID
   , BYREF pStreamInfo AS DWORD _                       ' __out MFT_INPUT_STREAM_INFO *pStreamInfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetOutputStreamInfo ( _                       ' VTable offset = 28
     BYVAL dwOutputStreamID AS DWORD _                  ' __in  DWORD dwOutputStreamID
   , BYREF pStreamInfo AS DWORD _                       ' __out MFT_OUTPUT_STREAM_INFO *pStreamInfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAttributes ( _                             ' VTable offset = 32
     BYREF pAttributes AS IMFAttributes _               ' __out IMFAttributes **pAttributes
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetInputStreamAttributes ( _                  ' VTable offset = 36
     BYVAL dwInputStreamID AS DWORD _                   ' __in  DWORD dwInputStreamID
   , BYREF pAttributes AS IMFAttributes _               ' __out IMFAttributes **pAttributes
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetOutputStreamAttributes ( _                 ' VTable offset = 40
     BYVAL dwOutputStreamID AS DWORD _                  ' __in  DWORD dwOutputStreamID
   , BYREF pAttributes AS IMFAttributes _               ' __out IMFAttributes **pAttributes
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DeleteInputStream ( _                         ' VTable offset = 44
     BYVAL dwStreamID AS DWORD _                        ' __in DWORD dwStreamID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddInputStreams ( _                           ' VTable offset = 48
     BYVAL cStreams AS DWORD _                          ' __in DWORD cStreams
   , BYVAL adwStreamIDs AS DWORD _                      ' __in DWORD *adwStreamIDs
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetInputAvailableType ( _                     ' VTable offset = 52
     BYVAL dwInputStreamID AS DWORD _                   ' __in  DWORD dwInputStreamID
   , BYVAL dwTypeIndex AS DWORD _                       ' __in  DWORD dwTypeIndex
   , BYREF ppType AS IMFMediaType _                     ' __out IMFMediaType **ppType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetOutputAvailableType ( _                    ' VTable offset = 56
     BYVAL dwOutputStreamID AS DWORD _                  ' __in  DWORD dwOutputStreamID
   , BYVAL dwTypeIndex AS DWORD _                       ' __in  DWORD dwTypeIndex
   , BYREF ppType AS IMFMediaType _                     ' __out IMFMediaType **ppType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetInputType ( _                              ' VTable offset = 60
     BYVAL dwInputStreamID AS DWORD _                   ' __in DWORD dwInputStreamID
   , BYVAL pType AS IMFMediaType _                      ' __in IMFMediaType *pType
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetOutputType ( _                             ' VTable offset = 64
     BYVAL dwOutputStreamID AS DWORD _                  ' __in DWORD dwOutputStreamID
   , BYVAL pType AS IMFMediaType _                      ' __in IMFMediaType *pType
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetInputCurrentType ( _                       ' VTable offset = 68
     BYVAL dwInputStreamID AS DWORD _                   ' __in  DWORD dwInputStreamID
   , BYREF ppType AS IMFMediaType _                     ' __out IMFMediaType **ppType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetOutputCurrentType ( _                      ' VTable offset = 72
     BYVAL dwOutputStreamID AS DWORD _                  ' __in  DWORD dwOutputStreamID
   , BYREF ppType AS IMFMediaType _                     ' __out IMFMediaType **ppType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetInputStatus ( _                            ' VTable offset = 76
     BYVAL dwInputStreamID AS DWORD _                   ' __in  DWORD dwInputStreamID
   , BYREF pdwFlags AS DWORD _                          ' __out DWORD *pdwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetOutputStatus ( _                           ' VTable offset = 80
     BYREF pdwFlags AS DWORD _                          ' __out DWORD *pdwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetOutputBounds ( _                           ' VTable offset = 84
     BYVAL hnsLowerBound AS QUAD _                      ' __in LONGLONG hnsLowerBound
   , BYVAL hnsUpperBound AS QUAD _                      ' __in LONGLONG hnsUpperBound
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ProcessEvent ( _                              ' VTable offset = 88
     BYVAL dwInputStreamID AS DWORD _                   ' __in DWORD dwInputStreamID
   , BYVAL pEvent AS IMFMediaEvent _                    ' __in IMFMediaEvent *pEvent
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ProcessMessage ( _                            ' VTable offset = 92
     BYVAL eMessage AS DWORD _                          ' __in MFT_MESSAGE_TYPE eMessage
   , BYVAL ulParam AS DWORD _                           ' __in ULONG_PTR ulParam
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ProcessInput ( _                              ' VTable offset = 96
     BYVAL dwInputStreamID AS DWORD _                   ' __in DWORD dwInputStreamID
   , BYVAL pSample AS IMFSample _                       ' __in IMFSample *pSample
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ProcessOutput ( _                             ' VTable offset = 100
     BYVAL dwFlags AS DWORD _                           ' __in  DWORD dwFlags
   , BYVAL cOutputBufferCount AS DWORD _                ' __in  DWORD cOutputBufferCount
   , BYREF pOutputSamples AS MFT_OUTPUT_DATA_BUFFER _   ' __in  MFT_OUTPUT_DATA_BUFFER *pOutputSamples
   , BYREF pdwStatus AS DWORD _                         ' __out DWORD *pdwStatus
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMFTransform_INTERFACE_DEFINED__ */

'#if (WINVER >= _WIN32_WINNT_WIN7)
' // Size = 20 bytes
TYPE STREAM_MEDIUM DWORD
   gidMedium        AS GUID    ' GUID
   unMediumInstance AS DWORD   ' UINT32
END TYPE
'#endif // (WINVER >= _WIN32_WINNT_WIN7)

MACRO MFPKEY_CLSID = GUID$("{c57a84c0-1a80-40a3-97b5-9272a403c8ae}") & MKDWD$(&H01???)
MACRO MFPKEY_CATEGORY = GUID$("{c57a84c0-1a80-40a3-97b5-9272a403c8ae}") & MKDWD$(&H02???)
MACRO MFPKEY_EXATTRIBUTE_SUPPORTED = GUID$("{456fe843-3c87-40c0-949d-1409c97dab2c}") & MKDWD$(&H01???)
MACRO MFPKEY_MULTICHANNEL_CHANNEL_MASK = GUID$("{58bdaf8c-3224-4692-86d0-44d65c5bf82b}") & MKDWD$(&H01???)

$MF_SA_D3D_AWARE                     = GUID$("{eaa35c29-775e-488e-9b61-b3283e49583b}")
$MF_SA_REQUIRED_SAMPLE_COUNT         = GUID$("{18802c61-324b-4952-abd0-176ff5c696ff}")
'#if (WINVER >= _WIN32_WINNT_WIN7)
$MF_TRANSFORM_ASYNC                  = GUID$("{f81a699a-649a-497d-8c73-29f8fed6ad7a}")
$MF_TRANSFORM_ASYNC_UNLOCK           = GUID$("{e5666d6b-3422-4eb6-a421-da7db1f8e207}")
$MF_TRANSFORM_FLAGS_Attribute        = GUID$("{9359bb7e-6275-46c4-a025-1c01e45f1a86}")
$MF_TRANSFORM_CATEGORY_Attribute     = GUID$("{ceabba49-506d-4757-a6ff-66c184987e4e}")
$MFT_TRANSFORM_CLSID_Attribute       = GUID$("{6821c42b-65a4-4e82-99bc-9a88205ecd0c}")
$MFT_INPUT_TYPES_Attributes          = GUID$("{4276c9b1-759d-4bf3-9cd0-0d723d138f96}")
$MFT_OUTPUT_TYPES_Attributes         = GUID$("{8eae8cf3-a44f-4306-ba5c-bf5dda242818}")
$MFT_ENUM_HARDWARE_URL_Attribute     = GUID$("{2fb866ac-b078-4942-ab6c-003d05cda674}")
$MFT_FRIENDLY_NAME_Attribute         = GUID$("{314ffbae-5b41-4c95-9c19-4e7d586face3}")
$MFT_CONNECTED_STREAM_ATTRIBUTE      = GUID$("{71eeb820-a59f-4de2-bcec-38db1dd611a4}")
$MFT_CONNECTED_TO_HW_STREAM          = GUID$("{34e6e728-06d6-4491-a553-4795650db912}")
$MFT_PREFERRED_OUTPUTTYPE_Attribute  = GUID$("{7e700499-396a-49ee-b1b4-f628021e8c9d}")
$MFT_PROCESS_LOCAL_Attribute         = GUID$("{543186e4-4649-4e65-b588-4aa352aff379}")
$MFT_PREFERRED_ENCODER_PROFILE       = GUID$("{53004909-1ef5-46d7-a18e-5a75f8b5905f}")
$MFT_HW_TIMESTAMP_WITH_QPC_Attribute = GUID$("{8d030fb8-cc43-4258-a22e-9210bef89be4}")
$MFT_FIELDOFUSE_UNLOCK_Attribute     = GUID$("{8ec2e9fd-9148-410d-831e-702439461a8e}")
$MFT_CODEC_MERIT_Attribute           = GUID$("{88a7cb15-7b07-4a34-9128-e64c6703c4d3}")
$MFT_ENUM_TRANSCODE_ONLY_ATTRIBUTE   = GUID$("{111ea8cd-b62a-4bdb-89f6-67ffcdc2458b}")

DECLARE FUNCTION MFCreateTransformActivate IMPORT "Mfplat.dll" ALIAS "MFCreateTransformActivate" ( _
   BYREF ppActivate AS IMFActivate _                    ' __out IMFActivate** ppActivate
 ) AS LONG                                              ' HRESULT

'#endif // (WINVER >= _WIN32_WINNT_WIN7)
