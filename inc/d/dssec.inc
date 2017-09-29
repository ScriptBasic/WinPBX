' ########################################################################################
' Microsoft Windows
' File: dssec.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%DSSEC_INC = 1

#INCLUDE ONCE "aclui.inc"   ' // LPSECURITYINFO

'//+---------------------------------------------------------------------------
'//
'//  Function:   PFNREADOBJECTSECURITY
'//
'//  Synopsis:   Reads the security descriptor of a DS object
'//
'//  Arguments:  [IN  LPCWSTR]               --  ADS path of DS Object
'//              [IN  SECURITY_INFORMATION]  --  Which SD parts to read
'//              [OUT PSECURITY_DESCRIPTOR*] --  Return SD here. Caller frees with LocalFree
'//              [IN  LPARAM]                --  Context param
'//
'//  Return:     HRESULT
'//
'//----------------------------------------------------------------------------
'//
'//  Function:   PFNWRITEOBJECTSECURITY
'//
'//  Synopsis:   Writes a security descriptor to a DS object
'//
'//  Arguments:  [IN  LPCWSTR]               --  ADS path of DS Object
'//              [IN  SECURITY_INFORMATION]  --  Which SD parts to write
'//              [OUT PSECURITY_DESCRIPTOR]  --  Security descriptor to write
'//              [IN  LPARAM]                --  Context param
'//
'//  Return:     HRESULT
'//
'//----------------------------------------------------------------------------
'typedef HRESULT (WINAPI *PFNREADOBJECTSECURITY)(LPCWSTR, SECURITY_INFORMATION, PSECURITY_DESCRIPTOR*, LPARAM);
'typedef HRESULT (WINAPI *PFNWRITEOBJECTSECURITY)(LPCWSTR, SECURITY_INFORMATION, PSECURITY_DESCRIPTOR, LPARAM);

'FUNCTION READOBJECTSECURITY ( _
'   BYREF pwszAdsPath AS WSTRINGZ _            ' IN LPCWSTR
' , BYVAL secinfo AS SECURITY_INFORMATION _    ' IN SECURITY_INFORMATION
' , BYREF sd AS SECURITY_DESCRIPTOR _          ' OUT PSECURITY_DESCRIPTOR
' , BYVAL lParam AS LONG _                     ' IN LPARAM
' ) AS LONG                                    ' HRESULT
'END FUNCTION

'FUNCTION WRITEOBJECTSECURITY ( _
'   BYREF pwszAdsPath AS WSTRINGZ _            ' IN LPCWSTR
' , BYVAL secinfo AS SECURITY_INFORMATION _    ' IN SECURITY_INFORMATION
' , BYREF sd AS SECURITY_DESCRIPTOR _          ' OUT PSECURITY_DESCRIPTOR
' , BYVAL lParam AS LONG _                     ' IN LPARAM
' ) AS LONG                                    ' HRESULT
'END FUNCTION

'//+---------------------------------------------------------------------------
'//
'//  Function:   DSCreateISecurityInfoObject
'//
'//  Synopsis:   Instantiates an ISecurityInfo interface for a DS object
'//
'//  Arguments:  [IN  pwszObjectPath]    --  Full ADS path of DS object
'//              [IN  pwszObjectClass]   --  Class of the object (optional)
'//              [IN  dwFlags]           --  Combination of DSSI_* flags
'//              [OUT ppSI]              --  Interface pointer returned here
'//              [IN  pfnReadSD]         --  Optional function for reading SD
'//              [IN  pfnWriteSD]        --  Optional function for writing SD
'//              [IN  LPARAM]            --  Passed to pfnReadSD/pfnWriteSD
'//
'//  Return:     HRESULT
'//
'//----------------------------------------------------------------------------

DECLARE FUNCTION DSCreateISecurityInfoObject IMPORT "DSSEC.DLL" ALIAS "DSCreateISecurityInfoObject" ( _
   BYREF pwszObjectPath AS WSTRINGZ _                   ' __in  LPCWSTR pwszObjectPath
 , BYREF pwszObjectClass AS WSTRINGZ _                  ' __in  LPCWSTR pwszObjectClass
 , BYVAL dwFlags AS DWORD _                             ' __in  DWORD dwFlags
 , BYREF ppSI AS ISecurityInformation _                 ' __out LPSECURITYINFO *ppSI
 , BYVAL pfnReadSD AS DWORD _                           ' __in_opt PFNREADOBJECTSECURITY pfnReadSD
 , BYVAL pfnWriteSD AS DWORD _                          ' __in_opt PFNWRITEOBJECTSECURITY pfnWriteSD
 , BYVAL lpContext AS LONG _                            ' __in  LPARAM lpContext
 ) AS LONG                                              ' HRESULT


%DSSI_READ_ONLY           = &H00000001???
%DSSI_NO_ACCESS_CHECK     = &H00000002???
%DSSI_NO_EDIT_SACL        = &H00000004???
%DSSI_NO_EDIT_OWNER       = &H00000008???
%DSSI_IS_ROOT             = &H00000010???
%DSSI_NO_FILTER           = &H00000020???
%DSSI_NO_READONLY_MESSAGE = &H00000040???

'//
'// Same as above, with optional server, user & password arguments.
'// If use & password are not provided, ADSI defaults are used.
'// If the server is not provided, it is obtained from the object
'// path or DsGetDcName.
'//

DECLARE FUNCTION DSCreateISecurityInfoObjectEx IMPORT "DSSEC.DLL" ALIAS "DSCreateISecurityInfoObjectEx" ( _
   BYREF pwszObjectPath AS WSTRINGZ _                   ' __in  LPCWSTR pwszObjectPath
 , BYREF pwszObjectClass AS WSTRINGZ _                  ' __in  LPCWSTR pwszObjectClass
 , BYREF pwszServer AS WSTRINGZ _                       ' __in  LPCWSTR pwszServer
 , BYREF pwszUserName AS WSTRINGZ _                     ' __in  LPCWSTR pwszUserName
 , BYREF pwszPassword AS WSTRINGZ _                     ' __in  LPCWSTR pwszPassword
 , BYVAL dwFlags AS DWORD _                             ' __in  DWORD dwFlags
 , BYREF ppSI AS ISecurityInformation _                 ' __out LPSECURITYINFO *ppSI
 , BYVAL pfnReadSD AS DWORD _                           ' __in_opt PFNREADOBJECTSECURITY pfnReadSD
 , BYVAL pfnWriteSD AS DWORD _                          ' __in_opt PFNWRITEOBJECTSECURITY pfnWriteSD
 , BYVAL lpContext AS LONG _                            ' __in  LPARAM lpContext
 ) AS LONG                                              ' HRESULT


'//+---------------------------------------------------------------------------
'//
'//  Function:   DSCreateSecurityPage
'//
'//  Synopsis:   Creates a Security property page for a DS object
'//
'//  Arguments:  [IN  pwszObjectPath]    --  Full ADS path of DS object
'//              [IN  pwszObjectClass]   --  Class of the object (optional)
'//              [IN  dwFlags]           --  Combination of DSSI_* flags
'//              [OUT phPage]            --  HPROPSHEETPAGE returned here
'//              [IN  pfnReadSD]         --  Optional function for reading SD
'//              [IN  pfnWriteSD]        --  Optional function for writing SD
'//              [IN  LPARAM]            --  Passed to pfnReadSD/pfnWriteSD
'//
'//  Return:     HRESULT
'//
'//----------------------------------------------------------------------------

DECLARE FUNCTION DSCreateSecurityPage IMPORT "DSSEC.DLL" ALIAS "DSCreateSecurityPage" ( _
   BYREF pwszObjectPath AS WSTRINGZ _                   ' __in  LPCWSTR pwszObjectPath
 , BYREF pwszObjectClass AS WSTRINGZ _                  ' __in  LPCWSTR pwszObjectClass
 , BYVAL dwFlags AS DWORD _                             ' __in  DWORD dwFlags
 , BYREF phPage AS DWORD _                              ' __out HPROPSHEETPAGE *phPage
 , BYVAL pfnReadSD AS DWORD _                           ' __in_opt PFNREADOBJECTSECURITY pfnReadSD
 , BYVAL pfnWriteSD AS DWORD _                          ' __in_opt PFNWRITEOBJECTSECURITY pfnWriteSD
 , BYVAL lpContext AS LONG _                            ' __in  LPARAM lpContext
 ) AS LONG                                              ' HRESULT

'//+---------------------------------------------------------------------------
'//
'//  Function:   DSEditSecurity
'//
'//  Synopsis:   Displays a modal dialog for editing security on a DS object
'//
'//  Arguments:  [IN  hwndOwner]         --  Dialog owner window
'//              [IN  pwszObjectPath]    --  Full ADS path of DS object
'//              [IN  pwszObjectClass]   --  Class of the object (optional)
'//              [IN  dwFlags]           --  Combination of DSSI_* flags
'//              [IN  pwszCaption]       --  Optional dialog caption
'//              [IN  pfnReadSD]         --  Optional function for reading SD
'//              [IN  pfnWriteSD]        --  Optional function for writing SD
'//              [IN  LPARAM]            --  Passed to pfnReadSD/pfnWriteSD
'//
'//  Return:     HRESULT
'//
'//----------------------------------------------------------------------------

DECLARE FUNCTION DSEditSecurity IMPORT "DSSEC.DLL" ALIAS "DSEditSecurity" ( _
   BYREF pwszObjectPath AS WSTRINGZ _                   ' __in  LPCWSTR pwszObjectPath
 , BYREF pwszObjectClass AS WSTRINGZ _                  ' __in  LPCWSTR pwszObjectClass
 , BYVAL dwFlags AS DWORD _                             ' __in  DWORD dwFlags
 , BYREF pwszCaption AS WSTRINGZ _                      ' __in  LPCWSTR pwszCaption
 , BYVAL pfnReadSD AS DWORD _                           ' __in_opt PFNREADOBJECTSECURITY pfnReadSD
 , BYVAL pfnWriteSD AS DWORD _                          ' __in_opt PFNWRITEOBJECTSECURITY pfnWriteSD
 , BYVAL lpContext AS LONG _                            ' __in  LPARAM lpContext
 ) AS LONG                                              ' HRESULT

'FUNCTION DSCREATEISECINFO ( _
'   BYREF pwszObjectPath AS WSTRINGZ _                   ' __in  LPCWSTR pwszObjectPath
' , BYREF pwszObjectClass AS WSTRINGZ _                  ' __in  LPCWSTR pwszObjectClass
' , BYVAL dwFlags AS DWORD _                             ' __in  DWORD dwFlags
' , BYREF ppSI AS ISecurityInformation _                 ' __out LPSECURITYINFO *ppSI
' , BYVAL pfnReadSD AS DWORD _                           ' __in_opt PFNREADOBJECTSECURITY pfnReadSD
' , BYVAL pfnWriteSD AS DWORD _                          ' __in_opt PFNWRITEOBJECTSECURITY pfnWriteSD
' , BYVAL lpContext AS LONG _                            ' __in  LPARAM lpContext
' ) AS LONG                                              ' HRESULT

'END FUNCTION


'FUNCTION DSCREATEISECINFOEX ( _
'   BYREF pwszObjectPath AS WSTRINGZ _                   ' __in  LPCWSTR pwszObjectPath
' , BYREF pwszObjectClass AS WSTRINGZ _                  ' __in  LPCWSTR pwszObjectClass
' , BYREF pwszServer AS WSTRINGZ _                       ' __in  LPCWSTR pwszServer
' , BYREF pwszUserName AS WSTRINGZ _                     ' __in  LPCWSTR pwszUserName
' , BYREF pwszPassword AS WSTRINGZ _                     ' __in  LPCWSTR pwszPassword
' , BYVAL dwFlags AS DWORD _                             ' __in  DWORD dwFlags
' , BYREF ppSI AS ISecurityInformation _                 ' __out LPSECURITYINFO *ppSI
' , BYVAL pfnReadSD AS DWORD _                           ' __in_opt PFNREADOBJECTSECURITY pfnReadSD
' , BYVAL pfnWriteSD AS DWORD _                          ' __in_opt PFNWRITEOBJECTSECURITY pfnWriteSD
' , BYVAL lpContext AS LONG _                            ' __in  LPARAM lpContext
' ) AS LONG                                              ' HRESULT

'END FUNCTION

'FUNCTION DSCREATESECPAGE ( _
'   BYREF pwszObjectPath AS WSTRINGZ _                   ' __in  LPCWSTR pwszObjectPath
' , BYREF pwszObjectClass AS WSTRINGZ _                  ' __in  LPCWSTR pwszObjectClass
' , BYVAL dwFlags AS DWORD _                             ' __in  DWORD dwFlags
' , BYREF phPage AS DWORD _                              ' __out HPROPSHEETPAGE* phPage
' , BYVAL pfnReadSD AS DWORD _                           ' __in  PFNREADOBJECTSECURITY pfnReadSD
' , BYVAL pfnWriteSD AS DWORD _                          ' __in  PFNWRITEOBJECTSECURITY pfnWriteSD
' , BYVAL lParam AS LONG _                               ' __in  LPARAM lpContext
' ) AS LONG                                              ' HRESULT
'END FUNCTION

'FUNCTION DSEDITSECURITY ( _
'   BYREF pwszObjectPath AS WSTRINGZ _                   ' __in  LPCWSTR pwszObjectPath
' , BYREF pwszObjectClass AS WSTRINGZ _                  ' __in  LPCWSTR pwszObjectClass
' , BYVAL dwFlags AS DWORD _                             ' __in  DWORD dwFlags
' , BYREF pwszCaption AS WSTRINGZ _                      ' __in  LPCWSTR pwszCaption
' , BYVAL pfnReadSD AS DWORD _                           ' __in_opt PFNREADOBJECTSECURITY pfnReadSD
' , BYVAL pfnWriteSD AS DWORD _                          ' __in_opt PFNWRITEOBJECTSECURITY pfnWriteSD
' , BYVAL lpContext AS LONG _                            ' __in  LPARAM lpContext
' ) AS LONG                                              ' HRESULT

'END FUNCTION
