' ########################################################################################
' Microsoft Windows
' File: ADOXEX_ParameterInfo.bas
' Contents: ADOX example
' The following code demonstrates how to use the Command property with the Command object
' to retrieve parameter information for the Procedure.
' Compilers: PBWIN 10+, PBCC 6+
' Headers: Windows API headers 3.0
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
   LOCAL pProcedures AS ADOXPRocedures
   LOCAL pProcedure AS ADOXProcedure
   LOCAL pParameters AS ADOParameters
   LOCAL pParameter AS ADOParameter
   LOCAL ConStr AS WSTRING
   LOCAL vCommand AS VARIANT
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
      ' // Get a reference to the Procedures collection
      pProcedures = pCatalog.Procedures
      ' // Get the Procedure object
      pProcedure = pProcedures.Item("AuthorById")
      ' // Get the Command
      vCommand = pProcedure.Command
      pProcedure = NOTHING
      pCommand = vCommand
      vCommand = EMPTY
      ' // Get a reference to the Parameters collection
      pParameters = pCommand.Parameters
      pCommand = NOTHING
      ' // Retrieve the number of objects in the collection
      nCount = pParameters.Count
      IF nCount = 0 THEN EXIT TRY
      FOR i = 0 TO nCount - 1
         pParameter = pParameters.Item(i)
         ? "Parameter name: " & pParameter.Name & $CRLF & _
           "Parameter type: " & STR$(pParameter.Type)
         pParameter = NOTHING
      NEXT
   CATCH
      ' // Display error information
      ? AdoGetErrorInfo(pConnection, OBJRESULT)
   FINALLY
      ' // Release the collections
      pParameters = NOTHING
      pProcedures = NOTHING
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
