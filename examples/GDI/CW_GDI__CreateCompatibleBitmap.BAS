' ========================================================================================
' Displays the text string "Hello, world!" on a small bitmap and then does a BitBlt from
' the bitmap to the program's client area.
' ========================================================================================

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
   pWindow.CreateWindow(%NULL, "CreateCompatibleBitmap Demo", 0, 0, 0, 0, 0, 0, CODEPTR(WindowProc))
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

   STATIC hBitmap  AS DWORD
   STATIC hdcMem   AS DWORD
   STATIC cxBitmap AS LONG
   STATIC cyBitmap AS LONG
   STATIC cxClient AS LONG
   STATIC cyClient AS LONG
   STATIC wszText  AS WSTRINGZ * 256
   LOCAL  hdc      AS DWORD
   LOCAL  hMenu    AS DWORD
   LOCAL  x        AS LONG
   LOCAL  y        AS LONG
   LOCAL  ps       AS PAINTSTRUCT
   LOCAL  tsize    AS APISIZE

   SELECT CASE wMsg

      CASE %WM_CREATE
         wszText = "Hello, world! "
         hdc = GetDC(hwnd)
         hdcMem = CreateCompatibleDC(hdc)
         GetTextExtentPoint32 hdc, wszText, LEN(wszText), tsize
         cxBitmap = tsize.cx
         cyBitmap = tsize.cy
         hBitmap = CreateCompatibleBitmap(hdc, cxBitmap, cyBitmap)
         ReleaseDC hwnd, hdc
         SelectObject hdcMem, hBitmap
         TextOut hdcMem, 0, 0, wszText, LEN(wszText)
         EXIT FUNCTION

      CASE %WM_COMMAND
         SELECT CASE LO(WORD, wParam)

            CASE %IDCANCEL
               IF HI(WORD, wParam) = %BN_CLICKED THEN
                  SendMessage hWnd, %WM_CLOSE, 0, 0
                  EXIT FUNCTION
               END IF

         END SELECT

      CASE %WM_SIZE
         cxClient = LO(WORD, lParam)
         cyClient = HI(WORD, lParam)
         EXIT FUNCTION

      CASE %WM_PAINT
         hdc = BeginPaint(hwnd, ps)
         FOR y = 0 TO cyClient - 1 STEP cyBitmap
            FOR x = 0 TO cxClient - 1 STEP cxBitmap
               BitBlt hdc, x, y, cxBitmap, cyBitmap, hdcMem, 0, 0, %SRCCOPY
            NEXT
         NEXT
         EndPaint hWnd, ps
         EXIT FUNCTION

      CASE %WM_DESTROY
         DeleteDC hdcMem
         DeleteObject hBitmap
         PostQuitMessage 0
         EXIT FUNCTION

   END SELECT

   FUNCTION = DefWindowProc(hWnd, wMsg, wParam, lParam)

END FUNCTION
' ========================================================================================
