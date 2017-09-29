' ########################################################################################
' Drawing markers
' You can use the line functions to draw markers. A marker is a symbol centered over a
' point. Drawing applications use markers to designate starting points, ending points,
' and control points. Spreadsheet applications use markers to designate points of interest
' on a chart or graph.
' In the following code sample, the application-defined Marker function creates a marker
' by using the MoveToEx and LineTo functions. These functions draw two intersecting lines,
' 20 pixels in length, centered over the cursor coordinates.
' The system stores the coordinates of the cursor in the lParam parameter of the
' WM_LBUTTONDOWN message when the user presses the left mouse button. The following code
' demonstrates how an application gets these coordinates, determines whether they lie
' within its client area, and passes them to the Marker function to draw the marker.
' http://msdn.microsoft.com/en-us/library/ms534252(VS.85).aspx
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
   pWindow.CreateWindow(%NULL, "Drawing Markers", 0, 0, 0, 0, 0, 0, CODEPTR(WindowProc))
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
' Draw the marker
' ========================================================================================
SUB Marker(BYVAL x AS LONG, BYVAL y AS LONG, BYVAL hWnd AS DWORD)

   LOCAL hdc AS DWORD

   hdc = GetDC(hWnd)
   MoveToEx hdc, x - 10, y, BYVAL %NULL
   LineTo hdc, x + 10, y
   MoveToEx hdc, x, y - 10, BYVAL %NULL
   LineTo hdc, x, y + 10
   ReleaseDC hWnd, hdc

END SUB
' ========================================================================================

' ========================================================================================
' Main window procedure
' ========================================================================================
FUNCTION WindowProc (BYVAL hwnd AS DWORD, BYVAL wMsg AS DWORD, BYVAL wParam AS DWORD, BYVAL lParam AS LONG) AS LONG

   DIM    ptMouseDown(32) AS STATIC POINTAPI
   STATIC index AS LONG
   LOCAL  rc AS RECT
   LOCAL  hrgn AS DWORD

   SELECT CASE wMsg

      CASE %WM_COMMAND
         SELECT CASE LO(WORD, wParam)
            CASE %IDCANCEL
               IF HI(WORD, wParam) = %BN_CLICKED THEN
                  SendMessage hWnd, %WM_CLOSE, 0, 0
                  EXIT FUNCTION
               END IF
         END SELECT

      CASE %WM_LBUTTONDOWN
         IF index < 32 THEN
            ' // Create the region from the client area.
            GetClientRect hWnd, rc
            hrgn = CreateRectRgn(rc.nLeft, rc.nTop, rc.nRight, rc.nBottom)
            ptMouseDown(index).x = LO(WORD, lParam)
            ptMouseDown(index).y = HI(WORD, lParam)
            ' // Test for a hit in the client rectangle.
            IF PtInRegion(hrgn, ptMouseDown(index).x, ptMouseDown(index).y) THEN
               ' // If a hit occurs, record the mouse coords.
               Marker ptMouseDown(index).x, ptMouseDown(index).y, hWnd
               index += 1
            END IF
         END IF
         EXIT FUNCTION

      CASE %WM_DESTROY
         PostQuitMessage 0
         EXIT FUNCTION

   END SELECT

   FUNCTION = DefWindowProc(hWnd, wMsg, wParam, lParam)

END FUNCTION
' ========================================================================================
