' ########################################################################################
' Microsoft Windows
' File: StreamCache.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%STREAMCACHE_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "objidl.inc"
#INCLUDE ONCE "nsscore.inc"
#INCLUDE ONCE "DataContainerVersion.inc"
#INCLUDE ONCE "event.inc"
#INCLUDE ONCE "WMSProxy.inc"

$IID_IWMSCacheProxy               = GUID$("{2E34AB83-0D3D-11D2-9EEE-006097D2D7CF}")
$IID_IWMSCacheProxyCallback       = GUID$("{2E34AB84-0D3D-11D2-9EEE-006097D2D7CF}")
$IID_IWMSCacheProxyServer         = GUID$("{68F2A550-D815-11D2-BEF6-00A0C95EC343}")
$IID_IWMSCacheProxyServerCallback = GUID$("{68F2A551-D815-11D2-BEF6-00A0C95EC343}")
$IID_IWMSCacheItemDescriptor      = GUID$("{C3CBA330-AC05-11D2-BEF0-00A0C95EC343}")
$IID_IWMSCacheItemCollection      = GUID$("{E6E05D80-F45C-11D2-BEFE-00A0C95EC343}")

' ========================================================================================
' WMS_CACHE_QUERY_MISS_RESPONSE enum
' ========================================================================================

%WMS_CACHE_QUERY_MISS_SKIP              = 0
%WMS_CACHE_QUERY_MISS_DISCONNECT        = %WMS_CACHE_QUERY_MISS_SKIP              + 1
%WMS_CACHE_QUERY_MISS_REDIRECT          = %WMS_CACHE_QUERY_MISS_DISCONNECT        + 1
%WMS_CACHE_QUERY_MISS_REDIRECT_TO_PROXY = %WMS_CACHE_QUERY_MISS_REDIRECT          + 1
%WMS_CACHE_QUERY_MISS_PLAY_BROADCAST    = %WMS_CACHE_QUERY_MISS_REDIRECT_TO_PROXY + 1
%WMS_CACHE_QUERY_MISS_PLAY_ON_DEMAND    = %WMS_CACHE_QUERY_MISS_PLAY_BROADCAST    + 1
%WMS_CACHE_QUERY_MISS_FORWARD_REQUEST   = %WMS_CACHE_QUERY_MISS_PLAY_ON_DEMAND    + 1
%WMS_CACHE_QUERY_MISS_PROCESS_REQUEST   = %WMS_CACHE_QUERY_MISS_FORWARD_REQUEST   + 1

' ========================================================================================
' WMS_CACHE_QUERY_RESPONSE enum
' ========================================================================================

%WMS_CACHE_QUERY_HIT_PLAY_ON_DEMAND  = 0
%WMS_CACHE_QUERY_HIT_PLAY_BROADCAST  = %WMS_CACHE_QUERY_HIT_PLAY_ON_DEMAND  + 1
%WMS_CACHE_QUERY_HIT_PROCESS_REQUEST = %WMS_CACHE_QUERY_HIT_PLAY_BROADCAST  + 1
%WMS_CACHE_QUERY_MISS                = %WMS_CACHE_QUERY_HIT_PROCESS_REQUEST + 1

' ========================================================================================
' WMS_CACHE_VERSION_COMPARE_RESPONSE enum
' ========================================================================================

%WMS_CACHE_VERSION_FAIL_TO_CHECK_VERSION = 0
%WMS_CACHE_VERSION_CACHE_STALE           = %WMS_CACHE_VERSION_FAIL_TO_CHECK_VERSION + 1
%WMS_CACHE_VERSION_CACHE_UP_TO_DATE      = %WMS_CACHE_VERSION_CACHE_STALE           + 1

' ========================================================================================
' WMS_CACHE_CONTENT_TYPE_FLAGS enum
' ========================================================================================

%WMS_CACHE_CONTENT_TYPE_BROADCAST = &H1
%WMS_CACHE_CONTENT_TYPE_PLAYLIST  = &H2

' ========================================================================================
' WMS_CACHE_QUERY_TYPE_FLAGS enum
' ========================================================================================

%WMS_CACHE_QUERY_OPEN             = &H1
%WMS_CACHE_QUERY_GET_CONTENT_INFO = &H2
%WMS_CACHE_QUERY_CACHE_EVENT      = &H4
%WMS_CACHE_QUERY_REVERSE_PROXY    = &H8
%WMS_CACHE_QUERY_LOCAL_EVENT      = &H10

' ========================================================================================
' WMS_CACHE_CONTENT_DOWNLOAD_FLAGS enum
' ========================================================================================

%WMS_CONTENT_DOWNLOAD_ABORT_IF_BCAST = &H1

' ========================================================================================
' WMS_CACHE_REMOTE_EVENT_FLAGS enum
' ========================================================================================

%WMS_CACHE_REMOTE_OPEN  = &H1
%WMS_CACHE_REMOTE_CLOSE = &H2
%WMS_CACHE_REMOTE_LOG   = &H4


' ########################################################################################
' Interface name = IWMSCacheProxy
' IID = {2E34AB83-0D3D-11D2-9EEE-006097D2D7CF}
' Contains methods that administer a cache. This interface is implemented by a cache / proxy plug-in and called by the server.
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IWMSCacheProxy_INTERFACE_DEFINED)
    %IWMSCacheProxy_INTERFACE_DEFINED = 1

INTERFACE IWMSCacheProxy $IID_IWMSCacheProxy

   INHERIT IUnknown

   ' =====================================================================================
   METHOD QueryCache ( _                                ' VTable offset = 12
     BYVAL bstrOriginUrl AS WSTRING _                   ' __in BSTR bstrOriginUrl
   , BYVAL pUserContext AS IWMSContext _                ' __in IWMSContext *pUserContext
   , BYVAL pCommandContext AS IWMSCommandContext _      ' __in IWMSCommandContext *pCommandContext
   , BYVAL pPresentationContext AS IWMSContext _        ' __in IWMSContext *pPresentationContext
   , BYVAL lQueryType AS LONG _                         ' __in long lQueryType
   , BYVAL pCallback AS IWMSCacheProxyCallback _        ' __in IWMSCacheProxyCallback *pCallback
   , BYVAL varContext AS VARIANT _                      ' __in VARIANT varContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD QueryCacheMissPolicy ( _                      ' VTable offset = 16
     BYVAL bstrOriginUrl AS WSTRING _                   ' __in BSTR bstrOriginUrl
   , BYVAL pUserContext AS IWMSContext _                ' __in IWMSContext *pUserContext
   , BYVAL pCommandContext AS IWMSCommandContext _      ' __in IWMSCommandContext *pCommandContext
   , BYVAL pPresentationContext AS IWMSContext _        ' __in IWMSContext *pPresentationContext
   , BYVAL pCachePluginContext AS IUnknown _            ' __in IUnknown *pCachePluginContext
   , BYVAL lQueryType AS LONG _                         ' __in long lQueryType
   , BYVAL pCallback AS IWMSCacheProxyCallback _        ' __in IWMSCacheProxyCallback *pCallback
   , BYVAL varContext AS VARIANT _                      ' __in VARIANT varContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RemoveCacheItem ( _                           ' VTable offset = 20
     BYVAL bstrOriginUrl AS WSTRING _                   ' __in BSTR bstrOriginUrl
   , BYVAL pCallback AS IWMSCacheProxyCallback _        ' __in IWMSCacheProxyCallback *pCallback
   , BYVAL varContext AS VARIANT _                      ' __in VARIANT varContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RemoveAllCacheItems ( _                       ' VTable offset = 24
     BYVAL pCallback AS IWMSCacheProxyCallback _        ' __in IWMSCacheProxyCallback *pCallback
   , BYVAL varContext AS VARIANT _                      ' __in VARIANT varContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddCacheItem ( _                              ' VTable offset = 28
     BYVAL bstrOriginUrl AS WSTRING _                   ' __in BSTR bstrOriginUrl
   , BYVAL bstrPrestuffUrl AS WSTRING _                 ' __in BSTR bstrPrestuffUrl
   , BYVAL lExpiration AS LONG _                        ' __in long lExpiration
   , BYVAL lBandwidth AS LONG _                         ' __in long lBandwidth
   , BYVAL lRemoteEventFlags AS LONG _                  ' __in long lRemoteEventFlags
   , BYVAL pCallback AS IWMSCacheProxyCallback _        ' __in IWMSCacheProxyCallback *pCallback
   , BYVAL varContext AS VARIANT _                      ' __in VARIANT varContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD QuerySpaceForCacheItem ( _                    ' VTable offset = 32
     BYVAL lContentSizeLow AS LONG _                    ' __in long lContentSizeLow
   , BYVAL lContentSizeHigh AS LONG _                   ' __in long lContentSizeHigh
   , BYREF pvarfSpaceAvail AS INTEGER _                 ' __out VARIANT_BOOL *pvarfSpaceAvail
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD FindCacheItem ( _                             ' VTable offset = 36
     BYVAL bstrOriginUrl AS WSTRING _                   ' __in BSTR bstrOriginUrl
   , BYREF ppCacheItemDescriptor AS IWMSCacheItemDescriptor _ ' __out IWMSCacheItemDescriptor **ppCacheItemDescriptor
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateCacheItemCollection ( _                 ' VTable offset = 40
     BYREF ppCacheItemCollection AS IWMSCacheItemCollection _ ' __out IWMSCacheItemCollection **ppCacheItemCollection
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnCacheClientClose ( _                        ' VTable offset = 44
     BYVAL resultHr AS LONG _                           ' __in HRESULT resultHr
   , BYVAL pUserContext AS IWMSContext _                ' __in IWMSContext *pUserContext
   , BYVAL pPresentationContext AS IWMSContext _        ' __in IWMSContext *pPresentationContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWMSCacheProxy_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IWMSCacheProxyCallback
' IID = {2E34AB84-0D3D-11D2-9EEE-006097D2D7CF}
' Contains methods that enable a cache / proxy plug-in to respond to calls that the server makes through the IWMSCacheProxy interface. This interface is implemented by the server and called by a cache / proxy plug-in.
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IWMSCacheProxyCallback_INTERFACE_DEFINED)
    %IWMSCacheProxyCallback_INTERFACE_DEFINED = 1

INTERFACE IWMSCacheProxyCallback $IID_IWMSCacheProxyCallback

   INHERIT IUnknown

   ' =====================================================================================
   METHOD OnQueryCache ( _                              ' VTable offset = 12
     BYVAL lHr AS LONG _                                ' __in long lHr
   , BYVAL Response AS LONG _                           ' __in WMS_CACHE_QUERY_RESPONSE Response
   , BYVAL bstrCacheUrl AS WSTRING _                    ' __in BSTR bstrCacheUrl
   , BYVAL pContentInfo AS IWMSContext _                ' __in IWMSContext *pContentInfo
   , BYVAL pCachePluginContext AS IUnknown _            ' __in IUnknown *pCachePluginContext
   , BYVAL varContext AS VARIANT _                      ' __in VARIANT varContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnQueryCacheMissPolicy ( _                    ' VTable offset = 16
     BYVAL lHr AS LONG _                                ' __in long lHr
   , BYVAL CacheMissPolicy AS LONG _                    ' __in WMS_CACHE_QUERY_MISS_RESPONSE CacheMissPolicy
   , BYVAL bstrUrl AS WSTRING _                         ' __in BSTR bstrUrl
   , BYVAL pProxyContext AS IWMSProxyContext _          ' __in IWMSProxyContext *pProxyContext
   , BYVAL pContentInfo AS IWMSContext _                ' __in IWMSContext *pContentInfo
   , BYVAL varContext AS VARIANT _                      ' __in VARIANT varContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnRemoveCacheItem ( _                         ' VTable offset = 20
     BYVAL lHr AS LONG _                                ' __in long lHr
   , BYVAL varContext AS VARIANT _                      ' __in VARIANT varContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnRemoveAllCacheItems ( _                     ' VTable offset = 24
     BYVAL lHr AS LONG _                                ' __in long lHr
   , BYVAL varContext AS VARIANT _                      ' __in VARIANT varContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnAddCacheItem ( _                            ' VTable offset = 28
     BYVAL lHr AS LONG _                                ' __in long lHr
   , BYVAL pCacheItemDescriptor AS IWMSCacheItemDescriptor _ ' __in IWMSCacheItemDescriptor *pCacheItemDescriptor
   , BYVAL varServerContext AS VARIANT _                ' __in VARIANT varServerContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWMSCacheProxyCallback_INTERFACE_DEFINED__ */


' ########################################################################################
' Interface name = IWMSCacheProxyServer
' IID = {68F2A550-D815-11D2-BEF6-00A0C95EC343}
' Contains methods that validate client authorization, retrieve information about cached content, determine whether the content is current, and download content to a cache.
' This interface is implemented by the server and called by a cache / proxy plug-in.
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IWMSCacheProxyServer_INTERFACE_DEFINED)
    %IWMSCacheProxyServer_INTERFACE_DEFINED = 1

INTERFACE IWMSCacheProxyServer $IID_IWMSCacheProxyServer

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetContentInformation ( _                     ' VTable offset = 12
     BYVAL bstrOriginUrl AS WSTRING _                   ' __in BSTR bstrOriginUrl
   , BYVAL pPresentationContext AS IWMSContext _        ' __in IWMSContext *pPresentationContext
   , BYVAL pICacheProxy AS IWMSCacheProxy _             ' __in IWMSCacheProxy *pICacheProxy
   , BYVAL pIProxyContext AS IWMSProxyContext _         ' __in_opt IWMSProxyContext *pIProxyContext
   , BYVAL pCallback AS IWMSCacheProxyServerCallback _  ' __in_opt IWMSCacheProxyServerCallback *pCallback
   , BYVAL varContext AS VARIANT _                      ' __in_opt VARIANT varContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CompareContentInformation ( _                 ' VTable offset = 16
     BYVAL bstrOriginUrl AS WSTRING _                   ' __in BSTR bstrOriginUrl
   , BYVAL pContentInfo AS IWMSContext _                ' __in IWMSContext *pContentInfo
   , BYVAL pPresentationContext AS IWMSContext _        ' __in IWMSContext *pPresentationContext
   , BYVAL pICacheProxy AS IWMSCacheProxy _             ' __in IWMSCacheProxy *pICacheProxy
   , BYVAL pIProxyContext AS IWMSProxyContext _         ' __in_opt IWMSProxyContext *pIProxyContext
   , BYVAL pCallback AS IWMSCacheProxyServerCallback _  ' __in_opt IWMSCacheProxyServerCallback *pCallback
   , BYVAL varContext AS VARIANT _                      ' __in_opt VARIANT varContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DownloadContent ( _                           ' VTable offset = 20
     BYVAL bstrOriginUrl AS WSTRING _                   ' __in BSTR bstrOriginUrl
   , BYVAL bstrCacheUrl AS WSTRING _                    ' __in BSTR bstrCacheUrl
   , BYVAL lBandwidth AS LONG _                         ' __in long lBandwidth
   , BYVAL lQuotaLow AS LONG _                          ' __in long lQuotaLow
   , BYVAL lQuotaHigh AS LONG _                         ' __in long lQuotaHigh
   , BYVAL lBitFlags AS LONG _                          ' __in long lBitFlags
   , BYVAL pICacheProxy AS IWMSCacheProxy _             ' __in IWMSCacheProxy *pICacheProxy
   , BYVAL pIProxyContext AS IWMSProxyContext _         ' __in_opt IWMSProxyContext *pIProxyContext
   , BYVAL pCallback AS IWMSCacheProxyServerCallback _  ' __in_opt IWMSCacheProxyServerCallback *pCallback
   , BYVAL varContext AS VARIANT _                      ' __in_opt VARIANT varContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CancelDownloadContent ( _                     ' VTable offset = 24
     BYVAL pArchiveContext AS IWMSContext _             ' __in IWMSContext *pArchiveContext
   , BYVAL pCallback AS IWMSCacheProxyServerCallback _  ' __in_opt IWMSCacheProxyServerCallback *pCallback
   , BYVAL varContext AS VARIANT _                      ' __in_opt VARIANT varContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWMSCacheProxyServer_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IWMSCacheProxyServerCallback
' IID = {68F2A551-D815-11D2-BEF6-00A0C95EC343}
' Contains methods that enable a cache / proxy plug-in to respond to calls that the server makes through the IWMSCacheProxyServer interface. This interface is implemented by a cache / proxy plug-in and called by the server.
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IWMSCacheProxyServerCallback_INTERFACE_DEFINED)
    %IWMSCacheProxyServerCallback_INTERFACE_DEFINED = 1

INTERFACE IWMSCacheProxyServerCallback $IID_IWMSCacheProxyServerCallback

   INHERIT IUnknown

   ' =====================================================================================
   METHOD OnGetContentInformation ( _                   ' VTable offset = 12
     BYVAL lHr AS LONG _                                ' __in long lHr
   , BYVAL pContentInfo AS IWMSContext _                ' __in IWMSContext *pContentInfo
   , BYVAL varContext AS VARIANT _                      ' __in VARIANT varContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnCompareContentInformation ( _               ' VTable offset = 16
     BYVAL lHr AS LONG _                                ' __in long lHr
   , BYVAL CompareResponse AS LONG _                    ' __in WMS_CACHE_VERSION_COMPARE_RESPONSE CompareResponse
   , BYVAL pNewContentInfo AS IWMSContext _             ' __in IWMSContext *pNewContentInfo
   , BYVAL varContext AS VARIANT _                      ' __in VARIANT varContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnDownloadContentProgress ( _                 ' VTable offset = 20
     BYVAL lHr AS LONG _                                ' __in long lHr
   , BYVAL opCode AS LONG _                             ' __in WMS_RECORD_PROGRESS_OPCODE opCode
   , BYVAL pArchiveContext AS IWMSContext _             ' __in IWMSContext *pArchiveContext
   , BYVAL varContext AS VARIANT _                      ' __in VARIANT varContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnDownloadContentFinished ( _                 ' VTable offset = 24
     BYVAL lHr AS LONG _                                ' __in long lHr
   , BYVAL DWORD _                                      ' __in SAFEARRAY psaArchiveContexts
   , BYVAL varContext AS VARIANT _                      ' __in VARIANT varContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnCancelDownloadContent ( _                   ' VTable offset = 28
     BYVAL lHr AS LONG _                                ' __in long lHr
   , BYVAL varContext AS VARIANT _                      ' __in VARIANT varContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWMSCacheProxyServerCallback_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IWMSCacheItemDescriptor
' IID = {C3CBA330-AC05-11D2-BEF0-00A0C95EC343}
' Retrieves the size, version number, expiration date, and URL of cached content. This interface is implemented by a cache / proxy plug-in and called by the server.
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IWMSCacheItemDescriptor_INTERFACE_DEFINED)
    %IWMSCacheItemDescriptor_INTERFACE_DEFINED = 1

INTERFACE IWMSCacheItemDescriptor $IID_IWMSCacheItemDescriptor

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetOriginUrl ( _                              ' VTable offset = 12
     BYREF pbstrOriginUrl AS WSTRING _                  ' __out BSTR *pbstrOriginUrl
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCacheUrl ( _                               ' VTable offset = 16
     BYREF pbstrCacheUrl AS WSTRING _                   ' __out BSTR *pbstrCacheUrl
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetContentInformation ( _                     ' VTable offset = 20
     BYREF ppContentInfo AS IWMSContext _               ' __out IWMSContext **ppContentInfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetContentSize ( _                            ' VTable offset = 24
     BYREF plContentSizeLow AS LONG _                   ' __out long *plContentSizeLow
   , BYREF plContentSizeHigh AS LONG _                  ' __out long *plContentSizeHigh
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWMSCacheItemDescriptor_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IWMSCacheItemCollection
' IID = {E6E05D80-F45C-11D2-BEFE-00A0C95EC343}
' Contains a collection of IWMSCacheItemDescriptor objects. This interface is implemented by a cache / proxy plug-in and called by the server.
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IWMSCacheItemCollection_INTERFACE_DEFINED)
    %IWMSCacheItemCollection_INTERFACE_DEFINED = 1

INTERFACE IWMSCacheItemCollection $IID_IWMSCacheItemCollection

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetCount ( _                                  ' VTable offset = 12
     BYREF plNumCacheItemDescriptors AS LONG _          ' __out long *plNumCacheItemDescriptors
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetItem ( _                                   ' VTable offset = 16
     BYVAL lIndex AS LONG _                             ' __in long lIndex
   , BYREF ppCacheItemDescriptor AS IWMSCacheItemDescriptor _ ' __out IWMSCacheItemDescriptor **ppCacheItemDescriptor
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWMSCacheItemCollection_INTERFACE_DEFINED__ */
