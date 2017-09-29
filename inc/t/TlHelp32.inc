' ########################################################################################
' Microsoft Windows
' File: TlHelp32.inc
' Contents: WIN32 tool help functions, types, and definitions
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%TLHELP32_INC = 1

#INCLUDE ONCE "windows.inc"

%MAX_MODULE_NAME32 = 255

'/****** Shapshot function **********************************************/

DECLARE FUNCTION CreateToolhelp32Snapshot IMPORT "kernel32.dll" ALIAS "CreateToolhelp32Snapshot" ( _
   BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYVAL th32ProcessID AS DWORD _                       ' __in DWORD th32ProcessID
 ) AS DWORD                                             ' HANDLE

'//
'// The th32ProcessID argument is only used if TH32CS_SNAPHEAPLIST or
'// TH32CS_SNAPMODULE is specified. th32ProcessID == 0 means the current
'// process.
'//
'// NOTE that all of the snapshots are global except for the heap and module
'//      lists which are process specific. To enumerate the heap or module
'//      state for all WIN32 processes call with TH32CS_SNAPALL and the
'//      current process. Then for each process in the TH32CS_SNAPPROCESS
'//      list that isn't the current process, do a call with just
'//      TH32CS_SNAPHEAPLIST and/or TH32CS_SNAPMODULE.
'//
'// dwFlags
'//
%TH32CS_SNAPHEAPLIST = &H00000001???
%TH32CS_SNAPPROCESS  = &H00000002???
%TH32CS_SNAPTHREAD   = &H00000004???
%TH32CS_SNAPMODULE   = &H00000008???
%TH32CS_SNAPMODULE32 = &H00000010???
%TH32CS_SNAPALL      = %TH32CS_SNAPHEAPLIST OR %TH32CS_SNAPPROCESS OR %TH32CS_SNAPTHREAD OR %TH32CS_SNAPMODULE
%TH32CS_INHERIT      = &H80000000???
'//
'// Use CloseHandle to destroy the snapshot
'//

'/****** heap walking ***************************************************/

' // Size = 16 bytes
TYPE HEAPLIST32 DWORD
   dwSize        AS DWORD   ' SIZE_T
   th32ProcessID AS DWORD   ' DWORD       ' // owning process
   th32HeapID    AS DWORD   ' ULONG_PTR   ' // heap (in owning process's context!)
   dwFlags       AS DWORD   ' DWORD
END TYPE

'//
'// dwFlags
'//
%HF32_DEFAULT     = 1  ' // process's default heap
%HF32_SHARED      = 2  ' // is shared heap

DECLARE FUNCTION Heap32ListFirst IMPORT "kernel32.dll" ALIAS "Heap32ListFirst" ( _
   BYVAL hSnapshot AS DWORD _                           ' __in HANDLE hSnapshot
 , BYREF lphl AS HEAPLIST32 _                           ' __in_out LPHEAPLIST32 lphl
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION Heap32ListNext IMPORT "kernel32.dll" ALIAS "Heap32ListNext" ( _
   BYVAL hSnapshot AS DWORD _                           ' __in  HANDLE hSnapshot
 , BYREF lphl AS HEAPLIST32 _                           ' __out LPHEAPLIST32 lphl
 ) AS LONG                                              ' BOOL

' // Size = 36 bytes
TYPE HEAPENTRY32 DWORD
   dwSize        AS DWORD   ' SIZE_T
   hHandle       AS DWORD   ' HANDLE // Handle of this heap block
   dwAddress     AS DWORD   ' ULONG_PTR // Linear address of start of block
   dwBlockSize   AS DWORD   ' SIZE_T // Size of block in bytes
   dwFlags       AS DWORD   ' DWORD
   dwLockCount   AS DWORD   ' DWORD
   dwResvd       AS DWORD   ' DWORD
   th32ProcessID AS DWORD   ' DWORD // owning process
   th32HeapID    AS DWORD   ' DWORD // heap block is in
END TYPE

'//
'// dwFlags
'//
%LF32_FIXED    = &H00000001???
%LF32_FREE     = &H00000002???
%LF32_MOVEABLE = &H00000004???

DECLARE FUNCTION Heap32First IMPORT "kernel32.dll" ALIAS "Heap32First" ( _
   BYREF lphe AS HEAPENTRY32 _                          ' __in_out LPHEAPENTRY32 lphe
 , BYVAL th32ProcessID AS DWORD _                       ' __in DWORD th32ProcessID
 , BYVAL th32HeapID AS DWORD _                          ' __in ULONG_PTR th32HeapID
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION Heap32Next IMPORT "kernel32.dll" ALIAS "Heap32Next" ( _
   BYREF lphe AS HEAPENTRY32 _                          ' __out LPHEAPENTRY32 lphe
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION Toolhelp32ReadProcessMemory IMPORT "kernel32.dll" ALIAS "Toolhelp32ReadProcessMemory" ( _
   BYVAL th32ProcessID AS DWORD _                       ' __in  DWORD   th32ProcessID
 , BYVAL lpBaseAddress AS DWORD _                       ' __in  LPCVOID lpBaseAddress
 , BYVAL lpBuffer AS DWORD _                            ' __out LPVOID  lpBuffer
 , BYVAL cbRead AS DWORD _                              ' __in  SIZE_T  cbRead
 , BYREF lpNumberOfBytesRead AS DWORD _                 ' __out SIZE_T *lpNumberOfBytesRead
 ) AS LONG                                              ' BOOL

'/***** Process walking *************************************************/

' // Size = 556 bytes
TYPE PROCESSENTRY32W DWORD
   dwSize              AS DWORD                  ' DWORD
   cntUsage            AS DWORD                  ' DWORD
   th32ProcessID       AS DWORD                  ' DWORD // this process
   th32DefaultHeapID   AS DWORD                  ' ULONG_PTR
   th32ModuleID        AS DWORD                  ' DWORD // associated exe
   cntThreads          AS DWORD                  ' DWORD
   th32ParentProcessID AS DWORD                  ' DWORD // this process's parent process
   pcPriClassBase      AS LONG                   ' LONG // Base priority of process's threads
   dwFlags             AS DWORD                  ' DWORD
   szExeFile           AS WSTRINGZ * %MAX_PATH   ' WCHAR[MAX_PATH] // Path
END TYPE

DECLARE FUNCTION Process32FirstW IMPORT "kernel32.dll" ALIAS "Process32FirstW" ( _
   BYVAL hSnapshot AS DWORD _                           ' __in HANDLE hSnapshot
 , BYREF lppe AS PROCESSENTRY32W _                      ' __in_out LPPROCESSENTRY32W lppe
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION Process32NextW IMPORT "kernel32.dll" ALIAS "Process32NextW" ( _
   BYVAL hSnapshot AS DWORD _                           ' __in  HANDLE hSnapshot
 , BYREF lppe AS PROCESSENTRY32W _                      ' __out LPPROCESSENTRY32W lppe
 ) AS LONG                                              ' BOOL

' // Size = 296 bytes
TYPE PROCESSENTRY32A DWORD
   dwSize              AS DWORD                ' DWORD
   cntUsage            AS DWORD                ' DWORD
   th32ProcessID       AS DWORD                ' DWORD // this process
   th32DefaultHeapID   AS DWORD                ' ULONG_PTR
   th32ModuleID        AS DWORD                ' DWORD // associated exe
   cntThreads          AS DWORD                ' DWORD
   th32ParentProcessID AS DWORD                ' DWORD // this process's parent process
   pcPriClassBase      AS LONG                 ' LONG // Base priority of process's threads
   dwFlags             AS DWORD                ' DWORD
   szExeFile           AS ASCIIZ * %MAX_PATH   ' CHAR[MAX_PATH]
END TYPE

#IF %DEF(%UNICODE)
   MACRO PROCESSENTRY32 = PROCESSENTRY32W
#ELSE
   MACRO PROCESSENTRY32 = PROCESSENTRY32A
#ENDIF

DECLARE FUNCTION Process32FirstA IMPORT "kernel32.dll" ALIAS "Process32First" ( _
   BYVAL hSnapshot AS DWORD _                           ' __in HANDLE hSnapshot
 , BYREF lppe AS PROCESSENTRY32 _                       ' __in_out LPPROCESSENTRY32 lppe
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION Process32NextA IMPORT "kernel32.dll" ALIAS "Process32Next" ( _
   BYVAL hSnapshot AS DWORD _                           ' __in  HANDLE hSnapshot
 , BYREF lppe AS PROCESSENTRY32 _                       ' __out LPPROCESSENTRY32 lppe
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO Process32First = Process32FirstW
#ELSE
   MACRO Process32First = Process32FirstA
#ENDIF

#IF %DEF(%UNICODE)
   MACRO Process32Next = Process32NextW
#ELSE
   MACRO Process32Next = Process32NextA
#ENDIF

'/***** Thread walking **************************************************/

' // Size = 28 bytes
TYPE THREADENTRY32 DWORD
   dwSize             AS DWORD   ' DWORD
   cntUsage           AS DWORD   ' DWORD
   th32ThreadID       AS DWORD   ' DWORD // this thread
   th32OwnerProcessID AS DWORD   ' DWORD // Process this thread is associated with
   tpBasePri          AS LONG    ' LONG
   tpDeltaPri         AS LONG    ' LONG
   dwFlags            AS DWORD   ' DWORD
END TYPE

DECLARE FUNCTION Thread32First IMPORT "kernel32.dll" ALIAS "Thread32First" ( _
   BYVAL hSnapshot AS DWORD _                           ' __in HANDLE hSnapshot
 , BYREF lpte AS THREADENTRY32 _                        ' __in_out LPTHREADENTRY32 lpte
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION Thread32Next IMPORT "kernel32.dll" ALIAS "Thread32Next" ( _
   BYVAL hSnapshot AS DWORD _                           ' __in  HANDLE hSnapshot
 , BYREF lpte AS THREADENTRY32 _                        ' __out LPTHREADENTRY32 lpte
 ) AS LONG                                              ' BOOL

'/***** Module walking *************************************************/

' // Size = 1064 bytes
TYPE MODULEENTRY32W DWORD
   dwSize        AS DWORD                               ' DWORD
   th32ModuleID  AS DWORD                               ' DWORD // This module
   th32ProcessID AS DWORD                               ' DWORD // owning process
   GlblcntUsage  AS DWORD                               ' DWORD // Global usage count on the module
   ProccntUsage  AS DWORD                               ' DWORD // Module usage count in th32ProcessID's context
   modBaseAddr   AS BYTE PTR                            ' BYTE * // Base address of module in th32ProcessID's context
   modBaseSize   AS DWORD                               ' DWORD // Size in bytes of module starting at modBaseAddr
   hModule       AS DWORD                               ' HMODULE // The hModule of this module in th32ProcessID's context
   szModule      AS WSTRINGZ * %MAX_MODULE_NAME32 + 1   ' WCHAR[MAX_MODULE_NAME32]
   szExePath     AS WSTRINGZ * %MAX_PATH                ' WCHAR[MAX_PATH]
END TYPE

DECLARE FUNCTION Module32FirstW IMPORT "kernel32.dll" ALIAS "Module32FirstW" ( _
   BYVAL hSnapshot AS DWORD _                           ' __in HANDLE hSnapshot
 , BYREF lpme AS MODULEENTRY32W _                       ' __in_out LPMODULEENTRY32W lpme
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION Module32NextW IMPORT "kernel32.dll" ALIAS "Module32NextW" ( _
   BYVAL hSnapshot AS DWORD _                           ' __in  HANDLE hSnapshot
 , BYREF lpme AS MODULEENTRY32W _                       ' __out LPMODULEENTRY32W lpme
 ) AS LONG                                              ' BOOL

' // Size = 548 bytes
TYPE MODULEENTRY32A DWORD
   dwSize        AS DWORD                             ' DWORD
   th32ModuleID  AS DWORD                             ' DWORD // This module
   th32ProcessID AS DWORD                             ' DWORD // owning process
   GlblcntUsage  AS DWORD                             ' DWORD // Global usage count on the module
   ProccntUsage  AS DWORD                             ' DWORD // Module usage count in th32ProcessID's context
   modBaseAddr   AS BYTE PTR                          ' BYTE * // Base address of module in th32ProcessID's context
   modBaseSize   AS DWORD                             ' DWORD // Size in bytes of module starting at modBaseAddr
   hModule       AS DWORD                             ' DWORD // The hModule of this module in th32ProcessID's context
   szModule      AS ASCIIZ * %MAX_MODULE_NAME32 + 1   ' char[MAX_MODULE_NAME32 + 1]
   szExePath     AS ASCIIZ * %MAX_PATH                ' char[MAX_PATH]
END TYPE

#IF %DEF(%UNICODE)
   MACRO MODULEENTRY32 = MODULEENTRY32W
#ELSE
   MACRO MODULEENTRY32 = MODULEENTRY32A
#ENDIF

'//
'// NOTE CAREFULLY that the modBaseAddr and hModule fields are valid ONLY
'// in th32ProcessID's process context.
'//

DECLARE FUNCTION Module32FirstA IMPORT "kernel32.dll" ALIAS "Module32First" ( _
   BYVAL hSnapshot AS DWORD _                           ' __in HANDLE hSnapshot
 , BYREF lpme AS MODULEENTRY32 _                        ' __in_out LPMODULEENTRY32W lpme
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION Module32NextA IMPORT "kernel32.dll" ALIAS "Module32Next" ( _
   BYVAL hSnapshot AS DWORD _                           ' __in  HANDLE hSnapshot
 , BYREF lpme AS MODULEENTRY32 _                        ' __out LPMODULEENTRY32 lpme
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO Module32First = Module32FirstW
#ELSE
   MACRO Module32First = Module32FirstA
#ENDIF

#IF %DEF(%UNICODE)
   MACRO Module32Next = Module32NextW
#ELSE
   MACRO Module32Next = Module32NextA
#ENDIF
