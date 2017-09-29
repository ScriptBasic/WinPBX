' ########################################################################################
' Microsoft Windows
' File: Errors.inc
' Contents: ActiveMovie error defines.
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%ERRORS_INC = 1

'// codes 0-01ff are reserved for OLE
%VFW_FIRST_CODE     = &H200
%MAX_ERROR_TEXT_LEN = 160

#INCLUDE ONCE "VFWMSGS.INC"                   ' // includes all message definitions

'typedef BOOL (WINAPI* AMGETERRORTEXTPROCA)(HRESULT, char *, DWORD);
'typedef BOOL (WINAPI* AMGETERRORTEXTPROCW)(HRESULT, WCHAR *, DWORD);

'FUNCTION AMGETERRORTEXTPROCA ( _
'   BYVAL hr AS LONG _                                   ' [in] HRESULT hr
' , BYREF pBuffer AS ASCIIZ _                            ' [in] CHAR* pBuffer
' , BYVAL MaxLen AS DWORD _                              ' [in] DWORD MaxLen
'   ) AS LONG

'FUNCTION AMGETERRORTEXTPROCW ( _
'   BYVAL hr AS LONG _                                   ' [in] HRESULT hr
' , BYVAL pBuffer AS DWORD _                             ' [in] CHAR* pBuffer
' , BYVAL MaxLen AS DWORD _                              ' [in] DWORD MaxLen
'   ) AS LONG

'AMOVIEAPI DWORD WINAPI AMGetErrorTextA( HRESULT hr , char *pbuffer , DWORD MaxLen);
'AMOVIEAPI DWORD WINAPI AMGetErrorTextW( HRESULT hr , WCHAR *pbuffer , DWORD MaxLen);

DECLARE FUNCTION AMGetErrorTextA IMPORT "QUARTZ.DLL" ALIAS "AMGetErrorTextA" ( _
   BYVAL hr AS LONG _                                   ' __in HRESULT hr
 , BYREF pBuffer AS ASCIIZ _                            ' __in CHAR* pBuffer
 , BYVAL MaxLen AS DWORD _                              ' __in DWORD MaxLen
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION AMGetErrorTextW IMPORT "QUARTZ.DLL" ALIAS "AMGetErrorTextW" ( _
   BYVAL hr AS LONG _                                   ' __in HRESULT hr
 , BYREF pBuffer AS WSTRINGZ _                          ' __in WCHAR* pBuffer
 , BYVAL MaxLen AS DWORD _                              ' __in DWORD MaxLen
 ) AS DWORD                                             ' DWORD

#IF %DEF(%UNICODE)
   MACRO AMGetErrorText = AMGetErrorTextW
#ELSE
   MACRO AMGetErrorText = AMGetErrorTextA
#ENDIF
