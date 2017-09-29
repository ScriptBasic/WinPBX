' ========================================================================================
' The following example code shows how to retrieve the default connection time-out value.
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
   LOCAL pData AS DWORD
   LOCAL dwSize AS DWORD
   LOCAL wszUserAgent AS WSTRINGZ * 260

   dwSize = 4  ' size of a DWORD

   ' Use WinHttpOpen to obtain a session handle.
   wszUserAgent = "A WinHTTP Example Program/1.0"
   hSession = WinHttpOpen(wszUserAgent, _
                          %WINHTTP_ACCESS_TYPE_DEFAULT_PROXY, _
                          BYVAL %WINHTTP_NO_PROXY_NAME, _
                          BYVAL %WINHTTP_NO_PROXY_BYPASS, _
                          0)

   IF hSession THEN
      ' Use WinHttpQueryOption to retrieve internet options.
      IF WinHttpQueryOption(hSession, _
                            %WINHTTP_OPTION_CONNECT_TIMEOUT, _
                            VARPTR(pdata), _
                            dwSize) THEN
         PRINT "Connection timeout: " pdata
      ELSE
         PRINT "Error " GetLastError " in WinHttpQueryOption"
      END IF
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
