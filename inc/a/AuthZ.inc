' ########################################################################################
' Microsoft Windows
' File: authz.inc
' Contents: Authorization framework APIs
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%AUTHZ_INC = 1

#INCLUDE ONCE "windows.inc"
#INCLUDE ONCE "adtgen.inc"

'//
'// Flags which may be used at the time of client context creation using a sid.
'//

%AUTHZ_SKIP_TOKEN_GROUPS  = &H2
%AUTHZ_REQUIRE_S4U_LOGON  = &H4
%AUTHZ_COMPUTE_PRIVILEGES = &H8

'DECLARE_HANDLE(AUTHZ_ACCESS_CHECK_RESULTS_HANDLE);
'DECLARE_HANDLE(AUTHZ_CLIENT_CONTEXT_HANDLE);
'DECLARE_HANDLE(AUTHZ_RESOURCE_MANAGER_HANDLE);
'DECLARE_HANDLE(AUTHZ_AUDIT_EVENT_HANDLE);
'DECLARE_HANDLE(AUTHZ_AUDIT_EVENT_TYPE_HANDLE);
'DECLARE_HANDLE(AUTHZ_SECURITY_EVENT_PROVIDER_HANDLE);

'typedef AUTHZ_ACCESS_CHECK_RESULTS_HANDLE    *PAUTHZ_ACCESS_CHECK_RESULTS_HANDLE;
'typedef AUTHZ_CLIENT_CONTEXT_HANDLE          *PAUTHZ_CLIENT_CONTEXT_HANDLE;
'typedef AUTHZ_RESOURCE_MANAGER_HANDLE        *PAUTHZ_RESOURCE_MANAGER_HANDLE;
'typedef AUTHZ_AUDIT_EVENT_HANDLE             *PAUTHZ_AUDIT_EVENT_HANDLE;
'typedef AUTHZ_AUDIT_EVENT_TYPE_HANDLE        *PAUTHZ_AUDIT_EVENT_TYPE_HANDLE;
'typedef AUTHZ_SECURITY_EVENT_PROVIDER_HANDLE *PAUTHZ_SECURITY_EVENT_PROVIDER_HANDLE;

'//
'// Structure defining the access check request.
'//

' // Size = 20 bytes
TYPE AUTHZ_ACCESS_REQUEST DWORD
   DesiredAccess        AS ACCESS_MASK            ' ACCESS_MASK
   PrincipalSelfSid     AS SID PTR                ' PSID
   ObjectTypeList       AS OBJECT_TYPE_LIST PTR   ' POBJECT_TYPE_LIST
   ObjectTypeListLength AS DWORD                  ' DWORD
   OptionalArguments    AS DWORD                  ' PVOID
END TYPE

'//
'// Structure to return the results of the access check call.
'//

%AUTHZ_GENERATE_SUCCESS_AUDIT = &H1
%AUTHZ_GENERATE_FAILURE_AUDIT = &H2

' // Size = 16 bytes
TYPE AUTHZ_ACCESS_REPLY DWORD
   ResultListLength      AS DWORD             ' DWORD
   GrantedAccessMask     AS ACCESS_MASK PTR   ' PACCESS_MASK
   SaclEvaluationResults AS DWORD PTR         ' PDWORD OPTIONAL
   Error                 AS DWORD PTR         ' PDWORD
END TYPE


'//
'// Typedefs for callback functions to be provided by the resource manager.
'//

'//
'// Callback access check function takes in
'//     AuthzClientContext - a client context
'//     pAce - pointer to a callback ace
'//     pArgs - Optional arguments that were passed to AuthzAccessCheck thru
'//             AuthzAccessRequest->OptionalArguments are passed back here.
'//     pbAceApplicable - The resource manager must supply whether the ace should
'//         be used in the computation of access evaluation
'//
'// Returns
'//     TRUE if the API succeeded.
'//     FALSE on any intermediate errors (like failed memory allocation)
'//         In case of failure, the caller must use SetLastError(ErrorValue).
'//

'typedef BOOL (CALLBACK *PFN_AUTHZ_DYNAMIC_ACCESS_CHECK) (
'                  IN AUTHZ_CLIENT_CONTEXT_HANDLE hAuthzClientContext,
'                  IN PACE_HEADER                 pAce,
'                  IN PVOID                       pArgs                OPTIONAL,
'                  IN OUT PBOOL                   pbAceApplicable
'                  );

'FUNCTION FN_AUTHZ_DYNAMIC_ACCESS_CHECK ( _
'   BYVAL DWORD _                              ' IN AUTHZ_CLIENT_CONTEXT_HANDLE hAuthzClientContext
' , BYVAL DWORD _                              ' IN PACE_HEADER                 pAce
' , BYVAL DWORD _                              ' IN PVOID                       pArgs                OPTIONAL
' , BYREF LONG _                               ' IN OUT PBOOL                   pbAceApplicable
' ) AS LONG                                    ' BOOL

'//
'// Callback compute dynamic groups function takes in
'//     AuthzClientContext - a client context
'//     pArgs - Optional arguments that supplied to AuthzInitializeClientContext*
'//         thru DynamicGroupArgs are passed back here..
'//     pSidAttrArray - To allocate and return an array of (sids, attribute)
'//         pairs to be added to the normal part of the client context.
'//     pSidCount - Number of elements in pSidAttrArray
'//     pRestrictedSidAttrArray - To allocate and return an array of (sids, attribute)
'//         pairs to be added to the restricted part of the client context.
'//     pRestrictedSidCount - Number of elements in pRestrictedSidAttrArray
'//
'// Note:
'//    Memory returned thru both these array will be freed by the callback
'//    free function defined by the resource manager.
'//
'// Returns
'//     TRUE if the API succeeded.
'//     FALSE on any intermediate errors (like failed memory allocation)
'//         In case of failure, the caller must use SetLastError(ErrorValue).
'//

'typedef BOOL (CALLBACK *PFN_AUTHZ_COMPUTE_DYNAMIC_GROUPS) (
'                  IN  AUTHZ_CLIENT_CONTEXT_HANDLE hAuthzClientContext,
'                  IN  PVOID                       Args,
'                  OUT PSID_AND_ATTRIBUTES         *pSidAttrArray,
'                  OUT PDWORD                      pSidCount,
'                  OUT PSID_AND_ATTRIBUTES         *pRestrictedSidAttrArray,
'                  OUT PDWORD                      pRestrictedSidCount
'                  );

'FUNCTION FN_AUTHZ_COMPUTE_DYNAMIC_GROUPS ( _
'   BYVAL DWORD _                              ' IN  AUTHZ_CLIENT_CONTEXT_HANDLE hAuthzClientContext
' , BYVAL DWORD _                              ' IN  PVOID                       Args
' , BYREF SID_AND_ATTRIBUTES _                 ' OUT PSID_AND_ATTRIBUTES         *pSidAttrArray
' , BYREF DWORD _                              ' OUT PDWORD                      pSidCount
' , BYREF SID_AND_ATTRIBUTES _                 ' OUT PSID_AND_ATTRIBUTES         *pRestrictedSidAttrArray
' , BYREF DWORD _                              ' OUT PDWORD                      pRestrictedSidCount
' ) AS LONG                                    ' BOOL

'//
'// Callback free function takes in
'//     pSidAttrArray - To be freed. This has been allocated by the compute
'//     dynamic groups function.
'//

'typedef VOID (CALLBACK *PFN_AUTHZ_FREE_DYNAMIC_GROUPS) (
'                  IN PSID_AND_ATTRIBUTES pSidAttrArray
'                  );

'SUB FN_AUTHZ_FREE_DYNAMIC_GROUPS ( _
'   BYREF SID_AND_ATTRIBUTES _                 ' IN PSID_AND_ATTRIBUTES pSidAttrArray
' )                                            ' VOID

'//
'//  BEGIN: *** (Subject) Security attributes ***
'//
'//  WARNING!!!:
'//      These #defines and data structures exactly mirror
'//      the TOKEN_XXX definitions in ntseapi.w. Keep them
'//      in sync.
'//


'//
'//  Security attribute data types ...
'//

%AUTHZ_SECURITY_ATTRIBUTE_TYPE_INVALID   = &H00

%AUTHZ_SECURITY_ATTRIBUTE_TYPE_INT64     = &H01
%AUTHZ_SECURITY_ATTRIBUTE_TYPE_UINT64    = &H02

'//
'//  Case insensitive attribute value string by default.
'//  Unless the flag AUTHZ_SECURITY_ATTRIBUTE_VALUE_CASE_SENSITIVE
'//  is set indicating otherwise.
'//

%AUTHZ_SECURITY_ATTRIBUTE_TYPE_STRING    = &H03

'//
'//  Fully-qualified binary name.
'//

' // Size = 16 bytes - must be 8 bytes aligned
TYPE AUTHZ_SECURITY_ATTRIBUTE_FQBN_VALUE QWORD
   Version AS QUAD           ' ULONG64
   pName   AS WSTRINGZ PTR   ' PWSTR
END TYPE

%AUTHZ_SECURITY_ATTRIBUTE_TYPE_FQBN      = &H04

'//
'//  This is the 'catch all' type. The attribute manipulation
'//  code really doesn't care about the actual format of the
'//  value. Value subtypes are defined only for this type.
'//  Value subtypes permit easy addition of new subtypes
'//  without having to change the attribute manipulation
'//  (and WOW64 thunking!) code.
'//

' // Size = 8 bytes
TYPE AUTHZ_SECURITY_ATTRIBUTE_OCTET_STRING_VALUE DWORD
   pValue      AS DWORD   ' PVOID //  Pointer is BYTE aligned.
   ValueLength AS DWORD   ' ULONG    //  In bytes
END TYPE

%AUTHZ_SECURITY_ATTRIBUTE_TYPE_OCTET_STRING  = &H10

'//
'//  Attribute operations that can be specified for a 'set' API:
'//


'typedef enum {

'    //
'    //  No-op
'    //

'    AUTHZ_SECURITY_ATTRIBUTE_OPERATION_NONE = 0,

'    //
'    //  Delete all existing security attributes and their values in
'    //  the NT token and replace it with the specified attributes/values.
'    //  If attributes to replace with are not specified, all existing
'    //  attributes and values are deleted.
'    //
'    //  This operation can be specified at most once and must be the
'    //  only operation specified.
'    //

'    AUTHZ_SECURITY_ATTRIBUTE_OPERATION_REPLACE_ALL,

'    //
'    //  Add a new attribute or a new value to an existing attribute.
'    //  If the value specified for any attribute already exists for
'    //  that attribute, the call fails.
'    //

'    AUTHZ_SECURITY_ATTRIBUTE_OPERATION_ADD,

'    //
'    //  Delete the specified value(s) of the specified attribute(s).
'    //  If the last value is deleted from an attribute, the attribute
'    //  itself is removed. If no matching attribute name was found, no
'    //  modifications are done and the call fails. If no value is specified
'    //  for the attribute, the attribute itself will be deleted.
'    //

'    AUTHZ_SECURITY_ATTRIBUTE_OPERATION_DELETE,

'    //
'    //  The value(s) of the specified security attribute(s) completely
'    //  replace(s) the existing value(s) of the attribute(s). If the
'    //  attribute does not already exist, it is added.  When no value
'    //  is specified, the attribute is deleted, if it exists; otherwise,
'    //  the operation is simply ignored and no failure is reported.
'    //

'    AUTHZ_SECURITY_ATTRIBUTE_OPERATION_REPLACE
'} AUTHZ_SECURITY_ATTRIBUTE_OPERATION, *PAUTHZ_SECURITY_ATTRIBUTE_OPERATION;

%AUTHZ_SECURITY_ATTRIBUTE_OPERATION_NONE        = 0
%AUTHZ_SECURITY_ATTRIBUTE_OPERATION_REPLACE_ALL = 1
%AUTHZ_SECURITY_ATTRIBUTE_OPERATION_ADD         = 2
%AUTHZ_SECURITY_ATTRIBUTE_OPERATION_DELETE      = 3
%AUTHZ_SECURITY_ATTRIBUTE_OPERATION_REPLACE     = 4

'//
'//  An individual security attribute.
'//

'typedef struct _AUTHZ_SECURITY_ATTRIBUTE_V1 {

'    //
'    //  Name of the attribute.
'    //  Case insensitive Windows Unicode string.
'    //

'    PWSTR   pName;

'    //
'    //  Data type of attribute.
'    //

'    USHORT  ValueType;

'    //
'    //  Pass 0 in a set operation and check for 0 in
'    //  a get operation.
'    //

'    USHORT  Reserved;

'//
'//  Attribute must not be inherited across process spawns.
'//

'#define AUTHZ_SECURITY_ATTRIBUTE_NON_INHERITABLE      0x0001


'//
'//  Attribute value is compared in a case sensitive way. It is valid with string value
'//  or composite type containing string value. For other types of value, this flag
'//  will be ignored. Currently, it is valid with the two types:
'//  AUTHZ_SECURITY_ATTRIBUTE_TYPE_STRING and AUTHZ_SECURITY_ATTRIBUTE_TYPE_FQBN.
'//
'#define AUTHZ_SECURITY_ATTRIBUTE_VALUE_CASE_SENSITIVE         0x0002

'#define AUTHZ_SECURITY_ATTRIBUTE_VALID_FLAGS   (    \
'                        AUTHZ_SECURITY_ATTRIBUTE_NON_INHERITABLE |  \
'                        AUTHZ_SECURITY_ATTRIBUTE_VALUE_CASE_SENSITIVE     \
'                        )

'    ULONG   Flags;

'    //
'    //  Number of values.
'    //

'    ULONG   ValueCount;

'    //
'    //  The actual value itself.
'    //

'    union {
'        PLONG64                                         pInt64;
'        PULONG64                                        pUint64;
'        PWSTR                                           *ppString;
'        PAUTHZ_SECURITY_ATTRIBUTE_FQBN_VALUE            pFqbn;
'        PAUTHZ_SECURITY_ATTRIBUTE_OCTET_STRING_VALUE    pOctetString;
'    } Values;
'} AUTHZ_SECURITY_ATTRIBUTE_V1, *PAUTHZ_SECURITY_ATTRIBUTE_V1;

%AUTHZ_SECURITY_ATTRIBUTE_NON_INHERITABLE = &H0001???
%AUTHZ_SECURITY_ATTRIBUTE_VALUE_CASE_SENSITIVE = &H0002???
%AUTHZ_SECURITY_ATTRIBUTE_VALID_FLAGS = %AUTHZ_SECURITY_ATTRIBUTE_NON_INHERITABLE OR %AUTHZ_SECURITY_ATTRIBUTE_VALUE_CASE_SENSITIVE

' // Size = 4 bytes
UNION AUTHZ_SECURITY_ATTRIBUTE_V1_Values DWORD
   pInt64       AS QUAD PTR                                          ' PLONG64
   pUint64      AS QUAD PTR                                          ' PULONG64
   ppString     AS WSTRINGZ PTR                                      ' PWSTR*
   pFqbn        AS AUTHZ_SECURITY_ATTRIBUTE_FQBN_VALUE PTR           ' PAUTHZ_SECURITY_ATTRIBUTE_FQBN_VALUE
   pOctetString AS AUTHZ_SECURITY_ATTRIBUTE_OCTET_STRING_VALUE PTR   ' PAUTHZ_SECURITY_ATTRIBUTE_OCTET_STRING_VALUE
END UNION

' // Size = 20 bytes
TYPE AUTHZ_SECURITY_ATTRIBUTE_V1 DWORD FILL
   pName      AS WSTRINGZ PTR   ' PWSTR
   ValueType  AS WORD           ' USHORT
   Reserved   AS WORD           ' USHORT
   Flags      AS DWORD          ' ULONG
   ValueCount AS DWORD          ' ULONG
   Values     AS AUTHZ_SECURITY_ATTRIBUTE_V1_Values
END TYPE


'//
'//  Set of security attributes.
'//

'typedef struct _AUTHZ_SECURITY_ATTRIBUTES_INFORMATION {

'    //
'    //  Versioning. The interpretation of the pointers in the
'    //  Attribute field below is dependent on the version field.
'    //
'    //  Get operations return the version while the set operation
'    //  MUST specify the version of the data structure passed in.
'    //

'#define AUTHZ_SECURITY_ATTRIBUTES_INFORMATION_VERSION_V1    1

'#define AUTHZ_SECURITY_ATTRIBUTES_INFORMATION_VERSION       \
'    AUTHZ_SECURITY_ATTRIBUTES_INFORMATION_VERSION_V1

'    //
'    //  MUST BE first.
'    //

'    USHORT  Version;

'    //
'    //  Pass 0 in set operations and ignore on get operations.
'    //

'    USHORT  Reserved;

'    ULONG   AttributeCount;
'    union {
'        PAUTHZ_SECURITY_ATTRIBUTE_V1    pAttributeV1;
'    } Attribute;
'} AUTHZ_SECURITY_ATTRIBUTES_INFORMATION,
'    *PAUTHZ_SECURITY_ATTRIBUTES_INFORMATION;

%AUTHZ_SECURITY_ATTRIBUTES_INFORMATION_VERSION_V1 = 1
%AUTHZ_SECURITY_ATTRIBUTES_INFORMATION_VERSION    = %AUTHZ_SECURITY_ATTRIBUTES_INFORMATION_VERSION_V1

' // Size = 4 bytes
UNION AUTHZ_SECURITY_ATTRIBUTES_INFORMATION_Attribute DWORD
   pAttributeV1 AS AUTHZ_SECURITY_ATTRIBUTE_V1 PTR
END UNION

' // Size = 12 bytes
TYPE AUTHZ_SECURITY_ATTRIBUTES_INFORMATION DWORD FILL
   Version        AS WORD    ' USHORT
   Reserved       AS WORD    ' USHORT
   AttributeCount AS DWORD   ' ULONG
   Attribute      AS AUTHZ_SECURITY_ATTRIBUTES_INFORMATION_Attribute
END TYPE

'//
'// Valid flags for AuthzAccessCheck
'//

%AUTHZ_ACCESS_CHECK_NO_DEEP_COPY_SD = &H00000001???

DECLARE FUNCTION AuthzAccessCheck IMPORT "Authz.dll" ALIAS "AuthzAccessCheck" ( _
   BYVAL Flags AS DWORD _                               ' __in     DWORD                              Flags
 , BYVAL hAuthzClientContext AS DWORD _                 ' __in     AUTHZ_CLIENT_CONTEXT_HANDLE        hAuthzClientContext
 , BYREF AUTHZ_ACCESS_REQUEST _                         ' __in     PAUTHZ_ACCESS_REQUEST              pRequest
 , BYVAL pRequest AS DWORD _                            ' __in     AUTHZ_AUDIT_EVENT_HANDLE           hAuditEvent                      OPTIONAL
 , BYREF pSecurityDescriptor AS SECURITY_DESCRIPTOR _   ' __in     PSECURITY_DESCRIPTOR               pSecurityDescriptor
 , BYREF OptionalSecurityDescriptorArray AS SECURITY_DESCRIPTOR _ ' __in     PSECURITY_DESCRIPTOR               *OptionalSecurityDescriptorArray OPTIONAL
 , BYVAL OptionalSecurityDescriptorCount AS DWORD _     ' __in     DWORD                              OptionalSecurityDescriptorCount
 , BYREF pReply AS AUTHZ_ACCESS_REPLY _                 ' __in_out PAUTHZ_ACCESS_REPLY                pReply
 , BYREF phAccessCheckResults AS DWORD _                ' __out    PAUTHZ_ACCESS_CHECK_RESULTS_HANDLE phAccessCheckResults             OPTIONAL
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION AuthzCachedAccessCheck IMPORT "Authz.dll" ALIAS "AuthzCachedAccessCheck" ( _
   BYVAL Flags AS DWORD _                               ' __in     DWORD                             Flags
 , BYVAL hAccessCheckResults AS DWORD _                 ' __in     AUTHZ_ACCESS_CHECK_RESULTS_HANDLE hAccessCheckResults
 , BYREF pRequest AS AUTHZ_ACCESS_REQUEST _             ' __in     PAUTHZ_ACCESS_REQUEST             pRequest
 , BYVAL hAuditEvent AS DWORD _                         ' __in     AUTHZ_AUDIT_EVENT_HANDLE          hAuditEvent          OPTIONAL
 , BYREF hAuditEvent AS AUTHZ_ACCESS_REPLY _            ' __in_out PAUTHZ_ACCESS_REPLY               pReply
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION AuthzOpenObjectAudit IMPORT "Authz.dll" ALIAS "AuthzOpenObjectAudit" ( _
   BYVAL Flags AS DWORD _                               ' __in DWORD                       Flags
 , BYVAL hAuthzClientContext AS DWORD _                 ' __in AUTHZ_CLIENT_CONTEXT_HANDLE hAuthzClientContext
 , BYREF pRequest AS AUTHZ_ACCESS_REQUEST _             ' __in PAUTHZ_ACCESS_REQUEST       pRequest
 , BYVAL pRequest AS DWORD _                            ' __in AUTHZ_AUDIT_EVENT_HANDLE    hAuditEvent
 , BYREF pSecurityDescriptor AS SECURITY_DESCRIPTOR _   ' __in PSECURITY_DESCRIPTOR        pSecurityDescriptor
 , BYREF OptionalSecurityDescriptorArray AS SECURITY_DESCRIPTOR _ ' __in PSECURITY_DESCRIPTOR        *OptionalSecurityDescriptorArray OPTIONAL
 , BYVAL OptionalSecurityDescriptorCount AS DWORD _     ' __in DWORD                       OptionalSecurityDescriptorCount
 , BYREF pReply AS AUTHZ_ACCESS_REPLY _                 ' __in PAUTHZ_ACCESS_REPLY         pReply
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION AuthzFreeHandle IMPORT "Authz.dll" ALIAS "AuthzFreeHandle" ( _
   BYVAL hAccessCheckResults AS DWORD _                 ' __in AUTHZ_ACCESS_CHECK_RESULTS_HANDLE hAccessCheckResults
 ) AS LONG                                              ' BOOL

'//
'// Flags for AuthzInitializeResourceManager
'//

%AUTHZ_RM_FLAG_NO_AUDIT = &H1
%AUTHZ_RM_FLAG_INITIALIZE_UNDER_IMPERSONATION = &H2
%AUTHZ_VALID_RM_INIT_FLAGS = %AUTHZ_RM_FLAG_NO_AUDIT OR %AUTHZ_RM_FLAG_INITIALIZE_UNDER_IMPERSONATION

DECLARE FUNCTION AuthzInitializeResourceManager IMPORT "Authz.dll" ALIAS "AuthzInitializeResourceManager" ( _
   BYVAL Flags AS DWORD _                               ' __in  DWORD                            Flags
 , BYVAL pfnDynamicAccessCheck AS DWORD _               ' __in  PFN_AUTHZ_DYNAMIC_ACCESS_CHECK   pfnDynamicAccessCheck   OPTIONAL
 , BYVAL pfnComputeDynamicGroups AS DWORD _             ' __in  PFN_AUTHZ_COMPUTE_DYNAMIC_GROUPS pfnComputeDynamicGroups OPTIONAL
 , BYVAL pfnFreeDynamicGroups AS DWORD _                ' __in  PFN_AUTHZ_FREE_DYNAMIC_GROUPS    pfnFreeDynamicGroups    OPTIONAL
 , BYREF szResourceManagerName AS WSTRINGZ _            ' __in  PCWSTR                           szResourceManagerName
 , BYREF phAuthzResourceManager AS DWORD _              ' __out PAUTHZ_RESOURCE_MANAGER_HANDLE  phAuthzResourceManager
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION AuthzFreeResourceManager IMPORT "Authz.dll" ALIAS "AuthzFreeResourceManager" ( _
   BYVAL hAuthzResourceManager AS DWORD _               ' __in AUTHZ_RESOURCE_MANAGER_HANDLE hAuthzResourceManager
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION AuthzInitializeContextFromToken IMPORT "Authz.dll" ALIAS "AuthzInitializeContextFromToken" ( _
   BYVAL Flags AS DWORD _                               ' __in  DWORD                         Flags
 , BYVAL TokenHandle AS DWORD _                         ' __in  HANDLE                        TokenHandle
 , BYVAL hAuthzResourceManager AS DWORD _               ' __in  AUTHZ_RESOURCE_MANAGER_HANDLE hAuthzResourceManager
 , BYREF pExpirationTime AS ANY _                       ' __in  PLARGE_INTEGER                pExpirationTime        OPTIONAL
 , BYVAL Identifier AS QUAD _                           ' __in  LUID                          Identifier
 , BYVAL DynamicGroupArgs AS DWORD _                    ' __in  PVOID                         DynamicGroupArgs       OPTIONAL
 , BYREF phAuthzClientContext AS DWORD _                ' __out PAUTHZ_CLIENT_CONTEXT_HANDLE  phAuthzClientContext
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION AuthzInitializeContextFromSid IMPORT "Authz.dll" ALIAS "AuthzInitializeContextFromSid" ( _
   BYVAL Flags AS DWORD _                               ' __in  DWORD                         Flags
 , BYVAL UserSid AS SID PTR _                           ' __in  PSID                          UserSid
 , BYVAL hAuthzResourceManager AS DWORD _               ' __in  AUTHZ_RESOURCE_MANAGER_HANDLE hAuthzResourceManager
 , BYREF pExpirationTime AS ANY _                       ' __in  PLARGE_INTEGER                pExpirationTime        OPTIONAL
 , BYVAL Identifier AS QUAD _                           ' __in  LUID                          Identifier
 , BYVAL DynamicGroupArgs AS DWORD _                    ' __in  PVOID                         DynamicGroupArgs       OPTIONAL
 , BYREF phAuthzClientContext AS DWORD _                ' __out PAUTHZ_CLIENT_CONTEXT_HANDLE  phAuthzClientContext
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION AuthzInitializeContextFromAuthzContext IMPORT "Authz.dll" ALIAS "AuthzInitializeContextFromAuthzContext" ( _
   BYVAL Flags AS DWORD _                               ' __in  DWORD                        Flags
 , BYVAL hAuthzClientContext AS DWORD _                 ' __in  AUTHZ_CLIENT_CONTEXT_HANDLE  hAuthzClientContext
 , BYREF pExpirationTime AS ANY _                       ' __in  PLARGE_INTEGER               pExpirationTime         OPTIONAL
 , BYVAL Identifier AS QUAD _                           ' __in  LUID                         Identifier
 , BYVAL DynamicGroupArgs AS DWORD _                    ' __in  PVOID                        DynamicGroupArgs
 , BYREF phNewAuthzClientContext AS DWORD _             ' __out PAUTHZ_CLIENT_CONTEXT_HANDLE phNewAuthzClientContext
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION AuthzAddSidsToContext IMPORT "Authz.dll" ALIAS "AuthzAddSidsToContext" ( _
   BYVAL hAuthzClientContext AS DWORD _                              ' __in  AUTHZ_CLIENT_CONTEXT_HANDLE  hAuthzClientContext
 , BYREF Sids AS SID_AND_ATTRIBUTES _                   ' __in  PSID_AND_ATTRIBUTES          Sids                    OPTIONAL
 , BYVAL SidCount AS DWORD _                            ' __in  DWORD                        SidCount
 , BYREF RestrictedSids AS SID_AND_ATTRIBUTES _         ' __in  PSID_AND_ATTRIBUTES          RestrictedSids          OPTIONAL
 , BYVAL RestrictedSidCount AS DWORD _                  ' __in  DWORD                        RestrictedSidCount
 , BYREF phNewAuthzClientContext AS DWORD _             ' __out PAUTHZ_CLIENT_CONTEXT_HANDLE phNewAuthzClientContext
 ) AS LONG                                              ' BOOL

'//
'//  API to modify security attributes in AUTHZ client context.
'//

DECLARE FUNCTION AuthzModifySecurityAttributes IMPORT "Authz.dll" ALIAS "AuthzModifySecurityAttributes" ( _
   BYVAL hAuthzClientContext AS DWORD _                           ' __in AUTHZ_CLIENT_CONTEXT_HANDLE            hAuthzClientContext
 , BYVAL pOperations AS LONG _                                    ' __in PAUTHZ_SECURITY_ATTRIBUTE_OPERATION    pOperations
 , BYREF pAttributes AS AUTHZ_SECURITY_ATTRIBUTES_INFORMATION _   ' __in PAUTHZ_SECURITY_ATTRIBUTES_INFORMATION pAttributes
 ) AS LONG                                                        ' BOOL

'//
'// Enumeration type to be used to specify the type of information to be
'// retrieved from an existing AuthzClientContext.
'//

' enum AUTHZ_CONTEXT_INFORMATION_CLASS
MACRO AUTHZ_CONTEXT_INFORMATION_CLASS_ENUM = LONG
%AuthzContextInfoUserSid            = 1
%AuthzContextInfoGroupsSids         = 2
%AuthzContextInfoRestrictedSids     = 3
%AuthzContextInfoPrivileges         = 4
%AuthzContextInfoExpirationTime     = 5
%AuthzContextInfoServerContext      = 6
%AuthzContextInfoIdentifier         = 7
%AuthzContextInfoSource             = 8
%AuthzContextInfoAll                = 9
%AuthzContextInfoAuthenticationId   = 10
%AuthzContextInfoSecurityAttributes = 11

DECLARE FUNCTION AuthzGetInformationFromContext IMPORT "Authz.dll" ALIAS "AuthzGetInformationFromContext" ( _
   BYVAL hAuthzClientContext AS DWORD _                 ' __in  AUTHZ_CLIENT_CONTEXT_HANDLE     hAuthzClientContext
 , BYVAL InfoClass AS AUTHZ_CONTEXT_INFORMATION_CLASS_ENUM _ ' __in  AUTHZ_CONTEXT_INFORMATION_CLASS InfoClass
 , BYVAL BufferSize AS DWORD _                          ' __in  DWORD                           BufferSize
 , BYREF pSizeRequired AS DWORD _                       ' __out PDWORD                          pSizeRequired
 , BYREF Buffer AS ANY _                                ' __out PVOID                           Buffer
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION AuthzFreeContext IMPORT "Authz.dll" ALIAS "AuthzFreeContext" ( _
   BYVAL hAuthzClientContext AS DWORD _                 ' __in AUTHZ_CLIENT_CONTEXT_HANDLE hAuthzClientContext
 ) AS LONG                                              ' BOOL

'//
'// Valid flags that may be used in AuthzInitializeObjectAccessAuditEvent().
'//

%AUTHZ_NO_SUCCESS_AUDIT                   = &H00000001???
%AUTHZ_NO_FAILURE_AUDIT                   = &H00000002???
%AUTHZ_NO_ALLOC_STRINGS                   = &H00000004???

%AUTHZ_VALID_OBJECT_ACCESS_AUDIT_FLAGS    = %AUTHZ_NO_SUCCESS_AUDIT OR _
                                            %AUTHZ_NO_FAILURE_AUDIT OR _
                                            %AUTHZ_NO_ALLOC_STRINGS

'AUTHZAPI
'BOOL
'WINAPI
'AuthzInitializeObjectAccessAuditEvent(
'    IN    DWORD                         Flags,
'    IN    AUTHZ_AUDIT_EVENT_TYPE_HANDLE hAuditEventType,
'    __in  PWSTR                         szOperationType,
'    __in  PWSTR                         szObjectType,
'    __in  PWSTR                         szObjectName,
'    __in  PWSTR                         szAdditionalInfo,
'    OUT   PAUTHZ_AUDIT_EVENT_HANDLE     phAuditEvent,
'    IN    DWORD                         dwAdditionalParameterCount,
'    ...
'    );

DECLARE FUNCTION AuthzInitializeObjectAccessAuditEvent CDECL IMPORT "Authz.dll" ALIAS "AuthzInitializeObjectAccessAuditEvent" ( _
   BYVAL Flags AS DWORD _                               ' __in  DWORD                         Flags
 , BYVAL hAuditEventType AS DWORD _                     ' __in  AUTHZ_AUDIT_EVENT_TYPE_HANDLE hAuditEventType
 , BYREF szOperationType AS WSTRINGZ _                  ' __in  PWSTR                         szOperationType
 , BYREF szObjectType AS WSTRINGZ _                     ' __in  PWSTR                         szObjectType
 , BYREF szObjectName AS WSTRINGZ _                     ' __in  PWSTR                         szObjectName
 , BYREF szAdditionalInfo AS WSTRINGZ _                 ' __in  PWSTR                         szAdditionalInfo
 , BYREF phAuditEvent AS DWORD _                        ' __out PAUTHZ_AUDIT_EVENT_HANDLE     phAuditEvent
 , BYVAL dwAdditionalParameterCount AS DWORD _          ' __in  DWORD                         dwAdditionalParameterCount
 ) AS LONG                                              ' BOOL

'AUTHZAPI
'BOOL
'WINAPI
'AuthzInitializeObjectAccessAuditEvent2(
'    IN    DWORD                         Flags,
'    IN    AUTHZ_AUDIT_EVENT_TYPE_HANDLE hAuditEventType,
'    __in  PWSTR                         szOperationType,
'    __in  PWSTR                         szObjectType,
'    __in  PWSTR                         szObjectName,
'    __in  PWSTR                         szAdditionalInfo,
'    __in  PWSTR                         szAdditionalInfo2,
'    OUT   PAUTHZ_AUDIT_EVENT_HANDLE     phAuditEvent,
'    IN    DWORD                         dwAdditionalParameterCount,
'    ...
'    );

DECLARE FUNCTION AuthzInitializeObjectAccessAuditEvent2 CDECL IMPORT "Authz.dll" ALIAS "AuthzInitializeObjectAccessAuditEvent2" ( _
   BYVAL Flags AS DWORD _                               ' __in  DWORD                         Flags
 , BYVAL hAuditEventType AS DWORD _                     ' __in  AUTHZ_AUDIT_EVENT_TYPE_HANDLE hAuditEventType
 , BYREF szOperationType AS WSTRINGZ _                  ' __in  PWSTR                         szOperationType
 , BYREF szObjectType AS WSTRINGZ _                     ' __in  PWSTR                         szObjectType
 , BYREF szObjectName AS WSTRINGZ _                     ' __in  PWSTR                         szObjectName
 , BYREF szAdditionalInfo AS WSTRINGZ _                 ' __in  PWSTR                         szAdditionalInfo
 , BYREF szAdditionalInfo2 AS WSTRINGZ _                ' __in  PWSTR                         szAdditionalInfo2
 , BYREF phAuditEvent AS DWORD _                        ' __out PAUTHZ_AUDIT_EVENT_HANDLE     phAuditEvent
 , BYVAL dwAdditionalParameterCount AS DWORD _          ' __in  DWORD                         dwAdditionalParameterCount
 ) AS LONG                                              ' BOOL

'//
'// Enumeration type to be used to specify the type of information to be
'// retrieved from an existing AUTHZ_AUDIT_EVENT_HANDLE.
'//

' enum AUTHZ_AUDIT_EVENT_INFORMATION_CLASS
%AuthzAuditEventInfoFlags          = 1
%AuthzAuditEventInfoOperationType  = 2
%AuthzAuditEventInfoObjectType     = 3
%AuthzAuditEventInfoObjectName     = 4
%AuthzAuditEventInfoAdditionalInfo = 5

' Removed in the Windows 7 SDK
'DECLARE FUNCTION AuthzGetInformationFromAuditEvent IMPORT "Authz.dll" ALIAS "AuthzGetInformationFromAuditEvent" ( _
'   BYVAL hAuditEvent AS DWORD _                         ' __in  AUTHZ_AUDIT_EVENT_HANDLE            hAuditEvent
' , BYVAL InfoClass AS DWORD _                           ' __in  AUTHZ_AUDIT_EVENT_INFORMATION_CLASS InfoClass
' , BYVAL BufferSize AS DWORD _                          ' __in  DWORD                               BufferSize
' , BYREF pSizeRequired AS DWORD _                       ' __out PDWORD                              pSizeRequired
' , BYREF Buffer AS ANY _                                ' __out PVOID                               Buffer
' ) AS LONG                                              ' BOOL

DECLARE FUNCTION AuthzFreeAuditEvent IMPORT "Authz.dll" ALIAS "AuthzFreeAuditEvent" ( _
   BYVAL hAuditEvent AS DWORD _                         ' __in AUTHZ_AUDIT_EVENT_HANDLE hAuditEvent
 ) AS LONG                                              ' BOOL

'//
'// Support for SACL evaluation
'//

DECLARE FUNCTION AuthzEvaluateSacl IMPORT "Authz.dll" ALIAS "AuthzEvaluateSacl" ( _
   BYVAL AuthzClientContext AS DWORD _                  ' __in  AUTHZ_CLIENT_CONTEXT_HANDLE AuthzClientContext
 , BYREF pRequest AS AUTHZ_ACCESS_REQUEST _             ' __in  PAUTHZ_ACCESS_REQUEST       pRequest
 , BYREF Sacl AS ACL _                                  ' __in  PACL                        Sacl
 , BYVAL GrantedAccess AS ACCESS_MASK _                 ' __in  ACCESS_MASK                 GrantedAccess
 , BYVAL AccessGranted AS LONG _                        ' __in  BOOL                        AccessGranted
 , BYREF pbGenerateAudit AS LONG _                      ' __out PBOOL                       pbGenerateAudit
 ) AS LONG                                              ' BOOL

'//
'// Support for generic auditing.
'//

' // Size = 8 bytes
TYPE AUTHZ_REGISTRATION_OBJECT_TYPE_NAME_OFFSET DWORD
   szObjectTypeName AS WSTRINGZ PTR   ' PWSTR
   dwOffset         AS DWORD          ' DWORD
END TYPE

UNION AUTHZ_SOURCE_SCHEMA_REGISTRATION_UNION DWORD
   pReserved     AS DWORD      ' PVOID
   pProviderGuid AS GUID PTR   ' GUID*
END UNION

' // Size = 40 bytes
TYPE AUTHZ_SOURCE_SCHEMA_REGISTRATION DWORD
   dwFlags                    AS DWORD          ' DWORD
   szEventSourceName          AS WSTRINGZ PTR   ' PWSTR
   szEventMessageFile         AS WSTRINGZ PTR   ' PWSTR
   szEventSourceXmlSchemaFile AS WSTRINGZ PTR   ' PWSTR
   szEventAccessStringsFile   AS WSTRINGZ PTR   ' PWSTR
   szExecutableImagePath      AS WSTRINGZ PTR   ' PWSTR
   AUTHZ_SOURCE_SCHEMA_REGISTRATION_UNION
   dwObjectTypeNameCount      AS DWORD          ' DWORD
   ObjectTypeNames(0)         AS AUTHZ_REGISTRATION_OBJECT_TYPE_NAME_OFFSET
END TYPE

%AUTHZ_FLAG_ALLOW_MULTIPLE_SOURCE_INSTANCES = &H1

DECLARE FUNCTION AuthzInstallSecurityEventSource IMPORT "Authz.dll" ALIAS "AuthzInstallSecurityEventSource" ( _
   BYVAL dwFlags AS DWORD _                                  ' __in DWORD                             dwFlags
 , BYREF pRegistration AS AUTHZ_SOURCE_SCHEMA_REGISTRATION _ ' __in PAUTHZ_SOURCE_SCHEMA_REGISTRATION pRegistration
 ) AS LONG                                                   ' BOOL

DECLARE FUNCTION AuthzUninstallSecurityEventSource IMPORT "Authz.dll" ALIAS "AuthzUninstallSecurityEventSource" ( _
   BYVAL dwFlags AS DWORD _                             ' __in DWORD  dwFlags
 , BYREF szEventSourceName AS WSTRINGZ _                ' __in PCWSTR szEventSourceName
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION AuthzEnumerateSecurityEventSources IMPORT "Authz.dll" ALIAS "AuthzEnumerateSecurityEventSources" ( _
   BYVAL dwFlags AS DWORD _                             ' __in     DWORD                             dwFlags
 , BYREF Buffer AS AUTHZ_SOURCE_SCHEMA_REGISTRATION _   ' __out    PAUTHZ_SOURCE_SCHEMA_REGISTRATION Buffer
 , BYREF pdwCount AS DWORD _                            ' __out    PDWORD                            pdwCount
 , BYREF pdwLength AS DWORD _                           ' __in_out PDWORD                            pdwLength
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION AuthzRegisterSecurityEventSource IMPORT "Authz.dll" ALIAS "AuthzRegisterSecurityEventSource" ( _
   BYVAL dwFlags AS DWORD _                             ' __in  DWORD                                 dwFlags
 , BYREF szEventSourceName AS WSTRINGZ _                ' __in  PCWSTR                                szEventSourceName
 , BYREF phEventProvider AS DWORD _                     ' __out PAUTHZ_SECURITY_EVENT_PROVIDER_HANDLE phEventProvider
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION AuthzUnregisterSecurityEventSource IMPORT "Authz.dll" ALIAS "AuthzUnregisterSecurityEventSource" ( _
   BYVAL dwFlags AS DWORD _                             ' __in     DWORD                                 dwFlags
 , BYREF phEventProvider AS DWORD _                     ' __in_out PAUTHZ_SECURITY_EVENT_PROVIDER_HANDLE phEventProvider
 ) AS LONG                                              ' BOOL

'AUTHZAPI
'BOOL
'WINAPI
'AuthzReportSecurityEvent(
'    IN     DWORD                                dwFlags,
'    IN OUT AUTHZ_SECURITY_EVENT_PROVIDER_HANDLE hEventProvider,
'    IN     DWORD                                dwAuditId,
'    IN     PSID                                 pUserSid        OPTIONAL,
'    IN     DWORD                                dwCount,
'    ...
'    );

DECLARE FUNCTION AuthzReportSecurityEvent CDECL IMPORT "Authz.dll" ALIAS "AuthzReportSecurityEvent" ( _
   BYVAL dwFlags AS DWORD _                             ' __in DWORD                                dwFlags
 , BYVAL hEventProvider AS DWORD _                      ' __in AUTHZ_SECURITY_EVENT_PROVIDER_HANDLE hEventProvider
 , BYVAL dwAuditId AS DWORD _                           ' __in DWORD                                dwAuditId
 , BYVAL pUserSid AS SID PTR _                          ' __in PSID                                 pUserSid        OPTIONAL
 , BYVAL dwCount AS DWORD _                             ' __in DWORD                                dwCount
 , OPTIONAL BYREF ANY _                                 ' A list of AuditParamFlag type/value pairs
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION AuthzReportSecurityEventFromParams IMPORT "Authz.dll" ALIAS "AuthzReportSecurityEventFromParams" ( _
   BYVAL dwFlags AS DWORD _                             ' __in DWORD                                dwFlags
 , BYVAL hEventProvider AS DWORD _                      ' __in AUTHZ_SECURITY_EVENT_PROVIDER_HANDLE hEventProvider
 , BYVAL dwAuditId AS DWORD _                           ' __in DWORD                                dwAuditId
 , BYVAL pUserSid AS SID PTR _                          ' __in PSID                                 pUserSid       OPTIONAL
 , BYREF pParams AS AUDIT_PARAMS _                      ' __in PAUDIT_PARAMS                        pParams
 ) AS LONG                                              ' BOOL
