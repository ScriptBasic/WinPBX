' ########################################################################################
' Microsoft Windows
' File: avrfsdk.inc
' Contents: Application Verifier Exposed Interfaces
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%AVRFSDK_INC = 1

#INCLUDE ONCE"windows.inc"

'//
'// tool helper function
'//

%AVRF_MAX_TRACES = 32

' // Size = 264 bytes
TYPE AVRF_BACKTRACE_INFORMATION QWORD FILL
   Depth AS DWORD   ' ULONG
   Index AS DWORD   ' ULONG
   ReturnAddresses (%AVRF_MAX_TRACES - 1) AS QUAD   ' ULONG64 ReturnAddresses[AVRF_MAX_TRACES];
END TYPE

' enum eUserAllocationState
MACRO EUSERALLOCATIONSTATE_ENUM = LONG
%AllocationStateUnknown = 0
%AllocationStateBusy    = 1
%AllocationStateFree    = 2

' enum eHeapAllocationState {
MACRO EHEAPALLOCATIONSTATE_ENUM = DWORD
%HeapFullPageHeap = &H40000000???
%HeapMetadata     = &H80000000???
%HeapStateMask    = &HFFFF0000???

' enum eHeapEnumerationLevel
MACRO EHEAPENUMERATIONLEVEL_ENUM = DWORD
%HeapEnumerationEverything = &H0???
' // reserved codes from 0x1 to oxFFFFFFFE
%HeapEnumerationStop = &HFFFFFFFF???

' // Size = 64 bytes
TYPE AVRF_HEAP_ALLOCATION QWORD FILL
   HeapHandle           AS QUAD    ' ULONG64
   UserAllocation       AS QUAD    ' ULONG64
   UserAllocationSize   AS QUAD    ' ULONG64
   Allocation           AS QUAD    ' ULONG64
   AllocationSize       AS QUAD    ' ULONG64
   UserAllocationState  AS DWORD   ' ULONG
   HeapState            AS DWORD   ' ULONG
   HeapContext          AS QUAD    ' ULONG64
   BackTraceInformation AS AVRF_BACKTRACE_INFORMATION PTR   ' PAVRF_BACKTRACE_INFORMATION BackTraceInformation
   filler               AS DWORD   ' // To keep QWORD alignment
END TYPE


' enum eHANDLE_TRACE_OPERATIONS
%OperationDbUnused = 0
%OperationDbOPEN   = 1
%OperationDbCLOSE  = 2
%OperationDbBADREF = 3

' // Size = 288 bytes
TYPE AVRF_HANDLE_OPERATION QWORD FILL
   Handle               AS QUAD    ' ULONG64
   ProcessId            AS DWORD   ' ULONG
   ThreadId             AS DWORD   ' ULONG
   OperationType        AS DWORD   ' ULONG
   Spare0               AS DWORD   ' ULONG
   BackTraceInformation AS AVRF_BACKTRACE_INFORMATION   ' AVRF_BACKTRACE_INFORMATION
END TYPE


' enum eAvrfResourceTypes
%AvrfResourceHeapAllocation = 0
%AvrfResourceHandleTrace    = 1
%AvrfResourceMax            = 2

'//
'// generic prototype
'//

'typedef ULONG
'(NTAPI * AVRF_RESOURCE_ENUMERATE_CALLBACK)(
'    PVOID ResourceDescription,
'    PVOID EnumerationContext,
'    PULONG EnumerationLevel
'    );

'FUNCTION AVRF_RESOURCE_ENUMERATE_CALLBACK ( _
'   BYVAL ResourceDescription AS DWORD _                 ' PVOID ResourceDescription
' , BYVAL EnumerationContext AS DWORD _                  ' PVOID EnumerationContext
' , BYREF EnumerationLevel AS DWORD _                    ' PULONG EnumerationLevel
' ) AS DWORD                                             ' ULONG

'//
'// Heap Allocations Specialized Prototype
'//

'typedef ULONG
'(NTAPI * AVRF_HEAPALLOCATION_ENUMERATE_CALLBACK)(
'    PAVRF_HEAP_ALLOCATION HeapAllocation,
'    PVOID EnumerationContext,
'    PULONG EnumerationLevel
'    );

'FUNCTION AVRF_HEAPALLOCATION_ENUMERATE_CALLBACK ( _
'   BYREF HeapAllocation AS PAVRF_HEAP_ALLOCATION _      ' PAVRF_HEAP_ALLOCATION HeapAllocation
' , BYVAL EnumerationContext AS DWORD _                  ' PVOID EnumerationContext
' , BYREF EnumerationLevel AS DWORD _                    ' PULONG EnumerationLevel
' ) AS DWORD                                             ' ULONG

'//
'// Handle Tracing Specialized Prototype
'//

'typedef ULONG
'(NTAPI * AVRF_HANDLEOPERATION_ENUMERATE_CALLBACK)(
'    PAVRF_HANDLE_OPERATION HandleOperation,
'    PVOID EnumerationContext,
'    PULONG EnumerationLevel
'    );

'FUNCTION AVRF_HANDLEOPERATION_ENUMERATE_CALLBACK ( _
'   BYREF HandleOperation AS AVRF_HANDLE_OPERATION _     ' PAVRF_HANDLE_OPERATION HandleOperation
' , BYVAL EnumerationContext AS DWORD _                  ' PVOID EnumerationContext
' , BYREF EnumerationLevel AS DWORD _                    ' PULONG EnumerationLevel
' ) AS DWORD                                             ' ULONG

'//
'// flags for AvrfResourceHeapAllocation
'//

%AVRF_ENUM_RESOURCES_FLAGS_SUSPEND             = &H00000001???
%AVRF_ENUM_RESOURCES_FLAGS_DONT_RESOLVE_TRACES = &H00000002???

FUNCTION VerifierEnumerateResource ( _
   BYVAL hProcess AS DWORD _                            ' HANDLE
 , BYVAL Flags AS DWORD _                               ' ULONG
 , BYVAL ResourceType AS DWORD _                        ' ULONG
 , BYVAL ResourceCallback AS DWORD _                    ' AVRF_RESOURCE_ENUMERATE_CALLBACK
 , BYVAL EnumerationContext AS DWORD _                  ' PVOID
 ) AS DWORD                                             ' ULONG

   LOCAL dwRes AS DWORD
   LOCAL hLib AS DWORD
   LOCAL pProc AS DWORD
   hLib = LoadLibrary("verifier.dll")
   IF hLib = %NULL THEN EXIT FUNCTION
   pProc = GetProcAddress(hLib, "VerifierEnumerateResource")
   IF pProc THEN CALL DWORD pProc USING VerifierEnumerateResource(hProcess, Flags, ResourceType, ResourceCallback, EnumerationContext) TO dwRes
   FreeLibrary hLib
   FUNCTION = dwRes

END FUNCTION

'//
'// API to find out if per user verifier settings are enabled
'//

FUNCTION VerifierIsPerUserSettingsEnabled () AS LONG

   LOCAL bRes AS DWORD
   LOCAL hLib AS DWORD
   LOCAL pProc AS DWORD
   hLib = LoadLibrary("verifier.dll")
   IF hLib = %NULL THEN EXIT FUNCTION
   pProc = GetProcAddress(hLib, "VerifierIsPerUserSettingsEnabled")
   IF pProc THEN CALL DWORD pProc USING VerifierIsPerUserSettingsEnabled() TO bRes
   FreeLibrary hLib
   FUNCTION = bRes

END FUNCTION
