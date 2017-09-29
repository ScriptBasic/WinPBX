' ########################################################################################
' Microsoft Windows
' File: CAfxTime.inc
' Contents: Date-time class. Inherits from IPowerTime.
' Copyright (c) 2011 José Roca.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%CAFXTIME_INC = 1

#INCLUDE ONCE "windows.inc"
#INCLUDE ONCE "AfxTime.inc"

' ########################################################################################
' CAfxTime class.
' ########################################################################################
CLASS CAfxTime

   INSTANCE m_pTime AS IPowerTime

   ' =====================================================================================
   ' Create method
   ' =====================================================================================
   CLASS METHOD Create
      m_pTime = CLASS "PowerTime"
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Destroy method
   ' =====================================================================================
   CLASS METHOD Destroy
      m_pTime = NOTHING
   END METHOD
   ' =====================================================================================

   INTERFACE IAfxTime : INHERIT IAutomation

   ' *************************************************************************************
   '                             *** IPowerTime methods ***
   ' *************************************************************************************

   ' =====================================================================================
   ' Adds the specified number of days to the value of this object.
   ' You can subtract days by using a negative number.
   ' =====================================================================================
   METHOD AddDays (BYVAL Days AS LONG)
      m_pTime.AddDays(Days)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Adds the specified number of hours to the value of this object.
   ' You can subtract hours by using a negative number.
   ' =====================================================================================
   METHOD AddHours (BYVAL Hours AS LONG)
      m_pTime.AddHours(Hours)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Adds the specified number of minutes to the value of this object.
   ' You can subtract minutes by using a negative number.
   ' =====================================================================================
   METHOD AddMinutes (BYVAL Minutes AS LONG)
      m_pTime.AddMinutes(Minutes)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Adds the specified number of months to the value of this object.
   ' You can subtract months by using a negative number.
   ' =====================================================================================
   METHOD AddMonths (BYVAL Months AS LONG)
      m_pTime.AddMonths(Months)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Adds the specified number of milliseconds to the value of this object.
   ' You can subtract milliseconds by using a negative number.
   ' =====================================================================================
   METHOD AddMSeconds (BYVAL Milliseconds AS LONG)
      m_pTime.AddMSeconds(Milliseconds)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Adds the specified number of seconds to the value of this object.
   ' You can subtract seconds by using a negative number.
   ' =====================================================================================
   METHOD AddSeconds (BYVAL Seconds AS LONG)
      m_pTime.AddSeconds(Seconds)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Adds the specified number of ticks to the value of this object.
   ' You can subtract ticks by using a negative number.
   ' =====================================================================================
   METHOD AddTicks (BYVAL Ticks AS LONG)
      m_pTime.AddTicks(Ticks)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Adds the specified number of years to the value of this object.
   ' You can subtract years by using a negative number.
   ' =====================================================================================
   METHOD AddYears (BYVAL Years AS LONG)
      m_pTime.AddYears(Years)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' The date part of the internal PowerTime object is compared to the date part of the
   ' specified external PowerTime object. The time-of-day part of each is ignored.
   ' The difference is assigned to the parameter variables you provide. Sign is -1 if the
   ' internal value is smaller. Sign is 0 if the values are equal. Sign is +1 if the
   ' internal value is larger. The other parameters tell the difference as positive
   ' integer values. If parameters are invalid, an appropriate error code is returned
   ' in OBJRESULT.
   ' =====================================================================================
   METHOD DateDiff (BYVAL pTime AS IPowerTime, BYREF Sign AS LONG, BYREF Years AS LONG, BYREF Months AS LONG, BYREF Days AS LONG)
      m_pTime.DateDiff(pTime, Sign, Years, Months, Days)
      IF OBJRESULT THEN METHOD OBJRESULT = OBJRESULT
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns the Date component of the PowerTime object expressed as a string. The date is
   ' formatted for the locale, based upon the LCID parameter. If LCID is zero, or not
   ' given, the default LCID for the user is substituted.
   ' =====================================================================================
   METHOD DateString (BYVAL OPTIONAL LCID AS LONG) AS STRING
      METHOD = m_pTime.DateString(LCID)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns the Date component of the PowerTime object, expressed as a string, with a
   ' full alphabetic month name. The date is formatted for the locale, based upon the
   ' LCID parameter. If LCID is zero, or not given, the default LCID for the user is substituted.
   ' =====================================================================================
   METHOD DateStringLong (BYVAL OPTIONAL LCID AS LONG) AS WSTRING
      METHOD = m_pTime.DateStringLong(LCID)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns the Day component of the PowerTime object. It is a  value in the range of 1-31.
   ' =====================================================================================
   METHOD Day () AS LONG
      METHOD = m_pTime.Day
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns the Day-of-Week component of the PowerTime object. It is a numeric value in
   ' the range of 0-6 (representing Sunday through Saturday).
   ' =====================================================================================
   METHOD DayOfWeek () AS LONG
      METHOD = m_pTime.DayOfWeek
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns the Day-of-Week name of the PowerTime object, expressed as a string (Sunday,
   ' Monday...).  The day name is appropriate for the locale, based upon the LCID parameter.
   ' If LCID is zero, or not given, the default LCID for the user is substituted.
   ' =====================================================================================
   METHOD DayOfWeekString (OPTIONAL BYVAL LCID AS LONG) AS WSTRING
      METHOD = m_pTime.DayOfWeekString
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns the number of days which comprise the month of the date of the PowerTime object.
   ' This is a numeric value in the range of 28-31.
   ' =====================================================================================
   METHOD DaysInMonth () AS LONG
      METHOD = m_pTime.DaysInMonth
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns a Quad-Integer value of the PowerTime object as a FileTime.
   ' =====================================================================================
   PROPERTY GET FileTime () AS QUAD
      PROPERTY = m_pTime.FileTime
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' The FileTime Quad-Integer value specified by the parameter is assigned as the PowerTime object value.
   ' =====================================================================================
   PROPERTY SET FileTime (BYVAL qFileTime AS QUAD)
      m_pTime.FileTime = qFileTime
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Returns the Hour component of the PowerTime object. It is a numeric value in the range of 0-23.
   ' =====================================================================================
   METHOD Hour () AS LONG
      METHOD = m_pTime.Hour
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns true/false (-1/0) to tell if the PowerTime object year is a leap year.
   ' =====================================================================================
   METHOD IsLeapYear () AS LONG
      METHOD = m_pTime.IsLeapYear
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns the Minute component of the PowerTime object. This is a numeric value in the range of 0-59.
   ' =====================================================================================
   METHOD Minute () AS LONG
      METHOD = m_pTime.Minute
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns the Month component of the PowerTime object. This is a numeric value in the range of 1-12.
   ' =====================================================================================
   METHOD Month () AS LONG
      METHOD = m_pTime.Month
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns the Month component of the PowerTime object, expressed as a string (January, February...).
   ' =====================================================================================
   METHOD MonthString () AS STRING
      METHOD = m_pTime.MonthString
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns the millisecond component of the PowerTime object.
   ' This is a numeric value in the range of 0-999.
   ' =====================================================================================
   METHOD MSecond () AS LONG
      METHOD = m_pTime.MSecond
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' The date component of the PowerTime object is assigned a new value based upon the
   ' specified parameters. The time component is unchanged. If parameters are invalid, an
   ' appropriate error code is returned in OBJRESULT.
   ' =====================================================================================
   METHOD NewDate (BYVAL Year AS LONG, OPTIONAL BYVAL Month AS LONG, BYVAL Day AS LONG) AS LONG
      m_pTime.NewDate(Year, Month, Day)
      IF OBJRESULT THEN METHOD OBJRESULT = OBJRESULT
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' The time component of the PowerTime object is assigned a new value based upon the
   ' specified parameters. The date component is unchanged. If parameters are invalid, an
   ' appropriate error code is returned in OBJRESULT.
   ' =====================================================================================
   METHOD NewTime (BYVAL Hour AS LONG, OPTIONAL BYVAL Minute AS LONG, BYVAL Second AS LONG, BYVAL MSecond AS LONG, BYVAL Tick AS LONG) AS LONG
      m_pTime.NewTime(Hour, Minute, Second, MSecond, Tick)
      IF OBJRESULT THEN METHOD OBJRESULT = OBJRESULT
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' The current local date and time on this computer is assigned to this PowerTime object.
   ' =====================================================================================
   METHOD Now
      m_pTime.Now
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' The current Coordinated Universal date and time (UTC) is assigned to this PowerTime object.
   ' =====================================================================================
   METHOD NowUTC
      m_pTime.NowUTC
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns the Second component of the PowerTime object. This is a numeric value in the range of 0-59.
   ' =====================================================================================
   METHOD Second () AS LONG
      METHOD = m_pTime.Second
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns the Tick component of the PowerTime object. This is a numeric value in the range of 0-999.
   ' =====================================================================================
   METHOD Tick () AS LONG
      METHOD = m_pTime.Tick
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' The internal PowerTime object is compared to the specified external PowerTime object.
   ' The difference is assigned to the parameter variables you provide. Sign is -1 if the
   ' internal value is smaller. Sign is 0 if the values are equal. Sign is +1 if the
   ' internal value is larger. The other parameters tell the difference as positive
   ' integer values. If you wish to return the time difference in units smaller than days,
   ' fill the unwanted parameters with BYVAL 0 and they will be ignored. For example:
   ' ThisObject.TimeDiff(ThatObject, Sign, BYVAL 0, BYVAL 0, Minutes)
   ' In the above, if the difference was precisely one day, the value 1440 would be
   ' assigned to Minutes (24 hours * 60 minutes). If parameters are invalid, an
   ' appropriate error code is returned in OBJRESULT.
   ' =====================================================================================
   METHOD TimeDiff (BYVAL pTime AS IPowerTime, BYREF Sign AS LONG, BYREF Days AS LONG, OPTIONAL BYREF Hours AS LONG, BYREF Minutes AS LONG, BYREF Seconds AS LONG, BYREF MSeconds AS QUAD, BYREF Ticks AS QUAD)
      m_pTime.TimeDiff(pTime, Sign, Days, Hours, Minutes, Seconds, MSeconds, Ticks)
      IF OBJRESULT THEN METHOD OBJRESULT = OBJRESULT
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns the Time component of the PowerTime object expressed as a string.
   ' The time is formatted as hh:mm AM/PM.
   ' =====================================================================================
   METHOD TimeString () AS STRING
      METHOD = m_pTime.TimeString
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns the Time component of the PowerTime object expressed as a string.
   ' The time is formatted as hh:mm in 24-hour notation.
   ' =====================================================================================
   METHOD TimeString24 () AS STRING
      METHOD = m_pTime.TimeString24
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns the Time component of the PowerTime object expressed as a string.
   ' The time is formatted as hh:mm:ss.mmm in 24-hour notation.
   ' =====================================================================================
   METHOD TimeStringFull () AS WSTRING
      METHOD = m_pTime.TimeStringFull
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' The current local date on this computer is assigned to this PowerTime object.
   ' This is suitable for applications that work with dates only.
   ' =====================================================================================
   METHOD Today
      m_pTime.Today
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' The PowerTime object is converted to local time. It is assumed that the previous
   ' value was in Coordinated Universal Time (UTC).
   ' =====================================================================================
   METHOD ToLocalTime
      m_pTime.ToLocalTime
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' The PowerTime object is converted to Coordinated Universal Time (UTC). It is assumed
   ' that previous value was in local time.
   ' =====================================================================================
   METHOD ToUTC
      m_pTime.ToUTC
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns the Year component of the PowerTime object as a numeric value.
   ' =====================================================================================
   METHOD Year () AS LONG
      METHOD = m_pTime.Year
   END METHOD
   ' =====================================================================================

   ' *************************************************************************************
   '                             *** Additional methods ***
   ' *************************************************************************************

   ' ========================================================================================
   ' Returns a reference to the IPowerTime interface.
   ' ========================================================================================
   PROPERTY GET PowerTime () AS IPowerTime
      PROPERTY = m_pTime
   END PROPERTY
   ' ========================================================================================

   ' ========================================================================================
   ' Returns the Date component of the PowerTime object expressed as a fotmatted time string.
   ' The time is formatted according the supplied mask. For example, to get the date string
   ' "Wed, Aug 31 94" use the following picture string: "'ddd',' MMM dd yy".
   ' See http://msdn.microsoft.com/en-us/library/dd317787%28VS.85%29.aspx for possible values.
   ' ========================================================================================
   METHOD DateFormat (BYVAL bstrMask AS WSTRING, OPTIONAL BYVAL LCID AS LONG) AS WSTRING
      LOCAL ST AS SYSTEMTIME, FT AS FILETIME
      LOCAL wszDate AS WSTRINGZ * 260
      FT.qDateTime = m_pTime.FileTime
      FileTimeToSystemTime(FT, ST)
      IF LCID = 0 THEN LCID = %LOCALE_USER_DEFAULT
      GetDateFormatW(LCID, %NULL, ST, BYCOPY bstrMask, wszDate, SIZEOF(wszDate))
      METHOD = wszDate
   END METHOD
   ' ========================================================================================

   ' ========================================================================================
   ' Returns the Time component of the PowerTime object expressed as a fotmatted time string.
   ' The time is formatted according the supplied mask, e.g. "hh':'mm':'ss tt".
   ' See http://msdn.microsoft.com/en-us/library/dd318131%28VS.85%29.aspx for possible values.
   ' ========================================================================================
   METHOD TimeFormat (BYVAL bstrMask AS WSTRING, OPTIONAL BYVAL LCID AS LONG) AS WSTRING
      LOCAL ST AS SYSTEMTIME, FT AS FILETIME
      LOCAL wszTime AS WSTRINGZ * 260
      FT.qDateTime = m_pTime.FileTime
      FileTimeToSystemTime(FT, ST)
      IF LCID = 0 THEN LCID = %LOCALE_USER_DEFAULT
      GetTimeFormatW(LCID, %NULL, ST, BYCOPY bstrMask, wszTime, SIZEOF(wszTime))
      METHOD = wszTime
   END METHOD
   ' ========================================================================================

   ' =====================================================================================
   ' Returns the number of days of the year.
   ' =====================================================================================
   METHOD DaysInYear () AS LONG
      IF m_pTime.IsLeapYear THEN METHOD = 366 ELSE METHOD = 365
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' True (-1) if the date is on the first of a month; False (0), otherwise.
   ' =====================================================================================
   METHOD IsFirstOfMonth () AS LONG
      IF m_pTime.Day = 1 THEN METHOD = -1
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' True (-1) if the date is the last day of the month; False (0), otherwise.
   ' =====================================================================================
   METHOD IsLastOfMonth () AS LONG
      IF m_pTime.Day = m_pTime.DaysInMonth THEN METHOD = -1
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns the astronomical day of the PowerTime object as a numeric value.
   ' =====================================================================================
   METHOD ToAstroDay () AS LONG
      LOCAL y AS DOUBLE, nYear, nDay, nMonth AS LONG
      nYear = m_pTime.Year
      nDay = m_pTime.Day
      nMonth = m_pTime.Month
      y = nYear + (nMonth - 2.85) / 12
      METHOD = INT(INT(INT(367 * y) - 1.75 * INT(y) + nDay) - 0.75 * INT(0.01 * y)) + 1721116
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns the julian representation of the PowerTime object as a numeric value.
   ' =====================================================================================
   METHOD ToJulian () AS LONG
      LOCAL y AS DOUBLE, nYear, nDay, nMonth AS LONG
      LOCAL DaysElapsed, InvalidLeapYears, ValidLeapYears, DaysOfMonths AS LONG
      nYear = m_pTime.Year
      nDay = m_pTime.Day
      nMonth = m_pTime.Month
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
      METHOD = DaysElapsed - InvalidLeapYears + ValidLeapYears + DaysOfMonths + nDay
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' The date component of the PowerTime object is assigned a new value based upon the
   ' specified julian date. If the date is invalid, an appropriate error code is returned in OBJRESULT.
   ' Returns True/False (-1/0).
   ' =====================================================================================
   METHOD FromJulian (BYVAL nJulian AS LONG) AS LONG
      LOCAL wDay, wMonth, wYear AS WORD
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
      LOCAL ST AS SYSTEMTIME, FT AS FILETIME
      ST.wYear = wYear : ST.wMonth = wMonth : ST.wDay = wDay
      IF SystemTimeToFileTime(ST, FT) = 0 THEN EXIT METHOD
      ME.FileTime = FT.qDateTime
      METHOD = -1
   END METHOD
   ' ======================================================================================

   ' =====================================================================================
   ' Returns the day of the year of the PowerTime object, where Jan 1 is the first day of the year.
   ' =====================================================================================
   METHOD DayOfYear () AS LONG
      METHOD = AfxGetDayOfYear(m_pTime.Day, m_pTime.Month, m_pTime.Year)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns the week number for the PowerTime object.
   ' =====================================================================================
   METHOD WeekNumber () AS LONG
      METHOD = AfxWeekNumber(m_pTime.Day, m_pTime.Month, m_pTime.Year)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns the number of weeks of the PowerTime object year, where weeks are taken to
   ' start on Monday. Will be 52 or 53.
   ' =====================================================================================
   METHOD WeeksInYear () AS LONG
      METHOD = AfxWeeksInYear(m_pTime.Year)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns the number of weeks of the PowerTime object month.
   ' =====================================================================================
   METHOD WeeksInMonth () AS LONG
      LOCAL wod AS LONG
      wod = AfxAstroDayOfWeek(1, m_pTime.Month, m_pTime.Year) - 1
      IF wod = -1 THEN wod = 6
      METHOD = (m_pTime.DaysInMonth + wod) \ 7
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Initializes a PowerTime object from string.
   ' =====================================================================================
   METHOD FromString (BYVAL bstrDate AS WSTRING, OPTIONAL BYVAL LCID AS LONG, BYVAL dwFlags AS DWORD)
      LOCAL hr AS LONG, vbDate AS DOUBLE, ST AS SYSTEMTIME, FT AS FILETIME
      hr = VarDateFromStr(BYCOPY bstrDate, LCID, dwFlags, vbDate)
      IF hr THEN METHOD OBJRESULT = hr : EXIT METHOD
      IF VariantTimeToSystemTime(vbDate, ST) = %FALSE THEN METHOD OBJRESULT = %E_FAIL : EXIT METHOD
      IF SystemTimeToFileTime(ST, FT) = 0 THEN METHOD OBJRESULT = %E_FAIL : EXIT METHOD
      ME.FileTime = FT.qDateTime
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Initializes a PowerTime object from a FILETIME structure.
   ' =====================================================================================
   METHOD FromFileTimeStruct (BYREF FT AS FILETIME)
      ME.FileTime = FT.qDateTime
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Initializes a PowerTime object from a SYSTEMTIME structure.
   ' Returns True/False (-1/0).
   ' =====================================================================================
   METHOD FromSystemTime (BYREF ST AS SYSTEMTIME) AS LONG
      LOCAL FT AS FILETIME
      IF SystemTimeToFileTime(ST, FT) = 0 THEN EXIT METHOD
      ME.FileTime = FT.qDateTime
      METHOD = -1
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Initializes a PowerTime object from a variant representation of time.
   ' Returns True/False (-1/0).
   ' =====================================================================================
   METHOD FromVariantDate (BYVAL vbDate AS DOUBLE) AS LONG
      LOCAL ST AS SYSTEMTIME, FT AS FILETIME
      IF VariantTimeToSystemTime(vbDate, ST) = %FALSE THEN EXIT METHOD
      IF SystemTimeToFileTime(ST, FT) = 0 THEN EXIT METHOD
      ME.FileTime = FT.qDateTime
      METHOD = -1
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Initializes a PowerTime object from a VT_DATE variant.
   ' Returns True/False (-1/0).
   ' =====================================================================================
   METHOD FromVarDate (BYVAL vDate AS VARIANT) AS LONG
      LOCAL vbDate AS DOUBLE, ST AS SYSTEMTIME, FT AS FILETIME
      IF VARIANTVT(vDate) <> %VT_DATE THEN EXIT METHOD
      vbDate = VARIANT#(vDate)
      IF VariantTimeToSystemTime(vbDate, ST) = %FALSE THEN EXIT METHOD
      IF SystemTimeToFileTime(ST, FT) = 0 THEN EXIT METHOD
      ME.FileTime = FT.qDateTime
      METHOD = -1
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Converts the PowerTime object to a variant representation of time.
   ' =====================================================================================
   METHOD ToVariantDate () AS DOUBLE
      LOCAL ST AS SYSTEMTIME, vbDate AS DOUBLE
      ST.wYear = m_pTime.Year : ST.wMonth = m_pTime.Month : ST.wDayOfWeek = m_pTime.DayOfWeek : ST.wDay = m_pTime.Day
      ST.wHour = m_pTime.Hour : ST.wMinute = m_pTime.Minute : ST.wSecond = m_pTime.Second : ST.wMilliseconds = m_pTime.MSecond
      SystemTimeToVariantTime(ST, vbDate)
      METHOD = vbDate
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Converts the PowerTime object to a VARIANT of type VT_DATE.
   ' =====================================================================================
   METHOD ToVarDate () AS VARIANT
      LOCAL ST AS SYSTEMTIME, vbDate AS DOUBLE, vDate AS VARIANT, pv AS tagVARIANT PTR
      ST.wYear = m_pTime.Year : ST.wMonth = m_pTime.Month : ST.wDayOfWeek = m_pTime.DayOfWeek : ST.wDay = m_pTime.Day
      ST.wHour = m_pTime.Hour : ST.wMinute = m_pTime.Minute : ST.wSecond = m_pTime.Second : ST.wMilliseconds = m_pTime.MSecond
      IF SystemTimeToVariantTime(ST, vbDate) = %FALSE THEN EXIT METHOD
      pv = VARPTR(vDate)
      @pv.vt = %VT_DATE
      @pv.date = vbDate
      METHOD = vDate
   END METHOD
   ' =====================================================================================

   END INTERFACE
   ' =====================================================================================

END CLASS
' ########################################################################################

' ========================================================================================
' Creates an instance of the class.
' ========================================================================================
FUNCTION NewAfxTime () AS IAfxTime
   LOCAL pTime AS IAfxTime
   pTime = CLASS "CAfxTime"
   FUNCTION = pTime
END FUNCTION
' ========================================================================================
