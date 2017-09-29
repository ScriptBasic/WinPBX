' ########################################################################################
' Microsoft Windows
' File: LoadPerf.inc
' Contents: Header file for the Performance Monitor counter string installation and
' removal functions.
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%LOADPERF_INC = 1

#INCLUDE ONCE "windows.inc"

'// function prototypes for perf counter name string load & unload functions
'// provided in LOADPERF.DLL

'#ifdef __LOADPERF__
'#define LOADPERF_FUNCTION   DWORD __stdcall
'#else
'#define LOADPERF_FUNCTION   __declspec(dllimport) DWORD __stdcall
'#endif

'// flags for dwFlags Argument
%LOADPERF_FLAGS_DELETE_MOF_ON_EXIT  = 1???   ' ((ULONG_PTR) 1)
%LOADPERF_FLAGS_LOAD_REGISTRY_ONLY  = 2???   ' ((ULONG_PTR) 2)
%LOADPERF_FLAGS_CREATE_MOF_ONLY     = 4???   ' ((ULONG_PTR) 4)
%LOADPERF_FLAGS_DISPLAY_USER_MSGS   = 8???   ' ((ULONG_PTR) 8)

DECLARE FUNCTION InstallPerfDllW IMPORT "LOADPERF.DLL" ALIAS "InstallPerfDllW" ( _
   BYREF szComputerName AS WSTRINGZ _                   ' __in  LPCWSTR   szComputerName
 , BYREF lpIniFile AS WSTRINGZ _                        ' __in  LPCWSTR   lpIniFile
 , BYVAL dwFlags AS DWORD _                             ' __in  ULONG_PTR dwFlags
 ) AS DWORD                                             ' LOADPERF_FUNCTION

DECLARE FUNCTION InstallPerfDllA IMPORT "LOADPERF.DLL" ALIAS "InstallPerfDllA" ( _
   BYREF szComputerName AS ASCIIZ _                     ' __in  LPCSTR    szComputerName
 , BYREF lpIniFile AS ASCIIZ _                          ' __in  LPCSTR    lpIniFile
 , BYVAL dwFlags AS DWORD _                             ' __in  ULONG_PTR dwFlags
 ) AS DWORD                                             ' LOADPERF_FUNCTION

#IF %DEF(%UNICODE)
   MACRO InstallPerfDll = InstallPerfDllW
#ELSE
   MACRO InstallPerfDll = InstallPerfDllA
#ENDIF

DECLARE FUNCTION LoadPerfCounterTextStringsA IMPORT "LOADPERF.DLL" ALIAS "LoadPerfCounterTextStringsA" ( _
   BYREF lpCommandLine AS ASCIIZ _                      ' __in LPSTR lpCommandLine
 , BYVAL bQuietModeArg AS LONG _                        ' __in BOOL  bQuietModeArg
 ) AS DWORD                                             ' LOADPERF_FUNCTION

DECLARE FUNCTION LoadPerfCounterTextStringsW IMPORT "LOADPERF.DLL" ALIAS "LoadPerfCounterTextStringsW" ( _
   BYREF lpCommandLine AS WSTRINGZ _                    ' __in LPWSTR lpCommandLine
 , BYVAL bQuietModeArg AS LONG _                        ' __in BOOL   bQuietModeArg
 ) AS DWORD                                             ' LOADPERF_FUNCTION

#IF %DEF(%UNICODE)
   MACRO LoadPerfCounterTextStrings = LoadPerfCounterTextStringsW
#ELSE
   MACRO LoadPerfCounterTextStrings = LoadPerfCounterTextStringsA
#ENDIF

DECLARE FUNCTION UnloadPerfCounterTextStringsW IMPORT "LOADPERF.DLL" ALIAS "UnloadPerfCounterTextStringsW" ( _
   BYREF lpCommandLine AS WSTRINGZ _                    ' __in LPWSTR lpCommandLine
 , BYVAL bQuietModeArg AS LONG _                        ' __in BOOL   bQuietModeArg
 ) AS DWORD                                             ' LOADPERF_FUNCTION

DECLARE FUNCTION UnloadPerfCounterTextStringsA IMPORT "LOADPERF.DLL" ALIAS "UnloadPerfCounterTextStringsA" ( _
   BYREF lpCommandLine AS ASCIIZ _                      ' __in LPSTR lpCommandLine
 , BYVAL bQuietModeArg AS LONG _                        ' __in BOOL  bQuietModeArg
 ) AS DWORD                                             ' LOADPERF_FUNCTION

#IF %DEF(%UNICODE)
   MACRO UnloadPerfCounterTextStrings = UnloadPerfCounterTextStringsW
#ELSE
   MACRO UnloadPerfCounterTextStrings = UnloadPerfCounterTextStringsA
#ENDIF

DECLARE FUNCTION UpdatePerfNameFilesA IMPORT "LOADPERF.DLL" ALIAS "UpdatePerfNameFilesA" ( _
   BYREF szNewCtrFilePath AS ASCIIZ _                   ' __in LPCSTR    szNewCtrFilePath
 , BYREF szNewHlpFilePath AS ASCIIZ _                   ' __in LPCSTR    szNewHlpFilePath
 , BYREF szLanguageID AS ASCIIZ _                       ' __in LPSTR     szLanguageID
 , BYVAL dwFlags AS DWORD _                             ' __in ULONG_PTR dwFlags
 ) AS DWORD                                             ' LOADPERF_FUNCTION

DECLARE FUNCTION UpdatePerfNameFilesW IMPORT "LOADPERF.DLL" ALIAS "UpdatePerfNameFilesW" ( _
   BYREF szNewCtrFilePath AS WSTRINGZ _                 ' __in LPCWSTR   szNewCtrFilePath
 , BYREF szNewHlpFilePath AS WSTRINGZ _                 ' __in LPCWSTR   szNewHlpFilePath
 , BYVAL szLanguageID AS DWORD _                        ' __in LPSWTR    szLanguageID
 , BYVAL dwFlags AS DWORD _                             ' __in ULONG_PTR dwFlags
 ) AS DWORD                                             ' LOADPERF_FUNCTION

#IF %DEF(%UNICODE)
   MACRO UpdatePerfNameFiles = UpdatePerfNameFilesW
#ELSE
   MACRO UpdatePerfNameFiles = UpdatePerfNameFilesA
#ENDIF

DECLARE FUNCTION SetServiceAsTrustedA IMPORT "LOADPERF.DLL" ALIAS "SetServiceAsTrustedA" ( _
   BYREF szReserved AS ASCIIZ _                         ' __in LPCSTR    szReserved
 , BYREF szServiceName AS ASCIIZ _                      ' __in LPCSTR    szServiceName
 ) AS DWORD                                             ' LOADPERF_FUNCTION

DECLARE FUNCTION SetServiceAsTrustedW IMPORT "LOADPERF.DLL" ALIAS "SetServiceAsTrustedW" ( _
   BYREF szReserved AS WSTRINGZ _                       ' __in LPCWSTR szReserved
 , BYREF szServiceName AS WSTRINGZ _                    ' __in LPCWSTR szServiceName
 ) AS DWORD                                             ' LOADPERF_FUNCTION

#IF %DEF(%UNICODE)
   MACRO SetServiceAsTrusted = SetServiceAsTrustedW
#ELSE
   MACRO SetServiceAsTrusted = SetServiceAsTrustedA
#ENDIF

DECLARE FUNCTION BackupPerfRegistryToFileW IMPORT "LOADPERF.DLL" ALIAS "BackupPerfRegistryToFileW" ( _
   BYREF szFileName AS WSTRINGZ _                       ' __in LPCWSTR szFileName
 , BYREF szCommentString AS WSTRINGZ _                  ' __in LPCWSTR szCommentString
 ) AS DWORD                                             ' DWORD

MACRO BackupPerfRegistryToFile = BackupPerfRegistryToFileW

DECLARE FUNCTION RestorePerfRegistryFromFileW IMPORT "LOADPERF.DLL" ALIAS "RestorePerfRegistryFromFileW" ( _
   BYREF szFileName AS WSTRINGZ _                       ' __in LPCWSTR szFileName
 , BYREF szLangId AS WSTRINGZ _                         ' __in LPCWSTR szLangId
 ) AS DWORD                                             ' DWORD

MACRO RestorePerfRegistryFromFile = RestorePerfRegistryFromFileW
