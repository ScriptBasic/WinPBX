' ========================================================================================
' Example of use of the ODBC raw API functions
' ========================================================================================

#COMPILE EXE
#DIM ALL
#INCLUDE ONCE "ODBC.INC"

' ========================================================================================
' Main
' ========================================================================================
FUNCTION PBMAIN

   LOCAL r AS INTEGER
   LOCAL hEnv AS DWORD
   LOCAL wDirection AS WORD
   LOCAL DriverAttributes AS STRING * 255
   LOCAL szDriverDescription AS ASCIIZ * 255  ' Driver description
   LOCAL cbDriverDescriptionLen AS INTEGER    ' Driver description total length
   LOCAL szDriverAttributes AS ASCIIZ * 255   ' Driver attributes
   LOCAL cbDriverAttributesLen AS INTEGER     ' Driver attributes total length

   ' Allocates the environment handle
   r = SQLAllocHandle (%SQL_HANDLE_ENV, %SQL_NULL_HENV, hEnv)
   IF ISFALSE SQL_SUCCEEDED(r) OR ISFALSE hEnv THEN EXIT FUNCTION

   ' Tells to the driver manager that is an application that uses the ODBC driver 3.x
   r = SQLSetEnvAttr (hEnv, %SQL_ATTR_ODBC_VERSION, BYVAL %SQL_OV_ODBC3, %SQL_IS_INTEGER)
   IF ISFALSE SQL_SUCCEEDED(r) THEN GOTO Terminate

   wDirection = %SQL_FETCH_FIRST
   DO
      DriverAttributes = ""
      r = SQLDrivers(hEnv, wDirection, szDriverDescription, SIZEOF(szDriverDescription), _
                     cbDriverDescriptionLen, BYVAL VARPTR(DriverAttributes), LEN(DriverAttributes), cbDriverAttributesLen)
      IF r = %SQL_NO_DATA THEN EXIT DO
      IF ISFALSE SQL_SUCCEEDED(r) THEN
         ? SQLGetErrorInfo(%SQL_HANDLE_ENV, hEnv, r)
         EXIT DO
      END IF
      REPLACE CHR$(0,0) WITH ";" IN DriverAttributes
      REPLACE ANY CHR$(0) WITH ";" IN DriverAttributes
      szDriverAttributes = TRIM$(DriverAttributes)
      ? "Driver description: " & szDriverDescription
      ? "Server description len: " & STR$(cbDriverDescriptionLen)
      ? "Driver attributes: " & szDriverAttributes
      ? "Driver attributes len: " & STR$(cbDriverAttributesLen)
      wDirection = %SQL_FETCH_NEXT
      #IF %DEF(%PB_CC32)
      WAITKEY$
      #ENDIF
   LOOP

Terminate:

   ' Frees the environment handle
   IF hEnv THEN SQLFreeHandle(%SQL_HANDLE_ENV, hEnv)

   #IF %DEF(%PB_CC32)
      WAITKEY$
   #ENDIF

END FUNCTION
' ========================================================================================
