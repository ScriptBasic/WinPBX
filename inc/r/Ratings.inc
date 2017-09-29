' ########################################################################################
' Microsoft Windows
' File: Ratings.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

'#pragma once

#INCLUDE THIS ONCE
%RATINGS_INC = 1

#INCLUDE ONCE "winerror.inc"
#INCLUDE ONCE "shlwapi.inc"

DECLARE FUNCTION RatingEnable IMPORT "msrating.dll" ALIAS "RatingEnable" ( _
   BYVAL hwndParent AS DWORD _                          ' __in HWND hwndParent
 , BYREF pszUsername AS ASCIIZ _                        ' __in LPCSTR pszUsername
 , BYVAL fEnable AS LONG _                              ' __in BOOL fEnable
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION RatingEnableW IMPORT "msrating.dll" ALIAS "RatingEnableW" ( _
   BYVAL hwndParent AS DWORD _                          ' __in HWND hwndParent
 , BYREF pszUsername AS WSTRINGZ _                      ' __in LPCWSTR pszUsername
 , BYVAL fEnable AS LONG _                              ' __in BOOL fEnable
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION RatingCheckUserAccess IMPORT "msrating.dll" ALIAS "RatingCheckUserAccess" ( _
   BYREF pszUsername AS ASCIIZ _                        ' __in_opt LPCSTR pszUsername
 , BYREF pszURL AS ASCIIZ _                             ' __in_opt LPCSTR pszURL
 , BYREF pszRatingInfo AS ASCIIZ _                      ' __in_opt LPCSTR pszRatingInfo
 , BYVAL pData AS BYTE PTR _                            ' __in LPBYTE pData
 , BYVAL cbData AS DWORD _                              ' __in DWORD cbData
 , BYREF ppRatingDetails AS DWORD _                     ' __out_opt void **ppRatingDetails
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION RatingCheckUserAccessW IMPORT "msrating.dll" ALIAS "RatingCheckUserAccessW" ( _
   BYREF pszUsername AS WSTRINGZ _                      ' __in_opt LPCWSTR pszUsername
 , BYREF pszURL AS WSTRINGZ _                           ' __in_opt LPCWSTR pszURL
 , BYREF pszRatingInfo AS WSTRINGZ _                    ' __in_opt LPCWSTR pszRatingInfo
 , BYVAL pData AS BYTE PTR _                            ' __in LPBYTE pData
 , BYVAL cbData AS DWORD _                              ' __in DWORD cbData
 , BYREF ppRatingDetails AS DWORD _                     ' __out_opt void **ppRatingDetails
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION RatingAccessDeniedDialog IMPORT "msrating.dll" ALIAS "RatingAccessDeniedDialog" ( _
   BYVAL hDlg AS DWORD _                                ' __in HWND hDlg
 , BYREF pszUsername AS ASCIIZ _                        ' __in_opt LPCSTR pszUsername
 , BYREF pszContentDescription AS ASCIIZ _              ' __in LPCSTR pszContentDescription
 , BYREF pRatingDetails AS DWORD _                      ' __out void *pRatingDetails
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION RatingAccessDeniedDialogW IMPORT "msrating.dll" ALIAS "RatingAccessDeniedDialogW" ( _
   BYVAL hDlg AS DWORD _                                ' __in HWND hDlg
 , BYREF pszUsername AS WSTRINGZ _                      ' __in_opt LPCWSTR pszUsername
 , BYREF pszContentDescription AS WSTRINGZ _            ' __in LPCWSTR pszContentDescription
 , BYREF pRatingDetails AS DWORD _                      ' __out void *pRatingDetails
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION RatingAccessDeniedDialog2 IMPORT "msrating.dll" ALIAS "RatingAccessDeniedDialog2" ( _
   BYVAL hDlg AS DWORD _                                ' __in HWND hDlg
 , BYREF pszUsername AS ASCIIZ _                        ' __in_opt LPCSTR pszUsername
 , BYREF pRatingDetails AS DWORD _                      ' __out void *pRatingDetails
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION RatingAccessDeniedDialog2W IMPORT "msrating.dll" ALIAS "RatingAccessDeniedDialog2W" ( _
   BYVAL hDlg AS DWORD _                                ' __in HWND hDlg
 , BYREF pszUsername AS WSTRINGZ _                      ' __in_opt LPCWSTR pszUsername
 , BYREF pRatingDetails AS DWORD _                      ' __out void *pRatingDetails
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION RatingFreeDetails IMPORT "msrating.dll" ALIAS "RatingFreeDetails" ( _
   BYVAL pRatingDetails AS DWORD _                      ' __in_opt void *pRatingDetails
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION RatingObtainCancel IMPORT "msrating.dll" ALIAS "RatingObtainCancel" ( _
   BYVAL hRatingObtainQuery AS DWORD _                  ' __in HANDLE hRatingObtainQuery
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION RatingObtainQuery IMPORT "msrating.dll" ALIAS "RatingObtainQuery" ( _
   BYREF pszTargetUrl AS ASCIIZ _                       ' __in LPCSTR pszTargetUrl
 , BYVAL dwUserData AS DWORD _                          ' __in DWORD dwUserData
 , BYVAL fCallback AS DWORD _                           ' __in *fCallback
 , BYREF phRatingObtainQuery AS DWORD _                 ' __out_opt HANDLE *phRatingObtainQuery
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION RatingObtainQueryW IMPORT "msrating.dll" ALIAS "RatingObtainQueryW" ( _
   BYREF pszTargetUrl AS WSTRINGZ _                     ' __in LPCWSTR pszTargetUrl
 , BYVAL dwUserData AS DWORD _                          ' __in DWORD dwUserData
 , BYVAL fCallback AS DWORD _                           ' __in *fCallback
 , BYREF phRatingObtainQuery AS DWORD _                 ' __out_opt HANDLE *phRatingObtainQuery
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION RatingSetupUI IMPORT "msrating.dll" ALIAS "RatingSetupUI" ( _
   BYVAL hDlg AS DWORD _                                ' __in HWND hDlg
 , BYREF pszUsername AS ASCIIZ _                        ' __in LPCSTR pszUsername
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION RatingSetupUIW IMPORT "msrating.dll" ALIAS "RatingSetupUIW" ( _
   BYVAL hDlg AS DWORD _                                ' __in HWND hDlg
 , BYREF pszUsername AS WSTRINGZ _                      ' __in LPCWSTR pszUsername
 ) AS LONG                                              ' HRESULT

'#ifdef _INC_COMMCTRL
'STDAPI RatingAddPropertyPage(PROPSHEETHEADER *ppsh);
'#endif

'STDAPI RatingAddToApprovedSites(HWND hDlg,
'                                DWORD cbPasswordBlob,
'                                __inout_bcount(cbPasswordBlob) BYTE *pbPasswordBlob,
'                                __in LPCWSTR lpszUrl,
'                                BOOL fAlwaysNever,
'                                BOOL fSitePage,
'                                BOOL fApprovedSitesEnforced);

'STDAPI RatingClickedOnPRFInternal(HWND hWndOwner, HINSTANCE /*p_hInstance*/, __in LPSTR lpszFileName, int nShow);
'STDAPI RatingClickedOnRATInternal(HWND hWndOwner, HINSTANCE /*p_hInstance*/, __in LPSTR lpszFileName, int nShow);

DECLARE FUNCTION RatingEnabledQuery IMPORT "msrating.dll" ALIAS "RatingEnabledQuery" ( _
 ) AS LONG                                              ' HRESULT

' Not implemented
'STDAPI RatingInit();
'STDAPI_(void) RatingTerm();

'// A way to check if ratings are installed. We still need to calling
'// ratings dll to find out for sure but this allows us to delay load ratings.
'_inline BOOL IS_RATINGS_ENABLED()
'{
'    TCHAR szSup[200];
'    DWORD dwType;
'    DWORD cbSize = sizeof(szSup);

'    return (SHGetValue(HKEY_LOCAL_MACHINE,
'                       TEXT("Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\Ratings"),
'                       TEXT("Key"),
'                       &dwType, szSup, &cbSize) == ERROR_SUCCESS);
'}

FUNCTION IS_RATINGS_ENABLED_A() AS LONG

   LOCAL szSup AS ASCIIZ * 200
   LOCAL dwType AS DWORD
   LOCAL cbSize AS DWORD
   LOCAL lStatus AS LONG

   cbSize = SIZEOF(szSup)
   lStatus = SHGetValueA(%HKEY_LOCAL_MACHINE, _
                         "Software\Microsoft\Windows\CurrentVersion\Policies\Ratings", _
                         "Key", _
                         dwType, szSup, cbSize)
   IF lStatus = %ERROR_SUCCESS THEN FUNCTION = %TRUE

END FUNCTION

FUNCTION IS_RATINGS_ENABLED_W() AS LONG

   LOCAL szSup AS WSTRINGZ * 200
   LOCAL dwType AS DWORD
   LOCAL cbSize AS DWORD
   LOCAL lStatus AS LONG

   cbSize = SIZEOF(szSup)
   lStatus = SHGetValueW(%HKEY_LOCAL_MACHINE, _
                         "Software\Microsoft\Windows\CurrentVersion\Policies\Ratings"$$, _
                         "Key"$$, _
                         dwType, szSup, cbSize)
   IF lStatus = %ERROR_SUCCESS THEN FUNCTION = %TRUE

END FUNCTION

#IF %DEF(%UNICODE)
   MACRO IS_RATINGS_ENABLED = IS_RATINGS_ENABLED_W
#ELSE
   MACRO IS_RATINGS_ENABLED = IS_RATINGS_ENABLED_A
#ENDIF
