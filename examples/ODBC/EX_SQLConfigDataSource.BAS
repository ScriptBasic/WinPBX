' ========================================================================================
' This example creates an Access database.
' To create a databse that is compatible with Microsoft Access 2.0 use:
' r = SQLConfigDataSource(0, %ODBC_ADD_DSN, "Microsoft Access Driver (*.mdb)", "CREATE_V2DB=new.mdb")
' ========================================================================================

#COMPILE EXE
#DIM ALL
#INCLUDE ONCE "odbcinst.inc"

' ========================================================================================
' Main
' ========================================================================================
FUNCTION PBMAIN

   LOCAL r AS INTEGER
   r = SQLConfigDataSource(0, %ODBC_ADD_DSN, "Microsoft Access Driver (*.mdb)", "CREATE_DB=new.mdb")
   IF ISTRUE r THEN
      ? "Database created"
   END IF

   #IF %DEF(%PB_CC32)
      WAITKEY$
   #ENDIF

END FUNCTION
' ========================================================================================
