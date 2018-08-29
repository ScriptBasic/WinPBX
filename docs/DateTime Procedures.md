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
| [AfxFileTimeToTime64](#AfxFileTimeToTime64) | Converts a FILETIME to a __time64_t (LONGLONG) value. |
| [AfxFileTimeToTimeStr](#AfxFileTimeToTimeStr) | Converts a FILETIME type to a string containing the time based on the specified mask, e.g. "hh':'mm':'ss". |
| [AfxGmtTime64](#AfxGmtTime64) | Converts a FILETIME to a __time64_t (LONGLONG) value. |
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
