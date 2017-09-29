' ########################################################################################
' Microsoft Windows
' File: perflib.inc
' Contents: Public headers for PERFLIB provider APIs,
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%PERFLIB_INC = 1

'// PERFLIB V2 provider side published literals, data structures and APIs.
'//

'// This is used in generated PERF_COUNTERSET_INFO structure to declare provider type.
'// Kernel provider is reserved for Microsoft internal use.
'// Driver provider and user-mode provider literals will be published.
'//
%PERF_PROVIDER_USER_MODE   = 0
%PERF_PROVIDER_KERNEL_MODE = 1
%PERF_PROVIDER_DRIVER      = 2

'// These are used for PERF_COUNTERSET_INFO::InstanceType value. That is, whether the CounterSet
'// allows multiple instances (for example, Process, PhysicalDisk, etc) or only single default instance
'// (for example, Memory, TCP, etc).
'//
%PERF_COUNTERSET_FLAG_MULTIPLE            = 2  ' // 0010
%PERF_COUNTERSET_FLAG_AGGREGATE           = 4  ' // 0100
%PERF_COUNTERSET_FLAG_HISTORY             = 8  ' // 1000
%PERF_COUNTERSET_FLAG_INSTANCE            = 16  ' // 00010000

%PERF_COUNTERSET_SINGLE_INSTANCE          = 0
%PERF_COUNTERSET_MULTI_INSTANCES          = %PERF_COUNTERSET_FLAG_MULTIPLE
%PERF_COUNTERSET_SINGLE_AGGREGATE         = %PERF_COUNTERSET_FLAG_AGGREGATE
%PERF_COUNTERSET_MULTI_AGGREGATE          = %PERF_COUNTERSET_FLAG_AGGREGATE OR %PERF_COUNTERSET_FLAG_MULTIPLE
%PERF_COUNTERSET_SINGLE_AGGREGATE_HISTORY = %PERF_COUNTERSET_FLAG_HISTORY OR %PERF_COUNTERSET_SINGLE_AGGREGATE
%PERF_COUNTERSET_INSTANCE_AGGREGATE       = %PERF_COUNTERSET_MULTI_AGGREGATE OR %PERF_COUNTERSET_FLAG_INSTANCE

'// Pre-defined aggregation function for CounterSets that need counter data aggregation. This is only useful
'// for CounterSet with instanceType PERF_COUNTERSET_SINGLE_AGGREGATE, PERF_COUNTERSET_MULTI_AGGREGATE, and
'// PERF_COUNTERSET_SINGLE_AGGREGATE_HISTORY. For other CounterSet instanceTypes, this is no effect.
'//
%PERF_AGGREGATE_UNDEFINED = 0
%PERF_AGGREGATE_TOTAL     = 1
%PERF_AGGREGATE_AVG       = 2
%PERF_AGGREGATE_MIN       = 3
%PERF_AGGREGATE_MAX       = 4

'// These are possible attributes used in generated PERF_COUNTER_INFO::Attrib value.
'//
%PERF_ATTRIB_BY_REFERENCE       = &H0000000000000001&&
%PERF_ATTRIB_NO_DISPLAYABLE     = &H0000000000000002&&
%PERF_ATTRIB_NO_GROUP_SEPARATOR = &H0000000000000004&&
%PERF_ATTRIB_DISPLAY_AS_REAL    = &H0000000000000008&&
%PERF_ATTRIB_DISPLAY_AS_HEX     = &H0000000000000010&&

'// Provider counterset is defined as a leading PERF_COUNTERSET_INFO structure followed by a sequence
'// of PERF_COUNTER_INFO structures. Note that the structure block will be automatically generated
'// by schema generation/parsing tool.
'//
' // Size = 40 bytes
TYPE PERF_COUNTERSET_INFO DWORD
   CounterSetGuid AS GUID    ' GUID
   ProviderGuid   AS GUID    ' GUID
   NumCounters    AS DWORD   ' ULONG
   InstanceType   AS DWORD   ' ULONG
END TYPE

' // Size = 32 bytes
TYPE PERF_COUNTER_INFO QWORD FILL
   CounterId   AS DWORD   ' ULONG // max of 64K counters per GUID instance
   Type        AS DWORD   ' ULONG
   Attrib      AS QUAD    ' ULONGLONG
   Size        AS DWORD   ' ULONG
   DetailLevel AS DWORD   ' ULONG
   Scale       AS LONG    ' LONG
   Offset      AS DWORD   ' ULONG // overlays to give the actual counter
END TYPE

'// PERF_COUNTERSET_INSTANCE block is returned from PerfCreateInstance() API call to identify specific
'// instance of a counterset. The returned block is formed by PERF_COUNTERSET_INSTANCE structure followed
'// by counter data block (layout defined by provider counterset template) and instance name string (if exists).
'//
' // Size = 32 bytes
TYPE PERF_COUNTERSET_INSTANCE DWORD
   CounterSetGuid     AS GUID    ' GUID
   dwSize             AS DWORD   ' ULONG
   InstanceId         AS DWORD   ' ULONG
   InstanceNameOffset AS DWORD   ' ULONG
   InstanceNameSize   AS DWORD   ' ULONG
END TYPE

'// PERF_COUNTER_IDENTITY structure is used in customized notification callback. Wheneven PERFLIB V2
'// invokes customized notification callback, it passes wnode datablock (which contains WNODE_HEADER
'// structure followed by other binary data) that contains the information providers can use.
'//
'// For PERF_ADD_COUNTER and PERF_REMOVE_COUNTER request, PERFLIB will pass PERF_COUNTER_IDENTITY block
'// so that providers know which counter is added/removed. For other requests, currently only machine name
'// is passed (so that providers can determine whether the request is for physical node or virtual node).
'//
' // Size = 40 bytes
TYPE PERF_COUNTER_IDENTITY DWORD
   CounterSetGuid AS GUID    ' GUID
   BufferSize     AS DWORD   ' ULONG
   CounterId      AS DWORD   ' ULONG
   InstanceId     AS DWORD   ' ULONG
   MachineOffset  AS DWORD   ' ULONG
   NameOffset     AS DWORD   ' ULONG
   Reserved       AS DWORD   ' ULONG
END TYPE

%PERF_WILDCARD_COUNTER = &HFFFFFFFF???
'#define PERF_WILDCARD_INSTANCE  L"*"
'#define PERF_AGGREGATE_INSTANCE L"_Total"
$$PERF_WILDCARD_INSTANCE  = "*"$$
$$PERF_AGGREGATE_INSTANCE = "_Total"$$
%PERF_MAX_INSTANCE_NAME = 1024

%PERF_ADD_COUNTER           = 1
%PERF_REMOVE_COUNTER        = 2
%PERF_ENUM_INSTANCES        = 3
%PERF_COLLECT_START         = 5
%PERF_COLLECT_END           = 6
%PERF_FILTER                = 9

'// Prototype for service request callback. Data providers register with PERFLIB V2 by passing a service
'// request callback function that is called for all PERFLIB requests.
'//
'typedef ULONG (
'#ifndef MIDL_PASS
'WINAPI
'#endif
'* PERFLIBREQUEST)(
'    IN ULONG  RequestCode,
'    IN PVOID  Buffer,
'    IN ULONG  BufferSize
');

'FUNCTION PERFLIBREQUEST ( _
'   BYVAL RequestCode AS DWORD _                         ' __in ULONG  RequestCode
' , BYVAL Buffer AS DWORD _                              ' __in PVOID  Buffer
' , BYVAL BufferSize AS DWORD _                          ' __in ULONG  BufferSize
' ) AS DWORD                                             ' ULONG

'// Usually PerfSetCounterSetInfo() calls is automatically generated PerfAutoStartUp() function (generated
'// by schema generation/parsing tool) to inform PERFLIB the layout of specific counterset.
'//
'ULONG __stdcall
'PerfStartProvider(
'    __in     LPGUID          ProviderGuid,
'    __in_opt PERFLIBREQUEST  ControlCallback,
'    __out    HANDLE        * phProvider
');

'// Start PERFLIB V2 provider with customized memory allocation/free routines.
'//
'typedef LPVOID (* PERF_MEM_ALLOC)(IN SIZE_T AllocSize, IN LPVOID pContext);
'FUNCTION PERF_MEM_ALLOC (BYVAL AllocSize AS DWORD, BYVAL pContext AS DWORD) AS DWORD
'typedef void (* PERF_MEM_FREE)(IN LPVOID pBuffer, IN LPVOID pContext);
'SUB PERF_MEM_FREE (BYVAL pBuffer AS DWORD, BYVAL pContext AS DWORD)

' // Size = 24 bytes
TYPE PERF_PROVIDER_CONTEXT DWORD
   ContextSize     AS DWORD   ' DWORD // should be sizeof(PERF_PROVIDER_CONTEXT)
   Reserved        AS DWORD   ' DWORD
   ControlCallback AS DWORD   ' PERFLIBREQUEST
   MemAllocRoutine AS DWORD   ' PERF_MEM_ALLOC
   MemFreeRoutine  AS DWORD   ' PERF_MEM_FREE
   pMemContext     AS DWORD   ' LPVOID
END TYPE

MACRO PROVIDER_CONTEXT = PERF_PROVIDER_CONTEXT

DECLARE FUNCTION PerfStartProviderEx IMPORT "Advapi32.dll" ALIAS "PerfStartProviderEx" ( _
   BYREF ProviderGuid AS GUID _                         ' __in     LPGUID                  ProviderGuid
 , BYVAL ProviderContext AS DWORD _                     ' __in_opt PPERF_PROVIDER_CONTEXT  ProviderContext
 , BYREF phProvider AS DWORD _                          ' __out    PHANDLE                 phProvider
 ) AS DWORD                                             ' ULONG

DECLARE FUNCTION PerfStartProvider IMPORT "Advapi32.dll" ALIAS "PerfStartProvider" ( _
   BYREF ProviderGuid AS GUID _                         ' __in     LPGUID          ProviderGuid
 , BYVAL ControlCallback AS DWORD _                     ' __in_opt PERFLIBREQUEST  ControlCallback
 , BYREF phProvider AS DWORD _                          ' __out    HANDLE        * phProvider
 ) AS DWORD                                             ' ULONG

DECLARE FUNCTION PerfStopProvider IMPORT "Advapi32.dll" ALIAS "PerfStopProvider" ( _
   BYVAL hProvider AS DWORD _                           ' __in HANDLE hProvider
 ) AS DWORD                                             ' ULONG

DECLARE FUNCTION PerfSetCounterSetInfo IMPORT "Advapi32.dll" ALIAS "PerfSetCounterSetInfo" ( _
   BYVAL hProvider AS DWORD _                           ' __in     HANDLE hProvider
 , BYREF pTemplate AS PERF_COUNTERSET_INFO _            ' __in_out PPERF_COUNTERSET_INFO pTemplate
 , BYVAL dwTemplateSize AS DWORD _                      ' __in     ULONG dwTemplateSize
 ) AS DWORD                                             ' ULONG

DECLARE FUNCTION PerfCreateInstance IMPORT "Advapi32.dll" ALIAS "PerfCreateInstance" ( _
   BYVAL hProvider AS DWORD _                           ' __in HANDLE  hProvider
 , BYREF CounterSetGuid AS GUID _                       ' __in LPCGUID CounterSetGuid
 , BYREF szInstanceName AS WSTRINGZ _                   ' __in LPCWSTR szInstanceName
 , BYVAL dwInstance AS DWORD _                          ' __in ULONG   dwInstance
 ) AS DWORD                                             ' PERF_COUNTERSET_INSTANCE

DECLARE FUNCTION PerfDeleteInstance IMPORT "Advapi32.dll" ALIAS "PerfDeleteInstance" ( _
   BYVAL hProvider AS DWORD _                           ' __in HANDLE                   hProvider
 , BYREF InstanceBlock AS PERF_COUNTERSET_INSTANCE _    ' __in PERF_COUNTERSET_INSTANCE InstanceBlock
 ) AS DWORD                                             ' ULONG

DECLARE FUNCTION PerfQueryInstance IMPORT "Advapi32.dll" ALIAS "PerfQueryInstance" ( _
   BYVAL hProvider AS DWORD _                           ' __in HANDLE  hProvider
 , BYREF CounterSetGuid AS GUID _                       ' __in LPCGUID CounterSetGuid
 , BYREF szInstanceName AS WSTRINGZ _                   ' __in LPCWSTR szInstanceName
 , BYVAL dwInstance AS DWORD _                          ' __in ULONG   dwInstance
 ) AS DWORD                                             ' PERF_COUNTERSET_INSTANCE

DECLARE FUNCTION PerfSetCounterRefValue IMPORT "Advapi32.dll" ALIAS "PerfSetCounterRefValue" ( _
   BYVAL hProvider AS DWORD _                           ' __in HANDLE                    hProvider
 , BYREF pInstance AS PERF_COUNTERSET_INSTANCE _        ' __in PPERF_COUNTERSET_INSTANCE pInstance
 , BYVAL CounterId AS DWORD _                           ' __in ULONG                     CounterId
 , BYVAL lpAddr AS DWORD _                              ' __in LPVOID                    lpAddr
 ) AS DWORD                                             ' ULONG

DECLARE FUNCTION PerfSetULongCounterValue IMPORT "Advapi32.dll" ALIAS "PerfSetULongCounterValue" ( _
   BYVAL hProvider AS DWORD _                           ' __in HANDLE                    hProvider
 , BYREF pInstance AS PERF_COUNTERSET_INSTANCE _        ' __in PPERF_COUNTERSET_INSTANCE pInstance
 , BYVAL CounterId AS DWORD _                           ' __in ULONG                     CounterId
 , BYVAL lValue AS DWORD _                              ' __in ULONG                     lValue
 ) AS DWORD                                             ' ULONG

DECLARE FUNCTION PerfSetULongLongCounterValue IMPORT "Advapi32.dll" ALIAS "PerfSetULongLongCounterValue" ( _
   BYVAL hProvider AS DWORD _                           ' __in HANDLE                    hProvider
 , BYREF pInstance AS PERF_COUNTERSET_INSTANCE _        ' __in PPERF_COUNTERSET_INSTANCE pInstance
 , BYVAL CounterId AS DWORD _                           ' __in ULONG                     CounterId
 , BYVAL llValue AS QUAD _                              ' __in ULONGLONG                 llValue
 ) AS DWORD                                             ' ULONG

DECLARE FUNCTION PerfIncrementULongCounterValue IMPORT "Advapi32.dll" ALIAS "PerfIncrementULongCounterValue" ( _
   BYVAL hProvider AS DWORD _                           ' __in HANDLE                    hProvider
 , BYREF pInstance AS PERF_COUNTERSET_INSTANCE _        ' __in PPERF_COUNTERSET_INSTANCE pInstance
 , BYVAL CounterId AS DWORD _                           ' __in ULONG                     CounterId
 , BYVAL lValue AS DWORD _                              ' __in ULONG                     lValue
 ) AS DWORD                                             ' ULONG

DECLARE FUNCTION PerfIncrementULongLongCounterValue IMPORT "Advapi32.dll" ALIAS "PerfIncrementULongLongCounterValue" ( _
   BYVAL hProvider AS DWORD _                           ' __in HANDLE                    hProvider
 , BYREF pInstance AS PERF_COUNTERSET_INSTANCE _        ' __in PPERF_COUNTERSET_INSTANCE pInstance
 , BYVAL CounterId AS DWORD _                           ' __in ULONG                     CounterId
 , BYVAL llValue AS QUAD _                              ' __in ULONGLONG                 llValue
 ) AS DWORD                                             ' ULONG

DECLARE FUNCTION PerfDecrementULongCounterValue IMPORT "Advapi32.dll" ALIAS "PerfDecrementULongCounterValue" ( _
   BYVAL hProvider AS DWORD _                           ' __in HANDLE                    hProvider
 , BYREF pInstance AS PERF_COUNTERSET_INSTANCE _        ' __in PPERF_COUNTERSET_INSTANCE pInstance
 , BYVAL CounterId AS DWORD _                           ' __in ULONG                     CounterId
 , BYVAL lValue AS DWORD _                              ' __in ULONG                     lValue
 ) AS DWORD                                             ' ULONG

DECLARE FUNCTION PerfDecrementULongLongCounterValue IMPORT "Advapi32.dll" ALIAS "PerfDecrementULongLongCounterValue" ( _
   BYVAL hProvider AS DWORD _                           ' __in HANDLE                    hProvider
 , BYREF pInstance AS PERF_COUNTERSET_INSTANCE _        ' __in PPERF_COUNTERSET_INSTANCE pInstance
 , BYVAL CounterId AS DWORD _                           ' __in ULONG                     CounterId
 , BYVAL llValue AS QUAD _                              ' __in ULONGLONG                 llValue
 ) AS DWORD                                             ' ULONG
