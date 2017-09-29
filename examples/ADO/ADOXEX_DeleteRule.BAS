' ########################################################################################
' Microsoft Windows
' File: ADOXEX_DeleteRule.bas
' Contents: ADOX example
' This example demonstrates the DeleteRule property of a Key object. The code appends a
' new Table and then defines a new primary key, setting DeleteRule to adRICascade.
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
   LOCAL pKeyColumns AS ADOXColumns
   LOCAL pKeyColumn AS ADOXColumn
   LOCAL pPrimaryKey AS ADOXKey
   LOCAL pKeys AS ADOXKeys
   LOCAL pConnection AS ADOConnection
   LOCAL vConnection AS VARIANT
   LOCAL HRESULT AS LONG

   ' // Create a Catalog object
   pCatalog = NEWCOM "ADOX.Catalog"
   IF ISNOTHING(pCatalog) THEN EXIT FUNCTION

   ' // Create a Table object
   pTable = NEWCOM "ADOX.Table"
   IF ISNOTHING(pTable) THEN EXIT FUNCTION

   ' // Create a Key object
   pPrimaryKey = NEWCOM "ADOX.Key"
   IF ISNOTHING(pPrimaryKey) THEN EXIT FUNCTION

   TRY
      ' // Set the ActiveConnection property of the Catalog
      pCatalog.ActiveConnection = "Provider=Microsoft.Jet.OLEDB.4.0;Data Source=biblio.mdb"
      ' // Set the name of the new table
      pTable.Name = "NewTable"
      ' // Append a numeric and a text field to the new table
      pColumns = pTable.Columns
      pColumns.Append "NumField", %adInteger
      ' // Note: If you are using Jet 3.51 instead of 4.0 use %adVarChar
      pColumns.Append "TextField", %adVarWChar, 20
      ' // Append the new table
      pTables = pCatalog.Tables
      pTables.Append pTable
      ' // Define the primary key
      pPrimaryKey.Name = "NumField"
      pPrimaryKey.Type = %adKeyPrimary
      pPrimaryKey.RelatedTable = "Title Author"
      pKeyColumns = pPrimaryKey.Columns
      pKeyColumns.Append "NumField", %adVarWChar
      pKeyColumn = pKeyColumns.Item("NumField")
      pKeyColumn.RelatedColumn = "Au_ID"
      pPrimaryKey.DeleteRule = %adRICascade
      ' // Append the primary key
      pKeys = pTable.Keys
      pKeys.Append pPrimaryKey
   CATCH
      HRESULT = OBJRESULT
      ' // Display error information
      vConnection = pCatalog.ActiveConnection
      pConnection = vConnection
      ? AdoGetErrorInfo(pConnection, HRESULT)
      vConnection = EMPTY
      pConnection = NOTHING
   FINALLY
      ' // Delete the table as this is a demo
      IF ISTRUE ISOBJECT(pTables) THEN
         pTables.Delete "NewTable"
         ? "NewTable deleted"
      END IF
      ' // Release objects and collections
      pKeys = NOTHING
      pKeyColumn = NOTHING
      pKeyColumns = NOTHING
      pColumns = NOTHING
      pTable = NOTHING
      pTables = NOTHING
   END TRY

   ' // Release the main objects
   pPrimaryKey = NOTHING
   pTable = NOTHING
   pCatalog = NOTHING

   #IF %DEF(%PB_CC32)
      WAITKEY$
   #ENDIF

END FUNCTION
' ========================================================================================
