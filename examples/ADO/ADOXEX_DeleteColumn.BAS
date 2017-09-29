' ########################################################################################
' Microsoft Windows
' File: ADOXEX_DeleteColumn.bas
' Contents: ADOX example
' Demonstrates how to delete a column (Field in ADO lingo) from a table.
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
   LOCAL pTables AS ADOXTables
   LOCAL pTable AS ADOXTable
   LOCAL pColumns AS ADOXColumns
   LOCAL pConnection AS ADOConnection
   LOCAL vConnection AS VARIANT
   LOCAL ConStr AS WSTRING
   LOCAL HRESULT AS LONG

   ' // Create a Catalog object
   pCatalog = NEWCOM "ADOX.Catalog"
   IF ISNOTHING(pCatalog) THEN EXIT FUNCTION

   TRY
      ' // Set the ActiveConnection property of the Catalog
      pCatalog.ActiveConnection = "Provider=Microsoft.Jet.OLEDB.4.0;Data Source=biblio.mdb"
      ' // Get a pointer to the Tables collection
      pTables = pCatalog.Tables
      ' // Get a pointer to the table "Contacts4"
      pTable = pTables.Item("Contacts4")
      ' // Get a pointer to the Columns collection
      pColumns = pTable.Columns
      ' // Delete the "Notes" column from the collection
      ' --> change it as needed <--
      pColumns.Delete "Notes"
      ? "Column deleted"
   CATCH
      HRESULT = OBJRESULT
      ' // Display error information
      vConnection = pCatalog.ActiveConnection
      pConnection = vConnection
      ? AdoGetErrorInfo(pConnection, HRESULT)
      vConnection = EMPTY
      pConnection = NOTHING
   FINALLY
      ' // Release objects and collections
      pColumns = NOTHING
      pTable = NOTHING
      pTables = NOTHING
   END TRY

   ' // Release the Catalog object
   pCatalog = NOTHING

   #IF %DEF(%PB_CC32)
      WAITKEY$
   #ENDIF

END FUNCTION
' ========================================================================================
