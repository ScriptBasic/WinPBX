' ########################################################################################
' Microsoft Windows
' File: LMShare.inc
' Contents: API function prototypes and data structures for the following groups of NT API functions:
' NetShare, NetSession, NetFile, NetConnection
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

'//
'// SHARE API
'//

#INCLUDE THIS ONCE
%LMSHARE_INC = 1

#INCLUDE ONCE "wtypes.inc"
#INCLUDE ONCE "lmcons.inc"

#IF NOT %DEF(%LMSHARE)
    %LMSHARE = 1

'//
'// Function Prototypes - Share
'//

DECLARE FUNCTION NetShareAdd IMPORT "NETAPI32.DLL" ALIAS "NetShareAdd" ( _
   BYREF servername AS WSTRINGZ _                       ' __in  LMSTR   servername
 , BYVAL level AS DWORD _                               ' __in  DWORD   level
 , BYVAL buf AS BYTE PTR _                              ' __in  LPBYTE  buf
 , BYREF parm_err AS DWORD _                            ' __out LPDWORD parm_err
 ) AS DWORD                                             ' NET_API_STATUS

DECLARE FUNCTION NetShareEnum IMPORT "NETAPI32.DLL" ALIAS "NetShareEnum" ( _
   BYREF servername AS WSTRINGZ _                       ' __in  LMSTR       servername
 , BYVAL level AS DWORD _                               ' __in  DWORD       level
 , BYREF bufptr AS ANY _                                ' __out LPBYTE      *bufptr
 , BYVAL prefmaxlen AS DWORD _                          ' __in  DWORD       prefmaxlen
 , BYREF entriesread AS DWORD _                         ' __out LPDWORD     entriesread
 , BYREF totalentries AS DWORD _                        ' __out LPDWORD     totalentries
 , BYREF resume_handle AS DWORD _                       ' __in_out LPDWORD  resume_handle
 ) AS DWORD                                             ' NET_API_STATUS

DECLARE FUNCTION NetShareEnumSticky IMPORT "NETAPI32.DLL" ALIAS "NetShareEnumSticky" ( _
   BYREF servername AS WSTRINGZ _                          ' __in  LMSTR       servername
 , BYVAL level AS DWORD _                               ' __in  DWORD       level
 , BYREF bufptr AS ANY _                                ' __out LPBYTE      *bufptr
 , BYVAL prefmaxlen AS DWORD _                          ' __in  DWORD       prefmaxlen
 , BYREF entriesread AS DWORD _                         ' __out LPDWORD     entriesread
 , BYREF totalentries AS DWORD _                        ' __out LPDWORD     totalentries
 , BYREF resume_handle AS DWORD _                       ' __in_out LPDWORD  resume_handle
 ) AS DWORD                                             ' NET_API_STATUS

DECLARE FUNCTION NetShareGetInfo IMPORT "NETAPI32.DLL" ALIAS "NetShareGetInfo" ( _
   BYREF servername AS WSTRINGZ _                       ' __in  LMSTR   servername
 , BYREF netname AS WSTRINGZ _                          ' __in  LMSTR   netname
 , BYVAL level AS DWORD _                               ' __in  DWORD   level
 , BYREF bufptr AS ANY _                                ' __out LPBYTE  *bufptr
 ) AS DWORD                                             ' NET_API_STATUS

DECLARE FUNCTION NetShareSetInfo IMPORT "NETAPI32.DLL" ALIAS "NetShareSetInfo" ( _
   BYREF servername AS WSTRINGZ _                       ' __in  LMSTR   servername
 , BYREF netname AS WSTRINGZ _                          ' __in  LMSTR   netname
 , BYVAL level AS DWORD _                               ' __in  DWORD   level
 , BYVAL buf AS BYTE PTR _                              ' __in  LPBYTE  buf
 , BYREF parm_err AS DWORD _                            ' __out LPDWORD parm_err
 ) AS DWORD                                             ' NET_API_STATUS

DECLARE FUNCTION NetShareDel IMPORT "NETAPI32.DLL" ALIAS "NetShareDel" ( _
   BYREF servername AS WSTRINGZ _                       ' __in  LMSTR   servername
 , BYREF netname AS WSTRINGZ _                          ' __in  LMSTR   netname
 , BYVAL reserved AS DWORD _                            ' __in  DWORD   reserved
 ) AS DWORD                                             ' NET_API_STATUS

DECLARE FUNCTION NetShareDelSticky IMPORT "NETAPI32.DLL" ALIAS "NetShareDelSticky" ( _
   BYREF servername AS WSTRINGZ _                       ' __in  LMSTR   servername
 , BYREF netname AS WSTRINGZ _                          ' __in  LMSTR   netname
 , BYVAL reserved AS DWORD _                            ' __in  DWORD   reserved
 ) AS DWORD                                             ' NET_API_STATUS

DECLARE FUNCTION NetShareCheck IMPORT "NETAPI32.DLL" ALIAS "NetShareCheck" ( _
   BYREF servername AS WSTRINGZ _                       ' __in  LMSTR   servername
 , BYREF device AS WSTRINGZ _                           ' __in  LMSTR   device
 , BYREF type AS DWORD _                                ' __out LPDWORD type
 ) AS DWORD                                             ' NET_API_STATUS

DECLARE FUNCTION NetShareDelEx IMPORT "NETAPI32.DLL" ALIAS "NetShareDelEx" ( _
   BYREF servername AS WSTRINGZ _                       ' __in  LMSTR   servername
 , BYVAL level AS DWORD _                               ' __in  DWORD   level
 , BYVAL buf AS BYTE PTR _                              ' __in  LPBYTE  buf
 ) AS DWORD                                             ' NET_API_STATUS

'//
'// Data Structures - Share
'//

' // Size = 4 bytes
TYPE SHARE_INFO_0 DWORD
   shi0_netname        AS WSTRINGZ PTR   ' LMSTR shi0_netname
END TYPE

' // Size = 12 bytes
TYPE SHARE_INFO_1 DWORD
   shi1_netname        AS WSTRINGZ PTR   ' LMSTR shi1_netname
   shi1_type           AS DWORD          ' DWORD shi1_type
   shi1_remark         AS WSTRINGZ PTR   ' LMSTR shi1_remark
END TYPE

' // Size = 32 bytes
TYPE SHARE_INFO_2 DWORD
   shi2_netname        AS WSTRINGZ PTR   ' LMSTR shi2_netname
   shi2_type           AS DWORD          ' DWORD shi2_type
   shi2_remark         AS WSTRINGZ PTR   ' LMSTR shi2_remark
   shi2_permissions    AS DWORD          ' DWORD shi2_permissions
   shi2_max_uses       AS DWORD          ' DWORD shi2_max_uses
   shi2_current_uses   AS DWORD          ' DWORD shi2_current_uses
   shi2_path           AS WSTRINGZ PTR   ' LMSTR shi2_path
   shi2_passwd         AS WSTRINGZ PTR   ' LMSTR shi2_passwd
END TYPE

' // Size = 16 bytes
TYPE SHARE_INFO_501 DWORD
   shi501_netname      AS WSTRINGZ PTR   ' LMSTR shi501_netname
   shi501_type         AS DWORD          ' DWORD shi501_type
   shi501_remark       AS WSTRINGZ PTR   ' LMSTR shi501_remark
   shi501_flags        AS DWORD          ' DWORD shi501_flags
END TYPE

' // Size = 40 bytes
TYPE SHARE_INFO_502 DWORD
   shi502_netname             AS WSTRINGZ PTR   ' LMSTR shi502_netname
   shi502_type                AS DWORD          ' DWORD shi502_type
   shi502_remark              AS WSTRINGZ PTR   ' LMSTR shi502_remark
   shi502_permissions         AS DWORD          ' DWORD shi502_permissions
   shi502_max_uses            AS DWORD          ' DWORD shi502_max_uses
   shi502_current_uses        AS DWORD          ' DWORD shi502_current_uses
   shi502_path                AS WSTRINGZ PTR   ' LMSTR shi502_path
   shi502_passwd              AS WSTRINGZ PTR   ' LMSTR shi502_passwd
   shi502_reserved            AS DWORD          ' DWORD shi502_reserved
   shi502_security_descriptor AS SECURITY_DESCRIPTOR PTR   ' PSECURITY_DESCRIPTOR shi502_security_descriptor
END TYPE

' // Size = 44 bytes
TYPE SHARE_INFO_503 DWORD
   shi503_netname             AS WSTRINGZ PTR   ' LMSTR
   shi503_type                AS DWORD          ' DWORD
   shi503_remark              AS WSTRINGZ PTR   ' LMSTR
   shi503_permissions         AS DWORD          ' DWORD
   shi503_max_uses            AS DWORD          ' DWORD
   shi503_current_uses        AS DWORD          ' DWORD
   shi503_path                AS WSTRINGZ PTR   ' LMSTR
   shi503_passwd              AS WSTRINGZ PTR   ' LMSTR
   shi503_servername          AS WSTRINGZ PTR   ' LMSTR
   shi503_reserved            AS DWORD          ' DWORD
   shi503_security_descriptor AS SECURITY_DESCRIPTOR PTR   ' PSECURITY_DESCRIPTOR
END TYPE

' // Size = 4 bytes
TYPE SHARE_INFO_1004 DWORD
   shi1004_remark      AS WSTRINGZ PTR   ' LMSTR shi1004_remark
END TYPE

' // Size = 4 bytes
TYPE SHARE_INFO_1005 DWORD
   shi1005_flags       AS DWORD   ' DWORD  shi1005_flags
END TYPE

' // Size = 4 bytes
TYPE SHARE_INFO_1006 DWORD
   shi1006_max_uses    AS DWORD   ' DWORD shi1006_max_uses
END TYPE

' // Size = 8 bytes
TYPE SHARE_INFO_1501 DWORD
   shi1501_reserved            AS DWORD                     ' DWORD shi1501_reserved
   shi1501_security_descriptor AS SECURITY_DESCRIPTOR PTR   ' PSECURITY_DESCRIPTOR shi1501_security_descriptor
END TYPE

' // Size = 16 bytes
TYPE SHARE_INFO_1503 DWORD
   shi1503_sharefilter AS GUID   ' GUID
END TYPE

'//
'// NetShareAlias functions
'//

DECLARE FUNCTION NetServerAliasAdd IMPORT "NETAPI32.DLL" ALIAS "NetServerAliasAdd" ( _
   BYREF servername AS WSTRINGZ _                       ' __in  LMSTR   servername
 , BYVAL level AS DWORD _                               ' __in  DWORD   level
 , BYVAL buf AS BYTE PTR _                              ' __in  LPBYTE  buf
 ) AS DWORD                                             ' NET_API_STATUS

DECLARE FUNCTION NetServerAliasDel IMPORT "NETAPI32.DLL" ALIAS "NetServerAliasDel" ( _
   BYREF servername AS WSTRINGZ _                       ' __in  LMSTR   servername
 , BYVAL level AS DWORD _                               ' __in  DWORD   level
 , BYVAL buf AS BYTE PTR _                              ' __in  LPBYTE  buf
 ) AS DWORD                                             ' NET_API_STATUS

DECLARE FUNCTION NetServerAliasEnum IMPORT "NETAPI32.DLL" ALIAS "NetServerAliasEnum" ( _
   BYREF servername AS WSTRINGZ _                       ' __in  LMSTR   servername
 , BYVAL level AS DWORD _                               ' __in  DWORD   level
 , BYREF bufptr AS ANY _                                ' __out LPBYTE  *bufptr
 , BYVAL prefmaxlen AS DWORD _                          ' __in  DWORD   prefmaxlen
 , BYREF entriesread AS DWORD _                         ' __out LPDWORD entriesread
 , BYREF totalentries AS DWORD _                        ' __out LPDWORD totalentries
 , BYREF resumehandle AS DWORD _                        ' __in_out LPDWORD  resumehandle
 ) AS DWORD                                             ' NET_API_STATUS

' // Size = 16 bytes
TYPE SERVER_ALIAS_INFO_0 DWORD
   srvai0_alias    AS WSTRINGZ PTR   ' LMSTR
   srvai0_target   AS WSTRINGZ PTR   ' LMSTR
   srvai0_default  AS BYTE           ' BOOLEAN
   srvai0_reserved AS DWORD          ' ULONG
END TYPE

'//
'// Special Values and Constants - Share
'//

'//
'// Values for parm_err parameter.
'//

%SHARE_NETNAME_PARMNUM      = 1
%SHARE_TYPE_PARMNUM         = 3
%SHARE_REMARK_PARMNUM       = 4
%SHARE_PERMISSIONS_PARMNUM  = 5
%SHARE_MAX_USES_PARMNUM     = 6
%SHARE_CURRENT_USES_PARMNUM = 7
%SHARE_PATH_PARMNUM         = 8
%SHARE_PASSWD_PARMNUM       = 9
%SHARE_FILE_SD_PARMNUM      = 501
%SHARE_SERVER_PARMNUM       = 503

'//
'// Single-field infolevels for NetShareSetInfo.
'//

%SHARE_REMARK_INFOLEVEL = %PARMNUM_BASE_INFOLEVEL + %SHARE_REMARK_PARMNUM
%SHARE_MAX_USES_INFOLEVEL = %PARMNUM_BASE_INFOLEVEL + %SHARE_MAX_USES_PARMNUM
%SHARE_FILE_SD_INFOLEVEL = %PARMNUM_BASE_INFOLEVEL + %SHARE_FILE_SD_PARMNUM

%SHI1_NUM_ELEMENTS      = 4
%SHI2_NUM_ELEMENTS      = 10

'//
'// Share types (shi1_type and shi2_type fields).
'//

%STYPE_DISKTREE         = 0
%STYPE_PRINTQ           = 1
%STYPE_DEVICE           = 2
%STYPE_IPC              = 3

%STYPE_TEMPORARY        = &H40000000???
%STYPE_SPECIAL          = &H80000000???

%SHI_USES_UNLIMITED     = &HFFFFFFFF???   ' (DWORD)-1

'//
'// Flags values for the 501 and 1005 levels
'//
%SHI1005_FLAGS_DFS       = &H0001    ' // Share is in the DFS
%SHI1005_FLAGS_DFS_ROOT  = &H0002    ' // Share is root of DFS

%CSC_MASK_EXT            = &H2030    ' // Used to mask off the following states (including SHI1005_FLAGS_ENABLE_HASH)
%CSC_MASK                = &H0030    ' // Used to mask off the following states

%CSC_CACHE_MANUAL_REINT  = &H0000    ' // No automatic file by file reintegration
%CSC_CACHE_AUTO_REINT    = &H0010    ' // File by file reintegration is OK
%CSC_CACHE_VDO           = &H0020    ' // no need to flow opens
%CSC_CACHE_NONE          = &H0030    ' // no CSC for this share


%SHI1005_FLAGS_RESTRICT_EXCLUSIVE_OPENS    = &H0100   ' // Used to disallow read-deny read behavior
%SHI1005_FLAGS_FORCE_SHARED_DELETE         = &H0200   ' // Used to allows force shared delete
%SHI1005_FLAGS_ALLOW_NAMESPACE_CACHING     = &H0400   ' // The clients may cache the namespace
%SHI1005_FLAGS_ACCESS_BASED_DIRECTORY_ENUM = &H0800   ' // Trim visible files in enumerations based on access
%SHI1005_FLAGS_FORCE_LEVELII_OPLOCK        = &H1000   ' // Only issue level2 oplock
%SHI1005_FLAGS_ENABLE_HASH                 = &H2000   ' // Enable hash generation and retrieval requests from share

'//
'// The subset of 1005 infolevel flags that can be set via the API
'//
%SHI1005_VALID_FLAGS_SET = %CSC_MASK OR _
                           %SHI1005_FLAGS_RESTRICT_EXCLUSIVE_OPENS OR _
                           %SHI1005_FLAGS_FORCE_SHARED_DELETE OR _
                           %SHI1005_FLAGS_ALLOW_NAMESPACE_CACHING OR _
                           %SHI1005_FLAGS_ACCESS_BASED_DIRECTORY_ENUM OR _
                           %SHI1005_FLAGS_FORCE_LEVELII_OPLOCK OR _
                           %SHI1005_FLAGS_ENABLE_HASH

'#endif // _LMSHARE_
#ENDIF   ' #IF NOT %DEF(%LMSHARE)

'//
'// SESSION API
'//


#IF NOT %DEF(%LMSESSION)
    %LMSESSION = 1

'#ifndef _LMSESSION_
'#define _LMSESSION_

'//
'// Function Prototypes Session
'//

DECLARE FUNCTION NetSessionEnum IMPORT "NETAPI32.DLL" ALIAS "NetSessionEnum" ( _
   BYREF servername AS WSTRINGZ _                       ' __in  LMSTR       servername OPTIONAL
 , BYREF UncClientName AS WSTRINGZ _                    ' __in  LMSTR       UncClientName OPTIONAL
 , BYREF username AS WSTRINGZ _                         ' __in  LMSTR       username OPTIONAL
 , BYVAL level AS DWORD _                               ' __in  DWORD       level
 , BYREF bufptr AS ANY _                                ' __out LPBYTE      *bufptr
 , BYVAL prefmaxlen AS DWORD _                          ' __in  DWORD       prefmaxlen
 , BYREF entriesread AS DWORD _                         ' __out LPDWORD     entriesread
 , BYREF totalentries AS DWORD _                        ' __out LPDWORD     totalentries
 , BYREF resume_handle AS DWORD _                       ' __in_out LPDWORD  resume_handle OPTIONAL
 ) AS DWORD                                             ' NET_API_STATUS

DECLARE FUNCTION NetSessionDel IMPORT "NETAPI32.DLL" ALIAS "NetSessionDel" ( _
   BYREF servername AS WSTRINGZ _                       ' __in  LMSTR       servername OPTIONAL
 , BYREF UncClientName AS WSTRINGZ _                    ' __in  LMSTR       UncClientName
 , BYREF username AS WSTRINGZ _                         ' __in  LMSTR       username
 ) AS DWORD                                             ' NET_API_STATUS

DECLARE FUNCTION NetSessionGetInfo IMPORT "NETAPI32.DLL" ALIAS "NetSessionGetInfo" ( _
   BYREF WSTRINGZ _                                     ' __in  LMSTR       servername OPTIONAL
 , BYREF WSTRINGZ _                                     ' __in  LMSTR       UncClientName
 , BYREF WSTRINGZ _                                     ' __in  LMSTR       username
 , BYVAL DWORD _                                        ' __in  DWORD       level
 , BYREF ANY _                                          ' __out LPBYTE      *bufptr
 ) AS DWORD                                             ' NET_API_STATUS

'//
'// Data Structures - Session
'//

' // Size = 4 bytes
TYPE SESSION_INFO_0 DWORD
   sesi0_cname AS WSTRINGZ PTR   ' LMSTR sesi0_cname  // client name (no backslashes)
END TYPE

' // Size = 24 bytes
TYPE SESSION_INFO_1 DWORD
   sesi1_cname      AS WSTRINGZ PTR   ' LMSTR sesi1_cname  // client name (no backslashes)
   sesi1_username   AS WSTRINGZ PTR   ' LMSTR sesi1_username
   sesi1_num_opens  AS DWORD          ' DWORD sesi1_num_opens
   sesi1_time       AS DWORD          ' DWORD sesi1_time
   sesi1_idle_time  AS DWORD          ' DWORD sesi1_idle_time
   sesi1_user_flags AS DWORD          ' DWORD sesi1_user_flags
END TYPE

' // Size = 28 bytes
TYPE SESSION_INFO_2 DWORD
   sesi2_cname       AS WSTRINGZ PTR   ' LMSTR sesi2_cname
   sesi2_username    AS WSTRINGZ PTR   ' LMSTR sesi2_username
   sesi2_num_opens   AS DWORD          ' DWORD sesi2_num_opens
   sesi2_time        AS DWORD          ' DWORD sesi2_time
   sesi2_idle_time   AS DWORD          ' DWORD sesi2_idle_time
   sesi2_user_flags  AS DWORD          ' DWORD sesi2_user_flags
   sesi2_cltype_name AS WSTRINGZ PTR   ' LMSTR sesi2_cltype_name
END TYPE

' // Size = 12 bytes
TYPE SESSION_INFO_10 DWORD
   sesi10_cname     AS WSTRINGZ PTR   ' LMSTR sesi10_cname  // client name (no backslashes)
   sesi10_username  AS WSTRINGZ PTR   ' LMSTR sesi10_username
   sesi10_time      AS DWORD          ' DWORD sesi10_time
   sesi10_idle_time AS DWORD          ' DWORD sesi10_idle_time
END TYPE

' // Size = 32 bytes
TYPE SESSION_INFO_502 DWORD
   sesi502_cname       AS WSTRINGZ PTR   ' LMSTR sesi502_cname  // client name (no backslashes)
   sesi502_username    AS WSTRINGZ PTR   ' LMSTR sesi502_username
   sesi502_num_opens   AS DWORD          ' DWORD sesi502_num_opens
   sesi502_time        AS DWORD          ' DWORD sesi502_time
   sesi502_idle_time   AS DWORD          ' DWORD sesi502_idle_time
   sesi502_user_flags  AS DWORD          ' DWORD sesi502_user_flags
   sesi502_cltype_name AS WSTRINGZ PTR   ' LMSTR sesi502_cltype_name
   sesi502_transport   AS WSTRINGZ PTR   ' LMSTR sesi502_transport
END TYPE

'//
'// Special Values and Constants - Session
'//


'//
'// Bits defined in sesi1_user_flags.
'//

%SESS_GUEST         = &H00000001 ' // session is logged on as a guest
%SESS_NOENCRYPTION  = &H00000002 ' // session is not using encryption

%SESI1_NUM_ELEMENTS = 8
%SESI2_NUM_ELEMENTS = 9

'#endif // _LMSESSION_
#ENDIF   ' #IF NOT %DEF(%LMSESSION)

'//
'// CONNECTION API
'//

#IF NOT %DEF(%LMCONNECTION)
    %LMCONNECTION = 1

'#ifndef _LMCONNECTION_
'#define _LMCONNECTION_

'//
'// Function Prototypes - CONNECTION
'//

DECLARE FUNCTION NetConnectionEnum IMPORT "NETAPI32.DLL" ALIAS "NetConnectionEnum" ( _
   BYREF servername AS WSTRINGZ _                       ' __in  LMSTR   servername OPTIONAL
 , BYREF qualifier AS WSTRINGZ _                        ' __in  LMSTR   qualifier
 , BYVAL level AS DWORD _                               ' __in  DWORD   level
 , BYREF bufptr AS ANY _                                ' __out LPBYTE  *bufptr
 , BYVAL prefmaxlen AS DWORD _                          ' __in  DWORD   prefmaxlen
 , BYREF entriesread AS DWORD _                         ' __out LPDWORD entriesread
 , BYREF totalentries AS DWORD _                        ' __out LPDWORD totalentries
 , BYREF resume_handle AS DWORD _                       ' __in_out LPDWORD resume_handle OPTIONAL
 ) AS DWORD                                             ' NET_API_STATUS

'//
'// Data Structures - CONNECTION
'//

' // Size = 4 bytes
TYPE CONNECTION_INFO_0 DWORD
   coni0_id AS DWORD   ' DWORD   coni0_id
END TYPE

' // Size = 28 bytes
TYPE CONNECTION_INFO_1 DWORD
   coni1_id        AS DWORD          ' DWORD coni1_id
   coni1_type      AS DWORD          ' DWORD coni1_type
   coni1_num_opens AS DWORD          ' DWORD coni1_num_opens
   coni1_num_users AS DWORD          ' DWORD coni1_num_users
   coni1_time      AS DWORD          ' DWORD coni1_time
   coni1_username  AS WSTRINGZ PTR   ' LMSTR coni1_username
   coni1_netname   AS WSTRINGZ PTR   ' LMSTR coni1_netname
END TYPE

'#endif // _LMCONNECTION_
#ENDIF   ' #IF NOT %DEF(%LMCONNECTION)

'//
'// FILE API
'//

#IF NOT %DEF(%LMFILE)
    %LMFILE = 1

'#ifndef _LMFILE_
'#define _LMFILE_

'//
'// Function Prototypes - FILE
'//

DECLARE FUNCTION NetFileClose IMPORT "NETAPI32.DLL" ALIAS "NetFileClose" ( _
   BYREF servername AS WSTRINGZ _                       ' __in LMSTR    servername OPTIONAL
 , BYVAL fileid AS DWORD _                              ' __in DWORD    fileid
 ) AS DWORD                                             ' NET_API_STATUS

DECLARE FUNCTION NetFileEnum IMPORT "NETAPI32.DLL" ALIAS "NetFileEnum" ( _
   BYREF servername AS WSTRINGZ _                       ' __in  LMSTR       servername OPTIONAL
 , BYREF basepath AS WSTRINGZ _                         ' __in  LMSTR       basepath OPTIONAL
 , BYREF username AS WSTRINGZ _                         ' __in  LMSTR       username OPTIONAL
 , BYVAL level AS DWORD _                               ' __in  DWORD       level
 , BYREF bufptr AS ANY _                                ' __out LPBYTE      *bufptr
 , BYVAL prefmaxlen AS DWORD _                          ' __in  DWORD       prefmaxlen
 , BYREF prefmaxlen AS DWORD _                          ' __in  DWORD       prefmaxlen
 , BYREF totalentries AS DWORD _                        ' __out LPDWORD     totalentries
 , BYREF resume_handle AS DWORD _                       ' __in_out PDWORD_PTR  resume_handle OPTIONAL
 ) AS DWORD                                             ' NET_API_STATUS

DECLARE FUNCTION NetFileGetInfo IMPORT "NETAPI32.DLL" ALIAS "NetFileGetInfo" ( _
   BYREF servername AS WSTRINGZ _                       ' __in  LMSTR   servername OPTIONAL
 , BYVAL fileid AS DWORD _                              ' __in  DWORD   fileid
 , BYVAL level AS DWORD _                               ' __in  DWORD   level
 , BYREF bufptr AS ANY _                                ' __out LPBYTE  *bufptr
 ) AS DWORD                                             ' NET_API_STATUS

'//
'// Data Structures - File
'//

'//  File APIs are available at information levels 2 & 3 only. Levels 0 &
'//  1 are not supported.
'//

' // Size = 4 bytes
TYPE FILE_INFO_2 DWORD
   fi2_id AS DWORD   ' DWORD fi2_id
END TYPE

' // Size = 20 bytes
TYPE FILE_INFO_3 DWORD
   fi3_id          AS DWORD          ' DWORD fi3_id
   fi3_permissions AS DWORD          ' DWORD fi3_permissions
   fi3_num_locks   AS DWORD          ' DWORD fi3_num_locks
   fi3_pathname    AS WSTRINGZ PTR   ' LMSTR fi3_pathname
   fi3_username    AS WSTRINGZ PTR   ' LMSTR fi3_username
END TYPE

'//
'// Special Values and Constants - File
'//

'//
'// bit values for permissions
'//

%PERM_FILE_READ     = &H1  ' // user has read access
%PERM_FILE_WRITE    = &H2  ' // user has write access
%PERM_FILE_CREATE   = &H4  ' // user has create access

#ENDIF   ' #IF NOT %DEF(%LMFILE)
