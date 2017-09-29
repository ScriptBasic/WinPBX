' ########################################################################################
' Microsoft Windows
' File: ADOEX_SchemaProviderTypes2b.bas
' Contents: ADO example
' Demonstrates the use of OpenSchema with the %adSchemaProviderTypes query.
' Also demonstrates how to constrain the query to an specified type.
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
   LOCAL vCriteria AS VARIANT
   DIM   vCriteriaArray(1 TO 2) AS VARIANT

   ' // Create a Connection object
   pConnection = NEWCOM "ADODB.Connection"
   IF ISNOTHING(pConnection) THEN EXIT FUNCTION

   TRY
      ' // Connection String - Change it if needed
      ConStr = "Provider=Microsoft.Jet.OLEDB.4.0;Data Source=biblio.mdb"
      ' // Open the connection
      pConnection.Open ConStr
      ' // Put in it the value 131 to constrain the query to the decimal type
      vCriteriaArray(1) = 131 AS WORD
      vCriteriaArray(2) = EMPTY
      vCriteria = vCriteriaArray()
      ' // Open the schema
      pRecordset = pConnection.OpenSchema(%adSchemaProviderTypes, vCriteria)
      ' // Parse the recordset
      pRecordset.MoveFirst
      DO
         ' // While not at the end of the recordset...
         IF pRecordset.EOF THEN EXIT DO
         vRes = pRecordset.Collect("TYPE_NAME")
         ? "Type name: " & VARIANT$$(vRes)
         vRes = pRecordset.Collect("DATA_TYPE")
         ? "Data type: " & STR$(VARIANT#(vRes))
         vRes = pRecordset.Collect("COLUMN_SIZE")
         ? "Column size: " & STR$(VARIANT#(vRes))
         vRes = pRecordset.Collect("LITERAL_PREFIX")
         ? "Literal prefix: " & VARIANT$$(vRes)
         vRes = pRecordset.Collect("LITERAL_SUFFIX")
         ? "Literal suffix: " & VARIANT$$(vRes)
         vRes = pRecordset.Collect("CREATE_PARAMS")
         ? "Create params: " & VARIANT$$(vRes)
         vRes = pRecordset.Collect("IS_NULLABLE")
         ? "Is nullable: " & STR$(CINT(VARIANT#(vRes)))
         vRes = pRecordset.Collect("CASE_SENSITIVE")
         ? "Case sensitive: " & STR$(CINT(VARIANT#(vRes)))
         vRes = pRecordset.Collect("SEARCHABLE")
         ? "Searchable: " & STR$(VARIANT#(vRes))
         vRes = pRecordset.Collect("UNSIGNED_ATTRIBUTE")
         ? "Unsigned attribute: " & STR$(CINT(VARIANT#(vRes)))
         vRes = pRecordset.Collect("FIXED_PREC_SCALE")
         ? "Fixed precision scale: " & STR$(CINT(VARIANT#(vRes)))
         vRes = pRecordset.Collect("AUTO_UNIQUE_VALUE")
         ? "Auto unique value: " & STR$(CINT(VARIANT#(vRes)))
         vRes = pRecordset.Collect("LOCAL_TYPE_NAME")
         ? "Local type name: " & VARIANT$$(vRes)
         vRes = pRecordset.Collect("MINIMUM_SCALE")
         ? "Minimum scale: " & STR$(VARIANT#(vRes))
         vRes = pRecordset.Collect("MAXIMUM_SCALE")
         ? "Maximum scale: " & STR$(VARIANT#(vRes))
         vRes = pRecordset.Collect("GUID")
         ? "Guid: " & GUIDTXT$(VARIANT$$(vRes))
         vRes = pRecordset.Collect("TYPELIB")
         ? "Typelib: " & VARIANT$$(vRes)
         vRes = pRecordset.Collect("VERSION")
         ? "Version: " & VARIANT$$(vRes)
         vRes = pRecordset.Collect("IS_LONG")
         ? "Is long: " & STR$(CINT(VARIANT#(vRes)))
         vRes = pRecordset.Collect("BEST_MATCH")
         ? "Best match: " & STR$(CINT(VARIANT#(vRes)))
         vRes = pRecordset.Collect("IS_FIXEDLENGTH")
         ? "Is fixed length: " & STR$(CINT(VARIANT#(vRes)))
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
