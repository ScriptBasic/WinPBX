' ########################################################################################
' Microsoft Windows
' File: ADOEX_SchemaTables2.bas
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
#INCLUDE ONCE "oaidl.inc"

FUNCTION AdoTableExists (BYVAL pConnection AS ADOCOnnection, BYVAL strTableName AS STRING) AS LONG

   LOCAL pRecordset AS ADORecordset
   LOCAL vRes AS VARIANT

   ' // Create a SafeArray with four elements
   DIM rgsabound AS SAFEARRAYBOUND
   DIM psa AS DWORD
   rgsabound.lLBound = 1
   rgsabound.cElements = 4
   psa = SafeArrayCreate(%VT_VARIANT, 1, rgsabound)

   ' Explanation:
   ' In the SchemaEnum of the ADO documentation you will find that
   ' %adSchemaColumns has four possible constrains:
   ' TABLE_CATALOG
   ' TABLE_SCHEMA
   ' TABLE_NAME
   ' TABLE_TYPE
   ' We are going to constrain by the table name and table type.
   ' The non-used elements of the array must be filled with and EMPTY variant.

   DIM vPrm AS VARIANT
   DIM vEmpty AS VARIANT
   DIM ix AS LONG
   ix = 1 : SafeArrayPutElement(psa, ix, vEmpty)
   ix = 2 : SafeArrayPutElement(psa, ix, vEmpty)
   vPrm = strTableName AS WSTRING
   ix = 3 : SafeArrayPutElement(psa, ix, vPrm)
   vPrm = "Table" AS WSTRING
   ix = 4 : SafeArrayPutElement(psa, ix, vPrm)

   ' // Insert the SafeArray into a variant
   DIM vCriteria AS VARIANT
   DIM lpv AS VARIANTAPI PTR
   lpv = VARPTR(vCriteria)
   @lpv.vt = %VT_ARRAY OR %VT_VARIANT
   @lpv.vd.parray = psa

   ' // Open the schema
   pRecordset = pConnection.OpenSchema(%adSchemaTables, vCriteria)

   ' // Destroy the SafeArray
   vCriteria = EMPTY

   IF ISNOTHING(pRecordset) THEN EXIT FUNCTION

   vRes = pRecordset.Collect("TABLE_NAME")
   IF UCASE$(VARIANT$$(vRes)) = UCASE$(strTableName) THEN FUNCTION = %TRUE

   ' // Close and release the recordset
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

   ' // Release the Connection object
   pConnection = NOTHING

   #IF %DEF(%PB_CC32)
      WAITKEY$
   #ENDIF

END FUNCTION
' ========================================================================================
