' ########################################################################################
' Microsoft Windows
' File: GraphCtx.inc
' Contents: Graphic control
' Copyright (c) 2011-2012 José Roca. All Rights Reserved.
' Freeware. Use at your own risk.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%GRAPHCTX_INC = 1

#INCLUDE ONCE "windows.inc"
#INCLUDE ONCE "GDIPLUS.inc"

%GRAPHCTX_SETVIRTUALBUFFER = %WM_USER + 101

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
'    IF wParam = %IDC_GRCTX THEN
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

' ========================================================================================
' GRAPHCTXDATA structure
' ========================================================================================
TYPE GRAPHCTXDATA
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
   m_BitsPerPel  AS LONG    ' // Bits per pixel
   m_Stretchable AS LONG    ' // Contents are stretchable
   m_StretchMode AS LONG    ' // Stretch mode
   m_Resizable   AS DWORD   ' // Contents are resizable
END TYPE
' ========================================================================================

' ========================================================================================
' Registers the window class
' ========================================================================================
FUNCTION InitGraphCtx () AS WORD

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

   szClassName        = "GRAPHCTX"
   wcex.cbSize        = SIZEOF(wcex)
   wcex.style         = %CS_HREDRAW OR %CS_VREDRAW   ' OR %CS_DBLCLKS
   wcex.lpfnWndProc   = CODEPTR(GraphCtxProc)
   wcex.cbClsExtra    = 0
   wcex.cbWndExtra    = 4 ' For pointer to GRAPHCTXDATA structure
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
FUNCTION GraphCtxProc (BYVAL hwnd AS DWORD, BYVAL wMsg AS DWORD, _
                       BYVAL wParam AS DWORD, BYVAL lParam AS LONG) AS LONG

   LOCAL hStatus       AS LONG                  ' // Result code
   LOCAL pdata         AS GRAPHCTXDATA PTR      ' // Pointer to the control's data
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
   LOCAL hCloneDC      AS DWORD                 ' // Clone device context
   LOCAL hCloneBmp     AS DWORD                 ' // Clone bitmap handle
   LOCAL rcClone       AS RECT                  ' // Clone rectangle

   ' // Gets a pointer to the control data
   IF ISTRUE hwnd AND wMsg <> %WM_CREATE THEN pdata = GetWindowLong(hwnd, 0)

   SELECT CASE wMsg

      CASE %WM_CREATE
         ' // Allocates memory for the control's data
'         pdata = HeapAlloc(GetProcessHeap(), %HEAP_ZERO_MEMORY, SIZEOF(@pdata))
         pdata = HeapAlloc(GetProcessHeap(), %HEAP_ZERO_MEMORY, SIZEOF(GRAPHCTXDATA))
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
         ' // If resizable or stretchable, disable scroll bars
         IF @pdata.m_Resizable OR @pData.m_Stretchable THEN
            ' // Initializes scroll bar ranges
            GetClientRect hwnd, rc
            @pData.m_MaxX = rc.nRight - rc.nLeft
            @pData.m_MaxY = rc.nBottom - rc.nTop
            si.cbSize = SIZEOF(si)
            si.fMask = %SIF_RANGE
            si.nMin = 0
            si.nMax = @pData.m_MaxX - rc.nRight - rc.nLeft
            SetScrollInfo hwnd, %SB_HORZ, si, 1
            si.nMax = @pData.m_MaxY - rc.nBottom - rc.nTop
            SetScrollInfo hwnd, %SB_VERT, si, 1
         ELSE
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
         END IF
         ' // Invalidates the window to force redrawing
         InvalidateRect hwnd, BYVAL %NULL, 0
         EXIT FUNCTION

      CASE %WM_DESTROY
         ' // Restore the original bitmap
         SelectObject(@pdata.m_hMemDc, @pdata.m_hOldBmp)
         ' // Destroys the bitmap and the memory device context
         IF @pdata.m_hBmp THEN DeleteObject @pdata.m_hBmp
         IF @pdata.m_hMemDc THEN DeleteDC @pdata.m_hMemDc
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
         IF @pData.m_Stretchable = 0 THEN
            hr = BitBlt(hDc, 0, 0, GetDeviceCaps(hdc, %HORZRES), GetDeviceCaps(hdc, %VERTRES), _
                 @pdata.m_hMemDc, rc.nLeft + @pData.m_OrgX, rc.nTop + @pData.m_OrgY, %SRCCOPY)
         ELSE
            SetStretchBltMode hdc, @pData.m_StretchMode
            IF @pData.m_StretchMode = %HALFTONE THEN SetBrushOrgEx hdc, 0, 0, BYVAL %NULL
            hr = StretchBlt(hDc, 0, 0, GetDeviceCaps(hdc, %HORZRES), GetDeviceCaps(hdc, %VERTRES), _
                 @pdata.m_hMemDc, 0, 0, @pData.m_vWidth, @pData.m_vHeight, %SRCCOPY)
         END IF
         EXIT FUNCTION

      CASE %WM_PAINT
         ' // Copies the bitmap to the control's window
         hDc = BeginPaint(hwnd, ps)
         IF @pData.m_Stretchable = 0 THEN
            hr = BitBlt(hDc, ps.rcPaint.nLeft, ps.rcPaint.nTop, _
                 ps.rcPaint.nRight - ps.rcPaint.nLeft, _
                 ps.rcPaint.nBottom - ps.rcPaint.nTop, _
                 @pdata.m_hMemDc, ps.rcPaint.nLeft + @pData.m_OrgX, ps.rcPaint.nTop + @pData.m_OrgY, %SRCCOPY)
         ELSE
            GetClientRect hwnd, rc
            SetStretchBltMode hdc, @pData.m_StretchMode
            IF @pData.m_StretchMode = %HALFTONE THEN SetBrushOrgEx hdc, 0, 0, BYVAL %NULL
            hr = StretchBlt(hDc, ps.rcPaint.nLeft, ps.rcPaint.nTop, _
                 ps.rcPaint.nRight - ps.rcPaint.nLeft, _
                 ps.rcPaint.nBottom - ps.rcPaint.nTop, _
                 @pdata.m_hMemDc, 0, 0, @pData.m_vWidth, @pData.m_vHeight, %SRCCOPY)
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

      CASE %WM_LBUTTONDOWN
         ' // Forwards the message to the parent window
         phdr.hwndFrom = hwnd
         phdr.idFrom = GetDlgCtrlId(hwnd)
         phdr.code = %NM_CLICK
         SendMessage GetParent(hwnd), %WM_NOTIFY, GetDlgCtrlId(hwnd), VARPTR(phdr)
         EXIT FUNCTION

      CASE %WM_RBUTTONDOWN
         ' // Forwards the message to the parent window
         phdr.hwndFrom = hwnd
         phdr.idFrom = GetDlgCtrlId(hwnd)
         phdr.code = %NM_RCLICK
         SendMessage GetParent(hwnd), %WM_NOTIFY, GetDlgCtrlId(hwnd), VARPTR(phdr)
         EXIT FUNCTION

      CASE %WM_LBUTTONDBLCLK
         ' // Forwards the message to the parent window
         phdr.hwndFrom = hwnd
         phdr.idFrom = GetDlgCtrlId(hwnd)
         phdr.code = %NM_DBLCLK
         SendMessage GetParent(hwnd), %WM_NOTIFY, GetDlgCtrlId(hwnd), VARPTR(phdr)
         EXIT FUNCTION

      CASE %WM_RBUTTONDBLCLK
         ' // Forwards the message to the parent window
         phdr.hwndFrom = hwnd
         phdr.idFrom = GetDlgCtrlId(hwnd)
         phdr.code = %NM_RDBLCLK
         SendMessage GetParent(hwnd), %WM_NOTIFY, GetDlgCtrlId(hwnd), VARPTR(phdr)
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

      CASE %GRAPHCTX_SETVIRTUALBUFFER

         ' // Clone the memory bitmap to restore it later
         SetRect (rcClone, 0, 0, wParam, lParam)
         hDc = GetDC(hwnd)
         hCloneDc = CreateCompatibleDC(hDc)
         hCloneBmp = CreateBitmap(@pData.m_vWidth, @pData.m_vHeight, 1, @pData.m_BitsPerPel, BYVAL %NULL)
         IF hCloneBmp THEN
            SelectObject(hCloneDc, hCloneBmp)
            hr = BitBlt(hCloneDC, 0, 0, @pData.m_vWidth, @pData.m_vHeight, @pdata.m_hMemDc, 0, 0, %SRCCOPY)
         END IF
         ReleaseDc hwnd, hDc

         ' // Restore the original bitmap
         SelectObject(@pdata.m_hMemDc, @pdata.m_hOldBmp)
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

         ' // Copy the cloned bitmap
         IF hCloneBmp THEN
            hr = BitBlt(@pdata.m_hMemDc, 0, 0, @pData.m_vWidth, @pData.m_vHeight, hCloneDc, 0, 0, %SRCCOPY)
            SelectObject(hCloneDc, 0)
            DeleteDC hCloneDC
            DeleteObject hCloneBmp
            InvalidateRect hwnd, BYVAL %NULL, 0
         END IF

         EXIT FUNCTION

   END SELECT

   ' // Default processing for other messages.
   FUNCTION = DefWindowProc(hwnd, wMsg, wParam, lParam)

END FUNCTION
' ========================================================================================

' ========================================================================================
' Determines whether the current process is dots per inch (dpi) aware such that it adjusts
' the sizes of UI elements to compensate for the dpi setting.
' ========================================================================================
FUNCTION GraphCtx_IsProcessDPIAware () AS LONG
   LOCAL bRes AS LONG
   LOCAL hLib AS DWORD
   LOCAL pProc AS DWORD
   hLib = LoadLibrary("user32.dll")
   IF hLib = 0 THEN EXIT FUNCTION
   pProc = GetProcAddress(hLib, "IsProcessDPIAware")
   IF pProc THEN CALL DWORD pProc USING GraphCtx_IsProcessDPIAware() TO bRes
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
FUNCTION GraphCtx_GetDc (BYVAL hwnd AS DWORD) AS DWORD

   LOCAL pdata AS GRAPHCTXDATA PTR    ' // Pointer to the control's data

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
FUNCTION GraphCtx_GethBmp (BYVAL hwnd AS DWORD) AS DWORD

   LOCAL pdata AS GRAPHCTXDATA PTR    ' // Pointer to the control's data

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
FUNCTION GraphCtx_GetBits (BYVAL hwnd AS DWORD) AS DWORD

   LOCAL pdata AS GRAPHCTXDATA PTR    ' // Pointer to the control's data

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
FUNCTION GraphCtx_Clear (BYVAL hwnd AS DWORD, BYVAL pRGBColor AS DWORD) AS LONG

   LOCAL pdata AS GRAPHCTXDATA PTR    ' // Pointer to the control's data
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
FUNCTION GraphCtx_SetVirtualBufferSize (BYVAL hwnd AS DWORD, BYVAL nWidth AS LONG, BYVAL nHeight AS LONG) AS LONG

   IF ISFALSE IsWindow(hwnd) THEN FUNCTION = %E_INVALIDARG : EXIT FUNCTION
   IF nWidth < 0 THEN FUNCTION =  %E_INVALIDARG : EXIT FUNCTION
   IF nHeight < 0 THEN FUNCTION = %E_INVALIDARG : EXIT FUNCTION
   SendMessage(hwnd, %GRAPHCTX_SETVIRTUALBUFFER, nWidth, nHeight)

END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the width of the virtual buffer.
' Parameter:
' Return value:
' * The width of the virtual buffer.
' ========================================================================================
FUNCTION GraphCtx_GetVirtualBufferWidth (BYVAL hwnd AS DWORD) AS LONG

   LOCAL pdata AS GRAPHCTXDATA PTR    ' // Pointer to the control's data

   ' // Checks the validity of the parameter
   IF ISFALSE hwnd THEN EXIT FUNCTION
   ' // Gets a pointer to the control's data
   pdata = GetWindowLong(hwnd, 0)
   IF ISFALSE pdata THEN EXIT FUNCTION
   FUNCTION = @pdata.m_vWidth

END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the height of the virtual buffer.
' Parameter:
' Return value:
' * The width of the virtual buffer.
' ========================================================================================
FUNCTION GraphCtx_GetVirtualBufferHeight (BYVAL hwnd AS DWORD) AS LONG

   LOCAL pdata AS GRAPHCTXDATA PTR    ' // Pointer to the control's data

   ' // Checks the validity of the parameter
   IF ISFALSE hwnd THEN EXIT FUNCTION
   ' // Gets a pointer to the control's data
   pdata = GetWindowLong(hwnd, 0)
   IF ISFALSE pdata THEN EXIT FUNCTION
   FUNCTION = @pdata.m_vHeight

END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the value of the stretchable property
' Parameter:
' * hwnd = Control's window handle
' Return value:
' * TRUE or FALSE
' ========================================================================================
FUNCTION GraphCtx_IsStretchable (BYVAL hwnd AS DWORD) AS LONG

   LOCAL pdata AS GRAPHCTXDATA PTR    ' // Pointer to the control's data

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
FUNCTION GraphCtx_SetStretchable (BYVAL hwnd AS DWORD, BYVAL bStretchable AS LONG) AS LONG

   LOCAL pdata AS GRAPHCTXDATA PTR    ' // Pointer to the control's data

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
FUNCTION GraphCtx_GetStretchMode (BYVAL hwnd AS DWORD) AS LONG

   LOCAL pdata AS GRAPHCTXDATA PTR    ' // Pointer to the control's data

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
FUNCTION GraphCtx_SetStretchMode (BYVAL hwnd AS DWORD, BYVAL nStretchMode AS LONG) AS LONG

   LOCAL pdata AS GRAPHCTXDATA PTR    ' // Pointer to the control's data

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
FUNCTION GraphCtx_IsResizable (BYVAL hwnd AS DWORD) AS LONG

   LOCAL pdata AS GRAPHCTXDATA PTR    ' // Pointer to the control's data

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
FUNCTION GraphCtx_SetResizable (BYVAL hwnd AS DWORD, BYVAL bResizable AS LONG) AS LONG

   LOCAL pdata AS GRAPHCTXDATA PTR    ' // Pointer to the control's data

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
' Prints the bitmap using the current default printer and printer settings.
' Parameters:
' * hwnd = Control's window handle
' Return Value: Returns %TRUE if the bitmap has been printed successfully, or %FALSE otherwise.
' ========================================================================================
FUNCTION GraphCtx_PrintBitmap (BYVAL hwnd AS DWORD) AS LONG

   LOCAL pdata AS GRAPHCTXDATA PTR    ' // Pointer to the control's data

   ' // Checks the validity of the parameter
   IF ISFALSE hwnd THEN EXIT FUNCTION
   ' // Gets a pointer to the control's data
   pdata = GetWindowLong(hwnd, 0)
   IF ISFALSE pdata THEN EXIT FUNCTION

   ' // Get the name of the default printer
   LOCAL wszPrinterName AS WSTRINGZ * %MAX_PATH
   GetProfileStringW("WINDOWS", "DEVICE", "", wszPrinterName, SIZEOF(wszPrinterName))
   wszPrinterName = PARSE$(wszPrinterName, 1)
   IF wszPrinterName = "" THEN EXIT FUNCTION

   ' // Open the printer
   LOCAL hPrinter AS DWORD
   IF OpenPrinterW(wszPrinterName, hPrinter, BYVAL %NULL) = 0 THEN EXIT FUNCTION
   ' // Allocate a buffer of the correct size
   LOCAL dwNeeded AS DWORD
   LOCAL bufferDoc AS STRING
   dwNeeded = DocumentPropertiesW(%NULL, hPrinter, wszPrinterName, BYVAL %NULL, BYVAL %NULL, 0)
   bufferDoc = SPACE$(dwNeeded)
   ' // Retrieve the printer configuration data
   LOCAL nRet AS LONG
   nRet = DocumentPropertiesW(%NULL, hPrinter, wszPrinterName, BYVAL STRPTR(bufferDoc), BYVAL %NULL, %DM_OUT_BUFFER)
   IF nRet <> %IDOK THEN GOTO LExit
   ' // Cast it to a DEVMODEW structure
   LOCAL pDevMode AS DEVMODEW PTR
   pDevMode = STRPTR(bufferDoc)
   ' // Create a device context for the printer
   LOCAL hdc AS DWORD
   hdc = CreateDCW(wszPrinterName, wszPrinterName, BYVAL %NULL, BYVAL pDevMode)
   IF hdc = %NULL THEN GOTO LExit

   ' // Print the bitmap
   LOCAL di AS DOCINFOW
   di.cbSize = SIZEOF(DOCINFOW)
   LOCAL wszDocName AS WSTRINGZ * 260
   wszDocName = "GraphCtx Bitmap"
   di.lpszDocName = VARPTR(wszDocName)
   nRet = StartDocW(hdc, di)
   IF nRet <= 0 THEN GOTO LExit
   ' // Draw the image
   SendMessage hwnd, %WM_PRINTCLIENT, hdc, 0
   EndPage(hdc)
   EndDoc(hdc)

LExit:

   ' // Finished with the printer
   IF hPrinter THEN ClosePrinter(hPrinter)
   ' // Cleanup
   IF hdc THEN DeleteDC(hdc)

END FUNCTION
' ========================================================================================
