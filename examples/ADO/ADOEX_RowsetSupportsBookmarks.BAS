' ########################################################################################
' Microsoft Windows
' File: ADOEX_RowsetSupportsBookmarks.bas
' Contents: ADO example
' Checks if the recordset supports bookmarks.
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
' Checks if the recordset supports bookmarks.
' Returns VARIANT_FALSE (0) or VARIANT_TRUE (-1)
' With ADO, you can use bBookmarks = pRecordset.Supports(%adBookmark) instead.
' ========================================================================================
FUNCTION OLEDB_RowsetSupportsBookmarks (BYVAL pRecordset AS ADORecordset) AS INTEGER

   LOCAL hr AS LONG                         ' // HRESULT code
   LOCAL pRC AS ADORecordsetConstruction    ' // RecordsetConstruction object
   LOCAL pRowset AS IRowset                 ' // IRowset interface
   LOCAL pRI AS IRowsetInfo                 ' // IRowsetInfo interface
   LOCAL PropIDSet AS DBPROPIDSET           ' // DBPROPIDSET structure
   DIM   rgPropertyIDs(0) AS DWORD          ' // Array of Property IDs
   LOCAL ulPropSet AS DWORD                 ' // Number of returned properties
   LOCAL pPropSet AS DBPROPSET PTR          ' // Pointer variable to access the DBPROPSET structure

   ' // Get a reference to the ADORecordsetConstruction interface
   pRC = pRecordset
   IF ISNOTHING(pRc) THEN EXIT FUNCTION
   ' // Get a reference to the Rowset interface
   pRowset = pRc.Rowset
   ' // Release the ADORecordsetConstruction obejct (no longer needed)
   pRC = NOTHING
   ' // Terminate if pRowset is false
   IF ISNOTHING(pRowset) THEN EXIT FUNCTION

   ' // Query for the IRowsetInfo interface
   pRI = pRowset
   IF ISNOTHING(pRI) THEN EXIT FUNCTION
   ' // Fill the DBPROPIDSET structure
   PropIDSet.cPropertyIDs = 1
   PropIDSet.guidPropertySet = $DBPROPSET_ROWSET
   rgPropertyIDs(0) = %DBPROP_BOOKMARKS
   PropIDSet.rgPropertyIDs = VARPTR(rgPropertyIDs(0))
   ' // Retrieve the property
   hr = pRI.GetProperties(1, PropIDSet, ulPropSet, pPropSet)
   IF hr = %S_OK AND ISTRUE pPropSet THEN
      ' // If it is a valid address...
      IF ISTRUE @pPropSet.rgProperties THEN
         ' // Get the value: VARIANT_FALSE(0) or VARIANT_TRUE (-1)
         IF ISTRUE ulPropSet THEN  ' Must be 1, since we have requested one property
            FUNCTION = @pPropSet.@rgProperties[0].vValue.boolVal
            ' // Note: We don't need to clear the variant because it doesn't contain
            ' // any reference value. If it did, such a BSTR, we will need to clear it using
            ' // VariantClear @pPropSetPtr.@rgProperties[0].vValue to avoid memory leaks.
         END IF
         ' // Free the memory allocated by the server for the properties array
         CoTaskMemFree @pPropSet.rgProperties
      END IF
      ' // Free the memory allocated by the server for the DBPROPSET structure
      CoTaskMemFree pPropSet
   END IF

   ' // Release the RowsetInfo interface
   pRI = NOTHING
   ' // Release the Rowset interface
   pRowset = NOTHING

END FUNCTION
' ========================================================================================

' ========================================================================================
' Main
' ========================================================================================
FUNCTION PBMAIN

   LOCAL pConnection AS ADOConnection       ' // Connection object
   LOCAL pRecordset AS ADORecordset         ' // Recordset object
   LOCAL ConStr AS WSTRING                  ' // Connection string
   LOCAL SqlStr AS WSTRING                  ' // Query string
   LOCAL bBookmarks AS INTEGER              ' // Flag

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
      ' // Check if the recordset supports boookmars
      bBookmarks = OLEDB_RowsetSupportsBookmarks(pRecordset)
      ? "Result = " & STR$(bBookmarks)
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
