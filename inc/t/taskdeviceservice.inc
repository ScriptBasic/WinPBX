' ########################################################################################
' Microsoft Windows
' File: TaskDeviceService.inc
' Contents: Contains declarations for the Task Device Service
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%TASKDEVICESERVICE_INC = 1

#INCLUDE ONCE "DeviceServices.inc"
#INCLUDE ONCE "MessageDeviceService.inc"
#INCLUDE ONCE "SyncDeviceService.inc"


'/*****************************************************************************/
'/*  Task Service Info                                                        */
'/*****************************************************************************/

$SERVICE_Tasks = GUID$("{BB340C54-B5C6-491D-8827-28D0E7631903}")

$$NAME_TasksSvc                     = "Tasks"$$
%TYPE_TasksSvc                      = %DEVSVCTYPE_DEFAULT


'/*****************************************************************************/
'/*  Task Service Properties                                                  */
'/*****************************************************************************/

MACRO PKEY_TasksSvc_SyncActiveOnly       = PKEY_SyncSvc_FilterType


'/*****************************************************************************/
'/*  Task Service Object Formats                                              */
'/*****************************************************************************/

'/*  FORMAT_AbstractTask
' */

$FORMAT_AbstractTask = GUID$("{522979c0-74cf-44ab-9754-55bc596a67df}")

$$NAME_AbstractTask                  = "AbstractTask"$$


'/*****************************************************************************/
'/*  Task Service Object Property Keys                                        */
'/*****************************************************************************/

$NAMESPACE_TaskObj = GUID$("{E354E95E-D8A0-4637-A03A-0CB26838DBC7}")

'/*  PKEY_TaskObj_ReminderDateTime
' *
' *  Type: String
' *  Form: DateTime
' */

MACRO PKEY_TaskObj_ReminderDateTime = GUID$("{E354E95E-D8A0-4637-A03A-0CB26838DBC7}") & MKDWD$(13)

$$NAME_TaskObj_ReminderDateTime      = "ReminderDateTime"$$


'/*  PKEY_TaskObj_Complete
' *
' *  Type: UInt8
' *  Form: Enum
' */

MACRO PKEY_TaskObj_Complete = GUID$("{E354E95E-D8A0-4637-A03A-0CB26838DBC7}") & MKDWD$(14)

$$NAME_TaskObj_Complete              = "Complete"$$

%ENUM_TaskObj_CompleteFalse          = &H00
%ENUM_TaskObj_CompleteTrue           = &Hff


'/*  TaskObj.BeginDate
' *
' *  Contains the date that the task should start- the date is assumed to
' *  be relative to the current device time zone
' *
' *  Type: String
' *  Form: ISO8601 Date
' */

MACRO PKEY_TaskObj_BeginDate = GUID$("{E354E95E-D8A0-4637-A03A-0CB26838DBC7}") & MKDWD$(15)

$$NAME_TaskObj_BeginDate             = "BeginDate"$$


'/*  TaskObj.EndDate
' *
' *  Contains the date that the task should end- the date is assumed to be
' *  relative to the current device time zone
' *
' *  Type: String
' *  Form: ISO8601 Date
' */

MACRO PKEY_TaskObj_EndDate = GUID$("{E354E95E-D8A0-4637-A03A-0CB26838DBC7}") & MKDWD$(16)

$$NAME_TaskObj_EndDate               = "EndDate"$$
