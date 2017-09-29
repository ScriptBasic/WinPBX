' ########################################################################################
' Microsoft Windows
' File: GLCtx.inc
' Contents: OpenGL Graphic Control
' Copyright (c) 2011 José Roca. All Rights Reserved.
' Freeware. Use at your own risk.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%GLCTX_INC = 1

#INCLUDE ONCE "windows.inc"
#INCLUDE ONCE "GDIPLUS.inc"
#INCLUDE ONCE "glu.inc"

%GLCTX_SETVIRTUALBUFFER = %WM_USER + 101

' // Notification messages
'%NM_CLICK           = %NM_FIRST - 2
'%NM_DBLCLK          = %NM_FIRST - 3
'%NM_RCLICK          = %NM_FIRST - 5
'%NM_RDBLCLK         = %NM_FIRST - 6
'%NM_SETFOCUS        = %NM_FIRST - 7
'%NM_KILLFOCUS       = %NM_FIRST - 8

' // Process them in the main window callback as follows:
'
' CASE %WM_NOTIFY
'    LOCAL phdr AS NMHDR PTR
'    phdr = lParam
'    IF wParam = %IDC_GLCTX THEN
'       SELECT CASE @phdr.code
'          CASE %NM_CLICK
'             ' Left button clicked
'          CASE %NM_RCLICK
'             ' Right button clicked
'          CASE %NM_SETFOCUS
'             ' The control has gained focus
'          CASE %NM_KILLFOCUS
'             ' The control has lost focus
'       END SELECT
'    END IF
' An application should return nonzero if it processes this message.

' ========================================================================================
' GLCTXDATA structure
' ========================================================================================
TYPE GLCTXDATA
   m_hMemDc      AS DWORD   ' // Memory compatible device context handle
   m_hBmp        AS DWORD   ' // Bitmap handle
   m_hOldBmp     AS DWORD   ' // Old Bitmap handle
   m_vWidth      AS DWORD   ' // Width of the virtual buffer
   m_vHeight     AS DWORD   ' // Height of the virtual buffer
   m_bkcolor     AS DWORD   ' // Background color
   m_MaxX        AS LONG    ' // Maximum horizontal range
   m_MaxY        AS LONG    ' // Maximum vertical range
   m_OrgX        AS LONG    ' // x-origin for current display
   m_OrgY        AS LONG    ' // y-origin for current display
   m_coord       AS RECT    ' // Client area
   m_token       AS DWORD   ' // Token returned by GdiplusStartup
   m_pvBits      AS DWORD   ' // Location of the DIB bit values
   m_hRC         AS DWORD   ' // Rendering context handle
   m_BitsPerPel  AS LONG    ' // Bits per pixel
   m_Stretchable AS LONG    ' // Contents are stretchable
   m_StretchMode AS LONG    ' // Stretch mode
   m_Resizable   AS DWORD   ' // Contents are resizable
END TYPE
' ========================================================================================

' ========================================================================================
' Registers the window class
' ========================================================================================
FUNCTION InitGlCtx () AS WORD

   LOCAL  wcex AS WNDCLASSEX               ' // WNDCLASSEX structure
   STATIC wAtom AS WORD                    ' // Atom
#IF %DEF(%UNICODE)
   LOCAL  szClassName AS WSTRINGZ * 256    ' // Class name
#ELSE
   LOCAL  szClassName AS ASCIIZ * 256      ' // Class name
#ENDIF

   ' // Already initialized
   IF wAtom <> 0 THEN
      FUNCTION = wAtom
      EXIT FUNCTION
   END IF

   szClassName        = "GLCTX"
   wcex.cbSize        = SIZEOF(wcex)
   wcex.style         = %CS_HREDRAW OR %CS_VREDRAW   ' OR %CS_DBLCLKS
   wcex.lpfnWndProc   = CODEPTR(GlCtxProc)
   wcex.cbClsExtra    = 0
   wcex.cbWndExtra    = 4 ' For pointer to GLCTXDATA structure
   wcex.hInstance     = GetModuleHandle(BYVAL %NULL)
   wcex.hIcon         = %NULL
   wcex.hCursor       = LoadCursor(%NULL, BYVAL %IDC_ARROW)
   wcex.hbrBackground = GetStockObject(%WHITE_BRUSH)
   wcex.lpszMenuName  = %NULL
   wcex.lpszClassName = VARPTR(szClassName)
   wcex.hIconSm       = %NULL

   wAtom = RegisterClassEx(wcex)
   FUNCTION = wAtom

END FUNCTION
' ========================================================================================

' ========================================================================================
' Control callback procedure
' ========================================================================================
FUNCTION GlCtxProc (BYVAL hwnd AS DWORD, BYVAL wMsg AS DWORD, _
                    BYVAL wParam AS DWORD, BYVAL lParam AS LONG) AS LONG

   LOCAL hStatus       AS LONG                  ' // Result code
   LOCAL pdata         AS GLCTXDATA PTR         ' // Pointer to the control's data
   LOCAL hr            AS LONG                  ' // HRESULT
   LOCAL hDc           AS DWORD                 ' // Device context handle
   LOCAL hBrush        AS DWORD                 ' // Brush handle
   LOCAL dwStyle       AS DWORD                 ' // Window style
   LOCAL ps            AS PAINTSTRUCT           ' // PAINTSTRUCT structure
   LOCAL phdr          AS NMHDR                 ' // NMHDR structure
   LOCAL nPage         AS LONG                  ' // Page size
   LOCAL Increment     AS LONG                  ' // Increment
   LOCAL rc            AS RECT                  ' // RECT structure
   LOCAL rcParent      AS RECT                  ' // Client area of the parent
   LOCAL rcFill        AS RECT                  ' // Area to fill
   LOCAL si            AS SCROLLINFO            ' // SCROLLINFO sructure
   LOCAL pCreateStruct AS CREATESTRUCT PTR      ' // Initialization parameters
   LOCAL StartupInput  AS GdiplusStartupInput   ' // GdiplusStartupInput structure
   LOCAL bi            AS BITMAPINFO            ' // BITMAPINFO structure
   LOCAL ppvBits       AS DWORD                 ' // Location of the DIB bit values

   ' // Gets a pointer to the control data
   IF ISTRUE hwnd AND wMsg <> %WM_CREATE THEN pdata = GetWindowLong(hwnd, 0)

   SELECT CASE wMsg

      CASE %WM_CREATE
         ' // Allocates memory for the control's data
'         pdata = HeapAlloc(GetProcessHeap(), %HEAP_ZERO_MEMORY, SIZEOF(@pdata))
         pdata = HeapAlloc(GetProcessHeap(), %HEAP_ZERO_MEMORY, SIZEOF(GLCTXDATA))
         IF ISTRUE pdata THEN
            ' // Stores the pointer in the cbWndExtra member of the window class
            SetWindowLong hwnd, 0, pdata
            ' // Pointer to the initialization parameters structure
            pCreateStruct = lParam
            IF @pCreateStruct.lpCreateParams = %TRUE THEN
               ' // Initialize GDI+
               StartupInput.GdiplusVersion = 1
               hStatus = GdiplusStartup(@pData.m_token, StartupInput, BYVAL %NULL)
               IF hStatus <> %StatusOk OR @pData.m_token = 0 THEN
                  FUNCTION = -1   ' // Abort the action
                  EXIT FUNCTION
               END IF
            END IF
            ' // Creates a compatible memory device context and bitmap
            GetClientRect hwnd, @pData.m_coord
            hDc = GetDC(hwnd)
            @pData.m_BitsPerPel = GetDeviceCaps(hDC, %BITSPIXEL)
            @pdata.m_hMemDc = CreateCompatibleDc(hDc)
            bi.bmiHeader.biSize = SIZEOF(bi.bmiHeader)
            bi.bmiHeader.biWidth = @pData.m_coord.nRight - @pData.m_coord.nLeft
            bi.bmiHeader.biHeight = @pData.m_coord.nBottom - @pData.m_coord.nTop
            bi.bmiHeader.biPlanes = 1
            bi.bmiHeader.biBitCount = @pData.m_BitsPerPel
            bi.bmiHeader.biCompression = %BI_RGB
            @pdata.m_hBmp = CreateDIBSection(hDC, bi, %DIB_RGB_COLORS, BYVAL VARPTR(ppvBits), %NULL, 0)
            @pdata.m_pvBits = ppvBits
            @pdata.m_hOldBmp = SelectObject(@pdata.m_hMemDc, @pdata.m_hBmp)
'            FillRect @pdata.m_hMemDc, @pData.m_coord, %COLOR_BTNFACE + 1
'            FillRect @pdata.m_hMemDc, @pData.m_coord, 0
            FillRect @pdata.m_hMemDc, @pData.m_coord, GetClassLong(GetParent(hwnd), %GCL_HBRBACKGROUND)
            ReleaseDc hwnd, hDc
            ' // Set the virtual size equal to the size of the bitmap
            @pData.m_vWidth = @pData.m_coord.nRight - @pData.m_coord.nLeft
            @pData.m_vHeight = @pData.m_coord.nBottom - @pData.m_coord.nTop
            ' // Default stretch mode
            @pData.m_StretchMode = %HALFTONE
            ' // OpenGL: Set the pixel format
            IF ISFALSE GlCtx_SetPixelFormat(@pdata.m_hMemDc, @pData.m_BitsPerPel) THEN
               ' // Aborts the action
               FUNCTION = -1
               EXIT FUNCTION
            END IF
            @pdata.m_hRC = GlCtx_CreateContext(@pdata.m_hMemDc)
            ' // OpenGL: Create the rendering context
            IF @pdata.m_hRC = 0 THEN
               ' // Aborts the action
               FUNCTION = -1
               EXIT FUNCTION
            END IF
            ' // Initializes scroll bar ranges
            @pData.m_MaxX = @pData.m_coord.nRight - @pData.m_coord.nLeft
            @pData.m_MaxY = @pData.m_coord.nBottom - @pData.m_coord.nTop
            si.cbSize = SIZEOF(si)
            si.fMask = %SIF_RANGE
            si.nMin = 0
            si.nMax = @pData.m_MaxX - @pData.m_coord.nRight - @pData.m_coord.nLeft
            SetScrollInfo hwnd, %SB_HORZ, si, 1
            si.nMax = @pData.m_MaxY - @pData.m_coord.nBottom - @pData.m_coord.nTop
            SetScrollInfo hwnd, %SB_VERT, si, 1
            ' // Invalidates the window to force redrawing
            InvalidateRect hwnd, BYVAL %NULL, 0
            EXIT FUNCTION
         ELSE
            ' // Aborts the action
            FUNCTION = -1
            EXIT FUNCTION
         END IF

      CASE %WM_KEYDOWN
         ' // Keyboard navigation
         SELECT CASE LO(WORD, wParam)
            CASE %VK_RETURN
               SendMessage GetParent(hwnd), %WM_COMMAND, MAK(LONG, %IDOK, %BN_CLICKED), hwnd
            CASE %VK_ESCAPE
               SendMessage GetParent(hwnd), %WM_COMMAND, MAK(LONG, %IDCANCEL, %BN_CLICKED), hwnd
            CASE %VK_RIGHT
               IF GetAsyncKeyState(%VK_CONTROL) THEN
                   SendMessage hwnd, %WM_HSCROLL, %SB_PAGERIGHT, 0
               ELSE
                   SendMessage hwnd, %WM_HSCROLL, %SB_LINERIGHT, 0
               END IF
            CASE %VK_LEFT
               IF GetAsyncKeyState(%VK_CONTROL) THEN
                   SendMessage hwnd,%WM_HSCROLL, %SB_PAGELEFT, 0
               ELSE
                  SendMessage hwnd, %WM_HSCROLL, %SB_LINELEFT, 0
               END IF
            CASE %VK_DOWN
               SendMessage hwnd, %WM_VSCROLL, %SB_LINEDOWN, 0
            CASE %VK_UP
               SendMessage hwnd, %WM_VSCROLL, %SB_LINEUP, 0
            CASE %VK_PGDN
               SendMessage hwnd, %WM_VSCROLL, %SB_PAGEDOWN, 0
            CASE %VK_PGUP
               SendMessage hwnd, %WM_VSCROLL, %SB_PAGEUP, 0
            CASE %VK_HOME
               SendMessage hwnd, %WM_VSCROLL, %SB_TOP, 0
            CASE %VK_END
               SendMessage hwnd, %WM_VSCROLL, %SB_BOTTOM, 0
         END SELECT
         EXIT FUNCTION

      CASE %WM_MOUSEWHEEL
         LOCAL zDelta AS INTEGER
         zDelta = HI(WORD, wParam)
         IF (LO(WORD, wParam) AND %MK_CONTROL) = %MK_CONTROL THEN    ' Horizontal scroll
            IF zDelta > 0 THEN                                       ' Scroll to the left
               SendMessage hwnd, %WM_HSCROLL, %SB_LINELEFT, 0
            ELSE                                                     ' Scroll to the right
               SendMessage hwnd, %WM_HSCROLL, %SB_LINERIGHT, 0
            END IF
         ELSE                                                        ' Vertical scroll
            IF zDelta > 0 THEN                                       ' Scroll up
               SendMessage hwnd, %WM_VSCROLL, %SB_LINEUP, 0
            ELSE                                                     ' Scroll down
               SendMessage hwnd, %WM_VSCROLL, %SB_LINEDOWN, 0
            END IF
         END IF
         EXIT FUNCTION

      CASE %WM_HSCROLL
         ' // Horizontal scrolling
         SELECT CASE LO(WORD, wParam)
            CASE %SB_THUMBTRACK
               @pData.m_OrgX = HI(WORD, wParam)
            CASE %SB_LINERIGHT
               IF @pData.m_OrgX < @pData.m_MaxX - @pData.m_coord.nRight - @pData.m_coord.nLeft THEN
                  @pData.m_OrgX = @pData.m_OrgX + 10
                  IF @pData.m_OrgX > @pData.m_MaxX - @pData.m_coord.nRight - @pData.m_coord.nLeft THEN
                     @pData.m_OrgX = @pData.m_MaxX - @pData.m_coord.nRight - @pData.m_coord.nLeft
                  END IF
               END IF
            CASE %SB_LINELEFT
               IF @pData.m_OrgX > 0 THEN
                  @pData.m_OrgX = @pData.m_OrgX - 10
                  IF @pData.m_OrgX < 0 THEN @pData.m_OrgX = 0
               END IF
            CASE %SB_PAGERIGHT
               nPage = @pData.m_coord.nRight - @pData.m_coord.nLeft
               IF @pData.m_OrgX + nPage < @pData.m_MaxX - @pData.m_coord.nRight - @pData.m_coord.nLeft THEN
                  @pData.m_OrgX = @pData.m_OrgX + nPage
               ELSE
                  @pData.m_OrgX = @pData.m_MaxX - @pData.m_coord.nRight - @pData.m_coord.nLeft
               END IF
            CASE %SB_PAGELEFT
               nPage = @pData.m_coord.nRight - @pData.m_coord.nLeft
               IF @pData.m_OrgX - nPage > 0 THEN
                  @pData.m_OrgX = @pData.m_OrgX - nPage
               ELSE
                  @pData.m_OrgX = 0
               END IF
         END SELECT
         si.fMask = %SIF_POS
         si.nPos = @pData.m_OrgX
         SetScrollInfo hwnd, %SB_HORZ, si, 1
         ' // Invalidates the window to force redrawing
         InvalidateRect hwnd, BYVAL %NULL, 0
         EXIT FUNCTION

      CASE %WM_VSCROLL
         ' // Vertical scrolling
         SELECT CASE LO(WORD, wParam)
            CASE %SB_THUMBTRACK
               @pData.m_OrgY = HI(WORD, wParam)
            CASE %SB_LINEDOWN
               IF @pData.m_OrgY < @pData.m_MaxY - @pData.m_coord.nBottom - @pData.m_coord.nTop THEN
                  @pData.m_OrgY = @pData.m_OrgY + 10
                  IF @pData.m_OrgY > @pData.m_MaxY - @pData.m_coord.nBottom - @pData.m_coord.nTop THEN
                     @pData.m_OrgY = @pData.m_MaxY - @pData.m_coord.nBottom - @pData.m_coord.nTop
                  END IF
               END IF
            CASE %SB_LINEUP
               IF @pData.m_OrgY > 0 THEN
                  @pData.m_OrgY = @pData.m_OrgY - 10
                  IF @pData.m_OrgY < 0 THEN @pData.m_OrgY = 0
               END IF
            CASE %SB_PAGEDOWN
               nPage = @pData.m_coord.nBottom - @pData.m_coord.nTop
               IF @pData.m_OrgY + nPage < @pData.m_MaxY - @pData.m_coord.nBottom - @pData.m_coord.nTop THEN
                  @pData.m_OrgY = @pData.m_OrgY + nPage
               ELSE
                  @pData.m_OrgY = @pData.m_MaxY - @pData.m_coord.nBottom - @pData.m_coord.nTop
               END IF
            CASE %SB_PAGEUP
               nPage = @pData.m_coord.nBottom - @pData.m_coord.nTop
               IF @pData.m_OrgY - nPage > 0 THEN
                  @pData.m_OrgY = @pData.m_OrgY - nPage
               ELSE
                  @pData.m_OrgY = 0
               END IF
            CASE %SB_TOP
               @pData.m_OrgX = 0
               @pData.m_OrgY = 0
               si.fMask = %SIF_POS
               si.nPos = @pData.m_OrgX
               SetScrollInfo hwnd, %SB_HORZ, si, 1
            CASE %SB_BOTTOM
               GetClientRect hwnd, rc
               @pData.m_OrgX = @pData.m_MaxX - rc.nRight
               @pData.m_OrgY = @pData.m_MaxY - rc.nBottom
               si.fMask = %SIF_POS
               si.nPos = @pData.m_OrgX
               SetScrollInfo hwnd, %SB_HORZ, si, 1
         END SELECT
         si.fMask = %SIF_POS
         si.nPos = @pData.m_OrgY
         SetScrollInfo hwnd, %SB_VERT, si, 1
         ' // Invalidates the window to force redrawing
         InvalidateRect hwnd, BYVAL %NULL, 0
         EXIT FUNCTION

      CASE %WM_SIZE
         ' // If resizable or stretchable, sets the virtual buffer to the size of the control.
         ' // This disallows scrolling and clears the contents. Therefore, the caller must redraw it.
         IF @pdata.m_Resizable OR @pData.m_Stretchable THEN
            SendMessage hwnd, %GLCTX_SETVIRTUALBUFFER, LO(WORD, lParam), HI(WORD, lParam)
         ELSE
            ' // Updates virtual window origins
            Increment = LO(WORD, lParam) - @pData.m_coord.nRight - @pData.m_coord.nLeft
            IF Increment < 0 THEN Increment = 0
            IF (Increment > 0) AND (@pData.m_OrgX >= (LO(WORD, lParam) - @pData.m_coord.nRight - @pData.m_coord.nLeft)) THEN @pData.m_OrgX = @pData.m_OrgX - Increment
            IF @pData.m_OrgX < 0 THEN  @pData.m_OrgX = 0
            Increment = HI(WORD, lParam) - @pData.m_coord.nBottom - @pData.m_coord.nTop
            IF Increment < 0 THEN Increment = 0
            IF(Increment > 0) AND (@pData.m_OrgY >= (HI(WORD, lParam) - @pData.m_coord.nBottom - @pData.m_coord.nTop)) THEN @pData.m_OrgY = @pData.m_OrgY - Increment
            IF @pData.m_OrgY < 0 THEN @pData.m_OrgY = 0
            ' // Stores new window extents
            @pData.m_coord.nRight  = LO(WORD, lParam)
            @pData.m_coord.nBottom = HI(WORD, lParam)
            ' // Reinitializes scroll bar ranges
            si.cbSize = sizeof(si)
            si.fMask = %SIF_RANGE OR %SIF_POS
            si.nMin = 0
            si.nMax = @pData.m_MaxX - @pData.m_coord.nRight - @pData.m_coord.nLeft
            si.nPos = @pData.m_OrgX
            SetScrollInfo hwnd, %SB_HORZ, si, 1
            si.nMax = @pData.m_MaxY - @pData.m_coord.nBottom - @pData.m_coord.nTop
            si.nPos = @pData.m_OrgY
            SetScrollInfo hwnd, %SB_VERT, si, 1
            ' // Invalidates the window to force redrawing
            InvalidateRect hwnd, BYVAL %NULL, 0
         END IF

         EXIT FUNCTION

      CASE %WM_DESTROY
         ' // Restore the original bitmap
         SelectObject(@pdata.m_hMemDc, @pdata.m_hOldBmp)
         ' // Release the device and rendering contexts
         IF @pdata.m_hMemDc THEN wglMakeCurrent @pdata.m_hMemDc, 0
         IF @pdata.m_hRC THEN wglDeleteContext @pdata.m_hRC
         ' // Destroys the bitmap and the memory device context
         IF @pdata.m_hBmp THEN DeleteObject @pdata.m_hBmp
         IF @pdata.m_hMemDc THEN DeleteObject @pdata.m_hMemDc
         ' // Shutdown GDI+
         IF @pData.m_token THEN GdiplusShutdown @pData.m_token
         ' // Deallocates the memory used for the control's data
         IF pdata THEN CALL HeapFree(GetProcessHeap(), 0, BYVAL pdata)
         EXIT FUNCTION

      CASE %WM_ERASEBKGND
         ' // If not stretchable...
         IF @pData.m_Stretchable = 0 THEN
            ' // Erases only the portion of the window not covered
            ' // by the graphic or image to avoid flicker
            GetClientRect hwnd, rc
            IF rc.nRight - rc.nLeft > @pData.m_vWidth OR _
               rc.nBottom - rc.nTop > @pData.m_vHeight THEN
               hDC = wParam
               hBrush = CreateSolidBrush(@pdata.m_bkColor)
               IF hBrush THEN
                  rcFill = rc
                  rcFill.nLeft = @pData.m_vWidth
                  FillRect hDc, rcFill, hBrush
                  rcFill = rc
                  rcFill.nTop = @pData.m_vHeight
                  FillRect hDc, rcFill, hBrush
                  DeleteObject hBrush
               END IF
            END IF
         END IF
         FUNCTION = 1
         EXIT FUNCTION

      CASE %WM_PRINTCLIENT
         ' // Copies the bitmap to the provided device context
         hDc = wParam
         GetClientRect(hwnd, rc)
         IF @pData.m_Stretchable THEN
            SetStretchBltMode hdc, @pData.m_StretchMode
            IF @pData.m_StretchMode = %HALFTONE THEN SetBrushOrgEx hdc, 0, 0, BYVAL %NULL
            hr = StretchBlt(hDc, 0, 0, GetDeviceCaps(hdc, %HORZRES), GetDeviceCaps(hdc, %VERTRES), _
                 @pdata.m_hMemDc, 0, 0, @pData.m_vWidth, @pData.m_vHeight, %SRCCOPY)
         ELSE
            hr = BitBlt(hDc, 0, 0, GetDeviceCaps(hdc, %HORZRES), GetDeviceCaps(hdc, %VERTRES), _
                 @pdata.m_hMemDc, rc.nLeft + @pData.m_OrgX, rc.nTop + @pData.m_OrgY, %SRCCOPY)
         END IF
         EXIT FUNCTION

      CASE %WM_PAINT
         ' // Copies the bitmap to the control's window
         hDc = BeginPaint(hwnd, ps)
         IF @pData.m_Stretchable THEN
            SetStretchBltMode hdc, @pData.m_StretchMode
            IF @pData.m_StretchMode = %HALFTONE THEN SetBrushOrgEx hdc, 0, 0, BYVAL %NULL
            hr = StretchBlt(hDc, ps.rcPaint.nLeft, ps.rcPaint.nTop, _
                 ps.rcPaint.nRight - ps.rcPaint.nLeft, _
                 ps.rcPaint.nBottom - ps.rcPaint.nTop, _
                 @pdata.m_hMemDc, 0, 0, @pData.m_vWidth, @pData.m_vHeight, %SRCCOPY)
         ELSE
            hr = BitBlt(hDc, ps.rcPaint.nLeft, ps.rcPaint.nTop, _
                 ps.rcPaint.nRight - ps.rcPaint.nLeft, _
                 ps.rcPaint.nBottom - ps.rcPaint.nTop, _
                 @pdata.m_hMemDc, ps.rcPaint.nLeft + @pData.m_OrgX, ps.rcPaint.nTop + @pData.m_OrgY, %SRCCOPY)
         END IF
         EndPaint hwnd, ps
         EXIT FUNCTION

      CASE %WM_COMMAND, %WM_NOTIFY
         ' // Forwards the message to the parent window
         SendMessage GetParent(hwnd), wMsg, wParam, lParam

      CASE %WM_GETDLGCODE
         ' // Ensures that the control will process all the keystrokes by itself
         FUNCTION = %DLGC_WANTALLKEYS
         EXIT FUNCTION

      CASE %WM_MOUSEMOVE
         ' // Forwards the message to the parent window
         SendMessage GetParent(hwnd), wMsg, wParam, lParam
         EXIT FUNCTION

      CASE %WM_LBUTTONUP
         ' // Forwards the message to the parent window
         SendMessage GetParent(hwnd), wMsg, wParam, lParam
         EXIT FUNCTION

      CASE %WM_LBUTTONDOWN
         ' // Forwards the message to the parent window
         phdr.hwndFrom = hwnd
         phdr.idFrom = GetDlgCtrlId(hwnd)
         phdr.code = %NM_CLICK
'         SendMessage GetParent(hwnd), %WM_NOTIFY, GetDlgCtrlId(hwnd), VARPTR(phdr)
         IF SendMessage(GetParent(hwnd), %WM_NOTIFY, GetDlgCtrlId(hwnd), VARPTR(phdr)) = 0 THEN
            SendMessage GetParent(hwnd), wMsg, wParam, lParam
         END IF
         EXIT FUNCTION

      CASE %WM_RBUTTONDOWN
         ' // Forwards the message to the parent window
         phdr.hwndFrom = hwnd
         phdr.idFrom = GetDlgCtrlId(hwnd)
         phdr.code = %NM_RCLICK
'         SendMessage GetParent(hwnd), %WM_NOTIFY, GetDlgCtrlId(hwnd), VARPTR(phdr)
         IF SendMessage(GetParent(hwnd), %WM_NOTIFY, GetDlgCtrlId(hwnd), VARPTR(phdr)) = 0 THEN
            SendMessage GetParent(hwnd), wMsg, wParam, lParam
         END IF
         EXIT FUNCTION

      CASE %WM_LBUTTONDBLCLK
         ' // Forwards the message to the parent window
         phdr.hwndFrom = hwnd
         phdr.idFrom = GetDlgCtrlId(hwnd)
         phdr.code = %NM_DBLCLK
'         SendMessage GetParent(hwnd), %WM_NOTIFY, GetDlgCtrlId(hwnd), VARPTR(phdr)
         IF SendMessage(GetParent(hwnd), %WM_NOTIFY, GetDlgCtrlId(hwnd), VARPTR(phdr)) = 0 THEN
            SendMessage GetParent(hwnd), wMsg, wParam, lParam
         END IF
         EXIT FUNCTION

      CASE %WM_RBUTTONDBLCLK
         ' // Forwards the message to the parent window
         phdr.hwndFrom = hwnd
         phdr.idFrom = GetDlgCtrlId(hwnd)
         phdr.code = %NM_RDBLCLK
'         SendMessage GetParent(hwnd), %WM_NOTIFY, GetDlgCtrlId(hwnd), VARPTR(phdr)
         IF SendMessage(GetParent(hwnd), %WM_NOTIFY, GetDlgCtrlId(hwnd), VARPTR(phdr)) = 0 THEN
            SendMessage GetParent(hwnd), wMsg, wParam, lParam
         END IF
         EXIT FUNCTION

      CASE %WM_SETFOCUS
         ' // Forwards the message to the parent window
         phdr.hwndFrom = hwnd
         phdr.idFrom = GetDlgCtrlId(hwnd)
         phdr.code = %NM_SETFOCUS
         SendMessage GetParent(hwnd), %WM_NOTIFY, GetDlgCtrlId(hwnd), VARPTR(phdr)
         EXIT FUNCTION

      CASE %WM_KILLFOCUS
         ' // Forwards the message to the parent window
         phdr.hwndFrom = hwnd
         phdr.idFrom = GetDlgCtrlId(hwnd)
         phdr.code = %NM_KILLFOCUS
         SendMessage GetParent(hwnd), %WM_NOTIFY, GetDlgCtrlId(hwnd), VARPTR(phdr)
         EXIT FUNCTION

      CASE %WM_ENABLE
         ' // Redraws the control
         InvalidateRect hwnd, BYVAL %NULL, 0
         UpdateWindow hwnd
         EXIT FUNCTION

      CASE %GLCTX_SETVIRTUALBUFFER
         ' // Restore the original bitmap
         SelectObject(@pdata.m_hMemDc, @pdata.m_hOldBmp)
         ' // Release the device and rendering contexts
         IF @pdata.m_hMemDc THEN wglMakeCurrent @pdata.m_hMemDc, 0
         IF @pdata.m_hRC THEN wglDeleteContext @pdata.m_hRC
         ' // Destroys the bitmap and the memory device context
         IF @pdata.m_hBmp THEN DeleteObject @pdata.m_hBmp
         IF @pdata.m_hMemDc THEN DeleteObject @pdata.m_hMemDc
         @pData.m_vWidth = wParam
         @pData.m_vHeight = lParam
         ' // Creates a virtual compatible memory device context and bitmap.
         ' // wParam holds the width and lParam the height.
         hDc = GetDC(hwnd)
         @pdata.m_hMemDc = CreateCompatibleDc(hDc)
         bi.bmiHeader.biSize = SIZEOF(bi.bmiHeader)
         bi.bmiHeader.biWidth = wParam
         bi.bmiHeader.biHeight = lParam
         bi.bmiHeader.biPlanes = 1
         bi.bmiHeader.biBitCount = @pData.m_BitsPerPel
         bi.bmiHeader.biCompression = %BI_RGB
         @pdata.m_hBmp = CreateDIBSection(hDC, bi, %DIB_RGB_COLORS, BYVAL VARPTR(ppvBits), %NULL, 0)
         @pdata.m_pvBits = ppvBits
         @pdata.m_hOldBmp = SelectObject(@pdata.m_hMemDc, @pdata.m_hBmp)
         ' // Adjusts the coordinates
         @pData.m_coord.nRight = @pData.m_coord.nLeft + wParam
         @pData.m_coord.nBottom = @pData.m_coord.nTop + lParam
         ' // Erases the background with the specified or a default color
         IF @pdata.m_bkColor THEN
            hBrush = CreateSolidBrush(@pdata.m_bkColor)
            IF hBrush THEN
               FillRect @pdata.m_hMemDc, @pData.m_coord, hBrush
               DeleteObject hBrush
            END IF
         ELSE
'            FillRect @pdata.m_hMemDc, @pData.m_coord, %COLOR_BTNFACE + 1
            FillRect @pdata.m_hMemDc, @pData.m_coord, GetClassLong(GetParent(hwnd), %GCL_HBRBACKGROUND)
         END IF
         ReleaseDc hwnd, hDc
         ' // OpenGL: Set the pixel format and create the rendering context
         IF GlCtx_SetPixelFormat(@pdata.m_hMemDc, @pData.m_BitsPerPel) THEN
            @pdata.m_hRC = GlCtx_CreateContext(@pdata.m_hMemDc)
         END IF
         IF @pdata.m_Resizable = 0 AND @pdata.m_Stretchable = 0 THEN
            ' // Adds scrollbars if needed
            GetClientRect GetParent(hwnd), rcParent
            IF wParam > rcParent.nRight OR lParam > rcParent.nBottom THEN
               dwStyle = GetWindowLong(hwnd, %GWL_STYLE)
               dwStyle = dwStyle OR %WS_HSCROLL OR %WS_VSCROLL
               hr = SetWindowLong(hwnd, %GWL_STYLE, dwStyle)
            END IF
            ' // Initializes scroll bar ranges
            @pData.m_MaxX = @pData.m_coord.nRight - @pData.m_coord.nLeft
            @pData.m_MaxY = @pData.m_coord.nBottom - @pData.m_coord.nTop
            si.cbSize = SIZEOF(si)
            si.fMask = %SIF_RANGE
            si.nMin = 0
            si.nMax = @pData.m_MaxX - @pData.m_coord.nRight - @pData.m_coord.nLeft
            SetScrollInfo hwnd, %SB_HORZ, si, 1
            si.nMax = @pData.m_MaxY - @pData.m_coord.nBottom - @pData.m_coord.nTop
            SetScrollInfo hwnd, %SB_VERT, si, 1
            ' // Invalidates the window to force redrawing
            InvalidateRect hwnd, BYVAL %NULL, 0
         END IF
         EXIT FUNCTION

   END SELECT

   ' Default processing for other messages.
   FUNCTION = DefWindowProc(hwnd, wMsg, wParam, lParam)

END FUNCTION
' ========================================================================================

' ========================================================================================
' Set the pixel format
' ========================================================================================
FUNCTION GlCtx_SetPixelFormat (BYVAL hdc AS DWORD, BYVAL nBitsPerPel AS LONG) AS LONG

   LOCAL pf AS LONG
   LOCAL pfd AS PIXELFORMATDESCRIPTOR
   LOCAL cDepthBits AS LONG

   cDepthBits = nBitsPerPel - 8
   IF cDepthBits < 16 THEN cDepthBits = 16

   ' // Fill the PIXELFORMATDESCRIPTOR structure
   pfd.nSize           = SIZEOF(PIXELFORMATDESCRIPTOR)   ' Size of the structure
   pfd.nVersion        = 1                               ' Version number
   pfd.dwFlags         = %PFD_SUPPORT_OPENGL _           ' The buffer supports OpenGL drawing
                         OR %PFD_SUPPORT_GDI             ' The buffer supports GDI drawing.
   pfd.iPixelType      = %PFD_TYPE_RGBA                  ' Request an RGBA format
   pfd.cColorBits      = nBitsPerPel                     ' Number of color bitplanes in each color buffer
   pfd.cRedBits        = 0                               ' Number of red bitplanes in each RGBA color buffer.
   pfd.cRedShift       = 0                               ' Shift count for red bitplanes in each RGBA color buffer.
   pfd.cGreenBits      = 0                               ' Number of green bitplanes in each RGBA color buffer.
   pfd.cGreenShift     = 0                               ' Shift count for green bitplanes in each RGBA color buffer.
   pfd.cBlueBits       = 0                               ' Number of blue bitplanes in each RGBA color buffer.
   pfd.cBlueShift      = 0                               ' Shift count for blue bitplanes in each RGBA color buffer.
   pfd.cAlphaBits      = 0                               ' Number of alpha bitplanes in each RGBA color buffer
   pfd.cAlphaShift     = 0                               ' Shift count for alpha bitplanes in each RGBA color buffer.
   pfd.cAccumBits      = 64                              ' Total number of bitplanes in the accumulation buffer.
   pfd.cAccumRedBits   = 0                               ' Number of red bitplanes in the accumulation buffer.
   pfd.cAccumGreenBits = 0                               ' Number of gree bitplanes in the accumulation buffer.
   pfd.cAccumBlueBits  = 0                               ' Number of blue bitplanes in the accumulation buffer.
   pfd.cAccumAlphaBits = 0                               ' Number of alpha bitplanes in the accumulation buffer.
   pfd.cDepthBits      = cDepthBits                      ' Depth of the depth (z-axis) buffer.
   pfd.cStencilBits    = 0                               ' Depth of the stencil buffer.
   pfd.cAuxBuffers     = 0                               ' Number of auxiliary buffers.
   pfd.iLayerType      = 0                               ' Ignored. Earlier implementations of OpenGL used this member, but it is no longer used.
   pfd.bReserved       = 0                               ' Number of overlay and underlay planes.
   pfd.dwLayerMask     = 0                               ' Ignored. Earlier implementations of OpenGL used this member, but it is no longer used.
   pfd.dwVisibleMask   = 0                               ' Transparent color or index of an underlay plane.
   pfd.dwDamageMask    = 0                               ' Ignored. Earlier implementations of OpenGL used this member, but it is no longer used.

   ' // Find a matching pixel format
   pf = ChoosePixelFormat(hDC, pfd)
   IF ISFALSE pf THEN
'      OutputDebugString "Can't find a suitable pixel format"
      MessageBox(0, "Can't find a suitable pixel format", "GlCtx_SetPixelFormat", _
                 %MB_OK OR %MB_ICONINFORMATION OR %MB_APPLMODAL)
      EXIT FUNCTION
   END IF

   ' // Set the pixel format
   IF ISFALSE SetPixelFormat(hDC, pf, pfd) THEN
'      OutputDebugString "Can't set the pixel format"
      MessageBox(0, "Can't set the pixel format", "GlCtx_SetPixelFormat", _
                 %MB_OK OR %MB_ICONINFORMATION OR %MB_APPLMODAL)
      EXIT FUNCTION
   END IF
   FUNCTION = %TRUE

END FUNCTION
' ========================================================================================

' ========================================================================================
' Create context
' ========================================================================================
FUNCTION GlCtx_CreateContext (BYVAL hdc AS DWORD) AS DWORD

   LOCAL hRC AS DWORD

   ' // Create a new OpenGL rendering context
   hRC = wglCreateContext(hdc)
   IF ISFALSE hRC THEN
'      OutputDebugString "Can't create an OpenGL rendering context"
      MessageBox(0, "Can't create an OpenGL rendering context", "GlCtx_CreateContext", _
                 %MB_OK OR %MB_ICONINFORMATION OR %MB_APPLMODAL)
      EXIT FUNCTION
   END IF

   ' // Make it current
   IF ISFALSE wglMakeCurrent(hdc, hRC) THEN
'      OutputDebugString "Can't activate the OpenGL rendering context"
      MessageBox(0, "Can't activate the OpenGL rendering context", "GlCtx_CreateContext", _
                 %MB_OK OR %MB_ICONINFORMATION OR %MB_APPLMODAL)
   END IF

   FUNCTION = hRC

END FUNCTION
' ========================================================================================

' ========================================================================================
' Determines whether the current process is dots per inch (dpi) aware such that it adjusts
' the sizes of UI elements to compensate for the dpi setting.
' ========================================================================================
FUNCTION GlCtx_IsProcessDPIAware () AS LONG
   LOCAL bRes AS LONG
   LOCAL hLib AS DWORD
   LOCAL pProc AS DWORD
   hLib = LoadLibrary("user32.dll")
   IF hLib = 0 THEN EXIT FUNCTION
   pProc = GetProcAddress(hLib, "IsProcessDPIAware")
   IF pProc THEN CALL DWORD pProc USING GlCtx_IsProcessDPIAware() TO bRes
   FreeLibrary hLib
   FUNCTION = bRes
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the handle of the memory device context of the control.
' Parameter:
' * hwnd = Control's window handle
' Return value:
' * The handle of the memory device context.
' ========================================================================================
FUNCTION GlCtx_GetDc (BYVAL hwnd AS DWORD) AS DWORD

   LOCAL pdata AS GLCTXDATA PTR    ' // Pointer to the control's data

   ' // Checks the validity of the parameter
   IF ISFALSE hwnd THEN EXIT FUNCTION
   ' // Gets a pointer to the control's data
   pdata = GetWindowLong(hwnd, 0)
   IF ISFALSE pdata THEN EXIT FUNCTION
   ' // Returns the handle of the memory device context
   FUNCTION = @pdata.m_hMemDc

END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the handle of the compatible bitmap.
' Parameter:
' * hwnd = Control's window handle
' Return value:
' * The handle of the compatible bitmap.
' ========================================================================================
FUNCTION GlCtx_GethBmp (BYVAL hwnd AS DWORD) AS DWORD

   LOCAL pdata AS GLCTXDATA PTR    ' // Pointer to the control's data

   ' // Checks the validity of the parameter
   IF ISFALSE hwnd THEN EXIT FUNCTION
   ' // Gets a pointer to the control's data
   pdata = GetWindowLong(hwnd, 0)
   IF ISFALSE pdata THEN EXIT FUNCTION
   ' // Returns the handle of the compatible bitmap
   FUNCTION = @pdata.m_hBmp

END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the location of the DIB bit values.
' Parameter:
' * hwnd = Control's window handle
' Return value:
' * The address of the DIB bit values.
' ========================================================================================
FUNCTION GlCtx_GetBits (BYVAL hwnd AS DWORD) AS DWORD

   LOCAL pdata AS GLCTXDATA PTR    ' // Pointer to the control's data

   ' // Checks the validity of the parameter
   IF ISFALSE hwnd THEN EXIT FUNCTION
   ' // Gets a pointer to the control's data
   pdata = GetWindowLong(hwnd, 0)
   IF ISFALSE pdata THEN EXIT FUNCTION
   ' // Returns the handle of the compatible bitmap
   FUNCTION = @pdata.m_pvBits

END FUNCTION
' ========================================================================================

' ========================================================================================
' Clears the graphic control with the specified RGB color.
' Parameters:
' * hwnd = Control's window handle
' * pRGBColor = RGB color used to fill the control.
' Return value:
' * If the function succeeds, the return value is TRUE.
'   If the function fails, the return value is FALSE.
' ========================================================================================
FUNCTION GlCtx_Clear (BYVAL hwnd AS DWORD, BYVAL pRGBColor AS DWORD) AS LONG

   LOCAL pdata AS GLCTXDATA PTR    ' // Pointer to the control's data
   LOCAL rc AS RECT
   LOCAL hBrush AS DWORD

   ' // Checks the validity of the parameter
   IF ISFALSE hwnd THEN EXIT FUNCTION
   ' // Gets a pointer to the control's data
   pdata = GetWindowLong(hwnd, 0)
   IF ISFALSE pdata THEN EXIT FUNCTION
   IF ISFALSE @pdata.m_hMemDc THEN EXIT FUNCTION
   hBrush = CreateSolidBrush(pRGBColor)
   GetClientRect hwnd, rc
   IF @pData.m_vWidth THEN rc.nRight = rc.nLeft + @pData.m_vWidth
   IF @pData.m_vHeight THEN rc.nBottom = rc.nTop + @pData.m_vHeight
   FUNCTION = FillRect(@pdata.m_hMemDc, rc, hBrush)
   DeleteObject hBrush
   @pdata.m_bkColor = pRGBColor

END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the size of the virtual buffer.
' Parameters:
' * hwnd = Control's window handle
' * nWidth = Width, in pixels, of the virtual buffer.
' * nHeight = Height, in pixels, of the virtual buffer.
' Return value:
' * If the function succeeds, the return value is %S_OK.
' ========================================================================================
FUNCTION GlCtx_SetVirtualBufferSize (BYVAL hwnd AS DWORD, BYVAL nWidth AS LONG, BYVAL nHeight AS LONG) AS LONG

   IF ISFALSE IsWindow(hwnd) THEN FUNCTION = %E_INVALIDARG : EXIT FUNCTION
   IF nWidth < 0 THEN FUNCTION =  %E_INVALIDARG : EXIT FUNCTION
   IF nHeight < 0 THEN FUNCTION = %E_INVALIDARG : EXIT FUNCTION
   SendMessage(hwnd, %GLCTX_SETVIRTUALBUFFER, nWidth, nHeight)

END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the value of the stretchable property
' Parameter:
' * hwnd = Control's window handle
' Return value:
' * TRUE or FALSE
' ========================================================================================
FUNCTION GlCtx_IsStretchable (BYVAL hwnd AS DWORD) AS LONG

   LOCAL pdata AS GLCTXDATA PTR    ' // Pointer to the control's data

   ' // Checks the validity of the parameter
   IF ISFALSE hwnd THEN EXIT FUNCTION
   ' // Gets a pointer to the control's data
   pdata = GetWindowLong(hwnd, 0)
   IF ISFALSE pdata THEN EXIT FUNCTION
   FUNCTION = @pdata.m_Stretchable

END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the value of the stretchable property
' Parameters:
' * hwnd = Control's window handle
' * bResizable = TRUE or FALSE
' Return value:
' * The previous value of the property
' ========================================================================================
FUNCTION GlCtx_SetStretchable (BYVAL hwnd AS DWORD, BYVAL bStretchable AS LONG) AS LONG

   LOCAL pdata AS GLCTXDATA PTR    ' // Pointer to the control's data

   ' // Checks the validity of the parameter
   IF ISFALSE hwnd THEN EXIT FUNCTION
   ' // Gets a pointer to the control's data
   pdata = GetWindowLong(hwnd, 0)
   IF ISFALSE pdata THEN EXIT FUNCTION
   FUNCTION = @pdata.m_Stretchable
   @pdata.m_Stretchable = IIF&(bStretchable <> 0, %TRUE, %FALSE)

END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the value of the stretch mode property
' Parameter:
' * hwnd = Control's window handle
' Return value:
' * The strech mode.
' ========================================================================================
FUNCTION GlCtx_GetStretchMode (BYVAL hwnd AS DWORD) AS LONG

   LOCAL pdata AS GLCTXDATA PTR    ' // Pointer to the control's data

   ' // Checks the validity of the parameter
   IF ISFALSE hwnd THEN EXIT FUNCTION
   ' // Gets a pointer to the control's data
   pdata = GetWindowLong(hwnd, 0)
   IF ISFALSE pdata THEN EXIT FUNCTION
   FUNCTION = @pdata.m_StretchMode

END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the value of the stretch mode property
' Parameters:
' * hwnd = Control's window handle
' * nStretchMode = The stretching mode.
' - See SetStretchBltMode Function for possible values.
' Return value:
' * The previous value of the property
' ========================================================================================
FUNCTION GlCtx_SetStretchMode (BYVAL hwnd AS DWORD, BYVAL nStretchMode AS LONG) AS LONG

   LOCAL pdata AS GLCTXDATA PTR    ' // Pointer to the control's data

   ' // Checks the validity of the parameter
   IF ISFALSE hwnd THEN EXIT FUNCTION
   ' // Gets a pointer to the control's data
   pdata = GetWindowLong(hwnd, 0)
   IF ISFALSE pdata THEN EXIT FUNCTION
   FUNCTION = @pdata.m_StretchMode
   @pdata.m_StretchMode = nStretchMode

END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the value of the resizable property
' Parameter:
' * hwnd = Control's window handle
' Return value:
' * TRUE or FALSE
' ========================================================================================
FUNCTION GlCtx_IsResizable (BYVAL hwnd AS DWORD) AS LONG

   LOCAL pdata AS GLCTXDATA PTR    ' // Pointer to the control's data

   ' // Checks the validity of the parameter
   IF ISFALSE hwnd THEN EXIT FUNCTION
   ' // Gets a pointer to the control's data
   pdata = GetWindowLong(hwnd, 0)
   IF ISFALSE pdata THEN EXIT FUNCTION
   FUNCTION = @pdata.m_Resizable

END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the value of the resizable property
' Parameters:
' * hwnd = Control's window handle
' * bResizable = TRUE or FALSE
' Return value:
' * The previous value of the property
' ========================================================================================
FUNCTION GlCtx_SetResizable (BYVAL hwnd AS DWORD, BYVAL bResizable AS LONG) AS LONG

   LOCAL pdata AS GLCTXDATA PTR    ' // Pointer to the control's data

   ' // Checks the validity of the parameter
   IF ISFALSE hwnd THEN EXIT FUNCTION
   ' // Gets a pointer to the control's data
   pdata = GetWindowLong(hwnd, 0)
   IF ISFALSE pdata THEN EXIT FUNCTION
   FUNCTION = @pdata.m_Resizable
   @pdata.m_Resizable = IIF&(bResizable <> 0, %TRUE, %FALSE)

END FUNCTION
' ========================================================================================

' ========================================================================================
' If an application places more than one instance of this control on a form, we need to
' make sure that OpenGL calls are directed to the correct render context. This is achieved
' by calling GlCtx_MakeCurrent passing the handle of the wanted instance of the control.
' Parameter:
' * hwnd = Control's window handle
' Return value:
' * TRUE or FALSE
' ========================================================================================
FUNCTION GlCtx_MakeCurrent (BYVAL hwnd AS DWORD) AS LONG

   LOCAL pdata AS GLCTXDATA PTR    ' // Pointer to the control's data

   ' // Checks the validity of the parameter
   IF ISFALSE hwnd THEN EXIT FUNCTION
   ' // Gets a pointer to the control's data
   pdata = GetWindowLong(hwnd, 0)
   IF ISFALSE pdata THEN EXIT FUNCTION
   FUNCTION = wglMakeCurrent(@pdata.m_hMemDc, @pData.m_hRC)

END FUNCTION
' ========================================================================================
