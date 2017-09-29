' ########################################################################################
' Microsoft Windows
' File: HLink.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%HLINK_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "urlmon.inc"

'//--------------------------------------------------------------------------
'// OLE Hyperlinking Interfaces.

'/****************************************************************************/
'/**** Error codes                                                        ****/
'/****************************************************************************/
#IF NOT %DEF(%HLINK_ERRORS_DEFINED)
%HLINK_ERRORS_DEFINED = 1
%HLINK_E_FIRST                    = %OLE_E_LAST + 1
%HLINK_S_FIRST                    = %OLE_S_LAST + 1
%HLINK_S_DONTHIDE                 = %HLINK_S_FIRST
#ENDIF   ' //_HLINK_ERRORS_DEFINED


'/****************************************************************************/
'/**** Hyperlink APIs                                                     ****/
'/****************************************************************************/

$CFSTR_HYPERLINK = "Hyperlink"

DECLARE FUNCTION HlinkCreateFromMoniker IMPORT "HLINK.DLL" ALIAS "HlinkCreateFromMoniker" ( _
   BYVAL pimkTrgt AS IMoniker _                         ' __in  IMoniker * pimkTrgt
 , BYREF pwzLocation AS WSTRINGZ _                      ' __in  LPCWSTR pwzLocation
 , BYREF pwzFriendlyName AS WSTRINGZ _                  ' __in  LPCWSTR pwzFriendlyName
 , BYVAL pihlsite AS IHlinkSite _                       ' __in  IHlinkSite * pihlsite
 , BYVAL dwSiteData AS DWORD _                          ' __in  DWORD dwSiteData
 , BYVAL piunkOuter AS IUnknown _                       ' __in  IUnknown * piunkOuter
 , BYREF riid AS GUID _                                 ' __in  REFIID riid
 , BYREF ppvObj AS ANY _                                ' __out void ** ppvObj
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION HlinkCreateFromString IMPORT "HLINK.DLL" ALIAS "HlinkCreateFromString" ( _
   BYREF pwzTarget AS WSTRINGZ _                        ' __in  LPCWSTR pwzTarget
 , BYREF pwzLocation AS WSTRINGZ _                      ' __in  LPCWSTR pwzLocation
 , BYREF pwzFriendlyName AS WSTRINGZ _                  ' __in  LPCWSTR pwzFriendlyName
 , BYVAL pihlsite AS IHlinkSite _                       ' __in  IHlinkSite * pihlsite
 , BYVAL dwSiteData AS DWORD _                          ' __in  DWORD dwSiteData
 , BYVAL piunkOuter AS IUnknown _                       ' __in  IUnknown * piunkOuter
 , BYREF riid AS GUID _                                 ' __in  REFIID riid
 , BYREF ppvObj AS ANY _                                ' __out void ** ppvObj
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION HlinkCreateFromData IMPORT "HLINK.DLL" ALIAS "HlinkCreateFromData" ( _
   BYVAL piDataObj AS IDataObject _                     ' __in  IDataObject *piDataObj
 , BYVAL pihlsite AS IHlinkSite _                       ' __in  IHlinkSite * pihlsite
 , BYVAL dwSiteData AS DWORD _                          ' __in  DWORD dwSiteData
 , BYVAL piunkOuter AS IUnknown _                       ' __in  IUnknown * piunkOuter
 , BYREF riid AS GUID _                                 ' __in  REFIID riid
 , BYREF ppvObj AS ANY _                                ' __out void ** ppvObj
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION HlinkQueryCreateFromData IMPORT "HLINK.DLL" ALIAS "HlinkQueryCreateFromData" ( _
   BYVAL piDataObj AS IDataObject _                     ' __in  IDataObject *piDataObj
 ) AS LONG                                              ' HRESULT

' Not currently supported
'DECLARE FUNCTION HlinkClone IMPORT "HLINK.DLL" ALIAS "HlinkClone" ( _
'   BYVAL pihl AS IHlink _                               ' __in  IHlink * pihl
' , BYREF riid AS GUID _                                 ' __in  REFIID riid
' , BYVAL pihlsiteForClone AS IHlinkSite _               ' __in  IHlinkSite * pihlsiteForClone
' , BYVAL dwSiteData AS DWORD _                          ' __in  DWORD dwSiteData
' , BYREF ppvObj AS ANY _                                ' __out void ** ppvObj
' ) AS LONG                                              ' HRESULT

DECLARE FUNCTION HlinkCreateBrowseContext IMPORT "HLINK.DLL" ALIAS "HlinkCreateBrowseContext" ( _
   BYVAL piunkOuter AS IUnknown _                       ' __in  IUnknown * piunkOuter
 , BYREF riid AS GUID _                                 ' __in  REFIID riid
 , BYREF ppvObj AS ANY _                                ' __out void ** ppvObj
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION HlinkNavigateToStringReference IMPORT "HLINK.DLL" ALIAS "HlinkNavigateToStringReference" ( _
   BYREF pwzTarget AS WSTRINGZ _                        ' __in  LPCWSTR pwzTarget
 , BYREF pwzLocation AS WSTRINGZ _                      ' __in  LPCWSTR pwzLocation
 , BYVAL pihlsite AS IHlinkSite _                       ' __in  IHlinkSite * pihlsite
 , BYVAL dwSiteData AS DWORD _                          ' __in  DWORD dwSiteData
 , BYVAL pihlframe AS IHlinkFrame _                     ' __in  IHlinkFrame *pihlframe
 , BYVAL grfHLNF AS DWORD _                             ' __in  DWORD grfHLNF
 , BYVAL pibc AS IBindCtx _                             ' __in  LPBC pibc
 , BYVAL pibsc AS IBindStatusCallback _                 ' __in  IBindStatusCallback * pibsc
 , BYVAL pihlbc AS IHlinkBrowseContext _                ' __in  IHlinkBrowseContext *pihlbc
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION HlinkNavigate IMPORT "HLINK.DLL" ALIAS "HlinkNavigate" ( _
   BYVAL pihl AS IHlink _                               ' __in  IHlink * pihl
 , BYVAL pihlframe AS IHlinkFrame _                     ' __in  IHlinkFrame * pihlframe
 , BYVAL grfHLNF AS DWORD _                             ' __in  DWORD grfHLNF
 , BYVAL pbc AS IBindCtx _                              ' __in  LPBC pbc
 , BYVAL pibsc AS IBindStatusCallback _                 ' __in  IBindStatusCallback * pibsc
 , BYVAL pihlbc AS IHlinkBrowseContext _                ' __in  IHlinkBrowseContext *pihlbc
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION HlinkOnNavigate IMPORT "HLINK.DLL" ALIAS "HlinkOnNavigate" ( _
   BYVAL pihlframe AS IHlinkFrame _                     ' __in  IHlinkFrame * pihlframe
 , BYVAL pihlbc AS IHlinkBrowseContext _                ' __in  IHlinkBrowseContext * pihlbc
 , BYVAL grfHLNF AS DWORD _                             ' __in  DWORD grfHLNF
 , BYVAL pimkTarget AS IMoniker _                       ' __in  IMoniker * pimkTarget
 , BYREF pwzLocation AS WSTRINGZ _                      ' __in  LPCWSTR pwzLocation
 , BYREF pwzFriendlyName AS WSTRINGZ _                  ' __in  LPCWSTR pwzFriendlyName
 , BYREF puHLID AS DWORD _                              ' __out ULONG * puHLID
 ) AS LONG                                              ' HRESULT

' Not currently supported
'DECLARE FUNCTION HlinkUpdateStackItem IMPORT "HLINK.DLL" ALIAS "HlinkUpdateStackItem" ( _
'   BYVAL pihlframe AS IHlinkFrame _                     ' __in  IHlinkFrame * pihlframe
' , BYVAL pihlbc AS IHlinkBrowseContext _                ' __in  IHlinkBrowseContext * pihlbc
' , BYVAL uHLID AS DWORD _                               ' __in  ULONG uHLID
' , BYVAL pimkTrgt AS IMoniker _                         ' __in  IMoniker * pimkTrgt
' , BYREF pwzLocation AS WSTRINGZ _                      ' __in  LPCWSTR pwzLocation
' , BYREF pwzFriendlyName AS WSTRINGZ _                  ' __in  LPCWSTR pwzFriendlyName
' ) AS LONG                                              ' HRESULT

' Not currently supported
'DECLARE FUNCTION HlinkOnRenameDocument IMPORT "HLINK.DLL" ALIAS "HlinkOnRenameDocument" ( _
'   BYVAL dwReserved AS DWORD _                          ' __in  DWORD dwReserved
' , BYVAL pihlbc AS IHlinkBrowseContext _                ' __in  IHlinkBrowseContext * pihlbc
' , BYVAL pimkOld AS IMoniker _                          ' __in  IMoniker * pimkOld
' , BYVAL pimkNew AS IMoniker _                          ' __in  IMoniker * pimkNew
' ) AS LONG                                              ' HRESULT

' Not currently supported
'DECLARE FUNCTION HlinkResolveMonikerForData IMPORT "HLINK.DLL" ALIAS "HlinkResolveMonikerForData" ( _
'   BYVAL pimkReference AS IMoniker _                    ' __in  LPMONIKER pimkReference
' , BYVAL reserved AS DWORD _                            ' __in  DWORD reserved
' , BYVAL pibc AS IBindCtx _                             ' __in  LPBC pibc
' , BYVAL cFmtetc AS DWORD _                             ' __in  ULONG cFmtetc
' , BYREF rgFmtetc AS FORMATETC _                        ' __in  FORMATETC * rgFmtetc
' , BYVAL pibsc AS IBindStatusCallback _                 ' __in  IBindStatusCallback * pibsc
' , BYVAL pimkBase AS IMoniker _                         ' __in  LPMONIKER pimkBase
' ) AS LONG                                              ' HRESULT

' Not currently supported
'DECLARE FUNCTION HlinkResolveStringForData IMPORT "HLINK.DLL" ALIAS "HlinkResolveStringForData" ( _
'   BYREF pwzReference AS WSTRINGZ _                     ' __in  LPCWSTR pwzReference
' , BYVAL reserved AS DWORD _                            ' __in  DWORD reserved
' , BYVAL pibc AS IBindCtx _                             ' __in  LPBC pibc
' , BYVAL cFmtetc AS DWORD _                             ' __in  ULONG cFmtetc
' , BYREF rgFmtetc AS FORMATETC _                        ' __in  FORMATETC * rgFmtetc
' , BYVAL pibsc AS IBindStatusCallback _                 ' __in  IBindStatusCallback * pibsc
' , BYVAL pimkBase AS IMoniker _                         ' __in  LPMONIKER pimkBase
' ) AS LONG                                              ' HRESULT

' Not currently supported
'DECLARE FUNCTION HlinkParseDisplayName IMPORT "HLINK.DLL" ALIAS "HlinkParseDisplayName" ( _
'   BYVAL pibc AS IBindCtx _                             ' __in  LPBC pibc
' , BYREF pwzDisplayName AS WSTRINGZ _                   ' __in  LPCWSTR pwzDisplayName
' , BYVAL fNoForceAbs AS LONG _                          ' __in  BOOL fNoForceAbs
' , BYREF pcchEaten AS DWORD _                           ' __out ULONG * pcchEaten
' , BYREF ppimk AS IMoniker _                            ' __out IMoniker ** ppimk
' ) AS LONG                                              ' HRESULT

' Not currently supported
'DECLARE FUNCTION HlinkCreateExtensionServices IMPORT "HLINK.DLL" ALIAS "HlinkCreateExtensionServices" ( _
'   BYREF pwzAdditionalHeaders AS WSTRINGZ _             ' __in  LPCWSTR pwzAdditionalHeaders
' , BYVAL phwnd AS DWORD _                               ' __in  HWND phwnd
' , BYREF pszUsername AS WSTRINGZ _                      ' __in  LPCWSTR pszUsername
' , BYREF pszPassword AS WSTRINGZ _                      ' __in  LPCWSTR pszPassword
' , BYVAL piunkOuter AS IUnknown _                       ' __in  IUnknown * piunkOuter
' , BYREF riid AS GUID _                                 ' __out REFIID riid
' , BYREF ppvObj AS ANY _                                ' __out void ** ppvObj
' ) AS LONG                                              ' HRESULT

' Not currently supported
'DECLARE FUNCTION HlinkPreprocessMoniker IMPORT "HLINK.DLL" ALIAS "HlinkPreprocessMoniker" ( _
'   BYVAL pibc AS IBindCtx _                             ' __in  LPBC pibc
' , BYVAL pimkIn AS IMoniker _                           ' __in  IMoniker *pimkIn
' , BYREF ppimkOut AS IMoniker _                         ' __out IMoniker **ppimkOut
' ) AS LONG                                              ' HRESULT

' Not currently supported
'DECLARE FUNCTION OleSaveToStreamEx IMPORT "HLINK.DLL" ALIAS "OleSaveToStreamEx" ( _
'   BYVAL piunk AS IUnknown _                            ' __in  IUnknown * piunk
' , BYVAL pistm AS IStream _                             ' __in  IStream * pistm
' , BYVAL fClearDirty AS LONG _                          ' __in  BOOL fClearDirty
' ) AS LONG                                              ' HRESULT

' HLSR enum
%HLSR_HOME          = 0
%HLSR_SEARCHPAGE    = 1
%HLSR_HISTORYFOLDER = 2

DECLARE FUNCTION HlinkSetSpecialReference IMPORT "HLINK.DLL" ALIAS "HlinkSetSpecialReference" ( _
   BYVAL uReference AS DWORD _                          ' __in  ULONG uReference
 , BYREF pwzReference AS WSTRINGZ _                     ' __in  LPCWSTR pwzReference
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION HlinkGetSpecialReference IMPORT "HLINK.DLL" ALIAS "HlinkGetSpecialReference" ( _
   BYVAL uReference AS DWORD _                          ' __in  ULONG uReference
 , BYREF ppwzReference AS DWORD _                       ' __out LPWSTR *ppwzReference
 ) AS LONG                                              ' HRESULT

' HLSHORTCUTF enum
%HLSHORTCUTF_DEFAULT                     = 0
%HLSHORTCUTF_DONTACTUALLYCREATE          = &H1
%HLSHORTCUTF_USEFILENAMEFROMFRIENDLYNAME = &H2
%HLSHORTCUTF_USEUNIQUEFILENAME           = &H4
%HLSHORTCUTF_MAYUSEEXISTINGSHORTCUT      = &H8

' Not currently supported
'DECLARE FUNCTION HlinkCreateShortcut IMPORT "HLINK.DLL" ALIAS "HlinkCreateShortcut" ( _
'   BYVAL grfHLSHORTCUTF AS DWORD _                      ' __in  DWORD grfHLSHORTCUTF
' , BYVAL pihl AS IHlink _                               ' __in  IHlink *pihl
' , BYREF pwzDir AS WSTRINGZ _                           ' __in  LPCWSTR pwzDir
' , BYREF pwzFileName AS WSTRINGZ _                      ' __in  LPCWSTR pwzFileName
' , BYREF ppwzShortcutFile AS DWORD _                    ' __out LPWSTR *ppwzShortcutFile
' , BYVAL dwReserved AS DWORD _                          ' __in  DWORD dwReserved
' ) AS LONG                                              ' HRESULT

' Not currently supported
'DECLARE FUNCTION HlinkCreateShortcutFromMoniker IMPORT "HLINK.DLL" ALIAS "HlinkCreateShortcutFromMoniker" ( _
'   BYVAL grfHLSHORTCUTF AS DWORD _                      ' __in  DWORD grfHLSHORTCUTF
' , BYVAL pimkTarget AS IMoniker _                       ' __in  IMoniker *pimkTarget
' , BYREF pwzLocation AS WSTRINGZ _                      ' __in  LPCWSTR pwzLocation
' , BYREF pwzDir AS WSTRINGZ _                           ' __in  LPCWSTR pwzDir
' , BYREF pwzFileName AS WSTRINGZ _                      ' __in  LPCWSTR pwzFileName
' , BYREF ppwzShortcutFile AS DWORD _                    ' __out LPWSTR *ppwzShortcutFile
' , BYVAL dwReserved AS DWORD _                          ' __in  DWORD dwReserved
' ) AS LONG                                              ' HRESULT

' Not currently supported
'DECLARE FUNCTION HlinkCreateShortcutFromString IMPORT "HLINK.DLL" ALIAS "HlinkCreateShortcutFromString" ( _
'   BYVAL grfHLSHORTCUTF AS DWORD _                      ' __in  DWORD grfHLSHORTCUTF
' , BYREF pwzTarget AS WSTRINGZ _                        ' __in  LPCWSTR pwzTarget
' , BYREF pwzLocation AS WSTRINGZ _                      ' __in  LPCWSTR pwzLocation
' , BYREF pwzDir AS WSTRINGZ _                           ' __in  LPCWSTR pwzDir
' , BYREF pwzFileName AS WSTRINGZ _                      ' __in  LPCWSTR pwzFileName
' , BYREF ppwzShortcutFile AS DWORD _                    ' __out LPWSTR *ppwzShortcutFile
' , BYVAL dwReserved AS DWORD _                          ' __in  DWORD dwReserved
' ) AS LONG                                              ' HRESULT

' Not currently supported
'DECLARE FUNCTION HlinkResolveShortcut IMPORT "HLINK.DLL" ALIAS "HlinkResolveShortcut" ( _
'   BYREF pwzShortcutFileName AS WSTRINGZ _              ' __in  LPCWSTR pwzShortcutFileName
' , BYVAL pihlsite AS IHlinkSite _                       ' __in  IHlinkSite * pihlsite
' , BYVAL dwSiteData AS DWORD _                          ' __in  DWORD dwSiteData
' , BYVAL piunkOuter AS IUnknown _                       ' __in  IUnknown * piunkOuter
' , BYREF riid AS GUID _                                 ' __in  REFIID riid
' , BYREF ppvObj AS ANY _                                ' __out void ** ppvObj
' ) AS LONG                                              ' HRESULT

' Not currently supported
'DECLARE FUNCTION HlinkResolveShortcutToMoniker IMPORT "HLINK.DLL" ALIAS "HlinkResolveShortcutToMoniker" ( _
'   BYREF pwzShortcutFileName AS WSTRINGZ _              ' __in  LPCWSTR pwzShortcutFileName
' , BYVAL ppimkTarget AS IMoniker _                      ' __in  IMoniker **ppimkTarget
' , BYREF ppwzLocation AS DWORD _                        ' __out LPWSTR *ppwzLocation
' ) AS LONG                                              ' HRESULT

' Not currently supported
'DECLARE FUNCTION HlinkResolveShortcutToString IMPORT "HLINK.DLL" ALIAS "HlinkResolveShortcutToString" ( _
'   BYREF pwzShortcutFileName AS WSTRINGZ _              ' __in  LPCWSTR pwzShortcutFileName
' , BYREF ppwzTarget AS DWORD _                          ' __out LPWSTR *ppwzTarget
' , BYREF ppwzLocation AS DWORD _                        ' __out LPWSTR *ppwzLocation
' ) AS LONG                                              ' HRESULT

' Not currently supported
'DECLARE FUNCTION HlinkIsShortcut IMPORT "HLINK.DLL" ALIAS "HlinkIsShortcut" ( _
'   BYREF pwzFileName AS WSTRINGZ _                      ' __in  LPCWSTR pwzFileName
' ) AS LONG                                              ' HRESULT

' Not currently supported
'DECLARE FUNCTION HlinkGetValueFromParams IMPORT "HLINK.DLL" ALIAS "HlinkGetValueFromParams" ( _
'   BYREF pwzParams AS WSTRINGZ _                        ' __in  LPCWSTR pwzParams
' , BYREF pwzName AS WSTRINGZ _                          ' __in  LPCWSTR pwzName
' , BYREF ppwzValue AS DWORD _                           ' __out LPWSTR *ppwzValue
' ) AS LONG                                              ' HRESULT

' HLTRANSLATEF enum
%HLTRANSLATEF_DEFAULT                = 0
%HLTRANSLATEF_DONTAPPLYDEFAULTPREFIX = &H1


' Not currently supported
'DECLARE FUNCTION HlinkTranslateURL IMPORT "HLINK.DLL" ALIAS "HlinkTranslateURL" ( _
'   BYREF pwzURL AS WSTRINGZ _                           ' __in  LPCWSTR pwzURL
' , BYVAL grfFlags AS DWORD _                            ' __in  DWORD grfFlags
' , BYREF ppwzTranslatedURL AS DWORD _                   ' __out LPWSTR *ppwzTranslatedURL
' ) AS LONG                                              ' HRESULT


'/****************************************************************************/
'/**** Hyperlink interface definitions                                    ****/
'/****************************************************************************/

#IF NOT %DEF(%IHlink_INTERFACE_DEFINED)
%IHlink_INTERFACE_DEFINED = 1

' HLNF enum
%HLNF_INTERNALJUMP          = &H1
%HLNF_OPENINNEWWINDOW       = &H2
%HLNF_NAVIGATINGBACK        = &H4
%HLNF_NAVIGATINGFORWARD     = &H8
%HLNF_NAVIGATINGTOSTACKITEM = &H10
%HLNF_CREATENOHISTORY       = &H20

' HLINKGETREF enum
%HLINKGETREF_DEFAULT  = 0
%HLINKGETREF_ABSOLUTE = 1
%HLINKGETREF_RELATIVE = 2

' HLFNAMEF enum
%HLFNAMEF_DEFAULT          = 0
%HLFNAMEF_TRYCACHE         = &H1
%HLFNAMEF_TRYPRETTYTARGET  = &H2
%HLFNAMEF_TRYFULLTARGET    = &H4
%HLFNAMEF_TRYWIN95SHORTCUT = &H8


' HLINKMISC enum
%HLINKMISC_RELATIVE = &H1

' HLINKSETF enum
%HLINKSETF_TARGET   = &H1
%HLINKSETF_LOCATION = &H2


' ########################################################################################
' IHlink interface
' IID = 79eac9c3-baf9-11ce-8c82-00aa004ba90b
' Inherited interface = IUnknown
' ########################################################################################

$IID_IHlink = GUID$("{79eac9c3-baf9-11ce-8c82-00aa004ba90b}")

INTERFACE IHlink $IID_IHlink

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetHlinkSite ( _                              ' VTable offset = 12
     BYVAL pihlSite AS IHlinkSite _                     ' __in IHlinkSite *pihlSite
   , BYVAL dwSiteData AS DWORD _                        ' __in DWORD dwSiteData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetHlinkSite ( _                              ' VTable offset = 16
     BYREF ppihlSite AS IHlinkSite _                    ' __out IHlinkSite **ppihlSite,
   , BYREF pdwSiteData AS DWORD _                       ' __out DWORD *pdwSiteData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetMonikerReference ( _                       ' VTable offset = 20
     BYVAL grfHLSETF AS DWORD _                         ' __in DWORD grfHLSETF
   , BYVAL pimkTarget AS IMoniker _                     ' __in IMoniker *pimkTarget
   , BYREF pwzLocation AS WSTRINGZ _                    ' __in LPCWSTR pwzLocation
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMonikerReference ( _                       ' VTable offset = 24
     BYVAL dwWhichRef AS DWORD _                        ' __in DWORD dwWhichRef
   , BYREF ppimkTarget AS IMoniker _                    ' __out IMoniker **ppimkTarget
   , BYREF ppwzLocation AS DWORD _                      ' __out LPWSTR *ppwzLocation
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetStringReference ( _                        ' VTable offset = 28
     BYVAL grfHLSETF AS DWORD _                         ' __in DWORD grfHLSETF
   , BYREF pwzTarget AS WSTRINGZ _                      ' __in LPCWSTR pwzTarget
   , BYREF pwzLocation AS WSTRINGZ _                    ' __in LPCWSTR pwzLocation
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetStringReference ( _                        ' VTable offset = 32
     BYVAL dwWhichRef AS DWORD _                        ' __in DWORD dwWhichRef
   , BYREF ppwzTarget AS DWORD _                        ' __out LPWSTR *ppwzTarget
   , BYREF ppwzLocation AS DWORD _                      ' __out LPWSTR *ppwzLocation
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetFriendlyName ( _                           ' VTable offset = 36
     BYREF pwzFriendlyName AS WSTRINGZ _                ' __in LPCWSTR pwzFriendlyName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFriendlyName ( _                           ' VTable offset = 40
     BYVAL grfHLFNAMEF AS DWORD _                       ' __in DWORD grfHLFNAMEF
   , BYREF ppwzFriendlyName AS DWORD _                  ' __out LPWSTR *ppwzFriendlyName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetTargetFrameName ( _                        ' VTable offset = 44
     BYREF pwzTargetFrameName AS WSTRINGZ _             ' __in LPCWSTR pwzTargetFrameName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTargetFrameName ( _                        ' VTable offset = 48
     BYREF ppwzTargetFrameName AS DWORD _               ' __out LPWSTR *ppwzTargetFrameName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMiscStatus ( _                             ' VTable offset = 52
     BYREF pdwStatus AS DWORD _                         ' __out DWORD *pdwStatus
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Navigate ( _                                  ' VTable offset = 56
     BYVAL grfHLNF AS DWORD _                           ' __in DWORD grfHLNF
   , BYVAL pibc AS IBindCtx _                           ' __in LPBC pibc
   , BYVAL pibsc AS IBindStatusCallback _               ' __in IBindStatusCallback *pibsc
   , BYVAL pihlbc AS IHlinkBrowseContext _              ' __in IHlinkBrowseContext *pihlbc
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetAdditionalParams ( _                       ' VTable offset = 60
     BYREF pwzAdditionalParams AS WSTRINGZ _            ' __in LPCWSTR pwzAdditionalParams
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAdditionalParams ( _                       ' VTable offset = 64
     BYREF ppwzAdditionalParams AS DWORD _              ' __out LPWSTR *ppwzAdditionalParams
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IHlink_INTERFACE_DEFINED__ */


#IF NOT %DEF(%IHlinkSite_INTERFACE_DEFINED)
%IHlinkSite_INTERFACE_DEFINED = 1

' HLINKWHICHMK enum
%HLINKWHICHMK_CONTAINER = 1
%HLINKWHICHMK_BASE      = 2


' ########################################################################################
' IHlinkSite interface
' IID = 79eac9c3-baf9-11ce-8c82-00aa004ba90b
' Inherited interface = IUnknown
' ########################################################################################

$IID_IHlinkSite = GUID$("{79eac9c2-baf9-11ce-8c82-00aa004ba90b}")

INTERFACE IHlinkSite $IID_IHlinkSite

   INHERIT IUnknown

   ' =====================================================================================
   METHOD QueryService ( _                              ' VTable offset = 12
     BYVAL dwSiteData AS DWORD _                        ' __in  DWORD dwSiteData
   , BYREF guidService AS GUID _                        ' __in  REFGUID guidService
   , BYREF riid AS GUID _                               ' __in  REFIID riid
   , BYREF ppiunk AS IUnknown _                         ' __out IUnknown **ppiunk
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMoniker ( _                                ' VTable offset = 16
     BYVAL dwSiteData AS DWORD _                        ' __in  DWORD dwSiteData
   , BYVAL dwAssign AS DWORD _                          ' __in  DWORD dwAssign
   , BYVAL dwWhich AS DWORD _                           ' __in  DWORD dwWhich
   , BYREF ppimk AS IMoniker _                          ' __out IMoniker **ppimk
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ReadyToNavigate ( _                           ' VTable offset = 20
     BYVAL dwSiteData AS DWORD _                        ' __in DWORD dwSiteData
   , BYVAL dwReserved AS DWORD _                        ' __in DWORD dwReserved
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnNavigationComplete ( _                      ' VTable offset = 24
     BYVAL dwSiteData AS DWORD _                        ' __in DWORD dwSiteData
   , BYVAL dwReserved AS DWORD _                        ' __in DWORD dwReserved
   , BYVAL hrError AS DWORD _                           ' __in HRESULT hrError
   , BYREF pwzError AS WSTRINGZ _                       ' __in LPCWSTR pwzError
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IHlinkSite_INTERFACE_DEFINED__ */


#IF NOT %DEF(%IHlinkTarget_INTERFACE_DEFINED)
%IHlinkTarget_INTERFACE_DEFINED = 1

' ########################################################################################
' IHlinkTarget interface
' IID = 79eac9c3-baf9-11ce-8c82-00aa004ba90b
' Inherited interface = IUnknown
' ########################################################################################

$IID_IHlinkTarget = GUID$("{79eac9c4-baf9-11ce-8c82-00aa004ba90b}")

INTERFACE IHlinkTarget $IID_IHlinkTarget

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetBrowseContext ( _                          ' VTable offset = 12
     BYVAL pihlbc AS IHlinkBrowseContext _              ' __in IHlinkBrowseContext *pihlbc
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetBrowseContext ( _                          ' VTable offset = 16
     BYREF ppihlbc AS IHlinkBrowseContext _             ' __out IHlinkBrowseContext **ppihlbc
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Navigate ( _                                  ' VTable offset = 20
     BYVAL grfHLNF AS DWORD _                           ' __in DWORD grfHLNF
   , BYREF pwzJumpLocation AS WSTRINGZ _                ' __in LPCWSTR pwzJumpLocation
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMoniker ( _                                ' VTable offset = 24
     BYREF pwzLocation AS WSTRINGZ _                    ' __in  LPCWSTR pwzLocation
   , BYVAL dwAssign AS DWORD _                          ' __in  DWORD dwAssign
   , BYREF ppimkLocation AS IMoniker _                  ' __out IMoniker **ppimkLocation
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFriendlyName ( _                           ' VTable offset = 28
     BYREF pwzLocation AS WSTRINGZ _                    ' __in  LPCWSTR pwzLocation
   , BYREF ppwzFriendlyName AS DWORD _                  ' __out LPWSTR *ppwzFriendlyName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IHlinkTarget_INTERFACE_DEFINED__ */


#IF NOT %DEF(%IHlinkFrame_INTERFACE_DEFINED)
%IHlinkFrame_INTERFACE_DEFINED = 1

' ########################################################################################
' IHlinkFrame interface
' IID = 79eac9c5-baf9-11ce-8c82-00aa004ba90b
' Inherited interface = IUnknown
' ########################################################################################

$IID_IHlinkFrame = GUID$("{79eac9c5-baf9-11ce-8c82-00aa004ba90b}")

INTERFACE IHlinkFrame $IID_IHlinkFrame

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetBrowseContext ( _                          ' VTable offset = 12
     BYVAL pihlbc AS IHlinkBrowseContext _              ' __in IHlinkBrowseContext *pihlbc
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetBrowseContext ( _                          ' VTable offset = 16
     BYREF ppihlbc AS IHlinkBrowseContext _             ' __out IHlinkBrowseContext **ppihlbc
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Navigate ( _                                  ' VTable offset = 20
     BYVAL grfHLNF AS DWORD _                           ' __in DWORD grfHLNF
   , BYVAL pbc AS IBindCtx _                            ' __in LPBC pbc
   , BYVAL pibsc AS IBindStatusCallback _               ' __in IBindStatusCallback *pibsc
   , BYVAL pihlNavigate AS IHlink _                     ' __in IHlink *pihlNavigate
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnNavigate ( _                                ' VTable offset = 24
     BYVAL grfHLNF AS DWORD _                           ' __in DWORD grfHLNF
   , BYVAL pimkTarget AS IMoniker _                     ' __in IMoniker *pimkTarget
   , BYREF pwzLocation AS WSTRINGZ _                    ' __in LPCWSTR pwzLocation
   , BYREF pwzFriendlyName AS WSTRINGZ _                ' __in LPCWSTR pwzFriendlyName
   , BYVAL dwReserved AS DWORD _                        ' __in DWORD dwReserved
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UpdateHlink ( _                               ' VTable offset = 28
     BYVAL uHLID AS DWORD _                             ' __in ULONG uHLID
   , BYVAL pimkTarget AS IMoniker _                     ' __in IMoniker *pimkTarget
   , BYREF pwzLocation AS WSTRINGZ _                    ' __in LPCWSTR pwzLocation
   , BYREF pwzFriendlyName AS WSTRINGZ _                ' __in LPCWSTR pwzFriendlyName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IHlinkFrame_INTERFACE_DEFINED__ */


#IF NOT %DEF(%IEnumHLITEM_INTERFACE_DEFINED)
%IEnumHLITEM_INTERFACE_DEFINED = 1

' // Size = 8 bytes
TYPE HLITEM DWORD
   uHLID           AS DWORD          ' ULONG
   pwzFriendlyName AS WSTRINGZ PTR   ' LPWSTR
END TYPE

' ########################################################################################
' IEnumHLITEM interface
' IID = 79eac9c6-baf9-11ce-8c82-00aa004ba90b
' Inherited interface = IUnknown
' ########################################################################################

$IID_IEnumHLITEM = GUID$("{79eac9c6-baf9-11ce-8c82-00aa004ba90b}")

INTERFACE IEnumHLITEM $IID_IEnumHLITEM

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Next ( _                                      ' VTable offset = 12
     BYVAL celt AS DWORD _                              ' __in  ULONG celt
   , BYREF rgelt AS HLITEM _                            ' __out HLITEM *rgelt
   , BYREF pceltFetched AS DWORD _                      ' __out ULONG *pceltFetched
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
     BYREF ppienumhlitem AS IEnumHLITEM _               ' __out IEnumHLITEM **ppienumhlitem
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEnumHLITEM_INTERFACE_DEFINED__ */


#IF NOT %DEF(%IHlinkBrowseContext_INTERFACE_DEFINED)
%IHlinkBrowseContext_INTERFACE_DEFINED = 1

' enum __MIDL_IHlinkBrowseContext_0001
%HLTB_DOCKEDLEFT   = 0
%HLTB_DOCKEDTOP    = 1
%HLTB_DOCKEDRIGHT  = 2
%HLTB_DOCKEDBOTTOM = 3
%HLTB_FLOATING     = 4

' // Size = 20 bytes
TYPE HLTBINFO DWORD
   uDockType AS DWORD   ' ULONG
   rcTbPos   AS RECT    ' RECT
END TYPE

' enum __MIDL_IHlinkBrowseContext_0002
%HLBWIF_HASFRAMEWNDINFO   = &H1
%HLBWIF_HASDOCWNDINFO     = &H2
%HLBWIF_FRAMEWNDMAXIMIZED = &H4
%HLBWIF_DOCWNDMAXIMIZED   = &H8
%HLBWIF_HASWEBTOOLBARINFO = &H10
%HLBWIF_WEBTOOLBARHIDDEN  = &H20

' // Size = 60 bytes
TYPE HLBWINFO DWORD
   cbSize     AS DWORD      ' ULONG
   grfHLBWIF  AS DWORD      ' DWORD
   rcFramePos AS RECT       ' RECT
   rcDocPos   AS RECT       ' RECT
   hltbinfo   AS HLTBINFO   ' HLTBINFO
END TYPE

' enum __MIDL_IHlinkBrowseContext_0003
%HLID_INVALID     = 0
%HLID_PREVIOUS    = &Hffffffff
%HLID_NEXT        = &Hfffffffe
%HLID_CURRENT     = &Hfffffffd
%HLID_STACKBOTTOM = &Hfffffffc
%HLID_STACKTOP    = &Hfffffffb

' enum __MIDL_IHlinkBrowseContext_0004
%HLQF_ISVALID   = &H1
%HLQF_ISCURRENT = &H2


' ########################################################################################
' IHlinkBrowseContext interface
' IID = 79eac9c7-baf9-11ce-8c82-00aa004ba90b
' Inherited interface = IUnknown
' ########################################################################################

$IID_IHlinkBrowseContext = GUID$("{79eac9c7-baf9-11ce-8c82-00aa004ba90b}")

INTERFACE IHlinkBrowseContext $IID_IHlinkBrowseContext

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Register ( _                                  ' VTable offset = 12
     BYVAL reserved AS DWORD _                          ' __in  DWORD reserved
   , BYVAL piunk AS IUnknown _                          ' __in  IUnknown *piunk
   , BYVAL pimk AS IMoniker _                           ' __in  IMoniker *pimk
   , BYREF pdwRegister AS DWORD _                       ' __out DWORD *pdwRegister
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetObject ( _                                 ' VTable offset = 16
     BYVAL pimk AS IMoniker _                           ' __in  IMoniker *pimk
   , BYVAL fBindIfRootRegistered AS LONG _              ' __in  BOOL fBindIfRootRegistered
   , BYREF ppiunk AS IUnknown _                         ' __out IUnknown **ppiunk
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Revoke ( _                                    ' VTable offset = 20
     BYVAL dwRegister AS DWORD _                        ' __in DWORD dwRegister
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetBrowseWindowInfo ( _                       ' VTable offset = 24
     BYREF phlbwi AS HLBWINFO _                         ' __in HLBWINFO *phlbwi
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetBrowseWindowInfo ( _                       ' VTable offset = 28
     BYREF phlbwi AS HLBWINFO _                         ' __out HLBWINFO *phlbwi
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetInitialHlink ( _                           ' VTable offset = 32
     BYVAL pimkTarget AS IMoniker _                     ' __in IMoniker *pimkTarget
   , BYREF pwzLocation AS WSTRINGZ _                    ' __in LPCWSTR pwzLocation
   , BYREF pwzFriendlyName AS WSTRINGZ _                ' __in LPCWSTR pwzFriendlyName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnNavigateHlink ( _                           ' VTable offset = 36
     BYVAL grfHLNF AS DWORD _                           ' __in  DWORD grfHLNF
   , BYVAL pimkTarget AS IMoniker _                     ' __in  IMoniker *pimkTarget
   , BYREF pwzLocation AS WSTRINGZ _                    ' __in  LPCWSTR pwzLocation
   , BYREF pwzFriendlyName AS WSTRINGZ _                ' __in  LPCWSTR pwzFriendlyName
   , BYREF puHLID AS DWORD _                            ' __out ULONG *puHLID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UpdateHlink ( _                               ' VTable offset = 40
     BYVAL uHLID AS DWORD _                             ' __in ULONG uHLID
   , BYVAL pimkTarget AS IMoniker _                     ' __in IMoniker *pimkTarget
   , BYREF pwzLocation AS WSTRINGZ _                    ' __in LPCWSTR pwzLocation
   , BYREF pwzFriendlyName AS WSTRINGZ _                ' __in LPCWSTR pwzFriendlyName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumNavigationStack ( _                       ' VTable offset = 44
     BYVAL dwReserved AS DWORD _                        ' __in  DWORD dwReserved
   , BYVAL grfHLFNAMEF AS DWORD _                       ' __in  DWORD grfHLFNAMEF
   , BYREF ppienumhlitem AS IEnumHLITEM _               ' __out IEnumHLITEM **ppienumhlitem
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD QueryHlink ( _                                ' VTable offset = 48
     BYVAL grfHLQF AS DWORD _                           ' __in DWORD grfHLQF
   , BYVAL uHLID AS DWORD _                             ' __in ULONG uHLID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetHlink ( _                                  ' VTable offset = 52
     BYVAL uHLID AS DWORD _                             ' __in  ULONG uHLID
   , BYREF ppihl AS IHlink _                            ' __out IHlink **ppihl
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetCurrentHlink ( _                           ' VTable offset = 56
     BYVAL uHLID AS DWORD _                             ' __in ULONG uHLID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 60
     BYVAL piunkOuter AS IUnknown _                     ' __in  IUnknown *piunkOuter
   , BYREF riid AS GUID _                               ' __in  REFIID riid
   , BYREF ppiunkObj AS IUnknown _                      ' __out IUnknown **ppiunkObj
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Close ( _                                     ' VTable offset = 64
     BYVAL reserved AS DWORD _                          ' __in DWORD reserved
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IHlinkBrowseContext_INTERFACE_DEFINED__ */


#IF NOT %DEF(%IExtensionServices_INTERFACE_DEFINED)
%IExtensionServices_INTERFACE_DEFINED = 1

' ########################################################################################
' IExtensionServices interface
' IID = 79eac9cb-baf9-11ce-8c82-00aa004ba90b
' Inherited interface = IUnknown
' ########################################################################################

$IID_IExtensionServices = GUID$("{79eac9cb-baf9-11ce-8c82-00aa004ba90b}")

INTERFACE IExtensionServices $IID_IExtensionServices

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetAdditionalHeaders ( _                      ' VTable offset = 12
     BYREF pwzAdditionalHeaders AS WSTRINGZ _           ' __in LPCWSTR pwzAdditionalHeaders
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetAuthenticateData ( _                       ' VTable offset = 16
     BYVAL phwnd AS DWORD _                             ' __in HWND phwnd
   , BYREF pwzUsername AS WSTRINGZ _                    ' __in LPCWSTR pwzUsername
   , BYREF pwzPassword AS WSTRINGZ _                    ' __in LPCWSTR pwzPassword
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IExtensionServices_INTERFACE_DEFINED__ */
