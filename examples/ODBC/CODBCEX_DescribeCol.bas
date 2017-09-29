' ########################################################################################
' Microsoft Windows
' File: CODBCEX_DescribeCol.bas
' Contents: CODBC class example
' Demonstrates the use of the DescribeCol method
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
      pStmt.ExecDirect ("SELECT TOP 20 * FROM Authors ORDER BY Author")
      ' -------------------------------------------------------------------------------------
      ' Use DescribeCol to retrieve information about column 2
      ' -------------------------------------------------------------------------------------
      LOCAL strColName AS STRING
      LOCAL iNameLength AS INTEGER
      LOCAL iDataType AS INTEGER
      LOCAL dwColumnSize AS DWORD
      LOCAL iDecimalDigits AS INTEGER
      LOCAL iNullable AS INTEGER
      pStmt.DescribeCol(2, strColName, iDataType, dwColumnSize, iDecimalDigits, iNullable)
      ? "Column name: " & strColName
      ? "Name length: " & FORMAT$(iNameLength)
      ? "Data type: " & FORMAT$(iDataType)
      ? "Column size: " & FORMAT$(dwColumnSize)
      ? "Decimal digits: " & FORMAT$(iDecimalDigits)
      ? "Nullable: " & FORMAT$(iNullable) & " - " & IIF$(iNullable, "TRUE", "FALSE")
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
