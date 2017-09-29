' ########################################################################################
' Microsoft Windows
' File: ADOXEX_RenameTable.bas
' Contents: ADOX example
' Demonstrates how to rename a table using ADOX.
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
   LOCAL ConStr AS WSTRING

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
      ' // Get a reference to the Contacts3 table
      pTable = pTables.Item("Authors")
      pTable.Name = "Authors2"
      ? "Table renamed"
   CATCH
      ' // Display error information
      ? AdoGetErrorInfo(pConnection, OBJRESULT)
   FINALLY
      ' // Release the Table object and the Tables collection
      pTable = NOTHING
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
