' ########################################################################################
' Oval Button Custom Control
' http://www.powerbasic.com/support/forums/Forum7/HTML/000791.html
' Updated to PBWIN 9.01 by José Roca, April 2009.
' ----------------------------------------------------------------------------------------
' Public Domain, December 2000 by Borje Hagsten. A special thank you
' to Dave Navarro, Chris Boss and Lance Edmonds for the lessons on how
' to deal with custom controls, brushes, font handles and other GDI objects.
'
' Please feel free to use and modify as you whish - Merry Christmas! :-)
' See log on changes to the code at the bottom of this page.
'
' Fully working, both mouse and keyboard actions are trapped and handled
' in a way I believe is correct. Tested for memory leaks and seems to be
' both safe and working well. Commented code, hope you can follow.
'
' Example on how to easily add and use the control in a program
' provided. All you have to do is to add #INCLUDE "OVALBUTN.INC"
' to your code and then add the control with CONTROL ADD "OVALBUTTON"..
' or via API, CreateWindow("OVALBUTTON"..
' See sample program for more on this. Could also be compiled as a
' DLL or added to a collection of custom controls, but it's nicer to
' embed and avoid extra DLL's when we can, right?
'
' Hopefully we can get together a whole library of free custom controls
' for embedding in our PB prog's one day. Stay tuned for more..  :-)
' ########################################################################################

#COMPILE EXE
#INCLUDE "windows.inc"

' ========================================================================================
' Initialize procedure for the custom control
' ========================================================================================
FUNCTION InitOvalBtn() AS LONG

   LOCAL wc          AS WNDCLASS
   LOCAL szClassName AS ASCIIZ * 12 '<- change for longer classnames..

   ' Register custom control window class.
   szClassName      = "OVALBUTTON"
   wc.style         = %CS_HREDRAW OR %CS_VREDRAW OR %CS_PARENTDC OR %CS_GLOBALCLASS
   wc.lpfnWndProc   = CODEPTR(OvalBtnProc)
   wc.cbClsExtra    = 0
   wc.cbWndExtra    = 20    ' 5 x 4 (Long) pre-allocated bytes for unique data
   wc.hInstance     = GetModuleHandle(BYVAL %NULL)
   wc.hIcon         = %NULL
   wc.hCursor       = LoadCursor(%NULL, BYVAL %IDC_HAND) '<- I like the hand here..
   wc.hbrBackground = %COLOR_BTNFACE + 1
   wc.lpszMenuName  = %NULL
   wc.lpszClassName = VARPTR(szClassName)

   FUNCTION = RegisterClass(wc)

END FUNCTION
' ========================================================================================

' ========================================================================================
' Oval Button Custom Control Procedure
' ========================================================================================
FUNCTION OvalBtnProc (BYVAL hWnd AS DWORD, BYVAL wMsg AS DWORD, _
                      BYVAL wParam AS DWORD, BYVAL lParam AS LONG) AS LONG

   SELECT CASE wMsg

      CASE %WM_CREATE

         LOCAL rc       AS RECT
         LOCAL pt       AS POINT
         LOCAL hFontOld AS DWORD
         LOCAL hRgn     AS DWORD   ' SetWindowLong hWnd,  0, hRgn
         LOCAL hFont    AS DWORD   ' SetWindowLong hWnd,  4,   (not used here)
         LOCAL dn       AS LONG    ' SetWindowLong hWnd,  8, dn
         LOCAL dClicked AS LONG    ' SetWindowLong hWnd, 12, dClicked

         GetClientRect(hWnd, rc)

         ' Create an elliptic region, to keep drawing and mouse actions, etc.
         ' to the actual form of the control (oval).
         hRgn = CreateEllipticRgn(0, 0, rc.nRight, rc.nBottom)
         IF hRgn THEN
            SetWindowRgn(hWnd, hRgn, %TRUE)
            SetWindowLong hWnd, 0, hRgn '<- store region's handle
         END IF

         EXIT FUNCTION

     CASE %WM_DESTROY
         GetWindowRgn(hWnd, hRgn)
         IF hRgn THEN DeleteObject hRgn
         EXIT FUNCTION

     CASE %WM_SETFOCUS, %WM_KILLFOCUS   ' Set focus rect on button through WM_PAINT
         InvalidateRect hWnd, BYVAL %NULL, 0 : UpdateWindow hWnd
         EXIT FUNCTION

     CASE %WM_KEYDOWN
         dn = GetWindowLong(hWnd, 8)
         dClicked = GetWindowLong(hWnd, 12)
         IF dn OR dClicked THEN EXIT SELECT
         SetCapture hWnd                 ' Trap Space bar and Enter key
         IF wParam = %VK_SPACE OR HIWRD(GetKeyState(%VK_RETURN)) <> 0 THEN
            dn = %TRUE : SetWindowLong hWnd,  8, dn
            InvalidateRect hWnd, BYVAL %NULL, 0 : UpdateWindow hWnd
            FUNCTION = 0 : EXIT FUNCTION
         END IF

     CASE %WM_KEYUP                     ' Act on Space bar and Enter key
         IF wParam = %VK_SPACE OR wParam = %VK_RETURN THEN
            dClicked = GetWindowLong(hWnd, 12)
            IF dClicked THEN EXIT SELECT
            ReleaseCapture
            dn = GetWindowLong(hWnd, 8)
            IF dn OR wParam = %VK_RETURN  THEN
               dn = %FALSE : SetWindowLong hWnd,  8, dn
               InvalidateRect hWnd, BYVAL %NULL, 0 : UpdateWindow hWnd
               ' Not sure about %BM_CLICK here. Regular buttons seems to send zero, but..?
               SendMessage GetParent(hWnd), %WM_COMMAND, MAKLNG(GetDlgCtrlID(hWnd), %BM_CLICK), hWnd
            END IF
            dn = %FALSE : SetWindowLong hWnd,  8, dn
            InvalidateRect hWnd, BYVAL %NULL, 0 : UpdateWindow hWnd
            EXIT FUNCTION
        END IF

     CASE %WM_MOUSEMOVE   ' Make sure it acts as should if pressed down and mouse is moved
         dClicked = GetWindowLong(hWnd, 12)
         IF wParam = %MK_LBUTTON AND dClicked THEN
            hRgn = GetWindowLong(hWnd, 0)
            dn = GetWindowLong(hWnd, 8)
            GetCursorPos(pt)
            IF PtInRegion(hRgn, pt.x, pt.y) THEN
               IF dn = %TRUE THEN EXIT SELECT '<- to avoid unnecessary redrawing
               dn = %TRUE
            ELSE
               IF dn = 0 THEN EXIT SELECT
               dn = %FALSE
            END IF
            SetWindowLong hWnd,  8, dn
            InvalidateRect hWnd, BYVAL %NULL, 0 : UpdateWindow hWnd
        END IF

     CASE %WM_LBUTTONDOWN
         dClicked = %TRUE : SetWindowLong hWnd, 12, dClicked ' <- a flag for %WM_MOUSEMOVE
         IF GetFocus <> hWnd THEN SetFocus hWnd  ' Set the focus to clicked control
         SetCapture hWnd  ' <-- set and keep capture to current control
         dn = %TRUE : SetWindowLong hWnd,  8, dn
         InvalidateRect hWnd, BYVAL %NULL, 0 : UpdateWindow hWnd
         EXIT FUNCTION

     CASE %WM_LBUTTONUP
         dn = GetWindowLong(hWnd, 8)
         IF dn THEN  ' Not sure about %BM_CLICK here either. Maybe should be zero?
            dn = %FALSE : SetWindowLong hWnd,  8, dn
            InvalidateRect hWnd, BYVAL %NULL, 0 : UpdateWindow hWnd
            SendMessage GetParent(hWnd), %WM_COMMAND, MAKLNG(GetDlgCtrlID(hWnd), %BM_CLICK), hWnd
         END IF
         dClicked = %FALSE : SetWindowLong hWnd, 12, dClicked
         ReleaseCapture
         EXIT FUNCTION

      CASE %WM_PAINT
         ' This is where the button is drawn. I'm not be the best artist,
         ' but it looks quite ok. Please feel free to experiment here and
         ' make better-looking buttons, or add graphics, etc. to them.

         LOCAL zCaption AS ASCIIZ * 100
         LOCAL ps       AS PaintStruct
         LOCAL rcTxtUp  AS RECT, rcTxtDn AS RECT
         LOCAL hDC      AS DWORD, hPen AS DWORD, hPenOld AS DWORD

         '=== Initialize ============================================
         hDC = BeginPaint(hWnd, ps)
         hFont = GetStockObject(%ANSI_VAR_FONT)
         IF hFont THEN hFontOld = SelectObject(hDC, hFont)
         SetBkColor(hDC, GetSysColor(%COLOR_BTNFACE))
         SetTextColor(hDC, GetSysColor(%COLOR_BTNTEXT))

         '=== Get Rect and Caption ==================================
         GetClientRect(hWnd, rc)
         GetWindowText(hWnd, zCaption, 100)

         '=== make two different text RECT's for up and down ========
         rcTxtUp.nLeft = 16 : rcTxtUp.nRight  = rc.nRight - 16
         rcTxtUp.nTop  = 4  : rcTxtUp.nBottom = rc.nBottom - 6
         rcTxtDn.nLeft = 17 : rcTxtDn.nRight  = rc.nRight - 15
         rcTxtDn.nTop  = 5  : rcTxtDn.nBottom = rc.nBottom - 5

         '=== Draw Button (oval) =====================================
         dn = GetWindowLong(hWnd, 8)
         IF dn THEN  ' Button down
            DrawText hDC, zCaption, -1, rcTxtDn, %DT_SINGLELINE OR %DT_VCENTER OR %DT_CENTER
            DrawButn hDC, 1, 0, %COLOR_BTNTEXT, rc    'Black
            DrawButn hDC, 1, 1, %COLOR_BTNSHADOW, rc  'Gray
            DrawButn hDC, 0, 2, %COLOR_BTNFACE, rc    'Light Gray
            DrawButn hDC, 0, 1, %COLOR_BTNHILIGHT, rc 'White
         ELSE        'Button up
            DrawText hDC, zCaption, -1, rcTxtUp, %DT_SINGLELINE OR %DT_VCENTER OR %DT_CENTER
            DrawButn hDC, 1, 0, %COLOR_BTNHILIGHT, rc  'White
            DrawButn hDC, 1, 1, %COLOR_BTNFACE, rc     'Light Gray
            DrawButn hDC, 0, 2, %COLOR_BTNSHADOW, rc   'Gray
            DrawButn hDC, 0, 1, %COLOR_BTNTEXT, rc     'Black
         END IF

        '=== Draw Focus rect (oval) =================================
         IF GetFocus = hWnd THEN
            hPen = CreatePen(%PS_SOLID, 1, GetSysColor(%COLOR_BTNSHADOW))
         ELSE
            hPen = CreatePen(%PS_SOLID, 1, GetSysColor(%COLOR_BTNFACE))
         END IF
         hPenOld = SelectObject(hDC, hPen)
         Arc hDC, 6, 4, rc.nright-6, rc.nbottom-5, _  ' <- Focus rectangle bounds
                  0, 0, 0, 0                          ' <- all zero for full oval
         SelectObject hDC, hPenOld
         DeleteObject hPen

         '=== End paint procedure ====================================
         SelectObject hDC, hFontOld
         EndPaint hWnd, ps
         EXIT FUNCTION

   END SELECT

   ' Default processing for other messages.
   FUNCTION = DefWindowProc(hWnd, wMsg, wParam, lParam)

END FUNCTION
' ========================================================================================

' ========================================================================================
' Draw oval button
' ========================================================================================
SUB DrawButn(BYVAL hDC AS DWORD, BYVAL UpLow AS LONG, BYVAL n AS LONG, _
             BYVAL sCol AS LONG, rc AS RECT)

   LOCAL hPen AS DWORD, hPenOld AS DWORD

   hPen  = CreatePen(%PS_SOLID, 1, GetSysColor(sCol))
   hPenOld = SelectObject(hDC, hPen)

   IF UpLow = 1 THEN ' draw upper left part of oval
      Arc hDC, n, n, rc.nright-n, rc.nbottom-n, _
               rc.nright, rc.nbottom / 3.5, 1, rc.nbottom / 2 + 5

   ELSE              ' draw lower right part of oval
      Arc hDC, n, n, rc.nright-n, rc.nbottom-n, _
               1, rc.nbottom / 2 + 5, rc.nright, rc.nbottom / 3.5
   END IF

   SelectObject hDC, hPenOld
   DeleteObject hPen

END SUB
' ========================================================================================


' ########################################################################################
' Small PB/DDT sample on how to use the Oval Custom Control Buttons
' ########################################################################################

' ========================================================================================
' Create Dialog and controls
' ========================================================================================
FUNCTION PBMAIN () AS LONG

   LOCAL hDlg AS LONG
   DIALOG NEW 0, "Custom Control Buttons", ,, 149, 115, %WS_SYSMENU TO hDlg

   CONTROL ADD BUTTON, hDlg, 101, "Regular button",      4, 4, 69, 14
   CONTROL ADD BUTTON, hDlg, 102, "Another boring one", 73, 4, 69, 14

   InitOvalBtn   ' Initialize custom control button in OVALBUTN.INC
                 ' Then add custom control buttons the normal way
   CONTROL ADD "OVALBUTTON", hDlg, 201, "Click me!",  4, 26, 70, 20, _
               %WS_CHILD OR %WS_VISIBLE OR %WS_TABSTOP
   CONTROL ADD "OVALBUTTON", hDlg, 202, "Me to!",    74, 26, 70, 20, _
               %WS_CHILD OR %WS_VISIBLE OR %WS_TABSTOP
   CONTROL ADD "OVALBUTTON", hDlg, 203, "Exit",      34, 48, 80, 30, _
               %WS_CHILD OR %WS_VISIBLE OR %WS_TABSTOP

   CONTROL ADD LABEL, hDlg, 301, "Use Tab to move around..", 4, 85, 138, 12, _
                      %SS_CENTER, %WS_EX_CLIENTEDGE

   DIALOG SHOW MODAL hDlg, CALL DlgMainProc

END FUNCTION
' ========================================================================================

' ========================================================================================
' Dialog Callback procedure
' ========================================================================================
CALLBACK FUNCTION DlgMainProc

   STATIC hBrushBack AS LONG
   LOCAL txt AS STRING

   SELECT CASE CB.MSG
      CASE %WM_INITDIALOG
         hBrushBack = CreateSolidBrush(RGB(255, 255, 244))

      CASE %WM_CTLCOLORSTATIC         ' Set a bright background to the label
         IF CB.LPARAM = GetDlgItem(CB.HNDL, 301) THEN FUNCTION = hBrushBack

      CASE %WM_COMMAND
         SELECT CASE CB.CTL           ' Handle all controls in one place
            CASE 101 : BEEP
            CASE 102 : BEEP
            CASE 201                  ' I prefer the MessageBox API..  :-)
               MessageBox(CB.HNDL, "Neat, eh?", "Custom Control Buttons", _
                          %MB_OK OR %MB_ICONQUESTION)
            CASE 202 : BEEP
            CASE 203                 ' User tries to exit via custom control button
               IF EndProcedure(CB.HNDL) = %TRUE THEN
                  DIALOG END CB.HNDL       'Close the program
               END IF
         END SELECT
         CONTROL GET TEXT CB.HNDL, CBCTL TO txt
         CONTROL SET TEXT CB.HNDL, 301, "Button Caption:  " & txt

      CASE %WM_SYSCOMMAND   ' User tries to exit via System menu/button Close
         IF CB.WPARAM = %SC_CLOSE THEN
            IF EndProcedure(CB.HNDL) = %FALSE THEN
              FUNCTION = 1   ' Return 1 to stop from exiting
              EXIT FUNCTION
            END IF
        END IF

      CASE %WM_DESTROY
         DeleteObject hBrushBack 'Delete brush to avoid memory leaks

   END SELECT

END FUNCTION
' ========================================================================================

' ========================================================================================
' Useful End procedure
' ========================================================================================
FUNCTION EndProcedure(BYVAL hWnd AS LONG) AS LONG
   IF MessageBox(hWnd, "Exit program?", "Custom Control Button", _
                %MB_YESNO OR %MB_ICONQUESTION) = %IDYES THEN
      FUNCTION = %TRUE
      EXIT FUNCTION
   END IF
END FUNCTION
' ========================================================================================
