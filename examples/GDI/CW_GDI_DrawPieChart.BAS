' ########################################################################################
' You can use the line and curve functions to draw a pie chart. The primary function used
' to draw pie charts is the AngleArc function, which requires you to supply the coordinates
' of the center of the pie, the radius of the pie, a start angle, and a sweep angle.
' To fill the pie chart using the current brush, embed the call to AngleArc in a path bracket.
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
   pWindow.CreateWindow(%NULL, "Drawing a Pie Chart", 0, 0, 0, 0, 0, 0, CODEPTR(WindowProc))
   ' // Change the background color
   pWindow.Brush = %COLOR_WINDOW + 1
   ' // Set the client size
   pWindow.SetClientSize 560, 380
   ' // Center the window
   pWindow.CenterWindow

   ' // Default message pump (you can replace it with your own)
   pWindow.DoEvents(nCmdShow)

END FUNCTION
' ========================================================================================

' ========================================================================================
' Main window procedure.
' ========================================================================================
FUNCTION WindowProc (BYVAL hwnd AS DWORD, BYVAL wMsg AS DWORD, BYVAL wParam AS DWORD, BYVAL lParam AS LONG) AS LONG

   LOCAL rc AS RECT
   LOCAL hDC AS DWORD
   LOCAL ps AS PAINTSTRUCT
   LOCAL nX AS LONG
   LOCAL nY AS LONG
   LOCAL dwRadius AS DWORD
   LOCAL xStartAngle AS SINGLE
   LOCAL xSweepAngle AS SINGLE

   SELECT CASE wMsg

      CASE %WM_COMMAND
         SELECT CASE LO(WORD, wParam)

            CASE %IDCANCEL
               IF HI(WORD, wParam) = %BN_CLICKED THEN
                  SendMessage hwnd, %WM_CLOSE, 0, 0
                  EXIT FUNCTION
               END IF

         END SELECT

      CASE %WM_PAINT
         nX = 300
         nY = 190
         dwRadius = 150
         xStartAngle = 30
         xSweepAngle = 300
         hDC = BeginPaint(hWnd, ps)
         BeginPath hdc
         SelectObject hdc, GetStockObject(%GRAY_BRUSH)
         MoveToEx hdc, nX, nY, BYVAL %NULL
         AngleArc hdc, nX, nY, dwRadius, xStartAngle, xSweepAngle
         LineTo hdc, nX, nY
         EndPath hdc
         StrokeAndFillPath hdc
         EndPaint(hWnd, ps)
         EXIT FUNCTION

      CASE %WM_DESTROY
         PostQuitMessage 0
         EXIT FUNCTION

   END SELECT

   FUNCTION = DefWindowProc(hwnd, wMsg, wParam, lParam)

END FUNCTION
' ========================================================================================