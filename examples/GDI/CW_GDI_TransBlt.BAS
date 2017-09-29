' ========================================================================================
' TRANSBLT.BAS - Demonstrates Bitmaps with Transparency
' This is an adaptation of transblt.c (C) Copyright Microsoft Corp. 1993.
' http://support.microsoft.com/kb/q97365/
' TRANSBLT performs transparency and masking effects on bitmaps.
' ========================================================================================

' CSED_PBWIN - Use the PBWIN compiler
#COMPILE EXE
#DIM ALL
%UNICODE = 1

' // Include files for external files
#INCLUDE ONCE "CWindow.inc"   ' // CWindow class
#RESOURCE RES, "CW_GDI_TransBlt.res"

%IDM_ABOUT = 100

%IDM_MASK1 = 200
%IDM_MASK2 = 201
%IDM_MASK3 = 202

%IDM_BLACK = 300
%IDM_RED   = 301
%IDM_DRED  = 302
%IDM_GREEN = 303
%IDM_CYAN  = 304

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
   pWindow.CreateWindow(%NULL, "TransBlt Sample Application", 0, 0, 0, 0, 0, 0, CODEPTR(WindowProc))
   ' // Change the background color
   pWindow.Brush = %COLOR_WINDOW + 1
   ' // Set the client size
   pWindow.SetClientSize 500, 320
   ' // Center the window
   pWindow.CenterWindow

   ' // Load the menu
   LOCAL hMenu AS DWORD
   hMenu = LoadMenu(hInstance, "transbltMenu")
   SetMenu pWindow.hwnd, hMenu

   ' // Default message pump (you can replace it with your own)
   pWindow.DoEvents(nCmdShow)

END FUNCTION
' ========================================================================================

' ========================================================================================
' Main window procedure
' ========================================================================================
FUNCTION WindowProc (BYVAL hwnd AS DWORD, BYVAL wMsg AS DWORD, BYVAL wParam AS DWORD, BYVAL lParam AS LONG) AS LONG

   STATIC rgbWhite        AS DWORD
   STATIC rgbBlack        AS DWORD
   STATIC rgbTransparent  AS DWORD
   STATIC hbmHouse        AS DWORD
   STATIC hbmFade         AS DWORD
   STATIC hbmDefault      AS DWORD
   STATIC hbmBinoculars   AS DWORD
   STATIC hbmTransMask    AS DWORD
   STATIC hdcMem          AS DWORD
   STATIC hdcMem2         AS DWORD
   STATIC bTransMaskBuilt AS LONG
   STATIC dwMaskType      AS DWORD           ' mask being demoed
   STATIC dwTransColor    AS DWORD           ' transparent color
   DIM    HouseColor(4)   AS STATIC DWORD
   LOCAL  hdcScreen       AS DWORD
   LOCAL  hbr             AS DWORD
   LOCAL  i               AS LONG
   DIM    poly(2)         AS POINTAPI
   LOCAL  ps              AS PAINTSTRUCT
   LOCAL  x               AS DWORD
   LOCAL  y               AS DWORD
   LOCAL  oldMode         AS DWORD
   LOCAL  rgbOld          AS DWORD
   STATIC hInstance       AS DWORD
   LOCAL  lpc             AS CREATESTRUCT PTR

   SELECT CASE wMsg

      CASE %WM_CREATE

         lpc = lParam
         hInstance = @lpc.hInstance
         dwMaskType = %IDM_MASK1     ' mask being demoed
         dwTransColor = %IDM_BLACK    ' transparent color
         HouseColor(0) = RGB(0, 0, 0)
         HouseColor(1) = RGB(255, 0, 0)
         HouseColor(2) = RGB(128, 0, 0)
         HouseColor(3) = RGB (0, 255, 0)
         HouseColor(4) = RGB(0, 255, 255)
         rgbWhite = RGB(255, 255, 255)
         rgbBlack = RGB(0, 0, 0)
         rgbTransparent = HouseColor(dwTransColor - %IDM_BLACK)

         ' Build the bitmaps
         hdcScreen = GetDC(%NULL)
         hbmHouse = CreateCompatibleBitmap(hdcScreen, 50, 50)
         hbmFade = CreateCompatibleBitmap(hdcScreen, 100, 100)
         hbmBinoculars = CreateBitmap(50, 50, 1, 1, BYVAL %NULL)
         hbmTransMask = CreateBitmap(50, 50, 1, 1, BYVAL %NULL)
         hdcMem = CreateCompatibleDC(hdcScreen)
         hdcMem2 = CreateCompatibleDC(hdcScreen)
         ReleaseDC %NULL, hdcScreen

         ' Draw the house bitmap.  This will be the basic source bitmap.
         SelectObject(hdcMem, GetStockObject(%NULL_PEN))
         hbmDefault = SelectObject(hdcMem, hbmHouse)

         ' sky.
         hbr = CreateSolidBrush(RGB(0, 255, 255))
         hbr = SelectObject(hdcMem, hbr)
         PatBlt hdcMem, 0, 0, 50, 30, %PATCOPY
         hbr = SelectObject(hdcMem, hbr)
         DeleteObject hbr

         ' horizon.
         PatBlt hdcMem, 0, 30, 50, 31, %BLACKNESS

         ' lawn
         hbr = CreateSolidBrush(RGB(0, 255, 0))
         hbr = SelectObject(hdcMem, hbr)
         PatBlt hdcMem, 0, 31, 50, 20, %PATCOPY
         hbr = SelectObject(hdcMem, hbr)
         DeleteObject hbr

         ' house body
         hbr = CreateSolidBrush(RGB(255, 0, 0))
         hbr = SelectObject(hdcMem, hbr)
         PatBlt hdcMem, 5, 20, 40, 20, %PATCOPY
         hbr = SelectObject(hdcMem, hbr)
         DeleteObject hbr

         ' house roof
         hbr = CreateSolidBrush(RGB(128, 0, 0))
         hbr = SelectObject(hdcMem, hbr)
         poly(0).x = 2
         poly(0).y = 20
         poly(1).x = 47
         poly(1).y = 20
         poly(2).x = 25
         poly(2).y = 5
         Polygon hdcMem, poly(0), 3
         hbr = SelectObject(hdcMem, hbr)
         DeleteObject hbr

         ' windows
         hbr = SelectObject(hdcMem, GetStockObject(%BLACK_BRUSH))
         PatBlt hdcMem, 10, 22, 12, 13, %BLACKNESS
         PatBlt hdcMem, 28, 22, 12, 13, %BLACKNESS

         ' build the fade background bitmap.
         SelectObject hdcMem, hbmFade
         FOR i = 56 TO 255 STEP 2
            hbr = CreateSolidBrush(RGB(i, 0, i))
            hbr = SelectObject(hdcMem, hbr)
            PatBlt hdcMem, 0, (i - 56)/2, 100, 3, %PATCOPY
            hbr = SelectObject(hdcMem, hbr)
            DeleteObject hbr
         NEXT

         ' build the binoculars true mask.
         SelectObject hdcMem, hbmBinoculars
         PatBlt hdcMem, 0, 0, 50, 50, %WHITENESS
         SelectObject(hdcMem, GetStockObject(%BLACK_BRUSH))
         Ellipse hdcMem, 7, 7, 24, 43
         Ellipse hdcMem, 26, 7, 43, 43

         SelectObject hdcMem, hbmDefault

         EXIT FUNCTION

      CASE %WM_INITMENU
         CheckMenuItem wParam, dwMaskType, %MF_CHECKED
         CheckMenuItem wParam, dwTransColor, %MF_CHECKED
         EXIT FUNCTION

      CASE %WM_COMMAND
         SELECT CASE LO(WORD, wParam)

            CASE %IDCANCEL
               IF HI(WORD, wParam) = %BN_CLICKED THEN
                  SendMessage hWnd, %WM_CLOSE, 0, 0
                  EXIT FUNCTION
               END IF

            CASE %IDM_ABOUT
               DialogBox hInstance, "AboutBox", hWnd, CODEPTR(AboutDlgProc)
               EXIT FUNCTION

            CASE %IDM_MASK1, %IDM_MASK2, %IDM_MASK3
               IF LO(WORD, wParam) <> dwMaskType THEN
                  CheckMenuItem GetMenu(hWnd), dwMaskType, %MF_UNCHECKED
                  dwMaskType = LO(WORD, wParam)
                  CheckMenuItem GetMenu(hWnd), dwMaskType, %MF_CHECKED
                  InvalidateRect hWnd, BYVAL %NULL, %TRUE
                  EXIT FUNCTION
               END IF

            CASE %IDM_BLACK, %IDM_RED, %IDM_DRED, %IDM_GREEN, %IDM_CYAN
               IF LO(WORD, wParam) <> dwTransColor THEN
                  CheckMenuItem GetMenu(hWnd), dwTransColor, %MF_UNCHECKED
                  dwTransColor = LO(WORD, wParam)
                  CheckMenuItem GetMenu(hWnd), dwTransColor, %MF_UNCHECKED
                  rgbTransparent = HouseColor(dwTransColor - %IDM_BLACK)
                  bTransMaskBuilt = %FALSE
                  InvalidateRect hWnd, BYVAL %NULL, %TRUE
                  EXIT FUNCTION
               END IF

         END SELECT

      CASE %WM_PAINT
         hdcScreen = BeginPaint(hWnd, ps)
         ' fill in destination space
         SelectObject hdcMem, hbmFade
         BitBlt hdcScreen, 300, 0, 100, 100, hdcMem, 0, 0, %SRCCOPY
         SetBkColor hdcScreen, rgbWhite
         SetTextColor hdcScreen, rgbBlack
         x = 320 : y = 20
         SELECT CASE dwMaskType
            CASE %IDM_MASK1
               SelectObject hdcMem, hbmHouse
               SelectObject hdcMem2, hbmBinoculars
               ShowStatus hdcScreen, hdcMem, hdcMem2, hbmFade
               BitBlt hdcScreen, x, y, 50, 50, hdcMem, 0, 0, %SRCINVERT
               BitBlt hdcScreen, x, y, 50, 50, hdcMem2, 0, 0, %SRCAND
               BitBlt hdcScreen, x, y, 50, 50, hdcMem, 0, 0, %SRCINVERT
            CASE %IDM_MASK2, %IDM_MASK3
               SelectObject hdcMem, hbmHouse
               SelectObject hdcMem2, hbmTransMask
               ' if the device supports transparency, let it do the work.
               IF (GetDeviceCaps(hdcScreen, %CAPS1) AND %C1_TRANSPARENT) THEN
                  oldMode = SetBkMode(hdcScreen, %NEWTRANSPARENT)
                  rgbOld = SetBkColor(hdcScreen, rgbTransparent)
                  BitBlt hdcScreen, x, y, 50, 50, hdcMem, 0, 0, %SRCCOPY
                  SetBkColor hdcScreen, rgbOld
                  SetBkMode hdcScreen, oldMode
               ELSE
                  ' build mask based on transparent color.
                  IF ISFALSE bTransMaskBuilt THEN
                     bTransMaskBuilt = %TRUE
                     SetBkColor hdcMem, rgbTransparent
                     BitBlt hdcMem2, 0, 0, 50, 50, hdcMem, 0, 0, %SRCCOPY
                  END IF
                  ShowStatus hdcScreen, hdcMem, hdcMem2, hbmFade
                  '/ using a true mask.
                  IF dwMaskType = %IDM_MASK2 THEN
                     BitBlt hdcScreen, x, y, 50, 50, hdcMem, 0, 0, %SRCINVERT
                     BitBlt hdcScreen, x, y, 50, 50, hdcMem2, 0, 0, %SRCAND
                     BitBlt hdcScreen, x, y, 50, 50, hdcMem, 0, 0, %SRCINVERT
                  ELSE
                     ' using the black-source method.
                     ' if transparent color is black, the house bitmap is
                     ' ready for use.  Otherwise, put black in the right
                     ' place for masking.
                     IF dwTransColor <> %IDM_BLACK THEN
                        SetBkColor hdcMem, rgbBlack
                        SetTextColor hdcMem, rgbWhite
                        BitBlt hdcMem, 0, 0, 50, 50, hdcMem2, 0, 0, %SRCAND
                        ' show the modified bitmap
                        BitBlt hdcScreen, 120, 150, 50, 50, hdcMem, 0, 0, %SRCCOPY
                        TextOut hdcScreen, 100, 220, "(Modified Source)", 17
                     END IF
                     BitBlt hdcScreen, x, y, 50, 50, hdcMem2, 0, 0, %SRCAND
                     BitBlt hdcScreen, x, y, 50, 50, hdcMem, 0, 0, %SRCPAINT
                     ' undo work on house bitmap.
                     IF dwTransColor <> %IDM_BLACK THEN
                        SetBkColor hdcMem, rgbTransparent
                        SetTextColor hdcMem, rgbBlack
                        BitBlt hdcMem, 0, 0, 50, 50, hdcMem2, 0, 0, %SRCPAINT
                     END IF
                  END IF
                  SelectObject hdcMem, hbmDefault
                  SelectObject hdcMem2, hbmDefault
                  EndPaint hWnd, ps
               END IF
         END SELECT
         EXIT FUNCTION

     CASE %WM_DESTROY
         DeleteObject hbmHouse
         DeleteObject hbmFade
         DeleteObject hbmBinoculars
         DeleteObject hbmTransMask
         DeleteDC hdcMem
         DeleteDC hdcMem2
         PostQuitMessage 0
         EXIT FUNCTION

   END SELECT

   FUNCTION = DefWindowProc(hwnd, wMsg, wParam, lParam)

END FUNCTION
' ========================================================================================

' ========================================================================================
SUB ShowStatus (BYVAL hdcDst AS DWORD, BYVAL hdcSrc AS DWORD, BYVAL hdcMask AS DWORD, BYVAL hbmFade AS DWORD)

   LOCAL hbm AS DWORD

   hbm = SelectObject(hdcSrc, hbmFade)
   BitBlt hdcDst, 0, 0, 100, 100, hdcSrc, 0, 0, %SRCCOPY
   SelectObject hdcSrc, hbm
   TextOut hdcDst, 0, 110, "Destination", 11

   BitBlt hdcDst, 120, 20, 50, 50, hdcSrc, 0, 0, %SRCCOPY
   TextOut hdcDst, 100, 110, "+ Source", 8

   IF hdcMask THEN
      BitBlt hdcDst, 220, 20, 50, 50, hdcMask, 0, 0, %SRCCOPY
      TextOut hdcDst, 200, 110, "+ Mask", 6
   END IF

   TextOut hdcDst, 300, 110, "= Transparency", 14

END SUB
' ========================================================================================

' ========================================================================================
FUNCTION AboutDlgProc (BYVAL hDlg AS DWORD, BYVAL message AS DWORD, BYVAL wParam AS DWORD, BYVAL lParam AS LONG) AS LONG

   SELECT CASE message

      CASE %WM_INITDIALOG
         FUNCTION = %TRUE
         EXIT FUNCTION

      CASE %WM_COMMAND
         SELECT CASE LO(WORD, wParam)
            CASE %IDOK, %IDCANCEL
               EndDialog hDlg, 0
               FUNCTION = %TRUE
               EXIT FUNCTION
         END SELECT

   END SELECT

END FUNCTION
' ========================================================================================
