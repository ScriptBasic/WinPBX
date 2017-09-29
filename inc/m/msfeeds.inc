' ########################################################################################
' Microsoft Windows
' File: MSFeeds.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

' ########################################################################################
' Library name: Feeds
' Version: 1.0, Locale ID = 0
' Description: Microsoft Feeds, version 1.0
' Documentation string: Microsoft Feeds
' Path: C:\Windows\system32\msfeeds.dll
' Library GUID: {9CDCD9C9-BC40-41C6-89C5-230466DB0BD0}
' ########################################################################################

#INCLUDE THIS ONCE
%MSFEEDS_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "oaidl.inc"

' ========================================================================================
' ProgIDs (Program identifiers)
' ========================================================================================

' CLSID = {FAEB54C4-F66F-4806-83A0-805299F5E3AD}
$PROGID_FeedsManager = "Microsoft.FeedsManager"

' ========================================================================================
' ClsIDs (Class identifiers)
' ========================================================================================

' // Low-level interfaces
$CLSID_XFeedsManager = GUID$("{FE6B11C3-C72E-4061-86C6-9D163121F229}")

' // Automation interfaces
$CLSID_FeedFolderWatcher = GUID$("{281001ED-7765-4CB0-84AF-E9B387AF01FF}")
$CLSID_FeedWatcher = GUID$("{18A6737B-F433-4687-89BC-A1B4DFB9F123}")
$CLSID_FeedsManager = GUID$("{FAEB54C4-F66F-4806-83A0-805299F5E3AD}")

' ========================================================================================
' IIDs (Interface identifiers)
' ========================================================================================

' // Low-level interfaces
$IID_IXFeed = GUID$("{A44179A4-E0F6-403B-AF8D-D080F425A451}")
$IID_IXFeed2 = GUID$("{CE528E77-3716-4EB7-956D-F5E37502E12A}")
$IID_IXFeedEnclosure = GUID$("{BFBFB953-644F-4792-B69C-DFACA4CBF89A}")
$IID_IXFeedEvents = GUID$("{1630852E-1263-465B-98E5-FE60FFEC4AC2}")
$IID_IXFeedFolder = GUID$("{4C963678-3A51-4B88-8531-98B90B6508F2}")
$IID_IXFeedFolderEvents = GUID$("{7964B769-234A-4BB1-A5F4-90454C8AD07E}")
$IID_IXFeedItem = GUID$("{E757B2F5-E73E-434E-A1BF-2BD7C3E60FCB}")
$IID_IXFeedItem2 = GUID$("{6CDA2DC7-9013-4522-9970-2A9DD9EAD5A3}")
$IID_IXFeedsEnum = GUID$("{DC43A9D5-5015-4301-8C96-A47434B4D658}")
$IID_IXFeedsManager = GUID$("{5357E238-FB12-4ACA-A930-CAB7832B84BF}")

' // Automation interfaces
$IID_IFeed = GUID$("{F7F915D8-2EDE-42BC-98E7-A5D05063A757}")
$IID_IFeed2 = GUID$("{33F2EA09-1398-4AB9-B6A4-F94B49D0A42E}")
$IID_IFeedEnclosure = GUID$("{361C26F7-90A4-4E67-AE09-3A36A546436A}")
$IID_IFeedEvents = GUID$("{ABF35C99-0681-47EA-9A8C-1436A375A99E}")
$IID_IFeedFolder = GUID$("{81F04AD1-4194-4D7D-86D6-11813CEC163C}")
$IID_IFeedFolderEvents = GUID$("{20A59FA6-A844-4630-9E98-175F70B4D55B}")
$IID_IFeedItem = GUID$("{0A1E6CAD-0A47-4DA2-A13D-5BAAA5C8BD4F}")
$IID_IFeedItem2 = GUID$("{79AC9EF4-F9C1-4D2B-A50B-A7FFBA4DCF37}")
$IID_IFeedsEnum = GUID$("{E3CD0028-2EED-4C60-8FAE-A3225309A836}")
$IID_IFeedsManager = GUID$("{A74029CC-1F1A-4906-88F0-810638D86591}")

' ========================================================================================
' FEEDS_BACKGROUNDSYNC_ACTION enum
' ========================================================================================

%FBSA_DISABLE                                           = 0
%FBSA_ENABLE                                            = 1
%FBSA_RUNNOW                                            = 2

' ========================================================================================
' FEEDS_BACKGROUNDSYNC_STATUS enum
' ========================================================================================

%FBSS_DISABLED                                          = 0
%FBSS_ENABLED                                           = 1

' ========================================================================================
' FEEDS_EVENTS_SCOPE enum
' ========================================================================================

%FES_ALL                                                = 0
%FES_SELF_ONLY                                          = 1
%FES_SELF_AND_CHILDREN_ONLY                             = 2

' ========================================================================================
' FEEDS_EVENTS_MASK enum
' ========================================================================================

%FEM_FOLDEREVENTS                                       = &H1
%FEM_FEEDEVENTS                                         = &H2

' ========================================================================================
' FEEDS_DOWNLOAD_ERROR enum
' ========================================================================================

%FDE_NONE                                               = 0
%FDE_DOWNLOAD_FAILED                                    = 1
%FDE_INVALID_FEED_FORMAT                                = 2
%FDE_NORMALIZATION_FAILED                               = 3
%FDE_PERSISTENCE_FAILED                                 = 4
%FDE_DOWNLOAD_BLOCKED                                   = 5
%FDE_CANCELED                                           = 6
%FDE_UNSUPPORTED_AUTH                                   = 7
%FDE_BACKGROUND_DOWNLOAD_DISABLED                       = 8
%FDE_NOT_EXIST                                          = 9
%FDE_UNSUPPORTED_MSXML                                  = 10
%FDE_UNSUPPORTED_DTD                                    = 11
%FDE_DOWNLOAD_SIZE_LIMIT_EXCEEDED                       = 12
%FDE_ACCESS_DENIED                                      = 13
%FDE_AUTH_FAILED                                        = 14
%FDE_INVALID_AUTH                                       = 15

' ========================================================================================
' FEEDS_ERROR_CODE enum
' ========================================================================================

%FEC_E_ERRORBASE                                        = &HC0040200???
%FEC_E_INVALIDMSXMLPROPERTY                             = %FEC_E_ERRORBASE
%FEC_E_DOWNLOADSIZELIMITEXCEEDED                        = %FEC_E_INVALIDMSXMLPROPERTY + 1

' ========================================================================================
' FEEDS_EVENTS_ITEM_COUNT_FLAGS enum
' ========================================================================================

%FEICF_READ_ITEM_COUNT_CHANGED                          = &H1&
%FEICF_UNREAD_ITEM_COUNT_CHANGED                        = &H2&

'typedef int FEICF;

' ========================================================================================
' FEEDS_XML_SORT_PROPERTY enum
' ========================================================================================

%FXSP_NONE                                              = 0
%FXSP_PUBDATE                                           = 1
%FXSP_DOWNLOADTIME                                      = 2

' ========================================================================================
' FEEDS_XML_SORT_ORDER enum
' ========================================================================================

%FXSO_NONE                                              = 0
%FXSO_ASCENDING                                         = 1
%FXSO_DESCENDING                                        = 2

' ========================================================================================
' FEEDS_XML_FILTER_FLAGS enum
' ========================================================================================

%FXFF_ALL                                               = 0
%FXFF_UNREAD                                            = &H1
%FXFF_READ                                              = &H2

' ========================================================================================
' FEEDS_XML_INCLUDE_FLAGS enum
' ========================================================================================

%FXIF_NONE                                              = 0
%FXIF_CF_EXTENSIONS                                     = &H1

' ========================================================================================
' FEEDS_SYNC_SETTING enum
' ========================================================================================

%FSS_DEFAULT                                            = 0
%FSS_INTERVAL                                           = 1
%FSS_MANUAL                                             = 2
%FSS_SUGGESTED                                          = 3

' ========================================================================================
' FEEDS_DOWNLOAD_STATUS enum
' ========================================================================================

%FDS_NONE                                               = 0
%FDS_PENDING                                            = 1
%FDS_DOWNLOADING                                        = 2
%FDS_DOWNLOADED                                         = 3
%FDS_DOWNLOAD_FAILED                                    = 4

' ########################################################################################
' Interface name = IXFeedsManager
' IID = 5357E238-FB12-4ACA-A930-CAB7832B84BF
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IXFeedsManager_INTERFACE_DEFINED)
    %XIFeedsManager_INTERFACE_DEFINED = 1

INTERFACE IXFeedsManager $IID_IFeedsManager

   INHERIT IUnknown

   ' =====================================================================================
   METHOD RootFolder ( _                                ' VTable offset = 12
     BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppv AS IUnknown _                            ' __out void **ppv
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsSubscribed ( _                              ' VTable offset = 16
     BYREF pszUrl AS WSTRINGZ _                         ' __in LPCWSTR pszUrl
   , BYREF pbSubscribed AS LONG _                       ' __out BOOL *pbSubscribed
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ExistsFeed ( _                                ' VTable offset = 20
     BYREF pszPath AS WSTRINGZ _                        ' __in LPCWSTR pszPath
   , BYREF pbFeedExists AS LONG _                       ' __out BOOL *pbFeedExists
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFeed ( _                                   ' VTable offset = 24
     BYREF pszPath AS WSTRINGZ _                        ' __in LPCWSTR pszPath
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppv AS IUnknown _                            ' __out void **ppv
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFeedByUrl ( _                              ' VTable offset = 28
     BYREF pszUrl AS WSTRINGZ _                         ' __in LPCWSTR pszUrl
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppv AS IUnknown _                            ' __out void **ppv
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ExistsFolder ( _                              ' VTable offset = 32
     BYREF pszPath AS WSTRINGZ _                        ' __in LPCWSTR pszPath
   , BYREF pbFolderExists AS LONG _                     ' __out BOOL *pbFolderExists
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFolder ( _                                 ' VTable offset = 36
     BYREF pszPath AS WSTRINGZ _                        ' __in LPCWSTR pszPath
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppv AS IUnknown _                            ' __out void **ppv
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DeleteFeed ( _                                ' VTable offset = 40
     BYREF pszPath AS WSTRINGZ _                        ' __in LPCWSTR pszPath
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DeleteFolder ( _                              ' VTable offset = 44
     BYREF pszPath AS WSTRINGZ _                        ' __in LPCWSTR pszPath
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD BackgroundSync ( _                            ' VTable offset = 48
     BYVAL fbsa AS DWORD _                              ' __in FEEDS_BACKGROUNDSYNC_ACTION fbsa
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD BackgroundSyncStatus ( _                      ' VTable offset = 52
     BYREF pfbss AS DWORD _                             ' __out FEEDS_BACKGROUNDSYNC_STATUS *pfbss
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DefaultInterval ( _                           ' VTable offset = 56
     BYREF puiInterval AS DWORD _                       ' __out UINT *puiInterval
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetDefaultInterval ( _                        ' VTable offset = 60
     BYVAL uiInterval AS LONG _                         ' __in UINT uiInterval
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AsyncSyncAll ( _                              ' VTable offset = 64
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Normalize ( _                                 ' VTable offset = 68
     BYVAL pStreamIn AS IStream _                       ' __in IStream *pStreamIn
   , BYREF ppStreamOut AS IStream _                     ' __out IStream **ppStreamOut
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ItemCountLimit ( _                            ' VTable offset = 72
     BYREF puiItemCountLimit AS DWORD _                 ' __out UINT *puiItemCountLimit
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IXFeedsManager_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IXFeedsEnum
' IID = DC43A9D5-5015-4301-8C96-A47434B4D658
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IXFeedsEnum_INTERFACE_DEFINED)
    %XIFeedsEnum_INTERFACE_DEFINED = 1

INTERFACE IXFeedsEnum $IID_IXFeedsEnum

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Count ( _                                     ' VTable offset = 12
     BYREF puiCount AS DWORD _                          ' __out UINT *puiCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Item ( _                                      ' VTable offset = 16
     BYREF uiIndex AS DWORD _                           ' __in UINT uiIndex
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppv AS IUnknown _                            ' __out void **ppv
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IXFeedsEnum_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IXFeedFolder
' IID = 4C963678-3A51-4B88-8531-98B90B6508F2
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IXFeedFolder_INTERFACE_DEFINED)
    %IXFeedFolder_INTERFACE_DEFINED = 1

INTERFACE IXFeedFolder $IID_IXFeedFolder

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Feeds ( _                                     ' VTable offset = 12
     BYREF ppfe AS IXFeedsEnum _                        ' __out IXFeedsEnum **ppfe
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Subfolders ( _                                ' VTable offset = 16
     BYREF ppfe AS IXFeedsEnum _                        ' __out IXFeedsEnum **ppfe
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateFeed ( _                                ' VTable offset = 20
     BYREF pszName AS WSTRINGZ _                        ' __in LPCWSTR pszName
   , BYREF pszUrl AS WSTRINGZ _                         ' __in LPCWSTR pszUrl
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppv AS IUnknown _                            ' __out void **ppv
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateSubfolder ( _                           ' VTable offset = 24
     BYREF pszName AS WSTRINGZ _                        ' __in LPCWSTR pszName
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppv AS IUnknown _                            ' __out void **ppv
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ExistsFeed ( _                                ' VTable offset = 28
     BYREF pszName AS WSTRINGZ _                        ' __in LPCWSTR pszName
   , BYREF pbFeedExists AS LONG _                       ' __out BOOL *pbFeedExists
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ExistsSubfolder ( _                           ' VTable offset = 32
     BYREF pszName AS WSTRINGZ _                        ' __in LPCWSTR pszName
   , BYVAL pbSubfolderExists AS LONG _                  ' __in BOOL *pbSubfolderExists
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFeed ( _                                   ' VTable offset = 36
     BYREF pszName AS WSTRINGZ  _                       ' __in LPCWSTR pszName
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppv AS IUnknown _                            ' __out void **ppv
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSubfolder ( _                              ' VTable offset = 40
     BYREF pszName AS WSTRINGZ _                        ' __in LPCWSTR pszName
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppv AS IUnknown _                            ' __out void **ppv
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Delete ( _                                    ' VTable offset = 44
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Name ( _                                      ' VTable offset = 48
     BYREF ppszName AS DWORD _                          ' __out LPWSTR *ppszName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Rename ( _                                    ' VTable offset = 52
     BYREF pszName AS WSTRINGZ _                        ' __in LPCWSTR pszName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Path ( _                                      ' VTable offset = 60
     BYREF ppszPath AS DWORD _                          ' __out LPWSTR *ppszPath
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Move ( _                                      ' VTable offset = 64
     BYREF pszPath AS WSTRINGZ _                        ' __in LPCWSTR pszPath
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Parent ( _                                    ' VTable offset = 68
     BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppv AS IUnknown _                            ' __out void **ppv
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsRoot ( _                                    ' VTable offset = 72
     BYREF pbIsRootFeedFolder AS LONG _                 ' __out BOOL *pbIsRootFeedFolder
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetWatcher ( _                                ' VTable offset = 76
     BYVAL scope AS DWORD _                             ' __in FEEDS_EVENTS_SCOPE scope
   , BYVAL mask AS DWORD _                              ' __in FEEDS_EVENTS_MASK mask
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppv AS IUnknown _                            ' __out void **ppv
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD TotalUnreadItemCount ( _                      ' VTable offset = 80
      BYREF puiTotalUnreadItemCount AS DWORD _          ' __out UINT *puiTotalUnreadItemCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD TotalItemCount ( _                            ' VTable offset = 84
     BYREF puiTotalItemCount AS DWORD _                 ' __out UINT *puiTotalItemCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IXFeedFolder_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IXFeedFolderEvents
' IID = 7964B769-234A-4BB1-A5F4-90454C8AD07E
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IXFeedFolderEvents_INTERFACE_DEFINED)
    %IXFeedFolderEvents_INTERFACE_DEFINED = 1

INTERFACE IXFeedFolderEvents $IID_IXFeedFolderEvents

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Error ( _                                     ' VTable offset = 12
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD FolderAdded ( _                               ' VTable offset = 16
     BYREF pszPath AS WSTRINGZ _                        ' __in LPCWSTR pszPath
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD FolderDeleted ( _                             ' VTable offset = 20
     BYREF pszPath AS WSTRINGZ _                        ' __in LPCWSTR pszPath
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD FolderRenamed ( _                             ' VTable offset = 24
     BYREF pszPath AS WSTRINGZ _                        ' __in LPCWSTR pszPath
   , BYREF pszOldPath AS WSTRINGZ _                     ' __in LPCWSTR pszOldPath
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD FolderMovedFrom ( _                           ' VTable offset = 28
     BYREF pszPath AS WSTRINGZ _                        ' __in LPCWSTR pszPath
   , BYREF pszOldPath AS WSTRINGZ _                     ' __in LPCWSTR pszOldPath
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD FolderMovedTo ( _                             ' VTable offset = 32
     BYREF pszPath AS WSTRINGZ _                        ' __in LPCWSTR pszPath
   , BYREF pszOldPath AS WSTRINGZ _                     ' __in LPCWSTR pszOldPath
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD FolderItemCountChanged ( _                    ' VTable offset = 36
     BYREF pszPath AS WSTRINGZ _                        ' __in LPCWSTR pszPath
   , BYVAL feicfFlags AS LONG _                         ' __in FEICF feicfFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD FeedAdded ( _                                 ' VTable offset = 40
     BYREF pszPath AS WSTRINGZ _                        ' __in LPCWSTR pszPath
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD FeedDeleted ( _                               ' VTable offset = 44
     BYREF pszPath AS WSTRINGZ _                        ' __in LPCWSTR pszPath
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD FeedRenamed ( _                               ' VTable offset = 48
     BYREF pszPath AS WSTRINGZ _                        ' __in LPCWSTR pszPath
   , BYREF pszOldPath AS WSTRINGZ _                     ' __in LPCWSTR pszOldPath
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD FeedUrlChanged ( _                            ' VTable offset = 52
     BYREF pszPath AS WSTRINGZ _                        ' __in LPCWSTR pszPath
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD FeedMovedFrom ( _                             ' VTable offset = 56
     BYREF pszPath AS WSTRINGZ _                        ' __in LPCWSTR pszPath
   , BYREF pszOldPath AS WSTRINGZ _                     ' __in LPCWSTR pszOldPath
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD FeedMovedTo ( _                               ' VTable offset = 60
     BYREF pszPath AS WSTRINGZ _                        ' __in LPCWSTR pszPath
   , BYREF pszOldPath AS WSTRINGZ _                     ' __in LPCWSTR pszOldPath
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD FeedDownloading ( _                           ' VTable offset = 64
     BYREF pszPath AS WSTRINGZ _                        ' __in LPCWSTR pszPath
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD FeedDownloadCompleted ( _                     ' VTable offset = 68
     BYREF pszPath AS WSTRINGZ _                        ' __in LPCWSTR pszPath
   , BYVAL fde AS DWORD _                               ' __in FEEDS_DOWNLOAD_ERROR fde
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD FeedItemCountChanged ( _                      ' VTable offset = 72
     BYREF pszPath AS WSTRINGZ _                        ' __in LPCWSTR pszPath
   , BYVAL feicfFlags AS LONG _                         ' __in FEICF feicfFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IXFeedFolderEvents_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IXFeed
' IID = A44179A4-E0F6-403B-AF8D-D080F425A451
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IXFeed_INTERFACE_DEFINED)
    %IXFeed_INTERFACE_DEFINED = 1

INTERFACE IXFeed $IID_IXFeed

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Xml ( _                                       ' VTable offset = 12
     BYVAL uiItemCount AS DWORD _                       ' __in UINT uiItemCount
   , BYVAL sortProperty AS DWORD _                      ' __in FEEDS_XML_SORT_PROPERTY sortProperty
   , BYVAL sortOrder AS DWORD _                         ' __in FEEDS_XML_SORT_ORDER sortOrder
   , BYVAL filterFlags AS DWORD _                       ' __in FEEDS_XML_FILTER_FLAGS filterFlags
   , BYVAL includeFlags AS DWORD _                      ' __in FEEDS_XML_INCLUDE_FLAGS includeFlags
   , BYREF pps AS IStream _                             ' __out IStream **pps
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Name ( _                                      ' VTable offset = 16
     BYREF ppszName AS DWORD _                          ' __out LPWSTR *ppszName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Rename ( _                                    ' VTable offset = 20
     BYREF pszName AS WSTRINGZ _                        ' __in LPCWSTR pszName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Url ( _                                       ' VTable offset = 24
     BYREF ppszUrl AS DWORD _                           ' __out LPWSTR *ppszUrl
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetUrl ( _                                    ' VTable offset = 28
     BYREF pszUrl AS WSTRINGZ _                         ' __in LPCWSTR pszUrl
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD LocalId ( _                                   ' VTable offset = 32
     BYREF pguid AS GUID _                              ' __out GUID *pguid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Path ( _                                      ' VTable offset = 36
     BYREF ppszPath AS DWORD _                          ' __out LPWSTR *ppszPath
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Move ( _                                      ' VTable offset = 40
     BYREF pszPath AS WSTRINGZ _                        ' __in LPCWSTR pszPath
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Parent ( _                                    ' VTable offset = 44
     BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppv AS IUnknown _                            ' __out void **ppv
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD LastWriteTime ( _                             ' VTable offset = 48
     BYREF pstLastWriteTime AS SYSTEMTIME _             ' __out SYSTEMTIME *pstLastWriteTime
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Delete ( _                                    ' VTable offset = 52
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Download ( _                                  ' VTable offset = 56
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AsyncDownload ( _                             ' VTable offset = 60
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CancelAsyncDownload ( _                       ' VTable offset = 64
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SyncSetting ( _                               ' VTable offset = 68
     BYREF pfss AS DWORD _                              ' __out FEEDS_SYNC_SETTING *pfss
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetSyncSetting ( _                            ' VTable offset = 72
     BYVAL fss AS DWORD _                               ' __in FEEDS_SYNC_SETTING fss
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Interval ( _                                  ' VTable offset = 76
     BYREF puiInterval AS DWORD _                       ' __out UINT *puiInterval
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetInterval ( _                               ' VTable offset = 80
     BYVAL uiInterval AS DWORD _                        ' __in UINT uiInterval
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD LastDownloadTime ( _                          ' VTable offset = 84
     BYREF pstLastDownloadTime AS SYSTEMTIME _          ' __out SYSTEMTIME *pstLastDownloadTime
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD LocalEnclosurePath ( _                        ' VTable offset = 88
     BYREF ppszPath AS DWORD _                          ' __out LPWSTR *ppszPath
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Items ( _                                     ' VTable offset = 92
     BYREF ppfe AS IXFeedsEnum _                        ' __out IXFeedsEnum **ppfe
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetItem ( _                                   ' VTable offset = 96
     BYVAL uiId AS DWORD _                              ' __in UINT uiId
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppv AS IUnknown _                            ' __out void **ppv
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD MarkAllItemsRead ( _                          ' VTable offset = 100
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD MaxItemCount ( _                              ' VTable offset = 104
     BYREF puiMaxItemCount AS DWORD _                   ' __out UINT *puiMaxItemCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetMaxItemCount ( _                           ' VTable offset = 108
     BYVAL uiMaxItemCount AS DWORD _                    ' __in UINT uiMaxItemCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DownloadEnclosuresAutomatically ( _           ' VTable offset = 112
     BYREF pbDownloadEnclosuresAutomatically AS LONG _  ' __out BOOL *pbDownloadEnclosuresAutomatically
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetDownloadEnclosuresAutomatically ( _        ' VTable offset = 116
     BYVAL bDownloadEnclosuresAutomatically AS LONG _   ' __in BOOL bDownloadEnclosuresAutomatically
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DownloadStatus ( _                            ' VTable offset = 120
     BYREF pfds AS DWORD _                              ' __out FEEDS_DOWNLOAD_STATUS *pfds
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD LastDownloadError ( _                         ' VTable offset = 124
     BYREF pfde AS DWORD _                              ' __out FEEDS_DOWNLOAD_ERROR *pfde
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Merge ( _                                     ' VTable offset = 128
     BYVAL pStream AS IStream _                         ' __in IStream *pStream
   , BYREF pszUrl AS WSTRINGZ _                         ' __in LPCWSTR pszUrl
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DownloadUrl ( _                               ' VTable offset = 132
     BYREF ppszUrl AS DWORD _                           ' __out LPWSTR *ppszUrl
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Title ( _                                     ' VTable offset = 136
     BYREF ppszTitle AS DWORD _                         ' __out LPWSTR *ppszTitle
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Description ( _                               ' VTable offset = 140
     BYREF ppszDescription AS DWORD _                   ' __out LPWSTR *ppszDescription
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Link ( _                                      ' VTable offset = 144
     BYREF ppszHomePage AS DWORD _                      ' __out LPWSTR *ppszHomePage
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Image ( _                                     ' VTable offset = 148
     BYREF ppszImageUrl AS DWORD _                      ' __out LPWSTR *ppszImageUrl
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD LastBuildDate ( _                             ' VTable offset = 152
     BYREF pstLastBuildDate AS SYSTEMTIME _             ' __out SYSTEMTIME *pstLastBuildDate
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD PubDate ( _                                   ' VTable offset = 156
     BYREF pstPubDate AS SYSTEMTIME _                   ' __out SYSTEMTIME *pstPubDate
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Ttl ( _                                       ' VTable offset = 160
     BYREF puiTtl AS DWORD _                            ' __out UINT *puiTtl
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Language ( _                                  ' VTable offset = 164
     BYREF ppszLanguage AS DWORD _                      ' __out LPWSTR *ppszLanguage
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Copyright ( _                                 ' VTable offset = 168
     BYREF ppszCopyright AS DWORD _                     ' __out LPWSTR *ppszCopyright
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsList ( _                                    ' VTable offset = 172
     BYREF pbIsList AS LONG _                           ' __out BOOL *pbIsList
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetWatcher ( _                                ' VTable offset = 176
     BYVAL scope AS DWORD _                             ' __in FEEDS_EVENTS_SCOPE scope
   , BYVAL mask AS DWORD _                              ' __in FEEDS_EVENTS_MASK mask
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppv AS IUnknown _                            ' __out void **ppv
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UnreadItemCount ( _                           ' VTable offset = 180
     BYREF puiUnreadItemCount AS DWORD _                ' __out UINT *puiUnreadItemCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ItemCount ( _                                 ' VTable offset = 184
     BYREF puiItemCount AS DWORD _                      ' __out UINT *puiItemCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IXFeed_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IXFeed2
' IID = CE528E77-3716-4EB7-956D-F5E37502E12A
' Inherited interface = IXFeed
' ########################################################################################

#IF NOT %DEF(%IXFeed2_INTERFACE_DEFINED)
    %IXFeed2_INTERFACE_DEFINED = 1

INTERFACE IXFeed2 $IID_IXFeed2

   INHERIT IUnknown

   ' =====================================================================================
   ' IXFeed methods
   ' =====================================================================================
   METHOD Xml ( _                                       ' VTable offset = 12
     BYVAL uiItemCount AS DWORD _                       ' __in UINT uiItemCount
   , BYVAL sortProperty AS DWORD _                      ' __in FEEDS_XML_SORT_PROPERTY sortProperty
   , BYVAL sortOrder AS DWORD _                         ' __in FEEDS_XML_SORT_ORDER sortOrder
   , BYVAL filterFlags AS DWORD _                       ' __in FEEDS_XML_FILTER_FLAGS filterFlags
   , BYVAL includeFlags AS DWORD _                      ' __in FEEDS_XML_INCLUDE_FLAGS includeFlags
   , BYREF pps AS IStream _                             ' __out IStream **pps
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Name ( _                                      ' VTable offset = 16
     BYREF ppszName AS DWORD _                          ' __out LPWSTR *ppszName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Rename ( _                                    ' VTable offset = 20
     BYREF pszName AS WSTRINGZ _                        ' __in LPCWSTR pszName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Url ( _                                       ' VTable offset = 24
     BYREF ppszUrl AS DWORD _                           ' __out LPWSTR *ppszUrl
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetUrl ( _                                    ' VTable offset = 28
     BYREF pszUrl AS WSTRINGZ _                         ' __in LPCWSTR pszUrl
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD LocalId ( _                                   ' VTable offset = 32
     BYREF pguid AS GUID _                              ' __out GUID *pguid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Path ( _                                      ' VTable offset = 36
     BYREF ppszPath AS DWORD _                          ' __out LPWSTR *ppszPath
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Move ( _                                      ' VTable offset = 40
     BYREF pszPath AS WSTRINGZ _                        ' __in LPCWSTR pszPath
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Parent ( _                                    ' VTable offset = 44
     BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppv AS IUnknown _                            ' __out void **ppv
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD LastWriteTime ( _                             ' VTable offset = 48
     BYREF pstLastWriteTime AS SYSTEMTIME _             ' __out SYSTEMTIME *pstLastWriteTime
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Delete ( _                                    ' VTable offset = 52
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Download ( _                                  ' VTable offset = 56
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AsyncDownload ( _                             ' VTable offset = 60
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CancelAsyncDownload ( _                       ' VTable offset = 64
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SyncSetting ( _                               ' VTable offset = 68
     BYREF pfss AS DWORD _                              ' __out FEEDS_SYNC_SETTING *pfss
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetSyncSetting ( _                            ' VTable offset = 72
     BYVAL fss AS DWORD _                               ' __in FEEDS_SYNC_SETTING fss
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Interval ( _                                  ' VTable offset = 76
     BYREF puiInterval AS DWORD _                       ' __out UINT *puiInterval
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetInterval ( _                               ' VTable offset = 80
     BYVAL uiInterval AS DWORD _                        ' __in UINT uiInterval
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD LastDownloadTime ( _                          ' VTable offset = 84
     BYREF pstLastDownloadTime AS SYSTEMTIME _          ' __out SYSTEMTIME *pstLastDownloadTime
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD LocalEnclosurePath ( _                        ' VTable offset = 88
     BYREF ppszPath AS DWORD _                          ' __out LPWSTR *ppszPath
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Items ( _                                     ' VTable offset = 92
     BYREF ppfe AS IXFeedsEnum _                        ' __out IXFeedsEnum **ppfe
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetItem ( _                                   ' VTable offset = 96
     BYVAL uiId AS DWORD _                              ' __in UINT uiId
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppv AS IUnknown _                            ' __out void **ppv
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD MarkAllItemsRead ( _                          ' VTable offset = 100
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD MaxItemCount ( _                              ' VTable offset = 104
     BYREF puiMaxItemCount AS DWORD _                   ' __out UINT *puiMaxItemCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetMaxItemCount ( _                           ' VTable offset = 108
     BYVAL uiMaxItemCount AS DWORD _                    ' __in UINT uiMaxItemCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DownloadEnclosuresAutomatically ( _           ' VTable offset = 112
     BYREF pbDownloadEnclosuresAutomatically AS LONG _  ' __out BOOL *pbDownloadEnclosuresAutomatically
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetDownloadEnclosuresAutomatically ( _        ' VTable offset = 116
     BYVAL bDownloadEnclosuresAutomatically AS LONG _   ' __in BOOL bDownloadEnclosuresAutomatically
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DownloadStatus ( _                            ' VTable offset = 120
     BYREF pfds AS DWORD _                              ' __out FEEDS_DOWNLOAD_STATUS *pfds
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD LastDownloadError ( _                         ' VTable offset = 124
     BYREF pfde AS DWORD _                              ' __out FEEDS_DOWNLOAD_ERROR *pfde
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Merge ( _                                     ' VTable offset = 128
     BYVAL pStream AS IStream _                         ' __in IStream *pStream
   , BYREF pszUrl AS WSTRINGZ _                         ' __in LPCWSTR pszUrl
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DownloadUrl ( _                               ' VTable offset = 132
     BYREF ppszUrl AS DWORD _                           ' __out LPWSTR *ppszUrl
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Title ( _                                     ' VTable offset = 136
     BYREF ppszTitle AS DWORD _                         ' __out LPWSTR *ppszTitle
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Description ( _                               ' VTable offset = 140
     BYREF ppszDescription AS DWORD _                   ' __out LPWSTR *ppszDescription
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Link ( _                                      ' VTable offset = 144
     BYREF ppszHomePage AS DWORD _                      ' __out LPWSTR *ppszHomePage
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Image ( _                                     ' VTable offset = 148
     BYREF ppszImageUrl AS DWORD _                      ' __out LPWSTR *ppszImageUrl
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD LastBuildDate ( _                             ' VTable offset = 152
     BYREF pstLastBuildDate AS SYSTEMTIME _             ' __out SYSTEMTIME *pstLastBuildDate
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD PubDate ( _                                   ' VTable offset = 156
     BYREF pstPubDate AS SYSTEMTIME _                   ' __out SYSTEMTIME *pstPubDate
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Ttl ( _                                       ' VTable offset = 160
     BYREF puiTtl AS DWORD _                            ' __out UINT *puiTtl
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Language ( _                                  ' VTable offset = 164
     BYREF ppszLanguage AS DWORD _                      ' __out LPWSTR *ppszLanguage
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Copyright ( _                                 ' VTable offset = 168
     BYREF ppszCopyright AS DWORD _                     ' __out LPWSTR *ppszCopyright
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsList ( _                                    ' VTable offset = 172
     BYREF pbIsList AS LONG _                           ' __out BOOL *pbIsList
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetWatcher ( _                                ' VTable offset = 176
     BYVAL scope AS DWORD _                             ' __in FEEDS_EVENTS_SCOPE scope
   , BYVAL mask AS DWORD _                              ' __in FEEDS_EVENTS_MASK mask
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppv AS IUnknown _                            ' __out void **ppv
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UnreadItemCount ( _                           ' VTable offset = 180
     BYREF puiUnreadItemCount AS DWORD _                ' __out UINT *puiUnreadItemCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ItemCount ( _                                 ' VTable offset = 184
     BYREF puiItemCount AS DWORD _                      ' __out UINT *puiItemCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IXFeed2 methods
   ' =====================================================================================
   METHOD GetItemByEffectiveId ( _                      ' VTable offset = 188
     BYVAL uiEffectiveId AS DWORD _                     ' __in UINT uiEffectiveId
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppv AS IUnknown _                            ' __out void **ppv
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD LastItemDownloadTime ( _                      ' VTable offset = 192
     BYREF pstLastItemDownloadTime AS SYSTEMTIME _      ' __out SYSTEMTIME *pstLastItemDownloadTime
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Username ( _                                  ' VTable offset = 196
     BYREF ppszUsername AS DWORD _                      ' __out LPWSTR *ppszUsername
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Password ( _                                  ' VTable offset = 200
     BYREF ppszPassword AS DWORD _                      ' __out LPWSTR *ppszPassword
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetCredentials ( _                            ' VTable offset = 204
     BYREF pszUsername AS WSTRINGZ _                    ' __in LPCWSTR pszUsername
   , BYREF pszPassword AS WSTRINGZ _                    ' __in LPCWSTR pszPassword
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ClearCredentials ( _                          ' VTable offset = 208
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IXFeed2_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IXFeedEvents
' IID = 1630852E-1263-465B-98E5-FE60FFEC4AC2
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IXFeedEvents_INTERFACE_DEFINED)
    %IXFeedEvents_INTERFACE_DEFINED = 1

INTERFACE IXFeedEvents $IID_IXFeedEvents

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Error ( _                                     ' VTable offset = 12
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD FeedDeleted ( _                               ' VTable offset = 16
     BYREF pszPath AS WSTRINGZ _                        ' __in LPCWSTR pszPath
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD FeedRenamed ( _                               ' VTable offset = 20
     BYREF pszPath AS WSTRINGZ _                        ' __in LPCWSTR pszPath
   , BYREF pszOldPath AS WSTRINGZ _                     ' __in LPCWSTR pszOldPath
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD FeedUrlChanged ( _                            ' VTable offset = 24
     BYREF pszPath AS WSTRINGZ _                        ' __in LPCWSTR pszPath
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD FeedMoved ( _                                 ' VTable offset = 28
     BYREF pszPath AS WSTRINGZ _                        ' __in LPCWSTR pszPath
   , BYREF pszOldPath AS WSTRINGZ _                     ' __in LPCWSTR pszOldPath
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD FeedDownloading ( _                           ' VTable offset = 32
     BYREF pszPath AS WSTRINGZ _                        ' __in LPCWSTR pszPath
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD FeedDownloadCompleted ( _                     ' VTable offset = 36
     BYREF pszPath AS WSTRINGZ _                        ' __in LPCWSTR pszPath
   , BYVAL fde AS DWORD _                               ' __in FEEDS_DOWNLOAD_ERROR fde
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD FeedItemCountChanged ( _                      ' VTable offset = 40
     BYREF pszPath AS WSTRINGZ _                        ' __in LPCWSTR pszPath
   , BYVAL feicfFlags AS DWORD _                        ' __in FEICF feicfFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IXFeedEvents_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IXFeedItem
' IID = E757B2F5-E73E-434E-A1BF-2BD7C3E60FCB
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IXFeedItem_INTERFACE_DEFINED)
    %XIFeedItem_INTERFACE_DEFINED = 1

INTERFACE IXFeedItem $IID_IXFeedItem

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Xml ( _                                       ' VTable offset = 12
     BYVAL fxif AS DWORD _                              ' __in FEEDS_XML_INCLUDE_FLAGS fxif
   , BYREF pps AS IStream _                             ' __out IStream **pps
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Title ( _                                     ' VTable offset = 16
     BYREF ppszTitle AS DWORD _                         ' __out LPWSTR *ppszTitle
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Link ( _                                      ' VTable offset = 20
     BYREF ppszUrl AS DWORD _                           ' __out LPWSTR *ppszUrl
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Guid ( _                                      ' VTable offset = 24
     BYREF ppszGuid AS DWORD _                          ' __out LPWSTR *ppszGuid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Description ( _                               ' VTable offset = 28
     BYREF ppszDescription AS DWORD _                   ' __out LPWSTR *ppszDescription
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD PubDate ( _                                   ' VTable offset = 32
     BYREF pstPubDate AS DWORD _                        ' __out SYSTEMTIME *pstPubDate
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Comments ( _                                  ' VTable offset = 36
     BYREF ppszUrl AS DWORD _                           ' __out LPWSTR *ppszUrl
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Author ( _                                    ' VTable offset = 40
     BYREF ppszAuthor AS DWORD _                        ' __out LPWSTR *ppszAuthor
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Enclosure ( _                                 ' VTable offset = 44
     BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppv AS IUnknown _                            ' __out void **ppv
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsRead ( _                                    ' VTable offset = 48
     BYREF pbIsRead AS LONG _                           ' __out BOOL *pbIsRead
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetIsRead ( _                                 ' VTable offset = 52
     BYVAL bIsRead AS LONG _                            ' __in BOOL bIsRead
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD LocalId ( _                                   ' VTable offset = 56
     BYREF puiId AS DWORD _                             ' __out UINT *puiId
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Parent ( _                                    ' VTable offset = 60
     BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppv AS IUnknown _                            ' __out void **ppv
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Delete ( _                                    ' VTable offset = 64
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DownloadUrl ( _                               ' VTable offset = 68
     BYREF ppszUrl AS DWORD _                           ' __out LPWSTR *ppszUrl
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD LastDownloadTime ( _                          ' VTable offset = 72
     BYREF pstLastDownloadTime AS SYSTEMTIME _          ' __out SYSTEMTIME *pstLastDownloadTime
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Modified ( _                                  ' VTable offset = 76
     BYREF pstModifiedTime AS SYSTEMTIME _              ' __out SYSTEMTIME *pstModifiedTime
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IXFeedItem_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IXFeedItem2
' IID = 6CDA2DC7-9013-4522-9970-2A9DD9EAD5A3
' Inherited interface = IXFeedItem
' ########################################################################################

#IF NOT %DEF(%IXFeedItem2_INTERFACE_DEFINED)
    %XIFeedItem2_INTERFACE_DEFINED = 1

INTERFACE IXFeedItem2 $IID_IXFeedItem2

   INHERIT IUnknown

   ' =====================================================================================
   ' IXFeedItem Methods
   ' =====================================================================================
   METHOD Xml ( _                                       ' VTable offset = 12
     BYVAL fxif AS DWORD _                              ' __in FEEDS_XML_INCLUDE_FLAGS fxif
   , BYREF pps AS IStream _                             ' __out IStream **pps
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Title ( _                                     ' VTable offset = 16
     BYREF ppszTitle AS DWORD _                         ' __out LPWSTR *ppszTitle
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Link ( _                                      ' VTable offset = 20
     BYREF ppszUrl AS DWORD _                           ' __out LPWSTR *ppszUrl
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Guid ( _                                      ' VTable offset = 24
     BYREF ppszGuid AS DWORD _                          ' __out LPWSTR *ppszGuid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Description ( _                               ' VTable offset = 28
     BYREF ppszDescription AS DWORD _                   ' __out LPWSTR *ppszDescription
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD PubDate ( _                                   ' VTable offset = 32
     BYREF pstPubDate AS DWORD _                        ' __out SYSTEMTIME *pstPubDate
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Comments ( _                                  ' VTable offset = 36
     BYREF ppszUrl AS DWORD _                           ' __out LPWSTR *ppszUrl
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Author ( _                                    ' VTable offset = 40
     BYREF ppszAuthor AS DWORD _                        ' __out LPWSTR *ppszAuthor
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Enclosure ( _                                 ' VTable offset = 44
     BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppv AS IUnknown _                            ' __out void **ppv
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsRead ( _                                    ' VTable offset = 48
     BYREF pbIsRead AS LONG _                           ' __out BOOL *pbIsRead
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetIsRead ( _                                 ' VTable offset = 52
     BYVAL bIsRead AS LONG _                            ' __in BOOL bIsRead
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD LocalId ( _                                   ' VTable offset = 56
     BYREF puiId AS DWORD _                             ' __out UINT *puiId
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Parent ( _                                    ' VTable offset = 60
     BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppv AS IUnknown _                            ' __out void **ppv
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Delete ( _                                    ' VTable offset = 64
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DownloadUrl ( _                               ' VTable offset = 68
     BYREF ppszUrl AS DWORD _                           ' __out LPWSTR *ppszUrl
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD LastDownloadTime ( _                          ' VTable offset = 72
     BYREF pstLastDownloadTime AS SYSTEMTIME _          ' __out SYSTEMTIME *pstLastDownloadTime
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Modified ( _                                  ' VTable offset = 76
     BYREF pstModifiedTime AS SYSTEMTIME _              ' __out SYSTEMTIME *pstModifiedTime
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IXFeedItem2 Methods
   ' =====================================================================================
   METHOD EffectiveId ( _                               ' VTable offset = 80
     BYREF puiEffectiveId AS DWORD _                    ' __out UINT *puiEffectiveId
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IXFeedItem2_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IXFeedEnclosure
' IID = BFBFB953-644F-4792-B69C-DFACA4CBF89A
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IXFeedEnclosure_INTERFACE_DEFINED)
    %IXFeedEnclosure_INTERFACE_DEFINED = 1

INTERFACE IXFeedEnclosure $IID_IXFeedEnclosure

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Url ( _                                       ' VTable offset = 12
     BYREF ppszUrl AS DWORD _                           ' __out LPWSTR *ppszUrl
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Type ( _                                      ' VTable offset = 16
     BYREF ppszMimeType AS DWORD _                      ' __out LPWSTR *ppszMimeType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Length ( _                                    ' VTable offset = 20
     BYREF puiLength AS DWORD _                         ' __out UINT *puiLength
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AsyncDownload ( _                             ' VTable offset = 24
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CancelAsyncDownload ( _                       ' VTable offset = 28
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DownloadStatus ( _                            ' VTable offset = 32
     BYREF pfds AS DWORD _                              ' __out FEEDS_DOWNLOAD_STATUS *pfds
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD LastDownloadError ( _                         ' VTable offset = 36
     BYREF pfde AS DWORD _                              ' __out FEEDS_DOWNLOAD_ERROR *pfde
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD LocalPath ( _                                 ' VTable offset = 40
     BYREF ppszPath AS DWORD _                          ' __out LPWSTR *ppszPath
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Parent ( _                                    ' VTable offset = 44
     BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppv AS IUnknown _                            ' __out void **ppv
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DownloadUrl ( _                               ' VTable offset = 48
     BYREF ppszUrl AS DWORD _                           ' __out LPWSTR *ppszUrl
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DownloadMimeType ( _                          ' VTable offset = 52
     BYREF ppszMimeType AS DWORD _                      ' __out LPWSTR *ppszMimeType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RemoveFile ( _                                ' VTable offset = 56
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetFile ( _                                   ' VTable offset = 60
     BYREF pszDownloadUrl AS WSTRINGZ _                 ' __in LPCWSTR pszDownloadUrl
   , BYREF pszDownloadFilePath AS WSTRINGZ _            ' __in LPCWSTR pszDownloadFilePath
   , BYREF pszDownloadMimeType AS WSTRINGZ _            ' __in LPCWSTR pszDownloadMimeType
   , BYREF pszEnclosureFilename AS WSTRINGZ _           ' __in LPCWSTR pszEnclosureFilename
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IXFeedEnclosure_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IFeedsManager
' IID = {A74029CC-1F1A-4906-88F0-810638D86591}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IFeedsManager_INTERFACE_DEFINED)
    %IFeedsManager_INTERFACE_DEFINED = 1

INTERFACE IFeedsManager $IID_IFeedsManager

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET RootFolder <4096> ( _                   ' VTable offset = 28
   ) AS IDispatch                                       ' __retval_out IDispatch **disp
   ' =====================================================================================
   METHOD IsSubscribed <4097> ( _                       ' VTable offset = 32
     BYVAL feedUrl AS WSTRING _                         ' __in BSTR feedUrl
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *subscribed
   ' =====================================================================================
   METHOD ExistsFeed <4098> ( _                         ' VTable offset = 36
     BYVAL feedPath AS WSTRING _                        ' __in BSTR feedPath
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *exists
   ' =====================================================================================
   METHOD GetFeed <4099> ( _                            ' VTable offset = 40
     BYVAL feedPath AS WSTRING _                        ' __in BSTR feedPath
   ) AS IDispatch                                       ' __retval_out IDispatch **disp
   ' =====================================================================================
   METHOD GetFeedByUrl <4104> ( _                       ' VTable offset = 44
     BYVAL feedUrl AS WSTRING _                         ' __in BSTR feedUrl
   ) AS IDispatch                                       ' __retval_out IDispatch **disp
   ' =====================================================================================
   METHOD ExistsFolder <4100> ( _                       ' VTable offset = 48
     BYVAL folderPath AS WSTRING _                      ' __in BSTR folderPath
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *exists
   ' =====================================================================================
   METHOD GetFolder <4101> ( _                          ' VTable offset = 52
     BYVAL folderPath AS WSTRING _                      ' __in BSTR folderPath
   ) AS IDispatch                                       ' __retval_out IDispatch **disp
   ' =====================================================================================
   METHOD DeleteFeed <4102> ( _                         ' VTable offset = 56
     BYVAL feedPath AS WSTRING _                        ' __in BSTR feedPath
   )                                                    ' VOID
   ' =====================================================================================
   METHOD DeleteFolder <4103> ( _                       ' VTable offset = 60
     BYVAL folderPath AS WSTRING _                      ' __in BSTR folderPath
   )                                                    ' VOID
   ' =====================================================================================
   METHOD BackgroundSync <4105> ( _                     ' VTable offset = 64
     BYVAL action AS LONG _                             ' __in FEEDS_BACKGROUNDSYNC_ACTION action
   )                                                    ' VOID
   ' =====================================================================================
   PROPERTY GET BackgroundSyncStatus <4106> ( _         ' VTable offset = 68
   ) AS LONG                                            ' __retval_out FEEDS_BACKGROUNDSYNC_STATUS *status
   ' =====================================================================================
   PROPERTY GET DefaultInterval <4107> ( _              ' VTable offset = 72
   ) AS LONG                                            ' __retval_out LONG *minutes
   ' =====================================================================================
   PROPERTY SET DefaultInterval <4107> ( _              ' VTable offset = 76
     BYVAL minutes AS LONG _                            ' __in LONG minutes
   )                                                    ' VOID
   ' =====================================================================================
   METHOD AsyncSyncAll <4108> ( _                       ' VTable offset = 80
   )                                                    ' VOID
   ' =====================================================================================
   METHOD Normalize <4109> ( _                          ' VTable offset = 84
     BYVAL feedXmlIn AS WSTRING _                       ' __in BSTR feedXmlIn
   ) AS WSTRING                                         ' __retval_out BSTR *feedXmlOut
   ' =====================================================================================
   PROPERTY GET ItemCountLimit <4110> ( _               ' VTable offset = 88
   ) AS LONG                                            ' __retval_out LONG *itemCountLimit
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IFeedsManager_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IFeedsEnum
' IID = {E3CD0028-2EED-4C60-8FAE-A3225309A836}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IFeedsEnum_INTERFACE_DEFINED)
    %IFeedsEnum_INTERFACE_DEFINED = 1

INTERFACE IFeedsEnum $IID_IFeedsEnum

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Count <8192> ( _                        ' VTable offset = 28
   ) AS LONG                                            ' __retval_out LONG *count
   ' =====================================================================================
   METHOD Item <8193> ( _                               ' VTable offset = 32
     BYVAL index AS LONG _                              ' __in LONG index
   ) AS IDispatch                                       ' __retval_out IDispatch **disp
   ' =====================================================================================
   PROPERTY GET NewEnum_ <-4> ( _                       ' VTable offset = 36
   ) AS IUnknown                                        ' __retval_out IEnumVARIANT **enumVar
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IFeedsEnum_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IFeedFolder
' IID = {81F04AD1-4194-4D7D-86D6-11813CEC163C}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IFeedFolder_INTERFACE_DEFINED)
    %IFeedFolder_INTERFACE_DEFINED = 1

INTERFACE IFeedFolder $IID_IFeedFolder

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Feeds <12288> ( _                       ' VTable offset = 28
   ) AS IDispatch                                       ' __retval_out IDispatch **disp
   ' =====================================================================================
   PROPERTY GET Subfolders <12289> ( _                  ' VTable offset = 32
   ) AS IDispatch                                       ' __retval_out IDispatch **disp
   ' =====================================================================================
   METHOD CreateFeed <12290> ( _                        ' VTable offset = 36
     BYVAL feedName AS WSTRING _                        ' __in BSTR feedName
   , BYVAL feedUrl AS WSTRING _                         ' __in BSTR feedUrl
   ) AS IDispatch                                       ' __retval_out IDispatch **disp
   ' =====================================================================================
   METHOD CreateSubfolder <12291> ( _                   ' VTable offset = 40
     BYVAL folderName AS WSTRING _                      ' __in BSTR folderName
   ) AS IDispatch                                       ' __retval_out IDispatch **disp
   ' =====================================================================================
   METHOD ExistsFeed <12292> ( _                        ' VTable offset = 44
     BYVAL feedName AS WSTRING _                        ' __in BSTR feedName
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *exists
   ' =====================================================================================
   METHOD GetFeed <12293> ( _                           ' VTable offset = 48
     BYVAL feedName AS WSTRING _                        ' __in BSTR feedName
   ) AS IDispatch                                       ' __retval_out IDispatch **disp
   ' =====================================================================================
   METHOD ExistsSubfolder <12294> ( _                   ' VTable offset = 52
     BYVAL folderName AS WSTRING _                      ' __in BSTR folderName
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *exists
   ' =====================================================================================
   METHOD GetSubfolder <12295> ( _                      ' VTable offset = 56
     BYVAL folderName AS WSTRING _                      ' __in BSTR folderName
   ) AS IDispatch                                       ' __retval_out IDispatch **disp
   ' =====================================================================================
   METHOD Delete <12296> ( _                            ' VTable offset = 60
   )                                                    ' VOID
   ' =====================================================================================
   PROPERTY GET Name <12297> ( _                        ' VTable offset = 64
   ) AS WSTRING                                         ' __retval_out BSTR *folderName
   ' =====================================================================================
   METHOD Rename <12298> ( _                            ' VTable offset = 68
     BYVAL folderName AS WSTRING _                      ' __in BSTR folderName
   )                                                    ' VOID
   ' =====================================================================================
   PROPERTY GET Path <12299> ( _                        ' VTable offset = 72
   ) AS WSTRING                                         ' __retval_out BSTR *folderPath
   ' =====================================================================================
   METHOD Move <12300> ( _                              ' VTable offset = 76
     BYVAL newParentPath AS WSTRING _                   ' __in BSTR newParentPath
   )                                                    ' VOID
   ' =====================================================================================
   PROPERTY GET Parent <12301> ( _                      ' VTable offset = 80
   ) AS IDispatch                                       ' __retval_out IDispatch **disp
   ' =====================================================================================
   PROPERTY GET IsRoot <12302> ( _                      ' VTable offset = 84
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *isRoot
   ' =====================================================================================
   PROPERTY GET TotalUnreadItemCount <12303> ( _        ' VTable offset = 88
   ) AS LONG                                            ' __retval_out LONG *count
   ' =====================================================================================
   PROPERTY GET TotalItemCount <12304> ( _              ' VTable offset = 92
   ) AS LONG                                            ' __retval_out LONG *count
   ' =====================================================================================
   METHOD GetWatcher <12305> ( _                        ' VTable offset = 96
     BYVAL scope AS LONG _                              ' __in FEEDS_EVENTS_SCOPE scope
   , BYVAL mask AS LONG _                               ' __in FEEDS_EVENTS_MASK mask
   ) AS IDispatch                                       ' __retval_out IDispatch **disp
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IFeedFolder_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IFeedFolderEvents
' IID = 20A59FA6-A844-4630-9E98-175F70B4D55B
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IFeedFolderEvents_INTERFACE_DEFINED)
    %IFeedFolderEvents_INTERFACE_DEFINED = 1

INTERFACE IFeedFolderEvents $IID_IFeedFolderEvents

   INHERIT IDispatch

   ' =====================================================================================
   METHOD Error <28672> ( _                             ' VTable offset = 12
   )                                                    ' void
   ' =====================================================================================
   METHOD FolderAdded <28673> ( _                       ' VTable offset = 16
     BYVAL path AS WSTRING _                            ' __in const BSTR path
   )                                                    ' void
   ' =====================================================================================
   METHOD FolderDeleted <28674> ( _                     ' VTable offset = 20
     BYVAL path AS WSTRING _                            ' __in const BSTR path
   )                                                    ' void
   ' =====================================================================================
   METHOD FolderRenamed <28675> ( _                     ' VTable offset = 24
     BYVAL path AS WSTRING _                            ' __in const BSTR path
   , BYVAL oldPath AS WSTRING _                         ' __in const BSTR oldPath
   )                                                    ' void
   ' =====================================================================================
   METHOD FolderMovedFrom <28676> ( _                   ' VTable offset = 28
     BYVAL path AS WSTRING _                            ' __in const BSTR path
   , BYVAL oldPath AS WSTRING _                         ' __in const BSTR oldPath
   )                                                    ' void
   ' =====================================================================================
   METHOD FolderMovedTo <28677> ( _                     ' VTable offset = 32
     BYVAL path AS WSTRING _                            ' __in const BSTR path
   , BYVAL oldPath AS WSTRING _                         ' __in const BSTR oldPath
   )                                                    ' void
   ' =====================================================================================
   METHOD FolderItemCountChanged <28678> ( _            ' VTable offset = 36
     BYVAL path AS WSTRING _                            ' __in const BSTR path
   , BYVAL itemCountType AS LONG _                      ' __in LONG itemCountType
   )                                                    ' void
   ' =====================================================================================
   METHOD FeedAdded <28679> ( _                         ' VTable offset = 40
     BYVAL path AS WSTRING _                            ' __in const BSTR path
   )                                                    ' void
   ' =====================================================================================
   METHOD FeedDeleted <28680> ( _                       ' VTable offset = 44
     BYVAL path AS WSTRING _                            ' __in const BSTR path
   )                                                    ' void
   ' =====================================================================================
   METHOD FeedRenamed <28681> ( _                       ' VTable offset = 48
     BYVAL path AS WSTRING _                            ' __in const BSTR path
   , BYVAL oldPath AS WSTRING _                         ' __in const BSTR oldPath
   )                                                    ' void
   ' =====================================================================================
   METHOD FeedUrlChanged <28682> ( _                    ' VTable offset = 52
     BYVAL path AS WSTRING _                            ' __in const BSTR path
   )                                                    ' void
   ' =====================================================================================
   METHOD FeedMovedFrom <28683> ( _                     ' VTable offset = 56
     BYVAL path AS WSTRING _                            ' __in const BSTR path
   , BYVAL oldPath AS WSTRING _                         ' __in const BSTR oldPath
   )                                                    ' void
   ' =====================================================================================
   METHOD FeedMovedTo <28684> ( _                       ' VTable offset = 60
     BYVAL path AS WSTRING _                            ' __in const BSTR path
   , BYVAL oldPath AS WSTRING _                         ' __in const BSTR oldPath
   )                                                    ' void
   ' =====================================================================================
   METHOD FeedDownloading <28685> ( _                   ' VTable offset = 64
     BYVAL path AS WSTRING _                            ' __in const BSTR path
   )                                                    ' void
   ' =====================================================================================
   METHOD FeedDownloadCompleted <28686> ( _             ' VTable offset = 68
     BYVAL path AS WSTRING _                            ' __in const BSTR path
   , BYVAL fde AS LONG _                                ' __in FEEDS_DOWNLOAD_ERROR fde
   )                                                    ' void
   ' =====================================================================================
   METHOD FeedItemCountChanged <28687> ( _              ' VTable offset = 72
     BYVAL path AS WSTRING _                            ' __in const BSTR path
   , BYVAL feicfFlags AS LONG _                         ' __in FEICF feicfFlags
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IFeedFolderEvents_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IFeed
' IID = {F7F915D8-2EDE-42BC-98E7-A5D05063A757}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IFeed_INTERFACE_DEFINED)
    %IFeed_INTERFACE_DEFINED = 1

INTERFACE IFeed $IID_IFeed

   INHERIT IDispatch

   ' =====================================================================================
   METHOD Xml <16384> ( _                               ' VTable offset = 28
     BYVAL count AS LONG _                              ' __in LONG count
   , BYVAL sortProperty AS LONG _                       ' __in FEEDS_XML_SORT_PROPERTY sortProperty
   , BYVAL sortOrder AS LONG _                          ' __in FEEDS_XML_SORT_ORDER sortOrder
   , BYVAL filterFlags AS LONG _                        ' __in FEEDS_XML_FILTER_FLAGS filterFlags
   , BYVAL includeFlags AS LONG _                       ' __in FEEDS_XML_INCLUDE_FLAGS includeFlags
   ) AS WSTRING                                         ' __retval_out BSTR *xml
   ' =====================================================================================
   PROPERTY GET Name <16385> ( _                        ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR *name
   ' =====================================================================================
   METHOD Rename <16386> ( _                            ' VTable offset = 36
     BYVAL name AS WSTRING _                            ' __in BSTR name
   )                                                    ' VOID
   ' =====================================================================================
   PROPERTY GET Url <16387> ( _                         ' VTable offset = 40
   ) AS WSTRING                                         ' __retval_out BSTR *feedUrl
   ' =====================================================================================
   PROPERTY SET Url <16387> ( _                         ' VTable offset = 44
     BYVAL feedUrl AS WSTRING _                         ' __in BSTR feedUrl
   )                                                    ' VOID
   ' =====================================================================================
   PROPERTY GET LocalId <16388> ( _                     ' VTable offset = 48
   ) AS WSTRING                                         ' __retval_out BSTR *feedGuid
   ' =====================================================================================
   PROPERTY GET Path <16389> ( _                        ' VTable offset = 52
   ) AS WSTRING                                         ' __retval_out BSTR *path
   ' =====================================================================================
   METHOD Move <16390> ( _                              ' VTable offset = 56
     BYVAL newParentPath AS WSTRING _                   ' __in BSTR newParentPath
   )                                                    ' VOID
   ' =====================================================================================
   PROPERTY GET Parent <16391> ( _                      ' VTable offset = 60
   ) AS IDispatch                                       ' __retval_out IDispatch **disp
   ' =====================================================================================
   PROPERTY GET LastWriteTime <16392> ( _               ' VTable offset = 64
   ) AS DOUBLE                                          ' __retval_out DATE *lastWrite
   ' =====================================================================================
   METHOD Delete <16393> ( _                            ' VTable offset = 68
   )                                                    ' VOID
   ' =====================================================================================
   METHOD Download <16394> ( _                          ' VTable offset = 72
   )                                                    ' VOID
   ' =====================================================================================
   METHOD AsyncDownload <16395> ( _                     ' VTable offset = 76
   )                                                    ' VOID
   ' =====================================================================================
   METHOD CancelAsyncDownload <16396> ( _               ' VTable offset = 80
   )                                                    ' VOID
   ' =====================================================================================
   PROPERTY GET SyncSetting <16398> ( _                 ' VTable offset = 84
   ) AS LONG                                            ' __retval_out FEEDS_SYNC_SETTING *syncSetting
   ' =====================================================================================
   PROPERTY SET SyncSetting <16398> ( _                 ' VTable offset = 88
     BYVAL syncSetting AS LONG _                        ' __in FEEDS_SYNC_SETTING syncSetting
   )                                                    ' VOID
   ' =====================================================================================
   PROPERTY GET Interval <16397> ( _                    ' VTable offset = 92
   ) AS LONG                                            ' __retval_out LONG *minutes
   ' =====================================================================================
   PROPERTY SET Interval <16397> ( _                    ' VTable offset = 96
     BYVAL minutes AS LONG _                            ' __in LONG minutes
   )                                                    ' VOID
   ' =====================================================================================
   PROPERTY GET LastDownloadTime <16399> ( _            ' VTable offset = 100
   ) AS DOUBLE                                          ' __retval_out DATE *lastDownload
   ' =====================================================================================
   PROPERTY GET LocalEnclosurePath <16400> ( _          ' VTable offset = 104
   ) AS WSTRING                                         ' __retval_out BSTR *path
   ' =====================================================================================
   PROPERTY GET Items <16401> ( _                       ' VTable offset = 108
   ) AS IDispatch                                       ' __retval_out IDispatch **disp
   ' =====================================================================================
   METHOD GetItem <16402> ( _                           ' VTable offset = 112
     BYVAL itemId AS LONG _                             ' __in LONG itemId
   ) AS IDispatch                                       ' __retval_out IDispatch **disp
   ' =====================================================================================
   PROPERTY GET Title <16403> ( _                       ' VTable offset = 116
   ) AS WSTRING                                         ' __retval_out BSTR *title
   ' =====================================================================================
   PROPERTY GET Description <16404> ( _                 ' VTable offset = 120
   ) AS WSTRING                                         ' __retval_out BSTR *description
   ' =====================================================================================
   PROPERTY GET Link <16405> ( _                        ' VTable offset = 124
   ) AS WSTRING                                         ' __retval_out BSTR *homePage
   ' =====================================================================================
   PROPERTY GET Image <16406> ( _                       ' VTable offset = 128
   ) AS WSTRING                                         ' __retval_out BSTR *imageUrl
   ' =====================================================================================
   PROPERTY GET LastBuildDate <16407> ( _               ' VTable offset = 132
   ) AS DOUBLE                                          ' __retval_out DATE *lastBuildDate
   ' =====================================================================================
   PROPERTY GET PubDate <16408> ( _                     ' VTable offset = 136
   ) AS DOUBLE                                          ' __retval_out DATE *lastPopulateDate
   ' =====================================================================================
   PROPERTY GET Ttl <16409> ( _                         ' VTable offset = 140
   ) AS LONG                                            ' __retval_out LONG *ttl
   ' =====================================================================================
   PROPERTY GET Language <16410> ( _                    ' VTable offset = 144
   ) AS WSTRING                                         ' __retval_out BSTR *language
   ' =====================================================================================
   PROPERTY GET Copyright <16411> ( _                   ' VTable offset = 148
   ) AS WSTRING                                         ' __retval_out BSTR *copyright
   ' =====================================================================================
   PROPERTY GET MaxItemCount <16422> ( _                ' VTable offset = 152
   ) AS LONG                                            ' __retval_out LONG *count
   ' =====================================================================================
   PROPERTY SET MaxItemCount <16422> ( _                ' VTable offset = 156
     BYVAL count AS LONG _                              ' __in LONG count
   )                                                    ' VOID
   ' =====================================================================================
   PROPERTY GET DownloadEnclosuresAutomatically <16412> ( _ ' VTable offset = 160
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *downloadEnclosuresAutomatically
   ' =====================================================================================
   PROPERTY SET DownloadEnclosuresAutomatically <16412> ( _ ' VTable offset = 164
     BYVAL downloadEnclosuresAutomatically AS INTEGER _ ' __in VARIANT_BOOL downloadEnclosuresAutomatically
   )                                                    ' VOID
   ' =====================================================================================
   PROPERTY GET DownloadStatus <16413> ( _              ' VTable offset = 168
   ) AS LONG                                            ' __retval_out FEEDS_DOWNLOAD_STATUS *status
   ' =====================================================================================
   PROPERTY GET LastDownloadError <16414> ( _           ' VTable offset = 172
   ) AS LONG                                            ' __retval_out FEEDS_DOWNLOAD_ERROR *error
   ' =====================================================================================
   METHOD Merge <16415> ( _                             ' VTable offset = 176
     BYVAL feedXml AS WSTRING _                         ' __in BSTR feedXml
   , BYVAL feedUrl AS WSTRING _                         ' __in BSTR feedUrl
   )                                                    ' VOID
   ' =====================================================================================
   PROPERTY GET DownloadUrl <16416> ( _                 ' VTable offset = 180
   ) AS WSTRING                                         ' __retval_out BSTR *feedUrl
   ' =====================================================================================
   PROPERTY GET IsList <16417> ( _                      ' VTable offset = 184
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *isList
   ' =====================================================================================
   METHOD MarkAllItemsRead <16418> ( _                  ' VTable offset = 188
   )                                                    ' VOID
   ' =====================================================================================
   METHOD GetWatcher <16419> ( _                        ' VTable offset = 192
     BYVAL scope AS LONG _                              ' __in FEEDS_EVENTS_SCOPE scope
   , BYVAL mask AS LONG _                               ' __in FEEDS_EVENTS_MASK mask
   ) AS IDispatch                                       ' __retval_out IDispatch **disp
   ' =====================================================================================
   PROPERTY GET UnreadItemCount <16420> ( _             ' VTable offset = 196
   ) AS LONG                                            ' __retval_out LONG *count
   ' =====================================================================================
   PROPERTY GET ItemCount <16421> ( _                   ' VTable offset = 200
   ) AS LONG                                            ' __retval_out LONG *count
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IFeed_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IFeed2
' IID = {33F2EA09-1398-4AB9-B6A4-F94B49D0A42E}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IFeed
' ########################################################################################

#IF NOT %DEF(%IFeed2_INTERFACE_DEFINED)
    %IFeed2_INTERFACE_DEFINED = 1

INTERFACE IFeed2 $IID_IFeed2

   INHERIT IDispatch

   ' =====================================================================================
   ' IFeed Methods
   ' =====================================================================================
   METHOD Xml <16384> ( _                               ' VTable offset = 28
     BYVAL count AS LONG _                              ' __in LONG count
   , BYVAL sortProperty AS LONG _                       ' __in FEEDS_XML_SORT_PROPERTY sortProperty
   , BYVAL sortOrder AS LONG _                          ' __in FEEDS_XML_SORT_ORDER sortOrder
   , BYVAL filterFlags AS LONG _                        ' __in FEEDS_XML_FILTER_FLAGS filterFlags
   , BYVAL includeFlags AS LONG _                       ' __in FEEDS_XML_INCLUDE_FLAGS includeFlags
   ) AS WSTRING                                         ' __retval_out BSTR *xml
   ' =====================================================================================
   PROPERTY GET Name <16385> ( _                        ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR *name
   ' =====================================================================================
   METHOD Rename <16386> ( _                            ' VTable offset = 36
     BYVAL name AS WSTRING _                            ' __in BSTR name
   )                                                    ' VOID
   ' =====================================================================================
   PROPERTY GET Url <16387> ( _                         ' VTable offset = 40
   ) AS WSTRING                                         ' __retval_out BSTR *feedUrl
   ' =====================================================================================
   PROPERTY SET Url <16387> ( _                         ' VTable offset = 44
     BYVAL feedUrl AS WSTRING _                         ' __in BSTR feedUrl
   )                                                    ' VOID
   ' =====================================================================================
   PROPERTY GET LocalId <16388> ( _                     ' VTable offset = 48
   ) AS WSTRING                                         ' __retval_out BSTR *feedGuid
   ' =====================================================================================
   PROPERTY GET Path <16389> ( _                        ' VTable offset = 52
   ) AS WSTRING                                         ' __retval_out BSTR *path
   ' =====================================================================================
   METHOD Move <16390> ( _                              ' VTable offset = 56
     BYVAL newParentPath AS WSTRING _                   ' __in BSTR newParentPath
   )                                                    ' VOID
   ' =====================================================================================
   PROPERTY GET Parent <16391> ( _                      ' VTable offset = 60
   ) AS IDispatch                                       ' __retval_out IDispatch **disp
   ' =====================================================================================
   PROPERTY GET LastWriteTime <16392> ( _               ' VTable offset = 64
   ) AS DOUBLE                                          ' __retval_out DATE *lastWrite
   ' =====================================================================================
   METHOD Delete <16393> ( _                            ' VTable offset = 68
   )                                                    ' VOID
   ' =====================================================================================
   METHOD Download <16394> ( _                          ' VTable offset = 72
   )                                                    ' VOID
   ' =====================================================================================
   METHOD AsyncDownload <16395> ( _                     ' VTable offset = 76
   )                                                    ' VOID
   ' =====================================================================================
   METHOD CancelAsyncDownload <16396> ( _               ' VTable offset = 80
   )                                                    ' VOID
   ' =====================================================================================
   PROPERTY GET SyncSetting <16398> ( _                 ' VTable offset = 84
   ) AS LONG                                            ' __retval_out FEEDS_SYNC_SETTING *syncSetting
   ' =====================================================================================
   PROPERTY SET SyncSetting <16398> ( _                 ' VTable offset = 88
     BYVAL syncSetting AS LONG _                        ' __in FEEDS_SYNC_SETTING syncSetting
   )                                                    ' VOID
   ' =====================================================================================
   PROPERTY GET Interval <16397> ( _                    ' VTable offset = 92
   ) AS LONG                                            ' __retval_out LONG *minutes
   ' =====================================================================================
   PROPERTY SET Interval <16397> ( _                    ' VTable offset = 96
     BYVAL minutes AS LONG _                            ' __in LONG minutes
   )                                                    ' VOID
   ' =====================================================================================
   PROPERTY GET LastDownloadTime <16399> ( _            ' VTable offset = 100
   ) AS DOUBLE                                          ' __retval_out DATE *lastDownload
   ' =====================================================================================
   PROPERTY GET LocalEnclosurePath <16400> ( _          ' VTable offset = 104
   ) AS WSTRING                                         ' __retval_out BSTR *path
   ' =====================================================================================
   PROPERTY GET Items <16401> ( _                       ' VTable offset = 108
   ) AS IDispatch                                       ' __retval_out IDispatch **disp
   ' =====================================================================================
   METHOD GetItem <16402> ( _                           ' VTable offset = 112
     BYVAL itemId AS LONG _                             ' __in LONG itemId
   ) AS IDispatch                                       ' __retval_out IDispatch **disp
   ' =====================================================================================
   PROPERTY GET Title <16403> ( _                       ' VTable offset = 116
   ) AS WSTRING                                         ' __retval_out BSTR *title
   ' =====================================================================================
   PROPERTY GET Description <16404> ( _                 ' VTable offset = 120
   ) AS WSTRING                                         ' __retval_out BSTR *description
   ' =====================================================================================
   PROPERTY GET Link <16405> ( _                        ' VTable offset = 124
   ) AS WSTRING                                         ' __retval_out BSTR *homePage
   ' =====================================================================================
   PROPERTY GET Image <16406> ( _                       ' VTable offset = 128
   ) AS WSTRING                                         ' __retval_out BSTR *imageUrl
   ' =====================================================================================
   PROPERTY GET LastBuildDate <16407> ( _               ' VTable offset = 132
   ) AS DOUBLE                                          ' __retval_out DATE *lastBuildDate
   ' =====================================================================================
   PROPERTY GET PubDate <16408> ( _                     ' VTable offset = 136
   ) AS DOUBLE                                          ' __retval_out DATE *lastPopulateDate
   ' =====================================================================================
   PROPERTY GET Ttl <16409> ( _                         ' VTable offset = 140
   ) AS LONG                                            ' __retval_out LONG *ttl
   ' =====================================================================================
   PROPERTY GET Language <16410> ( _                    ' VTable offset = 144
   ) AS WSTRING                                         ' __retval_out BSTR *language
   ' =====================================================================================
   PROPERTY GET Copyright <16411> ( _                   ' VTable offset = 148
   ) AS WSTRING                                         ' __retval_out BSTR *copyright
   ' =====================================================================================
   PROPERTY GET MaxItemCount <16422> ( _                ' VTable offset = 152
   ) AS LONG                                            ' __retval_out LONG *count
   ' =====================================================================================
   PROPERTY SET MaxItemCount <16422> ( _                ' VTable offset = 156
     BYVAL count AS LONG _                              ' __in LONG count
   )                                                    ' VOID
   ' =====================================================================================
   PROPERTY GET DownloadEnclosuresAutomatically <16412> ( _ ' VTable offset = 160
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *downloadEnclosuresAutomatically
   ' =====================================================================================
   PROPERTY SET DownloadEnclosuresAutomatically <16412> ( _ ' VTable offset = 164
     BYVAL downloadEnclosuresAutomatically AS INTEGER _ ' __in VARIANT_BOOL downloadEnclosuresAutomatically
   )                                                    ' VOID
   ' =====================================================================================
   PROPERTY GET DownloadStatus <16413> ( _              ' VTable offset = 168
   ) AS LONG                                            ' __retval_out FEEDS_DOWNLOAD_STATUS *status
   ' =====================================================================================
   PROPERTY GET LastDownloadError <16414> ( _           ' VTable offset = 172
   ) AS LONG                                            ' __retval_out FEEDS_DOWNLOAD_ERROR *error
   ' =====================================================================================
   METHOD Merge <16415> ( _                             ' VTable offset = 176
     BYVAL feedXml AS WSTRING _                         ' __in BSTR feedXml
   , BYVAL feedUrl AS WSTRING _                         ' __in BSTR feedUrl
   )                                                    ' VOID
   ' =====================================================================================
   PROPERTY GET DownloadUrl <16416> ( _                 ' VTable offset = 180
   ) AS WSTRING                                         ' __retval_out BSTR *feedUrl
   ' =====================================================================================
   PROPERTY GET IsList <16417> ( _                      ' VTable offset = 184
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *isList
   ' =====================================================================================
   METHOD MarkAllItemsRead <16418> ( _                  ' VTable offset = 188
   )                                                    ' VOID
   ' =====================================================================================
   METHOD GetWatcher <16419> ( _                        ' VTable offset = 192
     BYVAL scope AS LONG _                              ' __in FEEDS_EVENTS_SCOPE scope
   , BYVAL mask AS LONG _                               ' __in FEEDS_EVENTS_MASK mask
   ) AS IDispatch                                       ' __retval_out IDispatch **disp
   ' =====================================================================================
   PROPERTY GET UnreadItemCount <16420> ( _             ' VTable offset = 196
   ) AS LONG                                            ' __retval_out LONG *count
   ' =====================================================================================
   PROPERTY GET ItemCount <16421> ( _                   ' VTable offset = 200
   ) AS LONG                                            ' __retval_out LONG *count
   ' =====================================================================================

   ' =====================================================================================
   ' IFeed2 Methods
   ' =====================================================================================
   METHOD GetItemByEffectiveId <16423> ( _              ' VTable offset = 204
     BYVAL itemEffectiveId AS DWORD _                   ' __in LONG itemEffectiveId
   ) AS IDispatch                                       ' __out_retval IDispatch **disp
   ' =====================================================================================
   PROPERTY GET LastItemDownloadTime <16424> ( _        ' VTable offset = 208
   ) AS DOUBLE                                          ' __out_retval DATE *LastItemDownloadTime
   ' =====================================================================================
   PROPERTY GET Username <16425> ( _                    ' VTable offset = 212
   ) AS WSTRING                                         ' __out_retval BSTR *Username
   ' =====================================================================================
   PROPERTY GET Password <16426> ( _                    ' VTable offset = 216
   ) AS WSTRING                                         ' __out_retval BSTR *Password
   ' =====================================================================================
   METHOD SetCredentials <16427> ( _                    ' VTable offset = 220
     BYVAL Username AS WSTRING _                        ' __in BSTR Username
   , BYVAL Password AS WSTRING _                        ' __in BSTR Password
   )                                                    ' void
   ' =====================================================================================
   METHOD ClearCredentials <16428> ( _                  ' VTable offset = 224
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IFeed2_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IFeedEvents
' IID = ABF35C99-0681-47EA-9A8C-1436A375A99E
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IFeedEvents_INTERFACE_DEFINED)
    %IFeedEvents_INTERFACE_DEFINED = 1

INTERFACE IFeedEvents $IID_IFeedEvents

   INHERIT IDispatch

   ' =====================================================================================
   METHOD Error <32768> ( _                             ' VTable offset = 12
   )                                                    ' void
   ' =====================================================================================
   METHOD FeedDeleted <32769> ( _                       ' VTable offset = 16
     BYVAL path AS WSTRING _                            ' __in const BSTR path
   )                                                    ' void
   ' =====================================================================================
   METHOD FeedRenamed <32770> ( _                       ' VTable offset = 20
     BYVAL path AS WSTRING _                            ' __in const BSTR path
   , BYVAL oldPath AS WSTRING _                         ' __in const BSTR oldPath
   )                                                    ' void
   ' =====================================================================================
   METHOD FeedUrlChanged <32771> ( _                    ' VTable offset = 24
     BYVAL path AS WSTRING _                            ' __in const BSTR path
   )                                                    ' void
   ' =====================================================================================
   METHOD FeedMoved <32772> ( _                         ' VTable offset = 28
     BYVAL path AS WSTRING _                            ' __in const BSTR path
   , BYVAL oldPath AS WSTRING _                         ' __in const BSTR oldPath
   )                                                    ' void
   ' =====================================================================================
   METHOD FeedDownloading <32773> ( _                   ' VTable offset = 32
     BYVAL path AS WSTRING _                                    ' __in const BSTR path
   )                                                    ' void
   ' =====================================================================================
   METHOD FeedDownloadCompleted <32774> ( _             ' VTable offset = 36
     BYVAL path AS WSTRING _                            ' __in const BSTR path
   , BYVAL fde AS LONG _                                ' __in FEEDS_DOWNLOAD_ERROR fde
   )                                                    ' void
   ' =====================================================================================
   ' Note: Wrongly flagged as DISPID_FEEDFOLDEREVENTS_FeedItemCountChanged (28687)
   ' in the .idl file
   ' =====================================================================================
   METHOD FeedItemCountChanged <32775> ( _              ' VTable offset = 40
     BYVAL path AS WSTRING _                            ' __in const BSTR path
   , BYVAL feicfFlags AS LONG _                         ' __in FEICF feicfFlags
   )                                                    ' void
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IFeedEvents_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IFeedItem
' IID = {0A1E6CAD-0A47-4DA2-A13D-5BAAA5C8BD4F}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IFeedItem_INTERFACE_DEFINED)
    %IFeedItem_INTERFACE_DEFINED = 1

INTERFACE IFeedItem $IID_IFeedItem

   INHERIT IDispatch

   ' =====================================================================================
   METHOD Xml <20480> ( _                               ' VTable offset = 28
     BYVAL includeFlags AS LONG _                       ' __in FEEDS_XML_INCLUDE_FLAGS includeFlags
   ) AS WSTRING                                         ' __retval_out BSTR *xml
   ' =====================================================================================
   PROPERTY GET Title <20481> ( _                       ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR *title
   ' =====================================================================================
   PROPERTY GET Link <20482> ( _                        ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *linkUrl
   ' =====================================================================================
   PROPERTY GET Guid <20483> ( _                        ' VTable offset = 40
   ) AS WSTRING                                         ' __retval_out BSTR *itemGuid
   ' =====================================================================================
   PROPERTY GET Description <20484> ( _                 ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *description
   ' =====================================================================================
   PROPERTY GET PubDate <20485> ( _                     ' VTable offset = 48
   ) AS DOUBLE                                          ' __retval_out DATE *pubDate
   ' =====================================================================================
   PROPERTY GET Comments <20486> ( _                    ' VTable offset = 52
   ) AS WSTRING                                         ' __retval_out BSTR *comments
   ' =====================================================================================
   PROPERTY GET Author <20487> ( _                      ' VTable offset = 56
   ) AS WSTRING                                         ' __retval_out BSTR *author
   ' =====================================================================================
   PROPERTY GET Enclosure <20488> ( _                   ' VTable offset = 60
   ) AS IDispatch                                       ' __retval_out IDispatch **disp
   ' =====================================================================================
   PROPERTY GET IsRead <20489> ( _                      ' VTable offset = 64
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *isRead
   ' =====================================================================================
   PROPERTY SET IsRead <20489> ( _                      ' VTable offset = 68
     BYVAL isRead AS INTEGER _                          ' __in VARIANT_BOOL isRead
   )                                                    ' VOID
   ' =====================================================================================
   PROPERTY GET LocalId <20490> ( _                     ' VTable offset = 72
   ) AS LONG                                            ' __retval_out LONG *itemId
   ' =====================================================================================
   PROPERTY GET Parent <20491> ( _                      ' VTable offset = 76
   ) AS IDispatch                                       ' __retval_out IDispatch **disp
   ' =====================================================================================
   METHOD Delete <20492> ( _                            ' VTable offset = 80
   )                                                    ' VOID
   ' =====================================================================================
   PROPERTY GET DownloadUrl <20493> ( _                 ' VTable offset = 84
   ) AS WSTRING                                         ' __retval_out BSTR *itemUrl
   ' =====================================================================================
   PROPERTY GET LastDownloadTime <20494> ( _            ' VTable offset = 88
   ) AS DOUBLE                                          ' __retval_out DATE *lastDownload
   ' =====================================================================================
   PROPERTY GET Modified <20495> ( _                    ' VTable offset = 92
   ) AS DOUBLE                                          ' __retval_out DATE *modified
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IFeedItem_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IFeedItem2
' IID = {79AC9EF4-F9C1-4D2B-A50B-A7FFBA4DCF37}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IFeedItem
' ########################################################################################

#IF NOT %DEF(%IFeedItem2_INTERFACE_DEFINED)
    %IFeedItem2_INTERFACE_DEFINED = 1

INTERFACE IFeedItem2 $IID_IFeedItem2

   INHERIT IDispatch

   ' =====================================================================================
   ' IFeedItem Methods
   ' =====================================================================================
   METHOD Xml <20480> ( _                               ' VTable offset = 28
     BYVAL includeFlags AS LONG _                       ' __in FEEDS_XML_INCLUDE_FLAGS includeFlags
   ) AS WSTRING                                         ' __retval_out BSTR *xml
   ' =====================================================================================
   PROPERTY GET Title <20481> ( _                       ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR *title
   ' =====================================================================================
   PROPERTY GET Link <20482> ( _                        ' VTable offset = 36
   ) AS WSTRING                                         ' __retval_out BSTR *linkUrl
   ' =====================================================================================
   PROPERTY GET Guid <20483> ( _                        ' VTable offset = 40
   ) AS WSTRING                                         ' __retval_out BSTR *itemGuid
   ' =====================================================================================
   PROPERTY GET Description <20484> ( _                 ' VTable offset = 44
   ) AS WSTRING                                         ' __retval_out BSTR *description
   ' =====================================================================================
   PROPERTY GET PubDate <20485> ( _                     ' VTable offset = 48
   ) AS DOUBLE                                          ' __retval_out DATE *pubDate
   ' =====================================================================================
   PROPERTY GET Comments <20486> ( _                    ' VTable offset = 52
   ) AS WSTRING                                         ' __retval_out BSTR *comments
   ' =====================================================================================
   PROPERTY GET Author <20487> ( _                      ' VTable offset = 56
   ) AS WSTRING                                         ' __retval_out BSTR *author
   ' =====================================================================================
   PROPERTY GET Enclosure <20488> ( _                   ' VTable offset = 60
   ) AS IDispatch                                       ' __retval_out IDispatch **disp
   ' =====================================================================================
   PROPERTY GET IsRead <20489> ( _                      ' VTable offset = 64
   ) AS INTEGER                                         ' __retval_out VARIANT_BOOL *isRead
   ' =====================================================================================
   PROPERTY SET IsRead <20489> ( _                      ' VTable offset = 68
     BYVAL isRead AS INTEGER _                          ' __in VARIANT_BOOL isRead
   )                                                    ' VOID
   ' =====================================================================================
   PROPERTY GET LocalId <20490> ( _                     ' VTable offset = 72
   ) AS LONG                                            ' __retval_out LONG *itemId
   ' =====================================================================================
   PROPERTY GET Parent <20491> ( _                      ' VTable offset = 76
   ) AS IDispatch                                       ' __retval_out IDispatch **disp
   ' =====================================================================================
   METHOD Delete <20492> ( _                            ' VTable offset = 80
   )                                                    ' VOID
   ' =====================================================================================
   PROPERTY GET DownloadUrl <20493> ( _                 ' VTable offset = 84
   ) AS WSTRING                                         ' __retval_out BSTR *itemUrl
   ' =====================================================================================
   PROPERTY GET LastDownloadTime <20494> ( _            ' VTable offset = 88
   ) AS DOUBLE                                          ' __retval_out DATE *lastDownload
   ' =====================================================================================
   PROPERTY GET Modified <20495> ( _                    ' VTable offset = 92
   ) AS DOUBLE                                          ' __retval_out DATE *modified
   ' =====================================================================================

   ' =====================================================================================
   ' IFeedItem2 Methods
   ' =====================================================================================
   PROPERTY GET EffectiveId <20496> ( _                 ' VTable offset = 96
   ) AS LONG                                            ' __out_retval LONG *EffectiveId
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IFeedItem2_INTERFACE_DEFINED__ */

' ########################################################################################
' Interface name = IFeedEnclosure
' IID = {361C26F7-90A4-4E67-AE09-3A36A546436A}
' Attributes = 4160 [&H1040] [Dual] [Dispatchable]
' Inherited interface = IDispatch
' ########################################################################################

#IF NOT %DEF(%IFeedEnclosure_INTERFACE_DEFINED)
    %IFeedEnclosure_INTERFACE_DEFINED = 1

INTERFACE IFeedEnclosure $IID_IFeedEnclosure

   INHERIT IDispatch

   ' =====================================================================================
   PROPERTY GET Url <24576> ( _                         ' VTable offset = 28
   ) AS WSTRING                                         ' __retval_out BSTR *enclosureUrl
   ' =====================================================================================
   PROPERTY GET Type <24577> ( _                        ' VTable offset = 32
   ) AS WSTRING                                         ' __retval_out BSTR *mimeType
   ' =====================================================================================
   PROPERTY GET Length <24578> ( _                      ' VTable offset = 36
   ) AS LONG                                            ' __retval_out LONG *length
   ' =====================================================================================
   METHOD AsyncDownload <24579> ( _                     ' VTable offset = 40
   )                                                    ' VOID
   ' =====================================================================================
   METHOD CancelAsyncDownload <24580> ( _               ' VTable offset = 44
   )                                                    ' VOID
   ' =====================================================================================
   PROPERTY GET DownloadStatus <24581> ( _              ' VTable offset = 48
   ) AS LONG                                            ' __retval_out FEEDS_DOWNLOAD_STATUS *status
   ' =====================================================================================
   PROPERTY GET LastDownloadError <24582> ( _           ' VTable offset = 52
   ) AS LONG                                            ' __retval_out FEEDS_DOWNLOAD_ERROR *error
   ' =====================================================================================
   PROPERTY GET LocalPath <24583> ( _                   ' VTable offset = 56
   ) AS WSTRING                                         ' __retval_out BSTR *localPath
   ' =====================================================================================
   PROPERTY GET Parent <24584> ( _                      ' VTable offset = 60
   ) AS IDispatch                                       ' __retval_out IDispatch **disp
   ' =====================================================================================
   PROPERTY GET DownloadUrl <24585> ( _                 ' VTable offset = 64
   ) AS WSTRING                                         ' __retval_out BSTR *enclosureUrl
   ' =====================================================================================
   PROPERTY GET DownloadMimeType <24586> ( _            ' VTable offset = 68
   ) AS WSTRING                                         ' __retval_out BSTR *mimeType
   ' =====================================================================================
   METHOD RemoveFile <24587> ( _                        ' VTable offset = 72
   )                                                    ' VOID
   ' =====================================================================================
   METHOD SetFile <24588> ( _                           ' VTable offset = 76
     BYVAL downloadUrl AS WSTRING _                     ' __in BSTR downloadUrl
   , BYVAL downloadFilePath AS WSTRING _                ' __in BSTR downloadFilePath
   , BYVAL downloadMimeType AS WSTRING _                ' __in BSTR downloadMimeType
   , BYVAL enclosureFilename AS WSTRING _               ' __in BSTR enclosureFilename
   )                                                    ' VOID
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IFeedEnclosure_INTERFACE_DEFINED__ */
