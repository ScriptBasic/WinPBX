' ########################################################################################
' Microsoft Windows
' File: WinNls32.inc
' Contents: Procedure declarations, constant definitions and macros for the Windows NT 3.x
' compatible FarEast IMM component.
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%WINNLS32_INC = 1

#INCLUDE ONCE "windows.inc"

' // Size = 12 bytes
TYPE DATETIME WORD
   year  AS WORD
   month AS WORD
   day   AS WORD
   hour  AS WORD
   min   AS WORD
   sec   AS WORD
END TYPE

' // Size = 180 bytes
TYPE IMEPROA BYTE
   hWnd          AS DWORD            ' HWND
   InstDate      AS DATETIME         ' DATETIME
   wVersion      AS DWORD            ' UINT
   szDescription AS STRING * 50      ' BYTE
   szName        AS STRING * 80      ' BYTE
   szOptions     AS STRING * 30      ' BYTE
END TYPE

' // Size = 340 bytes
TYPE IMEPROW BYTE
   hWnd          AS DWORD          ' HWND
   InstDate      AS DATETIME       ' DATETIME
   wVersion      AS DWORD          ' UINT
   szDescription AS WSTRINGZ * 50  ' WCHAR
   szName        AS WSTRINGZ * 80  ' WCHAR
   szOptions     AS WSTRINGZ * 30  ' WCHAR
END TYPE

#IF %DEF(%UNICODE)
   MACRO IMEPRO = IMEPROW
#ELSE
   MACRO IMEPRO = IMEPROA
#ENDIF

DECLARE FUNCTION IMPGetIMEA IMPORT "USER32.DLL" ALIAS "IMPGetIMEA" ( _
   BYVAL hwnd AS DWORD _                                ' __in HWND hwnd
 , BYREF lpimepro AS IMEPROA _                          ' __out LPIMEPROA lpimepro
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION IMPGetIMEW IMPORT "USER32.DLL" ALIAS "IMPGetIMEW" ( _
   BYVAL hwnd AS DWORD _                                ' __in HWND hwnd
 , BYREF lpimepro AS IMEPROW _                          ' __out LPIMEPROW lpimepro
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO IMPGetIME = IMPGetIMEW
#ELSE
   MACRO IMPGetIME = IMPGetIMEA
#ENDIF

DECLARE FUNCTION IMPQueryIMEA IMPORT "USER32.DLL" ALIAS "IMPQueryIMEA" ( _
   BYREF lpimepro AS IMEPROA _                          ' __in_out LPIMEPROA lpimepro
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION IMPQueryIMEW IMPORT "USER32.DLL" ALIAS "IMPQueryIMEW" ( _
   BYREF lpimepro AS IMEPROW _                          ' __in_out LPIMEPROW lpimepro
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO IMPQueryIME = IMPQueryIMEW
#ELSE
   MACRO IMPQueryIME = IMPQueryIMEA
#ENDIF

DECLARE FUNCTION IMPSetIMEA IMPORT "USER32.DLL" ALIAS "IMPSetIMEA" ( _
   BYVAL hwnd AS DWORD _                                ' __in HWND hwnd
 , BYREF lpimepro AS IMEPROA _                          ' __in LPIMEPROA lpimepro
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION IMPSetIMEW IMPORT "USER32.DLL" ALIAS "IMPSetIMEW" ( _
   BYVAL hwnd AS DWORD _                                ' __in HWND hwnd
 , BYREF lpimepro AS IMEPROW _                          ' __in LPIMEPROW lpimepro
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO IMPSetIME = IMPSetIMEW
#ELSE
   MACRO IMPSetIME = IMPSetIMEA
#ENDIF

DECLARE FUNCTION WINNLSGetIMEHotkey IMPORT "USER32.DLL" ALIAS "WINNLSGetIMEHotkey" ( _
   BYVAL hwnd AS DWORD _                                ' __in HWND hwnd
 ) AS DWORD                                             ' UINT

DECLARE FUNCTION WINNLSEnableIME IMPORT "USER32.DLL" ALIAS "WINNLSEnableIME" ( _
   BYVAL hwnd AS DWORD _                                ' __in HWND hwnd
 , BYVAL bFlag AS LONG _                                ' __in BOOL bFlag
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION WINNLSGetEnableStatus IMPORT "USER32.DLL" ALIAS "WINNLSGetEnableStatus" ( _
   BYVAL hwnd AS DWORD _                                ' __in HWND hwnd
 ) AS LONG                                              ' BOOL
