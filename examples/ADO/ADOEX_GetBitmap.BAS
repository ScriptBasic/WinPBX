' ########################################################################################
' Microsoft Windows
' File: ADOEX_GetBitmap.bas
' Contents: ADO example
' How to Retrieve Bitmap from Access
' Compilers: PBWIN 10+, PBCC 6+
' Headers: Windows API headers 3.0+
' Copyright (c) 2012 José Roca. Freeware. Use at your own risk.
' Portions Copyright (c) Microsoft Corporation. All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

' ########################################################################################
' How to Retrieve Bitmap from Access
' This example shows how to extract the bitmap photos in the Microsoft Access 97 Nwind.mdb
' database and save them to a file. In order to accomplish this task, an the Access and
' OLE headers must be stripped from the field.
' Because the definition of OLE object storage is not documented, the code below searches
' the object's OLE header for characters consistent with the start of the graphic. This
' method may not work in all circumstances.
' Note: Adaptation of the code posted in the following Microsoft Knowledge Base article:
' http://support.microsoft.com/kb/q175261/
' ########################################################################################

#COMPILE EXE
#DIM ALL
#INCLUDE ONCE "ADO.INC"

TYPE OBJECTHEADER
  Signature    AS INTEGER
  HeaderSize   AS INTEGER
  ObjectType   AS LONG
  NameLen      AS INTEGER
  ClassLen     AS INTEGER
  NameOffset   AS INTEGER
  ClassOffset  AS INTEGER
  ObjectWidth  AS INTEGER
  ObjectHeight AS INTEGER
  OleInfo      AS ASCIIZ * 256
END TYPE

' ========================================================================================
' Main
' ========================================================================================
FUNCTION PBMAIN

   LOCAL pConnection AS ADOConnection
   LOCAL pRecordset AS ADORecordset
   LOCAL pFields AS ADOFields
   LOCAL pField AS ADOField
   LOCAL ConStr AS WSTRING
   LOCAL SqlStr AS WSTRING
   LOCAL nSize AS LONG
   LOCAL vRes AS VARIANT
   LOCAL ObjectOffset AS LONG
   LOCAL BitmapHeaderOffset AS INTEGER
   LOCAL BitmapOffset AS LONG
   LOCAL Buffer AS STRING
   LOCAL i AS LONG
   DIM   Arr(0) AS BYTE
   DIM   ArrBmp(0) AS BYTE
   DIM   ObjHeader AS OBJECTHEADER

   ' // Create a Connection object
   pConnection = NEWCOM "ADODB.Connection"
   IF ISNOTHING(pConnection) THEN EXIT FUNCTION

   ' // Create a Recordset object
   pRecordset = NEWCOM "ADODB.Recordset"
   IF ISNOTHING(pRecordset) THEN EXIT FUNCTION

   TRY
      ' // Connection String - Change it if needed
      ConStr = "Provider=Microsoft.Jet.OLEDB.4.0;Data Source=nwind.mdb"
      ' // Open the connection
      pConnection.Open ConStr
      ' // Open the recordset
      SqlStr = "SELECT * FROM Employees ORDER BY EmployeeID"
      pRecordset.Open SqlStr, pConnection, %adOpenKeyset, %adLockOptimistic, %adCmdText
      ' // Find the record
      pRecordset.Find "LastName = 'Davolio'", 0, 1
      ' // Get a reference to the Fields collection
      pFields = pRecordset.Fields
      ' // Get a reference to the Field object
      pField = pFields.Item("Photo")
      ' // Retrieve the actual size of the field
      nSize = pField.ActualSize
      ' // Get the content of the field
      vRes = pField.GetChunk(nSize)
      ' // Release the Field object
      pField = NOTHING
      ' // Release the Fields collection
      pFields = NOTHING
      ' // Store the content in a byte array
      Arr() = vRes
      ' // Empty the variant
      vRes = EMPTY
      ' // Copy information into a variable of the OBJECTHEADER user defined type
'      CopyMemory VARPTR(ObjHeader), VARPTR(Arr(0)), SIZEOF(OBJECTHEADER)
      MEMORY COPY VARPTR(Arr(0)), VARPTR(ObjHeader), SIZEOF(OBJECTHEADER)
      ' // Determine where the Access Header ends
      ObjectOffset = ObjHeader.HeaderSize + 1
      ' // Grab enough bytes after the OLE header to get the bitmap header
      FOR i = ObjectOffset TO ObjectOffset + 512
         IF UBOUND(Arr) => i THEN
            Buffer = Buffer & CHR$(Arr(i))
         END IF
      NEXT i
      ' // Make sure the class of the object is a Paint Brush object
      IF MID$(Buffer, 12, 6) = "PBrush" THEN
         BitmapHeaderOffset = INSTR(Buffer, "BM")
         IF BitmapHeaderOffset THEN
            ' // Calculate the beginning of the bitmap
            BitmapOffset = ObjectOffset + BitmapHeaderOffset - 1
            ' // Move the bitmap into its own array
            REDIM ArrBmp(UBOUND(Arr) - BitmapOffset)
            CopyMemory VARPTR(ArrBmp(0)), VARPTR(Arr(BitmapOffset)), UBOUND(Arr) - BitmapOffset + 1
            ' // Save the bitmap to a file. Change path as needed.
            OPEN "Photo.bmp" FOR BINARY AS #1
            PUT #1, 1, ArrBmp()
            CLOSE #1
            ? "File saved"
         END IF
      END IF
   CATCH
      ' // Display error information
      ? AdoGetErrorInfo(pConnection, OBJRESULT)
   FINALLY
      ' // Close the recordset
      IF pRecordset.State = %adStateOpen THEN pRecordset.Close
      ' // Close the connection
      IF pConnection.State = %adStateOpen THEN pConnection.Close
   END TRY

   #IF %DEF(%PB_CC32)
      WAITKEY$
   #ENDIF

END FUNCTION
' ========================================================================================
