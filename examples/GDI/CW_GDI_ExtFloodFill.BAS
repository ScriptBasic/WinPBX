' ########################################################################################
' The following example demonstrates the use of the ExtFloodFill function.
' ########################################################################################

' CSED_PBWIN - Use the PBWIN compiler
#COMPILE EXE
#DIM ALL
%UNICODE = 1

' // Include files for external files
#INCLUDE ONCE "CWindow.inc"   ' // CWindow class

' ========================================================================================
' Draws filled boxes
' ========================================================================================
SUB DrawFilledBoxes (BYVAL hDC AS LONG)

   LOCAL i AS LONG
   LOCAL x AS LONG
   LOCAL hPen AS LONG
   LOCAL hOldPen AS LONG
   LOCAL hBrush AS LONG
   LOCAL hOldBrush AS LONG

   ' // Create a pen: style, width, color
   hPen = CreatePen (%PS_SOLID, 0, RGB(000, 000, 000))
   ' // Select the pen (use this color for now) and save old one
   hOldPen = SelectObject(hDC, hPen)

   ' // Draw the boxes
   FOR i = 0 TO 7
      FOR x = 0 TO 9
         Rectangle hDC, x * 50, i * 50, (x * 50) + 49, (i * 50) + 49
      NEXT
   NEXT

   ' // Fill the boxes with color
   FOR i = 0 TO 7
      FOR x = 0 TO 9
         hBrush = CreateSolidBrush(RGB(0, 0, x * i * 10))
         hOldBrush = SelectObject(hDC, hBrush)
         ExtFloodFill hDC, (x * 50) + 25, (i * 50) + 25, RGB(255, 255, 255), %FLOODFILLSURFACE
         SelectObject hDC, hOldBrush
         DeleteObject hBrush
      NEXT
   NEXT

   ' // Select the old pen
   SelectObject hDC, hOldPen
   ' // Delete the pen
   DeleteObject hPen

END SUB
' ========================================================================================

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
   pWindow.CreateWindow(%NULL, "ExtFloodFill Demo", 0, 0, 0, 0, 0, 0, CODEPTR(WindowProc))
   ' // Change the background color
   pWindow.Brush = %COLOR_WINDOW + 1
   ' // Set the client size
   pWindow.SetClientSize 500, 320
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

   LOCAL  rc AS RECT
   LOCAL  hDC AS DWORD
   LOCAL  ps AS PAINTSTRUCT
   LOCAL  hBitmap AS DWORD
   LOCAL  hOldBitmap AS DWORD
   LOCAL  hTmpDC AS DWORD
   STATIC hMemDC AS DWORD

   SELECT CASE wMsg

      CASE %WM_CREATE
        GetClientRect hwnd, rc
        hTmpDC = GetDC(%NULL)
        hMemDC = CreateCompatibleDC(hTmpDC)
        hBitmap  = CreateCompatibleBitmap(hTmpDC, rc.nRight - rc.nLeft, rc.nBottom - rc.nTop)
        hOldBitmap  = SelectObject(hMemDC, hBitmap)
        FillRect hMemDC, rc, GetStockObject(%WHITE_BRUSH)
        DrawFilledBoxes hMemDC
        ReleaseDC %NULL, hTmpDC
        EXIT FUNCTION

      CASE %WM_COMMAND
         SELECT CASE LO(WORD, wParam)
            CASE %IDCANCEL
               IF HI(WORD, wParam) = %BN_CLICKED THEN
                  SendMessage hwnd, %WM_CLOSE, 0, 0
                  EXIT FUNCTION
               END IF
         END SELECT
         EXIT FUNCTION

      CASE %WM_PAINT
         hDC = BeginPaint(hWnd, ps)
         BitBlt ps.hDC, 0, 0, ps.rcPaint.nRight, ps.rcPaint.nBottom, hMemDC, 0, 0, %SRCCOPY
         EndPaint(hWnd, ps)
         EXIT FUNCTION

      CASE %WM_DESTROY
         SelectObject hMemDC, hOldBitmap
         DeleteObject hBitmap
         DeleteDC hMemDC
         PostQuitMessage 0
         EXIT FUNCTION

   END SELECT

   FUNCTION = DefWindowProc(hwnd, wMsg, wParam, lParam)

END FUNCTION
' ========================================================================================
