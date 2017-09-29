' ########################################################################################
' Microsoft Windows
' File: ADOXEX_Fields.bas
' Contents: ADOX example
' Retrieves the fields of the "All Titles" view.
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
   LOCAL pViews AS ADOXViews
   LOCAL pView AS ADOXView
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
      ' // Get a reference to the Views collection
      pViews = pCatalog.Views
      ' // Get the number of objects in the collection
      nCount = pViews.Count
      IF nCount = 0 THEN EXIT TRY
      ' // Enumerate the objects
      FOR i = 0 TO nCount - 1
         pView = pViews.Item(i)
         ? "Name: " & pView.Name
         pView = NOTHING
      NEXT
      pView = pViews.Item("All Titles")
      ? "Date created: " & AfxVarToStr(pView.DateCreated)
      ? "Date modified: " & AfxVarToStr(pView.DateModified)
      pView = NOTHING
   CATCH
      ' // Display error information
      ? AdoGetErrorInfo(pConnection, OBJRESULT)
   FINALLY
      ' // Release the collection
      pViews = NOTHING
      ' Close the connection
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
