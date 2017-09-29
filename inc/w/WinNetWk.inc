' ########################################################################################
' Microsoft Windows
' File: WinNetWk.inc
' Contents: Standard WINNET Header File for WIN32
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%WINNETWK_INC = 1

#INCLUDE ONCE "winerror.inc"

'//
'// Network types
'//

#INCLUDE ONCE "wnnc.inc"

'//
'//  Network Resources.
'//

%RESOURCE_CONNECTED    = &H00000001???
%RESOURCE_PUBLICNET    = &H00000002???
%RESOURCE_GLOBALNET    = &H00000002???
%RESOURCE_REMEMBERED   = &H00000003???
'#if(WINVER >= 0x0400)
%RESOURCE_RECENT       = &H00000004???
%RESOURCE_CONTEXT      = &H00000005???
'#endif /* WINVER >= 0x0400 */

%RESOURCETYPE_ANY      = &H00000000???
%RESOURCETYPE_DISK     = &H00000001???
%RESOURCETYPE_PRINT    = &H00000002???
'#if(WINVER >= 0x0400)
%RESOURCETYPE_RESERVED = &H00000008???
'#endif /* WINVER >= 0x0400 */
%RESOURCETYPE_UNKNOWN  = &HFFFFFFFF???

%RESOURCEUSAGE_CONNECTABLE   = &H00000001???
%RESOURCEUSAGE_CONTAINER     = &H00000002???
'#if(WINVER >= 0x0400)
%RESOURCEUSAGE_NOLOCALDEVICE = &H00000004???
%RESOURCEUSAGE_SIBLING       = &H00000008???
%RESOURCEUSAGE_ATTACHED      = &H00000010???
%RESOURCEUSAGE_ALL           = %RESOURCEUSAGE_CONNECTABLE OR %RESOURCEUSAGE_CONTAINER OR %RESOURCEUSAGE_ATTACHED
'#endif /* WINVER >= 0x0400 */
%RESOURCEUSAGE_RESERVED      = &H80000000???

%RESOURCEDISPLAYTYPE_GENERIC      = &H00000000???
%RESOURCEDISPLAYTYPE_DOMAIN       = &H00000001???
%RESOURCEDISPLAYTYPE_SERVER       = &H00000002???
%RESOURCEDISPLAYTYPE_SHARE        = &H00000003???
%RESOURCEDISPLAYTYPE_FILE         = &H00000004???
%RESOURCEDISPLAYTYPE_GROUP        = &H00000005???
'#if(WINVER >= 0x0400)
%RESOURCEDISPLAYTYPE_NETWORK      = &H00000006???
%RESOURCEDISPLAYTYPE_ROOT         = &H00000007???
%RESOURCEDISPLAYTYPE_SHAREADMIN   = &H00000008???
%RESOURCEDISPLAYTYPE_DIRECTORY    = &H00000009???
'#endif /* WINVER >= 0x0400 */
%RESOURCEDISPLAYTYPE_TREE         = &H0000000A???
'#if(WINVER >= 0x0400)
%RESOURCEDISPLAYTYPE_NDSCONTAINER = &H0000000B???
'#endif /* WINVER >= 0x0400 */

' // Size = 32 bytes
TYPE NETRESOURCEA DWORD
   dwScope       AS DWORD        ' DWORD
   dwType        AS DWORD        ' DWORD
   dwDisplayType AS DWORD        ' DWORD
   dwUsage       AS DWORD        ' DWORD
   lpLocalName   AS ASCIIZ PTR   ' LPSTR
   lpRemoteName  AS ASCIIZ PTR   ' LPSTR
   lpComment     AS ASCIIZ PTR   ' LPSTR
   lpProvider    AS ASCIIZ PTR   ' LPSTR
END TYPE

' // Size = 32 bytes
TYPE NETRESOURCEW DWORD
   dwScope       AS DWORD          ' DWORD
   dwType        AS DWORD          ' DWORD
   dwDisplayType AS DWORD          ' DWORD
   dwUsage       AS DWORD          ' DWORD
   lpLocalName   AS WSTRINGZ PTR   ' LPWSTR
   lpRemoteName  AS WSTRINGZ PTR   ' LPWSTR
   lpComment     AS WSTRINGZ PTR   ' LPWSTR
   lpProvider    AS WSTRINGZ PTR   ' LPWSTR
END TYPE

#IF %DEF(%UNICODE)
   MACRO NETRESOURCE = NETRESOURCEW
#ELSE
   MACRO NETRESOURCE = NETRESOURCEA
#ENDIF

'//
'//  Network Connections.
'//

'#define NETPROPERTY_PERSISTENT       1
%NETPROPERTY_PERSISTENT = 1

%CONNECT_UPDATE_PROFILE = &H00000001???
%CONNECT_UPDATE_RECENT  = &H00000002???
%CONNECT_TEMPORARY      = &H00000004???
%CONNECT_INTERACTIVE    = &H00000008???
%CONNECT_PROMPT         = &H00000010???
%CONNECT_NEED_DRIVE     = &H00000020???
'#if(WINVER >= 0x0400)
%CONNECT_REFCOUNT       = &H00000040???
%CONNECT_REDIRECT       = &H00000080???
%CONNECT_LOCALDRIVE     = &H00000100???
%CONNECT_CURRENT_MEDIA  = &H00000200???
%CONNECT_DEFERRED       = &H00000400???
%CONNECT_RESERVED       = &HFF000000???
'#endif /* WINVER >= 0x0400 */
'#if(WINVER >= 0x0500)
%CONNECT_COMMANDLINE    = &H00000800???
%CONNECT_CMD_SAVECRED   = &H00001000???
'#endif /* WINVER >= 0x0500 */
'#if(WINVER >= 0x0600)
%CONNECT_CRED_RESET     = &H00002000???
'#endif /* WINVER >= 0x0600 */

DECLARE FUNCTION WNetAddConnectionA IMPORT "MPR.DLL" ALIAS "WNetAddConnectionA" ( _
   BYREF lpRemoteName AS ASCIIZ _                       ' __in LPCSTR lpRemoteName
 , BYREF lpPassword AS ASCIIZ _                         ' __in LPCSTR lpPassword
 , BYREF lpLocalName AS ASCIIZ _                        ' __in LPCSTR lpLocalName
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION WNetAddConnectionW IMPORT "MPR.DLL" ALIAS "WNetAddConnectionW" ( _
   BYREF lpRemoteName AS WSTRINGZ _                     ' __in LPCWSTR lpRemoteName
 , BYREF lpPassword AS WSTRINGZ _                       ' __in LPCWSTR lpPassword
 , BYREF lpLocalName AS WSTRINGZ _                      ' __in LPCWSTR lpLocalName
 ) AS DWORD                                             ' DWORD

#IF %DEF(%UNICODE)
   MACRO WNetAddConnection = WNetAddConnectionW
#ELSE
   MACRO WNetAddConnection = WNetAddConnectionA
#ENDIF

DECLARE FUNCTION WNetAddConnection2A IMPORT "MPR.DLL" ALIAS "WNetAddConnection2A" ( _
   BYREF lpNetResource AS NETRESOURCEA  _               ' __in LPNETRESOURCEA lpNetResource
 , BYREF lpPassword AS ASCIIZ _                         ' __in LPCSTR         lpPassword
 , BYREF lpUserName AS ASCIIZ _                         ' __in LPCSTR         lpUserName
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD          dwFlags
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION WNetAddConnection2W IMPORT "MPR.DLL" ALIAS "WNetAddConnection2W" ( _
   BYREF lpNetResource AS NETRESOURCEW _                ' __in LPNETRESOURCEW lpNetResource
 , BYREF lpPassword AS WSTRINGZ _                       ' __in LPCWSTR        lpPassword
 , BYREF lpUserName AS WSTRINGZ _                       ' __in LPCWSTR        lpUserName
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD          dwFlags
 ) AS DWORD                                             ' DWORD

#IF %DEF(%UNICODE)
   MACRO WNetAddConnection2 = WNetAddConnection2W
#ELSE
   MACRO WNetAddConnection2 = WNetAddConnection2A
#ENDIF

DECLARE FUNCTION WNetAddConnection3A IMPORT "MPR.DLL" ALIAS "WNetAddConnection3A" ( _
   BYVAL hwndOwner AS DWORD _                           ' __in HWND           hwndOwner
 , BYREF lpNetResource AS NETRESOURCEA _                ' __in LPNETRESOURCEA lpNetResource
 , BYREF lpPassword AS ASCIIZ _                         ' __in LPCSTR         lpPassword
 , BYREF lpUserName AS ASCIIZ _                         ' __in LPCSTR         lpUserName
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD          dwFlags
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION WNetAddConnection3W IMPORT "MPR.DLL" ALIAS "WNetAddConnection3W" ( _
   BYVAL hwndOwner AS DWORD _                           ' __in HWND           hwndOwner
 , BYREF lpNetResource AS NETRESOURCEW _                ' __in LPNETRESOURCEW lpNetResource
 , BYREF lpPassword AS WSTRINGZ _                       ' __in LPCWSTR        lpPassword
 , BYREF lpUserName AS WSTRINGZ _                       ' __in LPCWSTR        lpUserName
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD          dwFlags
 ) AS DWORD                                             ' DWORD

#IF %DEF(%UNICODE)
   MACRO WNetAddConnection3 = WNetAddConnection3W
#ELSE
   MACRO WNetAddConnection3 = WNetAddConnection3A
#ENDIF

DECLARE FUNCTION WNetCancelConnectionA IMPORT "MPR.DLL" ALIAS "WNetCancelConnectionA" ( _
   BYREF lpName AS ASCIIZ _                             ' __in LPCSTR lpName
 , BYVAL fForce AS LONG _                               ' __in BOOL   fForce
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION WNetCancelConnectionW IMPORT "MPR.DLL" ALIAS "WNetCancelConnectionW" ( _
   BYREF lpName AS WSTRINGZ _                           ' __in LPCWSTR lpName
 , BYVAL fForce AS LONG _                               ' __in BOOL    fForce
 ) AS DWORD                                             ' DWORD

#IF %DEF(%UNICODE)
   MACRO WNetCancelConnection = WNetCancelConnectionW
#ELSE
   MACRO WNetCancelConnection = WNetCancelConnectionA
#ENDIF

DECLARE FUNCTION WNetCancelConnection2A IMPORT "MPR.DLL" ALIAS "WNetCancelConnection2A" ( _
   BYREF lpName AS ASCIIZ _                             ' __in LPCSTR lpName
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD  dwFlags
 , BYVAL fForce AS LONG _                               ' __in BOOL   fForce
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION WNetCancelConnection2W IMPORT "MPR.DLL" ALIAS "WNetCancelConnection2W" ( _
   BYREF lpName AS WSTRINGZ _                           ' __in LPCWSTR lpName
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD   dwFlags
 , BYVAL fForce AS LONG _                               ' __in BOOL    fForce
 ) AS DWORD                                             ' DWORD

#IF %DEF(%UNICODE)
   MACRO WNetCancelConnection2 = WNetCancelConnection2W
#ELSE
   MACRO WNetCancelConnection2 = WNetCancelConnection2A
#ENDIF

DECLARE FUNCTION WNetGetConnectionA IMPORT "MPR.DLL" ALIAS "WNetGetConnectionA" ( _
   BYREF lpLocalName AS ASCIIZ _                        ' __in LPCSTR lpLocalName
 , BYREF lpRemoteName AS ASCIIZ _                       ' __out LPSTR lpRemoteName
 , BYREF lpnLength AS DWORD _                           ' __in_out LPDWORD lpnLength
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION WNetGetConnectionW IMPORT "MPR.DLL" ALIAS "WNetGetConnectionW" ( _
   BYREF lpLocalName AS WSTRINGZ _                      ' __in LPCWSTR lpLocalName
 , BYREF lpRemoteName AS WSTRINGZ _                     ' __out LPWSTR lpRemoteName
 , BYREF lpnLength AS DWORD _                           ' __in_out LPDWORD lpnLength
 ) AS DWORD                                             ' DWORD

#IF %DEF(%UNICODE)
   MACRO WNetGetConnection = WNetGetConnectionW
#ELSE
   MACRO WNetGetConnection = WNetGetConnectionA
#ENDIF

'#if (_WIN32_WINNT >= _WIN32_WINNT_LONGHORN)
DECLARE FUNCTION WNetRestoreSingleConnectionW IMPORT "MPR.DLL" ALIAS "WNetRestoreSingleConnectionW" ( _
   BYVAL hwndParent AS DWORD _                          ' __in_opt HWND    hwndParent
 , BYREF lpDevice AS WSTRINGZ _                         ' __in     LPCWSTR lpDevice
 , BYVAL fUseUI AS LONG _                               ' __in     BOOL    fUseUI
 ) AS DWORD                                             ' DWORD

MACRO WNetRestoreSingleConnection = WNetRestoreSingleConnectionW
'#else
' Not supported on Windows Vista and later.
DECLARE FUNCTION WNetRestoreConnectionW IMPORT "MPR.DLL" ALIAS "WNetRestoreConnectionW" ( _
   BYVAL hwndParent AS DWORD _                          ' __in HWND    hwndParent
 , BYREF lpDevice AS WSTRINGZ _                         ' __in LPCWSTR lpDevice
 ) AS DWORD                                             ' DWORD

MACRO WNetRestoreConnection = WNetRestoreConnectionW
'#endif

'#if(WINVER >= 0x0400)
DECLARE FUNCTION WNetUseConnectionA IMPORT "MPR.DLL" ALIAS "WNetUseConnectionA" ( _
   BYVAL hwndOwner AS DWORD _                           ' __in HWND           hwndOwner
 , BYREF lpNetResource AS NETRESOURCEA _                ' __in LPNETRESOURCEA lpNetResource
 , BYREF lpPassword AS ASCIIZ _                         ' __in LPCSTR         lpPassword
 , BYREF lpUserID AS ASCIIZ _                           ' __in LPCSTR         lpUserID
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD          dwFlags
 , BYREF lpAccessName AS ASCIIZ _                       ' __out LPSTR         lpAccessName
 , BYREF lpBufferSize AS DWORD _                        ' __in_out LPDWORD    lpBufferSize
 , BYREF lpResult AS DWORD _                            ' __out LPDWORD       lpResult
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION WNetUseConnectionW IMPORT "MPR.DLL" ALIAS "WNetUseConnectionW" ( _
   BYVAL hwndOwner AS DWORD _                           ' __in HWND           hwndOwner
 , BYREF lpNetResource AS NETRESOURCEW _                ' __in LPNETRESOURCEW lpNetResource
 , BYREF lpPassword AS WSTRINGZ _                       ' __in LPCWSTR        lpPassword
 , BYREF lpUserID AS WSTRINGZ _                         ' __in LPCWSTR        lpUserID
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD          dwFlags
 , BYREF lpAccessName AS WSTRINGZ _                     ' __out LPWSTR        lpAccessName
 , BYREF lpBufferSize AS DWORD _                        ' __in_out LPDWORD    lpBufferSize
 , BYREF lpResult AS DWORD _                            ' __out LPDWORD       lpResult
 ) AS DWORD                                             ' DWORD

#IF %DEF(%UNICODE)
   MACRO WNetUseConnection = WNetUseConnectionW
#ELSE
   MACRO WNetUseConnection = WNetUseConnectionA
#ENDIF
'#endif /* WINVER >= 0x0400 */

'//
'//  Network Connection Dialogs.
'//

DECLARE FUNCTION WNetConnectionDialog IMPORT "MPR.DLL" ALIAS "WNetConnectionDialog" ( _
   BYVAL hwnd AS DWORD  _                               ' __in HWND  hwnd
 , BYVAL dwType AS DWORD _                              ' __in DWORD dwType
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION WNetDisconnectDialog IMPORT "MPR.DLL" ALIAS "WNetDisconnectDialog" ( _
   BYVAL hwnd AS DWORD _                                ' __in_opt HWND  hwnd
 , BYVAL dwType AS DWORD _                              ' __in     DWORD dwType
 ) AS DWORD                                             ' DWORD

'#if(WINVER >= 0x0400)

' // Size = 20 bytes
TYPE CONNECTDLGSTRUCTA DWORD
   cbStructure AS DWORD             ' DWORD // size of this structure in bytes
   hwndOwner   AS DWORD             ' HWND  // owner window for the dialog (HWND)
   lpConnRes   AS NETRESOURCE PTR   ' LPNETRESOURCEA // requested resource info
   dwFlags     AS DWORD             ' DWORD // flags
   dwDevNum    AS DWORD             ' DWORD //number of devices connected to
END TYPE

' // Size = 20 bytes
TYPE CONNECTDLGSTRUCTW DWORD
   cbStructure AS DWORD             ' DWORD // size of this structure in bytes
   hwndOwner   AS DWORD             ' HWND  // owner window for the dialog (HWND)
   lpConnRes   AS NETRESOURCEW PTR  ' LPNETRESOURCEW // requested resource info
   dwFlags     AS DWORD             ' DWORD // flags
   dwDevNum    AS DWORD             ' DWORD //number of devices connected to
END TYPE

#IF %DEF(%UNICODE)
   MACRO CONNECTDLGSTRUCT = CONNECTDLGSTRUCTW
#ELSE
   MACRO CONNECTDLGSTRUCT = CONNECTDLGSTRUCTA
#ENDIF

%CONNDLG_RO_PATH        = &H00000001???   ' Resource path should be read-only
%CONNDLG_CONN_POINT     = &H00000002???   ' Netware-style movable connection point
%CONNDLG_USE_MRU        = &H00000004???   ' Use MRU combobox
%CONNDLG_HIDE_BOX       = &H00000008???   ' Hide persistent connect checkbox

'/*
' * NOTE:  Set at most ONE of the below flags.  If neither flag is set,
' *        then the persistence is set to whatever the user chose during
' *        a previous connection
' */

%CONNDLG_PERSIST        = &H00000010???   ' Force persistent connection
%CONNDLG_NOT_PERSIST    = &H00000020???   ' Force connection NOT persistent

DECLARE FUNCTION WNetConnectionDialog1A IMPORT "MPR.DLL" ALIAS "WNetConnectionDialog1A" ( _
   BYREF lpConnDlgStruct AS CONNECTDLGSTRUCTA _         ' __in_out LPCONNECTDLGSTRUCTA lpConnDlgStruct
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION WNetConnectionDialog1W IMPORT "MPR.DLL" ALIAS "WNetConnectionDialog1W" ( _
   BYREF lpConnDlgStruct AS CONNECTDLGSTRUCTW _         ' __in_out LPCONNECTDLGSTRUCTW lpConnDlgStruct
 ) AS DWORD                                             ' DWORD

#IF %DEF(%UNICODE)
   MACRO WNetConnectionDialog1 = WNetConnectionDialog1W
#ELSE
   MACRO WNetConnectionDialog1 = WNetConnectionDialog1A
#ENDIF

' // Size = 20 bytes
TYPE DISCDLGSTRUCTA DWORD
   cbStructure  AS DWORD        ' DWORD // size of this structure in bytes
   hwndOwner    AS DWORD        ' HWND  // owner window for the dialog (HWND)
   lpLocalName  AS ASCIIZ PTR   ' LPSTR // local device name
   lpRemoteName AS ASCIIZ PTR   ' LPSTR // network resource name
   dwFlags      AS DWORD        ' DWORD // flags
END TYPE

' // Size = 20 bytes
TYPE DISCDLGSTRUCTW DWORD
   cbStructure  AS DWORD          ' DWORD  // size of this structure in bytes
   hwndOwner    AS DWORD          ' HWND   // owner window for the dialog (HWND)
   lpLocalName  AS WSTRINGZ PTR   ' LPWSTR // local device name
   lpRemoteName AS WSTRINGZ PTR   ' LPWSTR // network resource name
   dwFlags      AS DWORD          ' DWORD  // flags
END TYPE

#IF %DEF(%UNICODE)
   MACRO DISCDLGSTRUCT = DISCDLGSTRUCTW
#ELSE
   MACRO DISCDLGSTRUCT = DISCDLGSTRUCTA
#ENDIF

%DISC_UPDATE_PROFILE = &H00000001???
%DISC_NO_FORCE       = &H00000040???

DECLARE FUNCTION WNetDisconnectDialog1A IMPORT "MPR.DLL" ALIAS "WNetDisconnectDialog1A" ( _
   BYREF lpConnDlgStruct AS DISCDLGSTRUCTA _            ' __in LPDISCDLGSTRUCTA lpConnDlgStruct
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION WNetDisconnectDialog1W IMPORT "MPR.DLL" ALIAS "WNetDisconnectDialog1W" ( _
   BYREF lpConnDlgStruct AS DISCDLGSTRUCTW _            ' __in LPDISCDLGSTRUCTW lpConnDlgStruct
 ) AS DWORD                                             ' DWORD

#IF %DEF(%UNICODE)
   MACRO WNetDisconnectDialog1 = WNetDisconnectDialog1W
#ELSE
   MACRO WNetDisconnectDialog1 = WNetDisconnectDialog1A
#ENDIF
'#endif /* WINVER >= 0x0400 */

'//
'//  Network Browsing.
'//

DECLARE FUNCTION WNetOpenEnumA IMPORT "MPR.DLL" ALIAS "WNetOpenEnumA" ( _
   BYVAL dwScope AS DWORD _                             ' __in DWORD          dwScope
 , BYVAL dwType AS DWORD _                              ' __in DWORD          dwType
 , BYVAL dwUsage AS DWORD _                             ' __in DWORD          dwUsage
 , BYREF lpNetResource AS NETRESOURCEA _                ' __in LPNETRESOURCEA lpNetResource
 , BYREF lphEnum AS DWORD _                             ' __out LPHANDLE      lphEnum
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION WNetOpenEnumW IMPORT "MPR.DLL" ALIAS "WNetOpenEnumW" ( _
   BYVAL dwScope AS DWORD _                             ' __in DWORD           dwScope
 , BYVAL dwType AS DWORD _                              ' __in DWORD           dwType
 , BYVAL dwUsage AS DWORD _                             ' __in DWORD           dwUsage
 , BYREF lpNetResource AS NETRESOURCEW _                ' __in LPNETRESOURCEW  lpNetResource
 , BYREF lphEnum AS DWORD _                             ' __out LPHANDLE       lphEnum
 ) AS DWORD                                             ' DWORD

#IF %DEF(%UNICODE)
   MACRO WNetOpenEnum = WNetOpenEnumW
#ELSE
   MACRO WNetOpenEnum = WNetOpenEnumA
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION WNetEnumResourceA LIB "Mpr.dll" ALIAS "WNetEnumResourceA" ( _
    BYVAL hEnum    AS DWORD, _  ' HANDLE
    lpcCount       AS DWORD, _
    BYVAL lpBuffer AS DWORD, _  ' LPVOID
    lpBufferSize   AS DWORD _
    ) AS DWORD
#ELSE
DECLARE FUNCTION WNetEnumResourceA IMPORT "MPR.DLL" ALIAS "WNetEnumResourceA" ( _
   BYVAL hEnum AS DWORD _                               ' __in HANDLE  hEnum
 , BYREF lpcCount AS DWORD _                            ' __in_out LPDWORD lpcCount
 , BYREF lpBuffer AS ANY _                              ' __out LPVOID  lpBuffer
 , BYREF lpBufferSize AS DWORD _                        ' __in_out LPDWORD lpBufferSize
 ) AS DWORD                                             ' DWORD
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION WNetEnumResourceW LIB "Mpr.dll" ALIAS "WNetEnumResourceW" ( _
    BYVAL hEnum    AS DWORD, _  ' HANDLE
    lpcCount       AS DWORD, _
    BYVAL lpBuffer AS DWORD, _  ' LPVOID
    lpBufferSize   AS DWORD _
    ) AS DWORD
#ELSE
DECLARE FUNCTION WNetEnumResourceW IMPORT "MPR.DLL" ALIAS "WNetEnumResourceW" ( _
   BYVAL hEnum AS DWORD _                               ' __in HANDLE  hEnum
 , BYREF lpcCount AS DWORD _                            ' __in_out LPDWORD lpcCount
 , BYREF lpBuffer AS ANY _                              ' __out LPVOID  lpBuffer
 , BYREF lpBufferSize AS DWORD _                        ' __in_out LPDWORD lpBufferSize
 ) AS DWORD                                             ' DWORD
#ENDIF

#IF %DEF(%UNICODE)
   MACRO WNetEnumResource = WNetEnumResourceW
#ELSE
   MACRO WNetEnumResource = WNetEnumResourceA
#ENDIF

DECLARE FUNCTION WNetCloseEnum IMPORT "MPR.DLL" ALIAS "WNetCloseEnum" ( _
   BYVAL hEnum AS DWORD _                               ' __in HANDLE   hEnum
 ) AS DWORD                                             ' DWORD

'#if(WINVER >= 0x0400)

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION WNetGetResourceParentA LIB "Mpr.dll" _
    ALIAS "WNetGetResourceParentA" ( _
    lpNetResource  AS NETRESOURCEA, _
    BYVAL lpBuffer AS DWORD, _   ' LPVOID
    lpcbBuffer     AS DWORD _
    ) AS DWORD
#ELSE
DECLARE FUNCTION WNetGetResourceParentA IMPORT "MPR.DLL" ALIAS "WNetGetResourceParentA" ( _
   BYREF lpNetResource AS NETRESOURCEA _                ' __in LPNETRESOURCEA lpNetResource
 , BYREF lpBuffer AS ANY _                              ' __out LPVOID lpBuffer
 , BYREF lpcbBuffer AS DWORD _                          ' __in_out LPDWORD lpcbBuffer
 ) AS DWORD                                             ' DWORD
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION WNetGetResourceParentW LIB "Mpr.dll" _
    ALIAS "WNetGetResourceParentW" ( _
    lpNetResource  AS NETRESOURCEW, _
    BYVAL lpBuffer AS DWORD, _   ' LPVOID
    lpcbBuffer     AS DWORD _
    ) AS DWORD
#ELSE
DECLARE FUNCTION WNetGetResourceParentW IMPORT "MPR.DLL" ALIAS "WNetGetResourceParentW" ( _
   BYREF lpNetResource AS NETRESOURCEW _                ' __in LPNETRESOURCEW lpNetResource
 , BYREF lpBuffer AS ANY _                              ' __out LPVOID lpBuffer
 , BYREF lpcbBuffer AS DWORD _                          ' __in_out LPDWORD lpcbBuffer
 ) AS DWORD                                             ' DWORD
#ENDIF

#IF %DEF(%UNICODE)
   MACRO WNetGetResourceParent = WNetGetResourceParentW
#ELSE
   MACRO WNetGetResourceParent = WNetGetResourceParentA
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION WNetGetResourceInformationA LIB "Mpr.dll" _
    ALIAS "WNetGetResourceInformationA" ( _
    lpNetResource  AS NETRESOURCEA, _
    BYVAL lpBuffer AS DWORD, _   ' LPVOID
    lpcbBuffer     AS DWORD, _
    lplpSystem     AS ANY _      ' LPSTR *
    ) AS DWORD
#ELSE
DECLARE FUNCTION WNetGetResourceInformationA IMPORT "MPR.DLL" ALIAS "WNetGetResourceInformationA" ( _
   BYREF lpNetResource AS NETRESOURCEA _                ' __in LPNETRESOURCEA  lpNetResource
 , BYREF lpBuffer AS ANY _                              ' __out LPVOID         lpBuffer
 , BYREF lpcbBuffer AS DWORD _                          ' __in_out LPDWORD     lpcbBuffer
 , BYREF lplpSystem AS ANY _                            ' __out LPSTR         *lplpSystem
 ) AS DWORD                                             ' DWORD
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION WNetGetResourceInformationW LIB "Mpr.dll" _
    ALIAS "WNetGetResourceInformationW" ( _
    lpNetResource  AS NETRESOURCEW, _
    BYVAL lpBuffer AS DWORD, _   ' LPVOID
    lpcbBuffer     AS DWORD, _
    lplpSystem     AS ANY _      ' LPSTR *
    ) AS DWORD
#ELSE
DECLARE FUNCTION WNetGetResourceInformationW IMPORT "MPR.DLL" ALIAS "WNetGetResourceInformationW" ( _
   BYREF lpNetResource AS NETRESOURCEW _                ' __in LPNETRESOURCEW   lpNetResource
 , BYREF lpBuffer AS ANY _                              ' __out LPVOID          lpBuffer
 , BYREF lpcbBuffer AS DWORD _                          ' __in_out LPDWORD      lpcbBuffer
 , BYREF lplpSystem AS ANY _                            ' __out LPWSTR         *lplpSystem
 ) AS DWORD                                             ' DWORD
#ENDIF

#IF %DEF(%UNICODE)
   MACRO WNetGetResourceInformation = WNetGetResourceInformationW
#ELSE
   MACRO WNetGetResourceInformation = WNetGetResourceInformationA
#ENDIF

'#endif /* WINVER >= 0x0400 */

'//
'//  Universal Naming.
'//

%UNIVERSAL_NAME_INFO_LEVEL = &H00000001???
%REMOTE_NAME_INFO_LEVEL    = &H00000002???

' // Size = 4 bytes
TYPE UNIVERSAL_NAME_INFOA DWORD
   lpUniversalName AS ASCIIZ PTR   ' LPSTR
END TYPE

' // Size = 4 bytes
TYPE UNIVERSAL_NAME_INFOW DWORD
   lpUniversalName AS WSTRINGZ PTR   ' LPWSTR
END TYPE

#IF %DEF(%UNICODE)
   MACRO UNIVERSAL_NAME_INFO = UNIVERSAL_NAME_INFOW
#ELSE
   MACRO UNIVERSAL_NAME_INFO = UNIVERSAL_NAME_INFOA
#ENDIF

' // Size = 12 bytes
TYPE REMOTE_NAME_INFOA DWORD
   lpUniversalName  AS ASCIIZ PTR   ' LPSTR
   lpConnectionName AS ASCIIZ PTR   ' LPSTR
   lpRemainingPath  AS ASCIIZ PTR   ' LPSTR
END TYPE

' // Size = 12 bytes
TYPE REMOTE_NAME_INFOW DWORD
   lpUniversalName  AS WSTRINGZ PTR   ' LPWSTR
   lpConnectionName AS WSTRINGZ PTR   ' LPWSTR
   lpRemainingPath  AS WSTRINGZ PTR   ' LPWSTR
END TYPE

#IF %DEF(%UNICODE)
   MACRO REMOTE_NAME_INFO = REMOTE_NAME_INFOW
#ELSE
   MACRO REMOTE_NAME_INFO = REMOTE_NAME_INFOA
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION WNetGetUniversalNameA LIB "Mpr.dll" _
    ALIAS "WNetGetUniversalNameA" ( _
    lpLocalPath       AS ASCIIZ, _
    BYVAL dwInfoLevel AS DWORD, _
    BYVAL lpBuffer    AS DWORD, _   ' LPVOID
    lpBufferSize      AS DWORD _
    ) AS DWORD
#ELSE
DECLARE FUNCTION WNetGetUniversalNameA IMPORT "MPR.DLL" ALIAS "WNetGetUniversalNameA" ( _
   BYREF lpLocalPath AS ASCIIZ _                        ' __in LPCSTR      lpLocalPath
 , BYVAL dwInfoLevel AS DWORD _                         ' __in DWORD       dwInfoLevel
 , BYREF lpBuffer AS ANY _                              ' __out LPVOID     lpBuffer
 , BYREF lpBufferSize AS DWORD _                        ' __in_out LPDWORD lpBufferSize
 ) AS DWORD                                             ' DWORD
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION WNetGetUniversalNameW LIB "Mpr.dll" _
    ALIAS "WNetGetUniversalNameW" ( _
    lpLocalPath       AS WSTRINGZ, _
    BYVAL dwInfoLevel AS DWORD, _
    BYVAL lpBuffer    AS DWORD, _   ' LPVOID
    lpBufferSize      AS DWORD _
    ) AS DWORD
#ELSE
DECLARE FUNCTION WNetGetUniversalNameW IMPORT "MPR.DLL" ALIAS "WNetGetUniversalNameW" ( _
   BYREF lpLocalPath AS WSTRINGZ _                      ' __in LPCWSTR     lpLocalPath
 , BYVAL dwInfoLevel AS DWORD _                         ' __in DWORD       dwInfoLevel
 , BYREF lpBuffer AS ANY _                              ' __out LPVOID     lpBuffer
 , BYREF lpBufferSize AS DWORD _                        ' __in_out LPDWORD lpBufferSize
 ) AS DWORD                                             ' DWORD
#ENDIF

#IF %DEF(%UNICODE)
   MACRO WNetGetUniversalName = WNetGetUniversalNameW
#ELSE
   MACRO WNetGetUniversalName = WNetGetUniversalNameA
#ENDIF

'//
'//  Authentication and Logon/Logoff.
'//

DECLARE FUNCTION WNetGetUserA IMPORT "MPR.DLL" ALIAS "WNetGetUserA" ( _
   BYREF lpName AS ASCIIZ _                             ' __in LPCSTR      lpName
 , BYREF lpUserName AS ASCIIZ _                         ' __out LPSTR      lpUserName
 , BYREF lpnLength AS DWORD _                           ' __in_out LPDWORD lpnLength
 ) AS DWORD                                             ' DWORD

'//
'//  Authentication and Logon/Logoff.
'//

DECLARE FUNCTION WNetGetUserW IMPORT "MPR.DLL" ALIAS "WNetGetUserW" ( _
   BYREF lpName AS WSTRINGZ _                           ' __in LPCWSTR     lpName
 , BYREF lpUserName AS WSTRINGZ _                       ' __out LPWSTR     lpUserName
 , BYREF lpnLength AS DWORD _                           ' __in_out LPDWORD lpnLength
 ) AS DWORD                                             ' DWORD

#IF %DEF(%UNICODE)
   MACRO WNetGetUser = WNetGetUserW
#ELSE
   MACRO WNetGetUser = WNetGetUserA
#ENDIF

'//
'// Other.
'//

'#if(WINVER >= 0x0400)
%WNFMT_MULTILINE    = &H01
%WNFMT_ABBREVIATED  = &H02
%WNFMT_INENUM       = &H10
%WNFMT_CONNECTION   = &H20
'#endif /* WINVER >= 0x0400 */

'#if(WINVER >= 0x0400)

DECLARE FUNCTION WNetGetProviderNameA IMPORT "MPR.DLL" ALIAS "WNetGetProviderNameA" ( _
   BYVAL dwNetType AS DWORD _                           ' __in DWORD       dwNetType
 , BYREF lpProviderName AS ASCIIZ _                     ' __out LPSTR      lpProviderName
 , BYREF lpBufferSize AS DWORD _                        ' __in_out LPDWORD lpBufferSize
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION WNetGetProviderNameW IMPORT "MPR.DLL" ALIAS "WNetGetProviderNameW" ( _
   BYVAL dwNetType AS DWORD _                           ' __in DWORD       dwNetType
 , BYREF lpProviderName AS WSTRINGZ _                   ' __out LPWSTR     lpProviderName
 , BYREF lpBufferSize AS DWORD _                        ' __in_out LPDWORD lpBufferSize
 ) AS DWORD                                             ' DWORD

#IF %DEF(%UNICODE)
   MACRO WNetGetProviderName = WNetGetProviderNameW
#ELSE
   MACRO WNetGetProviderName = WNetGetProviderNameA
#ENDIF

' // Size = 32 bytes
TYPE NETINFOSTRUCT DWORD
   cbStructure       AS DWORD   ' DWORD
   dwProviderVersion AS DWORD   ' DWORD
   dwStatus          AS DWORD   ' DWORD
   dwCharacteristics AS DWORD   ' DWORD
   dwHandle          AS DWORD   ' ULONG_PTR
   wNetType          AS WORD    ' WORD
   dwPrinters        AS DWORD   ' DWORD
   dwDrives          AS DWORD   ' DWORD
END TYPE

%NETINFO_DLL16      = &H00000001???  ' Provider running as 16 bit Winnet Driver
%NETINFO_DISKRED    = &H00000004???  ' Provider requires disk redirections to connect
%NETINFO_PRINTERRED = &H00000008???  ' Provider requires printer redirections to connect

DECLARE FUNCTION WNetGetNetworkInformationA IMPORT "MPR.DLL" ALIAS "WNetGetNetworkInformationA" ( _
   BYREF lpProvider AS ASCIIZ _                         ' __in LPCSTR           lpProvider
 , BYREF lpNetInfoStruct AS NETINFOSTRUCT _             ' __out LPNETINFOSTRUCT lpNetInfoStruct
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION WNetGetNetworkInformationW IMPORT "MPR.DLL" ALIAS "WNetGetNetworkInformationW" ( _
   BYREF lpProvider AS WSTRINGZ _                       ' __in LPCWSTR          lpProvider
 , BYREF lpNetInfoStruct AS NETINFOSTRUCT _             ' __out LPNETINFOSTRUCT lpNetInfoStruct
 ) AS DWORD                                             ' DWORD

#IF %DEF(%UNICODE)
   MACRO WNetGetNetworkInformation = WNetGetNetworkInformationW
#ELSE
   MACRO WNetGetNetworkInformation = WNetGetNetworkInformationA
#ENDIF

'#endif /* WINVER >= 0x0400 */

' *********************** BEGIN NOT IN WINDOWS VISTA SDK ************************

'//
'//  User Profiles.
'//

'typedef UINT (FAR PASCAL *PFNGETPROFILEPATHA) (
'    LPCSTR    pszUsername,
'    LPSTR     pszBuffer,
'    UINT        cbBuffer
'    );

'typedef UINT (FAR PASCAL *PFNGETPROFILEPATHW) (
'    LPCWSTR    pszUsername,
'    LPWSTR     pszBuffer,
'    UINT        cbBuffer
'    );

'typedef UINT (FAR PASCAL *PFNRECONCILEPROFILEA) (
'    LPCSTR    pszCentralFile,
'    LPCSTR    pszLocalFile,
'    DWORD       dwFlags
'    );

'typedef UINT (FAR PASCAL *PFNRECONCILEPROFILEW) (
'    LPCWSTR    pszCentralFile,
'    LPCWSTR    pszLocalFile,
'    DWORD       dwFlags
'    );

%RP_LOGON   = &H01   ' if set, do for logon, else for logoff
%RP_INIFILE = &H02   ' if set, reconcile .INI file, else reg. hive

'//
'//  Policies.
'//

'typedef BOOL (FAR PASCAL *PFNPROCESSPOLICIESA) (
'    HWND        hwnd,
'    LPCSTR    pszPath,
'    LPCSTR    pszUsername,
'    LPCSTR    pszComputerName,
'    DWORD       dwFlags
'    );

'typedef BOOL (FAR PASCAL *PFNPROCESSPOLICIESW) (
'    HWND        hwnd,
'    LPCWSTR    pszPath,
'    LPCWSTR    pszUsername,
'    LPCWSTR    pszComputerName,
'    DWORD       dwFlags
'    );

%PP_DISPLAYERRORS = &H01  ' if set, display error messages, else fail silently if error
'#endif /* WINVER >= 0x0400 */

' ************************* END NOT IN WINDOWS VISTA SDK ************************

'//
'//  Error handling.
'//

DECLARE FUNCTION WNetGetLastErrorA IMPORT "MPR.DLL" ALIAS "WNetGetLastErrorA" ( _
   BYREF lpError AS DWORD _                             ' __out LPDWORD lpError
 , BYREF lpErrorBuf AS ASCIIZ _                         ' __out LPSTR   lpErrorBuf
 , BYVAL nErrorBufSize AS DWORD _                       ' __in DWORD    nErrorBufSize
 , BYREF lpNameBuf AS ASCIIZ _                          ' __out LPSTR   lpNameBuf
 , BYVAL nNameBufSize AS DWORD _                        ' __in DWORD    nNameBufSize
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION WNetGetLastErrorW IMPORT "MPR.DLL" ALIAS "WNetGetLastErrorW" ( _
   BYREF lpError AS DWORD _                             ' __out LPDWORD lpError
 , BYREF lpErrorBuf AS WSTRINGZ _                       ' __out LPWSTR  lpErrorBuf
 , BYVAL nErrorBufSize AS DWORD _                       ' __in DWORD    nErrorBufSize
 , BYREF lpNameBuf AS WSTRINGZ _                        ' __out LPWSTR  lpNameBuf
 , BYVAL nNameBufSize AS DWORD _                        ' __in DWORD    nNameBufSize
 ) AS DWORD                                             ' DWORD

#IF %DEF(%UNICODE)
   MACRO WNetGetLastError = WNetGetLastErrorW
#ELSE
   MACRO WNetGetLastError = WNetGetLastErrorA
#ENDIF

'//
'//  STATUS CODES
'//

'// General

%WN_SUCCESS          = %NO_ERROR
%WN_NO_ERROR         = %NO_ERROR
%WN_NOT_SUPPORTED    = %ERROR_NOT_SUPPORTED
%WN_CANCEL           = %ERROR_CANCELLED
%WN_RETRY            = %ERROR_RETRY
%WN_NET_ERROR        = %ERROR_UNEXP_NET_ERR
%WN_MORE_DATA        = %ERROR_MORE_DATA
%WN_BAD_POINTER      = %ERROR_INVALID_ADDRESS
%WN_BAD_VALUE        = %ERROR_INVALID_PARAMETER
%WN_BAD_USER         = %ERROR_BAD_USERNAME
%WN_BAD_PASSWORD     = %ERROR_INVALID_PASSWORD
%WN_ACCESS_DENIED    = %ERROR_ACCESS_DENIED
%WN_FUNCTION_BUSY    = %ERROR_BUSY
%WN_WINDOWS_ERROR    = %ERROR_UNEXP_NET_ERR
%WN_OUT_OF_MEMORY    = %ERROR_NOT_ENOUGH_MEMORY
%WN_NO_NETWORK       = %ERROR_NO_NETWORK
%WN_EXTENDED_ERROR   = %ERROR_EXTENDED_ERROR
%WN_BAD_LEVEL        = %ERROR_INVALID_LEVEL
%WN_BAD_HANDLE       = %ERROR_INVALID_HANDLE
'#if(WINVER >= 0x0400)
%WN_NOT_INITIALIZING = %ERROR_ALREADY_INITIALIZED
%WN_NO_MORE_DEVICES  = %ERROR_NO_MORE_DEVICES
'#endif /* WINVER >= 0x0400 */

'// Connection

%WN_NOT_CONNECTED        = %ERROR_NOT_CONNECTED
%WN_OPEN_FILES           = %ERROR_OPEN_FILES
%WN_DEVICE_IN_USE        = %ERROR_DEVICE_IN_USE
%WN_BAD_NETNAME          = %ERROR_BAD_NET_NAME
%WN_BAD_LOCALNAME        = %ERROR_BAD_DEVICE
%WN_ALREADY_CONNECTED    = %ERROR_ALREADY_ASSIGNED
%WN_DEVICE_ERROR         = %ERROR_GEN_FAILURE
%WN_CONNECTION_CLOSED    = %ERROR_CONNECTION_UNAVAIL
%WN_NO_NET_OR_BAD_PATH   = %ERROR_NO_NET_OR_BAD_PATH
%WN_BAD_PROVIDER         = %ERROR_BAD_PROVIDER
%WN_CANNOT_OPEN_PROFILE  = %ERROR_CANNOT_OPEN_PROFILE
%WN_BAD_PROFILE          = %ERROR_BAD_PROFILE
%WN_BAD_DEV_TYPE         = %ERROR_BAD_DEV_TYPE
%WN_DEVICE_ALREADY_REMEMBERED = %ERROR_DEVICE_ALREADY_REMEMBERED
%WN_CONNECTED_OTHER_PASSWORD  = %ERROR_CONNECTED_OTHER_PASSWORD
'#if(WINVER >= 0x0501)
%WN_CONNECTED_OTHER_PASSWORD_DEFAULT = %ERROR_CONNECTED_OTHER_PASSWORD_DEFAULT
'#endif /* WINVER >= 0x0501 */

'// Enumeration

%WN_NO_MORE_ENTRIES     = %ERROR_NO_MORE_ITEMS
%WN_NOT_CONTAINER       = %ERROR_NOT_CONTAINER

'#if(WINVER >= 0x0400)
'// Authentication

%WN_NOT_AUTHENTICATED   = %ERROR_NOT_AUTHENTICATED
%WN_NOT_LOGGED_ON       = %ERROR_NOT_LOGGED_ON
%WN_NOT_VALIDATED       = %ERROR_NO_LOGON_SERVERS
'#endif /* WINVER >= 0x0400 */


'//
'//  For Shell
'//

'#if(WINVER >= 0x0400)

' // Size = 20 bytes
TYPE NETCONNECTINFOSTRUCT DWORD
   cbStructure   AS DWORD
   dwFlags       AS DWORD
   dwSpeed       AS DWORD
   dwDelay       AS DWORD
   dwOptDataSize AS DWORD
END TYPE

%WNCON_FORNETCARD = &H00000001???
%WNCON_NOTROUTED  = &H00000002???
%WNCON_SLOWLINK   = &H00000004???
%WNCON_DYNAMIC    = &H00000008???

DECLARE FUNCTION MultinetGetConnectionPerformanceA IMPORT "MPR.DLL" ALIAS "MultinetGetConnectionPerformanceA" ( _
   BYREF lpNetResource AS NETRESOURCEA _                  ' __in LPNETRESOURCEA lpNetResource
 , BYREF lpNetConnectInfoStruct AS NETCONNECTINFOSTRUCT _ ' __out LPNETCONNECTINFOSTRUCT lpNetConnectInfoStruct
 ) AS DWORD                                               ' DWORD

DECLARE FUNCTION MultinetGetConnectionPerformanceW IMPORT "MPR.DLL" ALIAS "MultinetGetConnectionPerformanceW" ( _
   BYREF lpNetResource AS NETRESOURCEW _                  ' __in LPNETRESOURCEW lpNetResource
 , BYREF lpNetConnectInfoStruct AS NETCONNECTINFOSTRUCT _ ' __out LPNETCONNECTINFOSTRUCT lpNetConnectInfoStruct
 ) AS DWORD                                               ' DWORD

#IF %DEF(%UNICODE)
   MACRO MultinetGetConnectionPerformance = MultinetGetConnectionPerformanceW
#ELSE
   MACRO MultinetGetConnectionPerformance = MultinetGetConnectionPerformanceA
#ENDIF

'#endif /* WINVER >= 0x0400 */
