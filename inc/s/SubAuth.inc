' ########################################################################################
' Microsoft Windows
' File: SubAuth.inc
' Contents: This module defines types and macros for Subauthentication Packages
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%SUBAUTH_INC = 1

'#if (!defined(_NTDEF_)) && (!defined(_NTSECAPI_))
'typedef LONG NTSTATUS, *PNTSTATUS;

'typedef struct _UNICODE_STRING {
'    USHORT Length;
'    USHORT MaximumLength;
'    PWSTR Buffer;
'} UNICODE_STRING, *PUNICODE_STRING;

'typedef struct _STRING {
'    USHORT Length;
'    USHORT MaximumLength;
'    PCHAR Buffer;
'} STRING, *PSTRING;
'#endif

'#ifndef _NTDEF_

#IF NOT %DEF(%NTDEF)
   #IF NOT %DEF(%NTSECAPI_INC)
      ' // Size = 8 bytes
      TYPE UNICODE_STRING WORD
         Length        AS WORD
         MaximumLength AS WORD
         Buffer        AS WSTRINGZ PTR
      END TYPE
      ' // Size = 8 bytes
      TYPE ANSI_STRING WORD
         Length        AS WORD
         MaximumLength AS WORD
         Buffer        AS ASCIIZ PTR
      END TYPE
   #ENDIF
#ENDIF

' // Size = 8 bytes
TYPE OLD_LARGE_INTEGER DWORD
   LowPart  AS DWORD   ' ULONG
   HighPart AS LONG    ' LONG
END TYPE

'#define NT_SUCCESS(Status) ((NTSTATUS)(Status) >= 0)

#IF NOT %DEF(%NTDEF)
FUNCTION NT_SUCCESS(BYVAL Status AS LONG) AS LONG
   FUNCTION = (BITS(LONG, Status) >= 0)
END FUNCTION
#ENDIF

'#endif

'#ifndef _NTSAM_SAM_HANDLE_
'typedef PVOID SAM_HANDLE, *PSAM_HANDLE;
'#define _NTSAM_SAM_HANDLE_
'#endif

'#ifndef _NTSAM_USER_ACCOUNT_FLAGS_
#IF NOT %DEF(%NTSAM_USER_ACCOUNT_FLAGS)

'//
'// User account control flags...
'//

%USER_ACCOUNT_DISABLED                       = &H00000001???
%USER_HOME_DIRECTORY_REQUIRED                = &H00000002???
%USER_PASSWORD_NOT_REQUIRED                  = &H00000004???
%USER_TEMP_DUPLICATE_ACCOUNT                 = &H00000008???
%USER_NORMAL_ACCOUNT                         = &H00000010???
%USER_MNS_LOGON_ACCOUNT                      = &H00000020???
%USER_INTERDOMAIN_TRUST_ACCOUNT              = &H00000040???
%USER_WORKSTATION_TRUST_ACCOUNT              = &H00000080???
%USER_SERVER_TRUST_ACCOUNT                   = &H00000100???
%USER_DONT_EXPIRE_PASSWORD                   = &H00000200???
%USER_ACCOUNT_AUTO_LOCKED                    = &H00000400???
%USER_ENCRYPTED_TEXT_PASSWORD_ALLOWED        = &H00000800???
%USER_SMARTCARD_REQUIRED                     = &H00001000???
%USER_TRUSTED_FOR_DELEGATION                 = &H00002000???
%USER_NOT_DELEGATED                          = &H00004000???
%USER_USE_DES_KEY_ONLY                       = &H00008000???
%USER_DONT_REQUIRE_PREAUTH                   = &H00010000???
%USER_PASSWORD_EXPIRED                       = &H00020000???
%USER_TRUSTED_TO_AUTHENTICATE_FOR_DELEGATION = &H00040000???
%USER_NO_AUTH_DATA_REQUIRED                  = &H00080000???
%USER_PARTIAL_SECRETS_ACCOUNT                = &H00100000???
%USER_USE_AES_KEYS                           = &H00200000???

'#define NEXT_FREE_ACCOUNT_CONTROL_BIT (USER_USE_AES_KEYS << 1)
%NEXT_FREE_ACCOUNT_CONTROL_BIT = %USER_USE_AES_KEYS * 2

%USER_MACHINE_ACCOUNT_MASK =    _
            (%USER_INTERDOMAIN_TRUST_ACCOUNT OR _
             %USER_WORKSTATION_TRUST_ACCOUNT OR _
             %USER_SERVER_TRUST_ACCOUNT)

%USER_ACCOUNT_TYPE_MASK =       _
            (%USER_TEMP_DUPLICATE_ACCOUNT OR _
             %USER_NORMAL_ACCOUNT OR _
             %USER_MACHINE_ACCOUNT_MASK)

%USER_COMPUTED_ACCOUNT_CONTROL_BITS =  _
            (%USER_ACCOUNT_AUTO_LOCKED OR _
             %USER_PASSWORD_EXPIRED)


'//
'// Logon times may be expressed in day, hour, or minute granularity.
'//
'//              Days per week    = 7
'//              Hours per week   = 168
'//              Minutes per week = 10080
'//

%SAM_DAYS_PER_WEEK    = 7
%SAM_HOURS_PER_WEEK   = 24 * %SAM_DAYS_PER_WEEK
%SAM_MINUTES_PER_WEEK = 60 * %SAM_HOURS_PER_WEEK

'typedef struct _LOGON_HOURS {

'    USHORT UnitsPerWeek;

'    //
'    // UnitsPerWeek is the number of equal length time units the week is
'    // divided into.  This value is used to compute the length of the bit
'    // string in logon_hours.  Must be less than or equal to
'    // SAM_UNITS_PER_WEEK (10080) for this release.
'    //
'    // LogonHours is a bit map of valid logon times.  Each bit represents
'    // a unique division in a week.  The largest bit map supported is 1260
'    // bytes (10080 bits), which represents minutes per week.  In this case
'    // the first bit (bit 0, byte 0) is Sunday, 00:00:00 - 00-00:59; bit 1,
'    // byte 0 is Sunday, 00:01:00 - 00:01:59, etc.  A NULL pointer means
'    // DONT_CHANGE for SamSetInformationUser() calls.
'    //

'    PUCHAR LogonHours;

'} LOGON_HOURS, *PLOGON_HOURS;

' // Size ) 8 bytes
TYPE LOGON_HOURS DWORD
   UnitsPerWeek AS WORD
   LogonHours   AS BYTE PTR
END TYPE

' // Size ) 8 bytes
TYPE SR_SECURITY_DESCRIPTOR DWORD
   Length             AS DWORD      ' ULONG
   SecurityDescriptor AS BYTE PTR   ' PUCHAR
END TYPE

'#define _NTSAM_USER_ACCOUNT_FLAG_
'#endif

' Microsoft drops the final "S" on this definition, but the equate is clearly
' intended to match the #IF block, so...
%NTSAM_USER_ACCOUNT_FLAGS = 1
#ENDIF  ' #IF NOT %DEF(%NTSAM_USER_ACCOUNT_FLAGS)

'#ifndef _NTSAM_USER_ALL_INFO_
'#include "pshpack4.h"

#IF NOT %DEF(%NTSAM_USER_ALL_INFO)
' // Size = 196 bytes
TYPE USER_ALL_INFORMATION   ' Must be 8 byte aligned
   LastLogon            AS QUAD                     ' LARGE_INTEGER
   LastLogoff           AS QUAD                     ' LARGE_INTEGER
   PasswordLastSet      AS QUAD                     ' LARGE_INTEGER
   AccountExpires       AS QUAD                     ' LARGE_INTEGER
   PasswordCanChange    AS QUAD                     ' LARGE_INTEGER
   PasswordMustChange   AS QUAD                     ' LARGE_INTEGER
   UserName             AS UNICODE_STRING           ' UNICODE_STRING
   FullName             AS UNICODE_STRING           ' UNICODE_STRING
   HomeDirectory        AS UNICODE_STRING           ' UNICODE_STRING
   HomeDirectoryDrive   AS UNICODE_STRING           ' UNICODE_STRING
   ScriptPath           AS UNICODE_STRING           ' UNICODE_STRING
   ProfilePath          AS UNICODE_STRING           ' UNICODE_STRING
   AdminComment         AS UNICODE_STRING           ' UNICODE_STRING
   WorkStations         AS UNICODE_STRING           ' UNICODE_STRING
   UserComment          AS UNICODE_STRING           ' UNICODE_STRING
   Parameters           AS UNICODE_STRING           ' UNICODE_STRING
   LmPassword           AS UNICODE_STRING           ' UNICODE_STRING
   NtPassword           AS UNICODE_STRING           ' UNICODE_STRING
   PrivateData          AS UNICODE_STRING           ' UNICODE_STRING
   SecurityDescriptor   AS SR_SECURITY_DESCRIPTOR   ' SR_SECURITY_DESCRIPTOR
   UserId               AS DWORD                    ' ULONG
   PrimaryGroupId       AS DWORD                    ' ULONG
   UserAccountControl   AS DWORD                    ' ULONG
   WhichFields          AS DWORD                    ' ULONG
   LogonHours           AS LOGON_HOURS              ' LOGON_HOURS
   BadPasswordCount     AS WORD                     ' USHORT
   LogonCount           AS WORD                     ' USHORT
   CountryCode          AS WORD                     ' USHORT
   CodePage             AS WORD                     ' USHORT
   LmPasswordPresent    AS BYTE                     ' BOOLEAN
   NtPasswordPresent    AS BYTE                     ' BOOLEAN
   PasswordExpired      AS BYTE                     ' BOOLEAN
   PrivateDataSensitive AS BYTE                     ' BOOLEAN
END TYPE
%NTSAM_USER_ALL_INFO = 1
#ENDIF  ' #IF NOT %DEF(%NTSAM_USER_ALL_INFO)

'#include "poppack.h"
'#define _NTSAM_USER_ALL_INFO_
'#endif

'#ifndef _NTSAM_SAM_USER_PARMS_
'#define USER_ALL_PARAMETERS         0x00200000
'#define _NTSAM_SAM_USER_PARMS_
'#endif

#IF NOT %DEF(%NTSAM_SAM_USER_PARMS)
   %USER_ALL_PARAMETERS  = &H00200000???
   %NTSAM_SAM_USER_PARMS = 1
#ENDIF

%CLEAR_BLOCK_LENGTH = 8

UNION CLEAR_BLOCK_UNION
   data AS STRING * %CLEAR_BLOCK_LENGTH   ' CHAR    data[CLEAR_BLOCK_LENGTH]
   ' // For compatibility with the PB declares
   cdata AS STRING * %CLEAR_BLOCK_LENGTH   ' CHAR    data[CLEAR_BLOCK_LENGTH]
END UNION

' // Size = 8 bytes
TYPE CLEAR_BLOCK BYTE
   CLEAR_BLOCK_UNION
END TYPE

%CYPHER_BLOCK_LENGTH = 8

UNION CYPHER_BLOCK_UNION
   data AS STRING * %CYPHER_BLOCK_LENGTH   ' CHAR    data[CYPHER_BLOCK_LENGTH]
   ' // For compatibility with the PB declares
   cdata AS STRING * %CYPHER_BLOCK_LENGTH   ' CHAR    data[CYPHER_BLOCK_LENGTH]
END UNION

' // Size = 8 bytes
TYPE CYPHER_BLOCK BYTE
   CYPHER_BLOCK_UNION
END TYPE

UNION LM_OWF_PASSWORD_UNION
   data(1) AS CYPHER_BLOCK   ' CYPHER_BLOCK data[2]
   ' // For compatibility with the PB declares
   cdata(1) AS CYPHER_BLOCK   ' CYPHER_BLOCK data[2]
END UNION

' // Size = 16 bytes
TYPE LM_OWF_PASSWORD BYTE
   LM_OWF_PASSWORD_UNION
END TYPE

'typedef LM_OWF_PASSWORD *           PLM_OWF_PASSWORD;
'typedef CLEAR_BLOCK                 LM_CHALLENGE;
'typedef LM_CHALLENGE *              PLM_CHALLENGE;
'typedef LM_OWF_PASSWORD             NT_OWF_PASSWORD;
'typedef NT_OWF_PASSWORD *           PNT_OWF_PASSWORD;
'typedef LM_CHALLENGE                NT_CHALLENGE;
'typedef NT_CHALLENGE *              PNT_CHALLENGE;

MACRO LM_CHALLENGE = CLEAR_BLOCK
MACRO NT_OWF_PASSWORD = LM_OWF_PASSWORD
MACRO NT_CHALLENGE = LM_CHALLENGE

%USER_SESSION_KEY_LENGTH = %CYPHER_BLOCK_LENGTH * 2

UNION USER_SESSION_KEY_UNION
   data(1) AS CYPHER_BLOCK   ' CYPHER_BLOCK data[2]
   ' // For compatibility with the PB declares
   cdata(1) AS CYPHER_BLOCK   ' CYPHER_BLOCK data[2]
END UNION

' // Size = 16 bytes
TYPE USER_SESSION_KEY BYTE
   USER_SESSION_KEY_UNION
END TYPE

'typedef enum _NETLOGON_LOGON_INFO_CLASS {
%NetlogonInteractiveInformation           = 1
%NetlogonNetworkInformation               = 2
%NetlogonServiceInformation               = 3
%NetlogonGenericInformation               = 4
%NetlogonInteractiveTransitiveInformation = 5
%NetlogonNetworkTransitiveInformation     = 6
%NetlogonServiceTransitiveInformation     = 7

' // Size = 36 bytes
TYPE NETLOGON_LOGON_IDENTITY_INFO   ' Must be 8 byte aligned
   LogonDomainName  AS UNICODE_STRING   ' UNICODE_STRING
   ParameterControl AS DWORD            ' ULONG
   LogonId          AS QUAD             ' OLD_LARGE_INTEGER
   UserName         AS UNICODE_STRING   ' UNICODE_STRING
   Workstation      AS UNICODE_STRING   ' UNICODE_STRING
END TYPE

' // Size = 68 bytes
TYPE NETLOGON_INTERACTIVE_INFO DWORD
   Identity      AS NETLOGON_LOGON_IDENTITY_INFO
   LmOwfPassword AS LM_OWF_PASSWORD
   NtOwfPassword AS NT_OWF_PASSWORD
END TYPE

' // Size = 68 bytes
TYPE NETLOGON_SERVICE_INFO DWORD
   Identity      AS NETLOGON_LOGON_IDENTITY_INFO
   LmOwfPassword AS LM_OWF_PASSWORD
   NtOwfPassword AS NT_OWF_PASSWORD
END TYPE

' // Size = 60 bytes
TYPE NETLOGON_NETWORK_INFO DWORD
   Identity            AS NETLOGON_LOGON_IDENTITY_INFO
   LmChallenge         AS LM_CHALLENGE
   NtChallengeResponse AS ANSI_STRING
   LmChallengeResponse AS ANSI_STRING
END TYPE

' // Size = 52 bytes
TYPE NETLOGON_GENERIC_INFO DWORD
   Identity    AS NETLOGON_LOGON_IDENTITY_INFO
   PackageName AS UNICODE_STRING
   DataLength  AS DWORD      ' ULONG
   LogonData   AS BYTE PTR   ' PUCHAR
END TYPE

'// Values for Flags
%MSV1_0_PASSTHRU    = &H01???
%MSV1_0_GUEST_LOGON = &H02???

DECLARE FUNCTION Msv1_0SubAuthenticationRoutine ALIAS "Msv1_0SubAuthenticationRoutine" ( _
   BYVAL LogonLevel AS LONG _                           ' __in  NETLOGON_LOGON_INFO_CLASS LogonLevel
 , BYREF LogonInformation AS ANY _                      ' __in  PVOID LogonInformation
 , BYVAL Flags AS DWORD _                               ' __in  ULONG Flags
 , BYREF UserAll AS USER_ALL_INFORMATION _              ' __in  PUSER_ALL_INFORMATION UserAll
 , BYREF WhichFields AS DWORD _                         ' __out PULONG WhichFields
 , BYREF UserFlags AS DWORD _                           ' __out PULONG UserFlags
 , BYREF Authoritative AS BYTE _                        ' __out PBOOLEAN Authoritative
 , BYREF LogoffTime AS ANY _                            ' __out PLARGE_INTEGER LogoffTime
 , BYREF KickoffTime AS ANY _                           ' __out PLARGE_INTEGER KickoffTime
 ) AS LONG                                              ' NTSTATUS

' // Size = 64 bytes
TYPE MSV1_0_VALIDATION_INFO QWORD FILL   ' Must be 8 byte aligned
   LogoffTime      AS QUAD               ' LARGE_INTEGER
   KickoffTime     AS QUAD               ' LARGE_INTEGER
   LogonServer     AS UNICODE_STRING     ' UNICODE_STRING
   LogonDomainName AS UNICODE_STRING     ' UNICODE_STRING
   SessionKey      AS USER_SESSION_KEY   ' USER_SESSION_KEY
   Authoritative   AS BYTE               ' BOOLEAN
   UserFlags       AS DWORD              ' ULONG
   WhichFields     AS DWORD              ' ULONG
   UserId          AS DWORD              ' ULONG
END TYPE

'// values for WhichFields

%MSV1_0_VALIDATION_LOGOFF_TIME   = &H00000001???
%MSV1_0_VALIDATION_KICKOFF_TIME  = &H00000002???
%MSV1_0_VALIDATION_LOGON_SERVER  = &H00000004???
%MSV1_0_VALIDATION_LOGON_DOMAIN  = &H00000008???
%MSV1_0_VALIDATION_SESSION_KEY   = &H00000010???
%MSV1_0_VALIDATION_USER_FLAGS    = &H00000020???
%MSV1_0_VALIDATION_USER_ID       = &H00000040???

'// legal values for ActionsPerformed
%MSV1_0_SUBAUTH_ACCOUNT_DISABLED = &H00000001???
%MSV1_0_SUBAUTH_PASSWORD         = &H00000002???
%MSV1_0_SUBAUTH_WORKSTATIONS     = &H00000004???
%MSV1_0_SUBAUTH_LOGON_HOURS      = &H00000008???
%MSV1_0_SUBAUTH_ACCOUNT_EXPIRY   = &H00000010???
%MSV1_0_SUBAUTH_PASSWORD_EXPIRY  = &H00000020???
%MSV1_0_SUBAUTH_ACCOUNT_TYPE     = &H00000040???
%MSV1_0_SUBAUTH_LOCKOUT          = &H00000080???

DECLARE FUNCTION Msv1_0SubAuthenticationRoutineEx ALIAS "Msv1_0SubAuthenticationRoutineEx" ( _
   BYVAL LogonLevel AS LONG _                           ' __in  NETLOGON_LOGON_INFO_CLASS LogonLevel
 , BYREF LogonInformation AS ANY _                      ' __in  PVOID LogonInformation
 , BYVAL Flags AS DWORD _                               ' __in  ULONG Flags
 , BYREF UserAll AS USER_ALL_INFORMATION _              ' __in  PUSER_ALL_INFORMATION UserAll
 , BYREF UserHandle AS ANY _                            ' __in  SAM_HANDLE UserHandle
 , BYREF ValidationInfo AS MSV1_0_VALIDATION_INFO _     ' __in  OUT PMSV1_0_VALIDATION_INFO ValidationInfo
 , BYREF ActionsPerformed AS DWORD _                    ' __out PULONG ActionsPerformed
 ) AS LONG                                              ' NTSTATUS

DECLARE FUNCTION Msv1_0SubAuthenticationRoutineGeneric ALIAS "Msv1_0SubAuthenticationRoutineGeneric" ( _
   BYVAL SubmitBuffer AS DWORD _                        ' __in  PVOID SubmitBuffer
 , BYVAL SubmitBufferLength AS DWORD _                  ' __in  ULONG SubmitBufferLength
 , BYREF ReturnBufferLength AS DWORD _                  ' __out ULONG ReturnBufferLength
 , BYREF ReturnBuffer AS ANY _                          ' __out PVOID ReturnBuffer
 ) AS LONG                                              ' NTSTATUS

DECLARE FUNCTION Msv1_0SubAuthenticationFilter ALIAS "Msv1_0SubAuthenticationFilter" ( _
   BYVAL LogonLevel AS LONG _                           ' __in  NETLOGON_LOGON_INFO_CLASS LogonLevel
 , BYVAL LogonInformation AS DWORD _                    ' __in  PVOID LogonInformation
 , BYVAL Flags AS DWORD _                               ' __in  ULONG Flags
 , BYREF UserAll AS USER_ALL_INFORMATION _              ' __in  USER_ALL_INFORMATION UserAll
 , BYREF WhichFields AS DWORD _                         ' __out PULONG WhichFields
 , BYREF UserFlags AS DWORD _                           ' __out PULONG UserFlags
 , BYREF Authoritative AS BYTE _                        ' __out PBOOLEAN Authoritative
 , BYREF LogoffTime AS ANY _                            ' __out PLARGE_INTEGER LogoffTime
 , BYREF KickoffTime AS ANY _                           ' __out PLARGE_INTEGER KickoffTime
 ) AS LONG                                              ' NTSTATUS

%STATUS_SUCCESS                = &H00000000&
%STATUS_INVALID_INFO_CLASS     = &HC0000003&
%STATUS_NO_SUCH_USER           = &HC0000064&
%STATUS_WRONG_PASSWORD         = &HC000006A&
%STATUS_PASSWORD_RESTRICTION   = &HC000006C&
%STATUS_LOGON_FAILURE          = &HC000006D&
%STATUS_ACCOUNT_RESTRICTION    = &HC000006E&
%STATUS_INVALID_LOGON_HOURS    = &HC000006F&
%STATUS_INVALID_WORKSTATION    = &HC0000070&
%STATUS_PASSWORD_EXPIRED       = &HC0000071&
%STATUS_ACCOUNT_DISABLED       = &HC0000072&
%STATUS_INSUFFICIENT_RESOURCES = &HC000009A&
%STATUS_ACCOUNT_EXPIRED        = &HC0000193&
%STATUS_PASSWORD_MUST_CHANGE   = &HC0000224&
%STATUS_ACCOUNT_LOCKED_OUT     = &HC0000234&
