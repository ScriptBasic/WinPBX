' ########################################################################################
' Microsoft Windows
' File: DAO.inc
' Contents: Master include file for DAO 3.6
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%DAO_INC = 1

#INCLUDE ONCE "windows.inc"
#INCLUDE ONCE "dbdaoerr.inc"
#INCLUDE ONCE "dbdaoint.inc"

' ========================================================================================
' Retrieves rich information from the DAO Errors collection.
' When an DAO call returns a result code you can call this function. If pErrors is true,
' then it is an error returned by the provider else it must be a Windows error.
' ========================================================================================
FUNCTION DaoGetErrorInfo (BYVAL pDbEngine AS DAODBEngine, BYVAL dwError AS DWORD) AS WSTRING

   LOCAL pErrors AS DAOErrors         ' // Pointer to the Errors collection
   LOCAL pError AS DAOError           ' // Pointer to the Error object
   LOCAL nCount AS LONG               ' // Number of errors
   LOCAL i AS LONG                    ' // Loop counter variable
   LOCAL bstrErrorText AS WSTRING     ' // String to return the result
   LOCAL cbMsgLen AS DWORD            ' // Length of the message
   LOCAL pBuffer AS WSTRINGZ PTR      ' // Pointer to the buffer

   IF ISNOTHING(pDbEngine) THEN EXIT FUNCTION
   IF dwError = 0 THEN EXIT FUNCTION

   ' Get a reference to the Errors collection
   pErrors = pDbEngine.Errors
   IF ISOBJECT(pErrors) THEN
      ' Number of errors
      nCount = pErrors.Count
      ' Show all the errors (the collection is zero-based)
      FOR i = 0 TO nCount - 1
         ' Retrieve the Error object
         pError = pErrors.Item(i)
         ' Show his properties
         IF ISOBJECT(pError) THEN
            bstrErrorText += "Number: " & FORMAT$(pError.Number) & $CRLF
            bstrErrorText += "Source: " & pError.Source & $CRLF
            bstrErrorText += "Description: " & pError.Description & $CRLF
            bstrErrorText += "Help file: " & pError.HelpFile & $CRLF
            bstrErrorText += "Help context: " & FORMAT$(pError.HelpContext)
         END IF
         ' Release the Error object
         pError = NOTHING
      NEXT
      ' Release the Errors collection
      pErrors = NOTHING
      ' Return the error information
      IF nCount THEN
         FUNCTION = bstrErrorText
         EXIT FUNCTION
      END IF
   END IF

   ' See if it is a Windows error
   cbMsgLen = FormatMessageW(%FORMAT_MESSAGE_ALLOCATE_BUFFER OR _
              %FORMAT_MESSAGE_FROM_SYSTEM OR %FORMAT_MESSAGE_IGNORE_INSERTS, _
              BYVAL %NULL, dwError, BYVAL MAKELANGID(%LANG_NEUTRAL, %SUBLANG_DEFAULT), _
              BYVAL VARPTR(pBuffer), 0, BYVAL %NULL)
   IF cbMsgLen THEN
      bstrErrorText = "Windows error" & $CRLF
      bstrErrorText = bstrErrorText & "Error code :" & FORMAT$(dwError) & " [&H" & HEX$(dwError, 8) & "]"
      bstrErrorText = bstrErrorText & "Description: " & @pBuffer
      LocalFree pBuffer
   ELSE
      bstrErrorText = "DAO Runtime error " & FORMAT$(dwError) & " [&H" & HEX$(dwError, 8) & "]"
   END IF

   FUNCTION = bstrErrorText

END FUNCTION
' ========================================================================================
