' ########################################################################################
' Microsoft Windows
' File: NTSecAPI.inc
' Contents: Local Security Authority APIs.
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%NTSECAPI_INC = 1

#INCLUDE ONCE "windows.inc"

$Audit_System_SecurityStateChange = GUID$("{0cce9210-69ae-11d9-bed3-505054503030}")
$Audit_System_SecuritySubsystemExtension = GUID$("{0cce9211-69ae-11d9-bed3-505054503030}")
$Audit_System_Integrity = GUID$("{0cce9212-69ae-11d9-bed3-505054503030}")
$Audit_System_IPSecDriverEvents = GUID$("{0cce9213-69ae-11d9-bed3-505054503030}")
$Audit_System_Others = GUID$("{0cce9214-69ae-11d9-bed3-505054503030}")
$Audit_Logon_Logon = GUID$("{0cce9215-69ae-11d9-bed3-505054503030}")
$Audit_Logon_Logoff = GUID$("{0cce9216-69ae-11d9-bed3-505054503030}")
$Audit_Logon_AccountLockout = GUID$("{0cce9217-69ae-11d9-bed3-505054503030}")
$Audit_Logon_IPSecMainMode = GUID$("{0cce9218-69ae-11d9-bed3-505054503030}")
$Audit_Logon_IPSecQuickMode = GUID$("{0cce9219-69ae-11d9-bed3-505054503030}")
$Audit_Logon_IPSecUserMode = GUID$("{0cce921a-69ae-11d9-bed3-505054503030}")
$Audit_Logon_SpecialLogon = GUID$("{0cce921b-69ae-11d9-bed3-505054503030}")
$Audit_Logon_Others = GUID$("{0cce921c-69ae-11d9-bed3-505054503030}")
$Audit_ObjectAccess_FileSystem = GUID$("{0cce921d-69ae-11d9-bed3-505054503030}")
$Audit_ObjectAccess_Registry = GUID$("{0cce921e-69ae-11d9-bed3-505054503030}")
$Audit_ObjectAccess_Kernel = GUID$("{0cce921f-69ae-11d9-bed3-505054503030}")
$Audit_ObjectAccess_Sam = GUID$("{0cce9220-69ae-11d9-bed3-505054503030}")
$Audit_ObjectAccess_CertificationServices = GUID$("{0cce9221-69ae-11d9-bed3-505054503030}")
$Audit_ObjectAccess_ApplicationGenerated = GUID$("{0cce9222-69ae-11d9-bed3-505054503030}")

'/*
'The Audit_ObjectAccess_Handle sub-category behaves different from the other sub-categories.
'For handle based audits to be generated (Open handle AuditId: 0x1230, Close handle AuditId:
'0x1232), the corresponding object sub-category AND Audit_ObjectAccess_Handle must be
'enabled. For eg, to generate handle based audits for Reg keys, both
'Audit_ObjectAccess_Registry and Audit_ObjectAccess_Handle must be enabled
'*/

$Audit_ObjectAccess_Handle = GUID$("{0cce9223-69ae-11d9-bed3-505054503030}")
$Audit_ObjectAccess_Share = GUID$("{0cce9224-69ae-11d9-bed3-505054503030}")
$Audit_ObjectAccess_FirewallPacketDrops = GUID$("{0cce9225-69ae-11d9-bed3-505054503030}")
$Audit_ObjectAccess_FirewallConnection = GUID$("{0cce9226-69ae-11d9-bed3-505054503030}")
$Audit_ObjectAccess_Other = GUID$("{0cce9227-69ae-11d9-bed3-505054503030}")
$Audit_PrivilegeUse_Sensitive = GUID$("{0cce9228-69ae-11d9-bed3-505054503030}")
$Audit_PrivilegeUse_NonSensitive = GUID$("{0cce9229-69ae-11d9-bed3-505054503030}")
$Audit_PrivilegeUse_Others = GUID$("{0cce922a-69ae-11d9-bed3-505054503030}")
$Audit_DetailedTracking_ProcessCreation = GUID$("{0cce922b-69ae-11d9-bed3-505054503030}")
$Audit_DetailedTracking_ProcessTermination = GUID$("{0cce922c-69ae-11d9-bed3-505054503030}")
$Audit_DetailedTracking_DpapiActivity = GUID$("{0cce922d-69ae-11d9-bed3-505054503030}")
$Audit_DetailedTracking_RpcCall = GUID$("{0cce922e-69ae-11d9-bed3-505054503030}")
$Audit_PolicyChange_AuditPolicy = GUID$("{0cce922f-69ae-11d9-bed3-505054503030}")
$Audit_PolicyChange_AuthenticationPolicy = GUID$("{0cce9230-69ae-11d9-bed3-505054503030}")
$Audit_PolicyChange_AuthorizationPolicy = GUID$("{0cce9231-69ae-11d9-bed3-505054503030}")
$Audit_PolicyChange_MpsscvRulePolicy = GUID$("{0cce9232-69ae-11d9-bed3-505054503030}")
$Audit_PolicyChange_WfpIPSecPolicy = GUID$("{0cce9233-69ae-11d9-bed3-505054503030}")
$Audit_PolicyChange_Others = GUID$("{0cce9234-69ae-11d9-bed3-505054503030}")
$Audit_AccountManagement_UserAccount = GUID$("{0cce9235-69ae-11d9-bed3-505054503030}")
$Audit_AccountManagement_ComputerAccount = GUID$("{0cce9236-69ae-11d9-bed3-505054503030}")
$Audit_AccountManagement_SecurityGroup = GUID$("{0cce9237-69ae-11d9-bed3-505054503030}")
$Audit_AccountManagement_DistributionGroup = GUID$("{0cce9238-69ae-11d9-bed3-505054503030}")
$Audit_AccountManagement_ApplicationGroup = GUID$("{0cce9239-69ae-11d9-bed3-505054503030}")
$Audit_AccountManagement_Others = GUID$("{0cce923a-69ae-11d9-bed3-505054503030}")
$Audit_DSAccess_DSAccess = GUID$("{0cce923b-69ae-11d9-bed3-505054503030}")
$Audit_DsAccess_AdAuditChanges = GUID$("{0cce923c-69ae-11d9-bed3-505054503030}")
$Audit_Ds_Replication = GUID$("{0cce923d-69ae-11d9-bed3-505054503030}")
$Audit_Ds_DetailedReplication = GUID$("{0cce923e-69ae-11d9-bed3-505054503030}")
$Audit_AccountLogon_CredentialValidation = GUID$("{0cce923f-69ae-11d9-bed3-505054503030}")
$Audit_AccountLogon_Kerberos = GUID$("{0cce9240-69ae-11d9-bed3-505054503030}")
$Audit_AccountLogon_Others = GUID$("{0cce9241-69ae-11d9-bed3-505054503030}")

'//
'// All categories are named as <Audit_CategoryName>
'//

$Audit_System = GUID$("{69979848-797a-11d9-bed3-505054503030}")
$Audit_Logon = GUID$("{69979849-797a-11d9-bed3-505054503030}")
$Audit_ObjectAccess = GUID$("{6997984a-797a-11d9-bed3-505054503030}")
$Audit_PrivilegeUse = GUID$("{6997984b-797a-11d9-bed3-505054503030}")
$Audit_DetailedTracking = GUID$("{6997984c-797a-11d9-bed3-505054503030}")
$Audit_PolicyChange = GUID$("{6997984d-797a-11d9-bed3-505054503030}")
$Audit_AccountManagement = GUID$("{6997984e-797a-11d9-bed3-505054503030}")
$Audit_DirectoryServiceAccess = GUID$("{6997984f-797a-11d9-bed3-505054503030}")
$Audit_AccountLogon = GUID$("{69979850-797a-11d9-bed3-505054503030}")
$Audit_AccountLogon_KerbCredentialValidation = GUID$("{0cce9242-69ae-11d9-bed3-505054503030}")
$Audit_Logon_NPS = GUID$("{0cce9243-69ae-11d9-bed3-505054503030}")
$Audit_ObjectAccess_DetailedFileShare = GUID$("{0cce9244-69ae-11d9-bed3-505054503030}")

'#ifndef _NTDEF_
'typedef LONG NTSTATUS, *PNTSTATUS;
'#endif

#INCLUDE ONCE "lsalookup.inc"

'#ifndef _NTLSA_IFS_
'// begin_ntifs


'//
'// Security operation mode of the system is held in a control
'// longword.
'//

'typedef ULONG  LSA_OPERATIONAL_MODE, *PLSA_OPERATIONAL_MODE;

'// end_ntifs
'#endif // _NTLSA_IFS_

'//
'// The flags in the security operational mode are defined
'// as:
'//
'//    PasswordProtected - Some level of authentication (such as
'//        a password) must be provided by users before they are
'//        allowed to use the system.  Once set, this value will
'//        not be cleared without re-booting the system.
'//
'//    IndividualAccounts - Each user must identify an account to
'//        logon to.  This flag is only meaningful if the
'//        PasswordProtected flag is also set.  If this flag is
'//        not set and the PasswordProtected flag is set, then all
'//        users may logon to the same account.  Once set, this value
'//        will not be cleared without re-booting the system.
'//
'//    MandatoryAccess - Indicates the system is running in a mandatory
'//        access control mode (e.g., B-level as defined by the U.S.A's
'//        Department of Defense's "Orange Book").  This is not utilized
'//        in the current release of NT.  This flag is only meaningful
'//        if both the PasswordProtected and IndividualAccounts flags are
'//        set.  Once set, this value will not be cleared without
'//        re-booting the system.
'//
'//    LogFull - Indicates the system has been brought up in a mode in
'//        which if must perform security auditing, but its audit log
'//        is full.  This may (should) restrict the operations that
'//        can occur until the audit log is made not-full again.  THIS
'//        VALUE MAY BE CLEARED WHILE THE SYSTEM IS RUNNING (I.E., WITHOUT
'//        REBOOTING).
'//
'// If the PasswordProtected flag is not set, then the system is running
'// without security, and user interface should be adjusted appropriately.
'//

%LSA_MODE_PASSWORD_PROTECTED   = &H00000001???
%LSA_MODE_INDIVIDUAL_ACCOUNTS  = &H00000002???
%LSA_MODE_MANDATORY_ACCESS     = &H00000004???
%LSA_MODE_LOG_FULL             = &H00000008???

'#ifndef _NTLSA_IFS_
'// begin_ntifs
'//
'// Used by a logon process to indicate what type of logon is being
'// requested.
'//

'typedef enum _SECURITY_LOGON_TYPE {
'    Interactive = 2,    // Interactively logged on (locally or remotely)
'    Network,            // Accessing system via network
'    Batch,              // Started via a batch queue
'    Service,            // Service started by service controller
'    Proxy,              // Proxy logon
'    Unlock,             // Unlock workstation
'    NetworkCleartext,   // Network logon with cleartext credentials
'    NewCredentials,     // Clone caller, new default credentials
'    RemoteInteractive,  // Remote, yet interactive. Terminal server
'    CachedInteractive,  // Try cached credentials without hitting the net.
'    CachedRemoteInteractive, // Same as RemoteInteractive, this is used internally for auditing purpose
'    CachedUnlock        // Cached Unlock workstation
'} SECURITY_LOGON_TYPE, *PSECURITY_LOGON_TYPE;

%SECURITY_LOGON_TYPE_Interactive             = 2  ' Interactively logged on (locally or remotely)
%SECURITY_LOGON_TYPE_Network                 = 3  ' Accessing system via network
%SECURITY_LOGON_TYPE_Batch                   = 4  ' Started via a batch queue
%SECURITY_LOGON_TYPE_Service                 = 5  ' Service started by service controller
%SECURITY_LOGON_TYPE_Proxy                   = 6  ' Proxy logon
%SECURITY_LOGON_TYPE_Unlock                  = 7  ' Unlock workstation
%SECURITY_LOGON_TYPE_NetworkCleartext        = 8  ' Network logon with cleartext credentials
%SECURITY_LOGON_TYPE_NewCredentials          = 9  ' Clone caller = 3 new default credentials
'#if (_WIN32_WINNT >= 0x0501)
%SECURITY_LOGON_TYPE_RemoteInteractive       = 10 ' Remote = 3 yet interactive. Terminal server
%SECURITY_LOGON_TYPE_CachedInteractive       = 11 ' Try cached credentials without hitting the net.
'    // The types below only exist in Windows Server 2003 and greater
'#endif
'#if (_WIN32_WINNT >= 0x0502)
%SECURITY_LOGON_TYPE_CachedRemoteInteractive = 12 ' Same as RemoteInteractive = 3 this is used internally for auditing purpose
%SECURITY_LOGON_TYPE_CachedUnlock            = 13 ' Cached Unlock workstation
'#endif

'// end_ntifs
'#endif // _NTLSA_IFS_

'#ifndef _NTLSA_IFS_
'// begin_ntifs

'#ifndef _NTLSA_AUDIT_
'#define _NTLSA_AUDIT_

'/////////////////////////////////////////////////////////////////////////
'//                                                                     //
'// Data types related to Auditing                                      //
'//                                                                     //
'/////////////////////////////////////////////////////////////////////////

'//
'// The following enumerated type is used between the reference monitor and
'// LSA in the generation of audit messages.  It is used to indicate the
'// type of data being passed as a parameter from the reference monitor
'// to LSA.  LSA is responsible for transforming the specified data type
'// into a set of unicode strings that are added to the event record in
'// the audit log.
'//

' SE_ADT_PARAMETER_TYPE enum
%SeAdtParmTypeNone               = 0
%SeAdtParmTypeString             = 1
%SeAdtParmTypeFileSpec           = 2
%SeAdtParmTypeUlong              = 3
%SeAdtParmTypeSid                = 4
%SeAdtParmTypeLogonId            = 5
%SeAdtParmTypeNoLogonId          = 6
%SeAdtParmTypeAccessMask         = 7
%SeAdtParmTypePrivs              = 8
%SeAdtParmTypeObjectTypes        = 9
%SeAdtParmTypeHexUlong           = 10
%SeAdtParmTypePtr                = 11
%SeAdtParmTypeTime               = 12
%SeAdtParmTypeGuid               = 13
'//
'// Everything below exists only in Windows Server 2003 and Greater
'//
%SeAdtParmTypeLuid               = 14
%SeAdtParmTypeHexInt64           = 15
%SeAdtParmTypeStringList         = 16
%SeAdtParmTypeSidList            = 17
%SeAdtParmTypeDuration           = 18
%SeAdtParmTypeUserAccountControl = 19
%SeAdtParmTypeNoUac              = 20
%SeAdtParmTypeMessage            = 21
%SeAdtParmTypeDateTime           = 22
%SeAdtParmTypeSockAddr           = 23
'//
'// Everything below this exists only in Windows Server 2008 and greater
'//
%SeAdtParmTypeSD                  = 24
%SeAdtParmTypeLogonHours          = 25
%SeAdtParmTypeLogonIdNoSid        = 26
%SeAdtParmTypeUlongNoConv         = 27
%SeAdtParmTypeSockAddrNoPort      = 28

'//
'// Everything below this exists only in Windows Server 2008 and greater
'//

%SeAdtParmTypeAccessReason        = 29

'#ifndef GUID_DEFINED
'#include <guiddef.h>
'#endif /* GUID_DEFINED */

#IF NOT %DEF(%GUID_DEFINED)
#INCLUDE ONCE "guiddef.inc"
#ENDIF   ' /* GUID_DEFINED */

%SE_ADT_OBJECT_ONLY = &H1

' // Size = 24 bytes
TYPE SE_ADT_OBJECT_TYPE DWORD FILL
   ObjectType AS GUID          ' GUID ObjectType
   Flags      AS WORD          ' USHORT Flags
   Level      AS WORD          ' USHORT Level
   AccessMask AS ACCESS_MASK   ' ACCESS_MASK AccessMask
END TYPE

UNION SE_ADT_PARAMETER_ARRAY_ENTRY_TYPE_UNION
   Type    AS LONG    ' SE_ADT_PARAMETER_TYPE Type
   ' // For compatibility with the PB declares
   nType   AS LONG    ' SE_ADT_PARAMETER_TYPE Type
END UNION

' // Size = 20 bytes
TYPE SE_ADT_PARAMETER_ARRAY_ENTRY DWORD
   SE_ADT_PARAMETER_ARRAY_ENTRY_TYPE_UNION
   Length  AS DWORD   ' ULONG Length
   Data(1) AS DWORD   ' ULONG_PTR Data[2]
   Address AS DWORD   ' PVOID Address
END TYPE

' // Size = 144 bytes
TYPE SE_ADT_ACCESS_REASON DWORD
   AccessMask         AS ACCESS_MASK               ' ACCESS_MASK
   AccessReasons(31)  AS DWORD                     ' ULONG[32]
   ObjectTypeIndex    AS DWORD                     ' ULONG
   AccessGranted      AS DWORD                     ' ULONG
   SecurityDescriptor AS SECURITY_DESCRIPTOR PTR   ' PSECURITY_DESCRIPTOR // multple SDs may be stored here in self-relative way.
END TYPE

'//
'// Structure that will be passed between the Reference Monitor and LSA
'// to transmit auditing information.
'//

%SE_MAX_AUDIT_PARAMETERS         = 32
%SE_MAX_GENERIC_AUDIT_PARAMETERS = 28

UNION SE_ADT_PARAMETER_ARRAY_TYPE_UNION
   Type              AS WORD    ' USHORT Type
   ' // For compatibility with the PB declares
   nType             AS WORD    ' USHORT Type
END UNION

' // Size = 664 bytes
TYPE SE_ADT_PARAMETER_ARRAY DWORD FILL
   CategoryId        AS DWORD   ' ULONG CategoryId
   AuditId           AS DWORD   ' ULONG AuditId
   ParameterCount    AS DWORD   ' ULONG ParameterCount
   Length            AS DWORD   ' ULONG Length
   FlatSubCategoryId AS WORD    ' USHORT FlatSubCategoryId
   SE_ADT_PARAMETER_ARRAY_TYPE_UNION
   Flags             AS DWORD   ' ULONG Flags
   Parameters(%SE_MAX_AUDIT_PARAMETERS - 1) AS SE_ADT_PARAMETER_ARRAY_ENTRY
                                ' SE_ADT_PARAMETER_ARRAY_ENTRY Parameters[ SE_MAX_AUDIT_PARAMETERS ];
END TYPE

%SE_ADT_PARAMETERS_SELF_RELATIVE     = &H00000001???
%SE_ADT_PARAMETERS_SEND_TO_LSA       = &H00000002???
%SE_ADT_PARAMETER_EXTENSIBLE_AUDIT   = &H00000004???
%SE_ADT_PARAMETER_GENERIC_AUDIT      = &H00000008???
%SE_ADT_PARAMETER_WRITE_SYNCHRONOUS  = &H00000010???

'#endif   ' // _NTLSA_AUDIT_

'// end_ntifs
'#endif   ' // _NTLSA_IFS_

'//
'// This macro only existed in Windows Server 2008 and after
'//

'#define LSAP_SE_ADT_PARAMETER_ARRAY_TRUE_SIZE(AuditParameters)    \
'     ( sizeof(SE_ADT_PARAMETER_ARRAY) -                           \
'       sizeof(SE_ADT_PARAMETER_ARRAY_ENTRY) *                     \
'       (SE_MAX_AUDIT_PARAMETERS - AuditParameters->ParameterCount) )

'//
'// Audit Event Categories
'//
'// The following are the built-in types or Categories of audit event.
'// WARNING!  This structure is subject to expansion.  The user should not
'// compute the number of elements of this type directly, but instead
'// should obtain the count of elements by calling LsaQueryInformationPolicy()
'// for the PolicyAuditEventsInformation class and extracting the count from
'// the MaximumAuditEventCount field of the returned structure.
'//

' POLICY_AUDIT_EVENT_TYPE enum
%AuditCategorySystem                 = 0
%AuditCategoryLogon                  = 1
%AuditCategoryObjectAccess           = 2
%AuditCategoryPrivilegeUse           = 3
%AuditCategoryDetailedTracking       = 4
%AuditCategoryPolicyChange           = 5
%AuditCategoryAccountManagement      = 6
%AuditCategoryDirectoryServiceAccess = 7
%AuditCategoryAccountLogon           = 8

'//
'// The following defines describe the auditing options for each
'// event type
'//

'// Leave options specified for this event unchanged

%POLICY_AUDIT_EVENT_UNCHANGED   = &H00000000???

'// Audit successful occurrences of events of this type

%POLICY_AUDIT_EVENT_SUCCESS     = &H00000001???

'// Audit failed attempts to cause an event of this type to occur

%POLICY_AUDIT_EVENT_FAILURE     = &H00000002???

%POLICY_AUDIT_EVENT_NONE        = &H00000004???

'// Mask of valid event auditing options

%POLICY_AUDIT_EVENT_MASK = _
    %POLICY_AUDIT_EVENT_SUCCESS OR _
    %POLICY_AUDIT_EVENT_FAILURE OR _
    %POLICY_AUDIT_EVENT_UNCHANGED OR _
    %POLICY_AUDIT_EVENT_NONE

'#ifdef _NTDEF_
'#ifndef IN
'#define IN
'#endif

'#ifndef OUT
'#define OUT
'#endif

'#ifndef OPTIONAL
'#define OPTIONAL
'#endif
'#endif  // _NTDEF_

' Not included in Windows 7 SDK, but needed here.
#IF NOT %DEF(%ANSI_STRING_DEFINED)
%ANSI_STRING_DEFINED = 1
' // Size = 8 bytes
TYPE ANSI_STRING WORD
   Length        AS WORD
   MaximumLength AS WORD
   Buffer        AS ASCIIZ PTR
END TYPE
#ENDIF

' Not included in Windows 7 SDK, but needed here.
#IF NOT %DEF(%UNICODE_STRING_DEFINED)
%UNICODE_STRING_DEFINED = 1
' // Size = 8 bytes
TYPE UNICODE_STRING WORD
   Length        AS WORD           ' USHORT Length
   MaximumLength AS WORD           ' USHORT MaximumLength
   Buffer        AS WSTRINGZ PTR   ' PWSTR  Buffer
END TYPE
#ENDIF

'#endif // _NTDEF_

'//
'// Macro for determining whether an API succeeded.
'//

'#define LSA_SUCCESS(Error) ((LONG)(Error) >= 0)

FUNCTION LSA_SUCCESS (BYVAL nError AS LONG) AS LONG
   FUNCTION = -(BITS(LONG, nError) >= 0)
END FUNCTION

'#ifndef _NTLSA_IFS_
'// begin_ntifs

DECLARE FUNCTION LsaRegisterLogonProcess IMPORT "SECUR32.DLL" ALIAS "LsaRegisterLogonProcess" ( _
   BYREF LogonProcessName AS LSA_STRING _               ' __in PLSA_STRING LogonProcessName
 , BYREF LsaHandle AS DWORD _                           ' __out PHANDLE LsaHandle
 , BYREF SecurityMode AS DWORD _                        ' __out PLSA_OPERATIONAL_MODE SecurityMode
 ) AS LONG                                              ' NTSTATUS

'//
'// The function below did not exist in NTIFS before windows XP
'// However, the function has always been there, so it is okay to use
'// even on w2k
'//

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION LsaLogonUser LIB "SECUR32.DLL" _
   ALIAS "LsaLogonUser" ( _
    BYVAL LsaHandle                       AS DWORD, _
    OriginName                            AS LSA_STRING, _
    BYVAL LogonType                       AS LONG, _
    BYVAL AuthenticationPackage           AS DWORD , _
    BYVAL AuthenticationInformation       AS DWORD, _
    BYVAL AuthenticationInformationLength AS DWORD , _
    BYVAL LocalGroups                     AS TOKEN_GROUPS PTR, _
    SourceContext                         AS TOKEN_SOURCE, _
    ProfileBuffer                         AS DWORD, _
    ProfileBufferLength                   AS DWORD, _
    LogonId                               AS QUAD, _
    Token                                 AS DWORD, _
    Quotas                                AS QUOTA_LIMITS, _
    SubStatus                             AS LONG _
    ) AS LONG
#ELSE
DECLARE FUNCTION LsaLogonUser IMPORT "SECUR32.DLL" ALIAS "LsaLogonUser" ( _
   BYVAL LsaHandle AS DWORD _                           ' __in HANDLE LsaHandle
 , BYREF OriginName AS LSA_STRING _                     ' __in PLSA_STRING OriginName
 , BYVAL LogonType AS LONG _                            ' __in SECURITY_LOGON_TYPE LogonType
 , BYVAL AuthenticationPackage AS DWORD _               ' __in ULONG AuthenticationPackage
 , BYVAL AuthenticationInformation AS DWORD _           ' __in_bcount(AuthenticationInformationLength) PVOID AuthenticationInformation
 , BYVAL AuthenticationInformationLength AS DWORD _     ' __in ULONG AuthenticationInformationLength
 , BYREF LocalGroups AS ANY _                           ' __in_opt PTOKEN_GROUPS [fake type] LocalGroups
 , BYREF SourceContext AS TOKEN_SOURCE _                ' __in PTOKEN_SOURCE SourceContext
 , BYREF ProfileBuffer AS ANY _                         ' __out PVOID *ProfileBuffer
 , BYREF ProfileBufferLength AS DWORD _                 ' __out PULONG ProfileBufferLength
 , BYREF LogonId AS QUAD _                              ' __out PLUID LogonId
 , BYREF Token AS DWORD _                               ' __out PHANDLE Token
 , BYREF Quotas AS QUOTA_LIMITS _                       ' __out PQUOTA_LIMITS Quotas
 , BYREF SubStatus AS LONG _                            ' __out PNTSTATUS SubStatus
 ) AS LONG                                              ' NTSTATUS
#ENDIF

'// end_ntifs

DECLARE FUNCTION LsaLookupAuthenticationPackage IMPORT "SECUR32.DLL" ALIAS "LsaLookupAuthenticationPackage" ( _
   BYVAL LsaHandle AS DWORD _                           ' __in HANDLE LsaHandle
 , BYREF PackageName AS LSA_STRING _                    ' __in PLSA_STRING PackageName
 , BYREF AuthenticationPackage AS DWORD _               ' __out PULONG AuthenticationPackage
 ) AS LONG                                              ' NTSTATUS

'// begin_ntifs

DECLARE FUNCTION LsaFreeReturnBuffer IMPORT "SECUR32.DLL" ALIAS "LsaFreeReturnBuffer" ( _
   BYVAL Buffer AS DWORD _                              ' __in PVOID Buffer
 ) AS LONG                                              ' NTSTATUS

'// end_ntifs

DECLARE FUNCTION LsaCallAuthenticationPackage IMPORT "SECUR32.DLL" ALIAS "LsaCallAuthenticationPackage" ( _
   BYVAL LsaHandle AS DWORD _                           ' __in HANDLE LsaHandle
 , BYVAL AuthenticationPackage AS DWORD _               ' __in ULONG AuthenticationPackage
 , BYVAL ProtocolSubmitBuffer AS DWORD _                ' __in_bcount(SubmitBufferLength) PVOID ProtocolSubmitBuffer
 , BYVAL SubmitBufferLength AS DWORD _                  ' __in ULONG SubmitBufferLength
 , BYREF ProtocolReturnBuffer AS ANY _                  ' __out_opt PVOID *ProtocolReturnBuffer
 , BYREF ReturnBufferLength AS DWORD _                  ' __out_opt PULONG ReturnBufferLength
 , BYREF ProtocolStatus AS DWORD _                      ' __out_opt PNTSTATUS ProtocolStatus
 ) AS LONG                                              ' NTSTATUS

DECLARE FUNCTION LsaDeregisterLogonProcess IMPORT "SECUR32.DLL" ALIAS "LsaDeregisterLogonProcess" ( _
   BYVAL LsaHandle AS DWORD _                           ' __in HANDLE LsaHandle
 ) AS LONG                                              ' NTSTATUS

DECLARE FUNCTION LsaConnectUntrusted IMPORT "SECUR32.DLL" ALIAS "LsaConnectUntrusted" ( _
   BYREF LsaHandle AS DWORD _                           ' __out PHANDLE LsaHandle
 ) AS LONG                                              ' NTSTATUS

'#endif // _NTLSA_IFS_

'////////////////////////////////////////////////////////////////////////////
'//                                                                        //
'// Local Security Policy Administration API datatypes and defines         //
'//                                                                        //
'////////////////////////////////////////////////////////////////////////////

'//
'// Access types for the Policy object
'//

%POLICY_VIEW_LOCAL_INFORMATION   = &H00000001???
%POLICY_VIEW_AUDIT_INFORMATION   = &H00000002???
%POLICY_GET_PRIVATE_INFORMATION  = &H00000004???
%POLICY_TRUST_ADMIN              = &H00000008???
%POLICY_CREATE_ACCOUNT           = &H00000010???
%POLICY_CREATE_SECRET            = &H00000020???
%POLICY_CREATE_PRIVILEGE         = &H00000040???
%POLICY_SET_DEFAULT_QUOTA_LIMITS = &H00000080???
%POLICY_SET_AUDIT_REQUIREMENTS   = &H00000100???
%POLICY_AUDIT_LOG_ADMIN          = &H00000200???
%POLICY_SERVER_ADMIN             = &H00000400???
%POLICY_LOOKUP_NAMES             = &H00000800???
%POLICY_NOTIFICATION             = &H00001000???

%POLICY_ALL_ACCESS =   %STANDARD_RIGHTS_REQUIRED         OR _
                       %POLICY_VIEW_LOCAL_INFORMATION    OR _
                       %POLICY_VIEW_AUDIT_INFORMATION    OR _
                       %POLICY_GET_PRIVATE_INFORMATION   OR _
                       %POLICY_TRUST_ADMIN               OR _
                       %POLICY_CREATE_ACCOUNT            OR _
                       %POLICY_CREATE_SECRET             OR _
                       %POLICY_CREATE_PRIVILEGE          OR _
                       %POLICY_SET_DEFAULT_QUOTA_LIMITS  OR _
                       %POLICY_SET_AUDIT_REQUIREMENTS    OR _
                       %POLICY_AUDIT_LOG_ADMIN           OR _
                       %POLICY_SERVER_ADMIN              OR _
                       %POLICY_LOOKUP_NAMES

%POLICY_READ       =   %STANDARD_RIGHTS_READ             OR _
                       %POLICY_VIEW_AUDIT_INFORMATION    OR _
                       %POLICY_GET_PRIVATE_INFORMATION

%POLICY_WRITE      =   %STANDARD_RIGHTS_WRITE            OR _
                       %POLICY_TRUST_ADMIN               OR _
                       %POLICY_CREATE_ACCOUNT            OR _
                       %POLICY_CREATE_SECRET             OR _
                       %POLICY_CREATE_PRIVILEGE          OR _
                       %POLICY_SET_DEFAULT_QUOTA_LIMITS  OR _
                       %POLICY_SET_AUDIT_REQUIREMENTS    OR _
                       %POLICY_AUDIT_LOG_ADMIN           OR _
                       %POLICY_SERVER_ADMIN

%POLICY_EXECUTE    =   %STANDARD_RIGHTS_EXECUTE          OR _
                       %POLICY_VIEW_LOCAL_INFORMATION    OR _
                       %POLICY_LOOKUP_NAMES

'//
'// Legacy policy object specific data types.
'//
'// The following data type is used in name to SID lookup services to describe
'// the domains referenced in the lookup operation.
'//

' // Size = 12 bytes
TYPE LSA_TRANSLATED_SID DWORD
   Use         AS LONG    ' SID_NAME_USE Use
   RelativeId  AS DWORD   ' ULONG RelativeId
   DomainIndex AS LONG    ' LONG DomainIndex
END TYPE

'// where members have the following usage:
'//
'//     Use - identifies the use of the SID.  If this value is SidUnknown or
'//         SidInvalid, then the remainder of the record is not set and
'//         should be ignored.
'//
'//     RelativeId - Contains the relative ID of the translated SID.  The
'//         remainder of the SID (the prefix) is obtained using the
'//         DomainIndex field.
'//
'//     DomainIndex - Is the index of an entry in a related
'//         LSA_REFERENCED_DOMAIN_LIST data structure describing the
'//         domain in which the account was found.
'//
'//         If there is no corresponding reference domain for an entry, then
'//         this field will contain a negative value.
'//

'//
'// The following data type is used to represent the role of the LSA
'// server (primary or backup).
'//

' POLICY_LSA_SERVER_ROLE enum
%PolicyServerRoleBackup  = 2
%PolicyServerRolePrimary = 3

'#if (_WIN32_WINNT < 0x0502)
'//
'// The following data type is used to represent the state of the LSA
'// server (enabled or disabled).  Some operations may only be performed on
'// an enabled LSA server.
'//

' enum POLICY_SERVER_ENABLE_STATE {

%PolicyServerEnabled  = 2
%PolicyServerDisabled = 3

'//
'// The following data type is used to specify the auditing options for
'// an Audit Event Type.
'//

'typedef ULONG POLICY_AUDIT_EVENT_OPTIONS, *PPOLICY_AUDIT_EVENT_OPTIONS;

'// where the following flags can be set:
'//
'//     POLICY_AUDIT_EVENT_UNCHANGED - Leave existing auditing options
'//         unchanged for events of this type.  This flag is only used for
'//         set operations.  If this flag is set, then all other flags
'//         are ignored.
'//
'//     POLICY_AUDIT_EVENT_NONE - Cancel all auditing options for events
'//         of this type.  If this flag is set, the success/failure flags
'//         are ignored.
'//
'//     POLICY_AUDIT_EVENT_SUCCESS - When auditing is enabled, audit all
'//         successful occurrences of events of the given type.
'//
'//     POLICY_AUDIT_EVENT_FAILURE - When auditing is enabled, audit all
'//         unsuccessful occurrences of events of the given type.
'//

'//
'// The following data type defines the classes of Policy Information
'// that may be queried/set.
'//

' POLICY_INFORMATION_CLASS enum
%PolicyAuditLogInformation       = 1
%PolicyAuditEventsInformation    = 2
%PolicyPrimaryDomainInformation  = 3
%PolicyPdAccountInformation      = 4
%PolicyAccountDomainInformation  = 5
%PolicyLsaServerRoleInformation  = 6
%PolicyReplicaSourceInformation  = 7
%PolicyDefaultQuotaInformation   = 8
%PolicyModificationInformation   = 9
%PolicyAuditFullSetInformation   = 10
%PolicyAuditFullQueryInformation = 11
%PolicyDnsDomainInformation      = 12
%PolicyDnsDomainInformationInt   = 13
%PolicyLocalAccountDomainInformation = 14
%PolicyLastEntry = 15

'//
'// The following data type corresponds to the PolicyAuditLogInformation
'// information class.  It is used to represent information relating to
'// the Audit Log.
'//
'// This structure may be used in both query and set operations.  However,
'// when used in set operations, some fields are ignored.
'//

' // Size = 40 bytes
TYPE POLICY_AUDIT_LOG_INFO QWORD FILL
   AuditLogPercentFull            AS DWORD   ' ULONG
   MaximumLogSize                 AS DWORD   ' ULONG
   AuditRetentionPeriod           AS QUAD    ' LARGE_INTEGER
   AuditLogFullShutdownInProgress AS BYTE    ' BOOLEAN
   TimeToShutdown                 AS QUAD    ' LARGE_INTEGER
   NextAuditRecordId              AS DWORD   ' ULONG
   dwFiller                       AS DWORD   ' // To keep QWORD alignment
END TYPE

'// where the members have the following usage:
'//
'//     AuditLogPercentFull - Indicates the percentage of the Audit Log
'//         currently being used.
'//
'//     MaximumLogSize - Specifies the maximum size of the Audit Log in
'//         kilobytes.
'//
'//     AuditRetentionPeriod - Indicates the length of time that Audit
'//         Records are to be retained.  Audit Records are discardable
'//         if their timestamp predates the current time minus the
'//         retention period.
'//
'//     AuditLogFullShutdownInProgress - Indicates whether or not a system
'//         shutdown is being initiated due to the security Audit Log becoming
'//         full.  This condition will only occur if the system is configured
'//         to shutdown when the log becomes full.
'//
'//         TRUE indicates that a shutdown is in progress
'//         FALSE indicates that a shutdown is not in progress.
'//
'//         Once a shutdown has been initiated, this flag will be set to
'//         TRUE.  If an administrator is able to currect the situation
'//         before the shutdown becomes irreversible, then this flag will
'//         be reset to false.
'//
'//         This field is ignored for set operations.
'//
'//     TimeToShutdown - If the AuditLogFullShutdownInProgress flag is set,
'//         then this field contains the time left before the shutdown
'//         becomes irreversible.
'//
'//         This field is ignored for set operations.
'//


'//
'// The following data type corresponds to the PolicyAuditEventsInformation
'// information class.  It is used to represent information relating to
'// the audit requirements.
'//

' // Size = 12 bytes
TYPE POLICY_AUDIT_EVENTS_INFO DWORD
   AuditingMode           AS BYTE        ' BOOLEAN
   EventAuditingOptions   AS DWORD PTR   ' PPOLICY_AUDIT_EVENT_OPTIONS
   MaximumAuditEventCount AS DWORD       ' ULONG
END TYPE

'// where the members have the following usage:
'//
'//     AuditingMode - A Boolean variable specifying the Auditing Mode value.
'//         This value is interpreted as follows:
'//
'//         TRUE - Auditing is to be enabled (set operations) or is enabled
'//             (query operations).  Audit Records will be generated according
'//             to the Event Auditing Options in effect (see the
'//             EventAuditingOptions field.
'//
'//         FALSE - Auditing is to be disabled (set operations) or is
'//             disabled (query operations).  No Audit Records will be
'//             generated.  Note that for set operations the Event Auditing
'//             Options in effect will still be updated as specified by the
'//             EventAuditingOptions field whether Auditing is enabled or
'//             disabled.
'//
'//    EventAuditingOptions - Pointer to an array of Auditing Options
'//        indexed by Audit Event Type.
'//
'//    MaximumAuditEventCount - Specifiesa count of the number of Audit
'//        Event Types specified by the EventAuditingOptions parameter.  If
'//        this count is less than the number of Audit Event Types supported
'//        by the system, the Auditing Options for Event Types with IDs
'//        higher than (MaximumAuditEventCount + 1) are left unchanged.
'//

'//
'// The following data type is used to represent information relating to
'// the audit requirements.
'//

' // Size = 8 bytes
TYPE POLICY_AUDIT_SUBCATEGORIES_INFO DWORD
   MaximumSubCategoryCount AS DWORD   ' ULONG
   EventAuditingOptions    AS DWORD PTR   ' PPOLICY_AUDIT_EVENT_OPTIONS
END TYPE

' // Size = 8 bytes
TYPE POLICY_AUDIT_CATEGORIES_INFO DWORD
   MaximumCategoryCount AS DWORD   ' ULONG
   SubCategoriesInfo    AS POLICY_AUDIT_SUBCATEGORIES_INFO PTR   ' PPOLICY_AUDIT_SUBCATEGORIES_INFO
END TYPE

'//
'// Valid bits for Per user policy mask.
'//

%PER_USER_POLICY_UNCHANGED               = &H00
%PER_USER_AUDIT_SUCCESS_INCLUDE          = &H01
%PER_USER_AUDIT_SUCCESS_EXCLUDE          = &H02
%PER_USER_AUDIT_FAILURE_INCLUDE          = &H04
%PER_USER_AUDIT_FAILURE_EXCLUDE          = &H08
%PER_USER_AUDIT_NONE                     = &H10

%VALID_PER_USER_AUDIT_POLICY_FLAG = %PER_USER_AUDIT_SUCCESS_INCLUDE OR _
                                    %PER_USER_AUDIT_SUCCESS_EXCLUDE OR _
                                    %PER_USER_AUDIT_FAILURE_INCLUDE OR _
                                    %PER_USER_AUDIT_FAILURE_EXCLUDE OR _
                                    %PER_USER_AUDIT_NONE


'//
'// The following structure corresponds to the PolicyPrimaryDomainInformation
'// information class.
'//

UNION POLICY_PRIMARY_DOMAIN_INFO_NAME_UNION
   Name AS LSA_UNICODE_STRING   ' LSA_UNICODE_STRING Name
   ' // For compatibility with the PB declares
   uName AS LSA_UNICODE_STRING
END UNION

UNION POLICY_PRIMARY_DOMAIN_INFO_SID_UNION
   Sid  AS SID PTR              ' PSID Sid
   ' // For compatibility with the PB declares
   pSid  AS SID PTR             ' PSID Sid
END UNION

' // Size = 12 bytes
TYPE POLICY_PRIMARY_DOMAIN_INFO DWORD
   POLICY_PRIMARY_DOMAIN_INFO_NAME_UNION
   POLICY_PRIMARY_DOMAIN_INFO_SID_UNION
END TYPE

'// where the members have the following usage:
'//
'//     Name - Is the name of the domain
'//
'//     Sid - Is the Sid of the domain
'//


'//
'// The following structure corresponds to the PolicyPdAccountInformation
'// information class.  This structure may be used in Query operations
'// only.
'//

UNION POLICY_PD_ACCOUNT_INFO_NAME_UNION
   Name AS LSA_UNICODE_STRING   ' LSA_UNICODE_STRING Name
   ' // For compatibility with the PB declares
   uName AS LSA_UNICODE_STRING
END UNION

' // Size = 8 bytes
TYPE POLICY_PD_ACCOUNT_INFO DWORD
   POLICY_PD_ACCOUNT_INFO_NAME_UNION
END TYPE

'// where the members have the following usage:
'//
'//     Name - Is the name of an account in the domain that should be used
'//         for authentication and name/ID lookup requests.
'//


'//
'// The following structure corresponds to the PolicyLsaServerRoleInformation
'// information class.
'//

' // Size = 4 bytes
TYPE POLICY_LSA_SERVER_ROLE_INFO DWORD
   LsaServerRole AS LONG   ' POLICY_LSA_SERVER_ROLE LsaServerRole
END TYPE

'// where the fields have the following usage:
'//
'// TBS
'//


'//
'// The following structure corresponds to the PolicyReplicaSourceInformation
'// information class.
'//

' // Size = 16 bytes
TYPE POLICY_REPLICA_SOURCE_INFO DWORD
   ReplicaSource      AS LSA_UNICODE_STRING   ' LSA_UNICODE_STRING ReplicaSource
   ReplicaAccountName AS LSA_UNICODE_STRING   ' LSA_UNICODE_STRING ReplicaAccountName
END TYPE

'//
'// The following structure corresponds to the PolicyDefaultQuotaInformation
'// information class.
'//

' // Size = 32 bytes
TYPE POLICY_DEFAULT_QUOTA_INFO DWORD
   QuotaLimits AS QUOTA_LIMITS   ' QUOTA_LIMITS QuotaLimits
END TYPE

'//
'// The following structure corresponds to the PolicyModificationInformation
'// information class.
'//

' // Size = 16 bytes
TYPE POLICY_MODIFICATION_INFO QWORD
   ModifiedId           AS QUAD   ' LARGE_INTEGER ModifiedId
   DatabaseCreationTime AS QUAD   ' LARGE_INTEGER DatabaseCreationTime
END TYPE

'// where the members have the following usage:
'//
'//     ModifiedId - Is a 64-bit unsigned integer that is incremented each
'//         time anything in the LSA database is modified.  This value is
'//         only modified on Primary Domain Controllers.
'//
'//     DatabaseCreationTime - Is the date/time that the LSA Database was
'//         created.  On Backup Domain Controllers, this value is replicated
'//         from the Primary Domain Controller.
'//

'//
'// The following structure type corresponds to the PolicyAuditFullSetInformation
'// Information Class.
'//

' // Size = 1 byte
TYPE POLICY_AUDIT_FULL_SET_INFO BYTE
   ShutDownOnFull AS BYTE   ' BOOLEAN ShutDownOnFull
END TYPE

'//
'// The following structure type corresponds to the PolicyAuditFullQueryInformation
'// Information Class.
'//

' // Size = 2 bytes
TYPE POLICY_AUDIT_FULL_QUERY_INFO BYTE
   ShutDownOnFull AS BYTE   ' BOOLEAN ShutDownOnFull
   LogIsFull      AS BYTE   ' BOOLEAN LogIsFull
END TYPE

'//
'// The following data type defines the classes of Policy Information
'// that may be queried/set that has domain wide effect.
'//

'typedef enum _POLICY_DOMAIN_INFORMATION_CLASS {

' POLICY_DOMAIN_INFORMATION_CLASS enum
'#if (_WIN32_WINNT <= 0x0500)
%PolicyDomainQualityOfServiceInformation = 0
'#endif
%PolicyDomainEfsInformation              = 2
%PolicyDomainKerberosTicketInformation   = 3

'#if (_WIN32_WINNT < 0x0502)
'//
'// QualityOfService information.  Corresponds to PolicyDomainQualityOfServiceInformation
'//

%POLICY_QOS_SCHANNEL_REQUIRED            = &H00000001???
%POLICY_QOS_OUTBOUND_INTEGRITY           = &H00000002???
%POLICY_QOS_OUTBOUND_CONFIDENTIALITY     = &H00000004???
%POLICY_QOS_INBOUND_INTEGRITY            = &H00000008???
%POLICY_QOS_INBOUND_CONFIDENTIALITY      = &H00000010???
%POLICY_QOS_ALLOW_LOCAL_ROOT_CERT_STORE  = &H00000020???
%POLICY_QOS_RAS_SERVER_ALLOWED           = &H00000040???
%POLICY_QOS_DHCP_SERVER_ALLOWED          = &H00000080???

'//
'// Bits 0x00000100 through 0xFFFFFFFF are reserved for future use.
'//
'#endif

'#if (_WIN32_WINNT == 0x0500)
' // Size = 4 bytes
TYPE POLICY_DOMAIN_QUALITY_OF_SERVICE_INFO DWORD
   QualityOfService AS DWORD   ' ULONG
END TYPE
'//
'// where the members have the following usage:
'//
'//  QualityOfService - Determines what specific QOS actions a machine should take
'//
'#endif

'//
'// The following structure corresponds to the PolicyEfsInformation
'// information class
'//

' // Size = 8 bytes
TYPE POLICY_DOMAIN_EFS_INFO DWORD
   InfoLength AS DWORD      ' ULONG   InfoLength
   EfsBlob    AS BYTE PTR   ' PUCHAR  EfsBlob
END TYPE

'//
'// where the members have the following usage:
'//
'//      InfoLength - Length of the EFS Information blob
'//
'//      EfsBlob - Efs blob data
'//


'//
'// The following structure corresponds to the PolicyDomainKerberosTicketInformation
'// information class
'//

%POLICY_KERBEROS_VALIDATE_CLIENT = &H00000080???

' // Size = 48 bytes
TYPE POLICY_DOMAIN_KERBEROS_TICKET_INFO QWORD FILL
   AuthenticationOptions AS DWORD   ' ULONG
   MaxServiceTicketAge   AS QUAD    ' LARGE_INTEGER
   MaxTicketAge          AS QUAD    ' LARGE_INTEGER
   MaxRenewAge           AS QUAD    ' LARGE_INTEGER
   MaxClockSkew          AS QUAD    ' LARGE_INTEGER
   Reserved              AS QUAD    ' LARGE_INTEGER
END TYPE

'//
'// where the members have the following usage
'//
'//      AuthenticationOptions -- allowed ticket options (POLICY_KERBEROS_* flags )
'//
'//      MaxServiceTicketAge   -- Maximum lifetime for a service ticket
'//
'//      MaxTicketAge -- Maximum lifetime for the initial ticket
'//
'//      MaxRenewAge -- Maximum cumulative age a renewable ticket can be with
'//                     requring authentication
'//
'//      MaxClockSkew -- Maximum tolerance for synchronization of computer clocks
'//
'//      Reserved   --  Reserved


'//
'// The following data type defines the classes of Policy Information / Policy Domain Information
'// that may be used to request notification
'//

' POLICY_NOTIFICATION_INFORMATION_CLASS enum
%PolicyNotifyAuditEventsInformation            = 1
%PolicyNotifyAccountDomainInformation          = 2
%PolicyNotifyServerRoleInformation             = 3
%PolicyNotifyDnsDomainInformation              = 4
%PolicyNotifyDomainEfsInformation              = 5
%PolicyNotifyDomainKerberosTicketInformation   = 6
%PolicyNotifyMachineAccountPasswordInformation = 7
%PolicyNotifyGlobalSaclInformation             = 8
%PolicyNotifyMax                               = 9   ' // must always be the last entry

'//
'// LSA RPC Context Handle (Opaque form).  Note that a Context Handle is
'// always a pointer type unlike regular handles.
'//

'typedef PVOID LSA_HANDLE, *PLSA_HANDLE;


'//
'// Trusted Domain Object specific data types
'//

'//
'// This data type defines the following information classes that may be
'// queried or set.
'//

' TRUSTED_INFORMATION_CLASS enum
%TrustedDomainNameInformation          = 1
%TrustedControllersInformation         = 2
%TrustedPosixOffsetInformation         = 3
%TrustedPasswordInformation            = 4
%TrustedDomainInformationBasic         = 5
%TrustedDomainInformationEx            = 6
%TrustedDomainAuthInformation          = 7
%TrustedDomainFullInformation          = 8
%TrustedDomainAuthInformationInternal  = 9
%TrustedDomainFullInformationInternal  = 10
%TrustedDomainInformationEx2Internal   = 11
%TrustedDomainFullInformation2Internal = 12
%TrustedDomainSupportedEncryptionTypes = 13

'//
'// The following data type corresponds to the TrustedDomainNameInformation
'// information class.
'//

UNION TRUSTED_DOMAIN_NAME_INFO_NAME_UNION
   Name AS LSA_UNICODE_STRING   ' LSA_UNICODE_STRING Name
   ' // For compatibility with the PB declares
   uName AS LSA_UNICODE_STRING
END UNION

' // Size = 8 bytes
TYPE TRUSTED_DOMAIN_NAME_INFO DWORD
   TRUSTED_DOMAIN_NAME_INFO_NAME_UNION
END TYPE

'// where members have the following meaning:
'//
'// Name - The name of the Trusted Domain.
'//

'//
'// The following data type corresponds to the TrustedControllersInformation
'// information class.
'//

' // Size = 8 bytes
TYPE TRUSTED_CONTROLLERS_INFO DWORD
   Entries AS DWORD                    ' ULONG Entries
   Names   AS LSA_UNICODE_STRING PTR   ' PLSA_UNICODE_STRING Names
END TYPE

'// where members have the following meaning:
'//
'// Entries - Indicate how mamy entries there are in the Names array.
'//
'// Names - Pointer to an array of LSA_UNICODE_STRING structures containing the
'//     names of domain controllers of the domain.  This information may not
'//     be accurate and should be used only as a hint.  The order of this
'//     list is considered significant and will be maintained.
'//
'//     By convention, the first name in this list is assumed to be the
'//     Primary Domain Controller of the domain.  If the Primary Domain
'//     Controller is not known, the first name should be set to the NULL
'//     string.
'//


'//
'// The following data type corresponds to the TrustedPosixOffsetInformation
'// information class.
'//

' // Size = 4 bytes
TYPE TRUSTED_POSIX_OFFSET_INFO DWORD
   Offset AS DWORD   ' ULONG Offset
END TYPE

'// where members have the following meaning:
'//
'// Offset - Is an offset to use for the generation of Posix user and group
'//     IDs from SIDs.  The Posix ID corresponding to any particular SID is
'//     generated by adding the RID of that SID to the Offset of the SID's
'//     corresponding TrustedDomain object.
'//

'//
'// The following data type corresponds to the TrustedPasswordInformation
'// information class.
'//

' // Size = 16 bytes
TYPE TRUSTED_PASSWORD_INFO DWORD
   Password    AS LSA_UNICODE_STRING   ' LSA_UNICODE_STRING Password
   OldPassword AS LSA_UNICODE_STRING   ' LSA_UNICODE_STRING OldPassword
END TYPE

' // Size = 12 bytes
MACRO TRUSTED_DOMAIN_INFORMATION_BASIC = LSA_TRUST_INFORMATION

'//
'// Direction of the trust
'//
%TRUST_DIRECTION_DISABLED        = &H00000000???
%TRUST_DIRECTION_INBOUND         = &H00000001???
%TRUST_DIRECTION_OUTBOUND        = &H00000002???
%TRUST_DIRECTION_BIDIRECTIONAL   = %TRUST_DIRECTION_INBOUND OR %TRUST_DIRECTION_OUTBOUND

%TRUST_TYPE_DOWNLEVEL            = &H00000001???  ' NT4 and before
%TRUST_TYPE_UPLEVEL              = &H00000002???  ' NT5
%TRUST_TYPE_MIT                  = &H00000003???  ' Trust with a MIT Kerberos realm

'#if (_WIN32_WINNT < 0x0502)
%TRUST_TYPE_DCE                  = &H00000004???  ' // Trust with a DCE realm
'#endif

'// Levels 0x5 - 0x000FFFFF reserved for future use
'// Provider specific trust levels are from 0x00100000 to 0xFFF00000

%TRUST_ATTRIBUTE_NON_TRANSITIVE     = &H00000001???  ' // Disallow transitivity
%TRUST_ATTRIBUTE_UPLEVEL_ONLY       = &H00000002???  ' // Trust link only valid for uplevel client
'#if (_WIN32_WINNT == 0x0500)
%TRUST_ATTRIBUTE_TREE_PARENT        = &H00400000???  ' // Denotes that we are setting the trust
                                                     ' // to our parent in the org tree...
%TRUST_ATTRIBUTE_TREE_ROOT          = &H00800000???  ' // Denotes that we are setting the trust
                                                     ' // to another tree root in a forest...
'// Trust attributes 0x00000004 through 0x004FFFFF reserved for future use
'// Trust attributes 0x00F00000 through 0x00400000 are reserved for internal use
'// Trust attributes 0x01000000 through 0xFF000000 are reserved for user
'// defined values
'%TRUST_ATTRIBUTES_VALID             = &HFF02FFFF???
'#endif
'#if (_WIN32_WINNT < 0x0502)
'#define TRUST_ATTRIBUTE_FILTER_SIDS        0x00000004  // Used to quarantine domains
'#else
%TRUST_ATTRIBUTE_QUARANTINED_DOMAIN = &H00000004???  ' // Used to quarantine domains
'#endif
'#if (_WIN32_WINNT >= 0x0501)
%TRUST_ATTRIBUTE_FOREST_TRANSITIVE  = &H00000008???  ' // This link may contain forest trust information
'#if (_WIN32_WINNT >= 0x0502)
%TRUST_ATTRIBUTE_CROSS_ORGANIZATION = &H00000010???  ' // This trust is to a domain/forest which is not part of this enterprise
%TRUST_ATTRIBUTE_WITHIN_FOREST      = &H00000020???  ' // Trust is internal to this forest
%TRUST_ATTRIBUTE_TREAT_AS_EXTERNAL  = &H00000040???  ' // Trust is to be treated as external for trust boundary purposes
'#if (_WIN32_WINNT >= 0x0600)
%TRUST_ATTRIBUTE_TRUST_USES_RC4_ENCRYPTION = &H00000080??? ' // MIT trust with RC4
%TRUST_ATTRIBUTE_TRUST_USES_AES_KEYS       = &H00000100??? ' // Use AES keys to encrypte KRB TGTs
'#endif
'// Trust attributes 0x00000040 through 0x00200000 are reserved for future use
'#else
'// Trust attributes 0x00000010 through 0x00200000 are reserved for future use
'#endif
'// Trust attributes 0x00400000 through 0x00800000 were used previously (up to W2K) and should not be re-used
'// Trust attributes 0x01000000 through 0x80000000 are reserved for user
%TRUST_ATTRIBUTES_VALID          = &HFF03FFFF???
'#endif
%TRUST_ATTRIBUTES_USER           = &HFF000000???

UNION TRUSTED_DOMAIN_INFORMATION_EX_NAME_UNION
   Name AS LSA_UNICODE_STRING   ' LSA_UNICODE_STRING Name
   ' // For compatibility with the PB declares
   uName AS LSA_UNICODE_STRING
END UNION

UNION TRUSTED_DOMAIN_INFORMATION_EX_SID_UNION
   Sid             AS SID PTR              ' PSID Sid
   ' // For compatibility with the PB declares
   pSid            AS SID PTR              ' PSID Sid
END UNION

' // Size = 32 bytes
TYPE TRUSTED_DOMAIN_INFORMATION_EX DWORD
   TRUSTED_DOMAIN_INFORMATION_EX_NAME_UNION
   FlatName        AS LSA_UNICODE_STRING   ' LSA_UNICODE_STRING FlatName
   TRUSTED_DOMAIN_INFORMATION_EX_SID_UNION
   TrustDirection  AS DWORD                ' ULONG TrustDirection
   TrustType       AS DWORD                ' ULONG TrustType
   TrustAttributes AS DWORD                ' ULONG TrustAttributes
END TYPE

UNION TRUSTED_DOMAIN_INFORMATION_EX2_NAME_UNION
   Name AS LSA_UNICODE_STRING   ' LSA_UNICODE_STRING Name
   ' // For compatibility with the PB declares
   uName AS LSA_UNICODE_STRING
END UNION

UNION TRUSTED_DOMAIN_INFORMATION_EX2_SID_UNION
   Sid             AS SID PTR              ' PSID Sid
   ' // For compatibility with the PB declares
   pSid            AS SID PTR              ' PSID Sid
END UNION

' // Size = 40 bytes
TYPE TRUSTED_DOMAIN_INFORMATION_EX2 DWORD
   TRUSTED_DOMAIN_INFORMATION_EX2_NAME_UNION
   FlatName          AS LSA_UNICODE_STRING   ' LSA_UNICODE_STRING FlatName
   TRUSTED_DOMAIN_INFORMATION_EX2_SID_UNION
   TrustDirection    AS DWORD                ' ULONG TrustDirection
   TrustType         AS DWORD                ' ULONG TrustType
   TrustAttributes   AS DWORD                ' ULONG TrustAttributes
   ForestTrustLength AS DWORD                ' ULONG ForestTrustLength
   ForestTrustInfo   AS BYTE PTR             ' PUCHAR ForestTrustInfo
END TYPE

'//
'// Type of authentication information
'//
%TRUST_AUTH_TYPE_NONE    = 0   ' Ignore this entry
%TRUST_AUTH_TYPE_NT4OWF  = 1   ' NT4 OWF password
%TRUST_AUTH_TYPE_CLEAR   = 2   ' Cleartext password
%TRUST_AUTH_TYPE_VERSION = 3   ' Cleartext password version number

' // Size = 24 bytes
TYPE LSA_AUTH_INFORMATION QWORD FILL
   LastUpdateTime AS QUAD       ' LARGE_INTEGER
   AuthType       AS DWORD      ' ULONG
   AuthInfoLength AS DWORD      ' ULONG
   AuthInfo       AS BYTE PTR   ' PUCHAR
   filler         AS DWORD      ' // To keep QWORD alignment
END TYPE

' // Size = 24 bytes
TYPE TRUSTED_DOMAIN_AUTH_INFORMATION DWORD
   IncomingAuthInfos                         AS DWORD                      ' ULONG
   IncomingAuthenticationInformation         AS LSA_AUTH_INFORMATION PTR   ' PLSA_AUTH_INFORMATION
   IncomingPreviousAuthenticationInformation AS LSA_AUTH_INFORMATION PTR   ' PLSA_AUTH_INFORMATION
   OutgoingAuthInfos                         AS DWORD                      ' ULONG
   OutgoingAuthenticationInformation         AS LSA_AUTH_INFORMATION PTR   ' PLSA_AUTH_INFORMATION
   OutgoingPreviousAuthenticationInformation AS LSA_AUTH_INFORMATION PTR   ' PLSA_AUTH_INFORMATION
END TYPE

' // Size = 60 bytes
TYPE TRUSTED_DOMAIN_FULL_INFORMATION DWORD
   Information     AS TRUSTED_DOMAIN_INFORMATION_EX
   PosixOffset     AS TRUSTED_POSIX_OFFSET_INFO
   AuthInformation AS TRUSTED_DOMAIN_AUTH_INFORMATION
END TYPE

' // Size = 68 bytes
TYPE TRUSTED_DOMAIN_FULL_INFORMATION2 DWORD
   Information     AS TRUSTED_DOMAIN_INFORMATION_EX2
   PosixOffset     AS TRUSTED_POSIX_OFFSET_INFO
   AuthInformation AS TRUSTED_DOMAIN_AUTH_INFORMATION
END TYPE

' // Size = 4 bytes
TYPE TRUSTED_DOMAIN_SUPPORTED_ENCRYPTION_TYPES DWORD
   SupportedEncryptionTypes AS DWORD   ' ULONG
END TYPE

' LSA_FOREST_TRUST_RECORD_TYPE enum
%ForestTrustTopLevelName   = 0
%ForestTrustTopLevelNameEx = 1
%ForestTrustDomainInfo     = 2
%ForestTrustRecordTypeLast = %ForestTrustDomainInfo

'#if (_WIN32_WINNT < 0x0502)
%LSA_FOREST_TRUST_RECORD_TYPE_UNRECOGNIZED = &H80000000???
'#endif

'//
'// Bottom 16 bits of the flags are reserved for disablement reasons
'//

%LSA_FTRECORD_DISABLED_REASONS = &H0000FFFF???

'//
'// Reasons for a top-level name forest trust record to be disabled
'//

%LSA_TLN_DISABLED_NEW      = &H00000001???
%LSA_TLN_DISABLED_ADMIN    = &H00000002???
%LSA_TLN_DISABLED_CONFLICT = &H00000004???

'//
'// Reasons for a domain information forest trust record to be disabled
'//

%LSA_SID_DISABLED_ADMIN    = &H00000001???
%LSA_SID_DISABLED_CONFLICT = &H00000002???
%LSA_NB_DISABLED_ADMIN     = &H00000004???
%LSA_NB_DISABLED_CONFLICT  = &H00000008???

UNION LSA_FOREST_TRUST_DOMAIN_INFO_SID_UNION
   Sid         AS SID PTR              ' PSID Sid
   ' // For compatibility with the PB declares
   pSid        AS SID PTR              ' PSID Sid
END UNION

' // Size = 20 bytes
TYPE LSA_FOREST_TRUST_DOMAIN_INFO DWORD
   LSA_FOREST_TRUST_DOMAIN_INFO_SID_UNION
   DnsName     AS LSA_UNICODE_STRING   ' LSA_UNICODE_STRING DnsName
   NetbiosName AS LSA_UNICODE_STRING   ' LSA_UNICODE_STRING NetbiosName
END TYPE

'#if (_WIN32_WINNT >= 0x0502)
'//
'//  To prevent huge data to be passed in, we should put a limit on LSA_FOREST_TRUST_BINARY_DATA.
'//      128K is large enough that can't be reached in the near future, and small enough not to
'//      cause memory problems.

%MAX_FOREST_TRUST_BINARY_DATA_SIZE = 128 * 1024
'#endif

' // Size = 8 bytes
TYPE LSA_FOREST_TRUST_BINARY_DATA DWORD
   Length AS DWORD      ' ULONG Length
   Buffer AS BYTE PTR   ' PUCHAR Buffer
END TYPE

' // Size = 20 bytes
UNION LSA_FOREST_TRUST_RECORD_ForestTrustData DWORD
   TopLevelName AS LSA_UNICODE_STRING
   DomainInfo   AS LSA_FOREST_TRUST_DOMAIN_INFO
   tData        AS LSA_FOREST_TRUST_BINARY_DATA
END UNION

' // Size = 40 bytes
TYPE LSA_FOREST_TRUST_RECORD   ' Must be 8 byte aligned
   Flags           AS DWORD   ' ULONG
   ForestTrustType AS LONG    ' LSA_FOREST_TRUST_RECORD_TYPE
   Time            AS QUAD    ' LARGE_INTEGER
   LSA_FOREST_TRUST_RECORD_ForestTrustData
   alignment__     AS DWORD   ' // To keep 8 byte alignment
END TYPE

'#if (_WIN32_WINNT >= 0x0502)
'//
'// To prevent forest trust blobs of large size, number of records must be
'// smaller than MAX_RECORDS_IN_FOREST_TRUST_INFO
'//

%MAX_RECORDS_IN_FOREST_TRUST_INFO = 4000
'#endif
' // Size = 8 bytes
TYPE LSA_FOREST_TRUST_INFORMATION DWORD
   RecordCount AS DWORD   ' ULONG RecordCount
   Entries     AS DWORD   ' PLSA_FOREST_TRUST_RECORD * Entries
END TYPE

' LSA_FOREST_TRUST_COLLISION_RECORD_TYPE enum
%CollisionTdo   = 0
%CollisionXref  = 1
%CollisionOther = 2

UNION LSA_FOREST_TRUST_COLLISION_RECORD_TYPE_UNION
   Type  AS LONG                 ' LSA_FOREST_TRUST_COLLISION_RECORD_TYPE
   ' // For compatibility with the PB declares
   tType  AS LONG                ' LSA_FOREST_TRUST_COLLISION_RECORD_TYPE
END UNION

UNION LSA_FOREST_TRUST_COLLISION_RECORD_NAME_UNION
   Name  AS LSA_UNICODE_STRING   ' LSA_UNICODE_STRING
   ' // For compatibility with the PB declares
   uName AS LSA_UNICODE_STRING   ' LSA_UNICODE_STRING
END UNION

' // Size = 20 bytes
TYPE LSA_FOREST_TRUST_COLLISION_RECORD DWORD
   Index AS DWORD                ' ULONG
   LSA_FOREST_TRUST_COLLISION_RECORD_TYPE_UNION
   Flags AS DWORD                ' ULONG
   LSA_FOREST_TRUST_COLLISION_RECORD_NAME_UNION
END TYPE

' // Size = 8 bytes
TYPE LSA_FOREST_TRUST_COLLISION_INFORMATION DWORD
   RecordCount AS DWORD   ' ULONG RecordCount
   Entries     AS DWORD   ' PLSA_FOREST_TRUST_COLLISION_RECORD * Entries
END TYPE

'//
'// LSA Enumeration Context
'//

'typedef ULONG LSA_ENUMERATION_HANDLE, *PLSA_ENUMERATION_HANDLE;

'//
'// LSA Enumeration Information
'//

UNION LSA_ENUMERATION_INFORMATION_SID_UNION
   Sid AS SID PTR    ' PSID Sid
   ' // For compatibility with the PB declares
   pSid AS SID PTR   ' PSID Sid
END UNION

' // Size = 4 bytes
TYPE LSA_ENUMERATION_INFORMATION DWORD
   LSA_ENUMERATION_INFORMATION_SID_UNION
END TYPE


'////////////////////////////////////////////////////////////////////////////
'//                                                                        //
'// Local Security Policy - Miscellaneous API function prototypes          //
'//                                                                        //
'////////////////////////////////////////////////////////////////////////////

DECLARE FUNCTION LsaFreeMemory IMPORT "ADVAPI32.DLL" ALIAS "LsaFreeMemory" ( _
   BYVAL Buffer AS DWORD _                              ' __in_opt PVOID Buffer
 ) AS LONG                                              ' NTSTATUS

DECLARE FUNCTION LsaClose IMPORT "ADVAPI32.DLL" ALIAS "LsaClose" ( _
   BYVAL ObjectHandle AS DWORD _                        ' __in LSA_HANDLE ObjectHandle
 ) AS LONG                                              ' NTSTATUS

'#if (_WIN32_WINNT >= 0x0600)

' // Size = 24 bytes
TYPE LSA_LAST_INTER_LOGON_INFO QWORD
   LastSuccessfulLogon                        AS QUAD    ' LARGE_INTEGER
   LastFailedLogon                            AS QUAD    ' LARGE_INTEGER
   FailedAttemptCountSinceLastSuccessfulLogon AS DWORD   ' ULONG
END TYPE

'#endif

'#if (_WIN32_WINNT >= 0x0501)
' // Size = 184 bytes
TYPE SECURITY_LOGON_SESSION_DATA   ' Must be 8 byte aligned
   Size                  AS DWORD                ' ULONG
   LogonId               AS QUAD                 ' LUID
   UserName              AS LSA_UNICODE_STRING   ' LSA_UNICODE_STRING
   LogonDomain           AS LSA_UNICODE_STRING   ' LSA_UNICODE_STRING
   AuthenticationPackage AS LSA_UNICODE_STRING   ' LSA_UNICODE_STRING
   LogonType             AS DWORD                ' ULONG
   Session               AS DWORD                ' ULONG
   Sid                   AS SID PTR              ' PSID
   LogonTime             AS QUAD                 ' LARGE_INTEGER
   ' // new for whistler:
   LogonServer           AS LSA_UNICODE_STRING   ' LSA_UNICODE_STRING
   DnsDomainName         AS LSA_UNICODE_STRING   ' LSA_UNICODE_STRING
   Upn                   AS LSA_UNICODE_STRING   ' LSA_UNICODE_STRING
'#if (_WIN32_WINNT >= 0x0600)
   ' // new for LH
   UserFlags             AS DWORD                ' ULONG
   alignment__           AS DWORD                ' // To keep 8 byte alignment
   LastLogonInfo         AS LSA_LAST_INTER_LOGON_INFO
   LogonScript           AS LSA_UNICODE_STRING
   ProfilePath           AS LSA_UNICODE_STRING
   HomeDirectory         AS LSA_UNICODE_STRING
   HomeDirectoryDrive    AS LSA_UNICODE_STRING
   LogoffTime            AS QUAD                 ' LARGE_INTEGER
   KickOffTime           AS QUAD                 ' LARGE_INTEGER
   PasswordLastSet       AS QUAD                 ' LARGE_INTEGER
   PasswordCanChange     AS QUAD                 ' LARGE_INTEGER
   PasswordMustChange    AS QUAD                 ' LARGE_INTEGER
'#endif
END TYPE

DECLARE FUNCTION LsaEnumerateLogonSessions IMPORT "SECUR32.DLL" ALIAS "LsaEnumerateLogonSessions" ( _
   BYREF LogonSessionCount AS DWORD _                   ' __out PULONG LogonSessionCount
 , BYREF LogonSessionList AS DWORD _                    ' __out PLUID * LogonSessionList
 ) AS LONG                                              ' NTSTATUS

DECLARE FUNCTION LsaGetLogonSessionData IMPORT "SECUR32.DLL" ALIAS "LsaGetLogonSessionData" ( _
   BYREF LogonId AS QUAD _                              ' __in PLUID LogonId
 , BYREF ppLogonSessionData AS DWORD _                  ' __out PSECURITY_LOGON_SESSION_DATA * ppLogonSessionData
 ) AS LONG                                              ' NTSTATUS
'#endif

DECLARE FUNCTION LsaOpenPolicy IMPORT "ADVAPI32.DLL" ALIAS "LsaOpenPolicy" ( _
   BYREF SystemName AS LSA_UNICODE_STRING _             ' __in_opt PLSA_UNICODE_STRING SystemName
 , BYREF ObjectAttributes AS LSA_OBJECT_ATTRIBUTES _    ' __in PLSA_OBJECT_ATTRIBUTES ObjectAttributes
 , BYVAL DesiredAccess AS ACCESS_MASK _                 ' __in ACCESS_MASK DesiredAccess
 , BYREF PolicyHandle AS DWORD _                        ' __out PLSA_HANDLE PolicyHandle
 ) AS LONG                                              ' NTSTATUS

DECLARE FUNCTION LsaQueryInformationPolicy IMPORT "ADVAPI32.DLL" ALIAS "LsaQueryInformationPolicy" ( _
   BYVAL PolicyHandle AS DWORD _                        ' __in LSA_HANDLE PolicyHandle
 , BYVAL InformationClass AS LONG _                     ' __in POLICY_INFORMATION_CLASS InformationClass
 , BYREF Buffer AS ANY _                                ' __out PVOID *Buffer
 ) AS LONG                                              ' NTSTATUS

DECLARE FUNCTION LsaSetInformationPolicy IMPORT "ADVAPI32.DLL" ALIAS "LsaSetInformationPolicy" ( _
   BYVAL PolicyHandle AS DWORD _                        ' __in LSA_HANDLE PolicyHandle
 , BYVAL InformationClass AS LONG _                     ' __in POLICY_INFORMATION_CLASS InformationClass
 , BYVAL Buffer AS DWORD _                              ' __in PVOID Buffer
 ) AS LONG                                              ' NTSTATUS

DECLARE FUNCTION LsaQueryDomainInformationPolicy IMPORT "ADVAPI32.DLL" ALIAS "LsaQueryDomainInformationPolicy" ( _
   BYVAL PolicyHandle AS DWORD _                        ' __in LSA_HANDLE PolicyHandle
 , BYVAL InformationClass AS LONG _                     ' __in POLICY_DOMAIN_INFORMATION_CLASS InformationClass
 , BYREF Buffer AS ANY _                                ' __out PVOID *Buffer
 ) AS LONG                                              ' NTSTATUS

DECLARE FUNCTION LsaSetDomainInformationPolicy IMPORT "ADVAPI32.DLL" ALIAS "LsaSetDomainInformationPolicy" ( _
   BYVAL PolicyHandle AS DWORD _                        ' __in LSA_HANDLE PolicyHandle
 , BYVAL InformationClass AS LONG _                     ' __in POLICY_DOMAIN_INFORMATION_CLASS InformationClass
 , BYVAL Buffer AS DWORD _                              ' __in_opt PVOID Buffer
 ) AS LONG                                              ' NTSTATUS

DECLARE FUNCTION LsaRegisterPolicyChangeNotification IMPORT "SECUR32.DLL" ALIAS "LsaRegisterPolicyChangeNotification" ( _
   BYVAL InformationClass AS LONG _                     ' __in POLICY_NOTIFICATION_INFORMATION_CLASS InformationClass
 , BYVAL NotificationEventHandle AS DWORD _             ' __in HANDLE  NotificationEventHandle
 ) AS LONG                                              ' NTSTATUS

DECLARE FUNCTION LsaUnregisterPolicyChangeNotification IMPORT "SECUR32.DLL" ALIAS "LsaUnregisterPolicyChangeNotification" ( _
   BYVAL InformationClass AS LONG _                     ' __in POLICY_NOTIFICATION_INFORMATION_CLASS InformationClass
 , BYVAL NotificationEventHandle AS DWORD _             ' __in HANDLE  NotificationEventHandle
 ) AS LONG                                              ' NTSTATUS

DECLARE FUNCTION LsaEnumerateTrustedDomains IMPORT "ADVAPI32.DLL" ALIAS "LsaEnumerateTrustedDomains" ( _
   BYVAL PolicyHandle AS DWORD _                        ' __in LSA_HANDLE PolicyHandle
 , BYREF EnumerationContext AS DWORD _                  ' __inout PLSA_ENUMERATION_HANDLE EnumerationContext
 , BYREF Buffer AS ANY _                                ' __out PVOID *Buffer
 , BYVAL PreferedMaximumLength AS DWORD _               ' __in ULONG PreferedMaximumLength
 , BYREF CountReturned AS DWORD _                       ' __out PULONG CountReturned
 ) AS LONG                                              ' NTSTATUS

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION LsaLookupNames LIB "ADVAPI32.DLL" _
   ALIAS "LsaLookupNames" ( _
    BYVAL PolicyHandle AS DWORD, _
    BYVAL COUNT AS DWORD, _
    BYVAL Names AS LSA_UNICODE_STRING PTR, _
    ReferencedDomains AS DWORD, _
    Sids AS DWORD _
    ) AS LONG
#ELSE
DECLARE FUNCTION LsaLookupNames IMPORT "ADVAPI32.DLL" ALIAS "LsaLookupNames" ( _
   BYVAL PolicyHandle AS DWORD _                        ' __in LSA_HANDLE PolicyHandle
 , BYVAL Count AS DWORD _                               ' __in ULONG Count
 , BYREF Names AS LSA_UNICODE_STRING _                  ' __in PLSA_UNICODE_STRING Names
 , BYREF ReferencedDomains AS DWORD _                   ' __out PLSA_REFERENCED_DOMAIN_LIST *ReferencedDomains
 , BYREF Sids AS DWORD _                                ' __out PLSA_TRANSLATED_SID *Sids
 ) AS LONG                                              ' NTSTATUS
#ENDIF

'#if (_WIN32_WINNT >= 0x0501)
#IF %DEF(%USEPBDECL)
DECLARE FUNCTION LsaLookupNames2 LIB "ADVAPI32.DLL" _
   ALIAS "LsaLookupNames2" ( _
    BYVAL PolicyHandle AS DWORD, _
    BYVAL Flags AS DWORD, _  ' Reserved
    BYVAL COUNT AS DWORD, _
    BYVAL Names AS LSA_UNICODE_STRING PTR, _
    ReferencedDomains AS DWORD, _
    Sids AS DWORD _
    ) AS LONG
#ELSE
DECLARE FUNCTION LsaLookupNames2 IMPORT "ADVAPI32.DLL" ALIAS "LsaLookupNames2" ( _
   BYVAL PolicyHandle AS DWORD _                        ' __in LSA_HANDLE PolicyHandle
 , BYVAL Flags AS DWORD _                               ' __in ULONG Flags // Reserved
 , BYVAL Count AS DWORD _                               ' __in ULONG Count
 , BYREF Names AS LSA_UNICODE_STRING _                  ' __in PLSA_UNICODE_STRING Names
 , BYREF ReferencedDomains AS DWORD _                   ' __out PLSA_REFERENCED_DOMAIN_LIST *ReferencedDomains
 , BYREF Sids AS DWORD _                                ' __out PLSA_TRANSLATED_SID2 *Sids
 ) AS LONG                                              ' NTSTATUS
#ENDIF
'#endif

DECLARE FUNCTION LsaLookupSids IMPORT "ADVAPI32.DLL" ALIAS "LsaLookupSids" ( _
   BYVAL PolicyHandle AS DWORD _                        ' __in LSA_HANDLE PolicyHandle
 , BYVAL Count AS DWORD _                               ' __in ULONG Count
 , BYVAL Sids AS SID PTR _                              ' __in PSID *Sids
 , BYREF ReferencedDomains AS DWORD _                   ' __out PLSA_REFERENCED_DOMAIN_LIST *ReferencedDomains
 , BYREF Names AS DWORD _                               ' __out PLSA_TRANSLATED_NAME *Names
 ) AS LONG                                              ' NTSTATUS

$$SE_INTERACTIVE_LOGON_NAME             = "SeInteractiveLogonRight"$$
$$SE_NETWORK_LOGON_NAME                 = "SeNetworkLogonRight"$$
$$SE_BATCH_LOGON_NAME                   = "SeBatchLogonRight"$$
$$SE_SERVICE_LOGON_NAME                 = "SeServiceLogonRight"$$
$$SE_DENY_INTERACTIVE_LOGON_NAME        = "SeDenyInteractiveLogonRight"$$
$$SE_DENY_NETWORK_LOGON_NAME            = "SeDenyNetworkLogonRight"$$
$$SE_DENY_BATCH_LOGON_NAME              = "SeDenyBatchLogonRight"$$
$$SE_DENY_SERVICE_LOGON_NAME            = "SeDenyServiceLogonRight"$$
'#if (_WIN32_WINNT >= 0x0501)
$$SE_REMOTE_INTERACTIVE_LOGON_NAME      = "SeRemoteInteractiveLogonRight"$$
$$SE_DENY_REMOTE_INTERACTIVE_LOGON_NAME = "SeDenyRemoteInteractiveLogonRight"$$
'#endif

'//
'// This new API returns all the accounts with a certain privilege
'//

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION LsaEnumerateAccountsWithUserRight LIB "ADVAPI32.DLL" _
   ALIAS "LsaEnumerateAccountsWithUserRight" ( _
    BYVAL PolicyHandle AS DWORD, _
    UserRights         AS LSA_UNICODE_STRING, _
    EnumerationBuffer  AS DWORD, _
    CountReturned      AS DWORD _
    ) AS LONG
#ELSE
DECLARE FUNCTION LsaEnumerateAccountsWithUserRight IMPORT "ADVAPI32.DLL" ALIAS "LsaEnumerateAccountsWithUserRight" ( _
   BYVAL PolicyHandle AS DWORD _                        ' __in LSA_HANDLE PolicyHandle
 , BYREF UserRight AS LSA_UNICODE_STRING _              ' __in_opt PLSA_UNICODE_STRING UserRight
 , BYREF Buffer AS ANY _                                ' __out PVOID *Buffer
 , BYREF CountReturned AS DWORD _                       ' __out PULONG CountReturned
 ) AS LONG                                              ' NTSTATUS
#ENDIF

'//
'// These new APIs differ by taking a SID instead of requiring the caller
'// to open the account first and passing in an account handle
'//

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION LsaEnumerateAccountRights LIB "ADVAPI32.DLL" _
   ALIAS "LsaEnumerateAccountRights" ( _
    BYVAL PolicyHandle AS DWORD, _
    AccountSid         AS SID, _
    UserRights         AS DWORD, _
    CountOfRights      AS DWORD _
    ) AS LONG
#ELSE
DECLARE FUNCTION LsaEnumerateAccountRights IMPORT "ADVAPI32.DLL" ALIAS "LsaEnumerateAccountRights" ( _
   BYVAL PolicyHandle AS DWORD _                        ' __in LSA_HANDLE PolicyHandle
 , BYVAL AccountSid AS SID PTR _                        ' __in PSID AccountSid
 , BYREF UserRights AS LSA_UNICODE_STRING _             ' __deref_out_ecount(*CountOfRights) PLSA_UNICODE_STRING *UserRights
 , BYREF CountOfRights AS DWORD _                       ' __out PULONG CountOfRights
 ) AS LONG                                              ' NTSTATUS
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION LsaAddAccountRights LIB "ADVAPI32.DLL" _
   ALIAS "LsaAddAccountRights" ( _
    BYVAL PolicyHandle  AS DWORD, _
    AccountSid          AS SID, _
    UserRights          AS LSA_UNICODE_STRING, _
    BYVAL CountOfRights AS DWORD _
    ) AS LONG
#ELSE
DECLARE FUNCTION LsaAddAccountRights IMPORT "ADVAPI32.DLL" ALIAS "LsaAddAccountRights" ( _
   BYVAL PolicyHandle AS DWORD _                        ' __in LSA_HANDLE PolicyHandle
 , BYVAL AccountSid AS SID PTR _                        ' __in PSID AccountSid
 , BYREF UserRights AS LSA_UNICODE_STRING _             ' __in_ecount(CountOfRights) PLSA_UNICODE_STRING UserRights
 , BYVAL CountOfRights AS DWORD _                       ' __in ULONG CountOfRights
 ) AS LONG                                              ' NTSTATUS
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION LsaRemoveAccountRights LIB "ADVAPI32.DLL" _
   ALIAS "LsaRemoveAccountRights" ( _
    BYVAL PolicyHandle  AS DWORD, _
    AccountSid          AS SID, _
    BYVAL AllRights     AS BYTE, _
    UserRights          AS LSA_UNICODE_STRING, _
    BYVAL CountOfRights AS DWORD _
    ) AS LONG
#ELSE
DECLARE FUNCTION LsaRemoveAccountRights IMPORT "ADVAPI32.DLL" ALIAS "LsaRemoveAccountRights" ( _
   BYVAL PolicyHandle AS DWORD _                        ' __in LSA_HANDLE PolicyHandle
 , BYVAL AccountSid AS SID PTR _                        ' __in PSID AccountSid
 , BYVAL AllRights AS BYTE _                            ' __in BOOLEAN AllRights
 , BYREF UserRights AS LSA_UNICODE_STRING _             ' __in_ecount_opt(CountOfRights) PLSA_UNICODE_STRING UserRights
 , BYVAL CountOfRights AS DWORD _                       ' __in ULONG CountOfRights
 ) AS LONG                                              ' NTSTATUS
#ENDIF

'///////////////////////////////////////////////////////////////////////////////
'//                                                                           //
'// Local Security Policy - Trusted Domain Object API function prototypes     //
'//                                                                           //
'///////////////////////////////////////////////////////////////////////////////

DECLARE FUNCTION LsaOpenTrustedDomainByName IMPORT "ADVAPI32.DLL" ALIAS "LsaOpenTrustedDomainByName" ( _
   BYVAL PolicyHandle AS DWORD _                        ' __in LSA_HANDLE PolicyHandle
 , BYREF TrustedDomainName AS LSA_UNICODE_STRING _      ' __in PLSA_UNICODE_STRING TrustedDomainName
 , BYVAL DesiredAccess AS ACCESS_MASK _                 ' __in ACCESS_MASK DesiredAccess
 , BYREF TrustedDomainHandle AS DWORD _                 ' __out PLSA_HANDLE TrustedDomainHandle
 ) AS LONG                                              ' NTSTATUS

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION LsaQueryTrustedDomainInfo LIB "ADVAPI32.DLL" _
   ALIAS "LsaQueryTrustedDomainInfo" ( _
    BYVAL PolicyHandle     AS DWORD, _
    TrustedDomainSid       AS SID, _
    BYVAL InformationClass AS LONG, _
    Buffer AS DWORD _
    ) AS LONG
#ELSE
DECLARE FUNCTION LsaQueryTrustedDomainInfo IMPORT "ADVAPI32.DLL" ALIAS "LsaQueryTrustedDomainInfo" ( _
   BYVAL PolicyHandle AS DWORD _                        ' __in LSA_HANDLE PolicyHandle
 , BYVAL TrustedDomainSid AS SID PTR _                  ' __in PSID TrustedDomainSid
 , BYVAL InformationClass AS LONG _                     ' __in TRUSTED_INFORMATION_CLASS InformationClass
 , BYREF Buffer AS ANY _                                ' __out PVOID *Buffer
 ) AS LONG                                              ' NTSTATUS
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION LsaSetTrustedDomainInformation LIB "ADVAPI32.DLL" _
   ALIAS "LsaSetTrustedDomainInformation" ( _
    BYVAL PolicyHandle     AS DWORD, _
    TrustedDomainSid       AS SID, _
    BYVAL InformationClass AS LONG, _
    BYVAL Buffer           AS DWORD _
    ) AS LONG
#ELSE
DECLARE FUNCTION LsaSetTrustedDomainInformation IMPORT "ADVAPI32.DLL" ALIAS "LsaSetTrustedDomainInformation" ( _
   BYVAL PolicyHandle AS DWORD _                        ' __in LSA_HANDLE PolicyHandle
 , BYVAL TrustedDomainSid AS SID PTR _                  ' __in PSID TrustedDomainSid
 , BYVAL InformationClass AS LONG _                     ' __in TRUSTED_INFORMATION_CLASS InformationClass
 , BYVAL Buffer AS DWORD _                              ' __in PVOID Buffer
 ) AS LONG                                              ' NTSTATUS
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION LsaDeleteTrustedDomain LIB "ADVAPI32.DLL" _
   ALIAS "LsaDeleteTrustedDomain" ( _
    BYVAL PolicyHandle AS DWORD, _
    TrustedDomainSid   AS SID _
    ) AS LONG
#ELSE
DECLARE FUNCTION LsaDeleteTrustedDomain IMPORT "ADVAPI32.DLL" ALIAS "LsaDeleteTrustedDomain" ( _
   BYVAL PolicyHandle AS DWORD _                        ' __in LSA_HANDLE PolicyHandle
 , BYVAL TrustedDomainSid AS SID PTR _                  ' __in PSID TrustedDomainSid
 ) AS LONG                                              ' NTSTATUS
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION LsaQueryTrustedDomainInfoByName LIB "ADVAPI32.DLL" _
   ALIAS "LsaQueryTrustedDomainInfoByName" ( _
    BYVAL PolicyHandle     AS DWORD, _
    TrustedDomainName      AS LSA_UNICODE_STRING, _
    BYVAL InformationClass AS LONG, _
    Buffer                 AS DWORD _
    ) AS LONG
#ELSE
DECLARE FUNCTION LsaQueryTrustedDomainInfoByName IMPORT "ADVAPI32.DLL" ALIAS "LsaQueryTrustedDomainInfoByName" ( _
   BYVAL PolicyHandle AS DWORD _                        ' __in LSA_HANDLE PolicyHandle
 , BYREF TrustedDomainName AS LSA_UNICODE_STRING _      ' __in PLSA_UNICODE_STRING TrustedDomainName
 , BYVAL InformationClass AS LONG _                     ' __in TRUSTED_INFORMATION_CLASS InformationClass
 , BYREF Buffer AS ANY _                                ' __out PVOID *Buffer
 ) AS LONG                                              ' NTSTATUS
#ENDIF

DECLARE FUNCTION LsaSetTrustedDomainInfoByName IMPORT "ADVAPI32.DLL" ALIAS "LsaSetTrustedDomainInfoByName" ( _
   BYVAL PolicyHandle AS DWORD _                        ' __in LSA_HANDLE PolicyHandle
 , BYREF TrustedDomainName AS LSA_UNICODE_STRING _      ' __in PLSA_UNICODE_STRING TrustedDomainName
 , BYVAL InformationClass AS LONG _                     ' __in TRUSTED_INFORMATION_CLASS InformationClass
 , BYVAL Buffer AS DWORD _                              ' __in PVOID Buffer
 ) AS LONG                                              ' NTSTATUS

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION LsaEnumerateTrustedDomainsEx LIB "ADVAPI32.DLL" _
   ALIAS "LsaEnumerateTrustedDomainsEx" ( _
    BYVAL PolicyHandle          AS DWORD, _
    EnumerationContext          AS DWORD, _
    Buffer                      AS DWORD, _
    BYVAL PreferedMaximumLength AS DWORD, _
    CountReturned               AS DWORD _
    ) AS LONG
#ELSE
DECLARE FUNCTION LsaEnumerateTrustedDomainsEx IMPORT "ADVAPI32.DLL" ALIAS "LsaEnumerateTrustedDomainsEx" ( _
   BYVAL PolicyHandle AS DWORD _                        ' __in LSA_HANDLE PolicyHandle
 , BYREF EnumerationContext AS DWORD _                  ' __inout PLSA_ENUMERATION_HANDLE EnumerationContext
 , BYREF Buffer AS ANY _                                ' __out PVOID *Buffer
 , BYVAL PreferedMaximumLength AS DWORD _               ' __in ULONG PreferedMaximumLength
 , BYREF CountReturned AS DWORD _                       ' __out PULONG CountReturned
 ) AS LONG                                              ' NTSTATUS
#ENDIF

DECLARE FUNCTION LsaCreateTrustedDomainEx IMPORT "ADVAPI32.DLL" ALIAS "LsaCreateTrustedDomainEx" ( _
   BYVAL PolicyHandle AS DWORD _                        ' __in LSA_HANDLE PolicyHandle
 , BYREF TrustedDomainInformation AS TRUSTED_DOMAIN_INFORMATION_EX _    ' __in PTRUSTED_DOMAIN_INFORMATION_EX TrustedDomainInformation
 , BYREF AuthenticationInformation AS TRUSTED_DOMAIN_AUTH_INFORMATION _ ' __in PTRUSTED_DOMAIN_AUTH_INFORMATION AuthenticationInformation
 , BYVAL DesiredAccess AS ACCESS_MASK _                 ' __in ACCESS_MASK DesiredAccess
 , BYREF TrustedDomainHandle AS DWORD _                 ' __out PLSA_HANDLE TrustedDomainHandle
 ) AS LONG                                              ' NTSTATUS

'#if (_WIN32_WINNT >= 0x0501)
DECLARE FUNCTION LsaQueryForestTrustInformation IMPORT "ADVAPI32.DLL" ALIAS "LsaQueryForestTrustInformation" ( _
   BYVAL PolicyHandle AS DWORD _                        ' __in LSA_HANDLE PolicyHandle
 , BYREF TrustedDomainName AS LSA_UNICODE_STRING _      ' __in PLSA_UNICODE_STRING TrustedDomainName
 , BYREF ForestTrustInfo AS DWORD _                     ' __out PLSA_FOREST_TRUST_INFORMATION * ForestTrustInfo
 ) AS LONG                                              ' NTSTATUS

DECLARE FUNCTION LsaSetForestTrustInformation IMPORT "ADVAPI32.DLL" ALIAS "LsaSetForestTrustInformation" ( _
   BYVAL PolicyHandle AS DWORD _                        ' __in LSA_HANDLE PolicyHandle
 , BYREF TrustedDomainName AS LSA_UNICODE_STRING _      ' __in PLSA_UNICODE_STRING TrustedDomainName
 , BYREF ForestTrustInfo AS LSA_FOREST_TRUST_INFORMATION _ ' __in PLSA_FOREST_TRUST_INFORMATION ForestTrustInfo
 , BYVAL CheckOnly AS BYTE _                            ' __in BOOLEAN CheckOnly
 , BYREF CollisionInfo AS DWORD _                       ' __out PLSA_FOREST_TRUST_COLLISION_INFORMATION * CollisionInfo
 ) AS LONG                                              ' NTSTATUS

'// #define TESTING_MATCHING_ROUTINE

#IF %DEF(%TESTING_MATCHING_ROUTINE)
DECLARE FUNCTION LsaForestTrustFindMatch IMPORT "ADVAPI32.DLL" ALIAS "LsaForestTrustFindMatch" ( _
   BYVAL PolicyHandle AS DWORD _                        ' __in LSA_HANDLE PolicyHandle
 , BYVAL Type AS DWORD _                                ' __in ULONG Type
 , BYREF Name AS LSA_UNICODE_STRING _                   ' __in PLSA_UNICODE_STRING Name
 , BYREF Match AS LSA_UNICODE_STRING _                  ' __out PLSA_UNICODE_STRING * Match
 ) AS LONG                                              ' NTSTATUS
#ENDIF

'#endif

'//
'// This API sets the workstation password (equivalent of setting/getting
'// the SSI_SECRET_NAME secret)
'//

DECLARE FUNCTION LsaStorePrivateData IMPORT "ADVAPI32.DLL" ALIAS "LsaStorePrivateData" ( _
   BYVAL PolicyHandle AS DWORD _                        ' __in LSA_HANDLE PolicyHandle
 , BYREF KeyName AS LSA_UNICODE_STRING _                ' __in PLSA_UNICODE_STRING KeyName
 , BYREF PrivateData AS LSA_UNICODE_STRING _            ' __in_opt PLSA_UNICODE_STRING PrivateData
 ) AS LONG                                              ' NTSTATUS

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION LsaRetrievePrivateData LIB "ADVAPI32.DLL" _
   ALIAS "LsaRetrievePrivateData" ( _
    BYVAL PolicyHandle AS DWORD, _
    KeyName AS LSA_UNICODE_STRING, _
    PrivateData AS DWORD _
    ) AS LONG
#ELSE
DECLARE FUNCTION LsaRetrievePrivateData IMPORT "ADVAPI32.DLL" ALIAS "LsaRetrievePrivateData" ( _
   BYVAL PolicyHandle AS DWORD _                        ' __in LSA_HANDLE PolicyHandle
 , BYREF KeyName AS LSA_UNICODE_STRING _                ' __in PLSA_UNICODE_STRING KeyName
 , BYREF PrivateData AS LSA_UNICODE_STRING _            ' __out PLSA_UNICODE_STRING * PrivateData
 ) AS LONG                                              ' NTSTATUS
#ENDIF

DECLARE FUNCTION LsaNtStatusToWinError IMPORT "ADVAPI32.DLL" ALIAS "LsaNtStatusToWinError" ( _
   BYVAL Status AS LONG _                               ' __in NTSTATUS Status
 ) AS DWORD                                             ' ULONG

'//
'// Define a symbol so we can tell if ntifs.h has been included.
'//

'// begin_ntifs
'#ifndef _NTLSA_IFS_
'#define _NTLSA_IFS_
'#endif
'// end_ntifs


'//
'// SPNEGO package stuff
'//

' NEGOTIATE_MESSAGES enum
%NegEnumPackagePrefixes = 0
%NegGetCallerName       = 1
%NegCallPackageMax      = 2

%NEGOTIATE_MAX_PREFIX   = 32

' // Size = 48 bytes
TYPE NEGOTIATE_PACKAGE_PREFIX DWORD
   PackageId    AS DWORD   ' ULONG_PTR
   PackageDataA AS DWORD   ' PVOID
   PackageDataW AS DWORD   ' PVOID
   PrefixLen    AS DWORD   ' ULONG_PTR
   Prefix       AS STRING * %NEGOTIATE_MAX_PREFIX   ' UCHAR Prefix[ NEGOTIATE_MAX_PREFIX ]
END TYPE

' // Size = 16 bytes
TYPE NEGOTIATE_PACKAGE_PREFIXES DWORD
   MessageType AS DWORD   ' ULONG
   PrefixCount AS DWORD   ' ULONG
   Offset      AS DWORD   ' ULONG
'#if(_WIN32_WINNT >= 0x0502)
#IF %WINVER >= &H0502
   Pad         AS DWORD   ' ULONG   // Align structure for 64-bit
#endif
END TYPE

' // Size = 12 bytes
TYPE NEGOTIATE_CALLER_NAME_REQUEST DWORD
   MessageType AS DWORD   ' ULONG
   LogonId     AS QUAD    ' LUID
END TYPE

' // Size = 8 bytes
TYPE NEGOTIATE_CALLER_NAME_RESPONSE DWORD
   MessageType AS DWORD          ' ULONG
   CallerName  AS WSTRINGZ PTR   ' PWSTR
END TYPE

'#ifndef _NTDEF_
'typedef LSA_UNICODE_STRING UNICODE_STRING, *PUNICODE_STRING;
'typedef LSA_STRING STRING, *PSTRING ;
'#endif

#IF NOT %DEF(%DOMAIN_PASSWORD_INFORMATION_DEFINED)
%DOMAIN_PASSWORD_INFORMATION_DEFINED = 1
' // Size = 24 bytes
TYPE DOMAIN_PASSWORD_INFORMATION   ' Must be 8 byte aligned
   MinPasswordLength     AS WORD    ' USHORT
   PasswordHistoryLength AS WORD    ' USHORT
   PasswordProperties    AS DWORD   ' ULONG
   MaxPasswordAge        AS QUAD    ' LARGE_INTEGER
   MinPasswordAge        AS QUAD    ' LARGE_INTEGER
END TYPE
#ENDIF  ' #IF NOT %DEF(%DOMAIN_PASSWORD_INFORMATION_DEFINED)

'#if (_WIN32_WINNT >= 0x0501)
'//
'// PasswordProperties flags
'//

%DOMAIN_PASSWORD_COMPLEX         = &H00000001???
%DOMAIN_PASSWORD_NO_ANON_CHANGE  = &H00000002???
%DOMAIN_PASSWORD_NO_CLEAR_CHANGE = &H00000004???
%DOMAIN_LOCKOUT_ADMINS           = &H00000008???
%DOMAIN_PASSWORD_STORE_CLEARTEXT = &H00000010???
%DOMAIN_REFUSE_PASSWORD_CHANGE   = &H00000020???
'#if(_WIN32_WINNT >= 0x0502)
%DOMAIN_NO_LM_OWF_CHANGE         = &H00000040???
'#endif
'#endif

#IF NOT %DEF(%PASSWORD_NOTIFICATION_DEFINED)
    %PASSWORD_NOTIFICATION_DEFINED = 1

'typedef NTSTATUS (*PSAM_PASSWORD_NOTIFICATION_ROUTINE) (
'    PUNICODE_STRING UserName,
'    ULONG RelativeId,
'    PUNICODE_STRING NewPassword
');

'FUNCTION SAM_PASSWORD_NOTIFICATION_ROUTINE ( _
'   BYREF UserName AS UNICODE STRING, _                  ' PUNICODE_STRING UserName
'   BYVAL DWORD, _                                       ' ULONG RelativeId
'   BYREF NewPassword AS UNICODE_STRING _                ' PUNICODE_STRING NewPassword
'   ) AS LONG                                            ' NTSTATUS

$$SAM_PASSWORD_CHANGE_NOTIFY_ROUTINE = "PasswordChangeNotify"$$

'typedef BOOLEAN (*PSAM_INIT_NOTIFICATION_ROUTINE) (
');

$$SAM_INIT_NOTIFICATION_ROUTINE = "InitializeChangeNotify"$$

$$SAM_PASSWORD_FILTER_ROUTINE = "PasswordFilter"$$

'typedef BOOLEAN (*PSAM_PASSWORD_FILTER_ROUTINE) (
'    __in PUNICODE_STRING  AccountName,
'    __in PUNICODE_STRING  FullName,
'    __in PUNICODE_STRING Password,
'    __in BOOLEAN SetOperation
'    );

'FUNCTION SAM_PASSWORD_FILTER_ROUTINE ( _
'   BYREF AccountName AS UNICODE_STRING, _               ' __in PUNICODE_STRING AccountName
'   BYREF FullName AS v, _                               ' __in PUNICODE_STRING FullName
'   BYREF Password AS UNICODE_STRING, _                  ' __in PUNICODE_STRING Password
'   BYVAL SetOperation AS BYTE _                         ' __in BOOLEAN SetOperation
'   ) AS BYTE                                            ' BOOLEAN

#ENDIF   ' // _PASSWORD_NOTIFICATION_DEFINED


'/////////////////////////////////////////////////////////////////////////
'//                                                                     //
'// Name of the MSV1_0 authentication package                           //
'//                                                                     //
'/////////////////////////////////////////////////////////////////////////

'#define MSV1_0_PACKAGE_NAME     "MICROSOFT_AUTHENTICATION_PACKAGE_V1_0"
'#define MSV1_0_PACKAGE_NAMEW    L"MICROSOFT_AUTHENTICATION_PACKAGE_V1_0"
'#define MSV1_0_PACKAGE_NAMEW_LENGTH sizeof(MSV1_0_PACKAGE_NAMEW) - sizeof(WCHAR)
$$MSV1_0_PACKAGE_NAME   = "MICROSOFT_AUTHENTICATION_PACKAGE_V1_0"$$

'//
'// Location of MSV authentication package data
'//
'#define MSV1_0_SUBAUTHENTICATION_KEY "SYSTEM\\CurrentControlSet\\Control\\Lsa\\MSV1_0"
'#define MSV1_0_SUBAUTHENTICATION_VALUE "Auth"
$$MSV1_0_SUBAUTHENTICATION_KEY = "SYSTEM\CurrentControlSet\Control\Lsa\MSV1_0"$$
$$MSV1_0_SUBAUTHENTICATION_VALUE = "Auth"$$


'/////////////////////////////////////////////////////////////////////////
'//                                                                     //
'// Widely used MSV1_0 data types                                       //
'//                                                                     //
'/////////////////////////////////////////////////////////////////////////


'///////////////////////////////////////////////////////////////////////////////
'//                                                                           //
'//       LOGON      Related Data Structures
'//
'//                                                                           //
'///////////////////////////////////////////////////////////////////////////////

'//
'// When a LsaLogonUser() call is dispatched to the MsV1_0 authentication
'// package, the beginning of the AuthenticationInformation buffer is
'// cast to a MSV1_0_LOGON_SUBMIT_TYPE to determine the type of logon
'// being requested.  Similarly, upon return, the type of profile buffer
'// can be determined by typecasting it to a MSV_1_0_PROFILE_BUFFER_TYPE.
'//

'//
'//  MSV1.0 LsaLogonUser() submission message types.
'//

' MSV1_0_LOGON_SUBMIT_TYPE enum
%MsV1_0InteractiveLogon       = 2
%MsV1_0Lm20Logon              = 3
%MsV1_0NetworkLogon           = 4
%MsV1_0SubAuthLogon           = 5
%MsV1_0WorkstationUnlockLogon = 7
'// defined in Windows Server 2008 and up
%MsV1_0S4ULogon               = 12
%MsV1_0VirtualLogon           = 82

'//
'//  MSV1.0 LsaLogonUser() profile buffer types.
'//

' MSV1_0_PROFILE_BUFFER_TYPE enum
%MsV1_0InteractiveProfile = 2
%MsV1_0Lm20LogonProfile   = 3
%MsV1_0SmartCardProfile   = 4

'//
'// MsV1_0InteractiveLogon
'//
'// The AuthenticationInformation buffer of an LsaLogonUser() call to
'// perform an interactive logon contains the following data structure:
'//

' // Size = 28 bytes
TYPE MSV1_0_INTERACTIVE_LOGON DWORD
   MessageType     AS LONG
   LogonDomainName AS UNICODE_STRING
   UserName        AS UNICODE_STRING
   Password        AS UNICODE_STRING
END TYPE

'//
'// Where:
'//
'//     MessageType - Contains the type of logon being requested.  This
'//         field must be set to MsV1_0InteractiveLogon.
'//
'//     UserName - Is a string representing the user's account name.  The
'//         name may be up to 255 characters long.  The name is treated case
'//         insensitive.
'//
'//     Password - Is a string containing the user's cleartext password.
'//         The password may be up to 255 characters long and contain any
'//         UNICODE value.
'//
'//


'//
'// The ProfileBuffer returned upon a successful logon of this type
'// contains the following data structure:
'//

' // Size = 112 bytes
TYPE MSV1_0_INTERACTIVE_PROFILE   ' Must be 8 byte aligned
   MessageType        AS LONG             ' MSV1_0_PROFILE_BUFFER_TYPE
   LogonCount         AS WORD             ' USHORT
   BadPasswordCount   AS WORD             ' USHORT
   LogonTime          AS QUAD             ' LARGE_INTEGER
   LogoffTime         AS QUAD             ' LARGE_INTEGER
   KickOffTime        AS QUAD             ' LARGE_INTEGER
   PasswordLastSet    AS QUAD             ' LARGE_INTEGER
   PasswordCanChange  AS QUAD             ' LARGE_INTEGER
   PasswordMustChange AS QUAD             ' LARGE_INTEGER
   LogonScript        AS UNICODE_STRING   ' UNICODE_STRING
   HomeDirectory      AS UNICODE_STRING   ' UNICODE_STRING
   FullName           AS UNICODE_STRING   ' UNICODE_STRING
   ProfilePath        AS UNICODE_STRING   ' UNICODE_STRING
   HomeDirectoryDrive AS UNICODE_STRING   ' UNICODE_STRING
   LogonServer        AS UNICODE_STRING   ' UNICODE_STRING
   UserFlags          AS DWORD            ' ULONG
   filler             AS DWORD            ' // To keep QWORD alignment
END TYPE

'//
'// where:
'//
'//     MessageType - Identifies the type of profile data being returned.
'//         Contains the type of logon being requested.  This field must
'//         be set to MsV1_0InteractiveProfile.
'//
'//     LogonCount - Number of times the user is currently logged on.
'//
'//     BadPasswordCount - Number of times a bad password was applied to
'//         the account since last successful logon.
'//
'//     LogonTime - Time when user last logged on.  This is an absolute
'//         format NT standard time value.
'//
'//     LogoffTime - Time when user should log off.  This is an absolute
'//         format NT standard time value.
'//
'//     KickOffTime - Time when system should force user logoff.  This is
'//         an absolute format NT standard time value.
'//
'//     PasswordLastChanged - Time and date the password was last
'//         changed.  This is an absolute format NT standard time
'//         value.
'//
'//     PasswordCanChange - Time and date when the user can change the
'//         password.  This is an absolute format NT time value.  To
'//         prevent a password from ever changing, set this field to a
'//         date very far into the future.
'//
'//     PasswordMustChange - Time and date when the user must change the
'//         password.  If the user can never change the password, this
'//         field is undefined.  This is an absolute format NT time
'//         value.
'//
'//     LogonScript - The (relative) path to the account's logon
'//         script.
'//
'//     HomeDirectory - The home directory for the user.
'//


'//
'// MsV1_0Lm20Logon and MsV1_0NetworkLogon
'//
'// The AuthenticationInformation buffer of an LsaLogonUser() call to
'// perform an network logon contains the following data structure:
'//
'// MsV1_0NetworkLogon logon differs from MsV1_0Lm20Logon in that the
'// ParameterControl field exists.
'//

%MSV1_0_CHALLENGE_LENGTH          = 8
%MSV1_0_USER_SESSION_KEY_LENGTH   = 16
%MSV1_0_LANMAN_SESSION_KEY_LENGTH = 8

'//
'// Values for ParameterControl.
'//

%MSV1_0_CLEARTEXT_PASSWORD_ALLOWED      = &H02???
%MSV1_0_UPDATE_LOGON_STATISTICS         = &H04???
%MSV1_0_RETURN_USER_PARAMETERS          = &H08???
%MSV1_0_DONT_TRY_GUEST_ACCOUNT          = &H10???
%MSV1_0_ALLOW_SERVER_TRUST_ACCOUNT      = &H20???
%MSV1_0_RETURN_PASSWORD_EXPIRY          = &H40???
'// this next flag says that CaseInsensitiveChallengeResponse
'//  (aka LmResponse) contains a client challenge in the first 8 bytes
'#define MSV1_0_USE_CLIENT_CHALLENGE          0x80
'#define MSV1_0_TRY_GUEST_ACCOUNT_ONLY        0x100
'#define MSV1_0_RETURN_PROFILE_PATH           0x200
'#define MSV1_0_TRY_SPECIFIED_DOMAIN_ONLY     0x400
'#define MSV1_0_ALLOW_WORKSTATION_TRUST_ACCOUNT 0x800
%MSV1_0_USE_CLIENT_CHALLENGE            = &H80???
%MSV1_0_TRY_GUEST_ACCOUNT_ONLY          = &H100???
%MSV1_0_RETURN_PROFILE_PATH             = &H200???
%MSV1_0_TRY_SPECIFIED_DOMAIN_ONLY       = &H400???
%MSV1_0_ALLOW_WORKSTATION_TRUST_ACCOUNT = &H800???
'//#if (_WIN32_WINNT >= 0x0501) -- Disabled until IIS fixes their target version.
%MSV1_0_DISABLE_PERSONAL_FALLBACK       = &H00001000???
%MSV1_0_ALLOW_FORCE_GUEST               = &H00002000???
'//#endif
'#if (_WIN32_WINNT >= 0x0502)
%MSV1_0_CLEARTEXT_PASSWORD_SUPPLIED     = &H00004000???
'// Start
'// Doesnt exist in Windows XP but does exist in Windows 2000 Security Rollup and up
%MSV1_0_USE_DOMAIN_FOR_ROUTING_ONLY     = &H00008000???
'#endif
%MSV1_0_SUBAUTHENTICATION_DLL_EX        = &H00100000???
'// Defined in Windows Server 2003 SP1 and above
%MSV1_0_ALLOW_MSVCHAPV2                 = &H00010000???

'#if (_WIN32_WINNT >= 0x0600)

'//Defined in Windows Server 2008 and up
%MSV1_0_S4U2SELF                        = &H00020000???  ' // no password is needed
%MSV1_0_CHECK_LOGONHOURS_FOR_S4U        = &H00040000???  ' // check logon hours for S4U logon

'#endif

'//
'// The high order byte is a value indicating the SubAuthentication DLL.
'//  Zero indicates no SubAuthentication DLL.
'//
%MSV1_0_SUBAUTHENTICATION_DLL         = &HFF000000???
%MSV1_0_SUBAUTHENTICATION_DLL_SHIFT   = 24
%MSV1_0_MNS_LOGON                     = &H01000000???

'//
'// This is the list of subauthentication dlls used in MS
'//

%MSV1_0_SUBAUTHENTICATION_DLL_RAS     = 2
%MSV1_0_SUBAUTHENTICATION_DLL_IIS     = 132

' // Size = 56 bytes
TYPE MSV1_0_LM20_LOGON DWORD
   MessageType                      AS LONG             ' MSV1_0_LOGON_SUBMIT_TYPE
   LogonDomainName                  AS UNICODE_STRING   ' UNICODE_STRING
   UserName                         AS UNICODE_STRING   ' UNICODE_STRING
   Workstation                      AS UNICODE_STRING   ' UNICODE_STRING
   ChallengeToClient                AS STRING * %MSV1_0_CHALLENGE_LENGTH   ' UCHAR ChallengeToClient[MSV1_0_CHALLENGE_LENGTH]
   CaseSensitiveChallengeResponse   AS LSA_STRING       ' LSA_STRING
   CaseInsensitiveChallengeResponse AS LSA_STRING       ' LSA_STRING
   ParameterControl                 AS DWORD            ' ULONG
END TYPE

'//
'// NT 5.0 SubAuth dlls can use this struct
'//

' // Size = 60 bytes
TYPE MSV1_0_SUBAUTH_LOGON DWORD
   MessageType         AS LONG             ' MSV1_0_LOGON_SUBMIT_TYPE
   LogonDomainName     AS UNICODE_STRING   ' UNICODE_STRING
   UserName            AS UNICODE_STRING   ' UNICODE_STRING
   Workstation         AS UNICODE_STRING   ' UNICODE_STRING
   ChallengeToClient   AS STRING * %MSV1_0_CHALLENGE_LENGTH   ' UCHAR ChallengeToClient[MSV1_0_CHALLENGE_LENGTH]
   AuthenticationInfo1 AS LSA_STRING       ' LSA_STRING
   AuthenticationInfo2 AS LSA_STRING       ' LSA_STRING
   ParameterControl    AS DWORD            ' ULONG
   SubAuthPackageId    AS DWORD            ' ULONG
END TYPE

'#if (_WIN32_WINNT >= 0x0600)

'//
'// s4u2self logon
'//
'// Defined in Windows Server 2008 and above

'//
'// request to enforce logon hours policy
'//

%MSV1_0_S4U_LOGON_FLAG_CHECK_LOGONHOURS = &H2

' // Size = 24 bytes
TYPE MSV1_0_S4U_LOGON DWORD
   MessageType       AS LONG             ' MSV1_0_LOGON_SUBMIT_TYPE
   Flags             AS DWORD            ' ULONG
   UserPrincipalName AS UNICODE_STRING   ' // username or username@domain
   DomainName        AS UNICODE_STRING   ' // Optional: if missing, using the local machine
END TYPE

'#endif

'//
'// Values for UserFlags.
'//

%LOGON_GUEST                 = &H0001???
%LOGON_NOENCRYPTION          = &H0002???
%LOGON_CACHED_ACCOUNT        = &H0004???
%LOGON_USED_LM_PASSWORD      = &H0008???
%LOGON_EXTRA_SIDS            = &H0020???
%LOGON_SUBAUTH_SESSION_KEY   = &H0040???
%LOGON_SERVER_TRUST_ACCOUNT  = &H0080???
%LOGON_NTLMV2_ENABLED        = &H0100???   ' says DC understands NTLMv2
%LOGON_RESOURCE_GROUPS       = &H0200???
%LOGON_PROFILE_PATH_RETURNED = &H0400???
'// Defined in Windows Server 2008 and above
%LOGON_NT_V2                 = &H800???    ' // NT response was used for validation
%LOGON_LM_V2                 = &H1000???   ' // LM response was used for validation
%LOGON_NTLM_V2               = &H2000???   ' // LM response was used to authenticate but NT response was used to derive the session key

'//
'// The high order byte is reserved for return by SubAuthentication DLLs.
'//

'#define MSV1_0_SUBAUTHENTICATION_FLAGS 0xFF000000
%MSV1_0_SUBAUTHENTICATION_FLAGS = &HFF000000???

'// Values returned by the MSV1_0_MNS_LOGON SubAuthentication DLL
%LOGON_GRACE_LOGON              = &H01000000???

' // Size = 80 bytes
TYPE MSV1_0_LM20_LOGON_PROFILE QWORD FILL
   MessageType      AS LONG             ' MSV1_0_PROFILE_BUFFER_TYPE
   KickOffTime      AS QUAD             ' LARGE_INTEGER
   LogoffTime       AS QUAD             ' LARGE_INTEGER
   UserFlags        AS DWORD            ' ULONG
   UserSessionKey   AS STRING * %MSV1_0_USER_SESSION_KEY_LENGTH     ' UCHAR UserSessionKey[MSV1_0_USER_SESSION_KEY_LENGTH]
   LogonDomainName  AS UNICODE_STRING   ' UNICODE_STRING
   LanmanSessionKey AS STRING * %MSV1_0_LANMAN_SESSION_KEY_LENGTH   ' UCHAR LanmanSessionKey[MSV1_0_LANMAN_SESSION_KEY_LENGTH]
   LogonServer      AS UNICODE_STRING   ' UNICODE_STRING
   UserParameters   AS UNICODE_STRING   ' UNICODE_STRING
END TYPE

'//
'// Supplemental credentials structure used for passing credentials into
'// MSV1_0 from other packages
'//

%MSV1_0_OWF_PASSWORD_LENGTH = 16
%MSV1_0_CRED_LM_PRESENT     = &H1
%MSV1_0_CRED_NT_PRESENT     = &H2
%MSV1_0_CRED_VERSION        = 0

' // Size = 40 bytes
TYPE MSV1_0_SUPPLEMENTAL_CREDENTIAL DWORD
   Version    AS DWORD   ' ULONG
   Flags      AS DWORD   ' ULONG
   LmPassword AS STRING * %MSV1_0_OWF_PASSWORD_LENGTH   ' UCHAR LmPassword[MSV1_0_OWF_PASSWORD_LENGTH]
   NtPassword AS STRING * %MSV1_0_OWF_PASSWORD_LENGTH   ' UCHAR NtPassword[MSV1_0_OWF_PASSWORD_LENGTH]
END TYPE

'//
'// NTLM3 definitions.
'//

%MSV1_0_NTLM3_RESPONSE_LENGTH = 16
%MSV1_0_NTLM3_OWF_LENGTH      = 16

'//
'// this is the longest amount of time we'll allow challenge response
'// pairs to be used. Note that this also has to allow for worst case clock skew
'//
'#if (_WIN32_WINNT == 0x0500)
'#IF %WINVER = &H0500
'#define MSV1_0_MAX_NTLM3_LIFE 1800     // 30 minutes (in seconds)
'#else
%MSV1_0_MAX_NTLM3_LIFE = 129600     ' 36 hours (in seconds)
'#endif
%MSV1_0_MAX_AVL_SIZE   = 64000

'#if (_WIN32_WINNT >= 0x0501)
'//
'// MsvAvFlags bit values
'//

%MSV1_0_AV_FLAG_FORCE_GUEST            = &H00000001???
'#if (_WIN32_WINNT >= 0x0600)
%MSV1_0_AV_FLAG_MIC_HANDSHAKE_MESSAGES = &H00000002???   ' // the client supports
                                                         ' // hand-shake messages integrity
'#endif
'#endif

'// this is an MSV1_0 private data structure, defining the layout of an NTLM3 response, as sent by a
'//  client in the NtChallengeResponse field of the NETLOGON_NETWORK_INFO structure. If can be differentiated
'//  from an old style NT response by its length. This is crude, but it needs to pass through servers and
'//  the servers' DCs that do not understand NTLM3 but that are willing to pass longer responses.

' // Size = 48 bytes
TYPE MSV1_0_NTLM3_RESPONSE QWORD FILL
   Response   AS ASCIIZ * %MSV1_0_NTLM3_RESPONSE_LENGTH ' UCHAR Response[MSV1_0_NTLM3_RESPONSE_LENGTH]
   RespType   AS BYTE        ' UCHAR
   HiRespType AS BYTE        ' UCHAR
   Flags      AS WORD        ' USHORT
   MsgWord    AS DWORD       ' ULONG
   TimeStamp  AS QUAD        ' ULONGULONG
   ChallengeFromClient AS STRING * %MSV1_0_CHALLENGE_LENGTH   ' UCHAR ChallengeFromClient[MSV1_0_CHALLENGE_LENGTH]
   AvPairsOff AS DWORD       ' ULONG
   filler     AS DWORD       ' // To keep QWORD alignment
'   Buffer(0)  AS BYTE        ' UCHAR Buffer[1];    // start of buffer with AV pairs (or future stuff -- so use the offset)
END TYPE

'#define MSV1_0_NTLM3_INPUT_LENGTH (sizeof(MSV1_0_NTLM3_RESPONSE) - MSV1_0_NTLM3_RESPONSE_LENGTH)
'#if(_WIN32_WINNT >= 0x0502)
'#define MSV1_0_NTLM3_MIN_NT_RESPONSE_LENGTH RTL_SIZEOF_THROUGH_FIELD(MSV1_0_NTLM3_RESPONSE, AvPairsOff)
'#endif

' MSV1_0_AVID enum
%MsvAvEOL              = 0  ' // end of list
%MsvAvNbComputerName   = 1  ' // server's computer name -- NetBIOS
%MsvAvNbDomainName     = 2  ' // server's domain name -- NetBIOS
%MsvAvDnsComputerName  = 3  ' // server's computer name -- DNS
%MsvAvDnsDomainName    = 4  ' // server's domain name -- DNS
'#if (_WIN32_WINNT >= 0x0501)
%MsvAvDnsTreeName      = 5  ' // server's tree name -- DNS
%MsvAvFlags            = 6  ' // server's extended flags -- DWORD mask
'#if (_WIN32_WINNT >= 0x0600)
%MsvAvTimestamp        = 7  ' // contains the server's local time in FILETIME,
                            ' // (64 bit 100 ns ticks since 1602
                            ' // (UTC)) in little endian byte order
%MsvAvRestrictions     = 8  ' // token restrictions
%MsvAvTargetName       = 9
%MsvAvChannelBindings  = 10
'#endif
'#endif

' // Size = 4 bytes
TYPE MSV1_0_AV_PAIR WORD
   AvId  AS WORD   ' USHORT
   AvLen AS WORD   ' USHORT
   ' // Data is treated as byte array following structure
END TYPE


'///////////////////////////////////////////////////////////////////////////////
'//                                                                           //
'//       CALL PACKAGE Related Data Structures                                //
'//                                                                           //
'///////////////////////////////////////////////////////////////////////////////


'//
'//  MSV1.0 LsaCallAuthenticationPackage() submission and response
'//  message types.
'//

' MSV1_0_PROTOCOL_MESSAGE_TYPE enum
%MsV1_0Lm20ChallengeRequest     = 0       ' Both submission and response
%MsV1_0Lm20GetChallengeResponse = 1       ' Both submission and response
%MsV1_0EnumerateUsers           = 2       ' Both submission and response
%MsV1_0GetUserInfo              = 3       ' Both submission and response
%MsV1_0ReLogonUsers             = 4       ' Submission only
%MsV1_0ChangePassword           = 5       ' Both submission and response
%MsV1_0ChangeCachedPassword     = 6       ' Both submission and response
%MsV1_0GenericPassthrough       = 7       ' Both submission and response
%MsV1_0CacheLogon               = 8       ' Submission only, no response
%MsV1_0SubAuth                  = 9       ' Both submission and response
%MsV1_0DeriveCredential         = 10      ' Both submission and response
%MsV1_0CacheLookup              = 11      ' Both submission and response
'#if (_WIN32_WINNT >= 0x0501)
%MsV1_0SetProcessOption         = 12      ' Submission only, no response
'#endif
'#if (_WIN32_WINNT >= 0x0600)
%MsV1_0ConfigLocalAliases       = 13
%MsV1_0ClearCachedCredentials   = 14
'#endif

' // Size = 40 bytes
TYPE MSV1_0_CHANGEPASSWORD_REQUEST DWORD
   MessageType   AS LONG             ' MSV1_0_PROTOCOL_MESSAGE_TYPE
   DomainName    AS UNICODE_STRING   ' UNICODE_STRING
   AccountName   AS UNICODE_STRING   ' UNICODE_STRING
   OldPassword   AS UNICODE_STRING   ' UNICODE_STRING
   NewPassword   AS UNICODE_STRING   ' UNICODE_STRING
   Impersonating AS BYTE             ' BOOLEAN
END TYPE

' // Size = 32 bytes
TYPE MSV1_0_CHANGEPASSWORD_RESPONSE DWORD
   MessageType        AS LONG   ' MSV1_0_PROTOCOL_MESSAGE_TYPE
   PasswordInfoValid  AS BYTE   ' BOOLEAN
   DomainPasswordInfo AS DOMAIN_PASSWORD_INFORMATION
END TYPE

'//
'// MsV1_0GenericPassthrough - for remoting a CallPackage to
'// a domain controller on the specified domain
'//

' // Size = 32 bytes
TYPE MSV1_0_PASSTHROUGH_REQUEST DWORD
   MessageType AS LONG             ' MSV1_0_PROTOCOL_MESSAGE_TYPE
   DomainName  AS UNICODE_STRING   ' UNICODE_STRING
   PackageName AS UNICODE_STRING   ' UNICODE_STRING
   DataLength  AS DWORD            ' ULONG
   LogonData   AS BYTE PTR         ' PUCHAR
   Pad         AS DWORD            ' ULONG
END TYPE

' // Size = 16 bytes
TYPE MSV1_0_PASSTHROUGH_RESPONSE DWORD
   MessageType    AS LONG       ' MSV1_0_PROTOCOL_MESSAGE_TYPE
   Pad            AS DWORD      ' ULONG
   DataLength     AS DWORD      ' ULONG
   ValidationData AS BYTE PTR   ' PUCHAR
END TYPE

'//
'// MsV1_0SubAuthInfo submit buffer and response - for submitting a buffer to a
'// specified Subauthentication Package during an LsaCallAuthenticationPackage().
'// If this Subauthentication is to be done locally, then package this message
'// in LsaCallAuthenticationPackage(). If this SubAuthentication needs to be done
'// on the domain controller, then call LsaCallauthenticationPackage with the
'// message type being MsV1_0GenericPassThrough and the LogonData in this struct
'// should be a PMSV1_0_SUBAUTH_REQUEST
'//

' // Size = 16 bytes
TYPE MSV1_0_SUBAUTH_REQUEST DWORD
   MessageType         AS LONG       ' MSV1_0_PROTOCOL_MESSAGE_TYPE
   SubAuthPackageId    AS DWORD      ' ULONG
   SubAuthInfoLength   AS DWORD      ' ULONG
   SubAuthSubmitBuffer AS BYTE PTR   ' PUCHAR
END TYPE

' // Size = 12 bytes
TYPE MSV1_0_SUBAUTH_RESPONSE DWORD
   MessageType         AS LONG       ' MSV1_0_PROTOCOL_MESSAGE_TYPE
   SubAuthInfoLength   AS DWORD      ' ULONG
   SubAuthReturnBuffer AS BYTE PTR   ' PUCHAR
END TYPE

'#if(_WIN32_WINNT >= 0x0501)
'#define RtlGenRandom                    SystemFunction036
'#endif
'#if(_WIN32_WINNT >= 0x0500)
'#define RtlEncryptMemory                SystemFunction040
'#define RtlDecryptMemory                SystemFunction041
'#endif

'#if(_WIN32_WINNT >= 0x0501)
#IF %WINVER >= &H0501
DECLARE FUNCTION RtlGenRandom IMPORT "Advapi32.dll" ALIAS "SystemFunction036" ( _
   BYREF RandomBuffer AS ANY _                          ' __out PVOID RandomBuffer
 , BYVAL RandomBufferLength AS DWORD _                  ' __in ULONG RandomBufferLength
 ) AS BYTE                                              ' BOOLEAN
#ENDIF

'//
'// The buffer passed into RtlEncryptMemory and RtlDecryptMemory
'// must be a multiple of this length.
'//

%RTL_ENCRYPT_MEMORY_SIZE             = 8

'//
'// Allow Encrypt/Decrypt across process boundaries.
'// eg: encrypted buffer passed across LPC to another process which calls RtlDecryptMemory.
'//

%RTL_ENCRYPT_OPTION_CROSS_PROCESS    = &H01

'//
'// Allow Encrypt/Decrypt across callers with same LogonId.
'// eg: encrypted buffer passed across LPC to another process which calls RtlDecryptMemory whilst impersonating.
'//

%RTL_ENCRYPT_OPTION_SAME_LOGON       = &H02

DECLARE FUNCTION RtlEncryptMemory IMPORT "Advapi32.dll" ALIAS "SystemFunction040" ( _
   BYREF Memory AS ANY _                                ' __inout PVOID Memory
 , BYVAL MemorySize AS DWORD _                          ' __in ULONG MemorySize
 , BYVAL OptionFlags AS DWORD _                         ' __in ULONG OptionFlags
 ) AS LONG                                              ' NTSTATUS

DECLARE FUNCTION RtlDecryptMemory IMPORT "Advapi32.dll" ALIAS "SystemFunction041" ( _
   BYREF Memory AS ANY _                                ' __inout PVOID Memory
 , BYVAL MemorySize AS DWORD _                          ' __in ULONG MemorySize
 , BYVAL OptionFlags AS DWORD _                         ' __in ULONG OptionFlags
 ) AS LONG                                              ' NTSTATUS

'// Revision of the Kerberos Protocol.  MS uses Version 5, Revision 6

%KERBEROS_VERSION  = 5
%KERBEROS_REVISION = 6

'// Encryption Types:
'// These encryption types are supported by the default MS KERBSUPP DLL
'// as crypto systems.  Values over 127 are local values, and may be changed
'// without notice.

%KERB_ETYPE_NULL                    = 0
%KERB_ETYPE_DES_CBC_CRC             = 1
%KERB_ETYPE_DES_CBC_MD4             = 2
%KERB_ETYPE_DES_CBC_MD5             = 3
%KERB_ETYPE_AES128_CTS_HMAC_SHA1_96 = 17
%KERB_ETYPE_AES256_CTS_HMAC_SHA1_96 = 18

%KERB_ETYPE_RC4_MD4                 = -128   ' &HFFFFFF80&
%KERB_ETYPE_RC4_PLAIN2              = -129
%KERB_ETYPE_RC4_LM                  = -130
%KERB_ETYPE_RC4_SHA                 = -131
%KERB_ETYPE_DES_PLAIN               = -132
%KERB_ETYPE_RC4_HMAC_OLD            = -133   ' &HFFFFFF7B&
%KERB_ETYPE_RC4_PLAIN_OLD           = -134
%KERB_ETYPE_RC4_HMAC_OLD_EXP        = -135
%KERB_ETYPE_RC4_PLAIN_OLD_EXP       = -136
%KERB_ETYPE_RC4_PLAIN               = -140
%KERB_ETYPE_RC4_PLAIN_EXP           = -141

'//
'// used internally by userapi.cxx
'//

%KERB_ETYPE_AES128_CTS_HMAC_SHA1_96_PLAIN = -148
%KERB_ETYPE_AES256_CTS_HMAC_SHA1_96_PLAIN = -149

'//
'// Pkinit encryption types
'//

%KERB_ETYPE_DSA_SHA1_CMS      = 9
%KERB_ETYPE_RSA_MD5_CMS       = 10
%KERB_ETYPE_RSA_SHA1_CMS      = 11
%KERB_ETYPE_RC2_CBC_ENV       = 12
%KERB_ETYPE_RSA_ENV           = 13
%KERB_ETYPE_RSA_ES_OEAP_ENV   = 14
%KERB_ETYPE_DES_EDE3_CBC_ENV  = 15

'//
'// Deprecated
'//

%KERB_ETYPE_DSA_SIGN          = 8
%KERB_ETYPE_RSA_PRIV          = 9
%KERB_ETYPE_RSA_PUB           = 10
%KERB_ETYPE_RSA_PUB_MD5       = 11
%KERB_ETYPE_RSA_PUB_SHA1      = 12
%KERB_ETYPE_PKCS7_PUB         = 13

'#if(_WIN32_WINNT >= 0x0502)
'//
'// Unsupported but defined types
'//

%KERB_ETYPE_DES3_CBC_MD5      = 5
%KERB_ETYPE_DES3_CBC_SHA1     = 7
%KERB_ETYPE_DES3_CBC_SHA1_KD  = 16
'#endif

'//
'// In use types
'//

%KERB_ETYPE_DES_CBC_MD5_NT    = 20
%KERB_ETYPE_RC4_HMAC_NT       = 23
%KERB_ETYPE_RC4_HMAC_NT_EXP   = 24

'// Checksum algorithms.
'// These algorithms are keyed internally for our use.

%KERB_CHECKSUM_NONE          = 0
%KERB_CHECKSUM_CRC32         = 1
%KERB_CHECKSUM_MD4           = 2
%KERB_CHECKSUM_KRB_DES_MAC   = 4
'#if (_WIN32_WINNT >= 0x0501)
%KERB_CHECKSUM_KRB_DES_MAC_K = 5
'#endif
%KERB_CHECKSUM_MD5           = 7
%KERB_CHECKSUM_MD5_DES       = 8

%KERB_CHECKSUM_SHA1_NEW            = 14          ' // defined in RFC3961
%KERB_CHECKSUM_HMAC_SHA1_96_AES128 = 15
%KERB_CHECKSUM_HMAC_SHA1_96_AES256 = 16

%KERB_CHECKSUM_LM          = -130
%KERB_CHECKSUM_SHA1        = -131
%KERB_CHECKSUM_REAL_CRC32  = -132
%KERB_CHECKSUM_DES_MAC     = -133
%KERB_CHECKSUM_DES_MAC_MD5 = -134
%KERB_CHECKSUM_MD25        = -135
%KERB_CHECKSUM_RC4_MD5     = -136
%KERB_CHECKSUM_MD5_HMAC    = -137    ' used by netlogon
%KERB_CHECKSUM_HMAC_MD5    = -138    ' used by Kerberos

'//
'// used internally by userapi.cxx
'//

%KERB_CHECKSUM_HMAC_SHA1_96_AES128_Ki = -150
%KERB_CHECKSUM_HMAC_SHA1_96_AES256_Ki = -151

%AUTH_REQ_ALLOW_FORWARDABLE      = &H00000001???
%AUTH_REQ_ALLOW_PROXIABLE        = &H00000002???
%AUTH_REQ_ALLOW_POSTDATE         = &H00000004???
%AUTH_REQ_ALLOW_RENEWABLE        = &H00000008???
%AUTH_REQ_ALLOW_NOADDRESS        = &H00000010???
%AUTH_REQ_ALLOW_ENC_TKT_IN_SKEY  = &H00000020???
%AUTH_REQ_ALLOW_VALIDATE         = &H00000040???
%AUTH_REQ_VALIDATE_CLIENT        = &H00000080???
%AUTH_REQ_OK_AS_DELEGATE         = &H00000100???
%AUTH_REQ_PREAUTH_REQUIRED       = &H00000200???
%AUTH_REQ_TRANSITIVE_TRUST       = &H00000400???
'#if(_WIN32_WINNT >= 0x0502)
%AUTH_REQ_ALLOW_S4U_DELEGATE     = &H00000800???
'#endif

%AUTH_REQ_PER_USER_FLAGS = %AUTH_REQ_ALLOW_FORWARDABLE OR _
                           %AUTH_REQ_ALLOW_PROXIABLE OR _
                           %AUTH_REQ_ALLOW_POSTDATE OR _
                           %AUTH_REQ_ALLOW_RENEWABLE OR _
                           %AUTH_REQ_ALLOW_VALIDATE

'//
'// Ticket Flags:
'//

%KERB_TICKET_FLAGS_reserved          = &H80000000???
%KERB_TICKET_FLAGS_forwardable       = &H40000000???
%KERB_TICKET_FLAGS_forwarded         = &H20000000???
%KERB_TICKET_FLAGS_proxiable         = &H10000000???
%KERB_TICKET_FLAGS_proxy             = &H08000000???
%KERB_TICKET_FLAGS_may_postdate      = &H04000000???
%KERB_TICKET_FLAGS_postdated         = &H02000000???
%KERB_TICKET_FLAGS_invalid           = &H01000000???
%KERB_TICKET_FLAGS_renewable         = &H00800000???
%KERB_TICKET_FLAGS_initial           = &H00400000???
%KERB_TICKET_FLAGS_pre_authent       = &H00200000???
%KERB_TICKET_FLAGS_hw_authent        = &H00100000???
%KERB_TICKET_FLAGS_ok_as_delegate    = &H00040000???
%KERB_TICKET_FLAGS_name_canonicalize = &H00010000???
'#if (_WIN32_WINNT == 0x0501)
%KERB_TICKET_FLAGS_cname_in_pa_data  = &H00040000???
'#endif
%KERB_TICKET_FLAGS_reserved1         = &H00000001???

'#if (_WIN32_WINNT >= 0x0501)
'//
'// Name types
'//

%KRB_NT_UNKNOWN              = 0     ' Name type not known
%KRB_NT_PRINCIPAL            = 1     ' Just the name of the principal as in DCE, or for users
%KRB_NT_PRINCIPAL_AND_ID     = -131  ' Name of the principal and its SID.
%KRB_NT_SRV_INST             = 2     ' Service and other unique instance (krbtgt)
%KRB_NT_SRV_INST_AND_ID      = -132  ' SPN and SID
%KRB_NT_SRV_HST              = 3     ' Service with host name as instance (telnet, rcommands)
%KRB_NT_SRV_XHST             = 4     ' Service with host as remaining components
%KRB_NT_UID                  = 5     ' Unique ID
%KRB_NT_ENTERPRISE_PRINCIPAL = 10    ' UPN or SPN
%KRB_NT_ENT_PRINCIPAL_AND_ID = -130  ' UPN and SID

'//
'// MS extensions, negative according to the RFC
'//

%KRB_NT_MS_PRINCIPAL        = -128   ' // NT4 style name

%KRB_NT_MS_PRINCIPAL_AND_ID = -129   ' // nt4 style name with sid

%KRB_NT_MS_BRANCH_ID        = -133   ' // Branch ID

'#define KERB_IS_MS_PRINCIPAL(_x_) (((_x_) <= KRB_NT_MS_PRINCIPAL) || ((_x_) >= KRB_NT_ENTERPRISE_PRINCIPAL))

FUNCTION KERB_IS_MS_PRINCIPAL (BYVAL x AS LONG) AS LONG
   FUNCTION = (((x) <= %KRB_NT_MS_PRINCIPAL) OR ((x) >= %KRB_NT_ENTERPRISE_PRINCIPAL))
END FUNCTION
'#endif

'#if (_WIN32_WINNT >= 0x0600)
%KRB_NT_X500_PRINCIPAL = 6          ' // Encoded X.500 Distingished name [RFC 2253]
'#endif

'#ifndef MICROSOFT_KERBEROS_NAME_A

'#define MICROSOFT_KERBEROS_NAME_A   "Kerberos"
'#define MICROSOFT_KERBEROS_NAME_W   L"Kerberos"
'#ifdef WIN32_CHICAGO
'#define MICROSOFT_KERBEROS_NAME MICROSOFT_KERBEROS_NAME_A
'#else
'#define MICROSOFT_KERBEROS_NAME MICROSOFT_KERBEROS_NAME_W
'#endif // WIN32_CHICAGO
'#endif // MICROSOFT_KERBEROS_NAME_A

#IF NOT %DEF($MICROSOFT_KERBEROS_NAME_A)
   $MICROSOFT_KERBEROS_NAME_A = "Kerberos"
   $$MICROSOFT_KERBEROS_NAME_W = "Kerberos"$$
   #IF %DEF(%UNICODE)
      MACRO MICROSOFT_KERBEROS_NAME = $$MICROSOFT_KERBEROS_NAME_W
   #ELSE
      MACRO MICROSOFT_KERBEROS_NAME = $MICROSOFT_KERBEROS_NAME_A
   #ENDIF
#ENDIF


'/////////////////////////////////////////////////////////////////////////
'//
'// Quality of protection parameters for MakeSignature / EncryptMessage
'//
'/////////////////////////////////////////////////////////////////////////

'//
'// This flag indicates to EncryptMessage that the message is not to actually
'// be encrypted, but a header/trailer are to be produced.
'//

%KERB_WRAP_NO_ENCRYPT = &H80000001???

'/////////////////////////////////////////////////////////////////////////
'//
'// LsaLogonUser parameters
'//
'/////////////////////////////////////////////////////////////////////////

' KERB_LOGON_SUBMIT_TYPE enum
%KerbInteractiveLogon       = 2
%KerbSmartCardLogon         = 6
%KerbWorkstationUnlockLogon = 7
%KerbSmartCardUnlockLogon   = 8
%KerbProxyLogon             = 9
%KerbTicketLogon            = 10
%KerbTicketUnlockLogon      = 11
'//#if (_WIN32_WINNT >= 0x0501) -- Disabled until IIS fixes their target version.
%KerbS4ULogon               = 12
'//#endif
%KerbCertificateLogon       = 13
%KerbCertificateS4ULogon    = 14
%KerbCertificateUnlockLogon = 15

' // Size = 28 bytes
TYPE KERB_INTERACTIVE_LOGON DWORD
   MessageType     AS LONG             ' KERB_LOGON_SUBMIT_TYPE
   LogonDomainName AS UNICODE_STRING   ' UNICODE_STRING
   UserName        AS UNICODE_STRING   ' UNICODE_STRING
   Password        AS UNICODE_STRING   ' UNICODE_STRING
END TYPE

' // Size = 36 bytes
TYPE KERB_INTERACTIVE_UNLOCK_LOGON DWORD
   Logon   AS KERB_INTERACTIVE_LOGON   ' KERB_INTERACTIVE_LOGON
   LogonId AS QUAD                     ' LUID
END TYPE

' // Size = 20 bytes
TYPE KERB_SMART_CARD_LOGON DWORD
   MessageType   AS LONG             ' KERB_LOGON_SUBMIT_TYPE
   Pin           AS UNICODE_STRING   ' UNICODE_STRING
   CspDataLength AS DWORD            ' ULONG
   CspData       AS BYTE PTR         ' PUCHAR
END TYPE

' // Size = 28 bytes
TYPE KERB_SMART_CARD_UNLOCK_LOGON DWORD
   Logon   AS KERB_SMART_CARD_LOGON   ' KERB_SMART_CARD_LOGON
   LogonId AS QUAD                    ' LUID
END TYPE


'#if (_WIN32_WINNT >= 0x0600)

'//
'// let the KDC detect account mapping conflicts for the same certificate.
'//

%KERB_CERTIFICATE_LOGON_FLAG_CHECK_DUPLICATES = &H1

' // Size = 40 bytes
TYPE KERB_CERTIFICATE_LOGON DWORD
   MessageType   AS LONG             ' KERB_LOGON_SUBMIT_TYPE // KerbCertificateLogon
   DomainName    AS UNICODE_STRING   ' // OPTIONAL, if supplied, used to locate the account forest
   UserName      AS UNICODE_STRING   '   // OPTIONAL, if supplied, used to locate the account
   Pin           AS UNICODE_STRING
   Flags         AS DWORD            ' ULONG // additional flags
   CspDataLength AS DWORD            ' ULONG
   CspData       AS BYTE PTR         ' PUCHAR // contains the smartcard CSP data
END TYPE

' // Size = 48 bytes
TYPE KERB_CERTIFICATE_UNLOCK_LOGON DWORD
   Logon   AS KERB_CERTIFICATE_LOGON
   LogonId AS QUAD   ' LUID
END TYPE

'//
'// let the KDC detect account mapping conflicts for the same certificate.
'//

%KERB_CERTIFICATE_S4U_LOGON_FLAG_CHECK_DUPLICATES = &H1
%KERB_CERTIFICATE_S4U_LOGON_FLAG_CHECK_LOGONHOURS = &H2
%KERB_CERTIFICATE_S4U_LOGON_FLAG_FAIL_IF_NT_AUTH_POLICY_REQUIRED = &H4

' // Size = 32 bytes
TYPE KERB_CERTIFICATE_S4U_LOGON DWORD
   MessageType       AS LONG   ' KERB_LOGON_SUBMIT_TYPE
   Flags             AS DWORD   ' ULONG
   UserPrincipalName AS UNICODE_STRING
           ' // OPTIONAL, certificate mapping hints: username or username@domain
   DomainName        AS UNICODE_STRING   ' // used to locate the forest
           ' // OPTIONAL, certificate mapping hints: if missing, using the local machine's domain
   CertificateLength AS DWORD   ' ULONG // for the client certificate
   Certificate       AS BYTE PTR   ' PUCHAR // for the client certificate, BER encoded
END TYPE

'#endif


'//
'// Structure used for a ticket-only logon
'//

' // Size = 24 bytes
TYPE KERB_TICKET_LOGON DWORD
   MessageType                AS LONG       ' KERB_LOGON_SUBMIT_TYPE
   Flags                      AS DWORD      ' ULONG
   ServiceTicketLength        AS DWORD      ' ULONG
   TicketGrantingTicketLength AS DWORD      ' ULONG
   ServiceTicket              AS BYTE PTR   ' PUCHAR  // REQUIRED: Service ticket "host"
   TicketGrantingTicket       AS BYTE PTR   ' PUCHAR  // OPTIONAL: User's encdoded in a KERB_CRED message, encrypted with session key from service ticket
END TYPE

'//
'// Flags for the ticket logon flags field
'//

%KERB_LOGON_FLAG_ALLOW_EXPIRED_TICKET = &H1

' // Size = 32 bytes
TYPE KERB_TICKET_UNLOCK_LOGON DWORD
   Logon   AS KERB_TICKET_LOGON   ' KERB_TICKET_LOGON
   LogonId AS QUAD                ' LUID
END TYPE

'//#if (_WIN32_WINNT >= 0x0501) -- Disabled until IIS fixes their target version.
'//
'//  Used for S4U Client requests
'//
'//

'#if (_WIN32_WINNT >= 0x0600)

'//
'// request to enforce logon hours policy
'//

%KERB_S4U_LOGON_FLAG_CHECK_LOGONHOURS = &H2

'#endif

'//
'//  Used for S4U Client requests
'//
'//

' // Size = 24 bytes
TYPE KERB_S4U_LOGON DWORD
   MessageType AS LONG             ' KERB_LOGON_SUBMIT_TYPE enum
   Flags       AS DWORD            ' ULONG
   ClientUpn   AS UNICODE_STRING   ' UNICODE_STRING
   ClientRealm AS UNICODE_STRING   ' UNICODE_STRING
END TYPE

'//
'// Use the same profile structure as MSV1_0
'//

' KERB_PROFILE_BUFFER_TYPE enum
%KerbInteractiveProfile = 2
%KerbSmartCardProfile   = 4
%KerbTicketProfile      = 6

' // Size = 112 bytes
TYPE KERB_INTERACTIVE_PROFILE   ' Must be 8 byte aligned
   MessageType        AS LONG             ' KERB_PROFILE_BUFFER_TYPE
   LogonCount         AS WORD             ' USHORT
   BadPasswordCount   AS WORD             ' USHORT
   LogonTime          AS QUAD             ' LARGE_INTEGER
   LogoffTime         AS QUAD             ' LARGE_INTEGER
   KickOffTime        AS QUAD             ' LARGE_INTEGER
   PasswordLastSet    AS QUAD             ' LARGE_INTEGER
   PasswordCanChange  AS QUAD             ' LARGE_INTEGER
   PasswordMustChange AS QUAD             ' LARGE_INTEGER
   LogonScript        AS UNICODE_STRING   ' UNICODE_STRING
   HomeDirectory      AS UNICODE_STRING   ' UNICODE_STRING
   FullName           AS UNICODE_STRING   ' UNICODE_STRING
   ProfilePath        AS UNICODE_STRING   ' UNICODE_STRING
   HomeDirectoryDrive AS UNICODE_STRING   ' UNICODE_STRING
   LogonServer        AS UNICODE_STRING   ' UNICODE_STRING
   UserFlags          AS DWORD            ' ULONG
   filler             AS DWORD            ' // To keep QWORD alignment
END TYPE

'//
'// For smart card, we return a smart card profile, which is an interactive
'// profile plus a certificate
'//

' // Size = 120 bytes
TYPE KERB_SMART_CARD_PROFILE   ' Must be 8 byte aligned
   Profile         AS KERB_INTERACTIVE_PROFILE
   CertificateSize AS DWORD      ' ULONG
   CertificateData AS BYTE PTR   ' PUCHAR
END TYPE

'//
'// For a ticket logon profile, we return the session key from the ticket
'//

' // Size = 12 bytes
TYPE KERB_CRYPTO_KEY DWORD
   KeyType AS LONG       ' LONG
   Length  AS DWORD      ' ULONG
   Value   AS BYTE PTR   ' PUCHAR
END TYPE

' // Size = 12 bytes
TYPE KERB_CRYPTO_KEY32 DWORD
   KeyType AS LONG    ' LONG
   Length  AS DWORD   ' ULONG
   Offset  AS DWORD   ' ULONG
END TYPE

' // Size = 128 bytes
TYPE KERB_TICKET_PROFILE   ' Must be 8 byte aligned
   Profile     AS KERB_INTERACTIVE_PROFILE
   SessionKey  AS KERB_CRYPTO_KEY
   alignment__ AS DWORD   ' // To keep 8 byte alignment
END TYPE

' KERB_PROTOCOL_MESSAGE_TYPE enum
%KerbDebugRequestMessage                 = 0
%KerbQueryTicketCacheMessage             = 1
%KerbChangeMachinePasswordMessage        = 2
%KerbVerifyPacMessage                    = 3
%KerbRetrieveTicketMessage               = 4
%KerbUpdateAddressesMessage              = 5
%KerbPurgeTicketCacheMessage             = 6
%KerbChangePasswordMessage               = 7
%KerbRetrieveEncodedTicketMessage        = 8
%KerbDecryptDataMessage                  = 9
%KerbAddBindingCacheEntryMessage         = 10
%KerbSetPasswordMessage                  = 11
%KerbSetPasswordExMessage                = 12
'#if (_WIN32_WINNT == 0x0500)
'    KerbAddExtraCredentialsMessage = 17
'#endif
'#if (_WIN32_WINNT >= 0x0501)
%KerbVerifyCredentialsMessage            = 13
%KerbQueryTicketCacheExMessage           = 14
%KerbPurgeTicketCacheExMessage           = 15
'#endif
'#if (_WIN32_WINNT >= 0x0502)
%KerbRefreshSmartcardCredentialsMessage  = 16
%KerbAddExtraCredentialsMessage          = 17
%KerbQuerySupplementalCredentialsMessage = 18
'#endif
'#if (_WIN32_WINNT >= 0x0600)
%KerbTransferCredentialsMessage          = 19
%KerbQueryTicketCacheEx2Message          = 20
%KerbSubmitTicketMessage                 = 21
%KerbAddExtraCredentialsExMessage        = 22
'#endif

'//
'// Used both for retrieving tickets and for querying ticket cache
'//

' // Size = 12 bytes
TYPE KERB_QUERY_TKT_CACHE_REQUEST DWORD
   MessageType AS LONG   ' KERB_PROTOCOL_MESSAGE_TYPE
   LogonId     AS QUAD   ' LUID
END TYPE

' // Size = 48 bytes
TYPE KERB_TICKET_CACHE_INFO   ' Must be 8 byte aligned
   ServerName     AS UNICODE_STRING   ' UNICODE_STRING
   RealmName      AS UNICODE_STRING   ' UNICODE_STRING
   StartTime      AS QUAD             ' LARGE_INTEGER
   EndTime        AS QUAD             ' LARGE_INTEGER
   RenewTime      AS QUAD             ' LARGE_INTEGER
   EncryptionType AS LONG             ' LONG
   TicketFlags    AS DWORD            ' ULONG
END TYPE

'#if (_WIN32_WINNT >= 0x0501)
' // Size = 64 bytes
TYPE KERB_TICKET_CACHE_INFO_EX   ' Must be 8 byte aligned
   ClientName     AS UNICODE_STRING   ' UNICODE_STRING
   ClientRealm    AS UNICODE_STRING   ' UNICODE_STRING
   ServerName     AS UNICODE_STRING   ' UNICODE_STRING
   ServerRealm    AS UNICODE_STRING   ' UNICODE_STRING
   StartTime      AS QUAD             ' LARGE_INTEGER
   EndTime        AS QUAD             ' LARGE_INTEGER
   RenewTime      AS QUAD             ' LARGE_INTEGER
   EncryptionType AS LONG             ' LONG
   TicketFlags    AS DWORD            ' ULONG
END TYPE
'#endif

' // Size = 72 bytes
TYPE KERB_TICKET_CACHE_INFO_EX2   ' Must be 8 byte aligned
   ClientName     AS UNICODE_STRING   ' UNICODE_STRING
   ClientRealm    AS UNICODE_STRING   ' UNICODE_STRING
   ServerName     AS UNICODE_STRING   ' UNICODE_STRING
   ServerRealm    AS UNICODE_STRING   ' UNICODE_STRING
   StartTime      AS QUAD             ' LARGE_INTEGER
   EndTime        AS QUAD             ' LARGE_INTEGER
   RenewTime      AS QUAD             ' LARGE_INTEGER
   EncryptionType AS LONG             ' LONG
   TicketFlags    AS DWORD            ' ULONG
   ' // the following are new in KERB_TICKET_CACHE_INFO_EX2
   SessionKeyType AS DWORD            ' ULONG
   BranchId       AS DWORD            ' ULONG
END TYPE

' // Size = 56 bytes
TYPE KERB_QUERY_TKT_CACHE_RESPONSE DWORD
   MessageType    AS LONG    ' KERB_PROTOCOL_MESSAGE_TYPE
   CountOfTickets AS DWORD   ' ULONG
   Tickets(0)     AS KERB_TICKET_CACHE_INFO  ' KERB_TICKET_CACHE_INFO Tickets[ANYSIZE_ARRAY]
END TYPE

'#if (_WIN32_WINNT >= 0x0502)
' // Size = 72 bytes
TYPE KERB_QUERY_TKT_CACHE_EX_RESPONSE DWORD
   MessageType    AS LONG    ' KERB_PROTOCOL_MESSAGE_TYPE
   CountOfTickets AS DWORD   ' ULONG
   Tickets(0)     AS KERB_TICKET_CACHE_INFO_EX  ' KERB_TICKET_CACHE_INFO_EX Tickets[ANYSIZE_ARRAY]
END TYPE
'#endif

' // Size = 80 bytes
TYPE KERB_QUERY_TKT_CACHE_EX2_RESPONSE DWORD
   MessageType    AS LONG    ' KERB_PROTOCOL_MESSAGE_TYPE
   CountOfTickets AS DWORD   ' ULONG
   Tickets(0)     AS KERB_TICKET_CACHE_INFO_EX2  ' KERB_TICKET_CACHE_INFO_EX2 Tickets[ANYSIZE_ARRAY]
END TYPE

'//
'// Types for retrieving encoded ticket from the cache
'//

#IF NOT %DEF(%SECHANDLE_DEFINED)
%SECHANDLE_DEFINED = 1
' // Size = 8 bytes
TYPE SecHandle DWORD
   dwLower AS DWORD   ' ULONG_PTR
   dwUpper AS DWORD   ' ULONG_PTR
END TYPE
#ENDIF  ' #IF NOT %DEF(%SECHANDLE_DEFINED)

'#if (_WIN32_WINNT >= 0x0501)
'// Ticket Flags
%KERB_USE_DEFAULT_TICKET_FLAGS       = &H0

'// CacheOptions
%KERB_RETRIEVE_TICKET_DEFAULT        = &H00
'#endif
%KERB_RETRIEVE_TICKET_DONT_USE_CACHE = &H01
%KERB_RETRIEVE_TICKET_USE_CACHE_ONLY = &H02
%KERB_RETRIEVE_TICKET_USE_CREDHANDLE = &H04
'#if (_WIN32_WINNT >= 0x0501)
%KERB_RETRIEVE_TICKET_AS_KERB_CRED   = &H08
%KERB_RETRIEVE_TICKET_WITH_SEC_CRED  = &H10
'#endif
'#if (_WIN32_WINNT >= 0x0600)
%KERB_RETRIEVE_TICKET_CACHE_TICKET   = &H20
'#endif

'#if (_WIN32_WINNT >= 0x0601)
%KERB_RETRIEVE_TICKET_MAX_LIFETIME   = &H40
'#endif

'#if (_WIN32_WINNT >= 0x0501)
'// Encryption Type options
%KERB_ETYPE_DEFAULT = &H0 ' don't specify etype in tkt req.

UNION KERB_AUTH_DATA_TYPE_UNION
   Type   AS DWORD      ' ULONG
   ' // For compatibility with the PB declares
   dType   AS DWORD      ' ULONG
END UNION

UNION KERB_AUTH_DATA_DATA_UNION
   Data   AS BYTE PTR   ' PUCHAR
   ' // For compatibility with the PB declares
   uData  AS BYTE PTR   ' PUCHAR
END UNION

' // Size = 12 bytes
TYPE KERB_AUTH_DATA DWORD
   KERB_AUTH_DATA_TYPE_UNION
   Length AS DWORD      ' ULONG
   KERB_AUTH_DATA_DATA_UNION
END TYPE

' // Size = 12 bytes
TYPE KERB_NET_ADDRESS DWORD
   Family  AS DWORD      ' ULONG
   Length  AS DWORD      ' ULONG
   Address AS BYTE PTR   ' PCHAR
END TYPE

' // Size = 16 bytes
TYPE KERB_NET_ADDRESSES DWORD
   Number       AS DWORD             ' ULONG
   Addresses(0) AS KERB_NET_ADDRESS  ' KERB_NET_ADDRESS Addresses[ANYSIZE_ARRAY]
END TYPE
'#endif

'//
'// Types for the information about a ticket
'//

' // Size = 12 bytes
TYPE KERB_EXTERNAL_NAME DWORD FILL
   NameType  AS INTEGER          ' SHORT
   NameCount AS WORD             ' USHORT
   Names(0)  AS UNICODE_STRING   ' UNICODE_STRING Names[ANYSIZE_ARRAY]
END TYPE

' // Size = 104 bytes
TYPE KERB_EXTERNAL_TICKET   ' Must be 8 byte aligned
   ServiceName         AS KERB_EXTERNAL_NAME PTR   ' PKERB_EXTERNAL_NAME
   TargetName          AS KERB_EXTERNAL_NAME PTR   ' PKERB_EXTERNAL_NAME
   ClientName          AS KERB_EXTERNAL_NAME PTR   ' PKERB_EXTERNAL_NAME
   DomainName          AS UNICODE_STRING           ' UNICODE_STRING
   TargetDomainName    AS UNICODE_STRING           ' UNICODE_STRING
   AltTargetDomainName AS UNICODE_STRING           ' UNICODE_STRING
   SessionKey          AS KERB_CRYPTO_KEY          ' KERB_CRYPTO_KEY
   TicketFlags         AS DWORD                    ' ULONG
   Flags               AS DWORD                    ' ULONG
   KeyExpirationTime   AS QUAD                     ' LARGE_INTEGER
   StartTime           AS QUAD                     ' LARGE_INTEGER
   EndTime             AS QUAD                     ' LARGE_INTEGER
   RenewUntil          AS QUAD                     ' LARGE_INTEGER
   TimeSkew            AS QUAD                     ' LARGE_INTEGER
   EncodedTicketSize   AS DWORD                    ' ULONG
   EncodedTicket       AS BYTE PTR                 ' PUCHAR
END TYPE

' // Size = 40 bytes
TYPE KERB_RETRIEVE_TKT_REQUEST DWORD
   MessageType       AS LONG             ' KERB_PROTOCOL_MESSAGE_TYPE
   LogonId           AS QUAD             ' LUID
   TargetName        AS UNICODE_STRING   ' UNICODE_STRING
   TicketFlags       AS DWORD            ' ULONG
   CacheOptions      AS DWORD            ' ULONG
   EncryptionType    AS LONG             ' LONG
   CredentialsHandle AS SecHandle        ' SecHandle
END TYPE

' // Size = 104 bytes
TYPE KERB_RETRIEVE_TKT_RESPONSE DWORD
   Ticket AS KERB_EXTERNAL_TICKET
END TYPE

'//
'// Used to purge entries from the ticket cache
'//

' // Size = 28 bytes
TYPE KERB_PURGE_TKT_CACHE_REQUEST DWORD
   MessageType AS LONG             ' KERB_PROTOCOL_MESSAGE_TYPE
   LogonId     AS QUAD             ' LUID
   ServerName  AS UNICODE_STRING   ' UNICODE_STRING
   RealmName   AS UNICODE_STRING   ' UNICODE_STRING
END TYPE

'#if (_WIN32_WINNT >= 0x0501)
'//
'// Flags for purge requests
'//

%KERB_PURGE_ALL_TICKETS = 1

' // Size = 80 bytes
TYPE KERB_PURGE_TKT_CACHE_EX_REQUEST DWORD
   MessageType    AS LONG    ' KERB_PROTOCOL_MESSAGE_TYPE
   LogonId        AS QUAD    ' LUID
   Flags          AS DWORD   ' ULONG
   TicketTemplate AS KERB_TICKET_CACHE_INFO_EX
END TYPE
'#endif

' // Size = 36 bytes
TYPE KERB_SUBMIT_TKT_REQUEST DWORD
   MessageType    AS LONG                ' KERB_PROTOCOL_MESSAGE_TYPE
   LogonId        AS QUAD                ' LUID
   Flags          AS DWORD               ' ULONG
   Key            AS KERB_CRYPTO_KEY32   ' // key to decrypt KERB_CRED
   KerbCredSize   AS DWORD               ' ULONG
   KerbCredOffset AS DWORD               ' ULONG
END TYPE

'//
'// KerbChangePassword
'//
'// KerbChangePassword changes the password on the KDC account plus
'//  the password cache and logon credentials if applicable.
'//
'//

' // Size = 40 bytes
TYPE KERB_CHANGEPASSWORD_REQUEST DWORD
   MessageType   AS LONG             ' KERB_PROTOCOL_MESSAGE_TYPE
   DomainName    AS UNICODE_STRING   ' UNICODE_STRING
   AccountName   AS UNICODE_STRING   ' UNICODE_STRING
   OldPassword   AS UNICODE_STRING   ' UNICODE_STRING
   NewPassword   AS UNICODE_STRING   ' UNICODE_STRING
   Impersonating AS BYTE             ' BOOLEAN
END TYPE

'//
'// KerbSetPassword
'//
'// KerbSetPassword changes the password on the KDC account plus
'//  the password cache and logon credentials if applicable.
'//
'//

' // Size = 48 bytes
TYPE KERB_SETPASSWORD_REQUEST DWORD
   MessageType       AS LONG             ' KERB_PROTOCOL_MESSAGE_TYPE
   LogonId           AS QUAD             ' LUID
   CredentialsHandle AS SecHandle        ' SecHandle
   Flags             AS DWORD            ' ULONG
   DomainName        AS UNICODE_STRING   ' UNICODE_STRING
   AccountName       AS UNICODE_STRING   ' UNICODE_STRING
   Password          AS UNICODE_STRING   ' UNICODE_STRING
END TYPE

' // Size = 80 bytes
TYPE KERB_SETPASSWORD_EX_REQUEST DWORD
   MessageType       AS LONG             ' KERB_PROTOCOL_MESSAGE_TYPE
   LogonId           AS QUAD             ' LUID
   CredentialsHandle AS SecHandle        ' SecHandle
   Flags             AS DWORD            ' ULONG
   AccountRealm      AS UNICODE_STRING   ' UNICODE_STRING
   AccountName       AS UNICODE_STRING   ' UNICODE_STRING
   Password          AS UNICODE_STRING   ' UNICODE_STRING
   ClientRealm       AS UNICODE_STRING   ' UNICODE_STRING
   ClientName        AS UNICODE_STRING   ' UNICODE_STRING
   Impersonating     AS BYTE             ' BOOLEAN
   KdcAddress        AS UNICODE_STRING   ' UNICODE_STRING
   KdcAddressType    AS DWORD            ' ULONG
END TYPE

%DS_UNKNOWN_ADDRESS_TYPE     = 0  ' anything *but* IP
%KERB_SETPASS_USE_LOGONID    = 1
%KERB_SETPASS_USE_CREDHANDLE = 2

' // Size = 52 bytes
TYPE KERB_DECRYPT_REQUEST DWORD
   MessageType       AS LONG              ' KERB_PROTOCOL_MESSAGE_TYPE enum
   LogonId           AS QUAD              ' LUID
   Flags             AS DWORD             ' ULONG
   CryptoType        AS LONG              ' LONG
   KeyUsage          AS LONG              ' LONG
   Key               AS KERB_CRYPTO_KEY   ' KERB_CRYPTO_KEY  // optional
   EncryptedDataSize AS DWORD             ' ULONG
   InitialVectorSize AS DWORD             ' ULONG
   InitialVector     AS BYTE PTR          ' PUCHAR
   EncryptedData     AS BYTE PTR          ' PUCHAR
END TYPE

'//
'// If set, use the primary key from the current logon session of the one provided in the LogonId field.
'// Otherwise, use the Key in the KERB_DECRYPT_MESSAGE.

%KERB_DECRYPT_FLAG_DEFAULT_KEY = &H00000001???

' // Size = 1 byte
TYPE KERB_DECRYPT_RESPONSE BYTE
   DecryptedData(0) AS BYTE   ' UCHAR DecryptedData[ANYSIZE_ARRAY]
END TYPE

'//
'// Request structure for adding a binding cache entry. TCB privilege
'// is required for this operation.
'//

' // Size = 24 bytes
TYPE KERB_ADD_BINDING_CACHE_ENTRY_REQUEST DWORD
   MessageType AS LONG             ' KERB_PROTOCOL_MESSAGE_TYPE
   RealmName   AS UNICODE_STRING   ' UNICODE_STRING
   KdcAddress  AS UNICODE_STRING   ' UNICODE_STRING
   AddressType AS DWORD            ' ULONG
END TYPE

'#if (_WIN32_WINNT >= 0x0502)
'//
'// Request structure for reacquiring smartcard credentials for a
'// given LUID.
'// Requires TCB.
'//

' // Size = 24 bytes
TYPE KERB_REFRESH_SCCRED_REQUEST DWORD
   MessageType    AS LONG             ' KERB_PROTOCOL_MESSAGE_TYPE
   CredentialBlob AS UNICODE_STRING   ' UNICODE_STRING
   LogonId        AS QUAD             ' LUID
   Flags          AS DWORD            ' ULONG
END TYPE

'//
'// Flags for KERB_REFRESH_SCCRED_REQUEST
'//
'//      KERB_REFRESH_SCCRED_RELEASE
'//      Release the smartcard handle for LUID
'//
'//      KERB_REFRESH_SCCRED_GETTGT
'//      Use the certificate hash in the blob to get a TGT for the logon
'//      session.
'//
%KERB_REFRESH_SCCRED_RELEASE  = &H0
%KERB_REFRESH_SCCRED_GETTGT   = &H1
'#endif

'#if (_WIN32_WINNT != 0x0501)
'//
'// Request structure for adding extra Server credentials to a given
'// logon session.  Only applicable during AcceptSecurityContext, and
'// requires TCB to alter "other" creds
'//

' // Size = 40 bytes
TYPE KERB_ADD_CREDENTIALS_REQUEST DWORD
   MessageType AS LONG             ' KERB_PROTOCOL_MESSAGE_TYPE
   UserName    AS UNICODE_STRING   ' UNICODE_STRING
   DomainName  AS UNICODE_STRING   ' UNICODE_STRING
   Password    AS UNICODE_STRING   ' UNICODE_STRING
   LogonId     AS QUAD             ' LUID
   Flags       AS DWORD            ' ULONG
END TYPE

%KERB_REQUEST_ADD_CREDENTIAL     = 1
%KERB_REQUEST_REPLACE_CREDENTIAL = 2
%KERB_REQUEST_REMOVE_CREDENTIAL  = 4
'#endif

'#if (_WIN32_WINNT >= 0x0600)

' // Size = 52 bytes
TYPE KERB_ADD_CREDENTIALS_REQUEST_EX DWORD
   Credentials        AS KERB_ADD_CREDENTIALS_REQUEST
   ' // new for Ex
   PrincipalNameCount AS DWORD   ' ULONG
   PrincipalNames(0)  AS UNICODE_STRING
END TYPE

'#endif

'//
'// Request structure for transferring credentials between 2 luids.
'// Requires TCB.
'//

' // Size = 24 bytes
TYPE KERB_TRANSFER_CRED_REQUEST DWORD
   MessageType        AS LONG    ' KERB_PROTOCOL_MESSAGE_TYPE
   OriginLogonId      AS QUAD    ' LUID
   DestinationLogonId AS QUAD    ' LUID
   Flags              AS DWORD   ' ULONG
END TYPE

%KERB_TRANSFER_CRED_WITH_TICKETS = &H1

' // Size = 8 bytes
TYPE POLICY_AUDIT_SID_ARRAY DWORD
   UsersCount   AS DWORD     ' ULONG
   UserSidArray AS SID PTR   ' PSID*
END TYPE

' // Size = 36 bytes
TYPE AUDIT_POLICY_INFORMATION DWORD
   AuditSubCategoryGuid AS GUID   ' GUID
   AuditingInformation  AS DWORD  ' ULONG
   AuditCategoryGuid    AS GUID   ' GUID
END TYPE

%AUDIT_SET_SYSTEM_POLICY                 = &H0001
%AUDIT_QUERY_SYSTEM_POLICY               = &H0002
%AUDIT_SET_USER_POLICY                   = &H0004
%AUDIT_QUERY_USER_POLICY                 = &H0008
%AUDIT_ENUMERATE_USERS                   = &H0010
%AUDIT_SET_MISC_POLICY                   = &H0020
%AUDIT_QUERY_MISC_POLICY                 = &H0040

%AUDIT_GENERIC_ALL            = %STANDARD_RIGHTS_REQUIRED  OR _
                                %AUDIT_SET_SYSTEM_POLICY   OR _
                                %AUDIT_QUERY_SYSTEM_POLICY OR _
                                %AUDIT_SET_USER_POLICY     OR _
                                %AUDIT_QUERY_USER_POLICY   OR _
                                %AUDIT_ENUMERATE_USERS     OR _
                                %AUDIT_SET_MISC_POLICY     OR _
                                %AUDIT_QUERY_MISC_POLICY

%AUDIT_GENERIC_READ           = %STANDARD_RIGHTS_READ      OR _
                                %AUDIT_QUERY_SYSTEM_POLICY OR _
                                %AUDIT_QUERY_USER_POLICY   OR _
                                %AUDIT_ENUMERATE_USERS     OR _
                                %AUDIT_QUERY_MISC_POLICY

%AUDIT_GENERIC_WRITE          = %STANDARD_RIGHTS_WRITE     OR _
                                %AUDIT_SET_USER_POLICY     OR _
                                %AUDIT_SET_MISC_POLICY     OR _
                                %AUDIT_SET_SYSTEM_POLICY

%AUDIT_GENERIC_EXECUTE        = %STANDARD_RIGHTS_EXECUTE


#IF %DEF(%USEPBDECL)
DECLARE FUNCTION AuditSetSystemPolicy LIB "AdvApi32.dll" _
    ALIAS "AuditSetSystemPolicy" ( _
    BYVAL pAuditPolicy  AS AUDIT_POLICY_INFORMATION PTR, _
    BYVAL dwPolicyCount AS DWORD _
    ) AS BYTE  ' BOOLEAN
#ELSE
DECLARE FUNCTION AuditSetSystemPolicy IMPORT "Advapi32.dll" ALIAS "AuditSetSystemPolicy" ( _
   BYREF pAuditPolicy AS AUDIT_POLICY_INFORMATION _     ' __in PCAUDIT_POLICY_INFORMATION pAuditPolicy
 , BYVAL PolicyCount AS DWORD _                         ' __in ULONG PolicyCount
 ) AS BYTE                                              ' BOOLEAN
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION AuditSetPerUserPolicy LIB "AdvApi32.dll" _
    ALIAS "AuditSetPerUserPolicy" ( _
    pSid                AS SID, _
    BYVAL pAuditPolicy  AS AUDIT_POLICY_INFORMATION PTR, _
    BYVAL dwPolicyCount AS DWORD _
    ) AS BYTE  ' BOOLEAN
#ELSE
DECLARE FUNCTION AuditSetPerUserPolicy IMPORT "Advapi32.dll" ALIAS "AuditSetPerUserPolicy" ( _
   BYVAL pSid AS SID PTR _                              ' __in const PSID pSid
 , BYREF pAuditPolicy AS AUDIT_POLICY_INFORMATION _     ' __in PCAUDIT_POLICY_INFORMATION pAuditPolicy
 , BYVAL PolicyCount AS DWORD _                         ' __in ULONG PolicyCount
 ) AS BYTE                                              ' BOOLEAN
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION AuditQuerySystemPolicy LIB "AdvApi32.dll" _
    ALIAS "AuditQuerySystemPolicy" ( _
    BYVAL pSubCategoryGuids AS GUID PTR, _
    BYVAL dwPolicyCount     AS DWORD, _
    ppAuditPolicy           AS ANY _   ' AUDIT_POLICY_INFORMATION PTR PTR
    ) AS BYTE  ' BOOLEAN
#ELSE
DECLARE FUNCTION AuditQuerySystemPolicy IMPORT "Advapi32.dll" ALIAS "AuditQuerySystemPolicy" ( _
   BYREF pSubCategoryGuids AS GUID _                    ' __in const GUID* pSubCategoryGuids
 , BYVAL PolicyCount AS DWORD _                         ' __in ULONG PolicyCount
 , BYREF ppAuditPolicy AS AUDIT_POLICY_INFORMATION _    ' __out PAUDIT_POLICY_INFORMATION* ppAuditPolicy
 ) AS BYTE                                              ' BOOLEAN
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION AuditQueryPerUserPolicy LIB "AdvApi32.dll" _
    ALIAS "AuditQueryPerUserPolicy" ( _
    pSid                    AS SID, _
    BYVAL pSubCategoryGuids AS GUID PTR, _
    BYVAL dwPolicyCount     AS DWORD, _
    ppAuditPolicy           AS ANY _   ' AUDIT_POLICY_INFORMATION PTR PTR
    ) AS BYTE  ' BOOLEAN
#ELSE
DECLARE FUNCTION AuditQueryPerUserPolicy IMPORT "Advapi32.dll" ALIAS "AuditQueryPerUserPolicy" ( _
   BYVAL pSid AS SID PTR _                              ' __in const PSID pSid
 , BYREF pSubCategoryGuids AS GUID _                    ' __in const GUID* pSubCategoryGuids
 , BYVAL PolicyCount AS DWORD _                         ' __in ULONG PolicyCount
 , BYREF ppAuditPolicy AS AUDIT_POLICY_INFORMATION _    ' __out PAUDIT_POLICY_INFORMATION* ppAuditPolicy
 ) AS BYTE                                              ' BOOLEAN
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION AuditEnumeratePerUserPolicy LIB "AdvApi32.dll" _
    ALIAS "AuditEnumeratePerUserPolicy" ( _
    ppAuditSidArray AS ANY _   ' POLICY_AUDIT_SID_ARRAY PTR PTR
    ) AS BYTE  ' BOOLEAN
#ELSE
DECLARE FUNCTION AuditEnumeratePerUserPolicy IMPORT "Advapi32.dll" ALIAS "AuditEnumeratePerUserPolicy" ( _
   BYREF ppAuditSidArray AS POLICY_AUDIT_SID_ARRAY _    ' __out PPOLICY_AUDIT_SID_ARRAY* ppAuditSidArray
 ) AS BYTE                                              ' BOOLEAN
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION AuditComputeEffectivePolicyBySid LIB "AdvApi32.dll" _
    ALIAS "AuditComputeEffectivePolicyBySid" ( _
    pSid                    AS SID, _
    BYVAL pSubCategoryGuids AS GUID PTR, _
    BYVAL dwPolicyCount     AS DWORD, _
    ppAuditPolicy           AS ANY _   ' AUDIT_POLICY_INFORMATION PTR PTR
    ) AS BYTE  ' BOOLEAN
#ELSE
DECLARE FUNCTION AuditComputeEffectivePolicyBySid IMPORT "Advapi32.dll" ALIAS "AuditComputeEffectivePolicyBySid" ( _
   BYVAL pSid AS SID PTR _                              ' __in const PSID pSid
 , BYREF pSubCategoryGuids AS GUID _                    ' __in const GUID* pSubCategoryGuids
 , BYVAL PolicyCount AS DWORD _                         ' __in ULONG PolicyCount
 , BYREF ppAuditPolicy AS AUDIT_POLICY_INFORMATION _    ' __out PAUDIT_POLICY_INFORMATION* ppAuditPolicy
 ) AS BYTE                                              ' BOOLEAN
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION AuditComputeEffectivePolicyByToken LIB "AdvApi32.dll" _
    ALIAS "AuditComputeEffectivePolicyByToken" ( _
    BYVAL hTokenHandle      AS DWORD, _   ' HANDLE
    BYVAL pSubCategoryGuids AS GUID PTR, _
    BYVAL dwPolicyCount     AS DWORD, _
    ppAuditPolicy           AS ANY _   ' AUDIT_POLICY_INFORMATION PTR PTR
    ) AS BYTE  ' BOOLEAN
#ELSE
DECLARE FUNCTION AuditComputeEffectivePolicyByToken IMPORT "Advapi32.dll" ALIAS "AuditComputeEffectivePolicyByToken" ( _
   BYVAL hTokenHandle AS DWORD _                        ' __in HANDLE hTokenHandle
 , BYREF pSubCategoryGuids AS GUID _                    ' __in const GUID* pSubCategoryGuids
 , BYVAL PolicyCount AS DWORD _                         ' __in ULONG PolicyCount
 , BYREF ppAuditPolicy AS AUDIT_POLICY_INFORMATION _    ' __out PAUDIT_POLICY_INFORMATION* ppAuditPolicy
 ) AS BYTE                                              ' BOOLEAN
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION AuditEnumerateCategories LIB "AdvApi32.dll" _
    ALIAS "AuditEnumerateCategories" ( _
    ppAuditCategoriesArray AS ANY, _    ' GUID PTR PTR,
    pdwCountReturned       AS DWORD _
    ) AS BYTE  ' BOOLEAN
#ELSE
DECLARE FUNCTION AuditEnumerateCategories IMPORT "Advapi32.dll" ALIAS "AuditEnumerateCategories" ( _
   BYREF ppAuditCategoriesArray AS GUID _               ' __out GUID** ppAuditCategoriesArray
 , BYREF pCountReturned AS DWORD _                      ' __out PULONG pCountReturned
 ) AS BYTE                                              ' BOOLEAN
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION AuditLookupCategoryNameW LIB "AdvApi32.dll" _
    ALIAS "AuditLookupCategoryNameW" ( _
    pAuditCategoryGuid AS GUID, _
    ppszCategoryName   AS ANY _   ' PWSTR*
    ) AS BYTE  ' BOOLEAN
#ELSE
DECLARE FUNCTION AuditLookupCategoryNameW IMPORT "Advapi32.dll" ALIAS "AuditLookupCategoryNameW" ( _
   BYREF pAuditCategoryGuid AS GUID _                   ' __in const GUID* pAuditCategoryGuid
 , BYREF ppszCategoryName AS WSTRINGZ _                 ' __out PWSTR* ppszCategoryName
 ) AS BYTE                                              ' BOOLEAN
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION AuditLookupCategoryNameA LIB "AdvApi32.dll" _
    ALIAS "AuditLookupCategoryNameA" ( _
    pAuditCategoryGuid AS GUID, _
    ppszCategoryName   AS ANY _    ' PSTR*
    ) AS BYTE  ' BOOLEAN
#ELSE
DECLARE FUNCTION AuditLookupCategoryNameA IMPORT "Advapi32.dll" ALIAS "AuditLookupCategoryNameA" ( _
   BYREF pAuditCategoryGuid AS GUID _                   ' __in const GUID* pAuditCategoryGuid
 , BYREF ppszCategoryName AS ASCIIZ _                   ' __out PSTR* ppszCategoryName
 ) AS BYTE                                              ' BOOLEAN
#ENDIF

#IF %DEF(%UNICODE)
   MACRO AuditLookupCategoryName = AuditLookupCategoryNameW
#ELSE
   MACRO AuditLookupCategoryName = AuditLookupCategoryNameA
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION AuditLookupSubCategoryNameW LIB "AdvApi32.dll" _
    ALIAS "AuditLookupSubCategoryNameW" ( _
    pAuditSubCategoryGuid AS GUID, _
    ppszSubCategoryName   AS ANY _    ' PWSTR*
    ) AS BYTE  ' BOOLEAN
#ELSE
DECLARE FUNCTION AuditLookupSubCategoryNameW IMPORT "Advapi32.dll" ALIAS "AuditLookupSubCategoryNameW" ( _
   BYREF pAuditSubCategoryGuid AS GUID _                ' __in const GUID* pAuditSubCategoryGuid
 , BYREF ppszSubCategoryName AS WSTRINGZ _              ' __out PWSTR* ppszSubCategoryName
 ) AS BYTE                                              ' BOOLEAN
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION AuditLookupSubCategoryNameA LIB "AdvApi32.dll" _
    ALIAS "AuditLookupSubCategoryNameA" ( _
    pAuditSubCategoryGuid AS GUID, _
    ppszSubCategoryName   AS ANY _    ' PSTR*
    ) AS BYTE  ' BOOLEAN
#ELSE
DECLARE FUNCTION AuditLookupSubCategoryNameA IMPORT "Advapi32.dll" ALIAS "AuditLookupSubCategoryNameA" ( _
   BYREF pAuditSubCategoryGuid AS GUID _                ' __in const GUID* pAuditSubCategoryGuid
 , BYREF ppszSubCategoryName AS ASCIIZ _                ' __out PSTR* ppszSubCategoryName
 ) AS BYTE                                              ' BOOLEAN
#ENDIF

#IF %DEF(%UNICODE)
   MACRO AuditLookupSubCategoryName = AuditLookupSubCategoryNameW
#ELSE
   MACRO AuditLookupSubCategoryName = AuditLookupSubCategoryNameA
#ENDIF

DECLARE FUNCTION AuditLookupCategoryIdFromCategoryGuid IMPORT "Advapi32.dll" ALIAS "AuditLookupCategoryIdFromCategoryGuid" ( _
   BYREF pAuditCategoryGuid AS GUID _                   ' __in const GUID* pAuditCategoryGuid
 , BYREF pAuditCategoryId AS LONG _                     ' __out PPOLICY_AUDIT_EVENT_TYPE pAuditCategoryId
 ) AS BYTE                                              ' BOOLEAN

DECLARE FUNCTION AuditLookupCategoryGuidFromCategoryId IMPORT "Advapi32.dll" ALIAS "AuditLookupCategoryGuidFromCategoryId" ( _
   BYVAL AuditCategoryId AS LONG _                      ' __in POLICY_AUDIT_EVENT_TYPE AuditCategoryId
 , BYREF pAuditCategoryGuid AS GUID _                   ' __out GUID* pAuditCategoryGuid
 ) AS BYTE                                              ' BOOLEAN

DECLARE FUNCTION AuditSetSecurity IMPORT "Advapi32.dll" ALIAS "AuditSetSecurity" ( _
   BYVAL SecurityInformation AS SECURITY_INFORMATION _  ' __in SECURITY_INFORMATION SecurityInformation
 , BYREF pSecurityDescriptor AS SECURITY_DESCRIPTOR _   ' __in PSECURITY_DESCRIPTOR pSecurityDescriptor
 ) AS BYTE                                              ' BOOLEAN

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION AuditQuerySecurity LIB "AdvApi32.dll" _
    ALIAS "AuditQuerySecurity" ( _
    BYVAL SecurityInformation AS SECURITY_INFORMATION, _
    ppSecurityDescriptor      AS ANY  _  ' SECURITY_DESCRIPTOR PTR PTR
    ) AS BYTE  ' BOOLEAN
#ELSE
DECLARE FUNCTION AuditQuerySecurity IMPORT "Advapi32.dll" ALIAS "AuditQuerySecurity" ( _
   BYVAL SecurityInformation AS SECURITY_INFORMATION _  ' __in SECURITY_INFORMATION SecurityInformation
 , BYREF ppSecurityDescriptor AS SECURITY_DESCRIPTOR _  ' __out PSECURITY_DESCRIPTOR *ppSecurityDescriptor
 ) AS BYTE                                              ' BOOLEAN
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION AuditSetGlobalSaclW LIB "AdvApi32.dll" _
    ALIAS "AuditSetGlobalSaclW" ( _
    ObjectTypeName AS WSTRINGZ, _
    pAcl           AS ACL _
    ) AS BYTE  ' BOOLEAN
#ELSE
DECLARE FUNCTION AuditSetGlobalSaclW IMPORT "Advapi32.dll" ALIAS "AuditSetGlobalSaclW" ( _
   BYREF ObjectTypeName AS WSTRINGZ _                   ' __in PCWSTR ObjectTypeName
 , BYVAL Acl AS ACL PTR _                               ' __in_opt PACL Acl
 ) AS BYTE                                              ' BOOLEAN
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION AuditSetGlobalSaclA LIB "AdvApi32.dll" _
    ALIAS "AuditSetGlobalSaclA" ( _
    ObjectTypeName AS ASCIIZ, _
    pAcl           AS ACL _
    ) AS BYTE  ' BOOLEAN
#ELSE
DECLARE FUNCTION AuditSetGlobalSaclA IMPORT "Advapi32.dll" ALIAS "AuditSetGlobalSaclA" ( _
   BYREF ObjectTypeName AS ASCIIZ _                     ' __in PCSTR ObjectTypeName
 , BYVAL Acl AS ACL PTR _                               ' __in_opt PACL Acl
 ) AS BYTE                                              ' BOOLEAN
#ENDIF

#IF %DEF(%UNICODE)
   MACRO AuditSetGlobalSacl = AuditSetGlobalSaclW
#ELSE
   MACRO AuditSetGlobalSacl = AuditSetGlobalSaclA
#ENDIF

DECLARE FUNCTION AuditQueryGlobalSaclW IMPORT "Advapi32.dll" ALIAS "AuditQueryGlobalSaclW" ( _
   BYREF ObjectTypeName AS WSTRINGZ _                   ' __in PCWSTR ObjectTypeName
 , BYREF Acl AS ANY _                                   ' __out PACL *Acl
 ) AS BYTE                                              ' BOOLEAN

DECLARE FUNCTION AuditQueryGlobalSaclA IMPORT "Advapi32.dll" ALIAS "AuditQueryGlobalSaclA" ( _
   BYREF ObjectTypeName AS ASCIIZ _                     ' __in PCSTR ObjectTypeName
 , BYREF Acl AS ANY _                                   ' __out PACL *Acl
 ) AS BYTE                                              ' BOOLEAN

#IF %DEF(%UNICODE)
   MACRO AuditQueryGlobalSacl = AuditQueryGlobalSaclW
#ELSE
   MACRO AuditQueryGlobalSacl = AuditQueryGlobalSaclA
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE SUB AuditFree LIB "AdvApi32.dll" ALIAS "AuditFree" (Buffer AS ANY)
#ELSE
DECLARE SUB AuditFree IMPORT "Advapi32.dll" ALIAS "AuditFree" ( _
   BYVAL Buffer AS DWORD _                              ' __in PVOID Buffer
 )                                                      ' void
#ENDIF

'#if (_WIN32_WINNT >= 0x0601)

'//
'// Pku2u package name
'//

$PKU2U_PACKAGE_NAME_A          = "pku2u"
$$PKU2U_PACKAGE_NAME_W          = "pku2u"$$

#IF %DEF(%UNICODE)
   MACRO PKU2U_PACKAGE_NAME = $$PKU2U_PACKAGE_NAME_W
#ELSE
   MACRO PKU2U_PACKAGE_NAME = $PKU2U_PACKAGE_NAME_A
#ENDIF


'#endif // _WIN32_WINNT


'#if (_WIN32_WINNT >= 0x0601)

'// the following structure contains the ASN.1 encoded X.509 certificate
' // Size = 8 bytes
TYPE PKU2U_CERT_BLOB DWORD
   CertOffset AS DWORD   ' ULONG // each element is a byte
   CertLength AS WORD   ' USHORT
END TYPE

'#define PKU2U_CREDUI_CONTEXT_VERSION  0x4154414454524543i64  // "CERTDATA"
%PKU2U_CREDUI_CONTEXT_VERSION = &H4154414454524543&&   ' // "CERTDATA"

' // Size = 24 bytes
TYPE PKU2U_CREDUI_CONTEXT   ' Must be 8 byte aligned
   Version           AS QUAD    ' ULONG64
   cbHeaderLength    AS WORD    ' USHORT
   cbStructureLength AS DWORD   ' ULONG
   CertArrayCount    AS WORD    ' USHORT // followed by an array of PKU2U_CERT_BLOB
   CertArrayOffset   AS DWORD   ' ULONG // offset to the array
   filler            AS DWORD   ' // To keep QWORD alignment
END TYPE

'/////////////////////////////////////////////////////////////////////////
'//
'// LsaLogonUser parameters
'//
'/////////////////////////////////////////////////////////////////////////

' enum PKU2U_LOGON_SUBMIT_TYPE
%Pku2uCertificateS4ULogon = 14

' // Size = 32 bytes
TYPE PKU2U_CERTIFICATE_S4U_LOGON DWORD
   MessageType       AS LONG                 ' PKU2U_LOGON_SUBMIT_TYPE
   Flags             AS DWORD                ' ULONG
   UserPrincipalName AS UNICODE_STRING
   DomainName        AS UNICODE_STRING
   CertificateLength AS DWORD                ' ULONG // for the client certificate
   Certificate       AS BYTE PTR             ' PUCHAR // for the client certificate, BER encoded
END TYPE

'#endif // _WIN32_WINNT
