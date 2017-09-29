' ########################################################################################
' Microsoft Windows
' File: Sspi.inc
' Contents: Security Support Provider Interface prototypes and structure definitions
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

' NOTE: The parameters of type TimeStamp, CredHandle, CtxtHandle have been declared
' AS ANY to allow to pass an structure or a QUAD.

#INCLUDE THIS ONCE
%SSPI_INC = 1

#INCLUDE ONCE "wincred.inc"
#INCLUDE ONCE "ntsecapi.inc"
#INCLUDE ONCE "sdkddkver.inc"

'#ifndef __SSPI_H__
'#define __SSPI_H__

'#if _MSC_VER > 1000
'#pragma once
'#endif

'#ifdef __cplusplus
'extern "C" {
'#endif

'//
'// Determine environment:
'//

'#IF %DEF(%SECURITY_WIN32)
'%ISSP_LEVEL = 32
'%ISSP_MODE  = 1
'#ENDIF   ' // SECURITY_WIN32

'#IF %DEF(%SECURITY_KERNEL)
'%ISSP_LEVEL = 32         ' // ntifs
'//
'// SECURITY_KERNEL trumps SECURITY_WIN32.  Undefine ISSP_MODE so that
'// we don't get redefine errors.
'//
'#ifdef ISSP_MODE
'#undef ISSP_MODE
'#endif
'%ISSP_MODE  = 0           ' // ntifs
'#ENDIF   ' // SECURITY_KERNEL

'#ifdef SECURITY_MAC
'#define ISSP_LEVEL  32
'#define ISSP_MODE   1
'#endif // SECURITY_MAC


'#ifndef ISSP_LEVEL
'#error  You must define one of SECURITY_WIN32, SECURITY_KERNEL, or
'#error  SECURITY_MAC
'#endif // !ISSP_LEVEL

'//
'// Now, define platform specific mappings:
'//

'#if defined(_NO_KSECDD_IMPORT_)

'#define KSECDDDECLSPEC

'#else

'#define KSECDDDECLSPEC __declspec(dllimport)

'#endif

'typedef WCHAR SEC_WCHAR;
'typedef CHAR SEC_CHAR;

'#ifndef __SECSTATUS_DEFINED__
'typedef LONG SECURITY_STATUS;
'#define __SECSTATUS_DEFINED__
'#endif

'#define SEC_TEXT TEXT
'#define SEC_FAR
'#define SEC_ENTRY __stdcall

'//
'// Decide what a string - 32 bits only since for 16 bits it is clear.
'//


'#ifdef UNICODE
'typedef SEC_WCHAR * SECURITY_PSTR;
'typedef CONST SEC_WCHAR * SECURITY_PCSTR;
'#else // UNICODE
'typedef SEC_CHAR * SECURITY_PSTR;
'typedef CONST SEC_CHAR * SECURITY_PCSTR;
'#endif // UNICODE



'//
'// Equivalent string for rpcrt:
'//

'#define __SEC_FAR

'//
'// Okay, security specific types:
'//

#IF NOT %DEF(%SECHANDLE_DEFINED)
%SECHANDLE_DEFINED = 1
' // Size = 8 bytes
TYPE SecHandle DWORD
   dwLower AS DWORD   ' ULONG_PTR
   dwUpper AS DWORD   ' ULONG_PTR
END TYPE
#ENDIF

'#define SecInvalidateHandle( x )    \
'            ((PSecHandle) x)->dwLower = ((ULONG_PTR) ((INT_PTR)-1)) ; \
'            ((PSecHandle) x)->dwUpper = ((ULONG_PTR) ((INT_PTR)-1)) ; \

SUB SecInvalidateHandle (BYREF x AS SecHandle)
  x.dwLower = &HFFFFFFFF???
  x.dwUpper = &HFFFFFFFF???
END SUB

'#define SecIsValidHandle( x ) \
'            ( ( ((PSecHandle) x)->dwLower != ((ULONG_PTR) ((INT_PTR) -1 ))) && \
'              ( ((PSecHandle) x)->dwUpper != ((ULONG_PTR) ((INT_PTR) -1 ))) )

FUNCTION SecIsValidHandle (BYREF x AS SecHandle) AS LONG
   FUNCTION = ((x.dwLower <> &HFFFFFFFF???) AND (x.dwUpper <> &HFFFFFFFF???))
END FUNCTION

'//
'// pseudo handle value: the handle has already been deleted
'//

'#define SEC_DELETED_HANDLE  ((ULONG_PTR) (-2))
%SEC_DELETED_HANDLE = &HFFFFFFFE???

'typedef SecHandle CredHandle;
'typedef PSecHandle PCredHandle;

' // Size = 8 bytes
TYPE CredHandle DWORD
   dwLower AS DWORD   ' ULONG_PTR
   dwUpper AS DWORD   ' ULONG_PTR
END TYPE

'typedef SecHandle CtxtHandle;
'typedef PSecHandle PCtxtHandle;

' // Size = 8 bytes
TYPE CtxtHandle DWORD
   dwLower AS DWORD   ' ULONG_PTR
   dwUpper AS DWORD   ' ULONG_PTR
END TYPE

'#  ifdef WIN32_CHICAGO

'typedef unsigned __int64 QWORD;
'typedef QWORD SECURITY_INTEGER, *PSECURITY_INTEGER;
'#define SEC_SUCCESS(Status) ((Status) >= 0)

'#  elif defined(_NTDEF_) || defined(_WINNT_)

'typedef LARGE_INTEGER _SECURITY_INTEGER, SECURITY_INTEGER, *PSECURITY_INTEGER; // ntifs

'#  else // _NTDEF_ || _WINNT_

'typedef struct _SECURITY_INTEGER
'{
'    unsigned long LowPart;
'    long HighPart;
'} SECURITY_INTEGER, *PSECURITY_INTEGER;

'#  endif // _NTDEF_ || _WINNT_

'#  ifndef SECURITY_MAC

'typedef SECURITY_INTEGER TimeStamp;                 // ntifs
'typedef SECURITY_INTEGER * PTimeStamp;      // ntifs

'#  else // SECURITY_MAC
'typedef unsigned long TimeStamp;
'typedef unsigned long * PTimeStamp;
'#  endif // SECUIRT_MAC

FUNCTION SEC_SUCCESS (BYVAL nStatus AS LONG) AS LONG
   FUNCTION = -(nStatus >= 0)
END FUNCTION

' // Size = 8 bytes
TYPE SECURITY_INTEGER DWORD
   LowPart  AS DWORD   ' unsigned long
   HighPart AS LONG    ' long
END TYPE

'//
'// If we are in 32 bit mode, define the SECURITY_STRING structure,
'// as a clone of the base UNICODE_STRING structure.  This is used
'// internally in security components, an as the string interface
'// for kernel components (e.g. FSPs)
'//

'#  ifndef _NTDEF_
'typedef struct _SECURITY_STRING {
'    unsigned short      Length;
'    unsigned short      MaximumLength;
'#    ifdef MIDL_PASS
'    [size_is(MaximumLength / 2), length_is(Length / 2)]
'#    endif // MIDL_PASS
'    unsigned short *    Buffer;
''} SECURITY_STRING, * PSECURITY_STRING;
'#  else // _NTDEF_
'typedef UNICODE_STRING SECURITY_STRING, *PSECURITY_STRING;  // ntifs
'#  endif // _NTDEF_

' // Size = 8 bytes
TYPE SECURITY_STRING WORD
   Length        AS WORD       ' unsigned short
   MaximumLength AS WORD       ' unsigned short
   Buffer        AS WORD PTR   ' unsigned short *
END TYPE

'//
'// SecPkgInfo structure
'//
'//  Provides general information about a security provider
'//

' // Size = 20 bytes
TYPE SecPkgInfoW WORD
   fCapabilities AS DWORD          ' unsigned long // Capability bitmask
   wVersion      AS WORD           ' unsigned short // Version of driver
   wRPCID        AS WORD           ' unsigned short // ID for RPC Runtime
   cbMaxToken    AS DWORD          ' unsigned long // Size of authentication token (max)
   Name          AS WSTRINGZ PTR   ' SEC_WCHAR * // Text name
   Comment       AS WSTRINGZ PTR   ' SEC_WCHAR * // Comment
END TYPE

' // Size = 20 bytes
TYPE SecPkgInfoA WORD
   fCapabilities AS DWORD        ' unsigned long // Capability bitmask
   wVersion      AS WORD         ' unsigned short // Version of driver
   wRPCID        AS WORD         ' unsigned short // ID for RPC Runtime
   cbMaxToken    AS DWORD        ' unsigned long // Size of authentication token (max)
   Name          AS ASCIIZ PTR   ' SEC_CHAR * // Text name
   Comment       AS ASCIIZ PTR   ' SEC_CHAR * // Comment
END TYPE

MACRO SecPkgInfo = SecPkgInfoA

'//
'//  Security Package Capabilities
'//
%SECPKG_FLAG_INTEGRITY              = &H00000001???   ' // Supports integrity on messages
%SECPKG_FLAG_PRIVACY                = &H00000002???   ' // Supports privacy (confidentiality)
%SECPKG_FLAG_TOKEN_ONLY             = &H00000004???   ' // Only security token needed
%SECPKG_FLAG_DATAGRAM               = &H00000008???   ' // Datagram RPC support
%SECPKG_FLAG_CONNECTION             = &H00000010???   ' // Connection oriented RPC support
%SECPKG_FLAG_MULTI_REQUIRED         = &H00000020???   ' // Full 3-leg required for re-auth.
%SECPKG_FLAG_CLIENT_ONLY            = &H00000040???   ' // Server side functionality not available
%SECPKG_FLAG_EXTENDED_ERROR         = &H00000080???   ' // Supports extended error msgs
%SECPKG_FLAG_IMPERSONATION          = &H00000100???   ' // Supports impersonation
%SECPKG_FLAG_ACCEPT_WIN32_NAME      = &H00000200???   ' // Accepts Win32 names
%SECPKG_FLAG_STREAM                 = &H00000400???   ' // Supports stream semantics
%SECPKG_FLAG_NEGOTIABLE             = &H00000800???   ' // Can be used by the negotiate package
%SECPKG_FLAG_GSS_COMPATIBLE         = &H00001000???   ' // GSS Compatibility Available
%SECPKG_FLAG_LOGON                  = &H00002000???   ' // Supports common LsaLogonUser
%SECPKG_FLAG_ASCII_BUFFERS          = &H00004000???   ' // Token Buffers are in ASCII
%SECPKG_FLAG_FRAGMENT               = &H00008000???   ' // Package can fragment to fit
%SECPKG_FLAG_MUTUAL_AUTH            = &H00010000???   ' // Package can perform mutual authentication
%SECPKG_FLAG_DELEGATION             = &H00020000???   ' // Package can delegate
%SECPKG_FLAG_READONLY_WITH_CHECKSUM = &H00040000???   ' // Package can delegate
%SECPKG_FLAG_RESTRICTED_TOKENS      = &H00080000???   ' // Package supports restricted callers
%SECPKG_FLAG_NEGO_EXTENDER          = &H00100000???   ' // this package extends SPNEGO, there is at most one
%SECPKG_FLAG_NEGOTIABLE2            = &H00200000???   ' // this package is negotiated under the NegoExtender

%SECPKG_ID_NONE      = &HFFFF??


'//
'// SecBuffer
'//
'//  Generic memory descriptors for buffers passed in to the security
'//  API
'//

' // Size = 12 bytes
TYPE SecBuffer DWORD
   cbBuffer   AS DWORD   ' unsigned long // Size of the buffer, in bytes
   BufferType AS DWORD   ' unsigned long // Type of the buffer (below)
   pvBuffer   AS DWORD   ' __field_bcount(cbBuffer) void SEC_FAR * // Pointer to the buffer
END TYPE

' // Size = 12 bytes
TYPE SecBufferDesc DWORD
   ulVersion AS DWORD           ' unsigned long // Version number
   cBuffers  AS DWORD           ' unsigned long // Number of buffers
   pBuffers  AS SecBuffer PTR   ' PSecBuffer // Pointer to array of buffers
END TYPE

%SECBUFFER_VERSION                = 0

%SECBUFFER_EMPTY                  = 0               ' // Undefined, replaced by provider
%SECBUFFER_DATA                   = 1               ' // Packet data
%SECBUFFER_TOKEN                  = 2               ' // Security token
%SECBUFFER_PKG_PARAMS             = 3               ' // Package specific parameters
%SECBUFFER_MISSING                = 4               ' // Missing Data indicator
%SECBUFFER_EXTRA                  = 5               ' // Extra data
%SECBUFFER_STREAM_TRAILER         = 6               ' // Security Trailer
%SECBUFFER_STREAM_HEADER          = 7               ' // Security Header
%SECBUFFER_NEGOTIATION_INFO       = 8               ' // Hints from the negotiation pkg
%SECBUFFER_PADDING                = 9               ' // non-data padding
%SECBUFFER_STREAM                 = 10              ' // whole encrypted message
%SECBUFFER_MECHLIST               = 11
%SECBUFFER_MECHLIST_SIGNATURE     = 12
%SECBUFFER_TARGET                 = 13              ' // obsolete
%SECBUFFER_CHANNEL_BINDINGS       = 14
%SECBUFFER_CHANGE_PASS_RESPONSE   = 15
%SECBUFFER_TARGET_HOST            = 16
%SECBUFFER_ALERT                  = 17

%SECBUFFER_ATTRMASK               = &HF0000000???
%SECBUFFER_READONLY               = &H80000000???   ' // Buffer is read-only, no checksum
%SECBUFFER_READONLY_WITH_CHECKSUM = &H10000000???   ' // Buffer is read-only, and checksummed
%SECBUFFER_RESERVED               = &H60000000???   ' // Flags reserved to security system

' // Size = 16 bytes
TYPE SEC_NEGOTIATION_INFO DWORD
   Size       AS DWORD          ' unsigned long // Size of this structure
   NameLength AS DWORD          ' unsigned long // Length of name hint
   Name       AS WSTRINGZ PTR   ' SEC_WCHAR * // Name hint
   Reserved   AS DWORD          ' void * // Reserved
END TYPE

' // Size = 32 bytes
TYPE SEC_CHANNEL_BINDINGS DWORD
   dwInitiatorAddrType     AS DWORD   ' unsigned long
   cbInitiatorLength       AS DWORD   ' unsigned long
   dwInitiatorOffset       AS DWORD   ' unsigned long
   dwAcceptorAddrType      AS DWORD   ' unsigned long
   cbAcceptorLength        AS DWORD   ' unsigned long
   dwAcceptorOffset        AS DWORD   ' unsigned long
   cbApplicationDataLength AS DWORD   ' unsigned long
   dwApplicationDataOffset AS DWORD   ' unsigned long
END TYPE


'//
'//  Data Representation Constant:
'//
%SECURITY_NATIVE_DREP            = &H00000010???
%SECURITY_NETWORK_DREP           = &H00000000???

'//
'//  Credential Use Flags
'//
%SECPKG_CRED_INBOUND             = &H00000001???
%SECPKG_CRED_OUTBOUND            = &H00000002???
%SECPKG_CRED_BOTH                = &H00000003???
%SECPKG_CRED_DEFAULT             = &H00000004???
%SECPKG_CRED_RESERVED            = &HF0000000???

'//
'//  SSP SHOULD prompt the user for credentials/consent, independent
'//  of whether credentials to be used are the 'logged on' credentials
'//  or retrieved from credman.
'//
'//  An SSP may choose not to prompt, however, in circumstances determined
'//  by the SSP.
'//

%SECPKG_CRED_AUTOLOGON_RESTRICTED    = &H00000010???

'//
'// auth will always fail, ISC() is called to process policy data only
'//

%SECPKG_CRED_PROCESS_POLICY_ONLY     = &H00000020???

'//
'//  InitializeSecurityContext Requirement and return flags:
'//

%ISC_REQ_DELEGATE                = &H00000001???
%ISC_REQ_MUTUAL_AUTH             = &H00000002???
%ISC_REQ_REPLAY_DETECT           = &H00000004???
%ISC_REQ_SEQUENCE_DETECT         = &H00000008???
%ISC_REQ_CONFIDENTIALITY         = &H00000010???
%ISC_REQ_USE_SESSION_KEY         = &H00000020???
%ISC_REQ_PROMPT_FOR_CREDS        = &H00000040???
%ISC_REQ_USE_SUPPLIED_CREDS      = &H00000080???
%ISC_REQ_ALLOCATE_MEMORY         = &H00000100???
%ISC_REQ_USE_DCE_STYLE           = &H00000200???
%ISC_REQ_DATAGRAM                = &H00000400???
%ISC_REQ_CONNECTION              = &H00000800???
%ISC_REQ_CALL_LEVEL              = &H00001000???
%ISC_REQ_FRAGMENT_SUPPLIED       = &H00002000???
%ISC_REQ_EXTENDED_ERROR          = &H00004000???
%ISC_REQ_STREAM                  = &H00008000???
%ISC_REQ_INTEGRITY               = &H00010000???
%ISC_REQ_IDENTIFY                = &H00020000???
%ISC_REQ_NULL_SESSION            = &H00040000???
%ISC_REQ_MANUAL_CRED_VALIDATION  = &H00080000???
%ISC_REQ_RESERVED1               = &H00100000???
%ISC_REQ_FRAGMENT_TO_FIT         = &H00200000???
'// This exists only in Windows Vista and greater
%ISC_REQ_FORWARD_CREDENTIALS     = &H00400000???
%ISC_REQ_NO_INTEGRITY            = &H00800000???   ' // honored only by SPNEGO
%ISC_REQ_USE_HTTP_STYLE          = &H01000000???

%ISC_RET_DELEGATE                = &H00000001???
%ISC_RET_MUTUAL_AUTH             = &H00000002???
%ISC_RET_REPLAY_DETECT           = &H00000004???
%ISC_RET_SEQUENCE_DETECT         = &H00000008???
%ISC_RET_CONFIDENTIALITY         = &H00000010???
%ISC_RET_USE_SESSION_KEY         = &H00000020???
%ISC_RET_USED_COLLECTED_CREDS    = &H00000040???
%ISC_RET_USED_SUPPLIED_CREDS     = &H00000080???
%ISC_RET_ALLOCATED_MEMORY        = &H00000100???
%ISC_RET_USED_DCE_STYLE          = &H00000200???
%ISC_RET_DATAGRAM                = &H00000400???
%ISC_RET_CONNECTION              = &H00000800???
%ISC_RET_INTERMEDIATE_RETURN     = &H00001000???
%ISC_RET_CALL_LEVEL              = &H00002000???
%ISC_RET_EXTENDED_ERROR          = &H00004000???
%ISC_RET_STREAM                  = &H00008000???
%ISC_RET_INTEGRITY               = &H00010000???
%ISC_RET_IDENTIFY                = &H00020000???
%ISC_RET_NULL_SESSION            = &H00040000???
%ISC_RET_MANUAL_CRED_VALIDATION  = &H00080000???
%ISC_RET_RESERVED1               = &H00100000???
%ISC_RET_FRAGMENT_ONLY           = &H00200000???
'// This exists only in Windows Vista and greater
%ISC_RET_FORWARD_CREDENTIALS     = &H00400000???

%ISC_RET_USED_HTTP_STYLE         = &H01000000???
%ISC_RET_NO_ADDITIONAL_TOKEN     = &H02000000???   ' // *INTERNAL*
%ISC_RET_REAUTHENTICATION        = &H08000000???   ' // *INTERNAL*

%ASC_REQ_DELEGATE                = &H00000001???
%ASC_REQ_MUTUAL_AUTH             = &H00000002???
%ASC_REQ_REPLAY_DETECT           = &H00000004???
%ASC_REQ_SEQUENCE_DETECT         = &H00000008???
%ASC_REQ_CONFIDENTIALITY         = &H00000010???
%ASC_REQ_USE_SESSION_KEY         = &H00000020???
%ASC_REQ_ALLOCATE_MEMORY         = &H00000100???
%ASC_REQ_USE_DCE_STYLE           = &H00000200???
%ASC_REQ_DATAGRAM                = &H00000400???
%ASC_REQ_CONNECTION              = &H00000800???
%ASC_REQ_CALL_LEVEL              = &H00001000???
%ASC_REQ_EXTENDED_ERROR          = &H00008000???
%ASC_REQ_STREAM                  = &H00010000???
%ASC_REQ_INTEGRITY               = &H00020000???
%ASC_REQ_LICENSING               = &H00040000???
%ASC_REQ_IDENTIFY                = &H00080000???
%ASC_REQ_ALLOW_NULL_SESSION      = &H00100000???
%ASC_REQ_ALLOW_NON_USER_LOGONS   = &H00200000???
%ASC_REQ_ALLOW_CONTEXT_REPLAY    = &H00400000???
%ASC_REQ_FRAGMENT_TO_FIT         = &H00800000???
%ASC_REQ_FRAGMENT_SUPPLIED       = &H00002000???
%ASC_REQ_NO_TOKEN                = &H01000000???
%ASC_REQ_PROXY_BINDINGS          = &H04000000???
'// SSP_RET_REAUTHENTICATION        = &H08000000???  // *INTERNAL*
%ASC_REQ_ALLOW_MISSING_BINDINGS  = &H10000000???

%ASC_RET_DELEGATE                = &H00000001???
%ASC_RET_MUTUAL_AUTH             = &H00000002???
%ASC_RET_REPLAY_DETECT           = &H00000004???
%ASC_RET_SEQUENCE_DETECT         = &H00000008???
%ASC_RET_CONFIDENTIALITY         = &H00000010???
%ASC_RET_USE_SESSION_KEY         = &H00000020???
%ASC_RET_ALLOCATED_MEMORY        = &H00000100???
%ASC_RET_USED_DCE_STYLE          = &H00000200???
%ASC_RET_DATAGRAM                = &H00000400???
%ASC_RET_CONNECTION              = &H00000800???
%ASC_RET_CALL_LEVEL              = &H00002000???   ' // skipped 1000 to be like ISC_
%ASC_RET_THIRD_LEG_FAILED        = &H00004000???
%ASC_RET_EXTENDED_ERROR          = &H00008000???
%ASC_RET_STREAM                  = &H00010000???
%ASC_RET_INTEGRITY               = &H00020000???
%ASC_RET_LICENSING               = &H00040000???
%ASC_RET_IDENTIFY                = &H00080000???
%ASC_RET_NULL_SESSION            = &H00100000???
%ASC_RET_ALLOW_NON_USER_LOGONS   = &H00200000???
%ASC_RET_ALLOW_CONTEXT_REPLAY    = &H00400000???   ' // deprecated - don't use this flag!!!
%ASC_RET_FRAGMENT_ONLY           = &H00800000???
%ASC_RET_NO_TOKEN                = &H01000000???
%ASC_RET_NO_ADDITIONAL_TOKEN     = &H02000000???   ' // *INTERNAL*
%ASC_RET_NO_PROXY_BINDINGS       = &H04000000???
'// SSP_RET_REAUTHENTICATION        = &H08000000???  // *INTERNAL*
%ASC_RET_MISSING_BINDINGS        = &H10000000???

'//
'//  Security Credentials Attributes:
'//

%SECPKG_CRED_ATTR_NAMES          = 1
%SECPKG_CRED_ATTR_SSI_PROVIDER   = 2

' // Size = 4 bytes
TYPE SecPkgCredentials_NamesW DWORD
   sUserName AS WSTRINGZ PTR   ' SEC_WCHAR *
END TYPE

' // Size = 4 bytes
TYPE SecPkgCredentials_NamesA DWORD
   sUserName AS ASCIIZ PTR   ' SEC_CHAR *
END TYPE

MACRO SecPkgCredentials_Names = SecPkgCredentials_NamesA

'#if NTDDI_VERSION > NTDDI_WS03
' // Size = 12 bytes
TYPE SecPkgCredentials_SSIProviderW DWORD
   sProviderName      AS WSTRINGZ PTR   ' SEC_WCHAR *
   ProviderInfoLength AS DWORD          ' unsigned long
   ProviderInfo       AS ASCIIZ PTR     ' char *
END TYPE
'#endif // End W2k3SP1 and greater

' // Size = 12 bytes
TYPE SecPkgCredentials_SSIProviderA DWORD
   sProviderName      AS ASCIIZ PTR   ' SEC_CHAR *
   ProviderInfoLength AS DWORD        ' unsigned long
   ProviderInfo       AS ASCIIZ PTR   ' char *
END TYPE

MACRO SecPkgCredentials_SSIProvider = SecPkgCredentials_SSIProviderA

'//
'//  Security Context Attributes:
'//

%SECPKG_ATTR_SIZES              = 0
%SECPKG_ATTR_NAMES              = 1
%SECPKG_ATTR_LIFESPAN           = 2
%SECPKG_ATTR_DCE_INFO           = 3
%SECPKG_ATTR_STREAM_SIZES       = 4
%SECPKG_ATTR_KEY_INFO           = 5
%SECPKG_ATTR_AUTHORITY          = 6
%SECPKG_ATTR_PROTO_INFO         = 7
%SECPKG_ATTR_PASSWORD_EXPIRY    = 8
%SECPKG_ATTR_SESSION_KEY        = 9
%SECPKG_ATTR_PACKAGE_INFO       = 10
%SECPKG_ATTR_USER_FLAGS         = 11
%SECPKG_ATTR_NEGOTIATION_INFO   = 12
%SECPKG_ATTR_NATIVE_NAMES       = 13
%SECPKG_ATTR_FLAGS              = 14
'// These attributes exist only in Win XP and greater
%SECPKG_ATTR_USE_VALIDATED      = 15
%SECPKG_ATTR_CREDENTIAL_NAME    = 16
%SECPKG_ATTR_TARGET_INFORMATION = 17
%SECPKG_ATTR_ACCESS_TOKEN       = 18
'// These attributes exist only in Win2K3 and greater
%SECPKG_ATTR_TARGET             = 19
%SECPKG_ATTR_AUTHENTICATION_ID  = 20
'// These attributes exist only in Win2K3SP1 and greater
%SECPKG_ATTR_LOGOFF_TIME        = 21

'//
'// win7 or greater
'//
%SECPKG_ATTR_NEGO_KEYS         = 22
%SECPKG_ATTR_PROMPTING_NEEDED  = 24
%SECPKG_ATTR_UNIQUE_BINDINGS   = 25
%SECPKG_ATTR_ENDPOINT_BINDINGS = 26
%SECPKG_ATTR_CLIENT_SPECIFIED_TARGET = 27

%SECPKG_ATTR_LAST_CLIENT_TOKEN_STATUS = 30
%SECPKG_ATTR_NEGO_PKG_INFO        = 31   ' // contains nego info of packages
%SECPKG_ATTR_NEGO_STATUS          = 32   ' // contains the last error
%SECPKG_ATTR_CONTEXT_DELETED      = 33   ' // a context has been deleted

%SECPKG_ATTR_SUBJECT_SECURITY_ATTRIBUTES = 128

' // Size = 4 bytes
TYPE SecPkgContext_SubjectAttributes DWORD
   AttributeInfo AS DWORD   ' void *  ' // contains a PAUTHZ_SECURITY_ATTRIBUTES_INFORMATION structure
END TYPE

%SECPKG_ATTR_NEGO_INFO_FLAG_NO_KERBEROS = &H1
%SECPKG_ATTR_NEGO_INFO_FLAG_NO_NTLM     = &H2

'//
'// types of credentials, used by SECPKG_ATTR_PROMPTING_NEEDED
'//

' enum SECPKG_CRED_CLASS
%SecPkgCredClass_None              = 0    ' // no creds
%SecPkgCredClass_Ephemeral         = 10   ' // logon creds
%SecPkgCredClass_PersistedGeneric  = 20   ' // saved creds, not target specific
%SecPkgCredClass_PersistedSpecific = 30   ' // saved creds, target specific
%SecPkgCredClass_Explicit          = 40   ' // explicitly supplied creds

' // Size = 8 bytes
TYPE SecPkgContext_CredInfo DWORD
   CredClass         AS LONG    ' SECPKG_CRED_CLASS
   IsPromptingNeeded AS DWORD   ' unsigned long
END TYPE

' // Size = 4 bytes
TYPE SecPkgContext_NegoPackageInfo DWORD
   PackageMask AS DWORD   ' unsigned long
END TYPE

' // Size = 4 bytes
TYPE SecPkgContext_NegoStatus DWORD
   LastStatus AS DWORD   ' unsigned long
END TYPE

' // Size = 16 bytes
TYPE SecPkgContext_Sizes DWORD
   cbMaxToken        AS DWORD   ' unsigned long
   cbMaxSignature    AS DWORD   ' unsigned long
   cbBlockSize       AS DWORD   ' unsigned long
   cbSecurityTrailer AS DWORD   ' unsigned long
END TYPE

' // Size = 20 bytes
TYPE SecPkgContext_StreamSizes DWORD
   cbHeader         AS DWORD   ' unsigned long
   cbTrailer        AS DWORD   ' unsigned long
   cbMaximumMessage AS DWORD   ' unsigned long
   cBuffers         AS DWORD   ' unsigned long
   cbBlockSize      AS DWORD   ' unsigned long
END TYPE

' // Size = 4 bytes
TYPE SecPkgContext_NamesW DWORD
   sUserName AS WSTRINGZ PTR   ' SEC_WCHAR *
END TYPE

' enum _SECPKG_ATTR_LCT_STATUS
%SecPkgAttrLastClientTokenYes = 0
%SecPkgAttrLastClientTokenNo = 1
%SecPkgAttrLastClientTokenMaybe = 2

' // Size = 4 bytes
TYPE SecPkgContext_LastClientTokenStatus DWORD
   LastClientTokenStatus AS LONG   ' SECPKG_ATTR_LCT_STATUS
END TYPE

' // Size = 4 bytes
TYPE SecPkgContext_NamesA DWORD
   sUserName AS ASCIIZ PTR   ' SEC_CHAR *
END TYPE

MACRO SecPkgContext_Names = SecPkgContext_NamesA

' // Size = 16 bytes
TYPE SecPkgContext_Lifespan QWORD
   tsStart  AS QUAD   ' TimeStamp
   tsExpiry AS QUAD   ' TimeStamp
END TYPE

' // Size = 8 bytes
TYPE SecPkgContext_DceInfo DWORD
   AuthzSvc AS DWORD   ' unsigned long
   pPac     AS DWORD   ' void *
END TYPE

' // Size = 20 bytes
TYPE SecPkgContext_KeyInfoA DWORD
   sSignatureAlgorithmName AS ASCIIZ PTR   ' SEC_CHAR *
   sEncryptAlgorithmName   AS ASCIIZ PTR   ' SEC_CHAR *
   KeySize                 AS DWORD        ' unsigned long
   SignatureAlgorithm      AS DWORD        ' unsigned long
   EncryptAlgorithm        AS DWORD        ' unsigned long
END TYPE

' // Size = 20 bytes
TYPE SecPkgContext_KeyInfoW DWORD
   sSignatureAlgorithmName AS WSTRINGZ PTR   ' SEC_WCHAR *
   sEncryptAlgorithmName   AS WSTRINGZ PTR   ' SEC_WCHAR *
   KeySize                 AS DWORD          ' unsigned long
   SignatureAlgorithm      AS DWORD          ' unsigned long
   EncryptAlgorithm        AS DWORD          ' unsigned long
END TYPE

MACRO SecPkgContext_KeyInfo = SecPkgContext_KeyInfoA

' // Size = 4 bytes
TYPE SecPkgContext_AuthorityA DWORD
   sAuthorityName AS ASCIIZ PTR   ' SEC_CHAR *
END TYPE

' // Size = 4 bytes
TYPE SecPkgContext_AuthorityW DWORD
   sAuthorityName AS WSTRINGZ PTR   ' SEC_WCHAR *
END TYPE

MACRO SecPkgContext_Authority = SecPkgContext_AuthorityA

' // Size = 12 bytes
TYPE SecPkgContext_ProtoInfoA DWORD
   sProtocolName AS ASCIIZ PTR   ' SEC_CHAR *
   majorVersion  AS DWORD        ' unsigned long
   minorVersion  AS DWORD        ' unsigned long
END TYPE

' // Size = 12 bytes
TYPE SecPkgContext_ProtoInfoW DWORD
   sProtocolName AS WSTRINGZ PTR   ' SEC_WCHAR *
   majorVersion  AS DWORD          ' unsigned long
   minorVersion  AS DWORD          ' unsigned long
END TYPE

MACRO SecPkgContext_ProtoInfo = SecPkgContext_ProtoInfoA

' // Size = 8 bytes
TYPE SecPkgContext_PasswordExpiry QWORD
   tsPasswordExpires AS QUAD   ' TimeStamp
END TYPE

'#if NTDDI_VERSION > NTDDI_WS03
' // Size = 8 bytes
TYPE SecPkgContext_LogoffTime QWORD
   tsLogoffTime AS QUAD   ' TimeStamp
END TYPE
'#endif // Greater than Windows Server 2003 RTM (SP1 and greater contains this)

' // Size = 8 bytes
TYPE SecPkgContext_SessionKey DWORD
   SessionKeyLength AS DWORD      ' unsigned long
   SessionKey       AS BYTE PTR   ' unsigned char *
END TYPE

'// used by nego2
' // Size = 24 bytes
TYPE SecPkgContext_NegoKeys DWORD
   KeyType         AS DWORD        ' unsigned long
   KeyLength       AS WORD         ' unsigned short
   KeyValue        AS BYTE PTR     ' __field_bcount(KeyLength) unsigned char*
   VerifyKeyType   AS DWORD        ' unsigned long
   VerifyKeyLength AS WORD         ' unsigned short
   VerifyKeyValue  AS BYTE PTR     ' __field_bcount(VerifyKeyLength) unsigned char*
END TYPE

' // Size = 4 bytes
TYPE SecPkgContext_PackageInfoW DWORD
   PackageInfo AS SecPkgInfoW PTR   ' PSecPkgInfoW
END TYPE

' // Size = 4 bytes
TYPE SecPkgContext_PackageInfoA DWORD
   PackageInfo AS SecPkgInfoA PTR   ' PSecPkgInfoA
END TYPE

MACRO SecPkgContext_PackageInfo = SecPkgContext_PackageInfoA

' // Size = 4 bytes
TYPE SecPkgContext_UserFlags DWORD
   UserFlags AS DWORD   ' unsigned long
END TYPE

' // Size = 4 bytes
TYPE SecPkgContext_Flags DWORD
   Flags AS DWORD   ' unsigned long
END TYPE

' // Size = 8 bytes
TYPE SecPkgContext_NegotiationInfoA DWORD
   PackageInfo      AS SecPkgInfoA PTR   ' PSecPkgInfoA
   NegotiationState AS DWORD             ' unsigned long
END TYPE

' // Size = 8 bytes
TYPE SecPkgContext_NegotiationInfoW DWORD
   PackageInfo      AS SecPkgInfoW PTR   ' PSecPkgInfoW
   NegotiationState AS DWORD             ' unsigned long
END TYPE

MACRO SecPkgContext_NegotiationInfo = SecPkgContext_NegotiationInfoA

%SECPKG_NEGOTIATION_COMPLETE      = 0
%SECPKG_NEGOTIATION_OPTIMISTIC    = 1
%SECPKG_NEGOTIATION_IN_PROGRESS   = 2
%SECPKG_NEGOTIATION_DIRECT        = 3
%SECPKG_NEGOTIATION_TRY_MULTICRED = 4

' // Size = 8 bytes
TYPE SecPkgContext_NativeNamesW DWORD
   sClientName AS WSTRINGZ PTR   ' SEC_WCHAR *
   sServerName AS WSTRINGZ PTR   ' SEC_WCHAR *
END TYPE

' // Size = 8 bytes
TYPE SecPkgContext_NativeNamesA DWORD
   sClientName AS ASCIIZ PTR   ' SEC_CHAR *
   sServerName AS ASCIIZ PTR   ' SEC_CHAR *
END TYPE

MACRO SecPkgContext_NativeNames = SecPkgContext_NativeNamesA

'#if OSVER(NTDDI_VERSION) > NTDDI_WIN2K
' // Size = 8 bytes
TYPE SecPkgContext_CredentialNameW DWORD
   CredentialType  AS DWORD          ' unsigned long
   sCredentialName AS WSTRINGZ PTR   ' SEC_WCHAR *
END TYPE
'#endif // Later than win2k

' // Size = 8 bytes
TYPE SecPkgContext_CredentialNameA DWORD
   CredentialType  AS DWORD        ' unsigned long
   sCredentialName AS ASCIIZ PTR   ' SEC_CHAR *
END TYPE

MACRO SecPkgContext_CredentialName = SecPkgContext_CredentialNameA

' // Size = 4 bytes
TYPE SecPkgContext_AccessToken DWORD
   AccessToken AS DWORD   ' void *
END TYPE

' // Size = 8 bytes
TYPE SecPkgContext_TargetInformation DWORD
   MarshalledTargetInfoLength AS DWORD      ' unsigned long
   MarshalledTargetInfo       AS BYTE PTR   ' unsigned char *
END TYPE

' // Size = 8 bytes
TYPE SecPkgContext_AuthzID DWORD
   AuthzIDLength AS DWORD        ' unsigned long
   AuthzID       AS ASCIIZ PTR   ' char *
END TYPE

' // Size = 8 bytes
TYPE SecPkgContext_Target DWORD
   TargetLength AS DWORD        ' unsigned long
   Target       AS ASCIIZ PTR   ' char *
END TYPE

' // Size = 4 bytes
TYPE SecPkgContext_ClientSpecifiedTarget DWORD
   sTargetName AS WSTRINGZ PTR   ' SEC_WCHAR *
END TYPE

' // Size = 8 bytes
TYPE SecPkgContext_Bindings DWORD
   BindingsLength AS DWORD                      ' unsigned long
   Bindings       AS SEC_CHANNEL_BINDINGS PTR   ' __field_bcount(BindingsLength) SEC_CHANNEL_BINDINGS * Bindings
END TYPE

'typedef void
'(SEC_ENTRY * SEC_GET_KEY_FN) (
'    void * Arg,                 // Argument passed in
'    void * Principal,           // Principal ID
'    unsigned long KeyVer,               // Key Version
'    void * * Key,       // Returned ptr to key
'    SECURITY_STATUS * Status    // returned status
'    );

'//
'// Flags for ExportSecurityContext
'//

%SECPKG_CONTEXT_EXPORT_RESET_NEW  = &H00000001   ' // New context is reset to initial state
%SECPKG_CONTEXT_EXPORT_DELETE_OLD = &H00000002   ' // Old context is deleted during export
'// This is only valid in W2K3SP1 and greater
%SECPKG_CONTEXT_EXPORT_TO_KERNEL  = &H00000004   ' // Context is to be transferred to the kernel

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION AcquireCredentialsHandleW LIB "Secur32.dll" _
    ALIAS "AcquireCredentialsHandleW" ( _
    pszPrincipal         AS WSTRINGZ, _    ' Name of principal
    pszPackage           AS WSTRINGZ, _    ' Name of package
    BYVAL fCredentialUse AS DWORD, _       ' Flags indicating use
    pvLogonId            AS ANY, _         ' void ptr  ' Pointer to logon ID
    pAuthData            AS ANY, _         ' void ptr  ' Package specific data
    BYVAL pGetKeyFn      AS DWORD, _       ' SEC_GET_KEY_FN  ' Pointer to GetKey() func
    pvGetKeyArgument     AS ANY, _         ' void ptr  ' Value to pass to GetKey()
    phCredential         AS CredHandle, _  ' (out) Cred Handle
    ptsExpiry            AS ANY _          ' (out) Lifetime (optional)
    ) AS LONG
#ELSE
DECLARE FUNCTION AcquireCredentialsHandleW IMPORT "SECUR32.DLL" ALIAS "AcquireCredentialsHandleW" ( _
   BYREF pszPrincipal AS WSTRINGZ _                     ' __in_opt  LPWSTR pszPrincipal            // Name of principal
 , BYREF pszPackage AS WSTRINGZ _                       ' __in      LPWSTR pszPackage              // Name of package
 , BYVAL fCredentialUse AS DWORD _                      ' __in      unsigned long fCredentialUse   // Flags indicating use
 , BYREF pvLogonId AS ANY _                             ' __in_opt  void * pvLogonId               // Pointer to logon ID
 , BYREF pAuthData AS ANY _                             ' __in_opt  void * pAuthData               // Package specific data
 , BYVAL pGetKeyFn AS DWORD _                           ' __in_opt  SEC_GET_KEY_FN pGetKeyFn       // Pointer to GetKey() func // This parameter is not used and should be set to NULL.
 , BYVAL pvGetKeyArgument AS DWORD _                    ' __in_opt  void * pvGetKeyArgument        // Value to pass to GetKey() // This parameter is not used and should be set to NULL.
 , BYREF phCredential AS ANY _                          ' __out     PCredHandle phCredential       // (out) Cred Handle
 , BYREF ptsExpiry AS ANY _                             ' __out_opt PTimeStamp ptsExpiry           // (out) Lifetime (optional)
 ) AS LONG                                              ' SECURITY_STATUS
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION AcquireCredentialsHandleA LIB "Secur32.dll" _
    ALIAS "AcquireCredentialsHandleA" ( _
    pszPrincipal         AS ASCIIZ, _      ' Name of principal
    pszPackage           AS ASCIIZ, _      ' Name of package
    BYVAL fCredentialUse AS DWORD, _       ' Flags indicating use
    pvLogonId            AS ANY, _         ' void ptr ' Pointer to logon ID
    pAuthData            AS ANY, _         ' void ptr ' Package specific data
    BYVAL pGetKeyFn      AS DWORD, _       ' SEC_GET_KEY_FN ' Pointer to GetKey() func
    pvGetKeyArgument     AS ANY, _         ' void ptr ' Value to pass to GetKey()
    phCredential         AS CredHandle, _  ' (out) Cred Handle
    ptsExpiry            AS ANY _          ' (out) Lifetime (optional)
    ) AS LONG
#ELSE
DECLARE FUNCTION AcquireCredentialsHandleA IMPORT "SECUR32.DLL" ALIAS "AcquireCredentialsHandleA" ( _
   BYREF pszPrincipal AS ASCIIZ _                       ' __in_opt  LPSTR pszPrincipal  // Name of principal
 , BYREF pszPackage AS ASCIIZ _                         ' __in      LPSTR pszPackage    // Name of package
 , BYVAL fCredentialUse AS DWORD _                      ' __in      unsigned long fCredentialUse     // Flags indicating use
 , BYREF pvLogonId AS ANY _                             ' __in_opt  void * pvLogonId         // Pointer to logon ID
 , BYREF pAuthData AS ANY _                             ' __in_opt  void * pAuthData         // Package specific data
 , BYVAL pGetKeyFn AS DWORD _                           ' __in_opt  SEC_GET_KEY_FN pGetKeyFn         // Pointer to GetKey() func // This parameter is not used and should be set to NULL.
 , BYVAL pvGetKeyArgument AS DWORD _                    ' __in_opt  void * pvGetKeyArgument  // Value to pass to GetKey() // This parameter is not used and should be set to NULL.
 , BYREF phCredential AS ANY _                          ' __out     PCredHandle phCredential         // (out) Cred Handle
 , BYREF ptsExpiry AS ANY _                             ' __out_opt PTimeStamp ptsExpiry             // (out) Lifetime (optional)
 ) AS LONG                                              ' SECURITY_STATUS
#ENDIF

#IF %DEF(%UNICODE)
   MACRO AcquireCredentialsHandle = AcquireCredentialsHandleW
#ELSE
   MACRO AcquireCredentialsHandle = AcquireCredentialsHandleA
#ENDIF

DECLARE FUNCTION FreeCredentialsHandle IMPORT "SECUR32.DLL" ALIAS "FreeCredentialsHandle" ( _
   BYREF phCredential AS ANY _                          ' __in PCredHandle phCredential // Handle to free
 ) AS LONG                                              ' SECURITY_STATUS

DECLARE FUNCTION AddCredentialsW IMPORT "SECUR32.DLL" ALIAS "AddCredentialsW" ( _
   BYREF hCredentials AS ANY _                          ' __in      PCredHandle hCredentials
 , BYREF pszPrincipal AS WSTRINGZ _                     ' __in_opt  LPWSTR pszPrincipal // Name of principal
 , BYREF pszPackage AS WSTRINGZ _                       ' __in      LPWSTR pszPackage   // Name of package
 , BYVAL fCredentialUse AS DWORD _                      ' __in      unsigned long fCredentialUse     // Flags indicating use
 , BYREF pAuthData AS ANY _                             ' __in_opt  void * pAuthData         // Package specific data
 , BYVAL pGetKeyFn AS DWORD _                           ' __in_opt  SEC_GET_KEY_FN pGetKeyFn         // Pointer to GetKey() func
 , BYVAL pvGetKeyArgument AS DWORD _                    ' __in_opt  void * pvGetKeyArgument  // Value to pass to GetKey()
 , BYREF ptsExpiry AS ANY _                             ' __out_opt PTimeStamp ptsExpiry             // (out) Lifetime (optional)
 ) AS LONG                                              ' SECURITY_STATUS

DECLARE FUNCTION AddCredentialsA IMPORT "SECUR32.DLL" ALIAS "AddCredentialsA" ( _
   BYREF hCredentials AS ANY _                          ' __in      PCredHandle hCredentials
 , BYREF pszPrincipal AS ASCIIZ _                       ' __in_opt  LPSTR pszPrincipal  // Name of principal
 , BYREF pszPackage AS ASCIIZ _                         ' __in      LPSTR pszPackage    // Name of package
 , BYVAL fCredentialUse AS DWORD _                      ' __in      unsigned long fCredentialUse     // Flags indicating use
 , BYREF pAuthData AS ANY _                             ' __in_opt  void * pAuthData         // Package specific data
 , BYVAL pGetKeyFn AS DWORD _                           ' __in_opt  SEC_GET_KEY_FN pGetKeyFn         // Pointer to GetKey() func
 , BYVAL pvGetKeyArgument AS DWORD _                    ' __in_opt  void * pvGetKeyArgument  // Value to pass to GetKey()
 , BYREF ptsExpiry AS ANY _                             ' __out_opt PTimeStamp ptsExpiry             // (out) Lifetime (optional)
 ) AS LONG                                              ' SECURITY_STATUS

#IF %DEF(%UNICODE)
   MACRO AddCredentials = AddCredentialsW
#ELSE
   MACRO AddCredentials = AddCredentialsA
#ENDIF

'////////////////////////////////////////////////////////////////////////
'///
'/// Password Change Functions
'///
'////////////////////////////////////////////////////////////////////////

'#if ISSP_MODE != 0

DECLARE FUNCTION ChangeAccountPasswordW IMPORT "SECUR32.DLL" ALIAS "ChangeAccountPasswordW" ( _
   BYREF pszPackageName AS WSTRINGZ _                   ' __in    SEC_WCHAR *    pszPackageName
 , BYREF pszDomainName AS WSTRINGZ _                    ' __in    SEC_WCHAR *    pszDomainName
 , BYREF pszAccountName AS WSTRINGZ _                   ' __in    SEC_WCHAR *    pszAccountName
 , BYREF pszOldPassword AS WSTRINGZ _                   ' __in    SEC_WCHAR *    pszOldPassword
 , BYREF pszNewPassword AS WSTRINGZ _                   ' __in    SEC_WCHAR *    pszNewPassword
 , BYVAL bImpersonating AS BYTE _                       ' __in    BOOLEAN        bImpersonating
 , BYVAL dwReserved AS DWORD _                          ' __in    unsigned long  dwReserved
 , BYREF pOutput AS SecBufferDesc _                     ' __inout PSecBufferDesc pOutput
 ) AS LONG                                              ' SECURITY_STATUS

DECLARE FUNCTION ChangeAccountPasswordA IMPORT "SECUR32.DLL" ALIAS "ChangeAccountPasswordA" ( _
   BYREF pszPackageName AS ASCIIZ _                     ' __in    SEC_CHAR *     pszPackageName
 , BYREF pszDomainName AS ASCIIZ _                      ' __in    SEC_CHAR *     pszDomainName
 , BYREF pszAccountName AS ASCIIZ _                     ' __in    SEC_CHAR *     pszAccountName
 , BYREF pszOldPassword AS ASCIIZ _                     ' __in    SEC_CHAR *     pszOldPassword
 , BYREF pszNewPassword AS ASCIIZ _                     ' __in    SEC_CHAR *     pszNewPassword
 , BYVAL bImpersonating AS BYTE _                       ' __in    BOOLEAN        bImpersonating
 , BYVAL dwReserved AS DWORD _                          ' __in    unsigned long  dwReserved
 , BYREF pOutput AS SecBufferDesc _                     ' __inout PSecBufferDesc pOutput
 ) AS LONG                                              ' SECURITY_STATUS

#IF %DEF(%UNICODE)
   MACRO ChangeAccountPassword = ChangeAccountPasswordW
#ELSE
   MACRO ChangeAccountPassword = ChangeAccountPasswordA
#ENDIF

'#endif // ISSP_MODE


'////////////////////////////////////////////////////////////////////////
'///
'/// Context Management Functions
'///
'////////////////////////////////////////////////////////////////////////

DECLARE FUNCTION InitializeSecurityContextW IMPORT "SECUR32.DLL" ALIAS "InitializeSecurityContextW" ( _
   BYREF phCredential AS ANY _                          ' __in_opt    PCredHandle phCredential              // Cred to base context
 , BYREF phContext AS ANY _                             ' __in_opt    PCtxtHandle phContext                 // Existing context (OPT)
 , BYREF pszTargetName AS WSTRINGZ _                    ' __in_opt    SEC_WCHAR * pszTargetName             // Name of target
 , BYVAL fContextReq AS DWORD _                         ' __in        unsigned long fContextReq             // Context Requirements
 , BYVAL Reserved1 AS DWORD _                           ' __in        unsigned long Reserved1               // Reserved, MBZ
 , BYVAL TargetDataRep AS LONG _                        ' __in        unsigned long TargetDataRep           // Data rep of target
 , BYREF pInput AS SecBufferDesc _                      ' __in_opt    PSecBufferDesc pInput                 // Input Buffers
 , BYVAL Reserved2 AS DWORD _                           ' __in        unsigned long Reserved2               // Reserved, MBZ
 , BYREF phNewContext AS ANY _                          ' __inout_opt PCtxtHandle phNewContext              // (out) New Context handle
 , BYREF pOutput AS SecBufferDesc _                     ' __inout_opt PSecBufferDesc pOutput                // (inout) Output Buffers
 , BYREF pfContextAttr AS DWORD _                       ' __out       unsigned long * pfContextAttr         // (out) Context attrs
 , BYREF ptsExpiry AS ANY _                             ' __out_opt   PTimeStamp ptsExpiry                  // (out) Life span (OPT)
 ) AS LONG                                              ' SECURITY_STATUS

DECLARE FUNCTION InitializeSecurityContextA IMPORT "SECUR32.DLL" ALIAS "InitializeSecurityContextA" ( _
   BYREF phCredential AS ANY _                          ' __in_opt    PCredHandle phCredential              // Cred to base context
 , BYREF phContext AS ANY _                             ' __in_opt    PCtxtHandle phContext                 // Existing context (OPT)
 , BYREF pszTargetName AS ASCIIZ _                      ' __in_opt    SEC_CHAR * pszTargetName              // Name of target
 , BYVAL fContextReq AS DWORD _                         ' __in        unsigned long fContextReq             // Context Requirements
 , BYVAL Reserved1 AS DWORD _                           ' __in        unsigned long Reserved1               // Reserved, MBZ
 , BYVAL TargetDataRep AS LONG _                        ' __in        unsigned long TargetDataRep           // Data rep of target
 , BYREF pInput AS SecBufferDesc _                      ' __in_opt    PSecBufferDesc pInput                 // Input Buffers
 , BYVAL Reserved2 AS DWORD _                           ' __in        unsigned long Reserved2               // Reserved, MBZ
 , BYREF phNewContext AS ANY _                          ' __inout_opt PCtxtHandle phNewContext              // (out) New Context handle
 , BYREF pOutput AS SecBufferDesc _                     ' __inout_opt PSecBufferDesc pOutput                // (inout) Output Buffers
 , BYREF pfContextAttr AS DWORD _                       ' __out       unsigned long * pfContextAttr         // (out) Context attrs
 , BYREF ptsExpiry AS ANY _                             ' __out_opt   PTimeStamp ptsExpiry                  // (out) Life span (OPT)
 ) AS LONG                                              ' SECURITY_STATUS

#IF %DEF(%UNICODE)
   MACRO InitializeSecurityContext = InitializeSecurityContextW
#ELSE
   MACRO InitializeSecurityContext = InitializeSecurityContextA
#ENDIF

DECLARE FUNCTION AcceptSecurityContext IMPORT "SECUR32.DLL" ALIAS "AcceptSecurityContext" ( _
   BYREF phCredential AS ANY _                          ' __in_opt  PCredHandle phCredential               // Cred to base context
 , BYREF phContext AS ANY _                             ' __in_opt  PCtxtHandle phContext                  // Existing context (OPT)
 , BYREF pInput AS SecBufferDesc _                      ' __in_opt  PSecBufferDesc pInput                  // Input buffer
 , BYVAL fContextReq AS DWORD _                         ' __in      unsigned long fContextReq              // Context Requirements
 , BYVAL TargetDataRep AS DWORD _                       ' __in      unsigned long TargetDataRep            // Target Data Rep
 , BYREF phNewContext AS ANY _                          ' __in_opt  PCtxtHandle phNewContext               // (out) New context handle
 , BYREF pOutput AS SecBufferDesc _                     ' __in_opt  PSecBufferDesc pOutput                 // (inout) Output buffers
 , BYREF pfContextAttr AS DWORD _                       ' __out     unsigned long * pfContextAttr          // (out) Context attributes
 , BYREF ptsExpiry AS ANY _                             ' __out_opt PTimeStamp ptsExpiry                   // (out) Life span (OPT)
 ) AS LONG                                              ' SECURITY_STATUS

DECLARE FUNCTION CompleteAuthToken IMPORT "SECUR32.DLL" ALIAS "CompleteAuthToken" ( _
   BYREF phContext AS ANY _                             ' __in PCtxtHandle phContext  // Context to complete
 , BYREF pToken AS SecBufferDesc _                      ' __in PSecBufferDesc pToken  // Token to complete
 ) AS LONG                                              ' SECURITY_STATUS

DECLARE FUNCTION ImpersonateSecurityContext IMPORT "SECUR32.DLL" ALIAS "ImpersonateSecurityContext" ( _
   BYREF phContext AS ANY _                             ' __in PCtxtHandle phContext  // Context to complete
 ) AS LONG                                              ' SECURITY_STATUS

DECLARE FUNCTION RevertSecurityContext IMPORT "SECUR32.DLL" ALIAS "RevertSecurityContext" ( _
   BYREF phContext AS ANY _                             ' __in PCtxtHandle phContext  // Context from which to revert
 ) AS LONG                                              ' SECURITY_STATUS

DECLARE FUNCTION QuerySecurityContextToken IMPORT "SECUR32.DLL" ALIAS "QuerySecurityContextToken" ( _
   BYREF phContext AS ANY _                             ' __in  PCtxtHandle phContext
 , BYREF Token AS ANY _                                 ' __out void * * Token
 ) AS LONG                                              ' SECURITY_STATUS

DECLARE FUNCTION DeleteSecurityContext IMPORT "SECUR32.DLL" ALIAS "DeleteSecurityContext" ( _
   BYREF phContext AS ANY _                             ' __in PCtxtHandle phContext  // Context to delete
 ) AS LONG                                              ' SECURITY_STATUS

DECLARE FUNCTION ApplyControlToken IMPORT "SECUR32.DLL" ALIAS "ApplyControlToken" ( _
   BYREF phContext AS ANY _                             ' __in PCtxtHandle phContext  // Context to modify
 , BYREF pInput AS SecBufferDesc _                      ' __in PSecBufferDesc pInput  // Input token to apply
 ) AS LONG                                              ' SECURITY_STATUS

DECLARE FUNCTION QueryContextAttributesW IMPORT "SECUR32.DLL" ALIAS "QueryContextAttributesW" ( _
   BYREF phContext AS ANY _                             ' __in  PCtxtHandle phContext      // Context to query
 , BYVAL ulAttribute AS DWORD _                         ' __in  unsigned long ulAttribute  // Attribute to query
 , BYREF pBuffer AS ANY _                               ' __out void * pBuffer             // Buffer for attributes
 ) AS LONG                                              ' SECURITY_STATUS

DECLARE FUNCTION QueryContextAttributesA IMPORT "SECUR32.DLL" ALIAS "QueryContextAttributesA" ( _
   BYREF phContext AS ANY _                             ' __in  PCtxtHandle phContext      // Context to query
 , BYVAL ulAttribute AS DWORD _                         ' __in  unsigned long ulAttribute  // Attribute to query
 , BYREF pBuffer AS ANY _                               ' __out void * pBuffer             // Buffer for attributes
 ) AS LONG                                              ' SECURITY_STATUS

#IF %DEF(%UNICODE)
   MACRO QueryContextAttributes = QueryContextAttributesW
#ELSE
   MACRO QueryContextAttributes = QueryContextAttributesA
#ENDIF

DECLARE FUNCTION SetContextAttributesW IMPORT "SECUR32.DLL" ALIAS "SetContextAttributesW" ( _
   BYREF phContext AS ANY _                             ' __in PCtxtHandle phContext      // Context to set
 , BYVAL ulAttribute AS DWORD _                         ' __in unsigned long ulAttribute  // Attribute to set
 , BYREF pBuffer AS ANY _                               ' __in_bcount(cbBuffer) void * pBuffer // Buffer for attributes
 , BYVAL cbBuffer AS DWORD _                            ' __in unsigned long cbBuffer     // Size (in bytes) of Buffer
 ) AS LONG                                              ' SECURITY_STATUS

DECLARE FUNCTION SetContextAttributesA IMPORT "SECUR32.DLL" ALIAS "SetContextAttributesA" ( _
   BYREF phContext AS ANY _                             ' __in PCtxtHandle phContext      // Context to set
 , BYVAL ulAttribute AS DWORD _                         ' __in unsigned long ulAttribute  // Attribute to set
 , BYREF pBuffer AS ANY _                               ' __in_bcount(cbBuffer) void * pBuffer // Buffer for attributes
 , BYVAL cbBuffer AS DWORD _                            ' __in unsigned long cbBuffer     // Size (in bytes) of Buffer
 ) AS LONG                                              ' SECURITY_STATUS

#IF %DEF(%UNICODE)
   MACRO SetContextAttributes = SetContextAttributesW
#ELSE
   MACRO SetContextAttributes = SetContextAttributesA
#ENDIF

DECLARE FUNCTION QueryCredentialsAttributesW IMPORT "SECUR32.DLL" ALIAS "QueryCredentialsAttributesW" ( _
   BYREF phCredential AS ANY _                          ' __in    PCredHandle phCredential   // Credential to query
 , BYVAL ulAttribute AS DWORD _                         ' __in    unsigned long ulAttribute  // Attribute to query
 , BYREF pBuffer AS ANY _                               ' __inout void * pBuffer             // Buffer for attributes
 ) AS LONG                                              ' SECURITY_STATUS

DECLARE FUNCTION QueryCredentialsAttributesA IMPORT "SECUR32.DLL" ALIAS "QueryCredentialsAttributesA" ( _
   BYREF phCredential AS ANY _                          ' __in    PCredHandle phCredential   // Credential to query
 , BYVAL ulAttribute AS DWORD _                         ' __in    unsigned long ulAttribute  // Attribute to query
 , BYREF pBuffer AS ANY _                               ' __inout void * pBuffer             // Buffer for attributes
 ) AS LONG                                              ' SECURITY_STATUS

#IF %DEF(%UNICODE)
   MACRO QueryCredentialsAttributes = QueryCredentialsAttributesW
#ELSE
   MACRO QueryCredentialsAttributes = QueryCredentialsAttributesA
#ENDIF

DECLARE FUNCTION SetCredentialsAttributesW IMPORT "SECUR32.DLL" ALIAS "SetCredentialsAttributesW" ( _
   BYREF phCredential AS ANY _                          ' __in PCredHandle phCredential        // Credential to set
 , BYVAL ulAttribute AS DWORD _                         ' __in unsigned long ulAttribute       // Attribute to set
 , BYREF pBuffer AS ANY _                               ' __in_bcount(cbBuffer) void * pBuffer // Buffer for attributes
 , BYVAL cbBuffer AS DWORD _                            ' __in unsigned long cbBuffer          // Size (in bytes) of Buffer
 ) AS LONG                                              ' SECURITY_STATUS

DECLARE FUNCTION SetCredentialsAttributesA IMPORT "SECUR32.DLL" ALIAS "SetCredentialsAttributesA" ( _
   BYREF phCredential AS ANY _                          ' __in PCredHandle phCredential        // Credential to set
 , BYVAL ulAttribute AS DWORD _                         ' __in unsigned long ulAttribute       // Attribute to set
 , BYREF pBuffer AS ANY _                               ' __in_bcount(cbBuffer) void * pBuffer // Buffer for attributes
 , BYVAL cbBuffer AS DWORD _                            ' __in unsigned long cbBuffer          // Size (in bytes) of Buffer
 ) AS LONG                                              ' SECURITY_STATUS

#IF %DEF(%UNICODE)
   MACRO SetCredentialsAttributes = SetCredentialsAttributesW
#ELSE
   MACRO SetCredentialsAttributes = SetCredentialsAttributesA
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION FreeContextBuffer LIB "Secur32.dll" _
    ALIAS "FreeContextBuffer" ( _
    pvContextBuffer AS ANY _  ' void ptr ' buffer to free
    ) AS LONG
#ELSE
DECLARE FUNCTION FreeContextBuffer IMPORT "SECUR32.DLL" ALIAS "FreeContextBuffer" ( _
   BYVAL pvContextBuffer AS DWORD _                     ' __inout PVOID pvContextBuffer  // buffer to free
 ) AS LONG                                              ' SECURITY_STATUS
#ENDIF

'///////////////////////////////////////////////////////////////////
'////
'////    Message Support API
'////
'//////////////////////////////////////////////////////////////////

DECLARE FUNCTION MakeSignature IMPORT "SECUR32.DLL" ALIAS "MakeSignature" ( _
   BYREF phContext AS ANY _                             ' __in PCtxtHandle phContext       // Context to use
 , BYVAL fQOP AS DWORD _                                ' __in unsigned long fQOP          // Quality of Protection
 , BYREF pMessage AS SecBufferDesc _                    ' __in PSecBufferDesc pMessage     // Message to sign
 , BYVAL MessageSeqNo AS DWORD _                        ' __in unsigned long MessageSeqNo  // Message Sequence Num.
 ) AS LONG                                              ' SECURITY_STATUS

DECLARE FUNCTION VerifySignature IMPORT "SECUR32.DLL" ALIAS "VerifySignature" ( _
   BYREF phContext AS ANY _                             ' __in  PCtxtHandle phContext         // Context to use
 , BYREF pMessage AS SecBufferDesc _                    ' __in  PSecBufferDesc pMessage       // Message to verify
 , BYVAL MessageSeqNo AS DWORD _                        ' __in  unsigned long MessageSeqNo    // Sequence Num.
 , BYREF pfQOP AS DWORD _                               ' __out unsigned long * pfQOP // QOP used
 ) AS LONG                                              ' SECURITY_STATUS

%SECQOP_WRAP_NO_ENCRYPT      = &H80000001???
%SECQOP_WRAP_OOB_DATA        = &H40000000???

DECLARE FUNCTION EncryptMessage IMPORT "SECUR32.DLL" ALIAS "EncryptMessage" ( _
   BYREF phContext AS ANY _                             ' __in    PCtxtHandle    phContext
 , BYVAL fQOP AS DWORD _                                ' __in    unsigned long  fQOP
 , BYREF pMessage AS SecBufferDesc _                    ' __inout PSecBufferDesc pMessage
 , BYVAL MessageSeqNo AS DWORD _                        ' __in    unsigned long  MessageSeqNo
 ) AS LONG                                              ' SECURITY_STATUS

DECLARE FUNCTION DecryptMessage IMPORT "SECUR32.DLL" ALIAS "DecryptMessage" ( _
   BYREF phContext AS ANY _                             ' __in      PCtxtHandle    phContext
 , BYREF pMessage AS SecBufferDesc _                    ' __inout   PSecBufferDesc pMessage
 , BYVAL MessageSeqNo AS DWORD _                        ' __in      unsigned long  MessageSeqNo
 , BYREF fQOP AS DWORD _                                ' __out_opt unsigned long* fQOP
 ) AS LONG                                              ' SECURITY_STATUS


'///////////////////////////////////////////////////////////////////////////
'////
'////    Misc.
'////
'///////////////////////////////////////////////////////////////////////////

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION EnumerateSecurityPackagesW LIB "Secur32.dll" _
    ALIAS "EnumerateSecurityPackagesW" ( _
    BYVAL pcPackages    AS DWORD PTR, _  ' Receives num. packages
    BYVAL ppPackageInfo AS DWORD _       ' SecPkgInfoW PTR PTR ' Receives array of info
    ) AS LONG
#ELSE
DECLARE FUNCTION EnumerateSecurityPackagesW IMPORT "SECUR32.DLL" ALIAS "EnumerateSecurityPackagesW" ( _
   BYREF pcPackages AS DWORD _                          ' __out       unsigned long * pcPackages    // Receives num. packages
 , BYREF ppPackageInfo AS ANY _                         ' __deref_out PSecPkgInfoW * ppPackageInfo  // Receives array of info
 ) AS LONG                                              ' SECURITY_STATUS
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION EnumerateSecurityPackagesA LIB "Secur32.dll" _
    ALIAS "EnumerateSecurityPackagesA" ( _
    BYVAL pcPackages    AS DWORD PTR, _   ' Receives num. packages
    BYVAL ppPackageInfo AS DWORD _        ' SecPkgInfoA PTR PTR  ' Receives array of info
    ) AS LONG
#ELSE
DECLARE FUNCTION EnumerateSecurityPackagesA IMPORT "SECUR32.DLL" ALIAS "EnumerateSecurityPackagesA" ( _
   BYREF pcPackages AS DWORD _                          ' __out       unsigned long * pcPackages    // Receives num. packages
 , BYREF ppPackageInfo AS ANY _                         ' __deref_out PSecPkgInfoA * ppPackageInfo  // Receives array of info
 ) AS LONG                                              ' SECURITY_STATUS
#ENDIF

#IF %DEF(%UNICODE)
   MACRO EnumerateSecurityPackages = EnumerateSecurityPackagesW
#ELSE
   MACRO EnumerateSecurityPackages = EnumerateSecurityPackagesA
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION QuerySecurityPackageInfoW LIB "Secur32.dll" _
    ALIAS "QuerySecurityPackageInfoW" ( _
    pszPackageName      AS WSTRINGZ, _  ' Name of package
    BYVAL ppPackageInfo AS DWORD _      ' SecPkgInfoW PTR PTR ' Receives package info
    ) AS LONG
#ELSE
DECLARE FUNCTION QuerySecurityPackageInfoW IMPORT "SECUR32.DLL" ALIAS "QuerySecurityPackageInfoW" ( _
   BYREF pszPackageName AS WSTRINGZ _                   ' __in        LPWSTR pszPackageName   // Name of package
 , BYREF ppPackageInfo AS ANY _                         ' __deref_out PSecPkgInfoW *ppPackageInfo  // Receives package info
 ) AS LONG                                              ' SECURITY_STATUS
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION QuerySecurityPackageInfoA LIB "Secur32.dll" _
    ALIAS "QuerySecurityPackageInfoA" ( _
    pszPackageName      AS ASCIIZ, _  ' Name of package
    BYVAL ppPackageInfo AS DWORD _    ' SecPkgInfoA PTR PTR ' Receives package info
    ) AS LONG
#ELSE
DECLARE FUNCTION QuerySecurityPackageInfoA IMPORT "SECUR32.DLL" ALIAS "QuerySecurityPackageInfoA" ( _
   BYREF pszPackageName AS ASCIIZ _                     ' __in        LPSTR pszPackageName   // Name of package
 , BYREF ppPackageInfo AS ANY _                         ' __deref_out PSecPkgInfoA *ppPackageInfo  // Receives package info
 ) AS LONG                                              ' SECURITY_STATUS
#ENDIF

#IF %DEF(%UNICODE)
   MACRO QuerySecurityPackageInfo = QuerySecurityPackageInfoW
#ELSE
   MACRO QuerySecurityPackageInfo = QuerySecurityPackageInfoA
#ENDIF

' SecDelegationType enum
%SecFull      = 0
%SecService   = 1
%SecTree      = 2
%SecDirectory = 3
%SecObject    = 4

DECLARE FUNCTION DelegateSecurityContext IMPORT "SECUR32.DLL" ALIAS "DelegateSecurityContext" ( _
   BYREF phContext AS ANY _                             ' __in     PCtxtHandle         phContext           // IN Active context to delegate
 , BYREF pszTarget AS ASCIIZ _                          ' __in     LPSTR               pszTarget           // IN Target path
 , BYVAL DelegationType AS LONG _                       ' __in     SecDelegationType   DelegationType      // IN Type of delegation
 , BYREF pExpiry AS ANY _                               ' __in_opt PTimeStamp          pExpiry             // IN OPTIONAL time limit
 , BYREF pPackageParameters AS SecBuffer _              ' __in_opt PSecBuffer          pPackageParameters  // IN OPTIONAL package specific
 , BYREF pOutput AS SecBufferDesc _                     ' __out    PSecBufferDesc      pOutput             // OUT Token for applycontroltoken.
 ) AS LONG                                              ' SECURITY_STATUS


'///////////////////////////////////////////////////////////////////////////
'////
'////    Proxies
'////
'///////////////////////////////////////////////////////////////////////////


'//
'// Proxies are only available on NT platforms
'//

'///////////////////////////////////////////////////////////////////////////
'////
'////    Context export/import
'////
'///////////////////////////////////////////////////////////////////////////

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION ExportSecurityContext LIB "Secur32.dll" _
    ALIAS "ExportSecurityContext" ( _
    phContext      AS ANY, _  ' (in) context to export
    BYVAL fFlags   AS DWORD, _       ' (in) option flags
    pPackedContext AS SecBuffer, _   ' (out) marshalled context
    pToken         AS ANY _          ' void ptr ptr ' (out, optional) token handle for impersonation
    ) AS LONG
#ELSE
DECLARE FUNCTION ExportSecurityContext IMPORT "SECUR32.DLL" ALIAS "ExportSecurityContext" ( _
   BYREF phContext AS ANY _                             ' __in  PCtxtHandle phContext            // (in) context to export
 , BYVAL fFlags AS DWORD _                              ' __in  ULONG fFlags                     // (in) option flags
 , BYREF pPackedContext AS SecBuffer _                  ' __out PSecBuffer pPackedContext        // (out) marshalled context
 , BYREF pToken AS DWORD _                              ' __out void * * pToken  // (out, optional) token handle for impersonation
 ) AS LONG                                              ' SECURITY_STATUS
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION ImportSecurityContextW LIB "Secur32.dll" _
    ALIAS "ImportSecurityContextW" ( _
    pszPackage     AS WSTRINGZ, _
    pPackedContext AS SecBuffer, _  ' (in) marshalled context
    Token          AS ANY, _        ' void *, ' (in, optional) handle to token for context
    phContext      AS ANY _         ' (out) new context handle
    ) AS LONG
#ELSE
DECLARE FUNCTION ImportSecurityContextW IMPORT "SECUR32.DLL" ALIAS "ImportSecurityContextW" ( _
   BYREF pszPackage AS WSTRINGZ _                       ' __in  LPWSTR      pszPackage
 , BYREF pPackedContext AS SecBuffer _                  ' __in  PSecBuffer  pPackedContext  // (in) marshalled context
 , BYVAL Token AS DWORD _                               ' __in  void *      Token           // (in, optional) handle to token for context
 , BYREF phContext AS ANY _                             ' __out PCtxtHandle phContext       // (out) new context handle
 ) AS LONG                                              ' SECURITY_STATUS
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION ImportSecurityContextA LIB "Secur32.dll" _
    ALIAS "ImportSecurityContextA" ( _
    pszPackage     AS ASCIIZ, _
    pPackedContext AS SecBuffer, _  ' (in) marshalled context
    Token          AS ANY, _        ' void ptr ' (in, optional) handle to token for context
    phContext      AS ANY _         ' (out) new context handle
    ) AS LONG
#ELSE
DECLARE FUNCTION ImportSecurityContextA IMPORT "SECUR32.DLL" ALIAS "ImportSecurityContextA" ( _
   BYREF pszPackage AS ASCIIZ _                         ' __in  LPSTR       pszPackage
 , BYREF pPackedContext AS SecBuffer _                  ' __in  PSecBuffer  pPackedContext  // (in) marshalled context
 , BYVAL Token AS DWORD _                               ' __in  void *      Token           // (in, optional) handle to token for context
 , BYREF phContext AS ANY _                             ' __out PCtxtHandle phContext       // (out) new context handle
 ) AS LONG                                              ' SECURITY_STATUS
#ENDIF

#IF %DEF(%UNICODE)
   MACRO ImportSecurityContext = ImportSecurityContextW
#ELSE
   MACRO ImportSecurityContext = ImportSecurityContextA
#ENDIF

'#IF %ISSP_MODE = 0
'KSECDDDECLSPEC
'NTSTATUS
'NTAPI
'SecMakeSPN(
'    IN PUNICODE_STRING ServiceClass,
'    IN PUNICODE_STRING ServiceName,
'    IN PUNICODE_STRING InstanceName OPTIONAL,
'    IN USHORT InstancePort OPTIONAL,
'    IN PUNICODE_STRING Referrer OPTIONAL,
'    IN OUT PUNICODE_STRING Spn,
'    OUT PULONG Length OPTIONAL,
'    IN BOOLEAN Allocate
'    );

'#if OSVER(NTDDI_VERSION) > NTDD_WIN2K

'KSECDDDECLSPEC
'NTSTATUS
'NTAPI
'SecMakeSPNEx(
'    IN PUNICODE_STRING ServiceClass,
'    IN PUNICODE_STRING ServiceName,
'    IN PUNICODE_STRING InstanceName OPTIONAL,
'    IN USHORT InstancePort OPTIONAL,
'    IN PUNICODE_STRING Referrer OPTIONAL,
'    IN PUNICODE_STRING TargetInfo OPTIONAL,
'    IN OUT PUNICODE_STRING Spn,
'    OUT PULONG Length OPTIONAL,
'    IN BOOLEAN Allocate
'    );

'#if OSVER(NTDDI_VERSION) > NTDDI_WS03

'KSECDDDECLSPEC
'NTSTATUS
'NTAPI
'SecMakeSPNEx2(
'    IN PUNICODE_STRING ServiceClass,
'    IN PUNICODE_STRING ServiceName,
'    IN PUNICODE_STRING InstanceName OPTIONAL,
'    IN USHORT InstancePort OPTIONAL,
'    IN PUNICODE_STRING Referrer OPTIONAL,
'    IN PUNICODE_STRING InTargetInfo OPTIONAL,
'    IN OUT PUNICODE_STRING Spn,
'    OUT PULONG TotalSize OPTIONAL,
'    IN BOOLEAN Allocate,
'    IN BOOLEAN IsTargetInfoMarshaled
'    );

'#endif // Windows Vista and greater

'KSECDDDECLSPEC
'NTSTATUS
'SEC_ENTRY
'SecLookupAccountSid(
'    IN PSID Sid,
'    IN OUT PULONG NameSize,
'    OUT PUNICODE_STRING NameBuffer,
'    IN OUT PULONG DomainSize OPTIONAL,
'    OUT PUNICODE_STRING DomainBuffer OPTIONAL,
'    OUT PSID_NAME_USE NameUse
'    );

'KSECDDDECLSPEC
'NTSTATUS
'SEC_ENTRY
'SecLookupAccountName(
'    IN PUNICODE_STRING Name,
'    IN OUT PULONG SidSize,
'    OUT PSID Sid,
'    OUT PSID_NAME_USE NameUse,
'    IN OUT PULONG DomainSize OPTIONAL,
'    OUT PUNICODE_STRING ReferencedDomain OPTIONAL
'    );

'#endif // Greater than W2k

'#if OSVER(NTDDI_VERSION) > NTDDI_WINXP

'KSECDDDECLSPEC
'NTSTATUS
'SEC_ENTRY
'SecLookupWellKnownSid(
'    IN WELL_KNOWN_SID_TYPE SidType,
'    OUT PSID Sid,
'    ULONG SidBufferSize,
'    OUT PULONG SidSize OPTIONAL
'    );

'#endif // Greater than XP

'#ENDIF

'///////////////////////////////////////////////////////////////////////////////
'////
'////  Fast access for RPC:
'////
'///////////////////////////////////////////////////////////////////////////////

$SECURITY_ENTRYPOINT_ANSIW = "InitSecurityInterfaceW"
$SECURITY_ENTRYPOINT_ANSIA  = "InitSecurityInterfaceA"
$$SECURITY_ENTRYPOINTW      = "InitSecurityInterfaceW"$$     ' // ntifs
$$SECURITY_ENTRYPOINTA      = "InitSecurityInterfaceA"$$
$SECURITY_ENTRYPOINT16      = "INITSECURITYINTERFACEA"

'#define FreeCredentialHandle FreeCredentialsHandle

' // Size = 116 bytes
TYPE SecurityFunctionTableW DWORD
   dwVersion                   AS DWORD   ' unsigned long
   EnumerateSecurityPackagesW  AS DWORD   ' ENUMERATE_SECURITY_PACKAGES_FN_W
   QueryCredentialsAttributesW AS DWORD   ' QUERY_CREDENTIALS_ATTRIBUTES_FN_W
   AcquireCredentialsHandleW   AS DWORD   ' ACQUIRE_CREDENTIALS_HANDLE_FN_W
   FreeCredentialsHandle       AS DWORD   ' FREE_CREDENTIALS_HANDLE_FN
   Reserved2                   AS DWORD   ' void *
   InitializeSecurityContextW  AS DWORD   ' INITIALIZE_SECURITY_CONTEXT_FN_W
   AcceptSecurityContext       AS DWORD   ' ACCEPT_SECURITY_CONTEXT_FN
   CompleteAuthToken           AS DWORD   ' COMPLETE_AUTH_TOKEN_FN
   DeleteSecurityContext       AS DWORD   ' DELETE_SECURITY_CONTEXT_FN
   ApplyControlToken           AS DWORD   ' APPLY_CONTROL_TOKEN_FN
   QueryContextAttributesW     AS DWORD   ' QUERY_CONTEXT_ATTRIBUTES_FN_W
   ImpersonateSecurityContext  AS DWORD   ' IMPERSONATE_SECURITY_CONTEXT_FN
   RevertSecurityContext       AS DWORD   ' REVERT_SECURITY_CONTEXT_FN
   MakeSignature               AS DWORD   ' MAKE_SIGNATURE_FN
   VerifySignature             AS DWORD   ' VERIFY_SIGNATURE_FN
   FreeContextBuffer           AS DWORD   ' FREE_CONTEXT_BUFFER_FN
   QuerySecurityPackageInfoW   AS DWORD   ' QUERY_SECURITY_PACKAGE_INFO_FN_W
   Reserved3                   AS DWORD   ' void *
   Reserved4                   AS DWORD   ' void *
   ExportSecurityContext       AS DWORD   ' EXPORT_SECURITY_CONTEXT_FN
   ImportSecurityContextW      AS DWORD   ' IMPORT_SECURITY_CONTEXT_FN_W
   AddCredentialsW             AS DWORD   ' ADD_CREDENTIALS_FN_W
   Reserved8                   AS DWORD   ' void *
   QuerySecurityContextToken   AS DWORD   ' QUERY_SECURITY_CONTEXT_TOKEN_FN
   EncryptMessage              AS DWORD   ' ENCRYPT_MESSAGE_FN
   DecryptMessage              AS DWORD   ' DECRYPT_MESSAGE_FN
'#if OSVER(NTDDI_VERSION) > NTDDI_WIN2K
   ' // Fields below this are available in OSes after w2k
   SetContextAttributesW       AS DWORD   ' SET_CONTEXT_ATTRIBUTES_FN_W
'#endif // greater thean 2K
'#if NTDDI_VERSION > NTDDI_WS03SP1
   ' // Fields below this are available in OSes after W2k3SP1
   SetCredentialsAttributesW   AS DWORD   ' SET_CREDENTIALS_ATTRIBUTES_FN_W
'#endif
'#if ISSP_MODE != 0
'    CHANGE_PASSWORD_FN_W                ChangeAccountPasswordW;
'#else
'    void *                      Reserved9;
'#endif
END TYPE

' // Size = 116 bytes
TYPE SecurityFunctionTableA DWORD
   dwVersion                   AS DWORD   ' unsigned long
   EnumerateSecurityPackagesA  AS DWORD   ' ENUMERATE_SECURITY_PACKAGES_FN_A
   QueryCredentialsAttributesA AS DWORD   ' QUERY_CREDENTIALS_ATTRIBUTES_FN_A
   AcquireCredentialsHandleA   AS DWORD   ' ACQUIRE_CREDENTIALS_HANDLE_FN_A
   FreeCredentialHandle        AS DWORD   ' FREE_CREDENTIALS_HANDLE_FN
   Reserved2                   AS DWORD   ' void *
   InitializeSecurityContextA  AS DWORD   ' INITIALIZE_SECURITY_CONTEXT_FN_A
   AcceptSecurityContext       AS DWORD   ' ACCEPT_SECURITY_CONTEXT_FN
   CompleteAuthToken           AS DWORD   ' COMPLETE_AUTH_TOKEN_FN
   DeleteSecurityContext       AS DWORD   ' DELETE_SECURITY_CONTEXT_FN
   ApplyControlToken           AS DWORD   ' APPLY_CONTROL_TOKEN_FN
   QueryContextAttributesA     AS DWORD   ' QUERY_CONTEXT_ATTRIBUTES_FN_A
   ImpersonateSecurityContext  AS DWORD   ' IMPERSONATE_SECURITY_CONTEXT_FN
   RevertSecurityContext       AS DWORD   ' REVERT_SECURITY_CONTEXT_FN
   MakeSignature               AS DWORD   ' MAKE_SIGNATURE_FN
   VerifySignature             AS DWORD   ' VERIFY_SIGNATURE_FN
   FreeContextBuffer           AS DWORD   ' FREE_CONTEXT_BUFFER_FN
   QuerySecurityPackageInfoA   AS DWORD   ' QUERY_SECURITY_PACKAGE_INFO_FN_A
   Reserved3                   AS DWORD   ' void *
   Reserved4                   AS DWORD   ' void *
   ExportSecurityContext       AS DWORD   ' EXPORT_SECURITY_CONTEXT_FN
   ImportSecurityContextA      AS DWORD   ' IMPORT_SECURITY_CONTEXT_FN_A
   AddCredentialsA             AS DWORD   ' ADD_CREDENTIALS_FN_A
   Reserved8                   AS DWORD   ' void *
   QuerySecurityContextToken   AS DWORD   ' QUERY_SECURITY_CONTEXT_TOKEN_FN
   EncryptMessage              AS DWORD   ' ENCRYPT_MESSAGE_FN
   DecryptMessage              AS DWORD   ' DECRYPT_MESSAGE_FN
   SetContextAttributesA       AS DWORD   ' SET_CONTEXT_ATTRIBUTES_FN_A
   SetCredentialsAttributesA   AS DWORD   ' SET_CREDENTIALS_ATTRIBUTES_FN_A
'#if ISSP_MODE != 0
'    CHANGE_PASSWORD_FN_A                ChangeAccountPasswordA;
'#else
'    void *                      Reserved9;
'#endif
END TYPE

#IF %DEF(%UNICODE)
   MACRO SecurityFunctionTable = SecurityFunctionTableW
#ELSE
   MACRO SecurityFunctionTable = SecurityFunctionTableA
#ENDIF

'// Function table has all routines through DecryptMessage
%SECURITY_SUPPORT_PROVIDER_INTERFACE_VERSION   = 1  ' // ntifs

'// Function table has all routines through SetContextAttributes
%SECURITY_SUPPORT_PROVIDER_INTERFACE_VERSION_2 = 2  ' // ntifs

'// Function table has all routines through SetCredentialsAttributes
%SECURITY_SUPPORT_PROVIDER_INTERFACE_VERSION_3 = 3  ' // ntifs

'// Function table has all routines through ChangeAccountPassword
%SECURITY_SUPPORT_PROVIDER_INTERFACE_VERSION_4 = 4  ' // ntifs

DECLARE FUNCTION InitSecurityInterfaceA IMPORT "SECUR32.DLL" ALIAS "InitSecurityInterfaceA" ( _
 ) AS DWORD                                             ' PSecurityFunctionTableA

DECLARE FUNCTION InitSecurityInterfaceW IMPORT "SECUR32.DLL" ALIAS "InitSecurityInterfaceW" ( _
 ) AS DWORD                                             ' PSecurityFunctionTableW

#IF %DEF(%UNICODE)
   MACRO InitSecurityInterface = InitSecurityInterfaceW
#ELSE
   MACRO InitSecurityInterface = InitSecurityInterfaceA
#ENDIF

'#IF %DEF(%SECURITY_WIN32)

'//
'// SASL Profile Support
'//

DECLARE FUNCTION SaslEnumerateProfilesA IMPORT "SECUR32.DLL" ALIAS "SaslEnumerateProfilesA" ( _
   BYREF ProfileList AS DWORD _                         ' __deref_out LPSTR * ProfileList
 , BYREF ProfileCount AS DWORD _                        ' __out       ULONG * ProfileCount
 ) AS LONG                                              ' SECURITY_STATUS

DECLARE FUNCTION SaslEnumerateProfilesW IMPORT "SECUR32.DLL" ALIAS "SaslEnumerateProfilesW" ( _
   BYREF ProfileList AS DWORD _                         ' __deref_out LPWSTR * ProfileList
 , BYREF ProfileCount AS DWORD _                        ' __out       ULONG * ProfileCount
 ) AS LONG                                              ' SECURITY_STATUS

#IF %DEF(%UNICODE)
   MACRO SaslEnumerateProfiles = SaslEnumerateProfilesW
#ELSE
   MACRO SaslEnumerateProfiles = SaslEnumerateProfilesA
#ENDIF

DECLARE FUNCTION SaslGetProfilePackageA IMPORT "SECUR32.DLL" ALIAS "SaslGetProfilePackageA" ( _
   BYREF ProfileName AS ASCIIZ _                        ' __in        LPSTR ProfileName
 , BYREF PackageInfo AS SecPkgInfoA _                   ' __deref_out PSecPkgInfoA * PackageInfo
 ) AS LONG                                              ' SECURITY_STATUS

DECLARE FUNCTION SaslGetProfilePackageW IMPORT "SECUR32.DLL" ALIAS "SaslGetProfilePackageW" ( _
   BYREF ProfileName AS WSTRINGZ _                      ' __in        LPWSTR ProfileName
 , BYREF PackageInfo AS SecPkgInfoW _                   ' __deref_out PSecPkgInfoW * PackageInfo
 ) AS LONG                                              ' SECURITY_STATUS

#IF %DEF(%UNICODE)
   MACRO SaslGetProfilePackage = SaslGetProfilePackageW
#ELSE
   MACRO SaslGetProfilePackage = SaslGetProfilePackageA
#ENDIF

DECLARE FUNCTION SaslIdentifyPackageA IMPORT "SECUR32.DLL" ALIAS "SaslIdentifyPackageA" ( _
   BYREF pInput AS SecBufferDesc _                      ' __in        PSecBufferDesc pInput
 , BYREF PackageInfo AS SecPkgInfoA _                   ' __deref_out PSecPkgInfoA * PackageInfo
 ) AS LONG                                              ' SECURITY_STATUS

DECLARE FUNCTION SaslIdentifyPackageW IMPORT "SECUR32.DLL" ALIAS "SaslIdentifyPackageW" ( _
   BYREF pInput AS SecBufferDesc _                      ' __in        PSecBufferDesc pInput
 , BYREF PackageInfo AS SecPkgInfoW _                   ' __deref_out PSecPkgInfoW * PackageInfo
 ) AS LONG                                              ' SECURITY_STATUS

#IF %DEF(%UNICODE)
   MACRO SaslIdentifyPackage = SaslIdentifyPackageW
#ELSE
   MACRO SaslIdentifyPackage = SaslIdentifyPackageA
#ENDIF

DECLARE FUNCTION SaslInitializeSecurityContextW IMPORT "SECUR32.DLL" ALIAS "SaslInitializeSecurityContextW" ( _
   BYREF phCredential AS CredHandle _                   ' __in_opt    PCredHandle             phCredential  // Cred to base context
 , BYREF phContext AS CtxtHandle _                      ' __in_opt    PCtxtHandle             phContext     // Existing context (OPT)
 , BYREF pszTargetName AS WSTRINGZ _                    ' __in_opt    LPWSTR                  pszTargetName // Name of target
 , BYVAL fContextReq AS DWORD _                         ' __in        unsigned long           fContextReq   // Context Requirements
 , BYVAL Reserved1 AS DWORD _                           ' __in        unsigned long           Reserved1     // Reserved, MBZ
 , BYVAL TargetDataRep AS DWORD _                       ' __in        unsigned long           TargetDataRep // Data rep of target
 , BYREF pInput AS SecBufferDesc _                      ' __in_opt    PSecBufferDesc          pInput        // Input Buffers
 , BYVAL Reserved2 AS DWORD _                           ' __in        unsigned long           Reserved2     // Reserved, MBZ
 , BYREF phNewContext AS CtxtHandle _                   ' __inout_opt PCtxtHandle             phNewContext  // (out) New Context handle
 , BYREF pOutput AS SecBufferDesc _                     ' __inout_opt PSecBufferDesc          pOutput       // (inout) Output Buffers
 , BYREF pfContextAttr AS DWORD _                       ' __out       unsigned long *         pfContextAttr // (out) Context attrs
 , BYREF ptsExpiry AS QUAD _                            ' __out_opt   PTimeStamp              ptsExpiry     // (out) Life span (OPT)
 ) AS LONG                                              ' SECURITY_STATUS

DECLARE FUNCTION SaslInitializeSecurityContextA IMPORT "SECUR32.DLL" ALIAS "SaslInitializeSecurityContextA" ( _
   BYREF phCredential AS CredHandle _                   ' __in_opt    PCredHandle             phCredential  // Cred to base context
 , BYREF phContext AS CtxtHandle _                      ' __in_opt    PCtxtHandle             phContext     // Existing context (OPT)
 , BYREF pszTargetName AS ASCIIZ _                      ' __in_opt    LPSTR                   pszTargetName // Name of target
 , BYVAL fContextReq AS DWORD _                         ' __in        unsigned long           fContextReq   // Context Requirements
 , BYVAL Reserved1 AS DWORD _                           ' __in        unsigned long           Reserved1     // Reserved, MBZ
 , BYVAL TargetDataRep AS DWORD _                       ' __in        unsigned long           TargetDataRep // Data rep of target
 , BYREF pInput AS SecBufferDesc _                      ' __in_opt    PSecBufferDesc          pInput        // Input Buffers
 , BYVAL Reserved2 AS DWORD _                           ' __in        unsigned long           Reserved2     // Reserved, MBZ
 , BYREF phNewContext AS CtxtHandle _                   ' __inout_opt PCtxtHandle             phNewContext  // (out) New Context handle
 , BYREF pOutput AS SecBufferDesc _                     ' __inout_opt PSecBufferDesc          pOutput       // (inout) Output Buffers
 , BYREF pfContextAttr AS DWORD _                       ' __out       unsigned long *         pfContextAttr // (out) Context attrs
 , BYREF ptsExpiry AS QUAD _                            ' __out_opt   PTimeStamp              ptsExpiry     // (out) Life span (OPT)
 ) AS LONG                                              ' SECURITY_STATUS

#IF %DEF(%UNICODE)
   MACRO SaslInitializeSecurityContext = SaslInitializeSecurityContextW
#ELSE
   MACRO SaslInitializeSecurityContext = SaslInitializeSecurityContextA
#ENDIF

DECLARE FUNCTION SaslAcceptSecurityContext IMPORT "SECUR32.DLL" ALIAS "SaslAcceptSecurityContext" ( _
   BYREF phCredential AS CredHandle _                   ' __in_opt    PCredHandle             phCredential  // Cred to base context
 , BYREF phContext AS CtxtHandle _                      ' __in_opt    PCtxtHandle             phContext     // Existing context (OPT)
 , BYREF pInput AS SecBufferDesc _                      ' __in_opt    PSecBufferDesc          pInput        // Input buffer
 , BYVAL fContextReq AS DWORD _                         ' __in        unsigned long           fContextReq   // Context Requirements
 , BYVAL TargetDataRep AS DWORD _                       ' __in        unsigned long           TargetDataRep // Target Data Rep
 , BYREF phNewContext AS CtxtHandle _                   ' __inout_opt PCtxtHandle             phNewContext  // (out) New context handle
 , BYREF pOutput AS SecBufferDesc _                     ' __inout_opt PSecBufferDesc          pOutput       // (inout) Output buffers
 , BYREF pfContextAttr AS DWORD _                       ' __out       unsigned long *         pfContextAttr // (out) Context attributes
 , BYREF ptsExpiry AS QUAD _                            ' __out_opt   PTimeStamp              ptsExpiry     // (out) Life span (OPT)
 ) AS LONG                                              ' SECURITY_STATUS


%SASL_OPTION_SEND_SIZE        = 1   ' // Maximum size to send to peer
%SASL_OPTION_RECV_SIZE        = 2   ' // Maximum size willing to receive
%SASL_OPTION_AUTHZ_STRING     = 3   ' // Authorization string
%SASL_OPTION_AUTHZ_PROCESSING = 4   ' // Authorization string processing

' SASL_AUTHZID_STATE enum
%Sasl_AuthZIDForbidden = 0          ' // allow no AuthZID strings to be specified - error out (default)
%Sasl_AuthZIDProcessed = 1          ' // AuthZID Strings processed by Application or SSP

DECLARE FUNCTION SaslSetContextOption IMPORT "SECUR32.DLL" ALIAS "SaslSetContextOption" ( _
   BYREF ContextHandle AS CtxtHandle _                  ' __in PCtxtHandle ContextHandle
 , BYVAL Option AS DWORD _                              ' __in ULONG Option
 , BYVAL Value AS DWORD _                               ' __in PVOID Value
 , BYVAL Size AS DWORD _                                ' __in ULONG Size
 ) AS LONG                                              ' SECURITY_STATUS

DECLARE FUNCTION SaslGetContextOption IMPORT "SECUR32.DLL" ALIAS "SaslGetContextOption" ( _
   BYREF ContextHandle AS CtxtHandle _                  ' __in      PCtxtHandle ContextHandle
 , BYVAL Option AS DWORD _                              ' __in      ULONG Option
 , BYVAL Value AS DWORD _                               ' __out     PVOID Value
 , BYVAL Size AS DWORD _                                ' __in      ULONG Size
 , BYREF Needed AS DWORD _                              ' __out_opt PULONG Needed OPTIONAL
 ) AS LONG                                              ' SECURITY_STATUS

'#ENDIF   ' #IF %DEF(%SECURITY_WIN32)

'//
'// This is the legacy credentials structure.
'// The EX version below is preferred.

#IF NOT %DEF(%AUTH_IDENTITY_DEFINED)
%AUTH_IDENTITY_DEFINED = 1

%SEC_WINNT_AUTH_IDENTITY_ANSI    = &H1
%SEC_WINNT_AUTH_IDENTITY_UNICODE = &H2

' // Size = 28 bytes
TYPE SEC_WINNT_AUTH_IDENTITY_W DWORD
   User           AS WORD PTR   ' unsigned short * //  Non-NULL terminated string.
   UserLength     AS DWORD      ' unsigned long    //  # of characters (NOT bytes), not including NULL.
   Domain         AS WORD PTR   ' unsigned short * //  Non-NULL terminated string.
   DomainLength   AS DWORD      ' unsigned long    //  # of characters (NOT bytes), not including NULL.
   Password       AS WORD PTR   ' unsigned short * //  Non-NULL terminated string.
   PasswordLength AS DWORD      ' unsigned long    //  # of characters (NOT bytes), not including NULL.
   Flags          AS DWORD      ' unsigned long
END TYPE

' // Size = 28 bytes
TYPE SEC_WINNT_AUTH_IDENTITY_A DWORD
   User           AS BYTE PTR   ' unsigned char * //  Non-NULL terminated string.
   UserLength     AS DWORD      ' unsigned long   //  # of characters (NOT bytes), not including NULL.
   Domain         AS BYTE PTR   ' unsigned char * //  Non-NULL terminated string.
   DomainLength   AS DWORD      ' unsigned long   //  # of characters (NOT bytes), not including NULL.
   Password       AS BYTE PTR   ' unsigned char * //  Non-NULL terminated string.
   PasswordLength AS DWORD      ' unsigned long   //  # of characters (NOT bytes), not including NULL.
   Flags          AS DWORD      ' unsigned long
END TYPE

#IF %DEF(%UNICODE)
   MACRO SEC_WINNT_AUTH_IDENTITY = SEC_WINNT_AUTH_IDENTITY_W
#ELSE
   MACRO SEC_WINNT_AUTH_IDENTITY = SEC_WINNT_AUTH_IDENTITY_A
#ENDIF

#ENDIF   ' //_AUTH_IDENTITY_DEFINED


#IF NOT %DEF(%AUTH_IDENTITY_EX2_DEFINED)
    %AUTH_IDENTITY_EX2_DEFINED = 1

%SEC_WINNT_AUTH_IDENTITY_VERSION_2 = &H201

' // Size = 48 bytes
TYPE SEC_WINNT_AUTH_IDENTITY_EX2 DWORD
   Version                 AS DWORD   ' unsigned long // contains SEC_WINNT_AUTH_IDENTITY_VERSION_2
   cbHeaderLength          AS WORD    ' unsigned short
   cbStructureLength       AS DWORD   ' unsigned long
   UserOffset              AS DWORD   ' unsigned long // Non-NULL terminated string, unicode only
   UserLength              AS WORD    ' unsigned short // # of bytes (NOT WCHARs), not including NULL.
   DomainOffset            AS DWORD   ' unsigned long // Non-NULL terminated string, unicode only
   DomainLength            AS WORD    ' unsigned short // # of bytes (NOT WCHARs), not including NULL.
   PackedCredentialsOffset AS DWORD   ' unsigned long // Non-NULL terminated string, unicode only
   PackedCredentialsLength AS WORD    ' unsigned short // # of bytes (NOT WCHARs), not including NULL.
   Flags                   AS DWORD   ' unsigned long
   PackageListOffset       AS DWORD   ' unsigned long // Non-NULL terminated string, unicode only
   PackageListLength       AS WORD    ' unsigned short
END TYPE

#ENDIF   ' // _AUTH_IDENTITY_EX2_DEFINED

'//
'// This is the combined authentication identity structure that may be
'// used with the negotiate package, NTLM, Kerberos, or SCHANNEL
'//

#IF NOT %DEF(%SEC_WINNT_AUTH_IDENTITY_VERSION)
%SEC_WINNT_AUTH_IDENTITY_VERSION = &H200

' // Size = 44 bytes
TYPE SEC_WINNT_AUTH_IDENTITY_EXW DWORD
   Version           AS DWORD      ' unsigned long
   Length            AS DWORD      ' unsigned long
   User              AS WORD PTR   ' unsigned short * //  Non-NULL terminated string.
   UserLength        AS DWORD      ' unsigned long    //  # of characters (NOT bytes), not including NULL.
   Domain            AS WORD PTR   ' unsigned short * //  Non-NULL terminated string.
   DomainLength      AS DWORD      ' unsigned long    //  # of characters (NOT bytes), not including NULL.
   Password          AS WORD PTR   ' unsigned short * //  Non-NULL terminated string.
   PasswordLength    AS DWORD      ' unsigned long    //  # of characters (NOT bytes), not including NULL.
   Flags             AS DWORD      ' unsigned long
   PackageList       AS WORD PTR   ' unsigned short *
   PackageListLength AS DWORD      ' unsigned long
END TYPE

' // Size = 44 bytes
TYPE SEC_WINNT_AUTH_IDENTITY_EXA DWORD
   Version           AS DWORD      ' unsigned long
   Length            AS DWORD      ' unsigned long
   User              AS BYTE PTR   ' unsigned char * //  Non-NULL terminated string.
   UserLength        AS DWORD      ' unsigned long   //  # of characters (NOT bytes), not including NULL.
   Domain            AS BYTE PTR   ' unsigned char * //  Non-NULL terminated string.
   DomainLength      AS DWORD      ' unsigned long   //  # of characters (NOT bytes), not including NULL.
   Password          AS BYTE PTR   ' unsigned char * //  Non-NULL terminated string.
   PasswordLength    AS DWORD      ' unsigned long   //  # of characters (NOT bytes), not including NULL.
   Flags             AS DWORD      ' unsigned long
   PackageList       AS BYTE PTR   ' unsigned char *
   PackageListLength AS DWORD      ' unsigned long
END TYPE

#IF %DEF(%UNICODE)
   MACRO SEC_WINNT_AUTH_IDENTITY_EX = SEC_WINNT_AUTH_IDENTITY_EXW
#ELSE
   MACRO SEC_WINNT_AUTH_IDENTITY_EX = SEC_WINNT_AUTH_IDENTITY_EXA
#ENDIF

#ENDIF   ' // SEC_WINNT_AUTH_IDENTITY_VERSION

#IF NOT %DEF(%AUTH_IDENTITY_INFO_DEFINED)
    %AUTH_IDENTITY_INFO_DEFINED = 1

'//
'// the procedure for how to parse a SEC_WINNT_AUTH_IDENTITY_INFO structure:
'//
'// 1) First check the first DWORD of SEC_WINNT_AUTH_IDENTITY_INFO, if the first
'//   DWORD is 0x200, it is either an AuthIdExw or AuthIdExA, otherwise if the first
'//   DWORD is 0x201, the structure is an AuthIdEx2 structure. Otherwise the structure
'//   is either an AuthId_a or an AuthId_w.
'//
'// 2) Secondly check the flags for SEC_WINNT_AUTH_IDENTITY_ANSI or
'//   SEC_WINNT_AUTH_IDENTITY_UNICODE, the presence of the former means the structure
'//   is an ANSI structure. Otherwise, the structure is the wide version.  Note that
'//   AuthIdEx2 does not have an ANSI version so this check does not apply to it.
'//

' // Size = 48 bytes
UNION SEC_WINNT_AUTH_IDENTITY_INFO
   AuthIdExw AS SEC_WINNT_AUTH_IDENTITY_EXW
   AuthIdExa AS SEC_WINNT_AUTH_IDENTITY_EXA
   AuthId_a  AS SEC_WINNT_AUTH_IDENTITY_A
   AuthId_w  AS SEC_WINNT_AUTH_IDENTITY_W
   AuthIdEx2 AS SEC_WINNT_AUTH_IDENTITY_EX2
END UNION

'// the credential structure is encrypted via
'// RtlEncryptMemory(OptionFlags = 0)
%SEC_WINNT_AUTH_IDENTITY_FLAGS_PROCESS_ENCRYPTED = &H10???

'// the credential structure is protected by local system via
'// RtlEncryptMemory(OptionFlags =
'// IOCTL_KSEC_ENCRYPT_MEMORY_SAME_LOGON)
%SEC_WINNT_AUTH_IDENTITY_FLAGS_SYSTEM_PROTECTED  = &H20???

%SEC_WINNT_AUTH_IDENTITY_FLAGS_RESERVED       = &H10000???
%SEC_WINNT_AUTH_IDENTITY_FLAGS_NULL_USER      = &H20000???
%SEC_WINNT_AUTH_IDENTITY_FLAGS_NULL_DOMAIN    = &H40000???

'//
'//  These bits are for communication between SspiPromptForCredentials()
'//  and the credential providers. Do not use these bits for any other
'//  purpose.
'//

%SEC_WINNT_AUTH_IDENTITY_FLAGS_SSPIPFC_USE_MASK  = &HFF000000???

'//
'//  Instructs the credential provider to not save credentials itself
'//  when caller selects the "Remember my credential" checkbox.
'//

%SEC_WINNT_AUTH_IDENTITY_FLAGS_SSPIPFC_SAVE_CRED_BY_CALLER   = &H80000000???

'//
'//  State of the "Remember my credentials" checkbox.
'//  When set, indicates checked; when cleared, indicates unchecked.
'//

%SEC_WINNT_AUTH_IDENTITY_FLAGS_SSPIPFC_SAVE_CRED_CHECKED     = &H40000000???

%SEC_WINNT_AUTH_IDENTITY_FLAGS_VALID_SSPIPFC_FLAGS  = _
                %SEC_WINNT_AUTH_IDENTITY_FLAGS_SSPIPFC_SAVE_CRED_BY_CALLER OR _
                %SEC_WINNT_AUTH_IDENTITY_FLAGS_SSPIPFC_SAVE_CRED_CHECKED


#ENDIF   ' // _AUTH_IDENTITY_INFO_DEFINED

'#ifndef _SSPIPFC_NONE_ // the public view

'// begin_ntifs

'typedef PVOID PSEC_WINNT_AUTH_IDENTITY_OPAQUE; // the credential structure is opaque

'// end_ntifs

'#else  // the internal view

'typedef PSEC_WINNT_AUTH_IDENTITY_INFO PSEC_WINNT_AUTH_IDENTITY_OPAQUE;

'#endif // _SSPIPFC_NONE_

'//
'//  dwFlags parameter of SspiPromptForCredentials():
'//

'//
'//  Indicates that the credentials should not be saved if
'//  the user selects the 'save' (or 'remember my password')
'//  checkbox in the credential dialog box. The location pointed
'//  to by the pfSave parameter indicates whether or not the user
'//  selected the checkbox.
'//
'//  Note that some credential providers won't honour this flag and
'//  may save the credentials in a persistent manner anyway if the
'//  user selects the 'save' checbox.
'//

%SSPIPFC_SAVE_CRED_BY_CALLER     = &H00000001???

%SSPIPFC_VALID_FLAGS = %SSPIPFC_SAVE_CRED_BY_CALLER

'#ifndef _SSPIPFC_NONE_ // the public view

'// Use SspiFreeAuthIdentity() to free the buffer returned
'// in ppAuthIdentity.

#IF %DEF(%USEPBDECL)
'DECLARE FUNCTION SspiPromptForCredentialsW LIB "Secur32.dll" _
'    ALIAS "SspiPromptForCredentialsW" ( _
DECLARE FUNCTION SspiPromptForCredentialsW LIB "CREDUI.DLL" _
    ALIAS "SspiPromptForCredentialsW" ( _
    pszTargetName      AS WSTRINGZ, _
    pUiInfo            AS CREDUI_INFOW, _
    BYVAL dwAuthError  AS DWORD, _
    pszPackage         AS WSTRINGZ, _
    pInputAuthIdentity AS ANY, _  ' SEC_WINNT_AUTH_IDENTITY_OPAQUE, _
    ppAuthIdentity     AS ANY, _  ' SEC_WINNT_AUTH_IDENTITY_OPAQUE PTR PTR
    pfSave             AS LONG, _
    BYVAL dwFlags      AS DWORD _
    ) AS DWORD
#ELSE
DECLARE FUNCTION SspiPromptForCredentialsW IMPORT "CREDUI.DLL" ALIAS "SspiPromptForCredentialsW" ( _
   BYREF pszTargetName AS WSTRINGZ _                    ' __in PCWSTR pszTargetName
 , BYREF pUiInfo AS CREDUI_INFOW _                      ' __in_opt PCREDUI_INFOW pUiInfo
 , BYVAL dwAuthError AS DWORD _                         ' __in unsigned long dwAuthError
 , BYREF pszPackage AS WSTRINGZ _                       ' __in PCWSTR pszPackage
 , BYVAL pInputAuthIdentity AS DWORD _                  ' __in_opt PSEC_WINNT_AUTH_IDENTITY_OPAQUE pInputAuthIdentity
 , BYREF ppAuthIdentity AS DWORD _                      ' __out PSEC_WINNT_AUTH_IDENTITY_OPAQUE* ppAuthIdentity
 , BYREF pfSave AS LONG _                               ' __inout_opt int* pfSave
 , BYVAL dwFlags AS DWORD _                             ' __in unsigned long dwFlags
 ) AS DWORD                                             ' unsigned long
#ENDIF

'// Use SspiFreeAuthIdentity() to free the buffer returned
'// in ppAuthIdentity.

#IF %DEF(%USEPBDECL)
'DECLARE FUNCTION SspiPromptForCredentialsA LIB "Secur32.dll" _
'    ALIAS "SspiPromptForCredentialsA" ( _
DECLARE FUNCTION SspiPromptForCredentialsA LIB "CREDUI.DLL" _
    ALIAS "SspiPromptForCredentialsA" ( _
    pszTargetName      AS ASCIIZ, _
    pUiInfo            AS CREDUI_INFOA, _
    BYVAL dwAuthError  AS DWORD, _
    pszPackage         AS ASCIIZ, _
    pInputAuthIdentity AS ANY, _  ' SEC_WINNT_AUTH_IDENTITY_OPAQUE, _
    ppAuthIdentity     AS ANY, _  ' SEC_WINNT_AUTH_IDENTITY_OPAQUE PTR PTR
    pfSave             AS LONG, _
    BYVAL dwFlags      AS DWORD _
    ) AS DWORD
#ELSE
DECLARE FUNCTION SspiPromptForCredentialsA IMPORT "CREDUI.DLL" ALIAS "SspiPromptForCredentialsA" ( _
   BYREF pszTargetName AS ASCIIZ _                      ' __in PCSTR pszTargetName
 , BYREF pUiInfo AS CREDUI_INFOA _                      ' __in_opt PCREDUI_INFOA pUiInfo
 , BYVAL dwAuthError AS DWORD _                         ' __in unsigned long dwAuthError
 , BYREF pszPackage AS ASCIIZ _                         ' __in PCSTR pszPackage
 , BYVAL pInputAuthIdentity AS DWORD _                  ' __in_opt PSEC_WINNT_AUTH_IDENTITY_OPAQUE pInputAuthIdentity
 , BYREF ppAuthIdentity AS DWORD _                      ' __out PSEC_WINNT_AUTH_IDENTITY_OPAQUE* ppAuthIdentity
 , BYREF pfSave AS LONG _                               ' __inout_opt int* pfSave
 , BYVAL dwFlags AS DWORD _                             ' __in unsigned long dwFlags
 ) AS DWORD                                             ' unsigned long
#ENDIF

#IF %DEF(%UNICODE)
   MACRO SspiPromptForCredentials = SspiPromptForCredentialsW
#ELSE
   MACRO SspiPromptForCredentials = SspiPromptForCredentialsA
#ENDIF

'#endif // _SSPIPFC_NONE_

'#ifdef _SEC_WINNT_AUTH_TYPES

' // Size = 8 bytes
TYPE SEC_WINNT_AUTH_BYTE_VECTOR DWORD
   ByteArrayOffset AS DWORD   ' unsigned long // each element is a byte
   ByteArrayLength AS WORD    ' unsigned short
END TYPE

' // Size = 24 bytes
TYPE SEC_WINNT_AUTH_DATA DWORD
   CredType AS GUID   ' GUID
   CredData AS SEC_WINNT_AUTH_BYTE_VECTOR
END TYPE

' // Size = 28 bytes
TYPE SEC_WINNT_AUTH_PACKED_CREDENTIALS DWORD FILL
   cbHeaderLength    AS WORD                  ' unsigned short // the length of the header
   cbStructureLength AS WORD                  ' unsigned short // pay load length including the header
   AuthData          AS SEC_WINNT_AUTH_DATA
END TYPE

'// {28BFC32F-10F6-4738-98D1-1AC061DF716A}
'static const GUID SEC_WINNT_AUTH_DATA_TYPE_PASSWORD =
'   { 0x28bfc32f, 0x10f6, 0x4738, { 0x98, 0xd1, 0x1a, 0xc0, 0x61, 0xdf, 0x71, 0x6a } };
$SEC_WINNT_AUTH_DATA_TYPE_PASSWORD = GUID$("{28BFC32F-10F6-4738-98D1-1AC061DF716A}")

'// {235F69AD-73FB-4dbc-8203-0629E739339B}
'static const GUID SEC_WINNT_AUTH_DATA_TYPE_CERT =
'   { 0x235f69ad, 0x73fb, 0x4dbc, { 0x82, 0x3, 0x6, 0x29, 0xe7, 0x39, 0x33, 0x9b } };
$SEC_WINNT_AUTH_DATA_TYPE_CERT = GUID$("{235F69AD-73FB-4dbc-8203-0629E739339B}")

' // Size = 8 bytes
TYPE SEC_WINNT_AUTH_DATA_PASSWORD DWORD
   UnicodePassword AS SEC_WINNT_AUTH_BYTE_VECTOR
END TYPE

'//
'// smartcard cred data
'//
'// {68FD9879-079C-4dfe-8281-578AADC1C100}

'static const GUID SEC_WINNT_AUTH_DATA_TYPE_CSP_DATA =
'   { 0x68fd9879, 0x79c, 0x4dfe, { 0x82, 0x81, 0x57, 0x8a, 0xad, 0xc1, 0xc1, 0x0 } };
$SEC_WINNT_AUTH_DATA_TYPE_CSP_DATA = GUID$("{68fd9879-079c-4dfe-8281-578aadc1c100}")

' // Size = 12 bytes
TYPE SEC_WINNT_AUTH_CERTIFICATE_DATA DWORD FILL
   cbHeaderLength    AS WORD   ' unsigned short
   cbStructureLength AS WORD   ' unsigned short
   Certificate       AS SEC_WINNT_AUTH_BYTE_VECTOR
END TYPE

' // Size = 8 bytes
TYPE SEC_WINNT_CREDUI_CONTEXT_VECTOR DWORD
   CredUIContextArrayOffset AS DWORD   ' ULONG // offset starts at the beginning of
   ' // this structure, and each element is a SEC_WINNT_AUTH_BYTE_VECTOR that
   ' // describes the flat CredUI context returned by SpGetCredUIContext()
   CredUIContextCount AS WORD   ' USHORT
END TYPE

' // Size = 8 bytes
TYPE SEC_WINNT_AUTH_SHORT_VECTOR DWORD
   ShortArrayOffset AS DWORD   ' ULONG // each element is a short
   ShortArrayCount  AS WORD    ' USHORT // number of characters
END TYPE

'// free the returned memory using SspiLocalFree

DECLARE FUNCTION SspiGetCredUIContext IMPORT "CREDUI.DLL" ALIAS "SspiGetCredUIContext" ( _
   BYVAL ContextHandle AS DWORD _                       ' __in HANDLE ContextHandle
 , BYREF CredType AS GUID _                             ' __in GUID* CredType
 , BYREF LogonId AS QUAD _                              ' __in_opt LUID* LogonId // use this LogonId, the caller must be localsystem to supply a logon id
 , BYREF CredUIContexts AS SEC_WINNT_CREDUI_CONTEXT_VECTOR _ ' __out PSEC_WINNT_CREDUI_CONTEXT_VECTOR* CredUIContexts
 , BYREF TokenHandle AS DWORD _                         ' __out_opt HANDLE* TokenHandle
 ) AS LONG                                              ' SECURITY_STATUS

DECLARE FUNCTION SspiUpdateCredentials IMPORT "CREDUI.DLL" ALIAS "SspiUpdateCredentials" ( _
   BYVAL ContextHandle AS DWORD _                       ' __in HANDLE ContextHandle
 , BYREF CredType AS GUID _                             ' __in GUID* CredType
 , BYVAL FlatCredUIContextLength AS DWORD _             ' __in ULONG FlatCredUIContextLength
 , BYVAL FlatCredUIContext AS BYTE PTR _                ' __in PUCHAR FlatCredUIContext
 ) AS LONG                                              ' SECURITY_STATUS

' // Size = 52 bytes
TYPE CREDUIWIN_MARSHALED_CONTEXT DWORD
   StructureType       AS GUID
   cbHeaderLength      AS WORD    ' USHORT
   LogonId             AS QUAD    ' // user's logon id
   MarshaledDataType   AS GUID
   MarshaledDataOffset AS DWORD   ' ULONG
   MarshaledDataLength AS WORD    ' USHORT
END TYPE

' // Size = 24 bytes
TYPE SEC_WINNT_CREDUI_CONTEXT DWORD
   cbHeaderLength      AS WORD                 ' USHORT
   CredUIContextHandle AS DWORD                ' HANDLE // the handle to call SspiGetCredUIContext()
   UIInfo              AS CREDUI_INFOW PTR     ' PCREDUI_INFOW // input from SspiPromptForCredentials()
   dwAuthError         AS DWORD                ' ULONG // the authentication error
   pInputAuthIdentity  AS DWORD                ' PSEC_WINNT_AUTH_IDENTITY_OPAQUE
   TargetName          AS UNICODE_STRING PTR   ' PUNICODE_STRING
END TYPE

'// {3C3E93D9-D96B-49b5-94A7-458592088337}
'static const GUID CREDUIWIN_STRUCTURE_TYPE_SSPIPFC  =
'{ 0x3c3e93d9, 0xd96b, 0x49b5, { 0x94, 0xa7, 0x45, 0x85, 0x92, 0x8, 0x83, 0x37 } };
$CREDUIWIN_STRUCTURE_TYPE_SSPIPFC = GUID$("{3C3E93D9-D96B-49b5-94A7-458592088337}")

'// {C2FFFE6F-503D-4c3d-A95E-BCE821213D44}
'static const GUID SSPIPFC_STRUCTURE_TYPE_CREDUI_CONTEXT =
'{ 0xc2fffe6f, 0x503d, 0x4c3d, { 0xa9, 0x5e, 0xbc, 0xe8, 0x21, 0x21, 0x3d, 0x44 } };
$SSPIPFC_STRUCTURE_TYPE_CREDUI_CONTEXT = GUID$("{C2FFFE6F-503D-4c3d-A95E-BCE821213D44}")

' // Size = 24 bytes
TYPE SEC_WINNT_AUTH_PACKED_CREDENTIALS_EX DWORD
   cbHeaderLength    AS WORD    ' unsigned short
   Flags             AS DWORD   ' unsigned long // contains the Flags field in
                                ' // SEC_WINNT_AUTH_IDENTITY_EX
   PackedCredentials AS SEC_WINNT_AUTH_BYTE_VECTOR
   PackageList       AS SEC_WINNT_AUTH_SHORT_VECTOR
END TYPE

'//
'// free the returned memory using SspiLocalFree
'//

DECLARE FUNCTION SspiUnmarshalCredUIContext IMPORT "CREDUI.DLL" ALIAS "SspiUnmarshalCredUIContext" ( _
   BYVAL MarshaledCredUIContext AS BYTE PTR _           ' __in PUCHAR MarshaledCredUIContext
 , BYVAL MarshaledCredUIContextLength AS DWORD _        ' __in ULONG MarshaledCredUIContextLength
 , BYREF CredUIContext AS SEC_WINNT_CREDUI_CONTEXT _    ' __out PSEC_WINNT_CREDUI_CONTEXT* CredUIContext
 ) AS LONG                                              ' SECURITY_STATUS

'#endif // _SEC_WINNT_AUTH_TYPES

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SspiPrepareForCredRead LIB "Secur32.dll" _
    ALIAS "SspiPrepareForCredRead" ( _
    AuthIdentity           AS ANY, _  ' SEC_WINNT_AUTH_IDENTITY_OPAQUE
    pszTargetName          AS WSTRINGZ, _
    pCredmanCredentialType AS DWORD, _
    ppszCredmanTargetName  AS ANY _  ' PCWSTR*
    ) AS LONG
#ELSE
DECLARE FUNCTION SspiPrepareForCredRead IMPORT "SspiCli.dll" ALIAS "SspiPrepareForCredRead" ( _
   BYVAL AuthIdentity AS DWORD _                        ' __in PSEC_WINNT_AUTH_IDENTITY_OPAQUE AuthIdentity
 , BYREF pszTargetName AS WSTRINGZ _                    ' __in PCWSTR pszTargetName
 , BYREF pCredmanCredentialType AS DWORD _              ' __out PULONG pCredmanCredentialType
 , BYREF ppszCredmanTargetName AS ANY _                 ' __out PCWSTR* ppszCredmanTargetName
 ) AS LONG                                              ' SECURITY_STATUS
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SspiPrepareForCredWrite LIB "Secur32.dll" _
    ALIAS "SspiPrepareForCredWrite" ( _
    AuthIdentity           AS ANY, _  ' SEC_WINNT_AUTH_IDENTITY_OPAQUE, _
    pszTargetName          AS WSTRINGZ, _ ' supply NULL for username-target credentials
    pCredmanCredentialType AS DWORD, _
    ppszCredmanTargetName  AS ANY, _  ' PCWSTR*
    ppszCredmanUserName    AS ANY, _  ' PCWSTR*
    ppCredentialBlob       AS ANY, _  ' PUCHAR *
    pCredentialBlobSize    AS DWORD _
    ) AS LONG
#ELSE
DECLARE FUNCTION SspiPrepareForCredWrite IMPORT "SspiCli.dll" ALIAS "SspiPrepareForCredWrite" ( _
   BYVAL AuthIdentity AS DWORD _                        ' __in PSEC_WINNT_AUTH_IDENTITY_OPAQUE AuthIdentity
 , BYREF pszTargetName AS WSTRINGZ _                    ' __in_opt PCWSTR pszTargetName // supply NULL for username-target credentials
 , BYREF pCredmanCredentialType AS DWORD _              ' __out PULONG pCredmanCredentialType
 , BYREF ppszCredmanTargetName AS DWORD _               ' __out PCWSTR* ppszCredmanTargetName
 , BYREF ppszCredmanUserName AS DWORD _                 ' __out PCWSTR* ppszCredmanUserName
 , BYREF ppCredentialBlob AS DWORD _                    ' __out PUCHAR *ppCredentialBlob
 , BYREF pCredentialBlobSize AS DWORD _                 ' __out PULONG pCredentialBlobSize
 ) AS LONG                                              ' SECURITY_STATUS
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SspiEncryptAuthIdentity LIB "Secur32.dll" _
    ALIAS "SspiEncryptAuthIdentity" ( _
    AuthData AS ANY _  ' SEC_WINNT_AUTH_IDENTITY_OPAQUE
    ) AS LONG
#ELSE
DECLARE FUNCTION SspiEncryptAuthIdentity IMPORT "SspiCli.dll" ALIAS "SspiEncryptAuthIdentity" ( _
   BYVAL AuthData AS DWORD _                            ' __inout PSEC_WINNT_AUTH_IDENTITY_OPAQUE AuthData
 ) AS LONG                                              ' SECURITY_STATUS
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SspiDecryptAuthIdentity LIB "Secur32.dll" _
    ALIAS "SspiDecryptAuthIdentity" ( _
    EncryptedAuthData AS ANY _  ' SEC_WINNT_AUTH_IDENTITY_OPAQUE
    ) AS LONG
#ELSE
DECLARE FUNCTION SspiDecryptAuthIdentity IMPORT "SspiCli.dll" ALIAS "SspiDecryptAuthIdentity" ( _
   BYVAL EncryptedAuthData AS DWORD _                   ' __inout PSEC_WINNT_AUTH_IDENTITY_OPAQUE EncryptedAuthData
 ) AS LONG                                              ' SECURITY_STATUS
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SspiIsAuthIdentityEncrypted LIB "Secur32.dll" _
    ALIAS "SspiIsAuthIdentityEncrypted" ( _
    EncryptedAuthData AS ANY _  ' SEC_WINNT_AUTH_IDENTITY_OPAQUE
    ) AS BYTE  ' BOOLEAN
#ELSE
DECLARE FUNCTION SspiIsAuthIdentityEncrypted IMPORT "SspiCli.dll" ALIAS "SspiIsAuthIdentityEncrypted" ( _
   BYVAL EncryptedAuthData AS DWORD _                   ' __inout PSEC_WINNT_AUTH_IDENTITY_OPAQUE EncryptedAuthData
 ) AS BYTE                                              ' BOOLEAN
#ENDIF

'#if (NTDDI_VERSION >= NTDDI_WIN7)
'//
'//  Convert the _OPAQUE structure passed in to the
'//  3 tuple <username, domainname, 'password'>.
'//
'//  Note: The 'strings' returned need not necessarily be
'//  in user recognisable form. The purpose of this API
'//  is to 'flatten' the _OPAQUE structure into the 3 tuple.
'//  User recognisable <username, domainname> can always be
'//  obtained by passing NULL to the pszPackedCredentialsString
'//  parameter.
'//
'// zero out the pszPackedCredentialsString then
'// free the returned memory using SspiLocalFree()
'//

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SspiEncodeAuthIdentityAsStrings LIB "Secur32.dll" _
    ALIAS "SspiEncodeAuthIdentityAsStrings" ( _
    pAuthIdentity               AS ANY, _  ' SEC_WINNT_AUTH_IDENTITY_OPAQUE
    ppszUserName                AS ANY, _  ' PCWSTR*
    ppszDomainName              AS ANY, _  ' PCWSTR*
    ppszPackedCredentialsString AS ANY _   ' PCWSTR*
    ) AS LONG
#ELSE
DECLARE FUNCTION SspiEncodeAuthIdentityAsStrings IMPORT "SspiCli.dll" ALIAS "SspiEncodeAuthIdentityAsStrings" ( _
   BYVAL pAuthIdentity AS DWORD _                       ' __in PSEC_WINNT_AUTH_IDENTITY_OPAQUE pAuthIdentity
 , BYREF ppszUserName AS DWORD _                        ' __out_opt PCWSTR* ppszUserName
 , BYREF ppszDomainName AS DWORD _                      ' __out_opt PCWSTR* ppszDomainName
 , BYREF ppszPackedCredentialsString AS DWORD _         ' __out_opt PCWSTR* ppszPackedCredentialsString
 ) AS LONG                                              ' SECURITY_STATUS
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SspiValidateAuthIdentity LIB "Secur32.dll" _
    ALIAS "SspiValidateAuthIdentity" ( _
    AuthData AS ANY _  ' SEC_WINNT_AUTH_IDENTITY_OPAQUE
    ) AS LONG
#ELSE
DECLARE FUNCTION SspiValidateAuthIdentity IMPORT "SspiCli.dll" ALIAS "SspiValidateAuthIdentity" ( _
   BYVAL AuthData AS DWORD _                            ' __in PSEC_WINNT_AUTH_IDENTITY_OPAQUE AuthData
 ) AS LONG                                              ' SECURITY_STATUS
#ENDIF

'//
'// free the returned memory using SspiFreeAuthIdentity()
'//

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SspiCopyAuthIdentity LIB "Secur32.dll" _
    ALIAS "SspiCopyAuthIdentity" ( _
    AuthData     AS ANY, _  ' SEC_WINNT_AUTH_IDENTITY_OPAQUE, _
    AuthDataCopy AS ANY _   ' SEC_WINNT_AUTH_IDENTITY_OPAQUE ptr ptr
    ) AS LONG
#ELSE
DECLARE FUNCTION SspiCopyAuthIdentity IMPORT "SspiCli.dll" ALIAS "SspiCopyAuthIdentity" ( _
   BYVAL AuthData AS DWORD _                            ' __in PSEC_WINNT_AUTH_IDENTITY_OPAQUE AuthData
 , BYREF AuthDataCopy AS DWORD _                        ' __out PSEC_WINNT_AUTH_IDENTITY_OPAQUE* AuthDataCopy
 ) AS LONG                                              ' SECURITY_STATUS
#ENDIF

'//
'// use only for the memory returned by SspiCopyAuthIdentity().
'// Internally calls SspiZeroAuthIdentity().
'//

#IF %DEF(%USEPBDECL)
DECLARE SUB SspiFreeAuthIdentity LIB "Secur32.dll" _
    ALIAS "SspiFreeAuthIdentity" ( _
    AuthData AS ANY _  ' SEC_WINNT_AUTH_IDENTITY_OPAQUE
    )
#ELSE
DECLARE SUB SspiFreeAuthIdentity IMPORT "SspiCli.dll" ALIAS "SspiFreeAuthIdentity" ( _
   BYVAL AuthData AS DWORD _                            ' __in PSEC_WINNT_AUTH_IDENTITY_OPAQUE AuthData
 )                                                      ' void
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE SUB SspiZeroAuthIdentity LIB "Secur32.dll" _
    ALIAS "SspiZeroAuthIdentity" ( _
    AuthData AS ANY _  ' SEC_WINNT_AUTH_IDENTITY_OPAQUE
    )
#ELSE
DECLARE SUB SspiZeroAuthIdentity IMPORT "SspiCli.dll" ALIAS "SspiZeroAuthIdentity" ( _
   BYVAL AuthData AS DWORD _                            ' __in PSEC_WINNT_AUTH_IDENTITY_OPAQUE AuthData
 )                                                      ' void
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE SUB SspiLocalFree LIB "Secur32.dll" ALIAS "SspiLocalFree" ( _
    DataBuffer AS ANY _  ' VOID PTR
    )
#ELSE
DECLARE SUB SspiLocalFree IMPORT "SspiCli.dll" ALIAS "SspiLocalFree" ( _
   BYVAL DataBuffer AS DWORD _                          ' __in_opt PVOID DataBuffer
 )                                                      ' void
#ENDIF

'//
'// call SspiFreeAuthIdentity to free the returned AuthIdentity
'// which zeroes out the credentials blob before freeing it
'//

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SspiEncodeStringsAsAuthIdentity LIB "Secur32.dll" _
    ALIAS "SspiEncodeStringsAsAuthIdentity" ( _
    pszUserName                AS WSTRINGZ, _
    pszDomainName              AS WSTRINGZ, _
    pszPackedCredentialsString AS WSTRINGZ, _
    ppAuthIdentity             AS ANY _  ' SEC_WINNT_AUTH_IDENTITY_OPAQUE ptr ptr
    ) AS LONG
#ELSE
DECLARE FUNCTION SspiEncodeStringsAsAuthIdentity IMPORT "SspiCli.dll" ALIAS "SspiEncodeStringsAsAuthIdentity" ( _
   BYREF pszUserName AS WSTRINGZ _                      ' __in_opt PCWSTR pszUserName
 , BYREF pszDomainName AS WSTRINGZ _                    ' __in_opt PCWSTR pszDomainName
 , BYREF pszPackedCredentialsString AS WSTRINGZ _       ' __in_opt PCWSTR pszPackedCredentialsString
 , BYREF ppAuthIdentity AS DWORD _                      ' __out PSEC_WINNT_AUTH_IDENTITY_OPAQUE* ppAuthIdentity
 ) AS LONG                                              ' SECURITY_STATUS
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SspiCompareAuthIdentities LIB "Secur32.dll" _
    ALIAS "SspiCompareAuthIdentities" ( _
    AuthIdentity1        AS ANY, _   ' SEC_WINNT_AUTH_IDENTITY_OPAQUE
    AuthIdentity2        AS ANY, _   ' SEC_WINNT_AUTH_IDENTITY_OPAQUE
    SameSuppliedUser     AS BYTE, _  ' BOOLEAN
    SameSuppliedIdentity AS BYTE _   ' BOOLEAN
    ) AS LONG
#ELSE
DECLARE FUNCTION SspiCompareAuthIdentities IMPORT "SspiCli.dll" ALIAS "SspiCompareAuthIdentities" ( _
   BYVAL AuthIdentity1 AS DWORD _                       ' __in_opt PSEC_WINNT_AUTH_IDENTITY_OPAQUE AuthIdentity1
 , BYVAL AuthIdentity2 AS DWORD _                       ' __in_opt PSEC_WINNT_AUTH_IDENTITY_OPAQUE AuthIdentity2
 , BYREF SameSuppliedUser AS BYTE _                     ' __out_opt PBOOLEAN SameSuppliedUser
 , BYREF SameSuppliedIdentity AS BYTE _                 ' __out_opt PBOOLEAN SameSuppliedIdentity
 ) AS LONG                                              ' SECURITY_STATUS
#ENDIF

'//
'// zero out the returned AuthIdentityByteArray then
'// free the returned memory using SspiLocalFree()
'//

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SspiMarshalAuthIdentity LIB "Secur32.dll" _
    ALIAS "SspiMarshalAuthIdentity" ( _
    AuthIdentity          AS ANY, _ ' SEC_WINNT_AUTH_IDENTITY_OPAQUE
    AuthIdentityLength    AS DWORD, _
    AuthIdentityByteArray AS ANY _  ' char**
    ) AS LONG
#ELSE
DECLARE FUNCTION SspiMarshalAuthIdentity IMPORT "SspiCli.dll" ALIAS "SspiMarshalAuthIdentity" ( _
   BYVAL AuthIdentity AS DWORD _                        ' __in PSEC_WINNT_AUTH_IDENTITY_OPAQUE AuthIdentity
 , BYREF AuthIdentityLength AS LONG _                   ' __out unsigned long* AuthIdentityLength
 , BYREF AuthIdentityByteArray AS STRING _              ' __out char** AuthIdentityByteArray
 ) AS LONG                                              ' SECURITY_STATUS
#ENDIF

'//
'// free the returned auth identity using SspiFreeAuthIdentity()
'//

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SspiUnmarshalAuthIdentity LIB "Secur32.dll" _
    ALIAS "SspiUnmarshalAuthIdentity" ( _
    BYVAL AuthIdentityLength    AS DWORD, _
    BYVAL AuthIdentityByteArray AS BYTE PTR, _
    ppAuthIdentity              AS ANY _  ' SEC_WINNT_AUTH_IDENTITY_OPAQUE ptr ptr
    ) AS LONG
#ELSE
DECLARE FUNCTION SspiUnmarshalAuthIdentity IMPORT "SspiCli.dll" ALIAS "SspiUnmarshalAuthIdentity" ( _
   BYVAL AuthIdentityLength AS LONG _                   ' __in unsigned long AuthIdentityLength
 , BYREF AuthIdentityByteArray AS BYTE _                ' __in char* AuthIdentityByteArray
 , BYREF ppAuthIdentity AS DWORD _                      ' __out PSEC_WINNT_AUTH_IDENTITY_OPAQUE* ppAuthIdentity
 ) AS LONG                                              ' SECURITY_STATUS
#ENDIF

DECLARE FUNCTION SspiIsPromptingNeeded IMPORT "CREDUI.DLL" ALIAS "SspiIsPromptingNeeded" ( _
   BYVAL ErrorOrNtStatus AS DWORD _                     ' __in unsigned long ErrorOrNtStatus
 ) AS BYTE                                              ' BOOLEAN

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SspiGetTargetHostName LIB "Secur32.dll" _
    ALIAS "SspiGetTargetHostName" ( _
    pszTargetName AS WSTRINGZ, _
    pszHostName   AS ANY _  ' PWSTR*
    ) AS LONG
#ELSE
DECLARE FUNCTION SspiGetTargetHostName IMPORT "SspiCli.dll" ALIAS "SspiGetTargetHostName" ( _
   BYREF pszTargetName AS WSTRINGZ _                    ' __in PCWSTR pszTargetName
 , BYREF pszHostName AS DWORD _                         ' __out PWSTR* pszHostName
 ) AS LONG                                              ' SECURITY_STATUS
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SspiExcludePackage LIB "Secur32.dll" _
    ALIAS "SspiExcludePackage" ( _
    AuthIdentity      AS ANY, _  ' SEC_WINNT_AUTH_IDENTITY_OPAQUE
    pszPackageName    AS WSTRINGZ, _
    ppNewAuthIdentity AS ANY _   ' SEC_WINNT_AUTH_IDENTITY_OPAQUE ptr ptr
    ) AS LONG
#ELSE
DECLARE FUNCTION SspiExcludePackage IMPORT "SspiCli.dll" ALIAS "SspiExcludePackage" ( _
   BYVAL AuthIdentity AS DWORD _                        ' __in_opt PSEC_WINNT_AUTH_IDENTITY_OPAQUE AuthIdentity
 , BYREF pszPackageName AS WSTRINGZ _                   ' __in PCWSTR pszPackageName
 , BYREF ppNewAuthIdentity AS DWORD _                   ' __out PSEC_WINNT_AUTH_IDENTITY_OPAQUE* ppNewAuthIdentity
 ) AS LONG                                              ' SECURITY_STATUS
#ENDIF

'//
'// Common types used by negotiable security packages
'//

%SEC_WINNT_AUTH_IDENTITY_MARSHALLED = &H4   ' // all data is in one buffer
%SEC_WINNT_AUTH_IDENTITY_ONLY       = &H8   ' // these credentials are for identity only - no PAC needed

'#endif // NTDDI_VERSION
'//
'// Routines for manipulating packages
'//

' // Size = 20 bytes
TYPE SECURITY_PACKAGE_OPTIONS DWORD
   Size          AS DWORD   ' unsigned long
   Type          AS DWORD   ' unsigned long
   Flags         AS DWORD   ' unsigned long
   SignatureSize AS DWORD   ' unsigned long
   Signature     AS DWORD   ' void *
END TYPE

%SECPKG_OPTIONS_TYPE_UNKNOWN = 0
%SECPKG_OPTIONS_TYPE_LSA     = 1
%SECPKG_OPTIONS_TYPE_SSPI    = 2

%SECPKG_OPTIONS_PERMANENT    = &H00000001???

DECLARE FUNCTION AddSecurityPackageA IMPORT "SECUR32.DLL" ALIAS "AddSecurityPackageA" ( _
   BYREF pszPackageName AS ASCIIZ _                     ' __in     LPSTR  pszPackageName
 , BYREF pOptions AS SECURITY_PACKAGE_OPTIONS _         ' __in_opt PSECURITY_PACKAGE_OPTIONS pOptions
 ) AS LONG                                              ' SECURITY_STATUS

DECLARE FUNCTION AddSecurityPackageW IMPORT "SECUR32.DLL" ALIAS "AddSecurityPackageW" ( _
   BYREF pszPackageName AS WSTRINGZ _                   ' __in     LPWSTR pszPackageName
 , BYREF pOptions AS SECURITY_PACKAGE_OPTIONS _         ' __in_opt PSECURITY_PACKAGE_OPTIONS pOptions
 ) AS LONG                                              ' SECURITY_STATUS

#IF %DEF(%UNICODE)
   MACRO AddSecurityPackage = AddSecurityPackageW
#ELSE
   MACRO AddSecurityPackage = AddSecurityPackageA
#ENDIF

DECLARE FUNCTION DeleteSecurityPackageA IMPORT "SECUR32.DLL" ALIAS "DeleteSecurityPackageA" ( _
   BYREF pszPackageName AS ASCIIZ _                     ' __in LPSTR pszPackageName
 ) AS LONG                                              ' SECURITY_STATUS

DECLARE FUNCTION DeleteSecurityPackageW IMPORT "SECUR32.DLL" ALIAS "DeleteSecurityPackageW" ( _
   BYREF pszPackageName AS WSTRINGZ _                   ' __in LPWSTR pszPackageName
 ) AS LONG                                              ' SECURITY_STATUS

#IF %DEF(%UNICODE)
   MACRO DeleteSecurityPackage = DeleteSecurityPackageW
#ELSE
   MACRO DeleteSecurityPackage = DeleteSecurityPackageA
#ENDIF
