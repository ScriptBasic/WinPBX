' ########################################################################################
' Create a complex window region from a bitmap
'
' Author Patrice Terrier
' http://www.zapsolution.com
' http://www.powerbasic.com/support/forums/Forum7/HTML/002269.html
' March 18, 2004 12:30 PM
' Adapted by José Roca, April 2009
'
' Use Escape click to close the window
' Hold down left mouse to drag the window.
' ########################################################################################

#COMPILE EXE
#DIM ALL
#INCLUDE "windows.inc"

GLOBAL UseBitmap AS LONG

' ========================================================================================
' Get bitmap size.
' ========================================================================================
SUB GetPixmapSize (BYVAL hBmp AS DWORD, BYREF xWidth AS LONG, BYREF yHeight AS LONG)
   LOCAL bm AS BITMAP
   IF hBmp THEN
      GetObject(hBmp, SIZEOF(bm), bm)
      xWidth = bm.bmWidth
      yHeight = bm.bmHeight
   END IF
END SUB
' ========================================================================================

' ========================================================================================
' Convert bitmap to region.
' ========================================================================================
FUNCTION ConvertBitmapToRgn (BYVAL hBmp AS DWORD, BYVAL TransColor AS LONG) AS DWORD

   LOCAL bm         AS BITMAP
   LOCAL rc         AS RECT
   LOCAL bi         AS BITMAPINFO
   LOCAL rdh        AS RGNDATAHEADER PTR
   LOCAL os         AS OSVERSIONINFO
   LOCAL lpRect     AS RECT PTR
   LOCAL MaxRegions AS LONG
   LOCAL pWidth     AS LONG
   LOCAL pHeight    AS LONG
   LOCAL hDC        AS DWORD
   LOCAL hMem1DC    AS DWORD
   LOCAL hMem2DC    AS DWORD
   LOCAL hTmpBmp    AS DWORD
   LOCAL hToDIB     AS DWORD
   LOCAL TT         AS LONG
   LOCAL T          AS LONG
   LOCAL RegionData AS STRING
   LOCAL hRgn1      AS DWORD
   LOCAL hRgn2      AS DWORD
   LOCAL I          AS LONG
   LOCAL J          AS LONG
   LOCAL K          AS LONG
   LOCAL M          AS LONG
   DIM   Ar()       AS LONG

   MaxRegions = 4000
   GetPixmapSize(hBmp, pWidth, pHeight)
   hDC = CreateIC ("DISPLAY", BYVAL %NULL, BYVAL %NULL, BYVAL %NULL)

   hMem1DC = CreateCompatibleDC(hDC)
   hMem2DC = CreateCompatibleDC(hDC)
   hTmpBmp = CreateCompatibleBitmap(hDC, pWidth, pHeight)
   SelectObject(hMem1DC, hBmp)
   SelectObject(hMem2DC, hTmpBmp)
   BitBlt(hMem2DC, 0, 0, pWidth, pHeight, hMem1DC, 0, 0, %SRCCOPY)

   bi.bmiHeader.biSize = SIZEOF(bi.bmiHeader)
   bi.bmiHeader.biWidth = pWidth
   bi.bmiHeader.biHeight = pHeight
   bi.bmiHeader.biPlanes = 1
   bi.bmiHeader.biBitCount = 32
   bi.bmiHeader.biCompression = %BI_RGB

   hToDIB = CreateDIBSection(hMem1DC, bi, %DIB_RGB_COLORS, 0, 0, 0)

   SelectObject(hMem1DC, hToDIB)
   GetObject(hToDIB, SIZEOF(bm), bm)
   BitBlt(hMem1DC, 0, 0, pWidth, pHeight, hMem2DC, 0, 0, %SRCCOPY)

   REDIM Ar(0) AT bm.bmBits
   TT = 0

   ' Set up the transparent color
   IF TransColor = -1 THEN
      T = (Ar((pHeight - 1) * pWidth) AND &HFFFFFF)'<--- (0, 0)
   ELSE
      T = TransColor ' Common Trancolor is magenta &HFF00FF
   END IF

   RegionData = STRING$(SIZEOF(RGNDATAHEADER) + SIZEOF(RECT) * MaxRegions, 0)
   rdh = STRPTR(RegionData)
   @rdh.nCount = MaxRegions + 1
   @rdh.dwSize = SIZEOF(RGNDATAHEADER)
   @rdh.iType = %RDH_RECTANGLES
   @rdh.rcBound.nLeft = 0
   @rdh.rcBound.nTop = 0
   @rdh.rcBound.nRight = pWidth
   @rdh.rcBound.nBottom = pHeight
   FOR J = 0 TO pHeight - 1
      TT = pWidth * (pHeight - 1 - J)
      M = -1
      FOR I = 0 TO pWidth
         IF I = pWidth THEN K = T ELSE K = (Ar(TT) AND &HFFFFFF)
         INCR TT
         IF K <> T THEN
            IF M = -1 THEN M = I
         ELSEIF M >= 0 THEN
            IF @rdh.nCount >= MaxRegions THEN
               hRgn2 = ExtCreateRegion(BYVAL %NULL, SIZEOF(RGNDATAHEADER) + (SIZEOF(RECT) * @rdh.nCount), BYVAL rdh)
               IF hRgn1 = 0 THEN
                  hRgn1 = hRgn2
               ELSE
                  CombineRgn(hRgn1, hRgn1, hRgn2, %RGN_OR)
                  DeleteObject(hRgn2)
               END IF
               lpRect = SIZEOF(RGNDATAHEADER) + rdh
               @rdh.nCount = 0
            END IF
            INCR @rdh.nCount
            @lpRect.nLeft = M
            @lpRect.nRight = I
            @lpRect.nTop = J
            @lpRect.nBottom = J + 1
            lpRect = lpRect + SIZEOF(RECT)
            M = -1
         END IF
      NEXT
   NEXT
   hRgn2 = ExtCreateRegion(BYVAL 0, SIZEOF(RGNDATAHEADER) + (SIZEOF(RECT) * @rdh.nCount), BYVAL rdh)
   IF hRgn1 = 0 THEN
      hRgn1 = hRgn2
   ELSE
      CombineRgn(hRgn1, hRgn1, hRgn2, %RGN_OR)
      DeleteObject(hRgn2)
   END IF

   DeleteDC(hMem1DC)
   DeleteDC(hMem2DC)
   DeleteDC(hDC)
   DeleteObject(hTmpBmp)
   DeleteObject(hToDIB)

   FUNCTION = hRgn1

END FUNCTION
' ========================================================================================

' ========================================================================================
' Main Window procedure
' ========================================================================================
FUNCTION WndProc (BYVAL hWnd AS DWORD, BYVAL wMsg AS DWORD, BYVAL wParam AS DWORD, BYVAL lParam AS LONG) AS LONG

   LOCAL hDC AS DWORD
   LOCAL xSize AS LONG
   LOCAL ySize AS LONG

   SELECT CASE wMsg

      CASE %WM_SYSCOMMAND
         ' Capture this message and send a WM_CLOSE message
         IF (wParam AND &HFFF0) = %SC_CLOSE THEN
            SendMessage hWnd, %WM_CLOSE, 0, 0
            EXIT FUNCTION
         END IF

      CASE %WM_COMMAND
         SELECT CASE LO(WORD, wParam)
            CASE %IDOK, %IDCANCEL
               IF HI(WORD, wParam) = %BN_CLICKED THEN
                  SendMessage hWnd, %WM_CLOSE, 0, 0
                  EXIT FUNCTION
               END IF
         END SELECT

      CASE %WM_ERASEBKGND
         hDC = CreateCompatibleDC(wParam)
         GetPixmapSize(UseBitmap, xSize, ySize)
         SelectObject hDC, UseBitmap
         BitBlt wParam, 0, 0, xSize, ySize, hDC, 0, 0, %SRCCOPY
         DeleteDC hDC
         FUNCTION = 1
         EXIT FUNCTION

      CASE %WM_RBUTTONDOWN
         PostQuitMessage(0)
         EXIT FUNCTION

      CASE %WM_DESTROY
         PostQuitMessage 0
         EXIT FUNCTION

   END SELECT

   FUNCTION = DefWindowProc(hWnd, wMsg, wParam, lParam)

   EXIT FUNCTION

END FUNCTION

' ========================================================================================
' Main
' ========================================================================================
FUNCTION WinMain (BYVAL hInstance AS DWORD, BYVAL hPrevInstance AS DWORD, BYVAL lpszCmdLine AS ASCIIZ PTR, BYVAL nCmdShow AS LONG) AS LONG

   LOCAL wcex        AS WNDCLASSEX
   LOCAL szClassName AS ASCIIZ * 80
   LOCAL hFrame      AS DWORD
   LOCAL BmpFile     AS STRING
   LOCAL dwStyle     AS DWORD
   LOCAL XouT        AS LONG
   LOCAL YouT        AS LONG
   LOCAL hRgnClip    AS DWORD

   IF LEN(COMMAND$) = 0 THEN
      BmpFile = "Nenufars.bmp"
   ELSE
      BmpFile = COMMAND$
   END IF
   IF LEN(DIR$(BmpFile)) = 0 THEN EXIT FUNCTION

   szClassName = "REGION"

   wcex.cbSize        = SIZEOF(wcex)
   wcex.style         = %CS_HREDRAW OR %CS_VREDRAW
   wcex.lpfnWndProc   = CODEPTR(WndProc)
   wcex.cbClsExtra    = 0
   wcex.cbWndExtra    = 0
   wcex.hInstance     = hInstance
   wcex.hIcon         = %NULL 'LoadIcon(hInstance, "PROGRAM")
   wcex.hCursor       = LoadCursor(%NULL, BYVAL %IDC_ARROW)
   wcex.hbrBackground = GetStockObject( %LTGRAY_BRUSH )
   wcex.lpszMenuName  = %NULL
   wcex.lpszClassName = VARPTR(szClassName)
   wcex.hIconSm       = 0
   RegisterClassEx(wcex)

   dwStyle = %WS_POPUP OR %WS_VISIBLE  OR %WS_SYSMENU 'OR %WS_CLIPCHILDREN

   UseBitmap = LoadImage(BYVAL %NULL, (BmpFile), %IMAGE_BITMAP, 0, 0, %LR_LOADFROMFILE)
   GetPixmapSize(UseBitmap, XouT, YouT)

   dwStyle = %WS_POPUP OR %WS_SYSMENU
   hFrame  = CreateWindowEx( _
             0, _                       ' window extended style
             szClassName, _             ' window class name
             szClassName, _             ' window title
             dwStyle, _                 ' window style
             0, _                       ' initial x position
             0, _                       ' initial y position
             XouT, _                    ' initial x size
             YouT, _                    ' initial y size
             %NULL, _                   ' parent window handle
             %NULL, _                   ' window menu handle
             hInstance, _               ' program instance handle
             BYVAL %NULL)               ' creation parameters

   IF hFrame = 0 THEN EXIT FUNCTION

   IF UseBitmap THEN
      hRgnClip = ConvertBitmapToRgn(UseBitmap, -1)
      IF hRgnClip THEN SetWindowRgn(hFrame, hRgnClip, %TRUE)
   END IF

   ShowWindow(hFrame, %SW_SHOW)
   UpdateWindow(hFrame)

   ' Message handler loop
   LOCAL uMsg AS tagMsg
   WHILE GetMessage(uMsg, %NULL, 0, 0)
      IF ISFALSE IsDialogMessage(hFrame, uMsg) THEN
         TranslateMessage uMsg
         DispatchMessage uMsg
      END IF
   WEND

   IF UseBitmap THEN DeleteObject(UseBitmap)

   FUNCTION = uMsg.wParam

END FUNCTION
' ========================================================================================
