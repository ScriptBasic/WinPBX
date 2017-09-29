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

   ' First, use WinHttpQueryHeaders to obtain the size of the buffer.
   IF bResults THEN
      WinHttpQueryHeaders(hRequest, %WINHTTP_QUERY_RAW_HEADERS_CRLF, _
                          BYVAL %WINHTTP_HEADER_NAME_BY_INDEX, %NULL, _
                          dwSize, BYVAL %WINHTTP_NO_HEADER_INDEX)
   END IF

   ' Allocate memory for the buffer.
   IF GetLastError = %ERROR_INSUFFICIENT_BUFFER THEN
      strOutBuffer = SPACE$(dwSize)
      '  Now, use WinHttpQueryHeaders to retrieve the header.
       bResults = WinHttpQueryHeaders(hRequest, _
                                      %WINHTTP_QUERY_RAW_HEADERS_CRLF, _
                                      BYVAL %WINHTTP_HEADER_NAME_BY_INDEX, _
                                      STRPTR(strOutBuffer), dwSize, _
                                      BYVAL %WINHTTP_NO_HEADER_INDEX)
   END IF

   ' Print the header contents.
   IF bResults THEN
      STDOUT "Header contents: "
      STDOUT ACODE$(strOutBuffer)
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
