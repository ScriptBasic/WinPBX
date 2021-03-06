' ########################################################################################
' Microsoft Windows
' File: Ime.inc
' Contents: Procedure declarations, constant definitions and macros for the IME component
' Copyright (c) 2011 Jos� Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%IME_INC = 1

'#ifndef _WINDEF_
'typedef unsigned int UINT;
'#endif // _WINDEF_

%IME_MAXPROCESS = 32

DECLARE FUNCTION SendIMEMessageEx IMPORT "IMM32.DLL" ALIAS "SendIMEMessageExA" ( _
   BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 , BYVAL lParam AS LONG _                               ' __in LPARAM lParam
 ) AS LONG                                              ' LRESULT

DECLARE FUNCTION SendIMEMessageExW IMPORT "IMM32.DLL" ALIAS "SendIMEMessageExW" ( _
   BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 , BYVAL lParam AS LONG _                               ' __in LPARAM lParam
 ) AS LONG                                              ' LRESULT

'//
'// IMESTRUCT structure for SendIMEMessageEx
'//

' // Size = 32 bytes
TYPE IMESTRUCT DWORD
   fnc       AS DWORD  ' UINT     fnc        // function code
   wParam    AS LONG   ' WPARAM   wParam     // word parameter
   wCount    AS DWORD  ' UINT     wCount     // word counter
   dchSource AS DWORD  ' UINT     dchSource  // offset to Source from top of memory object
   dchDest   AS DWORD  ' UINT     dchDest    // offset to Desrination from top of memory object
   lParam1   AS LONG   ' LPARAM   lParam1
   lParam2   AS LONG   ' LPARAM   lParam2
   lParam3   AS LONG   ' LPARAM   lParam3
END TYPE

%CP_HWND   = 0
%CP_OPEN   = 1
%CP_DIRECT = 2
%CP_LEVEL  = 3


'//
'//      Virtual Keys
'//

#IF NOT %DEF(%VK_DBE_ALPHANUMERIC)
%VK_DBE_ALPHANUMERIC           = &H0f0
%VK_DBE_KATAKANA               = &H0f1
%VK_DBE_HIRAGANA               = &H0f2
%VK_DBE_SBCSCHAR               = &H0f3
%VK_DBE_DBCSCHAR               = &H0f4
%VK_DBE_ROMAN                  = &H0f5
%VK_DBE_NOROMAN                = &H0f6
%VK_DBE_ENTERWORDREGISTERMODE  = &H0f7
%VK_DBE_ENTERIMECONFIGMODE     = &H0f8
%VK_DBE_FLUSHSTRING            = &H0f9
%VK_DBE_CODEINPUT              = &H0fa
%VK_DBE_NOCODEINPUT            = &H0fb
%VK_DBE_DETERMINESTRING        = &H0fc
%VK_DBE_ENTERDLGCONVERSIONMODE = &H0fd
#ENDIF

'//
'//     switch for wParam of IME_SETCONVERSIONWINDOW
'//
%MCW_DEFAULT  = &H00
%MCW_RECT     = &H01
%MCW_WINDOW   = &H02
%MCW_SCREEN   = &H04
%MCW_VERTICAL = &H08
%MCW_HIDDEN   = &H10

'//
'//    switch for wParam of IME_SETCONVERSIONMODE
'//       and IME_GETCONVERSIONMODE
'//
%IME_MODE_ALPHANUMERIC   = &H0001

#IF %DEF(%KOREA)    ' BeomOh - 9/29/92
    %IME_MODE_SBCSCHAR   = &H0002
#ELSE
    %IME_MODE_SBCSCHAR   = &H0008
#ENDIF

%IME_MODE_KATAKANA       = &H0002
%IME_MODE_HIRAGANA       = &H0004
%IME_MODE_HANJACONVERT   = &H0004
%IME_MODE_DBCSCHAR       = &H0010
%IME_MODE_ROMAN          = &H0020
%IME_MODE_NOROMAN        = &H0040
%IME_MODE_CODEINPUT      = &H0080
%IME_MODE_NOCODEINPUT    = &H0100

'//
'//     IME APIs
'//
%IME_GETIMECAPS            = &H03
%IME_SETOPEN               = &H04
%IME_GETOPEN               = &H05
%IME_GETVERSION            = &H07
%IME_SETCONVERSIONWINDOW   = &H08
%IME_MOVEIMEWINDOW         = %IME_SETCONVERSIONWINDOW       ' KOREA only
%IME_SETCONVERSIONMODE     = &H10

%IME_GETCONVERSIONMODE     = &H11
%IME_SET_MODE              = &H12          ' KOREA only
%IME_SENDVKEY              = &H13
%IME_ENTERWORDREGISTERMODE = &H18
%IME_SETCONVERSIONFONTEX   = &H19

'//
'// IME_CODECONVERT subfunctions
'//
%IME_BANJAtoJUNJA = &H13     ' KOREA only
%IME_JUNJAtoBANJA = &H14     ' KOREA only
%IME_JOHABtoKS    = &H15     ' KOREA only
%IME_KStoJOHAB    = &H16     ' KOREA only

'//
'// IME_AUTOMATA subfunctions
'//
%IMEA_INIT = &H01            ' KOREA only
%IMEA_NEXT = &H02            ' KOREA only
%IMEA_PREV = &H03            ' KOREA only

'//
'// IME_HANJAMODE subfunctions
'//
%IME_REQUEST_CONVERT = &H01  ' KOREA only
%IME_ENABLE_CONVERT  = &H02  ' KOREA only

'//
'// IME_MOVEIMEWINDOW subfunctions
'//
%INTERIM_WINDOW = &H00       ' KOREA only
%MODE_WINDOW    = &H01       ' KOREA only
%HANJA_WINDOW   = &H02       ' KOREA only

'//
'//    error code
'//
%IME_RS_ERROR       = &H01   ' genetal error
%IME_RS_NOIME       = &H02   ' IME is not installed
%IME_RS_TOOLONG     = &H05   ' given string is too long
%IME_RS_ILLEGAL     = &H06   ' illegal charactor(s) is string
%IME_RS_NOTFOUND    = &H07   ' no (more) candidate
%IME_RS_NOROOM      = &H0a   ' no disk/memory space
%IME_RS_DISKERROR   = &H0e   ' disk I/O error
%IME_RS_INVALID     = &H11   ' Win3.1/NT
%IME_RS_NEST        = &H12   ' called nested
%IME_RS_SYSTEMMODAL = &H13   ' called when system mode

'//
'//   report messge from IME to WinApps
'//
%WM_IME_REPORT       = &H0280

'//
'//   report message parameter for WM_IME_REPORT
'//
%IR_STRINGSTART   = &H100
%IR_STRINGEND     = &H101
%IR_OPENCONVERT   = &H120
%IR_CHANGECONVERT = &H121
%IR_CLOSECONVERT  = &H122
%IR_FULLCONVERT   = &H123
%IR_IMESELECT     = &H130
%IR_STRING        = &H140
%IR_DBCSCHAR      = &H160
%IR_UNDETERMINE   = &H170
%IR_STRINGEX      = &H180   ' New for 3.1
%IR_MODEINFO      = &H190

'//#define WM_CONVERTREQUESTEX     0x0109
%WM_WNT_CONVERTREQUESTEX = &H0109  ' %WM_CONVERTREQUESTEX: 109 for NT, 108 for OT
%WM_CONVERTREQUEST       = &H010A
%WM_CONVERTRESULT        = &H010B
%WM_INTERIM              = &H010C

%WM_IMEKEYDOWN           = &H290
%WM_IMEKEYUP             = &H291

'//
'// UNDETERMINESTRING structure for IR_UNDETERMINE
'//

' // Size = 56 bytes
TYPE UNDETERMINESTRUCT DWORD
   dwSize             AS DWORD   ' DWORD    dwSize
   uDefIMESize        AS DWORD   ' UINT     uDefIMESize
   uDefIMEPos         AS DWORD   ' UINT     uDefIMEPos
   uUndetTextLen      AS DWORD   ' UINT     uUndetTextLen
   uUndetTextPos      AS DWORD   ' UINT     uUndetTextPos
   uUndetAttrPos      AS DWORD   ' UINT     uUndetAttrPos
   uCursorPos         AS DWORD   ' UINT     uCursorPos
   uDeltaStart        AS DWORD   ' UINT     uDeltaStart
   uDetermineTextLen  AS DWORD   ' UINT     uDetermineTextLen
   uDetermineTextPos  AS DWORD   ' UINT     uDetermineTextPos
   uDetermineDelimPos AS DWORD   ' UINT     uDetermineDelimPos
   uYomiTextLen       AS DWORD   ' UINT     uYomiTextLen
   uYomiTextPos       AS DWORD   ' UINT     uYomiTextPos
   uYomiDelimPos      AS DWORD   ' UINT     uYomiDelimPos
END TYPE

' // Size = 20 bytes
TYPE STRINGEXSTRUCT DWORD
   dwSize             AS DWORD   ' DWORD    dwSize
   uDeterminePos      AS DWORD   ' UINT     uDeterminePos
   uDetermineDelimPos AS DWORD   ' UINT     uDetermineDelimPos
   uYomiPos           AS DWORD   ' UINT     uYomiPos
   uYomiDelimPos      AS DWORD   ' UINT     uYomiDelimPos
END TYPE
