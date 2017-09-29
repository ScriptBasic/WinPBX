' ########################################################################################
' Microsoft Windows
' File: ADOEX_ReadExcelSheet.bas
' Contents: ADO example
' Demonstrates how to read an Excel sheet using ADO.
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
   LOCAL pRecordset AS ADORecordset
   LOCAL ConStr AS WSTRING
   LOCAL SqlStr AS WSTRING
   LOCAL vRes1, vRes2 AS VARIANT

   ' // Creates a Connection object
   pConnection = NEWCOM "ADODB.Connection"
   IF ISNOTHING(pConnection) THEN EXIT FUNCTION

   ' // Create a Recordset object
   pRecordset = NEWCOM "ADODB.Recordset"
   IF ISNOTHING(pRecordset) THEN EXIT FUNCTION

   TRY
      ' // Connection String - Change it if needed
      ConStr = "Provider=MSDASQL;Driver={Microsoft Excel Driver (*.xls)};DBQ=test.xls;ReadOnly=False"
      ' // Open the connection
      pConnection.Open ConStr
      ' // Set the cursor location
      pRecordset.CursorLocation = %adUseClient
      ' // Open the recordset
      ' // Instead of [Hoja1$] you will need to use the appropiate
      ' // name if you aren't using an Spanish version of Excel,
      ' // e.g. [Sheet1$] for the English version.
      SqlStr = "SELECT * FROM [Hoja1$]"
      pRecordset.Open SqlStr, pConnection, %adOpenStatic, %adLockOptimistic, %adCmdText
      DO
         ' // While not at the end of the recordset...
         IF pRecordset.EOF THEN EXIT DO
         vRes1 = pRecordset.Collect("Column 1")
         vRes2 = pRecordset.Collect("Column 2")
         ? VARIANT$$(vRes1) & " " & VARIANT$$(vRes2)
         ' // Fetch the next row
         pRecordset.MoveNext
      LOOP
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
