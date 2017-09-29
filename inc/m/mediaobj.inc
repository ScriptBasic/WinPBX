' ########################################################################################
' Microsoft Windows
' File: mediaobj.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%MEDIAOBJ_INC = 1

' // Size = 72 bytes
TYPE DMO_MEDIA_TYPE DWORD
  majortype            AS GUID        ' GUID      majortype
  subtype              AS GUID        ' GUID      subtype
  bFixedSizeSamples    AS LONG        ' BOOL      bFixedSizeSamples
  bTemporalCompression AS LONG        ' BOOL      bTemporalCompression
  lSampleSize          AS DWORD       ' ULONG     lSampleSize
  formattype           AS GUID        ' GUID      formattype
  pUnk                 AS DWORD PTR   ' IUnknown  *pUnk
  cbFormat             AS DWORD       ' ULONG     cbFormat
  pbFormat             AS BYTE PTR    ' [size_is(cbFormat)] BYTE *pbFormat
END TYPE

'typedef LONGLONG REFERENCE_TIME;

' enum DMO_INPUT_DATA_BUFFER_FLAGS
%DMO_INPUT_DATA_BUFFERF_SYNCPOINT   = &H1
%DMO_INPUT_DATA_BUFFERF_TIME        = &H2
%DMO_INPUT_DATA_BUFFERF_TIMELENGTH  = &H4

' enum DMO_OUTPUT_DATA_BUFFER_FLAGS
%DMO_OUTPUT_DATA_BUFFERF_SYNCPOINT  = &H1
%DMO_OUTPUT_DATA_BUFFERF_TIME       = &H2
%DMO_OUTPUT_DATA_BUFFERF_TIMELENGTH = &H4
%DMO_OUTPUT_DATA_BUFFERF_INCOMPLETE = &H1000000

' enum DMO_INPUT_STATUS_FLAGS
%DMO_INPUT_STATUSF_ACCEPT_DATA      = &H1

' enum DMO_INPUT_STREAM_INFO_FLAGS
%DMO_INPUT_STREAMF_WHOLE_SAMPLES            = &H1
%DMO_INPUT_STREAMF_SINGLE_SAMPLE_PER_BUFFER = &H2
%DMO_INPUT_STREAMF_FIXED_SAMPLE_SIZE        = &H4
%DMO_INPUT_STREAMF_HOLDS_BUFFERS            = &H8

' enum DMO_OUTPUT_STREAM_INFO_FLAGS
%DMO_OUTPUT_STREAMF_WHOLE_SAMPLES            = &H1
%DMO_OUTPUT_STREAMF_SINGLE_SAMPLE_PER_BUFFER = &H2
%DMO_OUTPUT_STREAMF_FIXED_SAMPLE_SIZE        = &H4
%DMO_OUTPUT_STREAMF_DISCARDABLE              = &H8
%DMO_OUTPUT_STREAMF_OPTIONAL                 = &H10

' enum DMO_SET_TYPE_FLAGS
%DMO_SET_TYPEF_TEST_ONLY = &H1
%DMO_SET_TYPEF_CLEAR     = &H2

' enum DMO_PROCESS_OUTPUT_FLAGS
%DMO_PROCESS_OUTPUT_DISCARD_WHEN_NO_BUFFER   = &H1


' ########################################################################################
' Interface name = IMediaBuffer
' IID = {59EFF8B9-938C-4A26-82F2-95CB84CDC837}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMediaBuffer_INTERFACE_DEFINED)
    %IMediaBuffer_INTERFACE_DEFINED = 1

$IID_IMediaBuffer = GUID$("{59EFF8B9-938C-4A26-82F2-95CB84CDC837}")

INTERFACE IMediaBuffer $IID_IMediaBuffer

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetLength ( _                                 ' VTable offset = 12
     BYVAL cbLength AS DWORD _                          ' __in DWORD cbLength
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMaxLength ( _                              ' VTable offset = 16
     BYREF pcbMaxLength AS DWORD _                      ' __out DWORD *pcbMaxLength
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetBufferAndLength ( _                        ' VTable offset = 20
     BYREF ppBuffer AS DWORD _                          ' __out BYTE **ppBuffer
   , BYREF pcbLength AS DWORD _                         ' __out DWORD *pcbLength
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMediaBuffer_INTERFACE_DEFINED__ */

' // Size = 24 bytes
TYPE DMO_OUTPUT_DATA_BUFFER QWORD FILL
   pBuffer      AS DWORD   ' IMediaBuffer *pBuffer
   dwStatus     AS DWORD   ' DWORD dwStatus
   rtTimestamp  AS QUAD    ' REFERENCE_TIME rtTimestamp
   rtTimelength AS QUAD    ' REFERENCE_TIME rtTimelength
END TYPE

' ########################################################################################
' Interface name = IMediaObject
' IID = {D8AD0F58-5494-4102-97C5-EC798E59BCF4}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMediaObject_INTERFACE_DEFINED)
    %IMediaObject_INTERFACE_DEFINED = 1

$IID_IMediaObject = GUID$("{D8AD0F58-5494-4102-97C5-EC798E59BCF4}")

INTERFACE IMediaObject $IID_IMediaObject

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetStreamCount ( _                            ' VTable offset = 12
     BYREF pcInputStreams AS DWORD _                    ' __out DWORD *pcInputStreams
   , BYREF pcOutputStreams AS DWORD _                   ' __out DWORD *pcOutputStreams
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetInputStreamInfo ( _                        ' VTable offset = 16
     BYVAL dwInputStreamIndex AS DWORD _                ' __in  DWORD dwInputStreamIndex
   , BYREF pdwFlags AS DWORD _                          ' __out DWORD *pdwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetOutputStreamInfo ( _                       ' VTable offset = 20
     BYVAL dwOutputStreamIndex AS DWORD _               ' __in  DWORD dwOutputStreamIndex
   , BYREF pdwFlags AS DWORD _                          ' __out DWORD *pdwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetInputType ( _                              ' VTable offset = 24
     BYVAL dwInputStreamIndex AS DWORD _                ' __in  DWORD dwInputStreamIndex
   , BYVAL dwTypeIndex AS DWORD _                       ' __in  DWORD dwTypeIndex
   , BYREF pmt AS DMO_MEDIA_TYPE _                      ' __out DMO_MEDIA_TYPE *pmt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetOutputType ( _                             ' VTable offset = 28
     BYVAL dwOutputStreamIndex AS DWORD _               ' __in  DWORD dwOutputStreamIndex
   , BYVAL dwTypeIndex AS DWORD _                       ' __in  DWORD dwTypeIndex
   , BYREF pmt AS DMO_MEDIA_TYPE _                      ' __out DMO_MEDIA_TYPE *pmt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetInputType ( _                              ' VTable offset = 32
     BYVAL dwInputStreamIndex AS DWORD _                ' __in DWORD dwInputStreamIndex
   , BYREF pmt AS DMO_MEDIA_TYPE _                      ' __in const DMO_MEDIA_TYPE *pmt
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetOutputType ( _                             ' VTable offset = 36
     BYVAL dwOutputStreamIndex AS DWORD _               ' __in DWORD dwOutputStreamIndex
   , BYREF pmt AS DMO_MEDIA_TYPE _                      ' __in const DMO_MEDIA_TYPE *pmt
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetInputCurrentType ( _                       ' VTable offset = 40
     BYVAL dwInputStreamIndex AS DWORD _                ' __in  DWORD dwInputStreamIndex
   , BYREF pmt AS DMO_MEDIA_TYPE _                      ' __out DMO_MEDIA_TYPE *pmt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetOutputCurrentType ( _                      ' VTable offset = 44
     BYVAL dwOutputStreamIndex AS DWORD _               ' __in  DWORD dwOutputStreamIndex
   , BYREF pmt AS DMO_MEDIA_TYPE _                      ' __out DMO_MEDIA_TYPE *pmt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetInputSizeInfo ( _                          ' VTable offset = 48
     BYVAL dwInputStreamIndex AS DWORD _                ' __in  DWORD dwInputStreamIndex
   , BYREF pcbSize AS DWORD _                           ' __out DWORD *pcbSize
   , BYREF pcbMaxLookahead AS DWORD _                   ' __out DWORD *pcbMaxLookahead
   , BYREF pcbAlignment AS DWORD _                      ' __out DWORD *pcbAlignment
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetOutputSizeInfo ( _                         ' VTable offset = 52
     BYVAL dwOutputStreamIndex AS DWORD _               ' __in  DWORD dwOutputStreamIndex
   , BYREF pcbSize AS DWORD _                           ' __out DWORD *pcbSize
   , BYREF pcbAlignment AS DWORD _                      ' __out DWORD *pcbAlignment
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetInputMaxLatency ( _                        ' VTable offset = 56
     BYVAL dwInputStreamIndex AS DWORD _                ' __in  DWORD dwInputStreamIndex
   , BYREF prtMaxLatency AS QUAD _                      ' __out REFERENCE_TIME *prtMaxLatency
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetInputMaxLatency ( _                        ' VTable offset = 60
     BYVAL dwInputStreamIndex AS DWORD _                ' __in  DWORD dwInputStreamIndex
   , BYVAL rtMaxLatency AS QUAD _                       ' __in  REFERENCE_TIME rtMaxLatency
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Flush ( _                                     ' VTable offset = 64
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Discontinuity ( _                             ' VTable offset = 68
     BYVAL dwInputStreamIndex AS DWORD _                ' __in DWORD dwInputStreamIndex
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AllocateStreamingResources ( _                ' VTable offset = 72
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD FreeStreamingResources ( _                    ' VTable offset = 76
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetInputStatus ( _                            ' VTable offset = 80
     BYVAL dwInputStreamIndex AS DWORD _                ' __in  DWORD dwInputStreamIndex
   , BYREF dwFlags AS DWORD _                           ' __out DWORD *dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ProcessInput ( _                              ' VTable offset = 84
     BYVAL dwInputStreamIndex AS DWORD _                ' __in DWORD dwInputStreamIndex
   , BYVAL pBuffer AS IMediaBuffer _                    ' __in IMediaBuffer *pBuffer
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYVAL rtTimestamp AS QUAD _                        ' __in REFERENCE_TIME rtTimestamp
   , BYVAL rtTimelength AS QUAD _                       ' __in REFERENCE_TIME rtTimelength
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ProcessOutput ( _                             ' VTable offset = 88
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYVAL cOutputBufferCount AS DWORD _                ' __in DWORD cOutputBufferCount
   , BYREF pOutputBuffers AS DMO_OUTPUT_DATA_BUFFER _   ' __in_out DMO_OUTPUT_DATA_BUFFER *pOutputBuffers
   , BYREF pdwStatus AS DWORD _                         ' __out DWORD *pdwStatus
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Lock ( _                                      ' VTable offset = 92
     BYVAL bLock AS LONG _                              ' __in LONG bLock
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMediaObject_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IEnumDMO
' IID = {2C3CD98A-2BFA-4A53-9C27-5249BA64BA0F}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IEnumDMO_INTERFACE_DEFINED)
    %IEnumDMO_INTERFACE_DEFINED = 1

$IID_IEnumDMO = GUID$("{2C3CD98A-2BFA-4A53-9C27-5249BA64BA0F}")

INTERFACE IEnumDMO $IID_IEnumDMO

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Next ( _                                      ' VTable offset = 12
     BYVAL cItemsToFetch AS DWORD _                     ' __in  DWORD cItemsToFetch
   , BYREF pCLSID AS GUID _                             ' __out CLSID *pCLSID
   , BYREF Names AS DWORD _                             ' __out WCHAR **Names
   , BYREF pcItemsFetched AS DWORD _                    ' __out DWORD *pcItemsFetched
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Skip ( _                                      ' VTable offset = 16
     BYVAL cItemsToFetch AS DWORD _                     ' __in DWORD cItemsToFetch
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reset ( _                                     ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 24
     BYREF ppEnum AS IEnumDMO _                         ' __out IEnumDMO **ppEnum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEnumDMO_INTERFACE_DEFINED__ */


' enum DMO_INPLACE_PROCESS_FLAGS
%DMO_INPLACE_NORMAL = 0
%DMO_INPLACE_ZERO   = &H1


' ########################################################################################
' Interface name = IMediaObjectInPlace
' IID = {651B9AD0-0FC7-4AA9-9538-D89931010741}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMediaObjectInPlace_INTERFACE_DEFINED)
    %IMediaObjectInPlace_INTERFACE_DEFINED = 1

$IID_IMediaObjectInPlace = GUID$("{651B9AD0-0FC7-4AA9-9538-D89931010741}")

INTERFACE IMediaObjectInPlace $IID_IMediaObjectInPlace

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Process ( _                                   ' VTable offset = 12
     BYVAL ulSize AS DWORD _                            ' __in ULONG ulSize
   , BYVAL pData AS BYTE PTR _                          ' __in_out BYTE *pData
   , BYVAL refTimeStart AS QUAD _                       ' __in REFERENCE_TIME refTimeStart
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 16
     BYREF ppMediaObject AS IMediaObjectInPlace _       ' __out IMediaObjectInPlace **ppMediaObject
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetLatency ( _                                ' VTable offset = 20
     BYREF pLatencyTime AS QUAD _                       ' __out REFERENCE_TIME *pLatencyTime
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMediaObjectInPlace_INTERFACE_DEFINED__ */


' enum DMO_QUALITY_STATUS_FLAGS
%DMO_QUALITY_STATUS_ENABLED   = &H1


' ########################################################################################
' Interface name = IDMOQualityControl
' IID = {65ABEA96-CF36-453F-AF8A-705E98F16260}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDMOQualityControl_INTERFACE_DEFINED)
    %IDMOQualityControl_INTERFACE_DEFINED = 1

$IID_IDMOQualityControl = GUID$("{65ABEA96-CF36-453F-AF8A-705E98F16260}")

INTERFACE IDMOQualityControl $IID_IDMOQualityControl

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetNow ( _                                    ' VTable offset = 12
     BYVAL rtNow AS QUAD _                              ' __in REFERENCE_TIME rtNow
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetStatus ( _                                 ' VTable offset = 16
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetStatus ( _                                 ' VTable offset = 20
     BYREF pdwFlags AS DWORD _                          ' __out DWORD *pdwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDMOQualityControl_INTERFACE_DEFINED__ */


' enum DMO_VIDEO_OUTPUT_STREAM_FLAGS
%DMO_VOSF_NEEDS_PREVIOUS_SAMPLE   = &H1


' ########################################################################################
' Interface name = IDMOVideoOutputOptimizations
' IID = {BE8F4F4E-5B16-4D29-B350-7F6B5D9298AC}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDMOVideoOutputOptimizations_INTERFACE_DEFINED)
    %IDMOVideoOutputOptimizations_INTERFACE_DEFINED = 1

$IID_IDMOVideoOutputOptimizations = GUID$("{BE8F4F4E-5B16-4D29-B350-7F6B5D9298AC}")

INTERFACE IDMOVideoOutputOptimizations $IID_IDMOVideoOutputOptimizations

   INHERIT IUnknown

   ' =====================================================================================
   METHOD QueryOperationModePreferences ( _             ' VTable offset = 12
     BYVAL ulOutputStreamIndex AS DWORD _               ' __in  ULONG ulOutputStreamIndex
   , BYREF pdwRequestedCapabilities AS DWORD _          ' __out DWORD *pdwRequestedCapabilities
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetOperationMode ( _                          ' VTable offset = 16
     BYVAL ulOutputStreamIndex AS DWORD _               ' __in ULONG ulOutputStreamIndex
   , BYVAL dwEnabledFeatures AS DWORD _                 ' __in DWORD dwEnabledFeatures
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCurrentOperationMode ( _                   ' VTable offset = 20
     BYVAL ulOutputStreamIndex AS DWORD _               ' __in  ULONG ulOutputStreamIndex
   , BYREF pdwEnabledFeatures AS DWORD _                ' __out DWORD *pdwEnabledFeatures
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCurrentSampleRequirements ( _              ' VTable offset = 24
     BYVAL ulOutputStreamIndex AS DWORD _               ' __in  ULONG ulOutputStreamIndex
   , BYREF pdwRequestedFeatures AS DWORD _              ' __out DWORD *pdwRequestedFeatures
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDMOVideoOutputOptimizations_INTERFACE_DEFINED__ */
