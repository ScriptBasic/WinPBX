# CFileSys Class

The **CFileSys** class wraps the Microsoft File System Object and provides methods to work with files and folders, giving your application the ability to create, copy, alter, move, and delete files and folders, or to determine if and where particular files or folders exist. It also enables you to get information about files and folders, such as their names and the date they were created or last modified.

### Methods

| Name       | Description |
| ---------- | ----------- |
| BuildPath | Appends a name to an existing path. |
| CopyFile | Copies one or more files from one location to another. |
| CopyFolder | Recursively copies a folder from one location to another. |
| CreateFolder | Creates a folder. |
| DeleteFile | Deletes a specified file. |
| DeleteFolder | Deletes a specified folder and its contents. |
| DriveExists | Checks if the specified drive exists. |
| DriveLetters | Returns a semicolon separated list with the driver letters. |
| FileExists | Checks for the existence of the specified file. |
| FolderExists | Checks for the existence of the specified folder. |
| GetAbsolutePathName | Returns complete and unambiguous path from a provided path specification. |
| GetBaseName | Returns a string containing the base name of the last component, less any file extension, in a path. |
| GetDriveAvailableSpace | Returns the amount of space available to a user on the specified drive or network share. |
| GetDriveFileSystem | Returns the type of file system in use for the specified drive or network share. |
| GetDriveFreeSpace | Returns the amount of free space available to a user on the specified drive or network share. |
| GetDriveName | Returns a string containing the name of the drive for a specified path. |
| GetDriveShareName | Returns the network share name for a specified drive. |
| GetDriveTotalSize | Returns the total space, in bytes, of a drive or network share. |
| GetDriveType | Returns a value indicating the type of a specified drive. |
| GetExtesionName | Returns a string containing the extension name of the file for a specified path. |
| GetFileAttributes | Returns the attributes of files. Read/write or read-only, depending on the attribute. |
| GetFileDateCreated | Returns the date and time that the specified file was created. |
| GetFileDateLastAccessed | Returns the date and time that the specified file was accessed. |
| GetFileDateLastModified | Returns the date and time that the specified file was modified. |
| GetFileName | Returns a string containing the name of the file for a specified path. |
| GetFileShortName | Returns the short name used by programs that require the earlier 8.3 file naming convention. |
| GetFileShortPath | Returns the short path used by programs that require the earlier 8.3 file naming convention. |
| GetFileSize | Returns the size, in bytes, of the specified file. |
| GetFileType | Returns information about the type of a file. |
| GetFileVersion | Returns the version number of a specified file. |
| GetFolderAttributes | Returns the attributes of folders. |
| GetFolderDateCreated | Returns the date and time that the specified folder was created. |
| GetFolderDateLastAccessed | Returns the date and time that the specified folder was last accessed. |
| GetFolderDateLastModified | Returns the date and time that the specified folder was last modified. |
| GetFolderDriveLetter | Returns a string containing the drive letter for a specified folder. |
| GetFolderName | Returns a string containing the name of the folder for a specified path, i.e. the path minus the file name. |
| GetFolderShortName | Returns the short name used by programs that require the earlier 8.3 file naming convention. |
| GetFolderShortPath | Returns the short path used by programs that require the earlier 8.3 file naming convention. |
| GetFolderSize | Returns the size, in bytes, of all files and subfolders contained in the folder. |
| GetFolderType | Returns information about the type of a folder. |
| GetLastResult | Returns the last result code. |
| GetNumDrives | Returns the number of drives. |
| GetNumFiles | Returns the number of files contained in a specified folder, including those with hidden and system file attributes set. |
| GetNumSubFolders | Returns the number of folders contained in a specified folder, including those with hidden and system file attributes set. |
| GetParentFolderName | Returns the folder name for the parent of the specified folder. |
| GetSerialNumber | Returns the decimal serial number used to uniquely identify a disk volume. |
| GetStandardStream | Returns a TextStream object corresponding to the standard input, output, or error stream. |
| GetTempName | Returns a randomly generated temporary file or folder name that is useful for performing operations that require a temporary file or folder. |
| GetVolumeName | Returns the volume name of the specified drive. |
| IsDriveReady | Returns True if the specified drive is ready; False if it is not. |
| IsRootFolder | Returns True(-1) if the specified folder is the root folder; False(0) if it is not. |
| MoveFile | Moves one or more files from one location to another. |
| MoveFolder | Moves one or more folders from one location to another. |
| SetFileAttributes | Sets the attributes of files. |
| SetFileName | Sets the name of a specified file. |
| SetFolderAttributes | Sets the attributes of folders. |
| SetFolderName | Sets the name of a specified folder. |
| SetVolumeName | Sets the volume name of the specified drive. |

#### Include File:

CFileSys.inc
