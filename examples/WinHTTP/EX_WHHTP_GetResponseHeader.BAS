' ========================================================================================
' The following example shows how to open an HTTP connection, send an HTTP request, and
' get the date header from the response.
' ========================================================================================

#COMPILE EXE
#DIM ALL
#INCLUDE ONCE "httprequest.inc"
#INCLUDE ONCE "ole2utils.inc"

' ========================================================================================
' Main
' ========================================================================================
FUNCTION PBMAIN

   LOCAL pWHttp AS IWinHttpRequest
   LOCAL bstrResponseHeader AS WSTRING
   LOCAL iSucceeded AS INTEGER

   ' Creates an instance of the HTTP service
   pWHttp = NEWCOM "WinHttp.WinHttpRequest.5.1"
   IF ISNOTHING(pWHttp) THEN EXIT FUNCTION

   TRY
      ' Opens an HTTP connection to an HTTP resource
      pWHttp.Open "GET", "http://microsoft.com"
      ' Sends an HTTP request to the HTTP server
      pWHttp.Send
      ' Wait for response with a timeout of 5 seconds
      iSucceeded = pWHttp.WaitForResponse(5)
      ' Get the response headers
      bstrResponseHeader = pWHttp.GetResponseHeader("Date")
      MSGBOX bstrResponseHeader
   CATCH
      OleShowErrorInfo OBJRESULT
   END TRY

END FUNCTION
' ========================================================================================
