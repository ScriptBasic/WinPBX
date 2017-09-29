' ########################################################################################
' Microsoft Windows
' File: AfxTime.inc
' Contents: Date and time functions.
' Copyright (c) 2011 José Roca
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%AFXTIME_INC = 1

#INCLUDE ONCE "windows.inc"
#INCLUDE ONCE "AfxNls.inc"
#INCLUDE ONCE "OleAuto.inc"

' ========================================================================================
' Returns the Astronomical Day for any given date.
' Parameters:
' - nDay: A number between 1-31.
' - nMonth; A number between 1-12.
' - nYear: A four digit year, e.g. 2011.
' Return Value:
' - The Astronomical Day.
' See: http://support.microsoft.com/kb/109451/en-us
' Note: Among other things, can be used to find the number of days between any two dates, e.g.:
' PRINT AfxAstroDay(1, 3, -12400) - AfxAstroDay(28, 2, -12400)  ' Prints 2
' PRINT AfxAstroDay(1, 3, 12000) - AfxAstroDay(28, 2, -12000) ' Prints 8765822
' PRINT AfxAstroDay(28, 2, 1902) - AfxAstroDay(1, 3, 1898)  ' Prints 1459 days
' ========================================================================================
FUNCTION AfxAstroDay (BYVAL nDay AS LONG, BYVAL nMonth AS LONG, BYVAL nYear AS LONG) AS LONG
   LOCAL y AS DOUBLE
   y = nYear + (nMonth - 2.85) / 12
   FUNCTION = INT(INT(INT(367 * y) - 1.75 * INT(y) + nDay) - 0.75 * INT(0.01 * y)) + 1721116
END FUNCTION
' ========================================================================================

' ========================================================================================
' Calculates the day of the week, Sunday through Monday, of a given date.
' Parameters:
' - nDay: A number between 1-31.
' - nMonth; A number between 1-12.
' - nYear: A four digit year, e.g. 2011.
' Return Value:
' - A number between 0-6, where 0 = Sunday, 1 = Monday, 2 = Tuesday, 3 = Wednesday,
'   4 = Thursday, 5 = Friday, 6 = Saturday.
' ========================================================================================
FUNCTION AfxAstroDayOfWeek (BYVAL nDay AS LONG, BYVAL nMonth AS LONG, BYVAL nYear AS LONG) AS LONG
   FUNCTION = AfxAstroDay(nDay, nMonth, nYear) MOD 7
END FUNCTION
' ========================================================================================

' ========================================================================================
' Converts a Gregorian date to a Julian date.
' Parameters:
' - nDay: A number between 1-31.
' - nMonth: A number between 1-12.
' - nYear: A four digit year, e.g. 2011.
' Return Value:
' - The converted date.
' ========================================================================================
FUNCTION AfxDateToJulian (BYVAL nDay AS LONG, BYVAL nMonth AS LONG, BYVAL nYear AS LONG) AS LONG

   LOCAL DaysElapsed AS LONG
   LOCAL InvalidLeapYears AS LONG
   LOCAL ValidLeapYears AS LONG
   LOCAL DaysOfMonths AS LONG

   ' // January or February? 13 or 14th month of the previous year.
   IF nMonth < 3 THEN nMonth += 12 : DECR nYear
   ' // Day 1 of julian calendar is 1/1/-4712 and there are 365.25 days per year
   DaysElapsed = INT((nYear + 4712) * 365.25)
   ' // Substract invalid leap years
   InvalidLeapYears = nYear \ 100
   ' // Add valid leap years
   ValidLeapYears = nYear \ 400
   ' // Days of months
   DaysOfMonths = INT(30.6 * (nMonth - 1) + .2)

   FUNCTION = DaysElapsed - InvalidLeapYears + ValidLeapYears + DaysOfMonths + nDay

END FUNCTION
' ========================================================================================

' ========================================================================================
' Calculates the days of difference between two dates.
' Parameters:
' - nDay1, nMonth1, nYear1 : The first date
' - nDay2, nMonth2, nYear2 : The second date
' Return Value:
' - The days of difference.
' ========================================================================================
FUNCTION AfxDateDiff (BYVAL nDay1 AS LONG, BYVAL nMonth1 AS LONG, BYVAL nYear1 AS LONG, _
   BYVAL nDay2 AS LONG, BYVAL nMonth2 AS LONG, BYVAL nYear2 AS LONG) AS LONG
   LOCAL t1, t2 AS LONG
   t1 = AfxDateToJulian(nDay1, nMonth1, nYear1)
   t2 = AfxDateToJulian(nDay2, nMonth2, nYear2)
   FUNCTION = t2 - t1
END FUNCTION
' ========================================================================================

' ========================================================================================
' Adds the specified number of days to a given date.
' Parameters:
' - nDay: A number between 1-31.
' - nMonth; A number between 1-12.
' - nYear: A four digit year, e.g. 2011.
' - nDays: The number of days to add (or substract, if the number is negative).
' Return Value:
' - The new date in Julian format. To convert it to Gregorian, call functions such
'   AfxJulianToDate or AfxJulianToDateStr.
' ========================================================================================
FUNCTION AfxDateAdd (BYVAL nDay AS LONG, BYVAL nMonth AS LONG, BYVAL nYear AS LONG, BYVAL nDays AS LONG) AS LONG
   FUNCTION = AfxDateToJulian(nDay, nMonth, nYear) + nDays
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the first day of the first week of a year. The year must be a 4 digit year.
' Please note that the result can be one of the last days of the previous year, e.g. the
' first day of the first week of year 2002 is 31 December 2001.
' To convert the returned julian date to gregorian use AfxJulianToDate or AfxJulianToDateStr.
' ========================================================================================
FUNCTION AfxWeekOne (BYVAL nYear AS LONG) AS LONG
   LOCAL nFirstDay AS LONG
   nFirstDay = AfxDateToJulian(1, 1, nYear) - 1  ' Dec. 31 of prev. year
   DO
      INCR nFirstDay
   LOOP UNTIL (nFirstDay MOD 7 + 1) = 4    ' until first Thursday of the year is found
   FUNCTION = nFirstDay - 3                ' first day of week 1 is a Monday
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the week number for a given date. The year must be a 4 digit year.
' ========================================================================================
FUNCTION AfxWeekNumber (BYVAL nDay AS LONG, BYVAL nMonth AS LONG, BYVAL nYear AS LONG) AS LONG
   LOCAL nFirstDay AS LONG, nFinalDay AS LONG, nToDay AS LONG
   nFirstDay = AfxWeekOne(nYear)
   nFinalDay = AfxWeekOne(nYear + 1) - 1
   nToDay = AfxDateToJulian(nDay, nMonth, nYear)
   SELECT CASE nToDay
      CASE < nFirstDay
         ' it is week 52 or 53, but which one?
         ' therefore we need week one of previous year as a starting point
         nFirstDay = AfxWeekOne(nYear - 1)
      CASE > nFinalDay
         ' there is only one possibility: week number 1
         FUNCTION = 1
         EXIT FUNCTION
   END SELECT
   FUNCTION = ((nToDay - nFirstDay) \ 7) + 1
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the number of weeks in the year, where weeks are taken to start on Monday. Will be 52 or 53.
' ========================================================================================
FUNCTION AfxWeeksInYear (BYVAL nYear AS LONG) AS LONG
   LOCAL nWeeks AS LONG
   nWeeks = AfxWeekNumber(31, 12, nYear)
   IF nWeeks = 53 THEN FUNCTION = 53 ELSE FUNCTION = 52
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the number of weeks in the specified month. Will be 4 or 5.
' ========================================================================================
FUNCTION AfxWeeksInMonth (BYVAL nMonth AS LONG, BYVAL nYear AS LONG) AS LONG
   LOCAL dow, nWeeks AS LONG
   dow = AfxAstroDayOfWeek(1, nMonth, nYear) - 1
   IF dow = -1 THEN dow = 6
   nWeeks = (AfxDaysInMonth(nMonth, nYear) + dow) \ 7
   FUNCTION = nWeeks
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the current day.
' ========================================================================================
FUNCTION AfxDay () AS WORD
   LOCAL ST AS SYSTEMTIME
   GetLocalTime ST
   FUNCTION = ST.wDay
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the current day of week: 0 = Sunday, 1 = Monday, etc.
' ========================================================================================
FUNCTION AfxDayOfWeek () AS WORD
   LOCAL ST AS SYSTEMTIME
   GetLocalTime ST
   FUNCTION = ST.wDayOfWeek
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the localized name of the day of the week.
' Parameters:
' - nDay: A number between 1-31.
' - nMonth; A number between 1-12.
' - nYear: A four digit year, e.g. 2011.
' Return Value:
' - The localized day of week name.
' ========================================================================================
FUNCTION AfxGetDayOfWeekName (BYVAL nDay AS LONG, BYVAL nMonth AS LONG, BYVAL nYear AS LONG, OPTIONAL BYVAL lcid AS DWORD) AS WSTRING
   LOCAL ST AS SYSTEMTIME
   LOCAL wszDate AS WSTRINGZ * 260
   ST.wYear = nYear
   ST.wMonth = nMonth
   ST.wDay = nDay
   IF lcid = 0 THEN lcid = %LOCALE_USER_DEFAULT
   GetDateFormatW(lcid, %NULL, ST, "dddd", wszDate, SIZEOF(wszDate))
   FUNCTION = wszDate
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the localized short name of the day of the week.
' Parameters:
' - nDay: A number between 1-31.
' - nMonth; A number between 1-12.
' - nYear: A four digit year, e.g. 2011.
' Return Value:
' - The localized day of week short name.
' ========================================================================================
FUNCTION AfxGetDayOfWeekShortName (BYVAL nDay AS LONG, BYVAL nMonth AS LONG, BYVAL nYear AS LONG, OPTIONAL BYVAL lcid AS DWORD) AS WSTRING
   LOCAL ST AS SYSTEMTIME
   LOCAL wszDate AS WSTRINGZ * 260
   ST.wYear = nYear
   ST.wMonth = nMonth
   ST.wDay = nDay
   IF lcid = 0 THEN lcid = %LOCALE_USER_DEFAULT
   GetDateFormatW(lcid, %NULL, ST, "ddd", wszDate, SIZEOF(wszDate))
   FUNCTION = wszDate
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retuns the current date based on the specified mask, e.g. "dd-MM-yyyy".
' ========================================================================================
FUNCTION AfxGetFormattedDate (BYVAL bstrMask AS WSTRING, OPTIONAL BYVAL lcid AS DWORD) AS WSTRING
   LOCAL wszDateStr AS WSTRINGZ * 260
   IF lcid = 0 THEN lcid = %LOCALE_USER_DEFAULT
   GetDateFormatW(lcid, %NULL, BYVAL %NULL, BYCOPY bstrMask, wszDateStr, SIZEOF(wszDateStr))
   FUNCTION = wszDateStr
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the current date in yyyyMMdd format, usually used in some database indexed date fields.
' ========================================================================================
FUNCTION AfxDbDate (OPTIONAL BYVAL lcid AS DWORD) AS WSTRING
   FUNCTION = AfxGetFormattedDate("yyyyMMdd", lcid)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the current date in yyMMdd format, usually used in some database indexed date fields.
' ========================================================================================
FUNCTION AfxShortDbDate (OPTIONAL BYVAL lcid AS DWORD) AS WSTRING
   FUNCTION = AfxGetFormattedDate("yyMMdd", lcid)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retuns the current time based on the specified mask, e.g. "hh':'mm':'ss".
' ========================================================================================
FUNCTION AfxGetFormattedTime (BYVAL bstrMask AS WSTRING, OPTIONAL BYVAL lcid AS DWORD) AS WSTRING
   LOCAL wszDateStr AS WSTRINGZ * 260
   IF lcid = 0 THEN lcid = %LOCALE_USER_DEFAULT
   GetTimeFormatW(lcid, %NULL, BYVAL %NULL, BYCOPY bstrMask, wszDateStr, SIZEOF(wszDateStr))
   FUNCTION = wszDateStr
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the current time in hh:mm:ss format.
' ========================================================================================
FUNCTION AfxTimeStr (OPTIONAL BYVAL lcid AS DWORD) AS WSTRING
   FUNCTION = AfxGetFormattedTime("hh':'mm':'ss", lcid)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the localized name of the specified month.
' ========================================================================================
FUNCTION AfxGetMonthName (BYVAL nMonth AS LONG, OPTIONAL BYVAL lcid AS DWORD) AS WSTRING
   LOCAL ST AS SYSTEMTIME
   LOCAL wszDate AS WSTRINGZ * 260
   GetSystemTime(ST)
   ST.wMonth = nMonth
   IF lcid = 0 THEN lcid = %LOCALE_USER_DEFAULT
   GetDateFormatW(lcid, %NULL, ST, "MMMM", wszDate, SIZEOF(wszDate))
   FUNCTION = wszDate
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the localized short name of the specified month.
' ========================================================================================
FUNCTION AfxGetShortMonthName (BYVAL nMonth AS LONG, OPTIONAL BYVAL lcid AS DWORD) AS WSTRING
   LOCAL ST AS SYSTEMTIME
   LOCAL wszDate AS WSTRINGZ * 260
   GetSystemTime(ST)
   ST.wMonth = nMonth
   IF lcid = 0 THEN lcid = %LOCALE_USER_DEFAULT
   GetDateFormatW(lcid, %NULL, ST, "MMM", wszDate, SIZEOF(wszDate))
   FUNCTION = wszDate
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the localized name of today's month.
' ========================================================================================
FUNCTION AfxGetTodayMonthName (OPTIONAL BYVAL lcid AS DWORD) AS WSTRING
   LOCAL ST AS SYSTEMTIME
   LOCAL wszDate AS WSTRINGZ * 260
   GetSystemTime(ST)
   IF lcid = 0 THEN lcid = %LOCALE_USER_DEFAULT
   GetDateFormatW(lcid, %NULL, ST, "MMMM", wszDate, SIZEOF(wszDate))
   FUNCTION = wszDate
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the localized name of today.
' ========================================================================================
FUNCTION AfxGetTodayName (OPTIONAL BYVAL lcid AS DWORD) AS WSTRING
   LOCAL ST AS SYSTEMTIME
   LOCAL wszDate AS WSTRINGZ * 260
   GetSystemTime(ST)
   IF lcid = 0 THEN lcid = %LOCALE_USER_DEFAULT
   GetDateFormatW(lcid, %NULL, ST, "dddd", wszDate, SIZEOF(wszDate))
   FUNCTION = wszDate
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the localized short name of today's month.
' ========================================================================================
FUNCTION AfxGetTodayShortMonthName (OPTIONAL BYVAL lcid AS DWORD) AS WSTRING
   LOCAL ST AS SYSTEMTIME
   LOCAL wszDate AS WSTRINGZ * 260
   GetSystemTime(ST)
   IF lcid = 0 THEN lcid = %LOCALE_USER_DEFAULT
   GetDateFormatW(lcid, %NULL, ST, "MMM", wszDate, SIZEOF(wszDate))
   FUNCTION = wszDate
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the localized short name of today.
' ========================================================================================
FUNCTION AfxGetTodayShortName (OPTIONAL BYVAL lcid AS DWORD) AS WSTRING
   LOCAL ST AS SYSTEMTIME
   LOCAL wszDate AS WSTRINGZ * 260
   GetSystemTime(ST)
   IF lcid = 0 THEN lcid = %LOCALE_USER_DEFAULT
   GetDateFormatW(lcid, %NULL, ST, "ddd", wszDate, SIZEOF(wszDate))
   FUNCTION = wszDate
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the current hour.
' ========================================================================================
FUNCTION AfxHour () AS WORD
   LOCAL ST AS SYSTEMTIME
   GetLocalTime ST
   FUNCTION = ST.wHour
END FUNCTION
' ========================================================================================

' ========================================================================================
' Determines if a given year is a leap year or not.
' Parameters:
' - nYear: A four digit year, e.g. 2011.
' Return Value:
' - TRUE or FALSE.
' Note: A leap year is defined as all years divisible by 4, except for years divisible by
' 100 that are not also divisible by 400. Years divisible by 400 are leap years. 2000 is a
' leap year. 1900 is not a leap year.
' ========================================================================================
FUNCTION AfxIsLeapYear (BYVAL nYear AS LONG) AS LONG
   IF (nYear MOD 4 = 0 AND nYear MOD 100 <> 0) OR nYear MOD 400 = 0 THEN FUNCTION = %TRUE
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the number of days in the specified year.
' Parameters:
' - nYear: A four digit year, e.g. 2011.
' Return Value:
' - The number of days.
' ========================================================================================
FUNCTION AfxDaysInYear (BYVAL nYear AS LONG) AS LONG
   IF AfxIsLeapYear(nYear) THEN FUNCTION = 366 ELSE FUNCTION = 365
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the number of days in the specified month.
' Parameters:
' - nMonth: A two digit month (1-12).
' - nYear: A four digit year, e.g. 2011.
' Return Value:
' - The number of days.
' ========================================================================================
FUNCTION AfxDaysInMonth (BYVAL nMonth AS LONG, BYVAL nYear AS LONG) AS LONG
   SELECT CASE nMonth
      CASE 2 : IF AfxIsLeapYear(nYear) THEN FUNCTION = 29 ELSE FUNCTION = 28
      CASE 4, 6, 9, 11 : FUNCTION = 30
      CASE 1, 3, 5, 7, 8, 10, 12 : FUNCTION = 31
   END SELECT
END FUNCTION
' ========================================================================================

' ========================================================================================
' Given a Julian date, returns the day of week.
' ========================================================================================
FUNCTION AfxJulianDayOfWeek (BYVAL nJulian AS LONG) AS LONG
   LOCAL dow AS LONG
   dow = (nJulian + 1) MOD 7
   IF (dow => 0) THEN FUNCTION = dow ELSE FUNCTION = dow + 7
END FUNCTION
' ========================================================================================

' ========================================================================================
' Converts a Julian date to a Gregorian date.
' Parameters:
' - nJulian [in] = The julian date to convert
' - nDay [out] = The day
' - nMonth [out] = The month
' - nYear [out] = The year
' ========================================================================================
SUB AfxJulianToDate (BYVAL nJulian AS LONG, BYREF wDay AS WORD, BYREF wMonth AS WORD, BYREF wYear AS WORD)
   LOCAL nHelp AS LONG, nTmpMonth AS LONG, nTmpYear AS LONG
   nJulian = nJulian + 68569
   nHelp = 4 * nJulian \ 146097
   nJulian = nJulian - ((146097 * nHelp + 3) \ 4)
   nTmpYear = 4000 * (nJulian + 1) \ 1461001
   nJulian = nJulian - (1461 * nTmpYear \ 4) + 31
   nTmpMonth = 80 * nJulian \ 2447
   wDay = nJulian - (2447 * nTmpMonth \ 80)
   wMonth = nTmpMonth + 2 - (12 * (nTmpMonth \ 11))
   wYear = 100 * (nHelp - 49) + nTmpYear + (nTmpMonth \ 11)
END SUB
' ========================================================================================

' ========================================================================================
' Converts a Julian date to a Gregorian date based on the specified mask, e.g. "dd-MM-yyyy".
' Parameters:
' - bstrMask = The format string.
' - nJulian = The Julian date to convert.
' Return Value:
' - The converted date.
' ========================================================================================
FUNCTION AfxJulianToDateStr (BYVAL bstrMask AS WSTRING, BYVAL nJulian AS LONG, OPTIONAL BYVAL lcid AS DWORD) AS WSTRING
   LOCAL ST AS SYSTEMTIME
   LOCAL wszDate AS WSTRINGZ * 260
   AfxJulianToDate(nJulian, ST.wDay, ST.wMonth, ST.wYear)
   IF lcid = 0 THEN lcid = %LOCALE_USER_DEFAULT
   GetDateFormatW(lcid, %NULL, ST, BYCOPY bstrMask, wszDate, SIZEOF(wszDate))
   FUNCTION = wszDate
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the day of the year, where Jan 1 is the first day of the year.
' ========================================================================================
FUNCTION AfxGetDayOfYear (BYVAL nDay AS LONG, BYVAL nMonth AS LONG, BYVAL nYear AS LONG) AS LONG
   FUNCTION = AfxAstroDay(nDay, nMonth, nYear) - AfxAstroDay(1, 1, nYear) + 1
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the number of days between two given dates.
' ========================================================================================
FUNCTION AfxGetDaysBetween (BYVAL nDay1 AS LONG, BYVAL nMonth1 AS LONG, BYVAL nYear1 AS LONG, BYVAL nDay2 AS LONG, BYVAL nMonth2 AS LONG, BYVAL nYear2 AS LONG) AS LONG
   FUNCTION = AfxAstroDay(nDay1, nMonth1, nYear1) - AfxAstroDay(nDay2, nMonth2, nYear2)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the current date in long format.
' ========================================================================================
FUNCTION AfxLongDate (OPTIONAL BYVAL lcid AS DWORD) AS WSTRING
   LOCAL ST AS SYSTEMTIME
   LOCAL wszDate AS WSTRINGZ * 260
   GetLocalTime ST
   IF lcid = 0 THEN lcid = %LOCALE_USER_DEFAULT
   GetDateFormatW(lcid, %DATE_LONGDATE, ST, BYVAL %NULL, wszDate, SIZEOF(wszDate))
   FUNCTION = wszDate
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the current month.
' ========================================================================================
FUNCTION AfxMonth () AS WORD
   LOCAL ST AS SYSTEMTIME
   GetLocalTime ST
   FUNCTION = ST.wMonth
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the curent date and time as a QUAD (8 bytes).
' ========================================================================================
FUNCTION AfxQuadDateTime () AS QUAD
   LOCAL ST AS SYSTEMTIME, FT AS FILETIME
   GetLocalTime(ST)
   SystemTimeToFileTime(ST, FT)
   FUNCTION = FT.qDateTime
END FUNCTION
' ========================================================================================

' ========================================================================================
' Converts a date and time stored in a QUAD into a string.
' ========================================================================================
FUNCTION AfxQuadDateTimeToStr (BYVAL qTime AS QUAD) AS WSTRING
   IF qTime = 0 THEN EXIT FUNCTION
   LOCAL ST AS SYSTEMTIME, FT AS FILETIME, bstrDateSep, bstrTimeSep AS WSTRING
   bstrDateSep = AfxGetLocaleDateSeparator
   bstrTimeSep = AfxGetLocaleTimeSeparator
   FT.qDateTime = qTime
   FileTimeToSystemTime(FT, ST)
   FUNCTION = FORMAT$(ST.wDay,"00") & bstrDateSep & _
              FORMAT$(ST.wMonth,"00") & bstrDateSep & _
              FORMAT$(ST.wYear,"00") & " " & _
              FORMAT$(ST.wHour,"00") & bstrTimeSep & _
              FORMAT$(ST.wMinute,"00") & bstrTimeSep & _
              FORMAT$(ST.wSecond,"00")
END FUNCTION
' ========================================================================================

' ========================================================================================
' Converts a date stored in a QUAD into a formatted date string. For example, to get
' the date string "Wed, Aug 31 94" use the following picture string: "ddd',' MMM dd yy".
' ========================================================================================
FUNCTION AfxQuadDateToFormattedStr (BYVAL bstrMask AS WSTRING, BYVAL qTime AS QUAD, OPTIONAL BYVAL lcid AS DWORD) AS WSTRING
   IF qTime = 0 THEN EXIT FUNCTION
   LOCAL ST AS SYSTEMTIME, FT AS FILETIME
   LOCAL wszDate AS WSTRINGZ * 260
   FT.qDateTime = qTime
   FileTimeToSystemTime(FT, ST)
   IF lcid = 0 THEN lcid = %LOCALE_USER_DEFAULT
   GetDateFormatW(lcid, %NULL, ST, BYCOPY bstrMask, wszDate, SIZEOF(wszDate))
   FUNCTION = wszDate
END FUNCTION
' ========================================================================================

' ========================================================================================
' Converts a date stored in a QUAD into a string.
' ========================================================================================
FUNCTION AfxQuadDateToStr (BYVAL qTime AS QUAD) AS WSTRING
   IF qTime = 0 THEN EXIT FUNCTION
   LOCAL ST AS SYSTEMTIME, FT AS FILETIME, bstrDateSep AS WSTRING
   bstrDateSep = AfxGetLocaleDateSeparator
   FT.qDateTime = qTime
   FileTimeToSystemTime(FT, ST)
   FUNCTION = FORMAT$(ST.wDay,"00") & bstrDateSep & _
              FORMAT$(ST.wMonth,"00") & bstrDateSep & _
              FORMAT$(ST.wYear,"00")
END FUNCTION
' ========================================================================================

' ========================================================================================
' Converts a time stored in a QUAD into a formatted time string. For example, to get the
' time string "11:29:40 PM" use the following picture string: "hh':'mm':'ss tt".
' ========================================================================================
FUNCTION AfxQuadTimeToFormattedStr (BYVAL bstrMask AS WSTRING, BYVAL qTime AS QUAD, OPTIONAL BYVAL lcid AS DWORD) AS WSTRING
   IF qTime = 0 THEN EXIT FUNCTION
   LOCAL ST AS SYSTEMTIME, FT AS FILETIME
   LOCAL wszTime AS WSTRINGZ * 260
   FT.qDateTime = qTime
   FileTimeToSystemTime(FT, ST)
   IF lcid = 0 THEN lcid = %LOCALE_USER_DEFAULT
   GetTimeFormatW(lcid, %NULL, ST, BYCOPY bstrMask, wszTime, SIZEOF(wszTime))
   FUNCTION = wszTime
END FUNCTION
' ========================================================================================

' ========================================================================================
' Converts a time stored in a QUAD into a string.
' ========================================================================================
FUNCTION AfxQuadTimeToStr (BYVAL qTime AS QUAD) AS WSTRING
   IF qTime = 0 THEN EXIT FUNCTION
   LOCAL ST AS SYSTEMTIME, FT AS FILETIME, bstrDateSep AS WSTRING
   bstrDateSep = AfxGetLocaleDateSeparator
   FT.qDateTime = qTime
   FileTimeToSystemTime(FT, ST)
   FUNCTION = FORMAT$(ST.wDay,"00") & bstrDateSep & _
              FORMAT$(ST.wMonth,"00") & bstrDateSep & _
              FORMAT$(ST.wYear,"00")
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the current date in short format.
' ========================================================================================
FUNCTION AfxShortDate (OPTIONAL BYVAL lcid AS DWORD) AS WSTRING
   LOCAL ST AS SYSTEMTIME
   LOCAL wszDate AS WSTRINGZ * 260
   GetLocalTime ST
   IF lcid = 0 THEN lcid = %LOCALE_USER_DEFAULT
   GetDateFormatW(lcid, %DATE_SHORTDATE, ST, BYVAL %NULL, wszDate, SIZEOF(wszDate))
   FUNCTION = wszDate
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the current year.
' ========================================================================================
FUNCTION AfxYear () AS WORD
   LOCAL ST AS SYSTEMTIME
   GetLocalTime ST
   FUNCTION = ST.wYear
END FUNCTION
' ========================================================================================

' ========================================================================================
' Indicates whether the current date and time falls in the range of daylight saving time
' for the current time zone.
' ========================================================================================
FUNCTION AfxTimeZoneIsDaylightSavingTime () AS LONG
   LOCAL r AS LONG
   LOCAL tzi AS TIME_ZONE_INFORMATION
   r = GetTimeZoneInformation(tzi)
   IF r = %TIME_ZONE_ID_DAYLIGHT THEN FUNCTION = %TRUE
END FUNCTION
' ========================================================================================

' ========================================================================================
' Current bias for local time translation. The bias is the difference between Coordinated
' Universal Time (UTC) and local time. All translations between UTC and local time are
' based on the following formula: UTC = local time + bias. Units = minutes.
' ========================================================================================
FUNCTION AfxGetTimeZoneBias () AS LONG
   LOCAL r AS LONG
   LOCAL tzi AS TIME_ZONE_INFORMATION
   r = GetTimeZoneInformation(tzi)
   IF r = %TIME_ZONE_ID_INVALID THEN EXIT FUNCTION
   FUNCTION = tzi.Bias
END FUNCTION
' ========================================================================================

' ========================================================================================
' Bias value to be used during local time translations that occur during daylight saving
' time. This property is ignored if a value for the DaylightDay property is not supplied.
' The value of this property is added to the Bias property to form the bias used during
' daylight time. In most time zones, the value of this property is 60. Units = minutes.
' ========================================================================================
FUNCTION AfxGetTimeZoneDaylightBias () AS LONG
   LOCAL r AS LONG
   LOCAL tzi AS TIME_ZONE_INFORMATION
   r = GetTimeZoneInformation(tzi)
   IF r = %TIME_ZONE_ID_INVALID THEN EXIT FUNCTION
   FUNCTION = tzi.DaylightBias
END FUNCTION
' ========================================================================================

' ========================================================================================
' A description for standard time. For example, "EST" could indicate Eastern Standard Time.
' The string will be returned unchanged by the GetTimeZoneInformation function.
' This string can be empty.
' ========================================================================================
FUNCTION AfxGetTimeZoneStandardName () AS WSTRING
   LOCAL r AS LONG
   LOCAL tzi AS TIME_ZONE_INFORMATION
   r = GetTimeZoneInformation(tzi)
   IF r = %TIME_ZONE_ID_INVALID THEN EXIT FUNCTION
   FUNCTION = tzi.StandardName
END FUNCTION
' ========================================================================================

' ========================================================================================
' A description for daylight saving time. For example, "PDT" could indicate Pacific
' Daylight Time. The string will be returned unchanged by the GetTimeZoneInformation
' function. This string can be empty.
' ========================================================================================
FUNCTION AfxGetTimeZoneDaylightName () AS WSTRING
   LOCAL r AS LONG
   LOCAL tzi AS TIME_ZONE_INFORMATION
   r = GetTimeZoneInformation(tzi)
   IF r = %TIME_ZONE_ID_INVALID THEN EXIT FUNCTION
   FUNCTION = tzi.DaylightName
END FUNCTION
' ========================================================================================

' ========================================================================================
' DaylightDayOfWeek of the DaylightMonth when the transition from standard time to daylight
' saving time occurs on this operating system.
' Example: If the transition day (DaylightDayOfWeek) occurs on a Sunday, then the value
' "1" indicates the first Sunday of the DaylightMonth, "2" indicates the second Sunday,
' and so on. The value "5" indicates the last DaylightDayOfWeek in the month.
' ========================================================================================
FUNCTION AfxGetTimeZoneDaylightDay () AS LONG
   LOCAL r AS LONG
   LOCAL tzi AS TIME_ZONE_INFORMATION
   r = GetTimeZoneInformation(tzi)
   IF r = %TIME_ZONE_ID_INVALID THEN EXIT FUNCTION
   FUNCTION = tzi.DaylightDate.wDay
END FUNCTION
' ========================================================================================

' ========================================================================================
' Day of the week when the transition from standard time to daylight saving time occurs on
' an operating system. 0 = Sunday, 1 = Monday, and so on.
' ========================================================================================
FUNCTION AfxGetTimeZoneDaylightDayOfWeek () AS LONG
   LOCAL r AS LONG
   LOCAL tzi AS TIME_ZONE_INFORMATION
   r = GetTimeZoneInformation(tzi)
   IF r = %TIME_ZONE_ID_INVALID THEN EXIT FUNCTION
   FUNCTION = tzi.DaylightDate.wDayOfWeek
END FUNCTION
' ========================================================================================

' ========================================================================================
' Hour of the day when the transition from standard time to daylight saving time occurs on
' an operating system.
' ========================================================================================
FUNCTION AfxGetTimeZoneDaylightHour () AS LONG
   LOCAL r AS LONG
   LOCAL tzi AS TIME_ZONE_INFORMATION
   r = GetTimeZoneInformation(tzi)
   IF r = %TIME_ZONE_ID_INVALID THEN EXIT FUNCTION
   FUNCTION = tzi.DaylightDate.wHour
END FUNCTION
' ========================================================================================

' ========================================================================================
' Month when the transition from standard time to daylight saving time occurs on an
' operating system.
' ========================================================================================
FUNCTION AfxGetTimeZoneDaylightMonth () AS LONG
   LOCAL r AS LONG
   LOCAL tzi AS TIME_ZONE_INFORMATION
   r = GetTimeZoneInformation(tzi)
   IF r = %TIME_ZONE_ID_INVALID THEN EXIT FUNCTION
   FUNCTION = tzi.DaylightDate.wMonth
END FUNCTION
' ========================================================================================

' ========================================================================================
' Converts a DATE type to a string
' ========================================================================================
FUNCTION AfxVarDateToString (BYVAL vbDate AS DOUBLE, OPTIONAL BYVAL lcid AS DWORD) AS WSTRING
   LOCAL bstrOut AS WSTRING
   IF lcid = 0 THEN lcid = %LOCALE_USER_DEFAULT
   VarBstrFromDate(vbDate, lcid, %VAR_DATEVALUEONLY, bstrOut)
   FUNCTION = bstrOut
END FUNCTION
' ========================================================================================

' ========================================================================================
' Converts a DATE type to a string
' ========================================================================================
FUNCTION AfxVarTimeToString (BYVAL vbDate AS DOUBLE, OPTIONAL BYVAL lcid AS DWORD) AS WSTRING
   LOCAL bstrOut AS WSTRING
   IF lcid = 0 THEN lcid = %LOCALE_USER_DEFAULT
   VarBstrFromDate(vbDate, lcid, %VAR_TIMEVALUEONLY, bstrOut)
   FUNCTION = bstrOut
END FUNCTION
' ========================================================================================

' ========================================================================================
' Converts a DATE type to a string
' ========================================================================================
FUNCTION AfxVarDateTimeToString (BYVAL vbDate AS DOUBLE, OPTIONAL BYVAL lcid AS DWORD, BYVAL dwFlags AS DWORD) AS WSTRING
   LOCAL bstrOut AS WSTRING
   IF lcid = 0 THEN lcid = %LOCALE_USER_DEFAULT
   VarBstrFromDate(vbDate, lcid, dwFlags, bstrOut)
   FUNCTION = bstrOut
END FUNCTION
' ========================================================================================
