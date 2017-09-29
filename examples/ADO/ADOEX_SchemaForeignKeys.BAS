' ########################################################################################
' Microsoft Windows
' File: ADOEX_SchemaForeignKeys.bas
' Contents: ADO example
' Demonstrates the use of OpenSchema with the %adSchemaForeignKeys query.
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
      pRecordset = pConnection.OpenSchema(%adSchemaForeignKeys)
      pRecordset.MoveFirst
      DO
         ' // While not at the end of the recordset...
         IF pRecordset.EOF THEN EXIT DO
         vRes = pRecordset.Collect("FK_TABLE_CATALOG")
         ? "Table catalog: " & VARIANT$$(vRes)
         vRes = pRecordset.Collect("FK_TABLE_SCHEMA")
         ? "Table schema: " & VARIANT$$(vRes)
         vRes = pRecordset.Collect("FK_TABLE_NAME")
         ? "Table name: " & VARIANT$$(vRes)
         vRes = pRecordset.Collect("FK_COLUMN_NAME")
         ? "Column name: " & VARIANT$$(vRes)
         vRes = pRecordset.Collect("FK_COLUMN_GUID")
         ? "Column guid: " & GUIDTXT$(VARIANT$$(vRes))
         vRes = pRecordset.Collect("FK_COLUMN_PROPID")
         ? "Column propid: " & STR$(VARIANT#(vRes))
         vRes = pRecordset.Collect("ORDINAL")
         ? "Ordinal: " & STR$(VARIANT#(vRes))
         vRes = pRecordset.Collect("UPDATE_RULE")
         ? "Update rule: " & VARIANT$$(vRes)
         vRes = pRecordset.Collect("DELETE_RULE")
         ? "Delete rule: " & VARIANT$$(vRes)
         vRes = pRecordset.Collect("FK_NAME")
         ? "Foreign key name: " & VARIANT$$(vRes)
         vRes = pRecordset.Collect("DEFERRABILITY")
         ? "Deferrability: " & STR$(VARIANT#(vRes))
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
