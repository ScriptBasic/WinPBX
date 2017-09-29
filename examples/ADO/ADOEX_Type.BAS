' ########################################################################################
' Microsoft Windows
' File: ADOEX_Type.bas
' Contents: ADO example
' Compilers: PBWIN 10+, PBCC 6+
' Headers: Windows API headers 3.0+
' Copyright (c) 2012 José Roca. Freeware. Use at your own risk.
' Portions Copyright (c) Microsoft Corporation. All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

' ########################################################################################
' This example demonstrates the Type property. It is a model of a utility for listing the
' names and types of a collection, like Properties, Fields, etc.
' We do not need to open the recordset to access the Properties collection, they come into
' existence when the Recordset object is instantiated. However, setting the CursorLocation
' property to %adUseClient adds several dynamic properties to the Recordset object's
' Properties collection, making the example a little more interesting.
' ########################################################################################

#COMPILE EXE
#DIM ALL
#INCLUDE ONCE "ADO.INC"

' ========================================================================================
' Main
' ========================================================================================
FUNCTION PBMAIN

   LOCAL pRecordset AS ADORecordset
   LOCAL pProperties AS ADOProperties
   LOCAL pProperty AS ADOProperty
   LOCAL vConnection AS VARIANT
   LOCAL pConnection AS ADOConnection
   LOCAL nCount AS LONG
   LOCAL nType AS LONG
   LOCAL i AS LONG
   LOCAL strName AS WSTRING
   LOCAL strType AS WSTRING
   LOCAL HRESULT AS LONG

   ' // Create a client-side recordset
   pRecordset = NEWCOM "ADODB.Recordset"
   IF ISNOTHING(pRecordset) THEN EXIT FUNCTION

   TRY
      ' // Set the cursor location
      pRecordset.CursorLocation = %adUseClient
      ' // Get a reference to the Properties collection
      pProperties = pRecordset.Properties
      ' // Retrieve the number of objects in the collection
      nCount = pProperties.Count
      ' // ADO collections are zero based
      FOR i = 0 TO nCount - 1
         ' // Get a reference to the Property object
         pProperty = pProperties.Item(i)
         nType = pProperty.Type
         SELECT CASE AS LONG nType
           CASE %adBigInt           : strType = "adBigInt"
           CASE %adBinary           : strType = "adBinary"
           CASE %adBoolean          : strType = "adBoolean"
           CASE %adBSTR             : strType = "adBSTR"
           CASE %adChapter          : strType = "adChapter"
           CASE %adChar             : strType = "adChar"
           CASE %adCurrency         : strType = "adCurrency"
           CASE %adDate             : strType = "adDate"
           CASE %adDBDate           : strType = "adDBDate"
           CASE %adDBTime           : strType = "adDBTime"
           CASE %adDBTimeStamp      : strType = "adDBTimeStamp"
           CASE %adDecimal          : strType = "adDecimal"
           CASE %adDouble           : strType = "adDouble"
           CASE %adEmpty            : strType = "adEmpty"
           CASE %adError            : strType = "adError"
           CASE %adFileTime         : strType = "adFileTime"
           CASE %adGUID             : strType = "adGUID"
           CASE %adIDispatch        : strType = "adIDispatch"
           CASE %adInteger          : strType = "adInteger"
           CASE %adIUnknown         : strType = "adIUnknown"
           CASE %adLongVarBinary    : strType = "adLongVarBinary"
           CASE %adLongVarChar      : strType = "adLongVarChar"
           CASE %adLongVarWChar     : strType = "adLongVarWChar"
           CASE %adNumeric          : strType = "adNumeric"
           CASE %adPropVariant      : strType = "adPropVariant"
           CASE %adSingle           : strType = "adSingle"
           CASE %adSmallInt         : strType = "adSmallInt"
           CASE %adTinyInt          : strType = "adTinyInt"
           CASE %adUnsignedBigInt   : strType = "adUnsignedBigInt"
           CASE %adUnsignedInt      : strType = "adUnsignedInt"
           CASE %adUnsignedSmallInt : strType = "adUnsignedSmallInt"
           CASE %adUnsignedTinyInt  : strType = "adUnsignedTinyInt"
           CASE %adUserDefined      : strType = "adUserDefined"
           CASE %adVarBinary        : strType = "adVarBinary"
           CASE %adVarChar          : strType = "adVarChar"
           CASE %adVariant          : strType = "adVariant"
           CASE %adVarNumeric       : strType = "adVarNumeric"
           CASE %adVarWChar         : strType = "adVarWChar"
           CASE %adWChar            : strType = "adWChar"
           CASE ELSE                : strType = "*UNKNOWN*"
         END SELECT
         ' // Get the name of the property
         strName = pProperty.Name
         ' // Display the results
         ? "Property" & STR$(i) & ": " & strName & ", Type = " & strType
         ' // Release the property object
         pProperty = NOTHING
      NEXT
   CATCH
      ' // Display error information
      HRESULT = OBJRESULT
      vConnection = pRecordset.ActiveConnection
      pConnection = vConnection
      vConnection = EMPTY
      ? AdoGetErrorInfo(pConnection, HRESULT)
      pConnection = NOTHING
   FINALLY
      IF ISOBJECT(pRecordset) THEN
         ' // Close the recordset
         IF pRecordset.State = %adStateOpen THEN pRecordset.Close
      END IF
   END TRY

   ' // Release the Recordset object
   pRecordset = NOTHING

   #IF %DEF(%PB_CC32)
      WAITKEY$
   #ENDIF

END FUNCTION
' ========================================================================================
