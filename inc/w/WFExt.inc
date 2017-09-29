' ########################################################################################
' Microsoft Windows
' File: WFExt.inc
' Contents: Windows File Manager Extensions definitions (Win32 variant)
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%WFEXT_INC = 1

#INCLUDE ONCE "windows.inc"

%MENU_TEXT_LEN         = 40

%FMMENU_FIRST          = 1
%FMMENU_LAST           = 99

%FMEVENT_LOAD          = 100
%FMEVENT_UNLOAD        = 101
%FMEVENT_INITMENU      = 102
%FMEVENT_USER_REFRESH  = 103
%FMEVENT_SELCHANGE     = 104
%FMEVENT_TOOLBARLOAD   = 105
%FMEVENT_HELPSTRING    = 106
%FMEVENT_HELPMENUITEM  = 107

%FMFOCUS_DIR           = 1
%FMFOCUS_TREE          = 2
%FMFOCUS_DRIVES        = 3
%FMFOCUS_SEARCH        = 4

%FM_GETFOCUS           = %WM_USER + &H0200
%FM_GETSELCOUNT        = %WM_USER + &H0202
%FM_GETSELCOUNTLFN     = %WM_USER + &H0203   ' LFN versions are odd
%FM_REFRESH_WINDOWS    = %WM_USER + &H0206
%FM_RELOAD_EXTENSIONS  = %WM_USER + &H0207

%FM_GETDRIVEINFO       = %WM_USER + &H0201
%FM_GETFILESEL         = %WM_USER + &H0204
%FM_GETFILESELLFN      = %WM_USER + &H0205   ' LFN versions are odd

%FM_GETDRIVEINFOW      = %WM_USER + &H0211
%FM_GETFILESELW        = %WM_USER + &H0214
%FM_GETFILESELLFNW     = %WM_USER + &H0215   ' LFN versions are odd

' // Size = 276 bytes
TYPE FMS_GETFILESELA DWORD
   ftTime AS FILETIME         ' FILETIME ftTime
   dwSize AS DWORD            ' DWORD dwSize
   bAttr  AS BYTE             ' BYTE bAttr
   szName AS ASCIIZ * 260     ' CHAR szName[260]  // always fully qualified
END TYPE

' // Size = 536 bytes
TYPE FMS_GETFILESELW DWORD
   ftTime AS FILETIME         ' FILETIME ftTime
   dwSize AS DWORD            ' DWORD dwSize
   bAttr  AS BYTE             ' BYTE bAttr
   szName AS WSTRINGZ * 260   ' WCHAR szName[260]  // always fully qualified
END TYPE

#IF %DEF(%UNICODE)
   MACRO FMS_GETFILESEL = FMS_GETFILESELW
#ELSE
   MACRO FMS_GETFILESEL = FMS_GETFILESELA
#ENDIF

' // Size = 412 bytes
TYPE FMS_GETDRIVEINFOA DWORD        ' // for drive
   dwTotalSpace AS DWORD            ' DWORD dwTotalSpace
   dwFreeSpace  AS DWORD            ' DWORD dwFreeSpace
   szPath       AS ASCIIZ * 260     ' CHAR  szPath[260]   // current directory
   szVolume     AS ASCIIZ * 14      ' CHAR  szVolume[14]  // volume label
   szShare      AS ASCIIZ * 128     ' CHAR  szShare[128]  // if this is a net drive
END TYPE

' // Size = 812 bytes
TYPE FMS_GETDRIVEINFOW DWORD        ' // for drive
   dwTotalSpace AS DWORD            ' DWORD dwTotalSpace
   dwFreeSpace  AS DWORD            ' DWORD dwFreeSpace
   szPath       AS WSTRINGZ * 260   ' WCHAR szPath[260]   // current directory
   szVolume     AS WSTRINGZ * 14    ' WCHAR szVolume[14]  // volume label
   szShare      AS WSTRINGZ * 128   ' WCHAR szShare[128]  // if this is a net drive
END TYPE

#IF %DEF(%UNICODE)
   MACRO FMS_GETDRIVEINFO = FMS_GETDRIVEINFOW
#ELSE
   MACRO FMS_GETDRIVEINFO = FMS_GETDRIVEINFOA
#ENDIF

' // Size = 52 bytes
TYPE FMS_LOADA DWORD
   dwSize     AS DWORD                        ' DWORD dwSize                    // for version checks
   szMenuName AS ASCIIZ * %MENU_TEXT_LEN      ' CHAR  szMenuName[MENU_TEXT_LEN] // output
   hMenu      AS DWORD                        ' HMENU hMenu                     // output
   wMenuDelta AS DWORD                        ' UINT  wMenuDelta                // input
END TYPE

' // Size = 92 bytes
TYPE FMS_LOADW DWORD
   dwSize     AS DWORD                       ' DWORD dwSize                    // for version checks
   szMenuName AS WSTRINGZ * %MENU_TEXT_LEN   ' WCHAR szMenuName[MENU_TEXT_LEN] // output
   hMenu      AS DWORD                       ' HMENU hMenu                     // output
   wMenuDelta AS DWORD                       ' UINT  wMenuDelta                // input
END TYPE

#IF %DEF(%UNICODE)
   MACRO FMS_LOAD = FMS_LOADW
#ELSE
   MACRO FMS_LOAD = FMS_LOADA
#ENDIF

'// Toolbar definitions

' // Size = 6 bytes
TYPE EXT_BUTTON WORD
   idCommand AS WORD   ' WORD idCommand /* menu command to trigger */
   idsHelp   AS WORD   ' WORD idsHelp   /* help string ID */
   fsStyle   AS WORD   ' WORD fsStyle   /* button style */
END TYPE

' // Size = 20 bytes
TYPE FMS_TOOLBARLOAD DWORD FILL
   dwSize    AS DWORD            ' DWORD dwSize           /* for version checks */
   lpButtons AS EXT_BUTTON PTR   ' LPEXT_BUTTON lpButtons /* output */
   cButtons  AS WORD             ' WORD cButtons          /* output, 0==>no buttons */
   cBitmaps  AS WORD             ' WORD cBitmaps          /* number of non-sep buttons */
   idBitmap  AS WORD             ' WORD idBitmap          /* output */
   hBitmap   AS DWORD            ' HBITMAP hBitmap        /* output if idBitmap==0 */
END TYPE

' // Size = 136 bytes
TYPE FMS_HELPSTRINGA DWORD
   idCommand AS LONG             ' INT   idCommand   /* input, -1==>the menu was selected */
   hMenu     AS DWORD            ' HMENU hMenu       /* input, the extensions menu */
   szHelp    AS ASCIIZ * 128     ' CHAR  szHelp[128] /* output, the help string */
END TYPE

' // Size = 264 bytes
TYPE FMS_HELPSTRINGW DWORD
   idCommand AS LONG             ' INT   idCommand   /* input, -1==>the menu was selected */
   hMenu     AS DWORD            ' HMENU hMenu       /* input, the extensions menu */
   szHelp    AS WSTRINGZ * 128   ' WCHAR szHelp[128] /* output, the help string */
END TYPE

#IF %DEF(%UNICODE)
   MACRO FMS_HELPSTRING = FMS_HELPSTRINGW
#ELSE
   MACRO FMS_HELPSTRING = FMS_HELPSTRINGA
#ENDIF

'typedef DWORD (APIENTRY *FM_EXT_PROC)(HWND, WORD, LONG);
'FUNCTION FM_EXT_PROC (BYVAL DWORD, BYVAL WORD, BYVAL LONG) AS DWORD
'typedef DWORD (APIENTRY *FM_UNDELETE_PROC)(HWND, LPTSTR);
'FUNCTION FM_UNDELETE_PROC (BYVAK DWORD, BYREF ASCIIZ) AS DWORD

