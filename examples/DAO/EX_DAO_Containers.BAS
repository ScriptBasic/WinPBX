' ########################################################################################
' Container Object, Containers Collection, and Document Object, Documents Collection Example
' This example enumerates the properties of all the Container and Document objects in
' the current database.
' ########################################################################################

' SED_PBCC ' Use PBCC compiler
#COMPILE EXE
#DIM ALL
#INCLUDE "DAO.INC"
#INCLUDE "AfxTime.inc"

' ========================================================================================
' Main
' ========================================================================================
FUNCTION PBMAIN

   LOCAL pDbEngine AS DAODBEngine         ' Pointer to the DbEngine object
   LOCAL pDatabase AS DAODatabase         ' Pointer to the Database object
   LOCAL pContainers AS DAOContainers     ' Pointer to the Containers collection
   LOCAL pContainer AS DAOContainer       ' Pointer to a Container object
   LOCAL pDocuments AS DAODocuments       ' Pointer to the Documents collection
   LOCAL pDocument AS DAODocument         ' Pointer to a Document object
   LOCAL cCount AS LONG                   ' Number of containers
   LOCAL dCount AS LONG                   ' Number of documents
   LOCAL i AS LONG                        ' Loop counter
   LOCAL j AS LONG                        ' Loop counter

   ' Create a new DBEngine object
   pDbEngine = NEWCOM "DAO.DBEngine.36"
   IF ISNOTHING(pDbEngine) THEN EXIT FUNCTION

   TRY
      ' Open the Database
      pDatabase = pDbEngine.OpenDatabase(EXE.Path$ & "BIBLIO.MDB", %FALSE)
      ' Get a reference to the Containers collection
      pContainers = pDatabase.Containers
      IF ISNOTHING(pContainers) THEN EXIT TRY
      ' Retrieve the number of Containers
      cCount = pContainers.Count
      FOR i = 0 to cCount - 1     ' DAO collections are zero based
         ' Get a reference to the Container object
         pContainer = pContainers.Item(i)
         IF ISOBJECT(pContainer) THEN
            PRINT "Container Name: " & pContainer.Name
            PRINT "Container Owner: " & pContainer.Owner
            PRINT "Container User name: " & pContainer.UserName
            ' Get a reference to the Documents collection
            pDocuments = pContainer.Documents
            IF ISOBJECT(pDocuments) THEN
               ' Get the number of documents
               dCount = pDocuments.Count
               FOR j = 0 TO dCount - 1
                  ' Get a reference to the Document object
                  pDocument = pDocuments.Item(j)
                  IF ISOBJECT(pDocument) THEN
                     PRINT "Document Name: " & pDocument.Name
                     PRINT "Document Owner: " & pDocument.Owner
                     PRINT "Document User name: " & pDocument.UserName
                     PRINT "Document Date created: " & AfxVarDateToString(VARIANT#(pDocument.DateCreated))
                     PRINT "Document Date last updated: " & AfxVarDateToString(VARIANT#(pDocument.LastUpdated))
                     ' Release the Document object
                     pDocument = NOTHING
                  END IF
               NEXT
               ' Release the Documents collection
               pDocuments = NOTHING
            END IF
            ' Release the Container object
            pContainer = NOTHING
         END IF
      NEXT
      ' Release the Containers collection
      pContainers = NOTHING
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
