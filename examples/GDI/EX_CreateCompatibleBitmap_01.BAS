' ========================================================================================
' Displays the text string "Hello, world!" on a small bitmap and then does a BitBlt from
' the bitmap to the program's client area.
' ========================================================================================

#COMPILE EXE
#DIM ALL
#INCLUDE "windows.inc"

' ========================================================================================
' Main
' ========================================================================================
FUNCTION WinMain (BYVAL hInstance AS DWORD, BYVAL hPrevInstance AS DWORD, BYVAL lpszCmdLine AS ASCIIZ PTR, BYVAL nCmdShow AS LONG) AS LONG

   LOCAL hWndMain    AS DWORD
   LOCAL hCtl        AS DWORD
   LOCAL hFont       AS DWORD
   LOCAL wcex        AS WNDCLASSEX
   LOCAL szClassName AS ASCIIZ * 80
   LOCAL rc          AS RECT
   LOCAL szCaption   AS ASCIIZ * 255
   LOCAL nLeft       AS LONG
   LOCAL nTop        AS LONG
   LOCAL nWidth      AS LONG
   LOCAL nHeight     AS LONG

   hFont = GetStockObject(%ANSI_VAR_FONT)

   ' Register the window class
   szClassName        = "MyClassName"
   wcex.cbSize        = SIZEOF(wcex)
   wcex.style         = 0 ' %CS_HREDRAW OR %CS_VREDRAW
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

   ' Window caption
   szCaption = "CreateCompatibleBitmap Example"

   ' Retrieve the size of the working area
   SystemParametersInfo %SPI_GETWORKAREA, 0, BYVAL VARPTR(rc), 0

   ' Calculate the position and size of the window
   nWidth  = (((rc.nRight - rc.nLeft)) + 2) * 0.75   ' 75% of the client screen width
   nHeight = (((rc.nBottom - rc.nTop)) + 2) * 0.70   ' 70% of the client screen height
   nLeft   = ((rc.nRight - rc.nLeft) \ 2) - nWidth \ 2
   nTop    = ((rc.nBottom - rc.nTop) \ 2) - (nHeight \ 2)

   ' Create a window using the registered class
   hWndMain = CreateWindowEx(%WS_EX_CONTROLPARENT, _           ' extended style
                             szClassName, _                    ' window class name
                             szCaption, _                      ' window caption
                             %WS_OVERLAPPEDWINDOW OR _
                             %WS_CLIPCHILDREN, _               ' window styles
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
' Main Window procedure
' ========================================================================================
FUNCTION WndProc (BYVAL hWnd AS DWORD, BYVAL wMsg AS DWORD, BYVAL wParam AS DWORD, BYVAL lParam AS LONG) AS LONG

   STATIC hBitmap  AS DWORD
   STATIC hdcMem   AS DWORD
   STATIC cxBitmap AS LONG
   STATIC cyBitmap AS LONG
   STATIC cxClient AS LONG
   STATIC cyClient AS LONG
   STATIC szText   AS ASCIIZ * 256
   LOCAL  hdc      AS DWORD
   LOCAL  hMenu    AS DWORD
   LOCAL  x        AS LONG
   LOCAL  y        AS LONG
   LOCAL  ps       AS PAINTSTRUCT
   LOCAL  tsize    AS APISIZE

   SELECT CASE wMsg

      CASE %WM_CREATE
         szText = "Hello, world! "
         hdc = GetDC(hwnd)
         hdcMem = CreateCompatibleDC(hdc)
         GetTextExtentPoint32 hdc, szText, LEN(szText), tsize
         cxBitmap = tsize.cx
         cyBitmap = tsize.cy
         hBitmap = CreateCompatibleBitmap(hdc, cxBitmap, cyBitmap)
         ReleaseDC hwnd, hdc
         SelectObject hdcMem, hBitmap
         TextOut hdcMem, 0, 0, szText, LEN(szText)
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
