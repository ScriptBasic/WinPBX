' ########################################################################################
' Microsoft Windows
' File: TrackbarCtrl.inc
' Contents: Trackbar Control Wrapper Functions
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%TRACKBARCTRL_INC = 1

#INCLUDE ONCE "commctrl.inc"

' ========================================================================================
' Clears the current selection range in a trackbar.
' ========================================================================================
SUB Trackbar_ClearSel (BYVAL hTrackbar AS DWORD, BYVAL fRedraw AS DWORD)
   SendMessage hTrackbar, %TBM_CLEARSEL, fRedraw, 0
END SUB
' ========================================================================================

' ========================================================================================
' Removes the current tick marks from a trackbar. This message does not remove the first
' and last tick marks, which are created automatically by the trackbar.
' ========================================================================================
SUB Trackbar_ClearTics (BYVAL hTrackbar AS DWORD, BYVAL fRedraw AS DWORD)
   SendMessage hTrackbar, %TBM_CLEARTICS, fRedraw, 0
END SUB
' ========================================================================================

' ========================================================================================
' Retrieves the handle to a trackbar control buddy window at a given location.
' The specified location is relative to the control's orientation (horizontal or vertical).
' ========================================================================================
FUNCTION Trackbar_GetBuddy (BYVAL hTrackbar AS DWORD, BYVAL fLocation AS DWORD) AS DWORD
   FUNCTION = SendMessage(hTrackbar, %TBM_GETBUDDY, fLocation, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the size and position of the bounding rectangle for a trackbar's channel.
' (The channel is the area over which the slider moves. It contains the highlight when a
' range is selected.)
' ========================================================================================
SUB Trackbar_GetChannelRect (BYVAL hTrackbar AS DWORD, BYREF lprc AS RECT)
   SendMessage hTrackbar, %TBM_GETCHANNELRECT, 0, VARPTR(lprc)
END SUB
' ========================================================================================

' ========================================================================================
' Retrieves the number of logical positions the trackbar's slider moves in response to
' keyboard input from the arrow keys, such as the or keys. The logical positions are the
' integer increments in the trackbar's range of minimum to maximum slider positions.
' ========================================================================================
FUNCTION Trackbar_GetLineSize (BYVAL hTrackbar AS DWORD) AS LONG
   FUNCTION = SendMessage (hTrackbar, %TBM_GETLINESIZE, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the number of tick marks in a trackbar.
' ========================================================================================
FUNCTION Trackbar_GetNumTics (BYVAL hTrackbar AS DWORD) AS LONG
   FUNCTION = SendMessage (hTrackbar, %TBM_GETNUMTICS, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the number of logical positions the trackbar's slider moves in response to
' keyboard input, such as the or keys, or mouse input, such as clicks in the trackbar's
' channel. The logical positions are the integer increments in the trackbar's range of
' minimum to maximum slider positions.
' ========================================================================================
FUNCTION Trackbar_GetPageSize (BYVAL hTrackbar AS DWORD) AS LONG
   FUNCTION = SendMessage (hTrackbar, %TBM_GETPAGESIZE, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the current logical position of the slider in a trackbar. The logical positions
' are the integer values in the trackbar's range of minimum to maximum slider positions.
' ========================================================================================
FUNCTION Trackbar_GetPos (BYVAL hTrackbar AS DWORD) AS LONG
   FUNCTION = SendMessage (hTrackbar, %TBM_GETPOS, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the address of an array that contains the positions of the tick marks for a trackbar.
' ========================================================================================
FUNCTION Trackbar_GetPTics (BYVAL hTrackbar AS DWORD) AS DWORD
   FUNCTION = SendMessage (hTrackbar, %TBM_GETPTICS, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the maximum position for the slider in a trackbar.
' ========================================================================================
FUNCTION Trackbar_GetRangeMax (BYVAL hTrackbar AS DWORD) AS LONG
   FUNCTION = SendMessage (hTrackbar, %TBM_GETRANGEMAX, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the maximum position for the slider in a trackbar.
' ========================================================================================
FUNCTION Trackbar_GetRangeMin (BYVAL hTrackbar AS DWORD) AS LONG
   FUNCTION = SendMessage (hTrackbar, %TBM_GETRANGEMIN, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the ending position of the current selection range in a trackbar.
' ========================================================================================
FUNCTION Trackbar_GetSelEnd (BYVAL hTrackbar AS DWORD) AS LONG
   FUNCTION = SendMessage (hTrackbar, %TBM_GETSELEND, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the starting position of the current selection range in a trackbar.
' ========================================================================================
FUNCTION Trackbar_GetSelStart (BYVAL hTrackbar AS DWORD) AS LONG
   FUNCTION = SendMessage (hTrackbar, %TBM_GETSELSTART, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the length of the slider in a trackbar.
' ========================================================================================
FUNCTION Trackbar_GetThumbLength (BYVAL hTrackbar AS DWORD) AS LONG
   FUNCTION = SendMessage (hTrackbar, %TBM_GETTHUMBLENGTH, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the length of the slider in a trackbar.
' ========================================================================================
SUB Trackbar_GetThumbRect (BYVAL hTrackbar AS DWORD, BYREF lprc AS RECT)
   SendMessage hTrackbar, %TBM_GETTHUMBRECT, 0, VARPTR(lprc)
END SUB
' ========================================================================================

' ========================================================================================
' Retrieves the length of the slider in a trackbar.
' ========================================================================================
FUNCTION Trackbar_GetTic (BYVAL hTrackbar AS DWORD, BYVAL iTic AS DWORD) AS LONG
   FUNCTION = SendMessage (hTrackbar, %TBM_GETTIC, iTic, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the length of the slider in a trackbar.
' ========================================================================================
FUNCTION Trackbar_GetTicPos (BYVAL hTrackbar AS DWORD, BYVAL iTic AS DWORD) AS LONG
   FUNCTION = SendMessage (hTrackbar, %TBM_GETTICPOS, iTic, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the handle to the ToolTip control assigned to the trackbar, if any.
' ========================================================================================
FUNCTION Trackbar_GetTooltips (BYVAL hTrackbar AS DWORD) AS DWORD
   FUNCTION = SendMessage (hTrackbar, %TBM_GETTOOLTIPS, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the Unicode character format flag for the control.
' ========================================================================================
FUNCTION Trackbar_GetUnicodeFormat (BYVAL hTrackbar AS DWORD) AS LONG
   FUNCTION = SendMessage (hTrackbar, %TBM_GETUNICODEFORMAT, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Assigns a window as the buddy window for a trackbar control. Trackbar buddy windows are
' automatically displayed in a location relative to the control's orientation (horizontal
' or vertical).
' ========================================================================================
FUNCTION Trackbar_SetBuddy (BYVAL hTrackbar AS DWORD, BYVAL fLocation AS DWORD, BYVAL hwndBuddy AS DWORD) AS DWORD
   FUNCTION = SendMessage (hTrackbar, %TBM_SETBUDDY, fLocation, hwndBuddy)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the number of logical positions the trackbar's slider moves in response to keyboard
' input from the arrow keys, such as the or keys. The logical positions are the integer
' increments in the trackbar's range of minimum to maximum slider positions.
' ========================================================================================
FUNCTION Trackbar_SetLineSize (BYVAL hTrackbar AS DWORD, BYVAL lLineSize AS LONG) AS LONG
   FUNCTION = SendMessage (hTrackbar, %TBM_SETLINESIZE, 0, lLineSize)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the number of logical positions the trackbar's slider moves in response to keyboard
' input, such as the or keys, or mouse input, such as clicks in the trackbar's channel.
' The logical positions are the integer increments in the trackbar's range of minimum to
' maximum slider positions.
' ========================================================================================
FUNCTION Trackbar_SetPageSize (BYVAL hTrackbar AS DWORD, BYVAL lPageSize AS LONG) AS LONG
   FUNCTION = SendMessage(hTrackbar, %TBM_SETPAGESIZE, 0, lPageSize)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the current logical position of the slider in a trackbar.
' ========================================================================================
SUB Trackbar_SetPos (BYVAL hTrackbar AS DWORD, BYVAL fPosition AS LONG, BYVAL lPosition AS LONG)
   SendMessage hTrackbar, %TBM_SETPOS, fPosition, lPosition
END SUB
' ========================================================================================

' ========================================================================================
' Sets the range of minimum and maximum logical positions for the slider in a trackbar.
' ========================================================================================
SUB Trackbar_SetRange (BYVAL hTrackbar AS DWORD, BYVAL fRedraw AS LONG, BYVAL lMinimum AS LONG, BYVAL lMaximum AS LONG)
   SendMessage hTrackbar, %TBM_SETRANGE, fRedraw, MAK(LONG, lMinimum, lMaximum)
END SUB
' ========================================================================================

' ========================================================================================
' Sets the maximum logical position for the slider in a trackbar.
' ========================================================================================
SUB Trackbar_SetRangeMax (BYVAL hTrackbar AS DWORD, BYVAL fRedraw AS LONG, BYVAL lMaximum AS LONG)
   SendMessage hTrackbar, %TBM_SETRANGEMAX, fRedraw, lMaximum
END SUB
' ========================================================================================

' ========================================================================================
' Sets the minimum logical position for the slider in a trackbar.
' ========================================================================================
SUB Trackbar_SetRangeMin (BYVAL hTrackbar AS DWORD, BYVAL fRedraw AS LONG, BYVAL lMinimum AS LONG)
   SendMessage hTrackbar, %TBM_SETRANGEMIN, fRedraw, lMinimum
END SUB
' ========================================================================================

' ========================================================================================
' Sets the starting and ending positions for the available selection range in a trackbar.
' ========================================================================================
SUB Trackbar_SetSel (BYVAL hTrackbar AS DWORD, BYVAL fRedraw AS DWORD, BYVAL lMinimum AS LONG, BYVAL lMaximum AS LONG)
   SendMessage hTrackbar, %TBM_SETSEL, fRedraw, MAK(LONG, lMinimum, lMaximum)
END SUB
' ========================================================================================

' ========================================================================================
' Sets the ending logical position of the current selection range in a trackbar. This
' message is ignored if the trackbar does not have the TBS_ENABLESELRANGE style.
' ========================================================================================
SUB Trackbar_SetSelEnd (BYVAL hTrackbar AS DWORD, BYVAL fRedraw AS LONG, BYVAL lEnd AS LONG)
   SendMessage hTrackbar, %TBM_SETSELEND, fRedraw, lEnd
END SUB
' ========================================================================================

' ========================================================================================
' Sets the starting logical position of the current selection range in a trackbar. This
' message is ignored if the trackbar does not have the BS_ENABLESELRANGE style.
' ========================================================================================
SUB Trackbar_SetSelStart (BYVAL hTrackbar AS DWORD, BYVAL fRedraw AS LONG, BYVAL lStart AS LONG)
   SendMessage hTrackbar, %TBM_SETSELSTART, fRedraw, lStart
END SUB
' ========================================================================================

' ========================================================================================
' Sets the length of the slider in a trackbar. This message is ignored if the trackbar
' does not have the TBS_FIXEDLENGTH style.
' ========================================================================================
SUB Trackbar_SetThumbLength (BYVAL hTrackbar AS DWORD, BYVAL iLength AS LONG)
   SendMessage hTrackbar, %TBM_SETTHUMBLENGTH, iLength, 0
END SUB
' ========================================================================================

' ========================================================================================
' Sets a tick mark in a trackbar at the specified logical position.
' ========================================================================================
FUNCTION Trackbar_SetTic (BYVAL hTrackbar AS DWORD, BYVAL lPosition AS LONG) AS LONG
   FUNCTION = SendMessage (hTrackbar, %TBM_SETTIC, 0, lPosition)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the interval frequency for tick marks in a trackbar.
' ========================================================================================
SUB Trackbar_SetTicFreq (BYVAL hTrackbar AS DWORD, BYVAL wFreq AS WORD)
   SendMessage hTrackbar, %TBM_SETTICFREQ, wFreq, 0
END SUB
' ========================================================================================

' ========================================================================================
' Positions a ToolTip control used by a trackbar control. Trackbar controls that use the
' TBS_TOOLTIPS style display ToolTips.
' ========================================================================================
FUNCTION Trackbar_SetTipSide (BYVAL hTrackbar AS DWORD, BYVAL fLocation AS LONG) AS LONG
   FUNCTION = SendMessage (hTrackbar, %TBM_SETTIPSIDE, fLocation, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Assigns a ToolTip control to a trackbar control.
' ========================================================================================
SUB Trackbar_SetToolTips (BYVAL hTrackbar AS DWORD, BYVAL hwndTT AS DWORD)
   SendMessage hTrackbar, %TBM_SETTOOLTIPS, hwndTT, 0
END SUB
' ========================================================================================

' ========================================================================================
' Sets the Unicode character format flag for the control. This message allows you to
' change the character set used by the control at run time rather than having to re-create
' the control.
' ========================================================================================
FUNCTION Trackbar_SetUnicodeFormat (BYVAL hTrackbar AS DWORD, BYVAL fUnicode AS LONG) AS LONG
   FUNCTION = SendMessage (hTrackbar, %TBM_SETUNICODEFORMAT, fUnicode, 0)
END FUNCTION
' ========================================================================================
