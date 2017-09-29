' ########################################################################################
' This example creates a TableDef object and a Field object, appends the Field to the
' Fields collection in the new TableDef, and appends the TableDef to the TableDefs
' collection in the current database.
' ########################################################################################

' SED_PBCC ' Use PBCC compiler
#COMPILE EXE
#DIM ALL
#INCLUDE "DAO.INC"

' ========================================================================================
' Main
' ========================================================================================
FUNCTION PBMAIN

   LOCAL pDbEngine AS DAODBEngine         ' Pointer to the DbEngine object
   LOCAL pDatabase AS DAODatabase         ' Pointer to the Database object
   LOCAL pTableDef AS DAOTableDef         ' Pointer to the TableDef object
   LOCAL pField AS DAOField               ' Pointer to the Field object
   LOCAL pFields AS DAOFields             ' Pointer to the Fields collection
   LOCAL pTableDefs AS DAOTableDefs       ' Pointer to the TableDefs collection

   ' Create a new DBEngine object
   pDbEngine = NEWCOM "DAO.DBEngine.36"
   IF ISNOTHING(pDbEngine) THEN EXIT FUNCTION

   TRY
      ' Open the Database
      pDatabase = pDbEngine.OpenDatabase(EXE.Path$ & "BIBLIO.MDB")
      ' Create a new TableDef object
      pTableDef = pDatabase.CreateTableDef("MyTable")
      IF ISOBJECT(pTableDef) THEN
         ' Create a Field object
         pField = pTableDef.CreateField("MyField", %dbDate)
         IF ISOBJECT(pField) THEN
            ' Get a reference to the Fields collection
            pFields = pTableDef.Fields
            IF ISOBJECT(pFields) THEN
               ' Append the field to the collection
               pFields.Append pField
               ' Release the Fields collection
               pFields = NOTHING
               ' Get a reference to the TableDefs collection
               pTableDefs = pDatabase.TableDefs
               IF ISOBJECT(pTableDefs) THEN
                  ' Append the TableDef to the collection
                  pTableDefs.Append pTableDef
                  ' Release the TableDefs collection
                  pTableDefs = NOTHING
                  PRINT "Table definition appended"
               END IF
            END IF
            ' Release the Field object
            pField = NOTHING
         END IF
         ' Release the TableDef object
         pTableDef = NOTHING
      END IF
   CATCH
      STDOUT DaoGetErrorInfo(pDbEngine, OBJRESULT)
   FINALLY
      ' Close the database
      IF ISOBJECT(pDatabase) THEN pDatabase.Close
   END TRY

   ' Cleanup
   pDatabase = NOTHING
   pDbEngine = NOTHING

   WAITKEY$

END FUNCTION
' ========================================================================================
