' ########################################################################################
' GetRows example
' ########################################################################################

' SED_PBCC ' Use PBCC compiler
#COMPILE EXE
#DIM ALL
#INCLUDE "DAO.INC"
'#INCLUDE "AfxVarToStr.inc"

' ========================================================================================
' Main
' ========================================================================================
FUNCTION PBMAIN

   LOCAL pDbEngine AS DAODBEngine         ' Pointer to the DbEnfine object
   LOCAL pDatabase AS DAODatabase         ' Pointer to the Database object
   LOCAL pRecordset AS DAORecordset       ' Pointer to the Recordset object
   LOCAL SqlStr AS STRING                 ' SQL string

   ' Create a new DBEngine object
   pDbEngine = NEWCOM "DAO.DBEngine.36"
   IF ISNOTHING(pDbEngine) THEN EXIT FUNCTION

   TRY
      ' Open the Database
      pDatabase = pDbEngine.OpenDatabase(EXE.Path$ & "BIBLIO.MDB", %FALSE)
      ' Open a recordset
      SqlStr = "SELECT * FROM Authors"
      pRecordset = pDatabase.OpenRecordset(SqlStr, %dbOpenDynaset, %dbOpenDynaset)
      ' Get ten rows in a two-dimensional array contained in a variant
      LOCAL vRows AS VARIANT
      vRows = pRecordset.GetRows(10)
      ' Copy the contents in a Variant array
      DIM vRowsArray(0 TO 0) AS VARIANT
      vRowsArray() = vRows
      ' Calculate the lower and upper bounds of the array
      LOCAL il AS LONG, iu AS LONG
      LOCAL  jl AS LONG, ju AS LONG
      il = LBOUND(vRowsArray, 1)
      iu = UBOUND(vRowsArray, 1)
      jl = LBOUND(vRowsArray, 2)
      ju = UBOUND(vRowsArray, 2)
      ' Print the contents of the array
      LOCAL i AS LONG, j AS LONG
      FOR j = jl TO ju
         FOR i = il TO iu
            IF VARIANTVT(vRowsArray(i, j)) = %VT_BSTR THEN
               PRINT VARIANT$$(vRowsArray(i, j))
            ELSEIF VARIANTVT(vRowsArray(i, j)) = %VT_NULL THEN
               PRINT
            ELSE
               PRINT STR$(VARIANT#(vRowsArray(i, j)))
            END IF
            ' Or you can use:
'            PRINT AfxVarToStr(vRowsArray(i, j))
         NEXT
      NEXT
   CATCH
      STDOUT DaoGetErrorInfo(pDbEngine, OBJRESULT)
   FINALLY
      ' Close the recordset
      IF ISOBJECT(pRecordset) THEN pRecordset.Close
      ' Close the database
      IF ISOBJECT(pDatabase) THEN pDatabase.Close
   END TRY

   ' Cleanup
   pRecordset = NOTHING
   pDatabase = NOTHING
   pDbEngine = NOTHING

   WAITKEY$

END FUNCTION
' ========================================================================================
