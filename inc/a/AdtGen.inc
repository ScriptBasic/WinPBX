' ########################################################################################
' Microsoft Windows
' File: AdtGen.inc
' Contents: Sefinitions of types/functions required for generating generic audits.
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%ADTGEN_INC = 1

#INCLUDE ONCE "windows.inc"

'//
'// type of audit
'//
'// AUDIT_TYPE_LEGACY
'//     In this case the audit event schema is stored in a .mc file.
'//
'// AUDIT_TYPE_WMI
'//     The schema is stored in WMI. (currently not supported)
'//

%AUDIT_TYPE_LEGACY = 1
%AUDIT_TYPE_WMI    = 2

'//
'// Type of parameters passed in the AUDIT_PARAMS.Parameters array
'//
'// Use the AdtInitParams function to initialize and prepare
'// an array of audit parameters.
'//

' enum AUDIT_PARAM_TYPE
MACRO AUDIT_PARAM_TYPE_ENUM = LONG
%APT_None           = 1
%APT_String         = 2
%APT_Ulong          = 3
%APT_Pointer        = 4
%APT_Sid            = 5
%APT_LogonId        = 6
%APT_ObjectTypeList = 7
%APT_Luid           = 8
%APT_Guid           = 9
%APT_Time           = 10
%APT_Int64          = 11
%APT_IpAddress      = 12
%APT_LogonIdWithSid = 13

'//
'// There are two types of flags that can be used with a parameter.
'//
'// - formatting flag
'//   This defines the appearance of a parameter when
'//   written to the eventlog. Such flags may become obsolete
'//   when we move to WMI auditing.
'//
'// - control flag
'//   This causes a specified action to be taken that affects
'//   a parameter value.
'//
'//   For example:
'//   If you use the AP_PrimaryLogonId/AP_ClientLogonId flag,
'//   the system will capture the logon-id from the process/thread token.
'//

%AP_ParamTypeBits = 8
%AP_ParamTypeMask = &H000000ff???

'//
'// the flags values below have overlapping values. this is ok since
'// the scope of each flag is limited to the type to which it applies.
'//

'//
'// APT_Ulong : format flag : causes a number to appear in hex
'//

'#define AP_FormatHex      (0x0001L << AP_ParamTypeBits)
%AP_FormatHex = &H00000100???

'//
'// APT_Ulong : format flag : causes a number to be treated as access-mask.
'//                           The meaning of each bit depends on the associated
'//                           object type.
'//

'#define AP_AccessMask     (0x0002L << AP_ParamTypeBits)
%AP_AccessMask = &H00000200???


'//
'// APT_String : format flag : causes a string to be treated as a file-path
'//

'#define AP_Filespec       (0x0001L << AP_ParamTypeBits)
%AP_Filespec = &H00000100???

'//
'// APT_LogonId : control flag : logon-id is captured from the process token
'//

'#define AP_PrimaryLogonId (0x0001L << AP_ParamTypeBits)
%AP_PrimaryLogonId = &H00000100???

'//
'// APT_LogonId : control flag : logon-id is captured from the thread token
'//

'#define AP_ClientLogonId  (0x0002L << AP_ParamTypeBits)
%AP_ClientLogonId = &H00000200???


'//
'// internal helper macros
'//

'#define ApExtractType(TypeFlags)  ((AUDIT_PARAM_TYPE)(TypeFlags & AP_ParamTypeMask))
'#define ApExtractFlags(TypeFlags) ((TypeFlags & ~AP_ParamTypeMask))

MACRO ApExtractType(TypeFlags) = TypeFlags AND %AP_ParamTypeMask
MACRO ApExtractFlags(TypeFlags) = TypeFlags AND NOT %AP_ParamTypeMask

'//
'// Element of an object-type-list
'//
'// The AUDIT_OBJECT_TYPES structure identifies an object type element
'// in a hierarchy of object types. The AccessCheckByType functions use
'// an array of such structures to define a hierarchy of an object and
'// its subobjects, such as property sets and properties.
'//

' // Size = 24 bytes
TYPE AUDIT_OBJECT_TYPE DWORD FILL
   ObjectType AS GUID          ' GUID   // guid of the (sub)object
   Flags      AS WORD          ' USHORT // currently not defined
   Level      AS WORD          ' USHORT // level within the hierarchy.
                               '        // 0 is the root level
   AccessMask AS ACCESS_MASK   '        // ACCESS_MASK access-mask for this (sub)object
END TYPE

' // Size = 8 bytes
TYPE AUDIT_OBJECT_TYPES DWORD FILL
   Count        AS WORD                    ' USHORT // number of object-types in pObjectTypes
   Flags        AS WORD                    ' USHORT // currently not defined
   pObjectTypes AS AUDIT_OBJECT_TYPE PTR   ' AUDIT_OBJECT_TYPE* // array of object-types
END TYPE


'//
'// Maximum size of the SOCKADDR_STORAGE structure
'//

%AUTHZ_SS_MAXSIZE = 128                ' // Maximum size


' // Size = 128 bytes
TYPE AUDIT_IP_ADDRESS
   pIpAddress AS STRING * %AUTHZ_SS_MAXSIZE   ' BYTE pIpAddress[_AUTHZ_SS_MAXSIZE];
END TYPE

'//
'// Structure that defines a single audit parameter.
'//
'// LsaGenAuditEvent accepts an array of such elements to
'// represent the parameters of the audit to be generated.
'//
'// It is best to initialize this structure using AdtInitParams function.
'// This will ensure compatibility with any future changes to this
'// structure.
'//

' // Size = 4 bytes
UNION AUDIT_PARAM_UNION_1 DWORD
   Data0           AS DWORD                    ' ULONG_PTR
   String          AS WSTRINGZ PTR             ' PWSTR
   u               AS DWORD                    ' ULONG_PTR
   psid            AS SID PTR                  ' SID*
   pguid           AS GUID PTR                 ' GUID*
   LogonId_LowPart AS DWORD                    ' ULONG
   pObjectTypes    AS AUDIT_OBJECT_TYPES PTR   ' AUDIT_OBJECT_TYPES*
   pIpAddress      AS AUDIT_IP_ADDRESS PTR     ' AUDIT_IP_ADDRESS*
END UNION

' // Size = 4 bytes
UNION AUDIT_PARAM_UNION_2 DWORD
   Data1            AS DWORD   ' ULONG_PTR
   LogonId_HighPart AS LONG    ' LONG
END UNION

' // Size = 20 bytes
TYPE AUDIT_PARAM DWORD
   Type   AS AUDIT_PARAM_TYPE_ENUM   ' AUDIT_PARAM_TYPE // type
   Length AS DWORD                   ' ULONG // currently unused
   Flags  AS DWORD                   ' DWORD // currently unused
   AUDIT_PARAM_UNION_1
   AUDIT_PARAM_UNION_2
END TYPE

'//
'// Audit control flags. To be used with AUDIT_PARAMS.Flags
'//

%APF_AuditFailure = &H00000000???  ' // generate a failure audit
%APF_AuditSuccess = &H00000001???  ' // generate a success audit when set,
                                   ' // a failure audit otherwise.

'//
'// set of valid audit control flags
'//

%APF_ValidFlags = %APF_AuditSuccess

'//
'// Audit parameters passed to LsaGenAuditEvent
'//

' // Size = 16 bytes
TYPE AUDIT_PARAMS DWORD FILL
   Length     AS DWORD             ' ULONG // size in bytes
   Flags      AS DWORD             ' DWORD // currently unused
   Count      AS WORD              ' USHORT // number of parameters
   Parameters AS AUDIT_PARAM PTR   ' AUDIT_PARAM* // array of parameters
END TYPE

'//
'// Defines the elements of a legacy audit event.
'//

' // Size: 6 bytes
TYPE AUTHZ_AUDIT_EVENT_TYPE_LEGACY WORD
   CategoryId     AS WORD   ' USHORT
   AuditId        AS WORD   ' USHORT
   ParameterCount AS WORD   ' USHORT
END TYPE

' // Size = 6 bytes
UNION AUTHZ_AUDIT_EVENT_TYPE_UNION WORD
   Legacy AS AUTHZ_AUDIT_EVENT_TYPE_LEGACY
END UNION

'//
'// description of an audit event
'//

' // Size = 32 bytes
TYPE AUTHZ_AUDIT_EVENT_TYPE_OLD DWORD
   Version  AS DWORD   ' ULONG
   dwFlags  AS DWORD   ' DWORD
   RefCount AS LONG    ' LONG
   hAudit   AS DWORD   ' ULONG_PTR
   LinkId   AS QUAD    ' LUID
   u        AS AUTHZ_AUDIT_EVENT_TYPE_UNION
END TYPE

'//
'// Begin support for extensible auditing.
'//

'//
'// Registration Flags.
'//

%AUTHZ_ALLOW_MULTIPLE_SOURCE_INSTANCES = &H1
%AUTHZ_MIGRATED_LEGACY_PUBLISHER       = &H2

'//
'// Audit Generation Flags.
'//

%AUTHZ_AUDIT_INSTANCE_INFORMATION = &H2
