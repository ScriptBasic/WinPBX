' ########################################################################################
' Microsoft Windows
' File: RebarCtrl.inc
' Contents: Rebar Control Wrapper Functions
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%REBARCTRL_INC = 1

#INCLUDE ONCE "commctrl.inc"
#INCLUDE ONCE "uxtheme.inc"
#INCLUDE ONCE "oleidl.inc"

' ========================================================================================
' Puts the rebar control in drag-and-drop mode.
' ========================================================================================
SUB Rebar_BeginDrag (BYVAL hRebar AS DWORD, BYVAL uBand AS DWORD, BYVAL dwPos AS DWORD)
   SendMessage hRebar, %RB_BEGINDRAG, uBand, dwPos
END SUB
' ========================================================================================

' ========================================================================================
' Deletes a band from a rebar control.
' ========================================================================================
FUNCTION Rebar_DeleteBand (BYVAL hRebar AS DWORD, BYVAL uBand AS DWORD) AS LONG
   FUNCTION = SendMessage (hRebar, %RB_DELETEBAND, uBand, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Updates the drag position in the rebar control after a previous RB_BEGINDRAG message.
' ========================================================================================
SUB Rebar_DragMove (BYVAL hRebar AS DWORD, BYVAL dwPos AS DWORD)
   SendMessage hRebar, %RB_DRAGMOVE, 0, dwPos
END SUB
' ========================================================================================

' ========================================================================================
' Terminates the rebar control's drag-and-drop operation. This message does not cause an
' RBN_ENDDRAG notification to be sent.
' ========================================================================================
SUB Rebar_EndDrag (BYVAL hRebar AS DWORD)
   SendMessage hRebar, %RB_ENDDRAG, 0, 0
END SUB
' ========================================================================================

' ========================================================================================
' Retrieves the borders of a band. The result of this message can be used to calculate the
' usable area in a band.
' ========================================================================================
SUB Rebar_GetBandBorders (BYVAL hRebar AS DWORD, BYVAL uBand AS DWORD, BYREF lprc AS RECT)
   SendMessage hRebar, %RB_GETBANDBORDERS, uBand, VARPTR(lprc)
END SUB
' ========================================================================================

' ========================================================================================
' Retrieves the count of bands currently in the rebar control.
' ========================================================================================
FUNCTION Rebar_GetBandCount (BYVAL hRebar AS DWORD) AS DWORD
   FUNCTION = SendMessage (hRebar, %RB_GETBANDCOUNT, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves information about a specified band in a rebar control.
' ========================================================================================
FUNCTION Rebar_GetBandInfo (BYVAL hRebar AS DWORD, BYVAL uBand AS DWORD, BYREF lprbbi AS REBARBANDINFO) AS LONG
   FUNCTION = SendMessage(hRebar, %RB_GETBANDINFO, uBand, VARPTR(lprbbi))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the margins of a band.
' ========================================================================================
SUB Rebar_GetBandMargins (BYVAL hRebar AS DWORD, BYREF pMargins AS MARGINS)
   SendMessage hRebar, %RB_GETBANDMARGINS, 0, VARPTR(pMargins)
END SUB
' ========================================================================================

' ========================================================================================
' Retrieves the height of the rebar control.
' ========================================================================================
FUNCTION Rebar_GetBarHeight (BYVAL hRebar AS DWORD) AS DWORD
   FUNCTION = SendMessage (hRebar, %RB_GETBARHEIGHT, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves information about the rebar control and the image list it uses.
' ========================================================================================
FUNCTION Rebar_GetBarInfo (BYVAL hRebar AS DWORD, BYREF lprbi AS REBARINFO) AS LONG
   FUNCTION = SendMessage (hRebar, %RB_GETBARINFO, 0, VARPTR(lprbi))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves a rebar control's default background color.
' ========================================================================================
FUNCTION Rebar_GetBkColor (BYVAL hRebar AS DWORD) AS DWORD
   FUNCTION = SendMessage (hRebar, %RB_GETBKCOLOR, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the color scheme information from the rebar control.
' ========================================================================================
FUNCTION Rebar_GetColorScheme (BYVAL hRebar AS DWORD, BYREF lpcs AS COLORSCHEME) AS LONG
   FUNCTION = SendMessage (hRebar, %RB_GETCOLORSCHEME, 0, VARPTR(lpcs))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves a rebar control's IDropTarget interface pointer.
' ========================================================================================
FUNCTION Rebar_GetDropTarget (BYVAL hRebar AS DWORD) AS IDropTarget
   LOCAL ppIDropTarget AS IDropTarget
   SendMessage hRebar, %RB_GETDROPTARGET, 0, VARPTR(ppIDropTarget)
   FUNCTION = ppIDropTarget
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the extended style.
' ========================================================================================
FUNCTION Rebar_GetExtendedStyle (BYVAL hRebar AS DWORD) AS DWORD
   FUNCTION = SendMessage (hRebar, %RB_GETEXTENDEDSTYLE, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the rebar control's current palette.
' ========================================================================================
FUNCTION Rebar_GetPalette (BYVAL hRebar AS DWORD) AS DWORD
   FUNCTION = SendMessage (hRebar, %RB_GETPALETTE, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the bounding rectangle for a given band in a rebar control.
' ========================================================================================
FUNCTION Rebar_GetRect (BYVAL hRebar AS DWORD, BYVAL uBand AS DWORD, BYREF lprc AS RECT) AS LONG
   FUNCTION = SendMessage (hRebar, %RB_GETRECT, uBand, VARPTR(lprc))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the number of rows of bands in a rebar control.
' ========================================================================================
FUNCTION Rebar_GetRowCount (BYVAL hRebar AS DWORD) AS DWORD
   FUNCTION = SendMessage (hRebar, %RB_GETROWCOUNT, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the height of a specified row in a rebar control.
' ========================================================================================
FUNCTION Rebar_GetRowHeight (BYVAL hRebar AS DWORD, BYVAL uRow AS DWORD) AS DWORD
   FUNCTION = SendMessage (hRebar, %RB_GETROWHEIGHT, uRow, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves a rebar control's default text color.
' ========================================================================================
FUNCTION Rebar_GetTextColor (BYVAL hRebar AS DWORD) AS DWORD
   FUNCTION = SendMessage (hRebar, %RB_GETTEXTCOLOR, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the handle to any ToolTip control associated with the rebar control.
' ========================================================================================
FUNCTION Rebar_GetTooltips (BYVAL hRebar AS DWORD) AS DWORD
   FUNCTION = SendMessage (hRebar, %RB_GETTOOLTIPS, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the Unicode character format flag for the control.
' ========================================================================================
FUNCTION Rebar_GetUnicodeFormat (BYVAL hRebar AS DWORD) AS LONG
   FUNCTION = SendMessage (hRebar, %RB_GETUNICODEFORMAT, 0, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Determines which portion of a rebar band is at a given point on the screen, if a rebar
' band exists at that point.
' ========================================================================================
FUNCTION Rebar_HitTest (BYVAL hRebar AS DWORD, BYREF lprhbt AS RBHITTESTINFO) AS LONG
   FUNCTION = SendMessage (hRebar, %RB_HITTEST, 0, VARPTR(lprhbt))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Converts a band identifier to a band index in a rebar control.
' ========================================================================================
FUNCTION Rebar_IdToIndex (BYVAL hRebar AS DWORD, BYVAL uBandID AS DWORD) AS LONG
   FUNCTION = SendMessage (hRebar, %RB_IDTOINDEX, uBandID, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Inserts a new band in a rebar control.
' ========================================================================================
FUNCTION Rebar_InsertBand (BYVAL hRebar AS DWORD, BYVAL uIndex AS DWORD, BYREF lprbbi AS REBARBANDINFO) AS LONG
   FUNCTION = SendMessage (hRebar, %RB_INSERTBAND, uIndex, VARPTR(lprbbi))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Resizes a band in a rebar control to either its ideal or largest size.
' ========================================================================================
SUB Rebar_MaximizeBand (BYVAL hRebar AS DWORD, BYVAL uBand AS DWORD, BYVAL fIdeal AS DWORD)
   SendMessage hRebar, %RB_MAXIMIZEBAND, uBand, fIdeal
END SUB
' ========================================================================================

' ========================================================================================
' Resizes a band in a rebar control to its smallest size.
' ========================================================================================
SUB Rebar_MinimizeBand (BYVAL hRebar AS DWORD, BYVAL uBand AS DWORD)
  SendMessage hRebar, %RB_MINIMIZEBAND, uBand, 0
END SUB
' ========================================================================================

' ========================================================================================
' Moves a band from one index to another.
' ========================================================================================
FUNCTION Rebar_MoveBand (BYVAL hRebar AS DWORD, BYVAL iFrom AS DWORD, BYVAL iTo AS DWORD) AS LONG
   FUNCTION = SendMessage (hRebar, %RB_MOVEBAND, iFrom, iTo)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sent to a rebar control to programmatically push a chevron.
' ========================================================================================
SUB Rebar_PushChevron (BYVAL hRebar AS DWORD, BYVAL uBand AS DWORD, BYVAL iAppValue AS DWORD)
   SendMessage hRebar, %RB_PUSHCHEVRON, uBand, iAppValue
END SUB
' ========================================================================================

' ========================================================================================
' Sets characteristics of an existing band in a rebar control.
' ========================================================================================
FUNCTION Rebar_SetBandInfo (BYVAL hRebar AS DWORD, BYVAL uBand AS DWORD, BYREF lprbbi AS REBARBANDINFO) AS LONG
   FUNCTION = SendMessage (hRebar, %RB_SETBANDINFO, uBand, VARPTR(lprbbi))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the characteristics of a rebar control.
' ========================================================================================
FUNCTION Rebar_SetBandWidth (BYVAL hRebar AS DWORD, BYVAL uBand AS DWORD, BYVAL nWidth AS DWORD) AS LONG
   FUNCTION = SendMessage (hRebar, %RB_SETBANDWIDTH, uBand, nWidth)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the characteristics of a rebar control.
' ========================================================================================
FUNCTION Rebar_SetBarInfo (BYVAL hRebar AS DWORD, BYREF lprbi AS REBARINFO) AS LONG
   FUNCTION = SendMessage (hRebar, %RB_SETBARINFO, 0, VARPTR(lprbi))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets a rebar control's default background color.
' ========================================================================================
FUNCTION Rebar_SetBkColor (BYVAL hRebar AS DWORD, BYVAL clrBk AS DWORD) AS DWORD
   FUNCTION = SendMessage (hRebar, %RB_SETBKCOLOR, 0, clrBk)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the color scheme information for the rebar control.
' ========================================================================================
SUB Rebar_SetColorScheme (BYVAL hRebar AS DWORD, BYREF lpcs AS COLORSCHEME)
   SendMessage hRebar, %RB_SETCOLORSCHEME, 0, VARPTR(lpcs)
END SUB
' ========================================================================================

' ========================================================================================
' Sets the rebar control's current palette.
' ========================================================================================
FUNCTION Rebar_SetPalette (BYVAL hRebar AS DWORD, BYVAL hpal AS DWORD) AS DWORD
   FUNCTION = SendMessage (hRebar, %RB_SETPALETTE, 0, hpal)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets a rebar control's parent window.
' ========================================================================================
FUNCTION Rebar_SetParent (BYVAL hRebar AS DWORD, BYVAL hwndParent AS DWORD) AS DWORD
   FUNCTION = SendMessage (hRebar, %RB_SETPARENT, hwndParent, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets a rebar control's default text color.
' ========================================================================================
FUNCTION Rebar_SetTextColor (BYVAL hRebar AS DWORD, BYVAL clrText AS DWORD) AS DWORD
   FUNCTION = SendMessage (hRebar, %RB_SETTEXTCOLOR, 0, clrText)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Associates a tooltip control with the rebar control.
' ========================================================================================
SUB Rebar_SetTooltips (BYVAL hRebar AS DWORD, BYVAL hwndToolTip AS DWORD)
   SendMessage hRebar, %RB_SETTOOLTIPS, hwndToolTip, 0
END SUB
' ========================================================================================

' ========================================================================================
' Sets the Unicode character format flag for the control. This message allows you to
' change the character set used by the control at run time rather than having to re-create
' the control.
' ========================================================================================
FUNCTION Rebar_SetUnicodeFormat (BYVAL hRebar AS DWORD, BYVAL fUnicode AS DWORD) AS LONG
   FUNCTION = SendMessage (hRebar, %RB_SETUNICODEFORMAT, fUnicode, 0)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the visual style of a rebar control.
' ========================================================================================
SUB Rebar_SetWindowTheme (BYVAL hRebar AS DWORD, BYVAL bstrTheme AS WSTRING)
   SendMessage hRebar, %RB_SETWINDOWTHEME, 0, STRPTR(bstrTheme)
END SUB
' ========================================================================================

' ========================================================================================
' Shows or hides a given band in a rebar control.
' ========================================================================================
FUNCTION Rebar_ShowBand (BYVAL hRebar AS DWORD, BYVAL uBand AS DWORD, BYVAL fShow AS DWORD) AS LONG
   FUNCTION = SendMessage (hRebar, %RB_SHOWBAND, uBand, fShow)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Attempts to find the best layout of the bands for the given rectangle.
' ========================================================================================
FUNCTION Rebar_SizeToRect (BYVAL hRebar AS DWORD, BYREF prc AS RECT) AS LONG
   FUNCTION = SendMessage (hRebar, %RB_SIZETORECT, 0, VARPTR(prc))
END FUNCTION
' ========================================================================================
