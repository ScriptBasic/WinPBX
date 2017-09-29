' ========================================================================================
' This example shows how to make an 8-bit device independent bitmap (DIB) from scratch.
' It initializes the necessary structures and then calls the CreateDIBitmap API function.
' Adapted from code posted at VB Helper: http://www.vb-helper.com/howto_make_8bit_dib.html
' ========================================================================================

' CSED_PBWIN - Use the PBWIN compiler
#COMPILE EXE
#DIM ALL
%UNICODE = 1

' // Include files for external files
#INCLUDE ONCE "CWindow.inc"   ' // CWindow class

TYPE BITMAPINFO256
   bmiHeader      AS BITMAPINFOHEADER
   bmiColors(255) AS RGBQUAD
END TYPE

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
   pWindow.CreateWindow(%NULL, "CreateDIBitmap Demo", 0, 0, 0, 0, 0, 0, CODEPTR(WindowProc))
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

   LOCAL  i              AS LONG            ' // Loop counter
   LOCAL  y              AS LONG            ' // Loop counter
   LOCAL  x              AS LONG            ' // Loop counter
   LOCAL  hdc            AS DWORD           ' // Window device context
   LOCAL  hdcScreen      AS DWORD           ' // Desktop device context
   LOCAL  ps             AS PAINTSTRUCT     ' // PAINTSTRUCT structure
   LOCAL  bmpinfo        AS BITMAPINFO256   ' // BITMAPINFO structure
   LOCAL  hDIB           AS DWORD           ' // DIB handle
   STATIC hdcCompatible  AS DWORD           ' // Handle of the compatible device context
   STATIC cxBitmap       AS LONG            ' // Width of the bitmap
   STATIC cyBitmap       AS LONG            ' // Height of the bitmap
   STATIC cxClient       AS LONG            ' // Width of the client area
   STATIC cyClient       AS LONG            ' // Height of the client area
   DIM    rgPixels(0, 0) AS BYTE            ' // Pixels array

   SELECT CASE wMsg

      CASE %WM_CREATE

         cxBitmap = 100   ' Width in pixels
         cyBitmap = 256   ' Height in pixels

         ' // Fills the BITMAPINFO structure
         bmpinfo.bmiHeader.biSize = SIZEOF(bmpinfo.bmiHeader)
         bmpinfo.bmiHeader.biWidth = cxBitmap        ' Width in pixels
         bmpinfo.bmiHeader.biHeight = cyBitmap       ' Height in pixels
         bmpinfo.bmiHeader.biPlanes = 1              ' 1 color plane
         bmpinfo.bmiHeader.biBitCount = 8            ' 8 bits per pixel
         bmpinfo.bmiHeader.biCompression = %BI_RGB   ' No compression
         bmpinfo.bmiHeader.biSizeImage = 0           ' Unneeded with no compression
         bmpinfo.bmiHeader.biXPelsPerMeter = 0       ' Unneeded
         bmpinfo.bmiHeader.biYPelsPerMeter = 0       ' Unneeded
         bmpinfo.bmiHeader.biClrUsed = 256           ' # colors in color table
         bmpinfo.bmiHeader.biClrImportant = 256      ' # important colors.

         ' // Initializes the DIB's color table to 256 shades of blue.
         FOR i = 0 TO 255
            bmpinfo.bmiColors(i).rgbRed = 0
            bmpinfo.bmiColors(i).rgbGreen = 0
            bmpinfo.bmiColors(i).rgbBlue = i
            bmpinfo.bmiColors(i).rgbReserved = 0
         NEXT

         ' // Draws a picture on the DIB, covering it with shades of blue.
         ' // For every 20th pixel vertically and horizontally, the code
         ' // subtracts the color value from 255 to make part of a line.
         REDIM rgPixels(0 TO cxBitmap - 1, 0 TO cyBitmap - 1)
         FOR y = 0 TO cyBitmap - 1
            FOR x = 0 TO cxBitmap - 1
               IF y MOD 20 = 19 OR x MOD 20 = 19 THEN
                  rgPixels(x, y) = y
               ELSE
                  rgPixels(x, y) = 255 - y
               END IF
            NEXT
         NEXT

         ' // Gets the screen's device context.
         hdcScreen = GetDC(%HWND_DESKTOP)
         ' // Creates the DIB.
         hDIB = CreateDIBitmap(hdcScreen, bmpinfo.bmiHeader, %CBM_INIT, _
                rgPixels(0, 0), BYVAL VARPTR(bmpinfo), %DIB_RGB_COLORS)
         ' // Creates a compatible device context.
         hdcCompatible = CreateCompatibleDC(hdcScreen)
         ' // Selects the DIB into the compatible DC.
         SelectObject(hdcCompatible, hDIB)
         ' // Deletes the screen DC and the DIB
         DeleteDC hdcScreen
         DeleteObject hDIB
         EXIT FUNCTION

      CASE %WM_COMMAND
         SELECT CASE LO(WORD, wParam)
            CASE %IDCANCEL
               IF HIWRD(wParam) = %BN_CLICKED THEN
                  SendMessage hwnd, %WM_CLOSE, 0, 0
                  EXIT FUNCTION
               END IF
         END SELECT

     CASE %WM_SIZE
         cxClient = LO(WORD, lParam)
         cyClient = HI(WORD, lParam)
         FUNCTION = 0
         EXIT FUNCTION

      CASE %WM_PAINT
         hdc = BeginPaint(hwnd, ps)
         StretchBlt hdc, 0, 0, cxClient, cyClient, _
                    hdcCompatible, 0, 0, cxBitmap, cyBitmap, %SRCCOPY
         EndPaint hwnd, ps
         EXIT FUNCTION

      CASE %WM_ERASEBKGND
         hdc = wParam
         StretchBlt hdc, 0, 0, cxClient, cyClient, _
                    hdcCompatible, 0, 0, cxBitmap, cyBitmap, %SRCCOPY
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
