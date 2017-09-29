' ########################################################################################
' Microsoft Windows
' File: ADOEX_GetRows.bas
' Contents: ADO example
' Demonstrates the use of the GetRows method.
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
#INCLUDE ONCE "AfxVarToStr.INC"

' ========================================================================================
' Main
' ========================================================================================
FUNCTION PBMAIN

   LOCAL pConnection AS ADOConnection
   LOCAL pRecordset AS ADORecordset
   LOCAL ConStr AS WSTRING
   LOCAL SqlStr AS WSTRING

   ' // Create a Connection object
   pConnection = NEWCOM "ADODB.Connection"
   IF ISNOTHING(pConnection) THEN EXIT FUNCTION

   ' // Create a Recordset object
   pRecordset = NEWCOM "ADODB.Recordset"
   IF ISNOTHING(pRecordset) THEN EXIT FUNCTION

   TRY
      ' // Connection String - Change it if needed
      ConStr = "Provider=Microsoft.Jet.OLEDB.4.0;Data Source=biblio.mdb"
      ' // Open the connection
      pConnection.Open ConStr
      ' // Open the recordset
      SqlStr = "SELECT TOP 20 * FROM Publishers ORDER BY Name"
      pRecordset.Open SqlStr, pConnection, %adOpenKeyset, %adLockOptimistic, %adCmdText
      ' // Get all the rows of the recordset in a two-dimensional safe array
      LOCAL vRows AS VARIANT
      vRows = pRecordset.GetRows(-1)
      ' // Copy the contents in a Variant array
      DIM vRowsArray(0 TO 0) AS VARIANT
      vRowsArray() = vRows
      ' // Calculate the lower and upper bounds of the array
      LOCAL il AS LONG, iu AS LONG
      LOCAL  jl AS LONG, ju AS LONG
      il = LBOUND(vRowsArray, 1)
      iu = UBOUND(vRowsArray, 1)
      jl = LBOUND(vRowsArray, 2)
      ju = UBOUND(vRowsArray, 2)
      ' // Print the contents of the array
      LOCAL i AS LONG, j AS LONG
      FOR j = jl TO ju
         FOR i = il TO iu
            ? AfxVarToStr(vRowsArray(i, j))
         NEXT
      NEXT
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
