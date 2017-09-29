' ########################################################################################
' Microsoft Windows
' File: CODBCEX_Drivers.bas
' Contents: CODBC class example
' Demonstrates the use of the DescRecXXX properties.
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
#INCLUDE ONCE "CODBC.INC"

' ========================================================================================
' Main
' ========================================================================================
FUNCTION PBMAIN

   ' // Create an instance of the class
   LOCAL pOdbc AS IOdbc
   pOdbc = NewOdbc(%SQL_OV_ODBC3_80)
   IF ISNOTHING(pOdbc) THEN EXIT FUNCTION

   ' // Create a connection
   LOCAL pCon AS IOdbcConnection
   pCon = pOdbc.Connection("Connection1")
   IF ISNOTHING(pCon) THEN EXIT FUNCTION

   TRY
      ' // Open the database
      pCon.OpenDatabase("DRIVER={Microsoft Access Driver (*.mdb)};DBQ=biblio.mdb;UID=;PWD=;")
      ' // Allocate an statement handle
      LOCAL pStmt AS IOdbcStatement
      pStmt = pCon.Statement("Statement1")
      ' // Cursor type
      pStmt.SetMultiuserKeysetCursor
      ' // Generate a result set
      pStmt.ExecDirect ("SELECT TOP 20 * FROM Titles ORDER BY Title")
      ' // Get the current setting or values of the descriptor record for the 9th field ("Price")
      LOCAL strName AS STRING, StringLength AS INTEGER
      LOCAL nType AS INTEGER, nSubType AS INTEGER, nLength AS LONG
      LOCAL nPrecision AS INTEGER, nScale AS INTEGER, nNullable AS INTEGER
      pStmt.GetImpRowDescRec(9, strName, StringLength, nType, nSubType, nLength, nPrecision, nScale, nNullable)
      ? "Name: " & strName
      ? "String length: " & STR$(StringLength)
      ? "Type: " & STR$(nType)
      ? "Subtype: " & STR$(nSubType)
      ? "Length: " & STR$(nLength)
      ? "Precision: " & STR$(nPrecision)
      ? "Scale: " & STR$(nScale)
      ? "Nullable: " & STR$(nNullable)
   CATCH
     ' // Display error information
      ? OdbcOleErrorInfo(OBJRESULT)
   END TRY

   ' // Destroy the class
   pOdbc = NOTHING

   #IF %DEF(%PB_CC32)
      WAITKEY$
   #ENDIF

END FUNCTION
' ========================================================================================
