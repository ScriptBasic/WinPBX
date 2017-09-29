' ========================================================================================
' Demostrates the use of the SQLGetTranslator function
' ========================================================================================

#COMPILE EXE
#DIM ALL
#INCLUDE ONCE "odbcinst.inc"

' ========================================================================================
' Main
' ========================================================================================
FUNCTION WINMAIN (BYVAL hInstance AS DWORD, BYVAL hPrevInstance AS DWORD, BYVAL lpszCmdLine AS ASCIIZ PTR, BYVAL nCmdShow AS LONG) AS LONG

   LOCAL hWndMain AS DWORD
   LOCAL hCtl AS DWORD
   LOCAL hFont AS DWORD
   LOCAL wcex AS WndClassEx
   LOCAL szClassName AS ASCIIZ * 80
   LOCAL rc AS RECT
   LOCAL szCaption AS ASCIIZ * 255
   LOCAL nLeft AS LONG
   LOCAL nTop AS LONG
   LOCAL nWidth AS LONG
   LOCAL nHeight AS LONG

   hFont = GetStockObject(%ANSI_VAR_FONT)

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

   ' Window caption
   szCaption = "SQLGetTranslator Demo"

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
                             %WS_CLIPCHILDREN, _               ' window style
                             nLeft, _                          ' initial x position
                             nTop, _                           ' initial y position
                             nWidth, _                         ' initial x size
                             nHeight, _                        ' initial y size
                             %NULL, _                          ' parent window handle
                             0, _                              ' window menu handle
                             hInstance, _                      ' program instance handle
                             BYVAL %NULL)                      ' creation parameters

   hCtl = CreateWindowEx(0, "BUTTON", "&Ok", %WS_CHILD OR %WS_VISIBLE OR %WS_TABSTOP OR %BS_FLAT, _
          0, 0, 0, 0, hWndMain, %IDOK, hInstance, BYVAL %NULL)
   IF hFont THEN SendMessage hCtl, %WM_SETFONT, hFont, 0

   hCtl = CreateWindowEx(0, "BUTTON", "&Close", %WS_CHILD OR %WS_VISIBLE OR %WS_TABSTOP OR %BS_FLAT, _
          0, 0, 0, 0, hWndMain, %IDCANCEL, hInstance, BYVAL %NULL)
   IF hFont THEN SendMessage hCtl, %WM_SETFONT, hFont, 0

   ' Show the window
   ShowWindow hWndMain, nCmdShow
   UpdateWindow hWndMain

   ' Message handler loop
   LOCAL Msg AS tagMsg
   WHILE GetMessage(Msg, %NULL, 0, 0)
      IF ISFALSE IsDialogMessage(hWndMain, Msg) THEN
         TranslateMessage Msg
         DispatchMessage Msg
      END IF
   WEND

   FUNCTION = msg.wParam

END FUNCTION
' ========================================================================================

' ========================================================================================
' Main Window procedure
' ========================================================================================
FUNCTION WndProc (BYVAL hWnd AS DWORD, BYVAL wMsg AS DWORD, BYVAL wParam AS DWORD, BYVAL lParam AS LONG) AS LONG

   LOCAL rc AS RECT

   SELECT CASE wMsg

      CASE %WM_SIZE
         ' Resize the two sample buttons of the dialog
         IF wParam <> %SIZE_MINIMIZED THEN
            GetClientRect hWnd, rc
            MoveWindow GetDlgItem(hWNd, %IDOK), (rc.nRight - rc.nLeft) - 185, (rc.nBottom - rc.nTop) - 35, 75, 23, %TRUE
            MoveWindow GetDlgItem(hWNd, %IDCANCEL), (rc.nRight - rc.nLeft) - 95, (rc.nBottom - rc.nTop) - 35, 75, 23, %TRUE
         END IF

      CASE %WM_COMMAND
         SELECT CASE LOWRD(wParam)

            CASE %IDOK
               IF HIWRD(wParam) = %BN_CLICKED THEN
                  LOCAL szName AS ASCIIZ * 1025
                  LOCAL szPath AS ASCIIZ * %MAX_PATH + 1
                  LOCAL pcbNameOut AS WORD
                  LOCAL pcbPathOut AS WORD
                  LOCAL pvOption AS DWORD
                  FUNCTION = SQLGetTranslator(hWnd, szName, SIZEOF(szName), pcbNameOut, szPath, SIZEOF(szPath), pcbPathOut, pvOption)
                  szName = LEFT$(szName, pcbNameOut)
                  szPath = LEFT$(szPath, pcbPathOut)
                  ? "Name: " &  szName & $CRLF & "Path: " & szPath & $CRLF & "Option:" & STR$(pvOption)
               END IF

            CASE %IDCANCEL
               IF HIWRD(wParam) = %BN_CLICKED THEN
                  SendMessage hWnd, %WM_DESTROY, wParam, lParam
                  FUNCTION = 0
                  EXIT FUNCTION
               END IF

         END SELECT

      CASE %WM_DESTROY
         PostQuitMessage 0    ' This function closes the main window
         FUNCTION = 0         ' by sending zero to the main message loop
         EXIT FUNCTION

   END SELECT

   FUNCTION = DefWindowProc(hWnd, wMsg, wParam, lParam)

END FUNCTION
' ========================================================================================
