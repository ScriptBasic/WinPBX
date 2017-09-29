' ########################################################################################
' Microsoft Windows
' File: ADOEX_GetOrdinalColumnNumbers.bas
' Contents: ADO example
' Retrieves the ordinal column numbers of a table.
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
#INCLUDE ONCE "OLEDB.INC"

' ========================================================================================
' Main
' ========================================================================================
FUNCTION PBMAIN

   LOCAL hr AS LONG                         ' // HRESULT code
   LOCAL pConnection AS ADOConnection       ' // Connection object
   LOCAL pRecordset AS ADORecordset         ' // Recordset object
   LOCAL ConStr AS WSTRING                  ' // Connection string
   LOCAL SqlStr AS WSTRING                  ' // Query string
   LOCAL pRC AS ADORecordsetConstruction    ' // RecordsetConstruction object
   LOCAL pRowset AS IRowset                 ' // IRowset interface
   LOCAL pCI AS IColumnsInfo                ' // IColumnsInfo interface
   LOCAL prgInfo AS DBCOLUMNINFO PTR        ' // Pointer variable to access the DBCOLUMNINFO array of structures
   LOCAL pStringsBuffer AS WSTRINGZ PTR     ' // Address of the strings
   LOCAL ulNumColumns AS DWORD              ' // Number of columns
   LOCAL i AS LONG                          ' // Loop counter
   LOCAL iOrdinal AS DWORD                  ' // Ordinal

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
      ' // Set the cursor location
      pRecordset.CursorLocation = %adUseClient
      ' // Open the recordset
      SqlStr = "Publishers"
      pRecordset.Open SqlStr, pConnection, %adOpenStatic, %adLockOptimistic, %adCmdTable
      ' // Get a reference to the ADORecordsetConstruction object
      pRC = pRecordset
      IF ISNOTHING(pRC) THEN EXIT TRY
      ' // Get a reference to the Rowset interface
      pRowset = pRc.Rowset
      ' // Release the ADORecordsetConstruction object (no longer needed)
      pRC = NOTHING
      ' // Terminate if pRowset is false
      IF ISNOTHING(pRowset) THEN EXIT TRY
      ' // Get a reference to the IColumnsInfo interface
      pCI = pRowset
      IF ISNOTHING(pCI) THEN EXIT TRY
      ' // Retrieve the information about the columns
      hr = pCI.GetColumnInfo(ulNumColumns, prgInfo, pStringsBuffer)
      IF hr = %S_OK THEN
         ' // Show the number of columns (including the one reserved for bookmarks, if any)
         ? "Columns = " & STR$(ulNumColumns)
         ' // If the recordset supports bookmarks, column 0 is reserved for them,
         ' // so change the start index from 0 to 1
         FOR i = 0 TO ulNumColumns - 1
            IF @prgInfo[i].pwszName THEN
               ' // Retrieve the ordinal number
               iOrdinal = @prgInfo[i].iOrdinal
               ' // Show the ordinal number and the name of the column
               ' // Don't use MSGBOX here: it corrupts the memory of prgInfo. Use MessageBox instead.
               #IF %DEF(%PB_CC32)
               ? "Ordinal =" & STR$(iOrdinal) & " | Name = " & @prgInfo[i].@pwszName
               #ELSE
               MessageBox(0, "Ordinal =" & STR$(iOrdinal) & " | Name = " & @prgInfo[i].@pwszName, "", %MB_ICONINFORMATION OR %MB_OK)
               #ENDIF
               ' // Free the memory allocated by the server for the name
               CoTaskMemFree @prgInfo[i].pwszName
            END IF
         NEXT
         ' // Free the memory allocated by the server for the array of DBCOLUMNINFO structures
         CoTaskMemFree prgInfo
         ' // Free the memory allocated by the server for the strings block
         CoTaskMemFree pStringsBuffer
      END IF

      ' // Release the IColumnsInfo interface
      pCI = NOTHING
      ' // Release the IRowset interface
      pRowset = NOTHING

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
