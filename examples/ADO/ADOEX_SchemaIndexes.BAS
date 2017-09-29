' ########################################################################################
' Microsoft Windows
' File: ADOEX_SchemaIndexes.bas
' Contents: ADO example
' Demonstrates the use of OpenSchema with the %adSchemaIndexes query.
' Returns a Columns Rowset. See the OLE DB Programmer's Reference for further information.
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
   LOCAL vRes AS VARIANT

   ' // Create a Connection object
   pConnection = NEWCOM "ADODB.Connection"
   IF ISNOTHING(pConnection) THEN EXIT FUNCTION

   TRY
      ' // Connection String - Change it if needed
      ConStr = "Provider=Microsoft.Jet.OLEDB.4.0;Data Source=biblio.mdb"
      ' // Open the connection
      pConnection.Open ConStr
      ' // Open the schema
      pRecordset = pConnection.OpenSchema(%adSchemaIndexes)
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
         vRes = pRecordset.Collect("INDEX_CATALOG")
         ? "Index catalog: " & VARIANT$$(vRes)
         vRes = pRecordset.Collect("INDEX_SCHEMA")
         ? "Index schema: " & VARIANT$$(vRes)
         vRes = pRecordset.Collect("INDEX_NAME")
         ? "Index name: " & VARIANT$$(vRes)
         vRes = pRecordset.Collect("PRIMARY_KEY")
         ? "Primary key: " & STR$(CINT(VARIANT#(vRes)))
         vRes = pRecordset.Collect("UNIQUE")
         ? "Unique: " & STR$(CINT(VARIANT#(vRes)))
         vRes = pRecordset.Collect("CLUSTERED")
         ? "Clustered: " & STR$(CINT(VARIANT#(vRes)))
         vRes = pRecordset.Collect("TYPE")
         ? "Type: " & STR$(VARIANT#(vRes))
         vRes = pRecordset.Collect("FILL_FACTOR")
         ? "Fill factor: " & STR$(VARIANT#(vRes))
         vRes = pRecordset.Collect("INITIAL_SIZE")
         ? "Initial size: " & STR$(VARIANT#(vRes))
         vRes = pRecordset.Collect("NULLS")
         ? "Nulls: " & STR$(VARIANT#(vRes))
         vRes = pRecordset.Collect("SORT_BOOKMARKS")
         ? "Sort bookmarks: " & STR$(CINT(VARIANT#(vRes)))
         vRes = pRecordset.Collect("AUTO_UPDATE")
         ? "Auto update: " & STR$(CINT(VARIANT#(vRes)))
         vRes = pRecordset.Collect("NULL_COLLATION")
         ? "Null collation: " & STR$(VARIANT#(vRes))
         vRes = pRecordset.Collect("ORDINAL_POSITION")
         ? "Ordinal position: " & STR$(VARIANT#(vRes))
         vRes = pRecordset.Collect("COLUMN_NAME")
         ? "Column name: " & VARIANT$$(vRes)
         vRes = pRecordset.Collect("COLUMN_GUID")
         ? "Column guid: " & GUIDTXT$(VARIANT$$(vRes))
         vRes = pRecordset.Collect("COLUMN_PROPID")
         ? "Column propid: " & STR$(VARIANT#(vRes))
         vRes = pRecordset.Collect("COLLATION")
         ? "Collation: " & STR$(VARIANT#(vRes))
         vRes = pRecordset.Collect("CARDINALITY")
         ? "Cardinality: " & STR$(VARIANT#(vRes))
         vRes = pRecordset.Collect("PAGES")
         ? "Pages: " & STR$(VARIANT#(vRes))
         vRes = pRecordset.Collect("FILTER_CONDITION")
         ? "Filter condition: " & VARIANT$$(vRes)
         vRes = pRecordset.Collect("INTEGRATED")
         ? "Integrated: " & STR$(CINT(VARIANT#(vRes)))
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
