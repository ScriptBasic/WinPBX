' ########################################################################################
' Microsoft Windows
' File: ADOEX_Field.bas
' Contents: ADO example
' Demonstrates the use of the Fields collection and the Field object
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
   LOCAL pRecordset AS ADORecordset
   LOCAL pFields AS ADOFields
   LOCAL pField AS ADOField
   LOCAL ConStr AS WSTRING
   LOCAL SqlStr AS WSTRING
   LOCAL vRes AS VARIANT
   LOCAL nCount AS LONG
   LOCAL i AS LONG

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
      SqlStr = "SELECT * FROM Authors ORDER BY Author"
      pRecordset.Open SqlStr, pConnection, %adOpenKeyset, %adLockOptimistic, %adCmdText
      ' // Get a reference to the Fields collection
      pFields = pRecordset.Fields
      nCount = pFields.Count
      ' // Parse the collection (Ado collections are zero based)
      FOR i = 0 TO nCount - 1
         ' // Get a reference to the Field object
         pField = pFields.Item(i)
         #IF %DEF(%PB_CC32)
         ? " ===================================================================="
         #ENDIF
         ? "Name: " & pField.Name
         ? "Type: " & STR$(pField.Type)
         ? "Status: " & STR$(pField.Status)
         ? "Actual size: " & STR$(pField.ActualSize)
         ? "Attibutes: " & STR$(pField.Attributes)
         ? "Defined size: " & STR$(pField.DefinedSize)
         vRes = pField.Value
         ? "Value: " & IIF$(VARIANTVT(vRes) = %VT_BSTR, VARIANT$$(vRes), STR$(VARIANT#(vRes)))
         ? "Precision: " & STR$(pField.Precision)
         ? "Numeric scale: " & STR$(pField.NumericScale)
         vRes = pField.OriginalValue
         ? "Original value: " & IIF$(VARIANTVT(vRes) = %VT_BSTR, VARIANT$$(vRes), STR$(VARIANT#(vRes)))
'         vRes = pField.UnderlyingValue
'         ? "Underlying value: " & IIF$(VARIANTVT(vRes) = %VT_BSTR, VARIANT$$(vRes), STR$(VARIANT#(vRes)))
         ' // Release the Field object
         pField = NOTHING
         #IF %DEF(%PB_CC32)
         ? " ===================================================================="
         WAITKEY$
         #ENDIF
      NEXT
      ' // Release the Fields collection
      pFields = NOTHING
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
