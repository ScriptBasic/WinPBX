# CFindFile Class

#### Methods

| Name       | Description |
| ---------- | ----------- |
| [Close](#Close) | Ends the search, resets the context and releases all resources. |
| [CreationTime](#CreationTime) | Returns the time, in local time format, the file was created. |
| [FileAttributes](#FileAttributes) | Returns the attributes of the last found file. |
| FileExt | Returns the extesion of the found file. |
| FileName | Returns the name of the found file. |
| FileNameX | Returns the name and extension of the found file. |
| FilePath | Returns the full path of the found file. |
| FileSize | Returns the size of the found file, in bytes. |
| FileURL | Returns the file URL. |
| FindFile | Opens a file search. |
| FindNext | Searches the next file. |
| IsCompressedFile | Checks if the found file is a compressed file. |
| IsDots | Call this method to test for the current directory and parent directory markers while iterating through files. |
| IsEncryptedFile | Checks if the found file is an encrypted file. |
| IsFile | Checks if the found file is a file and not a folder. |
| IsFolder | Checks if the found file is a folder. |
| IsHiddenFile | Checks if the found file is a hidden file. |
| IsNormalFile | Checks if the found file is a normal file. |
| IsNotContentIndexedFile | Checks if the found file is not to be indexed by the content indexing service.. |
| IsOffLineFile | Checks if the found file is not available immediately. |
| IsReadOnlyFile | Checks if the found file is a read only file. |
| IsReparsePointFile | Checks if the found file is is file or directory that has an associated reparse point, or a file that is a symbolic link. |
| IsSparseFile | Checks if the found file is a sparse file. |
| IsSystemFile | Checks if the found file is a system file. |
| IsTemporaryFile | Checks if the found file is a temporary file. |
| LastAccessTime | Returns the time the file was last accessed, in local time format. |
| LastWriteTime | Returns the time the file was written to, truncated, or overwritten, in local time format. |
| MatchesMask | Tests the file attributes on the found file. |
| Root | Returns the root of the found file. |
| ShortFileName | Returns an alternative name for the file. This name is in the classic 8.3 file name format. |

#### Include file

CFindFile.inc

# <a name="Close"></a>Close

Call this method to end the search, reset the context, and release all resources. After calling **Close**, you do not have to create a new **CFindFile** instance before calling FindFile to begin a new search.

```
SUB Close
```

# <a name="CreationTime"></a>CreationTime

Call this method to get the time, in local time format, the file was created.

```
FUNCTION CreationTime () AS FILETIME
```

# <a name="FileAttributes"></a>FileAttributes

Call this method to get the time, in local time format, the file was created.

```
FUNCTION FileAttributes () AS DWORD
```

#### File Attribute Constants

File attributes are metadata values stored by the file system on disk and are used by the system and are available to developers via various file I/O APIs. For a list of related APIs and topics, see the See Also section.

| Attribute  | Description |
| ---------- | ----------- |
| FILE_ATTRIBUTE_ARCHIVE | A file or directory that is an archive file or directory. Applications typically use this attribute to mark files for backup or removal. |
| FILE_ATTRIBUTE_DEVICE | This value is reserved for system use. |
| FILE_ATTRIBUTE_DIRECTORY | The handle that identifies a directory. |
| FILE_ATTRIBUTE_ENCRYPTED | A file or directory that is encrypted. For a file, all data streams in the file are encrypted. For a directory, encryption is the default for newly created files and subdirectories. |
| FILE_ATTRIBUTE_HIDDEN | The file or directory is hidden. It is not included in an ordinary directory listing. |
| FILE_ATTRIBUTE_INTEGRITY_STREAM | The directory or user data stream is configured with integrity (only supported on ReFS volumes). It is not included in an ordinary directory listing. The integrity setting persists with the file if it's renamed. If a file is copied the destination file will have integrity set if either the source file or destination directory have integrity set. Windows Server 2008 R2, Windows 7, Windows Server 2008, Windows Vista, Windows Server 2003, and Windows XP: This flag is not supported until Windows Server 2012. |
| FILE_ATTRIBUTE_NORMAL | A file that does not have other attributes set. This attribute is valid only when used alone. |
| FILE_ATTRIBUTE_NOT_CONTENT_INDEXED | The file or directory is not to be indexed by the content indexing service. |
| FILE_ATTRIBUTE_NO_SCRUB_DATA | The user data stream not to be read by the background data integrity scanner (AKA scrubber). When set on a directory it only provides inheritance. This flag is only supported on Storage Spaces and ReFS volumes. It is not included in an ordinary directory listing. Windows Server 2008 R2, Windows 7, Windows Server 2008, Windows Vista, Windows Server 2003, and Windows XP: This flag is not supported until Windows 8 and Windows Server 2012. |
| FILE_ATTRIBUTE_OFFLINE | The data of a file is not available immediately. This attribute indicates that the file data is physically moved to offline storage. This attribute is used by Remote Storage, which is the hierarchical storage management software. Applications should not arbitrarily change this attribute. |
| FILE_ATTRIBUTE_READONLY | A file that is read-only. Applications can read the file, but cannot write to it or delete it. This attribute is not honored on directories. For more information, see You cannot view or change the Read-only or the System attributes of folders in Windows Server 2003, in Windows XP, in Windows Vista or in Windows 7. |
| FILE_ATTRIBUTE_REPARSE_POINT | A file or directory that has an associated reparse point, or a file that is a symbolic link. |
| FILE_ATTRIBUTE_SPARSE_FILE | A file that is a sparse file. |
| FILE_ATTRIBUTE_SYSTEM | A file or directory that the operating system uses a part of, or uses exclusively. |
| FILE_ATTRIBUTE_TEMPORARY | A file that is being used for temporary storage. File systems avoid writing data back to mass storage if sufficient cache memory is available, because typically, an application deletes a temporary file after the handle is closed. In that scenario, the system can entirely avoid writing the data. Otherwise, the data is written after the handle is closed. |
| FILE_ATTRIBUTE_VIRTUAL | This value is reserved for system use. |

#### Remarks

The FILE_ATTRIBUTE_SPARSE_FILE attribute on the file is set if any of the streams of the file have ever been sparse.
