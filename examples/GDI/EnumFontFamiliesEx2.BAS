' ########################################################################################
' The following code enumerates all styles and charsets of the Times New Roman font.
' ########################################################################################

' CSED_PBCC - Use the PBCC compiler
#COMPILE EXE
#DIM ALL
#INCLUDE "windows.inc"

' ========================================================================================
' Main
' ========================================================================================
FUNCTION PBMAIN () AS LONG

   LOCAL hdc AS DWORD
   LOCAL lf AS LOGFONT
   LOCAL strOutput AS STRING

   ' Create a device context
   hdc = GetDC(%HWND_DESKTOP)
   lf.lfFaceName = "Times New Roman"
   lf.lfCharset = %DEFAULT_CHARSET
   ' Enumerate the fonts
   EnumFontFamiliesEx hDc, lf, CODEPTR(EnumFontFamExProc), VARPTR(strOutput), 0
   STDOUT strOutput
   ' Delete the device context
   DeleteDC hdc

   WAITKEY$

END FUNCTION
' ========================================================================================

' ========================================================================================
' EnumFontFamExProc callback procedure
' ========================================================================================
FUNCTION EnumFontFamExProc (BYREF lpelf AS ENUMLOGFONT, BYREF lpntm AS NEWTEXTMETRIC, BYVAL FontType AS DWORD, BYVAL lParam AS STRING PTR) AS LONG

   @lParam = @lParam & "Font name: " & lpelf.elfFullName & _
             " Font style: " & lpelf.elfStyle & _
             " Charset: " & FORMAT$(lpelf.elfLogFont.lfCharset) & _
             " Weight: " & FORMAT$(lpelf.elfLogFont.lfWeight) & $CRLF
   FUNCTION = %TRUE

END FUNCTION
' ========================================================================================
