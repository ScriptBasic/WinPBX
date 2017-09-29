' ########################################################################################
' Alpha Blending a Bitmap
' ########################################################################################

' CSED_PBWIN - Use the PBWIN compiler
#COMPILE EXE
#DIM ALL
%UNICODE = 1

' // Include files for external files
#INCLUDE ONCE "CWindow.inc"   ' // CWindow class

' ========================================================================================
' The following code sample divides a window into three horizontal areas. Then it draws an
' alpha-blended bitmap in each of the window areas as follows:
'    * In the top area, constant alpha = 50% but there is no source alpha.
'    * In the middle area, constant alpha = 100% (disabled) and source alpha is 0
'      (transparent) in the middle of the bitmap and 0xff (opaque) elsewhere.
'    * In the bottom area, constant alpha = 75% and source alpha changes.
' ========================================================================================
SUB DrawAlphaBlend (BYVAL hwnd AS LONG, BYVAL hDCwnd AS LONG)

   LOCAL hdc AS LONG              ' handle of the DC we will create
   LOCAL bf AS BLENDFUNCTION      ' structure for alpha blending
   LOCAL hbitmap AS LONG          ' bitmap handle
   LOCAL bmi AS BITMAPINFO        ' bitmap header
   LOCAL pvBits AS DWORD PTR      ' pointer to DIB section
   LOCAL ulWindowWidth AS LONG    ' window width
   LOCAL ulWindowHeight AS LONG   ' window height
   LOCAL ulBitmapWidth AS LONG    ' bitmap width
   LOCAL ulBitmapHeight AS LONG   ' bitmap height
   LOCAL rt AS RECT               ' used for getting window LOCALensions
   LOCAL x AS LONG, y AS LONG     ' stepping variables
   LOCAL ubAlpha AS BYTE          ' used for doing transparent gradient
   LOCAL ubRed   AS BYTE
   LOCAL ubGreen AS BYTE
   LOCAL ubBlue  AS BYTE
   LOCAL fAlphaFactor AS SINGLE   ' used to do premultiply

   ' get window dimensions
   GetClientRect hwnd, rt

   ' calculate window width/height
   ulWindowWidth = rt.nright - rt.nleft
   ulWindowHeight = rt.nbottom - rt.ntop

   ' make sure we have at least some window size
   IF ulWindowWidth = 0 OR ulWindowHeight = 0 THEN EXIT SUB

   ' divide the window into 3 horizontal areas
   ulWindowHeight = ulWindowHeight \ 3

   ' create a DC for our bitmap -- the source DC for AlphaBlend
   hdc = CreateCompatibleDC(hDCwnd)

   ' setup bitmap info
   ' set the bitmap width and height to 60% of the width and height of each of
   ' the three horizontal areas. Later on, the blending will occur in the center
   ' of each of the three areas.
   bmi.bmiHeader.biSize = sizeof(BITMAPINFOHEADER)
   ulBitmapWidth = ulWindowWidth - (ulWindowWidth \ 5) * 2
   bmi.bmiHeader.biWidth = ulBitmapWidth
   ulBitmapHeight = ulWindowHeight - (ulWindowHeight \ 5) * 2
   bmi.bmiHeader.biHeight = ulBitmapHeight
   bmi.bmiHeader.biPlanes = 1
   bmi.bmiHeader.biBitCount = 32         ' four 8-bit components
   bmi.bmiHeader.biCompression = %BI_RGB
   bmi.bmiHeader.biSizeImage = ulBitmapWidth * ulBitmapHeight * 4

   ' create our DIB section and select the bitmap into the dc
   hbitmap = CreateDIBSection(hdc, bmi, %DIB_RGB_COLORS, BYVAL VARPTR(pvBits), 0, 0)
   SelectObject hdc, hbitmap

   ' in top window area, constant alpha = 50%, but no source alpha
   ' the color format for each pixel is &Haarrggbb
   ' set all pixels to blue and set source alpha to zero
   FOR y = 0 TO ulBitmapHeight - 1
      FOR x = 0 TO ulBitmapWidth - 1
         @pvBits[x + y * ulBitmapWidth] = &H000000FF
      NEXT
   NEXT

   bf.BlendOp = %AC_SRC_OVER
   bf.BlendFlags = 0
   bf.SourceConstantAlpha = &H7F  ' half of &HFF = 50% transparency
   bf.AlphaFormat = 0             ' ignore source alpha channel

   IF ISFALSE AlphaBlend(hDCwnd, (ulWindowWidth\5), (ulWindowHeight\5), _
                         ulBitmapWidth, ulBitmapHeight, hdc, 0, 0, _
                         ulBitmapWidth, ulBitmapHeight, bf) THEN
      DeleteObject hbitmap
      DeleteDC hdc
      EXIT SUB
   END IF

   ' in middle window area, constant alpha = 100% (disabled), source
   ' alpha is 0 in middle of bitmap and opaque in rest of bitmap
   FOR y = 0 TO ulBitmapHeight - 1
      FOR x = 0 TO ulBitmapWidth - 1
         IF (x > (ulBitmapWidth \ 5)) AND (x < (ulBitmapWidth-ulBitmapWidth \ 5)) AND _
            (y > (ulBitmapHeight \ 5)) AND (y < (ulBitmapHeight-ulBitmapHeight \ 5)) THEN
            ' in middle of bitmap: source alpha = 0 (transparent).
            ' This means multiply each color component by &H00.
            ' Thus, after AlphaBlend, we have a, &H00 * r,
            ' &H00 * g,and &H00 * b (which is &H00000000)
            ' for now, set all pixels to red
            @pvBits[x + y * ulBitmapWidth] = &H00FF0000
         ELSE
            ' in the rest of bitmap, source alpha = &Hff (opaque)
            ' and set all pixels to blue
            @pvBits[x + y * ulBitmapWidth] = &HFF0000FF
         END IF
      NEXT
   NEXT

   bf.BlendOp = %AC_SRC_OVER
   bf.BlendFlags = 0
   bf.AlphaFormat = %AC_SRC_ALPHA  ' use source alpha
   bf.SourceConstantAlpha = &HFF   ' opaque (disable constant alpha)

   IF ISFALSE AlphaBlend(hDCwnd, ulWindowWidth \ 5, ulWindowHeight \ 5 + ulWindowHeight, _
                         ulBitmapWidth, ulBitmapHeight, hdc, 0, 0, ulBitmapWidth, _
                         ulBitmapHeight, bf) THEN
      DeleteObject hbitmap
      DeleteDC hdc
      EXIT SUB
   END IF

   ' bottom window area, use constant alpha = 75% and a changing
   ' source alpha. Create a gradient effect using source alpha, and
   ' then fade it even more with constant alpha
   ubRed   = &H00
   ubGreen = &H00
   ubBlue  = &HFF

   LOCAL f AS SINGLE

   FOR y = 0 TO ulBitmapHeight - 1
      FOR x = 0 TO ulBitmapWidth - 1
         ' for a simple gradient, base the alpha value on the x
         ' value of the pixel
         f = x / ulBitmapWidth * 255
         ubAlpha = f
         ' calculate the factor by which we multiply each component
         fAlphaFactor = ubAlpha / &HFF
         f = ubBlue * fAlphaFactor
         ubBlue = f
         @pvBits[x + y * ulBitmapWidth] = ubAlpha OR _            '&Haa000000
                                          ubRed   OR _            '&H00rr0000
                                          ubGreen OR _            '&H0000gg00
                                          ubBlue                  '&H000000bb
      NEXT
   NEXT

   bf.BlendOp = %AC_SRC_OVER
   bf.BlendFlags = 0
   bf.AlphaFormat = 0
   bf.SourceConstantAlpha = &HBF   ' use constant alpha, with 75% opaqueness

   AlphaBlend hDCwnd, ulWindowWidth \ 5, _
              ulWindowHeight \ 5 + 2 * ulWindowHeight, ulBitmapWidth, _
              ulBitmapHeight, hdc, 0, 0, ulBitmapWidth, _
              ulBitmapHeight, bf

   ' do cleanup
   DeleteObject hbitmap
   DeleteDC hdc

END SUB
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
   pWindow.CreateWindow(%NULL, "AlphaBlend Demo", 0, 0, 0, 0, 0, 0, CODEPTR(WindowProc))
   ' // Set the client size
   pWindow.SetClientSize 500, 320
   ' // Center the window
   pWindow.CenterWindow

   ' // Default message pump (you can replace it with your own)
   pWindow.DoEvents(nCmdShow)

END FUNCTION
' ========================================================================================

' ========================================================================================
' Main dialog callback.
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
         DrawAlphaBlend hwnd, hdc
         EndPaint hwnd, ps
         EXIT FUNCTION

     CASE %WM_DESTROY
         PostQuitMessage 0
         EXIT FUNCTION

   END SELECT

   FUNCTION = DefWindowProc(hwnd, wMsg, wParam, lParam)

END FUNCTION
' ========================================================================================
