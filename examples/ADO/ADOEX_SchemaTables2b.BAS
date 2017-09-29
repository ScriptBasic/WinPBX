' ########################################################################################
' Microsoft Windows
' File: ADOEX_SchemaTables2b.bas
' Contents: ADO example
' Demonstrates the use of OpenSchema with the %adSchemaTables query.
' Checks if a table exists in a database.
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

FUNCTION AdoTableExists (BYVAL pConnection AS ADOCOnnection, BYVAL strTableName AS STRING) AS LONG

   LOCAL pRecordset AS ADORecordset
   LOCAL vRes AS VARIANT
   LOCAL vCriteria AS VARIANT
   DIM   vCriteriaArray(1 TO 4) AS VARIANT

   ' // Create a SafeArray with four elements
   vCriteriaArray(1) = EMPTY
   vCriteriaArray(2) = EMPTY
   vCriteriaArray(3) = strTableName
   vCriteriaArray(4) = "Table"
   vCriteria = vCriteriaArray()

   ' // Open the schema
   pRecordset = pConnection.OpenSchema(%adSchemaTables, vCriteria)
   IF ISNOTHING(pRecordset) THEN EXIT FUNCTION

   vRes = pRecordset.Collect("TABLE_NAME")
   IF UCASE$(VARIANT$$(vRes)) = UCASE$(strTableName) THEN FUNCTION = %TRUE

   ' // Close and releases the recordset
   pRecordset.Close
   pRecordset = NOTHING

END FUNCTION

' ========================================================================================
' Main
' ========================================================================================
FUNCTION PBMAIN

   LOCAL pConnection AS ADOConnection
   LOCAL pRecordset AS ADORecordset
   LOCAL ConStr AS WSTRING
   LOCAL vRes AS VARIANT

   ' // Create a Connection object
   pConnection = NEWCOM "ADODB.Connection"
   IF ISNOTHING(pConnection) THEN EXIT FUNCTION

   TRY
      ' // Connection String - Change it if needed
      ConStr = "Provider=Microsoft.Jet.OLEDB.4.0;Data Source=biblio.mdb"
      ' // Open the connection
      pConnection.Open ConStr
      ' // Check if Publishers table exists
      IF ISTRUE AdoTableExists(pConnection, "Publishers") THEN
         ? "Table exists"
      ELSE
         ? "Table doesn't exist"
      END IF
   CATCH
      ' // Display error information
      ? AdoGetErrorInfo(pConnection, OBJRESULT)
   FINALLY
      ' // Close the connection
      IF pConnection.State = %adStateOpen THEN pConnection.Close
   END TRY

   ' // Releases the Connection object
   pConnection = NOTHING

   #IF %DEF(%PB_CC32)
      WAITKEY$
   #ENDIF

END FUNCTION
' ========================================================================================
