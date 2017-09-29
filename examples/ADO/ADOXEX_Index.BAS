' ########################################################################################
' Microsoft Windows
' File: ADOXEX_Index.bas
' Contents: ADOX example
' The following code demonstrates how to create a new index.
' The index is on two columns in the table.
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

   LOCAL pCatalog AS ADOXCatalog
   LOCAL pTable AS ADOXTable
   LOCAL pTables AS ADOXTables
   LOCAL pIndex AS ADOXIndex
   LOCAL pIndexes AS ADOXIndexes
   LOCAL pColumns AS ADOXColumns
   LOCAL pIdxColumns AS ADOXColumns
   LOCAL pConnection AS ADOConnection
   LOCAL vConnection AS VARIANT
   LOCAL HRESULT AS LONG

   ' // Create a Catalog object
   pCatalog = NEWCOM "ADOX.Catalog"
   IF ISNOTHING(pCatalog) THEN EXIT FUNCTION

   ' // Create a Table object
   pTable = NEWCOM "ADOX.Table"
   IF ISNOTHING(pTable) THEN EXIT FUNCTION

   ' // Create an Index object
   pIndex = NEWCOM "ADOX.Index"
   IF ISNOTHING(pIndex) THEN EXIT FUNCTION

   TRY
      ' // Set the ActiveConnection property of the Catalog
      pCatalog.ActiveConnection = "Provider=Microsoft.Jet.OLEDB.4.0;Data Source=biblio.mdb"
      ' // Set the name of the table
      pTable.Name = "myTable"
      ' // Append fields to the new table
      pColumns = pTable.Columns
      pColumns.Append "Column1", %adInteger
      pColumns.Append "Column2", %adInteger
      ' // Note: If you are using Jet 3.51 instead of 4.0 use %adVarChar
      pColumns.Append "Column3", %adVarWChar, 50
      ' // Append the new table
      pTables = pCatalog.Tables
      pTables.Append pTable
      ' // Define a multicolumn index
      pIndex.Name = "multicolidx"
      pIdxColumns = pIndex.Columns
      pIdxColumns.Append "Column1", %adVarWChar
      pIdxColumns.Append "Column2", %adVarWChar
      ' // Append the index to the table
      pIndexes = pTable.Indexes
      pIndexes.Append pIndex
   CATCH
      HRESULT = OBJRESULT
      ' // Display error information
      vConnection = pCatalog.ActiveConnection
      pConnection = vConnection
      ? AdoGetErrorInfo(pConnection, HRESULT)
      vConnection = EMPTY
      pConnection = NOTHING
   FINALLY
      ' // Delete the table as this is a demonstration
      IF ISTRUE ISOBJECT(pTables) THEN
         pTables.Delete "MyTable"
         ? "MyTable deleted"
      END IF
      ' // Release objects and collections
      pIdxColumns = NOTHING
      pColumns = NOTHING
      pIndexes = NOTHING
      pTables = NOTHING
   END TRY

   ' // Release the main objects
   pIndex = NOTHING
   pTable = NOTHING
   pCatalog = NOTHING

   #IF %DEF(%PB_CC32)
      WAITKEY$
   #ENDIF

END FUNCTION
' ========================================================================================
