' ########################################################################################
' Microsoft Windows
' File: shlobj.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%SHLOBJ_INC = 1

' // Must go before shellapi.inc or a macro nesting overflow can occur.
#INCLUDE ONCE "shobjidl.inc"

#INCLUDE ONCE "shellapi.inc"
' // Removed the dependency of mshtml, that adds about 6Kb of bloat and only is
' // needed for the DoPrivacyDlg function.
'#INCLUDE ONCE "mshtmlc.inc"

'#IF NOT %DEF(%COMMCTRL_INC)
'#INCLUDE ONCE "commctrl.inc"  ' // for LPTBBUTTON
'#endif

'#ifndef INITGUID
#INCLUDE ONCE "shlguid.inc"
'#endif /* !INITGUID */

'#include <pshpack1.h>   /* Assume byte packing throughout */

#INCLUDE ONCE "shtypes.inc"
'#INCLUDE ONCE "shobjidl.inc"

'//===========================================================================
'//
'// Legacy exports that are no longer needed, call the COM API instead
'//
'//===========================================================================

'SHSTDAPI SHGetMalloc(__out IMalloc **ppMalloc); // CoGetMalloc(MEMCTX_TASK,ppMalloc)
'SHSTDAPI_(void *) SHAlloc(SIZE_T cb);           // CoTaskMemAlloc(cb)
'SHSTDAPI_(void)   SHFree(__in_opt void * pv);   // CoTaskMemFree(pv)

DECLARE FUNCTION SHGetMalloc IMPORT "SHELL32.DLL" ALIAS "SHGetMalloc" ( _
   BYREF ppMalloc AS IMalloc _                          ' __out LPMALLOC *ppMalloc
 ) AS LONG                                              ' HRESULT

DECLARE SUB SHAlloc IMPORT "SHELL32.DLL" ALIAS "SHAlloc" ( _
   BYVAL cb AS DWORD _                                  ' __in SIZE_T cb
 )                                                      ' void

DECLARE SUB SHFree IMPORT "SHELL32.DLL" ALIAS "SHFree" ( _
   BYVAL pv AS DWORD _                                  ' __in void *pv
 )                                                      ' void

'//===========================================================================
'//
'// IExtractIcon interface
'//
'//  This interface is used in two different places in the shell.
'//
'// Case-1: Icons of sub-folders for the scope-pane of the explorer.
'//
'//  It is used by the explorer to get the "icon location" of
'// sub-folders from each shell folders. When the user expands a folder
'// in the scope pane of the explorer, the explorer does following:
'//  (1) binds to the folder (gets IShellFolder),
'//  (2) enumerates its sub-folders by calling its EnumObjects member,
'//  (3) calls its GetUIObjectOf member to get IExtractIcon interface
'//     for each sub-folders.
'//  In this case, the explorer uses only IExtractIcon::GetIconLocation
'// member to get the location of the appropriate icon. An icon location
'// always consists of a file name (typically DLL or EXE) and either an icon
'// resource or an icon index.
'//
'//
'// Case-2: Extracting an icon image from a file
'//
'//  It is used by the shell when it extracts an icon image
'// from a file. When the shell is extracting an icon from a file,
'// it does following:
'//  (1) creates the icon extraction handler object (by getting its CLSID
'//     under the {ProgID}\shell\ExtractIconHanler key and calling
'//     CoCreateInstance requesting for IExtractIcon interface).
'//  (2) Calls IExtractIcon::GetIconLocation.
'//  (3) Then, calls IExtractIcon::ExtractIcon with the location/index pair.
'//  (4) If (3) returns NOERROR, it uses the returned icon.
'//  (5) Otherwise, it recursively calls this logic with new location
'//     assuming that the location string contains a fully qualified path name.
'//
'//  From extension programmer's point of view, there are only two cases
'// where they provide implementations of IExtractIcon:
'//  Case-1) providing explorer extensions (i.e., IShellFolder).
'//  Case-2) providing per-instance icons for some types of files.
'//
'// Because Case-1 is described above, we'll explain only Case-2 here.
'//
'// When the shell is about display an icon for a file, it does following:
'//  (1) Finds its ProgID and ClassID.
'//  (2) If the file has a ClassID, it gets the icon location string from the
'//    "DefaultIcon" key under it. The string indicates either per-class
'//    icon (e.g., "FOOBAR.DLL,2") or per-instance icon (e.g., "%1,1").
'//  (3) If a per-instance icon is specified, the shell creates an icon
'//    extraction handler object for it, and extracts the icon from it
'//    (which is described above).
'//
'//  It is important to note that the shell calls IExtractIcon::GetIconLocation
'// first, then calls IExtractIcon::Extract. Most application programs
'// that support per-instance icons will probably store an icon location
'// (DLL/EXE name and index/id) rather than an icon image in each file.
'// In those cases, a programmer needs to implement only the GetIconLocation
'// member and it Extract member simply returns S_FALSE. They need to
'// implement Extract member only if they decided to store the icon images
'// within files themselved or some other database (which is very rare).
'//
'//
'//
'// [Member functions]
'//
'//
'// IExtractIcon::GetIconLocation
'//
'//  This function returns an icon location.
'//
'//  Parameters:
'//   uFlags     [in]  -- Specifies if it is opened or not (GIL_OPENICON or 0)
'//   szIconFile [out] -- Specifies the string buffer buffer for a location name.
'//   cchMax     [in]  -- Specifies the size of szIconFile (almost always MAX_PATH)
'//   piIndex    [out] -- Sepcifies the address of UINT for the index.
'//   pwFlags    [out] -- Returns GIL_* flags
'//  Returns:
'//   NOERROR, if it returns a valid location; S_FALSE, if the shell use a
'//   default icon.
'//
'//  Notes: The location may or may not be a path to a file. The caller can
'//   not assume anything unless the subsequent Extract member call returns
'//   S_FALSE.
'//
'//   if the returned location is not a path to a file, GIL_NOTFILENAME should
'//   be set in the returned flags.
'//
'// IExtractIcon::Extract
'//
'//  This function extracts an icon image from a specified file.
'//
'//  Parameters:
'//   pszFile [in] -- Specifies the icon location (typically a path to a file).
'//   nIconIndex [in] -- Specifies the icon index.
'//   phiconLarge [out] -- Specifies the HICON variable for large icon.
'//   phiconSmall [out] -- Specifies the HICON variable for small icon.
'//   nIconSize [in] -- Specifies the size icon required (size of large icon)
'//                     LOWORD is the requested large icon size
'//                     HIWORD is the requested small icon size
'//  Returns:
'//   NOERROR, if it extracted the from the file.
'//   S_FALSE, if the caller should extract from the file specified in the
'//           location.
'//
'//===========================================================================

'// GetIconLocation() input flags

%GIL_OPENICON      = &H0001???      ' // allows containers to specify an "open" look
%GIL_FORSHELL      = &H0002???      ' // icon is to be displayed in a ShellFolder
%GIL_ASYNC         = &H0020???      ' // this is an async extract, return E_PENDING
%GIL_DEFAULTICON   = &H0040???      ' // get the default icon location if the final one takes too long to get
%GIL_FORSHORTCUT   = &H0080???      ' // the icon is for a shortcut to the object
%GIL_CHECKSHIELD   = &H0200???      ' // return GIL_SHIELD or GIL_FORCENOSHIELD, don't block if GIL_ASYNC is set

'// GetIconLocation() return flags

%GIL_SIMULATEDOC   = &H0001???      ' // simulate this document icon for this
%GIL_PERINSTANCE   = &H0002???      ' // icons from this class are per instance (each file has its own)
%GIL_PERCLASS      = &H0004???      ' // icons from this class per class (shared for all files of this type)
%GIL_NOTFILENAME   = &H0008???      ' // location is not a filename, must call ::ExtractIcon
%GIL_DONTCACHE     = &H0010???      ' // this icon should not be cached
%GIL_SHIELD        = &H0200???      ' // icon should be "stamped" with the LUA shield
%GIL_FORCENOSHIELD = &H0400???      ' // icon must *not* be "stamped" with the LUA shield

' ########################################################################################
' IExtractIcon interface
' IID = 000214EB-0000-0000-C000-000000000046
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IExtractIcon_INTERFACE_DEFINED)
    %IExtractIcon_INTERFACE_DEFINED = 1

INTERFACE IExtractIcon $IID_IExtractIcon

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetIconLocation ( _                           ' VTable offset = 12
     BYVAL uFlags AS DWORD _                            ' __in UINT uFlags
   , BYREF szIconFile AS ASCIIZ _                       ' __out LPSTR szIconFile
   , BYVAL cchMax AS DWORD _                            ' __in UINT cchMax
   , BYREF piIndex AS LONG _                            ' __out int * piIndex
   , BYREF pwFlags AS DWORD _                           ' __out UINT * pwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Extract ( _                                   ' VTable offset = 16
     BYREF pszFile AS ASCIIZ _                          ' __in LPCSTR pszFile
   , BYVAL nIconIndex AS DWORD _                        ' __in UINT nIconIndex
   , BYREF phiconLarge AS DWORD _                       ' __out HICON *phiconLarge
   , BYREF phiconSmall AS DWORD _                       ' __out HICON *phiconSmall
   , BYVAL nIconSize AS DWORD _                         ' __in UINT nIconSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IExtractIcon_INTERFACE_DEFINED__ */

' ########################################################################################
' IExtractIconW interface
' IID = 000214FA-0000-0000-C000-000000000046
' Inherited interface = IUnknown
' Unicode version of IExtractIcon.
' ########################################################################################

#IF NOT %DEF(%IExtractIconW_INTERFACE_DEFINED)
    %IExtractIconW_INTERFACE_DEFINED = 1

INTERFACE IExtractIconW $IID_IExtractIconW

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetIconLocation ( _                           ' VTable offset = 12
     BYVAL uFlags AS DWORD _                            ' __in UINT uFlags
   , BYREF szIconFile AS WSTRINGZ _                     ' __out LPWSTR szIconFile
   , BYVAL cchMax AS DWORD _                            ' __in UINT cchMax
   , BYREF piIndex AS LONG _                            ' __out int * piIndex
   , BYREF pwFlags AS DWORD _                           ' __out UINT * pwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Extract ( _                                   ' VTable offset = 16
     BYREF pszFile AS WSTRINGZ _                        ' __in LPCWSTR pszFile
   , BYVAL nIconIndex AS DWORD _                        ' __in UINT nIconIndex
   , BYREF phiconLarge AS DWORD _                       ' __out HICON *phiconLarge
   , BYREF phiconSmall AS DWORD _                       ' __out HICON *phiconSmall
   , BYVAL nIconSize AS DWORD _                         ' __in UINT nIconSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IExtractIconW_INTERFACE_DEFINED__ */

'//===========================================================================
'//
'// IShellIconOverlayIdentifier
'//
'// Used to identify a file as a member of the group of files that have this specific
'// icon overlay
'//
'// Users can create new IconOverlayIdentifiers and place them in the following registry
'// location together with the Icon overlay image and their priority.
'// HKEY_LOCAL_MACHINE "Software\\Microsoft\\Windows\\CurrentVersion\\ShellIconOverlayIdentifiers"
'//
'// The shell will enumerate through all IconOverlayIdentifiers at start, and prioritize
'// them according to internal rules, in case the internal rules don't apply, we use their
'// input priority
'//
'// IShellIconOverlayIdentifier:IsMemberOf(LPCWSTR pwszPath, DWORD dwAttrib)
'//      pwszPath        full path of the file
'//      dwAttrib        attribute of this file
'//
'//  returns:
'//      S_OK,    if the file is a member
'//      S_FALSE, if the file is not a member
'//      E_FAIL,  if the operation failed due to bad WIN32_FIND_DATA
'//
'// IShellIconOverlayIdentifier::GetOverlayInfo(LPWSTR pwszIconFile, int * pIndex, DWORD * dwFlags) PURE;
'//      pszIconFile    the path of the icon file
'//      pIndex         Depend on the flags, this could contain the IconIndex
'//      dwFlags        defined below
'//
'// IShellIconOverlayIdentifier::GetPriority(int * pIPriority) PURE;
'//      pIPriority     the priority of this Overlay Identifier
'//
'//===========================================================================

' ########################################################################################
' IShellIconOverlayIdentifier interface
' IID = 0C6C4200-C589-11D0-999A-00C04FD655E1
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IShellIconOverlayIdentifier_INTERFACE_DEFINED)
    %IShellIconOverlayIdentifier_INTERFACE_DEFINED = 1

INTERFACE IShellIconOverlayIdentifier $IID_IShellIconOverlayIdentifier

   INHERIT IUnknown

   ' =====================================================================================
   METHOD IsMemberOf ( _                                ' VTable offset = 12
     BYREF pwszPath AS WSTRINGZ _                       ' __in LPCWSTR pwszPath
   , BYVAL dwAttrib AS DWORD _                          ' __in DWORD dwAttrib
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetOverlayInfo ( _                            ' VTable offset = 16
     BYREF pwszIconFile AS WSTRINGZ _                   ' __in LPWSTR pwszIconFile
   , BYVAL cchMax AS LONG _                             ' __in int cchMax
   , BYREF pIndex AS LONG _                             ' __out int * pIndex
   , BYREF pdwFlags AS DWORD _                          ' __out DWORD * pdwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPriority ( _                               ' VTable offset = 20
     BYREF pIPriority AS LONG _                         ' __out int * pIPriority
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IShellIconOverlayIdentifier_INTERFACE_DEFINED__ */


%ISIOI_ICONFILE            = &H00000001???          ' // path is returned through pwszIconFile
%ISIOI_ICONINDEX           = &H00000002???          ' // icon index in pwszIconFile is returned through pIndex

'//===========================================================================
'//
'// IShellIconOverlayManager
'//
'// Used to return the icon overlay information including OverlayIndex, Image Index or Priority for an IShellFolder object.
'//
'// IShellIconOverlayManager:GetFileOverlayInfo(LPCWSTR pwszPath, DWORD dwAttrib, int * pIndex, DWORD dwflags)
'//      pwszPath        full path of the file
'//      dwAttrib        attribute of this file
'//      pIndex          pointer to the Icon Index in the system image list
'//      pOverlayIndex   pointer to the OverlayIndex in the system image list
'//      pPriority       pointer to the Priority of this overlay
'// IShellIconOverlayManager:GetReservedOverlayInfo(LPCWSTR pwszPath, DWORD dwAttrib, int * pIndex, DWORD dwflags, int iReservedID)
'//      iReservedID     reserved icon overlay id
'//  returns:
'//      S_OK,  if the index of an Overlay is found
'//      S_FALSE, if no Overlay exists for this file
'//      E_FAIL, if lpfd is bad
'// IShellIconOverlayManager:RefreshOverlayImages(DWORD dwFlags)
'//      This will refresh the overlay cache, depends on the dwFlags passed in
'//      It will reload the icons into the imagelist, when passed SIOM_ICONINDEX
'// IShellIconOverlayManager::LoadNonloadedOverlayIdentifiers()
'//      This method loads any registered overlay identifiers (handlers) that
'//      are not currently loaded.
'// IShellIconOverlayManager::OverlayIndexFromImageIndex(int iImage, int *piIndex, BOOL fAdd)
'//      iImage          existing shell image list index to look for
'//      piIndex         returned overlay index
'//      fAdd            Add image if not already present?
'//===========================================================================

' ########################################################################################
' IShellIconOverlayManager interface
' IID = F10B5E34-DD3B-42A7-AA7D-2F4EC54BB09B
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IShellIconOverlayManager_INTERFACE_DEFINED)
    %IShellIconOverlayManager_INTERFACE_DEFINED = 1

INTERFACE IShellIconOverlayManager $IID_IShellIconOverlayManager

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetFileOverlayInfo ( _                        ' VTable offset = 12
     BYREF pwszPath AS WSTRINGZ _                       ' __in LPCWSTR pwszPath
   , BYVAL dwAttrib AS DWORD _                          ' __in DWORD dwAttrib
   , BYREF pIndex AS LONG _                             ' __out int * pIndex
   , BYVAL dwflags AS DWORD _                           ' __in DWORD dwflags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetReservedOverlayInfo ( _                    ' VTable offset = 16
     BYREF pwszPath AS WSTRINGZ _                       ' __in LPCWSTR pwszPath
   , BYVAL dwAttrib AS DWORD _                          ' __in DWORD dwAttrib
   , BYREF pIndex AS LONG _                             ' __out int * pIndex
   , BYVAL dwflags AS DWORD _                           ' __in DWORD dwflags
   , BYVAL iReservedID AS LONG _                        ' __in int iReservedID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RefreshOverlayImages ( _                      ' VTable offset = 20
     BYVAL dwflags AS DWORD _                           ' __in DWORD dwflags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD LoadNonloadedOverlayIdentifiers ( _           ' VTable offset = 24
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OverlayIndexFromImageIndex ( _                ' VTable offset = 28
     BYVAL iImage AS LONG _                             ' __in int iImage
   , BYREF piIndex AS LONG _                            ' __out int * piIndex
   , BYVAL fAdd AS LONG _                               ' __in BOOL fAdd
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IShellIconOverlayManager_INTERFACE_DEFINED__ */


%SIOM_OVERLAYINDEX      = 1
%SIOM_ICONINDEX         = 2
'%SIOM_PRIORITY          = 3
%SIOM_RESERVED_SHARED   = 0
%SIOM_RESERVED_LINK     = 1
%SIOM_RESERVED_SLOWFILE = 2
%SIOM_RESERVED_DEFAULT  = 3


'//===========================================================================
'//
'// IShellIconOverlay
'//
'// Used to return the icon overlay index or its icon index for an IShellFolder object,
'// this is always implemented with IShellFolder
'//
'// IShellIconOverlay:GetOverlayIndex(LPCITEMIDLIST pidl, DWORD * pdwIndex)
'//      pidl            object to identify icon overlay for.
'//      pdwIndex        the Overlay Index in the system image list
'//
'// IShellIconOverlay:GetOverlayIconIndex(LPCITEMIDLIST pidl, DWORD * pdwIndex)
'//      pdwIconIndex    the Overlay Icon index in the system image list
'// This method is only used for those who are interested in seeing the real bits
'// of the Overlay Icon
'//
'//  returns:
'//      S_OK,  if the index of an Overlay is found
'//      S_FALSE, if no Overlay exists for this file
'//      E_FAIL, if pidl is bad
'//
'//===========================================================================

' ########################################################################################
' IShellIconOverlay interface
' IID = 7D688A70-C613-11D0-999B-00C04FD655E1
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IShellIconOverlay_INTERFACE_DEFINED)
    %IShellIconOverlay_INTERFACE_DEFINED = 1

INTERFACE IShellIconOverlay $IID_IShellIconOverlay

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetOverlayIndex ( _                           ' VTable offset = 12
     BYVAL pidl AS DWORD _                              ' __in LPCITEMIDLIST pidl
   , BYREF pIndex AS LONG _                             ' __inout int * pIndex
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetOverlayIconIndex ( _                       ' VTable offset = 16
     BYVAL pidl AS DWORD _                              ' __in LPCITEMIDLIST pidl
   , BYREF pIconIndex AS LONG _                         ' __inout int * pIconIndex
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IShellIconOverlay_INTERFACE_DEFINED__ */

%OI_DEFAULT = &H00000000???
%OI_ASYNC   = &HFFFFEEEE???

'//-------------------------------------------------------------------------
'//
'// SHGetIconOverlayIndex
'//
'// This function takes the path and icon/res id to the icon and convert it into
'// an overlay index in the system image list.
'// Note: there are totally only 15 slots for system image overlays, some of which
'// was reserved by the system, or taken by the overlayidentifiers, so it's possible
'// that this function would fail and return -1;
'//
'// To get the default overlays in the system, such as the share hand, link shortcut
'// and slow files, pass NULL as the file name, then the IDO_SHGIOI_* flags as the icon index
'//-------------------------------------------------------------------------

%IDO_SHGIOI_SHARE    = &H0FFFFFFF???
%IDO_SHGIOI_LINK     = &H0FFFFFFE???
%IDO_SHGIOI_SLOWFILE = &H0FFFFFFFD???
%IDO_SHGIOI_DEFAULT  = &H0FFFFFFFC???

DECLARE FUNCTION SHGetIconOverlayIndexA IMPORT "SHELL32.DLL" ALIAS "SHGetIconOverlayIndexA" ( _
   BYREF pszIconPath AS ASCIIZ _                        ' __in LPCSTR pszIconPath
 , BYVAL iIconIndex AS LONG _                           ' __in int iIconIndex
 ) AS LONG                                              ' int

DECLARE FUNCTION SHGetIconOverlayIndexW IMPORT "SHELL32.DLL" ALIAS "SHGetIconOverlayIndexW" ( _
   BYREF pszIconPath AS WSTRINGZ  _                     ' __in LPCWSTR pszIconPath
 , BYVAL iIconIndex AS LONG _                           ' __in int iIconIndex
 ) AS LONG                                              ' int

#IF %DEF(%UNICODE)
   MACRO SHGetIconOverlayIndex = SHGetIconOverlayIndexW
#ELSE
   MACRO SHGetIconOverlayIndex = SHGetIconOverlayIndexA
#ENDIF

'#if (_WIN32_IE >= 0x0400)

'// IShellLinkDataList::GetFlags()/SetFlags()
%SLDF_DEFAULT            = &H00000000???
%SLDF_HAS_ID_LIST        = &H00000001??? ' Shell link saved with ID list
%SLDF_HAS_LINK_INFO      = &H00000002??? ' Shell link saved with LinkInfo
%SLDF_HAS_NAME           = &H00000004???
%SLDF_HAS_RELPATH        = &H00000008???
%SLDF_HAS_WORKINGDIR     = &H00000010???
%SLDF_HAS_ARGS           = &H00000020???
%SLDF_HAS_ICONLOCATION   = &H00000040???
%SLDF_UNICODE            = &H00000080??? ' the strings are unicode
%SLDF_FORCE_NO_LINKINFO  = &H00000100??? ' don't create a LINKINFO (make a dumb link)
%SLDF_HAS_EXP_SZ         = &H00000200??? ' the link contains expandable env strings
%SLDF_RUN_IN_SEPARATE    = &H00000400??? ' Run the 16-bit target exe in a separate VDM/WOW
'#if (NTDDI_VERSION < NTDDI_VISTA)
%SLDF_HAS_LOGO3ID        = &H00000800??? ' this link is a special Logo3/MSICD link
'#endif
%SLDF_HAS_DARWINID       = &H00001000??? ' this link is a special Darwin link
%SLDF_RUNAS_USER         = &H00002000??? ' Run this link as a different user
%SLDF_HAS_EXP_ICON_SZ    = &H00004000??? ' contains expandable env string for icon path
'#if (NTDDI_VERSION >= NTDDI_WINXP)
%SLDF_NO_PIDL_ALIAS      = &H00008000??? ' don't ever resolve to a logical location
%SLDF_FORCE_UNCNAME      = &H00010000??? ' make GetPath() prefer the UNC name to the local name
%SLDF_RUN_WITH_SHIMLAYER = &H00020000??? ' Launch the target of this link w/ shim layer active
'#if (NTDDI_VERSION >= NTDDI_VISTA)
%SLDF_FORCE_NO_LINKTRACK                     = &H00040000???  ' // disable ObjectID tracking information
%SLDF_ENABLE_TARGET_METADATA                 = &H00080000???  ' // enable caching of target metadata into link
%SLDF_DISABLE_LINK_PATH_TRACKING             = &H00100000???  ' // disable EXP_SZ_LINK_SIG tracking
%SLDF_DISABLE_KNOWNFOLDER_RELATIVE_TRACKING  = &H00200000???  ' // disable KnownFolder tracking information (EXP_KNOWN_FOLDER)
'#if (NTDDI_VERSION >= NTDDI_WIN7)
#IF %WINVER >= &H601
%SLDF_NO_KF_ALIAS                            = &H00400000???  ' // disable Known Folder alias mapping when loading the IDList during deserialization
%SLDF_ALLOW_LINK_TO_LINK                     = &H00800000???  ' // allows this link to point to another shell link - must only be used when it is not possible to create cycles
%SLDF_UNALIAS_ON_SAVE                        = &H01000000???  ' // unalias the IDList when saving
%SLDF_PREFER_ENVIRONMENT_PATH                = &H02000000???  ' // the IDList is not persisted, instead it is recalculated from the path with environmental variables at load time
                                                              ' // we don't hit the disk to recalculate the IDList (the result is a simple IDList).  also Resolve does nothing
                                                              ' // if SetPath is called and the path does not have environmental variable in it, SLDF_PREFER_ENVIRONMENT_PATH is removed
%SLDF_KEEP_LOCAL_IDLIST_FOR_UNC_TARGET       = &H04000000???  ' // if target is a UNC location on a local machine, keep the local target in addition to the remote one
%SLDF_VALID                                  = &H07FFF7FF???  ' // bits that are valid for ::SetFlags()
#ELSE
%SLDF_VALID                                  = &H003FF7FF???  ' // bits that are valid for ::SetFlags()
#ENDIF
'#endif
'SLDF_RESERVED                               = (int) 0x80000000,   // Reserved-- so we can use the low word as an index value in the future
%SLDF_RESERVED           = &H80000000& ' Reserved-- so we can use the low word as an index value in the future
'#endif

'DEFINE_ENUM_FLAG_OPERATORS(SHELL_LINK_DATA_FLAGS);

' // Size = 8 bytes
TYPE DATABLOCK_HEADER BYTE
   cbSize      AS DWORD   ' DWORD // Size of this extra data block
   dwSignature AS DWORD   ' DWORD // signature of this extra data block
END TYPE

'#ifdef LF_FACESIZE
'typedef struct {
'#ifdef __cplusplus
'    DATABLOCK_HEADER dbh;
'#else
'    DATABLOCK_HEADER DUMMYSTRUCTNAME;
'#endif
'    WORD     wFillAttribute;         // fill attribute for console
'    WORD     wPopupFillAttribute;    // fill attribute for console popups
'    COORD    dwScreenBufferSize;     // screen buffer size for console
'    COORD    dwWindowSize;           // window size for console
'    COORD    dwWindowOrigin;         // window origin for console
'    DWORD    nFont;
'    DWORD    nInputBufferSize;
'    COORD    dwFontSize;
'    UINT     uFontFamily;
'    UINT     uFontWeight;
'    WCHAR    FaceName[LF_FACESIZE];
'    UINT     uCursorSize;
'    BOOL     bFullScreen;
'    BOOL     bQuickEdit;
'    BOOL     bInsertMode;
'    BOOL     bAutoPosition;
'    UINT     uHistoryBufferSize;
'    UINT     uNumberOfHistoryBuffers;
'    BOOL     bHistoryNoDup;
'    COLORREF ColorTable[ 16 ];
'} NT_CONSOLE_PROPS, *LPNT_CONSOLE_PROPS;
'#define NT_CONSOLE_PROPS_SIG 0xA0000002
'#endif  // LF_FACESIZE

UNION NT_CONSOLE_PROPS_DATABLOCK_HEADER_UNION
   dbh                     AS DATABLOCK_HEADER   ' DATABLOCK_HEADER
   ' // For compatibility with the PB declares
   DATABLOCK_HEADER
END UNION

' // Size = 204 bytes
TYPE NT_CONSOLE_PROPS BYTE
   NT_CONSOLE_PROPS_DATABLOCK_HEADER_UNION
   wFillAttribute          AS WORD               ' WORD    // fill attribute for console
   wPopupFillAttribute     AS WORD               ' WORD    // fill attribute for console popups
   dwScreenBufferSize      AS COORD              ' COORD   // screen buffer size for console
   dwWindowSize            AS COORD              ' COORD   // window size for console
   dwWindowOrigin          AS COORD              ' COORD   // window origin for console
   nFont                   AS DWORD              ' DWORD
   nInputBufferSize        AS DWORD              ' DWORD
   dwFontSize              AS COORD              ' COORD
   uFontFamily             AS DWORD              ' UINT
   uFontWeight             AS DWORD              ' UINT
   FaceName                AS WSTRINGZ * %LF_FACESIZE   ' WCHAR [LF_FACESIZE]
   uCursorSize             AS DWORD              ' UINT
   bFullScreen             AS LONG               ' BOOL
   bQuickEdit              AS LONG               ' BOOL
   bInsertMode             AS LONG               ' BOOL
   bAutoPosition           AS LONG               ' BOOL
   uHistoryBufferSize      AS DWORD              ' UINT
   uNumberOfHistoryBuffers AS DWORD              ' UINT
   bHistoryNoDup           AS LONG               ' BOOL
   ColorTable(15)          AS DWORD              ' COLORREF [ 16 ]
END TYPE

'// This is a FE Console property
'typedef struct {
'#ifdef __cplusplus
'    DATABLOCK_HEADER dbh;
'#else
'    DATABLOCK_HEADER DUMMYSTRUCTNAME;
'#endif
'    UINT     uCodePage;
'} NT_FE_CONSOLE_PROPS, *LPNT_FE_CONSOLE_PROPS;

UNION NT_FE_CONSOLE_PROPS_DATABLOCK_HEADER_UNION
   dbh       AS DATABLOCK_HEADER   ' DATABLOCK_HEADER
   ' // For compatibility with the PB declares
   DATABLOCK_HEADER
END UNION

' // Size = 12 bytes
TYPE NT_FE_CONSOLE_PROPS BYTE
   NT_FE_CONSOLE_PROPS_DATABLOCK_HEADER_UNION
   uCodePage AS DWORD              ' UINT
END TYPE

%NT_FE_CONSOLE_PROPS_SIG = &HA0000004???

'#if (_WIN32_IE >= 0x0500)
'typedef struct {
'#ifdef __cplusplus
'    DATABLOCK_HEADER dbh;
'#else
'    DATABLOCK_HEADER DUMMYSTRUCTNAME;
'#endif
'    CHAR        szDarwinID[MAX_PATH];  // ANSI darwin ID associated with link
'    WCHAR       szwDarwinID[MAX_PATH]; // UNICODE darwin ID associated with link
'} EXP_DARWIN_LINK, *LPEXP_DARWIN_LINK;
'#define EXP_DARWIN_ID_SIG       0xA0000006
'#define EXP_LOGO3_ID_SIG        0xA0000007
'#endif

UNION EXP_DARWIN_LINK_DATABLOCK_HEADER_UNION
   dbh         AS DATABLOCK_HEADER   ' DATABLOCK_HEADER
   ' // For compatibility with the PB declares
   DATABLOCK_HEADER
END UNION

' // Size = 788 bytes
TYPE EXP_DARWIN_LINK BYTE
   EXP_DARWIN_LINK_DATABLOCK_HEADER_UNION
   szDarwinID  AS ASCIIZ * %MAX_PATH
   szwDarwinID AS WSTRINGZ * %MAX_PATH
END TYPE

%EXP_DARWIN_ID_SIG       = &HA0000006???

%EXP_SPECIAL_FOLDER_SIG         = &HA0000005???  ' // LPEXP_SPECIAL_FOLDER

' // Size = 16 bytes
TYPE EXP_SPECIAL_FOLDER BYTE
   cbSize          AS DWORD   ' DWORD // Size of this extra data block
   dwSignature     AS DWORD   ' DWORD // signature of this extra data block
   idSpecialFolder AS DWORD   ' DWORD // special folder id this link points into
   cbOffset        AS DWORD   ' DWORD // ofset into pidl from SLDF_HAS_ID_LIST for child
END TYPE

' // Size = 788 bytes
TYPE EXP_SZ_LINK BYTE
   cbSize      AS DWORD                  ' DWORD // Size of this extra data block
   dwSignature AS DWORD                  ' DWORD // signature of this extra data block
   szTarget    AS ASCIIZ * %MAX_PATH     ' CHAR  [MAX_PATH] // ANSI target name w/EXP_SZ in it
   swzTarget   AS WSTRINGZ * %MAX_PATH   ' WCHAR [MAX_PATH] // UNICODE target name w/EXP_SZ in it
END TYPE

%EXP_SZ_LINK_SIG                = &HA0000001???  ' // LPEXP_SZ_LINK (target)
%EXP_SZ_ICON_SIG                = &HA0000007???  ' // LPEXP_SZ_LINK (icon)

'#if (NTDDI_VERSION >= NTDDI_VISTA)
' // Size = 9 bytes
TYPE EXP_PROPERTYSTORAGE BYTE
   cbSize               AS DWORD   ' DWORD // Size of this extra data block
   dwSignature          AS DWORD   ' DWORD // signature of this extra data block
   abPropertyStorage(0) AS BYTE    ' BYTE[1]
END TYPE
%EXP_PROPERTYSTORAGE_SIG     = &HA0000009???
'#endif
'#endif // (_WIN32_IE >= 0x0400)


#IF %DEF(%SHELLAPI_INC)    ' /* for LPSHELLEXECUTEINFO */

' ########################################################################################
' IShellExecuteHook interface
' IID = 000214F5-0000-0000-C000-000000000046
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IShellExecuteHook_INTERFACE_DEFINED)
    %IShellExecuteHook_INTERFACE_DEFINED = 1

INTERFACE IShellExecuteHook $IID_IShellExecuteHook

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Execute ( _                                   ' VTable offset = 12
     BYREF pei AS SHELLEXECUTEINFOA _                   ' __in LPSHELLEXECUTEINFOA pei
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IShellExecuteHook_INTERFACE_DEFINED__ */


' ########################################################################################
' IShellExecuteHookW interface
' IID = 000214FB-0000-0000-C000-000000000046
' Inherited interface = IUnknown
' Unicode version of IShellExecuteHook.
' ########################################################################################

#IF NOT %DEF(%IShellExecuteHookW_INTERFACE_DEFINED)
    %IShellExecuteHookW_INTERFACE_DEFINED = 1

INTERFACE IShellExecuteHookW $IID_IShellExecuteHookW

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Execute ( _                                   ' VTable offset = 12
     BYREF pei AS SHELLEXECUTEINFOW _                   ' __in LPSHELLEXECUTEINFOW pei
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IShellExecuteHookW_INTERFACE_DEFINED__ */


#ENDIF   ' #IF %DEF(%SHELLAPI_INC)


' ########################################################################################
' IURLSearchHook interface
' IID = AC60F6A0-0FD9-11D0-99CB-00C04FD64497
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IURLSearchHook_INTERFACE_DEFINED)
    %IURLSearchHook_INTERFACE_DEFINED = 1

INTERFACE IURLSearchHook $IID_IURLSearchHook

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Translate ( _                                 ' VTable offset = 12
     BYREF lpwszSearchURL AS WSTRINGZ _                 ' __in LPWSTR lpwszSearchURL
   , BYVAL cchBufferSize AS DWORD _                     ' __in DWORD cchBufferSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IURLSearchHook_INTERFACE_DEFINED__ */


' ########################################################################################
' ISearchContext interface
' IID = 09F656A2-41AF-480C-88F7-16CC0D164615
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ISearchContext_INTERFACE_DEFINED)
    %ISearchContext_INTERFACE_DEFINED = 1

INTERFACE ISearchContext $IID_ISearchContext

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetSearchUrl ( _                              ' VTable offset = 12
     BYREF pbstrSearchUrl AS WSTRING _                  ' __out BSTR * pbstrSearchUrl
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSearchText ( _                             ' VTable offset = 16
     BYREF pbstrSearchText AS WSTRING _                 ' __out BSTR * pbstrSearchText
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSearchStyle ( _                            ' VTable offset = 20
     BYREF pdwSearchStyle AS DWORD _                    ' __out DWORD * pdwSearchStyle
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISearchContext_INTERFACE_DEFINED__ */


' ########################################################################################
' IURLSearchHook2 interface
' IID = 5EE44DA4-6D32-46E3-86BC-07540DEDD0E0
' Inherited interface = IURLSearchHook
' ########################################################################################

#IF NOT %DEF(%IURLSearchHook2_INTERFACE_DEFINED)
    %IURLSearchHook2_INTERFACE_DEFINED = 1

INTERFACE IURLSearchHook2 $IID_IURLSearchHook2

   INHERIT IUnknown

   ' =====================================================================================
   ' IURLSearchHook Method
   ' =====================================================================================
   METHOD Translate ( _                                 ' VTable offset = 12
     BYREF lpwszSearchURL AS WSTRINGZ _                 ' __in LPWSTR lpwszSearchURL
   , BYVAL cchBufferSize AS DWORD _                     ' __in DWORD cchBufferSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IURLSearchHook2 Method
   ' =====================================================================================
   METHOD TranslateWithSearchContext ( _                ' VTable offset = 16
     BYREF lpwszSearchURL AS WSTRINGZ _                 ' __in LPWSTR lpwszSearchURL
   , BYVAL cchBufferSize AS DWORD _                     ' __in DWORD cchBufferSize
   , BYVAL pSearchContext AS ISearchContext _           ' __in ISearchContext * pSearchContext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IURLSearchHook2_INTERFACE_DEFINED__ */


' ########################################################################################
' INewShortcutHook interface
' IID = 000214E1-0000-0000-C000-000000000046
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%INewShortcutHook_INTERFACE_DEFINED)
    %INewShortcutHook_INTERFACE_DEFINED = 1

INTERFACE INewShortcutHook $IID_INewShortcutHook

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetReferent ( _                               ' VTable offset = 12
     BYREF pcszReferent AS ASCIIZ _                     ' __in LPCSTR pcszReferent
   , BYVAL hwnd AS DWORD _                              ' __in HWND hwnd
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetReferent ( _                               ' VTable offset = 16
     BYREF pcszReferent AS ASCIIZ _                     ' __inout LPCSTR pcszReferent
   , BYVAL cchReferent AS LONG _                        ' __in int cchReferent
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetFolder ( _                                 ' VTable offset = 20
     BYREF pcszFolder AS ASCIIZ _                       ' __in LPCSTR pcszFolder
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFolder ( _                                 ' VTable offset = 24
     BYREF pcszFolder AS ASCIIZ _                       ' __inout LPCSTR pcszFolder
   , BYVAL cchFolder AS LONG _                          ' __in int cchFolder
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetName ( _                                   ' VTable offset = 28
     BYREF pszName AS ASCIIZ _                          ' __inout LPCSTR pszName
   , BYVAL cchName AS LONG _                            ' __in int cchName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetExtension ( _                              ' VTable offset = 32
     BYREF pszExtension AS ASCIIZ _                     ' __inout LPCSTR pszExtension
   , BYVAL cchExtension AS LONG _                       ' __in int cchExtension
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __INewShortcutHook_INTERFACE_DEFINED__ */


' ########################################################################################
' INewShortcutHookW interface
' IID = 000214F7-0000-0000-C000-000000000046
' Inherited interface = IUnknown
' Unicode version of INewShortcutHook.
' ########################################################################################

#IF NOT %DEF(%INewShortcutHookW_INTERFACE_DEFINED)
    %INewShortcutHookW_INTERFACE_DEFINED = 1

INTERFACE INewShortcutHookW $IID_INewShortcutHookW

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetReferent ( _                               ' VTable offset = 12
     BYVAL pcszReferent AS DWORD _                      ' __in LPCSTR pcszReferent
   , BYVAL hwnd AS DWORD _                              ' __in HWND hwnd
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetReferent ( _                               ' VTable offset = 16
     BYVAL pcszReferent AS DWORD _                      ' __inout LPCSTR pcszReferent
   , BYVAL cchReferent AS LONG _                        ' __in int cchReferent
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetFolder ( _                                 ' VTable offset = 20
     BYVAL pcszFolder AS DWORD _                        ' __in LPCSTR pcszFolder
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFolder ( _                                 ' VTable offset = 24
     BYVAL pcszFolder AS DWORD _                        ' __inout LPCSTR pcszFolder
   , BYVAL cchFolder AS LONG _                          ' __in int cchFolder
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetName ( _                                   ' VTable offset = 28
     BYVAL pszName AS DWORD _                           ' __inout LPCSTR pszName
   , BYVAL cchName AS LONG _                            ' __in int cchName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetExtension ( _                              ' VTable offset = 32
     BYVAL pszExtension AS DWORD _                      ' __inout LPCSTR pszExtension
   , BYVAL cchExtension AS LONG _                       ' __in int cchExtension
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __INewShortcutHookW_INTERFACE_DEFINED__ */


'//===========================================================================
'//
'// ICopyHook Interface
'//
'//  The copy hook is called whenever file system directories are
'//  copy/moved/deleted/renamed via the shell.  It is also called by the shell
'//  on changes of status of printers.
'//
'//  Clients register their id under STRREG_SHEX_COPYHOOK for file system hooks
'//  and STRREG_SHEx_PRNCOPYHOOK for printer hooks.
'//  the CopyCallback is called prior to the action, so the hook has the chance
'//  to allow, deny or cancel the operation by returning the falues:
'//     IDYES  -  means allow the operation
'//     IDNO   -  means disallow the operation on this file, but continue with
'//              any other operations (eg. batch copy)
'//     IDCANCEL - means disallow the current operation and cancel any pending
'//              operations
'//
'//   arguments to the CopyCallback
'//      hwnd - window to use for any UI
'//      wFunc - what operation is being done
'//      wFlags - and flags (FOF_*) set in the initial call to the file operation
'//      pszSrcFile - name of the source file
'//      dwSrcAttribs - file attributes of the source file
'//      pszDestFile - name of the destiation file (for move and renames)
'//      dwDestAttribs - file attributes of the destination file
'//
'//
'//===========================================================================

' ########################################################################################
' ICopyHook interface
' IID = 000214EF-0000-0000-C000-000000000046
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ICopyHook_INTERFACE_DEFINED)
    %ICopyHook_INTERFACE_DEFINED = 1

INTERFACE ICopyHook $IID_ICopyHook

   INHERIT IUnknown

   ' =====================================================================================
   METHOD CopyCallback ( _                              ' VTable offset = 12
     BYVAL hwnd AS DWORD _                              ' __in HWND hwnd
   , BYVAL wFunc AS DWORD _                             ' __in UINT wFunc
   , BYVAL wFlags AS DWORD _                            ' __in UINT wFlags
   , BYREF pszSrcFile AS ASCIIZ _                       ' __in LPCSTR pszSrcFile
   , BYVAL dwSrcAttribs AS DWORD _                      ' __in DWORD dwSrcAttribs
   , BYREF pszDestFile AS ASCIIZ _                      ' __in LPCSTR pszDestFile
   , BYVAL dwDestAttribs AS DWORD _                     ' __in DWORD dwDestAttribs
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICopyHook_INTERFACE_DEFINED__ */


' ########################################################################################
' ICopyHookW interface
' IID = 000214FC-0000-0000-C000-000000000046
' Inherited interface = IUnknown
' Unicode version of ICopyHook.
' ########################################################################################

#IF NOT %DEF(%ICopyHookW_INTERFACE_DEFINED)
    %ICopyHookW_INTERFACE_DEFINED = 1

INTERFACE ICopyHookW $IID_ICopyHookW

   INHERIT IUnknown

   ' =====================================================================================
   METHOD CopyCallback ( _                              ' VTable offset = 12
     BYVAL hwnd AS DWORD _                              ' __in HWND hwnd
   , BYVAL wFunc AS DWORD _                             ' __in UINT wFunc
   , BYVAL wFlags AS DWORD _                            ' __in UINT wFlags
   , BYREF pszSrcFile AS WSTRINGZ _                     ' __in LPCWSTR pszSrcFile
   , BYVAL dwSrcAttribs AS DWORD _                      ' __in DWORD dwSrcAttribs
   , BYREF pszDestFile AS WSTRINGZ _                    ' __in LPCWSTR pszDestFile
   , BYVAL dwDestAttribs AS DWORD _                     ' __in DWORD dwDestAttribs
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICopyHookW_INTERFACE_DEFINED__ */


'// IFileViewer, IFileViewerSite not supported as of win2k
'#if (NTDDI_VERSION < NTDDI_WIN2K)

' ########################################################################################
' IFileViewerSite interface
' IID = 000214F3-0000-0000-C000-000000000046
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IFileViewerSite_INTERFACE_DEFINED)
    %IFileViewerSite_INTERFACE_DEFINED = 1

INTERFACE IFileViewerSite $IID_IFileViewerSite

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetPinnedWindow ( _                           ' VTable offset = 12
     BYVAL hwnd AS DWORD _                              ' __in HWND hwnd
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPinnedWindow ( _                           ' VTable offset = 16
     BYREF phwnd AS DWORD _                             ' __out HWND *phwnd
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IFileViewerSite_INTERFACE_DEFINED__ */


'//===========================================================================
'//
'// IFileViewer Interface
'//
'// Implemented in a FileViewer component object.  Used to tell a
'// FileViewer to PrintTo or to view, the latter happening though
'// ShowInitialize and Show.  The filename is always given to the
'// viewer through IPersistFile.
'//
'//===========================================================================

#IF NOT %DEF(%IFileViewer_INTERFACE_DEFINED)
    %IFileViewer_INTERFACE_DEFINED = 1

'#include <pshpack8.h>

' // Size = 556 bytes
TYPE FVSHOWINFO DWORD FILL
   ' // Stuff passed into viewer (in)
   cbSize       AS DWORD       ' DWORD // Size of structure for future expansion...
   hwndOwner    AS DWORD       ' HWND  // who is the owner window.
   iShow        AS LONG        ' int   // The show command
   ' // Passed in and updated  (in/Out)
   dwFlags      AS DWORD       ' DWORD // flags
   rect         AS RECT        ' RECT  // Where to create the window may have defaults
   punkRel      AS DWORD PTR   ' IUnknown *punkRel // Relese this interface when window is visible
   ' // Stuff that might be returned from viewer (out)
   strNewFile   AS WSTRINGZ * %MAX_PATH   ' OLECHAR [MAX_PATH] // New File to view.
END TYPE

'#include <poppack.h>        /* Return to byte packing */

'    // Define File View Show Info Flags.
%FVSIF_RECT      = &H00000001???      ' // The rect variable has valid data.
%FVSIF_PINNED    = &H00000002???      ' // We should Initialize pinned

%FVSIF_NEWFAILED = &H08000000???      ' // The new file passed back failed
                                        ' // to be viewed.

%FVSIF_NEWFILE   = &H80000000???      ' // A new file to view has been returned
%FVSIF_CANVIEWIT = &H40000000???      ' // The viewer can view it.


' ########################################################################################
' IFileViewer interface
' IID = 000214F0-0000-0000-C000-000000000046
' Inherited interface = IUnknown
' ########################################################################################

INTERFACE IFileViewer $IID_IFileViewer

   INHERIT IUnknown

   ' =====================================================================================
   METHOD ShowInitialize ( _                            ' VTable offset = 12
     BYVAL lpfsi AS IFileViewerSite _                   ' __in LPFILEVIEWERSITE lpfsi
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Show ( _                                      ' VTable offset = 16
     BYREF pvsi AS FVSHOWINFO _                         ' __in LPFVSHOWINFO pvsi
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD PrintTo ( _                                   ' VTable offset = 20
     BYREF pszDriver AS ASCIIZ _                        ' __in LPSTR pszDriver
   , BYVAL fSuppressUI AS LONG _                        ' __in BOOL fSuppressUI
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IFileViewer_INTERFACE_DEFINED__ */


' ########################################################################################
' IFileViewerW interface
' IID = 000214F8-0000-0000-C000-000000000046
' Inherited interface = IUnknown
' Unicode version of IFileViewer.
' ########################################################################################

#IF NOT %DEF(%IFileViewerW_INTERFACE_DEFINED)
    %IFileViewerW_INTERFACE_DEFINED = 1

INTERFACE IFileViewerW $IID_IFileViewerW

   INHERIT IUnknown

   ' =====================================================================================
   METHOD ShowInitialize ( _                            ' VTable offset = 12
     BYVAL lpfsi AS IFileViewerSite _                   ' __in LPFILEVIEWERSITE lpfsi
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Show ( _                                      ' VTable offset = 16
     BYREF pvsi AS FVSHOWINFO _                         ' __in LPFVSHOWINFO pvsi
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD PrintTo ( _                                   ' VTable offset = 20
     BYREF pszDriver AS WSTRINGZ _                      ' __in LPWSTR pszDriver
   , BYVAL fSuppressUI AS LONG _                        ' __in BOOL fSuppressUI
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IFileViewerW_INTERFACE_DEFINED__ */


'// IFileViewer, IFileViewerSite not supported as of win2k
'#endif // (NTDDI_VERSION < NTDDI_WIN2K)


'//--------------------------------------------------------------------------
'//
'// Command/menuitem IDs
'//
'//  The explorer dispatches WM_COMMAND messages based on the range of
'// command/menuitem IDs. All the IDs of menuitems that the view (right
'// pane) inserts must be in FCIDM_SHVIEWFIRST/LAST (otherwise, the explorer
'// won't dispatch them). The view should not deal with any menuitems
'// in FCIDM_BROWSERFIRST/LAST (otherwise, it won't work with the future
'// version of the shell).
'//
'//  FCIDM_SHVIEWFIRST/LAST      for the right pane (IShellView)
'//  FCIDM_BROWSERFIRST/LAST     for the explorer frame (IShellBrowser)
'//  FCIDM_GLOBAL/LAST           for the explorer's submenu IDs
'//
'//--------------------------------------------------------------------------

%FCIDM_SHVIEWFIRST           = &H0000??
%FCIDM_SHVIEWLAST            = &H7fff??
%FCIDM_BROWSERFIRST          = &Ha000??
%FCIDM_BROWSERLAST           = &Hbf00??
%FCIDM_GLOBALFIRST           = &H8000??
%FCIDM_GLOBALLAST            = &H9fff??

'//
'// Global submenu IDs and separator IDs
'//
%FCIDM_MENU_FILE             = %FCIDM_GLOBALFIRST + &H0000
%FCIDM_MENU_EDIT             = %FCIDM_GLOBALFIRST + &H0040
%FCIDM_MENU_VIEW             = %FCIDM_GLOBALFIRST + &H0080
%FCIDM_MENU_VIEW_SEP_OPTIONS = %FCIDM_GLOBALFIRST + &H0081
%FCIDM_MENU_TOOLS            = %FCIDM_GLOBALFIRST + &H00c0  ' // for Win9x compat
%FCIDM_MENU_TOOLS_SEP_GOTO   = %FCIDM_GLOBALFIRST + &H00c1  ' // for Win9x compat
%FCIDM_MENU_HELP             = %FCIDM_GLOBALFIRST + &H0100
%FCIDM_MENU_FIND             = %FCIDM_GLOBALFIRST + &H0140
%FCIDM_MENU_EXPLORE          = %FCIDM_GLOBALFIRST + &H0150
%FCIDM_MENU_FAVORITES        = %FCIDM_GLOBALFIRST + &H0170

'//--------------------------------------------------------------------------
'// control IDs known to the view
'//--------------------------------------------------------------------------

%FCIDM_TOOLBAR      = %FCIDM_BROWSERFIRST + 0
%FCIDM_STATUS       = %FCIDM_BROWSERFIRST + 1

'#if (_WIN32_IE >= 0x0400)
'//--------------------------------------------------------------------------
'//
'// The resource id of the offline cursor
'// This cursor is avaialble in shdocvw.dll
%IDC_OFFLINE_HAND        = 103
'#if (_WIN32_IE >= _WIN32_IE_IE70)
%IDC_PANTOOL_HAND_OPEN   = 104
%IDC_PANTOOL_HAND_CLOSED = 105
'#endif
'//
'//--------------------------------------------------------------------------
'#endif

'// SBCMDID_GETPANE - not necessarily in order
%PANE_NONE       = &HFFFFFFFF???   ' ((DWORD)-1)
%PANE_ZONE       = 1
%PANE_OFFLINE    = 2
%PANE_PRINTER    = 3
%PANE_SSL        = 4
%PANE_NAVIGATION = 5
%PANE_PROGRESS   = 6
'#if (_WIN32_IE >= _WIN32_IE_IE60)
%PANE_PRIVACY    = 7
'#endif

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION ILClone LIB "Shell32.dll" ALIAS "ILClone" _
    (pidl AS ITEMIDLIST) AS DWORD
#ELSE
DECLARE FUNCTION ILClone IMPORT "SHELL32.DLL" ALIAS "ILClone" ( _
   BYVAL pidl AS DWORD _                                ' __in LPCITEMIDLIST pidl
 ) AS DWORD                                             ' LPITEMIDLIST
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION ILCloneFirst LIB "Shell32.dll" ALIAS "ILCloneFirst" _
    (pidl AS ITEMIDLIST) AS DWORD
#ELSE
DECLARE FUNCTION ILCloneFirst IMPORT "SHELL32.DLL" ALIAS "ILCloneFirst" ( _
   BYVAL pidl AS DWORD _                                ' __in LPCITEMIDLIST pidl
 ) AS DWORD                                             ' LPITEMIDLIST
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION ILCombine LIB "Shell32.dll" ALIAS "ILCombine" _
    (pidl1 AS ITEMIDLIST, pidl2 AS ITEMIDLIST) AS DWORD
#ELSE
DECLARE FUNCTION ILCombine IMPORT "SHELL32.DLL" ALIAS "ILCombine" ( _
   BYVAL pidl1 AS DWORD _                               ' __in LPCITEMIDLIST pidl1
 , BYVAL pidl2 AS DWORD _                               ' __in LPCITEMIDLIST pidl2
 ) AS DWORD                                             ' LPITEMIDLIST
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE SUB ILFree LIB "Shell32.dll" ALIAS "ILFree" _
    (pidl AS ITEMIDLIST)
#ELSE
DECLARE SUB ILFree IMPORT "SHELL32.DLL" ALIAS "ILFree" ( _
   BYVAL pidl AS DWORD _                                ' __in LPITEMIDLIST pidl
 )                                                      ' void
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION ILGetNext LIB "Shell32.dll" ALIAS "ILGetNext" _
    (pidl AS ITEMIDLIST) AS DWORD
#ELSE
DECLARE FUNCTION ILGetNext IMPORT "SHELL32.DLL" ALIAS "ILGetNext" ( _
   BYVAL pidl AS DWORD _                                ' __in LPCITEMIDLIST pidl
 ) AS DWORD                                             ' LPITEMIDLIST
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION ILGetSize LIB "Shell32.dll" ALIAS "ILGetSize" _
    (pidl AS ITEMIDLIST) AS DWORD
#ELSE
DECLARE FUNCTION ILGetSize IMPORT "SHELL32.DLL" ALIAS "ILGetSize" ( _
   BYVAL pidl AS DWORD _                                ' __in LPCITEMIDLIST pidl
 ) AS DWORD                                             ' UINT
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION ILFindChild LIB "Shell32.dll" ALIAS "ILFindChild" _
    (pidlParent AS ITEMIDLIST, pidlChild AS ITEMIDLIST) AS DWORD
#ELSE
DECLARE FUNCTION ILFindChild IMPORT "SHELL32.DLL" ALIAS "ILFindChild" ( _
   BYVAL pidlParent AS DWORD _                          ' __in LPCITEMIDLIST pidlParent
 , BYVAL pidlChild AS DWORD _                           ' __in LPCITEMIDLIST pidlChild
 ) AS DWORD                                             ' LPITEMIDLIST
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION ILFindLastID LIB "Shell32.dll" ALIAS "ILFindLastID" _
    (pidl AS ITEMIDLIST) AS DWORD
#ELSE
DECLARE FUNCTION ILFindLastID IMPORT "SHELL32.DLL" ALIAS "ILFindLastID" ( _
   BYVAL pidl AS DWORD _                                ' __in LPCITEMIDLIST pidl
 ) AS DWORD                                             ' LPITEMIDLIST
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION ILRemoveLastID LIB "Shell32.dll" ALIAS "ILRemoveLastID" _
    (pidl AS ITEMIDLIST) AS LONG
#ELSE
DECLARE FUNCTION ILRemoveLastID IMPORT "SHELL32.DLL" ALIAS "ILRemoveLastID" ( _
   BYVAL pidl AS DWORD _                                ' __in LPITEMIDLIST pidl
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION ILIsEqual LIB "Shell32.dll" ALIAS "ILIsEqual" _
    (pidl1 AS ITEMIDLIST, pidl2 AS ITEMIDLIST) AS LONG
#ELSE
DECLARE FUNCTION ILIsEqual IMPORT "SHELL32.DLL" ALIAS "ILIsEqual" ( _
   BYVAL pidl1 AS DWORD _                               ' __in LPCITEMIDLIST pidl1
 , BYVAL pidl2 AS DWORD _                               ' __in LPCITEMIDLIST pidl2
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION ILIsParent LIB "Shell32.dll" ALIAS "ILIsParent" _
    (pidl1 AS ITEMIDLIST, pidl2 AS ITEMIDLIST, _
    BYVAL fImmediate AS LONG) AS LONG
#ELSE
DECLARE FUNCTION ILIsParent IMPORT "SHELL32.DLL" ALIAS "ILIsParent" ( _
   BYVAL pidlParent AS DWORD _                          ' __in LPCITEMIDLIST pidlParent
 , BYVAL pidlBelow AS DWORD _                           ' __in LPCITEMIDLIST pidlBelow
 , BYVAL fImmediate AS LONG _                           ' __in BOOL fImmediate
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION ILSaveToStream LIB "Shell32.dll" ALIAS "ILSaveToStream" _
    (pstm AS ANY, pidl AS ITEMIDLIST) AS LONG
#ELSE
DECLARE FUNCTION ILSaveToStream IMPORT "SHELL32.DLL" ALIAS "ILSaveToStream" ( _
   BYVAL pstm AS IStream _                              ' __in IStream * pstm
 , BYVAL pidl AS DWORD _                                ' __in LPCITEMIDLIST pidl
 ) AS LONG                                              ' HRESULT
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION ILLoadFromStream LIB "Shell32.dll" ALIAS "ILLoadFromStream" _
    (pstm AS ANY, pidl AS ITEMIDLIST) AS LONG
#ELSE
DECLARE FUNCTION ILLoadFromStream IMPORT "SHELL32.DLL" ALIAS "ILLoadFromStream" ( _
   BYVAL pstm AS IStream _                              ' __in IStream *pstm
 , BYREF pidl AS ANY _                                  ' __out LPITEMIDLIST *pidl
 ) AS LONG                                              ' HRESULT
#ENDIF

'#if (NTDDI_VERSION >= NTDDI_VISTA)

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION ILLoadFromStreamEx LIB "Shell32.dll" _
    ALIAS "ILLoadFromStreamEx" (pstm AS ANY, pidl AS ITEMIDLIST) AS LONG
#ELSE
DECLARE FUNCTION ILLoadFromStreamEx IMPORT "SHELL32.DLL" ALIAS "ILLoadFromStreamEx" ( _
   BYVAL pstm AS IStream _                              ' __in IStream *pstm
 , BYREF pidl AS ANY _                                  ' __out PIDLIST_RELATIVE *pidl
 ) AS LONG                                              ' HRESULT
#ENDIF

'#endif // NTDDI_VISTA

'#if (_WIN32_IE >= 0x0400)

DECLARE FUNCTION ILCreateFromPathA IMPORT "SHELL32.DLL" ALIAS "ILCreateFromPathA" ( _
   BYREF pszPath AS ASCIIZ _                            ' __in LPCSTR pszPath
 ) AS DWORD                                             ' LPITEMIDLIST

DECLARE FUNCTION ILCreateFromPathW IMPORT "SHELL32.DLL" ALIAS "ILCreateFromPathW" ( _
   BYREF pwszPath AS WSTRINGZ _                         ' __in LPCWSTR pwszPath
 ) AS DWORD                                             ' LPITEMIDLIST

'#ifdef NO_WRAPPERS_FOR_ILCREATEFROMPATH
'SHSTDAPI_(PIDLIST_ABSOLUTE)     ILCreateFromPath(LPCTSTR pszPath);
'DECLARE FUNCTION ILCreateFromPath IMPORT "SHELL32.DLL" ALIAS "ILCreateFromPath" ( _
'   BYREF pszPath AS ASCIIZ _                            ' __in LPCSTR pszPath
' ) AS DWORD                                             ' LPITEMIDLIST
'#else
'#ifdef UNICODE
'#define ILCreateFromPath        ILCreateFromPathW
'#else
'#define ILCreateFromPath        ILCreateFromPathA
'#endif  // !UNICODE
'#endif  // NO_WRAPPERS_FOR_ILCREATEFROMPATH

#IF %DEF(%UNICODE)
   MACRO ILCreateFromPath = ILCreateFromPathW
#ELSE
   MACRO ILCreateFromPath = ILCreateFromPathA
#ENDIF

'#endif  // (_WIN32_IE >= 0x0400)

DECLARE FUNCTION SHILCreateFromPath IMPORT "SHELL32.DLL" ALIAS "SHILCreateFromPath" ( _
   BYREF pszPath AS WSTRINGZ _                          ' __in LPCWSTR pszPath
 , BYREF ppidl AS ANY _                                 ' __out PIDLIST_ABSOLUTE *ppidl
 , BYREF rgflnOut AS DWORD _                            ' __inout DWORD *rgflnOut
 ) AS LONG                                              ' HRESULT

'#define VOID_OFFSET(pv, cb)     ((void*)(((BYTE*)(pv))+(cb)))

'#if defined(STRICT_TYPED_ITEMIDS) && defined(__cplusplus)

'} // extern "C"

'inline PIDLIST_ABSOLUTE ILCloneFull(__in PCUIDLIST_ABSOLUTE pidl) { return reinterpret_cast<PIDLIST_ABSOLUTE>(ILClone(pidl)); }
'inline PITEMID_CHILD    ILCloneChild(__in PCUITEMID_CHILD pidl)   { return ILCloneFirst(pidl); }

'inline HRESULT ILLoadFromStreamEx(__in IStream *pstm, __out PIDLIST_ABSOLUTE *ppidl) { return ILLoadFromStreamEx(pstm, reinterpret_cast<PIDLIST_RELATIVE*>(ppidl)); }
'inline HRESULT ILLoadFromStreamEx(__in IStream *pstm, __out PITEMID_CHILD *ppidl)    { return ILLoadFromStreamEx(pstm, reinterpret_cast<PIDLIST_RELATIVE*>(ppidl)); }

'inline PCUIDLIST_RELATIVE ILSkip(__in PCUIDLIST_RELATIVE pidl, UINT cb) { return reinterpret_cast<PCUIDLIST_RELATIVE>(VOID_OFFSET(pidl, cb)); }
'inline PUIDLIST_RELATIVE  ILSkip(__in PUIDLIST_RELATIVE  pidl, UINT cb) { return const_cast<PUIDLIST_RELATIVE>(ILSkip(const_cast<PCUIDLIST_RELATIVE>(pidl), cb)); }

'inline PCUIDLIST_RELATIVE ILNext(__in PCUIDLIST_RELATIVE pidl) { return ILSkip(pidl, pidl->mkid.cb); }
'inline PUIDLIST_RELATIVE  ILNext(__in PUIDLIST_RELATIVE  pidl) { return const_cast<PUIDLIST_RELATIVE>(ILNext(const_cast<PCUIDLIST_RELATIVE>(pidl))); }

'inline BOOL ILIsAligned(__in PCUIDLIST_RELATIVE pidl)       { return (((DWORD_PTR)(pidl) & (sizeof(void*) - 1)) == 0); }

'inline BOOL ILIsEmpty(__in_opt PCUIDLIST_RELATIVE pidl)     { return ((pidl == NULL) || (pidl->mkid.cb==0)); }

'// ILIsChild does not guarantee that pidl is non-null or non-empty.
'inline BOOL ILIsChild(__in_opt PCUIDLIST_RELATIVE pidl)         { return (ILIsEmpty(pidl) || ILIsEmpty(ILNext(pidl))); }

'extern "C" {

'#else // !defined(STRICT_TYPED_ITEMIDS) || !defined(__cplusplus)

'#define ILCloneFull             ILClone
'#define ILCloneChild            ILCloneFirst

'#define ILSkip(pidl, cb)        ((PUIDLIST_RELATIVE)VOID_OFFSET((pidl), (cb)))
'#define ILNext(pidl)            ILSkip(pidl, (pidl)->mkid.cb)

'#define ILIsAligned(pidl)       (((DWORD_PTR)(pidl) & (sizeof(void*) - 1)) == 0)

'#define ILIsEmpty(pidl)         ((pidl) == NULL || (pidl)->mkid.cb==0)

'// ILIsChild does not guarantee that pidl is non-null or non-empty.
'#define ILIsChild(pidl)         (ILIsEmpty(pidl) || ILIsEmpty(ILNext(pidl)))

'#endif // defined(STRICT_TYPED_ITEMIDS) && defined(__cplusplus)

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION ILAppendID LIB "Shell32.dll" ALIAS "ILAppendID" _
    (pidl AS ITEMIDLIST, pmkid AS SHITEMID, BYVAL fAppend AS LONG) _
    AS DWORD
#ELSE
DECLARE FUNCTION ILAppendID IMPORT "SHELL32.DLL" ALIAS "ILAppendID" ( _
   BYVAL pidl AS DWORD _                                ' __in LPITEMIDLIST pidl
 , BYVAL pmkid AS DWORD _                               ' __in LPSHITEMID pmkid
 , BYVAL fAppend AS LONG _                              ' __in BOOL fAppend
 ) AS DWORD                                             ' LPITEMIDLIST
#ENDIF

'#endif

'#if (NTDDI_VERSION >= NTDDI_VISTA)

'// SHGetPathFromIDListEx returns a win32 file system path for the item in the name space.
'//  and has a few special cases that include returning UNC printer names too!

' enum GPFIDL_FLAGS
%GPFIDL_DEFAULT    = &H0000???  ' // normal Win32 file name, servers and drive roots included
%GPFIDL_ALTNAME    = &H0001???  ' // short file name
%GPFIDL_UNCPRINTER = &H0002???  ' // include UNC printer names too (non file system item)
'typedef int GPFIDL_FLAGS;

' // PB declare.
'DECLARE FUNCTION SHGetPathFromIDListEx LIB "Shell32.dll" _
'    ALIAS "SHGetPathFromIDListEx" (BYVAL pidl AS ITEMIDLIST PTR, _
'    pszPath AS WSTRINGZ, BYVAL cchPath AS DWORD, BYVAL uOpts AS DWORD) _
'    AS LONG

DECLARE FUNCTION SHGetPathFromIDListEx IMPORT "SHELL32.DLL" ALIAS "SHGetPathFromIDListEx" ( _
   BYVAL pidl AS DWORD _                                ' __in PCIDLIST_ABSOLUTE pidl
 , BYREF pszPath AS WSTRINGZ _                          ' __out PWSTR pszPath
 , BYVAL cchPath AS DWORD _                             ' __in DWORD cchPath
 , BYVAL uOpts AS DWORD _                               ' __in GPFIDL_FLAGS uOpts
 ) AS LONG                                              ' BOOL

'#endif

' // SHGetPathFromIDListA is the old version of SHGetPathFromIDListEx that assumes the size of the buffer (MAX_PATH).
' // The pidl should point to a file system object.
#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SHGetPathFromIDListA LIB "Shell32.dll" _
    ALIAS "SHGetPathFromIDListA" (BYVAL pidl AS ITEMIDLIST PTR, _
    pszPath AS ASCIIZ) AS LONG
#ELSE
DECLARE FUNCTION SHGetPathFromIDListA IMPORT "SHELL32.DLL" ALIAS "SHGetPathFromIDListA" ( _
   BYVAL pidl AS DWORD _                                ' __in PCIDLIST_ABSOLUTE pidl
 , BYREF pszPath AS ASCIIZ _                            ' __out LPSTR pszPath
 ) AS LONG                                              ' BOOL
#ENDIF

' // SHGetPathFromIDListW is the old version of SHGetPathFromIDListEx that assumes the size of the buffer (MAX_PATH).
' // The pidl should point to a file system object.
#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SHGetPathFromIDListW LIB "Shell32.dll" _
    ALIAS "SHGetPathFromIDListW" (BYVAL pidl AS ITEMIDLIST PTR, _
    pszPath AS WSTRINGZ) AS LONG
#ELSE
DECLARE FUNCTION SHGetPathFromIDListW IMPORT "SHELL32.DLL" ALIAS "SHGetPathFromIDListW" ( _
   BYVAL pidl AS DWORD _                                ' __in PCIDLIST_ABSOLUTE pidl
 , BYREF pszPath AS WSTRINGZ _                          ' __out LPWSTR pszPath
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%UNICODE)
   MACRO SHGetPathFromIDList = SHGetPathFromIDListW
#ELSE
   MACRO SHGetPathFromIDList = SHGetPathFromIDListA
#ENDIF

DECLARE FUNCTION SHCreateDirectory IMPORT "SHELL32.DLL" ALIAS "SHCreateDirectory" ( _
   BYVAL hwnd AS DWORD _                                ' __in_opt HWND hwnd
 , BYREF pszPath AS WSTRINGZ _                          ' __in LPCWSTR pszPath
 ) AS LONG                                              ' int

DECLARE FUNCTION SHCreateDirectoryExA IMPORT "SHELL32.DLL" ALIAS "SHCreateDirectoryExA" ( _
   BYVAL hwnd AS DWORD _                                ' __in_opt HWND hwnd
 , BYREF pszPath AS ASCIIZ _                            ' __in LPCSTR pszPath
 , BYREF psa AS SECURITY_ATTRIBUTES _                   ' __in_opt SECURITY_ATTRIBUTES *psa
 ) AS LONG                                              ' int

DECLARE FUNCTION SHCreateDirectoryExW IMPORT "SHELL32.DLL" ALIAS "SHCreateDirectoryExW" ( _
   BYVAL hwnd AS DWORD _                                ' __in_opt HWND hwnd
 , BYREF pszPath AS WSTRINGZ _                          ' __in LPCWSTR pszPath
 , BYREF psa AS SECURITY_ATTRIBUTES _                   ' __in_opt SECURITY_ATTRIBUTES *psa
 ) AS LONG                                              ' int

#IF %DEF(%UNICODE)
   MACRO SHCreateDirectoryEx = SHCreateDirectoryExW
#ELSE
   MACRO SHCreateDirectoryEx = SHCreateDirectoryExA
#ENDIF

'#if (NTDDI_VERSION >= NTDDI_VISTA)
%OFASI_EDIT          = &H0001???
%OFASI_OPENDESKTOP   = &H0002???
'#endif

'#if (NTDDI_VERSION >= NTDDI_WINXP)

#IF %DEF(%USEPBDECL)
'DECLARE FUNCTION SHOpenFolderAndSelectItems LIB "Shell32.dll" _
'    ALIAS "SHOpenFolderAndSelectItems" _
'    (BYVAL pidlFolder AS ITEMIDLIST PTR, BYVAL cidl AS DWORD, _
'    BYVAL apidl AS ITEMIDLIST, BYVAL dwFlags AS DWORD) AS LONG
DECLARE FUNCTION SHOpenFolderAndSelectItems LIB "Shell32.dll" _
    ALIAS "SHOpenFolderAndSelectItems" _
    (BYVAL pidlFolder AS ITEMIDLIST PTR, BYVAL cidl AS DWORD, _
    BYVAL apidl AS ITEMIDLIST PTR, BYVAL dwFlags AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION SHOpenFolderAndSelectItems IMPORT "SHELL32.DLL" ALIAS "SHOpenFolderAndSelectItems" ( _
   BYVAL pidl AS DWORD _                                ' __in PCIDLIST_ABSOLUTE pidlFolder
 , BYVAL cidl AS DWORD _                                ' __in UINT cidl
 , BYVAL apidl AS DWORD _                               ' __in PCUITEMID_CHILD_ARRAY apidl
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 ) AS LONG                                              ' HRESULT
#ENDIF


'//  deprecated because of parameter ambiguity
'//  call SHCreateItemWithParent() or SHCreateItemFromIDList() instead
#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SHCreateShellItem LIB "Shell32.dll" _
    ALIAS "SHCreateShellItem" (BYVAL pidlParent AS ITEMIDLIST PTR, _
    psfParent AS ANY, BYVAL pidl AS ITEMIDLIST PTR, ppsi AS ANY) AS LONG
#ELSE
DECLARE FUNCTION SHCreateShellItem IMPORT "SHELL32.DLL" ALIAS "SHCreateShellItem" ( _
   BYVAL pidlParent AS DWORD _                          ' __in_opt PCIDLIST_ABSOLUTE pidlParent
 , BYVAL psfParent AS IShellFolder _                    ' __in_opt IShellFolder *psfParent
 , BYVAL pidl AS DWORD _                                ' __in PCUITEMID_CHILD pidl
 , BYREF ppsi AS IShellItem _                           ' __out IShellItem **ppsi
 ) AS LONG                                              ' HRESULT
#ENDIF

'#endif

'//-------------------------------------------------------------------------
'//
'// SHGetSpecialFolderLocation
'//
'//  Caller should use SHGetMalloc to obtain an allocator that can free the pidl
'//
'//
'//-------------------------------------------------------------------------
'//
'// registry entries for special paths are kept in :
'#define REGSTR_PATH_SPECIAL_FOLDERS    REGSTR_PATH_EXPLORER TEXT("\\Shell Folders")
$REGSTR_PATH_SPECIAL_FOLDERS   = "Software\Microsoft\Windows\CurrentVersion\Explorer\Shell Folders"

%CSIDL_DESKTOP                   = &H0000& ' <desktop>
%CSIDL_INTERNET                  = &H0001& ' Internet Explorer (icon on desktop)
%CSIDL_PROGRAMS                  = &H0002& ' Start Menu\Programs
%CSIDL_CONTROLS                  = &H0003& ' My Computer\Control Panel
%CSIDL_PRINTERS                  = &H0004& ' My Computer\Printers
%CSIDL_PERSONAL                  = &H0005& ' My Documents
%CSIDL_FAVORITES                 = &H0006& ' <user name>\Favorites
%CSIDL_STARTUP                   = &H0007& ' Start Menu\Programs\Startup
%CSIDL_RECENT                    = &H0008& ' <user name>\Recent
%CSIDL_SENDTO                    = &H0009& ' <user name>\SendTo
%CSIDL_BITBUCKET                 = &H000a& ' <desktop>\Recycle Bin
%CSIDL_STARTMENU                 = &H000b& ' <user name>\Start Menu
%CSIDL_MYDOCUMENTS               = %CSIDL_PERSONAL  ' //  Personal was just a silly name for My Documents
%CSIDL_MYMUSIC                   = &H000d& ' "My Music" folder
%CSIDL_MYVIDEO                   = &H000e& ' "My Videos" folder
%CSIDL_DESKTOPDIRECTORY          = &H0010& ' <user name>\Desktop
%CSIDL_DRIVES                    = &H0011& ' My Computer
%CSIDL_NETWORK                   = &H0012& ' Network Neighborhood
%CSIDL_NETHOOD                   = &H0013& ' <user name>\nethood
%CSIDL_FONTS                     = &H0014& ' windows\fonts
%CSIDL_TEMPLATES                 = &H0015&
%CSIDL_COMMON_STARTMENU          = &H0016& ' All Users\Start Menu
%CSIDL_COMMON_PROGRAMS           = &H0017& ' All Users\Programs
%CSIDL_COMMON_STARTUP            = &H0018& ' All Users\Startup
%CSIDL_COMMON_DESKTOPDIRECTORY   = &H0019& ' All Users\Desktop
%CSIDL_APPDATA                   = &H001a& ' <user name>\Application Data
%CSIDL_PRINTHOOD                 = &H001b& ' <user name>\PrintHood

#IF NOT %DEF(%CSIDL_LOCAL_APPDATA)
%CSIDL_LOCAL_APPDATA             = &H001c&   '// <user name>\Local Settings\Applicaiton Data (non roaming)
#ENDIF   ' // CSIDL_LOCAL_APPDATA

%CSIDL_ALTSTARTUP                = &H001d&        ' // non localized startup
%CSIDL_COMMON_ALTSTARTUP         = &H001e&        ' // non localized common startup
%CSIDL_COMMON_FAVORITES          = &H001f&

#IF NOT %DEF(%SHFOLDER_INC)
%CSIDL_INTERNET_CACHE            = &H0020&
%CSIDL_COOKIES                   = &H0021&
%CSIDL_HISTORY                   = &H0022&
%CSIDL_COMMON_APPDATA            = &H0023&        ' // All Users\Application Data
%CSIDL_WINDOWS                   = &H0024&        ' // GetWindowsDirectory()
%CSIDL_SYSTEM                    = &H0025&        ' // GetSystemDirectory()
%CSIDL_PROGRAM_FILES             = &H0026&        ' // C:\Program Files
%CSIDL_MYPICTURES                = &H0027&        ' // C:\Program Files\My Pictures
#ENDIF   ' // #IF NOT %DEF(%SHFOLDER_INC)

%CSIDL_PROFILE                   = &H0028&        ' // USERPROFILE
%CSIDL_SYSTEMX86                 = &H0029&        ' // x86 system directory on RISC
%CSIDL_PROGRAM_FILESX86          = &H002a&        ' // x86 C:\Program Files on RISC

#IF NOT %DEF(%SHFOLDER_INC)
%CSIDL_PROGRAM_FILES_COMMON      = &H002b&        ' // C:\Program Files\Common
#ENDIF   ' // #IF NOT %DEF(%SHFOLDER_INC)

%CSIDL_PROGRAM_FILES_COMMONX86   = &H002c&        ' // x86 Program Files\Common on RISC
%CSIDL_COMMON_TEMPLATES          = &H002d&        ' // All Users\Templates

#IF NOT %DEF(%SHFOLDER_INC)
%CSIDL_COMMON_DOCUMENTS          = &H002e&        ' // All Users\Documents
%CSIDL_COMMON_ADMINTOOLS         = &H002f&        ' // All Users\Start Menu\Programs\Administrative Tools
%CSIDL_ADMINTOOLS                = &H0030&        ' // <user name>\Start Menu\Programs\Administrative Tools
#ENDIF   ' // #IF NOT %DEF(%SHFOLDER_INC)

%CSIDL_CONNECTIONS               = &H0031&        ' // Network and Dial-up Connections
%CSIDL_COMMON_MUSIC              = &H0035&        ' // All Users\My Music
%CSIDL_COMMON_PICTURES           = &H0036&        ' // All Users\My Pictures
%CSIDL_COMMON_VIDEO              = &H0037&        ' // All Users\My Video
%CSIDL_RESOURCES                 = &H0038&        ' // Resource Direcotry

#IF NOT %DEF(%SHFOLDER_INC)
%CSIDL_RESOURCES_LOCALIZED       = &H0039&        ' // Localized Resource Direcotry
#ENDIF   ' // #IF NOT %DEF(%SHFOLDER_INC)

%CSIDL_COMMON_OEM_LINKS          = &H003a&        ' // Links to All Users OEM specific apps
%CSIDL_CDBURN_AREA               = &H003b&        ' // USERPROFILE\Local Settings\Application Data\Microsoft\CD Burning
' // unused                               = &H003c&
%CSIDL_COMPUTERSNEARME           = &H003d&        ' // Computers Near Me (computered from Workgroup membership)

#IF NOT %DEF(%SHFOLDER_INC)
%CSIDL_FLAG_CREATE               = &H8000&        ' // combine with CSIDL_ value to force folder creation in SHGetFolderPath()
#ENDIF   ' // #IF NOT %DEF(%SHFOLDER_INC)

%CSIDL_FLAG_DONT_VERIFY          = &H4000&        ' // combine with CSIDL_ value to return an unverified folder path
%CSIDL_FLAG_DONT_UNEXPAND        = &H2000&        ' // combine with CSIDL_ value to avoid unexpanding environment variables
'#if (NTDDI_VERSION >= NTDDI_WINXP)
%CSIDL_FLAG_NO_ALIAS             = &H1000&        ' // combine with CSIDL_ value to insure non-alias versions of the pidl
%CSIDL_FLAG_PER_USER_INIT        = &H0800&        ' // combine with CSIDL_ value to indicate per-user init (eg. upgrade)
'#endif  // NTDDI_WINXP
%CSIDL_FLAG_MASK                 = &HFF00&        ' // mask for all possible flag values


DECLARE FUNCTION SHGetSpecialFolderLocation IMPORT "SHELL32.DLL" ALIAS "SHGetSpecialFolderLocation" ( _
   BYVAL hwndOwner AS DWORD _                           ' __in HWND hwndOwner
 , BYVAL nFolder AS LONG _                              ' __in int nFolder
 , BYREF ppidl AS ANY _                                 ' __out LPITEMIDLIST *ppidl
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION SHCloneSpecialIDList IMPORT "SHELL32.DLL" ALIAS "SHCloneSpecialIDList" ( _
   BYVAL hwndOwner AS DWORD _                           ' __in HWND hwndOwner
 , BYVAL csidl AS LONG _                                ' __in int csidl
 , BYVAL fCreate AS LONG _                              ' __in BOOL fCreate
 ) AS DWORD                                             ' LPITEMIDLIST

DECLARE FUNCTION SHGetSpecialFolderPathA IMPORT "SHELL32.DLL" ALIAS "SHGetSpecialFolderPathA" ( _
   BYVAL hwndOwner AS DWORD _                           ' __in HWND hwndOwner
 , BYREF lpszPath AS ASCIIZ _                           ' __in LPSTR lpszPath
 , BYVAL nFolder AS LONG _                              ' __in int nFolder
 , BYVAL fCreate AS LONG _                              ' __in BOOL fCreate
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SHGetSpecialFolderPathW IMPORT "SHELL32.DLL" ALIAS "SHGetSpecialFolderPathW" ( _
   BYVAL hwndOwner AS DWORD _                           ' __in HWND hwndOwner
 , BYREF lpszPath AS WSTRINGZ _                         ' __in LPWSTR lpszPath
 , BYVAL nFolder AS LONG _                              ' __in int nFolder
 , BYVAL fCreate AS LONG _                              ' __in BOOL fCreate
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO SHGetSpecialFolderPath = SHGetSpecialFolderPathW
#ELSE
   MACRO SHGetSpecialFolderPath = SHGetSpecialFolderPathA
#ENDIF

'#if (NTDDI_VERSION >= NTDDI_WIN2K)
DECLARE SUB SHFlushSFCache IMPORT "SHELL32.DLL" ALIAS "SHFlushSFCache" ()

' SHGFP_TYPE enum
%SHGFP_TYPE_CURRENT  = 0  ' // current value for user, verify it exists
%SHGFP_TYPE_DEFAULT  = 1  ' // default value, may not exist

#IF NOT %DEF(%SHFOLDER_INC)

DECLARE FUNCTION SHGetFolderPathA IMPORT "SHELL32.DLL" ALIAS "SHGetFolderPathA" ( _
   BYVAL hwnd AS DWORD _                                ' __in HWND hwnd
 , BYVAL csidl AS LONG _                                ' __in int csidl
 , BYVAL hToken AS DWORD _                              ' __in_opt HANDLE hToken
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYREF pszPath AS ASCIIZ _                            ' __out LPSTR pszPath
 ) AS LONG                                              ' HRESULT

' // Deprecated. As of Windows Vista, this function is merely a wrapper for SHGetKnownFolderPath.
DECLARE FUNCTION SHGetFolderPathW IMPORT "SHELL32.DLL" ALIAS "SHGetFolderPathW" ( _
   BYVAL hwnd AS DWORD _                                ' __in HWND hwnd
 , BYVAL csidl AS LONG _                                ' __in int csidl
 , BYVAL hToken AS DWORD _                              ' __in_opt HANDLE hToken
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYREF pszPath AS WSTRINGZ _                          ' __out LPWSTR pszPath
 ) AS LONG                                              ' HRESULT

#IF %DEF(%UNICODE)
   MACRO SHGetFolderPath = SHGetFolderPathW
#ELSE
   MACRO SHGetFolderPath = SHGetFolderPathA
#ENDIF

#ENDIF   ' #IF NOT %DEF(%SHFOLDER_INC)

DECLARE FUNCTION SHGetFolderLocation IMPORT "SHELL32.DLL" ALIAS "SHGetFolderLocation" ( _
   BYVAL hwndOwner AS DWORD _                           ' __in HWND hwndOwner
 , BYVAL nFolder AS LONG _                              ' __in int nFolder
 , BYVAL hToken AS DWORD _                              ' __in_opt HANDLE hToken
 , BYVAL dwReserved AS DWORD _                          ' __in DWORD dwReserved
 , BYREF ppidl AS ANY _                                 ' __out LPITEMIDLIST *ppidl
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION SHSetFolderPathA IMPORT "SHELL32.DLL" ALIAS "SHSetFolderPathA" ( _
   BYVAL csidl AS LONG _                                ' __in int csidl
 , BYVAL hToken AS DWORD _                              ' __in_opt HANDLE hToken
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYREF pszPath AS ASCIIZ _                            ' __in LPCSTR pszPath
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION SHSetFolderPathW IMPORT "SHELL32.DLL" ALIAS "SHSetFolderPathW" ( _
   BYVAL csidl AS LONG _                                ' __in int csidl
 , BYVAL hToken AS DWORD _                              ' __in_opt HANDLE hToken
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYREF pszPath AS WSTRINGZ _                          ' __in LPCWSTR pszPath
 ) AS LONG                                              ' HRESULT

#IF %DEF(%UNICODE)
   MACRO SHSetFolderPath = SHSetFolderPathW
#ELSE
   MACRO SHSetFolderPath = SHSetFolderPathA
#ENDIF

'#endif  // NTDDI_WIN2K

DECLARE FUNCTION SHGetFolderPathAndSubDirA IMPORT "SHELL32.DLL" ALIAS "SHGetFolderPathAndSubDirA" ( _
   BYVAL hwnd AS DWORD _                                ' __in HWND hwnd
 , BYVAL csidl AS LONG _                                ' __in int csidl
 , BYVAL hToken AS DWORD _                              ' __in_opt HTOKEN hToken
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYREF pszSubDir AS ASCIIZ _                          ' __in_opt LPCSTR pszSubDir
 , BYREF pszPath AS ASCIIZ _                            ' __in LPSTR pszPath
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION SHGetFolderPathAndSubDirW IMPORT "SHELL32.DLL" ALIAS "SHGetFolderPathAndSubDirW" ( _
   BYVAL hwnd AS DWORD _                                ' __in HWND hwnd
 , BYVAL csidl AS LONG _                                ' __in int csidl
 , BYVAL hToken AS DWORD _                              ' __in_opt HTOKEN hToken
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYREF pszSubDir AS WSTRINGZ _                        ' __in_opt LPCWSTR pszSubDir
 , BYREF pszPath AS WSTRINGZ _                          ' __in LPWSTR pszPath
 ) AS LONG                                              ' HRESULT

#IF %DEF(%UNICODE)
   MACRO SHGetFolderPathAndSubDir = SHGetFolderPathAndSubDirW
#ELSE
   MACRO SHGetFolderPathAndSubDir = SHGetFolderPathAndSubDirA
#ENDIF

'#if (NTDDI_VERSION >= NTDDI_VISTA)

'// flags for Known Folder APIs

'typedef enum
'{
'    KF_FLAG_DEFAULT         = 0x00000000,

'    // Make sure that the folder already exists or create it and apply security specified in folder definition
'    // If folder can not be created then function will return failure and no folder path (IDList) will be returned
'    // If folder is located on the network the function may take long time to execute
'    KF_FLAG_CREATE          = 0x00008000,

'    // If this flag is specified then the folder path is returned and no verification is performed
'    // Use this flag is you want to get folder's path (IDList) and do not need to verify folder's existence
'    //
'    // If this flag is NOT specified then Known Folder API will try to verify that the folder exists
'    //     If folder does not exist or can not be accessed then function will return failure and no folder path (IDList) will be returned
'    //     If folder is located on the network the function may take long time to execute
'    KF_FLAG_DONT_VERIFY     = 0x00004000,

'    // Set folder path as is and do not try to substitute parts of the path with environments variables.
'    // If flag is not specified then Known Folder will try to replace parts of the path with some
'    // known environment variables (%USERPROFILE%, %APPDATA% etc.)
'    KF_FLAG_DONT_UNEXPAND   = 0x00002000,

'    // Get file system based IDList if available. If the flag is not specified the Known Folder API
'    // will try to return aliased IDList by default. Example for FOLDERID_Documents -
'    // Aliased - [desktop]\[user]\[Documents] - exact location is determined by shell namespace layout and might change
'    // Non aliased - [desktop]\[computer]\[disk_c]\[users]\[user]\[Documents] - location is determined by folder location in the file system
'    KF_FLAG_NO_ALIAS        = 0x00001000,

'    // Initialize the folder with desktop.ini settings
'    // If folder can not be initialized then function will return failure and no folder path will be returned
'    // If folder is located on the network the function may take long time to execute
'    KF_FLAG_INIT            = 0x00000800,

'    // Get the default path, will also verify folder existence unless KF_FLAG_DONT_VERIFY is also specified
'    KF_FLAG_DEFAULT_PATH    = 0x00000400,

'    // Get the not-parent-relative default path. Only valid with KF_FLAG_DEFAULT_PATH
'    KF_FLAG_NOT_PARENT_RELATIVE = 0x00000200,

'    // Build simple IDList
'    KF_FLAG_SIMPLE_IDLIST   = 0x00000100,

'    // only return the aliased IDLists, don't fallback to file system path
'    KF_FLAG_ALIAS_ONLY      = 0x80000000,
'} KNOWN_FOLDER_FLAG;

%KF_FLAG_DEFAULT             = &H00000000???
%KF_FLAG_CREATE              = &H00008000???
%KF_FLAG_DONT_VERIFY         = &H00004000???
%KF_FLAG_DONT_UNEXPAND       = &H00002000???
%KF_FLAG_NO_ALIAS            = &H00001000???
%KF_FLAG_INIT                = &H00000800???
%KF_FLAG_DEFAULT_PATH        = &H00000400???
%KF_FLAG_NOT_PARENT_RELATIVE = &H00000200???
%KF_FLAG_SIMPLE_IDLIST       = &H00000100???
%KF_FLAG_ALIAS_ONLY          = &H80000000???

'DEFINE_ENUM_FLAG_OPERATORS(KNOWN_FOLDER_FLAG);

DECLARE FUNCTION SHGetKnownFolderIDList IMPORT "SHELL32.DLL" ALIAS "SHGetKnownFolderIDList" ( _
   BYREF rfid AS GUID _                                 ' __in REFKNOWNFOLDERID rfid
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYVAL hToken AS DWORD _                              ' __in_opt HANDLE hToken
 , BYREF ppidl AS ANY _                                 ' __out PIDLIST_ABSOLUTE *ppidl
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION SHSetKnownFolderPath IMPORT "SHELL32.DLL" ALIAS "SHSetKnownFolderPath" ( _
   BYREF rfid AS GUID _                                 ' __in REFKNOWNFOLDERID rfid
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYVAL hToken AS DWORD _                              ' __in_opt HANDLE hToken
 , BYREF pszPath AS WSTRINGZ _                          ' __in PCWSTR pszPath
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION SHGetKnownFolderPath IMPORT "SHELL32.DLL" ALIAS "SHGetKnownFolderPath" ( _
   BYREF rfid AS GUID _                                 ' __in REFKNOWNFOLDERID rfid
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYVAL hToken AS DWORD _                              ' __in_opt HANDLE hToken
 , BYREF ppszPath AS DWORD _                            ' __out PWSTR *ppszPath // free *ppszPath with CoTaskMemFree
 ) AS LONG                                              ' HRESULT

'#endif  // NTDDI_VISTA

'#if (NTDDI_VERSION >= NTDDI_WIN7)
'// returns IShellItem or related interface
DECLARE FUNCTION SHGetKnownFolderItem IMPORT "SHELL32.DLL" ALIAS "SHGetKnownFolderItem" ( _
   BYREF rfid AS GUID _                                 ' __in REFKNOWNFOLDERID rfid
 , BYVAL flags AS LONG _                                ' __in KNOWN_FOLDER_FLAG flags
 , BYVAL hToken AS DWORD _                              ' __in_opt HANDLE hToken
 , BYREF riid AS GUID _                                 ' __in REFIID riid
 , BYREF ppv AS ANY _                                   ' __out void **ppv
 ) AS LONG                                              ' HRESULT
'#endif // NTDDI_WIN7

'#if (NTDDI_VERSION >= NTDDI_WIN2K)

%FCS_READ                    = &H00000001???
%FCS_FORCEWRITE              = &H00000002???
%FCS_WRITE                   = %FCS_READ OR %FCS_FORCEWRITE

%FCS_FLAG_DRAGDROP           = 2

'// Mask which values have been retreived or being set.
%FCSM_VIEWID                 = &H00000001???
%FCSM_WEBVIEWTEMPLATE        = &H00000002???
%FCSM_INFOTIP                = &H00000004???
%FCSM_CLSID                  = &H00000008???
%FCSM_ICONFILE               = &H00000010???
%FCSM_LOGO                   = &H00000020???
%FCSM_FLAGS                  = &H00000040???

'#if (NTDDI_VERSION >= NTDDI_VISTA)
'#include <pshpack8.h>

'// Used by SHGetSetFolderCustomSettingsW
' // Size = 60 bytes
TYPE SHFOLDERCUSTOMSETTINGS DWORD FILL
   dwSize                    AS DWORD          ' DWORD
   dwMask                    AS DWORD          ' DWORD        // IN/OUT   Which Attributes to Get/Set
   pvid                      AS DWORD          ' SHELLVIEWID* // OUT - if dwReadWrite is FCS_READ, IN - otherwise
   ' // The folder's WebView template path
   pszWebViewTemplate        AS WSTRINGZ PTR   ' LPWSTR       // OUT - if dwReadWrite is FCS_READ, IN - otherwise
   cchWebViewTemplate        AS DWORD          ' DWORD        // IN - Specifies the size of the buffer pointed to by pszWebViewTemplate
                                               '              // Ignored if dwReadWrite is FCS_READ
   pszWebViewTemplateVersion AS WSTRINGZ PTR   ' LPWSTR       // currently IN only
   ' // Infotip for the folder
   pszInfoTip                AS WSTRINGZ PTR   ' LPWSTR       // OUT - if dwReadWrite is FCS_READ, IN - otherwise
   cchInfoTip                AS DWORD          ' DWORD        // IN - Specifies the size of the buffer pointed to by pszInfoTip
                                               '              // Ignored if dwReadWrite is FCS_READ
   ' // CLSID that points to more info in the registry
   pclsid                    AS GUID   PTR     ' CLSID*       // OUT - if dwReadWrite is FCS_READ, IN - otherwise
   ' // Other flags for the folder. Takes FCS_FLAG_* values
   dwFlags                   AS DWORD          ' DWORD        // OUT - if dwReadWrite is FCS_READ, IN - otherwise
   pszIconFile               AS WSTRINGZ PTR   ' LPWSTR       // OUT - if dwReadWrite is FCS_READ, IN - otherwise
   cchIconFile               AS DWORD          ' DWORD        // IN - Specifies the size of the buffer pointed to by pszIconFile
                                               '              // Ignored if dwReadWrite is FCS_READ
   iIconIndex                AS LONG           ' int          // OUT - if dwReadWrite is FCS_READ, IN - otherwise
   pszLogo                   AS WSTRINGZ PTR   ' LPWSTR       // OUT - if dwReadWrite is FCS_READ, IN - otherwise
   cchLogo                   AS DWORD          ' DWORD        // IN - Specifies the size of the buffer pointed to by pszIconFile
                                               '              // Ignored if dwReadWrite is FCS_READ
END TYPE

'#include <poppack.h>        /* Return to byte packing */

'// Gets/Sets the Folder Custom Settings for pszPath based on dwReadWrite. dwReadWrite can be FCS_READ/FCS_WRITE/FCS_FORCEWRITE
DECLARE FUNCTION SHGetSetFolderCustomSettings IMPORT "SHELL32.DLL" ALIAS "SHGetSetFolderCustomSettings" ( _
   BYREF pfcs AS SHFOLDERCUSTOMSETTINGS _               ' __in LPSHFOLDERCUSTOMSETTINGS pfcs
 , BYREF pszPath AS WSTRINGZ _                          ' __in LPCWSTR pszPath
 , BYVAL dwReadWrite AS DWORD _                         ' __in DWORD dwReadWrite
 ) AS LONG                                              ' HRESULT

'#endif //NTDDI_VISTA
'#endif  // NTDDI_WIN2K

'//-------------------------------------------------------------------------
'//
'// SHBrowseForFolder API
'//
'//
'//-------------------------------------------------------------------------

'typedef int (CALLBACK* BFFCALLBACK)(HWND hwnd, UINT uMsg, LPARAM lParam, LPARAM lpData);

'#include <pshpack8.h>

UNION BROWSEINFO_CALLBACK
   lpfnCallback   AS DWORD            ' BFFCALLBACK // Old name
   lpfn           AS DWORD            ' BFFCALLBACK // New name
END UNION

' // Size = 32 bytes
TYPE BROWSEINFOA DWORD FILL
   hWndOwner      AS DWORD            ' HWND
   pIDLRoot       AS ITEMIDLIST PTR   ' LPCITEMIDLIST
   pszDisplayName AS ASCIIZ PTR       ' LPSTR         // Return display name of item selected.
   lpszTitle      AS ASCIIZ PTR       ' LPCSTR        // text to go in the banner over the tree.
   ulFlags        AS DWORD            ' UINT          // Flags that control the return stuff
   BROWSEINFO_CALLBACK
   lParam         AS LONG             ' LPARAM        // extra info that's passed back in callbacks
   iImage         AS LONG             ' int           // output var: where to return the Image index.
END TYPE

' // Size = 32 bytes
TYPE BROWSEINFOW DWORD FILL
   hWndOwner      AS DWORD            ' HWND
   pIDLRoot       AS ITEMIDLIST PTR   ' LPCITEMIDLIST
   pszDisplayName AS WSTRINGZ PTR     ' LPWSTR        // Return display name of item selected.
   lpszTitle      AS WSTRINGZ PTR     ' LPCWSTR       // text to go in the banner over the tree.
   ulFlags        AS DWORD            ' UINT          // Flags that control the return stuff
   BROWSEINFO_CALLBACK
   lParam         AS LONG             ' LPARAM        // extra info that's passed back in callbacks
   iImage         AS LONG             ' int           // output var: where to return the Image index.
END TYPE

MACRO BROWSEINFO = BROWSEINFOA

'#include <poppack.h>        /* Return to byte packing */

' // Note: The remed equates are predefined in the compiler.

'// Browsing for directory.
'%BIF_RETURNONLYFSDIRS    = &H00000001???   ' // For finding a folder to start document searching
'%BIF_DONTGOBELOWDOMAIN   = &H00000002???   ' // For starting the Find Computer
%BIF_STATUSTEXT          = &H00000004???   ' // Top of the dialog has 2 lines of text for BROWSEINFO.lpszTitle and one line if
                                           ' // this flag is set.  Passing the message BFFM_SETSTATUSTEXTA to the hwnd can set the
                                           ' // rest of the text.  This is not used with BIF_USENEWUI and BROWSEINFO.lpszTitle gets
                                           ' // all three lines of text.
'%BIF_RETURNFSANCESTORS   = &H00000008???
'%BIF_EDITBOX             = &H00000010???   ' // Add an editbox to the dialog
'%BIF_VALIDATE            = &H00000020???   ' // insist on valid result (or CANCEL)

'%BIF_NEWDIALOGSTYLE      = &H00000040???   ' // Use the new dialog layout with the ability to resize
                                           ' // Caller needs to call OleInitialize() before using this API

'%BIF_USENEWUI            = %BIF_NEWDIALOGSTYLE OR %BIF_EDITBOX

'%BIF_BROWSEINCLUDEURLS   = &H00000080???   ' // Allow URLs to be displayed or entered. (Requires BIF_USENEWUI)
'%BIF_UAHINT              = &H00000100???   ' // Add a UA hint to the dialog, in place of the edit box. May not be combined with BIF_EDITBOX
'%BIF_NONEWFOLDERBUTTON   = &H00000200???   ' // Do not add the "New Folder" button to the dialog.  Only applicable with BIF_NEWDIALOGSTYLE.
'%BIF_NOTRANSLATETARGETS  = &H00000400???   ' // don't traverse target as shortcut

%BIF_BROWSEFORCOMPUTER   = &H00001000???   ' // Browsing for Computers.
%BIF_BROWSEFORPRINTER    = &H00002000???   ' // Browsing for Printers
'%BIF_BROWSEINCLUDEFILES  = &H00004000???   ' // Browsing for Everything
'%BIF_SHAREABLE           = &H00008000???   ' // sharable resources displayed (remote shares, requires BIF_USENEWUI)
%BIF_BROWSEFILEJUNCTIONS = &H00010000???   ' // allow folder junctions like zip files and libraries to be browsed

' // message from browser
%BFFM_INITIALIZED       = 1
%BFFM_SELCHANGED        = 2
%BFFM_VALIDATEFAILEDA   = 3   ' // lParam:szPath ret:1(cont),0(EndDialog)
%BFFM_VALIDATEFAILEDW   = 4   ' // lParam:wzPath ret:1(cont),0(EndDialog)
%BFFM_IUNKNOWN          = 5   ' // provides IUnknown to client. lParam: IUnknown*

%BFFM_VALIDATEFAILED    = %BFFM_VALIDATEFAILEDA

' // messages to browser
%BFFM_SETSTATUSTEXTA    = %WM_USER + 100
%BFFM_ENABLEOK          = %WM_USER + 101
%BFFM_SETSELECTIONA     = %WM_USER + 102
%BFFM_SETSELECTIONW     = %WM_USER + 103
%BFFM_SETSTATUSTEXTW    = %WM_USER + 104
%BFFM_SETOKTEXT         = %WM_USER + 105 ' // Unicode only
%BFFM_SETEXPANDED       = %WM_USER + 106 ' // Unicode only

%BFFM_SETSTATUSTEXT     = %BFFM_SETSTATUSTEXTA
%BFFM_SETSELECTION      = %BFFM_SETSELECTIONA

DECLARE FUNCTION SHBrowseForFolderA IMPORT "SHELL32.DLL" ALIAS "SHBrowseForFolderA" ( _
   BYREF lpbi AS BROWSEINFOA _                          ' __in LPBROWSEINFO lpbi
 ) AS DWORD                                             ' PIDLIST_ABSOLUTE

DECLARE FUNCTION SHBrowseForFolderW IMPORT "SHELL32.DLL" ALIAS "SHBrowseForFolderW" ( _
   BYREF lpbi AS BROWSEINFOW _                          ' __in LPBROWSEINFOW lpbi
 ) AS DWORD                                             ' PIDLIST_ABSOLUTE

#IF %DEF(%UNICODE)
   MACRO SHBrowseForFolder = SHBrowseForFolderW
#ELSE
   MACRO SHBrowseForFolder = SHBrowseForFolderA
#ENDIF

'#endif

'//-------------------------------------------------------------------------
'//
'// SHLoadInProc
'//
'//   When this function is called, the shell calls CoCreateInstance
'//  (or equivalent) with CLSCTX_INPROC_SERVER and the specified CLSID
'//  from within the shell's process and release it immediately.
'//
'//   This function is no longer implemented. It will return E_NOTIMPL.
'//-------------------------------------------------------------------------

DECLARE FUNCTION SHLoadInProc IMPORT "SHELL32.DLL" ALIAS "SHLoadInProc" ( _
   BYREF rclsid AS GUID _                               ' __in REFCLSID rclsid
 ) AS LONG                                              ' HRESULT


'#if (_WIN32_IE >= 0x0600)

'//-------------------------------------------------------------------------
'//
'// SHEnableServiceObject
'//
'//   Like SHLoadInProc, but gives control over the object's lifetime
'//  via fEnable parameter.  TRUE tells the shell to create the object
'//  and hold onto it, FALSE tells the shell to look for the previously
'//  created instance of the object and release it.
'//
'//   This function is no longer implemented. It will return E_NOTIMPL.
'//-------------------------------------------------------------------------

DECLARE FUNCTION SHEnableServiceObject IMPORT "SHELL32.DLL" ALIAS "SHEnableServiceObject" ( _
   BYREF rclsid AS GUID _                               ' __in REFCLSID rclsid
 , BYVAL fEnable AS LONG _                              ' __in BOOL fEnable
 ) AS LONG                                              ' HRESULT

'#endif


'//-------------------------------------------------------------------------
'//
'// Internet Shortcut Object
'//
'//-------------------------------------------------------------------------
'// Cmds for CGID_ShortCut

'#if (_WIN32_IE >= _WIN32_IE_IE501)
%ISHCUTCMDID_DOWNLOADICON      = 0
%ISHCUTCMDID_INTSHORTCUTCREATE = 1
'#if (_WIN32_IE >= _WIN32_IE_IE70)
%ISHCUTCMDID_COMMITHISTORY     = 2
%ISHCUTCMDID_SETUSERAWURL      = 3
'#endif
%CMDID_INTSHORTCUTCREATE       = %ISHCUTCMDID_INTSHORTCUTCREATE
'#endif

'// Bindctx key, passed to IShellFolder::ParseDiplayName.  Provides dbfolder with extra
'// data, besides the name, necessary for the parse. the object in the bind context implements
'// IPropertyStore and provides a fixed set of properties
'#define STR_PARSE_WITH_PROPERTIES           L"ParseWithProperties"
$STR_PARSE_WITH_PROPERTIES           = "ParseWithProperties"

'// Bindctx key, passed to IShellFolder::ParseDisplayName(). used to pass the original item that
'// is being re-parsed. that item is stored as an IShellItem that supports IParentAndItem,
'// and should be the un-aliased form of the item.
'#define STR_PARSE_PARTIAL_IDLIST            L"ParseOriginalItem"
$STR_PARSE_PARTIAL_IDLIST            = "ParseOriginalItem"

'//
'//  Helper function which returns a IShellFolder interface to the desktop
'// folder. This is equivalent to call CoCreateInstance with CLSID_ShellDesktop.
'//
'//  CoCreateInstance(CLSID_Desktop, NULL,
'//                   CLSCTX_INPROC, IID_IShellFolder, &pshf);
'//
#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SHGetDesktopFolder LIB "Shell32.dll" _
    ALIAS "SHGetDesktopFolder" (ppshf AS ANY) AS LONG
#ELSE
DECLARE FUNCTION SHGetDesktopFolder IMPORT "SHELL32.DLL" ALIAS "SHGetDesktopFolder" ( _
   BYREF ppshf AS IShellFolder _                        ' __out IShellFolder **ppshf
 ) AS LONG                                              ' HRESULT
#ENDIF

' ########################################################################################
' IShellDetails interface
' IID = 000214EC-0000-0000-C000-000000000046
' Inherited interface = IUnknown
' ########################################################################################

'// this interface is deprecated, data sources should
'// implement IShellFolder2::GetDetailsOf()/GetDetailsEx() instead

#IF NOT %DEF(%IShellDetails_INTERFACE_DEFINED)
    %IShellDetails_INTERFACE_DEFINED = 1

INTERFACE IShellDetails $IID_IShellDetails

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetDetailsOf ( _                              ' VTable offset = 12
     BYVAL pidl AS DWORD _                              ' __in LPCITEMIDLIST pidl
   , BYVAL iColumn AS DWORD _                           ' __in UINT iColumn
   , BYREF pDetails AS SHELLDETAILS _                   ' __out SHELLDETAILS *pDetails
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ColumnClick ( _                               ' VTable offset = 16
     BYVAL iColumn AS DWORD _                           ' __in UINT iColumn
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IShellDetails_INTERFACE_DEFINED__ */

'//-------------------------------------------------------------------------
'//
'// IObjMgr interface
'//
'//
'// [Member functions]
'//
'// IObjMgr::Append(punk)
'//   This function adds an object to the end of a list of objects.
'//
'// IObjMgr::Remove(punk)
'//   This function removes an object from a list of objects.
'//
'// This is implemented by CLSID_ACLMulti so each AutoComplete List
'// (CLSID_ACLHistory, CLSID_ACListISF, CLSID_ACLMRU) can be added.
'// CLSID_ACLMulti's IEnumString will then be the union of the results
'// from the COM Objects added.
'//-------------------------------------------------------------------------

' ########################################################################################
' IObjMgr interface
' IID = 00BB2761-6A77-11D0-A535-00C04FD7D062
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IObjMgr_INTERFACE_DEFINED)
    %IObjMgr_INTERFACE_DEFINED = 1

INTERFACE IObjMgr $IID_IObjMgr

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Append ( _                                    ' VTable offset = 12
     BYVAL punk AS IUnknown _                           ' __in IUnknown *punk
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Remove ( _                                    ' VTable offset = 12
     BYVAL punk AS IUnknown _                           ' __in IUnknown *punk
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IObjMgr_INTERFACE_DEFINED__ */

'//-------------------------------------------------------------------------
'//
'// ICurrentWorkingDirectory interface
'//
'//
'// [Member functions]
'//
'// ICurrentWorkingDirectory::GetDirectory(LPWSTR pwzPath, DWORD cchSize)
'//   This function gets the Current Working Directory from a COM object that
'//   stores such state.
'//
'// ICurrentWorkingDirectory::SetDirectory(LPCWSTR pwzPath)
'//   This function sets the Current Working Directory of a COM object that
'//   stores such state.
'//
'// This function can be used generically.  One COM object that implements it
'// is CLSID_ACListISF so that the AutoComplete engine can complete relative
'// paths.  SetDirectory() will set the "Current Working Directory" and
'// AutoComplete with then complete both absolute and relative paths.
'// For Example, if ::SetDirectory(L"C:\Program Files") is called, then
'// the user can AutoComplete "..\winnt".  In order to set the current
'// working directory for non-file system paths, "ftp://ftp.microsoft.com/" or
'// "Control Panel" for example, use IPersistFolder.
'//-------------------------------------------------------------------------

' ########################################################################################
' ICurrentWorkingDirectory interface
' IID = 91956D21-9276-11D1-921A-006097DF5BD4
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ICurrentWorkingDirectory_INTERFACE_DEFINED)
    %ICurrentWorkingDirectory_INTERFACE_DEFINED = 1

INTERFACE ICurrentWorkingDirectory $IID_ICurrentWorkingDirectory

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetDirectory ( _                              ' VTable offset = 12
     BYREF pwzPath AS WSTRINGZ _                        ' __in LPWSTR pwzPath
   , BYVAL cchSize AS DWORD _                           ' __in DWORD cchSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetDirectory ( _                              ' VTable offset = 16
     BYREF pwzPath AS WSTRINGZ _                        ' __in LPWSTR pwzPath
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICurrentWorkingDirectory_INTERFACE_DEFINED__ */


'//-------------------------------------------------------------------------
'//
'// IACList interface
'//
'//
'// [Member functions]
'//
'// IObjMgr::Expand(LPCOLESTR)
'//   This function tells an autocomplete list to expand a specific string.
'//
'// If the user enters a multi-level path, AutoComplete (CLSID_AutoComplete)
'// will use this interface to tell the "AutoComplete Lists" where to expand
'// the results.
'//
'// For Example, if the user enters "C:\Program Files\Micros", AutoComplete
'// first completely enumerate the "AutoComplete Lists" via IEnumString.  Then it
'// will call the "AutoComplete Lists" with IACList::Expand(L"C:\Program Files").
'// It will then enumerate the IEnumString interface again to get results in
'// that directory.
'//-------------------------------------------------------------------------

' ########################################################################################
' IACList interface
' IID = 77A130B0-94FD-11D0-A544-00C04FD7d062
' Inherited interface = IUnknown
' Mimimum operating systems: Windows 2000, Windows Millennium Edition
' ########################################################################################

#IF NOT %DEF(%IACList_INTERFACE_DEFINED)
    %IACList_INTERFACE_DEFINED = 1

INTERFACE IACList $IID_IACList

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Expand ( _                                    ' VTable offset = 12
     BYVAL pszExpand AS DWORD _                         ' __in LPCOLESTR pszExpand
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IACList_INTERFACE_DEFINED__ */

'//-------------------------------------------------------------------------
'//
'// IACList2 interface
'//
'// [Description]
'//              This interface exists to allow the caller to set filter criteria
'// for an AutoComplete List.  AutoComplete Lists generates the list of
'// possible AutoComplete completions.  CLSID_ACListISF is one AutoComplete
'// List COM object that implements this interface.
'//-------------------------------------------------------------------------

' ########################################################################################
' IACList2 interface
' IID = 470141a0-5186-11d2-bbb6-0060977b464c
' Inherited interface = IACList
' Mimimum operating systems: Windows 2000, Windows Millennium Edition
' ########################################################################################

#IF NOT %DEF(%IACList2_INTERFACE_DEFINED)
    %IACList2_INTERFACE_DEFINED = 1

' AUTOCOMPLETELISTOPTIONS enum
%ACLO_NONE             = 0   ' // don't enumerate anything
%ACLO_CURRENTDIR       = 1   ' // enumerate current directory
%ACLO_MYCOMPUTER       = 2   ' // enumerate MyComputer
%ACLO_DESKTOP          = 4   ' // enumerate Desktop Folder
%ACLO_FAVORITES        = 8   ' // enumerate Favorites Folder
%ACLO_FILESYSONLY      = 16  ' // enumerate only the file system
'#if (_WIN32_IE >= _WIN32_IE_IE60)
%ACLO_FILESYSDIRS      = 32  ' // enumerate only the file system dirs, UNC shares, and UNC servers.
'#endif
'#if (_WIN32_IE >= _WIN32_IE_IE70)
%ACLO_VIRTUALNAMESPACE = 64  ' // enumereate on the virual namespace
'#endif

INTERFACE IACList2 $IID_IACList2

   INHERIT IUnknown

   ' =====================================================================================
   ' IACList Method
   ' =====================================================================================
   METHOD Expand ( _                                    ' VTable offset = 12
     BYVAL pszExpand AS DWORD _                         ' __in LPCOLESTR pszExpand
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IACList2 Methods
   ' =====================================================================================
   METHOD SetOptions ( _                                ' VTable offset = 16
     BYVAL dwFlag AS DWORD _                            ' __in DWORD dwFlag
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetOptions ( _                                ' VTable offset = 20
     BYREF pdwFlag AS DWORD _                           ' __in DWORD* pdwFlag
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IACList2_INTERFACE_DEFINED__ */

'/*-------------------------------------------------------------------------*\
'    INTERFACE: IProgressDialog

'    DESCRIPTION:
'        CLSID_ProgressDialog/IProgressDialog exist to allow a caller to create
'    a progress dialog, set it's title, animation, text lines, progress, and
'    it will do all the work of updating on a background thread, being modless,
'    handling the user cancelling the operation, and estimating the time remaining
'    until the operation completes.

'    USAGE:
'        This is how the dialog is used during operations that require progress
'    and the ability to cancel:
'    {
'        DWORD dwComplete, dwTotal;
'        IProgressDialog * ppd;
'        CoCreateInstance(CLSID_ProgressDialog, NULL, CLSCTX_INPROC_SERVER, IID_IProgressDialog, (void **)&ppd);
'        ppd->SetTitle(L"My Slow Operation");                                // Set the title of the dialog.
'        ppd->SetAnimation(hInstApp, IDA_OPERATION_ANIMATION);               // Set the animation to play.
'        ppd->StartProgressDialog(hwndParent, punk, PROGDLG_AUTOTIME, NULL); // Display and enable automatic estimated time remaining.
'        ppd->SetCancelMsg(L"Please wait while the current operation is cleaned up", NULL);   // Will only be displayed if Cancel button is pressed.

'        dwComplete = 0;
'        dwTotal = CalcTotalUnitsToDo();

'        // Reset because CalcTotalUnitsToDo() took a long time and the estimated time
'        // is based on the time between ::StartProgressDialog() and the first
'        // ::SetProgress() call.
'        ppd->Timer(PDTIMER_RESET, NULL);

'        for (nIndex = 0; nIndex < nTotal; nIndex++)
'        {
'            if (TRUE == ppd->HasUserCancelled())
'                break;

'            ppd->SetLine(2, L"I'm processing item n", FALSE, NULL);
'            dwComplete += DoSlowOperation();

'            ppd->SetProgress(dwCompleted, dwTotal);
'        }

'        ppd->StopProgressDialog();
'        ppd->Release();
'    }
'\*-------------------------------------------------------------------------*/

#IF NOT %DEF(%IProgressDialog_INTERFACE_DEFINED)
    %IProgressDialog_INTERFACE_DEFINED = 1

'// Flags for IProgressDialog::StartProgressDialog() (dwFlags)
%PROGDLG_NORMAL          = &H00000000???      ' // default normal progress dlg behavior
%PROGDLG_MODAL           = &H00000001???      ' // the dialog is modal to its hwndParent (default is modeless)
%PROGDLG_AUTOTIME        = &H00000002???      ' // automatically updates the "Line3" text with the "time remaining" (you cant call SetLine3 if you passs this!)
%PROGDLG_NOTIME          = &H00000004???      ' // we dont show the "time remaining" if this is set. We need this if dwTotal < dwCompleted for sparse files
%PROGDLG_NOMINIMIZE      = &H00000008???      ' // Do not have a minimize button in the caption bar.
%PROGDLG_NOPROGRESSBAR   = &H00000010???      ' // Don't display the progress bar
'#if (_WIN32_IE >= _WIN32_IE_IE70)
%PROGDLG_MARQUEEPROGRESS = &H00000020???      ' // Use marquee progress (comctl32 v6 required)
%PROGDLG_NOCANCEL        = &H00000040???      ' // No cancel button (operation cannot be canceled) (use sparingly)
'#endif

'' // Time Actions (dwTimerAction)
%PDTIMER_RESET           = &H00000001???      ' // Reset the timer so the progress will be calculated from now until the first ::SetProgress() is called so
                                              ' // those this time will correspond to the values passed to ::SetProgress().  Only do this before ::SetProgress() is called.

'#if (_WIN32_IE >= _WIN32_IE_IE70)
%PDTIMER_PAUSE           = &H00000002         ' // Progress has been suspended
%PDTIMER_RESUME          = &H00000003         ' // Progress has resumed
'#endif

' ########################################################################################
' IProgressDialog interface
' IID = EBBC7C04-315E-11d2-B62F-006097DF5BD4
' Inherited interface: IUnknown
' ########################################################################################

INTERFACE IProgressDialog $IID_IProgressDialog

   INHERIT IUnknown

   ' =====================================================================================
   METHOD StartProgressDialog ( _                       ' VTable offset = 12
     BYVAL hwndParent AS DWORD _                        ' __in HWND hwndParent
   , BYVAL punkEnableModless AS DWORD _                 ' __in IUnknown *punkEnableModless
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , OPTIONAL BYVAL pvReserved AS DWORD _               ' __in LPCVOID pvReserved
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD StopProgressDialog ( _                        ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetTitle ( _                                  ' VTable offset = 20
     BYREF pwzTitle AS WSTRINGZ _                       ' __in LPCWSTR pwzTitle
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetAnimation ( _                              ' VTable offset = 24
     BYVAL hInstAnimation AS DWORD _                    ' __in HINSTANCE hInstAnimation
   , BYVAL idAnimation AS DWORD _                       ' __in UINT idAnimation
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD HasUserCancelled ( _                          ' VTable offset = 28
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetProgress ( _                               ' VTable offset = 32
     BYVAL dwCompleted AS DWORD _                       ' __in DWORD dwCompleted
   , BYVAL dwTotal AS DWORD _                           ' __in DWORD dwTotal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetProgress64 ( _                             ' VTable offset = 36
     BYVAL ullCompleted AS QUAD _                       ' __in ULONGLONG ullCompleted
   , BYVAL ullTotal AS QUAD _                           ' __in ULONGLONG ullTotal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetLine ( _                                   ' VTable offset = 40
     BYVAL dwLineNum AS DWORD _                         ' __in DWORD dwLineNum
   , BYREF pwzString AS WSTRINGZ _                      ' __in LPCWSTR pwzString
   , BYVAL fCompactPath AS LONG _                       ' __in BOOL fCompactPath
   , OPTIONAL BYVAL pvReserved AS DWORD _               ' __in LPCVOID pvReserved
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetCancelMsg ( _                              ' VTable offset = 44
     BYREF pwzCancelMsg AS WSTRINGZ _                   ' __in LPCWSTR pwzCancelMsg
   , OPTIONAL BYVAL pvReserved AS DWORD _               ' __in LPCVOID pvReserved
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Timer ( _                                     ' VTable offset = 48
     BYVAL dwTimerAction AS DWORD _                     ' __in DWORD dwTimerAction
   , OPTIONAL BYVAL pvReserved AS DWORD _               ' __in LPCVOID pvReserved
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IProgressDialog_INTERFACE_DEFINED__ */


'//==========================================================================
'// IDockingWindowSite/IDockingWindow/IDockingWindowFrame interfaces
'// IInputObjectSite/IInputObject interfaces
'//
'//  These interfaces allow us (or ISVs) to install/update external Internet
'// Toolbar for IE and the shell. The frame will simply get the CLSID from
'// registry (to be defined) and CoCreateInstance it.
'//
'//==========================================================================


'//-------------------------------------------------------------------------
'//
'// IDockingWindowSite interface
'//
'//   A site implements this interface so the object can negotiate for
'// and inquire about real estate on the site.
'//
'// [Member functions]
'//
'// IDockingWindowSite::GetBorderDW(punkObj, prcBorder)
'//   Site returns the bounding rectangle of the given source object
'//   (punkObj).
'//
'// IDockingWindowSite::RequestBorderSpaceDW(punkObj, pbw)
'//   Object requests that the site makes room for it, as specified in
'//   *pbw.
'//
'// IDockingWindowSite::SetBorderSpaceDW(punkObj, pbw)
'//   Object requests that the site set the border spacing to the size
'//   specified in *pbw.
'//
'//-------------------------------------------------------------------------

' ########################################################################################
' IDockingWindowSite interface
' IID = 2A342FC2-7B26-11D0-8CA9-00A0C92DBFE8
' Inherited interface = IOleWindow
' ########################################################################################

#IF NOT %DEF(%IDockingWindowSite_INTERFACE_DEFINED)
    %IDockingWindowSite_INTERFACE_DEFINED = 1

INTERFACE IDockingWindowSite $IID_IDockingWindowSite

   INHERIT IUnknown

   ' =====================================================================================
   ' IOleWindow methods
   ' =====================================================================================
   METHOD GetWindow ( _                                 ' VTable offset = 12
     BYREF phwnd AS DWORD _                             ' __in HWND * phwnd
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ContextSensitiveHelp ( _                      ' VTable offset = 16
     BYVAL fEnterMode AS LONG _                         ' __in BOOL fEnterMode
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IDockingWindowSite methods
   ' =====================================================================================
   METHOD GetBorderDW ( _                               ' VTable offset = 20
     BYVAL punkObj AS IUnknown _                        ' __in IUnknown* punkObj
   , BYREF prcBorder AS RECT _                          ' __out LPRECT prcBorder
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RequestBorderSpaceDW ( _                      ' VTable offset = 24
     BYVAL punkObj AS IUnknown _                        ' __in IUnknown* punkObj
   , BYREF pbw AS RECT _                                ' __out LPCBORDERWIDTHS pbw
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetBorderSpaceDW ( _                          ' VTable offset = 28
     BYVAL punkObj AS IUnknown _                        ' __in IUnknown* punkObj
   , BYREF pbw AS RECT _                                ' __in LPCBORDERWIDTHS pbw
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDockingWindowSite_INTERFACE_DEFINED__ */


'//-------------------------------------------------------------------------
'//
'// IDockingWindowFrame interface
'//
'// [Member functions]
'//
'// IDockingWindowFrame::AddToolbar(punkSrc, pwszItem, dwReserved)
'//
'// IDockingWindowFrame::RemoveToolbar(punkSrc, dwRemoveFlags)
'//
'// IDockingWindowFrame::FindToolbar(pwszItem, riid, ppv)
'//
'//-------------------------------------------------------------------------

'// flags for RemoveToolbar
%DWFRF_NORMAL            = &H0000???
%DWFRF_DELETECONFIGDATA  = &H0001???

'// flags for AddToolbar
%DWFAF_HIDDEN            = &H0001???  ' // add hidden
%DWFAF_GROUP1            = &H0002???  ' // insert at end of group 1
%DWFAF_GROUP2            = &H0004???  ' // insert at end of group 2
%DWFAF_AUTOHIDE          = &H0010???  ' // The toolbar will be subject to AutoHide in Full Screen mode

' ########################################################################################
' IDockingWindowFrame interface
' IID = 47D2657A-7B27-11D0-8CA9-00A0C92DBFE8
' Inherited interface = IOleWindow
' ########################################################################################

#IF NOT %DEF(%IDockingWindowFrame_INTERFACE_DEFINED)
    %IDockingWindowFrame_INTERFACE_DEFINED = 1

INTERFACE IDockingWindowFrame $IID_IDockingWindowFrame

   INHERIT IUnknown

   ' =====================================================================================
   ' IOleWindow methods
   ' =====================================================================================
   METHOD GetWindow ( _                                 ' VTable offset = 12
     BYREF phwnd AS DWORD _                             ' __in HWND * phwnd
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ContextSensitiveHelp ( _                      ' VTable offset = 16
     BYVAL fEnterMode AS LONG _                         ' __in BOOL fEnterMode
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IDockingWindowFrame methods
   ' =====================================================================================
   METHOD AddToolbar ( _                                ' VTable offset = 20
     BYVAL punkSrc AS IUnknown _                        ' __in IUnknown* punkSrc
   , BYREF pwszItem AS WSTRINGZ _                       ' __in LPCWSTR pwszItem
   , BYVAL dwAddFlags AS DWORD _                        ' __in DWORD dwAddFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RemoveToolbar ( _                             ' VTable offset = 24
     BYVAL punkSrc AS IUnknown _                        ' __in IUnknown* punkSrc
   , BYVAL dwRemoveFlags AS DWORD _                     ' __in DWORD dwRemoveFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD FindToolbar ( _                               ' VTable offset = 28
     BYREF pwszItem AS WSTRINGZ _                       ' __in LPCWSTR pwszItem
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppv AS IUnknown _                            ' __out void **ppv
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDockingWindowFrame_INTERFACE_DEFINED__ */

'#if (_WIN32_IE >= 0x0400)

'/* ***************** IThumbnailCapture
' * CaptureThumbnail : takes an IHTMLDocument2 and returns a thumbnail of specified
' *                    size as an hbitmap
' */

' ########################################################################################
' IThumbnailCapture interface
' IID = 4EA39266-7211-409F-B622-F63DBD16C533
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IThumbnailCapture_INTERFACE_DEFINED)
    %IThumbnailCapture_INTERFACE_DEFINED = 1

INTERFACE IThumbnailCapture $IID_IThumbnailCapture

   INHERIT IUnknown

   ' =====================================================================================
   METHOD CaptureThumbnail ( _                          ' VTable offset = 12
     BYREF pMaxSize AS SIZE _                           ' __in const SIZE * pMaxSize
   , BYVAL pHTMLDoc2 AS IUnknown _                      ' __in IUnknown * pHTMLDoc2
   , BYVAL phbmThumbnail AS DWORD _                     ' __in HBITMAP * phbmThumbnail
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IThumbnailCapture_INTERFACE_DEFINED__ */

'#endif


'#if (NTDDI_VERSION >= NTDDI_WIN2K && NTDDI_VERSION < NTDDI_VISTA)

'#include <pshpack8.h>

' // Size = 528 bytes
TYPE ENUMSHELLIMAGESTOREDATA DWORD FILL
   szPath      AS WSTRINGZ * %MAX_PATH   ' WCHAR [MAX_PATH]
   ftTimeStamp AS FILETIME               ' FILETIME
END TYPE

'#include <poppack.h>        /* Return to byte packing */


' ########################################################################################
' IEnumShellImageStore interface
' IID = 6DFD582B-92E3-11D1-98A3-00C04FB687DA
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IEnumShellImageStore_INTERFACE_DEFINED)
    %IEnumShellImageStore_INTERFACE_DEFINED = 1

INTERFACE IEnumShellImageStore $IID_IEnumShellImageStore

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Reset ( _                                     ' VTable offset = 12
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Next ( _                                      ' VTable offset = 16
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   , BYREF prgElt AS ENUMSHELLIMAGESTOREDATA _          ' __out PENUMSHELLIMAGESTOREDATA * prgElt
   , BYREF pceltFetched AS DWORD _                      ' __out ULONG * pceltFetched
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Skip ( _                                      ' VTable offset = 20
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 24
     BYREF ppEnum AS IEnumShellImageStore _             ' __out IEnumShellImageStore ** ppEnum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEnumShellImageStore_INTERFACE_DEFINED__ */

'// flags used to determine the capabilities of the storage for the images
%SHIMSTCAPFLAG_LOCKABLE  = &H0001???  ' // does the store require/support locking
%SHIMSTCAPFLAG_PURGEABLE = &H0002???  ' // does the store require dead items purging externally ?

'// this interface is used to manipulate the Image cache. It can potentially be used
'// in a free threaded manner in conjunction with the Lock parameter to Open and close

' ########################################################################################
' IShellImageStore interface
' IID = 48C8118C-B924-11D1-98D5-00C04FB687DA
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IShellImageStore_INTERFACE_DEFINED)
    %IShellImageStore_INTERFACE_DEFINED = 1

INTERFACE IShellImageStore $IID_IShellImageStore

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Open ( _                                      ' VTable offset = 12
     BYVAL dwMode AS DWORD _                            ' __in DWORD dwMode
   , BYREF pdwLock AS DWORD _                           ' __out DWORD * pdwLock
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Create ( _                                    ' VTable offset = 16
     BYVAL dwMode AS DWORD _                            ' __in DWORD dwMode
   , BYREF pdwLock AS DWORD _                           ' __out DWORD * pdwLock
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ReleaseLock ( _                               ' VTable offset = 20
     BYREF pdwLock AS DWORD _                           ' __out DWORD const * pdwLock
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Close ( _                                     ' VTable offset = 24
     BYREF pdwLock AS DWORD _                           ' __out DWORD const * pdwLock
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Commit ( _                                    ' VTable offset = 28
     BYREF pdwLock AS DWORD _                           ' __out DWORD const * pdwLock
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsLocked ( _                                  ' VTable offset = 32
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMode ( _                                   ' VTable offset = 36
     BYREF pdwMode AS DWORD _                           ' __out DWORD * pdwMode
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCapabilities ( _                           ' VTable offset = 40
     BYREF pdwCapMask AS DWORD _                        ' __out DWORD * pdwCapMask
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddEntry ( _                                  ' VTable offset = 44
     BYREF pszName AS WSTRINGZ _                        ' __in LPCWSTR pszName
   , BYREF pftTimeStamp AS FILETIME _                   ' __in const FILETIME * pftTimeStamp
   , BYVAL dwMode AS DWORD _                            ' __in DWORD dwMode
   , BYVAL hImage AS DWORD _                            ' __in HBITMAP hImage
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetEntry ( _                                  ' VTable offset = 48
     BYREF pszName AS WSTRINGZ _                        ' __in LPCWSTR pszName
   , BYVAL dwMode AS DWORD _                            ' __in DWORD dwMode
   , BYREF phImage AS DWORD _                           ' __out HBITMAP * phImage
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DeleteEntry ( _                               ' VTable offset = 52
     BYREF pszName AS WSTRINGZ _                        ' __in LPCWSTR pszName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsEntryInStore ( _                            ' VTable offset = 56
     BYREF pszName AS WSTRINGZ _                        ' __in LPCWSTR pszName
   , BYREF pftTimeStamp AS FILETIME _                   ' __out FILETIME * pftTimeStamp
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Enum ( _                                      ' VTable offset = 60
     BYREF ppEnum AS IEnumShellImageStore _             ' __out LPENUMSHELLIMAGESTORE * ppEnum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IShellImageStore_INTERFACE_DEFINED__ */

'#endif  // (NTDDI_VERSION >= NTDDI_WIN2K && NTDDI_VERSION < NTDDI_VISTA)


'#if (_WIN32_IE >= 0x0400)

'////  IShellFolderBand

'// Field mask
%ISFB_MASK_STATE          = &H00000001???  ' // TRUE if dwStateMask and dwState is valid
%ISFB_MASK_BKCOLOR        = &H00000002???  ' // TRUE if crBkgnd field is valid
%ISFB_MASK_VIEWMODE       = &H00000004???  ' // TRUE if wViewMode field is valid
%ISFB_MASK_SHELLFOLDER    = &H00000008???
%ISFB_MASK_IDLIST         = &H00000010???
%ISFB_MASK_COLORS         = &H00000020???  ' // TRUE if crXXXX fields are valid (except bkgnd)

%ISFB_STATE_DEFAULT       = &H00000000???
%ISFB_STATE_DEBOSSED      = &H00000001???
%ISFB_STATE_ALLOWRENAME   = &H00000002???
%ISFB_STATE_NOSHOWTEXT    = &H00000004???  ' // TRUE if _fNoShowText
%ISFB_STATE_CHANNELBAR    = &H00000010???  ' // TRUE if we want NavigateTarget support
%ISFB_STATE_QLINKSMODE    = &H00000020???  ' // TRUE if we want to turn off drag & drop onto content items
%ISFB_STATE_FULLOPEN      = &H00000040???  ' // TRUE if band should maximize when opened
%ISFB_STATE_NONAMESORT    = &H00000080???  ' // TRUE if band should _not_ sort icons by name
%ISFB_STATE_BTNMINSIZE    = &H00000100???  ' // TRUE if band should report min thickness of button

%ISFBVIEWMODE_SMALLICONS  = &H0001??
%ISFBVIEWMODE_LARGEICONS  = &H0002??
'#if (_WIN32_IE < _WIN32_IE_IE70)
%ISFBVIEWMODE_LOGOS       = &H0003??
'#endif

'#include <pshpack8.h>

' // Size = 36 bytes
TYPE BANDINFOSFB DWORD FILL
   dwMask      AS DWORD             ' DWORD         // [in] ISFB_MASK mask of valid fields from crBkgnd on
   dwStateMask AS DWORD             ' DWORD         // [in] ISFB_STATE mask of dwState bits being set/queried
   dwState     AS DWORD             ' DWORD         // [in/out] ISFB_STATE bits
   crBkgnd     AS DWORD             ' COLORREF      // [in/out]
   crBtnLt     AS DWORD             ' COLORREF      // [in/out]
   crBtnDk     AS DWORD             ' COLORREF      // [in/out]
   wViewMode   AS WORD              ' WORD          // [in/out]
   wAlign      AS WORD              ' WORD          // not used (yet)
   psf         AS DWORD             ' IShellFolder* // [out]
   pidl        AS ITEMIDLIST PTR    ' LPITEMIDLIST  // [out]
END TYPE

'#include <poppack.h>        /* Return to byte packing */

' ########################################################################################
' IShellFolderBand interface
' IID = 7FE80CC8-C247-11D0-B93A-00A0C90312E1
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IShellFolderBand_INTERFACE_DEFINED)
    %IShellFolderBand_INTERFACE_DEFINED = 1

INTERFACE IShellFolderBand $IID_IShellFolderBand

   INHERIT IUnknown

   ' =====================================================================================
   METHOD InitializeSFB ( _                             ' VTable offset = 12
     BYVAL psf AS IShellFolder _                        ' __in IShellFolder *psf
   , BYVAL pidl AS DWORD _                              ' __in LPCITEMIDLIST pidl
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetBandInfoSFB ( _                            ' VTable offset = 16
     BYREF pbi AS BANDINFOSFB _                         ' __in PBANDINFOSFB pbi
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetBandInfoSFB ( _                            ' VTable offset = 20
     BYREF pbi AS BANDINFOSFB _                         ' __out PBANDINFOSFB pbi
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IShellFolderBand_INTERFACE_DEFINED__ */

' Command Target IDs
%SFBID_PIDLCHANGED        = 0

' ########################################################################################
' IDeskBarClient interface
' IID = EB0FE175-1A3A-11D0-89B3-00A0C90A90AC
' Inherited interface = IOleWindow
' ########################################################################################

#IF NOT %DEF(%IDeskBarClient_INTERFACE_DEFINED)
    %IDeskBarClient_INTERFACE_DEFINED = 1

$IID_IDeskBarClient = GUID$("{EB0FE175-1A3A-11D0-89B3-00A0C90A90AC}")

INTERFACE IDeskBarClient $IID_IDeskBarClient

   INHERIT IUnknown

   ' =====================================================================================
   ' IOleWindow methods
   ' =====================================================================================
   METHOD GetWindow ( _                                 ' VTable offset = 12
     BYREF phwnd AS DWORD _                             ' __in HWND * phwnd
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ContextSensitiveHelp ( _                      ' VTable offset = 16
     BYVAL fEnterMode AS LONG _                         ' __in BOOL fEnterMode
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IDeskBarClient Methods
   ' =====================================================================================
   METHOD SetDeskBarSite ( _                            ' VTable offset = 20
     BYVAL punkSite AS IUnknown _                       ' __in_opt IUnknown* punkSite
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetModeDBC ( _                                ' VTable offset = 24
     BYVAL dwState AS DWORD _                           ' __in DWORD dwState
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UIActivateDBC ( _                             ' VTable offset = 28
     BYVAL dwState AS DWORD _                           ' __in DWORD dwState
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSize ( _                                   ' VTable offset = 32
     BYVAL dwWhich AS DWORD _                           ' __in DWORD dwWhich
   , BYREF prc AS RECT _                                ' __out LPRECT prc
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDeskBarClient_INTERFACE_DEFINED__ */

%DBC_GS_IDEAL         = 0  ' // get the ideal size
%DBC_GS_SIZEDOWN      = 1  ' // clip the height of a rect to a multiple of the rebar's integral size


%DBC_HIDE        = 0  ' // Band is hidden (being destroyed)
%DBC_SHOW        = 1  ' // Band is visible
%DBC_SHOWOBSCURE = 2  ' // Band is completely obscured


%DBCID_EMPTY      = 0      ' // bandsite is empty
%DBCID_ONDRAG     = 1      ' // (down)DragMoveEnter/Leave vaIn:I4:eDrag
%DBCID_CLSIDOFBAR = 2      ' // clsid of bar inside
%DBCID_RESIZE     = 3      ' // resize from keyboard
%DBCID_GETBAR     = 4      ' // returns vaOut:VT_UNKNOWN of hosting dockbar (IDeskBar)

'#endif // (_WIN32_IE > 0x0400)

'#if (_WIN32_IE >= 0x400)
'//
'// We need to make sure that WININET.H is included before this interface is
'// used because the COMPONENT structure uses INTERNET_MAX_URL_LENGTH
'//

'#INCLUDE ONCE "wininet.inc"   ' // Don't include it: it creates conflicts with Socket Tools.

#IF %DEF(%WININET_INC)
'//
'//  Flags and structures used by IActiveDesktop
'//

' // Size = 8 bytes
TYPE WALLPAPEROPT BYTE
   dwSize  AS DWORD   ' DWORD // size of this Structure.
   dwStyle AS DWORD   ' DWORD // WPSTYLE_* mentioned above
END TYPE

' // Size = 12 bytes
TYPE COMPONENTSOPT BYTE
   dwSize            AS DWORD   ' DWORD // Size of this structure
   fEnableComponents AS LONG    ' BOOL  // Enable components?
   fActiveDesktop    AS LONG    ' BOOL  // Active desktop enabled ?
END TYPE

' // Size = 44 bytes
TYPE COMPPOS BYTE
   dwSize                AS DWORD   ' DWORD // Size of this structure
   iLeft                 AS LONG    ' int   // Left of top-left corner in screen co-ordinates.
   iTop                  AS LONG    ' int   // Top of top-left corner in screen co-ordinates.
   dwWidth               AS DWORD   ' DWORD // Width in pixels.
   dwHeight              AS DWORD   ' DWORD // Height in pixels.
   izIndex               AS LONG    ' int   // Indicates the Z-order of the component.
   fCanResize            AS LONG    ' BOOL  // Is the component resizeable?
   fCanResizeX           AS LONG    ' BOOL  // Resizeable in X-direction?
   fCanResizeY           AS LONG    ' BOOL  // Resizeable in Y-direction?
   iPreferredLeftPercent AS LONG    ' int   // Left of top-left corner as percent of screen width
   iPreferredTopPercent  AS LONG    ' int   // Top of top-left corner as percent of screen height
END TYPE

' // Size = 24 bytes
TYPE COMPSTATEINFO BYTE
   dwSize      AS DWORD   ' DWORD // Size of this structure.
   iLeft       AS LONG    ' int   // Left of the top-left corner in screen co-ordinates.
   iTop        AS LONG    ' int   // Top of top-left corner in screen co-ordinates.
   dwWidth     AS DWORD   ' DWORD // Width in pixels.
   dwHeight    AS DWORD   ' DWORD // Height in pixels.
   dwItemState AS DWORD   ' DWORD // State of the component (full-screen mode or split-screen or normal state.
END TYPE

%COMPONENT_TOP = &H3fffffff???  ' // izOrder value meaning component is at the top


'// iCompType values
%COMP_TYPE_HTMLDOC      = 0
%COMP_TYPE_PICTURE      = 1
%COMP_TYPE_WEBSITE      = 2
%COMP_TYPE_CONTROL      = 3
%COMP_TYPE_CFHTML       = 4
%COMP_TYPE_MAX          = 4

'// The following is the COMPONENT structure used in IE4.01, IE4.0 and Memphis. It is kept here for compatibility
'// reasons.

' // Size = 8924 bytes
TYPE IE4COMPONENT BYTE
   dwSize           AS DWORD    ' DWORD   // Size of this structure
   dwID             AS DWORD    ' DWORD   // Reserved: Set it always to zero.
   iComponentType   AS LONG     ' int     // One of COMP_TYPE_*
   fChecked         AS LONG     ' BOOL    // Is this component enabled?
   fDirty           AS LONG     ' BOOL    // Had the component been modified and not yet saved to disk?
   fNoScroll        AS LONG     ' BOOL    // Is the component scrollable?
   cpPos            AS COMPPOS  ' COMPPOS // Width, height etc.,
   wszFriendlyName  AS WSTRINGZ * %MAX_PATH                  ' WCHAR [MAX_PATH]                 // Friendly name of component.
   wszSource        AS WSTRINGZ * %INTERNET_MAX_URL_LENGTH   ' WCHAR [INTERNET_MAX_URL_LENGTH]  //URL of the component.
   wszSubscribedURL AS WSTRINGZ * %INTERNET_MAX_URL_LENGTH   ' WCHAR [INTERNET_MAX_URL_LENGTH]  //Subscrined URL
END TYPE

'//
'// The following is the new NT5 component structure. Note that the initial portion of this component exactly
'// matches the IE4COMPONENT structure. All new fields are added at the bottom and the dwSize field is used to
'// distinguish between IE4COMPONENT and the new COMPONENT structures.
'//

' // Size = 8976 bytes
TYPE COMPONENT BYTE
   dwSize           AS DWORD     ' DWORD   // Size of this structure
   dwID             AS DWORD     ' DWORD   // Reserved: Set it always to zero.
   iComponentType   AS LONG      ' int     // One of COMP_TYPE_*
   fChecked         AS LONG      ' BOOL    // Is this component enabled?
   fDirty           AS LONG      ' BOOL    // Had the component been modified and not yet saved to disk?
   fNoScroll        AS LONG      ' BOOL    // Is the component scrollable?
   cpPos            AS COMPPOS   ' COMPPOS // Width, height etc.,
   wszFriendlyName  AS WSTRINGZ * %MAX_PATH                  ' WCHAR [MAX_PATH];          // Friendly name of component.
   wszSource        AS WSTRINGZ * %INTERNET_MAX_URL_LENGTH   ' WCHAR [INTERNET_MAX_URL_LENGTH]; //URL of the component.
   wszSubscribedURL AS WSTRINGZ * %INTERNET_MAX_URL_LENGTH   ' WCHAR [INTERNET_MAX_URL_LENGTH]; //Subscrined URL
   ' // New fields are added below. Everything above here must exactly match the IE4COMPONENT Structure.
   dwCurItemState   AS DWORD           ' DWORD         // Current state of the Component.
   csiOriginal      AS COMPSTATEINFO   ' COMPSTATEINFO // Original state of the component when it was first added.
   csiRestored      AS COMPSTATEINFO   ' COMPSTATEINFO // Restored state of the component.
END TYPE


'// Defines for dwCurItemState
%IS_NORMAL                 = &H00000001???
%IS_FULLSCREEN             = &H00000002???
%IS_SPLIT                  = &H00000004???
%IS_VALIDSIZESTATEBITS     = %IS_NORMAL OR %IS_SPLIT OR %IS_FULLSCREEN  ' // The set of IS_* state bits which define the "size" of the component - these bits are mutually exclusive.
%IS_VALIDSTATEBITS         = %IS_NORMAL OR %IS_SPLIT OR %IS_FULLSCREEN OR &H80000000??? OR &H40000000???  ' // All of the currently defined IS_* bits.

'////////////////////////////////////////////
'// Flags for IActiveDesktop::ApplyChanges()
%AD_APPLY_SAVE             = &H00000001???
%AD_APPLY_HTMLGEN          = &H00000002???
%AD_APPLY_REFRESH          = &H00000004???
%AD_APPLY_ALL              = %AD_APPLY_SAVE OR %AD_APPLY_HTMLGEN OR %AD_APPLY_REFRESH
%AD_APPLY_FORCE            = &H00000008???
%AD_APPLY_BUFFERED_REFRESH = &H00000010???
%AD_APPLY_DYNAMICREFRESH   = &H00000020???

'////////////////////////////////////////////
'// Flags for IActiveDesktop::GetWallpaper()
'#if (NTDDI_VERSION >= NTDDI_VISTA)
%AD_GETWP_BMP             = &H00000000???
%AD_GETWP_IMAGE           = &H00000001???
%AD_GETWP_LAST_APPLIED    = &H00000002???
'#endif

'////////////////////////////////////////////
'// Flags for IActiveDesktop::GetWallpaperOptions()
'//           IActiveDesktop::SetWallpaperOptions()
%WPSTYLE_CENTER     = 0
%WPSTYLE_TILE       = 1
%WPSTYLE_STRETCH    = 2
'#if (NTDDI_VERSION >= NTDDI_WIN7)
%WPSTYLE_KEEPASPECT = 3
%WPSTYLE_CROPTOFIT  = 4
%WPSTYLE_MAX        = 5
'#else
'#define WPSTYLE_MAX         3
'#endif // NTDDI_WIN7
%WPSTYLE_MAX        = 5

'////////////////////////////////////////////
'// Flags for IActiveDesktop::ModifyComponent()

%COMP_ELEM_TYPE          = &H00000001???
%COMP_ELEM_CHECKED       = &H00000002???
%COMP_ELEM_DIRTY         = &H00000004???
%COMP_ELEM_NOSCROLL      = &H00000008???
%COMP_ELEM_POS_LEFT      = &H00000010???
%COMP_ELEM_POS_TOP       = &H00000020???
%COMP_ELEM_SIZE_WIDTH    = &H00000040???
%COMP_ELEM_SIZE_HEIGHT   = &H00000080???
%COMP_ELEM_POS_ZINDEX    = &H00000100???
%COMP_ELEM_SOURCE        = &H00000200???
%COMP_ELEM_FRIENDLYNAME  = &H00000400???
%COMP_ELEM_SUBSCRIBEDURL = &H00000800???
%COMP_ELEM_ORIGINAL_CSI  = &H00001000???
%COMP_ELEM_RESTORED_CSI  = &H00002000???
%COMP_ELEM_CURITEMSTATE  = &H00004000???

%COMP_ELEM_ALL = %COMP_ELEM_TYPE OR %COMP_ELEM_CHECKED OR %COMP_ELEM_DIRTY OR _
                 %COMP_ELEM_NOSCROLL OR %COMP_ELEM_POS_LEFT OR %COMP_ELEM_SIZE_WIDTH OR _
                 %COMP_ELEM_SIZE_HEIGHT OR %COMP_ELEM_POS_ZINDEX OR %COMP_ELEM_SOURCE OR _
                 %COMP_ELEM_FRIENDLYNAME OR %COMP_ELEM_POS_TOP OR %COMP_ELEM_SUBSCRIBEDURL OR _
                 %COMP_ELEM_ORIGINAL_CSI OR %COMP_ELEM_RESTORED_CSI OR %COMP_ELEM_CURITEMSTATE


'////////////////////////////////////////////
'// Flags for IActiveDesktop::AddDesktopItemWithUI()
%DTI_ADDUI_DEFAULT               = &H00000000???
%DTI_ADDUI_DISPSUBWIZARD         = &H00000001???
%DTI_ADDUI_POSITIONITEM          = &H00000002???

'////////////////////////////////////////////
'// Flags for IActiveDesktop::AddUrl()
%ADDURL_SILENT             = &H0001???

'////////////////////////////////////////////
'// Default positions for ADI
%COMPONENT_DEFAULT_LEFT    = &HFFFF???
%COMPONENT_DEFAULT_TOP     = &HFFFF???

'//
'//  Interface for manipulating the Active Desktop.
'//

' ########################################################################################
' IActiveDesktop interface
' IID = F490EB00-1240-11D1-9888-006097DEACF9
' Inherited interface: IUnknown
' ########################################################################################

#IF NOT %DEF(%IActiveDesktop_INTERFACE_DEFINED)
    %IActiveDesktop_INTERFACE_DEFINED = 1

INTERFACE IActiveDesktop $IID_IActiveDesktop

   INHERIT IUnknown

   ' =====================================================================================
   METHOD ApplyChanges ( _                              ' VTable offset = 12
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetWallpaper ( _                              ' VTable offset = 16
     BYREF pwszWallpaper AS WSTRINGZ _                  ' __out LPWSTR pwszWallpaper
   , BYVAL cchWallpaper AS DWORD _                      ' __in UINT cchWallpaper
   , OPTIONAL BYVAL dwReserved AS DWORD _               ' __in DWORD dwReserved
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetWallpaper ( _                              ' VTable offset = 20
     BYREF pwszWallpaper AS WSTRINGZ _                  ' __in LPCWSTR pwszWallpaper
   , OPTIONAL BYVAL dwReserved AS DWORD _               ' __in DWORD dwReserved
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetWallpaperOptions ( _                       ' VTable offset = 24
     BYREF pwpo AS WALLPAPEROPT _                       ' __out LPWALLPAPEROPT pwpo
   , OPTIONAL BYVAL dwReserved AS DWORD _               ' __in DWORD dwReserved
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetWallpaperOptions ( _                       ' VTable offset = 28
     BYREF pwpo AS WALLPAPEROPT _                       ' __in LPCWALLPAPEROPT pwpo
   , OPTIONAL BYVAL dwReserved AS DWORD _               ' __in DWORD dwReserved
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPattern ( _                                ' VTable offset = 32
     BYREF pwszPattern AS WSTRINGZ _                    ' __out LPWSTR pwszPattern
   , BYVAL cchPattern AS DWORD _                        ' __in UINT cchPattern
   , OPTIONAL BYVAL dwReserved AS DWORD _               ' __in DWORD dwReserved
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPattern ( _                                ' VTable offset = 36
     BYREF pwszPattern AS WSTRINGZ _                    ' __in LPCWSTR pwszPattern
   , OPTIONAL BYVAL dwReserved AS DWORD _               ' __in DWORD dwReserved
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDesktopItemOptions ( _                     ' VTable offset = 40
     BYREF pco AS COMPONENTSOPT _                       ' __out LPCOMPONENTSOPT pco
   , OPTIONAL BYVAL dwReserved AS DWORD _               ' __in DWORD dwReserved
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetDesktopItemOptions ( _                     ' VTable offset = 44
     BYREF pco AS COMPONENTSOPT _                       ' __in LPCOMPONENTSOPT pco
   , OPTIONAL BYVAL dwReserved AS DWORD _               ' __in DWORD dwReserved
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddDesktopItem ( _                            ' VTable offset = 48
     BYREF pcomp AS COMPONENT _                         ' __in LPCOMPONENT pcomp
   , OPTIONAL BYVAL dwReserved AS DWORD _               ' __in DWORD dwReserved
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddDesktopItemWithUI ( _                      ' VTable offset = 52
     BYVAL hwnd AS DWORD _                              ' __in HWND hwnd
   , BYREF pcomp AS COMPONENT _                         ' __in LPCOMPONENT pcomp
   , OPTIONAL BYVAL dwReserved AS DWORD _               ' __in DWORD dwReserved
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ModifyDesktopItem ( _                         ' VTable offset = 56
     BYREF pcomp AS COMPONENT _                         ' __in LPCOMPONENT pcomp
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RemoveDesktopItem ( _                         ' VTable offset = 60
     BYREF pcomp AS COMPONENT _                         ' __in LPCOMPONENT pcomp
   , OPTIONAL BYVAL dwReserved AS DWORD _               ' __in DWORD dwReserved
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDesktopItemCount ( _                       ' VTable offset = 64
     BYREF lpiCount AS LONG _                           ' __out LPINT lpiCount
   , OPTIONAL BYVAL dwReserved AS DWORD _               ' __in DWORD dwReserved
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDesktopItem ( _                            ' VTable offset = 68
     BYVAL nComponent AS LONG _                         ' __in int nComponent
   , BYREF pcomp AS COMPONENT _                         ' __out LPCOMPONENT pcomp
   , OPTIONAL BYVAL dwReserved AS DWORD _               ' __in DWORD dwReserved
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDesktopItemByID ( _                        ' VTable offset = 72
     BYVAL dwID AS DWORD _                              ' __in DWORD dwID
   , BYREF pcomp AS COMPONENT _                         ' __out LPCOMPONENT pcomp
   , OPTIONAL BYVAL dwReserved AS DWORD _               ' __in DWORD dwReserved
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GenerateDesktopItemHtml ( _                   ' VTable offset = 76
     BYREF pwszFileName AS WSTRINGZ _                   ' __in LPCWSTR pwszFileName
   , BYREF pcomp AS COMPONENT _                         ' __in LPCOMPONENT pcomp
   , OPTIONAL BYVAL dwReserved AS DWORD _               ' __in DWORD dwReserved
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddUrl ( _                                    ' VTable offset = 80
     BYVAL hwnd AS DWORD _                              ' __in HWND hwnd
   , BYREF pszSource AS WSTRINGZ _                      ' __in LPCWSTR pszSource
   , BYREF pcomp AS COMPONENT _                         ' __in LPCOMPONENT pcomp
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDesktopItemBySource ( _                    ' VTable offset = 84
     BYREF pszSource AS WSTRINGZ _                      ' __in LPCWSTR pszSource
   , BYREF pcomp AS COMPONENT _                         ' __in LPCOMPONENT pcomp
   , OPTIONAL BYVAL dwReserved AS DWORD _               ' __in DWORD dwReserved
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE
' ========================================================================================

#ENDIF   ' /* __IActiveDesktop_INTERFACE_DEFINED__ */

'// Flags for SetSafeMode
%SSM_CLEAR       = &H0000???
%SSM_SET         = &H0001???
%SSM_REFRESH     = &H0002???
%SSM_UPDATE      = &H0004???

'// Flags for Set/GetScheme
%SCHEME_DISPLAY  = &H0001???
%SCHEME_EDIT     = &H0002???
%SCHEME_LOCAL    = &H0004???
%SCHEME_GLOBAL   = &H0008???
%SCHEME_REFRESH  = &H0010???
%SCHEME_UPDATE   = &H0020???
%SCHEME_DONOTUSE = &H0040???   ' // used to be SCHEME_ENUMERATE; no longer supported
%SCHEME_CREATE   = &H0080???

' ########################################################################################
' IActiveDesktopP interface
' IID = 52502EE0-EC80-11D0-89AB-00C04FC2972D
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IActiveDesktopP_INTERFACE_DEFINED)
    %IActiveDesktopP_INTERFACE_DEFINED = 1

INTERFACE IActiveDesktopP $IID_IActiveDesktopP

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetSafeMode ( _                               ' VTable offset = 12
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnsureUpdateHTML ( _                          ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetScheme ( _                                 ' VTable offset = 20
     BYREF pwszSchemeName AS WSTRINGZ _                 ' __in LPCWSTR pwszSchemeName
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetScheme ( _                                 ' VTable offset = 24
     BYREF pwszSchemeName AS WSTRINGZ _                 ' __in LPCWSTR pwszSchemeName
   , BYREF lpdwcchBuffer AS DWORD _                     ' __out DWORD *lpdwcchBuffer
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IActiveDesktopP_INTERFACE_DEFINED__ */

' ########################################################################################
' IADesktopP2 interface
' IID = B22754E2-4574-11d1-9888-006097DEACF9
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IActiveDesktopP2_INTERFACE_DEFINED)
    %IActiveDesktopP2_INTERFACE_DEFINED = 1

'//Flags for GetADOObjectFlags
%GADOF_DIRTY = &H00000001???

INTERFACE IADesktopP2 $IID_IADesktopP2

   INHERIT IUnknown

   ' =====================================================================================
   METHOD ReReadWallpaper ( _                           ' VTable offset = 12
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetADObjectFlags ( _                          ' VTable offset = 16
     BYREF lpdwFlags AS DWORD _                         ' __out DWORD *lpdwFlags
   , BYVAL dwMask AS DWORD _                            ' __in DWORD dwMask
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UpdateAllDesktopSubscriptions ( _             ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD MakeDynamicChanges ( _                        ' VTable offset = 24
     BYVAL pOleObj AS IOleObject _                      ' __in IOleObject *pOleObj
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IActiveDesktopP2_INTERFACE_DEFINED__ */

#ENDIF   ' // _WININET_

'#if (_WIN32_IE >= 0x0500)

%MAX_COLUMN_NAME_LEN = 80
%MAX_COLUMN_DESC_LEN = 128

'#include <pshpack1.h>

' // Size = 450 bytes
TYPE SHCOLUMNINFO BYTE
   scid           AS SHCOLUMNID   ' SHCOLUMNID // OUT the unique identifier of this column
   vt             AS WORD         ' VARTYPE    // OUT the native type of the data returned
   fmt            AS DWORD        ' DWORD      // OUT this listview format (LVCFMT_LEFT, usually)
   cChars         AS DWORD        ' UINT       // OUT the default width of the column, in characters
   csFlags        AS DWORD        ' DWORD      // OUT SHCOLSTATE flags
   wszTitle       AS WSTRINGZ * %MAX_COLUMN_NAME_LEN   ' WCHAR [MAX_COLUMN_NAME_LEN] // OUT the title of the column
   wszDescription AS WSTRINGZ * %MAX_COLUMN_DESC_LEN   ' WCHAR [MAX_COLUMN_DESC_LEN] // OUT full description of this column
END TYPE

'#include <poppack.h>        /* Return to default */

'#include <pshpack8.h>

' // Size = 528 bytes
TYPE SHCOLUMNINIT DWORD FILL
   dwFlags    AS DWORD   ' ULONG  // initialization flags
   dwReserved AS DWORD   ' ULONG  // reserved for future use.
   wszFolder  AS WSTRINGZ * %MAX_PATH   ' WCHAR [MAX_PATH] // fully qualified folder path (or empty if multiple folders)
END TYPE

%SHCDF_UPDATEITEM        = &H00000001???     ' // this flag is a hint that the file has changed since the last call to GetItemData

' // Size = 536 bytes
TYPE SHCOLUMNDATA DWORD FILL
   dwFlags          AS DWORD                  ' ULONG  // combination of SHCDF_ flags.
   dwFileAttributes AS DWORD                  ' DWORD  // file attributes.
   dwReserved       AS DWORD                  ' ULONG  // reserved for future use.
   pwszExt          AS WSTRINGZ PTR           ' WCHAR* // address of file name extension
   wszFile          AS WSTRINGZ * %MAX_PATH   ' WCHAR [MAX_PATH] // Absolute path of file.
END TYPE

'#include <poppack.h>        /* Return to byte packing */

'// Note: these objects must be threadsafe!  GetItemData _will_ be called
'// simultaneously from multiple threads.

' ########################################################################################
' IColumnProvider interface
' IID = E8025004-1C42-11D2-BE2C-00A0C9A83DA1
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IColumnProvider_INTERFACE_DEFINED)
    %IColumnProvider_INTERFACE_DEFINED = 1

INTERFACE IColumnProvider $IID_IColumnProvider

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Initialize ( _                                ' VTable offset = 12
     BYREF psci AS SHCOLUMNINIT _                       ' __in LPCSHCOLUMNINIT psci
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetColumnInfo ( _                             ' VTable offset = 16
     BYVAL dwIndex AS DWORD _                           ' __in DWORD dwIndex
   , BYREF psci AS SHCOLUMNINFO _                       ' __out SHCOLUMNINFO *psci
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetItemData ( _                               ' VTable offset = 20
     BYREF pscid AS SHCOLUMNID _                        ' __in LPCSHCOLUMNID pscid
   , BYREF pscd AS SHCOLUMNDATA _                       ' __inLPCSHCOLUMNDATA pscd
   , BYREF pvarData AS VARIANT _                        ' __out VARIANT *pvarData
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IColumnProvider_INTERFACE_DEFINED__ */

'#endif // (_WIN32_IE >= 0x0500)
'#endif // _WIN32_IE

'//==========================================================================
'// Clipboard format which may be supported by IDataObject from system
'// defined shell folders (such as directories, network, ...).
'//==========================================================================

'#define CFSTR_SHELLIDLIST                   TEXT("Shell IDList Array")      // CF_IDLIST
'#define CFSTR_SHELLIDLISTOFFSET             TEXT("Shell Object Offsets")    // CF_OBJECTPOSITIONS
'#define CFSTR_NETRESOURCES                  TEXT("Net Resource")            // CF_NETRESOURCE
'#define CFSTR_FILEDESCRIPTORA               TEXT("FileGroupDescriptor")     // CF_FILEGROUPDESCRIPTORA
'#define CFSTR_FILEDESCRIPTORW               TEXT("FileGroupDescriptorW")    // CF_FILEGROUPDESCRIPTORW
'#define CFSTR_FILECONTENTS                  TEXT("FileContents")            // CF_FILECONTENTS
'#define CFSTR_FILENAMEA                     TEXT("FileName")                // CF_FILENAMEA
'#define CFSTR_FILENAMEW                     TEXT("FileNameW")               // CF_FILENAMEW
'#define CFSTR_PRINTERGROUP                  TEXT("PrinterFriendlyName")     // CF_PRINTERS
'#define CFSTR_FILENAMEMAPA                  TEXT("FileNameMap")             // CF_FILENAMEMAPA
'#define CFSTR_FILENAMEMAPW                  TEXT("FileNameMapW")            // CF_FILENAMEMAPW
'#define CFSTR_SHELLURL                      TEXT("UniformResourceLocator")
'#define CFSTR_INETURLA                      CFSTR_SHELLURL
'#define CFSTR_INETURLW                      TEXT("UniformResourceLocatorW")
'#define CFSTR_PREFERREDDROPEFFECT           TEXT("Preferred DropEffect")
'#define CFSTR_PERFORMEDDROPEFFECT           TEXT("Performed DropEffect")
'#define CFSTR_PASTESUCCEEDED                TEXT("Paste Succeeded")
'#define CFSTR_INDRAGLOOP                    TEXT("InShellDragLoop")
'#define CFSTR_DRAGCONTEXT                   TEXT("DragContext")
'#define CFSTR_MOUNTEDVOLUME                 TEXT("MountedVolume")
'#define CFSTR_PERSISTEDDATAOBJECT           TEXT("PersistedDataObject")
'#define CFSTR_TARGETCLSID                   TEXT("TargetCLSID")                         // HGLOBAL with a CLSID of the drop target
'#define CFSTR_LOGICALPERFORMEDDROPEFFECT    TEXT("Logical Performed DropEffect")
'#define CFSTR_AUTOPLAY_SHELLIDLISTS         TEXT("Autoplay Enumerated IDList Array")  //  (HGLOBAL with LPIDA)
'#define CFSTR_UNTRUSTEDDRAGDROP             TEXT("UntrustedDragDrop") //  DWORD
'#define CFSTR_FILE_ATTRIBUTES_ARRAY         TEXT("File Attributes Array")               // (FILE_ATTRIBUTES_ARRAY format on HGLOBAL)
'#define CFSTR_INVOKECOMMAND_DROPPARAM       TEXT("InvokeCommand DropParam")             // (HGLOBAL with LPWSTR)
'#define CFSTR_SHELLDROPHANDLER              TEXT("DropHandlerCLSID")                    // (HGLOBAL with CLSID of drop handler)
'#define CFSTR_DROPDESCRIPTION               TEXT("DropDescription")                     // (HGLOBAL with DROPDESCRIPTION)

$CFSTR_SHELLIDLIST                   = "Shell IDList Array"      ' // CF_IDLIST
$CFSTR_SHELLIDLISTOFFSET             = "Shell Object Offsets"    ' // CF_OBJECTPOSITIONS
$CFSTR_NETRESOURCES                  = "Net Resource"            ' // CF_NETRESOURCE
$CFSTR_FILEDESCRIPTORA               = "FileGroupDescriptor"     ' // CF_FILEGROUPDESCRIPTORA
$$CFSTR_FILEDESCRIPTORW              = "FileGroupDescriptorW"$$    ' // CF_FILEGROUPDESCRIPTORW
$CFSTR_FILECONTENTS                  = "FileContents"            ' // CF_FILECONTENTS
$CFSTR_FILENAMEA                     = "FileName"                ' // CF_FILENAMEA
$$CFSTR_FILENAMEW                    = "FileNameW"$$               ' // CF_FILENAMEW
$CFSTR_PRINTERGROUP                  = "PrinterFriendlyName"     ' // CF_PRINTERS
$CFSTR_FILENAMEMAPA                  = "FileNameMap"             ' // CF_FILENAMEMAPA
$$CFSTR_FILENAMEMAPW                 = "FileNameMapW"$$            ' // CF_FILENAMEMAPW
$CFSTR_SHELLURL                      = "UniformResourceLocator"
$CFSTR_INETURLA                      = $CFSTR_SHELLURL
$$CFSTR_INETURLW                     = "UniformResourceLocatorW"$$
$CFSTR_PREFERREDDROPEFFECT           = "Preferred DropEffect"
$CFSTR_PERFORMEDDROPEFFECT           = "Performed DropEffect"
$CFSTR_PASTESUCCEEDED                = "Paste Succeeded"
$CFSTR_INDRAGLOOP                    = "InShellDragLoop"
$CFSTR_DRAGCONTEXT                   = "DragContext"
$CFSTR_MOUNTEDVOLUME                 = "MountedVolume"
$CFSTR_PERSISTEDDATAOBJECT           = "PersistedDataObject"
$CFSTR_TARGETCLSID                   = "TargetCLSID"                      ' // HGLOBAL with a CLSID of the drop target
$CFSTR_LOGICALPERFORMEDDROPEFFECT    = "Logical Performed DropEffect"
$CFSTR_AUTOPLAY_SHELLIDLISTS         = "Autoplay Enumerated IDList Array" ' //  (HGLOBAL with LPIDA
$CFSTR_UNTRUSTEDDRAGDROP             = "UntrustedDragDrop"                ' //  DWORD
$CFSTR_FILE_ATTRIBUTES_ARRAY         = "File Attributes Array"            ' // (FILE_ATTRIBUTES_ARRAY format on HGLOBAL)
$CFSTR_INVOKECOMMAND_DROPPARAM       = "InvokeCommand DropParam"          ' // (HGLOBAL with LPWSTR)
$CFSTR_SHELLDROPHANDLER              = "DropHandlerCLSID"                 ' // (HGLOBAL with CLSID of drop handler)
$CFSTR_DROPDESCRIPTION               = "DropDescription"                  ' // (HGLOBAL with DROPDESCRIPTION)

#IF %DEF(%UNICODE)
   MACRO CFSTR_FILEDESCRIPTOR = $$CFSTR_FILEDESCRIPTORW
   MACRO CFSTR_FILENAME       = $$CFSTR_FILENAMEW
   MACRO CFSTR_FILENAMEMAP    = $$CFSTR_FILENAMEMAPW
   MACRO CFSTR_INETURL        = $$CFSTR_INETURLW
#ELSE
   MACRO CFSTR_FILEDESCRIPTOR = $CFSTR_FILEDESCRIPTORA
   MACRO CFSTR_FILENAME       = $CFSTR_FILENAMEA
   MACRO CFSTR_FILENAMEMAP    = $CFSTR_FILENAMEMAPA
   MACRO CFSTR_INETURL        = $CFSTR_INETURLA
#ENDIF

%DVASPECT_SHORTNAME = 2  ' // use for CF_HDROP to get short name version of file paths
%DVASPECT_COPY      = 3  ' // use to indicate format is a "Copy" of the data (FILECONTENTS, FILEDESCRIPTOR, etc)
%DVASPECT_LINK      = 4  ' // use to indicate format is a "Shortcut" to the data (FILECONTENTS, FILEDESCRIPTOR, etc)

'#include <pshpack8.h>
'//
'// format of CF_NETRESOURCE
'//

' // Size = 36 bytes
TYPE NRESARRAY DWORD FILL
   cItems AS DWORD         ' UINT
   nr(0)  AS NETRESOURCE   ' NETRESOURCE[1]
END TYPE
'#include <poppack.h>        /* Return to byte packing */

'//
'// format of CF_IDLIST
'//
' // Size = 8 bytes
TYPE CIDA BYTE
   cidl       AS DWORD   ' // number of relative IDList
   aoffset(0) AS DWORD   ' // [0]: folder IDList, [1]-[cidl]: item IDList
END TYPE

'//
'// FILEDESCRIPTOR.dwFlags field indicate which fields are to be used
'//
' FD_FLAGS enum
%FD_CLSID            = &H00000001???
%FD_SIZEPOINT        = &H00000002???
%FD_ATTRIBUTES       = &H00000004???
%FD_CREATETIME       = &H00000008???
%FD_ACCESSTIME       = &H00000010???
%FD_WRITESTIME       = &H00000020???
%FD_FILESIZE         = &H00000040???
%FD_PROGRESSUI       = &H00004000???      ' // Show Progress UI w/Drag and Drop
%FD_LINKUI           = &H00008000???      ' // 'link' UI is prefered
'#if (NTDDI_VERSION >= NTDDI_VISTA)
'FD_UNICODE          = (int) 0x80000000,       // this descriptor is UNICODE
%FD_UNICODE          = &H80000000&        ' // this descriptor is UNICODE
'#endif

UNION FILEDESCRIPTOR_CLSID_UNION
   clsid            AS GUID   ' CLSID
   ' // For compatibility with the PB declares
   nclsid           AS GUID   ' CLSID
END UNION

' // Size = 332 bytes
TYPE FILEDESCRIPTORA BYTE
   dwFlags          AS DWORD                   ' DWORD
   FILEDESCRIPTOR_CLSID_UNION
   sizel            AS SIZEL                   ' SIZEL
   pointl           AS POINTL                  ' POINTL
   dwFileAttributes AS DWORD                   ' DWORD
   ftCreationTime   AS FILETIME                ' FILETIME
   ftLastAccessTime AS FILETIME                ' FILETIME
   ftLastWriteTime  AS FILETIME                ' FILETIME
   nFileSizeHigh    AS DWORD                   ' DWORD
   nFileSizeLow     AS DWORD                   ' DWORD
   cFileName        AS ASCIIZ * %MAX_PATH      ' CHAR [MAX_PATH]
END TYPE

' // Size = 592 bytes
TYPE FILEDESCRIPTORW BYTE
   dwFlags          AS DWORD                   ' DWORD
   FILEDESCRIPTOR_CLSID_UNION
   sizel            AS SIZEL                   ' SIZEL
   pointl           AS POINTL                  ' POINTL
   dwFileAttributes AS DWORD                   ' DWORD
   ftCreationTime   AS FILETIME                ' FILETIME
   ftLastAccessTime AS FILETIME                ' FILETIME
   ftLastWriteTime  AS FILETIME                ' FILETIME
   nFileSizeHigh    AS DWORD                   ' DWORD
   nFileSizeLow     AS DWORD                   ' DWORD
   cFileName        AS WSTRINGZ * %MAX_PATH    ' WCHAR [MAX_PATH]
END TYPE

MACRO FILEDESCRIPTOR = FILEDESCRIPTORA

'//
'// format of CF_FILEGROUPDESCRIPTOR
'//

' // Size = 336 bytes
TYPE FILEGROUPDESCRIPTOR BYTE
   cItems AS DWORD              ' UINT
   fgd(0) AS FILEDESCRIPTORA    ' FILEDESCRIPTORA[1]
END TYPE

' // Size = 596 bytes
TYPE FILEGROUPDESCRIPTORW BYTE
   cItems AS DWORD              ' UINT
   fgd(0) AS FILEDESCRIPTORW    ' FILEDESCRIPTORW[1]
END TYPE

'//
'// format of CF_HDROP and CF_PRINTERS, in the HDROP case the data that follows
'// is a double null terinated list of file names, for printers they are printer
'// friendly names
'//

' // Size = 20 bytes
TYPE DROPFILES
   pFiles AS DWORD   ' DWORD // offset of file list
   pt     AS POINT   ' POINT // drop point (client coords)
   fNC    AS LONG    ' BOOL  // is it on NonClient area and pt is in screen coords
   fWide  AS LONG    ' BOOL  // WIDE character switch
END TYPE

'#if (NTDDI_VERSION >= NTDDI_VISTA)
' // Size = 16 bytes
TYPE FILE_ATTRIBUTES_ARRAY BYTE
   cItems                  AS DWORD   ' UINT  // number of items in rgdwFileAttributes array
   dwSumFileAttributes     AS DWORD   ' DWORD // all of the attributes ORed together
   dwProductFileAttributes AS DWORD   ' DWORD // all of the attributes ANDed together
   rgdwFileAttributes(0)   AS DWORD   ' DWORD[0] // array
END TYPE                              '          // clipboard format definition for CFSTR_FILE_ATTRIBUTES_ARRAY
'#endif

'#if (NTDDI_VERSION >= NTDDI_VISTA)
' enum DROPIMAGETYPE
%DROPIMAGE_INVALID = -1                 ' // no image preference (use default)
%DROPIMAGE_NONE    = 0                  ' // red "no" circle
%DROPIMAGE_COPY    = %DROPEFFECT_COPY   ' // plus for copy
%DROPIMAGE_MOVE    = %DROPEFFECT_MOVE   ' // movement arrow for move
%DROPIMAGE_LINK    = %DROPEFFECT_LINK   ' // link arrow for link
%DROPIMAGE_LABEL   = 6                  ' // tag icon to indicate metadata will be changed
%DROPIMAGE_WARNING = 7                  ' // yellow exclamation, something is amiss with the operation
%DROPIMAGE_NOIMAGE = 8                  ' // no image at all

UNION DROPDESCRIPTION_TYPE_UNION
   type      AS LONG   ' DROPIMAGETYPE // indicates the stock image to use
   ' // For compatibility with the PB declares
   ntype     AS LONG
END UNION

' // Size = 1044 bytes
TYPE DROPDESCRIPTION BYTE
   DROPDESCRIPTION_TYPE_UNION
'// text such as "Move to %1"
   szMessage AS WSTRINGZ * %MAX_PATH   ' WCHAR
'// text such as "Documents", inserted as specified by szMessage
   szInsert  AS WSTRINGZ * %MAX_PATH   ' WCHAR
'// some UI coloring is applied to the text in szInsert, if used by specifying %1 in szMessage.
'// %% and %1 are the subset of FormatMessage markers that are processed here.
END TYPE

'#endif // (NTDDI_VERSION >= NTDDI_VISTA)


'//====== File System Notification APIs ===============================
'//

' // Size = 8 bytes
TYPE SHChangeNotifyEntry BYTE
   pidl       AS ITEMIDLIST PTR   ' LPCITEMIDLIST
   fRecursive AS LONG             ' BOOL
END TYPE

'//
'//  File System Notification flags
'//

%SHCNRF_InterruptLevel     = &H0001???
%SHCNRF_ShellLevel         = &H0002???
%SHCNRF_RecursiveInterrupt = &H1000???
%SHCNRF_NewDelivery        = &H8000???

%SHCNE_RENAMEITEM          = &H00000001???
%SHCNE_CREATE              = &H00000002???
%SHCNE_DELETE              = &H00000004???
%SHCNE_MKDIR               = &H00000008???
%SHCNE_RMDIR               = &H00000010???
%SHCNE_MEDIAINSERTED       = &H00000020???
%SHCNE_MEDIAREMOVED        = &H00000040???
%SHCNE_DRIVEREMOVED        = &H00000080???
%SHCNE_DRIVEADD            = &H00000100???
%SHCNE_NETSHARE            = &H00000200???
%SHCNE_NETUNSHARE          = &H00000400???
%SHCNE_ATTRIBUTES          = &H00000800???
%SHCNE_UPDATEDIR           = &H00001000???
%SHCNE_UPDATEITEM          = &H00002000???
%SHCNE_SERVERDISCONNECT    = &H00004000???
%SHCNE_UPDATEIMAGE         = &H00008000???
%SHCNE_DRIVEADDGUI         = &H00010000???
%SHCNE_RENAMEFOLDER        = &H00020000???
%SHCNE_FREESPACE           = &H00040000???

'#if (_WIN32_IE >= 0x0400)
'// SHCNE_EXTENDED_EVENT: the extended event is identified in dwItem1,
'// packed in LPITEMIDLIST format (same as SHCNF_DWORD packing).
'// Additional information can be passed in the dwItem2 parameter
'// of SHChangeNotify (called "pidl2" below), which if present, must also
'// be in LPITEMIDLIST format.
'//
'// Unlike the standard events, the extended events are ORDINALs, so we
'// don't run out of bits.  Extended events follow the SHCNEE_* naming
'// convention.
'//
'// The dwItem2 parameter varies according to the extended event.

%SHCNE_EXTENDED_EVENT      = &H04000000???
'#endif      // (_WIN32_IE >= 0x0400)

%SHCNE_ASSOCCHANGED        = &H08000000???

%SHCNE_DISKEVENTS          = &H0002381F???
%SHCNE_GLOBALEVENTS        = &H0C0581E0???  ' // Events that dont match pidls first
%SHCNE_ALLEVENTS           = &H7FFFFFFF???
%SHCNE_INTERRUPT           = &H80000000???  ' // The presence of this flag indicates
                                            ' // that the event was generated by an
                                            ' // interrupt.  It is stripped out before
                                            ' // the clients of SHCNNotify_ see it.

'#if (_WIN32_IE >= 0x0400)
'// SHCNE_EXTENDED_EVENT extended events.  These events are ordinals.
'// This is not a bitfield.

%SHCNEE_ORDERCHANGED       = 2&  ' // pidl2 is the changed folder
%SHCNEE_MSI_CHANGE         = 4&  ' // pidl2 is a SHChangeProductKeyAsIDList
%SHCNEE_MSI_UNINSTALL      = 5&  ' // pidl2 is a SHChangeProductKeyAsIDList
'#endif


'// Flags
'// uFlags & SHCNF_TYPE is an ID which indicates what dwItem1 and dwItem2 mean
%SHCNF_IDLIST      = &H0000???      ' // LPITEMIDLIST
%SHCNF_PATHA       = &H0001???      ' // path name
%SHCNF_PRINTERA    = &H0002???      ' // printer friendly name
%SHCNF_DWORD       = &H0003???      ' // DWORD
%SHCNF_PATHW       = &H0005???      ' // path name
%SHCNF_PRINTERW    = &H0006???      ' // printer friendly name
%SHCNF_TYPE        = &H00FF???
%SHCNF_FLUSH       = &H1000???
%SHCNF_FLUSHNOWAIT = &H3000???      ' // includes SHCNF_FLUSH

%SHCNF_NOTIFYRECURSIVE = &H10000???   ' // Notify clients registered for any child

%SHCNF_PATH        = %SHCNF_PATHA
%SHCNF_PRINTER     = %SHCNF_PRINTERA

'//
'//  APIs
'//
DECLARE SUB SHChangeNotify IMPORT "SHELL32.DLL" ALIAS "SHChangeNotify" ( _
   BYVAL wEventId AS LONG _                             ' __in LONG wEventId
 , BYVAL uFlags AS DWORD _                              ' __in UINT uFlags
 , OPTIONAL BYREF dwItem1 AS ANY _                      ' __in_opt LPCVOID dwItem1
 , OPTIONAL BYREF dwItem2 AS ANY _                      ' __in_opt LPCVOID dwItem2
 )                                                      ' void

'//
'// IShellChangeNotify
'//

' ########################################################################################
' IShellChangeNotify interface
' IID = D82BE2B1-5764-11D0-A96E-00C04FD705A2
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IShellChangeNotify_INTERFACE_DEFINED)
    %IShellChangeNotify_INTERFACE_DEFINED = 1

INTERFACE IShellChangeNotify $IID_IShellChangeNotify

   INHERIT IUnknown

   ' =====================================================================================
   METHOD OnChange ( _                                  ' VTable offset = 12
     BYVAL lEvent AS LONG _                             ' __in LONG lEvent
   , BYVAL pidl1 AS DWORD _                             ' __in LPCITEMIDLIST pidl1
   , BYVAL pidl2 AS DWORD _                             ' __in LPCITEMIDLIST pidl2
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IShellChangeNotify_INTERFACE_DEFINED__ */

'//
'// IQueryInfo
'//
'//-------------------------------------------------------------------------
'//
'// IQueryInfo interface
'//
'// [Methods]
'//              ::GetInfoTip()
'//-------------------------------------------------------------------------

' ########################################################################################
' IQueryInfo interface
' IID = 00021500-0000-0000-C000-000000000046
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IQueryInfo_INTERFACE_DEFINED)
    %IQueryInfo_INTERFACE_DEFINED = 1

INTERFACE IQueryInfo $IID_IQueryInfo

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetInfoTip ( _                                ' VTable offset = 12
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF ppwszTip AS DWORD _                          ' __out WCHAR **ppwszTip
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetInfoFlags ( _                              ' VTable offset = 16
     BYREF pdwFlags AS DWORD _                          ' __out DWORD *pdwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IQueryInfo_INTERFACE_DEFINED__ */

%QITIPF_DEFAULT          = &H00000000???
%QITIPF_USENAME          = &H00000001???
%QITIPF_LINKNOTARGET     = &H00000002???
%QITIPF_LINKUSETARGET    = &H00000004???
'#if (NTDDI_VERSION >= NTDDI_WINXP)
%QITIPF_USESLOWTIP       = &H00000008???  ' // Flag says it's OK to take a long time generating tip
'#endif
'#if (NTDDI_VERSION >= NTDDI_VISTA)
%QITIPF_SINGLELINE       = &H00000010???
'#endif

%QIF_CACHED              = &H00000001???
%QIF_DONTEXPANDFOLDER    = &H00000002???

'//
'// SHAddToRecentDocs
'//
' enum SHARD
%SHARD_PIDL            = &H00000001???
%SHARD_PATHA           = &H00000002???
%SHARD_PATHW           = &H00000003???
'#if (NTDDI_VERSION >= NTDDI_WIN7)
%SHARD_APPIDINFO       = &H00000004???   ' // indicates the data type is a pointer to a SHARDAPPIDINFO structure
%SHARD_APPIDINFOIDLIST = &H00000005???   ' // indicates the data type is a pointer to a SHARDAPPIDINFOIDLIST structure
%SHARD_LINK            = &H00000006???   ' // indicates the data type is a pointer to an IShellLink instance
%SHARD_APPIDINFOLINK   = &H00000007???   ' // indicates the data type is a pointer to a SHARDAPPIDINFOLINK structure
%SHARD_SHELLITEM       = &H00000008???   ' // indicates the data type is a pointer to an IShellItem instance
'#endif
%SHARD_PATH            = %SHARD_PATHA

'#if (NTDDI_VERSION >= NTDDI_WIN7)

' // Size = 8 bytes
TYPE SHARDAPPIDINFO BYTE
   psi      AS DWORD PTR       ' IShellItem* // The namespace location of the the item that should be added to the recent docs folder.
   pszAppID AS WSTRINGZ PTR    ' PCWSTR // The id of the application that should be associated with this recent doc.
END TYPE

' // Size = 8 bytes
TYPE SHARDAPPIDINFOIDLIST BYTE
   pidl     AS ITEMIDLIST PTR   ' PCIDLIST_ABSOLUTE // The idlist for the shell item that should be added to the recent docs folder.
   pszAppID AS WSTRINGZ PTR     ' PCWSTR // The id of the application that should be associated with this recent doc.
END TYPE

' // Size = 8 bytes
TYPE SHARDAPPIDINFOLINK BYTE
   psl      AS DWORD PTR      ' IShellLink* // An IShellLink instance that when launched opens a recently used item in the specified
                              '             // application. This link is not added to the recent docs folder, but will be added to the
                              '             // specified application's destination list.
   pszAppID AS WSTRINGZ PTR   ' PCWSTR // The id of the application that should be associated with this recent doc.
END TYPE

'#endif

'// The type of the data pointed to by pv is a function of uFlags values that are SHARD_XXX values.  PV can be a PCIDLIST_ABSOLUTE, PCWSTR, PCSTR, SHARDAPPIDINFO, or SHARDAPPIDINFOIDLIST.
DECLARE SUB SHAddToRecentDocs IMPORT "SHELL32.DLL" ALIAS "SHAddToRecentDocs" ( _
   BYVAL uFlags AS DWORD _                              ' __in UINT uFlags
 , BYREF pv AS ANY _                                    ' __in LPCVOID pv
 )                                                      ' void

' // Size = 12 bytes
TYPE SHChangeDWORDAsIDList BYTE
   cb      AS WORD    ' USHORT
   dwItem1 AS DWORD   ' DWORD
   dwItem2 AS DWORD   ' DWORD
   cbZero  AS WORD    ' USHORT
END TYPE

'#if (NTDDI_VERSION >= NTDDI_WIN2K)

' // Size = 540 bytes
TYPE SHChangeUpdateImageIDList BYTE
   cb          AS WORD                   ' USHORT
   iIconIndex  AS LONG                   ' int
   iCurIndex   AS LONG                   ' int
   uFlags      AS DWORD                  ' UINT
   dwProcessID AS DWORD                  ' DWORD
   szName      AS WSTRINGZ * %MAX_PATH   ' WCHAR [MAX_PATH]
   cbZero      AS WORD                   ' USHORT
END TYPE

DECLARE FUNCTION SHHandleUpdateImage IMPORT "SHELL32.DLL" ALIAS "SHHandleUpdateImage" ( _
   BYVAL pidlExtra AS ITEMIDLIST PTR _                  ' __in PCIDLIST_ABSOLUTE pidlExtra
 ) AS LONG                                              ' int

' // Size = 82 bytes
TYPE SHChangeProductKeyAsIDList BYTE
   cb            AS WORD            ' USHORT
   wszProductKey AS WSTRINGZ * 39   ' WCHAR [39]
   cbZero        AS WORD            ' USHORT
END TYPE

DECLARE SUB SHUpdateImageA IMPORT "SHELL32.DLL" ALIAS "SHUpdateImageA" ( _
   BYREF pszHashItem AS ASCIIZ _                        ' __in LPCSTR pszHashItem
 , BYVAL iIndex AS LONG _                               ' __in int iIndex
 , BYVAL uFlags AS DWORD _                              ' __in UINT uFlags
 , BYVAL iImageIndex AS LONG _                          ' __in int iImageIndex
 )                                                      ' void

DECLARE SUB SHUpdateImageW IMPORT "SHELL32.DLL" ALIAS "SHUpdateImageW" ( _
   BYREF pszHashItem AS WSTRINGZ _                      ' __in LPCWSTR pszHashItem
 , BYVAL iIndex AS LONG _                               ' __in int iIndex
 , BYVAL uFlags AS DWORD _                              ' __in UINT uFlags
 , BYVAL iImageInde AS LONG _                           ' __in int iImageInde
 )                                                      ' void

#IF %DEF(%UNICODE)
   MACRO SHUpdateImage = SHUpdateImageW
#ELSE
   MACRO SHUpdateImage = SHUpdateImageA
#ENDIF

'#endif /* NTDDI_WIN2K */

DECLARE FUNCTION SHChangeNotifyRegister IMPORT "SHELL32.DLL" ALIAS "SHChangeNotifyRegister" ( _
   BYVAL hwnd AS DWORD _                                ' __in HWND hwnd
 , BYVAL fSources AS LONG _                             ' __in int fSources
 , BYVAL fEvents AS LONG _                              ' __in LONG fEvents
 , BYVAL wMsg AS DWORD _                                ' __in UINT wMsg
 , BYVAL cEntries AS LONG _                             ' __in int cEntries
 , BYREF pfsne AS SHChangeNotifyEntry _                 ' __in SHChangeNotifyEntry *pfsne
 ) AS DWORD                                             ' DWORD

' ========================================================================================
' NTSHChangeNotifyRegister
' Registers a window that receives notifications from the file system or Shell.
' Notifications that are received will use shared memory, equivalent to calling
' SHChangeNotifyRegister with the SHCNRF_NewDelivery flag set.
' This function does not have an associated header or library file so it must be called by
' ordinal value. Call LoadLibrary with the DLL name Shell32.dll to obtain a module handle.
' Then call GetProcAddress with that module handle and the ordinal number 640 to use this
' function.
' Minimum operating system: Windows 2000.
' This function is available through Microsoft Windows XP Service Pack 2 (SP2) and Windows
' Server 2003. It might be altered or unavailable in subsequent versions of Windows.
' Note: Removed from Vista SDK.
' ========================================================================================

'FUNCTION NTSHChangeNotifyRegister ( _
'   BYVAL hwnd AS DWORD _                         ' __in HWND hwnd
' , BYVAL fSources AS LONG _                      ' __in int fSources
' , BYVAL fEvents AS LONG _                       ' __in LONG fEvents
' , BYVAL wMsg AS DWORD _                         ' __in UINT wMsg
' , BYVAL cEntries AS LONG _                      ' __in int cEntries
' , BYREF pfsne AS IUnknown _                     ' __in SHChangeNotifyEntry *pfsne
'   ) AS DWORD                                    ' ULONG

'   LOCAL hLib  AS DWORD
'   LOCAL pAddr AS DWORD
'   LOCAL dwRes AS DWORD

'   hLib = LoadLibrary("SHELL32.DLL")
'   IF hLib = %NULL THEN EXIT FUNCTION
'   pAddr = GetProcAddress(hLib, BYVAL MAK(DWORD, 640, 0))
'   IF pAddr THEN CALL DWORD pAddr USING NTSHChangeNotifyRegister(hwnd, fSources, fEvents, wMsg, cEntries, pfsne) TO dwRes
'   FreeLibrary hLib
'   FUNCTION = dwRes

'END FUNCTION

DECLARE FUNCTION SHChangeNotifyDeregister IMPORT "SHELL32.DLL" ALIAS "SHChangeNotifyDeregister" ( _
   BYVAL ulID AS DWORD _                                ' __in ULONG ulID
 ) AS LONG                                              ' BOOL

' ========================================================================================
' NTSHChangeNotifyDeregister
' Unregisters the client's window process from receiving SHChangeNotify. This is the
' equivalent of calling the SHChangeNotifyDeregister function.
' This function does not have an associated header or library file so it must be called by
' ordinal value. Call LoadLibrary with the DLL name Shell32.dll to obtain a module handle.
' Then call GetProcAddress with that module handle and the ordinal number 641 to use this
' function.
' Minimum operating system: Windows 2000.
' Note: Removed from Vista SDK.
' ========================================================================================

'FUNCTION NTSHChangeNotifyDeregister ( _
'   BYVAL ulID AS DWORD _                         ' __in ULONG ulID
'   ) AS LONG                                     ' BOOL

'   LOCAL hLib  AS DWORD
'   LOCAL pAddr AS DWORD
'   LOCAL bRes  AS LONG

'   hLib = LoadLibrary("SHELL32.DLL")
'   IF hLib = %NULL THEN EXIT FUNCTION
'   pAddr = GetProcAddress(hLib, BYVAL MAK(DWORD, 641, 0))
'   IF pAddr THEN CALL DWORD pAddr USING NTSHChangeNotifyDeregister(ulID) TO bRes
'   FreeLibrary hLib
'   FUNCTION = bRes

'END FUNCTION


' enum SCNRT_STATUS
%SCNRT_ENABLE  = 0
%SCNRT_DISABLE = 1

'#if (NTDDI_VERSION >= NTDDI_VISTA)
'//  use SHChangeNotifyRegisterThread() to enable Async Register and Deregister.
'//  call with SCNRT_ENABLE at the thread proc begining and SCNRT_DISABLE at the end
'//  the call with SCNRT_DISABLE can block while it synchronizes with the main ChangeNotify thread
'#endif

DECLARE SUB SHChangeNotifyRegisterThread IMPORT "SHELL32.DLL" ALIAS "SHChangeNotifyRegisterThread" ( _
   BYVAL status AS DWORD _                              ' __in SCNRT_STATUS status
 )                                                      ' void

DECLARE FUNCTION SHChangeNotification_Lock IMPORT "SHELL32.DLL" ALIAS "SHChangeNotification_Lock" ( _
   BYVAL hChange AS DWORD _                             ' __in HANDLE hChange
 , BYVAL dwProcId AS DWORD _                            ' __in DWORD dwProcId
 , BYREF pppidl AS ANY _                                ' __out LPITEMIDLIST **pppidl
 , BYREF plEvent AS LONG _                              ' __out LONG *plEvent
 ) AS DWORD                                             ' HANDLE

DECLARE FUNCTION SHChangeNotification_Unlock IMPORT "SHELL32.DLL" ALIAS "SHChangeNotification_Unlock" ( _
   BYVAL hLock AS DWORD _                               ' __in HANDLE hLock
 ) AS LONG                                              ' BOOL

'#if (_WIN32_IE >= 0x0400)
'// The pidls that are given to the view via the ChangeNotifyEvents are simple Pidls,
'// SHGetRealIDL() will convert them to true PIDLs.
#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SHGetRealIDL LIB "Shell32.dll" ALIAS "SHGetRealIDL" _
    (psf AS ANY, pdlSimple AS ITEMIDLIST, ppidlReal AS ANY) AS LONG
#ELSE
DECLARE FUNCTION SHGetRealIDL IMPORT "SHELL32.DLL" ALIAS "SHGetRealIDL" ( _
   BYVAL psf AS IShellFolder _                          ' __in IShellFolder *psf
 , BYVAL pidlSimple AS DWORD _                          ' __in PCUITEMID_CHILD pidlSimple
 , BYREF ppidlReal AS ANY _                             ' __out PITEMID_CHILD *ppidlReal
 ) AS LONG                                              ' HRESULT
#ENDIF
'#endif // (_WIN32_IE >= 0x0400)

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SHGetInstanceExplorer LIB "Shell32.dll" _
    ALIAS "SHGetInstanceExplorer" (ppunk AS ANY) AS LONG
#ELSE
DECLARE FUNCTION SHGetInstanceExplorer IMPORT "SHELL32.DLL" ALIAS "SHGetInstanceExplorer" ( _
   BYREF ppunk AS IUnknown _                            ' __out IUnknown **ppunk
 ) AS LONG                                              ' HRESULT
#ENDIF

'//
'// SHGetDataFromIDListA/W
'//
'// SHGetDataFromIDList nFormat values TCHAR
%SHGDFIL_FINDDATA        = 1
%SHGDFIL_NETRESOURCE     = 2
%SHGDFIL_DESCRIPTIONID   = 3

%SHDID_ROOT_REGITEM         = 1
%SHDID_FS_FILE              = 2
%SHDID_FS_DIRECTORY         = 3
%SHDID_FS_OTHER             = 4
%SHDID_COMPUTER_DRIVE35     = 5
%SHDID_COMPUTER_DRIVE525    = 6
%SHDID_COMPUTER_REMOVABLE   = 7
%SHDID_COMPUTER_FIXED       = 8
%SHDID_COMPUTER_NETDRIVE    = 9
%SHDID_COMPUTER_CDROM       = 10
%SHDID_COMPUTER_RAMDISK     = 11
%SHDID_COMPUTER_OTHER       = 12
%SHDID_NET_DOMAIN           = 13
%SHDID_NET_SERVER           = 14
%SHDID_NET_SHARE            = 15
%SHDID_NET_RESTOFNET        = 16
%SHDID_NET_OTHER            = 17
'#if (NTDDI_VERSION >= NTDDI_WINXP)
%SHDID_COMPUTER_IMAGING     = 18
%SHDID_COMPUTER_AUDIO       = 19
%SHDID_COMPUTER_SHAREDDOCS  = 20
'#endif
'#if (NTDDI_VERSION >= NTDDI_VISTA)
%SHDID_MOBILE_DEVICE        = 21  ' // PDA/PalmPC
'#endif

'#include <pshpack8.h>
UNION SHDESCRIPTIONID_CLSID_UNION
   clsid           AS GUID   ' CLSID
   ' // for compatibility with the PB headers
   nclsid          AS GUID   ' CLSID
END UNION
' // Size = 20 bytes
TYPE SHDESCRIPTIONID DWORD FILL
   dwDescriptionId AS DWORD   ' DWORD
   SHDESCRIPTIONID_CLSID_UNION
END TYPE
'#include <poppack.h>        /* Return to byte packing */

'// these delegate to IShellFolder2::GetItemData()

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SHGetDataFromIDListA LIB "Shell32.dll" _
    ALIAS "SHGetDataFromIDListA" (psf AS ANY, pidl AS ITEMIDLIST, _
    BYVAL nFormat AS LONG, pv AS ANY, BYVAL cb AS LONG) AS LONG
#ELSE
DECLARE FUNCTION SHGetDataFromIDListA IMPORT "SHELL32.DLL" ALIAS "SHGetDataFromIDListA" ( _
   BYVAL psf AS IShellFolder _                          ' __in IShellFolder *psf
 , BYVAL pidl AS DWORD _                                ' __in PCUITEMID_CHILD pidl
 , BYVAL nFormat AS LONG _                              ' __in int nFormat
 , BYREF pv AS ANY _                                    ' __out PVOID pv
 , BYVAL cb AS LONG _                                   ' __in int cb
 ) AS LONG                                              ' HRESULT
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SHGetDataFromIDListW LIB "Shell32.dll" _
    ALIAS "SHGetDataFromIDListW" (psf AS ANY, pidl AS ITEMIDLIST, _
    BYVAL nFormat AS LONG, pv AS ANY, BYVAL cb AS LONG) AS LONG
#ELSE
DECLARE FUNCTION SHGetDataFromIDListW IMPORT "SHELL32.DLL" ALIAS "SHGetDataFromIDListW" ( _
   BYVAL psf AS IShellFolder _                          ' __in IShellFolder *psf
 , BYVAL pidl AS DWORD _                                ' __in PCUITEMID_CHILD pidl
 , BYVAL nFormat AS LONG _                              ' __in int nFormat
 , BYREF pv AS ANY _                                    ' __out PVOID pv
 , BYVAL cb AS LONG _                                   ' __in int cb
 ) AS LONG                                              ' HRESULT
#ENDIF

#IF %DEF(%UNICODE)
   MACRO SHGetDataFromIDList = SHGetDataFromIDListW
#ELSE
   MACRO SHGetDataFromIDList = SHGetDataFromIDListA
#ENDIF

'//===========================================================================

'// PathResolve flags
%PRF_VERIFYEXISTS            = &H0001???
%PRF_TRYPROGRAMEXTENSIONS    = &H0002??? OR %PRF_VERIFYEXISTS
%PRF_FIRSTDIRDEF             = &H0004???
%PRF_DONTFINDLNK             = &H0008???     ' // if PRF_TRYPROGRAMEXTENSIONS is specified
'#if (NTDDI_VERSION >= NTDDI_WINXPSP2)
%PRF_REQUIREABSOLUTE         = &H0010???
'#endif

DECLARE FUNCTION RestartDialog IMPORT "SHELL32.DLL" ALIAS "RestartDialog" ( _
   BYVAL hParent AS DWORD _                             ' __in HWND hParent
 , BYREF pszPrompt AS WSTRINGZ _                        ' __in LPCWSTR pszPrompt
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 ) AS LONG                                              ' int

DECLARE FUNCTION RestartDialogEx IMPORT "SHELL32.DLL" ALIAS "RestartDialogEx" ( _
   BYVAL hParent AS DWORD _                             ' __in HWND hParent
 , BYREF pszPrompt AS WSTRINGZ _                        ' __in LPCWSTR pszPrompt
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYVAL dwReasonCode AS DWORD _                        ' __in HWND dwReasonCode
 ) AS LONG                                              ' int

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SHCoCreateInstance LIB "Shell32.dll" _
    ALIAS "SHCoCreateInstance" (pszCLSID AS WSTRINGZ, pclsid AS GUID, _
    pUnkOuter AS ANY, riid AS GUID, ppv AS ANY) AS LONG
#ELSE
DECLARE SUB SHCoCreateInstance IMPORT "SHELL32.DLL" ALIAS "SHCoCreateInstance" ( _
   BYREF pszCLSID AS WSTRINGZ _                         ' __in LPCWSTR pszCLSID
 , BYREF pclsid AS GUID _                               ' __in const CLSID *pclsid
 , BYVAL pUnkOuter AS IUnknown _                        ' __in IUnknown *pUnkOuter
 , BYREF riid AS GUID _                                 ' __in REFIID riid
 , BYREF ppv AS ANY _                                   ' __out void **ppv
 )                                                      ' void
#ENDIF

'#if (NTDDI_VERSION >= NTDDI_VISTA)
#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SHCreateDataObject LIB "Shell32.dll" _
    ALIAS "SHCreateDataObject" (pdlFolder AS ITEMIDLIST, _
    BYVAL cidl AS DWORD, BYVAL apidl AS ITEMIDLIST PTR, _
    pdtInner AS ANY, riid AS GUID, ppv AS ANY) AS LONG
#ELSE
DECLARE SUB SHCreateDataObject IMPORT "SHELL32.DLL" ALIAS "SHCreateDataObject" ( _
   BYVAL pidl AS DWORD _                                ' __in PCIDLIST_ABSOLUTE pidlFolder
 , BYVAL cidl AS DWORD _                                ' __in UINT cidl
 , BYVAL apidl AS DWORD _                               ' __in PCUITEMID_CHILD_ARRAY apidl
 , BYVAL pdtInner AS IDataObject _                      ' __in_opt IDataObject *pdtInner
 , BYREF riid AS GUID _                                 ' __in REFIID riid
 , BYREF ppv AS IUnknown _                              ' __out void **ppv
 )                                                      ' void
#ENDIF
'#endif

'// For CallCPLEntry16
'//
'DECLARE_HANDLE(FARPROC16);

' Removed from the Vista SDK.
'DECLARE FUNCTION CallCPLEntry16 IMPORT "SHELL32.DLL" ALIAS "CallCPLEntry16" ( _
'   BYVAL hInst AS DWORD _                               ' __in HINSTANCE hInst
' , BYVAL lpfnEntry AS DWORD _                           ' __in FARPROC16 lpfnEntry
' , BYVAL hwndCPL AS DWORD _                             ' __in HWND hwndCPL
' , BYVAL msg AS DWORD _                                 ' __in UINT msg
' , BYVAL lParam1 AS LONG _                              ' __in LPARAM lParam1
' , BYVAL lParam2 AS LONG _                              ' __in LPARAM lParam2
' ) AS LONG                                              ' int

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION CIDLData_CreateFromIDArray LIB "Shell32.dll" _
    ALIAS "CIDLData_CreateFromIDArray" (pidlFolder AS ITEMIDLIST, _
    BYVAL cidl AS DWORD, BYVAL apidl AS ITEMIDLIST PTR, _
    ppdtobj AS ANY) AS LONG
#ELSE
DECLARE FUNCTION CIDLData_CreateFromIDArray IMPORT "SHELL32.DLL" ALIAS "CIDLData_CreateFromIDArray" ( _
   BYVAL pidl AS DWORD _                                ' __in PCIDLIST_ABSOLUTE pidlFolder
 , BYVAL cidl AS DWORD _                                ' __in UINT cidl
 , BYVAL apidl AS DWORD _                               ' __in PCUIDLIST_RELATIVE_ARRAY apidl
 , BYREF ppdtobj AS IDataObject _                       ' __out IDataObject **ppdtobj
 ) AS LONG                                              ' HRESULT
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SHCreateStdEnumFmtEtc LIB "Shell32.dll" _
    ALIAS "SHCreateStdEnumFmtEtc" (BYVAL cfmt AS DWORD, afmt AS ANY, _
    ppenumFormatEtc AS ANY) AS LONG
#ELSE
DECLARE FUNCTION SHCreateStdEnumFmtEtc IMPORT "SHELL32.DLL" ALIAS "SHCreateStdEnumFmtEtc" ( _
   BYVAL cfmt AS DWORD _                                ' __in UINT cfmt
 , BYREF afmt AS FORMATETC _                            ' __in const FORMATETC afmt[]
 , BYREF ppenumFormatEtc AS IEnumFORMATETC _            ' __out IEnumFORMATETC **ppenumFormatEtc
 ) AS LONG                                              ' HRESULT
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SHDoDragDrop LIB "Shell32.dll" ALIAS "SHDoDragDrop" _
    (BYVAL hwnd AS DWORD, pdata AS ANY, pdsrc AS ANY, _
    BYVAL dwEffect AS DWORD, pdwEffect AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION SHDoDragDrop IMPORT "SHELL32.DLL" ALIAS "SHDoDragDrop" ( _
   BYVAL hwnd AS DWORD _                                ' __in HWND hwnd
 , BYVAL pdtobj AS IDataObject _                        ' __in IDataObject *pdtobj
 , BYVAL pdsrc AS IDropSource _                         ' __in_opt IDropSource *pdsrc
 , BYVAL dwEffect AS DWORD _                            ' __in DWORD dwEffect
 , BYREF pdwEffect AS DWORD _                           ' __out DWORD *pdwEffect
 ) AS LONG                                              ' HRESULT
#ENDIF

'// stuff for doing auto scrolling
%NUM_POINTS = 3
' // Size = 48 bytes
TYPE AUTO_SCROLL_DATA DWORD
   iNextSample               AS LONG    ' int
   dwLastScroll              AS DWORD   ' DWORD
   bFull                     AS LONG    ' BOOL
   pts     (%NUM_POINTS - 1) AS POINT   ' POINT [NUM_POINTS]
   dwTimes (%NUM_POINTS - 1) AS DWORD   ' DWORD [NUM_POINTS]
END TYPE

DECLARE FUNCTION DAD_SetDragImage IMPORT "SHELL32.DLL" ALIAS "DAD_SetDragImage" ( _
   BYVAL him AS DWORD _                                 ' __in HIMAGELIST him
 , BYREF pptOffset AS POINT _                           ' __in POINT *pptOffset
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION DAD_DragEnterEx IMPORT "SHELL32.DLL" ALIAS "DAD_DragEnterEx" ( _
   BYVAL hwnd AS DWORD _                                ' __in HWND hwndTarget
 , BYVAL ptStart AS POINT _                             ' __in const POINT ptStart
 ) AS LONG                                              ' BOOL

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION DAD_DragEnterEx2 LIB "Shell32.dll " ALIAS "DAD_DragEnterEx2" _
    (BYVAL hwndTarget AS DWORD, BYVAL ptStart AS POINT, pdtObject AS ANY) _
    AS LONG
#ELSE
DECLARE FUNCTION DAD_DragEnterEx2 IMPORT "SHELL32.DLL" ALIAS "DAD_DragEnterEx2" ( _
   BYVAL hwnd AS DWORD _                                ' __in HWND hwndTarget
 , BYVAL ptStart AS POINT _                             ' __in const POINT ptStart
 , BYVAL pdtObject AS IDataObject _                     ' __in IDataObject *pdtObject
 ) AS LONG                                              ' BOOL
#ENDIF

DECLARE FUNCTION DAD_ShowDragImage IMPORT "SHELL32.DLL" ALIAS "DAD_ShowDragImage" ( _
   BYVAL fShow AS LONG _                                ' __in BOOL fShow
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION DAD_DragMove IMPORT "SHELL32.DLL" ALIAS "DAD_DragMove" ( _
   BYVAL pt AS POINT _                                  ' __in POINT pt
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION DAD_DragLeave IMPORT "SHELL32.DLL" ALIAS "DAD_DragLeave" () AS LONG

DECLARE FUNCTION DAD_AutoScroll IMPORT "SHELL32.DLL" ALIAS "DAD_AutoScroll" ( _
   BYVAL hwnd AS DWORD _                                ' __in HWND hwnd
 , BYREF pad AS AUTO_SCROLL_DATA _                      ' __in AUTO_SCROLL_DATA *pad
 , BYREF pptNow AS POINT _                              ' __in const POINT *pptNow
 ) AS LONG                                              ' BOOL

' // Size = 12 bytes
TYPE CABINETSTATE BYTE
   cLength                   AS WORD               ' WORD cLength
   nVersion                  AS WORD               ' WORD nVersion
   fFullPathTitle            AS BIT * 1 IN DWORD   ' BOOL fFullPathTitle            : 1
   fSaveLocalView            AS BIT * 1            ' BOOL fSaveLocalView            : 1
   fNotShell                 AS BIT * 1            ' BOOL fNotShell                 : 1
   fSimpleDefault            AS BIT * 1            ' BOOL fSimpleDefault            : 1
   fDontShowDescBar          AS BIT * 1            ' BOOL fDontShowDescBar          : 1
   fNewWindowMode            AS BIT * 1            ' BOOL fNewWindowMode            : 1
   fShowCompColor            AS BIT * 1            ' BOOL fShowCompColor            : 1;  // NT: Show compressed volumes in a different colour
   fDontPrettyNames          AS BIT * 1            ' BOOL fDontPrettyNames          : 1;  // NT: Do 8.3 name conversion, or not!
   fAdminsCreateCommonGroups AS BIT * 1            ' BOOL fAdminsCreateCommonGroups : 1;  // NT: Administrators create comon groups
   fUnusedFlags              AS BIT * 7            ' UINT fUnusedFlags : 7;
   fMenuEnumFilter           AS DWORD              ' UINT fMenuEnumFilter
END TYPE

%CABINETSTATE_VERSION = 2

'// APIs for reading and writing the cabinet state.
DECLARE FUNCTION ReadCabinetState IMPORT "SHELL32.DLL" ALIAS "ReadCabinetState" ( _
   BYREF lpState AS CABINETSTATE _                      ' __in CABINETSTATE *lpState
 , BYVAL cbLength AS LONG _                             ' __in int cbLength
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION WriteCabinetState IMPORT "SHELL32.DLL" ALIAS "WriteCabinetState" ( _
   BYREF lpState AS CABINETSTATE _                      ' __in CABINETSTATE *lpState
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION PathMakeUniqueName IMPORT "SHELL32.DLL" ALIAS "PathMakeUniqueName" ( _
   BYREF pszUniqueName AS WSTRINGZ _                    ' __in LPWSTR pszUniqueName
 , BYVAL cchMax AS DWORD _                              ' __in UINT cchMax
 , BYREF pszTemplate AS WSTRINGZ _                      ' __in LPCWSTR pszTemplate
 , BYREF pszLongPlate AS WSTRINGZ _                     ' __in LPCWSTR pszLongPlate
 , BYREF pszDir AS WSTRINGZ _                           ' __in LPCWSTR pszDir
 ) AS LONG                                              ' BOOL

DECLARE SUB PathQualify IMPORT "SHELL32.DLL" ALIAS "PathQualify" ( _
   BYREF psz AS WSTRINGZ _                              ' LPWSTR psz
 )                                                      ' void

DECLARE FUNCTION PathIsExe IMPORT "SHELL32.DLL" ALIAS "PathIsExe" ( _
   BYREF szfile AS WSTRINGZ _                           ' __in LPCWSTR szfile
 ) AS LONG                                              ' int

DECLARE FUNCTION PathIsSlowA IMPORT "SHELL32.DLL" ALIAS "PathIsSlowA" ( _
   BYREF pszFile AS ASCIIZ _                            ' __in LPCSTR pszFile
 , BYVAL dwAttr AS DWORD _                              ' __in DWORD dwAttr
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION PathIsSlowW IMPORT "SHELL32.DLL" ALIAS "PathIsSlowW" ( _
   BYREF pszFile AS WSTRINGZ _                          ' __in LPCWSTR pszFile
 , BYVAL dwAttr AS DWORD _                              ' __in DWORD dwAttr
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO PathIsSlow = PathIsSlowW
#ELSE
   MACRO PathIsSlow = PathIsSlowA
#ENDIF

'//
'//  Return codes from PathCleanupSpec.  Negative return values are
'//  unrecoverable errors
'//
%PCS_FATAL        = &H80000000???
%PCS_REPLACEDCHAR = &H00000001???
%PCS_REMOVEDCHAR  = &H00000002???
%PCS_TRUNCATED    = &H00000004???
%PCS_PATHTOOLONG  = &H00000008???  ' // Always combined with FATAL

DECLARE FUNCTION PathCleanupSpec IMPORT "SHELL32.DLL" ALIAS "PathCleanupSpec" ( _
   BYREF pszDir AS WSTRINGZ _                           ' __in LPCWSTR pszDir
 , BYREF pszSpec AS WSTRINGZ _                          ' __inout LPWSTR pszSpec
 ) AS LONG                                              ' int

DECLARE FUNCTION PathResolve IMPORT "SHELL32.DLL" ALIAS "PathResolve" ( _
   BYREF pszPath AS WSTRINGZ _                          ' __inout LPWSTR pszPath
 , BYREF dirs AS ANY _                                  ' __in_opt LPCWSTR *dirs
 , BYVAL fFlags AS DWORD _                              ' __in UINT fFlags
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetFileNameFromBrowse IMPORT "SHELL32.DLL" ALIAS "GetFileNameFromBrowse" ( _
   BYVAL hwnd AS DWORD _                                ' __in HWND hwnd
 , BYREF pszFilePath AS WSTRINGZ _                      ' __inout LPWSTR pszFilePath
 , BYVAL cchFilePath AS DWORD _                         ' __in UINT cchFilePath
 , BYREF pszWorkingDir AS WSTRINGZ _                    ' __in LPCWSTR pszWorkingDir
 , BYREF pszDefExt AS WSTRINGZ _                        ' __in LPCWSTR pszDefExt
 , BYREF pszFilters AS WSTRINGZ _                       ' __in LPCWSTR pszFilters
 , BYREF szTitle AS WSTRINGZ _                          ' __in LPCWSTR szTitle
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION DriveType IMPORT "SHELL32.DLL" ALIAS "DriveType" ( _
   BYVAL iDrive AS LONG _                               ' __in int iDrive
 ) AS LONG                                              ' int

DECLARE FUNCTION RealDriveType IMPORT "SHELL32.DLL" ALIAS "RealDriveType" ( _
   BYVAL Drive AS LONG _                                ' __in int Drive
 , BYVAL fOKToHitNe AS LONG _                           ' __in BOOL fOKToHitNe
 ) AS LONG                                              ' int

DECLARE FUNCTION IsNetDrive IMPORT "SHELL32.DLL" ALIAS "IsNetDrive" ( _
   BYVAL iDrive AS LONG _                               ' __in int iDrive
 ) AS LONG                                              ' int

'// Flags for Shell_MergeMenus

%MM_ADDSEPARATOR    = &H00000001???
%MM_SUBMENUSHAVEIDS = &H00000002???
%MM_DONTREMOVESEPS  = &H00000004???

DECLARE FUNCTION Shell_MergeMenus IMPORT "SHELL32.DLL" ALIAS "Shell_MergeMenus" ( _
   BYVAL hmDst AS DWORD _                               ' __in HMENU hmDst
 , BYVAL hmSrc AS DWORD _                               ' __in HMENU hmSrc
 , BYVAL uInsert AS DWORD _                             ' __in UINT uInsert
 , BYVAL uIDAdjust AS DWORD _                           ' __in UINT uIDAdjust
 , BYVAL uIDAdjustMax AS DWORD _                        ' __in UINT uIDAdjustMax
 , BYVAL uFlags AS DWORD _                              ' __in ULONG uFlags
 ) AS DWORD                                             ' UINT


'/*
' * The SHObjectProperties API provides an easy way to invoke
' *   the Properties context menu command on shell objects.
' *
' *   PARAMETERS
' *
' *     hwnd    The window handle of the window which will own the dialog
' *     dwType       A SHOP_ value as defined below
' *     lpObject     Name of the object, see SHOP_ values below
' *     lpPage       The name of the property sheet page to open to or NULL.
' *
' *   RETURN
' *
' *     TRUE if the Properties command was invoked
' */
DECLARE FUNCTION SHObjectProperties IMPORT "SHELL32.DLL" ALIAS "SHObjectProperties" ( _
   BYVAL hwnd AS DWORD _                                ' __in HWND hwnd
 , BYVAL dwType AS DWORD _                              ' __in DWORD dwType
 , BYREF szObject AS WSTRINGZ _                         ' __in LPCWSTR szObject
 , BYREF szPage AS WSTRINGZ _                           ' __in LPCWSTR szPage
 ) AS LONG                                              ' BOOL

%SHOP_PRINTERNAME = &H00000001???  ' // lpObject points to a printer friendly name
%SHOP_FILEPATH    = &H00000002???  ' // lpObject points to a fully qualified path+file name
%SHOP_VOLUMEGUID  = &H00000004???  ' // lpObject points to a Volume GUID

'/*
' * The SHFormatDrive API provides access to the Shell
' *   format dialog. This allows apps which want to format disks
' *   to bring up the same dialog that the Shell does to do it.
' *
' *   This dialog is not sub-classable. You cannot put custom
' *   controls in it. If you want this ability, you will have
' *   to write your own front end for the DMaint_FormatDrive
' *   engine.
' *
' *   NOTE that the user can format as many diskettes in the specified
' *   drive, or as many times, as he/she wishes to. There is no way to
' *   force any specififc number of disks to format. If you want this
' *   ability, you will have to write your own front end for the
' *   DMaint_FormatDrive engine.
' *
' *   NOTE also that the format will not start till the user pushes the
' *   start button in the dialog. There is no way to do auto start. If
' *   you want this ability, you will have to write your own front end
' *   for the DMaint_FormatDrive engine.
' *
' *   PARAMETERS
' *
' *     hwnd    = The window handle of the window which will own the dialog
' *               NOTE that unlike SHCheckDrive, hwnd == NULL does not cause
' *               this dialog to come up as a "top level application" window.
' *               This parameter should always be non-null, this dialog is
' *               only designed to be the child of another window, not a
' *               stand-alone application.
' *     drive   = The 0 based (A: == 0) drive number of the drive to format
' *     fmtID   = The ID of the physical format to format the disk with
' *               NOTE: The special value SHFMT_ID_DEFAULT means "use the
' *                     default format specified by the DMaint_FormatDrive
' *                     engine". If you want to FORCE a particular format
' *                     ID "up front" you will have to call
' *                     DMaint_GetFormatOptions yourself before calling
' *                     this to obtain the valid list of phys format IDs
' *                     (contents of the PhysFmtIDList array in the
' *                     FMTINFOSTRUCT).
' *     options = There is currently only two option bits defined
' *
' *                SHFMT_OPT_FULL
' *                SHFMT_OPT_SYSONLY
' *
' *               The normal defualt in the Shell format dialog is
' *               "Quick Format", setting this option bit indicates that
' *               the caller wants to start with FULL format selected
' *               (this is useful for folks detecting "unformatted" disks
' *               and wanting to bring up the format dialog).
' *
' *               The SHFMT_OPT_SYSONLY initializes the dialog to
' *               default to just sys the disk.
' *
' *               All other bits are reserved for future expansion and
' *               must be 0.
' *
' *               Please note that this is a bit field and not a value
' *               and treat it accordingly.
' *
' *   RETURN
' *      The return is either one of the SHFMT_* values, or if the
' *      returned DWORD value is not == to one of these values, then
' *      the return is the physical format ID of the last succesful
' *      format. The LOWORD of this value can be passed on subsequent
' *      calls as the fmtID parameter to "format the same type you did
' *      last time".
' *
' */
DECLARE FUNCTION SHFormatDrive IMPORT "SHELL32.DLL" ALIAS "SHFormatDrive" ( _
   BYVAL hwnd AS DWORD _                                ' __in HWND hwnd
 , BYVAL drive AS DWORD _                               ' __in UINT drive
 , BYVAL fmtID AS DWORD _                               ' __in UINT fmtID
 , BYVAL options AS DWORD _                             ' __in UINT options
 ) AS DWORD                                             ' DWORD

'//
'// Special value of fmtID which means "use the default format"
'//
%SHFMT_ID_DEFAULT    = &HFFFF???

'//
'// Option bits for options parameter
'//
%SHFMT_OPT_FULL     = &H0001???
%SHFMT_OPT_SYSONLY  = &H0002???

'//
'// Special return values. PLEASE NOTE that these are DWORD values.
'//
%SHFMT_ERROR     = &HFFFFFFFF???     ' // Error on last format, drive may be formatable
%SHFMT_CANCEL    = &HFFFFFFFE???     ' // Last format was canceled
%SHFMT_NOFORMAT  = &HFFFFFFFD???     ' // Drive is not formatable

'#ifndef HPSXA_DEFINED
'#define HPSXA_DEFINED
'DECLARE_HANDLE( HPSXA );
'#endif

DECLARE FUNCTION SHCreatePropSheetExtArray IMPORT "SHELL32.DLL" ALIAS "SHCreatePropSheetExtArray" ( _
   BYVAL hkey AS DWORD _                                ' __in HKEY hkey
 , BYREF pszSubkey AS WSTRINGZ _                        ' __in LPCWSTR pszSubkey
 , BYVAL max_iface AS DWORD _                           ' __in UINT max_iface
 ) AS DWORD                                             ' HPSXA

DECLARE SUB SHDestroyPropSheetExtArray IMPORT "SHELL32.DLL" ALIAS "SHDestroyPropSheetExtArray" ( _
   BYVAL hpsxa AS DWORD _                               ' __in HPSXA hpsxa
 )                                                      ' void

DECLARE FUNCTION SHAddFromPropSheetExtArray IMPORT "SHELL32.DLL" ALIAS "SHAddFromPropSheetExtArray" ( _
   BYVAL hpsxa AS DWORD _                               ' __in HPSXA hpsxa
 , BYVAL lpfnAddPage AS DWORD _                         ' __in LPFNADDPROPSHEETPAGE lpfnAddPage
 , BYVAL lParam AS LONG _                               ' __in LPARAM lParam
 ) AS DWORD                                             ' UINT

DECLARE FUNCTION SHReplaceFromPropSheetExtArray IMPORT "SHELL32.DLL" ALIAS "SHReplaceFromPropSheetExtArray" ( _
   BYVAL hpsxa AS DWORD _                               ' __in HPSXA hpsxa
 , BYVAL uPageID AS DWORD _                             ' __in UINT uPageID
 , BYVAL lpfnReplaceWith AS DWORD _                     ' __in LPFNADDPROPSHEETPAGE lpfnReplaceWith
 , BYVAL lParam AS LONG _                               ' __in LPARAM lParam
 ) AS DWORD                                             ' UINT

' Deprecated. Removed from the Windows 7 SDK.
'DECLARE FUNCTION ILLoadFromStream IMPORT "SHELL32.DLL" ALIAS "ILLoadFromStream" ( _
'   BYVAL pstm AS IStream _                              ' __in IStream *pstm
' , BYREF pidl AS ANY _                                  ' __inout PIDLIST_RELATIVE *pidl
' ) AS LONG                                              ' HRESULT


'#if (NTDDI_VERSION >= NTDDI_WIN2K && NTDDI_VERSION < NTDDI_VISTA)

' ########################################################################################
' IDefViewFrame interface
' IID = 710EB7A0-45ED-11D0-924A-0020AFC7AC4D
' Inherited interface = IUnknown
' Minimum operating system: Windows 2000
' IDefViewFrame is used only for its IUnknown functionality. It has no methods of its own.
' The interface identifier (IID) for this interface is IID_IDefViewFrame. Use the service
' ID SID_DefView (defined in shlguid.h) in a call to QueryService as shown in this example.
' HRESULT hr = isp->QueryService(punkSite, SID_DefView, IID_IDefViewFrame, (void**)&pdvf);
' ########################################################################################

#IF NOT %DEF(%IDefViewFrame_INTERFACE_DEFINED)
    %IDefViewFrame_INTERFACE_DEFINED = 1

INTERFACE IDefViewFrame $IID_IDefViewFrame

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetWindowLV ( _                               ' VTable offset = 12
     BYREF phwnd AS DWORD _                             ' __out HWND * phwnd
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ReleaseWindowLV ( _                           ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetShellFolder ( _                            ' VTable offset = 20
     BYREF ppsf AS IShellFolder _                       ' __out IShellFolder **ppsf
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDefViewFrame_INTERFACE_DEFINED__ */

'#endif


'//===========================================================================
'// shell restriction values, parameter for SHRestricted()
' RESTRICTIONS enum
%REST_NONE                       = &H00000000???
%REST_NORUN                      = &H00000001???
%REST_NOCLOSE                    = &H00000002???
%REST_NOSAVESET                  = &H00000004???
%REST_NOFILEMENU                 = &H00000008???
%REST_NOSETFOLDERS               = &H00000010???
%REST_NOSETTASKBAR               = &H00000020???
%REST_NODESKTOP                  = &H00000040???
%REST_NOFIND                     = &H00000080???
%REST_NODRIVES                   = &H00000100???
%REST_NODRIVEAUTORUN             = &H00000200???
%REST_NODRIVETYPEAUTORUN         = &H00000400???
%REST_NONETHOOD                  = &H00000800???
%REST_STARTBANNER                = &H00001000???
%REST_RESTRICTRUN                = &H00002000???
%REST_NOPRINTERTABS              = &H00004000???
%REST_NOPRINTERDELETE            = &H00008000???
%REST_NOPRINTERADD               = &H00010000???
%REST_NOSTARTMENUSUBFOLDERS      = &H00020000???
%REST_MYDOCSONNET                = &H00040000???
%REST_NOEXITTODOS                = &H00080000???
%REST_ENFORCESHELLEXTSECURITY    = &H00100000???
%REST_LINKRESOLVEIGNORELINKINFO  = &H00200000???
%REST_NOCOMMONGROUPS             = &H00400000???
%REST_SEPARATEDESKTOPPROCESS     = &H00800000???
%REST_NOWEB                      = &H01000000???
%REST_NOTRAYCONTEXTMENU          = &H02000000???
%REST_NOVIEWCONTEXTMENU          = &H04000000???
%REST_NONETCONNECTDISCONNECT     = &H08000000???
%REST_STARTMENULOGOFF            = &H10000000???
%REST_NOSETTINGSASSIST           = &H20000000???
%REST_NOINTERNETICON             = &H40000001???
%REST_NORECENTDOCSHISTORY        = &H40000002???
%REST_NORECENTDOCSMENU           = &H40000003???
%REST_NOACTIVEDESKTOP            = &H40000004???
%REST_NOACTIVEDESKTOPCHANGES     = &H40000005???
%REST_NOFAVORITESMENU            = &H40000006???
%REST_CLEARRECENTDOCSONEXIT      = &H40000007???
%REST_CLASSICSHELL               = &H40000008???
%REST_NOCUSTOMIZEWEBVIEW         = &H40000009???
%REST_NOHTMLWALLPAPER            = &H40000010???
%REST_NOCHANGINGWALLPAPER        = &H40000011???
%REST_NODESKCOMP                 = &H40000012???
%REST_NOADDDESKCOMP              = &H40000013???
%REST_NODELDESKCOMP              = &H40000014???
%REST_NOCLOSEDESKCOMP            = &H40000015???
%REST_NOCLOSE_DRAGDROPBAND       = &H40000016???
%REST_NOMOVINGBAND               = &H40000017???
%REST_NOEDITDESKCOMP             = &H40000018???
%REST_NORESOLVESEARCH            = &H40000019???
%REST_NORESOLVETRACK             = &H4000001A???
%REST_FORCECOPYACLWITHFILE       = &H4000001B???
%REST_NOLOGO3CHANNELNOTIFY       = &H4000001C???
%REST_NOFORGETSOFTWAREUPDATE     = &H4000001D???
%REST_NOSETACTIVEDESKTOP         = &H4000001E???
%REST_NOUPDATEWINDOWS            = &H4000001F???
%REST_NOCHANGESTARMENU           = &H40000020???
%REST_NOFOLDEROPTIONS            = &H40000021???
%REST_HASFINDCOMPUTERS           = &H40000022???
%REST_INTELLIMENUS               = &H40000023???
%REST_RUNDLGMEMCHECKBOX          = &H40000024???
%REST_ARP_ShowPostSetup          = &H40000025???
%REST_NOCSC                      = &H40000026???
%REST_NOCONTROLPANEL             = &H40000027???
%REST_ENUMWORKGROUP              = &H40000028???
%REST_ARP_NOARP                  = &H40000029???
%REST_ARP_NOREMOVEPAGE           = &H4000002A???
%REST_ARP_NOADDPAGE              = &H4000002B???
%REST_ARP_NOWINSETUPPAGE         = &H4000002C???
%REST_GREYMSIADS                 = &H4000002D???
%REST_NOCHANGEMAPPEDDRIVELABEL   = &H4000002E???
%REST_NOCHANGEMAPPEDDRIVECOMMENT = &H4000002F???
%REST_MaxRecentDocs              = &H40000030???
%REST_NONETWORKCONNECTIONS       = &H40000031???
%REST_FORCESTARTMENULOGOFF       = &H40000032???
%REST_NOWEBVIEW                  = &H40000033???
%REST_NOCUSTOMIZETHISFOLDER      = &H40000034???
%REST_NOENCRYPTION               = &H40000035???
' Do not use me                  = &H40000036???
%REST_DONTSHOWSUPERHIDDEN        = &H40000037???
%REST_NOSHELLSEARCHBUTTON        = &H40000038???
%REST_NOHARDWARETAB              = &H40000039???
%REST_NORUNASINSTALLPROMPT       = &H4000003A???
%REST_PROMPTRUNASINSTALLNETPATH  = &H4000003B???
%REST_NOMANAGEMYCOMPUTERVERB     = &H4000003C???
%REST_NORECENTDOCSNETHOOD        = &H4000003D???
%REST_DISALLOWRUN                = &H4000003E???
%REST_NOWELCOMESCREEN            = &H4000003F???
%REST_RESTRICTCPL                = &H40000040???
%REST_DISALLOWCPL                = &H40000041???
%REST_NOSMBALLOONTIP             = &H40000042???
%REST_NOSMHELP                   = &H40000043???
%REST_NOWINKEYS                  = &H40000044???
%REST_NOENCRYPTONMOVE            = &H40000045???
%REST_NOLOCALMACHINERUN          = &H40000046???
%REST_NOCURRENTUSERRUN           = &H40000047???
%REST_NOLOCALMACHINERUNONCE      = &H40000048???
%REST_NOCURRENTUSERRUNONCE       = &H40000049???
%REST_FORCEACTIVEDESKTOPON       = &H4000004A???
'%REST_NOCOMPUTERSNEARME          = &H4000004B???
' Do not use me                  = &H4000004B???
%REST_NOVIEWONDRIVE              = &H4000004C???
'#if (NTDDI_VERSION >= NTDDI_WINXP) || defined(IE_BACKCOMPAT_VERSION)
%REST_NONETCRAWL                 = &H4000004D???
%REST_NOSHAREDDOCUMENTS          = &H4000004E???
'#endif  // NTDDI_WINXP
'#if (NTDDI_VERSION >= NTDDI_WINXP)
%REST_NOSMMYDOCS                 = &H4000004F???
%REST_NOSMMYPICS                 = &H40000050???
%REST_ALLOWBITBUCKDRIVES         = &H40000051???
%REST_NONLEGACYSHELLMODE         = &H40000052???
%REST_NOCONTROLPANELBARRICADE    = &H40000053???
%REST_NOSTARTPAGE                = &H40000054???
%REST_NOAUTOTRAYNOTIFY           = &H40000055???
%REST_NOTASKGROUPING             = &H40000056???
%REST_NOCDBURNING                = &H40000057???
'#endif  // NTDDI_WINXP
'#if (NTDDI_VERSION >= NTDDI_WIN2KSP3)
%REST_MYCOMPNOPROP               = &H40000058???
%REST_MYDOCSNOPROP               = &H40000059???
'#endif  // NTDDI_WIN2KSP3
'#if (NTDDI_VERSION >= NTDDI_WINXP)
%REST_NOSTARTPANEL               = &H4000005A???
%REST_NODISPLAYAPPEARANCEPAGE    = &H4000005B???
%REST_NOTHEMESTAB                = &H4000005C???
%REST_NOVISUALSTYLECHOICE        = &H4000005D???
%REST_NOSIZECHOICE               = &H4000005E???
%REST_NOCOLORCHOICE              = &H4000005F???
%REST_SETVISUALSTYLE             = &H40000060???
'#endif  // NTDDI_WINXP
'#if (NTDDI_VERSION >= NTDDI_WIN2KSP3)
%REST_STARTRUNNOHOMEPATH         = &H40000061???
'#endif  // NTDDI_WIN2KSP3
'#if (NTDDI_VERSION >= NTDDI_WINXP)
%REST_NOUSERNAMEINSTARTPANEL     = &H40000062???
%REST_NOMYCOMPUTERICON           = &H40000063???
%REST_NOSMNETWORKPLACES          = &H40000064???
%REST_NOSMPINNEDLIST             = &H40000065???
%REST_NOSMMYMUSIC                = &H40000066???
%REST_NOSMEJECTPC                = &H40000067???
%REST_NOSMMOREPROGRAMS           = &H40000068???
%REST_NOSMMFUPROGRAMS            = &H40000069???
%REST_NOTRAYITEMSDISPLAY         = &H4000006A???
%REST_NOTOOLBARSONTASKBAR        = &H4000006B???
'#endif  // NTDDI_WINXP
'#if (NTDDI_VERSION >= NTDDI_WIN2KSP3)
%REST_NOSMCONFIGUREPROGRAMS      = &H4000006F???
'#endif  // NTDDI_WIN2KSP3
'#if (NTDDI_VERSION >= NTDDI_WINXP)
%REST_HIDECLOCK                  = &H40000070???
%REST_NOLOWDISKSPACECHECKS       = &H40000071???
'#endif  // NTDDI_WINXP
'#if (NTDDI_VERSION >= NTDDI_WIN2KSP4)
%REST_NOENTIRENETWORK            = &H40000072???
'#endif  // NTDDI_WIN2KSP4
'#if (NTDDI_VERSION >= NTDDI_WINXP)
%REST_NODESKTOPCLEANUP           = &H40000073???
%REST_BITBUCKNUKEONDELETE        = &H40000074???
%REST_BITBUCKCONFIRMDELETE       = &H40000075???
%REST_BITBUCKNOPROP              = &H40000076???
%REST_NODISPBACKGROUND           = &H40000077???
%REST_NODISPSCREENSAVEPG         = &H40000078???
%REST_NODISPSETTINGSPG           = &H40000079???
%REST_NODISPSCREENSAVEPREVIEW    = &H4000007A???
%REST_NODISPLAYCPL               = &H4000007B???
%REST_HIDERUNASVERB              = &H4000007C???
%REST_NOTHUMBNAILCACHE           = &H4000007D???
'#endif  // NTDDI_WINXP
'#if (NTDDI_VERSION >= NTDDI_WINXPSP1) || defined(IE_BACKCOMPAT_VERSION)
%REST_NOSTRCMPLOGICAL            = &H4000007E???
%REST_NOPUBLISHWIZARD            = &H4000007F???  ' // disables publishing wizard (WPW)
%REST_NOONLINEPRINTSWIZARD       = &H40000080???  ' // disables online prints wizard (OPW)
%REST_NOWEBSERVICES              = &H40000081???  ' // disables the web specified services for both OPW and WPW
'#endif  // NTDDI_WINXPSP1
'#if (NTDDI_VERSION >= NTDDI_WIN2KSP3)
%REST_ALLOWUNHASHEDWEBVIEW       = &H40000082???
'#endif  // NTDDI_WIN2KSP3
%REST_ALLOWLEGACYWEBVIEW         = &H40000083???
'#if (NTDDI_VERSION >= NTDDI_WIN2KSP3)
%REST_REVERTWEBVIEWSECURITY      = &H40000084???
'#endif  // NTDDI_WIN2KSP3
'#if (NTDDI_VERSION >= NTDDI_WIN2KSP4)
%REST_INHERITCONSOLEHANDLES      = &H40000086???
'#endif  // NTDDI_WIN2KSP4
'#if (NTDDI_VERSION >= NTDDI_WINXPSP2 && NTDDI_VERSION < NTDDI_VISTA)
%REST_NODISCONNECT               = &H41000001???
%REST_NOSECURITY                 = &H41000002???
%REST_NOFILEASSOCIATE            = &H41000003???
%REST_SORTMAXITEMCOUNT           = &H40000087???  ' // Do not sort views with more items than this key. Useful for viewing big amount of files in one folder.
'#endif
'#if (NTDDI_VERSION >= NTDDI_WINXPSP2)
%REST_NOREMOTERECURSIVEEVENTS    = &H40000089???  ' // Dont register network change events recursively to avoid network traffic
'#endif  // NTDDI_WINXPSP2
'#if (NTDDI_VERSION >= NTDDI_WINXPSP2)
%REST_NOREMOTECHANGENOTIFY       = &H40000091???  ' // Do not notify for remote changy notifies
'#if (NTDDI_VERSION < NTDDI_VISTA)
%REST_NOSIMPLENETIDLIST          = &H40000092???  ' // No simple network IDLists
'#endif
%REST_NOENUMENTIRENETWORK        = &H40000093???  ' // Don't enumerate entire network if we happen to get to it (in conjunction with REST_NOENTIRENETWORK)
'#if (NTDDI_VERSION < NTDDI_VISTA)
%REST_NODETAILSTHUMBNAILONNETWORK= &H40000094???  ' // Disable Thumbnail for Network files in DUI Details pane
'#endif
%REST_NOINTERNETOPENWITH         = &H40000095???  ' // dont allow looking on the internet for file associations
'#endif  // NTDDI_WINXPSP2
'#if (NTDDI_VERSION >= NTDDI_WINXPSP2)
'%REST_ALLOWLEGACYLMZBEHAVIOR     = &H4000009A???  ' Removed from Vista SDK // allowable LMZ behavior for ActiveX objects changed in XPSP2, this policy gets the pre-XPSP2 behavior
%REST_DONTRETRYBADNETNAME        = &H4000009B???  ' // In Network Places: if provider returns ERROR_BAD_NET_NAME, give up
%REST_ALLOWFILECLSIDJUNCTIONS    = &H4000009C???  ' // re-enable legacy support for file.{guid} junctions in FileSystem Folder
%REST_NOUPNPINSTALL              = &H4000009D???  ' // disable "install UPnP" task in My Net Places
'#endif  // NTDDI_WINXPSP2
%REST_ARP_DONTGROUPPATCHES       = &H400000AC???  ' //List individual patches in Add/Remove Programs
%REST_ARP_NOCHOOSEPROGRAMSPAGE   = &H400000AD???  ' //Choose programs page
%REST_NODISCONNECT               = &H41000001???  ' // No Disconnect option in Start menu
%REST_NOSECURITY                 = &H41000002???  ' // No Security option in start menu
%REST_NOFILEASSOCIATE            = &H41000003???  ' // Do not allow user to change file association
'#if (NTDDI_VERSION >= NTDDI_WINXPSP2)
%REST_ALLOWCOMMENTTOGGLE         = &H41000004???  ' // Allow the user to toggle the positions of the Comment and the Computer Name
'#if (NTDDI_VERSION < NTDDI_VISTA)
%REST_USEDESKTOPINICACHE         = &H41000005???  ' // Cache desktop.ini entries from network folders
'#endif  // NTDDI_VISTA
'#endif  // NTDDI_WINXPSP2

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION OpenRegStream LIB "Shell32.dll" ALIAS "OpenRegStream" _
    (BYVAL hkey AS DWORD, pszSubkey AS WSTRINGZ, pszValue AS WSTRINGZ, _
    BYVAL grfMode AS DWORD) AS DWORD
#ELSE
DECLARE FUNCTION OpenRegStream IMPORT "SHELL32.DLL" ALIAS "OpenRegStream" ( _
   BYVAL hkey AS DWORD _                                ' __in HKEY hkey
 , BYREF pszSubkey AS WSTRINGZ _                        ' __in LPCWSTR pszSubkey
 , BYREF pszValue AS WSTRINGZ _                         ' __in LPCWSTR pszValue
 , BYVAL grfMode AS DWORD _                             ' __in DWORD grfMode
 ) AS IStream                                           ' IStream
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SHFindFiles LIB "Shell32.dll" ALIAS "SHFindFiles" _
    (pidlFolder AS ITEMIDLIST, pidlSaveFile AS ITEMIDLIST) AS LONG
#ELSE
DECLARE FUNCTION SHFindFiles IMPORT "SHELL32.DLL" ALIAS "SHFindFiles" ( _
   OPTIONAL BYVAL pidlFolder AS DWORD _                 ' __in_opt PCIDLIST_ABSOLUTE pidlFolder
 , OPTIONAL BYVAL pidlSaveFile AS DWORD _               ' __in_opt PCIDLIST_ABSOLUTE pidlSaveFile
 ) AS LONG                                              ' BOOL
#ENDIF

DECLARE SUB PathGetShortPath IMPORT "SHELL32.DLL" ALIAS "PathGetShortPath" ( _
   BYREF pszLongPath AS WSTRINGZ _                      ' __inout LPWSTR pszLongPath
 )                                                      ' void

DECLARE FUNCTION PathYetAnotherMakeUniqueName IMPORT "SHELL32.DLL" ALIAS "PathYetAnoterMakeUniqueName" ( _
   BYREF pszUniqueName AS WSTRINGZ _                    ' __in LPWSTR pszUniqueName
 , BYREF pszPath AS WSTRINGZ _                          ' __in LPCWSTR pszPath
 , BYREF pszShort AS WSTRINGZ _                         ' __in LPCWSTR pszShort
 , BYREF pszFileSpec AS WSTRINGZ _                      ' __in LPCWSTR pszFileSpec
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION Win32DeleteFile IMPORT "SHELL32.DLL" ALIAS "Win32DeleteFile" ( _
   BYREF pszFileName AS WSTRINGZ _                      ' __in LPCWSTR pszFileName
 ) AS LONG                                              ' BOOL

'#if (NTDDI_VERSION < NTDDI_VISTA)
'//
'// Path processing function
'//
%PPCF_ADDQUOTES              = &H00000001???        ' // return a quoted name if required
%PPCF_ADDARGUMENTS           = &H00000003???        ' // appends arguments (and wraps in quotes if required)
%PPCF_NODIRECTORIES          = &H00000010???        ' // don't match to directories
%PPCF_FORCEQUALIFY           = &H00000040???        ' // qualify even non-relative names
%PPCF_LONGESTPOSSIBLE        = &H00000080???        ' // always find the longest possible name

DECLARE FUNCTION PathProcessCommand IMPORT "SHELL32.DLL" ALIAS "PathProcessCommand" ( _
   BYREF lpSrc AS WSTRINGZ _                            ' __in LPCWSTR lpSrc
 , BYREF lpDest AS WSTRINGZ _                           ' __in LPWSTR lpDest
 , BYVAL iDestMax AS LONG _                             ' __in int iDestMax
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 ) AS LONG                                              ' LONG
'#endif

DECLARE FUNCTION SHRestricted IMPORT "SHELL32.DLL" ALIAS "SHRestricted" ( _
   BYVAL rest AS DWORD _                              ' __in RESTRICTIONS rest
 ) AS DWORD                                             ' DWORD

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SignalFileOpen LIB "Shell32.dll" ALIAS "SignalFileOpen" _
    (pidl AS ITEMIDLIST) AS LONG
#ELSE
DECLARE FUNCTION SignalFileOpen IMPORT "SHELL32.DLL" ALIAS "SignalFileOpen" ( _
   BYVAL pidl AS DWORD _                                ' __in PCIDLIST_ABSOLUTE pidl
 ) AS LONG                                              ' BOOL
#ENDIF

' Prior to Windows 7, this function was declared in Shlobj.h. In Windows 7 and later versions, it is declared in Shobjidl.h.
'DECLARE FUNCTION SHSimpleIDListFromPath IMPORT "SHELL32.DLL" ALIAS "SHSimpleIDListFromPath" ( _
'   BYREF pszPath AS WSTRINGZ _                          ' __in LPCWSTR pszPath
' ) AS DWORD                                             ' PIDLIST_ABSOLUTE

'#if (NTDDI_VERSION >= NTDDI_VISTA)
#IF %DEF(%USEPBDECL)
DECLARE FUNCTION AssocGetDetailsOfPropKey LIB "Shell32.dll" _
    ALIAS "AssocGetDetailsOfPropKey" (psf AS ANY, pidl AS ITEMIDLIST, _
    pkey AS PROPERTYKEY, pv AS VARIANT, pfFoundPropKey AS LONG) AS LONG
#ELSE
DECLARE FUNCTION AssocGetDetailsOfPropKey IMPORT "SHELL32.DLL" ALIAS "AssocGetDetailsOfPropKey" ( _
   BYVAL psf AS IShellFolder _                          ' __in IShellFolder *psf
 , BYVAL pidl AS DWORD _                                ' __in PCUITEMID_CHILD pidl
 , BYREF pkey AS PROPERTYKEY _                          ' __in const PROPERTYKEY *pkey
 , BYREF pv AS VARIANT _                                ' __out VARIANT *pv
 , BYREF pfFoundPropKey AS LONG _                       ' __out_opt BOOL *pfFoundPropKey
 ) AS LONG                                              ' HRESULT
#ENDIF
'#endif

'#if (NTDDI_VERSION < NTDDI_VISTA)
DECLARE FUNCTION SHLoadOle IMPORT "SHELL32.DLL" ALIAS "SHLoadOle" ( _
   BYVAL lParam AS LONG _                               ' __in LPARAM lParam
 ) AS LONG                                              ' HRESULT
'#endif

DECLARE FUNCTION SHStartNetConnectionDialogA IMPORT "SHELL32.DLL" ALIAS "SHStartNetConnectionDialogA" ( _
   BYVAL hwnd AS DWORD _                                ' __in HWND hwnd
 , BYREF pszRemoteName AS ASCIIZ _                      ' __in LPCSTR pszRemoteName
 , BYVAL dwType AS DWORD _                              ' __in DWORD dwType
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION SHStartNetConnectionDialogW IMPORT "SHELL32.DLL" ALIAS "SHStartNetConnectionDialogW" ( _
   BYVAL hwnd AS DWORD _                                ' __in HWND hwnd
 , BYREF pszRemoteName AS WSTRINGZ _                    ' __in LPCWSTR pszRemoteName
 , BYVAL dwType AS DWORD _                              ' __in DWORD dwType
 ) AS LONG                                              ' HRESULT

#IF %DEF(%UNICODE)
   MACRO SHStartNetConnectionDialog = SHStartNetConnectionDialogW
#ELSE
   MACRO SHStartNetConnectionDialog = SHStartNetConnectionDialogA
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SHDefExtractIconA LIB "Shell32.dll" _
    ALIAS "SHDefExtractIconA" (pszIconFile AS ASCIIZ, BYVAL iIndex AS LONG, _
    BYVAL uFlags AS DWORD, phiconLarge AS DWORD, phiconSmall AS DWORD, _
    BYVAL nIconSize AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION SHDefExtractIconA IMPORT "SHELL32.DLL" ALIAS "SHDefExtractIconA" ( _
   BYREF pszIconFile AS ASCIIZ _                        ' __in LPCSTR pszIconFile
 , BYVAL iIndex AS LONG _                               ' __in int iIndex
 , BYVAL uFlags AS DWORD _                              ' __in UINT uFlags
 , BYREF phiconLarge AS DWORD _                         ' __out HICON *phiconLarge
 , BYREF phiconSmall AS DWORD _                         ' __out HICON *phiconSmall
 , BYREF nIconSize AS DWORD _                           ' __out UINT nIconSize
 ) AS LONG                                              ' HRESULT
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SHDefExtractIconW LIB "Shell32.dll" _
    ALIAS "SHDefExtractIconW" (pszIconFile AS WSTRINGZ, BYVAL iIndex AS LONG, _
    BYVAL uFlags AS DWORD, phiconLarge AS DWORD, phiconSmall AS DWORD, _
    BYVAL nIconSize AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION SHDefExtractIconW IMPORT "SHELL32.DLL" ALIAS "SHDefExtractIconW" ( _
   BYREF pszIconFile AS WSTRINGZ _                      ' __in LPCWSTR pszIconFile
 , BYVAL iIndex AS LONG _                               ' __in int iIndex
 , BYVAL uFlags AS DWORD _                              ' __in UINT uFlags
 , BYREF phiconLarge AS DWORD _                         ' __out HICON *phiconLarge
 , BYREF phiconSmall AS DWORD _                         ' __out HICON *phiconSmall
 , BYREF nIconSize AS DWORD _                           ' __out UINT nIconSize
 ) AS LONG                                              ' HRESULT
#ENDIF

#IF %DEF(%UNICODE)
   MACRO SHDefExtractIcon = SHDefExtractIconW
#ELSE
   MACRO SHDefExtractIcon = SHDefExtractIconA
#ENDIF

'// Elevation

'// OpenAsInfo flags
' enum tagOPEN_AS_INFO_FLAGS
%OAIF_ALLOW_REGISTRATION = &H00000001???    ' // enable the "always use this file" checkbox (NOTE if you don't pass this, it will be disabled)
%OAIF_REGISTER_EXT       = &H00000002???    ' // do the registration after the user hits "ok"
%OAIF_EXEC               = &H00000004???    ' // execute file after registering
%OAIF_FORCE_REGISTRATION = &H00000008???    ' // force the "always use this file" checkbox to be checked (normally, you won't use the OAIF_ALLOW_REGISTRATION when you pass this)
'#if (NTDDI_VERSION >= NTDDI_VISTA)
%OAIF_HIDE_REGISTRATION  = &H00000020???    ' // hide the "always use this file" checkbox
%OAIF_URL_PROTOCOL       = &H00000040???    ' // the "extension" passed is actually a protocol, and open with should show apps registered as capable of handling that protocol
'#endif
'typedef int OPEN_AS_INFO_FLAGS;

'#include <pshpack8.h>

' // Size = 12 bytes
TYPE OPENASINFO DWORD FILL
   pcszFile    AS WSTRINGZ PTR    ' LPCWSTR // [in] file name, or protocol name if
                                  '         //      OAIF_URL_PROTOCOL is set.
   pcszClass   AS WSTRINGZ PTR    ' LPCWSTR // [in] file class description. NULL means
                                  '         //      use pcszFile's extension. ignored
                                  '         //      if OAIF_URL_PROTOCOL is set.
   oaifInFlags AS DWORD           ' OPEN_AS_INFO_FLAGS // [in] input flags from OPEN_AS_INFO_FLAGS enumeration
END TYPE

'#include <poppack.h>        /* Return to byte packing */

'#if (NTDDI_VERSION >= NTDDI_VISTA)
DECLARE FUNCTION SHOpenWithDialog IMPORT "SHELL32.DLL" ALIAS "SHOpenWithDialog" ( _
   BYVAL hwnd AS DWORD _                                ' __in_opt HWND hwndParent
 , BYREF poainfo AS OPENASINFO _                        ' __in const OPENASINFO* poainfo
 ) AS LONG                                              ' HRESULT
'#endif // NTDDI_VISTA

DECLARE FUNCTION Shell_GetImageLists IMPORT "SHELL32.DLL" ALIAS "Shell_GetImageLists" ( _
   BYREF phiml AS DWORD _                               ' __in HIMAGELIST *phiml
 , BYREF phimlSmall AS DWORD _                          ' __in HIMAGELIST *phimlSmall
 ) AS LONG                                              ' BOOL

#IF (%NTDDI_VERSION < %NTDDI_VISTA)

DECLARE FUNCTION Shell_GetCachedImageIndex IMPORT "SHELL32.DLL" ALIAS "Shell_GetCachedImageIndex" ( _
   BYREF pszIconPath AS WSTRINGZ _                      ' __in LPCWSTR pszIconPath
 , BYVAL iIconIndex AS LONG _                           ' __in int iIconIndex
 , BYVAL uIconFlags AS DWORD _                          ' __in UINT uIconFlags
 ) AS LONG                                              ' int

#ELSE

' The Shell_GetCachedImageIndexA and Shell_GetCachedImageIndexW versions of this
' function are new for Windows Vista. Previous versions supported
' Shell_GetCachedImageIndex only, which takes a Unicode string.

DECLARE FUNCTION Shell_GetCachedImageIndexA IMPORT "SHELL32.DLL" ALIAS "Shell_GetCachedImageIndexA" ( _
   BYREF pszIconPath AS ASCIIZ _                        ' __in LPCSTR pszIconPath
 , BYVAL iIconIndex AS LONG _                           ' __in int iIconIndex
 , BYVAL uIconFlags AS DWORD _                          ' __in UINT uIconFlags
 ) AS LONG                                              ' int

DECLARE FUNCTION Shell_GetCachedImageIndexW IMPORT "SHELL32.DLL" ALIAS "Shell_GetCachedImageIndexW" ( _
   BYREF pszIconPath AS WSTRINGZ _                      ' __in LPCWSTR pszIconPath
 , BYVAL iIconIndex AS LONG _                           ' __in int iIconIndex
 , BYVAL uIconFlags AS DWORD _                          ' __in UINT uIconFlags
 ) AS LONG                                              ' int

#IF %DEF(%UNICODE)
   MACRO Shell_GetCachedImageIndex = Shell_GetCachedImageIndexW
#ELSE
   MACRO Shell_GetCachedImageIndex = Shell_GetCachedImageIndexA
#ENDIF

#ENDIF

'//
'// IDocViewSite
'//
' ########################################################################################
' IDocViewSite interface
' IID = 87D605E0-C511-11CF-89A9-00A0C9054129
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDocViewSite_INTERFACE_DEFINED)
    %IDocViewSite_INTERFACE_DEFINED = 1

INTERFACE IDocViewSite $IID_IDocViewSite

   INHERIT IUnknown

   ' =====================================================================================
   METHOD OnSetTitle ( _                                ' VTable offset = 12
     BYREF pvTitle AS VARIANT _                         ' VARIANTARG *pvTitle
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDocViewSite_INTERFACE_DEFINED__ */

%VALIDATEUNC_CONNECT  = &H0001???          ' // connect a drive letter
%VALIDATEUNC_NOUI     = &H0002???          ' // don't bring up UI
%VALIDATEUNC_PRINT    = &H0004???          ' // validate as print share instead of disk share
'#if (NTDDI_VERSION >= NTDDI_VISTA)
#IF %WINVER >= &H0600
%VALIDATEUNC_PERSIST  = &H0008???          ' // the connection should be made persistent
%VALIDATEUNC_VALID    = &H000F???          ' // valid flags
#ELSE
%VALIDATEUNC_VALID    = &H0007???          ' // valid flags
#ENDIF

DECLARE FUNCTION SHValidateUNC IMPORT "SHELL32.DLL" ALIAS "SHValidateUNC" ( _
   BYVAL hwndOwner AS DWORD _                           ' __in HWND hwndOwner
 , BYREF pszFile AS WSTRINGZ _                          ' __in LPWSTR pszFile
 , BYVAL fConnect AS DWORD _                            ' __in UINT fConnect
 ) AS LONG                                              ' BOOL

%OPENPROPS_NONE       = &H0000???
%OPENPROPS_INHIBITPIF = &H8000???
%GETPROPS_NONE        = &H0000???
%SETPROPS_NONE        = &H0000???
%CLOSEPROPS_NONE      = &H0000???
%CLOSEPROPS_DISCARD   = &H0001???

%PIFNAMESIZE          = 30
%PIFSTARTLOCSIZE      = 63
%PIFDEFPATHSIZE       = 64
%PIFPARAMSSIZE        = 64
%PIFSHPROGSIZE        = 64
%PIFSHDATASIZE        = 64
%PIFDEFFILESIZE       = 80
%PIFMAXFILEPATH       = 260

' Unaligned structure
' // Size = 658 bytes
TYPE PROPPRG BYTE
   flPrg           AS WORD                                        ' WORD  // see PRG_ flags
   flPrgInit       AS WORD                                        ' WORD  // see PRGINIT_ flags
   achTitle        AS ASCIIZ * %PIFNAMESIZE                       ' CHAR [PIFNAMESIZE] // name[30]
   achCmdLine      AS ASCIIZ * %PIFSTARTLOCSIZE+%PIFPARAMSSIZE+1  ' CHAR [PIFSTARTLOCSIZE+PIFPARAMSSIZE+1] // startfile[63] + params[64]
   achWorkDir      AS ASCIIZ * %PIFDEFPATHSIZE                    ' CHAR [PIFDEFPATHSIZE] // defpath[64]
   wHotKey         AS WORD                                        ' WORD   // PfHotKeyScan thru PfHotKeyVal
   achIconFile     AS ASCIIZ * %PIFDEFFILESIZE                    ' CHAR [PIFDEFFILESIZE] // name of file containing icon
   wIconIndex      AS WORD                                        ' WORD   // index of icon within file
   dwEnhModeFlags  AS DWORD                                       ' DWORD  // reserved enh-mode flags
   dwRealModeFlags AS DWORD                                       ' DWORD  // real-mode flags (see RMOPT_*)
   achOtherFile    AS ASCIIZ * %PIFDEFFILESIZE                    ' CHAR [PIFDEFFILESIZE] // name of "other" file in directory
   achPIFFile      AS ASCIIZ * %PIFMAXFILEPATH                    ' CHAR [PIFMAXFILEPATH] // name of PIF file
END TYPE

DECLARE FUNCTION PifMgr_OpenProperties IMPORT "SHELL32.DLL" ALIAS "PifMgr_OpenProperties" ( _
   BYREF pszApp AS WSTRINGZ _                           ' __in LPCWSTR pszApp
 , BYREF lpszPIF AS WSTRINGZ _                          ' __in LPCWSTR lpszPIF
 , BYVAL hInf AS DWORD _                                ' __in UINT hInf
 , BYVAL flOpt AS DWORD _                               ' __in UINT flOpt
 ) AS DWORD                                             ' HANDLE

DECLARE FUNCTION PifMgr_GetProperties IMPORT "SHELL32.DLL" ALIAS "PifMgr_GetProperties" ( _
   BYVAL hProps AS DWORD _                              ' __in HANDLE hProps
 , BYREF pszGroup AS ASCIIZ _                           ' __in LPCSTR pszGroup
 , BYREF lpProps AS PROPPRG _                           ' __out VOID *lpProps
 , BYVAL cbProps AS DWORD _                             ' __in int cbProps
 , BYVAL flOpt AS DWORD _                               ' __in UINT flOpt
 ) AS LONG                                              ' int

DECLARE FUNCTION PifMgr_SetProperties IMPORT "SHELL32.DLL" ALIAS "PifMgr_SetProperties" ( _
   BYVAL hProps AS DWORD _                              ' __in HANDLE hProps
 , BYREF pszGroup AS ASCIIZ _                           ' __in LPCSTR pszGroup
 , BYREF lpProps AS PROPPRG _                           ' __out VOID *lpProps
 , BYVAL cbProps AS DWORD _                             ' __in int cbProps
 , BYVAL flOpt AS DWORD _                               ' __in UINT flOpt
 ) AS LONG                                              ' int

DECLARE FUNCTION PifMgr_CloseProperties IMPORT "SHELL32.DLL" ALIAS "PifMgr_CloseProperties" ( _
   BYVAL hProps AS DWORD _                              ' __in HANDLE hProps
 , BYVAL flOpt AS DWORD _                               ' __in UINT flOpt
 ) AS LONG                                              ' int

#IF %DEF(%USEPBDECL)
DECLARE SUB SHSetInstanceExplorer LIB "Shell32.dll" _
    ALIAS "SHSetInstanceExplorer" (punk AS ANY)
#ELSE
DECLARE SUB SHSetInstanceExplorer IMPORT "SHELL32.DLL" ALIAS "SHSetInstanceExplorer" ( _
   BYVAL punk AS IUnknown _                             ' __in IUnknown *punk
 )                                                      ' void
#ENDIF

DECLARE FUNCTION IsUserAnAdmin IMPORT "SHELL32.DLL" ALIAS "IsUserAnAdmin" ( _
 ) AS LONG                                              ' BOOL


' ########################################################################################
' IInitializeObject interface
' IID = 4622AD16-FF23-11d0-8D34-00A0C90F2719
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IInitializeObject_INTERFACE_DEFINED)
    %IInitializeObject_INTERFACE_DEFINED = 1

$IID_IInitializeObject = GUID$("{4622AD16-FF23-11d0-8D34-00A0C90F2719}")

INTERFACE IInitializeObject $IID_IInitializeObject

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Initialize ( _                                ' VTable offset = 12
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IInitializeObject_INTERFACE_DEFINED__ */


%BMICON_LARGE = 0
%BMICON_SMALL = 1


' ########################################################################################
' IBanneredBar interface
' IID = 596A9A94-013E-11d1-8D34-00A0C90F2719
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IBanneredBar_INTERFACE_DEFINED)
    %IBanneredBar_INTERFACE_DEFINED = 1

$IID_IBanneredBar = GUID$("{596A9A94-013E-11d1-8D34-00A0C90F2719}")

INTERFACE IBanneredBar $IID_IBanneredBar

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetIconSize ( _                               ' VTable offset = 12
     BYVAL iIcon AS DWORD _                             ' __in DWORD iIcon
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetIconSize ( _                               ' VTable offset = 16
     BYREF piIcon AS DWORD _                            ' __out DWORD* piIcon
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetBitmap ( _                                 ' VTable offset = 20
     BYVAL hBitmap AS DWORD _                           ' __in HBITMAP hBitmap
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetBitmap ( _                                 ' VTable offset = 24
     BYREF phBitmap AS DWORD _                          ' __out HBITMAP* phBitmap
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IBanneredBar_INTERFACE_DEFINED__ */


DECLARE FUNCTION SHShellFolderView_Message IMPORT "SHELL32.DLL" ALIAS "SHShellFolderView_Message" ( _
   BYVAL hwnd AS DWORD _                                ' __in HWND hwnd
 , BYVAL uMsg AS DWORD _                                ' __in UINT uMsg
 , BYVAL lparam AS LONG _                               ' __in LPARAM lparam
 ) AS LONG                                              ' LRESULT

'//
'// Callback interface for the IShellFolderView
'//

' ########################################################################################
' IShellFolderViewCB interface
' IID = 2047E320-F2A9-11CE-AE65-08002B2E1262
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IShellFolderViewCB_INTERFACE_DEFINED)
    %IShellFolderViewCB_INTERFACE_DEFINED = 1

INTERFACE IShellFolderViewCB $IID_IShellFolderViewCB

   INHERIT IUnknown

   ' =====================================================================================
   METHOD MessageSFVCB ( _                              ' VTable offset = 12
     BYVAL uMsg AS DWORD _                              ' __in UINT uMsg
   , BYVAL wParam AS DWORD _                            ' __in WPARAM wParam
   , BYVAL lParam AS LONG _                             ' __in LPARAM lParam
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IShellFolderViewCB_INTERFACE_DEFINED__ */

'#include <pshpack8.h>

%QCMINFO_PLACE_BEFORE = 0
%QCMINFO_PLACE_AFTER  = 1

' // Size = 8 bytes
TYPE QCMINFO_IDMAP_PLACEMENT BYTE
   id     AS DWORD   ' UINT
   fFlags AS DWORD   ' UINT
END TYPE

' // Size = 12 bytes
TYPE QCMINFO_IDMAP BYTE
   nMaxIds    AS DWORD                     ' UINT
   pIdList(0) AS QCMINFO_IDMAP_PLACEMENT   ' QCMINFO_IDMAP_PLACEMENT[1]
END TYPE

' // Size = 20 bytes
TYPE QCMINFO BYTE
   hMenu      AS DWORD                ' HMENU // in
   indexMenu  AS DWORD                ' UINT  // in
   idCmdFirst AS DWORD                ' UINT  // in/out
   idCmdLast  AS DWORD                ' UINT  // in
   pldMap     AS QCMINFO_IDMAP PTR    ' QCMINFO_IDMAP const* // in / unused
END TYPE

'// TBINFO flags
%TBIF_APPEND          = 0???
%TBIF_PREPEND         = 1???
%TBIF_REPLACE         = 2???
%TBIF_DEFAULT         = &H00000000???
%TBIF_INTERNETBAR     = &H00010000???
%TBIF_STANDARDTOOLBAR = &H00020000???
%TBIF_NOTOOLBAR       = &H00030000???

' // Size = 8 bytes
TYPE TBINFO BYTE
   cbuttons AS DWORD   ' UINT // out
   uFLags   AS DWORD   ' UINT // out (one of TBIF_ flags)
END TYPE

' // Size = 280 bytes
TYPE DETAILSINFO BYTE
   pidl   AS ITEMIDLIST PTR   ' LPCITEMIDLIST
   fmt    AS LONG             ' int
   cxChar AS LONG             ' int
   str    AS STRRET           ' STRRET
   iImage AS LONG             ' int
END TYPE

' // Size = 12 bytes
TYPE SFVM_PROPPAGE_DATA BYTE
   dwReserved AS DWORD   ' DWORD
   pfn        AS DWORD   ' LPFNADDPROPSHEETPAGE
   lParam     AS LONG    ' LPARAM
END TYPE

' // Size = 1040 bytes
TYPE SFVM_HELPTOPIC_DATA BYTE
   wszHelpFile  AS WSTRINGZ * %MAX_PATH   ' WCHAR [MAX_PATH]
   wszHelpTopic AS WSTRINGZ * %MAX_PATH   ' WCHAR [MAX_PATH]
END TYPE

'//                         uMsg       wParam             lParam
%SFVM_MERGEMENU           =  1    ' // -                  LPQCMINFO
%SFVM_INVOKECOMMAND       =  2    ' // idCmd              -
%SFVM_GETHELPTEXT         =  3    ' // idCmd,cchMax       pszText
%SFVM_GETTOOLTIPTEXT      =  4    ' // idCmd,cchMax       pszText
%SFVM_GETBUTTONINFO       =  5    ' // -                  LPTBINFO
%SFVM_GETBUTTONS          =  6    ' // idCmdFirst,cbtnMax LPTBBUTTON
%SFVM_INITMENUPOPUP       =  7    ' // idCmdFirst,nIndex  hmenu
%SFVM_FSNOTIFY            = 14    ' // LPCITEMIDLIST*     lEvent
%SFVM_WINDOWCREATED       = 15    ' // hwnd               -
%SFVM_GETDETAILSOF        = 23    ' // iColumn            DETAILSINFO*
%SFVM_COLUMNCLICK         = 24    ' // iColumn            -
%SFVM_QUERYFSNOTIFY       = 25    ' // -                  SHChangeNotifyEntry *
%SFVM_DEFITEMCOUNT        = 26    ' // -                  UINT*
%SFVM_DEFVIEWMODE         = 27    ' // -                  FOLDERVIEWMODE*
%SFVM_UNMERGEMENU         = 28    ' // -                  hmenu
%SFVM_UPDATESTATUSBAR     = 31    ' // fInitialize        -
%SFVM_BACKGROUNDENUM      = 32    ' // -                  -
%SFVM_DIDDRAGDROP         = 36    ' // dwEffect           IDataObject *
%SFVM_SETISFV             = 39    ' // -                  IShellFolderView*
%SFVM_THISIDLIST          = 41    ' // -                  LPITMIDLIST*
%SFVM_ADDPROPERTYPAGES    = 47    ' // -                  SFVM_PROPPAGE_DATA *
%SFVM_BACKGROUNDENUMDONE  = 48    ' // -                  -
%SFVM_GETNOTIFY           = 49    ' // LPITEMIDLIST*      LONG*
%SFVM_GETSORTDEFAULTS     = 53    ' // iDirection         iParamSort
%SFVM_SIZE                = 57    ' // -                  -
%SFVM_GETZONE             = 58    ' // -                  DWORD*
%SFVM_GETPANE             = 59    ' // Pane ID            DWORD*
%SFVM_GETHELPTOPIC        = 63    ' // -                  SFVM_HELPTOPIC_DATA *
%SFVM_GETANIMATION        = 68    ' // HINSTANCE *        WCHAR *


'// IShellFolderView
'//
'// Deprecated: use IFolderView and IFolderView2 instead.
'//
'// IShellFolderView is supported by the IShellView object returned from SHCreateShellFolderView.
'//
'// Warnings:
'//  - Some methods on this interface do not follow standard COM rules.
'//  - Some methods can be used to configure the IShellView or cause it to behave incorrectly.
'//  - Few of these methods have parameter or range validation, so callers can cause the IShellView to fault.

' // Size = 16 bytes
TYPE ITEMSPACING BYTE
   cxSmall AS LONG   ' int
   cySmall AS LONG   ' int
   cxLarge AS LONG   ' int
   cyLarge AS LONG   ' int
END TYPE

'// defines for IShellFolderView::SetObjectCount
%SFVSOC_INVALIDATE_ALL   = &H00000001???   ' // Assumed to reset only what is neccessary...
%SFVSOC_NOSCROLL         = &H00000002???   ' %LVSICF_NOSCROLL

'// defines for IShellFolderView::SelectItems()
%SFVS_SELECT_NONE        = &H0   ' // unselect all
%SFVS_SELECT_ALLITEMS    = &H1   ' // select all
%SFVS_SELECT_INVERT      = &H2   ' // Invert the selection

'DECLARE_INTERFACE_IID_(IShellFolderView, IUnknown, "37A378C0-F82D-11CE-AE65-08002B2E1262")
'{
'    // *** IUnknown methods ***
'    STDMETHOD(QueryInterface) (THIS_ REFIID riid, void **ppv) PURE;
'    STDMETHOD_(ULONG,AddRef) (THIS)  PURE;
'    STDMETHOD_(ULONG,Release) (THIS) PURE;

'    // *** IShellFolderView methods ***
'    STDMETHOD(Rearrange) (THIS_ LPARAM lParamSort) PURE; // use IFolderView2::SetSortColumns
'    STDMETHOD(GetArrangeParam) (THIS_ LPARAM *plParamSort) PURE; // use IFolderView2::GetSortColumns
'    STDMETHOD(ArrangeGrid) (THIS) PURE; // select Arrange by Grid
'    STDMETHOD(AutoArrange) (THIS) PURE; // select Auto Arrange
'    STDMETHOD(GetAutoArrange) (THIS) PURE; // use IFolderView::GetAutoArrange
'    STDMETHOD(AddObject) (THIS_ PUITEMID_CHILD pidl, UINT *puItem) PURE; // items added here may disappear (the data source is the final arbiter of which items are available to the view)
'    STDMETHOD(GetObject) (THIS_ PITEMID_CHILD *ppidl, UINT uItem) PURE; // use IFolderView::Item
'    STDMETHOD(RemoveObject) (THIS_ PUITEMID_CHILD pidl, UINT *puItem) PURE; // items removed here may reappear (the data source is the final arbiter of which items are available to the view)
'    STDMETHOD(GetObjectCount) (THIS_ UINT *puCount) PURE; // use IFolderView::ItemCount
'    STDMETHOD(SetObjectCount) (THIS_ UINT uCount, UINT dwFlags) PURE; // not implemented on Vista.  Sends LVM_SETITEMCOUNT with WPARAM=uCount and LPARAM=dwFlags to listview on XP.
'    STDMETHOD(UpdateObject) (THIS_ PUITEMID_CHILD pidlOld, PUITEMID_CHILD pidlNew, UINT *puItem) PURE; // swaps ITEMID_CHILDs, returning new index.  Changes may be discarded (the data source is the final arbiter of which items are available to the view)
'    STDMETHOD(RefreshObject) (THIS_ PUITEMID_CHILD pidl, UINT *puItem) PURE; // tickles the listview to re-draw the item
'    STDMETHOD(SetRedraw) (THIS_ BOOL bRedraw) PURE; // sends WM_SETREDRAW to the listview
'    STDMETHOD(GetSelectedCount) (THIS_ UINT *puSelected) PURE; // use IFolderView2::GetSelection
'    // NOTE: GetSelectedObjects hands out const pointers to internal ITEMID_CHILD structures. The caller is expected to act on them immediately (and not cache them).  LocalFree the array, but not the items it contains.
'    STDMETHOD(GetSelectedObjects) (THIS_ PCUITEMID_CHILD **pppidl, UINT *puItems) PURE; // use IFolderView2::GetSelection.
'    STDMETHOD(IsDropOnSource) (THIS_ IDropTarget *pDropTarget) PURE; // use IFolderView2::IsMoveInSameFolder
'    STDMETHOD(GetDragPoint) (THIS_ POINT *ppt) PURE; // returns point corresponding to drag-and-drop operation
'    STDMETHOD(GetDropPoint) (THIS_ POINT *ppt) PURE; // returns point corresponding to drag-and-drop operation
'    STDMETHOD(MoveIcons) (THIS_ IDataObject *pDataObject) PURE; // not implemented
'    STDMETHOD(SetItemPos) (THIS_ PCUITEMID_CHILD pidl, POINT *ppt) PURE; // use IFolderView::SelectAndPositionItems
'    STDMETHOD(IsBkDropTarget) (THIS_ IDropTarget *pDropTarget) PURE; // returns S_OK if drag-and-drop is on the background, S_FALSE otherwise
'    STDMETHOD(SetClipboard) (THIS_ BOOL bMove) PURE; // if bMove is TRUE, this attempts to cut (edit.cut, ctrl-x) the current selection.  bMove of FALSE is not supported.
'    STDMETHOD(SetPoints) (THIS_ IDataObject *pDataObject) PURE; // copies points of current selection in to data object.  Call is not needed if drag operation was originated by the IShellView.
'    STDMETHOD(GetItemSpacing) (THIS_ ITEMSPACING *pSpacing) PURE; // use IFolderView::GetSpacing instead.  GetItemSpacing returns the spacing for small and large view modes only, returning S_OK if the current view mode is is positionable, S_FALSE otherwise.
'    STDMETHOD(SetCallback) (THIS_ IShellFolderViewCB* pNewCB, IShellFolderViewCB** ppOldCB) PURE; // replace the IShellFolderViewCB that the IShellView uses
'    STDMETHOD(Select) ( THIS_  UINT dwFlags ) PURE; // SFVS_ select flags: select all, select none, invert selection
'    STDMETHOD(QuerySupport) (THIS_ UINT * pdwSupport ) PURE; // does nothing, returns S_OK.
'    STDMETHOD(SetAutomationObject)(THIS_ IDispatch* pdisp) PURE; // replaces the IShellView's internal automation object.
'} ;

' ########################################################################################
' IShellFolderView interface
' IID = 37A378C0-F82D-11CE-AE65-08002B2E1262
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IShellFolderView_INTERFACE_DEFINED)
    %IShellFolderView_INTERFACE_DEFINED = 1

$IID_IShellFolderView = GUID$("{37A378C0-F82D-11CE-AE65-08002B2E1262}")

INTERFACE IShellFolderView $IID_IShellFolderView

   INHERIT IUnknown

   METHOD Rearrange (BYVAL lParamSort AS LONG) AS LONG
   METHOD GetArrangeParam (BYREF plParamSort AS LONG) AS LONG
   METHOD ArrangeGrid () AS LONG
   METHOD AutoArrange () AS LONG
   METHOD GetAutoArrange () AS LONG
   METHOD AddObject (BYVAL pidl AS DWORD, BYREF puItem AS DWORD) AS LONG
   METHOD GetObject (BYREF ppidl AS DWORD, BYVAL uItem AS DWORD) AS LONG
   METHOD RemoveObject (BYVAL pidl AS DWORD, BYREF puItem AS DWORD) AS LONG
   METHOD GetObjectCount (BYREF puCount AS DWORD) AS LONG
   METHOD SetObjectCount (BYVAL uCount AS DWORD, BYVAL dwFlags AS DWORD) AS LONG
   METHOD UpdateObject (BYVAL pidlOld AS DWORD, BYVAL pidlNew AS DWORD, BYREF puItem AS DWORD) AS LONG
   METHOD RefreshObject (BYVAL pidl AS DWORD, BYREF puItem AS DWORD) AS LONG
   METHOD SetRedraw (BYVAL bRedraw AS LONG) AS LONG
   METHOD GetSelectedCount (BYREF puSelected AS DWORD) AS LONG
   ' // NOTE: GetSelectedObjects hands out const pointers to internal ITEMID_CHILD structures.
   ' // The caller is expected to act on them immediately (and not cache them).
   ' // LocalFree the array, but not the items it contains.
   METHOD GetSelectedObjects (BYREF pppidl AS DWORD, BYREF puItems AS DWORD) AS LONG
   METHOD IsDropOnSource (BYVAL pDropTarget AS IDropTarget) AS LONG
   METHOD GetDragPoint (BYREF ppt AS POINT) AS LONG
   METHOD GetDropPoint (BYREF ppt AS POINT) AS LONG
   METHOD MoveIcons (BYVAL pDataObject AS IDataObject) AS LONG
   METHOD SetItemPos (BYVAL pidl AS DWORD, BYREF ppt AS POINT) AS LONG
   METHOD IsBkDropTarget (BYVAL pDropTarget AS IDropTarget) AS LONG
   METHOD SetClipboard (BYVAL bMove AS LONG) AS LONG
   METHOD SetPoints (BYVAL pDataObject AS IDataObject) AS LONG
   METHOD GetItemSpacing (BYREF pSpacing AS ITEMSPACING) AS LONG
   METHOD SetCallback (BYVAL pNewCB AS IShellFolderViewCB, BYREF ppOldCB AS IShellFolderViewCB) AS LONG
   METHOD Select (BYVAL dwFlags AS DWORD) AS LONG
   METHOD QuerySupport (BYREF pdwSupport AS DWORD) AS LONG
   METHOD SetAutomationObject (BYVAL pdisp AS IDispatch) AS LONG

END INTERFACE

#ENDIF   ' /* __IShellFolderView_INTERFACE_DEFINED__ */

' // SHCreateShellFolderView struct
' // Size = 16 bytes
TYPE SFV_CREATE
   cbSize   AS DWORD      ' UINT
   pshf     AS DWORD PTR  ' IShellFolder*
   psvOuter AS DWORD PTR  ' IShellView*
   psfvcb   AS DWORD PTR  ' IShellFolderViewCB* // No callback if NULL
END TYPE

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SHCreateShellFolderView LIB "Shell32.dll" _
    ALIAS "SHCreateShellFolderView" (pcsfv AS SFV_CREATE, ppsv AS ANY) AS LONG
#ELSE
DECLARE FUNCTION SHCreateShellFolderView IMPORT "SHELL32.DLL" ALIAS "SHCreateShellFolderView" ( _
   BYREF pcsfv AS SFV_CREATE  _                         ' __in const SFV_CREATE* pcsfv
 , BYREF ppsv AS IShellView _                           ' __out IShellView **ppsv
 ) AS LONG                                              ' LRESULT
#ENDIF

'typedef HRESULT (CALLBACK * LPFNDFMCALLBACK)(__in_opt IShellFolder *psf, __in_opt HWND hwnd,
'                                             __in_opt IDataObject *pdtobj, __in UINT uMsg, __in WPARAM wParam, __in LPARAM lParam);

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION CDefFolderMenu_Create2 LIB "Shell32.dll" _
    ALIAS "CDefFolderMenu_Create2" (pidlFolder AS ITEMIDLIST, _
    BYVAL hwnd AS DWORD, BYVAL cidl AS DWORD, apidl AS ITEMIDLIST, _
    psf AS ANY, BYVAL pfn AS DWORD, BYVAL nKeys AS DWORD, _
    BYVAL ahKeys AS DWORD PTR, ppcm AS ANY) AS LONG
#ELSE
DECLARE FUNCTION CDefFolderMenu_Create2 IMPORT "SHELL32.DLL" ALIAS "CDefFolderMenu_Create2" ( _
   BYVAL pidlFolder AS DWORD _                          ' __in_opt LPCITEMIDLIST pidlFolder
 , BYVAL hwnd AS DWORD _                                ' __in_opt HWND hwnd
 , BYVAL cidl AS DWORD _                                ' __in_opt UINT cidl
 , BYVAL apidl AS DWORD _                               ' __in_opt LPCITEMIDLIST *apidl
 , BYVAL psf AS IShellFolder _                          ' __in_opt IShellFolder *psf
 , BYVAL psf AS DWORD _                                 ' __in_opt LPFNDFMCALLBACK lpfn
 , BYVAL nKeys AS DWORD _                               ' __in UINT nKeys
 , BYREF ahkeyClsKeys AS DWORD _                        ' __in const HKEY *ahkeyClsKeys
 , BYREF ppcm AS IContextMenu _                         ' __out IContextMenu **ppcm
 ) AS LONG                                              ' int
#ENDIF


' // Size = 36 bytes
TYPE DEFCONTEXTMENU BYTE
   hwnd                AS DWORD            ' HWND
   pcmcb               AS DWORD      PTR   ' IContextMenuCB* // optional: callback object
   pidlFolder          AS ITEMIDLIST PTR   ' PCIDLIST_ABSOLUTE // optional: IDList to folder of the items, computed from psf if NULL
   psf                 AS DWORD      PTR   ' IShellFolder* // folder of the items
   cidl                AS DWORD            ' UINT // # of items in apidl
   apidl               AS ITEMIDLIST PTR   ' PCUITEMID_CHILD_ARRAY // items operating on, used to get IDataObject and IAssociationArray
   punkAssociationInfo AS DWORD      PTR   ' IUnknown* // optional: IQueryAssociations, specifies where to load extensions from, computed from apidl if NULL
   cKeys               AS DWORD            ' UINT // # of items in aKeys, may be zero
   aKeys               AS DWORD            ' const HKEY* // optional: specifies where to load extensions from
END TYPE

'// creates object that implements IContextMenu/IContextMenu2/IContextMenu3, typically
'// used in the implemetnation of ::GetUIObjectOf()

'#if (NTDDI_VERSION >= NTDDI_VISTA)
#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SHCreateDefaultContextMenu LIB "Shell32.dll" _
    ALIAS "SHCreateDefaultContextMenu" (pdcm AS DEFCONTEXTMENU, _
    riid AS GUID, ppv AS ANY) AS LONG
#ELSE
DECLARE FUNCTION SHCreateDefaultContextMenu IMPORT "SHELL32.DLL" ALIAS "SHCreateDefaultContextMenu" ( _
   BYREF pdcm AS DEFCONTEXTMENU _                       ' __in const DEFCONTEXTMENU *pdcm
 , BYREF riid AS GUID _                                 ' __in REFIID riid
 , BYREF ppv AS IUnknown _                              ' __out void **ppv
 ) AS LONG                                              ' HRESULT
#ENDIF
'#endif // NTDDI_VISTA

'SHSTDAPI_(BOOL) SHOpenPropSheetA(__in_opt LPCSTR pszCaption, __in_ecount_opt(cikeys) HKEY ahkeys[], UINT cikeys,
'                                 __in_opt const CLSID * pclsidDefault, __in IDataObject *pdtobj,
'                                 __in_opt IShellBrowser *psb, __in_opt LPCSTR pStartPage);
'SHSTDAPI_(BOOL) SHOpenPropSheetW(__in_opt LPCWSTR pszCaption, __in_ecount_opt(cikeys) HKEY ahkeys[], UINT cikeys,
'                                 __in_opt const CLSID * pclsidDefault, __in IDataObject *pdtobj,
'                                 __in_opt IShellBrowser *psb, __in_opt LPCWSTR pStartPage);

' Implemeneted as Unicode version only.
#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SHOpenPropSheetW LIB "Shell32.dll" _
    ALIAS "SHOpenPropSheetW" (pszCaption AS WSTRINGZ, ahkeys AS ANY, _
    BYVAL cikeys AS DWORD, pclsidDefault AS GUID, pdtobj AS ANY, _
    psb AS ANY, pStartPage AS ASCIIZ) AS LONG
#ELSE
DECLARE FUNCTION SHOpenPropSheetW IMPORT "SHELL32.DLL" ALIAS "SHOpenPropSheetW" ( _
   BYREF pszCaption AS WSTRINGZ _                       ' __in LPCWSTR pszCaption
 , BYREF ahkeys AS DWORD _                              ' __in HKEY ahkeys[]
 , BYVAL ckeys AS DWORD _                               ' __in UINT ckeys
 , BYREF pclsidDef AS GUID _                            ' __in const CLSID *pclsidDef
 , BYVAL pdtobj AS IDataObject _                        ' __in IDataObject *pdtobj
 , BYVAL psb AS IShellBrowser _                         ' __in IShellBrowser *psb
 , BYREF pStartPage AS WSTRINGZ _                       ' __in LPCWSTR pStartPage
 ) AS LONG                                              ' BOOL
#ENDIF

MACRO SHOpenPropSheet = SHOpenPropSheetW

' // structure for lParam of DFM_INFOKECOMMANDEX
' // Size = 28 bytes
TYPE DFMICS BYTE
   cbSize     AS DWORD                     ' DWORD
   fMask      AS DWORD                     ' DWORD // CMIC_MASK_ values for the invoke
   lParam     AS LONG                      ' LPARAM // same as lParam of DFM_INFOKECOMMAND
   idCmdFirst AS DWORD                     ' UINT
   idDefMax   AS DWORD                     ' UINT
   pici       AS CMINVOKECOMMANDINFO PTR   ' LPCMINVOKECOMMANDINFO // the whole thing so you can re-invoke on a child
'#if (NTDDI_VERSION >= NTDDI_VISTA)
#IF %WINVER >= &H0600
   punkSite   AS DWORD PTR                 ' IUnknown* // site pointer for context menu handler
#ENDIF
END TYPE

'// Note on context menus ranges:
'//  Standard Items // DFM_MERGECONTEXTMENU, context menu extensions, DFM_MERGECONTEXTMENU_TOP
'//  Separator
'//  View Items   // context menu extensions can get here
'//  Separator
'//  (defcm S_FALSE "default" items, if applicable)
'//  Separator
'//  Folder Items // context menu extensions can get here
'//  Separator
'//  Bottom Items // DFM_MERGECONTEXTMENU_BOTTOM

'//                         uMsg       wParam             lParam
%DFM_MERGECONTEXTMENU        =  1      ' // uFlags       LPQCMINFO
%DFM_INVOKECOMMAND           =  2      ' // idCmd        pszArgs
%DFM_GETHELPTEXT             = 5       ' // idCmd,cchMax pszText -Ansi
%DFM_WM_MEASUREITEM          = 6       ' // ---from the message---
%DFM_WM_DRAWITEM             = 7       ' // ---from the message---
%DFM_WM_INITMENUPOPUP        = 8       ' // ---from the message---
%DFM_VALIDATECMD             = 9       ' // idCmd        0
%DFM_MERGECONTEXTMENU_TOP    = 10      ' // uFlags       LPQCMINFO
%DFM_GETHELPTEXTW            = 11      ' // idCmd,cchMax pszText -Unicode
%DFM_INVOKECOMMANDEX         = 12      ' // idCmd        PDFMICS
%DFM_MAPCOMMANDNAME          = 13      ' // idCmd *      pszCommandName
%DFM_GETDEFSTATICID          = 14      ' // idCmd *      0
%DFM_GETVERBW                = 15      ' // idCmd,cchMax pszText -Unicode
%DFM_GETVERBA                = 16      ' // idCmd,cchMax pszText -Ansi
%DFM_MERGECONTEXTMENU_BOTTOM = 17      ' // uFlags       LPQCMINFO
%DFM_MODIFYQCMFLAGS          = 18      ' // uFlags       UINT *puNewFlags;   modify the CFM_XXX values passed to IContextMenu::QueryContextMenu

' // Commands from DFM_INVOKECOMMAND when strings are passed in
%DFM_CMD_DELETE              = &HFFFFFFFF???   ' ((UINT)-1)
%DFM_CMD_MOVE                = &HFFFFFFFE???   ' ((UINT)-2)
%DFM_CMD_COPY                = &HFFFFFFFD???   ' ((UINT)-3)
%DFM_CMD_LINK                = &HFFFFFFFC???   ' ((UINT)-4)
%DFM_CMD_PROPERTIES          = &HFFFFFFFB???   ' ((UINT)-5)
%DFM_CMD_NEWFOLDER           = &HFFFFFFFA???   ' ((UINT)-6)
%DFM_CMD_PASTE               = &HFFFFFFF9???   ' ((UINT)-7)
%DFM_CMD_VIEWLIST            = &HFFFFFFF8???   ' ((UINT)-8)
%DFM_CMD_VIEWDETAILS         = &HFFFFFFF7???   ' ((UINT)-9)
%DFM_CMD_PASTELINK           = &HFFFFFFF6???   ' ((UINT)-10)
%DFM_CMD_PASTESPECIAL        = &HFFFFFFF5???   ' ((UINT)-11)
%DFM_CMD_MODALPROP           = &HFFFFFFF4???   ' ((UINT)-12)
%DFM_CMD_RENAME              = &HFFFFFFF3???   '((UINT)-13)

'typedef HRESULT (CALLBACK * LPFNVIEWCALLBACK)(IShellView *psvOuter,
'                                                IShellFolder *psf,
'                                                HWND hwndMain,
'                                                UINT uMsg,
'                                                WPARAM wParam,
'                                                LPARAM lParam);

' // SHCreateShellFolderViewEx struct
' // Size = 28 bytes
TYPE CSFV BYTE
   cbsize      AS DWORD            ' UINT
   pshf        AS DWORD            ' IShellFolder*
   psvOuter    AS DWORD            ' IShellView*
   pidl        AS ITEMIDLIST PTR   ' LPCITEMIDLIST
   lEvents     AS LONG             ' LONG
   pfnCallback AS DWORD            ' LPFNVIEWCALLBACK  // No callback if NULL
   fvm         AS DWORD            ' FOLDERVIEWMODE
END TYPE

'// Tell the FolderView to rearrange.  The lParam will be passed to
'// IShellFolder::CompareIDs
%SFVM_REARRANGE           = &H00000001???
'#define ShellFolderView_ReArrange(_hwnd, _lparam) \
'        (BOOL)SHShellFolderView_Message(_hwnd, SFVM_REARRANGE, _lparam)
MACRO ShellFolderView_ReArrange(hwnd,lparam) = SHShellFolderView_Message(hwnd,%SFVM_REARRANGE,lParam)

'// Add an OBJECT into the view
%SFVM_ADDOBJECT           = &H00000003???
MACRO ShellFolderView_AddObject(hwnd,pidl) = SHShellFolderView_Message(hwnd,%SFVM_ADDOBJECT,VARPTR(pidl))

'// Remove an OBJECT into the view
%SFVM_REMOVEOBJECT        = &H00000006???
MACRO ShellFolderView_RemoveObject(hwnd,pidl) = SHShellFolderView_Message(hwnd,%SFVM_REMOVEOBJECT,VARPTR(pidl))

'// updates an object by passing in pointer to two PIDLS, the first
'// is the old pidl, the second one is the one with update information.
'//
'// _ppidl[1] must be a *copy* of a pidl, as control over the lifetime
'// of the pidl belongs to the view after successful completion of
'// this call.  (Unsuccessful completion (a -1 return) implies failure
'// and the caller must free the memory.)  Win95 waits a while before
'// freeing the pidl, IE4 frees the pidl immediately.
'// IShellFolderView::UpdateObject does not suffer from this problem.
'//
%SFVM_UPDATEOBJECT        = &H00000007???
MACRO ShellFolderView_UpdateObject(hwnd,ppidl) = SHShellFolderView_Message(hwnd,%SFVM_UPDATEOBJECT,VARPTR()ppidl)

'// Returns an array of the selected IDS to the caller.
'//     lparam is a pointer to receive the idlists into
'//     return value is the count of items in the array.
%SFVM_GETSELECTEDOBJECTS  = &H00000009???
MACRO ShellFolderView_GetSelectedObjects(hwnd,ppidl) = SHShellFolderView_Message(hwnd,%SFVM_GETSELECTEDOBJECTS,VARPTR(ppidl))

' // Size = 12 bytes
TYPE SFV_SETITEMPOS BYTE
   pidl AS ITEMIDLIST PTR
   pt AS POINT
END TYPE

'// Sets the position of an item in the viewer
'//     lparam is a pointer to a SVF_SETITEMPOS
'//     return value is unused
%SFVM_SETITEMPOS          = &H0000000E???
'FUNCTION ShellFolderView_SetItemPos (BYVAL hwnd AS DWORD, BYVAL pidl AS DWORD, BYVAL x AS LONG, BYVAL y AS LONG) AS LONG
'   LOCAL sip AS SFV_SETITEMPOS
'   sip.pidl = pidl
'   sip.pt.x = x
'   sip.pt.y = y
'   FUNCTION = SHShellFolderView_Message(hwnd, %SFVM_SETITEMPOS, VARPTR(sip))
'END FUNCTION

MACRO FUNCTION ShellFolderView_SetItemPos (hwnd, pidl, x, y)
   MACROTEMP sip
   LOCAL sip AS SFV_SETITEMPOS
   sip.pidl = pidl
   sip.pt.x = x
   sip.pt.y = y
END MACRO = SHShellFolderView_Message(hwnd, %SFVM_SETITEMPOS, VARPTR(sip))

'//  Notifies a ShellView when one of its objects get put on the clipboard
'//  as a result of a menu command.
'//
'//
'//     lparam is the dwEffect (DROPEFFECT_MOVE, DROPEFFECT_COPY)
'//     return value is void.
%SFVM_SETCLIPBOARD        = &H00000010???
MACRO ShellFolderView_SetClipboard(hwnd,dwEffect) = SHShellFolderView_Message(hwnd,%SFVM_SETCLIPBOARD,dwEFfect)

%SFVM_SETPOINTS           = &H00000017???
MACRO ShellFolderView_SetPoints(hwnd,pdtobj) = SHShellFolderView_Message(hwnd,%SFVM_SETPOINTS,pdtobj)

'#include <poppack.h>        /* Return to byte packing */

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SHFind_InitMenuPopup LIB "Shell32.dll" _
    ALIAS "SHFind_InitMenuPopup" (BYVAL hmenu AS DWORD, _
    BYVAL hwndOwner AS DWORD, BYVAL idCmdFirst AS DWORD, _
    BYVAL idCmdLast AS DWORD) AS DWORD
#ELSE
DECLARE FUNCTION SHFind_InitMenuPopup IMPORT "SHELL32.DLL" ALIAS "SHDinf_InitMenuPopup" ( _
   BYVAL hmenu AS DWORD _                               ' __in HMENU hmenu
 , BYVAL hwnd AS DWORD _                                ' __in HWND hwnd
 , BYVAL idCmdFirst AS DWORD _                          ' __in UINT idCmdFirst
 , BYVAL idCmdLast AS DWORD _                           ' __in UINT idCmdLast
 ) AS IContextMenu                                      ' IContextMenu *
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SHCreateShellFolderViewEx LIB "Shell32.dll" _
    ALIAS "SHCreateShellFolderViewEx" (pcsfv AS CSFV, ppsv AS ANY) AS LONG
#ELSE
DECLARE FUNCTION SHCreateShellFolderViewEx IMPORT "SHELL32.DLL" ALIAS "SHCreateShellFolderViewEx" ( _
   BYREF pcsfv AS CSFV _                                ' __in LPCSFV pcsfv
 , BYREF ppsv AS IShellView _                           ' __out IShellView **ppsv
 ) AS LONG                                              ' HRESULT
#ENDIF

'//
'// PROPIDs for Internet Shortcuts (FMTID_Intshcut) to be used with
'// IPropertySetStorage/IPropertyStorage
'//
'// The known property ids and their variant types are:
'//      PID_IS_URL          [VT_LPWSTR]   URL
'//      PID_IS_NAME         [VT_LPWSTR]   Name of the internet shortcut
'//      PID_IS_WORKINGDIR   [VT_LPWSTR]   Working directory for the shortcut
'//      PID_IS_HOTKEY       [VT_UI2]      Hotkey for the shortcut
'//      PID_IS_SHOWCMD      [VT_I4]       Show command for shortcut
'//      PID_IS_ICONINDEX    [VT_I4]       Index into file that has icon
'//      PID_IS_ICONFILE     [VT_LPWSTR]   File that has the icon
'//      PID_IS_WHATSNEW     [VT_LPWSTR]   What's New text
'//      PID_IS_AUTHOR       [VT_LPWSTR]   Author
'//      PID_IS_DESCRIPTION  [VT_LPWSTR]   Description text of site
'//      PID_IS_COMMENT      [VT_LPWSTR]   User annotated comment
'//

%PID_IS_URL         = 2
%PID_IS_NAME        = 4
%PID_IS_WORKINGDIR  = 5
%PID_IS_HOTKEY      = 6
%PID_IS_SHOWCMD     = 7
%PID_IS_ICONINDEX   = 8
%PID_IS_ICONFILE    = 9
%PID_IS_WHATSNEW    = 10
%PID_IS_AUTHOR      = 11
%PID_IS_DESCRIPTION = 12
%PID_IS_COMMENT     = 13

'//
'// PROPIDs for Internet Sites (FMTID_InternetSite) to be used with
'// IPropertySetStorage/IPropertyStorage
'//
'// The known property ids and their variant types are:
'//      PID_INTSITE_WHATSNEW     [VT_LPWSTR]   What's New text
'//      PID_INTSITE_AUTHOR       [VT_LPWSTR]   Author
'//      PID_INTSITE_LASTVISIT    [VT_FILETIME] Time site was last visited
'//      PID_INTSITE_LASTMOD      [VT_FILETIME] Time site was last modified
'//      PID_INTSITE_VISITCOUNT   [VT_UI4]      Number of times user has visited
'//      PID_INTSITE_DESCRIPTION  [VT_LPWSTR]   Description text of site
'//      PID_INTSITE_COMMENT      [VT_LPWSTR]   User annotated comment
'//      PID_INTSITE_RECURSE      [VT_UI4]      Levels to recurse (0-3)
'//      PID_INTSITE_WATCH        [VT_UI4]      PIDISM_ flags
'//      PID_INTSITE_SUBSCRIPTION [VT_UI8]      Subscription cookie
'//      PID_INTSITE_URL          [VT_LPWSTR]   URL
'//      PID_INTSITE_TITLE        [VT_LPWSTR]   Title
'//      PID_INTSITE_CODEPAGE     [VT_UI4]      Codepage of the document
'//      PID_INTSITE_TRACKING     [VT_UI4]      Tracking
'//      PID_INTSITE_ICONINDEX    [VT_I4]       Retrieve the index to the icon
'//      PID_INTSITE_ICONFILE     [VT_LPWSTR]   Retrieve the file containing the icon index.


%PID_INTSITE_WHATSNEW     = 2
%PID_INTSITE_AUTHOR       = 3
%PID_INTSITE_LASTVISIT    = 4
%PID_INTSITE_LASTMOD      = 5
%PID_INTSITE_VISITCOUNT   = 6
%PID_INTSITE_DESCRIPTION  = 7
%PID_INTSITE_COMMENT      = 8
%PID_INTSITE_FLAGS        = 9
%PID_INTSITE_CONTENTLEN   = 10
%PID_INTSITE_CONTENTCODE  = 11
%PID_INTSITE_RECURSE      = 12
%PID_INTSITE_WATCH        = 13
%PID_INTSITE_SUBSCRIPTION = 14
%PID_INTSITE_URL          = 15
%PID_INTSITE_TITLE        = 16
%PID_INTSITE_CODEPAGE     = 18
%PID_INTSITE_TRACKING     = 19
%PID_INTSITE_ICONINDEX    = 20
%PID_INTSITE_ICONFILE     = 21


'// Flags for PID_IS_FLAGS
%PIDISF_RECENTLYCHANGED  = &H00000001???
%PIDISF_CACHEDSTICKY     = &H00000002???
%PIDISF_CACHEIMAGES      = &H00000010???
%PIDISF_FOLLOWALLLINKS   = &H00000020???

'// Values for PID_INTSITE_WATCH
%PIDISM_GLOBAL           = 0      ' // Monitor based on global setting
%PIDISM_WATCH            = 1      ' // User says watch
%PIDISM_DONTWATCH        = 2      ' // User says don't watch


'////////////////////////////////////////////////////////////////////
'//
'// The shell keeps track of some per-user state to handle display
'// options that is of major interest to ISVs.
'// The key one requested right now is "DoubleClickInWebView".

'typedef struct {
'    BOOL fShowAllObjects : 1;
'    BOOL fShowExtensions : 1;
'    BOOL fNoConfirmRecycle : 1;

'    BOOL fShowSysFiles : 1;
'    BOOL fShowCompColor : 1;
'    BOOL fDoubleClickInWebView : 1;
'    BOOL fDesktopHTML : 1;
'    BOOL fWin95Classic : 1;
'    BOOL fDontPrettyPath : 1;
'    BOOL fShowAttribCol : 1; // No longer used, dead bit
'    BOOL fMapNetDrvBtn : 1;
'    BOOL fShowInfoTip : 1;
'    BOOL fHideIcons : 1;
'    BOOL fWebView : 1;
'    BOOL fFilter : 1;
'    BOOL fShowSuperHidden : 1;
'    BOOL fNoNetCrawling : 1;

'    DWORD dwWin95Unused; // Win95 only - no longer supported pszHiddenFileExts
'    UINT  uWin95Unused; // Win95 only - no longer supported cbHiddenFileExts

'    // Note: Not a typo!  This is a persisted structure so we cannot use LPARAM
'    LONG   lParamSort;
'    int    iSortDirection;

'    UINT   version;

'    // new for win2k. need notUsed var to calc the right size of ie4 struct
'    // FIELD_OFFSET does not work on bit fields
'    UINT uNotUsed; // feel free to rename and use
'    BOOL fSepProcess: 1;

'    // new for Whistler.
'    BOOL fStartPanelOn: 1;       //Indicates if the Whistler StartPanel mode is ON or OFF.
'    BOOL fShowStartPage: 1;      //Indicates if the Whistler StartPage on desktop is ON or OFF.

'    // new for Windows Vista
'    BOOL fAutoCheckSelect: 1;
'    BOOL fIconsOnly: 1;
'    BOOL fShowTypeOverlay: 1;

'    UINT fSpareFlags : 11;

'} SHELLSTATEA, *LPSHELLSTATEA;

' // Size = 32 bytes
TYPE SHELLSTATEA BYTE
   fShowAllObjects       AS BIT * 1 IN DWORD
   fShowExtensions       AS BIT * 1
   fNoConfirmRecycle     AS BIT * 1
   fShowSysFiles         AS BIT * 1
   fShowCompColor        AS BIT * 1
   fDoubleClickInWebView AS BIT * 1
   fDesktopHTML          AS BIT * 1
   fWin95Classic         AS BIT * 1
   fDontPrettyPath       AS BIT * 1
   fShowAttribCol        AS BIT * 1   ' // No longer used, dead bit
   fMapNetDrvBtn         AS BIT * 1
   fShowInfoTip          AS BIT * 1
   fHideIcons            AS BIT * 1
   fWebView              AS BIT * 1
   fFilter               AS BIT * 1
   fShowSuperHidden      AS BIT * 1
   fNoNetCrawling        AS BIT * 1
   dwWin95Unused         AS DWORD   ' DWORD dwWin95Unused; // Win95 only - no longer supported pszHiddenFileExts
   uWin95Unused          AS DWORD   ' UINT  uWin95Unused; // Win95 only - no longer supported cbHiddenFileExts
   ' // Note: Not a typo!  This is a persisted structure so we cannot use LPARAM
   lParamSort            AS LONG    ' LONG   lParamSort
   iSortDirection        AS LONG    ' int    iSortDirection
   version               AS DWORD   ' UINT   version
   ' // new for win2k. need notUsed var to calc the right size of ie4 struct
   ' // FIELD_OFFSET does not work on bit fields
   uNotUsed              AS DWORD   ' UINT uNotUsed; // feel free to rename and use
   fSepProcess           AS BIT * 1 IN DWORD
   ' // new for Whistler.
   fStartPanelOn         AS BIT * 1   ' // Indicates if the Whistler StartPage mode is ON or OFF.
   fShowStartPage        AS BIT * 1   ' // Indicates if the Whistler StartPage on desktop is ON or OFF.
   ' // new for Longhorn
   fAutoCheckSelect      AS BIT * 1
   fIconsOnly            AS BIT * 1
   fShowTypeOverlay      AS BIT * 1
   fSpareFlags           AS BIT * 11
END TYPE

'typedef struct {
'    BOOL fShowAllObjects : 1;
'    BOOL fShowExtensions : 1;
'    BOOL fNoConfirmRecycle : 1;
'    BOOL fShowSysFiles : 1;
'    BOOL fShowCompColor : 1;
'    BOOL fDoubleClickInWebView : 1;
'    BOOL fDesktopHTML : 1;
'    BOOL fWin95Classic : 1;
'    BOOL fDontPrettyPath : 1;
'    BOOL fShowAttribCol : 1;
'    BOOL fMapNetDrvBtn : 1;
'    BOOL fShowInfoTip : 1;
'    BOOL fHideIcons : 1;
'    BOOL fWebView : 1;
'    BOOL fFilter : 1;
'    BOOL fShowSuperHidden : 1;
'    BOOL fNoNetCrawling : 1;

'    DWORD dwWin95Unused; // Win95 only - no longer supported pszHiddenFileExts
'    UINT  uWin95Unused; // Win95 only - no longer supported cbHiddenFileExts

'    // Note: Not a typo!  This is a persisted structure so we cannot use LPARAM
'    LONG   lParamSort;
'    int    iSortDirection;
'    UINT   version;

'    // new for win2k. need notUsed var to calc the right size of ie4 struct
'    // FIELD_OFFSET does not work on bit fields
'    UINT uNotUsed; // feel free to rename and use
'    BOOL fSepProcess: 1;

'    // new for Whistler.
'    BOOL fStartPanelOn: 1;       //Indicates if the Whistler StartPage mode is ON or OFF.
'    BOOL fShowStartPage: 1;      //Indicates if the Whistler StartPage on desktop is ON or OFF.

'    // new for Windows Vista
'    BOOL fAutoCheckSelect: 1;
'    BOOL fIconsOnly: 1;
'    BOOL fShowTypeOverlay: 1;

'    // If you need a new flag, steal a bit from from fSpareFlags.
'    // Also, keep SHELLFLAGSTATE and SHGetSettings in sync when adding new flags.
'    UINT fSpareFlags : 11;

'} SHELLSTATEW, *LPSHELLSTATEW;

' // Size = 32 bytes
TYPE SHELLSTATEW BYTE
   fShowAllObjects       AS BIT * 1 IN DWORD
   fShowExtensions       AS BIT * 1
   fNoConfirmRecycle     AS BIT * 1
   fShowSysFiles         AS BIT * 1
   fShowCompColor        AS BIT * 1
   fDoubleClickInWebView AS BIT * 1
   fDesktopHTML          AS BIT * 1
   fWin95Classic         AS BIT * 1
   fDontPrettyPath       AS BIT * 1
   fShowAttribCol        AS BIT * 1   ' // No longer used, dead bit
   fMapNetDrvBtn         AS BIT * 1
   fShowInfoTip          AS BIT * 1
   fHideIcons            AS BIT * 1
   fWebView              AS BIT * 1
   fFilter               AS BIT * 1
   fShowSuperHidden      AS BIT * 1
   fNoNetCrawling        AS BIT * 1
   dwWin95Unused         AS DWORD   ' DWORD dwWin95Unused; // Win95 only - no longer supported pszHiddenFileExts
   uWin95Unused          AS DWORD   ' UINT  uWin95Unused; // Win95 only - no longer supported cbHiddenFileExts
   ' // Note: Not a typo!  This is a persisted structure so we cannot use LPARAM
   lParamSort            AS LONG    ' LONG   lParamSort
   iSortDirection        AS LONG    ' int    iSortDirection
   version               AS DWORD   ' UINT   version
   ' // new for win2k. need notUsed var to calc the right size of ie4 struct
   ' // FIELD_OFFSET does not work on bit fields
   uNotUsed              AS DWORD   ' UINT uNotUsed; // feel free to rename and use
   fSepProcess           AS BIT * 1 IN DWORD
   ' // new for Whistler.
   fStartPanelOn         AS BIT * 1   ' // Indicates if the Whistler StartPage mode is ON or OFF.
   fShowStartPage        AS BIT * 1   ' // Indicates if the Whistler StartPage on desktop is ON or OFF.
   ' // new for Longhorn
   fAutoCheckSelect      AS BIT * 1
   fIconsOnly            AS BIT * 1
   fShowTypeOverlay      AS BIT * 1
   fSpareFlags           AS BIT * 11
END TYPE

MACRO SHELLSTATE = SHELLSTATEA

%SHELLSTATEVERSION_IE4   = 9
%SHELLSTATEVERSION_WIN2K = 10

'#define SHELLSTATE_SIZE_WIN95 FIELD_OFFSET(SHELLSTATE,lParamSort)
'#define SHELLSTATE_SIZE_NT4   FIELD_OFFSET(SHELLSTATE,version)
'#define SHELLSTATE_SIZE_IE4   FIELD_OFFSET(SHELLSTATE,uNotUsed)
'#define SHELLSTATE_SIZE_WIN2K sizeof(SHELLSTATE)

DECLARE SUB SHGetSetSettings IMPORT "SHELL32.DLL" ALIAS "SHGetSetSettings" ( _
   BYREF lpss AS SHELLSTATE _                           ' __in LPSHELLSTATE lpss
 , BYVAL dwMask AS DWORD _                              ' __in DWORD dwMask
 , BYVAL bSet AS LONG _                                 ' __in BOOL bSet
 )                                                      ' void

'//
'//  SysFiles are these windows special files:
'//      "dll sys vxd 386 drv"
'//
'//  hidden files are files with the FILE_ATTRIBUTE_HIDDEN attribute
'//
'//  system files are files with the FILE_ATTRIBUTE_SYSTEM attribute
'//
'//      fShowAllObjects fShowSysFiles   Result
'//      --------------- -------------   ------
'//      0               0               hide hidden + SysFiles + system files
'//      0               1               hide hidden files.
'//      1               0               show all files.
'//      1               1               show all files.
'//

' // Size = 4 bytes
TYPE SHELLFLAGSTATE
   fShowAllObjects       AS BIT * 1 IN DWORD   ' BOOL fShowAllObjects : 1
   fShowExtensions       AS BIT * 1            ' BOOL fShowExtensions : 1
   fNoConfirmRecycle     AS BIT * 1            ' BOOL fNoConfirmRecycle : 1
   fShowSysFiles         AS BIT * 1            ' BOOL fShowSysFiles : 1
   fShowCompColor        AS BIT * 1            ' BOOL fShowCompColor : 1
   fDoubleClickInWebView AS BIT * 1            ' BOOL fDoubleClickInWebView : 1
   fDesktopHTML          AS BIT * 1            ' BOOL fDesktopHTML : 1
   fWin95Classic         AS BIT * 1            ' BOOL fWin95Classic : 1
   fDontPrettyPath       AS BIT * 1            ' BOOL fDontPrettyPath : 1
   fShowAttribCol        AS BIT * 1            ' BOOL fShowAttribCol : 1
   fMapNetDrvBtn         AS BIT * 1            ' BOOL fMapNetDrvBtn : 1
   fShowInfoTip          AS BIT * 1            ' BOOL fShowInfoTip : 1
   fHideIcons            AS BIT * 1            ' BOOL fHideIcons : 1
'#if (NTDDI_VERSION >= NTDDI_VISTA)
#IF %WINVER >= &H0600
   fAutoCheckSelect      AS BIT * 1
   fIconsOnly            AS BIT * 1
   fRestFlags            AS BIT * 1            ' // when adding additional flags keep SHELLSTATE and SHGetSettings in sync.
#ELSE
   fRestFlags            AS BIT * 3            ' UINT fRestFlags : 3
#ENDIF
END TYPE

%SSF_SHOWALLOBJECTS          = &H00000001???
%SSF_SHOWEXTENSIONS          = &H00000002???
%SSF_HIDDENFILEEXTS          = &H00000004???
%SSF_SERVERADMINUI           = &H00000004???
%SSF_SHOWCOMPCOLOR           = &H00000008???
%SSF_SORTCOLUMNS             = &H00000010???
%SSF_SHOWSYSFILES            = &H00000020???
%SSF_DOUBLECLICKINWEBVIEW    = &H00000080???
%SSF_SHOWATTRIBCOL           = &H00000100???
%SSF_DESKTOPHTML             = &H00000200???
%SSF_WIN95CLASSIC            = &H00000400???
%SSF_DONTPRETTYPATH          = &H00000800???
%SSF_SHOWINFOTIP             = &H00002000???
%SSF_MAPNETDRVBUTTON         = &H00001000???
%SSF_NOCONFIRMRECYCLE        = &H00008000???
%SSF_HIDEICONS               = &H00004000???
%SSF_FILTER                  = &H00010000???
%SSF_WEBVIEW                 = &H00020000???
%SSF_SHOWSUPERHIDDEN         = &H00040000???
%SSF_SEPPROCESS              = &H00080000???
'#if (NTDDI_VERSION >= NTDDI_WINXP)
%SSF_NONETCRAWLING           = &H00100000???
%SSF_STARTPANELON            = &H00200000???
%SSF_SHOWSTARTPAGE           = &H00400000???
'#endif  // NTDDI_WINXP
'#if (NTDDI_VERSION >= NTDDI_VISTA)
%SSF_AUTOCHECKSELECT         = &H00800000???
%SSF_ICONSONLY               = &H01000000???
%SSF_SHOWTYPEOVERLAY         = &H02000000???
'#endif  // NTDDI_VISTA

'// SHGetSettings(LPSHELLFLAGSTATE lpss, DWORD dwMask)
'//
'// Specify the bits you are interested in in dwMask and they will be
'// filled out in the lpss structure.
'//
'// When these settings change, a WM_SETTINGCHANGE message is sent
'// with the string lParam value of "ShellState".
'//
DECLARE SUB SHGetSettings IMPORT "SHELL32.DLL" ALIAS "SHGetSettings" ( _
   BYREF lpsfs AS SHELLFLAGSTATE _                      ' __in LPSHELLFLAGSTATE lpsfs
 , BYVAL dwMask AS DWORD _                              ' __in DWORD dwMask
 )                                                      ' void

'// SHBindToParent(LPCITEMIDLIST pidl, REFIID riid, void **ppv, LPCITEMIDLIST *ppidlLast)
'//
'// Given a pidl, you can get an interface pointer (as specified by riid) of the pidl's parent folder (in ppv)
'// If ppidlLast is non-NULL, you can also get the pidl of the last item.
'//
#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SHBindToParent LIB "Shell32.dll" ALIAS "SHBindToParent" _
    (BYVAL pidl AS ITEMIDLIST PTR, riid AS GUID, ppv AS ANY, _
    ppidlLast AS ANY) AS LONG
#ELSE
DECLARE FUNCTION SHBindToParent IMPORT "SHELL32.DLL" ALIAS "SHBindToParent" ( _
   BYVAL pidl AS DWORD _                                ' __in PCIDLIST_ABSOLUTE pidl
 , BYREF riid AS GUID _                                 ' __in REFIID riid
 , BYREF ppv AS ANY _                                   ' __out VOID **ppv
 , BYREF ppidlLast AS ANY _                             ' __out_opt PCUITEMID_CHILD *ppidlLast
 ) AS LONG                                              ' HRESULT
#ENDIF

'#if (NTDDI_VERSION >= NTDDI_VISTA)

'// Same as SHBindToParent, except you also specify which root to use.
#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SHBindToFolderIDListParent LIB "Shell32.dll" _
    ALIAS "SHBindToFolderIDListParent" (psfRoot AS ANY, _
    pidl AS ITEMIDLIST, riid AS GUID, ppv AS ANY, _
    ppidlLast AS ANY) AS LONG
#ELSE
DECLARE FUNCTION SHBindToFolderIDListParent IMPORT "SHELL32.DLL" ALIAS "SHBindToFolderIDListParent" ( _
   BYVAL psfRoot AS IShellFolder _                      ' __in_opt IShellFolder *psfRoot
 , BYVAL pidl AS DWORD _                                ' __in PCUIDLIST_RELATIVE pidl
 , BYREF riid AS GUID _                                 ' __in REFIID riid
 , BYREF ppv AS ANY _                                   ' __out VOID **ppv
 , BYREF ppidlLast AS ANY _                             ' __out_opt PCUITEMID_CHILD *ppidlLast
 ) AS LONG                                              ' HRESULT
#ENDIF

'// same as SHBindToFolderIDListParent but with a IBindCtx *pbc;
#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SHBindToFolderIDListParentEx LIB "Shell32.dll" _
    ALIAS "SHBindToFolderIDListParentEx" (psfRoot AS ANY, _
    pidl AS ITEMIDLIST, ppbc AS ANY, riid AS GUID, _
    ppv AS ANY, ppidlLast AS ANY) AS LONG
#ELSE
DECLARE FUNCTION SHBindToFolderIDListParentEx IMPORT "SHELL32.DLL" ALIAS "SHBindToFolderIDListParentEx" ( _
   BYVAL psfRoot AS IShellFolder _                      ' __in_opt IShellFolder *psfRoot
 , BYVAL pidl AS DWORD _                                ' __in PCUIDLIST_RELATIVE pidl
 , BYVAL ppbc AS IBindCtx _                             ' __in_opt IBindCtx *ppbc
 , BYREF riid AS GUID _                                 ' __in REFIID riid
 , BYREF ppv AS ANY _                                   ' __out VOID **ppv
 , BYREF ppidlLast AS ANY _                             ' __out_opt PCUITEMID_CHILD *ppidlLast
 ) AS LONG                                              ' HRESULT
#ENDIF

'// helper function that gets the desktop object, then calls BindToObject on that
#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SHBindToObject LIB "Shell32.dll" ALIAS "SHBindToObject" _
    (psf AS ANY, pidl AS ITEMIDLIST, pbc AS ANY, riid AS GUID, _
    ppv AS ANY) AS LONG
#ELSE
DECLARE FUNCTION SHBindToObject IMPORT "SHELL32.DLL" ALIAS "SHBindToObject" ( _
   BYVAL psf AS IShellFolder _                          ' __in_opt IShellFolder *psf
 , BYVAL pidl AS DWORD _                                ' __in PCUIDLIST_RELATIVE pidl
 , BYVAL ppbc AS IBindCtx _                             ' __in_opt IBindCtx *ppbc
 , BYREF riid AS GUID _                                 ' __in REFIID riid
 , BYREF ppv AS ANY _                                   ' __out void **ppv
 ) AS LONG                                              ' HRESULT
#ENDIF

'#endif // NTDDI_VISTA

'// SHSTDAPI SHParseDisplayName(PCWSTR pszName, IBindCtx *pbc, LPITEMIDLIST *ppidl, SFGAOF sfgaoIn, SFGAOF *psfgaoOut)
'//
'//  given a string it will call psfDesktop->ParseDisplayName() to try and create a pidl
'//  if no pbc specified, it uses the preferred options for parsing.
'//  this includes mapping file system paths to their appropriate aliased location (RegisterObjectParam(STR_PARSE_TRANSLATE_ALIASES))
'//  psfgaoOut is optional for SFGAO attributes
'//
'#if (NTDDI_VERSION >= NTDDI_WINXP)
#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SHParseDisplayName LIB "Shell32.dll" _
    ALIAS "SHParseDisplayName" _
    (pszName      AS WSTRINGZ, _
    pbc           AS ANY, _
    ppidl         AS ANY, _
    BYVAL sfgoaIn AS DWORD, _   ' SFGAOF
    psfgaoOut     AS DWORD _    ' SFGAOF
    ) AS LONG
#ELSE
DECLARE FUNCTION SHParseDisplayName IMPORT "SHELL32.DLL" ALIAS "SHParseDisplayname" ( _
   BYREF pszName AS WSTRINGZ _                          ' __in LPCWSTR pszName
 , BYVAL pbc AS IBindCtx _                              ' __in_opt IBindCtx *pbc
 , BYREF ppidl AS ANY _                                 ' __out PIDLIST_ABSOLUTE *ppidl
 , BYVAL sfgaoIn AS DWORD _                             ' __in SFGAOF sfgaoIn
 , BYREF psfgaoOut AS DWORD _                           ' __out_opt SFGAOF *psfgaoOut
 ) AS LONG                                              ' HRESULT
#ENDIF
'#endif // NTDDI_WINXP

'// SHPathPrepareForWrite(HWND hwnd, IUnknown *punkEnableModless, LPCTSTR pszPath, DWORD dwFlags)
'//
'// DESCRIPTION:
'//     This API will prepare the path for the caller.  This includes:
'// 1. Prompting for the ejectable media to be re-inserted. (Floppy, CD-ROM, ZIP drive, etc.)
'// 2. Prompting for the media to be formatted. (Floppy, hard drive, etc.)
'// 3. Remount mapped drives if the connection was lost. (\\unc\share mapped to N: becomes disconnected)
'// 4. If the path doesn't exist, create it.  (SHPPFW_DIRCREATE and SHPPFW_ASKDIRCREATE)
'// 5. Display an error if the media is read only. (SHPPFW_NOWRITECHECK not set)
'//
'// PARAMETERS:
'//      hwnd: Parernt window for UI.  NULL means don't display UI. OPTIONAL
'//      punkEnableModless: Parent that will be set to modal during UI using IOleInPlaceActiveObject::EnableModeless(). OPTIONAL
'//      pszPath: Path to verify is valid for writting.  This can be a UNC or file drive path.  The path
'//               should only contain directories.  Pass SHPPFW_IGNOREFILENAME if the last path segment
'//               is always filename to ignore.
'//      dwFlags: SHPPFW_* Flags to modify behavior
'//
'//-------------------------------------------------------------------------
%SHPPFW_NONE             = &H00000000???
%SHPPFW_DIRCREATE        = &H00000001???              ' // Create the directory if it doesn't exist without asking the user.
%SHPPFW_ASKDIRCREATE     = &H00000002???              ' // Create the directory if it doesn't exist after asking the user.
%SHPPFW_IGNOREFILENAME   = &H00000004???              ' // Ignore the last item in pszPath because it's a file.  Example: pszPath="C:\DirA\DirB", only use "C:\DirA".
%SHPPFW_NOWRITECHECK     = &H00000008???              ' // Caller only needs to read from the drive, so don't check if it's READ ONLY.
'#if (NTDDI_VERSION >= NTDDI_WINXP)
%SHPPFW_MEDIACHECKONLY   = &H00000010???              ' // do the retrys on the media (or net path), return errors if the file can't be found
'#endif // NTDDI_WINXP
%SHPPFW_DEFAULT          = %SHPPFW_DIRCREATE          ' // May change

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SHPathPrepareForWriteA LIB "Shell32.dll" _
    ALIAS "SHPathPrepareForWriteA" (BYVAL hwnd AS DWORD, _
    punkEnableModless AS ANY, pszPath AS ASCIIZ, BYVAL dwFlags AS DWORD) _
    AS LONG
#ELSE
DECLARE FUNCTION SHPathPrepareForWriteA IMPORT "SHELL32.DLL" ALIAS "SHPathPrepareForWriteA" ( _
   BYVAL hwnd AS DWORD _                                ' __in HWND hwnd
 , BYVAL punkEnableModless AS IUnknown _                ' __in IUnknown *punkEnableModless
 , BYREF pszPath AS ASCIIZ _                            ' __in LPCSTR pszPath
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 ) AS LONG                                              ' HRESULT
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SHPathPrepareForWriteW LIB "Shell32.dll" _
    ALIAS "SHPathPrepareForWriteW" (BYVAL hwnd AS DWORD, _
    punkEnableModless AS ANY, pszPath AS WSTRINGZ, BYVAL dwFlags AS DWORD) _
    AS LONG
#ELSE
DECLARE FUNCTION SHPathPrepareForWriteW IMPORT "SHELL32.DLL" ALIAS "SHPathPrepareForWriteW" ( _
   BYVAL hwnd AS DWORD _                                ' __in HWND hwnd
 , BYVAL punkEnableModless AS IUnknown _                ' __in IUnknown *punkEnableModless
 , BYREF pszPath AS WSTRINGZ _                          ' __in LPCWSTR pszPath
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 ) AS LONG                                              ' HRESULT
#ENDIF

#IF %DEF(%UNICODE)
   MACRO SHPathPrepareForWrite = SHPathPrepareForWriteW
#ELSE
   MACRO SHPathPrepareForWrite = SHPathPrepareForWriteA
#ENDIF

'//--------------------------------------------------------------------------
'//
'// Interface used for exposing the INI file methods on a shortcut file
'//
'//
'//--------------------------------------------------------------------------

' ########################################################################################
' INamedPropertyBag interface
' IID = FB700430-952C-11D1-946F-000000000000
' Inherited interface = IUnknown
' Minimum operating system: Windows XP
' ########################################################################################

INTERFACE INamedPropertyBag $IID_INamedPropertyBag

   INHERIT IUnknown

   ' =====================================================================================
   METHOD ReadPropertyNPB ( _                           ' VTable offset = 12
     BYVAL pszBagname AS DWORD _                        ' __in LPCOLESTR pszBagname
   , BYVAL pszPropName AS DWORD _                       ' __in LPCOLESTR pszPropName
   , BYREF pVar AS PROPVARIANT _                        ' __inout PROPVARIANT *pVar
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD WritePropertyNPB ( _                          ' VTable offset = 16
     BYVAL pszBagname AS DWORD _                        ' __in LPCOLESTR pszBagname
   , BYVAL pszPropName AS DWORD _                       ' __in LPCOLESTR pszPropName
   , BYREF pVar AS PROPVARIANT _                        ' __in PROPVARIANT *pVar
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RemovePropertyNPB ( _                         ' VTable offset = 20
     BYVAL pszBagname AS DWORD _                        ' __in LPCOLESTR pszBagname
   , BYVAL pszPropName AS DWORD _                       ' __in LPCOLESTR pszPropName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#IF %DEF(%URLMON_INC)
'//    NOTE: urlmon.h must be included before shlobj.h to access this function.
'//
'//    SoftwareUpdateMessageBox
'//
'//    Provides a standard message box for the alerting the user that a software
'//    update is available or installed. No UI will be displayed if there is no
'//    update available or if the available update version is less than or equal
'//    to the Advertised update version.
'//
'//    hWnd                - [in] Handle of owner window
'//    szDistUnit          - [in] Unique identifier string for a code distribution unit. For
'//                               ActiveX controls and Active Setup installed components, this
'//                               is typically a GUID string.
'//    dwFlags             - [in] Must be 0.
'//    psdi                - [in,out] Pointer to SOFTDISTINFO ( see URLMon.h ). May be NULL.
'//                                cbSize should be initialized
'//                                by the caller to sizeof(SOFTDISTINFO), dwReserved should be set to 0.
'//
'//    RETURNS:
'//
'//    IDNO     - The user chose cancel. If *pbRemind is FALSE, the caller should save the
'//               update version from the SOFTDISTINFO and pass it in as the Advertised
'//               version in future calls.
'//
'//    IDYES    - The user has selected Update Now/About Update. The caller should navigate to
'//               the SOFTDISTINFO's pszHREF to initiate the install or learn about it.
'//               The caller should save the update version from the SOFTDISTINFO and pass
'//               it in as the Advertised version in future calls.
'//
'//    IDIGNORE - There is no pending software update. Note: There is
'//               no Ignore button in the standard UI. This occurs if the available
'//               version is less than the installed version or is not present or if the
'//               Advertised version is greater than or equal to the update version.
'//
'//    IDABORT  - An error occured. Call GetSoftwareUpdateInfo() for a more specific HRESULT.
'//               Note: There is no Abort button in the standard UI.


DECLARE FUNCTION SoftwareUpdateMessageBox IMPORT "SHDOCVW.DLL" ALIAS "SoftwareUpdateMessageBox" ( _
   BYVAL hwnd AS DWORD _                                ' __in HWND hwnd
 , BYREF pszDistUnit AS WSTRINGZ _                      ' __in LPCWSTR pszDistUnit
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYREF psdi AS SOFTDISTINFO _                         ' __in LPSOFTDISTINFO psdi
 ) AS DWORD                                             ' DWORD

#ENDIF   ' // if __urlmon_h__


'//  SHPropStgCreate()
'//  Wrap of IPropertySetStorage::Open/Create
'//
'//  This function ensures proper handling of code page retrieval/assignment
'//  for the requested property set operation.
'//
'//  psstg,          //  Address of IPropertySetStorage vtable
'//  fmtid,          //  property set ID
'//  pclsid,         //  class ID associated with the set. This can be NULL
'//  grfFlags,       //  PROPSETFLAG_xxx.  All sets containing ansi bytes should be created with
'                    //  PROPSETFLAG_ANSI, otherwise PROPSETFLAG_DEFAULT.
'//  grfMode,        //  STGM_ flags.  Must contain STGM_DIRECT|STGM_EXCLUSIVE.
'//  dwDisposition,  //  OPEN_EXISTING. OPEN_ALWAYS, CREATE_NEW, or CREATE_ALWAYS
'//  IPropertyStorage** ppstg,  // Address to receive requested vtable
'//  puCodePage      //  Optional address to receive the code page ID for the set.
'//
#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SHPropStgCreate LIB "Shell32.dll" _
    ALIAS "SHPropStgCreate" (psstg AS ANY, fmtid AS GUID, _ 'REFFMTID
    pclsid AS GUID, BYVAL grfFlags AS DWORD, BYVAL grfMode AS DWORD, _
    BYVAL dwDisposition AS DWORD, ppstg AS ANY, puCodePage AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION SHPropStgCreate IMPORT "SHELL32.DLL" ALIAS "SHPropStgCreate" ( _
   BYVAL psstg AS IPropertySetStorage _                 ' __in IPropertySetStorage *psstg
 , BYREF fmtid AS GUID _                                ' __in REFFMTID fmtid
 , BYREF pclsid AS GUID _                               ' __in_opt const CLSID *pclsid
 , BYVAL grfFlags AS DWORD _                            ' __in DWORD grfFlags
 , BYVAL grfMode AS DWORD _                             ' __in DWORD grfMode
 , BYVAL dwDisposition AS DWORD _                       ' __in DWORD dwDisposition
 , BYREF ppstg AS IPropertyStorage _                    ' __out IPropertyStorage **ppstg
 , BYREF puCodePage AS DWORD _                          ' __out_opt UINT *puCodePage
 ) AS LONG                                              ' HRESULT
#ENDIF

'//  SHPropStgReadMultiple()
'//  IPropertyStorage::ReadMultiple wrap
'//
'//  The wrap ensures ANSI/UNICODE translations are handled properly for
'//  legacy property sets.
'//
'//  pps,       // address of IPropertyStorage vtable.
'//  uCodePage, //Code page value retrieved from SHCreatePropertySet
'//  cpspec,    //Count of properties being read
'//  rgpspec,   //Array of the properties to be read
'//  rgvar      //Array of PROPVARIANTs containing the property values on return
'//
#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SHPropStgReadMultiple LIB "Shell32.dll" _
    ALIAS "SHPropStgReadMultiple" (pps AS ANY, BYVAL ducodepage AS DWORD, _
    BYVAL cpspec AS DWORD, rgpspec AS ANY, rgvar AS ANY) AS LONG
#ELSE
DECLARE FUNCTION SHPropStgReadMultiple IMPORT "SHELL32.DLL" ALIAS "SHPropStgReadMultiple" ( _
   BYVAL pps AS IPropertyStorage _                      ' __in IPropertyStorage *pps
 , BYVAL uCodePage AS DWORD _                           ' __in UINT uCodePage
 , BYVAL cpspec AS DWORD _                              ' __in ULONG cpspec
 , BYREF rgpspec AS PROPSPEC _                          ' __in PROPSPEC const rgpspec[]
 , BYREF rgvar AS PROPVARIANT _                         ' __in PROPVARIANT rgvar[]
 ) AS LONG                                              ' HRESULT
#ENDIF

'//  SHPropStgWriteMultiple()
'//  IPropertyStorage::WriteMultiple wrap
'//
'//  The wrap ensures ANSI/UNICODE translations are handled properly for
'//  legacy property sets.
'//
'//  pps,       // address of IPropertyStorage vtable.
'//  uCodePage, // code page retrieved from SHCreatePropertySet.
'//  cpspec,    // The number of properties being set
'//  rgpspec,   // Property specifiers
'//  rgvar,     // Array of PROPVARIANT values
'//  propidNameFirst // Minimum value for property identifiers. This value should be >= PID_FIRST_USABLE
'//
#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SHPropStgWriteMultiple LIB "Shell32.dll" _
    ALIAS "SHPropStgWriteMultiple" (pps AS ANY, puCodePage AS DWORD, _
    BYVAL cpspec AS DWORD, rgpspec AS ANY, rgvar AS ANY, _
    BYVAL propidNameFirst AS DWORD _ ' PROPID
    ) AS LONG
#ELSE
DECLARE FUNCTION SHPropStgWriteMultiple IMPORT "SHELL32.DLL" ALIAS "SHPropStgWriteMultiple" ( _
   BYVAL pps AS IPropertyStorage _                      ' __in IPropertyStorage *pps
 , BYVAL uCodePage AS DWORD _                           ' __in UINT *uCodePage
 , BYVAL cpspec AS DWORD _                              ' __in ULONG cpspec
 , BYREF rgpspec AS PROPSPEC _                          ' __in PROPSPEC const rgpspec[]
 , BYREF rgvar AS PROPVARIANT _                         ' __in PROPVARIANT rgvar[]
 , BYVAL propidNameFirst AS DWORD _                     ' __in PROPID propidNameFirst
 ) AS LONG                                              ' HRESULT
#ENDIF

'#if (NTDDI_VERSION >= NTDDI_WINXP)
' Note: Implemented only as unicode version.
'SHSTDAPI SHCreateFileExtractIconA(LPCSTR pszFile, DWORD dwFileAttributes, REFIID riid, void **ppv);
'SHSTDAPI SHCreateFileExtractIconW(LPCWSTR pszFile, DWORD dwFileAttributes, REFIID riid, void **ppv);
#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SHCreateFileExtractIconW LIB "Shell32.dll" _
    ALIAS "SHCreateFileExtractIconW" (pszFile AS WSTRING, _
    BYVAL dwFileAttributes AS DWORD, riid AS GUID, ppv AS ANY) AS LONG
#ELSE
DECLARE FUNCTION SHCreateFileExtractIconW IMPORT "SHELL32.DLL" ALIAS "SHCreateFileExtractIconW" ( _
   BYREF pszFile AS WSTRINGZ _                          ' __in LPCWSTR pszFile
 , BYVAL dwFileAttributes AS DWORD _                    ' __in DWORD dwFileAttributes
 , BYREF riid AS GUID _                                 ' __in REFIID riid
 , BYREF ppv AS ANY _                                   ' __out void **ppv
 ) AS LONG                                              ' HRESULT
#ENDIF

MACRO SHCreateFileExtractIcon = SHCreateFileExtractIconW

'#include <pshpack8.h>
'#include <poppack.h>        /* Return to byte packing */

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SHLimitInputEdit LIB "Shell32.dll" _
    ALIAS "SHLimitInputEdit" (BYVAL hwndEdit AS DWORD, psf AS ANY) AS LONG
#ELSE
DECLARE FUNCTION SHLimitInputEdit IMPORT "SHELL32.DLL" ALIAS "SHLimitInputEdit" ( _
   BYVAL hwndEdit AS DWORD _                            ' __in HWND hwndEdit
 , BYVAL psf AS IShellFolder _                          ' __in IShellFolder *psf
 ) AS LONG                                              ' HRESULT
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SHGetAttributesFromDataObject LIB "Shell32.dll" _
    ALIAS "SHGetAttributesFromDataObject" (pdo AS ANY, _
    BYVAL dwAttributeMask AS DWORD, pdwAttributes AS DWORD, _
    pcItems AS DWORD) AS LONG
#ELSE
DECLARE FUNCTION SHGetAttributesFromDataObject IMPORT "SHELL32.DLL" ALIAS "SHGetAttributesFromDataObject" ( _
   BYVAL pdo AS IDataObject _                           ' __in IDataObject *pdo
 , BYVAL dwAttributeMask AS DWORD _                     ' __in DWORD dwAttributeMask
 , BYREF pdwAttributes AS DWORD _                       ' __out_opt DWORD *pdwAttributes
 , BYREF pcItems AS DWORD _                             ' __out_opt UINT *pcItems
 ) AS LONG                                              ' HRESULT
#ENDIF

'#endif  // NTDDI_WINXP

'#if (NTDDI_VERSION >= NTDDI_WIN2K)

'//
'// The SHMultiFileProperties API displays a property sheet for a
'// set of files specified in an IDList Array.
'//
'// Parameters:
'//      pdtobj  - Data object containing list of files.  The data
'//                object must provide the "Shell IDList Array"
'//                clipboard format.  The parent folder's implementation of
'//                IShellFolder::GetDisplayNameOf must return a fully-qualified
'//                filesystem path for each item in response to the
'//                SHGDN_FORPARSING flag.
'//
'//      dwFlags - Reserved for future use.  Should be set to 0.
'//
'// Returns:
'//      S_OK
'//
#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SHMultiFileProperties LIB "Shell32.dll" _
    ALIAS "SHMultiFileProperties" (pdtobj AS ANY, BYVAL dwFlags AS DWORD) _
    AS LONG
#ELSE
DECLARE FUNCTION SHMultiFileProperties IMPORT "SHELL32.DLL" ALIAS "SHMultiFileProperties" ( _
   BYVAL pdtobj AS IDataObject _                        ' __in IDataObject *pdtobj
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 ) AS LONG                                              ' HRESULT
#ENDIF

'#endif  // NTDDI_WIN2K

'#if (_WIN32_IE >= 0x0600)
'//
'//
'typedef void (CALLBACK *PFNASYNCICONTASKBALLBACK)(LPCITEMIDLIST pidl, LPVOID pvData, LPVOID pvHint, INT iIconIndex, INT iOpenIconIndex);

'// HRESULT SHMapIDListToImageListIndexAsync(IShellTaskScheduler* pts, IShellFolder *psf, LPCITEMIDLIST pidl, UINT flags,
'//                                            PFNASYNCICONTASKBALLBACK pfn, LPVOID pvData, LPVOID pvHint, int *piIndex, int *piIndexSel);
'// A usefull function for asynchronously mapping idlist into index into system
'// image list.  Optionally it can also look up the index of the selected icon.
'// pts          Task scheduler interface to use to create the background task
'// psf          Shell folder relating to the pidl
'// pidl         Item whose icon is requested
'// flags        GIL_ flags
'// pfn          Function called back when the background task is done
'// pvData       User data passed back in the (*pfn) callback
'// pvHint       User data passed back in the (*pfn) callback
'// piIndex      Icon index returned. This is the temporary index if the function returns E_PENDING. The final index will be provided thru the callback
'// piIndexSel   Optional icon index for the open icon case (GIL_OPENICON).
'//
'// Returns S_OK if all the requested info was available. E_PENDING means that you get temporary icons, and will be called back
'//              asynchronously with the final icons. Other failure code means the function failed.

' Note: Not implemented in Windows Vista and later versions.
'DECLARE FUNCTION SHMapIDListToImageListIndexAsync IMPORT "SHELL32.DLL" ALIAS "SHMapIDListToImageListIndexAsync" ( _
'   BYVAL pts AS IShellTaskScheduler _                   ' __in IShellTaskScheduler *pts
' , BYVAL psf AS IShellFolder _                          ' __in IShellFolder *psf
' , BYVAL pidl AS DWORD _                                ' __in LPCITEMIDLIST pidl
' , BYVAL flags AS DWORD _                               ' __in UINT flags
' , BYVAL pfn AS DWORD _                                 ' __in PFNASYNCICONTASKBALLBACK pfn
' , BYVAL pvData AS DWORD _                              ' __in void *pvData
' , BYVAL pvHint AS DWORD _                              ' __in void *pvHint
' , BYREF piIndex AS LONG _                              ' __out int *piIndex
' , BYREF piIndexSel AS LONG _                           ' __out int *piIndexSel
' ) AS LONG                                              ' HRESULT

'#endif // (_WIN32_IE >= 0x0600)

'// A usefull function in Defview for mapping idlist into index into system
'// image list.  Optionally it can also look up the index of the selected
'// icon.
DECLARE FUNCTION SHMapIDListToImageListIndex IMPORT "SHELL32.DLL" ALIAS "SHMapIDListToImageListIndex" ( _
   BYVAL pshf AS IShellFolder _                         ' __in IShellFolder *pshf
 , BYVAL pidl AS DWORD _                                ' __in LPCITEMIDLIST pidl
 , BYREF piIndexSel AS LONG _                           ' __out int *piIndexSel
 ) AS LONG                                              ' int

DECLARE FUNCTION SHCLSIDFromString IMPORT "SHELL32.DLL" ALIAS "SHCLSIDFromString" ( _
   BYREF psz AS WSTRINGZ _                              ' __in LPCWSTR psz
 , BYREF pcClsid AS GUID _                              ' __out CLSID pcClsid
 ) AS LONG                                              ' HRESULT

' It is not supported under Windows Vista and later. Use OleFlushClipboard instead.
'DECLARE FUNCTION SHFlushClipboard IMPORT "SHELL32.DLL" ALIAS "SHFlushClipboard" ( _
' ) AS LONG                                              ' __in HRESULT

' // deprecated: use CreateClassMoniker(CLSID_YourOwnClsid, ...)
#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SHCreateQueryCancelAutoPlayMoniker LIB "Shell32.dll" _
    ALIAS "SHCreateQueryCancelAutoPlayMoniker" (ppmoniker AS ANY) AS LONG
#ELSE
DECLARE FUNCTION SHCreateQueryCancelAutoPlayMoniker IMPORT "SHELL32.DLL" ALIAS "SHCreateQueryCancelAutoPlayMoniker" ( _
   BYREF ppmoniker AS IMoniker _                        ' __out IMoniker **ppmoniker
 ) AS LONG                                              ' HRESULT
#ENDIF

' Deprecated. Not available as of Windows Vista.
'DECLARE FUNCTION SHGetShellStyleHInstance IMPORT "SHELL32.DLL" ALIAS "SHGetShellStyleHInstance" ( _
' ) AS DWORD                                             ' HINSTANCE

' ========================================================================================
' PerUserInit
' Creates My Documents and other special folders, initializes them as needed, and creates
' the Send To shortcut menu item for My Documents.
' Note Applications do not need to call this function because the operating system already
' does so.
' This function does not have an associated header or library file so it must be called by
' ordinal value. Call LoadLibrary with the dynamic-link library (DLL) name Mydocs.dll to
' obtain a module handle. Then call GetProcAddress with that module handle and the ordinal
' number 7 to use this function.
' Minimum operating system: Windows 2000.
' This function is available through Microsoft Windows XP Service Pack 2 (SP2) and Windows
' Server 2003. It might be altered or unavailable in subsequent versions of Windows.
' ========================================================================================

SUB PerUserInit ()

   LOCAL hLib  AS DWORD
   LOCAL pAddr AS DWORD

   hLib = LoadLibrary("MYDOCS.DLL")
   IF hLib = %NULL THEN EXIT SUB
   pAddr = GetProcAddress(hLib, BYVAL MAK(DWORD, 7, 0))
   IF pAddr THEN CALL DWORD pAddr USING PerUserInit()
   FreeLibrary hLib

END SUB

DECLARE FUNCTION SHRunControlPanel IMPORT "SHELL32.DLL" ALIAS "SHRunControlPanel" ( _
   BYREF lpcszCmdLine AS WSTRINGZ _                     ' __in LPCWSTR lpcszCmdLine
 , BYVAL hwndMsgParent AS DWORD _                       ' __in HWND hwndMsgParent
 ) AS LONG                                              ' BOOL

' ========================================================================================
' PickIconDlg
' Displays a dialog box that allows a user to select an icon from a module.
' Minimum operating system: Windows XP.
' This function is available through Microsoft Windows XP Service Pack 2 (SP2) and Windows
' Server 2003. It might be altered or unavailable in subsequent versions of Windows.
' Note: This function is exported by name in Windows XP, but only by ordinal in previous
' versions. Besides, the icon path parameter must be an asciiz string in Windows 95/98 and
' unicode in 2000/XP/Vista/Windows 7.
' ========================================================================================

DECLARE FUNCTION PickIconDlg IMPORT "SHELL32.DLL" ALIAS "PickIconDlg" ( _
   BYVAL hwnd AS DWORD _                                ' __in HWND hwnd
 , BYREF pszIconPath AS WSTRINGZ _                      ' __inout LPWSTR pszIconPath
 , BYVAL cchIconPath AS DWORD _                         ' __in UINT cchIconPath
 , BYREF piIconIndex AS LONG _                          ' __inout int *piIconIndex
 ) AS LONG                                              ' int

' // Wrapper function for Windows 95/98
DECLARE FUNCTION Proto_PickIconDlgA ( _
   BYVAL hwnd AS DWORD _                                ' __in HWND hwnd
 , BYREF szIconPath AS ASCIIZ _                         ' __inout LPCSTR pszIconPath
 , BYVAL cchIconPath AS DWORD _                         ' __in UINT cchIconPath
 , BYREF piIconIndex AS LONG _                          ' __inout int *piIconIndex
 ) AS LONG                                              ' int

FUNCTION PickIconDialogA ( _
   BYVAL hwnd AS DWORD _                                ' __in HWND hwnd
 , BYREF szIconPath AS ASCIIZ _                         ' __inout LPCSTR pszIconPath
 , BYVAL cchIconPath AS DWORD _                         ' __in UINT cchIconPath
 , BYREF piIconIndex AS LONG _                          ' __inoutint *piIconIndex
   ) AS LONG                                            ' int

   LOCAL hr AS LONG
   LOCAL hLib AS DWORD
   LOCAL pPickDlg AS DWORD

   ' // Load the shell library
   hLib = LoadLibrary("SHELL32.DLL")
   IF hLib = %NULL THEN
      FUNCTION = GetLastError
      EXIT FUNCTION
   END IF
   ' // Get the address of the PickIconDlg (ordinal 62)
   pPickDlg = GetProcAddress(hLib, BYVAL MAK(LONG, 62, 0))
   IF ISFALSE pPickDlg THEN
      hr = GetLastError
   ELSE
      CALL DWORD pPickDlg USING Proto_PickIconDlgA(hwnd, szIconPath, LEN(szIconPath), piIconIndex) TO hr
   END IF
   ' // Free the library and return the result code
   FreeLibrary hLib
   FUNCTION = hr

END FUNCTION

' // Wrapper function for Windows 2000
DECLARE FUNCTION Proto_PickIconDlgW ( _
   BYVAL hwnd AS DWORD _                                ' __in HWND hwnd
 , BYREF szIconPath AS WSTRINGZ _                       ' __inout LPWSTR pszIconPath
 , BYVAL cchIconPath AS DWORD _                         ' __in UINT cchIconPath
 , BYREF piIconIndex AS LONG _                          ' __inout int *piIconIndex
 ) AS LONG                                              ' int

FUNCTION PickIconDialogW ( _
   BYVAL hwnd AS DWORD _                                ' __in HWND hwnd
 , BYREF wszIconPath AS WSTRINGZ _                      ' __inout LPCSTR pszIconPath
 , BYVAL cchIconPath AS DWORD _                         ' __in UINT cchIconPath
 , BYREF piIconIndex AS LONG _                          ' __inoutint *piIconIndex
   ) AS LONG                                            ' int

   LOCAL hr AS LONG
   LOCAL hLib AS DWORD
   LOCAL pPickDlg AS DWORD

   ' // Load the shell library
   hLib = LoadLibrary("SHELL32.DLL")
   IF hLib = %NULL THEN
      FUNCTION = GetLastError
      EXIT FUNCTION
   END IF
   ' // Get the address of the PickIconDlg (ordinal 62)
   pPickDlg = GetProcAddress(hLib, BYVAL MAK(LONG, 62, 0))
   IF ISFALSE pPickDlg THEN
      hr = GetLastError
   ELSE
      CALL DWORD pPickDlg USING Proto_PickIconDlgW(hwnd, wszIconPath, LEN(wszIconPath), piIconIndex) TO hr
   END IF
   ' // Free the library and return the result code
   FreeLibrary hLib
   FUNCTION = hr

END FUNCTION

'#include <pshpack8.h>

' Important  This structure cannot be used with operating systems later than Windows 2000.
' Note: szFileName contains the menu name. This string is Unicode in Windows 2000 or XP.
' // Size = 16 bytes
TYPE AASHELLMENUFILENAME BYTE
   cbTotal         AS INTEGER      ' SHORT
   rgbReserved(11) AS BYTE         ' BYTE[12]
   szFileName(0)   AS WORD         ' WCHAR  szFileName[1]; // variable length string
END TYPE

' // Size = 20 bytes
TYPE AASHELLMENUITEM DWORD FILL
   lpReserved1 AS DWORD                     ' void*
   iReserved   AS LONG                      ' int
   uiReserved  AS DWORD                     ' UINT
   lpName      AS AASHELLMENUFILENAME PTR   ' LPAASHELLMENUFILENAME
   psz         AS WSTRINGZ PTR              ' LPWSTR
END TYPE

'#include <poppack.h>        /* Return to byte packing */

'#if (NTDDI_VERSION >= NTDDI_WIN7)
'// returns an IStream or IStorage via riid/ppv
#IF %DEF(%USEPBDECL)
DECLARE FUNCTION StgMakeUniqueName LIB "Shell32.dll" _
    ALIAS "StgMakeUniqueName" (pstgParent AS ANY, _ ' IStorage PTR
    pszFileSpec AS WSTRINGZ, BYVAL grfMode AS DWORD, riid AS GUID, _
    ppv AS ANY) AS LONG
#ELSE
DECLARE FUNCTION StgMakeUniqueName IMPORT "SHELL32.DLL" ALIAS "StgMakeUniqueName" ( _
   BYVAL pstgParentA AS IStorage _                      ' __in IStorage *pstgParent
 , BYREF pszFileSpec AS WSTRINGZ _                      ' __in PCWSTR pszFileSpec
 , BYVAL grfMode AS DWORD _                             ' __in DWORD grfMode
 , BYREF riid AS GUID _                                 ' __in REFIID riid
 , BYREF ppv AS ANY _                                   ' __out void **ppv
 ) AS LONG                                              ' HRESULT
#ENDIF
'#endif // NTDDI_WIN7

'#if (_WIN32_IE >= _WIN32_IE_IE70)
' enum IESHORTCUTFLAGS
%IESHORTCUT_NEWBROWSER    = &H01???
%IESHORTCUT_OPENNEWTAB    = &H02???
%IESHORTCUT_FORCENAVIGATE = &H04???
%IESHORTCUT_BACKGROUNDTAB = &H08???
'#endif // _WIN32_IE_IE70

'#if (_WIN32_IE >= _WIN32_IE_XP)

DECLARE FUNCTION ImportPrivacySettings IMPORT "SHDOCVW.DLL" ALIAS "ImportPrivacySettings" ( _
   BYREF pszFilename AS WSTRINGZ _                      ' __in LPCWSTR pszFilename
 , BYREF pfParsePrivacyPreferences AS LONG _            ' __inout BOOL* pfParsePrivacyPreferences
 , BYREF pfParsePerSiteRules AS LONG _                  ' __inout BOOL* pfParsePerSiteRules
 ) AS LONG                                              ' BOOL

'#ifndef IEnumPrivacyRecords
'typedef interface IEnumPrivacyRecords IEnumPrivacyRecords;
'#endif

' Note: The IEnumPrivacyRecords interface is defined in MSHTMLC.INC.
#IF %DEF(%USEPBDECL)
DECLARE FUNCTION DoPrivacyDlg LIB "ShDocVW.dll" ALIAS "DoPrivacyDlg" _
    (BYVAL hwndOwner AS DWORD, pszUrl AS WSTRINGZ, pPrivacyEnum AS ANY, _
    BYVAL fReportAllSites AS LONG) AS LONG
#ELSE
DECLARE FUNCTION DoPrivacyDlg IMPORT "SHDOCVW.DLL" ALIAS "DoPrivacyDlg" ( _
   BYVAL hwndOwner AS DWORD _                           ' __in HWND hwndOwner
 , BYREF pszUrl AS WSTRINGZ _                           ' __in LPWSTR pszUrl
 , BYVAL pPrivacyEnum AS IUnknown _                     ' __in IEnumPrivacyRecords *pPrivacyEnum
 , BYVAL fReportAllSites AS LONG _                      ' __in BOOL fReportAllSites
 ) AS LONG                                              ' HRESULT
#ENDIF

'#endif  // _WIN32_IE_XP

'#include <poppack.h>

' ########################################################################################
' IShellTaskScheduler2 interface
' Inherited interface = IShellTaskScheduler
' Removed from the Vista and Windows 7 SDKs.
' ########################################################################################

'%ITSSFLAG_TASK_PLACEINFRONT          = &H00000001???
'%ITSSFLAG_TASK_PLACEINBACK           = &H00000002???

'INTERFACE IShellTaskScheduler2 $IID_IShellTaskScheduler2

'   INHERIT IUnknown

'   ' =====================================================================================
'   METHOD AddTask ( _                                   ' VTable offset = 12
'     BYVAL pTask AS IRunnableTask _                     ' __in IRunnableTask * pTask
'   , BYREF rtoid AS GUID _                              ' __in REFTASKOWNERID rtoid
'   , BYVAL lParam AS DWORD _                            ' __in DWORD_PTR lParam
'   , BYVAL dwPriority AS DWORD _                        ' __in DWORD dwPriority
'   ) AS LONG                                            ' HRESULT
'   ' =====================================================================================
'   METHOD RemoveTasks ( _                               ' VTable offset = 16
'     BYVAL lParam AS DWORD _                            ' __in DWORD_PTR lParam
'   , BYVAL fWaitIfRunning AS LONG _                     ' __in BOOL fWaitIfRunning
'   ) AS LONG                                            ' HRESULT
'   ' =====================================================================================
'   METHOD CountTasks ( _                                ' VTable offset = 20
'     BYREF rtoid AS GUID _                              ' __in REFTASKOWNERID rtoid
'   ) AS LONG                                            ' HRESULT
'   ' =====================================================================================
'   METHOD Status ( _                                    ' VTable offset = 24
'     BYVAL dwReleaseStatus AS DWORD _                   ' __in DWORD dwReleaseStatus
'   , BYVAL dwThreadTimeout AS DWORD _                   ' __in DWORD dwThreadTimeout
'   ) AS LONG                                            ' HRESULT
'   ' =====================================================================================
'   METHOD AddTask2 ( _                                  ' VTable offset = 28
'     BYREF rtoid AS GUID _                              ' __in REFTASKOWNERID rtoid
'   , BYVAL lParam AS DWORD _                            ' __in DWORD_PTR lParam
'   , BYVAL dwPriority AS DWORD _                        ' __in DWORD dwPriority
'   , BYVAL grfFlags AS DWORD _                          ' __in DWORD grfFlags
'   ) AS LONG                                            ' HRESULT
'   ' =====================================================================================
'   METHOD MoveTask ( _                                  ' VTable offset = 32
'     BYREF rtoid AS GUID _                              ' __in REFTASKOWNERID rtoid
'   , BYVAL lParam AS DWORD _                            ' __in DWORD_PTR lParam
'   , BYVAL dwPriority AS DWORD _                        ' __in DWORD dwPriority
'   , BYVAL grfFlags AS DWORD _                          ' __in DWORD grfFlags
'   ) AS LONG                                            ' HRESULT
'   ' =====================================================================================

'END INTERFACE
