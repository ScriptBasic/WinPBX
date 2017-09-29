' ########################################################################################
' Microsoft Windows
' File: Sfc.inc
' Contents: Header file for public SFC interfaces.
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%SFC_INC = 1

#INCLUDE ONCE "windows.inc"

%SFC_DISABLE_NORMAL         = 0
%SFC_DISABLE_ASK            = 1
%SFC_DISABLE_ONCE           = 2
%SFC_DISABLE_SETUP          = 3
%SFC_DISABLE_NOPOPUPS       = 4

%SFC_SCAN_NORMAL            = 0
%SFC_SCAN_ALWAYS            = 1
%SFC_SCAN_ONCE              = 2
%SFC_SCAN_IMMEDIATE         = 3

%SFC_QUOTA_DEFAULT          = 50
%SFC_QUOTA_ALL_FILES        = &HFFFFFFFF???   ' ((ULONG)-1)

$$SFC_IDLE_TRIGGER       = "WFP_IDLE_TRIGGER"$$

' // Size = 524 bytes
TYPE PROTECTED_FILE_DATA BYTE
   FileName   AS WSTRINGZ * %MAX_PATH   ' WCHAR
   FileNumber AS DWORD                  ' DWORD
END TYPE

DECLARE FUNCTION SfcGetNextProtectedFile IMPORT "SFC.DLL" ALIAS "SfcGetNextProtectedFile" ( _
   BYVAL RpcHandle AS DWORD _                           ' __in HANDLE RpcHandle // must be NULL
 , BYREF PROTECTED_FILE_DATA _                          ' __in PPROTECTED_FILE_DATA ProtFileData
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SfcIsFileProtected IMPORT "SFC.DLL" ALIAS "SfcIsFileProtected" ( _
   BYVAL RpcHandle AS DWORD _                           ' __in HANDLE RpcHandle // must be NULL
 , BYREF ProtFileName AS WSTRINGZ _                     ' __in LPCWSTR ProtFileName
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SfcIsKeyProtected IMPORT "SFC.DLL" ALIAS "SfcIsKeyProtected" ( _
   BYVAL KeyHandle AS DWORD _                           ' __in HKEY KeyHandle
 , BYREF SubKeyName AS WSTRINGZ _                       ' __in LPCWSTR SubKeyName OPTIONAL
 , BYVAL KeySam AS REGSAM _                             ' __in REGSAM KeySam
 ) AS LONG                                              ' BOOL

'//
'// new APIs which are not currently supported, but are stubbed out
'//
'BOOL
'WINAPI
'SfpVerifyFile(
'    __in LPCSTR pszFileName,
'    __in_ecount(dwErrSize) LPSTR  pszError,
'    __in DWORD   dwErrSize
'    );
