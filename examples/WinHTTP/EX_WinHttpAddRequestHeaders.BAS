' ========================================================================================
' The following example shows how to obtain an HINTERNET handle, open an HTTP session,
' create and send a request header, and examine the returned response header.
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
   LOCAL dwStatusCode AS DWORD
   LOCAL bResults AS LONG
   LOCAL hSession AS DWORD
   LOCAL hConnect AS DWORD
   LOCAL hRequest AS DWORD
   LOCAL wszUserAgent AS WSTRINGZ * 260
   LOCAL wszServerName AS WSTRINGZ * 260
   LOCAL wszVerb AS WSTRINGZ * 260
   LOCAL wszHeaders AS WSTRINGZ * 260

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

   ' Add a request header.
   IF hRequest THEN
      wszHeaders = "If-Modified-Since: Mon, 20 Nov 2000 20:00:00 GMT"
      bResults = WinHttpAddRequestHeaders(hRequest, _
                                          wszHeaders, _
                                          -1, _
                                          %WINHTTP_ADDREQ_FLAG_ADD)
   END IF

   ' Send a Request.
   IF bResults THEN
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

   ' Use WinHttpQueryHeaders to obtain the header buffer.
   IF bResults THEN
      bResults = WinHttpQueryHeaders(hRequest, _
                                     %WINHTTP_QUERY_STATUS_CODE OR %WINHTTP_QUERY_FLAG_NUMBER, _
                                     BYVAL %NULL, _
                                     VARPTR(dwStatusCode), _
                                     dwSize, _
                                     %WINHTTP_NO_HEADER_INDEX)
   END IF

   ' Based on the status code, determine whether
   ' the document was recently updated.
   IF bResults THEN
      IF dwStatusCode = 304 THEN
         PRINT "Document has not been updated."
      ELSEIF dwStatusCode = 200 THEN
         PRINT "Document has been updated."
      ELSE
         PRINT "Status code =" dwStatusCode
      END IF
   END IF

   ' Report any errors.
   IF ISFALSE bResults THEN
      PRINT "Error %d has occurred." GetLastError
   END IF

   ' Close open handles.
   IF hRequest THEN WinHttpCloseHandle(hRequest)
   IF hConnect THEN WinHttpCloseHandle(hConnect)
   IF hSession THEN WinHttpCloseHandle(hSession)

   WAITKEY$

END FUNCTION
' ========================================================================================
