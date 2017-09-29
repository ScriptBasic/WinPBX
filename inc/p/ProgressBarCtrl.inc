' ########################################################################################
' Microsoft Windows
' File: ProgressBarCtrl.inc
' Contents: Progress Bar Control Wrapper Functions
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%PROGRESSBARCTRL_INC = 1

#INCLUDE ONCE "commctrl.inc"

' ========================================================================================
' Advances the current position of a progress bar by a specified increment and redraws the
' bar to reflect the new position.
' ========================================================================================
FUNCTION ProgressBar_DeltaPos (BYVAL hProgress AS DWORD, BYVAL nIncrement AS LONG) AS LONG
   FUNCTION = SendMessage (hProgress, %PBM_DELTAPOS, nIncrement, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the color of the progress bar.
' ========================================================================================
FUNCTION ProgressBar_GetBarColor (BYVAL hProgress AS DWORD) AS DWORD
   FUNCTION = SendMessage (hProgress, %PBM_GETBARCOLOR, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the color of the progress bar.
' ========================================================================================
FUNCTION ProgressBar_GetBkColor (BYVAL hProgress AS DWORD) AS DWORD
   FUNCTION = SendMessage (hProgress, %PBM_GETBKCOLOR, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the current high limit of a given progress bar control.
' ========================================================================================
FUNCTION ProgressBar_GetHighLimit (BYVAL hProgress AS DWORD) AS LONG
   FUNCTION = SendMessage (hProgress, %PBM_GETRANGE, %FALSE, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the current low limit of a given progress bar control.
' ========================================================================================
FUNCTION ProgressBar_GetLowLimit (BYVAL hProgress AS DWORD) AS LONG
   FUNCTION = SendMessage (hProgress, %PBM_GETRANGE, %TRUE, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the current high limit of a given progress bar control.
' ========================================================================================
FUNCTION ProgressBar_GetMaxRange (BYVAL hProgress AS DWORD) AS LONG
   FUNCTION = SendMessage (hProgress, %PBM_GETRANGE, %FALSE, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the current low limit of a given progress bar control.
' ========================================================================================
FUNCTION ProgressBar_GetMinRange (BYVAL hProgress AS DWORD) AS LONG
   FUNCTION = SendMessage (hProgress, %PBM_GETRANGE, %TRUE, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the current position of the progress bar.
' ========================================================================================
FUNCTION ProgressBar_GetPos (BYVAL hProgress AS DWORD) AS DWORD
   FUNCTION = SendMessage (hProgress, %PBM_GETPOS, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves information about the current high and low limits of a given progress bar control.
' ========================================================================================
FUNCTION ProgressBar_GetRange (BYVAL hProgress AS DWORD, BYVAL fWhichLimit AS DWORD, BYREF ppBRange AS PBRANGE) AS LONG
   FUNCTION = SendMessage (hProgress, %PBM_GETRANGE, fWhichLimit, VARPTR(ppBRange))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the state of the progress bar.
' ========================================================================================
FUNCTION ProgressBar_GetState (BYVAL hProgress AS DWORD) AS LONG
   FUNCTION = SendMessage (hProgress, %PBM_GETSTATE, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Not implemented.
' ========================================================================================
'FUNCTION ProgressBar_GetStep (BYVAL hProgress AS DWORD) AS LONG
'   FUNCTION = SendMessage (hProgress, %PBM_GETSTEP, 0, 0)
'END FUNCTION
' ========================================================================================

' ========================================================================================
' Advances the current position for a progress bar by the specified increment and redraws
' the bar to reflect the new position.
' ========================================================================================
FUNCTION ProgressBar_IncPos (BYVAL hProgress AS DWORD, BYVAL nIncVal AS LONG) AS LONG
   LOCAL nPos AS LONG
   nPos = SendMessage (hProgress, %PBM_GETPOS, 0, 0)
   FUNCTION = SendMessage (hProgress, %PBM_SETPOS, nPos + nIncVal, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the color of the progress indicator bar in the progress bar control.
' ========================================================================================
FUNCTION ProgressBar_SetBarColor (BYVAL hProgress AS DWORD, BYVAL clrBar AS DWORD) AS DWORD
   FUNCTION = SendMessage (hProgress, %PBM_SETBARCOLOR, 0, clrBar)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the background color in the progress bar.
' ========================================================================================
FUNCTION ProgressBar_SetBkColor (BYVAL hProgress AS DWORD, BYVAL clrBk AS DWORD) AS DWORD
   FUNCTION = SendMessage (hProgress, %PBM_SETBKCOLOR, 0, clrBk)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the progress bar to marquee mode. This causes the progress bar to move like a marquee.
' ========================================================================================
FUNCTION ProgressBar_SetMarquee (BYVAL hProgress AS DWORD, BYVAL fOn AS LONG, BYVAL dwAnimationSpeed AS DWORD) AS LONG
   FUNCTION = SendMessage (hProgress, %PBM_SETMARQUEE, fOn, dwAnimationSpeed)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the progress bar marquee mode to off.
' ========================================================================================
FUNCTION ProgressBar_SetMarqueeOff (BYVAL hProgress AS DWORD) AS LONG
   FUNCTION = SendMessage (hProgress, %PBM_SETMARQUEE, %FALSE, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the progress bar to marquee mode. This causes the progress bar to move like a marquee.
' ========================================================================================
FUNCTION ProgressBar_SetMarqueeOn (BYVAL hProgress AS DWORD, BYVAL dwAnimationSpeed AS DWORD) AS LONG
   FUNCTION = SendMessage (hProgress, %PBM_SETMARQUEE, %TRUE, dwAnimationSpeed)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the current position for a progress bar and redraws the bar to reflect the new position.
' ========================================================================================
FUNCTION ProgressBar_SetPos (BYVAL hProgress AS DWORD, BYVAL nNewPos AS LONG) AS LONG
   FUNCTION = SendMessage (hProgress, %PBM_SETPOS, nNewPos, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the current position for a progress bar and redraws the bar to reflect the new position.
' ========================================================================================
FUNCTION ProgressBar_SetRange (BYVAL hProgress AS DWORD, BYVAL nMinRange AS WORD, BYVAL nMaxRange AS WORD) AS DWORD
   FUNCTION = SendMessage (hProgress, %PBM_SETRANGE, 0, MAK(DWORD, nMinRange, nMaxRange))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the range of a progress bar control to a 32-bit value.
' ========================================================================================
FUNCTION ProgressBar_SetRange32 (BYVAL hProgress AS DWORD, BYVAL iLowLim AS LONG, BYVAL iHighLim AS LONG) AS DWORD
   FUNCTION = SendMessage (hProgress, %PBM_SETRANGE32, iLowLim, iHighLim)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the state of the progress bar.
' ========================================================================================
FUNCTION ProgressBar_SetState (BYVAL hProgress AS DWORD, BYVAL iState AS LONG) AS LONG
   FUNCTION = SendMessage (hProgress, %PBM_SETSTATE, iState, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Specifies the step increment for a progress bar. The step increment is the amount by
' which the progress bar increases its current position whenever it receives a PBM_STEPIT
' message. By default, the step increment is set to 10.
' ========================================================================================
FUNCTION ProgressBar_SetStep (BYVAL hProgress AS DWORD, BYVAL nStepInc AS LONG) AS LONG
   FUNCTION = SendMessage (hProgress, %PBM_SETSTEP, nStepInc, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Advances the current position for a progress bar by the step increment and redraws the
' bar to reflect the new position. An application sets the step increment by sending the
' PBM_SETSTEP message.
' ========================================================================================
FUNCTION ProgressBar_StepIt (BYVAL hProgress AS DWORD) AS LONG
   FUNCTION = SendMessage (hProgress, %PBM_STEPIT, 0, 0)
END FUNCTION
' ========================================================================================
