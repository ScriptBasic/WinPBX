' ########################################################################################
' Microsoft Windows
' File: datacontainerversion.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%DATACONTAINERVERSION_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "objidl.inc"

$IID_IWMSDataContainerVersion = GUID$("{3AE75C14-2B3A-11D2-9EF7-006097D2D7CF}")

' WMS_DATA_CONTAINER_VERSION_CACHE_FLAGS enum
%WMS_DATA_CONTAINER_VERSION_ALLOW_PROXY_CACHING    = &H1
%WMS_DATA_CONTAINER_VERSION_ALLOW_PLAYER_CACHING   = &H2
%WMS_DATA_CONTAINER_VERSION_ALLOW_STREAM_SPLITTING = &H4


' ########################################################################################
' Interface name = IWMSDataContainerVersion
' IID = {3AE75C14-2B3A-11D2-9EF7-006097D2D7CF}
' Provides methods for retrieving content version information.
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IWMSDataContainerVersion_INTERFACE_DEFINED)
    %IWMSDataContainerVersion_INTERFACE_DEFINED = 1

INTERFACE IWMSDataContainerVersion $IID_IWMSDataContainerVersion

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetLastModifiedTime ( _                       ' VTable offset = 12
     BYREF pdateLastModifiedTime AS DOUBLE _            ' __out DATE *pdateLastModifiedTime
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetLastModifiedTime ( _                       ' VTable offset = 16
     BYVAL dateLastModifiedTime AS DOUBLE _             ' __in DATE dateLastModifiedTime
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetExpirationTime ( _                         ' VTable offset = 20
     BYREF pdateExpirationTime AS DOUBLE _              ' __out DATE *pdateExpirationTime
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetExpirationTime ( _                         ' VTable offset = 24
     BYVAL dateExpirationTime AS DOUBLE _               ' __in DATE dateExpirationTime
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCacheFlags ( _                             ' VTable offset = 28
     BYREF plFlags AS LONG _                            ' __out long *plFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetCacheFlags ( _                             ' VTable offset = 32
     BYVAL lFlags AS LONG _                             ' __in long lFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetContentSize ( _                            ' VTable offset = 36
     BYREF plContentSizeLow AS LONG _                   ' __out long *plContentSizeLow
   , BYREF plContentSizeHigh AS LONG _                  ' __out long *plContentSizeHigh
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetContentSize ( _                            ' VTable offset = 40
     BYVAL lContentSizeLow AS LONG _                    ' __in long lContentSizeLow
   , BYVAL lContentSizeHigh AS LONG _                   ' __in long lContentSizeHigh
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetEntityTagCount ( _                         ' VTable offset = 44
     BYREF plNumEntityTags AS LONG _                    ' __out long *plNumEntityTags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetEntityTag ( _                              ' VTable offset = 48
     BYVAL lTagNum AS LONG _                            ' __in long lTagNum
   , BYREF pszEntityTag AS WSTRING _                    ' __out BSTR *pszEntityTag
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetEntityTag ( _                              ' VTable offset = 52
     BYVAL szEntityTag AS WSTRING _                     ' __in BSTR szEntityTag
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Compare ( _                                   ' VTable offset = 56
     BYVAL pVersion AS IWMSDataContainerVersion _       ' __in IWMSDataContainerVersion *pVersion
   , BYREF pvfEqual AS INTEGER _                        ' __out VARIANT_BOOL *pvfEqual
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWMSDataContainerVersion_INTERFACE_DEFINED__ */
