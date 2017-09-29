' ########################################################################################
' This example shows the use of bookmarks
' ########################################################################################

' SED_PBCC ' Use PBCC compiler
#COMPILE EXE
#DIM ALL
#INCLUDE "DAO.INC"
#INCLUDE "OleAuto.INC"

' ========================================================================================
' Main
' ========================================================================================
FUNCTION PBMAIN

   LOCAL pDbEngine AS DAODBEngine          ' Pointer to the DbEnfine object
   LOCAL pDatabase AS DAODatabase          ' Pointer to the Database object
   LOCAL pRecordset AS DAORecordset        ' Pointer to the Recordset object
   LOCAL SqlStr AS WSTRING                 ' SQL string
   LOCAL vRes AS VARIANT                   ' General purpose variant
   LOCAL bm AS DWORD                       ' Bookmark

   ' Create a new DBEngine object
   pDbEngine = NEWCOM "DAO.DBEngine.36"
   IF ISNOTHING(pDbEngine) THEN EXIT FUNCTION

   TRY
      ' Open the Database
      pDatabase = pDbEngine.OpenDatabase(EXE.Path$ & "BIBLIO.MDB", %FALSE)
      ' Open a recordset
      SqlStr = "Authors"
      pRecordset = pDatabase.OpenRecordset(SqlStr, %dbOpenTable)
      ' Set the index
      pRecordset.Index = "PrimaryKey"
      ' Fetch the first record
      pRecordset.MoveFirst
      ' Get the content of the "Author" column
      vRes = pRecordset.Collect("Author")
      PRINT VARIANT$(vRes)
      ' Seek the 10th record
      pRecordset.Seek "=", 10
      ' Display the author's name
      vRes = pRecordset.Collect("Author")
      PRINT VARIANT$$(vRes)
      ' Get the bookmark
      bm = pRecordset.Bookmark
      ' Move to the last record
      pRecordset.MoveLast
      ' Display the author's name
      vres = pRecordset.Collect("Author")
      PRINT VARIANT$$(vRes)
      ' Return to the bookmarked record
      ' Please note the use of VARPTR to pass the address of the safe array
      ' containing the bookmark.
      IF ISTRUE bm THEN pRecordset.Bookmark = VARPTR(bm)
      ' Display the author's name
      vRes = pRecordset.Collect("Author")
      PRINT VARIANT$$(vRes)
      ' Free the safearray that contains the bookmark
      IF ISTRUE bm THEN SafeArrayDestroy(bm)
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
