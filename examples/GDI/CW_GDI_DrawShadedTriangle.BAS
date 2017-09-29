' ########################################################################################
' Drawing a Shaded Triangle
' To draw a shaded triangle, define a TRIVERTEX structure with three elements and a single
' GRADIENT_TRIANGLE structure. The following code example shows how to draw a shaded
' triangle using the GradientFill function with the GRADIENT_FILL_TRIANGLE mode defined.
' ########################################################################################

' CSED_PBWIN - Use the PBWIN compiler
#COMPILE EXE
#DIM ALL
%UNICODE = 1

' // Include files for external files
#INCLUDE ONCE "CWindow.inc"   ' // CWindow class

' ========================================================================================
' Draws a shaded triangle using the GradientFill function.
' ========================================================================================
SUB DrawShadedTriangle (BYVAL hWnd AS DWORD, BYVAL hdc AS DWORD)

   ' // Create an array of TRIVERTEX structures that describe
   ' // positional and color values for each vertex.

   DIM vertex(2) AS TRIVERTEX

   vertex(0).x     = 250
   vertex(0).y     = 50
   vertex(0).Red   = &Hff00
   vertex(0).Green = &H8000
   vertex(0).Blue  = &H0000
   vertex(0).Alpha = &H0000

   vertex(1).x     = 50
   vertex(1).y     = 250
   vertex(1).Red   = &H9000
   vertex(1).Green = &H0000
   vertex(1).Blue  = &H9000
   vertex(1).Alpha = &H0000

   vertex(2).x     = 450
   vertex(2).y     = 250
   vertex(2).Red   = &H9000
   vertex(2).Green = &H0000
   vertex(2).Blue  = &H9000
   vertex(2).Alpha = &H0000

   ' // Create a GRADIENT_TRIANGLE structure that
   ' // references the TRIVERTEX vertices.

   DIM gTriangle AS GRADIENT_TRIANGLE

   gTriangle.Vertex1   = 0
   gTriangle.Vertex2   = 1
   gTriangle.Vertex3   = 2

   ' // Draw a shaded triangle.
   GradientFill hDc, vertex(0), 3, gTriangle, 1, %GRADIENT_FILL_TRIANGLE

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
   pWindow.CreateWindow(%NULL, "Drawing a Shaded Triangle", 0, 0, 0, 0, 0, 0, CODEPTR(WindowProc))
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
         hdc = BeginPaint(hwnd, ps)
         DrawShadedTriangle hwnd, hdc
         EndPaint hwnd, ps
         EXIT FUNCTION

     CASE %WM_DESTROY
         PostQuitMessage 0
         EXIT FUNCTION

   END SELECT

   FUNCTION = DefWindowProc(hwnd, wMsg, wParam, lParam)

END FUNCTION
' ========================================================================================
