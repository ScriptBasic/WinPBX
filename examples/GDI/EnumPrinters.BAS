' ########################################################################################
' The following example enumerates the printers using a Level 2.
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
   DIM   Pi2(0) AS LOCAL PRINTER_INFO_2

   Level = 2
   EnumPrinters %PRINTER_ENUM_CONNECTIONS OR %PRINTER_ENUM_LOCAL OR %PRINTER_ENUM_NETWORK, _
                BYVAL %NULL, Level, BYVAL %NULL, 0, cbNeeded, cbReturned
   REDIM PI2(0 TO cbNeeded \ SIZEOF(PI2(0)))
   EnumPrinters %PRINTER_ENUM_CONNECTIONS OR %PRINTER_ENUM_LOCAL OR %PRINTER_ENUM_NETWORK, _
         "", Level, BYVAL VARPTR(PI2(0)), SIZEOF(PI2(0)) * (UBOUND(PI2) + 1), _
         cbNeeded, cbReturned
   FOR i = 0 TO cbReturned - 1
      PRINT PI2(i).@pPrinterName "," PI2(i).@pDriverName "," PI2(i).@pPortName
   NEXT
   WAITKEY$

END FUNCTION
' ========================================================================================
