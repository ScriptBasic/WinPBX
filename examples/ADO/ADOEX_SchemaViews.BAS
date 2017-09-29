' ########################################################################################
' Microsoft Windows
' File: ADOEX_SchemaViews.bas
' Contents: ADO example
' Demonstrates the use of OpenSchema with the %adSchemaViews query.
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
#INCLUDE ONCE "OleAuto.inc"

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
      ' // Open the schema
      pRecordset = pConnection.OpenSchema(%adSchemaViews)
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
         vRes = pRecordset.Collect("VIEW_DEFINITION")
         ? "View definition: " & VARIANT$$(vRes)
         vRes = pRecordset.Collect("CHECK_OPTION")
         ? "Check option: " & STR$(CINT(VARIANT#(vRes)))
         vRes = pRecordset.Collect("IS_UPDATABLE")
         ? "Is updatable: " & STR$(CINT(VARIANT#(vRes)))
         vRes = pRecordset.Collect("DESCRIPTION")
         ? "Description: " & VARIANT$$(vRes)
         vRes = pRecordset.Collect("DATE_CREATED")
         vbDate = VARIANT#(vRes)
         VariantTimeToSystemTime vbdate, st
         GetDateFormat 0, 1, st, BYVAL %NULL, d, 64
         ? "Datecreated: " & d
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
