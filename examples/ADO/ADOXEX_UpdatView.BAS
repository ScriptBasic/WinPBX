' ########################################################################################
' Microsoft Windows
' File: ADOXEX_UpdatView.bas
' Contents: ADOX example
' The following example demostrates how to use the Command property to update the text of a view.
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
   LOCAL pCommand AS ADOCommand
   LOCAL vCommand AS VARIANT
   LOCAL pViews AS ADOXViews
   LOCAL pView AS ADOXView
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
      ' // Get a reference to the Views collection
      pViews = pCatalog.Views
      ' // Get a reference to the "AllAuthors" view
      pView = pViews.Item("AllAuthors")
      ' // Get the Command of the View
      vCommand = pView.Command
      pCommand = vCommand
      ' // Update the CommandText property of the Command
      pCommand.CommandText = "SELECT Author FROM Authors"
      pCommand = NOTHING
      ' // Modify the Command of the View
      pView.Command = vCommand
      vCommand = EMPTY
      ? "View updated"
   CATCH
      ' // Display error information
      ? AdoGetErrorInfo(pConnection, OBJRESULT)
   FINALLY
      ' // Release the collection
      pView = NOTHING
      pViews = NOTHING
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
