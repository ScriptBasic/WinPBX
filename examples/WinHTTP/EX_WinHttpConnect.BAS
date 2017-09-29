' ========================================================================================
' The following example shows how to use secure transaction semantics to download a
' resource from an HTTPS server. The sample code initializes the Microsoft Windows HTTP
' Services (WinHTTP) application programming interface (API), selects a target HTTPS
' server, then opens and sends a request for this secure resource.
' WinHttpQueryDataAvailable is used with the request handle to determine how much data is
' available for download, then WinHttpReadData is used to read that data. This process
' repeats until the entire document has been retrieved and displayed.
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

   LOCAL dwSize AS DWORD
   LOCAL dwDownloaded AS DWORD
   LOCAL bResults AS LONG
   LOCAL hSession AS DWORD
   LOCAL hConnect AS DWORD
   LOCAL hRequest AS DWORD
   LOCAL wszUserAgent AS WSTRINGZ * 260
   LOCAL wszServerName AS WSTRINGZ * 260
   LOCAL wszVerb AS WSTRINGZ * 260
   LOCAL strOutBuffer AS STRING

   dwSize = 4  ' size of a DWORD

   ' Use WinHttpOpen to obtain a session handle.
   wszUserAgent = "A WinHTTP Example Program/1.0"
   hSession = WinHttpOpen(wszUserAgent, _
                          %WINHTTP_ACCESS_TYPE_DEFAULT_PROXY, _
                          BYVAL %WINHTTP_NO_PROXY_NAME, _
                          BYVAL %WINHTTP_NO_PROXY_BYPASS, _
                          0)

   ' Specify an HTTP server.
   IF hSession THEN
      wszServerName = "www.microsoft.com"
      hConnect = WinHttpConnect(hSession, _
                                wszServerName, _
                                %INTERNET_DEFAULT_HTTP_PORT, _
                                0)
   END IF


   ' Create an HTTP Request handle.
   IF hConnect THEN
      wszVerb = "GET"
      hRequest = WinHttpOpenRequest(hConnect, _
                                    wszVerb, _
                                    BYVAL %NULL,  _
                                    BYVAL %NULL, _
                                    BYVAL %WINHTTP_NO_REFERER, _
                                    BYVAL %WINHTTP_DEFAULT_ACCEPT_TYPES, _
                                    0)
   END IF

   ' Send a Request.
   ' Note: The Microsoft C example uses WINHTTP_FLAG_SECURE for the last
   ' parameter, but I have changed it to 0 because, otherwise, it returns
   ' error 12175 (ERROR_WINHTTP_SECURE_FAILURE)
   IF hRequest THEN
      bResults = WinHttpSendRequest(hRequest, _
                                    BYVAL %WINHTTP_NO_ADDITIONAL_HEADERS, _
                                    0, _
                                    %WINHTTP_NO_REQUEST_DATA, _
                                    0, _
                                    0, _
                                    0)
   END IF

   ' End the request.
   IF bResults THEN
      bResults = WinHttpReceiveResponse(hRequest, %NULL)
   END IF

   ' Keep checking for data until there is nothing left.
   IF bResults THEN
      DO
         ' Check for available data.
         dwSize = 0
         IF ISFALSE WinHttpQueryDataAvailable(hRequest, dwSize) THEN
            PRINT "Error " GetLastError " in WinHttpQueryDataAvailable."
            EXIT DO
         ELSE
            ' Allocate space for the buffer.
            strOutBuffer = STRING$(dwSize + 1, $NUL)
            ' Read the data.
            IF ISFALSE WinHttpReadData(hRequest, STRPTR(strOutBuffer), _
                                       dwSize, dwDownloaded) THEN
               PRINT "Error " GetLastError " in WinHttpReadData."
            ELSE
               STDOUT strOutBuffer
            END IF
         END IF
      LOOP WHILE dwSize > 0
   END IF

   ' Report any errors.
   IF ISFALSE bResults THEN
      PRINT "Error " GetLastError " has occurred."
   END IF

   ' Close open handles.
   IF hRequest THEN WinHttpCloseHandle(hRequest)
   IF hConnect THEN WinHttpCloseHandle(hConnect)
   IF hSession THEN WinHttpCloseHandle(hSession)

   WAITKEY$

END FUNCTION
' ========================================================================================
