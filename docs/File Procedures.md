# Dialogs

| Name       | Description |
| ---------- | ----------- |
| [AfxBrowseForFolder](#AfxBrowseForFolder) | Displays a dialog box that enables the user to select a folder. |
| [AfxOpenFileDialog](#AfxOpenFileDialog) | Creates an Open dialog box that lets the user specify the drive, directory, and the name of a file or set of files to be opened. |
| [AfxSaveFileDialog](#AfxSaveFileDialog) | Creates a Save dialog box that lets the user specify the drive, directory, and name of a file to save. |

# File and Folder Procedures

| Name       | Description |
| ---------- | ----------- |
| [AfxChDir](#AfxChDir) | Changes the current directory for the current process. |
| [AfxCopyFile](#AfxCopyFile) | Copies an existing file to a new file. |
| [AfxCreateDirectory](#AfxMakeDir) | Creates a new directory. |
| [AfxCurDir](#AfxCurDir) | Retrieves the current directory for the current process. |
| [AfxDeleteFile](#AfxDeleteFile) | Deletes the specified file. |
| [AfxFileCopy](#AfxCopyFile) | Copies an existing file to a new file. |
| [AfxFileDateTime](#AfxFileDateTime) | Returns the file's last modified date and time as Date Serial. |
| AfxFileExists | Searches a directory for a file or subdirectory with a name that matches a specific name (or partial name if wildcards are used). |
| AfxGetFileLen | Returns the size in bytes of the specified file. |
| AfxFileReadAllLines | Reads all the lines of the specified file into a safe array. |
| AfxFileScan | Scans a text file ans returns the number of occurrences of the specified delimiter. |
| AfxFolderExists | Searches a directory for a file or subdirectory with a name that matches a specific name (or partial name if wildcards are used). |
| [AfxGetCurDir](#AfxCurDir) | Retrieves the current directory for the current process. |
| [AfxGetCurrentDirectory](#AfxCurDir) | Retrieves the current directory for the current process. |
| AfxGetDriveType | Determines whether a disk drive is a removable, fixed, CD-ROM, RAM disk, or network drive. |
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
| [AfxKill](#AfxDeleteFile) | Deletes the specified file. |
| [AfxMakeDir](#AfxMakeDir) | Creates a new directory. |
| [AfxMkDir](#AfxMakeDir) | Creates a new directory. |
| [AfxMoveFile](#AfxMoveFile) | Moves an existing file or a directory, including its children. |
| [AfxName](#AfxMoveFile) | Moves an existing file or a directory, including its children. |
| AfxRemoveDirectory | Deletes an existing empty directory. |
| AfxRemoveDir | Deletes an existing empty directory. |
| [AfxRenameFile](#AfxMoveFile) | Moves an existing file or a directory, including its children. |
| AfxRmDir | Deletes an existing empty directory. |
| AfxSaveTempFile | Saves the contents of a string buffer in a temporary file. |
| [AfxSetCurDir](#AfxChDir) | Changes the current directory for the current process. |
| [AfxSetCurrentDirectory](#AfxChDir) | Changes the current directory for the current process. |

## Path and Url Procedures

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
| AfxPathGetDriveNumber | Searches a path for a drive letter within the range of 'A' to 'Z' and returns the corresponding drive number. |
| AfxPathIsContentType | Determines if a file's registered content type matches the specified content type. |
| AfxPathIsDirectory | Verifies that a path is a valid directory. |
| AfxPathIsDirectoryEmpty | Determines whether a specified path is an empty directory. |
| AfxPathIsFileSpec | Searches a path for any path-delimiting characters (for example, ':' or '\' ). If there are no path-delimiting characters present, the path is considered to be a File Spec path. |
| AfxPathIsHTMLFile | Determines if a file is an HTML file. The determination is made based on the content type that is registered for the file's extension. |
| AfxPathIsLFNFileSpec | Determines whether a file name is in long format. |
| AfxPathIsNetworkPath | Determines whether a path string represents a network resource. |
| AfxPathIsPrefix | Searches a path to determine if it contains a valid prefix of the type passed by wszPrefix. A prefix is one of these types: "C:\", ".", "..", "..\". |
| AfxPathIsRelative | Searches a path and determines if it is relative. |
| AfxPathIsRoot | Parses a path to determine if it is a directory root. |
| AfxPathIsSameRoot | Compares two paths to determine if they have a common root component. |
| AfxPathIsSystemFolder | Determines if an existing folder contains the attributes that make it a system folder. Alternately, this function indicates if certain attributes qualify a folder to be a system folder. |
| AfxPathIsUNC | Determines if the string is a valid Universal Naming Convention (UNC) for a server and share path. |
| AfxPathIsUNCServer | Determines if a string is a valid Universal Naming Convention (UNC) for a server path only. |
| AfxPathIsUNCServerShare | Determines if a string is a valid Universal Naming Convention (UNC) share path, \\*server*\*share*. |
| AfxPathIsURL | Tests a given string to determine if it conforms to a valid URL format. |
| AfxPathMakePretty | Converts a path to all lowercase characters to give the path a consistent appearance. |
| AfxPathMakeSystemFolder | Gives an existing folder the proper attributes to become a system folder. |
| AfxPathMatchSpec | Searches a string using a Microsoft MS-DOS wild card match type. |
| AfxPathMatchSpecEx | Searches a path to determine whether it contains a file of a specified file type extension. |
| AfxPathParseIconLocation | Parses a file location string that contains a file location and icon index, and returns separate values. |
| AfxPathQuoteSpaces | Searches a path for spaces. If spaces are found, the entire path is enclosed in quotation marks. |
| AfxPathRelativePathTo | Creates a relative path from one file or folder to another. |
| AfxPathRemoveArgs | Removes any arguments from a given path. |
| AfxPathRemoveBackslash | Removes the trailing backslash from a given path. |
| AfxPathRemoveBlanks | Removes all leading and trailing spaces from a string. |
| AfxPathRemoveExtension | Removes the file name extension from a path, if one is present. |
| AfxPathRemoveFileSpec | Removes the trailing file name and backslash from a path, if they are present. |
| AfxPathRenameExtension | Replaces the extension of a file name with a new extension. If the file name does not contain an extension, the extension will be attached to the end of the string. |
| AfxPathSearchAndQualify | Determines if a given path is correctly formatted and fully qualified. |
| AfxPathSetDlgItemPath | Sets the text of a child control in a window or dialog box, using AfxCompactPath to ensure the path fits in the control. |
| AfxPathSkipRoot | Parses a path, ignoring the drive letter or Universal Naming Convention (UNC) server/share path elements. |
| AfxPathStripPath | Removes the path portion of a fully qualified path and file. |
| AfxPathStripToRoot | Removes all parts of the path except for the root information. |
| AfxPathUndecorate | Removes the decoration from a path string. |
| AfxPathUnExpandEnvStrings | Replaces certain folder names in a fully-qualified path with their associated environment string. |
| AfxPathUnmakeSystemFolder | Removes the attributes from a folder that make it a system folder. This folder must actually exist in the file system. |
| AfxPathUnquoteSpaces | Removes quotes from the beginning and end of a path. |
| AfxUrlApplyScheme | Determines a scheme for a specified URL string, and returns a string with an appropriate prefix. |
| AfxUrlCanonicalize | Converts a URL string into canonical form. |
| AfxUrlCombine | When provided with a relative URL and its base, returns a URL in canonical form. |
| AfxUrlCompare | Makes a case-sensitive comparison of two URL strings. |
| AfxUrlCreateFromPath | Converts a Microsoft MS-DOS path to a canonicalized URL. |
| AfxUrlEscape | Converts characters in a URL that might be altered during transport across the Internet ("unsafe" characters) into their corresponding escape sequences. |
| AfxUrlEscapeSpaces | Converts space characters into their corresponding escape sequence. |
| AfxUrlFixup | Attempts to correct a URL whose protocol identifier is incorrect. For example, htttp will be changed to http. |
| AfxUrlGetLocation | Retrieves the location from a URL. |
| AfxUrlGetPart | Accepts a URL string and returns a specified part of that URL. |
| AfxUrlHash | Hashes a URL string. |
| AfxUrlIs | Tests whether or not a URL is a specified type. |
| AfxUrlIsFileUrl | Tests a URL to determine if it is a file URL. |
| AfxUrlIsNoHistory | Returns whether a URL is a URL that browsers typically do not include in navigation history. |
| AfxUrlIsOpaque | Returns whether a URL is opaque. |
| AfxUrlUnescape | Converts escape sequences back into ordinary characters. |
| AfxUrlUnescapeInPlace | Converts escape sequences back into ordinary characters and overwrites the original string. |

# <a name="AfxBrowseForFolder"></a>AfxBrowseForFolder

Displays a dialog box that enables the user to select a folder.

```
FUNCTION AfxBrowseForFolder (BYVAL hwnd AS HWND, BYVAL pwszTitle AS WSTRING PTR = NULL, _
   BYVAL pwszStartFolder AS WSTRING PTR = NULL, BYVAL nFlags AS LONG = 0) AS CWSTR
```

| Parameter  | Description |
| ---------- | ----------- |
| *hwnd* | The handle to the parent window of the dialog box. This value can be zero. |
| *pwszTitle* | Optional. A string value that represents the title displayed inside the Browse dialog box. |
| *pwszStartFolder* | Optional.  The initial folder that the dialog will show. |
| *nFlags* | Optional. A LONG value that contains the options for the method. This can be zero or a combination of the values listed under the *ulFlags* member of the **BROWSEINFO** structure. |

| Flag       | Description |
| ---------- | ----------- |
| BIF_RETURNONLYFSDIRS | Only return file system directories. If the user selects folders that are not part of the file system, the OK button is grayed. |
| BIF_DONTGOBELOWDOMAIN | Do not include network folders below the domain level in the dialog box's tree view control. |
| BIF_STATUSTEXT | Include a status area in the dialog box. The callback function can set the status text by sending messages to the dialog box. This flag is not supported when BIF_NEWDIALOGSTYLE is specified. |
| BIF_RETURNFSANCESTORS | Only return file system ancestors. An ancestor is a subfolder that is beneath the root folder in the namespace hierarchy. If the user selects an ancestor of the root folder that is not part of the file system, the OK button is grayed. |
| BIF_EDITBOX | Version 4.71. Include an edit control in the browse dialog box that allows the user to type the name of an item. |
| BIF_NEWDIALOGSTYLE | Version 5.0. Use the new user interface. Setting this flag provides the user with a larger dialog box that can be resized. The dialog box has several new capabilities, including: drag-and-drop capability within the dialog box, reordering, shortcut menus, new folders, delete, and other shortcut menu commands. |
| BIF_USENEWUI | Version 5.0. Use the new user interface, including an edit box. This flag is equivalent to BIF_EDITBOX OR BIF_NEWDIALOGSTYLE. |
| BIF_UAHINT | Version 6.0. When combined with BIF_NEWDIALOGSTYLE, adds a usage hint to the dialog box, in place of the edit box. BIF_EDITBOX overrides this flag. |
| BIF_NONEWFOLDERBUTTON | Version 6.0. Do not include the New Folder button in the browse dialog box. |
| BIF_NOTRANSLATETARGETS | Version 6.0. When the selected item is a shortcut, return the PIDL of the shortcut itself rather than its target. |
| BIF_BROWSEFORCOMPUTER | Only return computers. If the user selects anything other than a computer, the OK button is grayed. |
| BIF_BROWSEFORPRINTER | Only allow the selection of printers. If the user selects anything other than a printer, the OK button is grayed. In Windows XP and later systems, the best practice is to use a Windows XP-style dialog, setting the root of the dialog to the Printers and Faxes folder (CSIDL_PRINTERS). |
| BIF_BROWSEINCLUDEFILES | Version 4.71. The browse dialog box displays files as well as folders. |
| BIF_SHAREABLE | Version 5.0. The browse dialog box can display shareable resources on remote systems. This is intended for applications that want to expose remote shares on a local system. The BIF_NEWDIALOGSTYLE flag must also be set. |
| BIF_BROWSEFILEJUNCTIONS | Windows 7 and later. Allow folder junctions such as a library or a compressed file with a .zip file name extension to be browsed. |

#### Notes

If COM is initialized through CoInitializeEx with the COINIT_MULTITHREADED flag set, **AfxShellBrowserForFolder** fails if BIF_NEWDIALOGSTYLE or BIF_USENEWUI are passed.

#### Return value

The path of the selected folder.

#### Remarks

If you don't pass any flags, the function will use BIF_RETURNONLYFSDIRS OR BIF_DONTGOBELOWDOMAIN OR BIF_USENEWUI OR BIF_RETURNFSANCESTORS.

#### Usage example

```
DIM cws AS CWSTR = AfxBrowseForFolder(hwnd, "C:")
```

# <a name="AfxOpenFileDialog"></a>AfxOpenFileDialog

Creates an **Open** dialog box that lets the user specify the drive, directory, and the name of a file or set of files to be opened. The dialog box uses the Explorer-style user interface.

```
FUNCTION AfxOpenFileDialog (BYVAL hwndOwner AS HWND, BYREF wszTitle AS WSTRING, BYREF wszFile AS WSTRING, _
   BYREF wszInitialDir AS WSTRING, BYREF wszFilter AS WSTRING, BYREF wszDefExt AS WSTRING, _
   BYVAL pdwFlags AS DWORD PTR = NULL, BYVAL pdwBufLen AS DWORD PTR = NULL) AS CWSTR
```

| Parameter  | Description |
| ---------- | ----------- |
| *hwndOwner* | A handle to the window that owns the dialog box. This member can be any valid window handle, or it can be NULL if the dialog box has no owner. |
| *wszTitle* | A string to be placed in the title bar of the dialog box. If this member is NULL, the system uses the default title (that is, **Open**). |
| *wszFile* | The file name used to initialize the **File Name** edit control. |
| *wszInitialDir* | The initial directory.  If no initial directory is specified, the dialog will use the current directory. |
| *wszFilter* | A buffer containing pairs of "|" separated strings. The first string in each pair is a display string that describes the filter (for example, "Text Files"), and the second string specifies the filter pattern (for example, "\*.TXT"). To specify multiple filter patterns for a single display string, use a semicolon to separate the patterns (for example, "\*.TXT;\*.DOC;\*.BAK"). A pattern string can be a combination of valid file name characters and the asterisk (\*) wildcard character. Do not include spaces in the pattern string. The system does not change the order of the filters. It displays them in the File Types combo box in the order specified in *wszFilter*. |
| *wszDefExt* | The default extension. This extension is appended to the file name if the user fails to type an extension. This string can be any length, but only the first three characters are appended. The string should not contain a period (.). If this member is NULL and the user fails to type an extension, no extension is appended. |
| *pdwFlags* | \[in, out, optional] A set of bit flags you can use to initialize the dialog box. When the dialog box returns, it sets these flags to indicate the user's input. This member can be a combination of the following flags. |
| *pdwBufLen* | \[in, out, optional] Maximum length of the returned string containing the selected file or files. |

| Flag       | Description |
| ---------- | ----------- |
| OFN_ALLOWMULTISELECT | The **File Name** list box allows multiple selections. |
| OFN_DONTADDTORECENT | Prevents the system from adding a link to the selected file in the file system directory that contains the user's most recently used documents. To retrieve the location of this directory, call the **SHGetSpecialFolderLocation** function with the CSIDL_RECENT flag. |
| OFN_EXTENSIONDIFFERENT | The user typed a file name extension that differs from the extension specified by wszDefExt. The function does not use this flag if wszDefExt is NULL. |
| OFN_FILEMUSTEXIST | The user can type only names of existing files in the **File Name** entry field. If this flag is specified and the user enters an invalid name, the dialog box procedure displays a warning in a message box. If this flag is specified, the OFN_PATHMUSTEXIST flag is also used. |
| OFN_FORCESHOWHIDDEN | Forces the showing of system and hidden files, thus overriding the user setting to show or not show hidden files. However, a file that is marked both system and hidden is not shown. |
| OFN_HIDEREADONLY | Hides the Read Only check box. |
| OFN_NODEREFERENCELINKS | Directs the dialog box to return the path and file name of the selected shortcut (.LNK) file. If this value is not specified, the dialog box returns the path and file name of the file referenced by the shortcut. |
| OFN_NONETWORKBUTTON | Hides and disables the Network button. |
| OFN_NOREADONLYRETURN | The returned file does not have the Read Only check box selected and is not in a write-protected directory. |
| OFN_PATHMUSTEXIST | The user can type only valid paths and file names. If this flag is used and the user types an invalid path and file name in the **File Name** entry field, the dialog box function displays a warning in a message box. |
| OFN_READONLY | Causes the Read Only check box to be selected initially when the dialog box is created. This flag indicates the state of the Read Only check box when the dialog box is closed. |
| OFN_SHOWHELP | Causes the dialog box to display the Help button. The hwndOwner member must specify the window to receive the HELPMSGSTRING registered messages that the dialog box sends when the user clicks the **Help** button. |

#### Return value

If the OFN_ALLOWMULTISELECT flag is set and the user selects multiple files, the returned string contains the current directory followed by the file names of the selected files. For Explorer-style dialog boxes, the directory and file name strings are separated by semicolons. If the user selects only one file, the returned string does not have a separator between the path and file name.

Parse the number of ",". If only one, then the user has selected only a file and the string contains the full path. If more, The first substring contains the path and the others the files. If the user has not selected any file, an empty string is returned. On failure, an empty string is returned and, if not null, the pdwBufLen parameter will be filled by the size of the required buffer in characters.

#### Usage example:

```
DIM wszFile AS WSTRING * 260 = "*.*"
DIM wszInitialDir AS STRING * 260 = CURDIR
DIM wszFilter AS WSTRING * 260 = "BAS files (*.BAS)|*.BAS|" & "All Files (*.*)|*.*|"
DIM dwFlags AS DWORD = OFN_EXPLORER OR OFN_FILEMUSTEXIST OR OFN_HIDEREADONLY OR OFN_ALLOWMULTISELECT
DIM cws AS CWSTR = AfxOpenFileDialog(hwnd, "", wszFile, wszInitialDir, wszFilter, "BAS", @dwFlags, NULL)
AfxMsg cws
```

# <a name="AfxSaveFileDialog"></a>AfxSaveFileDialog

Creates a **Save** dialog box that lets the user specify the drive, directory, and name of a file to save. The dialog box uses the Explorer-style user interface.

```
FUNCTION AfxSaveFileDialog (BYVAL hwndOwner AS HWND, BYREF wszTitle AS WSTRING, BYREF wszFile AS WSTRING, _
   BYREF wszInitialDir AS WSTRING, BYREF wszFilter AS WSTRING, BYREF wszDefExt AS WSTRING, _
   BYVAL pdwFlags AS DWORD PTR = NULL) AS CWSTR
```

| Parameter  | Description |
| ---------- | ----------- |
| *hwndOwner* | A handle to the window that owns the dialog box. This member can be any valid window handle, or it can be NULL if the dialog box has no owner. |
| *wszTitle* | A string to be placed in the title bar of the dialog box. If this member is NULL, the system uses the default title (that is, **Save As**). |
| *wszFile* | The file name used to initialize the **File Name** edit control. |
| *wszInitialDir* | The initial directory.  If no initial directory is specified, the dialog will use the current directory. |
| *wszFilter* | A buffer containing pairs of "|" separated strings. The first string in each pair is a display string that describes the filter (for example, "Text Files"), and the second string specifies the filter pattern (for example, "\*.TXT"). To specify multiple filter patterns for a single display string, use a semicolon to separate the patterns (for example, "\*.TXT;\*.DOC;\*.BAK"). A pattern string can be a combination of valid file name characters and the asterisk (\*) wildcard character. Do not include spaces in the pattern string. The system does not change the order of the filters. It displays them in the File Types combo box in the order specified in *wszFilter*. |
| *wszDefExt* | The default extension. This extension is appended to the file name if the user fails to type an extension. This string can be any length, but only the first three characters are appended. The string should not contain a period (.). If this member is NULL and the user fails to type an extension, no extension is appended. |
| *pdwFlags* | \[in, out, optional] A set of bit flags you can use to initialize the dialog box. When the dialog box returns, it sets these flags to indicate the user's input. This member can be a combination of the following flags. |

| Flag       | Description |
| ---------- | ----------- |
| OFN_CREATEPROMPT | If the user specifies a file that does not exist, this flag causes the dialog box to prompt the user for permission to create the file. If the user chooses to create the file, the dialog box closes and the function returns the specified name; otherwise, the dialog box remains open. |
| OFN_DONTADDTORECENT | Prevents the system from adding a link to the selected file in the file system directory that contains the user's most recently used documents. To retrieve the location of this directory, call the **SHGetSpecialFolderLocation** function with the CSIDL_RECENT flag. |
| OFN_EXTENSIONDIFFERENT | The user typed a file name extension that differs from the extension specified by *wszDefExt*. The function does not use this flag if *wszDefExt* is NULL. |
| OFN_FORCESHOWHIDDEN | Forces the showing of system and hidden files, thus overriding the user setting to show or not show hidden files. However, a file that is marked both system and hidden is not shown. |
| OFN_HIDEREADONLY | Hides the **Read Only** check box |
| OFN_NOCHANGEDIR | Restores the current directory to its original value if the user changed the directory while searching for files. |
| OFN_NODEREFERENCELINKS | Directs the dialog box to return the path and file name of the selected shortcut (.LNK) file. If this value is not specified, the dialog box returns the path and file name of the file referenced by the shortcut. |
| OFN_NOTESTFILECREATE | The file is not created before the dialog box is closed. This flag should be specified if the application saves the file on a create-nonmodify network share. When an application specifies this flag, the library does not check for write protection, a full disk, an open drive door, or network protection. Applications using this flag must perform file operations carefully, because a file cannot be reopened once it is closed. |
| OFN_NONETWORKBUTTON | Hides and disables the **Network** button. |
| OFN_NOREADONLYRETURN | The returned file does not have the **Read Only** check box selected and is not in a write-protected directory. |
| OFN_OVERWRITEPROMPT | The user can type only valid paths and file names. If this flag is used and the user types an invalid path and file name in the **File Name** entry field, the dialog box function displays a warning in a message box. |
| OFN_PATHMUSTEXIST | The user can type only valid paths and file names. If this flag is used and the user types an invalid path and file name in the **File Name** entry field, the dialog box function displays a warning in a message box. |
| OFN_SHOWHELP | Causes the dialog box to display the **Help** button. The hwndOwner member must specify the window to receive the HELPMSGSTRING registered messages that the dialog box sends when the user clicks the **Help** button. |

#### Return value

The path of the file to be saved.

#### Usage example:

```
DIM wszFile AS WSTRING * 260 = "*.*"
DIM wszInitialDir AS STRING * 260 = CURDIR
DIM wszFilter AS WSTRING * 260 = "BAS files (*.BAS)|*.BAS|" & "All Files (*.*)|*.*|"
DIM dwFlags AS DWORD = OFN_EXPLORER OR OFN_FILEMUSTEXIST OR OFN_HIDEREADONLY OR OFN_OVERWRITEPROMPT
DIM cws AS CWSTR = AfxSaveFileDialog(hwnd, "", wszFile, wszInitialDir, wszFilter, "BAS", @dwFlags)
AfxMsg cws
```

# <a name="AfxChDir"></a>AfxChDir / AfxSetCurDir / AfxSetCurrentDirectory

Changes the current directory for the current process.

```
FUNCTION AfxChDir (BYVAL pwszPathName AS LPCWSTR) AS BOOLEAN
FUNCTION AfxSetCurDir (BYVAL pwszPathName AS LPCWSTR) AS BOOLEAN
FUNCTION AfxSetCurrentDirectory (BYVAL pwszPathName AS LPCWSTR) AS BOOLEAN
```

| Parameter  | Description |
| ---------- | ----------- |
| *lpPathName* | The path to the new current directory. This parameter may specify a relative path or a full path. In either case, the full path of the specified directory is calculated and stored as the current directory. |

#### Return value

If the function succeeds, the return value is TRUE.<br>
If the function fails, the return value is FALSE.<br>
To get extended error information, call **GetLastError**.

# <a name="AfxCopyFile"></a>AfxCopyFile / AfxFileCopy

Copies an existing file to a new file.

```
FUNCTION AfxCopyFile (BYVAL lpExistingFileName AS LPCWSTR, BYVAL lpNewFileName AS LPCWSTR, _
   BYVAL bFailIfExists AS BOOLEAN = FALSE) AS BOOLEAN
FUNCTION AfxFileCopy (BYVAL lpExistingFileName AS LPCWSTR, BYVAL lpNewFileName AS LPCWSTR, _
   BYVAL bFailIfExists AS BOOLEAN = FALSE) AS BOOLEAN
```

| Parameter  | Description |
| ---------- | ----------- |
| *lpExistingFileName* | The name of an existing file. To extend the limit of MAX_PATH characters to 32,767 wide characters prepend "\\?" to the path. If *lpExistingFileName* does not exist, **CopyFile** fails, and **GetLastError** returns ERROR_FILE_NOT_FOUND. |
| *lpNewFileName* | The name of the new file. To extend the limit of MAX_PATH characters to 32,767 wide characters prepend "\\?" to the path. |
| *bFailIfExists* | If this parameter is TRUE and the new file specified by *lpNewFileName* already exists, the function fails. If this parameter is FALSE and the new file already exists, the function overwrites the existing file and succeeds. |

#### Return value

If the function succeeds, the return value is TRUE.<br>
If the function fails, the return value is FALSE. To get extended error information, call **GetLastError**.

#### Rermarks

**AfxFileCopy** is an unicode replacement for Free Basic's **FileCopy** and returns 0 on success, or 1 if an error occurred.

# <a name="AfxMakeDir"></a>AfxMakeDir / AfxCreateDirectory / AfxMkDir

Creates a new directory.

```
FUNCTION AfxCreateDirectory (BYVAL lpPathName AS LPCWSTR) AS BOOLEAN
FUNCTION AfxMakeDir (BYVAL lpPathName AS LPCWSTR) AS BOOLEAN
FUNCTION AfxMkDir (BYVAL lpPathName AS LPCWSTR) AS BOOLEAN
```

| Parameter  | Description |
| ---------- | ----------- |
| *lpPathName* | The path of the directory to be created. To extend the limit to 32,767 wide characters, prepend "\\?" to the path. |

#### Return value:

If the function succeeds, the return value is TRUE.<br>
If the function fails, the return value is FALSE.<br>
To get extended error information, call GetLastError.

Possible errors include the following.

| Error      | Description |
| ---------- | ----------- |
| ERROR_ALREADY_EXISTS | The specified directory already exists. |
| ERROR_PATH_NOT_FOUND | One or more intermediate directories do not exist; this function will only create the final directory in the path. |

#### Remarks

**AfxMkDir** is an unicode replacement for Free Basic's **MkDir** and returns 0 on success, or -1 on failure.

# <a name="AfxDeleteFile"></a>AfxDeleteFile / AfxKill

Deletes the specified file.

```
FUNCTION AfxDeleteFile (BYVAL pwszFileSpec AS WSTRING PTR) AS BOOLEAN
FUNCTION AfxKill (BYVAL pwszFileSpec AS WSTRING PTR) AS BOOLEAN
```

| Parameter  | Description |
| ---------- | ----------- |
| *pwszFileSpec* | The full path and name of the file to delete. To extend the limit to 32,767 wide characters, prepend "\\?" to the path. |

#### Return value:

If the function succeeds, the return value is TRUE.<br>
If the function fails, the return value is FALSE.<br>
To get extended error information, call GetLastError.

#### Remarks

If an application attempts to delete a file that does not exist, this function fails with ERROR_FILE_NOT_FOUND. If the file is a read-only file, the function fails with ERROR_ACCESS_DENIED.

**AfxKill** is an unicode replacement for Free Basic's **Kill** and returns 0 on success, or -1 on failure.

# <a name="AfxFileDateTime"></a>AfxFileDateTime

Returns the file's last modified date and time as Date Serial.

```
FUNCTION AfxFileDateTime (BYREF wszFileName AS WSTRING) AS DOUBLE
```

#### Return value

The date and time as a Date Serial. If it fails, it returns 0.

#### Remark

Unicode replacement for Free Basic's **FileDateTime**.

#### Example

```
#include "windows.bi"
#include "vbcompat.bi"
#include "Afx/AfxWin.bi"
DIM wszFileName AS WSTRING * MAX_PATH = ExePath & "\c2.bas"
DIM dt AS DOUBLE = AfxFileDateTime(wszFileName)
PRINT Format(dt, "yyyy-mm-dd hh:mm AM/PM")
```

# <a name="AfxCurDir"></a>AfxCurdir / AfxGetCurDir / AfxGetCurrentDirectory

Retrieves the current directory for the current process.

```
FUNCTION AfxCurDir () AS CWSTR
FUNCTION AfxGetCurDir () AS CWSTR
FUNCTION AfxGetCurrentDirectory () AS CWSTR
```

#### Return value

The name of the current directory for the current process.

#### Remark

Unicode replacement for Free Basic's **CurDir**.

# <a name="AfxMoveFile"></a>AfxRenameFile / AfxMoveFile / AfxName

Moves an existing file or a directory, including its children.

```
FUNCTION AfxRenameFile (BYVAL lpExistingFileName AS LPCWSTR, BYVAL lpNewFileName AS LPCWSTR) AS BOOLEAN
FUNCTION AfxMoveFile (BYVAL lpExistingFileName AS LPCWSTR, BYVAL lpNewFileName AS LPCWSTR) AS BOOLEAN
FUNCTION AfxName (BYVAL lpExistingFileName AS LPCWSTR, BYVAL lpNewFileName AS LPCWSTR) AS LONG
```

| Parameter  | Description |
| ---------- | ----------- |
| *lpExistingFileName* | The name of an existing file. To extend the limit to 32,767 wide characters, prepend "\\?" to the path. If *lpExistingFileName* does not exist, **AfxRenameFile** fails, and **GetLastError** returns ERROR_FILE_NOT_FOUND. |
| *lpNewFileName* | The name of the new file. To extend the limit to 32,767 wide characters, prepend "\\?" to the path. |

#### Return value:

If the function succeeds, the return value is TRUE.<br>
If the function fails, the return value is FALSE.<br>
To get extended error information, call **GetLastError**.

#### Remark

**AfxName** is an unicode replacement for Free Basic's **Name** and returns 0 on success, or non-zerp on failure.
