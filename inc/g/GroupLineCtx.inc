' ========================================================================================
' GroupLine control
' Based in the CGroupLine control posted by Warren D. Stevens in The Code Project.
' http://www.codeproject.com/staticctrl/groupline.asp
' (c) 2008-2010 by José Roca. Freeware. Use at your own risk.
' ========================================================================================

' ========================================================================================
' Theme aware control that adds a line to your static text. The control looks similar to
' the controls used in Office 2003 (see Tools->Options in Word or Excel). It is called
' GroupLine because it is very similar to the standard GroupBox. The GroupLine control
' looks very much like the top edge of a GroupBox, and the purpose of both controls is to
' present dialog controls in logical groups. The difference is that the GroupLine is only
' the top Line of the GroupBox.
'
' GroupLine provides a nice way to bundle controls into logical groups (the whole point
' of a group control), but without the downside of the GroupBox (i.e. wasting valuable
' dialog real estate, on the left, right and bottom).

' * Text can be left, center or right aligned
' * The horizontal line takes up the remainder of the room in the control (a small gap is
'   left between the text and line).
' * Theme support is set to "Automatic" by default. You can disable theming calling the
'   GroupLineCtx_DisableTheming function
' * Windows XP draws standard GroupBoxes with themes the same way when enabled as when
'   they are disabled. This seemed like an odd behaviour, so GroupLine draws the disabled
'   state with grayed-out text.
' * If the control is not theme-enabled or you use it in a non-XP version of Windows,
'   it will be drawn using a classic Windows 2D appearance.
' ========================================================================================

#INCLUDE THIS ONCE
%GROUPLINECTX_INC = 1

#INCLUDE ONCE "uxtheme.inc"

' ========================================================================================
' GroupLine data structure
' ========================================================================================
TYPE GROUPLINECTXDATA
   m_dwTextFlags AS DWORD       ' // Format text flags
   m_hFont AS DWORD             ' // Default font handle
   m_bOwnFont AS LONG           ' // The control owns the font
   m_bIsThemed AS LONG          ' // Application is themed
END TYPE
' ========================================================================================

' ========================================================================================
' GroupLine control implementation
' ========================================================================================
FUNCTION UxDrawGroupLineCtx (BYVAL hwnd AS DWORD, BYVAL hDc AS DWORD) AS LONG

   LOCAL pgl AS GROUPLINECTXDATA PTR       ' // Pointer to the control data
   LOCAL hr AS LONG                        ' // Result code
   LOCAL hTheme AS DWORD                   ' // Theme handle
   LOCAL rc AS RECT                        ' // Coordinates of the control client area
   LOCAL rcContent AS RECT                 ' // Coordinates of the control content
   LOCAL iStateId AS LONG                  ' // Control state
   LOCAL rcText AS RECT                    ' // Coordinates for drawing text
   LOCAL rcDraw AS RECT                    ' // Coordinates for drawing operations
   LOCAL pLineColor AS LONG                ' // Color to draw the line
   LOCAL textWidth AS LONG                 ' // Width of the text
   LOCAL textHeight AS LONG                ' // Height of the text
   LOCAL hPen AS DWORD                     ' // Handle of the pen to draw the line
   LOCAL hOldPen AS DWORD                  ' // Old selected pen handle
   LOCAL nPos AS LONG                      ' // Starting position to draw the line
   LOCAL szl AS SIZEL                      ' // SIZEL structure
   LOCAL wszCaption AS WSTRINGZ * 260      ' // Control text (unicode)

   ' // Checks the validity of the parameters
   IF ISFALSE hwnd THEN EXIT FUNCTION
   IF ISFALSE hDc THEN EXIT FUNCTION

   ' // Gets a pointer to the control data
   pgl = GetWindowLong(hwnd, 0)
   IF ISFALSE pgl THEN EXIT FUNCTION

   ' // Gets the text of the control
   hr = GetWindowTextW(hwnd, wszCaption, SIZEOF(wszCaption))

   ' // Opens the theme data for the specified window and class
   IF @pgl.m_bIsThemed THEN
      hTheme = OpenThemeData(hwnd, "Button")
      IF ISFALSE hTheme THEN EXIT FUNCTION
   END IF

   ' // Gets the coordinates of the control's client area
   GetClientRect hwnd, rc

   ' // Sets the state of the control
   iStateId = %GBS_NORMAL
   IF ISFALSE IsWindowEnabled(hwnd) THEN iStateId = %GBS_DISABLED

   ' // Draws the control
   IF @pgl.m_bIsThemed THEN
      ' // Gets the size of the content for the theme-defined background
      hr = GetThemeBackgroundContentRect(hTheme, hDc, %BP_GROUPBOX, iStateId, rc, rcContent)
      ' // Calculates the size/location of the specified text
      hr = GetThemeTextExtent(hTheme, hDc, %BP_GROUPBOX, %GBS_NORMAL, _
              wszCaption, -1, %DT_LEFT OR %DT_SINGLELINE, BYVAL %NULL, rcText)
      textWidth = rcText.nRight - rc.nLeft
      textHeight = rcText.nBottom - rc.nTop
      ' // Get the theme color to draw the line
      hr = GetThemeColor(hTheme, %BP_GROUPBOX, iStateId, %TMT_EDGESHADOWCOLOR, pLineColor)
      ' // Crete a solid pen to draw the line
      hPen = CreatePen(%PS_SOLID, 1, pLineColor)
      ' // Select the new pen
      hOldPen = SelectObject(hDc, hPen)
      IF (@pgl.m_dwTextFlags AND %DT_RIGHT) = %DT_RIGHT THEN
         ' // Sets the coordinates for drawing
         rcDraw = rcContent
         rcDraw.nTop = rcDraw.nTop - 4
         rcDraw.nLeft = rcDraw.nLeft + 1
         rcDraw.nRight = rcDraw.nRight + 1
         IF iStateId = %GBS_NORMAL THEN
            ' // Draws the text using Windows themes
            hr = DrawThemeText(hTheme, hDc, %BP_GROUPBOX, iStateId, wszCaption, -1, @pgl.m_dwTextFlags, 0, rcDraw)
         ELSE
            ' // Draws the text using GDI. This is needed because standard group boxes
            ' // with themes are drawn the same way when enabled as when they are disabled.
            SetBkMode hDc, %TRANSPARENT
            OffsetRect rcDraw, 1, 1
            SetTextColor hDc, GetSysColor(%COLOR_3DHILIGHT)
            DrawTextW hDc, wszCaption, -1, rcDraw, @pgl.m_dwTextFlags
            OffsetRect rcDraw, -1, -1
            SetTextColor hDc, GetSysColor(%COLOR_3DSHADOW)
            DrawTextW hDc, wszCaption, -1, rcDraw, @pgl.m_dwTextFlags
         END IF
         ' // Draws the line using GDI
         hr = MoveToEx(hDc, rcContent.nLeft - 3, (textHeight \ 2) + 3, BYVAL %NULL)
         hr = LineTo(hDc, rcContent.nRight - textWidth - 6, (textHeight \ 2) + 3)
      ELSEIF (@pgl.m_dwTextFlags AND %DT_CENTER) = %DT_CENTER THEN
         ' // Sets the coordinates for drawing
         rcDraw = rcContent
         rcDraw.nTop = rcDraw.nTop - 4
         IF iStateId = %GBS_NORMAL THEN
            ' // Draws the text using Windows themes
            hr = DrawThemeText(hTheme, hDc, %BP_GROUPBOX, iStateId, wszCaption, -1, @pgl.m_dwTextFlags, 0, rcDraw)
         ELSE
            ' // Draws the text using GDI. This is needed because standard group boxes
            ' // with themes are drawn the same way when enabled as when they are disabled.
            SetBkMode hDc, %TRANSPARENT
            OffsetRect rcDraw, 1, 1
            SetTextColor hDc, GetSysColor(%COLOR_3DHILIGHT)
            DrawTextW hDc, wszCaption, -1, rcDraw, @pgl.m_dwTextFlags
            OffsetRect rcDraw, -1, -1
            SetTextColor hDc, GetSysColor(%COLOR_3DSHADOW)
            DrawTextW hDc, wszCaption, -1, rcDraw, @pgl.m_dwTextFlags
         END IF
         ' // Draws the lines using GDI
         hr = MoveToEx(hDc, rcContent.nLeft - 3, (textHeight \ 2) + 3, BYVAL %NULL)
         nPos = rcContent.nLeft + ((rcContent.nRight - rcContent.nLeft) \ 2) - (textWidth \ 2)
         hr = LineTo(hDc, nPos - 5, (textHeight \ 2) + 3)
         nPos = nPos + textWidth
         hr = MoveToEx(hDc, nPos + 7, (textHeight \ 2) + 3, BYVAL %NULL)
         hr = LineTo(hDc, rcContent.nRight + 3, (textHeight \ 2) + 3)
      ELSE
         ' // Sets the coordinates for drawing
         rcDraw = rcContent
         rcDraw.nLeft = rcDraw.nLeft - 4
         rcDraw.nTop = rcDraw.nTop - 4
         IF iStateId = %GBS_NORMAL THEN
            ' // Draws the text using Windows themes
            hr = DrawThemeText(hTheme, hDc, %BP_GROUPBOX, iStateId, wszCaption, -1, @pgl.m_dwTextFlags, 0, rcDraw)
         ELSE
            ' // Draws the text using GDI. This is needed because standard group boxes
            ' // with themes are drawn the same way when enabled as when they are disabled.
            SetBkMode hDc, %TRANSPARENT
            OffsetRect rcDraw, 1, 1
            SetTextColor hDc, GetSysColor(%COLOR_3DHILIGHT)
            DrawTextW hDc, wszCaption, -1, rcDraw, @pgl.m_dwTextFlags
            OffsetRect rcDraw, -1, -1
            SetTextColor hDc, GetSysColor(%COLOR_3DSHADOW)
            DrawTextW hDc, wszCaption, -1, rcDraw, @pgl.m_dwTextFlags
         END IF
         ' // Draws the line using GDI
         hr = MoveToEx(hDc, rcText.nRight + 6, (textHeight \ 2) + 3, BYVAL %NULL)
         hr = LineTo(hDc, rcContent.nRight + 3, (textHeight \ 2) + 3)
      END IF
      ' // Select the old pen
      IF hOldPen THEN SelectObject(hDc, hOldPen)
      ' // Destroys the new created pen
      DeleteObject hPen
   ELSE
      ' // Draws the text using GDI
      SetBkMode hDc, %TRANSPARENT
      rcContent = rc
      ' // Calculates the size/location of the specified text
      hr = GetTextExtentPoint32W(hDc, wszCaption, LEN(wszCaption), szl)
      textWidth = szl.cx
      textHeight = szl.cy
      ' Calculate coordinates and draw text and line(s)
      IF (@pgl.m_dwTextFlags AND %DT_RIGHT) = %DT_RIGHT THEN
         rcDraw = rcContent
         IF iStateId = %GBS_DISABLED THEN
            OffsetRect rcDraw, 1, 1
            SetTextColor hDc, GetSysColor(%COLOR_3DHILIGHT)
            DrawTextW hDc, wszCaption, -1, rcDraw, @pgl.m_dwTextFlags
            OffsetRect rcDraw, -1, -1
            SetTextColor hDc, GetSysColor(%COLOR_3DSHADOW)
            DrawTextW hDc, wszCaption, -1, rcDraw, @pgl.m_dwTextFlags
         ELSE
            SetTextColor hDc, GetSysColor(%COLOR_BTNTEXT)
            SetBkColor hDc, GetSysColor(%COLOR_BTNFACE)
            DrawTextW hDc, wszCaption, -1, rcContent, @pgl.m_dwTextFlags
         END IF
         hPen = CreatePen(%PS_SOLID, 1, GetSysColor(%COLOR_3DHIGHLIGHT))
         hOldPen = SelectObject(hDc, hPen)
         hr = MoveToEx(hDc, rcContent.nLeft - 3, (textHeight \ 2) + 4 + 1, BYVAL %NULL)
         hr = LineTo(hDc, rcContent.nRight - textWidth - 6, (textHeight \ 2) + 4 + 1)
         IF hOldPen THEN SelectObject(hDc, hOldPen)
         DeleteObject hPen
         hPen = CreatePen(%PS_SOLID, 1, GetSysColor(%COLOR_3DSHADOW))
         hOldPen = SelectObject(hDc, hPen)
         hr = MoveToEx(hDc, rcContent.nLeft - 3, (textHeight \ 2) + 4, BYVAL %NULL)
         hr = LineTo(hDc, rcContent.nRight - textWidth - 6, (textHeight \ 2) + 4)
         IF hOldPen THEN SelectObject(hDc, hOldPen)
         DeleteObject hPen
      ELSEIF (@pgl.m_dwTextFlags AND %DT_CENTER) = %DT_CENTER THEN
         rcDraw = rcContent
         IF iStateId = %GBS_DISABLED THEN
            OffsetRect rcDraw, 1, 1
            SetTextColor hDc, GetSysColor(%COLOR_3DHILIGHT)
            DrawTextW hDc, wszCaption, -1, rcDraw, @pgl.m_dwTextFlags
            OffsetRect rcDraw, -1, -1
            SetTextColor hDc, GetSysColor(%COLOR_3DSHADOW)
            DrawTextW hDc, wszCaption, -1, rcDraw, @pgl.m_dwTextFlags
         ELSE
            SetTextColor hDc, GetSysColor(%COLOR_BTNTEXT)
            SetBkColor hDc, GetSysColor(%COLOR_BTNFACE)
            DrawTextW hDc, wszCaption, -1, rcContent, @pgl.m_dwTextFlags
         END IF
         hPen = CreatePen(%PS_SOLID, 1, GetSysColor(%COLOR_3DHIGHLIGHT))
         hOldPen = SelectObject(hDc, hPen)
         hr = MoveToEx(hDc, rcContent.nLeft - 3, (textHeight \ 2) + 4 + 1, BYVAL %NULL)
         nPos = rcContent.nLeft + ((rcContent.nRight - rcContent.nLeft) \ 2) - (textWidth \ 2)
         hr = LineTo(hDc, nPos - 5, (textHeight \ 2) + 4 + 1)
         nPos = nPos + textWidth
         hr = MoveToEx(hDc, nPos + 7, (textHeight \ 2) + 4 + 1, BYVAL %NULL)
         hr = LineTo(hDc, rcContent.nRight + 3, (textHeight \ 2) + 4 + 1)
         IF hOldPen THEN SelectObject(hDc, hOldPen)
         DeleteObject hPen
         hPen = CreatePen(%PS_SOLID, 1, GetSysColor(%COLOR_3DSHADOW))
         hOldPen = SelectObject(hDc, hPen)
         hr = MoveToEx(hDc, rcContent.nLeft - 3, (textHeight \ 2) + 4, BYVAL %NULL)
         nPos = rcContent.nLeft + ((rcContent.nRight - rcContent.nLeft) \ 2) - (textWidth \ 2)
         hr = LineTo(hDc, nPos - 5, (textHeight \ 2) + 4)
         nPos = nPos + textWidth
         hr = MoveToEx(hDc, nPos + 7, (textHeight \ 2) + 4, BYVAL %NULL)
         hr = LineTo(hDc, rcContent.nRight + 3, (textHeight \ 2) + 4)
         IF hOldPen THEN SelectObject(hDc, hOldPen)
         DeleteObject hPen
      ELSE
         rcDraw = rcContent
         IF iStateId = %GBS_DISABLED THEN
            OffsetRect rcDraw, 1, 1
            SetTextColor hDc, GetSysColor(%COLOR_3DHILIGHT)
            DrawTextW hDc, wszCaption, -1, rcDraw, @pgl.m_dwTextFlags
            OffsetRect rcDraw, -1, -1
            SetTextColor hDc, GetSysColor(%COLOR_3DSHADOW)
            DrawTextW hDc, wszCaption, -1, rcDraw, @pgl.m_dwTextFlags
         ELSE
            SetTextColor hDc, GetSysColor(%COLOR_BTNTEXT)
            SetBkColor hDc, GetSysColor(%COLOR_BTNFACE)
            DrawTextW hDc, wszCaption, -1, rcContent, @pgl.m_dwTextFlags
         END IF
         hPen = CreatePen(%PS_SOLID, 1, GetSysColor(%COLOR_3DHIGHLIGHT))
         hOldPen = SelectObject(hDc, hPen)
         hr = MoveToEx(hDc, textWidth + 6, (textHeight \ 2) + 4 + 1, BYVAL %NULL)
         hr = LineTo(hDc, rcContent.nRight + 3, (textHeight \ 2) + 4 + 1)
         IF hOldPen THEN SelectObject(hDc, hOldPen)
         DeleteObject hPen
         hPen = CreatePen(%PS_SOLID, 1, GetSysColor(%COLOR_3DSHADOW))
         hOldPen = SelectObject(hDc, hPen)
         hr = MoveToEx(hDc, textWidth + 6, (textHeight \ 2) + 4, BYVAL %NULL)
         hr = LineTo(hDc, rcContent.nRight + 3, (textHeight \ 2) + 4)
         IF hOldPen THEN SelectObject(hDc, hOldPen)
         DeleteObject hPen
      END IF
   END IF

   IF @pgl.m_bIsThemed THEN
      ' // Closes the theme data handle
      CloseThemeData(hTheme)
   END IF

   FUNCTION = hr

END FUNCTION
' ========================================================================================

' ========================================================================================
' Registers the window class
' ========================================================================================
FUNCTION InitGroupLineCtx () AS WORD

   LOCAL  wcex AS WNDCLASSEX               ' // WNDCLASSEX structure
   STATIC wAtom AS WORD                    ' // Atom

   ' // Already initialized
   IF wAtom <> 0 THEN
      FUNCTION = wAtom
      EXIT FUNCTION
   END IF

   ' // Class name
#IF %DEF(%UNICODE)
   LOCAL szClassName AS WSTRINGZ * 256
#ELSE
   LOCAL szClassName AS ASCIIZ * 256
#ENDIF
   szClassName        = "GROUPLINECTX"

   wcex.cbSize        = SIZEOF(wcex)
   wcex.style         = %CS_HREDRAW OR %CS_VREDRAW ' OR %CS_GLOBALCLASS
   wcex.lpfnWndProc   = CODEPTR(GroupLineCtxProc)
   wcex.cbClsExtra    = 0
   wcex.cbWndExtra    = 4 ' For pointer to GROUPLINECTXDATA structure
   wcex.hInstance     = GetModuleHandle(BYVAL %NULL)
   wcex.hIcon         = %NULL
   wcex.hCursor       = LoadCursor(%NULL, BYVAL %IDC_ARROW)
   wcex.hbrBackground = 0
   wcex.lpszMenuName  = %NULL
   wcex.lpszClassName = VARPTR(szClassName)
   wcex.hIconSm       = %NULL

   wAtom = RegisterClassEx(wcex)
   FUNCTION = wAtom

END FUNCTION
' ========================================================================================

' ========================================================================================
' This is the code for the custom control itself.
' ========================================================================================
FUNCTION GroupLineCtxProc (BYVAL hwnd AS DWORD, BYVAL wMsg AS DWORD, _
                           BYVAL wParam AS DWORD, BYVAL lParam AS LONG) AS LONG

   LOCAL pgl AS GROUPLINECTXDATA PTR
   LOCAL hDc AS DWORD
   LOCAL pPaint AS PAINTSTRUCT

   ' // Gets a pointer to control data
   IF ISTRUE hwnd AND wMsg <> %WM_CREATE THEN pgl = GetWindowLong(hwnd, 0)

   SELECT CASE wMsg

      CASE %WM_CREATE
         ' // Allocates memory for the control data
'         pgl = HeapAlloc(GetProcessHeap(), %HEAP_ZERO_MEMORY, SIZEOF(@pgl))
         pgl = HeapAlloc(GetProcessHeap(), %HEAP_ZERO_MEMORY, SIZEOF(GROUPLINECTXDATA))
         IF ISTRUE pgl THEN
            ' // Stores the pointer in the cbWndExtra member of the window class
            SetWindowLong hwnd, 0, pgl
            ' // Checks if the application is themed
            IF ISTRUE IsAppThemed AND ISTRUE IsThemeActive THEN @pgl.m_bIsThemed = %TRUE
            ' // Default control font
            @pgl.m_hFont = GetStockObject(%ANSI_VAR_FONT)
            @pgl.m_dwTextFlags = %DT_LEFT OR %DT_VCENTER OR %DT_SINGLELINE OR %DT_NOCLIP
         ELSE
            ' // Aborts the action
            FUNCTION = -1
            EXIT FUNCTION
         END IF

      CASE %WM_DESTROY
         ' // Deletes the font
         IF ISTRUE @pgl.m_bOwnFont THEN
            IF ISTRUE @pgl.m_hFont THEN DeleteObject @pgl.m_hFont
         END IF
         ' // Deallocates the memory used for the control data
         IF pgl THEN CALL HeapFree(GetProcessHeap(), 0, BYVAL pgl)
         EXIT FUNCTION

      CASE %WM_ERASEBKGND
         ' // Don't erase the background to avoid flicker
         FUNCTION = 1
         EXIT FUNCTION

      CASE %WM_PRINTCLIENT
         ' // Draws the control in the provided device context
         hDc = wParam
         SelectObject hDC, @pgl.m_hFont
         UxDrawGroupLineCtx hwnd, hDc
         EXIT FUNCTION

      CASE %WM_PAINT
         ' // Draws the control
         hDc = BeginPaint(hwnd, pPaint)
         SelectObject hDc, @pgl.m_hFont
         UxDrawGroupLineCtx hwnd, hDc
         EndPaint hwnd, pPaint
         EXIT FUNCTION

      CASE %WM_ENABLE
         ' // Redraws the control
         InvalidateRect hwnd, BYVAL %NULL, 0
         UpdateWindow hwnd
         EXIT FUNCTION

      CASE %WM_SETFONT
         ' // Stores the font handle and redraws the control
         IF ISTRUE wParam THEN
            @pgl.m_hFont = wParam
            IF lParam  AND IsWindowVisible(hwnd) THEN
               InvalidateRect hwnd, BYVAL %NULL, 0
               UpdateWindow hwnd
            END IF
         END IF

   END SELECT

   ' Default processing for other messages.
   FUNCTION = DefWindowProc(hwnd, wMsg, wParam, lParam)

END FUNCTION
' ========================================================================================

' ========================================================================================
'                                    P R O P E R T I E S
' ========================================================================================

' ========================================================================================
' Sets the font for the control
' Parameters:
' * hwnd = control's window handle
' * m_hFont = Font handle
' * fRedraw = TRUE or FALSE (redraws the control to reflect the changes)
' * fDontOwn [optional] = If FALSE, the font is destroyed by the control; if TRUE, the
'   caller is responsible to destroy it using the returned handle.
' Return value:
' * Returns the handle of the previous font, if any.
' ========================================================================================
FUNCTION GroupLineCtx_SetFont (BYVAL hwnd AS DWORD, BYVAL hFont AS DWORD, BYVAL fRedraw AS LONG, OPTIONAL BYVAL fDontOwn AS LONG) AS LONG

   LOCAL pgl AS GROUPLINECTXDATA PTR    ' // Pointer to the control data

   ' // Check the validity of the parameters
   IF ISFALSE hwnd THEN EXIT FUNCTION
   IF ISFALSE hFont THEN EXIT FUNCTION
   ' // Gets a pointer to the control data
   pgl = GetWindowLong(hwnd, 0)
   IF ISFALSE pgl THEN EXIT FUNCTION
   ' // Return the old font handle
   FUNCTION = @pgl.m_hFont
   ' // Destroys the old font, if any, if it was owned by the control
   IF @pgl.m_bOwnFont THEN
      IF ISTRUE @pgl.m_hFont THEN DeleteObject @pgl.m_hFont
   END IF
   ' // Store the new values
   @pgl.m_hFont = hFont
   IF ISTRUE fDontOwn THEN
      @pgl.m_bOwnFont = %FALSE
   ELSE
      @pgl.m_bOwnFont = %TRUE
   END IF
   ' // Redraws the control
   IF fRedraw THEN
      InvalidateRect hwnd, BYVAL %NULL, 0
      UpdateWindow hwnd
   END IF

END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the font handle
' Parameters:
' * hwnd = control's window handle
' ========================================================================================
FUNCTION GroupLineCtx_GetFont (BYVAL hwnd AS DWORD) AS DWORD

   LOCAL pgl AS GROUPLINECTXDATA PTR    ' // Pointer to the control data

   IF ISFALSE hwnd THEN EXIT FUNCTION
   pgl = GetWindowLong(hwnd, 0)
   IF ISFALSE pgl THEN EXIT FUNCTION
   FUNCTION = @pgl.m_hFont

END FUNCTION
' ========================================================================================

' ========================================================================================
' Redraws the control
' Parameters:
' * hwnd = control's window handle
' Return value:
' * No return value.
' ========================================================================================
SUB GroupLineCtx_Redraw (BYVAL hwnd AS DWORD)
   IF ISFALSE hwnd THEN EXIT SUB
   InvalidateRect hwnd, BYVAL %NULL, 0
   UpdateWindow hwnd
END SUB
' ========================================================================================

' ========================================================================================
' Sets the text format
' Parameters:
' * hwnd = control's window handle
' * m_dwTextFlags = Format values (default DT_LEFT OR DT_VCENTER OR DT_SINGLELINE OR DT_NOCLIP)
'   - DT_BOTTOM = Renders the text string at the bottom of the display rectangle.
'     This value is used only with the DT_SINGLELINE value.
'   - DT_CENTER = Centers text horizontally in the display rectangle.
'   - DT_LEFT = Aligns text to the left.
'   - DT_NOCLIP = Draws the text string without clipping the display rectangle.
'   - DT_RIGHT = Aligns text to the right.
'   - DT_RTLREADING = Lays out text in right-to-left order for bidirectional text, for
'     example, text in a Hebrew or Arabic font. The default direction for text is
'     left-to-right.
'   - DT_SINGLELINE = Displays text on a single line. Carriage returns and line feeds do
'     not break the line.
'   - DT_TOP = Renders the text at the top of the display rectangle.
'   - DT_VCENTER = Centers text vertically. This value is used only with the DT_SINGLELINE
'     value.
' * fRedraw = TRUE or FALSE (redraws the control to reflect the changes)
' Return value:
' * Returns the previous value, if any.
' ========================================================================================
FUNCTION GroupLineCtx_SetTextFormat (BYVAL hwnd AS DWORD, BYVAL m_dwTextFlags AS DWORD, BYVAL fRedraw AS LONG) AS DWORD

   LOCAL pgl AS GROUPLINECTXDATA PTR    ' // Pointer to the control data

   IF ISFALSE hwnd THEN EXIT FUNCTION
   pgl = GetWindowLong(hwnd, 0)
   IF ISFALSE pgl THEN EXIT FUNCTION
   FUNCTION = @pgl.m_dwTextFlags
   @pgl.m_dwTextFlags = m_dwTextFlags
   ' // Redraws the control
   IF fRedraw THEN
      InvalidateRect hwnd, BYVAL %NULL, 0
      UpdateWindow hwnd
   END IF

END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the text format
' Parameters:
' * hwnd = control's window handle
' ========================================================================================
FUNCTION GroupLineCtx_GetTextFormat (BYVAL hwnd AS DWORD) AS DWORD

   LOCAL pgl AS GROUPLINECTXDATA PTR    ' // Pointer to the control data

   IF ISFALSE hwnd THEN EXIT FUNCTION
   pgl = GetWindowLong(hwnd, 0)
   IF ISFALSE pgl THEN EXIT FUNCTION
   FUNCTION = @pgl.m_dwTextFlags

END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns TRUE if themes are enabled or FALSE otherwise
' Parameters:
' * hwnd = control's window handle
' ========================================================================================
FUNCTION GroupLineCtx_IsThemed (BYVAL hwnd AS DWORD) AS LONG

   LOCAL pgl AS GROUPLINECTXDATA PTR    ' // Pointer to the control data

   IF ISFALSE hwnd THEN EXIT FUNCTION
   pgl = GetWindowLong(hwnd, 0)
   IF ISFALSE pgl THEN EXIT FUNCTION
   FUNCTION = @pgl.m_bIsThemed

END FUNCTION
' ========================================================================================

' ========================================================================================
' Enables theming
' Parameters:
' * hwnd = control's window handle
' Return value:
' * Returns TRUE or FALSE
' ========================================================================================
FUNCTION GroupLineCtx_EnableTheming (BYVAL hwnd AS DWORD) AS LONG

   LOCAL pgl AS GROUPLINECTXDATA PTR    ' // Pointer to the control data

   ' // Check the validity of the parameters
   IF ISFALSE hwnd THEN EXIT FUNCTION
   ' // Gets a pointer to the control data
   pgl = GetWindowLong(hwnd, 0)
   IF ISFALSE pgl THEN EXIT FUNCTION
   ' // Store the new state
   @pgl.m_bIsThemed = %TRUE
   ' // Redraws the control
   InvalidateRect hwnd, BYVAL %NULL, 0
   UpdateWindow hwnd
   ' // Return success
   FUNCTION = %TRUE

END FUNCTION
' ========================================================================================

' ========================================================================================
' Disables theming
' Parameters:
' * hwnd = control's window handle
' Return value:
' * Returns TRUE or FALSE
' ========================================================================================
FUNCTION GroupLineCtx_DisableTheming (BYVAL hwnd AS DWORD) AS LONG

   LOCAL pgl AS GROUPLINECTXDATA PTR    ' // Pointer to the control data

   ' // Check the validity of the parameters
   IF ISFALSE hwnd THEN EXIT FUNCTION
   ' // Gets a pointer to the control data
   pgl = GetWindowLong(hwnd, 0)
   IF ISFALSE pgl THEN EXIT FUNCTION
   ' // Store the new state
   @pgl.m_bIsThemed = %FALSE
   ' // Redraws the control
   InvalidateRect hwnd, BYVAL %NULL, 0
   UpdateWindow hwnd
   ' // Return success
   FUNCTION = %TRUE

END FUNCTION
' ========================================================================================
