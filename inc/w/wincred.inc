' ########################################################################################
' Microsoft Windows
' File: WinCred.inc
' Contents: Public data structures and API definitions needed for the Credential Manager.
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%WINCRED_INC = 1

#INCLUDE ONCE "windows.inc"
#INCLUDE ONCE "lmerr.inc"
#INCLUDE ONCE "ntstatus.inc"

'//
'// Ensure PCtxtHandle is defined
'//

#IF NOT %DEF(%SECHANDLE_DEFINED)
%SECHANDLE_DEFINED = 1
' // Size = 8 bytes
TYPE SecHandle DWORD
   dwLower AS DWORD   ' ULONG_PTR
   dwUpper AS DWORD   ' ULONG_PTR
END TYPE
#ENDIF

'typedef PSecHandle PCtxtHandle;


'//
'// Ensure FILETIME is defined
'//

'#ifndef _WINBASE_
'#ifndef _FILETIME_
'#define _FILETIME_
'typedef struct _FILETIME
'    {
'    DWORD dwLowDateTime;
'    DWORD dwHighDateTime;
'    }   FILETIME;
'typedef struct _FILETIME *PFILETIME;
'typedef struct _FILETIME *LPFILETIME;
'#endif // !_FILETIME
'#endif // _WINBASE_

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

'//
'// Ensure NTSTATUS is defined
'//
'#ifndef _NTDEF_
'typedef LONG NTSTATUS, *PNTSTATUS;
'#endif


'//-----------------------------------------------------------------------------
'// Macros
'//-----------------------------------------------------------------------------

'//
'// Macro to determine whether CredUIPromptForCredentials should be called upon a failed
'//      authentication attempt.
'//
'// Implemented as a macro so that the caller can delay load credui.dll only if this
'//      macro returns TRUE.
'//
'// Include only status codes that imply the username/password are wrong or that the
'//      password is expired.  In the former case, asking for a another username or password
'//      is appropriate.  In the later case, we put up a different dialog asking the
'//      user to change the password on the server.
'//
'// Don't include status codes such as ERROR_ACCOUNT_DISABLED, ERROR_ACCOUNT_RESTRICTION,
'//      ERROR_ACCOUNT_LOCKED_OUT, ERROR_ACCOUNT_EXPIRED, ERROR_LOGON_TYPE_NOT_GRANTED.
'//      For those, the user isn't going to have another account so prompting him
'//      won't help.
'//
'// STATUS_DOWNGRADE_DETECTED is included to handle the case where a corporate laptop
'//      is brought to another LAN.  A downgrade attack will indeed be detected,
'//      but we want to popup UI to allow the user to connect to resources in the
'//      other LAN.
'//
'// Don't use the CREDUIP_* macros directly.  Their definition is private to credui.dll.
'//

'// Don't require ntstatus.h
%STATUS_LOGON_FAILURE                  = &HC000006D&   ' // ntsubauth
%STATUS_WRONG_PASSWORD                 = &HC000006A&   ' // ntsubauth
%STATUS_PASSWORD_EXPIRED               = &HC0000071&   ' // ntsubauth
%STATUS_PASSWORD_MUST_CHANGE           = &HC0000224&   ' // ntsubauth
%STATUS_ACCESS_DENIED                  = &HC0000022&
%STATUS_DOWNGRADE_DETECTED             = &HC0000388&
%STATUS_AUTHENTICATION_FIREWALL_FAILED = &HC0000413&
%STATUS_ACCOUNT_DISABLED               = &HC0000072&   ' // ntsubauth
%STATUS_ACCOUNT_RESTRICTION            = &HC000006E&   ' // ntsubauth
%STATUS_ACCOUNT_LOCKED_OUT             = &HC0000234&   ' // ntsubauth
%STATUS_ACCOUNT_EXPIRED                = &HC0000193&   ' // ntsubauth
%STATUS_LOGON_TYPE_NOT_GRANTED         = &HC000015B&

FUNCTION CREDUIP_IS_USER_PASSWORD_ERROR(BYVAL nStatus AS LONG) AS LONG
   IF nStatus = %ERROR_LOGON_FAILURE OR _
      nStatus = HRESULT_FROM_WIN32(%ERROR_LOGON_FAILURE) OR _
      nStatus = %STATUS_LOGON_FAILURE OR _
      nStatus = HRESULT_FROM_NT(%STATUS_LOGON_FAILURE) OR _
      nStatus = %ERROR_ACCESS_DENIED OR _
      nStatus = HRESULT_FROM_WIN32(%ERROR_ACCESS_DENIED) OR _
      nStatus = %STATUS_ACCESS_DENIED OR _
      nStatus = HRESULT_FROM_NT(%STATUS_ACCESS_DENIED) OR _
      nStatus = %ERROR_INVALID_PASSWORD OR _
      nStatus = HRESULT_FROM_WIN32(%ERROR_INVALID_PASSWORD) OR _
      nStatus = %STATUS_WRONG_PASSWORD OR _
      nStatus = HRESULT_FROM_NT(%STATUS_WRONG_PASSWORD) OR _
      nStatus = %SEC_E_NO_CREDENTIALS OR _
      nStatus = %SEC_E_LOGON_DENIED OR _
      nStatus = %SEC_E_NO_CONTEXT OR _
      nStatus = %STATUS_NO_SECURITY_CONTEXT THEN
      FUNCTION = %TRUE
   END IF
END FUNCTION

FUNCTION CREDUIP_IS_DOWNGRADE_ERROR(BYVAL nStatus AS LONG) AS LONG
   IF nStatus = %ERROR_DOWNGRADE_DETECTED OR _
      nStatus = HRESULT_FROM_WIN32(%ERROR_DOWNGRADE_DETECTED) OR _
      nStatus = %STATUS_DOWNGRADE_DETECTED OR _
      nStatus = HRESULT_FROM_NT(%STATUS_DOWNGRADE_DETECTED) THEN
      FUNCTION = %TRUE
   END IF
END FUNCTION

FUNCTION CREDUIP_IS_EXPIRED_ERROR(BYVAL nStatus AS LONG) AS LONG
   IF nStatus = %ERROR_PASSWORD_EXPIRED OR _
      nStatus = HRESULT_FROM_WIN32(%ERROR_PASSWORD_EXPIRED) OR _
      nStatus = %STATUS_PASSWORD_EXPIRED OR _
      nStatus = HRESULT_FROM_NT(%STATUS_PASSWORD_EXPIRED) OR _
      nStatus = %ERROR_PASSWORD_MUST_CHANGE OR _
      nStatus = HRESULT_FROM_WIN32(%ERROR_PASSWORD_MUST_CHANGE) OR _
      nStatus = %STATUS_PASSWORD_MUST_CHANGE OR _
      nStatus = HRESULT_FROM_NT(%STATUS_PASSWORD_MUST_CHANGE) OR _
      nStatus = %NERR_PasswordExpired OR _
      nStatus = HRESULT_FROM_WIN32(%NERR_PasswordExpired) THEN
      FUNCTION = %TRUE
   END IF
END FUNCTION

FUNCTION CREDUI_IS_AUTHENTICATION_ERROR(BYVAL nStatus AS LONG)  AS LONG
   IF CREDUIP_IS_USER_PASSWORD_ERROR(nStatus) OR _
      CREDUIP_IS_DOWNGRADE_ERROR(nStatus) OR _
      CREDUIP_IS_EXPIRED_ERROR(nStatus) THEN
      FUNCTION = %TRUE
   END IF
END FUNCTION

FUNCTION CREDUI_NO_PROMPT_AUTHENTICATION_ERROR(BYVAL nStatus AS LONG) AS LONG
   IF nStatus = %ERROR_AUTHENTICATION_FIREWALL_FAILED OR _
      nStatus = HRESULT_FROM_WIN32(%ERROR_AUTHENTICATION_FIREWALL_FAILED) OR _
      nStatus = %STATUS_AUTHENTICATION_FIREWALL_FAILED OR _
      nStatus = HRESULT_FROM_NT(%STATUS_AUTHENTICATION_FIREWALL_FAILED) OR _
      nStatus = %ERROR_ACCOUNT_DISABLED OR _
      nStatus = HRESULT_FROM_WIN32(%ERROR_ACCOUNT_DISABLED) OR _
      nStatus = %STATUS_ACCOUNT_DISABLED OR _
      nStatus = HRESULT_FROM_NT(%STATUS_ACCOUNT_DISABLED) OR _
      nStatus = %ERROR_ACCOUNT_RESTRICTION OR _
      nStatus = HRESULT_FROM_WIN32(%ERROR_ACCOUNT_RESTRICTION) OR _
      nStatus = %STATUS_ACCOUNT_RESTRICTION OR _
      nStatus = HRESULT_FROM_NT(%STATUS_ACCOUNT_RESTRICTION) OR _
      nStatus = %ERROR_ACCOUNT_LOCKED_OUT OR _
      nStatus = HRESULT_FROM_WIN32(%ERROR_ACCOUNT_LOCKED_OUT) OR _
      nStatus = %STATUS_ACCOUNT_LOCKED_OUT OR _
      nStatus = HRESULT_FROM_NT(%STATUS_ACCOUNT_LOCKED_OUT) OR _
      nStatus = %ERROR_ACCOUNT_EXPIRED OR _
      nStatus = HRESULT_FROM_WIN32(%ERROR_ACCOUNT_EXPIRED) OR _
      nStatus = %STATUS_ACCOUNT_EXPIRED OR _
      nStatus = HRESULT_FROM_NT(%STATUS_ACCOUNT_EXPIRED) OR _
      nStatus = %ERROR_LOGON_TYPE_NOT_GRANTED OR _
      nStatus = HRESULT_FROM_WIN32(%ERROR_LOGON_TYPE_NOT_GRANTED) OR _
      nStatus = %STATUS_LOGON_TYPE_NOT_GRANTED OR _
      nStatus = HRESULT_FROM_NT(%STATUS_LOGON_TYPE_NOT_GRANTED) THEN
      FUNCTION = %TRUE
   END IF
END FUNCTION

'//-----------------------------------------------------------------------------
'// Structures
'//-----------------------------------------------------------------------------

'//
'// Credential Attribute
'//

'// Maximum length of the various credential string fields (in characters)
%CRED_MAX_STRING_LENGTH = 256

'// Maximum length of the UserName field.  The worst case is <User>@<DnsDomain>
%CRED_MAX_USERNAME_LENGTH = (256+1+256)

'// Maximum length of the TargetName field for CRED_TYPE_GENERIC (in characters)
%CRED_MAX_GENERIC_TARGET_NAME_LENGTH = 32767

'// Maximum length of the TargetName field for CRED_TYPE_DOMAIN_* (in characters)
'//      Largest one is <DfsRoot>\<DfsShare>
%CRED_MAX_DOMAIN_TARGET_NAME_LENGTH = (256+1+80)

'// Maximum size of the Credential Attribute Value field (in bytes)
%CRED_MAX_VALUE_SIZE = 256

'// Maximum number of attributes per credential
%CRED_MAX_ATTRIBUTES = 64

' // Size = 16 bytes
TYPE CREDENTIAL_ATTRIBUTEA DWORD
   Keyword   AS ASCIIZ PTR   ' LPSTR
   Flags     AS DWORD        ' DWORD
   ValueSize AS DWORD        ' DWORD
   Value     AS BYTE PTR     ' LPBYTE
END TYPE

' // Size = 16 bytes
TYPE CREDENTIAL_ATTRIBUTEW DWORD
   Keyword   AS WSTRINGZ PTR   ' LPWSTR
   Flags     AS DWORD          ' DWORD
   ValueSize AS DWORD          ' DWORD
   Value     AS BYTE PTR       ' LPBYTE
END TYPE

#IF %DEF(%UNICODE)
   MACRO CREDENTIAL_ATTRIBUTE = CREDENTIAL_ATTRIBUTEW
#ELSE
   MACRO CREDENTIAL_ATTRIBUTE = CREDENTIAL_ATTRIBUTEA
#ENDIF

'//
'// Special values of the TargetName field
'//
'#define CRED_SESSION_WILDCARD_NAME_W L"*Session"
'#define CRED_SESSION_WILDCARD_NAME_A "*Session"
'#define CRED_UNIVERSAL_WILDCARD_W L'*'
'#define CRED_UNIVERSAL_WILDCARD_A '*'
'#define CRED_SESSION_WILDCARD_NAME_LENGTH (sizeof(CRED_SESSION_WILDCARD_NAME_A)-1)
'#define CRED_TARGETNAME_DOMAIN_NAMESPACE_W L"Domain"
'#define CRED_TARGETNAME_DOMAIN_NAMESPACE_A "Domain"
'#define CRED_TARGETNAME_DOMAIN_NAMESPACE_LENGTH (sizeof(CRED_TARGETNAME_DOMAIN_NAMESPACE_A)-1)
'#define CRED_UNIVERSAL_WILDCARD_W L'*'
'#define CRED_UNIVERSAL_WILDCARD_A '*'
'#define CRED_TARGETNAME_LEGACYGENERIC_NAMESPACE_W L"LegacyGeneric"
'#define CRED_TARGETNAME_LEGACYGENERIC_NAMESPACE_A "LegacyGeneric"
'#define CRED_TARGETNAME_LEGACYGENERIC_NAMESPACE_LENGTH (sizeof(CRED_TARGETNAME_LEGACYGENERIC_NAMESPACE_A)-1)
'#define CRED_TARGETNAME_NAMESPACE_SEPERATOR_W L':'
'#define CRED_TARGETNAME_NAMESPACE_SEPERATOR_A ':'
'#define CRED_TARGETNAME_ATTRIBUTE_SEPERATOR_W L'='
'#define CRED_TARGETNAME_ATTRIBUTE_SEPERATOR_A '='
'#define CRED_TARGETNAME_DOMAIN_EXTENDED_USERNAME_SEPARATOR_W L'|'
'#define CRED_TARGETNAME_DOMAIN_EXTENDED_USERNAME_SEPARATOR_A '|'
'#define CRED_TARGETNAME_ATTRIBUTE_TARGET_W L"target"
'#define CRED_TARGETNAME_ATTRIBUTE_TARGET_A "target"
'#define CRED_TARGETNAME_ATTRIBUTE_TARGET_LENGTH (sizeof(CRED_TARGETNAME_ATTRIBUTE_TARGET_A)-1)
'#define CRED_TARGETNAME_ATTRIBUTE_NAME_W L"name"
'#define CRED_TARGETNAME_ATTRIBUTE_NAME_A "name"
'#define CRED_TARGETNAME_ATTRIBUTE_NAME_LENGTH (sizeof(CRED_TARGETNAME_ATTRIBUTE_NAME_A)-1)
'#define CRED_TARGETNAME_ATTRIBUTE_BATCH_W L"batch"
'#define CRED_TARGETNAME_ATTRIBUTE_BATCH_A "batch"
'#define CRED_TARGETNAME_ATTRIBUTE_BATCH_LENGTH (sizeof(CRED_TARGETNAME_ATTRIBUTE_BATCH_A)-1)
'#define CRED_TARGETNAME_ATTRIBUTE_INTERACTIVE_W L"interactive"
'#define CRED_TARGETNAME_ATTRIBUTE_INTERACTIVE_A "interactive"
'#define CRED_TARGETNAME_ATTRIBUTE_INTERACTIVE_LENGTH (sizeof(CRED_TARGETNAME_ATTRIBUTE_INTERACTIVE_A)-1)
'#define CRED_TARGETNAME_ATTRIBUTE_SERVICE_W L"service"
'#define CRED_TARGETNAME_ATTRIBUTE_SERVICE_A "service"
'#define CRED_TARGETNAME_ATTRIBUTE_SERVICE_LENGTH (sizeof(CRED_TARGETNAME_ATTRIBUTE_SERVICE_A)-1)
'#define CRED_TARGETNAME_ATTRIBUTE_NETWORK_W L"network"
'#define CRED_TARGETNAME_ATTRIBUTE_NETWORK_A "network"
'#define CRED_TARGETNAME_ATTRIBUTE_NETWORK_LENGTH (sizeof(CRED_TARGETNAME_ATTRIBUTE_NETWORK_A)-1)
'#define CRED_TARGETNAME_ATTRIBUTE_NETWORKCLEARTEXT_W L"networkcleartext"
'#define CRED_TARGETNAME_ATTRIBUTE_NETWORKCLEARTEXT_A "networkcleartext"
'#define CRED_TARGETNAME_ATTRIBUTE_NETWORKCLEARTEXT_LENGTH (sizeof(CRED_TARGETNAME_ATTRIBUTE_NETWORKCLEARTEXT_A)-1)
'#define CRED_TARGETNAME_ATTRIBUTE_REMOTEINTERACTIVE_W L"remoteinteractive"
'#define CRED_TARGETNAME_ATTRIBUTE_REMOTEINTERACTIVE_A "remoteinteractive"
'#define CRED_TARGETNAME_ATTRIBUTE_REMOTEINTERACTIVE_LENGTH (sizeof(CRED_TARGETNAME_ATTRIBUTE_REMOTEINTERACTIVE_A)-1)
'#define CRED_TARGETNAME_ATTRIBUTE_CACHEDINTERACTIVE_W L"cachedinteractive"
'#define CRED_TARGETNAME_ATTRIBUTE_CACHEDINTERACTIVE_A "cachedinteractive"
'#define CRED_TARGETNAME_ATTRIBUTE_CACHEDINTERACTIVE_LENGTH (sizeof(CRED_TARGETNAME_ATTRIBUTE_CACHEDINTERACTIVE_A)-1)

$$CRED_SESSION_WILDCARD_NAME_W = "*Session"$$
$CRED_SESSION_WILDCARD_NAME_A = "*Session"

$$CRED_UNIVERSAL_WILDCARD_W = "*"$$
$CRED_UNIVERSAL_WILDCARD_A = "*"

%CRED_SESSION_WILDCARD_NAME_LENGTH=7 ' (LEN($CRED_SESSION_WILDCARD_NAME_A)-1)

$$CRED_TARGETNAME_DOMAIN_NAMESPACE_W = "Domain"$$
$CRED_TARGETNAME_DOMAIN_NAMESPACE_A = "Domain"

%CRED_TARGETNAME_DOMAIN_NAMESPACE_LENGTH=5 ' (LEN($CRED_TARGETNAME_DOMAIN_NAMESPACE_A)-1)

$$CRED_UNIVERSAL_WILDCARD_W = "*"$$
$CRED_UNIVERSAL_WILDCARD_A = "*"

$$CRED_TARGETNAME_LEGACYGENERIC_NAMESPACE_W = "LegacyGeneric"$$
$CRED_TARGETNAME_LEGACYGENERIC_NAMESPACE_A = "LegacyGeneric"

%CRED_TARGETNAME_LEGACYGENERIC_NAMESPACE_LENGTH=12 ' (LEN($CRED_TARGETNAME_LEGACYGENERIC_NAMESPACE_A)-1)

$$CRED_TARGETNAME_NAMESPACE_SEPERATOR_W = ":"$$
$CRED_TARGETNAME_NAMESPACE_SEPERATOR_A = ":"

$$CRED_TARGETNAME_ATTRIBUTE_SEPERATOR_W = "="$$
$CRED_TARGETNAME_ATTRIBUTE_SEPERATOR_A = "="

$$CRED_TARGETNAME_DOMAIN_EXTENDED_USERNAME_SEPARATOR_W = "|"$$
$CRED_TARGETNAME_DOMAIN_EXTENDED_USERNAME_SEPARATOR_A = "|"

$$CRED_TARGETNAME_ATTRIBUTE_TARGET_W = "target"$$
$CRED_TARGETNAME_ATTRIBUTE_TARGET_A = "target"

%CRED_TARGETNAME_ATTRIBUTE_TARGET_LENGTH=5 ' (LEN($CRED_TARGETNAME_ATTRIBUTE_TARGET_A)-1)

$$CRED_TARGETNAME_ATTRIBUTE_NAME_W = "name"$$
$CRED_TARGETNAME_ATTRIBUTE_NAME_A = "name"

%CRED_TARGETNAME_ATTRIBUTE_NAME_LENGTH=3 ' (LEN($CRED_TARGETNAME_ATTRIBUTE_NAME_A)-1)
$$CRED_TARGETNAME_ATTRIBUTE_BATCH_W = "batch"$$
$CRED_TARGETNAME_ATTRIBUTE_BATCH_A = "batch"

%CRED_TARGETNAME_ATTRIBUTE_BATCH_LENGTH=4 ' (LEN($CRED_TARGETNAME_ATTRIBUTE_BATCH_A)-1)

$$CRED_TARGETNAME_ATTRIBUTE_INTERACTIVE_W = "interactive"$$
$CRED_TARGETNAME_ATTRIBUTE_INTERACTIVE_A = "interactive"

%CRED_TARGETNAME_ATTRIBUTE_INTERACTIVE_LENGTH=10 ' (LEN($CRED_TARGETNAME_ATTRIBUTE_INTERACTIVE_A)-1)

$$CRED_TARGETNAME_ATTRIBUTE_SERVICE_W = "service"$$
$CRED_TARGETNAME_ATTRIBUTE_SERVICE_A = "service"

%CRED_TARGETNAME_ATTRIBUTE_SERVICE_LENGTH=6 ' (LEN($CRED_TARGETNAME_ATTRIBUTE_SERVICE_A)-1)

$$CRED_TARGETNAME_ATTRIBUTE_NETWORK_W = "network"$$
$CRED_TARGETNAME_ATTRIBUTE_NETWORK_A = "network"

%CRED_TARGETNAME_ATTRIBUTE_NETWORK_LENGTH=6 ' (LEN($CRED_TARGETNAME_ATTRIBUTE_NETWORK_A)-1)

$$CRED_TARGETNAME_ATTRIBUTE_NETWORKCLEARTEXT_W = "networkcleartext"$$
$CRED_TARGETNAME_ATTRIBUTE_NETWORKCLEARTEXT_A = "networkcleartext"

%CRED_TARGETNAME_ATTRIBUTE_NETWORKCLEARTEXT_LENGTH=15 ' (LEN($CRED_TARGETNAME_ATTRIBUTE_NETWORKCLEARTEXT_A)-1)

$$CRED_TARGETNAME_ATTRIBUTE_REMOTEINTERACTIVE_W = "remoteinteractive"$$
$CRED_TARGETNAME_ATTRIBUTE_REMOTEINTERACTIVE_A = "remoteinteractive"

%CRED_TARGETNAME_ATTRIBUTE_REMOTEINTERACTIVE_LENGTH=16 ' (LEN($CRED_TARGETNAME_ATTRIBUTE_REMOTEINTERACTIVE_A)-1)

$$CRED_TARGETNAME_ATTRIBUTE_CACHEDINTERACTIVE_W = "cachedinteractive"$$
$CRED_TARGETNAME_ATTRIBUTE_CACHEDINTERACTIVE_A = "cachedinteractive"

%CRED_TARGETNAME_ATTRIBUTE_CACHEDINTERACTIVE_LENGTH=16 ' (LEN($CRED_TARGETNAME_ATTRIBUTE_CACHEDINTERACTIVE_A)-1)

#IF %DEF(%UNICODE)
MACRO CRED_SESSION_WILDCARD_NAME = $$CRED_SESSION_WILDCARD_NAME_W
MACRO CRED_TARGETNAME_DOMAIN_NAMESPACE = $$CRED_TARGETNAME_DOMAIN_NAMESPACE_W
MACRO CRED_UNIVERSAL_WILDCARD = $$CRED_UNIVERSAL_WILDCARD_W
MACRO CRED_TARGETNAME_NAMESPACE_SEPERATOR = $$CRED_TARGETNAME_NAMESPACE_SEPERATOR_W
MACRO CRED_TARGETNAME_ATTRIBUTE_SEPERATOR = $$CRED_TARGETNAME_ATTRIBUTE_SEPERATOR_W
MACRO CRED_TARGETNAME_ATTRIBUTE_NAME = $$CRED_TARGETNAME_ATTRIBUTE_NAME_W
MACRO CRED_TARGETNAME_ATTRIBUTE_TARGET = $$CRED_TARGETNAME_ATTRIBUTE_TARGET_W
MACRO CRED_TARGETNAME_ATTRIBUTE_BATCH = $$CRED_TARGETNAME_ATTRIBUTE_BATCH_W
MACRO CRED_TARGETNAME_ATTRIBUTE_INTERACTIVE = $$CRED_TARGETNAME_ATTRIBUTE_INTERACTIVE_W
MACRO CRED_TARGETNAME_ATTRIBUTE_SERVICE = $$CRED_TARGETNAME_ATTRIBUTE_SERVICE_W
MACRO CRED_TARGETNAME_ATTRIBUTE_NETWORK = $$CRED_TARGETNAME_ATTRIBUTE_NETWORK_W
MACRO CRED_TARGETNAME_ATTRIBUTE_NETWORKCLEARTEXT = $$CRED_TARGETNAME_ATTRIBUTE_NETWORKCLEARTEXT_W
MACRO CRED_TARGETNAME_ATTRIBUTE_REMOTEINTERACTIVE = $$CRED_TARGETNAME_ATTRIBUTE_REMOTEINTERACTIVE_W
MACRO CRED_TARGETNAME_ATTRIBUTE_CACHEDINTERACTIVE = $$CRED_TARGETNAME_ATTRIBUTE_CACHEDINTERACTIVE_W

#ELSE
MACRO CRED_SESSION_WILDCARD_NAME = $CRED_SESSION_WILDCARD_NAME_A
MACRO CRED_TARGETNAME_DOMAIN_NAMESPACE = $CRED_TARGETNAME_DOMAIN_NAMESPACE_A
MACRO CRED_UNIVERSAL_WILDCARD = $CRED_UNIVERSAL_WILDCARD_A
MACRO CRED_TARGETNAME_NAMESPACE_SEPERATOR = $CRED_TARGETNAME_NAMESPACE_SEPERATOR_A
MACRO CRED_TARGETNAME_ATTRIBUTE_SEPERATOR = $CRED_TARGETNAME_ATTRIBUTE_SEPERATOR_A
MACRO CRED_TARGETNAME_ATTRIBUTE_NAME = $CRED_TARGETNAME_ATTRIBUTE_NAME_A
MACRO CRED_TARGETNAME_ATTRIBUTE_TARGET = $CRED_TARGETNAME_ATTRIBUTE_TARGET_A
MACRO CRED_TARGETNAME_ATTRIBUTE_BATCH = $CRED_TARGETNAME_ATTRIBUTE_BATCH_A
MACRO CRED_TARGETNAME_ATTRIBUTE_INTERACTIVE = $CRED_TARGETNAME_ATTRIBUTE_INTERACTIVE_A
MACRO CRED_TARGETNAME_ATTRIBUTE_SERVICE = $CRED_TARGETNAME_ATTRIBUTE_SERVICE_A
MACRO CRED_TARGETNAME_ATTRIBUTE_NETWORK = $CRED_TARGETNAME_ATTRIBUTE_NETWORK_A
MACRO CRED_TARGETNAME_ATTRIBUTE_NETWORKCLEARTEXT = $CRED_TARGETNAME_ATTRIBUTE_NETWORKCLEARTEXT_A
MACRO CRED_TARGETNAME_ATTRIBUTE_REMOTEINTERACTIVE = $CRED_TARGETNAME_ATTRIBUTE_REMOTEINTERACTIVE_A
MACRO CRED_TARGETNAME_ATTRIBUTE_CACHEDINTERACTIVE = $CRED_TARGETNAME_ATTRIBUTE_CACHEDINTERACTIVE_A
#ENDIF ' UNICODE

'//
'// Add\Extract Logon type from flags
'//
%CRED_LOGON_TYPES_MASK             = &HF000???  ' // Mask to get logon types

'#define CredAppendLogonTypeToFlags(Flags, LogonType)      (Flags) |= ((LogonType) << 12)
'#define CredGetLogonTypeFromFlags(Flags)                  ((SECURITY_LOGON_TYPE)(((Flags) & CRED_LOGON_TYPES_MASK) >> 12))
'#define CredRemoveLogonTypeFromFlags(Flags)               (Flags) &= ~CRED_LOGON_TYPES_MASK

FUNCTION CredAppendLogonTypeToFlags (BYVAL Flags AS DWORD, BYVAL LogonType AS DWORD) AS DWORD
   SHIFT LEFT LogonType, 12
   FUNCTION = Flags OR LogonType
END FUNCTION

FUNCTION CredGetLogonTypeFromFlags (BYVAL Flags AS DWORD) AS DWORD
   LOCAL x AS DWORD
   x = Flags AND %CRED_LOGON_TYPES_MASK
   SHIFT RIGHT x, 12
   FUNCTION = x
END FUNCTION

FUNCTION CredRemoveLogonTypeFromFlags (BYVAL Flags AS DWORD) AS DWORD
   FUNCTION = Flags AND (NOT %CRED_LOGON_TYPES_MASK)
END FUNCTION

'//
'// Values of the Credential Flags field.
'//
%CRED_FLAGS_PASSWORD_FOR_CERT    = &H0001???
%CRED_FLAGS_PROMPT_NOW           = &H0002???
%CRED_FLAGS_USERNAME_TARGET      = &H0004???
%CRED_FLAGS_OWF_CRED_BLOB        = &H0008???
%CRED_FLAGS_REQUIRE_CONFIRMATION = &H0010???

'//
'//  Valid only for return and only with CredReadDomainCredentials().
'//  Indicates credential was returned due to wildcard match
'//  of targetname with credential.
'//

%CRED_FLAGS_WILDCARD_MATCH       = &H0020???
%CRED_FLAGS_VALID_FLAGS          = &HF01F???   ' // Mask of all valid flags

'//
'//  Bit mask for only those flags which can be passed to the credman
'//  APIs.
'//

%CRED_FLAGS_VALID_INPUT_FLAGS    = &HF01F???

'//
'// Values of the Credential Type field.
'//
%CRED_TYPE_GENERIC                 = 1
%CRED_TYPE_DOMAIN_PASSWORD         = 2
%CRED_TYPE_DOMAIN_CERTIFICATE      = 3
%CRED_TYPE_DOMAIN_VISIBLE_PASSWORD = 4
%CRED_TYPE_GENERIC_CERTIFICATE     = 5
%CRED_TYPE_DOMAIN_EXTENDED         = 6
%CRED_TYPE_MAXIMUM                 = 7      ' // Maximum supported cred type
%CRED_TYPE_MAXIMUM_EX = (%CRED_TYPE_MAXIMUM+1000)  ' // Allow new applications to run on old OSes

'//
'// Maximum size of the CredBlob field (in bytes)
'//
%CRED_MAX_CREDENTIAL_BLOB_SIZE = 5 * 512

'//
'// Values of the Credential Persist field
'//
%CRED_PERSIST_NONE             = 0
%CRED_PERSIST_SESSION          = 1
%CRED_PERSIST_LOCAL_MACHINE    = 2
%CRED_PERSIST_ENTERPRISE       = 3


'//
'// A credential
'//

' // Size = 52 bytes
TYPE CREDENTIALA DWORD
   Flags              AS DWORD                       ' DWORD
   Type               AS DWORD                       ' DWORD
   TargetName         AS ASCIIZ PTR                  ' LPSTR
   Comment            AS ASCIIZ PTR                  ' LPSTR
   LastWritten        AS FILETIME                    ' FILETIME
   CredentialBlobSize AS DWORD                       ' DWORD
   CredentialBlob     AS BYTE PTR                    ' LPBYTE
   Persist            AS DWORD                       ' DWORD
   AttributeCount     AS DWORD                       ' DWORD
   Attributes         AS CREDENTIAL_ATTRIBUTEA PTR   ' PCREDENTIAL_ATTRIBUTEA
   TargetAlias        AS ASCIIZ PTR                  ' LPSTR
   UserName           AS ASCIIZ PTR                  ' LPSTR
END TYPE

' // Size = 52 bytes
TYPE CREDENTIALW DWORD
   Flags              AS DWORD                       ' DWORD
   Type               AS DWORD                       ' DWORD
   TargetName         AS WSTRINGZ PTR                ' LPWSTR
   Comment            AS WSTRINGZ PTR                ' LPWSTR
   LastWritten        AS FILETIME                    ' FILETIME
   CredentialBlobSize AS DWORD                       ' DWORD
   CredentialBlob     AS BYTE PTR                    ' LPBYTE
   Persist            AS DWORD                       ' DWORD
   AttributeCount     AS DWORD                       ' DWORD
   Attributes         AS CREDENTIAL_ATTRIBUTEW PTR   ' PCREDENTIAL_ATTRIBUTEW
   TargetAlias        AS WSTRINGZ PTR                ' LPWSTR
   UserName           AS WSTRINGZ PTR                ' LPWSTR
END TYPE

#IF %DEF(%UNICODE)
   MACRO CREDENTIAL = CREDENTIALW
#ELSE
   MACRO CREDENTIAL = CREDENTIALA
#ENDIF

'//
'// Value of the Flags field in CREDENTIAL_TARGET_INFORMATION
'//

%CRED_TI_SERVER_FORMAT_UNKNOWN   = &H0001???  ' // Don't know if server name is DNS or netbios format
%CRED_TI_DOMAIN_FORMAT_UNKNOWN   = &H0002???  ' // Don't know if domain name is DNS or netbios format
%CRED_TI_ONLY_PASSWORD_REQUIRED  = &H0004???  ' // Server only requires a password and not a username
%CRED_TI_USERNAME_TARGET         = &H0008???  ' // TargetName is username
%CRED_TI_CREATE_EXPLICIT_CRED    = &H0010???  ' // When creating a cred, create one named TargetInfo->TargetName
%CRED_TI_WORKGROUP_MEMBER        = &H0020???  ' // Indicates the machine is a member of a workgroup
%CRED_TI_VALID_FLAGS             = &HF07F???


'//
'// A credential target
'//

' // Size = 40 bytes
TYPE CREDENTIAL_TARGET_INFORMATIONA DWORD
   TargetName        AS ASCIIZ PTR   ' LPSTR
   NetbiosServerName AS ASCIIZ PTR   ' LPSTR
   DnsServerName     AS ASCIIZ PTR   ' LPSTR
   NetbiosDomainName AS ASCIIZ PTR   ' LPSTR
   DnsDomainName     AS ASCIIZ PTR   ' LPSTR
   DnsTreeName       AS ASCIIZ PTR   ' LPSTR
   PackageName       AS ASCIIZ PTR   ' LPSTR
   Flags             AS DWORD        ' ULONG
   CredTypeCount     AS DWORD        ' DWORD
   CredTypes         AS DWORD PTR    ' LPDWORD
END TYPE

' // Size = 40 bytes
TYPE CREDENTIAL_TARGET_INFORMATIONW DWORD
   TargetName        AS WSTRINGZ PTR   ' LPWSTR
   NetbiosServerName AS WSTRINGZ PTR   ' LPWSTR
   DnsServerName     AS WSTRINGZ PTR   ' LPWSTR
   NetbiosDomainName AS WSTRINGZ PTR   ' LPWSTR
   DnsDomainName     AS WSTRINGZ PTR   ' LPWSTR
   DnsTreeName       AS WSTRINGZ PTR   ' LPWSTR
   PackageName       AS WSTRINGZ PTR   ' LPWSTR
   Flags             AS DWORD          ' ULONG
   CredTypeCount     AS DWORD          ' DWORD
   CredTypes         AS DWORD PTR      ' LPDWORD
END TYPE

#IF %DEF(%UNICODE)
   MACRO CREDENTIAL_TARGET_INFORMATION = CREDENTIAL_TARGET_INFORMATIONW
#ELSE
   MACRO CREDENTIAL_TARGET_INFORMATION = CREDENTIAL_TARGET_INFORMATIONA
#ENDIF

'//
'// Certificate credential information
'//
'// The cbSize should be the size of the structure, sizeof(CERT_CREDENTIAL_INFO),
'// rgbHashofCert is the hash of the cert which is to be used as the credential.
'//

%CERT_HASH_LENGTH       = 20  ' // SHA1 hashes are used for cert hashes

' // Size = 24 bytes
TYPE CERT_CREDENTIAL_INFO DWORD
   cbSize AS DWORD   ' ULONG
   rgbHashOfCert(%CERT_HASH_LENGTH - 1) AS BYTE   ' UCHAR
END TYPE

'//
'// Username Target credential information
'//
'// This credential can be pass to LsaLogonUser to ask it to find a credential with a
'// TargetName of UserName.
'//

' // Size = 4 bytes
TYPE USERNAME_TARGET_CREDENTIAL_INFO DWORD
   UserName AS WSTRINGZ PTR   ' LPWSTR
END TYPE

'//
'// Marshaled credential blob information.
'//

' // Size = 8 bytes
TYPE BINARY_BLOB_CREDENTIAL_INFO DWORD
   cbBlob AS DWORD      ' ULONG
   pbBlob AS BYTE PTR   ' LPBYTE
END TYPE

'//
'// Credential type for credential marshaling routines
'//

' enum CRED_MARSHAL_TYPE
%CertCredential               = 1
%UsernameTargetCredential     = 2
%BinaryBlobCredential         = 3
%UsernameForPackedCredentials = 4   '  // internal only, reserved

'//
'// Protection type for credential providers secret protection routines
'//

' enum CRED_PROTECTION_TYPE
%CredUnprotected       = 0
%CredUserProtection    = 1
%CredTrustedProtection = 2

'//
'// Values for authentication buffers packing
'//
%CRED_PACK_PROTECTED_CREDENTIALS      = &H1
%CRED_PACK_WOW_BUFFER                 = &H2
%CRED_PACK_GENERIC_CREDENTIALS        = &H4

'//
'// Credential UI info
'//

%CREDUI_INFO_DEFINED = 1

' // Size = 20 bytes
TYPE CREDUI_INFOA DWORD
   cbSize         AS DWORD        ' DWORD
   hwndParent     AS DWORD        ' HWND
   pszMessageText AS ASCIIZ PTR   ' PCSTR
   pszCaptionText AS ASCIIZ PTR   ' PCSTR
   hbmBanner      AS DWORD        ' HBITMAP
END TYPE

' // Size = 20 bytes
TYPE CREDUI_INFOW DWORD
   cbSize         AS DWORD          ' DWORD
   hwndParent     AS DWORD          ' HWND
   pszMessageText AS WSTRINGZ PTR   ' PCWSTR
   pszCaptionText AS WSTRINGZ PTR   ' PCWSTR
   hbmBanner      AS DWORD          ' HBITMAP
END TYPE

#IF %DEF(%UNICODE)
   MACRO CREDUI_INFO = CREDUI_INFOW
#ELSE
   MACRO CREDUI_INFO = CREDUI_INFOA
#ENDIF

'//-----------------------------------------------------------------------------
'// Values
'//-----------------------------------------------------------------------------

'// String length limits:

%CREDUI_MAX_MESSAGE_LENGTH         = 32767
%CREDUI_MAX_CAPTION_LENGTH         = 128
%CREDUI_MAX_GENERIC_TARGET_LENGTH  = %CRED_MAX_GENERIC_TARGET_NAME_LENGTH
%CREDUI_MAX_DOMAIN_TARGET_LENGTH   = %CRED_MAX_DOMAIN_TARGET_NAME_LENGTH

'//
'//  Username can be in <domain>\<user> or <user>@<domain>
'//  Length in characters, not including NULL termination.
'//

%CREDUI_MAX_USERNAME_LENGTH        = %CRED_MAX_USERNAME_LENGTH
%CREDUI_MAX_PASSWORD_LENGTH        = 512 \ 2

'//
'//  Packed credential returned by SspiEncodeAuthIdentityAsStrings().
'//  Length in characters, not including NULL termination.
'//

%CREDUI_MAX_PACKED_CREDENTIALS_LENGTH = (65535 \ 2) - 2   ' ((MAXUSHORT / 2) - 2)

'// maximum length in bytes for binary credential blobs

%CREDUI_MAX_CREDENTIALS_BLOB_SIZE = 65535   ' (MAXUSHORT)

'//
'// Flags for CredUIPromptForCredentials and/or CredUICmdLinePromptForCredentials
'//

%CREDUI_FLAGS_INCORRECT_PASSWORD          = &H00001???    ' // indicates the username is valid, but password is not
%CREDUI_FLAGS_DO_NOT_PERSIST              = &H00002???    ' // Do not show "Save" checkbox, and do not persist credentials
%CREDUI_FLAGS_REQUEST_ADMINISTRATOR       = &H00004???    ' // Populate list box with admin accounts
%CREDUI_FLAGS_EXCLUDE_CERTIFICATES        = &H00008???    ' // do not include certificates in the drop list
%CREDUI_FLAGS_REQUIRE_CERTIFICATE         = &H00010???
%CREDUI_FLAGS_SHOW_SAVE_CHECK_BOX         = &H00040???
%CREDUI_FLAGS_ALWAYS_SHOW_UI              = &H00080???
%CREDUI_FLAGS_REQUIRE_SMARTCARD           = &H00100???
%CREDUI_FLAGS_PASSWORD_ONLY_OK            = &H00200???
%CREDUI_FLAGS_VALIDATE_USERNAME           = &H00400???
%CREDUI_FLAGS_COMPLETE_USERNAME           = &H00800???    ' //
%CREDUI_FLAGS_PERSIST                     = &H01000???    ' // Do not show "Save" checkbox, but persist credentials anyway
%CREDUI_FLAGS_SERVER_CREDENTIAL           = &H04000???
%CREDUI_FLAGS_EXPECT_CONFIRMATION         = &H20000???    ' // do not persist unless caller later confirms credential via CredUIConfirmCredential() api
%CREDUI_FLAGS_GENERIC_CREDENTIALS         = &H40000???    ' // Credential is a generic credential
%CREDUI_FLAGS_USERNAME_TARGET_CREDENTIALS = &H80000???    ' // Credential has a username as the target
%CREDUI_FLAGS_KEEP_USERNAME               = &H100000???   ' // don't allow the user to change the supplied username

'//
'// Mask of flags valid for CredUIPromptForCredentials
'//
%CREDUI_FLAGS_PROMPT_VALID = _
      %CREDUI_FLAGS_INCORRECT_PASSWORD OR _
      %CREDUI_FLAGS_DO_NOT_PERSIST OR _
      %CREDUI_FLAGS_REQUEST_ADMINISTRATOR OR _
      %CREDUI_FLAGS_EXCLUDE_CERTIFICATES OR _
      %CREDUI_FLAGS_REQUIRE_CERTIFICATE OR _
      %CREDUI_FLAGS_SHOW_SAVE_CHECK_BOX OR _
      %CREDUI_FLAGS_ALWAYS_SHOW_UI OR _
      %CREDUI_FLAGS_REQUIRE_SMARTCARD OR _
      %CREDUI_FLAGS_PASSWORD_ONLY_OK OR _
      %CREDUI_FLAGS_VALIDATE_USERNAME OR _
      %CREDUI_FLAGS_COMPLETE_USERNAME OR _
      %CREDUI_FLAGS_PERSIST OR _
      %CREDUI_FLAGS_SERVER_CREDENTIAL OR _
      %CREDUI_FLAGS_EXPECT_CONFIRMATION OR _
      %CREDUI_FLAGS_GENERIC_CREDENTIALS OR _
      %CREDUI_FLAGS_USERNAME_TARGET_CREDENTIALS OR _
      %CREDUI_FLAGS_KEEP_USERNAME

'//
'// Flags for CredUIPromptForWindowsCredentials and CPUS_CREDUI Usage Scenarios
'//

%CREDUIWIN_GENERIC                   = &H00000001???  ' // Plain text username/password is being requested
%CREDUIWIN_CHECKBOX                  = &H00000002???  ' // Show the Save Credential checkbox
%CREDUIWIN_AUTHPACKAGE_ONLY          = &H00000010???  ' // Only Cred Providers that support the input auth package should enumerate
%CREDUIWIN_IN_CRED_ONLY              = &H00000020???  ' // Only the incoming cred for the specific auth package should be enumerated
%CREDUIWIN_ENUMERATE_ADMINS          = &H00000100???  ' // Cred Providers should enumerate administrators only
%CREDUIWIN_ENUMERATE_CURRENT_USER    = &H00000200???  ' // Only the incoming cred for the specific auth package should be enumerated
%CREDUIWIN_SECURE_PROMPT             = &H00001000???  ' // The Credui prompt should be displayed on the secure desktop
%CREDUIWIN_PACK_32_WOW               = &H10000000???  ' // Tell the credential provider it should be packing its Auth Blob 32 bit even though it is running 64 native

%CREDUIWIN_VALID_FLAGS = %CREDUIWIN_GENERIC                OR _
                         %CREDUIWIN_CHECKBOX               OR _
                         %CREDUIWIN_AUTHPACKAGE_ONLY       OR _
                         %CREDUIWIN_IN_CRED_ONLY           OR _
                         %CREDUIWIN_ENUMERATE_ADMINS       OR _
                         %CREDUIWIN_ENUMERATE_CURRENT_USER OR _
                         %CREDUIWIN_SECURE_PROMPT          OR _
                         %CREDUIWIN_PACK_32_WOW

'//-----------------------------------------------------------------------------
'// Functions
'//-----------------------------------------------------------------------------


'//
'// Values of flags to CredWrite and CredWriteDomainCredentials
'//

%CRED_PRESERVE_CREDENTIAL_BLOB = &H1

DECLARE FUNCTION CredWriteW IMPORT "ADVAPI32.DLL" ALIAS "CredWriteW" ( _
   BYREF Credential AS CREDENTIALW _                    ' __in PCREDENTIALW Credential
 , BYVAL Flags AS DWORD _                               ' __in DWORD Flags
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION CredWriteA IMPORT "ADVAPI32.DLL" ALIAS "CredWriteA" ( _
   BYREF Credential AS CREDENTIALA _                    ' __in PCREDENTIALA Credential
 , BYVAL Flags AS DWORD _                               ' __in DWORD Flags
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO CredWrite = CredWriteW
#ELSE
   MACRO CredWrite = CredWriteA
#ENDIF

DECLARE FUNCTION CredReadW IMPORT "ADVAPI32.DLL" ALIAS "CredReadW" ( _
   BYREF TargetName AS WSTRINGZ _                       ' __in LPCWSTR TargetName
 , BYVAL Type AS DWORD _                                ' __in DWORD Type
 , BYVAL Flags AS DWORD _                               ' __reserved DWORD Flags
 , BYREF Credential AS ANY _                            ' __out PCREDENTIALW *Credential
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION CredReadA IMPORT "ADVAPI32.DLL" ALIAS "CredReadA" ( _
   BYREF TargetName AS ASCIIZ _                         ' __in LPCSTR TargetName
 , BYVAL Type AS DWORD _                                ' __in DWORD Type
 , BYVAL Flags AS DWORD _                               ' __reserved DWORD Flags
 , BYREF Credential AS ANY _                            ' __out PCREDENTIALA *Credential
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO CredRead = CredReadW
#ELSE
   MACRO CredRead = CredReadA
#ENDIF

'//
'// Values of flags to CredEnumerate
'//

%CRED_ENUMERATE_ALL_CREDENTIALS = &H1

DECLARE FUNCTION CredEnumerateW IMPORT "ADVAPI32.DLL" ALIAS "CredEnumerateW" ( _
   BYREF Filter AS WSTRINGZ _                           ' __in LPCWSTR Filter
 , BYVAL Flags AS DWORD _                               ' __reserved DWORD Flags
 , BYREF Count AS DWORD _                               ' __out DWORD *Count
 , BYREF Credential AS ANY _                            ' __out PCREDENTIALW **Credential
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION CredEnumerateA IMPORT "ADVAPI32.DLL" ALIAS "CredEnumerateA" ( _
   BYREF Filter AS ASCIIZ _                             ' __in LPCSTR Filter
 , BYVAL Flags AS DWORD _                               ' __reserved DWORD Flags
 , BYREF Count AS DWORD _                               ' __out DWORD *Count
 , BYREF Credential AS ANY _                            ' __out PCREDENTIALA **Credential
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO CredEnumerate = CredEnumerateW
#ELSE
   MACRO CredEnumerate = CredEnumerateA
#ENDIF

DECLARE FUNCTION CredWriteDomainCredentialsW IMPORT "ADVAPI32.DLL" ALIAS "CredWriteDomainCredentialsW" ( _
   BYREF TargetInfo AS CREDENTIAL_TARGET_INFORMATIONW _ ' __in PCREDENTIAL_TARGET_INFORMATIONW TargetInfo
 , BYREF Credential AS CREDENTIALW _                    ' __in PCREDENTIALW Credential
 , BYVAL Flags AS DWORD _                               ' __in DWORD Flags
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION CredWriteDomainCredentialsA IMPORT "ADVAPI32.DLL" ALIAS "CredWriteDomainCredentialsA" ( _
   BYREF TargetInfo AS CREDENTIAL_TARGET_INFORMATIONA _ ' __in PCREDENTIAL_TARGET_INFORMATIONA TargetInfo
 , BYREF Credential AS CREDENTIALA _                    ' __in PCREDENTIALA Credential
 , BYVAL Flags AS DWORD _                               ' __in DWORD Flags
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO CredWriteDomainCredentials = CredWriteDomainCredentialsW
#ELSE
   MACRO CredWriteDomainCredentials = CredWriteDomainCredentialsA
#ENDIF

'//
'// Values of flags to CredReadDomainCredentials
'//

%CRED_CACHE_TARGET_INFORMATION = &H1


DECLARE FUNCTION CredReadDomainCredentialsW IMPORT "ADVAPI32.DLL" ALIAS "CredReadDomainCredentialsW" ( _
   BYREF TargetInfo AS CREDENTIAL_TARGET_INFORMATIONW _ ' __in PCREDENTIAL_TARGET_INFORMATIONW TargetInfo
 , BYVAL Flags AS DWORD _                               ' __in DWORD Flags
 , BYREF Count AS DWORD _                               ' __out DWORD *Count
 , BYREF Credential AS ANY _                            ' __out PCREDENTIALW **Credential
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION CredReadDomainCredentialsA IMPORT "ADVAPI32.DLL" ALIAS "CredReadDomainCredentialsA" ( _
   BYREF TargetInfo AS CREDENTIAL_TARGET_INFORMATIONA _ ' __in PCREDENTIAL_TARGET_INFORMATIONA TargetInfo
 , BYVAL Flags AS DWORD _                               ' __in DWORD Flags
 , BYREF Count AS DWORD _                               ' __out DWORD *Count
 , BYREF Credential AS ANY _                            ' __out PCREDENTIALA **Credential
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO CredReadDomainCredentials = CredReadDomainCredentialsW
#ELSE
   MACRO CredReadDomainCredentials = CredReadDomainCredentialsA
#ENDIF

DECLARE FUNCTION CredDeleteW IMPORT "ADVAPI32.DLL" ALIAS "CredDeleteW" ( _
   BYREF TargetName AS WSTRINGZ _                       ' __in LPCWSTR TargetName
 , BYVAL Type AS DWORD _                                ' __in DWORD Type
 , BYVAL Flags AS DWORD _                               ' __reserved DWORD Flags
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION CredDeleteA IMPORT "ADVAPI32.DLL" ALIAS "CredDeleteA" ( _
   BYREF TargetName AS ASCIIZ _                         ' __in LPCSTR TargetName
 , BYVAL Type AS DWORD _                                ' __in DWORD Type
 , BYVAL Flags AS DWORD _                               ' __reserved DWORD Flags
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO CredDelete = CredDeleteW
#ELSE
   MACRO CredDelete = CredDeleteA
#ENDIF

DECLARE FUNCTION CredRenameW IMPORT "ADVAPI32.DLL" ALIAS "CredRenameW" ( _
   BYREF TargetName AS WSTRINGZ _                       ' __in LPCWSTR TargetName
 , BYREF NewTargetName AS WSTRINGZ _                    ' __in LPCWSTR NewTargetName
 , BYVAL Type AS DWORD _                                ' __in DWORD Type
 , BYVAL Flags AS DWORD _                               ' __reserved DWORD Flags
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION CredRenameA IMPORT "ADVAPI32.DLL" ALIAS "CredRenameA" ( _
   BYREF TargetName AS ASCIIZ _                         ' __in LPCSTR TargetName
 , BYREF NewTargetName AS ASCIIZ _                      ' __in LPCSTR NewTargetName
 , BYVAL Type AS DWORD _                                ' __in DWORD Type
 , BYVAL Flags AS DWORD _                               ' __reserved DWORD Flags
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO CredRename = CredRenameW
#ELSE
   MACRO CredRename = CredRenameA
#ENDIF

'//
'// Values of flags to CredGetTargetInfo
'//

%CRED_ALLOW_NAME_RESOLUTION = &H1

DECLARE FUNCTION CredGetTargetInfoW IMPORT "ADVAPI32.DLL" ALIAS "CredGetTargetInfoW" ( _
   BYREF TargetName AS WSTRINGZ _                       ' __in LPCWSTR TargetName
 , BYVAL Flags AS DWORD _                               ' __in DWORD Flags
 , BYREF TargetInfo AS ANY _                            ' __out PCREDENTIAL_TARGET_INFORMATIONW *TargetInfo
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION CredGetTargetInfoA IMPORT "ADVAPI32.DLL" ALIAS "CredGetTargetInfoA" ( _
   BYREF TargetName AS ASCIIZ _                         ' __in LPCSTR TargetName
 , BYVAL Flags AS DWORD _                               ' __in DWORD Flags
 , BYREF TargetInfo AS ANY _                            ' __out PCREDENTIAL_TARGET_INFORMATIONA *TargetInfo
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO CredGetTargetInfo = CredGetTargetInfoW
#ELSE
   MACRO CredGetTargetInfo = CredGetTargetInfoA
#ENDIF

DECLARE FUNCTION CredMarshalCredentialW IMPORT "ADVAPI32.DLL" ALIAS "CredMarshalCredentialW" ( _
   BYVAL CredType AS LONG _                             ' __in CRED_MARSHAL_TYPE CredType
 , BYREF Credential AS ANY _                            ' __in PVOID Credential
 , BYREF MarshaledCredential AS ANY _                   ' __out LPWSTR *MarshaledCredential
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION CredMarshalCredentialA IMPORT "ADVAPI32.DLL" ALIAS "CredMarshalCredentialA" ( _
   BYVAL CredType AS LONG _                             ' __in CRED_MARSHAL_TYPE CredType
 , BYREF Credential AS ANY _                            ' __in PVOID Credential
 , BYREF MarshaledCredential AS ANY _                   ' __out LPSTR *MarshaledCredential
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO CredMarshalCredential = CredMarshalCredentialW
#ELSE
   MACRO CredMarshalCredential = CredMarshalCredentialA
#ENDIF

DECLARE FUNCTION CredUnmarshalCredentialW IMPORT "ADVAPI32.DLL" ALIAS "CredUnmarshalCredentialW" ( _
   BYREF MarshaledCredential AS WSTRINGZ _              ' __in LPCWSTR MarshaledCredential
 , BYREF CredType AS LONG _                             ' __out PCRED_MARSHAL_TYPE CredType
 , BYREF Credential AS ANY _                            ' __out PVOID *Credential
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION CredUnmarshalCredentialA IMPORT "ADVAPI32.DLL" ALIAS "CredUnmarshalCredentialA" ( _
   BYREF MarshaledCredential AS ASCIIZ _                ' __in LPCSTR MarshaledCredential
 , BYREF CredType AS LONG _                             ' __out PCRED_MARSHAL_TYPE CredType
 , BYREF Credential AS ANY _                            ' __out PVOID *Credential
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO CredUnmarshalCredential = CredUnmarshalCredentialW
#ELSE
   MACRO CredUnmarshalCredential = CredUnmarshalCredentialA
#ENDIF

DECLARE FUNCTION CredIsMarshaledCredentialW IMPORT "ADVAPI32.DLL" ALIAS "CredIsMarshaledCredentialW" ( _
   BYREF MarshaledCredential AS WSTRINGZ _              ' __in LPCWSTR MarshaledCredential
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION CredIsMarshaledCredentialA IMPORT "ADVAPI32.DLL" ALIAS "CredIsMarshaledCredentialA" ( _
   BYREF MarshaledCredential AS ASCIIZ _                ' __in LPCSTR MarshaledCredential
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO CredIsMarshaledCredential = CredIsMarshaledCredentialW
#ELSE
   MACRO CredIsMarshaledCredential = CredIsMarshaledCredentialA
#ENDIF

DECLARE FUNCTION CredUnPackAuthenticationBufferW IMPORT "CREDUI.DLL" ALIAS "CredUnPackAuthenticationBufferW" ( _
   BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYREF pAuthBuffer AS ANY _                           ' __in PVOID pAuthBuffer
 , BYVAL cbAuthBuffer AS DWORD _                        ' __in DWORD cbAuthBuffer
 , BYREF pszUserName AS WSTRINGZ _                      ' __out LPWSTR pszUserName
 , BYREF pcchMaxUserName AS DWORD _                     ' __in_out DWORD* pcchMaxUserName
 , BYREF pszDomainName AS WSTRINGZ _                    ' __out LPWSTR pszDomainName
 , BYREF pcchMaxDomainName AS DWORD _                   ' __in_out_opt DWORD* pcchMaxDomainName
 , BYREF pszPassword AS WSTRINGZ _                      ' __out LPWSTR pszPassword
 , BYREF pcchMaxPassword AS DWORD _                     ' __in_out DWORD* pcchMaxPassword
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION CredUnPackAuthenticationBufferA IMPORT "CREDUI.DLL" ALIAS "CredUnPackAuthenticationBufferA" ( _
   BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYREF pAuthBuffer AS ANY _                           ' __in PVOID pAuthBuffer
 , BYVAL cbAuthBuffer AS DWORD _                        ' __in DWORD cbAuthBuffer
 , BYREF pszUserName AS ASCIIZ _                        ' __out LPSTR pszUserName
 , BYREF pcchMaxUserName AS DWORD _                     ' __in_out DWORD* pcchMaxUserName
 , BYREF pszDomainName AS ASCIIZ _                      ' __out LPSTR pszDomainName
 , BYREF pcchMaxDomainName AS DWORD _                   ' __in_out_opt DWORD* pcchMaxDomainName
 , BYREF pszPassword AS ASCIIZ _                        ' __out LPSTR pszPassword
 , BYREF pcchMaxPassword AS DWORD _                     ' __in_out DWORD* pcchMaxPassword
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO CredUnPackAuthenticationBuffer = CredUnPackAuthenticationBufferW
#ELSE
   MACRO CredUnPackAuthenticationBuffer = CredUnPackAuthenticationBufferA
#ENDIF

DECLARE FUNCTION CredPackAuthenticationBufferW IMPORT "CREDUI.DLL" ALIAS "CredPackAuthenticationBufferW" ( _
   BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYREF pszUserName AS WSTRINGZ _                      ' __in LPWSTR pszUserName
 , BYREF pszPassword AS WSTRINGZ _                      ' __in LPWSTR pszPassword
 , BYVAL pPackedCredentials AS DWORD _                  ' __out PBYTE pPackedCredentials
 , BYREF pcbPackedCredentials AS DWORD _                ' __in_out DWORD* pcbPackedCredentials
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION CredPackAuthenticationBufferA IMPORT "CREDUI.DLL" ALIAS "CredPackAuthenticationBufferA" ( _
   BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYREF pszUserName AS ASCIIZ _                        ' __in LPSTR pszUserName
 , BYREF pszPassword AS ASCIIZ _                        ' __in LPSTR pszPassword
 , BYVAL pPackedCredentials AS DWORD _                  ' __out PBYTE pPackedCredentials
 , BYREF pcbPackedCredentials AS DWORD _                ' __in_out DWORD* pcbPackedCredentials
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO CredPackAuthenticationBuffer = CredPackAuthenticationBufferW
#ELSE
   MACRO CredPackAuthenticationBuffer = CredPackAuthenticationBufferA
#ENDIF

DECLARE FUNCTION CredProtectW IMPORT "ADVAPI32.DLL" ALIAS "CredProtectW" ( _
   BYVAL fAsSelf AS LONG _                              ' __in BOOL fAsSelf
 , BYREF pszCredentials AS WSTRINGZ _                   ' __in LPWSTR pszCredentials
 , BYVAL cchCredentials AS DWORD _                      ' __in DWORD cchCredentials
 , BYREF pszProtectedCredentials AS WSTRINGZ _          ' __out LPWSTR pszProtectedCredentials
 , BYREF pcchMaxChars AS DWORD _                        ' __in_out DWORD* pcchMaxChars
 , BYREF ProtectionType AS DWORD _                      ' __out_opt CRED_PROTECTION_TYPE* ProtectionType
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION CredProtectA IMPORT "ADVAPI32.DLL" ALIAS "CredProtectA" ( _
   BYVAL fAsSelf AS LONG _                              ' __in BOOL fAsSelf
 , BYREF pszCredentials AS ASCIIZ _                     ' __in LPSTR pszCredentials
 , BYVAL cchCredentials AS DWORD _                      ' __in DWORD cchCredentials
 , BYREF pszProtectedCredentials AS ASCIIZ _            ' __out LPSTR pszProtectedCredentials
 , BYREF pcchMaxChars AS DWORD _                        ' __in_out DWORD* pcchMaxChars
 , BYREF ProtectionType AS DWORD _                      ' __out_opt CRED_PROTECTION_TYPE* ProtectionType
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO CredProtect = CredProtectW
#ELSE
   MACRO CredProtect = CredProtectA
#ENDIF

DECLARE FUNCTION CredUnprotectW IMPORT "ADVAPI32.DLL" ALIAS "CredUnprotectW" ( _
   BYVAL fAsSelf AS LONG _                              ' __in BOOL fAsSelf
 , BYREF pszProtectedCredentials AS WSTRINGZ _          ' __in LPWSTR pszProtectedCredentials
 , BYVAL cchProtectedCredentials AS DWORD _             ' __in DWORD cchProtectedCredentials
 , BYREF pszCredentials AS WSTRINGZ _                   ' __out_opt LPWSTR pszCredentials
 , BYREF pcchMaxChars AS DWORD _                        ' __in_out DWORD* pcchMaxChars
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION CredUnprotectA IMPORT "ADVAPI32.DLL" ALIAS "CredUnprotectA" ( _
   BYVAL fAsSelf AS LONG _                              ' __in BOOL fAsSelf
 , BYREF pszProtectedCredentials AS ASCIIZ _            ' __in LPSTR  pszProtectedCredentials
 , BYVAL cchProtectedCredentials AS DWORD _             ' __in DWORD cchProtectedCredentials
 , BYREF pszCredentials AS ASCIIZ _                     ' __out_opt LPSTR pszCredentials
 , BYREF pcchMaxChars AS DWORD _                        ' __in_out DWORD* pcchMaxChars
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO CredUnprotect = CredUnprotectW
#ELSE
   MACRO CredUnprotect = CredUnprotectA
#ENDIF

DECLARE FUNCTION CredIsProtectedW IMPORT "ADVAPI32.DLL" ALIAS "CredIsProtectedW" ( _
   BYREF pszProtectedCredentials AS WSTRINGZ _          ' __in LPWSTR pszProtectedCredentials
 , BYREF pProtectionType AS DWORD _                     ' __out CRED_PROTECTION_TYPE* pProtectionType
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION CredIsProtectedA IMPORT "ADVAPI32.DLL" ALIAS "CredIsProtectedA" ( _
   BYREF pszProtectedCredentials AS ASCIIZ _            ' __in LPSTR pszProtectedCredentials
 , BYREF pProtectionType AS DWORD _                     ' __out CRED_PROTECTION_TYPE* pProtectionType
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO CredIsProtected = CredIsProtectedW
#ELSE
   MACRO CredIsProtected = CredIsProtectedA
#ENDIF

DECLARE FUNCTION CredFindBestCredentialW IMPORT "ADVAPI32.DLL" ALIAS "CredFindBestCredentialW" ( _
   BYREF TargetName AS WSTRINGZ _                       ' __in LPCWSTR TargetName
 , BYVAL Type AS DWORD _                                ' __in DWORD Type
 , BYVAL Flags AS DWORD _                               ' __in DWORD Flags
 , BYREF Credential AS ANY _                            ' __out PCREDENTIALW *Credential
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION CredFindBestCredentialA IMPORT "ADVAPI32.DLL" ALIAS "CredFindBestCredentialA" ( _
   BYREF TargetName AS ASCIIZ _                         ' __in LPCSTR TargetName
 , BYVAL Type AS DWORD _                                ' __in DWORD Type
 , BYVAL Flags AS DWORD _                               ' __in DWORD Flags
 , BYREF Credential AS ANY _                            ' __out PCREDENTIALA *Credential
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO CredFindBestCredential = CredFindBestCredentialW
#ELSE
   MACRO CredFindBestCredential = CredFindBestCredentialA
#ENDIF

DECLARE FUNCTION CredGetSessionTypes IMPORT "ADVAPI32.DLL" ALIAS "CredGetSessionTypes" ( _
   BYVAL MaximumPersistCount AS DWORD _                 ' __in DWORD MaximumPersistCount
 , BYREF MaximumPersist AS DWORD _                      ' __out LPDWORD MaximumPersist
 ) AS LONG                                              ' BOOL

#IF %DEF(%USEPBDECL)
DECLARE SUB CredFree LIB "AdvApi32.dll" ALIAS "CredFree" ( _
    Buffer AS ANY) ' PVOID
#ELSE
DECLARE SUB CredFree IMPORT "ADVAPI32.DLL" ALIAS "CredFree" ( _
   BYVAL Buffer AS DWORD _                              ' __in PVOID Buffer
 )                                                      ' VOID
#ENDIF

DECLARE FUNCTION CredUIPromptForCredentialsW IMPORT "CREDUI.DLL" ALIAS "CredUIPromptForCredentialsW" ( _
   BYREF pUiInfo AS CREDUI_INFOW _                      ' __in_opt PCREDUI_INFOW pUiInfo
 , BYREF pszTargetName AS WSTRINGZ _                    ' __in_opt PCWSTR pszTargetName
 , BYREF pContext AS SecHandle _                        ' __reserved PCtxtHandle pContext
 , BYVAL dwAuthError AS DWORD _                         ' __in DWORD dwAuthError
 , BYREF pszUserName AS WSTRINGZ _                      ' __out PWSTR pszUserName
 , BYVAL ulUserNameBufferSize AS DWORD _                ' __in ULONG ulUserNameBufferSize
 , BYREF pszPassword AS WSTRINGZ _                      ' __out PWSTR pszPassword
 , BYVAL ulPasswordBufferSize AS DWORD _                ' __in ULONG ulPasswordBufferSize
 , BYREF save AS LONG _                                 ' __in_out_opt BOOL *save
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION CredUIPromptForCredentialsA IMPORT "CREDUI.DLL" ALIAS "CredUIPromptForCredentialsA" ( _
   BYREF pUiInfo AS CREDUI_INFOA _                      ' __in_opt PCREDUI_INFOA pUiInfo
 , BYREF pszTargetName AS ASCIIZ _                      ' __in_opt PCSTR pszTargetName
 , BYREF pContext AS SecHandle _                        ' __reserved PCtxtHandle pContext
 , BYVAL dwAuthError AS DWORD _                         ' __in DWORD dwAuthError
 , BYREF pszUserName AS ASCIIZ _                        ' __out PSTR pszUserName
 , BYVAL ulUserNameBufferSize AS DWORD _                ' __in ULONG ulUserNameBufferSize
 , BYREF pszPassword AS ASCIIZ _                        ' __out PSTR pszPassword
 , BYVAL ulPasswordBufferSize AS DWORD _                ' __in ULONG ulPasswordBufferSize
 , BYREF save AS LONG _                                 ' __in_out_opt BOOL *save
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 ) AS DWORD                                             ' DWORD

#IF %DEF(%UNICODE)
   MACRO CredUIPromptForCredentials = CredUIPromptForCredentialsW
#ELSE
   MACRO CredUIPromptForCredentials = CredUIPromptForCredentialsA
#ENDIF

DECLARE FUNCTION CredUIPromptForWindowsCredentialsW IMPORT "CREDUI.DLL" ALIAS "CredUIPromptForWindowsCredentialsW" ( _
   BYREF pUiInfo AS CREDUI_INFOW _                      ' __in_opt PCREDUI_INFOW pUiInfo
 , BYVAL dwAuthError AS DWORD _                         ' __in DWORD dwAuthError
 , BYREF pulAuthPackage AS DWORD _                      ' __in_out ULONG *pulAuthPackage
 , BYREF pvInAuthBuffer AS ANY _                        ' __in LPCVOID pvInAuthBuffer
 , BYVAL ulInAuthBufferSize AS DWORD _                  ' __in ULONG ulInAuthBufferSize
 , BYREF ppvOutAuthBuffer AS ANY _                      ' __out LPVOID * ppvOutAuthBuffer
 , BYREF pulOutAuthBufferSize AS DWORD _                ' __out ULONG * pulOutAuthBufferSize
 , BYREF pfSave AS LONG _                               ' __in_out_opt BOOL *pfSave
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION CredUIPromptForWindowsCredentialsA IMPORT "CREDUI.DLL" ALIAS "CredUIPromptForWindowsCredentialsA" ( _
   BYREF pUiInfo AS CREDUI_INFOA _                      ' __in_opt PCREDUI_INFOA pUiInfo
 , BYVAL dwAuthError AS DWORD _                         ' __in DWORD dwAuthError
 , BYREF pulAuthPackage AS DWORD _                      ' __in_out ULONG *pulAuthPackage
 , BYREF pvInAuthBuffer AS ANY _                        ' __in LPCVOID pvInAuthBuffer
 , BYVAL ulInAuthBufferSize AS DWORD _                  ' __in ULONG ulInAuthBufferSize
 , BYREF ppvOutAuthBuffer AS ANY _                      ' __out LPVOID * ppvOutAuthBuffer
 , BYREF pulOutAuthBufferSize AS DWORD _                ' __out ULONG * pulOutAuthBufferSize
 , BYREF pfSave AS LONG _                               ' __in_out_opt BOOL *pfSave
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 ) AS DWORD                                             ' DWORD

#IF %DEF(%UNICODE)
   MACRO CredUIPromptForWindowsCredentials = CredUIPromptForWindowsCredentialsW
#ELSE
   MACRO CredUIPromptForWindowsCredentials = CredUIPromptForWindowsCredentialsA
#ENDIF

DECLARE FUNCTION CredUIParseUserNameW IMPORT "CREDUI.DLL" ALIAS "CredUIParseUserNameW" ( _
   BYREF UserName AS WSTRINGZ _                         ' __in CONST WCHAR *UserName
 , BYREF user AS WSTRINGZ _                             ' __out WCHAR *user
 , BYVAL userBufferSize AS DWORD _                      ' __in ULONG userBufferSize
 , BYREF domain AS WSTRINGZ _                           ' __out WCHAR *domain
 , BYVAL domainBufferSize AS DWORD _                    ' __in ULONG domainBufferSize
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION CredUIParseUserNameA IMPORT "CREDUI.DLL" ALIAS "CredUIParseUserNameA" ( _
   BYREF UserName AS ASCIIZ _                           ' __in CONST CHAR *UserName
 , BYREF user AS ASCIIZ _                               ' __out CHAR *user
 , BYVAL userBufferSize AS DWORD _                      ' __in ULONG userBufferSize
 , BYREF domain AS ASCIIZ _                             ' __out CHAR *domain
 , BYVAL domainBufferSize AS DWORD _                    ' __in ULONG domainBufferSize
 ) AS DWORD                                             ' DWORD

#IF %DEF(%UNICODE)
   MACRO CredUIParseUserName = CredUIParseUserNameW
#ELSE
   MACRO CredUIParseUserName = CredUIParseUserNameA
#ENDIF

DECLARE FUNCTION CredUICmdLinePromptForCredentialsW IMPORT "CREDUI.DLL" ALIAS "CredUICmdLinePromptForCredentialsW" ( _
   BYREF pszTargetName AS WSTRINGZ _                    ' __in_opt PCWSTR pszTargetName
 , BYREF pContext AS SecHandle _                        ' __reserved PCtxtHandle pContext
 , BYVAL dwAuthError AS DWORD _                         ' __in DWORD dwAuthError
 , BYREF UserName AS WSTRINGZ _                         ' __out PWSTR UserName
 , BYVAL ulUserBufferSize AS DWORD _                    ' __in ULONG ulUserBufferSize
 , BYREF pszPassword AS WSTRINGZ _                      ' __out PWSTR pszPassword
 , BYVAL ulPasswordBufferSize AS DWORD _                ' __in ULONG ulPasswordBufferSize
 , BYREF pfSave AS LONG _                               ' __in_out_opt PBOOL pfSave
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION CredUICmdLinePromptForCredentialsA IMPORT "CREDUI.DLL" ALIAS "CredUICmdLinePromptForCredentialsA" ( _
   BYREF pszTargetName AS ASCIIZ _                      ' __in_opt PCSTR pszTargetName
 , BYREF pContext AS SecHandle _                        ' __reserved PCtxtHandle pContext
 , BYVAL dwAuthError AS DWORD _                         ' __in DWORD dwAuthError
 , BYREF UserName AS ASCIIZ _                           ' __out PSTR UserName
 , BYVAL ulUserBufferSize AS DWORD _                    ' __in ULONG ulUserBufferSize
 , BYREF pszPassword AS ASCIIZ _                        ' __out PSTR pszPassword
 , BYVAL ulPasswordBufferSize AS DWORD _                ' __in ULONG ulPasswordBufferSize
 , BYREF pfSave AS LONG _                               ' __in_out_opt PBOOL pfSave
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 ) AS DWORD                                             ' DWORD

#IF %DEF(%UNICODE)
   MACRO CredUICmdLinePromptForCredentials = CredUICmdLinePromptForCredentialsW
#ELSE
   MACRO CredUICmdLinePromptForCredentials = CredUICmdLinePromptForCredentialsA
#ENDIF

'//
'// Call this API with bConfirm set to TRUE to confirm that the credential (previously created
'// via CredUIGetCredentials or CredUIPromptForCredentials worked, or with bConfirm set to FALSE
'// to indicate it didn't

DECLARE FUNCTION CredUIConfirmCredentialsW IMPORT "CREDUI.DLL" ALIAS "CredUIConfirmCredentialsW" ( _
   BYREF pszTargetName AS WSTRINGZ _                    ' __in PCWSTR pszTargetName
 , BYVAL bConfirm AS DWORD _                            ' __in BOOL  bConfirm
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION CredUIConfirmCredentialsA IMPORT "CREDUI.DLL" ALIAS "CredUIConfirmCredentialsA" ( _
   BYREF pszTargetName AS ASCIIZ _                      ' __in PCSTR pszTargetName
 , BYVAL bConfirm AS DWORD _                            ' __in BOOL  bConfirm
 ) AS DWORD                                             ' DWORD

#IF %DEF(%UNICODE)
   MACRO CredUIConfirmCredentials = CredUIConfirmCredentialsW
#ELSE
   MACRO CredUIConfirmCredentials = CredUIConfirmCredentialsA
#ENDIF

DECLARE FUNCTION CredUIStoreSSOCredW IMPORT "CREDUI.DLL" ALIAS "CredUIStoreSSOCredW" ( _
   BYREF pszRealm AS WSTRINGZ _                         ' __in_opt PCWSTR pszRealm
 , BYREF pszUsername AS WSTRINGZ _                      ' __in PCWSTR pszUsername
 , BYREF pszPassword AS WSTRINGZ _                      ' __in PCWSTR pszPassword
 , BYVAL bPersist AS LONG _                             ' __in BOOL   bPersist
 ) AS DWORD                                             ' DWORD

MACRO CredUIStoreSSOCred = CredUIStoreSSOCredW

DECLARE FUNCTION CredUIReadSSOCredW IMPORT "CREDUI.DLL" ALIAS "CredUIReadSSOCredW" ( _
   BYREF pszRealm AS WSTRINGZ _                         ' __in_opt PCWSTR pszRealm
 , BYREF ppszUsername AS ANY _                          ' __out PWSTR* ppszUsername
 ) AS DWORD                                             ' DWORD

MACRO CredUIReadSSOCred = CredUIReadSSOCredW
