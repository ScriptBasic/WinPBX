' ########################################################################################
' Microsoft Windows
' File: ADOEX_Transactions.bas
' Contents: ADO example
' Demonstrates the use of BeginTrans, CommitTrans and RollbackTrans.
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
      ' // Open the recordset
      SqlStr = "SELECT * FROM Authors"
      pRecordset.Open SqlStr, pConnection, %adOpenKeyset, %adLockOptimistic, %adCmdText
      ' // Begin a transaction
      pConnection.BeginTrans
      DO
         ' // While not at the end of the recordset...
         IF pRecordset.EOF THEN EXIT DO
         vRes = pRecordset.Collect("Year Born")
         ? STR$(VARIANT#(vRes))
         IF VARIANT#(vRes) = 1947 THEN
            pRecordset.Collect("Year Born") = 1900
         END IF
         ' // Fetch the next row
         pRecordset.MoveNext
      LOOP
      ' // Commit the transaction
'      pConnection.CommitTrans
      ' // Rollback the transaction because this is a demo
      pConnection.RollbackTrans
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
