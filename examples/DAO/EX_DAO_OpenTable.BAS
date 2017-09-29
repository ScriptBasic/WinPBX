' ########################################################################################
' This example opens a table-type Recordset and selects an index for the Recordset. By
' setting an index, the Microsoft Jet database engine returns records in the order
' specified by the index. Without an index, table-type Recordset objects return records
' from the database table in no particular order.
' ########################################################################################

' SED_PBCC ' Use PBCC compiler
#COMPILE EXE
#DIM ALL
#INCLUDE "DAO.INC"

' ========================================================================================
' Main
' ========================================================================================
FUNCTION PBMAIN

   LOCAL pDbEngine AS DAODBEngine          ' Pointer to the DbEnfine object
   LOCAL pDatabase AS DAODatabase          ' Pointer to the Database object
   LOCAL pRecordset AS DAORecordset        ' Pointer to the Recordset object
   LOCAL vRes AS VARIANT                   ' General purpose variant

   ' Create a new DBEngine object
   pDbEngine = NEWCOM "DAO.DBEngine.36"
   IF ISNOTHING(pDbEngine) THEN EXIT FUNCTION

   TRY
      ' Open the Database
      pDatabase = pDbEngine.OpenDatabase(EXE.Path$ & "BIBLIO.MDB", %FALSE)
      ' Open recordset on Authors table
      pRecordset = pDatabase.OpenRecordset("Authors", %dbOpenTable)
      ' Set the index
      pRecordset.Index = "Author"
      ' While not at the end of the recordset...
      WHILE NOT pRecordset.EOF
         ' Get the content of the "Author" column
         vRes = pRecordset.Collect("Author")
         PRINT VARIANT$$(vRes)
         ' Fetch the next row
         pRecordset.MoveNext
      WEND
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
