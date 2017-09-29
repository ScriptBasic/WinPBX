' ========================================================================================
' The following example captures an image of the entire screen, creates a compatible
' device context and a bitmap with the appropriate dimensions, selects the bitmap into the
' compatible DC, and then copies the image using the BitBlt function.
' Later, in the WM_PAINT and WM_ERASEBKGND messages, redisplays the image calling BitBlt
' again, specifying the compatible DC as the source DC and a window DC as the target DC.
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

   ' // Set process DPI aware
   AfxSetProcessDPIAware

   ' // Create an instance of the class
   LOCAL pWindow AS IWindow
   pWindow = CLASS "CWindow"
   IF ISNOTHING(pWindow) THEN EXIT FUNCTION

   ' // Create the main window
   ' // Note: CW_USEDEFAULT is used as the default value When passing 0's as the width and height
   pWindow.CreateWindow(%NULL, "BitBlt Demo", 0, 0, 0, 0, 0, 0, CODEPTR(WindowProc))
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

   STATIC hdcCompatible AS DWORD         ' // Handle of the compatible device context
   STATIC cxBitmap      AS LONG          ' // Width of the bitmap
   STATIC cyBitmap      AS LONG          ' // Height of the bitmap
   LOCAL  hdcScreen     AS DWORD         ' // Desktop device context
   LOCAL  hbmScreen     AS DWORD         ' // Screen bitmap handle
   LOCAL  hdc           AS DWORD         ' // Window device context
   LOCAL  ps            AS PAINTSTRUCT   ' // PAINTSTRUCT structure

   SELECT CASE wMsg

     CASE %WM_CREATE

         ' // Create a normal DC and a memory DC for the entire screen. The
         ' // normal DC provides a "snapshot" of the screen contents. The
         ' // memory DC keeps a copy of this "snapshot" in the associated
         ' // bitmap.
         hdcScreen = CreateDC("DISPLAY", BYVAL %NULL, BYVAL %NULL, BYVAL %NULL)
         hdcCompatible = CreateCompatibleDC(hdcScreen)

         ' // Create a compatible bitmap for hdcScreen.
         cxBitmap = GetDeviceCaps(hdcScreen, %HORZRES)
         cyBitmap = GetDeviceCaps(hdcScreen, %VERTRES)
         hbmScreen = CreateCompatibleBitmap(hdcScreen, cxBitmap, cyBitmap)

         ' // Select the bitmaps into the compatible DC.
         SelectObject(hdcCompatible, hbmScreen)
         ' // Copy color data for the entire display into a
         ' // the bitmap that is selected into a compatible DC.
         BitBlt hdcCompatible, 0, 0, cxBitmap, cyBitmap, hdcScreen, 0, 0, %SRCCOPY
         ' // Delete the screen DC and bitmap
         DeleteDC hdcScreen
         DeleteObject hbmScreen
         EXIT FUNCTION

      CASE %WM_COMMAND
         SELECT CASE LOWRD(wParam)
            CASE %IDCANCEL
               IF HIWRD(wParam) = %BN_CLICKED THEN
                  SendMessage hwnd, %WM_CLOSE, 0, 0
                  EXIT FUNCTION
               END IF
         END SELECT

      CASE %WM_PAINT
         hdc = BeginPaint(hwnd, ps)
         BitBlt hdc, 0, 0, cxBitmap, cyBitmap, hdcCompatible, 0, 0, %SRCCOPY
         EndPaint hwnd, ps
         EXIT FUNCTION

      CASE %WM_ERASEBKGND
         hdc = wParam
         BitBlt hdc, 0, 0, cxBitmap, cyBitmap, hdcCompatible, 0, 0, %SRCCOPY
         FUNCTION = %TRUE
         EXIT FUNCTION

      CASE %WM_DESTROY
         IF hdcCompatible THEN DeleteDC hdcCompatible
         PostQuitMessage 0
         EXIT FUNCTION

   END SELECT

   FUNCTION = DefWindowProc(hwnd, wMsg, wParam, lParam)

END FUNCTION
' ========================================================================================
