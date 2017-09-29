' ########################################################################################
' Microsoft Windows
' File: ADOXEX_Key.bas
' Contents: ADOX example
' The following code demonstrates how to create a new key.
' The key is on two columns in the table.
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

   LOCAL pCatalog AS ADOXCatalog
   LOCAL pForeignKey AS ADOXKey
   LOCAL pColumns AS ADOXColumns
   LOCAL pColumn AS ADOXColumn
   LOCAL pTables AS ADOXTables
   LOCAL pTable AS ADOXTable
   LOCAL pKeys AS ADOXKeys
   LOCAL pConnection AS ADOConnection
   LOCAL vConnection AS VARIANT
   LOCAL HRESULT AS LONG

   ' // Create a Catalog object
   pCatalog = NEWCOM "ADOX.Catalog"
   IF ISNOTHING(pCatalog) THEN EXIT FUNCTION

   ' // Create a Key object
   pForeignKey = NEWCOM "ADOX.Key"
   IF ISNOTHING(pForeignKey) THEN EXIT FUNCTION

   TRY
      ' // Set the ActiveConnection property of the Catalog
      pCatalog.ActiveConnection = "Provider=Microsoft.Jet.OLEDB.4.0;Data Source=nwind.mdb"
      ' // Define the foreign key
      pForeignKey.Name = "CustOrder"
      pForeignKey.Type = %adKeyForeign
      pForeignKey.RelatedTable = "Customers"
      pColumns = pForeignKey.Columns
      pColumns.Append "CustomerId", %adVarWChar
      pColumn = pColumns.Item("CustomerId")
      pColumn.RelatedColumn = "CustomerId"
      pForeignKey.UpdateRule = %adRICascade
      ' // Append the foreign key
      pTables = pCatalog.Tables
      pTable = pTables.Item("Orders")
      pKeys = pTable.Keys
      pKeys.Append pForeignKey
   CATCH
      HRESULT = OBJRESULT
      ' // Display error information
      vConnection = pCatalog.ActiveConnection
      pConnection = vConnection
      ? AdoGetErrorInfo(pConnection, HRESULT)
      vConnection = EMPTY
      pConnection = NOTHING
   FINALLY
      ' // Delete the key as this is a demonstration
      IF ISTRUE ISOBJECT(pTables) THEN
         pKeys.Delete "CustOrder"
         ? "CustOrder deleted"
      END IF
      ' // Release objects and collections
      pKeys = NOTHING
      pTable = NOTHING
      pTables = NOTHING
      pColumn = NOTHING
      pColumns = NOTHING
   END TRY

   ' // Release the main objects
   pForeignKey = NOTHING
   pCatalog = NOTHING

   #IF %DEF(%PB_CC32)
      WAITKEY$
   #ENDIF

END FUNCTION
' ========================================================================================
