' ########################################################################################
' Microsoft Windows
' File: ADOEX_AbsolutePosition.bas
' Contents: ADO example
' This example demonstrates how the AbsolutePosition property can track the progress of a
' loop that enumerates all the records of a Recordset. It uses the CursorLocation property
' to enable the AbsolutePosition property by setting the cursor to a client cursor.
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
      ' // Set the cursor location
      pRecordset.CursorLocation = %adUseClient
      ' // Open the recordset
      SqlStr = "Publishers"
      pRecordset.Open SqlStr, pConnection, %adOpenStatic, %adLockOptimistic, %adCmdTable
      DO
        ' // While not at the end of the recordset...
         IF pRecordset.EOF THEN EXIT DO
         ' // Get the absolute position and the Publisher's name
         vRes = pRecordset.Collect("Name")
         ? "Position:" & STR$(pRecordset.AbsolutePosition) & " " & VARIANT$$(vRes)
         ' // Fetch the next row
         pRecordset.MoveNext
      LOOP
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
