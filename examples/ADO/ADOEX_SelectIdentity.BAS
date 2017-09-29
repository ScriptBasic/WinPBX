' ########################################################################################
' Microsoft Windows
' File: ADOEX_SelectIdentity.bas
' Contents: ADO example
' The Jet OLE DB version 4.0 provider supports the SELECT @@Identity query that allows you
' to retrieve the value of the auto-increment field generated on your connection.
' Note: Uses the table created with the ADOX_CreateTable2.BAS example.
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
   LOCAL pParameters AS ADOParameters
   LOCAL pParameter AS ADOParameter
   LOCAL pRecordset AS ADORecordset
   LOCAL ConStr AS WSTRING
   LOCAL SqlStr AS WSTRING
   LOCAL vRes AS VARIANT
   LOCAL vOpt AS VARIANT

   vOpt = ERROR %DISP_E_PARAMNOTFOUND

   ' // Create a Connection object
   pConnection = NEWCOM "ADODB.Connection"
   IF ISNOTHING(pConnection) THEN EXIT FUNCTION

   ' // Create a Command object
   pCommand = NEWCOM "ADODB.Command"
   IF ISNOTHING(pCommand) THEN EXIT FUNCTION

   TRY
      ' // Connection String - Change it if needed
      ConStr = "Provider=Microsoft.Jet.OLEDB.4.0;Data Source=biblio.mdb"
      ' // Open the connection
      pConnection.Open ConStr
      ' // Set command properties
      pCommand.putref_ActiveConnection = pConnection
      pCommand.CommandType = %adCmdText
      pCommand.CommandText = "INSERT INTO Contacts2 (FirstName, LastName, Phone) VALUES (?, ?, ?)"
      ' // Create command parameters
      LOCAL bstrFirstName AS WSTRING
      LOCAL bstrLastName AS WSTRING
      LOCAL bstrPhone AS WSTRING
      LOCAL bstrNotes AS WSTRING
      bstrFirstName = "Joe"
      bstrLastName = "Doe"
      bStrPhone = "(xxx)-xxxx-xxxx"
      bstrNotes = "Actor"
      pParameters = pCommand.Parameters
      pParameter = pCommand.CreateParameter("FirstName", %adVarWChar, %adParamInput, 255, bstrFirstName)
      pParameters.Append pParameter
      pParameter = NOTHING
      pParameter = pCommand.CreateParameter("LastName", %adVarWChar, %adParamInput, 255, bstrLastName)
      pParameters.Append pParameter
      pParameter = NOTHING
      pParameter = pCommand.CreateParameter("Phone", %adVarWChar, %adParamInput, 255, bstrPhone)
      pParameters.Append pParameter
      pParameter = NOTHING
      pParameter = NOTHING
      pParameters = NOTHING
      ' // Run the command (perform the Insert)
      pCommand.Execute vOpt, vOpt, %adExecuteNoRecords
      ' // Get the new AutoNumber value
      pRecordset = pConnection.Execute("SELECT @@Identity", vOpt, %adCmdText)
      vRes = pRecordset.Collect(0)
      ? STR$(VARIANT#(vRes))
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
