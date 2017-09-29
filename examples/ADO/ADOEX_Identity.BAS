' ########################################################################################
' Microsoft Windows
' File: ADOEX_Identity.bas
' Contents: ADO example
' Compilers: PBWIN 10+, PBCC 6+
' Headers: Windows API headers 3.0+
' Copyright (c) 2012 José Roca. Freeware. Use at your own risk.
' Portions Copyright (c) Microsoft Corporation. All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

' ########################################################################################
' How do I get the AutoNumber (or Identity) for a newly inserted record?
' The AutoNumber field should always be available when a server-side cursor is used.
' However, if a client-side cursor location is used, then the AutoNumber field is only
' returned immediately when an Access 2000 database is used with OLE DB Provider for
' Jet 4.0 driver (or with the Jet 4.0 ODBC driver).
' http://support.microsoft.com/kb/q244136/
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
   LOCAL pProperties AS ADOProperties
   LOCAL pProperty AS ADOProperty
   LOCAL ConStr AS WSTRING
   LOCAL SqlStr AS WSTRING
   LOCAL vRes AS VARIANT
   DIM   vFieldList(2) AS VARIANT
   DIM   vValues(2) AS VARIANT

   ' // Create a Connection object
   pConnection = NEWCOM "ADODB.Connection"
   IF ISNOTHING(pConnection) THEN EXIT FUNCTION

   ' // Create a Command object
   pRecordset = NEWCOM "ADODB.Recordset"
   IF ISNOTHING(pRecordset) THEN EXIT FUNCTION

   TRY
      ' // Connection String - Change it if needed
      ConStr = "Provider=Microsoft.Jet.OLEDB.4.0;Data Source=biblio.mdb"
      ' // Open the connection
      pConnection.Open ConStr
      ' // Set the cursor location
      pRecordset.CursorLocation = %adUseClient
      ' // Get a reference to the Properties collection
      pProperties = pRecordset.Properties
      pProperty = pProperties.Item("Update Resync")
      pProperty.Value = %adResyncAutoIncrement
      ' // Open the recordset
      SqlStr = "SELECT * FROM Contacts2"
      pRecordset.Open SqlStr, pConnection, %adOpenStatic, %adLockBatchOptimistic, %adCmdText
      ' // Add a record
      vFieldList(0) = "FirstName"
      vFieldList(1) = "LastName"
      vFieldList(2) = "Phone"
      vValues(0) = "John"
      vValues(1) = "Smith"
      vValues(2) = "(111)111-1111"
      LOCAL v1 AS VARIANT, v2 AS VARIANT
      v1 = vFieldList()
      v2 = vValues()
      pRecordset.AddNew v1, v2
      pRecordset.Update   ' // Update local Recordset (since %adLockBatchOptimistic)
      ' // Add another record
      vValues(0) = "Jack"
      vValues(1) = "Sparrow"
      vValues(2) = "(222)222-2222"
      v2 = vValues()
      pRecordset.AddNew v1, v2
      pRecordset.Update   ' // Update local Recordset (since %adLockBatchOptimistic)
      ' // Update the Access database (4.0 format)
      pRecordset.MarshalOptions = %adMarshalModifiedOnly
      pRecordset.UpdateBatch %adAffectAll
      ' // New autonumber for the 2nd AddNew
      vRes = pRecordset.Collect("ContactId")
      ? STR$(VARIANT#(vRes))
      ' // New autonumber for the 1st AddNew
      pRecordset.MovePrevious
      vRes = pRecordset.Collect("ContactId")
      ? STR$(VARIANT#(vRes))
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
