' ########################################################################################
' Microsoft Windows
' File: ADOEX_SchemaColumns.bas
' Contents: ADO example
' Demonstrates the use of OpenSchema with the %adSchemaColumns query.
' Also demonstrates how to constrain the query to an specified type.
' Returns a Columns Rowset. See the OLE DB Programmer's Reference for further information.
' Compilers: PBWIN 10+, PBCC 6+
' Headers: Windows API headers 3.0+
' Copyright (c) 2012 Jos� Roca. Freeware. Use at your own risk.
' Portions Copyright (c) Microsoft Corporation. All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#COMPILE EXE
#DIM ALL
#INCLUDE ONCE "ADO.INC"
#INCLUDE ONCE "oaidl.INC"

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
      ' // Create a SafeArray with four elements
      DIM rgsabound AS SAFEARRAYBOUND
      DIM psa AS DWORD
      rgsabound.lLBound = 1
      rgsabound.cElements = 4
      psa = SafeArrayCreate(%VT_VARIANT, 1, rgsabound)
      ' -------------------------------------------------------------------------
      ' Explanation:
      ' %adSchemaColumns has four possible constrains:
      ' TABLE_CATALOG
      ' TABLE_SCHEMA
      ' TABLE_NAME
      ' COLUMN_NAME
      ' We are going to constrain by the table name, that is the third element.
      ' The non-used elements of the array must be filled with and EMPTY variant.
      ' -------------------------------------------------------------------------
      DIM vPrm AS VARIANT
      DIM vEmpty AS VARIANT
      DIM ix AS LONG
      ix = 1 : SafeArrayPutElement(psa, ix, vEmpty)
      ix = 2 : SafeArrayPutElement(psa, ix, vEmpty)
      vPrm = "Titles" AS WSTRING
      ix = 3 : SafeArrayPutElement(psa, ix, vPrm)
      ix = 4 : SafeArrayPutElement(psa, ix, vEmpty)

      ' // Insert the SafeArray into a variant
      DIM vCriteria AS VARIANT
      DIM lpv AS VARIANTAPI PTR
      lpv = VARPTR(vCriteria)
      @lpv.vt = %VT_ARRAY OR %VT_VARIANT
      @lpv.vd.parray = psa
      ' // Open the schema
      pRecordset = pConnection.OpenSchema(%adSchemaColumns, vCriteria)
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
         vRes = pRecordset.Collect("COLUMN_NAME")
         ? "Column name: " & VARIANT$$(vRes)
         vRes = pRecordset.Collect("COLUMN_GUID")
         ? "Column guid: " & GUIDTXT$(VARIANT$$(vRes))
         vRes = pRecordset.Collect("COLUMN_PROPID")
         ? "Column propid: " & STR$(VARIANT#(vRes))
         vRes = pRecordset.Collect("ORDINAL_POSITION")
         ? "Ordinal position: " & STR$(VARIANT#(vRes))
         vRes = pRecordset.Collect("COLUMN_HASDEFAULT")
         ? "Column has default: " & STR$(CINT(VARIANT#(vRes)))
         vRes = pRecordset.Collect("COLUMN_DEFAULT")
         ? "Column default: " & VARIANT$$(vRes)
         vRes = pRecordset.Collect("COLUMN_FLAGS")
         ? "Column flags: " & STR$(VARIANT#(vRes))
         vRes = pRecordset.Collect("IS_NULLABLE")
         ? "Is nullable: " & STR$(CINT(VARIANT#(vRes)))
         vRes = pRecordset.Collect("DATA_TYPE")
         ? "Data Type: " & STR$( VARIANT#(vRes))
         vRes = pRecordset.Collect("TYPE_GUID")
         ? "Type guid: " & GUIDTXT$(VARIANT$$(vRes))
         vRes = pRecordset.Collect("CHARACTER_MAXIMUM_LENGTH")
         ? "Character maximum length: " & STR$(VARIANT#(vRes))
         vRes = pRecordset.Collect("CHARACTER_OCTET_LENGTH")
         ? "Character octet length: " & STR$(VARIANT#(vRes))
         vRes = pRecordset.Collect("NUMERIC_PRECISION")
         ? "Numeric precision: " & STR$(VARIANT#(vRes))
         vRes = pRecordset.Collect("NUMERIC_SCALE")
         ? "Numeric scale: " & STR$(VARIANT#(vRes))
         vRes = pRecordset.Collect("DATETIME_PRECISION")
         ? "Datetime precision: " & STR$(VARIANT#(vRes))
         vRes = pRecordset.Collect("CHARACTER_SET_CATALOG")
         ? "Character set catalog: " & VARIANT$$(vRes)
         vRes = pRecordset.Collect("CHARACTER_SET_SCHEMA")
         ? "Character set schema: " & VARIANT$$(vRes)
         vRes = pRecordset.Collect("CHARACTER_SET_NAME")
         ? "Character set name: " & VARIANT$$(vRes)
         vRes = pRecordset.Collect("COLLATION_CATALOG")
         ? "Collation catalog: " & VARIANT$$(vRes)
         vRes = pRecordset.Collect("COLLATION_SCHEMA")
         ? "Collation schema: " & VARIANT$$(vRes)
         vRes = pRecordset.Collect("DOMAIN_NAME")
         ? "Domain name: " & VARIANT$$(vRes)
         vRes = pRecordset.Collect("DESCRIPTION")
         ? "Description: " & VARIANT$$(vRes)
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
