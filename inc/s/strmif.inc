' ########################################################################################
' Microsoft Windows
' File: strmif.inc
' Contents: Streams interfaces
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%STRMIF_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "unknwn.inc"
#INCLUDE ONCE "objidl.inc"
#INCLUDE ONCE "oaidl.inc"
#INCLUDE ONCE "ocidl.inc"
#INCLUDE ONCE "ddraw.inc"

%CDEF_CLASS_DEFAULT          = &H0001???
%CDEF_BYPASS_CLASS_MANAGER   = &H0002???
%CDEF_MERIT_ABOVE_DO_NOT_USE = &H0008???
%CDEF_DEVMON_CMGR_DEVICE     = &H0010???
%CDEF_DEVMON_DMO             = &H0020???
%CDEF_DEVMON_PNP_DEVICE      = &H0040???
%CDEF_DEVMON_FILTER          = &H0080???
%CDEF_DEVMON_SELECTIVE_MASK  = &H00f0???


' ########################################################################################
' Interface name = ICreateDevEnum
' IID = {29840822-5B84-11D0-BD3B-00A0C911CE86}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ICreateDevEnum_INTERFACE_DEFINED)
    %ICreateDevEnum_INTERFACE_DEFINED = 1

$IID_ICreateDevEnum = GUID$("{29840822-5B84-11D0-BD3B-00A0C911CE86}")

INTERFACE ICreateDevEnum $IID_ICreateDevEnum

   INHERIT IUnknown

   ' =====================================================================================
   METHOD CreateClassEnumerator ( _                     ' VTable offset = 12
     BYREF clsidDeviceClass AS GUID _                   ' __in  REFCLSID clsidDeviceClass
   , BYREF ppEnumMoniker AS IEnumMoniker _              ' __out IEnumMoniker **ppEnumMoniker
   , BYVAL dwFlags AS DWORD _                           ' __in  DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICreateDevEnum_INTERFACE_DEFINED__ */


%CHARS_IN_GUID = 39     ' // 128 bits, plus { - } punctuation and terminal null
                        '  // chars NOT BYTES in the standard representation
                        '  // e.g. {D3588AB0-0781-11ce-B03A-0020AF0BA770} + null

' // Size = 72 bytes
TYPE AM_MEDIA_TYPE DWORD
   majortype            AS GUID       ' GUID      majortype
   subtype              AS GUID       ' GUID      subtype
   bFixedSizeSamples    AS LONG       ' BOOL      bFixedSizeSamples
   bTemporalCompression AS LONG       ' BOOL      bTemporalCompression
   lSampleSize          AS DWORD      ' ULONG     lSampleSize
   formattype           AS GUID       ' GUID      formattype
   pUnk                 AS DWORD PTR  ' IUnknown  *pUnk
   cbFormat             AS DWORD      ' ULONG     cbFormat
   pbFormat             AS BYTE PTR   ' [size_is(cbFormat)] BYTE *pbFormat
END TYPE

' enum PIN_DIRECTION
%PINDIR_INPUT  = 0
%PINDIR_OUTPUT = %PINDIR_INPUT + 1

%MAX_PIN_NAME    = 128
%MAX_FILTER_NAME = 128

'typedef LONGLONG REFERENCE_TIME;
'typedef double REFTIME;
'typedef DWORD_PTR HSEMAPHORE;
'typedef DWORD_PTR HEVENT;

' // Size = 16 bytes
TYPE ALLOCATOR_PROPERTIES DWORD
   cBuffers AS LONG   ' long cBuffers
   cbBuffer AS LONG   ' long cbBuffer
   cbAlign  AS LONG   ' long cbAlign
   cbPrefix AS LONG   ' long cbPrefix
END TYPE


' ########################################################################################
' Interface name = IPin
' IID = {56A86891-0AD4-11CE-B03A-0020AF0BA770}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IPin_INTERFACE_DEFINED)
    %IPin_INTERFACE_DEFINED = 1

' // Size = 264 bytes
TYPE PIN_INFO DWORD
   pFilter AS DWORD PTR        ' IBaseFilter *pFilter
   dir     AS DWORD            ' PIN_DIRECTION dir
   achName AS WSTRINGZ * 128   ' WCHAR achName[ 128 ]
END TYPE

$IID_IPin = GUID$("{56A86891-0AD4-11CE-B03A-0020AF0BA770}")

INTERFACE IPin $IID_IPin

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Connect ( _                                   ' VTable offset = 12
     BYVAL pReceivePin AS IPin _                        ' __in IPin *pReceivePin
   , OPTIONAL BYREF pmt AS AM_MEDIA_TYPE _              ' __in_opt const AM_MEDIA_TYPE *pmt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ReceiveConnection ( _                         ' VTable offset = 16
     BYVAL pConnector AS IPin _                         ' __in IPin *pConnector
   , BYREF pmt AS AM_MEDIA_TYPE _                       ' __out const AM_MEDIA_TYPE *pmt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Disconnect ( _                                ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ConnectedTo ( _                               ' VTable offset = 24
     BYREF ppPin AS IPin _                              ' __out IPin **ppPin
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ConnectionMediaType ( _                       ' VTable offset = 28
     BYREF pmt AS AM_MEDIA_TYPE _                       ' __out AM_MEDIA_TYPE *pmt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD QueryPinInfo ( _                              ' VTable offset = 32
     BYREF pInfo AS PIN_INFO _                          ' __out PIN_INFO *pInfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD QueryDirection ( _                            ' VTable offset = 36
     BYREF pPinDir AS LONG _                            ' __out PIN_DIRECTION *pPinDir
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD QueryId ( _                                   ' VTable offset = 40
     BYREF Id AS DWORD _                                ' __out LPWSTR *Id
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD QueryAccept ( _                               ' VTable offset = 44
     BYREF pmt AS AM_MEDIA_TYPE _                       ' __in  const AM_MEDIA_TYPE *pmt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumMediaTypes ( _                            ' VTable offset = 48
     BYREF ppEnum AS IEnumMediaTypes _                  ' __out IEnumMediaTypes **ppEnum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD QueryInternalConnections ( _                  ' VTable offset = 52
     BYREF apPin AS IPin _                              ' __out IPin **apPin
   , BYREF nPin AS DWORD _                              ' __inout ULONG *nPin
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EndOfStream ( _                               ' VTable offset = 56
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD BeginFlush ( _                                ' VTable offset = 60
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EndFlush ( _                                  ' VTable offset = 64
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD NewSegment ( _                                ' VTable offset = 68
     BYVAL tStart AS QUAD _                             ' __in  REFERENCE_TIME tStart
   , BYVAL tStop AS QUAD _                              ' __in  REFERENCE_TIME tStop
   , BYVAL dRate AS DOUBLE _                            ' __in  double dRate
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IPin_INTERFACE_DEFINED__*/


' ########################################################################################
' Interface name = IEnumPins
' IID = {56A86892-0AD4-11CE-B03A-0020AF0BA770}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IEnumPins_INTERFACE_DEFINED)
    %IEnumPins_INTERFACE_DEFINED = 1

$IID_IEnumPins = GUID$("{56A86892-0AD4-11CE-B03A-0020AF0BA770}")

INTERFACE IEnumPins $IID_IEnumPins

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Next ( _                                      ' VTable offset = 12
     BYVAL cPins AS DWORD _                             ' __in  ULONG cPins
   , BYREF ppPins AS IPin _                             ' __out IPin **ppPins
   , OPTIONAL BYREF pcFetched AS DWORD _                ' __out_opt ULONG *pcFetched
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Skip ( _                                      ' VTable offset = 16
     BYVAL cPins AS DWORD _                             ' __in  ULONG cPins
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reset ( _                                     ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 24
     BYREF ppEnum AS IEnumPins _                        ' __out IEnumPins **ppEnum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEnumPins_INTERFACE_DEFINED__*/


' ########################################################################################
' Interface name = IEnumMediaTypes
' IID = {89C31040-846B-11CE-97D3-00AA0055595A}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IEnumMediaTypes_INTERFACE_DEFINED)
    %IEnumMediaTypes_INTERFACE_DEFINED = 1

$IID_IEnumMediaTypes = GUID$("{89C31040-846B-11CE-97D3-00AA0055595A}")

INTERFACE IEnumMediaTypes $IID_IEnumMediaTypes

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Next ( _                                      ' VTable offset = 12
     BYVAL cMediaTypes AS DWORD _                       ' __in  ULONG cMediaTypes
   , BYREF ppMediaTypes AS AM_MEDIA_TYPE _              ' __out AM_MEDIA_TYPE **ppMediaTypes
   , OPTIONAL BYREF pcFetched AS DWORD _                ' __out_opt ULONG *pcFetched
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Skip ( _                                      ' VTable offset = 16
     BYVAL cMediaTypes AS DWORD _                       ' __in  ULONG cMediaTypes
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reset ( _                                     ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 24
     BYREF ppEnum AS IEnumMediaTypes _                  ' __out IEnumMediaTypes **ppEnum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEnumMediaTypes_INTERFACE_DEFINED__*/


' ########################################################################################
' Interface name = IFilterGraph
' IID = {56A8689F-0AD4-11CE-B03A-0020AF0BA770}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IFilterGraph_INTERFACE_DEFINED)
    %IFilterGraph_INTERFACE_DEFINED = 1

$IID_IFilterGraph = GUID$("{56A8689F-0AD4-11CE-B03A-0020AF0BA770}")

INTERFACE IFilterGraph $IID_IFilterGraph

   INHERIT IUnknown

   ' =====================================================================================
   METHOD AddFilter ( _                                 ' VTable offset = 12
     BYVAL pFilter AS IBaseFilter _                     ' __in  IBaseFilter *pFilter
   , BYREF pName AS WSTRINGZ _                          ' __in LPCWSTR pName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RemoveFilter ( _                              ' VTable offset = 16
     BYVAL pFilter AS IBaseFilter _                     ' __in  IBaseFilter *pFilter
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumFilters ( _                               ' VTable offset = 20
     BYREF ppEnum AS IEnumFilters _                     ' __out IEnumFilters **ppEnum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD FindFilterByName ( _                          ' VTable offset = 24
     BYREF pName AS WSTRINGZ _                          ' __in  LPCWSTR pName
   , BYREF ppFilter AS IBaseFilter _                    ' __out IBaseFilter **ppFilter
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ConnectDirect ( _                             ' VTable offset = 28
     BYVAL ppinOut AS IPin _                            ' __in  IPin *ppinOut
   , BYVAL ppinIn AS IPin _                             ' __in  IPin *ppinIn
   , OPTIONAL BYREF pmt AS AM_MEDIA_TYPE _              ' __in_opt  const AM_MEDIA_TYPE *pmt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reconnect ( _                                 ' VTable offset = 32
     BYVAL ppin AS IPin _                               ' __in  IPin *ppin
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Disconnect ( _                                ' VTable offset = 36
     BYVAL ppin AS IPin _                               ' __in  IPin *ppin
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetDefaultSyncSource ( _                      ' VTable offset = 40
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IFilterGraph_INTERFACE_DEFINED__*/


' ########################################################################################
' Interface name = IEnumFilters
' IID = {56A86893-0AD4-11CE-B03A-0020AF0BA770}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IEnumFilters_INTERFACE_DEFINED)
    %IEnumFilters_INTERFACE_DEFINED = 1

$IID_IEnumFilters = GUID$("{56A86893-0AD4-11CE-B03A-0020AF0BA770}")

INTERFACE IEnumFilters $IID_IEnumFilters

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Next ( _                                      ' VTable offset = 12
     BYVAL cFilters AS DWORD _                          ' __in  ULONG cFilters
   , BYREF ppFilter AS IBaseFilter _                    ' __out IBaseFilter **ppFilter
   , BYREF pcFetched AS DWORD _                         ' __out ULONG *pcFetched
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Skip ( _                                      ' VTable offset = 16
     BYVAL cFilters AS DWORD _                          ' __in  ULONG cFilters
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reset ( _                                     ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 24
     BYREF ppEnum AS IEnumFilters _                     ' __out IEnumFilters **ppEnum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEnumFilters_INTERFACE_DEFINED__*/


' ########################################################################################
' Interface name = IMediaFilter
' IID = {56A86899-0AD4-11CE-B03A-0020AF0BA770}
' Inherited interface = IPersist
' ########################################################################################

#IF NOT %DEF(%IMediaFilter_INTERFACE_DEFINED)
    %IMediaFilter_INTERFACE_DEFINED = 1

$IID_IMediaFilter = GUID$("{56A86899-0AD4-11CE-B03A-0020AF0BA770}")

' enum FILTER_STATE
%State_Stopped = 1
%State_Paused  = 2
%State_Running = 3

INTERFACE IMediaFilter $IID_IMediaFilter

   INHERIT IUnknown

   ' =====================================================================================
   ' IPersist Methods
   ' =====================================================================================
   METHOD GetClassID ( _                                ' VTable offset = 12
     BYREF pClassID AS GUID _                           ' __out CLSID * pClassID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IMediaFilter Methods
   ' =====================================================================================
   METHOD Stop ( _                                      ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Pause ( _                                     ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Run ( _                                       ' VTable offset = 24
     BYVAL tStart AS QUAD _                             ' __in  REFERENCE_TIME tStart
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetState ( _                                  ' VTable offset = 28
     BYVAL dwMilliSecsTimeout AS DWORD _                ' __in  DWORD dwMilliSecsTimeout
   , BYREF State AS DWORD _                             ' __out FILTER_STATE *State
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetSyncSource ( _                             ' VTable offset = 32
     OPTIONAL BYVAL pClock AS IReferenceClock _         ' __in_opt  IReferenceClock *pClock
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSyncSource ( _                             ' VTable offset = 36
     BYREF pClock AS IReferenceClock  _                 ' __out IReferenceClock **pClock
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMediaFilter_INTERFACE_DEFINED__*/


' ########################################################################################
' Interface name = IBaseFilter
' IID = {56A86895-0AD4-11CE-B03A-0020AF0BA770}
' Inherited interface = IMediaFilter
' ########################################################################################

#IF NOT %DEF(%IBaseFilter_INTERFACE_DEFINED)
    %IBaseFilter_INTERFACE_DEFINED = 1

$IID_IBaseFilter = GUID$("{56A86895-0AD4-11CE-B03A-0020AF0BA770}")

' // Size = 260 bytes
TYPE FILTER_INFO DWORD
   achName AS WSTRINGZ * %MAX_FILTER_NAME   ' WCHAR achName[MAX_FILTER_NAME]
   pGraph  AS DWORD PTR                     ' IFilterGraph *pGraph
END TYPE

INTERFACE IBaseFilter $IID_IBaseFilter

   INHERIT IUnknown

   ' =====================================================================================
   ' IPersist Methods
   ' =====================================================================================
   METHOD GetClassID ( _                                ' VTable offset = 12
     BYREF pClassID AS GUID _                           ' __out CLSID * pClassID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IMediaFilter Methods
   ' =====================================================================================
   METHOD Stop ( _                                      ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Pause ( _                                     ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Run ( _                                       ' VTable offset = 24
     BYVAL tStart AS QUAD _                             ' __in  REFERENCE_TIME tStart
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetState ( _                                  ' VTable offset = 28
     BYVAL dwMilliSecsTimeout AS DWORD _                ' __in  DWORD dwMilliSecsTimeout
   , BYREF State AS DWORD _                             ' __out FILTER_STATE *State
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetSyncSource ( _                             ' VTable offset = 32
     OPTIONAL BYVAL pClock AS IReferenceClock _         ' __in_opt  IReferenceClock *pClock
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSyncSource ( _                             ' VTable offset = 36
     BYREF pClock AS IReferenceClock  _                 ' __out IReferenceClock **pClock
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IBaseFilter Methods
   ' =====================================================================================
   METHOD EnumPins ( _                                  ' VTable offset = 40
     BYREF ppEnum AS IEnumPins _                        ' __out IEnumPins **ppEnum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD FindPin ( _                                   ' VTable offset = 44
     BYREF Id AS WSTRINGZ _                             ' __in  LPCWSTR Id
   , BYREF ppPin AS IPin _                              ' __out IPin **ppPin
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD QueryFilterInfo ( _                           ' VTable offset = 48
     BYREF pInfo AS FILTER_INFO _                       ' __out FILTER_INFO *pInfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD JoinFilterGraph ( _                           ' VTable offset = 52
     OPTIONAL BYVAL pGraph AS IFilterGraph _            ' __in_opt IFilterGraph *pGraph
   , OPTIONAL BYREF pName AS WSTRINGZ _                 ' __in_opt LPCWSTR pName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD QueryVendorInfo ( _                           ' VTable offset = 56
     BYREF pVendorInfo AS DWORD _                       ' __out LPWSTR *pVendorInfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IBaseFilter_INTERFACE_DEFINED__*/


' ########################################################################################
' Interface name = IReferenceClock
' IID = {56A86897-0AD4-11CE-B03A-0020AF0BA770}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IReferenceClock_INTERFACE_DEFINED)
    %IReferenceClock_INTERFACE_DEFINED = 1

$IID_IReferenceClock = GUID$("{56A86897-0AD4-11CE-B03A-0020AF0BA770}")

INTERFACE IReferenceClock $IID_IReferenceClock

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetTime ( _                                   ' VTable offset = 12
     BYREF pTime AS QUAD _                              ' __out REFERENCE_TIME *pTime
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AdviseTime ( _                                ' VTable offset = 16
     BYVAL rtBaseTime AS QUAD _                         ' __in  REFERENCE_TIME rtBaseTime
   , BYVAL rtStreamTime AS QUAD _                       ' __in  REFERENCE_TIME rtStreamTime
   , BYVAL hEvent AS DWORD _                            ' __in  HEVENT hEvent
   , BYREF pdwAdviseCookie AS DWORD _                   ' __out DWORD_PTR *pdwAdviseCookie
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AdvisePeriodic ( _                            ' VTable offset = 20
     BYVAL rtStartTime AS QUAD _                        ' __in  REFERENCE_TIME rtStartTime
   , BYVAL rtPeriodTime AS QUAD _                       ' __in  REFERENCE_TIME rtPeriodTime
   , BYVAL hSemaphore AS DWORD _                        ' __in  HSEMAPHORE hSemaphore
   , BYREF pdwAdviseCookie AS DWORD _                   ' __out DWORD_PTR *pdwAdviseCookie
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Unadvise ( _                                  ' VTable offset = 24
     BYVAL dwAdviseCookie AS DWORD _                    ' __in  DWORD_PTR dwAdviseCookie
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IReferenceClock_INTERFACE_DEFINED__*/


' ########################################################################################
' Interface name = IReferenceClock2
' IID = {36b73885-c2c8-11cf-8b46-00805f6cef60}
' Inherited interface = IReferenceClock
' ########################################################################################

#IF NOT %DEF(%IReferenceClock2_INTERFACE_DEFINED)
    %IReferenceClock2_INTERFACE_DEFINED = 1

$IID_IReferenceClock2 = GUID$("{36b73885-c2c8-11cf-8b46-00805f6cef60}")

INTERFACE IReferenceClock2 $IID_IReferenceClock2

   INHERIT IUnknown

   ' =====================================================================================
   ' IReferenceClock Methods
   ' =====================================================================================
   METHOD GetTime ( _                                   ' VTable offset = 12
     BYREF pTime AS QUAD _                              ' __out REFERENCE_TIME *pTime
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AdviseTime ( _                                ' VTable offset = 16
     BYVAL rtBaseTime AS QUAD _                         ' __in  REFERENCE_TIME rtBaseTime
   , BYVAL rtStreamTime AS QUAD _                       ' __in  REFERENCE_TIME rtStreamTime
   , BYVAL hEvent AS DWORD _                            ' __in  HEVENT hEvent
   , BYREF pdwAdviseCookie AS DWORD _                   ' __out DWORD_PTR *pdwAdviseCookie
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AdvisePeriodic ( _                            ' VTable offset = 20
     BYVAL rtStartTime AS QUAD _                        ' __in  REFERENCE_TIME rtStartTime
   , BYVAL rtPeriodTime AS QUAD _                       ' __in  REFERENCE_TIME rtPeriodTime
   , BYVAL hSemaphore AS DWORD _                        ' __in  HSEMAPHORE hSemaphore
   , BYREF pdwAdviseCookie AS DWORD _                   ' __out DWORD_PTR *pdwAdviseCookie
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Unadvise ( _                                  ' VTable offset = 24
     BYVAL dwAdviseCookie AS DWORD _                    ' __in  DWORD_PTR dwAdviseCookie
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IReferenceClock2_INTERFACE_DEFINED__*/


' ########################################################################################
' Interface name = IMediaSample
' IID = {56a8689a-0ad4-11ce-b03a-0020af0ba770}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMediaSample_INTERFACE_DEFINED)
    %IMediaSample_INTERFACE_DEFINED = 1

$IID_IMediaSample = GUID$("{56a8689a-0ad4-11ce-b03a-0020af0ba770}")

INTERFACE IMediaSample $IID_IMediaSample

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetPointer ( _                                ' VTable offset = 12
     BYREF ppBuffer AS DWORD _                          ' __out BYTE **ppBuffer
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSize ( _                                   ' VTable offset = 16
   ) AS LONG                                            ' long
   ' =====================================================================================
   METHOD GetTime ( _                                   ' VTable offset = 20
     BYREF pTimeStart AS QUAD _                         ' __out REFERENCE_TIME *pTimeStart
   , BYREF pTimeEnd AS QUAD _                           ' __out REFERENCE_TIME *pTimeEnd
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetTime ( _                                   ' VTable offset = 24
     OPTIONAL BYREF pTimeStart AS QUAD _                ' __in_opt  REFERENCE_TIME *pTimeStart
   , OPTIONAL BYREF pTimeEnd AS QUAD _                  ' __in_opt  REFERENCE_TIME *pTimeEnd
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsSyncPoint ( _                               ' VTable offset = 28
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetSyncPoint ( _                              ' VTable offset = 32
     BYVAL bIsSyncPoint AS LONG _                       ' __in  BOOL bIsSyncPoint
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsPreroll ( _                                 ' VTable offset = 36
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPreroll ( _                                ' VTable offset = 40
     BYVAL bIsPreroll AS LONG _                         ' __in  BOOL bIsPreroll
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetActualDataLength ( _                       ' VTable offset = 44
   ) AS LONG                                            ' long
   ' =====================================================================================
   METHOD SetActualDataLength ( _                       ' VTable offset = 48
     BYVAL lLen AS LONG _                               ' __in  long lLen
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMediaType ( _                              ' VTable offset = 52
     BYREF ppMediaType AS AM_MEDIA_TYPE _               ' __out AM_MEDIA_TYPE **ppMediaType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetMediaType ( _                              ' VTable offset = 56
     BYREF ppMediaType AS AM_MEDIA_TYPE _               ' __in  AM_MEDIA_TYPE *ppMediaType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsDiscontinuity ( _                           ' VTable offset = 60
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetDiscontinuity ( _                          ' VTable offset = 64
     BYVAL bDiscontinuity AS LONG _                     ' __out BOOL bDiscontinuity
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMediaTime ( _                              ' VTable offset = 68
     BYREF pTimeStart AS QUAD _                         ' __out LONGLONG *pTimeStart
   , BYREF pTimeEnd AS QUAD _                           ' __out LONGLONG *pTimeEnd
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetMediaTime ( _                              ' VTable offset = 72
     OPTIONAL BYREF pTimeStart AS QUAD _                ' __in_opt LONGLONG *pTimeStart
   , OPTIONAL BYREF pTimeEnd AS QUAD _                  ' __in_opt LONGLONG *pTimeEnd
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMediaSample_INTERFACE_DEFINED__*/


' enum AM_SAMPLE_PROPERTY_FLAGS
%AM_SAMPLE_SPLICEPOINT       = &H1
%AM_SAMPLE_PREROLL           = &H2
%AM_SAMPLE_DATADISCONTINUITY = &H4
%AM_SAMPLE_TYPECHANGED       = &H8
%AM_SAMPLE_TIMEVALID         = &H10
%AM_SAMPLE_TIMEDISCONTINUITY = &H40
%AM_SAMPLE_FLUSH_ON_PAUSE    = &H80
%AM_SAMPLE_STOPVALID         = &H100
%AM_SAMPLE_ENDOFSTREAM       = &H200
%AM_STREAM_MEDIA             = 0
%AM_STREAM_CONTROL           = 1

' // Size = 48 bytes
TYPE AM_SAMPLE2_PROPERTIES   ' Must be 8 byte aligned
   cbData              AS DWORD               ' DWORD cbData
   dwTypeSpecificFlags AS DWORD               ' DWORD dwTypeSpecificFlags
   dwSampleFlags       AS DWORD               ' DWORD dwSampleFlags
   lActual             AS LONG                ' LONG lActual
   tStart              AS QUAD                ' REFERENCE_TIME tStart
   tStop               AS QUAD                ' REFERENCE_TIME tStop
   dwStreamId          AS DWORD               ' DWORD dwStreamId
   pMediaType          AS AM_MEDIA_TYPE PTR   ' AM_MEDIA_TYPE *pMediaType
   pbBuffer            AS BYTE PTR            ' BYTE *pbBuffer
   cbBuffer            AS LONG                ' LONG cbBuffer
END TYPE

' ########################################################################################
' Interface name = IMediaSample2
' IID = {36b73884-c2c8-11cf-8b46-00805f6cef60}
' Inherited interface = IMediaSample
' ########################################################################################

#IF NOT %DEF(%IMediaSample2_INTERFACE_DEFINED)
    %IMediaSample2_INTERFACE_DEFINED = 1

$IID_IMediaSample2 = GUID$("{36b73884-c2c8-11cf-8b46-00805f6cef60}")

INTERFACE IMediaSample2 $IID_IMediaSample2

   INHERIT IUnknown

   ' =====================================================================================
   ' IMediaSample Methods
   ' =====================================================================================
   METHOD GetPointer ( _                                ' VTable offset = 12
     BYREF ppBuffer AS DWORD _                          ' __out BYTE **ppBuffer
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSize ( _                                   ' VTable offset = 16
   ) AS LONG                                            ' long
   ' =====================================================================================
   METHOD GetTime ( _                                   ' VTable offset = 20
     BYREF pTimeStart AS QUAD _                         ' __out REFERENCE_TIME *pTimeStart
   , BYREF pTimeEnd AS QUAD _                           ' __out REFERENCE_TIME *pTimeEnd
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetTime ( _                                   ' VTable offset = 24
     OPTIONAL BYREF pTimeStart AS QUAD _                ' __in_opt  REFERENCE_TIME *pTimeStart
   , OPTIONAL BYREF pTimeEnd AS QUAD _                  ' __in_opt  REFERENCE_TIME *pTimeEnd
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsSyncPoint ( _                               ' VTable offset = 28
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetSyncPoint ( _                              ' VTable offset = 32
     BYVAL bIsSyncPoint AS LONG _                       ' __in  BOOL bIsSyncPoint
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsPreroll ( _                                 ' VTable offset = 36
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPreroll ( _                                ' VTable offset = 40
     BYVAL bIsPreroll AS LONG _                         ' __in  BOOL bIsPreroll
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetActualDataLength ( _                       ' VTable offset = 44
   ) AS LONG                                            ' long
   ' =====================================================================================
   METHOD SetActualDataLength ( _                       ' VTable offset = 48
     BYVAL lLen AS LONG _                               ' __in  long lLen
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMediaType ( _                              ' VTable offset = 52
     BYREF ppMediaType AS AM_MEDIA_TYPE _               ' __out AM_MEDIA_TYPE **ppMediaType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetMediaType ( _                              ' VTable offset = 56
     BYREF ppMediaType AS AM_MEDIA_TYPE _               ' __in  AM_MEDIA_TYPE *ppMediaType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsDiscontinuity ( _                           ' VTable offset = 60
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetDiscontinuity ( _                          ' VTable offset = 64
     BYVAL bDiscontinuity AS LONG _                     ' __out BOOL bDiscontinuity
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMediaTime ( _                              ' VTable offset = 68
     BYREF pTimeStart AS QUAD _                         ' __out LONGLONG *pTimeStart
   , BYREF pTimeEnd AS QUAD _                           ' __out LONGLONG *pTimeEnd
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetMediaTime ( _                              ' VTable offset = 72
     OPTIONAL BYREF pTimeStart AS QUAD _                ' __in_opt  LONGLONG *pTimeStart
   , OPTIONAL BYREF pTimeEnd AS QUAD _                  ' __in_opt  LONGLONG *pTimeEnd
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IMediaSample2 Methods
   ' =====================================================================================
   METHOD GetProperties ( _                             ' VTable offset = 76
     BYVAL cbProperties AS DWORD _                      ' __in  DWORD cbProperties
   , BYVAL pbProperties AS BYTE PTR _                   ' __out BYTE *pbProperties
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetProperties ( _                             ' VTable offset = 80
     BYVAL cbProperties AS DWORD _                      ' __in  DWORD cbProperties
   , BYVAL pbProperties AS BYTE PTR _                   ' __in  const BYTE *pbProperties
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMediaSample2_INTERFACE_DEFINED__*/


' ########################################################################################
' Interface name = IMediaSample2Config
' IID = {68961E68-832B-41EA-BC91-63593F3E70E3}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMediaSample2Config_INTERFACE_DEFINED)
    %IMediaSample2Config_INTERFACE_DEFINED = 1

$IID_IMediaSample2Config = GUID$("{68961E68-832B-41EA-BC91-63593F3E70E3}")

INTERFACE IMediaSample2Config $IID_IMediaSample2Config

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetSurface ( _                                ' VTable offset = 12
     BYREF ppDirect3DSurface9 AS IUnknown _             ' __out IUnknown **ppDirect3DSurface9
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMediaSample2Config_INTERFACE_DEFINED__*/


%AM_GBF_PREVFRAMESKIPPED = 1
%AM_GBF_NOTASYNCPOINT    = 2
%AM_GBF_NOWAIT           = 4
%AM_GBF_NODDSURFACELOCK  = 8


' ########################################################################################
' Interface name = IMemAllocator
' IID = {56a8689c-0ad4-11ce-b03a-0020af0ba770}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMemAllocator_INTERFACE_DEFINED)
    %IMemAllocator_INTERFACE_DEFINED = 1

$IID_IMemAllocator = GUID$("{56a8689c-0ad4-11ce-b03a-0020af0ba770}")

INTERFACE IMemAllocator $IID_IMemAllocator

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetProperties ( _                             ' VTable offset = 12
     BYREF pRequest AS ALLOCATOR_PROPERTIES _           ' __in  ALLOCATOR_PROPERTIES *pRequest
   , BYREF pActual AS ALLOCATOR_PROPERTIES _            ' __out ALLOCATOR_PROPERTIES *pActual
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetProperties ( _                             ' VTable offset = 16
     BYREF pProps AS ALLOCATOR_PROPERTIES _             ' __out ALLOCATOR_PROPERTIES *pProps
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Commit ( _                                    ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Decommit ( _                                  ' VTable offset = 24
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetBuffer ( _                                 ' VTable offset = 28
     BYREF ppBuffer AS IMediaSample _                   ' __out IMediaSample **ppBuffer
   , BYREF pStartTime AS QUAD _                         ' __in  REFERENCE_TIME *pStartTime
   , BYREF pEndTime AS QUAD _                           ' __in_opt  REFERENCE_TIME *pEndTime
   , BYREF dwFlags AS DWORD _                           ' __in_opt  DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ReleaseBuffer ( _                             ' VTable offset = 32
     BYVAL pBuffer AS IMediaSample _                    ' __in  IMediaSample *pBuffer
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMemAllocator_INTERFACE_DEFINED__*/


' ########################################################################################
' Interface name = IMemAllocatorCallbackTemp
' IID = {379a0cf0-c1de-11d2-abf5-00a0c905f375}
' Inherited interface = IMemAllocator
' ########################################################################################

#IF NOT %DEF(%IMemAllocatorCallbackTemp_INTERFACE_DEFINED)
    %IMemAllocatorCallbackTemp_INTERFACE_DEFINED = 1

$IID_IMemAllocatorCallbackTemp = GUID$("{379a0cf0-c1de-11d2-abf5-00a0c905f375}")

INTERFACE IMemAllocatorCallbackTemp $IID_IMemAllocatorCallbackTemp

   INHERIT IUnknown

   ' =====================================================================================
   ' IMemAllocator Methods
   ' =====================================================================================
   METHOD SetProperties ( _                             ' VTable offset = 12
     BYREF pRequest AS ALLOCATOR_PROPERTIES _           ' __in  ALLOCATOR_PROPERTIES *pRequest
   , BYREF pActual AS ALLOCATOR_PROPERTIES _            ' __out ALLOCATOR_PROPERTIES *pActual
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetProperties ( _                             ' VTable offset = 16
     BYREF pProps AS ALLOCATOR_PROPERTIES _             ' __out ALLOCATOR_PROPERTIES *pProps
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Commit ( _                                    ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Decommit ( _                                  ' VTable offset = 24
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetBuffer ( _                                 ' VTable offset = 28
     BYREF ppBuffer AS IMediaSample _                   ' __out IMediaSample **ppBuffer
   , BYREF pStartTime AS QUAD _                         ' __in_opt  REFERENCE_TIME *pStartTime
   , BYREF pEndTime AS QUAD _                           ' __in_opt  REFERENCE_TIME *pEndTime
   , BYREF dwFlags AS DWORD _                           ' __in  DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ReleaseBuffer ( _                             ' VTable offset = 32
     BYREF pBuffer AS IMediaSample _                    ' __in  IMediaSample *pBuffer
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IMemAllocatorCallbackTemp Methods
   ' =====================================================================================
   METHOD SetNotify ( _                                 ' VTable offset = 36
     BYVAL pNotify AS IMemAllocatorNotifyCallbackTemp _ ' __in  IMemAllocatorNotifyCallbackTemp *pNotify
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFreeCount ( _                              ' VTable offset = 40
     BYREF plBuffersFree AS LONG _                      ' __out LONG *plBuffersFree
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMemAllocatorCallbackTemp_INTERFACE_DEFINED__*/


' ########################################################################################
' Interface name = IMemAllocatorNotifyCallbackTemp
' IID = {92980b30-c1de-11d2-abf5-00a0c905f375}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMemAllocatorNotifyCallbackTemp_INTERFACE_DEFINED)
    %IMemAllocatorNotifyCallbackTemp_INTERFACE_DEFINED = 1

$IID_IMemAllocatorNotifyCallbackTemp = GUID$("{92980b30-c1de-11d2-abf5-00a0c905f375}")

INTERFACE IMemAllocatorNotifyCallbackTemp $IID_IMemAllocatorNotifyCallbackTemp

   INHERIT IUnknown

   ' =====================================================================================
   METHOD NotifyRelease ( _                             ' VTable offset = 12
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMemAllocatorNotifyCallbackTemp_INTERFACE_DEFINED__*/


' ########################################################################################
' Interface name = IMemInputPin
' IID = {56A8689D-0AD4-11CE-B03A-0020AF0BA770}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMemInputPin_INTERFACE_DEFINED)
    %IMemInputPin_INTERFACE_DEFINED = 1

$IID_IMemInputPin = GUID$("{56A8689D-0AD4-11CE-B03A-0020AF0BA770}")

INTERFACE IMemInputPin $IID_IMemInputPin

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetAllocator ( _                              ' VTable offset = 12
     BYREF ppAllocator AS IMemAllocator _               ' __out IMemAllocator **ppAllocator
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD NotifyAllocator ( _                           ' VTable offset = 16
     BYVAL pAllocator AS IMemAllocator _                ' __in  IMemAllocator *pAllocator
   , BYVAL bReadOnly AS LONG _                          ' __in  BOOL bReadOnly
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAllocatorRequirements ( _                  ' VTable offset = 20
     BYREF pProps AS ALLOCATOR_PROPERTIES _             ' __out ALLOCATOR_PROPERTIES *pProps
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Receive ( _                                   ' VTable offset = 28
     BYVAL pSample AS IMediaSample _                    ' __in  IMediaSample *pSample
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ReceiveMultiple ( _                           ' VTable offset = 32
     BYVAL pSamples AS IMediaSample _                   ' __in  IMediaSample **pSamples
   , BYVAL nSamples AS LONG _                           ' __in  long nSamples
   , BYREF nSamplesProcessed AS LONG _                  ' __out long *nSamplesProcessed
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ReceiveCanBlock ( _                           ' VTable offset = 36
     ) AS LONG                                          ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMemInputPin_INTERFACE_DEFINED__*/


' ########################################################################################
' Interface name = IAMovieSetup
' IID = {A3D8CEC0-7E5A-11CF-BBC5-00805F6CEF20}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IAMovieSetup_INTERFACE_DEFINED)
    %IAMovieSetup_INTERFACE_DEFINED = 1

$IID_IAMovieSetup = GUID$("{A3D8CEC0-7E5A-11CF-BBC5-00805F6CEF20}")

INTERFACE IAMovieSetup $IID_IAMovieSetup

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Register ( _                                  ' VTable offset = 12
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Unregister ( _                                ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAMovieSetup_INTERFACE_DEFINED__*/


' enum AM_SEEKING_SeekingFlags
%AM_SEEKING_NoPositioning          = 0
%AM_SEEKING_AbsolutePositioning    = &H1
%AM_SEEKING_RelativePositioning    = &H2
%AM_SEEKING_IncrementalPositioning = &H3
%AM_SEEKING_PositioningBitsMask    = &H3
%AM_SEEKING_SeekToKeyFrame         = &H4
%AM_SEEKING_ReturnTime             = &H8
%AM_SEEKING_Segment                = &H10
%AM_SEEKING_NoFlush                = &H20

' enum AM_SEEKING_SeekingCapabilities
%AM_SEEKING_CanSeekAbsolute        = &H1
%AM_SEEKING_CanSeekForwards        = &H2
%AM_SEEKING_CanSeekBackwards       = &H4
%AM_SEEKING_CanGetCurrentPos       = &H8
%AM_SEEKING_CanGetStopPos          = &H10
%AM_SEEKING_CanGetDuration         = &H20
%AM_SEEKING_CanPlayBackwards       = &H40
%AM_SEEKING_CanDoSegments          = &H80
%AM_SEEKING_Source                 = &H100


' ########################################################################################
' Interface name = IMediaSeeking
' IID = {36B73880-C2C8-11CF-8B46-00805F6CEF60}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMediaSeeking_INTERFACE_DEFINED)
    %IMediaSeeking_INTERFACE_DEFINED = 1

$IID_IMediaSeeking = GUID$("{36B73880-C2C8-11CF-8B46-00805F6CEF60}")

INTERFACE IMediaSeeking $IID_IMediaSeeking

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetCapabilities ( _                           ' VTable offset = 12
     BYREF pCapabilities AS DWORD _                     ' __out DWORD *pCapabilities
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CheckCapabilities ( _                         ' VTable offset = 16
     BYREF pCapabilities AS DWORD _                     ' __inout DWORD *pCapabilities
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsFormatSupported ( _                         ' VTable offset = 20
     BYREF pFormat AS GUID _                            ' __in  const GUID *pFormat
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD QueryPreferredFormat ( _                      ' VTable offset = 24
     BYREF pFormat AS GUID _                            ' __out GUID *pFormat
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTimeFormat ( _                             ' VTable offset = 28
     BYREF pFormat AS GUID _                            ' __out GUID *pFormat
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsUsingTimeFormat ( _                         ' VTable offset = 32
     BYREF pFormat AS GUID _                            ' __in  const GUID *pFormat
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetTimeFormat ( _                             ' VTable offset = 36
     BYREF pFormat AS GUID _                            ' __in  const GUID *pFormat
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDuration ( _                               ' VTable offset = 40
     BYREF pDuration AS QUAD _                          ' __out LONGLONG *pDuration
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetStopPosition ( _                           ' VTable offset = 44
     BYREF pStop AS QUAD _                              ' __out LONGLONG *pStop
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCurrentPosition ( _                        ' VTable offset = 48
     BYREF pCurrent AS QUAD _                           ' __out LONGLONG *pCurrent
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ConvertTimeFormat ( _                         ' VTable offset = 52
     BYREF pTarget AS QUAD _                            ' __out LONGLONG *pTarget
   , BYREF pTargetFormat AS GUID _                      ' __in  const GUID *pTargetFormat
   , BYVAL Source AS QUAD _                             ' __in  LONGLONG Source
   , OPTIONAL BYREF pSourceFormat AS GUID _             ' __in_opt  const GUID *pSourceFormat
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPositions ( _                              ' VTable offset = 56
     BYREF pCurrent AS QUAD _                           ' __inout_opt LONGLONG *pCurrent
   , BYVAL dwCurrentFlags AS DWORD _                    ' __in DWORD dwCurrentFlags
   , BYREF pStop AS QUAD _                              ' __inout_opt LONGLONG *pStop
   , BYVAL dwStopFlags AS DWORD _                       ' __in DWORD dwStopFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPositions ( _                              ' VTable offset = 60
     OPTIONAL BYREF pCurrent AS QUAD _                  ' __out_opt LONGLONG *pCurrent
   , OPTIONAL BYREF pStop AS QUAD _                     ' __out_opt LONGLONG *pStop
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAvailable ( _                              ' VTable offset = 64
     OPTIONAL BYREF pEarliest AS QUAD _                 ' __out_opt LONGLONG *pEarliest
   , OPTIONAL BYREF pLatest AS QUAD _                   ' __out_opt LONGLONG *pLatest
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetRate ( _                                   ' VTable offset = 68
     BYVAL dRate AS DOUBLE _                            ' __in  double dRate
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRate ( _                                   ' VTable offset = 72
     BYREF pdRate AS DOUBLE _                           ' __out double *pdRate
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPreroll ( _                                ' VTable offset = 76
     BYREF pllPreroll AS QUAD _                         ' __out LONGLONG *pllPreroll
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMediaSeeking_INTERFACE_DEFINED__*/


' AM_MEDIAEVENT_FLAGS
%AM_MEDIAEVENT_NONOTIFY = &H01

' // Size = 20 bytes
TYPE REGFILTER DWORD
   clsid AS GUID           ' CLSID Clsid
   Name  AS WSTRINGZ PTR   ' LPWSTR Name
END TYPE


' ########################################################################################
' Interface name = IEnumRegFilters
' IID = {56A868A4-0AD4-11CE-B03A-0020AF0BA770}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IEnumRegFilters_INTERFACE_DEFINED)
    %IEnumRegFilters_INTERFACE_DEFINED = 1

$IID_IEnumRegFilters = GUID$("{56A868A4-0AD4-11CE-B03A-0020AF0BA770}")

INTERFACE IEnumRegFilters $IID_IEnumRegFilters

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Next ( _                                      ' VTable offset = 12
     BYVAL cFilters AS DWORD _                          ' __in  ULONG cFilters
   , BYREF apRegFilter AS REGFILTER _                   ' __out REGFILTER **apRegFilter
   , OPTIONAL BYREF pcFetched AS DWORD _                ' __out_opt ULONG *pcFetched
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Skip ( _                                      ' VTable offset = 16
     BYVAL cFilters AS DWORD _                          ' __in  ULONG cFilters
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reset ( _                                     ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 24
     BYREF ppEnum AS IEnumRegFilters _                  ' __out IEnumRegFilters **ppEnum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEnumRegFilters_INTERFACE_DEFINED__*/


' enum Merit
%MERIT_PREFERRED     = &H800000
%MERIT_NORMAL        = &H600000
%MERIT_UNLIKELY      = &H400000
%MERIT_DO_NOT_USE    = &H200000
%MERIT_SW_COMPRESSOR = &H100000
%MERIT_HW_COMPRESSOR = &H100050


' ########################################################################################
' Interface name = IFilterMapper
' IID = {56A868A3-0AD4-11CE-B03A-0020AF0BA770}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IFilterMapper_INTERFACE_DEFINED)
    %IFilterMapper_INTERFACE_DEFINED = 1

$IID_IFilterMapper = GUID$("{56A868A3-0AD4-11CE-B03A-0020AF0BA770}")

INTERFACE IFilterMapper $IID_IFilterMapper

   INHERIT IUnknown

   ' =====================================================================================
   METHOD RegisterFilter ( _                            ' VTable offset = 12
     BYREF clsid AS GUID _                              ' __in  CLSID clsid
   , BYREF Name AS WSTRINGZ _                           ' __in  LPCWSTR Name
   , BYVAL dwMerit AS DWORD _                           ' __in  DWORD dwMerit
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RegisterFilterInstance ( _                    ' VTable offset = 16
     BYREF clsid AS GUID _                              ' __in  CLSID clsid
   , BYREF Name AS WSTRINGZ _                           ' __in  LPCWSTR Name
   , BYREF MRId AS GUID _                               ' __out CLSID *MRId
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RegisterPin ( _                               ' VTable offset = 20
     BYREF Filter AS GUID _                             ' __in  CLSID Filter
   , BYREF Name AS WSTRINGZ _                           ' __in  LPCWSTR Name
   , BYVAL bRendered AS LONG _                          ' __in  BOOL bRendered
   , BYVAL bOutput AS LONG _                            ' __in  BOOL bOutput
   , BYVAL bZero AS LONG _                              ' __in  BOOL bZero
   , BYVAL bMany AS LONG _                              ' __in  BOOL bMany
   , BYREF ConnectsToFilter AS GUID _                   ' __in  CLSID ConnectsToFilter
   , BYREF ConnectsToPin AS WSTRINGZ _                  ' __in  LPCWSTR ConnectsToPin
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RegisterPinType ( _                           ' VTable offset = 24
     BYREF clsFilter AS GUID _                          ' __in  CLSID clsFilter
   , BYREF strName AS WSTRINGZ _                        ' __in  LPCWSTR strName
   , BYREF clsMajorType AS GUID _                       ' __in  CLSID clsMajorType
   , BYREF clsSubType AS GUID _                         ' __in  CLSID clsSubType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UnregisterFilter ( _                          ' VTable offset = 28
     BYREF Filter AS GUID _                             ' __in  CLSID Filter
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UnregisterFilterInstance ( _                  ' VTable offset = 32
     BYREF MRId AS GUID _                               ' __in  CLSID MRId
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UnregisterPin ( _                             ' VTable offset = 36
     BYREF Filter AS GUID _                             ' __in  CLSID Filter
   , BYREF Name AS WSTRINGZ _                           ' __in  LPCWSTR Name
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumMatchingFilters ( _                       ' VTable offset = 40
     BYREF ppEnum AS IEnumRegFilters _                  ' __out IEnumRegFilters **ppEnum
   , BYVAL dwMerit AS DWORD _                           ' __in  DWORD dwMerit
   , BYVAL bInputNeeded AS LONG _                       ' __in  BOOL bInputNeeded
   , BYREF clsInMaj AS GUID _                           ' __in  CLSID clsInMaj
   , BYREF clsInSub AS GUID _                           ' __in  CLSID clsInSub
   , BYVAL bRender AS LONG _                            ' __in  BOOL bRender
   , BYVAL bOututNeeded AS LONG _                       ' __in  BOOL bOututNeeded
   , BYREF clsOutMaj AS GUID _                          ' __in  CLSID clsOutMaj
   , BYREF clsOutSub AS GUID _                          ' __in  CLSID clsOutSub
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IFilterMapper_INTERFACE_DEFINED__*/

' // Size = 8 bytes
TYPE REGPINTYPES DWORD
   clsMajorType             AS GUID PTR            ' const CLSID *clsMajorType
   clsMinorType             AS GUID PTR            ' const CLSID *clsMinorType
END TYPE

' // Size = 36 bytes
TYPE REGFILTERPINS DWORD
   strName                  AS WSTRINGZ PTR        ' LPWSTR strName
   bRendered                AS LONG                ' BOOL bRendered
   bOutput                  AS LONG                ' BOOL bOutput
   bZero                    AS LONG                ' BOOL bZero
   bMany                    AS LONG                ' BOOL bMany
   clsConnectsToFilter      AS GUID PTR            ' const CLSID *clsConnectsToFilter
   strConnectsToPin         AS WSTRINGZ PTR        ' const WCHAR *strConnectsToPin
   nMediaTypes              AS DWORD               ' UINT nMediaTypes
   lpMediaType              AS REGPINTYPES PTR     ' const REGPINTYPES *lpMediaType
END TYPE

' // Size = 24 bytes
TYPE REGPINMEDIUM DWORD
   clsMedium                AS GUID                ' CLSID clsMedium
   dw1                      AS DWORD               ' DWORD dw1
   dw2                      AS DWORD               ' DWORD dw2
END TYPE

' REG_PINFLAG Enumeration
%REG_PINFLAG_B_ZERO     = &H1
%REG_PINFLAG_B_RENDERER = &H2
%REG_PINFLAG_B_MANY     = &H4
%REG_PINFLAG_B_OUTPUT   = &H8

' // Size = 28 bytes
TYPE REGFILTERPINS2 DWORD
   dwFlags                  AS DWORD               ' DWORD dwFlags
   cInstances               AS DWORD               ' UINT cInstances
   nMediaTypes              AS DWORD               ' UINT nMediaTypes
   lpMediaType              AS REGPINTYPES PTR     ' const REGPINTYPES *lpMediaType
   nMediums                 AS DWORD               ' UINT nMediums
   lpMedium                 AS REGPINMEDIUM PTR    ' const REGPINMEDIUM *lpMedium
   clsPinCategory           AS GUID PTR            ' const CLSID *clsPinCategory
END TYPE

' // Size = 8 bytes
TYPE REGFILTER2_1 DWORD
   cPins                   AS DWORD                ' ULONG cPins
   rgPins                  AS REGFILTERPINS PTR    ' const REGFILTERPINS *rgPins
END TYPE

' // Size = 8 bytes
TYPE REGFILTER2_2 DWORD
   cPins2                  AS DWORD                ' ULONG cPins2
   rgPins2                 AS REGFILTERPINS2 PTR   ' const REGFILTERPINS2 *rgPins2
END TYPE

' // Size = 8 bytes
UNION REGFILTER2_UNION
   REGFILTER2_1
   REGFILTER2_2
END UNION

' // Size = 16 bytes
TYPE REGFILTER2 DWORD
   dwVersion              AS DWORD                 ' DWORD dwVersion
   dwMerit                AS DWORD                 ' DWORD dwMerit
   REGFILTER2_UNION
END TYPE


' ########################################################################################
' Interface name = IFilterMapper2
' IID = {56A868A3-0AD4-11CE-B03A-0020AF0BA770}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IFilterMapper2_INTERFACE_DEFINED)
    %IFilterMapper2_INTERFACE_DEFINED = 1

$IID_IFilterMapper2 = GUID$("{56A868A3-0AD4-11CE-B03A-0020AF0BA770}")

INTERFACE IFilterMapper2 $IID_IFilterMapper2

   INHERIT IUnknown

   ' =====================================================================================
   METHOD CreateCategory ( _                            ' VTable offset = 12
     BYREF clsidCategory AS GUID _                      ' __in  REFCLSID clsidCategory
   , BYVAL dwCategoryMerit AS DWORD _                   ' __in  DWORD dwCategoryMerit
   , BYREF Description AS WSTRINGZ _                    ' __in  LPCWSTR Description
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UnregisterFilter ( _                          ' VTable offset = 16
     BYREF pclsidCategory AS GUID _                     ' __in  const CLSID *pclsidCategory
   , BYREF szInstance AS WSTRINGZ _                     ' __in  const OLECHAR *szInstance
   , BYREF Filter AS GUID _                             ' __in  REFCLSID Filter
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RegisterFilter ( _                            ' VTable offset = 20
     BYREF clsidFilter AS GUID _                        ' __in  REFCLSID clsidFilter
   , BYREF Name AS WSTRINGZ _                           ' __in  LPCWSTR Name
   , BYREF ppMoniker AS IMoniker _                      ' __inout IMoniker **ppMoniker
   , BYREF pclsidCategory AS GUID _                     ' __in  const CLSID *pclsidCategory
   , BYREF szInstance AS WSTRINGZ _                     ' __in  const OLECHAR *szInstance
   , BYREF prf2 AS REGFILTER2 _                         ' __in  const REGFILTER2 *prf2
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumMatchingFilters ( _                       ' VTable offset = 24
     BYREF ppEnum AS IEnumMoniker _                     ' __out IEnumMoniker **ppEnum
   , BYVAL dwFlags AS DWORD _                           ' __in  DWORD dwFlags
   , BYVAL bExactMatch AS LONG _                        ' __in  BOOL bExactMatch
   , BYVAL dwMerit AS DWORD _                           ' __in  DWORD dwMerit
   , BYVAL bInputNeeded AS LONG _                       ' __in  BOOL bInputNeeded
   , BYVAL cInputTypes AS DWORD _                       ' __in  DWORD cInputTypes
   , OPTIONAL BYREF pInputTypes AS GUID _               ' __in_opt const GUID *pInputTypes
   , OPTIONAL BYREF pMedIn AS REGPINMEDIUM _            ' __in_opt const REGPINMEDIUM *pMedIn
   , OPTIONAL BYREF pPinCategoryIn AS GUID _            ' __in_opt const CLSID *pPinCategoryIn
   , OPTIONAL BYVAL bRender AS LONG _                   ' __in  BOOL bRender
   , OPTIONAL BYVAL bOutputNeeded AS LONG _             ' __in  BOOL bOutputNeeded
   , OPTIONAL BYVAL cOutputTypes AS DWORD _             ' __in  DWORD cOutputTypes
   , OPTIONAL BYREF pOutputTypes AS GUID _              ' __in_opt  const GUID *pOutputTypes
   , OPTIONAL BYREF pMedOut AS REGPINMEDIUM _           ' __in_opt  const REGPINMEDIUM *pMedOut
   , OPTIONAL BYREF pPinCategoryOut AS GUID _           ' __in_opt  const CLSID *pPinCategoryOut
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IFilterMapper2_INTERFACE_DEFINED__*/


' ########################################################################################
' Interface name = IFilterMapper3
' IID = {B79BB0B1-33C1-11D1-ABE1-00A0C905F375}
' Inherited interface = IFilterMapper2
' ########################################################################################

#IF NOT %DEF(%IFilterMapper3_INTERFACE_DEFINED)
    %IFilterMapper3_INTERFACE_DEFINED = 1

$IID_IFilterMapper3 = GUID$("{B79BB0B1-33C1-11D1-ABE1-00A0C905F375}")

INTERFACE IFilterMapper3 $IID_IFilterMapper3

   INHERIT IUnknown

   ' =====================================================================================
   ' IFilterMapper2 Methods
   ' =====================================================================================
   METHOD CreateCategory ( _                            ' VTable offset = 12
     BYREF clsidCategory AS GUID _                      ' __in  REFCLSID clsidCategory
   , BYVAL dwCategoryMerit AS DWORD _                   ' __in  DWORD dwCategoryMerit
   , BYREF Description AS WSTRINGZ _                    ' __in  LPCWSTR Description
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UnregisterFilter ( _                          ' VTable offset = 16
     BYREF pclsidCategory AS GUID _                     ' __in  const CLSID *pclsidCategory
   , BYREF szInstance AS WSTRINGZ _                     ' __in  const OLECHAR *szInstance
   , BYREF Filter AS GUID _                             ' __in  REFCLSID Filter
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RegisterFilter ( _                            ' VTable offset = 20
     BYREF clsidFilter AS GUID _                        ' __in  REFCLSID clsidFilter
   , BYREF Name AS WSTRINGZ _                           ' __in  LPCWSTR Name
   , BYREF ppMoniker AS IMoniker _                      ' __inout_opt IMoniker **ppMoniker
   , BYREF pclsidCategory AS GUID _                     ' __in  const CLSID *pclsidCategory
   , BYREF szInstance AS WSTRINGZ _                     ' __in  const OLECHAR *szInstance
   , BYREF prf2 AS REGFILTER2 _                         ' __in  const REGFILTER2 *prf2
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumMatchingFilters ( _                       ' VTable offset = 24
     BYREF ppEnum AS IEnumMoniker _                     ' __out IEnumMoniker **ppEnum
   , BYVAL dwFlags AS DWORD _                           ' __in  DWORD dwFlags
   , BYVAL bExactMatch AS LONG _                        ' __in  BOOL bExactMatch
   , BYVAL dwMerit AS DWORD _                           ' __in  DWORD dwMerit
   , BYVAL bInputNeeded AS LONG _                       ' __in  BOOL bInputNeeded
   , BYVAL cInputTypes AS DWORD _                       ' __in  DWORD cInputTypes
   , OPTIONAL BYREF pInputTypes AS GUID _               ' __in_opt  const GUID *pInputTypes
   , OPTIONAL BYREF pMedIn AS REGPINMEDIUM _            ' __in_opt  const REGPINMEDIUM *pMedIn
   , OPTIONAL BYREF pPinCategoryIn AS GUID _            ' __in_opt  const CLSID *pPinCategoryIn
   , OPTIONAL BYVAL bRender AS LONG _                   ' __in  BOOL bRender
   , OPTIONAL BYVAL bOutputNeeded AS LONG _             ' __in  BOOL bOutputNeeded
   , OPTIONAL BYVAL cOutputTypes AS DWORD _             ' __in  DWORD cOutputTypes
   , OPTIONAL BYREF pOutputTypes AS GUID _              ' __in_opt  const GUID *pOutputTypes
   , OPTIONAL BYREF pMedOut AS REGPINMEDIUM _           ' __in_opt  const REGPINMEDIUM *pMedOut
   , OPTIONAL BYREF pPinCategoryOut AS GUID _           ' __in_opt  const CLSID *pPinCategoryOut
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IFilterMapper3 Methods
   ' =====================================================================================
   METHOD GetICreateDevEnum ( _                         ' VTable offset = 28
     BYREF ppEnum AS ICreateDevEnum _                   ' __out ICreateDevEnum **ppEnum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IFilterMapper3_INTERFACE_DEFINED__*/


' enum QualityMessageType
%QualityMessageType_Famine = 0
%QualityMessageType_Flood  = %QualityMessageType_Famine + 1

' // Size = 24 bytes
TYPE Quality   ' Must be 8 byte aligned
   Type       AS DWORD   ' QualityMessageType Type
   Proportion AS LONG    ' long Proportion
   Late       AS QUAD    ' REFERENCE_TIME Late
   TimeStamp  AS QUAD    ' REFERENCE_TIME TimeStamp
END TYPE


' ########################################################################################
' Interface name = IQualityControl
' IID = {56A868A5-0AD4-11CE-B03A-0020AF0BA770}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IQualityControl_INTERFACE_DEFINED)
    %IQualityControl_INTERFACE_DEFINED = 1

$IID_IQualityControl = GUID$("{56A868A5-0AD4-11CE-B03A-0020AF0BA770}")

INTERFACE IQualityControl $IID_IQualityControl

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Notify ( _                                    ' VTable offset = 12
     BYVAL pSelf AS IBaseFilter _                       ' __in  IBaseFilter *pSelf
   , BYVAL q AS Quality _                               ' __in  Quality q
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetSink ( _                                   ' VTable offset = 16
     BYVAL piqc AS IQualityControl _                    ' __in  IQualityControl *piqc
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IQualityControl_INTERFACE_DEFINED__*/


%CK_NOCOLORKEY         = 0
%CK_INDEX              = &H1
%CK_RGB                = &H2

' // Size = 16 bytes
TYPE COLORKEY DWORD
   KeyType        AS DWORD   ' DWORD KeyType
   PaletteIndex   AS DWORD   ' DWORD PaletteIndex
   LowColorValue  AS DWORD   ' COLORREF LowColorValue
   HighColorValue AS DWORD   ' COLORREF HighColorValue
END TYPE

%ADVISE_NONE           = 0
%ADVISE_CLIPPING       = &H1
%ADVISE_PALETTE        = &H2
%ADVISE_COLORKEY       = &H4
%ADVISE_POSITION       = &H8
%ADVISE_DISPLAY_CHANGE = &H10

%ADVISE_ALL  = %ADVISE_CLIPPING OR %ADVISE_PALETTE OR %ADVISE_COLORKEY OR %ADVISE_POSITION
%ADVISE_ALL2 = %ADVISE_ALL OR %ADVISE_DISPLAY_CHANGE

#IF NOT %DEF(%RGNDATAHEADER_DEFINED)
%RGNDATAHEADER_DEFINED = 1
' // Size = 32 bytes
TYPE RGNDATAHEADER DWORD
   dwSize   AS DWORD
   iType    AS DWORD
   nCount   AS DWORD
   nRgnSize AS DWORD
   rcBound  AS RECT
END TYPE
#ENDIF

#IF NOT %DEF(%RGNDATA_DEFINED)
%RGNDATA_DEFINED = 1
' // Size = 36 bytes
TYPE RGNDATA DWORD
   rdh       AS RGNDATAHEADER   ' RGNDATAHEADER rdh
   Buffer(0) AS BYTE            ' char Buffer[ 1 ] - arbitrary-size buffer
END TYPE
#ENDIF


' ########################################################################################
' Interface name = IOverlayNotify
' IID = {56A868A0-0AD4-11CE-B03A-0020AF0BA770}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IOverlayNotify_INTERFACE_DEFINED)
    %IOverlayNotify_INTERFACE_DEFINED = 1

$IID_IOverlayNotify = GUID$("{56A868A0-0AD4-11CE-B03A-0020AF0BA770}")

INTERFACE IOverlayNotify $IID_IOverlayNotify

   INHERIT IUnknown

   ' =====================================================================================
   METHOD OnPaletteChange ( _                           ' VTable offset = 12
     BYVAL dwColors AS DWORD _                          ' __in  DWORD dwColors
   , BYREF pPalette AS PALETTEENTRY _                   ' __in  const PALETTEENTRY *pPalette
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnClipChange ( _                              ' VTable offset = 16
     BYREF pSourceRect AS RECT _                        ' __in  const RECT *pSourceRect
   , BYREF pDestinationRect AS RECT _                   ' __in  const RECT *pDestinationRect
   , BYREF pRgnData AS RGNDATA _                        ' __in  const RGNDATA *pRgnData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnColorKeyChange ( _                          ' VTable offset = 20
     BYREF pColorKey AS COLORKEY _                      ' __in  const COLORKEY *pColorKey
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnPositionChange ( _                          ' VTable offset = 24
     BYREF pSourceRect AS RECT _                        ' __in  const RECT *pSourceRect
   , BYREF pDestinationRect AS RECT _                   ' __in  const RECT *pDestinationRect
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IOverlayNotify_INTERFACE_DEFINED__*/


' ########################################################################################
' Interface name = IOverlayNotify2
' IID = {680EFA10-D535-11D1-87C8-00A0C9223196}
' Inherited interface = IOverlayNotify
' ########################################################################################

#IF NOT %DEF(%IOverlayNotify2_INTERFACE_DEFINED)
    %IOverlayNotify2_INTERFACE_DEFINED = 1

$IID_IOverlayNotify2 = GUID$("{680EFA10-D535-11D1-87C8-00A0C9223196}")

INTERFACE IOverlayNotify2 $IID_IOverlayNotify2

   INHERIT IUnknown

   ' =====================================================================================
   ' IOverlayNotify Methods
   ' =====================================================================================
   METHOD OnPaletteChange ( _                           ' VTable offset = 12
     BYVAL dwColors AS DWORD _                          ' __in  DWORD dwColors
   , BYREF pPalette AS PALETTEENTRY _                   ' __in  const PALETTEENTRY *pPalette
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnClipChange ( _                              ' VTable offset = 16
     BYREF pSourceRect AS RECT _                        ' __in  const RECT *pSourceRect
   , BYREF pDestinationRect AS RECT _                   ' __in  const RECT *pDestinationRect
   , BYREF pRgnData AS RGNDATA _                        ' __in  const RGNDATA *pRgnData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnColorKeyChange ( _                          ' VTable offset = 20
     BYREF pColorKey AS COLORKEY _                      ' __in  const COLORKEY *pColorKey
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnPositionChange ( _                          ' VTable offset = 24
     BYREF pSourceRect AS RECT _                        ' __in  const RECT *pSourceRect
   , BYREF pDestinationRect AS RECT _                   ' __in  const RECT *pDestinationRect
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IOverlayNotify2 Methods
   ' =====================================================================================
   METHOD OnDisplayChange ( _                           ' VTable offset = 28
     BYVAL DWORD _                                      ' __in  HMONITOR hMonitor
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IOverlayNotify2_INTERFACE_DEFINED__*/


' ########################################################################################
' Interface name = IOverlay
' IID = {56A868A1-0AD4-11CE-B03A-0020AF0BA770}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IOverlay_INTERFACE_DEFINED)
    %IOverlay_INTERFACE_DEFINED = 1

$IID_IOverlay = GUID$("{56A868A1-0AD4-11CE-B03A-0020AF0BA770}")

INTERFACE IOverlay $IID_IOverlay

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetPalette ( _                                ' VTable offset = 12
     BYREF pdwColors AS DWORD _                         ' __out DWORD *pdwColors
   , BYREF ppPalette AS PALETTEENTRY _                  ' __out PALETTEENTRY **ppPalette
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPalette ( _                                ' VTable offset = 16
     BYVAL dwColors AS DWORD _                          ' __in  DWORD dwColors
   , BYREF ppPalette AS PALETTEENTRY _                  ' __in  PALETTEENTRY *ppPalette
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDefaultColorKey ( _                        ' VTable offset = 20
     BYREF pColorKey AS COLORKEY _                      ' __out COLORKEY *pColorKey
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetColorKey ( _                               ' VTable offset = 24
     BYREF pColorKey AS COLORKEY _                      ' __out COLORKEY *pColorKey
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetColorKey ( _                               ' VTable offset = 28
     BYREF pColorKey AS COLORKEY _                      ' __inout COLORKEY *pColorKey
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetWindowHandle ( _                           ' VTable offset = 32
     BYREF pHwnd AS DWORD _                             ' __out HWND *pHwnd
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetClipList ( _                               ' VTable offset = 36
     BYREF pSourceRect AS RECT _                        ' __out RECT *pSourceRect
   , BYREF pDestinationRect AS RECT _                   ' __out RECT *pDestinationRect
   , BYREF ppRgnData AS DWORD _                         ' __out RGNDATA **ppRgnData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetVideoPosition ( _                          ' VTable offset = 40
     BYREF pSourceRect AS RECT _                        ' __out RECT *pSourceRect
   , BYREF pDestinationRect AS RECT _                   ' __out RECT *pDestinationRect
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Advise ( _                                    ' VTable offset = 44
     BYVAL pOverlayNotify AS IOverlayNotify _           ' __in  IOverlayNotify *pOverlayNotify
   , BYVAL dwInterests AS DWORD _                       ' __in  DWORD dwInterests
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Unadvise ( _                                  ' VTable offset = 48
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IOverlay_INTERFACE_DEFINED__*/


' ########################################################################################
' Interface name = IMediaEventSink
' IID = {56A868A2-0AD4-11CE-B03A-0020AF0BA770}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMediaEventSink_INTERFACE_DEFINED)
    %IMediaEventSink_INTERFACE_DEFINED = 1

$IID_IMediaEventSink = GUID$("{56A868A2-0AD4-11CE-B03A-0020AF0BA770}")

INTERFACE IMediaEventSink $IID_IMediaEventSink

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Notify ( _                                    ' VTable offset = 12
     BYVAL EventCode AS LONG _                          ' __in  long EventCode
   , BYVAL EventParam1 AS DWORD _                       ' __in  LONG_PTR EventParam1
   , BYVAL EventParam2 AS DWORD _                       ' __in  LONG_PTR EventParam2
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMediaEventSink_INTERFACE_DEFINED__*/


' ########################################################################################
' Interface name = IFileSourceFilter
' IID = {56A868A6-0AD4-11CE-B03A-0020AF0BA770}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IFileSourceFilter_INTERFACE_DEFINED)
    %IFileSourceFilter_INTERFACE_DEFINED = 1

$IID_IFileSourceFilter = GUID$("{56A868A6-0AD4-11CE-B03A-0020AF0BA770}")

INTERFACE IFileSourceFilter $IID_IFileSourceFilter

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Load ( _                                      ' VTable offset = 12
     BYREF pszFileName AS WSTRINGZ _                    ' __in  LPCOLESTR pszFileName
   , OPTIONAL BYREF pmt AS AM_MEDIA_TYPE _              ' __in_opt  const AM_MEDIA_TYPE *pmt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCurFile ( _                                ' VTable offset = 16
     BYREF ppszFileName AS DWORD _                      ' __out LPOLESTR *ppszFileName
   , OPTIONAL BYREF pmt AS AM_MEDIA_TYPE _              ' __out_opt AM_MEDIA_TYPE *pmt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IFileSourceFilter_INTERFACE_DEFINED__*/


' ########################################################################################
' Interface name = IFileSinkFilter
' IID = {A2104830-7C70-11CF-8BCE-00AA00A3F1A6}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IFileSinkFilter_INTERFACE_DEFINED)
    %IFileSinkFilter_INTERFACE_DEFINED = 1

$IID_IFileSinkFilter = GUID$("{A2104830-7C70-11CF-8BCE-00AA00A3F1A6}")

INTERFACE IFileSinkFilter $IID_IFileSinkFilter

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetFileName ( _                               ' VTable offset = 12
     BYREF pszFileName AS WSTRINGZ _                    ' __in  LPCOLESTR pszFileName
   , OPTIONAL BYREF pmt AS AM_MEDIA_TYPE _              ' __in_opt  const AM_MEDIA_TYPE *pmt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCurFile ( _                                ' VTable offset = 16
     BYREF ppszFileName AS DWORD _                      ' __out LPOLESTR *ppszFileName
   , BYREF pmt AS AM_MEDIA_TYPE _                       ' __out AM_MEDIA_TYPE *pmt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IFileSinkFilter_INTERFACE_DEFINED__*/


' ########################################################################################
' Interface name = IFileSinkFilter2
' IID = {00855B90-CE1B-11D0-BD4F-00A0C911CE86}
' Inherited interface = IFileSinkFilter
' ########################################################################################

#IF NOT %DEF(%IFileSinkFilter2_INTERFACE_DEFINED)
    %IFileSinkFilter2_INTERFACE_DEFINED = 1

$IID_IFileSinkFilter2 = GUID$("{00855B90-CE1B-11D0-BD4F-00A0C911CE86}")

INTERFACE IFileSinkFilter2 $IID_IFileSinkFilter2

   INHERIT IUnknown

   ' =====================================================================================
   ' IFileSinkFilter methods
   ' =====================================================================================
   METHOD SetFileName ( _                               ' VTable offset = 12
     BYREF pszFileName AS WSTRINGZ _                    ' __in  LPCOLESTR pszFileName
   , OPTIONAL BYREF pmt AS AM_MEDIA_TYPE _              ' __in_opt  const AM_MEDIA_TYPE *pmt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCurFile ( _                                ' VTable offset = 16
     BYREF ppszFileName AS DWORD _                      ' __out LPOLESTR *ppszFileName
   , BYREF pmt AS AM_MEDIA_TYPE _                       ' __out AM_MEDIA_TYPE *pmt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IFileSinkFilter2 methods
   ' =====================================================================================
   METHOD SetMode ( _                                   ' VTable offset = 20
     BYVAL dwFlags AS DWORD _                           ' __in  DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMode ( _                                   ' VTable offset = 24
     BYREF pdwFlags AS DWORD _                          ' __out DWORD *pdwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IFileSinkFilter2_INTERFACE_DEFINED__*/


' AM_FILESINK_FLAGS enum
%AM_FILE_OVERWRITE = &H1


' ########################################################################################
' Interface name = IGraphBuilder
' IID = {56A868A9-0AD4-11CE-B03A-0020AF0BA770}
' Inherited interface = IFilterGraph
' ########################################################################################

#IF NOT %DEF(%IGraphBuilder_INTERFACE_DEFINED)
    %IGraphBuilder_INTERFACE_DEFINED = 1

$IID_IGraphBuilder = GUID$("{56A868A9-0AD4-11CE-B03A-0020AF0BA770}")

INTERFACE IGraphBuilder $IID_IGraphBuilder

   INHERIT IUnknown

   ' =====================================================================================
   METHOD AddFilter ( _                                 ' VTable offset = 12
     BYVAL pFilter AS IBaseFilter _                     ' __in  IBaseFilter *pFilter
   , BYREF pName AS WSTRINGZ _                          ' __in  LPCWSTR pName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RemoveFilter ( _                              ' VTable offset = 16
     BYVAL pFilter AS IBaseFilter _                     ' __in  IBaseFilter *pFilter
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumFilters ( _                               ' VTable offset = 20
     BYREF ppEnum AS IEnumFilters _                     ' __out IEnumFilters **ppEnum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD FindFilterByName ( _                          ' VTable offset = 24
     BYREF pName AS WSTRINGZ _                          ' __in LPCWSTR pName
   , BYREF ppFilter AS IBaseFilter _                    ' __out IBaseFilter **ppFilter
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ConnectDirect ( _                             ' VTable offset = 28
     BYVAL ppinOut AS IPin _                            ' __in  IPin *ppinOut
   , BYVAL ppinIn AS IPin _                             ' __in  IPin *ppinIn
   , OPTIONAL BYREF pmt AS AM_MEDIA_TYPE _              ' __in_opt  const AM_MEDIA_TYPE *pmt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reconnect ( _                                 ' VTable offset = 32
     BYVAL ppin AS IPin _                               ' __in  IPin *ppin
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Disconnect ( _                                ' VTable offset = 36
     BYVAL ppin AS IPin _                               ' __in  IPin *ppin
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetDefaultSyncSource ( _                      ' VTable offset = 40
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Connect ( _                                   ' VTable offset = 44
     BYVAL ppinOut AS IPin _                            ' __in  IPin *ppinOut
   , BYVAL ppinIn AS IPin _                             ' __in  IPin *ppinIn
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Render ( _                                    ' VTable offset = 48
     BYVAL ppinOut AS IPin _                            ' __in  IPin *ppinOut
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RenderFile ( _                                ' VTable offset = 52
     BYREF lpcwstrFile AS WSTRINGZ _                    ' __in  LPCWSTR lpcwstrFile
   , OPTIONAL BYREF lpcwstrPlayList AS WSTRINGZ _       ' __in_opt  LPCWSTR lpcwstrPlayList
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddSourceFilter ( _                           ' VTable offset = 56
     BYREF lpcwstrFileName AS WSTRINGZ _                ' __in  LPCWSTR lpcwstrFileName
   , BYREF lpcwstrFilterName AS WSTRINGZ _              ' __in_opt  LPCWSTR lpcwstrFilterName
   , BYREF ppFilter AS IBaseFilter _                    ' __out IBaseFilter **ppFilter
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetLogFile ( _                                ' VTable offset = 60
     BYVAL hFile AS DWORD _                             ' __in  DWORD_PTR hFile
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Abort ( _                                     ' VTable offset = 64
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ShouldOperationContinue ( _                   ' VTable offset = 68
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IGraphBuilder_INTERFACE_DEFINED__*/


' ########################################################################################
' Interface name = ICaptureGraphBuilder
' IID = {BF87B6E0-8C27-11D0-B3F0-00AA003761C5}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ICaptureGraphBuilder_INTERFACE_DEFINED)
    %ICaptureGraphBuilder_INTERFACE_DEFINED = 1

$IID_ICaptureGraphBuilder = GUID$("{BF87B6E0-8C27-11D0-B3F0-00AA003761C5}")

INTERFACE ICaptureGraphBuilder $IID_ICaptureGraphBuilder

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetFiltergraph ( _                            ' VTable offset = 12
     BYVAL pfg AS IGraphBuilder _                       ' __in  IGraphBuilder *pfg
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFiltergraph ( _                            ' VTable offset = 16
     BYREF ppfg AS IGraphBuilder _                      ' __out IGraphBuilder **ppfg
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetOutputFileName ( _                         ' VTable offset = 20
     BYREF pType AS GUID _                              ' __in  const GUID *pType
   , BYREF lpstrFile AS WSTRINGZ _                      ' __in  LPCOLESTR lpstrFile
   , BYREF ppf AS IBaseFilter _                         ' __out IBaseFilter **ppf
   , BYREF ppSink AS IFileSinkFilter _                  ' __out IFileSinkFilter **ppSink
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD FindInterface ( _                             ' VTable offset = 24
     BYREF pCategory AS DWORD _                         ' __in_opt  const GUID *pCategory
   , BYVAL pf AS IBaseFilter _                          ' __in  IBaseFilter *pf
   , BYREF riid AS GUID _                               ' __in  REFIID riid
   , BYREF ppint AS IUnknown _                          ' __out void **ppint
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RenderStream ( _                              ' VTable offset = 28
     BYREF pCategory AS GUID _                          ' __in_opt  const GUID *pCategory
   , BYVAL pSource AS IUnknown _                        ' __in  IUnknown *pSource
   , BYVAL pfCompressor AS IBaseFilter _                ' __in  IBaseFilter *pfCompressor
   , BYVAL pfRenderer AS IBaseFilter _                  ' __in  IBaseFilter *pfRenderer
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ControlStream ( _                             ' VTable offset = 32
     BYREF pCategory AS GUID _                          ' __in_opt  const GUID *pCategory
   , BYVAL pFilter AS IBaseFilter _                     ' __in  IBaseFilter *pFilter
   , BYREF pstart AS QUAD _                             ' __in  REFERENCE_TIME *pstart
   , BYREF pstop AS QUAD _                              ' __in  REFERENCE_TIME *pstop
   , BYVAL wStartCookie AS WORD _                       ' __in  WORD wStartCookie
   , BYVAL wStopCookie AS WORD _                        ' __in  WORD wStopCookie
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AllocCapFile ( _                              ' VTable offset = 36
     BYREF lpstr AS WSTRINGZ _                          ' __in  LPCOLESTR lpstr
   , BYVAL dwlSize AS QUAD _                            ' __in  DWORDLONG dwlSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CopyCaptureFile ( _                           ' VTable offset = 40
     BYREF lpwstrOld AS WSTRINGZ _                      ' __in  LPOLESTR lpwstrOld
   , BYREF lpwstrNew AS WSTRINGZ _                      ' __in  LPOLESTR lpwstrNew
   , BYVAL fAllowEscAbort AS LONG _                     ' __in  int fAllowEscAbort
   , BYVAL pCallback AS IAMCopyCaptureFileProgress _    ' __in  IAMCopyCaptureFileProgress *pCallback
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICaptureGraphBuilder_INTERFACE_DEFINED__*/


' ########################################################################################
' Interface name = IAMCopyCaptureFileProgress
' IID = {670D1D20-A068-11D0-B3F0-00AA003761C5}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IAMCopyCaptureFileProgress_INTERFACE_DEFINED)
    %IAMCopyCaptureFileProgress_INTERFACE_DEFINED = 1

$IID_IAMCopyCaptureFileProgress = GUID$("{670D1D20-A068-11D0-B3F0-00AA003761C5}")

INTERFACE IAMCopyCaptureFileProgress $IID_IAMCopyCaptureFileProgress

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Progress ( _                                  ' VTable offset = 12
     BYVAL iProgress AS LONG _                          ' __in  int iProgress
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAMCopyCaptureFileProgress_INTERFACE_DEFINED__*/


' ########################################################################################
' Interface name = ICaptureGraphBuilder2
' IID = {93E5A4E0-2D50-11D2-ABFA-00A0C9C6E38D}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ICaptureGraphBuilder2_INTERFACE_DEFINED)
    %ICaptureGraphBuilder2_INTERFACE_DEFINED = 1

$IID_ICaptureGraphBuilder2 = GUID$("{93E5A4E0-2D50-11D2-ABFA-00A0C9C6E38D}")

INTERFACE ICaptureGraphBuilder2 $IID_ICaptureGraphBuilder2

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetFiltergraph ( _                            ' VTable offset = 12
     BYVAL pfg AS IGraphBuilder _                       ' __in  IGraphBuilder *pfg
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFiltergraph ( _                            ' VTable offset = 16
     BYREF ppfg AS IGraphBuilder _                      ' __out IGraphBuilder **ppfg
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetOutputFileName ( _                         ' VTable offset = 20
     BYREF pType AS GUID _                              ' __in  const GUID *pType
   , BYREF lpstrFile AS WSTRINGZ _                      ' __in  LPCOLESTR lpstrFile
   , BYREF ppf AS IBaseFilter _                         ' __out IBaseFilter **ppf
   , BYREF ppSink AS IFileSinkFilter _                  ' __out IFileSinkFilter **ppSink
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD FindInterface ( _                             ' VTable offset = 24
     BYREF pCategory AS GUID _                          ' __in_opt  const GUID *pCategory
   , BYREF pType AS GUID _                              ' __in_opt  const GUID *pType
   , BYVAL pf AS IBaseFilter _                          ' __in  IBaseFilter *pf
   , BYREF riid AS GUID _                               ' __in  REFIID riid
   , BYREF ppint AS IUnknown _                          ' __out void **ppint
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RenderStream ( _                              ' VTable offset = 28
     BYREF pCategory AS GUID _                          ' __in_opt  const GUID *pCategory
   , BYREF pType AS GUID _                              ' __in  const GUID *pType
   , BYVAL pSource AS IUnknown _                        ' __in  IUnknown *pSource
   , BYVAL pfCompressor AS IBaseFilter _                ' __in  IBaseFilter *pfCompressor
   , BYVAL pfRenderer AS IBaseFilter _                  ' __in  IBaseFilter *pfRenderer
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ControlStream ( _                             ' VTable offset = 32
     BYREF pCategory AS GUID _                          ' __in  const GUID *pCategory
   , BYREF pType AS GUID _                              ' __in  const GUID *pType
   , BYVAL pFilter AS IBaseFilter _                     ' __in  IBaseFilter *pFilter
   , BYREF pstart AS QUAD _                             ' __in_opt  REFERENCE_TIME *pstart
   , BYREF pstop AS QUAD _                              ' __in_opt  REFERENCE_TIME *pstop
   , BYVAL wStartCookie AS WORD _                       ' __in  WORD wStartCookie
   , BYVAL wStopCookie AS WORD _                        ' __in  WORD wStopCookie
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AllocCapFile ( _                              ' VTable offset = 36
     BYREF lpstr AS WSTRINGZ _                          ' __in  LPCOLESTR lpstr
   , BYVAL dwlSize AS QUAD _                            ' __in  DWORDLONG dwlSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CopyCaptureFile ( _                           ' VTable offset = 40
     BYREF lpwstrOld AS WSTRINGZ _                      ' __in  LPOLESTR lpwstrOld
   , BYREF lpwstrNew AS WSTRINGZ _                      ' __in  LPOLESTR lpwstrNew
   , BYVAL fAllowEscAbort AS LONG _                     ' __in  int fAllowEscAbort
   , BYVAL pCallback AS IAMCopyCaptureFileProgress _    ' __in  IAMCopyCaptureFileProgress *pCallback
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD FindPin ( _                                   ' VTable offset = 44
     BYVAL pSource AS IUnknown _                        ' __in  IUnknown *pSource
   , BYVAL pindir AS DWORD _                            ' __in  PIN_DIRECTION pindir
   , BYREF pCategory AS GUID _                          ' __in_opt  const GUID *pCategory
   , BYREF pType AS GUID _                              ' __in_opt  const GUID *pType
   , BYVAL fUnconnected AS LONG _                       ' __in  BOOL fUnconnected
   , BYVAL num AS LONG _                                ' __in  int num
   , BYREF ppPin AS IPin _                              ' __out IPin **ppPin
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICaptureGraphBuilder2_INTERFACE_DEFINED__*/


' AM_RENSDEREXFLAGS enum
%AM_RENDEREX_RENDERTOEXISTINGRENDERERS = &H1


' ########################################################################################
' Interface name = IFilterGraph2
' IID = {36b73882-c2c8-11cf-8b46-00805f6cef60}
' Inherited interface = IGraphBuilder
' ########################################################################################

#IF NOT %DEF(%IFilterGraph2_INTERFACE_DEFINED)
    %IFilterGraph2_INTERFACE_DEFINED = 1

$IID_IFilterGraph2 = GUID$("{36b73882-c2c8-11cf-8b46-00805f6cef60}")

INTERFACE IFilterGraph2 $IID_IFilterGraph2

   INHERIT IUnknown

   ' =====================================================================================
   ' IGraphBuilder Methods
   ' =====================================================================================
   METHOD AddFilter ( _                                 ' VTable offset = 12
     BYVAL pFilter AS IBaseFilter _                     ' __in  IBaseFilter *pFilter
   , BYREF pName AS WSTRINGZ _                          ' __in  LPCWSTR pName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RemoveFilter ( _                              ' VTable offset = 16
     BYVAL pFilter AS IBaseFilter _                     ' __in  IBaseFilter *pFilter
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumFilters ( _                               ' VTable offset = 20
     BYREF ppEnum AS IEnumFilters _                     ' __out IEnumFilters **ppEnum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD FindFilterByName ( _                          ' VTable offset = 24
     BYREF pName AS WSTRINGZ _                          ' __in LPCWSTR pName
   , BYREF ppFilter AS IBaseFilter _                    ' __out IBaseFilter **ppFilter
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ConnectDirect ( _                             ' VTable offset = 28
     BYVAL ppinOut AS IPin _                            ' __in  IPin *ppinOut
   , BYVAL ppinIn AS IPin _                             ' __in  IPin *ppinIn
   , OPTIONAL BYREF pmt AS AM_MEDIA_TYPE _              ' __in_opt  const AM_MEDIA_TYPE *pmt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reconnect ( _                                 ' VTable offset = 32
     BYVAL ppin AS IPin _                               ' __in  IPin *ppin
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Disconnect ( _                                ' VTable offset = 36
     BYVAL ppin AS IPin _                               ' __in  IPin *ppin
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetDefaultSyncSource ( _                      ' VTable offset = 40
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Connect ( _                                   ' VTable offset = 44
     BYVAL ppinOut AS IPin _                            ' __in  IPin *ppinOut
   , BYVAL ppinIn AS IPin _                             ' __in  IPin *ppinIn
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Render ( _                                    ' VTable offset = 48
     BYVAL ppinOut AS IPin _                            ' __in  IPin *ppinOut
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RenderFile ( _                                ' VTable offset = 52
     BYREF lpcwstrFile AS WSTRINGZ _                    ' __in  LPCWSTR lpcwstrFile
   , OPTIONAL BYREF lpcwstrPlayList AS WSTRINGZ _       ' __in  LPCWSTR lpcwstrPlayList
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddSourceFilter ( _                           ' VTable offset = 56
     BYREF lpcwstrFileName AS WSTRINGZ _                ' __in  LPCWSTR lpcwstrFileName
   , BYREF lpcwstrFilterName AS WSTRINGZ _              ' __in  LPCWSTR lpcwstrFilterName
   , BYREF ppFilter AS IBaseFilter _                    ' __out IBaseFilter **ppFilter
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetLogFile ( _                                ' VTable offset = 60
     BYVAL hFile AS DWORD _                             ' __in  DWORD_PTR hFile
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Abort ( _                                     ' VTable offset = 64
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ShouldOperationContinue ( _                   ' VTable offset = 68
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IFilterGraph2 Methods
   ' =====================================================================================
   METHOD AddSourceFilterForMoniker ( _                 ' VTable offset = 72
     BYVAL pMoniker AS IMoniker _                       ' __in IMoniker *pMoniker
   , BYVAL pCtx AS IBindCtx _                           ' __in IBindCtx *pCtx
   , BYREF lpcwstrFilterName AS WSTRINGZ _              ' __in LPCWSTR lpcwstrFilterName
   , BYREF ppFilter AS IBaseFilter _                    ' __out IBaseFilter **ppFilter
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ReconnectEx ( _                               ' VTable offset = 76
     BYVAL ppin AS IPin _                               ' __in IPin *ppin
   , OPTIONAL BYREF pmt AS AM_MEDIA_TYPE _              ' __in_opt const AM_MEDIA_TYPE *pmt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RenderEx ( _                                  ' VTable offset = 80
     BYVAL pPinOut AS IPin _                            ' __in IPin *pPinOut
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYVAL pvContext AS DWORD _                         ' __inout LPVOID pvContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IFilterGraph2_INTERFACE_DEFINED__*/


' ########################################################################################
' Interface name = IFilterGraph3
' IID = {AAF38154-B80B-422F-91E6-B66467509A07}
' Inherited interface = IFilterGraph2
' ########################################################################################

#IF NOT %DEF(%IFilterGraph3_INTERFACE_DEFINED)
    %IFilterGraph3_INTERFACE_DEFINED = 1

$IID_IFilterGraph3 = GUID$("{AAF38154-B80B-422F-91E6-B66467509A07}")

INTERFACE IFilterGraph3 $IID_IFilterGraph3

   INHERIT IUnknown

   ' =====================================================================================
   ' IGraphBuilder Methods
   ' =====================================================================================
   METHOD AddFilter ( _                                 ' VTable offset = 12
     BYVAL pFilter AS IBaseFilter _                     ' __in  IBaseFilter *pFilter
   , BYREF pName AS WSTRINGZ _                          ' __in  LPCWSTR pName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RemoveFilter ( _                              ' VTable offset = 16
     BYVAL pFilter AS IBaseFilter _                     ' __in  IBaseFilter *pFilter
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumFilters ( _                               ' VTable offset = 20
     BYREF ppEnum AS IEnumFilters _                     ' __out IEnumFilters **ppEnum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD FindFilterByName ( _                          ' VTable offset = 24
     BYREF pName AS WSTRINGZ _                          ' __in LPCWSTR pName
   , BYREF ppFilter AS IBaseFilter _                    ' __out IBaseFilter **ppFilter
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ConnectDirect ( _                             ' VTable offset = 28
     BYVAL ppinOut AS IPin _                            ' __in  IPin *ppinOut
   , BYVAL ppinIn AS IPin _                             ' __in  IPin *ppinIn
   , OPTIONAL BYREF pmt AS AM_MEDIA_TYPE _              ' __in_opt  const AM_MEDIA_TYPE *pmt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reconnect ( _                                 ' VTable offset = 32
     BYVAL ppin AS IPin _                               ' __in  IPin *ppin
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Disconnect ( _                                ' VTable offset = 36
     BYVAL ppin AS IPin _                               ' __in  IPin *ppin
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetDefaultSyncSource ( _                      ' VTable offset = 40
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Connect ( _                                   ' VTable offset = 44
     BYVAL ppinOut AS IPin _                            ' __in  IPin *ppinOut
   , BYVAL ppinIn AS IPin _                             ' __in  IPin *ppinIn
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Render ( _                                    ' VTable offset = 48
     BYVAL ppinOut AS IPin _                            ' __in  IPin *ppinOut
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RenderFile ( _                                ' VTable offset = 52
     BYREF lpcwstrFile AS WSTRINGZ _                    ' __in  LPCWSTR lpcwstrFile
   , OPTIONAL BYREF lpcwstrPlayList AS WSTRINGZ _       ' __in  LPCWSTR lpcwstrPlayList
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddSourceFilter ( _                           ' VTable offset = 56
     BYREF lpcwstrFileName AS WSTRINGZ _                ' __in  LPCWSTR lpcwstrFileName
   , BYREF lpcwstrFilterName AS WSTRINGZ _              ' __in  LPCWSTR lpcwstrFilterName
   , BYREF ppFilter AS IBaseFilter _                    ' __out IBaseFilter **ppFilter
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetLogFile ( _                                ' VTable offset = 60
     BYVAL hFile AS DWORD _                             ' __in  DWORD_PTR hFile
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Abort ( _                                     ' VTable offset = 64
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ShouldOperationContinue ( _                   ' VTable offset = 68
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IFilterGraph2 Methods
   ' =====================================================================================
   METHOD AddSourceFilterForMoniker ( _                 ' VTable offset = 72
     BYVAL pMoniker AS IMoniker _                       ' __in IMoniker *pMoniker
   , BYVAL pCtx AS IBindCtx _                           ' __in IBindCtx *pCtx
   , BYREF lpcwstrFilterName AS WSTRINGZ _              ' __in LPCWSTR lpcwstrFilterName
   , BYREF ppFilter AS IBaseFilter _                    ' __out IBaseFilter **ppFilter
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ReconnectEx ( _                               ' VTable offset = 76
     BYVAL ppin AS IPin _                               ' __in IPin *ppin
   , OPTIONAL BYREF pmt AS AM_MEDIA_TYPE _              ' __in const AM_MEDIA_TYPE *pmt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RenderEx ( _                                  ' VTable offset = 80
     BYVAL pPinOut AS IPin _                            ' __in IPin *pPinOut
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYVAL pvContext AS DWORD _                         ' __inout LPVOID pvContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IFilterGraph3 Methods
   ' =====================================================================================
   METHOD SetSyncSourceEx ( _                           ' VTable offset = 84
     BYVAL pClockForMostOfFilterGraph As IReferenceClock _ ' __in  IReferenceClock *pClockForMostOfFilterGraph
   , BYVAL pClockForFilter AS IReferenceClock _         ' __in  IReferenceClock *pClockForFilter
   , BYVAL pFilter As IBaseFilter _                     ' __in  IBaseFilter *pFilter
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IFilterGraph3_INTERFACE_DEFINED__*/


' ########################################################################################
' Interface name = IStreamBuilder
' IID = {56A868BF-0AD4-11CE-B03A-0020AF0BA770}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IStreamBuilder_INTERFACE_DEFINED)
    %IStreamBuilder_INTERFACE_DEFINED = 1

$IID_IStreamBuilder = GUID$("{56A868BF-0AD4-11CE-B03A-0020AF0BA770}")

INTERFACE IStreamBuilder $IID_IStreamBuilder

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Render ( _                                    ' VTable offset = 12
     BYVAL ppinOut AS IPin _                            ' __in  IPin *ppinOut
   , BYVAL pGraph AS IGraphBuilder _                    ' __in  IGraphBuilder *pGraph
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Backout ( _                                   ' VTable offset = 16
     BYVAL ppinOut AS IPin _                            ' __in  IPin *ppinOut
   , BYVAL pGraph AS IGraphBuilder _                    ' __in  IGraphBuilder *pGraph
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================


END INTERFACE

#ENDIF   ' /* __IStreamBuilder_INTERFACE_DEFINED__*/


' ########################################################################################
' Interface name = IAsyncReader
' IID = {56A868BF-0AD4-11CE-B03A-0020AF0BA770}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IAsyncReader_INTERFACE_DEFINED)
    %IAsyncReader_INTERFACE_DEFINED = 1

$IID_IAsyncReader = GUID$("{56A868BF-0AD4-11CE-B03A-0020AF0BA770}")

INTERFACE IAsyncReader $IID_IAsyncReader

   INHERIT IUnknown

   ' =====================================================================================
   METHOD RequestAllocator ( _                          ' VTable offset = 12
     BYVAL pPreferred AS IMemAllocator _                ' __in  IMemAllocator *pPreferred
   , BYREF pProps AS ALLOCATOR_PROPERTIES _             ' __in  ALLOCATOR_PROPERTIES *pProps
   , BYREF ppActual AS IMemAllocator _                  ' __out IMemAllocator **ppActual
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Request ( _                                   ' VTable offset = 16
     BYVAL pSample AS IMediaSample _                    ' __in  IMediaSample *pSample
   , BYVAL dwUser AS DWORD _                            ' __in  DWORD_PTR dwUser
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD WaitForNext ( _                               ' VTable offset = 20
     BYVAL dwTimeout AS DWORD _                         ' __in  DWORD dwTimeout
   , BYREF ppSample AS IMediaSample _                   ' __out_opt IMediaSample **ppSample
   , BYREF pdwUser As DWORD _                           ' __out DWORD_PTR *pdwUser
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SyncReadAligned ( _                           ' VTable offset = 24
     BYVAL pSample AS IMediaSample _                    ' __in  IMediaSample *pSample
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SyncRead ( _                                  ' VTable offset = 28
     BYVAL llPosition AS QUAD _                         ' __in  LONGLONG llPosition
   , BYVAL lLength As LONG _                            ' __in  LONG lLength
   , BYVAL pBuffer AS BYTE PTR _                        ' __out BYTE *pBuffer
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Length ( _                                    ' VTable offset = 32
     BYREF pTotal AS QUAD _                             ' __out LONGLONG *pTotal
   , BYREF pAvailable AS QUAD _                         ' __out LONGLONG *pAvailable
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD BeginFlush ( _                                ' VTable offset = 36
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EndFlush ( _                                  ' VTable offset = 40
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAsyncReader_INTERFACE_DEFINED__*/


' ########################################################################################
' Interface name = IGraphVersion
' IID = {56A868AB-0AD4-11CE-B03A-0020AF0BA770}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IGraphVersion_INTERFACE_DEFINED)
    %IGraphVersion_INTERFACE_DEFINED = 1

$IID_IGraphVersion = GUID$("{56A868AB-0AD4-11CE-B03A-0020AF0BA770}")

INTERFACE IGraphVersion $IID_IGraphVersion

   INHERIT IUnknown

   ' =====================================================================================
   METHOD QueryVersion ( _                              ' VTable offset = 12
     BYVAL pVersion AS LONG _                           ' __in  LONG *pVersion
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IGraphVersion_INTERFACE_DEFINED__*/


' ########################################################################################
' Interface name = IResourceConsumer
' IID = {56A868AD-0AD4-11CE-B03A-0020AF0BA770}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IResourceConsumer_INTERFACE_DEFINED)
    %IResourceConsumer_INTERFACE_DEFINED = 1

$IID_IResourceConsumer = GUID$("{56A868AD-0AD4-11CE-B03A-0020AF0BA770}")

INTERFACE IResourceConsumer $IID_IResourceConsumer

   INHERIT IUnknown

   ' =====================================================================================
   METHOD AcquireResource ( _                           ' VTable offset = 12
     BYVAL idResource AS LONG _                         ' __in  LONG idResource
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ReleaseResource ( _                           ' VTable offset = 16
     BYVAL idResource AS LONG _                         ' __in  LONG idResource
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IResourceConsumer_INTERFACE_DEFINED__*/


' ########################################################################################
' Interface name = IResourceManager
' IID = {56A868AC-0AD4-11CE-B03A-0020AF0BA770}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IResourceManager_INTERFACE_DEFINED)
    %IResourceManager_INTERFACE_DEFINED = 1

$IID_IResourceManager = GUID$("{56A868AC-0AD4-11CE-B03A-0020AF0BA770}")

INTERFACE IResourceManager $IID_IResourceManager

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Register ( _                                  ' VTable offset = 12
     BYREF pName AS WSTRINGZ _                          ' __in  LPCWSTR pName
   , BYVAL cResource AS LONG _                          ' __in  LONG cResource
   , BYREF plToken AS LONG _                            ' __out LONG *plToken
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RegisterGroup ( _                             ' VTable offset = 16
     BYREF pName As WSTRINGZ _                          ' __in  LPCWSTR pName
   , BYVAL cResource AS LONG _                          ' __in  LONG cResource
   , BYVAL palTokens AS LONG _                          ' __in  LONG *palTokens
   , BYREF plToken AS LONG _                            ' __out LONG *plToken
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RequestResource ( _                           ' VTable offset = 20
     BYVAL idResource AS LONG _                         ' __in  LONG idResource
   , BYVAL pFocusObject AS IUnknown _                   ' __in  IUnknown *pFocusObject
   , BYVAL pConsumer AS IResourceConsumer _             ' __in  IResourceConsumer *pConsumer
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD NotifyAcquire ( _                             ' VTable offset = 24
     BYVAL idResource AS LONG _                         ' __in  LONG idResource
   , BYVAL pConsumer AS IResourceConsumer _             ' __in  IResourceConsumer *pConsumer
   , BYVAL hr AS LONG _                                 ' __in  HRESULT hr
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD NotifyRelease ( _                             ' VTable offset = 28
     BYVAL idResource As LONG _                         ' __in  LONG idResource
   , BYVAL pConsumer AS IResourceConsumer _             ' __in  IResourceConsumer *pConsumer
   , BYVAL bStillWant AS LONG _                         ' __in  BOOL bStillWant
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CancelRequest ( _                             ' VTable offset = 32
     BYVAL idResource AS LONG _                         ' __in  LONG idResource
   , BYVAL pConsumer AS IResourceConsumer _             ' __in  IResourceConsumer *pConsumer
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetFocus ( _                                  ' VTable offset = 36
     BYVAL pFocusObject AS IUnknown _                   ' __in  IUnknown *pFocusObject
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ReleaseFocus ( _                              ' VTable offset = 40
     BYVAL pFocusObject As IUnknown _                   ' __in  IUnknown *pFocusObject
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IResourceManager_INTERFACE_DEFINED__*/


' ########################################################################################
' Interface name = IDistributorNotify
' IID = {56A868AF-0AD4-11CE-B03A-0020AF0BA770}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDistributorNotify_INTERFACE_DEFINED)
    %IDistributorNotify_INTERFACE_DEFINED = 1

$IID_IDistributorNotify = GUID$("{56A868AF-0AD4-11CE-B03A-0020AF0BA770}")

INTERFACE IDistributorNotify $IID_IDistributorNotify

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Stop( _                                       ' VTable offset = 12
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Pause ( _                                     ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Run ( _                                       ' VTable offset = 20
     BYVAL tStart As QUAD _                             ' REFERENCE_TIME tStart
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetSyncSource ( _                             ' VTable offset = 24
     BYVAL pClock AS IReferenceClock _                  ' __in  IReferenceClock *pClock
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD NotifyGraphChange ( _                         ' VTable offset = 28
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDistributorNotify_INTERFACE_DEFINED__*/


' enum AM_STREAM_INFO_FLAGS
%AM_STREAM_INFO_START_DEFINED   = &H1
%AM_STREAM_INFO_STOP_DEFINED    = &H2
%AM_STREAM_INFO_DISCARDING      = &H4
%AM_STREAM_INFO_STOP_SEND_EXTRA = &H10

' // Size = 32 bytes
TYPE AM_STREAM_INFO   ' Must be 8 byte aligned
   tStart        AS QUAD    ' REFERENCE_TIME tStart
   tStop         AS QUAD    ' REFERENCE_TIME tStop
   dwStartCookie AS DWORD   ' DWORD dwStartCookie
   dwStopCookie  AS DWORD   ' DWORD dwStopCookie
   dwFlags       AS DWORD   ' DWORD dwFlags
   alignment__   AS DWORD   ' // To keep 8 byte alignment
END TYPE


' ########################################################################################
' Interface name = IAMStreamControl
' IID = {36B73881-C2C8-11CF-8B46-00805F6CEF60}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IAMStreamControl_INTERFACE_DEFINED)
    %IAMStreamControl_INTERFACE_DEFINED = 1

$IID_IAMStreamControl = GUID$("{36B73881-C2C8-11CF-8B46-00805F6CEF60}")

INTERFACE IAMStreamControl $IID_IAMStreamControl

   INHERIT IUnknown

   ' =====================================================================================
   METHOD StartAt ( _                                   ' VTable offset = 12
     BYREF ptStart AS QUAD _                            ' __in_opt  const REFERENCE_TIME *ptStart
   , BYVAL dwCookie AS DWORD _                          ' __in  DWORD dwCookie
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD StopAt ( _                                    ' VTable offset = 16
     BYREF ptStop AS QUAD _                             ' __in_opt  const REFERENCE_TIME *ptStop
   , BYVAL bSendExtra AS LONG _                         ' __in  BOOL bSendExtra
   , BYVAL dwCookie AS DWORD _                          ' __in  DWORD dwCookie
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetInfo ( _                                   ' VTable offset = 20
     BYREF pInfo AS DWORD _                             ' __out AM_STREAM_INFO *pInfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAMStreamControl_INTERFACE_DEFINED__*/


' ########################################################################################
' Interface name = ISeekingPassThru
' IID = {36B73883-C2C8-11CF-8B46-00805F6CEF60}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ISeekingPassThru_INTERFACE_DEFINED)
    %ISeekingPassThru_INTERFACE_DEFINED = 1

$IID_ISeekingPassThru = GUID$("{36B73883-C2C8-11CF-8B46-00805F6CEF60}")

INTERFACE ISeekingPassThru $IID_ISeekingPassThru

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Init ( _                                      ' VTable offset = 12
     BYVAL bSupportRendering AS LONG _                  ' __in  BOOL bSupportRendering
   , BYVAL pPin AS IPin _                               ' __in  IPin *pPin
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISeekingPassThru_INTERFACE_DEFINED__*/


' ########################################################################################
' Interface name = IAMStreamConfig
' IID = {C6E13340-30AC-11D0-A18C-00A0C9118956}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IAMStreamConfig_INTERFACE_DEFINED)
    %IAMStreamConfig_INTERFACE_DEFINED = 1

$IID_IAMStreamConfig = GUID$("{C6E13340-30AC-11D0-A18C-00A0C9118956}")

' // Size = 128 bytes
TYPE VIDEO_STREAM_CONFIG_CAPS   ' Must be 8 byte aligned
   guid               AS GUID      ' GUID guid
   VideoStandard      AS DWORD     ' ULONG VideoStandard
   InputSize          AS SIZE      ' SIZE InputSize
   MinCroppingSize    AS SIZE      ' SIZE MinCroppingSize
   MaxCroppingSize    AS SIZE      ' SIZE MaxCroppingSize
   CropGranularityX   AS LONG      ' int CropGranularityX
   CropGranularityY   AS LONG      ' int CropGranularityY
   CropAlignX         AS LONG      ' int CropAlignX
   CropAlignY         AS LONG      ' int CropAlignY
   MinOutputSize      AS SIZE      ' SIZE MinOutputSize
   MaxOutputSize      AS SIZE      ' SIZE MaxOutputSize
   OutputGranularityX AS LONG      ' int OutputGranularityX
   OutputGranularityY AS LONG      ' int OutputGranularityY
   StretchTapsX       AS LONG      ' int StretchTapsX
   StretchTapsY       AS LONG      ' int StretchTapsY
   ShrinkTapsX        AS LONG      ' int ShrinkTapsX
   ShrinkTapsY        AS LONG      ' int ShrinkTapsY
   alignment__        AS DWORD
   MinFrameInterval   AS QUAD      ' LONGLONG MinFrameInterval
   MaxFrameInterval   AS QUAD      ' LONGLONG MaxFrameInterval
   MinBitsPerSecond   AS LONG      ' LONG MinBitsPerSecond
   MaxBitsPerSecond   AS LONG      ' LONG MaxBitsPerSecond
END TYPE

' // Size = 52 bytes
TYPE AUDIO_STREAM_CONFIG_CAPS DWORD
   guid                       AS GUID    ' GUID guid
   MinimumChannels            AS DWORD   ' ULONG MinimumChannels
   MaximumChannels            AS DWORD   ' ULONG MaximumChannels
   ChannelsGranularity        AS DWORD   ' ChannelsGranularity
   MinimumBitsPerSample       AS DWORD   ' MinimumBitsPerSample
   MaximumBitsPerSample       AS DWORD   ' MaximumBitsPerSample
   BitsPerSampleGranularity   AS DWORD   ' BitsPerSampleGranularity
   MinimumSampleFrequency     AS DWORD   ' MinimumSampleFrequency
   MaximumSampleFrequency     AS DWORD   ' MaximumSampleFrequency
   SampleFrequencyGranularity AS DWORD   ' SampleFrequencyGranularity
END TYPE


INTERFACE IAMStreamConfig $IID_IAMStreamConfig

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetFormat ( _                                 ' VTable offset = 12
     BYREF pmt As AM_MEDIA_TYPE _                       ' __in  AM_MEDIA_TYPE *pmt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFormat ( _                                 ' VTable offset = 16
     BYREF ppmt AS AM_MEDIA_TYPE _                      ' __out AM_MEDIA_TYPE **ppmt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetNumberOfCapabilities ( _                   ' VTable offset = 20
     BYREF piCount AS LONG _                            ' __out int *piCount
   , BYREF piSize AS LONG _                             ' __out int *piSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetStreamCaps ( _                             ' VTable offset = 24
     BYVAL iIndex As LONG _                             ' __in  int iIndex
   , BYREF ppmt As AM_MEDIA_TYPE _                      ' __out AM_MEDIA_TYPE **ppmt
   , BYVAL pSCC AS BYTE PTR _                           ' __out BYTE *pSCC
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAMStreamConfig_INTERFACE_DEFINED__*/


' ########################################################################################
' Interface name = IConfigInterleaving
' IID = {BEE3D220-157B-11D0-BD23-00A0C911CE86}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IConfigInterleaving_INTERFACE_DEFINED)
    %IConfigInterleaving_INTERFACE_DEFINED = 1

$IID_IConfigInterleaving = GUID$("{BEE3D220-157B-11D0-BD23-00A0C911CE86}")

' enum InterleavingMode
%INTERLEAVE_NONE          = 0
%INTERLEAVE_CAPTURE       = %INTERLEAVE_NONE    + 1
%INTERLEAVE_FULL          = %INTERLEAVE_CAPTURE + 1
%INTERLEAVE_NONE_BUFFERED = %INTERLEAVE_FULL    + 1

INTERFACE IConfigInterleaving $IID_IConfigInterleaving

   INHERIT IUnknown

   ' =====================================================================================
   METHOD put_Mode ( _                                  ' VTable offset = 12
     BYVAL mode AS DWORD _                              ' __in  InterleavingMode mode
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_Mode ( _                                  ' VTable offset = 16
     BYREF pmode AS DWORD _                             ' __out InterleavingMode *pmode
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_Interleaving ( _                          ' VTable offset = 20
     BYREF prtInterleave AS QUAD _                      ' __in  const REFERENCE_TIME *prtInterleave
   , BYREF prtPreroll AS QUAD _                         ' __in  const REFERENCE_TIME *prtPreroll
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_Interleaving ( _                          ' VTable offset = 24
     BYREF prtInterleave AS QUAD _                      ' __out const REFERENCE_TIME *prtInterleave
   , BYREF prtPreroll AS QUAD _                         ' __out const REFERENCE_TIME *prtPreroll
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IConfigInterleaving_INTERFACE_DEFINED__*/


' ########################################################################################
' Interface name = IConfigAviMux
' IID = {5ACD6AA0-F482-11CE-8B67-00AA00A3F1A6}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IConfigAviMux_INTERFACE_DEFINED)
    %IConfigAviMux_INTERFACE_DEFINED = 1

$IID_IConfigAviMux = GUID$("{5ACD6AA0-F482-11CE-8B67-00AA00A3F1A6}")

INTERFACE IConfigAviMux $IID_IConfigAviMux

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetMasterStream ( _                           ' VTable offset = 12
     BYVAL iStream AS LONG _                            ' __in  LONG iStream
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMasterStream ( _                           ' VTable offset = 16
     BYREF pStream AS LONG _                            ' __out LONG *pStream
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetOutputCompatibilityIndex ( _               ' VTable offset = 20
     BYVAL fOldIndex AS LONG _                          ' __in  BOOL fOldIndex
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetOutputCompatibilityIndex ( _               ' VTable offset = 24
     BYREF pfOldIndex AS LONG _                         ' __out BOOL *pfOldIndex
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IConfigAviMux_INTERFACE_DEFINED__*/


' enum CompressionCaps
%CompressionCaps_CanQuality  = &H1
%CompressionCaps_CanCrunch   = &H2
%CompressionCaps_CanKeyFrame = &H4
%CompressionCaps_CanBFrame   = &H8
%CompressionCaps_CanWindow   = &H10


' ########################################################################################
' Interface name = IAMVideoCompression
' IID = {C6E13343-30AC-11d0-A18C-00A0C9118956}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IAMVideoCompression_INTERFACE_DEFINED)
    %IAMVideoCompression_INTERFACE_DEFINED = 1

$IID_IAMVideoCompression = GUID$("{C6E13343-30AC-11d0-A18C-00A0C9118956}")

INTERFACE IAMVideoCompression $IID_IAMVideoCompression

   INHERIT IUnknown

   ' =====================================================================================
   METHOD put_KeyFrameRate ( _                          ' VTable offset = 12
     BYVAL KeyFrameRate AS LONG _                       ' __in  long KeyFrameRate
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_KeyFrameRate ( _                          ' VTable offset = 16
     BYREF pKeyFrameRate AS LONG _                      ' __out long *pKeyFrameRate
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_PFramesPerKeyFrame ( _                    ' VTable offset = 20
     BYVAL PFramesPerKeyFrame AS LONG _                 ' __in  long PFramesPerKeyFrame
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_PFramesPerKeyFrame ( _                    ' VTable offset = 24
     BYREF pPFramesPerKeyFrame AS LONG _                ' __out long *pPFramesPerKeyFrame
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_Quality ( _                               ' VTable offset = 28
     BYVAL Quality AS DOUBLE _                          ' __in  double Quality
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_Quality ( _                               ' VTable offset = 32
     BYREF pQuality AS DOUBLE _                         ' __out double *pQuality
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_WindowSize ( _                            ' VTable offset = 36
     BYVAL WindowSize AS QUAD _                         ' __in  DWORDLONG WindowSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_WindowSize ( _                            ' VTable offset = 40
     BYREF pWindowSize AS QUAD _                        ' __out DWORDLONG *pWindowSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetInfo ( _                                   ' VTable offset = 44
     OPTIONAL BYREF pszVersion AS WSTRINGZ _            ' __out_pot LPWSTR pszVersion,
   , OPTIONAL BYREF pcbVersion AS LONG _                ' __inout_opt int *pcbVersion
   , OPTIONAL BYREF pszDescription AS WSTRINGZ _        ' __out_opt LPWSTR pszDescription
   , OPTIONAL BYREF pcbDescription AS LONG _            ' __inout_opt int *pcbDescription
   , OPTIONAL BYREF pDefaultKeyFrameRate AS LONG _      ' __out_opt long *pDefaultKeyFrameRate
   , OPTIONAL BYREF pDefaultPFramesPerKey AS LONG _     ' __out_opt long *pDefaultPFramesPerKey
   , OPTIONAL BYREF pDefaultQuality AS DOUBLE _         ' __out_opt double *pDefaultQuality
   , OPTIONAL BYREF pCapabilities AS LONG _             ' __out_opt long *pCapabilities
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OverrideKeyFrame ( _                          ' VTable offset = 48
     BYVAL FrameNumber AS LONG _                        ' __in  long FrameNumber
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OverrideFrameSize ( _                         ' VTable offset = 52
     BYVAL FrameNumber AS LONG _                        ' __in  long FrameNumber
   , BYVAL Size AS LONG _                               ' __in  long Size
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAMVideoCompression_INTERFACE_DEFINED__*/

' enum VfwCaptureDialogs
%VfwCaptureDialog_Source       = &H1
%VfwCaptureDialog_Format       = &H2
%VfwCaptureDialog_Display      = &H4

' enum VfwCompressDialogs
%VfwCompressDialog_Config      = &H1
%VfwCompressDialog_About       = &H2
%VfwCompressDialog_QueryConfig = &H4
%VfwCompressDialog_QueryAbout  = &H8


' ########################################################################################
' Interface name = IAMVfwCaptureDialogs
' IID = {D8D715A0-6E5E-11D0-B3F0-00AA003761C5}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IAMVfwCaptureDialogs_INTERFACE_DEFINED)
    %IAMVfwCaptureDialogs_INTERFACE_DEFINED = 1

$IID_IAMVfwCaptureDialogs = GUID$("{D8D715A0-6E5E-11D0-B3F0-00AA003761C5}")

INTERFACE IAMVfwCaptureDialogs $IID_IAMVfwCaptureDialogs

   INHERIT IUnknown

   ' =====================================================================================
   METHOD HasDialog ( _                                 ' VTable offset = 12
     BYVAL iDialog AS LONG _                            ' __in  int iDialog
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ShowDialog ( _                                ' VTable offset = 16
     BYVAL iDialog AS LONG _                            ' __in  int iDialog
   , BYVAL hwnd AS DWORD _                              ' __in  HWND hwnd
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SendDriverMessage ( _                         ' VTable offset = 20
     BYVAL iDialog AS LONG _                            ' __in  int iDialog
   , BYVAL uMsg AS LONG _                               ' __in  int uMsg
   , BYVAL dw1 AS LONG _                                ' __in  long dw1
   , BYVAL dw2 As LONG _                                ' __in  long dw2
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAMVfwCaptureDialogs_INTERFACE_DEFINED__*/


' ########################################################################################
' Interface name = IAMVfwCompressDialogs
' IID = {D8D715A0-6E5E-11D0-B3F0-00AA003761C5}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IAMVfwCompressDialogs_INTERFACE_DEFINED)
    %IAMVfwCompressDialogs_INTERFACE_DEFINED = 1

$IID_IAMVfwCompressDialogs = GUID$("{D8D715A0-6E5E-11D0-B3F0-00AA003761C5}")

INTERFACE IAMVfwCompressDialogs $IID_IAMVfwCompressDialogs

   INHERIT IUnknown

   ' =====================================================================================
   METHOD ShowDialog ( _                                ' VTable offset = 12
     BYVAL iDialog AS LONG _                            ' __in  int iDialog
   , BYVAL hwnd AS DWORD _                              ' __in  HWND hwnd
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetState ( _                                  ' VTable offset = 16
     BYREF pState AS DWORD _                            ' __out LPVOID pState
   , BYREF pcbState AS LONG _                           ' __inout int *pcbState
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetState ( _                                  ' VTable offset = 20
     BYVAL pState AS DWORD _                            ' __in  LPVOID pState
   , BYVAL cbState AS LONG _                            ' __in  int cbState
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SendDriverMessage ( _                         ' VTable offset = 24
     BYVAL uMsg AS LONG _                               ' __in  int uMsg
   , BYVAL dw1 AS LONG _                                ' __in  long dw1
   , BYVAL dw2 AS LONG _                                ' __in  long dw2
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAMVfwCompressDialogs_INTERFACE_DEFINED__*/


' ########################################################################################
' Interface name = IAMDroppedFrames
' IID = {C6E13344-30AC-11D0-A18C-00A0C9118956}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IAMDroppedFrames_INTERFACE_DEFINED)
    %IAMDroppedFrames_INTERFACE_DEFINED = 1

$IID_IAMDroppedFrames = GUID$("{C6E13344-30AC-11D0-A18C-00A0C9118956}")

INTERFACE IAMDroppedFrames $IID_IAMDroppedFrames

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetNumDropped ( _                             ' VTable offset = 12
     BYREF plDropped AS LONG _                          ' __out long *plDropped
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetNumNotDropped ( _                          ' VTable offset = 16
     BYREF plNotDropped AS LONG _                       ' __out long *plNotDropped
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDroppedInfo ( _                            ' VTable offset = 20
     BYVAL lSize AS LONG _                              ' __in  long lSize
   , BYREF plArray AS LONG _                            ' __out long *plArray
   , BYREF plNumCopied AS LONG _                        ' __out long *plNumCopied
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAverageFrameSize ( _                       ' VTable offset = 24
     BYREF plAverageSize AS LONG _                      ' __out long *plAverageSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAMDroppedFrames_INTERFACE_DEFINED__*/


' ########################################################################################
' Interface name = IAMAudioInputMixer
' IID = {54C39221-8380-11D0-B3F0-00AA003761C5}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IAMAudioInputMixer_INTERFACE_DEFINED)
    %IAMAudioInputMixer_INTERFACE_DEFINED = 1

'#define AMF_AUTOMATICGAIN -1.0
%AMF_AUTOMATICGAIN = -1

$IID_IAMAudioInputMixer = GUID$("{54C39221-8380-11D0-B3F0-00AA003761C5}")

INTERFACE IAMAudioInputMixer $IID_IAMAudioInputMixer

   INHERIT IUnknown

   ' =====================================================================================
   METHOD put_Enable ( _                                ' VTable offset = 12
     BYVAL fEnable AS LONG _                            ' __in  BOOL fEnable
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_Enable ( _                                ' VTable offset = 16
     BYREF pfEnable AS LONG _                           ' __out BOOL *pfEnable
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_Mono ( _                                  ' VTable offset = 20
     BYVAL fMono AS LONG _                              ' __in  BOOL fMono
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_Mono ( _                                  ' VTable offset = 24
     BYREF pfMono AS LONG _                             ' __out BOOL *pfMono
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_MixLevel ( _                              ' VTable offset = 28
     BYVAL Level As DOUBLE _                            ' __in  double Level
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_MixLevel ( _                              ' VTable offset = 32
     BYREF pLevel AS DOUBLE _                           ' __out double *pLevel
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_Pan ( _                                   ' VTable offset = 36
     BYVAL Pan AS DOUBLE _                              ' __in  double Pan
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_Pan ( _                                   ' VTable offset = 40
     BYREF pPan AS DOUBLE _                             ' __out double *pPan
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_Loudness ( _                              ' VTable offset = 44
     BYVAL fLoudness AS LONG _                          ' __in  BOOL fLoudness
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_Loudness ( _                              ' VTable offset = 48
     BYREF pfLoudness AS LONG _                         ' __out BOOL *pfLoudness
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_Treble ( _                                ' VTable offset = 52
     BYVAL Treble AS DOUBLE _                           ' __in  double Treble
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_Treble ( _                                ' VTable offset = 56
     BYREF pTreble AS DOUBLE _                          ' __out double *pTreble
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_TrebleRange ( _                           ' VTable offset = 60
     BYREF pRange AS DOUBLE _                           ' __out double *pRange
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_Bass ( _                                  ' VTable offset = 64
     BYVAL Bass AS DOUBLE _                             ' __in  double Bass
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_Bass ( _                                  ' VTable offset = 68
     BYREF pBass AS DOUBLE _                            ' __out double *pBass
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_BassRange ( _                             ' VTable offset = 72
     BYREF pRange AS DOUBLE _                           ' __out double *pRange
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAMAudioInputMixer_INTERFACE_DEFINED__*/


' ########################################################################################
' Interface name = IAMBufferNegotiation
' IID = {56ED71A0-AF5F-11D0-B3F0-00AA003761C5}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IAMBufferNegotiation_INTERFACE_DEFINED)
    %IAMBufferNegotiation_INTERFACE_DEFINED = 1

$IID_IAMBufferNegotiation = GUID$("{56ED71A0-AF5F-11D0-B3F0-00AA003761C5}")

INTERFACE IAMBufferNegotiation $IID_IAMBufferNegotiation

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SuggestAllocatorProperties ( _                ' VTable offset = 12
     BYREF pprop AS ALLOCATOR_PROPERTIES _              ' __in  const ALLOCATOR_PROPERTIES *pprop
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAllocatorProperties ( _                    ' VTable offset = 16
     BYREF pprop AS ALLOCATOR_PROPERTIES _              ' __out const ALLOCATOR_PROPERTIES *pprop
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAMBufferNegotiation_INTERFACE_DEFINED__*/


' enum AnalogVideoStandard
%AnalogVideo_None        = 0
%AnalogVideo_NTSC_M      = &H1
%AnalogVideo_NTSC_M_J    = &H2
%AnalogVideo_NTSC_433    = &H4
%AnalogVideo_PAL_B       = &H10
%AnalogVideo_PAL_D       = &H20
%AnalogVideo_PAL_G       = &H40
%AnalogVideo_PAL_H       = &H80
%AnalogVideo_PAL_I       = &H100
%AnalogVideo_PAL_M       = &H200
%AnalogVideo_PAL_N       = &H400
%AnalogVideo_PAL_60      = &H800
%AnalogVideo_SECAM_B     = &H1000
%AnalogVideo_SECAM_D     = &H2000
%AnalogVideo_SECAM_G     = &H4000
%AnalogVideo_SECAM_H     = &H8000
%AnalogVideo_SECAM_K     = &H10000
%AnalogVideo_SECAM_K1    = &H20000
%AnalogVideo_SECAM_L     = &H40000
%AnalogVideo_SECAM_L1    = &H80000
%AnalogVideo_PAL_N_COMBO = &H100000

%AnalogVideoMask_MCE_NTSC  = ((((((%AnalogVideo_NTSC_M OR %AnalogVideo_NTSC_M_J ) OR %AnalogVideo_NTSC_433) OR %AnalogVideo_PAL_M) OR %AnalogVideo_PAL_N) OR %AnalogVideo_PAL_60) OR %AnalogVideo_PAL_N_COMBO)
%AnalogVideoMask_MCE_PAL   = ((((%AnalogVideo_PAL_B OR %AnalogVideo_PAL_D) OR %AnalogVideo_PAL_G) OR %AnalogVideo_PAL_H) OR %AnalogVideo_PAL_I)
%AnalogVideoMask_MCE_SECAM = (((((((%AnalogVideo_SECAM_B OR %AnalogVideo_SECAM_D) OR %AnalogVideo_SECAM_G) OR %AnalogVideo_SECAM_H) OR %AnalogVideo_SECAM_K) OR %AnalogVideo_SECAM_K1) OR %AnalogVideo_SECAM_L) OR %AnalogVideo_SECAM_L1)

' enum TunerInputType
%TunerInputCable         = 0
%TunerInputAntenna       = %TunerInputCable + 1

%AnalogVideo_NTSC_Mask   = &H00000007???
%AnalogVideo_PAL_Mask    = &H00100FF0???
%AnalogVideo_SECAM_Mask  = &H000FF000???

' enum VideoCopyProtectionType
%VideoCopyProtectionMacrovisionBasic = 0
%VideoCopyProtectionMacrovisionCBI   = %VideoCopyProtectionMacrovisionBasic + 1

' enum PhysicalConnectorType
%PhysConn_Video_Tuner           = 1
%PhysConn_Video_Composite       = %PhysConn_Video_Tuner          + 1
%PhysConn_Video_SVideo          = %PhysConn_Video_Composite       + 1
%PhysConn_Video_RGB             = %PhysConn_Video_SVideo          + 1
%PhysConn_Video_YRYBY           = %PhysConn_Video_RGB             + 1
%PhysConn_Video_SerialDigital   = %PhysConn_Video_YRYBY           + 1
%PhysConn_Video_ParallelDigital = %PhysConn_Video_SerialDigital   + 1
%PhysConn_Video_SCSI            = %PhysConn_Video_ParallelDigital + 1
%PhysConn_Video_AUX             = %PhysConn_Video_SCSI            + 1
%PhysConn_Video_1394            = %PhysConn_Video_AUX             + 1
%PhysConn_Video_USB             = %PhysConn_Video_1394            + 1
%PhysConn_Video_VideoDecoder    = %PhysConn_Video_USB             + 1
%PhysConn_Video_VideoEncoder    = %PhysConn_Video_VideoDecoder    + 1
%PhysConn_Video_SCART           = %PhysConn_Video_VideoEncoder    + 1
%PhysConn_Video_Black           = %PhysConn_Video_SCART           + 1
%PhysConn_Audio_Tuner           = &H1000
%PhysConn_Audio_Line            = %PhysConn_Audio_Tuner           + 1
%PhysConn_Audio_Mic             = %PhysConn_Audio_Line            + 1
%PhysConn_Audio_AESDigital      = %PhysConn_Audio_Mic             + 1
%PhysConn_Audio_SPDIFDigital    = %PhysConn_Audio_AESDigital      + 1
%PhysConn_Audio_SCSI            = %PhysConn_Audio_SPDIFDigital    + 1
%PhysConn_Audio_AUX             = %PhysConn_Audio_SCSI            + 1
%PhysConn_Audio_1394            = %PhysConn_Audio_AUX             + 1
%PhysConn_Audio_USB             = %PhysConn_Audio_1394            + 1
%PhysConn_Audio_AudioDecoder    = %PhysConn_Audio_USB             + 1


' ########################################################################################
' Interface name = IAMAnalogVideoDecoder
' IID = {C6E13350-30AC-11d0-A18C-00A0C9118956}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IAMAnalogVideoDecoder_INTERFACE_DEFINED)
    %IAMAnalogVideoDecoder_INTERFACE_DEFINED = 1

$IID_IAMAnalogVideoDecoder = GUID$("{C6E13350-30AC-11d0-A18C-00A0C9118956}")

INTERFACE IAMAnalogVideoDecoder $IID_IAMAnalogVideoDecoder

   INHERIT IUnknown

   ' =====================================================================================
   METHOD get_AvailableTVFormats ( _                    ' VTable offset = 12
     BYREF lAnalogVideoStandard AS LONG _               ' __out long *lAnalogVideoStandard
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_TVFormat ( _                              ' VTable offset = 16
     BYVAL lAnalogVideoStandard AS LONG _               ' __in  long lAnalogVideoStandard
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_TVFormat ( _                              ' VTable offset = 20
     BYREF plAnalogVideoStandard AS LONG _              ' __out long *plAnalogVideoStandard
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_HorizontalLocked ( _                      ' VTable offset = 24
     BYREF plLocked AS LONG _                           ' __out long *plLocked
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_VCRHorizontalLocking ( _                  ' VTable offset = 28
     BYVAL lVCRHorizontalLocking AS LONG _              ' __in  long lVCRHorizontalLocking
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_VCRHorizontalLocking ( _                  ' VTable offset = 32
     BYREF plVCRHorizontalLocking AS LONG _             ' __out long *plVCRHorizontalLocking
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_NumberOfLines ( _                         ' VTable offset = 36
     BYREF plNumberOfLines AS LONG _                    ' __out long *plNumberOfLines
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_OutputEnable ( _                          ' VTable offset = 40
     BYVAL lOutputEnable AS LONG _                      ' __in  long lOutputEnable
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_OutputEnable ( _                          ' VTable offset = 44
     BYREF plOutputEnable AS LONG _                     ' __out long *plOutputEnable
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAMAnalogVideoDecoder_INTERFACE_DEFINED__*/


' enum VideoProcAmpProperty
%VideoProcAmp_Brightness            = 0
%VideoProcAmp_Contrast              = %VideoProcAmp_Brightness            + 1
%VideoProcAmp_Hue                   = %VideoProcAmp_Contrast              + 1
%VideoProcAmp_Saturation            = %VideoProcAmp_Hue                   + 1
%VideoProcAmp_Sharpness             = %VideoProcAmp_Saturation            + 1
%VideoProcAmp_Gamma                 = %VideoProcAmp_Sharpness             + 1
%VideoProcAmp_ColorEnable           = %VideoProcAmp_Gamma                 + 1
%VideoProcAmp_WhiteBalance          = %VideoProcAmp_ColorEnable           + 1
%VideoProcAmp_BacklightCompensation = %VideoProcAmp_WhiteBalance          + 1
%VideoProcAmp_Gain                  = %VideoProcAmp_BacklightCompensation + 1

' enum VideoProcAmpFlags
%VideoProcAmp_Flags_Auto            = &H1
%VideoProcAmp_Flags_Manual          = &H2


' ########################################################################################
' Interface name = IAMVideoProcAmp
' IID = {C6E13360-30AC-11D0-A18C-00A0C9118956}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IAMVideoProcAmp_INTERFACE_DEFINED)
    %IAMVideoProcAmp_INTERFACE_DEFINED = 1

$IID_IAMVideoProcAmp = GUID$("{C6E13360-30AC-11D0-A18C-00A0C9118956}")

INTERFACE IAMVideoProcAmp $IID_IAMVideoProcAmp

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetRange ( _                                  ' VTable offset = 12
     BYVAL Property AS LONG _                           ' __in  long Property
   , BYREF pMin AS LONG _                               ' __out long *pMin
   , BYREF pMax AS LONG _                               ' __out long *pMax
   , BYREF pSteppingDelta AS LONG _                     ' __out long *pSteppingDelta
   , BYREF pDefault AS LONG _                           ' __out long *pDefault
   , BYREF pCapsFlags AS LONG _                         ' __out long *pCapsFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Set ( _                                       ' VTable offset = 16
     BYVAL Property AS LONG _                           ' __in  long Property
   , BYVAL lValue AS LONG _                             ' __in  long lValue
   , BYVAL Flags AS LONG _                              ' __in  long Flags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Get ( _                                       ' VTable offset = 20
     BYVAL Property AS LONG _                           ' __in  long Property
   , BYREF lValue AS LONG _                             ' __out long *lValue
   , BYREF Flags AS LONG _                              ' __out long *Flags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAMVideoProcAmp_INTERFACE_DEFINED__*/


' enum CameraControlProperty
%CameraControl_Pan      = 0
%CameraControl_Tilt     = %CameraControl_Pan      + 1
%CameraControl_Roll     = %CameraControl_Tilt     + 1
%CameraControl_Zoom     = %CameraControl_Roll     + 1
%CameraControl_Exposure = %CameraControl_Zoom     + 1
%CameraControl_Iris     = %CameraControl_Exposure + 1
%CameraControl_Focus    = %CameraControl_Iris     + 1

' enum CameraControlFlags
%CameraControl_Flags_Auto   = &H1
%CameraControl_Flags_Manual = &H2


' ########################################################################################
' Interface name = IAMCameraControl
' IID = {C6E13370-30AC-11D0-A18C-00A0C9118956}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IAMCameraControl_INTERFACE_DEFINED)
    %IAMCameraControl_INTERFACE_DEFINED = 1

$IID_IAMCameraControl = GUID$("{C6E13370-30AC-11D0-A18C-00A0C9118956}")

INTERFACE IAMCameraControl $IID_IAMCameraControl

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetRange ( _                                  ' VTable offset = 12
     BYVAL Property AS LONG _                           ' __in  long Property
   , BYREF pMin AS LONG _                               ' __out long *pMin
   , BYREF pMax AS LONG _                               ' __out long *pMax
   , BYREF pSteppingDelta AS LONG _                     ' __out long *pSteppingDelta
   , BYREF pDefault AS LONG _                           ' __out long *pDefault
   , BYREF pCapsFlags AS LONG _                         ' __out long *pCapsFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Set ( _                                       ' VTable offset = 16
     BYVAL Property AS LONG _                           ' __in  long Property
   , BYVAL lValue AS LONG _                             ' __in  long lValue
   , BYVAL Flags AS LONG _                              ' __in  long Flags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Get ( _                                       ' VTable offset = 20
     BYVAL Property AS LONG _                           ' __in  long Property
   , BYREF lValue AS LONG _                             ' __out long *lValue
   , BYREF Flags AS LONG _                              ' __out long *Flags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAMCameraControl_INTERFACE_DEFINED__*/


' enum VideoControlFlags
%VideoControlFlag_FlipHorizontal        = &H1
%VideoControlFlag_FlipVertical          = &H2
%VideoControlFlag_ExternalTriggerEnable = &H4
%VideoControlFlag_Trigger               = &H8


' ########################################################################################
' Interface name = IAMVideoControl
' IID = {6A2E0670-28E4-11D0-A18C-00A0C9118956}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IAMVideoControl_INTERFACE_DEFINED)
    %IAMVideoControl_INTERFACE_DEFINED = 1

$IID_IAMVideoControl = GUID$("{6A2E0670-28E4-11D0-A18C-00A0C9118956}")

INTERFACE IAMVideoControl $IID_IAMVideoControl

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetCaps ( _                                   ' VTable offset = 12
     BYVAL pPin AS IPin _                               ' __in  IPin *pPin
   , BYREF pCapsFlags AS LONG _                         ' __out long *pCapsFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetMode ( _                                   ' VTable offset = 16
     BYVAL pPin AS IPin _                               ' __in  IPin *pPin
   , BYVAL Mode AS LONG _                               ' __in  long Mode
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMode ( _                                   ' VTable offset = 20
     BYVAL pPin AS IPin _                               ' __in  IPin *pPin
   , BYREF Mode AS LONG _                               ' __out long *Mode
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCurrentActualFrameRate ( _                 ' VTable offset = 24
     BYVAL pPin AS IPin _                               ' __in  IPin *pPin
   , BYREF ActualFrameRate AS QUAD _                    ' __out LONGLONG *ActualFrameRate
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMaxAvailableFrameRate ( _                  ' VTable offset = 28
     BYVAL pPin AS IPin _                               ' __in  IPin *pPin
   , BYVAL iIndex AS LONG _                             ' __in  long iIndex
   , BYREF Dimensions AS SIZE _                         ' __in  SIZE Dimensions
   , BYREF MaxAvailableFrameRate AS QUAD _              ' __out LONGLONG *MaxAvailableFrameRate
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFrameRateList ( _                          ' VTable offset = 32
     BYVAL pPin AS IPin _                               ' __in  IPin *pPin
   , BYVAL iIndex AS LONG _                             ' __in  long iIndex
   , BYREF Dimensions AS SIZE _                         ' __in  SIZE Dimensions
   , BYREF ListSize AS LONG _                           ' __out long *ListSize
   , BYREF FrameRates AS QUAD _                         ' __out LONGLONG **FrameRates
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAMVideoControl_INTERFACE_DEFINED__*/


' ########################################################################################
' Interface name = IAMCrossbar
' IID = {C6E13380-30AC-11D0-A18C-00A0C9118956}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IAMCrossbar_INTERFACE_DEFINED)
    %IAMCrossbar_INTERFACE_DEFINED = 1

$IID_IAMCrossbar = GUID$("{C6E13380-30AC-11D0-A18C-00A0C9118956}")

INTERFACE IAMCrossbar $IID_IAMCrossbar

   INHERIT IUnknown

   ' =====================================================================================
   METHOD get_PinCounts ( _                             ' VTable offset = 12
     BYREF OutputPinCount AS LONG _                     ' __out long *OutputPinCount
   , BYREF InputPinCount AS LONG _                      ' __out long *InputPinCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CanRoute ( _                                  ' VTable offset = 16
     BYVAL OutputPinCount AS LONG _                     ' __in  long OutputPinIndex
   , BYVAL InputPinIndex AS LONG _                      ' __in  long InputPinIndex
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Route ( _                                     ' VTable offset = 20
     BYVAL OutputPinCount AS LONG _                     ' __in  long OutputPinIndex
   , BYVAL InputPinIndex AS LONG _                      ' __in  long InputPinIndex
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_IsRoutedTo ( _                            ' VTable offset = 24
     BYVAL OutputPinCount AS LONG _                     ' __in  long OutputPinIndex
   , BYREF InputPinCount AS LONG _                      ' __out long *InputPinCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_CrossbarPinInfo ( _                       ' VTable offset = 28
     BYVAL IsInputPin AS LONG _                         ' __in  BOOL IsInputPin
   , BYVAL PinIndex AS LONG _                           ' __in  long PinIndex
   , BYREF PinIndexRelated AS LONG _                    ' __out long *PinIndexRelated
   , BYREF PhysicalType AS LONG _                       ' __out long *PhysicalType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAMCrossbar_INTERFACE_DEFINED__*/


' enum AMTunerSubChannel
%AMTUNER_SUBCHAN_NO_TUNE     = -2
%AMTUNER_SUBCHAN_DEFAULT     = -1

' enum AMTunerSignalStrength
%AMTUNER_HASNOSIGNALSTRENGTH = -1
%AMTUNER_NOSIGNAL            = 0
%AMTUNER_SIGNALPRESENT       = 1

' enum AMTunerModeType
%AMTUNER_MODE_DEFAULT        = 0
%AMTUNER_MODE_TV             = &H1
%AMTUNER_MODE_FM_RADIO       = &H2
%AMTUNER_MODE_AM_RADIO       = &H4
%AMTUNER_MODE_DSS            = &H8

' enum AMTunerEventType
%AMTUNER_EVENT_CHANGED       = &H1


' ########################################################################################
' Interface name = IAMTuner
' IID = {211A8761-03AC-11D1-8D13-00AA00BD8339}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IAMTuner_INTERFACE_DEFINED)
    %IAMTuner_INTERFACE_DEFINED = 1

$IID_IAMTuner = GUID$("{211A8761-03AC-11D1-8D13-00AA00BD8339}")

INTERFACE IAMTuner $IID_IAMTuner

   INHERIT IUnknown

   ' =====================================================================================
   METHOD put_Channel ( _                               ' VTable offset = 12
     BYVAL lChannel AS LONG _                           ' __in  long lChannel
   , BYVAL lVideoSubChannel AS LONG _                   ' __in  long lVideoSubChannel
   , BYVAL lAudioSubChannel AS LONG _                   ' __in  long lAudioSubChannel
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_Channel ( _                               ' VTable offset = 16
     BYREF plChannel AS LONG _                          ' __out long *plChannel
   , BYREF plVideoSubChannel AS LONG _                  ' __out long *plVideoSubChannel
   , BYREF plAudioSubChannel AS LONG _                  ' __out long *plAudioSubChannel
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ChannelMinMax ( _                             ' VTable offset = 20
     BYREF lChannelMin AS LONG _                        ' __out long *lChannelMin
   , BYREF lChannelMax AS LONG _                        ' __out long *lChannelMax
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_CountryCode ( _                           ' VTable offset = 24
     BYVAL lCountryCode AS LONG _                       ' __in  long lCountryCode
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_CountryCode ( _                           ' VTable offset = 28
     BYREF plCountryCode AS LONG _                      ' __out long *plCountryCode
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_TuningSpace ( _                           ' VTable offset = 32
     BYVAL lTuningSpace AS LONG _                       ' __in  long lTuningSpace
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_TuningSpace ( _                           ' VTable offset = 36
     BYREF plTuningSpace AS LONG _                      ' __out long *plTuningSpace
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Logon ( _                                     ' VTable offset = 40
     BYVAL hCurrentUser AS DWORD _                      ' __in  HANDLE hCurrentUser
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Logout ( _                                    ' VTable offset = 44
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SignalPresent ( _                             ' VTable offset = 48
     BYREF plSignalStrength AS LONG _                   ' __out long *plSignalStrength
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_Mode ( _                                  ' VTable offset = 52
     BYVAL lMode AS DWORD _                             ' __in  AMTunerModeType lMode
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_Mode ( _                                  ' VTable offset = 56
     BYREF plMode AS DWORD _                            ' __out AMTunerModeType *plMode
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAvailableModes ( _                         ' VTable offset = 60
     BYREF plModes AS LONG _                            ' __out long *plModes
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RegisterNotificationCallBack ( _              ' VTable offset = 64
     BYVAL pNotify AS IAMTunerNotification _            ' __in  IAMTunerNotification *pNotify
   , BYVAL lEvents AS LONG _                            ' __in  long lEvents
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UnRegisterNotificationCallBack ( _            ' VTable offset = 68
     BYVAL pNotify AS IAMTunerNotification _            ' __in  IAMTunerNotification *pNotify
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAMTuner_INTERFACE_DEFINED__*/


' ########################################################################################
' Interface name = IAMTunerNotification
' IID = {211A8760-03AC-11D1-8D13-00AA00BD8339}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IAMTunerNotification_INTERFACE_DEFINED)
    %IAMTunerNotification_INTERFACE_DEFINED = 1

$IID_IAMTunerNotification = GUID$("{211A8760-03AC-11D1-8D13-00AA00BD8339}")

INTERFACE IAMTunerNotification $IID_IAMTunerNotification

   INHERIT IUnknown

   ' =====================================================================================
   METHOD put_Channel ( _                               ' VTable offset = 12
     BYVAL Event AS DWORD _                             ' __in  AMTunerEventType Event
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAMTunerNotification_INTERFACE_DEFINED__*/


' ########################################################################################
' Interface name = IAMTVTuner
' IID = {211A8766-03AC-11D1-8D13-00AA00BD8339}
' Inherited interface = IAMTuner
' ########################################################################################

#IF NOT %DEF(%IAMTVTuner_INTERFACE_DEFINED)
    %IAMTVTuner_INTERFACE_DEFINED = 1

$IID_IAMTVTuner = GUID$("{211A8766-03AC-11D1-8D13-00AA00BD8339}")

INTERFACE IAMTVTuner $IID_IAMTVTuner

   INHERIT IUnknown

   ' =====================================================================================
   ' IAMTuner Methods
   ' =====================================================================================
   METHOD put_Channel ( _                               ' VTable offset = 12
     BYVAL lChannel AS LONG _                           ' __in  long lChannel
   , BYVAL lVideoSubChannel AS LONG _                   ' __in  long lVideoSubChannel
   , BYVAL lAudioSubChannel AS LONG _                   ' __in  long lAudioSubChannel
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_Channel ( _                               ' VTable offset = 16
     BYREF plChannel AS LONG _                          ' __out long *plChannel
   , BYREF plVideoSubChannel AS LONG _                  ' __out long *plVideoSubChannel
   , BYREF plAudioSubChannel AS LONG _                  ' __out long *plAudioSubChannel
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ChannelMinMax ( _                             ' VTable offset = 20
     BYREF lChannelMin AS LONG _                        ' __out long *lChannelMin
   , BYREF lChannelMax AS LONG _                        ' __out long *lChannelMax
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_CountryCode ( _                           ' VTable offset = 24
     BYVAL lCountryCode AS LONG _                       ' __in  long lCountryCode
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_CountryCode ( _                           ' VTable offset = 28
     BYREF plCountryCode AS LONG _                      ' __out long *plCountryCode
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_TuningSpace ( _                           ' VTable offset = 32
     BYVAL lTuningSpace AS LONG _                       ' __in  long lTuningSpace
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_TuningSpace ( _                           ' VTable offset = 36
     BYREF plTuningSpace AS LONG _                      ' __out long *plTuningSpace
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Logon ( _                                     ' VTable offset = 40
     BYVAL hCurrentUser AS DWORD _                      ' __in  HANDLE hCurrentUser
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Logout ( _                                    ' VTable offset = 44
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SignalPresent ( _                             ' VTable offset = 48
     BYREF plSignalStrength AS LONG _                   ' __out long *plSignalStrength
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_Mode ( _                                  ' VTable offset = 52
     BYVAL lMode AS DWORD _                             ' __in  AMTunerModeType lMode
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_Mode ( _                                  ' VTable offset = 56
     BYREF plMode AS DWORD _                            ' __out AMTunerModeType *plMode
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAvailableModes ( _                         ' VTable offset = 60
     BYREF plModes AS LONG _                            ' __out long *plModes
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RegisterNotificationCallBack ( _              ' VTable offset = 64
     BYVAL pNotify AS IAMTunerNotification _            ' __in  IAMTunerNotification *pNotify
   , BYVAL lEvents AS LONG _                            ' __in  long lEvents
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UnRegisterNotificationCallBack ( _            ' VTable offset = 68
     BYVAL pNotify AS IAMTunerNotification _            ' __in  IAMTunerNotification *pNotify
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IAMTVTuner Methods
   ' =====================================================================================
   METHOD get_AvailableTVFormats ( _                    ' VTable offset = 72
     BYREF lAnalogVideoStandard AS LONG _               ' __out long *lAnalogVideoStandard
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_TVFormat ( _                              ' VTable offset = 76
     BYREF lAnalogVideoStandard AS LONG _               ' __out long *lAnalogVideoStandard
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AutoTune ( _                                  ' VTable offset = 80
     BYVAL lChannel AS LONG _                           ' __in  long lChannel
   , BYREF plFoundSignal AS LONG _                      ' __out long *plFoundSignal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD StoreAutoTune ( _                             ' VTable offset = 84
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_NumInputConnections ( _                   ' VTable offset = 88
     BYREF plNumInputConnections AS LONG _              ' __out long *plNumInputConnections
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_InputType ( _                             ' VTable offset = 92
     BYVAL lIndex AS LONG _                             ' __in  long lIndex
   , BYVAL InputType AS DWORD _                         ' __in  TunerInputType InputType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_InputType ( _                             ' VTable offset = 96
     BYVAL lIndex AS LONG _                             ' __in  long lIndex
   , BYREF pInputType AS DWORD _                        ' __out TunerInputType *pInputType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_ConnectInput ( _                          ' VTable offset = 100
     BYVAL lIndex AS LONG _                             ' __in  long lIndex
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_ConnectInput ( _                          ' VTable offset = 104
     BYREF plIndex AS LONG _                            ' __out long *plIndex
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_VideoFrequency ( _                        ' VTable offset = 108
     BYREF lFreq AS LONG _                              ' __out long *lFreq
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_AudioFrequency ( _                        ' VTable offset = 112
     BYREF lFreq AS LONG _                              ' __out long *lFreq
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAMTVTuner_INTERFACE_DEFINED__*/


' ########################################################################################
' Interface name = IBPCSatelliteTuner
' IID = {211A8765-03AC-11D1-8D13-00AA00BD8339}
' Inherited interface = IAMTuner
' ########################################################################################

#IF NOT %DEF(%IBPCSatelliteTuner_INTERFACE_DEFINED)
    %IBPCSatelliteTuner_INTERFACE_DEFINED = 1

$IID_IBPCSatelliteTuner = GUID$("{211A8765-03AC-11D1-8D13-00AA00BD8339}")

INTERFACE IBPCSatelliteTuner $IID_IBPCSatelliteTuner

   INHERIT IUnknown

   ' =====================================================================================
   ' IAMTuner Methods
   ' =====================================================================================
   METHOD put_Channel ( _                               ' VTable offset = 12
     BYVAL lChannel AS LONG _                           ' __in  long lChannel
   , BYVAL lVideoSubChannel AS LONG _                   ' __in  long lVideoSubChannel
   , BYVAL lAudioSubChannel AS LONG _                   ' __in  long lAudioSubChannel
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_Channel ( _                               ' VTable offset = 16
     BYREF plChannel AS LONG _                          ' __out long *plChannel
   , BYREF plVideoSubChannel AS LONG _                  ' __out long *plVideoSubChannel
   , BYREF plAudioSubChannel AS LONG _                  ' __out long *plAudioSubChannel
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ChannelMinMax ( _                             ' VTable offset = 20
     BYREF lChannelMin AS LONG _                        ' __out long *lChannelMin
   , BYREF lChannelMax AS LONG _                        ' __out long *lChannelMax
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_CountryCode ( _                           ' VTable offset = 24
     BYVAL lCountryCode AS LONG _                       ' __in  long lCountryCode
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_CountryCode ( _                           ' VTable offset = 28
     BYREF plCountryCode AS LONG _                      ' __out long *plCountryCode
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_TuningSpace ( _                           ' VTable offset = 32
     BYVAL lTuningSpace AS LONG _                       ' __in  long lTuningSpace
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_TuningSpace ( _                           ' VTable offset = 36
     BYREF plTuningSpace AS LONG _                      ' __out long *plTuningSpace
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Logon ( _                                     ' VTable offset = 40
     BYVAL hCurrentUser AS DWORD _                      ' __in  HANDLE hCurrentUser
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Logout ( _                                    ' VTable offset = 44
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SignalPresent ( _                             ' VTable offset = 48
     BYREF plSignalStrength AS LONG _                   ' __out long *plSignalStrength
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_Mode ( _                                  ' VTable offset = 52
     BYVAL lMode AS DWORD _                             ' __in  AMTunerModeType lMode
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_Mode ( _                                  ' VTable offset = 56
     BYREF plMode AS DWORD _                            ' __out AMTunerModeType *plMode
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAvailableModes ( _                         ' VTable offset = 60
     BYREF plModes AS LONG _                            ' __out long *plModes
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RegisterNotificationCallBack ( _              ' VTable offset = 64
     BYVAL pNotify AS IAMTunerNotification _            ' __in  IAMTunerNotification *pNotify
   , BYVAL lEvents AS LONG _                            ' __in  long lEvents
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UnRegisterNotificationCallBack ( _            ' VTable offset = 68
     BYVAL pNotify AS IAMTunerNotification _            ' __in  IAMTunerNotification *pNotify
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IBPCSatelliteTuner Methods
   ' =====================================================================================
   METHOD get_DefaultSubChannelTypes ( _                ' VTable offset = 72
     BYREF plDefaultVideoType AS LONG _                 ' __out long *plDefaultVideoType
   , BYREF plDefaultAudioType AS LONG _                 ' __out long *plDefaultAudioType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_DefaultSubChannelTypes ( _                ' VTable offset = 76
     BYVAL lDefaultVideoType AS LONG _                  ' __in  long lDefaultVideoType
   , BYVAL lDefaultAudioType AS LONG _                  ' __in  long lDefaultAudioType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsTapingPermitted ( _                         ' VTable offset = 80
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IBPCSatelliteTuner_INTERFACE_DEFINED__*/

' enum TVAudioMode
%AMTVAUDIO_MODE_MONO     = &H1
%AMTVAUDIO_MODE_STEREO   = &H2
%AMTVAUDIO_MODE_LANG_A   = &H10
%AMTVAUDIO_MODE_LANG_B   = &H20
%AMTVAUDIO_MODE_LANG_C   = &H40
%AMTVAUDIO_PRESET_STEREO = &H200
%AMTVAUDIO_PRESET_LANG_A = &H1000
%AMTVAUDIO_PRESET_LANG_B = &H2000
%AMTVAUDIO_PRESET_LANG_C = &H4000

' enum AMTVAudioEventType
%AMTVAUDIO_EVENT_CHANGED = &H1


' ########################################################################################
' Interface name = IAMTVAudio
' IID = {83EC1C30-23D1-11D1-99E6-00A0C9560266}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IAMTVAudio_INTERFACE_DEFINED)
    %IAMTVAudio_INTERFACE_DEFINED = 1

$IID_IAMTVAudio = GUID$("{83EC1C30-23D1-11D1-99E6-00A0C9560266}")

INTERFACE IAMTVAudio $IID_IAMTVAudio

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetHardwareSupportedTVAudioModes ( _          ' VTable offset = 12
     BYREF plModes AS LONG _                            ' __out long *plModes
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAvailableTVAudioModes ( _                  ' VTable offset = 16
     BYREF plModes AS LONG _                            ' __out long *plModes
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_TVAudioMode ( _                           ' VTable offset = 20
     BYREF plMode AS LONG _                             ' __out long *plMode
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_TVAudioMode ( _                           ' VTable offset = 24
     BYVAL lMode AS LONG _                              ' __in  long lMode
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RegisterNotificationCallBack ( _              ' VTable offset = 28
     BYVAL pNotify AS IAMTunerNotification _            ' __in  IAMTunerNotification *pNotify
   , BYVAL lEvents AS LONG _                            ' __in  long lEvents
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UnRegisterNotificationCallBack ( _            ' VTable offset = 32
     BYVAL pNotify AS IAMTunerNotification _            ' __in  IAMTunerNotification *pNotify
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAMTVAudio_INTERFACE_DEFINED__*/


' ########################################################################################
' Interface name = IAMTVAudioNotification
' IID = {83EC1C33-23D1-11D1-99E6-00A0C9560266}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IAMTVAudioNotification_INTERFACE_DEFINED)
    %IAMTVAudioNotification_INTERFACE_DEFINED = 1

$IID_IAMTVAudioNotification = GUID$("{83EC1C33-23D1-11D1-99E6-00A0C9560266}")

INTERFACE IAMTVAudioNotification $IID_IAMTVAudioNotification

   INHERIT IUnknown

   ' =====================================================================================
   METHOD OnEvent ( _                                   ' VTable offset = 12
     BYVAL Event AS DWORD _                             ' __in  AMTVAudioEventType Event
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAMTVAudioNotification_INTERFACE_DEFINED__*/


' ########################################################################################
' Interface name = IAMAnalogVideoEncoder
' IID = {C6E133B0-30AC-11D0-A18C-00A0C9118956}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IAMAnalogVideoEncoder_INTERFACE_DEFINED)
    %IAMAnalogVideoEncoder_INTERFACE_DEFINED = 1

$IID_IAMAnalogVideoEncoder = GUID$("{C6E133B0-30AC-11D0-A18C-00A0C9118956}")

INTERFACE IAMAnalogVideoEncoder $IID_IAMAnalogVideoEncoder

   INHERIT IUnknown

   ' =====================================================================================
   METHOD get_AvailableTVFormats ( _                    ' VTable offset = 12
     BYREF lAnalogVideoStandard AS LONG _               ' __out long *lAnalogVideoStandard
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_TVFormat ( _                              ' VTable offset = 16
     BYVAL lAnalogVideoStandard AS LONG _               ' __in  long lAnalogVideoStandard
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_TVFormat ( _                              ' VTable offset = 20
     BYREF plAnalogVideoStandard AS LONG _              ' __out long *plAnalogVideoStandard
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_CopyProtection ( _                        ' VTable offset = 24
     BYVAL lVideoCopyProtection AS LONG _               ' __in  long lVideoCopyProtection
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_CopyProtection ( _                        ' VTable offset = 28
     BYREF lVideoCopyProtection AS LONG _               ' __out long *lVideoCopyProtection
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_CCEnable ( _                              ' VTable offset = 32
     BYVAL lCCEnable AS LONG _                          ' __in  long lCCEnable
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_CCEnable ( _                              ' VTable offset = 36
     BYREF lCCEnable AS LONG _                          ' __out long *lCCEnable
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAMAnalogVideoEncoder_INTERFACE_DEFINED__*/

' enum AMPROPERTY_PIN
%AMPROPERTY_PIN_CATEGORY = 0
%AMPROPERTY_PIN_MEDIUM   = %AMPROPERTY_PIN_CATEGORY + 1

#IF NOT %DEF(%IKsPropertySet)
   %IKsPropertySet = 1

%KSPROPERTY_SUPPORT_GET  = 1
%KSPROPERTY_SUPPORT_SET  = 2

' ########################################################################################
' Interface name = IKsPropertySet
' IID = {31EFAC30-515C-11D0-A9AA-00AA0061BE93}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IKsPropertySet_INTERFACE_DEFINED)
    %IKsPropertySet_INTERFACE_DEFINED = 1

$IID_IKsPropertySet = GUID$("{31EFAC30-515C-11D0-A9AA-00AA0061BE93}")

INTERFACE IKsPropertySet $IID_IKsPropertySet

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Set ( _                                       ' VTable offset = 12
     BYREF guidPropSet AS GUID _                        ' __in  REFGUID guidPropSet
   , BYVAL dwPropID AS DWORD _                          ' __in  DWORD dwPropID
   , BYVAL pInstanceData AS DWORD _                     ' __in  LPVOID pInstanceData
   , BYVAL cbInstanceData AS DWORD _                    ' __in  DWORD cbInstanceData
   , BYVAL pPropData AS DWORD _                         ' __in  LPVOID pPropData
   , BYVAL cbPropData AS DWORD _                        ' __in  DWORD cbPropData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Get ( _                                       ' VTable offset = 16
     BYREF guidPropSet AS GUID _                        ' __in  REFGUID guidPropSet
   , BYVAL dwPropID AS DWORD _                          ' __in  DWORD dwPropID
   , BYVAL pInstanceData AS DWORD _                     ' __in  LPVOID pInstanceData
   , BYVAL cbInstanceData AS DWORD _                    ' __in  DWORD cbInstanceData
   , BYREF pPropData AS DWORD _                         ' __out LPVOID pPropData
   , BYVAL cbPropData AS DWORD _                        ' __in  DWORD cbPropData
   , BYREF pcbReturned AS DWORD _                       ' __out DWORD *pcbReturned
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD QuerySupported ( _                            ' VTable offset = 20
     BYREF guidPropSet AS GUID _                        ' __in  REFGUID guidPropSet
   , BYVAL dwPropID AS DWORD _                          ' __in  DWORD dwPropID
   , BYREF pTypeSupport AS DWORD _                      ' __out DWORD *pTypeSupport
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IKsPropertySet_INTERFACE_DEFINED__*/

#ENDIF   ' // _IKsPropertySet_


' ########################################################################################
' Interface name = IMediaPropertyBag
' IID = {6025A880-C0D5-11D0-BD4E-00A0C911CE86}
' Inherited interface = IPropertyBag
' ########################################################################################

#IF NOT %DEF(%IMediaPropertyBag_INTERFACE_DEFINED)
    %IMediaPropertyBag_INTERFACE_DEFINED = 1

$IID_IMediaPropertyBag = GUID$("{6025A880-C0D5-11D0-BD4E-00A0C911CE86}")

INTERFACE IMediaPropertyBag $IID_IMediaPropertyBag

   INHERIT IUnknown

   ' =====================================================================================
   ' IPropertyBag methods
   ' =====================================================================================
   METHOD Read ( _                                      ' VTable offset = 12
     BYREF pszPropName AS WSTRINGZ _                    ' __in LPCOLESTR pszPropName
   , BYREF pVar AS VARIANT _                            ' __in_out VARIANT *pVar
   , BYVAL pErrorLog AS IErrorLog _                     ' __in IErrorLog *pErrorLog
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Write ( _                                     ' VTable offset = 16
     BYREF pszPropName AS WSTRINGZ _                    ' __in LPCOLESTR pszPropName
   , BYREF pVar AS VARIANT _                            ' __in VARIANT *pVar
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IMediaPropertyBag Methods
   ' =====================================================================================
   METHOD EnumProperty ( _                              ' VTable offset = 24
     BYVAL iProperty AS DWORD _                         ' __in  ULONG iProperty
   , BYREF pvarPropertyName AS VARIANT _                ' __inout VARIANT *pvarPropertyName
   , BYREF pvarPropertyValue AS VARIANT _               ' __inout VARIANT *pvarPropertyValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMediaPropertyBag_INTERFACE_DEFINED__*/


' ########################################################################################
' Interface name = IPersistMediaPropertyBag
' IID = {5738E040-B67F-11D0-BD4D-00A0C911CE86}
' Inherited interface = IPersist
' ########################################################################################

#IF NOT %DEF(%IPersistMediaPropertyBag_INTERFACE_DEFINED)
    %IPersistMediaPropertyBag_INTERFACE_DEFINED = 1

$IID_IPersistMediaPropertyBag = GUID$("{5738E040-B67F-11D0-BD4D-00A0C911CE86}")

INTERFACE IPersistMediaPropertyBag $IID_IPersistMediaPropertyBag

   INHERIT IUnknown

   ' =====================================================================================
   ' IPersist Methods
   ' =====================================================================================
   METHOD GetClassID ( _                                ' VTable offset = 12
     BYREF GUID _                                       ' __out CLSID *pClassID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IPersistMediaPropertyBag Methods
   ' =====================================================================================
   METHOD InitNew ( _                                   ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Load ( _                                      ' VTable offset = 20
     BYVAL pPropBag AS IMediaPropertyBag _              ' __in  IMediaPropertyBag *pPropBag
   , BYVAL pErrorLog AS IErrorLog _                     ' __in  IErrorLog *pErrorLog
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Save ( _                                      ' VTable offset = 24
     BYVAL pPropBag AS IMediaPropertyBag _              ' __in  IMediaPropertyBag *pPropBag
   , BYVAL fClearDirty AS LONG _                        ' __in  BOOL fClearDirty
   , BYVAL fSaveAllProperties AS LONG _                 ' __in  BOOL fSaveAllProperties
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IPersistMediaPropertyBag_INTERFACE_DEFINED__*/


' ########################################################################################
' Interface name = IAMPhysicalPinInfo
' IID = {F938C991-3029-11CF-8C44-00AA006B6814}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IAMPhysicalPinInfo_INTERFACE_DEFINED)
    %IAMPhysicalPinInfo_INTERFACE_DEFINED = 1

$IID_IAMPhysicalPinInfo = GUID$("{F938C991-3029-11CF-8C44-00AA006B6814}")

INTERFACE IAMPhysicalPinInfo $IID_IAMPhysicalPinInfo

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetPhysicalType ( _                           ' VTable offset = 12
     BYREF pType AS LONG _                              ' __out long *pType
   , BYREF ppszType AS DWORD _                          ' __out LPOLESTR *ppszType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAMPhysicalPinInfo_INTERFACE_DEFINED__*/


' ########################################################################################
' Interface name = IAMExtDevice
' IID = {B5730A90-1A2C-11CF-8C23-00AA006B6814}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IAMExtDevice_INTERFACE_DEFINED)
    %IAMExtDevice_INTERFACE_DEFINED = 1

$IID_IAMExtDevice = GUID$("{B5730A90-1A2C-11CF-8C23-00AA006B6814}")

INTERFACE IAMExtDevice $IID_IAMExtDevice

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetCapability ( _                             ' VTable offset = 12
     BYVAL Capability AS LONG _                         ' __in  long Capability
   , BYREF pValue AS LONG _                             ' __out long *pValue
   , BYREF pdblValue AS DOUBLE _                        ' __out double *pdblValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_ExternalDeviceID ( _                      ' VTable offset = 16
     BYREF ppszData AS DWORD _                          ' __out LPOLESTR *ppszData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_ExternalDeviceVersion ( _                 ' VTable offset = 20
     BYREF ppszData AS DWORD _                          ' __out LPOLESTR *ppszData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_DevicePower ( _                           ' VTable offset = 24
     BYVAL PowerMode AS LONG _                          ' __in  long PowerMode
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_DevicePower ( _                           ' VTable offset = 28
     BYREF pPowerMode AS LONG _                         ' __out long *pPowerMode
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Calibrate ( _                                 ' VTable offset = 32
     BYVAL hEvent AS DWORD _                            ' __in  HEVENT hEvent
   , BYVAL Mode AS LONG _                               ' __in  long Mode
   , BYREF pStatus AS LONG _                            ' __out long *pStatus
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_DevicePort ( _                            ' VTable offset = 36
     BYVAL DevicePort AS LONG _                         ' __in  long DevicePort
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_DevicePort ( _                            ' VTable offset = 40
     BYREF pDevicePort AS LONG _                        ' __out long *pDevicePort
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAMExtDevice_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IAMExtTransport
' IID = {A03CD5F0-3045-11CF-8C44-00AA006B6814}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IAMExtTransport_INTERFACE_DEFINED)
    %IAMExtTransport_INTERFACE_DEFINED = 1

$IID_IAMExtTransport = GUID$("{A03CD5F0-3045-11CF-8C44-00AA006B6814}")

INTERFACE IAMExtTransport $IID_IAMExtTransport

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetCapability ( _                             ' VTable offset = 12
     BYVAL Capability AS LONG _                         ' __in  long Capability
   , BYREF pValue AS LONG _                             ' __out long *pValue
   , BYREF pdblValue AS DOUBLE _                        ' __out double *pdblValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_MediaState ( _                            ' VTable offset = 16
     BYVAL State AS LONG _                              ' __in  long State
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_MediaState ( _                            ' VTable offset = 20
     BYREF pState AS LONG _                             ' __out long *pState
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_LocalControl ( _                          ' VTable offset = 24
     BYVAL State AS LONG _                              ' __in  long State
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_LocalControl ( _                          ' VTable offset = 28
     BYREF pState AS LONG _                             ' __out long *pState
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetStatus ( _                                 ' VTable offset = 32
     BYVAL StatusItem AS LONG _                         ' __in  long StatusItem
   , BYREF pValue AS LONG _                             ' __out long *pValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTransportBasicParameters ( _               ' VTable offset = 36
     BYVAL Param AS LONG _                              ' __in  long Param
   , BYREF pValue AS LONG _                             ' __out long *pValue
   , BYREF ppszData AS DWORD _                          ' __out LPOLESTR *ppszData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetTransportBasicParameters ( _               ' VTable offset = 40
     BYVAL Param AS LONG _                              ' __in  long Param
   , BYVAL Value AS LONG _                              ' __in  long Value
   , BYREF pszData AS WSTRINGZ _                        ' __in  LPCOLESTR pszData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTransportVideoParameters ( _               ' VTable offset = 44
     BYVAl Param AS LONG _                              ' __in  long Param
   , BYREF pValue AS LONG _                             ' __out long *pValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetTransportVideoParameters ( _               ' VTable offset = 48
     BYVAl Param AS LONG _                              ' __in  long Param
   , BYVAL Value AS LONG _                              ' __in  long Value
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTransportAudioParameters ( _               ' VTable offset = 52
     BYVAl Param AS LONG _                              ' __in  long Param
   , BYREF pValue AS LONG _                             ' __out long *pValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetTransportAudioParameters ( _               ' VTable offset = 56
     BYVAl Param AS LONG _                              ' __in  long Param
   , BYVAL Value AS LONG _                              ' __in  long Value
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_Mode ( _                                  ' VTable offset = 60
     BYVAL Mode AS LONG _                               ' __in  long Mode
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_Mode ( _                                  ' VTable offset = 64
     BYREF pMode AS LONG _                              ' __out long *pMode
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_Rate ( _                                  ' VTable offset = 68
     BYVAL dblRate AS DOUBLE _                          ' __in  double dblRate
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_Rate ( _                                  ' VTable offset = 72
     BYREF pdblRate AS DOUBLE _                         ' __out double *pdblRate
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetChase ( _                                  ' VTable offset = 76
     BYREF pEnabled AS LONG _                           ' __out long *pEnabled
   , BYREF pOffset AS LONG _                            ' __out long *pOffset
   , BYREF phEvent AS DWORD _                           ' __out HEVENT *phEvent
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetChase ( _                                  ' VTable offset = 80
     BYVAL Enable AS LONG _                             ' __in  long Enable
   , BYVAL Offset AS LONG _                             ' __in  long Offset
   , BYVAL hEvent AS DWORD _                            ' __in  HEVENT hEvent
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetBump ( _                                   ' VTable offset = 84
     BYREF pSpeed AS LONG _                             ' __out long *pSpeed
   , BYREF pDuration AS LONG _                          ' __out long *pDuration
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetBump ( _                                   ' VTable offset = 88
     BYVAL Speed AS LONG _                              ' __in  long Speed
   , BYVAL Duration AS LONG _                           ' __in  long Duration
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_AntiClogControl ( _                       ' VTable offset = 92
     BYREF pEnabled AS LONG _                           ' __out long *pEnabled
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_AntiClogControl ( _                       ' VTable offset = 96
     BYVAL Enable AS LONG _                             ' __in  long Enable
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetEditPropertySet ( _                        ' VTable offset = 100
     BYVAL EditID AS LONG _                             ' __in  long EditID
   , BYREF pState AS LONG _                             ' __out long *pState
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetEditPropertySet ( _                        ' VTable offset = 104
     BYREF pEditID AS LONG _                            ' __inout long *pEditID
   , BYVAL State AS LONG _                              ' __in  long State
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetEditProperty ( _                           ' VTable offset = 108
     BYVAL EditID AS LONG _                             ' __in  long EditID
   , BYVAL Param AS LONG _                              ' __in  long Param
   , BYREF pValue AS LONG _                             ' __out long *pValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetEditProperty ( _                           ' VTable offset = 112
     BYVAL EditID AS LONG _                             ' __in  long EditID
   , BYVAL Param AS LONG _                              ' __in  long Param
   , BYVAL Value AS LONG _                              ' __in  long Value
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_EditStart ( _                             ' VTable offset = 116
     BYREF pValue AS LONG _                             ' __out long *pValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_EditStart ( _                             ' VTable offset = 120
     BYVAL Value AS LONG _                              ' __in  long Value
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAMExtTransport_INTERFACE_DEFINED__ */

#IF NOT %DEF(%TIMECODE_DEFINED)
%TIMECODE_DEFINED = 1

' // Size = 8 bytes
TYPE TIMECODE_STRUCT DWORD FILL
   wFrameRate  AS WORD
   wFrameFract AS WORD
   dwFrames    AS DWORD
END TYPE

' // Size = 8 bytes
UNION TIMECODE   ' Must be 8 bytes aligned
   TIMECODE_STRUCT
   qw AS QUAD
END UNION

#ENDIF

' // Size = 24 bytes
TYPE TIMECODE_SAMPLE   ' Must be 8 byte aligned
   qwTick   AS QUAD
   timecode AS TIMECODE
   dwUser   AS DWORD
   dwFlags  AS DWORD
END TYPE


' ########################################################################################
' Interface name = IAMTimecodeReader
' IID = {9B496CE1-811B-11CF-8C77-00AA006B6814}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IAMTimecodeReader_INTERFACE_DEFINED)
    %IAMTimecodeReader_INTERFACE_DEFINED = 1

$IID_IAMTimecodeReader = GUID$("{9B496CE1-811B-11CF-8C77-00AA006B6814}")

INTERFACE IAMTimecodeReader $IID_IAMTimecodeReader

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetTCRMode ( _                                ' VTable offset = 12
     BYVAL Param AS LONG _                              ' __in  long Param
   , BYREF pValue AS LONG _                             ' __out long *pValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetTCRMode ( _                                ' VTable offset = 16
     BYVAL Param AS LONG _                              ' __in  long Param
   , BYVAL Value AS LONG _                              ' __in  long Value
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_VITCLine ( _                              ' VTable offset = 20
     BYVAL Line AS LONG _                               ' __in  long Line
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_VITCLine ( _                              ' VTable offset = 24
     BYREF pLine AS LONG _                              ' __out long *pLine
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTimecode ( _                               ' VTable offset = 28
     BYREF pTimecodeSample AS TIMECODE_SAMPLE _         ' __out PTIMECODE_SAMPLE pTimecodeSample
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAMTimecodeReader_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IAMTimecodeGenerator
' IID = {9B496CE0-811B-11CF-8C77-00AA006B6814}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IAMTimecodeGenerator_INTERFACE_DEFINED)
    %IAMTimecodeGenerator_INTERFACE_DEFINED = 1

$IID_IAMTimecodeGenerator = GUID$("{9B496CE0-811B-11CF-8C77-00AA006B6814}")

INTERFACE IAMTimecodeGenerator $IID_IAMTimecodeGenerator

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetTCGMode ( _                                ' VTable offset = 12
     BYVAL Param AS LONG _                              ' __in  long Param
   , BYREF pValue AS LONG _                             ' __out long *pValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetTCGMode ( _                                ' VTable offset = 16
     BYVAL Param AS LONG _                              ' __in  long Param
   , BYVAL Value AS LONG _                              ' __in  long Value
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_VITCLine ( _                              ' VTable offset = 20
     BYVAL Line AS LONG _                               ' __in  long Line
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_VITCLine ( _                              ' VTable offset = 24
     BYREF pLine AS LONG _                              ' __out long *pLine
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetTimecode ( _                               ' VTable offset = 28
     BYREF pTimecodeSample AS TIMECODE_SAMPLE _         ' __in  PTIMECODE_SAMPLE pTimecodeSample
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTimecode ( _                               ' VTable offset = 32
     BYREF pTimecodeSample AS TIMECODE_SAMPLE _         ' __out PTIMECODE_SAMPLE pTimecodeSample
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAMTimecodeGenerator_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IAMTimecodeDisplay
' IID = {9B496CE2-811B-11CF-8C77-00AA006B6814}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IAMTimecodeDisplay_INTERFACE_DEFINED)
    %IAMTimecodeDisplay_INTERFACE_DEFINED = 1

$IID_IAMTimecodeDisplay = GUID$("{9B496CE2-811B-11CF-8C77-00AA006B6814}")

INTERFACE IAMTimecodeDisplay $IID_IAMTimecodeDisplay

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetTCDisplayEnable ( _                        ' VTable offset = 12
     BYREF pState AS LONG _                             ' __out long *pState
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetTCDisplayEnable ( _                        ' VTable offset = 16
     BYVAL State AS LONG _                              ' __in  long State
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTCDisplay ( _                              ' VTable offset = 20
     BYVAL Param AS LONG _                              ' __in  long Param
   , BYREF pValue AS LONG _                             ' __out long *pValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetTCDisplay ( _                              ' VTable offset = 24
     BYVAL Param AS LONG _                              ' __in  long Param
   , BYVAL Value AS LONG _                              ' __in  long Value
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAMTimecodeDisplay_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IAMDevMemoryAllocator
' IID = {C6545BF0-E76B-11D0-BD52-00A0C911CE86}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IAMDevMemoryAllocator_INTERFACE_DEFINED)
    %IAMDevMemoryAllocator_INTERFACE_DEFINED = 1

$IID_IAMDevMemoryAllocator = GUID$("{C6545BF0-E76B-11D0-BD52-00A0C911CE86}")

INTERFACE IAMDevMemoryAllocator $IID_IAMDevMemoryAllocator

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetInfo ( _                                   ' VTable offset = 12
     BYREF pdwcbTotalFree AS DWORD _                    ' __out DWORD *pdwcbTotalFree
   , BYREF pdwcbLargestFree AS DWORD _                  ' __out DWORD *pdwcbLargestFree
   , BYREF pdwcbTotalMemory AS DWORD _                  ' __out DWORD *pdwcbTotalMemory
   , BYREF pdwcbMinimumChunk AS DWORD _                 ' __out DWORD *pdwcbMinimumChunk
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CheckMemory ( _                               ' VTable offset = 16
     BYVAL pBuffer AS BYTE PTR _                        ' __in  const BYTE *pBuffer
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Alloc ( _                                     ' VTable offset = 20
     BYREF ppBuffer AS DWORD _                          ' __out BYTE **ppBuffer
   , BYREF pdwcbBuffer AS DWORD _                       ' __inout DWORD *pdwcbBuffer
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Free ( _                                      ' VTable offset = 24
     BYVAL pBuffer AS BYTE PTR _                        ' __in  BYTE *pBuffer
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDevMemoryObject ( _                        ' VTable offset = 24
     BYREF ppUnkInnner AS IUnknown _                    ' __out IUnknown **ppUnkInnner
   , BYVAL pUnkOuter AS IUnknown _                      ' __in  IUnknown *pUnkOuter
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAMDevMemoryAllocator_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IAMDevMemoryControl
' IID = {C6545BF1-E76B-11D0-BD52-00A0C911CE86}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IAMDevMemoryControl_INTERFACE_DEFINED)
    %IAMDevMemoryControl_INTERFACE_DEFINED = 1

$IID_IAMDevMemoryControl = GUID$("{C6545BF1-E76B-11D0-BD52-00A0C911CE86}")

INTERFACE IAMDevMemoryControl $IID_IAMDevMemoryControl

   INHERIT IUnknown

   ' =====================================================================================
   METHOD QueryWriteSync ( _                            ' VTable offset = 12
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD WriteSync ( _                                 ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDevId ( _                                  ' VTable offset = 20
     BYREF pdwDevId AS DWORD _                          ' __out DWORD *pdwDevId
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAMDevMemoryControl_INTERFACE_DEFINED__ */


' enum AMSTREAMSELECTINFOFLAGS
%AMSTREAMSELECTINFO_ENABLED     = &H1
%AMSTREAMSELECTINFO_EXCLUSIVE   = &H2

' enum AMSTREAMSELECTENABLEFLAGS
%AMSTREAMSELECTENABLE_ENABLE    = &H1
%AMSTREAMSELECTENABLE_ENABLEALL = &H2


' ########################################################################################
' Interface name = IAMStreamSelect
' IID = {C1960960-17F5-11D1-ABE1-00A0C905F375}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IAMStreamSelect_INTERFACE_DEFINED)
    %IAMStreamSelect_INTERFACE_DEFINED = 1

$IID_IAMStreamSelect = GUID$("{C1960960-17F5-11D1-ABE1-00A0C905F375}")

INTERFACE IAMStreamSelect $IID_IAMStreamSelect

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Count ( _                                     ' VTable offset = 12
     BYREF pcStreams AS DWORD _                         ' __out DWORD *pcStreams
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Info ( _                                      ' VTable offset = 16
     BYVAL lIndex AS LONG _                             ' __in  long lIndex
   , OPTIONAL BYREF ppmt AS AM_MEDIA_TYPE _             ' __out_opt AM_MEDIA_TYPE **ppmt
   , OPTIONAL BYREF pdwFlags AS DWORD _                 ' __out_opt DWORD *pdwFlags
   , OPTIONAL BYREF plcid AS LONG _                     ' __out_opt LCID *plcid
   , OPTIONAL BYREF pdwGroup AS DWORD _                 ' __out_opt DWORD *pdwGroup
   , OPTIONAL BYREF ppszName AS DWORD _                 ' __out_opt WCHAR **ppszName
   , OPTIONAL BYREF ppObject AS IUnknown _              ' __out_opt IUnknown **ppObject
   , OPTIONAL BYREF ppUnk AS IUnknown _                 ' __out_opt IUnknown **ppUnk
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Enable ( _                                    ' VTable offset = 20
     BYVAL lIndex AS LONG _                             ' __in  long lIndex
   , BYVAL dwFlags AS DWORD _                           ' __in  DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAMStreamSelect_INTERFACE_DEFINED__ */


' enum _AMRESCTL_RESERVEFLAGS
%AMRESCTL_RESERVEFLAGS_RESERVE   = 0
%AMRESCTL_RESERVEFLAGS_UNRESERVE = &H1


' ########################################################################################
' Interface name = IAMResourceControl
' IID = {8389D2D0-77D7-11D1-ABE6-00A0C905F375}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IAMResourceControl_INTERFACE_DEFINED)
    %IAMResourceControl_INTERFACE_DEFINED = 1

$IID_IAMResourceControl = GUID$("{8389D2D0-77D7-11D1-ABE6-00A0C905F375}")

INTERFACE IAMResourceControl $IID_IAMResourceControl

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Reserve ( _                                   ' VTable offset = 12
     BYVAL dwFlags AS DWORD _                           ' __in  DWORD dwFlags
   , BYVAL pvReserved AS DWORD _                        ' __in  PVOID pvReserved
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAMResourceControl_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IAMClockAdjust
' IID = {4D5466B0-A49C-11D1-ABE8-00A0C905F375}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IAMClockAdjust_INTERFACE_DEFINED)
    %IAMClockAdjust_INTERFACE_DEFINED = 1

$IID_IAMClockAdjust = GUID$("{4D5466B0-A49C-11D1-ABE8-00A0C905F375}")

INTERFACE IAMClockAdjust $IID_IAMClockAdjust

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetClockDelta ( _                             ' VTable offset = 12
     BYVAL rtDelta AS QUAD _                            ' __in  REFERENCE_TIME rtDelta
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAMClockAdjust_INTERFACE_DEFINED__ */


' enum _AM_FILTER_MISC_FLAGS
%AM_FILTER_MISC_FLAGS_IS_RENDERER = &H1
%AM_FILTER_MISC_FLAGS_IS_SOURCE   = &H2


' ########################################################################################
' Interface name = IAMFilterMiscFlags
' IID = {2DD74950-A890-11D1-ABE8-00A0C905F375}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IAMFilterMiscFlags_INTERFACE_DEFINED)
    %IAMFilterMiscFlags_INTERFACE_DEFINED = 1

$IID_IAMFilterMiscFlags = GUID$("{2DD74950-A890-11D1-ABE8-00A0C905F375}")

INTERFACE IAMFilterMiscFlags $IID_IAMFilterMiscFlags

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetMiscFlags ( _                              ' VTable offset = 12
     ) AS DWORD                                         ' ULONG
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAMFilterMiscFlags_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IDrawVideoImage
' IID = {48EFB120-AB49-11D2-AED2-00A0C995E8D5}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDrawVideoImage_INTERFACE_DEFINED)
    %IDrawVideoImage_INTERFACE_DEFINED = 1

$IID_IDrawVideoImage = GUID$("{48EFB120-AB49-11D2-AED2-00A0C995E8D5}")

INTERFACE IDrawVideoImage $IID_IDrawVideoImage

   INHERIT IUnknown

   ' =====================================================================================
   METHOD DrawVideoImageBegin ( _                       ' VTable offset = 12
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DrawVideoImageEnd ( _                         ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DrawVideoImageDraw ( _                        ' VTable offset = 20
     BYVAL hdc AS DWORD _                               ' __in  HDC hdc
   , BYREF lprcSrc AS RECT _                            ' __in  LPRECT lprcSrc
   , BYREF lprcDst AS RECT _                            ' __in  LPRECT lprcDst
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDrawVideoImage_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IDecimateVideoImage
' IID = {2E5EA3E0-E924-11D2-B6DA-00A0C995E8DF}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDecimateVideoImage_INTERFACE_DEFINED)
    %IDecimateVideoImage_INTERFACE_DEFINED = 1

$IID_IDecimateVideoImage = GUID$("{2E5EA3E0-E924-11D2-B6DA-00A0C995E8DF}")

INTERFACE IDecimateVideoImage $IID_IDecimateVideoImage

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetDecimationImageSize ( _                    ' VTable offset = 12
     BYVAL lWidth AS LONG _                             ' __in  long lWidth
   , BYVAL lHeight AS LONG _                            ' __in  long lHeight
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ResetDecimationImageSize ( _                  ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDecimateVideoImage_INTERFACE_DEFINED__ */


' enum DECIMATION_USAGE
%DECIMATION_LEGACY             = 0
%DECIMATION_USE_DECODER_ONLY   = %DECIMATION_LEGACY             + 1
%DECIMATION_USE_VIDEOPORT_ONLY = %DECIMATION_USE_DECODER_ONLY   + 1
%DECIMATION_USE_OVERLAY_ONLY   = %DECIMATION_USE_VIDEOPORT_ONLY + 1
%DECIMATION_DEFAULT            = %DECIMATION_USE_OVERLAY_ONLY   + 1


' ########################################################################################
' Interface name = IAMVideoDecimationProperties
' IID = {60D32930-13DA-11D3-9EC6-C4FCAEF5C7BE}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IAMVideoDecimationProperties_INTERFACE_DEFINED)
    %IAMVideoDecimationProperties_INTERFACE_DEFINED = 1

$IID_IAMVideoDecimationProperties = GUID$("{60D32930-13DA-11D3-9EC6-C4FCAEF5C7BE}")

INTERFACE IAMVideoDecimationProperties $IID_IAMVideoDecimationProperties

   INHERIT IUnknown

   ' =====================================================================================
   METHOD QueryDecimationUsage ( _                      ' VTable offset = 12
     BYREF lpUsage AS DWORD _                           ' __out DECIMATION_USAGE *lpUsage
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetDecimationUsage ( _                        ' VTable offset = 16
     BYVAL Usage AS DWORD _                             ' __in  DECIMATION_USAGE Usage
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAMVideoDecimationProperties_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IVideoFrameStep
' IID = {E46A9787-2B71-444D-A4B5-1FAB7B708D6A}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IVideoFrameStep_INTERFACE_DEFINED)
    %IVideoFrameStep_INTERFACE_DEFINED = 1

$IID_IVideoFrameStep = GUID$("{E46A9787-2B71-444D-A4B5-1FAB7B708D6A}")

INTERFACE IVideoFrameStep $IID_IVideoFrameStep

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Step ( _                                      ' VTable offset = 12
     BYVAL dwFrames AS DWORD _                          ' __in  DWORD dwFrames
   , OPTIONAL BYVAL pStepObject AS IUnknown _           ' __in  IUnknown *pStepObject
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CanStep ( _                                   ' VTable offset = 16
     BYVAL bMultiple AS LONG _                          ' __in  long bMultiple
   , OPTIONAL BYVAL pStepObject AS IUnknown _           ' __in  IUnknown *pStepObject
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CancelStep ( _                                ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IVideoFrameStep_INTERFACE_DEFINED__ */


' enum AM_PUSHSOURCE_FLAGS
%AM_PUSHSOURCECAPS_INTERNAL_RM      = &H1???
%AM_PUSHSOURCECAPS_NOT_LIVE         = &H2???
%AM_PUSHSOURCECAPS_PRIVATE_CLOCK    = &H4???
%AM_PUSHSOURCEREQS_USE_STREAM_CLOCK = &H10000???
%AM_PUSHSOURCEREQS_USE_CLOCK_CHAIN  = &H20000???


' ########################################################################################
' Interface name = IAMLatency
' IID = {62EA93BA-EC62-11D2-B770-00C04FB6BD3D}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IAMLatency_INTERFACE_DEFINED)
    %IAMLatency_INTERFACE_DEFINED = 1

$IID_IAMLatency = GUID$("{62EA93BA-EC62-11D2-B770-00C04FB6BD3D}")

INTERFACE IAMLatency $IID_IAMLatency

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetLatency ( _                                ' VTable offset = 12
     BYREF prtLatency AS QUAD _                         ' __in  REFERENCE_TIME *prtLatency
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAMLatency_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IAMPushSource
' IID = {F185FE76-E64E-11D2-B76E-00C04FB6BD3D}
' Inherited interface = IAMLatency
' ########################################################################################

#IF NOT %DEF(%IAMPushSource_INTERFACE_DEFINED)
    %IAMPushSource_INTERFACE_DEFINED = 1

$IID_IAMPushSource = GUID$("{F185FE76-E64E-11D2-B76E-00C04FB6BD3D}")

INTERFACE IAMPushSource $IID_IAMPushSource

   INHERIT IUnknown

   ' =====================================================================================
   ' IAMLatency Methods
   ' =====================================================================================
   METHOD GetLatency ( _                                ' VTable offset = 12
     BYREF prtLatency AS QUAD _                         ' __in  REFERENCE_TIME *prtLatency
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IAMPushSource Methods
   ' =====================================================================================
   METHOD GetPushSourceFlags ( _                        ' VTable offset = 16
     BYREF pFlags AS DWORD _                            ' __out ULONG *pFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPushSourceFlags ( _                        ' VTable offset = 20
     BYVAL Flags AS DWORD _                             ' __in  ULONG Flags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetStreamOffset ( _                           ' VTable offset = 24
     BYVAL rtOffset AS QUAD _                           ' __in  REFERENCE_TIME rtOffset
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetStreamOffset ( _                           ' VTable offset = 28
     BYREF prtOffset AS QUAD _                          ' __out REFERENCE_TIME *prtOffset
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMaxStreamOffset ( _                        ' VTable offset = 32
     BYREF prtMaxOffset AS QUAD _                       ' __out REFERENCE_TIME *prtMaxOffset
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetMaxStreamOffset ( _                        ' VTable offset = 37
     BYVAL rtMaxOffset AS QUAD _                        ' __in  REFERENCE_TIME rtMaxOffset
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAMPushSource_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IAMDeviceRemoval
' IID = {F90A6130-B658-11D2-AE49-0000F8754B99}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IAMDeviceRemoval_INTERFACE_DEFINED)
    %IAMDeviceRemoval_INTERFACE_DEFINED = 1

$IID_IAMDeviceRemoval = GUID$("{F90A6130-B658-11D2-AE49-0000F8754B99}")

INTERFACE IAMDeviceRemoval $IID_IAMDeviceRemoval

   INHERIT IUnknown

   ' =====================================================================================
   METHOD DeviceInfo ( _                                ' VTable offset = 12
     BYREF pclsidInterfaceClass AS GUID _               ' __out CLSID *pclsidInterfaceClass
   , BYREF pwszSymbolicLink AS DWORD _                  ' __out WCHAR **pwszSymbolicLink
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reassociate ( _                               ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Disassociate ( _                              ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAMDeviceRemoval_INTERFACE_DEFINED__ */

' // Size = 32 bytes
TYPE DVINFO DWORD
   dwDVAAuxSrc     AS DWORD
   dwDVAAuxCtl     AS DWORD
   dwDVAAuxSrc1    AS DWORD
   dwDVAAuxCtl1    AS DWORD
   dwDVVAuxSrc     AS DWORD
   dwDVVAuxCtl     AS DWORD
   dwDVReserved(1) AS DWORD
END TYPE

' enum DVENCODERRESOLUTION
%DVENCODERRESOLUTION_720x480 = 2012
%DVENCODERRESOLUTION_360x240 = 2013
%DVENCODERRESOLUTION_180x120 = 2014
%DVENCODERRESOLUTION_88x60   = 2015

' enum DVENCODERVIDEOFORMAT
%DVENCODERVIDEOFORMAT_NTSC   = 2000
%DVENCODERVIDEOFORMAT_PAL    = 2001

' enum DVENCODERFORMAT
%DVENCODERFORMAT_DVSD        = 2007
%DVENCODERFORMAT_DVHD        = 2008
%DVENCODERFORMAT_DVSL        = 2009


' ########################################################################################
' Interface name = IDVEnc
' IID = {D18E17A0-AACB-11D0-AFB0-00AA00B67A42}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDVEnc_INTERFACE_DEFINED)
    %IDVEnc_INTERFACE_DEFINED = 1

$IID_IDVEnc = GUID$("{D18E17A0-AACB-11D0-AFB0-00AA00B67A42}")

INTERFACE IDVEnc $IID_IDVEnc

   INHERIT IUnknown

   ' =====================================================================================
   METHOD get_IFormatResolution ( _                     ' VTable offset = 12
     BYREF VideoFormat AS LONG _                        ' __out int *VideoFormat
   , BYREF DVFormat AS DWORD _                          ' __out int *DVFormat
   , BYREF Resolution AS DWORD _                        ' __out int *Resolution
   , BYVAL fDVInfo AS BYTE _                            ' __in  BYTE fDVInfo
   , BYREF sDVInfo AS DVINFO _                          ' __out DVINFO *sDVInfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_IFormatResolution ( _                     ' VTable offset = 16
     BYVAL VideoFormat AS LONG _                        ' __in  int VideoFormat
   , BYVAL DVFormat AS DWORD _                          ' __in  int DVFormat
   , BYVAL Resolution AS DWORD _                        ' __in  int Resolution
   , BYVAL fDVInfo AS BYTE _                            ' __in  BYTE fDVInfo
   , BYREF sDVInfo AS DVINFO _                          ' __in  DVINFO *sDVInfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDVEnc_INTERFACE_DEFINED__ */


' enum DVDECODERRESOLUTION
%DVDECODERRESOLUTION_720x480 = 1000
%DVDECODERRESOLUTION_360x240 = 1001
%DVDECODERRESOLUTION_180x120 = 1002
%DVDECODERRESOLUTION_88x60   = 1003

' enum DVRESOLUTION
%DVRESOLUTION_FULL           = 1000
%DVRESOLUTION_HALF           = 1001
%DVRESOLUTION_QUARTER        = 1002
%DVRESOLUTION_DC             = 1003


' ########################################################################################
' Interface name = IIPDVDec
' IID = {B8E8BD60-0BFE-11D0-AF91-00AA00B67A42}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IIPDVDec_INTERFACE_DEFINED)
    %IIPDVDec_INTERFACE_DEFINED = 1

$IID_IIPDVDec = GUID$("{B8E8BD60-0BFE-11D0-AF91-00AA00B67A42}")

INTERFACE IIPDVDec $IID_IIPDVDec

   INHERIT IUnknown

   ' =====================================================================================
   METHOD get_IPDisplay ( _                             ' VTable offset = 12
     BYREF displayPix AS LONG _                         ' __out int *displayPix
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_IPDisplay ( _                             ' VTable offset = 16
     BYVAL displayPix AS LONG _                         ' __in  int displayPix
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IIPDVDec_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IDVRGB219
' IID = {58473A19-2BC8-4663-8012-25F81BABDDD1}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDVRGB219_INTERFACE_DEFINED)
    %IDVRGB219_INTERFACE_DEFINED = 1

$IID_IDVRGB219 = GUID$("{58473A19-2BC8-4663-8012-25F81BABDDD1}")

INTERFACE IDVRGB219 $IID_IDVRGB219

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetRGB219 ( _                                 ' VTable offset = 12
     BYVAL bState AS LONG _                             ' __in  BOOL bState
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDVRGB219_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IDVSplitter
' IID = {92A3A302-DA7C-4A1F-BA7E-1802BB5D2D02}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDVSplitter_INTERFACE_DEFINED)
    %IDVSplitter_INTERFACE_DEFINED = 1

$IID_IDVSplitter = GUID$("{92A3A302-DA7C-4A1F-BA7E-1802BB5D2D02}")

INTERFACE IDVSplitter $IID_IDVSplitter

   INHERIT IUnknown

   ' =====================================================================================
   METHOD DiscardAlternateVideoFrames ( _               ' VTable offset = 12
     BYVAL nDiscard AS LONG _                           ' __in  int nDiscard
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDVSplitter_INTERFACE_DEFINED__ */


' enum AM_AUDIO_RENDERER_STAT_PARAM
%AM_AUDREND_STAT_PARAM_BREAK_COUNT            = 1
%AM_AUDREND_STAT_PARAM_SLAVE_MODE             = %AM_AUDREND_STAT_PARAM_BREAK_COUNT            + 1
%AM_AUDREND_STAT_PARAM_SILENCE_DUR            = %AM_AUDREND_STAT_PARAM_SLAVE_MODE             + 1
%AM_AUDREND_STAT_PARAM_LAST_BUFFER_DUR        = %AM_AUDREND_STAT_PARAM_SILENCE_DUR            + 1
%AM_AUDREND_STAT_PARAM_DISCONTINUITIES        = %AM_AUDREND_STAT_PARAM_LAST_BUFFER_DUR        + 1
%AM_AUDREND_STAT_PARAM_SLAVE_RATE             = %AM_AUDREND_STAT_PARAM_DISCONTINUITIES        + 1
%AM_AUDREND_STAT_PARAM_SLAVE_DROPWRITE_DUR    = %AM_AUDREND_STAT_PARAM_SLAVE_RATE             + 1
%AM_AUDREND_STAT_PARAM_SLAVE_HIGHLOWERROR     = %AM_AUDREND_STAT_PARAM_SLAVE_DROPWRITE_DUR    + 1
%AM_AUDREND_STAT_PARAM_SLAVE_LASTHIGHLOWERROR = %AM_AUDREND_STAT_PARAM_SLAVE_HIGHLOWERROR     + 1
%AM_AUDREND_STAT_PARAM_SLAVE_ACCUMERROR       = %AM_AUDREND_STAT_PARAM_SLAVE_LASTHIGHLOWERROR + 1
%AM_AUDREND_STAT_PARAM_BUFFERFULLNESS         = %AM_AUDREND_STAT_PARAM_SLAVE_ACCUMERROR       + 1
%AM_AUDREND_STAT_PARAM_JITTER                 = %AM_AUDREND_STAT_PARAM_BUFFERFULLNESS         + 1


' ########################################################################################
' Interface name = IAMAudioRendererStats
' IID = {22320CB2-D41A-11D2-BF7C-D7CB9DF0BF93}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IAMAudioRendererStats_INTERFACE_DEFINED)
    %IAMAudioRendererStats_INTERFACE_DEFINED = 1

$IID_IAMAudioRendererStats = GUID$("{22320CB2-D41A-11D2-BF7C-D7CB9DF0BF93}")

INTERFACE IAMAudioRendererStats $IID_IAMAudioRendererStats

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetStatParam ( _                              ' VTable offset = 12
     BYVAL dwParam AS DWORD _                           ' __in  DWORD dwParam
   , BYREF pdwParam1 AS DWORD _                         ' __out DWORD *pdwParam1
   , BYREF pdwParam2 AS DWORD _                         ' __out DWORD *pdwParam2
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAMAudioRendererStats_INTERFACE_DEFINED__ */


' enum AM_INTF_SEARCH_FLAGS
%AM_INTF_SEARCH_INPUT_PIN  = &H1???
%AM_INTF_SEARCH_OUTPUT_PIN = &H2???
%AM_INTF_SEARCH_FILTER     = &H4???


' ########################################################################################
' Interface name = IAMGraphStreams
' IID = {632105FA-072E-11D3-8AF9-00C04FB6BD3D}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IAMGraphStreams_INTERFACE_DEFINED)
    %IAMGraphStreams_INTERFACE_DEFINED = 1

$IID_IAMGraphStreams = GUID$("{632105FA-072E-11D3-8AF9-00C04FB6BD3D}")

INTERFACE IAMGraphStreams $IID_IAMGraphStreams

   INHERIT IUnknown

   ' =====================================================================================
   METHOD FindUpstreamInterface ( _                     ' VTable offset = 12
     BYVAL pPin AS IPin _                               ' __in  IPin *pPin
   , BYREF riid AS GUID _                               ' __in  REFIID riid
   , BYREF ppvInterface AS IUnknown _                   ' __out void **ppvInterface
   , BYVAL dwFlags AS DWORD _                           ' __in  DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SyncUsingStreamOffset ( _                     ' VTable offset = 16
     BYVAL bUseStreamOffset AS LONG _                   ' __in  BOOL bUseStreamOffset
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetMaxGraphLatency ( _                        ' VTable offset = 20
     BYVAL rtMaxGraphLatency AS QUAD _                  ' __in  REFERENCE_TIME rtMaxGraphLatency
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAMGraphStreams_INTERFACE_DEFINED__ */


' enum AMOVERLAYFX
%AMOVERFX_NOFX            = 0
%AMOVERFX_MIRRORLEFTRIGHT = &H2
%AMOVERFX_MIRRORUPDOWN    = &H4
%AMOVERFX_DEINTERLACE     = &H8


' ########################################################################################
' Interface name = IAMOverlayFX
' IID = {62FAE250-7E65-4460-BFC9-6398B322073C}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IAMOverlayFX_INTERFACE_DEFINED)
    %IAMOverlayFX_INTERFACE_DEFINED = 1

$IID_IAMOverlayFX = GUID$("{62FAE250-7E65-4460-BFC9-6398B322073C}")

INTERFACE IAMOverlayFX $IID_IAMOverlayFX

   INHERIT IUnknown

   ' =====================================================================================
   METHOD QueryOverlayFXCaps ( _                        ' VTable offset = 12
     BYREF lpdwOverlayFXCaps AS DWORD _                 ' __out DWORD *lpdwOverlayFXCaps
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetOverlayFX ( _                              ' VTable offset = 16
     BYVAL dwOverlayFX AS DWORD _                       ' __in  DWORD dwOverlayFX
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetOverlayFX ( _                              ' VTable offset = 20
     BYREF lpdwOverlayFX AS DWORD _                     ' __out DWORD *lpdwOverlayFX
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAMOverlayFX_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IAMOpenProgress
' IID = {8E1C39A1-DE53-11CF-AA63-0080C744528D}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IAMOpenProgress_INTERFACE_DEFINED)
    %IAMOpenProgress_INTERFACE_DEFINED = 1

$IID_IAMOpenProgress = GUID$("{8E1C39A1-DE53-11CF-AA63-0080C744528D}")

INTERFACE IAMOpenProgress $IID_IAMOpenProgress

   INHERIT IUnknown

   ' =====================================================================================
   METHOD QueryProgress ( _                             ' VTable offset = 12
     BYREF pllTotal AS QUAD _                           ' __out LONGLONG *pllTotal
   , BYREF pllCurrent AS QUAD _                         ' __out LONGLONG *pllCurrent
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AbortOperation ( _                            ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAMOpenProgress_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IMpeg2Demultiplexer
' IID = {436EEE9C-264F-4242-90E1-4E330C107512}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMpeg2Demultiplexer_INTERFACE_DEFINED)
    %IMpeg2Demultiplexer_INTERFACE_DEFINED = 1

$IID_IMpeg2Demultiplexer = GUID$("{436EEE9C-264F-4242-90E1-4E330C107512}")

INTERFACE IMpeg2Demultiplexer $IID_IMpeg2Demultiplexer

   INHERIT IUnknown

   ' =====================================================================================
   METHOD CreateOutputPin ( _                           ' VTable offset = 12
     BYREF pMediaType AS AM_MEDIA_TYPE _                ' __in  AM_MEDIA_TYPE *pMediaType
   , BYREF pszPinName AS WSTRINGZ _                     ' __in  LPWSTR pszPinName
   , BYREF ppIPin AS IPin _                             ' __out IPin **ppIPin
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetOutputPinMediaType ( _                     ' VTable offset = 16
     BYREF pszPinName AS WSTRINGZ _                     ' __in  LPWSTR pszPinName
   , BYREF pMediaType AS AM_MEDIA_TYPE _                ' __in  AM_MEDIA_TYPE *pMediaType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DeleteOutputPin ( _                           ' VTable offset = 20
     BYREF pszPinName AS WSTRINGZ _                     ' __in  LPWSTR pszPinName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMpeg2Demultiplexer_INTERFACE_DEFINED__ */


%MPEG2_PROGRAM_STREAM_MAP           = &H00000000???
%MPEG2_PROGRAM_ELEMENTARY_STREAM    = &H00000001???
%MPEG2_PROGRAM_DIRECTORY_PES_PACKET = &H00000002???
%MPEG2_PROGRAM_PACK_HEADER          = &H00000003???
%MPEG2_PROGRAM_PES_STREAM           = &H00000004???
%MPEG2_PROGRAM_SYSTEM_HEADER        = &H00000005???
%SUBSTREAM_FILTER_VAL_NONE          = &H10000000???

' // Size = 16 bytes
TYPE STREAM_ID_MAP DWORD
   stream_id              AS DWORD
   dwMediaSampleContent   AS DWORD
   ulSubstreamFilterValue AS DWORD
   iDataOffset            AS LONG
END TYPE


' ########################################################################################
' Interface name = IEnumStreamIdMap
' IID = {945C1566-6202-46FC-96C7-D87F289C6534}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IEnumStreamIdMap_INTERFACE_DEFINED)
    %IEnumStreamIdMap_INTERFACE_DEFINED = 1

$IID_IEnumStreamIdMap = GUID$("{945C1566-6202-46FC-96C7-D87F289C6534}")

INTERFACE IEnumStreamIdMap $IID_IEnumStreamIdMap

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Next ( _                                      ' VTable offset = 12
     BYVAL cRequest AS DWORD _                          ' __in  ULONG cRequest
   , BYREF pStreamIdMap AS STREAM_ID_MAP _              ' __inout STREAM_ID_MAP *pStreamIdMap
   , OPTIONAL BYREF pcReceived AS DWORD _               ' __out_opt ULONG *pcReceived
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Skip ( _                                      ' VTable offset = 16
     BYVAL cRecords AS DWORD _                          ' __in  ULONG cRecords
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reset ( _                                     ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 24
     BYREF ppIEnumStreamIdMap AS IEnumStreamIdMap _     ' __out IEnumStreamIdMap **ppIEnumStreamIdMap
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEnumStreamIdMap_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IMPEG2StreamIdMap
' IID = {D0E04C47-25B8-4369-925A-362A01D95444}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMPEG2StreamIdMap_INTERFACE_DEFINED)
    %IMPEG2StreamIdMap_INTERFACE_DEFINED = 1

$IID_IMPEG2StreamIdMap = GUID$("{D0E04C47-25B8-4369-925A-362A01D95444}")

INTERFACE IMPEG2StreamIdMap $IID_IMPEG2StreamIdMap

   INHERIT IUnknown

   ' =====================================================================================
   METHOD MapStreamId ( _                               ' VTable offset = 12
     BYVAL ulStreamId AS DWORD _                        ' __in  ULONG ulStreamId
   , BYVAL MediaSampleContent AS DWORD _                ' __in  DWORD MediaSampleContent
   , BYVAL ulSubstreamFilterValue AS DWORD _            ' __in  ULONG ulSubstreamFilterValue
   , BYVAL iDataOffset AS LONG _                        ' __in  int iDataOffset
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UnmapStreamId ( _                             ' VTable offset = 16
     BYVAL culStreamId AS DWORD _                       ' __in  ULONG culStreamId
   , BYVAL pulStreamId AS DWORD _                       ' __in  ULONG *pulStreamId
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumStreamIdMap ( _                           ' VTable offset = 20
     BYREF ppIEnumStreamIdMap AS IEnumStreamIdMap _     ' __out IEnumStreamIdMap **ppIEnumStreamIdMap
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMPEG2StreamIdMap_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IRegisterServiceProvider
' IID = {7B3A2F01-0751-48DD-B556-004785171C54}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IRegisterServiceProvider_INTERFACE_DEFINED)
    %IRegisterServiceProvider_INTERFACE_DEFINED = 1

$IID_IRegisterServiceProvider = GUID$("{7B3A2F01-0751-48DD-B556-004785171C54}")

INTERFACE IRegisterServiceProvider $IID_IRegisterServiceProvider

   INHERIT IUnknown

   ' =====================================================================================
   METHOD RegisterService ( _                           ' VTable offset = 12
     BYREF guidService AS GUID _                        ' __in  REFGUID guidService
   , BYVAL pUnkObject AS IUnknown _                     ' __in  IUnknown *pUnkObject
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IRegisterServiceProvider_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IAMClockSlave
' IID = {9FD52741-176D-4b36-8F51-CA8F933223BE}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IAMClockSlave_INTERFACE_DEFINED)
    %IAMClockSlave_INTERFACE_DEFINED = 1

$IID_IAMClockSlave = GUID$("{9FD52741-176D-4b36-8F51-CA8F933223BE}")

INTERFACE IAMClockSlave $IID_IAMClockSlave

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetErrorTolerance ( _                         ' VTable offset = 12
     BYVAL dwTolerance AS DWORD _                       ' __in  DWORD dwTolerance
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetErrorTolerance ( _                         ' VTable offset = 16
      BYREF pdwTolerance AS DWORD _                     ' __out DWORD *pdwTolerance
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAMClockSlave_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IAMGraphBuilderCallback
' IID = {4995F511-9DDB-4F12-BD3B-F04611807B79}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IAMGraphBuilderCallback_INTERFACE_DEFINED)
    %IAMGraphBuilderCallback_INTERFACE_DEFINED = 1

$IID_IAMGraphBuilderCallback = GUID$("{4995F511-9DDB-4F12-BD3B-F04611807B79}")

INTERFACE IAMGraphBuilderCallback $IID_IAMGraphBuilderCallback

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SelectedFilter ( _                            ' VTable offset = 12
     BYVAL pMon AS IMoniker _                           ' __in  IMoniker *pMon
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreatedFilter ( _                             ' VTable offset = 16
     BYVAL pFil AS IBaseFilter _                        ' __in  IBaseFilter *pFil
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAMGraphBuilderCallback_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IAMFilterGraphCallback
' IID = {56A868FD-0AD4-11CE-B0A3-0020AF0BA770}
' Inherited interface = IUnknown
' The IAMFilterGraphCallback interface provides a callback mechanism during graph building.
' To use this interface, implement the interface in your application or client object.
' Query the Filter Graph Manager for the IObjectWithSite interface and call the
' IObjectWithSite::SetSite method with a pointer to your implementation of the interface.
' During graph building, if the Filter Graph Manager fails to render a pin, it calls the
' UnabletoRender method. The client can then take appropriate action, such as providing an
' error message for the user or registering a new filter.
' // Note: Because this interface was not defined as a proper interface it is
' //       supported under C++ only. Methods aren't stdcall.
' ########################################################################################

'#IF NOT %DEF(%IAMFilterGraphCallback)
'    %IAMFilterGraphCallback = 1

$IID_IAMFilterGraphCallback = GUID$("{56A868FD-0AD4-11CE-B0A3-0020AF0BA770}")

'INTERFACE IAMFilterGraphCallback $IID_IAMFilterGraphCallback

'   INHERIT IUnknown

'   ' =====================================================================================
'   METHOD UnableToRender ( _                            ' VTable offset = 12
'     BYVAL pPin AS IPin _                               ' __in  IPin *pPin
'   ) AS LONG                                            ' HRESULT
'   ' =====================================================================================

'END INTERFACE

'#ENDIF   ' // _IAMFilterGraphCallback_


' // Size = 32 bytes
TYPE CodecAPIEventData DWORD
   guid        AS GUID
   dataLength  AS DWORD
   reserved(2) AS DWORD
END TYPE


' ########################################################################################
' Interface name = ICodecAPI
' IID = {901DB4C7-31CE-41A2-85DC-8FA0BF41B8DA}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ICodecAPI_INTERFACE_DEFINED)
    %ICodecAPI_INTERFACE_DEFINED = 1

$IID_ICodecAPI = GUID$("{901DB4C7-31CE-41A2-85DC-8FA0BF41B8DA}")

INTERFACE ICodecAPI $IID_ICodecAPI

   INHERIT IUnknown

   ' =====================================================================================
   METHOD IsSupported ( _                               ' VTable offset = 12
     BYREF Api AS GUID _                                ' __in  const GUID *Api
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsModifiable ( _                              ' VTable offset = 16
     BYREF Api AS GUID _                                ' __in  const GUID *Api
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetParameterRange ( _                         ' VTable offset = 20
     BYREF Api AS GUID _                                ' __in  const GUID *Api
   , BYREF ValueMin AS VARIANT _                        ' __out VARIANT *ValueMin
   , BYREF ValueMax AS VARIANT _                        ' __out VARIANT *ValueMax
   , BYREF SteppingDelta AS VARIANT _                   ' __out VARIANT *SteppingDelta
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetParameterValues ( _                        ' VTable offset = 24
     BYREF Api AS GUID _                                ' __in  const GUID *Api
   , BYREF Values AS VARIANT _                          ' __out VARIANT **Values [array]
   , BYREF ValuesCount AS DWORD _                       ' __out ULONG *ValuesCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDefaultValue ( _                           ' VTable offset = 28
     BYREF Api AS GUID _                                ' __in  const GUID *Api
   , BYREF Value AS VARIANT _                           ' __out VARIANT *Value
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetValue ( _                                  ' VTable offset = 32
     BYREF Api AS GUID _                                ' __in  const GUID *Api
   , BYREF Value AS VARIANT _                           ' __out VARIANT *Value
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetValue ( _                                  ' VTable offset = 36
     BYREF Api AS GUID _                                ' __in  const GUID *Api
   , BYREF Value AS VARIANT _                           ' __in  VARIANT *Value
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RegisterForEvent ( _                          ' VTable offset = 40
     BYREF Api AS GUID _                                ' __in  const GUID *Api
   , BYVAL userData AS LONG _                           ' __in  LONG_PTR userData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UnregisterForEvent ( _                        ' VTable offset = 44
     BYREF Api AS GUID _                                ' __in  const GUID *Api
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetAllDefaults ( _                            ' VTable offset = 48
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetValueWithNotify ( _                        ' VTable offset = 52
     BYREF Api AS GUID _                                ' __in  const GUID *Api
   , BYREF Value AS VARIANT _                           ' __in  VARIANT *Value
   , BYREF ChangedParam AS GUID _                       ' __out GUID **ChangedParam
   , BYREF ChangedParamCount AS DWORD _                 ' __out ULONG *ChangedParamCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetAllDefaultsWithNotify ( _                  ' VTable offset = 56
     BYREF ChangedParam AS GUID _                       ' __out GUID **ChangedParam
   , BYREF ChangedParamCount AS DWORD _                 ' __out ULONG *ChangedParamCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAllSettings ( _                            ' VTable offset = 60
     BYVAL pStream AS IStream _                         ' __in  IStream *pStream
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetAllSettings ( _                            ' VTable offset = 64
     BYVAL pStream AS IStream _                         ' __in  IStream *pStream
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetAllSettingsWithNotify ( _                  ' VTable offset = 68
     BYVAL pStream AS IStream _                         ' __in  IStream *pStream
   , BYREF ChangedParam AS GUID _                       ' __out GUID **ChangedParam
   , BYREF ChangedParamCount AS DWORD _                 ' __out ULONG *ChangedParamCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICodecAPI_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IGetCapabilitiesKey
' IID = {A8809222-07BB-48EA-951C-33158100625B}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IGetCapabilitiesKey_INTERFACE_DEFINED)
    %IGetCapabilitiesKey_INTERFACE_DEFINED = 1

$IID_IGetCapabilitiesKey = GUID$("{A8809222-07BB-48EA-951C-33158100625B}")

INTERFACE IGetCapabilitiesKey $IID_IGetCapabilitiesKey

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetCapabilitiesKey ( _                        ' VTable offset = 12
     BYREF pHKey AS DWORD _                             ' __out HKEY *pHKey
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IGetCapabilitiesKey_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IEncoderAPI
' IID = {70423839-6ACC-4b23-B079-21DBF08156A5}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IEncoderAPI_INTERFACE_DEFINED)
    %IEncoderAPI_INTERFACE_DEFINED = 1

$IID_IEncoderAPI = GUID$("{70423839-6ACC-4b23-B079-21DBF08156A5}")

INTERFACE IEncoderAPI $IID_IEncoderAPI

   INHERIT IUnknown

   ' =====================================================================================
   METHOD IsSupported ( _                               ' VTable offset = 12
     BYREF Api AS GUID _                                ' __in  const GUID *Api
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsAvailable ( _                               ' VTable offset = 16
     BYREF Api AS GUID _                                ' __in  const GUID *Api
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetParameterRange ( _                         ' VTable offset = 20
     BYREF Api AS GUID _                                ' __in  const GUID *Api
   , BYREF ValueMin AS VARIANT _                        ' __out VARIANT *ValueMin
   , BYREF ValueMax AS VARIANT _                        ' __out VARIANT *ValueMax
   , BYREF SteppingDelta AS VARIANT _                   ' __out VARIANT *SteppingDelta
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetParameterValues ( _                        ' VTable offset = 24
     BYREF Api AS GUID _                                ' __in  const GUID *Api
   , BYREF Values AS VARIANT _                          ' __out VARIANT **Values
   , BYREF ValuesCount AS DWORD _                       ' __out ULONG *ValuesCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDefaultValue ( _                           ' VTable offset = 28
     BYREF Api AS GUID _                                ' __in  const GUID *Api
   , BYREF Value AS VARIANT _                           ' __out VARIANT *Value
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetValue ( _                                  ' VTable offset = 32
     BYREF Api AS GUID _                                ' __in  const GUID *Api
   , BYREF Value AS VARIANT _                           ' __out VARIANT *Value
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetValue ( _                                  ' VTable offset = 36
     BYREF Api AS GUID _                                ' __in  const GUID *Api
   , BYREF Value AS VARIANT _                           ' __out VARIANT *Value
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEncoderAPI_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IVideoEncoder
' IID = {02997C3B-8E1B-460E-9270-545E0DE9563E}
' Inherited interface = IEncoderAPI
' ########################################################################################

#IF NOT %DEF(%IVideoEncoder_INTERFACE_DEFINED)
    %IVideoEncoder_INTERFACE_DEFINED = 1

$IID_IVideoEncoder = GUID$("{02997C3B-8E1B-460E-9270-545E0DE9563E}")

INTERFACE IVideoEncoder $IID_IVideoEncoder

   INHERIT IUnknown

   ' =====================================================================================
   ' IEncoderAPI Methods
   ' =====================================================================================
   METHOD IsSupported ( _                               ' VTable offset = 12
     BYREF Api AS GUID _                                ' __in  const GUID *Api
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsAvailable ( _                               ' VTable offset = 16
     BYREF Api AS GUID _                                ' __in  const GUID *Api
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetParameterRange ( _                         ' VTable offset = 20
     BYREF Api AS GUID _                                ' __in  const GUID *Api
   , BYREF ValueMin AS VARIANT _                        ' __out VARIANT *ValueMin
   , BYREF ValueMax AS VARIANT _                        ' __out VARIANT *ValueMax
   , BYREF SteppingDelta AS VARIANT _                   ' __out VARIANT *SteppingDelta
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetParameterValues ( _                        ' VTable offset = 24
     BYREF Api AS GUID _                                ' __in  const GUID *Api
   , BYREF Values AS VARIANT _                          ' __out VARIANT **Values
   , BYREF ValuesCount AS DWORD _                       ' __out ULONG *ValuesCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDefaultValue ( _                           ' VTable offset = 28
     BYREF Api AS GUID _                                ' __in  const GUID *Api
   , BYREF Value AS VARIANT _                           ' __out VARIANT *Value
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetValue ( _                                  ' VTable offset = 32
     BYREF Api AS GUID _                                ' __in  const GUID *Api
   , BYREF Value AS VARIANT _                           ' __out VARIANT *Value
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetValue ( _                                  ' VTable offset = 36
     BYREF Api AS GUID _                                ' __in  const GUID *Api
   , BYREF Value AS VARIANT _                           ' __out VARIANT *Value
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IVideoEncoder_INTERFACE_DEFINED__ */


#IF NOT %DEF(%ENCODER_API_DEFINES)
    %ENCODER_API_DEFINES = 1
' enum VIDEOENCODER_BITRATE_MODE
%ConstantBitRate        = 0
%VariableBitRateAverage = %ConstantBitRate        + 1
%VariableBitRatePeak    = %VariableBitRateAverage + 1
#ENDIF   ' // __ENCODER_API_DEFINES__

%AM_GETDECODERCAP_QUERY_VMR_SUPPORT  = &H00000001???
%VMR_NOTSUPPORTED                    = &H00000000???
%VMR_SUPPORTED                       = &H00000001???
%AM_QUERY_DECODER_VMR_SUPPORT        = &H00000001???
%AM_QUERY_DECODER_DXVA_1_SUPPORT     = &H00000002???
%AM_QUERY_DECODER_DVD_SUPPORT        = &H00000003???
%AM_QUERY_DECODER_ATSC_SD_SUPPORT    = &H00000004???
%AM_QUERY_DECODER_ATSC_HD_SUPPORT    = &H00000005???
%AM_GETDECODERCAP_QUERY_VMR9_SUPPORT = &H00000006???
%DECODER_CAP_NOTSUPPORTED            = &H00000000???
%DECODER_CAP_SUPPORTED               = &H00000001???


' ########################################################################################
' Interface name = IAMDecoderCaps
' IID = {C0DFF467-D499-4986-972B-E1D9090FA941}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IAMDecoderCaps_INTERFACE_DEFINED)
    %IAMDecoderCaps_INTERFACE_DEFINED = 1

$IID_IAMDecoderCaps = GUID$("{C0DFF467-D499-4986-972B-E1D9090FA941}")

INTERFACE IAMDecoderCaps $IID_IAMDecoderCaps

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetDecoderCaps ( _                            ' VTable offset = 12
     BYVAL dwCapIndex AS DWORD _                        ' __in  DWORD dwCapIndex
   , BYREF lpdwCap AS DWORD _                           ' __out DWORD *lpdwCap
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAMDecoderCaps_INTERFACE_DEFINED__ */

' // Size = 256 bytes
TYPE AMCOPPSignature BYTE
   Signature(255) AS BYTE
END TYPE

' // Size = 4096 bytes
TYPE AMCOPPCommand BYTE
   macKDI            AS GUID
   guidCommandID     AS GUID
   dwSequence        AS DWORD
   cbSizeData        AS DWORD
   CommandData(4055) AS BYTE
END TYPE

' // Size = 4096 bytes
TYPE AMCOPPStatusInput BYTE
   rApp                AS GUID
   guidStatusRequestID AS GUID
   dwSequence          AS DWORD
   cbSizeData          AS DWORD
   StatusData(4055)    AS BYTE
END TYPE

' // Size = 4096 bytes
TYPE AMCOPPStatusOutput BYTE
   macKDI           AS GUID
   cbSizeData       AS DWORD
   COPPStatus(4075) AS BYTE
END TYPE

' ########################################################################################
' Interface name = IAMCertifiedOutputProtection
' IID = {6FEDED3E-0FF1-4901-A2F1-43F7012C8515}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IAMCertifiedOutputProtection_INTERFACE_DEFINED)
    %IAMCertifiedOutputProtection_INTERFACE_DEFINED = 1

$IID_IAMCertifiedOutputProtection = GUID$("{6FEDED3E-0FF1-4901-A2F1-43F7012C8515}")

INTERFACE IAMCertifiedOutputProtection $IID_IAMCertifiedOutputProtection

   INHERIT IUnknown

   ' =====================================================================================
   METHOD KeyExchange ( _                               ' VTable offset = 12
     BYREF pRandom AS GUID _                            ' __out GUID *pRandom
   , BYREF VarLenCertGH AS DWORD _                      ' __out BYTE **VarLenCertGH
   , BYREF pdwLengthCertGH AS DWORD _                   ' __out DWORD *pdwLengthCertGH
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SessionSequenceStart ( _                      ' VTable offset = 16
     BYREF pSig AS AMCOPPSignature _                    ' __in  AMCOPPSignature *pSig
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ProtectionCommand ( _                         ' VTable offset = 20
     BYREF cmd AS AMCOPPCommand _                       ' __in  const AMCOPPCommand *cmd
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ProtectionStatus ( _                          ' VTable offset = 24
     BYREF pStatusInput AS AMCOPPStatusInput _          ' __in  const AMCOPPStatusInput *pStatusInput
   , BYREF pStatusOutput AS AMCOPPStatusOutput _        ' __out AMCOPPStatusOutput *pStatusOutput
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAMCertifiedOutputProtection_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IAMAsyncReaderTimestampScaling
' IID = CF7B26FC-9A00-485B-8147-3E789D5E8F67
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IAMAsyncReaderTimestampScaling_INTERFACE_DEFINED)
    %IAMAsyncReaderTimestampScaling_INTERFACE_DEFINED = 1

$IID_IAMAsyncReaderTimestampScaling = GUID$("{CF7B26FC-9A00-485B-8147-3E789D5E8F67}")

INTERFACE IAMAsyncReaderTimestampScaling $IID_IAMAsyncReaderTimestampScaling

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetTimestampMode ( _                          ' VTable offset = 12
     BYREF pfRaw AS LONG _                              ' __out BOOL *pfRaw
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetTimestampMode ( _                          ' VTable offset = 16
     BYVAL fRaw AS LONG _                               ' __in BOOL fRaw
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAMAsyncReaderTimestampScaling_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IAMPluginControl
' IID = 0E26A181-F40C-4635-8786-976284B52981
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IAMPluginControl_INTERFACE_DEFINED)
    %IAMPluginControl_INTERFACE_DEFINED = 1

$IID_IAMPluginControl = GUID$("{0E26A181-F40C-4635-8786-976284B52981}")

INTERFACE IAMPluginControl $IID_IAMPluginControl

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetPreferredClsid ( _                         ' VTable offset = 12
     BYREF subType AS GUID _                            ' __in REFGUID subType
   , BYREF clsid AS GUID _                              ' __out CLSID *clsid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPreferredClsidByIndex ( _                  ' VTable offset = 16
     BYVAL index AS DWORD _                             ' __in DWORD index
   , BYREF subType AS GUID _                            ' __out GUID *subType
   , BYREF clsid AS GUID _                              ' __out CLSID *clsid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPreferredClsid ( _                         ' VTable offset = 20
     BYREF subType AS GUID _                            ' __in REFGUID subType
   , OPTIONAL BYREF clsid AS GUID _                     ' __in_opt const CLSID *clsid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsDisabled ( _                                ' VTable offset = 24
     BYREF clsid AS GUID _                              ' __in REFCLSID clsid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDisabledByIndex ( _                        ' VTable offset = 28
     BYVAL index AS DWORD _                             ' __in DWORD index
   , BYREF clsid AS GUID _                              ' __out CLSID *clsid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetDisabled ( _                               ' VTable offset = 32
     BYREF clsid AS GUID _                              ' __in REFCLSID clsid
   , BYVAL disabled AS LONG _                           ' __in BOOL disabled
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsLegacyDisabled ( _                          ' VTable offset = 36
     BYREF dllName AS WSTRINGZ _                        ' __in LPCWSTR dllName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAMPluginControl_INTERFACE_DEFINED__ */

' enum DVD_DOMAIN
%DVD_DOMAIN_FirstPlay         = 1
%DVD_DOMAIN_VideoManagerMenu  = %DVD_DOMAIN_FirstPlay         + 1
%DVD_DOMAIN_VideoTitleSetMenu = %DVD_DOMAIN_VideoManagerMenu  + 1
%DVD_DOMAIN_Title             = %DVD_DOMAIN_VideoTitleSetMenu + 1
%DVD_DOMAIN_Stop              = %DVD_DOMAIN_Title             + 1

' enum DVD_MENU_ID
%DVD_MENU_Title      = 2
%DVD_MENU_Root       = 3
%DVD_MENU_Subpicture = 4
%DVD_MENU_Audio      = 5
%DVD_MENU_Angle      = 6
%DVD_MENU_Chapter    = 7

' enum DVD_DISC_SIDE
%DVD_SIDE_A          = 1
%DVD_SIDE_B          = 2

' enum DVD_PREFERRED_DISPLAY_MODE
%DISPLAY_CONTENT_DEFAULT         = 0
%DISPLAY_16x9                    = 1
%DISPLAY_4x3_PANSCAN_PREFERRED   = 2
%DISPLAY_4x3_LETTERBOX_PREFERRED = 3

'typedef WORD DVD_REGISTER;
'typedef DVD_REGISTER GPRMARRAY[ 16 ];
'typedef DVD_REGISTER SPRMARRAY[ 24 ];

' // Size = 772 bytes
TYPE DVD_ATR BYTE
   ulCAT  AS DWORD          ' ULONG
   pbATRI AS STRING * 768   ' BYTE pbATRI[ 768 ]
END TYPE

'typedef BYTE DVD_VideoATR[ 2 ];
'typedef BYTE DVD_AudioATR[ 8 ];
'typedef BYTE DVD_SubpictureATR[ 6 ];

' enum DVD_FRAMERATE
%DVD_FPS_25        = 1
%DVD_FPS_30NonDrop = 3

' // Size = 4 bytes
TYPE DVD_TIMECODE DWORD
   Hours1        AS BIT * 4 IN DWORD  ' // Hours
   Hours10       AS BIT * 4           ' // Tens of Hours
   Minutes1      AS BIT * 4           ' // Minutes
   Minutes10     AS BIT * 4           ' // Tens of Minutes
   Seconds1      AS BIT * 4           ' // Seconds
   Seconds10     AS BIT * 4           ' // Tens of Seconds
   Frames1       AS BIT * 4           ' // Frames
   Frames10      AS BIT * 2           ' // Tens of Frames
   FrameRateCode AS BIT * 2           ' // use DVD_FRAMERATE to indicate frames/sec and drop/non-drop
END TYPE

' enum tagDVD_NavCmdType
%DVD_NavCmdType_Pre    = 1
%DVD_NavCmdType_Post   = 2
%DVD_NavCmdType_Cell   = 3
%DVD_NavCmdType_Button = 4

' enum DVD_TIMECODE_FLAGS
%DVD_TC_FLAG_25fps        = &H1
%DVD_TC_FLAG_30fps        = &H2
%DVD_TC_FLAG_DropFrame    = &H4
%DVD_TC_FLAG_Interpolated = &H8

' // Size = 4 bytes
TYPE DVD_HMSF_TIMECODE BYTE
   bHours   AS BYTE
   bMinutes AS BYTE
   bSeconds AS BYTE
   bFrames  AS BYTE
END TYPE

' // Size = 16 bytes
TYPE DVD_PLAYBACK_LOCATION2 DWORD
   TitleNum      AS DWORD
   ChapterNum    AS DWORD
   TimeCode      AS DVD_HMSF_TIMECODE
   TimeCodeFlags AS DWORD
END TYPE

' // Size = 12 bytes
TYPE DVD_PLAYBACK_LOCATION DWORD
   TitleNum   AS DWORD
   ChapterNum AS DWORD
   TimeCode   AS DWORD
END TYPE

'typedef DWORD VALID_UOP_SOMTHING_OR_OTHER;

' enum VALID_UOP_FLAG
%UOP_FLAG_Play_Title_Or_AtTime                   = &H1
%UOP_FLAG_Play_Chapter                           = &H2
%UOP_FLAG_Play_Title                             = &H4
%UOP_FLAG_Stop                                   = &H8
%UOP_FLAG_ReturnFromSubMenu                      = &H10
%UOP_FLAG_Play_Chapter_Or_AtTime                 = &H20
%UOP_FLAG_PlayPrev_Or_Replay_Chapter             = &H40
%UOP_FLAG_PlayNext_Chapter                       = &H80
%UOP_FLAG_Play_Forwards                          = &H100
%UOP_FLAG_Play_Backwards                         = &H200
%UOP_FLAG_ShowMenu_Title                         = &H400
%UOP_FLAG_ShowMenu_Root                          = &H800
%UOP_FLAG_ShowMenu_SubPic                        = &H1000
%UOP_FLAG_ShowMenu_Audio                         = &H2000
%UOP_FLAG_ShowMenu_Angle                         = &H4000
%UOP_FLAG_ShowMenu_Chapter                       = &H8000
%UOP_FLAG_Resume                                 = &H10000
%UOP_FLAG_Select_Or_Activate_Button              = &H20000
%UOP_FLAG_Still_Off                              = &H40000
%UOP_FLAG_Pause_On                               = &H80000
%UOP_FLAG_Select_Audio_Stream                    = &H100000
%UOP_FLAG_Select_SubPic_Stream                   = &H200000
%UOP_FLAG_Select_Angle                           = &H400000
%UOP_FLAG_Select_Karaoke_Audio_Presentation_Mode = &H800000
%UOP_FLAG_Select_Video_Mode_Preference           = &H1000000

' enum DVD_CMD_FLAGS
%DVD_CMD_FLAG_None              = 0
%DVD_CMD_FLAG_Flush             = &H1
%DVD_CMD_FLAG_SendEvents        = &H2
%DVD_CMD_FLAG_Block             = &H4
%DVD_CMD_FLAG_StartWhenRendered = &H8
%DVD_CMD_FLAG_EndAfterRendered  = &H10

' enum DVD_OPTION_FLAG
%DVD_ResetOnStop                     = 1
%DVD_NotifyParentalLevelChange       = 2
%DVD_HMSF_TimeCodeEvents             = 3
%DVD_AudioDuringFFwdRew              = 4
%DVD_EnableNonblockingAPIs           = 5
%DVD_CacheSizeInMB                   = 6
%DVD_EnablePortableBookmarks         = 7
%DVD_EnableExtendedCopyProtectErrors = 8
%DVD_NotifyPositionChange            = 9
%DVD_IncreaseOutputControl           = 10
%DVD_EnableStreaming                 = 11
%DVD_EnableESOutput                  = 12
%DVD_EnableTitleLength               = 13
%DVD_DisableStillThrottle            = 14
%DVD_EnableLoggingEvents             = 15
%DVD_MaxReadBurstInKB                = 16
%DVD_ReadBurstPeriodInMS             = 17

' enum DVD_RELATIVE_BUTTON
%DVD_Relative_Upper             = 1
%DVD_Relative_Lower             = 2
%DVD_Relative_Left              = 3
%DVD_Relative_Right             = 4

' enum DVD_PARENTAL_LEVEL
%DVD_PARENTAL_LEVEL_8           = &H8000
%DVD_PARENTAL_LEVEL_7           = &H4000
%DVD_PARENTAL_LEVEL_6           = &H2000
%DVD_PARENTAL_LEVEL_5           = &H1000
%DVD_PARENTAL_LEVEL_4           = &H800
%DVD_PARENTAL_LEVEL_3           = &H400
%DVD_PARENTAL_LEVEL_2           = &H200
%DVD_PARENTAL_LEVEL_1           = &H100

' enum DVD_AUDIO_LANG_EXT
%DVD_AUD_EXT_NotSpecified       = 0
%DVD_AUD_EXT_Captions           = 1
%DVD_AUD_EXT_VisuallyImpaired   = 2
%DVD_AUD_EXT_DirectorComments1  = 3
%DVD_AUD_EXT_DirectorComments2  = 4

' enum DVD_SUBPICTURE_LANG_EXT
%DVD_SP_EXT_NotSpecified              = 0
%DVD_SP_EXT_Caption_Normal            = 1
%DVD_SP_EXT_Caption_Big               = 2
%DVD_SP_EXT_Caption_Children          = 3
%DVD_SP_EXT_CC_Normal                 = 5
%DVD_SP_EXT_CC_Big                    = 6
%DVD_SP_EXT_CC_Children               = 7
%DVD_SP_EXT_Forced                    = 9
%DVD_SP_EXT_DirectorComments_Normal   = 13
%DVD_SP_EXT_DirectorComments_Big      = 14
%DVD_SP_EXT_DirectorComments_Children = 15

' enum DVD_AUDIO_APPMODE
%DVD_AudioMode_None     = 0
%DVD_AudioMode_Karaoke  = 1
%DVD_AudioMode_Surround = 2
%DVD_AudioMode_Other    = 3

' enum DVD_AUDIO_FORMAT
%DVD_AudioFormat_AC3       = 0
%DVD_AudioFormat_MPEG1     = 1
%DVD_AudioFormat_MPEG1_DRC = 2
%DVD_AudioFormat_MPEG2     = 3
%DVD_AudioFormat_MPEG2_DRC = 4
%DVD_AudioFormat_LPCM      = 5
%DVD_AudioFormat_DTS       = 6
%DVD_AudioFormat_SDDS      = 7
%DVD_AudioFormat_Other     = 8

' enum DVD_KARAOKE_DOWNMIX
%DVD_Mix_0to0 = &H1
%DVD_Mix_1to0 = &H2
%DVD_Mix_2to0 = &H4
%DVD_Mix_3to0 = &H8
%DVD_Mix_4to0 = &H10
%DVD_Mix_Lto0 = &H20
%DVD_Mix_Rto0 = &H40
%DVD_Mix_0to1 = &H100
%DVD_Mix_1to1 = &H200
%DVD_Mix_2to1 = &H400
%DVD_Mix_3to1 = &H800
%DVD_Mix_4to1 = &H1000
%DVD_Mix_Lto1 = &H2000
%DVD_Mix_Rto1 = &H4000

' // Size = 40 bytes
TYPE DVD_AudioAttributes DWORD FILL
   AppMode              AS LONG    ' DVD_AUDIO_APPMODE
   AppModeData          AS BYTE    ' BYTE
   AudioFormat          AS LONG    ' DVD_AUDIO_FORMAT
   Language             AS DWORD   ' LCID
   LanguageExtension    AS LONG    ' DVD_AUDIO_LANG_EXT
   fHasMultichannelInfo AS LONG    ' BOOL
   dwFrequency          AS DWORD   ' DWORD
   bQuantization        AS BYTE    ' BYTE
   bNumberOfChannels    AS BYTE    ' BYTE
   dwReserved(1)        AS DWORD   ' DWORD dwReserved[ 2 ]
END TYPE

' // Size = 20 bytes
TYPE DVD_MUA_MixingInfo DWORD
   fMixTo0              AS LONG    ' BOOL
   fMixTo1              AS LONG    ' BOOL
   fMix0InPhase         AS LONG    ' BOOL
   fMix1InPhase         AS LONG    ' BOOL
   dwSpeakerPosition    AS DWORD   ' DWORD
END TYPE

' // Size = 16 bytes
TYPE DVD_MUA_Coeff DWORD
   log2_alpha AS DOUBLE
   log2_beta  AS DOUBLE
END TYPE

' // Size = 288 bytes
TYPE DVD_MultichannelAudioAttributes BYTE
   Info(7)  AS DVD_MUA_MixingInfo
   Coeff(7) AS DVD_MUA_Coeff
END TYPE

' enum DVD_KARAOKE_CONTENTS
%DVD_Karaoke_GuideVocal1  = &H1
%DVD_Karaoke_GuideVocal2  = &H2
%DVD_Karaoke_GuideMelody1 = &H4
%DVD_Karaoke_GuideMelody2 = &H8
%DVD_Karaoke_GuideMelodyA = &H10
%DVD_Karaoke_GuideMelodyB = &H20
%DVD_Karaoke_SoundEffectA = &H40
%DVD_Karaoke_SoundEffectB = &H80

' enum DVD_KARAOKE_ASSIGNMENT
%DVD_Assignment_reserved0 = 0
%DVD_Assignment_reserved1 = 1
%DVD_Assignment_LR        = 2
%DVD_Assignment_LRM       = 3
%DVD_Assignment_LR1       = 4
%DVD_Assignment_LRM1      = 5
%DVD_Assignment_LR12      = 6
%DVD_Assignment_LRM12     = 7

' // Size = 32 bytes
TYPE DVD_KaraokeAttributes DWORD
   bVersion                         AS BYTE
   fMasterOfCeremoniesInGuideVocal1 AS LONG
   fDuet                            AS LONG
   ChannelAssignment                AS LONG
   wChannelContents(7)              AS WORD
END TYPE

' enum DVD_VIDEO_COMPRESSION
%DVD_VideoCompression_Other   = 0
%DVD_VideoCompression_MPEG1   = 1
%DVD_VideoCompression_MPEG2   = 2

' // Size = 52 bytes
TYPE DVD_VideoAttributes DWORD
   fPanscanPermitted    AS LONG
   fLetterboxPermitted  AS LONG
   ulAspectX            AS DWORD
   ulAspectY            AS DWORD
   ulFrameRate          AS DWORD
   ulFrameHeight        AS DWORD
   Compression          AS LONG
   fLine21Field1InGOP   AS LONG
   fLine21Field2InGOP   AS LONG
   ulSourceResolutionX  AS DWORD
   ulSourceResolutionY  AS DWORD
   fIsSourceLetterboxed AS LONG
   fIsFilmMode          AS LONG
END TYPE

' enum DVD_SUBPICTURE_TYPE
%DVD_SPType_NotSpecified = 0
%DVD_SPType_Language     = 1
%DVD_SPType_Other        = 2

' enum DVD_SUBPICTURE_CODING
%DVD_SPCoding_RunLength = 0
%DVD_SPCoding_Extended  = 1
%DVD_SPCoding_Other     = 2

' // Size = 16 bytes
TYPE DVD_SubpictureAttributes DWORD
   Type              AS LONG    ' DVD_SUBPICTURE_TYPE
   CodingMode        AS LONG    ' DVD_SUBPICTURE_CODING
   Language          AS DWORD   ' LCID
   LanguageExtension AS LONG    ' DVD_SUBPICTURE_LANG_EXT
END TYPE

' enum DVD_TITLE_APPMODE
%DVD_AppMode_Not_Specified = 0
%DVD_AppMode_Karaoke       = 1
%VD_AppMode_Other          = 3

' // Size = 4 bytes
UNION DVD_TitleAttributes_UNION
   AppMode AS LONG   ' DVD_TITLE_APPMODE
   TitleLength AS DVD_HMSF_TIMECODE
END UNION

' // Size = 3208 bytes
TYPE DVD_TitleAttributes QWORD FILL
   DVD_TitleAttributes_UNION
   VideoAttributes                AS DVD_VideoAttributes
   ulNumberOfAudioStreams         AS DWORD
   AudioAttributes(7)             AS DVD_AudioAttributes
   MultichannelAudioAttributes(7) AS DVD_MultichannelAudioAttributes
   ulNumberOfSubpictureStreams    AS DWORD
   SubpictureAttributes(31)       AS DVD_SubpictureAttributes
END TYPE

' // Size = 148 bytes
TYPE DVD_MenuAttributes DWORD
   fCompatibleRegion(7) AS LONG
   VideoAttributes      AS DVD_VideoAttributes
   fAudioPresent        AS LONG
   AudioAttributes      AS DVD_AudioAttributes
   fSubpicturePresent   AS LONG
   SubpictureAttributes AS DVD_SubpictureAttributes
END TYPE


' ########################################################################################
' Interface name = IDvdControl
' IID = {A70EFE61-E2A3-11D0-A9BE-00AA0061BE93}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDvdControl_INTERFACE_DEFINED)
    %IDvdControl_INTERFACE_DEFINED = 1

$IID_IDvdControl = GUID$("{A70EFE61-E2A3-11D0-A9BE-00AA0061BE93}")

INTERFACE IDvdControl $IID_IDvdControl

   INHERIT IUnknown

   ' =====================================================================================
   METHOD TitlePlay ( _                                 ' VTable offset = 12
     BYVAL ulTitle AS DWORD _                           ' __in  ULONG ulTitle
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ChapterPlay ( _                               ' VTable offset = 16
     BYVAL ulTitle AS DWORD _                           ' __in  ULONG ulTitle
   , BYVAL ulChapter AS DWORD _                         ' __in  ULONG ulChapter
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD TimePlay ( _                                  ' VTable offset = 20
     BYVAL ulTitle AS DWORD _                           ' __in  ULONG ulTitle
   , BYVAL bcdTime AS DWORD _                           ' __in  ULONG bcdTime
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD StopForResume ( _                             ' VTable offset = 24
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GoUp ( _                                      ' VTable offset = 28
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD TimeSearch ( _                                ' VTable offset = 32
     BYVAL bcdTime AS DWORD _                           ' __in  ULONG bcdTime
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ChapterSearch ( _                             ' VTable offset = 36
     BYVAL ulChapter AS DWORD _                         ' __in  ULONG ulChapter
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD PrevPGSearch ( _                              ' VTable offset = 40
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD TopPGSearch ( _                               ' VTable offset = 44
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD NextPGSearch ( _                              ' VTable offset = 48
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ForwardScan ( _                               ' VTable offset = 52
     BYVAL dwSpeed AS DOUBLE _                          ' __in  double dwSpeed
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD BackwardScan ( _                              ' VTable offset = 56
     BYVAL dwSpeed AS DOUBLE _                          ' __in  double dwSpeed
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD MenuCall ( _                                  ' VTable offset = 60
     BYVAL MenuID AS LONG _                             ' __in  DVD_MENU_ID MenuID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Resume ( _                                    ' VTable offset = 64
     BYVAL MenuID AS LONG _                             ' __in  DVD_MENU_ID MenuID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UpperButtonSelect ( _                         ' VTable offset = 68
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD LowerButtonSelect ( _                         ' VTable offset = 72
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD LeftButtonSelect ( _                          ' VTable offset = 76
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RightButtonSelect ( _                         ' VTable offset = 80
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ButtonActivate ( _                            ' VTable offset = 84
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ButtonSelectAndActivate ( _                   ' VTable offset = 88
     BYVAL ulButton AS DWORD _                          ' __in  ULONG ulButton
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD StillOff ( _                                  ' VTable offset = 92
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD PauseOn ( _                                   ' VTable offset = 96
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD PauseOff ( _                                  ' VTable offset = 100
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD MenuLanguageSelect ( _                        ' VTable offset = 104
     BYVAL Language AS DWORD _                          ' __in  LCID Language
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AudioStreamChange ( _                         ' VTable offset = 108
     BYVAL ulAudio AS DWORD _                           ' __in  ULONG ulAudio
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SubpictureStreamChange ( _                    ' VTable offset = 112
     BYVAL ulSubPicture AS DWORD _                      ' __in  ULONG ulSubPicture
   , BYVAL bDisplay AS LONG _                           ' __in  BOOL bDisplay
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AngleChange ( _                               ' VTable offset = 116
     BYVAL ulAngle AS DWORD _                           ' __in  ULONG ulAngle
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ParentalLevelSelect ( _                       ' VTable offset = 120
     BYVAL ulParentalLevel AS DWORD _                   ' __in  ULONG ulParentalLevel
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ParentalCountrySelect ( _                     ' VTable offset = 124
     BYVAL wCountry AS WORD _                           ' __in  WORD wCountry
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD KaraokeAudioPresentationModeChange ( _        ' VTable offset = 128
     BYVAL ulMode AS DWORD _                            ' __in  ULONG ulMode
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD VideoModePreferrence ( _                      ' VTable offset = 132
     BYVAL ulPreferredDisplayMode AS DWORD _            ' __in  ULONG ulPreferredDisplayMode
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetRoot ( _                                   ' VTable offset = 136
     BYREF pszPath AS WSTRINGZ _                        ' __in  LPCWSTR pszPath
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD MouseActivate ( _                             ' VTable offset = 140
     BYREF point AS POINT _                             ' __in  POINT point
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD MouseSelect ( _                               ' VTable offset = 144
     BYREF point AS POINT _                             ' __in  POINT point
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ChapterPlayAutoStop ( _                       ' VTable offset = 148
     BYVAL ulTitle AS DWORD _                           ' __in  ULONG ulTitle
   , BYVAL ulChapter AS DWORD _                         ' __in  ULONG ulChapter
   , BYVAL ulChaptersToPlay AS DWORD _                  ' __in  ULONG ulChaptersToPlay
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDvdControl_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IDvdInfo
' IID = {A70EFE60-E2A3-11D0-A9BE-00AA0061BE93}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDvdInfo_INTERFACE_DEFINED)
    %IDvdInfo_INTERFACE_DEFINED = 1

$IID_IDvdInfo = GUID$("{A70EFE60-E2A3-11D0-A9BE-00AA0061BE93}")

INTERFACE IDvdInfo $IID_IDvdInfo

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetCurrentDomain ( _                          ' VTable offset = 12
     BYREF pDomain AS LONG _                            ' __out DVD_DOMAIN *pDomain
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCurrentLocation ( _                        ' VTable offset = 16
     BYREF pLocation AS DVD_PLAYBACK_LOCATION _         ' __out DVD_PLAYBACK_LOCATION *pLocation
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTotalTitleTime ( _                         ' VTable offset = 20
     BYREF pulTotalTime AS DWORD _                      ' __out ULONG *pulTotalTime
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCurrentButton ( _                          ' VTable offset = 24
     BYREF pulButtonsAvailable AS DWORD _               ' __out ULONG *pulButtonsAvailable
   , BYREF pulCurrentButton AS DWORD _                  ' __out ULONG *pulCurrentButton
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCurrentAngle ( _                           ' VTable offset = 28
     BYREF pulAnglesAvailable AS DWORD _                ' __out ULONG *pulAnglesAvailable
   , BYREF pulCurrentAngle AS DWORD _                   ' __out ULONG *pulCurrentAngle
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCurrentAudio ( _                           ' VTable offset = 32
     BYREF pulAnglesAvailable AS DWORD _                ' __out ULONG *pulStreamsAvailable
   , BYREF pulCurrentStream AS DWORD _                  ' __out ULONG *pulCurrentStream
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCurrentSubpicture ( _                      ' VTable offset = 36
     BYREF pulAnglesAvailable AS DWORD _                ' __out ULONG *pulStreamsAvailable
   , BYREF pulCurrentStream AS DWORD _                  ' __out ULONG *pulCurrentStream
   , BYREF pIsDisabled AS LONG _                        ' __out BOOL *pIsDisabled
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCurrentUOPS ( _                            ' VTable offset = 40
     BYREF pUOP AS DWORD _                              ' __out VALID_UOP_SOMTHING_OR_OTHER *pUOP
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAllSPRMs ( _                               ' VTable offset = 44
     BYREF pRegisterArray AS DWORD _                    ' __out SPRMARRAY *pRegisterArray [Array of 24 words]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAllGPRMs ( _                               ' VTable offset = 48
     BYREFpRegisterArray As  DWORD _                    ' __out GPRMARRAY *pRegisterArray [Array of 16 words]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAudioLanguage ( _                          ' VTable offset = 52
     BYVAL ulStream AS DWORD _                          ' __in  ULONG ulStream
   , BYREF pLanguage AS DWORD _                         ' __out LCID *pLanguage
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSubpictureLanguage ( _                     ' VTable offset = 56
     BYVAL ulStream AS DWORD _                          ' __in  ULONG ulStream
   , BYREF pLanguage AS DWORD _                         ' __out LCID *pLanguage
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTitleAttributes ( _                        ' VTable offset = 60
     BYVAL ulTitle AS DWORD _                           ' __in  ULONG ulTitle
   , BYREF pATR AS DVD_ATR _                            ' __out DVD_ATR *pATR
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetVMGAttributes ( _                          ' VTable offset = 64
     BYREF pATR AS DVD_ATR _                            ' __out DVD_ATR *pATR
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCurrentVideoAttributes ( _                 ' VTable offset = 68
     BYREF pATR AS DVD_VideoAttributes _                ' __out DVD_VideoAttributes *pATR
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCurrentAudioAttributes ( _                 ' VTable offset = 72
     BYREF pATR AS BYTE _                               ' __out DVD_AudioATR *pATR [Array of 8 bytes]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCurrentSubpictureAttributes ( _            ' VTable offset = 76
     BYREF pATR AS BYTE _                               ' __out DVD_SubpictureATR *pATR [Array of 6 bytes]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCurrentVolumeInfo ( _                      ' VTable offset = 80
     BYREF pulNumOfVol AS DWORD _                       ' __out ULONG *pulNumOfVol
   , BYREF pulThisVolNum AS DWORD _                     ' __out ULONG *pulThisVolNum
   , BYREF pSide AS LONG _                              ' __out DVD_DISC_SIDE *pSide
   , BYREF pulNumOfTitles AS DWORD _                    ' __out ULONG *pulNumOfTitles
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDVDTextInfo ( _                            ' VTable offset = 84
     BYVAL pTextManager AS BYTE PTR _                   ' __out BYTE *pTextManager
   , BYVAL ulBufSize AS DWORD _                         ' __in  ULONG ulBufSize
   , BYREF pulActualSize AS DWORD _                     ' __out ULONG *pulActualSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPlayerParentalLevel ( _                    ' VTable offset = 88
     BYREF pulParentalLevel AS DWORD _                  ' __out ULONG *pulParentalLevel
   , BYREF pulCountryCode AS DWORD _                    ' __out ULONG *pulCountryCode
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetNumberOfChapters ( _                       ' VTable offset = 92
     BYVAL ulTitle AS DWORD _                           ' __in  ULONG ulTitle
   , BYREF pulNumberOfChapters AS DWORD _               ' __out ULONG *pulNumberOfChapters
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTitleParentalLevels ( _                    ' VTable offset = 96
     BYVAL ulTitle AS DWORD _                           ' __in  ULONG ulTitle
   , BYREF pulParentalLevels AS DWORD _                 ' __out ULONG *pulParentalLevels
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRoot ( _                                   ' VTable offset = 100
     BYREF pRoot AS ASCIIZ _                            ' __out LPSTR pRoot
   , BYVAL ulBufSize AS DWORD _                         ' __in  ULONG ulBufSize
   , BYREF pulActualSize AS DWORD _                     ' __out ULONG *pulActualSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDvdInfo_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IDvdCmd
' IID = {5A4A97E4-94EE-4A55-9751-74B5643AA27D}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDvdCmd_INTERFACE_DEFINED)
    %IDvdCmd_INTERFACE_DEFINED = 1

$IID_IDvdCmd = GUID$("{5A4A97E4-94EE-4A55-9751-74B5643AA27D}")

INTERFACE IDvdCmd $IID_IDvdCmd

   INHERIT IUnknown

   ' =====================================================================================
   METHOD WaitForStart ( _                              ' VTable offset = 12
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD WaitForEnd ( _                                ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDvdCmd_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IDvdState
' IID = {86303D6D-1C4A-4087-AB42-F711167048EF}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDvdState_INTERFACE_DEFINED)
    %IDvdState_INTERFACE_DEFINED = 1

$IID_IDvdState = GUID$("{86303D6D-1C4A-4087-AB42-F711167048EF}")

INTERFACE IDvdState $IID_IDvdState

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetDiscID ( _                                 ' VTable offset = 12
     BYREF pullUniqueID AS QUAD _                       ' __out ULONGLONG *pullUniqueID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetParentalLevel ( _                          ' VTable offset = 16
     BYREF pulParentalLevel AS DWORD _                  ' __out ULONG *pulParentalLevel
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDvdState_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IDvdControl2
' IID = {33BC7430-EEC0-11D2-8201-00A0C9D74842}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDvdControl2_INTERFACE_DEFINED)
    %IDvdControl2_INTERFACE_DEFINED = 1

$IID_IDvdControl2 = GUID$("{33BC7430-EEC0-11D2-8201-00A0C9D74842}")

INTERFACE IDvdControl2 $IID_IDvdControl2

   INHERIT IUnknown

   ' =====================================================================================
   METHOD PlayTitle ( _                                 ' VTable offset = 12
     BYVAL ulTitle AS DWORD _                           ' __in  ULONG ulTitle
   , BYVAL dwFlags AS DWORD _                           ' __in  DWORD dwFlags
   , BYREF ppCmd AS IDvdCmd _                           ' __out IDvdCmd **ppCmd
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD PlayChapterInTitle ( _                        ' VTable offset = 16
     BYVAL ulTitle AS DWORD _                           ' __in  ULONG ulTitle
   , BYVAL ulChapter AS DWORD _                         ' __in  ULONG ulChapter
   , BYVAL dwFlags AS DWORD _                           ' __in  DWORD dwFlags
   , BYREF ppCmd AS IDvdCmd _                           ' __out IDvdCmd **ppCmd
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD PlayAtTimeInTitle ( _                         ' VTable offset = 20
     BYVAL ulTitle AS DWORD _                           ' __in  ULONG ulTitle
   , BYREF pStartTime AS DVD_HMSF_TIMECODE _            ' __in  DVD_HMSF_TIMECODE *pStartTime
   , BYVAL dwFlags AS DWORD _                           ' __in  DWORD dwFlags
   , BYREF ppCmd AS IDvdCmd _                           ' __out IDvdCmd **ppCmd
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Stop ( _                                      ' VTable offset = 24
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ReturnFromSubmenu ( _                         ' VTable offset = 28
     BYVAL dwFlags AS DWORD _                           ' __in  DWORD dwFlags
   , BYREF ppCmd AS IDvdCmd _                           ' __out IDvdCmd **ppCmd
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD PlayAtTime ( _                                ' VTable offset = 32
     BYREF pTime AS DVD_HMSF_TIMECODE _                 ' __in  DVD_HMSF_TIMECODE *pTime
   , BYVAL dwFlags AS DWORD _                           ' __in  DWORD dwFlags
   , BYREF ppCmd AS IDvdCmd _                           ' __out IDvdCmd **ppCmd
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD PlayChapter ( _                               ' VTable offset = 36
     BYVAL ulChapter AS DWORD _                         ' __in  ULONG ulChapter
   , BYVAL dwFlags AS DWORD _                           ' __in  DWORD dwFlags
   , BYREF ppCmd AS IDvdCmd _                           ' __out IDvdCmd **ppCmd
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD PlayPrevChapter ( _                           ' VTable offset = 40
     BYVAL dwFlags AS DWORD _                           ' __in  DWORD dwFlags
   , BYREF ppCmd AS IDvdCmd _                           ' __out IDvdCmd **ppCmd
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ReplayChapter ( _                             ' VTable offset = 44
     BYVAL dwFlags AS DWORD _                           ' __in  DWORD dwFlags
   , BYREF ppCmd AS IDvdCmd _                           ' __out IDvdCmd **ppCmd
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD PlayNextChapter ( _                           ' VTable offset = 48
     BYVAL dwFlags AS DWORD _                           ' __in  DWORD dwFlags
   , BYREF ppCmd AS IDvdCmd _                           ' __out IDvdCmd **ppCmd
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD PlayForwards ( _                              ' VTable offset = 52
     BYVAL dSpeed AS DOUBLE _                           ' __in  double dSpeed
   , BYVAL dwFlags AS DWORD _                           ' __in  DWORD dwFlags
   , BYREF ppCmd AS IDvdCmd _                           ' __out IDvdCmd **ppCmd
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD PlayBackwards ( _                             ' VTable offset = 56
     BYVAL dSpeed AS DOUBLE _                           ' __in  double dSpeed
   , BYVAL dwFlags AS DWORD _                           ' __in  DWORD dwFlags
   , BYREF ppCmd AS IDvdCmd _                           ' __out IDvdCmd **ppCmd
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ShowMenu ( _                                  ' VTable offset = 60
     BYVAL MenuID AS LONG _                             ' __in  DVD_MENU_ID MenuID
   , BYVAL dwFlags AS DWORD _                           ' __in  DWORD dwFlags
   , BYREF ppCmd AS IDvdCmd _                           ' __out IDvdCmd **ppCmd
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Resume ( _                                    ' VTable offset = 64
     BYVAL dwFlags AS DWORD _                           ' __in  DWORD dwFlags
   , BYREF ppCmd AS IDvdCmd _                           ' __out IDvdCmd **ppCmd
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SelectRelativeButton ( _                      ' VTable offset = 68
     BYVAL buttonDir AS LONG _                          ' DVD_RELATIVE_BUTTON buttonDir
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ActivateButton ( _                            ' VTable offset = 72
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SelectButton ( _                              ' VTable offset = 76
     BYVAL ulButton AS DWORD _                          ' __in  ULONG ulButton
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SelectAndActivateButton ( _                   ' VTable offset = 80
     BYVAL ulButton AS DWORD _                          ' __in  ULONG ulButton
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD StillOff ( _                                  ' VTable offset = 84
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Pause ( _                                     ' VTable offset = 88
     BYVAL bState AS LONG _                             ' __in  BOOL bState
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SelectAudioStream ( _                         ' VTable offset = 92
     BYVAL ulAudio AS DWORD _                           ' __in  ULONG ulAudio
   , BYVAL dwFlags AS DWORD _                           ' __in  DWORD dwFlags
   , BYREF ppCmd AS IDvdCmd _                           ' __out IDvdCmd **ppCmd
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SelectSubpictureStream ( _                    ' VTable offset = 96
     BYVAL ulSubPicture AS DWORD _                      ' __in  ULONG ulSubPicture
   , BYVAL dwFlags AS DWORD _                           ' __in  DWORD dwFlags
   , BYREF ppCmd AS IDvdCmd _                           ' __out IDvdCmd **ppCmd
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetSubpictureState ( _                        ' VTable offset = 100
     BYVAL bState AS LONG _                             ' __in  BOOL bState
   , BYVAL dwFlags AS DWORD _                           ' __in  DWORD dwFlags
   , BYREF ppCmd AS IDvdCmd _                           ' __out IDvdCmd **ppCmd
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SelectAngle ( _                               ' VTable offset = 104
     BYVAL ulAngle AS DWORD _                           ' __in  ULONG ulAngle
   , BYVAL dwFlags AS DWORD _                           ' __in  DWORD dwFlags
   , BYREF ppCmd AS IDvdCmd _                           ' __out IDvdCmd **ppCmd
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SelectParentalLevel ( _                       ' VTable offset = 108
     BYVAL ulParentalLevel AS DWORD _                   ' __in  ULONG ulParentalLevel
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SelectParentalCountry ( _                     ' VTable offset = 112
     BYREF bCountry AS BYTE _                           ' __in  BYTE bCountry[ 2 ]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SelectKaraokeAudioPresentationMode ( _        ' VTable offset = 116
     BYVAL ulMode AS DWORD _                            ' __in  ULONG ulMode
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SelectVideoModePreference ( _                 ' VTable offset = 120
     BYVAL ulPreferredDisplayMode AS DWORD _            ' __in  ULONG ulPreferredDisplayMode
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetDVDDirectory ( _                           ' VTable offset = 124
     BYREF pszwPath AS WSTRINGZ _                       ' __in  LPCWSTR pszwPath
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ActivateAtPosition ( _                        ' VTable offset = 128
     BYVAL point AS POINT _                             ' __in  POINT point
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SelectAtPosition ( _                          ' VTable offset = 132
     BYVAL point AS POINT _                             ' __in  POINT point
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD PlayChaptersAutoStop ( _                      ' VTable offset = 136
     BYVAL ulTitle AS DWORD _                           ' __in  ULONG ulTitle
   , BYVAL ulChapter AS DWORD _                         ' __in  ULONG ulChapter
   , BYVAL ulChaptersToPlay AS DWORD _                  ' __in  ULONG ulChaptersToPlay
   , BYVAL dwFlags AS DWORD _                           ' __in  DWORD dwFlags
   , BYREF ppCmd AS IDvdCmd _                           ' __out IDvdCmd **ppCmd
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AcceptParentalLevelChange ( _                 ' VTable offset = 140
     BYVAL bAccept AS LONG _                            ' __in  BOOL bAccept
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetOption ( _                                 ' VTable offset = 144
     BYVAL flag AS LONG _                               ' __in  DVD_OPTION_FLAG flag
   , BYVAL fState AS LONG _                             ' __in  BOOL fState
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetState ( _                                  ' VTable offset = 148
     BYVAL pState AS DWORD _                            ' __in  IDvdState *pState
   , BYVAL dwFlags AS DWORD _                           ' __in  DWORD dwFlags
   , BYREF ppCmd AS IDvdCmd _                           ' __out IDvdCmd **ppCmd
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD PlayPeriodInTitleAutoStop ( _                 ' VTable offset = 152
     BYVAL ulTitle AS DWORD _                           ' __in  ULONG ulTitle
   , BYVAL pStartTime AS DVD_HMSF_TIMECODE _            ' __in  DVD_HMSF_TIMECODE *pStartTime
   , BYVAL pEndTime AS DVD_HMSF_TIMECODE _              ' __in  DVD_HMSF_TIMECODE *pEndTime
   , BYVAL dwFlags AS DWORD _                           ' __in  DWORD dwFlags
   , BYREF ppCmd AS IDvdCmd _                           ' __out IDvdCmd **ppCmd
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetGPRM ( _                                   ' VTable offset = 156
     BYVAL ulIndex AS DWORD _                           ' __in  ULONG ulIndex
   , BYVAL wValue AS WORD _                             ' __in  WORD wValue
   , BYVAL dwFlags AS DWORD _                           ' __in  DWORD dwFlags
   , BYREF ppCmd AS IDvdCmd _                           ' __out IDvdCmd **ppCmd
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SelectDefaultMenuLanguage ( _                 ' VTable offset = 160
     BYVAL Language AS DWORD _                          ' __in  LCID Language
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SelectDefaultAudioLanguage ( _                ' VTable offset = 164
     BYVAL Language AS DWORD _                          ' __in  LCID Language
   , BYVAL audioExtension AS LONG _                     ' __in  DVD_AUDIO_LANG_EXT audioExtension
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SelectDefaultSubpictureLanguage ( _           ' VTable offset = 168
     BYVAL Language AS DWORD _                          ' __in  LCID Language
   , BYVAL subpictureExtension AS LONG _                ' __in  DVD_SUBPICTURE_LANG_EXT subpictureExtension
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDvdControl2_INTERFACE_DEFINED__ */


' enum DVD_TextStringType
%DVD_Struct_Volume      = &H1
%DVD_Struct_Title       = &H2
%DVD_Struct_ParentalID  = &H3
%DVD_Struct_PartOfTitle = &H4
%DVD_Struct_Cell        = &H5
%DVD_Stream_Audio       = &H10
%DVD_Stream_Subpicture  = &H11
%DVD_Stream_Angle       = &H12
%DVD_Channel_Audio      = &H20
%DVD_General_Name       = &H30
%DVD_General_Comments   = &H31
%DVD_Title_Series       = &H38
%DVD_Title_Movie        = &H39
%DVD_Title_Video        = &H3a
%DVD_Title_Album        = &H3b
%DVD_Title_Song         = &H3c
%DVD_Title_Other        = &H3f
%DVD_Title_Sub_Series   = &H40
%DVD_Title_Sub_Movie    = &H41
%DVD_Title_Sub_Video    = &H42
%DVD_Title_Sub_Album    = &H43
%DVD_Title_Sub_Song     = &H44
%DVD_Title_Sub_Other    = &H47
%DVD_Title_Orig_Series  = &H48
%DVD_Title_Orig_Movie   = &H49
%DVD_Title_Orig_Video   = &H4a
%DVD_Title_Orig_Album   = &H4b
%DVD_Title_Orig_Song    = &H4c
%DVD_Title_Orig_Other   = &H4f
%DVD_Other_Scene        = &H50
%DVD_Other_Cut          = &H51
%DVD_Other_Take         = &H52

' enum DVD_TextCharSet
%DVD_CharSet_Unicode                       = 0
%DVD_CharSet_ISO646                        = 1
%DVD_CharSet_JIS_Roman_Kanji               = 2
%DVD_CharSet_ISO8859_1                     = 3
%DVD_CharSet_ShiftJIS_Kanji_Roman_Katakana = 4

%DVD_TITLE_MENU           = &H000
%DVD_STREAM_DATA_CURRENT  = &H800
%DVD_STREAM_DATA_VMGM     = &H400
%DVD_STREAM_DATA_VTSM     = &H401
%DVD_DEFAULT_AUDIO_STREAM = &H0f

' // Size = 72 bytes
TYPE DVD_DECODER_CAPS DWORD
   dwSize           AS DWORD
   dwAudioCaps      AS DWORD
   dFwdMaxRateVideo AS DOUBLE
   dFwdMaxRateAudio AS DOUBLE
   dFwdMaxRateSP    AS DOUBLE
   dBwdMaxRateVideo AS DOUBLE
   dBwdMaxRateAudio AS DOUBLE
   dBwdMaxRateSP    AS DOUBLE
   dwRes1           AS DWORD
   dwRes2           AS DWORD
   dwRes3           AS DWORD
   dwRes4           AS DWORD
END TYPE

%DVD_AUDIO_CAPS_AC3   = &H00000001???
%DVD_AUDIO_CAPS_MPEG2 = &H00000002???
%DVD_AUDIO_CAPS_LPCM  = &H00000004???
%DVD_AUDIO_CAPS_DTS   = &H00000008???
%DVD_AUDIO_CAPS_SDDS  = &H00000010???


' ########################################################################################
' Interface name = IDvdInfo2
' IID = {34151510-EEC0-11D2-8201-00A0C9D74842}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDvdInfo2_INTERFACE_DEFINED)
    %IDvdInfo2_INTERFACE_DEFINED = 1

$IID_IDvdInfo2 = GUID$("{34151510-EEC0-11D2-8201-00A0C9D74842}")

INTERFACE IDvdInfo2 $IID_IDvdInfo2

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetCurrentDomain ( _                          ' VTable offset = 12
     BYREF pDomain AS LONG _                            ' __out DVD_DOMAIN *pDomain
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCurrentLocation ( _                        ' VTable offset = 16
     BYREF pLocation AS DVD_PLAYBACK_LOCATION2 _        ' __out DVD_PLAYBACK_LOCATION2 *pLocation
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTotalTitleTime ( _                         ' VTable offset = 20
     BYREF pulTotalTime AS DWORD _                      ' __out ULONG *pulTotalTime
   , BYREF ulTimeCodeFlags AS DWORD _                   ' __out ULONG *ulTimeCodeFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCurrentButton ( _                          ' VTable offset = 24
     BYREF pulButtonsAvailable AS DWORD _               ' __out ULONG *pulButtonsAvailable
   , BYREF pulCurrentButton AS DWORD _                  ' __out ULONG *pulCurrentButton
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCurrentAngle ( _                           ' VTable offset = 28
     BYREF pulAnglesAvailable AS DWORD _                ' __out ULONG *pulAnglesAvailable
   , BYREF pulCurrentAngle AS DWORD _                   ' __out ULONG *pulCurrentAngle
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCurrentAudio ( _                           ' VTable offset = 32
     BYREF pulStreamsAvailable AS DWORD _               ' __out ULONG *pulStreamsAvailable
   , BYREF pulCurrentStream AS DWORD _                  ' __out ULONG *pulCurrentStream
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCurrentSubpicture ( _                      ' VTable offset = 36
     BYREF pulStreamsAvailable AS DWORD _               ' __out ULONG *pulStreamsAvailable
   , BYREF pulCurrentStream AS DWORD _                  ' __out ULONG *pulCurrentStream
   , BYREF pIsDisabled AS LONG _                        ' __out BOOL *pIsDisabled
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCurrentUOPS ( _                            ' VTable offset = 40
     BYREF pUOP AS DWORD _                              ' __out VALID_UOP_SOMTHING_OR_OTHER *pUOP
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAllSPRMs ( _                               ' VTable offset = 44
     BYREF pRegisterArray AS DWORD _                    ' __out SPRMARRAY *pRegisterArray [Array of 24 words]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAllGPRMs ( _                               ' VTable offset = 48
     BYREF pRegisterArray AS DWORD _                    ' __out GPRMARRAY *pRegisterArray [Array of 16 words]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAudioLanguage ( _                          ' VTable offset = 52
     BYVAL ulStream AS DWORD _                          ' __in  ULONG ulStream
   , BYREF pLanguage AS DWORD _                         ' __out LCID *pLanguage
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSubpictureLanguage ( _                     ' VTable offset = 56
     BYVAL ulStream AS DWORD _                          ' __in  ULONG ulStream
   , BYREF pLanguage AS DWORD _                         ' __out LCID *pLanguage
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTitleAttributes ( _                        ' VTable offset = 60
     BYVAL ulTitle AS DWORD _                           ' __in  ULONG ulTitle
   , BYREF pMenu AS DVD_MenuAttributes _                ' __out DVD_MenuAttributes *pMenu
   , BYREF pTitle AS DVD_TitleAttributes _              ' __out DVD_TitleAttributes *pTitle
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetVMGAttributes ( _                          ' VTable offset = 64
     BYREF pATR AS DVD_MenuAttributes _                 ' __out DVD_MenuAttributes *pATR
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCurrentVideoAttributes ( _                 ' VTable offset = 68
     BYREF pATR AS DVD_VideoAttributes _                ' __out DVD_VideoAttributes *pATR
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAudioAttributes ( _                        ' VTable offset = 72
     BYVAL ulStream AS DWORD _                          ' __in  ULONG ulStream
   , BYREF pATR AS DVD_AudioAttributes _                ' __out DVD_AudioAttributes *pATR
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetKaraokeAttributes ( _                      ' VTable offset = 76
     BYVAL ulStream AS DWORD _                          ' __in  ULONG ulStream
   , BYREF pAttributes AS DVD_KaraokeAttributes _       ' __out DVD_KaraokeAttributes *pAttributes
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSubpictureAttributes ( _                   ' VTable offset = 80
     BYVAL ulStream AS DWORD _                          ' __in  ULONG ulStream
   , BYREF pATR AS DVD_SubpictureAttributes _           ' __out DVD_SubpictureAttributes *pATR
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDVDVolumeInfo ( _                          ' VTable offset = 84
     BYREF pulNumOfVolumes AS DWORD _                   ' __out ULONG *pulNumOfVolumes
   , BYREF pulVolume AS DWORD _                         ' __out ULONG *pulVolume
   , BYREF pSide AS LONG _                              ' __out DVD_DISC_SIDE *pSide
   , BYREF pulNumOfTitles AS DWORD _                    ' __out ULONG *pulNumOfTitles
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDVDTextNumberOfLanguages ( _               ' VTable offset = 88
     BYREF pulNumOfLangs AS DWORD _                     ' __out ULONG *pulNumOfLangs
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDVDTextLanguageInfo ( _                    ' VTable offset = 92
     BYVAL ulLangIndex AS DWORD _                       ' __in  ULONG ulLangIndex
   , BYREF pulNumOfStrings AS DWORD _                   ' __out ULONG *pulNumOfStrings
   , BYREF pLangCode AS DWORD _                         ' __out LCID *pLangCode
   , BYREF pbCharacterSet AS LONG _                     ' __out enum DVD_TextCharSet *pbCharacterSet
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDVDTextStringAsNative ( _                  ' VTable offset = 96
     BYVAL ulLangIndex AS DWORD _                       ' __in  ULONG ulLangIndex
   , BYVAL ulStringIndex AS DWORD _                     ' __in  ULONG ulStringIndex
   , BYVAL pbBuffer AS BYTE PTR _                       ' __out BYTE *pbBuffer
   , BYVAL ulMaxBufferSize AS DWORD _                   ' __in  ULONG ulMaxBufferSize
   , BYREF pulActualSize AS DWORD _                     ' __out ULONG *pulActualSize
   , BYREF pType AS LONG _                              ' __out enum DVD_TextStringType *pType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDVDTextStringAsUnicode ( _                 ' VTable offset = 100
     BYVAL ulLangIndex AS DWORD _                       ' __in  ULONG ulLangIndex
   , BYVAL ulStringIndex AS DWORD _                     ' __in  ULONG ulStringIndex
   , BYREF pchwBuffer AS WSTRINGZ _                     ' __out WCHAR *pchwBuffer
   , BYVAL ulMaxBufferSize AS DWORD _                   ' __in  ULONG ulMaxBufferSize
   , BYREF pulActualSize AS DWORD _                     ' __out ULONG *pulActualSize
   , BYREF pType AS LONG _                              ' __out enum DVD_TextStringType *pType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPlayerParentalLevel ( _                    ' VTable offset = 104
     BYREF pulParentalLevel AS DWORD _                  ' __out ULONG *pulParentalLevel
   , BYREF pbCountryCode AS BYTE _                      ' __out BYTE pbCountryCode[ 2 ]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetNumberOfChapters ( _                       ' VTable offset = 108
     BYVAL ulTitle AS DWORD _                           ' __in  ULONG ulTitle
   , BYREF pulNumOfChapters AS DWORD _                  ' __out ULONG *pulNumOfChapters
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTitleParentalLevels ( _                    ' VTable offset = 112
     BYVAL ulTitle AS DWORD _                           ' __in  ULONG ulTitle
   , BYREF pulParentalLevels AS DWORD _                 ' __out ULONG *pulParentalLevels
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDVDDirectory ( _                           ' VTable offset = 116
     BYREF pszwPath AS DWORD _                          ' __out LPWSTR pszwPath
   , BYVAL ulMaxSize AS DWORD _                         ' __in  ULONG ulMaxSize
   , BYREF pulActualSize AS DWORD _                     ' __out ULONG *pulActualSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsAudioStreamEnabled ( _                      ' VTable offset = 120
     BYVAL ulStreamNum AS DWORD _                       ' __in  ULONG ulStreamNum
   , BYREF pbEnabled AS LONG _                          ' __out BOOL *pbEnabled
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDiscID ( _                                 ' VTable offset = 124
     BYREF pszwPath AS WSTRINGZ _                       ' __in  LPCWSTR pszwPath
   , BYREF pullDiscID AS QUAD _                         ' __out ULONGLONG *pullDiscID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetState ( _                                  ' VTable offset = 128
     BYREF pStateData AS IDvdState _                    ' __out IDvdState **pStateData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMenuLanguages ( _                          ' VTable offset = 132
     BYREF pLanguages AS DWORD _                        ' __out LCID *pLanguages
   , BYVAL ulMaxLanguages AS DWORD _                    ' __in  ULONG ulMaxLanguages
   , BYREF pulActualLanguages AS DWORD _                ' __out ULONG *pulActualLanguages
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetButtonAtPosition ( _                       ' VTable offset = 136
     BYREF point AS POINT _                             ' __in  POINT point
   , BYREF pulButtonIndex AS DWORD _                    ' __out ULONG *pulButtonIndex
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCmdFromEvent ( _                           ' VTable offset = 140
     BYVAL lParam1 AS LONG _                            ' __in  LONG_PTR lParam1
   , BYREF pCmdObj AS IDvdCmd _                         ' __out IDvdCmd **pCmdObj
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDefaultMenuLanguage ( _                    ' VTable offset = 144
     BYREF pLanguage AS DWORD _                         ' __out LCID *pLanguage
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDefaultAudioLanguage ( _                   ' VTable offset = 148
     BYREF pLanguage AS DWORD _                         ' __out LCID *pLanguage
   , BYREF pAudioExtension AS LONG _                    ' __out DVD_AUDIO_LANG_EXT *pAudioExtension
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDefaultSubpictureLanguage ( _              ' VTable offset = 152
     BYREF pLanguage AS DWORD _                         ' __out LCID *pLanguage
   , BYREF pSubpictureExtension AS LONG _               ' __out DVD_SUBPICTURE_LANG_EXT *pSubpictureExtension
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDecoderCaps ( _                            ' VTable offset = 156
     BYREF pCaps AS DVD_DECODER_CAPS _                  ' __out DVD_DECODER_CAPS *pCaps
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetButtonRect ( _                             ' VTable offset = 160
     BYVAL ulButton AS DWORD _                          ' __in  ULONG ulButton
   , BYREF pRect AS RECT _                              ' __out RECT *pRect
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsSubpictureStreamEnabled ( _                 ' VTable offset = 164
     BYVAL ulStreamNum AS DWORD _                       ' __in  ULONG ulStreamNum
   , BYREF pbEnabled AS LONG _                          ' __out BOOL *pbEnabled
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDvdInfo2_INTERFACE_DEFINED__ */


' enum AM_DVD_GRAPH_FLAGS
%AM_DVD_HWDEC_PREFER = &H1???
%AM_DVD_HWDEC_ONLY   = &H2???
%AM_DVD_SWDEC_PREFER = &H4???
%AM_DVD_SWDEC_ONLY   = &H8???
%AM_DVD_NOVPE        = &H100???
%AM_DVD_DO_NOT_CLEAR = &H200???
%AM_DVD_VMR9_ONLY    = &H800???
%AM_DVD_EVR_ONLY     = &H1000???
%AM_DVD_EVR_QOS      = &H2000???
%AM_DVD_ADAPT_GRAPH  = &H4000???
%AM_DVD_MASK         = &Hffff???

' enum AM_DVD_STREAM_FLAGS
%AM_DVD_STREAM_VIDEO  = &H1???
%AM_DVD_STREAM_AUDIO  = &H2???
%AM_DVD_STREAM_SUBPIC = &H4???

' // Size = 32 bytes
TYPE AM_DVD_RENDERSTATUS DWORD
   hrVPEStatus         AS LONG
   bDvdVolInvalid      AS LONG
   bDvdVolUnknown      AS LONG
   bNoLine21In         AS LONG
   bNoLine21Out        AS LONG
   iNumStreams         AS LONG
   iNumStreamsFailed   AS LONG
   dwFailedStreamsFlag AS DWORD
END TYPE


' ########################################################################################
' Interface name = IDvdGraphBuilder
' IID = {FCC152B6-F372-11D0-8E00-00C04FD7C08B}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDvdGraphBuilder_INTERFACE_DEFINED)
    %IDvdGraphBuilder_INTERFACE_DEFINED = 1

$IID_IDvdGraphBuilder = GUID$("{FCC152B6-F372-11D0-8E00-00C04FD7C08B}")

INTERFACE IDvdGraphBuilder $IID_IDvdGraphBuilder

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetFiltergraph ( _                            ' VTable offset = 12
     BYREF ppGB AS IGraphBuilder _                      ' __out IGraphBuilder **ppGB
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDvdInterface ( _                           ' VTable offset = 16
     BYREF riid AS GUID _                               ' __in  REFIID riid
   , BYREF ppvIF AS IUnknown _                          ' __out void **ppvIF
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RenderDvdVideoVolume ( _                      ' VTable offset = 20
     BYREF lpcwszPathName AS WSTRINGZ _                 ' __in  LPCWSTR lpcwszPathName
   , BYVAL dwFlags AS DWORD _                           ' __in  DWORD dwFlags
   , BYREF pStatus AS AM_DVD_RENDERSTATUS _             ' __out AM_DVD_RENDERSTATUS *pStatus
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDvdGraphBuilder_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IDDrawExclModeVideo
' IID = {153ACC21-D83B-11D1-82BF-00A0C9696C8F}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDDrawExclModeVideo_INTERFACE_DEFINED)
    %IDDrawExclModeVideo_INTERFACE_DEFINED = 1

$IID_IDDrawExclModeVideo = GUID$("{153ACC21-D83B-11D1-82BF-00A0C9696C8F}")

INTERFACE IDDrawExclModeVideo $IID_IDDrawExclModeVideo

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetDDrawObject ( _                            ' VTable offset = 12
     BYVAL pDDrawObject AS IDirectDraw _                ' __in  IDirectDraw *pDDrawObject
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDDrawObject ( _                            ' VTable offset = 16
     BYREF ppDDrawObject AS IDirectDraw _               ' __out IDirectDraw **ppDDrawObject
   , BYREF pbUsingExternal AS LONG _                    ' __out BOOL *pbUsingExternal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetDDrawSurface ( _                           ' VTable offset = 20
     BYVAL pDDrawSurface AS IDirectDrawSurface _        ' __in  IDirectDrawSurface *pDDrawSurface
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDDrawSurface ( _                           ' VTable offset = 24
     BYREF ppDDrawSurface AS IDirectDrawSurface _       ' __out IDirectDrawSurface **ppDDrawSurface
   , BYREF pbUsingExternal AS LONG _                    ' __out BOOL *pbUsingExternal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetDrawParameters ( _                         ' VTable offset = 28
     BYREF prcSource AS RECT _                          ' __in  const RECT *prcSource
   , BYREF prcTarget AS RECT _                          ' __in  const RECT *prcTarget
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetNativeVideoProps ( _                       ' VTable offset = 32
     BYREF pdwVideoWidth AS DWORD _                     ' __out DWORD *pdwVideoWidth
   , BYREF pdwVideoHeight AS DWORD _                    ' __out DWORD *pdwVideoHeight
   , BYREF pdwPictAspectRatioX AS DWORD _               ' __out DWORD *pdwPictAspectRatioX
   , BYREF pdwPictAspectRatioY AS DWORD _               ' __out DWORD *pdwPictAspectRatioY
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetCallbackInterface ( _                      ' VTable offset = 36
     BYVAL pCallback AS IDDrawExclModeVideoCallback _   ' __in  IDDrawExclModeVideoCallback *pCallback
   , BYVAL dwFlags AS DWORD _                           ' __in  DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDDrawExclModeVideo_INTERFACE_DEFINED__ */


' AM_OVERLAY_NOTIFY_FLAGS
%AM_OVERLAY_NOTIFY_VISIBLE_CHANGE = &H1???
%AM_OVERLAY_NOTIFY_SOURCE_CHANGE  = &H2???
%AM_OVERLAY_NOTIFY_DEST_CHANGE    = &H4???


' ########################################################################################
' Interface name = IDDrawExclModeVideoCallback
' IID = {913C24A0-20AB-11D2-9038-00A0C9697298}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDDrawExclModeVideoCallback_INTERFACE_DEFINED)
    %IDDrawExclModeVideoCallback_INTERFACE_DEFINED = 1

$IID_IDDrawExclModeVideoCallback = GUID$("{913C24A0-20AB-11D2-9038-00A0C9697298}")

INTERFACE IDDrawExclModeVideoCallback $IID_IDDrawExclModeVideoCallback

   INHERIT IUnknown

   ' =====================================================================================
   METHOD OnUpdateOverlay ( _                           ' VTable offset = 12
     BYVAL bBefore AS LONG _                            ' __in  BOOL bBefore
   , BYVAL dwFlags AS DWORD _                           ' __in  DWORD dwFlags
   , BYVAL bOldVisible AS LONG _                        ' __in  BOOL bOldVisible
   , BYREF prcOldSrc AS RECT _                          ' __in  const RECT *prcOldSrc
   , BYREF prcOldDest AS RECT _                         ' __in  const RECT *prcOldDest
   , BYVAL bNewVisible AS LONG _                        ' __in  BOOL bNewVisible
   , BYREF prcNewSrc AS RECT _                          ' __in  const RECT *prcNewSrc
   , BYREF prcNewDest AS RECT _                         ' __in  const RECT *prcNewDest
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnUpdateColorKey ( _                          ' VTable offset = 16
     BYREF pKey AS COLORKEY _                           ' __in  const COLORKEY *pKey
   , BYVAL dwColor AS DWORD _                           ' __in  DWORD dwColor
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnUpdateSize ( _                              ' VTable offset = 20
     BYVAL dwWidth AS DWORD _                           ' __in  DWORD dwWidth
   , BYVAL dwHeight AS DWORD _                          ' __in  DWORD dwHeight
   , BYVAL dwARWidth AS DWORD _                         ' __in  DWORD dwARWidth
   , BYVAL dwARHeight AS DWORD _                        ' __in  DWORD dwARHeight
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDDrawExclModeVideoCallback_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IPinConnection
' IID = {4A9A62D3-27D4-403D-91E9-89F540E55534}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IPinConnection_INTERFACE_DEFINED)
    %IPinConnection_INTERFACE_DEFINED = 1

$IID_IPinConnection = GUID$("{4A9A62D3-27D4-403D-91E9-89F540E55534}")

INTERFACE IPinConnection $IID_IPinConnection

   INHERIT IUnknown

   ' =====================================================================================
   METHOD DynamicQueryAccept ( _                        ' VTable offset = 12
     BYREF pmt AS AM_MEDIA_TYPE _                       ' __in  const AM_MEDIA_TYPE *pmt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD NotifyEndOfStream ( _                         ' VTable offset = 16
     BYVAL hNotifyEvent AS DWORD _                      ' __in  HANDLE hNotifyEvent
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsEndPin ( _                                  ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DynamicDisconnect ( _                         ' VTable offset = 24
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IPinConnection_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IPinFlowControl
' IID = {C56E9858-DBF3-4F6B-8119-384AF2060DEB}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IPinFlowControl_INTERFACE_DEFINED)
    %IPinFlowControl_INTERFACE_DEFINED = 1

$IID_IPinFlowControl = GUID$("{C56E9858-DBF3-4F6B-8119-384AF2060DEB}")

INTERFACE IPinFlowControl $IID_IPinFlowControl

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Block ( _                                     ' VTable offset = 12
     BYVAL dwBlockFlags AS DWORD _                      ' __in  DWORD dwBlockFlags
   , BYVAL hEvent AS DWORD _                            ' __in  HANDLE hEvent
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IPinFlowControl_INTERFACE_DEFINED__ */


' enum AM_PIN_FLOW_CONTROL_BLOCK_FLAGS
%AM_PIN_FLOW_CONTROL_BLOCK   = &H1

' enum AM_GRAPH_CONFIG_RECONNECT_FLAGS
%AM_GRAPH_CONFIG_RECONNECT_DIRECTCONNECT           = &H1
%AM_GRAPH_CONFIG_RECONNECT_CACHE_REMOVED_FILTERS   = &H2
%AM_GRAPH_CONFIG_RECONNECT_USE_ONLY_CACHED_FILTERS = &H4

' enum REM_FILTER_FLAGS
%REMFILTERF_LEAVECONNECTED   = &H1

' enum AM_FILTER_FLAGS
%AM_FILTER_FLAGS_REMOVABLE   = &H1


' ########################################################################################
' Interface name = IGraphConfig
' IID = {03A1EB8E-32BF-4245-8502-114D08A9CB88}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IGraphConfig_INTERFACE_DEFINED)
    %IGraphConfig_INTERFACE_DEFINED = 1

$IID_IGraphConfig = GUID$("{03A1EB8E-32BF-4245-8502-114D08A9CB88}")

INTERFACE IGraphConfig $IID_IGraphConfig

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Reconnect ( _                                 ' VTable offset = 12
     BYVAL pOutputPin AS IPin _                         ' __in  IPin *pOutputPin
   , BYVAL pInputPin AS IPin _                          ' __in  IPin *pInputPin
   , BYREF pmtFirstConnection AS AM_MEDIA_TYPE _        ' __in  const AM_MEDIA_TYPE *pmtFirstConnection
   , BYVAL pUsingFilter AS IBaseFilter _                ' __in  IBaseFilter *pUsingFilter
   , BYVAL hAbortEvent AS DWORD _                       ' __in  HANDLE hAbortEvent
   , BYVAL dwFlags AS DWORD _                           ' __in  DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reconfigure ( _                               ' VTable offset = 16
     BYVAL pCallback AS IGraphConfigCallback _          ' __in  IGraphConfigCallback *pCallback
   , BYVAL pvContext AS DWORD _                         ' __in  PVOID pvContext
   , BYVAL dwFlags AS DWORD _                           ' __in  DWORD dwFlags
   , BYVAL hAbortEvent AS DWORD _                       ' __in  HANDLE hAbortEvent
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddFilterToCache ( _                          ' VTable offset = 20
     BYVAL pFilter AS IBaseFilter _                     ' __in  IBaseFilter *pFilter
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumCacheFilter ( _                           ' VTable offset = 24
     BYREF pEnum AS IEnumFilters _                      ' __out IEnumFilters **pEnum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RemoveFilterFromCache ( _                     ' VTable offset = 28
     BYVAL pFilter AS IBaseFilter _                     ' __in  IBaseFilter *pFilter
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetStartTime ( _                              ' VTable offset = 32
     BYREF prtStart AS QUAD _                           ' __out REFERENCE_TIME *prtStart
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD PushThroughData ( _                           ' VTable offset = 36
     BYVAL pOutputPin AS IPin _                         ' __in  IPin *pOutputPin
   , BYVAL pConnection AS IPinConnection _              ' __in  IPinConnection *pConnection
   , BYVAL hEventAbort AS DWORD _                       ' __in  HANDLE hEventAbort
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetFilterFlags ( _                            ' VTable offset = 40
     BYVAL pFilter AS IBaseFilter _                     ' __in  IBaseFilter *pFilter
   , BYVAL dwFlags AS DWORD _                           ' __in  DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFilterFlags ( _                            ' VTable offset = 44
     BYVAL pFilter AS IBaseFilter _                     ' __in  IBaseFilter *pFilter
   , BYREF pdwFlags AS DWORD _                          ' __out DWORD *pdwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RemoveFilterEx ( _                            ' VTable offset = 48
     BYVAL pFilter AS IBaseFilter _                     ' __in  IBaseFilter *pFilter
   , BYVAL dwFlags AS DWORD _                           ' __in  DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IGraphConfig_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IGraphConfigCallback
' IID = {ADE0FD60-D19D-11D2-ABF6-00A0C905F375}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IGraphConfigCallback_INTERFACE_DEFINED)
    %IGraphConfigCallback_INTERFACE_DEFINED = 1

$IID_IGraphConfigCallback = GUID$("{ADE0FD60-D19D-11D2-ABF6-00A0C905F375}")

INTERFACE IGraphConfigCallback $IID_IGraphConfigCallback

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Reconfigure ( _                               ' VTable offset = 12
     BYVAL pvContext AS DWORD _                         ' __in  PVOID pvContext
   , BYVAL dwFlags AS DWORD _                           ' __in  DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IGraphConfigCallback_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IFilterChain
' IID = {DCFBDCF6-0DC2-45F5-9AB2-7C330EA09C29}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IFilterChain_INTERFACE_DEFINED)
    %IFilterChain_INTERFACE_DEFINED = 1

$IID_IFilterChain = GUID$("{DCFBDCF6-0DC2-45F5-9AB2-7C330EA09C29}")

INTERFACE IFilterChain $IID_IFilterChain

   INHERIT IUnknown

   ' =====================================================================================
   METHOD StartChain ( _                                ' VTable offset = 12
     BYVAL pStartFilter AS IBaseFilter _                ' __in  IBaseFilter *pStartFilter
   , BYVAL pEndFilter AS IBaseFilter _                  ' __in  IBaseFilter *pEndFilter
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD PauseChain ( _                                ' VTable offset = 16
     BYVAL pStartFilter AS IBaseFilter _                ' __in  IBaseFilter *pStartFilter
   , BYVAL pEndFilter AS IBaseFilter _                  ' __in  IBaseFilter *pEndFilter
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD StopChain ( _                                 ' VTable offset = 20
     BYVAL pStartFilter AS IBaseFilter _                ' __in  IBaseFilter *pStartFilter
   , BYVAL pEndFilter AS IBaseFilter _                  ' __in  IBaseFilter *pEndFilter
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RemoveChain ( _                               ' VTable offset = 24
     BYVAL pStartFilter AS IBaseFilter _                ' __in  IBaseFilter *pStartFilter
   , BYVAL pEndFilter AS IBaseFilter _                  ' __in  IBaseFilter *pEndFilter
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* C style interface */


'typedef DWORD *LPDIRECTDRAW7;
'typedef DWORD *LPDIRECTDRAWSURFACE7;
'typedef DWORD *LPDDPIXELFORMAT;
'typedef DWORD *LPBITMAPINFOHEADER;

' Already defined in DDRAW.INC with different variable names
'TYPE DDCOLORKEY DWORD
'   dw1 AS DWORD
'   dw2 AS DWORD
'END TYPE

' enum VMRPresentationFlags
%VMRSample_SyncPoint        = &H1???
%VMRSample_Preroll          = &H2???
%VMRSample_Discontinuity    = &H4???
%VMRSample_TimeValid        = &H8???
%VMRSample_SrcDstRectsValid = &H10???

' // Size = 72 bytes
TYPE VMRPRESENTATIONINFO   ' Must be 8 byte aligned
   dwFlags             AS DWORD   ' DWORD
   lpSurf              AS DWORD   ' LPDIRECTDRAWSURFACE7
   rtStart             AS QUAD    ' REFERENCE_TIME
   rtEnd               AS QUAD    ' REFERENCE_TIME
   szAspectRatio       AS SIZE    ' SIZE
   rcSrc               AS RECT    ' RECT
   rcDst               AS RECT    ' RECT
   dwTypeSpecificFlags AS DWORD   ' DWORD
   dwInterlaceFlags    AS DWORD   ' DWORD
END TYPE


' ########################################################################################
' Interface name = IVMRImagePresenter
' IID = {CE704FE7-E71E-41FB-BAA2-C4403E1182F5}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IVMRImagePresenter_INTERFACE_DEFINED)
    %IVMRImagePresenter_INTERFACE_DEFINED = 1

$IID_IVMRImagePresenter = GUID$("{CE704FE7-E71E-41FB-BAA2-C4403E1182F5}")

INTERFACE IVMRImagePresenter $IID_IVMRImagePresenter

   INHERIT IUnknown

   ' =====================================================================================
   METHOD StartPresenting ( _                           ' VTable offset = 12
     BYVAL dwUserID AS DWORD _                          ' __in  DWORD_PTR dwUserID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD StopPresenting ( _                            ' VTable offset = 16
     BYVAL dwUserID AS DWORD _                          ' __in  DWORD_PTR dwUserID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD PresentImage ( _                              ' VTable offset = 20
     BYVAL dwUserID AS DWORD _                          ' __in  DWORD_PTR dwUserID
   , BYREF lpPresInfo AS VMRPRESENTATIONINFO _          ' __in  VMRPRESENTATIONINFO *lpPresInfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IVMRImagePresenter_INTERFACE_DEFINED__ */


' enum VMRSurfaceAllocationFlags
%AMAP_PIXELFORMAT_VALID = &H1
%AMAP_3D_TARGET         = &H2
%AMAP_ALLOW_SYSMEM      = &H4
%AMAP_FORCE_SYSMEM      = &H8
%AMAP_DIRECTED_FLIP     = &H10
%AMAP_DXVA_TARGET       = &H20

' // Size = 40 bytes
TYPE VMRALLOCATIONINFO DWORD
   dwFlags          AS DWORD                  ' DWORD
   lpHdr            AS BITMAPINFOHEADER PTR   ' LPBITMAPINFOHEADER
   lpPixFmt         AS DWORD                  ' LPDDPIXELFORMAT
   szAspectRatio    AS SIZE                   ' SIZE
   dwMinBuffers     AS DWORD                  ' DWORD
   dwMaxBuffers     AS DWORD                  ' DWORD
   dwInterlaceFlags AS DWORD                  ' DWORD
   szNativeSize     AS SIZE                   ' SIZE
END TYPE


' ########################################################################################
' Interface name = IVMRSurfaceAllocator
' IID = {31CE832E-4484-458B-8CCA-F4D7E3DB0B52}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IVMRSurfaceAllocator_INTERFACE_DEFINED)
    %IVMRSurfaceAllocator_INTERFACE_DEFINED = 1

$IID_IVMRSurfaceAllocator = GUID$("{31CE832E-4484-458B-8CCA-F4D7E3DB0B52}")

INTERFACE IVMRSurfaceAllocator $IID_IVMRSurfaceAllocator

   INHERIT IUnknown

   ' =====================================================================================
   METHOD AllocateSurface ( _                           ' VTable offset = 12
     BYVAL dwUserID AS DWORD _                          ' __in  DWORD_PTR dwUserID
   , BYREF lpAllocInfo AS VMRALLOCATIONINFO _           ' __in  VMRALLOCATIONINFO *lpAllocInfo
   , BYREF lpdwActualBuffers AS DWORD _                 ' __inout DWORD *lpdwActualBuffers
   , BYREF lplpSurface AS IDirectDrawSurface7 _         ' __out LPDIRECTDRAWSURFACE7 *lplpSurface
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD FreeSurface ( _                               ' VTable offset = 16
     BYVAL dwID AS DWORD _                              ' __in  DWORD_PTR dwID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD PrepareSurface ( _                            ' VTable offset = 20
     BYVAL dwUserID AS DWORD _                          ' __in  DWORD_PTR dwUserID
   , BYVAL lpSurface AS IDirectDrawSurface7 _           ' __in  LPDIRECTDRAWSURFACE7 lpSurface
   , BYVAL dwSurfaceFlags AS DWORD _                    ' __in  DWORD dwSurfaceFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AdviseNotify ( _                              ' VTable offset = 24
     BYVAL lpIVMRSurfAllocNotify AS IVMRSurfaceAllocatorNotify _ ' __in  IVMRSurfaceAllocatorNotify *lpIVMRSurfAllocNotify
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IVMRSurfaceAllocator_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IVMRSurfaceAllocatorNotify
' IID = {AADA05A8-5A4E-4729-AF0B-CEA27AED51E2}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IVMRSurfaceAllocatorNotify_INTERFACE_DEFINED)
    %IVMRSurfaceAllocatorNotify_INTERFACE_DEFINED = 1

$IID_IVMRSurfaceAllocatorNotify = GUID$("{AADA05A8-5A4E-4729-AF0B-CEA27AED51E2}")

INTERFACE IVMRSurfaceAllocatorNotify $IID_IVMRSurfaceAllocatorNotify

   INHERIT IUnknown

   ' =====================================================================================
   METHOD AdviseSurfaceAllocator ( _                    ' VTable offset = 12
     BYVAL dwUserID AS DWORD _                          ' __in  DWORD_PTR dwUserID
   , BYVAL lpIVRMSurfaceAllocator AS IVMRSurfaceAllocator _ ' __in IVMRSurfaceAllocator *lpIVRMSurfaceAllocator
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetDDrawDevice ( _                            ' VTable offset = 16
     BYVAL lpDDrawDevice AS IDirectdraw7 _              ' __in  LPDIRECTDRAW7 lpDDrawDevice
   , BYVAL hMonitor AS DWORD _                          ' __in  HMONITOR hMonitor
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ChangeDDrawDevice ( _                         ' VTable offset = 20
     BYVAL lpDDrawDevice AS IDirectdraw7 _              ' __in  LPDIRECTDRAW7 lpDDrawDevice
   , BYVAL hMonitor AS DWORD _                          ' __in  HMONITOR hMonitor
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RestoreDDrawSurfaces ( _                      ' VTable offset = 24
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD NotifyEvent ( _                               ' VTable offset = 28
     BYVAL EventCode AS LONG _                          ' __in  LONG EventCode
   , BYVAL Param1 AS LONG _                             ' __in  LONG_PTR Param1
   , BYVAL Param2 AS LONG _                             ' __in  LONG_PTR Param2
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetBorderColor ( _                            ' VTable offset = 36
     BYVAL clrBorder AS DWORD _                         ' __in  COLORREF clrBorder
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IVMRSurfaceAllocatorNotify_INTERFACE_DEFINED__ */


' enum VMR_ASPECT_RATIO_MODE
%VMR_ARMODE_NONE       = 0
%VMR_ARMODE_LETTER_BOX = %VMR_ARMODE_NONE + 1


' ########################################################################################
' Interface name = IVMRWindowlessControl
' IID = {0EB1088C-4DCD-46F0-878F-39DAE86A51B7}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IVMRWindowlessControl_INTERFACE_DEFINED)
    %IVMRWindowlessControl_INTERFACE_DEFINED = 1

$IID_IVMRWindowlessControl = GUID$("{0EB1088C-4DCD-46F0-878F-39DAE86A51B7}")

INTERFACE IVMRWindowlessControl $IID_IVMRWindowlessControl

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetNativeVideoSize ( _                        ' VTable offset = 12
     BYREF lpWidth AS LONG _                            ' __out LONG *lpWidth
   , BYREF lpHeight AS LONG _                           ' __out LONG *lpHeight
   , BYREF lpARWidth AS LONG _                          ' __out LONG *lpARWidth
   , BYREF lpARHeight AS LONG _                         ' __out LONG *lpARHeight
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMinIdealVideoSize ( _                      ' VTable offset = 16
     BYREF lpWidth AS LONG _                            ' __out LONG *lpWidth
   , BYREF lpHeight AS LONG _                           ' __out LONG *lpHeight
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMaxIdealVideoSize ( _                      ' VTable offset = 20
     BYREF lpWidth AS LONG _                            ' __out LONG *lpWidth
   , BYREF lpHeight AS LONG _                           ' __out LONG *lpHeight
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetVideoPosition ( _                          ' VTable offset = 24
     BYREF lpSRCRect AS RECT _                          ' __in  const LPRECT lpSRCRect
   , BYREF lpDSTRect AS RECT _                          ' __in  const LPRECT lpDSTRect
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetVideoPosition ( _                          ' VTable offset = 28
     BYREF lpSRCRect AS RECT _                          ' __in  LPRECT lpSRCRect
   , BYREF lpDSTRect AS RECT _                          ' __in  LPRECT lpDSTRect
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAspectRatioMode ( _                        ' VTable offset = 32
     BYREF lpAspectRatioMode AS DWORD _                 ' __out DWORD *lpAspectRatioMode
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetAspectRatioMode ( _                        ' VTable offset = 36
     BYVAL AspectRatioMode AS DWORD _                   ' __in  DWORD AspectRatioMode
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetVideoClippingWindow ( _                    ' VTable offset = 40
     BYVAL hwnd AS DWORD _                              ' __in  HWND hwnd
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RepaintVideo ( _                              ' VTable offset = 44
     BYVAL hwnd AS DWORD _                              ' __in  HWND hwnd
   , BYVAL hdc AS DWORD _                               ' __in  HDC hdc
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DisplayModeChanged ( _                        ' VTable offset = 48
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCurrentImage ( _                           ' VTable offset = 52
     BYREF lpDib AS DWORD _                             ' __out BYTE **lpDib
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetBorderColor ( _                            ' VTable offset = 56
     BYVAL Clr AS DWORD _                               ' __in  COLORREF Clr
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetBorderColor ( _                            ' VTable offset = 60
     BYREF lpClr AS DWORD _                             ' __out COLORREF *lpClr
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetColorKey ( _                               ' VTable offset = 64
     BYVAL Clr AS DWORD _                               ' __in  COLORREF Clr
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetColorKey ( _                               ' VTable offset = 68
     BYREF lpClr AS DWORD _                             ' __out COLORREF *lpClr
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IVMRWindowlessControl_INTERFACE_DEFINED__ */


' enum VMRMixerPrefs
%MixerPref_NoDecimation         = &H1
%MixerPref_DecimateOutput       = &H2
%MixerPref_ARAdjustXorY         = &H4
%MixerPref_DecimationReserved   = &H8
%MixerPref_DecimateMask         = &Hf
%MixerPref_BiLinearFiltering    = &H10
%MixerPref_PointFiltering       = &H20
%MixerPref_FilteringMask        = &Hf0
%MixerPref_RenderTargetRGB      = &H100
%MixerPref_RenderTargetYUV      = &H1000
%MixerPref_RenderTargetYUV420   = &H200
%MixerPref_RenderTargetYUV422   = &H400
%MixerPref_RenderTargetYUV444   = &H800
%MixerPref_RenderTargetReserved = &He000
%MixerPref_RenderTargetMask     = &Hff00
%MixerPref_DynamicSwitchToBOB   = &H10000
%MixerPref_DynamicDecimateBy2   = &H20000
%MixerPref_DynamicReserved      = &Hc0000
%MixerPref_DynamicMask          = &Hf0000

' // Size = 16 bytes
TYPE NORMALIZEDRECT DWORD
   left   AS SINGLE
   top    AS SINGLE
   right  AS SINGLE
   bottom AS SINGLE
END TYPE


' ########################################################################################
' Interface name = IVMRMixerControl
' IID = {1C1A17B0-BED0-415D-974B-DC6696131599}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IVMRMixerControl_INTERFACE_DEFINED)
    %IVMRMixerControl_INTERFACE_DEFINED = 1

$IID_IVMRMixerControl = GUID$("{1C1A17B0-BED0-415D-974B-DC6696131599}")

INTERFACE IVMRMixerControl $IID_IVMRMixerControl

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetAlpha ( _                                  ' VTable offset = 12
     BYVAL dwStreamID AS DWORD _                        ' __in  DWORD dwStreamID
   , BYVAL Alpha AS SINGLE _                            ' __in  float Alpha
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAlpha ( _                                  ' VTable offset = 16
     BYVAL dwStreamID AS DWORD _                        ' __in  DWORD dwStreamID
   , BYREF pAlpha AS SINGLE _                           ' __out float *pAlpha
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetZOrder ( _                                 ' VTable offset = 20
     BYVAL dwStreamID AS DWORD _                        ' __in  DWORD dwStreamID
   , BYVAL dwZ AS DWORD _                               ' __in  DWORD dwZ
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetZOrder ( _                                 ' VTable offset = 24
     BYVAL dwStreamID AS DWORD _                        ' __in  DWORD dwStreamID
   , BYREF pZ AS DWORD _                                ' __out DWORD *pZ
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetOutputRect ( _                             ' VTable offset = 28
     BYVAL dwStreamID AS DWORD _                        ' __in  DWORD dwStreamID
   , BYREF pRect AS NORMALIZEDRECT _                    ' __in  const NORMALIZEDRECT *pRect
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetOutputRect ( _                             ' VTable offset = 32
     BYVAL dwStreamID AS DWORD _                        ' __in  DWORD dwStreamID
   , BYREF pRect AS NORMALIZEDRECT _                    ' __out NORMALIZEDRECT *pRect
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetBackgroundClr ( _                          ' VTable offset = 36
     BYVAL ClrBkg AS DWORD _                            ' __in  COLORREF ClrBkg
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetBackgroundClr ( _                          ' VTable offset = 40
     BYVAL ClrBkg AS DWORD _                            ' __in  COLORREF ClrBkg
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetMixingPrefs ( _                            ' VTable offset = 44
     BYVAL dwMixerPrefs AS DWORD _                      ' __in  DWORD dwMixerPrefs
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMixingPrefs ( _                            ' VTable offset = 48
     BYREF pdwMixerPrefs AS DWORD _                     ' __out DWORD *pdwMixerPrefs
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IVMRMixerControl_INTERFACE_DEFINED__ */

' // Size = 20 bytes
TYPE VMRGUID DWORD
   pGUID AS GUID PTR
   GUID  AS GUID
END TYPE

' // Size = 648 bytes
TYPE VMRMONITORINFO QWORD FILL  ' Must be 8 byte aligned
   guid            AS VMRGUID          ' VMRGUID guid
   rcMonitor       AS RECT             ' RECT rcMonitor
   hMon            AS DWORD            ' HMONITOR hMon
   dwFlags         AS DWORD            ' DWORD dwFlags
   szDevice        AS WSTRINGZ * 32    ' wchar_t szDevice[ 32 ]
   szDescription   AS WSTRINGZ * 256   ' wchar_t szDescription[ 256 ]
   liDriverVersion AS QUAD             ' LARGE_INTEGER liDriverVersion
   dwVendorId      AS DWORD            ' DWORD dwVendorId
   dwDeviceId      AS DWORD            ' DWORD dwDeviceId
   dwSubSysId      AS DWORD            ' DWORD dwSubSysId
   dwRevision      AS DWORD            ' DWORD dwRevision
END TYPE


' ########################################################################################
' Interface name = IVMRMonitorConfig
' IID = {9CF0B1B6-FBAA-4B7F-88CF-CF1F130A0DCE}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IVMRMonitorConfig_INTERFACE_DEFINED)
    %IVMRMonitorConfig_INTERFACE_DEFINED = 1

$IID_IVMRMonitorConfig = GUID$("{9CF0B1B6-FBAA-4B7F-88CF-CF1F130A0DCE}")

INTERFACE IVMRMonitorConfig $IID_IVMRMonitorConfig

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetMonitor ( _                                ' VTable offset = 12
     BYREF pGUID AS VMRGUID _                           ' __in  const VMRGUID *pGUID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMonitor ( _                                ' VTable offset = 16
     BYREF pGUID AS VMRGUID _                           ' __out VMRGUID *pGUID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetDefaultMonitor ( _                         ' VTable offset = 20
     BYREF pGUID AS VMRGUID _                           ' __in  const VMRGUID *pGUID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDefaultMonitor ( _                         ' VTable offset = 24
     BYREF pGUID AS VMRGUID _                           ' __out VMRGUID *pGUID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAvailableMonitors ( _                      ' VTable offset = 28
     BYREF pInfo AS VMRMONITORINFO _                    ' __out VMRMONITORINFO *pInfo
   , BYVAL dwMaxInfoArraySize AS DWORD _                ' __in  DWORD dwMaxInfoArraySize
   , BYREF pdwNumDevices AS DWORD _                     ' __out DWORD *pdwNumDevices
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IVMRMonitorConfig_INTERFACE_DEFINED__ */


' enum VMRRenderPrefs
%RenderPrefs_RestrictToInitialMonitor     = 0
%RenderPrefs_ForceOffscreen               = &H1
%RenderPrefs_ForceOverlays                = &H2
%RenderPrefs_AllowOverlays                = 0
%RenderPrefs_AllowOffscreen               = 0
%RenderPrefs_DoNotRenderColorKeyAndBorder = &H8
%RenderPrefs_Reserved                     = &H10
%RenderPrefs_PreferAGPMemWhenMixing       = &H20
%RenderPrefs_Mask                         = &H3f

' enum VMRMode
%VMRMode_Windowed   = &H1
%VMRMode_Windowless = &H2
%VMRMode_Renderless = &H4
%VMRMode_Mask       = &H7

' enum __MIDL___MIDL_itf_strmif_0393_0003
%MAX_NUMBER_OF_STREAMS = 16


' ########################################################################################
' Interface name = IVMRFilterConfig
' IID = {9E5530C5-7034-48B4-BB46-0B8A6EFC8E36}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IVMRFilterConfig_INTERFACE_DEFINED)
    %IVMRFilterConfig_INTERFACE_DEFINED = 1

$IID_IVMRFilterConfig = GUID$("{9E5530C5-7034-48B4-BB46-0B8A6EFC8E36}")

INTERFACE IVMRFilterConfig $IID_IVMRFilterConfig

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetImageCompositor ( _                        ' VTable offset = 12
     BYVAL lpVMRImgCompositor AS IVMRImageCompositor _  ' __in  IVMRImageCompositor *lpVMRImgCompositor
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetNumberOfStreams ( _                        ' VTable offset = 16
     BYVAL dwMaxStreams AS DWORD _                      ' __in  DWORD dwMaxStreams
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetNumberOfStreams ( _                        ' VTable offset = 20
     BYREF pdwMaxStreams AS DWORD _                     ' __out DWORD *pdwMaxStreams
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetRenderingPrefs ( _                         ' VTable offset = 24
     BYVAL dwRenderFlags AS DWORD _                     ' __in  DWORD dwRenderFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRenderingPrefs ( _                         ' VTable offset = 28
     BYREF pdwRenderFlags AS DWORD _                    ' __out DWORD *pdwRenderFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetRenderingMode ( _                          ' VTable offset = 32
     BYVAL Mode AS DWORD _                              ' __in  DWORD Mode
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRenderingMode ( _                          ' VTable offset = 36
     BYREF pMode AS DWORD _                             ' __out DWORD *pMode
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IVMRFilterConfig_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IVMRAspectRatioControl
' IID = {EDE80B5C-BAD6-4623-B537-65586C9F8DFD}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IVMRAspectRatioControl_INTERFACE_DEFINED)
    %IVMRAspectRatioControl_INTERFACE_DEFINED = 1

$IID_IVMRAspectRatioControl = GUID$("{EDE80B5C-BAD6-4623-B537-65586C9F8DFD}")

INTERFACE IVMRAspectRatioControl $IID_IVMRAspectRatioControl

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetAspectRatioMode ( _                        ' VTable offset = 12
     BYREF lpdwARMode AS DWORD _                        ' __out LPDWORD lpdwARMode
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetAspectRatioMode ( _                        ' VTable offset = 16
     BYVAL dwARMode AS DWORD _                          ' __in  DWORD dwARMode
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IVMRAspectRatioControl_INTERFACE_DEFINED__ */


' enum VMRDeinterlacePrefs
%DeinterlacePref_NextBest = &H1
%DeinterlacePref_BOB      = &H2
%DeinterlacePref_Weave    = &H4
%DeinterlacePref_Mask     = &H7

' enum VMRDeinterlaceTech
%DeinterlaceTech_Unknown             = 0
%DeinterlaceTech_BOBLineReplicate    = &H1
%DeinterlaceTech_BOBVerticalStretch  = &H2
%DeinterlaceTech_MedianFiltering     = &H4
%DeinterlaceTech_EdgeFiltering       = &H10
%DeinterlaceTech_FieldAdaptive       = &H20
%DeinterlaceTech_PixelAdaptive       = &H40
%DeinterlaceTech_MotionVectorSteered = &H80

' // Size = 8 bytes
TYPE VMRFrequency DWORD
   dwNumerator   AS DWORD
   dwDenominator AS DWORD
END TYPE

' // Size = 36 bytes
TYPE VMRVideoDesc DWORD
   dwSize               AS DWORD
   dwSampleWidth        AS DWORD
   dwSampleHeight       AS DWORD
   SingleFieldPerSample AS LONG
   dwFourCC             AS DWORD
   InputSampleFreq      AS VMRFrequency
   OutputFrameFreq      AS VMRFrequency
END TYPE

' // Size = 20 bytes
TYPE VMRDeinterlaceCaps DWORD
   dwSize                    AS DWORD
   dwNumPreviousOutputFrames AS DWORD
   dwNumForwardRefSamples    AS DWORD
   dwNumBackwardRefSamples   AS DWORD
   DeinterlaceTechnology     AS LONG    ' VMRDeinterlaceTech enum
END TYPE


' ########################################################################################
' Interface name = IVMRDeinterlaceControl
' IID = {BB057577-0DB8-4E6A-87A7-1A8C9A505A0F}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IVMRDeinterlaceControl_INTERFACE_DEFINED)
    %IVMRDeinterlaceControl_INTERFACE_DEFINED = 1

$IID_IVMRDeinterlaceControl = GUID$("{BB057577-0DB8-4E6A-87A7-1A8C9A505A0F}")

INTERFACE IVMRDeinterlaceControl $IID_IVMRDeinterlaceControl

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetNumberOfDeinterlaceModes ( _               ' VTable offset = 12
     BYREF lpVideoDescription AS VMRVideoDesc _         ' __in  VMRVideoDesc *lpVideoDescription
   , BYREF lpdwNumDeinterlaceModes AS DWORD _           ' __inout LPDWORD lpdwNumDeinterlaceModes
   , BYREF lpDeinterlaceModes AS GUID _                 ' __out LPGUID lpDeinterlaceModes
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDeinterlaceModeCaps ( _                    ' VTable offset = 16
     BYREF lpDeinterlaceMode AS GUID _                  ' __in  LPGUID lpDeinterlaceMode
   , BYREF lpVideoDescription AS VMRVideoDesc _         ' __in  VMRVideoDesc *lpVideoDescription
   , BYREF lpDeinterlaceCaps AS VMRDeinterlaceCaps _    ' __inout VMRDeinterlaceCaps *lpDeinterlaceCaps
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDeinterlaceMode ( _                        ' VTable offset = 20
     BYVAL dwStreamID AS DWORD _                        ' __in  DWORD dwStreamID
   , BYREF lpDeinterlaceMode AS GUID _                  ' __out LPGUID lpDeinterlaceMode
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetDeinterlaceMode ( _                        ' VTable offset = 24
     BYVAL dwStreamID AS DWORD _                        ' __in  DWORD dwStreamID
   , BYREF lpDeinterlaceMode AS GUID _                  ' __in  LPGUID lpDeinterlaceMode
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDeinterlacePrefs ( _                       ' VTable offset = 28
     BYREF lpdwDeinterlacePrefs AS DWORD _              ' __out LPDWORD lpdwDeinterlacePrefs
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetDeinterlacePrefs ( _                       ' VTable offset = 32
     BYVAL dwDeinterlacePrefs AS DWORD _                ' __in  DWORD dwDeinterlacePrefs
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetActualDeinterlaceMode ( _                  ' VTable offset = 36
     BYVAL dwStreamID AS DWORD _                        ' __in  DWORD dwStreamID
   , BYREF lpDeinterlaceMode AS GUID _                  ' __out LPGUID lpDeinterlaceMode
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IVMRDeinterlaceControl_INTERFACE_DEFINED__ */

' // Size = 52 bytes
TYPE VMRALPHABITMAP DWORD
   dwFlags   AS DWORD            ' DWORD dwFlags
   hdc       AS DWORD            ' HDC hdc
   pDDS      AS DWORD            ' LPDIRECTDRAWSURFACE7 pDDS
   rSrc      AS RECT             ' RECT rSrc
   rDest     AS NORMALIZEDRECT   ' NORMALIZEDRECT rDest
   fAlpha    AS SINGLE           ' FLOAT fAlpha
   clrSrcKey AS DWORD            ' COLORREF clrSrcKey
END TYPE

%VMRBITMAP_DISABLE            = &H00000001???
%VMRBITMAP_HDC                = &H00000002???
%VMRBITMAP_ENTIREDDS          = &H00000004???
%VMRBITMAP_SRCCOLORKEY        = &H00000008???
%VMRBITMAP_SRCRECT            = &H00000010???


' ########################################################################################
' Interface name = IVMRMixerBitmap
' IID = {1E673275-0257-40AA-AF20-7C608D4A0428}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IVMRMixerBitmap_INTERFACE_DEFINED)
    %IVMRMixerBitmap_INTERFACE_DEFINED = 1

$IID_IVMRMixerBitmap = GUID$("{1E673275-0257-40AA-AF20-7C608D4A0428}")

INTERFACE IVMRMixerBitmap $IID_IVMRMixerBitmap

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetAlphaBitmap ( _                            ' VTable offset = 12
     BYREF pBmpParms AS VMRALPHABITMAP _                ' __in  const VMRALPHABITMAP *pBmpParms
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UpdateAlphaBitmapParameters ( _               ' VTable offset = 16
     BYREF pBmpParms AS VMRALPHABITMAP _                ' __in  const VMRALPHABITMAP *pBmpParms
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAlphaBitmapParameters ( _                  ' VTable offset = 20
     BYREF pBmpParms AS VMRALPHABITMAP _                ' __out VMRALPHABITMAP *pBmpParms
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IVMRMixerBitmap_INTERFACE_DEFINED__ */

' // Size = 44 bytes
TYPE VMRVIDEOSTREAMINFO DWORD
   pddsVideoSurface AS DWORD            ' LPDIRECTDRAWSURFACE7 pddsVideoSurface
   dwWidth          AS DWORD            ' DWORD dwWidth
   dwHeight         AS DWORD            ' DWORD dwHeight
   dwStrmID         AS DWORD            ' DWORD dwStrmID
   fAlpha           AS SINGLE           ' FLOAT fAlpha
   ddClrKey         AS DDCOLORKEY       ' DDCOLORKEY ddClrKey
   rNormal          AS NORMALIZEDRECT   ' NORMALIZEDRECT rNormal
END TYPE


' ########################################################################################
' Interface name = IVMRImageCompositor
' IID = {7A4FB5AF-479F-4074-BB40-CE6722E43C82}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IVMRImageCompositor_INTERFACE_DEFINED)
    %IVMRImageCompositor_INTERFACE_DEFINED = 1

$IID_IVMRImageCompositor = GUID$("{7A4FB5AF-479F-4074-BB40-CE6722E43C82}")

INTERFACE IVMRImageCompositor $IID_IVMRImageCompositor

   INHERIT IUnknown

   ' =====================================================================================
   METHOD InitCompositionTarget ( _                     ' VTable offset = 12
     BYVAL pD3DDevice AS IUnknown _                     ' __in  IUnknown *pD3DDevice
   , BYVAL pddsRenderTarget AS IDirectDrawSurface7 _    ' __in  LPDIRECTDRAWSURFACE7 pddsRenderTarget
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD TermCompositionTarget ( _                     ' VTable offset = 16
     BYVAL pD3DDevice AS IUnknown _                     ' __in  IUnknown *pD3DDevice
   , BYVAL pddsRenderTarget AS IDirectDrawSurface7 _    ' __in  LPDIRECTDRAWSURFACE7 pddsRenderTarget
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetStreamMediaType ( _                        ' VTable offset = 20
     BYVAL dwStrmID AS DWORD _                          ' __in  DWORD dwStrmID
   , BYREF pmt AS AM_MEDIA_TYPE _                       ' __in  AM_MEDIA_TYPE *pmt
   , BYVAL fTexture AS LONG _                           ' __in  BOOL fTexture
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CompositeImage ( _                            ' VTable offset = 24
     BYVAL pD3DDevice AS IUnknown _                     ' __in  IUnknown *pD3DDevice
   , BYVAL pddsRenderTarget AS IDirectDrawSurface7 _    ' __in  LPDIRECTDRAWSURFACE7 pddsRenderTarget
   , BYREF pmtRenderTarget AS AM_MEDIA_TYPE _           ' __in  AM_MEDIA_TYPE *pmtRenderTarget
   , BYVAL rtStart AS QUAD _                            ' __in  REFERENCE_TIME rtStart
   , BYVAL rtEnd AS QUAD _                              ' __in  REFERENCE_TIME rtEnd
   , BYVAL dwClrBkGnd AS DWORD _                        ' __in  DWORD dwClrBkGnd
   , BYREF pVideoStreamInfo AS VMRVIDEOSTREAMINFO _     ' __in  VMRVIDEOSTREAMINFO *pVideoStreamInfo
   , BYVAL cStreams AS DWORD _                          ' __in  UINT cStreams
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IVMRImageCompositor_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IVMRVideoStreamControl
' IID = {058D1F11-2A54-4BEF-BD54-DF706626B727}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IVMRVideoStreamControl_INTERFACE_DEFINED)
    %IVMRVideoStreamControl_INTERFACE_DEFINED = 1

$IID_IVMRVideoStreamControl = GUID$("{058D1F11-2A54-4BEF-BD54-DF706626B727}")

INTERFACE IVMRVideoStreamControl $IID_IVMRVideoStreamControl

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetColorKey ( _                               ' VTable offset = 12
     BYREF lpClrKey AS DDCOLORKEY _                     ' __in  LPDDCOLORKEY lpClrKey
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetColorKey ( _                               ' VTable offset = 16
     BYREF lpClrKey AS DDCOLORKEY _                     ' __out LPDDCOLORKEY lpClrKey
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetStreamActiveState ( _                      ' VTable offset = 20
     BYVAL fActive AS LONG _                            ' __in  BOOL fActive
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetStreamActiveState ( _                      ' VTable offset = 24
     BYREF lpfActive AS LONG _                          ' __out BOOL *lpfActive
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IVMRVideoStreamControl_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IVMRSurface
' IID = {A9849BBE-9EC8-4263-B764-62730F0D15D0}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IVMRSurface_INTERFACE_DEFINED)
    %IVMRSurface_INTERFACE_DEFINED = 1

$IID_IVMRSurface = GUID$("{A9849BBE-9EC8-4263-B764-62730F0D15D0}")

INTERFACE IVMRSurface $IID_IVMRSurface

   INHERIT IUnknown

   ' =====================================================================================
   METHOD IsSurfaceLocked ( _                           ' VTable offset = 12
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD LockSurface ( _                               ' VTable offset = 16
     BYREF lpSurface AS DWORD _                         ' __out BYTE **lpSurface
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UnlockSurface ( _                             ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSurface ( _                                ' VTable offset = 24
     BYREF lplpSurface AS IDirectDrawSurface7 _         ' __out LPDIRECTDRAWSURFACE7 *lplpSurface
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IVMRSurface_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IVMRImagePresenterConfig
' IID = {9F3A1C85-8555-49BA-935F-BE5B5B29D178}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IVMRImagePresenterConfig_INTERFACE_DEFINED)
    %IVMRImagePresenterConfig_INTERFACE_DEFINED = 1

$IID_IVMRImagePresenterConfig = GUID$("{9F3A1C85-8555-49BA-935F-BE5B5B29D178}")

INTERFACE IVMRImagePresenterConfig $IID_IVMRImagePresenterConfig

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetRenderingPrefs ( _                         ' VTable offset = 12
     BYVAL dwRenderFlags AS DWORD _                     ' __in  DWORD dwRenderFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRenderingPrefs ( _                         ' VTable offset = 16
     BYREF dwRenderFlags AS DWORD _                     ' __out DWORD *dwRenderFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IVMRImagePresenterConfig_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IVMRImagePresenterExclModeConfig
' IID = {E6F7CE40-4673-44F1-8F77-5499D68CB4EA}
' Inherited interface = IVMRImagePresenterConfig
' ########################################################################################

#IF NOT %DEF(%IVMRImagePresenterExclModeConfig_INTERFACE_DEFINED)
    %IVMRImagePresenterExclModeConfig_INTERFACE_DEFINED = 1

$IID_IVMRImagePresenterExclModeConfig = GUID$("{E6F7CE40-4673-44F1-8F77-5499D68CB4EA}")

INTERFACE IVMRImagePresenterExclModeConfig $IID_IVMRImagePresenterExclModeConfig

   INHERIT IUnknown

   ' =====================================================================================
   ' IVMRImagePresenterConfig Methods
   ' =====================================================================================
   METHOD SetRenderingPrefs ( _                         ' VTable offset = 12
     BYVAL dwRenderFlags AS DWORD _                     ' __in  DWORD dwRenderFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRenderingPrefs ( _                         ' VTable offset = 16
     BYREF dwRenderFlags AS DWORD _                     ' __out DWORD *dwRenderFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IVMRImagePresenterExclModeConfig Methods
   ' =====================================================================================
   METHOD SetXlcModeDDObjAndPrimarySurface ( _          ' VTable offset = 20
     BYVAL lpDDObj AS IDirectDraw7 _                    ' __in  LPDIRECTDRAW7 lpDDObj
   , BYVAL lpPrimarySurf AS IDirectDrawSurface7 _       ' __in  LPDIRECTDRAWSURFACE7 lpPrimarySurf
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetXlcModeDDObjAndPrimarySurface ( _          ' VTable offset = 24
     BYREF lpDDObj AS IDirectDraw7 _                    ' __out LPDIRECTDRAW7 *lpDDObj
   , BYREF lpPrimarySurf AS IDirectDrawSurface7 _       ' __out LPDIRECTDRAWSURFACE7 *lpPrimarySurf
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IVMRImagePresenterExclModeConfig_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IVPManager
' IID = {AAC18C18-E186-46D2-825D-A1F8DC8E395A}
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IVPManager_INTERFACE_DEFINED)
    %IVPManager_INTERFACE_DEFINED = 1

$IID_IVPManager = GUID$("{AAC18C18-E186-46D2-825D-A1F8DC8E395A}")

INTERFACE IVPManager $IID_IVPManager

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetVideoPortIndex ( _                         ' VTable offset = 12
     BYVAL dwVideoPortIndex AS DWORD _                  ' __in  DWORD dwVideoPortIndex
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetVideoPortIndex ( _                         ' VTable offset = 16
     BYREF pdwVideoPortIndex AS DWORD _                 ' __out DWORD *pdwVideoPortIndex
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IVPManager_INTERFACE_DEFINED__ */
