' ########################################################################################
' Microsoft Windows
' File: AfxFile.inc
' Contents: File management wrapper functions.
' Copyright (c) 2011 José Roca
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%AFXFILE_INC = 1

#INCLUDE ONCE "windows.inc"
#INCLUDE ONCE "scrrun.inc"
#INCLUDE ONCE "oaidl.inc"
#INCLUDE ONCE "AfxTime.inc"
#INCLUDE ONCE "psapi.inc"

' ========================================================================================
' Checks if the specified drive exists and returns True(-1) or False(0).
' ========================================================================================
FUNCTION AfxDriveExists (BYVAL bstrDrive AS WSTRING) AS INTEGER

   LOCAL fso AS IFileSystem

   ' // Create an instance of the FileSystemObject
   fso = NEWCOM "Scripting.FileSystemObject"
   IF ISNOTHING(fso) THEN EXIT FUNCTION
   ' // Check if the drive exists
   FUNCTION = fso.DriveExists(bstrDrive)

END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns a ";" separated list of the driver letters.
' ========================================================================================
FUNCTION AfxDriveLetters () AS WSTRING

   LOCAL fso AS IFileSystem
   LOCAL pEnum AS IEnumVARIANT
   LOCAL pDrives AS IDriveCollection
   LOCAL pDrive AS IDrive
   LOCAL vItem AS VARIANT
   LOCAL celtFetched AS DWORD
   LOCAL bstrDrives AS WSTRING

   ' // Create an instance of the FileSystemObject
   fso = NEWCOM "Scripting.FileSystemObject"
   IF ISNOTHING(fso) THEN EXIT FUNCTION
   ' // Get a reference to the IDrives collection
   pDrives = fso.Drives
   IF ISNOTHING(pDrives) THEN EXIT FUNCTION
   ' // Get a reference to the standard enumerator
   pEnum = pDrives.NewEnum_
   IF ISNOTHING(pEnum) THEN EXIT FUNCTION
   ' // Enumerate the collection
   DO
      pEnum.Next 1, vItem, celtFetched
      IF celtFetched = 0 THEN EXIT DO
      pDrive = vItem
      IF ISNOTHING(pDrive) THEN EXIT DO
      bstrDrives += pDrive.DriveLetter & ";"
   LOOP
   ' // Remove the last ";"
   IF LEN(bstrDrives) THEN bstrDrives = LEFT$(bstrDrives, LEN(bstrDrives) - 1)
   ' // Return the drive letters
   FUNCTION = bstrDrives

END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the type of file system in use for the specified drive.
' Available return types include FAT, NTFS, and CDFS.
' ========================================================================================
FUNCTION AfxGetDriveFileSystem (BYVAL bstrDrive AS WSTRING) AS WSTRING

   LOCAL fso AS IFileSystem
   LOCAL pDrive AS IDrive

   ' // Create an instance of the FileSystemObject
   fso = NEWCOM "Scripting.FileSystemObject"
   IF ISNOTHING(fso) THEN EXIT FUNCTION
   ' // Get a reference to the IDrive interface
   pDrive = fso.GetDrive(bstrDrive)
   ' // Return the file system type
   FUNCTION = pDrive.FileSystem

END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the network share name for a specified drive.
' ========================================================================================
FUNCTION AfxGetDriveShareName (BYVAL bstrDrive AS WSTRING) AS WSTRING

   DIM fso AS IFileSystem
   DIM pDrive AS IDrive

   ' // Create an instance of the FileSystemObject
   fso = NEWCOM "Scripting.FileSystemObject"
   IF ISNOTHING(fso) THEN EXIT FUNCTION
   ' // Get a reference to the IDrive interface
   pDrive = fso.GetDrive(bstrDrive)
   IF ISNOTHING(pDrive) THEN EXIT FUNCTION
   ' // Return the volume name
   FUNCTION = pDrive.ShareName

END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns information about the type of a file. For example, for files ending in .TXT,
' "Text Document" is returned.
' ========================================================================================
FUNCTION AfxGetFileType (BYVAL bstrFile AS WSTRING) AS WSTRING

   LOCAL fso AS IFileSystem
   LOCAL pFile AS IFile

   ' // Create an instance of the FileSystemObject
   fso = NEWCOM "Scripting.FileSystemObject"
   IF ISNOTHING(fso) THEN EXIT FUNCTION
   ' // Get a reference to the IFile interface
   pFile = fso.GetFile(bstrFile)
   IF ISNOTHING(pFile) THEN EXIT FUNCTION
   ' // Return the type
   FUNCTION = pFile.Type

END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the version number of a specified file.
' ========================================================================================
FUNCTION AfxGetFileVersion (BYVAL bstrFileName AS WSTRING) AS WSTRING

   LOCAL fso AS IFileSystem3
   LOCAL bstrVersion AS WSTRING

   ' // Create an instance of the FileSystemObject
   fso = NEWCOM "Scripting.FileSystemObject"
   IF ISNOTHING(fso) THEN EXIT FUNCTION
   ' // Return the file version
   FUNCTION = fso.GetFileVersion(bstrFileName)

END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns information about the type of a folder.
' ========================================================================================
FUNCTION AfxGetFolderType (BYVAL bstrFolder AS WSTRING) AS WSTRING

   LOCAL fso AS IFileSystem
   LOCAL pFolder AS IFolder

   ' // Create an instance of the FileSystemObject
   fso = NEWCOM "Scripting.FileSystemObject"
   IF ISNOTHING(fso) THEN EXIT FUNCTION
   ' // Get a reference to the IFolder interface
   pFolder = fso.GetFolder(bstrFolder)
   IF ISNOTHING(pFolder) THEN EXIT FUNCTION
   ' // Return the type
   FUNCTION = pFolder.Type

END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the folder name for the parent of the specified folder.
' ========================================================================================
FUNCTION AfxGetParentFolderName (BYVAL bstrFolder AS WSTRING) AS WSTRING

   LOCAL fso AS IFileSystem
   LOCAL pFolder AS IFolder
   LOCAL pParentFolder AS IFolder

   ' // Create an instance of the FileSystemObject
   fso = NEWCOM "Scripting.FileSystemObject"
   IF ISNOTHING(fso) THEN EXIT FUNCTION
   ' // Get a reference to the IFolder interface
   pFolder = fso.GetFolder(bstrFolder)
   IF ISNOTHING(pFolder) THEN EXIT FUNCTION
   ' // Get a reference to the parent's IFolder interface
   pParentFolder = pFolder.ParentFolder
   IF ISNOTHING(pParentFolder) THEN EXIT FUNCTION
   ' // Return the name of the parent folder
   FUNCTION = pParentFolder.Name

END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the volume serial number that the operating system assigns when a hard disk is formatted.
' ========================================================================================
FUNCTION AfxGetSerialNumber (BYVAL bstrDrive AS WSTRING) AS DWORD

   DIM fso AS IFileSystem
   DIM pDrive AS IDrive

   ' // Create an instance of the FileSystemObject
   fso = NEWCOM "Scripting.FileSystemObject"
   IF ISNOTHING(fso) THEN EXIT FUNCTION
   ' // Get a reference to the IDrive interface
   pDrive = fso.GetDrive(bstrDrive)
   IF ISNOTHING(pDrive) THEN EXIT FUNCTION
   ' // Return the serial number
   FUNCTION = pDrive.SerialNumber

END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the volume name of the specified drive.
' ========================================================================================
FUNCTION AfxGetVolumeName (BYVAL bstrDrive AS WSTRING) AS WSTRING

   DIM fso AS IFileSystem
   DIM pDrive AS IDrive

   ' // Create an instance of the FileSystemObject
   fso = NEWCOM "Scripting.FileSystemObject"
   IF ISNOTHING(fso) THEN EXIT FUNCTION
   ' // Get a reference to the IDrive interface
   pDrive = fso.GetDrive(bstrDrive)
   IF ISNOTHING(pDrive) THEN EXIT FUNCTION
   ' // Return the volume name
   IF pDrive.IsReady THEN FUNCTION = pDrive.VolumeName

END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns True (-1) if the specified drive is ready; False (0) if it is not.
' ========================================================================================
FUNCTION AfxIsDriveReady (BYVAL bstrDrive AS WSTRING) AS INTEGER

   LOCAL fso AS IFileSystem
   LOCAL pDrive AS IDrive

   ' // Create an instance of the FileSystemObject
   fso = NEWCOM "Scripting.FileSystemObject"
   IF ISNOTHING(fso) THEN EXIT FUNCTION
   ' // Get a reference to the IDrive interface
   pDrive = fso.GetDrive(bstrDrive)
   IF ISNOTHING(pDrive) THEN EXIT FUNCTION
   ' // Check if the drive is ready
   FUNCTION = pDrive.IsReady

END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns True(-1) if the specified folder is the root folder; False(0) if it is not.
' ========================================================================================
FUNCTION AfxIsRootFolder (BYVAL bstrFolder AS WSTRING) AS INTEGER

   LOCAL fso AS IFileSystem
   LOCAL pFolder AS IFolder
   LOCAL iRootFolder AS INTEGER

   ' // Create an instance of the FileSystemObject
   fso = NEWCOM "Scripting.FileSystemObject"
   IF ISNOTHING(fso) THEN EXIT FUNCTION
   ' // Get a reference to the IFolder interface
   pFolder = fso.GetFolder(bstrFolder)
   IF ISNOTHING(pFolder) THEN EXIT FUNCTION
   ' Is root folder?
   FUNCTION = pFolder.IsRootFolder

END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the number of drives.
' ========================================================================================
FUNCTION AfxNumDrives () AS LONG

   LOCAL fso AS IFileSystem
   LOCAL pDrives AS IDriveCollection

   ' // Create an instance of the FileSystemObject
   fso = NEWCOM "Scripting.FileSystemObject"
   IF ISNOTHING(fso) THEN EXIT FUNCTION
   ' // Get a reference to the IDrives collection
   pDrives = fso.Drives
   IF ISNOTHING(pDrives) THEN EXIT FUNCTION
   ' // Return the number of drives
   FUNCTION = pDrives.Count

END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the number of files in the specified folder.
' ========================================================================================
FUNCTION AfxNumFiles (BYVAL bstrFolder AS WSTRING) AS LONG

   LOCAL fso AS IFileSystem
   LOCAL pFolder AS IFolder
   LOCAL pFiles AS IFileCollection

   ' // Create an instance of the FileSystemObject
   fso = NEWCOM "Scripting.FileSystemObject"
   IF ISNOTHING(fso) THEN EXIT FUNCTION
   ' // Get a reference to the IFolder interface
   pFolder = fso.GetFolder(bstrFolder)
   IF ISNOTHING(pFolder) THEN EXIT FUNCTION
   ' // Get a reference to the IFileCollection interface
   pFiles = pFolder.Files
   IF ISNOTHING(pFiles) THEN EXIT FUNCTION
   ' // Return the number of files
   FUNCTION = pFiles.Count

END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the number of folders contained in a specified folder, including those with
' hidden and system file attributes set.
' ========================================================================================
FUNCTION AfxNumSubFolders (BYVAL bstrFolder AS WSTRING) AS LONG

   LOCAL fso AS IFileSystem
   LOCAL pFolder AS IFolder
   LOCAL pSubFolders AS IFolderCollection

   ' // Create an instance of the FileSystemObject
   fso = NEWCOM "Scripting.FileSystemObject"
   IF ISNOTHING(fso) THEN EXIT FUNCTION
   ' // Get a reference to the IFolder collection
   pFolder = fso.GetFolder(bstrFolder)
   IF ISNOTHING(pFolder) THEN EXIT FUNCTION
   ' // Get a reference to the IFolderCollection interface
   pSubFolders = pFolder.SubFolders
   IF ISNOTHING(pSubFolders) THEN EXIT FUNCTION
   ' // Return the number of subfolders
   FUNCTION = pSubFolders.Count

END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the file-system attribute(s) of a disk file or directory.
' ========================================================================================
'FUNCTION AfxGetFileAttributes (BYVAL bstrFileSpec AS WSTRING) AS DWORD
'   LOCAL hFind AS DWORD
'   LOCAL fd AS WIN32_FIND_DATAW
'   IF ISTRUE LEN(bstrFileSpec) THEN
'      hFind = FindFirstFileW(BYCOPY bstrFileSpec, fd)
'      IF BITSE(hFind, %INVALID_HANDLE_VALUE, 32) THEN EXIT FUNCTION
'      FindClose hFind
'      FUNCTION = fd.dwFileAttributes
'   END IF
'END FUNCTION
'' ========================================================================================
FUNCTION AfxGetFileAttributes (BYVAL bstrFileSpec AS WSTRING) AS DWORD
   FUNCTION = GetFileAttributesW(BYCOPY bstrFileSpec)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns TRUE if the specified path is a file; FALSE, otherwise.
' ========================================================================================
FUNCTION AfxIsFile (BYVAL bstrFileSpec AS WSTRING) AS LONG
   LOCAL dwAttributes AS DWORD
   dwAttributes = GetFileAttributesW(BYCOPY bstrFileSpec)
   IF dwAttributes = %INVALID_FILE_ATTRIBUTES THEN EXIT FUNCTION
   FUNCTION = ((dwAttributes AND %FILE_ATTRIBUTE_DIRECTORY) <> %FILE_ATTRIBUTE_DIRECTORY)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns TRUE if the specified path is a directory; FALSE, otherwise.
' ========================================================================================
FUNCTION AfxIsFolder (BYVAL bstrFileSpec AS WSTRING) AS LONG
   LOCAL dwAttributes AS DWORD
   dwAttributes = GetFileAttributesW(BYCOPY bstrFileSpec)
   IF dwAttributes = %INVALID_FILE_ATTRIBUTES THEN EXIT FUNCTION
   FUNCTION = ((dwAttributes AND %FILE_ATTRIBUTE_DIRECTORY) = %FILE_ATTRIBUTE_DIRECTORY)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns TRUE if the specified path is a system file; FALSE, otherwise.
' ========================================================================================
FUNCTION AfxIsSystemFile (BYVAL bstrFileSpec AS WSTRING) AS LONG
   LOCAL dwAttributes AS DWORD
   dwAttributes = GetFileAttributesW(BYCOPY bstrFileSpec)
   IF dwAttributes = %INVALID_FILE_ATTRIBUTES THEN EXIT FUNCTION
   FUNCTION = ((dwAttributes AND %FILE_ATTRIBUTE_SYSTEM) = %FILE_ATTRIBUTE_SYSTEM)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns TRUE if the specified path is a hidden file; FALSE, otherwise.
' ========================================================================================
FUNCTION AfxIsHiddenFile (BYVAL bstrFileSpec AS WSTRING) AS LONG
   LOCAL dwAttributes AS DWORD
   dwAttributes = GetFileAttributesW(BYCOPY bstrFileSpec)
   IF dwAttributes = %INVALID_FILE_ATTRIBUTES THEN EXIT FUNCTION
   FUNCTION = ((dwAttributes AND %FILE_ATTRIBUTE_HIDDEN) = %FILE_ATTRIBUTE_HIDDEN)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns TRUE if the specified path is a read only file; FALSE, otherwise.
' ========================================================================================
FUNCTION AfxIsReadOnlyFile (BYVAL bstrFileSpec AS WSTRING) AS LONG
   LOCAL dwAttributes AS DWORD
   dwAttributes = GetFileAttributesW(BYCOPY bstrFileSpec)
   IF dwAttributes = %INVALID_FILE_ATTRIBUTES THEN EXIT FUNCTION
   FUNCTION = ((dwAttributes AND %FILE_ATTRIBUTE_READONLY) = %FILE_ATTRIBUTE_READONLY)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns TRUE if the specified path is a temporary file; FALSE, otherwise.
' ========================================================================================
FUNCTION AfxIsTemporaryFile (BYVAL bstrFileSpec AS WSTRING) AS LONG
   LOCAL dwAttributes AS DWORD
   dwAttributes = GetFileAttributesW(BYCOPY bstrFileSpec)
   IF dwAttributes = %INVALID_FILE_ATTRIBUTES THEN EXIT FUNCTION
   FUNCTION = ((dwAttributes AND %FILE_ATTRIBUTE_TEMPORARY) = %FILE_ATTRIBUTE_TEMPORARY)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns TRUE if the specified path is a normal file; FALSE, otherwise.
' ========================================================================================
FUNCTION AfxIsNormalFile (BYVAL bstrFileSpec AS WSTRING) AS LONG
   LOCAL dwAttributes AS DWORD
   dwAttributes = GetFileAttributesW(BYCOPY bstrFileSpec)
   IF dwAttributes = %INVALID_FILE_ATTRIBUTES THEN EXIT FUNCTION
   FUNCTION = ((dwAttributes AND %FILE_ATTRIBUTE_NORMAL) = %FILE_ATTRIBUTE_NORMAL)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns TRUE if the specified path is a compressed file or diectory; FALSE, otherwise.
' ========================================================================================
FUNCTION AfxIsCompressedFile (BYVAL bstrFileSpec AS WSTRING) AS LONG
   LOCAL dwAttributes AS DWORD
   dwAttributes = GetFileAttributesW(BYCOPY bstrFileSpec)
   IF dwAttributes = %INVALID_FILE_ATTRIBUTES THEN EXIT FUNCTION
   FUNCTION = ((dwAttributes AND %FILE_ATTRIBUTE_COMPRESSED) = %FILE_ATTRIBUTE_COMPRESSED)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns TRUE if the specified path is an encrypted file or diectory; FALSE, otherwise.
' ========================================================================================
FUNCTION AfxIsEncryptedFile (BYVAL bstrFileSpec AS WSTRING) AS LONG
   LOCAL dwAttributes AS DWORD
   dwAttributes = GetFileAttributesW(BYCOPY bstrFileSpec)
   IF dwAttributes = %INVALID_FILE_ATTRIBUTES THEN EXIT FUNCTION
   FUNCTION = ((dwAttributes AND %FILE_ATTRIBUTE_ENCRYPTED) = %FILE_ATTRIBUTE_ENCRYPTED)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns TRUE if the specified file or directory is not to be indexed by the content
' indexing service; FALSE, otherwise.
' ========================================================================================
FUNCTION AfxIsNotContentIndexedFile (BYVAL bstrFileSpec AS WSTRING) AS LONG
   LOCAL dwAttributes AS DWORD
   dwAttributes = GetFileAttributesW(BYCOPY bstrFileSpec)
   IF dwAttributes = %INVALID_FILE_ATTRIBUTES THEN EXIT FUNCTION
   FUNCTION = ((dwAttributes AND %FILE_ATTRIBUTE_NOT_CONTENT_INDEXED) = %FILE_ATTRIBUTE_NOT_CONTENT_INDEXED)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns TRUE if the specified file is not available immediately; FALSE, otherwise.
' ========================================================================================
FUNCTION AfxIsOffLineFile (BYVAL bstrFileSpec AS WSTRING) AS LONG
   LOCAL dwAttributes AS DWORD
   dwAttributes = GetFileAttributesW(BYCOPY bstrFileSpec)
   IF dwAttributes = %INVALID_FILE_ATTRIBUTES THEN EXIT FUNCTION
   FUNCTION = ((dwAttributes AND %FILE_ATTRIBUTE_OFFLINE) = %FILE_ATTRIBUTE_OFFLINE)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns TRUE if the specified path is a file or directory that has an associated reparse
' point, or a file that is a symbolic link; FALSE, otherwise.
' ========================================================================================
FUNCTION AfxIsReparsePointFile (BYVAL bstrFileSpec AS WSTRING) AS LONG
   LOCAL dwAttributes AS DWORD
   dwAttributes = GetFileAttributesW(BYCOPY bstrFileSpec)
   IF dwAttributes = %INVALID_FILE_ATTRIBUTES THEN EXIT FUNCTION
   FUNCTION = ((dwAttributes AND %FILE_ATTRIBUTE_REPARSE_POINT) = %FILE_ATTRIBUTE_REPARSE_POINT)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns TRUE if the specified path is a sparse file; FALSE, otherwise.
' ========================================================================================
FUNCTION AfxIsSparseFile (BYVAL bstrFileSpec AS WSTRING) AS LONG
   LOCAL dwAttributes AS DWORD
   dwAttributes = GetFileAttributesW(BYCOPY bstrFileSpec)
   IF dwAttributes = %INVALID_FILE_ATTRIBUTES THEN EXIT FUNCTION
   FUNCTION = ((dwAttributes AND %FILE_ATTRIBUTE_SPARSE_FILE) = %FILE_ATTRIBUTE_SPARSE_FILE)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the size in bytes of the specified file.
' ========================================================================================
FUNCTION AfxGetFileSize (BYVAL bstrFileSpec AS WSTRING) AS QUAD

   LOCAL hFind AS DWORD
   LOCAL fd AS WIN32_FIND_DATAW
   LOCAL qSize AS QUAD

   IF ISTRUE LEN(bstrFileSpec) THEN
      hFind = FindFirstFileW(BYCOPY bstrFileSpec, fd)
      IF BITSE(hFind, %INVALID_HANDLE_VALUE, 32) THEN EXIT FUNCTION
      FindClose hFind
      ' // Make sure that is not a directory or a temporary file
      IF (fd.dwFileAttributes AND %FILE_ATTRIBUTE_DIRECTORY) <> %FILE_ATTRIBUTE_DIRECTORY AND _
         (fd.dwFileAttributes AND %FILE_ATTRIBUTE_TEMPORARY) <> %FILE_ATTRIBUTE_TEMPORARY THEN
         qSize = (fd.nFileSizeHigh * (&HFFFFFFFF??? + 1)) + fd.nFileSizeLow
         FUNCTION = qSize
      END IF
   END IF

END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the time the file was created, in UTC format.
' ========================================================================================
FUNCTION AfxGetFileCreationTimeUTC (BYVAL bstrFileSpec AS WSTRING) AS QUAD

   LOCAL hFind AS DWORD
   LOCAL fd AS WIN32_FIND_DATAW

   IF ISTRUE LEN(bstrFileSpec) THEN
      hFind = FindFirstFileW(BYCOPY bstrFileSpec, fd)
      IF BITSE(hFind, %INVALID_HANDLE_VALUE, 32) THEN EXIT FUNCTION
      FindClose hFind
      ' // Make sure that is not a directory or a temporary file
      IF (fd.dwFileAttributes AND %FILE_ATTRIBUTE_DIRECTORY) <> %FILE_ATTRIBUTE_DIRECTORY AND _
         (fd.dwFileAttributes AND %FILE_ATTRIBUTE_TEMPORARY) <> %FILE_ATTRIBUTE_TEMPORARY THEN
         FUNCTION = fd.ftCreationTime.qDateTime
      END IF
   END IF

END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the time the file was created, in local time format.
' ========================================================================================
FUNCTION AfxGetFileCreationTime (BYVAL bstrFileSpec AS WSTRING) AS QUAD

   LOCAL hFind AS DWORD
   LOCAL fd AS WIN32_FIND_DATAW
   LOCAL FT AS FILETIME

   IF ISTRUE LEN(bstrFileSpec) THEN
      hFind = FindFirstFileW(BYCOPY bstrFileSpec, fd)
      IF BITSE(hFind, %INVALID_HANDLE_VALUE, 32) THEN EXIT FUNCTION
      FindClose hFind
      ' // Make sure that is not a directory or a temporary file
      IF (fd.dwFileAttributes AND %FILE_ATTRIBUTE_DIRECTORY) <> %FILE_ATTRIBUTE_DIRECTORY AND _
         (fd.dwFileAttributes AND %FILE_ATTRIBUTE_TEMPORARY) <> %FILE_ATTRIBUTE_TEMPORARY THEN
         IF FileTimeToLocalFileTime(fd.ftCreationTime, FT) THEN
            FUNCTION = FT.qDateTime
         END IF
      END IF
   END IF

END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the time the file was created, in UTC format, as a string.
' ========================================================================================
FUNCTION AfxGetFileCreationTimeUTCStr (BYVAL bstrFileSpec AS WSTRING, OPTIONAL BYVAL bstrDateMask AS WSTRING, BYVAL bstrTimeMask AS WSTRING, OPTIONAL BYVAL lcid AS DWORD) AS WSTRING

   LOCAL hFind AS DWORD
   LOCAL fd AS WIN32_FIND_DATAW
   LOCAL ST AS SYSTEMTIME
   LOCAL bstrDateTime AS WSTRING
   LOCAL wszDate AS WSTRINGZ * 260
   LOCAL wszTime AS WSTRINGZ * 260

   IF bstrDateMask = "" THEN bstrDateMask = "dddd, dd MMMM yyyy"
   IF bstrTimeMask = "" THEN bstrTimeMask = "hh:mm:ss"
   IF lcid = 0 THEN lcid = %LOCALE_USER_DEFAULT
   IF ISTRUE LEN(bstrFileSpec) THEN
      hFind = FindFirstFileW(BYCOPY bstrFileSpec, fd)
      IF BITSE(hFind, %INVALID_HANDLE_VALUE, 32) THEN EXIT FUNCTION
      FindClose hFind
      ' // Make sure that is not a directory or a temporary file
      IF (fd.dwFileAttributes AND %FILE_ATTRIBUTE_DIRECTORY) <> %FILE_ATTRIBUTE_DIRECTORY AND _
         (fd.dwFileAttributes AND %FILE_ATTRIBUTE_TEMPORARY) <> %FILE_ATTRIBUTE_TEMPORARY THEN
         IF FileTimeToSystemTime(fd.ftCreationTime, ST) THEN
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
            FUNCTION = bstrDateTime
         END IF
      END IF
   END IF

END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the time the file was created, in local time format, as a string.
' ========================================================================================
FUNCTION AfxGetFileCreationTimeStr (BYVAL bstrFileSpec AS WSTRING, OPTIONAL BYVAL bstrDateMask AS WSTRING, BYVAL bstrTimeMask AS WSTRING, OPTIONAL BYVAL lcid AS DWORD) AS WSTRING

   LOCAL hFind AS DWORD
   LOCAL fd AS WIN32_FIND_DATAW
   LOCAL FT AS FILETIME
   LOCAL ST AS SYSTEMTIME
   LOCAL bstrDateTime AS WSTRING
   LOCAL wszDate AS WSTRINGZ * 260
   LOCAL wszTime AS WSTRINGZ * 260

   IF bstrDateMask = "" THEN bstrDateMask = "dddd, dd MMMM yyyy"
   IF bstrTimeMask = "" THEN bstrTimeMask = "hh:mm:ss"
   IF lcid = 0 THEN lcid = %LOCALE_USER_DEFAULT
   IF ISTRUE LEN(bstrFileSpec) THEN
      hFind = FindFirstFileW(BYCOPY bstrFileSpec, fd)
      IF BITSE(hFind, %INVALID_HANDLE_VALUE, 32) THEN EXIT FUNCTION
      FindClose hFind
      ' // Make sure that is not a directory or a temporary file
      IF (fd.dwFileAttributes AND %FILE_ATTRIBUTE_DIRECTORY) <> %FILE_ATTRIBUTE_DIRECTORY AND _
         (fd.dwFileAttributes AND %FILE_ATTRIBUTE_TEMPORARY) <> %FILE_ATTRIBUTE_TEMPORARY THEN
         IF FileTimeToLocalFileTime(fd.ftCreationTime, FT) THEN
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
               FUNCTION = bstrDateTime
            END IF
         END IF
      END IF
   END IF

END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the time the file was last accessed, in UTC format.
' ========================================================================================
FUNCTION AfxGetFileLastAccessTimeUTC (BYVAL bstrFileSpec AS WSTRING) AS QUAD

   LOCAL hFind AS DWORD
   LOCAL fd AS WIN32_FIND_DATAW

   IF ISTRUE LEN(bstrFileSpec) THEN
      hFind = FindFirstFileW(BYCOPY bstrFileSpec, fd)
      IF BITSE(hFind, %INVALID_HANDLE_VALUE, 32) THEN EXIT FUNCTION
      FindClose hFind
      ' // Make sure that is not a directory or a temporary file
      IF (fd.dwFileAttributes AND %FILE_ATTRIBUTE_DIRECTORY) <> %FILE_ATTRIBUTE_DIRECTORY AND _
         (fd.dwFileAttributes AND %FILE_ATTRIBUTE_TEMPORARY) <> %FILE_ATTRIBUTE_TEMPORARY THEN
         FUNCTION = fd.ftLastAccessTime.qDateTime
      END IF
   END IF

END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the time the file was last accessed, in local time format.
' ========================================================================================
FUNCTION AfxGetFileLastAccessTime (BYVAL bstrFileSpec AS WSTRING) AS QUAD

   LOCAL hFind AS DWORD
   LOCAL fd AS WIN32_FIND_DATAW
   LOCAL FT AS FILETIME

   IF ISTRUE LEN(bstrFileSpec) THEN
      hFind = FindFirstFileW(BYCOPY bstrFileSpec, fd)
      IF BITSE(hFind, %INVALID_HANDLE_VALUE, 32) THEN EXIT FUNCTION
      FindClose hFind
      ' // Make sure that is not a directory or a temporary file
      IF (fd.dwFileAttributes AND %FILE_ATTRIBUTE_DIRECTORY) <> %FILE_ATTRIBUTE_DIRECTORY AND _
         (fd.dwFileAttributes AND %FILE_ATTRIBUTE_TEMPORARY) <> %FILE_ATTRIBUTE_TEMPORARY THEN
         IF FileTimeToLocalFileTime(fd.ftLastAccessTime, FT) THEN
            FUNCTION = FT.qDateTime
         END IF
      END IF
   END IF

END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the time the file was last accessed, in UTC format, as a string.
' ========================================================================================
FUNCTION AfxGetFileLastAccessTimeUTCStr (BYVAL bstrFileSpec AS WSTRING, OPTIONAL BYVAL bstrDateMask AS WSTRING, BYVAL bstrTimeMask AS WSTRING, OPTIONAL BYVAL lcid AS DWORD) AS WSTRING

   LOCAL hFind AS DWORD
   LOCAL fd AS WIN32_FIND_DATAW
   LOCAL ST AS SYSTEMTIME
   LOCAL bstrDateTime AS WSTRING
   LOCAL wszDate AS WSTRINGZ * 260
   LOCAL wszTime AS WSTRINGZ * 260

   IF bstrDateMask = "" THEN bstrDateMask = "dddd, dd MMMM yyyy"
   IF bstrTimeMask = "" THEN bstrTimeMask = "hh:mm:ss"
   IF lcid = 0 THEN lcid = %LOCALE_USER_DEFAULT
   IF ISTRUE LEN(bstrFileSpec) THEN
      hFind = FindFirstFileW(BYCOPY bstrFileSpec, fd)
      IF BITSE(hFind, %INVALID_HANDLE_VALUE, 32) THEN EXIT FUNCTION
      FindClose hFind
      ' // Make sure that is not a directory or a temporary file
      IF (fd.dwFileAttributes AND %FILE_ATTRIBUTE_DIRECTORY) <> %FILE_ATTRIBUTE_DIRECTORY AND _
         (fd.dwFileAttributes AND %FILE_ATTRIBUTE_TEMPORARY) <> %FILE_ATTRIBUTE_TEMPORARY THEN
         IF FileTimeToSystemTime(fd.ftLastAccessTime, ST) THEN
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
            FUNCTION = bstrDateTime
         END IF
      END IF
   END IF

END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the time the file was last accessed, in local time format, as a string.
' ========================================================================================
FUNCTION AfxGetFileLastAccessTimeStr (BYVAL bstrFileSpec AS WSTRING, OPTIONAL BYVAL bstrDateMask AS WSTRING, BYVAL bstrTimeMask AS WSTRING, OPTIONAL BYVAL lcid AS DWORD) AS WSTRING

   LOCAL hFind AS DWORD
   LOCAL fd AS WIN32_FIND_DATAW
   LOCAL FT AS FILETIME
   LOCAL ST AS SYSTEMTIME
   LOCAL bstrDateTime AS WSTRING
   LOCAL wszDate AS WSTRINGZ * 260
   LOCAL wszTime AS WSTRINGZ * 260

   IF bstrDateMask = "" THEN bstrDateMask = "dddd, dd MMMM yyyy"
   IF bstrTimeMask = "" THEN bstrTimeMask = "hh:mm:ss"
   IF lcid = 0 THEN lcid = %LOCALE_USER_DEFAULT
   IF ISTRUE LEN(bstrFileSpec) THEN
      hFind = FindFirstFileW(BYCOPY bstrFileSpec, fd)
      IF BITSE(hFind, %INVALID_HANDLE_VALUE, 32) THEN EXIT FUNCTION
      FindClose hFind
      ' // Make sure that is not a directory or a temporary file
      IF (fd.dwFileAttributes AND %FILE_ATTRIBUTE_DIRECTORY) <> %FILE_ATTRIBUTE_DIRECTORY AND _
         (fd.dwFileAttributes AND %FILE_ATTRIBUTE_TEMPORARY) <> %FILE_ATTRIBUTE_TEMPORARY THEN
         IF FileTimeToLocalFileTime(fd.ftLastAccessTime, FT) THEN
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
               FUNCTION = bstrDateTime
            END IF
         END IF
      END IF
   END IF

END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the time the file was last accessed in UTC format.
' ========================================================================================
FUNCTION AfxGetFileLastWriteTimeUTC (BYVAL bstrFileSpec AS WSTRING) AS QUAD

   LOCAL hFind AS DWORD
   LOCAL fd AS WIN32_FIND_DATAW

   IF ISTRUE LEN(bstrFileSpec) THEN
      hFind = FindFirstFileW(BYCOPY bstrFileSpec, fd)
      IF BITSE(hFind, %INVALID_HANDLE_VALUE, 32) THEN EXIT FUNCTION
      FindClose hFind
      ' // Make sure that is not a directory or a temporary file
      IF (fd.dwFileAttributes AND %FILE_ATTRIBUTE_DIRECTORY) <> %FILE_ATTRIBUTE_DIRECTORY AND _
         (fd.dwFileAttributes AND %FILE_ATTRIBUTE_TEMPORARY) <> %FILE_ATTRIBUTE_TEMPORARY THEN
         FUNCTION = fd.ftLastWriteTime.qDateTime
      END IF
   END IF

END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the time the file was written to, truncated, or overwritten, in local time format.
' ========================================================================================
FUNCTION AfxGetFileLastWriteTime (BYVAL bstrFileSpec AS WSTRING) AS QUAD

   LOCAL hFind AS DWORD
   LOCAL fd AS WIN32_FIND_DATAW
   LOCAL FT AS FILETIME

   IF ISTRUE LEN(bstrFileSpec) THEN
      hFind = FindFirstFileW(BYCOPY bstrFileSpec, fd)
      IF BITSE(hFind, %INVALID_HANDLE_VALUE, 32) THEN EXIT FUNCTION
      FindClose hFind
      ' // Make sure that is not a directory or a temporary file
      IF (fd.dwFileAttributes AND %FILE_ATTRIBUTE_DIRECTORY) <> %FILE_ATTRIBUTE_DIRECTORY AND _
         (fd.dwFileAttributes AND %FILE_ATTRIBUTE_TEMPORARY) <> %FILE_ATTRIBUTE_TEMPORARY THEN
         IF FileTimeToLocalFileTime(fd.ftLastWriteTime, FT) THEN
            FUNCTION = FT.qDateTime
         END IF
      END IF
   END IF

END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the time the file was written to, truncated, or overwritten, in UTC format, as a string.
' ========================================================================================
FUNCTION AfxGetFileLastWriteTimeUTCStr (BYVAL bstrFileSpec AS WSTRING, OPTIONAL BYVAL bstrDateMask AS WSTRING, BYVAL bstrTimeMask AS WSTRING, OPTIONAL BYVAL lcid AS DWORD) AS WSTRING

   LOCAL hFind AS DWORD
   LOCAL fd AS WIN32_FIND_DATAW
   LOCAL ST AS SYSTEMTIME
   LOCAL bstrDateTime AS WSTRING
   LOCAL wszDate AS WSTRINGZ * 260
   LOCAL wszTime AS WSTRINGZ * 260

   IF bstrDateMask = "" THEN bstrDateMask = "dddd, dd MMMM yyyy"
   IF bstrTimeMask = "" THEN bstrTimeMask = "hh:mm:ss"
   IF lcid = 0 THEN lcid = %LOCALE_USER_DEFAULT
   IF ISTRUE LEN(bstrFileSpec) THEN
      hFind = FindFirstFileW(BYCOPY bstrFileSpec, fd)
      IF BITSE(hFind, %INVALID_HANDLE_VALUE, 32) THEN EXIT FUNCTION
      FindClose hFind
      ' // Make sure that is not a directory or a temporary file
      IF (fd.dwFileAttributes AND %FILE_ATTRIBUTE_DIRECTORY) <> %FILE_ATTRIBUTE_DIRECTORY AND _
         (fd.dwFileAttributes AND %FILE_ATTRIBUTE_TEMPORARY) <> %FILE_ATTRIBUTE_TEMPORARY THEN
         IF FileTimeToSystemTime(fd.ftLastWriteTime, ST) THEN
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
            FUNCTION = bstrDateTime
         END IF
      END IF
   END IF

END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the time the file was written to, truncated, or overwritten, in local time format, as a string.
' ========================================================================================
FUNCTION AfxGetFileLastWriteTimeStr (BYVAL bstrFileSpec AS WSTRING, OPTIONAL BYVAL bstrDateMask AS WSTRING, BYVAL bstrTimeMask AS WSTRING, OPTIONAL BYVAL lcid AS DWORD) AS WSTRING

   LOCAL hFind AS DWORD
   LOCAL fd AS WIN32_FIND_DATAW
   LOCAL FT AS FILETIME
   LOCAL ST AS SYSTEMTIME
   LOCAL bstrDateTime AS WSTRING
   LOCAL wszDate AS WSTRINGZ * 260
   LOCAL wszTime AS WSTRINGZ * 260

   IF bstrDateMask = "" THEN bstrDateMask = "dddd, dd MMMM yyyy"
   IF bstrTimeMask = "" THEN bstrTimeMask = "hh:mm:ss"
   IF lcid = 0 THEN lcid = %LOCALE_USER_DEFAULT
   IF ISTRUE LEN(bstrFileSpec) THEN
      hFind = FindFirstFileW(BYCOPY bstrFileSpec, fd)
      IF BITSE(hFind, %INVALID_HANDLE_VALUE, 32) THEN EXIT FUNCTION
      FindClose hFind
      ' // Make sure that is not a directory or a temporary file
      IF (fd.dwFileAttributes AND %FILE_ATTRIBUTE_DIRECTORY) <> %FILE_ATTRIBUTE_DIRECTORY AND _
         (fd.dwFileAttributes AND %FILE_ATTRIBUTE_TEMPORARY) <> %FILE_ATTRIBUTE_TEMPORARY THEN
         IF FileTimeToLocalFileTime(fd.ftLastWriteTime, FT) THEN
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
               FUNCTION = bstrDateTime
            END IF
         END IF
      END IF
   END IF

END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the time the folder was created, in UTC format.
' ========================================================================================
FUNCTION AfxGetFolderCreationTimeUTC (BYVAL bstrFileSpec AS WSTRING) AS QUAD

   LOCAL hFind AS DWORD
   LOCAL fd AS WIN32_FIND_DATAW

   IF ISTRUE LEN(bstrFileSpec) THEN
      hFind = FindFirstFileW(BYCOPY bstrFileSpec, fd)
      IF BITSE(hFind, %INVALID_HANDLE_VALUE, 32) THEN EXIT FUNCTION
      FindClose hFind
      IF (fd.dwFileAttributes AND %FILE_ATTRIBUTE_DIRECTORY) = %FILE_ATTRIBUTE_DIRECTORY THEN
         FUNCTION = fd.ftCreationTime.qDateTime
      END IF
   END IF

END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the time the folder was created, in local time format.
' ========================================================================================
FUNCTION AfxGetFolderCreationTime (BYVAL bstrFileSpec AS WSTRING) AS QUAD

   LOCAL hFind AS DWORD
   LOCAL fd AS WIN32_FIND_DATAW
   LOCAL FT AS FILETIME

   IF ISTRUE LEN(bstrFileSpec) THEN
      hFind = FindFirstFileW(BYCOPY bstrFileSpec, fd)
      IF BITSE(hFind, %INVALID_HANDLE_VALUE, 32) THEN EXIT FUNCTION
      FindClose hFind
      IF (fd.dwFileAttributes AND %FILE_ATTRIBUTE_DIRECTORY) = %FILE_ATTRIBUTE_DIRECTORY THEN
         IF FileTimeToLocalFileTime(fd.ftCreationTime, FT) THEN
            FUNCTION = FT.qDateTime
         END IF
      END IF
   END IF

END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the time the folder was created, in UTC format, as a string.
' ========================================================================================
FUNCTION AfxGetFolderCreationTimeUTCStr (BYVAL bstrFileSpec AS WSTRING, OPTIONAL BYVAL bstrDateMask AS WSTRING, BYVAL bstrTimeMask AS WSTRING, OPTIONAL BYVAL lcid AS DWORD) AS WSTRING

   LOCAL hFind AS DWORD
   LOCAL fd AS WIN32_FIND_DATAW
   LOCAL ST AS SYSTEMTIME
   LOCAL bstrDateTime AS WSTRING
   LOCAL wszDate AS WSTRINGZ * 260
   LOCAL wszTime AS WSTRINGZ * 260

   IF bstrDateMask = "" THEN bstrDateMask = "dddd, dd MMMM yyyy"
   IF bstrTimeMask = "" THEN bstrTimeMask = "hh:mm:ss"
   IF lcid = 0 THEN lcid = %LOCALE_USER_DEFAULT
   IF ISTRUE LEN(bstrFileSpec) THEN
      hFind = FindFirstFileW(BYCOPY bstrFileSpec, fd)
      IF BITSE(hFind, %INVALID_HANDLE_VALUE, 32) THEN EXIT FUNCTION
      FindClose hFind
      IF (fd.dwFileAttributes AND %FILE_ATTRIBUTE_DIRECTORY) = %FILE_ATTRIBUTE_DIRECTORY THEN
         IF FileTimeToSystemTime(fd.ftCreationTime, ST) THEN
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
            FUNCTION = bstrDateTime
         END IF
      END IF
   END IF

END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the time the folder was created, in local time format, as a string.
' ========================================================================================
FUNCTION AfxGetFolderCreationTimeStr (BYVAL bstrFileSpec AS WSTRING, OPTIONAL BYVAL bstrDateMask AS WSTRING, BYVAL bstrTimeMask AS WSTRING, OPTIONAL BYVAL lcid AS DWORD) AS WSTRING

   LOCAL hFind AS DWORD
   LOCAL fd AS WIN32_FIND_DATAW
   LOCAL FT AS FILETIME
   LOCAL ST AS SYSTEMTIME
   LOCAL bstrDateTime AS WSTRING
   LOCAL wszDate AS WSTRINGZ * 260
   LOCAL wszTime AS WSTRINGZ * 260

   IF bstrDateMask = "" THEN bstrDateMask = "dddd, dd MMMM yyyy"
   IF bstrTimeMask = "" THEN bstrTimeMask = "hh:mm:ss"
   IF lcid = 0 THEN lcid = %LOCALE_USER_DEFAULT
   IF ISTRUE LEN(bstrFileSpec) THEN
      hFind = FindFirstFileW(BYCOPY bstrFileSpec, fd)
      IF BITSE(hFind, %INVALID_HANDLE_VALUE, 32) THEN EXIT FUNCTION
      FindClose hFind
      IF (fd.dwFileAttributes AND %FILE_ATTRIBUTE_DIRECTORY) = %FILE_ATTRIBUTE_DIRECTORY THEN
         IF FileTimeToLocalFileTime(fd.ftCreationTime, FT) THEN
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
               FUNCTION = bstrDateTime
            END IF
         END IF
      END IF
   END IF

END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the time the file was last accessed, in UTC format.
' ========================================================================================
FUNCTION AfxGetFolderLastAccessTimeUTC (BYVAL bstrFileSpec AS WSTRING) AS QUAD

   LOCAL hFind AS DWORD
   LOCAL fd AS WIN32_FIND_DATAW

   IF ISTRUE LEN(bstrFileSpec) THEN
      hFind = FindFirstFileW(BYCOPY bstrFileSpec, fd)
      IF BITSE(hFind, %INVALID_HANDLE_VALUE, 32) THEN EXIT FUNCTION
      FindClose hFind
      IF (fd.dwFileAttributes AND %FILE_ATTRIBUTE_DIRECTORY) = %FILE_ATTRIBUTE_DIRECTORY THEN
         FUNCTION = fd.ftLastAccessTime.qDateTime
      END IF
   END IF

END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the time the file was last accessed, in local time format.
' ========================================================================================
FUNCTION AfxGetFolderLastAccessTime (BYVAL bstrFileSpec AS WSTRING) AS QUAD

   LOCAL hFind AS DWORD
   LOCAL fd AS WIN32_FIND_DATAW
   LOCAL FT AS FILETIME

   IF ISTRUE LEN(bstrFileSpec) THEN
      hFind = FindFirstFileW(BYCOPY bstrFileSpec, fd)
      IF BITSE(hFind, %INVALID_HANDLE_VALUE, 32) THEN EXIT FUNCTION
      FindClose hFind
      IF (fd.dwFileAttributes AND %FILE_ATTRIBUTE_DIRECTORY) = %FILE_ATTRIBUTE_DIRECTORY THEN
         IF FileTimeToLocalFileTime(fd.ftLastAccessTime, FT) THEN
            FUNCTION = FT.qDateTime
         END IF
      END IF
   END IF

END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the time the folder was last accessed, in UTC format.
' ========================================================================================
FUNCTION AfxGetFolderLastAccessTimeUTCStr (BYVAL bstrFileSpec AS WSTRING, OPTIONAL BYVAL bstrDateMask AS WSTRING, BYVAL bstrTimeMask AS WSTRING, OPTIONAL BYVAL lcid AS DWORD) AS WSTRING

   LOCAL hFind AS DWORD
   LOCAL fd AS WIN32_FIND_DATAW
   LOCAL ST AS SYSTEMTIME
   LOCAL bstrDateTime AS WSTRING
   LOCAL wszDate AS WSTRINGZ * 260
   LOCAL wszTime AS WSTRINGZ * 260

   IF bstrDateMask = "" THEN bstrDateMask = "dddd, dd MMMM yyyy"
   IF bstrTimeMask = "" THEN bstrTimeMask = "hh:mm:ss"
   IF lcid = 0 THEN lcid = %LOCALE_USER_DEFAULT
   IF ISTRUE LEN(bstrFileSpec) THEN
      hFind = FindFirstFileW(BYCOPY bstrFileSpec, fd)
      IF BITSE(hFind, %INVALID_HANDLE_VALUE, 32) THEN EXIT FUNCTION
      FindClose hFind
      IF (fd.dwFileAttributes AND %FILE_ATTRIBUTE_DIRECTORY) = %FILE_ATTRIBUTE_DIRECTORY THEN
         IF FileTimeToSystemTime(fd.ftLastAccessTime, ST) THEN
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
            FUNCTION = bstrDateTime
         END IF
      END IF
   END IF

END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the time the folder was last accessed, in local time format.
' ========================================================================================
FUNCTION AfxGetFolderLastAccessTimeStr (BYVAL bstrFileSpec AS WSTRING, OPTIONAL BYVAL bstrDateMask AS WSTRING, BYVAL bstrTimeMask AS WSTRING, OPTIONAL BYVAL lcid AS DWORD) AS WSTRING

   LOCAL hFind AS DWORD
   LOCAL fd AS WIN32_FIND_DATAW
   LOCAL FT AS FILETIME
   LOCAL ST AS SYSTEMTIME
   LOCAL bstrDateTime AS WSTRING
   LOCAL wszDate AS WSTRINGZ * 260
   LOCAL wszTime AS WSTRINGZ * 260

   IF bstrDateMask = "" THEN bstrDateMask = "dddd, dd MMMM yyyy"
   IF bstrTimeMask = "" THEN bstrTimeMask = "hh:mm:ss"
   IF lcid = 0 THEN lcid = %LOCALE_USER_DEFAULT
   IF ISTRUE LEN(bstrFileSpec) THEN
      hFind = FindFirstFileW(BYCOPY bstrFileSpec, fd)
      IF BITSE(hFind, %INVALID_HANDLE_VALUE, 32) THEN EXIT FUNCTION
      FindClose hFind
      IF (fd.dwFileAttributes AND %FILE_ATTRIBUTE_DIRECTORY) = %FILE_ATTRIBUTE_DIRECTORY THEN
         IF FileTimeToLocalFileTime(fd.ftLastAccessTime, FT) THEN
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
               FUNCTION = bstrDateTime
            END IF
         END IF
      END IF
   END IF

END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the time the file was last wriiten to, in UTC format.
' ========================================================================================
FUNCTION AfxGetFolderLastWriteTimeUTC (BYVAL bstrFileSpec AS WSTRING) AS QUAD

   LOCAL hFind AS DWORD
   LOCAL fd AS WIN32_FIND_DATAW

   IF ISTRUE LEN(bstrFileSpec) THEN
      hFind = FindFirstFileW(BYCOPY bstrFileSpec, fd)
      IF BITSE(hFind, %INVALID_HANDLE_VALUE, 32) THEN EXIT FUNCTION
      FindClose hFind
      IF (fd.dwFileAttributes AND %FILE_ATTRIBUTE_DIRECTORY) = %FILE_ATTRIBUTE_DIRECTORY THEN
         FUNCTION = fd.ftLastWriteTime.qDateTime
      END IF
   END IF

END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the time the file was last written to, in local time format.
' ========================================================================================
FUNCTION AfxGetFolderLastWriteTime (BYVAL bstrFileSpec AS WSTRING) AS QUAD

   LOCAL hFind AS DWORD
   LOCAL fd AS WIN32_FIND_DATAW
   LOCAL FT AS FILETIME

   IF ISTRUE LEN(bstrFileSpec) THEN
      hFind = FindFirstFileW(BYCOPY bstrFileSpec, fd)
      IF BITSE(hFind, %INVALID_HANDLE_VALUE, 32) THEN EXIT FUNCTION
      FindClose hFind
      IF (fd.dwFileAttributes AND %FILE_ATTRIBUTE_DIRECTORY) = %FILE_ATTRIBUTE_DIRECTORY THEN
         IF FileTimeToLocalFileTime(fd.ftLastWriteTime, FT) THEN
            FUNCTION = FT.qDateTime
         END IF
      END IF
   END IF

END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the time the folder was last written to, in UTC format, as a string.
' ========================================================================================
FUNCTION AfxGetFolderLastWriteTimeUTCStr (BYVAL bstrFileSpec AS WSTRING, OPTIONAL BYVAL bstrDateMask AS WSTRING, BYVAL bstrTimeMask AS WSTRING, OPTIONAL BYVAL lcid AS DWORD) AS WSTRING

   LOCAL hFind AS DWORD
   LOCAL fd AS WIN32_FIND_DATAW
   LOCAL ST AS SYSTEMTIME
   LOCAL bstrDateTime AS WSTRING
   LOCAL wszDate AS WSTRINGZ * 260
   LOCAL wszTime AS WSTRINGZ * 260

   IF bstrDateMask = "" THEN bstrDateMask = "dddd, dd MMMM yyyy"
   IF bstrTimeMask = "" THEN bstrTimeMask = "hh:mm:ss"
   IF lcid = 0 THEN lcid = %LOCALE_USER_DEFAULT
   IF ISTRUE LEN(bstrFileSpec) THEN
      hFind = FindFirstFileW(BYCOPY bstrFileSpec, fd)
      IF BITSE(hFind, %INVALID_HANDLE_VALUE, 32) THEN EXIT FUNCTION
      FindClose hFind
      IF (fd.dwFileAttributes AND %FILE_ATTRIBUTE_DIRECTORY) = %FILE_ATTRIBUTE_DIRECTORY THEN
         IF FileTimeToSystemTime(fd.ftLastWriteTime, ST) THEN
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
            FUNCTION = bstrDateTime
         END IF
      END IF
   END IF

END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the time the folder was last written to, in local time format, as a string.
' ========================================================================================
FUNCTION AfxGetFolderLastWriteTimeStr (BYVAL bstrFileSpec AS WSTRING, OPTIONAL BYVAL bstrDateMask AS WSTRING, BYVAL bstrTimeMask AS WSTRING, OPTIONAL BYVAL lcid AS DWORD) AS WSTRING

   LOCAL hFind AS DWORD
   LOCAL fd AS WIN32_FIND_DATAW
   LOCAL FT AS FILETIME
   LOCAL ST AS SYSTEMTIME
   LOCAL bstrDateTime AS WSTRING
   LOCAL wszDate AS WSTRINGZ * 260
   LOCAL wszTime AS WSTRINGZ * 260

   IF bstrDateMask = "" THEN bstrDateMask = "dddd, dd MMMM yyyy"
   IF bstrTimeMask = "" THEN bstrTimeMask = "hh:mm:ss"
   IF lcid = 0 THEN lcid = %LOCALE_USER_DEFAULT
   IF ISTRUE LEN(bstrFileSpec) THEN
      hFind = FindFirstFileW(BYCOPY bstrFileSpec, fd)
      IF BITSE(hFind, %INVALID_HANDLE_VALUE, 32) THEN EXIT FUNCTION
      FindClose hFind
      IF (fd.dwFileAttributes AND %FILE_ATTRIBUTE_DIRECTORY) = %FILE_ATTRIBUTE_DIRECTORY THEN
         IF FileTimeToLocalFileTime(fd.ftLastWriteTime, FT) THEN
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
               FUNCTION = bstrDateTime
            END IF
         END IF
      END IF
   END IF

END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the size of a compressed file.
' ========================================================================================
FUNCTION AfxGetCompressedFileSize (BYVAL bstrFile AS WSTRING) AS QUAD

   LOCAL dwAttributes, dwFileSizeHigh, dwFileSizeLow AS DWORD, nError AS LONG

   ' // Check if the file is compressed
   dwAttributes = GetFileAttributesW(BYCOPY bstrFile)
   IF dwAttributes = %INVALID_FILE_ATTRIBUTES THEN EXIT FUNCTION
   IF (dwAttributes AND %FILE_ATTRIBUTE_COMPRESSED) <> %FILE_ATTRIBUTE_COMPRESSED THEN EXIT FUNCTION

   ' // Get the compressed size
   dwFileSizeLow = GetCompressedFileSize(BYVAL STRPTR(bstrFile), dwFileSizeHigh)
   nError = GetLastError
   ' // If the function fails, and dwFileSizeHigh is NULL, the return value is
   ' // INVALID_FILE_SIZE. To get extended error information, call GetLastError.
   ' // If the return value is INVALID_FILE_SIZE and lpFileSizeHigh is non-NULL,
   ' // an application must call GetLastError to determine whether the function
   ' // has succeeded (value is NO_ERROR) or failed (value is other than NO_ERROR).
   IF dwFileSizeLow = %INVALID_FILE_SIZE AND dwFileSizeHigh = 0 THEN EXIT FUNCTION
   IF dwFileSizeLow = %INVALID_FILE_SIZE AND dwFileSizeHigh <> 0 THEN
      IF nError <> %NO_ERROR THEN EXIT FUNCTION
      FUNCTION = dwFileSizeHigh * (2^32)
      EXIT FUNCTION
   END IF
   ' // If the function succeeds, the return value is the low-order DWORD of
   ' // the actual number of bytes of disk storage used to store the specified
   ' // file, and if dwFileSizeHigh is non-NULL, the function puts the high-order
   ' // DWORD of that actual value into the DWORD pointed to by that parameter.
   ' // This is the compressed file size for compressed files, the actual file
   ' // size for noncompressed files.
   IF dwFileSizeHigh > 0 THEN
      FUNCTION = (dwFileSizeHigh * (2^32)) + dwFileSizeLow
   ELSE
      FUNCTION = dwFileSizeLow
   END IF

END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the disk cluster size.
' ========================================================================================
FUNCTION AfxGetDiskClusterSize (BYVAL bstrRootFolder AS WSTRING) AS DWORD
   LOCAL dwSectorsPerCluster, dwBytesPerSector, dwNumberOfFreeClusters, dwTotalNumberOfClusters AS DWORD
   IF bstrRootFolder = "" THEN bstrRootFolder = CURDIR$
   IF LEFT$(bstrRootFolder, 2) <> "\\" THEN
      bstrRootFolder = UCASE$(LEFT$(bstrRootFolder, 1))
      IF INSTR(bstrRootFolder, ANY "ABCDEFGHIJKLMNOPQRSTUVWXYZ") = 0 THEN EXIT FUNCTION
      bstrRootFolder += ":\"
   END IF
   IF GetDiskFreeSpaceW(BYCOPY bstrRootFolder, dwSectorsPerCluster, dwBytesPerSector, _
      dwNumberOfFreeClusters, dwTotalNumberOfClusters) = 0 THEN EXIT FUNCTION
   FUNCTION = dwBytesPerSector * dwSectorsPerCluster
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the number of sectors per cluster.
' ========================================================================================
FUNCTION AfxGetDiskSectorsPerCluster (BYVAL bstrRootFolder AS WSTRING) AS DWORD
   LOCAL dwSectorsPerCluster, dwBytesPerSector, dwNumberOfFreeClusters, dwTotalNumberOfClusters AS DWORD
   IF bstrRootFolder = "" THEN bstrRootFolder = CURDIR$
   IF LEFT$(bstrRootFolder, 2) <> "\\" THEN
      bstrRootFolder = UCASE$(LEFT$(bstrRootFolder, 1))
      IF INSTR(bstrRootFolder, ANY "ABCDEFGHIJKLMNOPQRSTUVWXYZ") = 0 THEN EXIT FUNCTION
      bstrRootFolder += ":\"
   END IF
   IF GetDiskFreeSpaceW(BYCOPY bstrRootFolder, dwSectorsPerCluster, dwBytesPerSector, _
      dwNumberOfFreeClusters, dwTotalNumberOfClusters) = 0 THEN EXIT FUNCTION
   FUNCTION = dwSectorsPerCluster
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the number of bytes per sector.
' ========================================================================================
FUNCTION AfxGetDiskBytesPerSector (BYVAL bstrRootFolder AS WSTRING) AS DWORD
   LOCAL dwSectorsPerCluster, dwBytesPerSector, dwNumberOfFreeClusters, dwTotalNumberOfClusters AS DWORD
   IF bstrRootFolder = "" THEN bstrRootFolder = CURDIR$
   IF LEFT$(bstrRootFolder, 2) <> "\\" THEN
      bstrRootFolder = UCASE$(LEFT$(bstrRootFolder, 1))
      IF INSTR(bstrRootFolder, ANY "ABCDEFGHIJKLMNOPQRSTUVWXYZ") = 0 THEN EXIT FUNCTION
      bstrRootFolder += ":\"
   END IF
   IF GetDiskFreeSpaceW(BYCOPY bstrRootFolder, dwSectorsPerCluster, dwBytesPerSector, _
      dwNumberOfFreeClusters, dwTotalNumberOfClusters) = 0 THEN EXIT FUNCTION
   FUNCTION = dwBytesPerSector
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the number of free clusters.
' ========================================================================================
FUNCTION AfxGetDiskFreeClusters (BYVAL bstrRootFolder AS WSTRING) AS DWORD
   LOCAL dwSectorsPerCluster, dwBytesPerSector, dwNumberOfFreeClusters, dwTotalNumberOfClusters AS DWORD
   IF bstrRootFolder = "" THEN bstrRootFolder = CURDIR$
   IF LEFT$(bstrRootFolder, 2) <> "\\" THEN
      bstrRootFolder = UCASE$(LEFT$(bstrRootFolder, 1))
      IF INSTR(bstrRootFolder, ANY "ABCDEFGHIJKLMNOPQRSTUVWXYZ") = 0 THEN EXIT FUNCTION
      bstrRootFolder += ":\"
   END IF
   IF GetDiskFreeSpaceW(BYCOPY bstrRootFolder, dwSectorsPerCluster, dwBytesPerSector, _
      dwNumberOfFreeClusters, dwTotalNumberOfClusters) = 0 THEN EXIT FUNCTION
   FUNCTION = dwNumberOfFreeClusters
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the total number of clusters.
' ========================================================================================
FUNCTION AfxGetDiskTotalNumberOfClusters (BYVAL bstrRootFolder AS WSTRING) AS DWORD
   LOCAL dwSectorsPerCluster, dwBytesPerSector, dwNumberOfFreeClusters, dwTotalNumberOfClusters AS DWORD
   IF bstrRootFolder = "" THEN bstrRootFolder = CURDIR$
   IF LEFT$(bstrRootFolder, 2) <> "\\" THEN
      bstrRootFolder = UCASE$(LEFT$(bstrRootFolder, 1))
      IF INSTR(bstrRootFolder, ANY "ABCDEFGHIJKLMNOPQRSTUVWXYZ") = 0 THEN EXIT FUNCTION
      bstrRootFolder += ":\"
   END IF
   IF GetDiskFreeSpaceW(BYCOPY bstrRootFolder, dwSectorsPerCluster, dwBytesPerSector, _
      dwNumberOfFreeClusters, dwTotalNumberOfClusters) = 0 THEN EXIT FUNCTION
   FUNCTION = dwTotalNumberOfClusters
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the actual disk space used by a file.
' ========================================================================================
FUNCTION AfxGetFileDiskUsage (BYVAL bstrFile AS WSTRING) AS QUAD

   LOCAL qSize AS QUAD
   LOCAL dwClusters AS DWORD
   LOCAL dwClusterSize AS DWORD

   qSize = AfxGetFileSize(bstrFile)
   IF qSize = 0 THEN EXIT FUNCTION

   IF AfxIsCompressedFile(bstrFile) THEN
      FUNCTION = AfxGetCompressedFileSize(bstrFile)
   ELSE
      dwClusterSize = AfxGetDiskClusterSize(bstrFile)
      IF dwClusterSize = 0 THEN EXIT FUNCTION
      dwClusters = (qSize + (dwClusterSize - 1)) \ dwClusterSize
      FUNCTION = dwClusters * dwClusterSize
   END IF

END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the number of files that meet the specified criteria.
' Parameters:
' - bstrPath = The path of the folder to search.
'   Can include a drive name and system wildcard characters (* and ?).
' - bstrExt = The file extension
' - nAttribute = Includes filenames with specific attributes in the search, in addition to normal files.
'   If the value is negative, only files with the specific attributes are serached.
' Usage example: nCount = AfxGetFileCount("C:\Tests\*.bas)
' ========================================================================================
FUNCTION AfxGetFileCount (BYVAL bstrPath AS WSTRING, OPTIONAL BYVAL bstrExt AS WSTRING, OPTIONAL BYVAL nAttribute AS LONG) AS LONG

   LOCAL nCount AS LONG
   LOCAL bOnly AS LONG
   LOCAL bstrFile AS WSTRING

   bstrPath = TRIM$(bstrPath)
   IF bstrExt = "" THEN bstrExt = "*.*"
   IF bstrPath = "" THEN EXIT FUNCTION
   IF RIGHT$(bstrPath, 1) <> "\" THEN bstrPath += "\"
   bstrExt = TRIM$(bstrExt)
   IF nAttribute < 0 THEN bOnly = 1
   nAttribute = ABS(nAttribute)
   IF bOnly = 0 THEN
      bstrFile = DIR$(bstrPath & bstrExt, nAttribute)
   ELSE
      bstrFile = DIR$(bstrPath & bstrExt, ONLY nAttribute)
   END IF
   WHILE LEN(bstrFile)
      INCR nCount
      bstrFile = DIR$ (NEXT)
   WEND

   FUNCTION = nCount

END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the total size of the files that meet the specified criteria.
' Parameters:
' - bstrPath = The path of the folder to search.
' - bstrExt = The file extension. Can include system wildcard characters (* and ?).
' - nAttribute = Includes filenames with specific attributes in the search, in addition to normal files.
'   If the value is negative, only files with the specific attributes are searched.
' Usage example: qSize = AfxGetFolderSize("C:\Tests\", "*.bas")
' ========================================================================================
FUNCTION AfxGetFolderSize (BYVAL bstrPath AS WSTRING, OPTIONAL BYVAL bstrExt AS WSTRING, OPTIONAL BYVAL nAttribute AS LONG) AS QUAD

   LOCAL qSize AS QUAD
   LOCAL bOnly AS LONG
   LOCAL bstrFile AS WSTRING
   LOCAL d AS DIRDATA

   bstrPath = TRIM$(bstrPath)
   IF bstrPath = "" THEN EXIT FUNCTION
   IF RIGHT$(bstrPath, 1) <> "\" THEN bstrPath += "\"
   bstrExt = TRIM$(bstrExt)
   IF nAttribute < 0 THEN bOnly = 1
   nAttribute = ABS(nAttribute)
   IF bOnly = 0 THEN
      bstrFile = DIR$(bstrPath & bstrExt, nAttribute TO d)
   ELSE
      bstrFile = DIR$(bstrPath & bstrExt, ONLY nAttribute TO d)
   END IF
   WHILE LEN(bstrFile)
      IF (d.FileAttributes AND %FILE_ATTRIBUTE_COMPRESSED) = %FILE_ATTRIBUTE_COMPRESSED THEN
         qSize += AfxGetCompressedFileSize(d.FileName)
      ELSE
         qSize += (d.FileSizeHigh * (&HFFFFFFFF??? + 1)) + d.FileSizeLow
      END IF
      bstrFile = DIR$ (NEXT TO d)
   WEND

   FUNCTION = qSize

END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the total disk size in bytes of the files that meet the specified criteria.
' Parameters:
' - bstrPath = The path of the folder to search.
' - bstrExt = The file extension. Can include system wildcard characters (* and ?).
' - nAttribute = Includes filenames with specific attributes in the search, in addition to normal files.
'   If the value is negative, only files with the specific attributes are searched.
' Usage example: qSize = AfxGetFolderDiskUsage("C:\Tests\", "*.bas")
' ========================================================================================
FUNCTION AfxGetFolderDiskUsage (BYVAL bstrPath AS WSTRING, OPTIONAL BYVAL bstrExt AS WSTRING, OPTIONAL BYVAL nAttribute AS LONG) AS QUAD

   LOCAL dwClusters AS DWORD
   LOCAL dwClusterSize AS DWORD
   LOCAL qSize AS QUAD
   LOCAL qFileSize AS QUAD
   LOCAL bOnly AS LONG
   LOCAL bstrFile AS WSTRING
   LOCAL d AS DIRDATA

   bstrPath = TRIM$(bstrPath)
   IF bstrPath = "" THEN EXIT FUNCTION
   IF RIGHT$(bstrPath, 1) <> "\" THEN bstrPath += "\"
   bstrExt = TRIM$(bstrExt)
   IF nAttribute < 0 THEN bOnly = 1
   nAttribute = ABS(nAttribute)
   IF bOnly = 0 THEN
      bstrFile = DIR$(bstrPath & bstrExt, nAttribute TO d)
   ELSE
      bstrFile = DIR$(bstrPath & bstrExt, ONLY nAttribute TO d)
   END IF

   dwClusterSize = AfxGetDiskClusterSize(bstrPath)
   IF dwClusterSize = 0 THEN EXIT FUNCTION

   WHILE LEN(bstrFile)
      IF (d.FileAttributes AND %FILE_ATTRIBUTE_COMPRESSED) = %FILE_ATTRIBUTE_COMPRESSED THEN
         qFileSize += AfxGetCompressedFileSize(d.FileName)
      ELSE
         qFileSize = (d.FileSizeHigh * (&HFFFFFFFF??? + 1)) + d.FileSizeLow
      END IF
      dwClusters = (qFileSize + (dwClusterSize - 1)) \ dwClusterSize
      qSize += (dwClusters * dwClusterSize)
      bstrFile = DIR$ (NEXT TO d)
   WEND

   FUNCTION = qSize

END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the number of files that meet the specified criteria in the specified folder and its subfolders.
' Parameters:
' - bstrPath = The path of the folder to search.
'   Can include a drive name and system wildcard characters (* and ?).
' - bstrExt = The file extension
' - nAttribute = Includes filenames with specific attributes in the search, in addition to normal files.
'   If the value is negative, only files with the specific attributes are serached.
' Usage example: nCount = AfxGetFolderTreeFileCount("C:\Tests\", "*.bas")
' ========================================================================================
FUNCTION AfxGetFolderTreeFileCount (BYVAL bstrPath AS WSTRING, OPTIONAL BYVAL bstrExt AS WSTRING, OPTIONAL BYVAL nAttribute AS LONG) AS LONG

   LOCAL  hFind AS DWORD
   LOCAL  fd AS WIN32_FIND_DATAW
   LOCAL  bstrFile AS WSTRING
   LOCAL  bstrRootPath AS WSTRING
   LOCAL  nRootPathCount AS LONG
   STATIC nCount AS LONG
   STATIC bRecursion AS LONG

   bstrPath = TRIM$(bstrPath)
   IF bstrExt = "" THEN bstrExt = "*.*"
   IF bstrPath = "" THEN EXIT FUNCTION
   IF RIGHT$(bstrPath, 1) <> "\" THEN bstrPath += "\"
   IF bRecursion = 0 THEN bstrRootPath = bstrPath

   ' // Flag to know if we are in recursive mode
   INCR bRecursion

   ' // Recursively search subfolders
   hFind = FindFirstFileW(bstrPath & "*.*", fd)
   IF BITSE(hFind, %INVALID_HANDLE_VALUE, 32) THEN EXIT FUNCTION
   DO
      IF (fd.dwFileAttributes AND %FILE_ATTRIBUTE_DIRECTORY) = %FILE_ATTRIBUTE_DIRECTORY THEN
         IF fd.cFileName <> "." AND fd.cFileName <> ".." THEN   ' // Skip "." and  ".."
            nCount += AfxGetFileCount(bstrPath & "\" & fd.cFileName & "\", bstrExt, nAttribute)
            AfxGetFolderTreeFileCount(bstrPath & fd.cFileName & "\", bstrExt, nAttribute)
         END IF
      END IF
   LOOP WHILE FindNextFileW(hFind, fd)
   FindClose hFind

   ' // Return the number of files found
   FUNCTION = nCount

   ' // If recursion has finished, retrieve the count of files of the root path
   ' // and return the total of files found.
   DECR bRecursion
   IF bRecursion = 0 THEN
      nRootPathCount = AfxGetFileCount(bstrRootPath, bstrExt, nAttribute)
      FUNCTION = nCount + nRootPathCount
      nCount = 0
   END IF

END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the size of the files that meet the specified criteria in the specified folder and its subfolders.
' Parameters:
' - bstrPath = The path of the folder to search.
'   Can include a drive name and system wildcard characters (* and ?).
' - bstrExt = The file extension
' - nAttribute = Includes filenames with specific attributes in the search, in addition to normal files.
'   If the value is negative, only files with the specific attributes are serached.
' Usage example: nCount = AfxGetFolderTreeSize("C:\Tests\", "*.bas")
' ========================================================================================
FUNCTION AfxGetFolderTreeSize (BYVAL bstrPath AS WSTRING, OPTIONAL BYVAL bstrExt AS WSTRING, OPTIONAL BYVAL nAttribute AS LONG) AS QUAD

   LOCAL  hFind AS DWORD
   LOCAL  fd AS WIN32_FIND_DATAW
   LOCAL  bstrFile AS WSTRING
   LOCAL  bstrRootPath AS WSTRING
   LOCAL  qRootPathSize AS QUAD
   STATIC qSize AS QUAD
   STATIC bRecursion AS LONG

   bstrPath = TRIM$(bstrPath)
   IF bstrExt = "" THEN bstrExt = "*.*"
   IF bstrPath = "" THEN EXIT FUNCTION
   IF RIGHT$(bstrPath, 1) <> "\" THEN bstrPath += "\"
   IF bRecursion = 0 THEN bstrRootPath = bstrPath

   ' // Flag to know if we are in recursive mode
   INCR bRecursion

   ' // Recursively search subfolders
   hFind = FindFirstFileW(bstrPath & "*.*", fd)
   IF BITSE(hFind, %INVALID_HANDLE_VALUE, 32) THEN EXIT FUNCTION
   DO
      IF (fd.dwFileAttributes AND %FILE_ATTRIBUTE_DIRECTORY) = %FILE_ATTRIBUTE_DIRECTORY THEN
         IF fd.cFileName <> "." AND fd.cFileName <> ".." THEN   ' // Skip "." and  ".."
            qSize += AfxGetFolderSize(bstrPath & "\" & fd.cFileName & "\", bstrExt, nAttribute)
            AfxGetFolderTreeSize(bstrPath & fd.cFileName & "\", bstrExt, nAttribute)
         END IF
      END IF
   LOOP WHILE FindNextFileW(hFind, fd)
   FindClose hFind

   ' // Return the number of files found
   FUNCTION = qSize

   ' // If recursion has finished, retrieve the count of files of the root path
   ' // and return the total of files found.
   DECR bRecursion
   IF bRecursion = 0 THEN
      qRootPathSize = AfxGetFolderSize(bstrRootPath, bstrExt, nAttribute)
      FUNCTION = qSize + qRootPathSize
      qSize = 0
   END IF

END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the disk space used by the files that meet the specified criteria in the specified folder and its subfolders.
' Parameters:
' - bstrPath = The path of the folder to search.
'   Can include a drive name and system wildcard characters (* and ?).
' - bstrExt = The file extension
' - nAttribute = Includes filenames with specific attributes in the search, in addition to normal files.
'   If the value is negative, only files with the specific attributes are serached.
' Usage example: nCount = AfxGetFolderTreeDiskUsage("C:\Tests\", "*.bas")
' ========================================================================================
FUNCTION AfxGetFolderTreeDiskUsage (BYVAL bstrPath AS WSTRING, OPTIONAL BYVAL bstrExt AS WSTRING, OPTIONAL BYVAL nAttribute AS LONG) AS QUAD

   LOCAL  hFind AS DWORD
   LOCAL  fd AS WIN32_FIND_DATAW
   LOCAL  bstrFile AS WSTRING
   LOCAL  bstrRootPath AS WSTRING
   LOCAL  qRootPathSize AS QUAD
   STATIC qSize AS QUAD
   STATIC bRecursion AS LONG

   bstrPath = TRIM$(bstrPath)
   IF bstrExt = "" THEN bstrExt = "*.*"
   IF bstrPath = "" THEN EXIT FUNCTION
   IF RIGHT$(bstrPath, 1) <> "\" THEN bstrPath += "\"
   IF bRecursion = 0 THEN bstrRootPath = bstrPath

   ' // Flag to know if we are in recursive mode
   INCR bRecursion

   ' // Recursively search subfolders
   hFind = FindFirstFileW(bstrPath & "*.*", fd)
   IF BITSE(hFind, %INVALID_HANDLE_VALUE, 32) THEN EXIT FUNCTION
   DO
      IF (fd.dwFileAttributes AND %FILE_ATTRIBUTE_DIRECTORY) = %FILE_ATTRIBUTE_DIRECTORY THEN
         IF fd.cFileName <> "." AND fd.cFileName <> ".." THEN   ' // Skip "." and  ".."
            qSize += AfxGetFolderDiskUsage(bstrPath & "\" & fd.cFileName & "\", bstrExt, nAttribute)
            AfxGetFolderTreeDiskUsage(bstrPath & fd.cFileName & "\", bstrExt, nAttribute)
         END IF
      END IF
   LOOP WHILE FindNextFileW(hFind, fd)
   FindClose hFind

   ' // Return the number of files found
   FUNCTION = qSize

   ' // If recursion has finished, retrieve the count of files of the root path
   ' // and return the total of files found.
   DECR bRecursion
   IF bRecursion = 0 THEN
      qRootPathSize = AfxGetFolderDiskUsage(bstrRootPath, bstrExt, nAttribute)
      FUNCTION = qSize + qRootPathSize
      qSize = 0
   END IF

END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the number of subfolders of the specified folder and its subfolders.
' Parameters:
' - bstrPath = The path of the folder to search.
'   Can include a drive name and system wildcard characters (* and ?).
' Usage example: nCount = AfxGetFolderTreeSubfoldersCount("C:\Tests\")
' ========================================================================================
FUNCTION AfxGetFolderTreeSubfoldersCount (BYVAL bstrPath AS WSTRING) AS LONG

   LOCAL  hFind AS DWORD
   LOCAL  fd AS WIN32_FIND_DATAW
   LOCAL  bstrFile AS WSTRING
   STATIC nCount AS LONG
   STATIC bRecursion AS LONG

   bstrPath = TRIM$(bstrPath)
   IF bstrPath = "" THEN EXIT FUNCTION
   IF RIGHT$(bstrPath, 1) <> "\" THEN bstrPath += "\"

   ' // Flag to know if we are in recursive mode
   INCR bRecursion

   ' // Recursively search subfolders
   hFind = FindFirstFileW(bstrPath & "*.*", fd)
   IF BITSE(hFind, %INVALID_HANDLE_VALUE, 32) THEN EXIT FUNCTION
   DO
      IF (fd.dwFileAttributes AND %FILE_ATTRIBUTE_DIRECTORY) = %FILE_ATTRIBUTE_DIRECTORY THEN
         IF fd.cFileName <> "." AND fd.cFileName <> ".." THEN   ' // Skip "." and  ".."
            nCount += 1
            AfxGetFolderTreeSubfoldersCount(bstrPath & fd.cFileName & "\")
         END IF
      END IF
   LOOP WHILE FindNextFileW(hFind, fd)
   FindClose hFind

   ' // Return the number of files found
   FUNCTION = nCount

   ' // If recursion has finished, retrieve the count of files of the root path
   ' // and return the total of files found.
   DECR bRecursion
   IF bRecursion = 0 THEN nCount = 0

END FUNCTION
' ========================================================================================

' ========================================================================================
' Obtains a file name from a file handle using a file mapping object.
' Parameters:
' - hFile : File handle
' - strFileName : Pointer to an string variable that receives the retrieved file name.
' Return code:
' - S_OK on success, or an error code otherwise.
' Note  If the function fails, strFileName will return an empty string.
' ========================================================================================
FUNCTION AfxGetFileNameFromHandleA (BYVAL hFile AS DWORD, BYREF strFileName AS STRING) AS LONG

   LOCAL hFileMap AS DWORD
   LOCAL pMem AS DWORD
   LOCAL pszFilename AS ASCIIZ * %MAX_PATH + 1

   IF hFile = %NULL THEN
      FUNCTION = %ERROR_INVALID_HANDLE
      EXIT FUNCTION
   END IF

   IF VARPTR(strFileName) = %NULL THEN
      FUNCTION = %E_INVALIDARG
      EXIT FUNCTION
   END IF

   ' // Clear strFileName
   strFileName = ""

   ' // Get the file size.
   LOCAL dwFileSizeHi AS DWORD
   LOCAL dwFileSizeLo AS DWORD

   dwFileSizeLo = GetFileSize(hFile, dwFileSizeHi)
   ' // Cannot map a file with a length of zero.
   IF dwFileSizeLo = 0 AND dwFileSizeHi = 0 THEN
      FUNCTION = %ERROR_FILE_INVALID
      EXIT FUNCTION
   END IF

   ' // Create a file mapping object.
   hFileMap = CreateFileMappingA (hFile, BYVAL %NULL, %PAGE_READONLY, 0, 0, BYVAL %NULL)
   IF hFileMap = %NULL THEN
      FUNCTION = GetLastError
      EXIT FUNCTION
   END IF

   IF hFileMap THEN
      ' // Create a file mapping to get the file name.
      pMem = MapViewOfFile(hFileMap, %FILE_MAP_READ, 0, 0, 1)
      IF pMem THEN
         IF GetMappedFileNameA(GetCurrentProcess, pMem, pszFileName, %MAX_PATH) THEN
            ' // Translate path with device name to drive letters.
            LOCAL szDrive AS ASCIIZ * 3
            LOCAL szName AS ASCIIZ * %MAX_PATH
            LOCAL strTemp AS STRING
            LOCAL strBuffer AS STRING
            LOCAL nDriveCount AS LONG
            LOCAL i AS LONG
            ' // Prepare a long enough buffer
            strBuffer = STRING$(512, $NUL)
            ' // Get drives in strBuffer
            IF GetLogicalDriveStringsA(512, BYVAL STRPTR(strBuffer)) THEN
               ' // Remove the two trailing nuls
               strBuffer = RTRIM$(strBuffer, $NUL)
               ' // Number of drives
               nDriveCount = PARSECOUNT(strBuffer, $NUL)
               FOR i = 1 TO nDriveCount
                  ' // Retrieve the file name without trailing backslash
                  szDrive = PARSE$(strBuffer, $NUL, i)
                  ' // Obtain information about the MS-DOS device name
                  IF QueryDosDeviceA(szDrive, szName, %MAX_PATH) THEN
                     IF INSTR(pszFileName, szName) THEN
                        strTemp = REMOVE$(pszFileName, szName)
                        strFileName = szDrive & strTemp
                        EXIT FOR
                     END IF
                  END IF
               NEXT
            END IF
         END IF
         UnmapViewOfFile(pMem)
      END IF
      CloseHandle(hFileMap)
   END IF

   IF LEN(strFileName) = 0 THEN strFileName = pszFileName

END FUNCTION
' ========================================================================================
' ========================================================================================
FUNCTION AfxGetFileNameFromHandleW (BYVAL hFile AS DWORD, BYREF bstrFileName AS WSTRING) AS LONG

   LOCAL hFileMap AS DWORD
   LOCAL pMem AS DWORD
   LOCAL pwszFilename AS WSTRINGZ * %MAX_PATH + 1

   IF hFile = %NULL THEN
      FUNCTION = %ERROR_INVALID_HANDLE
      EXIT FUNCTION
   END IF

   IF VARPTR(bstrFileName) = %NULL THEN
      FUNCTION = %E_INVALIDARG
      EXIT FUNCTION
   END IF

   ' // Clear bstrFileName
   bstrFileName = ""

   ' // Get the file size.
   LOCAL dwFileSizeHi AS DWORD
   LOCAL dwFileSizeLo AS DWORD

   dwFileSizeLo = GetFileSize(hFile, dwFileSizeHi)
   ' // Cannot map a file with a length of zero.
   IF dwFileSizeLo = 0 AND dwFileSizeHi = 0 THEN
      FUNCTION = %ERROR_FILE_INVALID
      EXIT FUNCTION
   END IF

   ' // Create a file mapping object.
   hFileMap = CreateFileMappingW (hFile, BYVAL %NULL, %PAGE_READONLY, 0, 0, BYVAL %NULL)
   IF hFileMap = %NULL THEN
      FUNCTION = GetLastError
      EXIT FUNCTION
   END IF

   IF hFileMap THEN
      ' // Create a file mapping to get the file name.
      pMem = MapViewOfFile(hFileMap, %FILE_MAP_READ, 0, 0, 1)
      IF pMem THEN
         IF GetMappedFileNameW(GetCurrentProcess, pMem, pwszFileName, %MAX_PATH) THEN
            ' // Translate path with device name to drive letters.
            LOCAL wszDrive AS WSTRINGZ * 3
            LOCAL wszName AS WSTRINGZ * %MAX_PATH
            LOCAL bstrTemp AS WSTRING
            LOCAL bstrBuffer AS WSTRING
            LOCAL nDriveCount AS LONG
            LOCAL i AS LONG
            ' // Prepare a long enough buffer
            bstrBuffer = STRING$$(512, $NUL)
            ' // Get drives in strBuffer
            IF GetLogicalDriveStringsW(512, BYVAL STRPTR(bstrBuffer)) THEN
               ' // Remove the two trailing nuls
               bstrBuffer = RTRIM$(bstrBuffer, $NUL)
               ' // Number of drives
               nDriveCount = PARSECOUNT(bstrBuffer, $NUL & $NUL)
               FOR i = 1 TO nDriveCount
                  ' // Retrieve the file name without trailing backslash
                  wszDrive = PARSE$(bstrBuffer, $NUL & $NUL, i)
                  ' // Obtain information about the MS-DOS device name
                  IF QueryDosDeviceW(wszDrive, wszName, %MAX_PATH) THEN
                     IF INSTR(pwszFileName, wszName) THEN
                        bstrTemp = REMOVE$(pwszFileName, wszName)
                        bstrFileName = wszDrive & bstrTemp
                        EXIT FOR
                     END IF
                  END IF
               NEXT
            END IF
         END IF
         UnmapViewOfFile(pMem)
      END IF
      CloseHandle(hFileMap)
   END IF

   IF LEN(bstrFileName) = 0 THEN bstrFileName = pwszFileName

END FUNCTION
' ========================================================================================

#IF %DEF(%UNICODE)
   MACRO AfxGetFileNameFromHandle = AfxGetFileNameFromHandleW
#ELSE
   MACRO AfxGetFileNameFromHandle = AfxGetFileNameFromHandleA
#ENDIF

' ========================================================================================
' Loads a file and returns its content as a string.
' Parameter:
' - bstrFileSpec = Path of the file to be loaded. By default, the name is limited to MAX_PATH
'   characters. To extend this limit to 32,767 wide characters, prepend "\\?\" to the path.
' Return value: A string with the contents of the file.
' ========================================================================================
FUNCTION AfxLoadFileToString (BYVAL bstrFileSpec AS WSTRING) AS STRING

   LOCAL hFile AS DWORD
   LOCAL dwFileSize AS DWORD
   LOCAL dwHighSize AS DWORD
   LOCAL bSuccess AS LONG
   LOCAL buffer AS STRING
   LOCAL dwBytesRead AS DWORD

   hFile = CreateFileW(BYCOPY bstrFileSpec, %GENERIC_READ, %FILE_SHARE_READ, _
           BYVAL %NULL, %OPEN_EXISTING, %FILE_FLAG_SEQUENTIAL_SCAN, %NULL)
   IF BITSE(hFile, %INVALID_HANDLE_VALUE, 32) THEN EXIT FUNCTION

   dwFileSize = GetFileSize(hFile, dwHighSize)
   IF dwHighSize THEN
      CloseHandle hFile
      EXIT FUNCTION
   END IF

   buffer = SPACE$(dwFileSize)
   bSuccess = ReadFile(hFile, BYVAL STRPTR(buffer), dwFileSize, dwBytesRead, BYVAL %NULL)
   IF dwBytesRead < dwFileSize THEN buffer = LEFT$(buffer, dwBytesRead)
   CloseHandle hFile
   FUNCTION = buffer

END FUNCTION
' ========================================================================================

' ========================================================================================
' Get file content type from file extension looking at the registry.
' ========================================================================================
FUNCTION AfxGetContentTypeFromFileExt (BYVAL bstrExt AS WSTRING) AS WSTRING

   LOCAL hr       AS LONG
   LOCAL hKey     AS DWORD
   LOCAL wszBuff  AS WSTRINGZ * 1024

   IF LEFT$(bstrExt, 1) <> "." THEN bstrExt += "."
   IF RegOpenKeyExW(%HKEY_CLASSES_ROOT, BYCOPY bstrExt, 0, %KEY_QUERY_VALUE, hKey) = %ERROR_SUCCESS THEN
      IF hKey THEN
         ' // First look at the content type
         hr = RegQueryValueExW(hKey, "Content Type", 0, 0, wszBuff, SIZEOF(wszBuff))
         ' // If it fails, look at the default value
         IF hr <> %ERROR_SUCCESS THEN RegQueryValueExW(hKey, "", 0, 0, wszBuff, SIZEOF(wszBuff))
         RegCloseKey hKey
         wszBuff = EXTRACT$(wszBuff, CHR$(0))
      END IF
   END IF

   IF LEN(wszBuff) = 0 THEN wszBuff = "Unknown"
   FUNCTION = wszBuff

END FUNCTION
' ========================================================================================
