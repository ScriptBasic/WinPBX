' ########################################################################################
' Microsoft Windows
' File: LMRepl.inc
' Contents: Structures, function prototypes, and definitions for the replicator APIs
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%LMREPL_INC = 1

#INCLUDE ONCE "lmcons.inc"

'//
'// Replicator Configuration APIs
'//

%REPL_ROLE_EXPORT       = 1
%REPL_ROLE_IMPORT       = 2
%REPL_ROLE_BOTH         = 3

%REPL_INTERVAL_INFOLEVEL        = %PARMNUM_BASE_INFOLEVEL + 0
%REPL_PULSE_INFOLEVEL           = %PARMNUM_BASE_INFOLEVEL + 1
%REPL_GUARDTIME_INFOLEVEL       = %PARMNUM_BASE_INFOLEVEL + 2
%REPL_RANDOM_INFOLEVEL          = %PARMNUM_BASE_INFOLEVEL + 3

' // Size = 40 bytes
TYPE REPL_INFO_0 DWORD
   rp0_role          AS DWORD          ' DWORD  rp0_role
   rp0_exportpath    AS WSTRINGZ PTR   ' LPWSTR rp0_exportpath
   rp0_exportlist    AS WSTRINGZ PTR   ' LPWSTR rp0_exportlist
   rp0_importpath    AS WSTRINGZ PTR   ' LPWSTR rp0_importpath
   rp0_importlist    AS WSTRINGZ PTR   ' LPWSTR rp0_importlist
   rp0_logonusername AS WSTRINGZ PTR   ' LPWSTR rp0_logonusername
   rp0_interval      AS DWORD          ' DWORD  rp0_interval
   rp0_pulse         AS DWORD          ' DWORD  rp0_pulse
   rp0_guardtime     AS DWORD          ' DWORD  rp0_guardtime
   rp0_random        AS DWORD          ' DWORD  rp0_random
END TYPE

' // Size = 4 bytes
TYPE REPL_INFO_1000 DWORD
   rp1000_interval AS DWORD   ' DWORD rp1000_interval
END TYPE

' // Size = 4 bytes
TYPE REPL_INFO_1001 DWORD
   rp1001_pulse AS DWORD   ' DWORD rp1001_pulse
END TYPE

' // Size = 4 bytes
TYPE REPL_INFO_1002 DWORD
   rp1002_guardtime AS DWORD   ' DWORD rp1002_guardtime
END TYPE

' // Size = 4 bytes
TYPE REPL_INFO_1003 DWORD
   rp1003_random AS DWORD   ' DWORD rp1003_random
END TYPE

DECLARE FUNCTION NetReplGetInfo IMPORT "NETAPI32.DLL" ALIAS "NetReplGetInfo" ( _
   BYREF servername AS WSTRINGZ _                       ' __in  LPCWSTR servername OPTIONAL
 , BYVAL level AS DWORD _                               ' __in  DWORD level
 , BYREF bufptr AS ANY _                                ' __out LPBYTE * bufptr
 ) AS DWORD                                             ' NET_API_STATUS

DECLARE FUNCTION NetReplSetInfo IMPORT "NETAPI32.DLL" ALIAS "NetReplSetInfo" ( _
   BYREF servername AS WSTRINGZ _                       ' __in  LPCWSTR servername OPTIONAL
 , BYVAL level AS DWORD _                               ' __in  DWORD level
 , BYVAL buf AS BYTE PTR _                              ' __in  const LPBYTE buf
 , BYREF parm_err AS DWORD _                            ' __out LPDWORD parm_err OPTIONAL
 ) AS DWORD                                             ' NET_API_STATUS

'//
'// Replicator Export Directory APIs
'//

%REPL_INTEGRITY_FILE    = 1
%REPL_INTEGRITY_TREE    = 2

%REPL_EXTENT_FILE       = 1
%REPL_EXTENT_TREE       = 2

%REPL_EXPORT_INTEGRITY_INFOLEVEL = %PARMNUM_BASE_INFOLEVEL + 0
%REPL_EXPORT_EXTENT_INFOLEVEL    = %PARMNUM_BASE_INFOLEVEL + 1

' // Size = 4 bytes
TYPE REPL_EDIR_INFO_0 DWORD
   rped0_dirname AS WSTRINGZ PTR   ' LPWSTR rped0_dirname
END TYPE

' // Size = 12 bytes
TYPE REPL_EDIR_INFO_1 DWORD
   rped1_dirname   AS WSTRINGZ PTR   ' LPWSTR rped1_dirname
   rped1_integrity AS DWORD          ' DWORD  rped1_integrity
   rped1_extent    AS DWORD          ' DWORD  rped1_extent
END TYPE

' // Size = 20 bytes
TYPE REPL_EDIR_INFO_2 DWORD
   rped2_dirname   AS WSTRINGZ PTR   ' LPWSTR rped2_dirname
   rped2_integrity AS DWORD          ' DWORD  rped2_integrity
   rped2_extent    AS DWORD          ' DWORD  rped2_extent
   rped2_lockcount AS DWORD          ' DWORD  rped2_lockcount
   rped2_locktime  AS DWORD          ' DWORD  rped2_locktime
END TYPE

' // Size = 4 bytes
TYPE REPL_EDIR_INFO_1000 DWORD
   rped1000_integrity AS DWORD   ' DWORD rped1000_integrity
END TYPE

' // Size = 4 bytes
TYPE REPL_EDIR_INFO_1001 DWORD
   rped1001_extent AS DWORD   ' DWORD rped1001_extent
END TYPE

DECLARE FUNCTION NetReplExportDirAdd IMPORT "NETAPI32.DLL" ALIAS "NetReplExportDirAdd" ( _
   BYREF servername AS WSTRINGZ _                       ' __in  LPCWSTR servername OPTIONAL
 , BYVAL level AS DWORD _                               ' __in  DWORD level
 , BYVAL buf AS BYTE PTR _                              ' __in  const LPBYTE buf
 , BYREF parm_err AS DWORD _                            ' __out LPDWORD parm_err OPTIONAL
 ) AS DWORD                                             ' NET_API_STATUS

DECLARE FUNCTION NetReplExportDirDel IMPORT "NETAPI32.DLL" ALIAS "NetReplExportDirDel" ( _
   BYREF servername AS WSTRINGZ _                       ' __in LPCWSTR servername OPTIONAL
 , BYREF dirname AS WSTRINGZ _                          ' __in LPCWSTR dirname
 ) AS DWORD                                             ' NET_API_STATUS

DECLARE FUNCTION NetReplExportDirEnum IMPORT "NETAPI32.DLL" ALIAS "NetReplExportDirEnum" ( _
   BYREF servername AS WSTRINGZ _                       ' __in  LPCWSTR servername OPTIONAL
 , BYVAL level AS DWORD _                               ' __in  DWORD level
 , BYREF bufptr AS ANY _                                ' __out LPBYTE * bufptr
 , BYVAL prefmaxlen AS DWORD _                          ' __in  DWORD prefmaxlen
 , BYREF entriesread AS DWORD _                         ' __out LPDWORD entriesread
 , BYREF totalentries AS DWORD  _                       ' __out LPDWORD totalentries
 , BYREF resumehandle AS DWORD _                        ' __in_out LPDWORD resumehandle OPTIONAL
 ) AS DWORD                                             ' NET_API_STATUS

DECLARE FUNCTION NetReplExportDirGetInfo IMPORT "NETAPI32.DLL" ALIAS "NetReplExportDirGetInfo" ( _
   BYREF servername AS WSTRINGZ _                       ' __in  LPCWSTR servername OPTIONAL
 , BYREF dirname AS WSTRINGZ _                          ' __in  LPCWSTR dirname
 , BYVAL level AS DWORD _                               ' __in  DWORD level
 , BYREF bufptr AS ANY _                                ' __out LPBYTE * bufptr
 ) AS DWORD                                             ' NET_API_STATUS

DECLARE FUNCTION NetReplExportDirSetInfo IMPORT "NETAPI32.DLL" ALIAS "NetReplExportDirSetInfo" ( _
   BYREF servername AS WSTRINGZ _                       ' __in  LPCWSTR servername OPTIONAL
 , BYREF dirname AS WSTRINGZ _                          ' __in  LPCWSTR dirname
 , BYVAL level AS DWORD _                               ' __in  DWORD level
 , BYVAL buf AS BYTE PTR _                              ' __in  const LPBYTE buf
 , BYREF parm_err AS DWORD _                            ' __out LPDWORD parm_err OPTIONAL
 ) AS DWORD                                             ' NET_API_STATUS

DECLARE FUNCTION NetReplExportDirLock IMPORT "NETAPI32.DLL" ALIAS "NetReplExportDirLock" ( _
   BYREF servername AS WSTRINGZ _                       ' __in LPCWSTR servername OPTIONAL
 , BYREF dirname AS WSTRINGZ _                          ' __in LPCWSTR dirname
 ) AS DWORD                                             ' NET_API_STATUS

DECLARE FUNCTION NetReplExportDirUnlock IMPORT "NETAPI32.DLL" ALIAS "NetReplExportDirUnlock" ( _
   BYREF servername AS WSTRINGZ _                       ' __in LPCWSTR servername OPTIONAL
 , BYREF dirname AS WSTRINGZ _                          ' __in LPCWSTR dirname
 , BYVAL unlockforce AS DWORD _                         ' __in DWORD unlockforce
 ) AS DWORD                                             ' NET_API_STATUS

%REPL_UNLOCK_NOFORCE    = 0
%REPL_UNLOCK_FORCE      = 1

'//
'// Replicator Import Directory APIs
'//


' // Size = 4 bytes
TYPE REPL_IDIR_INFO_0 DWORD
   rpid0_dirname AS WSTRINGZ PTR   ' LPWSTR rpid0_dirname
END TYPE

' // Size = 24 bytes
TYPE REPL_IDIR_INFO_1 DWORD
   rpid1_dirname          AS WSTRINGZ PTR   ' LPWSTR rpid1_dirname
   rpid1_state            AS DWORD          ' DWORD  rpid1_state
   rpid1_mastername       AS WSTRINGZ PTR   ' LPWSTR rpid1_mastername
   rpid1_last_update_time AS DWORD          ' DWORD  rpid1_last_update_time
   rpid1_lockcount        AS DWORD          ' DWORD  rpid1_lockcount
   rpid1_locktime         AS DWORD          ' DWORD  rpid1_locktime
END TYPE


DECLARE FUNCTION NetReplImportDirAdd IMPORT "NETAPI32.DLL" ALIAS "NetReplImportDirAdd" ( _
   BYREF servername AS WSTRINGZ _                       ' __in  LPCWSTR servername OPTIONAL
 , BYVAL level AS DWORD _                               ' __in  DWORD level
 , BYVAL buf AS BYTE PTR _                              ' __in  const LPBYTE buf
 , BYREF parm_err AS DWORD _                            ' __out LPDWORD parm_err OPTIONAL
 ) AS DWORD                                             ' NET_API_STATUS

DECLARE FUNCTION NetReplImportDirDel IMPORT "NETAPI32.DLL" ALIAS "NetReplImportDirDel" ( _
   BYREF servername AS WSTRINGZ _                       ' __in LPCWSTR servername OPTIONAL
 , BYREF dirname AS WSTRINGZ _                          ' __in LPCWSTR dirname
 ) AS DWORD                                             ' NET_API_STATUS

DECLARE FUNCTION NetReplImportDirEnum IMPORT "NETAPI32.DLL" ALIAS "NetReplImportDirEnum" ( _
   BYREF servername AS WSTRINGZ _                       ' __in  LPCWSTR servername OPTIONAL
 , BYVAL level AS DWORD _                               ' __in  DWORD level
 , BYREF bufptr AS ANY _                                ' __out LPBYTE * bufptr
 , BYVAL prefmaxlen AS DWORD _                          ' __in  DWORD prefmaxlen
 , BYREF entriesread AS DWORD _                         ' __out LPDWORD entriesread
 , BYREF totalentries AS DWORD _                        ' __out LPDWORD totalentries
 , BYREF resumehandle AS DWORD _                        ' __in_out LPDWORD resumehandle OPTIONAL
 ) AS DWORD                                             ' NET_API_STATUS

DECLARE FUNCTION NetReplImportDirGetInfo IMPORT "NETAPI32.DLL" ALIAS "NetReplImportDirGetInfo" ( _
   BYREF servername AS WSTRINGZ _                       ' __in  LPCWSTR servername OPTIONAL
 , BYREF dirname AS WSTRINGZ _                          ' __in  LPCWSTR dirname
 , BYVAL level AS DWORD _                               ' __in  DWORD level
 , BYREF bufptr AS ANY _                                ' __out LPBYTE * bufptr
 ) AS DWORD                                             ' NET_API_STATUS

DECLARE FUNCTION NetReplImportDirLock IMPORT "NETAPI32.DLL" ALIAS "NetReplImportDirLock" ( _
   BYREF servername AS WSTRINGZ _                       ' __in LPCWSTR servername OPTIONAL
 , BYREF dirname AS WSTRINGZ _                          ' __in LPCWSTR dirname
 ) AS DWORD                                             ' NET_API_STATUS

DECLARE FUNCTION NetReplImportDirUnlock IMPORT "NETAPI32.DLL" ALIAS "NetReplImportDirUnlock" ( _
   BYREF servername AS WSTRINGZ _                       ' __in LPCWSTR servername OPTIONAL
 , BYREF dirname AS WSTRINGZ _                          ' __in LPCWSTR dirname
 , BYVAL unlockforce AS DWORD _                         ' __in DWORD unlockforce
 ) AS DWORD                                             ' NET_API_STATUS

%REPL_STATE_OK                  = 0
%REPL_STATE_NO_MASTER           = 1
%REPL_STATE_NO_SYNC             = 2
%REPL_STATE_NEVER_REPLICATED    = 3
