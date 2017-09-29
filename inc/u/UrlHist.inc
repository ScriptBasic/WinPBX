' ########################################################################################
' Microsoft Windows
' File: UrlHist.inc
' Contents: The IUrlHistory interfaces provide functionality to manage Microsoft Internet
' Explorer history information.
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%URLHIST_INC = 1

'/* header files for imported files */
#INCLUDE ONCE "objidl.inc"
#INCLUDE ONCE "oleidl.inc"
#INCLUDE ONCE "oaidl.inc"
#INCLUDE ONCE "docobj.inc"

'//=--------------------------------------------------------------------------=
'// UrlHist.h
'//=--------------------------------------------------------------------------=
'// (C) Copyright Microsoft Corporation.  All Rights Reserved.
'//
'// THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
'// ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO
'// THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
'// PARTICULAR PURPOSE.
'//=--------------------------------------------------------------------------=

'//---------------------------------------------------------------------------=
'// Url History Interfaces.


%STATURL_QUERYFLAG_ISCACHED = &H00010000???
%STATURL_QUERYFLAG_NOURL    = &H00020000???
%STATURL_QUERYFLAG_NOTITLE  = &H00040000???
%STATURL_QUERYFLAG_TOPLEVEL = &H00080000???
%STATURLFLAG_ISCACHED       = &H00000001???
%STATURLFLAG_ISTOPLEVEL     = &H00000002???

' ADDURL_FLAG enum
%ADDURL_FIRST                = 0
%ADDURL_ADDTOHISTORYANDCACHE = 0
%ADDURL_ADDTOCACHE           = 1
%ADDURL_Max                  = 2147483647&

'////////////////////////////////////////////////////////////////////////////
'//  Interface Definitions

' ########################################################################################
' IEnumSTATURL interface
' IID = 3C374A42-BAE4-11CF-BF7D-00AA006946EE
' Inherited interface = IUnknown
' This interface enumerates the items in the history cache.
' ########################################################################################

#IF NOT %DEF(%IEnumSTATURL_INTERFACE_DEFINED)
    %IEnumSTATURL_INTERFACE_DEFINED = 1

' // Size = 40 bytes
TYPE STATURL DWORD
   cbSize        AS DWORD                        ' DWORD cbSize
   pwcsUrl       AS WSTRINGZ PTR                 ' LPWSTR pwcsUrl
   pwcsTitle     AS WSTRINGZ PTR                 ' LPWSTR pwcsTitle
   ftLastVisited AS FILETIME                     ' FILETIME ftLastVisited
   ftLastUpdated AS FILETIME                     ' FILETIME ftLastUpdated
   ftExpires     AS FILETIME                     ' FILETIME ftExpires
   dwFlags       AS DWORD                        ' DWORD dwFlags
END TYPE

$IID_IEnumSTATURL = GUID$("{3C374A42-BAE4-11CF-BF7D-00AA006946EE}")

INTERFACE IEnumSTATURL $IID_IEnumSTATURL

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Next ( _                                      ' VTable offset = 12
     BYVAL celt AS DWORD _                              ' __in unsigned long celt
   , BYREF rgelt AS STATURL _                           ' __inout LPSTATURL rgelt
   , BYREF pceltFetched AS DWORD _                      ' __inout ULONG *pceltFetched
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
     BYREF ppenum AS IEnumSTATURL _                     ' __out IEnumSTATURL **ppenum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetFilter ( _                                 ' VTable offset = 28
      BYREF poszFilter AS WSTRINGZ _                    ' __in LPCOLESTR poszFilter
    , BYVAL dwFlags AS DWORD _                          ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEnumSTATURL_INTERFACE_DEFINED__ */


' ########################################################################################
' IUrlHistoryStg interface
' IID = 3C374A41-BAE4-11CF-BF7D-00AA006946EE
' Inherited interface = IUnknown
' This interface manages Microsoft Internet Explorer history for the current user.
' ########################################################################################

#IF NOT %DEF(%IUrlHistoryStg_INTERFACE_DEFINED)
    %IUrlHistoryStg_INTERFACE_DEFINED = 1

$IID_IUrlHistoryStg = GUID$("{3C374A41-BAE4-11CF-BF7D-00AA006946EE}")

INTERFACE IUrlHistoryStg $IID_IUrlHistoryStg

   INHERIT IUnknown

   ' =====================================================================================
   METHOD AddUrl ( _                                    ' VTable offset = 12
     BYREF pocsUrl AS WSTRINGZ _                        ' __in LPCOLESTR pocsUrl
   , BYREF pocsTitle AS WSTRINGZ _                      ' __in LPCOLESTR pocsTitle
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DeleteUrl ( _                                 ' VTable offset = 16
     BYREF pocsUrl AS WSTRINGZ _                        ' __in LPCOLESTR pocsUrl
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD QueryUrl ( _                                  ' VTable offset = 20
     BYREF pocsUrl AS WSTRINGZ _                        ' __in LPCOLESTR pocsUrl
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF lpSTATURL AS STATURL _                       ' __inout LPSTATURL lpSTATURL
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD BindToObject ( _                              ' VTable offset = 24
     BYREF pocsUrl AS WSTRINGZ _                        ' __in LPCOLESTR pocsUrl
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppvOut AS IUnknown _                         ' __out void **ppvOut
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumUrls ( _                                  ' VTable offset = 28
     BYREF ppEnum AS IEnumSTATURL _                     ' __out IEnumSTATURL **ppEnum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IUrlHistoryStg_INTERFACE_DEFINED__ */


' ########################################################################################
' IUrlHistoryStg2 interface
' IID = AFA0DC11-C313-11d0-831A-00C04FD5AE38
' Inherited interface = IUrlHistoryStg
' This interface provides additional features for managing the user's history.
' ########################################################################################

#IF NOT %DEF(%IUrlHistoryStg2_INTERFACE_DEFINED)
    %IUrlHistoryStg2_INTERFACE_DEFINED = 1

$IID_IUrlHistoryStg2 = GUID$("{AFA0DC11-C313-11d0-831A-00C04FD5AE38}")

INTERFACE IUrlHistoryStg2 $IID_IUrlHistoryStg2

   INHERIT IUnknown

   ' =====================================================================================
   METHOD AddUrl ( _                                    ' VTable offset = 12
     BYREF pocsUrl AS WSTRINGZ _                        ' __in LPCOLESTR pocsUrl
   , BYREF pocsTitle AS WSTRINGZ _                      ' __in LPCOLESTR pocsTitle
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DeleteUrl ( _                                 ' VTable offset = 16
     BYREF pocsUrl AS WSTRINGZ _                        ' __in LPCOLESTR pocsUrl
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD QueryUrl ( _                                  ' VTable offset = 20
     BYREF pocsUrl AS WSTRINGZ _                        ' __in LPCOLESTR pocsUrl
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF lpSTATURL AS STATURL _                       ' __inout LPSTATURL lpSTATURL
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD BindToObject ( _                              ' VTable offset = 24
     BYREF pocsUrl AS WSTRINGZ _                        ' __in LPCOLESTR pocsUrl
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppvOut AS IUnknown _                         ' __out void **ppvOut
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumUrls ( _                                  ' VTable offset = 28
     BYREF ppEnum AS IEnumSTATURL _                     ' __out IEnumSTATURL **ppEnum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddUrlAndNotify ( _                           ' VTable offset = 32
     BYREF pocsUrl AS WSTRINGZ _                        ' __in LPCOLESTR pocsUrl
   , BYREF pocsTitle AS WSTRINGZ _                      ' __in LPCOLESTR pocsTitle
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYVAL fWriteHistory AS LONG _                      ' __in BOOL fWriteHistory
   , BYVAL poctNotify AS IOleCommandTarget _            ' __in IOleCommandTarget *poctNotify
   , BYVAL punkISFolder AS IUnknown _                   ' __in IUnknown *punkISFolder
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ClearHistory ( _                              ' VTable offset = 36
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IUrlHistoryStg2_INTERFACE_DEFINED__ */


' ########################################################################################
' IUrlHistoryNotify interface
' IID = BC40BEC1-C493-11d0-831B-00C04FD5AE38
' Inherited interface = IOleCommandTarget
' This interface is a remapping of the IOleCommandTarget interface.
' ########################################################################################

#IF NOT %DEF(%IUrlHistoryNotify_INTERFACE_DEFINED)
    %IUrlHistoryNotify_INTERFACE_DEFINED = 1

$IID_IUrlHistoryNotify = GUID$("{BC40BEC1-C493-11d0-831B-00C04FD5AE38}")

INTERFACE IUrlHistoryNotify $IID_IUrlHistoryNotify

   INHERIT IUnknown

   ' =====================================================================================
   METHOD QueryStatus ( _                               ' VTable offset = 12
     BYREF pguidCmdGroup AS GUID _                      ' __in const GUID *pguidCmdGroup
   , BYVAL cCmds AS DWORD _                             ' __in ULONG cCmds
   , BYREF prgCmds AS OLECMD _                          ' __out OLECMD *prgCmds
   , BYREF pCmdText AS OLECMDTEXT _                     ' __out OLECMDTEXT *pCmdText
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Exec ( _                                      ' VTable offset = 16
     BYREF pguidCmdGroup AS GUID _                      ' __in const GUID *pguidCmdGroup
   , BYVAL nCmdID AS DWORD _                            ' __in DWORD nCmdID
   , BYVAL nCmdExecOpt AS DWORD _                       ' __in DWORD nCmdExecOpt
   , BYREF pvaIn AS VARIANT _                           ' __in VARIANTARG *pvaIn
   , BYREF pvaOut AS VARIANT _                          ' __out * VARIANTARG *pvaOut
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IUrlHistoryNotify_INTERFACE_DEFINED__ */
