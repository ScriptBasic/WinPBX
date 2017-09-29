' ########################################################################################
' Microsoft Windows
' File: ADOEX_ReadExcelSheet2.bas
' Contents: ADO example
' Compilers: PBWIN 10+, PBCC 6+
' Headers: Windows API headers 3.0+
' Copyright (c) 2012 José Roca. Freeware. Use at your own risk.
' Portions Copyright (c) Microsoft Corporation. All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

' ########################################################################################
' Demonstrates how to open an excel sheet and parse it as if it where a recordset.
' To solve the problem that the name of the sheet is localized ("Sheet", in English,
' "Hoja", in Spanish, etc.), first we use the OpenSchema method to retrieve the names of
' the excel sheets; then we open a recordset for each sheet, retrieve the number of columns
' and read them.
' Assumes that the first row contains the names of the columns and that all the rows have
' the same number of columns.
' ########################################################################################

#COMPILE EXE
#DIM ALL
#INCLUDE ONCE "ADO.INC"

' ========================================================================================
' Main
' ========================================================================================
FUNCTION PBMAIN

   LOCAL hr AS DWORD
   LOCAL pConnection AS ADOConnection
   LOCAL pRecordset AS ADORecordset
   LOCAL pFields AS ADOFields
   LOCAL ConStr AS WSTRING
   LOCAL SqlStr AS WSTRING
   LOCAL vRes AS VARIANT
   LOCAL c AS LONG
   LOCAL i AS LONG
   LOCAL x AS LONG
   DIM   TablesArray() AS STRING

   ' // Create a Connection object
   pConnection = NEWCOM "ADODB.Connection"
   IF ISNOTHING(pConnection) THEN EXIT FUNCTION

   TRY
      ' // Connection String - Change it if needed
      ConStr = "Provider=MSDASQL;Driver={Microsoft Excel Driver (*.xls)};DBQ=test3.xls;ReadOnly=False"
      ' // Open the connection
      pConnection.Open ConStr
      ' // Open the schema
      pRecordset = pConnection.OpenSchema(%adSchemaTables)
      pRecordset.MoveFirst
      DO
         ' // While not at the end of the recordset...
         IF pRecordset.EOF THEN EXIT DO
         vRes = pRecordset.Collect("TABLE_NAME")
         ? "Table Name = " & VARIANT$$(vRes)
         REDIM PRESERVE TablesArray(UBOUND(TablesArray) + 1)
         TablesArray(UBOUND(TablesArray)) = VARIANT$$(vRes)
         ' // Fetch the next row
         pRecordset.MoveNext
      LOOP
      ' // Close the recordset
      pRecordset.Close
      #IF %DEF(%PB_CC32)
      PRINT "-----------------------------------"
      #ENDIF
      ' // Open a recordset for each sheet
      IF UBOUND(TablesArray) > -1 THEN
         FOR i = LBOUND(TablesArray) TO UBOUND(TablesArray)
            SqlStr = "SELECT * FROM [" & TablesArray(i) & "]"
            pRecordset.Open SqlStr, pConnection, %adOpenStatic, -1, -1
            ' // Get a reference to the Fields collection
            pFields = pRecordset.Fields
            ' // Number of fields (columns)
            c = pFields.Count
            ' // Release the Fields collection
            pFields = NOTHING
            DO
               ' // While not at the end of the recordset...
               IF pRecordset.EOF THEN EXIT DO
               ' // Get the content of the columns
               FOR x = 0 TO c - 1
                  vRes = EMPTY
                  vRes = pRecordset.Collect(x)
                  IF VARIANTVT(vRes) = %VT_BSTR THEN
                     ? VARIANT$$(vRes)
                  ELSE
                     ? STR$(VARIANT#(vRes))
                  END IF
               NEXT
               ' // Fetch the next row
               pRecordset.MoveNext
            LOOP
            ' // Close the recordset
            pRecordset.Close
            #IF %DEF(%PB_CC32)
            PRINT "-----------------------------------"
            #ENDIF
         NEXT
      END IF
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
