' #####################################################################################
' Microsoft Windows
' File: CSQLite.inc
' Contents: SQLite3 wrapper class.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' #####################################################################################

#INCLUDE THIS ONCE
%CSQLITE_INC = 1

#INCLUDE ONCE "SQLite3.inc"
#INCLUDE ONCE "CSQLiteDbc.inc"
#INCLUDE ONCE "CSQLiteStmt.inc"
#INCLUDE ONCE "CSQLiteBlob.inc"
#INCLUDE ONCE "Ole2Utils.inc"

$CLSID_CSQLite = GUID$("{7B383C8E-4AB9-4EB3-8066-9D1E7772B99C}")
$IID_ISQLite = GUID$("{D81D28FF-69F1-445C-87BB-0182A06F0583}")

' ========================================================================================
' CSQLite class.
' ========================================================================================
CLASS CSQLite $CLSID_CSQLite

   ' =====================================================================================
   ' Initialization
   ' =====================================================================================
   CLASS METHOD Create
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Cleanup
   ' =====================================================================================
   CLASS METHOD Destroy
   END METHOD
   ' =====================================================================================

   ' #####################################################################################
   ' ISQLite3 interface
   ' #####################################################################################

   INTERFACE ISQLite $IID_ISQLite : INHERIT IAutomation

   ' =====================================================================================
   ' Returns rich error information.
   ' =====================================================================================
   METHOD OleErrorInfo () AS WSTRING

      LOCAL bstrMsg AS WSTRING
      LOCAL bstrDescription AS WSTRING
      LOCAL rguid AS GUID
      LOCAL bstrSource AS WSTRING
      LOCAL bstrHelpFile AS WSTRING
      LOCAL dwHelpContext AS DWORD
      LOCAL priid AS DWORD

      IF IErrorInfo_GetErrorInfo(NOTHING, BYVAL 0, bstrDescription, bstrSource, rguid, bstrHelpFile, dwHelpContext) = %S_OK THEN
         IF LEN(bstrSource) THEN bstrMsg += "Source: " & bstrSource & $CRLF
         IF rguid <> $IID_NULL THEN bstrMsg += "GUID: " & GUIDTXT$(rguid) & $CRLF
         IF LEN(bstrDescription) THEN bstrMsg += "Description: " & bstrDescription
      END IF
      METHOD = bstrMsg

   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns the SQLite3 version.
   ' =====================================================================================
   METHOD Version () AS STRING
      LOCAL psz AS ASCIIZ PTR
      psz = sqlite3_libversion
      IF psz THEN METHOD = @psz
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns the SQLite3 version number.
   ' =====================================================================================
   METHOD VersionNumber () AS LONG
      METHOD = sqlite3_libversion_number
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns the SQLite3 source ID
   ' =====================================================================================
   METHOD SourceID () AS STRING
      LOCAL psz AS ASCIIZ PTR
      psz = sqlite3_sourceid
      IF psz THEN METHOD = @psz
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Determines if the currently entered text seems to form a complete SQL statement or if
   ' additional input is needed before sending the text into SQLite for parsing.
   ' =====================================================================================
   ' =====================================================================================
   METHOD Complete (BYVAL sql AS STRING) AS LONG
      METHOD = sqlite3_complete(BYCOPY sql)
   END METHOD
   ' =====================================================================================
   ' =====================================================================================
   METHOD CompleteW (BYVAL sql AS WSTRING) AS LONG
      METHOD = sqlite3_complete16(BYCOPY sql)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Used to make global configuration changes to SQLite in order to tune SQLite to the
   ' specific needs of the application. The default configuration is recommended for most
   ' applications and so this routine is usually not necessary. It is provided to support
   ' rare applications with unusual needs.
   ' =====================================================================================
   METHOD Config (BYVAL op AS LONG, OPTIONAL BYVAL prm1 AS DWORD, BYVAL prm2 AS DWORD, BYVAL prm3 AS DWORD, BYVAL prm4 AS DWORD, _
      BYVAL prm5 AS DWORD, BYVAL prm6 AS DWORD, BYVAL prm7 AS DWORD, BYVAL prm8 AS DWORD, BYVAL prm9 AS DWORD, _
      BYVAL prm10 AS DWORD, BYVAL prm11 AS DWORD, BYVAL prm12 AS DWORD, BYVAL prm13 AS DWORD, BYVAL prm14 AS DWORD, _
      BYVAL prm15 AS DWORD, BYVAL prm16 AS DWORD) AS LONG
      METHOD = sqlite3_config(op, BYVAL prm1, BYVAL prm2, BYVAL prm3, BYVAL prm4, BYVAL prm5, BYVAL prm6, BYVAL prm7, _
               BYVAL prm8, BYVAL prm8, BYVAL prm10, BYVAL prm11, BYVAL prm12, BYVAL prm13, BYVAL prm14, BYVAL prm15, BYVAL prm16)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' This routine enables or disables the sharing of the database cache and schema data
   ' structures between connections to the same database.
   ' =====================================================================================
   METHOD EnableSharedCache (BYVAL bSharing AS LONG) AS LONG
      METHOD = sqlite3_enable_shared_cache(bSharing)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Writes a message into the error log established by the SQLITE_CONFIG_LOG option.
   ' =====================================================================================
   METHOD Log (BYVAL iErrCode AS LONG, BYVAL strFormat AS STRING, OPTIONAL BYVAL prm1 AS DWORD, BYVAL prm2 AS DWORD, BYVAL prm3 AS DWORD, BYVAL prm4 AS DWORD, _
      BYVAL prm5 AS DWORD, BYVAL prm6 AS DWORD, BYVAL prm7 AS DWORD, BYVAL prm8 AS DWORD, BYVAL prm9 AS DWORD, _
      BYVAL prm10 AS DWORD, BYVAL prm11 AS DWORD, BYVAL prm12 AS DWORD, BYVAL prm13 AS DWORD, BYVAL prm14 AS DWORD, _
      BYVAL prm15 AS DWORD, BYVAL prm16 AS DWORD) AS LONG
      sqlite3_log(iErrCode, BYCOPY strFormat, BYVAL prm1, BYVAL prm2, BYVAL prm3, BYVAL prm4, BYVAL prm5, BYVAL prm6, BYVAL prm7, _
                  BYVAL prm8, BYVAL prm8, BYVAL prm10, BYVAL prm11, BYVAL prm12, BYVAL prm13, BYVAL prm14, BYVAL prm15, BYVAL prm16)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Formats and writes a series of characters and  values into memory obtained from Malloc.
   ' The strings returned by these two routines should be released by Free. Both
   ' routines return a NULL pointer if Malloc is unable to allocate enough memory
   ' to hold the resulting string.
   ' =====================================================================================
   METHOD mprintf (BYVAL strFormat AS STRING, OPTIONAL BYVAL prm1 AS DWORD, BYVAL prm2 AS DWORD, BYVAL prm3 AS DWORD, BYVAL prm4 AS DWORD, _
      BYVAL prm5 AS DWORD, BYVAL prm6 AS DWORD, BYVAL prm7 AS DWORD, BYVAL prm8 AS DWORD, BYVAL prm9 AS DWORD, _
      BYVAL prm10 AS DWORD, BYVAL prm11 AS DWORD, BYVAL prm12 AS DWORD, BYVAL prm13 AS DWORD, BYVAL prm14 AS DWORD, _
      BYVAL prm15 AS DWORD, BYVAL prm16 AS DWORD) AS LONG
      METHOD = sqlite3_mprintf(BYCOPY strFormat, BYVAL prm1, BYVAL prm2, BYVAL prm3, BYVAL prm4, BYVAL prm5, BYVAL prm6, BYVAL prm7, _
               BYVAL prm8, BYVAL prm8, BYVAL prm10, BYVAL prm11, BYVAL prm12, BYVAL prm13, BYVAL prm14, BYVAL prm15, BYVAL prm16)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Pseudo-random number generator.
   ' =====================================================================================
   METHOD Randomness (BYVAL numBytes AS LONG) AS STRING
      LOCAL buffer AS STRING
      buffer = NUL$(numBytes + 1)
      sqlite3_randomness(numBytes, BYVAL STRPTR(buffer))
      METHOD = buffer
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Attempts to free the specified number of bytes of heap memory by deallocating non-essential
   ' memory allocations held by the database library. Memory used to cache database pages
   ' to improve performance is an example of non-essential memory. ReleaseMemory returns
   ' the number of bytes actually freed, which might be more or less than the amount requested.
   ' The ReleaseMemory method is a no-op returning zero if SQLite is not compiled with
   ' SQLITE_ENABLE_MEMORY_MANAGEMENT.
   ' =====================================================================================
   METHOD ReleaseMemory (BYVAL numBytes AS LONG) AS LONG
      METHOD = sqlite3_release_memory(numBytes)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Causes the current thread to suspend execution for at least a number of milliseconds
   ' specified in its parameter.
   ' =====================================================================================
   METHOD Sleep (BYVAL ms AS LONG) AS LONG
      METHOD = sqlite3_sleep(ms)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' This method retuns a formatted string of the specified size.
   ' =====================================================================================
   METHOD snprintf (BYVAL nLen AS LONG, BYVAL strFormat AS STRING, OPTIONAL BYVAL prm1 AS DWORD, BYVAL prm2 AS DWORD, BYVAL prm3 AS DWORD, BYVAL prm4 AS DWORD, _
      BYVAL prm5 AS DWORD, BYVAL prm6 AS DWORD, BYVAL prm7 AS DWORD, BYVAL prm8 AS DWORD, BYVAL prm9 AS DWORD, _
      BYVAL prm10 AS DWORD, BYVAL prm11 AS DWORD, BYVAL prm12 AS DWORD, BYVAL prm13 AS DWORD, BYVAL prm14 AS DWORD, _
      BYVAL prm15 AS DWORD, BYVAL prm16 AS DWORD) AS STRING
      LOCAL buffer AS STRING
      buffer = NUL$(nLen + 1)
      sqlite3_snprintf(nLen, BYVAL STRPTR(buffer), BYCOPY strFormat, BYVAL prm1, BYVAL prm2, BYVAL prm3, BYVAL prm4, BYVAL prm5, BYVAL prm6, BYVAL prm7, _
                       BYVAL prm8, BYVAL prm8, BYVAL prm10, BYVAL prm11, BYVAL prm12, BYVAL prm13, BYVAL prm14, BYVAL prm15, BYVAL prm16)
      METHOD = buffer
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Sets and/or queries the soft limit on the amount of heap memory that may be allocated by SQLite.
   ' =====================================================================================
   METHOD SoftHeapLimit64 (BYVAL numBytes AS LONG) AS QUAD
      METHOD = sqlite3_soft_heap_limit64(numBytes)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Retrieves runtime status information about the performance of SQLite, and optionally
   ' to reset various highwater marks.
   ' =====================================================================================
   METHOD Status (BYVAL op AS LONG, BYREF pCurrent AS LONG, BYREF pHighwater AS LONG, OPTIONAL BYVAL resetFlag AS LONG) AS LONG
      METHOD = sqlite3_status(op, pCurrent, pHighwater, resetFlag)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Allow applications and extensions to compare the contents of two buffers containing
   ' UTF-8 strings in a case-independent fashion, using the same definition of "case independence"
   ' that SQLite uses internally when comparing identifiers.
   ' =====================================================================================
   ' =====================================================================================
   METHOD stricmp (BYREF sz1 AS ASCIIZ, BYREF sz2 AS ASCIIZ) AS LONG
      METHOD = sqlite3_stricmp(sz1, sz2)
   END METHOD
   ' =====================================================================================
   ' =====================================================================================
   METHOD strnicmp (BYREF sz1 AS ASCIIZ, BYREF sz2 AS ASCIIZ, BYVAL nLen AS LONG) AS LONG
      METHOD = sqlite3_strnicmp(sz1, sz2, nLen)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns zero if and only if SQLite was compiled with mutexing code omitted due to the
   ' SQLITE_THREADSAFE compile-time option being set to 0.
   ' =====================================================================================
   METHOD ThreadSafe () AS LONG
      METHOD = sqlite3_threadsafe
   END METHOD
   ' =====================================================================================

   ' #####################################################################################
   ' Memory allocation
   ' #####################################################################################

   ' =====================================================================================
   ' The Malloc method returns a pointer to a block of memory at least N bytes in
   ' length, where N is the parameter. If sqlite3_malloc is unable to obtain sufficient free
   ' memory, it returns a NULL pointer. If the parameter N to sqlite3_malloc is zero or
   ' negative then sqlite3_malloc returns a NULL pointer.
   ' =====================================================================================
   METHOD Malloc (BYVAL numBytes AS LONG) AS DWORD
      METHOD = sqlite3_malloc(numBytes)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' The Realloc method attempts to resize a prior memory allocation to be at least N bytes,
   ' where N is the second parameter. The memory allocation to be resized is the first parameter.
   ' =====================================================================================
   METHOD Realloc (BYVAL pMem AS DWORD, BYVAL numBytes AS LONG) AS DWORD
      METHOD = sqlite3_realloc(pMem, numBytes)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Releases memory previously allocated by sqlite3_malloc or sqlite3_realloc.
   ' =====================================================================================
   METHOD Free (BYVAL pMem AS DWORD)
      sqlite3_free(pMem)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns the number of bytes of memory currently outstanding (malloced but not freed).
   ' =====================================================================================
   METHOD MemoryUsed () AS QUAD
      METHOD = sqlite3_memory_used
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns the maximum value of sqlite3_memory_used since the high-water mark was last reset.
   ' =====================================================================================
   METHOD MemoryHighwater (OPTIONAL BYVAL resetFlag AS LONG) AS QUAD
      METHOD = sqlite3_memory_highwater(resetFlag)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Creates a new connection object
   ' =====================================================================================
   METHOD Connection () AS ISQLiteConnection
      LOCAL pDbc AS ISQLiteConnection
      pDbc = CLASS "CSQLiteConnection"
      METHOD = pDbc
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Returns the English-language text that describes the result code, as UTF-8.
   ' =====================================================================================
   PROPERTY GET ErrStr (BYVAL nErrorCode AS LONG) AS STRING
      LOCAL pErrStr AS ASCIIZ PTR
      pErrStr = sqlite3_errstr(nErrorCode)
      IF pErrStr THEN PROPERTY = @pErrStr
   END PROPERTY
   ' =====================================================================================

   ' =====================================================================================
   ' Returns zero if string szStr matches the glob pattern szGlob, and it returns non-zero if
   ' string szStr does not match the glob pattern szGlob. This function is case sensitive.
   ' =====================================================================================
   METHOD strglob (BYREF szGlob AS ASCIIZ, BYREF szStr AS ASCIIZ) AS LONG
      METHOD = sqlite3_strglob(szGlob, szStr)
   END METHOD
   ' =====================================================================================

   END INTERFACE

END CLASS
' ========================================================================================

' ========================================================================================
' Creates an instance of the CSQLite class
' ========================================================================================
FUNCTION NewSQLite () AS ISQLite
   DIM pSQLite AS ISQLite
   pSQLite = CLASS "CSQLite"
   FUNCTION = pSQLite
END FUNCTION
' ========================================================================================
