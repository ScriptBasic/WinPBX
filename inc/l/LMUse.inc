' ########################################################################################
' Microsoft Windows
' File: LMUse.inc
' Contents: Structures, function prototypes, and definitions for the NetUse API.
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%LMUSE_INC = 1

#INCLUDE ONCE "lmcons.inc"
#INCLUDE ONCE "lmuseflg.inc"

'//
'// Function Prototypes
'//

DECLARE FUNCTION NetUseAdd IMPORT "NETAPI32.DLL" ALIAS "NetUseAdd" ( _
   BYREF UncServerName AS WSTRINGZ _                    ' __in_opt LMSTR UncServerName
 , BYVAL Level AS DWORD _                               ' __in DWORD Level
 , BYVAL Buf AS BYTE PTR _                              ' __in LPBYTE Buf
 , BYREF ParmError AS DWORD _                           ' __out_opt LPDWORD ParmError
 ) AS DWORD                                             ' NET_API_STATUS

DECLARE FUNCTION NetUseDel IMPORT "NETAPI32.DLL" ALIAS "NetUseDel" ( _
   BYREF UncServerName AS WSTRINGZ _                    ' __in_opt LMSTR UncServerName
 , BYREF UseName AS WSTRINGZ _                          ' __in LMSTR UseName
 , BYVAL ForceCond AS DWORD _                           ' __in DWORD ForceCond
 ) AS DWORD                                             ' NET_API_STATUS

DECLARE FUNCTION NetUseEnum IMPORT "NETAPI32.DLL" ALIAS "NetUseEnum" ( _
   BYREF UncServerName AS WSTRINGZ _                    ' __in_opt LMSTR UncServerName
 , BYVAL Level AS DWORD _                               ' __in DWORD Level
 , BYREF BufPtr AS ANY _                                ' __out_opt LPBYTE *BufPtr
 , BYVAL PreferedMaximumSize AS DWORD _                 ' __in DWORD PreferedMaximumSize
 , BYREF EntriesRead AS DWORD _                         ' __out_opt LPDWORD EntriesRead
 , BYREF TotalEntries AS DWORD _                        ' __out LPDWORD TotalEntries
 , BYREF ResumeHandle AS DWORD _                        ' __inout_opt LPDWORD ResumeHandle
 ) AS DWORD                                             ' NET_API_STATUS

DECLARE FUNCTION NetUseGetInfo IMPORT "NETAPI32.DLL" ALIAS "NetUseGetInfo" ( _
   BYREF UncServerName AS WSTRINGZ _                    ' __in_opt LMSTR UncServerName
 , BYREF UseName AS WSTRINGZ _                          ' __in LMSTR UseName
 , BYVAL Level AS DWORD _                               ' __in DWORD Level
 , BYREF BufPtr AS ANY _                                ' __out_opt LPBYTE *BufPtr
 ) AS DWORD                                             ' NET_API_STATUS

'//
'//  Data Structures
'//

' // Size = 8 bytes
TYPE USE_INFO_0 DWORD
   ui0_local  AS WSTRINGZ PTR   ' LMSTR ui0_local
   ui0_remote AS WSTRINGZ PTR   ' LMSTR ui0_remote
END TYPE

' // Size = 28 bytes
TYPE USE_INFO_1 DWORD
   ui1_local    AS WSTRINGZ PTR   ' LMSTR ui1_local
   ui1_remote   AS WSTRINGZ PTR   ' LMSTR ui1_remote
   ui1_password AS WSTRINGZ PTR   ' LMSTR ui1_password
   ui1_status   AS DWORD          ' DWORD ui1_status
   ui1_asg_type AS DWORD          ' DWORD ui1_asg_type
   ui1_refcount AS DWORD          ' DWORD ui1_refcount
   ui1_usecount AS DWORD          ' DWORD ui1_usecount
END TYPE

' // Size = 36 bytes
TYPE USE_INFO_2 DWORD
   ui2_local      AS WSTRINGZ PTR   ' LMSTR ui2_local
   ui2_remote     AS WSTRINGZ PTR   ' LMSTR ui2_remote
   ui2_password   AS WSTRINGZ PTR   ' LMSTR ui2_password
   ui2_status     AS DWORD          ' DWORD ui2_status
   ui2_asg_type   AS DWORD          ' DWORD ui2_asg_type
   ui2_refcount   AS DWORD          ' DWORD ui2_refcount
   ui2_usecount   AS DWORD          ' DWORD ui2_usecount
   ui2_username   AS WSTRINGZ PTR   ' LMSTR ui2_username
   ui2_domainname AS WSTRINGZ PTR   ' LMSTR ui2_domainname
END TYPE

' // Size = 40 bytes
TYPE USE_INFO_3 DWORD
   ui3_ui2   AS USE_INFO_2   ' USE_INFO_2 ui3_ui2
   ui3_flags AS DWORD        ' ULONG      ui3_flags
END TYPE

' // Size = 48 bytes
TYPE USE_INFO_4 DWORD
   ui4_ui3                  AS USE_INFO_3
   ui4_auth_identity_length AS DWORD      ' DWORD
   ui4_auth_identity        AS BYTE PTR   ' PBYTE
END TYPE

'//
'// Special Values and Constants
'//

'//
'// One of these values indicates the parameter within an information
'// structure that is invalid when ERROR_INVALID_PARAMETER is returned by
'// NetUseAdd.
'//

%USE_LOCAL_PARMNUM      = 1
%USE_REMOTE_PARMNUM     = 2
%USE_PASSWORD_PARMNUM   = 3
%USE_ASGTYPE_PARMNUM    = 4
%USE_USERNAME_PARMNUM   = 5
%USE_DOMAINNAME_PARMNUM = 6

'//
'// Values appearing in the ui1_status field of use_info_1 structure.
'// Note that USE_SESSLOST and USE_DISCONN are synonyms.
'//

%USE_OK                = 0
%USE_PAUSED            = 1
%USE_SESSLOST          = 2
%USE_DISCONN           = 2
%USE_NETERR            = 3
%USE_CONN              = 4
%USE_RECONN            = 5

'//
'// Values of the ui1_asg_type field of use_info_1 structure
'//

%USE_WILDCARD          = &HFFFFFFFF???  ' ( (DWORD) (-1) )
%USE_DISKDEV           = 0
%USE_SPOOLDEV          = 1
%USE_CHARDEV           = 2
%USE_IPC               = 3

'//
'// Flags defined in the use_info_3 structure
'//

%CREATE_NO_CONNECT = &H1        ' creation flags
%CREATE_BYPASS_CSC = &H2        ' force connection to server, bypassing CSC
                                '  all ops on this connection go to the server,
                                '  never to the cache
%USE_DEFAULT_CREDENTIALS = &H4  ' No explicit credentials passed to NetUseAdd
