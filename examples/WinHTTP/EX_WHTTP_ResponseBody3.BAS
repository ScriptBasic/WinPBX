' ========================================================================================
' The following example shows how to open an HTTP connection, send an HTTP request, and
' read the response body. The downloaded image, returned as an array of bytes, is saved
' into a file.
' ========================================================================================

' SED_PBWIN - Use he PBWIN compiler
#COMPILE EXE
#DIM ALL
#INCLUDE "httprequest.inc"
#INCLUDE "ole2utils.inc"

' ========================================================================================
' Main
' ========================================================================================
FUNCTION PBMAIN

   LOCAL pWHttp AS IWinHttpRequest
   LOCAL vBody AS VARIANT
   DIM   vByteArray(0) AS BYTE
   LOCAL iSucceeded AS INTEGER

   ' Creates an instance of the HTTP service
   pWHttp = NEWCOM "WinHttp.WinHttpRequest.5.1"
   IF ISNOTHING(pWHttp) THEN EXIT FUNCTION

   TRY
      ' Opens an HTTP connection to an HTTP resource
      pWHttp.Open "GET", "http://www.microsoft.com/library/homepage/images/ms-banner.gif"
      ' Sends an HTTP request to the HTTP server
      pWHttp.Send
      ' Wait for response with a timeout of 5 seconds
      iSucceeded = pWHttp.WaitForResponse(5)
      ' Get the response body
      vBody = pWHttp.ResponseBody
      IF OBJRESULT = %S_OK THEN
         ' Convert the variant to an array of bytes
         vByteArray() = vBody
         ' Save the array into a file
         OPEN "ms-banner.gif" FOR BINARY AS #1
         PUT #1, 1, vByteArray()
         CLOSE #1
         MSGBOX "File saved"
      END IF
   CATCH
      OleShowErrorInfo OBJRESULT
   END TRY

END FUNCTION
' ========================================================================================
