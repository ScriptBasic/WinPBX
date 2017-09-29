' ########################################################################################
' Microsoft Windows
' File: ADOEX_AddNewRecod.bas
' Contents: ADO example
' This example uses the AddNew method to create a new record.
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
   LOCAL bConStr AS WSTRING
   LOCAL bSqlStr AS WSTRING
   LOCAL v1 AS VARIANT
   LOCAL v2 AS VARIANT
   DIM   vFieldList(4) AS VARIANT
   DIM   vValues(4) AS VARIANT

   ' // Create a Connection object
   pConnection = NEWCOM "ADODB.Connection"
   IF ISNOTHING(pConnection) THEN EXIT FUNCTION

   ' // Create a Recordset object
   pRecordset = NEWCOM "ADODB.Recordset"
   IF ISNOTHING(pRecordset) THEN EXIT FUNCTION

   TRY
      ' // Connection String - Change it if needed
      bConStr = "Provider=Microsoft.Jet.OLEDB.4.0;Data Source=biblio.mdb"
      ' // Open the connection
      pConnection.Open bConStr
      ' // Open the recordset
      bSqlStr = "Publishers"
      pRecordset.Open bSqlStr, pConnection, %adOpenKeyset, %adLockOptimistic, %adCmdTableDirect
      ' // Fill the array of fields
      vFieldList(0) = "PubID"
      vFieldList(1) = "Name"
      vFieldList(2) = "Company Name"
      vFieldList(3) = "Address"
      vFieldList(4) = "City"
      ' // Fill the array of values
      vValues(0) = 10000 AS LONG
      vValues(1) = "Wile E. Coyote"
      vValues(2) = "Warner Brothers Studios"
      vValues(3) = "4000 Warner Boulevard"
      vValues(4) = "Burbank, CA. 91522"
      ' // Store the arrays in variants
      v1 = vFieldList()
      v2 = vValues()
      ' // Add the record
      pRecordset.AddNew v1, v2
      ? "Record added"
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
