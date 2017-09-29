' ########################################################################################
' Microsoft Windows
' File: ADOEX_Supports.bas
' Contents: ADO example
' This example uses the Supports method to display the options supported by a recordset
' opened with different cursor types.
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
' Display the options
' ========================================================================================
SUB ShowOptions (BYVAL pRecordset AS ADORecordset)

   ? "Cursor type: " & STR$(pRecordset.CursorType)

   IF ISTRUE pRecordset.Supports(%adAddNew) THEN ? "AddNew"
   IF ISTRUE pRecordset.Supports(%adApproxPosition) THEN ? "AbsolutePosition and AbsolutePage"
   IF ISTRUE pRecordset.Supports(%adBookmark) THEN ? "Bookmark"
   IF ISTRUE pRecordset.Supports(%adDelete) THEN ? "Delete"
   IF ISTRUE pRecordset.Supports(%adFind) THEN ? "Find"
   IF ISTRUE pRecordset.Supports(%adHoldRecords) THEN ? "Holding Records"
   IF ISTRUE pRecordset.Supports(%adMovePrevious) THEN ? "MovePrevious and Move"
   IF ISTRUE pRecordset.Supports(%adNotify) THEN ? "Notifications"
   IF ISTRUE pRecordset.Supports(%adResync) THEN ? "Resyncing data"
   IF ISTRUE pRecordset.Supports(%adUpdate) THEN ? "Update"
   IF ISTRUE pRecordset.Supports(%adUpdateBatch) THEN ? "Batch Updating"
   #IF %DEF(%PB_CC32)
   ? "------------------------------------------------------"
   WAITKEY$
   #ENDIF

END SUB
' ========================================================================================

' ========================================================================================
' Main
' ========================================================================================
FUNCTION PBMAIN

   LOCAL pConnection AS ADOConnection
   LOCAL pRecordset AS ADORecordset
   LOCAL ConStr AS WSTRING
   LOCAL SqlStr AS WSTRING
   LOCAL vRes AS VARIANT

   ' // Create an ADO connection object
   pConnection = NEWCOM "ADODB.Connection"
   IF ISNOTHING(pConnection) THEN EXIT FUNCTION

   ' // Create an ADO recordset object
   pRecordset = NEWCOM "ADODB.Recordset"
   IF ISNOTHING(pRecordset) THEN EXIT FUNCTION

   TRY
      ' // Connection String - Change it if needed
      ConStr = "Provider=Microsoft.Jet.OLEDB.4.0;Data Source=biblio.mdb"
      ' // Open the connection
      pConnection.Open ConStr
      ' // Open a keyset recordset
      SqlStr = "SELECT * FROM Authors"
      pRecordset.Open SqlStr, pConnection, %adOpenKeyset, -1, -1
      ' // Display the options
      ShowOptions pRecordset
      ' // Close the recordset
      pRecordset.Close
      ' // Open a forward only recordset
      pRecordset.Open SqlStr, pConnection, %adOpenForwardOnly, -1, -1
      ' // Display the options
      ShowOptions pRecordset
      ' // Close the recordset
      pRecordset.Close
      ' // Open an static recordset
      pRecordset.Open SqlStr, pConnection, %adOpenStatic, -1, -1
      ' // Display the options
      ShowOptions pRecordset
      ' // Close the recordset
      pRecordset.Close
   CATCH
      ' // Display error information
      ? AdoGetErrorInfo(pConnection, OBJRESULT)
   FINALLY
      ' // Close the recordset
      IF pRecordset.State = %adStateOpen THEN pRecordset.Close
      ' // Close the connection
      IF pConnection.State = %adStateOpen THEN pConnection.Close
   END TRY

   #IF %DEF(%PB_CC32)
      WAITKEY$
   #ENDIF

END FUNCTION
' ========================================================================================
