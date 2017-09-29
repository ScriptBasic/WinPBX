' ########################################################################################
' Microsoft Windows
' File: LMat.inc
' Contents: Structures, function prototypes, and definitions for the schedule service API-s
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%LMAT_INC = 1

#INCLUDE ONCE "lmcons.inc"

'//
'//  The following bits are used with Flags field in structures below.
'//

'//
'//  Do we exec programs for this job periodically (/EVERY switch)
'//  or one time (/NEXT switch).
'//

%JOB_RUN_PERIODICALLY            = &H01?   ' //  set if EVERY


'//
'//  Was there an error last time we tried to exec a program on behalf of
'//  this job.
'//  This flag is meaningfull on output only!
'//

%JOB_EXEC_ERROR                  = &H02?   ' //  set if error

'//
'//  Will this job run today or tomorrow.
'//  This flag is meaningfull on output only!
'//

%JOB_RUNS_TODAY                  = &H04?   ' //  set if today

'//
'//  Add current day of the month to DaysOfMonth input.
'//  This flag is meaningfull on input only!
'//

%JOB_ADD_CURRENT_DATE            = &H08?   ' // set if to add current date

'//
'//  Will this job be run interactively or not.  Windows NT 3.1 do not
'//  know about this bit, i.e. they submit interactive jobs only.
'//

%JOB_NONINTERACTIVE              = &H10?   ' // set for noninteractive


%JOB_INPUT_FLAGS     =  %JOB_RUN_PERIODICALLY OR _
                        %JOB_ADD_CURRENT_DATE OR _
                        %JOB_NONINTERACTIVE

%JOB_OUTPUT_FLAGS    =  %JOB_RUN_PERIODICALLY OR _
                        %JOB_EXEC_ERROR OR _
                        %JOB_RUNS_TODAY OR _
                        %JOB_NONINTERACTIVE


' // Size = 16 bytes
TYPE AT_INFO DWORD FILL
   JobTime     AS DWORD          ' DWORD_PTR
   DaysOfMonth AS DWORD          ' DWORD
   DaysOfWeek  AS BYTE           ' UCHAR
   Flags       AS BYTE           ' UCHAR
   Command     AS WSTRINGZ PTR   ' LPWSTR
END TYPE

' // Size = 20 bytes
TYPE AT_ENUM DWORD FILL
   JobId       AS DWORD          ' DWORD
   JobTime     AS DWORD          ' DWORD_PTR
   DaysOfMonth AS DWORD          ' DWORD
   DaysOfWeek  AS BYTE           ' UCHAR
   Flags       AS BYTE           ' UCHAR
   Command     AS WSTRINGZ PTR   ' LPWSTR
END TYPE

DECLARE FUNCTION NetScheduleJobAdd IMPORT "NETAPI32.DLL" ALIAS "NetScheduleJobAdd" ( _
   BYREF Servername AS WSTRINGZ _                       ' __in  LPCWSTR Servername OPTIONAL
 , BYREF Buffer AS ANY _                                ' __in  LPBYTE  Buffer
 , BYREF JobId AS DWORD _                               ' __out LPDWORD JobId
 ) AS DWORD                                             ' NET_API_STATUS

DECLARE FUNCTION NetScheduleJobDel IMPORT "NETAPI32.DLL" ALIAS "NetScheduleJobDel" ( _
   BYREF Servername AS WSTRINGZ _                       ' __in  LPCWSTR Servername OPTIONAL
 , BYVAL MinJobId AS DWORD _                            ' __in  DWORD   MinJobId
 , BYVAL MaxJobId AS DWORD _                            ' __in  DWORD   MaxJobId
 ) AS DWORD                                             ' NET_API_STATUS

DECLARE FUNCTION NetScheduleJobEnum IMPORT "NETAPI32.DLL" ALIAS "NetScheduleJobEnum" ( _
   BYREF Servername AS WSTRINGZ _                       ' __in     LPCWSTR  Servername OPTIONAL
 , BYREF PointerToBuffer AS ANY _                       ' __out    LPBYTE * PointerToBuffer
 , BYVAL PrefferedMaximumLength AS DWORD _              ' __in     DWORD    PrefferedMaximumLength
 , BYREF EntriesRead AS DWORD _                         ' __out    LPDWORD  EntriesRead
 , BYREF TotalEntries AS DWORD _                        ' __out    LPDWORD  TotalEntries
 , BYREF ResumeHandle AS DWORD _                        ' __in_out LPDWORD  ResumeHandle
 ) AS DWORD                                             ' NET_API_STATUS

DECLARE FUNCTION NetScheduleJobGetInfo IMPORT "NETAPI32.DLL" ALIAS "NetScheduleJobGetInfo" ( _
   BYREF Servername AS WSTRINGZ _                       ' __in  LPCWSTR  Servername OPTIONAL
 , BYVAL JobId AS DWORD _                               ' __in  DWORD    JobId
 , BYREF PointerToBuffer AS ANY _                       ' __out LPBYTE * PointerToBuffer
 ) AS DWORD                                             ' NET_API_STATUS
