' ########################################################################################
' Microsoft Windows
' File: GPEdit.inc
' Contents: Definitions and prototypes for Group Policy
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

'//
'// Terminology
'//
'// Group Policy Editor  -  The tool to view a Group Policy Object.
'//
'// Group Policy Object  -  A collection of administrator defined policies.
'//                         Each Group Policy Object (GPO) has both file system
'//                         and Active Directory storage available to it.
'//
'// IGPEInformation      -  The interface MMC Snapin Extensions use to
'//                         talk to the Group Policy Editor.
'//
'// IGroupPolicyObject   -  The interface used to create/edit a GPO directly
'//                         without going through the Group Policy Editor
'//

#INCLUDE THIS ONCE
%GPEDIT_INC = 1

#INCLUDE ONCE "objbase.inc"

'//
'// Group Policy Editor MMC SnapIn GUID
'//
'// {8FC0B734-A0E1-11d1-A7D3-0000F87571E3}

$CLSID_GPESnapIn = GUID$("{8FC0B734-A0E1-11d1-A7D3-0000F87571E3}")

'//
'// Group Policy Editor node ids
'//

'//
'// Computer Configuration\Windows Settings
'// {8FC0B737-A0E1-11d1-A7D3-0000F87571E3}
'//

$NODEID_Machine = GUID$("{8FC0B737-A0E1-11d1-A7D3-0000F87571E3}")


'//
'// Computer Configuration\Software Settings
'// {8FC0B73A-A0E1-11d1-A7D3-0000F87571E3}
'//

$NODEID_MachineSWSettings = GUID$("{8FC0B73A-A0E1-11d1-A7D3-0000F87571E3}")


'//
'// User Configuration\Windows Settings
'// {8FC0B738-A0E1-11d1-A7D3-0000F87571E3}
'//

$NODEID_User = GUID$("{8FC0B738-A0E1-11d1-A7D3-0000F87571E3}")


'//
'// User Configuration\Software Settings
'// {8FC0B73C-A0E1-11d1-A7D3-0000F87571E3}
'//

$NODEID_UserSWSettings = GUID$("{8FC0B73C-A0E1-11d1-A7D3-0000F87571E3}")


'//
'// IGPEInformation interface id
'//
'// {8FC0B735-A0E1-11d1-A7D3-0000F87571E3}

$IID_IGPEInformation = GUID$("{8FC0B735-A0E1-11d1-A7D3-0000F87571E3}")


'//
'// Group Policy Object class id
'//
'// {EA502722-A23D-11d1-A7D3-0000F87571E3}

$CLSID_GroupPolicyObject = GUID$("{EA502722-A23D-11d1-A7D3-0000F87571E3}")


'//
'// Group Policy Object interface id
'//
'// {EA502723-A23D-11d1-A7D3-0000F87571E3}

$IID_IGroupPolicyObject = GUID$("{EA502723-A23D-11d1-A7D3-0000F87571E3}")


'//
'// GUID that identifies the registry extension
'//

$REGISTRY_EXTENSION_GUID = GUID$("{35378EAC-683F-11D2-A89A-00C04FBBCFA2}")

'//
'// GUID that identifies the comments extension
'//

$ADMXCOMMENTS_EXTENSION_GUID = GUID$("{6C5A2A86-9EB3-42b9-AA83-A7371BA011B9}")


'//========================================================================================
'//
'// Resultant Set of Policy node ids
'//
'//========================================================================================

'//
'// Resultant Set of Policy MMC SnapIn GUID
'//
'// {6DC3804B-7212-458D-ADB0-9A07E2AE1FA2}

$CLSID_RSOPSnapIn = GUID$("{6DC3804B-7212-458D-ADB0-9A07E2AE1FA2}")


'//
'// Computer Configuration\Windows Settings
'// {BD4C1A2E-0B7A-4A62-A6B0-C0577539C97E}
'//

$NODEID_RSOPMachine = GUID$("{BD4C1A2E-0B7A-4A62-A6B0-C0577539C97E}")


'//
'// Computer Configuration\Software Settings
'// {6A76273E-EB8E-45DB-94C5-25663A5f2C1A}
'//

$NODEID_RSOPMachineSWSettings = GUID$("{6A76273E-EB8E-45DB-94C5-25663A5f2C1A}")


'//
'// User Configuration\Windows Settings
'// {AB87364F-0CEC-4CD8-9BF8-898F34628FB8}
'//

$NODEID_RSOPUser = GUID$("{AB87364F-0CEC-4CD8-9BF8-898F34628FB8}")


'//
'// User Configuration\Software Settings
'// {E52C5CE3-FD27-4402-84DE-D9A5F2858910}
'//

$NODEID_RSOPUserSWSettings = GUID$("{E52C5CE3-FD27-4402-84DE-D9A5F2858910}")


'//
'// IRSOPInformation interface id
'//
'// {9A5A81B5-D9C7-49EF-9D11-DDF50968C48D}

$IID_IRSOPInformation = GUID$("{9A5A81B5-D9C7-49EF-9D11-DDF50968C48D}")


'//
'// Define API decoration for direct importing of DLL references.
'//

'//
'// Group Policy Object Section flags
'//

%GPO_SECTION_ROOT               = 0  ' // Root
%GPO_SECTION_USER               = 1  ' // User
%GPO_SECTION_MACHINE            = 2  ' // Machine

'//
'// Group Policy Object types
'//

#IF NOT %DEF(%GROUP_POLICY_OBJECT_TYPE_ENUM_DEFINED)
%GROUP_POLICY_OBJECT_TYPE_ENUM_DEFINED = 1

' enum GROUP_POLICY_OBJECT_TYPE
%GPOTypeLocal      = 0    ' // Default GPO on the local machine
%GPOTypeRemote     = 1    ' // GPO on a remote machine
%GPOTypeDS         = 2    ' // GPO in the Active Directory
%GPOTypeLocalUser  = 3    ' // User-specific GPO on the local machine
%GPOTypeLocalGroup = 4    ' // Group-specific GPO on the local machine

#ENDIF   ' // GROUP_POLICY_OBJECT_TYPE_ENUM_DEFINED

'//
'// Group Policy Hint types
'//

' enum GROUP_POLICY_HINT_TYPE
%GPHintUnknown            = 0   ' // No link information available
%GPHintMachine            = 1   ' // GPO linked to a machine (local or remote)
%GPHintSite               = 2   ' // GPO linked to a site
%GPHintDomain             = 3   ' // GPO linked to a domain
%GPHintOrganizationalUnit = 4   ' // GPO linked to a organizational unit


' ########################################################################################
' Interface name = IGPEInformation
' IID = 8FC0B735-A0E1-11d1-A7D3-0000F87571E3
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IGPEInformation_INTERFACE_DEFINED)
    %IGPEInformation_INTERFACE_DEFINED = 1

INTERFACE IGPEInformation $IID_IGPEInformation

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetName ( _                                   ' VTable offset = 12
     BYREF pszName AS WSTRINGZ _                        ' __out LPOLESTR pszName
   , BYVAL cchMaxLength AS LONG _                       ' __in int cchMaxLength
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDisplayName ( _                            ' VTable offset = 16
     BYREF pszName AS WSTRINGZ _                        ' __out LPOLESTR pszName
   , BYVAL cchMaxLength AS LONG _                       ' __in int cchMaxLength
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRegistryKey ( _                            ' VTable offset = 20
     BYVAL dwSection AS DWORD _                         ' __in DWORD dwSection
   , BYREF hKey AS DWORD _                              ' __out HKEY *hKey
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDSPath ( _                                 ' VTable offset = 24
     BYVAL dwSection AS DWORD _                         ' __in DWORD dwSection
   , BYREF pszPath AS WSTRINGZ _                        ' __out LPOLESTR pszPath
   , BYVAL cchMaxPath AS LONG _                         ' __in int cchMaxPath
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFileSysPath ( _                            ' VTable offset = 28
     BYVAL dwSection AS DWORD _                         ' __in DWORD dwSection
   , BYREF pszPath AS WSTRINGZ _                        ' __out LPOLESTR pszPath
   , BYVAL cchMaxPath AS LONG _                         ' __in int cchMaxPath
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetOptions ( _                                ' VTable offset = 32
     BYREF dwOptions AS DWORD _                         ' __out DWORD *dwOptions
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetType ( _                                   ' VTable offset = 36
     BYREF gpoType AS LONG _                            ' __out GROUP_POLICY_OBJECT_TYPE *gpoType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetHint ( _                                   ' VTable offset = 40
     BYREF gpHint AS LONG _                             ' __out GROUP_POLICY_HINT_TYPE *gpHint
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD PolicyChanged ( _                             ' VTable offset = 44
     BYVAL bMachine AS LONG _                           ' __in BOOL bMachine
   , BYVAL bAdd AS LONG _                               ' __in BOOL bAdd
   , BYREF pGuidExtension AS GUID _                     ' __in GUID *pGuidExtension
   , BYREF pGuidSnapin AS GUID _                        ' __in GUID *pGuidSnapin
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IGPEInformation_INTERFACE_DEFINED__ */

'//
'// Group Policy Object open / creation flags
'//

%GPO_OPEN_LOAD_REGISTRY      = &H00000001???   ' // Load the registry files
%GPO_OPEN_READ_ONLY          = &H00000002???   ' // Open the GPO as read only


'//
'// Group Policy Object option flags
'//

%GPO_OPTION_DISABLE_USER     = &H00000001???   ' // The user portion of this GPO is disabled
%GPO_OPTION_DISABLE_MACHINE  = &H00000002???   ' // The machine portion of this GPO is disabled


' ########################################################################################
' Interface name = IGroupPolicyObject
' IID = EA502723-A23D-11d1-A7D3-0000F87571E3
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IGroupPolicyObject_INTERFACE_DEFINED)
    %IGroupPolicyObject_INTERFACE_DEFINED = 1

INTERFACE IGroupPolicyObject $IID_IGroupPolicyObject

   INHERIT IUnknown

   ' =====================================================================================
   METHOD New ( _                                       ' VTable offset = 12
     BYREF pszDomainName AS WSTRINGZ _                  ' __in LPOLESTR pszDomainName
   , BYREF pszDisplayName AS WSTRINGZ _                 ' __in LPOLESTR pszDisplayName
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OpenDSGPO ( _                                 ' VTable offset = 16
     BYREF pszPath AS WSTRINGZ _                        ' __in LPOLESTR pszPath
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OpenLocalMachineGPO ( _                       ' VTable offset = 20
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OpenRemoteMachineGPO ( _                      ' VTable offset = 24
     BYREF pszComputerName AS WSTRINGZ _                ' __in LPOLESTR pszComputerName
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Save ( _                                      ' VTable offset = 28
     BYVAL bMachine AS LONG _                           ' __in BOOL bMachine
   , BYVAL bAdd AS LONG _                               ' __in BOOL bAdd
   , BYREF pGuidExtension AS GUID _                     ' __in GUID *pGuidExtension
   , BYREF pGuid AS GUID _                              ' __in GUID *pGuid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Delete ( _                                    ' VTable offset = 32
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetName ( _                                   ' VTable offset = 36
     BYREF pszName AS WSTRINGZ _                        ' __out LPOLESTR pszName
   , BYVAL cchMaxLength AS LONG _                       ' __in int cchMaxLength
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDisplayName ( _                            ' VTable offset = 40
     BYREF pszName AS WSTRINGZ _                        ' __out LPOLESTR pszName
   , BYVAL cchMaxLength AS LONG _                       ' __in int cchMaxLength
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetDisplayName ( _                            ' VTable offset = 44
     BYREF pszName AS WSTRINGZ _                        ' __in LPOLESTR pszName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPath ( _                                   ' VTable offset = 48
     BYREF pszPath AS WSTRINGZ _                        ' __out LPOLESTR pszPath
   , BYVAL cchMaxPath AS LONG _                         ' __in int cchMaxPath
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDSPath ( _                                 ' VTable offset = 52
     BYVAL dwSection AS DWORD _                         ' __in DWORD dwSection
   , BYREF pszPath AS WSTRINGZ _                        ' __out LPOLESTR pszPath
   , BYVAL cchMaxPath AS LONG _                         ' __in int cchMaxPath
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFileSysPath ( _                            ' VTable offset = 52
     BYVAL dwSection AS DWORD _                         ' __in DWORD dwSection
   , BYREF pszPath AS WSTRINGZ _                        ' __out LPOLESTR pszPath
   , BYVAL cchMaxPath AS LONG _                         ' __in int cchMaxPath
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRegistryKey ( _                            ' VTable offset = 56
     BYVAL dwSection AS DWORD _                         ' __in DWORD dwSection
   , BYREF hKey AS DWORD _                              ' __out HKEY *hKey
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetOptions ( _                                ' VTable offset = 60
     BYREF dwOptions AS DWORD _                         ' __out DWORD *dwOptions
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetOptions ( _                                ' VTable offset = 64
     BYVAL dwOptions AS DWORD _                         ' __in DWORD dwOptions
   , BYVAL dwMask AS DWORD _                            ' __in DWORD dwMask
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetType ( _                                   ' VTable offset = 68
     BYREF gpoType AS LONG _                            ' __out GROUP_POLICY_OBJECT_TYPE *gpoType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMachineName ( _                            ' VTable offset = 72
     BYREF pszName AS WSTRINGZ _                        ' __out LPOLESTR pszName
   , BYVAL cchMaxLength AS LONG _                       ' __in int cchMaxLength
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPropertySheetPages ( _                     ' VTable offset = 76
     BYREF hPages AS DWORD _                            ' __out HPROPSHEETPAGE **hPages
   , BYREF uPageCount AS DWORD _                        ' __out UINT *uPageCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IGroupPolicyObject_INTERFACE_DEFINED__ */


'//
'// RSOP flags
'//

%RSOP_INFO_FLAG_DIAGNOSTIC_MODE  = &H00000001     ' // Running in diagnostic mode vs planning mode


' ########################################################################################
' Interface name = IRSOPInformation
' IID = 9A5A81B5-D9C7-49EF-9D11-DDF50968C48D
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IRSOPInformation_INTERFACE_DEFINED)
    %IRSOPInformation_INTERFACE_DEFINED = 1

INTERFACE IRSOPInformation $IID_IRSOPInformation

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetNamespace ( _                              ' VTable offset = 12
     BYVAL dwSection AS DWORD _                         ' __in DWORD dwSection
   , BYREF pszName AS WSTRINGZ _                        ' __out LPOLESTR pszName
   , BYVAL cchMaxLength AS LONG _                       ' __in int cchMaxLength
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFlags ( _                                  ' VTable offset = 16
     BYREF pdwFlags AS DWORD _                          ' __out DWORD * pdwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetEventLogEntryText ( _                      ' VTable offset = 20
     BYREF pszEventSource AS WSTRINGZ _                 ' __in LPOLESTR pszEventSource
   , BYREF pszEventLogName AS WSTRINGZ _                ' __in LPOLESTR pszEventLogName
   , BYREF pszEventTime AS WSTRINGZ _                   ' __in LPOLESTR pszEventTime
   , BYVAL dwEventID AS DWORD _                         ' __in DWORD dwEventID
   , BYREF ppszText AS DWORD _                          ' __out LPOLESTR *ppszText
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IRSOPInformation_INTERFACE_DEFINED__ */

'//=============================================================================
'//
'// CreateGPOLink
'//
'// Creates a link to a GPO for the specified Site, Domain, or Organizational Unit
'//
'// lpGPO         - ADSI path to the GPO
'// lpContainer   - ADSI path to the Site, Domain, or Organizational Unit
'// fHighPriority - Create the link as the highest or lowest priority
'//
'// Returns:  S_OK if successful
'//
'//=============================================================================

DECLARE FUNCTION CreateGPOLink IMPORT "Gpedit.dll" ALIAS "CreateGPOLink" ( _
   BYREF lpGPO AS WSTRINGZ _                            ' __in LPOLESTR lpGPO
 , BYREF lpContainer AS WSTRINGZ _                      ' __in LPOLESTR lpContainer
 , BYVAL fHighPriority AS LONG _                        ' __in BOOL fHighPriority
 ) AS LONG                                              ' HRESULT


'//=============================================================================
'//
'// DeleteGPOLink
'//
'// Deletes a link to a GPO for the specified Site, Domain, or Organizational Unit
'//
'// lpGPO         - ADSI path to the GPO
'// lpContainer   - ADSI path to the Site, Domain, or Organizational Unit
'//
'// Returns:  S_OK if successful
'//
'//=============================================================================

DECLARE FUNCTION CreateGPOLink IMPORT "Gpedit.dll" ALIAS "CreateGPOLink" ( _
   BYREF lpGPO AS WSTRINGZ _                            ' __in LPOLESTR lpGPO
 , BYREF lpContainer AS WSTRINGZ _                      ' __in LPOLESTR lpContainer
 , BYVAL fHighPriority AS LONG _                        ' __in BOOL fHighPriority
 ) AS LONG                                              ' HRESULT

'//=============================================================================
'//
'// DeleteAllGPOLinks
'//
'// Deletes all GPO links for the specified Site, Domain, or Organizational Unit
'//
'// lpContainer   - ADSI path to the Site, Domain, or Organizational Unit
'//
'// Returns:  S_OK if successful
'//
'//=============================================================================

DECLARE FUNCTION DeleteAllGPOLinks IMPORT "Gpedit.dll" ALIAS "DeleteAllGPOLinks" ( _
   BYREF lpContainer AS WSTRINGZ _                      ' __in LPOLESTR lpContainer
 ) AS LONG                                              ' HRESULT

'//=============================================================================
'//
'// BrowseForGPO
'//
'// Displays the GPO browser dialog
'//
'// lpBrowseInfo   - Address of a GPOBROWSEINFO structure
'//
'// Returns:  S_OK if successful
'//
'//=============================================================================

'//
'// Flags passed in the dwFlags field of the GPOBROWSEINFO structure
'//

%GPO_BROWSE_DISABLENEW           = &H00000001???   ' // Disables the New GPO functionality on all pages except "All"
%GPO_BROWSE_NOCOMPUTERS          = &H00000002???   ' // Removes the Computers tab
%GPO_BROWSE_NODSGPOS             = &H00000004???   ' // Removes the Domain/OU and Sites tabs
%GPO_BROWSE_OPENBUTTON           = &H00000008???   ' // Change the Ok button to say Open
%GPO_BROWSE_INITTOALL            = &H00000010???   ' // Initialize the dialog focused on the All pane
%GPO_BROWSE_NOUSERGPOS           = &H00000020???   ' // Removes the Users tab
%GPO_BROWSE_SENDAPPLYONEDIT      = &H00000040???   ' // Send the apply event if edit menu is selected

' // Size = 44 bytes
TYPE GPOBROWSEINFO DWORD
   dwSize       AS DWORD          ' DWORD // [in] Initialized to the size of this structure
   dwFlags      AS DWORD          ' DWORD // [in] Flags defined above
   hwndOwner    AS DWORD          ' HWND // [in] Parent window handle (can be NULL)
   lpTitle      AS WSTRINGZ PTR   ' LPOLESTR // [in] Title bar text.  If NULL, "Browse for a Group Policy Object" will be the default text
   lpInitialOU  AS WSTRINGZ PTR   ' LPOLESTR // [in] Initial Domain/Organizational Unit to open focus on
   lpDSPath     AS WSTRINGZ PTR   ' __field_ecount(dwDSPathSize) LPOLESTR // [in/out] Pointer to the buffer that receives the Active Directory GPO path
   dwDSPathSize AS DWORD          ' DWORD // [in] Size in characters of buffer given in lpDSPath
   lpName       AS WSTRINGZ PTR   ' __field_bcount( dwNameSize) LPOLESTR // [in/out] Pointer to a buffer that receives either the computer name or
                                  '       //      the friendly name of the GPO (can be NULL)
   dwNameSize   AS DWORD          ' DWORD // [in] Size in characters of buffer given in lpName
   gpoType      AS LONG           ' GROUP_POLICY_OBJECT_TYPE  // [out] Specifies the type of GPO
   gpoHint      AS LONG           ' GROUP_POLICY_HINT_TYPE // [out] Specifies a hint of the GPO association
END TYPE

DECLARE FUNCTION BrowseForGPO IMPORT "Gpedit.dll" ALIAS "BrowseForGPO" ( _
   BYREF lpBrowseInfo AS GPOBROWSEINFO _                ' __in_out LPGPOBROWSEINFO lpBrowseInfo
 ) AS LONG                                              ' HRESULT

'//=============================================================================
'//
'// ImportRSoPData
'//
'// Imports a data file generated by ExportRSoPData
'//
'// lpNameSpace   - Namespace to place the data in
'// lpFileName    - Filename containing the data
'//
'// Returns:  S_OK if successful
'//
'// Notes:    The namespace specified in lpNameSpace must exist prior to calling
'//           this function.
'//
'//=============================================================================

DECLARE FUNCTION ImportRSoPData IMPORT "Gpedit.dll" ALIAS "ImportRSoPData" ( _
   BYREF lpNameSpace AS WSTRINGZ _                     ' __in LPOLESTR lpNameSpace
 , BYREF lpFileName AS WSTRINGZ _                      ' __in LPOLESTR lpFileName
 ) AS LONG                                             ' HRESULT

'//=============================================================================
'//
'// ExportRSoPData
'//
'// Exports a WBEM namespace containing RSoP information to a data file.
'// This data file can be imported to a WBEM namespace using ImportRSoPData.
'//
'// lpNameSpace   - Namespace to read the data from
'// lpFileName    - Filename to receive the data
'//
'// Returns:  S_OK if successful
'//
'// Notes:    This function should be called twice.  Once for the user data
'//           and once for the computer data.
'//
'//=============================================================================

DECLARE FUNCTION ExportRSoPData IMPORT "Gpedit.dll" ALIAS "ExportRSoPData" ( _
   BYREF lpNameSpace AS WSTRINGZ _                      ' __in LPOLESTR lpNameSpace
 , BYREF lpFileName AS WSTRINGZ _                       ' __in LPOLESTR lpFileName
 ) AS LONG                                              ' HRESULT
