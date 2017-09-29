' ########################################################################################
' Microsoft Windows
' File: Sddl.inc
' Contents: This module defines the support and conversions routines necessary for SDDL
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%SDDL_INC = 1

#INCLUDE ONCE "windows.inc"

'//
'// SDDL Version information
'//
%SDDL_REVISION_1    = 1
%SDDL_REVISION      = %SDDL_REVISION_1

'//
'// SDDL Component tags
'//
$$SDDL_OWNER                          = "O"$$      ' // Owner tag
$$SDDL_GROUP                          = "G"$$      ' // Group tag
$$SDDL_DACL                           = "D"$$      ' // DACL tag
$$SDDL_SACL                           = "S"$$      ' // SACL tag

'//
'// SDDL Security descriptor controls
'//
$$SDDL_PROTECTED                      = "P"$$      ' // DACL or SACL Protected
$$SDDL_AUTO_INHERIT_REQ               = "AR"$$     ' // Auto inherit request
$$SDDL_AUTO_INHERITED                 = "AI"$$     ' // DACL/SACL are auto inherited
$$SDDL_NULL_ACL                       = "NO_ACCESS_CONTROL"$$   ' // Null ACL

'//
'// SDDL Ace types
'//
$$SDDL_ACCESS_ALLOWED                 = "A"$$    ' // Access allowed
$$SDDL_ACCESS_DENIED                  = "D"$$    ' // Access denied
$$SDDL_OBJECT_ACCESS_ALLOWED          = "OA"$$   ' // Object access allowed
$$SDDL_OBJECT_ACCESS_DENIED           = "OD"$$   ' // Object access denied
$$SDDL_AUDIT                          = "AU"$$   ' // Audit
$$SDDL_ALARM                          = "AL"$$   ' // Alarm
$$SDDL_OBJECT_AUDIT                   = "OU"$$   ' // Object audit
$$SDDL_OBJECT_ALARM                   = "OL"$$   ' // Object alarm
$$SDDL_MANDATORY_LABEL                = "ML"$$   ' // Integrity label
$$SDDL_CALLBACK_ACCESS_ALLOWED        = "XA"$$   ' // callback Access allowed
$$SDDL_CALLBACK_ACCESS_DENIED         = "XD"$$   ' // callback Access denied

'//
'// SDDL Ace flags
'//
$$SDDL_CONTAINER_INHERIT              = "CI"$$   ' // Container inherit
$$SDDL_OBJECT_INHERIT                 = "OI"$$   ' // Object inherit
$$SDDL_NO_PROPAGATE                   = "NP"$$   ' // Inherit no propagate
$$SDDL_INHERIT_ONLY                   = "IO"$$   ' // Inherit only
$$SDDL_INHERITED                      = "ID"$$   ' // Inherited
$$SDDL_AUDIT_SUCCESS                  = "SA"$$   ' // Audit success
$$SDDL_AUDIT_FAILURE                  = "FA"$$   ' // Audit failure


'//
'// SDDL Rights
'//
'#define SDDL_READ_PROPERTY                  TEXT("RP")
'#define SDDL_WRITE_PROPERTY                 TEXT("WP")
'#define SDDL_CREATE_CHILD                   TEXT("CC")
'#define SDDL_DELETE_CHILD                   TEXT("DC")
'#define SDDL_LIST_CHILDREN                  TEXT("LC")
'#define SDDL_SELF_WRITE                     TEXT("SW")
'#define SDDL_LIST_OBJECT                    TEXT("LO")
'#define SDDL_DELETE_TREE                    TEXT("DT")
'#define SDDL_CONTROL_ACCESS                 TEXT("CR")
'#define SDDL_READ_CONTROL                   TEXT("RC")
'#define SDDL_WRITE_DAC                      TEXT("WD")
'#define SDDL_WRITE_OWNER                    TEXT("WO")
'#define SDDL_STANDARD_DELETE                TEXT("SD")
'#define SDDL_GENERIC_ALL                    TEXT("GA")
'#define SDDL_GENERIC_READ                   TEXT("GR")
'#define SDDL_GENERIC_WRITE                  TEXT("GW")
'#define SDDL_GENERIC_EXECUTE                TEXT("GX")
'#define SDDL_FILE_ALL                       TEXT("FA")
'#define SDDL_FILE_READ                      TEXT("FR")
'#define SDDL_FILE_WRITE                     TEXT("FW")
'#define SDDL_FILE_EXECUTE                   TEXT("FX")
'#define SDDL_KEY_ALL                        TEXT("KA")
'#define SDDL_KEY_READ                       TEXT("KR")
'#define SDDL_KEY_WRITE                      TEXT("KW")
'#define SDDL_KEY_EXECUTE                    TEXT("KX")
'#define SDDL_NO_WRITE_UP                    TEXT("NW")
'#define SDDL_NO_READ_UP                     TEXT("NR")
'#define SDDL_NO_EXECUTE_UP                  TEXT("NX")

$$SDDL_READ_PROPERTY                  = "RP"$$
$$SDDL_WRITE_PROPERTY                 = "WP"$$
$$SDDL_CREATE_CHILD                   = "CC"$$
$$SDDL_DELETE_CHILD                   = "DC"$$
$$SDDL_LIST_CHILDREN                  = "LC"$$
$$SDDL_SELF_WRITE                     = "SW"$$
$$SDDL_LIST_OBJECT                    = "LO"$$
$$SDDL_DELETE_TREE                    = "DT"$$
$$SDDL_CONTROL_ACCESS                 = "CR"$$
$$SDDL_READ_CONTROL                   = "RC"$$
$$SDDL_WRITE_DAC                      = "WD"$$
$$SDDL_WRITE_OWNER                    = "WO"$$
$$SDDL_STANDARD_DELETE                = "SD"$$
$$SDDL_GENERIC_ALL                    = "GA"$$
$$SDDL_GENERIC_READ                   = "GR"$$
$$SDDL_GENERIC_WRITE                  = "GW"$$
$$SDDL_GENERIC_EXECUTE                = "GX"$$
$$SDDL_FILE_ALL                       = "FA"$$
$$SDDL_FILE_READ                      = "FR"$$
$$SDDL_FILE_WRITE                     = "FW"$$
$$SDDL_FILE_EXECUTE                   = "FX"$$
$$SDDL_KEY_ALL                        = "KA"$$
$$SDDL_KEY_READ                       = "KR"$$
$$SDDL_KEY_WRITE                      = "KW"$$
$$SDDL_KEY_EXECUTE                    = "KX"$$
$$SDDL_NO_WRITE_UP                    = "NW"$$
$$SDDL_NO_READ_UP                     = "NR"$$
$$SDDL_NO_EXECUTE_UP                  = "NX"$$

'//
'// SDDL User alias max size
'//      - currently, upto two supported eg. "DA"
'//      - modify this if more WCHARs need to be there in future e.g. "DAX"
'//

%SDDL_ALIAS_SIZE                    = 2

'//
'// SDDL User aliases
'//
$$SDDL_DOMAIN_ADMINISTRATORS          = "DA"$$      ' // Domain admins
$$SDDL_DOMAIN_GUESTS                  = "DG"$$      ' // Domain guests
$$SDDL_DOMAIN_USERS                   = "DU"$$      ' // Domain users
$$SDDL_ENTERPRISE_DOMAIN_CONTROLLERS  = "ED"$$      ' // Enterprise domain controllers
$$SDDL_DOMAIN_DOMAIN_CONTROLLERS      = "DD"$$      ' // Domain domain controllers
$$SDDL_DOMAIN_COMPUTERS               = "DC"$$      ' // Domain computers
$$SDDL_BUILTIN_ADMINISTRATORS         = "BA"$$      ' // Builtin (local  administrators
$$SDDL_BUILTIN_GUESTS                 = "BG"$$      ' // Builtin (local  guests
$$SDDL_BUILTIN_USERS                  = "BU"$$      ' // Builtin (local  users
$$SDDL_LOCAL_ADMIN                    = "LA"$$      ' // Local administrator account
$$SDDL_LOCAL_GUEST                    = "LG"$$      ' // Local group account
$$SDDL_ACCOUNT_OPERATORS              = "AO"$$      ' // Account operators
$$SDDL_BACKUP_OPERATORS               = "BO"$$      ' // Backup operators
$$SDDL_PRINTER_OPERATORS              = "PO"$$      ' // Printer operators
$$SDDL_SERVER_OPERATORS               = "SO"$$      ' // Server operators
$$SDDL_AUTHENTICATED_USERS            = "AU"$$      ' // Authenticated users
$$SDDL_PERSONAL_SELF                  = "PS"$$      ' // Personal self
$$SDDL_CREATOR_OWNER                  = "CO"$$      ' // Creator owner
$$SDDL_CREATOR_GROUP                  = "CG"$$      ' // Creator group
$$SDDL_LOCAL_SYSTEM                   = "SY"$$      ' // Local system
$$SDDL_POWER_USERS                    = "PU"$$      ' // Power users
$$SDDL_EVERYONE                       = "WD"$$      ' // Everyone ( World
$$SDDL_REPLICATOR                     = "RE"$$      ' // Replicator
$$SDDL_INTERACTIVE                    = "IU"$$      ' // Interactive logon user
$$SDDL_NETWORK                        = "NU"$$      ' // Nework logon user
$$SDDL_SERVICE                        = "SU"$$      ' // Service logon user
$$SDDL_RESTRICTED_CODE                = "RC"$$      ' // Restricted code
$$SDDL_ANONYMOUS                      = "AN"$$      ' // Anonymous Logon
$$SDDL_SCHEMA_ADMINISTRATORS          = "SA"$$      ' // Schema Administrators
$$SDDL_CERT_SERV_ADMINISTRATORS       = "CA"$$      ' // Certificate Server Administrators
$$SDDL_RAS_SERVERS                    = "RS"$$      ' // RAS servers group
$$SDDL_ENTERPRISE_ADMINS              = "EA"$$      ' // Enterprise administrators
$$SDDL_GROUP_POLICY_ADMINS            = "PA"$$      ' // Group Policy administrators
$$SDDL_ALIAS_PREW2KCOMPACC            = "RU"$$      ' // alias to allow previous windows 2000
$$SDDL_LOCAL_SERVICE                  = "LS"$$      ' // Local service account (for services
$$SDDL_NETWORK_SERVICE                = "NS"$$      ' // Network service account (for services
$$SDDL_REMOTE_DESKTOP                 = "RD"$$      ' // Remote desktop users (for terminal server
$$SDDL_NETWORK_CONFIGURATION_OPS      = "NO"$$      ' // Network configuration operators ( to manage configuration of networking features
$$SDDL_PERFMON_USERS                  = "MU"$$      ' // Performance Monitor Users
$$SDDL_PERFLOG_USERS                  = "LU"$$      ' // Performance Log Users
$$SDDL_IIS_USERS                      = "IS"$$      ' // Anonymous Internet Users
$$SDDL_CRYPTO_OPERATORS               = "CY"$$      ' // Crypto Operators
$$SDDL_OWNER_RIGHTS                   = "OW"$$      ' // Owner Rights SID
$$SDDL_EVENT_LOG_READERS              = "ER"$$      ' // Event log readers
$$SDDL_ENTERPRISE_RO_DCs              = "RO"$$      ' // Enterprise Read-only domain controllers
$$SDDL_CERTSVC_DCOM_ACCESS            = "CD"$$      ' // Users who can connect to certification authorities using DCOM

'//
'// Integrity Labels
'//
$$SDDL_ML_LOW                         = "LW"$$      ' // Low mandatory level
$$SDDL_ML_MEDIUM                      = "ME"$$      ' // Medium mandatory level
$$SDDL_ML_HIGH                        = "HI"$$      ' // High mandatory level
$$SDDL_ML_SYSTEM                      = "SI"$$      ' // System mandatory level

'//
'// SDDL Seperators - character version
'//
$$SDDL_SEPERATORC                         = CHR$$(";"$$)
$$SDDL_DELIMINATORC                       = CHR$$(":"$$)
$$SDDL_ACE_BEGINC                         = CHR$$("("$$)
$$SDDL_ACE_ENDC                           = CHR$$(")"$$)
$$SDDL_SPACEC                             = CHR$$(" "$$)
$$SDDL_ACE_COND_BEGINC                    = CHR$$("("$$)
$$SDDL_ACE_COND_ENDC                      = CHR$$(")"$$)
$$SDDL_ACE_COND_STRING_BEGINC             = CHR$$(""""$$)
$$SDDL_ACE_COND_STRING_ENDC               = CHR$$(""""$$)
$$SDDL_ACE_COND_COMPOSITEVALUE_BEGINC     = CHR$$("{"$$)
$$SDDL_ACE_COND_COMPOSITEVALUE_ENDC       = CHR$$("}"$$)
$$SDDL_ACE_COND_COMPOSITEVALUE_SEPERATORC = CHR$$(","$$)
$$SDDL_ACE_COND_BLOB_PREFIXC              = CHR$$("#"$$)
$$SDDL_ACE_COND_SID_BEGINC                = CHR$$("("$$)
$$SDDL_ACE_COND_SID_ENDC                  = CHR$$(")"$$)

'//
'// SDDL Seperators - string version
'//
$$SDDL_SEPERATOR                     = ";"$$
$$SDDL_DELIMINATOR                   = ":"$$
$$SDDL_ACE_BEGIN                     = "("$$
$$SDDL_ACE_END                       = ")"$$
$$SDDL_ACE_COND_BEGIN                = "("$$
$$SDDL_ACE_COND_END                  = ")"$$
$$SDDL_SPACE                         = " "$$
$$SDDL_ACE_COND_BLOB_PREFIX          = "#"$$
$$SDDL_ACE_COND_SID_PREFIX           = "SID"$$

'#if !defined(_NTDDK_)

'#if(_WIN32_WINNT >= 0x0500)

DECLARE FUNCTION ConvertSidToStringSidA IMPORT "ADVAPI32.DLL" ALIAS "ConvertSidToStringSidA" ( _
   BYVAL Sid AS SID PTR _                               ' __in  PSID    Sid
 , BYREF StringSid AS DWORD _                           ' __out LPSTR  *StringSid
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION ConvertSidToStringSidW IMPORT "ADVAPI32.DLL" ALIAS "ConvertSidToStringSidW" ( _
   BYVAL Sid AS SID PTR _                               ' __in  PSID     Sid
 , BYREF StringSid AS DWORD _                           ' __out LPWSTR  *StringSid
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO ConvertSidToStringSid = ConvertSidToStringSidW
#ELSE
   MACRO ConvertSidToStringSid = ConvertSidToStringSidA
#ENDIF

DECLARE FUNCTION ConvertStringSidToSidA IMPORT "ADVAPI32.DLL" ALIAS "ConvertStringSidToSidA" ( _
   BYREF StringSid AS ASCIIZ _                          ' __in  LPCSTR   StringSid
 , BYREF Sid AS ANY _                                   ' __out PSID    *Sid
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION ConvertStringSidToSidW IMPORT "ADVAPI32.DLL" ALIAS "ConvertStringSidToSidW" ( _
   BYREF StringSid AS WSTRINGZ _                        ' __in  LPCWSTR  StringSid
 , BYREF Sid AS ANY _                                   ' __out PSID    *Sid
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO ConvertStringSidToSid = ConvertStringSidToSidW
#ELSE
   MACRO ConvertStringSidToSid = ConvertStringSidToSidA
#ENDIF

DECLARE FUNCTION ConvertStringSecurityDescriptorToSecurityDescriptorA _
   IMPORT "ADVAPI32.DLL" ALIAS "ConvertStringSecurityDescriptorToSecurityDescriptorA" ( _
   BYREF StringSecurityDescriptor AS ASCIIZ _           ' __in LPCSTR StringSecurityDescriptor
 , BYVAL StringSDRevision AS DWORD _                    ' __in DWORD StringSDRevision
 , BYREF SecurityDescriptor AS SECURITY_DESCRIPTOR _    ' __out PSECURITY_DESCRIPTOR  *SecurityDescriptor
 , BYREF SecurityDescriptorSize AS DWORD _              ' __out PULONG  SecurityDescriptorSize OPTIONAL
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION ConvertStringSecurityDescriptorToSecurityDescriptorW _
   IMPORT "ADVAPI32.DLL" ALIAS "ConvertStringSecurityDescriptorToSecurityDescriptorW" ( _
   BYREF StringSecurityDescriptor AS WSTRINGZ _         ' __in LPCWSTR StringSecurityDescriptor
 , BYVAL StringSDRevision AS DWORD _                    ' __in DWORD StringSDRevision
 , BYREF SecurityDescriptor AS SECURITY_DESCRIPTOR _    ' __out PSECURITY_DESCRIPTOR  *SecurityDescriptor
 , BYREF SecurityDescriptorSize AS DWORD _              ' __out PULONG  SecurityDescriptorSize OPTIONAL
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO ConvertStringSecurityDescriptorToSecurityDescriptor = ConvertStringSecurityDescriptorToSecurityDescriptorW
#ELSE
   MACRO ConvertStringSecurityDescriptorToSecurityDescriptor = ConvertStringSecurityDescriptorToSecurityDescriptorA
#ENDIF

DECLARE FUNCTION ConvertSecurityDescriptorToStringSecurityDescriptorA _
   IMPORT "ADVAPI32.DLL" ALIAS "ConvertSecurityDescriptorToStringSecurityDescriptorA" ( _
   BYREF SecurityDescriptor AS SECURITY_DESCRIPTOR _    ' __in PSECURITY_DESCRIPTOR  SecurityDescriptor
 , BYVAL RequestedStringSDRevision AS DWORD _           ' __in DWORD RequestedStringSDRevision
 , BYVAL SecurityInformation AS SECURITY_INFORMATION _  ' __in SECURITY_INFORMATION SecurityInformation
 , BYREF StringSecurityDescriptor AS DWORD _            ' __out LPSTR  *StringSecurityDescriptor OPTIONAL
 , BYREF StringSecurityDescriptorLen AS DWORD _         ' __out PULONG StringSecurityDescriptorLen OPTIONAL
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION ConvertSecurityDescriptorToStringSecurityDescriptorW _
   IMPORT "ADVAPI32.DLL" ALIAS "ConvertSecurityDescriptorToStringSecurityDescriptorW" ( _
   BYREF SecurityDescriptor AS SECURITY_DESCRIPTOR _    ' __in PSECURITY_DESCRIPTOR  SecurityDescriptor
 , BYVAL RequestedStringSDRevision AS DWORD _           ' __in DWORD RequestedStringSDRevision
 , BYVAL SecurityInformation AS SECURITY_INFORMATION _  ' __in SECURITY_INFORMATION SecurityInformation
 , BYREF StringSecurityDescriptor AS DWORD _            ' __out LPWSTR  *StringSecurityDescriptor OPTIONAL
 , BYREF StringSecurityDescriptorLen AS DWORD _         ' __out PULONG StringSecurityDescriptorLen OPTIONAL
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO ConvertSecurityDescriptorToStringSecurityDescriptor = ConvertSecurityDescriptorToStringSecurityDescriptorW
#ELSE
   MACRO ConvertSecurityDescriptorToStringSecurityDescriptor = ConvertSecurityDescriptorToStringSecurityDescriptorA
#ENDIF

'#endif /* _WIN32_WINNT >=  0x0500 */

'#endif /* !defined(_NTDDK_) */
