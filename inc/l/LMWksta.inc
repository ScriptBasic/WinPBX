' ########################################################################################
' Microsoft Windows
' File: LMWksta.inc
' Contents: Structures, function prototypes, and definitions for the NetWorkstation and
' NetWkstaTransport API.
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%LMWKSTA_INC = 1

#INCLUDE ONCE "lmcons.inc"
#INCLUDE ONCE "lmuseflg.inc"

'//
'// Function Prototypes
'//

DECLARE FUNCTION NetWkstaGetInfo IMPORT "NETAPI32.DLL" ALIAS "NetWkstaGetInfo" ( _
   BYREF servername AS WSTRINGZ _                       ' __in  LMSTR   servername OPTIONAL
 , BYVAL level AS DWORD _                               ' __in  DWORD   level
 , BYREF bufptr AS ANY _                                ' __out LPBYTE  *bufptr
 ) AS DWORD                                             ' NET_API_STATUS

DECLARE FUNCTION NetWkstaSetInfo IMPORT "NETAPI32.DLL" ALIAS "NetWkstaSetInfo" ( _
   BYREF servername AS WSTRINGZ _                       ' __in  LMSTR   servername OPTIONAL
 , BYVAL level AS DWORD _                               ' __in  DWORD   level
 , BYVAL buffer AS BYTE PTR _                           ' __in  LPBYTE  buffer
 , BYREF parm_err AS DWORD _                            ' __out LPDWORD parm_err OPTIONAL
 ) AS DWORD                                             ' NET_API_STATUS

DECLARE FUNCTION NetWkstaUserGetInfo IMPORT "NETAPI32.DLL" ALIAS "NetWkstaUserGetInfo" ( _
   BYREF reserved AS WSTRINGZ _                         ' __in  LMSTR   reserved
 , BYVAL level AS DWORD _                               ' __in  DWORD   level
 , BYREF bufptr AS ANY _                                ' __out LPBYTE  *bufptr
 ) AS DWORD                                             ' NET_API_STATUS

DECLARE FUNCTION NetWkstaUserSetInfo IMPORT "NETAPI32.DLL" ALIAS "NetWkstaUserSetInfo" ( _
   BYREF reserved AS WSTRINGZ _                         ' __in  LMSTR  reserved
 , BYVAL level AS DWORD _                               ' __in  DWORD   level
 , BYVAL buf AS BYTE PTR _                              ' __inNetWkstaUserEnum LPBYTE  buf
 , BYREF parm_err AS DWORD _                            ' __out LPDWORD parm_err OPTIONAL
 ) AS DWORD                                             ' NET_API_STATUS

DECLARE FUNCTION NetWkstaUserEnum IMPORT "NETAPI32.DLL" ALIAS "NetWkstaUserEnum" ( _
   BYREF servername AS WSTRINGZ _                       ' __in  LMSTR       servername OPTIONAL
 , BYVAL level AS DWORD _                               ' __in  DWORD       level
 , BYREF bufptr AS ANY _                                ' __out LPBYTE      *bufptr
 , BYVAL prefmaxlen AS DWORD _                          ' __in  DWORD       prefmaxlen
 , BYREF entriesread AS DWORD _                         ' __out LPDWORD     entriesread
 , BYREF totalentries AS DWORD _                        ' __out LPDWORD     totalentries
 , BYREF resumehandle AS DWORD _                        ' __in_out LPDWORD resumehandle OPTIONAL
 ) AS DWORD                                             ' NET_API_STATUS

DECLARE FUNCTION NetWkstaTransportAdd IMPORT "NETAPI32.DLL" ALIAS "NetWkstaTransportAdd" ( _
   BYREF servername AS WSTRINGZ _                       ' __in  LMSTR   servername OPTIONAL
 , BYVAL level AS DWORD _                               ' __in  DWORD   level
 , BYVAL buf AS BYTE PTR _                              ' __in  LPBYTE  buf
 , BYREF parm_err AS DWORD _                            ' __out LPDWORD parm_err
 ) AS DWORD                                             ' NET_API_STATUS

DECLARE FUNCTION NetWkstaTransportDel IMPORT "NETAPI32.DLL" ALIAS "NetWkstaTransportDel" ( _
   BYREF servername AS WSTRINGZ _                       ' __in  LMSTR   servername OPTIONAL
 , BYREF transportname AS WSTRINGZ _                    ' __in  LMSTR   transportname
 , BYVAL ucond AS DWORD _                               ' __in  DWORD   ucond
 ) AS DWORD                                             ' NET_API_STATUS

DECLARE FUNCTION NetWkstaTransportEnum IMPORT "NETAPI32.DLL" ALIAS "NetWkstaTransportEnum" ( _
   BYREF servername AS WSTRINGZ _                       ' __in  LMSTR       servername OPTIONAL
 , BYVAL level AS DWORD _                               ' __in  DWORD       level
 , BYREF bufptr AS ANY _                                ' __out LPBYTE      *bufptr
 , BYVAL prefmaxlen AS DWORD _                          ' __in  DWORD       prefmaxlen
 , BYREF entriesread AS DWORD _                         ' __out LPDWORD     entriesread
 , BYREF totalentries AS DWORD _                        ' __out LPDWORD     totalentries
 , BYREF resumehandle AS DWORD _                        ' __in  OUT LPDWORD resumehandle OPTIONAL
 ) AS DWORD                                             ' NET_API_STATUS

'//
'//  Data Structures
'//

'//
'// NetWkstaGetInfo and NetWkstaSetInfo
'//

'//
'// NetWkstaGetInfo only.  System information - guest access
'//

' // Size = 20 bytes
TYPE WKSTA_INFO_100 DWORD
   wki100_platform_id  AS DWORD          ' DWORD wki100_platform_id
   wki100_computername AS WSTRINGZ PTR   ' LMSTR wki100_computername
   wki100_langroup     AS WSTRINGZ PTR   ' LMSTR wki100_langroup
   wki100_ver_major    AS DWORD          ' DWORD wki100_ver_major
   wki100_ver_minor    AS DWORD          ' DWORD wki100_ver_minor
END TYPE

'//
'// NetWkstaGetInfo only.  System information - user access
'//

' // Size = 24 bytes
TYPE WKSTA_INFO_101 DWORD
   wki101_platform_id  AS DWORD          ' DWORD wki101_platform_id
   wki101_computername AS WSTRINGZ PTR   ' LMSTR wki101_computername
   wki101_langroup     AS WSTRINGZ PTR   ' LMSTR wki101_langroup
   wki101_ver_major    AS DWORD          ' DWORD wki101_ver_major
   wki101_ver_minor    AS DWORD          ' DWORD wki101_ver_minor
   wki101_lanroot      AS WSTRINGZ PTR   ' LMSTR wki101_lanroot
END TYPE

'//
'// NetWkstaGetInfo only.  System information - admin or operator access
'//

' // Size = 28 bytes
TYPE WKSTA_INFO_102 DWORD
   wki102_platform_id     AS DWORD          ' DWORD wki102_platform_id
   wki102_computername    AS WSTRINGZ PTR   ' LMSTR wki102_computername
   wki102_langroup        AS WSTRINGZ PTR   ' LMSTR wki102_langroup
   wki102_ver_major       AS DWORD          ' DWORD wki102_ver_major
   wki102_ver_minor       AS DWORD          ' DWORD wki102_ver_minor
   wki102_lanroot         AS WSTRINGZ PTR   ' LMSTR wki102_lanroot
   wki102_logged_on_users AS DWORD          ' DWORD wki102_logged_on_users
END TYPE

'//
'// Down-level NetWkstaGetInfo and NetWkstaSetInfo.
'//
'// DOS specific workstation information -
'//    admin or domain operator access
'//

' // Size = 80 bytes
TYPE WKSTA_INFO_302 DWORD
   wki302_char_wait                AS DWORD          ' DWORD   wki302_char_wait
   wki302_collection_time          AS DWORD          ' DWORD   wki302_collection_time
   wki302_maximum_collection_count AS DWORD          ' DWORD   wki302_maximum_collection_count
   wki302_keep_conn                AS DWORD          ' DWORD   wki302_keep_conn
   wki302_keep_search              AS DWORD          ' DWORD   wki302_keep_search
   wki302_max_cmds                 AS DWORD          ' DWORD   wki302_max_cmds
   wki302_num_work_buf             AS DWORD          ' DWORD   wki302_num_work_buf
   wki302_siz_work_buf             AS DWORD          ' DWORD   wki302_siz_work_buf
   wki302_max_wrk_cache            AS DWORD          ' DWORD   wki302_max_wrk_cache
   wki302_sess_timeout             AS DWORD          ' DWORD   wki302_sess_timeout
   wki302_siz_error                AS DWORD          ' DWORD   wki302_siz_error
   wki302_num_alerts               AS DWORD          ' DWORD   wki302_num_alerts
   wki302_num_services             AS DWORD          ' DWORD   wki302_num_services
   wki302_errlog_sz                AS DWORD          ' DWORD   wki302_errlog_sz
   wki302_print_buf_time           AS DWORD          ' DWORD   wki302_print_buf_time
   wki302_num_char_buf             AS DWORD          ' DWORD   wki302_num_char_buf
   wki302_siz_char_buf             AS DWORD          ' DWORD   wki302_siz_char_buf
   wki302_wrk_heuristics           AS WSTRINGZ PTR   ' LMSTR   wki302_wrk_heuristics
   wki302_mailslots                AS DWORD          ' DWORD   wki302_mailslots
   wki302_num_dgram_buf            AS DWORD          ' DWORD   wki302_num_dgram_buf
END TYPE

'//
'// Down-level NetWkstaGetInfo and NetWkstaSetInfo
'//
'// OS/2 specific workstation information -
'//    admin or domain operator access
'//
' // Size = 84 bytes
TYPE WKSTA_INFO_402 DWORD
   wki402_char_wait                AS DWORD
   wki402_collection_time          AS DWORD
   wki402_maximum_collection_count AS DWORD
   wki402_keep_conn                AS DWORD
   wki402_keep_search              AS DWORD
   wki402_max_cmds                 AS DWORD
   wki402_num_work_buf             AS DWORD
   wki402_siz_work_buf             AS DWORD
   wki402_max_wrk_cache            AS DWORD
   wki402_sess_timeout             AS DWORD
   wki402_siz_error                AS DWORD
   wki402_num_alerts               AS DWORD
   wki402_num_services             AS DWORD
   wki402_errlog_sz                AS DWORD
   wki402_print_buf_time           AS DWORD
   wki402_num_char_buf             AS DWORD
   wki402_siz_char_buf             AS DWORD
   wki402_wrk_heuristics           AS WSTRINGZ PTR
   wki402_mailslots                AS DWORD
   wki402_num_dgram_buf            AS DWORD
   wki402_max_threads              AS DWORD
END TYPE

'//
'// Same-level NetWkstaGetInfo and NetWkstaSetInfo.
'//
'// NT specific workstation information -
'//    admin or domain operator access
'//
' // Size = 140 bytes
TYPE WKSTA_INFO_502 DWORD
   wki502_char_wait                              AS DWORD
   wki502_collection_time                        AS DWORD
   wki502_maximum_collection_count               AS DWORD
   wki502_keep_conn                              AS DWORD
   wki502_max_cmds                               AS DWORD
   wki502_sess_timeout                           AS DWORD
   wki502_siz_char_buf                           AS DWORD
   wki502_max_threads                            AS DWORD

   wki502_lock_quota                             AS DWORD
   wki502_lock_increment                         AS DWORD
   wki502_lock_maximum                           AS DWORD
   wki502_pipe_increment                         AS DWORD
   wki502_pipe_maximum                           AS DWORD
   wki502_cache_file_timeout                     AS DWORD
   wki502_dormant_file_limit                     AS DWORD
   wki502_read_ahead_throughput                  AS DWORD

   wki502_num_mailslot_buffers                   AS DWORD
   wki502_num_srv_announce_buffers               AS DWORD
   wki502_max_illegal_datagram_events            AS DWORD
   wki502_illegal_datagram_event_reset_frequency AS DWORD
   wki502_log_election_packets                   AS LONG

   wki502_use_opportunistic_locking              AS LONG
   wki502_use_unlock_behind                      AS LONG
   wki502_use_close_behind                       AS LONG
   wki502_buf_named_pipes                        AS LONG
   wki502_use_lock_read_unlock                   AS LONG
   wki502_utilize_nt_caching                     AS LONG
   wki502_use_raw_read                           AS LONG
   wki502_use_raw_write                          AS LONG
   wki502_use_write_raw_data                     AS LONG
   wki502_use_encryption                         AS LONG
   wki502_buf_files_deny_write                   AS LONG
   wki502_buf_read_only_files                    AS LONG
   wki502_force_core_create_mode                 AS LONG
   wki502_use_512_byte_max_transfer              AS LONG
END TYPE


'//
'// The following info-levels are only valid for NetWkstaSetInfo
'//

'//
'// The following levels are supported on down-level systems (LAN Man 2.x)
'// as well as NT systems:
'//

' // Size = 4 bytes
TYPE WKSTA_INFO_1010 DWORD
   wki1010_char_wait AS DWORD   ' DWORD wki1010_char_wait
END TYPE

' // Size = 4 bytes
TYPE WKSTA_INFO_1011 DWORD
   wki1011_collection_time AS DWORD   ' DWORD wki1011_collection_time
END TYPE

' // Size = 4 bytes
TYPE WKSTA_INFO_1012 DWORD
   wki1012_maximum_collection_count AS DWORD   ' DWORD wki1012_maximum_collection_count
END TYPE

'//
'// The following level are supported on down-level systems (LAN Man 2.x)
'// only:
'//

' // Size = 4 bytes
TYPE WKSTA_INFO_1027 DWORD
   wki1027_errlog_sz AS DWORD   ' DWORD wki1027_errlog_sz
END TYPE

' // Size = 4 bytes
TYPE WKSTA_INFO_1028 DWORD
   wki1028_print_buf_time AS DWORD   ' DWORD wki1028_print_buf_time
END TYPE

' // Size = 4 bytes
TYPE WKSTA_INFO_1032 DWORD
   wki1032_wrk_heuristics AS DWORD   ' DWORD wki1032_wrk_heuristics
END TYPE

'//
'// The following levels are settable on NT systems, and have no
'// effect on down-level systems (i.e. LANMan 2.x) since these
'// fields cannot be set on them:
'//

' // Size = 4 bytes
TYPE WKSTA_INFO_1013 DWORD
   wki1013_keep_conn AS DWORD   ' DWORD wki1013_keep_conn
END TYPE

' // Size = 4 bytes
TYPE WKSTA_INFO_1018 DWORD
   wki1018_sess_timeout AS DWORD   ' DWORD wki1018_sess_timeout
END TYPE

' // Size = 4 bytes
TYPE WKSTA_INFO_1023 DWORD
   wki1023_siz_char_buf AS DWORD   ' DWORD wki1023_siz_char_buf
END TYPE

' // Size = 4 bytes
TYPE WKSTA_INFO_1033 DWORD
   wki1033_max_threads AS DWORD   ' DWORD wki1033_max_threads
END TYPE

'//
'// The following levels are only supported on NT systems:
'//

' // Size = 4 bytes
TYPE WKSTA_INFO_1041 DWORD
   wki1041_lock_quota AS DWORD   ' DWORD wki1041_lock_quota
END TYPE

' // Size = 4 bytes
TYPE WKSTA_INFO_1042 DWORD
   wki1042_lock_increment AS DWORD   ' DWORD wki1042_lock_increment
END TYPE

' // Size = 4 bytes
TYPE WKSTA_INFO_1043 DWORD
   wki1043_lock_maximum AS DWORD   ' DWORD wki1043_lock_maximum
END TYPE

' // Size = 4 bytes
TYPE WKSTA_INFO_1044 DWORD
   wki1044_pipe_increment AS DWORD   ' DWORD wki1044_pipe_increment
END TYPE

' // Size = 4 bytes
TYPE WKSTA_INFO_1045 DWORD
   wki1045_pipe_maximum AS DWORD   ' DWORD wki1045_pipe_maximum
END TYPE

' // Size = 4 bytes
TYPE WKSTA_INFO_1046 DWORD
   wki1046_dormant_file_limit AS DWORD   ' DWORD wki1046_dormant_file_limit
END TYPE

' // Size = 4 bytes
TYPE WKSTA_INFO_1047 DWORD
   wki1047_cache_file_timeout AS DWORD   ' DWORD wki1047_cache_file_timeout
END TYPE

' // Size = 4 bytes
TYPE WKSTA_INFO_1048 DWORD
   wki1048_use_opportunistic_locking AS LONG   ' BOOL wki1048_use_opportunistic_locking
END TYPE

' // Size = 4 bytes
TYPE WKSTA_INFO_1049 DWORD
   wki1049_use_unlock_behind AS LONG   ' BOOL wki1049_use_unlock_behind
END TYPE

' // Size = 4 bytes
TYPE WKSTA_INFO_1050 DWORD
   wki1050_use_close_behind AS LONG   ' BOOL wki1050_use_close_behind
END TYPE

' // Size = 4 bytes
TYPE WKSTA_INFO_1051 DWORD
   wki1051_buf_named_pipes AS LONG   ' BOOL wki1051_buf_named_pipes
END TYPE

' // Size = 4 bytes
TYPE WKSTA_INFO_1052 DWORD
   wki1052_use_lock_read_unlock AS LONG   ' BOOL wki1052_use_lock_read_unlock
END TYPE

' // Size = 4 bytes
TYPE WKSTA_INFO_1053 DWORD
   wki1053_utilize_nt_caching AS LONG   ' BOOL wki1053_utilize_nt_caching
END TYPE

' // Size = 4 bytes
TYPE WKSTA_INFO_1054 DWORD
   wki1054_use_raw_read AS LONG   ' BOOL wki1054_use_raw_read
END TYPE

' // Size = 4 bytes
TYPE WKSTA_INFO_1055 DWORD
   wki1055_use_raw_write AS LONG   ' BOOL wki1055_use_raw_write
END TYPE

' // Size = 4 bytes
TYPE WKSTA_INFO_1056 DWORD
   wki1056_use_write_raw_data AS LONG   ' BOOL wki1056_use_write_raw_data
END TYPE

' // Size = 4 bytes
TYPE WKSTA_INFO_1057 DWORD
   wki1057_use_encryption AS LONG   ' BOOL wki1057_use_encryption
END TYPE

' // Size = 4 bytes
TYPE WKSTA_INFO_1058 DWORD
   wki1058_buf_files_deny_write AS LONG   ' BOOL wki1058_buf_files_deny_write
END TYPE

' // Size = 4 bytes
TYPE WKSTA_INFO_1059 DWORD
   wki1059_buf_read_only_files AS LONG   ' BOOL wki1059_buf_read_only_files
END TYPE

' // Size = 4 bytes
TYPE WKSTA_INFO_1060 DWORD
   wki1060_force_core_create_mode AS LONG   ' BOOL wki1060_force_core_create_mode
END TYPE

' // Size = 4 bytes
TYPE WKSTA_INFO_1061 DWORD
   wki1061_use_512_byte_max_transfer AS LONG   ' BOOL wki1061_use_512_byte_max_transfer
END TYPE

' // Size = 4 bytes
TYPE WKSTA_INFO_1062 DWORD
   wki1062_read_ahead_throughput AS DWORD   ' WORD wki1062_read_ahead_throughput
END TYPE

'//
'// NetWkstaUserGetInfo (local only) and NetWkstaUserEnum -
'//     no access restrictions.
'//

' // Size = 4 bytes
TYPE WKSTA_USER_INFO_0 DWORD
   wkui0_username AS WSTRINGZ PTR   ' LMSTR wkui0_username
END TYPE

'//
'// NetWkstaUserGetInfo (local only) and NetWkstaUserEnum -
'//     no access restrictions.
'//

' // Size = 16 bytes
TYPE WKSTA_USER_INFO_1 DWORD
   wkui1_username     AS WSTRINGZ PTR   ' LMSTR wkui1_username
   wkui1_logon_domain AS WSTRINGZ PTR   ' LMSTR wkui1_logon_domain
   wkui1_oth_domains  AS WSTRINGZ PTR   ' LMSTR wkui1_oth_domains
   wkui1_logon_server AS WSTRINGZ PTR   ' LMSTR wkui1_logon_server
END TYPE

'//
'// NetWkstaUserSetInfo - local access.
'//

' // Size = 16 bytes
TYPE WKSTA_USER_INFO_1101 DWORD
   wkui1101_oth_domains AS WSTRINGZ PTR   ' LMSTR wkui1101_oth_domains
END TYPE

'//
'// NetWkstaTransportAdd - admin access
'//

' // Size = 20 bytes
TYPE WKSTA_TRANSPORT_INFO_0 DWORD
   wkti0_quality_of_service AS DWORD          ' DWORD wkti0_quality_of_service
   wkti0_number_of_vcs      AS DWORD          ' DWORD wkti0_number_of_vcs
   wkti0_transport_name     AS WSTRINGZ PTR   ' LMSTR wkti0_transport_name
   wkti0_transport_address  AS WSTRINGZ PTR   ' LMSTR wkti0_transport_address
   wkti0_wan_ish            AS LONG           ' BOOL  wkti0_wan_ish
END TYPE

'//
'// Special Values and Constants
'//

'//
'//  Identifiers for use as NetWkstaSetInfo parmnum parameter
'//

'//
'// One of these values indicates the parameter within an information
'// structure that is invalid when ERROR_INVALID_PARAMETER is returned by
'// NetWkstaSetInfo.
'//

%WKSTA_PLATFORM_ID_PARMNUM             = 100
%WKSTA_COMPUTERNAME_PARMNUM            = 1
%WKSTA_LANGROUP_PARMNUM                = 2
%WKSTA_VER_MAJOR_PARMNUM               = 4
%WKSTA_VER_MINOR_PARMNUM               = 5
%WKSTA_LOGGED_ON_USERS_PARMNUM         = 6
%WKSTA_LANROOT_PARMNUM                 = 7
%WKSTA_LOGON_DOMAIN_PARMNUM            = 8
%WKSTA_LOGON_SERVER_PARMNUM            = 9
%WKSTA_CHARWAIT_PARMNUM                = 10  ' Supported by down-level.
%WKSTA_CHARTIME_PARMNUM                = 11  ' Supported by down-level.
%WKSTA_CHARCOUNT_PARMNUM               = 12  ' Supported by down-level.
%WKSTA_KEEPCONN_PARMNUM                = 13
%WKSTA_KEEPSEARCH_PARMNUM              = 14
%WKSTA_MAXCMDS_PARMNUM                 = 15
%WKSTA_NUMWORKBUF_PARMNUM              = 16
%WKSTA_MAXWRKCACHE_PARMNUM             = 17
%WKSTA_SESSTIMEOUT_PARMNUM             = 18
%WKSTA_SIZERROR_PARMNUM                = 19
%WKSTA_NUMALERTS_PARMNUM               = 20
%WKSTA_NUMSERVICES_PARMNUM             = 21
%WKSTA_NUMCHARBUF_PARMNUM              = 22
%WKSTA_SIZCHARBUF_PARMNUM              = 23
%WKSTA_ERRLOGSZ_PARMNUM                = 27  ' Supported by down-level.
%WKSTA_PRINTBUFTIME_PARMNUM            = 28  ' Supported by down-level.
%WKSTA_SIZWORKBUF_PARMNUM              = 29
%WKSTA_MAILSLOTS_PARMNUM               = 30
%WKSTA_NUMDGRAMBUF_PARMNUM             = 31
%WKSTA_WRKHEURISTICS_PARMNUM           = 32  ' Supported by down-level.
%WKSTA_MAXTHREADS_PARMNUM              = 33

%WKSTA_LOCKQUOTA_PARMNUM               = 41
%WKSTA_LOCKINCREMENT_PARMNUM           = 42
%WKSTA_LOCKMAXIMUM_PARMNUM             = 43
%WKSTA_PIPEINCREMENT_PARMNUM           = 44
%WKSTA_PIPEMAXIMUM_PARMNUM             = 45
%WKSTA_DORMANTFILELIMIT_PARMNUM        = 46
%WKSTA_CACHEFILETIMEOUT_PARMNUM        = 47
%WKSTA_USEOPPORTUNISTICLOCKING_PARMNUM = 48
%WKSTA_USEUNLOCKBEHIND_PARMNUM         = 49
%WKSTA_USECLOSEBEHIND_PARMNUM          = 50
%WKSTA_BUFFERNAMEDPIPES_PARMNUM        = 51
%WKSTA_USELOCKANDREADANDUNLOCK_PARMNUM = 52
%WKSTA_UTILIZENTCACHING_PARMNUM        = 53
%WKSTA_USERAWREAD_PARMNUM              = 54
%WKSTA_USERAWWRITE_PARMNUM             = 55
%WKSTA_USEWRITERAWWITHDATA_PARMNUM     = 56
%WKSTA_USEENCRYPTION_PARMNUM           = 57
%WKSTA_BUFFILESWITHDENYWRITE_PARMNUM   = 58
%WKSTA_BUFFERREADONLYFILES_PARMNUM     = 59
%WKSTA_FORCECORECREATEMODE_PARMNUM     = 60
%WKSTA_USE512BYTESMAXTRANSFER_PARMNUM  = 61
%WKSTA_READAHEADTHRUPUT_PARMNUM        = 62

'//
'// One of these values indicates the parameter within an information
'// structure that is invalid when ERROR_INVALID_PARAMETER is returned by
'// NetWkstaUserSetInfo.
'//

%WKSTA_OTH_DOMAINS_PARMNUM             = 101


'//
'// One of these values indicates the parameter within an information
'// structure that is invalid when ERROR_INVALID_PARAMETER is returned by
'// NetWkstaTransportAdd.
'//

%TRANSPORT_QUALITYOFSERVICE_PARMNUM    = 201
%TRANSPORT_NAME_PARMNUM                = 202
