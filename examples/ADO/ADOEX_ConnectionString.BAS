' ########################################################################################
' Microsoft Windows
' File: ADOEX_ConnectionString.bas
' Contents: ADO example
' Demonstrates the use of the ConnectionString, ActiveConnection and Source properties.
' Opens a connection with the biblio.mdb database, creates a recordset and parses the result.
' Instead of using  ADORecordset.Open, this example sets the properties individually.
' It also uses the Source property to show an alternate way to set the source for the recordset.
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
   LOCAL vOpt AS VARIANT

   vOpt = ERROR %DISP_E_PARAMNOTFOUND

   ' // Create a Connection object
   pConnection = NEWCOM "ADODB.Connection"
   IF ISNOTHING(pConnection) THEN EXIT FUNCTION

   ' // Create a Recordset object
   pRecordset = NEWCOM "ADODB.Recordset"
   IF ISNOTHING(pRecordset) THEN EXIT FUNCTION

   TRY
      ' // Connection String - Change it if needed
      ConStr = "Provider=Microsoft.Jet.OLEDB.4.0;Data Source=biblio.mdb"
      ' // Set the connection string
      pConnection.ConnectionString = Constr
      ' // Open the database
      pConnection.Open
      ' // Set the recordset's active connection
      pRecordset.putref_ActiveConnection = pConnection
      ' // Set the cursor location
      pRecordset.CursorLocation = %adUseClient
      ' *** The cursor type and lock type can't be set individually
      ' *** when using direct interface calls because the call to the
      ' *** Open method will reset them to 0.
      ' // Set the cursor type
'      pRecordset.CursorType = %adOpenKeyset
      ' // Set the lock type
'      pRecordset.LockType = %adLockOptimistic
      ' // Set the source for the recordset
      SqlStr = "SELECT * FROM Authors ORDER BY Author"
      pRecordset.Source = SqlStr
      ' // Open the recordset
      pRecordset.Open vOpt, vOpt, %adOpenKeyset, %adLockOptimistic
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
