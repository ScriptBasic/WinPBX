' ########################################################################################
' Microsoft Windows
' File: AfxPath.inc
' Contents: Path functions.
' Copyright (c) 2011 José Roca
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%AFXPATH_INC = 1

#INCLUDE ONCE "windows.inc"
#INCLUDE ONCE "shlwapi.inc"
'#INCLUDE ONCE "shlobj.inc"

' // Avoid the inclusion of shlobj.inc
#IF NOT %DEF(%WININET_INC)
%INTERNET_MAX_PATH_LENGTH        = 2048
%INTERNET_MAX_SCHEME_LENGTH      = 32    ' longest protocol name length
%INTERNET_MAX_URL_LENGTH         = (%INTERNET_MAX_SCHEME_LENGTH _
                                    + 4 _ ' sizeof("://") + null
                                    + %INTERNET_MAX_PATH_LENGTH)
#ENDIF

' ========================================================================================
' Adds a backslash to the end of a string to create the correct syntax for a path.
' ========================================================================================
FUNCTION AfxPathAddBackSlash (BYVAL bstrPath AS WSTRING) AS WSTRING
   LOCAL wszPath AS WSTRINGZ * %MAX_PATH
   wszPath = bstrPath
   PathAddBackSlashW(wszPath)
   FUNCTION = wszPath
END FUNCTION
' ========================================================================================

' ========================================================================================
' Adds a file extension to a path string.
' ========================================================================================
FUNCTION AfxPathAddExtension (BYVAL bstrPath AS WSTRING, BYVAL bstrExtension AS WSTRING) AS WSTRING
   LOCAL wszPath AS WSTRINGZ * %MAX_PATH
   wszPath = bstrPath
   PathAddExtensionW(wszPath, BYCOPY bstrExtension)
   FUNCTION = wszPath
END FUNCTION
' ========================================================================================

' ========================================================================================
' Appends one path to the end of another.
' ========================================================================================
FUNCTION AfxPathAppend (BYVAL bstrPath AS WSTRING, BYVAL bstrMore AS WSTRING) AS WSTRING
   LOCAL wszPath AS WSTRINGZ * %MAX_PATH
   wszPath = bstrPath
   PathAppendW(wszPath, BYCOPY bstrMore)
   FUNCTION = wszPath
END FUNCTION
' ========================================================================================

' ========================================================================================
' Creates a root path from a given drive number.
' ========================================================================================
FUNCTION AfxPathBuildRoot (BYVAL nDrive AS LONG) AS WSTRING
   LOCAL wszRoot AS WSTRINGZ * 4
   PathBuildRootW(wszRoot, nDrive)
   FUNCTION = wszRoot
END FUNCTION
' ========================================================================================

' ========================================================================================
' Canonicalizes a path.
' ========================================================================================
FUNCTION AfxPathCanonicalize (BYVAL bstrPath AS WSTRING) AS WSTRING
   LOCAL wszDest AS WSTRINGZ * %MAX_PATH
   PathCanonicalizeW(wszDest, BYCOPY bstrPath)
   FUNCTION = wszDest
END FUNCTION
' ========================================================================================

' ========================================================================================
' Concatenates two strings that represent properly formed paths into one path, as
' well as any relative path pieces.
' ========================================================================================
FUNCTION AfxPathCombine (BYVAL bstrDir AS WSTRING, BYVAL bstrFile AS WSTRING) AS WSTRING
   LOCAL wszDest AS WSTRINGZ * %MAX_PATH
   PathCombineW(wszDest, BYCOPY bstrDir, BYCOPY bstrFile)
   FUNCTION = wszDest
END FUNCTION
' ========================================================================================

' ========================================================================================
' Compares two paths to determine if they share a prefix and returns a string
' with the prefix characters, if any. A prefix is one of these types: "C:\\",
' ".", "..", "..\\".
' ========================================================================================
FUNCTION AfxPathCommonPrefix (BYVAL bstrFile1 AS WSTRING, BYVAL bstrFile2 AS WSTRING) AS WSTRING
   LOCAL szPath AS WSTRINGZ * %MAX_PATH
   PathCommonPrefixW(BYCOPY bstrFile1, BYCOPY bstrFile2, szPath)
   FUNCTION = szPath
END FUNCTION
' ========================================================================================

' ========================================================================================
' Truncates a file path to fit within a given pixel width by replacing path
' components with ellipses.
' ========================================================================================
FUNCTION AfxPathCompactPath (BYVAL hDC AS DWORD, BYVAL bstrPath AS WSTRING, BYVAL dx AS DWORD) AS WSTRING
   LOCAL wszPath AS WSTRINGZ * %MAX_PATH
   wszPath = bstrPath
   PathCompactPathW(hDC, wszPath, dx)
   FUNCTION = wszPath
END FUNCTION
' ========================================================================================

' ========================================================================================
' Truncates a path to fit within a certain number of characters by replacing path
' components with ellipses.
' ========================================================================================
FUNCTION AfxPathCompactPathEx (BYVAL bstrSrc AS WSTRING, BYVAL cchMax AS DWORD) AS WSTRING
   LOCAL wszOut AS WSTRINGZ * %MAX_PATH
   IF cchMax > %MAX_PATH THEN cchMax = %MAX_PATH - 1
   PathCompactPathExW(wszOut, BYCOPY bstrSrc, cchMax + 1, 0)
   FUNCTION = wszOut
END FUNCTION
' ========================================================================================

' ========================================================================================
' Takes a file URL and converts it to a Microsoft MS-DOS path.
' ========================================================================================
FUNCTION AfxPathCreateFromUrl (BYVAL bstrUrl AS WSTRING) AS WSTRING
   LOCAL cchPath AS DWORD
   LOCAL wszPath AS WSTRINGZ * %MAX_PATH
   cchPath = SIZEOF(wszPath)
   PathCreateFromUrlW(BYCOPY bstrUrl, wszPath, cchPath, 0)
   FUNCTION = wszPath
END FUNCTION
' ========================================================================================

' ========================================================================================
' Determines whether a path to a file system object such as a file or directory is valid.
' ========================================================================================
FUNCTION AfxPathFileExists (BYVAL bstrPath AS WSTRING) AS LONG
   FUNCTION = PathFileExistsW(BYCOPY bstrPath)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Searches a path for an extension.
' ========================================================================================
FUNCTION AfxPathFindExtension (BYVAL bstrPath AS WSTRING) AS WSTRING
   LOCAL pAddr AS DWORD
   LOCAL wszPath AS WSTRINGZ * %MAX_PATH
   wszPath = bstrPath
   pAddr = PathFindExtensionW(wszPath)
   IF pAddr THEN
      wszPath = PEEK$$(pAddr, VARPTR(wszPath) + LEN(wszPath) * 2 - pAddr)
      FUNCTION = wszPath
   END IF
END FUNCTION
' ========================================================================================

' ========================================================================================
' Searches a path for a file name.
' ========================================================================================
FUNCTION AfxPathFindFileName (BYVAL bstrPath AS WSTRING) AS WSTRING
   LOCAL pAddr AS DWORD
   LOCAL wszPath AS WSTRINGZ * %MAX_PATH
   wszPath = bstrPath
   pAddr = PathFindFileNameW(wszPath)
   IF pAddr THEN
      wszPath = PEEK$$(pAddr, VARPTR(wszPath) + LEN(wszPath) * 2 - pAddr)
      FUNCTION = wszPath
   END IF
END FUNCTION
' ========================================================================================

' ========================================================================================
' Parses a path for the next path component.
' ========================================================================================
FUNCTION AfxPathFindNextComponent (BYVAL bstrPath AS WSTRING) AS WSTRING
   LOCAL pwszComp AS WSTRINGZ PTR
   pwszComp = PathFindNextComponentW(BYCOPY bstrPath)
   IF pwszComp THEN FUNCTION = @pwszComp
END FUNCTION
' ========================================================================================

' ========================================================================================
' Searches for a file.
' ========================================================================================
FUNCTION AfxPathFindOnPath (BYVAL bstrFile AS WSTRING, OPTIONAL BYREF wszOtherDirs AS WSTRINGZ) AS WSTRING
   LOCAL wszFile AS WSTRINGZ * %MAX_PATH
   wszFile = bstrFile
   IF VARPTR(wszOtherDirs) THEN
      IF ISTRUE PathFindOnPathW(wszFile, wszOtherDirs) THEN FUNCTION = wszFile
   ELSE
      IF ISTRUE PathFindOnPathW(wszFile, BYVAL %NULL) THEN FUNCTION = wszFile
   END IF
END FUNCTION
' ========================================================================================

' ========================================================================================
' Determines if a given file name has one of a list of suffixes.
' ========================================================================================
FUNCTION AfxPathFindSuffixArrayA (BYVAL strPath AS STRING, BYREF apszSuffix AS ASCIIZ, BYVAL iArraySize AS LONG) AS STRING
   LOCAL pszSuffix AS ASCIIZ PTR
   pszSuffix = PathFindSuffixArrayA(BYCOPY strPath, apszSuffix, iArraySize)
   IF pszSuffix THEN FUNCTION = @pszSuffix
END FUNCTION
' ========================================================================================

' ========================================================================================
' Determines if a given file name has one of a list of suffixes.
' ========================================================================================
FUNCTION AfxPathFindSuffixArrayW (BYVAL bstrPath AS WSTRING, BYREF apwszSuffix AS WSTRINGZ, BYVAL iArraySize AS LONG) AS WSTRING
   LOCAL pwszSuffix AS WSTRINGZ PTR
   pwszSuffix = PathFindSuffixArrayW(BYCOPY bstrPath, apwszSuffix, iArraySize)
   IF pwszSuffix THEN FUNCTION = @pwszSuffix
END FUNCTION
' ========================================================================================

#IF %DEF(%UNICODE)
   MACRO AfxPathFindSuffixArray = AfxPathFindSuffixArrayW
#ELSE
   MACRO AfxPathFindSuffixArray = AfxPathFindSuffixArrayA
#ENDIF

' ========================================================================================
' Finds the command line arguments within a given path.
' ========================================================================================
FUNCTION AfxPathGetArgs (BYVAL bstrPath AS WSTRING) AS WSTRING
   LOCAL pwszArgs AS WSTRINGZ PTR
   pwszArgs = PathGetArgsW(BYCOPY bstrPath)
   IF pwszArgs <> %NULL THEN FUNCTION = @pwszArgs
END FUNCTION
' ========================================================================================

' ========================================================================================
' Determines the type of character with respect to a path.
' ========================================================================================
FUNCTION AfxPathGetCharType (BYVAL bstrCh AS WSTRING) AS DWORD
   FUNCTION = PathGetCharTypeW(ASC(bstrCh))
END FUNCTION
' ========================================================================================

' ========================================================================================
' Searches a path for a drive letter within the range of 'A' to 'Z' and returns the
' corresponding drive number.
' ========================================================================================
FUNCTION AfxPathGetDriveNumber (BYVAL bstrPath AS WSTRING) AS LONG
   FUNCTION = PathGetDriveNumberW(BYCOPY bstrPath)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Determines if a file's registered content type matches the specified content type.
' This function obtains the content type for the specified file type and compares
' that string with the szContentType The comparison is not case sensitive.
' ========================================================================================
FUNCTION AfxPathIsContentType (BYVAL bstrPath AS WSTRING, BYVAL bstrContentType AS WSTRING) AS LONG
   FUNCTION = PathIsContentTypeW(BYCOPY bstrPath, BYCOPY bstrContentType)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Verifies that a path is a valid directory.
' ========================================================================================
FUNCTION AfxPathIsDirectory (BYVAL bstrPath AS WSTRING) AS LONG
   FUNCTION = PathIsDirectoryW(BYCOPY bstrPath)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Determines whether or not a specified path is an empty directory.
' ========================================================================================
FUNCTION AfxPathIsDirectoryEmpty (BYVAL bstrPath AS WSTRING) AS LONG
   FUNCTION = PathIsDirectoryEmptyW(BYCOPY bstrPath)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Searches a path for any path delimiting characters (for example, ':' or '\' ).
' If there are no path delimiting characters present, the path is considered to be
' a File Spec path.
' ========================================================================================
FUNCTION AfxPathIsFileSpec (BYVAL bstrPath AS WSTRING) AS LONG
   FUNCTION = PathIsFileSpecW(BYCOPY bstrPath)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Determines if a file is an HTML file. The determination is made based on the
' content type that is registered for the file's extension.
' ========================================================================================
FUNCTION AfxPathIsHTMLFile (BYVAL bstrFile AS WSTRING) AS LONG
   FUNCTION = PathIsHTMLFileW(BYCOPY bstrFile)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Determines whether or not a file name is in long format.
' ========================================================================================
FUNCTION AfxPathIsLFNFileSpec (BYVAL bstrName AS WSTRING) AS LONG
   FUNCTION = PathIsLFNFileSpecW(BYCOPY bstrName)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Determines whether a path string represents a network resource.
' ========================================================================================
FUNCTION AfxPathIsNetworkPath (BYVAL bstrPath AS WSTRING) AS LONG
   FUNCTION = PathIsNetworkPathW(BYCOPY bstrPath)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Searches a path to determine if it contains a valid prefix of the type passed by
' szPrefix. A prefix is one of these types: "C:\\", ".", "..", "..\\".
' ========================================================================================
FUNCTION AfxPathIsPrefix (BYVAL bstrPrefix AS WSTRING, BYVAL bstrPath AS WSTRING) AS LONG
   FUNCTION = PathIsPrefixW(BYCOPY bstrPrefix, BYCOPY bstrPath)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Searches a path and determines if it is relative.
' ========================================================================================
FUNCTION AfxPathIsRelative (BYVAL bstrPath AS WSTRING) AS LONG
   FUNCTION = PathIsRelativeW(BYCOPY bstrPath)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Parses a path to determine if it is a directory root.
' ========================================================================================
FUNCTION AfxPathIsRoot (BYVAL bstrPath AS WSTRING) AS LONG
   FUNCTION = PathIsRootW(BYCOPY bstrPath)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Compares two paths to determine if they have a root component.
' ========================================================================================
FUNCTION AfxPathIsSameRoot (BYVAL bstrPath1 AS WSTRING, BYVAL bstrPath2 AS WSTRING) AS LONG
   FUNCTION = PathIsSameRootW(BYCOPY bstrPath1, BYCOPY bstrPath2)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Determines if an existing folder contains the attributes that make it a system
' folder. Alternately indicates if certain attributes qualify a folder to be a
' system folder.
' ========================================================================================
FUNCTION AfxPathIsSystemFolder (BYVAL bstrPath AS WSTRING, BYVAL dwAttrb AS DWORD) AS LONG
   FUNCTION = PathIsSystemFolderW(BYCOPY bstrPath, dwAttrb)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Determines if the string is a valid Universal Naming Convention (UNC) for a
' server and share path.
' ========================================================================================
FUNCTION AfxPathIsUNC (BYVAL bstrPath AS WSTRING) AS LONG
   FUNCTION = PathIsUNCW(BYCOPY bstrPath)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Determines if a string is a valid Universal Naming Convention (UNC) for a server
' path only.
' ========================================================================================
FUNCTION AfxPathIsUNCServer (BYVAL bstrPath AS WSTRING) AS LONG
   FUNCTION = PathIsUNCServerW(BYCOPY bstrPath)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Determines if a string is a valid Universal Naming Convention (UNC) share path,
' \\ server\ share.
' ========================================================================================
FUNCTION AfxPathIsUNCServerShare (BYVAL bstrPath AS WSTRING) AS LONG
   FUNCTION = PathIsUNCServerShareW(BYCOPY bstrPath)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Tests a given string to determine if it conforms to a valid URL format.
' ========================================================================================
FUNCTION AfxPathIsURL (BYVAL bstrPath AS WSTRING) AS LONG
   FUNCTION = PathIsURLW(BYCOPY bstrPath)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Converts a path to all lowercase characters to give the path a consistent appearance.
' This function only operates on paths that are entirely uppercase. For example:
' C:\WINDOWS will be converted to c:\windows, but c:\Windows will not be changed.
' ========================================================================================
FUNCTION AfxPathMakePretty (BYVAL bstrPath AS WSTRING) AS WSTRING
   LOCAL wszPath AS WSTRINGZ * %MAX_PATH
   wszPath = bstrPath
   PathMakePrettyW(wszPath)
   FUNCTION = wszPath
END FUNCTION
' ========================================================================================

' ========================================================================================
' Gives an existing folder the proper attributes to become a system folder.
' ========================================================================================
FUNCTION AfxPathMakeSystemFolder (BYVAL bstrPath AS WSTRING) AS LONG
   FUNCTION = PathMakeSystemFolderW(BYCOPY bstrPath)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Searches a string using an Microsoft MS-DOS wild card match type.
' ========================================================================================
FUNCTION AfxPathMatchSpec (BYVAL bstrFile AS WSTRING, BYVAL bstrSpec AS WSTRING) AS LONG
   FUNCTION = PathMatchSpecW(BYCOPY bstrFile, BYCOPY bstrSpec)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Searches a path to determine whether it contains a file of a specified file type extension.
' ========================================================================================
FUNCTION AfxPathMatchSpecEx (BYVAL bstrFile AS WSTRING, BYVAL bstrSpec AS WSTRING, BYVAL dwFlags AS DWORD) AS LONG
   FUNCTION = PathMatchSpecExW(BYCOPY bstrFile, BYCOPY bstrSpec, dwFlags)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Parses a file location string containing a file location and icon index, and
' returns the valid icon index value.
' ========================================================================================
FUNCTION AfxPathParseIconLocation (BYREF bstrIconFile AS WSTRING) AS WSTRING
   LOCAL wszIconFile AS WSTRINGZ * %MAX_PATH
   wszIconFile = bstrIconFile
   PathParseIconLocationW(wszIconFile)
   FUNCTION = wszIconFile
END FUNCTION
' ========================================================================================

' ========================================================================================
' Searches a path for spaces. If spaces are found, the entire path is enclosed in
' quotation marks.
' ========================================================================================
FUNCTION AfxPathQuoteSpaces (BYVAL bstrPath AS WSTRING) AS WSTRING
   LOCAL wszPath AS WSTRINGZ * %MAX_PATH
   wszPath = bstrPath
   PathQuoteSpacesW(wszPath)
   FUNCTION = wszPath
END FUNCTION
' ========================================================================================

' ========================================================================================
' Creates a relative path from one file or folder to another.
' ========================================================================================
FUNCTION AfxPathRelativePathTo (BYVAL bstrFrom AS WSTRING, BYVAL dwAttrFrom AS DWORD, BYVAL bstrTo AS WSTRING, BYVAL dwAttrTo AS DWORD) AS WSTRING
   LOCAL wszPath AS WSTRINGZ * %MAX_PATH
   IF ISTRUE PathRelativePathToW(wszPath, BYCOPY bstrFrom, dwAttrFrom, BYCOPY bstrTo, dwAttrto) THEN FUNCTION = wszPath
END FUNCTION
' ========================================================================================

' ========================================================================================
' Removes any arguments from a given path.
' ========================================================================================
FUNCTION AfxPathRemoveArgs (BYVAL bstrPath AS WSTRING) AS WSTRING
   LOCAL wszPath AS WSTRINGZ * %MAX_PATH
   wszPath = bstrPath
   PathRemoveArgsW(wszPath)
   FUNCTION = wszPath
END FUNCTION
' ========================================================================================

' ========================================================================================
' Removes the trailing backslash from a given path.
' ========================================================================================
FUNCTION AfxPathRemoveBackslash (BYVAL bstrPath AS WSTRING) AS WSTRING
   LOCAL wszPath AS WSTRINGZ * %MAX_PATH
   wszPath = bstrPath
   PathRemoveBackslashW(wszPath)
   FUNCTION = wszPath
END FUNCTION
' ========================================================================================

' ========================================================================================
' Removes all leading and trailing spaces from a path.
' ========================================================================================
FUNCTION AfxPathRemoveBlanks (BYVAL bstrPath AS WSTRING) AS WSTRING
   LOCAL wszPath AS WSTRINGZ * %MAX_PATH
   wszPath = bstrPath
   PathRemoveBlanksW(wszPath)
   FUNCTION = wszPath
END FUNCTION
' ========================================================================================

' ========================================================================================
' Removes the file extension from a path, if there is one.
' ========================================================================================
FUNCTION AfxPathRemoveExtension (BYVAL bstrPath AS WSTRING) AS WSTRING
   LOCAL wszPath AS WSTRINGZ * %MAX_PATH
   wszPath = bstrPath
   PathRemoveExtensionW(wszPath)
   FUNCTION = wszPath
END FUNCTION
' ========================================================================================

' ========================================================================================
' Removes the trailing file name and backslash from a path, if it has them.
' ========================================================================================
FUNCTION AfxPathRemoveFileSpec (BYVAL bstrPath AS WSTRING) AS WSTRING
   LOCAL wszPath AS WSTRINGZ * %MAX_PATH
   wszPath = bstrPath
   PathRemoveFileSpecW(wszPath)
   FUNCTION = wszPath
END FUNCTION
' ========================================================================================

' ========================================================================================
' Replaces the extension of a file name with a new extension. If the file name
' does not contain an extension, the extension will be attached to the end of the
' string.
' ========================================================================================
FUNCTION AfxPathRenameExtension (BYVAL bstrPath AS WSTRING, BYVAL bstrExt AS WSTRING) AS WSTRING
   LOCAL wszPath AS WSTRINGZ * %MAX_PATH
   wszPath = bstrPath
   PathRenameExtensionW(wszPath, BYCOPY bstrExt)
   FUNCTION = wszPath
END FUNCTION
' ========================================================================================

' ========================================================================================
' Determines if a given path is correctly formatted and fully qualified.
' ========================================================================================
FUNCTION AfxPathSearchAndQualify (BYVAL bstrPath AS WSTRING, BYVAL bstrFullyQualifiedPath AS WSTRING, BYVAL cchFullyQualifiedPath AS DWORD) AS LONG
   FUNCTION = PathSearchAndQualifyW(BYCOPY bstrPath, BYCOPY bstrFullyQualifiedPath, cchFullyQualifiedPath)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Sets the text of a child control in a window or dialog box, using
' PathCompactPath to make sure the path fits in the control.
' ========================================================================================
SUB AfxPathSetDlgItemPath (BYVAL hDlg AS DWORD, BYVAL id AS LONG, BYVAL bstrPath AS WSTRING)
   PathSetDlgItemPathW(BYVAL hDlg, BYVAL id, BYCOPY bstrPath)
END SUB
' ========================================================================================

' ========================================================================================
' Parses a path, ignoring the drive letter or Universal Naming Convention (UNC)
' server/share path parts.
' ========================================================================================
FUNCTION AfxPathSkipRoot (BYVAL bstrPath AS WSTRING) AS WSTRING
   LOCAL pAddr AS LONG
   LOCAL wszPath AS WSTRINGZ * %MAX_PATH
   wszPath = bstrPath
   pAddr = PathSkipRootW(wszPath)
   IF pAddr THEN
      wszPath = PEEK$$(pAddr, VARPTR(wszPath) + LEN(wszPath) * 2 - pAddr)
      FUNCTION = wszPath
   END IF
END FUNCTION
' ========================================================================================

' ========================================================================================
' Removes the path portion of a fully qualified path and file.
' ========================================================================================
FUNCTION AfxPathStripPath (BYVAL bstrPath AS WSTRING) AS WSTRING
   LOCAL wszPath AS WSTRINGZ * %MAX_PATH
   wszPath = bstrPath
   PathStripPathW(wszPath)
   FUNCTION = wszPath
END FUNCTION
' ========================================================================================

' ========================================================================================
' Removes all parts of the path except for the root information.
' ========================================================================================
FUNCTION AfxPathStripToRoot (BYVAL bstrPath AS WSTRING) AS WSTRING
   LOCAL wszPath AS WSTRINGZ * %MAX_PATH
   wszPath = bstrPath
   PathStripToRootW(wszPath)
   FUNCTION = wszPath
END FUNCTION
' ========================================================================================

' ========================================================================================
' Removes the decoration from a path string.
' ========================================================================================
FUNCTION AfxPathUndecorate (BYVAL bstrPath AS WSTRING) AS WSTRING
   LOCAL wszPath AS WSTRINGZ * %MAX_PATH
   wszPath = bstrPath
   PathUndecorateW(wszPath)
   FUNCTION = wszPath
END FUNCTION
' ========================================================================================

' ========================================================================================
' Takes a fully qualified path, and replaces several folder names with their
' associated environment string.
' ========================================================================================
FUNCTION AfxPathUnExpandEnvStrings (BYVAL bstrPath AS WSTRING) AS WSTRING
   LOCAL wszBuf AS WSTRINGZ * %MAX_PATH
   PathUnExpandEnvStringsW(BYCOPY bstrPath, wszBuf, SIZEOF(wszBuf))
   FUNCTION = wszBuf
END FUNCTION
' ========================================================================================

' ========================================================================================
' Removes the attributes from a folder that make it a system folder. This folder
' must actually exist in the file system.
' ========================================================================================
FUNCTION AfxPathUnmakeSystemFolder (BYVAL bstrPath AS WSTRING) AS LONG
   FUNCTION = PathUnmakeSystemFolderW(BYCOPY bstrPath)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Removes quotes from the beginning and end of a path.
' ========================================================================================
FUNCTION AfxPathUnquoteSpaces (BYVAL bstrPath AS WSTRING) AS WSTRING
   LOCAL wszPath AS WSTRINGZ * %MAX_PATH
   wszPath = bstrPath
   PathUnquoteSpacesW(wszPath)
   FUNCTION = wszPath
END FUNCTION
' ========================================================================================

' ========================================================================================
' Takes a URL string, determines a scheme for it, and returns a string with an
' appropriate prefix.
' ========================================================================================
FUNCTION AfxUrlApplyScheme (BYVAL bstrUrl AS WSTRING, BYVAL dwFlags AS DWORD) AS WSTRING
   LOCAL hr AS LONG
   LOCAL cchOut AS DWORD
   LOCAL wszOut AS WSTRINGZ * %INTERNET_MAX_URL_LENGTH
   cchOut = SIZEOF(wszOut)
   hr = UrlApplySchemeW(BYCOPY bstrUrl, wszOut, cchOut, dwFlags)
   IF hr = %S_OK OR hr = %S_FALSE THEN FUNCTION = wszOut ELSE FUNCTION = bstrUrl
END FUNCTION
' ========================================================================================

' ========================================================================================
' Takes a URL string and converts it into canonical form.
' ========================================================================================
FUNCTION AfxUrlCanonicalize (BYVAL bstrUrl AS WSTRING, BYVAL dwFlags AS DWORD) AS WSTRING
   LOCAL hr AS LONG
   LOCAL cchCanonicalized AS DWORD
   LOCAL wszCanonicalized AS WSTRINGZ * %INTERNET_MAX_URL_LENGTH
   cchCanonicalized = SIZEOF(wszCanonicalized)
   hr = UrlCanonicalizeW(BYCOPY bstrUrl, wszCanonicalized, cchCanonicalized, dwFlags)
   IF hr = %S_OK THEN FUNCTION = wszCanonicalized ELSE FUNCTION = bstrUrl
END FUNCTION
' ========================================================================================

' ========================================================================================
' When provided with a relative URL and its base, returns a URL in canonical form.
' ========================================================================================
FUNCTION AfxUrlCombine (BYVAL bstrBase AS WSTRING, BYVAL bstrRelative AS WSTRING, BYVAL dwFlags AS DWORD) AS WSTRING
   LOCAL hr AS LONG
   LOCAL cchCombined AS DWORD
   LOCAL wszCombined AS WSTRINGZ * %INTERNET_MAX_URL_LENGTH
   cchCombined = SIZEOF(wszCombined)
   hr = UrlCombineW(BYCOPY bstrBase, BYCOPY bstrRelative, wszCombined, cchCombined, dwFlags)
   IF hr = %S_OK THEN FUNCTION = wszCombined ELSE FUNCTION = bstrBase
END FUNCTION
' ========================================================================================

' ========================================================================================
' Makes a case-sensitive comparison of two URL strings.
' ========================================================================================
FUNCTION AfxUrlCompare (BYVAL bstrURL1 AS WSTRING, BYVAL bstrURL2 AS WSTRING, BYVAL fIgnoreSlash AS LONG) AS LONG
   FUNCTION = UrlCompareW(BYCOPY bstrURL1, BYCOPY bstrURL2, fIgnoreSlash)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Takes a Microsoft MS-DOS path and converts it to a canonicalized URL.
' ========================================================================================
FUNCTION AfxUrlCreateFromPath (BYVAL bstrPath AS WSTRING) AS WSTRING
   LOCAL hr AS LONG
   LOCAL cchUrl AS DWORD
   LOCAL wszUrl AS WSTRINGZ * %INTERNET_MAX_URL_LENGTH
   cchUrl = SIZEOF(wszUrl)
   hr = UrlCreateFromPathW(BYCOPY bstrPath, wszUrl, cchUrl, 0)
   IF hr = %S_OK OR hr = %S_FALSE THEN FUNCTION = wszUrl ELSE FUNCTION = bstrPath
END FUNCTION
' ========================================================================================

' ========================================================================================
' Converts characters in a URL that might be altered during transport across the
' Internet ("unsafe" characters) into their corresponding escape sequences.
' ========================================================================================
FUNCTION AfxUrlEscape (BYVAL bstrURL AS WSTRING, BYVAL dwFlags AS DWORD) AS WSTRING
   LOCAL hr AS LONG
   LOCAL cchEscaped AS DWORD
   LOCAL wszEscaped AS WSTRINGZ * %INTERNET_MAX_URL_LENGTH
   cchEscaped = SIZEOF(wszEscaped)
   hr = UrlEscapeW(BYCOPY bstrURL, wszEscaped, cchEscaped, 0)
   IF hr = %S_OK THEN FUNCTION = wszEscaped ELSE FUNCTION = bstrURL
END FUNCTION
' ========================================================================================

' ========================================================================================
' Converts space characters into their corresponding escape sequence.
' ========================================================================================
FUNCTION AfxUrlEscapeSpaces (BYVAL bstrURL AS WSTRING) AS WSTRING
   LOCAL hr AS LONG
   LOCAL cchEscaped AS DWORD
   LOCAL wszEscaped AS WSTRINGZ * %INTERNET_MAX_URL_LENGTH
   cchEscaped = SIZEOF(wszEscaped)
   hr = UrlEscapeSpacesW(BYCOPY bstrURL, wszEscaped, cchEscaped)
   IF hr = %S_OK THEN FUNCTION = wszEscaped ELSE FUNCTION = bstrURL
END FUNCTION
' ========================================================================================

' ========================================================================================
' Attempts to correct a URL whose protocol identifier is incorrect. For example, htttp
' will be changed to http.
' ========================================================================================
FUNCTION AfxUrlFixupW (BYVAL bstrUrl AS WSTRING) AS WSTRING
   LOCAL hr AS LONG
   LOCAL wszUrl AS WSTRINGZ * %INTERNET_MAX_URL_LENGTH
   LOCAL wszTranslatedUrl AS WSTRINGZ * %INTERNET_MAX_URL_LENGTH
   wszUrl = bstrUrl
   hr = UrlFixupW(wszUrl, wszTranslatedUrl, %INTERNET_MAX_URL_LENGTH)
   FUNCTION = wszTranslatedUrl
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the location from a URL.
' ========================================================================================
FUNCTION AfxUrlGetLocation (BYVAL bstrUrl AS WSTRING) AS WSTRING
   LOCAL pAddr AS DWORD
   LOCAL wszUrl AS WSTRINGZ * %MAX_PATH
   wszUrl = bstrUrl
   pAddr = UrlGetLocationW(wszUrl)
   IF pAddr THEN FUNCTION = PEEK$$(pAddr, VARPTR(wszUrl) + LEN(wszUrl) * 2 - pAddr)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Accepts a URL string and returns a specified part of that URL.
' ========================================================================================
FUNCTION AfxUrlGetPart (BYVAL bstrUrl AS WSTRING, BYVAL dwPart AS DWORD, BYVAL dwFlags AS DWORD) AS WSTRING
   LOCAL hr AS LONG
   LOCAL cchOut AS DWORD
   LOCAL wszOut AS WSTRINGZ * %INTERNET_MAX_URL_LENGTH
   cchOut = SIZEOF(wszOut)
   hr = UrlGetPartW(BYCOPY bstrUrl, wszOut, cchOut, dwPart, dwFlags)
   IF hr = %S_OK THEN FUNCTION = wszOut
END FUNCTION
' ========================================================================================

' ========================================================================================
' Hashes a URL string.
' ========================================================================================
FUNCTION AfxUrlHash (BYVAL bstrURL AS WSTRING, BYVAL pbHash AS BYTE PTR, BYVAL cbHash AS DWORD) AS LONG
   FUNCTION = UrlHashW(BYCOPY bstrURL, BYVAL pbHash, cbHash)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Tests whether or not a URL is a specified type.
' ========================================================================================
FUNCTION AfxUrlIs (BYVAL bstrURL AS WSTRING, BYVAL nUrlIs AS DWORD) AS LONG
   FUNCTION = UrlIsW(BYCOPY bstrURL, BYVAL nUrlIs)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns whether or not a URL is a No History URL.
' ========================================================================================
FUNCTION AfxUrlIsNoHistory (BYVAL bstrURL AS WSTRING) AS LONG
   FUNCTION = UrlIsNoHistoryW(BYCOPY bstrURL)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns whether a URL is opaque.
' ========================================================================================
FUNCTION AfxUrlIsOpaque (BYVAL bstrURL AS WSTRING) AS LONG
   FUNCTION = UrlIsOpaqueW(BYCOPY bstrURL)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Converts escape sequences back into ordinary characters.
' ========================================================================================
FUNCTION AfxUrlUnescape (BYVAL bstrURL AS WSTRING, BYVAL dwFlags AS DWORD) AS WSTRING
   LOCAL hr AS LONG
   LOCAL wszURL AS WSTRINGZ * %INTERNET_MAX_URL_LENGTH
   LOCAL cchUnescaped AS DWORD
   LOCAL wszUnescaped AS WSTRINGZ * %INTERNET_MAX_URL_LENGTH
   cchUnescaped = SIZEOF(wszUnescaped)
   wszURL = bstrURL
   hr = UrlUnescapeW(wszURL, wszUnescaped, cchUnescaped, 0)
   IF hr = %S_OK THEN
      IF (dwFlags AND %URL_UNESCAPE_INPLACE) = %URL_UNESCAPE_INPLACE THEN
         FUNCTION = wszURL
      ELSE
         FUNCTION = wszUnescaped
      END IF
   ELSE
      FUNCTION = wszURL
   END IF
END FUNCTION
' ========================================================================================

' ========================================================================================
' Converts escape sequences back into ordinary characters and overwrites the
' original string.
' ========================================================================================
FUNCTION AfxUrlUnescapeInPlace (BYREF wszURL AS WSTRINGZ, BYVAL dwFlags AS DWORD) AS LONG
   FUNCTION = UrlUnescapeInPlaceW(wszURL, dwFlags)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the path of the default browser.
' ========================================================================================
FUNCTION AfxGetDefaultBrowserPath () AS WSTRING
   LOCAL wszPath AS WSTRINGZ * %MAX_PATH
   IF SUCCEEDED(AssocQueryStringW(0, %ASSOCSTR_EXECUTABLE, "http", "open", wszPath, SIZEOF(wszPath))) THEN FUNCTION = wszPath
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the name of the default browser.
' ========================================================================================
FUNCTION AfxGetDefaultBrowserName () AS WSTRING
   LOCAL wszPath AS WSTRINGZ * %MAX_PATH
   IF SUCCEEDED(AssocQueryStringW(0, %ASSOCSTR_EXECUTABLE, "http", "open", wszPath, SIZEOF(wszPath))) THEN FUNCTION = PATHNAME$(NAMEX, wszPath)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the path of the default mail client application.
' ========================================================================================
FUNCTION AfxGetDefaultMailClientPath () AS WSTRING
   LOCAL wszPath AS WSTRINGZ * %MAX_PATH
   IF SUCCEEDED(AssocQueryStringW(0, %ASSOCSTR_EXECUTABLE, "mailto", "open", wszPath, SIZEOF(wszPath))) THEN FUNCTION = wszPath
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the name of the default mail client application.
' ========================================================================================
FUNCTION AfxGetDefaultMailClientName () AS WSTRING
   LOCAL wszPath AS WSTRINGZ * %MAX_PATH
   IF SUCCEEDED(AssocQueryStringW(0, %ASSOCSTR_EXECUTABLE, "mailto", "open", wszPath, SIZEOF(wszPath))) THEN FUNCTION = PATHNAME$(NAMEX, wszPath)
END FUNCTION
' ========================================================================================
