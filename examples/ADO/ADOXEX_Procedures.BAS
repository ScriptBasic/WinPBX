' ########################################################################################
' Microsoft Windows
' File: ADOXEX_Procedures.bas
' Contents: ADOX example
' Enumerates the Procedures collection.
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
#INCLUDE ONCE "AfxVarToStr.inc"

' ========================================================================================
' Main
' ========================================================================================
FUNCTION PBMAIN

   LOCAL pConnection AS ADOConnection
   LOCAL pCatalog AS ADOXCatalog
   LOCAL pProcedures AS ADOXPRocedures
   LOCAL pProcedure AS ADOXProcedure
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
      ' // Get a reference to the Procedures collection
      pProcedures = pCatalog.Procedures
      ' // Retrieve the number of objects in the collection
      nCount = pProcedures.Count
      IF nCount = 0 THEN EXIT TRY
      FOR i = 0 TO nCount - 1
         pProcedure = pProcedures.Item(i)
         ? "Procedure name: " & pProcedure.Name & $CRLF & _
           "Date created: " & AfxVarToStr(pProcedure.DateCreated)
         pProcedure = NOTHING
      NEXT
   CATCH
      ' // Display error information
      ? AdoGetErrorInfo(pConnection, OBJRESULT)
   FINALLY
      ' // Release the collection
      pProcedures = NOTHING
      ' // Close the connection
      IF pConnection.State = %adStateOpen THEN pConnection.Close
   END TRY

   '//  Release the objects
   pCatalog = NOTHING
   pConnection = NOTHING

   #IF %DEF(%PB_CC32)
      WAITKEY$
   #ENDIF

END FUNCTION
' ========================================================================================
