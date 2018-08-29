# Date and Time Procedures

Assorted date and time procedures.

**Include File**: AfxTime.inc.

| Name       | Description |
| ---------- | ----------- |
| [AfxAstroDay](#AfxAstroDay) | Returns the Astronomical Day for any given date. |
| [AfxAstroDayOfWeek](#AfxAstroDayOfWeek) | Calculates the day of the week, Sunday through Monday, of a given date. |
| [AfxDateAddDays](#AfxDateAddDays) | Adds the specified number of days to a given date. |
| [AfxDateDiff](#AfxDateDiff) | Calculates the days of difference between two dates. |
| [AfxDayOfYear](#AfxDayOfYear) | Returns the day of the year, where Jan 1 is the first day of the year. |
| [AfxDaysBetween](#AfxDaysBetween) | Returns the number of days between two given dates. |
| [AfxDaysInMonth](#AfxDaysInMonth) | Returns the number of days in the specified month/year. |
| [AfxDaysInYear](#AfxDaysInYear) | Returns the number of days in the specified year. |
| [AfxFileTimeToDateStr](#AfxFileTimeToDateStr) | Converts a FILETIME type to a string containing the date based on the specified mask, e.g. "dd-MM-yyyy". |
| [AfxFileTimeToTime64](#AfxFileTimeToTime64) | Converts a FILETIME to a \_\_time64_t (LONGLONG) value. |
| [AfxFileTimeToTimeStr](#AfxFileTimeToTimeStr) | Converts a FILETIME type to a string containing the time based on the specified mask, e.g. "hh':'mm':'ss". |
| [AfxGmtTime64](#AfxGmtTime64) | Converts a FILETIME to a \_\_time64_t (LONGLONG) value. |
| [AfxGregorianToJulian](#AfxGregorianToJulian) | Converts a Gregorian date to a Julian date. The year must be a 4 digit year. |
| [AfxIsFirstDayOfMonth](#AfxIsFirstDayOfMonth) | Returns TRUE if today is the first day of the month; False, otherwise. |
| [AfxIsLastDayOfMonth](#AfxIsLastDayOfMonth) | Returns TRUE if today is the last day of the month; False, otherwise. |
| [AfxIsLeapYear](#AfxIsLeapYear) | Determines if a given year is a leap year or not. |
| [AfxIsValidFILETIME](#AfxIsValidFILETIME) | Checks if a FILETIME is valid. |
| [AfxJulianDayOfWeek](#AfxJulianDayOfWeek) | Given a Julian date, returns the day of week. |
| [AfxJulianToGregorian](#AfxJulianToGregorian) | Converts a Julian date to a Gregorian date. |
| [AfxJulianToGregorianStr](#AfxJulianToGregorianStr) | Converts a Julian date to a Gregorian date based on the specified mask, e.g. "dd-MM-yyyy". |
| [AfxLocalDateStr](#AfxLocalDateStr) | Retuns the current local date based on the specified mask, e.g. "dd-MM-yyyy". |
| [AfxLocalDay](#AfxLocalDay) | Returns the current local day. The valid values are 1 through 31. |
| [AfxLocalDayName](#AfxLocalDayName) | Returns the localized name of today. |
| [AfxLocalDayOfWeek](#AfxLocalDayOfWeek) | Returns the current day of week. It is a numeric value in the range of 0-6 representing Sunday through Saturday: 0 = Sunday, 1 = Monday, etc. |
| [AfxLocalDayOfWeekName](#AfxLocalDayOfWeekName) | Returns the localized name of the day of the week. |
| [AfxLocalDayOfWeekShortName](#AfxLocalDayOfWeekShortName) | Returns the localized short name of the day of the week. |
| [AfxLocalDayShortName](#AfxLocalDayShortName) | Returns the localized short name of today. |
| [AfxLocalFileTime](#AfxLocalFileTime) | Returns the current local time as a FILETIME structure. |
| [AfxLocalHour](#AfxLocalHour) | Returns the current local hour. The valid values are 0 through 23. |
| [AfxLocalMonth](#AfxLocalMonth) | Returns the current local month. The valid values are 1 thorugh 12 (1 = January, etc.). |
| [AfxLocalMonthName](#AfxLocalMonthName) | Returns the localized name of today's local month. |
| [AfxLocalShortMonthName](#AfxLocalShortMonthName) | Returns the localized short name of today's local month. |
| [AfxLocalSystemTime](#AfxLocalSystemTime) | Returns the current local time as a SYSTEMTIME structure. |
| [AfxLocalTime64](#AfxLocalTime64) | Converts a FILETIME to a \_\_time64_t (LONGLONG) value. |
| [AfxLocalTimeStr](#AfxLocalTimeStr) | Retuns the current local time based on the specified mask, e.g. "hh':'mm':'ss". |
| [AfxLocalVariantTime](#AfxLocalVariantTime) | Returns the local date and time as a DATE_ (double). |
| [AfxLocalYear](#AfxLocalYear) | Returns the current local year. The valid values are 1601 through 30827. |
| [AfxLongDate](#AfxLongDate) | Returns the current date in long format. |
| [AfxMakeTime64](#AfxMakeTime64) | Converts the local time to a calendar value. |
| [AfxMonthName](#AfxMonthName) | Returns the localized name of the specified month. |
| [AfxQuadDateTime](#AfxQuadDateTime) | Returns the current date and time as a QUAD (8 bytes). In Free Basic, a QUAD is an ULONGLONG. |
| [AfxQuadDateToStr](#AfxQuadDateToStr) | Converts a date stored in a QUAD into a formatted date string. For example, to get the date string "Wed, Aug 31 94" use the following picture string: "ddd',' MMM dd yy".  In Free Basic, a QUAD is an ULONGLONG. |
| [AfxQuadTimeToStr](#AfxQuadTimeToStr) | Converts a time stored in a QUAD into a formatted time string. For example, get the time string "11:29:40 PM" use the following picture string: "hh':'mm':'ss tt".  In Free Basic, a QUAD is an ULONGLONG. |
| [AfxShortDate](#AfxShortDate) | Returns the current date in short format. |
| [AfxShortMonthName](#AfxShortMonthName) | Returns the localized short name of the specified month. |
| [AfxSystemDay](#AfxSystemDay) | Returns the current system day. The valid values are 1 through 31. |
| [AfxSystemDayName](#AfxSystemDayName) | Returns the localized name of today. |
| [AfxSystemDayOfWeek](#AfxSystemDayOfWeek) | Returns the current day of week. It is a numeric value in the range of 0-6 representing Sunday through Saturday: 0 = Sunday, 1 = Monday, etc. |
| [AfxSystemDayShortName](#AfxSystemDayShortName) | Returns the localized short name of today. |
| [AfxSystemFileTime](#AfxSystemFileTime) | Returns the current system time as a FILETIME structure. |
| [AfxSystemHour](#AfxSystemHour) | Returns the current system hour. The valid values are 0 through 23. |
| [AfxSystemMonth](#AfxSystemMonth) | Returns the current system month. The valid values are 1 thorugh 12 (1 = January, etc.). |
| [AfxSystemMonthName](#AfxSystemMonthName) | Returns the localized name of today's system month. |
| [AfxSystemShortMonthName](#AfxSystemShortMonthName) | Returns the localized short name of today's system month. |
| [AfxSystemSystemTime](#AfxSystemSystemTime) | Returns the current system time as a SYSTEMTIME structure. |
| [AfxSystemTimeToTime64](#AfxSystemTimeToTime64) | Converts a system time to a \_\_time64_t (LONGLONG). |
| [AfxSystemTimeToDateStr](#AfxSystemTimeToDateStr) | Converts a SYSTEMTIME type to a string containing the date based on the specified mask, e.g. "dd-MM-yyyy". |
| [AfxSystemTimeToTimeStr](#AfxSystemTimeToTimeStr) | Converts a SYSTEMTIME type to a string containing the time based on the specified mask, e.g. "hh':'mm':'ss". |
| [AfxSystemTimeToVariantTime](#AfxSystemTimeToVariantTime) | Converts a SYSTEMTIME to a DATE_ (double). |
| [AfxSystemYear](#AfxSystemYear) | Returns the current system year. The valid values are 1601 through 30827. |
| [AfxTime64](#AfxTime64) | Returns the time as seconds elapsed since midnight, January 1, 1970. |
| [AfxTime64ToFileTime](#AfxTime64ToFileTime) | Converts a \_\_time64_t (LONGLONG) value to a FILETIME structure. |
| [AfxTime64ToSystemTime](#AfxTime64ToSystemTime) | Converts a \_\_time64_t (LONGLONG) to a SYSTEMTIME structure. |
| [AfxTimeZoneBias](#AfxTimeZoneBias) | Current bias for local time translation. The bias is the difference between Coordinated Universal Time (UTC) and local time. All translations between UTC and local time are based on the following formula: UTC = local time + bias. Units = minutes. |
| [AfxTimeZoneDaylightBias](#AfxTimeZoneDaylightBias) | Bias value to be used during local time translations that occur during daylight saving time. This property is ignored if a value for the **DaylightDay** property is not supplied. The value of this property is added to the Bias property to form the bias used during daylight time. In most time zones, the value of this property is -60. Units = minutes. |
| [AfxTimeZoneDaylightDay](#AfxTimeZoneDaylightDay) | **DaylightDayOfWeek** of the **DaylightMonth** when the transition from standard time to daylight saving time occurs on this operating system. |
| [AfxTimeZoneDaylightDayOfWeek](#AfxTimeZoneDaylightDayOfWeek) | Day of the week when the transition from standard time to daylight saving time occurs on an operating system. |
| [AfxTimeZoneDaylightHour](#AfxTimeZoneDaylightHour) | Hour of the day when the transition from standard time to daylight saving time occurs on an operating system. |
| [AfxTimeZoneDaylightMonth](#AfxTimeZoneDaylightMonth) | Month when the transition from standard time to daylight saving time occurs on an operating system. |
| [AfxTimeZoneDaylightName](#AfxTimeZoneDaylightName) | A description for daylight saving time. For example, "EST" could indicate Eastern Standard Time. This string can be empty. |
| [AfxTimeZoneIsDaylightSavingTime](#AfxTimeZoneIsDaylightSavingTime) | Indicates whether the the system is operating in the range of daylight saving time for the current time zone. |
| [AfxTimeZoneStandardName](#AfxTimeZoneStandardName) | A description for standard time. For example, "EST" could indicate Eastern Standard Time. This string can be empty. |
| [AfxVariantDateTimeToStr](#AfxVariantDateTimeToStr) | Converts a DATE_ type to a string. |
| [AfxVariantDateToStr](#AfxVariantDateToStr) | Converts a DATE_ type to a string containing only the date. |
| [AfxVariantTimeToStr](#AfxVariantTimeToStr) | Converts a DATE_ type to a string containing only the time. |
| [AfxVariantTimeToSystemTime](#AfxVariantTimeToSystemTime) | Converts a DATE_ (double) to a SYSTEMTIME. |
| [AfxWeekNumber](#AfxWeekNumber) | Returns the week number for a given date. The year must be a 4 digit year. |
| [AfxWeekOne](#AfxWeekOne) | Returns the first day of the first week of a year. The year must be a 4 digit year. |
| [AfxWeeksInMonth](#AfxWeeksInMonth) | Returns the number of weeks in the specified month. Will be 4 or 5. |
| [AfxWeeksInYear](#AfxWeeksInYear) | Returns the number of weeks in the year, where weeks are taken to start on Monday. Will be 52 or 53. |

# <a name="AfxAstroDay"></a>AfxAstroDay

Returns the Astronomical Day for any given date.

```
FUNCTION AfxAstroDay (BYVAL nDay AS LONG, BYVAL nMonth AS LONG, BYVAL nYear AS LONG) AS LONG
```

| Parameter  | Description |
| ---------- | ----------- |
| *nDay* | A day number (1-31). |
| *nMonth* | A month number (1-12). |
| *nYear* | A four digit year. |

#### Return value

The astronomical day.

#### Remarks

Among other things, can be used to find the number of days between any two dates, e.g.:

```
PRINT AfxAstroDay(1, 3, -12400) - AfxAstroDay(28, 2, -12400)  ' Prints 2
PRINT AfxAstroDay(1, 3, 12000) - AfxAstroDay(28, 2, -12000)  ' Prints 8765822
PRINT AfxAstroDay(28, 2, 1902) - AfxAstroDay(1, 3, 1898)  ' Prints 1459 days
```

# <a name="AfxAstroDayOfWeek"></a>AfxAstroDayOfWeek

Calculates the day of the week, Sunday through Monday, of a given date.

```
FUNCTION AfxAstroDayOfWeek (BYVAL nDay AS LONG, BYVAL nMonth AS LONG, BYVAL nYear AS LONG) AS LONG
```

| Parameter  | Description |
| ---------- | ----------- |
| *nDay* | A day number (1-31). |
| *nMonth* | A month number (1-12). |
| *nYear* | A four digit year. |

#### Return value

A number between 0-6, where 0 = Sunday, 1 = Monday, 2 = Tuesday, 3 = Wednesday, 4 = Thursday, 5 = Friday, 6 = Saturday.

# <a name="AfxDateAddDays"></a>AfxDateAddDays

Adds the specified number of days to a given date.

```
FUNCTION AfxDateAddDays (BYVAL nDay AS LONG, BYVAL nMonth AS LONG, BYVAL nYear AS LONG, _
   BYVAL nDays AS LONG) AS LONG
```

| Parameter  | Description |
| ---------- | ----------- |
| *nDay* | A day number (1-31). |
| *nMonth* | A month number (1-12). |
| *nYear* | A four digit year. |
| *nDays* | The number of days to add (or subtract, if it is negative). |

#### Return value

The new date in Julian format. To convert it to Gregorian, call functions such **AfxJulianToGregorian** or **AfxJulianToGregorianStr**.

# <a name="AfxDateDiff"></a>AfxDateDiff

Calculates the days of difference between two dates.

```
FUNCTION AfxDateDiff (BYVAL nDay1 AS LONG, BYVAL nMonth1 AS LONG, BYVAL nYear1 AS LONG, _
   BYVAL nDay2 AS LONG, BYVAL nMonth2 AS LONG, BYVAL nYear2 AS LONG) AS LONG
```

| Parameter  | Description |
| ---------- | ----------- |
| *nDay1* | A day number (1-31). |
| *nMonth1* | A month number (1-12). |
| *nYear1* | A four digit year. |
| *nDay2* | A day number (1-31). |
| *nMonth2* | A month number (1-12). |
| *nYear2* | A four digit year. |

#### Return value

The days of difference between the two dates.

# <a name="AfxDayOfYear"></a>AfxDayOfYear

Returns the day of the year, where Jan 1 is the first day of the year.

```
FUNCTION AfxDayOfYear (BYVAL nDay AS LONG, BYVAL nMonth AS LONG, BYVAL nYear AS LONG) AS LONG
```

| Parameter  | Description |
| ---------- | ----------- |
| *nDay* | A day number (1-31). |
| *nMonth* | A month number (1-12). |
| *nYear* | A four digit year. |

#### Return value

The day of the year.

# <a name="AfxDaysBetween"></a>AfxDaysBetween

Returns the number of days between two given dates.

```
FUNCTION AfxDaysBetween (BYVAL nDay1 AS LONG, BYVAL nMonth1 AS LONG, BYVAL nYear1 AS LONG, _
   BYVAL nDay2 AS LONG, BYVAL nMonth2 AS LONG, BYVAL nYear2 AS LONG) AS LONG
```

| Parameter  | Description |
| ---------- | ----------- |
| *nDay1* | A day number (1-31). |
| *nMonth1* | A month number (1-12). |
| *nYear1* | A four digit year. |
| *nDay2* | A day number (1-31). |
| *nMonth2* | A month number (1-12). |
| *nYear2* | A four digit year. |

#### Return value

The number of days.
