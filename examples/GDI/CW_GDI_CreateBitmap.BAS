' ########################################################################################
' This example creates a bitmap from the desktop and displays it.
' ########################################################################################

' CSED_PBWIN - Use the PBWIN compiler
#COMPILE EXE
#DIM ALL
%UNICODE = 1

' // Include files for external files
#INCLUDE ONCE "CWindow.inc"   ' // CWindow class


' ========================================================================================
' Creates a bitmap from the desktop
' ========================================================================================
FUNCTION CreateBitmapFromDesktop() AS DWORD

   LOCAL hDC AS DWORD
   LOCAL hMemDC AS DWORD
   LOCAL hwnd AS DWORD
   LOCAL bmp AS BITMAP
   LOCAL hMemBmp AS DWORD
   LOCAL hBmpOld AS DWORD

   hwnd = GetDesktopWindow
   hDC = GetWindowDC(hwnd)

   bmp.bmBitsPixel = GetDeviceCaps(hdc, %BITSPIXEL)
   bmp.bmPlanes =  GetDeviceCaps(hdc, %PLANES)
   bmp.bmWidth = GetDeviceCaps(hdc, %HORZRES)
   bmp.bmHeight = GetDeviceCaps(hdc, %VERTRES)
   bmp.bmWidthBytes = FIX((bmp.bmWidth + 15) / 16) * 2

   hMemBmp = CreateBitmap(bmp.bmWidth, bmp.bmHeight, bmp.bmPlanes, bmp.bmBitsPixel, BYVAL %NULL)
   hMemDC = CreateCompatibleDC(hDC)
   hBmpOld = SelectObject (hMemDC, hMemBmp)
   BitBlt hMemDC, 0, 0, bmp.bmWidth, bmp.bmHeight, hdc, 0, 0, %SRCCOPY
   ReleaseDC hWnd, hDC

   FUNCTION = hMemDC

END FUNCTION
' ========================================================================================

' ========================================================================================
' Main
' ========================================================================================
FUNCTION WinMain (BYVAL hInstance AS DWORD, BYVAL hPrevInstance AS DWORD, BYVAL lpszCmdLine AS WSTRINGZ PTR, BYVAL nCmdShow AS LONG) AS LONG

   ' // Set process DPI aware
   IF AfxGetWindowsVersion => 6 THEN SetProcessDPIAware

   ' // Create an instance of the class
   LOCAL pWindow AS IWindow
   pWindow = CLASS "CWindow"
   IF ISNOTHING(pWindow) THEN EXIT FUNCTION

   ' // Create the main window
   ' // Note: CW_USEDEFAULT is used as the default value When passing 0's as the width and height
   pWindow.CreateWindow(%NULL, "CreateBitmap Demo", 0, 0, 0, 0, 0, 0, CODEPTR(WindowProc))
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

   LOCAL  ps AS PAINTSTRUCT   ' // PAINTSTRUCT structure
   STATIC hMemDC AS DWORD     ' // Memory device context

   SELECT CASE wMsg

      CASE %WM_CREATE

         ' // Creates the bitmap
         hMemDC = CreateBitmapFromDesktop

      CASE %WM_COMMAND
         SELECT CASE LO(WORD, wParam)

            CASE %IDCANCEL
               IF HI(WORD, wParam) = %BN_CLICKED THEN
                  SendMessage hWnd, %WM_CLOSE, 0, 0
                  EXIT FUNCTION
               END IF

         END SELECT

      CASE %WM_PAINT
         ' // Redraws the bitmap
         BeginPaint hwnd, ps
         BitBlt ps.hdc, ps.rcPaint.nLeft, ps.rcPaint.ntop, ps.rcPaint.nRight - ps.rcPaint.nLeft, _
                ps.rcPaint.nbottom - ps.rcPaint.ntop, hMemDC, ps.rcPaint.nLeft, ps.rcPaint.ntop, %SRCCOPY
         EndPaint hwnd, ps
         EXIT FUNCTION

      CASE %WM_DESTROY
         DeleteDC hMemDC   ' // Deletes the memory context DC
         PostQuitMessage 0
         EXIT FUNCTION

   END SELECT

   FUNCTION = DefWindowProc(hWnd, wMsg, wParam, lParam)

END FUNCTION
' ========================================================================================
