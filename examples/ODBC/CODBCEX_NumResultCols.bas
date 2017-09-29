' ########################################################################################
' Microsoft Windows
' File: CODBCEX_NumResultCols.bas
' Contents: CODBC class example
' This example demostrates the use of the Columns and NumResultCols methods.
' It shows a way to create a recordset and parse its contents if we only knew the name of
' the database and the table.
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
      ' -------------------------------------------------------------------------------------
      ' Retrieve the column names
      ' -------------------------------------------------------------------------------------
      ' // Allocate an statement object
      LOCAL pStmt AS IOdbcStatement
      pStmt = pCon.Statement("Statement1")
      ' // Get a recordset with the column names
      pStmt.Columns("", "", "Authors", "")
      ' // Binds the variable
      STATIC szBuf AS ASCIIZ * 256
      STATIC cbbytes AS LONG
      STATIC szColumnName AS ASCIIZ * 129
      STATIC idx AS LONG
      pStmt.BindColToString(4, szColumnName, SIZEOF(szColumnName), cbbytes)
      DO
         IF ISFALSE pStmt.Fetch THEN EXIT DO
         ' // Skip column 0, reserved to bookmarks
         IF idx <> 0 THEN ? "Column name: " & szColumnName
         INCR idx
      LOOP
      ' // Destroy the statement object
      pCon.RemoveStatement("Statement1")
      pStmt = NOTHING
      ' -------------------------------------------------------------------------------------
      ' // Allocate an statement object
      pStmt = pCon.Statement("Statement2")
      ' // Cursor type
      pStmt.SetMultiuserKeysetCursor
      ' // Generate a result set
      pStmt.ExecDirect ("SELECT TOP 20 * FROM Authors ORDER BY Author")
      ' // Retrieve the number of columns
      LOCAL numCols AS INTEGER
      numCols = pStmt.NumResultCols
      ? "Number of columns: " & STR$(numCols)
      IF numCols = 0 THEN EXIT FUNCTION
      ' // Parse the result set
      DO
         ' // Fetch the record
         IF ISFALSE pStmt.Fetch THEN EXIT DO
         ' // Retrieve and display the values of the columns
         FOR idx = 1 TO numCols
            #IF %DEF(%PB_CC32)
            PRINT pStmt.GetDataString(idx) & " ";
            #ELSE
            MSGBOX pStmt.GetDataString(idx)
            #ENDIF
         NEXT
         #IF %DEF(%PB_CC32)
         PRINT
         #ENDIF
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
