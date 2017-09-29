' ########################################################################################
' Microsoft Windows
' File: ADOEX_Execute.bas
' Contents: ADO example
' Demonstrates the Execute method when run from a Command object.
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
   LOCAL pCommand AS ADOCommand
   LOCAL pRecordset AS ADORecordset
   LOCAL ConStr AS WSTRING
   LOCAL SqlStr AS WSTRING
   LOCAL vRes AS VARIANT

   ' // Create a Connection object
   pConnection = NEWCOM "ADODB.Connection"
   IF ISNOTHING(pConnection) THEN EXIT FUNCTION

   ' // Create a Command object
   pCommand = NEWCOM "ADODB.Command"
   IF ISNOTHING(pCommand) THEN EXIT FUNCTION

   TRY
      ' // Connection String - Change it if needed
      ConStr = "Provider=Microsoft.Jet.OLEDB.4.0;Data Source=biblio.mdb"
      ' // Open the connection
      pConnection.Open ConStr
      ' // Set the active connection
      pCommand.putref_ActiveConnection = pConnection
      ' // Set the CommandText property
      SqlStr = "SELECT TOP 20 * FROM Authors ORDER BY Author"
      pCommand.CommandText = SqlStr
      ' // Create the recordset
      pRecordset = pCommand.Execute
      DO
         ' // While not at the end of the recordset...
         IF pRecordset.EOF THEN EXIT DO
         ' // Get the content of the "Author" column
         vRes = pRecordset.Collect("Author")
         ? VARIANT$$(vRes)
         ' // Fetch the next row
         pRecordset.MoveNext
      LOOP
   CATCH
      ' // Display error information
      ? AdoGetErrorInfo(pConnection, OBJRESULT)
   FINALLY
      ' // Close and release the recordset
      IF ISOBJECT(pRecordset) THEN
         IF pRecordset.State = %adStateOpen THEN pRecordset.Close
         pRecordset = NOTHING
      END IF
      ' // Close the connection
      IF pConnection.State = %adStateOpen THEN pConnection.Close
   END TRY

   #IF %DEF(%PB_CC32)
      WAITKEY$
   #ENDIF

END FUNCTION
' ========================================================================================
