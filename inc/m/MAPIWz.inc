' ########################################################################################
' Microsoft Windows
' File: MAPIWz.inc
' Contents: Definitions for the Profile Wizard. Includes all prototypes and constants
' required by the provider-wizard code consumers.
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%MAPIWZ_INC = 1

#INCLUDE ONCE "WINDOWS.INC"

%WIZ_QUERYNUMPAGES = %WM_USER + 10
%WIZ_NEXT          = %WM_USER + 11
%WIZ_PREV          = %WM_USER + 12

'/*
' *   NOTE: Provider-Wizards should not use ids ranging between
' *   (WM_USER + 1) and (WM_USER +20) as these have been reserved for
' *   future releases.
' */

'/*   Flags for LaunchWizard API */

%MAPI_PW_FIRST_PROFILE      = &H00000001
%MAPI_PW_LAUNCHED_BY_CONFIG = &H00000002
%MAPI_PW_ADD_SERVICE_ONLY   = &H00000004
%MAPI_PW_PROVIDER_UI_ONLY   = &H00000008
%MAPI_PW_HIDE_SERVICES_LIST = &H00000010

'/*
' *  Provider should set this property to TRUE if it does not
' *  want the Profile Wizard to display the PST setup page.
' */
'#define PR_WIZARD_NO_PST_PAGE         PROP_TAG(PT_BOOLEAN, 0x6700)
'#define PR_WIZARD_NO_PAB_PAGE         PROP_TAG(PT_BOOLEAN, 0x6701)

%PR_WIZARD_NO_PST_PAGE = &H67000008
%PR_WIZARD_NO_PAB_PAGE = &H67010008

'typedef HRESULT (STDAPICALLTYPE LAUNCHWIZARDENTRY)
'(
'   HWND          hParentWnd,
'   ULONG         ulFlags,
'   LPCTSTR FAR * lppszServiceNameToAdd,
'   ULONG         cbBufferMax,
'   LPTSTR        lpszNewProfileName
');

'typedef BOOL (STDAPICALLTYPE SERVICEWIZARDDLGPROC)
'(
'   HWND         hDlg,
'   UINT         wMsgID,
'   WPARAM       wParam,
'   LPARAM       lParam
');

DECLARE FUNCTION LaunchWizard IMPORT "MAPI32.DLL" ALIAS "LAUNCHWIZARD" ( _
   BYVAL hParentWnd AS DWORD _                          ' __in  HWND hParentWnd
 , BYVAL ulFlags AS DWORD _                             ' __in  ULONG ulFlags
 , BYREF lppszServiceNameToAdd AS ASCIIZ _              ' __in  LPCTSTR FAR * lppszServiceNameToAdd [array]
 , BYVAL cbBufferMax AS DWORD _                         ' __in  ULONG cbBufferMax
 , BYREF lpszNewProfileName AS ASCIIZ _                 ' __out LPTSTR lpszNewProfileName
 ) AS LONG                                              ' HRESULT

' Note: You can also use LaunchWizard@20 as the alias name of the function.

' Example to use the LaunchWizard function
' ========================================================================================
'   DIM szServices(1) AS ASCIIZ * 256
'   DIM szProfName AS ASCIIZ * 80
'   DIM hr AS LONG

'   szServices(0) = "MSEMS"
'   szServices(1) = ""
'   hr = LaunchWizard(0, 0, szServices(0), SIZEOF(szProfName), szProfName)
' ========================================================================================

$LAUNCHWIZARDENTRYNAME = "LAUNCHWIZARD"
