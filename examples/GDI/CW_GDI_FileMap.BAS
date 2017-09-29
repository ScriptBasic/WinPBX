' ########################################################################################
' Reads data from a file and creates a map onscreen using SetPixelV. If the ASCII value of
' a byte is 0, it will show as black. At the other end of the spectrum, ASCII 255 will
' show as white.
' Based on an example posted at http://www.powerbasic.com/support/forums/Forum7/HTML/001283.html
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
   pWindow.CreateWindow(%NULL, "SetPixelV Demo", 0, 0, 0, 0, 0, 0, CODEPTR(WindowProc))
   ' // Change the background color
   pWindow.Brush = %COLOR_WINDOW + 1
   ' // Set the client size
   pWindow.SetClientSize 550, 350
   ' // Center the window
   pWindow.CenterWindow

   ' // Add the buttons
   pWindow.AddButton(pWindow.hwnd, 100, "&Clear", 0, 0, 0, 0)
   pWindow.AddButton(pWindow.hwnd, 101, "&Show", 0, 0, 0, 0)

   ' // Default message pump (you can replace it with your own)
   pWindow.DoEvents(nCmdShow)

END FUNCTION
' ========================================================================================

' ========================================================================================
' Main window procedure
' ========================================================================================
FUNCTION WindowProc (BYVAL hwnd AS DWORD, BYVAL wMsg AS DWORD, BYVAL wParam AS DWORD, BYVAL lParam AS LONG) AS LONG

   LOCAL rc AS RECT

   SELECT CASE wMsg

      CASE %WM_SIZE
         ' Resize the two buttons of the dialog
         IF wParam <> %SIZE_MINIMIZED THEN
            GetClientRect hWnd, rc
            MoveWindow GetDlgItem(hWnd, 100), (rc.nRight - rc.nLeft) - 185, (rc.nBottom - rc.nTop) - 35, 75, 23, %TRUE
            MoveWindow GetDlgItem(hWnd, 101), (rc.nRight - rc.nLeft) - 95, (rc.nBottom - rc.nTop) - 35, 75, 23, %TRUE
         END IF

      CASE %WM_COMMAND
         SELECT CASE LO(WORD, wParam)
            CASE 100
               InvalidateRect hWnd, BYVAL %NULL, %TRUE
               EXIT FUNCTION
            CASE 101
               SetWindowText hWnd, "Building graph, please wait..."
               ShowFileMap(hWnd, EXE.FULL$)
               EXIT FUNCTION
            CASE %IDCANCEL
               IF HI(WORD, wParam) = %BN_CLICKED THEN
                  SendMessage hWnd, %WM_CLOSE, 0, 0
                  EXIT FUNCTION
               END IF
         END SELECT

      CASE %WM_SYSCOMMAND
         ' Capture this message and send a WM_CLOSE message
         IF (wParam AND &HFFF0) = %SC_CLOSE THEN
            SendMessage hWnd, %WM_CLOSE, 0, 0
            EXIT FUNCTION
         END IF

      CASE %WM_DESTROY
         PostQuitMessage 0
         EXIT FUNCTION

   END SELECT

   FUNCTION = DefWindowProc(hWnd, wMsg, wParam, lParam)

END FUNCTION
' ========================================================================================

' ========================================================================================
' Draws the map.
' ========================================================================================
SUB ShowFileMap (BYVAL hWnd AS DWORD, BYVAL strFileName AS STRING)

   LOCAL i AS LONG
   LOCAL hdc AS DWORD
   LOCAL curX AS LONG
   LOCAL curY AS LONG
   LOCAL buffer AS STRING
   LOCAL nLen AS LONG
   LOCAL xVal AS LONG
   LOCAL Result AS LONG
   LOCAL rc AS RECT

   IF ISFALSE ISFILE(strFileName) THEN EXIT SUB
   OPEN strFileName FOR BINARY ACCESS READ AS #1
   nLen = LOF(1)
   buffer = STRING$(nLen, 0)
   GET #1, 1, buffer
   CLOSE #1

   GetClientRect hWnd, rc

   curX = 5
   curY = 5
   hdc = GetDC(hWnd)
   FOR i = 1 TO nLen
      xVal = ASC(MID$(buffer, i))
      Result = SetPixel(hDC, curX, curY, RGB(xVal, xVal, xVal))
      SetPixelV hdc, curX, curY, RGB(xVal, xVal, xVal)
      StretchBlt hdc, curX, curY, 2, 2, hdc, curX, curY, 1, 1, %SRCCOPY
      curX = curX + 2
      IF curY => rc.nBottom - 45 THEN EXIT FOR
      IF curX => rc.nRight - 5 THEN
         curX = 5
         curY = curY + 2
      END IF
   NEXT
   ReleaseDC hWnd, hdc
   SetWindowText hWnd, "Map built"

END SUB
' ========================================================================================
