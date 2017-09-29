' ########################################################################################
' Microsoft Windows
' File: ADOXEX_TableExists.bas
' Contents: ADOX example
' Checks if a table exists in the database
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
' Checks if a table exists in the database
' ========================================================================================
FUNCTION ADOX_TableExists (BYVAL pConnection AS ADOConnection, BYVAL bstrTableName AS WSTRING) AS LONG

   LOCAL pCatalog AS ADOXCatalog
   LOCAL pTables AS ADOXTables
   LOCAL pTable AS ADOXTable
   LOCAL nCount AS LONG
   LOCAL i AS LONG

   IF ISNOTHING(pConnection) THEN EXIT FUNCTION

   ' // Create a Catalog object
   pCatalog = NEWCOM "ADOX.Catalog"
   IF ISNOTHING(pCatalog) THEN EXIT FUNCTION

   ' // Set the ActiveConnection property of the Catalog
   pCatalog.putref_ActiveConnection = pConnection
   ' // Get a reference to the Tables collection
   pTables = pCatalog.Tables
   ' // Get the number of objects of the collection
   nCount = pTables.Count
   IF nCount = 0 THEN EXIT FUNCTION
   pTable = pTables.Item(bstrTableName)
   IF ISTRUE ISOBJECT(pTable) THEN FUNCTION = %TRUE
   pTable = NOTHING
   ' // Release the collection
   pTables = NOTHING

   ' // Release the Catalog object
   pCatalog = NOTHING

END FUNCTION
' ========================================================================================

' ========================================================================================
' Main
' ========================================================================================
FUNCTION PBMAIN

   LOCAL pConnection AS ADOConnection
   LOCAL ConStr AS WSTRING

   ' // Create a Connection object
   pConnection = NEWCOM "ADODB.Connection"
   IF ISNOTHING(pConnection) THEN EXIT FUNCTION

   TRY
      ' // Connection String - Change it if needed
      ConStr = "Provider=Microsoft.Jet.OLEDB.4.0;Data Source=biblio.mdb"
      ' // Open the connection
      pConnection.Open ConStr
      IF ADOX_TableExists(pConnection, "Publishers") THEN
         ? "Table exists"
      ELSE
         ? "Table doesn't exist"
      END IF
   CATCH
      ' // Display error information
      ? AdoGetErrorInfo(pConnection, OBJRESULT)
   END TRY

   ' // Release the connection
   pConnection = NOTHING

   #IF %DEF(%PB_CC32)
      WAITKEY$
   #ENDIF

END FUNCTION
' ========================================================================================
