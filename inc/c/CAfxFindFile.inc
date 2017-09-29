' ########################################################################################
' Microsoft Windows
' File: CAfxFindFile.inc
' Contents: File find class. Performs local file searches.
' Compilers: PBWin 10+, PBCC 6+.
' Copyright (c) 2014 José Roca.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%CAFXFILEFIND_INC = 1

#INCLUDE ONCE "windows.inc"

' // Avoid inclusion of shlwapi.inc (only needed for the PathRemoveFileSpecW declare)
'#INCLUDE ONCE "shlwapi.inc"
#IF NOT %DEF(%SHLWAPI_INC)
DECLARE FUNCTION PathRemoveFileSpecW IMPORT "SHLWAPI.DLL" ALIAS "PathRemoveFileSpecW" ( _
   BYREF pszPath AS WSTRINGZ _                          ' __inout LPWSTR pszPath
 ) AS LONG                                              ' BOOL
#ENDIF

' ########################################################################################
' CAfxFindFile class.
' ########################################################################################
CLASS CAfxFindFile

   INSTANCE m_hFile AS DWORD                 ' // Handle of the file used to start the search
   INSTANCE m_FileInfo AS WIN32_FIND_DATAW   ' // WIN32_FIND_DATAW structure
   INSTANCE m_bstrFileSpec AS WSTRING        ' // Path used to start the search

   ' =====================================================================================
   ' Create method
   ' =====================================================================================
   CLASS METHOD Create
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Destroy method
   ' =====================================================================================
   CLASS METHOD Destroy
      IF m_hFile <> 0 AND BITSE(m_hFile, %INVALID_HANDLE_VALUE, 32) = 0 THEN FindClose(m_hFile)
   END METHOD
   ' =====================================================================================

   INTERFACE IAfxFindFile : INHERIT IAutomation

   ' =====================================================================================
   ' Close method
   ' Call this method to end the search, reset the context, and release all resources.
   ' After calling Close, you do not have to create a new CAfxFindFile instance before
   ' calling FindFile to begin a new search.
   ' =====================================================================================
   METHOD Close
      IF m_hFile <> 0 AND BITSE(m_hFile, %INVALID_HANDLE_VALUE, 32) = 0 THEN
         FindClose(m_hFile)
         m_hFile = 0
         m_bstrFileSpec = ""
         RESET m_FileInfo
      END IF
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Method FindFile
   ' Call this method to open a file search.
   ' Parameter:
   ' bstrName
   '   A string containing the name of the file to find (must not end in a trailing
   '   backslash). If you pass an empty string, FindFile does a wildcard (*.*) search.
   '   If the string ends with a wildcard, period (.), or directory name, the user must
   '   have access permissions to the root and all subdirectories on the path.
   '   To extend the %MAX_PATH limit to 32,767 wide characters, prepend "\\?\" to the path.
   ' Return value:
   '   %TRUE if successful; otherwise FALSE. To get extended error information, call OBJRESULT.
   ' =====================================================================================
   METHOD FindFile (BYVAL bstrFileSpec AS WSTRING) AS LONG
      ME.Close   ' // Close previous search, if any
      m_bstrFileSpec = bstrFileSpec   ' // For the GetRoot method
      IF bstrFileSpec = "" THEN bstrFileSpec = "*.*"
      ' // Note: We need to use BYVAL STRPTR instead of BYCOPY because, otherwise,
      ' // GetLastError will always return 0.
      m_hFile = FindFirstFileW(BYVAL STRPTR(bstrFileSpec), m_FileInfo)
      LOCAL nError AS LONG
      nError = GetLastError
      IF BITSE(m_hFile, %INVALID_HANDLE_VALUE, 32) THEN
         METHOD OBJRESULT = HRESULT_FROM_WIN32(nError)
      ELSE
         METHOD = %TRUE
      END IF
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Method FindNextFile
   ' Call this method to continue a file search from a previous call to FindFile.
   ' Return value:
   '   Nonzero if there are more files; zero if the file found is the last one in the
   '   directory or if an error occurred. To get extended error information, call GetLastError.
   '   If the file found is the last file in the directory, or if no matching files can be
   '   found, the GetLastError function returns %ERROR_NO_MORE_FILES.
   ' =====================================================================================
   METHOD FindNextFile () AS LONG
      LOCAL bResult AS LONG
      IF m_hFile = 0 THEN
         METHOD OBJRESULT = HRESULT_FROM_WIN32(%ERROR_INVALID_HANDLE)
         EXIT METHOD
      END IF
      bResult = FindNextFileW(m_hFile, m_FileInfo)
      METHOD = bResult
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Method GetAttributes
   ' Call this method to get the attributes of the last found file.
   ' =====================================================================================
   METHOD GetFileAttributes () AS DWORD
      METHOD = m_FileInfo.dwFileAttributes
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Method IsDots
   ' Call this method to test for the current directory and parent directory markers while
   ' iterating through files.
   ' Return value:
   '   %TRUE if the found file has the name "." or "..", which indicates that the found
   '   file is actually a directory. Otherwise %FALSE.
   ' =====================================================================================
   METHOD IsDots () AS LONG
      IF ASC(m_FileInfo.cFileName) = 46 THEN METHOD = %TRUE
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Method IsFile
   ' Call this method to determine if the found file is a file.
   ' Return value:
   '   %TRUE if successful; otherwise %FALSE.
   ' =====================================================================================
   METHOD IsFile () AS LONG
      IF (m_FileInfo.dwFileAttributes AND %FILE_ATTRIBUTE_DIRECTORY) <> %FILE_ATTRIBUTE_DIRECTORY THEN METHOD = %TRUE
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Method IsFolder
   ' Call this method to determine if the found file is a folder.
   ' Return value:
   '   %TRUE if successful; otherwise %FALSE.
   ' =====================================================================================
   METHOD IsFolder () AS LONG
      IF (m_FileInfo.dwFileAttributes AND %FILE_ATTRIBUTE_DIRECTORY) = %FILE_ATTRIBUTE_DIRECTORY THEN METHOD = %TRUE
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Method IsSystemFile
   ' Call this method to determine if the found file is a system file.
   ' Return value:
   '   %TRUE if successful; otherwise %FALSE.
   ' =====================================================================================
   METHOD IsSystemFile () AS LONG
      IF (m_FileInfo.dwFileAttributes AND %FILE_ATTRIBUTE_SYSTEM) = %FILE_ATTRIBUTE_SYSTEM THEN METHOD = %TRUE
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Method IsHiddenFile
   ' Call this method to determine if the found file is a hidden file.
   ' Return value:
   '   %TRUE if successful; otherwise %FALSE.
   ' =====================================================================================
   METHOD IsHiddenFile () AS LONG
      IF (m_FileInfo.dwFileAttributes AND %FILE_ATTRIBUTE_HIDDEN) = %FILE_ATTRIBUTE_HIDDEN THEN METHOD = %TRUE
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Method IsReadOnlyFile
   ' Call this method to determine if the found file is a read only file.
   ' Return value:
   '   %TRUE if successful; otherwise %FALSE.
   ' =====================================================================================
   METHOD IsReadOnlyFile () AS LONG
      IF (m_FileInfo.dwFileAttributes AND %FILE_ATTRIBUTE_READONLY) = %FILE_ATTRIBUTE_READONLY THEN METHOD = %TRUE
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Method IsTemporaryFile
   ' Call this method to determine if the found file is a temporary file.
   ' Return value:
   '   %TRUE if successful; otherwise %FALSE.
   ' =====================================================================================
   METHOD IsTemporaryFile () AS LONG
      IF (m_FileInfo.dwFileAttributes AND %FILE_ATTRIBUTE_TEMPORARY) = %FILE_ATTRIBUTE_TEMPORARY THEN METHOD = %TRUE
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Method IsNormalFile
   ' Call this method to determine if the found file is a normal file.
   ' Return value:
   '   %TRUE if successful; otherwise %FALSE.
   ' =====================================================================================
   METHOD IsNormalFile () AS LONG
      IF (m_FileInfo.dwFileAttributes AND %FILE_ATTRIBUTE_NORMAL) = %FILE_ATTRIBUTE_NORMAL THEN METHOD = %TRUE
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Method IsCompressedFile
   ' Call this method to determine if the found file is a compressed file.
   ' Return value:
   '   %TRUE if successful; otherwise %FALSE.
   ' =====================================================================================
   METHOD IsCompressedFile () AS LONG
      IF (m_FileInfo.dwFileAttributes AND %FILE_ATTRIBUTE_COMPRESSED) = %FILE_ATTRIBUTE_COMPRESSED THEN METHOD = %TRUE
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Method IsEncryptedFile
   ' Call this method to determine if the found file is a encrypted file.
   ' Return value:
   '   %TRUE if successful; otherwise %FALSE.
   ' =====================================================================================
   METHOD IsEncryptedFile () AS LONG
      IF (m_FileInfo.dwFileAttributes AND %FILE_ATTRIBUTE_ENCRYPTED) = %FILE_ATTRIBUTE_ENCRYPTED THEN METHOD = %TRUE
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Method IsNotContentIndexedFile
   ' Call this method to determine if the found file is not to be indexed by the content indexing service.
   ' Return value:
   '   %TRUE if successful; otherwise %FALSE.
   ' =====================================================================================
   METHOD IsNotContentIndexedFile () AS LONG
      IF (m_FileInfo.dwFileAttributes AND %FILE_ATTRIBUTE_NOT_CONTENT_INDEXED) = %FILE_ATTRIBUTE_NOT_CONTENT_INDEXED THEN METHOD = %TRUE
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Method IsOffLineFile
   ' Call this method to determine if the found file is not available immediately.
   ' Return value:
   '   %TRUE if successful; otherwise %FALSE.
   ' =====================================================================================
   METHOD IsOffLineFile () AS LONG
      IF (m_FileInfo.dwFileAttributes AND %FILE_ATTRIBUTE_OFFLINE) = %FILE_ATTRIBUTE_OFFLINE THEN METHOD = %TRUE
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Method IsReparsePointFile
   ' Call this method to determine if the found file is file or directory that has an
   ' associated reparse point, or a file that is a symbolic link.
   ' Return value:
   '   %TRUE if successful; otherwise %FALSE.
   ' =====================================================================================
   METHOD IsReparsePointFile () AS LONG
      IF (m_FileInfo.dwFileAttributes AND %FILE_ATTRIBUTE_REPARSE_POINT) = %FILE_ATTRIBUTE_REPARSE_POINT THEN METHOD = %TRUE
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Method IsSparseFile
   ' Call this method to determine if the found file is a sparse file.
   ' Return value:
   '   %TRUE if successful; otherwise %FALSE.
   ' =====================================================================================
   METHOD IsSparseFile () AS LONG
      IF (m_FileInfo.dwFileAttributes AND %FILE_ATTRIBUTE_SPARSE_FILE) = %FILE_ATTRIBUTE_SPARSE_FILE THEN METHOD = %TRUE
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Method MatchesMask
   ' Call this method to test the file attributes on the found file.
   ' Parameter:
   ' dwMask
   '   Specifies one or more file attributes, identified in the WIN32_FIND_DATA structure,
   '   for the found file. To search for multiple attributes, use the bitwise OR operator.
   '   Any combination of the following attributes is acceptable:
   '   %FILE_ATTRIBUTE_ARCHIVE: The file is an archive file. Applications use this attribute
   '     to mark files for backup or removal.
   '   %FILE_ATTRIBUTE_COMPRESSED: The file or directory is compressed. For a file, this
   '     means that all of the data in the file is compressed. For a directory, this means
   '   that compression is the default for newly created files and subdirectories.
   '   %FILE_ATTRIBUTE_DIRECTORY: The file is a directory.
   '   %FILE_ATTRIBUTE_NORMAL: The file has no other attributes set. This attribute is valid
   '     only if used alone. All other file attributes override this attribute.
   '   %FILE_ATTRIBUTE_HIDDEN: The file is hidden. It is not to be included in an ordinary
   '     directory listing.
   '   %FILE_ATTRIBUTE_READONLY: The file is read only. Applications can read the file but
   '     cannot write to it or delete it.
   '   %FILE_ATTRIBUTE_SYSTEM: The file is part of or is used exclusively by the operating system.
   '   %FILE_ATTRIBUTE_TEMPORARY: The file is being used for temporary storage. Applications
   '     should write to the file only if absolutely necessary. Most of the file's data remains
   '     in memory without being flushed to the media because the file will soon be deleted.
   ' Return value
   '   %TRUE if successful; otherwise %FALSE.
   ' =====================================================================================
   METHOD MatchesMask (BYVAL dwMask AS DWORD) AS LONG
      METHOD = (m_FileInfo.dwFileAttributes AND dwMask)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Method GetFileName
   ' Call this method to get the title of the found file.
   ' Return value
   '   The name of the most-recently-found file, excluding the extension. For example,
   '   calling GetFileNameX to generate a user message about the file c:\myhtml\myfile.txt
   '   returns the file name myfile.
   ' =====================================================================================
   METHOD GetFileName () AS WSTRING
      LOCAL p AS LONG
      LOCAL bstrFileName AS WSTRING
      bstrFileName = m_FileInfo.cFileName
      p = INSTR(-1, bstrFileName, ANY ":/\")
      IF p THEN bstrFileName = MID$(bstrFileName, p + 1)
      p = INSTR(-1, bstrFileName, ".")
      IF p THEN bstrFileName = LEFT$(bstrFileName, p - 1)
      METHOD = bstrFileName
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Method GetFileNameX
   ' Call this method to get the name of the found file.
   ' Return value
   '   The name of the most-recently-found file, including the extension. For example,
   '   calling GetFileName to generate a user message about the file c:\myhtml\myfile.txt
   '   returns the file name myfile.txt.
   ' =====================================================================================
   METHOD GetFileNameX () AS WSTRING
      METHOD = m_FileInfo.cFileName
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Method GetFileNameExt
   ' Call this method to get the extesion of the found file.
   ' Return value
   ' =====================================================================================
   METHOD GetFileNameExt () AS WSTRING
      LOCAL p AS LONG
      p = INSTR(-1, m_FileInfo.cFileName, ".")
      IF p THEN METHOD = MID$(m_FileInfo.cFileName, p + 1)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Method GetFilePath
   ' GetFilePath returns the entire path for the file. For example, calling GetFilePath to
   ' generate a user message about the file c:\myhtml\myfile.txt returns the file path
   ' c:\myhtml\myfile.txt.
   ' =====================================================================================
   METHOD GetFilePath () AS WSTRING
      LOCAL nLen AS LONG, buffer AS WSTRINGZ * 4096
      nLen = GetFullPathNameW(m_FileInfo.cFileName, SIZEOF(buffer) \ 2, buffer)
      IF nLen THEN METHOD = LEFT$(buffer, nLen)
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Method GetFileURL
   ' Call this member function to retrieve the specified URL.
   ' GetFileURL is similar to the member function GetFilePath, except that it returns the
   ' URL in the form file://path. For example, calling GetFileURL to get the complete URL
   ' for myfile.txt returns the URL file://c:\myhtml\myfile.txt.
   ' =====================================================================================
   METHOD GetFileURL () AS WSTRING
      METHOD = "file://" & ME.GetFilePath
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Method GetRoot
   ' Call this member function to get the root of the found file.
   ' This method returns the drive specifier and path name used to start a search.
   ' For example, calling FindFile with *.dat results in GetRoot returning an empty string.
   ' Passing a path, such as c:\windows\system\*.dll, to FindFile results GetRoot
   ' returning c:\windows\system\.
   ' =====================================================================================
   METHOD GetRoot () AS WSTRING
      LOCAL wszPath AS WSTRINGZ * %MAX_PATH
      wszPath = m_bstrFileSpec
      PathRemoveFileSpecW(wszPath)
      IF LEN(wszPath) THEN wszPath += "\"
      METHOD = wszPath
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Method GetFileSize
   ' Call this method to get the size of the found file, in bytes.
   ' =====================================================================================
   METHOD GetFileSize () AS QUAD
      METHOD = (m_FileInfo.nFileSizeHigh * (&HFFFFFFFF??? + 1)) + m_FileInfo.nFileSizeLow
   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Method GetCreationTime
   ' Call this method to get the time, in local time format, the file was created.
   ' =====================================================================================
   METHOD GetCreationTime () AS QUAD
      LOCAL FT AS FILETIME
      IF FileTimeToLocalFileTime(m_FileInfo.ftCreationTime, FT) THEN METHOD = FT.qDateTime
   END METHOD
   ' =====================================================================================
   ' =====================================================================================
   METHOD GetCreationTimeStr (OPTIONAL BYVAL bstrDateMask AS WSTRING, BYVAL bstrTimeMask AS WSTRING, BYVAL lcid AS DWORD) AS WSTRING

      LOCAL FT AS FILETIME
      LOCAL ST AS SYSTEMTIME
      LOCAL bstrDateTime AS WSTRING
      LOCAL wszDate AS WSTRINGZ * 260
      LOCAL wszTime AS WSTRINGZ * 260

      IF bstrDateMask = "" THEN bstrDateMask = "dddd, dd MMMM yyyy"
      IF bstrTimeMask = "" THEN bstrTimeMask = "hh:mm:ss"
      IF lcid = 0 THEN lcid = %LOCALE_USER_DEFAULT

      IF FileTimeToLocalFileTime(m_FileInfo.ftCreationTime, FT) THEN
         IF FileTimeToSystemTime(FT, ST) THEN
            IF LEN(bstrDateMask) THEN
               GetDateFormatW(lcid, %NULL, ST, BYCOPY bstrDateMask, wszDate, SIZEOF(wszDate))
            END IF
            IF LEN(bstrTimeMask) THEN
               GetTimeFormatW(lcid, %NULL, ST, BYCOPY bstrTimeMask, wszTime, SIZEOF(wszTime))
            END IF
            IF LEN(wszDate) THEN bstrDateTime = wszDate
            IF LEN(wszTime) THEN
               IF LEN(bstrDateTime) THEN bstrDateTime += ", " & wszTime ELSE bstrDateTime = wszTime
            END IF
            METHOD = bstrDateTime
         END IF
      END IF

   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Method GetCreationTimeUTC
   ' Call this method to get the time, in UTC format, the file was created.
   ' =====================================================================================
   METHOD GetCreationTimeUTC () AS QUAD
      METHOD = m_FileInfo.ftCreationTime.qDateTime
   END METHOD
   ' =====================================================================================
   ' =====================================================================================
   METHOD GetCreationTimeUTCStr (OPTIONAL BYVAL bstrDateMask AS WSTRING, BYVAL bstrTimeMask AS WSTRING, BYVAL lcid AS DWORD) AS WSTRING

      LOCAL ST AS SYSTEMTIME
      LOCAL bstrDateTime AS WSTRING
      LOCAL wszDate AS WSTRINGZ * 260
      LOCAL wszTime AS WSTRINGZ * 260

      IF bstrDateMask = "" THEN bstrDateMask = "dddd, dd MMMM yyyy"
      IF bstrTimeMask = "" THEN bstrTimeMask = "hh:mm:ss"
      IF lcid = 0 THEN lcid = %LOCALE_USER_DEFAULT

      IF FileTimeToSystemTime(m_FileInfo.ftCreationTime, ST) THEN
         IF LEN(bstrDateMask) THEN
            GetDateFormatW(lcid, %NULL, ST, BYCOPY bstrDateMask, wszDate, SIZEOF(wszDate))
         END IF
         IF LEN(bstrTimeMask) THEN
            GetTimeFormatW(lcid, %NULL, ST, BYCOPY bstrTimeMask, wszTime, SIZEOF(wszTime))
         END IF
         IF LEN(wszDate) THEN bstrDateTime = wszDate
         IF LEN(wszTime) THEN
            IF LEN(bstrDateTime) THEN bstrDateTime += ", " & wszTime ELSE bstrDateTime = wszTime
         END IF
         METHOD = bstrDateTime
      END IF

   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Method GetLastAccessTime
   ' Call this method to get the time, in local time format, the file was last accessed.
   ' =====================================================================================
   METHOD GetLastAccessTime () AS QUAD
      LOCAL FT AS FILETIME
      IF FileTimeToLocalFileTime(m_FileInfo.ftLastAccessTime, FT) THEN METHOD = FT.qDateTime
   END METHOD
   ' =====================================================================================
   ' =====================================================================================
   METHOD GetLastAccessTimeStr (OPTIONAL BYVAL bstrDateMask AS WSTRING, BYVAL bstrTimeMask AS WSTRING, BYVAL lcid AS DWORD) AS WSTRING

      LOCAL FT AS FILETIME
      LOCAL ST AS SYSTEMTIME
      LOCAL bstrDateTime AS WSTRING
      LOCAL wszDate AS WSTRINGZ * 260
      LOCAL wszTime AS WSTRINGZ * 260

      IF bstrDateMask = "" THEN bstrDateMask = "dddd, dd MMMM yyyy"
      IF bstrTimeMask = "" THEN bstrTimeMask = "hh:mm:ss"
      IF lcid = 0 THEN lcid = %LOCALE_USER_DEFAULT

      IF FileTimeToLocalFileTime(m_FileInfo.ftLastAccessTime, FT) THEN
         IF FileTimeToSystemTime(FT, ST) THEN
            IF LEN(bstrDateMask) THEN
               GetDateFormatW(lcid, %NULL, ST, BYCOPY bstrDateMask, wszDate, SIZEOF(wszDate))
            END IF
            IF LEN(bstrTimeMask) THEN
               GetTimeFormatW(lcid, %NULL, ST, BYCOPY bstrTimeMask, wszTime, SIZEOF(wszTime))
            END IF
            IF LEN(wszDate) THEN bstrDateTime = wszDate
            IF LEN(wszTime) THEN
               IF LEN(bstrDateTime) THEN bstrDateTime += ", " & wszTime ELSE bstrDateTime = wszTime
            END IF
            METHOD = bstrDateTime
         END IF
      END IF

   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Method GetLastAccessTimeUTC
   ' Call this method to get the time, in UTC format, the file was accessed.
   ' =====================================================================================
   METHOD GetLastAccessTimeUTC () AS QUAD
      METHOD = m_FileInfo.ftLastAccessTime.qDateTime
   END METHOD
   ' =====================================================================================
   ' =====================================================================================
   METHOD GetLastAccessTimeUTCStr (OPTIONAL BYVAL bstrDateMask AS WSTRING, BYVAL bstrTimeMask AS WSTRING, BYVAL lcid AS DWORD) AS WSTRING

      LOCAL ST AS SYSTEMTIME
      LOCAL bstrDateTime AS WSTRING
      LOCAL wszDate AS WSTRINGZ * 260
      LOCAL wszTime AS WSTRINGZ * 260

      IF bstrDateMask = "" THEN bstrDateMask = "dddd, dd MMMM yyyy"
      IF bstrTimeMask = "" THEN bstrTimeMask = "hh:mm:ss"
      IF lcid = 0 THEN lcid = %LOCALE_USER_DEFAULT

      IF FileTimeToSystemTime(m_FileInfo.ftLastAccessTime, ST) THEN
         IF LEN(bstrDateMask) THEN
            GetDateFormatW(lcid, %NULL, ST, BYCOPY bstrDateMask, wszDate, SIZEOF(wszDate))
         END IF
         IF LEN(bstrTimeMask) THEN
            GetTimeFormatW(lcid, %NULL, ST, BYCOPY bstrTimeMask, wszTime, SIZEOF(wszTime))
         END IF
         IF LEN(wszDate) THEN bstrDateTime = wszDate
         IF LEN(wszTime) THEN
            IF LEN(bstrDateTime) THEN bstrDateTime += ", " & wszTime ELSE bstrDateTime = wszTime
         END IF
         METHOD = bstrDateTime
      END IF

   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Method GetLastWriteTime
   ' Call this method to get the time, in local time format, the file was written to,
   ' truncated, or overwritten.
   ' =====================================================================================
   METHOD GetLastWriteTime () AS QUAD
      LOCAL FT AS FILETIME
      IF FileTimeToLocalFileTime(m_FileInfo.ftLastWriteTime, FT) THEN METHOD = FT.qDateTime
   END METHOD
   ' =====================================================================================
   ' =====================================================================================
   METHOD GetLastWriteTimeStr (OPTIONAL BYVAL bstrDateMask AS WSTRING, BYVAL bstrTimeMask AS WSTRING, BYVAL lcid AS DWORD) AS WSTRING

      LOCAL FT AS FILETIME
      LOCAL ST AS SYSTEMTIME
      LOCAL bstrDateTime AS WSTRING
      LOCAL wszDate AS WSTRINGZ * 260
      LOCAL wszTime AS WSTRINGZ * 260

      IF bstrDateMask = "" THEN bstrDateMask = "dddd, dd MMMM yyyy"
      IF bstrTimeMask = "" THEN bstrTimeMask = "hh:mm:ss"
      IF lcid = 0 THEN lcid = %LOCALE_USER_DEFAULT

      IF FileTimeToLocalFileTime(m_FileInfo.ftLastWriteTime, FT) THEN
         IF FileTimeToSystemTime(FT, ST) THEN
            IF LEN(bstrDateMask) THEN
               GetDateFormatW(lcid, %NULL, ST, BYCOPY bstrDateMask, wszDate, SIZEOF(wszDate))
            END IF
            IF LEN(bstrTimeMask) THEN
               GetTimeFormatW(lcid, %NULL, ST, BYCOPY bstrTimeMask, wszTime, SIZEOF(wszTime))
            END IF
            IF LEN(wszDate) THEN bstrDateTime = wszDate
            IF LEN(wszTime) THEN
               IF LEN(bstrDateTime) THEN bstrDateTime += ", " & wszTime ELSE bstrDateTime = wszTime
            END IF
            METHOD = bstrDateTime
         END IF
      END IF

   END METHOD
   ' =====================================================================================

   ' =====================================================================================
   ' Method GetLastWriteTimeUTC
   ' Call this method to get the time, in UTC format, the file was written to, truncated,
   ' or overwritten.
   ' =====================================================================================
   METHOD GetLastWriteTimeUTC () AS QUAD
      METHOD = m_FileInfo.ftLastWriteTime.qDateTime
   END METHOD
   ' =====================================================================================
   ' =====================================================================================
   METHOD GetLastWriteTimeUTCStr (OPTIONAL BYVAL bstrDateMask AS WSTRING, BYVAL bstrTimeMask AS WSTRING, BYVAL lcid AS DWORD) AS WSTRING

      LOCAL ST AS SYSTEMTIME
      LOCAL bstrDateTime AS WSTRING
      LOCAL wszDate AS WSTRINGZ * 260
      LOCAL wszTime AS WSTRINGZ * 260

      IF bstrDateMask = "" THEN bstrDateMask = "dddd, dd MMMM yyyy"
      IF bstrTimeMask = "" THEN bstrTimeMask = "hh:mm:ss"
      IF lcid = 0 THEN lcid = %LOCALE_USER_DEFAULT

      IF FileTimeToSystemTime(m_FileInfo.ftLastWriteTime, ST) THEN
         IF LEN(bstrDateMask) THEN
            GetDateFormatW(lcid, %NULL, ST, BYCOPY bstrDateMask, wszDate, SIZEOF(wszDate))
         END IF
         IF LEN(bstrTimeMask) THEN
            GetTimeFormatW(lcid, %NULL, ST, BYCOPY bstrTimeMask, wszTime, SIZEOF(wszTime))
         END IF
         IF LEN(wszDate) THEN bstrDateTime = wszDate
         IF LEN(wszTime) THEN
            IF LEN(bstrDateTime) THEN bstrDateTime += ", " & wszTime ELSE bstrDateTime = wszTime
         END IF
         METHOD = bstrDateTime
      END IF

   END METHOD
   ' =====================================================================================

   END INTERFACE
   ' =====================================================================================

END CLASS
' ########################################################################################
