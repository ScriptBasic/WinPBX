' ========================================================================================
' The following example shows how to open an HTTP connection, send an HTTP request, and
' read the response body.
' ========================================================================================

#COMPILE EXE
#DIM ALL
#DEBUG ERROR ON
#INCLUDE "httprequest.inc"
#INCLUDE "ole2utils.inc"

' ========================================================================================
' Main
' ========================================================================================
FUNCTION PBMAIN

   LOCAL pWHttp AS IWinHttpRequest
   LOCAL vBody AS VARIANT
   LOCAL nBytes AS LONG
   LOCAL buffer AS STRING
   DIM   vByteArray(0) AS BYTE
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
      ' Get the response body
      vBody = pWHttp.ResponseBody
      ' Convert the variant to an array of bytes
      vByteArray() = vBody
      ' Convert the array of bytes to a string
      nBytes = UBOUND(vByteArray) - LBOUND(vByteArray) + 1
      IF nBytes THEN
         buffer = PEEK$(VARPTR(vByteArray(0)), nBytes)
         MSGBOX buffer
      END IF
   CATCH
      OleShowErrorInfo OBJRESULT
   END TRY

END FUNCTION
' ========================================================================================
