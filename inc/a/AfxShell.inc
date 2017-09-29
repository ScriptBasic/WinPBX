' ########################################################################################
' Microsoft Windows
' File: AfxShell.inc
' Contents: Windows wrapper functions.
' Copyright (c) 2011 José Roca
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%AFXSHELL_INC = 1

#INCLUDE ONCE "windows.inc"
#INCLUDE ONCE "shlobj.inc"
#INCLUDE ONCE "KnownFolders.inc"

' ========================================================================================
' Retrieves the path of an special folder.
' ========================================================================================
FUNCTION AfxGetSpecialFolderLocation (BYVAL nFolder AS LONG) AS WSTRING
   LOCAL pidl AS DWORD                     ' // Pointer to an item identifier list (PIDL)
   LOCAL wszPath AS WSTRINGZ * %MAX_PATH   ' // Folder's path
   IF SHGetSpecialFolderLocation(0, nFolder, pidl) = %S_OK THEN
      SHGetPathFromIDListW BYVAL pidl, wszPath
      CoTaskMemFree BYVAL pidl
      FUNCTION = wszPath
   END IF
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the Windows directory or SYSROOT. This corresponds to the %windir% or %SYSTEMROOT%
' environment variables. A typical path is C:\Windows.
' ========================================================================================
FUNCTION AfxGetWindowsFolder () AS WSTRING
   FUNCTION = AfxGetSpecialFolderLocation(%CSIDL_WINDOWS)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the file system directory that is used to store administrative tools for an
' individual user. The MMC will save customized consoles to this directory, and it will
' roam with the user.
' ========================================================================================
FUNCTION AfxGetAdminToolsFolder () AS WSTRING
   FUNCTION = AfxGetSpecialFolderLocation(%CSIDL_ADMINTOOLS)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the file system directory that corresponds to the user's nonlocalized Startup
' program group. This value is recognized in Windows Vista for backward compatibility, but
' the folder itself no longer exists.
' ========================================================================================
FUNCTION AfxGetAltStartupFolder () AS WSTRING
   FUNCTION = AfxGetSpecialFolderLocation(%CSIDL_ALTSTARTUP)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the file system directory that serves as a common repository for application-specific
' data. A typical path is C:\Documents and Settings\username\Application Data. This CSIDL
' is supported by the redistributable Shfolder.dll for systems that do not have the Microsoft
' Internet Explorer 4.0 integrated Shell installed.
' ========================================================================================
FUNCTION AfxGetCDBurningFolder () AS WSTRING
   FUNCTION = AfxGetSpecialFolderLocation(%CSIDL_CDBURN_AREA)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the file system directory that contains administrative tools for all users of
' the computer.
' ========================================================================================
FUNCTION AfxGetCommonAdminToolsFolder () AS WSTRING
   FUNCTION = AfxGetSpecialFolderLocation(%CSIDL_COMMON_ADMINTOOLS)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the file system directory that corresponds to the nonlocalized Startup program
' group for all users. This value is recognized in Windows Vista for backward compatibility,
' but the folder itself no longer exists.
' ========================================================================================
FUNCTION AfxGetCommonAltStartupFolder () AS WSTRING
   FUNCTION = AfxGetSpecialFolderLocation(%CSIDL_COMMON_ALTSTARTUP)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the file system directory that contains application data for all users. A typical
' path is C:\Documents and Settings\All Users\Application Data. This folder is used for
' application data that is not user specific. For example, an application can store a
' spell-check dictionary, a database of clip art, or a log file in the CSIDL_COMMON_APPDATA
' folder. This information will not roam and is available to anyone using the computer.
' ========================================================================================
FUNCTION AfxGetCommonAppDataFolder () AS WSTRING
   FUNCTION = AfxGetSpecialFolderLocation(%CSIDL_COMMON_APPDATA)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the file system directory that contains files and folders that appear on the
' desktop for all users. A typical path is C:\Documents and Settings\All Users\Desktop.
' ========================================================================================
FUNCTION AfxGetCommonDesktopFolder () AS WSTRING
   FUNCTION = AfxGetSpecialFolderLocation(%CSIDL_COMMON_DESKTOPDIRECTORY)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the file system directory that contains documents that are common to all users.
' A typical path is C:\Documents and Settings\All Users\Documents.
' ========================================================================================
FUNCTION AfxGetCommonDocumentsFolder () AS WSTRING
   FUNCTION = AfxGetSpecialFolderLocation(%CSIDL_COMMON_DOCUMENTS)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the system directory that serves as a common repository for favorite items
' common to all users.
' ========================================================================================
FUNCTION AfxGetCommonFavoritesFolder () AS WSTRING
   FUNCTION = AfxGetSpecialFolderLocation(%CSIDL_COMMON_FAVORITES)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the file system directory that serves as a repository for music files common to
' all users. A typical path is C:\Documents and Settings\All Users\Documents\My Music.
' ========================================================================================
FUNCTION AfxGetCommonMusicFolder () AS WSTRING
   FUNCTION = AfxGetSpecialFolderLocation(%CSIDL_COMMON_MUSIC)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the file system directory that serves as a repository for image files common to
' all users. A typical path is C:\Documents and Settings\All Users\Documents\My Pictures.
' ========================================================================================
FUNCTION AfxGetCommonPicturesFolder () AS WSTRING
   FUNCTION = AfxGetSpecialFolderLocation(%CSIDL_COMMON_PICTURES)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns a folder for components that are shared across applications. A typical path is
' C:\Program Files\Common. Valid only for Windows XP.
' ========================================================================================
FUNCTION AfxGetCommonProgramFilesFolder () AS WSTRING
   FUNCTION = AfxGetSpecialFolderLocation(%CSIDL_PROGRAM_FILES_COMMON)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the file system directory that contains the directories for the common program
' groups that appear on the Start menu for all users. A typical path is C:\Documents and
' Settings\All Users\Start Menu\Programs.
' ========================================================================================
FUNCTION AfxGetCommonProgramsFolder () AS WSTRING
   FUNCTION = AfxGetSpecialFolderLocation(%CSIDL_COMMON_PROGRAMS)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the file system directory that contains the programs and folders that appear on
' the Start menu for all users. A typical path is C:\Documents and Settings\All Users\Start Menu.
' ========================================================================================
FUNCTION AfxGetCommonStartMenuFolder () AS WSTRING
   FUNCTION = AfxGetSpecialFolderLocation(%CSIDL_COMMON_STARTMENU)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the file system directory that contains the programs that appear in the Startup
' folder for all users. A typical path is C:\Documents and Settings\All Users\Start Menu\Programs\Startup.
' ========================================================================================
FUNCTION AfxGetCommonStartupFolder () AS WSTRING
   FUNCTION = AfxGetSpecialFolderLocation(%CSIDL_COMMON_STARTUP)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the file system directory that contains the templates that are available to all
' users. A typical path is C:\Documents and Settings\All Users\Templates.
' ========================================================================================
FUNCTION AfxGetCommonTemplatesFolder () AS WSTRING
   FUNCTION = AfxGetSpecialFolderLocation(%CSIDL_COMMON_TEMPLATES)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the file system directory that serves as a repository for video files common to
' all users. A typical path is C:\Documents and Settings\All Users\Documents\My Videos.
' ========================================================================================
FUNCTION AfxGetCommonVideoFolder () AS WSTRING
   FUNCTION = AfxGetSpecialFolderLocation(%CSIDL_COMMON_VIDEO)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the file system directory that serves as a common repository for Internet cookies.
' A typical path is C:\Documents and Settings\username\Cookies.
' ========================================================================================
FUNCTION AfxGetCookiesFolder () AS WSTRING
   FUNCTION = AfxGetSpecialFolderLocation(%CSIDL_COOKIES)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the virtual folder that represents the Windows desktop, the root of the namespace.
' ========================================================================================
FUNCTION AfxGetDesktopFolder () AS WSTRING
   FUNCTION = AfxGetSpecialFolderLocation(%CSIDL_DESKTOP)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the virtual folder that represents the My Documents desktop item. This value is
' equivalent to CSIDL_PERSONAL.
' ========================================================================================
FUNCTION AfxGetDocumentsFolder () AS WSTRING
   FUNCTION = AfxGetSpecialFolderLocation(%CSIDL_MYDOCUMENTS)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the file system directory that serves as a common repository for the user's
' favorite items. A typical path is C:\Documents and Settings\username\Favorites.
' ========================================================================================
FUNCTION AfxGetFavoritesFolder () AS WSTRING
   FUNCTION = AfxGetSpecialFolderLocation(%CSIDL_FAVORITES)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the file system directory that serves as a common repository for the user's
' favorite items. A typical path is C:\Windows\Fonts.
' ========================================================================================
FUNCTION AfxGetFontsFolder () AS WSTRING
   FUNCTION = AfxGetSpecialFolderLocation(%CSIDL_FONTS)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the file system directory that serves as a common repository for Internet history items.
' ========================================================================================
FUNCTION AfxGetHistoryFolder () AS WSTRING
   FUNCTION = AfxGetSpecialFolderLocation(%CSIDL_HISTORY)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the system directory that serves as a common repository for temporary Internet
' files. A typical path is C:\Documents and Settings\username\Local Settings\Temporary Internet Files.
' ========================================================================================
FUNCTION AfxGetInternetCacheFolder () AS WSTRING
   FUNCTION = AfxGetSpecialFolderLocation(%CSIDL_INTERNET_CACHE)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the file system directory that serves as a data repository for local (nonroaming)
' applications. A typical path is C:\Documents and Settings\username\Local Settings\Application Data.
' ========================================================================================
FUNCTION AfxGetLocalAppDataFolder () AS WSTRING
   FUNCTION = AfxGetSpecialFolderLocation(%CSIDL_LOCAL_APPDATA)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the file system directory that serves as a common repository for music files.
' A typical path is C:\Documents and Settings\User\My Documents\My Music.
' ========================================================================================
FUNCTION AfxGetMusicFolder () AS WSTRING
   FUNCTION = AfxGetSpecialFolderLocation(%CSIDL_MYMUSIC)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the file system directory that contains the link objects that may exist in the
' My Network Places virtual folder. It is not the same as CSIDL_NETWORK, which represents
' the network namespace root. A typical path is C:\Documents and Settings\username\NetHood.
' ========================================================================================
FUNCTION AfxGetNetHoodFolder () AS WSTRING
   FUNCTION = AfxGetSpecialFolderLocation(%CSIDL_NETHOOD)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the file system directory that serves as a common repository for image files.
' A typical path is C:\Documents and Settings\username\My Documents\My Pictures.
' ========================================================================================
FUNCTION AfxGetPicturesFolder () AS WSTRING
   FUNCTION = AfxGetSpecialFolderLocation(%CSIDL_MYPICTURES)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the user's profile folder. A typical path is C:\Users\username. Applications
' should not create files or folders at this level; they should put their data under the
' locations referred to by CSIDL_APPDATA or CSIDL_LOCAL_APPDATA. However, if you are
' creating a new Known Folder the profile root referred to by CSIDL_PROFILE is appropriate.
' ========================================================================================
FUNCTION AfxGetProfileFolder () AS WSTRING
   FUNCTION = AfxGetSpecialFolderLocation(%CSIDL_PROFILE)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the Program Files folder. A typical path is C:\Program Files.
' ========================================================================================
FUNCTION AfxGetProgramFilesFolder () AS WSTRING
   FUNCTION = AfxGetSpecialFolderLocation(%CSIDL_PROGRAM_FILES)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns a file system directory that contains the user's program groups (which are
' themselves file system directories). A typical path is C:\Documents and Settings\username\
' Start Menu\Programs.
' ========================================================================================
FUNCTION AfxGetProgramsFolder () AS WSTRING
   FUNCTION = AfxGetSpecialFolderLocation(%CSIDL_PROGRAMS)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the file system directory that contains shortcuts to the user's most recently
' used documents. A typical path is C:\Documents and Settings\username\My Recent Documents.
' To create a shortcut in this folder, use SHAddToRecentDocs. In addition to creating the
' shortcut, this function updates the Shell's list of recent documents and adds the shortcut
' to the My Recent Documents submenu of the Start menu.
' ========================================================================================
FUNCTION AfxGetRecentUsedDocumentsFolder () AS WSTRING
   FUNCTION = AfxGetSpecialFolderLocation(%CSIDL_RECENT)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Windows Vista. The file system directory that contains resource data. A typical path is
' C:\Windows\Resources.
' ========================================================================================
FUNCTION AfxGetResourcesFolder () AS WSTRING
   FUNCTION = AfxGetSpecialFolderLocation(%CSIDL_RESOURCES)
END FUNCTION
' ========================================================================================

' ========================================================================================
' The file system directory that contains Send To menu items. A typical path is
' C:\Documents and Settings\username\SendTo.
' ========================================================================================
FUNCTION AfxGetSendToFolder () AS WSTRING
   FUNCTION = AfxGetSpecialFolderLocation(%CSIDL_SENDTO)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the file system directory that contains Start menu items. A typical path is
' C:\Documents and Settings\username\Start Menu.
' ========================================================================================
FUNCTION AfxGetStartMenuFolder () AS WSTRING
   FUNCTION = AfxGetSpecialFolderLocation(%CSIDL_STARTMENU)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the file system directory that corresponds to the user's Startup program group.
' The system starts these programs whenever any user logs on. A typical path is
' C:\Documents and Settings\username\Start Menu\Programs\Startup.
' ========================================================================================
FUNCTION AfxGetStartupFolder () AS WSTRING
   FUNCTION = AfxGetSpecialFolderLocation(%CSIDL_STARTUP)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the Windows System folder. A typical path is C:\Windows\System32.
' ========================================================================================
FUNCTION AfxGetSystemFolder () AS WSTRING
   FUNCTION = AfxGetSpecialFolderLocation(%CSIDL_SYSTEM)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the file system directory that serves as a common repository for document templates.
' A typical path is C:\Documents and Settings\username\Templates.
' ========================================================================================
FUNCTION AfxGetTemplatesFolder () AS WSTRING
   FUNCTION = AfxGetSpecialFolderLocation(%CSIDL_TEMPLATES)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the file system directory that serves as a common repository for video files.
' A typical path is C:\Documents and Settings\username\My Documents\My Videos.
' ========================================================================================
FUNCTION AfxGetVideoFolder () AS WSTRING
   FUNCTION = AfxGetSpecialFolderLocation(%CSIDL_MYVIDEO)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the CLSID (class identifier) of the specified folder.
' ========================================================================================
FUNCTION AfxGetFolderCLSID (BYVAL bstrPath AS WSTRING) AS WSTRING

   LOCAL hr AS LONG
   LOCAL pMalloc AS IMalloc
   LOCAL pshfDesktop AS IShellFolder
   LOCAL pidl AS ITEMIDLIST PTR
   LOCAL dwAttributes AS DWORD
   LOCAL pPersist AS IPersist
   LOCAL rclsid AS GUID

   hr = SHGetMalloc(pMalloc)
   IF SUCCEEDED(hr) THEN
      hr = SHGetDesktopFolder(pshfDesktop)
      IF SUCCEEDED(hr) THEN
         dwAttributes = %SFGAO_FOLDER
         hr = pshfDesktop.ParseDisplayName(%NULL, NOTHING, BYCOPY bstrPath, BYVAL %NULL, pidl, dwAttributes)
         IF SUCCEEDED(hr) THEN
            hr = pshfDesktop.BindToObject(pidl, NOTHING, $IID_IPersist, pPersist)
            IF SUCCEEDED(hr) THEN
               hr = pPersist.GetClassID(rclsid)
            END IF
            pMalloc.Free(pidl)
         END IF
         pshfDesktop = NOTHING
      END IF
      pMalloc = NOTHING
   END IF

   IF hr = %S_OK THEN FUNCTION = GUIDTXT$(rclsid)

END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the description string for a Shell link object.
' - wszLinkPath = The path of the link object.
' Example: ? AfxGetLinkDescription("C:\Users\Pepe\Desktop\Lynx.lnk")
' Note: According to MSDN, SLGP_UNCPRIORITY is unsupported.
' ========================================================================================
FUNCTION AfxGetLinkDescription (BYREF wszLinkPath AS WSTRINGZ) AS WSTRING

   ' // Create an instance of the IShellLink interface
   LOCAL pSlk AS IShellLinkW
   pSlk = NEWCOM CLSID $CLSID_ShellLink
   IF ISNOTHING (pSlk) THEN EXIT FUNCTION

   ' // The IShellLink Interface supports the IPersistFile
   ' // interface. Get an interface pointer to it.
   LOCAL ppf AS IPersistFile
   ppf = pSlk
   IF ISNOTHING(ppf) THEN EXIT FUNCTION

   ' // Load the file
   LOCAL hr AS LONG
   ppf.Load(wszLinkPath, %STGM_READ)
   IF SUCCEEDED(hr) THEN
      ' // Resolve the link by calling the Resolve method.
      ' // This enables us to find the file the link points to even if
      ' // it has been moved or renamed.
      pSlk.Resolve(0, %SLR_ANY_MATCH OR %SLR_NO_UI)
      ' // Get the path of the file the link points to.
      LOCAL wszPath AS WSTRINGZ * %MAX_PATH
      LOCAL wfd AS WIN32_FIND_DATAW
      hr = pSlk.GetPath(wszPath, %MAX_PATH, wfd, %SLGP_UNCPRIORITY)
      ' // Only get the description of the link if we successfully got the path
      IF SUCCEEDED(hr) THEN
         LOCAL wszDescription AS WSTRINGZ * %MAX_PATH
         hr = pSlk.GetDescription(wszDescription, %MAX_PATH)
         IF SUCCEEDED(hr) THEN FUNCTION = wszDescription
      END IF
   END IF

END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the command-line arguments associated with a Shell link object.
' - wszLinkPath = The path of the link object.
' Example: ? AfxGetLinkArguments("C:\Users\Pepe\Desktop\Lynx.lnk")
' ========================================================================================
FUNCTION AfxGetLinkArguments (BYREF wszLinkPath AS WSTRINGZ) AS WSTRING

   ' // Create an instance of the IShellLink interface
   LOCAL pSlk AS IShellLinkW
   pSlk = NEWCOM CLSID $CLSID_ShellLink
   IF ISNOTHING (pSlk) THEN EXIT FUNCTION

   ' // The IShellLink Interface supports the IPersistFile
   ' // interface. Get an interface pointer to it.
   LOCAL ppf AS IPersistFile
   ppf = pSlk
   IF ISNOTHING(ppf) THEN EXIT FUNCTION

   ' // Load the file
   LOCAL hr AS LONG
   ppf.Load(wszLinkPath, %STGM_READ)
   IF SUCCEEDED(hr) THEN
      ' // Resolve the link by calling the Resolve method.
      ' // This enables us to find the file the link points to even if
      ' // it has been moved or renamed.
      pSlk.Resolve(0, %SLR_ANY_MATCH OR %SLR_NO_UI)
      ' // Get the path of the file the link points to.
      LOCAL wszPath AS WSTRINGZ * %MAX_PATH
      LOCAL wfd AS WIN32_FIND_DATAW
      hr = pSlk.GetPath(wszPath, %MAX_PATH, wfd, %SLGP_UNCPRIORITY)
      ' // Only get the arguments of the link if we successfully got the path
      IF SUCCEEDED(hr) THEN
         LOCAL wszArguments AS WSTRINGZ * 1024
         hr = pSlk.GetArguments(wszArguments, 1024)
         IF SUCCEEDED(hr) THEN FUNCTION = wszArguments
      END IF
   END IF

END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the keyboard shortcut (hot key) for a Shell link object.
' - wszLinkPath = The path of the link object.
' Example: ? AfxGetLinkHotKey("C:\Users\Pepe\Desktop\Lynx.lnk")
' ========================================================================================
FUNCTION AfxGetLinkHotKey (BYREF wszLinkPath AS WSTRINGZ) AS WORD

   ' // Create an instance of the IShellLink interface
   LOCAL pSlk AS IShellLinkW
   pSlk = NEWCOM CLSID $CLSID_ShellLink
   IF ISNOTHING (pSlk) THEN EXIT FUNCTION

   ' // The IShellLink Interface supports the IPersistFile
   ' // interface. Get an interface pointer to it.
   LOCAL ppf AS IPersistFile
   ppf = pSlk
   IF ISNOTHING(ppf) THEN EXIT FUNCTION

   ' // Load the file
   LOCAL hr AS LONG
   ppf.Load(wszLinkPath, %STGM_READ)
   IF SUCCEEDED(hr) THEN
      ' // Resolve the link by calling the Resolve method.
      ' // This enables us to find the file the link points to even if
      ' // it has been moved or renamed.
      pSlk.Resolve(0, %SLR_ANY_MATCH OR %SLR_NO_UI)
      ' // Get the path of the file the link points to.
      LOCAL wszPath AS WSTRINGZ * %MAX_PATH
      LOCAL wfd AS WIN32_FIND_DATAW
      hr = pSlk.GetPath(wszPath, %MAX_PATH, wfd, %SLGP_UNCPRIORITY)
      ' // Only get the hot key of the link if we successfully got the path
      IF SUCCEEDED(hr) THEN
         LOCAL wHotKey AS WORD
         hr = pSlk.GetHotKey(wHotKey)
         IF SUCCEEDED(hr) THEN FUNCTION = wHotKey
      END IF
   END IF

END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the list of item identifiers for a Shell link object.
' - wszLinkPath = The path of the link object.
' Example: ? AfxGetLinkIDList("C:\Users\Pepe\Desktop\Lynx.lnk")
' ========================================================================================
FUNCTION AfxGetLinkIDList (BYREF wszLinkPath AS WSTRINGZ) AS DWORD

   ' // Create an instance of the IShellLink interface
   LOCAL pSlk AS IShellLinkW
   pSlk = NEWCOM CLSID $CLSID_ShellLink
   IF ISNOTHING (pSlk) THEN EXIT FUNCTION

   ' // The IShellLink Interface supports the IPersistFile
   ' // interface. Get an interface pointer to it.
   LOCAL ppf AS IPersistFile
   ppf = pSlk
   IF ISNOTHING(ppf) THEN EXIT FUNCTION

   ' // Load the file
   LOCAL hr AS LONG
   ppf.Load(wszLinkPath, %STGM_READ)
   IF SUCCEEDED(hr) THEN
      ' // Resolve the link by calling the Resolve method.
      ' // This enables us to find the file the link points to even if
      ' // it has been moved or renamed.
      pSlk.Resolve(0, %SLR_ANY_MATCH OR %SLR_NO_UI)
      ' // Get the path of the file the link points to.
      LOCAL wszPath AS WSTRINGZ * %MAX_PATH
      LOCAL wfd AS WIN32_FIND_DATAW
      hr = pSlk.GetPath(wszPath, %MAX_PATH, wfd, %SLGP_UNCPRIORITY)
      ' // Only get the ID list of the link if we successfully got the path
      IF SUCCEEDED(hr) THEN
         LOCAL dwIDList AS DWORD
         hr = pSlk.GetIDList(dwIDList)
         IF SUCCEEDED(hr) THEN FUNCTION = dwIDList
      END IF
   END IF

END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the location of the icon for a Shell link object.
' - wszLinkPath = The path of the link object.
' Example: ? AfxGetLinkIconLocation("C:\Users\Pepe\Desktop\Lynx.lnk")
' ========================================================================================
FUNCTION AfxGetLinkIconLocation (BYREF wszLinkPath AS WSTRINGZ) AS WSTRING

   ' // Create an instance of the IShellLink interface
   LOCAL pSlk AS IShellLinkW
   pSlk = NEWCOM CLSID $CLSID_ShellLink
   IF ISNOTHING (pSlk) THEN EXIT FUNCTION

   ' // The IShellLink Interface supports the IPersistFile
   ' // interface. Get an interface pointer to it.
   LOCAL ppf AS IPersistFile
   ppf = pSlk
   IF ISNOTHING(ppf) THEN EXIT FUNCTION

   ' // Load the file
   LOCAL hr AS LONG
   ppf.Load(wszLinkPath, %STGM_READ)
   IF SUCCEEDED(hr) THEN
      ' // Resolve the link by calling the Resolve method.
      ' // This enables us to find the file the link points to even if
      ' // it has been moved or renamed.
      pSlk.Resolve(0, %SLR_ANY_MATCH OR %SLR_NO_UI)
      ' // Get the path of the file the link points to.
      LOCAL wszPath AS WSTRINGZ * %MAX_PATH
      LOCAL wfd AS WIN32_FIND_DATAW
      hr = pSlk.GetPath(wszPath, %MAX_PATH, wfd, %SLGP_UNCPRIORITY)
      ' // Only get the icon location of the link if we successfully got the path
      IF SUCCEEDED(hr) THEN
         LOCAL piIcon AS LONG
         LOCAL wszIconLocation AS WSTRINGZ * %MAX_PATH
         hr = pSlk.GetIconLocation(wszIconLocation, %MAX_PATH, piIcon)
         IF SUCCEEDED(hr) THEN FUNCTION = wszIconLocation
      END IF
   END IF

END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the icon index for a Shell link object.
' - wszLinkPath = The path of the link object.
' Example: ? AfxGetLinkIconIndex("C:\Users\Pepe\Desktop\Lynx.lnk")
' ========================================================================================
FUNCTION AfxGetLinkIconIndex (BYREF wszLinkPath AS WSTRINGZ) AS LONG

   ' // Create an instance of the IShellLink interface
   LOCAL pSlk AS IShellLinkW
   pSlk = NEWCOM CLSID $CLSID_ShellLink
   IF ISNOTHING (pSlk) THEN EXIT FUNCTION

   ' // The IShellLink Interface supports the IPersistFile
   ' // interface. Get an interface pointer to it.
   LOCAL ppf AS IPersistFile
   ppf = pSlk
   IF ISNOTHING(ppf) THEN EXIT FUNCTION

   ' // Load the file
   LOCAL hr AS LONG
   ppf.Load(wszLinkPath, %STGM_READ)
   IF SUCCEEDED(hr) THEN
      ' // Resolve the link by calling the Resolve method.
      ' // This enables us to find the file the link points to even if
      ' // it has been moved or renamed.
      pSlk.Resolve(0, %SLR_ANY_MATCH OR %SLR_NO_UI)
      ' // Get the path of the file the link points to.
      LOCAL wszPath AS WSTRINGZ * %MAX_PATH
      LOCAL wfd AS WIN32_FIND_DATAW
      hr = pSlk.GetPath(wszPath, %MAX_PATH, wfd, %SLGP_UNCPRIORITY)
      ' // Only get the icon index of the link if we successfully got the path
      IF SUCCEEDED(hr) THEN
         LOCAL piIcon AS LONG
         LOCAL wszIconLocation AS WSTRINGZ * %MAX_PATH
         hr = pSlk.GetIconLocation(wszIconLocation, %MAX_PATH, piIcon)
         IF SUCCEEDED(hr) THEN FUNCTION = piIcon
      END IF
   END IF

END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the name of the working directory for a Shell link object.
' - wszLinkPath = The path of the link object.
' Example: ? AfxGetLinkWorkingDirectory("C:\Users\Pepe\Desktop\Lynx.lnk")
' ========================================================================================
FUNCTION AfxGetLinkWorkingDirectory (BYREF wszLinkPath AS WSTRINGZ) AS WSTRING

   ' // Create an instance of the IShellLink interface
   LOCAL pSlk AS IShellLinkW
   pSlk = NEWCOM CLSID $CLSID_ShellLink
   IF ISNOTHING (pSlk) THEN EXIT FUNCTION

   ' // The IShellLink Interface supports the IPersistFile
   ' // interface. Get an interface pointer to it.
   LOCAL ppf AS IPersistFile
   ppf = pSlk
   IF ISNOTHING(ppf) THEN EXIT FUNCTION

   ' // Load the file
   LOCAL hr AS LONG
   ppf.Load(wszLinkPath, %STGM_READ)
   IF SUCCEEDED(hr) THEN
      ' // Resolve the link by calling the Resolve method.
      ' // This enables us to find the file the link points to even if
      ' // it has been moved or renamed.
      pSlk.Resolve(0, %SLR_ANY_MATCH OR %SLR_NO_UI)
      ' // Get the path of the file the link points to.
      LOCAL wszPath AS WSTRINGZ * %MAX_PATH
      LOCAL wfd AS WIN32_FIND_DATAW
      hr = pSlk.GetPath(wszPath, %MAX_PATH, wfd, %SLGP_UNCPRIORITY)
      ' // Only get the working directory of the link if we successfully got the path
      IF SUCCEEDED(hr) THEN
         LOCAL wszWorkingDirectory AS WSTRINGZ * %MAX_PATH
         hr = pSlk.GetWorkingDirectory(wszWorkingDirectory, %MAX_PATH)
         IF SUCCEEDED(hr) THEN FUNCTION = wszWorkingDirectory
      END IF
   END IF

END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the path and file name of a Shell link object.
' - wszLinkPath = The path of the link object.
' Example: ? AfxGetLinkTargetPath("C:\Users\Pepe\Desktop\Lynx.lnk")
' ========================================================================================
FUNCTION AfxGetLinkTargetPath (BYREF wszLinkPath AS WSTRINGZ) AS WSTRING

   ' // Create an instance of the IShellLink interface
   LOCAL pSlk AS IShellLinkW
   pSlk = NEWCOM CLSID $CLSID_ShellLink
   IF ISNOTHING (pSlk) THEN EXIT FUNCTION

   ' // The IShellLink Interface supports the IPersistFile
   ' // interface. Get an interface pointer to it.
   LOCAL ppf AS IPersistFile
   ppf = pSlk
   IF ISNOTHING(ppf) THEN EXIT FUNCTION

   ' // Load the file
   LOCAL hr AS LONG
   ppf.Load(wszLinkPath, %STGM_READ)
   IF SUCCEEDED(hr) THEN
      ' // Resolve the link by calling the Resolve method.
      ' // This enables us to find the file the link points to even if
      ' // it has been moved or renamed.
      pSlk.Resolve(0, %SLR_ANY_MATCH OR %SLR_NO_UI)
      ' // Get the path of the file the link points to.
      LOCAL wszPath AS WSTRINGZ * %MAX_PATH
      LOCAL wfd AS WIN32_FIND_DATAW
      hr = pSlk.GetPath(wszPath, %MAX_PATH, wfd, %SLGP_UNCPRIORITY)
      IF SUCCEEDED(hr) THEN FUNCTION = wszPath
   END IF

END FUNCTION
' ========================================================================================

' ========================================================================================
' Gets the show command for a Shell link object.
' - wszLinkPath = The path of the link object.
' Example: ? AfxGetLinkHotKey("C:\Users\Pepe\Desktop\Lynx.lnk")
' ========================================================================================
FUNCTION AfxGetLinkShowCmd (BYREF wszLinkPath AS WSTRINGZ) AS LONG

   ' // Create an instance of the IShellLink interface
   LOCAL pSlk AS IShellLinkW
   pSlk = NEWCOM CLSID $CLSID_ShellLink
   IF ISNOTHING (pSlk) THEN EXIT FUNCTION

   ' // The IShellLink Interface supports the IPersistFile
   ' // interface. Get an interface pointer to it.
   LOCAL ppf AS IPersistFile
   ppf = pSlk
   IF ISNOTHING(ppf) THEN EXIT FUNCTION

   ' // Load the file
   LOCAL hr AS LONG
   ppf.Load(wszLinkPath, %STGM_READ)
   IF SUCCEEDED(hr) THEN
      ' // Resolve the link by calling the Resolve method.
      ' // This enables us to find the file the link points to even if
      ' // it has been moved or renamed.
      pSlk.Resolve(0, %SLR_ANY_MATCH OR %SLR_NO_UI)
      ' // Get the path of the file the link points to.
      LOCAL wszPath AS WSTRINGZ * %MAX_PATH
      LOCAL wfd AS WIN32_FIND_DATAW
      hr = pSlk.GetPath(wszPath, %MAX_PATH, wfd, %SLGP_SHORTPATH)
      ' // Only get the show command of the link if we successfully got the path
      IF SUCCEEDED(hr) THEN
         LOCAL piShowCmd AS LONG
         hr = pSlk.GetShowCmd(piShowCmd)
         IF SUCCEEDED(hr) THEN FUNCTION = piShowCmd
      END IF
   END IF

END FUNCTION
' ========================================================================================

' ========================================================================================
' Displays the standard file properties dialog.
' ========================================================================================
FUNCTION AfxShowFileProperties (BYVAL hwnd AS DWORD, BYREF wszFileName AS WSTRINGZ) AS LONG

   LOCAL SEI AS SHELLEXECUTEINFOW
   LOCAL wszVerb AS WSTRINGZ * %MAX_PATH
   LOCAL wszNull AS WSTRINGZ * 1
   LOCAL wszErrMsg AS WSTRINGZ * 260

   wszVerb          = "Properties"
   SEI.cbSize       = SIZEOF(SEI)
   SEI.fmask        = %SEE_MASK_INVOKEIDLIST
   SEI.hwnd         = hwnd
   SEI.lpVerb       = VARPTR(wszVerb)
   SEI.lpFile       = VARPTR(wszFileName)
   SEI.lpParameters = VARPTR(wszNull)
   SEI.lpDirectory  = VARPTR(wszNull)
   SEI.nShow        = 0
   SEI.hInstApp     = 0
   SEI.lpIDList     = 0
   ShellExecuteExW SEI
   IF SEI.hInstApp < 32 THEN FUNCTION = SEI.hInstApp

END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieves the path of an special folder. Windows Vista/Windows 7.
' ========================================================================================
FUNCTION AfxGetKnowFolder (BYREF rfid AS GUID, OPTIONAL BYVAL dwFlags AS DWORD, BYVAL hToken AS DWORD) AS WSTRING
   LOCAL pidl AS DWORD                     ' // Pointer to an item identifier list (PIDL)
   LOCAL wszPath AS WSTRINGZ * %MAX_PATH   ' // Folder's path
   IF SHGetKnownFolderIDList(rfid, dwFlags, hToken, pidl) = %S_OK THEN
      SHGetPathFromIDListW BYVAL pidl, wszPath
      CoTaskMemFree BYVAL pidl
      FUNCTION = wszPath
   END IF
END FUNCTION
' ========================================================================================

' ========================================================================================
' Displays a dialog box that enables the user to select a Shell folder.
' Paramaters:
' - hwnd       = The handle to the parent window of the dialog box. This value can be zero.
' - bstrTitle  = A string value that represents the title displayed inside the Browse dialog box.
' - Options    = Optional. A LONG value that contains the options for the method. This can be zero or a
'                combination of the values listed under the ulFlags member of the BROWSEINFO structure.
'                See: http://msdn.microsoft.com/en-us/library/windows/desktop/bb773205%28v=vs.85%29.aspx
' - RootFolder = Optional. The root folder to use in the dialog box. The user cannot browse
'                higher in the tree than this folder. If this value is not specified, the
'                root folder used in the dialog box is the desktop. This value can be a
'                string that specifies the path of the folder or one of the
'                ShellSpecialFolderConstants values.
'                See: http://msdn.microsoft.com/en-us/library/windows/desktop/bb774096%28v=vs.85%29.aspx
' Return Value:
'   The path of the selected folder.
' ========================================================================================
FUNCTION AfxShellBrowseForFolder (BYVAL hwnd AS DWORD, BYVAL bstrTitle AS WSTRING, OPTIONAL BYVAL Options AS LONG, OPTIONAL BYVAL RootFolder AS VARIANT) AS WSTRING
   LOCAL pShell AS IShellDispatch
   pShell = NEWCOM "Shell.Application"
   IF ISNOTHING(pShell) THEN EXIT FUNCTION
   LOCAL pFolder AS ShellFolder2
   pFolder = pShell.BrowseForFolder(hwnd, bstrTitle, Options, RootFolder)
   IF ISNOTHING(pFolder) THEN EXIT FUNCTION
   LOCAL pItem AS ShellFolderItem
   pItem = pFolder.Self
   IF ISNOTHING(pItem) THEN EXIT FUNCTION
   FUNCTION = pItem.Path
END FUNCTION
' ========================================================================================

' ========================================================================================
' Displays a dialog box that enables the user to select a folder.
' - bstrTitle   = A string value that represents the title displayed inside the Browse dialog box.
' - startFolder = The initial folder that the dialog will show.
' - dwFlags     = Optional. A LONG value that contains the options for the method. This can be a
'                 combination of the values listed under the ulFlags member of the BROWSEINFO structure.
'                 See: http://msdn.microsoft.com/en-us/library/windows/desktop/bb773205%28v=vs.85%29.aspx
'                 Default value = %BIF_RETURNONLYFSDIRS OR %BIF_DONTGOBELOWDOMAIN OR %BIF_USENEWUI OR %BIF_RETURNFSANCESTORS
' Note: To display the old style dialog, pass -1 in the dwFlags parameter.
' ========================================================================================
FUNCTION AfxBrowseForFolder (BYVAL hwnd AS DWORD, BYREF bstrTitle AS WSTRING, OPTIONAL BYVAL startFolder AS WSTRING, OPTIONAL BYVAL dwFlags AS DWORD) AS WSTRING

   LOCAL wszBuffer AS WSTRINGZ * %MAX_PATH
   LOCAL bi        AS BROWSEINFOW
   LOCAL pidl      AS DWORD

   IF dwFlags = 0 THEN dwFlags = %BIF_RETURNONLYFSDIRS OR %BIF_DONTGOBELOWDOMAIN OR %BIF_USENEWUI OR %BIF_RETURNFSANCESTORS
   IF BITSE(-1, dwFlags, 32) THEN dwFlags = %BIF_RETURNONLYFSDIRS OR %BIF_DONTGOBELOWDOMAIN OR %BIF_RETURNFSANCESTORS

   bi.hWndOwner    = hwnd
   bi.lpszTitle    = STRPTR(bstrTitle)
   bi.ulFlags      = dwFlags
   bi.lpfnCallback = CODEPTR(AfxBrowseForFolderProc)
   bi.lParam       = STRPTR(startFolder)
   pidl            = SHBrowseForFolderW(bi)

   IF pidl THEN
      SHGetPathFromIDListW(BYVAL pidl, wszBuffer)
      CoTaskMemFree BYVAL pidl
      FUNCTION = wszBuffer
   END IF

END FUNCTION

' // Browse for folder dialog procedure
FUNCTION AfxBrowseForFolderProc (BYVAL hwnd AS DWORD, BYVAL wMsg AS DWORD, BYVAL wParam AS DWORD, BYVAL lParam AS LONG) AS LONG

   LOCAL wszBuffer AS WSTRINGZ * %MAX_PATH

   IF wMsg = %BFFM_INITIALIZED THEN
      SendMessageW hwnd, %BFFM_SETSELECTIONW, %TRUE, lParam
   ELSEIF wMsg = %BFFM_SELCHANGED THEN
      SHGetPathFromIDListW(BYVAL wParam, wszBuffer)
      IF wParam = 0 OR _                                   ' // No id number
         wszBuffer = "" OR _                               ' // No name
         ISFALSE (GETATTR(wszBuffer) AND %SUBDIR) OR _     ' // Not a real subdir
         MID$(wszBuffer, 2, 1) <> ":" THEN                 ' // Not a local or mapped drive
            SendMessageW hwnd, %BFFM_ENABLEOK, %FALSE, %FALSE
      ELSEIF (GETATTR(wszBuffer) AND %SYSTEM) AND RIGHT$(wszBuffer, 2) <> ":\" THEN   ' // Exclude system folders, allow root directories
         SendMessageW hwnd, %BFFM_ENABLEOK, %FALSE, %FALSE
      END IF
   END IF

END FUNCTION
' ========================================================================================
