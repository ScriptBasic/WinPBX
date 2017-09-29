' ########################################################################################
' Cursor following eyes.
' Adaptation of the version posted by In Cairns in 2001.
' http://www.powerbasic.com/support/forums/Forum7/HTML/001222.html
' Adapted by José Roca, August 2011.
' ########################################################################################

' CSED_PBWIN - Use the PBWIN compiler
#COMPILE EXE
#DIM ALL
%UNICODE = 1

' // Include files for external files
#INCLUDE ONCE "CWindow.inc"   ' // CWindow class

' ========================================================================================
' Main
' ========================================================================================
FUNCTION WinMain (BYVAL hInstance AS DWORD, BYVAL hPrevInstance AS DWORD, BYVAL lpszCmdLine AS WSTRINGZ PTR, BYVAL nCmdShow AS LONG) AS LONG

   ' // Create an instance of the class
   LOCAL pWindow AS IWindow
   pWindow = CLASS "CWindow"
   IF ISNOTHING(pWindow) THEN EXIT FUNCTION

   ' // Create the main window
   ' // Note: CW_USEDEFAULT is used as the default value When passing 0's as the width and height
   pWindow.CreateWindow(%NULL, "Eyes", 0, 0, 300, 300, %WS_POPUP, %WS_EX_CONTROLPARENT, CODEPTR(WindowProc))
   ' // Change the background color
   pWindow.Brush = %COLOR_WINDOW + 1
   ' // Center the window
   pWindow.CenterWindow

   ' // Default message pump (you can replace it with your own)
   pWindow.DoEvents(nCmdShow)

END FUNCTION
' ========================================================================================

' ========================================================================================
' Main window procedure
' ========================================================================================
FUNCTION WindowProc (BYVAL hwnd AS DWORD, BYVAL wMsg AS DWORD, BYVAL wParam AS DWORD, BYVAL lParam AS LONG) AS LONG

   LOCAL  rc        AS RECT
   LOCAL  ps        AS PAINTSTRUCT
   LOCAL  hPen      AS DWORD
   LOCAL  hPenOld   AS DWORD
   LOCAL  hBrush    AS DWORD
   LOCAL  hBrushOld AS DWORD
   LOCAL  hDC       AS DWORD
   LOCAL  hRgn1     AS DWORD
   LOCAL  hRgn2     AS DWORD
   LOCAL  cPt       AS POINT

   STATIC hBmp      AS DWORD
   STATIC hBmpOld   AS DWORD
   STATIC hMemDC    AS DWORD
   STATIC offSetL   AS POINT
   STATIC offSetR   AS POINT
   STATIC oldCPt    AS POINT
   STATIC hTimer    AS DWORD

   SELECT CASE wMsg

      CASE %WM_CREATE

         ' // Draws the eyeballs
         hDC = GetDC(hWnd)
         BeginPath(hDC)
         Ellipse(hdc, 0, 0, 50, 50)
         Ellipse(hdc, 55, 0, 105, 50)
         EndPath(hDC)

         hRgn1 = PathToRegion(hDC)
         GetRgnBox(hRgn1, rc)
         hRgn2 = CreateRectRgnIndirect(rc)
         CombineRgn(hRgn2, hRgn2, hRgn1, %RGN_AND)
         DeleteObject(hRgn1)

         ' // Creates a memory bitmap
         hMemDC  = CreateCompatibleDC(%NULL)
         hBmp    = CreateCompatibleBitmap(hDC, 34, 34)
         hBmpOld = SelectObject(hMemDC, hBmp)

         ' // Releases the device context
         ReleaseDC(hWnd, hDC)

         ' // Draws the eyeball iris/pupil
         hPen = CreatePen(%PS_SOLID, 1, %BLACK)
         hBrush = CreateSolidBrush(%BLUE)
         hPenOld = SelectObject(hMemDC, hPen)
         hBrushOld = SelectObject(hMemDC, hBrush)
         PatBlt(hMemDC, 0, 0, 34, 34, %WHITENESS)
         Ellipse(hMemDC, 0, 0, 34, 34)
         DeleteObject(SelectObject(hMemDC, hBrushOld))
         hBrush = CreateSolidBrush(%BLACK)
         hBrushOld = SelectObject(hMemDC, hBrush)
         Ellipse(hMemDC, 12, 12, 20, 20)
         DeleteObject (SelectObject(hMemDC, hPenOld) )
         DeleteObject (SelectObject(hMemDC, hBrushOld) )

         SetWindowRgn(hWnd, hRgn2, 1)
         GetWindowRect(hWnd, rc)
         SetWindowPos(hWnd, %HWND_TOPMOST, 0, 0, rc.nRight - rc.nLeft, rc.nBottom - rc.nTop, %SWP_NOMOVE)
         ' // Set a timer for checking cursor movements
         hTimer = SetTimer(hWnd, 1, 50, %NULL)

         EXIT FUNCTION

      CASE %WM_PAINT
'         ps.fErase = 0
         hdc = BeginPaint(hWnd, ps)
         ' // Draw eyeballs
         BitBlt(hdc, 8 + offsetL.x, 8 + offsetL.y, 105, 50, hMemDC, 0, 0, %SRCCOPY)
         BitBlt(hdc, 63 + offsetR.x, 8 + offsetR.y, 105, 50, hMemDC, 0, 0, %SRCCOPY)
         ' // Draw outsides
         hPen = CreatePen(%PS_SOLID, GetSystemMetrics(%SM_CXBORDER) + 2, &H0)
         hPenOld = SelectObject(hdc, hPen)
         Arc(hdc, 0, 0, 50, 50, 0, 0, 0, 0)
         Arc(hdc, 55, 0, 105, 50, 0, 0, 0, 0)
         DeleteObject (SelectObject (hdc, hPenOld))
         EndPaint(hWnd, ps)
         EXIT FUNCTION

      CASE %WM_TIMER
         GetCursorPos cPt
         IF cPt <> oldCpt THEN
            GetWindowRect(hWnd, rc)
            CalculateOffset(rc, offsetL, cPt, 25, 25)
            CalculateOffset(rc, offsetR, cPt, 75, 25)
            oldCpt = cPt
            InvalidateRect(hWnd, BYVAL %NULL, 1)
         END IF
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
         KillTimer(hWnd, 1)
         DeleteObject(SelectObject (hMemDC, hBmpOld))
         DeleteObject(hMemDC)
         PostQuitMessage 0
         EXIT FUNCTION

   END SELECT

   FUNCTION = DefWindowProc(hWnd, wMsg, wParam, lParam)

END FUNCTION
' ========================================================================================

' ========================================================================================
' Calculate offset.
' ========================================================================================
SUB CalculateOffset(BYREF rc AS RECT, BYREF eOffset AS POINT, _
                    BYREF cPt AS POINT, BYVAL xOffset AS LONG, BYVAL yOffset AS LONG)

   LOCAL ePt      AS POINT
   LOCAL distance AS POINT
   LOCAL tRatio   AS LONG

   ' // Find current centre of given eye
   ePt.X = rc.nLeft + xOffset
   ePt.y = rc.nTop + yOffset

   ' // Determine offset from cursor
   distance.X = cPt.X - ePt.X
   distance.Y = cPt.Y - ePt.Y

   ' // If within rotation of eye, zero the offset
   IF ABS(distance.X) < 10 AND ABS(distance.Y) < 10 THEN
      eOffset.X = 0 : eOffset.Y = 0
   ELSE
      ' // Calculate ratio for offset distance calculations
      tRatio = INT(SQR( (distance.X * distance.X) + (distance.Y * distance.Y) ) / 10)
      ' // Convert to eye offset
      eOffset.X = INT(distance.X / tRatio)
      eOffset.Y = INT(distance.Y / tRatio)
   END IF

END SUB
' ========================================================================================
