' ########################################################################################
' Microsoft Windows
' File: NTSecPkg.inc
' Contents: Structures and APIs for use by a authentication or security package.
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%NTSECPKG_INC = 1

#INCLUDE ONCE "NTSecAPI.inc"
#INCLUDE ONCE "Security.inc"

'/////////////////////////////////////////////////////////////////////////
'//                                                                     //
'// Data types used by authentication packages                          //
'//                                                                     //
'/////////////////////////////////////////////////////////////////////////

'//
'// opaque data type which represents a client request
'//

'typedef PVOID *PLSA_CLIENT_REQUEST;


'//
'// When a logon of a user is requested, the authentication package
'// is expected to return one of the following structures indicating
'// the contents of a user's token.
'//

' enum LSA_TOKEN_INFORMATION_TYPE
%LsaTokenInformationNull = 0    ' // Implies LSA_TOKEN_INFORMATION_NULL data type
%LsaTokenInformationV1   = 1    ' // Implies LSA_TOKEN_INFORMATION_V1 data type
%LsaTokenInformationV2   = 2    ' // Implies LSA_TOKEN_INFORMATION_V2 data type


'//
'// The NULL information is used in cases where a non-authenticated
'// system access is needed.  For example, a non-authentication network
'// circuit (such as LAN Manager's null session) can be given NULL
'// information.  This will result in an anonymous token being generated
'// for the logon that gives the user no ability to access protected system
'// resources, but does allow access to non-protected system resources.
'//

'typedef struct _LSA_TOKEN_INFORMATION_NULL {

'    //
'    // Time at which the security context becomes invalid.
'    // Use a value in the distant future if the context
'    // never expires.
'    //

'    LARGE_INTEGER ExpirationTime;

'    //
'    // The SID(s) of groups the user is to be made a member of.  This should
'    // not include WORLD or other system defined and assigned
'    // SIDs.  These will be added automatically by LSA.
'    //
'    // Each SID is expected to be in a separately allocated block
'    // of memory.  The TOKEN_GROUPS structure is also expected to
'    // be in a separately allocated block of memory.
'    //

'    PTOKEN_GROUPS Groups;

'} LSA_TOKEN_INFORMATION_NULL, *PLSA_TOKEN_INFORMATION_NULL;

' // Size = 16 bytes
TYPE LSA_TOKEN_INFORMATION_NULL   ' Must be 8 byte aligned
   ExpirationTime AS QUAD               ' LARGE_INTEGER
   Groups         AS TOKEN_GROUPS PTR   ' PTOKEN_GROUPS
   alignment__    AS DWORD
END TYPE

'//
'// The V1 token information structure is superceeded by the V2 token
'// information structure.  The V1 strucure should only be used for
'// backwards compatability.
'// This structure contains information that an authentication package
'// can place in a Version 1 NT token object.
'//

'typedef struct _LSA_TOKEN_INFORMATION_V1 {

'    //
'    // Time at which the security context becomes invalid.
'    // Use a value in the distant future if the context
'    // never expires.
'    //

'    LARGE_INTEGER ExpirationTime;

'    //
'    // The SID of the user logging on.  The SID value is in a
'    // separately allocated block of memory.
'    //

'    TOKEN_USER User;

'    //
'    // The SID(s) of groups the user is a member of.  This should
'    // not include WORLD or other system defined and assigned
'    // SIDs.  These will be added automatically by LSA.
'    //
'    // Each SID is expected to be in a separately allocated block
'    // of memory.  The TOKEN_GROUPS structure is also expected to
'    // be in a separately allocated block of memory.
'    //

'    PTOKEN_GROUPS Groups;

'    //
'    // This field is used to establish the primary group of the user.
'    // This value does not have to correspond to one of the SIDs
'    // assigned to the user.
'    //
'    // The SID pointed to by this structure is expected to be in
'    // a separately allocated block of memory.
'    //
'    // This field is mandatory and must be filled in.
'    //

'    TOKEN_PRIMARY_GROUP PrimaryGroup;



'    //
'    // The privileges the user is assigned.  This list of privileges
'    // will be augmented or over-ridden by any local security policy
'    // assigned privileges.
'    //
'    // Each privilege is expected to be in a separately allocated
'    // block of memory.  The TOKEN_PRIVILEGES structure is also
'    // expected to be in a separately allocated block of memory.
'    //
'    // If there are no privileges to assign to the user, this field
'    // may be set to NULL.
'    //

'    PTOKEN_PRIVILEGES Privileges;



'    //
'    // This field may be used to establish an explicit default
'    // owner.  Normally, the user ID is used as the default owner.
'    // If another value is desired, it must be specified here.
'    //
'    // The Owner.Sid field may be set to NULL to indicate there is no
'    // alternate default owner value.
'    //

'    TOKEN_OWNER Owner;

'    //
'    // This field may be used to establish a default
'    // protection for the user.  If no value is provided, then
'    // a default protection that grants everyone all access will
'    // be established.
'    //
'    // The DefaultDacl.DefaultDacl field may be set to NULL to indicate
'    // there is no default protection.
'    //

'    TOKEN_DEFAULT_DACL DefaultDacl;

'} LSA_TOKEN_INFORMATION_V1, *PLSA_TOKEN_INFORMATION_V1;

' // Size = 40 bytes
TYPE LSA_TOKEN_INFORMATION_V1   ' Must be 8 byte aligned
   ExpirationTime AS QUAD                   ' LARGE_INTEGER
   User           AS TOKEN_USER
   Groups         AS TOKEN_GROUPS PTR       ' PTOKEN_GROUPS
   PrimaryGroup   AS TOKEN_PRIMARY_GROUP
   Privileges     AS TOKEN_PRIVILEGES PTR   ' PTOKEN_PRIVILEGES
   Owner          AS TOKEN_OWNER
   DefaultDacl    AS TOKEN_DEFAULT_DACL
   alignment__    AS DWORD
END TYPE

'//
'// The V2 information is used in most cases of logon.  The structure is identical
'// to the V1 token information structure, with the exception that the memory allocation
'// is handled differently.  The LSA_TOKEN_INFORMATION_V2 structure is intended to be
'// allocated monolithiclly, with the privileges, DACL, sids, and group array either part of
'// same allocation, or allocated and freed externally.
'//

'typedef LSA_TOKEN_INFORMATION_V1 LSA_TOKEN_INFORMATION_V2, *PLSA_TOKEN_INFORMATION_V2;

'/////////////////////////////////////////////////////////////////////////
'//                                                                     //
'// Interface definitions available for use by authentication packages  //
'//                                                                     //
'/////////////////////////////////////////////////////////////////////////

'typedef NTSTATUS
'(NTAPI LSA_CREATE_LOGON_SESSION) (
'    IN PLUID LogonId
'    );

'FUNCTION LSA_CREATE_LOGON_SESSION ( _
'   BYREF LogonId AS QUAD _                              ' __in PLUID LogonId
' ) AS LONG                                              ' NTSTATUS

'typedef NTSTATUS
'(NTAPI LSA_DELETE_LOGON_SESSION) (
'    IN PLUID LogonId
'    );

'FUNCTION LSA_DELETE_LOGON_SESSION ( _
'   BYREF LogonId AS QUAD _                              ' __in PLUID LogonId
' ) AS LONG                                              ' NTSTATUS

'typedef NTSTATUS
'(NTAPI LSA_ADD_CREDENTIAL) (
'    IN PLUID LogonId,
'    IN ULONG AuthenticationPackage,
'    IN PLSA_STRING PrimaryKeyValue,
'    IN PLSA_STRING Credentials
'    );

'FUNCTION LSA_ADD_CREDENTIAL ( _
'   BYREF LogonId AS QUAD _                              ' __in PLUID LogonId
' , BYVAL AuthenticationPackage AS DWORD _               ' __in ULONG AuthenticationPackage
' , BYREF PrimaryKeyValue AS LSA_STRING _                ' __in PLSA_STRING PrimaryKeyValue
' , BYREF Credentials AS LSA_STRING _                    ' __in PLSA_STRING Credentials
' ) AS LONG                                              ' NTSTATUS

'typedef NTSTATUS
'(NTAPI LSA_GET_CREDENTIALS) (
'    IN PLUID LogonId,
'    IN ULONG AuthenticationPackage,
'    IN OUT PULONG QueryContext,
'    IN BOOLEAN RetrieveAllCredentials,
'    IN PLSA_STRING PrimaryKeyValue,
'    OUT PULONG PrimaryKeyLength,
'    IN PLSA_STRING Credentials
'    );

'FUNCTION LSA_GET_CREDENTIALS ( _
'   BYREF LogonId AS QUAD _                              ' __in PLUID LogonId
' , BYVAL AuthenticationPackage AS DWORD _               ' __in ULONG AuthenticationPackage
' , BYREF QueryContext AS DWORD _                        ' __inout PULONG QueryContext
' , BYVAL RetrieveAllCredentials AS BYTE _               ' __in BOOLEAN RetrieveAllCredentials
' , BYREF PrimaryKeyValue AS LSA_STRING _                ' __in PLSA_STRING PrimaryKeyValue
' , BYREF PrimaryKeyLength AS DWORD _                    ' __out PULONG PrimaryKeyLength
' , BYREF Credentials AS LSA_STRING _                    ' __in PLSA_STRING Credentials
' ) AS LONG                                              ' NTSTATUS

'typedef NTSTATUS
'(NTAPI LSA_DELETE_CREDENTIAL) (
'    IN PLUID LogonId,
'    IN ULONG AuthenticationPackage,
'    IN PLSA_STRING PrimaryKeyValue
'    );

'FUNCTION LSA_DELETE_CREDENTIAL ( _
'   BYREF LogonId AS QUAD _                              ' __in PLUID LogonId
' , BYVAL AuthenticationPackage AS DWORD _               ' __in ULONG AuthenticationPackage
' , BYREF PrimaryKeyValue AS LSA_STRING _                ' __in PLSA_STRING PrimaryKeyValue
' ) AS LONG                                              ' NTSTATUS

'typedef PVOID
'(NTAPI LSA_ALLOCATE_LSA_HEAP) (
'    IN ULONG Length
'    );

'FUNCTION LSA_ALLOCATE_LSA_HEAP ( _
'   BYVAL Length AS DWORD _                              ' __in ULONG Length
' ) AS DWORD                                             ' PVOID

'typedef VOID
'(NTAPI LSA_FREE_LSA_HEAP) (
'    IN PVOID Base
'    );

'SUB LSA_FREE_LSA_HEAP ( _
'   BYVAL Base AS DWORD _                                ' __in PVOID Base
' )                                                      ' VOID

'typedef PVOID
'(NTAPI LSA_ALLOCATE_PRIVATE_HEAP) (
'    IN SIZE_T Length
'    );

'FUNCTION LSA_ALLOCATE_PRIVATE_HEAP ( _
'   BYVAL Length AS DWORD _                              ' __in SIZE_T Length
' ) AS DWORD                                             ' PVOID

'typedef VOID
'(NTAPI LSA_FREE_PRIVATE_HEAP) (
'    IN PVOID Base
'    );

'SUB LSA_FREE_PRIVATE_HEAP ( _
'   BYVAL Base AS DWORD _                                ' __in PVOID Base
' )                                                      ' VOID

'typedef NTSTATUS
'(NTAPI LSA_ALLOCATE_CLIENT_BUFFER) (
'    IN PLSA_CLIENT_REQUEST ClientRequest,
'    IN ULONG LengthRequired,
'    OUT PVOID *ClientBaseAddress
'    );

'FUNCTION LSA_ALLOCATE_CLIENT_BUFFER ( _
'   BYVAL ClientRequest AS DWORD _                       ' __in PLSA_CLIENT_REQUEST ClientRequest
' , BYVAL LengthRequired AS DWORD _                      ' __in ULONG LengthRequired
' , BYREF ClientBaseAddress AS DWORD _                   ' __out PVOID *ClientBaseAddress
' ) AS LONG                                              ' NTSTATUS

'typedef NTSTATUS
'(NTAPI LSA_FREE_CLIENT_BUFFER) (
'    IN PLSA_CLIENT_REQUEST ClientRequest,
'    IN PVOID ClientBaseAddress
'    );

'FUNCTION LSA_FREE_CLIENT_BUFFER ( _
'   BYVAL ClientRequest AS DWORD _                       ' __in PLSA_CLIENT_REQUEST ClientRequest
' , BYVAL ClientBaseAddress AS DWORD _                   ' __in PVOID ClientBaseAddress
' ) AS LONG                                              ' NTSTATUS

'typedef NTSTATUS
'(NTAPI LSA_COPY_TO_CLIENT_BUFFER) (
'    IN PLSA_CLIENT_REQUEST ClientRequest,
'    IN ULONG Length,
'    IN PVOID ClientBaseAddress,
'    IN PVOID BufferToCopy
'    );

'FUNCTION LSA_COPY_TO_CLIENT_BUFFER ( _
'   BYVAL ClientRequest AS DWORD _                       ' __in PLSA_CLIENT_REQUEST ClientRequest
' , BYVAL Length AS DWORD _                              ' __in ULONG Length
' , BYVAL ClientBaseAddress AS DWORD _                   ' __in PVOID ClientBaseAddress
' , BYVAL BufferToCopy AS DWORD _                        ' __in PVOID BufferToCopy
' ) AS LONG                                              ' NTSTATUS

'typedef NTSTATUS
'(NTAPI LSA_COPY_FROM_CLIENT_BUFFER) (
'    IN PLSA_CLIENT_REQUEST ClientRequest,
'    IN ULONG Length,
'    IN PVOID BufferToCopy,
'    IN PVOID ClientBaseAddress
'    );

'FUNCTION LSA_COPY_FROM_CLIENT_BUFFER ( _
'   BYVAL ClientRequest AS DWORD _                       ' __in PLSA_CLIENT_REQUEST ClientRequest
' , BYVAL Length AS DWORD _                              ' __in ULONG Length
' , BYVAL BufferToCopy AS DWORD _                        ' __in PVOID BufferToCopy
' , BYVAL ClientBaseAddress AS DWORD _                   ' __in PVOID ClientBaseAddress
' ) AS LONG                                              ' NTSTATUS

'typedef LSA_CREATE_LOGON_SESSION * PLSA_CREATE_LOGON_SESSION;
'typedef LSA_DELETE_LOGON_SESSION * PLSA_DELETE_LOGON_SESSION;
'typedef LSA_ADD_CREDENTIAL * PLSA_ADD_CREDENTIAL;
'typedef LSA_GET_CREDENTIALS * PLSA_GET_CREDENTIALS;
'typedef LSA_DELETE_CREDENTIAL * PLSA_DELETE_CREDENTIAL;
'typedef LSA_ALLOCATE_LSA_HEAP * PLSA_ALLOCATE_LSA_HEAP;
'typedef LSA_FREE_LSA_HEAP * PLSA_FREE_LSA_HEAP;
'typedef LSA_ALLOCATE_PRIVATE_HEAP * PLSA_ALLOCATE_PRIVATE_HEAP;
'typedef LSA_FREE_PRIVATE_HEAP * PLSA_FREE_PRIVATE_HEAP;
'typedef LSA_ALLOCATE_CLIENT_BUFFER * PLSA_ALLOCATE_CLIENT_BUFFER;
'typedef LSA_FREE_CLIENT_BUFFER * PLSA_FREE_CLIENT_BUFFER;
'typedef LSA_COPY_TO_CLIENT_BUFFER * PLSA_COPY_TO_CLIENT_BUFFER;
'typedef LSA_COPY_FROM_CLIENT_BUFFER * PLSA_COPY_FROM_CLIENT_BUFFER;

'//
'// The dispatch table of LSA services which are available to
'// authentication packages.
'//

' // Size = 40 bytes
TYPE LSA_DISPATCH_TABLE DWORD
   CreateLogonSession   AS DWORD   ' PLSA_CREATE_LOGON_SESSION
   DeleteLogonSession   AS DWORD   ' PLSA_DELETE_LOGON_SESSION
   AddCredential        AS DWORD   ' PLSA_ADD_CREDENTIAL
   GetCredentials       AS DWORD   ' PLSA_GET_CREDENTIALS
   DeleteCredential     AS DWORD   ' PLSA_DELETE_CREDENTIAL
   AllocateLsaHeap      AS DWORD   ' PLSA_ALLOCATE_LSA_HEAP
   FreeLsaHeap          AS DWORD   ' PLSA_FREE_LSA_HEAP
   AllocateClientBuffer AS DWORD   ' PLSA_ALLOCATE_CLIENT_BUFFER
   FreeClientBuffer     AS DWORD   ' PLSA_FREE_CLIENT_BUFFER
   CopyToClientBuffer   AS DWORD   ' PLSA_COPY_TO_CLIENT_BUFFER
   CopyFromClientBuffer AS DWORD   ' PLSA_COPY_FROM_CLIENT_BUFFER
END TYPE


'////////////////////////////////////////////////////////////////////////////
'//                                                                        //
'// Interface definitions of services provided by authentication packages  //
'//                                                                        //
'////////////////////////////////////////////////////////////////////////////

'//
'// Routine names
'//
'// The routines provided by the DLL must be assigned the following names
'// so that their addresses can be retrieved when the DLL is loaded.
'//

'#define LSA_AP_NAME_INITIALIZE_PACKAGE      "LsaApInitializePackage\0"
'#define LSA_AP_NAME_LOGON_USER              "LsaApLogonUser\0"
'#define LSA_AP_NAME_LOGON_USER_EX           "LsaApLogonUserEx\0"
'#define LSA_AP_NAME_CALL_PACKAGE            "LsaApCallPackage\0"
'#define LSA_AP_NAME_LOGON_TERMINATED        "LsaApLogonTerminated\0"
'#define LSA_AP_NAME_CALL_PACKAGE_UNTRUSTED  "LsaApCallPackageUntrusted\0"
'#define LSA_AP_NAME_CALL_PACKAGE_PASSTHROUGH "LsaApCallPackagePassthrough\0"

$LSA_AP_NAME_INITIALIZE_PACKAGE       = "LsaApInitializePackage"
$LSA_AP_NAME_LOGON_USER               = "LsaApLogonUser"
$LSA_AP_NAME_LOGON_USER_EX            = "LsaApLogonUserEx"
$LSA_AP_NAME_CALL_PACKAGE             = "LsaApCallPackage"
$LSA_AP_NAME_LOGON_TERMINATED         = "LsaApLogonTerminated"
$LSA_AP_NAME_CALL_PACKAGE_UNTRUSTED   = "LsaApCallPackageUntrusted"
$LSA_AP_NAME_CALL_PACKAGE_PASSTHROUGH = "LsaApCallPackagePassthrough"

'//
'// Routine templates
'//

'typedef NTSTATUS
'(NTAPI LSA_AP_INITIALIZE_PACKAGE) (
'    IN ULONG AuthenticationPackageId,
'    IN PLSA_DISPATCH_TABLE LsaDispatchTable,
'    IN PLSA_STRING Database OPTIONAL,
'    IN PLSA_STRING Confidentiality OPTIONAL,
'    OUT PLSA_STRING *AuthenticationPackageName
'    );

'FUNCTION LSA_AP_INITIALIZE_PACKAGE ( _
'   BYVAL AuthenticationPackageId AS DWORD _             ' __in ULONG AuthenticationPackageId
' , BYREF LsaDispatchTable AS LSA_DISPATCH_TABLE _       ' __in PLSA_DISPATCH_TABLE LsaDispatchTable
' , BYREF Database AS LSA_STRING _                       ' __in PLSA_STRING Database OPTIONAL
' , BYREF Confidentiality AS LSA_STRING _                ' __in PLSA_STRING Confidentiality OPTIONAL
' , BYREF AuthenticationPackageName AS LSA_STRING _      ' __out PLSA_STRING *AuthenticationPackageName
' ) AS LONG                                              ' NTSTATUS

'typedef NTSTATUS
'(NTAPI LSA_AP_LOGON_USER) (
'    IN PLSA_CLIENT_REQUEST ClientRequest,
'    IN SECURITY_LOGON_TYPE LogonType,
'    IN PVOID AuthenticationInformation,
'    IN PVOID ClientAuthenticationBase,
'    IN ULONG AuthenticationInformationLength,
'    OUT PVOID *ProfileBuffer,
'    OUT PULONG ProfileBufferLength,
'    OUT PLUID LogonId,
'    OUT PNTSTATUS SubStatus,
'    OUT PLSA_TOKEN_INFORMATION_TYPE TokenInformationType,
'    OUT PVOID *TokenInformation,
'    OUT PLSA_UNICODE_STRING *AccountName,
'    OUT PLSA_UNICODE_STRING *AuthenticatingAuthority
'    );

'FUNCTION LSA_AP_LOGON_USER ( _
'   BYVAL ClientRequest AS DWORD _                       ' __in PLSA_CLIENT_REQUEST ClientRequest
' , BYVAL LogonType AS LONG _                            ' __in SECURITY_LOGON_TYPE LogonType
' , BYVAL AuthenticationInformation AS DWORD _           ' __in PVOID AuthenticationInformation
' , BYVAL ClientAuthenticationBase AS DWORD _            ' __in PVOID ClientAuthenticationBase
' , BYVAL AuthenticationInformationLength AS DWORD _     ' __in ULONG AuthenticationInformationLength
' , BYREF ProfileBuffer AS DWORD _                       ' __out PVOID *ProfileBuffer
' , BYREF ProfileBufferLength AS DWORD _                 ' __out PULONG ProfileBufferLength
' , BYREF LogonId AS QUAD _                              ' __out PLUID LogonId
' , BYREF SubStatus AS LONG _                            ' __out PNTSTATUS SubStatus
' , BYREF TokenInformationType AS LONG _                 ' __out PLSA_TOKEN_INFORMATION_TYPE TokenInformationType
' , BYREF TokenInformation AS DWORD _                    ' __out PVOID *TokenInformation
' , BYREF AccountName AS LSA_UNICODE_STRING _            ' __out PLSA_UNICODE_STRING *AccountName
' , BYREF AuthenticatingAuthority AS LSA_UNICODE_STRING _ ' __out PLSA_UNICODE_STRING *AuthenticatingAuthority
' ) AS LONG                                              ' NTSTATUS

'typedef NTSTATUS
'(NTAPI LSA_AP_LOGON_USER_EX) (
'    IN PLSA_CLIENT_REQUEST ClientRequest,
'    IN SECURITY_LOGON_TYPE LogonType,
'    IN PVOID AuthenticationInformation,
'    IN PVOID ClientAuthenticationBase,
'    IN ULONG AuthenticationInformationLength,
'    OUT PVOID *ProfileBuffer,
'    OUT PULONG ProfileBufferLength,
'    OUT PLUID LogonId,
'    OUT PNTSTATUS SubStatus,
'    OUT PLSA_TOKEN_INFORMATION_TYPE TokenInformationType,
'    OUT PVOID *TokenInformation,
'    OUT PUNICODE_STRING *AccountName,
'    OUT PUNICODE_STRING *AuthenticatingAuthority,
'    OUT PUNICODE_STRING *MachineName
'    );

'FUNCTION LSA_AP_LOGON_USER_EX ( _
'   BYVAL ClientRequest AS DWORD _                       ' __in PLSA_CLIENT_REQUEST ClientRequest
' , BYVAL LogonType AS LONG _                            ' __in SECURITY_LOGON_TYPE LogonType
' , BYVAL AuthenticationInformation AS DWORD _           ' __in PVOID AuthenticationInformation
' , BYVAL ClientAuthenticationBase AS DWORD _            ' __in PVOID ClientAuthenticationBase
' , BYVAL AuthenticationInformationLength AS DWORD _     ' __in ULONG AuthenticationInformationLength
' , BYREF ProfileBuffer AS DWORD _                       ' __out PVOID *ProfileBuffer
' , BYREF ProfileBufferLength AS DWORD _                 ' __out PULONG ProfileBufferLength
' , BYREF LogonId AS QUAD _                              ' __out PLUID LogonId
' , BYREF SubStatus AS LONG _                            ' __out PNTSTATUS SubStatus
' , BYREF TokenInformationType AS LONG _                 ' __out PLSA_TOKEN_INFORMATION_TYPE TokenInformationType
' , BYREF TokenInformation AS DWORD _                    ' __out PVOID *TokenInformation
' , BYREF AccountName AS LSA_UNICODE_STRING _            ' __out PLSA_UNICODE_STRING *AccountName
' , BYREF AuthenticatingAuthority AS LSA_UNICODE_STRING _ ' __out PLSA_UNICODE_STRING *AuthenticatingAuthority
' , BYREF MachineName AS UNICODE_STRING _                ' __out PUNICODE_STRING *MachineName
' ) AS LONG                                              ' NTSTATUS

'typedef NTSTATUS
'(NTAPI LSA_AP_CALL_PACKAGE) (
'    IN PLSA_CLIENT_REQUEST ClientRequest,
'    IN PVOID ProtocolSubmitBuffer,
'    IN PVOID ClientBufferBase,
'    IN ULONG SubmitBufferLength,
'    OUT PVOID *ProtocolReturnBuffer,
'    OUT PULONG ReturnBufferLength,
'    OUT PNTSTATUS ProtocolStatus
'    );

'FUNCTION LSA_AP_LOGON_USER_EX ( _
'   BYVAL ClientRequest AS DWORD _                       ' __in PLSA_CLIENT_REQUEST ClientRequest
' , BYVAL ProtocolSubmitBuffer AS DWORD _                ' __in PVOID ProtocolSubmitBuffer
' , BYVAL ClientBufferBase AS DWORD _                    ' __in PVOID ClientBufferBase
' , BYVAL SubmitBufferLength AS DWORD _                  ' __in ULONG SubmitBufferLength
' , BYREF ProtocolReturnBuffer AS DWORD _                ' __out PVOID *ProtocolReturnBuffer
' , BYREF ReturnBufferLength AS DWORD _                  ' __out PULONG ReturnBufferLength
' , BYREF ProtocolStatus AS LONG _                       ' __out PNTSTATUS ProtocolStatus
' ) AS LONG                                              ' NTSTATUS

'typedef NTSTATUS
'(NTAPI LSA_AP_CALL_PACKAGE_PASSTHROUGH) (
'    IN PLSA_CLIENT_REQUEST ClientRequest,
'    IN PVOID ProtocolSubmitBuffer,
'    IN PVOID ClientBufferBase,
'    IN ULONG SubmitBufferLength,
'    OUT PVOID *ProtocolReturnBuffer,
'    OUT PULONG ReturnBufferLength,
'    OUT PNTSTATUS ProtocolStatus
'    );

'FUNCTION LSA_AP_CALL_PACKAGE_PASSTHROUGH ( _
'   BYVAL ClientRequest AS DWORD _                       ' __in PLSA_CLIENT_REQUEST ClientRequest
' , BYVAL ProtocolSubmitBuffer AS DWORD _                ' __in PVOID ProtocolSubmitBuffer
' , BYVAL ClientBufferBase AS DWORD _                    ' __in PVOID ClientBufferBase
' , BYVAL SubmitBufferLength AS DWORD _                  ' __in ULONG SubmitBufferLength
' , BYREF ProtocolReturnBuffer AS DWORD _                ' __out PVOID *ProtocolReturnBuffer
' , BYREF ReturnBufferLength AS DWORD _                  ' __out PULONG ReturnBufferLength
' , BYREF ProtocolStatus AS LONG _                       ' __out PNTSTATUS ProtocolStatus
' ) AS LONG                                              ' NTSTATUS

'typedef VOID
'(NTAPI LSA_AP_LOGON_TERMINATED) (
'    IN PLUID LogonId
'    );

'SUB LSA_AP_LOGON_TERMINATED ( _
'   BYREF LogonId AS QUAD _                              ' __in PLUID LogonId
' )                                                      ' VOID

'typedef LSA_AP_CALL_PACKAGE LSA_AP_CALL_PACKAGE_UNTRUSTED;

'typedef LSA_AP_INITIALIZE_PACKAGE * PLSA_AP_INITIALIZE_PACKAGE;
'typedef LSA_AP_LOGON_USER * PLSA_AP_LOGON_USER;
'typedef LSA_AP_LOGON_USER_EX * PLSA_AP_LOGON_USER_EX;
'typedef LSA_AP_CALL_PACKAGE * PLSA_AP_CALL_PACKAGE;
'typedef LSA_AP_CALL_PACKAGE_PASSTHROUGH * PLSA_AP_CALL_PACKAGE_PASSTHROUGH;
'typedef LSA_AP_LOGON_TERMINATED * PLSA_AP_LOGON_TERMINATED;
'typedef LSA_AP_CALL_PACKAGE_UNTRUSTED * PLSA_AP_CALL_PACKAGE_UNTRUSTED;


#IF NOT %DEF(%SAM_CREDENTIAL_UPDATE_DEFINED)
    %SAM_CREDENTIAL_UPDATE_DEFINED = 1

'FUNCTION SAM_CREDENTIAL_UPDATE_NOTIFY_ROUTINE ( _
'   BYREF ClearPassword AS UNICODE_STRING _              ' __in PUNICODE_STRING ClearPassword
' , BYVAL OldCredentials AS DWORD _                      ' __in PVOID OldCredentials
' , BYVAL OldCredentialSize AS DWORD _                   ' __in ULONG OldCredentialSize
' , BYVAL UserAccountControl AS DWORD _                  ' __in ULONG UserAccountControl
' , BYREF UPN AS UNICODE_STRING  _                       ' __in_opt PUNICODE_STRING UPN
' , BYREF UserName AS UNICODE_STRING _                   ' __in PUNICODE_STRING UserName
' , BYREF NetbiosDomainName AS UNICODE_STRING _          ' __in PUNICODE_STRING NetbiosDomainName
' , BYREF DnsDomainName AS UNICODE_STRING _              ' __in PUNICODE_STRING DnsDomainName
' , BYREF NewCredentials AS DWORD _                      ' __out PVOID * NewCredentials
' , BYREF NewCredentialSize AS DWORD _                   ' __out ULONG * NewCredentialSize
' ) AS LONG                                              ' NTSTATUS

$SAM_CREDENTIAL_UPDATE_NOTIFY_ROUTINE = "CredentialUpdateNotify"

'FUNCTION SAM_CREDENTIAL_UPDATE_REGISTER_ROUTINE ( _
'   BYREF CredentialName AS UNICODE_STRING _             ' __out PUNICODE_STRING CredentialName
' ) AS BYTE                                              ' BOOLEAN

$SAM_CREDENTIAL_UPDATE_REGISTER_ROUTINE = "CredentialUpdateRegister"

'typedef VOID (*PSAM_CREDENTIAL_UPDATE_FREE_ROUTINE) (
'    __in PVOID p
'    );

'SUB SAM_CREDENTIAL_UPDATE_REGISTER_ROUTINE ( _
'   BYVAL p AS DWORD _                                   ' __in PVOID p
' )                                                      ' VOID

$SAM_CREDENTIAL_UPDATE_FREE_ROUTINE = "CredentialUpdateFree"

' // Size = 12 bytes
TYPE SAM_REGISTER_MAPPING_ELEMENT DWORD
   Original    AS ASCIIZ PTR   ' __in PSTR Original
   Mapped      AS ASCIIZ PTR   ' __in PSTR Mapped
   Continuable AS BYTE         ' __in BOOLEAN Continuable;  // only honored for some operations
END TYPE

' // Size = 8 bytes
TYPE SAM_REGISTER_MAPPING_LIST DWORD
   Count    AS DWORD                              ' ULONG
   Elements AS SAM_REGISTER_MAPPING_ELEMENT PTR   ' __ecount(Count) PSAM_REGISTER_MAPPING_ELEMENT
END TYPE

' // Size = 8 bytes
TYPE SAM_REGISTER_MAPPING_TABLE DWORD
   Count AS DWORD                           ' ULONG
   Lists AS SAM_REGISTER_MAPPING_LIST PTR   ' __ecount(Count) PSAM_REGISTER_MAPPING_LIST
END TYPE

'typedef NTSTATUS (*PSAM_CREDENTIAL_UPDATE_REGISTER_MAPPED_ENTRYPOINTS_ROUTINE) (
'    __out SAM_REGISTER_MAPPING_TABLE *Table
'    );

'FUNCTION SAM_CREDENTIAL_UPDATE_REGISTER_MAPPED_ENTRYPOINTS_ROUTINE ( _
'   BYREF Table AS SAM_REGISTER_MAPPING_TABLE _          ' __out SAM_REGISTER_MAPPING_TABLE *Table
' ) AS LONG                                              ' NTSTATUS

$SAM_CREDENTIAL_UPDATE_REGISTER_MAPPED_ENTRYPOINTS_ROUTINE = "RegisterMappedEntrypoints"

#ENDIF   ' // _SAM_CREDENTIAL_UPDATE_DEFINED


'#ifdef SECURITY_KERNEL
'//
'// Can't use the windows.h def'ns in kernel mode.
'//
'typedef PVOID                   SEC_THREAD_START;
'typedef PVOID                   SEC_ATTRS;
'#else
'typedef LPTHREAD_START_ROUTINE  SEC_THREAD_START;
'typedef LPSECURITY_ATTRIBUTES   SEC_ATTRS;
'#endif


'#define SecEqualLuid(L1, L2)    \
'            ( ( ((PLUID)L1)->LowPart == ((PLUID)L2)->LowPart ) && \
'              ( ((PLUID)L1)->HighPart == ((PLUID)L2)->HighPart ) ) \
MACRO SecEqualLuid(L1, L2) = ((L1.LowPart = L2.LowPart) AND (L1.HighPart = L2.HighPart))

'#define SecIsZeroLuid( L1 ) \
'            ( ( L1->LowPart | L1->HighPart ) == 0 )
MACRO SecIsZeroLuid(L1) = ((L1.LowPart OR L1.HighPart) = 0)

#IF NOT %DEF(%LUID_DEFINED)
%LUID_DEFINED = 1
' // Size = 8 bytes
TYPE LUID_STRUCT DWORD
  LowPart  AS DWORD
  HighPart AS LONG
END TYPE
UNION LUID
   LUID_STRUCT
   QuadPart AS QUAD
END UNION
#ENDIF

'//
'// The following structures are used by the helper functions
'//

' // Size = 28 bytes
TYPE SECPKG_CLIENT_INFO DWORD FILL
   LogonId            AS QUAD    ' LUID // Effective Logon Id
   ProcessID          AS DWORD   ' ULONG // Process Id of caller
   ThreadID           AS DWORD   ' ULONG // Thread Id of caller
   HasTcbPrivilege    AS BYTE    ' BOOLEAN // Client has TCB
   Impersonating      AS BYTE    ' BOOLEAN // Client is impersonating
   Restricted         AS BYTE    ' BOOLEAN // Client is restricted
   ' // NT 5.1
   ClientFlags        AS BYTE    ' UCHAR // Extra flags about the client
   ImpersonationLevel AS LONG    ' SECURITY_IMPERSONATION_LEVEL // Impersonation level of client
   ' // NT 6
   ClientToken        AS DWORD   ' HANDLE
END TYPE

%SECPKG_CLIENT_PROCESS_TERMINATED = &H01???   ' // The client process has terminated
%SECPKG_CLIENT_THREAD_TERMINATED  = &H02???   ' // The client thread has terminated

' // Size = 20 bytes
TYPE SECPKG_CALL_INFO DWORD
   ProcessId  AS DWORD   ' ULONG
   ThreadId   AS DWORD   ' ULONG
   Attributes AS DWORD   ' ULONG
   CallCount  AS DWORD   ' ULONG
   MechOid    AS DWORD   ' PVOID // mechanism objection identifer
END TYPE

%SECPKG_CALL_KERNEL_MODE     = &H00000001???   ' // Call originated in kernel mode
%SECPKG_CALL_ANSI            = &H00000002???   ' // Call came from ANSI stub
%SECPKG_CALL_URGENT          = &H00000004???   ' // Call designated urgent
%SECPKG_CALL_RECURSIVE       = &H00000008???   ' // Call is recursing
%SECPKG_CALL_IN_PROC         = &H00000010???   ' // Call originated in process
%SECPKG_CALL_CLEANUP         = &H00000020???   ' // Call is cleanup from a client
%SECPKG_CALL_WOWCLIENT       = &H00000040???   ' // Call is from a WOW client process
%SECPKG_CALL_THREAD_TERM     = &H00000080???   ' // Call is from a thread that has term'd
%SECPKG_CALL_PROCESS_TERM    = &H00000100???   ' // Call is from a process that has term'd
%SECPKG_CALL_IS_TCB          = &H00000200???   ' // Call is from TCB
%SECPKG_CALL_NETWORK_ONLY    = &H00000400???   ' // Call asks for network logon only, no cached logons
%SECPKG_CALL_WINLOGON        = &H00000800???   ' // the caller of LsaLogonuser() is Winlogon
%SECPKG_CALL_ASYNC_UPDATE    = &H00001000???   ' // asynchronous update for unlock
%SECPKG_CALL_SYSTEM_PROC     = &H00002000???   ' // Call originated from the System process
%SECPKG_CALL_NEGO            = &H00004000???   ' // Called by SPNEGO
%SECPKG_CALL_NEGO_EXTENDER   = &H00008000???   ' // Called by NEGO extender
%SECPKG_CALL_BUFFER_MARSHAL  = &H00010000???   ' // Buffer passed is marshaled (by RPC)

' // Size = 16 bytes
TYPE SECPKG_SUPPLEMENTAL_CRED DWORD
   PackageName    AS UNICODE_STRING
   CredentialSize AS DWORD      ' ULONG
   Credentials    AS BYTE PTR   ' PUCHAR
END TYPE

' // Size = 8 bytes
TYPE SECPKG_BYTE_VECTOR DWORD
   ByteArrayOffset AS DWORD   ' ULONG // each element is a byte
   ByteArrayLength AS WORD    ' USHORT
END TYPE

' // Size = 8 bytes
TYPE SECPKG_SHORT_VECTOR DWORD
   ShortArrayOffset AS DWORD   ' ULONG // each element is a short
   ShortArrayCount  AS WORD    ' USHORT // number of characters
END TYPE

'//
'// the supplied credential structure
'//

' // Size = 32 bytes
TYPE SECPKG_SUPPLIED_CREDENTIAL DWORD FILL
   cbHeaderLength    AS WORD                  ' USHORT // the length of the header
   cbStructureLength AS WORD                  ' USHORT //  pay load length including the header
   UserName          AS SECPKG_SHORT_VECTOR   ' // unicode only
   DomainName        AS SECPKG_SHORT_VECTOR   ' // unicode only
   PackedCredentials AS SECPKG_BYTE_VECTOR    ' // SEC_WINNT_AUTH_PACKED_CREDENTIALS
   CredFlags         AS DWORD                 ' ULONG // authidentity flags
END TYPE

'//
'// the credential structure used by Nego2-SPMI
'//

%SECPKG_CREDENTIAL_VERSION = 201

'//
'//  credentials flags
'//

%SECPKG_CREDENTIAL_FLAGS_CALLER_HAS_TCB = &H1???

' // Size = 80 bytes
TYPE SECPKG_CREDENTIAL   ' Must be 8 byte aligned
   Version                AS QUAD                 ' ULONG64 // contains SECPKG_CREDENTIAL_VERSION
   cbHeaderLength         AS WORD                 ' USHORT // the length of the header
   alignment__            AS WORD                 ' // To keep 8 byte alignment
   cbStructureLength      AS DWORD                ' ULONG // pay load length including the header,
   ' // all the content of this structure is within a contiguous buffer
   ClientProcess          AS DWORD                ' ULONG // the caller's identity
   ClientThread           AS DWORD                ' ULONG // the caller's identity
   LogonId                AS QUAD                 ' // the caller's identity
   ClientToken            AS DWORD                ' HANDLE // the caller's identity
   SessionId              AS DWORD                ' ULONG // the caller's identity
   ModifiedId             AS QUAD                 ' // the caller's identity
   fCredentials           AS DWORD                ' ULONG // inbound or outbound?
   Flags                  AS DWORD                ' ULONG // contains SECPKG_CREDENTIAL_FLAGS
   PrincipalName          AS SECPKG_BYTE_VECTOR   ' // not used
   PackageList            AS SECPKG_BYTE_VECTOR   ' // list of packages, relevant only to SPNEGO
   MarshaledSuppliedCreds AS SECPKG_BYTE_VECTOR   ' // contains a SECPKG_SUPPLIED_CREDENTIAL structure
END TYPE

'typedef ULONG_PTR LSA_SEC_HANDLE;
'typedef LSA_SEC_HANDLE * PLSA_SEC_HANDLE;

' // Size = 20 bytes
TYPE SECPKG_SUPPLEMENTAL_CRED_ARRAY DWORD
   CredentialCount AS DWORD   ' ULONG
   Credentials(0)  AS SECPKG_SUPPLEMENTAL_CRED
END TYPE

'//
'// This flag is used for to indicate which buffers in the LSA are located
'// in the client's address space
'//

%SECBUFFER_UNMAPPED      = &H40000000???

'//
'// This flag is used to indicate that the buffer was mapped into the LSA
'// from kernel mode.
'//

%SECBUFFER_KERNEL_MAP    = &H20000000???

'typedef NTSTATUS
'(NTAPI LSA_CALLBACK_FUNCTION)(
'    ULONG_PTR    Argument1,
'    ULONG_PTR    Argument2,
'    PSecBuffer  InputBuffer,
'    PSecBuffer  OutputBuffer
'    );

'typedef LSA_CALLBACK_FUNCTION * PLSA_CALLBACK_FUNCTION;

'FUNCTION LSA_CALLBACK_FUNCTION ( _
'   BYVAL Argument1 AS DWORD _                           ' ULONG_PTR  Argument1
' , BYVAL Argument2 AS DWORD _                           ' ULONG_PTR  Argument2
' , BYREF InputBuffer AS SecBuffer _                     ' PSecBuffer InputBuffer
' , BYREF OutputBuffer AS SecBuffer _                    ' PSecBuffer OutputBuffer
' ) AS LONG                                              ' NTSTATUS


%PRIMARY_CRED_CLEAR_PASSWORD              = &H1
%PRIMARY_CRED_OWF_PASSWORD                = &H2
%PRIMARY_CRED_UPDATE                      = &H4    ' // this is a change of existing creds
%PRIMARY_CRED_CACHED_LOGON                = &H8
%PRIMARY_CRED_LOGON_NO_TCB                = &H10
%PRIMARY_CRED_LOGON_LUA                   = &H20
%PRIMARY_CRED_INTERACTIVE_SMARTCARD_LOGON = &H40
%PRIMARY_CRED_REFRESH_NEEDED              = &H80   ' // unlock refresh needed


%PRIMARY_CRED_LOGON_PACKAGE_SHIFT         = 24
%PRIMARY_CRED_PACKAGE_MASK                = &Hff000000???

'//
'// For cached logons, the RPC id of the package doing the logon is identified
'// by shifting the flags to the right by the PRIMARY_CRED_LOGON_PACKAGE_SHIFT.
'//

' // Size = 104 bytes
TYPE SECPKG_PRIMARY_CRED DWORD
   LogonId       AS QUAD
   DownlevelName AS UNICODE_STRING   ' // Sam Account Name
   DomainName    AS UNICODE_STRING   ' // Netbios domain name where account is located
   Password      AS UNICODE_STRING
   OldPassword   AS UNICODE_STRING
   UserSid       AS SID PTR          ' PSID
   Flags         AS DWORD            ' ULONG
   DnsDomainName AS UNICODE_STRING   ' // DNS domain name where account is located (if known)
   Upn           AS UNICODE_STRING   ' // UPN of account (if known)
   LogonServer   AS UNICODE_STRING
   Spare1        AS UNICODE_STRING
   Spare2        AS UNICODE_STRING
   Spare3        AS UNICODE_STRING
   Spare4        AS UNICODE_STRING
END TYPE

'//
'// Maximum size of stored credentials.
'//

%MAX_CRED_SIZE = 1024

'// Values for MachineState

%SECPKG_STATE_ENCRYPTION_PERMITTED        = &H01???
%SECPKG_STATE_STRONG_ENCRYPTION_PERMITTED = &H02???
%SECPKG_STATE_DOMAIN_CONTROLLER           = &H04???
%SECPKG_STATE_WORKSTATION                 = &H08???
%SECPKG_STATE_STANDALONE                  = &H10???

' // Size = 48 bytes
TYPE SECPKG_PARAMETERS DWORD
   Version       AS DWORD            ' ULONG
   MachineState  AS DWORD            ' ULONG
   SetupMode     AS DWORD            ' ULONG
   DomainSid     AS SID PTR          ' PSID
   DomainName    AS UNICODE_STRING
   DnsDomainName AS UNICODE_STRING
   DomainGuid    AS GUID
END TYPE


'//
'// Extended Package information structures
'//

' enum SECPKG_EXTENDED_INFORMATION_CLASS
%SecpkgGssInfo         = 1
%SecpkgContextThunks   = 2
%SecpkgMutualAuthLevel = 3
%SecpkgWowClientDll    = 4
%SecpkgExtraOids       = 5
%SecpkgMaxInfo         = 6
%SecpkgNego2Info       = 7

' // Size = 8 bytes
TYPE SECPKG_GSS_INFO DWORD
   EncodedIdLength AS DWORD   ' ULONG
   EncodedId(3)    AS BYTE    ' UCHAR[4]
END TYPE

' // Size = 8 bytes
TYPE SECPKG_CONTEXT_THUNKS DWORD
   InfoLevelCount AS DWORD   ' ULONG
   Levels(0)      AS DWORD   ' ULONG
END TYPE

' // Size = 4 bytes
TYPE SECPKG_MUTUAL_AUTH_LEVEL DWORD
   MutualAuthLevel AS DWORD   ' ULONG
END TYPE

' // Size = 8 bytes
TYPE SECPKG_WOW_CLIENT_DLL DWORD
   WowClientDllPath AS SECURITY_STRING
END TYPE

%SECPKG_MAX_OID_LENGTH = 32

' // Size = 40 bytes
TYPE SECPKG_SERIALIZED_OID DWORD
   OidLength     AS DWORD                             ' ULONG
   OidAttributes AS DWORD                             ' ULONG
   OidValue      AS ASCIIZ * %SECPKG_MAX_OID_LENGTH   ' UCHAR
END TYPE

' // Size = 44 bytes
TYPE SECPKG_EXTRA_OIDS DWORD
   OidCount AS DWORD   ' ULONG
   Oids(0)  AS SECPKG_SERIALIZED_OID
END TYPE

'// used by Nego2
' // Size = 20 bytes
TYPE SECPKG_NEGO2_INFO DWORD
   AuthScheme(15) AS BYTE   ' // auth id[16]
   PackageFlags   AS DWORD   ' ULONG
END TYPE

' // Size = 44 bytes
UNION SECPKG_EXTENDED_INFORMATION_UNION
   GssInfo         AS SECPKG_GSS_INFO
   ContextThunks   AS SECPKG_CONTEXT_THUNKS
   MutualAuthLevel AS SECPKG_MUTUAL_AUTH_LEVEL
   WowClientDll    AS SECPKG_WOW_CLIENT_DLL
   ExtraOids       AS SECPKG_EXTRA_OIDS
   Nego2Info       AS SECPKG_NEGO2_INFO
END UNION

' // Size = 48 bytes
TYPE SECPKG_EXTENDED_INFORMATION DWORD
   Class AS LONG   ' SECPKG_EXTENDED_INFORMATION_CLASS
   Info  AS SECPKG_EXTENDED_INFORMATION_UNION
END TYPE

' // Size = 8 bytes
TYPE SECPKG_TARGETINFO DWORD
   DomainSid    AS SID PTR        ' PSID
   ComputerName AS WSTRINGZ PTR   ' PCWSTR
END TYPE

%SECPKG_ATTR_SASL_CONTEXT = &H00010000???

' // Size = 4 bytes
TYPE SecPkgContext_SaslContext DWORD
   SaslContext AS DWORD   ' PVOID
END TYPE

'//
'// Setting this value as the first context thunk value will cause all
'// calls to go to the LSA:
'//

%SECPKG_ATTR_THUNK_ALL = &H00010000???


#IF NOT %DEF(%SECURITY_USER_DATA_DEFINED)
    %SECURITY_USER_DATA_DEFINED = 1

' // Size = 28 bytes
TYPE SECURITY_USER_DATA DWORD
   UserName        AS SECURITY_STRING   ' // User name
   LogonDomainName AS SECURITY_STRING   ' // Domain the user logged on to
   LogonServer     AS SECURITY_STRING   ' // Server that logged the user on
   pSid            AS SID PTR           ' PSID // SID of user
END TYPE

'typedef SECURITY_USER_DATA SecurityUserData, * PSecurityUserData;


%UNDERSTANDS_LONG_NAMES = 1
%NO_LONG_NAMES          = 2

#ENDIF   ' // SECURITY_USER_DATA_DEFINED

'//////////////////////////////////////////////////////////////////////////
'//
'// The following prototypes are to functions that are provided by the SPMgr
'// to security packages.
'//
'//////////////////////////////////////////////////////////////////////////

'typedef NTSTATUS
'(NTAPI LSA_IMPERSONATE_CLIENT) (
'    VOID
'    );

'FUNCTION LSA_IMPERSONATE_CLIENT () AS LONG

'typedef NTSTATUS
'(NTAPI LSA_UNLOAD_PACKAGE)(
'    VOID
'    );

'FUNCTION LSA_UNLOAD_PACKAGE () AS LONG

'typedef NTSTATUS
'(NTAPI LSA_DUPLICATE_HANDLE)(
'    IN HANDLE SourceHandle,
'    OUT PHANDLE DestionationHandle);

'FUNCTION LSA_DUPLICATE_HANDLE ( _
'   BYVAL SourceHandle AS DWORD _                        ' __in HANDLE SourceHandle
' , BYREF DestionationHandle AS DWORD _                  ' __out PHANDLE DestionationHandle
' ) AS LONG                                              ' NTSTATUS

'typedef NTSTATUS
'(NTAPI LSA_SAVE_SUPPLEMENTAL_CREDENTIALS)(
'    IN PLUID LogonId,
'    IN ULONG SupplementalCredSize,
'    IN PVOID SupplementalCreds,
'    IN BOOLEAN Synchronous
'    );

'FUNCTION LSA_SAVE_SUPPLEMENTAL_CREDENTIALS ( _
'   BYREF LogonId AS QUAD _                              ' __in PLUID LogonId
' , BYVAL SupplementalCredSize AS DWORD _                ' __in ULONG SupplementalCredSize
' , BYVAL SupplementalCreds AS DWORD _                   ' __in PVOID SupplementalCreds
' , BYVAL Synchronous AS BYTE _                          ' __in BOOLEAN Synchronous
' ) AS LONG                                              ' NTSTATUS

'typedef HANDLE
'(NTAPI LSA_CREATE_THREAD)(
'    IN SEC_ATTRS SecurityAttributes,
'    IN ULONG StackSize,
'    IN SEC_THREAD_START StartFunction,
'    IN PVOID ThreadParameter,
'    IN ULONG CreationFlags,
'    OUT PULONG ThreadId
'    );

'FUNCTION LSA_CREATE_THREAD ( _
'   BYVAL SecurityAttributes AS DWORD _                  ' __in SEC_ATTRS SecurityAttributes
' , BYVAL StackSize AS DWORD _                           ' __in ULONG StackSize
' , BYVAL StartFunction AS DWORD _                       ' __in SEC_THREAD_START StartFunction
' , BYVAL ThreadParameter AS DWORD _                     ' __in PVOID ThreadParameter
' , BYVAL CreationFlags AS DWORD _                       ' __in ULONG CreationFlags
' , BYREF ThreadId AS DWORD _                            ' __out PULONG ThreadId
' ) AS DWORD                                             ' HANDLE

'typedef NTSTATUS
'(NTAPI LSA_GET_CLIENT_INFO)(
'    OUT PSECPKG_CLIENT_INFO ClientInfo
'    );

'FUNCTION LSA_GET_CLIENT_INFO ( _
'   BYREF ClientInfo AS SECPKG_CLIENT_INFO _             ' __out PSECPKG_CLIENT_INFO ClientInfo
' ) AS LONG                                              ' NTSTATUS

'typedef HANDLE
'(NTAPI LSA_REGISTER_NOTIFICATION)(
'    IN SEC_THREAD_START StartFunction,
'    IN PVOID Parameter,
'    IN ULONG NotificationType,
'    IN ULONG NotificationClass,
'    IN ULONG NotificationFlags,
'    IN ULONG IntervalMinutes,
'    IN OPTIONAL HANDLE WaitEvent
'    );

'FUNCTION LSA_REGISTER_NOTIFICATION ( _
'   BYVAL StartFunction AS DWORD _                       ' __in SEC_THREAD_START StartFunction
' , BYVAL Parameter AS DWORD _                           ' __in PVOID Parameter
' , BYVAL NotificationType AS DWORD _                    ' __in ULONG NotificationType
' , BYVAL NotificationClass AS DWORD _                   ' __in ULONG NotificationClass
' , BYVAL NotificationFlags AS DWORD _                   ' __in ULONG NotificationFlags
' , BYVAL IntervalMinutes AS DWORD _                     ' __in ULONG IntervalMinutes
' , BYVAL WaitEvent AS DWORD _                           ' __in_opt HANDLE WaitEvent
' ) AS DWORD                                             ' HANDLE

'typedef NTSTATUS
'(NTAPI LSA_CANCEL_NOTIFICATION)(
'    IN HANDLE NotifyHandle
'    );

'FUNCTION LSA_CANCEL_NOTIFICATION ( _
'   BYVAL NotifyHandle AS DWORD _                        ' __in HANDLE NotifyHandle
' ) AS LONG                                              ' NTSTATUS

'typedef NTSTATUS
'(NTAPI LSA_MAP_BUFFER)(
'    IN PSecBuffer InputBuffer,
'    OUT PSecBuffer OutputBuffer
'    );

'FUNCTION LSA_MAP_BUFFER ( _
'   BYREF InputBuffer AS SecBuffer _                     ' __in PSecBuffer InputBuffer
' , BYREF OutputBuffer AS SecBuffer _                    ' __out PSecBuffer OutputBuffer
' ) AS LONG                                              ' NTSTATUS

'typedef NTSTATUS
'(NTAPI LSA_CREATE_TOKEN) (
'    IN PLUID LogonId,
'    IN PTOKEN_SOURCE TokenSource,
'    IN SECURITY_LOGON_TYPE LogonType,
'    IN SECURITY_IMPERSONATION_LEVEL ImpersonationLevel,
'    IN LSA_TOKEN_INFORMATION_TYPE TokenInformationType,
'    IN PVOID TokenInformation,
'    IN PTOKEN_GROUPS TokenGroups,
'    IN PUNICODE_STRING AccountName,
'    IN PUNICODE_STRING AuthorityName,
'    IN PUNICODE_STRING Workstation,
'    IN PUNICODE_STRING ProfilePath,
'    OUT PHANDLE Token,
'    OUT PNTSTATUS SubStatus
'    );

'FUNCTION LSA_CREATE_TOKEN ( _
'   BYREF LogonId AS QUAD _                              ' __in PLUID LogonId
' , BYREF TokenSource AS TOKEN_SOURCE _                  ' __in PTOKEN_SOURCE TokenSource
' , BYVAL LogonType AS LONG _                            ' __in SECURITY_LOGON_TYPE LogonType
' , BYVAL ImpersonationLevel AS LONG _                   ' __in SECURITY_IMPERSONATION_LEVEL ImpersonationLevel
' , BYVAL TokenInformationType AS LONG _                 ' __in LSA_TOKEN_INFORMATION_TYPE TokenInformationType
' , BYVAL TokenInformation AS DWORD _                    ' __in PVOID TokenInformation
' , BYREF TokenGroups AS TOKEN_GROUPS _                  ' __in PTOKEN_GROUPS TokenGroups
' , BYREF AccountName AS UNICODE_STRING _                ' __in PUNICODE_STRING AccountName
' , BYREF AuthorityName AS UNICODE_STRING _              ' __in PUNICODE_STRING AuthorityName
' , BYREF Workstation AS UNICODE_STRING _                ' __in PUNICODE_STRING Workstation
' , BYREF ProfilePath AS UNICODE_STRING _                ' __in PUNICODE_STRING ProfilePath
' , BYREF Token AS DWORD _                               ' __out PHANDLE Token
' , BYREF SubStatus AS LONG _                            '  __out PNTSTATUS SubStatus
' ) AS LONG                                              ' NTSTATUS

' enum SECPKG_SESSIONINFO_TYPE
%SecSessionPrimaryCred = 0   ' // SessionInformation is SECPKG_PRIMARY_CRED

'typedef NTSTATUS
'(NTAPI LSA_CREATE_TOKEN_EX) (
'    IN PLUID LogonId,
'    IN PTOKEN_SOURCE TokenSource,
'    IN SECURITY_LOGON_TYPE LogonType,
'    IN SECURITY_IMPERSONATION_LEVEL ImpersonationLevel,
'    IN LSA_TOKEN_INFORMATION_TYPE TokenInformationType,
'    IN PVOID TokenInformation,
'    IN PTOKEN_GROUPS TokenGroups,
'    IN PUNICODE_STRING Workstation,
'    IN PUNICODE_STRING ProfilePath,
'    IN PVOID SessionInformation,
'    IN SECPKG_SESSIONINFO_TYPE SessionInformationType,
'    OUT PHANDLE Token,
'    OUT PNTSTATUS SubStatus
'    );

'FUNCTION LSA_CREATE_TOKEN_EX ( _
'   BYREF LogonId AS QUAD _                              ' __in PLUID LogonId
' , BYREF TokenSource AS TOKEN_SOURCE _                  ' __in PTOKEN_SOURCE TokenSource
' , BYVAL LogonType AS LONG _                            ' __in SECURITY_LOGON_TYPE LogonType
' , BYVAL ImpersonationLevel AS LONG _                   ' __in SECURITY_IMPERSONATION_LEVEL ImpersonationLevel
' , BYVAL TokenInformationType AS LONG _                 ' __in LSA_TOKEN_INFORMATION_TYPE TokenInformationType
' , BYVAL TokenInformation AS DWORD _                    ' __in PVOID TokenInformation
' , BYREF TokenGroups AS TOKEN_GROUPS _                  ' __in PTOKEN_GROUPS TokenGroups
' , BYREF Workstation AS UNICODE_STRING _                ' __in PUNICODE_STRING Workstation
' , BYREF ProfilePath AS UNICODE_STRING _                ' __in PUNICODE_STRING ProfilePath
' , BYVAL SessionInformation AS DWORD _                  ' __in PVOID SessionInformation
' , BYVAL SessionInformationType AS LONG _               ' __in SECPKG_SESSIONINFO_TYPE SessionInformationType
' , BYREF Token AS DWORD _                               ' __out PHANDLE Token
' , BYREF SubStatus AS LONG _                            '  __out PNTSTATUS SubStatus
' ) AS LONG                                              ' NTSTATUS

'typedef VOID
'(NTAPI LSA_AUDIT_LOGON) (
'    IN NTSTATUS Status,
'    IN NTSTATUS SubStatus,
'    IN PUNICODE_STRING AccountName,
'    IN PUNICODE_STRING AuthenticatingAuthority,
'    IN PUNICODE_STRING WorkstationName,
'    IN OPTIONAL PSID UserSid,
'    IN SECURITY_LOGON_TYPE LogonType,
'    IN PTOKEN_SOURCE TokenSource,
'    IN PLUID LogonId
'    );

'SUB LSA_AUDIT_LOGON ( _
'   BYVAL Status AS LONG _                               ' __in NTSTATUS Status
' , BYVAL SubStatus AS LONG _                            ' __in NTSTATUS SubStatus
' , BYREF AccountName AS UNICODE_STRING _                ' __in PUNICODE_STRING AccountName
' , BYREF AuthenticatingAuthority AS UNICODE_STRING _    ' __in PUNICODE_STRING AuthenticatingAuthority
' , BYREF WorkstationName AS UNICODE_STRING _            ' __in PUNICODE_STRING WorkstationName
' , BYVAL UserSid AS SID PTR _                           ' __in_opt PSID UserSid
' , BYVAL LogonType AS LONG _                            ' __in SECURITY_LOGON_TYPE LogonType
' , BYREF TokenSource AS TOKEN_SOURCE _                  ' __in PTOKEN_SOURCE TokenSource
' , BYREF LogonId AS QUAD _                              ' __in PLUID LogonId
' )                                                      ' VOID

'typedef NTSTATUS
'(NTAPI LSA_CALL_PACKAGE) (
'    IN PUNICODE_STRING AuthenticationPackage,
'    IN PVOID ProtocolSubmitBuffer,
'    IN ULONG SubmitBufferLength,
'    OUT PVOID *ProtocolReturnBuffer,
'    OUT PULONG ReturnBufferLength,
'    OUT PNTSTATUS ProtocolStatus
'    );

'FUNCTION LSA_CALL_PACKAGE ( _
'   BYREF AuthenticationPackage AS UNICODE_STRING _      ' __in PUNICODE_STRING AuthenticationPackage
' , BYVAL ProtocolSubmitBuffer AS DWORD _                ' __in PVOID ProtocolSubmitBuffer
' , BYVAL SubmitBufferLength AS DWORD _                  ' __in ULONG SubmitBufferLength
' , BYREF ProtocolReturnBuffer AS DWORD _                ' __out PVOID *ProtocolReturnBuffer
' , BYREF ReturnBufferLength AS DWORD _                  ' __out PULONG ReturnBufferLength
' , BYREF ProtocolStatus AS LONG _                       ' __out PNTSTATUS ProtocolStatus
' ) AS LONG                                              ' NTSTATUS

'typedef NTSTATUS
'(NTAPI LSA_CALL_PACKAGEEX) (
'    IN PUNICODE_STRING AuthenticationPackage,
'    IN PVOID ClientBufferBase,
'    IN PVOID ProtocolSubmitBuffer,
'    IN ULONG SubmitBufferLength,
'    OUT PVOID *ProtocolReturnBuffer,
'    OUT PULONG ReturnBufferLength,
'    OUT PNTSTATUS ProtocolStatus
'    );

'FUNCTION LSA_CALL_PACKAGEEX ( _
'   BYREF AuthenticationPackage AS UNICODE_STRING _      ' __in PUNICODE_STRING AuthenticationPackage
' , BYVAL ClientBufferBase AS DWORD _                    ' __in PVOID ClientBufferBase
' , BYVAL ProtocolSubmitBuffer AS DWORD _                ' __in PVOID ProtocolSubmitBuffer
' , BYVAL SubmitBufferLength AS DWORD _                  ' __in ULONG SubmitBufferLength
' , BYREF ProtocolReturnBuffer AS DWORD _                ' __out PVOID *ProtocolReturnBuffer
' , BYREF ReturnBufferLength AS DWORD _                  ' __out PULONG ReturnBufferLength
' , BYREF ProtocolStatus AS LONG _                       ' __out PNTSTATUS ProtocolStatus
' ) AS LONG                                              ' NTSTATUS

'typedef NTSTATUS
'(NTAPI LSA_CALL_PACKAGE_PASSTHROUGH) (
'    IN PUNICODE_STRING AuthenticationPackage,
'    IN PVOID ClientBufferBase,
'    IN PVOID ProtocolSubmitBuffer,
'    IN ULONG SubmitBufferLength,
'    OUT PVOID *ProtocolReturnBuffer,
'    OUT PULONG ReturnBufferLength,
'    OUT PNTSTATUS ProtocolStatus
'    );

'FUNCTION LSA_CALL_PACKAGE_PASSTHROUGH ( _
'   BYREF AuthenticationPackage AS UNICODE_STRING _      ' __in PUNICODE_STRING AuthenticationPackage
' , BYVAL ClientBufferBase AS DWORD _                    ' __in PVOID ClientBufferBase
' , BYVAL ProtocolSubmitBuffer AS DWORD _                ' __in PVOID ProtocolSubmitBuffer
' , BYVAL SubmitBufferLength AS DWORD _                  ' __in ULONG SubmitBufferLength
' , BYREF ProtocolReturnBuffer AS DWORD _                ' __out PVOID *ProtocolReturnBuffer
' , BYREF ReturnBufferLength AS DWORD _                  ' __out PULONG ReturnBufferLength
' , BYREF ProtocolStatus AS LONG _                       ' __out PNTSTATUS ProtocolStatus
' ) AS LONG                                              ' NTSTATUS

'typedef BOOLEAN
'(NTAPI LSA_GET_CALL_INFO) (
'    OUT PSECPKG_CALL_INFO   Info
'    );

'FUNCTION LSA_GET_CALL_INFO ( _
'   BYREF Info AS SECPKG_CALL_INFO _                     ' __out PSECPKG_CALL_INFO Info
' ) AS BYTE                                              ' BOOLEAN

'typedef PVOID
'(NTAPI LSA_CREATE_SHARED_MEMORY)(
'    ULONG MaxSize,
'    ULONG InitialSize
'    );

'FUNCTION LSA_CREATE_SHARED_MEMORY ( _
'   BYVAL MaxSize AS DWORD _                             ' __in ULONG MaxSize
' , BYVAL InitialSize AS DWORD _                         ' __in ULONG InitialSize
' ) AS DWORD                                             ' PVOID

'typedef PVOID
'(NTAPI LSA_ALLOCATE_SHARED_MEMORY)(
'    PVOID SharedMem,
'    ULONG Size
'    );

'FUNCTION LSA_ALLOCATE_SHARED_MEMORY ( _
'   BYVAL SharedMem AS DWORD _                           ' __in PVOID SharedMem
' , BYVAL uSize AS DWORD _                               ' __in ULONG Size
' ) AS DWORD                                             ' PVOID

'typedef VOID
'(NTAPI LSA_FREE_SHARED_MEMORY)(
'    PVOID SharedMem,
'    PVOID Memory
'    );

'SUB LSA_ALLOCATE_SHARED_MEMORY ( _
'   BYVAL SharedMem AS DWORD _                           ' __in PVOID SharedMem
' , BYVAL Memory AS DWORD _                              ' __in PVOID Memory
' )                                                      ' VOID

'typedef BOOLEAN
'(NTAPI LSA_DELETE_SHARED_MEMORY)(
'    PVOID SharedMem
'    );

'FUNCTION LSA_DELETE_SHARED_MEMORY ( _
'   BYVAL SharedMem AS DWORD _                           ' __in PVOID SharedMem
' ) AS BYTE                                              ' BOOLEAN

'//
'// Account Access
'//

' enum SECPKG_NAME_TYPE
%SecNameSamCompatible = 0
%SecNameAlternateId   = 1
%SecNameFlat          = 2
%SecNameDN            = 3
%SecNameSPN           = 4

'typedef NTSTATUS
'(NTAPI LSA_OPEN_SAM_USER)(
'    PSECURITY_STRING Name,
'    SECPKG_NAME_TYPE NameType,
'    PSECURITY_STRING Prefix,
'    BOOLEAN AllowGuest,
'    ULONG Reserved,
'    PVOID * UserHandle
'    );

'FUNCTION LSA_OPEN_SAM_USER ( _
'   BYREF Name AS SECURITY_STRING _                      ' PSECURITY_STRING Name
' , BYVAL NameType AS LONG _                             ' SECPKG_NAME_TYPE NameType
' , BYREF Prefix AS SECURITY_STRING _                    ' PSECURITY_STRING Prefix
' , BYVAL AllowGuest AS BYTE _                           ' BOOLEAN AllowGuest
' , BYVAL Reserved AS DWORD _                            ' ULONG Reserved
' , BYVAL UserHandle AS DWORD _                          ' PVOID * UserHandle
' ) AS LONG                                              ' NTSTATUS

'typedef NTSTATUS
'(NTAPI LSA_GET_USER_CREDENTIALS)(
'    PVOID UserHandle,
'    PVOID * PrimaryCreds,
'    PULONG PrimaryCredsSize,
'    PVOID * SupplementalCreds,
'    PULONG SupplementalCredsSize
'    );

'FUNCTION LSA_GET_USER_CREDENTIALS ( _
'   BYVAL UserHandle AS DWORD _                          ' PVOID UserHandle
' , BYVAL PrimaryCreds AS DWORD _                        ' PVOID * PrimaryCreds
' , BYREF PrimaryCredsSize AS DWORD _                    ' PULONG PrimaryCredsSize
' , BYVAL SupplementalCreds AS DWORD _                   ' PVOID * SupplementalCreds
' , BYREF SupplementalCredsSize AS DWORD _               ' PULONG SupplementalCredsSize
' ) AS LONG                                              ' NTSTATUS

'typedef NTSTATUS
'(NTAPI LSA_GET_USER_AUTH_DATA)(
'    PVOID UserHandle,
'    PUCHAR * UserAuthData,
'    PULONG UserAuthDataSize
'    );

'FUNCTION LSA_GET_USER_AUTH_DATA ( _
'   BYVAL UserHandle AS DWORD _                          ' PVOID UserHandle
' , BYVAL UserAuthData AS BYTE PTR _                     ' PUCHAR * UserAuthData
' , BYREF UserAuthDataSize AS DWORD _                    ' PULONG UserAuthDataSize
' ) AS LONG                                              ' NTSTATUS

'typedef NTSTATUS
'(NTAPI LSA_CLOSE_SAM_USER)(
'    PVOID UserHandle
'    );

'FUNCTION LSA_CLOSE_SAM_USER ( _
'   BYVAL UserHandle AS DWORD _                          ' PVOID UserHandle
' ) AS LONG                                              ' NTSTATUS

'typedef NTSTATUS
'(NTAPI LSA_GET_AUTH_DATA_FOR_USER)(
'    PSECURITY_STRING Name,
'    SECPKG_NAME_TYPE NameType,
'    PSECURITY_STRING Prefix,
'    PUCHAR * UserAuthData,
'    PULONG UserAuthDataSize,
'    PUNICODE_STRING UserFlatName
'    );

'FUNCTION LSA_GET_AUTH_DATA_FOR_USER ( _
'   BYREF Name AS SECURITY_STRING _                      ' PSECURITY_STRING Name
' , BYVAL NameType AS LONG _                             ' SECPKG_NAME_TYPE NameType
' , BYREF Prefix AS SECURITY_STRING _                    ' PSECURITY_STRING Prefix
' , BYVAL UserAuthData AS BYTE PTR _                     ' PUCHAR * UserAuthData
' , BYREF UserAuthDataSize AS DWORD _                    ' PULONG UserAuthDataSize
' , BYREF UserFlatName AS UNICODE_STRING _               ' PUNICODE_STRING UserFlatName
' ) AS LONG                                              ' NTSTATUS

'typedef NTSTATUS
'(NTAPI LSA_CONVERT_AUTH_DATA_TO_TOKEN)(
'    IN PVOID UserAuthData,
'    IN ULONG UserAuthDataSize,
'    IN SECURITY_IMPERSONATION_LEVEL ImpersonationLevel,
'    IN PTOKEN_SOURCE TokenSource,
'    IN SECURITY_LOGON_TYPE LogonType,
'    IN PUNICODE_STRING AuthorityName,
'    OUT PHANDLE Token,
'    OUT PLUID LogonId,
'    OUT PUNICODE_STRING AccountName,
'    OUT PNTSTATUS SubStatus
'    );

'FUNCTION LSA_CONVERT_AUTH_DATA_TO_TOKEN ( _
'   BYVAL UserAuthData AS DWORD _                        ' __in PVOID UserAuthData
' , BYVAL UserAuthDataSize AS DWORD _                    ' __in ULONG UserAuthDataSize
' , BYVAL ImpersonationLevel AS LONG _                   ' __in SECURITY_IMPERSONATION_LEVEL ImpersonationLevel
' , BYREF TokenSource AS TOKEN_SOURCE _                  ' __in PTOKEN_SOURCE TokenSource
' , BYVAL LogonType AS LONG _                            ' __in SECURITY_LOGON_TYPE LogonType
' , BYREF AuthorityName AS UNICODE_STRING _              ' __in PUNICODE_STRING AuthorityName
' , BYREF Token AS DWORD _                               ' __out PHANDLE Token
' , BYREF LogonId AS QUAD _                              ' __out PLUID LogonId
' , BYREF AccountName AS UNICODE_STRING _                ' __out PUNICODE_STRING AccountName
' , BYREF SubStatus AS LONG _                            ' __out PNTSTATUS SubStatus
' ) AS LONG                                              ' NTSTATUS

'typedef NTSTATUS
'(NTAPI LSA_CRACK_SINGLE_NAME)(
'    IN ULONG FormatOffered,
'    IN BOOLEAN PerformAtGC,
'    IN PUNICODE_STRING NameInput,
'    IN PUNICODE_STRING Prefix OPTIONAL,
'    IN ULONG RequestedFormat,
'    OUT PUNICODE_STRING CrackedName,
'    OUT PUNICODE_STRING DnsDomainName,
'    OUT PULONG SubStatus
'    );

'FUNCTION LSA_CRACK_SINGLE_NAME ( _
'   BYVAL FormatOffered AS DWORD _                       ' __in ULONG FormatOffered
' , BYVAL PerformAtGC AS BYTE _                          ' __in BOOLEAN PerformAtGC
' , BYREF NameInput AS UNICODE_STRING _                  ' __in PUNICODE_STRING NameInput
' , BYREF Prefix AS UNICODE_STRING _                     ' __in PUNICODE_STRING Prefix OPTIONAL
' , BYVAL RequestedFormat AS DWORD _                     ' __in ULONG RequestedFormat
' , BYREF CrackedName AS UNICODE_STRING _                ' __out PUNICODE_STRING CrackedName
' , BYREF DnsDomainName AS UNICODE_STRING _              ' __out PUNICODE_STRING DnsDomainName
' , BYREF SubStatus AS DWORD _                           ' __out PULONG SubStatus
' ) AS LONG                                              ' NTSTATUS

'typedef NTSTATUS
'(NTAPI LSA_AUDIT_ACCOUNT_LOGON)(
'    IN ULONG AuditId,
'    IN BOOLEAN Success,
'    IN PUNICODE_STRING Source,
'    IN PUNICODE_STRING ClientName,
'    IN PUNICODE_STRING MappedName,
'    IN NTSTATUS Status
'    );

'FUNCTION LSA_AUDIT_ACCOUNT_LOGON ( _
'   BYVAL AuditId AS DWORD _                             ' __in ULONG AuditId
' , BYVAL Success AS BYTE _                              ' __in BOOLEAN Success
' , BYREF Source AS UNICODE_STRING _                     ' __in PUNICODE_STRING Source
' , BYREF ClientName AS UNICODE_STRING _                 ' __in PUNICODE_STRING ClientName
' , BYREF MappedName AS UNICODE_STRING _                 ' __in PUNICODE_STRING MappedName
' , BYVAL Status AS LONG _                               ' __in NTSTATUS Status
' ) AS LONG                                              ' NTSTATUS

'typedef NTSTATUS
'(NTAPI LSA_CLIENT_CALLBACK)(
'    __in  PCHAR      Callback,
'    __in  ULONG_PTR  Argument1,
'    __in  ULONG_PTR  Argument2,
'    __in  PSecBuffer Input,
'    __out PSecBuffer Output
'    );

'FUNCTION LSA_CLIENT_CALLBACK ( _
'   BYVAL Callback AS BYTE PTR _                         ' __in  PCHAR      Callback
' , BYVAL Argument1 AS DWORD _                           ' __in  ULONG_PTR  Argument1
' , BYVAL Argument2 AS DWORD _                           ' __in  ULONG_PTR  Argument2
' , BYREF Input AS SecBuffer _                           ' __in  PSecBuffer Input
' , BYREF Output AS SecBuffer _                          ' __out PSecBuffer Output
' ) AS LONG                                              ' NTSTATUS

'typedef
'NTSTATUS
'(NTAPI LSA_REGISTER_CALLBACK)(
'    ULONG   CallbackId,
'    PLSA_CALLBACK_FUNCTION Callback
'    );

'FUNCTION LSA_REGISTER_CALLBACK ( _
'   BYVAL CallbackId AS DWORD _                          ' ULONG CallbackId
' , BYVAL Callback AS DWORD _                            ' PLSA_CALLBACK_FUNCTION Callback
' ) AS LONG                                              ' NTSTATUS

%NOTIFIER_FLAG_NEW_THREAD    = &H00000001???
%NOTIFIER_FLAG_ONE_SHOT      = &H00000002???
%NOTIFIER_FLAG_SECONDS       = &H80000000???

%NOTIFIER_TYPE_INTERVAL      = 1
%NOTIFIER_TYPE_HANDLE_WAIT   = 2
%NOTIFIER_TYPE_STATE_CHANGE  = 3
%NOTIFIER_TYPE_NOTIFY_EVENT  = 4
%NOTIFIER_TYPE_IMMEDIATE     = 16

%NOTIFY_CLASS_PACKAGE_CHANGE  = 1
%NOTIFY_CLASS_ROLE_CHANGE     = 2
%NOTIFY_CLASS_DOMAIN_CHANGE   = 3
%NOTIFY_CLASS_REGISTRY_CHANGE = 4

' // Size = 16 bytes
TYPE SECPKG_EVENT_PACKAGE_CHANGE DWORD
   ChangeType  AS DWORD             ' ULONG
   PackageId   AS DWORD             ' LSA_SEC_HANDLE
   PackageName AS SECURITY_STRING
END TYPE

%SECPKG_PACKAGE_CHANGE_LOAD   = 0
%SECPKG_PACKAGE_CHANGE_UNLOAD = 1
%SECPKG_PACKAGE_CHANGE_SELECT = 2

' // Size = 8 bytes
TYPE SECPKG_EVENT_ROLE_CHANGE DWORD
   PreviousRole AS DWORD   ' ULONG
   NewRole      AS DWORD   ' ULONG
END TYPE

'typedef struct _SECPKG_PARAMETERS SECPKG_EVENT_DOMAIN_CHANGE;
'typedef struct _SECPKG_PARAMETERS * PSECPKG_EVENT_DOMAIN_CHANGE;


' // Size = 20 bytes
TYPE SECPKG_EVENT_NOTIFY DWORD
   EventClass       AS DWORD   ' ULONG
   Reserved         AS DWORD   ' ULONG
   EventDataSize    AS DWORD   ' ULONG
   EventData        AS DWORD   ' PVOID
   PackageParameter AS DWORD   ' PVOID
END TYPE


'typedef
'NTSTATUS
'(NTAPI LSA_UPDATE_PRIMARY_CREDENTIALS)(
'    IN PSECPKG_PRIMARY_CRED PrimaryCredentials,
'    IN OPTIONAL PSECPKG_SUPPLEMENTAL_CRED_ARRAY Credentials
'    );

'FUNCTION LSA_UPDATE_PRIMARY_CREDENTIALS ( _
'   BYREF PrimaryCredentials AS SECPKG_PRIMARY_CRED _    ' __in PSECPKG_PRIMARY_CRED PrimaryCredentials
' , BYREF Credentials AS SECPKG_SUPPLEMENTAL_CRED_ARRAY _ ' __in OPTIONAL PSECPKG_SUPPLEMENTAL_CRED_ARRAY Credentials
' ) AS LONG                                              ' NTSTATUS

'typedef
'VOID
'(NTAPI LSA_PROTECT_MEMORY)(
'    IN PVOID Buffer,
'    IN ULONG BufferSize
'    );

'SUB LSA_PROTECT_MEMORY ( _
'   BYVAL Buffer AS DWORD _                              ' __in PVOID Buffer
' , BYREF BufferSize AS DWORD _                          ' __in ULONG BufferSize
' )                                                      ' VOID

'typedef
'NTSTATUS
'(NTAPI LSA_OPEN_TOKEN_BY_LOGON_ID)(
'    IN PLUID LogonId,
'    OUT HANDLE *RetTokenHandle
'    );

'FUNCTION LSA_OPEN_TOKEN_BY_LOGON_ID ( _
'   BYREF LogonId AS QUAD _                              ' __in PLUID LogonId
' , BYREF RetTokenHandle AS DWORD _                      ' __out HANDLE *RetTokenHandle
' ) AS LONG                                              ' NTSTATUS

'typedef
'NTSTATUS
'(NTAPI LSA_EXPAND_AUTH_DATA_FOR_DOMAIN)(
'    IN PUCHAR UserAuthData,
'    IN ULONG UserAuthDataSize,
'    IN PVOID Reserved,
'    OUT PUCHAR * ExpandedAuthData,
'    OUT PULONG ExpandedAuthDataSize
'    );

'FUNCTION LSA_EXPAND_AUTH_DATA_FOR_DOMAIN ( _
'   BYVAL UserAuthData AS BYTE PTR _                     ' __in PUCHAR UserAuthData
' , BYVAL UserAuthDataSize AS DWORD _                    ' __in ULONG UserAuthDataSize
' , BYVAL Reserved AS DWORD _                            ' __in PVOID Reserved
' , BYREF ExpandedAuthData AS DWORD _                    ' __out PUCHAR * ExpandedAuthData
' , BYREF ExpandedAuthDataSize AS DWORD _                ' __out PULONG ExpandedAuthDataSize
' ) AS LONG                                              ' NTSTATUS

'typedef LSA_IMPERSONATE_CLIENT * PLSA_IMPERSONATE_CLIENT;
'typedef LSA_UNLOAD_PACKAGE * PLSA_UNLOAD_PACKAGE;
'typedef LSA_DUPLICATE_HANDLE * PLSA_DUPLICATE_HANDLE;
'typedef LSA_SAVE_SUPPLEMENTAL_CREDENTIALS * PLSA_SAVE_SUPPLEMENTAL_CREDENTIALS;
'typedef LSA_CREATE_THREAD * PLSA_CREATE_THREAD;
'typedef LSA_GET_CLIENT_INFO * PLSA_GET_CLIENT_INFO;
'typedef LSA_REGISTER_NOTIFICATION * PLSA_REGISTER_NOTIFICATION;
'typedef LSA_CANCEL_NOTIFICATION * PLSA_CANCEL_NOTIFICATION;
'typedef LSA_MAP_BUFFER * PLSA_MAP_BUFFER;
'typedef LSA_CREATE_TOKEN * PLSA_CREATE_TOKEN;
'typedef LSA_AUDIT_LOGON * PLSA_AUDIT_LOGON;
'typedef LSA_CALL_PACKAGE * PLSA_CALL_PACKAGE;
'typedef LSA_CALL_PACKAGEEX * PLSA_CALL_PACKAGEEX;
'typedef LSA_GET_CALL_INFO * PLSA_GET_CALL_INFO;
'typedef LSA_CREATE_SHARED_MEMORY * PLSA_CREATE_SHARED_MEMORY;
'typedef LSA_ALLOCATE_SHARED_MEMORY * PLSA_ALLOCATE_SHARED_MEMORY;
'typedef LSA_FREE_SHARED_MEMORY * PLSA_FREE_SHARED_MEMORY;
'typedef LSA_DELETE_SHARED_MEMORY * PLSA_DELETE_SHARED_MEMORY;
'typedef LSA_OPEN_SAM_USER * PLSA_OPEN_SAM_USER;
'typedef LSA_GET_USER_CREDENTIALS * PLSA_GET_USER_CREDENTIALS;
'typedef LSA_GET_USER_AUTH_DATA * PLSA_GET_USER_AUTH_DATA;
'typedef LSA_CLOSE_SAM_USER * PLSA_CLOSE_SAM_USER;
'typedef LSA_CONVERT_AUTH_DATA_TO_TOKEN * PLSA_CONVERT_AUTH_DATA_TO_TOKEN;
'typedef LSA_CLIENT_CALLBACK * PLSA_CLIENT_CALLBACK;
'typedef LSA_REGISTER_CALLBACK * PLSA_REGISTER_CALLBACK;
'typedef LSA_UPDATE_PRIMARY_CREDENTIALS * PLSA_UPDATE_PRIMARY_CREDENTIALS;
'typedef LSA_GET_AUTH_DATA_FOR_USER * PLSA_GET_AUTH_DATA_FOR_USER;
'typedef LSA_CRACK_SINGLE_NAME * PLSA_CRACK_SINGLE_NAME;
'typedef LSA_AUDIT_ACCOUNT_LOGON * PLSA_AUDIT_ACCOUNT_LOGON;
'typedef LSA_CALL_PACKAGE_PASSTHROUGH * PLSA_CALL_PACKAGE_PASSTHROUGH;
'typedef LSA_PROTECT_MEMORY * PLSA_PROTECT_MEMORY;
'typedef LSA_OPEN_TOKEN_BY_LOGON_ID * PLSA_OPEN_TOKEN_BY_LOGON_ID;
'typedef LSA_EXPAND_AUTH_DATA_FOR_DOMAIN * PLSA_EXPAND_AUTH_DATA_FOR_DOMAIN;
'typedef LSA_CREATE_TOKEN_EX * PLSA_CREATE_TOKEN_EX;

#IF %DEF(%WINCRED_INC)

'//
'// When passing a credential around, the CredentialBlob field is encrypted.
'// This structure describes this encrypted form.
'//
'//
'#IF NOT %DEF(%ENCRYPTED_CREDENTIAL_DEFINED)
'    %ENCRYPTED_CREDENTIAL_DEFINED = 1

'typedef struct _ENCRYPTED_CREDENTIALW {

'    //
'    // The credential
'    //
'    // The CredentialBlob field points to the encrypted credential
'    // The CredentialBlobSize field is the length (in bytes) of the encrypted credential
'    //

'    CREDENTIALW Cred;

'    //
'    // The size in bytes of the clear text credential blob
'    //

'    ULONG ClearCredentialBlobSize;
'} ENCRYPTED_CREDENTIALW, *PENCRYPTED_CREDENTIALW;
'#endif // _ENCRYPTED_CREDENTIAL_DEFINED

' // Size = 56 bytes
TYPE ENCRYPTED_CREDENTIALW DWORD
   Cred                    AS CREDENTIALW
   ClearCredentialBlobSize AS DWORD         ' ULONG
END TYPE

'#ENDIF   ' // _ENCRYPTED_CREDENTIAL_DEFINED

'//
'// Values for CredFlags parameter
'//

%CREDP_FLAGS_IN_PROCESS              = &H01   ' // Caller is in-process. Password data may be returned
%CREDP_FLAGS_USE_MIDL_HEAP           = &H02   ' // Allocated buffer should use MIDL_user_allocte
%CREDP_FLAGS_DONT_CACHE_TI           = &H04   ' // TargetInformation shouldn't be cached for CredGetTargetInfo
%CREDP_FLAGS_CLEAR_PASSWORD          = &H08   ' // Credential blob is passed in in-the-clear
%CREDP_FLAGS_USER_ENCRYPTED_PASSWORD = &H10   ' // Credential blob is passed protected by RtlEncryptMemory
%CREDP_FLAGS_TRUSTED_CALLER          = &H20   ' // Caller is a trusted process (eg. logon process).

'//
'// Possible forms of the username returned from CredMan
'//

' enum CredParsedUserNameType
%parsedUsernameInvalid      = 0
%parsedUsernameUpn          = 1
%parsedUsernameNt4Style     = 2
%parsedUsernameCertificate  = 3
%parsedUsernameNonQualified = 4


'typedef NTSTATUS
'(NTAPI CredReadFn) (
'    IN PLUID LogonId,
'    IN ULONG CredFlags,
'    IN LPWSTR TargetName,
'    IN ULONG Type,
'    IN ULONG Flags,
'    OUT PENCRYPTED_CREDENTIALW *Credential
'    );

'FUNCTION CredReadFn ( _
'   BYREF LogonId AS QUAD _                              ' __in PLUID LogonId
' , BYVAL CredFlags AS DWORD _                           ' __in ULONG CredFlags
' , BYREF TargetName AS WSTRINGZ _                       ' __in LPWSTR TargetName
' , BYVAL Type AS DWORD _                                ' __in ULONG Type
' , BYVAL Flags AS DWORD _                               '  __in ULONG Flags
' , BYREF Credential AS ENCRYPTED_CREDENTIALW _          ' __out PENCRYPTED_CREDENTIALW *Credential
' ) AS LONG                                              ' NTSTATUS

'typedef NTSTATUS
'(NTAPI CredReadDomainCredentialsFn) (
'    IN PLUID LogonId,
'    IN ULONG CredFlags,
'    IN PCREDENTIAL_TARGET_INFORMATIONW TargetInfo,
'    IN ULONG Flags,
'    OUT PULONG Count,
'    OUT PENCRYPTED_CREDENTIALW **Credential
'    );

'FUNCTION CredReadDomainCredentialsFn ( _
'   BYREF LogonId AS QUAD _                              ' __in PLUID LogonId
' , BYVAL CredFlags AS DWORD _                           ' __in ULONG CredFlags
' , BYREF TargetInfo AS CREDENTIAL_TARGET_INFORMATIONW _ ' __in PCREDENTIAL_TARGET_INFORMATIONW TargetInfo
' , BYVAL Flags AS DWORD _                               ' __in ULONG Flags
' , BYREF Count AS DWORD _                               ' __out PULONG Count
' , BYREF Credential AS ENCRYPTED_CREDENTIALW _          ' __out PENCRYPTED_CREDENTIALW **Credential
' ) AS LONG                                              ' NTSTATUS

'typedef VOID
'(NTAPI CredFreeCredentialsFn) (
'    IN ULONG Count,
'    IN PENCRYPTED_CREDENTIALW *Credentials OPTIONAL
'    );

'SUB CredReadDomainCredentialsFn ( _
'   BYVAL Count AS DWORD _                               ' __in ULONG Count
' , BYREF Credentials AS ENCRYPTED_CREDENTIALW _         ' __in PENCRYPTED_CREDENTIALW *Credentials OPTIONAL
' )                                                      ' VOID

'typedef NTSTATUS
'(NTAPI CredWriteFn) (
'    IN PLUID LogonId,
'    IN ULONG CredFlags,
'    IN PENCRYPTED_CREDENTIALW Credential,
'    IN ULONG Flags
'    );

'FUNCTION CredWriteFn ( _
'   BYREF LogonId AS QUAD _                              ' __in PLUID LogonId
' , BYVAL CredFlags AS DWORD _                           ' __in ULONG CredFlags
' , BYREF Credential AS ENCRYPTED_CREDENTIALW _          ' __in PENCRYPTED_CREDENTIALW Credential
' , BYVAL Flags AS DWORD _                               ' __in ULONG Flags
' ) AS LONG                                              ' NTSTATUS

'typedef NTSTATUS
'(NTAPI CrediUnmarshalandDecodeStringFn)(
'    IN  LPWSTR  MarshaledString,
'    OUT LPBYTE  *Blob,
'    OUT ULONG *BlobSize,
'    OUT BOOLEAN *IsFailureFatal
'    );

'FUNCTION CrediUnmarshalandDecodeStringFn ( _
'   BYREF MarshaledString AS WSTRINGZ _                  ' __in  LPWSTR  MarshaledString
' , BYVAL Blob AS BYTE PTR _                             ' __out LPBYTE  *Blob
' , BYREF BlobSize AS DWORD _                            ' __out ULONG *BlobSize
' , BYREF IsFailureFatal AS BYTE _                       ' __out BOOLEAN *IsFailureFatal
' ) AS LONG                                              ' NTSTATUS

'NTSTATUS
'CredMarshalTargetInfo (
'    __in        PCREDENTIAL_TARGET_INFORMATIONW InTargetInfo,
'    __deref_out PUSHORT *Buffer,
'    __out       PULONG   BufferSize
'    );

DECLARE FUNCTION CredMarshalTargetInfo IMPORT "Advapi32.dll" ALIAS "CredMarshalTargetInfo" ( _
   BYREF InTargetInfo AS CREDENTIAL_TARGET_INFORMATIONW _ ' __in  PCREDENTIAL_TARGET_INFORMATIONW InTargetInfo
 , BYREF Buffer AS WORD _                               ' __out PUSHORT *Buffer
 , BYREF BufferSize AS DWORD _                          ' __out PULONG BufferSize
 ) AS LONG                                              ' NTSTATUS

'NTSTATUS
'CredUnmarshalTargetInfo (
'    __in_bcount(BufferSize) PUSHORT            Buffer,
'    __in      ULONG                            BufferSize,
'    __out_opt PCREDENTIAL_TARGET_INFORMATIONW *RetTargetInfo,
'    __out_opt PULONG                           RetActualSize
'    );

DECLARE FUNCTION CredUnmarshalTargetInfo IMPORT "Advapi32.dll" ALIAS "CredUnmarshalTargetInfo" ( _
   BYREF Buffer AS WORD _                               ' __in_bcount(BufferSize) PUSHORT Buffer
 , BYVAL BufferSize AS DWORD _                          ' __in ULONG BufferSize
 , BYREF RetTargetInfo AS CREDENTIAL_TARGET_INFORMATIONW _ ' __out_opt PCREDENTIAL_TARGET_INFORMATIONW *RetTargetInfo
 , BYREF RetActualSize AS DWORD _                       ' __out_opt PULONG RetActualSize
 ) AS LONG                                              ' NTSTATUS

'// Number of bytes consumed by the trailing size ULONG
%CRED_MARSHALED_TI_SIZE_SIZE = 12

'NTSTATUS
'CredParseUserNameWithType (
'    __inout LPWSTR                  szParseName,
'    __out_opt PUNICODE_STRING       pUserName,
'    __out_opt PUNICODE_STRING       pDomainName,
'    __out CredParsedUserNameType *  pParseType
'    );

' Undocumented
'DECLARE FUNCTION CredParseUserNameWithType ( _
'   BYREF szParseName AS WSTRINGZ _                      ' __inout LPWSTR                  szParseName
' , BYREF pUserName AS UNICODE_STRING _                  ' __out_opt PUNICODE_STRING       pUserName
' , BYREF pDomainName AS UNICODE_STRING _                ' __out_opt PUNICODE_STRING       pDomainName
' , BYREF pParseType AS LONG _                           ' __out CredParsedUserNameType *  pParseType
' ) AS LONG                                              ' NTSTATUS

#ENDIF   ' // _WINCRED_H_


'//
'// Pure 32-bit versions of credential structures for packages
'// running wow64:
'//

' // Size = 28 bytes
TYPE SEC_WINNT_AUTH_IDENTITY32 DWORD
   User           AS DWORD   ' ULONG
   UserLength     AS DWORD   ' ULONG
   Domain         AS DWORD   ' ULONG
   DomainLength   AS DWORD   ' ULONG
   Password       AS DWORD   ' ULONG
   PasswordLength AS DWORD   ' ULONG
   Flags          AS DWORD   ' ULONG
END TYPE

' // Size = 44 bytes
TYPE SEC_WINNT_AUTH_IDENTITY_EX32 DWORD
   Version           AS DWORD   ' ULONG
   Length            AS DWORD   ' ULONG
   User              AS DWORD   ' ULONG
   UserLength        AS DWORD   ' ULONG
   Domain            AS DWORD   ' ULONG
   DomainLength      AS DWORD   ' ULONG
   Password          AS DWORD   ' ULONG
   PasswordLength    AS DWORD   ' ULONG
   Flags             AS DWORD   ' ULONG
   PackageList       AS DWORD   ' ULONG
   PackageListLength AS DWORD   ' ULONG
END TYPE

'// Functions provided by the SPM to the packages:
' // Size = 212 bytes
TYPE LSA_SECPKG_FUNCTION_TABLE DWORD
   CreateLogonSession            AS DWORD   ' PLSA_CREATE_LOGON_SESSION
   DeleteLogonSession            AS DWORD   ' PLSA_DELETE_LOGON_SESSION
   AddCredential                 AS DWORD   ' PLSA_ADD_CREDENTIAL
   GetCredentials                AS DWORD   ' PLSA_GET_CREDENTIALS
   DeleteCredential              AS DWORD   ' PLSA_DELETE_CREDENTIAL
   AllocateLsaHeap               AS DWORD   ' PLSA_ALLOCATE_LSA_HEAP
   FreeLsaHeap                   AS DWORD   ' PLSA_FREE_LSA_HEAP
   AllocateClientBuffer          AS DWORD   ' PLSA_ALLOCATE_CLIENT_BUFFER
   FreeClientBuffer              AS DWORD   ' PLSA_FREE_CLIENT_BUFFER
   CopyToClientBuffer            AS DWORD   ' PLSA_COPY_TO_CLIENT_BUFFER
   CopyFromClientBuffer          AS DWORD   ' PLSA_COPY_FROM_CLIENT_BUFFER
   ImpersonateClient             AS DWORD   ' PLSA_IMPERSONATE_CLIENT
   UnloadPackage                 AS DWORD   ' PLSA_UNLOAD_PACKAGE
   DuplicateHandle               AS DWORD   ' PLSA_DUPLICATE_HANDLE
   SaveSupplementalCredentials   AS DWORD   ' PLSA_SAVE_SUPPLEMENTAL_CREDENTIALS
   CreateThread                  AS DWORD   ' PLSA_CREATE_THREAD
   GetClientInfo                 AS DWORD   ' PLSA_GET_CLIENT_INFO
   RegisterNotification          AS DWORD   ' PLSA_REGISTER_NOTIFICATION
   CancelNotification            AS DWORD   ' PLSA_CANCEL_NOTIFICATION
   MapBuffer                     AS DWORD   ' PLSA_MAP_BUFFER
   CreateToken                   AS DWORD   ' PLSA_CREATE_TOKEN
   AuditLogon                    AS DWORD   ' PLSA_AUDIT_LOGON
   CallPackage                   AS DWORD   ' PLSA_CALL_PACKAGE
   FreeReturnBuffer              AS DWORD   ' PLSA_FREE_LSA_HEAP
   GetCallInfo                   AS DWORD   ' PLSA_GET_CALL_INFO
   CallPackageEx                 AS DWORD   ' PLSA_CALL_PACKAGEEX
   CreateSharedMemory            AS DWORD   ' PLSA_CREATE_SHARED_MEMORY
   AllocateSharedMemory          AS DWORD   ' PLSA_ALLOCATE_SHARED_MEMORY
   FreeSharedMemory              AS DWORD   ' PLSA_FREE_SHARED_MEMORY
   DeleteSharedMemory            AS DWORD   ' PLSA_DELETE_SHARED_MEMORY
   OpenSamUser                   AS DWORD   ' PLSA_OPEN_SAM_USER
   GetUserCredentials            AS DWORD   ' PLSA_GET_USER_CREDENTIALS
   GetUserAuthData               AS DWORD   ' PLSA_GET_USER_AUTH_DATA
   CloseSamUser                  AS DWORD   ' PLSA_CLOSE_SAM_USER
   ConvertAuthDataToToken        AS DWORD   ' PLSA_CONVERT_AUTH_DATA_TO_TOKEN
   ClientCallback                AS DWORD   ' PLSA_CLIENT_CALLBACK
   UpdateCredentials             AS DWORD   ' PLSA_UPDATE_PRIMARY_CREDENTIALS
   GetAuthDataForUser            AS DWORD   ' PLSA_GET_AUTH_DATA_FOR_USER
   CrackSingleName               AS DWORD   ' PLSA_CRACK_SINGLE_NAME
   AuditAccountLogon             AS DWORD   ' PLSA_AUDIT_ACCOUNT_LOGON
   CallPackagePassthrough        AS DWORD   ' PLSA_CALL_PACKAGE_PASSTHROUGH
#IF %DEF(%WINCRED_INC)
   CrediRead                     AS DWORD   ' CredReadFn*
   CrediReadDomainCredentials    AS DWORD   ' CredReadDomainCredentialsFn*
   CrediFreeCredentials          AS DWORD   ' CredFreeCredentialsFn*
#ELSE   ' // _WINCRED_H_
   DummyFunction1                AS DWORD   ' PLSA_PROTECT_MEMORY
   DummyFunction2                AS DWORD   ' PLSA_PROTECT_MEMORY
   DummyFunction3                AS DWORD   ' PLSA_PROTECT_MEMORY
#ENDIF   ' // _WINCRED_H_
   LsaProtectMemory              AS DWORD   ' PLSA_PROTECT_MEMORY
   LsaUnprotectMemory            AS DWORD   ' PLSA_PROTECT_MEMORY
   OpenTokenByLogonId            AS DWORD   ' PLSA_OPEN_TOKEN_BY_LOGON_ID
   ExpandAuthDataForDomain       AS DWORD   ' PLSA_EXPAND_AUTH_DATA_FOR_DOMAIN
   AllocatePrivateHeap           AS DWORD   ' PLSA_ALLOCATE_PRIVATE_HEAP
   FreePrivateHeap               AS DWORD   ' PLSA_FREE_PRIVATE_HEAP
   CreateTokenEx                 AS DWORD   ' PLSA_CREATE_TOKEN_EX
#IF %DEF(%WINCRED_INC)
   CrediWrite                    AS DWORD   ' CredWriteFn*
   CrediUnmarshalandDecodeString AS DWORD   ' CrediUnmarshalandDecodeStringFn*
#ELSE   ' // _WINCRED_H_
   DummyFunction4                AS DWORD   ' PLSA_PROTECT_MEMORY
   DummyFunction5                AS DWORD   ' PLSA_PROTECT_MEMORY
#ENDIF   ' // _WINCRED_H_
END TYPE


'typedef
'PVOID
'(NTAPI LSA_LOCATE_PKG_BY_ID)(
'    __in ULONG PackgeId
'    );

'FUNCTION LSA_LOCATE_PKG_BY_ID ( _
'   BYVAL PackgeId AS DWORD _                            ' __in ULONG PackgeId
' ) AS DWORD                                             ' PVOID

'typedef LSA_LOCATE_PKG_BY_ID * PLSA_LOCATE_PKG_BY_ID;

' // Size = 16 bytes
TYPE SECPKG_DLL_FUNCTIONS DWORD
   AllocateHeap      AS DWORD   ' PLSA_ALLOCATE_LSA_HEAP
   FreeHeap          AS DWORD   ' PLSA_FREE_LSA_HEAP
   RegisterCallback  AS DWORD   ' PLSA_REGISTER_CALLBACK
   LocatePackageById AS DWORD   ' PLSA_LOCATE_PKG_BY_ID
END TYPE


'//
'// The following prototypes are to functions that will be called only while
'// in the Security Package Manager context.
'//

'typedef NTSTATUS
'(NTAPI SpInitializeFn)(
'    IN ULONG_PTR PackageId,
'    IN PSECPKG_PARAMETERS Parameters,
'    IN PLSA_SECPKG_FUNCTION_TABLE FunctionTable
'    );

'FUNCTION SpInitializeFn ( _
'   BYVAL PackgeId AS DWORD _                            ' __in ULONG PackgeId
' , BYREF Parameters AS SECPKG_PARAMETERS _              '  __in PSECPKG_PARAMETERS Parameters
' , BYREF FunctionTable AS LSA_SECPKG_FUNCTION_TABLE _   '  __in PLSA_SECPKG_FUNCTION_TABLE FunctionTable
' ) AS LONG                                              ' NTSTATUS

'typedef NTSTATUS
'(NTAPI SpShutdownFn)(
'    VOID
'    );

'FUNCTION SpShutdownFn ( _
' ) AS LONG                                              ' NTSTATUS

'typedef NTSTATUS
'(NTAPI SpGetInfoFn)(
'    OUT PSecPkgInfo PackageInfo
'    );

'FUNCTION SpShutdownFn ( _
'   BYREF PackageInfo AS SecPkgInfo _                    ' PSecPkgInfo PackageInfo
' ) AS LONG                                              ' NTSTATUS

'typedef NTSTATUS
'(NTAPI SpGetExtendedInformationFn)(
'    IN  SECPKG_EXTENDED_INFORMATION_CLASS Class,
'    OUT PSECPKG_EXTENDED_INFORMATION * ppInformation
'    );

'FUNCTION SpGetExtendedInformationFn ( _
'   BYVAL Class AS LONG _                                ' __in  SECPKG_EXTENDED_INFORMATION_CLASS Class
' , BYREF ppInformation AS SECPKG_EXTENDED_INFORMATION _ ' __out PSECPKG_EXTENDED_INFORMATION * ppInformation
' ) AS LONG                                              ' NTSTATUS

'typedef NTSTATUS
'(NTAPI SpSetExtendedInformationFn)(
'    IN SECPKG_EXTENDED_INFORMATION_CLASS Class,
'    IN PSECPKG_EXTENDED_INFORMATION Info
'    );

'FUNCTION SpSetExtendedInformationFn ( _
'   BYVAL Class AS LONG _                                ' __in SECPKG_EXTENDED_INFORMATION_CLASS Class
' , BYREF Info AS SECPKG_EXTENDED_INFORMATION _          ' __in PSECPKG_EXTENDED_INFORMATION Info
' ) AS LONG                                              ' NTSTATUS

'typedef NTSTATUS
'(LSA_AP_LOGON_USER_EX2) (
'    __in PLSA_CLIENT_REQUEST ClientRequest,
'    __in SECURITY_LOGON_TYPE LogonType,
'    __in_bcount(SubmitBufferSize) PVOID ProtocolSubmitBuffer,
'    __in PVOID ClientBufferBase,
'    __in ULONG SubmitBufferSize,
'    __deref_out_bcount(*ProfileBufferSize) PVOID *ProfileBuffer,
'    __out PULONG ProfileBufferSize,
'    __out PLUID LogonId,
'    __out PNTSTATUS SubStatus,
'    __out PLSA_TOKEN_INFORMATION_TYPE TokenInformationType,
'    __deref_out PVOID *TokenInformation,
'    __out PUNICODE_STRING *AccountName,
'    __out PUNICODE_STRING *AuthenticatingAuthority,
'    __out PUNICODE_STRING *MachineName,
'    __out PSECPKG_PRIMARY_CRED PrimaryCredentials,
'    __deref_out PSECPKG_SUPPLEMENTAL_CRED_ARRAY * SupplementalCredentials
'    );

'FUNCTION LSA_AP_LOGON_USER_EX2 ( _
'   BYVAL ClientRequest AS DWORD _                       ' __in PLSA_CLIENT_REQUEST ClientRequest
' , BYVAL LogonType AS LONG _                            ' __in SECURITY_LOGON_TYPE LogonType
' , BYVAL ProtocolSubmitBuffer AS DWORD _                ' __in_bcount(SubmitBufferSize) PVOID ProtocolSubmitBuffer
' , BYVAL ClientBufferBase AS DWORD _                    ' __in PVOID ClientBufferBase
' , BYVAL SubmitBufferSize AS DWORD _                    ' __in ULONG SubmitBufferSize
' , BYVAL ProfileBuffer AS DWORD _                       ' __deref_out_bcount(*ProfileBufferSize) PVOID *ProfileBuffer
' , BYREF ProfileBufferSize AS DWORD _                   ' __out PULONG ProfileBufferSize
' , BYREF LogonId AS QUAD _                              ' __out PLUID LogonId
' , BYREF SubStatus AS LONG _                            ' __out PNTSTATUS SubStatus
' , BYREF TokenInformationType AS LONG _                 ' __out PLSA_TOKEN_INFORMATION_TYPE TokenInformationType
' , BYVAL TokenInformation AS DWORD _                    ' __deref_out PVOID *TokenInformation
' , BYREF AccountName AS UNICODE_STRING _                ' __out PUNICODE_STRING *AccountName
' , BYREF AuthenticatingAuthority AS UNICODE_STRING _    ' __out PUNICODE_STRING *AuthenticatingAuthority
' , BYREF MachineName AS UNICODE_STRING _                ' __out PUNICODE_STRING *MachineName
' , BYREF PrimaryCredentials AS SECPKG_PRIMARY_CRED _    ' __out PSECPKG_PRIMARY_CRED PrimaryCredentials
' , BYREF SupplementalCredentials AS SECPKG_SUPPLEMENTAL_CRED_ARRAY _ '  __deref_out PSECPKG_SUPPLEMENTAL_CRED_ARRAY * SupplementalCredentials
' ) AS LONG                                              ' NTSTATUS

'typedef LSA_AP_LOGON_USER_EX2 *PLSA_AP_LOGON_USER_EX2;

$LSA_AP_NAME_LOGON_USER_EX2 = "LsaApLogonUserEx2"

'typedef NTSTATUS
'(NTAPI SpAcceptCredentialsFn)(
'    IN SECURITY_LOGON_TYPE LogonType,
'    IN PUNICODE_STRING AccountName,
'    IN PSECPKG_PRIMARY_CRED PrimaryCredentials,
'    IN PSECPKG_SUPPLEMENTAL_CRED SupplementalCredentials
'    );

'FUNCTION SpAcceptCredentialsFn ( _
'   BYVAL LogonType AS LONG _                            ' __in SECURITY_LOGON_TYPE LogonType
' , BYREF AccountName AS UNICODE_STRING _                ' __in PUNICODE_STRING AccountName
' , BYREF PrimaryCredentials AS SECPKG_PRIMARY_CRED _    ' __in PSECPKG_PRIMARY_CRED PrimaryCredentials
' , BYREF SupplementalCredentials AS SECPKG_SUPPLEMENTAL_CRED _ ' __in PSECPKG_SUPPLEMENTAL_CRED SupplementalCredentials
' ) AS LONG                                              ' NTSTATUS

'#define SP_ACCEPT_CREDENTIALS_NAME "SpAcceptCredentials\0"
$SP_ACCEPT_CREDENTIALS_NAME = "SpAcceptCredentials"

'typedef NTSTATUS
'(NTAPI SpAcquireCredentialsHandleFn)(
'    IN OPTIONAL PUNICODE_STRING PrincipalName,
'    IN ULONG CredentialUseFlags,
'    IN OPTIONAL PLUID LogonId,
'    IN PVOID AuthorizationData,
'    IN PVOID GetKeyFunciton,
'    IN PVOID GetKeyArgument,
'    OUT PLSA_SEC_HANDLE CredentialHandle,
'    OUT PTimeStamp ExpirationTime
'    );

'FUNCTION SpAcquireCredentialsHandleFn ( _
'   BYREF PrincipalName AS UNICODE_STRING _              ' __in OPTIONAL PUNICODE_STRING PrincipalName
' , BYVAL CredentialUseFlags AS DWORD _                  ' __in ULONG CredentialUseFlags
' , BYREF LogonId AS QUAD _                              ' __in OPTIONAL PLUID LogonId
' , BYVAL AuthorizationData AS DWORD _                   ' __in PVOID AuthorizationData
' , BYVAL GetKeyFunciton AS DWORD _                      ' __in PVOID GetKeyFunciton
' , BYVAL GetKeyArgument AS DWORD _                      ' __in PVOID GetKeyArgument
' , BYREF CredentialHandle AS DWORD _                    ' __out PLSA_SEC_HANDLE CredentialHandle
' , BYREF ExpirationTime AS QUAD _                       ' __out PTimeStamp ExpirationTime
' ) AS LONG                                              ' NTSTATUS

'typedef NTSTATUS
'(NTAPI SpFreeCredentialsHandleFn)(
'    IN LSA_SEC_HANDLE CredentialHandle
'    );

'FUNCTION SpFreeCredentialsHandleFn ( _
'   BYVAL CredentialHandle AS DWORD _                    ' __in LSA_SEC_HANDLE CredentialHandle
' ) AS LONG                                              ' NTSTATUS

'typedef NTSTATUS
'(NTAPI SpQueryCredentialsAttributesFn)(
'    IN LSA_SEC_HANDLE CredentialHandle,
'    IN ULONG CredentialAttribute,
'    IN OUT PVOID Buffer
'    );

'FUNCTION SpQueryCredentialsAttributesFn ( _
'   BYVAL CredentialHandle AS DWORD _                    ' __in LSA_SEC_HANDLE CredentialHandle
' , BYVAL CredentialAttribute AS DWORD _                 ' __in ULONG CredentialAttribute
' , BYVAL Buffer AS DWORD _                              ' __inout PVOID Buffer
' ) AS LONG                                              ' NTSTATUS

'typedef NTSTATUS
'(NTAPI SpSetCredentialsAttributesFn)(
'    IN LSA_SEC_HANDLE CredentialHandle,
'    IN ULONG CredentialAttribute,
'    IN PVOID Buffer,
'    IN ULONG BufferSize );

'FUNCTION SpSetCredentialsAttributesFn ( _
'   BYVAL CredentialHandle AS DWORD _                    ' __in LSA_SEC_HANDLE CredentialHandle
' , BYVAL CredentialAttribute AS DWORD _                 ' __in ULONG CredentialAttribute
' , BYVAL Buffer AS DWORD _                              ' __inout PVOID Buffer
' , BYVAL BufferSize AS DWORD _                          ' __in ULONG BufferSize
' ) AS LONG                                              ' NTSTATUS

'typedef NTSTATUS
'(NTAPI SpAddCredentialsFn)(
'    IN LSA_SEC_HANDLE CredentialHandle,
'    IN OPTIONAL PUNICODE_STRING PrincipalName,
'    IN PUNICODE_STRING Package,
'    IN ULONG CredentialUseFlags,
'    IN PVOID AuthorizationData,
'    IN PVOID GetKeyFunciton,
'    IN PVOID GetKeyArgument,
'    OUT PTimeStamp ExpirationTime
'    );

'FUNCTION SpAddCredentialsFn ( _
'   BYVAL CredentialHandle AS DWORD _                    ' __in LSA_SEC_HANDLE CredentialHandle
' , BYREF PrincipalName AS UNICODE_STRING _              ' __in_opt PUNICODE_STRING PrincipalName
' , BYREF Package AS UNICODE_STRING _                    ' __in PUNICODE_STRING Package
' , BYVAL CredentialUseFlags AS DWORD _                  ' __in ULONG CredentialUseFlags
' , BYVAL AuthorizationData AS DWORD _                   ' __in PVOID AuthorizationData
' , BYVAL GetKeyFunciton AS DWORD _                      ' __in PVOID GetKeyFunciton
' , BYVAL GetKeyArgument AS DWORD _                      ' __in PVOID GetKeyArgument
' , BYREF ExpirationTime AS QUAD _                       ' __out PTimeStamp ExpirationTime
' ) AS LONG                                              ' NTSTATUS

'typedef NTSTATUS
'(NTAPI SpSaveCredentialsFn)(
'    IN LSA_SEC_HANDLE CredentialHandle,
'    IN PSecBuffer Credentials);

'FUNCTION SpSaveCredentialsFn ( _
'   BYVAL CredentialHandle AS DWORD _                    ' __in LSA_SEC_HANDLE CredentialHandle
' , BYREF Credentials AS SecBuffer _                     ' __in PSecBuffer Credentials
' ) AS LONG                                              ' NTSTATUS

'typedef NTSTATUS
'(NTAPI SpGetCredentialsFn)(
'    IN LSA_SEC_HANDLE CredentialHandle,
'    IN OUT PSecBuffer Credentials
'    );

'FUNCTION SpGetCredentialsFn ( _
'   BYVAL CredentialHandle AS DWORD _                    ' __in LSA_SEC_HANDLE CredentialHandle
' , BYREF Credentials AS SecBuffer _                     ' __inout PSecBuffer Credentials
' ) AS LONG                                              ' NTSTATUS

'typedef NTSTATUS
'(NTAPI SpDeleteCredentialsFn)(
'    IN LSA_SEC_HANDLE CredentialHandle,
'    IN PSecBuffer Key
'    );

'FUNCTION SpDeleteCredentialsFn ( _
'   BYVAL CredentialHandle AS DWORD _                    ' __in LSA_SEC_HANDLE CredentialHandle
' , BYREF Key AS SecBuffer _                             ' __in PSecBuffer Key
' ) AS LONG                                              ' NTSTATUS

'typedef NTSTATUS
'(NTAPI SpInitLsaModeContextFn)(
'    IN OPTIONAL LSA_SEC_HANDLE CredentialHandle,
'    IN OPTIONAL LSA_SEC_HANDLE ContextHandle,
'    IN OPTIONAL PUNICODE_STRING TargetName,
'    IN ULONG ContextRequirements,
'    IN ULONG TargetDataRep,
'    IN PSecBufferDesc InputBuffers,
'    OUT PLSA_SEC_HANDLE NewContextHandle,
'    IN OUT PSecBufferDesc OutputBuffers,
'    OUT PULONG ContextAttributes,
'    OUT PTimeStamp ExpirationTime,
'    OUT PBOOLEAN MappedContext,
'    OUT PSecBuffer ContextData
'    );

'FUNCTION SpInitLsaModeContextFn ( _
'   BYVAL CredentialHandle AS DWORD _                    ' __in_opt LSA_SEC_HANDLE CredentialHandle
' , BYVAL ContextHandle AS DWORD _                       ' __in_opt LSA_SEC_HANDLE ContextHandle
' , BYREF TargetName AS UNICODE_STRING _                 ' __in_opt PUNICODE_STRING TargetName
' , BYVAL ContextRequirements AS DWORD _                 ' __in ULONG ContextRequirements
' , BYVAL TargetDataRep AS DWORD _                       ' __in ULONG TargetDataRep
' , BYREF InputBuffers AS SecBufferDesc _                ' __in PSecBufferDesc InputBuffers
' , BYREF NewContextHandle AS DWORD _                    ' __out PLSA_SEC_HANDLE NewContextHandle
' , BYREF OutputBuffers AS SecBufferDesc _               ' __inout PSecBufferDesc OutputBuffers
' , BYREF ContextAttributes AS DWORD _                   ' __out PULONG ContextAttributes
' , BYREF ExpirationTime AS QUAD _                       ' __out PTimeStamp ExpirationTime
' , BYREF MappedContext AS BYTE _                        ' __out PBOOLEAN MappedContext
' , BYREF ContextData AS SecBuffer _                     ' __out PSecBuffer ContextData
' ) AS LONG                                              ' NTSTATUS

'typedef NTSTATUS
'(NTAPI SpDeleteContextFn)(
'    IN LSA_SEC_HANDLE ContextHandle
'    );

'FUNCTION SpInitLsaModeContextFn ( _
'   BYVAL ContextHandle AS DWORD _                       ' __in_opt LSA_SEC_HANDLE ContextHandle
' ) AS LONG                                              ' NTSTATUS

'typedef NTSTATUS
'(NTAPI SpApplyControlTokenFn)(
'    IN LSA_SEC_HANDLE ContextHandle,
'    IN PSecBufferDesc ControlToken);

'FUNCTION SpApplyControlTokenFn ( _
'   BYVAL ContextHandle AS DWORD _                       ' __in_opt LSA_SEC_HANDLE ContextHandle
' , BYREF ControlToken AS SecBufferDesc _                '  __in PSecBufferDesc ControlToken
' ) AS LONG                                              ' NTSTATUS

'typedef NTSTATUS
'(NTAPI SpAcceptLsaModeContextFn)(
'    IN OPTIONAL LSA_SEC_HANDLE CredentialHandle,
'    IN OPTIONAL LSA_SEC_HANDLE ContextHandle,
'    IN PSecBufferDesc InputBuffer,
'    IN ULONG ContextRequirements,
'    IN ULONG TargetDataRep,
'    OUT PLSA_SEC_HANDLE NewContextHandle,
'    OUT PSecBufferDesc OutputBuffer,
'    OUT PULONG ContextAttributes,
'    OUT PTimeStamp ExpirationTime,
'    OUT PBOOLEAN MappedContext,
'    OUT PSecBuffer ContextData
'    );

'FUNCTION SpAcceptLsaModeContextFn ( _
'   BYVAL CredentialHandle AS DWORD _                    ' __in_opt LSA_SEC_HANDLE CredentialHandle
' , BYVAL ContextHandle AS DWORD _                       ' __in_opt LSA_SEC_HANDLE ContextHandle
' , BYREF InputBuffer AS SecBufferDesc _                 ' __in PSecBufferDesc InputBuffer
' , BYVAL ContextRequirements AS DWORD _                 ' __in ULONG ContextRequirements
' , BYVAL TargetDataRep AS DWORD _                       ' __in ULONG TargetDataRep
' , BYREF NewContextHandle AS DWORD _                    ' __out PLSA_SEC_HANDLE NewContextHandle
' , BYREF OutputBuffer AS SecBufferDesc _                ' __out PSecBufferDesc OutputBuffer
' , BYREF ContextAttributes AS DWORD _                   ' __out PULONG ContextAttributes
' , BYREF ExpirationTime AS QUAD _                       ' __out PTimeStamp ExpirationTime
' , BYREF MappedContext AS BYTE _                        ' __out PBOOLEAN MappedContext
' , BYREF ContextData AS SecBuffer _                     ' __out PSecBuffer ContextData
' ) AS LONG                                              ' NTSTATUS

'typedef NTSTATUS
'(NTAPI SpGetUserInfoFn)(
'    IN PLUID LogonId,
'    IN ULONG Flags,
'    OUT PSecurityUserData * UserData
'    );

'FUNCTION SpGetUserInfoFn ( _
'   BYREF LogonId AS QUAD _                              ' __in PLUID LogonId
' , BYVAL Flags AS DWORD _                               ' __in ULONG Flags
' , BYREF UserData AS SECURITY_USER_DATA _               ' __out PSecurityUserData * UserData
' ) AS LONG                                              ' NTSTATUS

'typedef NTSTATUS
'(NTAPI SpQueryContextAttributesFn)(
'    IN LSA_SEC_HANDLE ContextHandle,
'    IN ULONG ContextAttribute,
'    IN OUT PVOID Buffer);

'FUNCTION SpQueryContextAttributesFn ( _
'   BYVAL ContextHandle AS DWORD _                       ' __in LSA_SEC_HANDLE ContextHandle
' , BYVAL ContextAttribute AS DWORD _                    ' __in ULONG ContextAttribute
' , BYVAL Buffer AS DWORD _                              ' __inout PVOID Buffer
' ) AS LONG                                              ' NTSTATUS

'typedef NTSTATUS
'(NTAPI SpSetContextAttributesFn)(
'    IN LSA_SEC_HANDLE ContextHandle,
'    IN ULONG ContextAttribute,
'    IN PVOID Buffer,
'    IN ULONG BufferSize );

'FUNCTION SpSetContextAttributesFn ( _
'   BYVAL ContextHandle AS DWORD _                       ' __in LSA_SEC_HANDLE ContextHandle
' , BYVAL ContextAttribute AS DWORD _                    ' __in ULONG ContextAttribute
' , BYVAL Buffer AS DWORD _                              ' __inout PVOID Buffer
' , BYVAL BufferSize AS DWORD _                          ' __in ULONG BufferSize
' ) AS LONG                                              ' NTSTATUS

'typedef NTSTATUS
'(NTAPI SpChangeAccountPasswordFn)(
'    __in PUNICODE_STRING      pDomainName,
'    __in PUNICODE_STRING      pAccountName,
'    __in PUNICODE_STRING      pOldPassword,
'    __in PUNICODE_STRING      pNewPassword,
'    __in BOOLEAN              Impersonating,
'    __inout PSecBufferDesc   pOutput
'    );

'FUNCTION SpChangeAccountPasswordFn ( _
'   BYREF pDomainName AS UNICODE_STRING _                ' __in PUNICODE_STRING pDomainName
' , BYREF pAccountName AS UNICODE_STRING _               ' __in PUNICODE_STRING pAccountName
' , BYREF pOldPassword AS UNICODE_STRING _               ' __in PUNICODE_STRING pOldPassword
' , BYREF pNewPassword AS UNICODE_STRING _               ' __in PUNICODE_STRING pNewPassword
' , BYVAL Impersonating AS BYTE _                        ' __in BOOLEAN Impersonating
' , BYREF pOutput AS SecBufferDesc _                     ' __inout PSecBufferDesc pOutput
' ) AS LONG                                              ' NTSTATUS

'typedef NTSTATUS
'(NTAPI SpQueryMetaDataFn)(
'    __in_opt LSA_SEC_HANDLE CredentialHandle,
'    __in_opt PUNICODE_STRING TargetName,
'    __in ULONG ContextRequirements,
'    __out PULONG MetaDataLength,
'    __deref_out_bcount(*MetaDataLength) PUCHAR* MetaData,
'    __inout PLSA_SEC_HANDLE ContextHandle
'    );

'FUNCTION SpQueryMetaDataFn ( _
'   BYVAL CredentialHandle AS DWORD _                    ' __in_opt LSA_SEC_HANDLE CredentialHandle
' , BYREF TargetName AS UNICODE_STRING _                 ' __in_opt PUNICODE_STRING TargetName
' , BYVAL ContextRequirements AS DWORD _                 ' __in ULONG ContextRequirements
' , BYREF MetaDataLength AS DWORD _                      ' __out PULONG MetaDataLength
' , BYVAL MetaData AS BYTE PTR _                         ' __deref_out_bcount(*MetaDataLength) PUCHAR* MetaData
' , BYREF ContextHandle AS DWORD _                       ' __inout PLSA_SEC_HANDLE ContextHandle
' ) AS LONG                                              ' NTSTATUS

'typedef NTSTATUS
'(NTAPI SpExchangeMetaDataFn)(
'    __in_opt LSA_SEC_HANDLE CredentialHandle,
'    __in_opt PUNICODE_STRING TargetName,
'    __in ULONG ContextRequirements,
'    __in ULONG MetaDataLength,
'    __in_bcount(MetaDataLength) PUCHAR MetaData,
'    __inout PLSA_SEC_HANDLE ContextHandle
'    );

'FUNCTION SpExchangeMetaDataFn ( _
'   BYVAL CredentialHandle AS DWORD _                    ' __in_opt LSA_SEC_HANDLE CredentialHandle
' , BYREF TargetName AS UNICODE_STRING _                 ' __in_opt PUNICODE_STRING TargetName
' , BYVAL ContextRequirements AS DWORD _                 ' __in ULONG ContextRequirements
' , BYVAL MetaDataLength AS DWORD _                      ' __in ULONG MetaDataLength
' , BYVAL MetaData AS BYTE PTR _                         ' __deref_out_bcount(*MetaDataLength) PUCHAR* MetaData
' , BYREF ContextHandle AS DWORD _                       ' __inout PLSA_SEC_HANDLE ContextHandle
' ) AS LONG                                              ' NTSTATUS

'typedef NTSTATUS
'(NTAPI SpGetCredUIContextFn)(
'   __in LSA_SEC_HANDLE ContextHandle,
'   __in GUID* CredType,
'   __out PULONG FlatCredUIContextLength,
'   __deref_out_bcount(*FlatCredUIContextLength)  PUCHAR* FlatCredUIContext
'   );

'FUNCTION SpGetCredUIContextFn ( _
'   BYVAL ContextHandle AS DWORD _                       ' __in_opt LSA_SEC_HANDLE ContextHandle
' , BYREF CredType AS GUID _                             ' __in GUID* CredType
' , BYREF FlatCredUIContextLength AS DWORD _             ' __out PULONG FlatCredUIContextLength
' , BYVAL FlatCredUIContext AS BYTE PTR _                ' __deref_out_bcount(*FlatCredUIContextLength) PUCHAR* FlatCredUIContext
' ) AS LONG                                              ' NTSTATUS

'typedef NTSTATUS
'(NTAPI SpUpdateCredentialsFn)(
'  __in LSA_SEC_HANDLE ContextHandle,
'  __in GUID* CredType,
'  __in ULONG FlatCredUIContextLength,
'  __in_bcount(FlatCredUIContextLength) PUCHAR FlatCredUIContext
'  );

'FUNCTION SpUpdateCredentialsFn ( _
'   BYVAL ContextHandle AS DWORD _                       ' __in_opt LSA_SEC_HANDLE ContextHandle
' , BYREF CredType AS GUID _                             ' __in GUID* CredType
' , BYVAL FlatCredUIContextLength AS DWORD _             ' __in ULONG FlatCredUIContextLength,
' , BYVAL FlatCredUIContext AS BYTE PTR _                ' __in_bcount(FlatCredUIContextLength) PUCHAR FlatCredUIContext
' ) AS LONG                                              ' NTSTATUS

'typedef NTSTATUS
'(NTAPI SpValidateTargetInfoFn) (
'    __in_opt PLSA_CLIENT_REQUEST ClientRequest,
'    __in_bcount(SubmitBufferLength) PVOID ProtocolSubmitBuffer,
'    __in PVOID ClientBufferBase,
'    __in ULONG SubmitBufferLength,
'    __in PSECPKG_TARGETINFO TargetInfo
'    );

'FUNCTION SpValidateTargetInfoFn ( _
'   BYVAL ClientRequest AS DWORD _                       ' __in_opt PLSA_CLIENT_REQUEST ClientRequest
' , BYVAL ProtocolSubmitBuffer AS DWORD _                ' __in_bcount(SubmitBufferLength) PVOID ProtocolSubmitBuffer
' , BYVAL ClientBufferBase AS DWORD _                    ' __in PVOID ClientBufferBase
' , BYVAL SubmitBufferLength AS DWORD _                  ' __in ULONG SubmitBufferLength
' , BYREF TargetInfo AS SECPKG_TARGETINFO _              ' __in PSECPKG_TARGETINFO TargetInfo
' ) AS LONG                                              ' NTSTATUS

' // Size = 140 bytes
TYPE SECPKG_FUNCTION_TABLE DWORD
   InitializePackage          AS DWORD   ' PLSA_AP_INITIALIZE_PACKAGE
   LogonUser                  AS DWORD   ' PLSA_AP_LOGON_USER
   CallPackage                AS DWORD   ' PLSA_AP_CALL_PACKAGE
   LogonTerminated            AS DWORD   ' PLSA_AP_LOGON_TERMINATED
   CallPackageUntrusted       AS DWORD   ' PLSA_AP_CALL_PACKAGE_UNTRUSTED
   CallPackagePassthrough     AS DWORD   ' PLSA_AP_CALL_PACKAGE_PASSTHROUGH
   LogonUserEx                AS DWORD   ' PLSA_AP_LOGON_USER_EX
   LogonUserEx2               AS DWORD   ' PLSA_AP_LOGON_USER_EX2
   Initialize                 AS DWORD   ' SpInitializeFn *
   Shutdown                   AS DWORD   ' SpShutdownFn *
   GetInfo                    AS DWORD   ' SpGetInfoFn *
   AcceptCredentials          AS DWORD   ' SpAcceptCredentialsFn *
   AcquireCredentialsHandle   AS DWORD   ' SpAcquireCredentialsHandleFn *
   QueryCredentialsAttributes AS DWORD   ' SpQueryCredentialsAttributesFn *
   FreeCredentialsHandle      AS DWORD   ' SpFreeCredentialsHandleFn *
   SaveCredentials            AS DWORD   ' SpSaveCredentialsFn *
   GetCredentials             AS DWORD   ' SpGetCredentialsFn *
   DeleteCredentials          AS DWORD   ' SpDeleteCredentialsFn *
   InitLsaModeContext         AS DWORD   ' SpInitLsaModeContextFn *
   AcceptLsaModeContext       AS DWORD   ' SpAcceptLsaModeContextFn *
   DeleteContext              AS DWORD   ' SpDeleteContextFn *
   ApplyControlToken          AS DWORD   ' SpApplyControlTokenFn *
   GetUserInfo                AS DWORD   ' SpGetUserInfoFn *
   GetExtendedInformation     AS DWORD   ' SpGetExtendedInformationFn *
   QueryContextAttributes     AS DWORD   ' SpQueryContextAttributesFn *
   AddCredentials             AS DWORD   ' SpAddCredentialsFn *
   SetExtendedInformation     AS DWORD   ' SpSetExtendedInformationFn *
   SetContextAttributes       AS DWORD   ' SpSetContextAttributesFn *
   SetCredentialsAttributes   AS DWORD   ' SpSetCredentialsAttributesFn *
   ChangeAccountPassword      AS DWORD   ' SpChangeAccountPasswordFn *
   QueryMetaData              AS DWORD   ' SpQueryMetaDataFn*
   ExchangeMetaData           AS DWORD   ' SpExchangeMetaDataFn*
   GetCredUIContext           AS DWORD   ' SpGetCredUIContextFn*
   UpdateCredentials          AS DWORD   ' SpUpdateCredentialsFn*
   ValidateTargetInfo         AS DWORD   ' SpValidateTargetInfoFn*
END TYPE

'//
'// The following prototypes are to functions that will be called while in the
'// context of a user process that is using the functions through the security
'// DLL.
'//
'typedef NTSTATUS
'(NTAPI SpInstanceInitFn)(
'    IN ULONG Version,
'    IN PSECPKG_DLL_FUNCTIONS FunctionTable,
'    OUT PVOID * UserFunctions
'    );

'FUNCTION SpInstanceInitFn ( _
'   BYVAL Version AS DWORD _                             ' __in ULONG Version
' , BYREF FunctionTable AS SECPKG_DLL_FUNCTIONS _        ' __in PSECPKG_DLL_FUNCTIONS FunctionTable
' , BYREF UserFunctions AS DWORD _                       ' __out PVOID * UserFunctions
' ) AS LONG                                              ' NTSTATUS

'typedef NTSTATUS
'(NTAPI SpInitUserModeContextFn)(
'    IN LSA_SEC_HANDLE ContextHandle,
'    IN PSecBuffer PackedContext
'    );

'FUNCTION SpInitUserModeContextFn ( _
'   BYVAL ContextHandle AS DWORD _                       ' __in LSA_SEC_HANDLE ContextHandle
' , BYREF PackedContext AS SecBuffer _                   ' __in PSecBuffer PackedContext
' ) AS LONG                                              ' NTSTATUS

'typedef NTSTATUS
'(NTAPI SpMakeSignatureFn)(
'    IN LSA_SEC_HANDLE ContextHandle,
'    IN ULONG QualityOfProtection,
'    IN PSecBufferDesc MessageBuffers,
'    IN ULONG MessageSequenceNumber
'    );

'FUNCTION SpMakeSignatureFn ( _
'   BYVAL ContextHandle AS DWORD _                       ' __in LSA_SEC_HANDLE ContextHandle
' , BYVAL QualityOfProtection AS DWORD _                 ' __in ULONG QualityOfProtection
' , BYREF MessageBuffers AS SecBufferDesc _              ' __in PSecBufferDesc MessageBuffers
' , BYVAL MessageSequenceNumber AS DWORD _               ' __in ULONG MessageSequenceNumber
' ) AS LONG                                              ' NTSTATUS

'typedef NTSTATUS
'(NTAPI SpVerifySignatureFn)(
'    IN LSA_SEC_HANDLE ContextHandle,
'    IN PSecBufferDesc MessageBuffers,
'    IN ULONG MessageSequenceNumber,
'    OUT PULONG QualityOfProtection
'    );

'FUNCTION SpVerifySignatureFn ( _
'   BYVAL ContextHandle AS DWORD _                       ' __in LSA_SEC_HANDLE ContextHandle
' , BYREF MessageBuffers AS SecBufferDesc _              ' __in PSecBufferDesc MessageBuffers
' , BYVAL MessageSequenceNumber AS DWORD _               ' __in ULONG MessageSequenceNumber
' , BYREF QualityOfProtection AS DWORD _                 ' __out PULONG QualityOfProtection
' ) AS LONG                                              ' NTSTATUS

'typedef NTSTATUS
'(NTAPI SpSealMessageFn)(
'    IN LSA_SEC_HANDLE ContextHandle,
'    IN ULONG QualityOfProtection,
'    IN PSecBufferDesc MessageBuffers,
'    IN ULONG MessageSequenceNumber
'    );

'FUNCTION SpSealMessageFn ( _
'   BYVAL ContextHandle AS DWORD _                       ' __in LSA_SEC_HANDLE ContextHandle
' , BYVAL QualityOfProtection AS DWORD _                 ' __in ULONG QualityOfProtection
' , BYREF MessageBuffers AS SecBufferDesc _              ' __in PSecBufferDesc MessageBuffers
' , BYVAL MessageSequenceNumber AS DWORD _               ' __in ULONG MessageSequenceNumber
' ) AS LONG                                              ' NTSTATUS

'typedef NTSTATUS
'(NTAPI SpUnsealMessageFn)(
'    IN LSA_SEC_HANDLE ContextHandle,
'    IN PSecBufferDesc MessageBuffers,
'    IN ULONG MessageSequenceNumber,
'    OUT PULONG QualityOfProtection
'    );

'FUNCTION SpUnsealMessageFn ( _
'   BYVAL ContextHandle AS DWORD _                       ' __in LSA_SEC_HANDLE ContextHandle
' , BYREF MessageBuffers AS SecBufferDesc _              ' __in PSecBufferDesc MessageBuffers
' , BYVAL MessageSequenceNumber AS DWORD _               ' __in ULONG MessageSequenceNumber
' , BYREF QualityOfProtection AS DWORD _                 ' __out PULONG QualityOfProtection
' ) AS LONG                                              ' NTSTATUS

'typedef NTSTATUS
'(NTAPI SpGetContextTokenFn)(
'    IN LSA_SEC_HANDLE ContextHandle,
'    OUT PHANDLE ImpersonationToken
'    );

'FUNCTION SpGetContextTokenFn ( _
'   BYVAL ContextHandle AS DWORD _                       ' __in LSA_SEC_HANDLE ContextHandle
' , BYREF ImpersonationToken AS DWORD _                  ' __out PHANDLE ImpersonationToken
' ) AS LONG                                              ' NTSTATUS

'typedef NTSTATUS
'(NTAPI SpExportSecurityContextFn)(
'    LSA_SEC_HANDLE       phContext,             // (in) context to export
'    ULONG                fFlags,                // (in) option flags
'    PSecBuffer           pPackedContext,        // (out) marshalled context
'    PHANDLE              pToken                 // (out, optional) token handle for impersonation
'    );

'FUNCTION SpExportSecurityContextFn ( _
'   BYVAL phContext AS DWORD _                           ' LSA_SEC_HANDLE phContext      ' // (in) context to export
' , BYREF fFlags AS DWORD _                              ' ULONG          fFlags         ' // (in) option flags
' , BYREF pPackedContext AS SecBuffer _                  ' PSecBuffer     pPackedContext ' // (out) marshalled context
' , BYREF pToken AS DWORD _                              ' PHANDLE        pToken         ' // (out, optional) token handle for impersonation
' ) AS LONG                                              ' NTSTATUS

'typedef NTSTATUS
'(NTAPI SpImportSecurityContextFn)(
'    PSecBuffer           pPackedContext,        // (in) marshalled context
'    HANDLE               Token,                 // (in, optional) handle to token for context
'    PLSA_SEC_HANDLE      phContext              // (out) new context handle
'    );

'FUNCTION SpImportSecurityContextFn ( _
'   BYREF pPackedContext AS SecBuffer _                  ' PSecBuffer      pPackedContext ' // (in) marshalled context
' , BYVAL Token AS DWORD _                               ' HANDLE          Token          ' // (in, optional) handle to token for context
' , BYVAL phContext AS DWORD _                           ' PLSA_SEC_HANDLE phContext      ' // (out) new context handle
' ) AS LONG                                              ' NTSTATUS

'typedef NTSTATUS
'(NTAPI SpCompleteAuthTokenFn)(
'    IN LSA_SEC_HANDLE ContextHandle,
'    IN PSecBufferDesc InputBuffer
'    );

'FUNCTION SpCompleteAuthTokenFn ( _
'   BYVAL ContextHandle AS DWORD _                       ' __in LSA_SEC_HANDLE ContextHandle
' , BYREF InputBuffer AS SecBufferDesc _                 ' __in PSecBufferDesc InputBuffer
' ) AS LONG                                              ' NTSTATUS

'typedef NTSTATUS
'(NTAPI SpFormatCredentialsFn)(
'    IN PSecBuffer Credentials,
'    OUT PSecBuffer FormattedCredentials
'    );

'FUNCTION SpFormatCredentialsFn ( _
'   BYVAL Credentials AS SecBuffer _                     ' __in PSecBuffer Credentials
' , BYREF FormattedCredentials AS SecBuffer _            ' __out PSecBuffer FormattedCredentials
' ) AS LONG                                              ' NTSTATUS

'typedef NTSTATUS
'(NTAPI SpMarshallSupplementalCredsFn)(
'    IN ULONG CredentialSize,
'    IN PUCHAR Credentials,
'    OUT PULONG MarshalledCredSize,
'    OUT PVOID * MarshalledCreds);

'FUNCTION SpMarshallSupplementalCredsFn ( _
'   BYVAL CredentialSize AS DWORD _                      ' __in ULONG CredentialSize
' , BYVAL Credentials AS BYTE PTR _                      ' __in PUCHAR Credentials
' , BYREF MarshalledCredSize AS DWORD _                  ' __out PULONG MarshalledCredSize
' , BYREF MarshalledCreds AS DWORD _                     ' __out PVOID * MarshalledCreds
' ) AS LONG                                              ' NTSTATUS

'typedef struct _SECPKG_USER_FUNCTION_TABLE {
'    SpInstanceInitFn *                      InstanceInit;
'    SpInitUserModeContextFn *               InitUserModeContext;
'    SpMakeSignatureFn *                     MakeSignature;
'    SpVerifySignatureFn *                   VerifySignature;
'    SpSealMessageFn *                       SealMessage;
'    SpUnsealMessageFn *                     UnsealMessage;
'    SpGetContextTokenFn *                   GetContextToken;
'    SpQueryContextAttributesFn *            QueryContextAttributes;
'    SpCompleteAuthTokenFn *                 CompleteAuthToken;
'    SpDeleteContextFn *                     DeleteUserModeContext;
'    SpFormatCredentialsFn *                 FormatCredentials;
'    SpMarshallSupplementalCredsFn *         MarshallSupplementalCreds;
'    SpExportSecurityContextFn *             ExportContext;
'    SpImportSecurityContextFn *             ImportContext;
'} SECPKG_USER_FUNCTION_TABLE, *PSECPKG_USER_FUNCTION_TABLE;

' // Size = 56 bytes
TYPE SECPKG_USER_FUNCTION_TABLE DWORD
   InstanceInit              AS DWORD   ' SpInstanceInitFn *
   InitUserModeContext       AS DWORD   ' SpInitUserModeContextFn *
   MakeSignature             AS DWORD   ' SpMakeSignatureFn *
   VerifySignature           AS DWORD   ' SpVerifySignatureFn *
   SealMessage               AS DWORD   ' SpSealMessageFn *
   UnsealMessage             AS DWORD   ' SpUnsealMessageFn *
   GetContextToken           AS DWORD   ' SpGetContextTokenFn *
   QueryContextAttributes    AS DWORD   ' SpQueryContextAttributesFn *
   CompleteAuthToken         AS DWORD   ' SpCompleteAuthTokenFn *
   DeleteUserModeContext     AS DWORD   ' SpDeleteContextFn *
   FormatCredentials         AS DWORD   ' SpFormatCredentialsFn *
   MarshallSupplementalCreds AS DWORD   ' SpMarshallSupplementalCredsFn *
   ExportContext             AS DWORD   ' SpExportSecurityContextFn *
   ImportContext             AS DWORD   ' SpImportSecurityContextFn *
END TYPE

'typedef NTSTATUS
'(SEC_ENTRY * SpLsaModeInitializeFn)(
'    IN ULONG LsaVersion,
'    OUT PULONG PackageVersion,
'    OUT PSECPKG_FUNCTION_TABLE * ppTables,
'    OUT PULONG pcTables);

'FUNCTION SpLsaModeInitializeFn ( _
'   BYVAL LsaVersion AS DWORD _                          ' __in ULONG LsaVersion
' , BYREF PackageVersion AS DWORD _                      ' __out PULONG PackageVersion
' , BYREF ppTables AS SECPKG_FUNCTION_TABLE _            ' __out PSECPKG_FUNCTION_TABLE * ppTables
' , BYREF pcTables AS DWORD _                            ' __out PULONG pcTables
' ) AS LONG                                              ' NTSTATUS

'typedef NTSTATUS
'(SEC_ENTRY * SpUserModeInitializeFn)(
'    IN ULONG LsaVersion,
'    OUT PULONG PackageVersion,
'    OUT PSECPKG_USER_FUNCTION_TABLE *ppTables,
'    OUT PULONG pcTables
'    );

'FUNCTION SpUserModeInitializeFn ( _
'   BYVAL LsaVersion AS DWORD _                          ' __in ULONG LsaVersion
' , BYREF PackageVersion AS DWORD _                      ' __out PULONG PackageVersion
' , BYREF ppTables AS SECPKG_FUNCTION_TABLE _            ' __out PSECPKG_FUNCTION_TABLE * ppTables
' , BYREF pcTables AS DWORD _                            ' __out PULONG pcTables
' ) AS LONG                                              ' NTSTATUS

$SECPKG_LSAMODEINIT_NAME  = "SpLsaModeInitialize"
$SECPKG_USERMODEINIT_NAME = "SpUserModeInitialize"

'//
'// Version of the security package interface.
'//
'// These defines are used for all of the following:
'//
'// * Passed by the LSA to SpLsaModeInitializeFn to indicate the version of the LSA.
'//      All packages currently expect the LSA to pass SECPKG_INTERFACE_VERSION.
'//
'// * Passed by secur32.dll to SpUserModeInitialzeFn to indicate the version of the secur32 DLL.
'//      All packages currently expect secur32 to pass SECPKG_INTERFACE_VERSION.
'//
'// * Returned from SpLsaModeInitializeFn to indicate the version of SECPKG_FUNCTION_TABLE.
'//      SECPKG_INTERFACE_VERSION indicates all fields through SetExtendedInformation are defined (potentially to NULL)
'//      SECPKG_INTERFACE_VERSION_2 indicates all fields through SetContextAttributes are defined (potentially to NULL)
'//      SECPKG_INTERFACE_VERSION_3 indicates all fields through SetCredentialsAttributes are defined (potentially to NULL)
'//      SECPKG_INTERFACE_VERSION_4 indicates all fields through ChangeAccountPassword are defined (potentially to NULL)
'//      SECPKG_INTERFACE_VERSION_5 indicates all fields through UpdateCredentials are defined (potentially to NULL)
'//      SECPKG_INTERFACE_VERSION_6 indicates all fields through ValidateTargetInfo are defined (potentially to NULL)
'//
'// * Returned from SpUserModeInitializeFn to indicate the version of the auth package.
'//      All packages currently return SECPKG_INTERFACE_VERSION
'//

%SECPKG_INTERFACE_VERSION    = &H00010000???
%SECPKG_INTERFACE_VERSION_2  = &H00020000???
%SECPKG_INTERFACE_VERSION_3  = &H00040000???
%SECPKG_INTERFACE_VERSION_4  = &H00080000???
%SECPKG_INTERFACE_VERSION_5  = &H00100000???
%SECPKG_INTERFACE_VERSION_6  = &H00200000???

' enum KSEC_CONTEXT_TYPE
%KSecPaged    = 0
%KSecNonPaged = 1

' // Size = 24 bytes
TYPE KSEC_LIST_ENTRY DWORD
   List       AS LIST_ENTRY
   RefCount   AS LONG    ' LONG
   Signature  AS DWORD   ' ULONG
   OwningList AS DWORD   ' PVOID
   Reserved   AS DWORD   ' PVOID
END TYPE

'#define KsecInitializeListEntry( Entry, SigValue ) \
'    ((PKSEC_LIST_ENTRY) Entry)->List.Flink = ((PKSEC_LIST_ENTRY) Entry)->List.Blink = NULL; \
'    ((PKSEC_LIST_ENTRY) Entry)->RefCount = 1; \
'    ((PKSEC_LIST_ENTRY) Entry)->Signature = SigValue; \
'    ((PKSEC_LIST_ENTRY) Entry)->OwningList = NULL; \
'    ((PKSEC_LIST_ENTRY) Entry)->Reserved = NULL;

MACRO KsecInitializeListEntry(Entry, SigValue)
   Entry.List.Flink = %NULL
   Entry.List.Blink = %NULL
   Entry.RefCount   = 1
   Entry.Signature  = SigValue
   Entry.OwningList = %NULL
   Entry.Reserved   = %NULL
END MACRO

'typedef PVOID
'(SEC_ENTRY KSEC_CREATE_CONTEXT_LIST)(
'    IN KSEC_CONTEXT_TYPE Type
'    );

'FUNCTION KSEC_CREATE_CONTEXT_LIST ( _
'   BYVAL Type AS LONG _                                 ' __in KSEC_CONTEXT_TYPE Type
' ) AS DWORD                                             ' PVOID

'typedef VOID
'(SEC_ENTRY KSEC_INSERT_LIST_ENTRY)(
'    IN PVOID List,
'    IN PKSEC_LIST_ENTRY Entry
'    );

'SUB KSEC_INSERT_LIST_ENTRY ( _
'   BYVAL List AS DWORD _                                ' __in PVOID List
' , BYREF Entry AS KSEC_LIST_ENTRY _                     ' __in PKSEC_LIST_ENTRY Entry
' )                                                      ' VOID

'typedef NTSTATUS
'(SEC_ENTRY KSEC_REFERENCE_LIST_ENTRY)(
'    IN PKSEC_LIST_ENTRY Entry,
'    IN ULONG Signature,
'    IN BOOLEAN RemoveNoRef
'    );

'FUNCTION KSEC_REFERENCE_LIST_ENTRY ( _
'   BYREF Entry AS KSEC_LIST_ENTRY _                     ' __in PKSEC_LIST_ENTRY Entry
' , BYVAL Signature AS DWORD _                           ' __in ULONG Signature
' , BYVAL RemoveNoRef AS BYTE _                          ' __in BOOLEAN RemoveNoRef
' ) AS LONG                                              ' NTSTATUS

'typedef VOID
'(SEC_ENTRY KSEC_DEREFERENCE_LIST_ENTRY)(
'    IN PKSEC_LIST_ENTRY Entry,
'    OUT BOOLEAN * Delete OPTIONAL
'    );

'SUB KSEC_DEREFERENCE_LIST_ENTRY ( _
'   BYREF Entry AS KSEC_LIST_ENTRY _                     ' __in PKSEC_LIST_ENTRY Entry
' , BYREF bDelete AS BYTE _                              ' __out BOOLEAN * Delete OPTIONAL
' )                                                      ' VOID

'typedef NTSTATUS
'(SEC_ENTRY KSEC_SERIALIZE_WINNT_AUTH_DATA)(
'    __in PVOID pvAuthData,
'    __out PULONG Size,
'    __deref_out PVOID * SerializedData );

'FUNCTION KSEC_SERIALIZE_WINNT_AUTH_DATA ( _
'   BYVAL pvAuthData AS DWORD _                          ' __in PVOID pvAuthData
' , BYREF uSize AS DWORD _                               ' __out PULONG Size
' , BYREF SerializedData AS DWORD _                      ' __out PVOID * SerializedData
' ) AS LONG                                              ' NTSTATUS

'typedef NTSTATUS
'(SEC_ENTRY KSEC_SERIALIZE_SCHANNEL_AUTH_DATA)(
'    __in PVOID pvAuthData,
'    __out PULONG Size,
'    __deref_out PVOID * SerializedData );

'FUNCTION KSEC_SERIALIZE_SCHANNEL_AUTH_DATA ( _
'   BYVAL pvAuthData AS DWORD _                          ' __in PVOID pvAuthData
' , BYREF uSize AS DWORD _                               ' __out PULONG Size
' , BYREF SerializedData AS DWORD _                      ' __out PVOID * SerializedData
' ) AS LONG                                              ' NTSTATUS

'#ifndef MIDL_PASS

'KSEC_CREATE_CONTEXT_LIST KSecCreateContextList;
'KSEC_INSERT_LIST_ENTRY KSecInsertListEntry;
'KSEC_REFERENCE_LIST_ENTRY KSecReferenceListEntry;
'KSEC_DEREFERENCE_LIST_ENTRY KSecDereferenceListEntry;
'KSEC_SERIALIZE_WINNT_AUTH_DATA KSecSerializeWinntAuthData;
'KSEC_SERIALIZE_SCHANNEL_AUTH_DATA KSecSerializeSchannelAuthData;

'#endif // not valid for MIDL_PASS

'typedef KSEC_CREATE_CONTEXT_LIST * PKSEC_CREATE_CONTEXT_LIST;
'typedef KSEC_INSERT_LIST_ENTRY * PKSEC_INSERT_LIST_ENTRY;
'typedef KSEC_REFERENCE_LIST_ENTRY * PKSEC_REFERENCE_LIST_ENTRY;
'typedef KSEC_DEREFERENCE_LIST_ENTRY * PKSEC_DEREFERENCE_LIST_ENTRY;
'typedef KSEC_SERIALIZE_WINNT_AUTH_DATA * PKSEC_SERIALIZE_WINNT_AUTH_DATA;
'typedef KSEC_SERIALIZE_SCHANNEL_AUTH_DATA * PKSEC_SERIALIZE_SCHANNEL_AUTH_DATA;

'typedef PVOID
'(SEC_ENTRY KSEC_LOCATE_PKG_BY_ID)(
'    __in ULONG PackageId
'    );

'SUB KSEC_LOCATE_PKG_BY_ID ( _
'   BYVAL PackageId AS DWORD _                           ' __in ULONG PackageId
' )                                                      ' VOID

'typedef KSEC_LOCATE_PKG_BY_ID * PKSEC_LOCATE_PKG_BY_ID;

'#ifndef MIDL_PASS

'KSEC_LOCATE_PKG_BY_ID KSecLocatePackageById;

'#endif // not valid for MIDL_PASS

' // Size = 36 bytes
TYPE SECPKG_KERNEL_FUNCTIONS DWORD
   AllocateHeap              AS DWORD   ' PLSA_ALLOCATE_LSA_HEAP
   FreeHeap                  AS DWORD   ' PLSA_FREE_LSA_HEAP
   CreateContextList         AS DWORD   ' PKSEC_CREATE_CONTEXT_LIST
   InsertListEntry           AS DWORD   ' PKSEC_INSERT_LIST_ENTRY
   ReferenceListEntry        AS DWORD   ' PKSEC_REFERENCE_LIST_ENTRY
   DereferenceListEntry      AS DWORD   ' PKSEC_DEREFERENCE_LIST_ENTRY
   SerializeWinntAuthData    AS DWORD   ' PKSEC_SERIALIZE_WINNT_AUTH_DATA
   SerializeSchannelAuthData AS DWORD   ' PKSEC_SERIALIZE_SCHANNEL_AUTH_DATA
   LocatePackageById         AS DWORD   ' PKSEC_LOCATE_PKG_BY_ID
END TYPE

'typedef NTSTATUS
'(NTAPI KspInitPackageFn)(
'    PSECPKG_KERNEL_FUNCTIONS    FunctionTable
'    );

'FUNCTION KspInitPackageFn ( _
'   BYREF FunctionTable AS SECPKG_KERNEL_FUNCTIONS _     ' PSECPKG_KERNEL_FUNCTIONS FunctionTable
' ) AS LONG                                              ' NTSTATUS

'typedef NTSTATUS
'(NTAPI KspDeleteContextFn)(
'    IN LSA_SEC_HANDLE ContextId,
'    OUT PLSA_SEC_HANDLE LsaContextId
'    );

'FUNCTION KspDeleteContextFn ( _
'   BYVAL ContextId AS DWORD _                           ' __in LSA_SEC_HANDLE ContextId
' , BYREF LsaContextId AS DWORD _                        ' __out PLSA_SEC_HANDLE LsaContextId
' ) AS LONG                                              ' NTSTATUS

'typedef NTSTATUS
'(NTAPI KspInitContextFn)(
'    IN LSA_SEC_HANDLE ContextId,
'    IN PSecBuffer ContextData,
'    OUT PLSA_SEC_HANDLE NewContextId
'    );

'FUNCTION KspInitContextFn ( _
'   BYVAL ContextId AS DWORD _                           ' __in LSA_SEC_HANDLE ContextId
' , BYREF ContextData AS SecBuffer _                     ' __in PSecBuffer ContextData
' , BYREF NewContextId AS DWORD _                        ' __out PLSA_SEC_HANDLE NewContextId
' ) AS LONG                                              ' NTSTATUS

'typedef NTSTATUS
'(NTAPI KspMakeSignatureFn)(
'    IN LSA_SEC_HANDLE ContextId,
'    IN ULONG fQOP,
'    IN OUT PSecBufferDesc Message,
'    IN ULONG MessageSeqNo
'    );

'FUNCTION KspMakeSignatureFn ( _
'   BYVAL ContextId AS DWORD _                           ' __in LSA_SEC_HANDLE ContextId
' , BYVAL fQOP AS DWORD _                                ' __in ULONG fQOP
' , BYREF Message AS SecBufferDesc _                     ' __inout PSecBufferDesc Message
' , BYVAL MessageSeqNo AS DWORD _                        ' __in ULONG MessageSeqNo
' ) AS LONG                                              ' NTSTATUS

'typedef NTSTATUS
'(NTAPI KspVerifySignatureFn)(
'    IN LSA_SEC_HANDLE ContextId,
'    IN OUT PSecBufferDesc Message,
'    IN ULONG MessageSeqNo,
'    OUT PULONG pfQOP
'    );

'FUNCTION KspVerifySignatureFn ( _
'   BYVAL ContextId AS DWORD _                           ' __in LSA_SEC_HANDLE ContextId
' , BYREF Message AS SecBufferDesc _                     ' __inout PSecBufferDesc Message
' , BYVAL MessageSeqNo AS DWORD _                        ' __in ULONG MessageSeqNo
' , BYREF pfQOP AS DWORD _                               ' __out ULONG pfQOP
' ) AS LONG                                              ' NTSTATUS

'typedef NTSTATUS
'(NTAPI KspSealMessageFn)(
'    IN LSA_SEC_HANDLE ContextId,
'    IN ULONG fQOP,
'    IN OUT PSecBufferDesc Message,
'    IN ULONG MessageSeqNo
'    );

'FUNCTION KspSealMessageFn ( _
'   BYVAL ContextId AS DWORD _                           ' __in LSA_SEC_HANDLE ContextId
' , BYVAL fQOP AS DWORD _                                ' __in ULONG fQOP
' , BYREF Message AS SecBufferDesc _                     ' __inout PSecBufferDesc Message
' , BYVAL MessageSeqNo AS DWORD _                        ' __in ULONG MessageSeqNo
' ) AS LONG                                              ' NTSTATUS

'typedef NTSTATUS
'(NTAPI KspUnsealMessageFn)(
'    IN LSA_SEC_HANDLE ContextId,
'    IN OUT PSecBufferDesc Message,
'    IN ULONG MessageSeqNo,
'    OUT PULONG pfQOP
'    );

'FUNCTION KspUnsealMessageFn ( _
'   BYVAL ContextId AS DWORD _                           ' __in LSA_SEC_HANDLE ContextId
' , BYREF Message AS SecBufferDesc _                     ' __inout PSecBufferDesc Message
' , BYVAL MessageSeqNo AS DWORD _                        ' __in ULONG MessageSeqNo
' , BYREF pfQOP AS DWORD _                               ' __out ULONG pfQOP
' ) AS LONG                                              ' NTSTATUS

'typedef NTSTATUS
'(NTAPI KspGetTokenFn)(
'    IN LSA_SEC_HANDLE ContextId,
'    OUT PHANDLE ImpersonationToken,
'    OUT OPTIONAL PACCESS_TOKEN * RawToken
'    );

'FUNCTION KspGetTokenFn ( _
'   BYVAL ContextId AS DWORD _                           ' __in LSA_SEC_HANDLE ContextId
' , BYREF ImpersonationToken AS DWORD _                  ' __out PHANDLE ImpersonationToken
' , BYREF RawToken AS DWORD _                            ' __out_opt PACCESS_TOKEN * RawToken
' ) AS LONG                                              ' NTSTATUS

'typedef NTSTATUS
'(NTAPI KspQueryAttributesFn)(
'    IN LSA_SEC_HANDLE ContextId,
'    IN ULONG Attribute,
'    IN OUT PVOID Buffer
'    );

'FUNCTION KspQueryAttributesFn ( _
'   BYVAL ContextId AS DWORD _                           ' __in LSA_SEC_HANDLE ContextId
' , BYVAL Attribute AS DWORD _                           ' __in ULONG Attribute
' , BYVAL Buffer AS DWORD _                              ' __inout PVOID Buffer
' ) AS LONG                                              ' NTSTATUS

'typedef NTSTATUS
'(NTAPI KspCompleteTokenFn)(
'    IN LSA_SEC_HANDLE ContextId,
'    IN PSecBufferDesc Token
'    );

'FUNCTION KspCompleteTokenFn ( _
'   BYVAL ContextId AS DWORD _                           ' __in LSA_SEC_HANDLE ContextId
' , BYREF Token AS SecBufferDesc _                       ' __in PSecBufferDesc Token
' ) AS LONG                                              ' NTSTATUS

'typedef NTSTATUS
'(NTAPI KspMapHandleFn)(
'    IN LSA_SEC_HANDLE ContextId,
'    OUT PLSA_SEC_HANDLE LsaContextId
'    );

'FUNCTION KspMapHandleFn ( _
'   BYVAL ContextId AS DWORD _                           ' __in LSA_SEC_HANDLE ContextId
' , BYREF LsaContextId AS DWORD _                        ' __out PLSA_SEC_HANDLE LsaContextId
' ) AS LONG                                              ' NTSTATUS

'typedef NTSTATUS
'(NTAPI KspSetPagingModeFn)(
'    IN BOOLEAN PagingMode
'    );

'FUNCTION KspSetPagingModeFn ( _
'   BYVAL PagingMode AS BYTE _                           ? __in BOOLEAN PagingMode
' ) AS LONG                                              ' NTSTATUS

'typedef NTSTATUS
'(NTAPI KspSerializeAuthDataFn)(
'    IN PVOID pvAuthData,
'    OUT PULONG Size,
'    OUT PVOID * SerializedData
'    );

'FUNCTION KspSerializeAuthDataFn ( _
'   BYVAL pvAuthData AS DWORD _                          ' __in PVOID pvAuthData
' , BYREF dwSize AS DWORD _                              ' __out PULONG Size
' , BYREF SerializedData AS DWORD _                      ' __out PVOID * SerializedData
' ) AS LONG                                              ' NTSTATUS

' // Size = 60 bytes
TYPE SECPKG_KERNEL_FUNCTION_TABLE DWORD
   Initialize           AS DWORD   ' KspInitPackageFn *
   DeleteContext        AS DWORD   ' KspDeleteContextFn *
   InitContext          AS DWORD   ' KspInitContextFn *
   MapHandle            AS DWORD   ' KspMapHandleFn *
   Sign                 AS DWORD   ' KspMakeSignatureFn *
   Verify               AS DWORD   ' KspVerifySignatureFn *
   Seal                 AS DWORD   ' KspSealMessageFn *
   Unseal               AS DWORD   ' KspUnsealMessageFn *
   GetToken             AS DWORD   ' KspGetTokenFn *
   QueryAttributes      AS DWORD   ' KspQueryAttributesFn *
   CompleteToken        AS DWORD   ' KspCompleteTokenFn *
   ExportContext        AS DWORD   ' SpExportSecurityContextFn *
   ImportContext        AS DWORD   ' SpImportSecurityContextFn *
   SetPackagePagingMode AS DWORD   ' KspSetPagingModeFn *
   SerializeAuthData    AS DWORD   ' KspSerializeAuthDataFn *
END TYPE

'SECURITY_STATUS
'SEC_ENTRY
'KSecRegisterSecurityProvider(
'    __in PSECURITY_STRING    ProviderName,
'    __in PSECPKG_KERNEL_FUNCTION_TABLE Table
'    );

' Undocumented
'DECLARE FUNCTION KSecRegisterSecurityProvider ( _
'   BYREF ProviderName AS SECURITY_STRING _              ' __in PSECURITY_STRING ProviderName,
' , BYVAL Table AS DWORD _                               ' __in PSECPKG_KERNEL_FUNCTION_TABLE Table
' ) AS LONG                                              ' SECURITY_STATUS

'extern SECPKG_KERNEL_FUNCTIONS KspKernelFunctions;
