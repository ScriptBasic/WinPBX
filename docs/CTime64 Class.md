# CTime64 Class

Represents an absolute time and date.

* **CTime64** values are based on coordinated universal time (UTC), which is equivalent to Coordinated Universal time (Greenwich Mean Time, GMT).
* A companion class, **CTimeSpan**, represents a time interval.
* The upper date limit is 12/31/3000. The lower limit is 1/1/1970 12:00:00 AM GMT.

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

# CTimeSpan Class

An amount of time, which is internally stored as the number of seconds in the time span.

* The **CTimeSpan** methods convert seconds to various combinations of days, hours, minutes, and seconds.
* The **CTimeSpan** object is stored in a \_\_time64_t structure, which is 8 bytes.
* A companion class, **CTime64**, represents an absolute time.

| Name       | Description |
| ---------- | ----------- |
| [Constructors](#Constructors2) | Create new **CTimeSpan** objects initialized to the specified value. |
| [CAST Operator](#CastOp2) | Returns the **CTimeSpan** value as a long integer. |
| [LET Operator](#LetOp2) | Assigns a value to a **CTimeSpan** object. |
| [Operators](#Operators2) | Adds, subtracts or compares **CTimeSpan** objects. |
| [GetDays](#GetDays) | Returns a value that represents the number of days in this **CTimeSpan**. |
| [GetHours](#GetHours) | Returns a value that represents the number of hours in the current day (–23 through 23). |
| [GetMinutes](#GetMinutes) | Returns a value that represents the number of minutes in the current hour (–59 through 59). |
| [GetSeconds](#GetSeconds) | Returns a value that represents the number of seconds in the current hour (–59 through 59). |
| [GetTimeSpan](#GetTimeSpan) | Returns the underlying time value from this **CTimeSpan** object. |
| [GetTotalHours](#GetTotalHours) | Returns a value that represents the total number of complete hours in this **CTimeSpan**. |
| [GetTotalMinutes](#GetTotalMinutes) | Returns a value that represents the total number of complete minutes in this **CTimeSpan**. |
| [GetTotalSeconds](#GetTotalSeconds) | Retrieves this date/time-span value expressed in seconds. |
| [SetTimeSpan](#SetTimeSpan) | Sets the value of this date/time-span value. |

# <a name="Constructors1"></a>Constructors (CTime64)

Create new **CTime64** objects initialized to the specified value.

```
CONSTRUCTOR CTime64
CONSTRUCTOR CTime64 (BYVAL timeSrc AS LONGLONG)
CONSTRUCTOR CTime64 (BYREF systimeSrc AS SYSTEMTIME)
CONSTRUCTOR CTime64 (BYREF filetimeSrc AS FILETIME)
CONSTRUCTOR CTime64 (BYVAL nYear AS LONG, BYVAL nMonth AS LONG, BYVAL nDay AS LONG, _
   BYVAL nHour AS LONG, BYVAL nMin AS LONG, BYVAL nSec AS LONG)
```

| Parameter  | Description |
| ---------- | ----------- |
| *timeSrc* | A \_\_time64_t (LONGLONG) value. |
| *systimeSrc* | A **SYSTEMTIME** structure to be converted to a **\_\_time64_t** (LONGLONG) value and copied into the new **CTime64** object. |
| *filetimeSrc* | A **FILETIME** structure to be converted to a **\_\_time64_t** (LONGLONG) value and copied into  the new **CTime64** object. Note that **FILETIME** uses Universal Coordinated Time (UTC), so if you pass a local time in the structure, your results will be incorrect. |
| *nYear / nMonth / nDay / nHour / nMin / nSec* |  Indicates the date and time values to be copied into the new **CTime64** object. |

#### Examples

Initializes a **CTime64** object from an existing **\_\_time64_t** value.

```
DIM ct1 AS CTime64 = CTime64().GetCurrentTime()
DIM ct2 AS CTime64 = ct1.GetTime
```

**Note**: You can also use DIM ct2 AS CTime64 = ct1

Initializes a **CTime64** object from individual date/time values.

```
' // Year = 2017, Month = 10 (October), Day = 9, Hour = 11, Minutes = 32, Seconds = 45
DIM ct AS CTime64 = CTime64(2017, 10, 9, 11, 32, 45)
```

Initializes a **CTime64** object from a **SYSTEMTIME** structure.

```
' // Year = 2017, Month = 10 (October), Day = 9, Hour = 11, Minutes = 32, Seconds = 45
DIM st AS SYSTEMTIME 
st.wYear = 2017
st.wMonth = 10
st.wDayOfWeek = 0
st.wDay = 9
st.wHour = 11
st.wMinute = 32
st.wSecond = 45
st.wMilliseconds = 0
' --or--
DIM st AS SYSTEMTIME = (2017, 10, 0, 9, 11, 32, 45, 0)
DIM ct AS CTime64 = st
' --or--
DIM ct AS CTime64
ct.SetDateTime(2017, 10, 9, 11, 32, 45)
DIM st AS SYSTEMTIME = ct.GetAsSystemtime
DIM ct2 AS CTime64 = st
' --or--
DIM ct AS CTime64
ct.SetDateTime(2017, 10, 9, 11, 32, 45)
DIM ct2 AS CTime64 = ct.GetAsSystemtime
```

# <a name="CastOp1"></a>CAST Operator (CTime64)

Returns the underlying value from this **CTime64** object.

```
OPERATOR CAST () AS LONGLONG
```

# <a name="LetOp1"></a>LET Operator (=) (CTime64)

Assigns a value to a **CTime64** object.

```
OPERATOR LET (BYVAL timeSrc AS LONGLONG)
OPERATOR LET (BYREF st AS SYSTEMTIME)
OPERATOR LET (BYREF ft AS FILETIME)
```

| Parameter  | Description |
| ---------- | ----------- |
| *timeSrc* | A \_\_time64_t (LONGLONG) value. |
| *st* | A **SYSTEMTIME** structure to be converted to a **\_\_time64_t** (LONGLONG) value and copied into the new **CTime64** object. |
| *ft* | A **FILETIME** structure to be converted to a **\_\_time64_t** (LONGLONG) value and copied into  the new **CTime64** object. Note that **FILETIME** uses Universal Coordinated Time (UTC), so if you pass a local time in the structure, your results will be incorrect. |

# <a name="Operators1"></a>Operators (CTime64)

Adds, subtracts or compares **CTime64** objects.

```
OPERATOR + (BYREF dt AS CTime64, BYREF dateSpan AS CTimeSpan) AS CTime64
OPERATOR - (BYREF dt AS CTime64, BYREF dateSpan AS CTimeSpan) AS CTime64
OPERATOR - (BYREF dt1 AS CTime64, BYREF dt2 AS CTime64) AS CTimeSpan
OPERATOR += (BYREF dateSpan AS CTimeSpan)
OPERATOR -= (BYREF dateSpan AS CTimeSpan)
OPERATOR = (BYREF dt1 AS CTime64, BYREF dt2 AS CTime64) AS BOOLEAN
OPERATOR <> (BYREF dt1 AS CTime64, BYREF dt2 AS CTime64) AS BOOLEAN
OPERATOR < (BYREF dt1 AS CTime64, BYREF dt2 AS CTime64) AS BOOLEAN
OPERATOR > (BYREF dt1 AS CTime64, BYREF dt2 AS CTime64) AS BOOLEAN
OPERATOR <= (BYREF dt1 AS CTime64, BYREF dt2 AS CTime64) AS BOOLEAN
OPERATOR >= (BYREF dt1 AS CTime64, BYREF dt2 AS CTime64) AS BOOLEAN
```

#### Remarks

```
+ Adds a CTimeSpan object to a CTime64 object.
- Subtracts a CTimeSpan object from a CTime64 object.
- Subtracts a CTime64 object from another CTime64 object.
+= Adds a CTimeSpan object to this CTime64 object.
-= Subtracts a CTimeSpan object from this CTime64 object.
```

