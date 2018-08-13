#File Procedures

| Name       | Description |
| ---------- | ----------- |
| AfxDeleteFile | Deletes the specified file. |
| AfxFileExists | Searches a directory for a file or subdirectory with a name that matches a specific name (or partial name if wildcards are used). |
| AfxDeleteFile | Deletes the specified file. |
| AfxFileReadAllLines | Reads all the lines of the specified file into a safe array. |
| AfxFileScan | Scans a text file ans returns the number of occurrences of the specified delimiter. |
| AfxFolderExists | Searches a directory for a file or subdirectory with a name that matches a specific name (or partial name if wildcards are used). |
| AfxGetCurDir | Retrieves the current directory for the current process. |
| AfxGetExeFileExt | Parses a path/filename and returns the extension portion of the path/file name. That is the last period (.) in the string plus the text to the right of it. |
| AfxGetExeFileName | Returns the file name of the program which is currently executing. |
| AfxGetExeFileNameX | Returns the file name and extension of the program which is currently executing. |
| AfxGetExeFullPath | Returns the complete drive, path, file name, and extension of the program which is currently executing. |
| AfxGetExePath | Returns the path of the program which is currently executing. The path has not a trailing backslash except if it is a drive, e.g. C:\. |
| AfxGetExePathName | Returns the path of the program which is currently executing. The path has a trailing backslash. |
| AfxGetFileCreationTime | Returns the time the file was created, in FILETIME format. |
| AfxGetFileExt | Parses a path/filename and returns the extension portion of the path/file name. That is the last period (.) in the string plus the text to the right of it. |
| AfxGetFileLastAccessTime | Returns the time the file was last accessed, in FILETIME format. |
| AfxGetFileLastWriteTime | Returns the time the file was last written to, truncated, or overwritten, in FILETIME format. |
| AfxGetFileName | Parses a path/filename and returns the file name portion. That is the text to the right of the last backslash (\) or colon (:), ending just before the last period (.). |
| AfxGetFileNameX | Parses a path/filename and returns the file name and extension portion. That is the text to the right of the last backslash (\) or colon (:). |
| AfxGetFileSize | Returns the size in bytes of the specified file. |
| AfxGetFileVersion | Retrieves the version of the specified file multiplied by 100, e.g. 601 for version 6.01. |
| AfxGetFolderName | Returns a string containing the name of the folder for a specified path, i.e. the path minus the file name. |
| AfxGetKnowFolderPath | Retrieves the path of an special folder. Requires Windows Vista/Windows 7 or superior. |
| AfxGetLongPathName | Retrieves the short path form of the specified path. |
| AfxGetPathName | Parses a path/filename and returns the path portion. That is the text up to and including the last backslash (\) or colon (:). |
| AfxGetShortPathName | Retrieves the short path form of the specified path. |
| AfxGetSpecialFolderLocation | Retrieves the path of an special folder. |
| AfxGetSystemDllPath | Retrieves the fully qualified path for the file that contains the specified module. |
| AfxGetWinDir | Retrieves the path of the Windows directory. |
| AfxIsCompressedFile | Returns True if the specified file or directory is compressed; False if it is not. |
| AfxIsEncryptedFile | Returns True if the specified file or directory is encrypted; False if it is not. |
| AfxIsFolder | Returns True if the specified path is a folder; False if it is not. |
| AfxIsHiddenFile | Returns True if the specified path is a hidden file or directory; False if it is not. |
| AfxIsNormalFile | Returns True if the specified path is a normal file (a file that does not have other attributes set); False if it is not. |
| AfxIsNotContentIndexedFile | Returns TRUE if the specified file or directory is not to be indexed by the content indexing service; FALSE, otherwise. |
| AfxIsOfflineFile | Returns TRUE if the specified file file is not available immediately; FALSE, otherwise. |
| AfxIsReadOnlyFile | Returns True if the specified path is a read only file; False if it is not. |
| AfxIsReparsePointFile | Returns TRUE if the specified path is a file or directory that has an associated reparse point, or a file that is a symbolic link.; FALSE, otherwise. |
| AfxIsSparseFile | Returns TRUE if the specified path is a sparse file; FALSE, otherwise. |
| AfxIsSystemFile | Returns True if the specified path is a system file; False if it is not. |
| AfxIsSystemFile | Returns True if the specified path is a system file; False if it is not. |
| AfxIsTemporaryFile | Returns True if the specified path is a temporary file; False if it is not. |
| AfxOpenFileDialog | Creates an Open dialog box that lets the user specify the drive, directory, and the name of a file or set of files to be opened. The dialog box uses the Explorer-style user interface. |

## File Path Procedures

| Name       | Description |
| ---------- | ----------- |
| AfxPathAddBackSlash | Adds a backslash to the end of a string to create the correct syntax for a path. If the source path already has a trailing backslash, no backslash will be added. |
| AfxPathAddExtension | Adds a file name extension to a path string. |
| AfxPathAppend | Appends one path to the end of another. |
| AfxPathBuildRoot | Creates a root path from a given drive number. |
| AfxPathCanonicalize | Removes elements of a file path according to special strings inserted into that path. |
| AfxPathCombine | Concatenates two strings that represent properly formed paths into one path; also concatenates any relative path elements. |
| AfxPathCommonPrefix | Compares two paths to determine if they share a common prefix. A prefix is one of these types: "C:\", ".", "..", "..\". |
| AfxPathCompactPath | Truncates a file path to fit within a given pixel width by replacing path components with ellipses. |
| AfxPathCompactPathEx | Truncates a path to fit within a certain number of characters by replacing path components with ellipses. |
| AfxPathCreateFromUrl | Converts a file URL to a Microsoft MS-DOS path. |
| AfxPathFileExists | Determines whether a path to a file system object such as a file or directory is valid. |
| AfxPathFindExtension | Searches a path for an extension. |
| AfxPathFindFileName | Searches a path for a file name. |
| AfxPathFindFileName | Searches a path for a file name. |
| AfxPathFindNextComponent | Parses a path and returns the portion of that path that follows the first backslash. |
| AfxPathFindOnPath | Searches for a file. |
| AfxPathFindSuffixArray | Determines whether a given file name has one of a list of suffixes. |
| AfxPathGetArgs | Finds the command line arguments within a given path. |
| AfxPathGetCharType | Determines the type of character in relation to a path. |
| AfxPathGetDriveNumber | Searches a path for a drive letter within the range of 'A' to 'Z' and returns the corresponding drive number. | AfxPathIsContentType | Determines if a file's registered content type matches the specified content type. |
|
