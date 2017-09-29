' ########################################################################################
' Microsoft Windows
' File: ADOEX_Fields.bas
' Contents: ADO example
' Opens a connection, creates a recordset and parses the result.
' This example uses the Fields collection and the Field object instead of the Collect
' method to retrieve the information.
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
   LOCAL pFields AS ADOFields
   LOCAL pField AS ADOField
   LOCAL ConStr AS WSTRING
   LOCAL SqlStr AS WSTRING
   LOCAL vRes1, vRes2, vRes3 AS VARIANT

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
      ' // Open the recordset
      SqlStr = "SELECT * FROM Publishers ORDER BY PubID"
      pRecordset.Open SqlStr, pConnection, %adOpenKeyset, %adLockOptimistic, %adCmdText
      ' // Get a reference to the Fields collection
      pFields = pRecordset.Fields
      ' // Parse the recordset
      DO
         ' // While not at the end of the recordset...
         IF pRecordset.EOF THEN EXIT DO
         pField = pFields.Item("PubID")
         vRes1 = pField.Value
         pField = pFields.Item("Name")
         vRes2 = pField.Value
         pField = pFields.Item("Company Name")
         vRes3 = pField.Value
         ? VARIANT$$(vRes1) & " " & VARIANT$$(vRes2) & " " & VARIANT$$(vRes3)
         pField = NOTHING
         ' // Fetch the next row
         pRecordset.MoveNext
      LOOP
      ' // Release the collection
      pFields = NOTHING
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
