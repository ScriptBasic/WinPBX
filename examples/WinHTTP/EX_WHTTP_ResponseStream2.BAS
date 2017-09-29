' ========================================================================================
' The following example shows how to open an HTTP connection, send an HTTP request, and
' read the response as an IStream. The data from the IStream is written to a file.
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
   LOCAL vSTream AS VARIANT
   LOCAL pIStream AS IStream
   LOCAL tstatstg AS STATSTG
   LOCAL strBuffer AS STRING
   LOCAL cb AS DWORD
   LOCAL cbRead AS DWORD
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
      ' Get the response as a stream
      vStream = pWHttp.ResponseStream
      IF VARIANTVT(vStream) = %VT_UNKNOWN THEN
         pIStream = vStream
         vStream = EMPTY
         ' Get the size of the stream
         pIStream.Stat(tstatstg, %STATFLAG_NONAME)
         ' Use a string as a buffer
         strBuffer = SPACE$(tstatstg.cbsize)
         ' Read the stream
         pIStream.Read STRPTR(strBuffer), LEN(strBuffer), cbRead
         IF cbRead < tstatstg.cbsize THEN strBuffer = LEFT$(strBuffer, cbRead)
         pIStream = NOTHING
         ' Save the buffer into a file
         OPEN "ms-banner.gif" FOR BINARY AS #1
         PUT #1, 1, strBuffer
         CLOSE #1
         MSGBOX "File saved"
      END IF
   CATCH
      OleShowErrorInfo OBJRESULT
   END TRY

END FUNCTION
' ========================================================================================
