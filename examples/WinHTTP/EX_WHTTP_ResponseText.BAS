' ========================================================================================
' The following example shows how to open an HTTP connection, send an HTTP request, and
' read the response text.
' ========================================================================================

#COMPILE EXE
#DIM ALL
#INCLUDE "httprequest.inc"
#INCLUDE "ole2utils.inc"

' ========================================================================================
' Main
' ========================================================================================
FUNCTION PBMAIN

   LOCAL pWHttp AS IWinHttpRequest
   LOCAL strResponseText AS WSTRING
   LOCAL iSucceeded AS INTEGER

   ' Creates an instance of the HTTP service
   pWHttp = NEWCOM "WinHttp.WinHttpRequest.5.1"
   IF ISNOTHING(pWHttp) THEN EXIT FUNCTION

   TRY
      ' Opens an HTTP connection to an HTTP resource
      pWHttp.Open "GET", "http://www.powerbasic.com"
      ' Sends an HTTP request to the HTTP server
      pWHttp.Send
      ' Wait for response with a timeout of 5 seconds
      iSucceeded = pWHttp.WaitForResponse(5)
      ' Gets the response entity body as a string
      strResponseText = pWHttp.ResponseText
      MSGBOX strResponseText
   CATCH
      OleShowErrorInfo OBJRESULT
   END TRY

END FUNCTION
' ========================================================================================
