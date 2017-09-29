' ########################################################################################
' The following code displays the font names and styles.
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

   ' Create a device context
   hdc = GetDC(%HWND_DESKTOP)
   ' Enumerate the fonts
   EnumFontFamilies hDc, BYVAL %NULL, CODEPTR(EnumFontFamProc), BYVAL %NULL
   ' Delete the device context
   DeleteDC hdc

   WAITKEY$

END FUNCTION
' ========================================================================================

' ========================================================================================
' EnumFontFamProc callback procedure
' ========================================================================================
FUNCTION EnumFontFamProc (BYREF lpelf AS ENUMLOGFONT, BYREF lpntm AS NEWTEXTMETRIC, BYVAL FontType AS DWORD, BYVAL lParam AS DWORD) AS LONG

   PRINT "Font name: " lpelf.elfFullName " ";
   PRINT "Font style: " lpelf.elfStyle
   FUNCTION = %TRUE

END FUNCTION
' ========================================================================================
