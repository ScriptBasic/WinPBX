# CFileSys Class

The **CFileSys** class wraps the Microsoft File System Object and provides methods to work with files and folders, giving your application the ability to create, copy, alter, move, and delete files and folders, or to determine if and where particular files or folders exist. It also enables you to get information about files and folders, such as their names and the date they were created or last modified.

### Methods

| Name       | Description |
| ---------- | ----------- |
| [BuildPath](#BuildPath) | Appends a name to an existing path. |
| [CopyFile](#CopyFile) | Copies one or more files from one location to another. |
| [CopyFolder](#CopyFolder) | Recursively copies a folder from one location to another. |
| [CreateFolder](#CreateFolder) | Creates a folder. |
| [DeleteFile](#DeleteFile) | Deletes a specified file. |
| [DeleteFolder](#DeleteFolder) | Deletes a specified folder and its contents. |
| [DriveExists](#DriveExists) | Checks if the specified drive exists. |
| [DriveLetters](#DriveLetters) | Returns a semicolon separated list with the driver letters. |
| [FileExists](#FileExists) | Checks for the existence of the specified file. |
| [FolderExists](#FolderExists) | Checks for the existence of the specified folder. |
| [GetAbsolutePathName](#GetAbsolutePathName) | Returns complete and unambiguous path from a provided path specification. |
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

# <a name="BuildPath"></a>BuildPath

Appends a name to an existing path.

```
FUNCTION BuildPath (BYREF cbsPath AS CBSTR, BYREF cbsName AS CBSTR) AS CWSTR
```

| Name       | Description |
| ---------- | ----------- |
| *cbsPath* | CBSTR. Existing path to which name is appended. Path can be absolute or relative and need not specify an existing folder. |
| *cbsName* | CBSTR. Name being appended to the existing path. |

#### Return value

CBSTR. The new path.

#### Remarks

The **BuildPath** method inserts an additional path separator between the existing path and the name, only if necessary.

#### Usage example

```
#INCLUDE ONCE "Afx/CFileSys.inc"
DIM pFileSys AS CFileSys
DIM cbsNewPath AS CBSTR = pFileSys.BuildPath ("C:\MyFolder", "Text.txt")
```

# <a name="CopyFile"></a>CopyFile

Copies one or more files from one location to another.

```
FUNCTION CopyFile (BYREF cbsSource AS CBSTR, BYREF cbsDestination AS CBSTR, _
   BYVAL OverWriteFiles AS VARIANT_BOOL = -1) AS HRESULT
```

| Name       | Description |
| ---------- | ----------- |
| *cbsSource* | CBSTR. Character string file specification, which can include wildcard characters, for one or more files to be copied. |
| *cbsDestination* | CBSTR. Character string destination where the file or files from source are to be copied. Wildcard characters are not allowed. |
| *OverWriteFiles* | Boolean value that indicates if existing files are to be overwritten. If true, files are overwritten; if false, they are not. The default is true. Note that **CopyFile** will fail if destination has the read-only attribute set, regardless of the value of overwrite. |

#### Return value

HRESULT. S_OK (0) on success, or an error code on failure.

#### Remarks

Wildcard characters can only be used in the last path component of the *cbSource* argument.

#### Usage example

```
#INCLUDE ONCE "Afx/CFileSys.inc"
DIM pFileSys AS CFileSys
pFileSys.CopyFile("C:\MyFolder\MyFile.txt", "C:\MyOtherFolder\MyFile.txt")
```

# <a name="CopyFolder"></a>CopyFolder

Recursively copies a folder from one location to another.

```
FUNCTION CopyFolder (BYREF cbsSource AS CBSTR, BYREF cbsDestination AS CBSTR, _
   BYVAL OverWriteFiles AS VARIANT_BOOL = -1) AS HRESULT
```

| Name       | Description |
| ---------- | ----------- |
| *cbsSource* | CBSTR. Character string file specification, which can include wildcard characters, for one or more folders to be copied. |
| *cbsDestination* | CBSTR. Character string destination where the folder and subfolders from source are to be copied (must end with a "\"). Wildcard characters are not allowed.  |
| *OverWriteFiles* | Boolean value that indicates if existing folders are to be overwritten. If true, files are overwritten; if false, they are not. The default is true. |

#### Return value

HRESULT. S_OK (0) on success, or an error code on failure.

#### Remarks

Wildcard characters can only be used in the last path component of the *cbSource* argument.

#### Usage example

```
#INCLUDE ONCE "Afx/CFileSys.inc"
DIM pFileSys AS CFileSys
pFileSys.CopyFolder("C:\MyFolder", "C:\MyOtherFolder\")
```

# <a name="CreateFolder"></a>CreateFolder

Creates a folder.

```
FUNCTION CreateFolder (BYREF cbsFolderSpec AS CBSTR) AS Afx_IFolder PTR
```

| Name       | Description |
| ---------- | ----------- |
| *cbsFolderSpec* | CBSTR. String expression that identifies the folder to create. |

#### Return value

IDispatch. Reference to an **IFolder** object.

#### Remarks

An error occurs if the specified folder already exists.

#### Usage example

```
#INCLUDE ONCE "Afx/CFileSys.inc"
DIM pFileSys AS CFileSys
DIM pFolder AS Afx_Folder PTR
pFolder = pFileSys.CreateFolder("C:\MyNewFolder")
IF pFolder THEN
   ' ....
   pFolder.Release
END IF
```

# <a name="DeleteFile"></a>DeleteFile

Deletes a specified file.

```
FUNCTION DeleteFile (BYREF cbsFileSpec AS CBSTR, BYVAL bForce AS VARIANT_BOOL = FALSE) AS HRESULT
```

| Name       | Description |
| ---------- | ----------- |
| *cbsFileSpec* | CBSTR. The name of the file to delete. cbsFileSpec can contain wildcard characters in the last path component. |
| *bForce* | Boolean value that is true if files with the read-only attribute set are to be deleted; false (default) if they are not. |

#### Return value

HRESULT. S_OK (0) on success, or an error code on failure.

#### Remarks

An error occurs if no matching files are found. The **DeleteFile** method stops on the first error it encounters. No attempt is made to roll back or undo any changes that were made before an error occurred.

#### Usage example

```
#INCLUDE ONCE "Afx/CFileSys.inc"
DIM pFileSys AS CFileSys
pFileSys.DeleteFile("C:\MyFolder\MyFile.txt")
```

# <a name="DeleteFolder"></a>DeleteFolder

Deletes a specified folder and its contents.

```
FUNCTION DeleteFolder (BYREF cbsFolderSpec AS CBSTR, BYVAL bForce AS VARIANT_BOOL = FALSE) AS HRESULT
```

| Name       | Description |
| ---------- | ----------- |
| *cbsFolderSpec* | CBSTR. The name of the folder to delete. *cbsFolderSpec* can contain wildcard characters in the last path component. |
| *bForce* | Boolean value that is true if folders with the read-only attribute set are to be deleted; false (default) if they are not. |

#### Return value

HRESULT. S_OK (0) on success, or an error code on failure.

#### Remarks

The **DeleteFolder** method does not distinguish between folders that have contents and those that do not. The specified folder is deleted regardless of whether or not it has contents. 

An error occurs if no matching folders are found. The **DeleteFolder** method stops on the first error it encounters. No attempt is made to roll back or undo any changes that were made before an error occurred.

#### Usage example

```
#INCLUDE ONCE "Afx/CFileSys.inc"
DIM pFileSys AS CFileSys
pFileSys.DeleteFolder("C:\MyFolder")
```

# <a name="DriveExists"></a>DriveExists

Returns True if the specified drive exists; False if it does not.

```
FUNCTION DriveExists (BYREF cbsDriveSpec AS CBSTR) AS BOOLEAN
```

| Name       | Description |
| ---------- | ----------- |
| *cbsDriveSpec* | CBSTR. A drive letter or a complete path specification. |

#### Return value

BOOLEAN. True if the specified drive exists; False if it does not.

#### Remarks

For drives with removable media, the **DriveExists** method returns true even if there are no media present. Use the **IsDriveReady** method to determine if a drive is ready.

#### Usage example

```
#INCLUDE ONCE "Afx/CFileSys.inc"
DIM pFileSys AS CFileSys
DIM fExists AS BOOLEAN = pFileSys.DriveExists("C:")
```

# <a name="DriveLetters"></a>DriveLetters

Returns a semicolon separated list with the driver letters.

```
FUNCTION DriveLetters () AS CBSTR
```

#### Return value

CBSTR. A semicolon separated list with the driver letters.

#### Usage example

```
#INCLUDE ONCE "Afx/CFileSys.inc"
DIM pFileSys AS CFileSys
DIM cbsLetters AS CBSTR = pFileSys.DriveLetters
```

# <a name="FileExists"></a>FileExists

Returns True if the specified file exists; False if it does not.

```
FUNCTION FileExists (BYREF cbsFileSpec AS CBSTR) AS BOOLEAN
```

| Name       | Description |
| ---------- | ----------- |
| *cbsFileSpec* | CBSTR. The name of the file whose existence is to be determined. A complete path specification (either absolute or relative) must be provided if the file isn't expected to exist in the current folder. |

#### Return value

Boolean. True if the specified file exists; False if it does not.

#### Usage example

```
#INCLUDE ONCE "Afx/CFileSys.inc"
DIM pFileSys AS CFileSys
DIM fExists AS BOOLEAN = pFileSys.FileExists("C:\MyFolder\Test.txt")
```

# <a name="FolderExists"></a>FolderExists

Returns True if the specified folder exists; False if it does not.

```
FUNCTION FolderExists (BYREF cbsFolderSpec AS CBSTR) AS BOOLEAN
```

| Name       | Description |
| ---------- | ----------- |
| *cbsFolderSpec* | CBSTR. The name of the folder whose existence is to be determined. A complete path specification (either absolute or relative) must be provided if the folder isn't expected to exist in the current folder. |

#### Return value

Boolean. True if the specified folder exists; False if it does not.

#### Usage example

```
#INCLUDE ONCE "Afx/CFileSys.inc"
DIM pFileSys AS CFileSys
DIM fExists AS BOOLEAN = pFileSys.FolderExists("C:\MyFolder")
```

# <a name="GetAbsolutePathName"></a>GetAbsolutePathName

Returns complete and unambiguous path from a provided path specification.

```
FUNCTION GetAbsolutePathName (BYREF cbsPathSpec AS CBSTR) AS CBSTR
```

| Name       | Description |
| ---------- | ----------- |
| *cbsPathSpec* | CBSTR. Path specification to change to a complete and unambiguous path. |

#### Return value

Boolean. The path name.

#### Remarks

A path is complete and unambiguous if it provides a complete reference from the root of the specified drive. A complete path can only end with a path separator character (\) if it specifies the root folder of a mapped drive.

Assuming the current directory is c:\mydocuments\reports, the following table illustrates the behavior of the **GetAbsolutePathName** method.

| pathspec   | Returned path |
| ---------- | ------------- |
| "c:" | "c:\mydocuments\reports" |
| "c:.." | "c:\mydocuments" |
| "c:\" | "c:\" |
| "c:*.*\may97" | "c:\mydocuments\reports\\\*\.\*\may97" |
| "region1" | "c:\mydocuments\reports\region1" |
| "c:\..\..\mydocuments" | "c:\mydocuments" |

#### Usage example

```
#INCLUDE ONCE "Afx/CFileSys.inc"
DIM pFileSys AS CFileSys
DIM cbsName AS CBSTR = pFileSys.GetAbsolutePathName("C:\MyFolder\Test.txt")
```
