' ########################################################################################
' Microsoft Windows
' File: shappmgr.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%SHAPPMGR_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "oaidl.inc"
#INCLUDE ONCE "ocidl.inc"
#INCLUDE ONCE "appmgmt.inc"

' APPINFODATAFLAGS enum
%AIM_DISPLAYNAME        = &H1???
%AIM_VERSION            = &H2???
%AIM_PUBLISHER          = &H4???
%AIM_PRODUCTID          = &H8???
%AIM_REGISTEREDOWNER    = &H10???
%AIM_REGISTEREDCOMPANY  = &H20???
%AIM_LANGUAGE           = &H40???
%AIM_SUPPORTURL         = &H80???
%AIM_SUPPORTTELEPHONE   = &H100???
%AIM_HELPLINK           = &H200???
%AIM_INSTALLLOCATION    = &H400???
%AIM_INSTALLSOURCE      = &H800???
%AIM_INSTALLDATE        = &H1000???
%AIM_REQUIREDBYPOLICY   = &H2000???
%AIM_CONTACT            = &H4000???
%AIM_COMMENTS           = &H8000???
%AIM_IMAGE              = &H20000???
%AIM_READMEURL          = &H40000???
%AIM_UPDATEINFOURL      = &H80000???

' // Size = 80 bytes
TYPE APPINFODATA DWORD
   cbSize               AS DWORD          ' DWORD
   dwMask               AS DWORD          ' DWORD
   pszDisplayName       AS WSTRINGZ PTR   ' LPWSTR
   pszVersion           AS WSTRINGZ PTR   ' LPWSTR
   pszPublisher         AS WSTRINGZ PTR   ' LPWSTR
   pszProductID         AS WSTRINGZ PTR   ' LPWSTR
   pszRegisteredOwner   AS WSTRINGZ PTR   ' LPWSTR
   pszRegisteredCompany AS WSTRINGZ PTR   ' LPWSTR
   pszLanguage          AS WSTRINGZ PTR   ' LPWSTR
   pszSupportUrl        AS WSTRINGZ PTR   ' LPWSTR
   pszSupportTelephone  AS WSTRINGZ PTR   ' LPWSTR
   pszHelpLink          AS WSTRINGZ PTR   ' LPWSTR
   pszInstallLocation   AS WSTRINGZ PTR   ' LPWSTR
   pszInstallSource     AS WSTRINGZ PTR   ' LPWSTR
   pszInstallDate       AS WSTRINGZ PTR   ' LPWSTR
   pszContact           AS WSTRINGZ PTR   ' LPWSTR
   pszComments          AS WSTRINGZ PTR   ' LPWSTR
   pszImage             AS WSTRINGZ PTR   ' LPWSTR
   pszReadmeUrl         AS WSTRINGZ PTR   ' LPWSTR
   pszUpdateInfoUrl     AS WSTRINGZ PTR   ' LPWSTR
END TYPE

' APPACTIONFLAGS enum
%APPACTION_INSTALL      = &H1???
%APPACTION_UNINSTALL    = &H2???
%APPACTION_MODIFY       = &H4???
%APPACTION_REPAIR       = &H8???
%APPACTION_UPGRADE      = &H10???
%APPACTION_CANGETSIZE   = &H20???
%APPACTION_MODIFYREMOVE = &H80???
%APPACTION_ADDLATER     = &H100???
%APPACTION_UNSCHEDULE   = &H200???

' // Size = 24 bytes
TYPE SLOWAPPINFO   ' Must be 8 byte aligned
   ullsize    AS QUAD           ' ULONGLONG
   ftLastUsed AS FILETIME       ' FILETIME
   iTimesUsed AS LONG           ' int
   pszImage   AS WSTRINGZ PTR   ' LPWSTR
END TYPE


' ########################################################################################
' IShellApp interface
' IID = A3E14960-935F-11D1-B8B8-006008059382
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IShellApp_INTERFACE_DEFINED)

$IID_IShellApp = GUID$("{A3E14960-935F-11D1-B8B8-006008059382}")

INTERFACE IShellApp $IID_IShellApp

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetAppInfo ( _                                ' VTable offset = 12
      BYREF pai AS APPINFODATA _                        ' __in_out PAPPINFODATA pai
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPossibleActions ( _                        ' VTable offset = 16
     BYREF pdwActions AS DWORD _                        ' __out DWORD *pdwActions
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSlowAppInfo ( _                            ' VTable offset = 20
     BYREF psaid AS SLOWAPPINFO _                       ' __in PSLOWAPPINFO psaid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCachedSlowAppInfo ( _                      ' VTable offset = 24
     BYREF psaid AS SLOWAPPINFO _                       ' __in PSLOWAPPINFO psaid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsInstalled ( _                               ' VTable offset = 28
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IShellApp_INTERFACE_DEFINED__ */


' ########################################################################################
' IPublishedApp interface
' IID = 1BC752E0-9046-11D1-B8B3-006008059382
' Inherited interface = IShellApp
' Minimum operating systems: Windows 98, Windows 2000, Windows XP
' ########################################################################################

#IF NOT %DEF(%IPublishedApp_INTERFACE_DEFINED)

$IID_IPublishedApp = GUID$("{1BC752E0-9046-11D1-B8B3-006008059382}")

' PUBAPPINFOFLAGS enum
%PAI_SOURCE        = &H1???
%PAI_ASSIGNEDTIME  = &H2???
%PAI_PUBLISHEDTIME = &H4???
%PAI_SCHEDULEDTIME = &H8???
%PAI_EXPIRETIME    = &H10???

' // Size = 76 bytes
TYPE PUBAPPINFO DWORD
   cbSize      AS DWORD          ' DWORD
   dwMask      AS DWORD          ' DWORD
   pszSource   AS WSTRINGZ PTR   ' LPWSTR
   stAssigned  AS SYSTEMTIME     ' SYSTEMTIME
   stPublished AS SYSTEMTIME     ' SYSTEMTIME
   stScheduled AS SYSTEMTIME     ' SYSTEMTIME
   stExpire    AS SYSTEMTIME     ' SYSTEMTIME
END TYPE

INTERFACE IPublishedApp $IID_IPublishedApp

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetAppInfo ( _                                ' VTable offset = 12
     BYREF pai AS APPINFODATA _                         ' __in_out PAPPINFODATA pai
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPossibleActions ( _                        ' VTable offset = 16
     BYREF pdwActions AS DWORD _                        ' __out DWORD *pdwActions
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSlowAppInfo ( _                            ' VTable offset = 20
     BYREF psaid AS SLOWAPPINFO _                       ' __in PSLOWAPPINFO psaid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCachedSlowAppInfo ( _                      ' VTable offset = 24
     BYREF psaid AS SLOWAPPINFO _                       ' __in PSLOWAPPINFO psaid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsInstalled ( _                               ' VTable offset = 28
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Install ( _                                   ' VTable offset = 12
     BYREF pstInstall AS SYSTEMTIME _                   ' __in LPSYSTEMTIME pstInstall
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPublishedAppInfo ( _                       ' VTable offset = 16
     BYREF ppai AS PUBAPPINFO  _                        ' __in_out PPUBAPPINFO ppai
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Unschedule ( _                                ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IPublishedApp_INTERFACE_DEFINED__ */


' ########################################################################################
' IPublishedApp2 interface
' IID = 12B81347-1B3A-4A04-AA61-3F768B67FD7E
' Inherited interface = IPublishedApp
' ########################################################################################

#IF NOT %DEF(%IPublishedApp2_INTERFACE_DEFINED)

$IID_IPublishedApp2 = GUID$("{12B81347-1B3A-4A04-AA61-3F768B67FD7E}")

INTERFACE IPublishedApp2 $IID_IPublishedApp2

   INHERIT IUnknown

   ' =====================================================================================
   ' IPublishedApp Methods
   ' =====================================================================================
   METHOD GetAppInfo ( _                                ' VTable offset = 12
     BYREF pai AS APPINFODATA _                         ' __in_out PAPPINFODATA pai
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPossibleActions ( _                        ' VTable offset = 16
     BYREF pdwActions AS DWORD _                        ' __out DWORD *pdwActions
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSlowAppInfo ( _                            ' VTable offset = 20
     BYREF psaid AS SLOWAPPINFO _                       ' __in PSLOWAPPINFO psaid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCachedSlowAppInfo ( _                      ' VTable offset = 24
     BYREF psaid AS SLOWAPPINFO _                       ' __in PSLOWAPPINFO psaid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsInstalled ( _                               ' VTable offset = 28
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Install ( _                                   ' VTable offset = 12
     BYREF pstInstall AS SYSTEMTIME _                   ' __in LPSYSTEMTIME pstInstall
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPublishedAppInfo ( _                       ' VTable offset = 16
     BYREF ppai AS PUBAPPINFO  _                        ' __in_out PPUBAPPINFO ppai
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Unschedule ( _                                ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IPublishedApp2 Methods
   ' =====================================================================================
   METHOD Install2 ( _                                  ' VTable offset = 24
     BYREF pstInstall AS SYSTEMTIME _                   ' __in LPSYSTEMTIME pstInstall
   , BYVAL hwndParent AS DWORD _                        ' __in HWND hwndParent
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IPublishedApp2_INTERFACE_DEFINED__ */


' ########################################################################################
' IEnumPublishedApps interface
' IID = 0B124F8C-91F0-11D1-B8B5-006008059382
' Inherited interface = IUnknown
' Minimum operating systems: Windows 98, Windows 2000, Windows XP
' ########################################################################################

#IF NOT %DEF(%IEnumPublishedApps_INTERFACE_DEFINED)

$IID_IEnumPublishedApps = GUID$("{0B124F8C-91F0-11D1-B8B5-006008059382}")

INTERFACE IEnumPublishedApps $IID_IEnumPublishedApps

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Next ( _                                      ' VTable offset = 12
     BYREF pia AS IPublishedApp _                       ' __out IPublishedApp **pia
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reset ( _                                     ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEnumPublishedApps_INTERFACE_DEFINED__ */


' ########################################################################################
' IAppPublisher interface
' IID = 07250A10-9CF9-11D1-9076-006008059382
' Inherited interface = IUnknown
' Minimum operating systems: Windows 98, Windows 2000, Windows XP
' ########################################################################################

#IF NOT %DEF(%IAppPublisher_INTERFACE_DEFINED)

$IID_IAppPublisher = GUID$("{07250A10-9CF9-11D1-9076-006008059382}")

INTERFACE IAppPublisher $IID_IAppPublisher

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetNumberOfCategories ( _                     ' VTable offset = 12
     BYREF pdwCat AS DWORD _                            ' __out DWORD *pdwCat
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCategories ( _                             ' VTable offset = 16
     BYREF pAppCategoryList AS APPCATEGORYINFOLIST _    ' __out APPCATEGORYINFOLIST *pAppCategoryList
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetNumberOfApps ( _                           ' VTable offset = 20
     BYREF pdwApps AS DWORD _                           ' __out DWORD *pdwApps
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumApps ( _                                  ' VTable offset = 24
     BYREF pAppCategoryId AS GUID _                     ' __in GUID *pAppCategoryId
   , BYREF ppepa AS IEnumPublishedApps _                ' __out IEnumPublishedApps **ppepa
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAppPublisher_INTERFACE_DEFINED__ */
