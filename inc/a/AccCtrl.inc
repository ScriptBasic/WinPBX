' ########################################################################################
' Microsoft Windows
' File: AccCtrl.inc
' Contents: Common includes for new style Win32 Access Control APIs
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%ACCCTRL_INC = 1

#INCLUDE ONCE "wtypes.inc"

'#define AccFree LocalFree
MACRO AccFree = LocalFree

'//
'// Definition:
'// This enumerated type defines the objects supported by the get/set API within
'// this document.  See section 3.1, Object Types for a detailed definition of the
'// supported object types, and their name formats.
'//

' Enum SE_OBJECT_TYPE
MACRO SE_OBJECT_TYPE_ENUM = LONG
%SE_UNKNOWN_OBJECT_TYPE     = 0
%SE_FILE_OBJECT             = 1
%SE_SERVICE                 = 2
%SE_PRINTER                 = 3
%SE_REGISTRY_KEY            = 4
%SE_LMSHARE                 = 5
%SE_KERNEL_OBJECT           = 6
%SE_WINDOW_OBJECT           = 7
%SE_DS_OBJECT               = 8
%SE_DS_OBJECT_ALL           = 9
%SE_PROVIDER_DEFINED_OBJECT = 10
%SE_WMIGUID_OBJECT          = 11
%SE_REGISTRY_WOW64_32KEY    = 12

'//
'// Definition: TRUSTEE_TYPE
'// This enumerated type specifies the type of trustee account for the trustee
'// returned by the API described in this document.
'// TRUSTEE_IS_UNKNOWN - The trustee is an unknown, but not necessarily invalid
'//                      type.  This field is not validated on input to the APIs
'//                      that take Trustees.
'// TRUSTEE_IS_USER      The trustee account is a user account.
'// TRUSTEE_IS_GROUP     The trustee account is a group account.
'//

' Enum TRUSTEE_TYPE
MACRO TRUSTEE_TYPE_ENUM = LONG
%TRUSTEE_IS_UNKNOWN          = 0
%TRUSTEE_IS_USER             = 1
%TRUSTEE_IS_GROUP            = 2
%TRUSTEE_IS_DOMAIN           = 3
%TRUSTEE_IS_ALIAS            = 4
%TRUSTEE_IS_WELL_KNOWN_GROUP = 5
%TRUSTEE_IS_DELETED          = 6
%TRUSTEE_IS_INVALID          = 7
%TRUSTEE_IS_COMPUTER         = 8

'//
'// Definition: TRUSTEE_FORM
'// This enumerated type specifies the form the trustee identifier is in for a
'// particular trustee.
'// TRUSTEE_IS_SID       The trustee is identified with a SID rather than with a name.
'// TRUSTEE_IS_NAME      The trustee is identified with a name.
'//

' Enum TRUSTEE_FORM
MACRO TRUSTEE_FORM_ENUM = LONG
%TRUSTEE_IS_SID              = 0
%TRUSTEE_IS_NAME             = 1
%TRUSTEE_BAD_FORM            = 2
%TRUSTEE_IS_OBJECTS_AND_SID  = 3
%TRUSTEE_IS_OBJECTS_AND_NAME = 4

'//
'// Definition: MULTIPLE_TRUSTEE_OPERATION
'// If the trustee is a multiple trustee, this enumerated type specifies the type.
'// TRUSTEE_IS_IMPERSONATE       The trustee is an impersonate trustee and the multiple
'//                          trustee field in the trustee points to another trustee
'//                          that is a trustee for the server that will be doing the
'//                          impersonation.
'//

' Enum MULTIPLE_TRUSTEE_OPERATION
MACRO MULTIPLE_TRUSTEE_OPERATION_ENUM = LONG
%NO_MULTIPLE_TRUSTEE    = 0
%TRUSTEE_IS_IMPERSONATE = 1

' // Size = 40 bytes
TYPE OBJECTS_AND_SID DWORD
   ObjectsPresent          AS DWORD        ' DWORD
   ObjectTypeGuid          AS GUID         ' GUID
   InheritedObjectTypeGuid AS GUID         ' GUID
   pSid                    AS SID PTR      ' SID *
END TYPE

' // Size = 20 bytes
TYPE OBJECTS_AND_NAME_A DWORD
   ObjectsPresent          AS DWORD                 ' DWORD
   ObjectType              AS SE_OBJECT_TYPE_ENUM   ' SE_OBJECT_TYPE
   ObjectTypeName          AS ASCIIZ PTR            ' LPSTR
   InheritedObjectTypeName AS ASCIIZ PTR            ' LPSTR
   ptstrName               AS ASCIIZ PTR            ' LPSTR
END TYPE

' // Size = 20 bytes
TYPE OBJECTS_AND_NAME_W DWORD
   ObjectsPresent          AS DWORD                 ' DWORD
   ObjectType              AS SE_OBJECT_TYPE_ENUM   ' SE_OBJECT_TYPE
   ObjectTypeName          AS WSTRINGZ PTR          ' LPWSTR
   InheritedObjectTypeName AS WSTRINGZ PTR          ' LPWSTR
   ptstrName               AS WSTRINGZ PTR          ' LPWSTR
END TYPE

#IF %DEF(%UNICODE)
MACRO OBJECTS_AND_NAME = OBJECTS_AND_NAME_W
#ELSE
MACRO OBJECTS_AND_NAME = OBJECTS_AND_NAME_A
#ENDIF

'//
'// Definition: TRUSTEE
'// This structure is used to pass account information into and out of the system
'// using the API defined in this document.
'// PMultipleTrustee     - if NON-NULL, points to another trustee structure, as
'//                        defined by the multiple trustee operation field.
'// MultipleTrusteeOperation - Defines the multiple trustee operation/type.
'// TrusteeForm - defines if the trustee is defined by name or SID.
'// TrusteeType - defines if the trustee type is unknown, a user or a group.
'// PwcsName     - points to the trustee name or the trustee SID.
'//

' // Size = 20 bytes
TYPE TRUSTEE_A DWORD
   pMultipleTrustee         AS TRUSTEE_A PTR                     ' struct _TRUSTEE_A           *pMultipleTrustee
   MultipleTrusteeOperation AS MULTIPLE_TRUSTEE_OPERATION_ENUM   ' MULTIPLE_TRUSTEE_OPERATION  MultipleTrusteeOperation
   TrusteeForm              AS TRUSTEE_FORM_ENUM                 ' TRUSTEE_FORM                TrusteeForm
   TrusteeType              AS TRUSTEE_TYPE_ENUM                 ' TRUSTEE_TYPE                TrusteeType
   ptstrName                AS ASCIIZ PTR                        ' LPSTR                       ptstrName
END TYPE

' // Size = 20 bytes
TYPE TRUSTEE_W DWORD
   pMultipleTrustee         AS TRUSTEE_W PTR                     ' struct _TRUSTEE_W           *pMultipleTrustee
   MultipleTrusteeOperation AS MULTIPLE_TRUSTEE_OPERATION_ENUM   ' MULTIPLE_TRUSTEE_OPERATION  MultipleTrusteeOperation
   TrusteeForm              AS TRUSTEE_FORM_ENUM                 ' TRUSTEE_FORM                TrusteeForm
   TrusteeType              AS TRUSTEE_TYPE_ENUM                 ' TRUSTEE_TYPE                TrusteeType
   ptstrName                AS WSTRINGZ PTR                      ' LPWSTR                      ptstrName
END TYPE

MACRO TRUSTEEA = TRUSTEE_A
MACRO TRUSTEEW = TRUSTEE_W
#IF %DEF(%UNICODE)
MACRO TRUSTEE  = TRUSTEE_W
#ELSE
MACRO TRUSTEE  = TRUSTEE_A
#ENDIF

'//
'// Definition: ACCESS_MODE
'// This enumerated type specifies how permissions are (requested)/to be applied
'// for the trustee by the access control entry.  On input this field can by any
'// of the values, although it is not meaningful to mix access control and audit
'// control entries.  On output this field will be either SET_ACCESS, DENY_ACCESS,
'// SET_AUDIT_SUCCESS, SET_AUDIT_FAILURE.
'// The following descriptions define how this type effects an explicit access
'// request to apply access permissions to an object.
'// GRANT_ACCESS - The trustee will have at least the requested permissions upon
'//                successful completion of the command. (If the trustee has
'//                additional permissions they will not be removed).
'// SET_ACCESS - The trustee will have exactly the requested permissions upon
'//              successful completion of the command.
'// DENY_ACCESS - The trustee will be denied the specified permissions.
'// REVOKE_ACCESS - Any explicit access rights the trustee has will be revoked.
'// SET_AUDIT_SUCCESS - The trustee will be audited for successful opens of the
'//                     object using the requested permissions.
'// SET_AUDIT_FAILURE - The trustee will be audited for failed opens of the object
'//                     using the requested permissions.
'//

' Enum ACCESS_MODE
MACRO ACCESS_MODE_ENUM = LONG
%NOT_USED_ACCESS   = 0
%GRANT_ACCESS      = 1
%SET_ACCESS        = 2
%DENY_ACCESS       = 3
%REVOKE_ACCESS     = 4
%SET_AUDIT_SUCCESS = 5
%SET_AUDIT_FAILURE = 6

'//
'// Definition: Inheritance flags
'// These bit masks are provided to allow simple application of inheritance in
'// explicit access requests on containers.
'// NO_INHERITANCE       The specific access permissions will only be applied to
'//                  the container, and will not be inherited by objects created
'//                  within the container.
'// SUB_CONTAINERS_ONLY_INHERIT  The specific access permissions will be inherited
'//                              and applied to sub containers created within the
'//                              container, and will be applied to the container
'//                              itself.
'// SUB_OBJECTS_ONLY_INHERIT     The specific access permissions will only be inherited
'//                              by objects created within the specific container.
'//                              The access permissions will not be applied to the
'//                              container itself.
'// SUB_CONTAINERS_AND_OBJECTS_INHERIT   The specific access permissions will be
'//                                      inherited by containers created within the
'//                                      specific container, will be applied to
'//                                      objects created within the container, but
'//                                      will not be applied to the container itself.
'//

%NO_INHERITANCE                     = &H0???
%SUB_OBJECTS_ONLY_INHERIT           = &H1???
%SUB_CONTAINERS_ONLY_INHERIT        = &H2???
%SUB_CONTAINERS_AND_OBJECTS_INHERIT = &H3???
%INHERIT_NO_PROPAGATE               = &H4???
%INHERIT_ONLY                       = &H8???

'//
'// Informational bit that is returned
'//
%INHERITED_ACCESS_ENTRY             = &H10???

'//
'// Informational bit that tells where a node was inherited from.  Valid only
'// for NT 5 APIs
'//
%INHERITED_PARENT                   = &H10000000???
%INHERITED_GRANDPARENT              = &H20000000???

'//
'// Definition: EXPLICIT_ACCESS
'// This structure is used to pass access control entry information into and out
'// of the system using the API defined in this document.
'// grfAccessPermissions - This contains the access permissions to assign for the
'//                     trustee.  It is in the form of an NT access mask.
'// grfAccessMode - This field defines how the permissions are to be applied for
'//                 the trustee.
'// grfInheritance - For containers, this field defines how the access control
'//                  entry is/(is requested) to be inherited on
'//                  objects/sub-containers created within the container.
'// Trustee - This field contains the definition of the trustee account the
'//           explicit access applies to.
'//

' // Size = 32 bytes
TYPE EXPLICIT_ACCESS_A DWORD
   grfAccessPermissions AS DWORD              ' DWORD
   grfAccessMode        AS ACCESS_MODE_ENUM   ' ACCESS_MODE
   grfInheritance       AS DWORD              ' DWORD
   Trustee              AS TRUSTEE_A          ' TRUSTEE_A
END TYPE

' // Size = 32 bytes
TYPE EXPLICIT_ACCESS_W DWORD
   grfAccessPermissions AS DWORD              ' DWORD
   grfAccessMode        AS ACCESS_MODE_ENUM   ' ACCESS_MODE
   grfInheritance       AS DWORD              ' DWORD
   Trustee              AS TRUSTEE_W          ' TRUSTEE_W
END TYPE

MACRO EXPLICIT_ACCESSA = EXPLICIT_ACCESS_A
MACRO EXPLICIT_ACCESSW = EXPLICIT_ACCESS_W
#IF %DEF(%UNICODE)
MACRO EXPLICIT_ACCESS  = EXPLICIT_ACCESS_W
#ELSE
MACRO EXPLICIT_ACCESS  = EXPLICIT_ACCESS_A
#ENDIF

'//----------------------------------------------------------------------------
'//
'//                                  NT5 APIs
'//
'//----------------------------------------------------------------------------

'//
'// Default provider
'//

$ACCCTRL_DEFAULT_PROVIDERA  = "Windows NT Access Provider"
$$ACCCTRL_DEFAULT_PROVIDERW = "Windows NT Access Provider"$$
#IF %DEF(%UNICODE)
MACRO ACCCTRL_DEFAULT_PROVIDER = $$ACCCTRL_DEFAULT_PROVIDERW
#ELSE
MACRO ACCCTRL_DEFAULT_PROVIDER = $ACCCTRL_DEFAULT_PROVIDERA
#ENDIF

'//
'/// Access rights
'//
'typedef     ULONG   ACCESS_RIGHTS, *PACCESS_RIGHTS;

'//
'// Inheritance flags
'//
'typedef ULONG INHERIT_FLAGS, *PINHERIT_FLAGS;

'//
'// Access / Audit structures
'//

' // Size = 40 bytes
TYPE ACTRL_ACCESS_ENTRYA DWORD
   Trustee            AS TRUSTEE_A      ' TRUSTEE_A
   fAccessFlags       AS DWORD          ' ULONG
   dAccess            AS DWORD          ' ACCESS_RIGHTS
   ProvSpecificAccess AS DWORD          ' ACCESS_RIGHTS
   Inheritance        AS DWORD          ' INHERIT_FLAGS
   lpInheritProperty  AS ASCIIZ PTR     ' LPSTR
END TYPE

' // Size = 40 bytes
TYPE ACTRL_ACCESS_ENTRYW DWORD
   Trustee            AS TRUSTEE_W      ' TRUSTEE_W
   fAccessFlags       AS DWORD          ' ULONG
   dAccess            AS DWORD          ' ACCESS_RIGHTS
   ProvSpecificAccess AS DWORD          ' ACCESS_RIGHTS
   Inheritance        AS DWORD          ' INHERIT_FLAGS
   lpInheritProperty  AS WSTRINGZ PTR   ' LPWSTR
END TYPE

MACRO ACTRL_ACCESS_ENTRY_A = ACTRL_ACCESS_ENTRYA
MACRO ACTRL_ACCESS_ENTRY_W = ACTRL_ACCESS_ENTRYW
#IF %DEF(%UNICODE)
MACRO ACTRL_ACCESS_ENTRY   = ACTRL_ACCESS_ENTRYW
#ELSE
MACRO ACTRL_ACCESS_ENTRY   = ACTRL_ACCESS_ENTRYA
#ENDIF

' // Size = 8 bytes
TYPE ACTRL_ACCESS_ENTRY_LISTA DWORD
   cEntries    AS DWORD                     ' ULONG
   pAccessList AS ACTRL_ACCESS_ENTRYA PTR   ' ACTRL_ACCESS_ENTRYA *
END TYPE

' // Size = 8 bytes
TYPE ACTRL_ACCESS_ENTRY_LISTW DWORD
   cEntries    AS DWORD                     ' ULONG
   pAccessList AS ACTRL_ACCESS_ENTRYW PTR   ' ACTRL_ACCESS_ENTRYW *
END TYPE

MACRO ACTRL_ACCESS_ENTRY_LIST_A = ACTRL_ACCESS_ENTRY_LISTA
MACRO ACTRL_ACCESS_ENTRY_LIST_W = ACTRL_ACCESS_ENTRY_LISTW
#IF %DEF(%UNICODE)
MACRO ACTRL_ACCESS_ENTRY_LIST   = ACTRL_ACCESS_ENTRY_LISTW
#ELSE
MACRO ACTRL_ACCESS_ENTRY_LIST   = ACTRL_ACCESS_ENTRY_LISTA
#ENDIF

' // Size = 12 bytes
TYPE ACTRL_PROPERTY_ENTRYA DWORD
   lpProperty       AS ASCIIZ PTR                     ' LPSTR
   pAccessEntryList AS ACTRL_ACCESS_ENTRY_LISTA PTR   ' PACTRL_ACCESS_ENTRY_LISTA
   fListFlags       AS DWORD                          ' ULONG
END TYPE

' // Size = 12 bytes
TYPE ACTRL_PROPERTY_ENTRYW DWORD
   lpProperty       AS WSTRINGZ PTR                   ' LPWSTR
   pAccessEntryList AS ACTRL_ACCESS_ENTRY_LISTW PTR   ' PACTRL_ACCESS_ENTRY_LISTW
   fListFlags       AS DWORD                          ' ULONG
END TYPE

MACRO ACTRL_PROPERTY_ENTRY_A = ACTRL_PROPERTY_ENTRYA
MACRO ACTRL_PROPERTY_ENTRY_W = ACTRL_PROPERTY_ENTRYW
#IF %DEF(%UNICODE)
MACRO ACTRL_PROPERTY_ENTRY   = ACTRL_PROPERTY_ENTRYW
#ELSE
MACRO ACTRL_PROPERTY_ENTRY   = ACTRL_PROPERTY_ENTRYA
#ENDIF


' // Size = 8 bytes
TYPE ACTRL_ALISTA DWORD
   cEntries            AS DWORD                      ' ULONG
   pPropertyAccessList AS ACTRL_PROPERTY_ENTRYA PTR  ' PACTRL_PROPERTY_ENTRYA
END TYPE

' // Size = 8 bytes
TYPE ACTRL_ALISTW DWORD
   cEntries            AS DWORD                      ' ULONG
   pPropertyAccessList AS ACTRL_PROPERTY_ENTRYW PTR  ' PACTRL_PROPERTY_ENTRYW
END TYPE

MACRO ACTRL_ALIST_A = ACTRL_ALISTA
MACRO ACTRL_ALIST_W = ACTRL_ALISTW
#IF %DEF(%UNICODE)
MACRO ACTRL_ALIST   = ACTRL_ALISTW
#ELSE
MACRO ACTRL_ALIST   = ACTRL_ALISTA
#ENDIF

' // Size = 8 bytes
TYPE ACTRL_ACCESSA DWORD
   cEntries            AS DWORD                      ' ULONG
   pPropertyAccessList AS ACTRL_PROPERTY_ENTRYA PTR  ' PACTRL_PROPERTY_ENTRYA
END TYPE

' // Size = 8 bytes
TYPE ACTRL_ACCESSW DWORD
   cEntries            AS DWORD                      ' ULONG
   pPropertyAccessList AS ACTRL_PROPERTY_ENTRYW PTR  ' PACTRL_PROPERTY_ENTRYW
END TYPE

MACRO ACTRL_ACCESS_A = ACTRL_ACCESSA
MACRO ACTRL_ACCESS_W = ACTRL_ACCESSW
#IF %DEF(%UNICODE)
MACRO ACTRL_ACCESS   = ACTRL_ACCESSW
#ELSE
MACRO ACTRL_ACCESS   = ACTRL_ACCESSA
#ENDIF

' // Size = 8 bytes
TYPE ACTRL_AUDITA DWORD
   cEntries            AS DWORD                      ' ULONG
   pPropertyAccessList AS ACTRL_PROPERTY_ENTRYA PTR  ' PACTRL_PROPERTY_ENTRYA
END TYPE

' // Size = 8 bytes
TYPE ACTRL_AUDITW DWORD
   cEntries            AS DWORD                      ' ULONG
   pPropertyAccessList AS ACTRL_PROPERTY_ENTRYW PTR  ' PACTRL_PROPERTY_ENTRYW
END TYPE

MACRO ACTRL_AUDIT_A = ACTRL_AUDITA
MACRO ACTRL_AUDIT_W = ACTRL_AUDITW
#IF %DEF(%UNICODE)
MACRO ACTRL_AUDIT   = ACTRL_AUDITW
#ELSE
MACRO ACTRL_AUDIT   = ACTRL_AUDITA
#ENDIF

'//
'// TRUSTEE_ACCESS flags
'//
%TRUSTEE_ACCESS_ALLOWED    = &H00000001???
%TRUSTEE_ACCESS_READ       = &H00000002???
%TRUSTEE_ACCESS_WRITE      = &H00000004???

%TRUSTEE_ACCESS_EXPLICIT   = &H00000001???
%TRUSTEE_ACCESS_READ_WRITE = %TRUSTEE_ACCESS_READ OR %TRUSTEE_ACCESS_WRITE


%TRUSTEE_ACCESS_ALL        = &HFFFFFFFF???

' // Size = 16 bytes
TYPE TRUSTEE_ACCESSA DWORD
   lpProperty      AS ASCIIZ PTR     ' LPSTR
   Access          AS DWORD          ' ACCESS_RIGHTS
   fAccessFlags    AS DWORD          ' ULONG
   fReturnedAccess AS DWORD          ' ULONG
END TYPE

' // Size = 16 bytes
TYPE TRUSTEE_ACCESSW DWORD
   lpProperty      AS WSTRINGZ PTR   ' LPWSTR
   Access          AS DWORD          ' ACCESS_RIGHTS
   fAccessFlags    AS DWORD          ' ULONG
   fReturnedAccess AS DWORD          ' ULONG
END TYPE

MACRO TRUSTEE_ACCESS_A = TRUSTEE_ACCESSA
MACRO TRUSTEE_ACCESS_W = TRUSTEE_ACCESSW
#IF %DEF(%UNICODE)
MACRO TRUSTEE_ACCESS   = TRUSTEE_ACCESSW
#ELSE
MACRO TRUSTEE_ACCESS   = TRUSTEE_ACCESSA
#ENDIF

'//
'// Generic permission values
'//
%ACTRL_RESERVED              = &H00000000???
%ACTRL_PERM_1                = &H00000001???
%ACTRL_PERM_2                = &H00000002???
%ACTRL_PERM_3                = &H00000004???
%ACTRL_PERM_4                = &H00000008???
%ACTRL_PERM_5                = &H00000010???
%ACTRL_PERM_6                = &H00000020???
%ACTRL_PERM_7                = &H00000040???
%ACTRL_PERM_8                = &H00000080???
%ACTRL_PERM_9                = &H00000100???
%ACTRL_PERM_10               = &H00000200???
%ACTRL_PERM_11               = &H00000400???
%ACTRL_PERM_12               = &H00000800???
%ACTRL_PERM_13               = &H00001000???
%ACTRL_PERM_14               = &H00002000???
%ACTRL_PERM_15               = &H00004000???
%ACTRL_PERM_16               = &H00008000???
%ACTRL_PERM_17               = &H00010000???
%ACTRL_PERM_18               = &H00020000???
%ACTRL_PERM_19               = &H00040000???
%ACTRL_PERM_20               = &H00080000???

'//
'// Access permissions
'//
%ACTRL_ACCESS_ALLOWED        = &H00000001???
%ACTRL_ACCESS_DENIED         = &H00000002???
%ACTRL_AUDIT_SUCCESS         = &H00000004???
%ACTRL_AUDIT_FAILURE         = &H00000008???

'//
'// Property list flags
'//
%ACTRL_ACCESS_PROTECTED      = &H00000001???

'//
'// Standard and object rights
'//
%ACTRL_SYSTEM_ACCESS         = &H04000000???
%ACTRL_DELETE                = &H08000000???
%ACTRL_READ_CONTROL          = &H10000000???
%ACTRL_CHANGE_ACCESS         = &H20000000???
%ACTRL_CHANGE_OWNER          = &H40000000???
%ACTRL_SYNCHRONIZE           = &H80000000???
%ACTRL_STD_RIGHTS_ALL        = &HF8000000???
%ACTRL_STD_RIGHT_REQUIRED    = %ACTRL_STD_RIGHTS_ALL AND (%ACTRL_SYNCHRONIZE XOR &HFFFFFFFF???)

#IF NOT %DEF(%DS_CONTROL_BITS_DEFINED)
%DS_CONTROL_BITS_DEFINED = 1
%ACTRL_DS_OPEN                          = %ACTRL_RESERVED
%ACTRL_DS_CREATE_CHILD                  = %ACTRL_PERM_1
%ACTRL_DS_DELETE_CHILD                  = %ACTRL_PERM_2
%ACTRL_DS_LIST                          = %ACTRL_PERM_3
%ACTRL_DS_SELF                          = %ACTRL_PERM_4
%ACTRL_DS_READ_PROP                     = %ACTRL_PERM_5
%ACTRL_DS_WRITE_PROP                    = %ACTRL_PERM_6
%ACTRL_DS_DELETE_TREE                   = %ACTRL_PERM_7
%ACTRL_DS_LIST_OBJECT                   = %ACTRL_PERM_8
%ACTRL_DS_CONTROL_ACCESS                = %ACTRL_PERM_9
#ENDIF

%ACTRL_FILE_READ                        = %ACTRL_PERM_1
%ACTRL_FILE_WRITE                       = %ACTRL_PERM_2
%ACTRL_FILE_APPEND                      = %ACTRL_PERM_3
%ACTRL_FILE_READ_PROP                   = %ACTRL_PERM_4
%ACTRL_FILE_WRITE_PROP                  = %ACTRL_PERM_5
%ACTRL_FILE_EXECUTE                     = %ACTRL_PERM_6
%ACTRL_FILE_READ_ATTRIB                 = %ACTRL_PERM_8
%ACTRL_FILE_WRITE_ATTRIB                = %ACTRL_PERM_9
%ACTRL_FILE_CREATE_PIPE                 = %ACTRL_PERM_10
%ACTRL_DIR_LIST                         = %ACTRL_PERM_1
%ACTRL_DIR_CREATE_OBJECT                = %ACTRL_PERM_2
%ACTRL_DIR_CREATE_CHILD                 = %ACTRL_PERM_3
%ACTRL_DIR_DELETE_CHILD                 = %ACTRL_PERM_7
%ACTRL_DIR_TRAVERSE                     = %ACTRL_PERM_6
%ACTRL_KERNEL_TERMINATE                 = %ACTRL_PERM_1
%ACTRL_KERNEL_THREAD                    = %ACTRL_PERM_2
%ACTRL_KERNEL_VM                        = %ACTRL_PERM_3
%ACTRL_KERNEL_VM_READ                   = %ACTRL_PERM_4
%ACTRL_KERNEL_VM_WRITE                  = %ACTRL_PERM_5
%ACTRL_KERNEL_DUP_HANDLE                = %ACTRL_PERM_6
%ACTRL_KERNEL_PROCESS                   = %ACTRL_PERM_7
%ACTRL_KERNEL_SET_INFO                  = %ACTRL_PERM_8
%ACTRL_KERNEL_GET_INFO                  = %ACTRL_PERM_9
%ACTRL_KERNEL_CONTROL                   = %ACTRL_PERM_10
%ACTRL_KERNEL_ALERT                     = %ACTRL_PERM_11
%ACTRL_KERNEL_GET_CONTEXT               = %ACTRL_PERM_12
%ACTRL_KERNEL_SET_CONTEXT               = %ACTRL_PERM_13
%ACTRL_KERNEL_TOKEN                     = %ACTRL_PERM_14
%ACTRL_KERNEL_IMPERSONATE               = %ACTRL_PERM_15
%ACTRL_KERNEL_DIMPERSONATE              = %ACTRL_PERM_16
%ACTRL_PRINT_SADMIN                     = %ACTRL_PERM_1
%ACTRL_PRINT_SLIST                      = %ACTRL_PERM_2
%ACTRL_PRINT_PADMIN                     = %ACTRL_PERM_3
%ACTRL_PRINT_PUSE                       = %ACTRL_PERM_4
%ACTRL_PRINT_JADMIN                     = %ACTRL_PERM_5
%ACTRL_SVC_GET_INFO                     = %ACTRL_PERM_1
%ACTRL_SVC_SET_INFO                     = %ACTRL_PERM_2
%ACTRL_SVC_STATUS                       = %ACTRL_PERM_3
%ACTRL_SVC_LIST                         = %ACTRL_PERM_4
%ACTRL_SVC_START                        = %ACTRL_PERM_5
%ACTRL_SVC_STOP                         = %ACTRL_PERM_6
%ACTRL_SVC_PAUSE                        = %ACTRL_PERM_7
%ACTRL_SVC_INTERROGATE                  = %ACTRL_PERM_8
%ACTRL_SVC_UCONTROL                     = %ACTRL_PERM_9
%ACTRL_REG_QUERY                        = %ACTRL_PERM_1
%ACTRL_REG_SET                          = %ACTRL_PERM_2
%ACTRL_REG_CREATE_CHILD                 = %ACTRL_PERM_3
%ACTRL_REG_LIST                         = %ACTRL_PERM_4
%ACTRL_REG_NOTIFY                       = %ACTRL_PERM_5
%ACTRL_REG_LINK                         = %ACTRL_PERM_6
%ACTRL_WIN_CLIPBRD                      = %ACTRL_PERM_1
%ACTRL_WIN_GLOBAL_ATOMS                 = %ACTRL_PERM_2
%ACTRL_WIN_CREATE                       = %ACTRL_PERM_3
%ACTRL_WIN_LIST_DESK                    = %ACTRL_PERM_4
%ACTRL_WIN_LIST                         = %ACTRL_PERM_5
%ACTRL_WIN_READ_ATTRIBS                 = %ACTRL_PERM_6
%ACTRL_WIN_WRITE_ATTRIBS                = %ACTRL_PERM_7
%ACTRL_WIN_SCREEN                       = %ACTRL_PERM_8
%ACTRL_WIN_EXIT                         = %ACTRL_PERM_9

' // Size = 4 bytes
UNION ACTRL_OVERLAPPED_UNION DWORD
   Provider  AS DWORD       ' PVOID
   Reserved1 AS DWORD       ' ULONG
END UNION

' // Size = 12 bytes
TYPE ACTRL_OVERLAPPED DWORD
   ACTRL_OVERLAPPED_UNION
   Reserved2 AS DWORD       ' ULONG
   hEvent    AS DWORD       ' HANDLE
END TYPE

' // Size = 8 bytes
TYPE ACTRL_ACCESS_INFOA DWORD
   fAccessPermission      AS DWORD        ' ULONG
   lpAccessPermissionName AS ASCIIZ PTR   ' LPSTR
END TYPE

' // Size = 8 bytes
TYPE ACTRL_ACCESS_INFOW DWORD
   fAccessPermission      AS DWORD        ' ULONG
   lpAccessPermissionName AS WSTRINGZ PTR ' LPWSTR
END TYPE

MACRO ACTRL_ACCESS_INFO_A = ACTRL_ACCESS_INFOA
MACRO ACTRL_ACCESS_INFO_W = ACTRL_ACCESS_INFOW
#IF %DEF(%UNICODE)
MACRO ACTRL_ACCESS_INFO   = ACTRL_ACCESS_INFOW
#ELSE
MACRO ACTRL_ACCESS_INFO   = ACTRL_ACCESS_INFOA
#ENDIF

' // Size = 8 bytes
TYPE ACTRL_CONTROL_INFOA DWORD
   lpControlId   AS ASCIIZ PTR   ' LPSTR
   lpControlName AS ASCIIZ PTR   ' LPSTR
END TYPE

' // Size = 8 bytes
TYPE ACTRL_CONTROL_INFOW DWORD
   lpControlId   AS WSTRINGZ PTR   ' LPWSTR
   lpControlName AS WSTRINGZ PTR   ' LPWSTR
END TYPE

MACRO ACTRL_CONTROL_INFO_A = ACTRL_CONTROL_INFOA
MACRO ACTRL_CONTROL_INFO_W = ACTRL_CONTROL_INFOW
#IF %DEF(%UNICODE)
MACRO ACTRL_CONTROL_INFO   = ACTRL_CONTROL_INFOW
#ELSE
MACRO ACTRL_CONTROL_INFO   = ACTRL_CONTROL_INFOA
#ENDIF

%ACTRL_ACCESS_NO_OPTIONS              = &H00000000???
%ACTRL_ACCESS_SUPPORTS_OBJECT_ENTRIES = &H00000001???

'#if (NTDDI_VERSION >= NTDDI_VISTA)
%TREE_SEC_INFO_SET                    = &H00000001???
%TREE_SEC_INFO_RESET                  = &H00000002???
%TREE_SEC_INFO_RESET_KEEP_EXPLICIT    = &H00000003???
'#endif // (NTDDI_VERSION >= NTDDI_VISTA)

' Enum PROG_INVOKE_SETTING
MACRO PROG_INVOKE_SETTING_ENUM = LONG
%ProgressInvokeNever        = 1   ' // Never invoke the progress function
%ProgressInvokeEveryObject  = 2   ' // Invoke for each object
%ProgressInvokeOnError      = 3   ' // Invoke only for each error case
%ProgressCancelOperation    = 4   ' // Stop propagation and return
%ProgressRetryOperation     = 5   ' // Retry operation on subtree
'#if (NTDDI_VERSION >= NTDDI_VISTA)
%ProgressInvokePrePostError = 6   ' // Invoke Pre, Post, Error
'#endif // (NTDDI_VERSION >= NTDDI_VISTA)

'//
'// Progress Function:
'// Caller of tree operation implements this Progress function, then
'// passes its function pointer to tree operation.
'// Tree operation invokes Progress function to provide progress and error
'// information to the caller during the potentially long execution
'// of the tree operation.  Tree operation provides the name of the object
'// last processed and the error status of the operation on that object.
'// Tree operation also passes the current InvokeSetting value.
'// Caller may change the InvokeSetting value, for example, from "Always"
'// to "Only On Error."
'//

'/*
'typedef VOID (*FN_PROGRESS) (
'    IN LPWSTR                   pObjectName,    // name of object just processed
'    IN DWORD                    Status,         // status of operation on object
'    IN OUT PPROG_INVOKE_SETTING pInvokeSetting, // Never, always,
'    IN PVOID                    Args,           // Caller specific data
'    IN BOOL                     SecuritySet     // Whether security was set
'    );
'*/

'DECLARE SUB FN_PROGRESS ( _
'   BYREF pObjectName    AS WSTRINGZ _                  ' __in LPWSTR pObjectName // name of object just processed
' , BYVAL Status         AS DWORD _                     ' __in DWORD Status       // status of operation on object
' , BYREF pInvokeSetting AS PROG_INVOKE_SETTING_ENUM _  ' __inout PPROG_INVOKE_SETTING pInvokeSetting // Never, always,
' , BYVAL Args           AS DWORD _                     ' __in PVOID Args         // Caller specific data
' , BYVAL SecuritySet    AS LONG _                      ' __in BOOL SecuritySet   // Whether security was set
' )                                                     ' void


'//
'// New Object Type function pointers.  TBD.
'// To support additional object resource managers generically, the
'// resource manager must provide it's own functions for operations
'// like:
'// GetAncestorAcl(IN ObjName, IN GenerationGap, IN DaclOrSacl?, ...)
'// GetAncestorName(...)
'// FreeNameStructure(...)
'//

' // Size = 4 bytes
TYPE FN_OBJECT_MGR_FUNCTIONS DWORD
   Placeholder AS DWORD   ' ULONG
END TYPE

'//
'// Name of ancestor and number of generations between
'// ancestor and inheriting object.
'//
'// GenerationGap:
'//     Name of ancestor from which ACE was inherited.
'//     NULL for explicit ACE.
'//
'// AncestorName:
'//     Number of levels (or generations) between the object and the ancestor.
'//     Parent, gap=1.
'//     Grandparent, gap=2.
'//     Set to 0 for explicit ACE on object.
'//

' // Size = 8 bytes
TYPE INHERITED_FROMA DWORD
   GenerationGap AS LONG         ' LONG
   AncestorName  AS ASCIIZ PTR   ' LPSTR
END TYPE

' // Size = 8 bytes
TYPE INHERITED_FROMW DWORD
   GenerationGap AS LONG           ' LONG
   AncestorName  AS WSTRINGZ PTR   ' LPWSTR
END TYPE

MACRO INHERITED_FROM_A = INHERITED_FROMA
MACRO INHERITED_FROM_W = INHERITED_FROMW
#IF %DEF(%UNICODE)
MACRO INHERITED_FROM   = INHERITED_FROMW
#ELSE
MACRO INHERITED_FROM   = INHERITED_FROMA
#ENDIF
