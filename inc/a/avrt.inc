' ########################################################################################
' Microsoft Windows
' File: avrt.inc
' Contents: Multimedia class scheduler APIs
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%AVRT_INC = 1

'//
'// AvRt Priorities
'//

' enum _AVRT_PRIORITY
MACRO AVRT_PRIORITY_ENUM = LONG
%AVRT_PRIORITY_LOW      = -1
%AVRT_PRIORITY_NORMAL   = 0
%AVRT_PRIORITY_HIGH     = 1
%AVRT_PRIORITY_CRITICAL = 2

'//
'//  Infinite timeout for a thread order group.
'//

%THREAD_ORDER_GROUP_INFINITE_TIMEOUT = -1&&   ' (-1I64)

DECLARE FUNCTION AvSetMmThreadCharacteristicsA IMPORT "AVRT.DLL" ALIAS "AvSetMmThreadCharacteristicsA" ( _
   BYREF TaskName AS ASCIIZ _                           ' __in LPCSTR TaskName
 , BYREF TaskIndex AS DWORD _                           ' __inout LPDWORD TaskIndex
 ) AS DWORD                                             ' HANDLE

DECLARE FUNCTION AvSetMmThreadCharacteristicsW IMPORT "AVRT.DLL" ALIAS "AvSetMmThreadCharacteristicsW" ( _
   BYREF TaskName AS WSTRINGZ _                         ' __in LPCWSTR TaskName
 , BYREF TaskIndex AS DWORD _                           ' __inout LPDWORD TaskIndex
 ) AS DWORD                                             ' HANDLE

#IF %DEF(%UNICODE)
MACRO AvSetMmThreadCharacteristics = AvSetMmThreadCharacteristicsW
#ELSE
MACRO AvSetMmThreadCharacteristics = AvSetMmThreadCharacteristicsA
#ENDIF

DECLARE FUNCTION AvSetMmMaxThreadCharacteristicsA IMPORT "AVRT.DLL" ALIAS "AvSetMmMaxThreadCharacteristicsA" ( _
   BYREF FirstTask AS ASCIIZ _                          ' __in LPCSTR FirstTask
 , BYREF SecondTask AS ASCIIZ _                         ' __in LPCSTR SecondTask
 , BYREF TaskIndex AS DWORD _                           ' __inout LPDWORD TaskIndex
 ) AS DWORD                                             ' HANDLE

DECLARE FUNCTION AvSetMmMaxThreadCharacteristicsW IMPORT "AVRT.DLL" ALIAS "AvSetMmMaxThreadCharacteristicsW" ( _
   BYREF FirstTask AS WSTRINGZ _                        ' __in LPCWSTR FirstTask
 , BYREF SecondTask AS WSTRINGZ _                       ' __in LPCWSTR SecondTask
 , BYREF TaskIndex AS DWORD _                           ' __inout LPDWORD TaskIndex
 ) AS DWORD                                             ' HANDLE

#IF %DEF(%UNICODE)
MACRO AvSetMmMaxThreadCharacteristics = AvSetMmMaxThreadCharacteristicsW
#ELSE
MACRO AvSetMmMaxThreadCharacteristics = AvSetMmMaxThreadCharacteristicsA
#ENDIF

DECLARE FUNCTION AvRevertMmThreadCharacteristics IMPORT "AVRT.DLL" ALIAS "AvRevertMmThreadCharacteristics" ( _
   BYVAL AvrtHandle AS DWORD _                          ' __in HANDLE AvrtHandle
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION AvSetMmThreadPriority IMPORT "AVRT.DLL" ALIAS "AvSetMmThreadPriority" ( _
   BYVAL AvrtHandle AS DWORD _                          ' __in HANDLE AvrtHandle
 , BYVAL Priority AS AVRT_PRIORITY_ENUM _               ' __in AVRT_PRIORITY Priority
 ) AS LONG                                              ' BOOL

' The Period and Timeout parameters have been declared AS ANY to allow the use of
' a LARGE_INTEGER structure of a QUAD variable.
DECLARE FUNCTION AvRtCreateThreadOrderingGroup IMPORT "AVRT.DLL" ALIAS "AvRtCreateThreadOrderingGroup" ( _
   BYREF Context AS DWORD _                             ' __out PHANDLE Context
 , BYREF Period AS ANY _                                ' __in PLARGE_INTEGER Period
 , BYREF ThreadOrderingGuid AS GUID _                   ' __inout GUID *ThreadOrderingGuid
 , OPTIONAL BYREF Timeout AS ANY _                      ' __in_opt PLARGE_INTEGER Timeout
 ) AS LONG                                              ' BOOL

' The Period and Timeout parameters have been declared AS ANY to allow the use of
' a LARGE_INTEGER structure of a QUAD variable.
DECLARE FUNCTION AvRtCreateThreadOrderingGroupExA IMPORT "AVRT.DLL" ALIAS "AvRtCreateThreadOrderingGroupExA" ( _
   BYREF Context AS DWORD _                             ' __out PHANDLE Context
 , BYREF Period AS ANY _                                ' __in PLARGE_INTEGER Period
 , BYREF ThreadOrderingGuid AS GUID _                   ' __inout GUID *ThreadOrderingGuid
 , BYREF Timeout AS ANY _                               ' __in_opt PLARGE_INTEGER Timeout
 , BYREF TaskName AS ASCIIZ _                           ' __in LPCSTR TaskName
 ) AS LONG                                              ' BOOL

' The Period and Timeout parameters have been declared AS ANY to allow the use of
' a LARGE_INTEGER structure of a QUAD variable.
DECLARE FUNCTION AvRtCreateThreadOrderingGroupExW IMPORT "AVRT.DLL" ALIAS "AvRtCreateThreadOrderingGroupExW" ( _
   BYREF Context AS DWORD _                             ' __out PHANDLE Context
 , BYREF Period AS ANY _                                ' __in PLARGE_INTEGER Period
 , BYREF ThreadOrderingGuid AS GUID _                   ' __inout GUID *ThreadOrderingGuid
 , BYREF Timeout AS ANY _                               ' __in_opt PLARGE_INTEGER Timeout
 , BYREF TaskName AS WSTRINGZ _                         ' __in LPCWSTR TaskName
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
MACRO AvRtCreateThreadOrderingGroupEx = AvRtCreateThreadOrderingGroupExW
#ELSE
MACRO AvRtCreateThreadOrderingGroupEx = AvRtCreateThreadOrderingGroupExA
#ENDIF

DECLARE FUNCTION AvRtJoinThreadOrderingGroup IMPORT "AVRT.DLL" ALIAS "AvRtJoinThreadOrderingGroup" ( _
   BYREF Context AS DWORD _                             ' __out PHANDLE Context
 , BYREF ThreadOrderingGuid AS GUID _                   ' __in GUID *ThreadOrderingGuid
 , BYVAL Before AS LONG _                               ' __in BOOL Before
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION AvRtWaitOnThreadOrderingGroup IMPORT "AVRT.DLL" ALIAS "AvRtWaitOnThreadOrderingGroup" ( _
   BYVAL Context AS DWORD _                             ' __in HANDLE Context
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION AvRtLeaveThreadOrderingGroup IMPORT "AVRT.DLL" ALIAS "AvRtLeaveThreadOrderingGroup" ( _
   BYVAL Context AS DWORD _                             ' __in HANDLE Context
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION AvRtDeleteThreadOrderingGroup IMPORT "AVRT.DLL" ALIAS "AvRtDeleteThreadOrderingGroup" ( _
   BYVAL Context AS DWORD _                             ' __in HANDLE Context
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION AvQuerySystemResponsiveness IMPORT "AVRT.DLL" ALIAS "AvQuerySystemResponsiveness" ( _
   BYVAL AvrtHandle AS DWORD _                          ' __in HANDLE AvrtHandle
 , BYREF SystemResponsivenessValue AS DWORD _           ' __out PULONG SystemResponsivenessValue
 ) AS LONG                                              ' BOOL
