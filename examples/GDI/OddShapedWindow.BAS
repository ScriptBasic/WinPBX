' ########################################################################################
' Odd shaped window demo
' Based on an example by Jules Marchildon
' http://www.powerbasic.com/support/pbforums/showthread.php?t=22622
' ########################################################################################

#COMPILE EXE
#DIM ALL
#DEBUG ERROR ON
#INCLUDE "windows.inc"

' ========================================================================================
' Main
' ========================================================================================
FUNCTION WinMain (BYVAL hInstance AS DWORD, BYVAL hPrevInstance AS DWORD, BYVAL lpszCmdLine AS WSTRINGZ PTR, BYVAL nCmdShow AS LONG) AS LONG

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
   szClassName        = "OSW"
   wcex.cbSize        = SIZEOF(wcex)
   wcex.style         = %CS_HREDRAW OR %CS_VREDRAW
   wcex.lpfnWndProc   = CODEPTR(WndProc)
   wcex.cbClsExtra    = 0
   wcex.cbWndExtra    = 0
   wcex.hInstance     = hInstance
   wcex.hCursor       = LoadCursor (%NULL, BYVAL %IDC_ARROW)
   wcex.hbrBackground = CreateSolidBrush(RGB(255,0,0))
   wcex.lpszMenuName  = %NULL
   wcex.lpszClassName = VARPTR(szClassName)
   wcex.hIcon         = LoadIcon (%NULL, BYVAL %IDI_APPLICATION)
   wcex.hIconSm       = LoadIcon (%NULL, BYVAL %IDI_APPLICATION)
   RegisterClassEx wcex

   ' Window caption
   szCaption = "Odd Shaped Window"

   ' Create a window using the registered class
   hWndMain = CreateWindowEx(%WS_EX_CONTROLPARENT, _           ' extended style
                             szClassName, _                    ' window class name
                             szCaption, _                      ' window caption
                             %WS_CAPTION OR %WS_SYSMENU, _     ' window style
                             100, _                            ' initial x position
                             200, _                            ' initial y position
                             530, _                            ' initial x size
                             155, _                            ' initial y size
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

   LOCAL rc       AS RECT
   LOCAL hRgn     AS DWORD
   LOCAL hDC      AS DWORD
   LOCAL hRgn1    AS DWORD
   LOCAL hRgn2    AS DWORD
   LOCAL hFont    AS DWORD
   LOCAL hOldFont AS DWORD
   LOCAL szText   AS ASCIIZ * 255

   SELECT CASE wMsg

      CASE %WM_CREATE
         hDC = GetDC(hWnd)
         szText = "PBWIN"
         hFont = CreateFont(200, 0, 0, 0, 1000, _
            %FALSE, %FALSE, %FALSE, _
            %ANSI_CHARSET, %OUT_CHARACTER_PRECIS, _
            %CLIP_DEFAULT_PRECIS, %PROOF_QUALITY, _
            %FIXED_PITCH , "Courier New")
         hOldFont = SelectObject(hDC, hFont)
         BeginPath hDC
         TextOut hDC, 0, 0, szText, LEN(szText)
         EndPath hDC
         hRgn1 = PathToRegion(hDC)
         GetRgnBox(hRgn1, rc)
         hRgn2 = CreateRectRgnIndirect(rc)
         CombineRgn hRgn2, hRgn2, hRgn1, %RGN_XOR   ' <-- Try %RGN_AND
         DeleteObject hRgn1
         ReleaseDC hWnd, hDC
         SetWindowRgn hWnd, hRgn2, 1
         SelectObject hDC, hOldFont
         DeleteObject hFont

      CASE %WM_COMMAND
         SELECT CASE LO(WORD, wParam)
            CASE %IDCANCEL
               IF HI(WORD, wParam) = %BN_CLICKED THEN
                  SendMessage hWnd, %WM_CLOSE, 0, 0
                  EXIT FUNCTION
               END IF
         END SELECT

      CASE %WM_LBUTTONDOWN
         ReleaseCapture
         SendMessage hWnd, %WM_NCLBUTTONDOWN, %HTCAPTION, %NULL
         EXIT FUNCTION

      CASE %WM_DESTROY
         PostQuitMessage 0
         EXIT FUNCTION

   END SELECT

   FUNCTION = DefWindowProc(hWnd, wMsg, wParam, lParam)

END FUNCTION
' ========================================================================================
