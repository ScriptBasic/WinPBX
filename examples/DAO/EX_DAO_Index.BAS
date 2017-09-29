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
   LOCAL pField1 AS DAOField              ' Pointer to the Field object
   LOCAL pField2 AS DAOField              ' Pointer to the Field object
   LOCAL pTableDefs AS DAOTableDefs       ' Pointer to the TableDefs collection
   LOCAL pIdxPrimary AS DAOIndex          ' Pointer to the Index object
   LOCAL pIndexes AS DAOIndexes           ' Pointer to the Indexes collection
   LOCAL pFields AS DAOFields             ' Pointer to the Fields collection
   LOCAL pIndexFields AS DAOIndexFields   ' Pointer to the IndexFields collection
   LOCAL vIndexFields AS VARIANT

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
         pField1 = pTableDef.CreateField("Field1", %dbLong)
         ' No Null values allowed
         IF ISOBJECT(pField1) THEN pField1.Required = %VARIANT_TRUE
         ' Create another Field object
         pField2 = pTableDef.CreateField("Field2", %dbLong)
         ' Create another Field object
         IF ISOBJECT(pField2) THEN pField2.Required = %VARIANT_TRUE
         ' Get a reference to the Fields collection
         pFields = pTableDef.Fields
         IF ISOBJECT(pFields) THEN
            ' Append the fields to the collection
            IF ISOBJECT(pField1) THEN pFields.Append pField1
            IF ISOBJECT(pField2) THEN pFields.Append pField2
            ' Release the Fields collection
            pFields = NOTHING
            ' Get a reference to the TableDefs collection
            pTableDefs = pDatabase.TableDefs
            IF ISOBJECT(pTableDefs) THEN
               ' Append the TableDef to the collection
               pTableDefs.Append pTableDef
               ' Release the TableDefs collection
               pTableDefs = NOTHING
            END IF
         END IF
         ' Release the Field objects
         pField1 = NOTHING
         pField2 = NOTHING
         ' Create primary index for those two fields.
         pIdxPrimary = pTableDef.CreateIndex("MyIndex")
         IF ISOBJECT(pIdxPrimary) THEN
            pIdxPrimary.Primary = %VARIANT_TRUE
            ' Create two field objects
            pField1 = pTableDef.CreateField("Field1")
            pField2 = pTableDef.CreateField("Field2")
            ' Get a reference to the fields collection
            vIndexFields = pIdxPrimary.Fields
            pIndexFields = vIndexFields
            vIndexFields = EMPTY
            IF ISOBJECT(pIndexFields) THEN
               ' Append the fields to the collection
               pIndexFields.Append pField1
               pIndexFields.Append pField2
               ' Release the IndexFields collection
               pIndexFields = NOTHING
            END IF
            ' Release the Field objects
            pField1 = NOTHING
            pField2 = NOTHING
            ' Get a reference to the Indexes collection
            pIndexes = pTableDef.Indexes
            IF ISOBJECT(pIndexes) THEN
               pIndexes.Append pIdxPrimary
               pIdxPrimary = NOTHING
               PRINT "Index created"
            END IF
            ' Release the primary index object
            pIdxPrimary = NOTHING
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
