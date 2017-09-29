' ########################################################################################
' The following code displays the names of the fonts available in the DISPLAY device.
' ########################################################################################

' SED_PBCC - Use the PBCC compiler
#COMPILE EXE
#DIM ALL
#INCLUDE "windows.inc"

' ========================================================================================
' Main
' ========================================================================================
FUNCTION PBMAIN () AS LONG

   LOCAL szDriver AS ASCIIZ * 256
   LOCAL hdc AS DWORD

   ' Create a device context
   szDriver = "DISPLAY"
   hdc = CreateDc (szDriver, BYVAL %NULL, BYVAL %NULL, BYVAL %NULL)
   ' Enumerate the fonts
   EnumFonts hDc, BYVAL %NULL, CODEPTR(EnumFontsProc), %NULL
   ' Delete the device context
   DeleteDC hdc

   WAITKEY$

END FUNCTION
' ========================================================================================

' ========================================================================================
' EnumFonts callback procedure
' ========================================================================================
FUNCTION EnumFontsProc (BYREF lplf AS LOGFONT, BYREF lptm AS TEXTMETRIC, BYVAL dwType AS DWORD, BYVAL pData AS DWORD) AS LONG

   PRINT "Font name: " lplf.lfFaceName
   FUNCTION = %TRUE

END FUNCTION
' ========================================================================================
