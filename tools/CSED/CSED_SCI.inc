' ########################################################################################
' CSED Editor
' File: CSED_SCI.INC
' Contents: Miscellaneous Scintilla related procedures
' Copyright (c) 2012 José Roca
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

' ========================================================================================
' PB Keywords
' Note: Added "|" as a dummy character so the first keyword can begin with an space.
' ========================================================================================
SUB CSED_LoadPBKeywords (BYVAL hwnd AS DWORD)

   LOCAL strFileName AS STRING
   LOCAL FileNumber AS LONG
   LOCAL strWord AS STRING
   LOCAL pSb AS IStringBuilderA

   pSb = CLASS "StringBuilderA"
   IF ISNOTHING(pSb) THEN EXIT SUB

   strFileName = EXE.PATH$ & "Keywords\CSED_PB_KEYWORDS.TXT"
   IF ISFALSE ISFILE(strFileName) THEN
      MessageBox(hwnd, " " & strFileName & " not found ", "CSED Editor", %MB_ICONERROR OR %MB_APPLMODAL)
      EXIT SUB
   END IF

   pSb.Add("| ")

   FileNumber = FREEFILE
   OPEN strFileName FOR INPUT AS FileNumber
   WHILE NOT EOF(FileNumber)
      LINE INPUT #FileNumber, strWord
      IF LEN(strWord) > 0 AND INSTR(strWord, "'") = 0 THEN
         pSb.Add(strWord & " ")
      END IF
   WEND
   CLOSE

   pSed.PBKeyWords = pSb.String
   pSb = NOTHING

END SUB
' ========================================================================================

' ========================================================================================
' RC keywords
' ========================================================================================
FUNCTION CSED_LoadCPPKeywords (BYVAL hwnd AS DWORD) AS STRING

   LOCAL strFileName AS STRING
   LOCAL FileNumber AS LONG
   LOCAL strWord AS STRING
   LOCAL pSb AS IStringBuilderA

   pSb = CLASS "StringBuilderA"
   IF ISNOTHING(pSb) THEN EXIT FUNCTION

   ' // C++ keywords
   strFileName = EXE.PATH$ & "Keywords\CSED_CPP_KEYWORDS.TXT"
   IF ISFALSE ISFILE(strFileName) THEN
      MessageBox(0, " " & strFileName & " not found ", "CSED Editor", %MB_ICONERROR OR %MB_APPLMODAL)
   ELSE
      FileNumber = FREEFILE
      OPEN strFileName FOR INPUT AS FileNumber
      WHILE NOT EOF(FileNumber)
         LINE INPUT #FileNumber, strWord
         IF LEN(strWord) > 0 AND INSTR(strWord, "'") = 0 THEN
            pSb.Add(strWord & " ")
         END IF
      WEND
      CLOSE
   END IF

   ' // Resource compiler keywords
   strFileName = EXE.PATH$ & "Keywords\CSED_RC_KEYWORDS.TXT"
   IF ISFALSE ISFILE(strFileName) THEN
      MessageBox(0, " " & strFileName & " not found ", "CSED Editor", %MB_ICONERROR OR %MB_APPLMODAL)
   ELSE
      FileNumber = FREEFILE
      OPEN strFileName FOR INPUT AS FileNumber
      WHILE NOT EOF(FileNumber)
         LINE INPUT #FileNumber, strWord
         IF LEN(strWord) > 0 AND INSTR(strWord, "'") = 0 THEN
            pSb.Add(strWord & " ")
         END IF
      WEND
      CLOSE
   END IF

   ' // JavaScript keywords
   strFileName = EXE.PATH$ & "Keywords\CSED_JS_KEYWORDS.TXT"
   IF ISFALSE ISFILE(strFileName) THEN
      MessageBox(0, " " & strFileName & " not found ", "CSED Editor", %MB_ICONERROR OR %MB_APPLMODAL)
   ELSE
      FileNumber = FREEFILE
      OPEN strFileName FOR INPUT AS FileNumber
      WHILE NOT EOF(FileNumber)
         LINE INPUT #FileNumber, strWord
         IF LEN(strWord) > 0 AND INSTR(strWord, "'") = 0 THEN
            pSb.Add(strWord & " ")
         END IF
      WEND
      CLOSE
   END IF

   ' // IDL keywords
   strFileName = EXE.PATH$ & "Keywords\CSED_IDL_KEYWORDS.TXT"
   IF ISFALSE ISFILE(strFileName) THEN
      MessageBox(0, " " & strFileName & " not found ", "CSED Editor", %MB_ICONERROR OR %MB_APPLMODAL)
   ELSE
      FileNumber = FREEFILE
      OPEN strFileName FOR INPUT AS FileNumber
      WHILE NOT EOF(FileNumber)
         LINE INPUT #FileNumber, strWord
         IF LEN(strWord) > 0 AND INSTR(strWord, "'") = 0 THEN
            pSb.Add(strWord & " ")
         END IF
      WEND
      CLOSE
   END IF

   ' // Java keywords
   strFileName = EXE.PATH$ & "Keywords\CSED_JAVA_KEYWORDS.TXT"
   IF ISFALSE ISFILE(strFileName) THEN
      MessageBox(0, " " & strFileName & " not found ", "CSED Editor", %MB_ICONERROR OR %MB_APPLMODAL)
   ELSE
      FileNumber = FREEFILE
      OPEN strFileName FOR INPUT AS FileNumber
      WHILE NOT EOF(FileNumber)
         LINE INPUT #FileNumber, strWord
         IF LEN(strWord) > 0 AND INSTR(strWord, "'") = 0 THEN
            pSb.Add(strWord & " ")
         END IF
      WEND
      CLOSE
   END IF

   FUNCTION = pSb.String
   pSb = NOTHING

END FUNCTION
' ========================================================================================

' ========================================================================================
' Set the charsets
' ========================================================================================
FUNCTION CSED_CharsetID (BYVAL strCharsetName AS STRING) AS LONG

   SELECT CASE strCharsetName
      CASE "Default"       : FUNCTION = %SC_CHARSET_DEFAULT
      CASE "Ansi"          : FUNCTION = %SC_CHARSET_ANSI
      CASE "Arabic"        : FUNCTION = %SC_CHARSET_ARABIC
      CASE "Baltic"        : FUNCTION = %SC_CHARSET_BALTIC
      CASE "Chinese Big 5" : FUNCTION = %SC_CHARSET_CHINESEBIG5
      CASE "East Europe"   : FUNCTION = %SC_CHARSET_EASTEUROPE
      CASE "GB 2312"       : FUNCTION = %SC_CHARSET_GB2312
      CASE "Greek"         : FUNCTION = %SC_CHARSET_GREEK
      CASE "Hangul"        : FUNCTION = %SC_CHARSET_HANGUL
      CASE "Hebrew"        : FUNCTION = %SC_CHARSET_HEBREW
      CASE "Johab"         : FUNCTION = %SC_CHARSET_JOHAB
      CASE "Mac"           : FUNCTION = %SC_CHARSET_MAC
      CASE "OEM"           : FUNCTION = %SC_CHARSET_OEM
      CASE "Russian"       : FUNCTION = %SC_CHARSET_RUSSIAN
      CASE "Shiftjis"      : FUNCTION = %SC_CHARSET_SHIFTJIS
      CASE "Symbol"        : FUNCTION = %SC_CHARSET_SYMBOL
      CASE "Thai"          : FUNCTION = %SC_CHARSET_THAI
      CASE "Turkish"       : FUNCTION = %SC_CHARSET_TURKISH
      CASE "Vietnamese"    : FUNCTION = %SC_CHARSET_VIETNAMESE
   END SELECT

END FUNCTION
' ========================================================================================

' ========================================================================================
' Set Scintilla Edit Control's options
' ========================================================================================
SUB CSED_SetScintillaOptions (BYVAL hSci AS DWORD, BYVAL strFileExt AS STRING)

   LOCAL bitsNeeded AS LONG   ' // Number of bits needed by the lexer for styling

   ' // Get direct pointer for faster access
   LOCAL pSci AS DWORD   ' // Scintilla's direct pointer
   pSci = SCI_GetDirectPointer(hSci)
   IF pSci = 0 THEN EXIT SUB

   ' // If Vista/Windows 7, use Direct Write for higher quality antialiased drawing
   IF AfxGetWindowsVersion => 6 THEN
      SCIP_SetBufferedDraw(pSci, 0)
      SCIP_SetTechnology(pSci, %SC_TECHNOLOGY_DIRECTWRITE)
   END IF

   ' // Set the default style
   SCIP_StyleSetFont(pSci, %STYLE_DEFAULT, pSed.DefaultFontName)
   SCIP_StyleSetSize(pSci, %STYLE_DEFAULT, pSed.DefaultFontSize)
   SCIP_StyleSetCharacterSet(pSci, %STYLE_DEFAULT, CSED_CharsetID(pSed.DefaultFontCharset))
   SCIP_StyleSetBold(pSci, %STYLE_DEFAULT, pSed.DefaultFontBold)
   SCIP_StyleSetItalic(pSci, %STYLE_DEFAULT, pSed.DefaultFontItalic)
   SCIP_StyleSetUnderline(pSci, %STYLE_DEFAULT, pSed.DefaultFontUnderline)
   SCIP_StyleSetFore(pSci, %STYLE_DEFAULT, pSed.DefaultForeColor)
   SCIP_StyleSetBack(pSci, %STYLE_DEFAULT, pSed.DefaultBackColor)
   IF strFileExt = ".BAS" OR strFileExt = ".INC" OR strFileExt = ".BI" OR _
      strFileExt = ".INL" OR strFileExt = ".PBTPL" THEN
      SCIP_StyleSetCase(pSci, %STYLE_DEFAULT, pSed.DefaultCase)
   END IF

   ' // Set all the other styles to the default
   SCIP_StyleClearAll(pSci)

   ' // Set the style for the line numbers
   IF pSed.UseAlwaysDefaultFont THEN
      SCIP_StyleSetFont(pSci, %STYLE_LINENUMBER, pSed.DefaultFontName)
   ELSE
      SCIP_StyleSetFont(pSci, %STYLE_LINENUMBER, pSed.LineNumberFontName)
   END IF
   IF pSed.UseAlwaysDefaultFontSize THEN
      SCIP_StyleSetSize(pSci, %STYLE_LINENUMBER, pSed.DefaultFontSize)
   ELSE
      SCIP_StyleSetSize(pSci, %STYLE_LINENUMBER, pSed.LineNumberFontSize)
   END IF
   SCIP_StyleSetCharacterSet(pSci, %STYLE_LINENUMBER, CSED_CharsetID(pSed.LineNumberFontCharset))
   SCIP_StyleSetBold(pSci, %STYLE_LINENUMBER, pSed.LineNumberFontBold)
   SCIP_StyleSetItalic(pSci, %STYLE_LINENUMBER, pSed.LineNumberFontItalic)
   SCIP_StyleSetUnderline(pSci, %STYLE_LINENUMBER, pSed.LineNumberFontUnderline)
   SCIP_StyleSetFore(pSci, %STYLE_LINENUMBER, pSed.LineNumberForeColor)
   SCIP_StyleSetBack(pSci, %STYLE_LINENUMBER, pSed.LineNumberBackColor)

   strFileExt = UCASE$(strFileExt)

   ' =======================================================================================
   ' // PowerBASIC and VB specific
   ' =======================================================================================
   IF strFileExt = ".BAS" OR strFileExt = ".INC" OR strFileExt = ".BI" OR _
      strFileExt = ".INL" OR strFileExt = ".PBTPL" THEN

      ' // Set the lexer
      'IF FoldOpt.FoldingLevel = 1 THEN
      '   SCIP_SetLexer(pSci, %SCLEX_POWERBASIC2)
      'ELSE
      '   SCIP_SetLexer(pSci, %SCLEX_POWERBASIC)
      'END IF
      ' // Use the VB lexer
      SCIP_SetLexer(pSci, %SCLEX_VB)
      ' // Set bit styles
      bitsNeeded = SCIP_GetStyleBits(pSci)
      SCIP_SetStyleBits(pSci, bitsNeeded)
      ' // Set PB Keywords
      SCIP_SetKeywords(pSci, 0, pSed.PBKeywords)

      IF pSed.SyntaxHighlighting = %BST_CHECKED THEN

         ' // Set the Comments style
         IF pSed.UseAlwaysDefaultFont THEN
            SCIP_StyleSetFont(pSci, %SCE_B_COMMENT, pSed.DefaultFontName)
            SCIP_StyleSetCharacterSet(pSci, %SCE_B_COMMENT, CSED_CharsetID(pSed.DefaultFontCharset))
            SCIP_StyleSetBold(pSci, %SCE_B_COMMENT, pSed.DefaultFontBold)
            SCIP_StyleSetItalic(pSci, %SCE_B_COMMENT, pSed.DefaultFontItalic)
            SCIP_StyleSetUnderline(pSci, %SCE_B_COMMENT, pSed.DefaultFontUnderline)
         ELSE
            SCIP_StyleSetFont(pSci, %SCE_B_COMMENT, pSed.CommentFontName)
            SCIP_StyleSetCharacterSet(pSci, %SCE_B_COMMENT, CSED_CharsetID(pSed.CommentFontCharset))
            SCIP_StyleSetBold(pSci, %SCE_B_COMMENT, pSed.CommentFontBold)
            SCIP_StyleSetItalic(pSci, %SCE_B_COMMENT, pSed.CommentFontItalic)
            SCIP_StyleSetUnderline(pSci, %SCE_B_COMMENT, pSed.CommentFontUnderline)
         END IF
         SCIP_StyleSetFore(pSci, %SCE_B_COMMENT, pSed.CommentForeColor)
         SCIP_StyleSetCase(pSci, %SCE_B_COMMENT, pSed.DefaultCase)
         IF pSed.UseAlwaysDefaultFontSize THEN
            SCIP_StyleSetSize(pSci, %SCE_B_COMMENT, pSed.DefaultFontSize)
         ELSE
            SCIP_StyleSetSize(pSci, %SCE_B_COMMENT, pSed.CommentFontSize)
         END IF
         IF pSed.UseAlwaysDefaultBackColor THEN
            SCIP_StyleSetBack(pSci, %SCE_B_COMMENT, pSed.DefaultBackColor)
         ELSE
            SCIP_StyleSetBack(pSci, %SCE_B_COMMENT, pSed.CommentBackColor)
         END IF

         ' // Set the Keywords style
         IF pSed.UseAlwaysDefaultFont THEN
            SCIP_StyleSetFont(pSci, %SCE_B_KEYWORD, pSed.DefaultFontName)
            SCIP_StyleSetCharacterSet(pSci, %SCE_B_KEYWORD, CSED_CharsetID(pSed.DefaultFontCharset))
            SCIP_StyleSetBold(pSci, %SCE_B_KEYWORD, pSed.DefaultFontBold)
            SCIP_StyleSetItalic(pSci, %SCE_B_KEYWORD, pSed.DefaultFontItalic)
            SCIP_StyleSetUnderline(pSci, %SCE_B_KEYWORD, pSed.DefaultFontUnderline)
         ELSE
            SCIP_StyleSetFont(pSci, %SCE_B_KEYWORD, pSed.KeywordFontName)
            SCIP_StyleSetCharacterSet(pSci, %SCE_B_KEYWORD, CSED_CharsetID(pSed.KeywordFontCharset))
            SCIP_StyleSetBold(pSci, %SCE_B_KEYWORD, pSed.KeywordFontBold)
            SCIP_StyleSetItalic(pSci, %SCE_B_KEYWORD, pSed.KeywordFontItalic)
            SCIP_StyleSetUnderline(pSci, %SCE_B_KEYWORD, pSed.KeywordFontUnderline)
         END IF
         SCIP_StyleSetFore(pSci, %SCE_B_KEYWORD, pSed.KeywordForeColor)
         SCIP_StyleSetCase(pSci, %SCE_B_KEYWORD, pSed.KeywordCase)
         IF pSed.UseAlwaysDefaultFontSize THEN
            SCIP_StyleSetSize(pSci, %SCE_B_KEYWORD, pSed.DefaultFontSize)
         ELSE
            SCIP_StyleSetSize(pSci, %SCE_B_KEYWORD, pSed.KeywordFontSize)
         END IF
         IF pSed.UseAlwaysDefaultBackColor THEN
            SCIP_StyleSetBack(pSci, %SCE_B_KEYWORD, pSed.DefaultBackColor)
         ELSE
            SCIP_StyleSetBack(pSci, %SCE_B_KEYWORD, pSed.KeywordBackColor)
         END IF

         ' // Set the Constants style
         IF pSed.UseAlwaysDefaultFont THEN
            SCIP_StyleSetFont(pSci, %SCE_B_CONSTANT, pSed.DefaultFontName)
            SCIP_StyleSetCharacterSet(pSci, %SCE_B_CONSTANT, CSED_CharsetID(pSed.DefaultFontCharset))
            SCIP_StyleSetBold(pSci, %SCE_B_CONSTANT, pSed.DefaultFontBold)
            SCIP_StyleSetItalic(pSci, %SCE_B_CONSTANT, pSed.DefaultFontItalic)
            SCIP_StyleSetUnderline(pSci, %SCE_B_CONSTANT, pSed.DefaultFontUnderline)
         ELSE
            SCIP_StyleSetFont(pSci, %SCE_B_CONSTANT, pSed.ConstantFontName)
            SCIP_StyleSetCharacterSet(pSci, %SCE_B_CONSTANT, CSED_CharsetID(pSed.ConstantFontCharset))
            SCIP_StyleSetBold(pSci, %SCE_B_CONSTANT, pSed.ConstantFontBold)
            SCIP_StyleSetItalic(pSci, %SCE_B_CONSTANT, pSed.ConstantFontItalic)
            SCIP_StyleSetUnderline(pSci, %SCE_B_CONSTANT, pSed.ConstantFontUnderline)
         END IF
         SCIP_StyleSetFore(pSci, %SCE_B_CONSTANT, pSed.ConstantForeColor)
         SCIP_StyleSetCase(pSci, %SCE_B_CONSTANT, pSed.DefaultCase)
         IF pSed.UseAlwaysDefaultFontSize THEN
            SCIP_StyleSetSize(pSci, %SCE_B_CONSTANT, pSed.DefaultFontSize)
         ELSE
            SCIP_StyleSetSize(pSci, %SCE_B_CONSTANT, pSed.KeywordFontSize)
         END IF
         IF pSed.UseAlwaysDefaultBackColor THEN
            SCIP_StyleSetBack(pSci, %SCE_B_CONSTANT, pSed.DefaultBackColor)
         ELSE
            SCIP_StyleSetBack(pSci, %SCE_B_CONSTANT, pSed.ConstantBackColor)
         END IF

         ' // Set the Identifiers style
         IF pSed.UseAlwaysDefaultFont THEN
            SCIP_StyleSetFont(pSci, %SCE_B_IDENTIFIER, pSed.DefaultFontName)
            SCIP_StyleSetCharacterSet(pSci, %SCE_B_IDENTIFIER, CSED_CharsetID(pSed.DefaultFontCharset))
            SCIP_StyleSetBold(pSci, %SCE_B_IDENTIFIER, pSed.DefaultFontBold)
            SCIP_StyleSetItalic(pSci, %SCE_B_IDENTIFIER, pSed.DefaultFontItalic)
            SCIP_StyleSetUnderline(pSci, %SCE_B_IDENTIFIER, pSed.DefaultFontUnderline)
         ELSE
            SCIP_StyleSetFont(pSci, %SCE_B_IDENTIFIER, pSed.IdentifierFontName)
            SCIP_StyleSetCharacterSet(pSci, %SCE_B_IDENTIFIER, CSED_CharsetID(pSed.IdentifierFontCharset))
            SCIP_StyleSetBold(pSci, %SCE_B_IDENTIFIER, pSed.IdentifierFontBold)
            SCIP_StyleSetItalic(pSci, %SCE_B_IDENTIFIER, pSed.IdentifierFontItalic)
            SCIP_StyleSetUnderline(pSci, %SCE_B_IDENTIFIER, pSed.IdentifierFontUnderline)
         END IF
         SCIP_StyleSetFore(pSci, %SCE_B_IDENTIFIER, pSed.IdentifierForeColor)
         SCIP_StyleSetCase(pSci, %SCE_B_IDENTIFIER, pSed.DefaultCase)
         IF pSed.UseAlwaysDefaultFontSize THEN
            SCIP_StyleSetSize(pSci, %SCE_B_IDENTIFIER, pSed.DefaultFontSize)
         ELSE
            SCIP_StyleSetSize(pSci, %SCE_B_IDENTIFIER, pSed.IdentifierFontSize)
         END IF
         IF pSed.UseAlwaysDefaultBackColor THEN
            SCIP_StyleSetBack(pSci, %SCE_B_IDENTIFIER, pSed.DefaultBackColor)
         ELSE
            SCIP_StyleSetBack(pSci, %SCE_B_IDENTIFIER, pSed.IdentifierBackColor)
         END IF

         ' // Set the Numbers style
         IF pSed.UseAlwaysDefaultFont THEN
            SCIP_StyleSetFont(pSci, %SCE_B_NUMBER, pSed.DefaultFontName)
            SCIP_StyleSetCharacterSet(pSci, %SCE_B_NUMBER, CSED_CharsetID(pSed.DefaultFontCharset))
            SCIP_StyleSetBold(pSci, %SCE_B_NUMBER, pSed.DefaultFontBold)
            SCIP_StyleSetItalic(pSci, %SCE_B_NUMBER, pSed.DefaultFontItalic)
            SCIP_StyleSetUnderline(pSci, %SCE_B_NUMBER, pSed.DefaultFontUnderline)
         ELSE
            SCIP_StyleSetFont(pSci, %SCE_B_NUMBER, pSed.NumberFontName)
            SCIP_StyleSetCharacterSet(pSci, %SCE_B_NUMBER, CSED_CharsetID(pSed.NumberFontCharset))
            SCIP_StyleSetBold(pSci, %SCE_B_NUMBER, pSed.NumberFontBold)
            SCIP_StyleSetItalic(pSci, %SCE_B_NUMBER, pSed.NumberFontItalic)
            SCIP_StyleSetUnderline(pSci, %SCE_B_NUMBER, pSed.NumberFontUnderline)
         END IF
         SCIP_StyleSetFore(pSci, %SCE_B_NUMBER, pSed.NumberForeColor)
         SCIP_StyleSetCase(pSci, %SCE_B_NUMBER, pSed.DefaultCase)
         IF pSed.UseAlwaysDefaultFontSize THEN
            SCIP_StyleSetSize(pSci, %SCE_B_NUMBER, pSed.DefaultFontSize)
         ELSE
            SCIP_StyleSetSize(pSci, %SCE_B_NUMBER, pSed.NumberFontSize)
         END IF
         IF pSed.UseAlwaysDefaultBackColor THEN
            SCIP_StyleSetBack(pSci, %SCE_B_NUMBER, pSed.NumberBackColor)
         ELSE
            SCIP_StyleSetBack(pSci, %SCE_B_NUMBER, pSed.NumberBackColor)
         END IF

         ' // Set the Operators style
         IF pSed.UseAlwaysDefaultFont THEN
            SCIP_StyleSetFont(pSci, %SCE_B_OPERATOR, pSed.DefaultFontName)
            SCIP_StyleSetCharacterSet(pSci, %SCE_B_OPERATOR, CSED_CharsetID(pSed.DefaultFontCharset))
            SCIP_StyleSetBold(pSci, %SCE_B_OPERATOR, pSed.DefaultFontBold)
            SCIP_StyleSetItalic(pSci, %SCE_B_OPERATOR, pSed.DefaultFontItalic)
            SCIP_StyleSetUnderline(pSci, %SCE_B_OPERATOR, pSed.DefaultFontUnderline)
         ELSE
            SCIP_StyleSetFont(pSci, %SCE_B_OPERATOR, pSed.OperatorFontName)
            SCIP_StyleSetCharacterSet(pSci, %SCE_B_OPERATOR, CSED_CharsetID(pSed.OperatorFontCharset))
            SCIP_StyleSetBold(pSci, %SCE_B_OPERATOR, pSed.OperatorFontBold)
            SCIP_StyleSetItalic(pSci, %SCE_B_OPERATOR, pSed.OperatorFontItalic)
            SCIP_StyleSetUnderline(pSci, %SCE_B_OPERATOR, pSed.OperatorFontUnderline)
         END IF
         SCIP_StyleSetFore(pSci, %SCE_B_OPERATOR, pSed.OperatorForeColor)
         SCIP_StyleSetCase(pSci, %SCE_B_OPERATOR, pSed.DefaultCase)
         IF pSed.UseAlwaysDefaultFontSize THEN
            SCIP_StyleSetSize(pSci, %SCE_B_OPERATOR, pSed.DefaultFontSize)
         ELSE
            SCIP_StyleSetSize(pSci, %SCE_B_OPERATOR, pSed.OperatorFontSize)
         END IF
         IF pSed.UseAlwaysDefaultBackColor THEN
            SCIP_StyleSetBack(pSci, %SCE_B_OPERATOR, pSed.OperatorBackColor)
         ELSE
            SCIP_StyleSetBack(pSci, %SCE_B_OPERATOR, pSed.OperatorBackColor)
         END IF

         ' // Set the Preprocessor style
         IF pSed.UseAlwaysDefaultFont THEN
            SCIP_StyleSetFont(pSci, %SCE_B_PREPROCESSOR, pSed.DefaultFontName)
            SCIP_StyleSetCharacterSet(pSci, %SCE_B_PREPROCESSOR, CSED_CharsetID(pSed.DefaultFontCharset))
            SCIP_StyleSetBold(pSci, %SCE_B_PREPROCESSOR, pSed.DefaultFontBold)
            SCIP_StyleSetItalic(pSci, %SCE_B_PREPROCESSOR, pSed.DefaultFontItalic)
            SCIP_StyleSetUnderline(pSci, %SCE_B_PREPROCESSOR, pSed.DefaultFontUnderline)
         ELSE
            SCIP_StyleSetFont(pSci, %SCE_B_PREPROCESSOR, pSed.PreprocessorFontName)
            SCIP_StyleSetCharacterSet(pSci, %SCE_B_PREPROCESSOR, CSED_CharsetID(pSed.PreprocessorFontCharset))
            SCIP_StyleSetBold(pSci, %SCE_B_PREPROCESSOR, pSed.PreprocessorFontBold)
            SCIP_StyleSetItalic(pSci, %SCE_B_PREPROCESSOR, pSed.PreprocessorFontItalic)
            SCIP_StyleSetUnderline(pSci, %SCE_B_PREPROCESSOR, pSed.PreprocessorFontUnderline)
         END IF
         SCIP_StyleSetFore(pSci, %SCE_B_PREPROCESSOR, pSed.PreprocessorForeColor)
         SCIP_StyleSetCase(pSci, %SCE_B_PREPROCESSOR, pSed.DefaultCase)
         IF pSed.UseAlwaysDefaultFontSize THEN
            SCIP_StyleSetSize(pSci, %SCE_B_PREPROCESSOR, pSed.DefaultFontSize)
         ELSE
            SCIP_StyleSetSize(pSci, %SCE_B_PREPROCESSOR, pSed.PreprocessorFontSize)
         END IF
         IF pSed.UseAlwaysDefaultBackColor THEN
            SCIP_StyleSetBack(pSci, %SCE_B_PREPROCESSOR, pSed.PreprocessorBackColor)
         ELSE
            SCIP_StyleSetBack(pSci, %SCE_B_PREPROCESSOR, pSed.PreprocessorBackColor)
         END IF

         ' // Set the Strings style
         IF pSed.UseAlwaysDefaultFont THEN
            SCIP_StyleSetFont(pSci, %SCE_B_STRING, pSed.DefaultFontName)
            SCIP_StyleSetCharacterSet(pSci, %SCE_B_STRING, CSED_CharsetID(pSed.DefaultFontCharset))
            SCIP_StyleSetBold(pSci, %SCE_B_STRING, pSed.DefaultFontBold)
            SCIP_StyleSetItalic(pSci, %SCE_B_STRING, pSed.DefaultFontItalic)
            SCIP_StyleSetUnderline(pSci, %SCE_B_STRING, pSed.DefaultFontUnderline)
         ELSE
            SCIP_StyleSetFont(pSci, %SCE_B_STRING, pSed.StringFontName)
            SCIP_StyleSetCharacterSet(pSci, %SCE_B_STRING, CSED_CharsetID(pSed.StringFontCharset))
            SCIP_StyleSetBold(pSci, %SCE_B_STRING, pSed.StringFontBold)
            SCIP_StyleSetItalic(pSci, %SCE_B_STRING, pSed.StringFontItalic)
            SCIP_StyleSetUnderline(pSci, %SCE_B_STRING, pSed.StringFontUnderline)
         END IF
         SCIP_StyleSetFore(pSci, %SCE_B_STRING, pSed.StringForeColor)
         SCIP_StyleSetCase(pSci, %SCE_B_STRING, pSed.DefaultCase)
         IF pSed.UseAlwaysDefaultFontSize THEN
            SCIP_StyleSetSize(pSci, %SCE_B_STRING, pSed.DefaultFontSize)
         ELSE
            SCIP_StyleSetSize(pSci, %SCE_B_STRING, pSed.StringFontSize)
         END IF
         IF pSed.UseAlwaysDefaultBackColor THEN
            SCIP_StyleSetBack(pSci, %SCE_B_STRING, pSed.StringBackColor)
         ELSE
            SCIP_StyleSetBack(pSci, %SCE_B_STRING, pSed.StringBackColor)
         END IF

         IF pSed.FoldLevel THEN
            ' // Enable folding of the procedures and functions
            SCIP_SetProperty(pSci, "fold", "1")
         ELSE
            ' // Disable folding
            SCIP_SetProperty(pSci, "fold", "0")
         END IF

      END IF

   END IF
   ' =======================================================================================

   ' =======================================================================================
   ' HTML/XML specific
   ' =======================================================================================
   IF strFileExt = ".HTML" OR strFileExt = ".HTM" OR strFileExt = ".SHTML" OR strFileExt = ".XML" OR _
      strFileExt = ".XSL" OR strFileExt = ".XSD" THEN

      ' // Set the lexer (no keywords, all are known)
      SCIP_SetLexer(pSci, %SCLEX_HTML)
      ' // Set bit styles
      bitsNeeded = SCIP_GetStyleBits(pSci)
      SCIP_SetStyleBits(pSci, bitsNeeded)

      ' // Set the styles
      IF pSed.SyntaxHighlighting = %BST_CHECKED THEN
         SCIP_StyleSetBold(pSci, %SCE_H_TAG, %TRUE)
         SCIP_StyleSetFore(pSci, %SCE_H_TAG, RGB(&H0000FF))
         SCIP_StyleSetFore(pSci, %SCE_H_TAGUNKNOWN, RGB(&HFF0000))
         SCIP_StyleSetFore(pSci, %SCE_H_ATTRIBUTE, RGB(&H008080))
         SCIP_StyleSetFore(pSci, %SCE_H_ATTRIBUTEUNKNOWN, RGB(&HFF0000))
         SCIP_StyleSetFore(pSci, %SCE_H_NUMBER, RGB(&H800080))
         SCIP_StyleSetFore(pSci, %SCE_H_DOUBLESTRING, RGB(&HFF00EE))
         SCIP_StyleSetFore(pSci, %SCE_H_SINGLESTRING, RGB(&HFF00EE))
         SCIP_StyleSetFore(pSci, %SCE_H_OTHER, RGB(&H800080))
         SCIP_StyleSetFore(pSci, %SCE_H_COMMENT, RGB(&H008000))
         SCIP_StyleSetItalic(pSci, %SCE_H_COMMENT, %TRUE)
         SCIP_StyleSetFore(pSci, %SCE_H_ENTITY, RGB(&H800080))
         SCIP_StyleSetFore(pSci, %SCE_H_TAGEND, RGB(&H0000FF))
         SCIP_StyleSetFore(pSci, %SCE_H_XMLSTART, RGB(&H0000FF))   ' // <?
         SCIP_StyleSetFore(pSci, %SCE_H_XMLEND, RGB(&H0000FF))   ' // ?>
         SCIP_StyleSetFore(pSci, %SCE_H_SCRIPT, RGB(&H0000FF))   ' // <script
         SCIP_StyleSetFore(pSci, %SCE_H_ASP, RGB(&H4F4F00))   '  // <% ... %>
         SCIP_StyleSetBack(pSci, %SCE_H_ASP, RGB(&HFFFF00))   '  // <% ... %>
         SCIP_StyleSetFore(pSci, %SCE_H_ASPAT, RGB(&H4F4F00))   '  // <%@ ... %>
         SCIP_StyleSetBack(pSci, %SCE_H_ASPAT, RGB(&H4F4F00))   '  // <%@ ... %>
         SCIP_StyleSetFore(pSci, %SCE_HB_DEFAULT, RGB(&H000000))
         SCIP_StyleSetFore(pSci, %SCE_HB_COMMENTLINE, RGB(&H008000))
         SCIP_StyleSetFore(pSci, %SCE_HB_NUMBER, RGB(&H008000))
         SCIP_StyleSetFore(pSci, %SCE_HB_WORD, RGB(&H0000FF))
         SCIP_StyleSetBold(pSci, %SCE_HB_WORD, %TRUE)
         SCIP_StyleSetFore(pSci, %SCE_HB_STRING, RGB(&HFF00EE))
         SCIP_StyleSetFore(pSci, %SCE_HB_IDENTIFIER, RGB(&H000000))
         SCIP_StyleSetFore(pSci, %SCE_HB_IDENTIFIER, RGB(&H000000))
         SCIP_StyleSetFore(pSci, %SCE_HBA_DEFAULT, RGB(&H000000))
         SCIP_StyleSetFore(pSci, %SCE_HBA_DEFAULT, RGB(&H008000))
         SCIP_StyleSetFore(pSci, %SCE_HBA_NUMBER, RGB(&H008080))
         SCIP_StyleSetFore(pSci, %SCE_HBA_WORD, RGB(&H0000FF))
         SCIP_StyleSetBold(pSci, %SCE_HBA_WORD, %TRUE)
         SCIP_StyleSetFore(pSci, %SCE_HBA_WORD, RGB(&H800080))
         SCIP_StyleSetFore(pSci, %SCE_HBA_IDENTIFIER, RGB(&H000000))
         SCIP_StyleSetFore(pSci, %SCE_HJ_START, RGB(&H808000))
         SCIP_StyleSetFore(pSci, %SCE_HJ_DEFAULT, RGB(&H000000))
         SCIP_StyleSetFore(pSci, %SCE_HJ_COMMENT, RGB(&H008000))
         SCIP_StyleSetFore(pSci, %SCE_HJ_COMMENTLINE, RGB(&H008000))
         SCIP_StyleSetFore(pSci, %SCE_HJ_COMMENTDOC, RGB(&H008000))
         SCIP_StyleSetFore(pSci, %SCE_HJ_NUMBER, RGB(&H008080))
         SCIP_StyleSetFore(pSci, %SCE_HJ_WORD, RGB(&H000000))
         SCIP_StyleSetFore(pSci, %SCE_HJ_KEYWORD, RGB(&H0000FF))
         SCIP_StyleSetFore(pSci, %SCE_HJ_DOUBLESTRING, RGB(&HFF00EE))
         SCIP_StyleSetFore(pSci, %SCE_HJ_SINGLESTRING, RGB(&HFF00EE))
         SCIP_StyleSetFore(pSci, %SCE_HJ_SYMBOLS, RGB(&H000000))
         SCIP_StyleSetFore(pSci, %SCE_HJ_SYMBOLS, RGB(&H808000))
         SCIP_StyleSetFore(pSci, %SCE_HJA_DEFAULT, RGB(&H000000))
         SCIP_StyleSetFore(pSci, %SCE_HJA_COMMENT, RGB(&H008000))
         SCIP_StyleSetFore(pSci, %SCE_HJA_COMMENTLINE, RGB(&H008000))
         SCIP_StyleSetFore(pSci, %SCE_HJA_COMMENTDOC, RGB(&H008000))
         SCIP_StyleSetFore(pSci, %SCE_HJA_NUMBER, RGB(&H008080))
         SCIP_StyleSetFore(pSci, %SCE_HJA_WORD, RGB(&H000000))
         SCIP_StyleSetFore(pSci, %SCE_HJA_KEYWORD, RGB(&H0000FF))
         SCIP_StyleSetFore(pSci, %SCE_HJA_DOUBLESTRING, RGB(&HFF00EE))
         SCIP_StyleSetFore(pSci, %SCE_HJA_SINGLESTRING, RGB(&HFF00EE))
         SCIP_StyleSetFore(pSci, %SCE_HJA_SYMBOLS, RGB(&H000000))

'         SCIP_StyleSetFore(pSci, %SCE_H_SGML_DEFAULT, RGB(&H000000))
'         SCIP_StyleSetFore(pSci, %SCE_H_SGML_COMMAND, RGB(&HFF0000))
'         SCIP_StyleSetFore(pSci, %SCE_H_SGML_1ST_PARAM, RGB(&H008080))
'         SCIP_StyleSetFore(pSci, %SCE_H_SGML_DOUBLESTRING, RGB(&HFF00EE))
'         SCIP_StyleSetFore(pSci, %SCE_H_SGML_SIMPLESTRING, RGB(&HFF00EE))
'         SCIP_StyleSetFore(pSci, %SCE_H_SGML_ERROR, RGB(&H800000))
'         SCIP_StyleSetFore(pSci, %SCE_H_SGML_SPECIAL, RGB(&H008080))
'         SCIP_StyleSetFore(pSci, %SCE_H_SGML_ENTITY, RGB(&H800080))
'         SCIP_StyleSetFore(pSci, %SCE_H_SGML_COMMENT, RGB(&H008000))
'         SCIP_StyleSetFore(pSci, %SCE_H_SGML_1ST_PARAM_COMMENT, RGB(&H008000))
'         SCIP_StyleSetFore(pSci, %SCE_H_SGML_BLOCK_DEFAULT, RGB(&H000000))

         IF strFileExt = ".HTML" OR strFileExt = ".HTM" THEN
            IF pSed.FoldLevel THEN
               ' // Enable folding of the procedures and functions
               SCIP_SetProperty(pSci, "fold", "1")
               SCIP_SetProperty(pSci, "fold.html", "1")
               SCIP_SetProperty(pSci, "fold.hypertext.comment", "1")
               SCIP_SetProperty(pSci, "fold.hypertext.heredoc", "1")
            ELSE
               ' // Disable folding
               SCIP_SetProperty(pSci, "fold", "0")
               SCIP_SetProperty(pSci, "fold.html", "0")
               SCIP_SetProperty(pSci, "fold.hypertext.comment", "0")
               SCIP_SetProperty(pSci, "fold.hypertext.heredoc", "0")
            END IF
         ELSE
            IF pSed.FoldLevel THEN
               ' // Enable folding of the procedures and functions
               SCIP_SetProperty(pSci, "fold", "1")
               SCIP_SetProperty(pSci, "fold.comment", "1")
               SCIP_SetProperty(pSci, "fold.preprocessor", "1")
               SCIP_SetProperty(pSci, "fold.compact", "1")
               SCIP_SetProperty(pSci, "fold.at.else", "1")
            ELSE
               ' // Disable folding
               SCIP_SetProperty(pSci, "fold", "0")
               SCIP_SetProperty(pSci, "fold.comment", "0")
               SCIP_SetProperty(pSci, "fold.preprocessor", "0")
               SCIP_SetProperty(pSci, "fold.compact", "0")
               SCIP_SetProperty(pSci, "fold.at.else", "0")
            END IF
         END IF

         ' //	For XML and HTML, setting this property to 1 will make tags match in a case
         ' //	sensitive way which is the expected behaviour for XML and XHTML.
         SCIP_SetProperty(pSci, "html.tags.case.sensitive", "0")

      END IF

   END IF

   ' =======================================================================================
   ' C/C++/C#/Java/IDL/JavaScript specific
   ' =======================================================================================
   IF strFileExt = ".C" OR strFileExt = ".CC" OR strFileExt = ".CPP" OR strFileExt = ".CXX" OR _
      strFileExt = ".H" OR strFileExt = ".HH"  OR strFileExt = ".HPP" OR strFileExt = ".HXX" OR _
      strFileExt = ".JAVA" OR strFileExt = ".JAD" OR strFileExt = ".JS" OR strFileExt = ".RC" OR _
      strFileExt = ".RC2" OR strFileExt = ".DLG" OR strFileExt = ".IDL" OR strFileExt = ".ODL" THEN

      ' // Set the lexer
      SCIP_SetLexer(pSci, %SCLEX_CPPNOCASE)
      ' // Set bit styles
      ' // Note: SCIP_GetStyleBits returns 7, but 8 are needed
      SCIP_SetStyleBits(pSci, 8)
      ' // Set keywords
      SCIP_SetKeywords(pSci, 0, CSED_LoadCPPKeywords(pSed.hwndMain))

      ' // Set the styles
      IF pSed.SyntaxHighlighting = %BST_CHECKED THEN

         SCIP_StyleSetFore(pSci, %SCE_C_DEFAULT, &H000000)
         SCIP_StyleSetFore(pSci, %SCE_C_PREPROCESSOR, &H0000FF)
         SCIP_StyleSetFore(pSci, %SCE_C_STRING, &H000096)
         SCIP_StyleSetFore(pSci, %SCE_C_OPERATOR, &HB0B0B0)
         SCIP_StyleSetFore(pSci, %SCE_C_NUMBER, &H800080)
         SCIP_StyleSetFore(pSci, %SCE_C_CHARACTER, &H00A0CD)
         SCIP_StyleSetFore(pSci, %SCE_C_COMMENT, &H969696)
         SCIP_StyleSetFore(pSci, %SCE_C_COMMENTLINE, &H969696)
         SCIP_StyleSetFore(pSci, %SCE_C_COMMENTDOC, &HE68C82)
         SCIP_StyleSetBold(pSci, %SCE_C_COMMENTDOC, %TRUE)
         SCIP_StyleSetFore(pSci, %SCE_C_COMMENTLINEDOC, &HE68C82)
         SCIP_StyleSetBold(pSci, %SCE_C_COMMENTLINEDOC, %TRUE)
         SCIP_StyleSetFore(pSci, %SCE_C_COMMENTDOCKEYWORD, &H828C00)
         SCIP_StyleSetFore(pSci, %SCE_C_COMMENTDOCKEYWORDERROR, &H00145A)
         SCIP_StyleSetFore(pSci, %SCE_C_REGEX, &HA01EA0)
         SCIP_StyleSetFore(pSci, %SCE_C_WORD, &HFF0000)
         SCIP_StyleSetBold(pSci, %SCE_C_WORD, %TRUE)

         IF pSed.FoldLevel THEN
            ' // Enable folding of the procedures and functions
            SCIP_SetProperty(pSci, "fold", "1")
         ELSE
            ' // Disable folding
            SCIP_SetProperty(pSci, "fold", "0")
         END IF

      END IF

   END IF
   ' =======================================================================================

   ' // Multiple selection
   SCIP_SetMultipleSelection(pSci, pSed.MultipleSelection)
   ' // Convert endigs when pasting
   SCIP_SetPasteConvertEndings(pSci, pSed.PasteConvertEndings)

   ' // Codetips
   SCIP_CallTipSetFore(pSci, pSed.CodetipForeColor)
   SCIP_CallTipSetBack(pSci, pSed.CodetipBackColor)

   ' // Caret
   SCIP_SetCaretFore(pSci, pSed.CaretForeColor)

   ' // Show caret line
   IF pSed.ShowCaretLine = %BST_CHECKED THEN
      SCIP_SetCaretLineVisible(pSci, %TRUE)
   ELSE
      SCIP_SetCaretLineVisible(pSci, %FALSE)
   END IF

   ' // Caret line color
   SCIP_SetCaretLineBack(pSci, pSed.CaretLineBackColor)

   ' // Selection
   SCIP_SetSelFore(pSci, %TRUE, pSed.SelectionForeColor)
   SCIP_SetSelBack(pSci, %TRUE, pSed.SelectionBackColor)

   ' // Tabs
   IF pSed.UseTabs = %BST_CHECKED THEN
      SCIP_SetUseTabs(pSci, %TRUE)
      CheckMenuItem pSed.hMenu, %IDM_USETABS, %MF_CHECKED
   ELSE
      SCIP_SetUseTabs(pSci, %FALSE)
      CheckMenuItem pSed.hMenu, %IDM_USETABS, %MF_UNCHECKED
   END IF
   SCIP_SetTabWidth(pSci, pSed.TabSize)

   ' // Auto indentation
   IF pSed.AutoIndent = %BST_CHECKED THEN
      CheckMenuItem pSed.hMenu, %IDM_AUTOINDENT, %MF_CHECKED
   ELSE
      CheckMenuItem pSed.hMenu, %IDM_AUTOINDENT, %MF_UNCHECKED
   END IF
   SCIP_SetIndent(pSci, pSed.IndentSize)

   ' // Indentation guides
   IF pSed.IndentGuides = %BST_CHECKED THEN
      SCIP_SetIndent(pSci, pSed.TabSize)
      CheckMenuItem pSed.hMenu, %IDM_SHOWINDENT, %MF_CHECKED
   ELSE
      SCIP_SetIndent(pSci, 0)
      CheckMenuItem pSed.hMenu, %IDM_SHOWINDENT, %MF_UNCHECKED
   END IF

   IF pSed.IndentGuides = %BST_CHECKED THEN
      SCIP_SetIndentationGuides(pSci, %TRUE)
   ELSE
      SCIP_SetIndentationGuides(pSci, %FALSE)
   END IF

   SCIP_StyleSetFore(pSci, %STYLE_INDENTGUIDE, pSed.IndentGuideForeColor)
   SCIP_StyleSetBack(pSci, %STYLE_INDENTGUIDE, pSed.IndentGuideBackColor)

   ' // Set edge column and mode
   IF pSed.EdgeColumn = %BST_CHECKED THEN
      SCIP_SetEdgeMode(pSci, %EDGE_LINE)
      CheckMenuItem pSed.hMenu, %IDM_SHOWEDGE, %MF_CHECKED
   ELSE
      SCIP_SetEdgeMode(pSci, %EDGE_NONE)
      CheckMenuItem pSed.hMenu, %IDM_SHOWEDGE, %MF_UNCHECKED
   END IF
   SCIP_SetEdgeColumn(pSci, pSed.EdgeWidth)
   SCIP_SetEdgeColor(pSci, pSed.EdgeForeColor)

   ' // Show white spaces as dots
   IF GetMenuState(pSed.hMenu, %IDM_SHOWSPACES, %MF_BYCOMMAND = %MF_CHECKED) THEN
      SCIP_SetViews(pSci, %SCWS_VISIBLEALWAYS)
      CheckMenuItem pSed.hMenu, %IDM_SHOWSPACES, %MF_CHECKED
   ELSE
      SCIP_SetViews(pSci, %SCWS_INVISIBLE)
      CheckMenuItem pSed.hMenu, %IDM_SHOWSPACES, %MF_UNCHECKED
   END IF

   ' // White space
   IF pSed.WhiteSpace = %BST_CHECKED THEN
      SCIP_SetViews(pSci, %SCWS_VISIBLEALWAYS)
      CheckMenuItem pSed.hMenu, %IDM_SHOWSPACES, %MF_CHECKED
   ELSE
      SCIP_SetViews(pSci, %SCWS_INVISIBLE)
      CheckMenuItem pSed.hMenu, %IDM_SHOWSPACES, %MF_UNCHECKED
   END IF
   SCIP_SetWhiteSpaceFore(pSci, %TRUE, pSed.WhitespaceForeColor)
   SCIP_SetWhiteSpaceBack(pSci, %TRUE, pSed.WhitespaceBackColor)

   ' // End of line
   IF pSed.EndOfLine = %BST_CHECKED THEN
      SCIP_SetViewEOL(pSci, %TRUE)
      CheckMenuItem pSed.hMenu, %IDM_SHOWEOL, %MF_CHECKED
   ELSE
      SCIP_SetViewEOL(pSci, %FALSE)
      CheckMenuItem pSed.hMenu, %IDM_SHOWEOL, %MF_UNCHECKED
   END IF

   ' // Magnification
   SCIP_SetZoom(pSci, pSed.Magnification)

   ' // Margin 0 for numbers
   SCIP_SetMarginTypeN(pSci, 0, %SC_MARGIN_NUMBER)
   SCIP_SetMarginSensitiveN(pSci, 0, 1)
   IF pSed.LineNumbers = %BST_CHECKED THEN
      SCIP_SetMarginWidthN(pSci, 0, pSed.LineNumbersWidth)
      CheckMenuItem psed.hMenu, %IDM_SHOWLINENUM, %MF_CHECKED
   ELSE
      SCIP_SetMarginWidthN(pSci, 0, 0)
      CheckMenuItem pSed.hMenu, %IDM_SHOWLINENUM, %MF_UNCHECKED
   END IF

   ' // Margin 1 for non-folding symbols
   SCIP_SetMarginTypeN(pSci, 1, %SC_MARGIN_SYMBOL)
   SCIP_SetMarginMaskN(pSci, 1, 1)
   SCIP_SetMarginSensitiveN(pSci, 1, 1)
   SCIP_SetMarginWidthN(pSci, 1, 16)

   SCIP_SetFoldMarginColor(pSci, 2, RGB(200,0,200))
   SCIP_SetFoldMarginHiColor(pSci, 2, RGB(100,0,100))

   ' // Margin 2 for folding symbols
   SCIP_SetMarginTypeN(pSci, 2, %SC_MARGIN_SYMBOL)
   SCIP_SetMarginMaskN(pSci, 2, %SC_MASK_FOLDERS)
   SCIP_SetMarginSensitiveN(pSci, 2, 1)
   IF pSed.Margin = %BST_CHECKED THEN
      SCIP_SetMarginWidthN(pSci, 2, pSed.MarginWidth)
      CheckMenuItem pSed.hMenu, %IDM_SHOWMARGIN, %MF_CHECKED
   ELSE
      SCIP_SetMarginWidthN(pSci, 2, 0)
      CheckMenuItem pSed.hMenu, %IDM_SHOWMARGIN, %MF_UNCHECKED
   END IF

   SELECT CASE pSed.FoldSymbol

      CASE 1

         ' // Initialize fold symbols for folding - Arrow (mimics MacIntosh)
         SCIP_MarkerDefine(pSci, %SC_MARKNUM_FOLDEROPEN, %SC_MARK_ARROWDOWN)
         SCIP_MarkerDefine(pSci, %SC_MARKNUM_FOLDER, %SC_MARK_ARROW)
         SCIP_MarkerDefine(pSci, %SC_MARKNUM_FOLDERSUB, %SC_MARK_EMPTY)
         SCIP_MarkerDefine(pSci, %SC_MARKNUM_FOLDERTAIL, %SC_MARK_EMPTY)
         SCIP_MarkerDefine(pSci, %SC_MARKNUM_FOLDEREND, %SC_MARK_EMPTY)
         SCIP_MarkerDefine(pSci, %SC_MARKNUM_FOLDEROPENMID, %SC_MARK_EMPTY)
         SCIP_MarkerDefine(pSci, %SC_MARKNUM_FOLDERMIDTAIL, %SC_MARK_EMPTY)

      CASE 2

         ' // Initialize fold symbols for folding - Plus/minus
         SCIP_MarkerDefine(pSci, %SC_MARKNUM_FOLDEROPEN, %SC_MARK_MINUS)
         SCIP_MarkerDefine(pSci, %SC_MARKNUM_FOLDER, %SC_MARK_PLUS)
         SCIP_MarkerDefine(pSci, %SC_MARKNUM_FOLDERSUB, %SC_MARK_EMPTY)
         SCIP_MarkerDefine(pSci, %SC_MARKNUM_FOLDERTAIL, %SC_MARK_EMPTY)
         SCIP_MarkerDefine(pSci, %SC_MARKNUM_FOLDEREND, %SC_MARK_EMPTY)
         SCIP_MarkerDefine(pSci, %SC_MARKNUM_FOLDEROPENMID, %SC_MARK_EMPTY)
         SCIP_MarkerDefine(pSci, %SC_MARKNUM_FOLDERMIDTAIL, %SC_MARK_EMPTY)

      CASE 3

         ' // Initialize fold symbols for folding - Circle
         SCIP_MarkerDefine(pSci, %SC_MARKNUM_FOLDEROPEN, %SC_MARK_CIRCLEMINUS)
         SCIP_MarkerDefine(pSci, %SC_MARKNUM_FOLDER, %SC_MARK_CIRCLEPLUS)
         SCIP_MarkerDefine(pSci, %SC_MARKNUM_FOLDERSUB, %SC_MARK_VLINE)
         SCIP_MarkerDefine(pSci, %SC_MARKNUM_FOLDERTAIL, %SC_MARK_LCORNERCURVE)
         SCIP_MarkerDefine(pSci, %SC_MARKNUM_FOLDEREND, %SC_MARK_CIRCLEPLUSCONNECTED)
         SCIP_MarkerDefine(pSci, %SC_MARKNUM_FOLDEROPENMID, %SC_MARK_CIRCLEMINUSCONNECTED)
         SCIP_MarkerDefine(pSci, %SC_MARKNUM_FOLDERMIDTAIL, %SC_MARK_TCORNERCURVE)

      CASE 4

         ' // Initialize fold symbols for folding - Box tree
         SCIP_MarkerDefine(pSci, %SC_MARKNUM_FOLDEROPEN, %SC_MARK_BOXMINUS)
         SCIP_MarkerDefine(pSci, %SC_MARKNUM_FOLDER, %SC_MARK_BOXPLUS)
         SCIP_MarkerDefine(pSci, %SC_MARKNUM_FOLDERSUB, %SC_MARK_VLINE)
         SCIP_MarkerDefine(pSci, %SC_MARKNUM_FOLDERTAIL, %SC_MARK_LCORNER)
         SCIP_MarkerDefine(pSci, %SC_MARKNUM_FOLDEREND, %SC_MARK_BOXPLUSCONNECTED)
         SCIP_MarkerDefine(pSci, %SC_MARKNUM_FOLDEROPENMID, %SC_MARK_BOXMINUSCONNECTED)
         SCIP_MarkerDefine(pSci, %SC_MARKNUM_FOLDERMIDTAIL, %SC_MARK_TCORNER)

   END SELECT

   ' // Draw line below if not expanded
   SCIP_SetFoldFlags(pSci, 16)

   ' // Fold margin colors.
   SCIP_SetFoldMarginColor(pSci, 2, pSed.FoldMarginForeColor)
   SCIP_SetFoldMarginColor(pSci, 2, pSed.FoldMarginBackColor)

   ' // Colors for folders closed and folders opened
   SCIP_MarkerSetFore(pSci, %SC_MARKNUM_FOLDER, pSed.FoldForeColor)
   SCIP_MarkerSetBack(pSci, %SC_MARKNUM_FOLDER, pSed.FoldBackColor)
   SCIP_MarkerSetFore(pSci, %SC_MARKNUM_FOLDEROPEN, pSed.FoldOpenForeColor)
   SCIP_MarkerSetBack(pSci, %SC_MARKNUM_FOLDEROPEN, pSed.FoldOpenBackColor)

   ' // Add "." and "_" to the list of allowable characters for word identification
   SCIP_SetWordChars(pSci, "~._:\abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789")

   ' Disable right click popup menu
   SCIP_UsePopUp(pSci, %FALSE)

   ' // Enable unicode (UTF-8 encoding)
   IF pSed.UnicodeEnabled THEN
      SCIP_SetCodePage pSci, %SC_CP_UTF8
   ELSE
      SCIP_SetCodePage pSci, 0
   END IF

   ' // For some reason it works with %SCMOD_SHIFT and %SCMOD_ALT but not with %SCMOD_CTRL
'   Local KeyMod as long
'   Local KeyId as long
'   KeyMod = %SCMOD_CTRL
'   Shift LEFT KeyMod, 16
'   KeyId = %SCK_INSERT
'   KeyId = KeyId or KeyMod
'   SciMsg pSci, %SCI_ASSIGNCMDKEY, KeyId, %SCI_COPY

END SUB
' ========================================================================================

' ========================================================================================
' Shows the line and column in the status bar
' ========================================================================================
SUB CSED_ShowLinCol

   LOCAL curPos   AS LONG           ' // Current position
   LOCAL nLine    AS LONG           ' // Number of line
   LOCAL nCol     AS LONG           ' // Number of column
   LOCAL nLines   AS LONG           ' // Number of lines in the document
   LOCAL nTextLen AS LONG           ' // Length in characters of the document
   LOCAL startPos AS LONG           ' // Starting position of selected text - UPDATED by WLB
   LOCAL endPos   AS LONG           ' // Ending position of selected text - UPDATED by WLB
   LOCAL strText  AS STRING         ' // General purpose variable

   ' // If there is not any file being edited...
   IF pSed.hEdit = 0 THEN
      CSED_ClearStatusbar
      CSED_DisableToolbarButtons
      CSED_DisableMenuItems
      EXIT SUB
   END IF

   ' // Retrieve the information and show it in the status bar
   curPos = SCI_GetCurrentPos(pSed.hEdit)
   nLine = SCI_LineFromPosition(pSed.hEdit, curPos) + 1
   nCol = SCI_GetColumn(pSed.hEdit, curPos) + 1
   strText = " " & FORMAT$(nLine) & ":" & FORMAT$(nCol)
   StatusBar_SetText(pSed.hStatusbar, 1, strText)
   nLines = SCI_GetLineCount(pSed.hEdit)
   nTextLen = SCI_GetTextLength(pSed.hEdit)
   strText = " " & FORMAT$(nLines) & " lines, " & FORMAT$(nTextLen) & " chars"
   startPos = SCI_GetSelectionStart(pSed.hEdit)
   endPos = SCI_GetSelectionEnd(pSed.hEdit)
   IF endPos > startPos THEN strText += ", " & FORMAT$(endPos - startPos) & " selected"
   StatusBar_SetText(pSed.hStatusbar, 2, strText)
   IF pSed.SelectedCompiler = 2 THEN strText = "PBCC" ELSE strText = "PBWIN"
   StatusBar_SetText(pSed.hStatusbar, 3, strText)
   ' // Change the toolbar buttons state if needed
   CSED_ChangeToolbarButtonsState
   CSED_ChangeMenuItemsState

END SUB
' ========================================================================================

' ========================================================================================
' Autocompletion listbox
' ========================================================================================
SUB CSED_AutoComplete (BYVAL hwnd AS DWORD)

   LOCAL i             AS LONG           ' // Loop counter
   LOCAL r             AS LONG           ' // Result
   LOCAL p             AS LONG           ' // Position
   LOCAL p2            AS LONG           ' // Position
   LOCAL hMdiChild     AS DWORD          ' // Child window handle
   LOCAL hCodeTipsFile AS LONG           ' // Code tips file handle
   LOCAL CodetipRecord AS STRING * 576   ' // Record string
   LOCAL iPos          AS LONG           ' // Position
   LOCAL startPos      AS LONG           ' // Starting position
   LOCAL endPos        AS LONG           ' // Ending position
   LOCAL numItems      AS LONG           ' // Number of items
   LOCAL buffer        AS STRING         ' // Buffer
   LOCAL strFindText   AS STRING         ' // Text to find
   LOCAL strWordList   AS STRING         ' // List of words
   LOCAL strPBKeywords AS STRING         ' // PB keywords
   LOCAL hSci          AS DWORD          ' // Handle of the edit control
   DIM   rghSci(0)     AS DWORD          ' // Array of Scintilla edit controls handles
   DIM   WordList(0)   AS LOCAL STRING   ' // Array of words found

   ' // Get the word under the cursor
   buffer = SCI_GetWord(pSed.hEdit, SCI_GetCurrentPos(pSed.hEdit))
   IF ISNULL(buffer) THEN EXIT SUB
   IF LEN(buffer) < 2 THEN
      MessageBox BYVAL hwnd, "Word too short to search", _
         "Auto Complete", %MB_OK OR %MB_ICONINFORMATION OR %MB_APPLMODAL
      EXIT SUB
   END IF
   strFindText = buffer

   ' // Get the handles of the edit controls
   hMdiChild = GetWindow(pSed.hwndClient, %GW_CHILD)
   IF hMdiChild = 0 THEN EXIT SUB
   rghSci(0) = GetDlgItem(hMdiChild, %IDC_EDIT)
   DO WHILE hMdiChild <> 0
      hMdiChild = GetWindow(hMdiChild, %GW_HWNDNEXT)
      IF hMdiChild THEN
         REDIM PRESERVE rghSci(UBOUND(rghSci) + 1)
         rghSci(UBOUND(rghSci)) = GetDlgItem(hMdiChild, %IDC_EDIT)
      END IF
   LOOP

   FOR i = LBOUND(rghSci) TO UBOUND(rghSci)
      ' // Scintilla edit control handle
      hSci = rghSci(i)
      ' // Ignore case
      SCI_AutocSetIgnoreCase(hSci, %TRUE)
      ' // Search whole document
      startPos = 0
      endPos = SCI_GetTextLength(hSci)
      DO
         ' // Set the find flags and the starting and ending positions
         SCI_SetSearchFlags(hSci, %SCFIND_WORDSTART)
         SCI_SetTargetStart(hSci, startPos)
         SCI_SetTargetEnd(hSci, endPos)
         ' // Search the text
         r = SCI_SearchInTarget(hSci, strFindText)
         ' // Increase the starting position
         startPos = r + 1
         ' // If r = -1 there is no more text to scan
         IF CINT(r) = -1 THEN
            EXIT DO
         ELSE
            buffer = SCI_GetWord(hSci, r)
            IF UCASE$(buffer) <> UCASE$(strFindText) THEN   ' // Skip our own word
               ARRAY SCAN WordList(), COLLATE UCASE, = buffer, TO iPos
               IF ISFALSE iPos THEN
                  INCR numItems
                  REDIM PRESERVE WordList(numItems - 1)
                  WordList(UBOUND(WordList)) = buffer
               END IF
            END IF
         END IF
      LOOP
   NEXT

   ' // Include PB keywords in the autocomplete list
   p2 = 1
   strPBKeywords = pSed.PBKeywords
   DO
      p = INSTR(p2, strPBKeyWords, " " & LCASE$(strFindText))
      IF p = 0 THEN EXIT DO
      p2 = INSTR(p + 1, strPBKeyWords, " ")
      IF p2 = 0 THEN EXIT DO
      buffer = MID$(strPBKeyWords, p + 1, p2 - p - 1)
      ARRAY SCAN WordList(), COLLATE UCASE, = buffer, TO iPos
      IF ISFALSE iPos THEN
         INCR numItems
         REDIM PRESERVE WordList(numItems - 1)
         WordList(UBOUND(WordList)) = UCASE$(buffer)
      END IF
   LOOP

   ' // Include the function names of the Codetips in the autocomplete list
   hCodetipsFile = trm_Open(EXE.PATH$ & "CSED_CODETIPS\" & $CODETIPSDB, %TRUE)
   IF ISTRUE hCodetipsFile THEN
      CodetipRecord = trm_GetEqualOrGreater(hCodetipsFile, 1, strFindText)
      DO
         IF TRIM$(CodetipRecord) = "" THEN EXIT DO
         buffer = TRIM$(LEFT$(CodetipRecord, 64))
         IF UCASE$(LEFT$(buffer, LEN(strFindText))) <> UCASE$(strFindText) THEN EXIT DO
         ARRAY SCAN WordList(), COLLATE UCASE, = buffer, TO iPos
         IF ISFALSE iPos THEN
            INCR numItems
            REDIM PRESERVE WordList(numItems - 1)
            WordList(UBOUND(WordList)) = buffer
         END IF
         CodetipRecord = trm_GetNext(hCodetipsFile)
      LOOP
      ' // Close the file
      trm_Close hCodetipsFile
   END IF

   IF ISTRUE numItems THEN
      ARRAY SORT WordList(), COLLATE UCASE
      strWordList = JOIN$(WordList(), $SPC)
      SCI_AutocShow(pSed.hEdit, LEN(strFindText), strWordList)
   END IF

END SUB
' ========================================================================================

' ========================================================================================
' Retrieves the code tip and returns it in as the result of the function.
' ========================================================================================
FUNCTION CSED_GetCodeTip (BYVAL strWord AS STRING) AS STRING

   LOCAL hCodeTipsFile AS LONG           ' // Code tips file handle
   LOCAL CodetipRecord AS STRING * 576   ' // Record string
   LOCAL strCodeTip AS STRING            ' // Code tip
   LOCAL p AS LONG                       ' // Position

   IF pSed.CodeTips <> %BST_CHECKED THEN EXIT FUNCTION

   ' // Retrieve the record
   hCodetipsFile = trm_Open(EXE.PATH$ & "CSED_CODETIPS\" & $CODETIPSDB, %TRUE)
   IF ISTRUE hCodetipsFile THEN
      CodetipRecord = trm_GetEqualOrGreater(hCodetipsFile, 1, strWord)
      IF UCASE$(TRIM$(LEFT$(CodetipRecord, 64))) = UCASE$(strWord) THEN
         strCodeTip = TRIM$(MID$(CodetipRecord, 65, LEN(CodetipRecord) - 64))
      ELSE
         CodetipRecord = trm_GetEqualOrGreater(hCodetipsFile, 1, strWord & "A")
         IF UCASE$(TRIM$(LEFT$(CodetipRecord, 64))) = UCASE$(strWord & "A") THEN
            strCodeTip = TRIM$(MID$(CodetipRecord, 65, LEN(CodetipRecord) - 64))
         END IF
         CodetipRecord = trm_GetEqualOrGreater(hCodetipsFile, 1, strWord & "W")
         IF UCASE$(TRIM$(LEFT$(CodetipRecord, 64))) = UCASE$(strWord & "W") THEN
            strCodeTip += $LF & TRIM$(MID$(CodetipRecord, 65, LEN(CodetipRecord) - 64))
         END IF
      END IF
      trm_Close hCodetipsFile
   END IF

   ' // Return the codetip found
   IF ISNOTNULL(strCodeTip) THEN
      REPLACE "  " WITH " " IN strCodeTip
      IF INSTR(strCodeTip, "( ") THEN
         REPLACE "( " WITH "(  " IN strCodeTip
      ELSEIF INSTR(strCodeTip, "(") THEN
         REPLACE "(" WITH "(  " IN strCodeTip
      END IF
      p = INSTR(strCodeTip, "(")
      IF p THEN
         IF MID$(strCodeTip, p + 1, 1) <> ")" AND MID$(strCodeTip, p + 1, 2) <> " )" THEN
            REPLACE "(" WITH "( _" & $LF IN strCodeTip
            IF INSTR(strCodeTip, " )") THEN
               REPLACE ")" WITH "_" & $LF & ")" IN strCodeTip
            ELSEIF INSTR(strCodeTip, ")") THEN
               REPLACE ")" WITH " _" & $LF & ")" IN strCodeTip
            END IF
         END IF
      END IF
      REPLACE ", " WITH "," IN strCodeTip
      REPLACE " ," WITH "," IN strCodeTip
      REPLACE "," WITH " _" & $LF & ", " IN strCodeTip
      FUNCTION = strCodeTip
   END IF

END FUNCTION
' ========================================================================================

' ========================================================================================
' Show codetips
' ========================================================================================
SUB CSED_ShowCodetip

   LOCAL curPos     AS LONG     ' // Current position
   LOCAL tipPos     AS LONG     ' // Tip position
   LOCAL buffer     AS STRING   ' // Buffer
   LOCAL CodetipStr AS STRING   ' // Codetip string

   ' // Retrieve the position
   curPos = SCI_GetCurrentPos(pSed.hEdit)
   tipPos = curPos - 1   ' // Skip the "("

   ' // Retrieve the word
   buffer = SCI_GetWord(pSed.hEdit, curPos - 1)
   IF LEN(buffer) THEN
      CodetipStr = TRIM$(CSED_GetCodetip(buffer))
      IF LEN(CodetipStr) THEN
         SCI_CallTipShow(pSed.hEdit, tipPos - LEN(buffer), CodetipStr)
      END IF
   END IF

END SUB
' ========================================================================================

' ========================================================================================
' Processes the Scintilla Edit Control notification messages
' ========================================================================================
FUNCTION SCI_OnNotify (BYVAL hwnd AS DWORD, BYVAL wParam AS DWORD, BYVAL lParam AS DWORD) AS LONG

   LOCAL i          AS LONG                 ' // Loop counter
   LOCAL curPos     AS LONG                 ' // Current position
   LOCAL LineNumber AS LONG                 ' // Line number
   LOCAL LineLen    AS LONG                 ' // Line length
   LOCAL IndentSize AS LONG                 ' // Size of the indent
   LOCAL TabSize    AS LONG                 ' // Tab size
   LOCAL nSpaces    AS LONG                 ' // Number of spaces
   LOCAL buffer     AS STRING               ' // Buffer
   LOCAL strFill    AS STRING               ' // Filler string
   LOCAL rightWord  AS STRING               ' // Word on the right side of the line
   LOCAL strEnd     AS STRING               ' // End of the construct
   LOCAL pNSC       AS SCNotification PTR   ' // Scintilla notification messages structure
   LOCAL tProc      AS CSED_PROCSTRUCT      ' // Proc structure

   pNSC = lParam
   SELECT CASE @pNSC.hdr.code
      CASE %SCN_UPDATEUI
         ' // Show line and column
         IF ((@pNSC.updated AND %SC_UPDATE_V_SCROLL) <> %SC_UPDATE_V_SCROLL) AND _
            ((@pNSC.updated AND %SC_UPDATE_H_SCROLL) <> %SC_UPDATE_H_SCROLL) THEN
            CSED_ShowLinCol
            ' // Show the sub/function name in the statusbar
            IF pSed.ShowProcedureName = %BST_CHECKED THEN
               CSED_WithinProc(tProc)
               StatusBar_SetText(pSed.hStatusbar, 4, tProc.ProcName)
            END IF
         END IF

      ' // Avoid repeated menu and toolbar update when doing a replace all action
'      CASE %SCN_MODIFIED
'         IF (pSed.FindReplaceObj.Flags AND %FR_REPLACEALL) <> %FR_REPLACEALL THEN
'            IF ((@pNSC.modificationType AND %SC_MOD_INSERTTEXT) = %SC_MOD_INSERTTEXT) THEN
'               CSED_ShowLinCol
'            END IF
'         END IF

      CASE %SCN_MARGINCLICK
         ' // Folder margin
         IF @pNSC.margin = 2 THEN
            LineNumber = SCI_LineFromPosition(pSed.hEdit, @pNSC.position)
            ' // If is the head line...
            IF (SCI_GetFoldLevel(pSed.hEdit, LineNumber) AND %SC_FOLDLEVELHEADERFLAG) <> 0 THEN
               IF SCI_ToggleFold(pSed.hEdit, LineNumber) = - 1 THEN
                  SCI_SelectLine(pSed.hEdit, LineNumber)
               END IF
            ELSE
               SCI_SelectLine(pSed.hEdit, LineNumber)
            END IF
         ELSE
            LineNumber = SCI_LineFromPosition(pSed.hEdit, @pNSC.position)
            SCI_SelectLine(pSed.hEdit, LineNumber)
         END IF

      CASE %SCN_CHARADDED
         IF @pNSC.ch = 40 THEN CSED_ShowCodetip                ' "(" // Show code tip
         IF @pNSC.ch = 41 THEN SCI_CallTipCancel(pSed.hEdit)   ' ")" // Cancel code tip
         ' // Auto indentation - since SCN_KEY isn't sent in the Windows version,
         ' // we detect the new line if the charadded is a carriage return
         IF @pNSC.ch = 13 THEN              ' carriage return
            IF pSed.AutoIndent = %BST_CHECKED THEN
               ' // Current position
               curPos = SCI_GetCurrentPos(pSed.hEdit)
               ' // Line number
               LineNumber = SCI_LineFromPosition(pSed.hEdit, curPos)
               ' // Line length of the previous line
               LineLen = SCI_LineLength(pSed.hEdit, LineNumber - 1)
               ' // Get the text of the previous line
               buffer = SCI_GetLine(pSed.hEdit, LineNumber - 1)
               ' // Get the tab width
               TabSize = SCI_GetTabWidth(pSed.hEdit)
               ' // Calculate the number of spaces to fill on the left
               nSpaces = 0
               FOR i = 1 TO LEN(buffer)
                  IF MID$(buffer, i, 1) <> " " THEN
                     IF MID$(buffer, i, 1) = $TAB THEN
                        nSpaces = nSpaces + TabSize
                     ELSE
                        EXIT FOR
                     END IF
                  ELSE
                     nSpaces = nSpaces + 1
                  END IF
               NEXT
               ' // Remove $CRLF
               buffer = REMOVE$(buffer, ANY CHR$(13, 10))
               ' // Remove spaces and tabs and convert to uppercase
               buffer = TRIM$(UCASE$(buffer), ANY CHR$(32, 9))
               IF (LEFT$(buffer, 3) = "IF " AND RIGHT$(buffer, 5) = " THEN") OR _
                  LEFT$(buffer, 4) = "ELSE" OR _
                  LEFT$(buffer, 7) = "SELECT " OR _
                  LEFT$(buffer, 5) = "CASE " OR _
                  LEFT$(buffer, 4) = "FOR " OR _
                  LEFT$(buffer, 3) = "DO " OR _
                  buffer = "DO" OR _
                  LEFT$(buffer, 6) = "WHILE " OR _
                  buffer = "WHILE" THEN
                  ' // Indentation size
                  IndentSize = SCI_GetIndent(pSed.hEdit)
                  ' // Add spaces to indent the line
                  strFill = SPACE$(nSpaces + IndentSize)
               ELSE
                  ' Add the same spaces on the left that the line above
                  strFill = SPACE$(nSpaces)
               END IF
               ' // Replace spaces with tabs
               IF pSed.UseTabs THEN strFill = SCI_SpacesToTabs(pSed.hEdit, strFill)
               ' // Indents the line
               SCI_AddText(pSed.hEdit, strFill)
            END IF
         END IF
         IF @pNSC.ch = 32 THEN
            IF pSed.ConstructAutocompletion THEN
               ' // Current position
               curPos = SCI_GetCurrentPos(pSed.hEdit)
               ' // Line number
               LineNumber = SCI_LineFromPosition(pSed.hEdit, curPos)
               ' // Length of the line
               LineLen = SCI_LineLength(pSed.hEdit, LineNumber)
               ' // Get the text of the line
               buffer = SCI_GetLine(pSed.hEdit, LineNumber)
               ' // Get the tab width
               TabSize = SCI_GetTabWidth(pSed.hEdit)
               ' // Calculate the number of spaces to fill on the left
               nSpaces = 0
               FOR i = 1 TO LEN(buffer)
                  IF MID$(buffer, i, 1) <> " " THEN
                     IF MID$(buffer, i, 1) = $TAB THEN
                        nSpaces = nSpaces + TabSize
                     ELSE
                        EXIT FOR
                     END IF
                  ELSE
                     nSpaces = nSpaces + 1
                  END IF
               NEXT
               ' // Remove $CRLF
               buffer = REMOVE$(buffer, ANY CHR$(13, 10))
               ' // Remove spaces and tabs and convert to uppercase
               buffer = TRIM$(UCASE$(buffer), ANY CHR$(32, 9))
               FOR i = LEN(buffer) TO 1 STEP -1
                  IF MID$(buffer, i, 1) <> CHR$(32) THEN
                     rightWord = MID$(buffer, i, 1) + rightWord
                  ELSE
                     EXIT FOR
                  END IF
               NEXT
               SELECT CASE buffer
                  CASE "FUNCTION"
                     CSED_WithinProc(tProc)
                     IF tProc.WhatIsDown <> %ID_PROCEND THEN
                        strFill = "FunName()" & $CRLF
                        SCI_AddText(pSed.hEdit, strFill)
                        IndentSize = SCI_GetIndent(pSed.hEdit)
                        strFill = SPACE$(nSpaces + IndentSize)
                        IF pSed.UseTabs THEN strFill = SCI_SpacesToTabs(pSed.hEdit, strFill)
                        SCI_AddText(pSed.hEdit, strFill)
                        strEnd = "END FUNCTION"
                        strFill = $CRLF & SPACE$(nSpaces) & strEnd
                        IF pSed.UseTabs THEN strFill = SCI_SpacesToTabs(pSed.hEdit, strFill)
                        SCI_AddText(pSed.hEdit, strFill)
                        SCI_GotoPos(pSed.hEdit, curPos)
                        SCI_SetAnchor(pSed.hEdit, curPos + 7)
                     END IF
                  CASE "SUB"
                     strFill = "SubName()" & $CRLF
                     SCI_AddText(pSed.hEdit, strFill)
                     IndentSize = SCI_GetIndent(pSed.hEdit)
                     strFill = SPACE$(nSpaces + IndentSize)
                     IF pSed.UseTabs THEN strFill = SCI_SpacesToTabs(pSed.hEdit, strFill)
                     SCI_AddText(pSed.hEdit, strFill)
                     strEnd = "END SUB"
                     strFill = $CRLF & SPACE$(nSpaces) & strEnd
                     IF pSed.UseTabs THEN strFill = SCI_SpacesToTabs(pSed.hEdit, strFill)
                     SCI_AddText(pSed.hEdit, strFill)
                     SCI_GotoPos(pSed.hEdit, curPos)
                     SCI_SetAnchor(pSed.hEdit, curPos + 7)
'                  CASE "CLASS"
                     ' // Don't autocomplete because conflicts with CLASS METHOD
'                     strFill = "ClassName" & $CRLF
'                     SCI_AddText(pSed.hEdit, strFill)
'                     IndentSize = SCI_GetIndent(pSed.hEdit)
'                     strFill = SPACE$(nSpaces + IndentSize)
'                     IF pSed.UseTabs THEN strFill = SCI_SpacesToTabs(pSed.hEdit, strFill)
'                     SCI_AddText(pSed.hEdit, strFill)
'                     strEnd = "END CLASS"
'                     strFill = $CRLF & SPACE$(nSpaces) & strEnd
'                     IF pSed.UseTabs THEN strFill = SCI_SpacesToTabs(pSed.hEdit, strFill)
'                     SCI_AddText(pSed.hEdit, strFill)
'                     SCI_GotoPos(pSed.hEdit, curPos)
'                     SCI_SetAnchor(pSed.hEdit, curPos + 9)
                  CASE "INTERFACE"
                     strFill = "InterfaceName" & $CRLF
                     SCI_AddText(pSed.hEdit, strFill)
                     IndentSize = SCI_GetIndent(pSed.hEdit)
                     strFill = SPACE$(nSpaces + IndentSize)
                     IF pSed.UseTabs THEN strFill = SCI_SpacesToTabs(pSed.hEdit, strFill)
                     SCI_AddText(pSed.hEdit, strFill)
                     strEnd = "END INTERFACE"
                     strFill = $CRLF & SPACE$(nSpaces) & strEnd
                     IF pSed.UseTabs THEN strFill = SCI_SpacesToTabs(pSed.hEdit, strFill)
                     SCI_AddText(pSed.hEdit, strFill)
                     SCI_GotoPos(pSed.hEdit, curPos)
                     SCI_SetAnchor(pSed.hEdit, curPos + 13)
                  CASE "METHOD", "CLASS METHOD"
                     strFill = "MethodName()" & $CRLF
                     SCI_AddText(pSed.hEdit, strFill)
                     IndentSize = SCI_GetIndent(pSed.hEdit)
                     strFill = SPACE$(nSpaces + IndentSize)
                     IF pSed.UseTabs THEN strFill = SCI_SpacesToTabs(pSed.hEdit, strFill)
                     SCI_AddText(pSed.hEdit, strFill)
                     strEnd = "END METHOD"
                     strFill = $CRLF & SPACE$(nSpaces) & strEnd
                     IF pSed.UseTabs THEN strFill = SCI_SpacesToTabs(pSed.hEdit, strFill)
                     SCI_AddText(pSed.hEdit, strFill)
                     SCI_GotoPos(pSed.hEdit, curPos)
                     SCI_SetAnchor(pSed.hEdit, curPos + 10)
                  CASE "PROPERTY"
                     strFill = "PropertyName()" & $CRLF
                     SCI_AddText(pSed.hEdit, strFill)
                     IndentSize = SCI_GetIndent(pSed.hEdit)
                     strFill = SPACE$(nSpaces + IndentSize)
                     IF pSed.UseTabs THEN strFill = SCI_SpacesToTabs(pSed.hEdit, strFill)
                     SCI_AddText(pSed.hEdit, strFill)
                     strEnd = "END PROPERTY"
                     strFill = $CRLF & SPACE$(nSpaces) & strEnd
                     IF pSed.UseTabs THEN strFill = SCI_SpacesToTabs(pSed.hEdit, strFill)
                     SCI_AddText(pSed.hEdit, strFill)
                     SCI_GotoPos(pSed.hEdit, curPos)
                     SCI_SetAnchor(pSed.hEdit, curPos + 12)
                  CASE "IF"
                     strFill = "x THEN" & $CRLF
                     SCI_AddText(pSed.hEdit, strFill)
                     IndentSize = SCI_GetIndent(pSed.hEdit)
                     strFill = SPACE$(nSpaces + IndentSize)
                     IF pSed.UseTabs THEN strFill = SCI_SpacesToTabs(pSed.hEdit, strFill)
                     SCI_AddText(pSed.hEdit, strFill)
                     strEnd = "END IF"
                     strFill = $CRLF & SPACE$(nSpaces) & strEnd
                     IF pSed.UseTabs THEN strFill = SCI_SpacesToTabs(pSed.hEdit, strFill)
                     SCI_AddText(pSed.hEdit, strFill)
                     SCI_GotoPos(pSed.hEdit, curPos)
                     SCI_SetAnchor(pSed.hEdit, curPos + 1)
                  CASE "WHILE"
                     strFill = "x" & $CRLF
                     SCI_AddText(pSed.hEdit, strFill)
                     IndentSize = SCI_GetIndent(pSed.hEdit)
                     strFill = SPACE$(nSpaces + IndentSize)
                     IF pSed.UseTabs THEN strFill = SCI_SpacesToTabs(pSed.hEdit, strFill)
                     SCI_AddText(pSed.hEdit, strFill)
                     strEnd = "WEND"
                     strFill = $CRLF & SPACE$(nSpaces) & strEnd
                     IF pSed.UseTabs THEN strFill = SCI_SpacesToTabs(pSed.hEdit, strFill)
                     SCI_AddText(pSed.hEdit, strFill)
                     SCI_GotoPos(pSed.hEdit, curPos)
                     SCI_SetAnchor(pSed.hEdit, curPos + 1)
                  CASE "FOR"
                     strFill = "x" & $CRLF
                     SCI_AddText(pSed.hEdit, strFill)
                     IndentSize = SCI_GetIndent(pSed.hEdit)
                     strFill = SPACE$(nSpaces + IndentSize)
                     IF pSed.UseTabs THEN strFill = SCI_SpacesToTabs(pSed.hEdit, strFill)
                     SCI_AddText(pSed.hEdit, strFill)
                     strEnd = "NEXT"
                     strFill = $CRLF & SPACE$(nSpaces) & strEnd
                     IF pSed.UseTabs THEN strFill = SCI_SpacesToTabs(pSed.hEdit, strFill)
                     SCI_AddText(pSed.hEdit, strFill)
                     SCI_GotoPos(pSed.hEdit, curPos)
                     SCI_SetAnchor(pSed.hEdit, curPos + 1)
                  CASE "SELECT"
                     strFill = "CASE x" & $CRLF
                     SCI_AddText(pSed.hEdit, strFill)
                     IndentSize = SCI_GetIndent(pSed.hEdit)
                     strEnd = "CASE ELSE"
                     strFill = SPACE$(nSpaces + 3) & strEnd
                     IF pSed.UseTabs THEN strFill = SCI_SpacesToTabs(pSed.hEdit, strFill)
                     SCI_AddText(pSed.hEdit, strFill)
                     strEnd = "END SELECT"
                     strFill = $CRLF & SPACE$(nSpaces) & strEnd
                     IF pSed.UseTabs THEN strFill = SCI_SpacesToTabs(pSed.hEdit, strFill)
                     SCI_AddText(pSed.hEdit, strFill)
                     SCI_GotoPos(pSed.hEdit, curPos + 5)
                     SCI_SetAnchor(pSed.hEdit, curPos + 6)
                  CASE "TYPE"
                     strFill = "TypeName" & $CRLF
                     SCI_AddText(pSed.hEdit, strFill)
                     IndentSize = SCI_GetIndent(pSed.hEdit)
                     strFill = SPACE$(nSpaces + IndentSize)
                     IF pSed.UseTabs THEN strFill = SCI_SpacesToTabs(pSed.hEdit, strFill)
                     SCI_AddText(pSed.hEdit, strFill)
                     strEnd = "END TYPE"
                     strFill = $CRLF & SPACE$(nSpaces) & strEnd
                     IF pSed.UseTabs THEN strFill = SCI_SpacesToTabs(pSed.hEdit, strFill)
                     SCI_AddText(pSed.hEdit, strFill)
                     SCI_GotoPos(pSed.hEdit, curPos)
                     SCI_SetAnchor(pSed.hEdit, curPos + 8)
                  CASE "UNION"
                     strFill = "UnionName" & $CRLF
                     SCI_AddText(pSed.hEdit, strFill)
                     IndentSize = SCI_GetIndent(pSed.hEdit)
                     strFill = SPACE$(nSpaces + IndentSize)
                     IF pSed.UseTabs THEN strFill = SCI_SpacesToTabs(pSed.hEdit, strFill)
                     SCI_AddText(pSed.hEdit, strFill)
                     strEnd = "END UNION"
                     strFill = $CRLF & SPACE$(nSpaces) & strEnd
                     IF pSed.UseTabs THEN strFill = SCI_SpacesToTabs(pSed.hEdit, strFill)
                     SCI_AddText(pSed.hEdit, strFill)
                     SCI_GotoPos(pSed.hEdit, curPos)
                     SCI_SetAnchor(pSed.hEdit, curPos + 9)
               END SELECT
            END IF
         END IF
   END SELECT

END FUNCTION
' ========================================================================================
