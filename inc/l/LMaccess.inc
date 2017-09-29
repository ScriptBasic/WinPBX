' ########################################################################################
' Microsoft Windows
' File: LMaccess.inc
' Contents: Structures, function prototypes, and definitions for the NetUser, NetUserModals,
' NetGroup, NetAccess, and NetLogon API.
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE

'//
'// User Class
'//

#IF NOT %DEF(%LMUSER)
    %LMUSER = 1

#INCLUDE ONCE "windows.inc"
#INCLUDE ONCE "lmcons.inc"

'//
'// Function Prototypes - User
'//

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION NetUserAdd LIB "NetAPI32.dll" ALIAS "NetUserAdd" ( _
    servername       AS WSTRINGZ, _
    BYVAL level      AS DWORD, _
    BYVAL buf        AS BYTE PTR, _
    parm_err         AS DWORD _
    ) AS DWORD
#ELSE
DECLARE FUNCTION NetUserAdd IMPORT "NETAPI32.DLL" ALIAS "NetUserAdd" ( _
   BYREF servername AS WSTRINGZ _                       ' __in  LPCWSTR    servername OPTIONAL
 , BYVAL level AS DWORD _                               ' __in  DWORD      level
 , BYREF buf AS ANY _                                   ' __in  LPBYTE     buf
 , BYREF parm_err AS DWORD _                            ' __out LPDWORD    parm_err OPTIONAL
 ) AS DWORD                                             ' NET_API_STATUS
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION NetUserEnum LIB "NetAPI32.dll" ALIAS "NetUserEnum" ( _
    servername       AS WSTRINGZ, _
    BYVAL level      AS DWORD, _
    BYVAL filter     AS DWORD, _
    BYVAL bufptr     AS BYTE PTR, _
    BYVAL prefmaxlen AS DWORD, _
    entriesread      AS DWORD, _
    totalentries     AS DWORD, _
    resume_handle    AS DWORD _
    ) AS DWORD
#ELSE
DECLARE FUNCTION NetUserEnum IMPORT "NETAPI32.DLL" ALIAS "NetUserEnum" ( _
   BYREF servername AS WSTRINGZ _                       ' __in  LPCWSTR    servername OPTIONAL
 , BYVAL level AS DWORD _                               ' __in  DWORD      level
 , BYVAL filter AS DWORD _                              ' __in  DWORD      filter
 , BYREF bufptr AS ANY _                                ' __out LPBYTE     *bufptr
 , BYVAL prefmaxlen AS DWORD _                          ' __in  DWORD      prefmaxlen
 , BYREF entriesread AS DWORD _                         ' __out LPDWORD    entriesread
 , BYREF totalentries AS DWORD _                        ' __out LPDWORD    totalentries
 , BYREF resume_handle AS DWORD _                       ' __in_out LPDWORD resume_handle OPTIONAL
 ) AS DWORD                                             ' NET_API_STATUS
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION NetUserGetInfo LIB "NetAPI32.dll" ALIAS "NetUserGetInfo" ( _
    servername       AS WSTRINGZ, _
    username         AS WSTRINGZ, _
    BYVAL level      AS DWORD, _
    BYVAL bufptr     AS BYTE PTR _
    ) AS DWORD
#ELSE
DECLARE FUNCTION NetUserGetInfo IMPORT "NETAPI32.DLL" ALIAS "NetUserGetInfo" ( _
   BYREF servername AS WSTRINGZ _                       ' __in  LPCWSTR    servername OPTIONAL
 , BYREF username AS WSTRINGZ _                         ' __in  LPCWSTR    username
 , BYVAL level AS DWORD _                               ' __in  DWORD      level
 , BYREF bufptr AS ANY _                                ' __out LPBYTE     *bufptr
 ) AS DWORD                                             ' NET_API_STATUS
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION NetUserSetInfo LIB "NetAPI32.dll" ALIAS "NetUserSetInfo" ( _
    servername       AS WSTRINGZ, _
    username         AS WSTRINGZ, _
    BYVAL level      AS DWORD, _
    BYVAL buf        AS BYTE PTR, _
    parm_err         AS DWORD _
    ) AS DWORD
#ELSE
DECLARE FUNCTION NetUserSetInfo IMPORT "NETAPI32.DLL" ALIAS "NetUserSetInfo" ( _
   BYREF servername AS WSTRINGZ _                       ' __in  LPCWSTR   servername OPTIONAL
 , BYREF username AS WSTRINGZ _                         ' __in  LPCWSTR   username
 , BYVAL level AS DWORD _                               ' __in  DWORD     level
 , BYREF buf AS ANY _                                   ' __in  LPBYTE    buf
 , BYREF parm_err AS DWORD _                            ' __out LPDWORD   parm_err OPTIONAL
 ) AS DWORD                                             ' NET_API_STATUS
#ENDIF

DECLARE FUNCTION NetUserDel IMPORT "NETAPI32.DLL" ALIAS "NetUserDel" ( _
   BYREF servername AS WSTRINGZ _                       ' __in  LPCWSTR    servername OPTIONAL
 , BYREF username AS WSTRINGZ _                         ' __in  LPCWSTR    username
 ) AS DWORD                                             ' NET_API_STATUS

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION NetUserGetGroups LIB "NetAPI32.dll" ALIAS "NetUserGetGroups" ( _
    servername       AS WSTRINGZ, _
    username         AS WSTRINGZ, _
    BYVAL level      AS DWORD, _
    BYVAL bufptr     AS BYTE PTR, _
    BYVAL prefmaxlen AS DWORD, _
    entriesread      AS DWORD, _
    totalentries     AS DWORD _
    ) AS DWORD
#ELSE
DECLARE FUNCTION NetUserGetGroups IMPORT "NETAPI32.DLL" ALIAS "NetUserGetGroups" ( _
   BYREF servername AS WSTRINGZ _                       ' __in  LPCWSTR   servername OPTIONAL
 , BYREF username AS WSTRINGZ _                         ' __in  LPCWSTR   username
 , BYVAL level AS DWORD _                               ' __in  DWORD     level
 , BYREF bufptr AS ANY _                                ' __out LPBYTE    *bufptr
 , BYVAL prefmaxlen AS DWORD _                          ' __in  DWORD     prefmaxlen
 , BYREF entriesread AS DWORD _                         ' __out LPDWORD   entriesread
 , BYREF totalentries AS DWORD _                        ' __out LPDWORD   totalentries
 ) AS DWORD                                             ' NET_API_STATUS
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION NetUserSetGroups LIB "NetAPI32.dll" ALIAS "NetUserSetGroups" ( _
    servername        AS WSTRINGZ, _
    username          AS WSTRINGZ, _
    BYVAL level       AS DWORD, _
    BYVAL buf         AS BYTE PTR, _
    BYVAL num_entries AS DWORD _
    ) AS DWORD
#ELSE
DECLARE FUNCTION NetUserSetGroups IMPORT "NETAPI32.DLL" ALIAS "NetUserSetGroups" ( _
   BYREF servername AS WSTRINGZ _                       ' __in  LPCWSTR   servername OPTIONAL
 , BYREF username AS WSTRINGZ _                         ' __in  LPCWSTR   username
 , BYVAL level AS DWORD _                               ' __in  DWORD     level
 , BYREF buf AS ANY _                                   ' __in  LPBYTE    buf
 , BYVAL num_entries AS DWORD _                         ' __in  DWORD     num_entries
 ) AS DWORD                                             ' NET_API_STATUS
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION NetUserGetLocalGroups LIB "NetAPI32.dll" ALIAS "NetUserGetLocalGroups" ( _
    servername       AS WSTRINGZ, _
    username         AS WSTRINGZ, _
    BYVAL level      AS DWORD, _
    BYVAL flags      AS DWORD, _
    BYVAL bufptr     AS BYTE PTR, _
    BYVAL prefmaxlen AS DWORD, _
    entriesread      AS DWORD, _
    totalentries     AS DWORD _
    ) AS DWORD
#ELSE
DECLARE FUNCTION NetUserGetLocalGroups IMPORT "NETAPI32.DLL" ALIAS "NetUserGetLocalGroups" ( _
   BYREF servername AS WSTRINGZ _                       ' __in  LPCWSTR   servername OPTIONAL
 , BYREF username AS WSTRINGZ _                         ' __in  LPCWSTR   username
 , BYVAL level AS DWORD _                               ' __in  DWORD     level
 , BYVAL flags AS DWORD _                               ' __in  DWORD     flags
 , BYREF bufptr AS ANY _                                ' __out LPBYTE    *bufptr
 , BYVAL prefmaxlen AS DWORD _                          ' __in  DWORD     prefmaxlen
 , BYREF entriesread AS DWORD _                         ' __out LPDWORD   entriesread
 , BYREF totalentries AS DWORD _                        ' __out LPDWORD   totalentries
 ) AS DWORD                                             ' NET_API_STATUS
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION NetUserModalsGet LIB "NetAPI32.dll" ALIAS "NetUserModalsGet" ( _
    servername   AS WSTRINGZ, _
    BYVAL level  AS DWORD, _
    BYVAL bufptr AS BYTE PTR _
    ) AS DWORD
#ELSE
DECLARE FUNCTION NetUserModalsGet IMPORT "NETAPI32.DLL" ALIAS "NetUserModalsGet" ( _
   BYREF servername AS WSTRINGZ _                       ' __in  LPCWSTR   servername OPTIONAL
 , BYVAL level AS DWORD _                               ' __in  DWORD     level
 , BYREF bufptr AS ANY _                                ' __out LPBYTE    *bufptr
 ) AS DWORD                                             ' NET_API_STATUS
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION NetUserModalsSet LIB "NetAPI32.dll" ALIAS "NetUserModalsSet" ( _
    servername  AS WSTRINGZ, _
    BYVAL level AS DWORD, _
    BYVAL buf   AS BYTE PTR, _
    parm_err    AS DWORD _
    ) AS DWORD
#ELSE
DECLARE FUNCTION NetUserModalsSet IMPORT "NETAPI32.DLL" ALIAS "NetUserModalsSet" ( _
   BYREF servername AS WSTRINGZ _                       ' __in  LPCWSTR   servername OPTIONAL
 , BYVAL level AS DWORD _                               ' __in  DWORD     level
 , BYREF buf AS ANY _                                   ' __in  LPBYTE    buf
 , BYREF parm_err AS DWORD _                            ' __out LPDWORD   parm_err OPTIONAL
 ) AS DWORD                                             ' NET_API_STATUS
#ENDIF

DECLARE FUNCTION NetUserChangePassword IMPORT "NETAPI32.DLL" ALIAS "NetUserChangePassword" ( _
   BYREF domainname AS WSTRINGZ _                       ' __in  LPCWSTR   domainname OPTIONAL
 , BYREF username AS WSTRINGZ _                         ' __in  LPCWSTR   username OPTIONAL
 , BYREF oldpassword AS WSTRINGZ _                      ' __in  LPCWSTR   oldpassword
 , BYREF newpassword AS WSTRINGZ _                      ' __in  LPCWSTR   newpassword
 ) AS DWORD                                             ' NET_API_STATUS

'//
'//  Data Structures - User
'//

' // Size = 4 bytes
TYPE USER_INFO_0 DWORD
   usri0_name AS WSTRINGZ PTR   ' LPWSTR   usri0_name
END TYPE

' // Size = 32 bytes
TYPE USER_INFO_1 DWORD
   usri1_name         AS WSTRINGZ PTR   ' LPWSTR   usri1_name
   usri1_password     AS WSTRINGZ PTR   ' LPWSTR   usri1_password
   usri1_password_age AS DWORD          ' DWORD    usri1_password_age
   usri1_priv         AS DWORD          ' DWORD    usri1_priv
   usri1_home_dir     AS WSTRINGZ PTR   ' LPWSTR   usri1_home_dir
   usri1_comment      AS WSTRINGZ PTR   ' LPWSTR   usri1_comment
   usri1_flags        AS DWORD          ' DWORD    usri1_flags
   usri1_script_path  AS WSTRINGZ PTR   ' LPWSTR   usri1_script_path
END TYPE

' // Size = 96 bytes
TYPE USER_INFO_2 DWORD
   usri2_name           AS WSTRINGZ PTR   ' LPWSTR   usri2_name
   usri2_password       AS WSTRINGZ PTR   ' LPWSTR   usri2_password
   usri2_password_age   AS DWORD          ' DWORD    usri2_password_age
   usri2_priv           AS DWORD          ' DWORD    usri2_priv
   usri2_home_dir       AS WSTRINGZ PTR   ' LPWSTR   usri2_home_dir
   usri2_comment        AS WSTRINGZ PTR   ' LPWSTR   usri2_comment
   usri2_flags          AS DWORD          ' DWORD    usri2_flags
   usri2_script_path    AS WSTRINGZ PTR   ' LPWSTR   usri2_script_path
   usri2_auth_flags     AS DWORD          ' DWORD    usri2_auth_flags
   usri2_full_name      AS WSTRINGZ PTR   ' LPWSTR   usri2_full_name
   usri2_usr_comment    AS WSTRINGZ PTR   ' LPWSTR   usri2_usr_comment
   usri2_parms          AS WSTRINGZ PTR   ' LPWSTR   usri2_parms
   usri2_workstations   AS WSTRINGZ PTR   ' LPWSTR   usri2_workstations
   usri2_last_logon     AS DWORD          ' DWORD    usri2_last_logon
   usri2_last_logoff    AS DWORD          ' DWORD    usri2_last_logoff
   usri2_acct_expires   AS DWORD          ' DWORD    usri2_acct_expires
   usri2_max_storage    AS DWORD          ' DWORD    usri2_max_storage
   usri2_units_per_week AS DWORD          ' DWORD    usri2_units_per_week
   usri2_logon_hours    AS BYTE PTR       ' PBYTE    usri2_logon_hours
   usri2_bad_pw_count   AS DWORD          ' DWORD    usri2_bad_pw_count
   usri2_num_logons     AS DWORD          ' DWORD    usri2_num_logons
   usri2_logon_server   AS WSTRINGZ PTR   ' LPWSTR   usri2_logon_server
   usri2_country_code   AS DWORD          ' DWORD    usri2_country_code
   usri2_code_page      AS DWORD          ' DWORD    usri2_code_page
END TYPE

' // Size = 116 bytes
TYPE USER_INFO_3 DWORD
   usri3_name              AS WSTRINGZ PTR   ' LPWSTR   usri3_name
   usri3_password          AS WSTRINGZ PTR   ' LPWSTR   usri3_password
   usri3_password_age      AS DWORD          ' DWORD    usri3_password_age
   usri3_priv              AS DWORD          ' DWORD    usri3_priv
   usri3_home_dir          AS WSTRINGZ PTR   ' LPWSTR   usri3_home_dir
   usri3_comment           AS WSTRINGZ PTR   ' LPWSTR   usri3_comment
   usri3_flags             AS DWORD          ' DWORD    usri3_flags
   usri3_script_path       AS WSTRINGZ PTR   ' LPWSTR   usri3_script_path
   usri3_auth_flags        AS DWORD          ' DWORD    usri3_auth_flags
   usri3_full_name         AS WSTRINGZ PTR   ' LPWSTR   usri3_full_name
   usri3_usr_comment       AS WSTRINGZ PTR   ' LPWSTR   usri3_usr_comment
   usri3_parms             AS WSTRINGZ PTR   ' LPWSTR   usri3_parms
   usri3_workstations      AS WSTRINGZ PTR   ' LPWSTR   usri3_workstations
   usri3_last_logon        AS DWORD          ' DWORD    usri3_last_logon
   usri3_last_logoff       AS DWORD          ' DWORD    usri3_last_logof
   usri3_acct_expires      AS DWORD          ' DWORD    usri3_acct_expires
   usri3_max_storage       AS DWORD          ' DWORD    usri3_max_storage
   usri3_units_per_week    AS DWORD          ' DWORD    usri3_units_per_week
   usri3_logon_hours       AS BYTE PTR       ' PBYTE    usri3_logon_hours
   usri3_bad_pw_count      AS DWORD          ' DWORD    usri3_bad_pw_count
   usri3_num_logons        AS DWORD          ' DWORD    usri3_num_logons
   usri3_logon_server      AS WSTRINGZ PTR   ' LPWSTR   usri3_logon_server
   usri3_country_code      AS DWORD          ' DWORD    usri3_country_code
   usri3_code_page         AS DWORD          ' DWORD    usri3_code_page
   usri3_user_id           AS DWORD          ' DWORD    usri3_user_id
   usri3_primary_group_id  AS DWORD          ' DWORD    usri3_primary_group_id
   usri3_profile           AS WSTRINGZ PTR   ' LPWSTR   usri3_profile
   usri3_home_dir_drive    AS WSTRINGZ PTR   ' LPWSTR   usri3_home_dir_drive
   usri3_password_expired  AS DWORD          ' DWORD    usri3_password_expired
END TYPE

' // Size = 116 bytes
TYPE USER_INFO_4 DWORD
   usri4_name             AS WSTRINGZ PTR   ' LPWSTR   usri4_name;
   usri4_password         AS WSTRINGZ PTR   ' LPWSTR   usri4_password
   usri4_password_age     AS DWORD          ' DWORD    usri4_password_age
   usri4_priv             AS DWORD          ' DWORD    usri4_priv
   usri4_home_dir         AS WSTRINGZ PTR   ' LPWSTR   usri4_home_dir
   usri4_comment          AS WSTRINGZ PTR   ' LPWSTR   usri4_comment
   usri4_flags            AS DWORD          ' DWORD    usri4_flags
   usri4_script_path      AS WSTRINGZ PTR   ' LPWSTR   usri4_script_path
   usri4_auth_flags       AS DWORD          ' DWORD    usri4_auth_flags
   usri4_full_name        AS WSTRINGZ PTR   ' LPWSTR   usri4_full_name
   usri4_usr_comment      AS WSTRINGZ PTR   ' LPWSTR   usri4_usr_comment
   usri4_parms            AS WSTRINGZ PTR   ' LPWSTR   usri4_parms
   usri4_workstations     AS WSTRINGZ PTR   ' LPWSTR   usri4_workstations
   usri4_last_logon       AS DWORD          ' DWORD    usri4_last_logon
   usri4_last_logoff      AS DWORD          ' DWORD    usri4_last_logoff
   usri4_acct_expires     AS DWORD          ' DWORD    usri4_acct_expires
   usri4_max_storage      AS DWORD          ' DWORD    usri4_max_storage
   usri4_units_per_week   AS DWORD          ' DWORD    usri4_units_per_week
   usri4_logon_hours      AS BYTE PTR       ' PBYTE    usri4_logon_hours
   usri4_bad_pw_count     AS DWORD          ' DWORD    usri4_bad_pw_count
   usri4_num_logons       AS DWORD          ' DWORD    usri4_num_logons
   usri4_logon_server     AS WSTRINGZ PTR   ' LPWSTR   usri4_logon_server
   usri4_country_code     AS DWORD          ' DWORD    usri4_country_code
   usri4_code_page        AS DWORD          ' DWORD    usri4_code_page
   usri4_user_sid         AS SID PTR        ' PSID     usri4_user_sid
   usri4_primary_group_id AS DWORD          ' DWORD    usri4_primary_group_id
   usri4_profile          AS WSTRINGZ PTR   ' LPWSTR   usri4_profile
   usri4_home_dir_drive   AS WSTRINGZ PTR   ' LPWSTR   usri4_home_dir_drive
   usri4_password_expired AS DWORD          ' DWORD    usri4_password_expired
END TYPE

' // Size = 16 bytes
TYPE USER_INFO_10 DWORD
   usri10_name        AS WSTRINGZ PTR   ' LPWSTR   usri10_name
   usri10_comment     AS WSTRINGZ PTR   ' LPWSTR   usri10_comment
   usri10_usr_comment AS WSTRINGZ PTR   ' LPWSTR   usri10_usr_comment
   usri10_full_name   AS WSTRINGZ PTR   ' LPWSTR   usri10_full_name
END TYPE

' // Size = 80 bytes
TYPE USER_INFO_11 DWORD
   usri11_name           AS WSTRINGZ PTR   ' LPWSTR   usri11_name
   usri11_comment        AS WSTRINGZ PTR   ' LPWSTR   usri11_comment
   usri11_usr_comment    AS WSTRINGZ PTR   ' LPWSTR   usri11_usr_comment
   usri11_full_name      AS WSTRINGZ PTR   ' LPWSTR   usri11_full_name
   usri11_priv           AS DWORD          ' DWORD    usri11_priv
   usri11_auth_flags     AS DWORD          ' DWORD    usri11_auth_flags
   usri11_password_age   AS DWORD          ' DWORD    usri11_password_age
   usri11_home_dir       AS WSTRINGZ PTR   ' LPWSTR   usri11_home_dir
   usri11_parms          AS WSTRINGZ PTR   ' LPWSTR   usri11_parms
   usri11_last_logon     AS DWORD          ' DWORD    usri11_last_logon
   usri11_last_logoff    AS DWORD          ' DWORD    usri11_last_logoff
   usri11_bad_pw_count   AS DWORD          ' DWORD    usri11_bad_pw_count
   usri11_num_logons     AS DWORD          ' DWORD    usri11_num_logons
   usri11_logon_server   AS WSTRINGZ PTR   ' LPWSTR   usri11_logon_server
   usri11_country_code   AS DWORD          ' DWORD    usri11_country_code
   usri11_workstations   AS WSTRINGZ PTR   ' LPWSTR   usri11_workstations
   usri11_max_storage    AS DWORD          ' DWORD    usri11_max_storage
   usri11_units_per_week AS DWORD          ' DWORD    usri11_units_per_week
   usri11_logon_hours    AS BYTE PTR       ' PBYTE    usri11_logon_hours
   usri11_code_page      AS DWORD          ' DWORD    usri11_code_page
END TYPE

' // Size = 20 bytes
TYPE USER_INFO_20 DWORD
   usri20_name      AS WSTRINGZ PTR   ' LPWSTR   usri20_name
   usri20_full_name AS WSTRINGZ PTR   ' LPWSTR   usri20_full_name
   usri20_comment   AS WSTRINGZ PTR   ' LPWSTR   usri20_comment
   usri20_flags     AS DWORD          ' DWORD    usri20_flags
   usri20_user_id   AS DWORD          ' DWORD    usri20_user_id
END TYPE

' // Size = 16 bytes
TYPE USER_INFO_21 BYTE
   usri21_password AS STRING * %ENCRYPTED_PWLEN   ' BYTE     usri21_password[ENCRYPTED_PWLEN]
END TYPE

' // Size = 108 bytes
TYPE USER_INFO_22 DWORD
   usri22_name           AS WSTRINGZ PTR                ' LPWSTR   usri22_name
   usri22_password       AS STRING * %ENCRYPTED_PWLEN   ' BYTE     usri22_password[ENCRYPTED_PWLEN]
   usri22_password_age   AS DWORD                       ' DWORD    usri22_password_age
   usri22_priv           AS DWORD                       ' DWORD    usri22_priv
   usri22_home_dir       AS WSTRINGZ PTR                ' LPWSTR   usri22_home_dir
   usri22_comment        AS WSTRINGZ PTR                ' LPWSTR   usri22_comment
   usri22_flags          AS DWORD                       ' DWORD    usri22_flags
   usri22_script_path    AS WSTRINGZ PTR                ' LPWSTR   usri22_script_path
   usri22_auth_flags     AS DWORD                       ' DWORD    usri22_auth_flags
   usri22_full_name      AS WSTRINGZ PTR                ' LPWSTR   usri22_full_name
   usri22_usr_comment    AS WSTRINGZ PTR                ' LPWSTR   usri22_usr_comment
   usri22_parms          AS WSTRINGZ PTR                ' LPWSTR   usri22_parms
   usri22_workstations   AS WSTRINGZ PTR                ' LPWSTR   usri22_workstations
   usri22_last_logon     AS DWORD                       ' DWORD    usri22_last_logon
   usri22_last_logoff    AS DWORD                       ' DWORD    usri22_last_logoff
   usri22_acct_expires   AS DWORD                       ' DWORD    usri22_acct_expires
   usri22_max_storage    AS DWORD                       ' DWORD    usri22_max_storage
   usri22_units_per_week AS DWORD                       ' DWORD    usri22_units_per_week
   usri22_logon_hours    AS BYTE PTR                    ' PBYTE    usri22_logon_hours
   usri22_bad_pw_count   AS DWORD                       ' DWORD    usri22_bad_pw_count
   usri22_num_logons     AS DWORD                       ' DWORD    usri22_num_logons
   usri22_logon_server   AS WSTRINGZ PTR                ' LPWSTR   usri22_logon_server
   usri22_country_code   AS DWORD                       ' DWORD    usri22_country_code
   usri22_code_page      AS DWORD                       ' DWORD    usri22_code_page
END TYPE

' // Size = 20 bytes
TYPE USER_INFO_23 DWORD
   usri23_name      AS WSTRINGZ PTR   ' LPWSTR   usri23_name
   usri23_full_name AS WSTRINGZ PTR   ' LPWSTR   usri23_full_name
   usri23_comment   AS WSTRINGZ PTR   ' LPWSTR   usri23_comment
   usri23_flags     AS DWORD          ' DWORD    usri23_flags
   usri23_user_sid  AS SID PTR        ' PSID     usri23_user_sid
END TYPE

' // Size = 4 bytes
TYPE USER_INFO_1003 DWORD
   usri1003_password AS WSTRINGZ PTR   ' LPWSTR  usri1003_password
END TYPE

' // Size = 4 bytes
TYPE USER_INFO_1005 DWORD
   usri1005_priv AS DWORD          ' DWORD   usri1005_priv
END TYPE

' // Size = 4 bytes
TYPE USER_INFO_1006 DWORD
   usri1006_home_dir AS WSTRINGZ PTR   ' LPWSTR  usri1006_home_dir
END TYPE

' // Size = 4 bytes
TYPE USER_INFO_1007 DWORD
   usri1007_comment AS WSTRINGZ PTR    ' LPWSTR  usri1007_comment
END TYPE

' // Size = 4 bytes
TYPE USER_INFO_1008 DWORD
   usri1008_flags AS DWORD         ' DWORD   usri1008_flags
END TYPE

' // Size = 4 bytes
TYPE USER_INFO_1009 DWORD
   usri1009_script_path AS WSTRINGZ PTR   ' LPWSTR  usri1009_script_path
END TYPE

' // Size = 4 bytes
TYPE USER_INFO_1010 DWORD
   usri1010_auth_flags AS DWORD   ' DWORD   usri1010_auth_flags
END TYPE

' // Size = 4 bytes
TYPE USER_INFO_1011 DWORD
   usri1011_full_name AS WSTRINGZ PTR   ' LPWSTR  usri1011_full_name
END TYPE

' // Size = 4 bytes
TYPE USER_INFO_1012 DWORD
   usri1012_usr_comment AS WSTRINGZ PTR   ' LPWSTR  usri1012_usr_comment
END TYPE

' // Size = 4 bytes
TYPE USER_INFO_1013 DWORD
   usri1013_parms AS WSTRINGZ PTR   ' LPWSTR  usri1013_parms
END TYPE

' // Size = 4 bytes
TYPE USER_INFO_1014 DWORD
   usri1014_workstations AS WSTRINGZ PTR   ' LPWSTR  usri1014_workstations;
END TYPE

' // Size = 4 bytes
TYPE USER_INFO_1017 DWORD
   usri1017_acct_expires AS DWORD   ' DWORD   usri1017_acct_expires
END TYPE

' // Size = 4 bytes
TYPE USER_INFO_1018 DWORD
   usri1018_max_storage AS DWORD   ' DWORD   usri1018_max_storage
END TYPE

' // Size = 8 bytes
TYPE USER_INFO_1020 DWORD
   usri1020_units_per_week AS DWORD      ' DWORD   usri1020_units_per_week
   usri1020_logon_hours    AS BYTE PTR   ' LPBYTE  usri1020_logon_hours
END TYPE

' // Size = 4 bytes
TYPE USER_INFO_1023 DWORD
   usri1023_logon_server AS WSTRINGZ PTR   ' LPWSTR  usri1023_logon_server
END TYPE

' // Size = 4 bytes
TYPE USER_INFO_1024 DWORD
   usri1024_country_code AS DWORD   ' DWORD   usri1024_country_code
END TYPE

' // Size = 4 bytes
TYPE USER_INFO_1025 DWORD
   usri1025_code_page AS DWORD   ' DWORD   usri1025_code_page
END TYPE

' // Size = 4 bytes
TYPE USER_INFO_1051 DWORD
   usri1051_primary_group_id AS DWORD   ' DWORD   usri1051_primary_group_id
END TYPE

' // Size = 4 bytes
TYPE USER_INFO_1052 DWORD
   usri1052_profile AS WSTRINGZ PTR   ' LPWSTR  usri1052_profile
END TYPE

' // Size = 4 bytes
TYPE USER_INFO_1053 DWORD
   usri1053_home_dir_drive AS WSTRINGZ PTR   ' LPWSTR  usri1053_home_dir_drive
END TYPE

'//
'//  Data Structures - User Modals
'//

' // Size = 20 bytes
TYPE USER_MODALS_INFO_0 DWORD
   usrmod0_min_passwd_len    AS DWORD   ' DWORD usrmod0_min_passwd_len
   usrmod0_max_passwd_age    AS DWORD   ' DWORD usrmod0_max_passwd_age
   usrmod0_min_passwd_age    AS DWORD   ' DWORD usrmod0_min_passwd_age
   usrmod0_force_logoff      AS DWORD   ' DWORD usrmod0_force_logoff
   usrmod0_password_hist_len AS DWORD   ' DWORD usrmod0_password_hist_len
END TYPE

' // Size = 4 bytes
TYPE USER_MODALS_INFO_1 DWORD
   usrmod1_role    AS DWORD          ' DWORD    usrmod1_role
   usrmod1_primary AS WSTRINGZ PTR   ' LPWSTR   usrmod1_primary
END TYPE

' // Size = 8 bytes
TYPE USER_MODALS_INFO_2 DWORD
   usrmod2_domain_name AS WSTRINGZ PTR     ' LPWSTR  usrmod2_domain_name
   usrmod2_domain_id   AS SID PTR          ' PSID    usrmod2_domain_id
END TYPE

' // Size = 12 bytes
TYPE USER_MODALS_INFO_3 DWORD
   usrmod3_lockout_duration           AS DWORD   ' DWORD usrmod3_lockout_duration
   usrmod3_lockout_observation_window AS DWORD   ' DWORD usrmod3_lockout_observation_window
   usrmod3_lockout_threshold          AS DWORD   ' DWORD usrmod3_lockout_threshold
END TYPE

' // Size = 4 bytes
TYPE USER_MODALS_INFO_1001 DWORD
   usrmod1001_min_passwd_len AS DWORD   ' DWORD   usrmod1001_min_passwd_len
END TYPE

' // Size = 4 bytes
TYPE USER_MODALS_INFO_1002 DWORD
   usrmod1002_max_passwd_age AS DWORD   ' DWORD   usrmod1002_max_passwd_age
END TYPE

' // Size = 4 bytes
TYPE USER_MODALS_INFO_1003 DWORD
   usrmod1003_min_passwd_age AS DWORD   ' DWORD   usrmod1003_min_passwd_age
END TYPE

' // Size = 4 bytes
TYPE USER_MODALS_INFO_1004 DWORD
   usrmod1004_force_logoff AS DWORD   ' DWORD   usrmod1004_force_logoff
END TYPE

' // Size = 4 bytes
TYPE USER_MODALS_INFO_1005 DWORD
   usrmod1005_password_hist_len AS DWORD   ' DWORD   usrmod1005_password_hist_len
END TYPE

' // Size = 4 bytes
TYPE USER_MODALS_INFO_1006 DWORD
   usrmod1006_role AS DWORD   ' DWORD   usrmod1006_role
END TYPE

' // Size = 4 bytes
TYPE USER_MODALS_INFO_1007 DWORD
   usrmod1007_primary AS WSTRINGZ PTR   ' LPWSTR  usrmod1007_primary
END TYPE


'//
'// Special Values and Constants - User
'//

'//
'//  Bit masks for field usriX_flags of USER_INFO_X (X = 0/1).
'//

%UF_SCRIPT                          = &H0001???
%UF_ACCOUNTDISABLE                  = &H0002???
%UF_HOMEDIR_REQUIRED                = &H0008???
%UF_LOCKOUT                         = &H0010???
%UF_PASSWD_NOTREQD                  = &H0020???
%UF_PASSWD_CANT_CHANGE              = &H0040???
%UF_ENCRYPTED_TEXT_PASSWORD_ALLOWED = &H0080???

'//
'// Account type bits as part of usri_flags.
'//

%UF_TEMP_DUPLICATE_ACCOUNT          = &H0100???
%UF_NORMAL_ACCOUNT                  = &H0200???
%UF_INTERDOMAIN_TRUST_ACCOUNT       = &H0800???
%UF_WORKSTATION_TRUST_ACCOUNT       = &H1000???
%UF_SERVER_TRUST_ACCOUNT            = &H2000???

%UF_MACHINE_ACCOUNT_MASK = %UF_INTERDOMAIN_TRUST_ACCOUNT OR _
                           %UF_WORKSTATION_TRUST_ACCOUNT OR _
                           %UF_SERVER_TRUST_ACCOUNT

%UF_ACCOUNT_TYPE_MASK = %UF_TEMP_DUPLICATE_ACCOUNT OR _
                        %UF_NORMAL_ACCOUNT OR _
                        %UF_INTERDOMAIN_TRUST_ACCOUNT OR _
                        %UF_WORKSTATION_TRUST_ACCOUNT OR _
                        %UF_SERVER_TRUST_ACCOUNT

%UF_DONT_EXPIRE_PASSWD                     = &H10000???
%UF_MNS_LOGON_ACCOUNT                      = &H20000???
%UF_SMARTCARD_REQUIRED                     = &H40000???
%UF_TRUSTED_FOR_DELEGATION                 = &H80000???
%UF_NOT_DELEGATED                          = &H100000???
%UF_USE_DES_KEY_ONLY                       = &H200000???
%UF_DONT_REQUIRE_PREAUTH                   = &H400000???
%UF_PASSWORD_EXPIRED                       = &H800000???
%UF_TRUSTED_TO_AUTHENTICATE_FOR_DELEGATION = &H1000000???
%UF_NO_AUTH_DATA_REQUIRED                  = &H2000000???
%UF_PARTIAL_SECRETS_ACCOUNT                = &H4000000???
%UF_USE_AES_KEYS                           = &H8000000???

%UF_SETTABLE_BITS = %UF_SCRIPT OR _
                    %UF_ACCOUNTDISABLE OR _
                    %UF_LOCKOUT OR _
                    %UF_HOMEDIR_REQUIRED OR _
                    %UF_PASSWD_NOTREQD OR _
                    %UF_PASSWD_CANT_CHANGE OR _
                    %UF_ACCOUNT_TYPE_MASK OR _
                    %UF_DONT_EXPIRE_PASSWD OR _
                    %UF_MNS_LOGON_ACCOUNT OR _
                    %UF_ENCRYPTED_TEXT_PASSWORD_ALLOWED OR _
                    %UF_SMARTCARD_REQUIRED OR _
                    %UF_TRUSTED_FOR_DELEGATION OR _
                    %UF_NOT_DELEGATED OR _
                    %UF_USE_DES_KEY_ONLY OR _
                    %UF_DONT_REQUIRE_PREAUTH OR _
                    %UF_PASSWORD_EXPIRED OR _
                    %UF_TRUSTED_TO_AUTHENTICATE_FOR_DELEGATION OR _
                    %UF_NO_AUTH_DATA_REQUIRED OR _
                    %UF_USE_AES_KEYS OR _
                    %UF_PARTIAL_SECRETS_ACCOUNT

'//
'// bit masks for the NetUserEnum filter parameter.
'//

%FILTER_TEMP_DUPLICATE_ACCOUNT    = &H0001???
%FILTER_NORMAL_ACCOUNT            = &H0002???
' %FILTER_PROXY_ACCOUNT             = &H0004???
%FILTER_INTERDOMAIN_TRUST_ACCOUNT = &H0008???
%FILTER_WORKSTATION_TRUST_ACCOUNT = &H0010???
%FILTER_SERVER_TRUST_ACCOUNT      = &H0020???

'//
'// bit masks for the NetUserGetLocalGroups flags
'//
%LG_INCLUDE_INDIRECT = &H0001???

'//
'//  Bit masks for field usri2_auth_flags of USER_INFO_2.
'//

%AF_OP_PRINT      = &H1???
%AF_OP_COMM       = &H2???
%AF_OP_SERVER     = &H4???
%AF_OP_ACCOUNTS   = &H8???
%AF_SETTABLE_BITS = %AF_OP_PRINT OR %AF_OP_COMM OR _
                    %AF_OP_SERVER OR %AF_OP_ACCOUNTS

'//
'//  UAS role manifests under NETLOGON
'//

%UAS_ROLE_STANDALONE = 0
%UAS_ROLE_MEMBER     = 1
%UAS_ROLE_BACKUP     = 2
%UAS_ROLE_PRIMARY    = 3

'//
'//  Values for ParmError for NetUserSetInfo.
'//

%USER_NAME_PARMNUM           = 1
%USER_PASSWORD_PARMNUM       = 3
%USER_PASSWORD_AGE_PARMNUM   = 4
%USER_PRIV_PARMNUM           = 5
%USER_HOME_DIR_PARMNUM       = 6
%USER_COMMENT_PARMNUM        = 7
%USER_FLAGS_PARMNUM          = 8
%USER_SCRIPT_PATH_PARMNUM    = 9
%USER_AUTH_FLAGS_PARMNUM     = 10
%USER_FULL_NAME_PARMNUM      = 11
%USER_USR_COMMENT_PARMNUM    = 12
%USER_PARMS_PARMNUM          = 13
%USER_WORKSTATIONS_PARMNUM   = 14
%USER_LAST_LOGON_PARMNUM     = 15
%USER_LAST_LOGOFF_PARMNUM    = 16
%USER_ACCT_EXPIRES_PARMNUM   = 17
%USER_MAX_STORAGE_PARMNUM    = 18
%USER_UNITS_PER_WEEK_PARMNUM = 19
%USER_LOGON_HOURS_PARMNUM    = 20
%USER_PAD_PW_COUNT_PARMNUM   = 21
%USER_NUM_LOGONS_PARMNUM     = 22
%USER_LOGON_SERVER_PARMNUM   = 23
%USER_COUNTRY_CODE_PARMNUM   = 24
%USER_CODE_PAGE_PARMNUM      = 25
%USER_PRIMARY_GROUP_PARMNUM  = 51
%USER_PROFILE                = 52 ' ?? Delete when convenient
%USER_PROFILE_PARMNUM        = 52
%USER_HOME_DIR_DRIVE_PARMNUM = 53

'//
'// the new infolevel counterparts of the old info level + parmnum
'//

%USER_NAME_INFOLEVEL            = _
            (%PARMNUM_BASE_INFOLEVEL + %USER_NAME_PARMNUM)
%USER_PASSWORD_INFOLEVEL        = _
            (%PARMNUM_BASE_INFOLEVEL + %USER_PASSWORD_PARMNUM)
%USER_PASSWORD_AGE_INFOLEVEL    = _
            (%PARMNUM_BASE_INFOLEVEL + %USER_PASSWORD_AGE_PARMNUM)
%USER_PRIV_INFOLEVEL            = _
            (%PARMNUM_BASE_INFOLEVEL + %USER_PRIV_PARMNUM)
%USER_HOME_DIR_INFOLEVEL        = _
            (%PARMNUM_BASE_INFOLEVEL + %USER_HOME_DIR_PARMNUM)
%USER_COMMENT_INFOLEVEL         = _
            (%PARMNUM_BASE_INFOLEVEL + %USER_COMMENT_PARMNUM)
%USER_FLAGS_INFOLEVEL           = _
            (%PARMNUM_BASE_INFOLEVEL + %USER_FLAGS_PARMNUM)
%USER_SCRIPT_PATH_INFOLEVEL     = _
            (%PARMNUM_BASE_INFOLEVEL + %USER_SCRIPT_PATH_PARMNUM)
%USER_AUTH_FLAGS_INFOLEVEL      = _
            (%PARMNUM_BASE_INFOLEVEL + %USER_AUTH_FLAGS_PARMNUM)
%USER_FULL_NAME_INFOLEVEL       = _
            (%PARMNUM_BASE_INFOLEVEL + %USER_FULL_NAME_PARMNUM)
%USER_USR_COMMENT_INFOLEVEL     = _
            (%PARMNUM_BASE_INFOLEVEL + %USER_USR_COMMENT_PARMNUM)
%USER_PARMS_INFOLEVEL           = _
            (%PARMNUM_BASE_INFOLEVEL + %USER_PARMS_PARMNUM)
%USER_WORKSTATIONS_INFOLEVEL    = _
            (%PARMNUM_BASE_INFOLEVEL + %USER_WORKSTATIONS_PARMNUM)
%USER_LAST_LOGON_INFOLEVEL      = _
            (%PARMNUM_BASE_INFOLEVEL + %USER_LAST_LOGON_PARMNUM)
%USER_LAST_LOGOFF_INFOLEVEL     = _
            (%PARMNUM_BASE_INFOLEVEL + %USER_LAST_LOGOFF_PARMNUM)
%USER_ACCT_EXPIRES_INFOLEVEL    = _
            (%PARMNUM_BASE_INFOLEVEL + %USER_ACCT_EXPIRES_PARMNUM)
%USER_MAX_STORAGE_INFOLEVEL     = _
            (%PARMNUM_BASE_INFOLEVEL + %USER_MAX_STORAGE_PARMNUM)
%USER_UNITS_PER_WEEK_INFOLEVEL  = _
            (%PARMNUM_BASE_INFOLEVEL + %USER_UNITS_PER_WEEK_PARMNUM)
%USER_LOGON_HOURS_INFOLEVEL     = _
            (%PARMNUM_BASE_INFOLEVEL + %USER_LOGON_HOURS_PARMNUM)
%USER_PAD_PW_COUNT_INFOLEVEL    = _
            (%PARMNUM_BASE_INFOLEVEL + %USER_PAD_PW_COUNT_PARMNUM)
%USER_NUM_LOGONS_INFOLEVEL      = _
            (%PARMNUM_BASE_INFOLEVEL + %USER_NUM_LOGONS_PARMNUM)
%USER_LOGON_SERVER_INFOLEVEL    = _
            (%PARMNUM_BASE_INFOLEVEL + %USER_LOGON_SERVER_PARMNUM)
%USER_COUNTRY_CODE_INFOLEVEL    = _
            (%PARMNUM_BASE_INFOLEVEL + %USER_COUNTRY_CODE_PARMNUM)
%USER_CODE_PAGE_INFOLEVEL       = _
            (%PARMNUM_BASE_INFOLEVEL + %USER_CODE_PAGE_PARMNUM)
%USER_PRIMARY_GROUP_INFOLEVEL   = _
            (%PARMNUM_BASE_INFOLEVEL + %USER_PRIMARY_GROUP_PARMNUM)
' ** Microsoft never defines %USER_POSIX_ID_PARMNUM ...!
'%USER_POSIX_ID_INFOLEVEL        = _
'            (%PARMNUM_BASE_INFOLEVEL + %USER_POSIX_ID_PARMNUM)
%USER_HOME_DIR_DRIVE_INFOLEVEL  = _
            (%PARMNUM_BASE_INFOLEVEL + %USER_HOME_DIR_DRIVE_PARMNUM)

'//
'//  For SetInfo call (parmnum 0) when password change not required
'//

$NULL_USERSETINFO_PASSWD = "              "

%TIMEQ_FOREVER             = &HFFFFFFFF??? ' ((unsigned long) -1L)
%USER_MAXSTORAGE_UNLIMITED = &HFFFFFFFF??? ' ((unsigned long) -1L)
%USER_NO_LOGOFF            = &HFFFFFFFF??? ' ((unsigned long) -1L)
%UNITS_PER_DAY             = 24
%UNITS_PER_WEEK            = %UNITS_PER_DAY * 7

'//
'// Privilege levels (USER_INFO_X field usriX_priv (X = 0/1)).
'//

%USER_PRIV_MASK   = &H3
%USER_PRIV_GUEST  = 0
%USER_PRIV_USER   = 1
%USER_PRIV_ADMIN  = 2

'//
'// user modals related defaults
'//

%MAX_PASSWD_LEN    = %PWLEN
%DEF_MIN_PWLEN     = 6
%DEF_PWUNIQUENESS  = 5
%DEF_MAX_PWHIST    = 8

%DEF_MAX_PWAGE     = %TIMEQ_FOREVER  ' forever
%DEF_MIN_PWAGE     = 0???            ' 0 days
%DEF_FORCE_LOGOFF  = &HFFFFFFFF???   ' never
%DEF_MAX_BADPW     = 0               ' no limit
%ONE_DAY           = 01*24*3600      ' 1 day

'//
'// User Logon Validation (codes returned)
'//

%VALIDATED_LOGON     = 0
%PASSWORD_EXPIRED    = 2
%NON_VALIDATED_LOGON = 3

%VALID_LOGOFF        = 1

'//
'// parmnum manifests for user modals
'//

%MODALS_MIN_PASSWD_LEN_PARMNUM             = 1
%MODALS_MAX_PASSWD_AGE_PARMNUM             = 2
%MODALS_MIN_PASSWD_AGE_PARMNUM             = 3
%MODALS_FORCE_LOGOFF_PARMNUM               = 4
%MODALS_PASSWD_HIST_LEN_PARMNUM            = 5
%MODALS_ROLE_PARMNUM                       = 6
%MODALS_PRIMARY_PARMNUM                    = 7
%MODALS_DOMAIN_NAME_PARMNUM                = 8
%MODALS_DOMAIN_ID_PARMNUM                  = 9
%MODALS_LOCKOUT_DURATION_PARMNUM           = 10
%MODALS_LOCKOUT_OBSERVATION_WINDOW_PARMNUM = 11
%MODALS_LOCKOUT_THRESHOLD_PARMNUM          = 12

'//
'// the new infolevel counterparts of the old info level + parmnum
'//

%MODALS_MIN_PASSWD_LEN_INFOLEVEL     = _
            (%PARMNUM_BASE_INFOLEVEL + %MODALS_MIN_PASSWD_LEN_PARMNUM)
%MODALS_MAX_PASSWD_AGE_INFOLEVEL     = _
            (%PARMNUM_BASE_INFOLEVEL + %MODALS_MAX_PASSWD_AGE_PARMNUM)
%MODALS_MIN_PASSWD_AGE_INFOLEVEL     = _
            (%PARMNUM_BASE_INFOLEVEL + %MODALS_MIN_PASSWD_AGE_PARMNUM)
%MODALS_FORCE_LOGOFF_INFOLEVEL       = _
            (%PARMNUM_BASE_INFOLEVEL + %MODALS_FORCE_LOGOFF_PARMNUM)
%MODALS_PASSWD_HIST_LEN_INFOLEVEL    = _
            (%PARMNUM_BASE_INFOLEVEL + %MODALS_PASSWD_HIST_LEN_PARMNUM)
%MODALS_ROLE_INFOLEVEL               = _
            (%PARMNUM_BASE_INFOLEVEL + %MODALS_ROLE_PARMNUM)
%MODALS_PRIMARY_INFOLEVEL            = _
            (%PARMNUM_BASE_INFOLEVEL + %MODALS_PRIMARY_PARMNUM)
%MODALS_DOMAIN_NAME_INFOLEVEL        = _
            (%PARMNUM_BASE_INFOLEVEL + %MODALS_DOMAIN_NAME_PARMNUM)
%MODALS_DOMAIN_ID_INFOLEVEL          = _
            (%PARMNUM_BASE_INFOLEVEL + %MODALS_DOMAIN_ID_PARMNUM)

'#endif // _LMUSER_
#ENDIF   ' #IF NOT %DEF(%LMUSER)
'//
'// Group Class
'//

#IF NOT %DEF(%LMGROUP)
    %LMGROUP = 1

'//
'// Function Prototypes
'//

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION NetGroupAdd LIB "NetAPI32.dll" ALIAS "NetGroupAdd" ( _
    servername  AS WSTRINGZ, _
    BYVAL level AS DWORD, _
    BYVAL buf   AS BYTE PTR, _
    parm_err    AS DWORD _
    ) AS DWORD
#ELSE
DECLARE FUNCTION NetGroupAdd IMPORT "NETAPI32.DLL" ALIAS "NetGroupAdd" ( _
   BYREF servername AS WSTRINGZ _                       ' __in  LPCWSTR  servername OPTIONAL
 , BYVAL level AS DWORD _                               ' __in  DWORD    level
 , BYREF buf AS ANY _                                   ' __in  LPBYTE   buf
 , BYREF parm_err AS DWORD _                            ' __out LPDWORD  parm_err OPTIONAL
 ) AS DWORD                                             ' NET_API_STATUS
#ENDIF

DECLARE FUNCTION NetGroupAddUser IMPORT "NETAPI32.DLL" ALIAS "NetGroupAddUser" ( _
   BYREF servername AS WSTRINGZ _                       ' __in  LPCWSTR   servername OPTIONAL
 , BYREF GroupName AS WSTRINGZ _                        ' __in  LPCWSTR   GroupName
 , BYREF username AS WSTRINGZ _                         ' __in  LPCWSTR   username
 ) AS DWORD                                             ' NET_API_STATUS

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION NetGroupEnum LIB "NetAPI32.dll" ALIAS "NetGroupEnum" ( _
    servername       AS WSTRINGZ, _
    BYVAL level      AS DWORD, _
    BYVAL bufptr     AS BYTE PTR, _
    BYVAL prefmaxlen AS DWORD, _
    entriesread      AS DWORD, _
    totalentries     AS DWORD, _
    resume_handle    AS DWORD _
    ) AS DWORD
#ELSE
DECLARE FUNCTION NetGroupEnum IMPORT "NETAPI32.DLL" ALIAS "NetGroupEnum" ( _
   BYREF servername AS WSTRINGZ _                       ' __in  LPCWSTR     servername OPTIONAL
 , BYVAL level AS DWORD _                               ' __in  DWORD       level
 , BYREF bufptr AS ANY _                                ' __out LPBYTE      *bufptr
 , BYVAL prefmaxlen AS DWORD _                          ' __in  DWORD       prefmaxlen
 , BYREF entriesread AS DWORD _                         ' __out LPDWORD     entriesread
 , BYREF totalentries AS DWORD _                        ' __out LPDWORD     totalentries
 , BYREF resume_handle AS DWORD _                       ' __in_out PDWORD_PTR resume_handle OPTIONAL
 ) AS DWORD                                             ' NET_API_STATUS
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION NetGroupGetInfo LIB "NetAPI32.dll" ALIAS "NetGroupGetInfo" ( _
    servername   AS WSTRINGZ, _
    GroupName    AS WSTRINGZ, _
    BYVAL level  AS DWORD, _
    BYVAL bufptr AS BYTE PTR _
    ) AS DWORD
#ELSE
DECLARE FUNCTION NetGroupGetInfo IMPORT "NETAPI32.DLL" ALIAS "NetGroupGetInfo" ( _
   BYREF servername AS WSTRINGZ _                       ' __in  LPCWSTR  servername OPTIONAL
 , BYREF groupname AS WSTRINGZ _                        ' __in  LPCWSTR  groupname
 , BYVAL level AS DWORD _                               ' __in  DWORD    level
 , BYREF bufptr AS ANY _                                ' __out LPBYTE   *bufptr
 ) AS DWORD                                             ' NET_API_STATUS
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION NetGroupSetInfo LIB "NetAPI32.dll" ALIAS "NetGroupSetInfo" ( _
    servername  AS WSTRINGZ, _
    GroupName   AS WSTRINGZ, _
    BYVAL level AS DWORD, _
    BYVAL buf   AS BYTE PTR, _
    parm_err    AS DWORD _
    ) AS DWORD
#ELSE
DECLARE FUNCTION NetGroupSetInfo IMPORT "NETAPI32.DLL" ALIAS "NetGroupSetInfo" ( _
   BYREF servername AS WSTRINGZ _                       ' __in  LPCWSTR  servername OPTIONAL
 , BYREF groupname AS WSTRINGZ _                        ' __in  LPCWSTR  groupname
 , BYVAL level AS DWORD _                               ' __in  DWORD    level
 , BYREF buf AS ANY _                                   ' __in  LPBYTE   buf
 , BYREF parm_err AS DWORD _                            ' __out LPDWORD  parm_err OPTIONAL
 ) AS DWORD                                             ' NET_API_STATUS
#ENDIF

DECLARE FUNCTION NetGroupDel IMPORT "NETAPI32.DLL" ALIAS "NetGroupDel" ( _
   BYREF servername AS WSTRINGZ _                       ' __in  LPCWSTR   servername OPTIONAL
 , BYREF groupname AS WSTRINGZ _                        ' __in  LPCWSTR   groupname
 ) AS DWORD                                             ' NET_API_STATUS

DECLARE FUNCTION NetGroupDelUser IMPORT "NETAPI32.DLL" ALIAS "NetGroupDelUser" ( _
   BYREF servername AS WSTRINGZ _                       ' __in  LPCWSTR   servername OPTIONAL
 , BYREF GroupName AS WSTRINGZ _                        ' __in  LPCWSTR   GroupName
 , BYREF Username AS WSTRINGZ _                         ' __in  LPCWSTR   Username
 ) AS DWORD                                             ' NET_API_STATUS

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION NetGroupGetUsers LIB "NetAPI32.dll" _
    ALIAS "NetGroupGetUsers" ( _
    servername       AS WSTRINGZ, _
    GroupName        AS WSTRINGZ, _
    BYVAL level      AS DWORD, _
    BYVAL bufptr     AS BYTE PTR, _
    BYVAL prefmaxlen AS DWORD, _
    entriesread      AS DWORD, _
    totalentries     AS DWORD, _
    resume_handle    AS DWORD _
    ) AS DWORD
#ELSE
DECLARE FUNCTION NetGroupGetUsers IMPORT "NETAPI32.DLL" ALIAS "NetGroupGetUsers" ( _
   BYREF servername AS WSTRINGZ _                       ' __in  LPCWSTR    servername OPTIONAL
 , BYREF groupname AS WSTRINGZ _                        ' __in  LPCWSTR    groupname
 , BYVAL level AS DWORD _                               ' __in  DWORD      level
 , BYREF bufptr AS ANY _                                ' __out LPBYTE     *bufptr
 , BYVAL prefmaxlen AS DWORD _                          ' __in  DWORD      prefmaxlen
 , BYREF entriesread AS DWORD _                         ' __out LPDWORD    entriesread
 , BYREF totalentries AS DWORD _                        ' __out LPDWORD    totalentries
 , BYREF ResumeHandle AS DWORD _                        ' __in_out PDWORD_PTR ResumeHandle
 ) AS DWORD                                             ' NET_API_STATUS
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION NetGroupSetUsers LIB "NetAPI32.dll" _
    ALIAS "NetGroupSetUsers" ( _
    servername         AS WSTRINGZ, _
    GroupName          AS WSTRINGZ, _
    BYVAL level        AS DWORD, _
    BYVAL buf          AS BYTE PTR, _
    BYVAL totalentries AS DWORD _
    ) AS DWORD
#ELSE
DECLARE FUNCTION NetGroupSetUsers IMPORT "NETAPI32.DLL" ALIAS "NetGroupSetUsers" ( _
   BYREF servername AS WSTRINGZ _                       ' __in  LPCWSTR    servername OPTIONAL
 , BYREF groupname AS WSTRINGZ _                        ' __in  LPCWSTR    groupname
 , BYVAL level AS DWORD _                               ' __in  DWORD      level
 , BYREF buf AS ANY _                                   ' __in  LPBYTE     buf
 , BYVAL totalentries AS DWORD _                        ' __in  DWORD      totalentries
 ) AS DWORD                                             ' NET_API_STATUS
#ENDIF

'//
'//  Data Structures - Group
'//

' // Size = 4 bytes
TYPE GROUP_INFO_0 DWORD
   grpi0_name AS WSTRINGZ PTR   ' LPWSTR   grpi0_name
END TYPE

' // Size = 8 bytes
TYPE GROUP_INFO_1 DWORD
   grpi1_name    AS WSTRINGZ PTR   ' LPWSTR   grpi1_name
   grpi1_comment AS WSTRINGZ PTR   ' LPWSTR   grpi1_comment
END TYPE

' // Size = 16 bytes
TYPE GROUP_INFO_2 DWORD
   grpi2_name       AS WSTRINGZ PTR   ' LPWSTR   grpi2_name
   grpi2_comment    AS WSTRINGZ PTR   ' LPWSTR   grpi2_comment
   grpi2_group_id   AS DWORD          ' DWORD    grpi2_group_id
   grpi2_attributes AS DWORD          ' DWORD    grpi2_attributes
END TYPE

' // Size = 16 bytes
TYPE GROUP_INFO_3 DWORD
   grpi3_name       AS WSTRINGZ PTR   ' LPWSTR   grpi3_name
   grpi3_comment    AS WSTRINGZ PTR   ' LPWSTR   grpi3_comment
   grpi3_group_sid  AS SID PTR        ' PSID     grpi3_group_sid
   grpi3_attributes AS DWORD          ' DWORD    grpi3_attributes
END TYPE

' // Size = 4 bytes
TYPE GROUP_INFO_1002 DWORD
   grpi1002_comment AS WSTRINGZ PTR   ' LPWSTR  grpi1002_comment
END TYPE

' // Size = 4 bytes
TYPE GROUP_INFO_1005 DWORD
   grpi1005_attributes AS DWORD   ' DWORD  grpi1005_attributes
END TYPE

' // Size = 4 bytes
TYPE GROUP_USERS_INFO_0 DWORD
   grui0_name AS WSTRINGZ PTR   ' LPWSTR  grui0_name
END TYPE

' // Size = 8 bytes
TYPE GROUP_USERS_INFO_1 DWORD
   grui1_name       AS WSTRINGZ PTR   ' LPWSTR  grui1_name
   grui1_attributes AS DWORD          ' DWORD   grui1_attributes
END TYPE

'//
'// Special Values and Constants - Group
'//

%GROUPIDMASK = &H8000???  ' MSB set if uid refers to a group

'//
'// Predefined group for all normal users, administrators and guests
'// LOCAL is a special group for pinball local security.
'//

'#define GROUP_SPECIALGRP_USERS      L"USERS"
'#define GROUP_SPECIALGRP_ADMINS     L"ADMINS"
'#define GROUP_SPECIALGRP_GUESTS     L"GUESTS"
'#define GROUP_SPECIALGRP_LOCAL      L"LOCAL"

$$GROUP_SPECIALGRP_USERS     = "USERS"$$
$$GROUP_SPECIALGRP_ADMINS    = "ADMINS"$$
$$GROUP_SPECIALGRP_GUESTS    = "GUESTS"$$
$$GROUP_SPECIALGRP_LOCAL     = "LOCAL"$$

'//
'// parmnum manifests for SetInfo calls (only comment is settable)
'//

%GROUP_ALL_PARMNUM         = 0
%GROUP_NAME_PARMNUM        = 1
%GROUP_COMMENT_PARMNUM     = 2
%GROUP_ATTRIBUTES_PARMNUM  = 3

'//
'// the new infolevel counterparts of the old info level + parmnum
'//

%GROUP_ALL_INFOLEVEL             = _
            (%PARMNUM_BASE_INFOLEVEL + %GROUP_ALL_PARMNUM)
%GROUP_NAME_INFOLEVEL            = _
            (%PARMNUM_BASE_INFOLEVEL + %GROUP_NAME_PARMNUM)
%GROUP_COMMENT_INFOLEVEL         = _
            (%PARMNUM_BASE_INFOLEVEL + %GROUP_COMMENT_PARMNUM)
%GROUP_ATTRIBUTES_INFOLEVEL      = _
            (%PARMNUM_BASE_INFOLEVEL + %GROUP_ATTRIBUTES_PARMNUM)
' ** Microsoft never defines %GROUP_POSIX_ID_PARMNUM ...!
'%GROUP_POSIX_ID_INFOLEVEL        = _
'            (%PARMNUM_BASE_INFOLEVEL + %GROUP_POSIX_ID_PARMNUM)

'#endif  // _LMGROUP_
#ENDIF   ' #IF NOT %DEF(%LMGROUP)

'//
'// LocalGroup Class
'//

#IF NOT %DEF(%LMLOCALGROUP)
    %LMLOCALGROUP = 1

'//
'// Function Prototypes
'//

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION NetLocalGroupAdd LIB "NetAPI32.dll" _
    ALIAS "NetLocalGroupAdd" ( _
    servername  AS WSTRINGZ, _
    BYVAL level AS DWORD, _
    BYVAL buf   AS BYTE PTR, _
    parm_err    AS DWORD _
    ) AS DWORD
#ELSE
DECLARE FUNCTION NetLocalGroupAdd IMPORT "NETAPI32.DLL" ALIAS "NetLocalGroupAdd" ( _
   BYREF servername AS WSTRINGZ _                       ' __in  LPCWSTR  servername OPTIONAL
 , BYVAL level AS DWORD _                               ' __in  DWORD    level
 , BYREF buf AS ANY _                                   ' __in  LPBYTE   buf
 , BYREF parm_err AS DWORD _                            ' __out LPDWORD  parm_err OPTIONAL
 ) AS DWORD                                             ' NET_API_STATUS
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION NetLocalGroupAddMember LIB "NetAPI32.dll" _
    ALIAS "NetLocalGroupAddMember" ( _
    servername AS WSTRINGZ, _
    GroupName  AS WSTRINGZ, _
    membersid  AS SID _
    ) AS DWORD
#ELSE
DECLARE FUNCTION NetLocalGroupAddMember IMPORT "NETAPI32.DLL" ALIAS "NetLocalGroupAddMember" ( _
   BYREF servername AS WSTRINGZ _                       ' __in  LPCWSTR  servername OPTIONAL
 , BYREF groupname AS WSTRINGZ _                        ' __in  LPCWSTR  groupname
 , BYVAL membersid AS SID PTR _                         ' __in  PSID     membersid
 ) AS DWORD                                             ' NET_API_STATUS
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION NetLocalGroupEnum LIB "NetAPI32.dll" _
    ALIAS "NetLocalGroupEnum" ( _
    servername       AS WSTRINGZ, _
    BYVAL level      AS DWORD, _
    BYVAL bufptr     AS BYTE PTR, _
    BYVAL prefmaxlen AS DWORD, _
    entriesread      AS DWORD, _
    totalentries     AS DWORD, _
    resumehandle     AS DWORD _
    ) AS DWORD
#ELSE
DECLARE FUNCTION NetLocalGroupEnum IMPORT "NETAPI32.DLL" ALIAS "NetLocalGroupEnum" ( _
   BYREF servername AS WSTRINGZ _                       ' __in  LPCWSTR     servername OPTIONAL
 , BYVAL level AS DWORD _                               ' __in  DWORD       level
 , BYREF bufptr AS ANY _                                ' __out LPBYTE      *bufptr
 , BYVAL prefmaxlen AS DWORD _                          ' __in  DWORD       prefmaxlen
 , BYREF entriesread AS DWORD _                         ' __out LPDWORD     entriesread
 , BYREF totalentries AS DWORD _                        ' __out LPDWORD     totalentries
 , BYREF resumehandle AS DWORD _                        ' __in_out PDWORD_PTR resumehandle OPTIONAL
 ) AS DWORD                                             ' NET_API_STATUS
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION NetLocalGroupGetInfo LIB "NetAPI32.dll" _
    ALIAS "NetLocalGroupGetInfo" ( _
    servername   AS WSTRINGZ, _
    GroupName    AS WSTRINGZ, _
    BYVAL level  AS DWORD, _
    BYVAL bufptr AS BYTE PTR _
    ) AS DWORD
#ELSE
DECLARE FUNCTION NetLocalGroupGetInfo IMPORT "NETAPI32.DLL" ALIAS "NetLocalGroupGetInfo" ( _
   BYREF servername AS WSTRINGZ _                       ' __in  LPCWSTR  servername OPTIONAL
 , BYREF groupname AS WSTRINGZ _                        ' __in  LPCWSTR  groupname
 , BYVAL level AS DWORD _                               ' __in  DWORD    level
 , BYREF bufptr AS ANY _                                ' __out LPBYTE   *bufptr
 ) AS DWORD                                             ' NET_API_STATUS
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION NetLocalGroupSetInfo LIB "NetAPI32.dll" _
    ALIAS "NetLocalGroupSetInfo" ( _
    servername  AS WSTRINGZ, _
    GroupName   AS WSTRINGZ, _
    BYVAL level AS DWORD, _
    BYVAL buf   AS BYTE PTR, _
    parm_err    AS DWORD _
    ) AS DWORD
#ELSE
DECLARE FUNCTION NetLocalGroupSetInfo IMPORT "NETAPI32.DLL" ALIAS "NetLocalGroupSetInfo" ( _
   BYREF servername AS WSTRINGZ _                       ' __in  LPCWSTR  servername OPTIONAL
 , BYREF groupname AS WSTRINGZ _                        ' __in  LPCWSTR  groupname
 , BYVAL level AS DWORD _                               ' __in  DWORD    level
 , BYREF buf AS ANY _                                   ' __in  LPBYTE   buf
 , BYREF parm_err AS DWORD _                            ' __out LPDWORD  parm_err OPTIONAL
 ) AS DWORD                                             ' NET_API_STATUS
#ENDIF

DECLARE FUNCTION NetLocalGroupDel IMPORT "NETAPI32.DLL" ALIAS "NetLocalGroupDel" ( _
   BYREF servername AS WSTRINGZ _                       ' __in  LPCWSTR   servername OPTIONAL
 , BYREF groupname AS WSTRINGZ _                        ' __in  LPCWSTR   groupname
 ) AS DWORD                                             ' NET_API_STATUS

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION NetLocalGroupDelMember LIB "NetAPI32.dll" _
    ALIAS "NetLocalGroupDelMember" ( _
    servername AS WSTRINGZ, _
    GroupName  AS WSTRINGZ, _
    membersid  AS SID _
    ) AS DWORD
#ELSE
DECLARE FUNCTION NetLocalGroupDelMember IMPORT "NETAPI32.DLL" ALIAS "NetLocalGroupDelMember" ( _
   BYREF servername AS WSTRINGZ _                       ' __in  LPCWSTR   servername OPTIONAL
 , BYREF groupname AS WSTRINGZ _                        ' __in  LPCWSTR   groupname
 , BYVAL membersid AS SID PTR _                         ' __in  PSID      membersid
 ) AS DWORD                                             ' NET_API_STATUS
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION NetLocalGroupGetMembers LIB "NetAPI32.dll" _
    ALIAS "NetLocalGroupGetMembers" ( _
    servername       AS WSTRINGZ, _
    GroupName        AS WSTRINGZ, _
    BYVAL level      AS DWORD, _
    BYVAL bufptr     AS BYTE PTR, _
    BYVAL prefmaxlen AS DWORD, _
    entriesread      AS DWORD, _
    totalentries     AS DWORD, _
    resumehandle     AS DWORD _
    ) AS DWORD
#ELSE
DECLARE FUNCTION NetLocalGroupGetMembers IMPORT "NETAPI32.DLL" ALIAS "NetLocalGroupGetMembers" ( _
   BYREF servername AS WSTRINGZ _                          ' __in  LPCWSTR    servername OPTIONAL
 , BYREF localgroupname AS WSTRINGZ _                      ' __in  LPCWSTR    localgroupname
 , BYVAL level AS DWORD _                               ' __in  DWORD      level
 , BYREF bufptr AS ANY _                                ' __out LPBYTE     *bufptr
 , BYVAL prefmaxlen AS DWORD _                          ' __in  DWORD      prefmaxlen
 , BYREF entriesread AS DWORD _                         ' __out LPDWORD    entriesread
 , BYREF totalentries AS DWORD _                        ' __out LPDWORD    totalentries
 , BYREF resumehandle AS DWORD _                        ' __in_out PDWORD_PTR resumehandle
 ) AS DWORD                                             ' NET_API_STATUS
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION NetLocalGroupSetMembers LIB "NetAPI32.dll" _
    ALIAS "NetLocalGroupSetMembers" ( _
    servername         AS WSTRINGZ, _
    GroupName          AS WSTRINGZ, _
    BYVAL level        AS DWORD, _
    BYVAL buf          AS BYTE PTR, _
    BYVAL totalentries AS DWORD _
    ) AS DWORD
#ELSE
DECLARE FUNCTION NetLocalGroupSetMembers IMPORT "NETAPI32.DLL" ALIAS "NetLocalGroupSetMembers" ( _
   BYREF servername AS WSTRINGZ _                       ' __in  LPCWSTR    servername OPTIONAL
 , BYREF groupname AS WSTRINGZ _                        ' __in  LPCWSTR    groupname
 , BYVAL level AS DWORD _                               ' __in  DWORD      level
 , BYREF buf AS ANY _                                   ' __in  LPBYTE     buf
 , BYVAL totalentries AS DWORD _                        ' __in  DWORD      totalentries
 ) AS DWORD                                             ' NET_API_STATUS
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION NetLocalGroupAddMembers LIB "NetAPI32.dll" _
    ALIAS "NetLocalGroupAddMembers" ( _
    servername         AS WSTRINGZ, _
    GroupName          AS WSTRINGZ, _
    BYVAL level        AS DWORD, _
    BYVAL buf          AS BYTE PTR, _
    BYVAL totalentries AS DWORD _
    ) AS DWORD
#ELSE
DECLARE FUNCTION NetLocalGroupAddMembers IMPORT "NETAPI32.DLL" ALIAS "NetLocalGroupAddMembers" ( _
   BYREF servername AS WSTRINGZ _                       ' __in  LPCWSTR    servername OPTIONAL
 , BYREF groupname AS WSTRINGZ _                        ' __in  LPCWSTR    groupname
 , BYVAL level AS DWORD _                               ' __in  DWORD      level
 , BYREF buf AS ANY _                                   ' __in  LPBYTE     buf
 , BYVAL totalentries AS DWORD _                        ' __in  DWORD      totalentries
 ) AS DWORD                                             ' NET_API_STATUS
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION NetLocalGroupDelMembers LIB "NetAPI32.dll" _
    ALIAS "NetLocalGroupDelMembers" ( _
    servername         AS WSTRINGZ, _
    GroupName          AS WSTRINGZ, _
    BYVAL level        AS DWORD, _
    BYVAL buf          AS BYTE PTR, _
    BYVAL totalentries AS DWORD _
    ) AS DWORD
#ELSE
DECLARE FUNCTION NetLocalGroupDelMembers IMPORT "NETAPI32.DLL" ALIAS "NetLocalGroupDelMembers" ( _
   BYREF servername AS WSTRINGZ _                       ' __in  LPCWSTR    servername OPTIONAL
 , BYREF groupname AS WSTRINGZ _                        ' __in  LPCWSTR    groupname
 , BYVAL level AS DWORD _                               ' __in  DWORD      level
 , BYREF buf AS ANY _                                   ' __in  LPBYTE     buf
 , BYVAL totalentries AS DWORD _                        ' __in  DWORD      totalentries
 ) AS DWORD                                             ' NET_API_STATUS
#ENDIF

'//
'//  Data Structures - LocalGroup
'//

' // Size = 4 bytes
TYPE LOCALGROUP_INFO_0 DWORD
   lgrpi0_name AS WSTRINGZ PTR   ' LPWSTR   lgrpi0_name
END TYPE

' // Size = 8 bytes
TYPE LOCALGROUP_INFO_1 DWORD
   lgrpi1_name    AS WSTRINGZ PTR   ' LPWSTR   lgrpi1_name
   lgrpi1_comment AS WSTRINGZ PTR   ' LPWSTR   lgrpi1_comment
END TYPE

' // Size = 4 bytes
TYPE LOCALGROUP_INFO_1002 DWORD
   lgrpi1002_comment AS WSTRINGZ PTR   ' LPWSTR  lgrpi1002_comment
END TYPE

' // Size = 4 bytes
TYPE LOCALGROUP_MEMBERS_INFO_0 DWORD
   lgrmi0_sid AS SID PTR   ' PSID    lgrmi0_sid
END TYPE

' // Size = 12 bytes
TYPE LOCALGROUP_MEMBERS_INFO_1 DWORD
   lgrmi1_sid      AS SID PTR        ' PSID         lgrmi1_sid
   lgrmi1_sidusage AS LONG           ' SID_NAME_USE lgrmi1_sidusage
   lgrmi1_name     AS WSTRINGZ PTR   ' LPWSTR       lgrmi1_name
END TYPE

' // Size = 12 bytes
TYPE LOCALGROUP_MEMBERS_INFO_2 DWORD
   lgrmi2_sid           AS SID PTR        ' PSID         lgrmi2_sid
   lgrmi2_sidusage      AS LONG           ' SID_NAME_USE lgrmi2_sidusage
   lgrmi2_domainandname AS WSTRINGZ PTR   ' LPWSTR       lgrmi2_domainandname
END TYPE

' // Size = 4 bytes
TYPE LOCALGROUP_MEMBERS_INFO_3 DWORD
   lgrmi3_domainandname AS WSTRINGZ PTR   ' LPWSTR       lgrmi3_domainandname
END TYPE

' // Size = 4 bytes
TYPE LOCALGROUP_USERS_INFO_0 DWORD
   lgrui0_name AS WSTRINGZ PTR   ' LPWSTR  lgrui0_name
END TYPE

%LOCALGROUP_NAME_PARMNUM    = 1
%LOCALGROUP_COMMENT_PARMNUM = 2

'//
'// Display Information APIs
'//

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION NetQueryDisplayInformation LIB "NetAPI32.dll" _
    ALIAS "NetQueryDisplayInformation" ( _
    ServerName             AS WSTRINGZ, _
    BYVAL Level            AS DWORD, _
    BYVAL Index            AS DWORD, _
    BYVAL EntriesRequested AS DWORD, _
    BYVAL PreferredMaximumLength AS DWORD, _
    ReturnedEntryCount     AS DWORD, _
    SortedBuffer           AS DWORD _
    ) AS DWORD
#ELSE
DECLARE FUNCTION NetQueryDisplayInformation IMPORT "NETAPI32.DLL" ALIAS "NetQueryDisplayInformation" ( _
   BYREF ServerName AS WSTRINGZ _                       ' __in  LPCWSTR ServerName OPTIONAL
 , BYVAL Level AS DWORD _                               ' __in  DWORD Level
 , BYVAL Index AS DWORD _                               ' __in  DWORD Index
 , BYVAL EntriesRequested AS DWORD _                    ' __in  DWORD EntriesRequested
 , BYVAL PreferredMaximumLength AS DWORD _              ' __in  DWORD PreferredMaximumLength
 , BYREF ReturnedEntryCount AS DWORD _                  ' __out LPDWORD ReturnedEntryCount
 , BYREF SortedBuffer AS ANY _                          ' __out PVOID *SortedBuffer
 ) AS DWORD                                             ' NET_API_STATUS
#ENDIF

DECLARE FUNCTION NetGetDisplayInformationIndex IMPORT "NETAPI32.DLL" ALIAS "NetGetDisplayInformationIndex" ( _
   BYREF ServerName AS WSTRINGZ _                       ' __in  LPCWSTR ServerName OPTIONAL
 , BYVAL Level AS DWORD _                               ' __in  DWORD Level
 , BYREF Prefix AS WSTRINGZ _                           ' __in  LPCWSTR Prefix
 , BYREF Index AS DWORD _                               ' __out LPDWORD Index
 ) AS DWORD                                             ' NET_API_STATUS

'//
'// QueryDisplayInformation levels

' // Size = 24 bytes
TYPE NET_DISPLAY_USER DWORD
   usri1_name       AS WSTRINGZ PTR   ' LPWSTR   usri1_name
   usri1_comment    AS WSTRINGZ PTR   ' LPWSTR   usri1_comment
   usri1_flags      AS DWORD          ' DWORD    usri1_flags
   usri1_full_name  AS WSTRINGZ PTR   ' LPWSTR   usri1_full_name
   usri1_user_id    AS DWORD          ' DWORD    usri1_user_id
   usri1_next_index AS DWORD          ' DWORD    usri1_next_index
END TYPE

' // Size = 20 bytes
TYPE NET_DISPLAY_MACHINE DWORD
   usri2_name       AS WSTRINGZ PTR   ' LPWSTR   usri2_name
   usri2_comment    AS WSTRINGZ PTR   ' LPWSTR   usri2_comment
   usri2_flags      AS DWORD          ' DWORD    usri2_flags
   usri2_user_id    AS DWORD          ' DWORD    usri2_user_id
   usri2_next_index AS DWORD          ' DWORD    usri2_next_index
END TYPE

' // Size = 20 bytes
TYPE NET_DISPLAY_GROUP DWORD
   grpi3_name       AS WSTRINGZ PTR   ' LPWSTR   grpi3_name
   grpi3_comment    AS WSTRINGZ PTR   ' LPWSTR   grpi3_comment
   grpi3_group_id   AS DWORD          ' DWORD    grpi3_group_id
   grpi3_attributes AS DWORD          ' DWORD    grpi3_attributes
   grpi3_next_index AS DWORD          ' DWORD    grpi3_next_index
END TYPE

'#endif  // _LMLOCALGROUP_
#ENDIF   ' #IF NOT %DEF(%LMLOCALGROUP)


'//
'// Access Class
'//

#IF NOT %DEF(%LMACCESS)
    %LMACCESS = 1

'//
'// Function Prototypes - Access
'//

' This function is obsolete. For a list of alternate functions, see Authorization Functions.
#IF %DEF(%USEPBDECL)
DECLARE FUNCTION NetAccessAdd LIB "NetAPI32.dll" ALIAS "NetAccessAdd" ( _
    servername  AS WSTRINGZ, _
    BYVAL level AS DWORD, _
    BYVAL buf   AS BYTE PTR, _
    parm_err    AS DWORD _
    ) AS DWORD
#ELSE
DECLARE FUNCTION NetAccessAdd IMPORT "NETAPI32.DLL" ALIAS "RxNetAccessAdd" ( _
   BYREF servername AS WSTRINGZ _                       ' __in  LPCWSTR  servername OPTIONAL
 , BYVAL level AS DWORD _                               ' __in  DWORD    level
 , BYREF buf AS ANY _                                   ' __in  LPBYTE   buf
 , BYREF parm_err AS DWORD _                            ' __out LPDWORD  parm_err OPTIONAL
 ) AS DWORD                                             ' NET_API_STATUS
#ENDIF

'This function is obsolete. For a list of alternate functions, see Authorization Functions.
#IF %DEF(%USEPBDECL)
DECLARE FUNCTION NetAccessEnum LIB "NetAPI32.dll" ALIAS "NetAccessEnum" ( _
    servername       AS WSTRINGZ, _
    BasePath         AS WSTRINGZ, _
    BYVAL Recursive  AS DWORD, _
    BYVAL level      AS DWORD, _
    bufptr           AS DWORD, _
    BYVAL prefmaxlen AS DWORD, _
    entriesread      AS DWORD, _
    totalentries     AS DWORD, _
    resume_handle    AS DWORD _
    ) AS DWORD
#ELSE
DECLARE FUNCTION NetAccessEnum IMPORT "NETAPI32.DLL" ALIAS "RxNetAccessEnum" ( _
   BYREF servername AS WSTRINGZ _                          ' __in  LPCWSTR    servername OPTIONAL
 , BYREF BasePath AS WSTRINGZ _                            ' __in  LPCWSTR    BasePath
 , BYVAL Recursive AS DWORD _                           ' __in  DWORD      Recursive
 , BYVAL level AS DWORD _                               ' __in  DWORD      level
 , BYREF bufptr AS ANY _                                ' __out LPBYTE     *bufptr
 , BYVAL prefmaxlen AS DWORD _                          ' __in  DWORD      prefmaxlen
 , BYREF entriesread AS DWORD _                         ' __out LPDWORD    entriesread
 , BYREF totalentries AS DWORD _                        ' __out LPDWORD    totalentries
 , BYREF resume_handle AS DWORD _                       ' __in_out LPDWORD resume_handle OPTIONAL
 ) AS DWORD                                             ' NET_API_STATUS
#ENDIF

'This function is obsolete. For a list of alternate functions, see Authorization Functions.
#IF %DEF(%USEPBDECL)
DECLARE FUNCTION NetAccessGetInfo LIB "NetAPI32.dll" _
    ALIAS "NetAccessGetInfo" ( _
    servername   AS WSTRINGZ, _
    resource     AS WSTRINGZ, _
    BYVAL level  AS DWORD, _
    BYVAL bufptr AS BYTE PTR _
    ) AS DWORD
#ELSE
DECLARE FUNCTION NetAccessGetInfo IMPORT "NETAPI32.DLL" ALIAS "RxNetAccessGetInfo" ( _
   BYREF servername AS WSTRINGZ _                       ' __in  LPCWSTR   servername OPTIONAL
 , BYREF resource AS WSTRINGZ _                         ' __in  LPCWSTR  resource
 , BYVAL level AS DWORD _                               ' __in  DWORD    level
 , BYREF bufptr AS ANY _                                ' __out LPBYTE   *bufptr
 ) AS DWORD                                             ' NET_API_STATUS
#ENDIF

'This function is obsolete. For a list of alternate functions, see Authorization Functions.
#IF %DEF(%USEPBDECL)
DECLARE FUNCTION NetAccessSetInfo LIB "NetAPI32.dll" _
    ALIAS "NetAccessSetInfo" ( _
    servername  AS WSTRINGZ, _
    resource    AS WSTRINGZ, _
    BYVAL level AS DWORD, _
    BYVAL buf   AS BYTE PTR, _
    parm_err    AS DWORD _
    ) AS DWORD
#ELSE
DECLARE FUNCTION NetAccessSetInfo IMPORT "NETAPI32.DLL" ALIAS "RxNetAccessSetInfo" ( _
   BYREF servername AS WSTRINGZ _                       ' __in  LPCWSTR  servername OPTIONAL
 , BYREF resource AS WSTRINGZ _                         ' __in  LPCWSTR  resource
 , BYVAL level AS DWORD _                               ' __in  DWORD    level
 , BYREF buf AS ANY _                                   ' __in  LPBYTE   buf
 , BYREF parm_err AS DWORD _                            ' __out LPDWORD  parm_err OPTIONAL
 ) AS DWORD                                             ' NET_API_STATUS
#ENDIF

'This function is obsolete. For a list of alternate functions, see Authorization Functions.
DECLARE FUNCTION NetAccessDel IMPORT "NETAPI32.DLL" ALIAS "RxNetAccessDel" ( _
   BYREF servername AS WSTRINGZ _                       ' __in  LPCWSTR   servername OPTIONAL
 , BYREF resource AS WSTRINGZ _                         ' __in  LPCWSTR   resource
 ) AS DWORD                                             ' NET_API_STATUS

'This function is obsolete. For a list of alternate functions, see Authorization Functions.
DECLARE FUNCTION NetAccessGetUserPerms IMPORT "NETAPI32.DLL" ALIAS "RxNetAccessGetUserPerms" ( _
   BYREF servername AS WSTRINGZ _                       ' __in  LPCWSTR  servername OPTIONAL
 , BYREF UGname AS WSTRINGZ _                           ' __in  LPCWSTR  UGname
 , BYREF resource AS WSTRINGZ _                         ' __in  LPCWSTR  resource
 , BYREF Perms AS DWORD _                               ' __out LPDWORD  Perms
 ) AS DWORD                                             ' NET_API_STATUS

'//
'// Data Structures - Access
'//

' // Size = 4 bytes
TYPE ACCESS_INFO_0 DWORD
   acc0_resource_name AS WSTRINGZ PTR   ' LPWSTR   acc0_resource_name
END TYPE

' // Size = 12 bytes
TYPE ACCESS_INFO_1 DWORD
   acc1_resource_name AS WSTRINGZ PTR   ' LPWSTR   acc1_resource_name
   acc1_attr          AS DWORD          ' DWORD    acc1_attr
   acc1_count         AS DWORD          ' DWORD    acc1_count
END TYPE

' // Size = 4 bytes
TYPE ACCESS_INFO_1002 DWORD
   acc1002_attr AS DWORD   ' DWORD   acc1002_attr
END TYPE

' // Size = 8 bytes
TYPE ACCESS_LIST DWORD
   acl_ugname AS WSTRINGZ PTR   ' LPWSTR   acl_ugname
   acl_access AS DWORD          ' DWORD    acl_access
END TYPE

'//
'// Special Values and Constants - Access
'//

'//
'// Maximum number of permission entries for each resource.
'//

'#define MAXPERMENTRIES      64
%MAXPERMENTRIES = 64

'//
'//  Bit values for the access permissions.  ACCESS_ALL is a handy
'//  way to specify maximum permissions.  These are used in
'//  acl_access field of access_list structures.
'//

%ACCESS_NONE   = 0
%ACCESS_READ   = &H01???
%ACCESS_WRITE  = &H02???
%ACCESS_CREATE = &H04???
%ACCESS_EXEC   = &H08???
%ACCESS_DELETE = &H10???
%ACCESS_ATRIB  = &H20???
%ACCESS_PERM   = &H40???

%ACCESS_ALL    = %ACCESS_READ OR _
                 %ACCESS_WRITE OR _
                 %ACCESS_CREATE OR _
                 %ACCESS_EXEC OR _
                 %ACCESS_DELETE OR _
                 %ACCESS_ATRIB OR _
                 %ACCESS_PERM

%ACCESS_GROUP  = &H8000???

'//
'// Bit values for the acc1_attr field of the ACCESS_INFO_1 structure.
'//

%ACCESS_AUDIT          = &H1???

%ACCESS_SUCCESS_OPEN   = &H10???
%ACCESS_SUCCESS_WRITE  = &H20???
%ACCESS_SUCCESS_DELETE = &H40???
%ACCESS_SUCCESS_ACL    = &H80???
%ACCESS_SUCCESS_MASK   = &HF0???

%ACCESS_FAIL_OPEN      = &H100???
%ACCESS_FAIL_WRITE     = &H200???
%ACCESS_FAIL_DELETE    = &H400???
%ACCESS_FAIL_ACL       = &H800???
%ACCESS_FAIL_MASK      = &HF00???

%ACCESS_FAIL_SHIFT     = 4??

'//
'// Parmnum value for NetAccessSetInfo.
'//

%ACCESS_RESOURCE_NAME_PARMNUM = 1
%ACCESS_ATTR_PARMNUM          = 2
%ACCESS_COUNT_PARMNUM         = 3
%ACCESS_ACCESS_LIST_PARMNUM   = 4

'//
'// the new infolevel counterparts of the old info level + parmnum
'//

%ACCESS_RESOURCE_NAME_INFOLEVEL  = _
            (%PARMNUM_BASE_INFOLEVEL + %ACCESS_RESOURCE_NAME_PARMNUM)
%ACCESS_ATTR_INFOLEVEL           = _
            (%PARMNUM_BASE_INFOLEVEL + %ACCESS_ATTR_PARMNUM)
%ACCESS_COUNT_INFOLEVEL          = _
            (%PARMNUM_BASE_INFOLEVEL + %ACCESS_COUNT_PARMNUM)
%ACCESS_ACCESS_LIST_INFOLEVEL    = _
            (%PARMNUM_BASE_INFOLEVEL + %ACCESS_ACCESS_LIST_PARMNUM)

'//
'// ACCESS_LETTERS defines a letter for each bit position in
'// the acl_access field of struct access_list.  Note that some
'// bits have a corresponding letter of ' ' (space).
'//

'#define ACCESS_LETTERS      "RWCXDAP         "
$ACCESS_LETTERS = "RWCXDAP         "


'//    ********************************
'//
'//    Password Checking API structures
'//
'//    ********************************


'//
'//    What kind of password checking is to be performed?
'//        NetValidateAuthentication : Check if the authentication can be done
'//        NetValidatePasswordChange: Check if the password can be changed
'//        NetValidatePasswordReset: Reset the password to the given value
'//

' NET_VALIDATE_PASSWORD_TYPE enum
%NetValidateAuthentication = 1
%NetValidatePasswordChange = 2
%NetValidatePasswordReset  = 3

'//
'//    Structure to keep the password hash
'//

' // Size = 8 bytes
TYPE NET_VALIDATE_PASSWORD_HASH DWORD
   Length AS DWORD      ' ULONG Length
   Hash   AS BYTE PTR   ' LPBYTE Hash
END TYPE

'// To be used with PresentFields member of NET_VALIDATE_PERSISTED_FIELDS
%NET_VALIDATE_PASSWORD_LAST_SET        = &H00000001???
%NET_VALIDATE_BAD_PASSWORD_TIME        = &H00000002???
%NET_VALIDATE_LOCKOUT_TIME             = &H00000004???
%NET_VALIDATE_BAD_PASSWORD_COUNT       = &H00000008???
%NET_VALIDATE_PASSWORD_HISTORY_LENGTH  = &H00000010???
%NET_VALIDATE_PASSWORD_HISTORY         = &H00000020???

'#if !defined(_WINBASE_) && !defined(_FILETIME_)
#IF NOT %DEF(%FILETIME_DEFINED)
%FILETIME_DEFINED = 1
' // Size = 8 bytes
TYPE FILETIME_STRUCT DWORD
   dwLowDateTime  AS DWORD   ' DWORD
   dwHighDateTime AS DWORD   ' DWORD
END TYPE

' // To allow to use both DWORD's and a QUAD
' // Size = 8 bytes
UNION FILETIME DWORD
   FILETIME_STRUCT
   qDateTime AS QUAD
END UNION
#ENDIF
'#endif

'//
'//    Structure to keep information about the password and related things.
'//        Present Fields: (used only in output args) which fields are changed.
'//            See the constants above.
'//        PasswordLastSet: When the password is last set.
'//        BadPasswordTime: When the password was incorrect for the last time.
'//        LockoutTime: When the account is locked out. If the account is not locked out
'//            it is 0.
'//        BadPasswordCount: How many times the password has given incorrectly in the
'//            Observation Window.
'//        PasswordHistoryLength: How many passwords are kept in the history
'//        PasswordHistory: Password hashes that are in the history
'//

' // Size = 40 bytes
TYPE NET_VALIDATE_PERSISTED_FIELDS DWORD
   PresentFields         AS DWORD      ' ULONG   PresentFields
   PasswordLastSet       AS FILETIME   ' FILETIME PasswordLastSet
   BadPasswordTime       AS FILETIME   ' FILETIME BadPasswordTime
   LockoutTime           AS FILETIME   ' FILETIME LockoutTime
   BadPasswordCount      AS DWORD      ' ULONG   BadPasswordCount
   PasswordHistoryLength AS DWORD      ' ULONG   PasswordHistoryLength
   PasswordHistory       AS NET_VALIDATE_PASSWORD_HASH PTR  ' PNET_VALIDATE_PASSWORD_HASH PasswordHistory
END TYPE

'//
'//    Output Arg
'//        ChangedPersistedFields: Any changes to the password related info
'//        ValidationStatus: Shows the result of the request
'//

' // Size = 44 bytes
TYPE NET_VALIDATE_OUTPUT_ARG DWORD
   ChangedPersistedFields AS NET_VALIDATE_PERSISTED_FIELDS  ' NET_VALIDATE_PERSISTED_FIELDS ChangedPersistedFields
   ValidationStatus       AS DWORD                          ' NET_API_STATUS ValidationStatus
END TYPE

'//
'//    If authentication type of password check is to be made,
'//        this kind of input must be used
'//
'//    InputPersistedFields: Information about the account to be logged into
'//    PasswordMatched: Indicates the result of the application's authentication of the supplied password
'//

' // Size = 44 bytes
TYPE NET_VALIDATE_AUTHENTICATION_INPUT_ARG DWORD
   InputPersistedFields AS NET_VALIDATE_PERSISTED_FIELDS   ' NET_VALIDATE_PERSISTED_FIELDS InputPersistedFields
   PasswordMatched      AS BYTE                            ' BOOLEAN PasswordMatched
END TYPE

'//
'//    If password change type of check is to be made,
'//        this kind of input must be used
'//
'//    InputPersistedFields: Information about the account to be logged into
'//    ClearPassword: The string which password is going to be
'//    UserAccountName: Name of the user account
'//    HashedPassword: Hash of the string that the password is going to be
'//    PasswordMatch: denotes if the old password supplied by user matched or not
'//

' // Size = 60 bytes
TYPE NET_VALIDATE_PASSWORD_CHANGE_INPUT_ARG DWORD
   InputPersistedFields AS NET_VALIDATE_PERSISTED_FIELDS   ' NET_VALIDATE_PERSISTED_FIELDS InputPersistedFields
   ClearPassword        AS WSTRINGZ PTR                    ' LPWSTR ClearPassword
   UserAccountName      AS WSTRINGZ PTR                    ' LPWSTR UserAccountName
   HashedPassword       AS NET_VALIDATE_PASSWORD_HASH      ' NET_VALIDATE_PASSWORD_HASH HashedPassword
   PasswordMatch        AS BYTE                            ' BOOLEAN PasswordMatch
END TYPE

'//
'//    If password reset type of check is to be made,
'//        this kind of input must be used
'//
'//    InputPersistedFields: Information about the account to be logged into
'//    ClearPassword: The string which password is going to be
'//    UserAccountName: Name of the user account
'//    HashedPassword: Hash of the string that the password is going to be
'//    PasswordMustChangeAtNextLogon: Password must change for the user to be logged in
'//    ClearLockout: If the account was locked out, this field can be used to clear lockout
'//

' // Size = 60 bytes
TYPE NET_VALIDATE_PASSWORD_RESET_INPUT_ARG
   InputPersistedFields          AS NET_VALIDATE_PERSISTED_FIELDS   ' NET_VALIDATE_PERSISTED_FIELDS InputPersistedFields
   ClearPassword                 AS WSTRINGZ PTR                    ' LPWSTR ClearPassword
   UserAccountName               AS WSTRINGZ PTR                    ' LPWSTR UserAccountName
   HashedPassword                AS NET_VALIDATE_PASSWORD_HASH      ' NET_VALIDATE_PASSWORD_HASH HashedPassword
   PasswordMustChangeAtNextLogon AS BYTE                            ' BOOLEAN  PasswordMustChangeAtNextLogon
   ClearLockout                  AS BYTE                            ' BOOLEAN  ClearLockout
   alignment__                   AS WORD
END TYPE

'//
'//    Password Checking API structures end here
'//

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION NetValidatePasswordPolicy LIB "NetAPI32.dll" _
    ALIAS "NetValidatePasswordPolicy" ( _
    ServerName           AS WSTRINGZ, _
    Qualifier            AS ANY, _
    BYVAL ValidationType AS LONG, _
    InputArg             AS ANY, _
    OutputArg            AS ANY _
    ) AS DWORD
#ELSE
DECLARE FUNCTION NetValidatePasswordPolicy IMPORT "NETAPI32.DLL" ALIAS "NetValidatePasswordPolicy" ( _
   BYREF ServerName AS WSTRINGZ _                       ' __in  LPCWSTR ServerName
 , BYVAL Qualifier AS DWORD _                           ' __in  LPVOID Qualifier
 , BYVAL ValidationType AS LONG _                       ' __in  NET_VALIDATE_PASSWORD_TYPE ValidationType
 , BYREF InputArg AS ANY _                              ' __in  LPVOID InputArg
 , BYREF OutputArg AS ANY _                             ' __out LPVOID *OutputArg
 ) AS DWORD                                             ' NET_API_STATUS
#ENDIF

DECLARE FUNCTION NetValidatePasswordPolicyFree IMPORT "NETAPI32.DLL" ALIAS "NetValidatePasswordPolicyFree" ( _
   BYREF OutputArg AS ANY _                             ' __in LPVOID *OutputArg
 ) AS DWORD                                             ' NET_API_STATUS

#ENDIF   ' #IF NOT %DEF(%LMACCESS)

'//
'// Domain Class
'//

#IF NOT %DEF(%LMDOMAIN)
    %LMDOMAIN = 1

'//
'// Function Prototypes - Domain
'//

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION NetGetDCName LIB "NetAPI32.dll" ALIAS "NetGetDCName" ( _
    servername   AS WSTRINGZ, _
    domainname   AS WSTRINGZ, _
    BYVAL bufptr AS BYTE PTR _
    ) AS DWORD
#ELSE
DECLARE FUNCTION NetGetDCName IMPORT "NETAPI32.DLL" ALIAS "NetGetDCName" ( _
   BYREF servername AS WSTRINGZ _                       ' __in  LPCWSTR  servername OPTIONAL
 , BYREF domainname AS WSTRINGZ _                       ' __in  LPCWSTR  domainname OPTIONAL
 , BYREF bufptr AS ANY _                                ' __out LPBYTE  *bufptr
 ) AS DWORD                                             ' NET_API_STATUS
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION NetGetAnyDCName LIB "NetAPI32.dll" ALIAS "NetGetAnyDCName" ( _
    servername   AS WSTRINGZ, _
    domainname   AS WSTRINGZ, _
    BYVAL bufptr AS BYTE PTR _
    ) AS DWORD
#ELSE
DECLARE FUNCTION NetGetAnyDCName IMPORT "NETAPI32.DLL" ALIAS "NetGetAnyDCName" ( _
   BYREF servername AS WSTRINGZ _                       ' __in  LPCWSTR  servername OPTIONAL
 , BYREF domainname AS WSTRINGZ _                       ' __in  LPCWSTR  domainname OPTIONAL
 , BYREF bufptr AS ANY _                                ' __out LPBYTE  *bufptr
 ) AS DWORD                                             ' NET_API_STATUS
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION I_NetLogonControl LIB "NetAPI32.dll" _
    ALIAS "I_NetLogonControl" ( _
    servername         AS WSTRINGZ, _
    BYVAL FunctionCode AS DWORD, _
    BYVAL QueryLevel   AS DWORD, _
    BYVAL Buffer       AS BYTE PTR _
    ) AS DWORD
#ELSE
DECLARE FUNCTION I_NetLogonControl IMPORT "NETAPI32.DLL" ALIAS "I_NetLogonControl" ( _
   BYREF ServerName AS WSTRINGZ _                       ' __in  LPCWSTR ServerName OPTIONAL
 , BYVAL FunctionCode AS DWORD _                        ' __in  DWORD FunctionCode
 , BYVAL QueryLevel AS DWORD _                          ' __in  DWORD QueryLevel
 , BYREF Buffer AS ANY _                                ' __out LPBYTE *Buffer
 ) AS DWORD                                             ' NET_API_STATUS
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION I_NetLogonControl2 LIB "NetAPI32.dll" _
    ALIAS "I_NetLogonControl2" ( _
    ServerName         AS WSTRINGZ, _
    BYVAL FunctionCode AS DWORD, _
    BYVAL QueryLevel   AS DWORD, _
    BYVAL pData        AS BYTE PTR, _
    BYVAL Buffer       AS BYTE PTR _
    ) AS DWORD
#ELSE
DECLARE FUNCTION I_NetLogonControl2 IMPORT "NETAPI32.DLL" ALIAS "I_NetLogonControl2" ( _
   BYREF ServerName AS WSTRINGZ _                       ' __in  LPCWSTR ServerName OPTIONAL
 , BYVAL FunctionCode AS DWORD _                        ' __in  DWORD FunctionCode
 , BYVAL QueryLevel AS DWORD _                          ' __in  DWORD QueryLevel
 , BYREF Data AS ANY _                                  ' __in  LPBYTE Data
 , BYREF Buffer AS ANY _                                ' __out LPBYTE *Buffer
 ) AS DWORD                                             ' NET_API_STATUS
#ENDIF

'#ifndef _NTDEF_
'typedef LONG NTSTATUS, *PNTSTATUS;
'#endif

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION NetEnumerateTrustedDomains LIB "NetAPI32.dll" _
    ALIAS "NetEnumerateTrustedDomains" ( _
    ServerName  AS WSTRINGZ, _
    DomainNames AS ANY _
    ) AS DWORD
#ELSE
DECLARE FUNCTION NetEnumerateTrustedDomains IMPORT "NETAPI32.DLL" ALIAS "NetEnumerateTrustedDomains" ( _
   BYREF ServerName AS WSTRINGZ _                       ' __in  LPWSTR ServerName OPTIONAL
 , BYREF DomainNames AS DWORD _                         ' __out LPWSTR *DomainNames
 ) AS LONG                                              ' NTSTATUS
#ENDIF

'//
'// Special Values and Constants - Domain
'//

'//
'// FunctionCode values for I_NetLogonControl.
'//
'// NOTE : if you change the following NETLOGON_CONTROL_* values,
'// change them in net\svcdlls\logonsrv\logon.idl file also.
'//

%NETLOGON_CONTROL_QUERY            = 1  ' No-op: just query
%NETLOGON_CONTROL_REPLICATE        = 2  ' Force replicate on BDC
%NETLOGON_CONTROL_SYNCHRONIZE      = 3  ' Force synchronize on BDC
%NETLOGON_CONTROL_PDC_REPLICATE    = 4  ' Force PDC to broadcast change
%NETLOGON_CONTROL_REDISCOVER       = 5  ' Force to re-discover trusted domain DCs
%NETLOGON_CONTROL_TC_QUERY         = 6  ' Query status of specified trusted channel status
%NETLOGON_CONTROL_TRANSPORT_NOTIFY = 7  ' Notify netlogon that a new transport has come online
%NETLOGON_CONTROL_FIND_USER        = 8  ' Find named user in a trusted domain
%NETLOGON_CONTROL_CHANGE_PASSWORD  = 9  ' Change machine password on a secure channel to a trusted domain
%NETLOGON_CONTROL_TC_VERIFY        = 10 ' Verify status of specified trusted channel
%NETLOGON_CONTROL_FORCE_DNS_REG    = 11 ' Force DNS re-registration of all registered records
%NETLOGON_CONTROL_QUERY_DNS_REG    = 12 ' Query the status of DNS updates

'// Debug function codes

%NETLOGON_CONTROL_UNLOAD_NETLOGON_DLL = &H0000FFFB???
%NETLOGON_CONTROL_BACKUP_CHANGE_LOG   = &H0000FFFC???
%NETLOGON_CONTROL_TRUNCATE_LOG        = &H0000FFFD???
%NETLOGON_CONTROL_SET_DBFLAG          = &H0000FFFE???
%NETLOGON_CONTROL_BREAKPOINT          = &H0000FFFF???

'//
'// Query level 1 for I_NetLogonControl
'//

' // Size = 8 bytes
TYPE NETLOGON_INFO_1 DWORD
   netlog1_flags                 AS DWORD   ' DWORD netlog1_flags
   netlog1_pdc_connection_status AS DWORD   ' NET_API_STATUS netlog1_pdc_connection_status
END TYPE

' // Size = 12 bytes
TYPE NETLOGON_INFO_2 DWORD
   netlog2_flags                 AS DWORD          ' DWORD netlog2_flags
   netlog2_pdc_connection_status AS DWORD          ' NET_API_STATUS netlog2_pdc_connection_status
   netlog2_trusted_dc_name       AS WSTRINGZ PTR   ' LPWSTR netlog2_trusted_dc_name
   netlog2_tc_connection_status  AS DWORD          ' NET_API_STATUS netlog2_tc_connection_status
END TYPE

' // Size = 28 bytes
TYPE NETLOGON_INFO_3 DWORD
   netlog3_flags          AS DWORD   ' DWORD netlog3_flags
   netlog3_logon_attempts AS DWORD   ' DWORD netlog3_logon_attempts
   netlog3_reserved1      AS DWORD   ' DWORD netlog3_reserved1
   netlog3_reserved2      AS DWORD   ' DWORD netlog3_reserved2
   netlog3_reserved3      AS DWORD   ' DWORD netlog3_reserved3
   netlog3_reserved4      AS DWORD   ' DWORD netlog3_reserved4
   netlog3_reserved5      AS DWORD   ' DWORD netlog3_reserved5
END TYPE

' // Size = 8 bytes
TYPE NETLOGON_INFO_4 DWORD
   netlog4_trusted_dc_name     AS WSTRINGZ PTR   ' LPWSTR netlog4_trusted_dc_name
   netlog4_trusted_domain_name AS WSTRINGZ PTR   ' LPWSTR netlog4_trusted_domain_name
END TYPE

'//
'// Values of netlog1_flags
'//

%NETLOGON_REPLICATION_NEEDED      = &H0001??? ' Database is out of date
%NETLOGON_REPLICATION_IN_PROGRESS = &H0002??? ' Replication is happening now
%NETLOGON_FULL_SYNC_REPLICATION   = &H0004??? ' full sync replication required/progress
%NETLOGON_REDO_NEEDED             = &H0008??? ' Redo of previous replication needed
%NETLOGON_HAS_IP                  = &H0010??? ' The trusted domain DC has an IP address
%NETLOGON_HAS_TIMESERV            = &H0020??? ' The trusted domain DC runs the Windows Time Service
%NETLOGON_DNS_UPDATE_FAILURE      = &H0040??? ' There was a failure in the last update for one of the DNS records
%NETLOGON_VERIFY_STATUS_RETURNED  = &H0080??? ' Trust verification status returned in netlog2_pdc_connection_status

'#define SERVICE_ACCOUNT_PASSWORD TEXT("_SA_{262E99C9-6160-4871-ACEC-4E61736B6F21}")
'#define SERVICE_ACCOUNT_SECRET_PREFIX TEXT("_SC_{262E99C9-6160-4871-ACEC-4E61736B6F21}_")

$SERVICE_ACCOUNT_PASSWORD = "_SA_{262E99C9-6160-4871-ACEC-4E61736B6F21}"
$SERVICE_ACCOUNT_SECRET_PREFIX = "_SC_{262E99C9-6160-4871-ACEC-4E61736B6F21}_"

$ServiceAccountPasswordGUID = GUID$("{262E99C9-6160-4871-ACEC-4E61736B6F21}")

DECLARE FUNCTION NetAddServiceAccount IMPORT "NETAPI32.DLL" ALIAS "NetAddServiceAccount" ( _
   BYREF ServerName AS WSTRINGZ _                       ' __in_opt LPWSTR ServerName
 , BYREF AccountName AS WSTRINGZ _                      ' __in LPWSTR AccountName
 , BYREF Reserved AS WSTRINGZ _                         ' __in LPWSTR Reserved
 , BYVAL Flags AS DWORD _                               ' __in DWORD Flags
 ) AS LONG                                              ' NTSTATUS

'// Do not create an account by this name
'// Only link this account to my computer if it exists
%SERVICE_ACCOUNT_FLAG_LINK_TO_HOST_ONLY = &H00000001???

'// Do not delete the service account object from AD
'// Simply unlink it from this computer and delete the local secret
%SERVICE_ACCOUNT_FLAG_UNLINK_FROM_HOST_ONLY = &H00000001???

DECLARE FUNCTION NetRemoveServiceAccount IMPORT "NETAPI32.DLL" ALIAS "NetRemoveServiceAccount" ( _
   BYREF ServerName AS WSTRINGZ _                       ' __in_opt LPWSTR ServerName
 , BYREF AccountName AS WSTRINGZ _                      ' __in LPWSTR AccountName
 , BYVAL Flags AS DWORD _                               ' __in DWORD Flags
 ) AS LONG                                              ' NTSTATUS

DECLARE FUNCTION NetEnumerateServiceAccounts IMPORT "NETAPI32.DLL" ALIAS "NetEnumerateServiceAccounts" ( _
   BYREF ServerName AS WSTRINGZ _                       ' __in_opt LPWSTR ServerName
 , BYVAL Flags AS DWORD _                               ' __in DWORD Flags
 , BYREF AccountsCount AS DWORD _                       ' __out DWORD* AccountsCount
 , BYREF Accounts AS ANY _                              ' __out PZPWSTR* Accounts
 ) AS LONG                                              ' NTSTATUS

DECLARE FUNCTION NetIsServiceAccount IMPORT "NETAPI32.DLL" ALIAS "NetIsServiceAccount" ( _
   BYREF ServerName AS WSTRINGZ _                       ' __in_opt LPWSTR ServerName
 , BYREF AccountName AS WSTRINGZ _                      ' __in LPWSTR AccountName
 , BYREF IsService AS LONG _                            ' __out BOOL *IsService
 ) AS LONG                                              ' NTSTATUS

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION NetQueryServiceAccount (ServerName AS WSTRINGZ, _
    AccountName AS WSTRINGZ, BYVAL InfoLevel AS DWORD, Buffer AS ANY) AS LONG
#ELSE
DECLARE FUNCTION NetQueryServiceAccount IMPORT "NETAPI32.DLL" ALIAS "NetQueryServiceAccount" ( _
   BYREF ServerName AS WSTRINGZ _                       ' __in_opt LPWSTR ServerName
 , BYREF AccountName AS WSTRINGZ _                      ' __in LPWSTR AccountName
 , BYVAL InfoLevel AS DWORD _                           ' __in DWORD InfoLevel
 , BYREF Buffer AS DWORD _                              ' __out PBYTE* Buffer
 ) AS LONG                                              ' NTSTATUS
#ENDIF

'//
'//  Data Structures - Service
'//

' enum MSA_INFO_LEVEL
%MsaInfoLevel0   = 0
%MsaInfoLevelMax = 1

' enum MSA_INFO_STATE
%MsaInfoNotExist      = 1
%MsaInfoNotService    = 2
%MsaInfoCannotInstall = 3
%MsaInfoCanInstall    = 4
%MsaInfoInstalled     = 5

' // Size = 4 bytes
TYPE MSA_INFO_0 DWORD
   State AS LONG   ' MSA_INFO_STATE
END TYPE

#ENDIF   ' #IF NOT %DEF(%LMDOMAIN)
