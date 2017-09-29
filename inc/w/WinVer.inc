' ########################################################################################
' Microsoft Windows
' File: WinVer.inc
' Contents: Include file for VER.DLL.  This library is designed to allow version stamping
' of Windows executable files* and of special .VER files for DOS executable files.
' Copyright (c) 2010 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%WINVER_INC = 1

#INCLUDE ONCE "VerRsrc.inc"
#INCLUDE ONCE "windows.inc"

'/* ----- Function prototypes ----- */

DECLARE FUNCTION VerFindFileA IMPORT "VERSION.DLL" ALIAS "VerFindFileA" ( _
   BYVAL uFlags AS DWORD _                              ' __in DWORD uFlags
 , BYREF szFileName AS ASCIIZ _                         ' __in LPSTR szFileName
 , BYREF szWinDir AS ASCIIZ _                           ' __in LPSTR szWinDir
 , BYREF szAppDir AS ASCIIZ _                           ' __in LPSTR szAppDir
 , BYREF szCurDir AS ASCIIZ _                           ' __out LPSTR szCurDir
 , BYREF lpuCurDirLen AS DWORD _                        ' __inout PUINT lpuCurDirLen
 , BYREF szDestDir AS ASCIIZ _                          ' __out LPSTR szDestDir
 , BYREF lpuDestDirLen AS DWORD _                       ' __inout PUINT lpuDestDirLen
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION VerFindFileW IMPORT "VERSION.DLL" ALIAS "VerFindFileW" ( _
   BYVAL uFlags AS DWORD _                              ' __in DWORD uFlags
 , BYREF szFileName AS WSTRINGZ _                       ' __in LPWSTR szFileName
 , BYREF szWinDir AS WSTRINGZ _                         ' __in LPWSTR szWinDir
 , BYREF szAppDir AS WSTRINGZ _                         ' __in LPWSTR szAppDir
 , BYREF szCurDir AS WSTRINGZ _                         ' __out LPWSTR szCurDir
 , BYREF lpuCurDirLen AS DWORD _                        ' __inout PUINT lpuCurDirLen
 , BYREF szDestDir AS WSTRINGZ _                        ' __out LPWSTR szDestDir
 , BYREF lpuDestDirLen AS DWORD _                       ' __inout PUINT lpuDestDirLen
 ) AS DWORD                                             ' DWORD

#IF %DEF(%UNICODE)
   MACRO VerFindFile = VerFindFileW
#ELSE
   MACRO VerFindFile = VerFindFileA
#ENDIF

DECLARE FUNCTION VerInstallFileA IMPORT "VERSION.DLL" ALIAS "VerInstallFileA" ( _
   BYVAL uFlags AS DWORD _                              ' __in DWORD uFlags
 , BYREF szSrcFileName AS ASCIIZ _                      ' __in LPSTR szSrcFileName
 , BYREF szDestFileName AS ASCIIZ _                     ' __in LPSTR szDestFileName
 , BYREF szSrcDir AS ASCIIZ _                           ' __in LPSTR szSrcDir
 , BYREF szDestDir AS ASCIIZ _                          ' __in LPSTR szDestDir
 , BYREF szCurDir AS ASCIIZ _                           ' __in LPSTR szCurDir
 , BYREF szTmpFile AS ASCIIZ _                          ' __out LPSTR szTmpFile
 , BYREF lpuTmpFileLen AS DWORD _                       ' __inout PUINT lpuTmpFileLen
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION VerInstallFileW IMPORT "VERSION.DLL" ALIAS "VerInstallFileW" ( _
   BYVAL uFlags AS DWORD _                              ' __in DWORD uFlags
 , BYREF szSrcFileName AS WSTRINGZ _                    ' __in LPWSTR szSrcFileName
 , BYREF szDestFileName AS WSTRINGZ _                   ' __in LPWSTR szDestFileName
 , BYREF szSrcDir AS WSTRINGZ _                         ' __in LPWSTR szSrcDir
 , BYREF szDestDir AS WSTRINGZ _                        ' __in LPWSTR szDestDir
 , BYREF szCurDir AS WSTRINGZ _                         ' __in LPWSTR szCurDir
 , BYREF szTmpFile AS WSTRINGZ _                        ' __out LPWSTR szTmpFile
 , BYREF lpuTmpFileLen AS DWORD _                       ' __inout PUINT lpuTmpFileLen
 ) AS DWORD                                             ' DWORD

#IF %DEF(%UNICODE)
   MACRO VerInstallFile = VerInstallFileW
#ELSE
   MACRO VerInstallFile = VerInstallFileA
#ENDIF

'/* Returns size of version info in bytes */
DECLARE FUNCTION GetFileVersionInfoSizeA IMPORT "VERSION.DLL" ALIAS "GetFileVersionInfoSizeA" ( _
   BYREF lptstrFilename AS ASCIIZ _                     ' __in LPCSTR lptstrFilename
 , OPTIONAL BYREF lpdwHandle AS DWORD _                 ' __out_opt LPDWORD lpdwHandle
 ) AS DWORD                                             ' DWORD

'/* Returns size of version info in bytes */
DECLARE FUNCTION GetFileVersionInfoSizeW IMPORT "VERSION.DLL" ALIAS "GetFileVersionInfoSizeW" ( _
   BYREF lptstrFilename AS WSTRINGZ _                   ' __in LPCWSTR lptstrFilename
 , OPTIONAL BYREF lpdwHandle AS DWORD _                 ' __out_opt LPDWORD lpdwHandle
 ) AS DWORD                                             ' DWORD

#IF %DEF(%UNICODE)
   MACRO GetFileVersionInfoSize = GetFileVersionInfoSizeW
#ELSE
   MACRO GetFileVersionInfoSize = GetFileVersionInfoSizeA
#ENDIF

DECLARE FUNCTION GetFileVersionInfoA IMPORT "VERSION.DLL"  ALIAS "GetFileVersionInfoA" ( _
   BYREF lptstrFilename AS ASCIIZ _                     ' __in LPCSTR lptstrFilename
 , BYVAL dwHandle AS DWORD _                            ' __in DWORD dwHandle
 , BYVAL dwLen AS DWORD _                               ' __in DWORD dwLen
 , BYREF lpData AS ANY _                                ' __out_bcount(dwLen) LPVOID lpData
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetFileVersionInfoW IMPORT "VERSION.DLL"  ALIAS "GetFileVersionInfoW" ( _
   BYREF lptstrFilename AS WSTRINGZ _                   ' __in LPCWSTR lptstrFilename
 , BYVAL dwHandle AS DWORD _                            ' __in DWORD dwHandle
 , BYVAL dwLen AS DWORD _                               ' __in DWORD dwLen
 , BYREF lpData AS ANY _                                ' __out_bcount(dwLen) LPVOID lpData
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO GetFileVersionInfo = GetFileVersionInfoW
#ELSE
   MACRO GetFileVersionInfo = GetFileVersionInfoA
#ENDIF

DECLARE FUNCTION GetFileVersionInfoSizeExA IMPORT "VERSION.DLL" ALIAS "GetFileVersionInfoSizeExA" ( _
   BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYREF lptstrFilename AS ASCIIZ _                     ' __in LPCSTR lptstrFilename
 , OPTIONAL BYREF lpdwHandle AS DWORD _                 ' __out_opt LPDWORD lpdwHandle
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION GetFileVersionInfoSizeExW IMPORT "VERSION.DLL" ALIAS "GetFileVersionInfoSizeExW" ( _
   BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYREF lptstrFilename AS WSTRINGZ _                   ' __in LPCWSTR lptstrFilename
 , OPTIONAL BYREF lpdwHandle AS DWORD _                 ' __out_opt LPDWORD lpdwHandle
 ) AS DWORD                                             ' DWORD

#IF %DEF(%UNICODE)
   MACRO GetFileVersionInfoSizeEx = GetFileVersionInfoSizeExW
#ELSE
   MACRO GetFileVersionInfoSizeEx = GetFileVersionInfoSizeExA
#ENDIF

DECLARE FUNCTION VerLanguageNameA IMPORT "KERNEL32.DLL" ALIAS "VerLanguageNameA" ( _
   BYVAL wLang AS DWORD _                               ' __in DWORD wLang
 , BYREF szLang AS ASCIIZ _                             ' __out LPSTR szLang
 , BYVAL nSize AS DWORD _                               ' __in DWORD nSize
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION VerLanguageNameW IMPORT "KERNEL32.DLL" ALIAS "VerLanguageNameW" ( _
   BYVAL wLang AS DWORD _                               ' __in DWORD wLang
 , BYREF szLang AS WSTRINGZ _                           ' __out LPWSTR szLang
 , BYVAL nSize AS DWORD _                               ' __in DWORD nSize
 ) AS DWORD                                             ' DWORD

#IF %DEF(%UNICODE)
   MACRO VerLanguageName = VerLanguageNameW
#ELSE
   MACRO VerLanguageName = VerLanguageNameA
#ENDIF

DECLARE FUNCTION VerQueryValueA IMPORT "VERSION.DLL" ALIAS "VerQueryValueA" ( _
   BYVAL pBlock AS DWORD _                              ' __in const LPVOID pBlock
 , BYREF lpSubBlock AS ASCIIZ _                         ' __in LPSTR lpSubBlock
 , BYREF lplpBuffer AS ANY _                            ' __out LPVOID * lplpBuffer
 , BYREF puLen AS DWORD _                               ' __out PUINT puLen
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION VerQueryValueW IMPORT "VERSION.DLL" ALIAS "VerQueryValueW" ( _
   BYVAL pBlock AS DWORD _                              ' __in const LPVOID pBlock
 , BYREF lpSubBlock AS WSTRINGZ _                       ' __in LPWSTR lpSubBlock
 , BYREF lplpBuffer AS ANY _                            ' __out LPVOID * lplpBuffer
 , BYREF puLen AS DWORD _                               ' __out PUINT puLen
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO VerQueryValue = VerQueryValueW
#ELSE
   MACRO VerQueryValue = VerQueryValueA
#ENDIF
