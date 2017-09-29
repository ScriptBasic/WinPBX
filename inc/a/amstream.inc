' ########################################################################################
' Microsoft Windows
' File: amstream.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%AMSTREAM_INC = 1

#INCLUDE ONCE "ddraw.inc"
#INCLUDE ONCE "strmif.inc"
#INCLUDE ONCE "mmsystem.inc"
#INCLUDE ONCE "mmstream.inc"
#INCLUDE ONCE "ddstream.inc"
#INCLUDE ONCE "austream.inc"

'enum __MIDL___MIDL_itf_amstream_0000_0001
%AMMSF_NOGRAPHTHREAD      = &H1

'enum __MIDL___MIDL_itf_amstream_0000_0002
%AMMSF_ADDDEFAULTRENDERER = &H1
%AMMSF_CREATEPEER         = &H2
%AMMSF_STOPIFNOSAMPLES    = &H4
%AMMSF_NOSTALL            = &H8

'enum __MIDL___MIDL_itf_amstream_0000_0003
%AMMSF_RENDERTYPEMASK     = &H3
%AMMSF_RENDERTOEXISTING   = 0
%AMMSF_RENDERALLSTREAMS   = &H1
%AMMSF_NORENDER           = &H2
%AMMSF_NOCLOCK            = &H4
%AMMSF_RUN                = &H8

' OUTPUT_STATE enum
MACRO OUTPUT_STATE_ENUM = LONG
%Disabled   = 0
%ReadData   = 1
%RenderData = 2

$CLSID_AMMultiMediaStream = GUID$("{49C47CE5-9BA4-11D0-8212-00C04FC32C45}")
$CLSID_AMDirectDrawStream = GUID$("{49C47CE4-9BA4-11D0-8212-00C04FC32C45}")
$CLSID_AMAudioStream      = GUID$("{8496E040-AF4C-11D0-8212-00C04FC32C45}")
$CLSID_AMAudioData        = GUID$("{F2468580-AF8A-11D0-8212-00C04FC32C45}")
$CLSID_AMMediaTypeStream  = GUID$("{CF0F2F7C-F7BF-11D0-900D-00C04FD9189D}")

' ########################################################################################
' Interface name = IDirectShowStream
' IID = {7DB01C96-C0C3-11D0-8FF1-00C04FD9189D}
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IDirectShowStream_INTERFACE_DEFINED)
    %IDirectShowStream_INTERFACE_DEFINED = 1

$IID_IDirectShowStream = GUID$("{7DB01C96-C0C3-11D0-8FF1-00C04FD9189D}")

INTERFACE IDirectShowStream $IID_IDirectShowStream

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET FileName <1> ( _                        ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *pVal
   ' =====================================================================================
   PROPERTY SET FileName <1> ( _                        ' VTable offset = 32
     BYVAL newVal AS WSTRING _                          ' __in BSTR newVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Video <2> ( _                           ' VTable offset = 36
   ) AS OUTPUT_STATE_ENUM                               ' __retval_out OUTPUT_STATE *pVal
   ' =====================================================================================
   PROPERTY SET Video <2> ( _                           ' VTable offset = 40
     BYVAL newVal AS OUTPUT_STATE_ENUM _                ' __in OUTPUT_STATE newVal
   )                                                    ' void
   ' =====================================================================================
   PROPERTY GET Audio <3> ( _                           ' VTable offset = 44
   ) AS OUTPUT_STATE_ENUM                               ' __retval_out OUTPUT_STATE *pVal
   ' =====================================================================================
   PROPERTY SET Audio <3> ( _                           ' VTable offset = 48
     BYVAL newVal AS OUTPUT_STATE_ENUM _                ' __in OUTPUT_STATE newVal
   )                                                    ' void
   ' =====================================================================================

END INTERFACE ' IDirectShowStream

#ENDIF   ' /* __IDirectShowStream_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IAMMultiMediaStream
' IID = {BEBE595C-9A6F-11D0-8FDE-00C04FD9189D}
' Inherited interface = IMultiMediaStream
' ########################################################################################

#IF NOT %DEF(%IAMMultiMediaStream_INTERFACE_DEFINED)
    %IAMMultiMediaStream_INTERFACE_DEFINED = 1

$IID_IAMMultiMediaStream = GUID$("{BEBE595C-9A6F-11D0-8FDE-00C04FD9189D}")

INTERFACE IAMMultiMediaStream $IID_IAMMultiMediaStream

   INHERIT IUnknown

   ' =====================================================================================
   ' IMultimediaStream Methods
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

   ' =====================================================================================
   ' IAMMultiMediaStream Methods
   ' =====================================================================================
   METHOD Initialize ( _                                ' VTable offset = 48
     BYVAL StreamType AS STREAM_TYPE_ENUM _             ' __in STREAM_TYPE StreamType
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYVAL pFilterGraph AS IGraphBuilder _              ' __in IGraphBuilder *pFilterGraph
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFilterGraph ( _                            ' VTable offset = 52
     BYREF ppGraphBuilder AS IGraphBuilder _            ' __out IGraphBuilder **ppGraphBuilder
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFilter ( _                                 ' VTable offset = 56
     BYREF ppFilter AS IMediaStreamFilter _             ' __out IMediaStreamFilter **ppFilter
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddMediaStream ( _                            ' VTable offset = 60
     BYVAL pStreamObject AS IUnknown _                  ' __in IUnknown *pStreamObject
   , BYREF PurposeId AS GUID _                          ' __in const MSPID *PurposeId
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF ppNewStream AS IMediaStream _                ' __out IMediaStream **ppNewStream
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OpenFile ( _                                  ' VTable offset = 64
     BYREF pszFileName AS WSTRINGZ _                    ' __in LPCWSTR pszFileName
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OpenMoniker ( _                               ' VTable offset = 68
     BYVAL pCtx AS IBindCtx _                           ' __in IBindCtx *pCtx
   , BYVAL pMoniker AS IMoniker _                       ' __in IMoniker *pMoniker
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Render ( _                                    ' VTable offset = 72
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAMMultiMediaStream_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IAMMediaStream
' IID = {BEBE595D-9A6F-11d0-8FDE-00C04FD9189D}
' Inherited interface = IMediaStream
' ########################################################################################

#IF NOT %DEF(%IAMMediaStream_INTERFACE_DEFINED)
    %IAMMediaStream_INTERFACE_DEFINED = 1

$IID_IAMMediaStream = GUID$("{BEBE595D-9A6F-11d0-8FDE-00C04FD9189D}")

INTERFACE IAMMediaStream $IID_IAMMediaStream

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
   ' IAMMediaStream Methods
   ' =====================================================================================
   METHOD Initialize ( _                                ' VTable offset = 36
     BYVAL pSourceObject AS IUnknown _                  ' __in IUnknown *pSourceObject
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF PurposeId AS GUID _                          ' __in REFMSPID PurposeId
   , BYVAL StreamType AS STREAM_TYPE_ENUM _             ' __in const STREAM_TYPE StreamType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetState ( _                                  ' VTable offset = 40
     BYVAL State AS DWORD _                             ' __in FILTER_STATE State
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD JoinAMMultiMediaStream ( _                    ' VTable offset = 44
     BYVAL pAMMultiMediaStream AS IAMMultiMediaStream _ ' __in IAMMultiMediaStream *pAMMultiMediaStream)
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD JoinFilter ( _                                ' VTable offset = 48
     BYVAL pMediaStreamFilter AS IMediaStreamFilter _   ' __in IMediaStreamFilter *pMediaStreamFilter
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD JoinFilterGraph ( _                           ' VTable offset = 52
     BYVAL pFilterGraph AS IFilterGraph _               ' __in IFilterGraph *pFilterGraph
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAMMediaStream_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IMediaStreamFilter
' IID = {BEBE595E-9A6F-11D0-8FDE-00C04FD9189D}
' Inherited interface = IBaseFilter
' ########################################################################################

#IF NOT %DEF(%IMediaStreamFilter_INTERFACE_DEFINED)
    %IMediaStreamFilter_INTERFACE_DEFINED = 1

$IID_IMediaStreamFilter = GUID$("{BEBE595E-9A6F-11D0-8FDE-00C04FD9189D}")

INTERFACE IMediaStreamFilter $IID_IMediaStreamFilter

   INHERIT IUnknown

   ' =====================================================================================
   ' IBaseFilter Methods
   ' =====================================================================================
   METHOD GetClassID ( _                                ' VTable offset = 12
     BYREF pClassID AS GUID _                           ' __out CLSID * pClassID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Stop ( _                                      ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Pause ( _                                     ' VTable offset = 20
     BYREF tStart AS QUAD _                             ' __out REFERENCE_TIME tStart
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Run ( _                                       ' VTable offset = 24
     BYREF tStart AS QUAD _                             ' __out REFERENCE_TIME tStart
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetState ( _                                  ' VTable offset = 28
     BYVAL dwMilliSecsTimeout AS DWORD _                ' __in DWORD dwMilliSecsTimeout
   , BYREF State AS DWORD _                             ' __out FILTER_STATE *State
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetSyncSource ( _                             ' VTable offset = 32
     BYVAL pClock AS IReferenceClock _                  ' __in IReferenceClock *pClock
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSyncSource ( _                             ' VTable offset = 36
     BYREF pClock AS IReferenceClock _                  ' __out IReferenceClock **pClock
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumPins ( _                                  ' VTable offset = 40
     BYREF ppEnum AS IEnumPins _                        ' __out IEnumPins **ppEnum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD FindPin ( _                                   ' VTable offset = 44
     BYREF Id AS WSTRINGZ _                             ' __in LPCWSTR Id
   , BYREF ppPin AS IPin _                              ' __out IPin **ppPin
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD QueryFilterInfo ( _                           ' VTable offset = 48
     BYREF pInfo AS FILTER_INFO _                       ' __out FILTER_INFO *pInfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD JoinFilterGraph ( _                           ' VTable offset = 52
     BYVAL pGraph AS IFilterGraph _                     ' __in IFilterGraph *pGraph
   , BYREF pName AS WSTRINGZ _                          ' __in LPCWSTR pName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD QueryVendorInfo ( _                           ' VTable offset = 56
     BYREF pVendorInfo AS DWORD _                       ' __out LPWSTR *pVendorInfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IMediaStreamFilter Methods
   ' =====================================================================================
   METHOD AddMediaStream ( _                            ' VTable offset = 60
     BYVAL pAMMediaStream AS IAMMediaStream _           ' __in IAMMediaStream *pAMMediaStream)
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMediaStream ( _                            ' VTable offset = 64
     BYREF idPurpose AS GUID _                          ' __in REFMSPID idPurpose
   , BYREF ppMediaStream AS IMediaStream _              ' __out IMediaStream **ppMediaStream
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumMediaStreams ( _                          ' VTable offset = 68
     BYVAL Index AS LONG _                              ' __in long Index
   , BYREF ppMediaStream AS IMediaStream _              ' __out IMediaStream **ppMediaStream
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SupportSeeking ( _                            ' VTable offset = 72
     BYVAL bRenderer AS LONG _                          ' __in BOOL bRenderer
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ReferenceTimeToStreamTime ( _                 ' VTable offset = 76
     BYREF pTime AS QUAD _                              ' __out_in REFERENCE_TIME *pTime
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCurrentStreamTime ( _                      ' VTable offset = 80
     BYREF pCurrentStreamTime AS QUAD _                 ' __out REFERENCE_TIME *pCurrentStreamTime
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD WaitUntil ( _                                 ' VTable offset = 84
     BYVAL WaitStreamTime AS QUAD _                     ' __in REFERENCE_TIME WaitStreamTime
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Flush ( _                                     ' VTable offset = 88
     BYVAL bCancelEOS AS LONG _                         ' __in BOOL bCancelEOS
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EndOfStream ( _                               ' VTable offset = 92
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMediaStreamFilter_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IDirectDrawMediaSampleAllocator
' IID = {AB6B4AFC-F6E4-11D0-900D-00C04FD9189D}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDirectDrawMediaSampleAllocator_INTERFACE_DEFINED)
    %IDirectDrawMediaSampleAllocator_INTERFACE_DEFINED = 1

$IID_IDirectDrawMediaSampleAllocator = GUID$("{AB6B4AFC-F6E4-11D0-900D-00C04FD9189D}")

INTERFACE IDirectDrawMediaSampleAllocator $IID_IDirectDrawMediaSampleAllocator

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetDirectDraw ( _                             ' VTable offset = 12
     BYREF ppDirectDraw AS IDirectDraw _                ' __in IDirectDraw **ppDirectDraw
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDirectDrawMediaSampleAllocator_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IDirectDrawMediaSample
' IID = {AB6B4AFE-F6E4-11D0-900D-00C04FD9189D}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDirectDrawMediaSample_INTERFACE_DEFINED)
    %IDirectDrawMediaSample_INTERFACE_DEFINED = 1

$IID_IDirectDrawMediaSample = GUID$("{AB6B4AFE-F6E4-11D0-900D-00C04FD9189D}")

INTERFACE IDirectDrawMediaSample $IID_IDirectDrawMediaSample

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetSurfaceAndReleaseLock ( _                  ' VTable offset = 12
     BYREF ppDirectDrawSurface AS IDirectDrawSurface _  ' __out IDirectDrawSurface **ppDirectDrawSurface
   , BYREF pRect AS RECT _                              ' __out RECT *pRect
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD LockMediaSamplePointer ( _                    ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDirectDrawMediaSample_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IAMMediaTypeStream
' IID = {AB6B4AFA-F6E4-11D0-900D-00C04FD9189D}
' Inherited interface = IMediaStream
' ########################################################################################

#IF NOT %DEF(%IAMMediaTypeStream_INTERFACE_DEFINED)
    %IAMMediaTypeStream_INTERFACE_DEFINED = 1

$IID_IAMMediaTypeStream = GUID$("{AB6B4AFA-F6E4-11D0-900D-00C04FD9189D}")

INTERFACE IAMMediaTypeStream $IID_IAMMediaTypeStream

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
   ' IAMMediaTypeStream Methods
   ' =====================================================================================
   METHOD GetFormat ( _                                 ' VTable offset = 36
     BYREF pMediaType AS AM_MEDIA_TYPE _                ' __out AM_MEDIA_TYPE *pMediaType
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetFormat ( _                                 ' VTable offset = 40
     BYREF pMediaType AS AM_MEDIA_TYPE _                ' __in AM_MEDIA_TYPE *pMediaType
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateSample ( _                              ' VTable offset = 44
     BYVAL lSampleSize AS LONG _                        ' __in long lSampleSize
   , BYVAL pbBuffer AS BYTE PTR _                       ' __in BYTE *pbBuffer
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYVAL pUnkOuter AS IUnknown _                      ' __in IUnknown *pUnkOuter
   , BYREF ppAMMediaTypeSample AS IAMMediaTypeSample _  ' __out IAMMediaTypeSample **ppAMMediaTypeSample
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetStreamAllocatorRequirements ( _            ' VTable offset = 48
     BYREF pProps AS ALLOCATOR_PROPERTIES _             ' __out ALLOCATOR_PROPERTIES *pProps
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetStreamAllocatorRequirements ( _            ' VTable offset = 52
     BYREF pProps AS ALLOCATOR_PROPERTIES _             ' __in ALLOCATOR_PROPERTIES *pProps
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAMMediaTypeStream_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IAMMediaTypeSample
' IID = {AB6B4AFB-F6E4-11D0-900D-00C04FD9189D}
' Inherited interface = IStreamSample
' ########################################################################################

#IF NOT %DEF(%IAMMediaTypeSample_INTERFACE_DEFINED)
    %IAMMediaTypeSample_INTERFACE_DEFINED = 1

$IID_IAMMediaTypeSample = GUID$("{AB6B4AFB-F6E4-11D0-900D-00C04FD9189D}")

INTERFACE IAMMediaTypeSample $IID_IAMMediaTypeSample

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
   ' IAMMediaTypeSample Methods
   ' =====================================================================================
   METHOD SetPointer ( _                                ' VTable offset = 32
     BYVAL pBuffer AS BYTE PTR _                        ' __in BYTE *pBuffer
   , BYVAL lSize AS LONG _                              ' __in long lSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPointer ( _                                ' VTable offset = 36
     BYREF ppBuffer AS DWORD _                          ' __out BYTE **ppBuffer
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSize ( _                                   ' VTable offset = 40
   ) AS LONG                                            ' LONG
   ' =====================================================================================
   METHOD GetTime ( _                                   ' VTable offset = 44
     BYREF pTimeStart AS QUAD _                         ' __out REFERENCE_TIME *pTimeStart
   , BYREF pTimeEnd AS QUAD _                           ' __out REFERENCE_TIME *pTimeEnd
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetTime ( _                                   ' VTable offset = 48
     BYREF pTimeStart AS QUAD _                         ' __in REFERENCE_TIME *pTimeStart
   , BYREF pTimeEnd AS QUAD _                           ' __in REFERENCE_TIME *pTimeEnd
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsSyncPoint ( _                               ' VTable offset = 52
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetSyncPoint ( _                              ' VTable offset = 56
     BYVAL bIsSyncPoint AS LONG _                       ' __in BOOL bIsSyncPoint
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsPreroll ( _                                 ' VTable offset = 60
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPreroll ( _                                ' VTable offset = 64
     BYVAL bIsPreroll AS LONG _                         ' __in BOOL bIsPreroll
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetActualDataLength ( _                       ' VTable offset = 68
   ) AS LONG                                            ' LONG
   ' =====================================================================================
   METHOD SetActualDataLength ( _                       ' VTable offset = 72
     BYVAL lActual AS LONG _                            ' __in long lActual
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMediaType ( _                              ' VTable offset = 76
     BYREF ppMediaType AS AM_MEDIA_TYPE _               ' __out AM_MEDIA_TYPE **ppMediaType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetMediaType ( _                              ' VTable offset = 80
     BYREF ppMediaType AS AM_MEDIA_TYPE _               ' __in AM_MEDIA_TYPE *ppMediaType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsDiscontinuity ( _                           ' VTable offset = 84
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetDiscontinuity ( _                          ' VTable offset = 88
     BYVAL bDiscontinuity AS LONG _                     ' __in BOOL bDiscontinuity
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMediaTime ( _                              ' VTable offset = 92
     BYREF pTimeStart AS QUAD _                         ' __out LONGLONG *pTimeStart
   , BYREF pTimeEnd AS QUAD _                           ' __out LONGLONG *pTimeEnd
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetMediaTime ( _                              ' VTable offset = 96
     BYVAL pTimeStart AS QUAD _                         ' __in LONGLONG *pTimeStart
   , BYVAL pTimeEnd AS QUAD _                           ' __in LONGLONG *pTimeEnd
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAMMediaTypeSample_INTERFACE_DEFINED__ */
