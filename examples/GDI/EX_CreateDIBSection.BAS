' ########################################################################################
' Small demo of fast bitmap manipulation via DIBs
' Public Domain by Borje Hagten, May 2002
' http://www.powerbasic.com/support/pbforums/showthread.php?t=23384
' Adapted from DDT to SDK by José Roca, April 2009
' Maybe not the best way to do it, but good enough for my needs.
' Using 32-bit DIB makes routines easier to code and understand, IMO.
' Special credits to Semen Matusovski for many nice "How to" samples
'
' Included routines
' ImgColorBlend:   Creates a chess-like pattern by replacing every other
'                  color1 pixel with color2.
' ImgColorReplace: Replaces color1 with color2. FloodFill is nice, but misses
'                  enclosed areas inside letters, etc. This one fixes that.
' ImgFlip...       Flips the image in various directions. StretchBlt can also
'                  do this, but is actually slower...
' ########################################################################################

#COMPILE EXE
#DIM ALL
#INCLUDE "windows.inc"
#INCLUDE "EditCtrl.inc"

%IDC_TEXT = 200

GLOBAL hViewer AS DWORD
GLOBAL hMemDC AS DWORD
GLOBAL hBitmap AS DWORD

' ========================================================================================
' Main
' ========================================================================================
FUNCTION WinMain (BYVAL hInstance AS DWORD, BYVAL hPrevInstance AS DWORD, BYVAL lpszCmdLine AS ASCIIZ PTR, BYVAL nCmdShow AS LONG) AS LONG

   LOCAL hWndMain          AS DWORD
   LOCAL wcex              AS WNDCLASSEX
   LOCAL szClassName       AS ASCIIZ * 80
   LOCAL szViewerClassName AS ASCIIZ * 80
   LOCAL rc                AS RECT
   LOCAL szCaption         AS ASCIIZ * 255
   LOCAL nLeft             AS LONG
   LOCAL nTop              AS LONG
   LOCAL nWidth            AS LONG
   LOCAL nHeight           AS LONG

   ' Register the window class
   szClassName        = "MyClassName"
   wcex.cbSize        = SIZEOF(wcex)
   wcex.style         = %CS_HREDRAW OR %CS_VREDRAW
   wcex.lpfnWndProc   = CODEPTR(WndProc)
   wcex.cbClsExtra    = 0
   wcex.cbWndExtra    = 0
   wcex.hInstance     = hInstance
   wcex.hCursor       = LoadCursor (%NULL, BYVAL %IDC_ARROW)
   wcex.hbrBackground = %COLOR_3DFACE + 1
   wcex.lpszMenuName  = %NULL
   wcex.lpszClassName = VARPTR(szClassName)
   wcex.hIcon         = LoadIcon (%NULL, BYVAL %IDI_APPLICATION) ' Sample, if resource icon: LoadIcon(hInst, "APPICON")
   wcex.hIconSm       = LoadIcon (%NULL, BYVAL %IDI_APPLICATION) ' Remember to set small icon too..
   RegisterClassEx wcex

   ' Register the window class
   szViewerClassName  = "BitMapViewer"
   wcex.cbSize        = SIZEOF(wcex)
   wcex.style         = 0
   wcex.lpfnWndProc   = CODEPTR(ViewerProc)
   wcex.cbClsExtra    = 0
   wcex.cbWndExtra    = 0
   wcex.hInstance     = hInstance
   wcex.hCursor       = LoadCursor (%NULL, BYVAL %IDC_ARROW)
   wcex.hbrBackground = 0
   wcex.lpszMenuName  = %NULL
   wcex.lpszClassName = VARPTR(szViewerClassName)
   wcex.hIcon         = 0
   wcex.hIconSm       = 0
   RegisterClassEx wcex

   ' Window caption
   szCaption = "DIB Manipulation Demo"

   ' Retrieve the size of the working area
   SystemParametersInfo %SPI_GETWORKAREA, 0, BYVAL VARPTR(rc), 0

   ' Calculate the position and size of the window
   nWidth  = 600
   nHeight = 458
   nLeft   = ((rc.nRight - rc.nLeft) \ 2) - nWidth \ 2
   nTop    = ((rc.nBottom - rc.nTop) \ 2) - (nHeight \ 2)

   ' Create a window using the registered class
   hWndMain = CreateWindowEx(%WS_EX_CONTROLPARENT, _           ' extended style
                             szClassName, _                    ' window class name
                             szCaption, _                      ' window caption
                             %WS_SYSMENU, _                    ' window styles
                             nLeft, _                          ' initial x position
                             nTop, _                           ' initial y position
                             nWidth, _                         ' initial x size
                             nHeight, _                        ' initial y size
                             %NULL, _                          ' parent window handle
                             0, _                              ' window menu handle
                             hInstance, _                      ' program instance handle
                             BYVAL %NULL)                      ' creation parameters

   ' Show the window
   ShowWindow hWndMain, nCmdShow
   UpdateWindow hWndMain

   ' Message handler loop
   LOCAL uMsg AS tagMsg
   WHILE GetMessage(uMsg, %NULL, 0, 0)
      IF ISFALSE IsDialogMessage(hWndMain, uMsg) THEN
         TranslateMessage uMsg
         DispatchMessage uMsg
      END IF
   WEND

   FUNCTION = uMsg.wParam

END FUNCTION
' ========================================================================================

' ========================================================================================
' Main Window callback
' ========================================================================================
FUNCTION WndProc (BYVAL hWnd AS DWORD, BYVAL wMsg AS DWORD, BYVAL wParam AS DWORD, BYVAL lParam AS LONG) AS LONG

   LOCAL hDC     AS DWORD
   LOCAL bm      AS BITMAP
   LOCAL bmi     AS BITMAPINFO
   LOCAL rc      AS RECT
   LOCAL strText AS STRING
   LOCAL hCtl    AS DWORD
   LOCAL hFont   AS DWORD

   SELECT CASE wMsg

      CASE %WM_CREATE

         ' // Create the controls
         hFont = GetStockObject(%ANSI_VAR_FONT)
         hViewer = CreateWindowEx(%WS_EX_CLIENTEDGE, "BitMapViewer", "", _
                     %WS_CHILD OR %WS_VISIBLE OR %WS_TABSTOP, _
                     0, 0, 426, 426, hwnd, 10, GetModuleHandle(""), BYVAL %NULL)
         hCtl = CreateWindowEx(0, "Static", "Text:", _
                    %WS_CHILD OR %WS_VISIBLE OR %WS_TABSTOP OR %BS_FLAT, _
                    438, 241, 150, 16, hwnd,  -1, GetModuleHandle(""), BYVAL %NULL)
         IF hFont THEN SendMessage hCtl, %WM_SETFONT, hFont, 0
         hCtl = CreateWindowEx(%WS_EX_CLIENTEDGE, "Edit", "PowerBASIC", _
                    %WS_CHILD OR %WS_VISIBLE OR %WS_TABSTOP OR %ES_CENTER OR %ES_AUTOHSCROLL, _
                    437, 257, 148, 19, hwnd, %IDC_TEXT, GetModuleHandle(""), BYVAL %NULL)
         IF hFont THEN SendMessage hCtl, %WM_SETFONT, hFont, 0
         hCtl = CreateWindowEx(0, "Button", "Blend color", _
                    %WS_CHILD OR %WS_VISIBLE OR %WS_TABSTOP OR %BS_FLAT, _
                    437, 289, 75, 23, hwnd, 20, GetModuleHandle(""), BYVAL %NULL)
         IF hFont THEN SendMessage hCtl, %WM_SETFONT, hFont, 0
         hCtl = CreateWindowEx(0, "Button", "Replace color", _
                    %WS_CHILD OR %WS_VISIBLE OR %WS_TABSTOP OR %BS_FLAT, _
                    512, 289, 75, 23, hwnd, 21, GetModuleHandle(""), BYVAL %NULL)
         IF hFont THEN SendMessage hCtl, %WM_SETFONT, hFont, 0
         hCtl = CreateWindowEx(0, "Button", "Flip updown", _
                    %WS_CHILD OR %WS_VISIBLE OR %WS_TABSTOP OR %BS_FLAT, _
                    437, 315, 75, 23, hwnd, 22, GetModuleHandle(""), BYVAL %NULL)
         IF hFont THEN SendMessage hCtl, %WM_SETFONT, hFont, 0
         hCtl = CreateWindowEx(0, "Button", "Flip sideways", _
                    %WS_CHILD OR %WS_VISIBLE OR %WS_TABSTOP OR %BS_FLAT, _
                    512, 315, 75, 23, hwnd, 23, GetModuleHandle(""), BYVAL %NULL)
         IF hFont THEN SendMessage hCtl, %WM_SETFONT, hFont, 0
         hCtl = CreateWindowEx(0, "Button", "Flip 180", _
                    %WS_CHILD OR %WS_VISIBLE OR %WS_TABSTOP OR %BS_FLAT, _
                    437, 341, 75, 23, hwnd, 24, GetModuleHandle(""), BYVAL %NULL)
         IF hFont THEN SendMessage hCtl, %WM_SETFONT, hFont, 0
         hCtl = CreateWindowEx(0, "Button", "Original", _
                    %WS_CHILD OR %WS_VISIBLE OR %WS_TABSTOP OR %BS_FLAT, _
                    512, 341, 75, 23, hwnd, 25, GetModuleHandle(""), BYVAL %NULL)
         IF hFont THEN SendMessage hCtl, %WM_SETFONT, hFont, 0
         hCtl = CreateWindowEx(0, "Button", "E&xit", _
                    %WS_CHILD OR %WS_VISIBLE OR %WS_TABSTOP OR %BS_FLAT, _
                    437, 397, 150, 22, hwnd, %IDCANCEL, GetModuleHandle(""), BYVAL %NULL)
         IF hFont THEN SendMessage hCtl, %WM_SETFONT, hFont, 0

         GetClientRect hViewer, rc
         hDC = GetDc(hViewer)
         bmi.bmiHeader.biSize        = SIZEOF(bmi.bmiHeader)
         bmi.bmiHeader.biWidth       = rc.nRight
         bmi.bmiHeader.biHeight      = -rc.nBottom   ' Top-down DIB - origin in upper left corner
         bmi.bmiHeader.biPlanes      = 1
         bmi.bmiHeader.biBitCount    = 32
         bmi.bmiHeader.biCompression = %BI_RGB
         hMemDC = CreateCompatibleDC(hDC)
         hBitmap = CreateDIBSection(hMemDC, bmi, %DIB_RGB_COLORS, 0, 0, 0)
         GlobalLock hBitmap
         SelectObject hMemDC, hBitmap
         SetBkMode hMemDC, %TRANSPARENT
         ReleaseDc hViewer, hDC
         strText = Edit_GetText(GetDlgItem(hwnd, %IDC_TEXT))
         ImgDrawText strText
         EXIT FUNCTION

      CASE %WM_COMMAND
         SELECT CASE LO(WORD, wParam)

            CASE %IDCANCEL
               IF HI(WORD, wParam) = %BN_CLICKED THEN
                  SendMessage hWnd, %WM_CLOSE, 0, 0
                  EXIT FUNCTION
               END IF

            CASE 20 : ImgColorBlend &HFFFF00&, &HC0C0C0&
            CASE 21 : ImgColorReplace &H008080&, &HFF0000&
            CASE 22 : ImgFlipBottomTop
            CASE 23 : ImgFlipLeftRight
            CASE 24 : ImgFlip180
            CASE 25 : strText = Edit_GetText(GetDlgItem(hwnd, %IDC_TEXT))
                      ImgDrawText strText

            CASE %IDC_TEXT
               IF HI(WORD, wParam) = %EN_CHANGE THEN
                  strText = Edit_GetText(GetDlgItem(hwnd, %IDC_TEXT))
                  ImgDrawText strText
               END IF

         END SELECT

      CASE %WM_SYSCOMMAND
         ' Capture this message and send a WM_CLOSE message
         IF (wParam AND &HFFF0) = %SC_CLOSE THEN
            SendMessage hWnd, %WM_CLOSE, 0, 0
            EXIT FUNCTION
         END IF

      CASE %WM_DESTROY
         IF hMemDC THEN DeleteDC hMemDC
         IF hBitmap THEN DeleteObject hBitmap
         PostQuitMessage 0
         EXIT FUNCTION

   END SELECT

   FUNCTION = DefWindowProc(hWnd, wMsg, wParam, lParam)

END FUNCTION
' ========================================================================================

' ========================================================================================
' Viewer window callback
' ========================================================================================
FUNCTION ViewerProc (BYVAL hWnd AS DWORD, BYVAL wMsg AS DWORD, _
                     BYVAL wParam AS DWORD, BYVAL lParam AS LONG) AS LONG

   LOCAL rc AS RECT
   LOCAL ps AS PAINTSTRUCT

   SELECT CASE wMsg

      CASE %WM_ERASEBKGND
         FUNCTION = 1
         EXIT FUNCTION

      CASE %WM_PAINT
         GetClientRect hWnd, rc
         BeginPaint hWnd, ps
         BitBlt ps.hDC, 0, 0, rc.nRight, rc.nBottom, hMemDC, 0, 0, %SRCCOPY
         EndPaint hWnd, ps
         EXIT FUNCTION

   END SELECT

   FUNCTION = DefWindowProc(hWnd, wMsg, wParam, lParam)

END FUNCTION
' ========================================================================================

' ========================================================================================
' Draw text, here slightly rotated, using Times New Roman italic font
' ========================================================================================
SUB ImgDrawText (BYVAL strText AS STRING)

   LOCAL x AS LONG
   LOCAL y AS LONG
   LOCAL hFont AS DWORD
   LOCAL hBrush AS DWORD
   LOCAL hBrushOld AS DWORD
   LOCAL Bm AS BITMAP
   LOCAL rc AS RECT
   LOCAL szl AS SIZEL
   LOCAL lf AS LOGFONT

   IF hMemDC = %NULL THEN EXIT SUB

   GetClientRect hViewer, rc

   lf.lfHeight         = 70
   lf.lfWeight         = %FW_BOLD
   lf.lfEscapement     = 170   ' 17 degree angle to match italic font
   lf.lfOrientation    = 170
   lf.lfItalic         = 1
   lf.lfCharSet        = %ANSI_CHARSET
   lf.lfOutPrecision   = %OUT_TT_PRECIS
   lf.lfClipPrecision  = %CLIP_DEFAULT_PRECIS
   lf.lfQuality        = %DEFAULT_QUALITY
   lf.lfPitchAndFamily = %FF_DONTCARE
   lf.lfFaceName       = "Times New Roman"

   hFont     = CreateFontIndirect(lf)
   hFont     = SelectObject(hMemDC, hFont)
   hBrush    = CreateSolidBrush(RGB(0, 128, 128))
   hBrushOld = SelectObject(hMemDC, hBrush)
   FillRect  hMemDC, rc, hBrush

   GetTextExtentPoint32 hMemDC, BYVAL STRPTR(strText), LEN(strText), szl
   x  = (rc.nRight  - szl.cx) / 2
   y  = (rc.nBottom - szl.cy) / 2 + TAN(17 * 4 * ATN(1) / 180) * szl.cx / 2 - 2
   ' y is not 100% correct, but good enough for this demo

   SetTextColor hMemDC, RGB(0,0,0)      ' Shadow
   TextOut hMemDC, x + 2, y + 2, BYVAL STRPTR(strText), LEN(strText)
   TextOut hMemDC, x + 3, y + 3, BYVAL STRPTR(strText), LEN(strText)

   SetTextColor hMemDC, RGB(128,128,0)  ' For smoother look
   TextOut hMemDC, x + 1, y + 1, BYVAL STRPTR(strText), LEN(strText)

   SetTextColor hMemDC, RGB(255,255,0)  ' Yellow text
   TextOut hMemDC, x, y, BYVAL STRPTR(strText), LEN(strText)

   DeleteObject SelectObject(hMemDC, hBrushOld)
   DeleteObject SelectObject(hMemDC, hFont)

   RedrawWindow hViewer, BYVAL 0, BYVAL 0, %RDW_INVALIDATE OR %RDW_UPDATENOW

END SUB
' ========================================================================================

' ========================================================================================
' Look for and replace every other pixel's color1 with color2 (chess pattern)
' ========================================================================================
SUB ImgColorBlend(BYVAL clr AS DWORD, BYVAL clr2 AS DWORD)

   LOCAL j AS LONG
   LOCAL dwp AS DWORD PTR
   LOCAL rowLen AS LONG
   LOCAL Bm AS BITMAP

   GetObject hBitmap, SIZEOF(bm), bm
   rowLen = bm.bmWidth * 4

   FOR j = 0 TO bm.bmHeight - 1                   ' Vertical loop
      dwp = bm.bmBits + j * rowLen                ' Start of row
      IF j MOD 2 THEN dwp = dwp + 4               ' One pixel in on every second row
      FOR dwp = dwp TO dwp + rowLen - 4 STEP 8    ' Check every other pixel in row
         IF @dwp = clr THEN @dwp = clr2
      NEXT
   NEXT

   RedrawWindow hViewer, BYVAL 0, BYVAL 0, %RDW_INVALIDATE OR %RDW_UPDATENOW

END SUB
' ========================================================================================

' ========================================================================================
' Replace all occurrences of color1 with color2
' ========================================================================================
SUB ImgColorReplace(BYVAL clr AS DWORD, BYVAL clr2 AS DWORD)

   LOCAL dwp AS DWORD PTR
   LOCAL Bm AS BITMAP

   GetObject hBitmap, SIZEOF(bm), bm

   FOR dwp = bm.bmBits TO bm.bmBits + (bm.bmWidth * bm.bmHeight * 4) STEP 4
      IF @dwp = clr THEN @dwp = clr2
   NEXT

   RedrawWindow hViewer, BYVAL 0, BYVAL 0, %RDW_INVALIDATE OR %RDW_UPDATENOW

END SUB
' ========================================================================================

' ========================================================================================
' Flip picture top to bottom
' ========================================================================================
SUB ImgFlipBottomTop

   LOCAL i AS LONG
   LOCAL j AS LONG
   LOCAL v1 AS DWORD
   LOCAL v2 AS DWORD
   LOCAL tdwp AS DWORD PTR
   LOCAL dwp AS DWORD PTR
   LOCAL dwp2 AS DWORD PTR
   LOCAL Bm AS BITMAP

   GetObject hBitmap, SIZEOF(bm), bm
   dwp  = bm.bmBits
   dwp2 = dwp + 4 * ((bm.bmWidth * bm.bmHeight) - bm.bmWidth)
   v1   = bm.bmHeight \ 2
   v2   = (bm.bmWidth * 8)

   FOR j = 1 TO v1             ' Vertical loop, top to bottom
      FOR i = 1 TO bm.bmWidth  ' Horizontal loop, row by row
         tdwp  = @dwp
         @dwp  = @dwp2
         @dwp2 = tdwp
         ! add dwp, 4
         ! add dwp2, 4
      NEXT
      dwp2 = dwp2 - v2
   NEXT

   RedrawWindow hViewer, BYVAL 0, BYVAL 0, %RDW_INVALIDATE OR %RDW_UPDATENOW

END SUB
' ========================================================================================

' ========================================================================================
' Flip picture left to right
' ========================================================================================
SUB ImgFlipLeftRight

   LOCAL i AS LONG
   LOCAL j AS LONG
   LOCAL v1 AS DWORD
   LOCAL v2 AS DWORD
   LOCAL v3 AS DWORD
   LOCAL dwp AS DWORD PTR
   LOCAL dwp2 AS DWORD PTR
   LOCAL tdwp AS DWORD PTR
   LOCAL Bm AS BITMAP

   GetObject hBitmap, SIZEOF(bm), bm
   dwp = bm.bmBits
   v1  = bm.bmWidth * 4
   v2  = bm.bmWidth \ 2
   v3  = bm.bmWidth * 2

   FOR j = 1 TO bm.bmHeight  ' Vertical loop, top to bottom
      dwp2  = dwp + v1
      FOR i = 1 TO v2        ' Horizontal loop, row by row
         tdwp  = @dwp        ' Swap color at pos1 with pos2's
         @dwp  = @dwp2
         @dwp2 = tdwp
         ! add dwp, 4
         ! sub dwp2, 4
      NEXT
      dwp = dwp + v3
   NEXT

   RedrawWindow hViewer, BYVAL 0, BYVAL 0, %RDW_INVALIDATE OR %RDW_UPDATENOW

END SUB
' ========================================================================================

' ========================================================================================
' Flip picture 180 degrees (half turn)
' ========================================================================================
SUB ImgFlip180

   LOCAL j AS LONG
   LOCAL dwp AS DWORD PTR
   LOCAL dwp2 AS DWORD PTR
   LOCAL tdwp AS DWORD PTR
   LOCAL Bm AS BITMAP

   GetObject hBitmap, SIZEOF(bm), bm
   dwp  = bm.bmBits
   dwp2 = bm.bmBits + (bm.bmHeight * bm.bmWidth * 4)

   FOR j = 1 TO (bm.bmHeight * bm.bmWidth) \ 2
      tdwp  = @dwp   ' Swap color at pos1 with pos2's
      @dwp  = @dwp2  ' (this is faster than PB's SWAP..)
      @dwp2 = tdwp
      ! add dwp, 4   ' Increase start pos
      ! sub dwp2, 4  ' Decrease end pos
   NEXT

   RedrawWindow hViewer, BYVAL 0, BYVAL 0, %RDW_INVALIDATE OR %RDW_UPDATENOW

END SUB
' ========================================================================================
