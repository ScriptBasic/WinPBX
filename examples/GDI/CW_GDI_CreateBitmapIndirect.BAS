' ========================================================================================
' This program is an adaptation of BRICKS2.C -- CreateBitmap Demonstration
' © Charles Petzold, 1998, described and analysed in Chapter 14 of the book Programming
' Windows, 5th Edition.
' If you're working with small monochrome images, you don't have to create them as
' resources. Unlike color bitmap objects, the format of monochrome bits is relatively
' simple and can almost be derived directly from the image you want to create.
' You can write down a series of bits (0 for black and 1 for white) that directly
' corresponds to this grid. Reading these bits from left to right, you can then assign
' each group of 8 bits a hexadecimal byte. If the width of the bitmap is not a multiple
' of 16, pad the bytes to the right with zeros to get an even number of bytes.
' The BRICKS2 program uses this technique to create the bricks bitmap directly without
' requiring a resource.
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
   pWindow.CreateWindow(%NULL, "CreateBitmapIndirect Demo", 0, 0, 0, 0, 0, 0, CODEPTR(WindowProc))
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

   STATIC hBitmap   AS DWORD
   STATIC cxClient  AS LONG
   STATIC cyClient  AS LONG
   STATIC cxSource  AS LONG
   STATIC cySource  AS LONG
   LOCAL  hdc       AS DWORD
   LOCAL  hdcMem    AS DWORD
   LOCAL  x         AS LONG
   LOCAL  y         AS LONG
   LOCAL  ps        AS PAINTSTRUCT
   STATIC bmp       AS BITMAP
   DIM    bmpbits(0 TO 7, 0 TO 1) AS STATIC BYTE

   SELECT CASE wMsg

      CASE %WM_CREATE
         bmp.bmType = 0
         bmp.bmWidth = 8
         bmp.bmHeight = 8
         bmp.bmWidthBytes = 2
         bmp.bmPlanes = 1
         bmp.bmBitsPixel = 1
         bmpbits(0, 0) = &HFF : bmpbits(1, 0) = 0
         bmpbits(2, 0) = &H0C : bmpbits(3, 0) = 0
         bmpbits(4, 0) = &H0C : bmpbits(5, 0) = 0
         bmpbits(6, 0) = &H0C : bmpbits(7, 0) = 0
         bmpbits(0, 1) = &HFF : bmpbits(1, 1) = 0
         bmpbits(2, 1) = &HC0 : bmpbits(3, 1) = 0
         bmpbits(4, 1) = &HC0 : bmpbits(5, 1) = 0
         bmpbits(6, 1) = &HC0 : bmpbits(7, 1) = 0
         bmp.bmBits = VARPTR(bmpbits(0))
         hBitmap = CreateBitmapIndirect(bmp)
         cxSource = bmp.bmWidth
         cySource = bmp.bmHeight
         FUNCTION = 0
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
         hdcMem = CreateCompatibleDC(hdc)
         SelectObject hdcMem, hBitmap
         FOR y = 0 TO cxClient - 1 STEP cySource
            FOR x = 0 TO cxClient - 1 STEP cxSource
               BitBlt hdc, x, y, cxSource, cySource, hdcMem, 0, 0, %SRCCOPY
            NEXT
         NEXT
         DeleteDC hdcMem
         EndPaint hWnd, ps
         EXIT FUNCTION

      CASE %WM_DESTROY
         DeleteObject hBitmap
         PostQuitMessage 0
         EXIT FUNCTION

   END SELECT

   FUNCTION = DefWindowProc(hWnd, wMsg, wParam, lParam)

END FUNCTION
' ========================================================================================
