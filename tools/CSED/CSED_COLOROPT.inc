' ########################################################################################
' CSED Editor
' File: CSED_COLOROPT.INC
' Contents: Color options dialog
' Copyright (c) 2012 José Roca
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE ONCE "CSED_CBCOLOR.inc"   ' // Combobox for color selection

' ========================================================================================
' Get type of character set - ansi, symbol.. a must for some fonts.
' ========================================================================================
FUNCTION CSED_EnumCharSet (BYREF elf AS ENUMLOGFONT, BYREF ntm AS NEWTEXTMETRIC, BYVAL FontType AS LONG, BYREF CharSet AS LONG) AS LONG
   CharSet = elf.elfLogFont.lfCharSet
END FUNCTION
' ========================================================================================

' ========================================================================================
' Create a desirable font and return its handle.
' ========================================================================================
#IF %DEF(%UNICODE)
FUNCTION CSED_MakeFontEx(BYVAL FontName AS WSTRING, BYVAL PointSize AS LONG, BYVAL fBold AS LONG, BYVAL fItalic AS LONG, BYVAL fUnderline AS LONG) AS DWORD
#ELSE
FUNCTION CSED_MakeFontEx(BYVAL FontName AS STRING, BYVAL PointSize AS LONG, BYVAL fBold AS LONG, BYVAL fItalic AS LONG, BYVAL fUnderline AS LONG) AS DWORD
#ENDIF

   LOCAL hDC AS DWORD
   LOCAL CharSet AS LONG
   LOCAL CyPixels AS LONG

   hDC = GetDC(%HWND_DESKTOP)
   CyPixels  = GetDeviceCaps(hDC, %LOGPIXELSY)
   EnumFontFamilies hDC, BYVAL STRPTR(FontName), CODEPTR(CSED_EnumCharSet), BYVAL VARPTR(CharSet)
   PointSize = -(PointSize * CyPixels) \ 72
   ReleaseDC %HWND_DESKTOP, hDC

   FUNCTION = CreateFont(PointSize, 0, _  ' // Height, width(default=0)
              0, 0, _                     ' // Escapement(angle), orientation
              fBold, _                    ' // Weight (%FW_DONTCARE = 0, %FW_NORMAL = 400, %FW_BOLD = 700)
              fItalic, _                  ' // Italic
              fUnderline, _               ' // Underline
              %FALSE, _                   ' // StrikeThru
              CharSet, %OUT_TT_PRECIS, _
              %CLIP_DEFAULT_PRECIS, %DEFAULT_QUALITY, _
              %FF_DONTCARE, BYCOPY FontName)

END FUNCTION
' ========================================================================================

' ========================================================================================
' Enumerate the names of all the fonts. Note the difference between how to enumerate them
' (%TMPF_FIXED_PITCH has the bit cleared).
' %TMPF_FIXED_PITCH for fixed pitch fonts (like in PB edit)
' %TMPF_TRUETYPE OR %TMPF_VECTOR for True type and vector fonts
' %TMPF_DEVICE for device fonts (like printer fonts)
' Exclude what you don't want to include in list.
' ========================================================================================
FUNCTION CSED_EnumFontName(lf AS LOGFONT, tm AS TEXTMETRIC, BYVAL FontType AS LONG, hwnd AS DWORD) AS LONG

   IF (FontType AND %TRUETYPE_FONTTYPE) THEN                      ' // True type fonts
      SendMessage hwnd, %CB_ADDSTRING, 0, VARPTR(lf.lfFaceName)
   ELSEIF (FontType AND %TMPF_FIXED_PITCH) = 0 THEN               ' <- check if bit is cleared!
      SendMessage hwnd, %CB_ADDSTRING, 0, VARPTR(lf.lfFaceName)   ' // fixed pitch fonts
   ELSEIF (FontType AND %TMPF_VECTOR) THEN
      SendMessage hwnd, %CB_ADDSTRING, 0, VARPTR(lf.lfFaceName)   ' // vector fonts
   ELSEIF (FontType AND %TMPF_DEVICE) THEN
      SendMessage hwnd, %CB_ADDSTRING, 0, VARPTR(lf.lfFaceName)   ' // device fonts
   ELSE
      SendMessage hwnd, %CB_ADDSTRING, 0, VARPTR(lf.lfFaceName)   ' // system, others
   END IF

   FUNCTION = %TRUE

END FUNCTION
' ========================================================================================

' ========================================================================================
' Fill a combo box with the names of all fonts of a certain type
' ========================================================================================
SUB CSED_FillFontCombo (BYVAL hwnd AS DWORD)
   LOCAL hDC AS DWORD
   SendMessage hwnd, %CB_RESETCONTENT, 0, 0
   hDC = GetDC(%HWND_DESKTOP)
   EnumFontFamilies hDC, BYVAL %NULL, CODEPTR(CSED_EnumFontName), BYVAL VARPTR(hwnd)
   ReleaseDC %HWND_DESKTOP, hDC
END SUB
' ========================================================================================

' ========================================================================================
' Fill a combobox with the allowed font sizes
' ========================================================================================
#IF %DEF(%UNICODE)
SUB CSED_FillFontSizeCombo (BYVAL hwnd AS DWORD, BYVAL strFontName AS WSTRING)
#ELSE
SUB CSED_FillFontSizeCombo (BYVAL hwnd AS DWORD, BYVAL strFontName AS STRING)
#ENDIF

   LOCAL hCb AS DWORD
   STATIC FullRange AS LONG

   strFontName = RTRIM$(strFontName, CHR$(0))
   hCb = GetDlgItem(hwnd, %IDC_CBFONTSIZE)

   SELECT CASE strFontName
      CASE ""
         FullRange = %FALSE
      CASE "Fixedsys"
         FullRange = %FALSE
         ComboBox_ResetContent(hCb)
         ComboBox_AddString hCb, "9"
      CASE "Courier"
         FullRange = %FALSE
         ComboBox_ResetContent(hCb)
         ComboBox_AddString hCb, "10"
         ComboBox_AddString hCb, "12"
         ComboBox_AddString hCb, "15"
      CASE "Terminal"
         FullRange = %FALSE
         ComboBox_ResetContent(hCb)
         ComboBox_AddString hCb, "5"
         ComboBox_AddString hCb, "6"
         ComboBox_AddString hCb, "12"
         ComboBox_AddString hCb, "14"
      CASE ELSE
         IF ISTRUE FullRange THEN EXIT SELECT
         FullRange = %TRUE
         ComboBox_ResetContent(hCb)
         ComboBox_AddString hCb, "8"
         ComboBox_AddString hCb, "9"
         ComboBox_AddString hCb, "10"
         ComboBox_AddString hCb, "11"
         ComboBox_AddString hCb, "12"
         ComboBox_AddString hCb, "14"
         ComboBox_AddString hCb, "16"
         ComboBox_AddString hCb, "18"
         ComboBox_AddString hCb, "20"
         ComboBox_AddString hCb, "22"
         ComboBox_AddString hCb, "24"
         ComboBox_AddString hCb, "26"
         ComboBox_AddString hCb, "28"
         ComboBox_AddString hCb, "32"
         ComboBox_AddString hCb, "36"
   END SELECT

'   ComboBox_SetCurSel hCb, 0

END SUB
' ========================================================================================

' ========================================================================================
' WM_DRAWITEM procedure
' ========================================================================================
FUNCTION CSED_DrawFontCombo(BYVAL hwnd AS DWORD, BYVAL wParam AS LONG, BYVAL lParam AS LONG) AS LONG

   LOCAL hFont AS DWORD
   LOCAL lpdis AS DRAWITEMSTRUCT PTR
#IF %DEF(%UNICODE)
   LOCAL szText AS WSTRINGZ * %MAX_PATH
#ELSE
   LOCAL szText AS ASCIIZ * %MAX_PATH
#ENDIF

   lpdis = lParam
   IF @lpdis.itemID = &HFFFFFFFF& THEN EXIT FUNCTION   ' empty list, take a break..

   SELECT CASE AS LONG @lpdis.itemAction
      CASE %ODA_DRAWENTIRE, %ODA_SELECT
         ' // If not selected or if in edit part of the combobox
         IF (@lpdis.itemState AND %ODS_SELECTED) = 0 OR _
               (@lpdis.itemState AND %ODS_COMBOBOXEDIT) THEN
            ' // Text background
            SetBkColor @lpdis.hDC, GetSysColor(%COLOR_WINDOW)
            ' // Text color
            SetTextColor @lpdis.hDC, GetSysColor(%COLOR_WINDOWTEXT)
            ' // Clear background
            FillRect @lpdis.hDC, @lpdis.rcItem, GetSysColorBrush(%COLOR_WINDOW)
         ELSE
            ' // Select text background
            SetBkColor @lpdis.hDC, GetSysColor(%COLOR_HIGHLIGHT)
            ' // Select text color
            SetTextColor @lpdis.hDC, GetSysColor(%COLOR_HIGHLIGHTTEXT)
            ' // Clear background
            FillRect @lpdis.hDC, @lpdis.rcItem, GetSysColorBrush(%COLOR_HIGHLIGHT)
         END IF

         ' // Get item's text (fontname), create font and draw text
         szText = ComboBox_GetLbText(hwnd, @lpdis.itemID)
         IF LEN(szText) THEN
            hFont = CSED_MakeFontEx(szText, 10, 0, 0, 0)
            IF hFont THEN hFont = SelectObject(@lpdis.hDC, hFont)
         END IF
         DrawText @lpdis.hDC, szText, LEN(szText), @lpdis.rcItem, %DT_SINGLELINE OR %DT_LEFT OR %DT_VCENTER
         IF hFont THEN DeleteObject SelectObject(@lpdis.hDC, hFont)

         ' // Focus rect around selected item
         IF (@lpdis.itemState AND %ODS_SELECTED) THEN
            DrawFocusRect @lpdis.hDC, @lpdis.rcItem
         END IF
         FUNCTION = %TRUE

   END SELECT

END FUNCTION
' ========================================================================================

' ========================================================================================
' Extracts the red color
' ========================================================================================
FUNCTION CSED_ExtractRedColor(BYVAL xRgbColor AS LONG) AS BYTE
   FUNCTION = xRgbColor MOD 256
END FUNCTION
' ========================================================================================

' ========================================================================================
' Extracts the green color
' ========================================================================================
FUNCTION CSED_ExtractGreenColor(BYVAL xRgbColor AS LONG) AS BYTE
   FUNCTION = (xRgbColor \ 256) MOD 256
END FUNCTION
' ========================================================================================

' ========================================================================================
' Extracts the blue color
' ========================================================================================
FUNCTION CSED_ExtractBlueColor(BYVAL xRgbColor AS LONG) AS BYTE
   FUNCTION = ((xRgbColor \ 256) \ 256) MOD 256
END FUNCTION
' ========================================================================================

' ========================================================================================
' Choose color dialog
' ========================================================================================
FUNCTION CSED_ChooseColor(BYVAL hParent AS DWORD, BYVAL DefaultColor AS LONG) AS LONG

    DIM ColorSpec AS LOCAL CHOOSECOLORAPI
    DIM lResult   AS LOCAL LONG
    DIM lCounter  AS LOCAL LONG
    DIM xRed      AS LOCAL BYTE
    DIM xGreen    AS LOCAL BYTE
    DIM xBlue     AS LOCAL BYTE

    DIM lCustomColor(15) AS LOCAL LONG

    ColorSpec.lStructSize  = LEN(ColorSpec)
    ColorSpec.hwndOwner    = hParent     ' // Handle of owner window.  If 0, dialog appears at top/left.
    ColorSpec.lpCustColors = VARPTR(lCustomColor(0))

    xRed = CSED_ExtractRedColor(DefaultColor)
    xGreen = CSED_ExtractGreenColor(DefaultColor)
    xBlue = CSED_ExtractBlueColor(DefaultColor)
    ColorSpec.rgbResult = RGB(xRed, xGreen, xBlue)

    ' // Try these options one by one, for different effects...
    ColorSpec.Flags = ColorSpec.Flags OR %CC_RGBINIT   ' // Tells control to start at default color
    ColorSpec.Flags = ColorSpec.Flags OR %CC_FULLOPEN

    FOR lCounter = 0 TO 15
       lCustomColor(lCounter) = RGB(0, lCounter * 16, (15 - lCounter) * 16)
    NEXT

    lResult = ChooseColor(ColorSpec)
    IF lResult THEN FUNCTION = Colorspec.rgbResult

END FUNCTION
' ========================================================================================

' ========================================================================================
' Store the selections
' ========================================================================================
#IF %DEF(%UNICODE)
SUB CSED_SaveColorsAndFontsSelection (BYVAL hwnd AS DWORD, BYVAL curSelStr AS WSTRING)
#ELSE
SUB CSED_SaveColorsAndFontsSelection (BYVAL hwnd AS DWORD, BYVAL curSelStr AS STRING)
#ENDIF

   LOCAL hCbForeCol AS DWORD
   LOCAL hCbBackCol AS DWORD
   LOCAL hCbFonts AS DWORD
   LOCAL hCbCharset AS DWORD
   LOCAL hCbFontSize AS DWORD

   hCbForeCol  = GetDlgItem(hwnd, %IDC_CBFORECOLOR)
   hCbBackCol  = GetDlgItem(hwnd, %IDC_CBBACKCOLOR)
   hCbFonts    = GetDlgItem(hwnd, %IDC_CBFONTS)
   hCbCharset  = GetDlgItem(hwnd, %IDC_CBCHARSET)
   hCbFontSize = GetDlgItem(hwnd, %IDC_CBFONTSIZE)

   SELECT CASE curSelStr
      ' // Color and fonts
      CASE "Default"
         pSed.DefaultForeColor = SendMessage(hCbForeCol, %CBCOL_GETUSERCOLOR, 0, 0)
         pSed.DefaultBackColor = SendMessage(hCbBackCol, %CBCOL_GETUSERCOLOR, 0, 0)
         pSed.DefaultFontName = ComboBox_GetLbText(hCbFonts, -1)
         pSed.DefaultFontCharset = ComboBox_GetLbText(hCbCharset, -1)
         CSED_FillFontSizeCombo hCbFontSize, pSed.DefaultFontName
         pSed.DefaultFontSize =  VAL(ComboBox_GetLbText(hCbFontSize, -1))
         pSed.DefaultFontBold = IsDlgButtonChecked(hwnd, %IDK_BOLD)
         pSed.DefaultFontItalic = IsDlgButtonChecked(hwnd, %IDK_ITALIC)
         pSed.DefaultFontUnderline = IsDlgButtonChecked(hwnd, %IDK_UNDERLINE)
      CASE "Comments"
         pSed.CommentForeColor = SendMessage(hCbForeCol, %CBCOL_GETUSERCOLOR, 0, 0)
         pSed.CommentBackColor = SendMessage(hCbBackCol, %CBCOL_GETUSERCOLOR, 0, 0)
         pSed.CommentFontName = ComboBox_GetLbText(hCbFonts, -1)
         pSed.CommentFontCharset = ComboBox_GetLbText(hCbCharset, -1)
         CSED_FillFontSizeCombo hCbFontSize, pSed.CommentFontName
         pSed.CommentFontSize =  VAL(ComboBox_GetLbText(hCbFontSize, -1))
         pSed.CommentFontBold = IsDlgButtonChecked(hwnd, %IDK_BOLD)
         pSed.CommentFontItalic = IsDlgButtonChecked(hwnd, %IDK_ITALIC)
         pSed.CommentFontUnderline = IsDlgButtonChecked(hwnd, %IDK_UNDERLINE)
      CASE "Constants"
         pSed.ConstantForeColor = SendMessage(hCbForeCol, %CBCOL_GETUSERCOLOR, 0, 0)
         pSed.ConstantBackColor = SendMessage(hCbBackCol, %CBCOL_GETUSERCOLOR, 0, 0)
         pSed.ConstantFontName = ComboBox_GetLbText(hCbFonts, -1)
         pSed.ConstantFontCharset = ComboBox_GetLbText(hCbCharset, -1)
         CSED_FillFontSizeCombo hCbFontSize, pSed.ConstantFontName
         pSed.ConstantFontSize =  VAL(ComboBox_GetLbText(hCbFontSize, -1))
         pSed.ConstantFontBold = IsDlgButtonChecked(hwnd, %IDK_BOLD)
         pSed.ConstantFontItalic = IsDlgButtonChecked(hwnd, %IDK_ITALIC)
         pSed.ConstantFontUnderline = IsDlgButtonChecked(hwnd, %IDK_UNDERLINE)
      CASE "Identifiers"
         pSed.IdentifierForeColor = SendMessage(hCbForeCol, %CBCOL_GETUSERCOLOR, 0, 0)
         pSed.IdentifierBackColor = SendMessage(hCbBackCol, %CBCOL_GETUSERCOLOR, 0, 0)
         pSed.IdentifierFontName = ComboBox_GetLbText(hCbFonts, -1)
         pSed.IdentifierFontCharset = ComboBox_GetLbText(hCbCharset, -1)
         CSED_FillFontSizeCombo hCbFontSize, pSed.IdentifierFontName
         pSed.IdentifierFontSize =  VAL(ComboBox_GetLbText(hCbFontSize, -1))
         pSed.IdentifierFontBold = IsDlgButtonChecked(hwnd, %IDK_BOLD)
         pSed.IdentifierFontItalic = IsDlgButtonChecked(hwnd, %IDK_ITALIC)
         pSed.IdentifierFontUnderline = IsDlgButtonChecked(hwnd, %IDK_UNDERLINE)
      CASE "Keywords"
         pSed.KeywordForeColor = SendMessage(hCbForeCol, %CBCOL_GETUSERCOLOR, 0, 0)
         pSed.KeywordBackColor = SendMessage(hCbBackCol, %CBCOL_GETUSERCOLOR, 0, 0)
         pSed.KeywordFontName = ComboBox_GetLbText(hCbFonts, -1)
         pSed.KeywordFontCharset = ComboBox_GetLbText(hCbCharset, -1)
         CSED_FillFontSizeCombo hCbFontSize, pSed.KeywordFontName
         pSed.KeywordFontSize =  VAL(ComboBox_GetLbText(hCbFontSize, -1))
         pSed.KeywordFontBold = IsDlgButtonChecked(hwnd, %IDK_BOLD)
         pSed.KeywordFontItalic = IsDlgButtonChecked(hwnd, %IDK_ITALIC)
         pSed.KeywordFontUnderline = IsDlgButtonChecked(hwnd, %IDK_UNDERLINE)
      CASE "Numbers"
         pSed.NumberForeColor = SendMessage(hCbForeCol, %CBCOL_GETUSERCOLOR, 0, 0)
         pSed.NumberBackColor = SendMessage(hCbBackCol, %CBCOL_GETUSERCOLOR, 0, 0)
         pSed.NumberFontName = ComboBox_GetLbText(hCbFonts, -1)
         pSed.NumberFontCharset = ComboBox_GetLbText(hCbCharset, -1)
         CSED_FillFontSizeCombo hCbFontSize, pSed.NumberFontName
         pSed.NumberFontSize =  VAL(ComboBox_GetLbText(hCbFontSize, -1))
         pSed.NumberFontBold = IsDlgButtonChecked(hwnd, %IDK_BOLD)
         pSed.NumberFontItalic = IsDlgButtonChecked(hwnd, %IDK_ITALIC)
         pSed.NumberFontUnderline = IsDlgButtonChecked(hwnd, %IDK_UNDERLINE)
      CASE "Line numbers"
         pSed.LineNumberForeColor = SendMessage(hCbForeCol, %CBCOL_GETUSERCOLOR, 0, 0)
         pSed.LineNumberBackColor = SendMessage(hCbBackCol, %CBCOL_GETUSERCOLOR, 0, 0)
         pSed.LineNumberFontName = ComboBox_GetLbText(hCbFonts, -1)
         pSed.LineNumberFontCharset = ComboBox_GetLbText(hCbCharset, -1)
         CSED_FillFontSizeCombo hCbFontSize, pSed.LineNumberFontName
         pSed.LineNumberFontSize =  VAL(ComboBox_GetLbText(hCbFontSize, -1))
         pSed.LineNumberFontBold = IsDlgButtonChecked(hwnd, %IDK_BOLD)
         pSed.LineNumberFontItalic = IsDlgButtonChecked(hwnd, %IDK_ITALIC)
         pSed.LineNumberFontUnderline = IsDlgButtonChecked(hwnd, %IDK_UNDERLINE)
      CASE "Operators"
         pSed.OperatorForeColor = SendMessage(hCbForeCol, %CBCOL_GETUSERCOLOR, 0, 0)
         pSed.OperatorBackColor = SendMessage(hCbBackCol, %CBCOL_GETUSERCOLOR, 0, 0)
         pSed.OperatorFontName = ComboBox_GetLbText(hCbFonts, -1)
         pSed.OperatorFontCharset = ComboBox_GetLbText(hCbCharset, -1)
         CSED_FillFontSizeCombo hCbFontSize, pSed.OperatorFontName
         pSed.OperatorFontSize =  VAL(ComboBox_GetLbText(hCbFontSize, -1))
         pSed.OperatorFontBold = IsDlgButtonChecked(hwnd, %IDK_BOLD)
         pSed.OperatorFontItalic = IsDlgButtonChecked(hwnd, %IDK_ITALIC)
         pSed.OperatorFontUnderline = IsDlgButtonChecked(hwnd, %IDK_UNDERLINE)
      CASE "Preprocessor"
         pSed.PreprocessorForeColor = SendMessage(hCbForeCol, %CBCOL_GETUSERCOLOR, 0, 0)
         pSed.PreprocessorBackColor = SendMessage(hCbBackCol, %CBCOL_GETUSERCOLOR, 0, 0)
         pSed.PreprocessorFontName = ComboBox_GetLbText(hCbFonts, -1)
         pSed.PreprocessorFontCharset = ComboBox_GetLbText(hCbCharset, -1)
         CSED_FillFontSizeCombo hCbFontSize, pSed.PreprocessorFontName
         pSed.PreprocessorFontSize =  VAL(ComboBox_GetLbText(hCbFontSize, -1))
         pSed.PreprocessorFontBold = IsDlgButtonChecked(hwnd, %IDK_BOLD)
         pSed.PreprocessorFontItalic = IsDlgButtonChecked(hwnd, %IDK_ITALIC)
         pSed.PreprocessorFontUnderline = IsDlgButtonChecked(hwnd, %IDK_UNDERLINE)
      CASE "Strings"
         pSed.StringForeColor = SendMessage(hCbForeCol, %CBCOL_GETUSERCOLOR, 0, 0)
         pSed.StringBackColor = SendMessage(hCbBackCol, %CBCOL_GETUSERCOLOR, 0, 0)
         pSed.StringFontName = ComboBox_GetLbText(hCbFonts, -1)
         pSed.StringFontCharset = ComboBox_GetLbText(hCbCharset, -1)
         CSED_FillFontSizeCombo hCbFontSize, pSed.StringFontName
         pSed.StringFontSize =  VAL(ComboBox_GetLbText(hCbFontSize, -1))
         pSed.StringFontBold = IsDlgButtonChecked(hwnd, %IDK_BOLD)
         pSed.StringFontItalic = IsDlgButtonChecked(hwnd, %IDK_ITALIC)
         pSed.StringFontUnderline = IsDlgButtonChecked(hwnd, %IDK_UNDERLINE)
      ' // Color only
      CASE "Caret"
         pSed.CaretForeColor = SendMessage(hCbForeCol, %CBCOL_GETUSERCOLOR, 0, 0)
      CASE "Edge"
         pSed.EdgeForeColor = SendMessage(hCbForeCol, %CBCOL_GETUSERCOLOR, 0, 0)
         pSed.EdgeBackColor = SendMessage(hCbBackCol, %CBCOL_GETUSERCOLOR, 0, 0)
      CASE "Fold"
         pSed.FoldForeColor = SendMessage(hCbForeCol, %CBCOL_GETUSERCOLOR, 0, 0)
         pSed.FoldBackColor = SendMessage(hCbBackCol, %CBCOL_GETUSERCOLOR, 0, 0)
      CASE "Fold open"
         pSed.FoldOpenForeColor = SendMessage(hCbForeCol, %CBCOL_GETUSERCOLOR, 0, 0)
         pSed.FoldOpenBackColor = SendMessage(hCbBackCol, %CBCOL_GETUSERCOLOR, 0, 0)
      CASE "Fold margin"
         pSed.FoldMarginForeColor = SendMessage(hCbForeCol, %CBCOL_GETUSERCOLOR, 0, 0)
         pSed.FoldMarginBackColor = SendMessage(hCbBackCol, %CBCOL_GETUSERCOLOR, 0, 0)
      CASE "Indent guides"
         pSed.IndentGuideForeColor = SendMessage(hCbForeCol, %CBCOL_GETUSERCOLOR, 0, 0)
         pSed.IndentGuideBackColor = SendMessage(hCbBackCol, %CBCOL_GETUSERCOLOR, 0, 0)
      CASE "Selection"
         pSed.SelectionForeColor = SendMessage(hCbForeCol, %CBCOL_GETUSERCOLOR, 0, 0)
         pSed.SelectionBackColor = SendMessage(hCbBackCol, %CBCOL_GETUSERCOLOR, 0, 0)
      CASE "Whitespace"
         pSed.WhitespaceForeColor = SendMessage(hCbForeCol, %CBCOL_GETUSERCOLOR, 0, 0)
         pSed.WhitespaceBackColor = SendMessage(hCbBackCol, %CBCOL_GETUSERCOLOR, 0, 0)
      CASE "Codetips"
         pSed.CodetipForeColor = SendMessage(hCbForeCol, %CBCOL_GETUSERCOLOR, 0, 0)
         pSed.CodetipBackColor = SendMessage(hCbBackCol, %CBCOL_GETUSERCOLOR, 0, 0)
      CASE "Caret line"
         pSed.CaretLineBackColor = SendMessage(hCbBackCol, %CBCOL_GETUSERCOLOR, 0, 0)
   END SELECT
END SUB
' ========================================================================================

' ========================================================================================
' Change the selection
' ========================================================================================
#IF %DEF(%UNICODE)
SUB CSED_ColorsAndFontsChangeSelection (BYVAL hwnd AS DWORD, BYVAL curSelStr AS WSTRING)
#ELSE
SUB CSED_ColorsAndFontsChangeSelection (BYVAL hwnd AS DWORD, BYVAL curSelStr AS STRING)
#ENDIF

   LOCAL hCbForeCol AS DWORD
   LOCAL hCbBackCol AS DWORD
   LOCAL hCbFonts AS DWORD
   LOCAL hCbCharset AS DWORD
   LOCAL hCbFontSize AS DWORD
#IF %DEF(%UNICODE)
   LOCAL szText AS WSTRINGZ * 255
#ELSE
   LOCAL szText AS ASCIIZ * 255
#ENDIF

   hCbForeCol  = GetDlgItem(hwnd, %IDC_CBFORECOLOR)
   hCbBackCol  = GetDlgItem(hwnd, %IDC_CBBACKCOLOR)
   hCbFonts    = GetDlgItem(hwnd, %IDC_CBFONTS)
   hCbCharset  = GetDlgItem(hwnd, %IDC_CBCHARSET)
   hCbFontSize = GetDlgItem(hwnd, %IDC_CBFONTSIZE)

   SELECT CASE curSelstr
      CASE "Default"
         EnableWindow hCbForeCol, %TRUE
         EnableWindow hCbBackCol, %TRUE
         EnableWindow hCbFonts, %TRUE
         EnableWindow hCbCharset, %TRUE
         EnableWindow hCbFontSize, %TRUE
         EnableWindow GetDlgItem(hwnd, %IDK_BOLD), %TRUE
         EnableWindow GetDlgItem(hwnd, %IDK_ITALIC), %TRUE
         EnableWindow GetDlgItem(hwnd, %IDK_UNDERLINE), %TRUE
         IF LEN(pSed.DefaultFontName) = 0 THEN pSed.DefaultFontName = "Courier New"
         szText = pSed.DefaultFontName
         SendMessage hCbFonts, %CB_SELECTSTRING, -1, VARPTR(szText)
         IF LEN(pSed.DefaultFontCharset) = 0 THEN pSed.DefaultFontCharset = "Ansi"
         szText = pSed.DefaultFontCharset
         SendMessage hCbCharset, %CB_SELECTSTRING, -1, VARPTR(szText)
         IF pSed.DefaultFontSize = 0 THEN pSed.DefaultFontSize = 8
         szText = FORMAT$(pSed.DefaultFontSize)
         SendMessage hCbFontSize, %CB_SELECTSTRING, -1, VARPTR(szText)
         ' // Default color
         SendMessage hCbForeCol, %CBCOL_SETAUTOCOLOR, %BLACK, 0
         SendMessage hCbBackCol, %CBCOL_SETAUTOCOLOR, %WHITE, 0
         IF pSed.DefaultForeColor = 0 AND _
            pSed.DefaultBackColor = 0 THEN
            pSed.DefaultForeColor = %BLACK
            pSed.DefaultBackColor = %WHITE
         END IF
         ' // User selected color
         SendMessage hCbForeCol, %CBCOL_SETUSERCOLOR, pSed.DefaultForeColor, 0
         SendMessage hCbBackCol, %CBCOL_SETUSERCOLOR, pSed.DefaultBackColor, 0
         ' // Select the user color
         ComboBox_SetCurSel(hCbForeCol, 17)
         ComboBox_SetCurSel(hCbBackCol, 17)
         ' // Checkboxes
         CheckDlgButton(hwnd, %IDK_BOLD, pSed.DefaultFontBold)
         CheckDlgButton(hwnd, %IDK_ITALIC, pSed.DefaultFontItalic)
         CheckDlgButton(hwnd, %IDK_UNDERLINE, pSed.DefaultFontUnderline)
      CASE "Comments"
         EnableWindow hCbForeCol, %TRUE
         EnableWindow hCbBackCol, %TRUE
         EnableWindow hCbFonts, %TRUE
         EnableWindow hCbCharset, %TRUE
         EnableWindow hCbFontSize, %TRUE
         EnableWindow GetDlgItem(hwnd, %IDK_BOLD), %TRUE
         EnableWindow GetDlgItem(hwnd, %IDK_ITALIC), %TRUE
         EnableWindow GetDlgItem(hwnd, %IDK_UNDERLINE), %TRUE
         IF LEN(pSed.CommentFontName) = 0 THEN pSed.CommentFontName = "Courier New"
         szText = pSed.CommentFontName
         SendMessage hCbFonts, %CB_SELECTSTRING, -1, VARPTR(szText)
         IF LEN(pSed.CommentFontCharset) = 0 THEN pSed.CommentFontCharset = "Ansi"
         szText = pSed.CommentFontCharset
         SendMessage hCbCharset, %CB_SELECTSTRING, -1, VARPTR(szText)
         IF pSed.CommentFontSize = 0 THEN pSed.CommentFontSize = 8
         szText = FORMAT$(pSed.CommentFontSize)
         SendMessage hCbFontSize, %CB_SELECTSTRING, -1, VARPTR(szText)
         ' // Default color
         SendMessage hCbForeCol, %CBCOL_SETAUTOCOLOR, RGB(0, 128, 0), 0
         SendMessage hCbBackCol, %CBCOL_SETAUTOCOLOR, %WHITE, 0
         IF pSed.CommentForeColor = 0 AND _
            pSed.CommentBackColor = 0 THEN
            pSed.CommentForeColor = RGB(0, 128, 0)
            pSed.CommentBackColor = %WHITE
         END IF
         ' // User selected color
         SendMessage hCbForeCol, %CBCOL_SETUSERCOLOR, pSed.CommentForeColor, 0
         SendMessage hCbBackCol, %CBCOL_SETUSERCOLOR, pSed.CommentBackColor, 0
         ' // Select the user color
         ComboBox_SetCurSel(hCbForeCol, 17)
         ComboBox_SetCurSel(hCbBackCol, 17)
         ' // Checkboxes
         CheckDlgButton(hwnd, %IDK_BOLD, pSed.CommentFontBold)
         CheckDlgButton(hwnd, %IDK_ITALIC, pSed.CommentFontItalic)
         CheckDlgButton(hwnd, %IDK_UNDERLINE, pSed.CommentFontUnderline)
      CASE "Constants"
         EnableWindow hCbForeCol, %TRUE
         EnableWindow hCbBackCol, %TRUE
         EnableWindow hCbFonts, %TRUE
         EnableWindow hCbCharset, %TRUE
         EnableWindow hCbFontSize, %TRUE
         EnableWindow GetDlgItem(hwnd, %IDK_BOLD), %TRUE
         EnableWindow GetDlgItem(hwnd, %IDK_ITALIC), %TRUE
         EnableWindow GetDlgItem(hwnd, %IDK_UNDERLINE), %TRUE
         IF LEN(pSed.ConstantFontName) = 0 THEN pSed.ConstantFontName = "Courier New"
         szText = pSed.ConstantFontName
         SendMessage hCbFonts, %CB_SELECTSTRING, -1, VARPTR(szText)
         IF LEN(pSed.ConstantFontCharset) = 0 THEN pSed.ConstantFontCharset = "Ansi"
         szText = pSed.ConstantFontCharset
         SendMessage hCbCharset, %CB_SELECTSTRING, -1, VARPTR(szText)
         IF pSed.ConstantFontSize = 0 THEN pSed.ConstantFontSize = 8
         szText = FORMAT$(pSed.ConstantFontSize)
         SendMessage hCbFontSize, %CB_SELECTSTRING, -1, VARPTR(szText)
         ' // Default color
         SendMessage hCbForeCol, %CBCOL_SETAUTOCOLOR, RGB(230, 50, 0), 0
         SendMessage hCbBackCol, %CBCOL_SETAUTOCOLOR, %WHITE, 0
         IF pSed.ConstantForeColor = 0 AND _
            pSed.ConstantBackColor = 0 THEN
            pSed.ConstantForeColor = RGB(230, 50, 0)
            pSed.ConstantBackColor = %WHITE
         END IF
         ' // User selected color
         SendMessage hCbForeCol, %CBCOL_SETUSERCOLOR, pSed.ConstantForeColor, 0
         SendMessage hCbBackCol, %CBCOL_SETUSERCOLOR, pSed.ConstantBackColor, 0
         ' // Select the user color
         ComboBox_SetCurSel(hCbForeCol, 17)
         ComboBox_SetCurSel(hCbBackCol, 17)
         CheckDlgButton(hwnd, %IDK_BOLD, pSed.ConstantFontBold)
         CheckDlgButton(hwnd, %IDK_ITALIC, pSed.ConstantFontItalic)
         CheckDlgButton(hwnd, %IDK_UNDERLINE, pSed.ConstantFontUnderline)
      CASE "Identifiers"
         EnableWindow hCbForeCol, %TRUE
         EnableWindow hCbBackCol, %TRUE
         EnableWindow hCbFonts, %TRUE
         EnableWindow hCbCharset, %TRUE
         EnableWindow hCbFontSize, %TRUE
         EnableWindow GetDlgItem(hwnd, %IDK_BOLD), %TRUE
         EnableWindow GetDlgItem(hwnd, %IDK_ITALIC), %TRUE
         EnableWindow GetDlgItem(hwnd, %IDK_UNDERLINE), %TRUE
         IF LEN(pSed.IdentifierFontName) = 0 THEN pSed.IdentifierFontName = "Courier New"
         szText = pSed.IdentifierFontName
         SendMessage hCbFonts, %CB_SELECTSTRING, -1, VARPTR(szText)
         IF LEN(pSed.IdentifierFontCharset) = 0 THEN pSed.IdentifierFontCharset = "Ansi"
         szText = pSed.IdentifierFontCharset
         SendMessage hCbCharset, %CB_SELECTSTRING, -1, VARPTR(szText)
         IF pSed.IdentifierFontSize = 0 THEN pSed.IdentifierFontSize = 8
         szText = FORMAT$(pSed.IdentifierFontSize)
         SendMessage hCbFontSize, %CB_SELECTSTRING, -1, VARPTR(szText)
         ' // Default color
         SendMessage hCbForeCol, %CBCOL_SETAUTOCOLOR, %BLACK, 0
         SendMessage hCbBackCol, %CBCOL_SETAUTOCOLOR, %WHITE, 0
         IF pSed.IdentifierForeColor = 0 AND _
            pSed.IdentifierBackColor = 0 THEN
            pSed.IdentifierForeColor = %BLACK
            pSed.IdentifierBackColor = %WHITE
         END IF
         ' // User selected color
         SendMessage hCbForeCol, %CBCOL_SETUSERCOLOR, pSed.IdentifierForeColor, 0
         SendMessage hCbBackCol, %CBCOL_SETUSERCOLOR, pSed.IdentifierBackColor, 0
         ' // Select the user color
         ComboBox_SetCurSel(hCbForeCol, 17)
         ComboBox_SetCurSel(hCbBackCol, 17)
         CheckDlgButton(hwnd, %IDK_BOLD, pSed.IdentifierFontBold)
         CheckDlgButton(hwnd, %IDK_ITALIC, pSed.IdentifierFontItalic)
         CheckDlgButton(hwnd, %IDK_UNDERLINE, pSed.IdentifierFontUnderline)
      CASE "Keywords"
         EnableWindow hCbForeCol, %TRUE
         EnableWindow hCbBackCol, %TRUE
         EnableWindow hCbFonts, %TRUE
         EnableWindow hCbCharset, %TRUE
         EnableWindow hCbFontSize, %TRUE
         EnableWindow GetDlgItem(hwnd, %IDK_BOLD), %TRUE
         EnableWindow GetDlgItem(hwnd, %IDK_ITALIC), %TRUE
         EnableWindow GetDlgItem(hwnd, %IDK_UNDERLINE), %TRUE
         IF LEN(pSed.KeywordFontName) = 0 THEN pSed.KeywordFontName = "Courier New"
         szText = pSed.KeywordFontName
         SendMessage hCbFonts, %CB_SELECTSTRING, -1, VARPTR(szText)
         IF LEN(pSed.KeywordFontCharset) = 0 THEN pSed.KeywordFontCharset = "Ansi"
         szText = pSed.KeywordFontCharset
         SendMessage hCbCharset, %CB_SELECTSTRING, -1, VARPTR(szText)
         IF pSed.KeywordFontSize = 0 THEN pSed.KeywordFontSize = 8
         szText = FORMAT$(pSed.KeywordFontSize)
         SendMessage hCbFontSize, %CB_SELECTSTRING, -1, VARPTR(szText)
         ' // Default color
         SendMessage hCbForeCol, %CBCOL_SETAUTOCOLOR, RGB(0, 0, 255), 0
         SendMessage hCbBackCol, %CBCOL_SETAUTOCOLOR, %WHITE, 0
         IF pSed.KeywordForeColor = 0 AND _
            pSed.KeywordBackColor = 0 THEN
            pSed.KeywordForeColor = RGB(0, 0, 255)
            pSed.KeywordBackColor = %WHITE
         END IF
         ' // User selected color
         SendMessage hCbForeCol, %CBCOL_SETUSERCOLOR, pSed.KeywordForeColor, 0
         SendMessage hCbBackCol, %CBCOL_SETUSERCOLOR, pSed.KeywordBackColor, 0
         ' // Select the user color
         ComboBox_SetCurSel(hCbForeCol, 17)
         ComboBox_SetCurSel(hCbBackCol, 17)
         CheckDlgButton(hwnd, %IDK_BOLD, pSed.KeywordFontBold)
         CheckDlgButton(hwnd, %IDK_ITALIC, pSed.KeywordFontItalic)
         CheckDlgButton(hwnd, %IDK_UNDERLINE, pSed.KeywordFontUnderline)
      CASE "Numbers"
         EnableWindow hCbForeCol, %TRUE
         EnableWindow hCbBackCol, %TRUE
         EnableWindow hCbFonts, %TRUE
         EnableWindow hCbCharset, %TRUE
         EnableWindow hCbFontSize, %TRUE
         EnableWindow GetDlgItem(hwnd, %IDK_BOLD), %TRUE
         EnableWindow GetDlgItem(hwnd, %IDK_ITALIC), %TRUE
         EnableWindow GetDlgItem(hwnd, %IDK_UNDERLINE), %TRUE
         IF LEN(pSed.NumberFontName) = 0 THEN pSed.NumberFontName = "Courier New"
         szText = pSed.NumberFontName
         SendMessage hCbFonts, %CB_SELECTSTRING, -1, VARPTR(szText)
         IF LEN(pSed.NumberFontCharset) = 0 THEN pSed.NumberFontCharset = "Ansi"
         szText = pSed.NumberFontCharset
         SendMessage hCbCharset, %CB_SELECTSTRING, -1, VARPTR(szText)
         IF pSed.NumberFontSize = 0 THEN pSed.NumberFontSize = 8
         szText = FORMAT$(pSed.NumberFontSize)
         SendMessage hCbFontSize, %CB_SELECTSTRING, -1, VARPTR(szText)
         ' // Default color
         SendMessage hCbForeCol, %CBCOL_SETAUTOCOLOR, RGB(192, 100, 0), 0
         SendMessage hCbBackCol, %CBCOL_SETAUTOCOLOR, %WHITE, 0
         IF pSed.NumberForeColor = 0 AND _
            pSed.NumberBackColor = 0 THEN
            pSed.NumberForeColor = RGB(192, 100, 0)
            pSed.NumberBackColor = %WHITE
         END IF
         ' // User selected color
         SendMessage hCbForeCol, %CBCOL_SETUSERCOLOR, pSed.NumberForeColor, 0
         SendMessage hCbBackCol, %CBCOL_SETUSERCOLOR, pSed.NumberBackColor, 0
         ' // Select the user color
         ComboBox_SetCurSel(hCbForeCol, 17)
         ComboBox_SetCurSel(hCbBackCol, 17)
         CheckDlgButton(hwnd, %IDK_BOLD, pSed.NumberFontBold)
         CheckDlgButton(hwnd, %IDK_ITALIC, pSed.NumberFontItalic)
         CheckDlgButton(hwnd, %IDK_UNDERLINE, pSed.NumberFontUnderline)
      CASE "Line numbers"
         EnableWindow hCbForeCol, %TRUE
         EnableWindow hCbBackCol, %TRUE
         EnableWindow hCbFonts, %TRUE
         EnableWindow hCbCharset, %TRUE
         EnableWindow hCbFontSize, %TRUE
         EnableWindow GetDlgItem(hwnd, %IDK_BOLD), %TRUE
         EnableWindow GetDlgItem(hwnd, %IDK_ITALIC), %TRUE
         EnableWindow GetDlgItem(hwnd, %IDK_UNDERLINE), %TRUE
         IF LEN(pSed.LineNumberFontName) = 0 THEN pSed.LineNumberFontName = "Courier New"
         szText = pSed.LineNumberFontName
         SendMessage hCbFonts, %CB_SELECTSTRING, -1, VARPTR(szText)
         IF LEN(pSed.LineNumberFontCharset) = 0 THEN pSed.LineNumberFontCharset = "Ansi"
         szText = pSed.LineNumberFontCharset
         SendMessage hCbCharset, %CB_SELECTSTRING, -1, VARPTR(szText)
         IF pSed.LineNumberFontSize = 0 THEN pSed.LineNumberFontSize = 8
         szText = FORMAT$(pSed.LineNumberFontSize)
         SendMessage hCbFontSize, %CB_SELECTSTRING, -1, VARPTR(szText)
         ' // Default color
         SendMessage hCbForeCol, %CBCOL_SETAUTOCOLOR, %BLACK, 0
'         SendMessage hCbBackCol, %CBCOL_SETAUTOCOLOR, RGB(235, 235, 235), 0
         SendMessage hCbBackCol, %CBCOL_SETAUTOCOLOR, %LTGRAY, 0
         IF pSed.LineNumberForeColor = 0 AND _
            pSed.LineNumberBackColor = 0 THEN
            pSed.LineNumberForeColor = %BLACK
            pSed.LineNumberBackColor = %LTGRAY
         END IF
         ' // User selected color
         SendMessage hCbForeCol, %CBCOL_SETUSERCOLOR, pSed.LineNumberForeColor, 0
         SendMessage hCbBackCol, %CBCOL_SETUSERCOLOR, pSed.LineNumberBackColor, 0
         ' // Select the user color
         ComboBox_SetCurSel(hCbForeCol, 17)
         ComboBox_SetCurSel(hCbBackCol, 17)
         CheckDlgButton(hwnd, %IDK_BOLD, pSed.LineNumberFontBold)
         CheckDlgButton(hwnd, %IDK_ITALIC, pSed.LineNumberFontItalic)
         CheckDlgButton(hwnd, %IDK_UNDERLINE, pSed.LineNumberFontUnderline)
      CASE "Operators"
         EnableWindow hCbForeCol, %TRUE
         EnableWindow hCbBackCol, %TRUE
         EnableWindow hCbFonts, %TRUE
         EnableWindow hCbCharset, %TRUE
         EnableWindow hCbFontSize, %TRUE
         EnableWindow GetDlgItem(hwnd, %IDK_BOLD), %TRUE
         EnableWindow GetDlgItem(hwnd, %IDK_ITALIC), %TRUE
         EnableWindow GetDlgItem(hwnd, %IDK_UNDERLINE), %TRUE
         IF LEN(pSed.OperatorFontName) = 0 THEN pSed.OperatorFontName = "Courier New"
         szText = pSed.OperatorFontName
         SendMessage hCbFonts, %CB_SELECTSTRING, -1, VARPTR(szText)
         IF LEN(pSed.OperatorFontCharset) = 0 THEN pSed.OperatorFontCharset = "Ansi"
         szText = pSed.OperatorFontCharset
         SendMessage hCbCharset, %CB_SELECTSTRING, -1, VARPTR(szText)
         IF pSed.OperatorFontSize = 0 THEN pSed.OperatorFontSize = 8
         szText = FORMAT$(pSed.OperatorFontSize)
         SendMessage hCbFontSize, %CB_SELECTSTRING, -1, VARPTR(szText)
         ' // Default color
         SendMessage hCbForeCol, %CBCOL_SETAUTOCOLOR, RGB(0, 128, 128), 0
         SendMessage hCbBackCol, %CBCOL_SETAUTOCOLOR, %WHITE, 0
         IF pSed.OperatorForeColor = 0 AND _
            pSed.OperatorBackColor = 0 THEN
            pSed.OperatorForeColor = RGB(0, 128, 128)
            pSed.OperatorBackColor = %LTGRAY
         END IF
         ' // User selected color
         SendMessage hCbForeCol, %CBCOL_SETUSERCOLOR, pSed.OperatorForeColor, 0
         SendMessage hCbBackCol, %CBCOL_SETUSERCOLOR, pSed.OperatorBackColor, 0
         ' // Select the user color
         ComboBox_SetCurSel(hCbForeCol, 17)
         ComboBox_SetCurSel(hCbBackCol, 17)
         CheckDlgButton(hwnd, %IDK_BOLD, pSed.OperatorFontBold)
         CheckDlgButton(hwnd, %IDK_ITALIC, pSed.OperatorFontItalic)
         CheckDlgButton(hwnd, %IDK_UNDERLINE, pSed.OperatorFontUnderline)
      CASE "Preprocessor"
         EnableWindow hCbForeCol, %TRUE
         EnableWindow hCbBackCol, %TRUE
         EnableWindow hCbFonts, %TRUE
         EnableWindow hCbCharset, %TRUE
         EnableWindow hCbFontSize, %TRUE
         EnableWindow GetDlgItem(hwnd, %IDK_BOLD), %TRUE
         EnableWindow GetDlgItem(hwnd, %IDK_ITALIC), %TRUE
         EnableWindow GetDlgItem(hwnd, %IDK_UNDERLINE), %TRUE
         IF LEN(pSed.PreprocessorFontName) = 0 THEN pSed.PreprocessorFontName = "Courier New"
         szText = pSed.PreprocessorFontName
         SendMessage hCbFonts, %CB_SELECTSTRING, -1, VARPTR(szText)
         IF LEN(pSed.PreprocessorFontCharset) = 0 THEN pSed.PreprocessorFontCharset = "Ansi"
         szText = pSed.PreprocessorFontCharset
         SendMessage hCbCharset, %CB_SELECTSTRING, -1, VARPTR(szText)
         IF pSed.PreprocessorFontSize = 0 THEN pSed.PreprocessorFontSize = 8
         szText = FORMAT$(pSed.PreprocessorFontSize)
         SendMessage hCbFontSize, %CB_SELECTSTRING, -1, VARPTR(szText)
         ' // Default color
         SendMessage hCbForeCol, %CBCOL_SETAUTOCOLOR, RGB(255, 0, 0), 0
         SendMessage hCbBackCol, %CBCOL_SETAUTOCOLOR, %WHITE, 0
         IF pSed.PreprocessorForeColor = 0 AND _
            pSed.PreprocessorbackColor = 0 THEN
            pSed.PreprocessorForeColor = RGB(255, 0, 0)
            pSed.PreprocessorBackColor = %WHITE
         END IF
         ' // User selected color
         SendMessage hCbForeCol, %CBCOL_SETUSERCOLOR, pSed.PreprocessorForeColor, 0
         SendMessage hCbBackCol, %CBCOL_SETUSERCOLOR, pSed.PreprocessorBackColor, 0
         ' // Select the user color
         ComboBox_SetCurSel(hCbForeCol, 17)
         ComboBox_SetCurSel(hCbBackCol, 17)
         CheckDlgButton(hwnd, %IDK_BOLD, pSed.PreprocessorFontBold)
         CheckDlgButton(hwnd, %IDK_ITALIC, pSed.PreprocessorFontItalic)
         CheckDlgButton(hwnd, %IDK_UNDERLINE, pSed.PreprocessorFontUnderline)
      CASE "Strings"
         EnableWindow hCbForeCol, %TRUE
         EnableWindow hCbBackCol, %TRUE
         EnableWindow hCbFonts, %TRUE
         EnableWindow hCbCharset, %TRUE
         EnableWindow hCbFontSize, %TRUE
         EnableWindow GetDlgItem(hwnd, %IDK_BOLD), %TRUE
         EnableWindow GetDlgItem(hwnd, %IDK_ITALIC), %TRUE
         EnableWindow GetDlgItem(hwnd, %IDK_UNDERLINE), %TRUE
         IF LEN(pSed.StringFontName) = 0 THEN pSed.StringFontName = "Courier New"
         szText = pSed.StringFontName
         SendMessage hCbFonts, %CB_SELECTSTRING, -1, VARPTR(szText)
         IF LEN(pSed.StringFontCharset) = 0 THEN pSed.StringFontCharset = "Ansi"
         szText = pSed.StringFontCharset
         SendMessage hCbCharset, %CB_SELECTSTRING, -1, VARPTR(szText)
         IF pSed.StringFontSize = 0 THEN pSed.StringFontSize = 8
         szText = FORMAT$(pSed.StringFontSize)
         SendMessage hCbFontSize, %CB_SELECTSTRING, -1, VARPTR(szText)
         ' // Default color
         SendMessage hCbForeCol, %CBCOL_SETAUTOCOLOR, RGB(255, 0, 255), 0
         SendMessage hCbBackCol, %CBCOL_SETAUTOCOLOR, %WHITE, 0
         IF pSed.StringForeColor = 0 AND _
            pSed.StringBackColor = 0 THEN
            pSed.StringForeColor = RGB(255, 0, 255)
            pSed.StringBackColor = %WHITE
         END IF
         ' // User selected color
         SendMessage hCbForeCol, %CBCOL_SETUSERCOLOR, pSed.StringForeColor, 0
         SendMessage hCbBackCol, %CBCOL_SETUSERCOLOR, pSed.StringBackColor, 0
         ' // Select the user color
         ComboBox_SetCurSel(hCbForeCol, 17)
         ComboBox_SetCurSel(hCbBackCol, 17)
         CheckDlgButton(hwnd, %IDK_BOLD, pSed.StringFontBold)
         CheckDlgButton(hwnd, %IDK_ITALIC, pSed.StringFontItalic)
         CheckDlgButton(hwnd, %IDK_UNDERLINE, pSed.StringFontUnderline)
      CASE "Caret"
         ' // Default color
         EnableWindow hCbForeCol, %TRUE
         SendMessage hCbForeCol, %CBCOL_SETAUTOCOLOR, %BLACK, 0
         ' // User selected color
         SendMessage hCbForeCol, %CBCOL_SETUSERCOLOR, pSed.CaretForeColor, 0
         ' // Select the user color
         ComboBox_SetCurSel(hCbForeCol, 17)
         ComboBox_SetCurSel(hCbBackCol, 17)
         CheckDlgButton(hwnd, %IDK_BOLD, %BST_UNCHECKED)
         CheckDlgButton(hwnd, %IDK_ITALIC, %BST_UNCHECKED)
         CheckDlgButton(hwnd, %IDK_UNDERLINE, %BST_UNCHECKED)
         ComboBox_SetCurSel(hCbFonts, -1)
         ComboBox_SetCurSel(hCbCharset, -1)
         ComboBox_SetCurSel(hCbFontSize, -1)
         EnableWindow hCbBackCol, %FALSE
         EnableWindow hCbFonts, %FALSE
         EnableWindow hCbCharset, %FALSE
         EnableWindow hCbFontSize, %FALSE
         EnableWindow GetDlgItem(hwnd, %IDK_BOLD), %FALSE
         EnableWindow GetDlgItem(hwnd, %IDK_ITALIC), %FALSE
         EnableWindow GetDlgItem(hwnd, %IDK_UNDERLINE), %FALSE
      CASE "Edge"
         ' // Default color
         EnableWindow hCbForeCol, %TRUE
         EnableWindow hCbBackCol, %TRUE
         SendMessage hCbForeCol, %CBCOL_SETAUTOCOLOR, %BLACK, 0
         SendMessage hCbBackCol, %CBCOL_SETAUTOCOLOR, %WHITE, 0
         IF pSed.EdgeForeColor = 0 AND _
            pSed.EdgeBackColor = 0 THEN _
            pSed.EdgeBackColor = %WHITE
         ' // User selected color
         SendMessage hCbForeCol, %CBCOL_SETUSERCOLOR, pSed.EdgeForeColor, 0
         SendMessage hCbBackCol, %CBCOL_SETUSERCOLOR, pSed.EdgeBackColor, 0
         ' // Select the user color
         ComboBox_SetCurSel(hCbForeCol, 17)
         ComboBox_SetCurSel(hCbBackCol, 17)
         CheckDlgButton(hwnd, %IDK_BOLD, %BST_UNCHECKED)
         CheckDlgButton(hwnd, %IDK_ITALIC, %BST_UNCHECKED)
         CheckDlgButton(hwnd, %IDK_UNDERLINE, %BST_UNCHECKED)
         ComboBox_SetCurSel(hCbFonts, -1)
         ComboBox_SetCurSel(hCbCharset, -1)
         ComboBox_SetCurSel(hCbFontSize, -1)
         EnableWindow hCbFonts, %FALSE
         EnableWindow hCbCharset, %FALSE
         EnableWindow hCbFontSize, %FALSE
         EnableWindow GetDlgItem(hwnd, %IDK_BOLD), %FALSE
         EnableWindow GetDlgItem(hwnd, %IDK_ITALIC), %FALSE
         EnableWindow GetDlgItem(hwnd, %IDK_UNDERLINE), %FALSE
      CASE "Fold"
         ' // Default color
         EnableWindow hCbForeCol, %TRUE
         EnableWindow hCbBackCol, %TRUE
         SendMessage hCbForeCol, %CBCOL_SETAUTOCOLOR, %RED, 0
         SendMessage hCbBackCol, %CBCOL_SETAUTOCOLOR, %WHITE, 0
         IF pSed.FoldForeColor = 0 AND _
            pSed.FoldBackColor = 0 THEN
            pSed.FoldForeColor = %RED
            pSed.FoldBackColor = %WHITE
         END IF
         ' // User selected color
         SendMessage hCbForeCol, %CBCOL_SETUSERCOLOR, pSed.FoldForeColor, 0
         SendMessage hCbBackCol, %CBCOL_SETUSERCOLOR, pSed.FoldBackColor, 0
         ' // Select the user color
         ComboBox_SetCurSel(hCbForeCol, 17)
         ComboBox_SetCurSel(hCbBackCol, 17)
         CheckDlgButton(hwnd, %IDK_BOLD, %BST_UNCHECKED)
         CheckDlgButton(hwnd, %IDK_ITALIC, %BST_UNCHECKED)
         CheckDlgButton(hwnd, %IDK_UNDERLINE, %BST_UNCHECKED)
         ComboBox_SetCurSel(hCbFonts, -1)
         ComboBox_SetCurSel(hCbCharset, -1)
         ComboBox_SetCurSel(hCbFontSize, -1)
         EnableWindow hCbFonts, %FALSE
         EnableWindow hCbCharset, %FALSE
         EnableWindow hCbFontSize, %FALSE
         EnableWindow GetDlgItem(hwnd, %IDK_BOLD), %FALSE
         EnableWindow GetDlgItem(hwnd, %IDK_ITALIC), %FALSE
         EnableWindow GetDlgItem(hwnd, %IDK_UNDERLINE), %FALSE
      CASE "Fold open"
         ' // Default color
         EnableWindow hCbForeCol, %TRUE
         EnableWindow hCbBackCol, %TRUE
         SendMessage hCbForeCol, %CBCOL_SETAUTOCOLOR, %RED, 0
         SendMessage hCbBackCol, %CBCOL_SETAUTOCOLOR, %WHITE, 0
         IF pSed.FoldOpenForeColor = 0 AND _
            pSed.FoldOpenBackColor = 0 THEN
            pSed.FoldOpenForeColor = %RED
            pSed.FoldOpenBackColor = %WHITE
         END IF
         ' // User selected color
         SendMessage hCbForeCol, %CBCOL_SETUSERCOLOR, pSed.FoldOpenForeColor, 0
         SendMessage hCbBackCol, %CBCOL_SETUSERCOLOR, pSed.FoldOpenBackColor, 0
         ' // Select the user color
         ComboBox_SetCurSel(hCbForeCol, 17)
         ComboBox_SetCurSel(hCbBackCol, 17)
         CheckDlgButton(hwnd, %IDK_BOLD, %BST_UNCHECKED)
         CheckDlgButton(hwnd, %IDK_ITALIC, %BST_UNCHECKED)
         CheckDlgButton(hwnd, %IDK_UNDERLINE, %BST_UNCHECKED)
         ComboBox_SetCurSel(hCbFonts, -1)
         ComboBox_SetCurSel(hCbCharset, -1)
         ComboBox_SetCurSel(hCbFontSize, -1)
         EnableWindow hCbFonts, %FALSE
         EnableWindow hCbCharset, %FALSE
         EnableWindow hCbFontSize, %FALSE
         EnableWindow GetDlgItem(hwnd, %IDK_BOLD), %FALSE
         EnableWindow GetDlgItem(hwnd, %IDK_ITALIC), %FALSE
         EnableWindow GetDlgItem(hwnd, %IDK_UNDERLINE), %FALSE
      CASE "Fold margin"
         ' // Default color
         EnableWindow hCbForeCol, %TRUE
         EnableWindow hCbBackCol, %TRUE
         SendMessage hCbForeCol, %CBCOL_SETAUTOCOLOR, RGB(200,0,200), 0
         SendMessage hCbBackCol, %CBCOL_SETAUTOCOLOR, RGB(100,0,100), 0
         IF pSed.FoldMarginForeColor = 0 AND _
            pSed.FoldMarginBackColor = 0 THEN
            pSed.FoldMarginForeColor = RGB(200,0,200)
            pSed.FoldMarginBackColor = RGB(100,0,100)
         END IF
         ' // User selected color
         SendMessage hCbForeCol, %CBCOL_SETUSERCOLOR, pSed.FoldMarginForeColor, 0
         SendMessage hCbBackCol, %CBCOL_SETUSERCOLOR, pSed.FoldMarginBackColor, 0
         ' // Select the user color
         ComboBox_SetCurSel(hCbForeCol, 17)
         ComboBox_SetCurSel(hCbBackCol, 17)
         CheckDlgButton(hwnd, %IDK_BOLD, %BST_UNCHECKED)
         CheckDlgButton(hwnd, %IDK_ITALIC, %BST_UNCHECKED)
         CheckDlgButton(hwnd, %IDK_UNDERLINE, %BST_UNCHECKED)
         ComboBox_SetCurSel(hCbFonts, -1)
         ComboBox_SetCurSel(hCbCharset, -1)
         ComboBox_SetCurSel(hCbFontSize, -1)
         EnableWindow hCbFonts, %FALSE
         EnableWindow hCbCharset, %FALSE
         EnableWindow hCbFontSize, %FALSE
         EnableWindow GetDlgItem(hwnd, %IDK_BOLD), %FALSE
         EnableWindow GetDlgItem(hwnd, %IDK_ITALIC), %FALSE
         EnableWindow GetDlgItem(hwnd, %IDK_UNDERLINE), %FALSE
      CASE "Indent guides"
         ' // Default color
         EnableWindow hCbForeCol, %TRUE
         EnableWindow hCbBackCol, %TRUE
         SendMessage hCbForeCol, %CBCOL_SETAUTOCOLOR, %BLACK, 0
         SendMessage hCbBackCol, %CBCOL_SETAUTOCOLOR, %WHITE, 0
         IF pSed.IndentGuideForeColor = 0 AND _
            pSed.IndentGuideBackColor = 0 THEN
            pSed.IndentGuideForeColor = %BLACK
            pSed.IndentGuideBackColor = %WHITE
         END IF
         ' // User selected color
         SendMessage hCbForeCol, %CBCOL_SETUSERCOLOR, pSed.IndentGuideForeColor, 0
         SendMessage hCbBackCol, %CBCOL_SETUSERCOLOR, pSed.IndentGuideBackColor, 0
         ' // Select the user color
         ComboBox_SetCurSel(hCbForeCol, 17)
         ComboBox_SetCurSel(hCbBackCol, 17)
         CheckDlgButton(hwnd, %IDK_BOLD, %BST_UNCHECKED)
         CheckDlgButton(hwnd, %IDK_ITALIC, %BST_UNCHECKED)
         CheckDlgButton(hwnd, %IDK_UNDERLINE, %BST_UNCHECKED)
         ComboBox_SetCurSel(hCbFonts, -1)
         ComboBox_SetCurSel(hCbCharset, -1)
         ComboBox_SetCurSel(hCbFontSize, -1)
         EnableWindow hCbFonts, %FALSE
         EnableWindow hCbCharset, %FALSE
         EnableWindow hCbFontSize, %FALSE
         EnableWindow GetDlgItem(hwnd, %IDK_BOLD), %FALSE
         EnableWindow GetDlgItem(hwnd, %IDK_ITALIC), %FALSE
         EnableWindow GetDlgItem(hwnd, %IDK_UNDERLINE), %FALSE
      CASE "Selection"
         ' // Default color
         EnableWindow hCbForeCol, %TRUE
         EnableWindow hCbBackCol, %TRUE
         SendMessage hCbForeCol, %CBCOL_SETAUTOCOLOR, %BLACK, 0
         SendMessage hCbBackCol, %CBCOL_SETAUTOCOLOR, %LTGRAY, 0
         IF pSed.SelectionForeColor = 0 AND _
            pSed.SelectionBackColor = 0 THEN _
            pSed.SelectionBackColor = %LTGRAY
         ' // User selected color
         SendMessage hCbForeCol, %CBCOL_SETUSERCOLOR, pSed.SelectionForeColor, 0
         SendMessage hCbBackCol, %CBCOL_SETUSERCOLOR, pSed.SelectionBackColor, 0
         ' Select the user color
         ComboBox_SetCurSel(hCbForeCol, 17)
         ComboBox_SetCurSel(hCbBackCol, 17)
         CheckDlgButton(hwnd, %IDK_BOLD, %BST_UNCHECKED)
         CheckDlgButton(hwnd, %IDK_ITALIC, %BST_UNCHECKED)
         CheckDlgButton(hwnd, %IDK_UNDERLINE, %BST_UNCHECKED)
         ComboBox_SetCurSel(hCbFonts, -1)
         ComboBox_SetCurSel(hCbCharset, -1)
         ComboBox_SetCurSel(hCbFontSize, -1)
         EnableWindow hCbFonts, %FALSE
         EnableWindow hCbCharset, %FALSE
         EnableWindow hCbFontSize, %FALSE
         EnableWindow GetDlgItem(hwnd, %IDK_BOLD), %FALSE
         EnableWindow GetDlgItem(hwnd, %IDK_ITALIC), %FALSE
         EnableWindow GetDlgItem(hwnd, %IDK_UNDERLINE), %FALSE
      CASE "Whitespace"
         ' // Default color
         EnableWindow hCbForeCol, %TRUE
         EnableWindow hCbBackCol, %TRUE
         SendMessage hCbForeCol, %CBCOL_SETAUTOCOLOR, %BLACK, 0
         SendMessage hCbBackCol, %CBCOL_SETAUTOCOLOR, %WHITE, 0
         IF pSed.WhiteSpaceForeColor = 0 AND _
            pSed.WhiteSpaceBackColor = 0 THEN _
            pSed.WhiteSpaceBackColor = %WHITE
         ' // User selected color
         SendMessage hCbForeCol, %CBCOL_SETUSERCOLOR, pSed.WhitespaceForeColor, 0
         SendMessage hCbBackCol, %CBCOL_SETUSERCOLOR, pSed.WhiteSpaceBackColor, 0
         ' // Select the user color
         ComboBox_SetCurSel(hCbForeCol, 17)
         ComboBox_SetCurSel(hCbBackCol, 17)
         CheckDlgButton(hwnd, %IDK_BOLD, %BST_UNCHECKED)
         CheckDlgButton(hwnd, %IDK_ITALIC, %BST_UNCHECKED)
         CheckDlgButton(hwnd, %IDK_UNDERLINE, %BST_UNCHECKED)
         ComboBox_SetCurSel(hCbFonts, -1)
         ComboBox_SetCurSel(hCbCharset, -1)
         ComboBox_SetCurSel(hCbFontSize, -1)
         EnableWindow hCbFonts, %FALSE
         EnableWindow hCbCharset, %FALSE
         EnableWindow hCbFontSize, %FALSE
         EnableWindow GetDlgItem(hwnd, %IDK_BOLD), %FALSE
         EnableWindow GetDlgItem(hwnd, %IDK_ITALIC), %FALSE
         EnableWindow GetDlgItem(hwnd, %IDK_UNDERLINE), %FALSE
      CASE "Codetips"
         ' // Default color
         EnableWindow hCbForeCol, %TRUE
         EnableWindow hCbBackCol, %TRUE
         SendMessage hCbForeCol, %CBCOL_SETAUTOCOLOR, %LTGRAY, 0
         SendMessage hCbBackCol, %CBCOL_SETAUTOCOLOR, %WHITE, 0
         IF pSed.CodetipForeColor = 0 AND _
            pSed.CodetipBackColor = 0 THEN
            pSed.CodetipForeColor = %LTGRAY
            pSed.CodetipBackColor = %WHITE
         END IF
         ' // User selected color
         SendMessage hCbForeCol, %CBCOL_SETUSERCOLOR, pSed.CodetipForeColor, 0
         SendMessage hCbBackCol, %CBCOL_SETUSERCOLOR, pSed.CodetipBackColor, 0
         ' // Select the user color
         ComboBox_SetCurSel(hCbForeCol, 17)
         ComboBox_SetCurSel(hCbBackCol, 17)
         CheckDlgButton(hwnd, %IDK_BOLD, %BST_UNCHECKED)
         CheckDlgButton(hwnd, %IDK_ITALIC, %BST_UNCHECKED)
         CheckDlgButton(hwnd, %IDK_UNDERLINE, %BST_UNCHECKED)
         ComboBox_SetCurSel(hCbFonts, -1)
         ComboBox_SetCurSel(hCbCharset, -1)
         ComboBox_SetCurSel(hCbFontSize, -1)
         EnableWindow hCbFonts, %FALSE
         EnableWindow hCbCharset, %FALSE
         EnableWindow hCbFontSize, %FALSE
         EnableWindow GetDlgItem(hwnd, %IDK_BOLD), %FALSE
         EnableWindow GetDlgItem(hwnd, %IDK_ITALIC), %FALSE
         EnableWindow GetDlgItem(hwnd, %IDK_UNDERLINE), %FALSE
      CASE "Caret line"
         ' // Default color
         EnableWindow hCbBackCol, %TRUE
         SendMessage hCbBackCol, %CBCOL_SETAUTOCOLOR, %YELLOW, 0
         ' // User selected color
         SendMessage hCbBackCol, %CBCOL_SETUSERCOLOR, pSed.CaretLineBackColor, 0
         ' // Select the user color
         ComboBox_SetCurSel(hCbForeCol, 17)
         ComboBox_SetCurSel(hCbBackCol, 17)
         CheckDlgButton(hwnd, %IDK_BOLD, %BST_UNCHECKED)
         CheckDlgButton(hwnd, %IDK_ITALIC, %BST_UNCHECKED)
         CheckDlgButton(hwnd, %IDK_UNDERLINE, %BST_UNCHECKED)
         ComboBox_SetCurSel(hCbFonts, -1)
         ComboBox_SetCurSel(hCbCharset, -1)
         ComboBox_SetCurSel(hCbFontSize, -1)
         EnableWindow hCbForeCol, %FALSE
         EnableWindow hCbFonts, %FALSE
         EnableWindow hCbCharset, %FALSE
         EnableWindow hCbFontSize, %FALSE
         EnableWindow GetDlgItem(hwnd, %IDK_BOLD), %FALSE
         EnableWindow GetDlgItem(hwnd, %IDK_ITALIC), %FALSE
         EnableWindow GetDlgItem(hwnd, %IDK_UNDERLINE), %FALSE
   END SELECT

END SUB
' ========================================================================================

' ========================================================================================
' Color and fonts options dialog
' ========================================================================================
SUB CSED_ColorOptionsDialog (BYVAL hParent AS DWORD)

   LOCAL hFont AS DWORD

   ' // Create an instance of the class
   LOCAL pColorOpt AS IWindow
   pColorOpt = CLASS "CWindow"
   IF ISNOTHING(pColorOpt) THEN EXIT SUB

   ' // Create the main window
   LOCAL hwnd AS DWORD
'   hwnd = pColorOpt.CreateWindow(hParent, "Colors and Fonts", 0, 0, 578, 420, _
'          %WS_VISIBLE OR %WS_CAPTION OR %WS_POPUPWINDOW, %WS_EX_TOOLWINDOW OR %WS_EX_WINDOWEDGE, _
'          CODEPTR(CSED_ColorOpt_WindowProc))
   hwnd = pColorOpt.CreateWindow(hParent, "Colors and Fonts", 0, 0, 0, 0, _
          %WS_VISIBLE OR %WS_CAPTION OR %WS_POPUPWINDOW, %WS_EX_WINDOWEDGE, _
          CODEPTR(CSED_ColorOpt_WindowProc))
   pColorOpt.SetClientSize 572, 400
   pColorOpt.CenterWindow(hwnd, hParent)

   ' // Add the controls
   LOCAL hCtl AS DWORD

   hCtl = pColorOpt.AddGroupBox(hwnd, -1, "Color", 10, 10, 552, 205, -1)
   hCtl = pColorOpt.AddLabel(hwnd, -1, "Item", 20, 30, 240, 20, -1)
   hCtl = pColorOpt.AddListBox(hwnd, %IDC_LBCOLSEL, "", 20, 50, 240, 150, _
          %WS_CHILD OR %WS_VISIBLE OR %WS_BORDER OR %WS_VSCROLL OR %WS_TABSTOP OR _
          %LBS_NOTIFY OR %LBS_NOINTEGRALHEIGHT, %WS_EX_CLIENTEDGE)

   hFont = pColorOpt.CreateFont("Tahoma", 8, %FW_BOLD, %FALSE, %FALSE, %FALSE, %DEFAULT_CHARSET)
   SendMessage hCtl, %WM_SETFONT, hFont, %TRUE

   Listbox_AddString hCtl, "Default"
   Listbox_AddString hCtl, "Caret"
   Listbox_AddString hCtl, "Caret line"
   Listbox_AddString hCtl, "Codetips"
   Listbox_AddString hCtl, "Comments"
'   Listbox_AddString hCtl, "Constants"
   Listbox_AddString hCtl, "Edge"
   Listbox_AddString hCtl, "Fold"
   Listbox_AddString hCtl, "Fold open"
   Listbox_AddString hCtl, "Fold margin"
   Listbox_AddString hCtl, "Identifiers"
   Listbox_AddString hCtl, "Indent guides"
   Listbox_AddString hCtl, "Keywords"
   Listbox_AddString hCtl, "Numbers"
   Listbox_AddString hCtl, "Line numbers"
   Listbox_AddString hCtl, "Operators"
   Listbox_AddString hCtl, "Preprocessor"
   Listbox_AddString hCtl, "Selection"
   Listbox_AddString hCtl, "Strings"
   Listbox_AddString hCtl, "Whitespace"

   Listbox_SetCurSel(hCtl, 0)
   SetFocus hCtl

   hCtl = pColorOpt.AddLabel(hwnd, -1, "Foreground color", 280, 50, 100, 20, -1)
   hCtl = CSED_CreateCBColorList(hwnd, %IDC_CBFORECOLOR, 280, 70, 270, 240, _
          GetSysColor(%COLOR_WINDOWTEXT), GetSysColor(%COLOR_WINDOWTEXT), _
          pColorOpt.rxRatio, pColorOpt.ryRatio)
   hCtl = pColorOpt.AddButton(hwnd, %IDB_USERFORECOLOR, "Custom color", 443, 103, 105, 22, -1)

   hCtl = pColorOpt.AddLabel(hwnd, -1, "Background color", 280, 120, 100, 20, -1)
   hCtl = CSED_CreateCBColorList(hwnd, %IDC_CBBACKCOLOR, 280, 140, 270, 240, _
          GetSysColor(%COLOR_WINDOWTEXT), GetSysColor(%COLOR_WINDOWTEXT), _
          pColorOpt.rxRatio, pColorOpt.ryRatio)
   hCtl = pColorOpt.AddButton(hwnd, %IDB_USERBACKCOLOR, "Custom color", 443, 173, 105, 22, -1)

   hCtl = pColorOpt.AddGroupBox(hwnd, -1, "Font", 10, 222, 290, 80, -1)
   hCtl = pColorOpt.AddComboBox(hwnd, %IDC_CBFONTS, "", 20, 244, 270, 200, _
          %WS_CHILD OR %WS_VISIBLE OR %WS_TABSTOP OR %WS_VSCROLL OR %CBS_DROPDOWNLIST OR _
          %CBS_OWNERDRAWFIXED OR %CBS_HASSTRINGS OR %CBS_SORT, %WS_EX_CLIENTEDGE)

   ' // Nicer with a bit bigger font, so increase line height in control - adjust to own liking.
   LOCAL ItemHeight AS LONG
   ItemHeight = SendMessage(hCtl, %CB_GETITEMHEIGHT, 0, 0)    ' // Get current line height
   SendMessage hCtl, %CB_SETITEMHEIGHT, -1, ItemHeight + 4    ' // Increase in edit part
   SendMessage hCtl, %CB_SETITEMHEIGHT, 0, ItemHeight + 4     ' // Increase in list

   ' // Fill the fonts combobox
   CSED_FillFontCombo hCtl

   ' // Reset the FullRange static variable
   CSED_FillFontSizeCombo hwnd, ""

   hCtl = pColorOpt.AddGroupBox(hwnd, -1, "Charset", 310, 222, 166, 80, -1)
   hCtl = pColorOpt.AddComboBox(hwnd, %IDC_CBCHARSET, "", 320, 244, 146, 146, -1)

   ComboBox_AddString hCtl, "Default"
   ComboBox_AddString hCtl, "Ansi"
   ComboBox_AddString hCtl, "Arabic"
   ComboBox_AddString hCtl, "Baltic"
   ComboBox_AddString hCtl, "Chinese Big 5"
   ComboBox_AddString hCtl, "East Europe"
   ComboBox_AddString hCtl, "GB 2312"
   ComboBox_AddString hCtl, "Greek"
   ComboBox_AddString hCtl, "Hangul"
   ComboBox_AddString hCtl, "Hebrew"
   ComboBox_AddString hCtl, "Johab"
   ComboBox_AddString hCtl, "Mac"
   ComboBox_AddString hCtl, "OEM"
   ComboBox_AddString hCtl, "Russian"
   ComboBox_AddString hCtl, "Shiftjis"
   ComboBox_AddString hCtl, "Symbol"
   ComboBox_AddString hCtl, "Thai"
   ComboBox_AddString hCtl, "Turkish"
   ComboBox_AddString hCtl, "Vietnamese"

   hCtl = pColorOpt.AddGroupBox(hwnd, -1, "Size", 486, 222, 76, 80, -1)
   hCtl = pColorOpt.AddComboBox(hwnd, %IDC_CBFONTSIZE, "", 496, 244, 56, 146, %WS_CHILD OR %WS_VISIBLE OR %WS_VSCROLL OR %WS_BORDER OR %WS_TABSTOP OR %CBS_DROPDOWN OR %CBS_HASSTRINGS)
   hCtl = pColorOpt.AddCheckBox(hwnd, %IDK_BOLD, "Bold", 20, 275, 70, 20, -1)
   hCtl = pColorOpt.AddCheckBox(hwnd, %IDK_ITALIC, "Italic", 112, 275, 70, 20, -1)
   hCtl = pColorOpt.AddCheckBox(hwnd, %IDK_UNDERLINE, "Underline", 194, 275, 80, 20, -1)

   hCtl = pColorOpt.AddCheckBox(hwnd, %IDK_USEDEFAULTCOLOR, _
          "Use always the default background color", 20, 312, 260, 20, -1)
   hCtl = pColorOpt.AddCheckBox(hwnd, %IDK_USEDEFAULTFONT, _
          "Use always the default font", 20, 334, 260, 20, -1)
   hCtl = pColorOpt.AddCheckBox(hwnd, %IDK_USEDEFAULTSIZE, _
          "Use always the default font size", 20, 356, 260, 20, -1)

   hCtl = pColorOpt.AddButton(hwnd, %IDOK, "&Apply", 306, 360, 75, 24, %BS_DEFPUSHBUTTON)
   hCtl = pColorOpt.AddButton(hwnd, %IDCANCEL, "&Close", 396, 360, 75, 24, -1)
   hCtl = pColorOpt.AddButton(hwnd, %IDBO_COLORS_HELP, "&Help", 486, 360, 75, 24, -1)

   ' // Select the default
   CSED_FillFontSizeCombo hwnd, "Default"
   CSED_ColorsAndFontsChangeSelection hwnd, "Default"
   IF pSed.UseAlwaysDefaultBackColor THEN CheckDlgButton(hwnd, %IDK_USEDEFAULTCOLOR, %BST_CHECKED)
   IF pSed.UseAlwaysDefaultFont THEN CheckDlgButton(hwnd, %IDK_USEDEFAULTFONT, %BST_CHECKED)
   IF pSed.UseAlwaysDefaultFontSize THEN CheckDlgButton(hwnd, %IDK_USEDEFAULTSIZE, %BST_CHECKED)

   ' // Default message pump (you can replace it with your own)
   pColorOpt.DoEvents

   IF hFont THEN DeleteObject hFont

END SUB
' ========================================================================================

' ========================================================================================
' Color options dialog procedure
' ========================================================================================
FUNCTION CSED_ColorOpt_WindowProc (BYVAL hwnd AS DWORD, BYVAL wMsg AS DWORD, BYVAL wParam AS DWORD, BYVAL lParam AS LONG) AS LONG

   LOCAL  userColor                 AS LONG
   LOCAL  selColor                  AS LONG
   LOCAL  curSel                    AS DWORD
#IF %DEF(%UNICODE)
   LOCAL  curSelStr                 AS WSTRING
   LOCAL  strFontName               AS WSTRING
   LOCAL  szPath                    AS WSTRINGZ * %MAX_PATH
   LOCAL  szText                    AS WSTRINGZ * %MAX_PATH
#ELSE
   LOCAL  curSelStr                 AS STRING
   LOCAL  strFontName               AS STRING
   LOCAL  szPath                    AS ASCIIZ * %MAX_PATH
   LOCAL  szText                    AS ASCIIZ * %MAX_PATH
#ENDIF
   STATIC hFocus                    AS DWORD

   SELECT CASE wMsg

      CASE %WM_CREATE
         ' // To make popup dialog modal
         EnableWindow GetParent(hwnd), %FALSE

      CASE %WM_NCACTIVATE
         IF ISFALSE wParam THEN hFocus = GetFocus

      CASE %WM_SETFOCUS
         IF hFocus THEN
            PostMessage hwnd, %WM_USER + 999, hFocus, 0
            hFocus = 0
         END IF

      CASE %WM_USER + 999
         IF ISTRUE wParam THEN SetFocus wParam

      CASE %WM_DRAWITEM   ' // Must pass this one on to ownerdrawn combo!
         IF wParam = %IDC_CBFORECOLOR THEN
            SendMessage GetDlgItem(hwnd, %IDC_CBFORECOLOR), wMsg, wParam, lParam
            FUNCTION = %TRUE
            EXIT FUNCTION
         END IF
         IF wParam = %IDC_CBBACKCOLOR THEN
            SendMessage GetDlgItem(hwnd, %IDC_CBBACKCOLOR), wMsg, wParam, lParam
            FUNCTION = %TRUE
            EXIT FUNCTION
         END IF
         IF wParam = %IDC_CBFONTS THEN
            CSED_DrawFontCombo GetDlgItem(hwnd, %IDC_CBFONTS), wParam, lParam
            FUNCTION = %TRUE
            EXIT FUNCTION
         END IF

      CASE %WM_COMMAND
         SELECT CASE LO(WORD, wParam)
            CASE %IDOK
               IF HI(WORD, wParam) = %BN_CLICKED THEN
                  ' // Get the selection
                  curSel = ListBox_GetCursel(GetDlgItem(hwnd, %IDC_LBCOLSEL))
                  curSelStr = ListBox_GetText(GetDlgItem(hwnd, %IDC_LBCOLSEL), curSel)
                  ' // Save the options
                  CSED_SaveColorsAndFontsSelection hwnd, curSelStr
                  ' // Get the Use always default background setting
                  pSed.UseAlwaysDefaultBackColor = IsDlgButtonChecked(hwnd, %IDK_USEDEFAULTCOLOR)
                  ' // Get the Use always default font
                  pSed.UseAlwaysDefaultFont = IsDlgButtonChecked(hwnd, %IDK_USEDEFAULTFONT)
                  ' // Get the Use always default font size
                  pSed.UseAlwaysDefaultFontSize = IsDlgButtonChecked(hwnd, %IDK_USEDEFAULTSIZE)
                  ' // Set the focus in the listbox
                  SetFocus GetDlgItem(hwnd, %IDC_LBCOLSEL)
                  ' // Change the options of the current document if any
                  IF pSed.hEdit THEN
                     szPath = AfxGetWindowText(GetParent(pSed.hEdit))
                     IF LEN(szPath) THEN
                        CSED_SetScintillaOptions(pSed.hEdit, PATHNAME$(EXTN, szPath))
                     END IF
                  END IF
                  EXIT FUNCTION
               END IF

            CASE %IDCANCEL
               IF HI(WORD, wParam) = %BN_CLICKED THEN
                  SendMessage hwnd, %WM_CLOSE, 0, 0
                  EXIT FUNCTION
               END IF

           CASE %IDC_CBFONTS
               IF HI(WORD, wParam) = %CBN_SELCHANGE THEN   ' // Selection change
                  strFontName = ComboBox_GetLbText(GetDlgItem(hwnd, %IDC_CBFONTS), -1)
                  CSED_FillFontSizeCombo hwnd, strFontName
                  EXIT FUNCTION
               END IF

            CASE %IDC_CBFORECOLOR
               IF HI(WORD, wParam) = %CBN_SELCHANGE THEN   ' // Selection change
                  selColor = SendMessage(GetDlgItem(hwnd, %IDC_CBFORECOLOR), %CBCOL_GETSELCOLOR, 0, 0)
                  SendMessage(GetDlgItem(hwnd, %IDC_CBFORECOLOR), %CBCOL_SETUSERCOLOR, selColor, 0)
               END IF
               EXIT FUNCTION

            CASE %IDC_CBBACKCOLOR
               IF HI(WORD, wParam) = %CBN_SELCHANGE THEN   ' // Selection change
                  selColor = SendMessage(GetDlgItem(hwnd, %IDC_CBBACKCOLOR), %CBCOL_GETSELCOLOR, 0, 0)
                  SendMessage(GetDlgItem(hwnd, %IDC_CBBACKCOLOR), %CBCOL_SETUSERCOLOR, selColor, 0)
               END IF
               EXIT FUNCTION

            CASE %IDB_USERFORECOLOR
               IF HI(WORD, wParam) = %BN_CLICKED THEN
                  selColor = SendMessage(GetDlgItem(hwnd, %IDC_CBFORECOLOR), %CBCOL_GETUSERCOLOR, 0, 0)
                  userColor = CSED_ChooseColor(hwnd, selColor)
                  IF ISTRUE userColor THEN
                     SendMessage GetDlgItem(hwnd, %IDC_CBFORECOLOR), %CBCOL_SETUSERCOLOR, userColor, 0
                     InvalidateRect GetDlgItem(hwnd, %IDC_CBFORECOLOR), BYVAL %NULL, %TRUE
                     UpdateWIndow GetDlgItem(hwnd, %IDC_CBFORECOLOR)
                  END IF
                  EXIT FUNCTION
               END IF

            CASE %IDB_USERBACKCOLOR
               IF HI(WORD, wParam) = %BN_CLICKED THEN
                  selColor = SendMessage(GetDlgItem(hwnd, %IDC_CBBACKCOLOR), %CBCOL_GETUSERCOLOR, 0, 0)
                  userColor = CSED_ChooseColor(hwnd, selColor)
                  IF ISTRUE userColor THEN
                     SendMessage GetDlgItem(hwnd, %IDC_CBBACKCOLOR), %CBCOL_SETUSERCOLOR, userColor, 0
                     InvalidateRect GetDlgItem(hwnd, %IDC_CBBACKCOLOR), BYVAL %NULL, %TRUE
                     UpdateWIndow GetDlgItem(hwnd, %IDC_CBBACKCOLOR)
                  END IF
                  EXIT FUNCTION
               END IF

            CASE %IDC_LBCOLSEL   ' // Listbox control
               IF HI(WORD, wParam) = %LBN_DBLCLK OR _
                  HI(WORD, wParam) = %LBN_SELCHANGE THEN
                     curSel = ListBox_GetCursel(GetDlgItem(hwnd, %IDC_LBCOLSEL))
                     curSelStr = ListBox_GetText(GetDlgItem(hwnd, %IDC_LBCOLSEL), curSel)
                     CSED_ColorsAndFontsChangeSelection hwnd, curSelStr
                  EXIT FUNCTION
               END IF

            CASE %IDBO_COLORS_HELP
               IF HI(WORD, wParam) = %BN_CLICKED THEN
                  szPath = EXE.Path$ & "CSED.CHM"
                  szText = "Colors and Fonts"
                  IF ISFILE(szPath) THEN
                     LOCAL hlk AS HH_AKLINK
                     hlk.cbStruct     = SIZEOF(hlk)
                     hlk.pszKeywords  = VARPTR(szText)
                     hlk.fIndexOnFail = %TRUE
                     HtmlHelp hwnd, szPath, %HH_DISPLAY_TOPIC, %NULL
                     HtmlHelp hwnd, szPath, %HH_KEYWORD_LOOKUP, VARPTR(hlk)
                  END IF
                  EXIT FUNCTION
               END IF

         END SELECT

     CASE %WM_CLOSE
         ' // Maintains parent's zorder
         EnableWindow GetParent(hwnd), %TRUE

     CASE %WM_DESTROY
         ' // Close the main window
         PostQuitMessage 0
         EXIT FUNCTION

   END SELECT

   FUNCTION = DefWindowProc(hwnd, wMsg, wParam, lParam)

END FUNCTION
' ========================================================================================
