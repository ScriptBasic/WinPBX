' ########################################################################################
' Microsoft Windows
' File: ADOXEX_CreateTable.bas
' Contents: ADOX example
' Demonstrates how to create a new table and append it to the Database collection.
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

   ' // Create a Table object
   pTable = NEWCOM "ADOX.Table"
   IF ISNOTHING(pTable) THEN EXIT FUNCTION

   TRY
      ' // Set the ActiveConnection property of the Catalog
      pCatalog.ActiveConnection = "Provider=Microsoft.Jet.OLEDB.4.0;Data Source=biblio.mdb"
      ' // Get a pointer to the Tables collection
      pTables = pCatalog.Tables
      ' // Create a new table called "Contacts"
      pTable.Name = "Contacts"
      ' // Create fields and appends them to the Columns collection of the new Table object
      ' // Note that in ADOX the ADO Fields are called Columns
      pColumns = pTable.Columns
      pColumns.Append "FirstName", %adVarWChar
      pColumns.Append "LastName", %adVarWChar
      pColumns.Append "Phone", %adVarWChar
      pColumns.Append "Notes", %adLongVarWChar
      ' // Add the new Table to the Tables collection of the database
      pTables.Append pTable
      ? "Table created"
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
