' ########################################################################################
' Color Picker
' http://www.powerbasic.com/support/forums/Forum7/HTML/001024.html
' Color-by-Name Chooser, associated NAME with color, and normal color chooser dialog.
' Sends RGB() text strings to the Clipboard for pasting into your PowerBasic Sourc Code.
' Creates and updates cColor.cfg file for your custom colors.
' As usual no warranty applies, use at your own risk.
' By Jules Marchildon <jmarchildon@look.ca>, June/2001
' Adapted by José Roca, April 2009.
' ########################################################################################

'#if 0
'This is a small programmers utility.  It contains my favorite colors in Borge Hagstens OwnerDraw
'color ListBox and list them by NAME.  These are my most used colors, so having them handy helps.
'After selecting the colors, you can paste the formatted text directly into your source code.  I added
'the normal color chooser dialog for convienence, and your custom colors are saved to a file called
'cColor.cfg upon exiting the program.  I hope you find it useful!

'Regards,
'Jules
'#endif

#COMPILE EXE
#DIM ALL
#INCLUDE ONCE "windows.inc"
#INCLUDE ONCE "comdlg32.inc"

GLOBAL ghInst AS DWORD, ghMain AS DWORD, ghList1 AS DWORD
GLOBAL ghButton1 AS DWORD, ghButton2 AS DWORD, ghButton3 AS DWORD
GLOBAL ghList2 AS DWORD, ghFont AS DWORD, ghSwatch AS DWORD
GLOBAL curSel AS LONG, ghBrush AS DWORD, cColor() AS LONG

TYPE PROPERTYITEM
  clrName   AS ASCIIZ * 225
  clrValue  AS LONG
END TYPE

GLOBAL pItem()  AS PROPERTYITEM

%IDC_LIST1    = 1000
%IDC_BUTTON1  = 1001
%IDC_BUTTON2  = 1002
%IDC_BUTTON3  = 1003
%IDC_LIST2    = 1004
%IDC_SWATCH   = 1005

' ========================================================================================
' Get our custom colors from file
' ========================================================================================
SUB InitializeCustomColors()

   LOCAL i           AS LONG
   LOCAL nCount      AS LONG
   LOCAL f           AS LONG
   LOCAL strFileName AS STRING
   LOCAL strInfo     AS STRING

   REDIM cColor(0 TO 15)
   strFileName = EXE.Path$ & "cColor.cfg"
   IF ISFILE(strFileName) THEN
      f = FREEFILE
      i = 0
      OPEN strFileName FOR INPUT AS f
      FOR i = 0 TO 15
         LINE INPUT #f, strInfo
         cColor(i) = VAL(strInfo)
         strInfo = ""
       NEXT
      CLOSE f
   ELSE
      ' This code snippet provided by Eric Pearson
      RANDOMIZE TIMER
      FOR nCount = 0 TO 15
         cColor(nCount) = RND(0, 16777215)
      NEXT
   END IF

END SUB
' ========================================================================================

' ========================================================================================
' Save private config file, holds our 16 custom colors
' ========================================================================================
FUNCTION PrivateConfigFile() AS LONG

   LOCAL i           AS LONG
   LOCAL f           AS LONG
   LOCAL strFileName AS STRING

   strFileName = EXE.Path$ & "cColor.cfg"
   IF ISFILE(strFileName) THEN KILL strFileName
   f = FREEFILE
   OPEN strFileName FOR OUTPUT AS f
   FOR i = 0 TO UBOUND(cColor)
      PRINT #f, cColor(i)
   NEXT
   CLOSE f
   FUNCTION = %TRUE

END FUNCTION
' ========================================================================================

' ========================================================================================
' Write to clipboard excerpt provided by Gafny Jacob
' ========================================================================================
SUB SendToClipBoard

   LOCAL i          AS LONG
   LOCAL ndx        AS LONG
   LOCAL hGout      AS DWORD
   LOCAL p          AS DWORD
   LOCAL buf        AS STRING
   LOCAL szListText AS ASCIIZ * 255

   ' Build the buffer string from the listbox contents
   ndx = SendMessage(ghList2, %LB_GETCOUNT, 0, 0)
   FOR i = 0 TO ndx - 1
      SendMessage(ghList2, %LB_GETTEXT, i, VARPTR(szListText))
      buf = buf + szListText + CHR$(13,10)
   NEXT
   hGout = GlobalAlloc(%GMEM_MOVEABLE OR %GMEM_ZEROINIT OR %GMEM_DDESHARE, LEN(buf) * 2)
   p = GlobalLock(hGout)
   POKE$ p, buf
   GlobalUnLock(hGout)
   IF OpenClipBoard(ghMain) THEN
      EmptyClipBoard
      SetClipBoardData(%CF_TEXT, hGout)
      CloseClipBoard
   END IF
   GlobalFree(hGout)

END SUB
' ========================================================================================

' ========================================================================================
' Update the color swatch sample
' ========================================================================================
SUB UpdateSwatch (BYVAL id AS LONG)

   LOCAL nSel    AS LONG
   LOCAL Lb      AS LOGBRUSH
   LOCAL d       AS STRING
   LOCAL rv      AS INTEGER
   LOCAL gv      AS INTEGER
   LOCAL bv      AS INTEGER
   LOCAL currClr AS ASCIIZ * 255

   ' Delete the old one
   DeleteObject(ghBrush)
   IF id = %IDC_LIST1 THEN
      ' Create a new brush based on currently selected color
      Lb.lbStyle = %BS_SOLID
      Lb.lbColor = pItem(curSel).clrValue
      ghBrush    = CreateBrushIndirect(Lb)
   END IF
   IF id = %IDC_LIST2 THEN
      ' Get the current selection from listbox 2
      nSel = SendMessage(ghList2, %LB_GETCURSEL, 0, 0)
      SendMessage(ghList2, %LB_GETTEXT, nSel, VARPTR(currClr))
      ' Parse the color value
      d  = ","
      currClr = LTRIM$(currClr,"RGB(")
      currClr = RTRIM$(currClr,")")
      rv      = VAL(Parse$(currClr,d,1))
      gv      = VAL(Parse$(currClr,d,2))
      bv      = VAL(Parse$(currClr,d,3))
      ' Create a new brush based on currently selected color
      Lb.lbStyle = %BS_SOLID
      Lb.lbColor = RGB(rv%,gv%,bv%)
      ghBrush    = CreateBrushIndirect(Lb)
   END IF

   ' Refresh the color swatch
   InvalidateRect(ghSwatch, BYVAL %NULL, %TRUE)
   UpdateWindow(ghSwatch)

END SUB

' ========================================================================================
' Owner Draw Listbox double click notification handler
' ========================================================================================
FUNCTION OnDoubleClick() AS STRING

   LOCAL clrStr AS ASCIIZ * 255
   LOCAL rv     AS STRING
   LOCAL gv     AS STRING
   LOCAL bv     AS STRING

   IF curSel = -1 THEN FUNCTION = "" : EXIT FUNCTION
   ' Get the color value from current selection
   clrStr = HEX$(pItem(curSel).clrValue, 6)
   ' Format the string
   rv = "&H" & MID$(clrStr, 1, 2)
   gv = "&H" & MID$(clrStr, 3, 2) & ","
   bv = "&H" & MID$(clrStr, 5, 2) & ","
   ' Note order of RGB, COLORREF 0x00bbggrr
   clrStr = "RGB(" & bv$ & gv$ & rv$ & ")"

   FUNCTION = clrStr

END FUNCTION
' ========================================================================================

' ========================================================================================
' Choose... button handler to popup the color chooser dialog
' ========================================================================================
FUNCTION OnButtonClicked() AS STRING

   LOCAL initClr   AS DWORD
   LOCAL currClr   AS ASCIIZ * 255
   LOCAL clrValue  AS LONG
   LOCAL clrStr    AS ASCIIZ * 255
   LOCAL ColorSpec AS CHOOSECOLORAPI
   LOCAL lResult   AS LONG
   LOCAL rv        AS STRING
   LOCAL gv        AS STRING
   LOCAL bv        AS STRING

   IF curSel > - 1 THEN initClr = pItem(curSel).clrValue
   ColorSpec.lStructSize  = LEN(ColorSpec)
   ColorSpec.hwndOwner    = ghList1
   ColorSpec.lpCustColors = VARPTR(cColor(0))
   ColorSpec.rgbResult    = initClr
   ColorSpec.Flags        = ColorSpec.Flags OR %CC_RGBINIT
   lResult = ChooseColor(ColorSpec)

   IF lResult = 0 THEN 'check if user cancelled dialog ?
      FUNCTION = ""
      EXIT FUNCTION
   ELSE
      clrStr = HEX$(ColorSpec.rgbResult,6)
      ' Format the string
      rv = "&H" & MID$(clrStr, 1,2)
      gv = "&H" & MID$(clrStr, 3,2) & ","
      bv = "&H" & MID$(clrStr, 5,2) & ","
      'Note order of RGB, COLORREF 0x00bbggrr
      clrStr = "RGB(" & bv & gv & rv & ")"
      FUNCTION = clrStr
   END IF

END FUNCTION
' ========================================================================================

' ========================================================================================
' Thanks to Dave Navarro for this great CreateFont code.
' ========================================================================================
FUNCTION MakeFont (BYVAL strFont AS STRING, BYVAL PointSize AS LONG) AS LONG

   LOCAL hDC AS DWORD, CyPixels AS LONG

   hDC = GetDC(%HWND_DESKTOP)
   CyPixels  = GetDeviceCaps(hDC, %LOGPIXELSY)
   ReleaseDC %HWND_DESKTOP, hDC
   PointSize = (PointSize * CyPixels) \ 72

   FUNCTION = CreateFont(0 - PointSize, 0, 0, 0, %FW_NORMAL, 0, 0, 0, _
      %ANSI_CHARSET, %OUT_TT_PRECIS, %CLIP_DEFAULT_PRECIS, _
      %DEFAULT_QUALITY, %FF_DONTCARE, BYCOPY strFont)

END FUNCTION                                                                                                                                                                                                                                                   _
' ========================================================================================

' ========================================================================================
' First Listbox Control item intializer
' ========================================================================================
SUB InitializePropertyItems()

   LOCAL i AS LONG

   ' Load up all my favorite  color "values" and "names"
   pItem(0).clrName   = "White"
   pItem(0).clrValue  = RGB( &HFF,&HFF,&HFF )
   pItem(1).clrName   = "Red"
   pItem(1).clrValue  = RGB( &HFF,&H00,&H00 )
   pItem(2).clrName   = "Green"
   pItem(2).clrValue  = RGB( &H00,&HFF,&H00 )
   pItem(3).clrName   = "Vlue"
   pItem(3).clrValue  = RGB( &H00,&H00,&HFF )
   pItem(4).clrName   = "Magenta"
   pItem(4).clrValue  = RGB( &HFF,&H00,&HFF )
   pItem(5).clrName   = "Cyan"
   pItem(5).clrValue  = RGB( &H00,&HFF,&HFF )
   pItem(6).clrName   = "Yellow"
   pItem(6).clrValue  = RGB( &HFF,&HFF,&H00 )
   pItem(7).clrName   = "Aquamarine"
   pItem(7).clrValue  = RGB( &H70,&HDB,&H93 )
   pItem(8).clrName   = "Bakers chocolate"
   pItem(8).clrValue  = RGB( &H5C,&H33,&H17 )
   pItem(9).clrName   = "Blue violet"
   pItem(9).clrValue  = RGB( &H9F,&H5F,&H9F )
   pItem(10).clrName  = "Brass"
   pItem(10).clrValue = RGB( &HB5,&HA6,&H42 )
   pItem(11).clrName  = "Bright gold"
   pItem(11).clrValue = RGB( &HD9,&HD9,&H19 )
   pItem(12).clrName  = "Brown"
   pItem(12).clrValue = RGB( &HA6,&H2A,&H2A )
   pItem(13).clrName  = "Bronze"
   pItem(13).clrValue = RGB( &H8C,&H78,&H53 )
   pItem(14).clrName  = "Bronze II"
   pItem(14).clrValue = RGB( &HA6,&H7D,&H3D )
   pItem(15).clrName  = "Cadet blue"
   pItem(15).clrValue = RGB( &H5F,&H9F,&H9F )
   pItem(16).clrName  = "Ccool copper"
   pItem(16).clrValue = RGB( &HD9,&H87,&H19 )
   pItem(17).clrName  = "Copper"
   pItem(17).clrValue = RGB( &HB8,&H73,&H33 )
   pItem(18).clrName  = "Coral"
   pItem(18).clrValue = RGB( &HFF,&HFF,&H00 )
   pItem(19).clrName  = "Corn flower blue"
   pItem(19).clrValue = RGB( &H42,&H42,&H6F )
   pItem(20).clrName  = "Dark brown"
   pItem(20).clrValue = RGB( &H5C,&H40,&H33 )
   pItem(21).clrName  = "Dark green"
   pItem(21).clrValue = RGB( &H2F,&H4F,&H2F )
   pItem(22).clrName  = "Dark green copper"
   pItem(22).clrValue = RGB( &H4A,&H76,&H6E )
   pItem(23).clrName  = "Dark oliven green"
   pItem(23).clrValue = RGB( &H4F,&H4F,&H2F )
   pItem(24).clrName  = "Dark orchid"
   pItem(24).clrValue = RGB( &H99,&H32,&HCD )
   pItem(25).clrName  = "Dark purple"
   pItem(25).clrValue = RGB( &H87,&H1F,&H78 )
   pItem(26).clrName  = "Dark slate blue"
   pItem(26).clrValue = RGB( &H6B,&H23,&H8E )
   pItem(27).clrName  = "Dark slate grey"
   pItem(27).clrValue = RGB( &H2F,&H4F,&H4F )
   pItem(28).clrName  = "Dark tan"
   pItem(28).clrValue = RGB( &H97,&H69,&H4F )
   pItem(29).clrName  = "Dark turquoise"
   pItem(29).clrValue = RGB( &H70,&H93,&HDB )
   pItem(30).clrName  = "Dark wood"
   pItem(30).clrValue = RGB( &H85,&H5E,&H42 )
   pItem(31).clrName  = "Dim grey"
   pItem(31).clrValue = RGB( &H54,&H54,&H54 )
   pItem(32).clrName  = "Dusty rose"
   pItem(32).clrValue = RGB( &H85,&H63,&H63 )
   pItem(33).clrName  = "Feldspar"
   pItem(33).clrValue = RGB( &HD1,&H92,&H75 )
   pItem(34).clrName  = "Firebrick"
   pItem(34).clrValue = RGB( &H8E,&H23,&H23 )
   pItem(35).clrName  = "Forest green"
   pItem(35).clrValue = RGB( &H23,&H8E,&H23 )
   pItem(36).clrName  = "Gold"
   pItem(36).clrValue = RGB( &HCD,&H7F,&H32 )
   pItem(37).clrName  = "Goldenrod"
   pItem(37).clrValue = RGB( &HDB,&HDB,&H70 )
   pItem(38).clrName  = "Grey"
   pItem(38).clrValue = RGB( &HC0,&HC0,&HC0 )
   pItem(39).clrName  = "Green copper"
   pItem(39).clrValue = RGB( &H52,&H7F,&H76 )
   pItem(40).clrName  = "Green yellow"
   pItem(40).clrValue = RGB( &H93,&HDB,&H70 )
   pItem(41).clrName  = "Hunter green"
   pItem(41).clrValue = RGB( &H21,&H5E,&H21 )
   pItem(42).clrName  = "Indianred"
   pItem(42).clrValue = RGB( &H4E,&H2F,&H2F )
   pItem(43).clrName  = "Khaki"
   pItem(43).clrValue = RGB( &H9F,&H9F,&H5F )
   pItem(44).clrName  = "Light blue"
   pItem(44).clrValue = RGB( &HC0,&HD9,&HD9 )
   pItem(45).clrName  = "Ligth grey"
   pItem(45).clrValue = RGB( &HA8,&HA8,&HA8 )
   pItem(46).clrName  = "Light steel blue"
   pItem(46).clrValue = RGB( &H8F,&H8F,&HBD )
   pItem(47).clrName  = "Light wood"
   pItem(47).clrValue = RGB( &HE9,&HC2,&HA6 )
   pItem(48).clrName  = "Lime green"
   pItem(48).clrValue = RGB( &H32,&HCD,&H32 )
   pItem(49).clrName  = "Mandarian orange"
   pItem(49).clrValue = RGB( &HE4,&H78,&H33 )
   pItem(50).clrName  = "Maroon"
   pItem(50).clrValue = RGB( &H8E,&H23,&H6B )
   pItem(51).clrName  = "Medium aquamarine"
   pItem(51).clrValue = RGB( &H32,&HCD,&H99 )
   pItem(52).clrName  = "Medium blue"
   pItem(52).clrValue = RGB( &H32,&H32,&HCD )
   pItem(53).clrName  = "Medium forest green"
   pItem(53).clrValue = RGB( &H6B,&H8E,&H23 )
   pItem(54).clrName  = "Medium goldenrod"
   pItem(54).clrValue = RGB( &HEA,&HEA,&HEA )
   pItem(55).clrName  = "Medium orchid"
   pItem(55).clrValue = RGB( &H93,&H70,&HDB )
   pItem(56).clrName  = "Medium sea green"
   pItem(56).clrValue = RGB( &H42,&H6F,&H42 )
   pItem(57).clrName  = "Medium slate blue"
   pItem(57).clrValue = RGB( &H7F,&H00,&HFF )
   pItem(58).clrName  = "Medium spring green"
   pItem(58).clrValue = RGB( &H7F,&HFF,&H00 )
   pItem(59).clrName  = "Medium turquoise"
   pItem(59).clrValue = RGB( &H70,&HDB,&HDB )
   pItem(60).clrName  = "Medium violet red"
   pItem(60).clrValue = RGB( &HDB,&H70,&H93 )
   pItem(61).clrName  = "Medium wood"
   pItem(61).clrValue = RGB( &HA6,&H80,&H64 )
   pItem(62).clrName  = "Midnight blue"
   pItem(62).clrValue = RGB( &H2F,&H2F,&H4F )
   pItem(63).clrName  = "Navy blue"
   pItem(63).clrValue = RGB( &H23,&H23,&H8E )
   pItem(64).clrName  = "Neon blue"
   pItem(64).clrValue = RGB( &H4D,&H4D,&HFF )
   pItem(65).clrName  = "Neon pink"
   pItem(65).clrValue = RGB( &HFF,&H6E,&HC7 )
   pItem(66).clrName  = "New midnight blue"
   pItem(66).clrValue = RGB( &H00,&H00,&H9C )
   pItem(67).clrName  = "New tan"
   pItem(67).clrValue = RGB( &HEB,&HC7,&H9E )
   pItem(68).clrName  = "Old gold"
   pItem(68).clrValue = RGB( &HCF,&HB5,&H3B )
   pItem(69).clrName  = "Orange"
   pItem(69).clrValue = RGB( &HFF,&H7F,&H00 )
   pItem(70).clrName  = "Orange red"
   pItem(70).clrValue = RGB( &HFF,&H24,&H00 )
   pItem(71).clrName  = "Orchid"
   pItem(71).clrValue = RGB( &HDB,&H70,&HDB )
   pItem(72).clrName  = "Pale green"
   pItem(72).clrValue = RGB( &H8F,&HBC,&H8F )
   pItem(73).clrName  = "Pink"
   pItem(73).clrValue = RGB( &HBC,&H8F,&H8F )
   pItem(74).clrName  = "Plumb"
   pItem(74).clrValue = RGB( &HEA,&HAD,&HEA )
   pItem(75).clrName  = "Quartz"
   pItem(75).clrValue = RGB( &HD9,&HD9,&HF3 )
   pItem(76).clrName  = "Rich blue"
   pItem(76).clrValue = RGB( &H59,&H59,&HAB )
   pItem(77).clrName  = "Salmon"
   pItem(77).clrValue = RGB( &H6F,&H42,&H42 )
   pItem(78).clrName  = "Scarlet"
   pItem(78).clrValue = RGB( &H8C,&H17,&H17 )
   pItem(79).clrName  = "Sea green"
   pItem(79).clrValue = RGB( &H23,&H8E,&H68 )
   pItem(80).clrName  = "Semi-sweet chocolate"
   pItem(80).clrValue = RGB( &H6B,&H42,&H26 )
   pItem(81).clrName  = "Sienna"
   pItem(81).clrValue = RGB( &H8E,&H6B,&H23 )
   pItem(82).clrName  = "Silver"
   pItem(82).clrValue = RGB( &HE6,&HE8,&HFA )
   pItem(83).clrName  = "Sky blue"
   pItem(83).clrValue = RGB( &H32,&H99,&HCC )
   pItem(84).clrName  = "Slate blue"
   pItem(84).clrValue = RGB( &H00,&H7F,&HFF )
   pItem(85).clrName  = "Spicy pink"
   pItem(85).clrValue = RGB( &HFF,&H1C,&HAE )
   pItem(86).clrName  = "Spring green"
   pItem(86).clrValue = RGB( &H00,&HFF,&H7F )
   pItem(87).clrName  = "Steel blue"
   pItem(87).clrValue = RGB( &H23,&H6B,&H8E )
   pItem(88).clrName  = "Summer sky"
   pItem(88).clrValue = RGB( &H38,&HB0,&HDE )
   pItem(89).clrName  = "Tan"
   pItem(89).clrValue = RGB( &HDB,&H93,&H70 )
   pItem(90).clrName  = "Thistle"
   pItem(90).clrValue = RGB( &HD8,&HBF,&HD8 )
   pItem(91).clrName  = "Turquoise"
   pItem(91).clrValue = RGB( &HAD,&HEA,&HEA )
   pItem(92).clrName  = "Very dark brown"
   pItem(92).clrValue = RGB( &H5C,&H40,&H33 )
   pItem(93).clrName  = "Very light grey"
   pItem(93).clrValue = RGB( &HCD,&HCD,&HCD )
   pItem(94).clrName  = "violet"
   pItem(94).clrValue = RGB( &H4F,&H2F,&H4F )
   pItem(95).clrName  = "Violet red"
   pItem(95).clrValue = RGB( &HCC,&H32,&H99 )
   pItem(96).clrName  = "Wheat"
   pItem(96).clrValue = RGB( &HD8,&HD8,&HBF )
   pItem(97).clrName  = "Yellow green"
   pItem(97).clrValue = RGB( &H99,&HCC,&H32 )
   pItem(98).clrName  = "Black"
   pItem(98).clrValue = RGB( &H00,&H00,&H00 )

   FOR i = 0 TO 98
      ' Loop thru and add strings.
      SendMessage(ghList1, %LB_ADDSTRING, 0, VARPTR(pItem(i&).clrName))
   NEXT

END SUB
' ========================================================================================

' ========================================================================================
' Main windows procedure
' ========================================================================================
FUNCTION WndProc (BYVAL hWnd AS DWORD, BYVAL wMsg AS DWORD, _
                  BYVAL wParam AS DWORD, BYVAL lParam AS LONG) AS LONG

   LOCAL ndx       AS LONG
   LOCAL lpDs      AS DRAWITEMSTRUCT PTR
   LOCAL rc        AS RECT
   LOCAL rectFull  AS RECT
   LOCAL rc2       AS RECT
   LOCAL szNew     AS ASCIIZ * 255
   LOCAL Lb        AS LOGBRUSH
   LOCAL hBrush    AS DWORD
   LOCAL hBrushOld AS DWORD
   LOCAL rct       AS RECT
   LOCAL lpdis     AS DRAWITEMSTRUCT PTR
   LOCAL szTxt     AS ASCIIZ * 255

   ghMain = hWnd

   SELECT CASE wMsg

      CASE %WM_CREATE
         Lb.lbStyle  = %BS_SOLID
         Lb.lbColor  = RGB(128,128,128)
         ghBrush     = CreateBrushIndirect(Lb)
         REDIM pItem(0 TO 98) AS PROPERTYITEM
         curSel = -1
         ghFont = MakeFont("MS San Sarif", 9)

         ' Create the OwnerDraw List box for our common color picks
         ghList1  = CreateWindowEx(%WS_EX_CLIENTEDGE, "LISTBOX", "", _
                                   %WS_CHILD OR %WS_VISIBLE OR _
                                   %WS_TABSTOP OR %WS_BORDER OR _
                                   %LBS_NOINTEGRALHEIGHT OR _
                                   %LBS_HASSTRINGS OR _
                                   %LBS_OWNERDRAWFIXED OR _
                                   %LBS_NOTIFY OR _
                                   %WS_VSCROLL, _
                                   10, 10, 240, 208, _
                                   hWnd, _
                                   %IDC_LIST1, _
                                   ghInst, BYVAL %NULL)
         SendMessage( ghList1, %WM_SETFONT, ghFont, 0 )

         ' Create the add button
         ghButton1 = CreateWindowEx(0, "BUTTON", "Add", _
                                    %WS_CHILD OR %WS_CLIPSIBLINGS OR _
                                    %WS_VISIBLE OR %BS_PUSHBUTTON, _
                                    255, 10, 80, 30, _
                                    hWnd, _
                                    %IDC_BUTTON1,   _
                                    ghInst, ByVal %NULL)
         SendMessage(ghButton1, %WM_SETFONT, ghFont, 0)

         ' Create the remove button
         ghButton2 = CreateWindowEx(0, "BUTTON", "Remove", _
                                    %WS_CHILD OR %WS_CLIPSIBLINGS OR _
                                    %WS_VISIBLE OR %BS_PUSHBUTTON, _
                                    255, 48, 80, 30, _
                                    hWnd, _
                                    %IDC_BUTTON2,   _
                                    ghInst, ByVal %NULL)
         SendMessage(ghButton2, %WM_SETFONT, ghFont, 0)

         ' Create the choose button
         ghButton3 = CreateWindowEx(0, "BUTTON", "Choose...", _
                                    %WS_CHILD OR %WS_CLIPSIBLINGS OR _
                                    %WS_VISIBLE OR %BS_PUSHBUTTON, _
                                    255, 88, 80, 30, _
                                    hWnd, _
                                    %IDC_BUTTON3,   _
                                    ghInst, ByVal %NULL)
         SendMessage(ghButton3, %WM_SETFONT, ghFont, 0)

         ' Create the 2nd List box that holds RGB() text
         ghList2   = CreateWindowEx(%WS_EX_CLIENTEDGE, "LISTBOX", "", _
                                    %WS_CHILD OR %WS_VISIBLE OR _
                                    %WS_TABSTOP OR %WS_BORDER OR _
                                    %LBS_NOINTEGRALHEIGHT OR _
                                    %LBS_HASSTRINGS OR _
                                    %LBS_NOTIFY OR _
                                    %WS_VSCROLL, _
                                    340, 10, 140, 110, _
                                    hWnd, _
                                    %IDC_LIST2, _
                                    ghInst, BYVAL %NULL)
         SendMessage(ghList2, %WM_SETFONT, ghFont, 0)

         ' Initialize our data for listbox number 1
         InitializePropertyItems
         ' Initialize our custom colors from the cColor.cfg file
         InitializeCustomColors

         ' Create our swatch sample using a static control
         ghSwatch = CreateWindowEx(%WS_EX_CLIENTEDGE,"STATIC", _
                                   "", %WS_CHILD OR %WS_VISIBLE _
                                   OR %WS_BORDER OR %WS_CLIPSIBLINGS, _
                                   255, 128, 225, 90, _
                                   hWnd, %IDC_SWATCH, _
                                   ghInst, BYVAL %NULL)

         EXIT FUNCTION

      CASE %WM_CTLCOLORSTATIC
         SELECT CASE GetDlgCtrlId(lParam)
            CASE %IDC_SWATCH
               FUNCTION = ghBrush
               EXIT FUNCTION
         END SELECT
         EXIT FUNCTION

      '-------------------------------------------------------------------------
      ' WM_DRAWITEM Exerpt provided by Borje Hagsten
      '-------------------------------------------------------------------------
      CASE %WM_DRAWITEM
         lpdis = lParam
         IF @lpdis.itemID = -1 THEN EXIT FUNCTION

         SELECT CASE @lpdis.itemAction
            CASE %ODA_DRAWENTIRE, %ODA_SELECT

               ' Clear background
               hBrush = CreateSolidBrush(GetSysColor(%COLOR_WINDOW))   ' Create a background brush
               hBrushOld = SelectObject(@lpdis.hDC, hBrush)            ' Select brush into device context
               FillRect(@lpdis.hDC, @lpdis.rcItem, hBrush)             ' Paint background color rectangle
               SelectObject(@lpdis.hDC, hBrushOld)                     ' Select old brush back
               DeleteObject(hBrush)                                    ' Delete brush

               ' Draw text
               SetBkColor(@lpdis.hDC, GetSysColor(%COLOR_WINDOW))       ' Set text Background
               SetTextColor(@lpdis.hDC, GetSysColor(%COLOR_WINDOWTEXT)) ' Set text color
               szTxt = pItem(@lpdis.itemID).clrName
               TextOut(@lpdis.hDC, 28, @lpdis.rcItem.ntop + 2, szTxt, LEN(szTxt))  ' Draw text

               ' Selected item
               IF (@lpdis.itemState AND %ODS_SELECTED) THEN              ' If selected
                  rct.nLeft   = 26 : rct.nRight = @lpdis.rcItem.nRight   ' Set cordinates
                  rct.ntop    = @lpdis.rcItem.ntop
                  rct.nbottom = @lpdis.rcItem.nbottom
                  InvertRect(@lpdis.hDC, rct)                           ' Invert area around text only
               END IF

               ' Paint color rectangle
               rct.nLeft   = 3 : rct.nRight = 24                         ' Set cordinates
               rct.ntop    = @lpdis.rcItem.ntop + 2
               rct.nbottom = @lpdis.rcItem.nbottom - 2
               hBrush = CreateSolidBrush(pItem(@lpdis.itemID).clrValue)  ' Create brush with proper color
               hBrushOld = SelectObject(@lpdis.hDC, hBrush)              ' Select brush into device context
               RoundRect(@lpdis.hDC, rct.nLeft, rct.ntop, rct.nRight, rct.nbottom, 3, 3) 'Draw
               SelectObject(@lpdis.hDC, hBrushOld)                  'Select old brush back
               DeleteObject(hBrush)                                 'Delete brush
               EXIT FUNCTION

            CASE %ODA_FOCUS
               DrawFocusRect(@lpdis.hDC, @lpdis.rcItem)  ' Draw focus rectangle

         END SELECT
         FUNCTION = %TRUE
         EXIT FUNCTION


      CASE %WM_COMMAND
         SELECT CASE LO(WORD, wParam)
            CASE %IDCANCEL
               IF HI(WORD, wParam) = %BN_CLICKED THEN
                  SendMessage hWnd, %WM_CLOSE, 0, 0
                  EXIT FUNCTION
               END IF

            CASE %IDC_LIST1 '1st ListBox notify
               SELECT CASE HI(WORD, wParam)
                  CASE %LBN_SELCHANGE
                     curSel = SendMessage(ghList1, %LB_GETCURSEL, 0, 0)
                     UpdateSwatch(%IDC_LIST1)
                  CASE %LBN_DBLCLK
                     szNew = OnDoubleClick
                     IF szNew <> "" THEN
                        SendMessage(ghList2,%LB_ADDSTRING, 0, VARPTR(szNew))
                        ndx = SendMessage(ghList2, %LB_GETCOUNT, 0, 0) - 1
                        SendMessage(ghList2, %LB_SETCURSEL, ndx, 0)
                        SendToClipBoard
                     END IF
               END SELECT

            CASE %IDC_LIST2     ' 2nd listbox notify
               SELECT CASE HI(WORD, wParam)
                  CASE %LBN_SELCHANGE
                     UpdateSwatch(%IDC_LIST2)
               END SELECT

            CASE %IDC_BUTTON1  ' Button ADD notify
               IF HI(WORD, wParam) = %BN_CLICKED THEN
                  szNew = OnDoubleClick()
                  IF szNew <> "" THEN
                     SendMessage(ghList2,%LB_ADDSTRING,0,VARPTR(szNew))
                     ndx = SendMessage(ghList2, %LB_GETCOUNT, 0, 0 ) - 1
                     SendMessage(ghList2, %LB_SETCURSEL, ndx, 0)
                     SendToClipBoard
                  END IF
               END IF

            CASE %IDC_BUTTON2  'button REMOVE notify
               IF HI(WORD, wParam) = %BN_CLICKED THEN
                  ndx = SendMessage(ghList2, %LB_GETCURSEL, 0, 0)
                  IF ndx > -1 THEN
                     SendMessage(ghList2, %LB_DELETESTRING, ndx, 0)
                     ndx = SendMessage( ghList2,%LB_GETCOUNT,0,0) - 1
                     SendMessage(ghList2, %LB_SETCURSEL, ndx, 0)
                     IF ndx = %LB_ERR THEN
                        UpdateSwatch(%IDC_LIST1)
                     ELSE
                        UpdateSwatch(%IDC_LIST2)
                     END IF
                     SendToClipBoard
                  END IF
               END IF

            CASE %IDC_BUTTON3  'button CHOOSE notify
               IF HI(WORD, wParam) = %BN_CLICKED THEN
                  szNew = OnButtonClicked
                  IF szNew <> "" THEN
                     SendMessage(ghList2, %LB_ADDSTRING, 0, VARPTR(szNew))
                     ' Set the current selection to last in the list
                     ndx = SendMessage( ghList2, %LB_GETCOUNT, 0, 0) - 1
                     SendMessage(ghList2, %LB_SETCURSEL, ndx, 0)
                     UpdateSwatch(%IDC_LIST2)
                     SendToClipBoard
                  END IF
               END IF
         END SELECT
         EXIT FUNCTION

      CASE %WM_DESTROY
         IF ghFont <> 0 THEN DeleteObject(ghFont)
         IF ghBrush <> 0 THEN DeleteObject(ghBrush)
         ' Save our custom colors to cColor.cfg
         PrivateConfigFile
         PostQuitMessage 0

   END SELECT

   FUNCTION = DefWindowProc(hWnd, wMsg, wParam, lParam)

END FUNCTION
' ========================================================================================

' ========================================================================================
' Main
' ========================================================================================
FUNCTION WinMain (BYVAL hInstance AS DWORD, BYVAL hPrevInstance AS DWORD, _
                  BYVAL lpCmdLine AS ASCIIZ PTR, BYVAL iCmdShow AS LONG) AS LONG

   LOCAL wcex        AS WNDCLASSEX
   LOCAL hWndMain    AS DWORD
   LOCAL szClassName AS ASCIIZ * 20
   LOCAL dwStyle     AS DWORD

   szClassName        = "COLORLIST"
   wcex.cbSize        = SIZEOF(wcex)
   wcex.style         = %CS_HREDRAW OR %CS_VREDRAW OR %CS_DBLCLKS
   wcex.lpfnWndProc   = CODEPTR(WndProc)
   wcex.cbClsExtra    = 0
   wcex.cbWndExtra    = 0
   wcex.hInstance     = hInstance
   wcex.hCursor       = LoadCursor(%NULL, BYVAL %IDC_ARROW)
   wcex.hbrBackground = GetStockObject(%LTGRAY_BRUSH)
   wcex.lpszMenuName  = %NULL
   wcex.lpszClassName = VARPTR(szClassName)
   wcex.hIcon         = LoadIcon (%NULL, BYVAL %IDI_APPLICATION)
   wcex.hIconSm       = LoadIcon (%NULL, BYVAL %IDI_APPLICATION)
   RegisterClassEx(wcex)

   ghInst = hInstance

   dwStyle = %WS_OVERLAPPED OR %WS_CAPTION OR %WS_SYSMENU OR %WS_MINIMIZEBOX

   ' Create the main window (my screen LCD,1024x768)
   hWndMain = CreateWindowEx(0, szClassName, "Programmers Color Picker", _
                             dwStyle, 210, 110, 498, 258, _
                             %HWND_DESKTOP, %NULL, hInstance, BYVAL %NULL)

   ShowWindow(hWndMain, %SW_SHOW)
   UpdateWindow(hWndMain)

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
