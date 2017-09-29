' ########################################################################################
' Microsoft Windows
' File: AclApi.inc
' Contents: Structure/constant definitions and typedefines for the Win32 Access Control APIs
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%ACLAPI_INC = 1

#INCLUDE ONCE "windows.inc"
#INCLUDE ONCE "accctrl.inc"

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

'typedef VOID (*FN_PROGRESS) (
'    __in LPWSTR                   pObjectName,    // name of object just processed
'    __in DWORD                    Status,         // status of operation on object
'    __in OUT PPROG_INVOKE_SETTING pInvokeSetting, // Never, always,
'    __in PVOID                    Args,           // Caller specific data
'    __in BOOL                     SecuritySet     // Whether security was set
'    );

'DECLARE SUB FN_PROGRESS ( _
'   BYREF pObjectName    AS WSTRINGZ _                  ' __in LPWSTR pObjectName // name of object just processed
' , BYVAL Status         AS DWORD _                     ' __in DWORD Status // status of operation on object
' , BYREF pInvokeSetting AS PROG_INVOKE_SETTING_ENUM _  ' __in OUT PPROG_INVOKE_SETTING pInvokeSetting, // Never, always,
' , BYVAL Args           AS DWORD _                     ' __in PVOID Args // Caller specific data
' , BYVAL SecuritySet    AS LONG _                      ' __in BOOL SecuritySet // Whether security was set
' )                                                     ' void

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SetEntriesInAclA LIB "ADVAPI32.DLL" _
   ALIAS "SetEntriesInAclA" ( _
    BYVAL cCountOfExplicitEntries AS DWORD, _
    BYVAL pListOfExplicitEntries  AS EXPLICIT_ACCESS_A PTR, _
    BYVAL OldAcl                  AS ACL PTR, _
    NewAcl                        AS DWORD _   ' ACL PTR PTR
    ) AS DWORD
#ELSE
DECLARE FUNCTION SetEntriesInAclA IMPORT "ADVAPI32.DLL" ALIAS "SetEntriesInAclA" ( _
   BYVAL cCountOfExplicitEntries AS DWORD _             ' __in ULONG cCountOfExplicitEntries
 , BYREF pListOfExplicitEntries AS EXPLICIT_ACCESS_A _  ' __in PEXPLICIT_ACCESS_A pListOfExplicitEntries
 , BYVAL OldAcl AS ACL PTR _                            ' __in_opt PACL OldAcl
 , BYREF NewAcl AS DWORD _                              ' __out PACL *NewAcl
 ) AS DWORD                                             ' DWORD
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SetEntriesInAclW LIB "ADVAPI32.DLL" _
   ALIAS "SetEntriesInAclW" ( _
    BYVAL cCountOfExplicitEntries AS DWORD, _
    BYVAL pListOfExplicitEntries  AS EXPLICIT_ACCESS_W PTR, _
    BYVAL OldAcl                  AS ACL PTR, _
    NewAcl                        AS DWORD _   ' ACL PTR PTR
    ) AS DWORD
#ELSE
DECLARE FUNCTION SetEntriesInAclW IMPORT "ADVAPI32.DLL" ALIAS "SetEntriesInAclW" ( _
   BYVAL cCountOfExplicitEntries AS DWORD _             ' __in ULONG cCountOfExplicitEntries
 , BYREF pListOfExplicitEntries AS EXPLICIT_ACCESS_W _  ' __in PEXPLICIT_ACCESS_W pListOfExplicitEntries
 , BYVAL OldAcl AS ACL PTR _                            ' __in_opt PACL OldAcl
 , BYREF NewAcl AS DWORD _                              ' __out PACL *NewAcl
 ) AS DWORD                                             ' DWORD
#ENDIF

#IF %DEF(%UNICODE)
MACRO SetEntriesInAcl = SetEntriesInAclW
#ELSE
MACRO SetEntriesInAcl = SetEntriesInAclA
#ENDIF

DECLARE FUNCTION GetExplicitEntriesFromAclA IMPORT "ADVAPI32.DLL" ALIAS "GetExplicitEntriesFromAclA" ( _
   BYVAL pacl AS ACL PTR _                              ' __in PACL pacl
 , BYREF pcCountOfExplicitEntries AS DWORD _            ' __out PULONG pcCountOfExplicitEntries
 , BYREF pListOfExplicitEntries AS DWORD _              ' __out PEXPLICIT_ACCESS_A *pListOfExplicitEntries
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION GetExplicitEntriesFromAclW IMPORT "ADVAPI32.DLL" ALIAS "GetExplicitEntriesFromAclW" ( _
   BYVAL Apacl AS ACL PTR _                             ' __in PACL pacl
 , BYREF pcCountOfExplicitEntries AS DWORD _            ' __out PULONG pcCountOfExplicitEntries
 , BYREF pListOfExplicitEntries AS DWORD _              ' __out PEXPLICIT_ACCESS_W *pListOfExplicitEntries
 ) AS DWORD                                             ' DWORD

#IF %DEF(%UNICODE)
MACRO GetExplicitEntriesFromAcl = GetExplicitEntriesFromAclW
#ELSE
MACRO GetExplicitEntriesFromAcl = GetExplicitEntriesFromAclA
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION GetEffectiveRightsFromAclA LIB "ADVAPI32.DLL" _
   ALIAS "GetEffectiveRightsFromAclA" ( _
    pacl          AS ACL, _
    pTrustee      AS TRUSTEE_A, _
    pAccessRights AS DWORD _
    ) AS DWORD
#ELSE
DECLARE FUNCTION GetEffectiveRightsFromAclA IMPORT "ADVAPI32.DLL" ALIAS "GetEffectiveRightsFromAclA" ( _
   BYVAL pacl AS ACL PTR _                              ' __in PACL pacl
 , BYREF pTrustee AS TRUSTEE_A _                        ' __in PTRUSTEE_A pTrustee
 , BYREF pAccessRights AS ACCESS_MASK _                 ' __out PACCESS_MASK pAccessRights
 ) AS DWORD                                             ' DWORD
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION GetEffectiveRightsFromAclW LIB "ADVAPI32.DLL" _
   ALIAS "GetEffectiveRightsFromAclW" ( _
    pacl          AS ACL, _
    pTrustee      AS TRUSTEE_W, _
    pAccessRights AS DWORD _
    ) AS DWORD
#ELSE
DECLARE FUNCTION GetEffectiveRightsFromAclW IMPORT "ADVAPI32.DLL" ALIAS "GetEffectiveRightsFromAclW" ( _
   BYVAL pacl AS ACL PTR _                              ' __in PACL pacl
 , BYREF pTrustee AS TRUSTEE_W _                        ' __in PTRUSTEE_W pTrustee
 , BYREF pAccessRights AS ACCESS_MASK _                 ' __out PACCESS_MASK pAccessRights
 ) AS DWORD                                             ' DWORD
#ENDIF

#IF %DEF(%UNICODE)
MACRO GetEffectiveRightsFromAcl = GetEffectiveRightsFromAclW
#ELSE
MACRO GetEffectiveRightsFromAcl = GetEffectiveRightsFromAclA
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION GetAuditedPermissionsFromAclA LIB "ADVAPI32.DLL" _
   ALIAS "GetAuditedPermissionsFromAclA" ( _
    pacl                     AS ACL, _
    pTrustee                 AS TRUSTEE_A, _
    pSuccessfulAuditedRights AS DWORD, _
    pFailedAuditRights       AS DWORD _
    ) AS DWORD
#ELSE
DECLARE FUNCTION GetAuditedPermissionsFromAclA IMPORT "ADVAPI32.DLL" ALIAS "GetAuditedPermissionsFromAclA" ( _
   BYVAL pacl AS ACL PTR _                              ' __in PACL pacl
 , BYREF pTrustee AS TRUSTEE_A _                        ' __in PTRUSTEE_A pTrustee
 , BYREF pSuccessfulAuditedRights AS ACCESS_MASK _      ' __out PACCESS_MASK pSuccessfulAuditedRights
 , BYREF pFailedAuditRights AS ACCESS_MASK _            ' __out PACCESS_MASK pFailedAuditRights
 ) AS DWORD                                             ' DWORD
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION GetAuditedPermissionsFromAclW LIB "ADVAPI32.DLL" _
   ALIAS "GetAuditedPermissionsFromAclW" ( _
    pacl                     AS ACL, _
    pTrustee                 AS TRUSTEE_W, _
    pSuccessfulAuditedRights AS DWORD, _
    pFailedAuditRights       AS DWORD _
    ) AS DWORD
#ELSE
DECLARE FUNCTION GetAuditedPermissionsFromAclW IMPORT "ADVAPI32.DLL" ALIAS "GetAuditedPermissionsFromAclW" ( _
   BYVAL pacl AS ACL PTR _                              ' __in PACL pacl
 , BYREF pTrustee AS TRUSTEE_W _                        ' __in PTRUSTEE_W pTrustee
 , BYREF pSuccessfulAuditedRights AS ACCESS_MASK _      ' __out PACCESS_MASK pSuccessfulAuditedRights
 , BYREF pFailedAuditRights AS ACCESS_MASK _            ' __out PACCESS_MASK pFailedAuditRights
 ) AS DWORD                                             ' DWORD
#ENDIF

#IF %DEF(%UNICODE)
MACRO GetAuditedPermissionsFromAcl = GetAuditedPermissionsFromAclW
#ELSE
MACRO GetAuditedPermissionsFromAcl = GetAuditedPermissionsFromAclA
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION GetNamedSecurityInfoA LIB "ADVAPI32.DLL" _
   ALIAS "GetNamedSecurityInfoA" ( _
    pObjectName          AS ASCIIZ, _
    BYVAL ObjectType     AS SE_OBJECT_TYPE_enum, _
    BYVAL SecurityInfo   AS SECURITY_INFORMATION, _
    ppsidOwner           AS DWORD, _   ' SID PTR PTR
    ppsidGroup           AS DWORD, _   ' SID PTR PTR
    ppDacl               AS DWORD, _   ' ACL PTR PTR
    ppSacl               AS DWORD, _   ' ACL PTR PTR
    ppSecurityDescriptor AS DWORD _    ' SECURITY_DESCRIPTOR PTR PTR
    ) AS DWORD
#ELSE
DECLARE FUNCTION GetNamedSecurityInfoA IMPORT "ADVAPI32.DLL" ALIAS "GetNamedSecurityInfoA" ( _
   BYREF pObjectName AS ASCIIZ _                        ' __in LPCSTR pObjectName
 , BYVAL ObjectType AS SE_OBJECT_TYPE_ENUM _            ' __in SE_OBJECT_TYPE ObjectType
 , BYVAL SecurityInfo AS SECURITY_INFORMATION _         ' __in SECURITY_INFORMATION SecurityInfo
 , OPTIONAL BYREF ppsidOwner AS DWORD _                 ' __out_opt const PSID *ppsidOwner
 , OPTIONAL BYREF ppsidGroup AS DWORD _                 ' __out_opt const PSID *ppsidGroup
 , OPTIONAL BYREF ppDacl AS DWORD _                     ' __out_opt const PACL *ppDacl
 , OPTIONAL BYREF ppSacl AS DWORD _                     ' __out_opt const PACL *ppSacl
 , OPTIONAL BYREF ppSecurityDescriptor AS DWORD _       ' __out PSECURITY_DESCRIPTOR *ppSecurityDescriptor
 ) AS DWORD                                             ' DWORD
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION GetNamedSecurityInfoW LIB "ADVAPI32.DLL" _
   ALIAS "GetNamedSecurityInfoW" ( _
    pObjectName          AS WSTRINGZ, _
    BYVAL ObjectType     AS SE_OBJECT_TYPE_enum, _
    BYVAL SecurityInfo   AS SECURITY_INFORMATION, _
    ppsidOwner           AS DWORD, _   ' SID PTR PTR
    ppsidGroup           AS DWORD, _   ' SID PTR PTR
    ppDacl               AS DWORD, _   ' ACL PTR PTR
    ppSacl               AS DWORD, _   ' ACL PTR PTR
    ppSecurityDescriptor AS DWORD _    ' SECURITY_DESCRIPTOR PTR PTR
    ) AS DWORD
#ELSE
DECLARE FUNCTION GetNamedSecurityInfoW IMPORT "ADVAPI32.DLL" ALIAS "GetNamedSecurityInfoW" ( _
   BYREF pObjectName AS WSTRINGZ _                      ' __in LPCWSTR pObjectName
 , BYVAL ObjectType AS SE_OBJECT_TYPE_ENUM _            ' __in SE_OBJECT_TYPE ObjectType
 , BYVAL SecurityInfo AS SECURITY_INFORMATION _         ' __in SECURITY_INFORMATION SecurityInfo
 , OPTIONAL BYREF ppsidOwner AS DWORD _                 ' __out_opt const PSID *ppsidOwner
 , OPTIONAL BYREF ppsidGroup AS DWORD _                 ' __out_opt const PSID *ppsidGroup
 , OPTIONAL BYREF ppDacl AS DWORD _                     ' __out_opt const PACL *ppDacl
 , OPTIONAL BYREF ppSacl AS DWORD _                     ' __out_opt const PACL *ppSacl
 , OPTIONAL BYREF ppSecurityDescriptor AS DWORD _       ' __out PSECURITY_DESCRIPTOR *ppSecurityDescriptor
 ) AS DWORD                                             ' DWORD
#ENDIF

#IF %DEF(%UNICODE)
MACRO GetNamedSecurityInfo = GetNamedSecurityInfoW
#ELSE
MACRO GetNamedSecurityInfo = GetNamedSecurityInfoA
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION GetSecurityInfo LIB "ADVAPI32.DLL" _
   ALIAS "GetSecurityInfo" ( _
    BYVAL shandle        AS DWORD, _
    BYVAL ObjectType     AS SE_OBJECT_TYPE_enum, _
    BYVAL SecurityInfo   AS SECURITY_INFORMATION, _
    ppsidOwner           AS DWORD, _   ' SID PTR PTR
    ppsidGroup           AS DWORD, _   ' SID PTR PTR
    ppDacl               AS DWORD, _   ' ACL PTR PTR
    ppSacl               AS DWORD, _   ' ACL PTR PTR
    ppSecurityDescriptor AS DWORD _    ' SECURITY_DESCRIPTOR PTR PTR
    ) AS DWORD
#ELSE
DECLARE FUNCTION GetSecurityInfo IMPORT "ADVAPI32.DLL" ALIAS "GetSecurityInfo" ( _
   BYVAL handle AS DWORD _                              ' __in HANDLE handle
 , BYVAL ObjectType AS SE_OBJECT_TYPE_ENUM _            ' __in SE_OBJECT_TYPE ObjectType
 , BYVAL SecurityInfo AS SECURITY_INFORMATION _         ' __in SECURITY_INFORMATION SecurityInfo
 , OPTIONAL BYREF ppsidOwner AS DWORD _                 ' __out_opt PSID *ppsidOwner
 , OPTIONAL BYREF ppsidGroup AS DWORD _                 ' __out_opt PSID *ppsidGroup
 , OPTIONAL BYREF ppDacl AS DWORD _                     ' __out_opt PACL *ppDacl
 , OPTIONAL BYREF ppSacl AS DWORD _                     ' __out_opt PACL *ppSacl
 , OPTIONAL BYREF ppSecurityDescriptor AS DWORD _       ' __PSECURITY_DESCRIPTOR *ppSecurityDescriptor
 ) AS DWORD                                             ' DWORD
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SetNamedSecurityInfoA LIB "ADVAPI32.DLL" _
   ALIAS "SetNamedSecurityInfoA" ( _
    pObjectName        AS ASCIIZ, _
    BYVAL ObjectType   AS SE_OBJECT_TYPE_enum, _
    BYVAL SecurityInfo AS SECURITY_INFORMATION, _
    ppsidOwner         AS DWORD, _   ' SID PTR PTR
    ppsidGroup         AS DWORD, _   ' SID PTR PTR
    ppDacl             AS DWORD, _   ' ACL PTR PTR
    ppSacl             AS DWORD _    ' ACL PTR PTR
    ) AS DWORD
#ELSE
DECLARE FUNCTION SetNamedSecurityInfoA IMPORT "ADVAPI32.DLL" ALIAS "SetNamedSecurityInfoA" ( _
   BYREF pObjectName AS ASCIIZ _                        ' __in LPSTR pObjectName
 , BYVAL ObjectType AS SE_OBJECT_TYPE_ENUM _            ' __in SE_OBJECT_TYPE ObjectType
 , BYVAL SecurityInfo AS SECURITY_INFORMATION _         ' __in SECURITY_INFORMATION SecurityInfo
 , OPTIONAL BYVAL psidOwner AS SID PTR _                ' __in_opt PSID psidOwner
 , OPTIONAL BYVAL psidGroup AS SID PTR _                ' __in_opt PSID psidGroup
 , OPTIONAL BYVAL pDacl AS ACL PTR _                    ' __in_opt PACL pDacl
 , OPTIONAL BYVAL pSacl AS ACL PTR _                    ' __in_opt PACL pSacl
 ) AS DWORD                                             ' DWORD
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SetNamedSecurityInfoW LIB "ADVAPI32.DLL" _
   ALIAS "SetNamedSecurityInfoW" ( _
    pObjectName        AS WSTRINGZ, _
    BYVAL ObjectType   AS SE_OBJECT_TYPE_enum, _
    BYVAL SecurityInfo AS SECURITY_INFORMATION, _
    ppsidOwner         AS DWORD, _   ' SID PTR PTR
    ppsidGroup         AS DWORD, _   ' SID PTR PTR
    ppDacl             AS DWORD, _   ' ACL PTR PTR
    ppSacl             AS DWORD _    ' ACL PTR PTR
    ) AS DWORD
#ELSE
DECLARE FUNCTION SetNamedSecurityInfoW IMPORT "ADVAPI32.DLL" ALIAS "SetNamedSecurityInfoW" ( _
   BYREF pObjectName AS WSTRINGZ _                      ' __in LPWSTR pObjectName
 , BYVAL ObjectType AS SE_OBJECT_TYPE_ENUM _            ' __in SE_OBJECT_TYPE ObjectType
 , BYVAL SecurityInfo AS SECURITY_INFORMATION _         ' __in SECURITY_INFORMATION SecurityInfo
 , OPTIONAL BYVAL psidOwner AS SID PTR _                ' __in_opt PSID psidOwner
 , OPTIONAL BYVAL psidGroup AS SID PTR _                ' __in_opt PSID psidGroup
 , OPTIONAL BYVAL pDacl AS ACL PTR _                    ' __in_opt PACL pDacl
 , OPTIONAL BYVAL pSacl AS ACL PTR _                    ' __in_opt PACL pSacl
 ) AS DWORD                                             ' DWORD
#ENDIF

#IF %DEF(%UNICODE)
MACRO SetNamedSecurityInfo = SetNamedSecurityInfoW
#ELSE
MACRO SetNamedSecurityInfo = SetNamedSecurityInfoA
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SetSecurityInfo LIB "ADVAPI32.DLL" _
   ALIAS "SetSecurityInfo" ( _
    BYVAL shandle      AS DWORD, _
    BYVAL ObjectType   AS SE_OBJECT_TYPE_enum, _
    BYVAL SecurityInfo AS SECURITY_INFORMATION, _
    ppsidOwner         AS DWORD, _   ' SID PTR PTR
    ppsidGroup         AS DWORD, _   ' SID PTR PTR
    ppDacl             AS DWORD, _   ' ACL PTR PTR
    ppSacl             AS DWORD _    ' ACL PTR PTR
    ) AS DWORD
#ELSE
DECLARE FUNCTION SetSecurityInfo IMPORT "ADVAPI32.DLL" ALIAS "SetSecurityInfo" ( _
   BYVAL handle AS DWORD _                              ' __in HANDLE handle
 , BYVAL ObjectType AS SE_OBJECT_TYPE_ENUM _            ' __in SE_OBJECT_TYPE ObjectType
 , BYVAL SecurityInfo AS SECURITY_INFORMATION _         ' __in SECURITY_INFORMATION SecurityInfo
 , BYVAL psidOwner AS SID PTR _                         ' __in PSID psidOwner
 , BYVAL psidGroup AS SID PTR _                         ' __in PSID psidGroup
 , BYVAL pDacl AS ACL PTR _                             ' __in PACL pDacl
 , BYVAL pSacl AS ACL PTR _                             ' __in PACL pSacl
 ) AS DWORD                                             ' DWORD
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION GetInheritanceSourceA LIB "ADVAPI32.DLL" _
   ALIAS "GetInheritanceSourceA" ( _
    pObjectName          AS ASCIIZ, _
    BYVAL ObjectType     AS SE_OBJECT_TYPE_enum, _
    BYVAL SecurityInfo   AS SECURITY_INFORMATION, _
    BYVAL Container      AS LONG, _
    pObjectClassGuids    AS DWORD, _   ' GUID PTR PTR
    BYVAL GuidCount      AS DWORD, _
    pAcl                 AS ACL, _
    pfnArray             AS DWORD, _   ' OBJECT_MGR_FUNCTS PTR
    pGenericMapping      AS GENERIC_MAPPING, _
    pInheritArray        AS DWORD _    ' INHERITED_FROM PTR (to one or more)
    ) AS DWORD
#ELSE
DECLARE FUNCTION GetInheritanceSourceA IMPORT "ADVAPI32.DLL" ALIAS "GetInheritanceSourceA" ( _
   BYREF pObjectName AS ASCIIZ _                        ' __in LPSTR pObjectName
 , BYVAL ObjectType AS SE_OBJECT_TYPE_ENUM _            ' __in SE_OBJECT_TYPE ObjectType
 , BYVAL SecurityInfo AS SECURITY_INFORMATION _         ' __in SECURITY_INFORMATION SecurityInfo
 , BYVAL Container AS LONG _                            ' __in BOOL Container
 , BYREF pObjectClassGuids AS GUID _                    ' __in_opt GUID	**pObjectClassGuids
 , BYVAL GuidCount AS DWORD _                           ' __in DWORD GuidCount
 , BYVAL pAcl AS ACL PTR _                              ' __in PACL pAcl
 , BYVAL pfnArray AS DWORD _                            ' __in_opt PFN_OBJECT_MGR_FUNCTS pfnArray
 , BYREF pGenericMapping AS GENERIC_MAPPING _           ' __in PGENERIC_MAPPING pGenericMapping
 , BYREF pInheritArray AS INHERITED_FROMA _             ' __out PINHERITED_FROMA pInheritArray
 ) AS DWORD                                             ' DWORD
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION GetInheritanceSourceW LIB "ADVAPI32.DLL" _
   ALIAS "GetInheritanceSourceW" ( _
    pObjectName          AS WSTRINGZ, _
    BYVAL ObjectType     AS SE_OBJECT_TYPE_enum, _
    BYVAL SecurityInfo   AS SECURITY_INFORMATION, _
    BYVAL Container      AS LONG, _
    pObjectClassGuids    AS DWORD, _   ' GUID PTR PTR
    BYVAL GuidCount      AS DWORD, _
    pAcl                 AS ACL, _
    pfnArray             AS DWORD, _   ' OBJECT_MGR_FUNCTS PTR
    pGenericMapping      AS GENERIC_MAPPING, _
    pInheritArray        AS DWORD _    ' INHERITED_FROM PTR (to one or more)
    ) AS DWORD
#ELSE
DECLARE FUNCTION GetInheritanceSourceW IMPORT "ADVAPI32.DLL" ALIAS "GetInheritanceSourceW" ( _
   BYREF pObjectName AS WSTRINGZ _                      ' __in LPWSTR pObjectName
 , BYVAL ObjectType AS SE_OBJECT_TYPE_ENUM _            ' __in SE_OBJECT_TYPE ObjectType
 , BYVAL SecurityInfo AS SECURITY_INFORMATION _         ' __in SECURITY_INFORMATION SecurityInfo
 , BYVAL Container AS LONG _                            ' __in BOOL Container
 , BYREF pObjectClassGuids AS GUID _                    ' __in_opt GUID	**pObjectClassGuids
 , BYVAL GuidCount AS DWORD _                           ' __in DWORD GuidCount
 , BYVAL pAcl AS ACL PTR _                              ' __in PACL pAcl
 , BYVAL pfnArray AS DWORD _                            ' __in_opt PFN_OBJECT_MGR_FUNCTS pfnArray
 , BYREF pGenericMapping AS GENERIC_MAPPING _           ' __in PGENERIC_MAPPING pGenericMapping
 , BYREF pInheritArray AS INHERITED_FROMW _             ' __out PINHERITED_FROMW pInheritArray
 ) AS DWORD                                             ' DWORD
#ENDIF

#IF %DEF(%UNICODE)
MACRO GetInheritanceSource = GetInheritanceSourceW
#ELSE
MACRO GetInheritanceSource = GetInheritanceSourceA
#ENDIF

' NOTE: The first parameter has been declared as ANY to allow to be used with
' both INHERITED_FROM and INHERITED_FROMW arrays.
#IF %DEF(%USEPBDECL)
DECLARE FUNCTION FreeInheritedFromArray LIB "ADVAPI32.DLL" _
   ALIAS "FreeInheritedFromArray" ( _
    BYVAL pInheritArray AS INHERITED_FROM PTR, _
    BYVAL AceCnt  AS WORD, _
    OPTIONAL BYVAL pfnArray AS DWORD _   ' OBJECT_MGR_FUNCTS PTR
    ) AS DWORD
#ELSE
DECLARE FUNCTION FreeInheritedFromArray IMPORT "ADVAPI32.DLL" ALIAS "FreeInheritedFromArray" ( _
   BYREF pInheritArray AS ANY _                         ' __in PINHERITED_FROMW pInheritArray
 , BYVAL AceCnt AS WORD _                               ' __in USHORT AceCnt
 , OPTIONAL BYVAL pfnArray AS DWORD _                   ' __in_opt PFN_OBJECT_MGR_FUNCTS pfnArray OPTIONAL
 ) AS DWORD                                             ' DWORD
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION TreeResetNamedSecurityInfoA LIB "ADVAPI32.DLL" _
   ALIAS "TreeResetNamedSecurityInfoA" ( _
    pObjectName        AS ASCIIZ, _
    BYVAL ObjectType   AS SE_OBJECT_TYPE_enum, _
    BYVAL SecurityInfo AS SECURITY_INFORMATION, _
    pOwner             AS SID, _
    pGroup             AS SID, _
    pDacl              AS ACL, _
    pSacl              AS ACL, _
    BYVAL KeepExplicit AS LONG, _
    BYVAL fnProgress   AS DWORD, _    ' FN_PROGRESS
    BYVAL ProgressInvokeSetting AS LONG, _   ' PROG_INVOKE_SETTING
    Args               AS ANY _
    ) AS DWORD
#ELSE
DECLARE FUNCTION TreeResetNamedSecurityInfoA IMPORT "ADVAPI32.DLL" ALIAS "TreeResetNamedSecurityInfoA" ( _
   BYREF pObjectName AS ASCIIZ _                        ' __in LPSTR pObjectName
 , BYVAL ObjectType AS SE_OBJECT_TYPE_ENUM _            ' __in SE_OBJECT_TYPE ObjectType
 , BYVAL SecurityInfo AS SECURITY_INFORMATION _         ' __in SECURITY_INFORMATION SecurityInfo
 , BYVAL pOwner AS SID PTR _                            ' __in_opt PSID pOwner
 , BYVAL pGroup AS SID PTR _                            ' __in_opt PSID pGroup
 , BYVAL pDacl AS ACL PTR _                             ' __in_opt PACL pDacl
 , BYVAL pSacl AS ACL PTR _                             ' __in_opt PACL pSacl
 , BYVAL KeepExplicit AS LONG _                         ' __in BOOL KeepExplicit
 , BYVAL fnProgress AS DWORD _                          ' __in_opt FN_PROGRESS fnProgress
 , BYVAL ProgressInvokeSetting AS PROG_INVOKE_SETTING_ENUM _ ' __in PROG_INVOKE_SETTING  ProgressInvokeSetting
 , OPTIONAL BYREF Args AS ANY _                         ' __in_opt PVOID Args
 ) AS DWORD                                             ' DWORD
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION TreeResetNamedSecurityInfoW LIB "ADVAPI32.DLL" _
   ALIAS "TreeResetNamedSecurityInfoW" ( _
    pObjectName        AS WSTRINGZ, _
    BYVAL ObjectType   AS SE_OBJECT_TYPE_enum, _
    BYVAL SecurityInfo AS SECURITY_INFORMATION, _
    pOwner             AS SID, _
    pGroup             AS SID, _
    pDacl              AS ACL, _
    pSacl              AS ACL, _
    BYVAL KeepExplicit AS LONG, _
    BYVAL fnProgress   AS DWORD, _    ' FN_PROGRESS
    BYVAL ProgressInvokeSetting AS LONG, _   ' PROG_INVOKE_SETTING
    Args               AS ANY _
    ) AS DWORD
#ELSE
DECLARE FUNCTION TreeResetNamedSecurityInfoW IMPORT "ADVAPI32.DLL" ALIAS "TreeResetNamedSecurityInfoW" ( _
   BYREF pObjectName AS WSTRINGZ _                      ' __in LPWSTR pObjectName
 , BYVAL ObjectType AS SE_OBJECT_TYPE_ENUM _            ' __in SE_OBJECT_TYPE ObjectType
 , BYVAL SecurityInfo AS SECURITY_INFORMATION _         ' __in SECURITY_INFORMATION SecurityInfo
 , BYVAL pOwner AS SID PTR _                            ' __in_opt PSID pOwner
 , BYVAL pGroup AS SID PTR _                            ' __in_opt PSID pGroup
 , BYVAL pDacl AS ACL PTR _                             ' __in_opt PACL pDacl
 , BYVAL pSacl AS ACL PTR _                             ' __in_opt PACL pSacl
 , BYVAL KeepExplicit AS LONG _                         ' __in BOOL KeepExplicit
 , BYVAL fnProgress AS DWORD _                          ' __in_opt FN_PROGRESS fnProgress
 , BYVAL ProgressInvokeSetting AS PROG_INVOKE_SETTING_ENUM _ ' __in PROG_INVOKE_SETTING ProgressInvokeSetting
 , OPTIONAL BYREF Args AS ANY _                         ' __in_opt PVOID Args
 ) AS DWORD                                             ' DWORD
#ENDIF

#IF %DEF(%UNICODE)
MACRO TreeResetNamedSecurityInfo = TreeResetNamedSecurityInfoW
#ELSE
MACRO TreeResetNamedSecurityInfo = TreeResetNamedSecurityInfoA
#ENDIF

'#if (NTDDI_VERSION >= NTDDI_VISTA)

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION TreeSetNamedSecurityInfoA LIB "ADVAPI32.DLL" _
   ALIAS "TreeSetNamedSecurityInfoA" ( _
    pObjectName           AS ASCIIZ, _
    BYVAL ObjectType      AS SE_OBJECT_TYPE_enum, _
    BYVAL SecurityInfo    AS SECURITY_INFORMATION, _
    pOwner                AS SID, _
    pGroup                AS SID, _
    pDacl                 AS ACL, _
    pSacl                 AS ACL, _
    BYVAL dwAction        AS DWORD, _
    BYVAL fnProgress      AS DWORD, _     ' FN_PROGRESS
    ProgressInvokeSetting AS LONG, _      ' PROG_INVOKE_SETTING
    Args                  AS ANY _
    ) AS DWORD
#ELSE
DECLARE FUNCTION TreeSetNamedSecurityInfoA IMPORT "ADVAPI32.DLL" ALIAS "TreeSetNamedSecurityInfoA" ( _
   BYREF pObjectName AS ASCIIZ _                        ' __in LPSTR pObjectName
 , BYVAL ObjectType AS SE_OBJECT_TYPE_ENUM _            ' __in SE_OBJECT_TYPE ObjectType
 , BYVAL SecurityInfo AS SECURITY_INFORMATION _         ' __in SECURITY_INFORMATION SecurityInfo
 , BYVAL pOwner AS SID PTR _                            ' __in_opt PSID pOwner
 , BYVAL pGroup AS SID PTR _                            ' __in_opt PSID pGroup
 , BYVAL pDacl AS ACL PTR _                             ' __in_opt PACL pDacl
 , BYVAL pSacl AS ACL PTR _                             ' __in_opt PACL pSacl
 , BYVAL dwAction AS DWORD _                            ' __in DWORD dwAction
 , BYVAL fnProgress AS DWORD _                          ' __in_opt FN_PROGRESS fnProgress
 , BYVAL ProgressInvokeSetting AS PROG_INVOKE_SETTING_ENUM _ ' __in PROG_INVOKE_SETTING  ProgressInvokeSetting
 , OPTIONAL BYREF Args AS ANY _                         ' __in_opt PVOID Args
 ) AS DWORD                                             ' DWORD
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION TreeSetNamedSecurityInfoW LIB "ADVAPI32.DLL" _
   ALIAS "TreeSetNamedSecurityInfoW" ( _
    pObjectName           AS WSTRINGZ, _
    BYVAL ObjectType      AS SE_OBJECT_TYPE_enum, _
    BYVAL SecurityInfo    AS SECURITY_INFORMATION, _
    pOwner                AS SID, _
    pGroup                AS SID, _
    pDacl                 AS ACL, _
    pSacl                 AS ACL, _
    BYVAL dwAction        AS DWORD, _
    BYVAL fnProgress      AS DWORD, _     ' FN_PROGRESS
    ProgressInvokeSetting AS LONG, _      ' PROG_INVOKE_SETTING
    Args                  AS ANY _
    ) AS DWORD
#ELSE
DECLARE FUNCTION TreeSetNamedSecurityInfoW IMPORT "ADVAPI32.DLL" ALIAS "TreeSetNamedSecurityInfoW" ( _
   BYREF pObjectName AS WSTRINGZ _                      ' __in LPWSTR pObjectName
 , BYVAL ObjectType AS SE_OBJECT_TYPE_ENUM _            ' __in SE_OBJECT_TYPE ObjectType
 , BYVAL SecurityInfo AS SECURITY_INFORMATION _         ' __in SECURITY_INFORMATION SecurityInfo
 , BYVAL pOwner AS SID PTR _                            ' __in_opt PSID pOwner
 , BYVAL pGroup AS SID PTR _                            ' __in_opt PSID pGroup
 , BYVAL pDacl AS ACL PTR _                             ' __in_opt PACL pDacl
 , BYVAL pSacl AS ACL PTR _                             ' __in_opt PACL pSacl
 , BYVAL dwAction AS DWORD _                            ' __in DWORD dwAction
 , BYVAL fnProgress AS DWORD _                          ' __in_opt FN_PROGRESS fnProgress
 , BYVAL ProgressInvokeSetting AS PROG_INVOKE_SETTING_ENUM _ ' __in PROG_INVOKE_SETTING ProgressInvokeSetting
 , OPTIONAL BYREF Args AS ANY _                         ' __in_opt PVOID Args
 ) AS DWORD                                             ' DWORD
#ENDIF

#IF %DEF(%UNICODE)
MACRO TreeSetNamedSecurityInfo = TreeSetNamedSecurityInfoW
#ELSE
MACRO TreeSetNamedSecurityInfo = TreeSetNamedSecurityInfoA
#ENDIF

'#endif // (NTDDI_VERSION >= NTDDI_VISTA)

'//----------------------------------------------------------------------------
'// The following API are provided for trusted servers to use to
'// implement access control on their own objects.
'//----------------------------------------------------------------------------

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION BuildSecurityDescriptorA LIB "ADVAPI32.DLL" _
   ALIAS "BuildSecurityDescriptorA" ( _
    pOwner                      AS TRUSTEE_A, _
    pGroup                      AS TRUSTEE_A, _
    BYVAL cCountOfAccessEntries AS DWORD, _
    BYVAL pListOfAccessEntries  AS EXPLICIT_ACCESS_A PTR, _
    BYVAL cCountOfAuditEntries  AS DWORD, _
    BYVAL pListOfAuditEntries   AS EXPLICIT_ACCESS_A PTR, _
    pOldSD                      AS SECURITY_DESCRIPTOR, _
    pSizeNewSD                  AS DWORD, _
    pNewSD                      AS SECURITY_DESCRIPTOR _
    ) AS DWORD
#ELSE
DECLARE FUNCTION BuildSecurityDescriptorA IMPORT "ADVAPI32.DLL" ALIAS "BuildSecurityDescriptorA" ( _
   BYREF pOwner AS TRUSTEE_A _                          ' __in_opt PTRUSTEE_A pOwner
 , BYREF pGroup AS TRUSTEE_A _                          ' __in_opt PTRUSTEE_A pGroup
 , BYVAL cCountOfAccessEntries AS DWORD _               ' __in ULONG cCountOfAccessEntries
 , BYREF pListOfAccessEntries AS EXPLICIT_ACCESS_A _    ' __in PEXPLICIT_ACCESS_A pListOfAccessEntries
 , BYVAL cCountOfAuditEntries AS DWORD _                ' __in ULONG cCountOfAuditEntries
 , BYREF pListOfAuditEntries AS EXPLICIT_ACCESS_A _     ' __in PEXPLICIT_ACCESS_A pListOfAuditEntries
 , BYREF pOldSD AS SECURITY_DESCRIPTOR _                ' __in_opt PSECURITY_DESCRIPTOR pOldSD
 , BYREF pSizeNewSD AS DWORD _                          ' __out PULONG pSizeNewSD
 , BYREF pNewSD AS SECURITY_DESCRIPTOR _                ' __out PSECURITY_DESCRIPTOR *pNewSD
 ) AS DWORD                                             ' DWORD
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION BuildSecurityDescriptorW LIB "ADVAPI32.DLL" _
   ALIAS "BuildSecurityDescriptorW" ( _
    pOwner                      AS TRUSTEE_W, _
    pGroup                      AS TRUSTEE_W, _
    BYVAL cCountOfAccessEntries AS DWORD, _
    BYVAL pListOfAccessEntries  AS EXPLICIT_ACCESS PTR, _
    BYVAL cCountOfAuditEntries  AS DWORD, _
    BYVAL pListOfAuditEntries   AS EXPLICIT_ACCESS PTR, _
    pOldSD                      AS SECURITY_DESCRIPTOR, _
    pSizeNewSD                  AS DWORD, _
    pNewSD                      AS SECURITY_DESCRIPTOR _
    ) AS DWORD
#ELSE
DECLARE FUNCTION BuildSecurityDescriptorW IMPORT "ADVAPI32.DLL" ALIAS "BuildSecurityDescriptorW" ( _
   BYREF pOwner AS TRUSTEE_W _                          ' __in_opt PTRUSTEE_W pOwner
 , BYREF pGroup AS TRUSTEE_W _                          ' __in_opt PTRUSTEE_W pGroup
 , BYVAL cCountOfAccessEntries AS DWORD _               ' __in ULONG cCountOfAccessEntries
 , BYREF pListOfAccessEntries AS EXPLICIT_ACCESS_W _    ' __in PEXPLICIT_ACCESS_A pListOfAccessEntries
 , BYVAL cCountOfAuditEntries AS DWORD _                ' __in ULONG cCountOfAuditEntries
 , BYREF pListOfAuditEntries AS EXPLICIT_ACCESS_W _     ' __in PEXPLICIT_ACCESS_A pListOfAuditEntries
 , BYREF pOldSD AS SECURITY_DESCRIPTOR _                ' __in_opt PSECURITY_DESCRIPTOR pOldSD
 , BYREF pSizeNewSD AS DWORD _                          ' __out PULONG pSizeNewSD
 , BYREF pNewSD AS SECURITY_DESCRIPTOR _                ' __out PSECURITY_DESCRIPTOR *pNewSD
 ) AS DWORD                                             ' DWORD
#ENDIF

#IF %DEF(%UNICODE)
MACRO BuildSecurityDescriptor = BuildSecurityDescriptorW
#ELSE
MACRO BuildSecurityDescriptor = BuildSecurityDescriptorA
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION LookupSecurityDescriptorPartsA LIB "ADVAPI32.DLL" _
   ALIAS "LookupSecurityDescriptorPartsA" ( _
    pOwner                      AS TRUSTEE_A, _
    pGroup                      AS TRUSTEE_A, _
    BYVAL cCountOfAccessEntries AS DWORD, _
    BYVAL pListOfAccessEntries  AS EXPLICIT_ACCESS_A PTR, _
    BYVAL cCountOfAuditEntries  AS DWORD, _
    BYVAL pListOfAuditEntries   AS EXPLICIT_ACCESS_A PTR, _
    pSD                         AS SECURITY_DESCRIPTOR _
    ) AS DWORD
#ELSE
DECLARE FUNCTION LookupSecurityDescriptorPartsA IMPORT "ADVAPI32.DLL" ALIAS "LookupSecurityDescriptorPartsA" ( _
   BYREF ppOwner AS TRUSTEE_A _                         ' __out_opt PTRUSTEE_A *ppOwner
 , BYREF ppGroup AS TRUSTEE_A _                         ' __out_opt PTRUSTEE_A *ppGroup
 , BYREF pcCountOfAccessEntries AS DWORD _              ' __out_opt PULONG pcCountOfAccessEntries
 , BYREF ppListOfAccessEntries AS DWORD _               ' __out PEXPLICIT_ACCESS_A *ppListOfAccessEntries
 , BYREF pcCountOfAuditEntries AS DWORD _               ' __out_opt PULONG pcCountOfAuditEntries
 , BYREF ppListOfAuditEntries AS DWORD _                ' __out PEXPLICIT_ACCESS_A *ppListOfAuditEntries
 , BYREF pSD AS SECURITY_DESCRIPTOR _                   ' __in PSECURITY_DESCRIPTOR pSD
 ) AS DWORD                                             ' DWORD
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION LookupSecurityDescriptorPartsW LIB "ADVAPI32.DLL" _
   ALIAS "LookupSecurityDescriptorPartsW" ( _
    pOwner                      AS TRUSTEE_W, _
    pGroup                      AS TRUSTEE_W, _
    BYVAL cCountOfAccessEntries AS DWORD, _
    BYVAL pListOfAccessEntries  AS EXPLICIT_ACCESS_W PTR, _
    BYVAL cCountOfAuditEntries  AS DWORD, _
    BYVAL pListOfAuditEntries   AS EXPLICIT_ACCESS_W PTR, _
    pSD                         AS SECURITY_DESCRIPTOR _
    ) AS DWORD
#ELSE
DECLARE FUNCTION LookupSecurityDescriptorPartsW IMPORT "ADVAPI32.DLL" ALIAS "LookupSecurityDescriptorPartsW" ( _
   BYREF ppOwner AS TRUSTEE_W _                         ' __out_opt PTRUSTEE_W *ppOwner
 , BYREF ppGroup AS TRUSTEE_W _                         ' __out_opt PTRUSTEE_W *ppGroup
 , BYREF pcCountOfAccessEntries AS DWORD _              ' __out_opt PULONG pcCountOfAccessEntries
 , BYREF ppListOfAccessEntries AS DWORD _               ' __out PEXPLICIT_ACCESS_W *ppListOfAccessEntries
 , BYREF pcCountOfAuditEntries AS DWORD _               ' __out_opt PULONG pcCountOfAuditEntries
 , BYREF ppListOfAuditEntries AS DWORD _                ' __out PEXPLICIT_ACCESS_W *ppListOfAuditEntries
 , BYREF pSD AS SECURITY_DESCRIPTOR _                   ' __in PSECURITY_DESCRIPTOR pSD
 ) AS DWORD                                             ' DWORD
#ENDIF

#IF %DEF(%UNICODE)
MACRO LookupSecurityDescriptorParts = LookupSecurityDescriptorPartsW
#ELSE
MACRO LookupSecurityDescriptorParts = LookupSecurityDescriptorPartsA
#ENDIF

'//----------------------------------------------------------------------------
'// The following helper API are provided for building
'// access control structures.
'//----------------------------------------------------------------------------

#IF %DEF(%USEPBDECL)
DECLARE SUB BuildExplicitAccessWithNameA LIB "ADVAPI32.DLL" _
   ALIAS "BuildExplicitAccessWithNameA" ( _
    BYVAL pExplicitAccess   AS EXPLICIT_ACCESS_A PTR, _
    pTrusteeName            AS ASCIIZ, _
    BYVAL AccessPermissions AS DWORD, _
    BYVAL AccessMode        AS ACCESS_MODE_enum, _
    BYVAL Inheritance       AS DWORD _
    )
#ELSE
DECLARE FUNCTION BuildExplicitAccessWithNameA IMPORT "ADVAPI32.DLL" ALIAS "BuildExplicitAccessWithNameA" ( _
   BYREF pExplicitAccess AS EXPLICIT_ACCESS_A _         ' __inout PEXPLICIT_ACCESS_A pExplicitAccess
 , BYREF pTrusteeName AS ASCIIZ _                       ' __in_opt LPSTR pTrusteeName
 , BYVAL AccessPermissions AS DWORD _                   ' __in DWORD AccessPermissions
 , BYVAL AccessMode AS ACCESS_MODE_ENUM _               ' __in ACCESS_MODE AccessMode
 , BYVAL Inheritance AS DWORD _                         ' __in DWORD Inheritance
 ) AS DWORD                                             ' DWORD
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE SUB BuildExplicitAccessWithNameW LIB "ADVAPI32.DLL" _
   ALIAS "BuildExplicitAccessWithNameW" ( _
    BYVAL pExplicitAccess   AS EXPLICIT_ACCESS_W PTR, _
    pTrusteeName            AS WSTRINGZ, _
    BYVAL AccessPermissions AS DWORD, _
    BYVAL AccessMode        AS ACCESS_MODE_enum, _
    BYVAL Inheritance       AS DWORD _
    )
#ELSE
DECLARE FUNCTION BuildExplicitAccessWithNameW IMPORT "ADVAPI32.DLL" ALIAS "BuildExplicitAccessWithNameW" ( _
   BYREF pExplicitAccess AS EXPLICIT_ACCESS_W _         ' __inout PEXPLICIT_ACCESS_W pExplicitAccess
 , BYREF pTrusteeName AS WSTRINGZ _                     ' __in_opt LPWSTR pTrusteeName
 , BYVAL AccessPermissions AS DWORD _                   ' __in DWORD AccessPermissions
 , BYVAL AccessMode AS ACCESS_MODE_ENUM _               ' __in ACCESS_MODE AccessMode
 , BYVAL Inheritance AS DWORD _                         ' __in DWORD Inheritance
 ) AS DWORD                                             ' DWORD
#ENDIF

#IF %DEF(%UNICODE)
MACRO BuildExplicitAccessWithName = BuildExplicitAccessWithNameW
#ELSE
MACRO BuildExplicitAccessWithName = BuildExplicitAccessWithNameA
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE SUB BuildImpersonateExplicitAccessWithNameA LIB "ADVAPI32.DLL" _
   ALIAS "BuildImpersonateExplicitAccessWithNameA" ( _
    BYVAL pExplicitAccess   AS EXPLICIT_ACCESS_A PTR, _
    pTrusteeName            AS ASCIIZ, _
    pTrustee                AS TRUSTEE_A, _
    BYVAL AccessPermissions AS DWORD, _
    BYVAL AccessMode        AS ACCESS_MODE_enum, _
    BYVAL Inheritance       AS DWORD _
    )
#ELSE
DECLARE SUB BuildImpersonateExplicitAccessWithNameA IMPORT "ADVAPI32.DLL" ALIAS "BuildImpersonateExplicitAccessWithNameA" ( _
   BYREF pExplicitAccess AS EXPLICIT_ACCESS_A _         ' __inout PEXPLICIT_ACCESS_A pExplicitAccess
 , BYREF pTrusteeName AS ASCIIZ _                       ' __in_opt LPSTR pTrusteeName
 , BYREF pTrustee AS TRUSTEE_A _                        ' __in_opt PTRUSTEE_A pTrustee
 , BYVAL AccessPermissions AS DWORD _                   ' __in DWORD AccessPermissions
 , BYVAL AccessMode AS ACCESS_MODE_ENUM _               ' __in ACCESS_MODE AccessMode
 , BYVAL Inheritance AS DWORD _                         ' __in DWORD Inheritance
 )                                                      ' void
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE SUB BuildImpersonateExplicitAccessWithNameW LIB "ADVAPI32.DLL" _
   ALIAS "BuildImpersonateExplicitAccessWithNameW" ( _
    BYVAL pExplicitAccess   AS EXPLICIT_ACCESS_W PTR, _
    pTrusteeName            AS WSTRINGZ, _
    pTrustee                AS TRUSTEE_A, _
    BYVAL AccessPermissions AS DWORD, _
    BYVAL AccessMode        AS ACCESS_MODE_enum, _
    BYVAL Inheritance       AS DWORD _
    )
#ELSE
DECLARE SUB BuildImpersonateExplicitAccessWithNameW IMPORT "ADVAPI32.DLL" ALIAS "BuildImpersonateExplicitAccessWithNameW" ( _
   BYREF pExplicitAccess AS EXPLICIT_ACCESS_W _         ' __inout PEXPLICIT_ACCESS_W pExplicitAccess
 , BYREF pTrusteeName AS WSTRINGZ _                     ' __in_opt LPWSTR pTrusteeName
 , BYREF pTrustee AS TRUSTEE_W _                        ' __in_opt PTRUSTEE_W pTrustee
 , BYVAL AccessPermissions AS DWORD _                   ' __in DWORD AccessPermissions
 , BYVAL AccessMode AS ACCESS_MODE_ENUM _               ' __in ACCESS_MODE AccessMode
 , BYVAL Inheritance AS DWORD _                         ' __in DWORD Inheritance
 )                                                      ' void
#ENDIF

#IF %DEF(%UNICODE)
MACRO BuildImpersonateExplicitAccessWithName = BuildImpersonateExplicitAccessWithNameW
#ELSE
MACRO BuildImpersonateExplicitAccessWithName = BuildImpersonateExplicitAccessWithNameA
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE SUB BuildTrusteeWithNameA LIB "ADVAPI32.DLL" _
   ALIAS "BuildTrusteeWithNameA" ( _
    pTrustee AS TRUSTEE_A, _
    pName    AS ASCIIZ _
    )
#ELSE
DECLARE SUB BuildTrusteeWithNameA IMPORT "ADVAPI32.DLL" ALIAS "BuildTrusteeWithNameA" ( _
   BYREF pTrustee AS TRUSTEE_A _                        ' __inout PTRUSTEE_A pTrustee
 , OPTIONAL BYREF pName AS ASCIIZ _                     ' __in_opt LPSTR pName
 )                                                      ' void
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE SUB BuildTrusteeWithNameW LIB "ADVAPI32.DLL" _
   ALIAS "BuildTrusteeWithNameW" ( _
    pTrustee AS TRUSTEE_W, _
    pName    AS WSTRINGZ _
    )
#ELSE
DECLARE SUB BuildTrusteeWithNameW IMPORT "ADVAPI32.DLL" ALIAS "BuildTrusteeWithNameW" ( _
   BYREF pTrustee AS TRUSTEE_W _                        ' __inout PTRUSTEE_W pTrustee
 , OPTIONAL BYREF pName AS WSTRINGZ _                   ' __in_opt LPWSTR pName
 )                                                      ' void
#ENDIF

#IF %DEF(%UNICODE)
MACRO BuildTrusteeWithName = BuildTrusteeWithNameW
#ELSE
MACRO BuildTrusteeWithName = BuildTrusteeWithNameA
#ENDIF

' Obsolete. Do not use.
#IF %DEF(%USEPBDECL)
DECLARE SUB BuildImpersonateTrusteeA LIB "ADVAPI32.DLL" _
   ALIAS "BuildImpersonateTrusteeA" ( _
    pTrustee            AS TRUSTEE_A, _
    pImpersonateTrustee AS TRUSTEE_A _
    )
#ELSE
DECLARE SUB BuildImpersonateTrusteeA IMPORT "ADVAPI32.DLL" ALIAS "BuildImpersonateTrusteeA" ( _
   BYREF pTrustee AS TRUSTEE_A _                        ' __inout PTRUSTEE_A pTrustee
 , OPTIONAL BYREF pImpersonateTrustee AS TRUSTEE_A _    ' __in_opt PTRUSTEE_A pImpersonateTrustee
 )                                                      ' void
#ENDIF

' Obsolete. Do not use.
#IF %DEF(%USEPBDECL)
DECLARE SUB BuildImpersonateTrusteeW LIB "ADVAPI32.DLL" _
   ALIAS "BuildImpersonateTrusteeW" ( _
    pTrustee            AS TRUSTEE_W, _
    pImpersonateTrustee AS TRUSTEE_W _
    )
#ELSE
DECLARE SUB BuildImpersonateTrusteeW IMPORT "ADVAPI32.DLL" ALIAS "BuildImpersonateTrusteeW" ( _
   BYREF pTrustee AS TRUSTEE_W _                        ' __inout PTRUSTEE_W pTrustee
 , OPTIONAL BYREF pImpersonateTrustee AS TRUSTEE_W _    ' __in_opt PTRUSTEE_W pImpersonateTrustee
 )                                                      ' void
#ENDIF

#IF %DEF(%UNICODE)
MACRO BuildImpersonateTrustee = BuildImpersonateTrusteeW
#ELSE
MACRO BuildImpersonateTrustee = BuildImpersonateTrusteeA
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE SUB BuildTrusteeWithSidA LIB "ADVAPI32.DLL" _
   ALIAS "BuildTrusteeWithSidA" ( _
    pTrustee   AS TRUSTEE_A, _
    BYVAL pSid AS SID PTR _
    )
#ELSE
DECLARE SUB BuildTrusteeWithSidA IMPORT "ADVAPI32.DLL" ALIAS "BuildTrusteeWithSidA" ( _
   BYREF pTrustee AS TRUSTEE_A _                        ' __inout PTRUSTEE_A pTrustee
 , OPTIONAL BYVAL pSid AS SID PTR _                     ' __in_opt PSID pSid
 )                                                      ' void
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE SUB BuildTrusteeWithSidW LIB "ADVAPI32.DLL" _
   ALIAS "BuildTrusteeWithSidW" ( _
    pTrustee   AS TRUSTEE_W, _
    BYVAL pSid AS SID PTR _
    )
#ELSE
DECLARE SUB BuildTrusteeWithSidW IMPORT "ADVAPI32.DLL" ALIAS "BuildTrusteeWithSidW" ( _
   BYREF pTrustee AS TRUSTEE_W _                        ' __inout PTRUSTEE_W pTrustee
 , OPTIONAL BYVAL pSid AS SID PTR _                     ' __in_opt PSID pSid
 )                                                      ' void
#ENDIF

#IF %DEF(%UNICODE)
MACRO BuildTrusteeWithSid = BuildTrusteeWithSidW
#ELSE
MACRO BuildTrusteeWithSid = BuildTrusteeWithSidA
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE SUB BuildTrusteeWithObjectsAndSidA LIB "ADVAPI32.DLL" _
   ALIAS "BuildTrusteeWithObjectsAndSidA" ( _
    pTrustee             AS TRUSTEE_A, _
    pObjSid              AS OBJECTS_AND_SID, _
    pObjectGuid          AS GUID, _
    pInheritedObjectGuid AS GUID, _
    BYVAL pSid           AS SID PTR _
    )
#ELSE
DECLARE SUB BuildTrusteeWithObjectsAndSidA IMPORT "ADVAPI32.DLL" ALIAS "BuildTrusteeWithObjectsAndSidA" ( _
   BYREF pTrustee AS TRUSTEE_A _                        ' __inout PTRUSTEE_A pTrustee
 , OPTIONAL BYREF pObjSid AS OBJECTS_AND_SID _          ' __in_opt POBJECTS_AND_SID pObjSid
 , OPTIONAL BYREF pObjectGuid AS GUID _                 ' __in_opt GUID * pObjectGuid
 , OPTIONAL BYREF pInheritedObjectGuid AS GUID _        ' __in_opt GUID * pInheritedObjectGuid
 , OPTIONAL BYVAL pSid AS SID PTR _                     ' __in_opt PSID pSid
 )                                                      ' void
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE SUB BuildTrusteeWithObjectsAndSidW LIB "ADVAPI32.DLL" _
   ALIAS "BuildTrusteeWithObjectsAndSidW" ( _
    pTrustee             AS TRUSTEE_W, _
    pObjSid              AS OBJECTS_AND_SID, _
    pObjectGuid          AS GUID, _
    pInheritedObjectGuid AS GUID, _
    BYVAL pSid           AS SID PTR _
    )
#ELSE
DECLARE SUB BuildTrusteeWithObjectsAndSidW IMPORT "ADVAPI32.DLL" ALIAS "BuildTrusteeWithObjectsAndSidW" ( _
   BYREF pTrustee AS TRUSTEE_W _                        ' __inout PTRUSTEE_W pTrustee
 , OPTIONAL BYREF pObjSid AS OBJECTS_AND_SID _          ' __in_opt POBJECTS_AND_SID pObjSid
 , OPTIONAL BYREF pObjectGuid AS GUID _                 ' __in_opt GUID * pObjectGuid
 , OPTIONAL BYREF pInheritedObjectGuid AS GUID _        ' __in_opt GUID * pInheritedObjectGuid
 , OPTIONAL BYVAL pSid AS SID PTR _                     ' __in_opt PSID pSid
 )                                                      ' void
#ENDIF

#IF %DEF(%UNICODE)
MACRO BuildTrusteeWithObjectsAndSid = BuildTrusteeWithObjectsAndSidW
#ELSE
MACRO BuildTrusteeWithObjectsAndSid = BuildTrusteeWithObjectsAndSidA
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE SUB BuildTrusteeWithObjectsAndNameA LIB "ADVAPI32.DLL" _
   ALIAS "BuildTrusteeWithObjectsAndNameA" ( _
    pTrustee                AS TRUSTEE_A, _
    pObjName                AS OBJECTS_AND_NAME, _
    ObjectType              AS SE_OBJECT_TYPE_enum, _
    ObjectTypeName          AS ASCIIZ, _
    InheritedObjectTypeName AS ASCIIZ, _
    TrusteeName             AS ASCIIZ _
    )
#ELSE
DECLARE SUB BuildTrusteeWithObjectsAndNameA IMPORT "ADVAPI32.DLL" ALIAS "BuildTrusteeWithObjectsAndNameA" ( _
   BYREF pTrustee AS TRUSTEE_A _                        ' __inout PTRUSTEE_A pTrustee
 , OPTIONAL BYREF pObjName AS OBJECTS_AND_NAME _        ' __in_opt POBJECTS_AND_NAME_A pObjName
 , OPTIONAL BYVAL ObjectType AS SE_OBJECT_TYPE_ENUM _   ' __in_opt SE_OBJECT_TYPE ObjectType
 , OPTIONAL BYREF ObjectTypeName AS ASCIIZ _            ' __in_opt LPSTR ObjectTypeName
 , OPTIONAL BYREF InheritedObjectTypeName AS ASCIIZ _   ' __in_opt LPSTR InheritedObjectTypeName,
 , OPTIONAL BYREF Name AS ASCIIZ _                      ' __in_opt LPSTR Name
 )                                                      ' void
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE SUB BuildTrusteeWithObjectsAndNameW LIB "ADVAPI32.DLL" _
   ALIAS "BuildTrusteeWithObjectsAndNameW" ( _
    pTrustee                AS TRUSTEE_W, _
    pObjName                AS OBJECTS_AND_NAME, _
    ObjectType              AS SE_OBJECT_TYPE_enum, _
    ObjectTypeName          AS WSTRINGZ, _
    InheritedObjectTypeName AS WSTRINGZ, _
    TrusteeName             AS WSTRINGZ _
    )
#ELSE
DECLARE SUB BuildTrusteeWithObjectsAndNameW IMPORT "ADVAPI32.DLL" ALIAS "BuildTrusteeWithObjectsAndNameW" ( _
   BYREF pTrustee AS TRUSTEE_W _                        ' __inout PTRUSTEE_W pTrustee
 , OPTIONAL BYREF pObjName AS OBJECTS_AND_NAME_W _      ' __in_opt POBJECTS_AND_NAME_W pObjName
 , OPTIONAL BYREF ObjectType AS SE_OBJECT_TYPE_ENUM _   ' __in_opt SE_OBJECT_TYPE ObjectType
 , OPTIONAL BYREF ObjectTypeName AS WSTRINGZ _          ' __in_opt LPWSTR ObjectTypeName
 , OPTIONAL BYREF InheritedObjectTypeName AS WSTRINGZ _ ' __in_opt LPWSTR InheritedObjectTypeName,
 , OPTIONAL BYVAL Name AS DWORD _                       ' __in_opt LPWSTR Name
 )                                                      ' void
#ENDIF

#IF %DEF(%UNICODE)
MACRO BuildTrusteeWithObjectsAndName = BuildTrusteeWithObjectsAndNameW
#ELSE
MACRO BuildTrusteeWithObjectsAndName = BuildTrusteeWithObjectsAndNameA
#ENDIF

DECLARE FUNCTION GetTrusteeNameA IMPORT "ADVAPI32.DLL" ALIAS "GetTrusteeNameA" ( _
   BYREF pTrustee AS TRUSTEE_A _                        ' __in PTRUSTEE_A pTrustee
 ) AS DWORD                                             ' LPSTR

DECLARE FUNCTION GetTrusteeNameW IMPORT "ADVAPI32.DLL" ALIAS "GetTrusteeNameW" ( _
   BYREF pTrustee AS TRUSTEE_W _                        ' __in PTRUSTEE_W pTrustee
 ) AS DWORD                                             ' LPWSTR

#IF %DEF(%UNICODE)
MACRO GetTrusteeName = GetTrusteeNameW
#ELSE
MACRO GetTrusteeName = GetTrusteeNameA
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION GetTrusteeTypeA LIB "ADVAPI32.DLL" _
   ALIAS "GetTrusteeTypeA" ( _
    pTrustee AS TRUSTEE_A _
    ) AS TRUSTEE_TYPE_enum
#ELSE
DECLARE FUNCTION GetTrusteeTypeA IMPORT "ADVAPI32.DLL" ALIAS "GetTrusteeTypeA" ( _
   OPTIONAL BYREF pTrustee AS TRUSTEE_A _               ' __in_opt PTRUSTEE_A pTrustee
 ) AS TRUSTEE_TYPE_ENUM                                 ' TRUSTEE_TYPE
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION GetTrusteeTypeW LIB "ADVAPI32.DLL" _
   ALIAS "GetTrusteeTypeW" ( _
    pTrustee AS TRUSTEE_W _
    ) AS TRUSTEE_TYPE_enum
#ELSE
DECLARE FUNCTION GetTrusteeTypeW IMPORT "ADVAPI32.DLL" ALIAS "GetTrusteeTypeW" ( _
   OPTIONAL BYREF pTrustee AS TRUSTEE_W _               ' __in_opt PTRUSTEE_W pTrustee
 ) AS TRUSTEE_TYPE_ENUM                                 ' TRUSTEE_TYPE
#ENDIF

#IF %DEF(%UNICODE)
MACRO GetTrusteeType = GetTrusteeTypeW
#ELSE
MACRO GetTrusteeType = GetTrusteeTypeA
#ENDIF

DECLARE FUNCTION GetTrusteeFormA IMPORT "ADVAPI32.DLL" ALIAS "GetTrusteeFormA" ( _
   BYREF pTrustee AS TRUSTEE_A _                        ' __in_PTRUSTEE_A pTrustee
 ) AS TRUSTEE_FORM_ENUM                                 ' TRUSTEE_FORM

DECLARE FUNCTION GetTrusteeFormW IMPORT "ADVAPI32.DLL" ALIAS "GetTrusteeFormW" ( _
   BYREF pTrustee AS TRUSTEE_W _                        ' __in_PTRUSTEE_W pTrustee
 ) AS TRUSTEE_FORM_ENUM                                 ' TRUSTEE_FORM

#IF %DEF(%UNICODE)
MACRO GetTrusteeForm = GetTrusteeFormW
#ELSE
MACRO GetTrusteeForm = GetTrusteeFormA
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION GetMultipleTrusteeOperationA LIB "ADVAPI32.DLL" _
   ALIAS "GetMultipleTrusteeOperationA" ( _
    pTrustee AS TRUSTEE_A _
    ) AS MULTIPLE_TRUSTEE_OPERATION_enum
#ELSE
DECLARE FUNCTION GetMultipleTrusteeOperationA IMPORT "ADVAPI32.DLL" ALIAS "GetMultipleTrusteeOperationA" ( _
   OPTIONAL BYREF pTrustee AS TRUSTEE_A _               ' __in_opt PTRUSTEE_A pTrustee
 ) AS MULTIPLE_TRUSTEE_OPERATION_ENUM                   ' MULTIPLE_TRUSTEE_OPERATION
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION GetMultipleTrusteeOperationW LIB "ADVAPI32.DLL" _
   ALIAS "GetMultipleTrusteeOperationW" ( _
    pTrustee AS TRUSTEE_W _
    ) AS MULTIPLE_TRUSTEE_OPERATION_enum
#ELSE
DECLARE FUNCTION GetMultipleTrusteeOperationW IMPORT "ADVAPI32.DLL" ALIAS "GetMultipleTrusteeOperationW" ( _
   OPTIONAL BYREF pTrustee AS TRUSTEE_W _               ' __in_opt PTRUSTEE_W pTrustee
 ) AS MULTIPLE_TRUSTEE_OPERATION_ENUM                   ' MULTIPLE_TRUSTEE_OPERATION
#ENDIF

#IF %DEF(%UNICODE)
MACRO GetMultipleTrusteeOperation = GetMultipleTrusteeOperationW
#ELSE
MACRO GetMultipleTrusteeOperation = GetMultipleTrusteeOperationA
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION GetMultipleTrusteeA LIB "ADVAPI32.DLL" _
   ALIAS "GetMultipleTrusteeA" ( _
    pTrustee AS TRUSTEE_A _
    ) AS DWORD
#ELSE
DECLARE FUNCTION GetMultipleTrusteeA IMPORT "ADVAPI32.DLL" ALIAS "GetMultipleTrusteeA" ( _
   OPTIONAL BYREF pTrustee AS TRUSTEE_A _               ' __in_opt PTRUSTEE_A pTrustee
 ) AS DWORD                                             ' PTRUSTEE_A
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION GetMultipleTrusteeW LIB "ADVAPI32.DLL" _
   ALIAS "GetMultipleTrusteeW" ( _
    pTrustee AS TRUSTEE_W _
    ) AS DWORD
#ELSE
DECLARE FUNCTION GetMultipleTrusteeW IMPORT "ADVAPI32.DLL" ALIAS "GetMultipleTrusteeW" ( _
   OPTIONAL BYREF pTrustee AS TRUSTEE_W _               ' __in_opt PTRUSTEE_W pTrustee
 ) AS DWORD                                             ' PTRUSTEE_W
#ENDIF

#IF %DEF(%UNICODE)
MACRO GetMultipleTrustee = GetMultipleTrusteeW
#ELSE
MACRO GetMultipleTrustee = GetMultipleTrusteeA
#ENDIF
