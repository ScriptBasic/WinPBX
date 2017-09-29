' ########################################################################################
' Microsoft Windows
' File: schedule.inc
' Contents: This file defines a common schedule structure for use by various NT components.
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%SCHEDULE_INC = 1

'//
'// The DS and FRS use the same structure to represent different schedules.
'// The DS uses a 15-minute polling schedule. FRS uses a 60-minute
'// start/stop schedule. Hence, the schedule for the system volume is
'// a special case because we only have the DS schedule to work from.
'// We will work around this problem by treating the 15
'// -minute polling schedule as a 60-minute start/stop schedule.
'// Replication is enabled for any hour that has any of the four
'// 15-minute bits set.
'//
'// When the ReplicationSchedule is not present the default is
'// "always replicate."
'//

'//
'// Only the interval schedule is currently implemented. Others are ignored.
'//
%SCHEDULE_INTERVAL      = 0   ' // schedule as understood by NT5
%SCHEDULE_BANDWIDTH     = 1   ' // bandwidth as understood by NT5
%SCHEDULE_PRIORITY      = 2   ' // priority as understood by NT5

'//
'// Schedule Header
'//
'// Each schedule blob begins with n array of schedule headers that
'// specify the number and type of schedules contained in the blob.
'//
' // Size = 8 bytes
TYPE SCHEDULE_HEADER DWORD
   Type   AS DWORD   ' ULONG // one of the SCHEDULE_ ordinals
   Offset AS DWORD   ' ULONG // offset from start of schedule structure
END TYPE

'//
'// Schedule
'//
' // Size = 20 bytes
TYPE SCHEDULE DWORD
   Size              AS DWORD   ' ULONG // inclusive size in bytes
   Bandwidth         AS DWORD   ' ULONG
   NumberOfSchedules AS DWORD   ' ULONG
   Schedules(0)      AS SCHEDULE_HEADER
END TYPE

'// The above structure is followed by the Data buffer and the
'// SCHEDULE_HEADER contains offsets to refer to the appropriate
'// parts in the data buffer.

%SCHEDULE_DATA_ENTRIES = (7 * 24)   ' // 7 days X 24 hours
