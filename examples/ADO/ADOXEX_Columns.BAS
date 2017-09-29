' ########################################################################################
' Microsoft Windows
' File: ADOXEX_Columns.bas
' Contents: ADOX example
' Demonstrates how to retrieve the names of the columns of a table.
' Uses the BIBLIO.MDB database that comes with Visual Studio.
' Note  For some reason, ADOX retuns the columns collection ordered by Column name.
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
#DEBUG ERROR ON
#INCLUDE ONCE "ADO.INC"

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
   LOCAL ConStr AS WSTRING
   LOCAL nCount AS LONG
   LOCAL i AS LONG

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
      ' // Get a reference to the Publishers table
      pTable = pTables.Item("Publishers")
      ' // Get a reference to the Columns collection of the table
      pColumns = pTable.Columns
      ' // Get the number of objects in the collection
      nCount = pColumns.Count
      IF nCount = 0 THEN EXIT TRY
      ' // Parse the collection
      FOR i = 0 TO nCount - 1
         pColumn = pColumns.Item(i)
         ? pColumn.Name
         pColumn = NOTHING
      NEXT
   CATCH
      ' // Display error information
      ? AdoGetErrorInfo(pConnection, OBJRESULT)
   FINALLY
      ' // Release the Columns collection
      pColumns = NOTHING
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
