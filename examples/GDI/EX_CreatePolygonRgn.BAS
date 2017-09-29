' ########################################################################################
' Dynamic non-rectangular dialog
' Based on an example posted by Lance Edmonds.
' Concept based on Public Domain VB code, but completely rewritten so that it no longer
' resembles the original!
' http://www.powerbasic.com/support/forums/Archives/Archive-000002/HTML/20020808-7-000294.html
' ########################################################################################

#COMPILE EXE
#DIM ALL
#INCLUDE "windows.inc"

%IDOK       = 1
%IDSTATIC   = 2
%NUM_POINTS = 8

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
   wcex.hIcon         = LoadIcon (%NULL, BYVAL %IDI_APPLICATION)
   wcex.hIconSm       = LoadIcon (%NULL, BYVAL %IDI_APPLICATION)
   RegisterClassEx wcex

   ' Window caption
   szCaption = "Stars in my eyes!?"

   ' Retrieve the size of the working area
   SystemParametersInfo %SPI_GETWORKAREA, 0, rc, 0

   ' Calculate the position and size of the window
   nWidth  = 540
   nHeight = 406
   nLeft   = ((rc.nRight - rc.nLeft) \ 2) - nWidth \ 2
   nTop    = ((rc.nBottom - rc.nTop) \ 2) - (nHeight \ 2)

   ' Create a window using the registered class
   hWndMain = CreateWindowEx(%WS_EX_CONTROLPARENT, _           ' extended style
                             szClassName, _                    ' window class name
                             szCaption, _                      ' window caption
                             %WS_CAPTION OR %WS_SYSMENU, _     ' window style
                             nLeft, _                          ' initial x position
                             nTop, _                           ' initial y position
                             nWidth, _                         ' initial x size
                             nHeight, _                        ' initial y size
                             %NULL, _                          ' parent window handle
                             0, _                              ' window menu handle
                             hInstance, _                      ' program instance handle
                             BYVAL %NULL)                      ' creation parameters

   hCtl = CreateWindowEx(0, "Static", "WOW!!! PB rocks!", _
               %WS_CHILD OR %WS_VISIBLE OR %SS_CENTER, _
               210, 179, 120, 23, hWndMain, %IDSTATIC, hInstance, BYVAL %NULL)
   IF hFont THEN SendMessage hCtl, %WM_SETFONT, hFont, 0

   hCtl = CreateWindowEx(0, "Button", "OK", _
               %WS_CHILD OR %WS_VISIBLE OR %WS_TABSTOP OR %BS_FLAT, _
               240, 203, 60, 23, hWndMain, %IDOK, hInstance, BYVAL %NULL)
   IF hFont THEN SendMessage hCtl, %WM_SETFONT, hFont, 0

   ' Show the window
   ShowWindow hWndMain, nCmdShow
   UpdateWindow hWndMain

   ' Set the timer
   SetTimer hWndMain, 0, 750, %NULL

   ' Message handler loop
   LOCAL uMsg AS tagMsg
   WHILE GetMessage(uMsg, %NULL, 0, 0)
      IF ISFALSE IsDialogMessage(hWndMain, uMsg) THEN
         TranslateMessage uMsg
         DispatchMessage uMsg
      END IF
   WEND

   ' Kill the timer
   KillTimer hWndMain, 0

   FUNCTION = uMsg.wParam

END FUNCTION
' ========================================================================================

' ========================================================================================
' Main Window procedure
' ========================================================================================
FUNCTION WndProc (BYVAL hWnd AS DWORD, BYVAL wMsg AS DWORD, BYVAL wParam AS DWORD, BYVAL lParam AS LONG) AS LONG

   SELECT CASE wMsg

      CASE %WM_TIMER
         SetRegion hWnd
         EXIT FUNCTION

      CASE %WM_COMMAND
         SELECT CASE LO(WORD, wParam)
            CASE %IDOK, %IDCANCEL
               IF HI(WORD, wParam) = %BN_CLICKED THEN
                  SendMessage hWnd, %WM_CLOSE, 0, 0
                  EXIT FUNCTION
               END IF
         END SELECT

      CASE %WM_DESTROY
         PostQuitMessage 0
         EXIT FUNCTION

   END SELECT

   FUNCTION = DefWindowProc(hWnd, wMsg, wParam, lParam)

END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the region.
' ========================================================================================
SUB SetRegion (BYVAL hWnd AS LONG)

   LOCAL x, y, z AS LONG
   LOCAL cx, cy, dt, th, pi AS SINGLE
   LOCAL hRgn AS DWORD
   LOCAL rc AS RECT
   STATIC NUM_POINTS AS LONG

   NUM_POINTS = RND(4,30) * 2
   REDIM w(0 TO 1) AS SINGLE
   REDIM h(0 TO 1) AS SINGLE
   REDIM rgPoints(1 TO NUM_POINTS) AS POINT

   GetWindowRect hWnd, rc
   x = rc.nRight - rc.nLeft
   y = rc.nBottom - rc.nTop

   pi = 3.1415926535!
   cx = x / 2
   cy = y / 2
   w(0) = x& * 0.15! : w(1) = x * 0.5!
   h(0) = y& * 0.15! : h(1) = y * 0.5!
   dt = 2 * pi / NUM_POINTS
   th = pi / 2!
   FOR z = 1 TO NUM_POINTS
      rgPoints(NUM_POINTS - z + 1).x = cx + w(z MOD 2) * COS(th)
      rgPoints(NUM_POINTS - z + 1).y = cy + h(z MOD 2) * SIN(th)
      th = th + dt
   NEXT
   hRgn = CreatePolygonRgn(rgPoints(1), NUM_POINTS, %ALTERNATE)
   SetWindowRgn hWnd, hRgn, %TRUE

END SUB
' ========================================================================================
