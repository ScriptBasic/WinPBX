' ########################################################################################
' Microsoft Windows
' File: ADOEX_ActiveCommand.bas
' Contents: ADO example
' This example demonstrates the use of the ActiveCommand property.
' A subroutine is given a Recordset object whose ActiveCommand property is used to display
' the command text and parameter that created the Recordset.
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
' The ShowActiveCommand routine is given only a Recordset object, yet it must print the
' command text and parameter that created the Recordset. This can be done because the
' Recordset object's ActiveCommand property yields the associated Command object.
' The Command object's CommandText property yields the parameterized command that was
' substituted for the command's parameter placeholder ("?").
' ========================================================================================
SUB ShowActiveCommand (BYVAL pConnection AS ADOConnection, BYVAL pRecordset AS ADORecordset)

   LOCAL bstrPrmName AS WSTRING
   LOCAL pCommand AS ADOCommand
   LOCAL bstrCommandText AS WSTRING
   LOCAL pParameters AS ADOParameters
   LOCAL pParameter AS ADOParameter
   LOCAL vValue AS VARIANT
   LOCAL bstrAuID AS WSTRING
   LOCAL bstrAuName AS WSTRING

   TRY
      pCommand = pRecordset.ActiveCommand
      bstrCommandText = pCommand.CommandText
      pParameters = pCommand.Parameters
      pParameter = pParameters.Item("Name")
      vValue = pParameter.Value
      bstrPrmName = VARIANT$$(vValue)
      ? "Command text: " & bstrCommandText
      ? "Parameter: " & bstrPrmName
      IF pRecordset.BOF THEN
         ? "Name = '" & bstrPrmName & "', not found"
      ELSE
         vValue = pRecordset.Collect("Author")
         bstrAuName = VARIANT$$(vValue)
         vValue = pRecordset.Collect("Au_ID")
         bstrAuID = STR$(VARIANT#(vValue))
         ? "Name = " & bstrAuName & ", ID = " & bstrAuID
      END IF
   CATCH
      ' // Display error information
      ? AdoGetErrorInfo(pConnection, OBJRESULT)
   END TRY

END SUB
' ========================================================================================

' ========================================================================================
' Main
' ========================================================================================
FUNCTION PBMAIN

   LOCAL pConnection AS ADOConnection
   LOCAL ConStr AS WSTRING
   LOCAL SqlStr AS WSTRING
   LOCAL pCommand AS ADOCommand
   LOCAL pRecordset AS ADORecordset
   LOCAL pParameters AS ADOParameters
   LOCAL pParameter AS ADOParameter

   ' // Create a Connection object
   pConnection = NEWCOM "ADODB.Connection"
   IF ISNOTHING(pConnection) THEN EXIT FUNCTION

   ' // Create an ADO command object
   pCommand = NEWCOM "ADODB.Command"
   IF ISFALSE ISOBJECT(pCommand) THEN EXIT FUNCTION

   TRY
      ' // Connection String - Change it if needed
      ConStr = "Provider=Microsoft.Jet.OLEDB.4.0;Data Source=biblio.mdb"
      ' // Open the connection
      pConnection.Open ConStr
      ' // Set the ADOCommand active connection
      pCommand.putref_ActiveConnection = pConnection
      ' // Set the command text
      pCommand.CommandText = "SELECT * FROM Authors WHERE Author = ?"
      ' // Create the parameter
      pParameter = pCommand.CreateParameter("Name", %adChar, %adParamInput, 255, "Bard, Dick")
      ' // Add the parameter to the collection
      pParameters = pCommand.Parameters
      pParameters.Append pParameter
      ' // Create the recordset by executing the command string
      pRecordset = pCommand.Execute
      ' // Display the results
      ShowActiveCommand pConnection, pRecordset
   CATCH
      ' // Display error information
      ? AdoGetErrorInfo(pConnection, OBJRESULT)
   FINALLY
      ' // Close the recordset
      IF ISOBJECT(pRecordset) THEN
         IF pRecordset.State = %adStateOpen THEN pRecordset.Close
      END IF
      ' // Close the connection
      IF pConnection.State = %adStateOpen THEN pConnection.Close
   END TRY

   #IF %DEF(%PB_CC32)
      WAITKEY$
   #ENDIF

END FUNCTION
' ========================================================================================
