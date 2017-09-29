' ########################################################################################
' Microsoft Windows
' File: ADOEX_Attributes.bas
' Contents: ADO example
' Demonstrates the use of the Attributes and Name properties.
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
   LOCAL pProperties AS ADOProperties
   LOCAL pProperty AS ADOProperty
   LOCAL pFields AS ADOFields
   LOCAL pField AS ADOField
   LOCAL ConStr AS WSTRING
   LOCAL SqlStr AS WSTRING
   LOCAL nCount AS LONG
   LOCAL lAttr AS LONG
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
      SqlStr = "SELECT * FROM Publishers"
      pRecordset.Open SqlStr, pConnection, %adOpenStatic, %adLockOptimistic, %adCmdText
      ' // Parse the Properties collection
      pProperties = pRecordset.Properties
      nCount = pProperties.Count
      FOR i = 0 TO nCount - 1
         pProperty = pProperties.Item(i)
         ? "Property name: " & pProperty.Name & " - " & "Attributes: " & STR$(pProperty.Attributes)
         pProperty = NOTHING
      NEXT
      pProperties = NOTHING
      ' // Parse the Fields collection
      pFields = pRecordset.Fields
      nCount = pFields.Count
      IF nCount THEN
         #IF %DEF(%PB_CC32)
         ?
         #ENDIF
         ? "Nullable fields:"
         #IF %DEF(%PB_CC32)
         ? "================"
         ?
         #ENDIF
      END IF
      FOR i = 0 TO nCount - 1
         pField = pFields.Item(i)
         ' // Get the attributes of the field
         lAttr = pField.Attributes
         ' // Display fields that are nullable
         IF (lAttr AND %adFldIsNullable) = %adFldIsNullable THEN
            ? "Field name: " & pField.Name
         END IF
         pField = NOTHING
      NEXT
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
