' ########################################################################################
' Microsoft Windows
' File: CODBCEX_BasicSteps.bas
' Contents: CODBC class example
' Demonstrates the basic steps to use the CODBC class to connect to a database, execute a
' query and fetch the results.
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
      ' // Parse the result set
      LOCAL strOutput AS STRING
      DO
         ' // Fetch the record
         IF ISFALSE pStmt.Fetch THEN EXIT DO
         ' // Get the values of the columns and display them
         strOutput = ""
         strOutput += pStmt.GetDataString(1) & " "
         strOutput += pStmt.GetDataString(2) & " "
         strOutput += pStmt.GetDataString(3)
         ? strOutput
         ' // Note: Instead of retrieving the data by ordinal,
         ' // you can also do it by column name.
'         strOutput = ""
'         strOutput += pStmt.GetDataString("Au_ID") & " "
'         strOutput += pStmt.GetDataString("Author") & " "
'         strOutput += pStmt.GetDataString("Year Born")
'         ? strOutput
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
