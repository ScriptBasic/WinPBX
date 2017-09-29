' ########################################################################################
' Microsoft Windows
' File: MMStream.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%MMSTREAN_INC = 1

'#define MS_ERROR_CODE(x) MAKE_HRESULT(1, FACILITY_ITF, (x) + 0x400)
'#define MS_SUCCESS_CODE(x) MAKE_HRESULT(0, FACILITY_ITF, x)

%MS_S_PENDING              = &H00040001&   ' MS_SUCCESS_CODE(1)
%MS_S_NOUPDATE             = &H00040002&   ' MS_SUCCESS_CODE(2)
%MS_S_ENDOFSTREAM          = &H00040003&   ' MS_SUCCESS_CODE(3)
%MS_E_SAMPLEALLOC          = &H80040401&   ' MS_ERROR_CODE(1)
%MS_E_PURPOSEID            = &H80040402&   ' MS_ERROR_CODE(2)
%MS_E_NOSTREAM             = &H80040403&   ' MS_ERROR_CODE(3)
%MS_E_NOSEEKING            = &H80040404&   ' MS_ERROR_CODE(4)
%MS_E_INCOMPATIBLE         = &H80040405&   ' MS_ERROR_CODE(5)
%MS_E_BUSY                 = &H80040406&   ' MS_ERROR_CODE(6)
%MS_E_NOTINIT              = &H80040407&   ' MS_ERROR_CODE(7)
%MS_E_SOURCEALREADYDEFINED = &H80040408&   ' MS_ERROR_CODE(8)
%MS_E_INVALIDSTREAMTYPE    = &H80040409&   ' MS_ERROR_CODE(9)
%MS_E_NOTRUNNING           = &H8004040A&   ' MS_ERROR_CODE(10)

$MSPID_PrimaryVideo = GUID$("{A35FF56A-9FDA-11D0-8FDF-00C04FD9189D}")
$MSPID_PrimaryAudio = GUID$("{A35FF56B-9FDA-11D0-8FDF-00C04FD9189D}")

'#if(_WIN32_WINNT < 0x0400)
'typedef void ( __stdcall *PAPCFUNC )(
'    DWORD_PTR dwParam);
'#endif

'typedef LONGLONG STREAM_TIME;
'typedef GUID MSPID;
'typedef REFGUID REFMSPID;

'MACRO STREAM_TIME = QUAD
'MACRO MSPID = GUID
'MACRO REFMSPID = GUID

' STREAM_TYPE enum
MACRO STREAM_TYPE_ENUM = LONG
%STREAMTYPE_READ      = 0
%STREAMTYPE_WRITE     = 1
%STREAMTYPE_TRANSFORM = 2

' STREAM_STATE enum
MACRO STREAM_STATE_ENUM = LONG
%STREAMSTATE_STOP = 0
%STREAMSTATE_RUN  = 1

' COMPLETION_STATUS_FLAGS enum
MACRO COMPLETION_STATUS_FLAGS_ENUM = DWORD
%COMPSTAT_NOUPDATEOK = &H1
%COMPSTAT_WAIT       = &H2
%COMPSTAT_ABORT      = &H4

'enum __MIDL___MIDL_itf_mmstream_0000_0004
%MMSSF_HASCLOCK     = &H1
%MMSSF_SUPPORTSEEK  = &H2
%MMSSF_ASYNCHRONOUS = &H4

'enum __MIDL___MIDL_itf_mmstream_0000_0005
%SSUPDATE_ASYNC      = &H1
%SSUPDATE_CONTINUOUS = &H2

' ########################################################################################
' Interface name = IMultiMediaStream
' IID = {B502D1BC-9A57-11d0-8FDE-00C04FD9189D}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMultiMediaStream_INTERFACE_DEFINED)
    %IMultiMediaStream_INTERFACE_DEFINED = 1

$IID_IMultiMediaStream = GUID$("{B502D1BC-9A57-11d0-8FDE-00C04FD9189D}")

INTERFACE IMultiMediaStream $IID_IMultiMediaStream

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetInformation ( _                            ' VTable offset = 12
     BYREF pdwFlags AS DWORD _                          ' __out DWORD *pdwFlags
   , BYREF pStreamType AS STREAM_TYPE_ENUM _            ' __out STREAM_TYPE *pStreamType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMediaStream ( _                            ' VTable offset = 16
     BYREF idPurpose AS GUID _                          ' __in REFMSPID idPurpose
   , BYREF ppMediaStream AS IMediaStream _              ' __out IMediaStream **ppMediaStream
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumMediaStreams ( _                          ' VTable offset = 20
     BYVAL Index AS LONG _                              ' __in long Index
   , BYREF ppMediaStream AS IMediaStream _              ' __out IMediaStream **ppMediaStream
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetState ( _                                  ' VTable offset = 24
     BYREF pCurrentState AS STREAM_STATE_ENUM _         ' __out STREAM_STATE *pCurrentState
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetState ( _                                  ' VTable offset = 28
     BYVAL NewState AS STREAM_STATE_ENUM _              ' __in STREAM_STATE NewState
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTime ( _                                   ' VTable offset = 32
     BYREF pCurrentTime AS QUAD _                       ' __out STREAM_TIME *pCurrentTime
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDuration ( _                               ' VTable offset = 36
     BYREF pDuration AS QUAD _                          ' __out STREAM_TIME *pDuration
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Seek ( _                                      ' VTable offset = 40
     BYVAL SeekTime AS QUAD _                           ' __in STREAM_TIME SeekTime
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetEndOfStreamEventHandle ( _                 ' VTable offset = 44
     BYREF phEOS AS DWORD _                             ' __out HANDLE *phEOS
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMultiMediaStream_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IMediaStream
' IID = {B502D1BD-9A57-11D0-8FDE-00C04FD9189D}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMediaStream_INTERFACE_DEFINED)
    %IMediaStream_INTERFACE_DEFINED = 1

$IID_IMediaStream = GUID$("{B502D1BD-9A57-11D0-8FDE-00C04FD9189D}")

INTERFACE IMediaStream $IID_IMediaStream

   INHERIT IUnknown

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

END INTERFACE

#ENDIF   ' /* __IMediaStream_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IStreamSample
' IID = {B502D1BE-9A57-11D0-8FDE-00C04FD9189D}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IStreamSample_INTERFACE_DEFINED)
    %IStreamSample_INTERFACE_DEFINED = 1

$IID_IStreamSample = GUID$("{B502D1BE-9A57-11D0-8FDE-00C04FD9189D}")

INTERFACE IStreamSample $IID_IStreamSample

   INHERIT IUnknown

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

END INTERFACE

#ENDIF   ' /* __IStreamSample_INTERFACE_DEFINED__ */
