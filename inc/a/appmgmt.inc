' ########################################################################################
' Microsoft Windows
' File: appmgmt.inc
' Contents: APIs for operations on MSI applications which are deployed and managed in the NT Directory.
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%APPMGMT_INC = 1

'typedef enum _INSTALLSPECTYPE
'{
'    APPNAME = 1,
'    FILEEXT,
'    PROGID,
'    COMCLASS
'} INSTALLSPECTYPE;

%INSTALLSPECTYPE_APPNAME  = 1
%INSTALLSPECTYPE_FILEEXT  = 2
%INSTALLSPECTYPE_PROGID   = 3
%INSTALLSPECTYPE_COMCLASS = 4

TYPE INSTALLSPEC_AppName DWORD
   Name  AS WSTRINGZ PTR   ' WCHAR * Name
   GPOId AS GUID           ' GUID    GPOId
END TYPE

TYPE INSTALLSPEC_COMClass DWORD
   Clsid  AS GUID
   ClsCtx AS DWORD
END TYPE

UNION INSTALLSPEC DWORD
   INSTALLSPEC_AppName
   FileExt AS WSTRINGZ PTR   ' WCHAR * FileExt
   ProgId  AS WSTRINGZ PTR   ' WCHAR * ProgId
   INSTALLSPEC_COMClass
END UNION

' // Size = 24 bytes
TYPE INSTALLDATA DWORD
   Type AS LONG          ' INSTALLSPECTYPE Type
   Spec AS INSTALLSPEC   ' INSTALLSPEC     Spec
END TYPE

'typedef enum
'{
'    ABSENT,
'    ASSIGNED,
'    PUBLISHED
'} APPSTATE;

%APPSTATE_ABSENT    = 0
%APPSTATE_ASSIGNED  = 1
%APPSTATE_PUBLISHED = 2

%LOCALSTATE_ASSIGNED                 = &H1    ' // app is assigned
%LOCALSTATE_PUBLISHED                = &H2    ' // app is published
%LOCALSTATE_UNINSTALL_UNMANAGED      = &H4    ' // uninstall any unmanaged version before assigning
%LOCALSTATE_POLICYREMOVE_ORPHAN      = &H8    ' // app is orphaned when policy removed
%LOCALSTATE_POLICYREMOVE_UNINSTALL   = &H10   ' // app is uninstalled when policy removed
%LOCALSTATE_ORPHANED                 = &H20   ' // app is orphaned after being applied
%LOCALSTATE_UNINSTALLED              = &H40   ' // app is uninstalled after being applied

' // Size = 16 bytes
TYPE LOCALMANAGEDAPPLICATION DWORD
   pszDeploymentName AS WSTRINGZ PTR   ' LPWSTR
   pszPolicyName     AS WSTRINGZ PTR   ' LPWSTR
   pszProductId      AS WSTRINGZ PTR   ' LPWSTR
   dwState           AS DWORD          ' DWORD
END TYPE

%MANAGED_APPS_USERAPPLICATIONS    = &H1
%MANAGED_APPS_FROMCATEGORY        = &H2
%MANAGED_APPS_INFOLEVEL_DEFAULT   = &H10000

%MANAGED_APPTYPE_WINDOWSINSTALLER = &H1
%MANAGED_APPTYPE_SETUPEXE         = &H2
%MANAGED_APPTYPE_UNSUPPORTED      = &H3

' // Size = 88 bytes
TYPE MANAGEDAPPLICATION DWORD
   pszPackageName AS WSTRINGZ PTR   ' LPWSTR
   pszPublisher   AS WSTRINGZ PTR   ' LPWSTR
   dwVersionHi    AS DWORD          ' DWORD
   dwVersionLo    AS DWORD          ' DWORD
   dwRevision     AS DWORD          ' DWORD
   GpoId          AS GUID           ' GUID
   pszPolicyName  AS WSTRINGZ PTR   ' LPWSTR
   ProductId      AS GUID           ' GUID
   Language       AS WORD           ' LANGID
   pszOwner       AS WSTRINGZ PTR   ' LPWSTR
   pszCompany     AS WSTRINGZ PTR   ' LPWSTR
   pszComments    AS WSTRINGZ PTR   ' LPWSTR
   pszContact     AS WSTRINGZ PTR   ' LPWSTR
   pszSupportUrl  AS WSTRINGZ PTR   ' LPWSTR
   dwPathType     AS DWORD          ' DWORD
   bInstalled     AS LONG           ' BOOL
END TYPE

' // Size = 24 bytes
TYPE APPCATEGORYINFO DWORD
   Locale         AS DWORD          ' LCID
   pszDescription AS WSTRINGZ PTR   ' LPWSTR
   AppCategoryId  AS GUID           ' GUID
END TYPE

' // Size = 8 bytes
TYPE APPCATEGORYINFOLIST DWORD
   cCategory     AS DWORD       ' DWORD
   pCategoryInfo AS DWORD       ' APPCATEGORYINFO PTR
END TYPE


DECLARE FUNCTION InstallApplication IMPORT "ADVAPI32.DLL" ALIAS "InstallApplication" ( _
   BYREF pInstallInfo AS INSTALLDATA _                  ' __in PINSTALLDATA pInstallInfo
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION UninstallApplication IMPORT "ADVAPI32.DLL" ALIAS "UninstallApplication" ( _
   BYREF ProductCode AS WSTRINGZ _                      ' __in WCHAR *ProductCode
 , BYVAL dwStatus AS DWORD _                            ' __in DWORD  dwStatus
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION CommandLineFromMsiDescriptor IMPORT "ADVAPI32.DLL" ALIAS "CommandLineFromMsiDescriptor" ( _
   BYREF Descriptor AS WSTRINGZ _                       ' __in WCHAR *Descriptor
 , BYREF CommandLine AS WSTRINGZ _                      ' __in WCHAR *CommandLine
 , BYVAL CommandLineLength AS DWORD _                   ' __in DWORD *CommandLineLength
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION GetManagedApplications IMPORT "ADVAPI32.DLL" ALIAS "GetManagedApplications" ( _
   BYREF pCategory AS GUID _                            ' __in  GUID                *pCategory
 , BYVAL dwQueryFlags AS DWORD _                        ' __in  DWORD                dwQueryFlags
 , BYVAL dwInfoLevel AS DWORD _                         ' __in  DWORD                dwInfoLevel
 , BYREF pdwApps AS DWORD _                             ' __out LPDWORD              pdwApps
 , BYREF prgManagedApps AS MANAGEDAPPLICATION _         ' __out PMANAGEDAPPLICATION* prgManagedApps
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION GetLocalManagedApplications IMPORT "ADVAPI32.DLL" ALIAS "GetLocalManagedApplications" ( _
   BYVAL bUserApps AS LONG _                            ' __in  BOOL                 bUserApps
 , BYREF pdwApps AS DWORD _                             ' __out LPDWORD              pdwApps
 , BYREF prgLocalApps AS MANAGEDAPPLICATION _           ' __out PMANAGEDAPPLICATION* prgLocalApps
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION GetLocalManagedApplicationData IMPORT "ADVAPI32.DLL" ALIAS "GetLocalManagedApplicationData" ( _
   BYREF ProductCode AS WSTRINGZ _                      ' __in WCHAR  *ProductCode
 , BYREF DisplayName AS DWORD _                         ' __out LPWSTR *DisplayName
 , BYREF SupportUrl AS DWORD _                          ' __out LPWSTR *SupportUrl
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION GetManagedApplicationCategories IMPORT "ADVAPI32.DLL" ALIAS "GetManagedApplicationCategories" ( _
   BYVAL dwReserved AS DWORD _                          ' __in  DWORD                dwReserved
 , BYREF pAppCategory AS APPCATEGORYINFOLIST _          ' __out APPCATEGORYINFOLIST* pAppCategory
 ) AS DWORD                                             ' DWORD
