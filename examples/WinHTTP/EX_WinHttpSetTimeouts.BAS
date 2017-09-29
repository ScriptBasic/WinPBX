' ========================================================================================
' The following example shows you how to retrieve the connection time-out value.
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

   LOCAL hSession AS DWORD
   LOCAL wszUserAgent AS WSTRINGZ * 260

   ' Use WinHttpOpen to obtain a session handle.
   wszUserAgent = "A WinHTTP Example Program/1.0"
   hSession = WinHttpOpen(wszUserAgent, _
                          %WINHTTP_ACCESS_TYPE_DEFAULT_PROXY, _
                          BYVAL %WINHTTP_NO_PROXY_NAME, _
                          BYVAL %WINHTTP_NO_PROXY_BYPASS, _
                          0)

   IF hSession THEN
      ' Use WinHttpSetTimeouts to set a new time-out values.
      IF ISFALSE WinHttpSetTimeouts(hSession, 10000, 10000, 10000, 10000) THEN
         PRINT "Error " GetLastError " in WinHttpSetTimeouts."
      ELSE
         PRINT "Timeouts set"
      END IF

      ' PLACE ADDITIONAL CODE HERE.

      ' When finished, release the HINTERNET handle.
      WinHttpCloseHandle(hSession)
   ELSE
      PRINT "Error " GetLastError " in in WinHttpOpen."
   END IF

   ' Close open handles.
   IF hSession THEN WinHttpCloseHandle(hSession)

   WAITKEY$

END FUNCTION
' ========================================================================================
