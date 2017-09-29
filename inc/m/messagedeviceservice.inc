' ########################################################################################
' Microsoft Windows
' File: MessageDeviceService.inc
' Contents: Declarations for the Message Device Service
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%MESSAGEDEVICESERVICE_INC = 1

#INCLUDE ONCE "DeviceServices.inc"

'/*****************************************************************************/
'/*  Message Service Info                                                     */
'/*****************************************************************************/

'DEFINE_DEVSVCGUID(SERVICE_Message,
'    0x29b43bd0, 0x6b16, 0x49af, 0xb7, 0x2e, 0x85, 0x77, 0x0a, 0xdf, 0xeb, 0xdd);
$SERVICE_Message = GUID$("{29b43bd0-6b16-49af-b72e-85770adfebdd}")

$$NAME_MessageSvc                = "Message"$$
%TYPE_MessageSvc                 = %DEVSVCTYPE_DEFAULT


'/*****************************************************************************/
'/*  Message Service Object Formats                                           */
'/*****************************************************************************/

'/*  FORMAT_AbstractMessage
' *
' *  MTP Format: Abstract Message (0xBB01)
' *  Suggested MIME Type:
' */

'DEFINE_DEVSVCGUID(FORMAT_AbstractMessage,
'    0xBB010000, 0xAE6C, 0x4804, 0x98, 0xBA, 0xC5, 0x7B, 0x46, 0x96, 0x5F, 0xE7);
$FORMAT_AbstractMessage = GUID$("{BB010000-AE6C-4804-98BA-C57B46965FE7}")

$$NAME_AbstractMessage           = "AbstractMessage"$$


'/*  FORMAT_AbstractMessageFolder
' *
' *  MTP Format: Abstract Message Folder (0xBA07)
' *  Suggested MIME Type:
' */

'DEFINE_DEVSVCGUID(FORMAT_AbstractMessageFolder,
'    0xBA070000, 0xAE6C, 0x4804, 0x98, 0xBA, 0xC5, 0x7B, 0x46, 0x96, 0x5F, 0xE7);
$FORMAT_AbstractMessageFolder = GUID$("{BA070000-AE6C-4804-98BA-C57B46965FE7}")

$$NAME_AbstractMessageFolder         = "AbstractMessageFolder"$$


'/*****************************************************************************/
'/*  Message Service Object Property Keys                                     */
'/*****************************************************************************/

'DEFINE_DEVSVCGUID(MESSAGESVC_OBJECT_PROPERTIES,
'    0xB28AE94B, 0x05A4, 0x4E8E, 0xBE, 0x01, 0x72, 0xCC, 0x7E, 0x09, 0x9D, 0x8F);
$MESSAGESVC_OBJECT_PROPERTIES = GUID$("{B28AE94B-05A4-4E8E-BE01-72CC7E099D8F}")

'/*  MessageObj.Subject
' *
' *  MTP Property: Subject (0xDCE2)
' *  Type: String/AUInt16
' *  Form: None/LongString
' */

'DEFINE_DEVSVCPROPKEY(PKEY_MessageObj_Subject,
'    0xB28AE94B, 0x05A4, 0x4E8E, 0xBE, 0x01, 0x72, 0xCC, 0x7E, 0x09, 0x9D, 0x8F,
'    2);
MACRO PKEY_MessageObj_Subject = GUID$("{B28AE94B-05A4-4E8E-BE01-72CC7E099D8F}") & MKDWD$(2)

$$NAME_MessageObj_Subject            = "Subject"$$


'/*  MessageObj.Body
' *
' *  MTP Property: Body Text (0xDCE1)
' *  Type: AUInt16
' *  Form: LongString
' */

'DEFINE_DEVSVCPROPKEY(PKEY_MessageObj_Body,
'    0xB28AE94B, 0x05A4, 0x4E8E, 0xBE, 0x01, 0x72, 0xCC, 0x7E, 0x09, 0x9D, 0x8F,
'    3);
MACRO PKEY_MessageObj_Body = GUID$("{B28AE94B-05A4-4E8E-BE01-72CC7E099D8F}") & MKDWD$(3)

$$NAME_MessageObj_Body               = "Body"$$


'/*  MessageObj.Priority
' *
' *  Type: UInt16
' *  Form: Enum
' */

'DEFINE_DEVSVCPROPKEY(PKEY_MessageObj_Priority,
'    0xB28AE94B, 0x05A4, 0x4E8E, 0xBE, 0x01, 0x72, 0xCC, 0x7E, 0x09, 0x9D, 0x8F,
'    4);
MACRO PKEY_MessageObj_Priority = GUID$("{B28AE94B-05A4-4E8E-BE01-72CC7E099D8F}") & MKDWD$(4)

$$NAME_MessageObj_Priority           = "Priority"$$

%ENUM_MessageObj_PriorityHighest = 2
%ENUM_MessageObj_PriorityNormal  = 1
%ENUM_MessageObj_PriorityLowest  = 0


'/*  MessageObj.Category
' *
' *  MTP Property:  ()
' *  Type: String/AUInt16
' *  Form: None/LongString
' */

'DEFINE_DEVSVCPROPKEY(PKEY_MessageObj_Category,
'    0xB28AE94B, 0x05A4, 0x4E8E, 0xBE, 0x01, 0x72, 0xCC, 0x7E, 0x09, 0x9D, 0x8F,
'    10);
MACRO PKEY_MessageObj_Category = GUID$("{B28AE94B-05A4-4E8E-BE01-72CC7E099D8F}") & MKDWD$(10)

$$NAME_MessageObj_Category           = "Category"$$


'/*  MessageObj.Sender
' *
' *  MTP Property: Message Sender (0xDD45)
' *  Type: String/AUInt16
' *  Form: None/LongString
' */

'DEFINE_DEVSVCPROPKEY(PKEY_MessageObj_Sender,
'    0xB28AE94B, 0x05A4, 0x4E8E, 0xBE, 0x01, 0x72, 0xCC, 0x7E, 0x09, 0x9D, 0x8F,
'    18);
MACRO PKEY_MessageObj_Sender = GUID$("{B28AE94B-05A4-4E8E-BE01-72CC7E099D8F}") & MKDWD$(18)

$$NAME_MessageObj_Sender             = "Sender"$$


'/*  MessageObj.To
' *
' *  MTP Property: Message To (0xDD40)
' *  Type: AUInt16
' *  Form: LongString
' */

'DEFINE_DEVSVCPROPKEY(PKEY_MessageObj_To,
'    0xB28AE94B, 0x05A4, 0x4E8E, 0xBE, 0x01, 0x72, 0xCC, 0x7E, 0x09, 0x9D, 0x8F,
'    20);
MACRO PKEY_MessageObj_To = GUID$("{B28AE94B-05A4-4E8E-BE01-72CC7E099D8F}") & MKDWD$(20)

$$NAME_MessageObj_To                 = "To"$$


'/*  MessageObj.CC
' *
' *  MTP Property: Message CC (0xDD41)
' *  Type: AUInt16
' *  Form: LongString
' */

'DEFINE_DEVSVCPROPKEY(PKEY_MessageObj_CC,
'    0xB28AE94B, 0x05A4, 0x4E8E, 0xBE, 0x01, 0x72, 0xCC, 0x7E, 0x09, 0x9D, 0x8F,
'    21);
MACRO PKEY_MessageObj_CC = GUID$("{B28AE94B-05A4-4E8E-BE01-72CC7E099D8F}") & MKDWD$(21)

$$NAME_MessageObj_CC                 = "CC"$$


'/*  MessageObj.BCC
' *
' *  MTP Property: Message BCC (0xDD42)
' *  Type: AUInt16
' *  Form: LongString
' */

'DEFINE_DEVSVCPROPKEY(PKEY_MessageObj_BCC,
'    0xB28AE94B, 0x05A4, 0x4E8E, 0xBE, 0x01, 0x72, 0xCC, 0x7E, 0x09, 0x9D, 0x8F,
'    22);
MACRO PKEY_MessageObj_BCC = GUID$("{B28AE94B-05A4-4E8E-BE01-72CC7E099D8F}") & MKDWD$(22)

$$NAME_MessageObj_BCC                = "BCC"$$


'/*  MessageObj.Read
' *
' *  MTP Property: Message Read (0xDD43)
' *  Type: UInt16
' *  Form: Enum
' */

'DEFINE_DEVSVCPROPKEY(PKEY_MessageObj_Read,
'    0xB28AE94B, 0x05A4, 0x4E8E, 0xBE, 0x01, 0x72, 0xCC, 0x7E, 0x09, 0x9D, 0x8F,
'    23);
MACRO PKEY_MessageObj_Read = GUID$("{B28AE94B-05A4-4E8E-BE01-72CC7E099D8F}") & MKDWD$(23)

$$NAME_MessageObj_Read               = "Read"$$

%ENUM_MessageObj_ReadFalse           = &H00
%ENUM_MessageObj_ReadTrue            = &Hff


'/*  MessageObj.ReceivedTime
' *
' *  MTP Property: Message Received Time (0xDD44)
' *  Type: String
' *  Form: DateTime
' */

'DEFINE_DEVSVCPROPKEY(PKEY_MessageObj_ReceivedTime,
'    0xB28AE94B, 0x05A4, 0x4E8E, 0xBE, 0x01, 0x72, 0xCC, 0x7E, 0x09, 0x9D, 0x8F,
'    24);
MACRO PKEY_MessageObj_ReceivedTime = GUID$("{B28AE94B-05A4-4E8E-BE01-72CC7E099D8F}") & MKDWD$(24)

$$NAME_MessageObj_ReceivedTime       = "ReceivedTime"$$


'/*  MessageObj.PatternOriginalDateTime
' *
' *  Contains the original UTC time that a recurring item was to take place.
' *
' *  Type: String
' *  Form: DateTime
' */

'DEFINE_DEVSVCPROPKEY(PKEY_MessageObj_PatternOriginalDateTime,
'    0xB28AE94B, 0x05A4, 0x4E8E, 0xBE, 0x01, 0x72, 0xCC, 0x7E, 0x09, 0x9D, 0x8F,
'    26);
MACRO PKEY_MessageObj_PatternOriginalDateTime = GUID$("{B28AE94B-05A4-4E8E-BE01-72CC7E099D8F}") & MKDWD$(26)

$$NAME_MessageObj_PatternOriginalDateTime = "PatternOriginalDateTime"$$


'/*  MessageObj.PatternType
' *
' *  Contains the pattern type of the recurring item.
' *
' *  Type: UInt32
' *  Form: Enum
' */

'DEFINE_DEVSVCPROPKEY(PKEY_MessageObj_PatternType,
'    0xB28AE94B, 0x05A4, 0x4E8E, 0xBE, 0x01, 0x72, 0xCC, 0x7E, 0x09, 0x9D, 0x8F,
'    27);
MACRO PKEY_MessageObj_PatternType = GUID$("{B28AE94B-05A4-4E8E-BE01-72CC7E099D8F}") & MKDWD$(27)

$$NAME_MessageObj_PatternType        = "PatternType"$$

%ENUM_MessageObj_PatternTypeDaily    = &H00000001???
%ENUM_MessageObj_PatternTypeWeekly   = &H00000002???
%ENUM_MessageObj_PatternTypeMonthly  = &H00000003???
%ENUM_MessageObj_PatternTypeYearly   = &H00000004???


'/*  MessageObj.PatternValidStartDate
' *
' *  Contains the first date on which the recurrence pattern is valid.  The
' *  first instance of the recurring item is on or after this date.  The date
' *  is in the time reference of the recurring item.
' *
' *  Type: String
' *  Form: ISO 8601 Date
' */

'DEFINE_DEVSVCPROPKEY(PKEY_MessageObj_PatternValidStartDate,
'    0xB28AE94B, 0x05A4, 0x4E8E, 0xBE, 0x01, 0x72, 0xCC, 0x7E, 0x09, 0x9D, 0x8F,
'    28);
MACRO PKEY_MessageObj_PatternValidStartDate = GUID$("{B28AE94B-05A4-4E8E-BE01-72CC7E099D8F}") & MKDWD$(28)

$$NAME_MessageObj_PatternValidStartDate  = "PatternValidStartDate"$$


'/*  MessageObj.PatternValidEndDate
' *
' *  Contains the last date on which the recurrence pattern is valid.  The
' *  last instance of the recurring item is on or before this date.  The date
' *  is in the time reference of the recurring item.
' *
' *  Type: String
' *  Form: ISO 8601 Date
' */

'DEFINE_DEVSVCPROPKEY(PKEY_MessageObj_PatternValidEndDate,
'    0xB28AE94B, 0x05A4, 0x4E8E, 0xBE, 0x01, 0x72, 0xCC, 0x7E, 0x09, 0x9D, 0x8F,
'    29);
MACRO PKEY_MessageObj_PatternValidEndDate = GUID$("{B28AE94B-05A4-4E8E-BE01-72CC7E099D8F}") & MKDWD$(29)

$$NAME_MessageObj_PatternValidEndDate = "PatternValidEndDate"$$


'/*  MessageObj.PatternPeriod
' *
' *  Contains the period of the repeating recurrence pattern.  The units of this
' *  property are determined by the value of MessageObj.PatternType.
' *
' *  Type: UInt32
' *  Form: None
' */

'DEFINE_DEVSVCPROPKEY(PKEY_MessageObj_PatternPeriod,
'    0xB28AE94B, 0x05A4, 0x4E8E, 0xBE, 0x01, 0x72, 0xCC, 0x7E, 0x09, 0x9D, 0x8F,
'    31);
MACRO PKEY_MessageObj_PatternPeriod = GUID$("{B28AE94B-05A4-4E8E-BE01-72CC7E099D8F}") & MKDWD$(31)

$$NAME_MessageObj_PatternPeriod      = "PatternPeriod"$$


'/*  MessageObj.PatternDayOfWeek
' *
' *  Contains the day of week mask for weekly, monthly, and yearly recurrence
' *  patterns.
' *
' *  Type: UInt16
' *  Form: None
' */

'DEFINE_DEVSVCPROPKEY(PKEY_MessageObj_PatternDayOfWeek,
'    0xB28AE94B, 0x05A4, 0x4E8E, 0xBE, 0x01, 0x72, 0xCC, 0x7E, 0x09, 0x9D, 0x8F,
'    32);
MACRO PKEY_MessageObj_PatternDayOfWeek = GUID$("{B28AE94B-05A4-4E8E-BE01-72CC7E099D8F}") & MKDWD$(32)

$$NAME_MessageObj_PatternDayOfWeek   = "PatternDayOfWeek"$$

%FLAG_MessageObj_DayOfWeekNone       = &H0000???
%FLAG_MessageObj_DayOfWeekSunday     = &H0001???
%FLAG_MessageObj_DayOfWeekMonday     = &H0002???
%FLAG_MessageObj_DayOfWeekTuesday    = &H0004???
%FLAG_MessageObj_DayOfWeekWednesday  = &H0008???
%FLAG_MessageObj_DayOfWeekThursday   = &H0010???
%FLAG_MessageObj_DayOfWeekFriday     = &H0020???
%FLAG_MessageObj_DayOfWeekSaturday   = &H0040???


'/*  MessageObj.PatternDayOfMonth
' *
' *  Contains the day of the month for monthly and yearly recurrence patterns.
' *  If day specified is greater than the number of days in the month the
' *  value is interpreted as the last valid day of the month.
' *
' *  Type: UInt8
' *  Form: Range
' */

'DEFINE_DEVSVCPROPKEY(PKEY_MessageObj_PatternDayOfMonth,
'    0xB28AE94B, 0x05A4, 0x4E8E, 0xBE, 0x01, 0x72, 0xCC, 0x7E, 0x09, 0x9D, 0x8F,
'    33);
MACRO PKEY_MessageObj_PatternDayOfMonth = GUID$("{B28AE94B-05A4-4E8E-BE01-72CC7E099D8F}") & MKDWD$(33)

$$NAME_MessageObj_PatternDayOfMonth  = "PatternDayOfMonth"$$

%RANGEMIN_MessageObj_PatternDayOfMonth  = 1
%RANGEMAX_MessageObj_PatternDayOfMonth  = 31
%RANGESTEP_MessageObj_PatternDayOfMonth = 1

'/*  MessageObj.PatternMonthOfYear
' *
' *  Contains the month of the year for yearly recurrence patterns.
' *
' *  Type: UInt8
' *  Form: Range
' */

'DEFINE_DEVSVCPROPKEY(PKEY_MessageObj_PatternMonthOfYear,
'    0xB28AE94B, 0x05A4, 0x4E8E, 0xBE, 0x01, 0x72, 0xCC, 0x7E, 0x09, 0x9D, 0x8F,
'    34);
MACRO PKEY_MessageObj_PatternMonthOfYear = GUID$("{B28AE94B-05A4-4E8E-BE01-72CC7E099D8F}") & MKDWD$(34)

$$NAME_MessageObj_PatternMonthOfYear = "PatternMonthOfYear"$$

%RANGEMIN_MessageObj_PatternMonthOfYear  = 1
%RANGEMAX_MessageObj_PatternMonthOfYear  = 12
%RANGESTEP_MessageObj_PatternMonthOfYear = 1


'/*  MessageObj.PatternInstance
' *
' *  Contains the instance of the recurring pattern that is to be matched.
' *
' *  Type: UInt8
' *  Form: Enum
' */

'DEFINE_DEVSVCPROPKEY(PKEY_MessageObj_PatternInstance,
'    0xB28AE94B, 0x05A4, 0x4E8E, 0xBE, 0x01, 0x72, 0xCC, 0x7E, 0x09, 0x9D, 0x8F,
'    35);
MACRO PKEY_MessageObj_PatternInstance = GUID$("{B28AE94B-05A4-4E8E-BE01-72CC7E099D8F}") & MKDWD$(35)

$$NAME_MessageObj_PatternInstance    = "PatternInstance"$$

%ENUM_MessageObj_PatternInstanceNone     = &H00
%ENUM_MessageObj_PatternInstanceFirst    = &H01
%ENUM_MessageObj_PatternInstanceSecond   = &H02
%ENUM_MessageObj_PatternInstanceThird    = &H03
%ENUM_MessageObj_PatternInstanceFourth   = &H04
%ENUM_MessageObj_PatternInstanceLast     = &H05


'/*  MessageObj.PatternDeleteDates
' *
' *  Contains a semi-colon separated list of the the dates on which instances
' *  of the recurring item have been deleted.  Does not contain the original
' *  dates for items which have been moved.  The date specified is in the
' *  time reference of the recurrence.
' *
' *  Type: AUInt16
' *  Form: LongString
' */

'DEFINE_DEVSVCPROPKEY(PKEY_MessageObj_PatternDeleteDates,
'    0xB28AE94B, 0x05A4, 0x4E8E, 0xBE, 0x01, 0x72, 0xCC, 0x7E, 0x09, 0x9D, 0x8F,
'    36);
MACRO PKEY_MessageObj_PatternDeleteDates = GUID$("{B28AE94B-05A4-4E8E-BE01-72CC7E099D8F}") & MKDWD$(36)

$$NAME_MessageObj_PatternDeleteDates = "PatternDeleteDates"$$
