' #####################################################################################
' Microsoft Windows
' File: CSQLiteBlob.inc
' Contents: SQLite3 wrapper class.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' #####################################################################################

#INCLUDE THIS ONCE
%CSQLITESTMT_INC = 1

#INCLUDE ONCE "CSQLite.inc"

$CLSID_CSQLiteBlob = GUID$("{C566E8F6-F599-44ED-86D7-4984235A3A2A}")
$IID_ISQLiteBlob = GUID$("{43B039F0-D571-4BF5-9FEB-C39C37EED544}")

' ========================================================================================
' CSQLiteBlob class.
' ========================================================================================
CLASS CSQLiteBlob $CLSID_CSQLiteBlob

   INSTANCE m_hBlob AS DWORD                     ' // Blob handle

   ' =====================================================================================
   ' Initialization
   ' =====================================================================================
   CLASS METHOD Create
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Closes the blob
   ' =====================================================================================
   CLASS METHOD Destroy
      ' // Closes the blob
      IF m_hBlob THEN sqlite3_blob_close(m_hBlob)
   END METHOD
   ' =====================================================================================

   ' #####################################################################################
   ' ISQLiteBlob interface
   ' #####################################################################################

   INTERFACE ISQLiteBlob $IID_ISQLiteBlob : INHERIT IAutomation

   ' =====================================================================================
   ' Gets the blob handle
   ' =====================================================================================
   PROPERTY GET hBlob () AS DWORD
      PROPERTY = m_hBlob
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Sets the blob handlle
   ' =====================================================================================
   PROPERTY SET hBlob (BYVAL hBlob AS DWORD)
      IF m_hBlob THEN sqlite3_blob_close(m_hBlob)
      m_hBlob = hBlob
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Gets an English-language description of the error.
   ' =====================================================================================
   PROPERTY GET ErrMsgW (BYVAL hDbc AS DWORD) AS WSTRING
      LOCAL pMsg AS WSTRINGZ PTR
      pMsg = SQLite3_errmsg16(hDbc)
      IF pMsg THEN PROPERTY = @pMsg
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Opens a blob. Note that the database name is not the filename that contains the database
   ' but rather the symbolic name of the database that appears after the AS keyword when
   ' the database is connected using ATTACH. For the main database file, the database name
   ' is "main". For TEMP tables, the database name is "temp".
   ' =====================================================================================
   METHOD BlobOpen (BYVAL hDbc AS DWORD, BYVAL strDb AS STRING, BYVAL strTable AS STRING, BYVAL strColumn AS STRING, BYVAL qRow AS QUAD, OPTIONAL BYVAL flags AS LONG) AS LONG
      LOCAL lRes AS LONG
      IF m_hBlob THEN sqlite3_blob_close(m_hBlob)
      lRes = sqlite3_blob_open(hDbc, BYCOPY strDb, BYCOPY strTable, BYCOPY strColumn, qRow, flags, m_hBlob)
      METHOD = lRes
      IF lRes THEN
         METHOD OBJRESULT = &H80004005&
         OleSetErrorInfo $IID_ISQLiteConnection, "ISQLITEBOB." & FUNCNAME$, "SQLite Error: " & FORMAT$(lRes) & ": " & ME.ErrMsgW(hDbc)
      END IF
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns the size in bytes of the blob.
   ' =====================================================================================
   METHOD BlobBytes () AS LONG
      IF m_hBlob = 0 THEN EXIT METHOD
      METHOD = sqlite3_blob_bytes(m_hBlob)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Closes the blob.
   ' =====================================================================================
   METHOD BlobClose (BYVAL pDbc AS ISQLiteConnection) AS LONG
      LOCAL lRes AS LONG
      IF m_hBlob THEN
         lRes = sqlite3_blob_close(m_hBlob)
         IF lRes = %SQLITE_OK THEN m_hBlob = 0
      END IF
      METHOD = lRes
      IF lRes THEN
         METHOD OBJRESULT = &H80004005&
         OleSetErrorInfo $IID_ISQLiteConnection, "ISQLITEBOB." & FUNCNAME$, "SQLite Error: " & FORMAT$(lRes) & ": " & pDbc.ErrMsgW
      END IF
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' This method is used to read data from an open BLOB handle into a caller-supplied buffer.
   ' numBytes bytes of data are copied into buffer szBuffer from the open BLOB, starting at offset nOffset.
   ' =====================================================================================
   METHOD BlobRead (BYVAL pDbc AS ISQLiteConnection, BYVAL pBuffer AS DWORD, BYVAL numBytes AS LONG, OPTIONAL BYVAL nOffset AS LONG) AS LONG
      LOCAL lRes AS LONG
      lRes = sqlite3_blob_read(m_hBlob, BYVAL pBuffer, numBytes, nOffset)
      METHOD = lRes
      IF lRes THEN
         METHOD OBJRESULT = &H80004005&
         OleSetErrorInfo $IID_ISQLiteConnection, "ISQLITEBOB." & FUNCNAME$, "SQLite Error: " & FORMAT$(lRes) & ": " & pDbc.ErrMsgW
      END IF
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' This method is used to write data into an open BLOB handle from a caller-supplied buffer.
   ' numBytes bytes of data are copied from the buffer szBuffer into the open BLOB, starting at offset nOffset.
   ' =====================================================================================
   METHOD BlobWrite (BYVAL pDbc AS ISQLiteConnection, BYVAL pBuffer AS DWORD, BYVAL numBytes AS LONG, OPTIONAL BYVAL nOffset AS LONG) AS LONG
      LOCAL lRes AS LONG
      lRes = sqlite3_blob_write(m_hBlob, BYVAL pBuffer, numBytes, nOffset)
      METHOD = lRes
      IF lRes THEN
         METHOD OBJRESULT = &H80004005&
         OleSetErrorInfo $IID_ISQLiteConnection, "ISQLITEBOB." & FUNCNAME$, "SQLite Error: " & FORMAT$(lRes) & ": " & pDbc.ErrMsgW
      END IF
   END METHOD
   ' =====================================================================================

   END INTERFACE

END CLASS
' ========================================================================================
