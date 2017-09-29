' ########################################################################################
' Microsoft Windows
' File: SearchAPI.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

' ########################################################################################
' Library name: SearchAPILib
' Version: 1.0, Locale ID = 0
' Library GUID: {00000000-0000-0000-0000-000000000000}
' ########################################################################################

#INCLUDE THIS ONCE
%SEARCHAPI_INC = 1

' /* header files for imported files */
#INCLUDE ONCE "unknwn.inc"
#INCLUDE ONCE "objidl.inc"
#INCLUDE ONCE "ocidl.inc"
#INCLUDE ONCE "propidl.inc"
#INCLUDE ONCE "filter.inc"
#INCLUDE ONCE "filterreg.inc"
#INCLUDE ONCE "propsys.inc"
#INCLUDE ONCE "oledb.inc"
#INCLUDE ONCE "StructuredQuery.inc"

'typedef LONG ITEMID;

' ========================================================================================
' ProgIDs (Program identifiers)
' ========================================================================================

' CLSID = {9E175B8D-F52A-11D8-B9A5-505054503030}
$PROGID_FilterRegistration1 = "Search.FilterRegistration.1"

' ========================================================================================
' ClsIDs (Class identifiers)
' ========================================================================================

$CLSID_CSearchLanguageSupport = GUID$("{6A68CC80-4337-4DBC-BD27-FBFB1053820B}")
$CLSID_CSearchManager = GUID$("{7D096C5F-AC08-4F1F-BEB7-5C22C517CE39}")
$CLSID_CSearchRoot = GUID$("{30766BD2-EA1C-4F28-BF27-0B44E2F68DB7}")
$CLSID_CSearchScopeRule = GUID$("{E63DE750-3BD7-4BE5-9C84-6B4281988C44}")
$CLSID_FilterRegistration = GUID$("{9E175B8D-F52A-11D8-B9A5-505054503030}")

' Included in the Windows Server 2008 SDK, but not in the Windows 7 SDK
'$CLSID_CSearchCatalogManager = GUID$("{AAB49DD5-AD0B-40AE-B654-AE8976BF6BD2}")
'$CLSID_CSearchQueryHelper = GUID$("{B271E955-09E1-42E1-9B95-5994A534B613}")
'$CLSID_CSearchItemsChangedSink = GUID$("{A5270F6C-19EC-4E17-9EA1-A7074276B9B9}")
'$CLSID_CSearchCrawlScopeManager = GUID$("{321069D2-2D7A-4AA1-9DC3-BA97CDF9AFB4}")
'$CLSID_CEnumSearchRoots = GUID$("{C188CDBA-53E5-4767-9FFB-FAFBD8017DF0}")
'$CLSID_CEnumSearchScopeRules = GUID$("{3379F9F7-F805-4827-9CF6-03DB41F297DA}")
'$CLSID_CSearchPersistentItemsChangedSink = GUID$("{D0F268B5-EA7A-4B35-BF2F-E1A091B80D51}")

' ========================================================================================
' IIDs (Interface identifiers)
' ========================================================================================

$IID_IUrlAccessor = GUID$("{0B63E318-9CCC-11D0-BCDB-00805FCCCE04}")
$IID_IUrlAccessor2 = GUID$("{C7310734-AC80-11D1-8DF3-00C04FB6EF4F}")
$IID_IUrlAccessor3 = GUID$("{6FBC7005-0455-4874-B8FF-7439450241A3}")
$IID_IUrlAccessor4 = GUID$("{5CC51041-C8D2-41D7-BCA3-9E9E286297DC}")
$IID_IOpLockStatus = GUID$("{C731065D-AC80-11D1-8DF3-00C04FB6EF4F}")
$IID_ISearchProtocolThreadContext = GUID$("{C73106E1-AC80-11D1-8DF3-00C04FB6EF4F}")
$IID_ISearchProtocol = GUID$("{C73106BA-AC80-11D1-8DF3-00C04FB6EF4F}")
$IID_ISearchProtocol2 = GUID$("{7789F0B2-B5B2-4722-8B65-5DBD150697A9}")
$IID_IProtocolHandlerSite = GUID$("{0B63E385-9CCC-11D0-BCDB-00805FCCCE04}")
$IID_ISearchRoot = GUID$("{04C18CCF-1F57-4CBD-88CC-3900F5195CE3}")
$IID_IEnumSearchRoots = GUID$("{AB310581-AC80-11D1-8DF3-00C04FB6EF52}")
$IID_ISearchScopeRule = GUID$("{AB310581-AC80-11D1-8DF3-00C04FB6EF53}")
$IID_IEnumSearchScopeRules = GUID$("{AB310581-AC80-11D1-8DF3-00C04FB6EF54}")
$IID_ISearchCrawlScopeManager = GUID$("{AB310581-AC80-11D1-8DF3-00C04FB6EF55}")
$IID_ISearchCrawlScopeManager2 = GUID$("{6292F7AD-4E19-4717-A534-8FC22BCD5CCD}")
$IID_ISearchItemsChangedSink = GUID$("{AB310581-AC80-11D1-8DF3-00C04FB6EF58}")
$IID_ISearchPersistentItemsChangedSink = GUID$("{A2FFDF9B-4758-4F84-B729-DF81A1A0612F}")
$IID_ISearchViewChangedSink = GUID$("{AB310581-AC80-11D1-8DF3-00C04FB6EF65}")
$IID_IGatherNotifyInline = GUID$("{7900F4F4-BA3F-4D53-8744-51626542351A}")
$IID_ISearchNotifyInlineSite = GUID$("{B5702E61-E75C-4B64-82A1-6CB4F832FCCF}")
$IID_IGatherNotifyInlineInternal = GUID$("{2E5C2EC6-4FF9-44B7-9869-6AF9A8D3FD67}")
$IID_IGatherInlineStatus = GUID$("{2137B63B-BBB0-4BEE-94B3-4691CCEF389A}")
$IID_ISearchCatalogManager = GUID$("{AB310581-AC80-11D1-8DF3-00C04FB6EF50}")
$IID_ISearchCatalogManager2 = GUID$("{7AC3286D-4D1D-4817-84FC-C1C85E3AF0D9}")
$IID_ISearchQueryHelper = GUID$("{AB310581-AC80-11D1-8DF3-00C04FB6EF63}")
$IID_IRowsetPrioritization = GUID$("{42811652-079D-481B-87A2-09A69ECC5F44}")
$IID_IRowsetEvents = GUID$("{1551AEA5-5D66-4B11-86F5-D5634CB211B9}")
$IID_ISearchManager = GUID$("{AB310581-AC80-11D1-8DF3-00C04FB6EF69}")
$IID_ISearchLanguageSupport = GUID$("{24C3CBAA-EBC1-491A-9EF1-9F6D8DEB1B8F}")

' ########################################################################################
' IUrlAccessor interface
' IID = 0B63E318-9CCC-11D0-BCDB-00805FCCCE04
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IUrlAccessor_INTERFACE_DEFINED)
    %IUrlAccessor_INTERFACE_DEFINED = 1

INTERFACE IUrlAccessor $IID_IUrlAccessor

   INHERIT IUnknown

   ' =====================================================================================
   METHOD AddRequestParameter ( _                       ' VTable offset = 12
     BYREF pSpec AS PROPSPEC _                          ' __in PROPSPEC *pSpec
   , BYREF pVar AS PROPVARIANT _                        ' __in PROPVARIANT *pVar
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDocFormat ( _                              ' VTable offset = 16
     BYREF wszDocFormat AS WSTRINGZ _                   ' __out WCHAR wszDocFormat[  ]
   , BYVAL dwSize AS DWORD _                            ' __in DWORD dwSize
   , BYREF pdwLength AS DWORD _                         ' __out DWORD *pdwLength
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCLSID ( _                                  ' VTable offset = 20
     BYREF pClsid AS GUID _                             ' __out CLSID *pClsid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetHost ( _                                   ' VTable offset = 24
     BYREF wszHost AS WSTRINGZ _                        ' __out WCHAR wszHost[  ]
   , BYVAL dwSize AS DWORD _                            ' __in DWORD dwSize
   , BYREF pdwLength AS DWORD _                         ' __out DWORD *pdwLength
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsDirectory ( _                               ' VTable offset = 28
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSize ( _                                   ' VTable offset = 32
     BYREF pllSize AS QUAD _                            ' __out ULONGLONG *pllSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetLastModified ( _                           ' VTable offset = 36
     BYREF pftLastModified AS FILETIME _                ' __out FILETIME *pftLastModified
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFileName ( _                               ' VTable offset = 40
     BYREF wszFileName AS WSTRINGZ _                    ' __out WCHAR wszFileName[  ]
   , BYVAL dwSize AS DWORD _                            ' __in DWORD dwSize
   , BYREF pdwLength AS DWORD _                         ' __out DWORD *pdwLength
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSecurityDescriptor ( _                     ' VTable offset = 44
     BYVAL pSD AS BYTE PTR _                            ' __out BYTE *pSD
   , BYVAL dwSize AS DWORD _                            ' __in DWORD dwSize
   , BYREF pdwLength AS DWORD _                         ' __out DWORD *pdwLength
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRedirectedURL ( _                          ' VTable offset = 48
     BYREF wszRedirectedURL AS WSTRINGZ _               ' __out WCHAR wszRedirectedURL[  ]
   , BYVAL dwSize AS DWORD _                            ' __in DWORD dwSize
   , BYREF pdwLength AS DWORD _                         ' __out DWORD *pdwLength
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSecurityProvider ( _                       ' VTable offset = 52
     BYREF pSPClsid AS GUID _                           ' __out CLSID *pSPClsid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD BindToStream ( _                              ' VTable offset = 56
     BYREF ppStream AS IStream _                        ' __out IStream **ppStream
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD BindToFilter ( _                              ' VTable offset = 60
     BYREF ppFilter AS IFilter _                        ' __out IStream **ppFilter
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IUrlAccessor_INTERFACE_DEFINED__ */

' ########################################################################################
' IUrlAccessor2 interface
' IID = C7310734-AC80-11D1-8DF3-00C04FB6EF4F
' Inherited interface = IUrlAccessor
' ########################################################################################

#IF NOT %DEF(%IUrlAccessor2_INTERFACE_DEFINED)
    %IUrlAccessor2_INTERFACE_DEFINED = 1

INTERFACE IUrlAccessor2 $IID_IUrlAccessor2

   INHERIT IUnknown

   ' =====================================================================================
   ' IUrlAccessor Methods
   ' =====================================================================================
   METHOD AddRequestParameter ( _                       ' VTable offset = 12
     BYREF pSpec AS PROPSPEC _                          ' __in PROPSPEC *pSpec
   , BYREF pVar AS PROPVARIANT _                        ' __in PROPVARIANT *pVar
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDocFormat ( _                              ' VTable offset = 16
     BYREF wszDocFormat AS WSTRINGZ _                   ' __out WCHAR wszDocFormat[  ]
   , BYVAL dwSize AS DWORD _                            ' __in DWORD dwSize
   , BYREF pdwLength AS DWORD _                         ' __out DWORD *pdwLength
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCLSID ( _                                  ' VTable offset = 20
     BYREF pClsid AS GUID _                             ' __out CLSID *pClsid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetHost ( _                                   ' VTable offset = 24
     BYREF wszHost AS WSTRINGZ _                        ' __out WCHAR wszHost[  ]
   , BYVAL dwSize AS DWORD _                            ' __in DWORD dwSize
   , BYREF pdwLength AS DWORD _                         ' __out DWORD *pdwLength
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsDirectory ( _                               ' VTable offset = 28
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSize ( _                                   ' VTable offset = 32
     BYREF pllSize AS QUAD _                            ' __out ULONGLONG *pllSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetLastModified ( _                           ' VTable offset = 36
     BYREF pftLastModified AS FILETIME _                ' __out FILETIME *pftLastModified
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFileName ( _                               ' VTable offset = 40
     BYREF wszFileName AS WSTRINGZ _                    ' __out WCHAR wszFileName[  ]
   , BYVAL dwSize AS DWORD _                            ' __in DWORD dwSize
   , BYREF pdwLength AS DWORD _                         ' __out DWORD *pdwLength
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSecurityDescriptor ( _                     ' VTable offset = 44
     BYVAL pSD AS BYTE PTR _                            ' __out BYTE *pSD
   , BYVAL dwSize AS DWORD _                            ' __in DWORD dwSize
   , BYREF pdwLength AS DWORD _                         ' __out DWORD *pdwLength
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRedirectedURL ( _                          ' VTable offset = 48
     BYREF wszRedirectedURL AS WSTRINGZ _               ' __out WCHAR wszRedirectedURL[  ]
   , BYVAL dwSize AS DWORD _                            ' __in DWORD dwSize
   , BYREF pdwLength AS DWORD _                         ' __out DWORD *pdwLength
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSecurityProvider ( _                       ' VTable offset = 52
     BYREF pSPClsid AS GUID _                           ' __out CLSID *pSPClsid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD BindToStream ( _                              ' VTable offset = 56
     BYREF ppStream AS IStream _                        ' __out IStream **ppStream
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD BindToFilter ( _                              ' VTable offset = 60
     BYREF ppFilter AS IFilter _                        ' __out IStream **ppFilter
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IUrlAccessor2 Methods
   ' =====================================================================================
   METHOD GetDisplayUrl ( _                             ' VTable offset = 64
     BYREF wszDocUrl AS WSTRINGZ _                      ' __out WCHAR wszDocUrl[  ]
   , BYVAL dwSize AS DWORD _                            ' __in DWORD dwSize
   , BYREF pdwLength AS DWORD _                         ' __out DWORD *pdwLength
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsDocument ( _                                ' VTable offset = 68
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCodePage ( _                               ' VTable offset = 72
     BYREF wszCodePage AS WSTRINGZ _                    ' __out WCHAR wszCodePage[  ]
   , BYVAL dwSize AS DWORD _                            ' __in DWORD dwSize
   , BYREF pdwLength AS DWORD _                         ' __out DWORD *pdwLength
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IUrlAccessor2_INTERFACE_DEFINED__ */

' ########################################################################################
' IUrlAccessor3 interface
' IID = 6FBC7005-0455-4874-B8FF-7439450241A3
' Inherited interface = IUrlAccessor2
' ########################################################################################

#IF NOT %DEF(%IUrlAccessor3_INTERFACE_DEFINED)
    %IUrlAccessor3_INTERFACE_DEFINED = 1

INTERFACE IUrlAccessor3 $IID_IUrlAccessor3

   INHERIT IUnknown

   ' =====================================================================================
   ' IUrlAccessor Methods
   ' =====================================================================================
   METHOD AddRequestParameter ( _                       ' VTable offset = 12
     BYREF pSpec AS PROPSPEC _                          ' __in PROPSPEC *pSpec
   , BYREF pVar AS PROPVARIANT _                        ' __in PROPVARIANT *pVar
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDocFormat ( _                              ' VTable offset = 16
     BYREF wszDocFormat AS WSTRINGZ _                   ' __out WCHAR wszDocFormat[  ]
   , BYVAL dwSize AS DWORD _                            ' __in DWORD dwSize
   , BYREF pdwLength AS DWORD _                         ' __out DWORD *pdwLength
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCLSID ( _                                  ' VTable offset = 20
     BYREF pClsid AS GUID _                             ' __out CLSID *pClsid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetHost ( _                                   ' VTable offset = 24
     BYREF wszHost AS WSTRINGZ _                        ' __out WCHAR wszHost[  ]
   , BYVAL dwSize AS DWORD _                            ' __in DWORD dwSize
   , BYREF pdwLength AS DWORD _                         ' __out DWORD *pdwLength
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsDirectory ( _                               ' VTable offset = 28
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSize ( _                                   ' VTable offset = 32
     BYREF pllSize AS QUAD _                            ' __out ULONGLONG *pllSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetLastModified ( _                           ' VTable offset = 36
     BYREF pftLastModified AS FILETIME _                ' __out FILETIME *pftLastModified
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFileName ( _                               ' VTable offset = 40
     BYREF wszFileName AS WSTRINGZ _                    ' __out WCHAR wszFileName[  ]
   , BYVAL dwSize AS DWORD _                            ' __in DWORD dwSize
   , BYREF pdwLength AS DWORD _                         ' __out DWORD *pdwLength
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSecurityDescriptor ( _                     ' VTable offset = 44
     BYVAL pSD AS BYTE PTR _                            ' __out BYTE *pSD
   , BYVAL dwSize AS DWORD _                            ' __in DWORD dwSize
   , BYREF pdwLength AS DWORD _                         ' __out DWORD *pdwLength
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRedirectedURL ( _                          ' VTable offset = 48
     BYREF wszRedirectedURL AS WSTRINGZ _               ' __out WCHAR wszRedirectedURL[  ]
   , BYVAL dwSize AS DWORD _                            ' __in DWORD dwSize
   , BYREF pdwLength AS DWORD _                         ' __out DWORD *pdwLength
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSecurityProvider ( _                       ' VTable offset = 52
     BYREF pSPClsid AS GUID _                           ' __out CLSID *pSPClsid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD BindToStream ( _                              ' VTable offset = 56
     BYREF ppStream AS IStream _                        ' __out IStream **ppStream
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD BindToFilter ( _                              ' VTable offset = 60
     BYREF ppFilter AS IFilter _                        ' __out IStream **ppFilter
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IUrlAccessor2 Methods
   ' =====================================================================================
   METHOD GetDisplayUrl ( _                             ' VTable offset = 64
     BYREF wszDocUrl AS WSTRINGZ _                      ' __out WCHAR wszDocUrl[  ]
   , BYVAL dwSize AS DWORD _                            ' __in DWORD dwSize
   , BYREF pdwLength AS DWORD _                         ' __out DWORD *pdwLength
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsDocument ( _                                ' VTable offset = 68
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCodePage ( _                               ' VTable offset = 72
     BYREF wszCodePage AS WSTRINGZ _                    ' __out WCHAR wszCodePage[  ]
   , BYVAL dwSize AS DWORD _                            ' __in DWORD dwSize
   , BYREF pdwLength AS DWORD _                         ' __out DWORD *pdwLength
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IUrlAccessor3 Methods
   ' =====================================================================================
   METHOD GetImpersonationSidBlobs ( _                  ' VTable offset = 76
     BYREF pcwszURL AS WSTRINGZ _                       ' __in LPCWSTR pcwszURL
   , BYREF pcSidCount AS DWORD _                        ' __out DWORD *pcSidCount
   , BYREF ppSidBlobs AS BLOB _                         ' __out BLOB **ppSidBlobs
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IUrlAccessor3_INTERFACE_DEFINED__ */

' ########################################################################################
' IUrlAccessor4 interface
' IID = 5CC51041-C8D2-41D7-BCA3-9E9E286297DC
' Inherited interface = IUrlAccessor3
' ########################################################################################

#IF NOT %DEF(%IUrlAccessor4_INTERFACE_DEFINED)
    %IUrlAccessor4_INTERFACE_DEFINED = 1

INTERFACE IUrlAccessor4 $IID_IUrlAccessor4

   INHERIT IUnknown

   ' =====================================================================================
   ' IUrlAccessor Methods
   ' =====================================================================================
   METHOD AddRequestParameter ( _                       ' VTable offset = 12
     BYREF pSpec AS PROPSPEC _                          ' __in PROPSPEC *pSpec
   , BYREF pVar AS PROPVARIANT _                        ' __in PROPVARIANT *pVar
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDocFormat ( _                              ' VTable offset = 16
     BYREF wszDocFormat AS WSTRINGZ _                   ' __out WCHAR wszDocFormat[  ]
   , BYVAL dwSize AS DWORD _                            ' __in DWORD dwSize
   , BYREF pdwLength AS DWORD _                         ' __out DWORD *pdwLength
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCLSID ( _                                  ' VTable offset = 20
     BYREF pClsid AS GUID _                             ' __out CLSID *pClsid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetHost ( _                                   ' VTable offset = 24
     BYREF wszHost AS WSTRINGZ _                        ' __out WCHAR wszHost[  ]
   , BYVAL dwSize AS DWORD _                            ' __in DWORD dwSize
   , BYREF pdwLength AS DWORD _                         ' __out DWORD *pdwLength
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsDirectory ( _                               ' VTable offset = 28
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSize ( _                                   ' VTable offset = 32
     BYREF pllSize AS QUAD _                            ' __out ULONGLONG *pllSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetLastModified ( _                           ' VTable offset = 36
     BYREF pftLastModified AS FILETIME _                ' __out FILETIME *pftLastModified
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFileName ( _                               ' VTable offset = 40
     BYREF wszFileName AS WSTRINGZ _                    ' __out WCHAR wszFileName[  ]
   , BYVAL dwSize AS DWORD _                            ' __in DWORD dwSize
   , BYREF pdwLength AS DWORD _                         ' __out DWORD *pdwLength
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSecurityDescriptor ( _                     ' VTable offset = 44
     BYVAL pSD AS BYTE PTR _                            ' __out BYTE *pSD
   , BYVAL dwSize AS DWORD _                            ' __in DWORD dwSize
   , BYREF pdwLength AS DWORD _                         ' __out DWORD *pdwLength
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRedirectedURL ( _                          ' VTable offset = 48
     BYREF wszRedirectedURL AS WSTRINGZ _               ' __out WCHAR wszRedirectedURL[  ]
   , BYVAL dwSize AS DWORD _                            ' __in DWORD dwSize
   , BYREF pdwLength AS DWORD _                         ' __out DWORD *pdwLength
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSecurityProvider ( _                       ' VTable offset = 52
     BYREF pSPClsid AS GUID _                           ' __out CLSID *pSPClsid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD BindToStream ( _                              ' VTable offset = 56
     BYREF ppStream AS IStream _                        ' __out IStream **ppStream
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD BindToFilter ( _                              ' VTable offset = 60
     BYREF ppFilter AS IFilter _                        ' __out IStream **ppFilter
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IUrlAccessor2 Methods
   ' =====================================================================================
   METHOD GetDisplayUrl ( _                             ' VTable offset = 64
     BYREF wszDocUrl AS WSTRINGZ _                      ' __out WCHAR wszDocUrl[  ]
   , BYVAL dwSize AS DWORD _                            ' __in DWORD dwSize
   , BYREF pdwLength AS DWORD _                         ' __out DWORD *pdwLength
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsDocument ( _                                ' VTable offset = 68
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCodePage ( _                               ' VTable offset = 72
     BYREF wszCodePage AS WSTRINGZ _                    ' __out WCHAR wszCodePage[  ]
   , BYVAL dwSize AS DWORD _                            ' __in DWORD dwSize
   , BYREF pdwLength AS DWORD _                         ' __out DWORD *pdwLength
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IUrlAccessor3 Methods
   ' =====================================================================================
   METHOD GetImpersonationSidBlobs ( _                  ' VTable offset = 76
     BYREF pcwszURL AS WSTRINGZ _                       ' __in LPCWSTR pcwszURL
   , BYREF pcSidCount AS DWORD _                        ' __out DWORD *pcSidCount
   , BYREF ppSidBlobs AS BLOB _                         ' __out BLOB **ppSidBlobs
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IUrlAccessor4 Methods
   ' =====================================================================================
   METHOD ShouldIndexItemContent ( _                    ' VTable offset = 80
     BYREF pfIndexContent AS DWORD _                    ' __out BOOL *pfIndexContent
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ShouldIndexProperty ( _                       ' VTable offset = 84
     BYREF key AS PROPERTYKEY _                         ' __in REFPROPERTYKEY key
   , BYREF pfIndexProperty AS LONG _                    ' __out BOOL *pfIndexProperty
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IUrlAccessor4_INTERFACE_DEFINED__ */

' ########################################################################################
' IOpLockStatus interface
' IID = C731065D-AC80-11D1-8DF3-00C04FB6EF4F
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IOpLockStatus_INTERFACE_DEFINED)
    %IOpLockStatus_INTERFACE_DEFINED = 1

INTERFACE IOpLockStatus $IID_IOpLockStatus

   INHERIT IUnknown

   ' =====================================================================================
   METHOD IsOplockValid ( _                             ' VTable offset = 12
     BYREF pfIsOplockValid AS LONG _                    ' __out BOOL *pfIsOplockValid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsOplockBroken ( _                            ' VTable offset = 16
     BYREF pfIsOplockBroken AS LONG _                   ' __out BOOL *pfIsOplockBroken
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetOplockEventHandle ( _                      ' VTable offset = 20
     BYREF phOplockEv AS DWORD _                        ' __out HANDLE *phOplockEv
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IOpLockStatus_INTERFACE_DEFINED__ */

' ########################################################################################
' ISearchProtocolThreadContext interface
' IID = C73106E1-AC80-11D1-8DF3-00C04FB6EF4F
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ISearchProtocolThreadContext_INTERFACE_DEFINED)
    %ISearchProtocolThreadContext_INTERFACE_DEFINED = 1

INTERFACE ISearchProtocolThreadContext $IID_ISearchProtocolThreadContext

   INHERIT IUnknown

   ' =====================================================================================
   METHOD ThreadInit ( _                                ' VTable offset = 12
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ThreadShutdown ( _                            ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ThreadIdle ( _                                ' VTable offset = 20
     BYVAL dwTimeElaspedSinceLastCallInMS AS DWORD _    ' __in DWORD dwTimeElaspedSinceLastCallInMS
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISearchProtocolThreadContext_INTERFACE_DEFINED__ */


'#pragma pack(8)
' // Size = 12 bytes
TYPE TIMEOUT_INFO DWORD
   dwSize           AS DWORD   ' DWORD
   dwConnectTimeout AS DWORD   ' DWORD
   dwDataTimeout    AS DWORD   ' DWORD
END TYPE

' enum PROXY_ACCESS
%PROXY_ACCESS_PRECONFIG = 0
%PROXY_ACCESS_DIRECT    = %PROXY_ACCESS_PRECONFIG + 1
%PROXY_ACCESS_PROXY     = %PROXY_ACCESS_DIRECT + 1

' // Size = 28 bytes
TYPE PROXY_INFO DWORD
   dwSize          AS DWORD          ' DWORD
   pcwszUserAgent  AS WSTRINGZ PTR   ' LPCWSTR
   paUseProxy      AS LONG           ' PROXY_ACCESS
   fLocalBypass    AS LONG           ' BOOL
   dwPortNumber    AS DWORD          ' DWORD
   pcwszProxyName  AS WSTRINGZ PTR   ' LPCWSTR
   pcwszBypassList AS WSTRINGZ PTR   ' LPCWSTR
END TYPE

' enum AUTH_TYPE
%eAUTH_TYPE_ANONYMOUS = 0
%eAUTH_TYPE_NTLM      = %eAUTH_TYPE_ANONYMOUS + 1
%eAUTH_TYPE_BASIC     = %eAUTH_TYPE_NTLM      + 1

' // Size = 16 bytes
TYPE AUTHENTICATION_INFO DWORD
   dwSize               AS DWORD          ' DWORD
   atAuthenticationType AS LONG           ' AUTH_TYPE
   pcwszUser            AS WSTRINGZ PTR   ' LPCWSTR
   pcwszPassword        AS WSTRINGZ PTR   ' LPCWSTR
END TYPE

' // Size = 12 bytes
TYPE INCREMENTAL_ACCESS_INFO DWORD
   dwSize             AS DWORD      ' DWORD
   ftLastModifiedTime AS FILETIME   ' FILETIME
END TYPE

' // Size = 20 bytes
TYPE ITEM_INFO DWORD
   dwSize               AS DWORD          ' DWORD
   pcwszFromEMail       AS WSTRINGZ PTR   ' LPCWSTR
   pcwszApplicationName AS WSTRINGZ PTR   ' LPCWSTR
   pcwszCatalogName     AS WSTRINGZ PTR   ' LPCWSTR
   pcwszContentClass    AS WSTRINGZ PTR   ' LPCWSTR
END TYPE

' ########################################################################################
' ISearchProtocol interface
' IID = C73106BA-AC80-11D1-8DF3-00C04FB6EF4F
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ISearchProtocol_INTERFACE_DEFINED)
    %ISearchProtocol_INTERFACE_DEFINED = 1

INTERFACE ISearchProtocol $IID_ISearchProtocol

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Init ( _                                      ' VTable offset = 12
     BYREF pTimeoutInfo AS TIMEOUT_INFO _               ' __in TIMEOUT_INFO *pTimeoutInfo
   , BYVAL pProtocolHandlerSite AS IProtocolHandlerSite _ ' __in IProtocolHandlerSite *pProtocolHandlerSite
   , BYREF pProxyInfo AS PROXY_INFO _                   ' __in PROXY_INFO *pProxyInfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateAccessor ( _                            ' VTable offset = 16
     BYREF pcwszURL AS WSTRINGZ _                       ' __in LPCWSTR pcwszURL
   , BYREF pAuthenticationInfo AS AUTHENTICATION_INFO _ ' __in AUTHENTICATION_INFO *pAuthenticationInfo
   , BYREF pIncrementalAccessInfo AS INCREMENTAL_ACCESS_INFO _ ' __in INCREMENTAL_ACCESS_INFO *pIncrementalAccessInfo
   , BYREF pItemInfo AS ITEM_INFO _                     ' __in ITEM_INFO *pItemInfo
   , BYREF ppAccessor AS IUrlAccessor _                 ' __out IUrlAccessor **ppAccessor
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CloseAccessor ( _                             ' VTable offset = 20
     BYVAL pAccessor AS IUrlAccessor _                  ' __in IUrlAccessor *pAccessor
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ShutDown ( _                                  ' VTable offset = 24
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISearchProtocol_INTERFACE_DEFINED__ */

' ########################################################################################
' ISearchProtocol2 interface
' IID = 7789F0B2-B5B2-4722-8B65-5DBD150697A9
' Inherited interface = ISearchProtocol
' ########################################################################################

#IF NOT %DEF(%ISearchProtocol2_INTERFACE_DEFINED)
    %ISearchProtocol2_INTERFACE_DEFINED = 1

INTERFACE ISearchProtocol2 $IID_ISearchProtocol2

   INHERIT IUnknown

   ' =====================================================================================
   ' ISearchProtocol Methods
   ' =====================================================================================
   METHOD Init ( _                                      ' VTable offset = 12
     BYREF pTimeoutInfo AS TIMEOUT_INFO _               ' __in TIMEOUT_INFO *pTimeoutInfo
   , BYVAL pProtocolHandlerSite AS IProtocolHandlerSite _ ' __in IProtocolHandlerSite *pProtocolHandlerSite
   , BYREF pProxyInfo AS PROXY_INFO _                   ' __in PROXY_INFO *pProxyInfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateAccessor ( _                            ' VTable offset = 16
     BYREF pcwszURL AS WSTRINGZ _                       ' __in LPCWSTR pcwszURL
   , BYREF pAuthenticationInfo AS AUTHENTICATION_INFO _ ' __in AUTHENTICATION_INFO *pAuthenticationInfo
   , BYREF pIncrementalAccessInfo AS INCREMENTAL_ACCESS_INFO _ ' __in INCREMENTAL_ACCESS_INFO *pIncrementalAccessInfo
   , BYREF pItemInfo AS ITEM_INFO _                     ' __in ITEM_INFO *pItemInfo
   , BYREF ppAccessor AS IUrlAccessor _                 ' __out IUrlAccessor **ppAccessor
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CloseAccessor ( _                             ' VTable offset = 20
     BYVAL pAccessor AS IUrlAccessor _                  ' __in IUrlAccessor *pAccessor
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ShutDown ( _                                  ' VTable offset = 24
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' CreateAccessorEx Methods
   ' =====================================================================================
   METHOD CreateAccessorEx ( _                          ' VTable offset = 28
     BYREF pcwszURL AS WSTRINGZ _                       ' __in LPCWSTR pcwszURL
   , BYREF pAuthenticationInfo AS AUTHENTICATION_INFO _ ' __in AUTHENTICATION_INFO *pAuthenticationInfo
   , BYREF pIncrementalAccessInfo AS INCREMENTAL_ACCESS_INFO _ ' __in INCREMENTAL_ACCESS_INFO *pIncrementalAccessInfo
   , BYREF pItemInfo AS ITEM_INFO _                     ' __in ITEM_INFO *pItemInfo
   , BYREF pUserData AS BLOB _                          ' __in const BLOB *pUserData
   , BYREF ppAccessor AS IUrlAccessor _                 ' __out IUrlAccessor **ppAccessor
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISearchProtocol2_INTERFACE_DEFINED__ */

' ########################################################################################
' IProtocolHandlerSite interface
' IID = 0B63E385-9CCC-11D0-BCDB-00805FCCCE04
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IProtocolHandlerSite_INTERFACE_DEFINED)
    %IProtocolHandlerSite_INTERFACE_DEFINED = 1

INTERFACE IProtocolHandlerSite $IID_IProtocolHandlerSite

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetFilter ( _                                 ' VTable offset = 12
     BYREF pclsidObj AS GUID _                          ' __in CLSID *pclsidObj
   , BYREF pcwszContentType AS WSTRINGZ _               ' __in LPCWSTR pcwszContentType
   , BYREF pcwszExtension AS WSTRINGZ _                 ' __in LPCWSTR pcwszExtension
   , BYREF ppFilter AS IFilter _                        ' __out IFilter **ppFilter
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IProtocolHandlerSite_INTERFACE_DEFINED__ */

' ########################################################################################
' IProtocolHandlerServices interface
' IID = C9FCD6B1-8B41-4D4D-8E65-4A33FBAD8DE0
' Inherited interface = IProtocolHandlerSite
' Note: This interface is not implemented.
' ########################################################################################

'#IF NOT %DEF(%IProtocolHandlerServices_INTERFACE_DEFINED)
'    %IProtocolHandlerServices_INTERFACE_DEFINED = 1

'$IID_IProtocolHandlerServices = GUID$("{C9FCD6B1-8B41-4D4D-8E65-4A33FBAD8DE0}")

'INTERFACE IProtocolHandlerServices $IID_IProtocolHandlerServices

'   INHERIT IUnknown

'   ' =====================================================================================
'   ' IProtocolHandlerSite Method
'   ' =====================================================================================
'   METHOD GetFilter ( _                                 ' VTable offset = 12
'     BYREF pclsidObj AS GUID _                          ' __in CLSID *pclsidObj
'   , BYREF pcwszContentType AS WSTRINGZ _               ' __in LPCWSTR pcwszContentType
'   , BYREF pcwszExtension AS WSTRINGZ _                 ' __in LPCWSTR pcwszExtension
'   , BYREF ppFilter AS IFilter _                        ' __out IFilter **ppFilter
'   ) AS LONG                                            ' HRESULT
'   ' =====================================================================================

'   ' =====================================================================================
'   ' IProtocolHandlerServices Method
'   ' =====================================================================================
'   METHOD CreateAccessor ( _                            ' VTable offset = 16
'     BYREF url AS WSTRINGZ _                            ' __in LPWSTR url
'   , BYREF ppAccessor AS IUrlAccessor _                 ' __out IUrlAccessor **ppAccessor
'   ) AS LONG                                            ' HRESULT
'   ' =====================================================================================

'END INTERFACE

'#ENDIF   ' /* __IProtocolHandlerServices_INTERFACE_DEFINED__ */

'#pragma pack()

' ########################################################################################
' ISearchRoot interface
' IID = 04C18CCF-1F57-4CBD-88CC-3900F5195CE3
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ISearchRoot_INTERFACE_DEFINED)
    %ISearchRoot_INTERFACE_DEFINED = 1

INTERFACE ISearchRoot $IID_ISearchRoot

   INHERIT IUnknown

   ' =====================================================================================
   METHOD put_Schedule ( _                              ' VTable offset = 12
     BYREF pszTaskArg AS WSTRINGZ _                     ' __in LPCWSTR pszTaskArg
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_Schedule ( _                              ' VTable offset = 16
     BYREF ppszTaskArg AS DWORD _                       ' __out LPWSTR *ppszTaskArg
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_RootURL ( _                               ' VTable offset = 20
     BYREF pszURL AS WSTRINGZ _                         ' __in LPCWSTR pszURL
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_RootURL ( _                               ' VTable offset = 24
     BYREF ppszURL AS WSTRINGZ _                        ' __in LPWSTR ppszURL
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_IsHierarchical ( _                        ' VTable offset = 28
     BYVAL fIsHierarchical AS LONG _                    ' __in BOOL fIsHierarchical
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_IsHierarchical ( _                        ' VTable offset = 32
     BYREF pfIsHierarchical AS LONG _                   ' __out BOOL *pfIsHierarchical
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_ProvidesNotifications ( _                 ' VTable offset = 36
     BYVAL fProvidesNotifications AS LONG _             ' __in BOOL fProvidesNotifications
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_ProvidesNotifications ( _                 ' VTable offset = 40
     BYREF pfProvidesNotifications AS LONG _            ' __out BOOL *pfProvidesNotifications
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_UseNotificationsOnly ( _                  ' VTable offset = 44
     BYVAL fUseNotificationsOnly AS LONG _              ' __in BOOL fUseNotificationsOnly
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_UseNotificationsOnly ( _                  ' VTable offset = 48
     BYVAL pfUseNotificationsOnly AS LONG _             ' __in BOOL pfUseNotificationsOnly
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_EnumerationDepth ( _                      ' VTable offset = 52
     BYVAL dwDepth AS DWORD _                           ' __in DWORD dwDepth
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_EnumerationDepth ( _                      ' VTable offset = 56
     BYREF pdwDepth AS DWORD _                          ' __out DWORD *pdwDepth
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_HostDepth ( _                             ' VTable offset = 60
     BYVAL dwDepth AS DWORD _                           ' __in DWORD dwDepth
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_HostDepth ( _                             ' VTable offset = 64
     BYREF pdwDepth AS DWORD _                          ' __out DWORD *pdwDepth
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_FollowDirectories ( _                     ' VTable offset = 68
     BYVAL fFollowDirectories AS LONG _                 ' __in BOOL fFollowDirectories
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_FollowDirectories ( _                     ' VTable offset = 72
     BYREF pfFollowDirectories AS LONG _                ' __out BOOL *pfFollowDirectories
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_AuthenticationType ( _                    ' VTable offset = 76
     BYVAL authType AS LONG _                           ' __in AUTH_TYPE authType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_AuthenticationType ( _                    ' VTable offset = 80
     BYREF pAuthType AS LONG _                          ' __out AUTH_TYPE *pAuthType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_User ( _                                  ' VTable offset = 84
     BYREF pszUser AS WSTRINGZ _                        ' __in LPCWSTR pszUser
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_User ( _                                  ' VTable offset = 88
     BYREF ppszUser AS DWORD _                          ' __out LPWSTR *ppszUser
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_Password ( _                              ' VTable offset = 92
     BYREF pszPassword AS WSTRINGZ _                    ' __in LPCWSTR pszPassword
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_Password ( _                              ' VTable offset = 96
     BYREF ppszPassword AS DWORD _                      ' __out LPWSTR *ppszPassword
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISearchRoot_INTERFACE_DEFINED__ */

' ########################################################################################
' IEnumSearchRoots interface
' IID = AB310581-AC80-11D1-8DF3-00C04FB6EF52
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IEnumSearchRoots_INTERFACE_DEFINED)
    %IEnumSearchRoots_INTERFACE_DEFINED = 1

INTERFACE IEnumSearchRoots $IID_IEnumSearchRoots

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Next ( _                                      ' VTable offset = 12
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   , BYREF rgelt AS ISearchRoot _                       ' __out ISearchRoot **rgelt
   , BYREF pceltFetched AS DWORD _                      ' __in_out ULONG *pceltFetched
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Skip ( _                                      ' VTable offset = 16
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reset ( _                                     ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 24
     BYREF ppenum AS IEnumSearchRoots _                 ' __out IEnumSearchRoots **ppenum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEnumSearchRoots_INTERFACE_DEFINED__ */

' enum FOLLOW_FLAGS
%FF_INDEXCOMPLEXURLS = &H1???
%FF_SUPPRESSINDEXING = &H2???

' ########################################################################################
' ISearchScopeRule interface
' IID = AB310581-AC80-11D1-8DF3-00C04FB6EF53
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ISearchScopeRule_INTERFACE_DEFINED)
    %ISearchScopeRule_INTERFACE_DEFINED = 1

INTERFACE ISearchScopeRule $IID_ISearchScopeRule

   INHERIT IUnknown

   ' =====================================================================================
   METHOD get_PatternOrURL ( _                          ' VTable offset = 12
     BYREF ppszPatternOrURL AS DWORD _                  ' __out LPWSTR *ppszPatternOrURL
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_IsIncluded ( _                            ' VTable offset = 16
     BYREF pfIsIncluded AS LONG _                       ' __out BOOL *pfIsIncluded
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_IsDefault ( _                             ' VTable offset = 20
     BYREF pfIsDefault AS LONG _                        ' __out BOOL *pfIsDefault
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_FollowFlags ( _                           ' VTable offset = 24
     BYREF pFollowFlags AS DWORD _                      ' __out DWORD *pFollowFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISearchScopeRule_INTERFACE_DEFINED__ */

' ########################################################################################
' IEnumSearchScopeRules interface
' IID = AB310581-AC80-11D1-8DF3-00C04FB6EF54
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IEnumSearchScopeRules_INTERFACE_DEFINED)
    %IEnumSearchScopeRules_INTERFACE_DEFINED = 1

INTERFACE IEnumSearchScopeRules $IID_IEnumSearchScopeRules

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Next ( _                                      ' VTable offset = 12
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   , BYREF pprgelt AS ISearchScopeRule _                ' __out ISearchScopeRule **pprgelt
   , BYREF pceltFetched AS DWORD _                      ' __in_out ULONG *pceltFetched
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Skip ( _                                      ' VTable offset = 16
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reset ( _                                     ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 24
     BYREF ppenum AS IEnumSearchScopeRules _            ' __out IEnumSearchScopeRules **ppenum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEnumSearchScopeRules_INTERFACE_DEFINED__ */

' enum CLUSION_REASON
%CLUSIONREASON_UNKNOWNSCOPE = 0
%CLUSIONREASON_DEFAULT      = 1
%CLUSIONREASON_USER         = 2
%CLUSIONREASON_GROUPPOLICY  = 3

' ########################################################################################
' ISearchCrawlScopeManager interface
' IID = AB310581-AC80-11D1-8DF3-00C04FB6EF55
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ISearchCrawlScopeManager_INTERFACE_DEFINED)
    %ISearchCrawlScopeManager_INTERFACE_DEFINED = 1

INTERFACE ISearchCrawlScopeManager $IID_ISearchCrawlScopeManager

   INHERIT IUnknown

   ' =====================================================================================
   METHOD AddDefaultScopeRule ( _                       ' VTable offset = 12
     BYREF pszURL AS WSTRINGZ _                         ' __in LPCWSTR pszURL
   , BYVAL fInclude AS LONG _                           ' __in BOOL fInclude
   , BYVAL fFollowFlags AS DWORD _                      ' __in DWORD fFollowFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddRoot ( _                                   ' VTable offset = 16
     BYVAL pSearchRoot AS ISearchRoot _                 ' __in ISearchRoot *pSearchRoot
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RemoveRoot ( _                                ' VTable offset = 20
     BYREF pszURL AS WSTRINGZ _                         ' __in LPCWSTR pszURL
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumerateRoots ( _                            ' VTable offset = 24
     BYREF ppSearchRoots AS IEnumSearchRoots _          ' __out IEnumSearchRoots **ppSearchRoots
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddHierarchicalScope ( _                      ' VTable offset = 28
     BYREF pszURL AS WSTRINGZ _                         ' __in LPCWSTR pszURL
   , BYVAL fInclude AS LONG _                           ' __in BOOL fInclude
   , BYVAL fDefault AS LONG _                           ' __in BOOL fDefault
   , BYVAL fOverrideChildren AS LONG _                  ' __in BOOL fOverrideChildren
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddUserScopeRule ( _                          ' VTable offset = 32
     BYREF pszURL AS WSTRINGZ _                         ' __in LPCWSTR pszURL
   , BYVAL fInclude AS LONG _                           ' __in BOOL fInclude
   , BYVAL fDefault AS LONG _                           ' __in BOOL fDefault
   , BYVAL fOverrideChildren AS LONG _                  ' __in BOOL fOverrideChildren
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RemoveScopeRule ( _                           ' VTable offset = 36
     BYREF pszRule AS WSTRINGZ _                        ' __in LPCWSTR pszRule
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumerateScopeRules ( _                       ' VTable offset = 40
     BYREF ppSearchScopeRules AS IEnumSearchScopeRules _ ' __out IEnumSearchScopeRules **ppSearchScopeRules
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD HasParentScopeRule ( _                        ' VTable offset = 44
     BYREF pszURL AS WSTRINGZ _                         ' __in LPCWSTR pszURL
   , BYREF pfHasParentRule AS LONG _                    ' __out BOOL *pfHasParentRule
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD HasChildScopeRule ( _                         ' VTable offset = 48
     BYREF pszURL AS WSTRINGZ _                         ' __in LPCWSTR pszURL
   , BYREF pfHasChildRule AS LONG _                     ' __out BOOL *pfHasChildRule
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IncludedInCrawlScope ( _                      ' VTable offset = 52
     BYREF pszURL AS WSTRINGZ _                         ' __in LPCWSTR pszURL
   , BYREF pfIsIncluded AS LONG _                       ' __out BOOL *pfIsIncluded
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IncludedInCrawlScopeEx ( _                    ' VTable offset = 56
     BYREF pszURL AS WSTRINGZ _                         ' __in LPCWSTR pszURL
   , BYREF pfIsIncluded AS LONG _                       ' __out BOOL *pfIsIncluded
   , BYREF pReason AS LONG _                            ' __out CLUSION_REASON *pReason
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RevertToDefaultScopes ( _                     ' VTable offset = 60
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SaveAll ( _                                   ' VTable offset = 64
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetParentScopeVersionId ( _                   ' VTable offset = 68
     BYREF pszURL AS WSTRINGZ _                         ' __in LPCWSTR pszURL
   , BYREF plScopeId AS LONG _                          ' __out BOOL *plScopeId
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RemoveDefaultScopeRule ( _                    ' VTable offset = 72
     BYREF pszURL AS WSTRINGZ _                         ' __in LPCWSTR pszURL
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISearchCrawlScopeManager_INTERFACE_DEFINED__ */

' ########################################################################################
' ISearchCrawlScopeManager2 interface
' IID = 6292F7AD-4E19-4717-A534-8FC22BCD5CCD
' Inherited interface = ISearchCrawlScopeManager
' ########################################################################################

#IF NOT %DEF(%ISearchCrawlScopeManager2_INTERFACE_DEFINED)
    %ISearchCrawlScopeManager2_INTERFACE_DEFINED = 1

INTERFACE ISearchCrawlScopeManager2 $IID_ISearchCrawlScopeManager2

   INHERIT IUnknown

   ' =====================================================================================
   ' ISearchCrawlScopeManager Methods
   ' =====================================================================================
   METHOD AddDefaultScopeRule ( _                       ' VTable offset = 12
     BYREF pszURL AS WSTRINGZ _                         ' __in LPCWSTR pszURL
   , BYVAL fInclude AS LONG _                           ' __in BOOL fInclude
   , BYVAL fFollowFlags AS DWORD _                      ' __in DWORD fFollowFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddRoot ( _                                   ' VTable offset = 16
     BYVAL pSearchRoot AS ISearchRoot _                 ' __in ISearchRoot *pSearchRoot
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RemoveRoot ( _                                ' VTable offset = 20
     BYREF pszURL AS WSTRINGZ _                         ' __in LPCWSTR pszURL
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumerateRoots ( _                            ' VTable offset = 24
     BYREF ppSearchRoots AS IEnumSearchRoots _          ' __out IEnumSearchRoots **ppSearchRoots
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddHierarchicalScope ( _                      ' VTable offset = 28
     BYREF pszURL AS WSTRINGZ _                         ' __in LPCWSTR pszURL
   , BYVAL fInclude AS LONG _                           ' __in BOOL fInclude
   , BYVAL fDefault AS LONG _                           ' __in BOOL fDefault
   , BYVAL fOverrideChildren AS LONG _                  ' __in BOOL fOverrideChildren
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddUserScopeRule ( _                          ' VTable offset = 32
     BYREF pszURL AS WSTRINGZ _                         ' __in LPCWSTR pszURL
   , BYVAL fInclude AS LONG _                           ' __in BOOL fInclude
   , BYVAL fDefault AS LONG _                           ' __in BOOL fDefault
   , BYVAL fOverrideChildren AS LONG _                  ' __in BOOL fOverrideChildren
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RemoveScopeRule ( _                           ' VTable offset = 36
     BYREF pszRule AS WSTRINGZ _                        ' __in LPCWSTR pszRule
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumerateScopeRules ( _                       ' VTable offset = 40
     BYREF ppSearchScopeRules AS IEnumSearchScopeRules _ ' __out IEnumSearchScopeRules **ppSearchScopeRules
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD HasParentScopeRule ( _                        ' VTable offset = 44
     BYREF pszURL AS WSTRINGZ _                         ' __in LPCWSTR pszURL
   , BYREF pfHasParentRule AS LONG _                    ' __out BOOL *pfHasParentRule
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD HasChildScopeRule ( _                         ' VTable offset = 48
     BYREF pszURL AS WSTRINGZ _                         ' __in LPCWSTR pszURL
   , BYREF pfHasChildRule AS LONG _                     ' __out BOOL *pfHasChildRule
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IncludedInCrawlScope ( _                      ' VTable offset = 52
     BYREF pszURL AS WSTRINGZ _                         ' __in LPCWSTR pszURL
   , BYREF pfIsIncluded AS LONG _                       ' __out BOOL *pfIsIncluded
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IncludedInCrawlScopeEx ( _                    ' VTable offset = 56
     BYREF pszURL AS WSTRINGZ _                         ' __in LPCWSTR pszURL
   , BYREF pfIsIncluded AS LONG _                       ' __out BOOL *pfIsIncluded
   , BYREF pReason AS LONG _                            ' __out CLUSION_REASON *pReason
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RevertToDefaultScopes ( _                     ' VTable offset = 60
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SaveAll ( _                                   ' VTable offset = 64
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetParentScopeVersionId ( _                   ' VTable offset = 68
     BYREF pszURL AS WSTRINGZ _                         ' __in LPCWSTR pszURL
   , BYREF plScopeId AS LONG _                          ' __out BOOL *plScopeId
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RemoveDefaultScopeRule ( _                    ' VTable offset = 72
     BYREF pszURL AS WSTRINGZ _                         ' __in LPCWSTR pszURL
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' ISearchCrawlScopeManager2 Methods
   ' =====================================================================================
   METHOD GetVersion ( _                                ' VTable offset = 76
     BYREF plVersion AS LONG _                          ' __out long **plVersion
   , BYREF phFileMapping AS DWORD _                     ' __out HANDLE *phFileMapping
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISearchCrawlScopeManager2_INTERFACE_DEFINED__ */

' enum SEARCH_KIND_OF_CHANGE
%SEARCH_CHANGE_ADD                       = 0???
%SEARCH_CHANGE_DELETE                    = 1???
%SEARCH_CHANGE_MODIFY                    = 2???
%SEARCH_CHANGE_MOVE_RENAME               = 3???
%SEARCH_CHANGE_SEMANTICS_DIRECTORY       = &H40000???
%SEARCH_CHANGE_SEMANTICS_SHALLOW         = &H80000???
%SEARCH_CHANGE_SEMANTICS_UPDATE_SECURITY = &H400000???

' enum SEARCH_NOTIFICATION_PRIORITY
%SEARCH_NORMAL_PRIORITY = 0???
%SEARCH_HIGH_PRIORITY   = 1???


' ########################################################################################
' ISearchItemsChangedSink interface
' IID = AB310581-AC80-11D1-8DF3-00C04FB6EF58
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ISearchItemsChangedSink_INTERFACE_DEFINED)
    %ISearchItemsChangedSink_INTERFACE_DEFINED = 1

' // Size = 20 bytes
TYPE SEARCH_ITEM_CHANGE DWORD
   Change      AS DWORD          ' SEARCH_KIND_OF_CHANGE
   Priority    AS DWORD          ' SEARCH_NOTIFICATION_PRIORITY
   pUserData   AS BLOB PTR       ' BLOB*
   lpwszURL    AS WSTRINGZ PTR   ' LPWSTR
   lpwszOldURL AS WSTRINGZ PTR   ' LPWSTR
END TYPE

INTERFACE ISearchItemsChangedSink $IID_ISearchItemsChangedSink

   INHERIT IUnknown

   ' =====================================================================================
   METHOD StartedMonitoringScope ( _                    ' VTable offset = 12
     BYREF pszURL AS WSTRINGZ _                         ' __in LPCWSTR pszURL
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD StoppedMonitoringScope ( _                    ' VTable offset = 16
     BYREF pszURL AS WSTRINGZ _                         ' __in LPCWSTR pszURL
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnItemsChanged ( _                            ' VTable offset = 20
     BYVAL dwNumberOfChanges AS DWORD _                 ' __in DWORD dwNumberOfChanges
   , BYREF rgDataChangeEntries AS SEARCH_ITEM_CHANGE _  ' __in SEARCH_ITEM_CHANGE rgDataChangeEntries[  ]
   , BYREF rgdwDocIds AS DWORD _                        ' __out DWORD rgdwDocIds[  ]
   , BYREF rghrCompletionCodes AS LONG _                ' __out HRESULT rghrCompletionCodes[  ]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISearchItemsChangedSink_INTERFACE_DEFINED__ */

' ########################################################################################
' ISearchPersistentItemsChangedSink interface
' IID = A2FFDF9B-4758-4F84-B729-DF81A1A0612F
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ISearchPersistentItemsChangedSink_INTERFACE_DEFINED)
    %ISearchPersistentItemsChangedSink_INTERFACE_DEFINED = 1

' // Size = 16 bytes
TYPE SEARCH_ITEM_PERSISTENT_CHANGE DWORD
   Change   AS DWORD          ' SEARCH_KIND_OF_CHANGE
   URL      AS WSTRINGZ PTR   ' LPWSTR
   OldURL   AS WSTRINGZ PTR   ' LPWSTR
   Priority AS DWORD          ' SEARCH_NOTIFICATION_PRIORITY
END TYPE

INTERFACE ISearchPersistentItemsChangedSink $IID_ISearchPersistentItemsChangedSink

   INHERIT IUnknown

   ' =====================================================================================
   METHOD StartedMonitoringScope ( _                    ' VTable offset = 12
     BYREF pszURL AS WSTRINGZ _                         ' __in LPCWSTR pszURL
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD StoppedMonitoringScope ( _                    ' VTable offset = 16
     BYREF pszURL AS WSTRINGZ _                         ' __in LPCWSTR pszURL
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnItemsChanged ( _                            ' VTable offset = 20
     BYVAL dwNumberOfChanges AS DWORD _                 ' __in DWORD dwNumberOfChanges
   , BYREF DataChangeEntries AS SEARCH_ITEM_PERSISTENT_CHANGE _ ' __in SEARCH_ITEM_PERSISTENT_CHANGE DataChangeEntries[  ]
   , BYREF hrCompletionCodes AS LONG _                  ' __out HRESULT hrCompletionCodes[  ]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISearchPersistentItemsChangedSink_INTERFACE_DEFINED__ */

' ########################################################################################
' ISearchViewChangedSink interface
' IID = AB310581-AC80-11D1-8DF3-00C04FB6EF65
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ISearchViewChangedSink_INTERFACE_DEFINED)
    %ISearchViewChangedSink_INTERFACE_DEFINED = 1

INTERFACE ISearchViewChangedSink $IID_ISearchViewChangedSink

   INHERIT IUnknown

   ' =====================================================================================
   METHOD OnChange ( _                                  ' VTable offset = 12
     BYVAL pdwDocID AS LONG _                           ' __in ITEMID *pdwDocID
   , BYREF pChange AS SEARCH_ITEM_CHANGE _              ' __in SEARCH_ITEM_CHANGE *pChange
   , BYVAL pfInView AS LONG _                           ' __in BOOL *pfInView
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISearchViewChangedSink_INTERFACE_DEFINED__ */

' ########################################################################################
' IGatherNotifyInline interface
' IID = 7900F4F4-BA3F-4D53-8744-51626542351A
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IGatherNotifyInline_INTERFACE_DEFINED)
    %IGatherNotifyInline_INTERFACE_DEFINED = 1

' // Size = 12 bytes
TYPE INLINE_NOTIFY_DATA_CHANGE_ENTRY DWORD
   eChangeAdviseCode  AS LONG           ' LONG
   pszPhysicalAddress AS WSTRINGZ PTR   ' LPCWSTR
   pUserData          AS BLOB PTR       ' const BLOB*
END TYPE

INTERFACE IGatherNotifyInline $IID_IGatherNotifyInline

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Initialize ( _                                ' VTable offset = 12
     BYREF pszApplication AS WSTRINGZ _                 ' __in LPCWSTR pszApplication
   , BYREF pszCatalog AS WSTRINGZ _                     ' __in LPCWSTR pszCatalog
   , BYVAL pClientSite AS ISearchNotifyInlineSite _     ' __in ISearchNotifyInlineSite *pClientSite
   , BYREF pGUIDCatalogResetSignature AS GUID _         ' __out GUID *pGUIDCatalogResetSignature
   , BYREF pGUIDCheckPointSignature AS GUID _           ' __out GUID *pGUIDCheckPointSignature
   , BYREF pdwLastCheckPointNumber AS DWORD _           ' __out DWORD *pdwLastCheckPointNumber
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnDataChange ( _                              ' VTable offset = 16
     BYVAL dwNumberEntries AS DWORD _                   ' __in DWORD dwNumberEntries
   , BYREF rgDataChangeEntries AS INLINE_NOTIFY_DATA_CHANGE_ENTRY _ ' __in INLINE_NOTIFY_DATA_CHANGE_ENTRY rgDataChangeEntries[  ]
   , BYREF rgdwDocIDs AS DWORD _                        ' __out DWORD rgdwDocIDs[  ]
   , BYREF rghrCompletionCodes AS LONG _                ' __out HRESULT rghrCompletionCodes[  ]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IGatherNotifyInline_INTERFACE_DEFINED__ */

' ########################################################################################
' ISearchNotifyInlineSite interface
' IID = B5702E61-E75C-4B64-82A1-6CB4F832FCCF
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ISearchNotifyInlineSite_INTERFACE_DEFINED)
    %ISearchNotifyInlineSite_INTERFACE_DEFINED = 1

' enum SEARCH_INDEXING_PHASE
%SEARCH_INDEXING_PHASE_GATHERER  = 0
%SEARCH_INDEXING_PHASE_QUERYABLE = 1
%SEARCH_INDEXING_PHASE_PERSISTED = 2

' // Size = 8 bytes
TYPE SEARCH_ITEM_INDEXING_STATUS DWORD
   dwDocID          AS DWORD   ' DWORD
   hrIndexingStatus AS LONG    ' HRESULT
END TYPE

INTERFACE ISearchNotifyInlineSite $IID_ISearchNotifyInlineSite

   INHERIT IUnknown

   ' =====================================================================================
   METHOD OnItemIndexedStatusChange ( _                 ' VTable offset = 12
     BYVAL sipStatus AS LONG _                          ' __in SEARCH_INDEXING_PHASE sipStatus
   , BYVAL dwNumEntries AS DWORD _                      ' __in DWORD dwNumEntries
   , BYREF rgItemStatusEntries AS SEARCH_ITEM_INDEXING_STATUS _ ' __in SEARCH_ITEM_INDEXING_STATUS rgItemStatusEntries[  ]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnCatalogStatusChange ( _                     ' VTable offset = 16
     BYREF guidCatalogResetSignature AS GUID _          ' __in REFGUID guidCatalogResetSignature
   , BYREF guidCheckPointSignature AS GUID _            ' __in REFGUID guidCheckPointSignature
   , BYVAL dwLastCheckPointNumber AS DWORD _            ' __in DWORD dwLastCheckPointNumber
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISearchNotifyInlineSite_INTERFACE_DEFINED__ */

' ########################################################################################
' IGatherNotifyInlineInternal interface
' IID = 2E5C2EC6-4FF9-44B7-9869-6AF9A8D3FD67
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IGatherNotifyInlineInternal_INTERFACE_DEFINED)
    %IGatherNotifyInlineInternal_INTERFACE_DEFINED = 1

INTERFACE IGatherNotifyInlineInternal $IID_IGatherNotifyInlineInternal

   INHERIT IUnknown

   ' =====================================================================================
   METHOD RegisterInlineNotificationClient ( _          ' VTable offset = 12
     BYVAL pClientSite AS ISearchNotifyInlineSite _     ' __in ISearchNotifyInlineSite *pClientSite
   , BYREF pGUIDCatalogResetSignature AS GUID _         ' __out GUID *pGUIDCatalogResetSignature
   , BYREF pGUIDCheckPointSignature AS GUID _           ' __out GUID *pGUIDCheckPointSignature
   , BYREF pdwLastCheckPointNumber AS DWORD _           ' __out DWORD *pdwLastCheckPointNumber
   , BYREF pdwClientID AS DWORD _                       ' __out DWORD *pdwClientID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnDataChangeInline ( _                        ' VTable offset = 16
     BYVAL dwClientID AS DWORD _                        ' __in DWORD dwClientID
   , BYVAL dwNumberEntries AS DWORD _                   ' __in DWORD dwNumberEntries
   , BYREF rgDataChangeEntries AS INLINE_NOTIFY_DATA_CHANGE_ENTRY _ ' __in INLINE_NOTIFY_DATA_CHANGE_ENTRY rgDataChangeEntries[  ]
   , BYREF rgdwDocIDs AS DWORD _                        ' __out DWORD rgdwDocIDs[  ]
   , BYREF rghrCompletionCodes AS LONG _                ' __out HRESULT rghrCompletionCodes[  ]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SendItemIndexedStatusChange ( _               ' VTable offset = 20
     BYVAL dwClientID AS DWORD _                        ' __in DWORD dwClientID
   , BYVAL sipStatus AS LONG _                          ' __in SEARCH_INDEXING_PHASE sipStatus
   , BYVAL dwNumEntries AS DWORD _                      ' __in DWORD dwNumEntries
   , BYREF rgItemStatusEntries AS SEARCH_ITEM_INDEXING_STATUS _ ' __in SEARCH_ITEM_INDEXING_STATUS rgItemStatusEntries[  ]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ReleaseInlineNotificationClient ( _           ' VTable offset = 24
     BYVAL dwClientID AS DWORD _                        ' __in DWORD dwClientID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IGatherNotifyInlineInternal_INTERFACE_DEFINED__ */

' ########################################################################################
' IGatherInlineStatus interface
' IID = 2137B63B-BBB0-4BEE-94B3-4691CCEF389A
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IGatherInlineStatus_INTERFACE_DEFINED)
    %IGatherInlineStatus_INTERFACE_DEFINED = 1

INTERFACE IGatherInlineStatus $IID_IGatherInlineStatus

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SendInlineStatusChange ( _                    ' VTable offset = 12
     BYVAL dwClientID AS DWORD _                        ' __in DWORD dwClientID
   , BYVAL sipStatus AS LONG _                          ' __in SEARCH_INDEXING_PHASE sipStatus
   , BYVAL dwNumEntries AS DWORD _                      ' __in DWORD dwNumEntries
   , BYREF rgItemStatusEntries AS SEARCH_ITEM_INDEXING_STATUS _ ' __in SEARCH_ITEM_INDEXING_STATUS rgItemStatusEntries[  ]
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IGatherInlineStatus_INTERFACE_DEFINED__ */

' enum CatalogStatus
%CATALOG_STATUS_IDLE                     = 0
%CATALOG_STATUS_PAUSED                   = 1
%CATALOG_STATUS_RECOVERING               = 2
%CATALOG_STATUS_FULL_CRAWL               = 3
%CATALOG_STATUS_INCREMENTAL_CRAWL        = 4
%CATALOG_STATUS_PROCESSING_NOTIFICATIONS = 5
%CATALOG_STATUS_SHUTTING_DOWN            = 6

' enum CatalogPausedReason
%CATALOG_PAUSED_REASON_NONE              = 0
%CATALOG_PAUSED_REASON_HIGH_IO           = 1
%CATALOG_PAUSED_REASON_HIGH_CPU          = 2
%CATALOG_PAUSED_REASON_HIGH_NTF_RATE     = 3
%CATALOG_PAUSED_REASON_LOW_BATTERY       = 4
%CATALOG_PAUSED_REASON_LOW_MEMORY        = 5
%CATALOG_PAUSED_REASON_LOW_DISK          = 6
%CATALOG_PAUSED_REASON_DELAYED_RECOVERY  = 7
%CATALOG_PAUSED_REASON_USER_ACTIVE       = 8
%CATALOG_PAUSED_REASON_EXTERNAL          = 9
%CATALOG_PAUSED_REASON_UPGRADING         = 10

' ########################################################################################
' ISearchCatalogManager interface
' IID = AB310581-AC80-11D1-8DF3-00C04FB6EF50
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ISearchCatalogManager_INTERFACE_DEFINED)
    %ISearchCatalogManager_INTERFACE_DEFINED = 1

INTERFACE ISearchCatalogManager $IID_ISearchCatalogManager

   INHERIT IUnknown

   ' =====================================================================================
   METHOD get_Name ( _                                  ' VTable offset = 12
     BYREF pszName AS DWORD _                           ' __out LPWSTR *pszName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetParameter ( _                              ' VTable offset = 16
     BYREF pszName AS WSTRINGZ _                        ' __in LPCWSTR pszName
   , BYREF ppValue AS PROPVARIANT _                     ' __out PROPVARIANT **ppValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetParameter ( _                              ' VTable offset = 20
     BYREF pszName AS WSTRINGZ _                        ' __in LPCWSTR pszName
   , BYREF pValue AS PROPVARIANT _                      ' __in PROPVARIANT *pValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCatalogStatus ( _                          ' VTable offset = 24
     BYREF pStatus AS LONG _                            ' __out CatalogStatus *pStatus
   , BYREF pPausedReason AS LONG _                      ' __out CatalogPausedReason *pPausedReason
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reset ( _                                     ' VTable offset = 28
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reindex ( _                                   ' VTable offset = 32
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ReindexMatchingURLs ( _                       ' VTable offset = 36
     BYREF pszPattern AS WSTRINGZ _                     ' __in LPCWSTR pszPattern
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ReindexSearchRoot ( _                         ' VTable offset = 40
     BYREF pszRootURL AS WSTRINGZ _                     ' __in LPCWSTR pszRootURL
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_ConnectTimeout ( _                        ' VTable offset = 44
     BYVAL dwConnectTimeout AS DWORD _                  ' __in DWORD dwConnectTimeout
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_ConnectTimeout ( _                        ' VTable offset = 48
     BYREF pdwConnectTimeout AS DWORD _                 ' __out DWORD *pdwConnectTimeout
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_DataTimeout ( _                           ' VTable offset = 52
     BYVAL dwDataTimeout AS DWORD _                     ' __in DWORD dwDataTimeout
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_DataTimeout ( _                           ' VTable offset = 56
     BYREF pdwDataTimeout AS DWORD _                    ' __out DWORD *pdwDataTimeout
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD NumberOfItems ( _                             ' VTable offset = 60
     BYREF plCount AS LONG _                            ' __out LONG *plCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD NumberOfItemsToIndex ( _                      ' VTable offset = 64
     BYREF plIncrementalCount AS LONG _                 ' __out LONG *plIncrementalCount
   , BYREF plNotificationQueue AS LONG _                ' __out LONG *plNotificationQueue
   , BYREF plHighPriorityQueue AS LONG _                ' __out LONG *plHighPriorityQueue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD URLBeingIndexed ( _                           ' VTable offset = 68
     BYREF pszUrl AS DWORD _                            ' __out LPWSTR *pszUrl
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetURLIndexingState ( _                       ' VTable offset = 72
     BYREF pszURL AS WSTRINGZ _                         ' __in LPCWSTR pszURL
   , BYREF pdwState AS DWORD _                          ' __out DWORD *pdwState
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPersistentItemsChangedSink ( _             ' VTable offset = 76
     BYREF ppISearchPersistentItemsChangedSink AS ISearchPersistentItemsChangedSink _ ' __out ISearchPersistentItemsChangedSink **ppISearchPersistentItemsChangedSink
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RegisterViewForNotification ( _               ' VTable offset = 80
     BYREF pszView AS WSTRINGZ _                        ' __in LPCWSTR pszView
   , BYVAL pViewChangedSink AS ISearchViewChangedSink _ ' __in ISearchViewChangedSink *pViewChangedSink
   , BYREF pdwCookie AS DWORD _                         ' __out DWORD *pdwCookie
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetItemsChangedSink ( _                       ' VTable offset = 84
     BYVAL pISearchNotifyInlineSite AS ISearchNotifyInlineSite _ ' __in ISearchNotifyInlineSite *pISearchNotifyInlineSite
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppv AS IUnknown _                            ' __out void **ppv
   , BYREF pGUIDCatalogResetSignature AS GUID _         ' __out GUID *pGUIDCatalogResetSignature
   , BYREF pGUIDCheckPointSignature AS GUID _           ' __out GUID *pGUIDCheckPointSignature
   , BYREF pdwLastCheckPointNumber AS DWORD _           ' __out DWORD *pdwLastCheckPointNumber
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UnregisterViewForNotification ( _             ' VTable offset = 88
     BYVAL dwCookie AS DWORD _                          ' __in DWORD dwCookie
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetExtensionClusion ( _                       ' VTable offset = 92
     BYREF pszExtension AS WSTRINGZ _                   ' __in LPCWSTR pszExtension
   , BYVAL fExclude AS LONG _                           ' __in BOOL fExclude
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumerateExcludedExtensions ( _               ' VTable offset = 96
     BYREF ppExtensions AS IEnumString _                ' __out IEnumString **ppExtensions
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetQueryHelper ( _                            ' VTable offset = 100
     BYREF ppSearchQueryHelper AS ISearchQueryHelper _  ' __out ISearchQueryHelper **ppSearchQueryHelper
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_DiacriticSensitivity ( _                  ' VTable offset = 104
     BYVAL fDiacriticSensitive AS LONG _                ' __in BOOL fDiacriticSensitive
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_DiacriticSensitivity ( _                  ' VTable offset = 108
     BYREF pfDiacriticSensitive AS LONG _               ' __out BOOL *pfDiacriticSensitive
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCrawlScopeManager ( _                      ' VTable offset = 112
     BYREF ppCrawlScopeManager AS ISearchCrawlScopeManager _ ' __out ISearchCrawlScopeManager **ppCrawlScopeManager
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISearchCatalogManager_INTERFACE_DEFINED__ */

' enum PRIORITIZE_FLAGS
%PRIORITIZE_FLAG_RETRYFAILEDITEMS   = &H1&
%PRIORITIZE_FLAG_IGNOREFAILURECOUNT = &H2&

'typedef int PRIORITIZE_FLAGS;

' ########################################################################################
' ISearchCatalogManager2 interface
' IID = 7AC3286D-4D1D-4817-84FC-C1C85E3AF0D9
' Inherited interface = ISearchCatalogManager
' ########################################################################################

#IF NOT %DEF(%ISearchCatalogManager2_INTERFACE_DEFINED)
    %ISearchCatalogManager2_INTERFACE_DEFINED = 1

INTERFACE ISearchCatalogManager2 $IID_ISearchCatalogManager2

   INHERIT IUnknown

   ' =====================================================================================
   ' ISearchCatalogManager Methods
   ' =====================================================================================
   METHOD get_Name ( _                                  ' VTable offset = 12
     BYREF pszName AS DWORD _                           ' __out LPWSTR *pszName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetParameter ( _                              ' VTable offset = 16
     BYREF pszName AS WSTRINGZ _                        ' __in LPCWSTR pszName
   , BYREF ppValue AS PROPVARIANT _                     ' __out PROPVARIANT **ppValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetParameter ( _                              ' VTable offset = 20
     BYREF pszName AS WSTRINGZ _                        ' __in LPCWSTR pszName
   , BYREF pValue AS PROPVARIANT _                      ' __in PROPVARIANT *pValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCatalogStatus ( _                          ' VTable offset = 24
     BYREF pStatus AS LONG _                            ' __out CatalogStatus *pStatus
   , BYREF pPausedReason AS LONG _                      ' __out CatalogPausedReason *pPausedReason
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reset ( _                                     ' VTable offset = 28
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reindex ( _                                   ' VTable offset = 32
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ReindexMatchingURLs ( _                       ' VTable offset = 36
     BYREF pszPattern AS WSTRINGZ _                     ' __in LPCWSTR pszPattern
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ReindexSearchRoot ( _                         ' VTable offset = 40
     BYREF pszRootURL AS WSTRINGZ _                     ' __in LPCWSTR pszRootURL
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_ConnectTimeout ( _                        ' VTable offset = 44
     BYVAL dwConnectTimeout AS DWORD _                  ' __in DWORD dwConnectTimeout
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_ConnectTimeout ( _                        ' VTable offset = 48
     BYREF pdwConnectTimeout AS DWORD _                 ' __out DWORD *pdwConnectTimeout
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_DataTimeout ( _                           ' VTable offset = 52
     BYVAL dwDataTimeout AS DWORD _                     ' __in DWORD dwDataTimeout
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_DataTimeout ( _                           ' VTable offset = 56
     BYREF pdwDataTimeout AS DWORD _                    ' __out DWORD *pdwDataTimeout
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD NumberOfItems ( _                             ' VTable offset = 60
     BYREF plCount AS LONG _                            ' __out LONG *plCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD NumberOfItemsToIndex ( _                      ' VTable offset = 64
     BYREF plIncrementalCount AS LONG _                 ' __out LONG *plIncrementalCount
   , BYREF plNotificationQueue AS LONG _                ' __out LONG *plNotificationQueue
   , BYREF plHighPriorityQueue AS LONG _                ' __out LONG *plHighPriorityQueue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD URLBeingIndexed ( _                           ' VTable offset = 68
     BYREF pszUrl AS DWORD _                            ' __out LPWSTR *pszUrl
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetURLIndexingState ( _                       ' VTable offset = 72
     BYREF pszURL AS WSTRINGZ _                         ' __in LPCWSTR pszURL
   , BYREF pdwState AS DWORD _                          ' __out DWORD *pdwState
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPersistentItemsChangedSink ( _             ' VTable offset = 76
     BYREF ppISearchPersistentItemsChangedSink AS ISearchPersistentItemsChangedSink _ ' __out ISearchPersistentItemsChangedSink **ppISearchPersistentItemsChangedSink
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RegisterViewForNotification ( _               ' VTable offset = 80
     BYREF pszView AS WSTRINGZ _                        ' __in LPCWSTR pszView
   , BYVAL pViewChangedSink AS ISearchViewChangedSink _ ' __in ISearchViewChangedSink *pViewChangedSink
   , BYREF pdwCookie AS DWORD _                         ' __out DWORD *pdwCookie
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetItemsChangedSink ( _                       ' VTable offset = 84
     BYVAL pISearchNotifyInlineSite AS ISearchNotifyInlineSite _ ' __in ISearchNotifyInlineSite *pISearchNotifyInlineSite
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppv AS IUnknown _                            ' __out void **ppv
   , BYREF pGUIDCatalogResetSignature AS GUID _         ' __out GUID *pGUIDCatalogResetSignature
   , BYREF pGUIDCheckPointSignature AS GUID _           ' __out GUID *pGUIDCheckPointSignature
   , BYREF pdwLastCheckPointNumber AS DWORD _           ' __out DWORD *pdwLastCheckPointNumber
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UnregisterViewForNotification ( _             ' VTable offset = 88
     BYVAL dwCookie AS DWORD _                          ' __in DWORD dwCookie
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetExtensionClusion ( _                       ' VTable offset = 92
     BYREF pszExtension AS WSTRINGZ _                   ' __in LPCWSTR pszExtension
   , BYVAL fExclude AS LONG _                           ' __in BOOL fExclude
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumerateExcludedExtensions ( _               ' VTable offset = 96
     BYREF ppExtensions AS IEnumString _                ' __out IEnumString **ppExtensions
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetQueryHelper ( _                            ' VTable offset = 100
     BYREF ppSearchQueryHelper AS ISearchQueryHelper _  ' __out ISearchQueryHelper **ppSearchQueryHelper
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_DiacriticSensitivity ( _                  ' VTable offset = 104
     BYVAL fDiacriticSensitive AS LONG _                ' __in BOOL fDiacriticSensitive
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_DiacriticSensitivity ( _                  ' VTable offset = 108
     BYREF pfDiacriticSensitive AS LONG _               ' __out BOOL *pfDiacriticSensitive
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCrawlScopeManager ( _                      ' VTable offset = 112
     BYREF ppCrawlScopeManager AS ISearchCrawlScopeManager _ ' __out ISearchCrawlScopeManager **ppCrawlScopeManager
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' ISearchCatalogManager2 Methods
   ' =====================================================================================
   METHOD PrioritizeMatchingURLs ( _                    ' VTable offset = 116
     BYREF pszPattern AS WSTRINGZ _                     ' __in LPCWSTR pszPattern
   , BYVAL dwPrioritizeFlags AS LONG _                  ' __in PRIORITIZE_FLAGS dwPrioritizeFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISearchCatalogManager2_INTERFACE_DEFINED__ */

' ########################################################################################
' ISearchQueryHelper interface
' IID = AB310581-AC80-11D1-8DF3-00C04FB6EF63
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ISearchQueryHelper_INTERFACE_DEFINED)
    %ISearchQueryHelper_INTERFACE_DEFINED = 1

' enum SEARCH_TERM_EXPANSION
%SEARCH_TERM_NO_EXPANSION     = 0
%SEARCH_TERM_PREFIX_ALL       = %SEARCH_TERM_NO_EXPANSION     + 1
%SEARCH_TERM_STEM_ALL         = %SEARCH_TERM_PREFIX_ALL       + 1

' enum SEARCH_QUERY_SYNTAX
%SEARCH_NO_QUERY_SYNTAX       = 0
%SEARCH_ADVANCED_QUERY_SYNTAX = %SEARCH_NO_QUERY_SYNTAX       + 1
%SEARCH_NATURAL_QUERY_SYNTAX  = %SEARCH_ADVANCED_QUERY_SYNTAX + 1

' // Size = 24 bytes
TYPE SEARCH_COLUMN_PROPERTIES   ' Must be 8 byte aligned
   Value       AS PROPVARIANT   ' PROPVARIANT
   lcid        AS DWORD         ' LCID
   alignment__ AS DWORD
END TYPE

INTERFACE ISearchQueryHelper $IID_ISearchQueryHelper

   INHERIT IUnknown

   ' =====================================================================================
   METHOD get_ConnectionString ( _                      ' VTable offset = 12
     BYREF pszConnectionString AS DWORD _               ' __out LPWSTR *pszConnectionString
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_QueryContentLocale ( _                    ' VTable offset = 16
     BYVAL lcid AS DWORD _                              ' __in LCID lcid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_QueryContentLocale ( _                    ' VTable offset = 20
     BYREF plcid AS DWORD _                             ' __out LCID *plcid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_QueryKeywordLocale ( _                    ' VTable offset = 24
     BYVAL lcid AS DWORD _                              ' __in LCID lcid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_QueryKeywordLocale ( _                    ' VTable offset = 28
     BYREF plcid AS DWORD _                             ' __out LCID *plcid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_QueryTermExpansion ( _                    ' VTable offset = 32
     BYVAL expandTerms AS LONG _                        ' __in SEARCH_TERM_EXPANSION expandTerms
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_QueryTermExpansion ( _                    ' VTable offset = 36
     BYREF pExpandTerms AS LONG _                       ' __out SEARCH_TERM_EXPANSION *pExpandTerms
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_QuerySyntax ( _                           ' VTable offset = 40
     BYVAL querySyntax AS LONG _                        ' __in SEARCH_QUERY_SYNTAX querySyntax
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_QuerySyntax ( _                           ' VTable offset = 44
     BYREF pQuerySyntax AS LONG _                       ' __out SEARCH_QUERY_SYNTAX *pQuerySyntax
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_QueryContentProperties ( _                ' VTable offset = 48
     BYREF pszContentProperties AS WSTRINGZ _           ' __in LPCWSTR pszContentProperties
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_QueryContentProperties ( _                ' VTable offset = 52
     BYREF ppszContentProperties AS DWORD _             ' __out LPWSTR *ppszContentProperties
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_QuerySelectColumns ( _                    ' VTable offset = 56
     BYREF pszSelectColumns AS WSTRINGZ _               ' __in LPCWSTR pszSelectColumns
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_QuerySelectColumns ( _                    ' VTable offset = 60
     BYREF ppszSelectColumns AS DWORD _                 ' __out LPWSTR *ppszSelectColumns
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_QueryWhereRestrictions ( _                ' VTable offset = 64
     BYREF pszRestrictions AS WSTRINGZ _                ' __in LPCWSTR pszRestrictions
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_QueryWhereRestrictions ( _                ' VTable offset = 68
     BYREF ppszRestrictions AS DWORD _                  ' __out LPWSTR *ppszRestrictions
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_QuerySorting ( _                          ' VTable offset = 72
     BYREF pszSorting AS WSTRINGZ _                     ' __in LPCWSTR pszSorting
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_QuerySorting ( _                          ' VTable offset = 76
     BYREF ppszSorting AS DWORD _                       ' __out LPWSTR *ppszSorting
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GenerateSQLFromUserQuery ( _                  ' VTable offset = 80
     BYREF pszQuery AS WSTRINGZ _                       ' __in LPCWSTR pszQuery
   , BYREF ppszSQL AS DWORD _                           ' __out LPWSTR *ppszSQL
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD WriteProperties ( _                           ' VTable offset = 84
     BYVAL itemID AS LONG _                             ' __in ITEMID itemID
   , BYVAL dwNumberOfColumns AS DWORD _                 ' __in DWORD dwNumberOfColumns
   , BYREF pColumns AS PROPERTYKEY _                    ' __in PROPERTYKEY *pColumns
   , BYREF pValues AS SEARCH_COLUMN_PROPERTIES _        ' __in SEARCH_COLUMN_PROPERTIES *pValues
   , BYREF pftGatherModifiedTime AS FILETIME _          ' __in FILETIME *pftGatherModifiedTime
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_QueryMaxResults ( _                       ' VTable offset = 88
     BYVAL cMaxResults AS LONG _                        ' __in LONG cMaxResults
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_QueryMaxResults ( _                       ' VTable offset = 92
     BYREF pcMaxResults AS LONG _                       ' __out LONG *pcMaxResults
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISearchQueryHelper_INTERFACE_DEFINED__ */

' enum PRIORITY_LEVEL
%PRIORITY_LEVEL_FOREGROUND = 0
%PRIORITY_LEVEL_HIGH       = 1
%PRIORITY_LEVEL_LOW        = 2
%PRIORITY_LEVEL_DEFAULT    = 3

' ########################################################################################
' IRowsetPrioritization interface
' IID = 42811652-079D-481B-87A2-09A69ECC5F44
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IRowsetPrioritization_INTERFACE_DEFINED)
    %IRowsetPrioritization_INTERFACE_DEFINED = 1

INTERFACE IRowsetPrioritization $IID_IRowsetPrioritization

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetScopePriority ( _                          ' VTable offset = 12
     BYVAL priority AS LONG _                           ' __in PRIORITY_LEVEL priority
   , BYVAL scopeStatisticsEventFrequency AS DWORD _     ' __in DWORD scopeStatisticsEventFrequency
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetScopePriority ( _                          ' VTable offset = 16
     BYREF priority AS LONG _                           ' __out PRIORITY_LEVEL *priority
   , BYREF scopeStatisticsEventFrequency AS DWORD _     ' __out DWORD *scopeStatisticsEventFrequency
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetScopeStatistics ( _                        ' VTable offset = 20
     BYREF indexedDocumentCount AS DWORD _              ' __out DWORD *indexedDocumentCount
   , BYREF oustandingAddCount AS DWORD _                ' __out DWORD *oustandingAddCount
   , BYREF oustandingModifyCount AS DWORD _             ' __out DWORD *oustandingModifyCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IRowsetPrioritization_INTERFACE_DEFINED__ */

' enum ROWSETEVENT_ITEMSTATE
%ROWSETEVENT_ITEMSTATE_NOTINROWSET = 0
%ROWSETEVENT_ITEMSTATE_INROWSET    = 1
%ROWSETEVENT_ITEMSTATE_UNKNOWN     = 2

' enum ROWSETEVENT_TYPE
%ROWSETEVENT_TYPE_DATAEXPIRED      = 0
%ROWSETEVENT_TYPE_FOREGROUNDLOST   = 1
%ROWSETEVENT_TYPE_SCOPESTATISTICS  = 2

' ########################################################################################
' IRowsetEvents interface
' IID = 1551AEA5-5D66-4B11-86F5-D5634CB211B9
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IRowsetEvents_INTERFACE_DEFINED)
    %IRowsetEvents_INTERFACE_DEFINED = 1

INTERFACE IRowsetEvents $IID_IRowsetEvents

   INHERIT IUnknown

   ' =====================================================================================
   METHOD OnNewItem ( _                                 ' VTable offset = 12
     BYREF itemID AS PROPVARIANT _                      ' __in REFPROPVARIANT itemID
   , BYVAL newItemState AS LONG _                       ' __in ROWSETEVENT_ITEMSTATE newItemState
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnChangedItem ( _                             ' VTable offset = 16
     BYREF itemID AS PROPVARIANT _                      ' __in REFPROPVARIANT itemID
   , BYVAL rowsetItemState AS LONG _                    ' __in ROWSETEVENT_ITEMSTATE rowsetItemState
   , BYVAL changedItemState AS LONG _                   ' __in ROWSETEVENT_ITEMSTATE changedItemState
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnDeletedItem ( _                             ' VTable offset = 20
     BYREF itemID AS PROPVARIANT _                      ' __in REFPROPVARIANT itemID
   , BYVAL deletedItemState AS LONG _                   ' __in ROWSETEVENT_ITEMSTATE deletedItemState
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnRowsetEvent ( _                             ' VTable offset = 24
     BYVAL eventType AS LONG _                          ' __in ROWSETEVENT_TYPE eventType
   , BYREF eventData AS PROPVARIANT _                   ' __in REFPROPVARIANT eventData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IRowsetEvents_INTERFACE_DEFINED__ */

' ########################################################################################
' ISearchManager interface
' IID = AB310581-AC80-11D1-8DF3-00C04FB6EF69
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ISearchManager_INTERFACE_DEFINED)
    %ISearchManager_INTERFACE_DEFINED = 1

INTERFACE ISearchManager $IID_ISearchManager

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetIndexerVersionStr ( _                      ' VTable offset = 12
     BYREF ppszVersionString AS DWORD _                 ' __out LPWSTR *ppszVersionString
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetIndexerVersion ( _                         ' VTable offset = 16
     BYREF pdwMajor AS DWORD _                          ' __out DWORD *pdwMajor
   , BYREF pdwMinor AS DWORD _                          ' __out DWORD *pdwMinor
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetParameter ( _                              ' VTable offset = 20
     BYREF pszName AS WSTRINGZ _                        ' __in LPCWSTR pszName
   , BYREF ppValue AS PROPVARIANT _                     ' __out PROPVARIANT **ppValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetParameter ( _                              ' VTable offset = 24
     BYREF pszName AS WSTRINGZ _                        ' __in LPCWSTR pszName
   , BYREF pValue AS PROPVARIANT _                      ' __in const PROPVARIANT *pValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   PROPERTY GET ProxyName ( _                           ' VTable offset = 28
     BYREF ppszProxyName AS DWORD _                     ' __out LPWSTR *ppszProxyName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   PROPERTY GET BypassList ( _                          ' VTable offset = 32
     BYREF ppszBypassList AS DWORD _                    ' __out LPWSTR *ppszBypassList
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetProxy ( _                                  ' VTable offset = 36
     BYVAL sUseProxy AS LONG _                          ' __in PROXY_ACCESS sUseProxy
   , BYVAL fLocalByPassProxy AS LONG _                  ' __in BOOL fLocalByPassProxy
   , BYVAL dwPortNumber AS DWORD _                      ' __in DWORD dwPortNumber
   , BYREF pszProxyName AS WSTRINGZ _                   ' __in LPCWSTR pszProxyName
   , BYREF pszByPassList AS WSTRINGZ _                  ' __in LPCWSTR pszByPassList
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCatalog ( _                                ' VTable offset = 40
     BYREF pszCatalog AS WSTRINGZ _                     ' __in LPCWSTR pszCatalog
   , BYREF ppCatalogManager AS ISearchCatalogManager _  ' __out ISearchCatalogManager **ppCatalogManager
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_UserAgent ( _                             ' VTable offset = 44
     BYREF ppszUserAgent AS DWORD _                     ' __out LPWSTR *ppszUserAgent
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD put_UserAgent ( _                             ' VTable offset = 48
     BYREF pszUserAgent AS WSTRINGZ _                   ' __in LPCWSTR pszUserAgent
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_UseProxy ( _                              ' VTable offset = 52
     BYREF pUseProxy AS LONG _                          ' __out PROXY_ACCESS *pUseProxy
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_LocalBypass ( _                           ' VTable offset = 56
     BYREF pfLocalBypass AS LONG _                      ' __out BOOL *pfLocalBypass
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD get_PortNumber ( _                            ' VTable offset = 60
     BYREF pdwPortNumber AS DWORD _                     ' __out DWORD *pdwPortNumber
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISearchManager_INTERFACE_DEFINED__ */

' ########################################################################################
' ISearchLanguageSupport interface
' IID = 24C3CBAA-EBC1-491A-9EF1-9F6D8DEB1B8F
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ISearchLanguageSupport_INTERFACE_DEFINED)
    %ISearchLanguageSupport_INTERFACE_DEFINED = 1

INTERFACE ISearchLanguageSupport $IID_ISearchLanguageSupport

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetDiacriticSensitivity ( _                   ' VTable offset = 12
     BYVAL fDiacriticSensitive AS LONG _                ' __in BOOL fDiacriticSensitive
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDiacriticSensitivity ( _                   ' VTable offset = 16
     BYREF pfDiacriticSensitive AS LONG _               ' __out BOOL *pfDiacriticSensitive
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD LoadWordBreaker ( _                           ' VTable offset = 20
     BYVAL lcid AS DWORD _                              ' __in LCID lcid
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppWordBreaker AS IUnknown _                  ' __out void **ppWordBreaker
   , BYREF pLcidUsed AS DWORD _                         ' __out LCID *pLcidUsed
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD LoadStemmer ( _                               ' VTable offset = 24
     BYVAL lcid AS DWORD _                              ' __in LCID lcid
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppStemmer AS IUnknown _                      ' __out void **ppStemmer
   , BYREF pLcidUsed AS DWORD _                         ' __out LCID *pLcidUsed
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsPrefixNormalized ( _                        ' VTable offset = 28
     BYREF pwcsQueryToken AS WSTRINGZ _                 ' __in LPCWSTR pwcsQueryToken
   , BYVAL cwcQueryToken AS DWORD _                     ' __in ULONG cwcQueryToken
   , BYREF pwcsDocumentToken AS WSTRINGZ _              ' __in LPCWSTR pwcsDocumentToken
   , BYVAL cwcDocumentToken AS DWORD _                  ' __in ULONG cwcDocumentToken
   , BYREF pulPrefixLength AS DWORD _                   ' __out ULONG *pulPrefixLength
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISearchLanguageSupport_INTERFACE_DEFINED__ */
