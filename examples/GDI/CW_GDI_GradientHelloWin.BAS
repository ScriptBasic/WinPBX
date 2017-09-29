' ========================================================================================
' The following example draws an horizontal gradient in the client area of the main window.
' ========================================================================================

' CSED_PBWIN - Use the PBWIN compiler
#COMPILE EXE
#DIM ALL
%UNICODE = 1

' // Include files for external files
#INCLUDE ONCE "CWindow.inc"   ' // CWindow class

' ========================================================================================
' Draws the gradient
' ========================================================================================
SUB DrawGradient (BYVAL hwnd AS DWORD, BYVAL hdc AS DWORD)

   LOCAL rc AS RECT
   DIM   vertex(1) AS TRIVERTEX

   GetClientRect hwnd, rc

   vertex(0).x      = 0
   vertex(0).y      = 0
   vertex(0).Red    = &HFF00
   vertex(0).Green  = &HFF00
   vertex(0).Blue   = &H0000
   vertex(0).Alpha  = &H0000

   vertex(1).x      = rc.nRight - rc.nLeft
   vertex(1).y      = rc.nBottom - rc.nTop
   vertex(1).Red    = &H8000
   vertex(1).Green  = &H0000
   vertex(1).Blue   = &H0000
   vertex(1).Alpha  = &H0000

   LOCAL gRect AS GRADIENT_RECT

   gRect.UpperLeft  = 0
   gRect.LowerRight = 1

   GradientFill hDc, vertex(0), 2, gRect, 1, %GRADIENT_FILL_RECT_H

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
   pWindow.CreateWindow(%NULL, "GradientFill Demo", 0, 0, 0, 0, 0, 0, CODEPTR(WindowProc))
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

   LOCAL rc AS RECT
   LOCAL hdc AS DWORD
   LOCAL ps  AS PAINTSTRUCT

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
         hdc = BeginPaint(hwnd, ps)                            ' prepares the specified window for painting
         DrawGradient hwnd, hdc
         SetBkMode hDC, %TRANSPARENT                           ' sets the background mode
         SetTextColor hDC, %WHITE                              ' sets the text color
         GetClientRect hwnd, rc                                ' retrieves the coordinates of the window's client area.
         DrawText hdc, "Hello, Windows!", -1, rc, _            ' draws formatted text in the specified rectangle.
                  %DT_SINGLELINE OR %DT_CENTER OR %DT_VCENTER
         EndPaint(hwnd, ps)                                    ' marks the end of painting in the specified window.
         EXIT FUNCTION

      CASE %WM_ERASEBKGND
         hdc = wParam
         DrawGradient hwnd, hdc
         FUNCTION = %TRUE
         EXIT FUNCTION

     CASE %WM_DESTROY
         PostQuitMessage 0
         EXIT FUNCTION

   END SELECT

   FUNCTION = DefWindowProc(hwnd, wMsg, wParam, lParam)

END FUNCTION
' ========================================================================================
