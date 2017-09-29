' ########################################################################################
' DrawRect sample, showing a completely flicker free way to draw a
' hollow rectangle in a window, by using a global memDC as buffer
' and temporary memDC for drawing, before copying all to screen.
'
' Also included is code for grid background points via pattern brush.
' Note: pattern brushes can only be 8x8 pixels in Win95. In all other
' systems, Win98 and up, brush can be larger. Commented code - hope
' it's understandable..
'
' Public Domain by Borje Hagsten, March 2003
'
' Can be used as base for a paint program, or why not a visual designer?
' Just add a few bytes of code for creating and resizing controls with
' the mouse, and you have made yourself your own visual designer..
' Adapted by José Roca, April 2009.
' ########################################################################################

#COMPILE EXE
#DIM ALL
#INCLUDE ONCE "windows.inc"

%IDC_CHK1 = 121
%IDC_CHK2 = 122

GLOBAL cGridX AS LONG, cGridY AS LONG, gShowGrid AS LONG, gSnapToGrid AS LONG
GLOBAL ghBitmap AS DWORD, ghBrush AS DWORD, gMemDC AS DWORD
GLOBAL gPt AS POINTAPI, gRc AS RECT

' ========================================================================================
' Main
' ========================================================================================
FUNCTION WinMain (BYVAL hInstance AS DWORD, BYVAL hPrevInstance AS DWORD, BYVAL lpszCmdLine AS ASCIIZ PTR, BYVAL nCmdShow AS LONG) AS LONG

   LOCAL hWndMain    AS DWORD
   LOCAL hCtl        AS DWORD
   LOCAL hFont       AS DWORD
   LOCAL wcex        AS WNDCLASSEX
   LOCAL szClassName AS ASCIIZ * 80
   LOCAL rc          AS RECT
   LOCAL szCaption   AS ASCIIZ * 255
   LOCAL nLeft       AS LONG
   LOCAL nTop        AS LONG
   LOCAL nWidth      AS LONG
   LOCAL nHeight     AS LONG

   hFont = GetStockObject(%ANSI_VAR_FONT)

   ' Register the window class
   szClassName        = "MyClassName"
   wcex.cbSize        = SIZEOF(wcex)
   wcex.style         = %CS_HREDRAW OR %CS_VREDRAW
   wcex.lpfnWndProc   = CODEPTR(WndProc)
   wcex.cbClsExtra    = 0
   wcex.cbWndExtra    = 0
   wcex.hInstance     = hInstance
   wcex.hCursor       = LoadCursor (%NULL, BYVAL %IDC_ARROW)
   wcex.hbrBackground = %COLOR_3DFACE + 1
   wcex.lpszMenuName  = %NULL
   wcex.lpszClassName = VARPTR(szClassName)
   wcex.hIcon         = LoadIcon (%NULL, BYVAL %IDI_APPLICATION) ' Sample, if resource icon: LoadIcon(hInst, "APPICON")
   wcex.hIconSm       = LoadIcon (%NULL, BYVAL %IDI_APPLICATION) ' Remember to set small icon too..
   RegisterClassEx wcex

   ' Window caption
   szCaption = "DrawRect and Grid Sample"

   ' Retrieve the size of the working area
   SystemParametersInfo %SPI_GETWORKAREA, 0, BYVAL VARPTR(rc), 0

   ' Calculate the position and size of the window
   nWidth  = 488
   nHeight = 323
   nLeft   = ((rc.nRight - rc.nLeft) \ 2) - nWidth \ 2
   nTop    = ((rc.nBottom - rc.nTop) \ 2) - (nHeight \ 2)

   ' Create a window using the registered class
   hWndMain = CreateWindowEx(%WS_EX_CONTROLPARENT, _           ' extended style
                             szClassName, _                    ' window class name
                             szCaption, _                      ' window caption
                             %WS_OVERLAPPEDWINDOW OR _
                             %WS_CLIPCHILDREN, _               ' window styles
                             nLeft, _                          ' initial x position
                             nTop, _                           ' initial y position
                             nWidth, _                         ' initial x size
                             nHeight, _                        ' initial y size
                             %NULL, _                          ' parent window handle
                             0, _                              ' window menu handle
                             hInstance, _                      ' program instance handle
                             BYVAL %NULL)                      ' creation parameters

   hCtl = CreateWindowEx(0, "Button", "&Snap to grid ", _
               %WS_CHILD OR %WS_VISIBLE OR %WS_TABSTOP OR %BS_AUTOCHECKBOX, _
               383, 211, 90, 17, hWndMain, %IDC_CHK1, GetModuleHandle(""), BYVAL %NULL)
   IF hFont THEN SendMessage hCtl, %WM_SETFONT, hFont, 0
   SendMessage hCtl, %BM_SETCHECK, %BST_CHECKED, 0

   hCtl = CreateWindowEx(0, "Button", "&Show grid ", _
               %WS_CHILD OR %WS_VISIBLE OR %WS_TABSTOP OR %BS_AUTOCHECKBOX, _
               383, 231, 90, 16, hWndMain, %IDC_CHK2, GetModuleHandle(""), BYVAL %NULL)
   IF hFont THEN SendMessage hCtl, %WM_SETFONT, hFont, 0
   SendMessage hCtl, %BM_SETCHECK, %BST_CHECKED, 0

   hCtl = CreateWindowEx(0, "Button", "&Quit", _
               %WS_CHILD OR %WS_VISIBLE OR %WS_TABSTOP OR %BS_FLAT, _
               383, 260, 90, 23, hWndMain, %IDCANCEL, GetModuleHandle(""), BYVAL %NULL)
   IF hFont THEN SendMessage hCtl, %WM_SETFONT, hFont, 0

   ' Show the window
   ShowWindow hWndMain, nCmdShow
   UpdateWindow hWndMain

   ' Message handler loop
   LOCAL uMsg AS tagMsg
   WHILE GetMessage(uMsg, %NULL, 0, 0)
      IF ISFALSE IsDialogMessage(hWndMain, uMsg) THEN
         TranslateMessage uMsg
         DispatchMessage uMsg
      END IF
   WEND

   FUNCTION = uMsg.wParam

END FUNCTION
' ========================================================================================

' ========================================================================================
' Main Window procedure
' ========================================================================================
FUNCTION WndProc (BYVAL hWnd AS DWORD, BYVAL wMsg AS DWORD, BYVAL wParam AS DWORD, BYVAL lParam AS LONG) AS LONG

   LOCAL  lRes AS LONG
   LOCAL  hdc  AS DWORD
   LOCAL  rc   AS RECT
   STATIC hCur AS DWORD

   SELECT CASE wMsg

      CASE %WM_CREATE
         cGridX      = 10     ' Horizontal grid size
         cGridY      = 10     ' Vertical grid size
         gShowGrid   = 1      ' Show grid at start
         gSnapToGrid = 1      ' Snap drawing to grid at start
         hCur        = LoadCursor(0, BYVAL %IDC_CROSS)  ' Store handle of cursot to use at draw
         ghBrush     = MakeGridBrush(hWnd)              ' and create grid brush
         EXIT FUNCTION

      CASE %WM_COMMAND
         SELECT CASE LO(WORD, wParam)
            CASE %IDCANCEL
               IF HI(WORD, wParam) = %BN_CLICKED THEN
                  SendMessage hWnd, %WM_CLOSE, 0, 0
                  EXIT FUNCTION
               END IF
            CASE %IDC_CHK1
               IF HI(WORD, wParam) = %BN_CLICKED THEN
                  gSnapToGrid = SendMessage(GetDlgItem(hWnd, LO(WORD, wParam)), %BM_GETCHECK, 0, 0)
                  EXIT FUNCTION
               END IF
            CASE %IDC_CHK2
               IF HI(WORD, wParam) = %BN_CLICKED THEN
                  gShowGrid = SendMessage(GetDlgItem(hWnd, LO(WORD, wParam)), %BM_GETCHECK, 0, 0)
                  RedrawWindow hWnd, BYVAL %NULL, 0, _
                               %RDW_ERASE OR %RDW_INVALIDATE OR %RDW_UPDATENOW
                  EXIT FUNCTION
               END IF
         END SELECT

      CASE %WM_ERASEBKGND
         IF gShowGrid AND ghBrush THEN
            hdc = wParam
            GetClientRect hWnd, rc
            FillRect hdc, rc, ghBrush
            FUNCTION = 1
            EXIT FUNCTION
         END IF

      CASE %WM_SETCURSOR
        ' If mouse button is pressed, over-ride default cursor and
        ' set "own", here cross cursor.
        IF wParam = hWnd AND HI(WORD, lParam) = %WM_LBUTTONDOWN THEN
           IF GetCursor <> hCur THEN SetCursor hCur
           FUNCTION = 1
           EXIT FUNCTION
        END IF

      CASE %WM_LBUTTONDOWN, %WM_LBUTTONDBLCLK
         ' Start selrect draw
         selRectBegin hWnd
         EXIT FUNCTION

      CASE %WM_MOUSEMOVE
         ' If mouse button is down while moved, draw rect
         IF (wParam AND %MK_LBUTTON) THEN
            selRectDraw hWnd, LO(WORD, lParam), HI(WORD, lParam)
            EXIT FUNCTION
         END IF

      CASE %WM_LBUTTONUP
         ' Mouse button released - end draw
         selRectEnd hWnd
         ' Now, when mouse button is released, global RECT (gRc)
         ' will hold coordinates of final drawn rect. If you
         ' for example want to select a group of controls or
         ' other objects, you can use IntersectRect API to see
         ' if parts of other RECT's are withing this global rect.
         ' Or use the coordinates to create a control/object of
         ' this size, whatever..
         EXIT FUNCTION

      CASE %WM_DESTROY
         ' Delete what we created on exit, to avoid mem leaks
         IF ghBrush THEN DeleteObject ghBrush
         IF ghBitmap THEN DeleteObject SelectObject(gMemDC, ghBitmap)
         IF gMemDC THEN DeleteDC gMemDC  'should already be deleted, but to make sure..
         PostQuitMessage 0
         EXIT FUNCTION

   END SELECT

   FUNCTION = DefWindowProc(hWnd, wMsg, wParam, lParam)

END FUNCTION
' ========================================================================================

' ========================================================================================
' Initialize sel rect drawing
' Copy dialog to global "screen buffer" for use as base for flicker
' free drawing and later restore.
' ========================================================================================
SUB selRectBegin (BYVAL hWnd AS DWORD)

   LOCAL hDC AS DWORD, hBit AS DWORD, pt AS POINT, rc AS RECT

   SetCapture hWnd                 ' Set capture to desired window
   GetClientRect hWnd, rc          ' Get client size
#IF %DEF(%USEPBDECL)
   MapWindowPoints hWnd, 0, VARPTR(rc), 2  ' Map client coordiantes to screen
#ELSE
   MapWindowPoints hWnd, 0, rc, 2  ' Map client coordiantes to screen
#ENDIF
   ClipCursor rc                   ' Clip cursor to client coordinates

   GetCursorPos gPt                ' Get cursor pos on screen
   ScreenToClient hWnd, gPt        ' Convert to client coordinates

   IF gSnapToGrid THEN
      gPt.x = (gPt.x \ cGridX) * cGridX  ' If snap to grid, calculate grid positin
      gPt.y = (gPt.y \ cGridY) * cGridY  ' via multiply of integer divide result
   END IF

   GetClientRect hWnd, rc          ' Create a global memDC and copy window to it.
   hDC      = GetDc(hWnd)
   gMemDC   = CreateCompatibleDC (hDC)
   ghBitmap = CreateCompatibleBitmap(hDC, rc.nRight, rc.nBottom)
   ghBitmap = SelectObject(gMemDC, ghBitmap)

   BitBlt gMemDC, 0, 0, rc.nRight, rc.nBottom, hDC, 0, 0, %SRCCOPY
   ReleaseDc hWnd, hDC

END SUB
' ========================================================================================

' ========================================================================================
' perform sel rect drawing
' ========================================================================================
SUB selRectDraw (BYVAL hWnd AS DWORD, BYVAL x AS LONG, BYVAL y AS LONG)

   LOCAL hDC AS DWORD, hBrush AS DWORD, hPen AS DWORD, rc AS RECT
   LOCAL memDC AS DWORD, hBitmap AS DWORD

   IF gSnapToGrid THEN
      ' MS cross cursor has mis-aligned hotspot - it should be at
      ' cross, but is upper-left corner. We should use own cross,
      ' but this is just a sample, so instead cheat and add 4 to pos..
      x = x + 4  ' <- Depends on where hotspot in cursor is..
      y = y + 4
      x = (x \ cGridX) * cGridX  ' First integer divide, then multiply for "grid effect".
      y = (y \ cGridY) * cGridY
   END IF

   ' Must make sure rect coordinates are correct,
   ' so right side always is larger than left, etc.
   IF (gPt.x <= x) AND (gPt.y >= y) THEN
      SetRect gRc, gPt.x, y, x, gPt.y
   ELSEIF (gPt.x > x) AND (gPt.y > y) THEN
      SetRect gRc, x, y, gPt.x, gPt.y
   ELSEIF (gPt.x >= x) AND (gPt.y <= y) THEN
      SetRect gRc, x, gPt.y, gPt.x, y
   ELSE
      SetRect gRc, gPt.x, gPt.y, x, y
   END IF

   GetClientRect hWnd, rc
   IF gRc.nLeft = gRc.nRight  THEN INCR gRc.nRight  '<- Ensure we never get a "null rect"
   IF gRc.nTop  = gRc.nBottom THEN INCR gRc.nBottom

   hDC     = GetDc(hWnd)
   memDC   = CreateCompatibleDC (hDC)  ' Create temporary memDC to draw in
   hBitmap = CreateCompatibleBitmap(hDC, rc.nRight, rc.nBottom)
   hBitmap = SelectObject(memDC, hBitmap)
   hBrush  = SelectObject(memDC, GetStockObject(%NULL_BRUSH))  ' For hollow rect

   BitBlt memDC, 0, 0, rc.nRight, rc.nBottom, gMemDC, 0, 0, %SRCCOPY  ' Copy original buffer to temp DC

   hPen = SelectObject(memDC, CreatePen(%PS_SOLID, 2, GetSysColor(%COLOR_3DSHADOW))) 'create pen
   Rectangle memDC, gRc.nLeft, gRc.nTop, gRc.nRight + 1, gRc.nBottom + 1             'draw rect
   DeleteObject SelectObject(memDC, hPen)

   BitBlt hDC, 0, 0, rc.nRight, rc.nBottom, memDC, 0, 0, %SRCCOPY  ' Copy temp DC to window

   SelectObject memDC, hBrush
   IF hBitmap  THEN DeleteObject SelectObject(memDC, hBitmap)  ' Clean up to avoid mem leaks
   IF memDC THEN DeleteDC memDC
   ReleaseDc hWnd, hDC

END SUB
' ========================================================================================

' ========================================================================================
' End sel rect drawing
' Copy original window buffer back to screen to wipe out drawn
' rectangle, delete global memDC, release capture and clipped cursor.
' ========================================================================================
SUB selRectEnd (BYVAL hWnd AS DWORD)

   LOCAL hDC AS DWORD, rc AS RECT

   hDC = GetDc(hWnd)
   GetClientRect hWnd, rc
   BitBlt hDC, 0, 0, rc.nRight, rc.nBottom, gMemDC, 0, 0, %SRCCOPY
   ReleaseDc hWnd, hDC

   IF ghBitmap  THEN
      DeleteObject SelectObject(gMemDC, ghBitmap)
      ghBitmap  = 0
   END IF
   IF gMemDC THEN
      DeleteDC gMemDC
      gMemDC = 0
   END IF
   ReleaseCapture

   ClipCursor BYVAL %NULL

END SUB
' ========================================================================================

' ========================================================================================
' Create a patterned brush for grid. By using this, grid draw becomes
' very quick, even on full size dialogs. Must warn though - in Win95,
' brush can be max 8x8 pixels. In Win98 and later, brush can be bigger,
' so never a problem there.
' ========================================================================================
FUNCTION MakeGridBrush(BYVAL hDlg AS DWORD) AS DWORD

   LOCAL hDC AS DWORD, memDC AS DWORD, hBitmap AS DWORD, hBitmapOld AS DWORD, rc AS RECT

   hDC        = GetDC(hDlg)
   memDC      = CreateCompatibleDC(hDC)
   hBitmap    = CreateCompatibleBitmap(hDC, cGridX, cGridY)
   hBitmapOld = SelectObject(memDC, hBitmap)

   rc.nRight  = cGridX
   rc.nBottom = cGridY
   FillRect memDC, rc, GetSysColorBrush(%COLOR_3DFACE)

   SetPixelV memDC, 0, 0, 0      ' Paint dots in all four corners
   SetPixelV memDC, 0, cGridY, 0
   SetPixelV memDC, cGridX, 0, 0
   SetPixelV memDC, cGridX, cGridY, 0

   FUNCTION = CreatePatternBrush(hBitmap)

   SelectObject memDC, hBitmapOld  ' Clean up to avoid memory leaks
   DeleteObject hBitmap
   DeleteDC memDC
   ReleaseDC hDlg, hDC

END FUNCTION
' ========================================================================================
