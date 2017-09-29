' ########################################################################################
' Microsoft Windows
' File: ADOXEX_AppendProcedure.bas
' Contents: ADOX example
' The following example demonstrates how to use a Command object and the Procedures
' collection Append method to create a new procedure in the underlying data source.
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
   LOCAL pCommand AS ADOCommand
   LOCAL pCatalog AS ADOXCatalog
   LOCAL pProcedures AS ADOXProcedures
   LOCAL ConStr AS WSTRING
   LOCAL bstrCommandText AS WSTRING

   ' // Create a Connection object
   pConnection = NEWCOM "ADODB.Connection"
   IF ISNOTHING(pConnection) THEN EXIT FUNCTION

   ' // Create a Command object
   pCommand = NEWCOM "ADODB.Command"
   IF ISNOTHING(pCommand) THEN EXIT FUNCTION

   ' // Create a Catalog object
   pCatalog = NEWCOM "ADOX.Catalog"
   IF ISNOTHING(pCatalog) THEN EXIT FUNCTION

   TRY
      ' // Connection String - Change it if needed
      ConStr = "Provider=Microsoft.Jet.OLEDB.4.0;Data Source=biblio.mdb"
      ' // Open the connection
      pConnection.Open ConStr
      ' // Create the parameterized command (Microsoft Jet specific)
      pCommand.putref_ActiveConnection = pConnection
      bstrCommandText = "PARAMETERS [AuthorId] Text; " & _
                       "SELECT * FROM Authors WHERE Aud_ID = [AuthorId]"
      pCommand.CommandText = bstrCommandText
      ' // Set the ActiveConnection property of the Catalog
      pCatalog.putref_ActiveConnection = pConnection
      ' // Get a reference to the Procedures collection
      pProcedures = pCatalog.Procedures
      ' // Append the procedure
      pProcedures.Append "AuthorById", pCommand
      ? "Procedure added"
   CATCH
      ' // Display error information
      ? AdoGetErrorInfo(pConnection, OBJRESULT)
   FINALLY
      ' // Release the collection
      pProcedures = NOTHING
      ' // Close the connection
      IF pConnection.State = %adStateOpen THEN pConnection.Close
   END TRY

   ' // Release the objects
   pCommand = NOTHING
   pCatalog = NOTHING
   pConnection = NOTHING

   #IF %DEF(%PB_CC32)
      WAITKEY$
   #ENDIF

END FUNCTION
' ========================================================================================
