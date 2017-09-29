' ########################################################################################
' Microsoft Windows
' File: CODBCEX_Drivers.bas
' Contents: CODBC class example
' Demonstrates the use of the Drivers method.
' Compilers: PBWIN 10+, PBCC 6+
' Headers: Windows API headers 2.03+
' Copyright (c) 2011 José Roca. Freeware. Use at your own risk.
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

   LOCAL wDirection AS WORD
   LOCAL strDriverAttributes AS STRING
   LOCAL strDriverDesc AS STRING

   TRY
      wDirection = %SQL_FETCH_FIRST
      DO
         strDriverAttributes = ""
         IF SQL_SUCCEEDED(pOdbc.Drivers(wDirection, strDriverDesc, strDriverAttributes)) = 0 THEN EXIT DO
         ? "Driver description: " & strDriverDesc
         ? "Driver attributes: " & strDriverAttributes
         wDirection = %SQL_FETCH_NEXT
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
