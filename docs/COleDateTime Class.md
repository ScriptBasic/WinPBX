# COleDateTime Class

Encapsulates the **DATE** data type that is used in OLE automation.

It is one of the possible types for the VARIANT data type of OLE automation. A **COleDateTime** value represents an absolute date and time value. The **DATE** type is implemented as a floating-point value. Days are measured from December 30, 1899, at midnight. The **COleDateTime** class handles dates from January 1, 100, through December 31, 9999. The **COleDateTime** class uses the Gregorian calendar; it does not support Julian dates. **COleDateTime** ignores Daylight Saving Time. This type is also used to represent date-only or time-only values. By convention, the date 0 (December 30, 1899) is used for time-only values and the time 00:00 (midnight) is used for date-only values.

**Caution**: Note that although day values become negative before midnight on December 30, 1899, time-of-day values do not. For example, 6:00 AM is always represented by a fractional value 0.25 regardless of whether the integer representing the day is positive (after December 30, 1899) or negative (before December 30, 1899). This means that a simple floating point comparison would erroneously sort a **COleDateTime** representing 6:00 AM on 12/29/1899 as later than one representing 7:00 AM on the same day.

**Include file**: COleDateTime.inc

| Name       | Description |
| ---------- | ----------- |
| [Constructors](#Constructors1) | Create new **COleDateTime** objects initialized to the specified value. |
| [CAST Operator](#CastOp1) | Returns the **COleDateTime** value as a long integer. |
| [LET Operator](#LetOp1) | Assigns a value to a **COleDateTime** object. |
| [Operators](#Operators1) | Adds, subtracts or compares **COleDateTime** objects. |
| [Format](#Format) | Converts a **COleDateTime** object to a string. |
| [GetAsDBTIMESTAMP](#GetAsDBTIMESTAMP) | Returns the date/time the of this **COleDateTime** object as a **DBTIMESTAMP** data structure. |
| [GetAsSystemTime](#GetAsSystemTime) | Returns the date/time the of this **COleDateTime** object as a **SYSTEMTIME** data structure. |
| [GetAsUdate](#GetAsUdate) | Returns the date/time the of this **COleDateTime** object as a UDATE structure. |
| [GetCurrentTime](#GetCurrentTime) | Returns the current date/time value in local time. |
| [GetDay](#GetDay) | Gets the day represented by this date/time value. |
| [GetDayOfWeek](#GetDayOfWeek) | Gets the day of the week represented by this date/time value. |
| [GetDayOfYear](#GetDayOfYear) | Gets the day of the year represented by this date/time value. |
| [GetHour](#GetHour) | Gets the hour represented by this date/time value. |
| [GetLocalTime](#GetLocalTime) | Returns the current date/time value in local time. |
| [GetMinute](#GetMinute) | Gets the minute represented by this date/time value. |
| [GetMonth](#GetMonth) | Gets the month represented by this date/time value. |
| [GetSecond](#GetSecond) | Gets the second represented by this date/time value. |
| [GetStatus](#GetStatus) | Gets the status (validity) of a given **COleDateTime** object. |
| [GetSystemTime](#GetSystemTime) | Returns the current date/time value in Coordinated Universal Time (UTC). |
| [GetYear](#GetYear) | Gets the year represented by this date/time value. |
| [GetYear](#GetYear) | Gets the year represented by this date/time value. |
| [SetDate](#SetDate) | Sets the date of this **COleDateTime** object. |
| [SetDateTime](#SetDateTime) | Sets the date and time of this **COleDateTime** object. |
| [SetStatus](#SetStatus) | Sets the status (validity) of a given **COleDateTime** object. |
| [SetTime](#SetTime) | Sets the time of this **COleDateTime** object. |
