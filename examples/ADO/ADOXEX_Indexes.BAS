' ########################################################################################
' Microsoft Windows
' File: ADOXEX_Indexes.bas
' Contents: ADOX example
' Parses the Indexes collection of a Table and shows the name of the Primary Key and the
' columns that make up the index.
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
   LOCAL pCatalog AS ADOXCatalog
   LOCAL pTables AS ADOXTables
   LOCAL pTable AS ADOXTable
   LOCAL pIndexes AS ADOXIndexes
   LOCAL pIndex AS ADOXIndex
   LOCAL pColumns AS ADOXColumns
   LOCAL pColumn AS ADOXColumn
   LOCAL ConStr AS STRING
   LOCAL vCommand AS VARIANT
   LOCAL IdxCount AS LONG
   LOCAL ColCount AS LONG
   LOCAL i AS LONG
   LOCAL x AS LONG

   ' // Create a Connection object
   pConnection = NEWCOM "ADODB.Connection"
   IF ISNOTHING(pConnection) THEN EXIT FUNCTION

   ' // Create a Catalog object
   pCatalog = NEWCOM "ADOX.Catalog"
   IF ISNOTHING(pCatalog) THEN EXIT FUNCTION

   TRY
      ' // Connection String - Change it if needed
      ConStr = "Provider=Microsoft.Jet.OLEDB.4.0;Data Source=biblio.mdb"
      ' // Open the connection
      pConnection.Open ConStr
      ' // Set the ActiveConnection property of the Catalog
      pCatalog.putref_ActiveConnection = pConnection
      ' // Get a reference to the Tables collection
      pTables = pCatalog.Tables
      ' // Get the Table object
      pTable = pTables.Item("Authors")
      ' // Get a reference to the Indexes collection
      pIndexes = pTable.Indexes
      pTable = NOTHING
      ' // Retrieve the number of objects in the collection
      IdxCount = pIndexes.Count
      IF IdxCount = 0 THEN EXIT TRY
      FOR i = 0 TO IdxCount - 1
         pIndex = pIndexes.Item(i)
         IF ISTRUE pIndex.PrimaryKey THEN
            ? "Index name: " & pIndex.Name
            pColumns = pIndex.Columns
            ColCount = pColumns.Count
            FOR x = 0 TO ColCount - 1
               pColumn = pColumns.Item(i)
               ? "Column name: " & pColumn.Name
               pColumn = NOTHING
            NEXT
            pColumns = NOTHING
         END IF
         pIndex = NOTHING
      NEXT
   CATCH
      ' // Display error information
      ? AdoGetErrorInfo(pConnection, OBJRESULT)
   FINALLY
      ' // Release the collections
      pIndexes = NOTHING
      pTables = NOTHING
      ' // Close the connection
      IF pConnection.State = %adStateOpen THEN pConnection.Close
   END TRY

   ' // Release the objects
   pCatalog = NOTHING
   pConnection = NOTHING

   #IF %DEF(%PB_CC32)
      WAITKEY$
   #ENDIF

END FUNCTION
' ========================================================================================
