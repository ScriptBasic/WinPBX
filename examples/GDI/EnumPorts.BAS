' ########################################################################################
' The following example enumerates the ports that are available for printing on the local server.
' ########################################################################################

' CSED_PBCC - Use the PBCC compiler
#COMPILE EXE
#DIM ALL
#INCLUDE "windows.inc"

' ========================================================================================
' Main
' ========================================================================================
FUNCTION PBMAIN () AS LONG

   LOCAL cbNeeded AS LONG
   LOCAL cbReturned AS LONG
   LOCAL i AS LONG
   DIM   Ports(0) AS PORT_INFO_1

   EnumPorts(BYVAL %NULL, 1, BYVAL %NULL, 0, cbNeeded, cbReturned)
   IF cbNeeded THEN
      REDIM Ports(0 TO cbNeeded \ SIZEOF(PORT_INFO_1))
#IF %DEF(%USEPBDECL)
      EnumPortsW BYVAL %NULL, 1, BYVAL VARPTR(Ports(0)), SIZEOF(Ports(0)) * (UBOUND(Ports) + 1), cbNeeded, cbReturned
#ELSE
      EnumPortsW BYVAL %NULL, 1, Ports(0), SIZEOF(Ports(0)) * (UBOUND(Ports) + 1), cbNeeded, cbReturned
#ENDIF
      PRINT " #", "Port name"
      PRINT " -", "---------"
      FOR i = 0 TO cbReturned - 1
          PRINT i, Ports(i).@pName
      NEXT
   END IF

   WAITKEY$

END FUNCTION
' ========================================================================================
