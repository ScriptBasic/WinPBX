' ########################################################################################
' Microsoft Windows
' File: ADOEX_SchemaTables.bas
' Contents: ADO example
' Demonstrates the use of OpenSchema with the %adSchemaTables query.
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

' ========================================================================================
' Main
' ========================================================================================
FUNCTION PBMAIN

   LOCAL pConnection AS ADOConnection
   LOCAL pRecordset AS ADORecordset
   LOCAL ConStr AS WSTRING
   LOCAL vRes AS VARIANT
   LOCAL d  AS ASCIIZ * 64
   LOCAL st AS SYSTEMTIME
   LOCAL vbDate AS DOUBLE

   ' // Create a Connection object
   pConnection = NEWCOM "ADODB.Connection"
   IF ISNOTHING(pConnection) THEN EXIT FUNCTION

   TRY
      ' // Connection String - Change it if needed
      ConStr = "Provider=Microsoft.Jet.OLEDB.4.0;Data Source=biblio.mdb"
      ' // Open the connection
      pConnection.Open ConStr
      ' // Create a SafeArray with two elements
      DIM rgsabound AS SAFEARRAYBOUND
      DIM psa AS DWORD
      rgsabound.lLBound = 1
      rgsabound.cElements = 2
      psa = SafeArrayCreate(%VT_VARIANT, 1, rgsabound)
      ' -------------------------------------------------------------------------
      ' Explanation:
      ' %adSchemaColumns has four possible constrains:
      ' TABLE_CATALOG
      ' TABLE_SCHEMA
      ' TABLE_NAME
      ' TABLE_TYPE
      ' We are going to constrain by the table type, that is the fourth element.
      ' The non-used elements of the array must be filled with and EMPTY variant.
      ' -------------------------------------------------------------------------
      DIM vPrm AS VARIANT
      DIM vEmpty AS VARIANT
      DIM ix AS LONG
      ix = 1 : SafeArrayPutElement(psa, ix, vEmpty)
      ix = 2 : SafeArrayPutElement(psa, ix, vEmpty)
      ix = 3 : SafeArrayPutElement(psa, ix, vEmpty)
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
      ' // Parse the recordset
      pRecordset.MoveFirst
      DO
         ' // While not at the end of the recordset...
         IF pRecordset.EOF THEN EXIT DO
         vRes = pRecordset.Collect("TABLE_CATALOG")
         ? "Table catalog: " & VARIANT$$(vRes)
         vRes = pRecordset.Collect("TABLE_SCHEMA")
         ? "Table schema: " & VARIANT$$(vRes)
         vRes = pRecordset.Collect("TABLE_NAME")
         ? "Table name: " & VARIANT$$(vRes)
         vRes = pRecordset.Collect("TABLE_TYPE")
         ? "Table type: " & VARIANT$$(vRes)
         vRes = pRecordset.Collect("TABLE_GUID")
         ? "Table guid: " & GUIDTXT$(VARIANT$$(vRes))
         vRes = pRecordset.Collect("DESCRIPTION")
         ? "Table description: " & VARIANT$$(vRes)
         vRes = pRecordset.Collect("TABLE_PROPID")
         ? "Table propid: " & STR$(VARIANT#(vRes))
         vRes = pRecordset.Collect("DATE_CREATED")
         vbDate = VARIANT#(vRes)
         VariantTimeToSystemTime vbdate, st
         GetDateFormat 0, 1, st, BYVAL %NULL, d, 64
         ? "Date created: " & d
         vRes = pRecordset.Collect("DATE_MODIFIED")
         vbDate = VARIANT#(vRes)
         VariantTimeToSystemTime vbdate, st
         GetDateFormat 0, 1, st, BYVAL %NULL, d, 64
         ? "Date modified: " & d
         #IF %DEF(%PB_CC32)
         WAITKEY$
         CLS
         #ENDIF
         ' // Fetch the next row
         pRecordset.MoveNext
      LOOP
   CATCH
      ' // Display error information
      ? AdoGetErrorInfo(pConnection, OBJRESULT)
   FINALLY
      IF ISOBJECT(pRecordset) THEN
         ' // Close the recordset
         IF pRecordset.State = %adStateOpen THEN pRecordset.Close
      END IF
      ' // Close the connection
      IF pConnection.State = %adStateOpen THEN pConnection.Close
   END TRY

   #IF %DEF(%PB_CC32)
      WAITKEY$
   #ENDIF

END FUNCTION
' ========================================================================================
