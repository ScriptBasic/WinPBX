' ########################################################################################
' Microsoft Windows
' File: winsafer.inc
' Contents: This file implements the publicly exported functions, data types, data
' structures, and definitions usable by programs that directly interact with the Windows
' SAFER APIs.
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%WINSAFER_INC = 1

#INCLUDE ONCE "guiddef.inc"
#INCLUDE ONCE "wincrypt.inc"

'//
'// Opaque datatype for representing handles to Safer objects.
'//

'DECLARE_HANDLE(SAFER_LEVEL_HANDLE);


'//
'// Constants to represent scope with SaferCreateLevel and others.
'//

%SAFER_SCOPEID_MACHINE = 1
%SAFER_SCOPEID_USER    = 2


'//
'// Pre-defined levels that can be used with SaferCreateLevel
'//

%SAFER_LEVELID_FULLYTRUSTED = &H40000???
%SAFER_LEVELID_NORMALUSER   = &H20000???
%SAFER_LEVELID_CONSTRAINED  = &H10000???
%SAFER_LEVELID_UNTRUSTED    = &H01000???
%SAFER_LEVELID_DISALLOWED   = &H00000???

'//
'// Flags to use when creating/opening a Level with SaferCreateLevel
'//

%SAFER_LEVEL_OPEN = 1


'//
'// Maximum string size.
'//

%SAFER_MAX_FRIENDLYNAME_SIZE = 256
%SAFER_MAX_DESCRIPTION_SIZE  = 256
%SAFER_MAX_HASH_SIZE         = 64

'//
'// Flags to use with SaferComputeTokenFromLevel.
'//

%SAFER_TOKEN_NULL_IF_EQUAL   = &H00000001???
%SAFER_TOKEN_COMPARE_ONLY    = &H00000002???
%SAFER_TOKEN_MAKE_INERT      = &H00000004???
%SAFER_TOKEN_WANT_FLAGS      = &H00000008???

'//
'// Flags for specifying what criteria within SAFER_CODE_PROPERTIES to evaluate
'// when finding code identity with SaferIdentifyLevel.
'//

%SAFER_CRITERIA_IMAGEPATH    = &H00001???
%SAFER_CRITERIA_NOSIGNEDHASH = &H00002???
%SAFER_CRITERIA_IMAGEHASH    = &H00004???
%SAFER_CRITERIA_AUTHENTICODE = &H00008???
%SAFER_CRITERIA_URLZONE      = &H00010???
%SAFER_CRITERIA_IMAGEPATH_NT = &H01000???

'//
'// Code image information structure passed to SaferIdentifyLevel.
'//

'#include <pshpack8.h>

' // Size = 112 bytes
TYPE SAFER_CODE_PROPERTIES   ' Must be 8 byte aligned
   cbSize           AS DWORD                     ' DWORD
   dwCheckFlags     AS DWORD                     ' DWORD
   ImagePath        AS WSTRINGZ PTR              ' LPCWSTR
   hImageFileHandle AS DWORD                     ' HANDLE
   UrlZoneId        AS DWORD                     ' DWORD
   ImageHash(%SAFER_MAX_HASH_SIZE - 1) AS BYTE   ' BYTE[SAFER_MAX_HASH_SIZE]
   dwImageHashSize  AS DWORD                     ' DWORD
   ImageSize        AS QUAD                      ' LARGE_INTEGER
   HashAlgorithm    AS DWORD                     ' ALG_ID
   pByteBlock       AS BYTE PTR                  ' LPBYTE
   hWndParent       AS DWORD                     ' HWND
   dwWVTUIChoice    AS DWORD                     ' DWORD
END TYPE

'#include <poppack.h>

'//
'// Masks for the per-identity WinSafer flags
'//

%SAFER_POLICY_JOBID_MASK                  = &HFF000000???
%SAFER_POLICY_JOBID_CONSTRAINED           = &H04000000???
%SAFER_POLICY_JOBID_UNTRUSTED             = &H03000000???
%SAFER_POLICY_ONLY_EXES                   = &H00010000???
%SAFER_POLICY_SANDBOX_INERT               = &H00020000???
%SAFER_POLICY_HASH_DUPLICATE              = &H00040000???
%SAFER_POLICY_ONLY_AUDIT                  = &H00001000???
%SAFER_POLICY_BLOCK_CLIENT_UI             = &H00002000???
%SAFER_POLICY_UIFLAGS_MASK                = &H000000FF???
%SAFER_POLICY_UIFLAGS_INFORMATION_PROMPT  = &H00000001???
%SAFER_POLICY_UIFLAGS_OPTION_PROMPT       = &H00000002???
%SAFER_POLICY_UIFLAGS_HIDDEN              = &H00000004???

'//
'// Information classes on the overall policy that can be queried
'// with SaferSet/GetPolicyInformation and set at different
'// policy scopes based on access of the caller.
'//

' enum SAFER_POLICY_INFO_CLASS

'//
'// Accesses the list of all Levels defined in a policy.
'// The corresponding data element is a buffer that is filled
'// with multiple DWORDs, each representing the LevelIds that
'// are defined within this scope.
'//

%SaferPolicyLevelList = 1

'//
'// for transparent enforcement of policy in the execution
'// framework -- will be used by native code execution but can
'// be used by any policy enforcement environment.
'// Corresponding data element is a DWORD holding a Boolean value.
'//

%SaferPolicyEnableTransparentEnforcement = 2

'//
'// Returns the name of the Level that has been designed
'// as the default level within the specified scope.
'// The corresponding data element is a single DWORD buffer
'// representing the LevelId of the default Level.  If no
'// level has been configured to be the default, then the
'// GetInfo API will return FALSE and GetLastError will
'// return ERROR_NOT_FOUND.
'//

%SaferPolicyDefaultLevel = 3

'//
'// Returns whether Code Identities or Default Level within the
'// user scope can be considered during identification.
'//

%SaferPolicyEvaluateUserScope = 4

'//
'// Control Flags for safer policy scope.
'//

%SaferPolicyScopeFlags = 5

'//
'// Flags which indicate "audit" or "block client UI" rules
'//

%SaferPolicyDefaultLevelFlags = 6

'//
'// Flag which indicates if certificate rules are applied in CreateProcess
'//

%SaferPolicyAuthenticodeEnabled = 7


'//
'// Enumerations used for retrieving specific information about a
'// single authorization Level via SaferGet/SetInformationFromLevel.
'//

' enum SAFER_OBJECT_INFO_CLASS

%SaferObjectLevelId = 1???                    ' // get: DWORD
%SaferObjectScopeId = 2???                    ' // get: DWORD
%SaferObjectFriendlyName = 3???               ' // get/set: LPCWSTR
%SaferObjectDescription = 4???                ' // get/set: LPCWSTR
%SaferObjectBuiltin = 5???                    ' // get: DWORD boolean

%SaferObjectDisallowed = 6???                 ' // get: DWORD boolean
%SaferObjectDisableMaxPrivilege = 7???        ' // get: DWORD boolean
%SaferObjectInvertDeletedPrivileges = 8???    ' // get: DWORD boolean
%SaferObjectDeletedPrivileges = 9???          ' // get: TOKEN_PRIVILEGES
%SaferObjectDefaultOwner = 10???              ' // get: TOKEN_OWNER
%SaferObjectSidsToDisable = 11???             ' // get: TOKEN_GROUPS
%SaferObjectRestrictedSidsInverted = 12???    ' // get: TOKEN_GROUPS
%SaferObjectRestrictedSidsAdded = 13???       ' // get: TOKEN_GROUPS

'//
'// To enumerate all identities, call GetInfo with
'//      SaferObjectAllIdentificationGuids.
'//

%SaferObjectAllIdentificationGuids = 14???   ' // get: SAFER_IDENTIFICATION_GUIDS

'//
'// To create a new identity, call SetInfo with
'//      SaferObjectSingleIdentification with a new
'//      unique GUID that you have generated.
'// To get details on a single identity, call GetInfo with
'//      SaferObjectSingleIdentification with desired GUID.
'// To modify details of a single identity, call SetInfo with
'//      SaferObjectSingleIdentification with desired info and GUID.
'// To delete an identity, call SetInfo with
'//      SaferObjectSingleIdentification with the
'//      header.dwIdentificationType set to 0.
'//

%SaferObjectSingleIdentification = 15???     ' // get/set: SAFER_IDENTIFICATION_*

%SaferObjectExtendedError = 16???            ' // get: DWORD dwError


'//
'// Structures and enums used by the SaferGet/SetLevelInformation APIs.
'//

'#include <pshpack8.h>

' enum SAFER_IDENTIFICATION_TYPES
%SaferIdentityDefault = 0
%SaferIdentityTypeImageName = 1
%SaferIdentityTypeImageHash = 2
%SaferIdentityTypeUrlZone = 3
%SaferIdentityTypeCertificate = 4

' // Size = 32 bytes
TYPE SAFER_IDENTIFICATION_HEADER   ' Must be 8 byte aligned
   dwIdentificationType AS LONG       ' SAFER_IDENTIFICATION_TYPES
   cbStructSize         AS DWORD      ' DWORD
   IdentificationGuid   AS GUID       ' GUID
   lastModified         AS FILETIME   ' FILETIME
END TYPE

' // Size = 552 bytes
TYPE SAFER_PATHNAME_IDENTIFICATION   ' Must be  8 byte aligned
   header       AS SAFER_IDENTIFICATION_HEADER              ' SAFER_IDENTIFICATION_HEADER
   Description  AS WSTRINGZ * %SAFER_MAX_DESCRIPTION_SIZE   ' WCHAR[SAFER_MAX_DESCRIPTION_SIZE]
   ImageName    AS WSTRINGZ PTR                             ' PWCHAR
   dwSaferFlags AS DWORD                                    ' DWORD
END TYPE

' // Size = 1144 bytes
TYPE SAFER_HASH_IDENTIFICATION   ' Must be 8 byte aligned
   header        AS SAFER_IDENTIFICATION_HEADER               ' SAFER_IDENTIFICATION_HEADER
   Description   AS WSTRINGZ * %SAFER_MAX_DESCRIPTION_SIZE    ' WCHAR[SAFER_MAX_DESCRIPTION_SIZE]
   FriendlyName  AS WSTRINGZ * %SAFER_MAX_FRIENDLYNAME_SIZE   ' WCHAR[SAFER_MAX_FRIENDLYNAME_SIZE]
   HashSize      AS DWORD                                     ' DWORD
   ImageHash(%SAFER_MAX_HASH_SIZE - 1) AS BYTE                ' BYTE[SAFER_MAX_HASH_SIZE]
   HashAlgorithm AS DWORD                                     ' ALG_ID
   ImageSize     AS QUAD                                      ' LARGE_INTEGER
   dwSaferFlags  AS DWORD                                     ' DWORD
   alignment__   AS DWORD                                     ' // To keep 8 byte alignment
END TYPE

' // Size = 1216 bytes
TYPE SAFER_HASH_IDENTIFICATION2   ' Must be 8 byte aligned
   hashIdentification AS SAFER_HASH_IDENTIFICATION   ' SAFER_HASH_IDENTIFICATION
   HashSize           AS DWORD                       ' DWORD
   ImageHash(%SAFER_MAX_HASH_SIZE - 1) AS BYTE       ' BYTE[SAFER_MAX_HASH_SIZE]
   HashAlgorithm      AS DWORD                       ' ALG_ID
END TYPE

' // Size = 40 bytes
TYPE SAFER_URLZONE_IDENTIFICATION   ' Must be 8 byte aligned
   header       AS SAFER_IDENTIFICATION_HEADER   ' SAFER_IDENTIFICATION_HEADER
   UrlZoneId    AS DWORD                         ' DWORD
   dwSaferFlags AS DWORD                         ' DWORD
END TYPE


'#include <poppack.h>

'//
'// Functions related to querying and setting the global policy
'// controls to disable transparent enforcement, and perform level
'// enumeration operations.
'//

DECLARE FUNCTION SaferGetPolicyInformation IMPORT "Advapi32.dll" ALIAS "SaferGetPolicyInformation" ( _
   BYVAL dwScopeId AS DWORD _                           ' __in DWORD dwScopeId
 , BYVAL SaferPolicyInfoClass AS LONG _                 ' __in SAFER_POLICY_INFO_CLASS SaferPolicyInfoClass
 , BYVAL InfoBufferSize AS DWORD _                      ' __in DWORD InfoBufferSize
 , BYREF InfoBuffer AS ANY _                            ' __out PVOID InfoBuffer
 , BYREF InfoBufferRetSize AS DWORD _                   ' __out PDWORD InfoBufferRetSize
 , BYVAL lpReserved AS DWORD _                          ' __reserved LPVOID lpReserved
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SaferSetPolicyInformation IMPORT "Advapi32.dll" ALIAS "SaferSetPolicyInformation" ( _
   BYVAL dwScopeId AS DWORD _                           ' __in DWORD dwScopeId
 , BYVAL SaferPolicyInfoClass AS LONG _                 ' __in SAFER_POLICY_INFO_CLASS SaferPolicyInfoClass
 , BYVAL InfoBufferSize AS DWORD _                      ' __in DWORD InfoBufferSize
 , BYREF InfoBuffer AS ANY _                            ' __in PVOID InfoBuffer
 , BYVAL lpReserved AS DWORD _                          ' __reserved LPVOID lpReserved
 ) AS LONG                                              ' BOOL

'//
'// Functions to open or close a handle to a Safer Level.
'//

DECLARE FUNCTION SaferCreateLevel IMPORT "Advapi32.dll" ALIAS "SaferCreateLevel" ( _
   BYVAL dwScopeId AS DWORD _                           ' __in DWORD dwScopeId
 , BYVAL dwLevelId AS DWORD _                           ' __in DWORD dwLevelId
 , BYVAL OpenFlags AS DWORD _                           ' __in DWORD OpenFlags
 , BYREF pLevelHandle AS DWORD _                        ' __out SAFER_LEVEL_HANDLE * pLevelHandle
 , BYVAL lpReserved AS DWORD _                          ' __reserved LPVOID lpReserved
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SaferCloseLevel IMPORT "Advapi32.dll" ALIAS "SaferCloseLevel" ( _
   BYVAL hLevelHandle AS DWORD _                        ' __in SAFER_LEVEL_HANDLE hLevelHandle
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SaferIdentifyLevel IMPORT "Advapi32.dll" ALIAS "SaferIdentifyLevel" ( _
   BYVAL dwNumProperties AS DWORD _                     ' __in DWORD dwNumProperties
 , BYREF pCodeProperties AS SAFER_CODE_PROPERTIES _     ' __in_opt PSAFER_CODE_PROPERTIES pCodeProperties
 , BYREF pLevelHandle AS DWORD _                        ' __out SAFER_LEVEL_HANDLE * pLevelHandle
 , BYVAL lpReserved AS DWORD _                          ' __in_opt LPVOID lpReserved
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SaferComputeTokenFromLevel IMPORT "Advapi32.dll" ALIAS "SaferComputeTokenFromLevel" ( _
   BYVAL LevelHandle AS DWORD _                         ' __in SAFER_LEVEL_HANDLE LevelHandle
 , BYVAL InAccessToken AS DWORD _                       ' __in_opt HANDLE InAccessToken
 , BYREF OutAccessToken AS DWORD _                      ' __out PHANDLE OutAccessToken
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYVAL lpReserved AS DWORD _                          ' __inout_opt LPVOID lpReserved
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SaferGetLevelInformation IMPORT "Advapi32.dll" ALIAS "SaferGetLevelInformation" ( _
   BYVAL LevelHandle AS DWORD _                         ' __in SAFER_LEVEL_HANDLE LevelHandle
 , BYVAL dwInfoType AS DWORD _                          ' __in SAFER_OBJECT_INFO_CLASS dwInfoType
 , BYREF lpQueryBuffer AS ANY _                         ' __out LPVOID lpQueryBuffer
 , BYVAL dwInBufferSize AS DWORD _                      ' __in DWORD dwInBufferSize
 , BYREF lpdwOutBufferSize AS DWORD _                   ' __out LPDWORD lpdwOutBufferSize
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SaferSetLevelInformation IMPORT "Advapi32.dll" ALIAS "SaferSetLevelInformation" ( _
   BYVAL LevelHandle AS DWORD _                         ' __in SAFER_LEVEL_HANDLE LevelHandle
 , BYVAL dwInfoType AS DWORD _                          ' __in SAFER_OBJECT_INFO_CLASS dwInfoType
 , BYREF lpQueryBuffer AS ANY _                         ' __out LPVOID lpQueryBuffer
 , BYVAL DdwInBufferSize AS WORD _                      ' __in DWORD dwInBufferSize
 ) AS LONG                                              ' BOOL

'//
'// This function performs logging of messages to the Application
'// event log.  This is called by the hooks within CreateProcess,
'// ShellExecute and cmd when a lower trust evaluation result occurs.
'//

DECLARE FUNCTION SaferRecordEventLogEntry IMPORT "Advapi32.dll" ALIAS "SaferRecordEventLogEntry" ( _
   BYVAL LevelHandle AS DWORD _                         ' __in SAFER_LEVEL_HANDLE LevelHandle
 , BYREF szTargetPath AS WSTRINGZ _                     ' __in LPCWSTR szTargetPath
 , BYVAL lpReserved AS DWORD _                          ' __reserved LPVOID lpReserved
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SaferiIsExecutableFileType IMPORT "Advapi32.dll" ALIAS "SaferiIsExecutableFileType" ( _
   BYREF szFullPathname AS WSTRINGZ _                   ' __in LPCWSTR szFullPathname
 , BYVAL bFromShellExecute AS BYTE _                    ' __in BOOLEAN bFromShellExecute
 ) AS LONG                                              ' BOOL

$$SRP_POLICY_EXE      = "EXE"$$
$$SRP_POLICY_DLL      = "DLL"$$
$$SRP_POLICY_MSI      = "MSI"$$
$$SRP_POLICY_SCRIPT   = "SCRIPT"$$
$$SRP_POLICY_SHELL    = "SHELL"$$
$$SRP_POLICY_NOV2     = "IGNORESRPV2"$$
