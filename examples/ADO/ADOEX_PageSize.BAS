' ########################################################################################
' Microsoft Windows
' File: ADOEX_PageSize.bas
' Contents: ADO example
' Demonstrates the use of the AbsolutePage, PageCount and PageSize properties
' The cursor location must be set to %adUseClient.
' Compilers: PBWIN 10+, PBCC 6+
' Headers: Windows API headers 3.0+
' Copyright (c) 2012 José Roca. Freeware. Use at your own risk.
' Portions Copyright (c) Microsoft Corporation. All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#COMPILE EXE
#DIM ALL
#INCLUDE ONCE "ADO.INC"

' ========================================================================================
' Main
' ========================================================================================
FUNCTION PBMAIN

   LOCAL pConnection AS ADOConnection
   LOCAL pRecordset AS ADORecordset
   LOCAL ConStr AS WSTRING
   LOCAL SqlStr AS WSTRING
   LOCAL nPageCount AS LONG
   LOCAL nPageSize AS LONG
   LOCAL i AS LONG
   LOCAL x AS LONG
   LOCAL vRes AS VARIANT

   ' // Create a Connection object
   pConnection = NEWCOM "ADODB.Connection"
   IF ISNOTHING(pConnection) THEN EXIT FUNCTION

   ' // Create a Recordset object
   pRecordset = NEWCOM "ADODB.Recordset"
   IF ISNOTHING(pRecordset) THEN EXIT FUNCTION

   TRY
      ' // Connection String - Change it if needed
      ConStr = "Provider=Microsoft.Jet.OLEDB.4.0;Data Source=biblio.mdb"
      ' // Open the connection
      pConnection.Open ConStr
      ' // Use client cursor to enable AbsolutePosition property
      pRecordset.CursorLocation = %adUseClient
      ' // Open the recordset
      SqlStr = "SELECT * FROM Publishers"
      pRecordset.Open SqlStr, pConnection, %adOpenStatic, %adLockOptimistic, %adCmdText
      ' // Display five records at a time
      pRecordset.PageSize = 5
      ' // Retrieve the number of pages
      nPageCount = pRecordset.PageCount
      ' // Pars the recordset
      FOR i = 1 TO nPageCount
         ' // Set the cursor at the beginning of the page
         pRecordset.AbsolutePage = i
         ' // Retrieve the number of records of the page
         nPageSize = pRecordset.PageSize
         FOR x = 1 TO nPageSize
            ' // Get the content of the "Name" column
            vRes = pRecordset.Collect("Name")
            ? VARIANT$$(vRes)
            ' // Fetch the next row
            pRecordset.MoveNext
            IF pRecordset.EOF THEN EXIT FOR
         NEXT
         #IF %DEF(%PB_CC32)
            WAITKEY$
         #ENDIF
      NEXT
   CATCH
      ' // Display error information
      ? AdoGetErrorInfo(pConnection, OBJRESULT)
   FINALLY
      ' // Close the recordset
      IF pRecordset.State = %adStateOpen THEN pRecordset.Close
      ' // Close the connection
      IF pConnection.State = %adStateOpen THEN pConnection.Close
   END TRY

   #IF %DEF(%PB_CC32)
      WAITKEY$
   #ENDIF

END FUNCTION
' ========================================================================================
