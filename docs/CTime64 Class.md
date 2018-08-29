# CTime64 Class

Represents an absolute time and date. **CTime64** values are based on coordinated universal time (UTC), which is equivalent to Coordinated Universal time (Greenwich Mean Time, GMT).

A companion class, CTimeSpan, represents a time interval.

The upper date limit is 12/31/3000. The lower limit is 1/1/1970 12:00:00 AM GMT.

**Include file**: CTime64.inc

| Name       | Description |
| ---------- | ----------- |
| [Constructors](#Constructors1) | Create new **CTime64** objects initialized to the specified value. |
| [CAST Operator](#CastOp1) | Returns the **CTime64** value as a long integer. |
| [LET Operator](#LetOp1) | Assigns a value to a **CTime64** object. |
| [Operators](#Operators1) | Adds, subtracts or compares **CTime64** objects. |
| [Format](#Format) | Converts a **CTime64** object to a string. |
| [GetAsFileTime](#GetAsFileTime) | Returns the time as a **FILETIME** structure. |
| [GetAsSystemTime](#GetAsSystemTime) | Returns the time as a **SYSTEMTIME** structure. |
| [GetCurrentTime](#GetCurrentTime) | Returns a **CTime64** object that represents the current system date and time. |
| [GetDay](#GetDay) | Returns the day represented by the **CTime64** object. |
| [GetDayOfWeek](#GetDayOfWeek) | Returns the day of the week represented by the **CTime64** object. |
| [GetGmtTime](#GetGmtTime) | Gets a **tm** structure that contains a decomposition of the time contained in this **CTime64** object. |
| [GetHour](#GetHour) | Returns the hour represented by the **CTime64** object. |
| [GetLocalTime](#GetLocalTime) | Gets a **tm** structure that contains a decomposition of the time contained in this **CTime64** object. |
| [GetMinute](#GetMinute) | Returns the minute represented by the **CTime64** object. |
| [GetMonth](#GetMonth) | Returns the month represented by the **CTime64** object. |
| [GetSecond](#GetSecond) | Returns the second represented by the **CTime64** object. |
| [GetTime](#GetTime) | Returns a \_\_time64_t (LONGLONG) value for the given **CTime64** object. |
| [GetYear](#GetYear) | Returns the year represented by the **CTime64** object. |
| [SetDateTime](#SetDateTime) | Sets the date and time of this **CTime64** object. |
