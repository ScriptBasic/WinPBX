' ########################################################################################
' WebBrowser example
' ########################################################################################

' SED_PBWIN - Use the PBWIN compiler
#COMPILE EXE
#DIM ALL
#INCLUDE "OLECON.INC"     ' // Ole Container
#INCLUDE "EXDISP.INC"   ' // WebBrowser Control
#INCLUDE "MSHTML.INC"   ' // MSHTML
#INCLUDE "AcroPDF.INC"  ' // Adobe Acrobat Browser Control

%IDC_IEWB = 101

' ========================================================================================
' PROCEDURE: PreTranslateMessage
' PURPOSE:   Preprocesses messages.
' RETURN:    TRUE if message was processed, FALSE if it was not.
' ========================================================================================

FUNCTION PreTranslateMessage ( _
   BYVAL hWnd  AS DWORD, _   ' handle of window
   BYREF Msg   AS tagMsg _   ' message information
   ) AS LONG

   ' Retrieve the handle of the window that hosts the WebBrowser control
   LOCAL hCtrl AS DWORD
   hCtrl = GetDlgItem(hWnd, %IDC_IEWB)

   ' Retrieve the ancestor of the control that has the focus
   LOCAL hWndCtrl AS DWORD
   hWndCtrl = GetFocus
   DO
      IF ISFALSE GetParent(hWndCtrl) OR GetParent(hWndCtrl) = hWnd THEN EXIT DO
      hWndCtrl = GetParent(hWndCtrl)
   LOOP

   ' %WM_FORWARDMSG = &H37F
   ' If the focus is in the WebBrowser, forward the message to it
   IF hCtrl = hWndCtrl THEN
      IF ISTRUE SendMessage(hCtrl, &H37F, 0, VARPTR(Msg)) THEN FUNCTION = %TRUE
   END IF

END FUNCTION
' ========================================================================================

' ========================================================================================
' Main
' ========================================================================================
FUNCTION WINMAIN (BYVAL hInstance AS DWORD, BYVAL hPrevInstance AS DWORD, BYVAL lpszCmdLine AS ASCIIZ PTR, BYVAL nCmdShow AS LONG) AS LONG

   LOCAL hWndMain AS dword
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

   OC_WinInit  ' Initialize the Ole Container

   hFont = GetStockObject(%ANSI_VAR_FONT)

   ' Register the window class
   szClassName        = "WebBrowser"
   wcex.cbSize        = SIZEOF(wcex)
   wcex.style         = 0 '%CS_HREDRAW OR %CS_VREDRAW
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
   szCaption = "WebBrowser Test - Embeding Acrobat"

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

   hCtl = CreateWindowEx(0, "BUTTON", "&Show Print Dialog", %WS_CHILD OR %WS_VISIBLE OR %WS_TABSTOP OR %BS_FLAT, _
          0, 0, 0, 0, hWndMain, %IDOK, hInstance, BYVAL %NULL)
   IF hFont THEN SendMessage hCtl, %WM_SETFONT, hFont, 0

   ' Show the window
   ShowWindow hWndMain, nCmdShow
   UpdateWindow hWndMain

   ' Message handler loop
   LOCAL Msg AS tagMsg
   WHILE GetMessage(Msg, %NULL, 0, 0)
      IF ISFALSE PreTranslateMessage(hWndMain, Msg) THEN
         IF ISFALSE IsDialogMessage(hWndMain, Msg) THEN
            TranslateMessage Msg
            DispatchMessage Msg
         END IF
      END IF
   WEND

   FUNCTION = msg.wParam

END FUNCTION
' ========================================================================================

' ========================================================================================
' Main Window procedure
' ========================================================================================
FUNCTION WndProc (BYVAL hWnd AS DWORD, BYVAL wMsg AS DWORD, BYVAL wParam AS DWORD, BYVAL lParam AS LONG) AS LONG

   LOCAL hr AS LONG
   LOCAL hCtl AS DWORD
   LOCAL rc AS RECT
   LOCAL pIWebBrowser2 AS IWebBrowser2
   LOCAL vUrl AS VARIANT
   LOCAL pIHTMLDocument AS IHTMLDocument
   LOCAL pIAcroAXDocShim AS IAcroAXDocShim

   SELECT CASE wMsg

      CASE %WM_CREATE
         ' Get the coordinates of the main window client area
         GetClientRect hWnd, rc
         ' Create an instance of the WebBrowser Control using ATL as the OLE container
         hCtl = CreateWindowEx(0, $OC_CLASSNAME, "Shell.Explorer", %WS_CHILD OR %WS_VISIBLE OR %WS_TABSTOP OR %WS_BORDER, _
                0, 0, 0, 0, hWnd, %IDC_IEWB, GetModuleHandle(""), BYVAL %NULL)
         ' Set the focus in the WebBrowser Control
         SetFocus hCtl
         ' Get a pointer to the IWebBrowser2 interface
         pIWebBrowser2 = OC_GetDispatch(GetDlgItem(hWnd, %IDC_IEWB))
         IF ISOBJECT(pIWebBrowser2) THEN
            ' Load the PDF document
            vUrl = EXE.Path$ & "ComCollections.pdf"
            pIWebBrowser2.Navigate2(vUrl)
            ' Release the interface
            pIWebBrowser2 = NOTHING
         END IF

      CASE %WM_SIZE
         ' Resizes the control
         IF wParam <> %SIZE_MINIMIZED THEN
            GetClientRect hWnd, rc
            MoveWindow GetDlgItem(hWnd, %IDOK), (rc.nRight - rc.nLeft) - 185, (rc.nBottom - rc.nTop) - 35, 120, 23, %TRUE
            MoveWindow GetDlgItem(hWnd, %IDC_IEWB), 0, 0, rc.nRight - rc.nLeft, rc.nBottom - rc.nTop - 60, %TRUE
         END IF

      CASE %WM_COMMAND
         ' -------------------------------------------------------
         ' Messages from controls and menu items are handled here.
         ' -------------------------------------------------------
         SELECT CASE LOWRD(wParam)

            CASE %IDCANCEL
               IF HIWRD(wParam) = %BN_CLICKED THEN
                  SendMessage hWnd, %WM_CLOSE, wParam, lParam
                  FUNCTION = 0
                  EXIT FUNCTION
               END IF

            CASE %IDOK
               IF HIWRD(wParam) = %BN_CLICKED THEN
                  pIWebBrowser2 = OC_GetDispatch(GetDlgItem(hWnd, %IDC_IEWB))
                  IF ISTRUE ISOBJECT(pIWebBrowser2) THEN
                     ' Get a reference to the active document
                     pIHTMLDocument = pIWebBrowser2.Document
                     IF ISTRUE ISOBJECT(pIHTMLDocument) THEN
                        ' Retrieve a reference to the IAcroAXDocShim interface
                        pIAcroAXDocShim = pIHTMLDocument
                        ' Show the print dialog
                        IF ISTRUE ISOBJECT(pIAcroAXDocShim) THEN
                           pIAcroAXDocShim.PrintWithDialog
                           pIAcroAXDocShim = NOTHING
                        END IF
                        pIHTMLDocument = NOTHING
                     END IF
                     pIWebBrowser2 = NOTHING
                  END IF
               END IF

         END SELECT

      CASE %WM_SYSCOMMAND
         ' Capture this message and send a WM_CLOSE message
         IF (wParam AND &HFFF0) = %SC_CLOSE THEN
            SendMessage hWnd, %WM_CLOSE, wParam, lParam
            EXIT FUNCTION
         END IF

      CASE %WM_DESTROY
         PostQuitMessage 0
         EXIT FUNCTION

   END SELECT

   FUNCTION = DefWindowProc(hWnd, wMsg, wParam, lParam)

END FUNCTION
' ========================================================================================
