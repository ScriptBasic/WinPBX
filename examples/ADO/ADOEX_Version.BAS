' ########################################################################################
' Microsoft Windows
' File: ADOEX_Version.bas
' Contents: ADO example
' This example uses the Version property of a Connection object to display the current ADO
' version. It also uses several dynamic properties to show other useful information.
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
   LOCAL pProperties AS ADOProperties
   LOCAL pProperty AS ADOProperty
   LOCAL ConStr AS WSTRING
   LOCAL vRes AS VARIANT

   ' Create an ADO connection object
   pConnection = NEWCOM "ADODB.Connection"
   IF ISNOTHING(pConnection) THEN EXIT FUNCTION

   TRY
      ' Connection String - Change it if needed
      ConStr = "Provider=Microsoft.Jet.OLEDB.4.0;Data Source=biblio.mdb"
      ' Open the connection
      pConnection.Open ConStr
      ' Show the version
      ? "ADO Version: " & ACODE$(pConnection.Version)
      ' Get a reference to the Properties collection
      pProperties = pConnection.Properties
      ' Retrieve and display several properties
      pProperty = pProperties.Item("DBMS Name")
      vRes = pProperty.Value
      ? "DBMS Name: " & VARIANT$$(vRes)
      pProperty = pProperties.Item("DBMS Version")
      vRes = pProperty.Value
      ? "DBMS Version: " & VARIANT$$(vRes)
      pProperty = pProperties.Item("Provider Friendly Name")
      vRes = pProperty.Value
      ? "Provider Friendly Name: " & VARIANT$$(vRes)
      pProperty = pProperties.Item("Provider Name")
      vRes = pProperty.Value
      ? "Provider Name: " & VARIANT$$(vRes)
      pProperty = pProperties.Item("Provider Version")
      vRes = pProperty.Value
      ? "Provider Version: " & VARIANT$$(vRes)
      pProperty = pProperties.Item("User ID")
      vRes = pProperty.Value
      ? "User ID: " & VARIANT$$(vRes)
      pProperty = pProperties.Item("User Name")
      vRes = pProperty.Value
      ? "User Name: " & VARIANT$$(vRes)
      pProperty = pProperties.Item("Active Sessions")
      vRes = pProperty.Value
      ? "Active Sessions: " & VARIANT$$(vRes)
      pProperty = pProperties.Item("Data Source")
      vRes = pProperty.Value
      ? "Data Source: " & VARIANT$$(vRes)
      pProperty = pProperties.Item("Data Source Name")
      vRes = pProperty.Value
      ? "Data Source Name: " & VARIANT$$(vRes)
   CATCH
      ' Display error information
      ? AdoGetErrorInfo(pConnection, OBJRESULT)
   FINALLY
      ' Release the Property object
      pProperty = NOTHING
      ' Release the Properties collection
      pProperties = NOTHING
      ' // Close the connection
      IF pConnection.State = %adStateOpen THEN pConnection.Close
   END TRY

   ' Release the Connection object
   pConnection = NOTHING

   #IF %DEF(%PB_CC32)
      WAITKEY$
   #ENDIF

END FUNCTION
' ========================================================================================
