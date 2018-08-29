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

# COleDateTimeSpan Class

| Name       | Description |
| ---------- | ----------- |
| [Constructors](#Constructors2) | Create new **COleDateTimeSpan** objects initialized to the specified value. |
| [CAST Operator](#CastOp2) | Returns the **COleDateTimeSpan** value as a long integer. |
| [LET Operator](#LetOp2) | Assigns a value to a **COleDateTimeSpan** object. |
| [Operators](#Operators2) | Adds, subtracts or compares **COleDateTimeSpan** objects. |
| [GetDays](#GetDays) | Retrieves the day portion of this date/time-span value. |
| [GetHours](#GetHours) | Retrieves the hour portion of this date/time-span value. |
| [GetMinutes](#GetMinutes) | Retrieves the minutes portion of this date/time-span value. |
| [GetSeconds](#GetSeconds) | Retrieves the seconds portion of this date/time-span value. |
| [GetStatus](#GetStatus) | Gets the status (validity) of a given **COleDateTimeSpan** object. |
| [GetTotalDays](#GetTotalDays) | Retrieves this date/time-span value expressed in days. |
| [GetTotalHours](#GetTotalHours) | Retrieves this date/time-span value expressed in hours. |
| [GetTotalMinutes](#GetTotalMinutes) | Retrieves this date/time-span value expressed in minutes. |
| [GetTotalSeconds](#GetTotalSeconds) | Retrieves this date/time-span value expressed in seconds. |
| [SetDateTimeSpan](#SetDateTimeSpan) | Sets the date and time of this **COleDateTimeSpan** object. |
| [SetStatus](#SetStatus) | Sets the status (validity) of a given **COleDateTimeSpan** object. |

# <a name="Constructors1"></a>Constructors (COleDateTimeSpan)

All these constructors create new COleDateTime objects initialized to the specified value.

```
CONSTRUCTOR COleDateTime
CONSTRUCTOR COleDateTime (BYREF dateSrc AS COleDateTime)
CONSTRUCTOR COleDateTime (BYREF varSrc AS VARIANT)
CONSTRUCTOR COleDateTime (BYVAL dtSrc AS DATE_)
CONSTRUCTOR COleDateTime (BYVAL timeSrc AS LONGLONG)
CONSTRUCTOR COleDateTime (BYREF systimeSrc AS SYSTEMTIME)
CONSTRUCTOR COleDateTime (BYREF filetimeSrc AS FILETIME)
CONSTRUCTOR COleDateTime (BYVAL wDosDate AS DWORD, BYVAL wDosTime AS WORD)
CONSTRUCTOR COleDateTime (BYREF dbts AS DBTIMESTAMP)
CONSTRUCTOR COleDateTime (BYREF ud AS UDATE)
CONSTRUCTOR COleDateTime (BYVAL nYear AS WORD, BYVAL nMonth AS WORD, BYVAL nDay AS WORD, _
   BYVAL nHour AS WORD, BYVAL nMin AS WORD, BYVAL nSec AS WORD)
CONSTRUCTOR COleDateTime (BYREF wsz AS WSTRING, BYVAL dwFlags AS DWORD = 0, _
   BYVAL lcid AS LCID = LANG_USER_DEFAULT)
```

| Parameter  | Description |
| ---------- | ----------- |
| *dateSrc* | An existing **COleDateTime** object to be copied into the new **COleDateTime** object. |
| *varSrc* | An existing VARIANT data structure to be converted to a date/time value (VT_DATE) and copied into the new **COleDateTime** object. |
| *dtSrc* | A date/time ( DATE) value to be copied into the new **COleDateTime** object. |
| *timeSrc* | A LongInt value to be converted to a date/time value and copied into the new **COleDateTime** object. |
| *systimeSrc* | A SYSTEMTIME structure to be converted to a date/time value and copied into the new **COleDateTime** object. |
| *filetimeSrc* | A **FILETIME** structure to be converted to a date/time value and copied into the new **COleDateTime** object. Note that **FILETIME** uses Universal Coordinated Time (UTC), so if you pass a local time in the structure, your results will be incorrect. See File Times in the Windows SDK for more information. |
| *nYear / nMonth / nDay / nHour / nMin / nSec* | Indicate the date and time values to be copied into the new **COleDateTime** object. |
| *wDosDate / wDosTime* | MS-DOS date and time values to be converted to a date/time value and copied into the new **COleDateTime** object. |
| *dbts* | A reference to a **DBTimeStamp** structure containing the current local time. |
| *wsz* | A null-terminated unicode string which is to be parsed. This parameter can take a variety of formats. For example, the following strings contain acceptable date/time formats:<br>"25 January 1996"<br>"8:30:00"<br>"20:30:00"<br>"January 25, 1996 8:30:00"<br>"8:30:00 Jan. 25, 1996"<br>"1/25/1996 8:30:00" // always specify the full year, even in a 'short date' format.<br>Note that the locale ID will also affect whether the string format is acceptable for conversion to a date/time value. In the case of VAR_DATEVALUEONLY, the time value is set to time 0, or midnight. In the case of VAR_TIMEVALUEONLY, the date value is set to date 0, meaning 30 December 1899. |
| *dwFlags* | Indicates flags for locale settings and parsing.<br>LOCALE_NOUSEROVERRIDE Use the system default locale settings, rather than custom user settings.<br>VAR_TIMEVALUEONLY Ignore the date portion during parsing.<br>VAR_DATEVALUEONLY Ignore the time portion during parsing. |
| *lcid* | Indicates locale ID to use for the conversion. Default value: LANG_USER_DEFAULT. |

#### Remarks

The status of the new **COleDateTime** object is set to valid.

