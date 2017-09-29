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

   ' Create a device context
   hdc = GetDC(%HWND_DESKTOP)
   lf.lfFaceName = "Times New Roman"
   lf.lfCharset = %DEFAULT_CHARSET
   ' Enumerate the fonts
   EnumFontFamiliesEx hDc, lf, CODEPTR(EnumFontFamExProc), %NULL, 0
   ' Delete the device context
   DeleteDC hdc

   WAITKEY$

END FUNCTION
' ========================================================================================

' ========================================================================================
' EnumFontFamExProc callback procedure
' ========================================================================================
FUNCTION EnumFontFamExProc (BYREF lpelf AS ENUMLOGFONT, BYREF lpntm AS NEWTEXTMETRIC, BYVAL FontType AS DWORD, BYVAL lParam AS DWORD) AS LONG

   PRINT "Font name: " lpelf.elfFullName " ";
   PRINT "Font style: " lpelf.elfStyle " ";
   PRINT "Charset: " lpelf.elfLogFont.lfCharset " ";
   PRINT "Weight: " lpelf.elfLogFont.lfWeight
   FUNCTION = %TRUE

END FUNCTION
' ========================================================================================
