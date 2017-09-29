' ========================================================================================
' TLB_UTILS.INC - Include file for the TypeLyb Browser
' (C) 2011 by José Roca. All rights reserved.
' ========================================================================================

' Resolution of the screen at design time
%DESIGN_LOGPIXELSX = 96
%DESIGN_LOGPIXELSY = 96

'------------------------------------------------------------------------------
'
' PROCEDURE: phnxGetResolutionRatios(SINGLE, SINGLE)
' PURPOSE:   Determines the ratios between the resolution of the screen on
'            which an application was designed and the resolution of the
'            screen on which the application is running.
' RETURNS:   Horizontal and vertical scaling factors.
'
'------------------------------------------------------------------------------

SUB phnxGetResolutionRatios _
   ( _
   rXFactor AS SINGLE, _   ' horizontal scaling factor
   rYFactor AS SINGLE _    ' vertical scaling factor
   )

   LOCAL hDC      AS DWORD

   ' Get the screen device context
   hDC = GetDC(%NULL)
   ' Resolution ratio = current resolution / design time resolution
   rXFactor = GetDeviceCaps(hDC, %LOGPIXELSX) / %DESIGN_LOGPIXELSX
   rYFactor = GetDeviceCaps(hDC, %LOGPIXELSY) / %DESIGN_LOGPIXELSY
   ReleaseDC %NULL, hDC

END SUB

' Windows95 and WindowsNT MENUITEMINFO struct size
%MENUITEMINFO_WIN95_SIZE = 44

'----------------------------------------------------------------------
'
' FUNCTION: IsWin95WinNT
' PURPOSE:  Determines whether the application is running on Windows95
'           or WindowsNT.
' RETURNS:  TRUE if OS is Windows95 or WindowsNT, FALSE if it is not.
'
'----------------------------------------------------------------------

FUNCTION IsWin95WinNT () AS LONG

  LOCAL tos     AS OSVERSIONINFO

  tos.dwOsVersionInfoSize = SIZEOF(tos)

  IF ISTRUE GetVersionEx(tos) THEN
    IF tos.dwPlatformId = %VER_PLATFORM_WIN32_WINDOWS THEN
      IF tos.dwMinorVersion < 10 THEN
        FUNCTION = %TRUE
        EXIT FUNCTION
      END IF
      ELSEIF tos.dwPlatformId = %VER_PLATFORM_WIN32_NT THEN
        IF tos.dwMajorVersion < 5 THEN
          FUNCTION = %TRUE
          EXIT FUNCTION
        END IF
    END IF
  END IF

  FUNCTION = %FALSE

END FUNCTION

'###############################################################################
' BEGIN Layout
'###############################################################################

DECLARE FUNCTION Layout_Apply LIB "LAYOUT32.DLL" ALIAS "Layout_Apply" (BYVAL hWnd AS DWORD, BYVAL hInstance AS DWORD, BYVAL wResID AS WORD, BYVAL fDlgUnits AS LONG, BYVAL rXFactor AS SINGLE, BYVAL rYFactor AS SINGLE) AS LONG
DECLARE FUNCTION Layout_ApplyEx LIB "LAYOUT32.DLL" ALIAS "Layout_ApplyEx" (BYVAL hWnd AS DWORD, BYVAL fDlgUnits AS LONG, BYVAL lpRules AS DWORD, BYVAL lpLimits AS DWORD) AS LONG
DECLARE FUNCTION Layout_Load LIB "LAYOUT32.DLL" ALIAS "Layout_Load" (BYVAL hInstance AS DWORD, BYVAL wResID AS WORD, BYVAL rXFactor AS SINGLE, BYVAL rYFactor AS SINGLE, lpRules AS DWORD, lpLimits AS DWORD) AS DWORD
DECLARE FUNCTION Layout_Unload LIB "LAYOUT32.DLL" ALIAS "Layout_Unload" (BYVAL lpRules AS DWORD, BYVAL lpLimits AS DWORD) AS LONG

'###############################################################################
' END Layout
'###############################################################################

'-------------------------------------------------------------------------------
'
' PROCEDURE: phnxAdjustWindowRect
' PURPOSE:   Adjusts the bounding rectangle of a nonresizeable window, based
'            on the desired size of the client area, when a system parameter
'            changes.
'
'-------------------------------------------------------------------------------

FUNCTION phnxAdjustWindowRect _
  ( _
  BYVAL hWnd      AS DWORD, _ ' window handle
  BYVAL cxClient  AS LONG, _  ' desired width of client area in pixels
  BYVAL cyClient  AS LONG _   ' desired height of client area in pixels
  ) AS LONG

  LOCAL trc     AS RECT
  LOCAL trcTemp AS RECT
  LOCAL hMenu   AS DWORD
  LOCAL dwStyle AS DWORD
  LOCAL cx      AS LONG
  LOCAL cy      AS LONG

  ' Calculate the height of the window taking menu wrap into account
  trc.nLeft   = 0
  trc.nTop    = 0
  trc.nRight  = cxClient
  trc.nBottom = cyClient
  hMenu   = GetMenu(hWnd)
  dwStyle = GetWindowLong(hWnd, %GWL_STYLE)
  AdjustWindowRectEx trc, dwStyle, (hMenu <> %NULL), GetWindowLong(hWnd, %GWL_EXSTYLE)
  ' If there is a menu, check how much wrapping occurs when we set the window
  ' to the width specified by AdjustWindowRect and an infinite amount of height.
  ' An infinite height allows us to see every single menu wrap.
  IF ISTRUE hMenu THEN
    trcTemp = trc
    trcTemp.nBottom = &H7FFF  ' "Infinite" height
    SendMessage hWnd, %WM_NCCALCSIZE, %FALSE, BYVAL VARPTR(trcTemp)
    ' Adjust our previous calculation to compensate for menu wrapping.
    trc.nBottom = trc.nBottom + trcTemp.nTop
  END IF
  ' AdjustWindowRectEx does not take the standard scrollbars into account
  IF (dwStyle AND %WS_HSCROLL) = %WS_HSCROLL THEN
    trc.nBottom = trc.nBottom + GetSystemMetrics(%SM_CYHSCROLL)
  END IF
  IF (dwStyle AND %WS_VSCROLL) = %WS_VSCROLL THEN
    trc.nRight = trc.nRight + GetSystemMetrics(%SM_CXVSCROLL)
  END IF
  cx = trc.nRight - trc.nLeft
  cy = trc.nBottom - trc.nTop
  SetWindowPos hWnd, %NULL, 0, 0, cx, cy, %SWP_NOZORDER OR %SWP_NOMOVE OR %SWP_NOACTIVATE

END FUNCTION

'------------------------------------------------------------------------------
'
' PROCEDURE: phnxCenterWindow
' PURPOSE:   Centers one window over another.  It also ensures that the
'            placement is within the 'working area', meaning that it is
'            both within the display limits of the screen, -and- not
'            obscured by the tray or other frameing elements of the
'            desktop.
'
'------------------------------------------------------------------------------

FUNCTION phnxCenterWindow _
  ( _
  BYVAL hWndChild   AS DWORD, _ ' handle of window to center
  BYVAL hWndParent  AS DWORD _  ' handle of reference window or NULL if window is the screen
  ) AS LONG

  LOCAL trcChild      AS RECT     ' Child window dimensions
  LOCAL trcParent     AS RECT     ' Parent window dimensions
  LOCAL trcWorkArea   AS RECT     ' Work area dimensions
  LOCAL tpt           AS POINTAPI ' x and y coordinate of centered window
  LOCAL cxChild       AS LONG     ' Width of child window
  LOCAL cyChild       AS LONG     ' Height of child window
  LOCAL cxParent      AS LONG     ' Width of parent window
  LOCAL cyParent      AS LONG     ' Height of parent window
  LOCAL fResult       AS LONG     ' Return flag for SystemParametersInfo()

  ' Get the Height and Width of the child window
  GetWindowRect hWndChild, trcChild
  cxChild = trcChild.nRight - trcChild.nLeft
  cyChild = trcChild.nBottom - trcChild.nTop

  ' Get the limits of the 'workarea'
  fResult = SystemParametersInfo(%SPI_GETWORKAREA, SIZEOF(trcWorkArea), BYVAL VARPTR(trcWorkArea), 0)
  IF ISFALSE(fResult) THEN
    trcWorkArea.nLeft   = 0
    trcWorkArea.nTop    = 0
    trcWorkArea.nRight  = GetSystemMetrics(%SM_CXSCREEN)
    trcWorkArea.nBottom = GetSystemMetrics(%SM_CYSCREEN)
  END IF

  ' Get the Height and Width of the parent window
  IF ISTRUE hWndParent THEN
    GetWindowRect hWndParent, trcParent
  ELSE
    trcParent.nLeft   = trcWorkArea.nLeft
    trcParent.nTop    = trcWorkArea.nTop
    trcParent.nRight  = trcWorkArea.nRight
    trcParent.nBottom = trcWorkArea.nBottom
  END IF
  cxParent = trcParent.nRight - trcParent.nLeft
  cyParent = trcParent.nBottom - trcParent.nTop

  ' Calculate new X position, then adjust for workarea
  tpt.x = trcParent.nLeft + ((cxParent - cxChild) \ 2)
  IF (tpt.x < trcWorkArea.nLeft) THEN
    tpt.x = trcWorkArea.nLeft
    ELSEIF ((tpt.x + cxChild) > trcWorkArea.nRight) THEN
      tpt.x = trcWorkArea.nRight - cxChild
  END IF

  ' Calculate new Y position, then adjust for workarea
  tpt.y = trcParent.nTop  + ((cyParent - cyChild) \ 2)
  IF (tpt.y < trcWorkArea.nTop) THEN
    tpt.y = trcWorkArea.nTop
    ELSEIF ((tpt.y + cyChild) > trcWorkArea.nBottom) THEN
      tpt.y = trcWorkArea.nBottom - cyChild
  END IF

  IF (GetWindowLong(hWndChild, %GWL_STYLE) AND %WS_CHILD) = %WS_CHILD THEN
    ScreenToClient hWndParent, tpt
  END IF

  ' Reposition the window
  FUNCTION = SetWindowPos(hWndChild, %NULL, tpt.x, tpt.y, 0, 0, %SWP_NOSIZE OR %SWP_NOZORDER)

END FUNCTION

'------------------------------------------------------------------------------
'
' PROCEDURE: phnxCreateFont
' PURPOSE:   Creates a logical font.
' RETURNS:   Handle of font or NULL on failure.
'
'------------------------------------------------------------------------------

FUNCTION phnxCreateFont _
   ( _
         szFaceName  AS ASCIIZ, _   ' typeface name of font
   BYVAL lPointSize  AS LONG, _     ' point size
   BYVAL lWeight     AS LONG, _     ' font weight(bold etc.)
   BYVAL bItalic     AS BYTE, _     ' TRUE = italic
   BYVAL bUnderline  AS BYTE, _     ' TRUE = underline
   BYVAL bStrikeOut  AS BYTE, _     ' TRUE = strikeout
   BYVAL bCharSet    AS BYTE _      ' character set
   ) AS DWORD

   LOCAL tlf      AS LOGFONT
   LOCAL hDC      AS DWORD

   hDC = GetDC(%HWND_DESKTOP)

   tlf.lfHeight         = -MulDiv(lPointSize, GetDeviceCaps(hDC, %LOGPIXELSY), 72)  ' logical font height
   tlf.lfWidth          =  0                                                        ' average character width
   tlf.lfEscapement     =  0                                                        ' escapement
   tlf.lfOrientation    =  0                                                        ' orientation angles
   tlf.lfWeight         =  lWeight                                                  ' font weight
   tlf.lfItalic         =  bItalic                                                  ' italic(TRUE/FALSE)
   tlf.lfUnderline      =  bUnderline                                               ' underline(TRUE/FALSE)
   tlf.lfStrikeOut      =  bStrikeOut                                               ' strikeout(TRUE/FALSE)
   tlf.lfCharSet        =  bCharset                                                 ' character set
   tlf.lfOutPrecision   =  %OUT_TT_PRECIS                                           ' output precision
   tlf.lfClipPrecision  =  %CLIP_DEFAULT_PRECIS                                     ' clipping precision
   tlf.lfQuality        =  %DEFAULT_QUALITY                                         ' output quality
   tlf.lfPitchAndFamily =  %FF_DONTCARE                                             ' pitch and family
   tlf.lfFaceName       =  szFaceName                                               ' typeface name

   ReleaseDC %HWND_DESKTOP, hDC

   FUNCTION = CreateFontIndirect(tlf)

END FUNCTION

'------------------------------------------------------------------------------
'
' FUNCTION: EnumFontFamProc
' PURPOSE:
'
'------------------------------------------------------------------------------

FUNCTION EnumFontFamProc _
   ( _
   BYVAL lpelf       AS DWORD, _ ' address of ENUMLOGFONT struct
   BYVAL lpntm       AS DWORD, _ ' address of NEWTEXTMETRIC struct
   BYVAL lFontType   AS LONG, _  ' font type
   BYVAL lplf        AS LONG _   ' address of LOGFONT struct
   ) AS LONG

   LOCAL ptelf    AS ENUMLOGFONT PTR
   LOCAL ptlf     AS LOGFONT PTR

   ptelf = lpelf
   ptlf  = lplf

   @ptlf.lfCharSet        = @ptelf.elfLogFont.lfCharSet
   @ptlf.lfPitchAndFamily = @ptelf.elfLogFont.lfPitchAndFamily
   @ptlf.lfFaceName       = @ptelf.elfLogFont.lfFaceName

   FUNCTION = %FALSE

END FUNCTION

'----------------------------------------------------------------------
'
' FUNCTION: phnxGetFormHandle
' PURPOSE:  Finds the handle of the top-level window or MDI child
'           window that is the ancestor of the specified window.  The
'           reference handle is the handle of any control on the form.
' RETURNS:  The handle of the form.
'
'----------------------------------------------------------------------

FUNCTION phnxGetFormHandle _
  ( _
  BYVAL hWnd  AS DWORD _  ' reference handle
  ) AS DWORD

  WHILE ISTRUE (GetWindowLong(hWnd, %GWL_STYLE) AND %WS_CHILD)
    IF ISTRUE (GetWindowLong(hWnd, %GWL_EXSTYLE) AND %WS_EX_MDICHILD) THEN EXIT LOOP
    hWnd = GetParent(hWnd)
  WEND

  FUNCTION = hWnd

END FUNCTION

'###############################################################################
' BEGIN Keyboard focus and default identifier support
'###############################################################################

' Keyboard focus and default identifier
TYPE KEYBOARDFOCUS        ' kf
  hWndFocus AS DWORD      ' handle of control with the focus
  wDefID    AS WORD       ' default identifier
  bClosed   AS BYTE       ' top-level window was closed
  lRetVal   AS LONG       ' return value
END TYPE

'----------------------------------------------------------------------
'
' FUNCTION: phnxSetReturnValue
' PURPOSE:  Sets the value to be returned to the application from
'           the function that created the modal window.
'
'----------------------------------------------------------------------

FUNCTION phnxSetReturnValue _
  ( _
  BYVAL hWnd      AS DWORD, _ ' handle of window
  BYVAL lRetVal   AS LONG _   ' return value
  ) AS LONG

  LOCAL ptkf      AS KEYBOARDFOCUS PTR

  hWnd = phnxGetFormHandle(hWnd)

  ptkf = GetProp(hWnd, "KEYBOARDFOCUS")

  IF ISTRUE ptkf THEN
    @ptkf.lRetVal = lRetVal
  END IF

END FUNCTION

'----------------------------------------------------------------------
'
' FUNCTION: GetNextTabItem
' PURPOSE:  Retrieves the handle of the first control that has the
'           WS_TABSTOP style that precedes (or follows) the specified
'           control.
' RETURN:   The window handle of the previous (or next) control that
'           has the WS_TABSTOP style set or hWndCtrl if no such control
'           exists.
' NOTES:    This function replaces the GetNextDlgTabItem API since it
'           sometimes causes a stack fault.
'
'----------------------------------------------------------------------

FUNCTION GetNextTabItem _
  ( _
  BYVAL hWnd      AS DWORD, _ ' handle of window
  BYVAL hWndCtrl  AS DWORD, _ ' handle of control receiving the focus
  BYVAL fPrevious AS LONG _   ' previous flag
  ) AS LONG

  LOCAL hWndItem  AS DWORD

  hWndItem = hWndCtrl

  IF IsWindow(hWnd) THEN

    DO
      IF ISFALSE hWndCtrl THEN
        hWndCtrl = GetWindow(hWnd, %GW_CHILD)
        IF ISTRUE fPrevious THEN
          IF ISTRUE hWndCtrl THEN hWndCtrl = GetWindow(hWndCtrl, %GW_HWNDLAST)
        END IF
      ELSE
        IF ISTRUE fPrevious THEN
          hWndCtrl = GetWindow(hWndCtrl, %GW_HWNDPREV)
        ELSE
          hWndCtrl = GetWindow(hWndCtrl, %GW_HWNDNEXT)
        END IF
      END IF
      IF ISTRUE hWndCtrl THEN
        IF ISTRUE IsWindowVisible(hWndCtrl) THEN
          IF ISTRUE IsWindowEnabled(hWndCtrl) THEN
            IF (GetWindowLong(hWndCtrl, %GWL_STYLE) AND %WS_TABSTOP) = %WS_TABSTOP THEN
              hWndItem = hWndCtrl
              EXIT DO
            ELSE
              IF (GetWindowLong(hWndCtrl, %GWL_EXSTYLE) AND %WS_EX_CONTROLPARENT) = %WS_EX_CONTROLPARENT THEN
                hWndItem = GetNextTabItem(hWndCtrl, %NULL, fPrevious)
                IF ISTRUE hWndItem THEN EXIT DO
              END IF
            END IF
          END IF
        END IF
      ELSE
        EXIT DO
      END IF
    LOOP

  END IF

  FUNCTION = hWndItem

END FUNCTION

'----------------------------------------------------------------------
'
' FUNCTION: FindDefButton
' PURPOSE:  Finds the current button with a heavy black border.
'
'----------------------------------------------------------------------

FUNCTION FindDefButton _
  ( _
  BYVAL hWnd  AS DWORD _  ' handle of window
  ) AS DWORD

  LOCAL hWndChild AS DWORD

  hWnd = phnxGetFormHandle(hWnd)

  EnumChildWindows hWnd, CODEPTR(FindDefButton_ChildEnumProc), VARPTR(hWndChild)

  FUNCTION = hWndChild

END FUNCTION

'----------------------------------------------------------------------
'
' FUNCTION: FindDefButton_ChildEnumProc
' PURPOSE:  Enumerates child controls on the specified window.
'
'----------------------------------------------------------------------

FUNCTION FindDefButton_ChildEnumProc _
  ( _
  BYVAL hWnd    AS DWORD, _ ' handle of child window
  BYVAL lParam  AS LONG _   ' address of variable with child window handle
  ) AS LONG

  LOCAL plItem  AS LONG PTR

  plItem = lParam

  IF ISTRUE(SendMessage(hWnd, %WM_GETDLGCODE, 0, 0) AND %DLGC_DEFPUSHBUTTON) THEN
    @plItem = hWnd
    FUNCTION = %FALSE
    EXIT FUNCTION
  END IF

  FUNCTION = %TRUE

END FUNCTION

'----------------------------------------------------------------------
'
' FUNCTION: FindDefIdHandle
' PURPOSE:  Finds the handle of the button with the default ID.
'
'----------------------------------------------------------------------

FUNCTION FindDefIdHandle _
  ( _
  BYVAL hWnd    AS DWORD, _ ' handle of window
  BYVAL wDefID  AS WORD _   ' identifier of button
  ) AS DWORD

  LOCAL hWndChild AS DWORD

  hWnd = phnxGetFormHandle(hWnd)

  IF ISTRUE wDefID THEN
    hWndChild = wDefID
    EnumChildWindows hWnd, CODEPTR(FindDefIdHandle_ChildEnumProc), VARPTR(hWndChild)
    IF ISFALSE IsChild(hWnd, hWndChild) THEN hWndChild = %NULL
  END IF

  FUNCTION = hWndChild

END FUNCTION

'----------------------------------------------------------------------
'
' FUNCTION: FindDefIdHandle_ChildEnumProc
' PURPOSE:  Enumerates child controls on the specified window.
'
'----------------------------------------------------------------------

FUNCTION FindDefIdHandle_ChildEnumProc _
  ( _
  BYVAL hWnd    AS DWORD, _ ' handle of child window
  BYVAL lParam  AS LONG _   ' address of variable - IN: default ID, OUT: child window handle
  ) AS LONG

  LOCAL plItem  AS LONG PTR

  plItem = lParam

  IF ISTRUE(SendMessage(hWnd, %WM_GETDLGCODE, 0, 0) AND (%DLGC_UNDEFPUSHBUTTON OR %DLGC_DEFPUSHBUTTON)) THEN
    IF GetDlgCtrlID(hWnd) = @plItem THEN
      @plItem = hWnd
      FUNCTION = %FALSE
      EXIT FUNCTION
    END IF
  END IF

  FUNCTION = %TRUE

END FUNCTION

'----------------------------------------------------------------------
'
' FUNCTION: SetCtrlFocus
' PURPOSE:  Sets the focus to a control of the specified window,
'           selecting text if the control is an edit window.
'
'----------------------------------------------------------------------

FUNCTION SetCtrlFocus _
  ( _
  BYVAL hWnd      AS DWORD, _ ' handle of window
  BYVAL hWndCtrl  AS DWORD _  ' handle of control receiving the focus
  ) AS LONG

  LOCAL ptkf      AS KEYBOARDFOCUS PTR
  LOCAL hWndPrev  AS DWORD
  LOCAL hWndDef   AS DWORD
  LOCAL hWndBtn   AS DWORD

  hWnd = phnxGetFormHandle(hWnd)

  ptkf = GetProp(hWnd, "KEYBOARDFOCUS")

  hWndPrev = GetFocus()

  IF ISTRUE IsChild(hWnd, hWndPrev) THEN
    IF ISTRUE(SendMessage(hWndPrev, %WM_GETDLGCODE, 0, 0) AND %DLGC_HASSETSEL) THEN
      SendMessage hWndPrev, %EM_SETSEL, -1, 0
    END IF
  END IF

  IF ISTRUE(SendMessage(hWndCtrl, %WM_GETDLGCODE, 0, 0) AND %DLGC_HASSETSEL) THEN
    SendMessage hWndCtrl, %EM_SETSEL, 0, -1
  END IF

  SetFocus hWndCtrl
  hWndBtn = FindDefButton(hWnd)
  IF ISTRUE ptkf THEN
    hWndDef = FindDefIdHandle(hWnd, @ptkf.wDefID)
  END IF

  ' If the control is not a pushbutton
  IF ISFALSE(SendMessage(hWndCtrl, %WM_GETDLGCODE, 0, 0) AND (%DLGC_UNDEFPUSHBUTTON OR %DLGC_DEFPUSHBUTTON)) THEN
    IF hWndBtn <> hWndDef THEN
      IF ISTRUE hWndBtn THEN
        SendMessage hWndBtn, %BM_SETSTYLE, %BS_PUSHBUTTON, %TRUE
      END IF
    END IF
    IF ISTRUE IsWindowEnabled(hWndDef) THEN
      SendMessage hWndDef, %BM_SETSTYLE, %BS_DEFPUSHBUTTON, %TRUE
    END IF
  ELSE
    IF hWndBtn <> hWndCtrl THEN
      IF ISTRUE hWndBtn THEN
        SendMessage hWndBtn, %BM_SETSTYLE, %BS_PUSHBUTTON, %TRUE
      END IF
    END IF
    SendMessage hWndCtrl, %BM_SETSTYLE, %BS_DEFPUSHBUTTON, %TRUE
  END IF

END FUNCTION

'----------------------------------------------------------------------
'
' FUNCTION: phnxEnableWindow
' PURPOSE:  Enables or disables the specified window.  This function
'           ensures that buttons are drawn properly and that the
'           keyboard focus is not stuck on a disabled control.
'
'----------------------------------------------------------------------

FUNCTION phnxEnableWindow _
  ( _
  BYVAL hWndCtrl  AS DWORD, _ ' handle of window
  BYVAL fEnable   AS LONG _   ' TRUE = enable, FALSE = disable
  ) AS LONG

  LOCAL hWnd      AS DWORD
  LOCAL ptkf      AS KEYBOARDFOCUS PTR
  LOCAL hWndDef   AS DWORD
  LOCAL hWndFocus AS DWORD

  hWnd = phnxGetFormHandle(hWndCtrl)

  ptkf = GetProp(hWnd, "KEYBOARDFOCUS")

  IF ISTRUE (GetWindowLong(hWndCtrl, %GWL_STYLE) AND %WS_CHILD) THEN
    hWndFocus = GetFocus()
    IF ISFALSE fEnable THEN
      ' Remove the heavy border if this is a button
      IF ISTRUE(SendMessage(hWndCtrl, %WM_GETDLGCODE, 0, 0) AND %DLGC_DEFPUSHBUTTON) THEN
        SendMessage hWndCtrl, %BM_SETSTYLE, %BS_PUSHBUTTON, %TRUE
      END IF
      IF hWndFocus = hWndCtrl THEN
        hWndFocus = GetNextTabItem(hWnd, hWndFocus, %FALSE)
        EnableWindow hWndCtrl, fEnable
        ' Set the keyboard focus to a control that is enabled
        IF ISTRUE hWndFocus THEN SetCtrlFocus hWnd, hWndFocus
        EXIT FUNCTION
      END IF
    END IF
    IF ISTRUE ptkf THEN
      hWndDef = FindDefIdHandle(hWnd, @ptkf.wDefID)
    END IF
    EnableWindow hWndCtrl, fEnable
    IF ISTRUE hWndFocus THEN
      ' If the focus is not a pushbutton
      IF ISFALSE(SendMessage(hWndFocus, %WM_GETDLGCODE, 0, 0) AND (%DLGC_UNDEFPUSHBUTTON OR %DLGC_DEFPUSHBUTTON)) THEN
        IF ISTRUE IsWindowEnabled(hWndDef) THEN
          SendMessage hWndDef, %BM_SETSTYLE, %BS_DEFPUSHBUTTON, %TRUE
        END IF
      END IF
    END IF
  ELSE
    EnableWindow hWndCtrl, fEnable
  END IF

END FUNCTION

'----------------------------------------------------------------------
'
' FUNCTION: GetNextDlgCtl
' PURPOSE:  Sets the keyboard focus to a different control in the
'           specified window.
'
'----------------------------------------------------------------------

FUNCTION GetNextDlgCtl _
  ( _
  BYVAL hWnd    AS DWORD, _ ' handle of window
  BYVAL wParam  AS DWORD, _ ' handle of control receiving the focus
  BYVAL lParam  AS LONG _   ' handle flag
  ) AS LONG

  LOCAL hWndChild AS DWORD

  hWnd = phnxGetFormHandle(hWnd)

  hWndChild = wParam

  IF ISFALSE lParam THEN
    hWndChild = GetNextTabItem(hWnd, GetFocus(), wParam)
  END IF
  IF (ISFALSE IsWindowEnabled(hWndChild)) OR (ISFALSE IsWindowVisible(hWndChild)) THEN
    hWndChild = GetNextTabItem(hWnd, %NULL, %FALSE)
  END IF
  IF ISTRUE hWndChild THEN SetCtrlFocus hWnd, hWndChild

END FUNCTION

'----------------------------------------------------------------------
'
' FUNCTION: SaveCtrlFocus
' PURPOSE:  Saves the control with the keyboard focus.
'
'----------------------------------------------------------------------

FUNCTION SaveCtrlFocus _
  ( _
  BYVAL hWnd  AS DWORD _  ' handle of window
  ) AS LONG

  LOCAL ptkf      AS KEYBOARDFOCUS PTR
  LOCAL hWndFocus AS DWORD
  LOCAL hWndDef   AS DWORD

  hWnd = phnxGetFormHandle(hWnd)

  ptkf = GetProp(hWnd, "KEYBOARDFOCUS")

  hWndFocus = GetFocus()

  IF ISTRUE ptkf THEN
    IF ISTRUE IsChild(hWnd, hWndFocus) THEN
      @ptkf.hWndFocus = hWndFocus
    END IF
  END IF
  ' Remove the heavy border of the default button or the button with the focus
  hWndDef = FindDefButton(hWnd)
  IF ISTRUE hWndDef THEN
    IF ISTRUE(SendMessage(hWndDef, %WM_GETDLGCODE, 0, 0) AND %DLGC_DEFPUSHBUTTON) THEN
      SendMessage hWndDef, %BM_SETSTYLE, %BS_PUSHBUTTON, %TRUE
    END IF
  END IF

END FUNCTION

'----------------------------------------------------------------------
'
' FUNCTION: RestoreCtrlFocus
' PURPOSE:  Restores the keyboard focus.
'
'----------------------------------------------------------------------

FUNCTION RestoreCtrlFocus _
  ( _
  BYVAL hWnd  AS DWORD _  ' handle of window
  ) AS LONG

  LOCAL ptkf      AS KEYBOARDFOCUS PTR
  LOCAL hWndFocus AS DWORD

  hWnd = phnxGetFormHandle(hWnd)

  ptkf = GetProp(hWnd, "KEYBOARDFOCUS")

  IF ISFALSE IsIconic(hWnd) THEN
    hWndFocus = GetNextTabItem(hWnd, %NULL, %FALSE)
    IF ISTRUE ptkf THEN
      IF ISFALSE @ptkf.bClosed THEN
        IF ISTRUE IsWindow(@ptkf.hWndFocus) THEN
          ' Don't set the focus back to controls if window has been closed.
          hWndFocus = @ptkf.hWndFocus
        ELSE
          @ptkf.hWndFocus = hWndFocus
        END IF
      END IF
    END IF
    SetCtrlFocus hWnd, hWndFocus
  END IF

END FUNCTION

'----------------------------------------------------------------------
'
' FUNCTION: GetDefID
' PURPOSE:  Retrieves the identifier of the default push button.
'
'----------------------------------------------------------------------

FUNCTION GetDefID _
  ( _
  BYVAL hWnd  AS DWORD _  ' handle of window
  ) AS LONG

  LOCAL ptkf      AS KEYBOARDFOCUS PTR
  LOCAL hWndChild AS DWORD

  hWnd = phnxGetFormHandle(hWnd)

  ptkf = GetProp(hWnd, "KEYBOARDFOCUS")

  IF ISTRUE ptkf THEN
    IF ISFALSE @ptkf.bClosed THEN
      IF ISTRUE @ptkf.wDefID THEN
        FUNCTION = MAKLNG(@ptkf.wDefID, %DC_HASDEFID)
        EXIT FUNCTION
      END IF
      hWndChild = FindDefButton(hWnd)
      IF ISTRUE hWndChild THEN
        FUNCTION = MAKLNG(GetDlgCtrlID(hWndChild), %DC_HASDEFID)
        EXIT FUNCTION
      END IF
    END IF
  END IF

  FUNCTION = %FALSE

END FUNCTION

'----------------------------------------------------------------------
'
' FUNCTION: SetDefID
' PURPOSE:  Sets the new default push button.
'
'----------------------------------------------------------------------

FUNCTION SetDefID _
  ( _
  BYVAL hWnd    AS DWORD, _ ' handle of window
  BYVAL wDefID  AS WORD _   ' identifier of new default button
  ) AS LONG

  LOCAL ptkf      AS KEYBOARDFOCUS PTR
  LOCAL hWndNew   AS DWORD
  LOCAL hWndDef   AS DWORD
  LOCAL hWndBtn   AS DWORD
  LOCAL hWndFocus AS DWORD
  LOCAL dwDlgCode AS DWORD

  hWnd = phnxGetFormHandle(hWnd)

  ptkf = GetProp(hWnd, "KEYBOARDFOCUS")

  hWndNew = FindDefIdHandle(hWnd, wDefID)
  IF ISTRUE hWndNew THEN
    dwDlgCode = SendMessage(hWndNew, %WM_GETDLGCODE, 0, 0)
    ' If destination is not a pushbutton
    IF ISFALSE(dwDlgCode AND (%DLGC_UNDEFPUSHBUTTON OR %DLGC_DEFPUSHBUTTON)) THEN
      FUNCTION = %TRUE
      EXIT FUNCTION
    END IF
  END IF
  IF ISTRUE ptkf THEN
    IF ISFALSE @ptkf.bClosed THEN
      hWndDef = FindDefIdHandle(hWnd, @ptkf.wDefID)
      IF ISTRUE hWndNew THEN
        @ptkf.wDefID = wDefID
      ELSE
        @ptkf.wDefID = 0
      END IF
      ' Do a visual clean up
      hWndFocus = GetFocus()
      hWndBtn   = FindDefButton(hWnd)
      IF ISTRUE hWndDef THEN
        SendMessage hWndDef, %BM_SETSTYLE, %BS_PUSHBUTTON, %TRUE
      END IF
      IF ISTRUE hWndBtn THEN
        IF hWndBtn <> hWndDef THEN
          SendMessage hWndBtn, %BM_SETSTYLE, %BS_PUSHBUTTON, %TRUE
        END IF
      END IF
      IF ISTRUE hWndNew THEN
        ' If the focus is not a pushbutton
        IF ISFALSE(SendMessage(hWndFocus, %WM_GETDLGCODE, 0, 0) AND (%DLGC_UNDEFPUSHBUTTON OR %DLGC_DEFPUSHBUTTON)) THEN
          SendMessage hWndNew, %BM_SETSTYLE, %BS_DEFPUSHBUTTON, %TRUE
        ELSE
          SendMessage hWndFocus, %BM_SETSTYLE, %BS_DEFPUSHBUTTON, %TRUE
        END IF
      END IF
    END IF
  END IF

  FUNCTION = %TRUE

END FUNCTION

'###############################################################################
' END Keyboard focus and default identifier support
'###############################################################################

'------------------------------------------------------------------------------
'
'   FUNCTION: phnxDrawBitmap
'   PURPOSE:  Draws a bitmap.  If fTransparent is nonzero, the bitmap is drawn
'             transparently.
'
'------------------------------------------------------------------------------

FUNCTION phnxDrawBitmap _
  ( _
  BYVAL hDC           AS DWORD, _ ' handle device context
  BYVAL x             AS LONG, _  ' x-coordinate of upper left corner
  BYVAL y             AS LONG, _  ' y-coordinate of upper left corner
  BYVAL hBmp          AS DWORD, _ ' handle of bitmap to draw
  BYVAL cxBmp         AS LONG, _  ' width of the bitmap
  BYVAL cyBmp         AS LONG, _  ' height of the bitmap
  BYVAL fTransparent  AS LONG, _  ' bitmap is drawn transparently if nonzero
  BYVAL dwTransColor  AS DWORD _  ' transparent color or &HFFFFFFFF??? to use color at (0,0)
  ) AS LONG

  LOCAL tbm           AS BITMAP
  LOCAL hDCBmp        AS DWORD
  LOCAL hDCAnd        AS DWORD
  LOCAL hDCInv        AS DWORD
  LOCAL hDCXor        AS DWORD
  LOCAL hBmpOld       AS DWORD
  LOCAL hBmpAndOld    AS DWORD
  LOCAL hBmpInvOld    AS DWORD
  LOCAL hBmpXorOld    AS DWORD
  LOCAL dwColor       AS DWORD

  IF GetObjectType(hBmp) = %OBJ_BITMAP THEN
    IF (cxBmp = 0) OR (cyBmp = 0) THEN
      GetObject hBmp, SIZEOF(tbm), BYVAL VARPTR(tbm)
      cxBmp = tbm.bmWidth
      cyBmp = tbm.bmHeight
    END IF
    ' Save the original bitmap
    ' ------------------------
    hDCBmp  = CreateCompatibleDC(hDC)
    hBmpOld = SelectObject(hDCBmp, hBmp)
    ' If bitmap is not transparent
    IF ISFALSE fTransparent THEN
      ' Copy the finish product to the screen
      BitBlt hDC, x, y, cxBmp, cyBmp, hDCBmp, 0, 0, %SRCCOPY
      ' Select orignal objects back into memory DCs
      SelectObject hDCBmp, hBmpOld
      ' Delete the memory DCs
      DeleteDC hDCBmp
    ' Bitmap is transparent
    ELSE
      ' Create the AND mask
      ' -------------------
      hDCAnd     = CreateCompatibleDC(hDC)
      ' Create monochrome bitmap
      hBmpAndOld = SelectObject(hDCAnd, CreateBitmap(cxBmp, cyBmp, 1, 1, BYVAL %NULL))
      ' Set the background color of the bitmp DC to the color
      ' contained in the parts of the bitmap that should be transparent
      dwColor = SetBkColor(hDCBmp, GetPixel(hDCBmp, 0, 0))
      ' Create the AND mask for the bitmap by copying
      ' the original bitmap to the monochrome bitmap
      BitBlt hDCAnd, 0, 0, cxBmp, cyBmp, hDCBmp, 0, 0, %SRCCOPY
      ' Set the background color of the original DC back to the original color
      SetBkColor hDCBmp, dwColor
      ' Create the INV mask (inverse-AND)
      ' ---------------------------------
      hDCInv     = CreateCompatibleDC(hDC)
      ' Create monochrome bitmap
      hBmpInvOld = SelectObject(hDCInv, CreateBitmap(cxBmp, cyBmp, 1, 1, BYVAL %NULL))
      ' Create the inverse of the AND mask
      BitBlt hDCInv, 0, 0, cxBmp, cyBmp, hDCAnd, 0, 0, %NOTSRCCOPY
      ' Create the XOR mask
      ' -------------------
      hDCXor     = CreateCompatibleDC(hDC)
      ' Create a bitmap for the XOR DC
      hBmpXorOld = SelectObject(hDCXor, CreateCompatibleBitmap(hDC, cxBmp, cyBmp))
      ' Copy the original bitmap to the initial XOR bitmap
      BitBlt hDCXor, 0, 0, cxBmp, cyBmp, hDCBmp, 0, 0, %SRCCOPY
      ' Transfer the INV mask to create the XOR mask
      BitBlt hDCXor, 0, 0, cxBmp, cyBmp, hDCInv, 0, 0, %SRCAND
      ' Apply the masks to the destination bitmap
      ' -----------------------------------------
      ' Apply the AND mask
      BitBlt hDC, 0, 0, cxBmp, cyBmp, hDCAnd, 0, 0, %SRCAND
      ' Apply the XOR mask
      BitBlt hDC, 0, 0, cxBmp, cyBmp, hDCXor, 0, 0, %SRCINVERT
      ' Clean up
      ' --------
      ' Select orignal objects back into memory DCs
      SelectObject hDCBmp, hBmpOld
      ' Delete the memory bitmaps
      DeleteObject SelectObject(hDCAnd, hBmpAndOld)
      DeleteObject SelectObject(hDCInv, hBmpInvOld)
      DeleteObject SelectObject(hDCXor, hBmpXorOld)
      ' Delete the memory DCs
      DeleteDC hDCBmp
      DeleteDC hDCAnd
      DeleteDC hDCInv
      DeleteDC hDCXor
    END IF
  END IF

END FUNCTION

'###############################################################################
' BEGIN CoolMenu
'###############################################################################

' Constants used for drawing
%CXGAP            = 1     ' num pixels between button and text
%CXTEXTMARGIN     = 2     ' num pixels pixels after hilite to start text
%CXBUTTONMARGIN   = 2     ' num pixels wider button is than bitmap
%CYBUTTONMARGIN   = 2     ' num pixels higher button is than bitmap

' Owner-draw menu item info
TYPE MENUITEMDATA ' mid
  dwMenuType    AS DWORD                ' menu type: "PHNX" 0x584E4850
  hInstance     AS DWORD                ' handle of instance with bitmap resources
  hMenu         AS DWORD                ' handle of popup menu
  szText        AS ASCIIZ * %MAX_PATH   ' item text
  fType         AS DWORD                ' original item type flags
  fState        AS DWORD                ' original item state
  hImlItem      AS DWORD                ' handle of item image list
  iItem         AS LONG                 ' index of item image in item image list
  hImlButton    AS DWORD                ' handle of button image list
  iButton       AS LONG                 ' index of button image in button image list
  fFlat         AS LONG                 ' TRUE: button images are always drawn flat
  fAlignRight   AS LONG                 ' TRUE: right-align accelerators
  wBmpId        AS WORD                 ' Resource identifier of left-margin bitmap
  cxAccelMax    AS LONG                 ' INTERNAL USE: width of longest accelerator string
  cxBmp         AS LONG                 ' INTERNAL USE: width of left-margin bitmap
  cxGapBmp      AS LONG                 ' INTERNAL USE: gap between left-margin bitmap and button image
  lpPopup       AS DWORD                ' address of popup title MENUITEMDATA
END TYPE

' Menu data
' Organization of resource data
TYPE MENUDATA
  wItemID AS WORD           ' menu item identifier(command id)
  iItem   AS INTEGER        ' index of item bitmap or -1(none)
  iButton AS INTEGER        ' index of button bitmap or -1(none)
  wBmpID  AS WORD           ' resource identifier of left-margin bitmap
END TYPE

'----------------------------------------------------------------------
'
' FUNCTION: CoolMenu_IsValidWritePtr
' PURPOSE:  Determines if the specified address was allocated by
'           the CoolMenu_Alloc.
' RETURN:   TRUE if memory was allocated by CoolMenu_Alloc, FALSE
'           if it was not.
'
'----------------------------------------------------------------------

FUNCTION CoolMenu_IsValidWritePtr _
  ( _
  BYVAL lptmid  AS DWORD _  ' base address of menu data
  ) AS LONG

  LOCAL     tmid          AS MENUITEMDATA
  LOCAL     ptmid         AS MENUITEMDATA PTR

  ptmid = lptmid

  IF ISTRUE ptmid THEN
    IF ISFALSE IsBadCodePtr(ptmid) THEN
      IF ISFALSE IsBadWritePtr(ptmid, SIZEOF(tmid)) THEN
        IF @ptmid.dwMenuType = &H584E4850??? THEN
          FUNCTION = %TRUE
          EXIT FUNCTION
        END IF
      END IF
    END IF
  END IF

  FUNCTION = %FALSE

END FUNCTION

'----------------------------------------------------------------------
'
' FUNCTION: CoolMenu_Alloc
' PURPOSE:  Allocates memory for menu item data(MENUITEMDATA).
'
'----------------------------------------------------------------------

FUNCTION CoolMenu_Alloc _
  ( _
  BYVAL hMenu       AS DWORD, _         ' handle of menu/submenu
        tmid        AS MENUITEMDATA, _  ' MENUITEMDATA info
  BYVAL lptmd       AS DWORD, _         ' base address of menu data
        lIndex      AS LONG, _          ' index into menu data
  BYVAL lMaxItems   AS LONG _           ' maximum number of items in menu data
  ) AS LONG

  REGISTER  lItemIdx      AS LONG
  LOCAL     szItem        AS ASCIIZ * %MAX_PATH
  LOCAL     tmii          AS MENUITEMINFO
  LOCAL     ptmd          AS MENUDATA PTR
  LOCAL     ptmid         AS MENUITEMDATA PTR
  LOCAL     lCount        AS LONG
  LOCAL     fIsWin95WinNT AS LONG

  ptmd = lptmd

  IF ISTRUE hMenu THEN
    fIsWin95WinNT = IsWin95WinNT()
    lCount   = GetMenuItemCount(hMenu)
    lItemIdx = 0

    DO
      IF lItemIdx >= lCount THEN EXIT DO
      IF fIsWin95WinNT THEN
        tmii.cbSize     = %MENUITEMINFO_WIN95_SIZE
        tmii.fMask      = %MIIM_TYPE OR %MIIM_STATE OR %MIIM_SUBMENU
      ELSE
        tmii.cbSize     = SIZEOF(tmii)
        tmii.fMask      = %MIIM_FTYPE OR %MIIM_STATE OR %MIIM_SUBMENU OR %MIIM_STRING
      END IF
      tmii.cch        = %MAX_PATH
      tmii.dwTypeData = VARPTR(szItem)
      GetMenuItemInfo hMenu, lItemIdx, %TRUE, BYVAL VARPTR(tmii)
      ptmid = HeapAlloc(GetProcessHeap(), %HEAP_ZERO_MEMORY, SIZEOF(tmid))
      IF ISTRUE ptmid THEN
        @ptmid.dwMenuType  = tmid.dwMenuType
        @ptmid.hInstance   = tmid.hInstance
        @ptmid.fFlat       = tmid.fFlat
        @ptmid.fAlignRight = tmid.fAlignRight
        @ptmid.lpPopup     = tmid.lpPopup
        @ptmid.hMenu       = hMenu
        @ptmid.szText      = szItem
        @ptmid.fType       = tmii.fType
        @ptmid.fState      = tmii.fState
        IF (tmii.fType AND %MFT_SEPARATOR) <> %MFT_SEPARATOR THEN
          IF lIndex < lMaxItems THEN
            @ptmid.iItem   = @ptmd[lIndex].iItem
            @ptmid.iButton = @ptmd[lIndex].iButton
            @ptmid.wBmpId  = @ptmd[lIndex].wBmpID
          ELSE
            @ptmid.iItem   = -1
            @ptmid.iButton = -1
            @ptmid.wBmpId  = 0
          END IF
          INCR lIndex
        END IF
        tmii.fMask      = %MIIM_DATA
        tmii.dwItemData = ptmid
        SetMenuItemInfo hMenu, lItemIdx, %TRUE, BYVAL VARPTR(tmii)
      END IF
      ' Do submenus of the current menu
      IF ISTRUE tmii.hSubMenu THEN
        tmid.lpPopup = ptmid
        CoolMenu_Alloc tmii.hSubMenu, tmid, BYVAL ptmd, lIndex, lMaxItems
      END IF
      INCR lItemIdx
    LOOP

  END IF

END FUNCTION

'----------------------------------------------------------------------
'
' FUNCTION: CoolMenu_SetData
' PURPOSE:  Loads menu data from the specified resource module.
'
'----------------------------------------------------------------------

FUNCTION CoolMenu_SetData _
  ( _
  BYVAL hMenu     AS DWORD, _   ' handle of menu
  BYVAL hInstance AS DWORD, _   ' handle of module with menu data
  BYVAL wResID    AS WORD  _    ' menu data identifier
  ) AS LONG

  LOCAL     tmid        AS MENUITEMDATA
  LOCAL     tmd         AS MENUDATA
  LOCAL     pwFlags     AS WORD PTR
  LOCAL     ptmd        AS MENUDATA PTR
  LOCAL     hResInfo    AS DWORD
  LOCAL     hRes        AS DWORD
  LOCAL     lpRes       AS DWORD
  LOCAL     cblRes      AS LONG
  LOCAL     lCount      AS LONG
  LOCAL     fFlat       AS LONG
  LOCAL     fAlignRight AS LONG
  LOCAL     lIndex      AS LONG

  IF ISTRUE IsMenu(hMenu) THEN
    ' Load the menu data
    hResInfo = FindResource(hInstance, BYVAL wResID, BYVAL %RT_RCDATA)
    IF ISTRUE hResInfo THEN
      cblRes = SizeofResource(hInstance, hResInfo)
      hRes   = LoadResource(hInstance, hResInfo)
      IF ISTRUE hRes THEN
        lpRes = LockResource(hRes)
        IF ISTRUE lpRes THEN
          ' Get the flags
          pwFlags = lpRes
          fFlat = @pwFlags
          INCR pwFlags
          fAlignRight = @pwFlags
          INCR pwFlags
          ' Base address of items
          ptmd = pwFlags
          ' Get the approximate count of items
          lCount = (cblRes - 4) \ SIZEOF(tmd)

          ' Initialize common attributes
          tmid.dwMenuType  = &H584E4850???  ' "PHNX"
          tmid.hInstance   = hInstance
          tmid.fFlat       = fFlat
          tmid.fAlignRight = fAlignRight
          tmid.lpPopup     = %NULL

          CoolMenu_Alloc hMenu, tmid, BYVAL ptmd, lIndex, lCount
        END IF
        FreeResource hRes
      END IF
    END IF
  END IF

END FUNCTION

'----------------------------------------------------------------------
'
' FUNCTION: CoolMenu_Load
' PURPOSE:  Loads menu data from the specified resource module.
' RETURN:   Handle of menu or NULL.
'
'----------------------------------------------------------------------

FUNCTION CoolMenu_Load _
  ( _
  BYVAL hInstance   AS DWORD, _   ' handle of module with menu data
  BYVAL wResID      AS WORD  _    ' menu data identifier
  ) AS LONG

  LOCAL     hMenu       AS DWORD

  hMenu = LoadMenu(hInstance, BYVAL wResID)
  IF ISTRUE hMenu THEN
    CoolMenu_SetData hMenu, hInstance, wResID
  END IF

  FUNCTION = hMenu

END FUNCTION

'----------------------------------------------------------------------
'
' FUNCTION: CoolMenu_SetImageList
' PURPOSE:  Sets the imagelists used by a CoolMenu.
'
'----------------------------------------------------------------------

FUNCTION CoolMenu_SetImageList _
  ( _
  BYVAL hMenu       AS DWORD, _ ' handle of top-level menu
  BYVAL fButtons    AS LONG, _  ' TRUE: button imagelist. FALSE: item imagelist
  BYVAL hImageList  AS DWORD _  ' handle of imagelist
  ) AS LONG

  REGISTER  lItemIdx      AS LONG
  LOCAL     tmii          AS MENUITEMINFO
  LOCAL     ptmid         AS MENUITEMDATA PTR
  LOCAL     lCount        AS LONG

  IF ISTRUE hMenu THEN
    IF IsWin95WinNT() THEN
      tmii.cbSize     = %MENUITEMINFO_WIN95_SIZE
    ELSE
      tmii.cbSize     = SIZEOF(tmii)
    END IF
    tmii.fMask      = %MIIM_DATA OR %MIIM_SUBMENU
    lCount   = GetMenuItemCount(hMenu)
    lItemIdx = 0

    DO
      IF lItemIdx >= lCount THEN EXIT DO
      GetMenuItemInfo hMenu, lItemIdx, %TRUE, BYVAL VARPTR(tmii)
      ptmid = tmii.dwItemData
      IF ISTRUE CoolMenu_IsValidWritePtr(ptmid) THEN
        IF ISTRUE fButtons THEN
          @ptmid.hImlButton = hImageList
        ELSE
          @ptmid.hImlItem   = hImageList
        END IF
      END IF
      ' Do submenus of the current menu
      IF ISTRUE tmii.hSubMenu THEN
        CoolMenu_SetImageList tmii.hSubMenu, fButtons, hImageList
      END IF
      INCR lItemIdx
    LOOP

  END IF

END FUNCTION

'----------------------------------------------------------------------
'
' FUNCTION: CoolMenu_GetImageList
' PURPOSE:  Retrieves the handle of the specified imagelist.
'
'----------------------------------------------------------------------

FUNCTION CoolMenu_GetImageList _
  ( _
  BYVAL hMenu     AS DWORD,  _  ' handle of top-level or popup menu
  BYVAL fButtons  AS LONG _     ' If TRUE, handle of Buttons imagelist is retrieved
  ) AS LONG

  REGISTER  lItemIdx      AS LONG
  LOCAL     tmii          AS MENUITEMINFO
  LOCAL     ptmid         AS MENUITEMDATA PTR
  LOCAL     hSubmenu      AS DWORD
  LOCAL     hImageList    AS DWORD
  LOCAL     lCount        AS LONG

  IF ISTRUE hMenu THEN
    IF ISTRUE IsWin95WinNT() THEN
      tmii.cbSize = %MENUITEMINFO_WIN95_SIZE
    ELSE
      tmii.cbSize = SIZEOF(tmii)
    END IF
    lCount   = GetMenuItemCount(hMenu)
    lItemIdx = 0

    DO
      IF lItemIdx >= lCount THEN EXIT DO
      tmii.fMask = %MIIM_DATA OR %MIIM_SUBMENU
      GetMenuItemInfo hMenu, lItemIdx, %TRUE, BYVAL VARPTR(tmii)
      ' Save the handle of the submenu
      hSubmenu = tmii.hSubMenu
      ptmid = tmii.dwItemData
      IF ISTRUE CoolMenu_IsValidWritePtr(ptmid) THEN
        IF ISTRUE fButtons THEN
          hImageList = @ptmid.hImlButton
        ELSE
          hImageList = @ptmid.hImlItem
        END IF
        EXIT DO
      END IF
      ' Do submenus of the current menu
      IF ISTRUE hSubMenu THEN
        hImageList = CoolMenu_GetImageList(hSubMenu, fButtons)
        IF ISTRUE hImageList THEN EXIT DO
      END IF
      INCR lItemIdx
    LOOP

  END IF

  FUNCTION = hImageList

END FUNCTION

'----------------------------------------------------------------------
'
' FUNCTION: CoolMenu_GetRedValue
' PURPOSE:  Retrieves the red component of the specified RGB value.
' RETURNS:  Red component.
'
'----------------------------------------------------------------------

FUNCTION CoolMenu_GetRedValue _
  ( _
  BYVAL dwRGB AS DWORD _    ' RGB value
  ) AS BYTE

  ! mov eax, dwRGB                    ; RGB value
  ! mov FUNCTION, al                  ; return the red component

END FUNCTION

'----------------------------------------------------------------------
'
' FUNCTION: CoolMenu_GetGreenValue
' PURPOSE:  Retrieves the green component of the specified RGB value.
' RETURNS:  Green component.
'
'----------------------------------------------------------------------

FUNCTION CoolMenu_GetGreenValue _
  ( _
  BYVAL dwRGB AS DWORD _    ' RGB value
  ) AS BYTE

  ! mov eax, dwRGB                    ; RGB value
  ! ror eax, 8                        ; rotate right by 8 bits
  ! mov FUNCTION, al                  ; return the green component

END FUNCTION

'----------------------------------------------------------------------
'
' FUNCTION: CoolMenu_GetBlueValue
' PURPOSE:  Retrieves the blue component of the specified RGB value.
' RETURNS:  Blue component.
'
'----------------------------------------------------------------------

FUNCTION CoolMenu_GetBlueValue _
  ( _
  BYVAL dwRGB AS DWORD _    ' RGB value
  ) AS BYTE

  ! mov eax, dwRGB                    ; RGB value
  ! ror eax, 16                       ; rotate right by 16 bits
  ! mov FUNCTION, al                  ; return the blue component

END FUNCTION

'----------------------------------------------------------------------
'
' FUNCTION: CoolMenu_DisableRect
' PURPOSE:  Retrieves the red component of the specified RGB value.
' RETURNS:  Red component.
'
'----------------------------------------------------------------------

FUNCTION CoolMenu_DisableRect _
  ( _
  BYVAL hDC           AS DWORD, _   ' device context
        trc           AS RECT, _    ' bounding box of area to be disabled
  BYVAL dwTransColor  AS DWORD, _   ' usually the background color(brush color)
  BYVAL fHiliteOnly   AS LONG, _
  BYVAL fEmbossed     AS LONG _
  ) AS LONG

  REGISTER  x             AS LONG
  REGISTER  y             AS LONG
  LOCAL     bRed          AS BYTE
  LOCAL     bGreen        AS BYTE
  LOCAL     bBlue         AS BYTE
  LOCAL     bRed1         AS BYTE
  LOCAL     bGreen1       AS BYTE
  LOCAL     bBlue1        AS BYTE
  LOCAL     bRed2         AS BYTE
  LOCAL     bGreen2       AS BYTE
  LOCAL     bBlue2        AS BYTE
  LOCAL     bRedT         AS BYTE
  LOCAL     bGreenT       AS BYTE
  LOCAL     bBlueT        AS BYTE
  LOCAL     bRedS         AS BYTE
  LOCAL     bGreenS       AS BYTE
  LOCAL     bBlueS        AS BYTE
  LOCAL     bRedH         AS BYTE
  LOCAL     bGreenH       AS BYTE
  LOCAL     bBlueH        AS BYTE
  LOCAL     bIntBkg       AS BYTE
  LOCAL     bIntCur       AS BYTE
  LOCAL     tbmi          AS BITMAPINFO
  LOCAL     pbBits        AS BYTE PTR
  LOCAL     pbCopy        AS BYTE PTR
  LOCAL     dwColor       AS DWORD
  LOCAL     hDIB          AS DWORD
  LOCAL     hTemp         AS DWORD
  LOCAL     hPal          AS DWORD
  LOCAL     hDCDest       AS DWORD
  LOCAL     hBmpDestOld   AS DWORD
  LOCAL     xMax          AS LONG
  LOCAL     yMax          AS LONG
  LOCAL     x1            AS LONG
  LOCAL     y1            AS LONG
  LOCAL     cxPaint       AS LONG
  LOCAL     cyPaint       AS LONG
  LOCAL     cblPerLine    AS LONG
  LOCAL     cblImage      AS LONG
  LOCAL     lOffset       AS LONG
  LOCAL     fSkip         AS LONG

  cxPaint = trc.nRight - trc.nLeft
  cyPaint = trc.nBottom - trc.nTop

  ' Create the destination bitmap(a 24 bpp top down dib)
  ' ----------------------------------------------------
  ' Calculate bytes per scan line
  cblPerLine = ((cxPaint * 3 + 3) \ 4) * 4
  cblImage   = cblPerLine * cyPaint
  tbmi.bmiHeader.biSize         = SIZEOF(tbmi.bmiHeader)
  tbmi.bmiHeader.biWidth        = cxPaint
  tbmi.bmiHeader.biHeight       = -cyPaint
  tbmi.bmiHeader.biPlanes       = 1
  tbmi.bmiHeader.biBitCount     = 24
  tbmi.bmiHeader.biCompression  = %BI_RGB
  tbmi.bmiHeader.biSizeImage    = cblImage
  tbmi.bmiHeader.biClrUsed      = 0
  tbmi.bmiHeader.biClrImportant = 0
  hDIB = CreateDIBSection(hDC, tbmi, %DIB_RGB_COLORS, VARPTR(pbBits), %NULL, 0)
  IF ISTRUE hDIB THEN
    hDCDest     = CreateCompatibleDC(hDC)
    hBmpDestOld = SelectObject(hDCDest, hDIB)
    BitBlt hDCDest, 0, 0, cxPaint, cyPaint, hDC, trc.nLeft, trc.nTop, %SRCCOPY
    pbCopy = HeapAlloc(GetProcessHeap(), %HEAP_ZERO_MEMORY, cblImage)
    IF ISTRUE pbCopy THEN
      ! push  ebx
      ! push  esi
      ! push  edi
      ! mov   ecx, cblImage
      ! mov   esi, pbBits
      ! mov   edi, pbCopy
      ! cld
      ! rep   movsb
      ! pop   edi
      ! pop   esi
      ! pop   ebx

      ' Transparent(range)
      bBlueT  = CoolMenu_GetBlueValue(dwTransColor)
      bBlue1  = MAX(0, bBlueT - 8)
      bBlue2  = MIN(bBlueT + 8, 255)
      bGreenT = CoolMenu_GetGreenValue(dwTransColor)
      bGreen1 = MAX(0, bGreenT - 8)
      bGreen2 = MIN(bGreenT + 8, 255)
      bRedT   = CoolMenu_GetRedValue(dwTransColor)
      bRed1   = MAX(0, bRedT - 8)
      bRed2   = MIN(bRedT + 8, 255)
      ' Highlight
      dwColor = GetSysColor(%COLOR_BTNHIGHLIGHT)
      bBlueH  = CoolMenu_GetBlueValue(dwColor)
      bGreenH = CoolMenu_GetGreenValue(dwColor)
      bRedH   = CoolMenu_GetRedValue(dwColor)
      ' Shadow
      dwColor = GetSysColor(%COLOR_BTNSHADOW)
      bBlueS  = CoolMenu_GetBlueValue(dwColor)
      bGreenS = CoolMenu_GetGreenValue(dwColor)
      bRedS   = CoolMenu_GetRedValue(dwColor)
      ' If shadow equals transparent, use average of shadow and highlight
      IF (bBlueS >= bBlue1) AND (bBlueS <= bBlue2) THEN
        IF (bGreenS >= bGreen1) AND (bGreenS <= bGreen2) THEN
          IF (bRedS >= bRed1) AND (bRedS <= bRed2) THEN
            bBlueS  = (bBlueH + bBlueS) \ 2
            bGreenS = (bGreenH + bGreenS) \ 2
            bRedS   = (bRedH + bRedS) \ 2
          END IF
        END IF
      END IF

      ' Background intensity
      bIntBkg = (bBlueT + bGreenT + bRedT) \ 3

      xMax    = cblPerLine - 3
      yMax    = cblImage - cblPerLine

      FOR y = 0 TO yMax STEP cblPerLine

        FOR x = 0 TO xMax STEP 3
          lOffset = y + x
          bBlue   = @pbCopy[lOffset]
          bGreen  = @pbCopy[lOffset + 1]
          bRed    = @pbCopy[lOffset + 2]
          fSkip   = %FALSE
          ' Check if current color can be considered to be transparent
          IF (bBlue >= bBlue1) AND (bBlue <= bBlue2) THEN
            IF (bGreen >= bGreen1) AND (bGreen <= bGreen2) THEN
              IF (bRed >= bRed1) AND (bRed <= bRed2) THEN
                fSkip = %TRUE
              END IF
            END IF
          END IF
          IF ISFALSE fSkip THEN
            ' Intensity at current pixel
            bIntCur = (bBlue + bGreen + bRed) \ 3
            ' If shadow can be applied
            IF ((bIntBkg <= 128) AND (bIntCur > 128)) OR ((bIntBkg > 128) AND (bIntCur <= 128)) OR ((bIntBkg < 128) AND (bIntCur < 128)) THEN
              IF ISFALSE fHiliteOnly THEN
                @pbBits[lOffset]     = bBlueS
                @pbBits[lOffset + 1] = bGreenS
                @pbBits[lOffset + 2] = bRedS
                ELSEIF ISTRUE fHiliteOnly THEN
                  @pbBits[lOffset]     = bBlueH
                  @pbBits[lOffset + 1] = bGreenH
                  @pbBits[lOffset + 2] = bRedH
              END IF
              IF ISTRUE fEmbossed THEN
                y1 = y + cblPerLine
                x1 = x + 3
                IF (y1 <= yMax) AND (x1 <= xMax) THEN
                  lOffset = y1 + x1
                  @pbBits[lOffset]     = bBlueH
                  @pbBits[lOffset + 1] = bGreenH
                  @pbBits[lOffset + 2] = bRedH
                END IF
              END IF
            ' Treat pixel as transparent
            ELSE
              @pbBits[lOffset]     = bBlueT
              @pbBits[lOffset + 1] = bGreenT
              @pbBits[lOffset + 2] = bRedT
            END IF
          END IF
        NEXT x

      NEXT Y

      ' Note: If the color resolution of the display is less than 24 bpp
      '       we will need to select and realize a palette into the screen
      '       DC so that we will have a reasonable color match.
      IF GetDeviceCaps(hDC, %BITSPIXEL) < 24 THEN
        hPal  = CreateHalftonePalette(hDC)
        hTemp = SelectPalette(hDC, hPal, %FALSE)
        RealizePalette hDC
        BitBlt hDC, trc.nLeft, trc.nTop, cxPaint, cyPaint, hDCDest, 0, 0, %SRCCOPY
        SelectObject hDC, hTemp
        RealizePalette hDC
        DeleteObject hPal
      ELSE
        BitBlt hDC, trc.nLeft, trc.nTop, cxPaint, cyPaint, hDCDest, 0, 0, %SRCCOPY
      END IF
      HeapFree GetProcessHeap(), 0, pbCopy
    END IF
    SelectObject hDCDest, hBmpDestOld
    DeleteObject hDIB
    DeleteDC hDCDest
  END IF

END FUNCTION

'----------------------------------------------------------------------
'
' FUNCTION: CoolMenu_ToOwnerDraw
' PURPOSE:  Converts only items in the current popup menu to
'           owner-draw.
'
'----------------------------------------------------------------------

FUNCTION CoolMenu_ToOwnerDraw _
  ( _
  BYVAL hMenu       AS DWORD _  ' popup menu handle
  ) AS LONG

  REGISTER  lItemIdx      AS LONG
  LOCAL     szItem        AS ASCIIZ * %MAX_PATH
  LOCAL     tbm           AS BITMAP
  LOCAL     tmii          AS MENUITEMINFO
  LOCAL     ptmid         AS MENUITEMDATA PTR
  LOCAL     hBmp          AS DWORD
  LOCAL     lCount        AS LONG
  LOCAL     fIsWin95WinNT AS LONG

  IF ISTRUE hMenu THEN
    fIsWin95WinNT = IsWin95WinNT()
    ' Get the popup title info using any item on this popup
    ' (the first item is used)
    IF fIsWin95WinNT THEN
      tmii.cbSize     = %MENUITEMINFO_WIN95_SIZE
    ELSE
      tmii.cbSize     = SIZEOF(tmii)
    END IF
    tmii.fMask = %MIIM_DATA
    GetMenuItemInfo hMenu, 0, %TRUE, BYVAL VARPTR(tmii)
    ptmid = tmii.dwItemData
    IF ISTRUE CoolMenu_IsValidWritePtr(ptmid) THEN
      ptmid = @ptmid.lpPopup
      IF ISTRUE CoolMenu_IsValidWritePtr(ptmid) THEN
        IF ISTRUE @ptmid.wBmpId THEN
          hBmp = LoadBitmap(@ptmid.hInstance, BYVAL @ptmid.wBmpId)
          IF ISTRUE hBmp THEN
            GetObject hBmp, SIZEOF(tbm), BYVAL VARPTR(tbm)
            @ptmid.cxBmp    = tbm.bmWidth
            @ptmid.cxGapBmp = %CXGAP * GetSystemMetrics(%SM_CXBORDER)
            DeleteObject hBmp
          END IF
        END IF
      END IF
    END IF
    lCount   = GetMenuItemCount(hMenu)
    lItemIdx = 0

    DO
      IF lItemIdx >= lCount THEN EXIT DO
      IF fIsWin95WinNT THEN
        tmii.cbSize     = %MENUITEMINFO_WIN95_SIZE
        tmii.fMask      = %MIIM_TYPE OR %MIIM_STATE OR %MIIM_DATA
      ELSE
        tmii.cbSize     = SIZEOF(tmii)
        tmii.fMask      = %MIIM_FTYPE OR %MIIM_STATE OR %MIIM_DATA OR %MIIM_STRING
      END IF
      tmii.cch        = %MAX_PATH
      tmii.dwTypeData = VARPTR(szItem)
      GetMenuItemInfo hMenu, lItemIdx, %TRUE, BYVAL VARPTR(tmii)
      ' Save items that may have change the last time the menu was accessed.
      ptmid = tmii.dwItemData
      IF ISTRUE CoolMenu_IsValidWritePtr(ptmid) THEN
        @ptmid.fState = tmii.fState
        @ptmid.hMenu  = hMenu
        IF (tmii.fType AND %MFT_OWNERDRAW) <> %MFT_OWNERDRAW THEN
          @ptmid.szText = szItem
          tmii.fType = tmii.fType OR %MFT_OWNERDRAW
          IF fIsWin95WinNT THEN
            tmii.fMask = %MIIM_TYPE
          ELSE
            tmii.fMask = %MIIM_FTYPE
          END IF
          SetMenuItemInfo hMenu, lItemIdx, %TRUE, BYVAL VARPTR(tmii)
        END IF
      END IF
      INCR lItemIdx
    LOOP

  END IF

END FUNCTION

'----------------------------------------------------------------------
'
' FUNCTION: CoolMenu_Revert
' PURPOSE:  Converts menu items from ower draw back to their
'           original type.
'
'----------------------------------------------------------------------

FUNCTION CoolMenu_Revert _
  ( _
  BYVAL hMenu   AS DWORD  _ ' handle of top-level menu
  ) AS LONG

  REGISTER  lItemIdx      AS LONG
  LOCAL     tmii          AS MENUITEMINFO
  LOCAL     ptmid         AS MENUITEMDATA PTR
  LOCAL     hSubmenu      AS DWORD
  LOCAL     lCount        AS LONG
  LOCAL     fIsWin95WinNT AS LONG

  IF ISTRUE hMenu THEN
    fIsWin95WinNT = IsWin95WinNT()
    lCount   = GetMenuItemCount(hMenu)
    lItemIdx = 0

    DO
      IF lItemIdx >= lCount THEN EXIT DO
      IF fIsWin95WinNT THEN
        tmii.cbSize     = %MENUITEMINFO_WIN95_SIZE
      ELSE
        tmii.cbSize     = SIZEOF(tmii)
      END IF
      tmii.fMask = %MIIM_DATA OR %MIIM_SUBMENU
      GetMenuItemInfo hMenu, lItemIdx, %TRUE, BYVAL VARPTR(tmii)
      ' Save the handle of the submenu
      hSubmenu = tmii.hSubMenu
      ' Set the menu to its original type, state and text
      ptmid = tmii.dwItemData
      IF ISTRUE CoolMenu_IsValidWritePtr(ptmid) THEN
'        @ptmid.cxAccelMax = 0
'        @ptmid.cxBmp      = 0
'        @ptmid.cxGapBmp   = 0
        IF fIsWin95WinNT THEN
          tmii.fMask      = %MIIM_TYPE OR %MIIM_STATE
        ELSE
          tmii.fMask      = %MIIM_FTYPE OR %MIIM_STATE OR %MIIM_STRING
        END IF
        tmii.fType      = @ptmid.fType
        tmii.fState     = @ptmid.fState
        tmii.dwTypeData = VARPTR(@ptmid.szText)
        SetMenuItemInfo hMenu, lItemIdx, %TRUE, BYVAL VARPTR(tmii)
      END IF
      ' Do submenus of the current menu
      IF ISTRUE hSubMenu THEN CoolMenu_Revert hSubMenu
      INCR lItemIdx
    LOOP

  END IF

END FUNCTION

'----------------------------------------------------------------------
'
' FUNCTION: CoolMenu_GetItemMnemonic
' PURPOSE:  Returns the mnemonic used in the given text if any.
' NOTES:    The OS uses only the last ampersand as a mnemonic in any
'           given text. Mnemonics are case insensitive so text passed
'           to this function must be in uppercase.
'
'----------------------------------------------------------------------

FUNCTION CoolMenu_GetItemMnemonic _
  ( _
  szText  AS ASCIIZ _
  ) AS BYTE

  LOCAL bMnemonic   AS BYTE
  LOCAL cblText     AS LONG

  cblText = LEN(szText)

  ! mov   edi, szText
  ! cmp   edi, 0                        ; test for NULL pointer
  ! je    gcimExit
  ' Find the start of the keyboard accelerator
gcimTab:
  ! mov   ecx, cblText
  ! cmp   ecx, 2
  ! jb    gcimExit
  ! add   edi, ecx
  ! dec   edi
  ! xor   eax, eax
  ! mov   al, &H09?                     ; load al with the byte to find
  ! std                                 ; read/write backward
  ! repnz scasb                         ; repeat until ecx=0 or byte at [edi] equals al
  ! cmp   ecx, 0
  ! jne   gcimRead
  ! mov   ecx, cblText
  ! add   edi, ecx
  ! dec   edi
  ' Remove extra ampersands
gcimRead:
  ! cmp   ecx, 0                      ; have all bytes been scanned?
  ! je    gcimExit
  ! mov   al, [edi]
  ! cmp   al, &H26?                   ; is byte at edi an ampersand?
  ! je    gcimEsc
  ! dec   edi
  ! dec   ecx
  ! jmp   gcimRead
gcimEsc:
  ! cmp   ecx, 2                      ; if ecx>=2 look at the previous byte
  ! jb    gcimChk
  ! cmp   byte ptr[edi-1], &H26?      ; is the ampersand escaped?
  ! jne   gcimChk
  ! sub   edi, 2
  ! sub   ecx, 2
  ! jmp   gcimRead
gcimChk:
  ! mov   al, byte ptr[edi+1]
  ! cmp   al, &H00?                   ; use the ampersand if it is not the last byte
  ! jne   gcimMne
  ! cmp   al, &H09?
  ! jne   gcimMne
  ! cmp   al, &H26?                   ; use ampersand if it is not followed by an escaped ampersand
  ! jne   gcimMne
  ! dec   edi
  ! dec   ecx
  ! jmp   gcimRead
gcimMne:
  ! mov   bMnemonic, al               ; save the mnemonic used
gcimExit:
  FUNCTION = bMnemonic

END FUNCTION

'----------------------------------------------------------------------
'
' FUNCTION: CoolMenu_OnMenuChar
' PURPOSE:  Processes the WM_MENUCHAR message.
' RETURNS:  The index of the item with the mnemonic character typed
'           by the user.
'
'----------------------------------------------------------------------

FUNCTION CoolMenu_OnMenuChar _
  ( _
  BYVAL hMenu AS DWORD, _   ' popup menu handle
  BYVAL bChar AS BYTE _     ' ASCII character
  ) AS LONG

  REGISTER  lItemIdx      AS LONG
  LOCAL     tmii          AS MENUITEMINFO
  LOCAL     ptmid         AS MENUITEMDATA PTR
  LOCAL     lCount        AS LONG

  IF ISTRUE hMenu THEN
    IF ISTRUE IsWin95WinNT() THEN
      tmii.cbSize = %MENUITEMINFO_WIN95_SIZE
    ELSE
      tmii.cbSize = SIZEOF(tmii)
    END IF
    lCount   = GetMenuItemCount(hMenu)
    lItemIdx = 0

    DO
      IF lItemIdx >= lCount THEN EXIT DO
      tmii.fMask = %MIIM_DATA
      GetMenuItemInfo hMenu, lItemIdx, %TRUE, BYVAL VARPTR(tmii)
      ptmid = tmii.dwItemData
      IF ISTRUE CoolMenu_IsValidWritePtr(ptmid) THEN
        IF CoolMenu_GetItemMnemonic(UCASE$(@ptmid.szText)) = bChar THEN
          FUNCTION = MAKDWD(lItemIdx, 2)
          EXIT FUNCTION
        END IF
      END IF
      INCR lItemIdx
    LOOP

  END IF

  FUNCTION = MAKDWD(0, 0)

END FUNCTION

'----------------------------------------------------------------------
'
' FUNCTION: CoolMenu_DeAlloc
' PURPOSE:  Frees memory associated with menu items.
'
'----------------------------------------------------------------------

FUNCTION CoolMenu_DeAlloc _
  ( _
  BYVAL hMenu   AS DWORD  _ ' handle of top-level or popup menu
  ) AS LONG

  REGISTER  lItemIdx      AS LONG
  LOCAL     tmii          AS MENUITEMINFO
  LOCAL     ptmid         AS MENUITEMDATA PTR
  LOCAL     hSubmenu      AS DWORD
  LOCAL     lCount        AS LONG

  IF ISTRUE hMenu THEN
    IF ISTRUE IsWin95WinNT() THEN
      tmii.cbSize = %MENUITEMINFO_WIN95_SIZE
    ELSE
      tmii.cbSize = SIZEOF(tmii)
    END IF
    lCount   = GetMenuItemCount(hMenu)
    lItemIdx = 0

    DO
      IF lItemIdx >= lCount THEN EXIT DO
      tmii.fMask = %MIIM_DATA OR %MIIM_SUBMENU
      GetMenuItemInfo hMenu, lItemIdx, %TRUE, BYVAL VARPTR(tmii)
      ' Save the handle of the submenu
      hSubmenu = tmii.hSubMenu
      ' Free memory associated with the menu
      ptmid = tmii.dwItemData
      IF ISTRUE CoolMenu_IsValidWritePtr(ptmid) THEN
        HeapFree GetProcessHeap(), 0, ptmid
        tmii.fMask      = %MIIM_DATA
        tmii.dwItemData = %NULL
        SetMenuItemInfo hMenu, lItemIdx, %TRUE, BYVAL VARPTR(tmii)
      END IF
      ' Do submenus of the current menu
      IF ISTRUE hSubMenu THEN CoolMenu_DeAlloc hSubMenu
      INCR lItemIdx
    LOOP

  END IF

END FUNCTION

'----------------------------------------------------------------------
'
' FUNCTION: CoolMenu_Destroy
' PURPOSE:  Frees memory associated with menu items and destroys
'           the menu.
'
'----------------------------------------------------------------------

FUNCTION CoolMenu_Destroy _
  ( _
  BYVAL hMenu   AS DWORD  _ ' handle of top-level menu
  ) AS LONG

  LOCAL hImageList  AS DWORD

  IF ISTRUE hMenu THEN
    hImageList = CoolMenu_GetImageList(hMenu, %FALSE)
    IF ISTRUE hImageList THEN ImageList_Destroy hImageList
    hImageList = CoolMenu_GetImageList(hMenu, %TRUE)
    IF ISTRUE hImageList THEN ImageList_Destroy hImageList
    CoolMenu_DeAlloc hMenu
    DestroyMenu hMenu
  END IF

END FUNCTION

'----------------------------------------------------------------------
'
' FUNCTION: CoolMenu_GetMetrics
' PURPOSE:
'
'----------------------------------------------------------------------

FUNCTION CoolMenu_GetMetrics _
  ( _
  hFont     AS DWORD, _   ' handle of normal font
  hFontBold AS DWORD, _   ' handle of bold font
  cyMenu    AS LONG, _    ' height of a menu item
  cxAveChar AS LONG _     ' average character width
  ) AS LONG

  LOCAL ttm         AS TEXTMETRIC
  LOCAL tsize       AS SIZEL
  LOCAL tncm        AS NONCLIENTMETRICS
  LOCAL hDC         AS LONG
  LOCAL hFontOld    AS LONG
  LOCAL lMapModeOld AS LONG

  tncm.cbSize = SIZEOF(tncm)
  SystemParametersInfo %SPI_GETNONCLIENTMETRICS, SIZEOF(tncm), BYVAL VARPTR(tncm), 0
  ' Menu normal font
  hFont = CreateFontIndirect(tncm.lfMenuFont)
  ' Menu bold font
  tncm.lfMenuFont.lfWeight = %FW_BOLD
  hFontBold = CreateFontIndirect(tncm.lfMenuFont)
  ' Menu height
  cyMenu = tncm.iMenuHeight

  ' Get the device context for the screen
  hDC         = GetDC(%NULL)
  lMapModeOld = SetMapMode(hDC, %MM_TEXT)
  hFontOld    = SelectObject(hDC, hFont)
  ' Average metrics for dialog font
  GetTextExtentPoint hDC,"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz", 52, tsize
  GetTextMetrics hDC, ttm
  ' This is the wacky formula used by Microsoft
  tsize.cx = (tsize.cx / 26)
  ' Round up the average character width
  tsize.cx = (tsize.cx + 1) / 2
'''''''  tsize.cx = (tsize.cx / 26 + 1) / 2
  tsize.cy = ttm.tmHeight
  cxAveChar = tsize.cx
  SelectObject hDC, hFontOld
  SetMapMode hDC, lMapModeOld
  ReleaseDC %NULL, hDC

END FUNCTION

'----------------------------------------------------------------------
'
' FUNCTION: CoolMenu_IsInFirstCol
' PURPOSE:
' RETURNS:
'
'----------------------------------------------------------------------

FUNCTION CoolMenu_IsInFirstCol _
  ( _
  BYVAL hMenu     AS DWORD, _
  BYVAL wItemID   AS WORD _
  ) AS LONG

  REGISTER  lItemIdx    AS LONG
  LOCAL     tmii        AS MENUITEMINFO
  LOCAL     ptmid       AS MENUITEMDATA PTR
  LOCAL     lCount      AS LONG
  LOCAL     lRefIdx     AS LONG

  IF ISTRUE IsWin95WinNT() THEN
    tmii.cbSize = %MENUITEMINFO_WIN95_SIZE
  ELSE
    tmii.cbSize = SIZEOF(tmii)
  END IF
  tmii.fMask  = %MIIM_ID
  lCount = GetMenuItemCount(hMenu)
  ' Find the index of the reference item in the menu
  lItemIdx  = 0

  DO
    IF lItemIdx >= lCount THEN EXIT DO
    GetMenuItemInfo hMenu, lItemIdx, %TRUE, BYVAL VARPTR(tmii)
    IF tmii.wID = wItemID THEN
      lRefIdx = lItemIdx
      EXIT DO
    END IF
    INCR lItemIdx
  LOOP

  ' Check whether it is in the first column by looking at items below it
  tmii.fMask = %MIIM_DATA
  lItemIdx = lRefIdx

  DO
    IF lItemIdx < 0 THEN EXIT DO
    GetMenuItemInfo hMenu, lItemIdx, %TRUE, BYVAL VARPTR(tmii)
    ptmid = tmii.dwItemData
    IF ISTRUE CoolMenu_IsValidWritePtr(ptmid) THEN
      IF (@ptmid.fType AND %MFT_MENUBREAK) = %MFT_MENUBREAK THEN
        FUNCTION = %FALSE
        EXIT FUNCTION
        ELSEIF (@ptmid.fType AND %MFT_MENUBARBREAK) = %MFT_MENUBARBREAK THEN
          FUNCTION = %FALSE
          EXIT FUNCTION
      END IF
    END IF
    DECR lItemIdx
  LOOP

  FUNCTION = %TRUE

END FUNCTION

'----------------------------------------------------------------------
'
' FUNCTION: CoolMenu_AlignLeft
' PURPOSE:
' RETURNS:
'
'----------------------------------------------------------------------

FUNCTION CoolMenu_AlignLeft _
  ( _
  BYVAL lptmis    AS DWORD, _
  BYVAL hFont     AS DWORD, _
  BYVAL hFontBold AS DWORD, _
  BYVAL cyMenu    AS LONG, _
  BYVAL cxAveChar AS LONG, _
        cxItem    AS LONG, _
        cyItem    AS LONG _
  ) AS LONG

  REGISTER  lItemIdx    AS LONG
  LOCAL     szLabel     AS ASCIIZ * %MAX_PATH
  LOCAL     szAccel     AS ASCIIZ * %MAX_PATH
  LOCAL     tmii        AS MENUITEMINFO
  LOCAL     trc         AS RECT
  LOCAL     ptmid       AS MENUITEMDATA PTR
  LOCAL     ptmidPop    AS MENUITEMDATA PTR
  LOCAL     ptmis       AS MEASUREITEMSTRUCT PTR
  LOCAL     hDC         AS DWORD
  LOCAL     hFontOld    AS DWORD
  LOCAL     hMenu       AS DWORD
  LOCAL     lCount      AS LONG
  LOCAL     lRefIdx     AS LONG
  LOCAL     lTabPos     AS LONG
  LOCAL     lHasAccel   AS LONG
  LOCAL     cxLabel     AS LONG
  LOCAL     cxTab       AS LONG
  LOCAL     cxAccel     AS LONG

  ptmis = lptmis

  ' Menu item data for the current item
  ptmid = @ptmis.itemData
  ' Menu item data for popup title
  ptmidPop = @ptmid.lpPopup

  hDC = GetDC(%NULL)
  ' Save the handle of the menu the reference item is in
  hMenu = @ptmid.hMenu

  ' Get the label width for the reference item
  GOSUB mglwCalc
  ' Save the height of the reference item
  cyItem = MAX(trc.nBottom, cyMenu)

  IF ISTRUE IsWin95WinNT() THEN
    tmii.cbSize = %MENUITEMINFO_WIN95_SIZE
  ELSE
    tmii.cbSize = SIZEOF(tmii)
  END IF
  tmii.fMask  = %MIIM_ID
  lCount = GetMenuItemCount(hMenu)
  ' Find the index of the reference item in the menu
  lItemIdx  = 0

  DO
    IF lItemIdx >= lCount THEN EXIT DO
    GetMenuItemInfo hMenu, lItemIdx, %TRUE, BYVAL VARPTR(tmii)
    IF tmii.wID = @ptmis.itemID THEN
      lRefIdx = lItemIdx
      EXIT DO
    END IF
    INCR lItemIdx
  LOOP

  ' Find the length of labels for items in the same
  ' column as the reference item but below it
  tmii.fMask = %MIIM_DATA
  lItemIdx = lRefIdx

  DO
    IF lItemIdx < 0 THEN EXIT DO
    GetMenuItemInfo hMenu, lItemIdx, %TRUE, BYVAL VARPTR(tmii)
    ptmid = tmii.dwItemData
    IF ISTRUE CoolMenu_IsValidWritePtr(ptmid) THEN
      IF (@ptmid.fType AND %MFT_MENUBREAK) = %MFT_MENUBREAK THEN
        EXIT DO
        ELSEIF (@ptmid.fType AND %MFT_MENUBARBREAK) = %MFT_MENUBARBREAK THEN
          EXIT DO
      END IF
      GOSUB mglwCalc
    END IF
    DECR lItemIdx
  LOOP

  ' Find the length of labels for items in the same
  ' column as the reference item but above it
  lItemIdx = lRefIdx + 1

  DO
    IF lItemIdx >= lCount THEN EXIT DO
    GetMenuItemInfo hMenu, lItemIdx, %TRUE, BYVAL VARPTR(tmii)
    ptmid = tmii.dwItemData
    IF ISTRUE CoolMenu_IsValidWritePtr(ptmid) THEN
      IF (@ptmid.fType AND %MFT_MENUBREAK) = %MFT_MENUBREAK THEN
        EXIT DO
        ELSEIF (@ptmid.fType AND %MFT_MENUBARBREAK) = %MFT_MENUBARBREAK THEN
          EXIT DO
      END IF
      GOSUB mglwCalc
    END IF
    INCR lItemIdx
  LOOP

  ' If accelerators are present set the width of a tab
  IF ISTRUE lHasAccel THEN cxTab = cxAveChar

  cxItem = cxLabel + cxTab + cxAccel
  ReleaseDC %NULL, hDC

  EXIT FUNCTION

mglwCalc:
  lTabPos = INSTR(@ptmid.szText, CHR$(&H09))
  IF ISTRUE lTabPos THEN
    szLabel = MID$(@ptmid.szText, 1, lTabPos - 1)
    szAccel = MID$(@ptmid.szText, lTabPos + 1)
  ELSE
    szLabel = @ptmid.szText
  END IF

  ' Label
  trc.nLeft   = 0
  trc.nTop    = 0
  trc.nRight  = 0
  trc.nBottom = 0

  IF (@ptmid.fState AND %MFS_DEFAULT) = %MFS_DEFAULT THEN
    hFontOld = SelectObject(hDC, hFontBold)
  ELSE
    hFontOld = SelectObject(hDC, hFont)
  END IF

  DrawTextEx hDC, BYVAL VARPTR(szLabel), LEN(szLabel), trc, _
             %DT_CALCRECT OR %DT_SINGLELINE OR %DT_LEFT, BYVAL %NULL

  SelectObject hDC, hFontOld

  cxLabel = MAX(cxLabel, trc.nRight)

  ' Accelerator
  IF lTabPos >= 1 THEN
    lHasAccel   = %TRUE
    trc.nLeft   = 0
    trc.nTop    = 0
    trc.nRight  = 0
    trc.nBottom = 0

    hFontOld = SelectObject(hDC, hFont)

    DrawTextEx hDC, BYVAL VARPTR(szAccel), LEN(szAccel), trc, _
               %DT_CALCRECT OR %DT_SINGLELINE OR %DT_LEFT, BYVAL %NULL

    SelectObject hDC, hFontOld

    cxAccel = MAX(cxAccel, trc.nRight)
    @ptmidPop.cxAccelMax = cxAccel
  END IF
  RETURN

END FUNCTION

'----------------------------------------------------------------------
'
' FUNCTION: CoolMenu_AlignRight
' PURPOSE:
' RETURNS:
'
'----------------------------------------------------------------------

FUNCTION CoolMenu_AlignRight _
  ( _
  BYVAL lptmis    AS DWORD, _
  BYVAL hFont     AS DWORD, _
  BYVAL hFontBold AS DWORD, _
  BYVAL cyMenu    AS LONG, _
  BYVAL cxAveChar AS LONG, _
        cxItem    AS LONG, _
        cyItem    AS LONG _
  ) AS LONG

  LOCAL     szLabel     AS ASCIIZ * %MAX_PATH
  LOCAL     szAccel     AS ASCIIZ * %MAX_PATH
  LOCAL     trc         AS RECT
  LOCAL     ptmid       AS MENUITEMDATA PTR
  LOCAL     ptmis       AS MEASUREITEMSTRUCT PTR
  LOCAL     hDC         AS DWORD
  LOCAL     hFontOld    AS DWORD
  LOCAL     cxTab       AS LONG
  LOCAL     lTabPos     AS LONG

  ptmis = lptmis

  ' Menu item data for the current item
  ptmid = @ptmis.itemData

  lTabPos = INSTR(@ptmid.szText, CHR$(&H09))
  IF ISTRUE lTabPos THEN
    cxTab   = cxAveChar
    szLabel = MID$(@ptmid.szText, 1, lTabPos - 1)
    szAccel = MID$(@ptmid.szText, lTabPos + 1)
    szLabel = szLabel + szAccel
  ELSE
    szLabel = @ptmid.szText
  END IF

  ' Label + accelerator
  trc.nLeft   = 0
  trc.nTop    = 0
  trc.nRight  = 0
  trc.nBottom = 0

  hDC = GetDC(%NULL)

  IF (@ptmid.fState AND %MFS_DEFAULT) = %MFS_DEFAULT THEN
    hFontOld = SelectObject(hDC, hFontBold)
  ELSE
    hFontOld = SelectObject(hDC, hFont)
  END IF

  DrawTextEx hDC, BYVAL VARPTR(szLabel), LEN(szLabel), trc, _
             %DT_CALCRECT OR %DT_SINGLELINE OR %DT_LEFT, BYVAL %NULL

  SelectObject hDC, hFontOld
  ReleaseDC %NULL, hDC

  cxItem = trc.nRight + cxTab
  cyItem = MAX(trc.nBottom, cyMenu)

END FUNCTION

'----------------------------------------------------------------------
'
' FUNCTION: CoolMenu_OnMeasureItem
' PURPOSE:
' RETURNS:
'
'----------------------------------------------------------------------

FUNCTION CoolMenu_OnMeasureItem _
  ( _
  BYVAL lptmis  AS DWORD _
  ) AS LONG

  LOCAL     ptmid       AS MENUITEMDATA PTR
  LOCAL     ptmidPop    AS MENUITEMDATA PTR
  LOCAL     ptmis       AS MEASUREITEMSTRUCT PTR
  LOCAL     hFont       AS DWORD
  LOCAL     hFontBold   AS DWORD
  LOCAL     cyMenu      AS LONG
  LOCAL     cxItem      AS LONG
  LOCAL     cyItem      AS LONG
  LOCAL     cxGap       AS LONG
  LOCAL     cxBtnMargin AS LONG
  LOCAL     cyBtnMargin AS LONG
  LOCAL     cxTxtMargin AS LONG
  LOCAL     cxImage     AS LONG
  LOCAL     cyImage     AS LONG
  LOCAL     cxImageBtn  AS LONG
  LOCAL     cyImageBtn  AS LONG
  LOCAL     cxButton    AS LONG
  LOCAL     cyButton    AS LONG
  LOCAL     cxFudge     AS LONG
  LOCAL     lFactor     AS LONG
  LOCAL     cxAveChar   AS LONG
  LOCAL     cxBmp       AS LONG
  LOCAL     cxGapBmp    AS LONG

  ptmis = lptmis

  ' Menu item data for the current item
  ptmid = @ptmis.itemData
  IF ISTRUE CoolMenu_IsValidWritePtr(ptmid) THEN
    ' Menu item data for popup title
    ptmidPop = @ptmid.lpPopup
    CoolMenu_GetMetrics hFont, hFontBold, cyMenu, cxAveChar
    IF (@ptmid.fType AND %MFT_SEPARATOR) = %MFT_SEPARATOR THEN
      ' Use half system height and zero width
      @ptmis.itemHeight = cyMenu \ 2
      @ptmis.itemWidth  = 0
    ELSE
      IF ISTRUE @ptmid.fAlignRight THEN
        CoolMenu_AlignRight BYVAL ptmis, hFont, hFontBold, cyMenu, cxAveChar, cxItem, cyItem
      ELSE
        CoolMenu_AlignLeft BYVAL ptmis, hFont, hFontBold, cyMenu, cxAveChar, cxItem, cyItem
      END IF

      ' Spacing metrics
      lFactor = GetSystemMetrics(%SM_CXBORDER)
      cxGap       = %CXGAP * lFactor
      cxBtnMargin = %CXBUTTONMARGIN * lFactor
      cyBtnMargin = %CYBUTTONMARGIN * lFactor
      cxTxtMargin = %CXTEXTMARGIN * lFactor

      ' Get dimensions of images
      ' Testing for the presence of a bitmap on each item
      ' gives us menu items that vary in height
      IF @ptmid.iItem >= 0 THEN
        IF ISTRUE @ptmid.hImlItem THEN
          ImageList_GetIconSize @ptmid.hImlItem, cxImage, cyImage
        END IF
      END IF
      IF ISTRUE @ptmid.hImlButton THEN
        ImageList_GetIconSize @ptmid.hImlButton, cxImageBtn, cyImageBtn
      END IF
      IF (cxImageBtn = 0) OR (cyImageBtn = 0) THEN
        cxImageBtn = GetSystemMetrics(%SM_CXMENUCHECK)
        cyImageBtn = GetSystemMetrics(%SM_CYMENUCHECK)
      END IF

      ' Button size
      cxButton    = cxBtnMargin + cxImageBtn + cxBtnMargin
      cyButton    = cyBtnMargin + cyImageBtn + cyBtnMargin
      ' Fudge factor
      cxFudge     = GetSystemMetrics(%SM_CXMENUCHECK) + 1
      ' Left-margin bitmap
      IF ISTRUE CoolMenu_IsInFirstCol(@ptmid.hMenu, @ptmis.itemID) THEN
        IF ISTRUE CoolMenu_IsValidWritePtr(ptmidPop) THEN
          cxBmp    = @ptmidPop.cxBmp
          cxGapBmp = @ptmidPop.cxGapBmp
        END IF
      END IF

      ' Height of item is the maximum of height of bitmaps and text
      @ptmis.itemHeight = MAX(cyItem, cyImage, cyButton)
      ' Width of item
      @ptmis.itemWidth = cxBmp + cxGapBmp + cxButton + cxGap + cxTxtMargin + cxItem + cxTxtMargin + cxButton
      ' Whatever value is returned Windows will add the width
      ' of a check bitmap to it.  Subtract this value to correct.
      @ptmis.itemWidth = @ptmis.itemWidth - cxFudge
    END IF
    DeleteObject hFont
    DeleteObject hFontBold
    FUNCTION = %TRUE
    EXIT FUNCTION
  END IF

  FUNCTION = %FALSE

END FUNCTION

'----------------------------------------------------------------------
'
' FUNCTION: CoolMenu_DrawCheckMark
' PURPOSE:
' RETURNS:
'
'----------------------------------------------------------------------

FUNCTION CoolMenu_DrawCheckMark _
  ( _
  BYVAL hMenu     AS DWORD, _
  BYVAL wItemId   AS WORD, _
  BYVAL lSelected AS LONG, _
  BYVAL lDisabled AS LONG, _
  BYVAL lChecked  AS LONG, _
  BYVAL fFlat     AS LONG, _
  BYVAL hDC       AS DWORD, _
        trc       AS RECT _
  ) AS LONG

  LOCAL szItem      AS ASCIIZ * %MAX_PATH
  LOCAL tmii        AS MENUITEMINFO
  LOCAL tbm         AS BITMAP
  LOCAL trcChk      AS RECT
  LOCAL hDCMem      AS DWORD
  LOCAL hBmp        AS DWORD
  LOCAL hBmpOld     AS DWORD
  LOCAL cxBmp       AS LONG
  LOCAL cyBmp       AS LONG
  LOCAL x           AS LONG
  LOCAL y           AS LONG
  LOCAL lRadioItem  AS LONG

  IF ISTRUE hMenu THEN
    ' If custom checked bitmaps are present use them
    ' otherwise use the Windows defaults
    IF ISTRUE IsWin95WinNT() THEN
      tmii.cbSize     = %MENUITEMINFO_WIN95_SIZE
      tmii.fMask      = %MIIM_TYPE OR %MIIM_CHECKMARKS
      tmii.cch        = %MAX_PATH
      tmii.dwTypeData = VARPTR(szItem)
    ELSE
      tmii.cbSize     = SIZEOF(tmii)
      tmii.fMask      = %MIIM_FTYPE OR %MIIM_CHECKMARKS
    END IF
    GetMenuItemInfo hMenu, wItemId, %FALSE, BYVAL VARPTR(tmii)

    IF lChecked THEN
      hBmp = tmii.hbmpChecked
    ELSE
      hBmp = tmii.hbmpUnchecked
    END IF
    IF ISFALSE hBmp THEN
      IF (tmii.fType AND %MFT_RADIOCHECK) = %MFT_RADIOCHECK THEN lRadioItem = %TRUE
    END IF

    IF GetObjectType(hBmp) = %OBJ_BITMAP THEN
      GetObject hBmp, SIZEOF(tbm), BYVAL VARPTR(tbm)
      cxBmp = tbm.bmWidth
      cyBmp = tbm.bmHeight
      x = (trc.nLeft + trc.nRight - cxBmp) \ 2
      y = (trc.nTop + trc.nBottom - cyBmp) \ 2
      phnxDrawBitmap hDC, x, y, hBmp, cxBmp, cyBmp, %TRUE, &HFFFFFFFF???
    ELSE
      hDCMem  = CreateCompatibleDC(hDC)
      cxBmp   = GetSystemMetrics(%SM_CXMENUCHECK)
      cyBmp   = GetSystemMetrics(%SM_CYMENUCHECK)
      hBmp    = CreateCompatibleBitmap(hDC, cxBmp, cyBmp)
      hBmpOld = SelectObject(hDCMem, hBmp)
      trcChk.nLeft   = 0
      trcChk.nTop    = 0
      trcChk.nRight  = cxBmp
      trcChk.nBottom = cyBmp
      PatBlt hDCMem, 0, 0, cxBmp, cyBmp, %WHITENESS
      IF ISTRUE lRadioItem THEN
        DrawFrameControl hDCMem, trcChk, %DFC_MENU, %DFCS_MENUBULLET
      ELSE
        DrawFrameControl hDCMem, trcChk, %DFC_MENU, %DFCS_MENUCHECK
      END IF
      x = (trc.nLeft + trc.nRight - cxBmp) \ 2
      y = (trc.nTop + trc.nBottom - cyBmp) \ 2
      BitBlt hDC, x, y, cxBmp, cyBmp, hDCMem, 0, 0, %SRCAND
      DeleteObject SelectObject(hDCMem, hBmpOld)
      DeleteDC hDCMem
    END IF

    IF ISTRUE lDisabled THEN
      IF ISTRUE lSelected THEN
        CoolMenu_DisableRect hDC, trc, GetSysColor(%COLOR_HIGHLIGHT), %FALSE, %FALSE
      ELSE
        CoolMenu_DisableRect hDC, trc, GetSysColor(%COLOR_MENU), %FALSE, %TRUE
      END IF
      ELSEIF ISTRUE lSelected THEN
        IF ISTRUE fFlat THEN
          CoolMenu_DisableRect hDC, trc, GetSysColor(%COLOR_HIGHLIGHT), %TRUE, %FALSE
        ELSE
          CoolMenu_DisableRect hDC, trc, GetSysColor(%COLOR_MENU), %TRUE, %FALSE
        END IF
    END IF
  END IF

END FUNCTION

'----------------------------------------------------------------------
'
' FUNCTION: CoolMenu_DrawText
' PURPOSE:
' RETURNS:
'
'----------------------------------------------------------------------

FUNCTION CoolMenu_DrawText _
  ( _
  BYVAL hDC           AS DWORD, _
        trcText       AS RECT, _
        szText        AS ASCIIZ, _
  BYVAL dwTxtClr      AS DWORD, _
  BYVAL cxAccelMax    AS LONG, _
  BYVAL fAlignRight   AS LONG _
  ) AS LONG

  LOCAL szItem      AS ASCIIZ * %MAX_PATH
  LOCAL szAccel     AS ASCIIZ * %MAX_PATH
  LOCAL trc         AS RECT
  LOCAL dwTxtClrOld AS DWORD
  LOCAL dwBkModeOld AS DWORD
  LOCAL lTabPos     AS LONG

  lTabPos = INSTR(szText, CHR$(&H09))
  IF ISTRUE lTabPos then
    szItem  = MID$(szText, 1, lTabPos - 1)
    szAccel = MID$(szText, lTabPos + 1)
  ELSE
    szItem  = szText
    szAccel = ""
  END IF

  dwTxtClrOld = SetTextColor(hDC, dwTxtClr)
  dwBkModeOld = SetBkMode(hDC, %TRANSPARENT)

  ' Left justified item text
  DrawTextEx hDC, BYVAL VARPTR(szItem), LEN(szItem), trcText, _
             %DT_SINGLELINE OR %DT_LEFT OR %DT_VCENTER, BYVAL %NULL
  ' Right aligned accelerator
  IF ISTRUE lTabPos THEN
    IF ISTRUE fAlignRight THEN
      DrawTextEx hDC, BYVAL VARPTR(szAccel), LEN(szAccel), trcText, _
                 %DT_SINGLELINE OR %DT_RIGHT OR %DT_VCENTER, BYVAL %NULL
    ELSE
      trc = trcText
      trc.nLeft = trc.nRight - cxAccelMax
      DrawTextEx hDC, BYVAL VARPTR(szAccel), LEN(szAccel), trc, _
                 %DT_SINGLELINE OR %DT_LEFT OR %DT_VCENTER OR %DT_NOCLIP, BYVAL %NULL
    END IF
  END IF

  SetTextColor hDC, dwTxtClrOld
  SetBkMode hDC, dwBkModeOld

END FUNCTION

'----------------------------------------------------------------------
'
' FUNCTION: CoolMenu_OnDrawItem
' PURPOSE:
' RETURNS:
'
'----------------------------------------------------------------------

FUNCTION CoolMenu_OnDrawItem _
  ( _
  BYVAL lptdis  AS DWORD _
  ) AS LONG

  LOCAL   trc         AS RECT
  LOCAL   trcItem     AS RECT
  LOCAL   tbm         AS BITMAP
  LOCAL   tmii        AS MENUITEMINFO
  LOCAL   ptmid       AS MENUITEMDATA PTR
  LOCAL   ptmidPop    AS MENUITEMDATA PTR
  LOCAL   ptdis       AS DRAWITEMSTRUCT PTR
  LOCAL   dwTxtClr    AS DWORD
  LOCAL   hBmp        AS DWORD
  LOCAL   cxGap       AS LONG
  LOCAL   cxBtnMargin AS LONG
  LOCAL   cyBtnMargin AS LONG
  LOCAL   cxTxtMargin AS LONG
  LOCAL   cxImage     AS LONG
  LOCAL   cyImage     AS LONG
  LOCAL   cxImageBtn  AS LONG
  LOCAL   cyImageBtn  AS LONG
  LOCAL   cxButton    AS LONG
  LOCAL   cyButton    AS LONG
  LOCAL   cxFudge     AS LONG
  LOCAL   cxBmp       AS LONG
  LOCAL   cxGapBmp    AS LONG
  LOCAL   lFactor     AS LONG
  LOCAL   x           AS LONG
  LOCAL   y           AS LONG
  LOCAL   lDisabled   AS LONG
  LOCAL   lSelected   AS LONG
  LOCAL   lChecked    AS LONG
  LOCAL   lCheckBmp   AS LONG

  ptdis = lptdis

  ' Menu item data for current item
  ptmid = @ptdis.itemData
  IF ISTRUE CoolMenu_IsValidWritePtr(ptmid) THEN
    ' Menu item data for popup title
    ptmidPop = @ptmid.lpPopup
    IF ISTRUE CoolMenu_IsValidWritePtr(ptmidPop) THEN
      ' Left-margin bitmap code
      IF @ptdis.rcItem.nLeft = 0 THEN
        IF ISTRUE @ptmidPop.wBmpId THEN
          hBmp = LoadBitmap(@ptmidPop.hInstance, BYVAL @ptmidPop.wBmpId)
          IF GetObjectType(hBmp) = %OBJ_BITMAP THEN
            GetObject hBmp, SIZEOF(tbm), BYVAL VARPTR(tbm)
            GetClipBox @ptdis.hDC, trc
            phnxDrawBitmap @ptdis.hDC, 0, trc.nBottom - tbm.bmHeight, hBmp, tbm.bmWidth, tbm.bmHeight, %FALSE, 0
            DeleteObject hBmp
          END IF
        END IF
      END IF

      IF @ptdis.rcItem.nLeft = 0 THEN
        cxBmp    = @ptmidPop.cxBmp
        cxGapBmp = @ptmidPop.cxGapBmp
      END IF

       IF (@ptmid.fType AND %MFT_SEPARATOR) = %MFT_SEPARATOR THEN
        ' Copy rectangle and vertically center separator
        trc = @ptdis.rcItem
        ' No gap between left-margin bitmap and separator
        trc.nLeft = trc.nLeft + cxBmp
        trc.nTop  = (trc.nTop + trc.nBottom) \ 2
        DrawEdge @ptdis.hDC, trc, %EDGE_ETCHED, %BF_TOP
      ELSE
        ' Spacing metrics
        lFactor     = GetSystemMetrics(%SM_CXBORDER)
        cxGap       = %CXGAP * lFactor
        cxBtnMargin = %CXBUTTONMARGIN * lFactor
        cyBtnMargin = %CYBUTTONMARGIN * lFactor
        cxTxtMargin = %CXTEXTMARGIN * lFactor

        ' Get dimensions of images
        ' Testing for the presence of a bitmap on each item
        ' gives us menu items that vary in height
        IF @ptmid.iItem >= 0 THEN
          IF ISTRUE @ptmid.hImlItem THEN
            ImageList_GetIconSize @ptmid.hImlItem, cxImage, cyImage
          END IF
        END IF
        IF ISTRUE @ptmid.hImlButton THEN
          ImageList_GetIconSize @ptmid.hImlButton, cxImageBtn, cyImageBtn
        END IF
        IF (cxImageBtn = 0) OR (cyImageBtn = 0) THEN
          cxImageBtn = GetSystemMetrics(%SM_CXMENUCHECK)
          cyImageBtn = GetSystemMetrics(%SM_CYMENUCHECK)
        END IF

        ' Button size
        cxButton    = cxBtnMargin + cxImageBtn + cxBtnMargin
        cyButton    = cyBtnMargin + cyImageBtn + cyBtnMargin
        ' Fudge factor
        cxFudge     = GetSystemMetrics(%SM_CXMENUCHECK) + 1

        lDisabled = (@ptdis.itemState AND %ODS_GRAYED)
        lSelected = (@ptdis.itemState AND %ODS_SELECTED)
        lChecked  = (@ptdis.itemState AND %ODS_CHECKED)
        ' Check for the presence of an unchecked bitmap
        IF ISTRUE IsWin95WinNT() THEN
          tmii.cbSize     = %MENUITEMINFO_WIN95_SIZE
        ELSE
          tmii.cbSize     = SIZEOF(tmii)
        END IF
        tmii.fMask      = %MIIM_CHECKMARKS
        GetMenuItemInfo @ptdis.hwndItem, @ptdis.itemID, %FALSE, BYVAL VARPTR(tmii)
        lCheckBmp = (ISTRUE lChecked) OR (ISTRUE tmii.hbmpUnchecked)

        trcItem = @ptdis.rcItem
        trcItem.nLeft = trcItem.nLeft + cxBmp
        ' Color the background
        trc = @ptdis.rcItem
        trc.nLeft = trc.nLeft + cxBmp

        FillRect @ptdis.hDC, trc, %COLOR_MENU + 1
        IF ISTRUE lSelected THEN
          IF (@ptmid.iButton >= 0) OR (ISTRUE lCheckBmp) THEN
            IF ISFALSE lDisabled THEN
              IF ISFALSE @ptmid.fFlat THEN
                trc.nLeft = trc.nLeft + cxGapBmp + cxButton + cxGap
              END IF
            END IF
          END IF
          FillRect @ptdis.hDC, trc, %COLOR_HIGHLIGHT + 1
          IF ISTRUE lDisabled THEN
            dwTxtClr = GetSysColor(%COLOR_GRAYTEXT)
            IF dwTxtClr = GetSysColor(%COLOR_HIGHLIGHT) THEN
              dwTxtClr = GetSysColor(%COLOR_MENUTEXT)
            END IF
          ELSE
            dwTxtClr = GetSysColor(%COLOR_HIGHLIGHTTEXT)
          END IF
        ELSE
          dwTxtClr = GetSysColor(%COLOR_MENUTEXT)
        END IF

        ' Draw button
        ' Calculate bounding rectangle of button
        IF (@ptmid.iButton >= 0) OR (ISTRUE lCheckBmp) THEN
          trc.nLeft   = @ptdis.rcItem.nLeft + cxBmp + cxGapBmp
          trc.nRight  = trc.nLeft + cxButton
          trc.nTop    = (@ptdis.rcItem.nTop + @ptdis.rcItem.nBottom - cyButton) \ 2
          trc.nBottom = trc.nTop + cyButton
          IF @ptmid.iButton >= 0 THEN
            x = trc.nLeft + cxBtnMargin
            y = (trc.nTop + trc.nBottom - cyImageBtn) \ 2
            ImageList_Draw @ptmid.hImlButton, @ptmid.iButton, @ptdis.hDC, x, y, %ILD_TRANSPARENT
            IF ISTRUE lDisabled THEN
              IF ISTRUE lSelected THEN
                CoolMenu_DisableRect @ptdis.hDC, trc, GetSysColor(%COLOR_HIGHLIGHT), %FALSE, %FALSE
              ELSE
                CoolMenu_DisableRect @ptdis.hDC, trc, GetSysColor(%COLOR_MENU), %FALSE, %TRUE
              END IF
            END IF
          ELSE
            CoolMenu_DrawCheckMark @ptmid.hMenu, @ptdis.itemID, lSelected, lDisabled, lChecked, @ptmid.fFlat, @ptdis.hDC, trc
          END IF
          IF ISFALSE @ptmid.fFlat THEN
            IF ISFALSE lDisabled THEN
              IF ISTRUE lSelected THEN
                DrawEdge @ptdis.hDC, trc, %BDR_RAISEDINNER, %BF_RECT
                ELSEIF ISTRUE lChecked THEN
                  DrawEdge @ptdis.hDC, trc, %BDR_SUNKENOUTER, %BF_RECT
              END IF
            END IF
          END IF
        END IF

        ' Paint the item bitmap and text.  No need to select font,
        ' because windows sets it up before sending WM_DRAWITEM
        trcItem = @ptdis.rcItem
        trcItem.nLeft   = trcItem.nLeft + cxBmp + cxGapBmp + cxButton + cxGap + cxTxtMargin
        trcItem.nRight  = trcItem.nRight - cxButton
        ' Draw the item bitmap
        IF @ptmid.iItem >= 0 THEN
          x = trcItem.nLeft
          y = (trcItem.nTop + trcItem.nBottom - cyImage) \ 2
          ImageList_Draw @ptmid.hImlItem, @ptmid.iItem, @ptdis.hDC, x, y, %ILD_TRANSPARENT
        END IF
        CoolMenu_DrawText @ptdis.hDC, trcItem, @ptmid.szText, dwTxtClr, @ptmidPop.cxAccelMax, @ptmid.fAlignRight
        IF ISTRUE lDisabled THEN
          ' Adjust the right side to avoid clipping
          trcItem.nRight = @ptdis.rcItem.nRight
          IF ISFALSE lSelected THEN
            CoolMenu_DisableRect @ptdis.hDC, trcItem, GetSysColor(%COLOR_MENU), %FALSE, %TRUE
          ELSE
            CoolMenu_DisableRect @ptdis.hDC, trcItem, GetSysColor(%COLOR_HIGHLIGHT), %FALSE, %FALSE
          END IF
        END IF
      END IF
      FUNCTION = %TRUE
      EXIT FUNCTION
    END IF
  END IF

  FUNCTION = %FALSE

END FUNCTION

'----------------------------------------------------------------------
'
' FUNCTION: CoolMenu_EnableMenuItem
' PURPOSE:  Enables, disables, or grays the specified menu item.
' RETURN:   The Return value specifies the previous state of the menu
'           item (it is either MF_DISABLED, MF_ENABLED, OR MF_GRAYED).
'           IF the menu item does not exist, the return value is -1.
'
'----------------------------------------------------------------------

FUNCTION CoolMenu_EnableMenuItem _
  ( _
  BYVAL hMenu         AS DWORD, _ ' handle to the menu
  BYVAL uIDEnableItem AS DWORD, _ ' specifies the menu item to be enabled, disabled, or grayed
  BYVAL uEnable       AS DWORD _  ' controls the interpretation of the uIDEnableItem parameter and indicates the state of the item
  ) AS LONG

  LOCAL tmii          AS MENUITEMINFO
  LOCAL ptmid         AS MENUITEMDATA PTR
  LOCAL fIsWin95WinNT AS LONG
  LOCAL fByPosition   AS LONG
  LOCAL lRetVal       AS LONG

  lRetVal = EnableMenuItem(hMenu, uIDEnableItem, uEnable)

  IF hMenu THEN
    fIsWin95WinNT = IsWin95WinNT()
    fByPosition = ((uEnable AND %MF_BYPOSITION) = %MF_BYPOSITION)
    IF IsWin95WinNT() THEN
      tmii.cbSize     = %MENUITEMINFO_WIN95_SIZE
    ELSE
      tmii.cbSize     = SIZEOF(tmii)
    END IF
    tmii.fMask      = %MIIM_DATA OR %MIIM_STATE
    GetMenuItemInfo hMenu, uIDEnableItem, fByPosition, BYVAL VARPTR(tmii)
    ptmid = tmii.dwItemData
    IF CoolMenu_IsValidWritePtr(ptmid) THEN
      @ptmid.fState = tmii.fState
    END IF
  END IF

  FUNCTION = lRetVal

END FUNCTION

'###############################################################################
' END CoolMenu
'###############################################################################

'----------------------------------------------------------------------
'
' PROCEDURE: phnxLoadRichEdit
' PURPOSE:   Loads the rich edit dynamic link library (DLL).
' RETURNS:   The handle of the DLL or NULL if the DLL does not exist.
'
'----------------------------------------------------------------------

FUNCTION phnxLoadRichEdit _
  ( _
  szLibName AS ASCIIZ _ ' Name of DLL or empty string to load latest version
  ) AS DWORD

  LOCAL hLibRichEd  AS DWORD

  ' First try the specified name
  IF LEN(szLibName) THEN hLibRichEd = LoadLibrary(szLibName)

  IF ISFALSE hLibRichEd THEN
    ' RichEdit 4.1 (Windows XP/SP1)
    hLibRichEd = LoadLibrary("MSFTEDIT.DLL")
    IF ISFALSE hLibRichEd THEN
      ' Try RichEdit 2.0 or 3.0
      hLibRichEd = LoadLibrary("RICHED20.DLL")
      IF ISFALSE hLibRichEd THEN
        ' Try RichEdit 1.0
        hLibRichEd = LoadLibrary("RICHED32.DLL")
      END IF
    END IF
  END IF

  FUNCTION = hLibRichEd

END FUNCTION

'----------------------------------------------------------------------
'
' PROCEDURE: phnxGetRichEditClass
' PURPOSE:   Retrieves the class name of the latest version of the
'            rich edit control that is installed.
'
'----------------------------------------------------------------------

FUNCTION phnxGetRichEditClass() AS STRING

  LOCAL szClassName AS ASCIIZ * %MAX_PATH
  LOCAL hLibRichEd  AS DWORD

  ' RichEdit 4.1 (Windows XP/SP1)
  hLibRichEd = LoadLibrary("MSFTEDIT.DLL")
  IF ISTRUE hLibRichEd THEN
    szClassName = "RichEdit50W"
  ' Try RichEdit 2.0 or 3.0
  ELSE
    hLibRichEd = LoadLibrary("RICHED20.DLL")
    IF ISTRUE hLibRichEd THEN
      szClassName = "RichEdit20A"
    ' Try RichEdit 1.0
    ELSE
      hLibRichEd = LoadLibrary("RICHED32.DLL")
      IF ISTRUE hLibRichEd THEN
        szClassName = "RichEdit"
      ' Use edit control
      ELSE
        szClassName = "Edit"
      END IF
    END IF
  END IF

  IF ISTRUE hLibRichEd THEN FreeLibrary hLibRichEd

  FUNCTION = szClassName

END FUNCTION

'###############################################################################
' BEGIN Splitterbar_Class32
'###############################################################################

' Icon/cursor file header format
' ------------------------------
' The icon file header is immediately followed by .idCount of ICONDIRENTRY structures
TYPE ICONDIR          ' id
  idReserved    AS WORD           ' Reserved (must be 0)
  idType        AS WORD           ' Resource Type (1 for icons)
  idCount       AS WORD           ' How many images?
END TYPE

TYPE ICONDIRENTRY     ' ide
  bWidth        AS BYTE           ' Width, in pixels, of the image
  bHeight       AS BYTE           ' Height, in pixels, of the image
  bColorCount   AS BYTE           ' Number of colors in image (0 if >=8bpp)
  bReserved     AS BYTE           ' Reserved ( must be 0)
  wPlanes       AS WORD           ' Color Planes
  wBitCount     AS WORD           ' Bits per pixel
  dwBytesInRes  AS DWORD          ' How many bytes in this resource?
  dwImageOffset AS DWORD          ' Where in the file is this image?
END TYPE

' Splitterbar control styles
%SBSTYLE_VERTICAL       = &H01??  ' creates a vertical Splitterbar
%SBSTYLE_HORIZONTAL     = &H02??  ' creates a horizontal Splitterbar
%SBSTYLE_RAISED         = &H10??  ' creates a Splitterbar with raised edges
%SBSTYLE_NOHOVERCURSOR  = &H20??  ' the splitterbar uses only one cursor instead of two. The default is a hover cursor and a drag cursor

' Splitterbar control messages
%SBARM_SETBKCOLOR     = %WM_USER + 1
' Purpose: sets the background color of a Splitterbar control.
' wParam:  N/A
' lParam:  new background color or -1 for no color.
' Return:  value of previous background color or %COLOR_BTNFACE for default.

%SBARM_GETBKCOLOR     = %WM_USER + 2
' Purpose: gets the background color of a Splitterbar control.
' wParam:  N/A
' lParam:  N/A
' Return:  value of background color or -1 for no color.

%SBARM_SETCURSOR      = %WM_USER + 3
' Purpose: sets the mouse pointer used by a Splitterbar control.
' wParam:  N/A
' lParam:  handle of new cursor.
' Return:  handle of previous cursor.

%SBARM_GETCURSOR      = %WM_USER + 4
' Purpose: gets the mouse pointer used by a Splitterbar control.
' wParam:  N/A
' lParam:  N/A
' Return:  handle of cursor used by control.

%SBARM_SETOFFSETS     = %WM_USER + 5
' Purpose: sets the width(height) of the margin beyond which a splitterbar can be dragged.
' wParam:  N/A
' lParam:  LOWRD = left margin(vertical splitter).  Top margin(horizontal splitterbar).
'          HIWRD = right margin(vertical splitter).  Bottom margin(horizontal splitterbar).
' Return:  previous margins or the defaults(2 pixels).

%SBARM_GETOFFSETS     = %WM_USER + 6
' Purpose: gets the width(height) of the margin beyond which a splitterbar can be dragged.
' wParam:  N/A
' lParam:  N/A
' Return:  the left(top) margin in the loword, the right(bottom) margin in the hiword.

' Splitterbar control notifications sent via WM_COMMAND.
%SBARN_POSCHANGED     = %WM_USER + 1
' Purpose: sent when the position of the splitterbar changes.
' wParam:  LOWRD = control identifier.  HIWRD = notification code
' lParam:  handle of control
' Return:  N/A

%SBARN_DBLCLK         = %WM_USER + 2
' Purpose: sent when the splitterbar is double-clicked.
' wParam:  LOWRD = control identifier.  HIWRD = notification code
' lParam:  handle of control
' Return:  N/A

' Splitterbar window information  ' sbi
TYPE SPLITTERBARINFO
  hCursor   AS DWORD    ' handle of cursor
  dwBkColor AS DWORD    ' background color
  wOffset1  AS WORD     ' right(bottom) margin in pixels
  wOffset2  AS WORD     ' left(top) margin in pixels
  fResizing AS LONG     ' INTERNAL USE: TRUE = panel is being resized
  tptOld    AS POINTAPI ' INTERNAL USE: old location of cursor
  trc       AS RECT     ' INTERNAL USE: current bounding rectangle of drag image
  xNew      AS LONG     ' INTERNAL USE: new horizontal position of splitterbar
  yNew      AS LONG     ' INTERNAL USE; new vertical position of splitterbar
  hBr       AS DWORD    ' INTERNAL USE: handle of pattern brush
END TYPE

'-------------------------------------------------------------------------------
'
' PROCEDURE: SplitterbarClass32_DrawDragImage
' PURPOSE:   Processes messages for windows created from the Splitterbar_Class32
'            class.
'
'-------------------------------------------------------------------------------

FUNCTION SplitterbarClass32_DrawDragImage _
  ( _
  BYVAL hWnd    AS DWORD _  ' window handle
  ) AS LONG

  LOCAL trc         AS RECT
  LOCAL ptsbi       AS SPLITTERBARINFO PTR
  LOCAL hWndParent  AS DWORD
  LOCAL hDC         AS DWORD
  LOCAL hBrOld      AS DWORD
  LOCAL lMapModeOld AS LONG

  ptsbi = GetWindowLong(hWnd, 0)

  hWndParent = GetParent(hWnd)
  hDC = GetWindowDC(hWndParent)
  BeginPath hDC
  MoveToEx hDC, @ptsbi.trc.nLeft, @ptsbi.trc.nTop, BYVAL %NULL
  LineTo hDC, @ptsbi.trc.nRight, @ptsbi.trc.nTop
  LineTo hDC, @ptsbi.trc.nRight, @ptsbi.trc.nBottom
  LineTo hDC, @ptsbi.trc.nLeft, @ptsbi.trc.nBottom
  LineTo hDC, @ptsbi.trc.nLeft, @ptsbi.trc.nTop
  EndPath hDC
  lMapModeOld = SetROP2(hDC, %R2_XORPEN)
  hBrOld = SelectObject(hDC, @ptsbi.hBr)
  FillPath hDC
  SelectObject hDC, hBrOld
  SetROP2 hDC, lMapModeOld
  ReleaseDC hWndParent, hDC

END FUNCTION

'-------------------------------------------------------------------------------
'
' PROCEDURE: SplitterbarClass32_WndProc
' PURPOSE:   Processes messages for windows created from the Splitterbar_Class32
'            class.
'
'-------------------------------------------------------------------------------

FUNCTION SplitterbarClass32_WndProc _
  ( _
  BYVAL hWnd    AS DWORD, _ ' window handle
  BYVAL uMsg    AS DWORD, _ ' type of message
  BYVAL wParam  AS DWORD, _ ' additional information
  BYVAL lParam  AS LONG _   ' additional information
  ) AS LONG

  LOCAL   trcWin        AS RECT
  LOCAL   trc           AS RECT
  LOCAL   tsbi          AS SPLITTERBARINFO
  LOCAL   tpt           AS POINTAPI
  LOCAL   tid           AS ICONDIR
  LOCAL   ptid          AS ICONDIR PTR
  LOCAL   ptide         AS ICONDIRENTRY PTR
  LOCAL   ptsbi         AS SPLITTERBARINFO PTR
  LOCAL   lpIconRes     AS DWORD
  LOCAL   hWndParent    AS DWORD
  LOCAL   dwStyle       AS DWORD
  LOCAL   hDCMem        AS DWORD
  LOCAL   hBmp          AS DWORD
  LOCAL   hBmpOld       AS DWORD
  LOCAL   hBrOld        AS DWORD
  LOCAL   hCursor       AS DWORD
  LOCAL   dwBkColor     AS DWORD
  LOCAL   cxDC          AS LONG
  LOCAL   cyDC          AS LONG
  LOCAL   dx            AS LONG
  LOCAL   dy            AS LONG
  LOCAL   lDim          AS LONG
  LOCAL   fDeflate      AS LONG
  LOCAL   lRet          AS LONG
  LOCAL   lOffset1      AS LONG
  LOCAL   lOffset2      AS LONG
  LOCAL   wOffset1      AS WORD
  LOCAL   wOffset2      AS WORD

  SELECT CASE uMsg
    CASE %WM_CREATE
      ptsbi = HeapAlloc(GetProcessHeap(), %HEAP_ZERO_MEMORY, SIZEOF(tsbi))
      IF ISFALSE ptsbi THEN
        FUNCTION = -1
        EXIT FUNCTION
      END IF
      SetWindowLong hWnd, 0, ptsbi
      @ptsbi.hCursor   = %NULL
      @ptsbi.dwBkColor = GetSysColor(%COLOR_BTNFACE)  ' default background color
      @ptsbi.wOffset1  = 2                            ' default margins
      @ptsbi.wOffset2  = 2                            ' default margins

    CASE %WM_NCHITTEST
      FUNCTION = %HTCLIENT
      EXIT FUNCTION

    CASE %SBARM_SETBKCOLOR
      ptsbi = GetWindowLong(hWnd, 0)
      dwBkColor = @ptsbi.dwBkColor
      @ptsbi.dwBkColor = lParam
      FUNCTION = dwBkColor
      EXIT FUNCTION

    CASE %SBARM_GETBKCOLOR
      ptsbi = GetWindowLong(hWnd, 0)
      FUNCTION = @ptsbi.dwBkColor
      EXIT FUNCTION

    CASE %SBARM_SETCURSOR
      ptsbi = GetWindowLong(hWnd, 0)
      hCursor = @ptsbi.hCursor
      @ptsbi.hCursor = lParam
      FUNCTION = hCursor
      EXIT FUNCTION

    CASE %SBARM_GETCURSOR
      ptsbi = GetWindowLong(hWnd, 0)
      FUNCTION = @ptsbi.hCursor
      EXIT FUNCTION

    CASE %SBARM_SETOFFSETS
      ptsbi = GetWindowLong(hWnd, 0)
      wOffset1 = @ptsbi.wOffset1
      wOffset2 = @ptsbi.wOffset2
      @ptsbi.wOffset1 = LOWRD(lParam)
      @ptsbi.wOffset2 = HIWRD(lParam)
      FUNCTION = MAKLNG(wOffset1, wOffset2)
      EXIT FUNCTION

    CASE %SBARM_GETOFFSETS
      ptsbi = GetWindowLong(hWnd, 0)
      FUNCTION = MAKLNG(@ptsbi.wOffset1, @ptsbi.wOffset2)
      EXIT FUNCTION

    CASE %WM_ERASEBKGND
      ptsbi = GetWindowLong(hWnd, 0)
      hWndParent = GetParent(hWnd)
      ' Create memory device context for painting
      GetClientRect hWnd, trc
      cxDC = trc.nRight - trc.nLeft
      cyDC = trc.nBottom - trc.nTop
      hDCMem  = CreateCompatibleDC(wParam)
      hBmpOld = SelectObject(hDCMem, CreateCompatibleBitmap(wParam, cxDC, cyDC))
      dwBkColor = @ptsbi.dwBkColor
      IF dwBkColor <> &HFFFFFFFF??? THEN
        hBrOld = SelectObject(hDCMem, CreateSolidBrush(dwBkColor))
        PatBlt hDCMem, 0, 0, cxDC, cyDC, %PATCOPY
        DeleteObject SelectObject(hDCMem, hBrOld)
      END IF
      IF (GetWindowLong(hWnd, %GWL_STYLE) AND %SBSTYLE_RAISED) = %SBSTYLE_RAISED THEN
        DrawEdge hDCMem, trc, %EDGE_RAISED, %BF_RECT OR %BF_SOFT
      END IF
      ' Blt the finish product to the screen
      BitBlt wParam, 0, 0, cxDC, cyDC, hDCMem, 0, 0, %SRCCOPY
      ' Select orignal objects back into memory DCs
      DeleteObject SelectObject(hDCMem, hBmpOld)
      ' Delete the memory DCs
      DeleteDC hDCMem
      FUNCTION = %TRUE
      EXIT FUNCTION

    CASE %WM_SETCURSOR
      ptsbi = GetWindowLong(hWnd, 0)
      ' Set the cursor iff the parent container did not set it
      lRet = DefWindowProc(hWnd, uMsg, wParam, lParam)
      IF ISFALSE lRet THEN
        dwStyle = GetWindowLong(hWnd, %GWL_STYLE)
        hCursor = @ptsbi.hCursor
        IF hCursor = %NULL THEN
          IF (dwStyle AND %SBSTYLE_HORIZONTAL) = %SBSTYLE_HORIZONTAL THEN
            SetCursor LoadCursor(%NULL, BYVAL %IDC_SIZENS)
            lpIconRes = CODEPTR(sbc32wpHCur)
          ELSE
            SetCursor LoadCursor(%NULL, BYVAL %IDC_SIZEWE)
            lpIconRes = CODEPTR(sbc32wpVCur)
          END IF
          IF ISTRUE lpIconRes THEN
            ptid = lpIconRes
            IF @ptid.idCount >= 1 THEN
              ptide = ptid + SIZEOF(tid)
              ' CreateIconFromResource() creates a shared cursor.  We don't want to call
              ' this function repeatedly since this may cause a memory leak on some systems.
              hCursor = CreateIconFromResource(BYVAL ptid + @ptide.dwImageOffset, @ptide.dwBytesInRes, @ptid.idType, &H30000???)
              @ptsbi.hCursor = hCursor
            END IF
          END IF
        END IF
        IF (dwStyle AND %SBSTYLE_NOHOVERCURSOR) = %SBSTYLE_NOHOVERCURSOR THEN
          SetCursor @ptsbi.hCursor
        ELSE
          IF (dwStyle AND %SBSTYLE_HORIZONTAL) = %SBSTYLE_HORIZONTAL THEN
            SetCursor LoadCursor(%NULL, BYVAL %IDC_SIZENS)
          ELSE
            SetCursor LoadCursor(%NULL, BYVAL %IDC_SIZEWE)
          END IF
        END IF
        lRet = %TRUE
      END IF
      FUNCTION = lRet
      EXIT FUNCTION

    CASE %WM_MOVE
      SendMessage GetParent(hWnd), %WM_COMMAND, MAKDWD(GetDlgCtrlID(hWnd), %SBARN_POSCHANGED), hWnd

    CASE %WM_MOUSEMOVE
      ptsbi = GetWindowLong(hWnd, 0)
      ' If resize bar is being dragged
      IF (@ptsbi.fResizing AND (%MK_LBUTTON AND wParam)) THEN
        wOffset1 = MAX(@ptsbi.wOffset1, 2)
        wOffset2 = MAX(@ptsbi.wOffset2, 2)
        hWndParent = GetParent(hWnd)
        GetClientRect hWndParent, trcWin
        MapWindowPoints hWndParent, %NULL, BYVAL VARPTR(trcWin), 2
        dwStyle = GetWindowLong(hWnd, %GWL_STYLE)
        ' Get the bounding rectangle of the control
        GetWindowRect hWnd, trc
        ' Get coords of mouse and calculate change in position
        GetCursorPos tpt
        IF (dwStyle AND %SBSTYLE_HORIZONTAL) = %SBSTYLE_HORIZONTAL THEN
          lDim     = trc.nBottom - trc.nTop
          dx       = 0
          dy       = tpt.y - @ptsbi.tptOld.y
          lOffset1 = trcWin.nTop + wOffset1
          lOffset2 = trcWin.nBottom - wOffset2
          IF ((@ptsbi.yNew + dy) < lOffset1) OR ((@ptsbi.yNew + lDim + dy) > lOffset2) THEN dy = 0
        ELSE
          lDim     = trc.nRight - trc.nLeft
          dx       = tpt.x - @ptsbi.tptOld.x
          dy       = 0
          lOffset1 = trcWin.nLeft + wOffset1
          lOffset2 = trcWin.nRight - wOffset2
          IF ((@ptsbi.xNew + dx) < lOffset1) OR ((@ptsbi.xNew + lDim + dx) > lOffset2) THEN dx = 0
        END IF
        ' If cursor is within the client area of the window
        IF ISTRUE PtInRect(trcWin, tpt) THEN
          IF (dx <> 0) OR (dy <> 0) THEN
            ' Save current coordinates of mouse
            @ptsbi.tptOld = tpt
            ' Erase old line
            SplitterbarClass32_DrawDragImage hWnd
            ' Update position of splitterbar and drag image
            @ptsbi.xNew = @ptsbi.xNew + dx
            @ptsbi.yNew = @ptsbi.yNew + dy
            @ptsbi.trc.nLeft   = @ptsbi.trc.nLeft   + dx
            @ptsbi.trc.nTop    = @ptsbi.trc.nTop    + dy
            @ptsbi.trc.nRight  = @ptsbi.trc.nRight  + dx
            @ptsbi.trc.nBottom = @ptsbi.trc.nBottom + dy
            ' Draw new line
            SplitterbarClass32_DrawDragImage hWnd
          END IF
        END IF
      END IF
      FUNCTION = %FALSE
      EXIT FUNCTION

    CASE %WM_LBUTTONDOWN
      ptsbi = GetWindowLong(hWnd, 0)
      IF ISTRUE IsWindowEnabled(hWnd) THEN
        ' Capture mouse
        SetCapture hWnd

        @ptsbi.fResizing = %TRUE

        SetCursor @ptsbi.hCursor

        GetCursorPos tpt
        hWndParent = GetParent(hWnd)
        GetClientRect hWndParent, trcWin
        MapWindowPoints hWndParent, %NULL, BYVAL VARPTR(trcWin), 2
        GetWindowRect hWnd, trc
        ' Initialize the new position of the splitterbar
        @ptsbi.xNew = trc.nLeft
        @ptsbi.yNew = trc.nTop

        IntersectRect @ptsbi.trc, trc, trcWin
        GetWindowRect hWndParent, trcWin
        IF (GetWindowLong(hWnd, %GWL_STYLE) AND %SBSTYLE_HORIZONTAL) = %SBSTYLE_HORIZONTAL THEN
          IF (trc.nBottom - trc.nTop) > 3 THEN fDeflate = -1
          tpt.y = (@ptsbi.trc.nBottom + @ptsbi.trc.nTop) \ 2
        ELSE
          IF (trc.nRight - trc.nLeft) > 3 THEN fDeflate = -1
          tpt.x = (@ptsbi.trc.nRight + @ptsbi.trc.nLeft) \ 2
        END IF

        ' Bounding rectangle of drag image in coordinate
        ' space of the window dc of the parent window
        OffsetRect @ptsbi.trc, -trcWin.nLeft, -trcWin.nTop
        IF fDeflate THEN InflateRect @ptsbi.trc, -1, -1

        ' Create brush used to paint line
        hBmp = CreateBitmap(8, 8, 1, 1, BYVAL CODEPTR(sbc32wpBr))
        @ptsbi.hBr = CreatePatternBrush(hBmp)
        DeleteObject hBmp
        SplitterbarClass32_DrawDragImage hWnd

        ' Save the initial coordinates of the mouse
        @ptsbi.tptOld = tpt
        SetCursorPos tpt.x, tpt.y
      END IF
      FUNCTION = %FALSE
      EXIT FUNCTION

    CASE %WM_LBUTTONDBLCLK
      SendMessage GetParent(hWnd), %WM_COMMAND, MAKDWD(GetDlgCtrlID(hWnd), %SBARN_DBLCLK), hWnd

    CASE %WM_LBUTTONUP
      IF GetCapture() = hWnd THEN ReleaseCapture

    CASE %WM_CAPTURECHANGED
      ptsbi = GetWindowLong(hWnd, 0)
      IF @ptsbi.fResizing THEN
        @ptsbi.fResizing = %FALSE
        ' Erase old line
        SplitterbarClass32_DrawDragImage hWnd
        ' Delete the brush used to paint line
        DeleteObject @ptsbi.hBr

        ' Calculate the new position of the splitterbar
        tpt.x = @ptsbi.xNew
        tpt.y = @ptsbi.yNew
        ScreenToClient GetParent(hWnd), tpt
        SetWindowPos hWnd, %NULL, tpt.x, tpt.y, 0, 0, %SWP_NOSIZE OR %SWP_NOZORDER

        ' The following two calls will cause the cursor to revert to
        ' the appropriate cursor for the window it is currently over
        ' since a WM_SETCURSOR is generated.
        GetCursorPos tpt
        SetCursorPos tpt.x, tpt.y
      END IF
      FUNCTION = %FALSE
      EXIT FUNCTION

    CASE %WM_DESTROY
      ptsbi = GetWindowLong(hWnd, 0)
      IF ISTRUE ptsbi THEN HeapFree GetProcessHeap(), 0, ptsbi
  END SELECT

  FUNCTION = DefWindowProc(hWnd, uMsg, wParam, lParam)
  EXIT FUNCTION

' Pattern brush(drag)
sbc32wpBr:
! dw &HAA??, &H55??, &HAA??, &H55??, &HAA??, &H55??, &HAA??, &H55??

' Default horizontal split cursor
sbc32wpHCur:
! db &H00?, &H00?, &H02?, &H00?, &H01?, &H00?, &H20?, &H20?, &H00?, &H00?, &H10?, &H00?, &H10?, &H00?, &H30?, &H01?
! db &H00?, &H00?, &H16?, &H00?, &H00?, &H00?, &H28?, &H00?, &H00?, &H00?, &H20?, &H00?, &H00?, &H00?, &H40?, &H00?
! db &H00?, &H00?, &H01?, &H00?, &H01?, &H00?, &H00?, &H00?, &H00?, &H00?, &H80?, &H00?, &H00?, &H00?, &H00?, &H00?
! db &H00?, &H00?, &H00?, &H00?, &H00?, &H00?, &H00?, &H00?, &H00?, &H00?, &H00?, &H00?, &H00?, &H00?, &H00?, &H00?
! db &H00?, &H00?, &HFF?, &HFF?, &HFF?, &H00?, &H00?, &H00?, &H00?, &H00?, &H00?, &H00?, &H00?, &H00?, &H00?, &H00?
! db &H00?, &H00?, &H00?, &H00?, &H00?, &H00?, &H00?, &H00?, &H00?, &H00?, &H00?, &H00?, &H00?, &H00?, &H00?, &H00?
! db &H00?, &H00?, &H00?, &H01?, &H80?, &H00?, &H00?, &H02?, &H40?, &H00?, &H00?, &H04?, &H20?, &H00?, &H00?, &H08?
! db &H10?, &H00?, &H00?, &H0E?, &H70?, &H00?, &H00?, &H02?, &H40?, &H00?, &H01?, &HFE?, &H7F?, &H80?, &H01?, &H00?
! db &H00?, &H80?, &H01?, &HFF?, &HFF?, &H80?, &H01?, &H00?, &H00?, &H80?, &H01?, &HFE?, &H7F?, &H80?, &H00?, &H02?
! db &H40?, &H00?, &H00?, &H0E?, &H70?, &H00?, &H00?, &H08?, &H10?, &H00?, &H00?, &H04?, &H20?, &H00?, &H00?, &H02?
! db &H40?, &H00?, &H00?, &H01?, &H80?, &H00?, &H00?, &H00?, &H00?, &H00?, &H00?, &H00?, &H00?, &H00?, &H00?, &H00?
! db &H00?, &H00?, &H00?, &H00?, &H00?, &H00?, &H00?, &H00?, &H00?, &H00?, &H00?, &H00?, &H00?, &H00?, &H00?, &H00?
! db &H00?, &H00?, &H00?, &H00?, &H00?, &H00?, &HFF?, &HFF?, &HFF?, &HFF?, &HFF?, &HFF?, &HFF?, &HFF?, &HFF?, &HFF?
! db &HFF?, &HFF?, &HFF?, &HFF?, &HFF?, &HFF?, &HFF?, &HFF?, &HFF?, &HFF?, &HFF?, &HFF?, &HFF?, &HFF?, &HFF?, &HFF?
! db &HFF?, &HFF?, &HFF?, &HFE?, &H7F?, &HFF?, &HFF?, &HFC?, &H3F?, &HFF?, &HFF?, &HF8?, &H1F?, &HFF?, &HFF?, &HF0?
! db &H0F?, &HFF?, &HFF?, &HF0?, &H0F?, &HFF?, &HFF?, &HFC?, &H3F?, &HFF?, &HFE?, &H00?, &H00?, &H7F?, &HFE?, &H00?
! db &H00?, &H7F?, &HFE?, &H00?, &H00?, &H7F?, &HFE?, &H00?, &H00?, &H7F?, &HFE?, &H00?, &H00?, &H7F?, &HFF?, &HFC?
! db &H3F?, &HFF?, &HFF?, &HF0?, &H0F?, &HFF?, &HFF?, &HF0?, &H0F?, &HFF?, &HFF?, &HF8?, &H1F?, &HFF?, &HFF?, &HFC?
! db &H3F?, &HFF?, &HFF?, &HFE?, &H7F?, &HFF?, &HFF?, &HFF?, &HFF?, &HFF?, &HFF?, &HFF?, &HFF?, &HFF?, &HFF?, &HFF?
! db &HFF?, &HFF?, &HFF?, &HFF?, &HFF?, &HFF?, &HFF?, &HFF?, &HFF?, &HFF?, &HFF?, &HFF?, &HFF?, &HFF?, &HFF?, &HFF?
! db &HFF?, &HFF?, &HFF?, &HFF?, &HFF?, &HFF?

' Default vertical split cursor
sbc32wpVCur:
! db &H00?, &H00?, &H02?, &H00?, &H01?, &H00?, &H20?, &H20?, &H00?, &H00?, &H0F?, &H00?, &H10?, &H00?, &H30?, &H01?
! db &H00?, &H00?, &H16?, &H00?, &H00?, &H00?, &H28?, &H00?, &H00?, &H00?, &H20?, &H00?, &H00?, &H00?, &H40?, &H00?
! db &H00?, &H00?, &H01?, &H00?, &H01?, &H00?, &H00?, &H00?, &H00?, &H00?, &H80?, &H00?, &H00?, &H00?, &H00?, &H00?
! db &H00?, &H00?, &H00?, &H00?, &H00?, &H00?, &H00?, &H00?, &H00?, &H00?, &H00?, &H00?, &H00?, &H00?, &H00?, &H00?
! db &H00?, &H00?, &HFF?, &HFF?, &HFF?, &H00?, &H00?, &H00?, &H00?, &H00?, &H00?, &H00?, &H00?, &H00?, &H00?, &H00?
! db &H00?, &H00?, &H00?, &H00?, &H00?, &H00?, &H00?, &H00?, &H00?, &H00?, &H00?, &H00?, &H00?, &H00?, &H00?, &H00?
! db &H00?, &H00?, &H00?, &H07?, &HC0?, &H00?, &H00?, &H05?, &H40?, &H00?, &H00?, &H05?, &H40?, &H00?, &H00?, &H05?
! db &H40?, &H00?, &H00?, &H05?, &H40?, &H00?, &H00?, &H35?, &H58?, &H00?, &H00?, &H55?, &H54?, &H00?, &H00?, &H9D?
! db &H72?, &H00?, &H01?, &H01?, &H01?, &H00?, &H01?, &H01?, &H01?, &H00?, &H00?, &H9D?, &H72?, &H00?, &H00?, &H55?
! db &H54?, &H00?, &H00?, &H35?, &H58?, &H00?, &H00?, &H05?, &H40?, &H00?, &H00?, &H05?, &H40?, &H00?, &H00?, &H05?
! db &H40?, &H00?, &H00?, &H05?, &H40?, &H00?, &H00?, &H07?, &HC0?, &H00?, &H00?, &H00?, &H00?, &H00?, &H00?, &H00?
! db &H00?, &H00?, &H00?, &H00?, &H00?, &H00?, &H00?, &H00?, &H00?, &H00?, &H00?, &H00?, &H00?, &H00?, &H00?, &H00?
! db &H00?, &H00?, &H00?, &H00?, &H00?, &H00?, &HFF?, &HFF?, &HFF?, &HFF?, &HFF?, &HFF?, &HFF?, &HFF?, &HFF?, &HFF?
! db &HFF?, &HFF?, &HFF?, &HFF?, &HFF?, &HFF?, &HFF?, &HFF?, &HFF?, &HFF?, &HFF?, &HFF?, &HFF?, &HFF?, &HFF?, &HFF?
! db &HFF?, &HFF?, &HFF?, &HF8?, &H3F?, &HFF?, &HFF?, &HF8?, &H3F?, &HFF?, &HFF?, &HF8?, &H3F?, &HFF?, &HFF?, &HF8?
! db &H3F?, &HFF?, &HFF?, &HF8?, &H3F?, &HFF?, &HFF?, &HC8?, &H27?, &HFF?, &HFF?, &H88?, &H23?, &HFF?, &HFF?, &H00?
! db &H01?, &HFF?, &HFE?, &H00?, &H00?, &HFF?, &HFE?, &H00?, &H00?, &HFF?, &HFF?, &H00?, &H01?, &HFF?, &HFF?, &H88?
! db &H23?, &HFF?, &HFF?, &HC8?, &H27?, &HFF?, &HFF?, &HF8?, &H3F?, &HFF?, &HFF?, &HF8?, &H3F?, &HFF?, &HFF?, &HF8?
! db &H3F?, &HFF?, &HFF?, &HF8?, &H3F?, &HFF?, &HFF?, &HF8?, &H3F?, &HFF?, &HFF?, &HFF?, &HFF?, &HFF?, &HFF?, &HFF?
! db &HFF?, &HFF?, &HFF?, &HFF?, &HFF?, &HFF?, &HFF?, &HFF?, &HFF?, &HFF?, &HFF?, &HFF?, &HFF?, &HFF?, &HFF?, &HFF?
! db &HFF?, &HFF?, &HFF?, &HFF?, &HFF?, &HFF?

END FUNCTION

'###############################################################################
' END Splitterbar_Class32
'###############################################################################

