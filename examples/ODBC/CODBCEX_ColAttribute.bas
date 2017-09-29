' ########################################################################################
' Microsoft Windows
' File: CODBCEX_ColAttribute.bas
' Contents: CODBC class example
' Demonstrates the use of the ColName property.
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

   TRY
      ' // Create a connection object
      LOCAL pCon AS IOdbcConnection
      pCon = pOdbc.Connection("Connection1")
      ' // Open the database
      pCon.OpenDatabase("DRIVER={Microsoft Access Driver (*.mdb)};DBQ=biblio.mdb;UID=;PWD=;")
      ' // Allocate an statement object
      LOCAL pStmt AS IOdbcStatement
      pStmt = pCon.Statement("Statement1")
      ' // Cursor type
      pStmt.SetMultiuserKeysetCursor
      ' // Generate a result set
      pStmt.ExecDirect ("SELECT TOP 20 * FROM Authors ORDER BY Author")
      ' // Retrieve the number of columns
      LOCAL numCols AS INTEGER
      numCols = pStmt.NumResultCols
      ? "Number of columns:" & STR$(numCols)
      IF numCols = 0 THEN EXIT FUNCTION
      ' // Retrieve the names of the fields (columns)
      LOCAL idx AS INTEGER
      FOR idx = 1 TO numCols
         ? "Field #" & FORMAT$(idx) & " name: " & pStmt.ColName(idx)
      NEXT
      ' // Parse the result set
      DO
         ' // Fetch the record
         IF ISFALSE pStmt.Fetch THEN EXIT DO
         ' // Get the values of the columns and display them
         FOR idx = 1 TO numCols
            ? pStmt.GetDataString(idx)
         NEXT
      LOOP
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
