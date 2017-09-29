' ########################################################################################
' The following example enumerates the printers using a Level 5.
' ########################################################################################

' SED_PBCC - Use the PBCC compiler
#COMPILE EXE
#DIM ALL
#INCLUDE "windows.inc"

' ========================================================================================
' Main
' ========================================================================================
FUNCTION PBMAIN () AS LONG

   LOCAL Level AS LONG
   LOCAL cbNeeded AS LONG
   LOCAL cbReturned AS LONG
   LOCAL i AS LONG
   DIM   Pi5(0) AS LOCAL PRINTER_INFO_5

   Level = 5
   EnumPrinters %PRINTER_ENUM_LOCAL, BYVAL %NULL, Level, BYVAL %NULL, 0, cbNeeded, cbReturned
   REDIM Pi5(0 TO cbNeeded \ SIZEOF(Pi5(0)))
   EnumPrinters %PRINTER_ENUM_LOCAL, "", Level, BYVAL VARPTR(Pi5(0)), _
         SIZEOF(Pi5(0)) * (UBOUND(Pi5) + 1), cbNeeded, cbReturned
   FOR i = 0 TO cbReturned - 1
      PRINT Pi5(i).@pPrinterName "," Pi5(i).@pPortName
   NEXT
   WAITKEY$

END FUNCTION
' ========================================================================================
