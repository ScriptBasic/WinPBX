' ========================================================================================
' The following example shows how to determine whether the current platform is supported.
' ========================================================================================

' SED_PBCC - Use the console compiler
#COMPILE EXE
#DIM ALL
#INCLUDE "windows.inc"
#INCLUDE "winhttp.inc"

' ========================================================================================
' Main
' ========================================================================================
FUNCTION PBMAIN () AS LONG

   IF WinHttpCheckPlatform THEN
      PRINT "This platform is supported by WinHTTP."
   ELSE
      PRINT "This platform is NOT supported by WinHTTP."
   END IF

   WAITKEY$

END FUNCTION
' ========================================================================================
