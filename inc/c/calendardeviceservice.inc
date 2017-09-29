' ########################################################################################
' Microsoft Windows
' File: CalendarDeviceService.inc
' Contents: Contains declarations for the Calendar Device Service
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%CALENDARDEVICESERVICE_INC = 1

#INCLUDE ONCE "DeviceServices.inc"
#INCLUDE ONCE "MessageDeviceService.inc"
#INCLUDE ONCE "SyncDeviceService.inc"

'/*****************************************************************************/
'/*  Calendar Service Info                                                    */
'/*****************************************************************************/

'DEFINE_DEVSVCGUID(SERVICE_Calendar,
'    0xE4DFDBD3, 0x7F04, 0x45E9, 0x9F, 0xA1, 0x5C, 0xA0, 0xEA, 0xEB, 0x0A, 0xE3);
$SERVICE_Calendar = GUID$("{E4DFDBD3-7F04-45E9-9FA1-5CA0EAEB0AE3}")

$$NAME_CalendarSvc                   = "Calendar"$$
%TYPE_CalendarSvc                    = %DEVSVCTYPE_DEFAULT


'/*****************************************************************************/
'/*  Calendar Service Properties                                              */
'/*****************************************************************************/

'DEFINE_DEVSVCGUID(NAMESPACE_CalendarSvc,
'    0x63816297, 0x61E5, 0x4306, 0xB1, 0xA3, 0xCE, 0xDF, 0x48, 0x1B, 0x86, 0x29);
$NAMESPACE_CalendarSvc = GUID$("{63816297-61E5-4306-B1A3-CEDF481B8629}")

'/*  PKEY_CalendarSvc_SyncInWindowOnly
' */

MACRO PKEY_CalendarSvc_SyncInWindowOnly = PKEY_SyncSvc_FilterType
$$NAME_CalendarSvc_SyncInWindowOnly = $$NAME_SyncSvc_FilterType


'/*  PKEY_CalendarSvc_SyncWindowStart
' *
' *  Indicates the number of minutes before TODAY that the sync window starts
' *
' *  Type: UInt32
' *  Form: None
' */

'DEFINE_DEVSVCPROPKEY(PKEY_CalendarSvc_SyncWindowStart,
'    0x63816297, 0x61E5, 0x4306, 0xB1, 0xA3, 0xCE, 0xDF, 0x48, 0x1B, 0x86, 0x29,
'    2);
MACRO PKEY_CalendarSvc_SyncWindowStart = GUID$("{63816297-61E5-4306-B1A3-CEDF481B8629}") & MKDWD$(2)

$$NAME_CalendarSvc_SyncWindowStart    = "SyncWindowStart"$$


'/*  PKEY_CalendarSvc_SyncWindowEnd
' *
' *  Indicates the number of minutes after TODAY that the sync window ends
' *
' *  Type: UInt32
' *  Form: None
' */

'DEFINE_DEVSVCPROPKEY(PKEY_CalendarSvc_SyncWindowEnd,
'    0x63816297, 0x61E5, 0x4306, 0xB1, 0xA3, 0xCE, 0xDF, 0x48, 0x1B, 0x86, 0x29,
'    3);
MACRO PKEY_CalendarSvc_SyncWindowEnd = GUID$("{63816297-61E5-4306-B1A3-CEDF481B8629}") & MKDWD$(3)

$$NAME_CalendarSvc_SyncWindowEnd      = "SyncWindowEnd"$$


'/*****************************************************************************/
'/*  Calendar Service Object Formats                                          */
'/*****************************************************************************/

'/*  FORMAT_AbstractActivity
' */

'DEFINE_DEVSVCGUID(FORMAT_AbstractActivity,
'    0xbf70e114, 0x3901, 0x4449, 0xbe, 0xe7, 0xd9, 0xea, 0x14, 0x93, 0xc3, 0x09);
$FORMAT_AbstractActivity = GUID$("{bf70e114-3901-4449-bee7-d9ea1493c309}")

$$NAME_AbstractActivity               = "AbstractActivity"$$

'/*  FORMAT_AbstractActivityOccurrence
' */

'DEFINE_DEVSVCGUID(FORMAT_AbstractActivityOccurrence,
'    0xE87A7008, 0x32D1, 0x42C5, 0x84, 0x88, 0x4C, 0x23, 0x58, 0x66, 0xAF, 0x32);
$FORMAT_AbstractActivityOccurrence = GUID$("{E87A7008-32D1-42C5-8488-4C235866AF32}")

$$NAME_AbstractActivityOccurrence     = "AbstractActivityOccurrence"$$

'/*  FORMAT_VCalendar1Activity
' */

'DEFINE_DEVSVCGUID(FORMAT_VCalendar1Activity,
'    0x23F7A5A5, 0xF7D3, 0x4585, 0xA1, 0xFF, 0x76, 0xE2, 0xD4, 0x5C, 0x91, 0x21);
$FORMAT_VCalendar1Activity = GUID$("{23F7A5A5-F7D3-4585-A1FF-76E2D45C9121}")
$NAME_VCalendar1Activity             = "VCalendar1"

'/*  FORMAT_ICalendarActivity
' *
' *  iCalendar file format (vCalendar Version 2)
' */

'DEFINE_DEVSVCGUID(FORMAT_ICalendarActivity,
'    0xCC4538CB, 0x7890, 0x41B7, 0xA3, 0xF1, 0xB6, 0xE6, 0x0B, 0xDD, 0x2A, 0x61);
$FORMAT_ICalendarActivity = GUID$("{CC4538CB-7890-41B7-A3F1-B6E60BDD2A61}")
$$NAME_ICalendarActivity              = "ICalendar"$$

'/*****************************************************************************/
'/*  Calendar Service Object Property Keys                                    */
'/*****************************************************************************/

'DEFINE_DEVSVCGUID(NAMESPACE_CalendarObj,
'    0xF99EFD03, 0x431D, 0x40D8, 0xA1, 0xC9, 0x4E, 0x22, 0x0D, 0x9C, 0x88, 0xD3);
$NAMESPACE_CalendarObj = GUID$("{F99EFD03-431D-40D8-A1C9-4E220D9C88D3}")


'/*  CalendarObj.Location
' *
' *  MTP Property: Activity Location (0xDD52)
' *  Type: String/AUInt16
' *  Form: None/LongString
' */

'DEFINE_DEVSVCPROPKEY(PKEY_CalendarObj_Location,
'    0xF99EFD03, 0x431D, 0x40D8, 0xA1, 0xC9, 0x4E, 0x22, 0x0D, 0x9C, 0x88, 0xD3,
'    3);
MACRO PKEY_CalendarObj_Location = GUID$("{F99EFD03-431D-40D8-A1C9-4E220D9C88D3}") & MKDWD$(3)

$$NAME_CalendarObj_Location           = "Location"$$


'/*  CalendarObj.Accepted
' *
' *  MTP Property: Activity Accepted (0xDD57)
' *  Type: AUInt16
' *  Form: LongString
' */

'DEFINE_DEVSVCPROPKEY(PKEY_CalendarObj_Accepted,
'    0xF99EFD03, 0x431D, 0x40D8, 0xA1, 0xC9, 0x4E, 0x22, 0x0D, 0x9C, 0x88, 0xD3,
'    10);
MACRO PKEY_CalendarObj_Accepted = GUID$("{F99EFD03-431D-40D8-A1C9-4E220D9C88D3}") & MKDWD$(10)

$$NAME_CalendarObj_Accepted           = "Accepted"$$


'/*  CalendarObj.Tentative
' *
' *  MTP Property: Activity Tentative (0xDD58)
' *  Type: AUInt16
' *  Form: LongString
' */

'DEFINE_DEVSVCPROPKEY(PKEY_CalendarObj_Tentative,
'    0xF99EFD03, 0x431D, 0x40D8, 0xA1, 0xC9, 0x4E, 0x22, 0x0D, 0x9C, 0x88, 0xD3,
'    12);
MACRO PKEY_CalendarObj_Tentative = GUID$("{F99EFD03-431D-40D8-A1C9-4E220D9C88D3}") & MKDWD$(12)

$$NAME_CalendarObj_Tentative          = "Tentative"$$


'/*  CalendarObj.Declined
' *
' *  MTP Property: Activity Declined (0xDD59)
' *  Type: AUInt16
' *  Form: LongString
' */

'DEFINE_DEVSVCPROPKEY(PKEY_CalendarObj_Declined,
'    0xF99EFD03, 0x431D, 0x40D8, 0xA1, 0xC9, 0x4E, 0x22, 0x0D, 0x9C, 0x88, 0xD3,
'    13);
MACRO PKEY_CalendarObj_Declined = GUID$("{F99EFD03-431D-40D8-A1C9-4E220D9C88D3}") & MKDWD$(13)

$$NAME_CalendarObj_Declined           = "Declined"$$


'/*  CalendarObj.TimeZone
' *
' *  Contains the TZ Database name for the time zone in which the appointment
' *  was created.

' *  Type: String
' *  Form: None
' */

'DEFINE_DEVSVCPROPKEY(PKEY_CalendarObj_TimeZone,
'    0xF99EFD03, 0x431D, 0x40D8, 0xA1, 0xC9, 0x4E, 0x22, 0x0D, 0x9C, 0x88, 0xD3,
'    14);
MACRO PKEY_CalendarObj_TimeZone = GUID$("{F99EFD03-431D-40D8-A1C9-4E220D9C88D3}") & MKDWD$(14)

$$NAME_CalendarObj_TimeZone           = "TimeZone"$$


'/*  CalendarObj.ReminderOffset
' *
' *  Contains the offset in minutes from the start of the appointment that
' *  a reminder is to be fired.
' *
' *  Type: UInt32
' *  Form: None
' */

'DEFINE_DEVSVCPROPKEY(PKEY_CalendarObj_ReminderOffset,
'    0xF99EFD03, 0x431D, 0x40D8, 0xA1, 0xC9, 0x4E, 0x22, 0x0D, 0x9C, 0x88, 0xD3,
'    15);
MACRO PKEY_CalendarObj_ReminderOffset = GUID$("{F99EFD03-431D-40D8-A1C9-4E220D9C88D3}") & MKDWD$(15)

$$NAME_CalendarObj_ReminderOffset     = "ReminderOffset"$$


'/*  CalendarObj.BusyStatus
' *
' *  Contains the free/busy status for the specified appointment.
' *
' *  Type: UInt16
' *  Form: Enum
' */

'DEFINE_DEVSVCPROPKEY(PKEY_CalendarObj_BusyStatus,
'    0xF99EFD03, 0x431D, 0x40D8, 0xA1, 0xC9, 0x4E, 0x22, 0x0D, 0x9C, 0x88, 0xD3,
'    16);
MACRO PKEY_CalendarObj_BusyStatus = GUID$("{F99EFD03-431D-40D8-A1C9-4E220D9C88D3}") & MKDWD$(16)

$$NAME_CalendarObj_BusyStatus         = "BusyStatus"$$

%ENUM_CalendarObj_BusyStatusFree         = &H0000
%ENUM_CalendarObj_BusyStatusBusy         = &H0001
%ENUM_CalendarObj_BusyStatusOutOfOffice  = &H0002
%ENUM_CalendarObj_BusyStatusTentative    = &H0003


'/*  CalendarObj.PatternStartTime
' *
' *  Contains the time of day at which a recurring item is to start.  The
' *  format is the time portion of an ISO 8601 DateTime value- e.g. HHMMSS.S
' *
' *  Type: String
' *  Form: ISO 8601 Time
' */

'DEFINE_DEVSVCPROPKEY(PKEY_CalendarObj_PatternStartTime,
'    0xF99EFD03, 0x431D, 0x40D8, 0xA1, 0xC9, 0x4E, 0x22, 0x0D, 0x9C, 0x88, 0xD3,
'    17);
MACRO PKEY_CalendarObj_PatternStartTime = GUID$("{F99EFD03-431D-40D8-A1C9-4E220D9C88D3}") & MKDWD$(17)

$$NAME_CalendarObj_PatternStartTime   = "PatternStartTime"$$


'/*  CalendarObj.PatternDuration
' *
' *  Contains the duration of the recurring item in minutes.
' *
' *  Type: UInt32
' *  Form: None
' */

'DEFINE_DEVSVCPROPKEY(PKEY_CalendarObj_PatternDuration,
'    0xF99EFD03, 0x431D, 0x40D8, 0xA1, 0xC9, 0x4E, 0x22, 0x0D, 0x9C, 0x88, 0xD3,
'    18);
MACRO PKEY_CalendarObj_PatternDuration = GUID$("{F99EFD03-431D-40D8-A1C9-4E220D9C88D3}") & MKDWD$(18)

$$NAME_CalendarObj_PatternDuration    = "PatternDuration"$$


'/*  CalendarObj.BeginDateTime
' *
' *  Contains the UTC date and time that the calendar item begins
' *
' *  Type: String
' *  Form: DateTime
' */

'DEFINE_DEVSVCPROPKEY(PKEY_CalendarObj_BeginDateTime,
'    0xF99EFD03, 0x431D, 0x40D8, 0xA1, 0xC9, 0x4E, 0x22, 0x0D, 0x9C, 0x88, 0xD3,
'    19);
MACRO PKEY_CalendarObj_BeginDateTime = GUID$("{F99EFD03-431D-40D8-A1C9-4E220D9C88D3}") & MKDWD$(19)

$$NAME_CalendarObj_BeginDateTime      = "BeginDateTime"$$


'/*  CalendarObj.EndDateTime
' *
' *  Contains the UTC date and time that the calendar item ends
' *
' *  Type: String
' *  Form: DateTime
' */

'DEFINE_DEVSVCPROPKEY(PKEY_CalendarObj_EndDateTime,
'    0xF99EFD03, 0x431D, 0x40D8, 0xA1, 0xC9, 0x4E, 0x22, 0x0D, 0x9C, 0x88, 0xD3,
'    20);
MACRO PKEY_CalendarObj_EndDateTime = GUID$("{F99EFD03-431D-40D8-A1C9-4E220D9C88D3}") & MKDWD$(20)

$$NAME_CalendarObj_EndDateTime        = "EndDateTime"$$
