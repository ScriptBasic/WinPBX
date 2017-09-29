' ########################################################################################
' Microsoft Windows
' File: MonthCalCtrl.inc
' Contents: Month Calendar Control Wrapper Functions
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%MONTHCALCTRL_INC = 1

#INCLUDE ONCE "commctrl.inc"

' ========================================================================================
' Gets the border size, in pixels, of a month calendar control.
' ========================================================================================
FUNCTION MonthCal_GetCalendarBorder (BYVAL hmc AS DWORD) AS DWORD
   FUNCTION = SendMessage(hmc, %MCM_GETCALENDARBORDER, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the number of calendars currently displayed in the calendar control.
' ========================================================================================
FUNCTION MonthCal_GetCalendarCount (BYVAL hmc AS DWORD) AS DWORD
   FUNCTION = SendMessage(hmc, %MCM_GETCALENDARCOUNT, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets information about a calendar grid.
' ========================================================================================
FUNCTION MonthCal_GetCalendarGridInfo (BYVAL hmc AS DWORD, BYREF pmcGridInfo AS MCGRIDINFO) AS LONG
   FUNCTION = SendMessage(hmc, %MCM_GETCALENDARGRIDINFO, 0, VARPTR(pmcGridInfo))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the current calendar ID for the given calendar control.
' ========================================================================================
FUNCTION MonthCal_GetCALID (BYVAL hmc AS DWORD) AS DWORD
   FUNCTION = SendMessage(hmc, %MCM_GETCALID, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the color for a given portion of a month calendar control.
' ========================================================================================
FUNCTION MonthCal_GetColor (BYVAL hmc AS DWORD, BYVAL iColor AS DWORD) AS DWORD
   FUNCTION = SendMessage(hmc, %MCM_GETCOLOR, iColor, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the view for a month calendar control.
' ========================================================================================
FUNCTION MonthCal_GetCurrentView (BYVAL hmc AS DWORD) AS DWORD
   FUNCTION = SendMessage(hmc, %MCM_GETCURRENTVIEW, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the currently selected date.
' ========================================================================================
FUNCTION MonthCal_GetCurSel (BYVAL hmc AS DWORD, BYREF lpSysTime AS SYSTEMTIME) AS LONG
   FUNCTION = SendMessage(hmc, %MCM_GETCURSEL, 0, VARPTR(lpSysTime))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the first day of the week for a month calendar control.
' ========================================================================================
FUNCTION MonthCal_GetFirstDayOfWeek (BYVAL hmc AS DWORD) AS DWORD
   FUNCTION = SendMessage(hmc, %MCM_GETFIRSTDAYOFWEEK, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the maximum date range that can be selected in a month calendar control.
' ========================================================================================
FUNCTION MonthCal_GetMaxSelCount (BYVAL hmc AS DWORD) AS DWORD
   FUNCTION = SendMessage(hmc, %MCM_GETMAXSELCOUNT, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the maximum width of the "today" string in a month calendar control.
' ========================================================================================
FUNCTION MonthCal_GetMaxTodayWidth (BYVAL hmc AS DWORD) AS DWORD
   FUNCTION = SendMessage(hmc, %MCM_GETMAXTODAYWIDTH, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the maximum width of the "today" string in a month calendar control.
' ========================================================================================
FUNCTION MonthCal_GetMinReqRect (BYVAL hmc AS DWORD, BYREF lpRectInfo AS RECT) AS LONG
   FUNCTION = SendMessage(hmc, %MCM_GETMINREQRECT, 0, VARPTR(lpRectInfo))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the scroll rate for a month calendar control. The scroll rate is the number of
' months that the control moves its display when the user clicks a scroll button.
' ========================================================================================
FUNCTION MonthCal_GetMonthDelta (BYVAL hmc AS DWORD) AS LONG
   FUNCTION = SendMessage(hmc, %MCM_GETMONTHDELTA, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves date information (using SYSTEMTIME structures) that represents the high and
' low limits of a month calendar control's display.
' ========================================================================================
FUNCTION MonthCal_GetMonthRange (BYVAL hmc AS DWORD, BYVAL dwFlag AS DWORD, BYREF lprgSysTimeArray AS SYSTEMTIME) AS LONG
   FUNCTION = SendMessage(hmc, %MCM_GETMONTHRANGE, dwFlag, VARPTR(lprgSysTimeArray))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the minimum and maximum allowable dates set for a month calendar control.
' ========================================================================================
FUNCTION MonthCal_GetRange (BYVAL hmc AS DWORD, BYREF lprgSysTimeArray AS SYSTEMTIME) AS DWORD
   FUNCTION = SendMessage(hmc, %MCM_GETRANGE, 0, VARPTR(lprgSysTimeArray))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves date information that represents the upper and lower limits of the date range
' currently selected by the user.
' ========================================================================================
FUNCTION MonthCal_GetSelRange (BYVAL hmc AS DWORD, BYREF lprgSysTimeArray AS SYSTEMTIME) AS LONG
   FUNCTION = SendMessage(hmc, %MCM_GETSELRANGE, 0, VARPTR(lprgSysTimeArray))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the date information for the date specified as "today" for a month calendar control.
' ========================================================================================
FUNCTION MonthCal_GetToday (BYVAL hmc AS DWORD, BYREF lpToday AS SYSTEMTIME) AS LONG
   FUNCTION = SendMessage(hmc, %MCM_GETTODAY, 0, VARPTR(lpToday))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the Unicode character format flag for the control.
' ========================================================================================
FUNCTION MonthCal_GetUnicodeFormat (BYVAL hmc AS DWORD) AS LONG
   FUNCTION = SendMessage(hmc, %MCM_GETUNICODEFORMAT, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Determines which portion of a month calendar control is at a given point on the screen.
' ========================================================================================
FUNCTION MonthCal_HitTest (BYVAL hmc AS DWORD, BYREF pMCHitTest AS MCHITTESTINFO) AS DWORD
   FUNCTION = SendMessage(hmc, %MCM_HITTEST, 0, VARPTR(pMCHitTest))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the border size, in pixels, of a month calendar control.
' ========================================================================================
FUNCTION MonthCal_SetCalendarBorder (BYVAL hmc AS DWORD, BYVAL fset AS LONG, BYVAL xyborder AS LONG) AS LONG
   FUNCTION = SendMessage(hmc, %MCM_SETCALENDARBORDER, fset, xyborder)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the calendar ID for the given calendar control.
' ========================================================================================
FUNCTION MonthCal_SetCALID (BYVAL hmc AS DWORD, BYVAL calid AS DWORD) AS DWORD
   FUNCTION = SendMessage(hmc, %MCM_SETCALID, calid, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the color for a given portion of a month calendar control.
' ========================================================================================
FUNCTION MonthCal_SetColor (BYVAL hmc AS DWORD, BYVAL iColor AS DWORD, BYVAL clr AS DWORD) AS LONG
   FUNCTION = SendMessage(hmc, %MCM_SETCOLOR, iColor, clr)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the view for a month calendar control.
' ========================================================================================
FUNCTION MonthCal_SetCurrentView (BYVAL hmc AS DWORD, BYVAL dwNewView AS DWORD) AS LONG
   FUNCTION = SendMessage(hmc, %MCM_SETCURRENTVIEW, 0, dwNewView)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the currently selected date for a month calendar control. If the specified date is
' not in view, the control updates the display to bring it into view.
' ========================================================================================
FUNCTION MonthCal_SetCurSel (BYVAL hmc AS DWORD, BYREF lpSysTime AS SYSTEMTIME) AS LONG
   FUNCTION = SendMessage(hmc, %MCM_SETCURSEL, 0, VARPTR(lpSysTime))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the day states for all months that are currently visible within a month calendar control.
' ========================================================================================
FUNCTION MonthCal_SetDayState (BYVAL hmc AS DWORD, BYVAL iMonths AS LONG, BYREF lpDayStateArray AS DWORD) AS LONG
   FUNCTION = SendMessage(hmc, %MCM_SETDAYSTATE, iMonths, VARPTR(lpDayStateArray))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the first day of the week for a month calendar control.
' ========================================================================================
FUNCTION MonthCal_SetFirstDayOfWeek (BYVAL hmc AS DWORD, BYVAL iDay AS LONG) AS DWORD
   FUNCTION = SendMessage(hmc, %MCM_SETFIRSTDAYOFWEEK, 0, iDay)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the maximum number of days that can be selected in a month calendar control.
' ========================================================================================
FUNCTION MonthCal_SetMaxSelCount (BYVAL hmc AS DWORD, BYVAL iMax AS DWORD) AS LONG
   FUNCTION = SendMessage(hmc, %MCM_SETMAXSELCOUNT, iMax, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the scroll rate for a month calendar control. The scroll rate is the number of
' months that the control moves its display when the user clicks a scroll button.
' ========================================================================================
FUNCTION MonthCal_SetMonthDelta (BYVAL hmc AS DWORD, BYVAL iDelta AS LONG) AS LONG
   FUNCTION = SendMessage(hmc, %MCM_SETMONTHDELTA, iDelta, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the minimum and maximum allowable dates for a month calendar control.
' ========================================================================================
FUNCTION MonthCal_SetRange (BYVAL hmc AS DWORD, BYVAL fWhichLimit AS DWORD, BYREF lprgSysTimeArray AS SYSTEMTIME) AS LONG
   FUNCTION = SendMessage(hmc, %MCM_SETRANGE, fWhichLimit, VARPTR(lprgSysTimeArray))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the selection for a month calendar control to a given date range.
' ========================================================================================
FUNCTION MonthCal_SetSelRange (BYVAL hmc AS DWORD, BYREF lprgSysTimeArray AS SYSTEMTIME) AS LONG
   FUNCTION = SendMessage(hmc, %MCM_SETSELRANGE, 0, VARPTR(lprgSysTimeArray))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the "today" selection for a month calendar control.
' ========================================================================================
SUB MonthCal_SetToday (BYVAL hmc AS DWORD, BYREF lpSysTime AS SYSTEMTIME)
   SendMessage hmc, %MCM_SETTODAY, 0, VARPTR(lpSysTime)
END SUB
' ========================================================================================

' ========================================================================================
' Sets the Unicode character format flag for the control. This message allows you to
' change the character set used by the control at run time rather than having to re-create
' the control.
' ========================================================================================
FUNCTION MonthCal_SetUnicodeFormat (BYVAL hmc AS DWORD, BYVAL fUnicode AS DWORD) AS LONG
   FUNCTION = SendMessage(hmc, %MCM_SETUNICODEFORMAT, fUnicode, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Calculates how many calendars will fit in the given rectangle, and then returns the
' minimum size that a rectangle needs to be to fit that number of calendars.
' ========================================================================================
FUNCTION MonthCal_SizeRectToMin (BYVAL hmc AS DWORD, BYREF prc AS RECT) AS LONG
   FUNCTION = SendMessage(hmc, %MCM_SIZERECTTOMIN, 0, VARPTR(prc))
END FUNCTION
' ========================================================================================
