' ========================================================================================
' XPBUTTON control
' Draws a themed button in Windows XP and a classic button in the other Windows versions.
' Do not use it with Windows 95 because the TrackMouseEvent is not available in that OS.
' (c) 2011 by José Roca. Freeware. Use at your own risk.
' ========================================================================================

#INCLUDE THIS ONCE
%XPBUTTON_INC = 1

#INCLUDE ONCE "uxtheme.inc"

' ========================================================================================
' XPBUTTON structure
' ========================================================================================
TYPE XPBUTTONDATA
   fState AS LONG             ' // Button state
   dwTextFlags AS DWORD       ' // Format text flags
   hCursor AS DWORD           ' // Cursor handle
   hFont AS DWORD             ' // Default font handle
   fOwnFont AS LONG           ' // The button owns the font
   hImage AS DWORD            ' // Image handle
   ImageType AS LONG          ' // Images type
   ImageWidth AS LONG         ' // Images width
   ImageHeight AS LONG        ' // Images height
   ImagePos AS LONG           ' // Images position
   fOwnImage AS LONG          ' // The button owns the image
   ImageMargin AS LONG        ' // Image margin (in pixels)
   TextMargin AS LONG         ' // Text margin (in pixels)
   hHotImage AS DWORD         ' // Hot image handle
   fOwnHotImage AS LONG       ' // The button owns the image
   hDisabledImage AS DWORD    ' // Disabled image handle
   fOwnDisabledImage AS LONG  ' // The button owns the image
   bIsToggle AS LONG          ' // Button is a toggle button
   bToggled AS LONG           ' // Toggle flag
   bIsThemed AS LONG          ' // Application is themed
   bClkDown AS LONG           ' // Button received the button down message
END TYPE
' ========================================================================================

' ========================================================================================
' Image class
' ========================================================================================
%XPBI_NORMAL = 1
%XPBI_HOT = 2
%XPBI_DISABLED = 3
' ========================================================================================

' ========================================================================================
' Image position
' ========================================================================================
%XPBI_NONE = &H0                                     ' // No image
%XPBI_LEFT = &H1                                     ' // Left (default)
%XPBI_RIGHT = &H2                                    ' // Right
%XPBI_CENTER = &H4                                   ' // Center
%XPBI_VCENTER = &H8                                  ' // Vertically centered
%XPBI_TOP = &H10                                     ' // Top
%XPBI_BOTTOM = &H20                                  ' // Bottom
%XPBI_ABOVE = %XPBI_TOP OR %XPBI_CENTER              ' // Above the text
%XPBI_BELOW = %XPBI_BOTTOM OR %XPBI_CENTER           ' // Below the text
%XPBI_CENTERCENTER = %XPBI_CENTER OR %XPBI_VCENTER   ' // Center-center (no text)
' ========================================================================================

' ========================================================================================
' XPButton control implementation
' ========================================================================================
FUNCTION UxDrawPushButton (BYVAL hwnd AS DWORD, BYVAL hDc AS DWORD) AS LONG

   LOCAL pbxp AS XPBUTTONDATA PTR           ' // Pointer to the button data
   LOCAL hr AS LONG                         ' // Result code
   LOCAL hTheme AS DWORD                    ' // Theme handle
   LOCAL rcClient AS RECT                   ' // Original coordinates of the button client area
   LOCAL rc AS RECT                         ' // Coordinates of the button client area
   LOCAL rcContent AS RECT                  ' // Coordinates of the button content
   LOCAL iStateId AS LONG                   ' // Button state
   LOCAL bIsPressed AS LONG                 ' // Boolean (pressed state)
   LOCAL bIsFocused AS LONG                 ' // Boolean (focused state)
   LOCAL bIsDisabled AS LONG                ' // Boolean (disabled state)
   LOCAL iy AS LONG                         ' // x-coordinate of the image
   LOCAL ix AS LONG                         ' // y-coordinate of the image
   LOCAL hImage AS DWORD                    ' // Image handle
   LOCAL fImageDrawn AS LONG                ' // Boolean
   LOCAL lStyle AS LONG                     ' // Button styles
   LOCAL uState AS DWORD                    ' // Initial state of the frame control
   LOCAL wszCaption AS WSTRINGZ * 260       ' // Button text

   ' // Checks the validity of the parameters
   IF hwnd = 0 THEN EXIT FUNCTION
   IF hDc = 0 THEN EXIT FUNCTION

   ' // Gets a pointer to the button data
   pbxp = GetWindowLong(hwnd, 0)
   IF pbxp = 0 THEN EXIT FUNCTION

   ' // Button styles
   IF @pbxp.bIsThemed = %FALSE THEN lStyle = GetWindowLong(hwnd, %GWL_STYLE)

   ' // Gets the text of the button
   hr = GetWindowTextW(hwnd, wszCaption, SIZEOF(wszCaption))

   ' // Opens the theme data for the specified window and class
   IF @pbxp.bIsThemed THEN
      hTheme = OpenThemeData(hwnd, "Button")
      IF hTheme = 0 THEN EXIT FUNCTION
   END IF

   ' // Gets the button state
   IF hwnd = GetFocus THEN bIsFocused = %TRUE
   IF (@pbxp.fState AND %BST_PUSHED) = %BST_PUSHED THEN bIsPressed = %TRUE
   IF IsWindowEnabled(hwnd) = %FALSE THEN bIsDisabled = %TRUE

   ' // Sets the button state for the theme
   iStateId = %PBS_NORMAL
   IF bIsPressed THEN iStateId = %PBS_PRESSED
   IF bIsDisabled THEN iStateId = %PBS_DISABLED
   IF iStateId = %PBS_NORMAL THEN
      IF bIsFocused THEN iStateId = %PBS_DEFAULTED
      IF GetProp(hwnd, "HOT") THEN iStateId = %PBS_HOT
   END IF

   ' // Toggled button
   IF @pbxp.bIsToggle AND @pbxp.bToggled THEN iStateId = %PBS_PRESSED

   ' // Gets the coordinates of the button's client area
   GetClientRect hwnd, rcClient
   rc = rcClient

   ' // Draws the button
   IF @pbxp.bIsThemed THEN
      ' // Increase 1 pixel to include the edge
      InflateRect rc, 1, 1
      ' // Draws the theme-specified border and fills for the "iPartId" and "iStateId".
      hr = DrawThemeBackground(hTheme, hDc, %BP_PUSHBUTTON, iStateId, rc, BYVAL %NULL)
      ' // Gets the size of the content for the theme-defined background
      hr = GetThemeBackgroundContentRect(hTheme, hDc, %BP_PUSHBUTTON, iStateId, rc, rcContent)
   ELSE
      ' // Uses GDI to draw the button
      rcContent = rc
      IF bIsFocused THEN
         IF @pbxp.bIsToggle = %FALSE OR bIsPressed = %FALSE THEN
            FrameRect hDc, rcContent, GetSysColorBrush(%COLOR_WINDOWTEXT)
         END IF
         InflateRect rcContent, -1, -1
      END IF
      IF @pbxp.bIsToggle THEN
         IF iStateId = %PBS_PRESSED THEN
            DrawEdge hDc, rcContent, %EDGE_SUNKEN, %BF_RECT OR %BF_MIDDLE OR %BF_SOFT
         ELSE
            IF (lStyle AND %BS_FLAT) = %BS_FLAT THEN
               DrawEdge hDc, rcContent, %EDGE_RAISED, %BF_RECT OR %BF_MIDDLE OR %BF_SOFT OR %BF_FLAT
            ELSE
               DrawEdge hDc, rcContent, %EDGE_RAISED, %BF_RECT OR %BF_MIDDLE OR %BF_SOFT
            END IF
         END IF
      ELSE
         FillRect hDc, rcContent, GetSysColorBrush(%COLOR_BTNFACE)
         IF bIsPressed THEN
            FrameRect hDc, rcContent, GetSysColorBrush(%COLOR_BTNSHADOW)
         ELSE
            uState = %DFCS_BUTTONPUSH
            IF iStateId = %PBS_HOT THEN uState = uState OR %DFCS_HOT
            IF (lStyle AND %BS_FLAT) = %BS_FLAT THEN uState = uState OR %DFCS_FLAT
            DrawFrameControl hDc, rcContent, %DFC_BUTTON, uState
         END IF
      END IF
   END IF

   ' // Calculates the y-coordinate of the image
   IF (@pbxp.ImagePos AND %XPBI_VCENTER) = %XPBI_VCENTER THEN
      iy = ((rcContent.nBottom - rcContent.nTop - @pbxp.ImageHeight) \ 2) + rcContent.nTop
   ELSEIF (@pbxp.ImagePos AND %XPBI_BOTTOM) = %XPBI_BOTTOM THEN
      iy = rcContent.nBottom - @pbxp.ImageHeight
   ELSE
      iy = rcContent.nTop
   END IF

   ' // Calculates the x-coordinate of the image
   IF (@pbxp.ImagePos AND %XPBI_RIGHT) = %XPBI_RIGHT THEN
      ix = rcContent.nRight - @pbxp.ImageMargin - @pbxp.ImageWidth
   ELSEIF (@pbxp.ImagePos AND %XPBI_LEFT) = %XPBI_LEFT THEN
      ix = rcContent.nLeft + @pbxp.ImageMargin
   ELSEIF (@pbxp.ImagePos AND %XPBI_CENTER) = %XPBI_CENTER THEN
      ix = ((rcClient.nRight - rcClient.nLeft) \ 2) - (@pbxp.ImageWidth \ 2)
   ELSE
      ix = rcContent.nLeft + @pbxp.ImageMargin
   END IF

   ' // If state = pressed, show the icon slightly displaced
   IF iStateId = %PBS_PRESSED THEN
      ix = ix + 1
      iy = iy + 1
   END IF

   ' // Draws the image (don't draw it if the icon for normal state doesn't exist)
   IF @pbxp.hImage AND @pbxp.ImagePos <> %XPBI_NONE THEN
      IF iStateId = %PBS_HOT THEN hImage = @pbxp.hHotImage
      IF iStateId = %PBS_DISABLED THEN hImage = @pbxp.hDisabledImage
      IF hImage = 0 THEN hImage = @pbxp.hImage
      IF @pbxp.ImageType = %IMAGE_BITMAP THEN
         DrawState hDc, 0, 0, hImage, 0, ix, iy, 0, 0, %DST_BITMAP
      ELSE
         DrawIconEx hDc, ix, iy, hImage, @pbxp.ImageWidth, @pbxp.ImageHeight, 0, BYVAL 0, %DI_NORMAL
      END IF
      fImageDrawn = %TRUE
   END IF

   ' // Calculates the coordinates of the text
   IF fImageDrawn THEN
      IF (@pbxp.ImagePos AND %XPBI_LEFT) = %XPBI_LEFT THEN
         IF (@pbxp.dwTextFlags AND %DT_CENTER) <> %DT_CENTER AND _
            (@pbxp.dwTextFlags AND %DT_RIGHT) <> %DT_RIGHT THEN
            IF (@pbxp.ImagePos AND %XPBI_ABOVE) = %XPBI_ABOVE THEN
               rcContent.nLeft = rcContent.nLeft + @pbxp.TextMargin
            ELSE
               rcContent.nLeft = rcContent.nLeft + @pbxp.TextMargin + @pbxp.ImageWidth + @pbxp.ImageMargin
            END IF
         END IF
      ELSEIF (@pbxp.ImagePos AND %XPBI_RIGHT) = %XPBI_RIGHT THEN
         IF (@pbxp.dwTextFlags AND %DT_RIGHT) = %DT_RIGHT THEN
            IF (@pbxp.ImagePos AND %XPBI_ABOVE) = %XPBI_ABOVE THEN
               rcContent.nRight = rcContent.nRight - @pbxp.TextMargin
            ELSE
               rcContent.nRight = rcContent.nRight - @pbxp.TextMargin - @pbxp.ImageWidth - @pbxp.ImageMargin
            END IF
         END IF
      END IF
   END IF

   IF (@pbxp.ImagePos AND %XPBI_CENTERCENTER) <> %XPBI_CENTERCENTER THEN
      IF (@pbxp.dwTextFlags AND %DT_CENTER) = %DT_CENTER THEN
         ' Do nothing
      ELSEIF (@pbxp.dwTextFlags AND %DT_RIGHT) = %DT_RIGHT THEN
         rcContent.nRight = rcContent.nRight - @pbxp.TextMargin
      ELSEIF (@pbxp.dwTextFlags AND %DT_LEFT) = %DT_LEFT THEN
         rcContent.nLeft = rcContent.nLeft + @pbxp.TextMargin
      END IF
      IF @pbxp.bIsThemed THEN
         ' // Draws the text using the theme-specified color and font for the "iPartId" and "iStateId"
         hr = DrawThemeText(hTheme, hDc, %BP_PUSHBUTTON, iStateId, wszCaption, -1, @pbxp.dwTextFlags, 0, rcContent)
      ELSE
         ' // Uses GDI to draw the text
         SetBkMode hDc, %TRANSPARENT
         IF bIsDisabled THEN
            OffsetRect rcContent, 1, 1
            SetTextColor hDc, GetSysColor(%COLOR_3DHILIGHT)
            DrawTextW hDc, wszCaption, -1, rcContent, @pbxp.dwTextFlags
            OffsetRect rcContent, -1, -1
            SetTextColor hDc, GetSysColor(%COLOR_3DSHADOW)
            DrawTextW hDc, wszCaption, -1, rcContent, @pbxp.dwTextFlags
         ELSE
            SetTextColor hDc, GetSysColor(%COLOR_BTNTEXT)
            SetBkColor hDc, GetSysColor(%COLOR_BTNFACE)
            DrawTextW hDc, wszCaption, -1, rcContent, @pbxp.dwTextFlags
         END IF
      END IF
   END IF

   IF @pbxp.bIsThemed THEN
      ' // Draws the focus rect
      IF bIsFocused THEN
         InflateRect rc, -3, -3
         DrawFocusRect hDc, rc
      END IF
      ' // Closes the theme data handle
      CloseThemeData(hTheme)
   ELSE
      ' // Draws the focus rect
      IF bIsFocused THEN
         InflateRect rc, -4, -4
         DrawFocusRect hDc, rc
      END IF
   END IF

   FUNCTION = hr

END FUNCTION
' ========================================================================================

' ========================================================================================
' Registers the window class
' ========================================================================================
FUNCTION InitXPButton () AS WORD

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
   szClassName        = "XPBUTTON"

   wcex.cbSize        = SIZEOF(wcex)
   wcex.style         = %CS_HREDRAW OR %CS_VREDRAW OR %CS_DBLCLKS  ' OR %CS_GLOBALCLASS
   wcex.lpfnWndProc   = CODEPTR(XPButtonProc)
   wcex.cbClsExtra    = 0
   wcex.cbWndExtra    = 4 ' For pointer to XPBUTTONDATA structure
   wcex.hInstance     = GetModuleHandle(BYVAL %NULL)
   wcex.hIcon         = %NULL
   wcex.hCursor       = %NULL
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
FUNCTION XPButtonProc (BYVAL hwnd AS DWORD, BYVAL wMsg AS DWORD, _
                       BYVAL wParam AS DWORD, BYVAL lParam AS LONG) AS LONG

   LOCAL pbxp AS XPBUTTONDATA PTR
   LOCAL hDc AS DWORD
   LOCAL pPaint AS PAINTSTRUCT
   LOCAL rc AS RECT
   LOCAL pt AS POINT
   LOCAL trackMouse AS TRACKMOUSEEVENTAPI
   LOCAL pMsg AS TAGMSG PTR
   LOCAL dwMsg AS DWORD

   ' // Gets a pointer to button data
   IF hwnd AND wMsg <> %WM_CREATE THEN pbxp = GetWindowLong(hwnd, 0)

   SELECT CASE wMsg

      CASE %WM_CREATE
         ' // Allocates memory for the button data
'         pbxp = HeapAlloc(GetProcessHeap(), %HEAP_ZERO_MEMORY, SIZEOF(@pbxp))
         pbxp = HeapAlloc(GetProcessHeap(), %HEAP_ZERO_MEMORY, SIZEOF(XPBUTTONDATA))
         IF pbxp THEN
            ' // Stores the pointer in the cbWndExtra member of the window class
            SetWindowLong hwnd, 0, pbxp
            ' // Checks if the application is themed
            IF IsAppThemed AND IsThemeActive THEN @pbxp.bIsThemed = %TRUE
            ' // Default button font
            @pbxp.hFont = GetStockObject(%ANSI_VAR_FONT)
            @pbxp.dwTextFlags = %DT_CENTER OR %DT_VCENTER OR %DT_SINGLELINE
            @pbxp.ImagePos = %XPBI_LEFT OR %XPBI_VCENTER
            @pbxp.ImageMargin = 4
            @pbxp.TextMargin = 4
            @pbxp.hCursor = LoadCursor(%NULL, BYVAL %IDC_ARROW)
         ELSE
            ' // Aborts the action
            FUNCTION = -1
            EXIT FUNCTION
         END IF

      CASE %WM_DESTROY
         ' // Deletes the images
         IF @pbxp.fOwnImage THEN
            IF @pbxp.hImage THEN DeleteObject @pbxp.hImage
         END IF
         IF @pbxp.fOwnHotImage THEN
            IF @pbxp.hHotImage THEN DeleteObject @pbxp.hHotImage
         END IF
         IF @pbxp.fOwnDisabledImage THEN
            IF @pbxp.hDisabledImage THEN DeleteObject @pbxp.hDisabledImage
         END IF
         ' // Deletes the font
         IF @pbxp.fOwnFont THEN
            IF @pbxp.hFont THEN DeleteObject @pbxp.hFont
         END IF
         ' // Deallocates the memory used for the button data
         IF pbxp THEN CALL HeapFree(GetProcessHeap(), 0, BYVAL pbxp)
         EXIT FUNCTION

      CASE %WM_ERASEBKGND
         ' // Don't erase the background to avoid flicker
         FUNCTION = 1
         EXIT FUNCTION

      CASE %WM_PRINTCLIENT
         ' // Draws the button
         hDc = wParam
         SelectObject hDC, @pbxp.hFont
         UxDrawPushButton hwnd, hDc
         EXIT FUNCTION

      CASE %WM_PAINT
         ' // Draws the button
         hDc = BeginPaint(hwnd, pPaint)
         SelectObject hDC, @pbxp.hFont
         UxDrawPushButton hwnd, hDc
         EndPaint hwnd, pPaint
         EXIT FUNCTION

      CASE %WM_COMMAND, %WM_NOTIFY
         ' // Forwards the message to the parent window
         SendMessage GetParent(hwnd), wMsg, wParam, lParam

      CASE %WM_ENABLE
         ' // Redraws the button
         InvalidateRect hwnd, BYVAL %NULL, 0
         UpdateWindow hwnd
         EXIT FUNCTION

      CASE %WM_SETFONT
         ' // Stores the font handle and redraws the button
         IF wParam THEN
            @pbxp.hFont = wParam
            IF lParam  AND IsWindowVisible(hwnd) THEN
               InvalidateRect hwnd, BYVAL %NULL, 0
               UpdateWindow hwnd
            END IF
         END IF

      CASE %WM_SETCURSOR
         ' // Establishes the cursor shape.
         IF @pbxp.hCursor THEN
            SetCursor @pbxp.hCursor
            FUNCTION = %TRUE
            EXIT FUNCTION
         END IF

      CASE %WM_SETFOCUS
         ' // Redraws the button
         InvalidateRect hwnd, BYVAL %NULL, 0
         UpdateWindow hwnd
         EXIT FUNCTION

      CASE %WM_KILLFOCUS
         ' // Redraws the button
         InvalidateRect hwnd, BYVAL %NULL, 0
         UpdateWindow hwnd
         EXIT FUNCTION

      CASE %WM_GETDLGCODE
         IF lParam = 0 THEN
            ' // Enables mnemonics
            FUNCTION = %DLGC_BUTTON OR %DLGC_UNDEFPUSHBUTTON
            EXIT FUNCTION
         ELSE
            ' // We want to handle the return key
            pMsg = lParam
            IF pMsg > 0 THEN
               dwMsg = @pMsg.Message
               IF dwMsg = %WM_KEYDOWN OR dwMsg = %WM_CHAR THEN
                  IF @pMsg.wParam = %VK_RETURN THEN
                     FUNCTION = %DLGC_WANTALLKEYS
                     EXIT FUNCTION
                  END IF
               END IF
            END IF
         END IF
         EXIT FUNCTION

      CASE %WM_LBUTTONDBLCLK
        ' // Forwards this message for rapid button clicking...
        SendMessage hwnd, %WM_LBUTTONDOWN, wParam, lParam
        EXIT FUNCTION

      CASE %WM_LBUTTONDOWN
         ' // If left button pressed, redraws the button in pushed state
         GetWindowRect hwnd, rc
         GetCursorPos pt
         IF PtInRect(rc, pt) THEN
            @pbxp.bClkDown = %TRUE
            IF @pbxp.bToggled = %FALSE THEN
               @pbxp.bToggled = %TRUE
            ELSE
               @pbxp.bToggled = %FALSE
            END IF
            @pbxp.fState = %BST_PUSHED
            SetCapture hwnd
            IF GetFocus <> hwnd THEN SetFocus hwnd
            InvalidateRect hwnd, BYVAL %NULL, 0
            UpdateWindow hwnd
         END IF
         EXIT FUNCTION

      CASE %WM_LBUTTONUP
         ' // Redraws the button in normal state
         ReleaseCapture
         GetWindowRect hwnd, rc
         GetCursorPos pt
         @pbxp.fState = 0
         InvalidateRect hwnd, BYVAL %NULL, 0
         UpdateWindow hwnd
         ' // Forwards the message to the parent window
         IF IsWindowEnabled(hwnd) THEN
            IF PtInRect(rc, pt) THEN
               IF @pbxp.bClkDown THEN SendMessage GetParent(hwnd), %WM_COMMAND, MAKLNG(GetDlgCtrlId(hwnd), %BN_CLICKED), hwnd
            END IF
         END IF
         @pbxp.bClkDown = %FALSE
         EXIT FUNCTION

      CASE %WM_KEYDOWN
         SELECT CASE wParam
            CASE %VK_RETURN, %VK_SPACE
               ' // Toggles the togle flag
               IF @pbxp.bToggled = %FALSE THEN
                  @pbxp.bToggled = %TRUE
               ELSE
                  @pbxp.bToggled = %FALSE
               END IF
               ' // Redraws the button in pushed state
               @pbxp.fState = %BST_PUSHED
               InvalidateRect hwnd, BYVAL %NULL, 0
               UpdateWindow hwnd
         END SELECT
         EXIT FUNCTION

      CASE %WM_KEYUP
         ' // Redraws the button in normal state
         IF @pbxp.fState = %BST_PUSHED THEN
            @pbxp.fState = 0
            InvalidateRect hwnd, BYVAL %NULL, 0
            UpdateWindow hwnd
            ' // Forwards the message to the parent window
            IF IsWindowEnabled(hwnd) THEN
               SendMessage GetParent(hwnd), %WM_COMMAND, MAKLNG(GetDlgCtrlId(hwnd), %BN_CLICKED), hwnd
            END IF
         END IF
         EXIT FUNCTION

      CASE %WM_MOUSEMOVE
         ' // Tracks the mouse movement and stores the hot state
         IF GetProp(hwnd, "HOT") = 0 THEN
            trackMouse.cbSize = SIZEOF(trackMouse)
            trackMouse.dwFlags = %TME_LEAVE
            trackMouse.hwndTrack = hwnd
            trackMouse.dwHoverTime = 1
            TrackMouseEvent(trackMouse)
            SetProp hwnd, "HOT", %TRUE
            InvalidateRect hwnd, BYVAL %NULL, 0
            UpdateWindow hwnd
         END IF
         EXIT FUNCTION

      CASE %WM_MOUSELEAVE
         ' // Removes the hot state and redraws the button
         RemoveProp hwnd, "HOT"
         InvalidateRect hwnd, BYVAL %NULL, 0
         UpdateWindow hwnd
         EXIT FUNCTION

   END SELECT

   ' Default processing for other messages.
   FUNCTION = DefWindowProc(hwnd, wMsg, wParam, lParam)

END FUNCTION
' ========================================================================================

' ========================================================================================
'                                    P R O P E R T I E S
' ========================================================================================

' ========================================================================================
' Sets the image for the button
' Parameters:
' * hwnd = Button's window handle
' * hImage = Image's handle
' * ImageType = IMAGE_ICON or IMAGE_BITMAP
' * ImageState =
'      XPBI_NORMAL = 1
'      XPBI_HOT = 2
'      XPBI_DISABLED = 3
' * fRedraw = TRUE or FALSE (redraws the button to reflect the changes)
' * fDontOwn [optional] = If FALSE, the image is destroyed by the control; if TRUE, the
'   caller is responsible to destroy it using the returned handle.
' Return value:
' * Returns the handle of the previous image, if any.
' ========================================================================================
FUNCTION XPButton_SetImage (BYVAL hwnd AS DWORD, BYVAL hImage AS DWORD, BYVAL ImageType AS LONG, BYVAL ImageState AS LONG, BYVAL fRedraw AS LONG, OPTIONAL BYVAL fDontOwn AS LONG) AS DWORD

   LOCAL pbxp AS XPBUTTONDATA PTR    ' // Pointer to the button data

   ' // Checks the validity of the parameters
   IF hwnd = 0 THEN EXIT FUNCTION
   IF hImage = 0 THEN EXIT FUNCTION
   IF ImageType <> %IMAGE_ICON AND ImageType <> %IMAGE_BITMAP THEN EXIT FUNCTION
   IF ImageState <> %XPBI_NORMAL AND ImageState <> %XPBI_HOT AND ImageState <> %XPBI_DISABLED THEN EXIT FUNCTION
   ' // Gets a pointer to the button data
   pbxp = GetWindowLong(hwnd, 0)
   IF pbxp = 0 THEN EXIT FUNCTION
   ' // Returns the old image handle
   SELECT CASE ImageState
      CASE %XPBI_NORMAL
         FUNCTION = @pbxp.hImage
      CASE %XPBI_HOT
         FUNCTION = @pbxp.hHotImage
      CASE %XPBI_DISABLED
         FUNCTION = @pbxp.hDisabledImage
   END SELECT
   ' // Destroys the old image, if any, if it was owned by the control
   SELECT CASE ImageState
      CASE %XPBI_NORMAL
         IF @pbxp.fOwnImage THEN
            IF @pbxp.hImage THEN DeleteObject @pbxp.hImage
         END IF
      CASE %XPBI_HOT
         IF @pbxp.fOwnHotImage THEN
            IF @pbxp.hHotImage THEN DeleteObject @pbxp.hHotImage
         END IF
      CASE %XPBI_DISABLED
         IF @pbxp.fOwnImage THEN
            IF @pbxp.hDisabledImage THEN DeleteObject @pbxp.hDisabledImage
         END IF
   END SELECT
   ' // Store the new values
   SELECT CASE ImageState
      CASE %XPBI_NORMAL
         @pbxp.hImage = hImage
         IF fDontOwn THEN
            @pbxp.fOwnImage = %FALSE
         ELSE
            @pbxp.fOwnImage = %TRUE
         END IF
      CASE %XPBI_HOT
         @pbxp.hHotImage = hImage
         IF fDontOwn THEN
            @pbxp.fOwnHotImage = %FALSE
         ELSE
            @pbxp.fOwnHotImage = %TRUE
         END IF
      CASE %XPBI_DISABLED
         @pbxp.hDisabledImage = hImage
         IF fDontOwn THEN
            @pbxp.fOwnDisabledImage = %FALSE
         ELSE
            @pbxp.fOwnDisabledImage = %TRUE
         END IF
   END SELECT
   ' // Image type
   @pbxp.ImageType = ImageType
   ' // Default width and height
   @pbxp.ImageWidth = 16
   @pbxp.ImageHeight = 16
   ' // Redraws the button
   IF fRedraw THEN
      InvalidateRect hwnd, BYVAL %NULL, 0
      UpdateWindow hwnd
   END IF

END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the icon for the button
' Parameters:
' * hwnd = Button's window handle
' * hIcon = Icon's handle
' * ImageState =
'      XPBI_NORMAL = 1
'      XPBI_HOT = 2
'      XPBI_DISABLED = 3
' Return value:
' * Returns the handle of the previous image, if any.
' ========================================================================================
FUNCTION XPButton_SetIcon (BYVAL hwnd AS DWORD, BYVAL hIcon AS DWORD, BYVAL ImageState AS LONG, BYVAL fRedraw AS LONG) AS DWORD
   FUNCTION = XPButton_SetImage(hwnd, hIcon, %IMAGE_ICON, ImageState, fRedraw, %TRUE)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the bitmap for the button
' Parameters:
' * hwnd = Button's window handle
' * hBitmap = Bitmap's handle
' * ImageState =
'      XPBI_NORMAL = 1
'      XPBI_HOT = 2
'      XPBI_DISABLED = 3
' * fDontOwn [optional] = If FALSE, the bitmap is destroyed by the control; if TRUE, the
'   caller is responsible to destroy it using the returned handle.
' Return value:
' * Returns the handle of the previous image, if any.
' ========================================================================================
FUNCTION XPButton_SetBitmap (BYVAL hwnd AS DWORD, BYVAL hBitmap AS DWORD, BYVAL ImageState AS LONG, BYVAL fRedraw AS LONG, OPTIONAL BYVAL fDontOwn AS LONG) AS DWORD
   FUNCTION = XPButton_SetImage(hwnd, hBitmap, %IMAGE_BITMAP, ImageState, fRedraw, fDontOwn)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Loads an icon from file and sets it as the image of tbe button.
' Parameters:
' * hwnd = Button's window handle
' * strPath = Full path of the icon's file.
' * fDontOwn [optional] = If FALSE the icon is destroyed by the control; if TRUE, the
'   caller is responsible to destroy it using the returned handle.
' Return value:
' * Returns the handle of the previous icon, if any.
' ========================================================================================
FUNCTION XPButton_SetIconFromFile (BYVAL hwnd AS DWORD, BYVAL strPath AS STRING, BYVAL ImageState AS LONG, BYVAL fRedraw AS LONG) AS DWORD
   LOCAL hIcon AS DWORD
   hIcon = LoadImage(%NULL, BYCOPY strPath, %IMAGE_ICON, 0, 0, %LR_LOADFROMFILE)
   FUNCTION = XPButton_SetImage(hwnd, hIcon, %IMAGE_ICON, ImageState, fRedraw, %TRUE)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Loads a bitmap from file and sets it as the image of tbe button.
' Parameters:
' * hwnd = Button's window handle
' * strPath = Full path of the bitmap file.
' * fDontOwn [optional] = If FALSE, the bitmap is destroyed by the control; if TRUE, the
'   caller is responsible to destroy it using the returned handle.
' Return value:
' * Returns the handle of the previous icon, if any.
' ========================================================================================
FUNCTION XPButton_SetBitmapFromFile (BYVAL hwnd AS DWORD, BYVAL strPath AS STRING, BYVAL ImageState AS LONG, BYVAL fRedraw AS LONG, OPTIONAL BYVAL fDontOwn AS LONG) AS DWORD
   LOCAL hBitmap AS DWORD
   hBitmap = LoadImage(%NULL, BYCOPY strPath, %IMAGE_BITMAP, 0, 0, %LR_LOADFROMFILE)
   FUNCTION = XPButton_SetImage(hwnd, hBitmap, %IMAGE_BITMAP, ImageState, fRedraw, fDontOwn)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the handle of the image
' Parameters:
' * hwnd = Button's window handle
' * ImageState =
'      XPBI_NORMAL = 1
'      XPBI_HOT = 2
'      XPBI_DISABLED = 3
' ========================================================================================
FUNCTION XPButton_GetImage (BYVAL hwnd AS DWORD, BYVAL ImageState AS LONG) AS DWORD
   LOCAL pbxp AS XPBUTTONDATA PTR    ' // Pointer to the button data
   IF hwnd = 0 THEN EXIT FUNCTION
   pbxp = GetWindowLong(hwnd, 0)
   IF pbxp = 0 THEN EXIT FUNCTION
   SELECT CASE ImageState
      CASE %XPBI_NORMAL
         FUNCTION = @pbxp.hImage
      CASE %XPBI_HOT
         FUNCTION = @pbxp.hHotImage
      CASE %XPBI_DISABLED
         FUNCTION = @pbxp.hDisabledImage
   END SELECT
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the size of the image
' Parameters:
' * hwnd = Button's window handle
' * nWidth = Width of the image, in pixels.
' * nHeight = Height of the image, in pixels.
' * fRedraw = TRUE or FALSE (redraws the button to reflect the changes)
' Return value:
' * Boolean. TRUE or FALSE.
' ========================================================================================
FUNCTION XPButton_SetImageSize (BYVAL hwnd AS DWORD, BYVAL nWidth AS LONG, BYVAL nHeight AS LONG, BYVAL fRedraw AS LONG) AS LONG

   LOCAL pbxp AS XPBUTTONDATA PTR    ' // Pointer to the button data

   IF hwnd = 0 THEN EXIT FUNCTION
   pbxp = GetWindowLong(hwnd, 0)
   IF pbxp = 0 THEN EXIT FUNCTION
   @pbxp.ImageWidth = nWidth
   @pbxp.ImageHeight = nHeight
   ' // Redraws the button
   IF fRedraw THEN
      InvalidateRect hwnd, BYVAL %NULL, 0
      UpdateWindow hwnd
   END IF
   FUNCTION = %TRUE

END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the width of the image.
' Parameters:
' * hwnd = Button's window handle
' * nWidth = Width of the image, in pixels.
' * fRedraw = TRUE or FALSE (redraws the button to reflect the changes)
' Return value:
' * Returns the previous width, if any.
' ========================================================================================
FUNCTION XPButton_SetImageWidth (BYVAL hwnd AS DWORD, BYVAL nWidth AS LONG, BYVAL fRedraw AS LONG) AS LONG

   LOCAL pbxp AS XPBUTTONDATA PTR    ' // Pointer to the button data

   IF hwnd = 0 THEN EXIT FUNCTION
   pbxp = GetWindowLong(hwnd, 0)
   IF pbxp = 0 THEN EXIT FUNCTION
   FUNCTION = @pbxp.ImageWidth
   @pbxp.ImageWidth = nWidth
   ' // Redraws the button
   IF fRedraw THEN
      InvalidateRect hwnd, BYVAL %NULL, 0
      UpdateWindow hwnd
   END IF

END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the width of the image.
' Parameters:
' * hwnd = Button's window handle
' ========================================================================================
FUNCTION XPButton_GetImageWidth (BYVAL hwnd AS DWORD) AS LONG

   LOCAL pbxp AS XPBUTTONDATA PTR    ' // Pointer to the button data

   IF hwnd = 0 THEN EXIT FUNCTION
   pbxp = GetWindowLong(hwnd, 0)
   IF pbxp = 0 THEN EXIT FUNCTION
   FUNCTION = @pbxp.ImageWidth

END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the height of the image.
' Parameters:
' * hwnd = Button's window handle
' * nHeight = Height of the image, in pixels.
' * fRedraw = TRUE or FALSE (redraws the button to reflect the changes)
' Return value:
' * Returns the previous height, if any.
' ========================================================================================
FUNCTION XPButton_SetImageHeight (BYVAL hwnd AS DWORD, BYVAL nHeight AS LONG, BYVAL fRedraw AS LONG) AS LONG

   LOCAL pbxp AS XPBUTTONDATA PTR    ' // Pointer to the button data

   IF hwnd = 0 THEN EXIT FUNCTION
   pbxp = GetWindowLong(hwnd, 0)
   IF pbxp = 0 THEN EXIT FUNCTION
   FUNCTION = @pbxp.ImageHeight
   @pbxp.ImageHeight = nHeight
   ' // Redraws the button
   IF fRedraw THEN
      InvalidateRect hwnd, BYVAL %NULL, 0
      UpdateWindow hwnd
   END IF

END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the height of the image.
' Parameters:
' * hwnd = Button's window handle
' ========================================================================================
FUNCTION XPButton_GetImageHeight (BYVAL hwnd AS DWORD) AS LONG

   LOCAL pbxp AS XPBUTTONDATA PTR    ' // Pointer to the button data

   IF hwnd = 0 THEN EXIT FUNCTION
   pbxp = GetWindowLong(hwnd, 0)
   IF pbxp = 0 THEN EXIT FUNCTION
   FUNCTION = @pbxp.ImageHeight

END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the position of the image
' Parameters:
' * hwnd = Button's window handle
' * nPos = Position.
'     %XPBI_NONE = &H0                                          ' // No image
'     %XPBI_LEFT = &H1                                          ' // Left (default)
'     %XPBI_RIGHT = &H2                                         ' // Right
'     %XPBI_CENTER = &H4                                        ' // Center
'     %XPBI_VCENTER = &H8                                       ' // Vertically centered
'     %XPBI_TOP = &H10                                          ' // Top
'     %XPBI_BOTTOM = &H20                                       ' // Bottom
'     %XPBI_ABOVE = %XPBI_TOP OR %XPBI_CENTER             ' // Above the text
'     %XPBI_BELOW = %XPBI_BOTTOM OR %XPBI_CENTER          ' // Below the text
'     %XPBI_CENTERCENTER = %XPBI_CENTER OR %XPBI_VCENTER  ' // Center-center (no text)
' * fRedraw = TRUE or FALSE (redraws the button to reflect the changes)
' Return value:
' * Returns the previous position, if any.
' ========================================================================================
FUNCTION XPButton_SetImagePos (BYVAL hwnd AS DWORD, BYVAL nPos AS LONG, BYVAL fRedraw AS LONG) AS LONG

   LOCAL pbxp AS XPBUTTONDATA PTR    ' // Pointer to the button data

   IF hwnd = 0 THEN EXIT FUNCTION
   pbxp = GetWindowLong(hwnd, 0)
   IF pbxp = 0 THEN EXIT FUNCTION
   FUNCTION = @pbxp.ImagePos
   @pbxp.ImagePos = nPos
   ' // Redraws the button
   IF fRedraw THEN
      InvalidateRect hwnd, BYVAL %NULL, 0
      UpdateWindow hwnd
   END IF

END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the position of the image.
' Parameters:
' * hwnd = Button's window handle
' ========================================================================================
FUNCTION XPButton_GetImagePos (BYVAL hwnd AS DWORD) AS LONG

   LOCAL pbxp AS XPBUTTONDATA PTR    ' // Pointer to the button data

   IF hwnd = 0 THEN EXIT FUNCTION
   pbxp = GetWindowLong(hwnd, 0)
   IF pbxp = 0 THEN EXIT FUNCTION
   FUNCTION = @pbxp.ImagePos

END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the font for the button
' Parameters:
' * hwnd = Button's window handle
' * hFont = Font handle
' * fRedraw = TRUE or FALSE (redraws the button to reflect the changes)
' * fDontOwn [optional] = If FALSE, the font is destroyed by the control; if TRUE, the
'   caller is responsible to destroy it using the returned handle.
' Return value:
' * Returns the handle of the previous font, if any.
' ========================================================================================
FUNCTION XPButton_SetFont (BYVAL hwnd AS DWORD, BYVAL hFont AS DWORD, BYVAL fRedraw AS LONG, OPTIONAL BYVAL fDontOwn AS LONG) AS DWORD

   LOCAL pbxp AS XPBUTTONDATA PTR    ' // Pointer to the button data

   ' // Check the validity of the parameters
   IF hwnd = 0 THEN EXIT FUNCTION
   IF hFont = 0 THEN EXIT FUNCTION
   ' // Gets a pointer to the button data
   pbxp = GetWindowLong(hwnd, 0)
   IF pbxp = 0 THEN EXIT FUNCTION
   ' // Return the old font handle
   FUNCTION = @pbxp.hFont
   ' // Destroys the old font, if any, if it was owned by the control
   IF @pbxp.fOwnFont THEN
      IF @pbxp.hFont THEN DeleteObject @pbxp.hFont
   END IF
   ' // Store the new values
   @pbxp.hFont = hFont
   IF fDontOwn THEN
      @pbxp.fOwnFont = %FALSE
   ELSE
      @pbxp.fOwnFont = %TRUE
   END IF
   ' // Redraws the button
   IF fRedraw THEN
      InvalidateRect hwnd, BYVAL %NULL, 0
      UpdateWindow hwnd
   END IF

END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the font handle
' Parameters:
' * hwnd = Button's window handle
' ========================================================================================
FUNCTION XPButton_GetFont (BYVAL hwnd AS DWORD) AS DWORD

   LOCAL pbxp AS XPBUTTONDATA PTR    ' // Pointer to the button data

   IF hwnd = 0 THEN EXIT FUNCTION
   pbxp = GetWindowLong(hwnd, 0)
   IF pbxp = 0 THEN EXIT FUNCTION
   FUNCTION = @pbxp.hFont

END FUNCTION
' ========================================================================================

' ========================================================================================
' Redraws the button
' Parameters:
' * hwnd = Button's window handle
' Return value:
' * No return value.
' ========================================================================================
SUB XPButton_Redraw (BYVAL hwnd AS DWORD)
   IF hwnd = 0 THEN EXIT SUB
   InvalidateRect hwnd, BYVAL %NULL, 0
   UpdateWindow hwnd
END SUB
' ========================================================================================

' ========================================================================================
' Sets the text format
' Parameters:
' * hwnd = Button's window handle
' * dwTextFlags = Format values (default DT_CENTER OR DT_VCENTER OR DT_SINGLELINE)
'   - DT_BOTTOM = Renders the text string at the bottom of the display rectangle.
'     This value is used only with the DT_SINGLELINE value.
'   - DT_CALCRECT = Determines the width and height of the display rectangle.
'   - DT_CENTER = Centers text horizontally in the display rectangle.
'   - DT_EDITCONTRO = Duplicates the text-displaying characteristics of a multiline edit
'     control. Specifically, the average character width is calculated in the same manner
'     as for an edit control, and the function does not display a partially visible last
'     line.
'   - DT_END_ELLIPSIS = Truncates a text string that is wider than the display rectangle
'     and adds an ellipsis to indicate the truncation. The string is not modified unless
'     the DT_MODIFYSTRING flag is specified.
'   - DT_EXPANDTABS = Expands tab characters. The default number of characters per tab
'     is eight. The DT_WORD_ELLIPSIS, DT_PATH_ELLIPSIS, and DT_END_ELLIPSIS values cannot
'     be used with the DT_EXPANDTABS value.
'   - DT_EXTERNALLEADING = Includes the external leading of a font in the line height.
'     Normally, external leading is not included in the height of a line of text.
'   - DT_HIDEPREFIX = Ignores the prefix character & in the text. The letter that follows
'     is not underlined, but other prefix characters are still processed. For example:
'        input string: "A&bc&&d"
'        normal: "Abc&d"
'        DT_HIDEPREFIX: "Abc&d"
'   - DT_LEFT = Aligns text to the left.
'   - DT_MODIFYSTRING = Modifies a string to match the displayed text. This value has
'     no effect unless DT_END_ELLIPSIS or DT_PATH_ELLIPSIS is specified.
'   - DT_NOCLIP = Draws the text string without clipping the display rectangle.
'   - DT_NOFULLWIDTHCHARBREAK = Prevents a line break at a double-byte character set
'     (DBCS), so that the line-breaking rule is equivalent to single-byte character set
'     (SBCS). This can be used, for example, to make icon labels written in Korean text
'     more readable. This value has no effect unless DT_WORDBREAK is specified.
'   - DT_NOPREFIX = Turns off processing of prefix characters. Normally, DrawThemeText
'     interprets the prefix character & as a directive to underscore the character that
'     follows, and the prefix characters && as a directive to print a single &. By
'     specifying DT_NOPREFIX, this processing is turned off. For example:
'        input string: "A&bc&&d"
'        normal: "Abc&d"
'        DT_NOPREFIX: "A&bc&&d"
'   - DT_PATH_ELLIPSIS = Replaces characters in the middle of text with an ellipsis so
'     that the result fits in the display rectangle. If the string contains backslash (\)
'     characters, DT_PATH_ELLIPSIS preserves as much as possible of the text after the
'     last backslash. The string is not modified unless the DT_MODIFYSTRING flag is
'     specified.
'   - DT_PREFIXONLY = Draws only an underline at the position of the character following
'     the prefix character &. Normally DrawThemeText interprets the & as a directive to
'     underline the character that follows and the prefix characters && as a directive to
'     print a single &. By specifying DT_PREFIXONLY, no characters are drawn, only an
'     underline. White spaces are placed in the positions where characters would normally
'     appear. For example:
'        input string: "A&bc&&d"
'        normal: "Abc&d"
'        DT_PREFIXONLY: " _   "
'   - DT_RIGHT = Aligns text to the right.
'   - DT_RTLREADING = Lays out text in right-to-left order for bidirectional text, for
'     example, text in a Hebrew or Arabic font. The default direction for text is
'     left-to-right.
'   - DT_SINGLELINE = Displays text on a single line. Carriage returns and line feeds do
'     not break the line.
'   - DT_TABSTOPS = Sets tab stops.
'   - DT_TOP = Renders the text at the top of the display rectangle.
'   - DT_VCENTER = Centers text vertically. This value is used only with the DT_SINGLELINE
'     value.
'   - DT_WORDBREAK = Breaks lines between words if a word would extend past the edge of
'     the display rectangle. A carriage return/line feed (CR/LF) sequence also breaks the
'     line.
'   - DT_WORD_ELLIPSIS = Truncates any word that does not fit in the display rectangle
'     and adds an ellipsis.
' * fRedraw = TRUE or FALSE (redraws the button to reflect the changes)
' Return value:
' * Returns the previous value, if any.
' ========================================================================================
FUNCTION XPButton_SetTextFormat (BYVAL hwnd AS DWORD, BYVAL dwTextFlags AS DWORD, BYVAL fRedraw AS LONG) AS DWORD

   LOCAL pbxp AS XPBUTTONDATA PTR    ' // Pointer to the button data

   IF hwnd = 0 THEN EXIT FUNCTION
   pbxp = GetWindowLong(hwnd, 0)
   IF pbxp = 0 THEN EXIT FUNCTION
   FUNCTION = @pbxp.dwTextFlags
   @pbxp.dwTextFlags = dwTextFlags
   ' // Redraws the button
   IF fRedraw THEN
      InvalidateRect hwnd, BYVAL %NULL, 0
      UpdateWindow hwnd
   END IF

END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the text format
' Parameters:
' * hwnd = Button's window handle
' ========================================================================================
FUNCTION XPButton_GetTextFormat (BYVAL hwnd AS DWORD) AS DWORD

   LOCAL pbxp AS XPBUTTONDATA PTR    ' // Pointer to the button data

   IF hwnd = 0 THEN EXIT FUNCTION
   pbxp = GetWindowLong(hwnd, 0)
   IF pbxp = 0 THEN EXIT FUNCTION
   FUNCTION = @pbxp.dwTextFlags

END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the image margin
' Parameters:
' * hwnd = Button's window handle
' * nMargin = Margin (in pixels)
' * fRedraw = TRUE or FALSE (redraws the button to reflect the changes)
' Return value:
' * Returns the previous margin, if any.
' ========================================================================================
FUNCTION XPButton_SetImageMargin (BYVAL hwnd AS DWORD, BYVAL nMargin AS LONG, BYVAL fRedraw AS LONG) AS LONG

   LOCAL pbxp AS XPBUTTONDATA PTR    ' // Pointer to the button data

   IF hwnd = 0 THEN EXIT FUNCTION
   pbxp = GetWindowLong(hwnd, 0)
   IF pbxp = 0 THEN EXIT FUNCTION
   FUNCTION = @pbxp.ImageMargin
   @pbxp.ImageMargin = nMargin
   ' // Redraws the button
   IF fRedraw THEN
      InvalidateRect hwnd, BYVAL %NULL, 0
      UpdateWindow hwnd
   END IF

END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the image margin
' Parameters:
' * hwnd = Button's window handle
' ========================================================================================
FUNCTION XPButton_GetImageMargin (BYVAL hwnd AS DWORD) AS LONG

   LOCAL pbxp AS XPBUTTONDATA PTR    ' // Pointer to the button data

   IF hwnd = 0 THEN EXIT FUNCTION
   pbxp = GetWindowLong(hwnd, 0)
   IF pbxp = 0 THEN EXIT FUNCTION
   FUNCTION = @pbxp.ImageMargin

END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the text margin
' Parameters:
' * hwnd = Button's window handle
' * nMargin = Margin (in pixels)
' * fRedraw = TRUE or FALSE (redraws the button to reflect the changes)
' Return value:
' * Returns the previous margin, if any.
' ========================================================================================
FUNCTION XPButton_SetTextMargin (BYVAL hwnd AS DWORD, BYVAL nMargin AS LONG, BYVAL fRedraw AS LONG) AS LONG

   LOCAL pbxp AS XPBUTTONDATA PTR    ' // Pointer to the button data

   IF hwnd = 0 THEN EXIT FUNCTION
   pbxp = GetWindowLong(hwnd, 0)
   IF pbxp = 0 THEN EXIT FUNCTION
   FUNCTION = @pbxp.TextMargin
   @pbxp.textMargin = nMargin
   ' // Redraws the button
   IF fRedraw THEN
      InvalidateRect hwnd, BYVAL %NULL, 0
      UpdateWindow hwnd
   END IF

END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the text margin
' Parameters:
' * hwnd = Button's window handle
' ========================================================================================
FUNCTION XPButton_GetTextMargin (BYVAL hwnd AS DWORD) AS LONG

   LOCAL pbxp AS XPBUTTONDATA PTR    ' // Pointer to the button data

   IF hwnd = 0 THEN EXIT FUNCTION
   pbxp = GetWindowLong(hwnd, 0)
   IF pbxp = 0 THEN EXIT FUNCTION
   FUNCTION = @pbxp.TextMargin

END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the button state
' Parameters:
' * hwnd = Button's window handle
' ========================================================================================
FUNCTION XPButton_GetButtonState (BYVAL hwnd AS DWORD) AS LONG

   LOCAL pbxp AS XPBUTTONDATA PTR    ' // Pointer to the button data

   IF hwnd = 0 THEN EXIT FUNCTION
   pbxp = GetWindowLong(hwnd, 0)
   IF pbxp = 0 THEN EXIT FUNCTION
   FUNCTION = @pbxp.fState

END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the image type
' Parameters:
' * hwnd = Button's window handle
' ========================================================================================
FUNCTION XPButton_GetImageType (BYVAL hwnd AS DWORD) AS LONG

   LOCAL pbxp AS XPBUTTONDATA PTR    ' // Pointer to the button data

   IF hwnd = 0 THEN EXIT FUNCTION
   pbxp = GetWindowLong(hwnd, 0)
   IF pbxp = 0 THEN EXIT FUNCTION
   FUNCTION = @pbxp.ImageType

END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets button to toggle state (TRUE) or to pushbutton state (FALSE)
' Parameters:
' * hwnd = Button's window handle
' * fToggle = Toggle state (TRUE or FALSE)
' * fRedraw = TRUE or FALSE (redraws the button to reflect the changes)
' Return value:
' * No retuern value.
' ========================================================================================
SUB XPButton_SetToggle (BYVAL hwnd AS DWORD, BYVAL fToggle AS LONG, BYVAL fRedraw AS LONG)

   LOCAL pbxp AS XPBUTTONDATA PTR    ' // Pointer to the button data

   IF hwnd = 0 THEN EXIT SUB
   pbxp = GetWindowLong(hwnd, 0)
   IF pbxp = 0 THEN EXIT SUB
   IF fToggle <> 0 THEN fToggle = %TRUE
   @pbxp.bIsToggle = fToggle
   ' // Redraws the button
   IF fRedraw THEN
      InvalidateRect hwnd, BYVAL %NULL, 0
      UpdateWindow hwnd
   END IF

END SUB
' ========================================================================================

' ========================================================================================
' Gets button toggle state
' Parameters:
' * hwnd = Button's window handle
' ========================================================================================
FUNCTION XPButton_GetToggle (BYVAL hwnd AS DWORD) AS LONG

   LOCAL pbxp AS XPBUTTONDATA PTR    ' // Pointer to the button data

   IF hwnd = 0 THEN EXIT FUNCTION
   pbxp = GetWindowLong(hwnd, 0)
   IF pbxp = 0 THEN EXIT FUNCTION
   FUNCTION = @pbxp.bIsToggle

END FUNCTION
' ========================================================================================

' ========================================================================================
' Set toggle state to pushed (TRUE) or unpushed (FALSE)
' Parameters:
' * hwnd = Button's window handle
' * fState = Toggled state (TRUE or FALSE)
' * fRedraw = TRUE or FALSE (redraws the button to reflect the changes)
' Return value:
' * No retuern value.
' ========================================================================================
SUB XPButton_SetToggleState (BYVAL hwnd AS DWORD, BYVAL fState AS LONG, BYVAL fRedraw AS LONG)

   LOCAL pbxp AS XPBUTTONDATA PTR    ' // Pointer to the button data

   IF hwnd = 0 THEN EXIT SUB
   pbxp = GetWindowLong(hwnd, 0)
   IF pbxp = 0 THEN EXIT SUB
   IF fState <> 0 THEN fState = -1
   @pbxp.bToggled = fState
   ' // Redraws the button
   IF fRedraw THEN
      InvalidateRect hwnd, BYVAL %NULL, 0
      UpdateWindow hwnd
   END IF

END SUB
' ========================================================================================

' ========================================================================================
' Returns TRUE if button is toggled (down) or FALSE otherwise
' Parameters:
' * hwnd = Button's window handle
' ========================================================================================
FUNCTION XPButton_GetToggleState (BYVAL hwnd AS DWORD) AS LONG

   LOCAL pbxp AS XPBUTTONDATA PTR    ' // Pointer to the button data

   IF hwnd = 0 THEN EXIT FUNCTION
   pbxp = GetWindowLong(hwnd, 0)
   IF pbxp = 0 THEN EXIT FUNCTION
   IF @pbxp.bToggled THEN FUNCTION = %TRUE

END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the cursor for the button
' Parameters:
' * hwnd = Button's window handle
' * hCursor = Cursor handle
' Return value:
' * Returns the handle of the previous cursor.
' ========================================================================================
FUNCTION XPButton_SetCursor (BYVAL hwnd AS DWORD, BYVAL hCursor AS DWORD) AS DWORD

   LOCAL pbxp AS XPBUTTONDATA PTR    ' // Pointer to the button data

   ' // Check the validity of the parameters
   IF hwnd = 0 THEN EXIT FUNCTION
   IF hCursor = 0 THEN EXIT FUNCTION
   ' // Gets a pointer to the button data
   pbxp = GetWindowLong(hwnd, 0)
   IF pbxp = 0 THEN EXIT FUNCTION
   ' // Return the old cursor handle
   FUNCTION = @pbxp.hCursor
   ' // Store the new handle
   @pbxp.hCursor = hCursor

END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the cursor handle
' Parameters:
' * hwnd = Button's window handle
' ========================================================================================
FUNCTION XPButton_GetCursor (BYVAL hwnd AS DWORD) AS DWORD

   LOCAL pbxp AS XPBUTTONDATA PTR    ' // Pointer to the button data

   IF hwnd = 0 THEN EXIT FUNCTION
   pbxp = GetWindowLong(hwnd, 0)
   IF pbxp = 0 THEN EXIT FUNCTION
   FUNCTION = @pbxp.hCursor

END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns TRUE if themes are enabled or FALSE otherwise
' Parameters:
' * hwnd = Button's window handle
' ========================================================================================
FUNCTION XPButton_IsThemed (BYVAL hwnd AS DWORD) AS LONG

   LOCAL pbxp AS XPBUTTONDATA PTR    ' // Pointer to the button data

   IF hwnd = 0 THEN EXIT FUNCTION
   pbxp = GetWindowLong(hwnd, 0)
   IF pbxp = 0 THEN EXIT FUNCTION
   FUNCTION = @pbxp.bIsThemed

END FUNCTION
' ========================================================================================

' ========================================================================================
' Enables theming
' Parameters:
' * hwnd = Button's window handle
' Return value:
' * Returns TRUE or FALSE
' ========================================================================================
FUNCTION XPButton_EnableTheming (BYVAL hwnd AS DWORD) AS LONG

   LOCAL pbxp AS XPBUTTONDATA PTR    ' // Pointer to the button data

   ' // Check the validity of the parameters
   IF hwnd = 0 THEN EXIT FUNCTION
   ' // Gets a pointer to the button data
   pbxp = GetWindowLong(hwnd, 0)
   IF pbxp = 0 THEN EXIT FUNCTION
   ' // Store the new state
   @pbxp.bIsThemed = %TRUE
   ' // Redraws the button
   InvalidateRect hwnd, BYVAL %NULL, 0
   UpdateWindow hwnd
   ' // Return success
   FUNCTION = %TRUE

END FUNCTION
' ========================================================================================

' ========================================================================================
' Disables theming
' Parameters:
' * hwnd = Button's window handle
' Return value:
' * Returns TRUE or FALSE
' ========================================================================================
FUNCTION XPButton_DisableTheming (BYVAL hwnd AS DWORD) AS LONG

   LOCAL pbxp AS XPBUTTONDATA PTR    ' // Pointer to the button data

   ' // Check the validity of the parameters
   IF hwnd = 0 THEN EXIT FUNCTION
   ' // Gets a pointer to the button data
   pbxp = GetWindowLong(hwnd, 0)
   IF pbxp = 0 THEN EXIT FUNCTION
   ' // Store the new state
   @pbxp.bIsThemed = %FALSE
   ' // Redraws the button
   InvalidateRect hwnd, BYVAL %NULL, 0
   UpdateWindow hwnd
   ' // Return success
   FUNCTION = %TRUE

END FUNCTION
' ========================================================================================
