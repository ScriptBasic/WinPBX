' ########################################################################################
' Microsoft Windows
' File: gameux.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%GAMEUX_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "oaidl.inc"
#INCLUDE ONCE "ocidl.inc"
#INCLUDE ONCE "shobjidl.inc"

'#define ID_GDF_XML __GDF_XML
'#define ID_GDF_THUMBNAIL __GDF_THUMBNAIL
'#define ID_ICON_ICO __ICON_ICO
'#define ID_GDF_XML_STR L"__GDF_XML"
'#define ID_GDF_THUMBNAIL_STR L"__GDF_THUMBNAIL"

' enum GAME_INSTALL_SCOPE
%GIS_NOT_INSTALLED = 1
%GIS_CURRENT_USER  = 2
%GIS_ALL_USERS     = 3

$CLSID_GameExplorer = GUID$("{9A5EA990-3034-4D6F-9128-01F3C61022BC}")
$CLSID_GameStatistics = GUID$("{DBC85A2C-C0DC-4961-B6E2-D28B62C11AD4}")

' ########################################################################################
' IGameExplorer interface
' IID = E7B2FB72-D728-49B3-A5F2-18EBF5F1349E
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IGameExplorer_INTERFACE_DEFINED)
    %IGameExplorer_INTERFACE_DEFINED = 1

$IID_IGameExplorer = GUID$("{E7B2FB72-D728-49B3-A5F2-18EBF5F1349E}")

INTERFACE IGameExplorer $IID_IGameExplorer

   INHERIT IUnknown

   ' =====================================================================================
   METHOD AddGame ( _                                   ' VTable offset = 12
     BYVAL bstrGDFBinaryPath AS WSTRING _               ' __in BSTR bstrGDFBinaryPath
   , BYVAL bstrGameInstallDirectory AS WSTRING _        ' __in BSTR bstrGameInstallDirectory
   , BYVAL installScope AS DWORD _                      ' __in GAME_INSTALL_SCOPE installScope
   , BYREF pguidInstanceID AS GUID _                    ' __inout GUID *pguidInstanceID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RemoveGame ( _                                ' VTable offset = 16
     BYVAL guidInstanceID AS GUID _                     ' __in GUID guidInstanceID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UpdateGame ( _                                ' VTable offset = 20
     BYVAL guidInstanceID AS GUID _                     ' __in GUID guidInstanceID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD VerifyAccess ( _                              ' VTable offset = 24
     BYVAL bstrGDFBinaryPath AS WSTRING _               ' __in BSTR bstrGDFBinaryPath
   , BYREF pfHasAccess AS LONG _                        ' __out BOOL *pfHasAccess
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IGameExplorer_INTERFACE_DEFINED__ */

' enum GAMESTATS_OPEN_TYPE
%GAMESTATS_OPEN_OPENORCREATE = 0
%GAMESTATS_OPEN_OPENONLY     = 1

' enum GAMESTATS_OPEN_RESULT
%GAMESTATS_OPEN_CREATED = 0
%GAMESTATS_OPEN_OPENED  = 1

' ########################################################################################
' IGameStatistics interface
' IID = 3887C9CA-04A0-42ae-BC4C-5FA6C7721145
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IGameStatistics_INTERFACE_DEFINED)
    %IGameStatistics_INTERFACE_DEFINED = 1

$IID_IGameStatistics = GUID$("{3887C9CA-04A0-42ae-BC4C-5FA6C7721145}")

INTERFACE IGameStatistics $IID_IGameStatistics

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetMaxCategoryLength ( _                      ' VTable offset = 12
     BYREF cch AS DWORD _                               ' __out UINT *cch
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMaxNameLength ( _                          ' VTable offset = 16
     BYREF cch AS DWORD _                               ' __out UINT *cch
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMaxValueLength ( _                         ' VTable offset = 20
     BYREF cch AS DWORD _                               ' __out UINT *cch
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMaxCategories ( _                          ' VTable offset = 24
     BYREF pMax AS WORD _                               ' __out WORD *pMax
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMaxStatsPerCategory ( _                    ' VTable offset = 28
     BYREF pMax AS WORD _                               ' __out WORD *pMax
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetCategoryTitle ( _                          ' VTable offset = 32
     BYVAL categoryIndex AS WORD _                      ' __in WORD categoryIndex
   , BYREF title AS WSTRINGZ _                          ' __in LPCWSTR title
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCategoryTitle ( _                          ' VTable offset = 36
     BYVAL categoryIndex AS WORD _                      ' __in WORD categoryIndex
   , BYREF pTitle AS DWORD _                            ' __out LPWSTR *pTitle
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetStatistic ( _                              ' VTable offset = 40
     BYVAL categoryIndex AS WORD _                      ' __in WORD categoryIndex
   , BYVAL statIndex AS WORD _                          ' __in WORD statIndex
   , BYREF pName AS DWORD _                             ' __inout LPWSTR *pName
   , BYREF pValue AS DWORD _                            ' __inout LPWSTR *pValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetStatistic ( _                              ' VTable offset = 44
     BYVAL categoryIndex AS WORD _                      ' __in WORD categoryIndex
   , BYVAL statIndex AS WORD _                          ' __in WORD statIndex
   , BYREF name AS WSTRINGZ _                           ' __in LPCWSTR name
   , BYREF value AS WSTRINGZ _                          ' __in LPCWSTR value
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Save ( _                                      ' VTable offset = 48
     BYVAL trackChanges AS LONG _                       ' __in BOOL trackChanges
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetLastPlayedCategory ( _                     ' VTable offset = 52
     BYVAL categoryIndex AS DWORD _                     ' __in UINT categoryIndex
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetLastPlayedCategory ( _                     ' VTable offset = 56
     BYREF pCategoryIndex AS DWORD _                    ' __out UINT *pCategoryIndex
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IGameStatistics_INTERFACE_DEFINED__ */

' ########################################################################################
' IGameStatisticsMgr interface
' IID = AFF3EA11-E70E-407d-95DD-35E612C41CE2
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IGameStatisticsMgr_INTERFACE_DEFINED)
    %IGameStatisticsMgr_INTERFACE_DEFINED = 1

$IID_IGameStatisticsMgr = GUID$("{AFF3EA11-E70E-407d-95DD-35E612C41CE2}")

INTERFACE IGameStatisticsMgr $IID_IGameStatisticsMgr

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetGameStatistics ( _                         ' VTable offset = 12
     BYREF GDFBinaryPath AS WSTRINGZ _                  ' __in LPCWSTR GDFBinaryPath
   , BYVAL openType AS LONG _                           ' __in GAMESTATS_OPEN_TYPE openType
   , BYREF pOpenResult AS LONG _                        ' __out GAMESTATS_OPEN_RESULT *pOpenResult
   , BYREF ppiStats AS IGameStatistics _                ' __out IGameStatistics **ppiStats
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RemoveGameStatistics ( _                      ' VTable offset = 16
     BYREF GDFBinaryPath AS WSTRINGZ _                  ' __in LPCWSTR GDFBinaryPath
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IGameStatisticsMgr_INTERFACE_DEFINED__ */

' ########################################################################################
' IGameExplorer2 interface
' IID = 86874AA7-A1ED-450d-A7EB-B89E20B2FFF3
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IGameExplorer2_INTERFACE_DEFINED)
    %IGameExplorer2_INTERFACE_DEFINED = 1

$IID_IGameExplorer2 = GUID$("{86874AA7-A1ED-450d-A7EB-B89E20B2FFF3}")

INTERFACE IGameExplorer2 $IID_IGameExplorer2

   INHERIT IUnknown

   ' =====================================================================================
   METHOD InstallGame ( _                               ' VTable offset = 12
     BYREF binaryGDFPath AS WSTRINGZ _                  ' __in LPCWSTR binaryGDFPath
   , BYREF installDirectory AS WSTRINGZ _               ' __in LPCWSTR installDirectory
   , BYVAL installScope AS LONG _                       ' __in GAME_INSTALL_SCOPE installScope
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UninstallGame ( _                             ' VTable offset = 16
     BYREF binaryGDFPath AS WSTRINGZ _                  ' __in LPCWSTR binaryGDFPath
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CheckAccess ( _                               ' VTable offset = 20
     BYREF binaryGDFPath AS WSTRINGZ _                  ' __in LPCWSTR binaryGDFPath
   , BYREF pHasAccess AS LONG _                         ' __out BOOL *pHasAccess
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IGameExplorer2_INTERFACE_DEFINED__ */
