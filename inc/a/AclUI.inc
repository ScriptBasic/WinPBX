' ########################################################################################
' Microsoft Windows
' File: AclUI.inc
' Contents: Definitions and prototypes for the ACLUI.DLL
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%ACLUI_INC = 1

#INCLUDE ONCE "windows.inc"
#INCLUDE ONCE "objbase.inc"
#include ONCE "prsht.inc"     ' // for HPROPSHEETPAGE
#INCLUDE ONCE "accctrl.inc"   ' // for SE_OBJECT_TYPE

'//
'// ISecurityInformation interface
'//
'//  Methods:
'//
'//     GetObjectInformation - Allows UI to determine type of object being
'//       edited.  Also allows determining if object is a container.
'//
'//     GetSecurity - Allows retrieving of ACLs from the original object
'//                       NOTE: ACLUI will LocalFree the security descriptor
'//                       returned by GetSecurity.
'//     SetSecurity - Allows setting of the ACLs on the original object
'//
'//     GetAccessRights - For retrieving the list of rights allowed
'//              on this object.
'//
'//     MapGeneric - For mapping generic rights to standard & specific rights
'//
'//     GetInheritTypes - For retrieving the list of possible sub-object types
'//              for a container.
'//
'//     PropertySheetCallback - A method which is called back during the various
'//              security UI property pages so that specialized work can be
'//              done.  Similar to PropSheetPageProc.  If uMsg == PSPCB_CREATE,
'//              then any error return value other than E_NOTIMPL will abort
'//              the creation of that page.  The type of page being created or
'//              destroyed is indicated by the uPage parameter.
'//

' // Size = 36 bytes
TYPE SI_OBJECT_INFO DWORD
   dwFlags        AS DWORD          ' DWORD
   hInstance      AS DWORD          ' HINSTANCE // resources (e.g. strings) reside here
   pszServerName  AS WSTRINGZ PTR   ' LPWSTR    // must be present
   pszObjectName  AS WSTRINGZ PTR   ' LPWSTR    // must be present
   pszPageTitle   AS WSTRINGZ PTR   ' LPWSTR    // only valid if SI_PAGE_TITLE is set
   guidObjectType AS GUID           ' GUID      // only valid if SI_OBJECT_GUID is set
END TYPE

'// SI_OBJECT_INFO flags
%SI_EDIT_PERMS                = &H00000000???   ' // always implied
%SI_EDIT_OWNER                = &H00000001???
%SI_EDIT_AUDITS               = &H00000002???
%SI_CONTAINER                 = &H00000004???
%SI_READONLY                  = &H00000008???
%SI_ADVANCED                  = &H00000010???
%SI_RESET                     = &H00000020???   ' // equals to SI_RESET_DACL|SI_RESET_SACL|SI_RESET_OWNER
%SI_OWNER_READONLY            = &H00000040???
%SI_EDIT_PROPERTIES           = &H00000080???
%SI_OWNER_RECURSE             = &H00000100???
%SI_NO_ACL_PROTECT            = &H00000200???
%SI_NO_TREE_APPLY             = &H00000400???
%SI_PAGE_TITLE                = &H00000800???
%SI_SERVER_IS_DC              = &H00001000???
%SI_RESET_DACL_TREE           = &H00004000???
%SI_RESET_SACL_TREE           = &H00008000???
%SI_OBJECT_GUID               = &H00010000???
%SI_EDIT_EFFECTIVE            = &H00020000???
%SI_RESET_DACL                = &H00040000???
%SI_RESET_SACL                = &H00080000???
%SI_RESET_OWNER               = &H00100000???
%SI_NO_ADDITIONAL_PERMISSION  = &H00200000???
'#if (NTDDI_VERSION >= NTDDI_VISTA)
%SI_VIEW_ONLY                 = &H00400000???
%SI_PERMS_ELEVATION_REQUIRED  = &H01000000???
%SI_AUDITS_ELEVATION_REQUIRED = &H02000000???
%SI_OWNER_ELEVATION_REQUIRED  = &H04000000???
'#endif // (NTDDI_VERSION >= NTDDI_VISTA)
%SI_MAY_WRITE                 = &H10000000???   ' // not sure if user can write permission

%SI_EDIT_ALL = %SI_EDIT_PERMS OR %SI_EDIT_OWNER OR %SI_EDIT_AUDITS

' // Size = 16 bytes
TYPE SI_ACCESS DWORD
   pguid   AS GUID PTR       ' const GUID *
   mask    AS ACCESS_MASK    ' ACCESS_MASK
   pszName AS WSTRINGZ PTR   ' LPCWSTR // may be resource ID
   dwFlags AS DWORD          ' DWORD
END TYPE

'// SI_ACCESS flags
%SI_ACCESS_SPECIFIC  = &H00010000???
%SI_ACCESS_GENERAL   = &H00020000???
%SI_ACCESS_CONTAINER = &H00040000???  ' // general access, container-only
%SI_ACCESS_PROPERTY  = &H00080000???
'// ACE inheritance flags (CONTAINER_INHERIT_ACE, etc.) may also be set.
'// They will be used as the inheritance when an access is turned on.

' // Size = 12 bytes
TYPE SI_INHERIT_TYPE DWORD
   pguid   AS GUID PTR       ' const GUID *
   dwFlags AS DWORD          ' ULONG
   pszName AS WSTRINGZ PTR   ' LPCWSTR // may be resource ID
END TYPE

'// SI_INHERIT_TYPE flags are a combination of INHERIT_ONLY_ACE,
'// CONTAINER_INHERIT_ACE, and OBJECT_INHERIT_ACE.

' SI_PAGE_TYPE enum
MACRO SI_PAGE_TYPE_ENUM = LONG
%SI_PAGE_PERM          = 0
%SI_PAGE_ADVPERM       = 1
%SI_PAGE_AUDIT         = 2
%SI_PAGE_OWNER         = 3
%SI_PAGE_EFFECTIVE     = 4
'#if (NTDDI_VERSION >= NTDDI_VISTA)
%SI_PAGE_TAKEOWNERSHIP = 5
'#endif // (NTDDI_VERSION >= NTDDI_VISTA)

'// Message to PropertySheetPageCallback (in addition to
'// PSPCB_CREATE and PSPCB_RELEASE)
%PSPCB_SI_INITDIALOG   = %WM_USER + 1

$IID_ISecurityInformation    = GUID$("{965FC360-16FF-11D0-91CB-00AA00BBB723}")
$IID_ISecurityInformation2   = GUID$("{C3CCFDB4-6F88-11D2-A3CE-00C04FB1782A}")
$IID_IEffectivePermission    = GUID$("{3853DC76-9F35-407C-88A1-D19344365FBC}")
$IID_ISecurityObjectTypeInfo = GUID$("{FC3066EB-79EF-444B-9111-D18A75EBF2FA}")
'#if (NTDDI_VERSION >= NTDDI_VISTA)
$IID_ISecurityInformation3   = GUID$("{E2CDC9CC-31BD-4F8F-8C8B-B641AF516A1A}")
'#endif // (NTDDI_VERSION >= NTDDI_VISTA)

' ########################################################################################
' ISecurityInformation interface
' IID = 965fc360-16ff-11d0-91cb-00aa00bbb723
' Inherited interface = IUnknown
' ########################################################################################

INTERFACE ISecurityInformation $IID_ISecurityInformation

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetObjectInformation ( _                      ' VTable offset = 12
     BYREF pObjectInfo AS SI_OBJECT_INFO _              ' __out PSI_OBJECT_INFO pObjectInfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSecurity ( _                               ' VTable offset = 16
     BYVAL RequestedInformation AS SECURITY_INFORMATION _ ' __in SECURITY_INFORMATION RequestedInformation
   , BYREF ppSecurityDescriptor AS DWORD _              ' __out PSECURITY_DESCRIPTOR *ppSecurityDescriptor
   , BYVAL fDefault AS LONG _                           ' __in BOOL fDefault
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetSecurity ( _                               ' VTable offset = 20
     BYVAL SecurityInformation AS SECURITY_INFORMATION _ ' __in SECURITY_INFORMATION SecurityInformation
   , BYREF pSecurityDescriptor AS SECURITY_DESCRIPTOR _ ' __in PSECURITY_DESCRIPTOR pSecurityDescriptor
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAccessRights ( _                           ' VTable offset = 24
     BYREF pguidObjectType AS GUID _                    ' __in const GUID* pguidObjectType
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags // SI_EDIT_AUDITS, SI_EDIT_PROPERTIES
   , BYREF ppAccess AS SI_ACCESS _                      ' __out PSI_ACCESS *ppAccess
   , BYREF pcAccesses AS DWORD _                        ' __out ULONG *pcAccesses
   , BYREF piDefaultAccess AS DWORD _                   ' __out ULONG *piDefaultAccess
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD MapGeneric ( _                                ' VTable offset = 28
     BYREF pguidObjectType AS GUID _                    ' __in const GUID *pguidObjectType
   , BYVAL pAceFlags AS BYTE PTR _                      ' __in UCHAR *pAceFlags
   , BYVAL pMask AS ACCESS_MASK _                       ' __in ACCESS_MASK *pMask
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetInheritTypes ( _                           ' VTable offset = 32
     BYREF ppInheritTypes AS SI_INHERIT_TYPE _          ' __out PSI_INHERIT_TYPE *ppInheritTypes
   , BYREF pcInheritTypes AS DWORD _                    ' __out ULONG *pcInheritTypes
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD PropertySheetPageCallback ( _                 ' VTable offset = 36
     BYVAL hwnd AS DWORD _                              ' __in HWND hwnd
   , BYVAL uMsg AS DWORD _                              ' __in UINT uMsg
   , BYVAL uPage AS SI_PAGE_TYPE_ENUM _                 ' __in SI_PAGE_TYPE uPage
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE


' ########################################################################################
' ISecurityInformation2 interface
' IID = c3ccfdb4-6f88-11d2-a3ce-00c04fb1782a
' Inherited interface = IUnknown
' ########################################################################################

INTERFACE ISecurityInformation2 $IID_ISecurityInformation2

   INHERIT IUnknown

   ' =====================================================================================
   METHOD IsDaclCanonical ( _                           ' VTable offset = 12
     BYVAL pDacl AS ACL PTR _                           ' __in PACL pDacl
   ) AS LONG                                            ' BOOL
   ' =====================================================================================
   METHOD LookupSids ( _                                ' VTable offset = 16
     BYVAL cSids AS DWORD _                             ' __in ULONG cSids
   , BYVAL rgpSids AS SID PTR _                         ' __in PSID *rgpSids
   , BYREF ppdo AS IDataObject _                        ' __out LPDATAOBJECT *ppdo
   ) AS LONG                                            ' BOOL
   ' =====================================================================================

END INTERFACE

'// HGLOBAL containing SID_INFO_LIST returned by ISecurityInformation2::LookupSids
'#define CFSTR_ACLUI_SID_INFO_LIST   TEXT("CFSTR_ACLUI_SID_INFO_LIST")
$$CFSTR_ACLUI_SID_INFO_LIST = "CFSTR_ACLUI_SID_INFO_LIST"$$

'// Data structures corresponding to CFSTR_ACLUI_SID_INFO_LIST

' // Size = 16 bytes
TYPE SID_INFO DWORD
   pSid          AS SID PTR        ' PSID
   pwzCommonName AS WSTRINGZ PTR   ' PWSTR
   pwzClass      AS WSTRINGZ PTR   ' PWSTR // Used for selecting icon, e.g. "User" or "Group"
   pwzUPN        AS WSTRINGZ PTR   ' PWSTR // Optional, may be NULL
END TYPE

' // Size = 20 bytes
TYPE SID_INFO_LIST DWORD
   cItems        AS DWORD      ' ULONG
   aSidInfo(0)   AS SID_INFO   ' SID_INFO[ANYSIZE_ARRAY];
END TYPE


' ########################################################################################
' IEffectivePermission interface
' IID = 3853dc76-9f35-407c-88a1-d19344365fbc
' Inherited interface = IUnknown
' ########################################################################################

INTERFACE IEffectivePermission $IID_IEffectivePermission

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetEffectivePermission ( _                    ' VTable offset = 12
     BYREF pguidObjectType AS GUID _                    ' __in const GUID* pguidObjectType
   , BYVAL pUserSid AS SID PTR _                        ' __in PSID pUserSid
   , BYREF pszServerName AS WSTRINGZ _                  ' __in LPCWSTR pszServerName
   , BYREF pSD AS SECURITY_DESCRIPTOR _                 ' __in PSECURITY_DESCRIPTOR pSD
   , BYREF ppObjectTypeList AS OBJECT_TYPE_LIST _       ' __out POBJECT_TYPE_LIST *ppObjectTypeList
   , BYREF pcObjectTypeListLength AS DWORD _            ' __out ULONG *pcObjectTypeListLength
   , BYREF ppGrantedAccessList AS ACCESS_MASK _         ' __out PACCESS_MASK *ppGrantedAccessList
   , BYREF pcGrantedAccessListLength AS DWORD _         ' __out ULONG *pcGrantedAccessListLength
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE


' ########################################################################################
' ISecurityObjectTypeInfo interface
' IID = fc3066eb-79ef-444b-9111-d18a75ebf2fa
' Inherited interface = IUnknown
' ########################################################################################

INTERFACE ISecurityObjectTypeInfo $IID_ISecurityObjectTypeInfo

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetInheritSource ( _                          ' VTable offset = 12
     BYVAL si AS SECURITY_INFORMATION _                 ' __in SECURITY_INFORMATION si
   , BYVAL pACL AS ACL PTR _                            ' __in PACL pACL
   , BYREF ppInheritArray AS INHERITED_FROM _           ' __out PINHERITED_FROM *ppInheritArray
   ) AS LONG                                            ' BOOL
   ' =====================================================================================

END INTERFACE

'#if (NTDDI_VERSION >= NTDDI_VISTA)
'// Support for separation or read-only ACL viewer and elevated ACL editor

' ########################################################################################
' ISecurityInformation3 interface
' IID = E2CDC9CC-31BD-4f8f-8C8B-B641AF516A1A
' Inherited interface = IUnknown
' Note: Requires Windows Vista.
' ########################################################################################

INTERFACE ISecurityInformation3 $IID_ISecurityInformation3

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetFullResourceName ( _                       ' VTable offset = 12
     BYREF ppszResourceName AS DWORD _                  ' __out LPWSTR *ppszResourceName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OpenElevatedEditor ( _                        ' VTable offset = 16
     BYVAL hWnd AS DWORD _                              ' __in HWND hWnd
   , BYVAL uPage AS SI_PAGE_TYPE_ENUM _                 ' __in SI_PAGE_TYPE uPage
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

'#endif // (NTDDI_VERSION >= NTDDI_VISTA)


DECLARE FUNCTION CreateSecurityPage IMPORT "ACLUI.DLL" ALIAS "CreateSecurityPage" ( _
   BYVAL psi AS ISecurityInformation _                  ' __in LPSECURITYINFO psi
 ) AS DWORD                                             ' HPROPSHEETPAGE

DECLARE FUNCTION EditSecurity IMPORT "ACLUI.DLL" ALIAS "EditSecurity" ( _
   BYVAL hwndOwner AS DWORD _                           ' __in HWND hwndOwner
 , BYVAL psi AS ISecurityInformation _                  ' __in LPSECURITYINFO psi
 ) AS LONG                                              ' BOOL

'#if (NTDDI_VERSION >= NTDDI_VISTA)
DECLARE FUNCTION EditSecurityAdvanced IMPORT "ACLUI.DLL" ALIAS "EditSecurityAdvanced" ( _
   BYVAL hwndOwner AS DWORD _                           ' __in HWND hwndOwner
 , BYVAL psi AS ISecurityInformation _                  ' __in LPSECURITYINFO psi
 , BYVAL uSIPage AS SI_PAGE_TYPE_ENUM _                 ' __in SI_PAGE_TYPE uSIPage
 ) AS LONG                                              ' HRESULT
'#endif // (NTDDI_VERSION >= NTDDI_VISTA)
