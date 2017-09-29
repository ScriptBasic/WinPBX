' ########################################################################################
' Drawing a Shaded Rectangle
' To draw a shaded rectangle, define a TRIVERTEX array with two elements and a single
' GRADIENT_RECT structure. The following code example shows how to draw a shaded rectangle
' using the GradientFill function with the GRADIENT_FILL_RECT mode defined.
' ########################################################################################

' CSED_PBWIN - Use the PBWIN compiler
#COMPILE EXE
#DIM ALL
%UNICODE = 1

' // Include files for external files
#INCLUDE ONCE "CWindow.inc"   ' // CWindow class

' ========================================================================================
' Draws a shaded rectangle using the GradientFill function.
' ========================================================================================
SUB DrawShadedRectangle (BYVAL hWnd AS DWORD, BYVAL hdc AS DWORD)

   ' // Create an array of TRIVERTEX structures that describe
   ' // positional and color values for each vertex. For a rectangle,
   ' // only two vertices need to be defined: upper-left and lower-right.

   DIM vertex(1) AS TRIVERTEX

   vertex(0).x     = 50
   vertex(0).y     = 100
   vertex(0).Red   = &H0000
   vertex(0).Green = &H8000
   vertex(0).Blue  = &H8000
   vertex(0).Alpha = &H0000

   vertex(1).x     = 450
   vertex(1).y     = 200
   vertex(1).Red   = &H0000
   vertex(1).Green = &HD000
   vertex(1).Blue  = &HD000
   vertex(1).Alpha = &H0000

   ' // Create a GRADIENT_TRIANGLE structure that
   ' // references the TRIVERTEX vertices.

   DIM gRect AS GRADIENT_RECT

   gRect.UpperLeft  = 0
   gRect.LowerRight = 1

   ' // Draw a shaded rectangle.
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
   pWindow.CreateWindow(%NULL, "Drawing a Shaded Rectangle", 0, 0, 0, 0, 0, 0, CODEPTR(WindowProc))
   ' // Change the background color
   pWindow.Brush = %COLOR_WINDOW + 1
   ' // Set the client size
   pWindow.SetClientSize 500, 300
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

   LOCAL  hdc AS DWORD
   LOCAL  ps  AS PAINTSTRUCT

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
         hdc = BeginPaint(hwnd, ps)
         DrawShadedRectangle hwnd, hdc
         EndPaint hwnd, ps
         EXIT FUNCTION

     CASE %WM_DESTROY
         PostQuitMessage 0
         EXIT FUNCTION

   END SELECT

   FUNCTION = DefWindowProc(hwnd, wMsg, wParam, lParam)

END FUNCTION
' ========================================================================================
