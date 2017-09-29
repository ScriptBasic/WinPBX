' ########################################################################################
' Microsoft Windows
' File: ADOXEX_Properties.bas
' Contents: ADOX example
' Enumerates the properties of the Name column of the BIBLIO.MDB database.
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
#INCLUDE ONCE "AfxVarToStr.inc"

' ========================================================================================
' Main
' ========================================================================================
FUNCTION PBMAIN

   LOCAL pConnection AS ADOConnection
   LOCAL pCatalog AS ADOXCatalog
   LOCAL pTables AS ADOXTables
   LOCAL pTable AS ADOXTable
   LOCAL pColumns AS ADOXColumns
   LOCAL pColumn AS ADOXColumn
   LOCAL pProperties AS ADOProperties
   LOCAL pProperty AS ADOProperty
   LOCAL ConStr AS WSTRING
   LOCAL nCount AS LONG
   LOCAL i AS LONG
   LOCAL vValue AS VARIANT

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
      ' // Get the number of objects of the collection
      nCount = pTables.Count
      IF nCount = 0 THEN EXIT TRY
      ' // Get a pointer to the table "Publishers"
      pTable = pTables.Item("Publishers")
      ' // Get a pointer to the Columns collection of the table
      pColumns = pTable.Columns
      pTable = NOTHING
      ' // Get the number of objects in the Columns collection for that table
      nCount = pColumns.Count
      IF nCount = 0 THEN EXIT TRY
      ' // Enumerate all the objects
      FOR i = 0 TO nCount - 1
         pColumn = pColumns.Item(i)
         ? "Column name: " & pColumn.Name
         ? "Defined size: " & STR$(pColumn.DefinedSize)
         ? "Type: " & STR$(pColumn.Type)
         ? "Attributes: " & STR$(pColumn.Attributes)
         pColumn = NOTHING
      NEXT
      ' // Get a pointer to the "Name" column
      pColumn = pColumns.Item("Name")
      ' // Get a pointer to his properties collection
      pProperties = pColumn.Properties
      nCount = pProperties.Count
      pColumn = NOTHING
      ' // Enumerate the properties
      #IF %DEF(%PB_CC32)
      ? "-----------------------------------------------------"
      ? "Properties of the Name column: "
      ? "-----------------------------------------------------"
      #ENDIF
      FOR i = 0 TO nCount - 1
         pProperty = pProperties.Item(i)
         ? "Property name: " & pProperty.Name
         vValue = pProperty.Value
         ? "Value: " & AfxVarToStr(vValue)
         ? "Type: " & STR$(pProperty.Type)
         ? "Attributes: " & STR$(pProperty.Attributes)
         pProperty = NOTHING
      NEXT
   CATCH
      ' // Display error information
      ? AdoGetErrorInfo(pConnection, OBJRESULT)
   FINALLY
      ' // Release the collections
      pProperties = NOTHING
      pColumns = NOTHING
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
