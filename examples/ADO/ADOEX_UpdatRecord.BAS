' ########################################################################################
' Microsoft Windows
' File: ADOEX_UpdatRecord.bas
' Contents: ADO example
' Demonstrates the use of the Update method.
' Note: Changed Update to Updat in the program name because the UAC triggers if certain
' words are used.
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
   LOCAL v1 AS VARIANT
   LOCAL v2 AS VARIANT
   DIM   vFieldList(2) AS VARIANT
   DIM   vValues(2) AS VARIANT

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
      ' // Retrieve the record to update
      SqlStr = "SELECT * FROM Publishers WHERE PubID=10000"
      pRecordset.Open SqlStr, pConnection, %adOpenKeyset, %adLockOptimistic, %adCmdText
      vRes = pRecordset.Collect("PubID")
      IF VARIANT#(vRes) = 10000 THEN
         ' // Fills the array of fields
         vFieldList(0) = "Company Name"
         vFieldList(1) = "Address"
         vFieldList(2) = "City"
         ' // Fill the array of values
         vValues(0) = "MGM Studios"
         vValues(1) = "10250 Constellation Boulevard"
         vValues(2) = "Los Angeles, CA. 90067"
         ' // Store the arrays in variants
         v1 = vFieldList()
         v2 = vValues()
         pRecordset.Update v1, v2
         ? "Record updated"
      ELSE
         ? "Record not found"
      END IF
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
