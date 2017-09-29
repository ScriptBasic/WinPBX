' ########################################################################################
' Microsoft Windows
' File: LMaudit.inc
' Contents: API function prototypes and data structures for the NetAudit group of NT API functions
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%LMAUDIT_INC = 1

#IF NOT %DEF(%LMHLOGDEFINED)
    %LMHLOGDEFINED = 1

' // Size = 16 bytes
TYPE HLOG DWORD
   time       AS DWORD   ' DWORD time
   last_flags AS DWORD   ' DWORD last_flags
   offset     AS DWORD   ' DWORD offset
   rec_offset AS DWORD   ' DWORD rec_offset
END TYPE

%LOGFLAGS_FORWARD    = 0
%LOGFLAGS_BACKWARD   = &H1
%LOGFLAGS_SEEK       = &H2

#ENDIF

'//
'// Function Prototypes - Audit
'//

DECLARE FUNCTION NetAuditClear IMPORT "NETAPI32.DLL" ALIAS "NetAuditClear" ( _
   BYREF server AS WSTRINGZ _                           ' __in  LPCWSTR  server OPTIONAL
 , BYREF backupfile AS WSTRINGZ _                       ' __in  LPCWSTR  backupfile OPTIONAL
 , BYREF service AS WSTRINGZ _                          ' __in  LPCWSTR  service OPTIONAL  // WARNING: buggy support before LM 2.0C!!
 ) AS DWORD                                             ' NET_API_STATUS

DECLARE FUNCTION NetAuditRead IMPORT "NETAPI32.DLL" ALIAS "NetAuditRead" ( _
   BYREF server AS WSTRINGZ _                           ' __in  LPCWSTR server OPTIONAL
 , BYREF service AS WSTRINGZ _                          ' __in  LPCWSTR service OPTIONAL,  // WARNING: buggy support before LM 2.0C!!
 , BYREF auditloghandle AS HLOG _                       ' __in  LPHLOG  auditloghandle
 , BYVAL offset AS DWORD _                              ' __in  DWORD   offset
 , BYVAL reserved1 AS DWORD _                           ' __in  LPDWORD reserved1 OPTIONAL
 , BYVAL reserved2 AS DWORD _                           ' __in  DWORD   reserved2
 , BYVAL offsetflag AS DWORD _                          ' __in  DWORD   offsetflag
 , BYREF bufptr AS ANY _                                ' __out LPBYTE  *bufptr
 , BYVAL prefmaxlen AS DWORD _                          ' __in  DWORD   prefmaxlen
 , BYREF bytesread AS DWORD _                           ' __out LPDWORD bytesread
 , BYREF totalavailable AS DWORD _                      ' __out LPDWORD totalavailable
 ) AS DWORD                                             ' NET_API_STATUS

DECLARE FUNCTION NetAuditWrite IMPORT "NETAPI32.DLL" ALIAS "NetAuditWrite" ( _
   BYVAL type AS DWORD _                                ' __in  DWORD    type
 , BYVAL buf AS BYTE PTR _                              ' __in  LPBYTE   buf
 , BYVAL numbytes AS DWORD _                            ' __in  DWORD    numbytes
 , OPTIONAL BYREF service AS WSTRINGZ _                 ' __in  LPCWSTR  service OPTIONAL
 , OPTIONAL BYVAL reserved AS BYTE PTR _                ' __in  LPBYTE   reserved OPTIONAL
 ) AS DWORD                                             ' NET_API_STATUS

'//
'// Data Structures - Audit
'//

' // Size = 24 bytes
TYPE AUDIT_ENTRY DWORD
   ae_len         AS DWORD   ' DWORD          ae_len
   ae_reserved    AS DWORD   ' DWORD          ae_reserved
   ae_time        AS DWORD   ' DWORD          ae_time
   ae_type        AS DWORD   ' DWORD          ae_type
   ae_data_offset AS DWORD   ' DWORD          ae_data_offset  /* Offset from beginning address of audit_entry */
   ae_data_size   AS DWORD   ' DWORD          ae_data_size   // byte count of ae_data area (not incl pad).
END TYPE

'#define REVISED_AUDIT_ENTRY_STRUCT

' // Size = 4 bytes
TYPE AE_SRVSTATUS DWORD
   ae_sv_status AS DWORD   ' DWORD ae_sv_status
END TYPE

' // Size = 12 bytes
TYPE AE_SESSLOGON DWORD
   ae_so_compname  AS DWORD   ' DWORD ae_so_compname
   ae_so_username  AS DWORD   ' DWORD ae_so_username
   ae_so_privilege AS DWORD   ' DWORD ae_so_privilege
END TYPE

' // Size = 12 bytes
TYPE AE_SESSLOGOFF DWORD
   ae_sf_compname AS DWORD   ' DWORD ae_sf_compname
   ae_sf_username AS DWORD   ' DWORD ae_sf_username
   ae_sf_reason   AS DWORD   ' DWORD ae_sf_reason
END TYPE

' // Size = 8 bytes
TYPE AE_SESSPWERR DWORD
   ae_sp_compname AS DWORD   ' DWORD ae_sp_compname
   ae_sp_username AS DWORD   ' DWORD ae_sp_username
END TYPE

' // Size = 16 bytes
TYPE AE_CONNSTART DWORD
   ae_ct_compname AS DWORD   ' DWORD ae_ct_compname
   ae_ct_username AS DWORD   ' DWORD ae_ct_username
   ae_ct_netname  AS DWORD   ' DWORD ae_ct_netname
   ae_ct_connid   AS DWORD   ' DWORD ae_ct_connid
END TYPE

' // Size = 20 bytes
TYPE AE_CONNSTOP DWORD
   ae_cp_compname AS DWORD   ' DWORD          ae_cp_compname
   ae_cp_username AS DWORD   ' DWORD          ae_cp_username
   ae_cp_netname  AS DWORD   ' DWORD          ae_cp_netname
   ae_cp_connid   AS DWORD   ' DWORD          ae_cp_connid
   ae_cp_reason   AS DWORD   ' DWORD          ae_cp_reason
END TYPE

' // Size = 16 bytes
TYPE AE_CONNREJ DWORD
   ae_cr_compname AS DWORD   ' DWORD ae_cr_compname
   ae_cr_username AS DWORD   ' DWORD ae_cr_username
   ae_cr_netname  AS DWORD   ' DWORD ae_cr_netname
   ae_cr_reason   AS DWORD   ' DWORD ae_cr_reason
END TYPE

' // Size = 28 bytes
TYPE AE_RESACCESS DWORD
   ae_ra_compname   AS DWORD   ' DWORD ae_ra_compname
   ae_ra_username   AS DWORD   ' DWORD ae_ra_username
   ae_ra_resname    AS DWORD   ' DWORD ae_ra_resname
   ae_ra_operation  AS DWORD   ' DWORD ae_ra_operation
   ae_ra_returncode AS DWORD   ' DWORD ae_ra_returncode
   ae_ra_restype    AS DWORD   ' DWORD ae_ra_restype
   ae_ra_fileid     AS DWORD   ' DWORD ae_ra_fileid
END TYPE

' // Size = 16 bytes
TYPE AE_RESACCESSREJ DWORD
   ae_rr_compname  AS DWORD   ' DWORD ae_rr_compname
   ae_rr_username  AS DWORD   ' DWORD ae_rr_username
   ae_rr_resname   AS DWORD   ' DWORD ae_rr_resname
   ae_rr_operation AS DWORD   ' DWORD ae_rr_operation
END TYPE

' // Size = 24 bytes
TYPE AE_CLOSEFILE DWORD
   ae_cf_compname AS DWORD   ' DWORD ae_cf_compname
   ae_cf_username AS DWORD   ' DWORD ae_cf_username
   ae_cf_resname  AS DWORD   ' DWORD ae_cf_resname
   ae_cf_fileid   AS DWORD   ' DWORD ae_cf_fileid
   ae_cf_duration AS DWORD   ' DWORD ae_cf_duration
   ae_cf_reason   AS DWORD   ' DWORD ae_cf_reason
END TYPE

' // Size = 28 bytes
TYPE AE_SERVICESTAT DWORD
   ae_ss_compname  AS DWORD   ' DWORD ae_ss_compname
   ae_ss_username  AS DWORD   ' DWORD ae_ss_username
   ae_ss_svcname   AS DWORD   ' DWORD ae_ss_svcname
   ae_ss_status    AS DWORD   ' DWORD ae_ss_status
   ae_ss_code      AS DWORD   ' DWORD ae_ss_code
   ae_ss_text      AS DWORD   ' DWORD ae_ss_text
   ae_ss_returnval AS DWORD   ' DWORD ae_ss_returnval
END TYPE

' // Size = 20 bytes
TYPE AE_ACLMOD DWORD
   ae_am_compname AS DWORD   ' DWORD ae_am_compname
   ae_am_username AS DWORD   ' DWORD ae_am_username
   ae_am_resname  AS DWORD   ' DWORD ae_am_resname
   ae_am_action   AS DWORD   ' DWORD ae_am_action
   ae_am_datalen  AS DWORD   ' DWORD ae_am_datalen
END TYPE

' // Size = 24 bytes
TYPE AE_UASMOD DWORD
   ae_um_compname AS DWORD   ' DWORD ae_um_compname
   ae_um_username AS DWORD   ' DWORD ae_um_username
   ae_um_resname  AS DWORD   ' DWORD ae_um_resname
   ae_um_rectype  AS DWORD   ' DWORD ae_um_rectype
   ae_um_action   AS DWORD   ' DWORD ae_um_action
   ae_um_datalen  AS DWORD   ' DWORD ae_um_datalen
END TYPE

' // Size = 16 bytes
TYPE AE_NETLOGON DWORD
   ae_no_compname  AS DWORD   ' DWORD ae_no_compname
   ae_no_username  AS DWORD   ' DWORD ae_no_username
   ae_no_privilege AS DWORD   ' DWORD ae_no_privilege
   ae_no_authflags AS DWORD   ' DWORD ae_no_authflags
END TYPE

' // Size = 16 bytes
TYPE AE_NETLOGOFF DWORD
   ae_nf_compname  AS DWORD   ' DWORD ae_nf_compname
   ae_nf_username  AS DWORD   ' DWORD ae_nf_username
   ae_nf_reserved1 AS DWORD   ' DWORD ae_nf_reserved1
   ae_nf_reserved2 AS DWORD   ' DWORD ae_nf_reserved2
END TYPE

' // Size = 16 bytes
TYPE AE_ACCLIM DWORD
   ae_al_compname AS DWORD   ' DWORD ae_al_compname
   ae_al_username AS DWORD   ' DWORD ae_al_username
   ae_al_resname  AS DWORD   ' DWORD ae_al_resname
   ae_al_limit    AS DWORD   ' DWORD ae_al_limit
END TYPE

'#define ACTION_LOCKOUT          00
'#define ACTION_ADMINUNLOCK      01

%ACTION_LOCKOUT         = 00
%ACTION_ADMINUNLOCK     = 01

' // Size = 16 bytes
TYPE AE_LOCKOUT DWORD
   ae_lk_compname     AS DWORD  ' DWORD ae_lk_compname // Ptr to computername of client.
   ae_lk_username     AS DWORD  ' DWORD ae_lk_username // Ptr to username of client (NULL if same as computername).
   ae_lk_action       AS DWORD  ' DWORD ae_lk_action   // Action taken on account:
                                '                      // 0 means locked out, 1 means not.
   ae_lk_bad_pw_count AS DWORD  ' DWORD ae_lk_bad_pw_count // Bad password count at the time of lockout.
END TYPE

' // Size = 48 bytes
TYPE AE_GENERIC DWORD
   ae_ge_msgfile AS DWORD   ' DWORD ae_ge_msgfile
   ae_ge_msgnum  AS DWORD   ' DWORD ae_ge_msgnum
   ae_ge_params  AS DWORD   ' DWORD ae_ge_params
   ae_ge_param1  AS DWORD   ' DWORD ae_ge_param1
   ae_ge_param2  AS DWORD   ' DWORD ae_ge_param2
   ae_ge_param3  AS DWORD   ' DWORD ae_ge_param3
   ae_ge_param4  AS DWORD   ' DWORD ae_ge_param4
   ae_ge_param5  AS DWORD   ' DWORD ae_ge_param5
   ae_ge_param6  AS DWORD   ' DWORD ae_ge_param6
   ae_ge_param7  AS DWORD   ' DWORD ae_ge_param7
   ae_ge_param8  AS DWORD   ' DWORD ae_ge_param8
   ae_ge_param9  AS DWORD   ' DWORD ae_ge_param9
END TYPE

'//
'// Special Values and Constants - Audit
'//

'//
'//    Audit entry types (field ae_type in audit_entry).
'//

%AE_SRVSTATUS    = 0
%AE_SESSLOGON    = 1
%AE_SESSLOGOFF   = 2
%AE_SESSPWERR    = 3
%AE_CONNSTART    = 4
%AE_CONNSTOP     = 5
%AE_CONNREJ      = 6
%AE_RESACCESS    = 7
%AE_RESACCESSREJ = 8
%AE_CLOSEFILE    = 9
%AE_SERVICESTAT  = 11
%AE_ACLMOD       = 12
%AE_UASMOD       = 13
%AE_NETLOGON     = 14
%AE_NETLOGOFF    = 15
%AE_NETLOGDENIED = 16
%AE_ACCLIMITEXCD = 17
%AE_RESACCESS2   = 18
%AE_ACLMODFAIL   = 19
%AE_LOCKOUT      = 20
%AE_GENERIC_TYPE = 21

'//
'//   Values for ae_ss_status field of ae_srvstatus.
'//

%AE_SRVSTART  = 0
%AE_SRVPAUSED = 1
%AE_SRVCONT   = 2
%AE_SRVSTOP   = 3

'//
'//    Values for ae_so_privilege field of ae_sesslogon.
'//

%AE_GUEST = 0
%AE_USER  = 1
%AE_ADMIN = 2

'//
'//   Values for various ae_XX_reason fields.
'//

%AE_NORMAL        = 0
%AE_USERLIMIT     = 0
%AE_GENERAL       = 0
%AE_ERROR         = 1
%AE_SESSDIS       = 1
%AE_BADPW         = 1
%AE_AUTODIS       = 2
%AE_UNSHARE       = 2
%AE_ADMINPRIVREQD = 2
%AE_ADMINDIS      = 3
%AE_NOACCESSPERM  = 3
%AE_ACCRESTRICT   = 4

%AE_NORMAL_CLOSE = 0
%AE_SES_CLOSE    = 1
%AE_ADMIN_CLOSE  = 2

'//
'// Values for xx_subreason fields.
'//

%AE_LIM_UNKNOWN     = 0
%AE_LIM_LOGONHOURS  = 1
%AE_LIM_EXPIRED     = 2
%AE_LIM_INVAL_WKSTA = 3
%AE_LIM_DISABLED    = 4
%AE_LIM_DELETED     = 5

'//
'// Values for xx_action fields
'//

%AE_MOD    = 0
%AE_DELETE = 1
%AE_ADD    = 2

'//
'// Types of UAS record for um_rectype field
'//

%AE_UAS_USER   = 0
%AE_UAS_GROUP  = 1
%AE_UAS_MODALS = 2

'//
'// Bitmasks for auditing events
'//

%SVAUD_SERVICE       = &H1???
%SVAUD_GOODSESSLOGON = &H6???
%SVAUD_BADSESSLOGON  = &H18???
%SVAUD_SESSLOGON     = %SVAUD_GOODSESSLOGON OR %SVAUD_BADSESSLOGON
%SVAUD_GOODNETLOGON  = &H60???
%SVAUD_BADNETLOGON   = &H180???
%SVAUD_NETLOGON      = %SVAUD_GOODNETLOGON OR %SVAUD_BADNETLOGON
%SVAUD_LOGON         = %SVAUD_NETLOGON OR %SVAUD_SESSLOGON
%SVAUD_GOODUSE       = &H600???
%SVAUD_BADUSE        = &H1800???
%SVAUD_USE           = %SVAUD_GOODUSE OR %SVAUD_BADUSE
%SVAUD_USERLIST      = &H2000???
%SVAUD_PERMISSIONS   = &H4000???
%SVAUD_RESOURCE      = &H8000???
%SVAUD_LOGONLIM      = &H00010000???

'//
'// Resource access audit bitmasks.
'//

%AA_AUDIT_ALL = &H0001???
%AA_A_OWNER   = &H0004???
%AA_CLOSE     = &H0008???
%AA_S_OPEN    = &H0010???
%AA_S_WRITE   = &H0020???
%AA_S_CREATE  = &H0020???
%AA_S_DELETE  = &H0040???
%AA_S_ACL     = &H0080???
%AA_S_ALL     = %AA_S_OPEN OR %AA_S_WRITE OR %AA_S_DELETE OR %AA_S_ACL
%AA_F_OPEN    = &H0100???
%AA_F_WRITE   = &H0200???
%AA_F_CREATE  = &H0200???
%AA_F_DELETE  = &H0400???
%AA_F_ACL     = &H0800???
%AA_F_ALL     = %AA_F_OPEN OR %AA_F_WRITE OR %AA_F_DELETE OR %AA_F_ACL

'// Pinball-specific
%AA_A_OPEN    = &H1000???
%AA_A_WRITE   = &H2000???
%AA_A_CREATE  = &H2000???
%AA_A_DELETE  = &H4000???
%AA_A_ACL     = &H8000???
%AA_A_ALL     = %AA_F_OPEN OR %AA_F_WRITE OR %AA_F_DELETE OR %AA_F_ACL
