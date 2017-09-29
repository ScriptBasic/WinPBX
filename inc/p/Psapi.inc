' ########################################################################################
' Microsoft Windows
' File: Psapi.inc
' Contents: Include file for APIs provided by PSAPI.DLL
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%PSAPI_INC = 1

#INCLUDE ONCE "WINDOWS.INC"

%LIST_MODULES_DEFAULT = &H0   ' // This is the default one app would get without any flag.
%LIST_MODULES_32BIT   = &H01  ' // list 32bit modules in the target process.
%LIST_MODULES_64BIT   = &H02  ' // list all 64bit modules. 32bit exe will be stripped off.

'// list all the modules
%LIST_MODULES_ALL   = %LIST_MODULES_32BIT OR %LIST_MODULES_64BIT

DECLARE FUNCTION EnumProcesses IMPORT "PSAPI.DLL" ALIAS "EnumProcesses" ( _
   BYREF lpidProcess AS DWORD _                         ' __out DWORD * lpidProcess
 , BYVAL cb AS DWORD _                                  ' __in  DWORD cb
 , BYREF lpcbNeeded AS DWORD _                          ' __out LPDWORD lpcbNeeded
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION EnumProcessModules IMPORT "PSAPI.DLL" ALIAS "EnumProcessModules" ( _
   BYVAL hProcess AS DWORD _                            ' __in  HANDLE hProcess
 , BYREF lphModule AS DWORD _                           ' __out HMODULE *lphModule
 , BYVAL cb AS DWORD _                                  ' __in  DWORD cb
 , BYREF lpcbNeeded AS DWORD _                          ' __out LPDWORD lpcbNeeded
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION EnumProcessModulesEx IMPORT "PSAPI.DLL" ALIAS "EnumProcessModulesEx" ( _
   BYVAL hProcess AS DWORD _                            ' __in  HANDLE hProcess
 , BYVAL lphModule AS DWORD _                           ' __out HMODULE *lphModule
 , BYVAL cb AS DWORD _                                  ' __in  DWORD cb
 , BYREF lpcbNeeded AS DWORD _                          ' __out LPDWORD lpcbNeeded
 , BYVAL dwFilterFlag AS DWORD _                        ' __in  DWORD dwFilterFlag
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetModuleBaseNameA IMPORT "PSAPI.DLL" ALIAS "GetModuleBaseNameA" ( _
   BYVAL hProcess AS DWORD _                            ' __in HANDLE hProcess
 , BYVAL hModule AS DWORD _                             ' __in_opt HMODULE hModule
 , BYREF lpBaseName AS ASCIIZ _                         ' __out LPSTR lpBaseName
 , BYVAL nSize AS DWORD _                               ' __in DWORD nSize
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION GetModuleBaseNameW IMPORT "PSAPI.DLL" ALIAS "GetModuleBaseNameW" ( _
   BYVAL hProcess AS DWORD _                            ' __in HANDLE hProcess
 , BYVAL hModule AS DWORD _                             ' __in_opt HMODULE hModule
 , BYREF lpBaseName AS WSTRINGZ _                       ' __out LPWSTR lpBaseName
 , BYVAL nSize AS DWORD _                               ' __in DWORD nSize
 ) AS DWORD                                             ' DWORD

#IF %DEF(%UNICODE)
   MACRO GetModuleBaseName = GetModuleBaseNameW
#ELSE
   MACRO GetModuleBaseName = GetModuleBaseNameA
#ENDIF

DECLARE FUNCTION GetModuleFileNameExA IMPORT "PSAPI.DLL" ALIAS "GetModuleFileNameExA" ( _
   BYVAL hProcess AS DWORD _                            ' __in HANDLE hProcess
 , BYVAL hModule AS DWORD _                             ' __in_opt HMODULE hModule
 , BYREF lpFilename AS ASCIIZ _                         ' __out LPSTR lpFilename
 , BYVAL nSize AS DWORD _                               ' __in DWORD nSize
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION GetModuleFileNameExW IMPORT "PSAPI.DLL" ALIAS "GetModuleFileNameExW" ( _
   BYVAL hProcess AS DWORD _                            ' __in HANDLE hProcess
 , BYVAL hModule AS DWORD _                             ' __in_opt HMODULE hModule
 , BYREF lpFilename AS WSTRINGZ _                       ' __out LPWSTR lpFilename
 , BYVAL nSize AS DWORD _                               ' __in DWORD nSize
 ) AS DWORD                                             ' DWORD

#IF %DEF(%UNICODE)
   MACRO GetModuleFileNameEx = GetModuleFileNameExW
#ELSE
   MACRO GetModuleFileNameEx = GetModuleFileNameExA
#ENDIF

' // Size = 12 bytes
TYPE MODULEINFO DWORD
   lpBaseOfDll AS DWORD   ' LPVOID
   SizeOfImage AS DWORD   ' DWORD
   EntryPoint  AS DWORD   ' LPVOID
END TYPE

DECLARE FUNCTION GetModuleInformation IMPORT "PSAPI.DLL" ALIAS "GetModuleInformation" ( _
   BYVAL hProcess AS DWORD _                            ' __in  HANDLE hProcess
 , BYVAL hModule AS DWORD _                             ' __in  HMODULE hModule
 , BYREF lpmodinfo AS MODULEINFO _                      ' __out LPMODULEINFO lpmodinfo
 , BYVAL cb AS DWORD _                                  ' __in  DWORD cb
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION EmptyWorkingSet IMPORT "PSAPI.DLL" ALIAS "EmptyWorkingSet" ( _
   BYVAL hProcess AS DWORD _                            ' __in HANDLE hProcess
 ) AS LONG                                              ' BOOL

'//
'// Working set information structures. All non-specified bits are reserved.
'//

'typedef union _PSAPI_WORKING_SET_BLOCK {
'    ULONG_PTR Flags;
'    struct {
'        ULONG_PTR Protection : 5;
'        ULONG_PTR ShareCount : 3;
'        ULONG_PTR Shared : 1;
'        ULONG_PTR Reserved : 3;
'#if defined(_WIN64)
'        ULONG_PTR VirtualPage : 52;
'#else
'        ULONG_PTR VirtualPage : 20;
'#endif
'    };
'} PSAPI_WORKING_SET_BLOCK, *PPSAPI_WORKING_SET_BLOCK;

'#IF %DEF(%WIN64) THEN
'' // Size = 8 bytes
'TYPE PSAPI_WORKING_SET_BLOCK_STRUCT QWORD
'   Protection  AS BIT * 5 IN QUAD   ' ULONG_PTR
'   ShareCount  AS BIT * 3
'   Shared      AS BIT * 1
'   Reserved    AS BIT * 3
'   VirtualPage AS BIT * 52
'END TYPE
'#ELSE
' // Size = 4 bytes
TYPE PSAPI_WORKING_SET_BLOCK_STRUCT DWORD
   Protection  AS BIT * 5 IN DWORD   ' ULONG_PTR
   ShareCount  AS BIT * 3
   Shared      AS BIT * 1
   Reserved    AS BIT * 3
   VirtualPage AS BIT * 20
END TYPE
'#ENDIF

'#IF %DEF(%WIN64) THEN
' // Size = 8 bytes
'UNION PSAPI_WORKING_SET_BLOCK QWORD
'   Flags AS QUAD   ' ULONG_PTR
'   PSAPI_WORKING_SET_BLOCK_STRUCT
'END UNION
'#ELSE
' // Size = 4 bytes
UNION PSAPI_WORKING_SET_BLOCK DWORD
   Flags AS DWORD   ' ULONG_PTR
   PSAPI_WORKING_SET_BLOCK_STRUCT
END UNION
'#ENDIF

' // Size = 8 bytes
TYPE PSAPI_WORKING_SET_INFORMATION DWORD
   NumberOfEntries   AS DWORD   ' ULONG_PTR
   WorkingSetInfo(0) AS PSAPI_WORKING_SET_BLOCK
END TYPE

'typedef union _PSAPI_WORKING_SET_EX_BLOCK {
'    ULONG_PTR Flags;
'    struct {
'        ULONG_PTR Valid : 1;        // The following fields are valid only if this bit is set
'        ULONG_PTR ShareCount : 3;
'        ULONG_PTR Win32Protection : 11;
'        ULONG_PTR Shared : 1;
'        ULONG_PTR Node : 6;
'        ULONG_PTR Locked : 1;
'        ULONG_PTR LargePage : 1;
'    };
'} PSAPI_WORKING_SET_EX_BLOCK, *PPSAPI_WORKING_SET_EX_BLOCK;

'#IF %DEF(%WIN64) THEN
' // Size = 8 bytes
'TYPE PSAPI_WORKING_SET_EX_BLOCK_STRUCT QDWORD
'   Valid           AS BIT * 1 IN QUAD   ' ULONG_PTR // The following fields are valid only if this bit is set
'   ShareCount      AS BIT * 3
'   Win32Protection AS BIT * 11
'   Shared          AS BIT * 1
'   Node            AS BIT * 6
'   Locked          AS BIT * 1
'   LargePage       AS BIT * 1
'END TYPE
'#ELSE
' // Size = 4 bytes
TYPE PSAPI_WORKING_SET_EX_BLOCK_STRUCT DWORD
   Valid           AS BIT * 1 IN DWORD   ' ULONG_PTR // The following fields are valid only if this bit is set
   ShareCount      AS BIT * 3
   Win32Protection AS BIT * 11
   Shared          AS BIT * 1
   Node            AS BIT * 6
   Locked          AS BIT * 1
   LargePage       AS BIT * 1
END TYPE
'#ENDIF

' // Size = 4 bytes
UNION PSAPI_WORKING_SET_EX_BLOCK DWORD
   Flags AS DWORD   ' ULONG_PTR
   PSAPI_WORKING_SET_EX_BLOCK_STRUCT
END UNION

' // Size = 8 bytes
TYPE PSAPI_WORKING_SET_EX_INFORMATION DWORD
   VirtualAddress    AS DWORD   ' PVOID
   VirtualAttributes AS PSAPI_WORKING_SET_EX_BLOCK
END TYPE

DECLARE FUNCTION QueryWorkingSet IMPORT "PSAPI.DLL" ALIAS "QueryWorkingSet" ( _
   BYVAL hProcess AS DWORD _                            ' __in  HANDLE hProcess
 , BYVAL pv AS DWORD _                                  ' __out PVOID pv
 , BYVAL cb AS DWORD _                                  ' __in  DWORD cb
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION QueryWorkingSetEx IMPORT "PSAPI.DLL" ALIAS "QueryWorkingSetEx" ( _
   BYVAL hProcess AS DWORD _                            ' __in  HANDLE hProcess
 , BYVAL pv AS DWORD _                                  ' __out PVOID pv
 , BYVAL cb AS DWORD _                                  ' __in  DWORD cb
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION InitializeProcessForWsWatch IMPORT "PSAPI.DLL" ALIAS "InitializeProcessForWsWatch" ( _
   BYVAL hProcess AS DWORD _                            ' __in HANDLE hProcess
 ) AS LONG                                              ' BOOL

' // Size = 8 bytes
TYPE PSAPI_WS_WATCH_INFORMATION DWORD
   FaultingPc AS DWORD   ' LPVOID
   FaultingVa AS DWORD   ' LPVOID
END TYPE

' // Size = 16 bytes
TYPE PSAPI_WS_WATCH_INFORMATION_EX DWORD
   BasicInfo        AS PSAPI_WS_WATCH_INFORMATION
   FaultingThreadId AS DWORD   ' ULONG_PTR
   Flags            AS DWORD   ' ULONG_PTR // Reserved
END TYPE

DECLARE FUNCTION GetWsChanges IMPORT "PSAPI.DLL" ALIAS "GetWsChanges" ( _
   BYVAL hProcess AS DWORD _                            ' __in  HANDLE hProcess
 , BYREF lpWatchInfo AS PSAPI_WS_WATCH_INFORMATION _    ' __out PSAPI_WS_WATCH_INFORMATION lpWatchInfo
 , BYVAL cb AS DWORD _                                  ' __in  DWORD cb
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetWsChangesEx IMPORT "PSAPI.DLL" ALIAS "GetWsChangesEx" ( _
   BYVAL hProcess AS DWORD _                            ' __in  HANDLE hProcess
 , BYREF lpWatchInfoEx AS PSAPI_WS_WATCH_INFORMATION_EX _ ' __out PPSAPI_WS_WATCH_INFORMATION_EX lpWatchInfoEx
 , BYVAL cb AS DWORD _                                  ' __in  PDWORD cb
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetMappedFileNameW IMPORT "PSAPI.DLL" ALIAS "GetMappedFileNameW" ( _
   BYVAL hProcess AS DWORD _                            ' __in  HANDLE hProcess
 , BYVAL lpv AS DWORD _                                 ' __in  LPVOID lpv
 , BYREF lpFilename AS WSTRINGZ _                       ' __out LPWSTR lpFilename
 , BYVAL nSize AS DWORD _                               ' __in  DWORD nSize
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION GetMappedFileNameA IMPORT "PSAPI.DLL" ALIAS "GetMappedFileNameA" ( _
   BYVAL hProcess AS DWORD _                            ' __in  HANDLE hProcess
 , BYVAL lpv AS DWORD _                                 ' __in  LPVOID lpv
 , BYREF lpFilename AS ASCIIZ _                         ' __out LPSTR lpFilename
 , BYVAL nSize AS DWORD _                               ' __in  DWORD nSize
 ) AS DWORD                                             ' DWORD

#IF %DEF(%UNICODE)
   MACRO GetMappedFileName = GetMappedFileNameW
#ELSE
   MACRO GetMappedFileName = GetMappedFileNameA
#ENDIF

DECLARE FUNCTION EnumDeviceDrivers IMPORT "PSAPI.DLL" ALIAS "EnumDeviceDrivers" ( _
   BYREF lpImageBase AS ANY _                           ' __out LPVOID *lpImageBase
 , BYVAL cb AS DWORD _                                  ' __in  DWORD cb
 , BYREF lpcbNeeded AS DWORD _                          ' __out LPDWORD lpcbNeeded
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetDeviceDriverBaseNameA IMPORT "PSAPI.DLL" ALIAS "GetDeviceDriverBaseNameA" ( _
   BYVAL ImageBase AS DWORD _                           ' __in  LPVOID ImageBase
 , BYREF lpFilename AS ASCIIZ _                         ' __out LPSTR lpFilename
 , BYVAL nSize AS DWORD _                               ' __in  DWORD nSize
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION GetDeviceDriverBaseNameW IMPORT "PSAPI.DLL" ALIAS "GetDeviceDriverBaseNameW" ( _
   BYVAL ImageBase AS DWORD _                           ' __in  LPVOID ImageBase
 , BYREF lpBaseName AS WSTRINGZ _                       ' __out LPWSTR lpBaseName
 , BYVAL nSize AS DWORD _                               ' __in  DWORD nSize
 ) AS DWORD                                             ' DWORD

#IF %DEF(%UNICODE)
   MACRO GetDeviceDriverBaseName = GetDeviceDriverBaseNameW
#ELSE
   MACRO GetDeviceDriverBaseName = GetDeviceDriverBaseNameA
#ENDIF

DECLARE FUNCTION GetDeviceDriverFileNameA IMPORT "PSAPI.DLL" ALIAS "GetDeviceDriverFileNameA" ( _
   BYVAL ImageBase AS DWORD _                           ' __in  LPVOID ImageBase
 , BYREF lpFilename AS ASCIIZ _                         ' __out LPSTR lpFilename
 , BYVAL nSize AS DWORD _                               ' __in  DWORD nSize
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION GetDeviceDriverFileNameW IMPORT "PSAPI.DLL" ALIAS "GetDeviceDriverFileNameW" ( _
   BYVAL ImageBase AS DWORD _                           ' __in  LPVOID ImageBase
 , BYREF lpFilename AS WSTRINGZ _                       ' __out LPWSTR lpFilename
 , BYVAL nSize AS DWORD _                               ' __in  DWORD nSize
 ) AS DWORD                                             ' DWORD

#IF %DEF(%UNICODE)
   MACRO GetDeviceDriverFileName = GetDeviceDriverFileNameW
#ELSE
   MACRO GetDeviceDriverFileName = GetDeviceDriverFileNameA
#ENDIF

'// Structure for GetProcessMemoryInfo()

' // Size = 40 bytes
TYPE PROCESS_MEMORY_COUNTERS DWORD
   cb                         AS DWORD   ' DWORD
   PageFaultCount             AS DWORD   ' DWORD
   PeakWorkingSetSize         AS DWORD   ' SIZE_T
   WorkingSetSize             AS DWORD   ' SIZE_T
   QuotaPeakPagedPoolUsage    AS DWORD   ' SIZE_T
   QuotaPagedPoolUsage        AS DWORD   ' SIZE_T
   QuotaPeakNonPagedPoolUsage AS DWORD   ' SIZE_T
   QuotaNonPagedPoolUsage     AS DWORD   ' SIZE_T
   PagefileUsage              AS DWORD   ' SIZE_T
   PeakPagefileUsage          AS DWORD   ' SIZE_T
END TYPE

'#if (_WIN32_WINNT >= 0x0501)
' Requires Windows Vista or Windows XP SP2.
' // Size = 44 bytes
TYPE PROCESS_MEMORY_COUNTERS_EX DWORD
   cb                         AS DWORD   ' DWORD
   PageFaultCount             AS DWORD   ' DWORD
   PeakWorkingSetSize         AS DWORD   ' SIZE_T
   WorkingSetSize             AS DWORD   ' SIZE_T
   QuotaPeakPagedPoolUsage    AS DWORD   ' SIZE_T
   QuotaPagedPoolUsage        AS DWORD   ' SIZE_T
   QuotaPeakNonPagedPoolUsage AS DWORD   ' SIZE_T
   QuotaNonPagedPoolUsage     AS DWORD   ' SIZE_T
   PagefileUsage              AS DWORD   ' SIZE_T
   PeakPagefileUsage          AS DWORD   ' SIZE_T
   PrivateUsage               AS DWORD   ' SIZE_T
END TYPE
'#endif

DECLARE FUNCTION GetProcessMemoryInfo IMPORT "PSAPI.DLL" ALIAS "GetProcessMemoryInfo" ( _
   BYVAL hProcess AS DWORD _                            ' __in HANDLE hProcess
 , BYREF ppsmemCounters AS PROCESS_MEMORY_COUNTERS _    ' __out PPROCESS_MEMORY_COUNTERS ppsmemCounters
 , BYVAL cb AS DWORD _                                  ' __in DWORD cb
 ) AS LONG                                              ' BOOL

' // Size = 56 bytes
TYPE PERFORMANCE_INFORMATION DWORD
   cb                AS DWORD   ' DWORD
   CommitTotal       AS DWORD   ' SIZE_T
   CommitLimit       AS DWORD   ' SIZE_T
   CommitPeak        AS DWORD   ' SIZE_T
   PhysicalTotal     AS DWORD   ' SIZE_T
   PhysicalAvailable AS DWORD   ' SIZE_T
   SystemCache       AS DWORD   ' SIZE_T
   KernelTotal       AS DWORD   ' SIZE_T
   KernelPaged       AS DWORD   ' SIZE_T
   KernelNonpaged    AS DWORD   ' SIZE_T
   PageSize          AS DWORD   ' SIZE_T
   HandleCount       AS DWORD   ' DWORD
   ProcessCount      AS DWORD   ' DWORD
   ThreadCount       AS DWORD   ' DWORD
END TYPE

DECLARE FUNCTION GetPerformanceInfo IMPORT "PSAPI.DLL" ALIAS "GetPerformanceInfo" ( _
   BYREF pPerformanceInformation AS PERFORMANCE_INFORMATION _ ' __out PPERFORMANCE_INFORMATION pPerformanceInformation
 , BYREF cb AS DWORD _                                  ' __in DWORD cb
 ) AS LONG                                              ' BOOL

' // Size = 20 bytes
TYPE ENUM_PAGE_FILE_INFORMATION DWORD
   cb         AS DWORD   ' DWORD
   Reserved   AS DWORD   ' DWORD
   TotalSize  AS DWORD   ' SIZE_T
   TotalInUse AS DWORD   ' SIZE_T
   PeakUsage  AS DWORD   ' SIZE_T
END TYPE

'typedef BOOL (*PENUM_PAGE_FILE_CALLBACKW) (LPVOID pContext, PENUM_PAGE_FILE_INFORMATION pPageFileInfo, LPCWSTR lpFilename);
'FUNCTION ENUM_PAGE_FILE_CALLBACKW ( _
'   BYVAL pContext AS DWORD _                            ' __in LPVOID pContext
' , BYREF pPageFileInfo AS ENUM_PAGE_FILE_INFORMATION _  ' __in ENUM_PAGE_FILE_INFORMATION pPageFileInfo
' , BYREF lpFileName AS WSTRINGZ _                       ' __in LPCWSTR lpFileName
' ) AS LONG                                              ' BOOL
'END FUNCTION

'typedef BOOL (*PENUM_PAGE_FILE_CALLBACKA) (LPVOID pContext, PENUM_PAGE_FILE_INFORMATION pPageFileInfo, LPCSTR lpFilename);
'FUNCTION ENUM_PAGE_FILE_CALLBACKA ( _
'   BYVAL pContext AS DWORD _                            ' __in LPVOID pContext
' , BYREF pPageFileInfo AS ENUM_PAGE_FILE_INFORMATION _  ' __in ENUM_PAGE_FILE_INFORMATION pPageFileInfo
' , BYREF lpFileName AS ASCIIZ _                         ' __in LPCSTR lpFileName
' ) AS LONG                                              ' BOOL
'END FUNCTION

DECLARE FUNCTION EnumPageFilesW IMPORT "PSAPI.DLL" ALIAS "EnumPageFilesW" ( _
   BYREF pCallbackRoutine AS DWORD _                    ' __out PENUM_PAGE_CALLBACK pCallbackRoutine
 , BYVAL lpContext AS DWORD _                           ' __in LPVOID lpContext
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION EnumPageFilesA IMPORT "PSAPI.DLL" ALIAS "EnumPageFilesA" ( _
   BYREF pCallbackRoutine AS DWORD _                    ' __out PENUM_PAGE_CALLBACK pCallbackRoutine
 , BYVAL lpContext AS DWORD _                           ' __in LPVOID lpContext
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO EnumPageFiles = EnumPageFilesW
#ELSE
   MACRO EnumPageFiles = EnumPageFilesA
#ENDIF

DECLARE FUNCTION GetProcessImageFileNameA IMPORT "PSAPI.DLL" ALIAS "GetProcessImageFileNameA" ( _
   BYVAL hProcess AS DWORD _                            ' __in HANDLE hProcess
 , BYREF lpImageFileName AS ASCIIZ _                    ' __out LPSTR lpImageFileName
 , BYVAL nSize AS DWORD _                               ' __in DWORD nSize
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION GetProcessImageFileNameW IMPORT "PSAPI.DLL" ALIAS "GetProcessImageFileNameA" ( _
   BYVAL hProcess AS DWORD _                            ' __in HANDLE hProcess
 , BYREF lpImageFileName AS WSTRINGZ _                  ' __out LPWSTR lpImageFileName
 , BYVAL nSize AS DWORD _                               ' __in DWORD nSize
 ) AS DWORD                                             ' DWORD

#IF %DEF(%UNICODE)
   MACRO GetProcessImageFileName = GetProcessImageFileNameW
#ELSE
   MACRO GetProcessImageFileName = GetProcessImageFileNameA
#ENDIF
