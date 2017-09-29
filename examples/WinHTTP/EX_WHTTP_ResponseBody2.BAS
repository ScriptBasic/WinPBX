' ========================================================================================
' The following example shows how to open an HTTP connection, send an HTTP request, and
' read the response body.
' Same as EX_WHTTP_ResponseBody.bas, but using the safe array API functions.
' ========================================================================================

#COMPILE EXE
#DIM ALL
#DEBUG ERROR ON
#INCLUDE "httprequest.inc"
#INCLUDE "oaidl.inc"          ' for tagVARIANT structure
#INCLUDE "ole2utils.inc"

' ========================================================================================
' Main
' ========================================================================================
FUNCTION PBMAIN

   LOCAL pWHttp AS IWinHttpRequest
   LOCAL vBody AS VARIANT
   LOCAL nBytes AS LONG
   LOCAL buffer AS STRING
   LOCAL pv AS tagVARIANT PTR
   LOCAL nDims AS LONG
   LOCAL nLBound AS LONG
   LOCAL nUBound AS LONG
   LOCAL pData AS DWORD
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
      ' Get a pointer to the returned safearray
      pv = VARPTR(vBody)
      IF @pv.parray THEN
         ' Retrieve the number of dimensions (must be 1)
         nDims = SafeArrayGetDim(@pv.parray)
         IF nDims = 1 THEN
            ' Retrieve the number of elements of the array
            SafeArrayGetLBound(@pv.parray, 1, nLBound)
            SafeArrayGetUBound(@pv.parray, 1, nUBound)
            ' Calculate the number of bytes to read
            nBytes = nUbound - nLBound + 1
            IF nBytes THEN
               ' Lock the safearray for access
               SafeArrayAccessData(@pv.parray, pData)
               IF pData THEN
                  ' Read the data
                  buffer = PEEK$(pData, nBytes)
                  ' Unlock the array
                  SafeArrayUnaccessData(@pv.parray)
                  ' Show the data
                  MSGBOX buffer
               END IF
            END IF
         END IF
      END IF
   CATCH
      OleShowErrorInfo OBJRESULT
   END TRY

END FUNCTION
' ========================================================================================
