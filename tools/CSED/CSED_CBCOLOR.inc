' ########################################################################################
' CSED Editor
' File: CSED_CBCOLOR.INC
' Contents: Owner draw combo box for color selection
' Based on code by Börje Hagsten, January 2001
' Copyright (c) 2011 José Roca
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

%CBCOL_SETAUTOCOLOR = %WM_USER + 100
%CBCOL_SETUSERCOLOR = %WM_USER + 101
%CBCOL_GETAUTOCOLOR = %WM_USER + 200
%CBCOL_GETUSERCOLOR = %WM_USER + 201
%CBCOL_GETSELCOLOR  = %WM_USER + 202

TYPE CBCOLORDATA
   oldProc   AS LONG
   autoColor AS LONG
   userColor AS LONG
   cols(15)  AS LONG
END TYPE
$CBCOLORDATAPTR = "CBCOLORDATAPTR"

' ========================================================================================
FUNCTION CSED_CreateCBColorList (BYVAL hwnd AS LONG, BYVAL CtrlId AS LONG, _
                                 BYVAL nLeft AS LONG, BYVAL nTop AS LONG, _
                                 BYVAL nWidth AS LONG, BYVAL nHeight AS LONG, _
                                 BYVAL autoCol AS LONG, BYVAL userCol AS LONG, _
                                 BYVAL rxRatio AS SINGLE, BYVAL ryRatio AS SINGLE _
                                 ) AS LONG

   LOCAL i AS LONG
   LOCAL cl AS LONG
   LOCAL hCombo AS LONG
   LOCAL cbc AS CBCOLORDATA PTR
#IF %DEF(%UNICODE)
   REDIM arr(17) AS WSTRING
#ELSE
   REDIM arr(17) AS STRING
#ENDIF

   ' // Create items for combo list
   arr(0)  = "Auto"          : arr(1)  = "Black"
   arr(2)  = "Blue"          : arr(3)  = "Green"
   arr(4)  = "Cyan"          : arr(5)  = "Red"
   arr(6)  = "Magenta"       : arr(7)  = "Brown"
   arr(8)  = "Light Gray"    : arr(9)  = "Gray"
   arr(10) = "Light Blue"    : arr(11) = "Light Green"
   arr(12) = "Light Cyan"    : arr(13) = "Light Red"
   arr(14) = "Light Magenta" : arr(15) = "Yellow"
   arr(16) = "Bright White"  : arr(17) = "User-selected..."

   hCombo = CreateWindowEx(%WS_EX_CLIENTEDGE, "COMBOBOX", BYVAL 0, %WS_VISIBLE OR _
                           %WS_CHILD OR %WS_VISIBLE OR %CBS_OWNERDRAWFIXED OR %CBS_HASSTRINGS OR _
                           %CBS_DROPDOWNLIST OR %WS_TABSTOP OR %CBS_DISABLENOSCROLL OR %WS_VSCROLL, _
                           nLeft * rxRatio, nTop * ryRatio, nWidth * rxRatio, nHeight * ryRatio, _
                           hwnd, CtrlId, GetWindowLong(hwnd, %GWL_HINSTANCE), BYVAL 0)
   IF hCombo = 0 THEN EXIT FUNCTION

   ' // Add items to the combo box
   IF hCombo THEN
      FOR i = 0 TO UBOUND(arr)
         SendMessage hCombo, %CB_ADDSTRING, 0, BYVAL STRPTR(arr(i))
      NEXT
   END IF

   cbc = HeapAlloc(GetProcessHeap(), %HEAP_ZERO_MEMORY, SIZEOF(@cbc))
   IF cbc = 0 THEN EXIT FUNCTION

   ' // Subclass the combo and initialize some control specific data
   @cbc.oldProc   = SetWindowLong(hCombo, %GWL_WNDPROC, BYVAL CODEPTR(CSED_CBProc))
   @cbc.autoColor = autoCol                 ' // Usually %COLOR_WINDOW or %COLOR_WINDOWTEXT
   @cbc.userColor = userCol                 ' // Same here
   FOR i = 1 TO 16                          ' // create initial grayscale color map for
      cl = i * 16 - 1                       ' // COMDLG32's extra colors in ChooseColor dialog
      @cbc.cols(16 - i) = RGB(cl, cl, cl)   ' // Note: array is static, but still local to each created control..
   NEXT
   SetProp hCombo, $CBCOLORDATAPTR, cbc     ' // Store pointer to memory for UDT in control's property list

   FUNCTION = hCombo

END FUNCTION
' ========================================================================================

' ========================================================================================
' Subclassed Combobox procedure
' ========================================================================================
FUNCTION CSED_CBProc(BYVAL hwnd AS LONG, BYVAL wMsg AS LONG, BYVAL wParam AS LONG, BYVAL lParam AS LONG) AS LONG

   LOCAL cbc AS CBCOLORDATA PTR

   ' // Get stored data
   cbc = GetProp(hwnd, $CBCOLORDATAPTR)

   SELECT CASE wMsg
      ' // Allows programmer to change auto color
      CASE %CBCOL_SETAUTOCOLOR
         @cbc.autoColor = wParam
      ' // Allows programmer to change user selected color
      CASE %CBCOL_SETUSERCOLOR
         @cbc.userColor = wParam
      ' // Allows programmer to get selected auto color
      CASE %CBCOL_GETAUTOCOLOR
         FUNCTION = @cbc.autoColor
         EXIT FUNCTION
      ' // Allows programmer to get selected user color
      CASE %CBCOL_GETUSERCOLOR
         FUNCTION = @cbc.userColor
         EXIT FUNCTION
      ' // Return selected color
      CASE %CBCOL_GETSELCOLOR
         LOCAL lRes AS LONG
         lRes = SendMessage(hwnd, %CB_GETCURSEL, 0, 0)
         IF lRes > %CB_ERR THEN FUNCTION = CSED_GetQBColor(hwnd, lRes, 1)
         EXIT FUNCTION

      ' // Unsubclass the combo box
      CASE %WM_DESTROY
         IF @cbc.oldProc THEN SetWindowLong hwnd, %GWL_WNDPROC, @cbc.oldProc
         IF cbc THEN HeapFree GetProcessHeap(), 0, BYVAL cbc
         RemoveProp hwnd, $CBCOLORDATAPTR
         EXIT FUNCTION

      CASE %WM_DRAWITEM
         LOCAL hBrush AS LONG
         LOCAL lpdis AS DRAWITEMSTRUCT PTR
         LOCAL rc AS RECT
#IF %DEF(%UNICODE)
         LOCAL szText AS WSTRINGZ * 80
#ELSE
         LOCAL szText AS ASCIIZ * 80
#ENDIF
         lpdis = lParam
         IF @lpdis.itemID = &HFFFFFFFF& THEN EXIT FUNCTION

         SELECT CASE @lpdis.itemAction
            CASE %ODA_DRAWENTIRE, %ODA_SELECT
               ' // Clear background
               FillRect @lpdis.hDC, @lpdis.rcItem, GetSysColorBrush(%COLOR_WINDOW)
               ' // Get text
               SendMessage hwnd, %CB_GETLBTEXT, @lpdis.itemID, VARPTR(szText)
               ' // Set text background
               SetBkColor @lpdis.hDC, GetSysColor(%COLOR_WINDOW)
               ' // Set text color
               SetTextColor @lpdis.hDC, GetSysColor(%COLOR_WINDOWTEXT)
               rc = @lpdis.rcItem
               rc.Left = 28
               DrawText @lpdis.hDC, szText, LEN(szText), rc, %DT_SINGLELINE OR %DT_LEFT OR %DT_VCENTER
               ' // Selected item
               IF (@lpdis.itemState AND %ODS_SELECTED) THEN   ' // If selected
                  IF (@lpdis.itemState AND &H1000) = 0 THEN   ' // If not %ODS_COMBOBOXEDIT (= &H1000)
                     ' // Set coordinates
                     rc.Left = 26
                     rc.Right = @lpdis.rcItem.Right
                     rc.Top = @lpdis.rcItem.Top
                     rc.Bottom = @lpdis.rcItem.Bottom
                     ' // Invert area around text only
                     InvertRect @lpdis.hDC, rc
                  END IF
                  ' // and draw a focus rectangle around all
                  DrawFocusRect @lpdis.hDC, @lpdis.rcItem
               END IF

               ' // Paint color rectangle (using RoundRect for nicer looks.. :-)
               IF (@lpdis.itemState AND &H1000) THEN          ' // If %ODS_COMBOBOXEDIT (= &H1000)
                  ' // Set coordinates
                  rc.Left = 4
                  rc.Right = 24
               ELSE
                  ' // A tiny bit to the left in list
                  rc.Left = 3
                  rc.Right = 23
               END IF
               rc.Top = @lpdis.rcItem.Top + 2
               rc.Bottom = @lpdis.rcItem.Bottom - 2
               ' // Create brush with proper color
               hBrush = CreateSolidBrush(CSED_GetQBColor(hwnd, @lpdis.itemID, 0))
               ' // Select brush into device context
               hBrush = SelectObject(@lpdis.hDC, hBrush)
               ' // Draw
               RoundRect @lpdis.hDC, rc.Left, rc.Top, rc.Right, rc.Bottom, 3, 3
               ' // Select old brush and delete the new one
               DeleteObject SelectObject(@lpdis.hDC, hBrush)

         END SELECT
         FUNCTION = %TRUE
         EXIT FUNCTION

   END SELECT

   FUNCTION = CallWindowProc(@cbc.oldProc, hwnd, wMsg, wParam, lParam) 'pass on for processing in oldProc

END FUNCTION
' ========================================================================================

' ========================================================================================
' Basic QB color function.
' ========================================================================================
FUNCTION CSED_GetQBColor(BYVAL hwnd AS LONG, BYVAL c AS LONG, BYVAL bShowDlg AS LONG) AS LONG

   LOCAL cbc AS CBCOLORDATA PTR

   cbc = GetProp(hwnd, $CBCOLORDATAPTR)

   SELECT CASE c
      CASE  0 : FUNCTION = @cbc.autoColor     ' // pre-set system color, like %COLOR_WINDOW or %COLOR_WINDOWTEXT
      CASE  1 : FUNCTION = RGB(0,0,0)         ' // Black
      CASE  2 : FUNCTION = RGB(0,0,128)       ' // Blue
      CASE  3 : FUNCTION = RGB(0,128,0)       ' // Green
      CASE  4 : FUNCTION = RGB(0,128,128)     ' // Cyan
      CASE  5 : FUNCTION = RGB(196,0,0)       ' // Red
      CASE  6 : FUNCTION = RGB(128,0,128)     ' // Magenta
      CASE  7 : FUNCTION = RGB(128,64,0)      ' // Brown
      CASE  8 : FUNCTION = RGB(196,196,196)   ' // Light Gray
      CASE  9 : FUNCTION = RGB(128,128,128)   ' // Gray
      CASE 10 : FUNCTION = RGB(0,0,255)       ' // Light Blue
      CASE 11 : FUNCTION = RGB(0,255,0)       ' // Light Green
      CASE 12 : FUNCTION = RGB(0,255,255)     ' // Light Cyan
      CASE 13 : FUNCTION = RGB(255,0,0)       ' // Light Red
      CASE 14 : FUNCTION = RGB(255,0,255)     ' // Light Magenta
      CASE 15 : FUNCTION = RGB(255,255,0)     ' // Yellow
      CASE 16 : FUNCTION = RGB(255,255,255)   ' // Bright White
      CASE 17
         ' // Show COMDLG32's color selection dialog
         IF bShowDlg THEN
            LOCAL cc AS CHOOSECOLORAPI
            cc.lStructSize  = SIZEOF(cc)
            ' // Pointer to defined custom colors
            cc.lpCustColors = VARPTR(@cbc.cols(0))
            ' // Show entire dialog
            cc.Flags = %CC_RGBINIT OR %CC_FULLOPEN
            cc.hwndowner = hwnd
            ' // Give the dialog a chance to "auto-select" previously selected color
            ' // (only works for base colors, but still better than nothing...)
            cc.rgbResult = @cbc.userColor
            ' Otherwise, userColor is same as before
            IF ChooseColor(cc) THEN @cbc.userColor = cc.rgbResult
         END IF
         ' // Return user-selected color
         FUNCTION = @cbc.userColor
   END SELECT

END FUNCTION
' ========================================================================================