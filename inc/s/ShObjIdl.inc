' ########################################################################################
' Microsoft Windows
' File: ShObjIdl.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

' ########################################################################################
' Library name: ShellObjects
' Version: 1.0, Locale ID = 0
' Library GUID: {50A7E9B1-70EF-11D1-B75A-00A0C90564FE}
' ########################################################################################

#INCLUDE THIS ONCE
%SHOBJIDL_INC = 1

' ========================================================================================
' ProgIDs (Program identifiers)
' ========================================================================================

' CLSID = {00021401-0000-0000-C000-000000000046}
$PROGID_ShellLink = "lnkfile"

'/* header files for imported files */
#INCLUDE ONCE "objidl.inc"
#INCLUDE ONCE "oleidl.inc"
#INCLUDE ONCE "oaidl.inc"
#INCLUDE ONCE "docobj.inc"
#INCLUDE ONCE "shtypes.inc"
#INCLUDE ONCE "servprov.inc"
#INCLUDE ONCE "comcat.inc"
#INCLUDE ONCE "propidl.inc"
#INCLUDE ONCE "prsht.inc"
#INCLUDE ONCE "propsys.inc"
#INCLUDE ONCE "sherrors.inc"
#INCLUDE ONCE "ObjectArray.inc"
#INCLUDE ONCE "sherrors.inc"
#INCLUDE ONCE "shellapi.inc"

'//===========================================================================
'//
'// IContextMenu interface
'//
'// [OverView]
'//
'//  The shell uses the IContextMenu interface in following three cases.
'//
'// case-1: The shell is loading context menu extensions.
'//
'//   When the user clicks the right mouse button on an item within the shell's
'//  name space (i.g., file, directory, server, work-group, etc.), it creates
'//  the default context menu for its type, then loads context menu extensions
'//  that are registered for that type (and its base type) so that they can
'//  add extra menu items. Those context menu extensions are registered at
'//  HKCR\{ProgID}\shellex\ContextMenuHandlers.
'//
'// case-2: The shell is retrieving a context menu of sub-folders in extended
'//   name-space.
'//
'//   When the explorer's name space is extended by name space extensions,
'//  the shell calls their IShellFolder::GetUIObjectOf to get the IContextMenu
'//  objects when it creates context menus for folders under those extended
'//  name spaces.
'//
'// case-3: The shell is loading non-default drag and drop handler for directories.
'//
'//   When the user performed a non-default drag and drop onto one of file
'//  system folders (i.e., directories), it loads shell extensions that are
'//  registered at HKCR\{ProgID}\DragDropHandlers.
'//
'//
'// [Member functions]
'//
'//
'// IContextMenu::QueryContextMenu
'//
'//   This member function may insert one or more menuitems to the specified
'//  menu (hmenu) at the specified location (indexMenu which is never be -1).
'//  The IDs of those menuitem must be in the specified range (idCmdFirst and
'//  idCmdLast). It returns the maximum menuitem ID offset (ushort) in the
'//  'code' field (low word) of the scode.
'//
'//   The uFlags specify the context. It may have one or more of following
'//  flags.
'//
'//  CMF_DEFAULTONLY: This flag is passed if the user is invoking the default
'//   action (typically by double-clicking, case 1 and 2 only). Context menu
'//   extensions (case 1) should not add any menu items, and returns NOERROR.
'//
'//  CMF_VERBSONLY: The explorer passes this flag if it is constructing
'//   a context menu for a short-cut object (case 1 and case 2 only). If this
'//   flag is passed, it should not add any menu-items that is not appropriate
'//   from a short-cut.
'//    A good example is the "Delete" menuitem, which confuses the user
'//   because it is not clear whether it deletes the link source item or the
'//   link itself.
'//
'//  CMF_EXPLORER: The explorer passes this flag if it has the left-side pane
'//   (case 1 and 2 only). Context menu extensions should ignore this flag.
'//
'//   High word (16-bit) are reserved for context specific communications
'//  and the rest of flags (13-bit) are reserved by the system.
'//
'//
'// IContextMenu::InvokeCommand
'//
'//   This member is called when the user has selected one of menuitems that
'//  are inserted by previous QueryContextMenu member. In this case, the
'//  LOWORD(lpici->lpVerb) contains the menuitem ID offset (menuitem ID -
'//  idCmdFirst).
'//
'//   This member function may also be called programmatically. In such a case,
'//  lpici->lpVerb specifies the canonical name of the command to be invoked,
'//  which is typically retrieved by GetCommandString member previously.
'//
'//  Parameters in lpci:
'//    cbSize -- Specifies the size of this structure (sizeof(*lpci))
'//    hwnd   -- Specifies the owner window for any message/dialog box.
'//    fMask  -- Specifies whether or not dwHotkey/hIcon paramter is valid.
'//    lpVerb -- Specifies the command to be invoked.
'//    lpParameters -- Parameters (optional)
'//    lpDirectory  -- Working directory (optional)
'//    nShow -- Specifies the flag to be passed to ShowWindow (SW_*).
'//    dwHotKey -- Hot key to be assigned to the app after invoked (optional).
'//    hIcon -- Specifies the icon (optional).
'//    hMonitor -- Specifies the default monitor (optional).
'//
'//
'// IContextMenu::GetCommandString
'//
'//   This member function is called by the explorer either to get the
'//  canonical (language independent) command name (uFlags == GCS_VERB) or
'//  the help text ((uFlags & GCS_HELPTEXT) != 0) for the specified command.
'//  The retrieved canonical string may be passed to its InvokeCommand
'//  member function to invoke a command programmatically. The explorer
'//  displays the help texts in its status bar; therefore, the length of
'//  the help text should be reasonably short (<40 characters).
'//
'//  Parameters:
'//   idCmd -- Specifies menuitem ID offset (from idCmdFirst)
'//   uFlags -- Either GCS_VERB or GCS_HELPTEXT
'//   pwReserved -- Reserved (must pass NULL when calling, must ignore when called)
'//   pszName -- Specifies the string buffer.
'//   cchMax -- Specifies the size of the string buffer.
'//
'//===========================================================================

'// QueryContextMenu uFlags
%CMF_NORMAL            = &H00000000???
%CMF_DEFAULTONLY       = &H00000001???
%CMF_VERBSONLY         = &H00000002???
%CMF_EXPLORE           = &H00000004???
%CMF_NOVERBS           = &H00000008???
%CMF_CANRENAME         = &H00000010???
%CMF_NODEFAULT         = &H00000020???
'#if (NTDDI_VERSION < NTDDI_VISTA)
%CMF_INCLUDESTATIC     = &H00000040???
'#endif
'#if (NTDDI_VERSION >= NTDDI_VISTA)
%CMF_ITEMMENU          = &H00000080???
'#endif
'#if (NTDDI_VERSION >= NTDDI_VISTA)
%CMF_EXTENDEDVERBS     = &H00000100???   ' // rarely used verbs
'#endif
%CMF_ASYNCVERBSTATE    = &H00000400???
%CMF_OPTIMIZEFORINVOKE = &H00000800???
%CMF_SYNCCASCADEMENU   = &H00001000???
%CMF_DONOTPICKDEFAULT  = &H00002000???
%CMF_RESERVED          = &Hffff0000???
%CMF_RESERVED          = &Hffff0000???   ' // View specific

'// GetCommandString uFlags
%GCS_VERBA         = &H00000000???     ' // canonical verb
%GCS_HELPTEXTA     = &H00000001???     ' // help text (for status bar)
%GCS_VALIDATEA     = &H00000002???     ' // validate command exists
%GCS_VERBW         = &H00000004???     ' // canonical verb (unicode)
%GCS_HELPTEXTW     = &H00000005???     ' // help text (unicode version)
%GCS_VALIDATEW     = &H00000006???     ' // validate command exists (unicode)
%GCS_VERBICONW     = &H00000014???     ' // icon string (unicode)
%GCS_UNICODE       = &H00000004???     ' // for bit testing - Unicode string

%GCS_VERB          = %GCS_VERBA
%GCS_HELPTEXT      = %GCS_HELPTEXTA
%GCS_VALIDATE      = %GCS_VALIDATEA

$CMDSTR_NEWFOLDERA       = "NewFolder"
$CMDSTR_VIEWLISTA        = "ViewList"
$CMDSTR_VIEWDETAILSA     = "ViewDetails"
$$CMDSTR_NEWFOLDERW      = "NewFolder"$$
$$CMDSTR_VIEWLISTW       = "ViewList"$$
$$CMDSTR_VIEWDETAILSW    = "ViewDetails"$$

#IF %DEF(%UNICODE)
MACRO CMDSTR_NEWFOLDER = $$CMDSTR_NEWFOLDERW
MACRO CMDSTR_VIEWLIST = $$CMDSTR_VIEWLISTW
MACRO CMDSTR_VIEWDETAILS = $$CMDSTR_VIEWDETAILSW
#ELSE
MACRO CMDSTR_NEWFOLDER = CMDSTR_NEWFOLDERA
MACRO CMDSTR_VIEWLIST = CMDSTR_VIEWLISTA
MACRO CMDSTR_VIEWDETAILS = CMDSTR_VIEWDETAILSA
#ENDIF

$CMDSTR_NEWFOLDER        = $CMDSTR_NEWFOLDERA
$CMDSTR_VIEWLIST         = $CMDSTR_VIEWLISTA
$CMDSTR_VIEWDETAILS      = $CMDSTR_VIEWDETAILSA

%CMIC_MASK_HOTKEY        = %SEE_MASK_HOTKEY
%CMIC_MASK_ICON          = %SEE_MASK_ICON
%CMIC_MASK_FLAG_NO_UI    = %SEE_MASK_FLAG_NO_UI
%CMIC_MASK_UNICODE       = %SEE_MASK_UNICODE
%CMIC_MASK_NO_CONSOLE    = %SEE_MASK_NO_CONSOLE
'#if (NTDDI_VERSION < NTDDI_VISTA)
'%CMIC_MASK_HASLINKNAME   = %SEE_MASK_HASLINKNAME   ' value not defined in any header
'%CMIC_MASK_HASTITLE      = %SEE_MASK_HASTITLE      ' value not defined in any header
'#endif  // NTDDI_VISTA
'%CMIC_MASK_FLAG_SEP_VDM  = %SEE_MASK_FLAG_SEPVDM   ' value not defined in any header
%CMIC_MASK_ASYNCOK       = %SEE_MASK_ASYNCOK
'#if (NTDDI_VERSION >= NTDDI_VISTA)
%CMIC_MASK_NOASYNC       = %SEE_MASK_NOASYNC
'#endif

'#if (_WIN32_IE >= _WIN32_IE_IE501)
%CMIC_MASK_SHIFT_DOWN    = &H10000000???
%CMIC_MASK_CONTROL_DOWN  = &H40000000???
'#endif  // _WIN32_IE_IE501
'#if (_WIN32_IE >= 0x0560)
%CMIC_MASK_FLAG_LOG_USAGE = %SEE_MASK_FLAG_LOG_USAGE
%CMIC_MASK_NOZONECHECKS   = %SEE_MASK_NOZONECHECKS
'#endif // (_WIN32_IE >= 0x560)

'#if (_WIN32_IE >= = &H0400)
%CMIC_MASK_PTINVOKE      = &H20000000???
'#endif

'#include <pshpack8.h>

' // Size = 36 bytes
TYPE CMINVOKECOMMANDINFO DWORD
   cbSize       AS DWORD        ' DWORD cbSize        // sizeof(CMINVOKECOMMANDINFO)
   fMask        AS DWORD        ' DWORD fMask         // any combination of CMIC_MASK_*
   hwnd         AS DWORD        ' HWND hwnd           // might be NULL (indicating no owner window)
   lpVerb       AS ASCIIZ PTR   ' LPCSTR lpVerb       // either a string or MAKEINTRESOURCE(idOffset)
   lpParameters AS ASCIIZ PTR   ' LPCSTR lpParameters // might be NULL (indicating no parameter)
   lpDirectory  AS ASCIIZ PTR   ' LPCSTR lpDirectory  // might be NULL (indicating no specific directory)
   nShow        AS LONG         ' int nShow           // one of SW_ values for ShowWindow() API
   dwHotKey     AS DWORD        ' DWORD dwHotKey
   hIcon        AS DWORD        ' HANDLE hIcon
END TYPE

' // Size = 64 bytes
TYPE CMINVOKECOMMANDINFOEX DWORD
   cbSize        AS DWORD            ' DWORD cbSize           // sizeof(CMINVOKECOMMANDINFO)
   fMask         AS DWORD            ' DWORD fMask            // any combination of CMIC_MASK_*
   hwnd          AS DWORD            ' HWND hwnd              // might be NULL (indicating no owner window)
   lpVerb        AS ASCIIZ PTR       ' LPCSTR lpVerb          // either a string or MAKEINTRESOURCE(idOffset)
   lpParameters  AS ASCIIZ PTR       ' LPCSTR lpParameters    // might be NULL (indicating no parameter)
   lpDirectory   AS ASCIIZ PTR       ' LPCSTR lpDirectory     // might be NULL (indicating no specific directory)
   nShow         AS LONG             ' int nShow              // one of SW_ values for ShowWindow() API
   dwHotKey      AS DWORD            ' DWORD dwHotKey
   hIcon         AS DWORD            ' HANDLE hIcon
   lpTitle       AS ASCIIZ PTR       ' LPCSTR lpTitle         // For CreateProcess-StartupInfo.lpTitle
   lpVerbW       AS WSTRINGZ PTR     ' LPCWSTR lpVerbW        // Unicode verb (for those who can use it)
   lpParametersW AS WSTRINGZ PTR     ' LPCWSTR lpParametersW  // Unicode parameters (for those who can use it)
   lpDirectoryW  AS WSTRINGZ PTR     ' LPCWSTR lpDirectoryW   // Unicode directory (for those who can use it)
   lpTitleW      AS WSTRINGZ PTR     ' LPCWSTR lpTitleW       // Unicode title (for those who can use it)
'#if (_WIN32_IE >= 0x0400)
   ptInvoke      AS POINT            ' POINT   ptInvoke       // Point where it's invoked
'#endif
END TYPE

'#include <poppack.h>        /* Return to byte packing */

' ########################################################################################
' IContextMenu interface
' IID = 000214E4-0000-0000-C000-000000000046
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IContextMenu_INTERFACE_DEFINED)
    %IContextMenu_INTERFACE_DEFINED = 1

$IID_IContextMenu = GUID$("{000214E4-0000-0000-C000-000000000046}")

INTERFACE IContextMenu $IID_IContextMenu

   INHERIT IUnknown

   ' =====================================================================================
   METHOD QueryContextMenu ( _                          ' VTable offset = 12
     BYVAL hmenu AS DWORD _                             ' __in HMENU hmenu
   , BYVAL indexMenu AS DWORD _                         ' __in UINT indexMenu
   , BYVAL idCmdFirst AS DWORD _                        ' __in UINT idCmdFirst
   , BYVAL idCmdLast AS DWORD _                         ' __in UINT idCmdLast
   , BYVAL uFlags AS DWORD _                            ' __in UINT uFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD InvokeCommand ( _                             ' VTable offset = 16
     BYREF lpici AS CMINVOKECOMMANDINFO _               ' __in LPCMINVOKECOMMANDINFO lpici
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCommandString ( _                          ' VTable offset = 20
     BYVAL idCmd AS DWORD _                             ' __in UINT_PTR idCmd
   , BYVAL uType AS DWORD _                             ' __in UINT uType
   , BYVAL pwReserved AS DWORD _                        ' __in UINT * pwReserved
   , BYREF pszName AS ASCIIZ _                          ' __out LPSTR pszName
   , BYVAL cchMax AS DWORD _                            ' __in UINT cchMax
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IContextMenu_INTERFACE_DEFINED__ */


' ########################################################################################
' IContextMenu2 interface
' IID = 000214F4-0000-0000-C000-000000000046
' Inherited interface = IContextMenu
' ########################################################################################

#IF NOT %DEF(%IContextMenu2_INTERFACE_DEFINED)
    %IContextMenu2_INTERFACE_DEFINED = 1

$IID_IContextMenu2 = GUID$("{000214F4-0000-0000-C000-000000000046}")

INTERFACE IContextMenu2 $IID_IContextMenu2

   INHERIT IUnknown

   ' =====================================================================================
   ' IContextMenu Methods
   ' =====================================================================================
   METHOD QueryContextMenu ( _                          ' VTable offset = 12
     BYVAL hmenu AS DWORD _                             ' __in HMENU hmenu
   , BYVAL indexMenu AS DWORD _                         ' __in UINT indexMenu
   , BYVAL idCmdFirst AS DWORD _                        ' __in UINT idCmdFirst
   , BYVAL idCmdLast AS DWORD _                         ' __in UINT idCmdLast
   , BYVAL uFlags AS DWORD _                            ' __in UINT uFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD InvokeCommand ( _                             ' VTable offset = 16
     BYREF lpici AS CMINVOKECOMMANDINFO _               ' __in LPCMINVOKECOMMANDINFO lpici
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCommandString ( _                          ' VTable offset = 20
     BYVAL idCmd AS DWORD _                             ' __in UINT_PTR idCmd
   , BYVAL uType AS DWORD _                             ' __in UINT uType
   , BYVAL pwReserved AS DWORD _                        ' __in UINT * pwReserved
   , BYREF pszName AS ASCIIZ _                          ' __out LPSTR pszName
   , BYVAL cchMax AS DWORD _                            ' __in UINT cchMax
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IContextMenu2 Method
   ' =====================================================================================
   METHOD HandleMenuMsg ( _                             ' VTable offset = 24
     BYVAL uMsg AS DWORD _                              ' __in UINT uMsg
   , BYVAL wParam AS DWORD _                            ' __in WPARAM wParam
   , BYVAL lParam AS LONG _                             ' __in LPARAM lParam
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IContextMenu2_INTERFACE_DEFINED__ */


' ########################################################################################
' IContextMenu3 interface
' IID = BCFCE0A0-EC17-11d0-8D10-00A0C90F2719
' Inherited interface = IContextMenu2
' ########################################################################################

#IF NOT %DEF(%IContextMenu3_INTERFACE_DEFINED)
    %IContextMenu3_INTERFACE_DEFINED = 1

$IID_IContextMenu3 = GUID$("{BCFCE0A0-EC17-11D0-8D10-00A0C90F2719}")

INTERFACE IContextMenu3 $IID_IContextMenu3

   INHERIT IUnknown

   ' =====================================================================================
   ' IContextMenu Methods
   ' =====================================================================================
   METHOD QueryContextMenu ( _                          ' VTable offset = 12
     BYVAL hmenu AS DWORD _                             ' __in HMENU hmenu
   , BYVAL indexMenu AS DWORD _                         ' __in UINT indexMenu
   , BYVAL idCmdFirst AS DWORD _                        ' __in UINT idCmdFirst
   , BYVAL idCmdLast AS DWORD _                         ' __in UINT idCmdLast
   , BYVAL uFlags AS DWORD _                            ' __in UINT uFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD InvokeCommand ( _                             ' VTable offset = 16
     BYREF lpici AS CMINVOKECOMMANDINFO _               ' __in LPCMINVOKECOMMANDINFO lpici
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCommandString ( _                          ' VTable offset = 20
     BYVAL idCmd AS DWORD _                             ' __in UINT_PTR idCmd
   , BYVAL uType AS DWORD _                             ' __in UINT uType
   , BYVAL pwReserved AS DWORD _                        ' __in UINT * pwReserved
   , BYREF pszName AS ASCIIZ _                          ' __out LPSTR pszName
   , BYVAL cchMax AS DWORD _                            ' __in UINT cchMax
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IContextMenu2 Method
   ' =====================================================================================
   METHOD HandleMenuMsg ( _                             ' VTable offset = 24
     BYVAL uMsg AS DWORD _                              ' __in UINT uMsg
   , BYVAL wParam AS DWORD _                            ' __in WPARAM wParam
   , BYVAL lParam AS LONG _                             ' __in LPARAM lParam
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IContextMenu3 Method
   ' =====================================================================================
   METHOD HandleMenuMsg2 ( _                            ' VTable offset = 28
     BYVAL uMsg AS DWORD _                              ' __in UINT uMsg
   , BYVAL wParam AS DWORD _                            ' __in WPARAM wParam
   , BYVAL lParam AS LONG _                             ' __in LPARAM lParam
   , BYREF plResult AS LONG _                           ' __out LRESULT* plResult
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IContextMenu3_INTERFACE_DEFINED__ */

' ########################################################################################
' IExecuteCommand interface
' IID = 7F9185B0-CB92-43C5-80A9-92277A4F7B54
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IExecuteCommand_INTERFACE_DEFINED)
    %IExecuteCommand_INTERFACE_DEFINED = 1

$IID_IExecuteCommand = GUID$("{7F9185B0-CB92-43C5-80A9-92277A4F7B54}")

INTERFACE IExecuteCommand $IID_IExecuteCommand

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetKeyState ( _                               ' VTable offset = 12
     BYVAL grfKeyState AS DWORD _                       ' __in DWORD grfKeyState
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetParameters ( _                             ' VTable offset = 16
     BYREF pszParameters AS WSTRINGZ _                  ' __in LPCWSTR pszParameters
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPosition ( _                               ' VTable offset = 20
     BYVAL pt AS POINT _                                ' __in POINT pt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetShowWindow ( _                             ' VTable offset = 24
     BYVAL nShow AS LONG _                              ' __in int nShow
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetNoShowUI ( _                               ' VTable offset = 28
     BYVAL fNoShowUI AS LONG _                          ' __in BOOL fNoShowUI
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetDirectory ( _                              ' VTable offset = 32
     BYREF pszDirectory AS WSTRINGZ _                   ' __in LPCWSTR pszDirectory
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Execute ( _                                   ' VTable offset = 36
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IExecuteCommand_INTERFACE_DEFINED__ */

' ########################################################################################
' IPersistFolder interface
' IID = 000214EA-0000-0000-C000-000000000046
' Inherited interface = IPersist
' ########################################################################################

#IF NOT %DEF(%IPersistFolder_INTERFACE_DEFINED)
    %IPersistFolder_INTERFACE_DEFINED = 1

$IID_IPersistFolder = GUID$("{000214EA-0000-0000-C000-000000000046}")

INTERFACE IPersistFolder $IID_IPersistFolder

   INHERIT IUnknown

   ' =====================================================================================
   ' IPersist Method
   ' =====================================================================================
   METHOD GetClassID ( _                                ' VTable offset = 12
     BYREF pClassID AS GUID _                           ' __out CLSID * pClassID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IPersistFolder Method
   ' =====================================================================================
   METHOD Initialize ( _                                ' VTable offset = 16
     BYVAL pidl AS DWORD _                              ' __in LPCITEMIDLIST pidl
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   '  /* __IPersistFolder_INTERFACE_DEFINED__ */


'//-------------------------------------------------------------------------
'//
'// IRunnableTask interface
'//
'//   This is a free threaded interface used for putting items on a background
'// scheduler for execution within the view.  It allows a scheduler to start and
'// stop tasks on as many worker threads as it deems necessary.
'//
'// Run(), Kill() and Suspend() may be called from different threads.
'//
'// [Member functions]
'//
'// IRunnableTask::Run(void)
'//   Initiate the task to run.  This should return E_PENDING if the task
'//   has been suspended.
'//
'// IRunnableTask::Kill(void)
'//
'// IRunnableTask::Suspend(void)
'//
'// IRunnableTask::Resume(void)
'//
'// IRunnableTask::IsRunning(void)
'//
'//-------------------------------------------------------------------------

'// Convenient state values
%IRTIR_TASK_NOT_RUNNING = 0
%IRTIR_TASK_RUNNING     = 1
%IRTIR_TASK_SUSPENDED   = 2
%IRTIR_TASK_PENDING     = 3
%IRTIR_TASK_FINISHED    = 4

' ########################################################################################
' IRunnableTask interface
' IID = 85788D00-6807-11D0-B810-00C04FD706EC
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IRunnableTask_INTERFACE_DEFINED)
    %IRunnableTask_INTERFACE_DEFINED = 1

$IID_IRunnableTask = GUID$("{85788D00-6807-11D0-B810-00C04FD706EC}")

INTERFACE IRunnableTask $IID_IRunnableTask

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Run ( _                                       ' VTable offset = 12
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Kill ( _                                      ' VTable offset = 16
     BYVAL fWait AS LONG _                              ' __in BOOL fWait
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Suspend ( _                                   ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Resume ( _                                    ' VTable offset = 24
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsRunning ( _                                 ' VTable offset = 24
   ) AS DWORD                                           ' ULONG
   ' =====================================================================================

END INTERFACE

#ENDIF   '  /* __IRunnableTask_INTERFACE_DEFINED__ */


'// ---IShellTaskScheduler
'// An interface for interacting with and controlling a task scheduler. This
'// interface does not need to be free-threaded unless the items in the queue
'// interact with the scheduler as well as the main execution thread on which the
'// task scheduler was created.

'// IShellTaskScheduler::AddTask()
'//      Adds Tasks to the scheduler's background queue. The TASKOWNERID allow particular types
'//      of tasks to be grouped so that they can be counted or removed. The lParam allows the task
'//      to be associated with a particular item (for example an item in a listview).
'// IShellTaskScheduler::RemoveTasks()
'//      Removes tasks from the scheduler's queue. These can be sepcified in terms of their TASKOWNERID
'//      or their LPARAM, or both, or neither (TOID_NULL && ITSAT_DEFAULT_LPARAM results in all tasks being
'//      removed). If a task that matches is currently running and ITaskScheduler::Status() has been
'//      passeed ITSSFLAG_KILL_ON_DESTROY then the scheduler will attempt to kill the current task. The
'//      fWaitIfRunning parameter is then passed to IRunnableTask::Kill().
'// IShellTaskScheduler::CountTasks()
'//      Counts the tasks in the queue depending upon the TASKOWNERID and the LPARAM passed. (TOID_NULL and
'//      ITSAT_DEFAULT_LPARAM will count all tasks in the queue)
'// IShellTaskScheduler::Status()
'//      This sets the ReleaseStatus for the current task and the background thread timeout. When
'//      ITaskScheduler::RemoveTasks() is called and there is a task currently running that matches
'//      ITSSFLAG_COMPLETE_ON_DESTROY will cause TRUE to be passed to the task's IRunnableTask::Kill().
'//      The dwThreadTimeout parameter if not set to the default will cause the background thread to
'//      die if no new tasks have been added to the queue in the timeout period. The Thread will be
'//      recreated when the next new task is added.

$TOID_NULL = $CLSID_NULL

'////////////////////////
'// Status() flags,
'// wait for the current task to complete before deleting the scheduler
%ITSSFLAG_COMPLETE_ON_DESTROY        = &H0000???

'// kill the current task (if there is one) when the task scheduler is deleted
%ITSSFLAG_KILL_ON_DESTROY            = &H0001???

%ITSSFLAG_SUPPORTS_TERMINATE         = &H0002???

%ITSSFLAG_FLAGS_MASK                 = &H0003???

'// set the timeout for killing the thread when the object is terminated.
'// this timeout can be used to stop the object from blocking the system
'// indefinitely.
%ITSSFLAG_THREAD_TERMINATE_TIMEOUT   = &H0010???

'// set the timeout for threads that are idle in the thread pool
%ITSSFLAG_THREAD_POOL_TIMEOUT        = &H0020???

'// The default timeout passed to release Status to determine how long the thread
'// can be asleep before the thread is expired
%ITSS_THREAD_DESTROY_DEFAULT_TIMEOUT = (10 * 1000)

'// default, we won't kill it...
%ITSS_THREAD_TERMINATE_TIMEOUT       = (%INFINITE)

'// there is no change to the thread timeout
%ITSS_THREAD_TIMEOUT_NO_CHANGE       = (%INFINITE - 1)

'// the LPARAM allows task to be associated with items thus all tasks owned by a
'// particular item can be accessed by passing a non default value for this parameter
%ITSAT_DEFAULT_LPARAM                = &HFFFFFFFF???

'// Task priorities
'// ---------------
'// This depends on the cooperation of tasks currently under execution. New tasks will
'// be inserted in the queue in priority order. If a task of a low priority is currently
'// under execution when a higher priority task is added, the scheduler will attempt
'// to suspend the task currently under execution. It will be resumed when the other tasks
'// have been completed.
%ITSAT_DEFAULT_PRIORITY              = &H10000000???
%ITSAT_MAX_PRIORITY                  = &H7FFFFFFF???
%ITSAT_MIN_PRIORITY                  = &H00000000???

' ########################################################################################
' IShellTaskScheduler interface
' IID = 6CCB7BE0-6807-11D0-B810-00C04FD706EC
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IShellTaskScheduler_INTERFACE_DEFINED)
    %IShellTaskScheduler_INTERFACE_DEFINED = 1

$IID_IShellTaskScheduler = GUID$("{6CCB7BE0-6807-11D0-B810-00C04FD706EC}")
$SID_ShellTaskScheduler = $IID_IShellTaskScheduler

INTERFACE IShellTaskScheduler $IID_IShellTaskScheduler

   INHERIT IUnknown

   ' =====================================================================================
   METHOD AddTask ( _                                   ' VTable offset = 12
     BYVAL pTask AS IRunnableTask _                     ' __in IRunnableTask * pTask
   , BYREF rtoid AS GUID _                              ' __in REFTASKOWNERID rtoid
   , BYVAL lParam AS DWORD _                            ' __in DWORD_PTR lParam
   , BYVAL dwPriority AS DWORD _                        ' __in DWORD dwPriority
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RemoveTasks ( _                               ' VTable offset = 16
     BYVAL lParam AS DWORD _                            ' __in DWORD_PTR lParam
   , BYVAL fWaitIfRunning AS LONG _                     ' __in BOOL fWaitIfRunning
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CountTasks ( _                                ' VTable offset = 20
     BYREF rtoid AS GUID _                              ' __in REFTASKOWNERID rtoid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Status ( _                                    ' VTable offset = 24
     BYVAL dwReleaseStatus AS DWORD _                   ' __in DWORD dwReleaseStatus
   , BYVAL dwThreadTimeout AS DWORD _                   ' __in DWORD dwThreadTimeout
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IShellTaskScheduler_INTERFACE_DEFINED__ */

' ########################################################################################
' IQueryCodePage interface
' IID = C7B236CE-EE80-11D0-985F-006008059382
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IQueryCodePage_INTERFACE_DEFINED)
    %IQueryCodePage_INTERFACE_DEFINED = 1

$IID_IQueryCodePage = GUID$("{C7B236CE-EE80-11D0-985F-006008059382}")

INTERFACE IQueryCodePage $IID_IQueryCodePage

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetCodePage ( _                               ' VTable offset = 12
     BYREF puiCodePage AS DWORD _                       ' __out UINT *puiCodePage
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetCodePage ( _                               ' VTable offset = 16
     BYVAKpuiCodePage AS DWORD _                        ' __in UINT uiCodePage
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IQueryCodePage_INTERFACE_DEFINED__ */

' ########################################################################################
' IPersistFolder2 interface
' IID = 1AC3D9F0-175C-11d1-95BE-00609797EA4F
' Inherited interface = IPersistFolder
' ########################################################################################

#IF NOT %DEF(%IPersistFolder2_INTERFACE_DEFINED)
    %IPersistFolder2_INTERFACE_DEFINED = 1

$IID_IPersistFolder2 = GUID$("{1AC3D9F0-175C-11d1-95BE-00609797EA4F}")

INTERFACE IPersistFolder2 $IID_IPersistFolder2

   INHERIT IUnknown

   ' =====================================================================================
   ' IPersist Method
   ' =====================================================================================
   METHOD GetClassID ( _                                ' VTable offset = 12
     BYREF pClassID AS GUID _                           ' __out CLSID * pClassID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IPersistFolder Method
   ' =====================================================================================
   METHOD Initialize ( _                                ' VTable offset = 16
     BYVAL pidl AS DWORD _                              ' __in LPCITEMIDLIST pidl
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IPersistFolder2 Method
   ' =====================================================================================
   METHOD GetCurFolder ( _                              ' VTable offset = 20
     BYREF ppidl AS DWORD _                             ' __out LPITEMIDLIST *ppidl
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IPersistFolder2_INTERFACE_DEFINED__ */

'#if (_WIN32_IE >= 0x0500)
%CSIDL_FLAG_PFTI_TRACKTARGET = &H4000&  ' CSIDL_FLAG_DONT_VERIFY
'#include <pshpack8.h>
' // Size = 1052 bytes
TYPE PERSIST_FOLDER_TARGET_INFO DWORD FILL
   pidlTargetFolder    AS DWORD            ' PIDLIST_ABSOLUTE
   szTargetParsingName AS WSTRINGZ * 260   ' WCHAR
   szNetworkProvider   AS WSTRINGZ * 260   ' WCHAR
   dwAttributes        AS DWORD            ' DWORD
   csidl               AS LONG             ' int
END TYPE
'#include <poppack.h>

' ########################################################################################
' IPersistFolder3 interface
' IID = CEF04FDF-FE72-11d2-87A5-00C04F6837CF
' Inherited interface = IPersistFolder2
' ########################################################################################

#IF NOT %DEF(%IPersistFolder3_INTERFACE_DEFINED)
    %IPersistFolder3_INTERFACE_DEFINED = 1

$IID_IPersistFolder3 = GUID$("{1AC3D9F0-175C-11d1-95BE-00609797EA4F}")

INTERFACE IPersistFolder3 $IID_IPersistFolder3

   INHERIT IUnknown

   ' =====================================================================================
   ' IPersist Method
   ' =====================================================================================
   METHOD GetClassID ( _                                ' VTable offset = 12
     BYREF pClassID AS GUID _                           ' __out CLSID * pClassID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IPersistFolder Method
   ' =====================================================================================
   METHOD Initialize ( _                                ' VTable offset = 16
     BYVAL pidl AS DWORD _                              ' __in LPCITEMIDLIST pidl
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IPersistFolder2 Method
   ' =====================================================================================
   METHOD GetCurFolder ( _                              ' VTable offset = 20
     BYREF ppidl AS DWORD _                             ' __out LPITEMIDLIST *ppidl
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IPersistFolder3 Methods
   ' =====================================================================================
   METHOD InitializeEx ( _                              ' VTable offset = 24
     BYVAL pbc AS IBindCtx _                            ' __in IBindCtx *pbc
   , BYVAL pidlRoot AS DWORD _                          ' __in PCIDLIST_ABSOLUTE pidlRoot
   , BYREF ppfti AS PERSIST_FOLDER_TARGET_INFO _        ' __in const PERSIST_FOLDER_TARGET_INFO *ppfti
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFolderTargetInfo ( _                       ' VTable offset = 28
     BYREF ppfti AS PERSIST_FOLDER_TARGET_INFO _        ' __out PERSIST_FOLDER_TARGET_INFO *ppfti
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IPersistFolder3_INTERFACE_DEFINED__ */


'#if (NTDDI_VERSION >= NTDDI_WINXP) || (_WIN32_IE >= _WIN32_IE_IE70)

' ########################################################################################
' IPersistIDList interface
' IID = 1079ACFC-29BD-11D3-8E0D-00C04F6837D5
' Inherited interface = IPersist
' ########################################################################################

#IF NOT %DEF(%IPersistIDList_INTERFACE_DEFINED)
    %IPersistIDList_INTERFACE_DEFINED = 1

$IID_IPersistIDList = GUID$("{1079ACFC-29BD-11D3-8E0D-00C04F6837D5}")

INTERFACE IPersistIDList $IID_IPersistIDList

   INHERIT IUnknown

   ' =====================================================================================
   ' IPersist Method
   ' =====================================================================================
   METHOD GetClassID ( _                                ' VTable offset = 12
     BYREF pClassID AS GUID _                           ' __out CLSID * pClassID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IPersistIDList Methods
   ' =====================================================================================
   METHOD SetIDList ( _                                 ' VTable offset = 16
     BYVAL pidl AS DWORD _                              ' __in LPCITEMIDLIST pidl
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetIDList ( _                                 ' VTable offset = 20
     BYREF ppidl AS DWORD _                             ' __out LPITEMIDLIST *ppidl
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IPersistIDList_INTERFACE_DEFINED__ */

'#endif  // NTDDI_WINXP|| (_WIN32_IE >= _WIN32_IE_IE70)


' ########################################################################################
' IEnumIDList interface
' IID = 000214F2-0000-0000-C000-000000000046
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IEnumIDList_INTERFACE_DEFINED)
   %IEnumIDList_INTERFACE_DEFINED = 1

$IID_IEnumIDList = GUID$("{000214F2-0000-0000-C000-000000000046}")

INTERFACE IEnumIDList $IID_IEnumIDList

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Next ( _                                      ' VTable offset = 12
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   , BYREF rgelt AS DWORD _                             ' __out LPITEMIDLIST *rgelt
   , BYREF pceltFetched AS DWORD _                      ' __out ULONG *pceltFetched
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Skip ( _                                      ' VTable offset = 16
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reset ( _                                     ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 24
     BYREF ppenum AS IEnumIDList _                      ' __out IEnumIDList **ppenum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEnumIDList_INTERFACE_DEFINED__ */


' ########################################################################################
' IEnumFullIDList interface
' IID = D0191542-7954-4908-BC06-B2360BBE45BA
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IEnumFullIDList_INTERFACE_DEFINED)
   %IEnumFullIDList_INTERFACE_DEFINED = 1

$IID_IEnumFullIDList = GUID$("{D0191542-7954-4908-BC06-B2360BBE45BA}")

INTERFACE IEnumFullIDList $IID_IEnumFullIDList

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Next ( _                                      ' VTable offset = 12
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   , BYREF rgelt AS DWORD _                             ' __out PIDLIST_ABSOLUTE *rgelt
   , BYREF pceltFetched AS DWORD _                      ' __out ULONG *pceltFetched
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Skip ( _                                      ' VTable offset = 16
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reset ( _                                     ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 24
     BYREF ppenum AS IEnumFullIDList _                  ' __out IEnumFullIDList **ppenum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEnumFullIDList_INTERFACE_DEFINED__ */


' SHGNO enum
%SHGDN_NORMAL        = 0???        ' // default (display purpose)
%SHGDN_INFOLDER      = 1???        ' // displayed under a folder (relative)
%SHGDN_FOREDITING    = &H1000???   ' // for in-place editing
%SHGDN_FORADDRESSBAR = &H4000???   ' // UI friendly parsing name (remove ugly stuff)
%SHGDN_FORPARSING    = &H8000???   ' // parsing name for ParseDisplayName()
'typedef DWORD SHGDNF;

' SHCONTF enum
%SHCONTF_CHECKING_FOR_CHILDREN = &H10???
%SHCONTF_FOLDERS               = &H20???   ' // only want folders enumerated (SFGAO_FOLDER)
%SHCONTF_NONFOLDERS            = &H40???   ' // include non folders
%SHCONTF_INCLUDEHIDDEN         = &H80???   ' // show items normally hidden
%SHCONTF_INIT_ON_FIRST_NEXT    = &H100???   ' // allow EnumObject() to return before validating enum
%SHCONTF_NETPRINTERSRCH        = &H200???   ' // hint that client is looking for printers
%SHCONTF_SHAREABLE             = &H400???   ' // hint that client is looking sharable resources (remote shares)
%SHCONTF_STORAGE               = &H800???   ' // include all items with accessible storage and their ancestors
%SHCONTF_NAVIGATION_ENUM       = &H1000???
%SHCONTF_FASTITEMS             = &H2000???
%SHCONTF_FLATLIST              = &H4000???
%SHCONTF_ENABLE_ASYNC          = &H8000???
%SHCONTF_INCLUDESUPERHIDDEN    = &H10000???
'typedef DWORD SHCONTF;

%SHCIDS_ALLFIELDS        = &H80000000???
%SHCIDS_CANONICALONLY    = &H10000000???
%SHCIDS_BITMASK          = &HFFFF0000???
%SHCIDS_COLUMNMASK       = &H0000FFFF???
%SFGAO_CANCOPY           = %DROPEFFECT_COPY   ' // Objects can be copied    (= &H1)
%SFGAO_CANMOVE           = %DROPEFFECT_MOVE   ' // Objects can be moved     (= &H2)
%SFGAO_CANLINK           = %DROPEFFECT_LINK   ' // Objects can be linked    (= &H4)
%SFGAO_STORAGE           = &H00000008???      ' // supports BindToObject(IID_IStorage)
%SFGAO_CANRENAME         = &H00000010???      ' // Objects can be renamed
%SFGAO_CANDELETE         = &H00000020???      ' // Objects can be deleted
%SFGAO_HASPROPSHEET      = &H00000040???      ' // Objects have property sheets
%SFGAO_DROPTARGET        = &H00000100???      ' // Objects are drop target
%SFGAO_CAPABILITYMASK    = &H00000177???
%SFGAO_ENCRYPTED         = &H00002000???      ' // object is encrypted (use alt color)
%SFGAO_ISSLOW            = &H00004000???      ' // 'slow' object
%SFGAO_GHOSTED           = &H00008000???      ' // ghosted icon
%SFGAO_LINK              = &H00010000???      ' // Shortcut (link)
%SFGAO_SHARE             = &H00020000???      ' // shared
%SFGAO_READONLY          = &H00040000???      ' // read-only
%SFGAO_HIDDEN            = &H00080000???      ' // hidden object
%SFGAO_DISPLAYATTRMASK   = &H000FC000???
%SFGAO_FILESYSANCESTOR   = &H10000000???      ' // may contain children with SFGAO_FILESYSTEM
%SFGAO_FOLDER            = &H20000000???      ' // support BindToObject(IID_IShellFolder)
%SFGAO_FILESYSTEM        = &H40000000???      ' // is a win32 file system object (file/folder/root)
%SFGAO_HASSUBFOLDER      = &H80000000???      ' // may contain children with SFGAO_FOLDER
%SFGAO_CONTENTSMASK      = &H80000000???
%SFGAO_VALIDATE          = &H01000000???      ' // invalidate cached information
%SFGAO_REMOVABLE         = &H02000000???      ' // is this removeable media?
%SFGAO_COMPRESSED        = &H04000000???      ' // Object is compressed (use alt color)
%SFGAO_BROWSABLE         = &H08000000???      ' // supports IShellFolder, but only implements CreateViewObject() (non-folder view)
%SFGAO_NONENUMERATED     = &H00100000???      ' // is a non-enumerated object
%SFGAO_NEWCONTENT        = &H00200000???      ' // should show bold in explorer tree
%SFGAO_CANMONIKER        = &H00400000???      ' // defunct
%SFGAO_HASSTORAGE        = &H00400000???      ' // defunct
%SFGAO_STREAM            = &H00400000???      ' // supports BindToObject(IID_IStream)
%SFGAO_STORAGEANCESTOR   = &H00800000???      ' // may contain children with SFGAO_STORAGE or SFGAO_STREAM
%SFGAO_STORAGECAPMASK    = &H70C50008???      ' // for determining storage capabilities, ie for open/save semantics
%SFGAO_PKEYSFGAOMASK     = &H81044000???      ' // Attributes that are masked out for PKEY_SFGAOFlags because they are considered to cause slow calculations or lack context (SFGAO_VALIDATE | SFGAO_ISSLOW | SFGAO_HASSUBFOLDER and others)

'typedef ULONG SFGAOF;

' Must be Unicode
$STR_BIND_FORCE_FOLDER_SHORTCUT_RESOLVE   = "Force Folder Shortcut Resolve"
$STR_AVOID_DRIVE_RESTRICTION_POLICY       = "Avoid Drive Restriction Policy"
$STR_AVOID_DRIVE_RESTRICTION_POLICY       = "Avoid Drive Restriction Policy"
$STR_SKIP_BINDING_CLSID                   = "Skip Binding CLSID"
$STR_PARSE_PREFER_FOLDER_BROWSING         = "Parse Prefer Folder Browsing"
$STR_DONT_PARSE_RELATIVE                  = "Don't Parse Relative"
$STR_PARSE_TRANSLATE_ALIASES              = "Parse Translate Aliases"
$STR_PARSE_SKIP_NET_CACHE                 = "Skip Net Resource Cache"
$STR_PARSE_SHELL_PROTOCOL_TO_FILE_OBJECTS = "Parse Shell Protocol To File Objects"
'#if (_WIN32_IE >= 0x0700)
$STR_TRACK_CLSID                          = "Track the CLSID"
$STR_INTERNAL_NAVIGATE                    = "Internal Navigation"
$STR_PARSE_PROPERTYSTORE                  = "DelegateNamedProperties"
$STR_NO_VALIDATE_FILENAME_CHARS           = "NoValidateFilenameChars"
'$STR_IFILTER_LOAD_DEFINED_FILTER          = "Only bind registered persistent handlers"   ' // Removed in Windows 7 SDK
'$STR_IFILTER_FORCE_TEXT_FILTER_FALLBACK   = "Always bind persistent handlers"   ' // Removed in Windows 7 SDK
$STR_BIND_DELEGATE_CREATE_OBJECT          = "Delegate Object Creation"
$STR_PARSE_ALLOW_INTERNET_SHELL_FOLDERS   = "Allow binding to Internet shell folder handlers and negate STR_PARSE_PREFER_WEB_BROWSING"
$STR_PARSE_PREFER_WEB_BROWSING            = "Do not bind to Internet shell folder handlers"
$STR_PARSE_SHOW_NET_DIAGNOSTICS_UI        = "Show network diagnostics UI"
$STR_PARSE_DONT_REQUIRE_VALIDATED_URLS    = "Do not require validated URLs"
'#endif // _WIN32_IE >= 0x0700
'#if (NTDDI_VERSION >= NTDDI_WIN7)
$STR_BIND_FOLDERS_READ_ONLY               = "Folders As Read Only"
$STR_BIND_FOLDER_ENUM_MODE                = "Folder Enum Mode"

' enum FOLDER_ENUM_MODE
%FEM_VIEWRESULT = 0
%FEM_NAVIGATION = 1


' ########################################################################################
' IObjectWithFolderEnumMode interface
' IID = 6A9D9026-0E6E-464C-B000-42ECC07DE673
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IObjectWithFolderEnumMode_INTERFACE_DEFINED)
    %IObjectWithFolderEnumMode_INTERFACE_DEFINED = 1

$IID_IObjectWithFolderEnumMode = GUID$("{6A9D9026-0E6E-464C-B000-42ECC07DE673}")

INTERFACE IObjectWithFolderEnumMode $IID_IObjectWithFolderEnumMode

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetMode ( _                                   ' VTable offset = 12
     BYVAL feMode AS LONG _                             ' __in FOLDER_ENUM_MODE feMode
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMode ( _                                   ' VTable offset = 16
     BYREF pfeMode AS LONG _                            ' __out FOLDER_ENUM_MODE *pfeMode
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IObjectWithFolderEnumMode_INTERFACE_DEFINED__ */


' Must be in unicode
$STR_PARSE_WITH_EXPLICIT_PROGID = "ExplicitProgid"
$STR_PARSE_WITH_EXPLICIT_ASSOCAPP = "ExplicitAssociationApp"
$STR_PARSE_EXPLICIT_ASSOCIATION_SUCCESSFUL = "ExplicitAssociationSuccessful"
$STR_PARSE_AND_CREATE_ITEM = "ParseAndCreateItem"

' ########################################################################################
' IParseAndCreateItem interface
' IID = 67EFED0E-E827-4408-B493-78F3982B685C
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IParseAndCreateItem_INTERFACE_DEFINED)
    %IParseAndCreateItem_INTERFACE_DEFINED = 1

$IID_IParseAndCreateItem = GUID$("{67EFED0E-E827-4408-B493-78F3982B685C}")

INTERFACE IParseAndCreateItem $IID_IParseAndCreateItem

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetItem ( _                                   ' VTable offset = 12
     BYVAL psi AS IShellItem _                          ' __in IShellItem *psi
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetItem ( _                                   ' VTable offset = 16
     BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppv AS IUnknown _                            ' __out void **ppv
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IParseAndCreateItem_INTERFACE_DEFINED__ */

$$STR_ITEM_CACHE_CONTEXT = "ItemCacheContext"$$

'#endif // NTDDI_VERSION >= NTDDI_WIN7

' ########################################################################################
' IShellFolder interface
' IID = 000214E6-0000-0000-C000-000000000046
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IShellFolder_INTERFACE_DEFINED)
    %IShellFolder_INTERFACE_DEFINED = 1

$IID_IShellFolder = GUID$("{000214E6-0000-0000-C000-000000000046}")

INTERFACE IShellFolder $IID_IShellFolder

   INHERIT IUnknown

   ' =====================================================================================
   METHOD ParseDisplayName ( _                          ' VTable offset = 12
     BYVAL hwnd AS DWORD _                              ' __in HWND hwnd
   , BYVAL pbc AS IBindCtx _                            ' __in LPBC pbc
   , BYREF pszDisplayName AS WSTRINGZ _                 ' __in LPOLESTR pszDisplayName
   , BYREF pchEaten AS DWORD _                          ' __out ULONG *pchEaten
   , BYREF ppidl AS DWORD _                             ' __out LPITEMIDLIST *ppidl
   , BYREF pdwAttributes AS DWORD _                     ' __inout ULONG *pdwAttributes
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumObjects ( _                               ' VTable offset = 16
     BYVAL hwnd AS DWORD _                              ' __in HWND hwnd
   , BYVAL grfFlags AS DWORD _                          ' __in SHCONTF grfFlags
   , BYREF ppenumIDList AS IEnumIDList _                ' __out IEnumIDList **ppenumIDList
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD BindToObject ( _                              ' VTable offset = 20
     BYVAL pidl AS DWORD _                              ' __in LPCITEMIDLIST pidl
   , BYVAL pbc AS IBindCtx _                            ' __in LPBC pbc
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppv AS IUnknown _                            ' __out void **ppv
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD BindToStorage ( _                             ' VTable offset = 24
     BYVAL pidl AS DWORD _                              ' __in LPCITEMIDLIST pidl
   , BYVAL pbc AS IBindCtx _                            ' __in LPBC pbc
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppv AS IUnknown _                            ' __out void **ppv
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CompareIDs ( _                                ' VTable offset = 28
     BYVAL lParam AS LONG _                             ' __in LPARAM lParam
   , BYVAL pidl1 AS DWORD _                             ' __in LPCITEMIDLIST pidl1
   , BYVAL pidl2 AS DWORD _                             ' __in LPCITEMIDLIST pidl2
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateViewObject ( _                          ' VTable offset = 32
     BYVAL hwndOwner AS  DWORD _                        ' __in HWND hwndOwner
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppv AS IUnknown _                            ' __out void **ppv
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAttributesOf ( _                           ' VTable offset = 36
     BYVAL cidl AS DWORD _                              ' __in UINT cidl
   , BYVAL apidl AS DWORD _                             ' __in LPCITEMIDLIST *apidl
   , BYREF rgfInOut AS DWORD _                          ' __inout SFGAOF *rgfInOut
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetUIObjectOf ( _                             ' VTable offset = 40
     BYVAL hwndOwner AS DWORD _                         ' __in HWND hwndOwner
   , BYVAL cidl AS DWORD _                              ' __in UINT cidl
   , BYVAL apidl AS DWORD _                             ' __in LPCITEMIDLIST *apidl
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF rgfReserved AS DWORD _                       ' __inout UINT *rgfReserved
   , BYREF ppv AS DWORD _                               ' __out void **ppv
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDisplayNameOf ( _                          ' VTable offset = 44
     BYVAL pidl AS DWORD _                              ' __in LPCITEMIDLIST pidl
   , BYVAL uFlags AS DWORD _                            ' __in SHGDNF uFlags
   , BYREF pName AS STRRET _                            ' __out STRRET *pName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetNameOf ( _                                 ' VTable offset = 48
     BYVAL hwnd AS DWORD _                              ' __in HWND hwnd
   , BYVAL pidl AS DWORD _                              ' __in LPCITEMIDLIST pidl
   , BYREF pszName AS WSTRINGZ _                        ' __in LPCOLESTR pszName
   , BYVAL uFlags AS DWORD _                            ' __in SHGDNF uFlags
   , BYREF ppidlOut AS DWORD _                          ' __out LPITEMIDLIST *ppidlOut
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IShellFolder_INTERFACE_DEFINED__ */


'#if (_WIN32_IE >= 0x0500)

' // Size = 4344 bytes
TYPE EXTRASEARCH DWORD FILL
   guidSearch      AS GUID              ' GUID guidSearch
   wszFriendlyName AS WSTRINGZ * 80     ' WCHAR wszFriendlyName[ 80 ]
   wszUrl          AS WSTRINGZ * 2084   ' WCHAR wszUrl[ 2084 ]
END TYPE

' ########################################################################################
' IEnumExtraSearch interface
' IID = 0E700BE1-9DB6-11D1-A1CE-00C04FD75D13
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IEnumExtraSearch_INTERFACE_DEFINED)
    %IEnumExtraSearch_INTERFACE_DEFINED = 1

$IID_IEnumExtraSearch = GUID$("{0E700BE1-9DB6-11D1-A1CE-00C04FD75D13}")

INTERFACE IEnumExtraSearch $IID_IEnumExtraSearch

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Next ( _                                      ' VTable offset = 12
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   , BYREF rgelt AS EXTRASEARCH _                       ' __out EXTRASEARCH *rgelt
   , BYREF pceltFetched AS DWORD _                      ' __out ULONG *pceltFetched
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Skip ( _                                      ' VTable offset = 16
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reset ( _                                     ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 24
     BYREF ppenum AS IEnumExtraSearch _                 ' __out IEnumExtraSearch **ppenum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEnumExtraSearch_INTERFACE_DEFINED__ */


' ########################################################################################
' IShellFolder2 interface
' IID = 93F2F68C-1D1B-11D3-A30E-00C04F79ABD1
' Inherited interface = IShellFolder
' ########################################################################################

#IF NOT %DEF(%IShellFolder2_INTERFACE_DEFINED)
    %IShellFolder2_INTERFACE_DEFINED = 1

$IID_IShellFolder2 = GUID$("{93F2F68C-1D1B-11d3-A30E-00C04F79ABD1}")

INTERFACE IShellFolder2 $IID_IShellFolder2

   INHERIT IUnknown

   ' =====================================================================================
   ' IShellFolder Methods
   ' =====================================================================================
   METHOD ParseDisplayName ( _                          ' VTable offset = 12
     BYVAL hwnd AS DWORD _                              ' __in HWND hwnd
   , BYVAL pbc AS IBindCtx _                            ' __in LPBC pbc
   , BYREF pszDisplayName AS WSTRINGZ _                 ' __in LPOLESTR pszDisplayName
   , BYREF pchEaten AS DWORD _                          ' __out ULONG *pchEaten
   , BYREF ppidl AS DWORD _                             ' __out LPITEMIDLIST *ppidl
   , BYREF pdwAttributes AS DWORD _                     ' __inout ULONG *pdwAttributes
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumObjects ( _                               ' VTable offset = 16
     BYVAL hwnd AS DWORD _                              ' __in HWND hwnd
   , BYVAL grfFlags AS DWORD _                          ' __in SHCONTF grfFlags
   , BYREF ppenumIDList AS IEnumIDList _                ' __out IEnumIDList **ppenumIDList
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD BindToObject ( _                              ' VTable offset = 20
     BYVAL pidl AS DWORD _                              ' __in LPCITEMIDLIST pidl
   , BYVAL pbc AS IBindCtx _                            ' __in LPBC pbc
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppv AS IUnknown _                            ' __out void **ppv
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD BindToStorage ( _                             ' VTable offset = 24
     BYVAL pidl AS DWORD _                              ' __in LPCITEMIDLIST pidl
   , BYVAL pbc AS IBindCtx _                            ' __in LPBC pbc
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppv AS IUnknown _                            ' __out void **ppv
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CompareIDs ( _                                ' VTable offset = 28
     BYVAL lParam AS LONG _                             ' __in LPARAM lParam
   , BYVAL pidl1 AS DWORD _                             ' __in LPCITEMIDLIST pidl1
   , BYVAL pidl2 AS DWORD _                             ' __in LPCITEMIDLIST pidl2
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateViewObject ( _                          ' VTable offset = 32
     BYVAL hwndOwner AS  DWORD _                        ' __in HWND hwndOwner
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppv AS IUnknown _                            ' __out void **ppv
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAttributesOf ( _                           ' VTable offset = 36
     BYVAL cidl AS DWORD _                              ' __in UINT cidl
   , BYVAL apidl AS DWORD _                             ' __in LPCITEMIDLIST *apidl
   , BYREF rgfInOut AS DWORD _                          ' __inout SFGAOF *rgfInOut
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetUIObjectOf ( _                             ' VTable offset = 40
     BYVAL hwndOwner AS DWORD _                         ' __in HWND hwndOwner
   , BYVAL cidl AS DWORD _                              ' __in UINT cidl
   , BYVAL apidl AS DWORD _                             ' __in LPCITEMIDLIST *apidl
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF rgfReserved AS DWORD _                       ' __inout UINT *rgfReserved
   , BYREF ppv AS DWORD _                               ' __out void **ppv
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDisplayNameOf ( _                          ' VTable offset = 44
     BYVAL pidl AS DWORD _                              ' __in LPCITEMIDLIST pidl
   , BYVAL uFlags AS DWORD _                            ' __in SHGDNF uFlags
   , BYREF pName AS STRRET _                            ' __out STRRET *pName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetNameOf ( _                                 ' VTable offset = 48
     BYVAL hwnd AS DWORD _                              ' __in HWND hwnd
   , BYVAL pidl AS DWORD _                              ' __in LPCITEMIDLIST pidl
   , BYREF pszName AS WSTRINGZ _                        ' __in LPCOLESTR pszName
   , BYVAL uFlags AS DWORD _                            ' __in SHGDNF uFlags
   , BYREF ppidlOut AS DWORD _                          ' __out LPITEMIDLIST *ppidlOut
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IShellFolder2 Methods
   ' =====================================================================================
   METHOD EnumSearches ( _                              ' VTable offset = 56
     BYREF ppenum AS IEnumExtraSearch _                 ' __out IEnumExtraSearch **ppenum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDefaultColumn ( _                          ' VTable offset = 60
     BYVAL dwRes AS DWORD _                             ' __in DWORD dwRes
   , BYREF pSort AS DWORD _                             ' __out ULONG *pSort
   , BYREF pDisplay AS DWORD _                          ' __out ULONG *pDisplay
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDefaultColumnState ( _                     ' VTable offset = 64
     BYVAL iColumn AS DWORD _                           ' __in UINT iColumn
   , BYREF pcsFlags AS DWORD _                          ' __out SHCOLSTATEF *pcsFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDetailsEx ( _                              ' VTable offset = 68
     BYVAL pidl AS DWORD _                              ' __in LPCITEMIDLIST pidl
   , BYREF pscid AS SHCOLUMNID _                        ' __in const SHCOLUMNID *pscid
   , BYREF pv AS VARIANT _                              ' __out VARIANT *pv
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDetailsOf ( _                              ' VTable offset = 72
     BYVAL pidl AS DWORD _                              ' __in LPCITEMIDLIST pidl
   , BYVAL iColumn AS DWORD _                           ' __in UINT iColumn
   , BYREF psd AS SHELLDETAILS _                        ' __out SHELLDETAILS *psd
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD MapColumnToSCID ( _                           ' VTable offset = 76
     BYVAL iColumn AS DWORD _                           ' __in UINT iColumn
   , BYREF pscid AS SHCOLUMNID _                        ' __in SHCOLUMNID *pscid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IShellFolder2_INTERFACE_DEFINED__ */


'#endif // _WIN32_IE >= 0x0500)

'typedef char *LPVIEWSETTINGS;

' FOLDERFLAGS enum
%FWF_AUTOARRANGE         = &H1???
%FWF_ABBREVIATEDNAMES    = &H2???
%FWF_SNAPTOGRID          = &H4???
%FWF_OWNERDATA           = &H8???
%FWF_BESTFITWINDOW       = &H10???
%FWF_DESKTOP             = &H20???
%FWF_SINGLESEL           = &H40???
%FWF_NOSUBFOLDERS        = &H80???
%FWF_TRANSPARENT         = &H100???
%FWF_NOCLIENTEDGE        = &H200???
%FWF_NOSCROLL            = &H400???
%FWF_ALIGNLEFT           = &H800???
%FWF_NOICONS             = &H1000???
%FWF_SHOWSELALWAYS       = &H2000???
%FWF_NOVISIBLE           = &H4000???
%FWF_SINGLECLICKACTIVATE = &H8000???
%FWF_NOWEBVIEW           = &H10000???
%FWF_HIDEFILENAMES       = &H20000???
%FWF_CHECKSELECT         = &H40000???
%FWF_NOENUMREFRESH       = &H80000???
%FWF_NOGROUPING          = &H100000???
%FWF_FULLROWSELECT       = &H200000???
%FWF_NOFILTERS           = &H400000???
%FWF_NOCOLUMNHEADER      = &H800000???
%FWF_NOHEADERINALLVIEWS  = &H1000000???
%FWF_EXTENDEDTILES       = &H2000000???
%FWF_TRICHECKSELECT      = &H4000000???
%FWF_AUTOCHECKSELECT     = &H8000000???
%FWF_NOBROWSERVIEWSTATE  = &H10000000???
%FWF_SUBSETGROUPS        = &H20000000???
%FWF_USESEARCHFOLDER     = &H40000000???
%FWF_ALLOWRTLREADING     = &H80000000&   ' ( int  )0x80000000

' FOLDERVIEWMODE enum
%FVM_FIRST      = 1
%FVM_ICON       = 1
%FVM_SMALLICON  = 2
%FVM_LIST       = 3
%FVM_DETAILS    = 4
%FVM_THUMBNAIL  = 5
%FVM_TILE       = 6
%FVM_THUMBSTRIP = 7
%FVM_CONTENT    = 8
%FVM_LAST       = 8

'#if (NTDDI_VERSION >= NTDDI_VISTA)
' enum FOLDERLOGICALVIEWMODE
%FLVM_UNSPECIFIED = -1
%FLVM_FIRST       = 1
%FLVM_DETAILS     = 1
%FLVM_TILES       = 2
%FLVM_ICONS       = 3
%FLVM_LIST        = 4
%FLVM_CONTENT     = 5
%FLVM_LAST        = 5
'#endif  // NTDDI_VISTA

' // Size = 8 bytes
TYPE FOLDERSETTINGS DWORD
   ViewMode AS DWORD   ' UINT ViewMode
   fFlags   AS DWORD   ' UINT fFlags
END TYPE


' ########################################################################################
' IFolderViewOptions interface
' IID = 3CC974D2-B302-4D36-AD3E-06D93F695D3F
' Inherited interface = IOleWindow
' ########################################################################################

#IF NOT %DEF(%IFolderViewOptions_INTERFACE_DEFINED)
    %IFolderViewOptions_INTERFACE_DEFINED = 1

' enum FOLDERVIEWOPTIONS
%FVO_DEFAULT           = 0???
%FVO_VISTALAYOUT       = &H1???
%FVO_CUSTOMPOSITION    = &H2???
%FVO_CUSTOMORDERING    = &H4???
%FVO_SUPPORTHYPERLINKS = &H8???
%FVO_NOANIMATIONS      = &H10???
%FVO_NOSCROLLTIPS      = &H20???

$IID_IFolderViewOptions = GUID$("{3CC974D2-B302-4D36-AD3E-06D93F695D3F}")

INTERFACE IFolderViewOptions $IID_IFolderViewOptions

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetFolderViewOptions ( _                      ' VTable offset = 12
     BYVAL fvoMask AS DWORD _                           ' __in FOLDERVIEWOPTIONS fvoMask
   , BYVAL fvoFlags AS DWORD _                          ' __in FOLDERVIEWOPTIONS fvoFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFolderViewOptions ( _                      ' VTable offset = 16
     BYREF pfvoFlags AS DWORD _                         ' __out FOLDERVIEWOPTIONS *pfvoFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IFolderViewOptions_INTERFACE_DEFINED__ */

' enum SVSIF
%SVSI_DESELECT       = 0???
%SVSI_SELECT         = &H1???
%SVSI_EDIT           = &H3???
%SVSI_DESELECTOTHERS = &H4???
%SVSI_ENSUREVISIBLE  = &H8???
%SVSI_FOCUSED        = &H10???
%SVSI_TRANSLATEPT    = &H20???
%SVSI_SELECTIONMARK  = &H40???
%SVSI_POSITIONITEM   = &H80???
%SVSI_CHECK          = &H100???
%SVSI_CHECK2         = &H200???
%SVSI_KEYBOARDSELECT = &H401???
%SVSI_NOTAKEFOCUS    = &H40000000???
%SVSI_NOSTATECHANGE  = &H80000000???  ' // work around the use of the high bit that results in 4245: signed/unsigned mismatch

'typedef UINT SVSIF;

' SVGIO enum
%SVGIO_BACKGROUND     = 0???
%SVGIO_SELECTION      = &H1???
%SVGIO_ALLVIEW        = &H2???
%SVGIO_CHECKED        = &H3???
%SVGIO_TYPE_MASK      = &HF???
%SVGIO_FLAG_VIEWORDER = &H80000000???

' SVUIA_STATUS enum
%SVUIA_DEACTIVATE       = 0
%SVUIA_ACTIVATE_NOFOCUS = 1
%SVUIA_ACTIVATE_FOCUS   = 2
%SVUIA_INPLACEACTIVATE  = 3


' ########################################################################################
' IShellView interface
' IID = 000214E3-0000-0000-C000-000000000046
' Inherited interface = IOleWindow
' ########################################################################################

#IF NOT %DEF(%IShellView_INTERFACE_DEFINED)
    %IShellView_INTERFACE_DEFINED = 1

$IID_IShellView = GUID$("{000214E3-0000-0000-C000-000000000046}")

INTERFACE IShellView $IID_IShellView

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
   ' IShellView methods
   ' =====================================================================================
   METHOD TranslateAccelerator ( _                      ' VTable offset = 20
     BYREF pmsg AS tagMSG _                             ' __in MSG *pmsg
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnableModeless ( _                            ' VTable offset = 24
     BYVAL fEnable AS LONG _                            ' __in BOOL fEnable
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UIActivate ( _                                ' VTable offset = 28
     BYVAL uState AS DWORD _                            ' __in UINT uState
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Refresh ( _                                   ' VTable offset = 32
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateViewWindow ( _                          ' VTable offset = 36
     BYVAL psvPrevious AS IShellView _                  ' __in IShellView *psvPrevious
   , BYREF pfs AS FOLDERSETTINGS _                      ' __in LPCFOLDERSETTINGS pfs
   , BYVAL psb AS IShellBrowser _                       ' __in IShellBrowser *psb
   , BYREF prcView AS RECT _                            ' __out RECT *prcView
   , BYREF phWnd AS DWORD _                             ' __out HWND *phWnd
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DestroyViewWindow ( _                         ' VTable offset = 40
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCurrentInfo ( _                            ' VTable offset = 44
     BYREF pfs AS FOLDERSETTINGS _                      ' __out LPFOLDERSETTINGS pfs
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddPropertySheetPages ( _                     ' VTable offset = 48
     BYVAL dwReserved AS DWORD _                        ' __in DWORD dwReserved
   , BYVAL pfn AS DWORD _                               ' __in LPFNSVADDPROPSHEETPAGE pfn
   , BYVAL lparam AS LONG _                             ' __in LPARAM lparam
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SaveViewState ( _                             ' VTable offset = 52
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SelectItem ( _                                ' VTable offset = 56
     BYVAL pidlItem AS DWORD _                          ' __in LPCITEMIDLIST pidlItem
   , BYVAL uFlags AS DWORD _                            ' __in SVSIF uFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetItemObject ( _                             ' VTable offset = 60
     BYVAL uItem AS DWORD _                             ' __in UINT uItem
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppv AS IUnknown _                            ' __out void **ppv
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IShellView_INTERFACE_DEFINED__ */


' ########################################################################################
' IShellView2 interface
' IID = 88E39E80-3578-11CF-AE69-08002B2E1262
' Inherited interface = IShellView
' ########################################################################################

#IF NOT %DEF(%IShellView2_INTERFACE_DEFINED)
    %IShellView2_INTERFACE_DEFINED = 1

'typedef GUID SHELLVIEWID;

%SV2GV_CURRENTVIEW = &HFFFFFFFF???   ' ((UINT)-1)
%SV2GV_DEFAULTVIEW = &HFFFFFFFE???   ' ((UINT)-2)

'#include <pshpack8.h>
' // Size = 28 bytes
TYPE SV2CVW2_PARAMS DWORD
   cbsize   AS DWORD                ' DWORD cbSize
   psvPrev  AS DWORD                ' IShellView *psvPrev
   pfs      AS FOLDERSETTINGS PTR   ' LPCFOLDERSETTINGS pfs
   psbOwner AS DWORD                ' IShellBrowser *psbOwner
   prcView  AS RECT PTR             ' RECT *prcView
   pvid     AS DWORD                ' const SHELLVIEWID *pvid
   hwndView AS DWORD                ' HWND hwndView
END TYPE
'#include <poppack.h>

$IID_IShellView2 = GUID$("{88E39E80-3578-11CF-AE69-08002B2E1262}")

INTERFACE IShellView2 $IID_IShellView2

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
   ' IShellView methods
   ' =====================================================================================
   METHOD TranslateAccelerator ( _                      ' VTable offset = 20
     BYREF pmsg AS tagMSG _                             ' __in MSG *pmsg
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnableModeless ( _                            ' VTable offset = 24
     BYVAL fEnable AS LONG _                            ' __in BOOL fEnable
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UIActivate ( _                                ' VTable offset = 28
     BYVAL uState AS DWORD _                            ' __in UINT uState
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Refresh ( _                                   ' VTable offset = 32
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateViewWindow ( _                          ' VTable offset = 36
     BYVAL psvPrevious AS IShellView _                  ' __in IShellView *psvPrevious
   , BYREF pfs AS FOLDERSETTINGS _                      ' __in LPCFOLDERSETTINGS pfs
   , BYVAL psb AS IShellBrowser _                       ' __in IShellBrowser *psb
   , BYREF prcView AS RECT _                            ' __out RECT *prcView
   , BYREF phWnd AS DWORD _                             ' __out HWND *phWnd
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DestroyViewWindow ( _                         ' VTable offset = 40
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCurrentInfo ( _                            ' VTable offset = 44
     BYREF pfs AS FOLDERSETTINGS _                      ' __out LPFOLDERSETTINGS pfs
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddPropertySheetPages ( _                     ' VTable offset = 48
     BYVAL dwReserved AS DWORD _                        ' __in DWORD dwReserved
   , BYVAL pfn AS DWORD _                               ' __in LPFNSVADDPROPSHEETPAGE pfn
   , BYVAL lparam AS LONG _                             ' __in LPARAM lparam
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SaveViewState ( _                             ' VTable offset = 52
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SelectItem ( _                                ' VTable offset = 56
     BYVAL pidlItem AS DWORD _                          ' __in LPCITEMIDLIST pidlItem
   , BYVAL uFlags AS DWORD _                            ' __in SVSIF uFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetItemObject ( _                             ' VTable offset = 60
     BYVAL uItem AS DWORD _                             ' __in UINT uItem
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppv AS IUnknown _                            ' __out void **ppv
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IShellView2 methods
   ' =====================================================================================
   METHOD GetView ( _                                   ' VTable offset = 64
     BYREF pvid AS GUID _                               ' __inout SHELLVIEWID *pvid
   , BYVAL uView AS DWORD _                             ' __in ULONG uView
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateViewWindow2 ( _                         ' VTable offset = 68
     BYREF lpParams AS SV2CVW2_PARAMS _                 ' __in LPSV2CVW2_PARAMS lpParams
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD HandleRename ( _                              ' VTable offset = 72
     BYVAL pidlNew AS DWORD _                           ' __in LPCITEMIDLIST pidlNew
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SelectAndPositionItem ( _                     ' VTable offset = 76
     BYVAL pidlItem AS DWORD _                          ' __in LPCITEMIDLIST pidlItem
   , BYVAL uFlags AS DWORD _                            ' __in UINT uFlags
   , BYREF ppt AS POINT _                               ' __in POINT *ppt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IShellView2_INTERFACE_DEFINED__ */


'#if (NTDDI_VERSION >= NTDDI_VISTA)

' ########################################################################################
' IShellView3 interface
' IID = EC39FA88-F8AF-41C5-8421-38BED28F4673
' Inherited interface = IShellView2
' ########################################################################################

#IF NOT %DEF(%IShellView3_INTERFACE_DEFINED)
    %IShellView3_INTERFACE_DEFINED = 1

$IID_IShellView3 = GUID$("{EC39FA88-F8AF-41C5-8421-38BED28F4673}")

' enum SV3CVW3
%SV3CVW3_DEFAULT          = 0???
%SV3CVW3_NONINTERACTIVE   = &H1???
%SV3CVW3_FORCEVIEWMODE    = &H2???
%SV3CVW3_FORCEFOLDERFLAGS = &H4???
'typedef DWORD SV3CVW3_FLAGS;

INTERFACE IShellView3 $IID_IShellView3

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
   ' IShellView methods
   ' =====================================================================================
   METHOD TranslateAccelerator ( _                      ' VTable offset = 20
     BYREF pmsg AS tagMSG _                             ' __in MSG *pmsg
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnableModeless ( _                            ' VTable offset = 24
     BYVAL fEnable AS LONG _                            ' __in BOOL fEnable
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UIActivate ( _                                ' VTable offset = 28
     BYVAL uState AS DWORD _                            ' __in UINT uState
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Refresh ( _                                   ' VTable offset = 32
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateViewWindow ( _                          ' VTable offset = 36
     BYVAL psvPrevious AS IShellView _                  ' __in IShellView *psvPrevious
   , BYREF pfs AS FOLDERSETTINGS _                      ' __in LPCFOLDERSETTINGS pfs
   , BYVAL psb AS IShellBrowser _                       ' __in IShellBrowser *psb
   , BYREF prcView AS RECT _                            ' __out RECT *prcView
   , BYREF phWnd AS DWORD _                             ' __out HWND *phWnd
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DestroyViewWindow ( _                         ' VTable offset = 40
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCurrentInfo ( _                            ' VTable offset = 44
     BYREF pfs AS FOLDERSETTINGS _                      ' __out LPFOLDERSETTINGS pfs
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddPropertySheetPages ( _                     ' VTable offset = 48
     BYVAL dwReserved AS DWORD _                        ' __in DWORD dwReserved
   , BYVAL pfn AS DWORD _                               ' __in LPFNSVADDPROPSHEETPAGE pfn
   , BYVAL lparam AS LONG _                             ' __in LPARAM lparam
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SaveViewState ( _                             ' VTable offset = 52
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SelectItem ( _                                ' VTable offset = 56
     BYVAL pidlItem AS DWORD _                          ' __in LPCITEMIDLIST pidlItem
   , BYVAL uFlags AS DWORD _                            ' __in SVSIF uFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetItemObject ( _                             ' VTable offset = 60
     BYVAL uItem AS DWORD _                             ' __in UINT uItem
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppv AS IUnknown _                            ' __out void **ppv
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IShellView2 methods
   ' =====================================================================================
   METHOD GetView ( _                                   ' VTable offset = 64
     BYREF pvid AS GUID _                               ' __inout SHELLVIEWID *pvid
   , BYVAL uView AS DWORD _                             ' __in ULONG uView
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateViewWindow2 ( _                         ' VTable offset = 68
     BYREF lpParams AS SV2CVW2_PARAMS _                 ' __in LPSV2CVW2_PARAMS lpParams
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD HandleRename ( _                              ' VTable offset = 72
     BYVAL pidlNew AS DWORD _                           ' __in LPCITEMIDLIST pidlNew
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SelectAndPositionItem ( _                     ' VTable offset = 76
     BYVAL pidlItem AS DWORD _                          ' __in LPCITEMIDLIST pidlItem
   , BYVAL uFlags AS DWORD _                            ' __in UINT uFlags
   , BYREF ppt AS POINT _                               ' __in POINT *ppt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IShellView3 Method
   ' =====================================================================================
   METHOD CreateViewWindow3 ( _                         ' VTable offset = 80
     BYVAL psbOwner AS IShellBrowser _                  ' __in IShellBrowser *psbOwner
   , BYVAL psvPrev AS IShellView _                      ' __in IShellView *psvPrev
   , BYVAL dwViewFlags AS DWORD _                       ' __in SV3CVW3_FLAGS dwViewFlags
   , BYVAL dwMask AS DWORD _                            ' __in FOLDERFLAGS dwMask
   , BYVAL dwFlags AS DWORD _                           ' __in FOLDERFLAGS dwFlags
   , BYVAL fvMode AS LONG _                             ' __in FOLDERVIEWMODE fvMode
   , BYREF pvid AS GUID _                               ' __in const SHELLVIEWID *pvid
   , BYREF prcView AS RECT _                            ' __in const RECT *prcView
   , BYREF phwndView AS DWORD _                         ' __out HWND *phwndView
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IShellView3_INTERFACE_DEFINED__ */

'#endif  // NTDDI_VISTA


' ########################################################################################
' IFolderView interface
' IID = CDE725B0-CCC9-4519-917E-325D72FAB4CE
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IFolderView_INTERFACE_DEFINED)
    %IFolderView_INTERFACE_DEFINED = 1

$IID_IFolderView = GUID$("{CDE725B0-CCC9-4519-917E-325D72FAB4CE}")
$SID_SFolderView = $IID_IFolderView    ' // folder view, usually IFolderView

INTERFACE IFolderView $IID_IFolderView

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetCurrentViewMode ( _                        ' VTable offset = 12
     BYREF pViewMode AS DWORD _                         ' __inout UINT *pViewMode
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetCurrentViewMode ( _                        ' VTable offset = 16
     BYVAL ViewMode AS DWORD _                          ' __in UINT ViewMode
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFolder ( _                                 ' VTable offset = 20
     BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppv AS IUnknown _                            ' __out void **ppv
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Item ( _                                      ' VTable offset = 24
     BYVAL iItemIndex AS LONG _                         ' __in int iItemIndex
   , BYREF ppidl AS DWORD _                             ' __out LPITEMIDLIST *ppidl
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ItemCount ( _                                 ' VTable offset = 28
     BYVAL uFlags AS DWORD _                            ' __in UINT uFlags
   , BYREF pcItems AS LONG _                            ' __out int *pcItems
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Items ( _                                     ' VTable offset = 32
     BYVAL uFlags AS DWORD _                            ' __in UINT uFlags
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppv AS IUnknown _                            ' __out void **ppv
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSelectionMarkedItem ( _                    ' VTable offset = 36
     BYREF piItem AS LONG _                             ' __out int *piItem
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFocusedItem ( _                            ' VTable offset = 40
     BYREF piItem AS LONG _                             ' __out int *piItem
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetItemPosition ( _                           ' VTable offset = 44
     BYVAL pidl AS DWORD _                              ' __in LPCITEMIDLIST pidl
   , BYREF ppt AS POINT _                               ' __out POINT *ppt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSpacing ( _                                ' VTable offset = 48
     BYREF ppt AS POINT _                               ' __inout POINT *ppt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDefaultSpacing ( _                         ' VTable offset = 52
     BYREF ppt AS POINT _                               ' __out POINT *ppt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAutoArrange ( _                            ' VTable offset = 56
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SelectItem ( _                                ' VTable offset = 60
     BYVAL iItem AS LONG _                              ' __in int iItem
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SelectAndPositionItems ( _                    ' VTable offset = 64
     BYVAL cidl AS DWORD _                              ' __in UINT cidl
   , BYVAL apidl AS DWORD _                             ' __in LPCITEMIDLIST *apidl
   , BYREF apt AS POINT _                               ' __in POINT *apt
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IFolderView_INTERFACE_DEFINED__ */

'#if (NTDDI_VERSION >= NTDDI_WIN7)

' ########################################################################################
' ISearchBoxInfo interface
' IID = 6AF6E03F-D664-4EF4-9626-F7E0ED36755E
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ISearchBoxInfo_INTERFACE_DEFINED)
    %ISearchBoxInfo_INTERFACE_DEFINED = 1

$IID_ISearchBoxInfo = GUID$("{6AF6E03F-D664-4EF4-9626-F7E0ED36755E}")

INTERFACE ISearchBoxInfo $IID_ISearchBoxInfo

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetCondition ( _                              ' VTable offset = 12
     BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppv AS IUnknown _                            ' __out_opt void **ppv
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetText ( _                                   ' VTable offset = 16
     BYREF ppsz AS DWORD _                              ' __out_opt LPWSTR *ppsz
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISearchBoxInfo_INTERFACE_DEFINED__ */

'#endif // (NTDDI_VERSION >= NTDDI_WIN7)

'#if (NTDDI_VERSION >= NTDDI_VISTA) || (_WIN32_IE >= _WIN32_IE_IE70)
'#ifndef NO_SHOBJIDL_SORTDIRECTION
' enum SORTDIRECTION
%SORT_DESCENDING = -1
%SORT_ASCENDING  = 1
'#endif  // NO_SHOBJIDL_SORTDIRECTION
'typedef int SORTDIRECTION;

' // Size = 24 bytes
TYPE SORTCOLUMN DWORD
   propkey   AS PROPERTYKEY
   direction AS LONG   ' SORTDIRECTION
END TYPE

' enum FVTEXTTYPE
%FVST_EMPTYTEXT = 0


' ########################################################################################
' IFolderView2 interface
' IID = 1AF3A467-214F-4298-908E-06B03E0B39F9
' Inherited interface = IFolderView
' ########################################################################################

#IF NOT %DEF(%IFolderView2_INTERFACE_DEFINED)
    %IFolderView2_INTERFACE_DEFINED = 1

$IID_IFolderView2 = GUID$("{1AF3A467-214F-4298-908E-06B03E0B39F9}")

INTERFACE IFolderView2 $IID_IFolderView2

   INHERIT IUnknown

   ' =====================================================================================
   ' IFolderView Methods
   ' =====================================================================================
   METHOD GetCurrentViewMode ( _                        ' VTable offset = 12
     BYREF pViewMode AS DWORD _                         ' __inout UINT *pViewMode
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetCurrentViewMode ( _                        ' VTable offset = 16
     BYVAL ViewMode AS DWORD _                          ' __in UINT ViewMode
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFolder ( _                                 ' VTable offset = 20
     BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppv AS IUnknown _                            ' __out void **ppv
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Item ( _                                      ' VTable offset = 24
     BYVAL iItemIndex AS LONG _                         ' __in int iItemIndex
   , BYREF ppidl AS DWORD _                             ' __out LPITEMIDLIST *ppidl
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ItemCount ( _                                 ' VTable offset = 28
     BYVAL uFlags AS DWORD _                            ' __in UINT uFlags
   , BYREF pcItems AS LONG _                            ' __out int *pcItems
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Items ( _                                     ' VTable offset = 32
     BYVAL uFlags AS DWORD _                            ' __in UINT uFlags
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppv AS IUnknown _                            ' __out void **ppv
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSelectionMarkedItem ( _                    ' VTable offset = 36
     BYREF piItem AS LONG _                             ' __out int *piItem
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFocusedItem ( _                            ' VTable offset = 40
     BYREF piItem AS LONG _                             ' __out int *piItem
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetItemPosition ( _                           ' VTable offset = 44
     BYVAL pidl AS DWORD _                              ' __in LPCITEMIDLIST pidl
   , BYREF ppt AS POINT _                               ' __out POINT *ppt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSpacing ( _                                ' VTable offset = 48
     BYREF ppt AS POINT _                               ' __inout POINT *ppt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDefaultSpacing ( _                         ' VTable offset = 52
     BYREF ppt AS POINT _                               ' __out POINT *ppt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAutoArrange ( _                            ' VTable offset = 56
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SelectItem ( _                                ' VTable offset = 60
     BYVAL iItem AS LONG _                              ' __in int iItem
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SelectAndPositionItems ( _                    ' VTable offset = 64
     BYVAL cidl AS DWORD _                              ' __in UINT cidl
   , BYVAL apidl AS DWORD _                             ' __in LPCITEMIDLIST *apidl
   , BYREF apt AS POINT _                               ' __in POINT *apt
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IFolderView2 Methods
   ' =====================================================================================
   METHOD SetGroupBy ( _                                ' VTable offset = 68
     BYREF key AS PROPERTYKEY _                         ' __in REFPROPERTYKEY key
   , BYVAL fAscending AS LONG _                         ' __in BOOL fAscending
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetGroupBy ( _                                ' VTable offset = 72
     BYREF pkey AS PROPERTYKEY _                        ' __out PROPERTYKEY *pkey
   , BYREF pfAscending AS LONG _                        ' __out BOOL *pfAscending
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetViewProperty ( _                           ' VTable offset = 76
     BYVAL pidl AS DWORD _                              ' __in PCUITEMID_CHILD pidl
   , BYREF propkey AS PROPERTYKEY _                     ' __in REFPROPERTYKEY propkey
   , BYREF propvar AS PROPVARIANT _                     ' __in REFPROPVARIANT propvar
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetViewProperty ( _                           ' VTable offset = 80
     BYVAL pidl AS DWORD _                              ' __in PCUITEMID_CHILD pidl
   , BYREF propkey AS PROPERTYKEY _                     ' __in REFPROPERTYKEY propkey
   , BYREF ppropvar AS PROPVARIANT _                    ' __out PROPVARIANT *ppropvar
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetTileViewProperties ( _                     ' VTable offset = 84
     BYVAL pidl AS DWORD _                              ' __in PCUITEMID_CHILD pidl
   , BYREF pszPropList AS WSTRINGZ _                    ' __in LPCWSTR pszPropList
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetExtendedTileViewProperties ( _             ' VTable offset = 88
     BYVAL pidl AS DWORD _                              ' __in PCUITEMID_CHILD pidl
   , BYREF pszPropList AS WSTRINGZ _                    ' __in LPCWSTR pszPropList
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetText ( _                                   ' VTable offset = 92
     BYVAL iType AS LONG _                              ' __in FVTEXTTYPE iType
   , BYREF pwszText AS WSTRINGZ _                       ' __in LPCWSTR pwszText
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetCurrentFolderFlags ( _                     ' VTable offset = 96
     BYVAL dwMask AS DWORD _                            ' __in DWORD dwMask
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCurrentFolderFlags ( _                     ' VTable offset = 100
     BYREF pdwFlags AS DWORD _                          ' __out DWORD *pdwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSortColumnCount ( _                        ' VTable offset = 104
     BYREF pcColumns AS LONG _                          ' __out int *pcColumns
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetSortColumns ( _                            ' VTable offset = 108
     BYREF rgSortColumns AS SORTCOLUMN _                ' __in const SORTCOLUMN *rgSortColumns
   , BYVAL cColumns AS LONG _                           ' __in int cColumns
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSortColumns ( _                            ' VTable offset = 112
     BYREF rgSortColumns AS SORTCOLUMN _                ' __out SORTCOLUMN *rgSortColumns
   , BYVAL cColumns AS LONG _                           ' __in int cColumns
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetItem ( _                                   ' VTable offset = 116
     BYVAL iItem AS LONG _                              ' __in int iItem
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppv AS IUnknown _                            ' __out void **ppv
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetVisibleItem ( _                            ' VTable offset = 120
     BYVAL iStart AS LONG _                             ' __in int iStart
   , BYVAL fPrevious AS LONG _                          ' __in BOOL fPrevious
   , BYREF piItem AS LONG _                             ' __out int *piItem
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSelectedItem ( _                           ' VTable offset = 124
     BYVAL iStart AS LONG _                             ' __in int iStart
   , BYREF piItem AS LONG _                             ' __out int *piItem
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSelection ( _                              ' VTable offset = 128
     BYVAL fNoneImpliesFolder AS LONG _                 ' __in BOOL fNoneImpliesFolder
   , BYREF ppsia AS IShellItemArray _                   ' __out IShellItemArray **ppsia
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSelectionState ( _                         ' VTable offset = 132
     BYVAL pidl AS DWORD _                              ' __in PCUITEMID_CHILD pidl
   , BYREF pdwFlags AS DWORD _                          ' __out DWORD *pdwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD InvokeVerbOnSelection ( _                     ' VTable offset = 136
     BYVAL pszVerb AS DWORD _                           ' __in LPCSTR pszVerb
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetViewModeAndIconSize ( _                    ' VTable offset = 140
     BYVAL uViewMode AS LONG _                          ' __in FOLDERVIEWMODE uViewMode
   , BYVAL iImageSize AS LONG _                         ' __in int iImageSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetViewModeAndIconSize ( _                    ' VTable offset = 144
     BYREF puViewMode AS LONG _                         ' __out FOLDERVIEWMODE *puViewMode
   , BYREF piImageSize AS LONG _                        ' __out int *piImageSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetGroupSubsetCount ( _                       ' VTable offset = 148
     BYVAL cVisibleRows AS DWORD _                      ' __in UINT cVisibleRows
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetGroupSubsetCount ( _                       ' VTable offset = 152
     BYREF pcVisibleRows AS DWORD _                     ' __out UINT *pcVisibleRows
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetRedraw ( _                                 ' VTable offset = 156
     BYVAL fRedrawOn AS LONG _                          ' __in BOOL fRedrawOn
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsMoveInSameFolder ( _                        ' VTable offset = 160
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DoRename ( _                                  ' VTable offset = 164
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IFolderView2_INTERFACE_DEFINED__ */

'#if (NTDDI_VERSION >= NTDDI_VISTA)

' ########################################################################################
' IFolderViewSettings interface
' IID = AE8C987D-8797-4ED3-BE72-2A47DD938DB0
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IFolderViewSettings_INTERFACE_DEFINED)
    %IFolderViewSettings_INTERFACE_DEFINED= 1

$IID_IFolderViewSettings = GUID$("{AE8C987D-8797-4ED3-BE72-2A47DD938DB0}")

INTERFACE IFolderViewSettings $IID_IFolderViewSettings

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetColumnPropertyList ( _                     ' VTable offset = 12
     BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppv AS IUnknown _                            ' __out void **ppv
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetGroupByProperty ( _                        ' VTable offset = 16
     BYREF pkey AS PROPERTYKEY _                        ' __out PROPERTYKEY *pkey
   , BYREF pfGroupAscending AS LONG _                   ' __out BOOL *pfGroupAscending
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetViewMode ( _                               ' VTable offset = 20
     BYREF plvm AS LONG _                               ' __out FOLDERLOGICALVIEWMODE *plvm
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetIconSize ( _                               ' VTable offset = 24
     BYREF puIconSize AS DWORD _                        ' __out UINT *puIconSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFolderFlags ( _                            ' VTable offset = 28
     BYREF pfolderMask AS DWORD _                       ' __out FOLDERFLAGS *pfolderMask
   , BYREF pfolderFlags AS DWORD _                      ' __out FOLDERFLAGS *pfolderFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSortColumns ( _                            ' VTable offset = 32
     BYREF rgSortColumns AS SORTCOLUMN _                ' __out SORTCOLUMN *rgSortColumns
   , BYVAL cColumnsIn AS DWORD _                        ' __in UINT cColumnsIn
   , BYREF pcColumnsOut AS DWORD _                      ' __out UINT *pcColumnsOut
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetGroupSubsetCount ( _                       ' VTable offset = 36
     BYREF pcVisibleRows AS DWORD _                     ' __out UINT *pcVisibleRows
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IFolderViewSettings_INTERFACE_DEFINED__ */

'#endif  // NTDDI_VISTA
'#endif  // (_WIN32_IE >= _WIN32_IE_IE70)

'#if (_WIN32_IE >= _WIN32_IE_IE70)

' ########################################################################################
' IPreviewHandlerVisuals interface
' IID = C0A651F5-B48B-11d2-B5ED-006097C686F6
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IPreviewHandlerVisuals_INTERFACE_DEFINED)
    %IPreviewHandlerVisuals_INTERFACE_DEFINED= 1

$IID_IPreviewHandlerVisuals = GUID$("{C0A651F5-B48B-11d2-B5ED-006097C686F6}")

INTERFACE IPreviewHandlerVisuals $IID_IPreviewHandlerVisuals

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetBackgroundColor ( _                        ' VTable offset = 12
     BYVAL color AS DWORD _                             ' __in COLORREF color
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetFont ( _                                   ' VTable offset = 16
     BYREF plf AS LOGFONTW _                            ' __in const LOGFONTW *plf
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetTextColor ( _                              ' VTable offset = 20
     BYVAL color AS DWORD _                             ' __in COLORREF color
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IPreviewHandlerVisuals_INTERFACE_DEFINED__ */


' ########################################################################################
' IVisualProperties interface
' IID = E693CF68-D967-4112-8763-99172AEE5E5A
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IVisualProperties_INTERFACE_DEFINED)
    %IVisualProperties_INTERFACE_DEFINED= 1

$IID_IVisualProperties = GUID$("{E693CF68-D967-4112-8763-99172AEE5E5A}")

' enum VPWATERMARKFLAGS
%VPWF_DEFAULT        = 0
%VPWF_ALPHABLEND     = &H1

' enum VPCOLORFLAGS
%VPCF_TEXT           = 1
%VPCF_BACKGROUND     = 2
%VPCF_SORTCOLUMN     = 3
%VPCF_SUBTEXT        = 4
%VPCF_TEXTBACKGROUND = 5

INTERFACE IVisualProperties $IID_IVisualProperties

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetWatermark ( _                              ' VTable offset = 12
     BYVAL hbmp AS DWORD _                              ' __in HBITMAP hbmp
   , BYVAL vpwf AS DWORD _                              ' __in VPWATERMARKFLAGS vpwf
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetColor ( _                                  ' VTable offset = 16
     BYVAL vpcf AS DWORD _                              ' __in VPCOLORFLAGS vpcf
   , BYVAL cr AS DWORD _                                ' __in COLORREF cr
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetColor ( _                                  ' VTable offset = 20
     BYREF vpcf AS DWORD _                              ' __in VPCOLORFLAGS vpcf
   , BYREF pcr AS DWORD _                               ' __out COLORREF *pcr
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetItemHeight ( _                             ' VTable offset = 24
     BYVAL cyItemInPixels AS LONG _                     ' __in int cyItemInPixels
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetItemHeight ( _                             ' VTable offset = 28
     BYREF cyItemInPixels AS LONG _                     ' __out int *cyItemInPixels
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetFont ( _                                   ' VTable offset = 32
     BYREF plf AS LOGFONTW _                            ' __in const LOGFONTW *plf
   , BYVAL bRedraw AS LONG _                            ' __in BOOL bRedraw
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFont ( _                                   ' VTable offset = 36
     BYREF plf AS LOGFONTW _                            ' __out LOGFONTW *plf
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetTheme ( _                                  ' VTable offset = 40
     BYREF pszSubAppName AS WSTRINGZ _                  ' __in LPCWSTR pszSubAppName
   , BYREF pszSubIdList AS WSTRINGZ _                   ' __in LPCWSTR pszSubIdList
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IVisualProperties_INTERFACE_DEFINED__ */

'#endif  // _WIN32_IE_IE70


%CDBOSC_SETFOCUS     = &H00000000???
%CDBOSC_KILLFOCUS    = &H00000001???
%CDBOSC_SELCHANGE    = &H00000002???
%CDBOSC_RENAME       = &H00000003???
%CDBOSC_STATECHANGE  = &H00000004???


' ########################################################################################
' ICommDlgBrowser interface
' IID = 000214F1-0000-0000-C000-000000000046
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ICommDlgBrowser_INTERFACE_DEFINED)
    %ICommDlgBrowser_INTERFACE_DEFINED = 1

$IID_ICommDlgBrowser = GUID$("{000214F1-0000-0000-C000-000000000046}")
$SID_SExplorerBrowserFrame = $IID_ICommDlgBrowser

INTERFACE ICommDlgBrowser $IID_ICommDlgBrowser

   INHERIT IUnknown

   ' =====================================================================================
   METHOD OnDefaultCommand ( _                          ' VTable offset = 12
     BYVAL ppshv AS IShellView _                        ' __in IShellView * ppshv
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnStateChange ( _                             ' VTable offset = 16
     BYVAL ppshv AS IShellView _                        ' __in IShellView * ppshv
   , BYVAL uChange AS DWORD _                           ' __in ULONG uChange
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IncludeObject ( _                             ' VTable offset = 20
     BYVAL ppshv AS IShellView _                        ' __in IShellView * ppshv
   , BYVAL pidl AS DWORD _                              ' __in LPCITEMIDLIST pidl
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICommDlgBrowser_INTERFACE_DEFINED__ */


'#if (NTDDI_VERSION >= NTDDI_WIN2K)
%CDB2N_CONTEXTMENU_DONE   = &H00000001???
%CDB2N_CONTEXTMENU_START  = &H00000002???
'//GetViewFlags
%CDB2GVF_SHOWALLFILES     = &H00000001???
'#if (NTDDI_VERSION >= NTDDI_VISTA)
%CDB2GVF_ISFILESAVE       = &H00000002???   ' // is file save, else file open
%CDB2GVF_ALLOWPREVIEWPANE = &H00000004???
%CDB2GVF_NOSELECTVERB     = &H00000008???
%CDB2GVF_NOINCLUDEITEM    = &H00000010???
%CDB2GVF_ISFOLDERPICKER   = &H00000020???
%CDB2GVF_ADDSHIELD        = &H00000040???   ' // when CDB2GVF_NOSELECTVERB is not specified this flag controls the display of a LUA shield on the Select menu item
'#endif  // NTDDI_VISTA


' ########################################################################################
' ICommDlgBrowser2 interface
' IID = 000214F1-0000-0000-C000-000000000046
' Inherited interface = ICommDlgBrowser
' ########################################################################################

#IF NOT %DEF(%ICommDlgBrowser2_INTERFACE_DEFINED)
    %ICommDlgBrowser2_INTERFACE_DEFINED = 1

$IID_ICommDlgBrowser2 = GUID$("{10339516-2894-11d2-9039-00C04F8EEB3E}")

INTERFACE ICommDlgBrowser2 $IID_ICommDlgBrowser2

   INHERIT IUnknown

   ' =====================================================================================
   ' ICommDlgBrowser Methods
   ' =====================================================================================
   METHOD OnDefaultCommand ( _                          ' VTable offset = 12
     BYVAL ppshv AS IShellView _                        ' __in IShellView * ppshv
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnStateChange ( _                             ' VTable offset = 16
     BYVAL ppshv AS IShellView _                        ' __in IShellView * ppshv
   , BYVAL uChange AS DWORD _                           ' __in ULONG uChange
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IncludeObject ( _                             ' VTable offset = 20
     BYVAL ppshv AS IShellView _                        ' __in IShellView * ppshv
   , BYVAL pidl AS DWORD _                              ' __in LPCITEMIDLIST pidl
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' ICommDlgBrowser2 Methods
   ' =====================================================================================
   METHOD Notify ( _                                    ' VTable offset = 24
     BYVAL ppshv AS IShellView _                        ' __in IShellView * ppshv
   , BYVAL dwNotifyType AS DWORD _                      ' __in DWORD dwNotifyType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDefaultMenuText ( _                        ' VTable offset = 28
     BYVAL ppshv AS IShellView _                        ' __in IShellView * ppshv
   , BYREF pszText AS WSTRINGZ _                        ' __in WCHAR *pszText
   , BYVAL cchMax AS LONG _                             ' __in INT cchMax
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetViewFlags ( _                              ' VTable offset = 32
     BYREF pdwFlags AS DWORD _                          ' __out DWORD *pdwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICommDlgBrowser2_INTERFACE_DEFINED__ */

'#endif  // NTDDI_WIN2K

'#if (_WIN32_IE >= _WIN32_IE_IE70)

' ########################################################################################
' ICommDlgBrowser3 interface
' IID = C8AD25A1-3294-41EE-8165-71174BD01C57
' Inherited interface = ICommDlgBrowser2
' ########################################################################################

#IF NOT %DEF(%ICommDlgBrowser3_INTERFACE_DEFINED)
    %ICommDlgBrowser3_INTERFACE_DEFINED = 1

$IID_ICommDlgBrowser3 = GUID$("{C8AD25A1-3294-41EE-8165-71174BD01C57}")

INTERFACE ICommDlgBrowser3 $IID_ICommDlgBrowser3

   INHERIT IUnknown

   ' =====================================================================================
   ' ICommDlgBrowser Methods
   ' =====================================================================================
   METHOD OnDefaultCommand ( _                          ' VTable offset = 12
     BYVAL ppshv AS IShellView _                        ' __in IShellView * ppshv
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnStateChange ( _                             ' VTable offset = 16
     BYVAL ppshv AS IShellView _                        ' __in IShellView * ppshv
   , BYVAL uChange AS DWORD _                           ' __in ULONG uChange
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IncludeObject ( _                             ' VTable offset = 20
     BYVAL ppshv AS IShellView _                        ' __in IShellView * ppshv
   , BYVAL pidl AS DWORD _                              ' __in LPCITEMIDLIST pidl
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' ICommDlgBrowser2 Methods
   ' =====================================================================================
   METHOD Notify ( _                                    ' VTable offset = 24
     BYVAL ppshv AS IShellView _                        ' __in IShellView * ppshv
   , BYVAL dwNotifyType AS DWORD _                      ' __in DWORD dwNotifyType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDefaultMenuText ( _                        ' VTable offset = 28
     BYVAL ppshv AS IShellView _                        ' __in IShellView * ppshv
   , BYREF pszText AS WSTRINGZ _                        ' __in WCHAR *pszText
   , BYVAL cchMax AS LONG _                             ' __in INT cchMax
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetViewFlags ( _                              ' VTable offset = 32
     BYREF pdwFlags AS DWORD _                          ' __out DWORD *pdwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' ICommDlgBrowser3 Methods
   ' =====================================================================================
   METHOD OnColumnClicked ( _                           ' VTable offset = 36
     BYVAL ppshv AS IShellView _                        ' __in IShellView *ppshv
   , BYVAL iColumn AS LONG _                            ' __in int iColumn
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCurrentFilter ( _                          ' VTable offset = 40
     BYREF pszFileSpec AS WSTRINGZ _                    ' __out LPWSTR pszFileSpec
   , BYVAL cchFileSpec AS LONG _                        ' __in int cchFileSpec
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnPreViewCreated ( _                          ' VTable offset = 44
     BYVAL ppshv AS IShellView _                        ' __in IShellView *ppshv
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICommDlgBrowser3_INTERFACE_DEFINED__ */

' enum CM_MASK
%CM_MASK_WIDTH               = &H1
%CM_MASK_DEFAULTWIDTH        = &H2
%CM_MASK_IDEALWIDTH          = &H4
%CM_MASK_NAME                = &H8
%CM_MASK_STATE               = &H10

' enum CM_STATE
%CM_STATE_NONE               = 0
%CM_STATE_VISIBLE            = &H1
%CM_STATE_FIXEDWIDTH         = &H2
%CM_STATE_NOSORTBYFOLDERNESS = &H4
%CM_STATE_ALWAYSVISIBLE      = &H8

' enum CM_ENUM_FLAGS
%CM_ENUM_ALL                 = &H1
%CM_ENUM_VISIBLE             = &H2

' enum %CM_SET_WIDTH_VALUE
%CM_WIDTH_USEDEFAULT         = -1
%CM_WIDTH_AUTOSIZE           = -2

' // Size = 184 bytes
TYPE CM_COLUMNINFO DWORD
   cbSize        AS DWORD           ' DWORD
   dwMask        AS DWORD           ' DWORD
   dwState       AS DWORD           ' DWORD
   uWidth        AS DWORD           ' UINT
   uDefaultWidth AS DWORD           ' UINT
   uIdealWidth   AS DWORD           ' UINT
   wszName       AS WSTRINGZ * 80   ' WCHAR
END TYPE

' ########################################################################################
' IColumnManager interface
' IID = C0A651F5-B48B-11d2-B5ED-006097C686F6
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IColumnManager_INTERFACE_DEFINED)
    %IColumnManager_INTERFACE_DEFINED= 1

$IID_IColumnManager = GUID$("{C0A651F5-B48B-11d2-B5ED-006097C686F6}")

INTERFACE IColumnManager $IID_IColumnManager

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetColumnInfo ( _                             ' VTable offset = 12
     BYREF propkey AS PROPERTYKEY _                     ' __in REFPROPERTYKEY propkey
   , BYREF pcmci AS CM_COLUMNINFO _                     ' __in const CM_COLUMNINFO *pcmci
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetColumnInfo ( _                             ' VTable offset = 16
     BYREF propkey AS PROPERTYKEY _                     ' __in REFPROPERTYKEY propkey
   , BYREF pcmci AS CM_COLUMNINFO _                     ' __out CM_COLUMNINFO *pcmci
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetColumnCount ( _                            ' VTable offset = 20
     BYVAL dwFlags AS DWORD _                           ' __in CM_ENUM_FLAGS dwFlags
   , BYREF puCount AS DWORD _                           ' __out UINT *puCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetColumns ( _                                ' VTable offset = 24
     BYVAL dwFlags AS DWORD _                           ' __in CM_ENUM_FLAGS dwFlags
   , BYREF rgkeyOrder AS PROPERTYKEY _                  ' __out PROPERTYKEY *rgkeyOrder
   , BYVAL cColumns AS DWORD _                          ' __in UINT cColumns
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetColumns ( _                                ' VTable offset = 28
     BYREF rgkeyOrder AS PROPERTYKEY _                  ' __in const PROPERTYKEY *rgkeyOrder
   , BYVAL cVisible AS DWORD _                          ' __in UINT cVisible
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IColumnManager_INTERFACE_DEFINED__ */

'#endif  // (_WIN32_IE >= _WIN32_IE_IE70)


' ########################################################################################
' IFolderFilterSite interface
' IID = C0A651F5-B48B-11d2-B5ED-006097C686F6
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IFolderFilterSite_INTERFACE_DEFINED)
    %IFolderFilterSite_INTERFACE_DEFINED= 1

$IID_IFolderFilterSite = GUID$("{C0A651F5-B48B-11d2-B5ED-006097C686F6}")

INTERFACE IFolderFilterSite $IID_IFolderFilterSite

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetFilter ( _                                 ' VTable offset = 12
     BYVAL punk AS IUnknown _                           ' __in IUnknown *punk
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IFolderFilterSite_INTERFACE_DEFINED__ */


' ########################################################################################
' IFolderFilter interface
' IID = 9CC22886-DC8E-11D2-B1D0-00C04F8EEB3E
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IFolderFilter_INTERFACE_DEFINED)
    %IFolderFilter_INTERFACE_DEFINED = 1

$IID_IFolderFilter = GUID$("{9CC22886-DC8E-11D2-B1D0-00C04F8EEB3E}")

INTERFACE IFolderFilter $IID_IFolderFilter

   INHERIT IUnknown

   ' =====================================================================================
   METHOD ShouldShow ( _                                ' VTable offset = 12
     BYVAL psf AS IShellFolder _                        ' __in IShellFolder *psf
   , BYVAL pidlFolder AS DWORD _                        ' __in LPCITEMIDLIST pidlFolder
   , BYVAL pidlItem AS DWORD _                          ' __in LPCITEMIDLIST pidlItem
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetEnumFlags ( _                              ' VTable offset = 16
     BYVAL psf AS IShellFolder _                        ' __in IShellFolder *psf
   , BYVAL pidlFolder AS DWORD _                        ' __in LPCITEMIDLIST pidlFolder
   , BYVAL phwnd AS DWORD _                             ' __in HWND *phwnd
   , BYREF pgrfFlags AS DWORD _                         ' __out DWORD *pgrfFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IFolderFilter_INTERFACE_DEFINED__ */


' ########################################################################################
' IInputObjectSite interface
' IID = F1DB8392-7331-11D0-8C99-00A0C92DBFE8
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IInputObjectSite_INTERFACE_DEFINED)
    %IInputObjectSite_INTERFACE_DEFINED = 1

$IID_IInputObjectSite = GUID$("{F1DB8392-7331-11D0-8C99-00A0C92DBFE8}")

INTERFACE IInputObjectSite $IID_IInputObjectSite

   INHERIT IUnknown

   ' =====================================================================================
   METHOD OnFocusChangeIS ( _                           ' VTable offset = 12
     BYVAL punkObj AS IUnknown _                        ' __in IUnknown* punkObj
   , BYVAL fSetFocus AS LONG _                          ' __in BOOL fSetFocus
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IInputObjectSite_INTERFACE_DEFINED__ */


' ########################################################################################
' IInputObject interface
' IID = 68284FAA-6A48-11D0-8C78-00C04FD918B4
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IInputObject_INTERFACE_DEFINED)
    %IInputObject_INTERFACE_DEFINED = 1

$IID_IInputObject = GUID$("{68284FAA-6A48-11D0-8C78-00C04FD918B4}")

INTERFACE IInputObject $IID_IInputObject

   INHERIT IUnknown

   ' =====================================================================================
   METHOD UIActivateIO ( _                              ' VTable offset = 12
     BYVAL fActivate AS LONG _                          ' __in BOOL fActivate
   , BYVAL lpMsg AS DWORD _                             ' __in LPMSG lpMsg
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD HasFocusIO ( _                                ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD TranslateAcceleratorIO ( _                    ' VTable offset = 20
     BYVAL lpMsg AS DWORD _                             ' __in LPMSG lpMsg
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IInputObject_INTERFACE_DEFINED__ */


' ########################################################################################
' IInputObject2 interface
' IID = 6915C085-510B-44CD-94AF-28DFA56CF92B
' Inherited interface = IInputObject
' ########################################################################################

#IF NOT %DEF(%IInputObject2_INTERFACE_DEFINED)
    %IInputObject2_INTERFACE_DEFINED = 1

$IID_IInputObject2 = GUID$("{6915C085-510B-44CD-94AF-28DFA56CF92B}")

INTERFACE IInputObject2 $IID_IInputObject2

   INHERIT IUnknown

   ' =====================================================================================
   ' IInputObject Methods
   ' =====================================================================================
   METHOD UIActivateIO ( _                              ' VTable offset = 12
     BYVAL fActivate AS LONG _                          ' __in BOOL fActivate
   , BYVAL lpMsg AS DWORD _                             ' __in LPMSG lpMsg
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD HasFocusIO ( _                                ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD TranslateAcceleratorIO ( _                    ' VTable offset = 20
     BYVAL lpMsg AS DWORD _                             ' __in LPMSG lpMsg
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IInputObject2 Methods
   ' =====================================================================================
   METHOD TranslateAcceleratorGlobal ( _                ' VTable offset = 24
     BYREF pMsg AS tagMSG _                             ' __in MSG *pMsg
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IInputObject2_INTERFACE_DEFINED__ */


' ########################################################################################
' IShellIcon interface
' IID = 000214E5-0000-0000-C000-000000000046
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IShellIcon_INTERFACE_DEFINED)
    %IShellIcon_INTERFACE_DEFINED = 1

$IID_IShellIcon = GUID$("{000214E5-0000-0000-C000-000000000046}")

INTERFACE IShellIcon $IID_IShellIcon

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetIconOf ( _                                 ' VTable offset = 12
     BYVAL pidl AS DWORD _                              ' __in LPCITEMIDLIST pidl
   , BYVAL flags AS DWORD _                             ' __in UINT flags
   , BYREF lpIconIndex AS LONG _                        ' __out LPINT lpIconIndex
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IShellIcon_INTERFACE_DEFINED__ */

%SBSP_DEFBROWSER            = &H0000???
%SBSP_SAMEBROWSER           = &H0001???
%SBSP_NEWBROWSER            = &H0002???
%SBSP_DEFMODE               = &H0000???
%SBSP_OPENMODE              = &H0010???
%SBSP_EXPLOREMODE           = &H0020???
%SBSP_HELPMODE              = &H0040???        ' // IEUNIX : Help window uses this.
%SBSP_NOTRANSFERHIST        = &H0080???
%SBSP_ABSOLUTE              = &H0000???
%SBSP_RELATIVE              = &H1000???
%SBSP_PARENT                = &H2000???
%SBSP_NAVIGATEBACK          = &H4000???
%SBSP_NAVIGATEFORWARD       = &H8000???
%SBSP_ALLOW_AUTONAVIGATE    = &H00010000???
'#if (NTDDI_VERSION >= NTDDI_VISTA)
%SBSP_KEEPSAMETEMPLATE      = &H00020000???
%SBSP_KEEPWORDWHEELTEXT     = &H00040000???
%SBSP_ACTIVATE_NOFOCUS      = &H00080000???
'#endif  // (NTDDI_VERSION >= NTDDI_VISTA)
'#if (_WIN32_IE >= _WIN32_IE_IE60SP2)
%SBSP_CALLERUNTRUSTED       = &H00800000???
%SBSP_TRUSTFIRSTDOWNLOAD    = &H01000000???
%SBSP_UNTRUSTEDFORDOWNLOAD  = &H02000000???
'#endif  // _WIN32_IE_IE60SP2
%SBSP_NOAUTOSELECT          = &H04000000???
%SBSP_WRITENOHISTORY        = &H08000000???
'#if (_WIN32_IE >= _WIN32_IE_IE60SP2)
%SBSP_TRUSTEDFORACTIVEX     = &H10000000???
'#endif  // _WIN32_IE_IE60SP2
'#if (_WIN32_IE >= _WIN32_IE_IE70)
%SBSP_FEEDNAVIGATION        = &H20000000???
'#endif  // _WIN32_IE_IE70
%SBSP_REDIRECT              = &H40000000???
%SBSP_INITIATEDBYHLINKFRAME = &H80000000???
%FCW_STATUS                 = &H0001???
%FCW_TOOLBAR                = &H0002???
%FCW_TREE                   = &H0003???
%FCW_INTERNETBAR            = &H0006???
%FCW_PROGRESS               = &H0008???
'#if (_WIN32_IE >= 0x0700)
'#endif
%FCT_MERGE                  = &H0001???
%FCT_CONFIGABLE             = &H0002???
%FCT_ADDTOEND               = &H0004???

'#ifdef _NEVER_
'typedef LPARAM LPTBBUTTONSB;
'#else //!_NEVER_
'#include <commctrl.h>
'typedef LPTBBUTTON LPTBBUTTONSB;
'#endif //_NEVER_

' To avoid to include commctrl.inc
#IF NOT %DEF(%TBBUTTON_DEFINED)
%TBBUTTON_DEFINED = 1
' // Size = 20 bytes
TYPE TBBUTTON BYTE
   iBitmap      AS LONG             ' int iBitmap
   idCommand    AS LONG             ' int idCommand
   fsState      AS BYTE             ' BYTE fsState
   fsStyle      AS BYTE             ' BYTE fsStyle
'#ifdef _WIN64
'   bReserved(5) AS BYTE            ' BYTE bReserved[6] // padding for alignment
'#elif defined(_WIN32)
   bReserved(1) AS BYTE            ' BYTE bReserved[2] // padding for alignment
'#endif
   dwData       AS DWORD            ' DWORD_PTR dwData
   iString      AS DWORD            ' INT_PTR iString
END TYPE
#ENDIF

' ########################################################################################
' IShellBrowser interface
' IID = 000214E2-0000-0000-C000-000000000046
' Inherited interface = IOleWindow
' ########################################################################################

#IF NOT %DEF(%IShellBrowser_INTERFACE_DEFINED)
    %IShellBrowser_INTERFACE_DEFINED = 1

$IID_IShellBrowser = GUID$("{000214E2-0000-0000-C000-000000000046}")

INTERFACE IShellBrowser $IID_IShellBrowser

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
   ' IShellBrowser methods
   ' =====================================================================================
   METHOD InsertMenusSB ( _                             ' VTable offset = 20
     BYVAL hmenuShared AS DWORD _                       ' __in HMENU hmenuShared
   , BYREF lpMenuWidths AS OLEMENUGROUPWIDTHS _         ' __inout LPOLEMENUGROUPWIDTHS lpMenuWidths
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetMenuSB ( _                                 ' VTable offset = 24
     BYVAL hmenuShared AS DWORD _                       ' __in HMENU hmenuShared
   , BYVAL holemenuRes AS DWORD _                       ' __in HOLEMENU holemenuRes
   , BYVAL hwndActiveObject AS DWORD _                  ' __in HWND hwndActiveObject
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RemoveMenusSB ( _                             ' VTable offset = 28
     BYVAL hmenuShared AS DWORD _                       ' __in HMENU hmenuShared
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetStatusTextSB ( _                           ' VTable offset = 32
     BYREF pszStatusText AS WSTRINGZ _                  ' __in LPCOLESTR pszStatusText
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnableModelessSB ( _                          ' VTable offset = 36
     BYVAL fEnable AS LONG _                            ' __in BOOL fEnable
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD TranslateAcceleratorSB ( _                    ' VTable offset = 40
     BYREF pmsg AS tagMSG _                             ' __in MSG *pmsg
   , BYVAL wID AS WORD _                                ' __in WORD wID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD BrowseObject ( _                              ' VTable offset = 44
     BYVAL pidl AS DWORD _                              ' __in LPCITEMIDLIST pidl
   , BYVAL wFlags AS DWORD _                            ' __in UINT wFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetViewStateStream ( _                        ' VTable offset = 48
     BYVAL grfMode AS DWORD _                           ' __in DWORD grfMode
   , BYREF ppStrm AS IStream _                          ' __out IStream **ppStrm
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetControlWindow ( _                          ' VTable offset = 52
     BYVAL id AS DWORD _                                ' __in UINT id
   , BYREF phwnd AS DWORD _                             ' __out HWND *phwnd
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SendControlMsg ( _                            ' VTable offset = 56
     BYVAL id AS DWORD _                                ' __in UINT id
   , BYVAL uMsg AS DWORD _                              ' __in UINT uMsg
   , BYVAL wParam AS DWORD _                            ' __in WPARAM wParam
   , BYVAL lParam AS LONG _                             ' __in LPARAM lParam
   , BYREF pret AS LONG _                               ' __in LRESULT *pret
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD QueryActiveShellView ( _                      ' VTable offset = 60
     BYREF ppshv AS IShellView _                        ' __out IShellView **ppshv
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnViewWindowActive ( _                        ' VTable offset = 64
     BYVAL pshv AS IShellView _                         ' __in IShellView *pshv
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetToolbarItems ( _                           ' VTable offset = 68
     BYREF lpButtons AS TBBUTTON _                      ' __in LPTBBUTTONSB lpButtons
   , BYVAL nButtons AS DWORD _                          ' __in UINT nButtons
   , BYVAL uFlags AS DWORD _                            ' __in UINT uFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IShellBrowser_INTERFACE_DEFINED__ */


' ########################################################################################
' IProfferService interface
' IID = CB728B20-F786-11CE-92AD-00AA00A74CD0
' Inherited interface = IPersist
' ########################################################################################

#IF NOT %DEF(%IProfferService_INTERFACE_DEFINED)
    %IProfferService_INTERFACE_DEFINED = 1

$IID_IProfferService = GUID$("{CB728B20-F786-11CE-92AD-00AA00A74CD0}")
$SID_SProfferService = $IID_IProfferService   ' // nearest service that you can proffer to

INTERFACE IProfferService $IID_IProfferService

   INHERIT IUnknown

   ' =====================================================================================
   METHOD ProfferService ( _                            ' VTable offset = 12
     BYREF rguidService AS GUID _                       ' __in REFGUID rguidService
   , BYVAL psp AS IServiceProvider _                    ' __in IServiceProvider *psp
   , BYREF pdwCookie AS DWORD _                         ' __out DWORD *pdwCookie
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RevokeService ( _                             ' VTable offset = 16
     BYVAL dwCookie AS DWORD _                          ' __in DWORD dwCookie
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IProfferService_INTERFACE_DEFINED__ */

' Must be in unicode format
$STR_DONT_RESOLVE_LINK  = "Don't Resolve Link"
$STR_PLAYLIST_EDITOR_UI = "Static List In Dialog"

' ########################################################################################
' IShellItem interface
' IID = 43826D1E-E718-42EE-BC55-A1E261C37BFE
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IShellItem_INTERFACE_DEFINED)
    %IShellItem_INTERFACE_DEFINED = 1

' enum SIGDN
%SIGDN_NORMALDISPLAY               = 0
%SIGDN_PARENTRELATIVEPARSING       = &H80018001&
%SIGDN_DESKTOPABSOLUTEPARSING      = &H80028000&
%SIGDN_PARENTRELATIVEEDITING       = &H80031001&
%SIGDN_DESKTOPABSOLUTEEDITING      = &H8004c000&
%SIGDN_FILESYSPATH                 = &H80058000&
%SIGDN_URL                         = &H80068000&
%SIGDN_PARENTRELATIVEFORADDRESSBAR = &H8007c001&
%SIGDN_PARENTRELATIVE              = &H80080001&

' enum SHELLITEMCOMPAREHINTF
%SICHINT_DISPLAY                       = 0
%SICHINT_ALLFIELDS                     = &H80000000&
%SICHINT_CANONICAL                     = &H10000000&
%SICHINT_TEST_FILESYSPATH_IF_NOT_EQUAL = &H20000000&
'typedef DWORD SICHINTF;

$IID_IShellItem = GUID$("{43826D1E-E718-42EE-BC55-A1E261C37BFE}")

INTERFACE IShellItem $IID_IShellItem

   INHERIT IUnknown

   ' =====================================================================================
   METHOD BindToHandler ( _                             ' VTable offset = 12
     BYVAL pbc AS IBindCtx _                            ' __in IBindCtx *pbc
   , BYREF rbhid AS GUID _                              ' __in REFGUID rbhid
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppvOut AS IUnknown _                         ' __out void **ppvOut
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetParent ( _                                 ' VTable offset = 16
     BYREF ppsi AS IShellItem _                         ' __out IShellItem **ppsi
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDisplayName ( _                            ' VTable offset = 20
     BYVAL sigdnName AS DWORD _                         ' __in SIGDN sigdnName
   , BYREF ppszName AS DWORD _                          ' __out LPOLESTR *ppszName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAttributes ( _                             ' VTable offset = 24
     BYVAL sfgaoMask AS DWORD _                         ' __in SFGAOF sfgaoMask
   , BYREF psfgaoAttribs AS DWORD _                     ' __out SFGAOF *psfgaoAttribs
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Compare ( _                                   ' VTable offset = 28
     BYVAL psi AS IShellItem _                          ' __in IShellItem *psi
   , BYVAL hint AS DWORD _                              ' __in SICHINTF hint
   , BYREF piOrder AS LONG _                            ' __out int *piOrder
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IShellItem_INTERFACE_DEFINED__ */


DECLARE FUNCTION SHSimpleIDListFromPath IMPORT "SHELL32.DLL" ALIAS "SHSimpleIDListFromPath" ( _
   BYREF pszPath AS WSTRINGZ _                          ' __in LPCWSTR pszPath
 ) AS DWORD                                             ' PIDLIST_ABSOLUTE

'#if (_WIN32_IE >= _WIN32_IE_IE70)
'// CLSID_ShellItem create and init helper APIs. produce IShellItem derived interfaces from these different expressions of an item
DECLARE FUNCTION SHCreateItemFromIDList IMPORT "SHELL32.DLL" ALIAS "SHCreateItemFromIDList" ( _
   BYVAL pidl AS DWORD _                                ' __in PCIDLIST_ABSOLUTE pidl
 , BYREF riid AS GUID _                                 ' __in REFIID riid
 , BYREF ppv AS IUnknown _                              ' __out void **ppv
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION SHCreateItemFromParsingName IMPORT "SHELL32.DLL" ALIAS "SHCreateItemFromParsingName" ( _
   BYREF pszPath AS WSTRINGZ _                          ' __in PCWSTR pszPath
 , BYVAL pbc AS IBindCtx _                              ' __in_opt IBindCtx *pbc
 , BYREF riid AS GUID _                                 ' __in REFIID riid
 , BYREF ppv AS IUnknown _                              ' __out void **ppv
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION SHCreateItemWithParent IMPORT "SHELL32.DLL" ALIAS "SHCreateItemWithParent" ( _
   BYVAL pidlParent AS DWORD _                          ' __in_opt PCIDLIST_ABSOLUTE pidlParent
 , BYVAL psfParent AS IShellFolder _                    ' __in_opt IShellFolder *psfParent
 , BYVAL pidl AS DWORD _                                ' __in PCUITEMID_CHILD pidl
 , BYREF riid AS GUID _                                 ' __in REFIID riid
 , BYREF ppvItem AS IUnknown _                          ' __out void **ppvItem
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION SHCreateItemFromRelativeName IMPORT "SHELL32.DLL" ALIAS "SHCreateItemFromRelativeName" ( _
   BYVAL psiParent AS IShellItem _                      ' __in IShellItem *psiParent
 , BYREF pszName AS WSTRINGZ _                          ' __in PCWSTR pszName
 , BYVAL pbc AS IBindCtx _                              ' __in_opt IBindCtx* pbc
 , BYREF riid AS GUID _                                 ' __in REFIID riid
 , BYREF ppv AS IUnknown _                              ' __out void **ppv
 ) AS LONG                                              ' HRESULT

'#endif  // (_WIN32_IE >= _WIN32_IE_IE70)

'#if (NTDDI_VERSION >= NTDDI_VISTA)
DECLARE FUNCTION SHCreateItemInKnownFolder IMPORT "SHELL32.DLL" ALIAS "SHCreateItemInKnownFolder" ( _
   BYREF kfid AS GUID _                                 ' __in REFKNOWNFOLDERID kfid
 , BYVAL dwKFFlags AS DWORD _                           ' __in DWORD dwKFFlags
 , BYREF pszItem AS WSTRINGZ _                          ' __in_opt PCWSTR pszItem
 , BYREF riid AS GUID _                                 ' __in REFIID riid
 , BYREF ppv AS IUnknown _                              ' __out void **ppv
 ) AS LONG                                              ' HRESULT

'// get the IDList expression from an object, works with objects that support IPersistIDlist or IPersistIDlist like CLSID_ShellItem and most shell folders
DECLARE FUNCTION SHGetIDListFromObject IMPORT "SHELL32.DLL" ALIAS "SHGetIDListFromObject" ( _
   BYVAL punk AS IUnknown _                             ' __in_opt IUnknown *punk
 , BYREF ppidl AS ANY _                                 ' __out PIDLIST_ABSOLUTE *ppidl
 ) AS LONG                                              ' HRESULT

'// these APIs return object that support IPropertyStore or related interfaces
DECLARE FUNCTION SHGetPropertyStoreFromIDList IMPORT "SHELL32.DLL" ALIAS "SHGetPropertyStoreFromIDList" ( _
   BYVAL pidl AS DWORD _                                ' __in PCIDLIST_ABSOLUTE pidl
 , BYVAL flags AS DWORD _                               ' __in GETPROPERTYSTOREFLAGS flags
 , BYREF riid AS GUID _                                 ' __in REFIID riid
 , BYREF ppv AS IUnknown _                              ' __out void **ppv
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION SHGetPropertyStoreFromParsingName IMPORT "SHELL32.DLL" ALIAS "SHGetPropertyStoreFromParsingName" ( _
   BYREF pszPath AS WSTRINGZ _                          ' __in PCWSTR pszPath
 , BYVAL pbc AS IBindCtx _                              ' __in_opt IBindCtx *pbc
 , BYVAL flags AS DWORD _                               ' __in GETPROPERTYSTOREFLAGS flags
 , BYREF riid AS GUID _                                 ' __in REFIID riid
 , BYREF ppv AS IUnknown _                              ' __out void **ppv
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION SHGetNameFromIDList IMPORT "SHELL32.DLL" ALIAS "SHGetNameFromIDList" ( _
   BYVAL pidl AS DWORD _                                ' __in PCIDLIST_ABSOLUTE pidl
 , BYVAL sigdnName AS DWORD _                           ' __in SIGDN sigdnName
 , BYREF ppszName AS DWORD _                            ' __out PWSTR *ppszName
 ) AS LONG                                              ' HRESULT

'#endif // (NTDDI_VERSION >= NTDDI_VISTA)

'#if (NTDDI_VERSION >= NTDDI_WIN7)

' enum DATAOBJ_GET_ITEM_FLAGS
%DOGIF_DEFAULT       = 0???
%DOGIF_TRAVERSE_LINK = &H1???
%DOGIF_NO_HDROP      = &H2???
%DOGIF_NO_URL        = &H4???
%DOGIF_ONLY_IF_ONE   = &H8???

DECLARE FUNCTION SHGetItemFromDataObject IMPORT "SHELL32.DLL" ALIAS "SHGetItemFromDataObject" ( _
   BYVAL pdtobj AS IDataObject _                        ' __in IDataObject *pdtobj
 , BYVAL dwFlags AS DWORD _                             ' __in DATAOBJ_GET_ITEM_FLAGS dwFlags
 , BYREF riid AS GUID _                                 ' __in REFIID riid
 , BYREF ppv AS ANY _                                   ' __out void **ppv
 ) AS LONG                                              ' HRESULT

'#endif // (NTDDI_VERSION >= NTDDI_WIN7)

' Must be in unicode format
$STR_GPS_HANDLERPROPERTIESONLY      = "GPS_HANDLERPROPERTIESONLY"
$STR_GPS_FASTPROPERTIESONLY         = "GPS_FASTPROPERTIESONLY"
$STR_GPS_OPENSLOWITEM               = "GPS_OPENSLOWITEM"
$STR_GPS_DELAYCREATION              = "GPS_DELAYCREATION"
$STR_GPS_BESTEFFORT                 = "GPS_BESTEFFORT"
$STR_GPS_NO_OPLOCK                  = "GPS_NO_OPLOCK"


' ########################################################################################
' IShellItem2 interface
' IID = 7E9FB0D3-919F-4307-AB2E-9B1860310C93
' Inherited interface = IShellItem
' ########################################################################################

#IF NOT %DEF(%IShellItem2_INTERFACE_DEFINED)
    %IShellItem2_INTERFACE_DEFINED = 1

$IID_IShellItem2 = GUID$("{7E9FB0D3-919F-4307-AB2E-9B1860310C93}")

INTERFACE IShellItem2 $IID_IShellItem2

   INHERIT IUnknown

   ' =====================================================================================
   ' IShellItem Methods
   ' =====================================================================================
   METHOD BindToHandler ( _                             ' VTable offset = 12
     BYVAL pbc AS IBindCtx _                            ' __in IBindCtx *pbc
   , BYREF rbhid AS GUID _                              ' __in REFGUID rbhid
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppvOut AS IUnknown _                         ' __out void **ppvOut
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetParent ( _                                 ' VTable offset = 16
     BYREF ppsi AS IShellItem _                         ' __out IShellItem **ppsi
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDisplayName ( _                            ' VTable offset = 20
     BYVAL sigdnName AS DWORD _                         ' __in SIGDN sigdnName
   , BYREF ppszName AS DWORD _                          ' __out LPOLESTR *ppszName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAttributes ( _                             ' VTable offset = 24
     BYVAL sfgaoMask AS DWORD _                         ' __in SFGAOF sfgaoMask
   , BYREF psfgaoAttribs AS DWORD _                     ' __out SFGAOF *psfgaoAttribs
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Compare ( _                                   ' VTable offset = 28
     BYVAL psi AS IShellItem _                          ' __in IShellItem *psi
   , BYVAL hint AS DWORD _                              ' __in SICHINTF hint
   , BYREF piOrder AS LONG _                            ' __out int *piOrder
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IShellItem2 Methods
   ' =====================================================================================
   METHOD GetPropertyStore ( _                          ' VTable offset = 32
     BYVAL flags AS LONG _                              ' __in GETPROPERTYSTOREFLAGS flags
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppv AS IUnknown _                            ' __out void **ppv
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPropertyStoreWithCreateObject ( _          ' VTable offset = 36
     BYVAL flags AS LONG _                              ' __in GETPROPERTYSTOREFLAGS flags
   , BYVAL punkCreateObject AS IUnknown _               ' __in IUnknown *punkCreateObject
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppv AS IUnknown _                            ' __out void **ppv
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPropertyStoreForKeys ( _                   ' VTable offset = 40
     BYREF rgKeys AS PROPERTYKEY _                      ' __in const PROPERTYKEY *rgKeys
   , BYVAL cKeys AS DWORD _                             ' __in UINT cKeys
   , BYVAL flags AS LONG _                              ' __in GETPROPERTYSTOREFLAGS flags
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppv AS IUnknown _                            ' __out void **ppv
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPropertyDescriptionList ( _                ' VTable offset = 44
     BYREF keyType AS PROPERTYKEY _                     ' __in REFPROPERTYKEY keyType
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppv AS IUnknown _                            ' __out void **ppv
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Update ( _                                    ' VTable offset = 48
     BYVAL pbc AS IBindCtx _                            ' __in IBindCtx *pbc
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetProperty ( _                               ' VTable offset = 52
     BYREF key AS PROPERTYKEY _                         ' __in REFPROPERTYKEY key
   , BYREF ppropvar AS PROPVARIANT _                    ' __out PROPVARIANT *ppropvar
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCLSID ( _                                  ' VTable offset = 56
     BYREF key AS PROPERTYKEY _                         ' __in REFPROPERTYKEY key
   , BYREF pclsid AS GUID _                             ' __out CLSID *pclsid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFileTime ( _                               ' VTable offset = 60
     BYREF key AS PROPERTYKEY _                         ' __in REFPROPERTYKEY key
   , BYREF pft AS FILETIME _                            ' __out FILETIME *pft
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetInt32 ( _                                  ' VTable offset = 64
     BYREF key AS PROPERTYKEY _                         ' __in REFPROPERTYKEY key
   , BYREF pi AS LONG _                                 ' __out int *pi
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetString ( _                                 ' VTable offset = 68
     BYREF key AS PROPERTYKEY _                         ' __in REFPROPERTYKEY key
   , BYREF ppsz AS DWORD _                              ' __out LPWSTR *ppsz
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetUInt32 ( _                                 ' VTable offset = 72
     BYREF key AS PROPERTYKEY _                         ' __in REFPROPERTYKEY key
   , BYREF pui AS DWORD _                               ' __out ULONG *pui
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetUInt64 ( _                                 ' VTable offset = 76
     BYREF key AS PROPERTYKEY _                         ' __in REFPROPERTYKEY key
   , BYREF pull AS QUAD _                               ' __out ULONGLONG *pull
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetBool ( _                                   ' VTable offset = 80
     BYREF key AS PROPERTYKEY _                         ' __in REFPROPERTYKEY key
   , BYREF pf AS LONG _                                 ' __out BOOL *pf
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IShellItem2_INTERFACE_DEFINED__ */

' enum SIIGB
%SIIGBF_RESIZETOFIT   = 0
%SIIGBF_BIGGERSIZEOK  = &H1
%SIIGBF_MEMORYONLY    = &H2
%SIIGBF_ICONONLY      = &H4
%SIIGBF_THUMBNAILONLY = &H8
%SIIGBF_INCACHEONLY   = &H10

'typedef int SIIGBF;


' ########################################################################################
' IShellItemImageFactory interface
' IID = BCC18B79-BA16-442F-80C4-8A59C30C463B
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IShellItemImageFactory_INTERFACE_DEFINED)
    %IShellItemImageFactory_INTERFACE_DEFINED = 1

$IID_IShellItemImageFactory = GUID$("{BCC18B79-BA16-442F-80C4-8A59C30C463B}")

INTERFACE IShellItemImageFactory $IID_IShellItemImageFactory

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetImage ( _                                  ' VTable offset = 12
     BYVAL size AS SIZE _                               ' __in SIZE size
   , BYREF flags AS LONG _                              ' __in SIIGBF flags
   , BYREF phbm AS DWORD _                              ' __out HBITMAP *phbm
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IShellItemImageFactory_INTERFACE_DEFINED__ */


' ########################################################################################
' IUserAccountChangeCallback interface
' IID = A561E69A-B4B8-4113-91A5-64C6BCCA3430
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IUserAccountChangeCallback_INTERFACE_DEFINED)
   %IUserAccountChangeCallback_INTERFACE_DEFINED = 1

$IID_IUserAccountChangeCallback = GUID$("{A561E69A-B4B8-4113-91A5-64C6BCCA3430}")

INTERFACE IUserAccountChangeCallback $IID_IUserAccountChangeCallback

   INHERIT IUnknown

   ' =====================================================================================
   METHOD OnPictureChange ( _                           ' VTable offset = 12
     BYREF pszUserName AS WSTRINGZ _                    ' __in LPCWSTR pszUserName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IUserAccountChangeCallback_INTERFACE_DEFINED__ */


'#if (NTDDI_VERSION >= NTDDI_WINXP)

' ########################################################################################
' IEnumShellItems interface
' IID = 70629033-E363-4A28-A567-0DB78006E6D7
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IEnumShellItems_INTERFACE_DEFINED)
    %IEnumShellItems_INTERFACE_DEFINED = 1

$IID_IEnumShellItems = GUID$("{70629033-E363-4A28-A567-0DB78006E6D7}")

INTERFACE IEnumShellItems $IID_IEnumShellItems

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Next ( _                                      ' VTable offset = 12
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   , BYREF rgelt AS IShellItem _                        ' __out IShellItem **rgelt
   , BYREF pceltFetched AS DWORD _                      ' __out ULONG *pceltFetched
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Skip ( _                                      ' VTable offset = 16
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reset ( _                                     ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 24
     BYREF ppenum AS IEnumShellItems _                  ' __out IEnumShellItems **ppenum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEnumShellItems_INTERFACE_DEFINED__ */

' enum STGOP
%STGOP_MOVE            = 1
%STGOP_COPY            = 2
%STGOP_SYNC            = 3
%STGOP_REMOVE          = 5
%STGOP_RENAME          = 6
%STGOP_APPLYPROPERTIES = 8
%STGOP_NEW             = 10

'#endif  // NTDDI_WINXP

' enum TRANSFER_SOURCE_FLAGS
%TSF_NORMAL                      = &0???
%TSF_FAIL_EXIST                  = &0???         ' // Fail if destination already exists
%TSF_RENAME_EXIST                = &H1???        ' // Rename with auto-name generation if destination already exists
%TSF_OVERWRITE_EXIST             = &H2???        ' // Overwrite/Merge with destination
%TSF_ALLOW_DECRYPTION            = &H4???        ' // Allow creation of decrypted destination
%TSF_NO_SECURITY                 = &H8???        ' // Without DACL/SACL/Owner
%TSF_COPY_CREATION_TIME          = &H10???       ' // Copy the creation time as part of the copy (useful for move as copy/delete)
%TSF_COPY_WRITE_TIME             = &H20???       ' // Copy the last write time as part of the copy
%TSF_USE_FULL_ACCESS             = &H40???       ' // Open a file with write, read, or delete as share mode
%TSF_DELETE_RECYCLE_IF_POSSIBLE  = &H80???       ' // Recycle if possible
%TSF_COPY_HARD_LINK              = &H100???      ' // Hard link desired (not required)
%TSF_COPY_LOCALIZED_NAME         = &H200???      ' // Copy localized name
%TSF_MOVE_AS_COPY_DELETE         = &H400???      ' // We are doing a move operation, but we are doing it as a copy/delete
%TSF_SUSPEND_SHELLEVENTS         = &H800???      ' // suspend shell events

'typedef DWORD TRANSFER_SOURCE_FLAGS;

'#if (_WIN32_IE >= _WIN32_IE_IE70)

' ########################################################################################
' ITransferAdviseSink interface
' IID = D594D0D8-8DA7-457B-B3B4-CE5DBAAC0B88
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ITransferAdviseSink_INTERFACE_DEFINED)
    %ITransferAdviseSink_INTERFACE_DEFINED = 1

' enum TRANSFER_ADVISE_STATE
%TS_PERFORMING    = &H1???
%TS_PREPARING     = &H2???
%TS_INDETERMINATE = &H4???
'typedef DWORD TRANSFER_ADVISE_STATE;

$IID_ITransferAdviseSink = GUID$("{D594D0D8-8DA7-457B-B3B4-CE5DBAAC0B88}")

INTERFACE ITransferAdviseSink $IID_ITransferAdviseSink

   INHERIT IUnknown

   ' =====================================================================================
   METHOD UpdateProgress ( _                            ' VTable offset = 12
     BYVAL ullSizeCurrent AS QUAD _                     ' __in ULONGLONG ullSizeCurrent
   , BYVAL ullSizeTotal AS QUAD _                       ' __in ULONGLONG ullSizeTotal
   , BYVAL nFilesCurrent AS LONG _                      ' __in int nFilesCurrent
   , BYVAL nFilesTotal AS LONG _                        ' __in int nFilesTotal
   , BYVAL nFoldersCurrent AS LONG _                    ' __in int nFoldersCurrent
   , BYVAL nFoldersTotal AS LONG _                      ' __in int nFoldersTotal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UpdateTransferState ( _                       ' VTable offset = 16
     BYVAL ts AS DWORD _                                ' __in TRANSFER_ADVISE_STATE ts
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ConfirmOverwrite ( _                          ' VTable offset = 20
     BYVAL psiSource AS IShellItem _                    ' __in IShellItem *psiSource
   , BYVAL psiDestParent AS IShellItem _                ' __in IShellItem *psiDestParent
   , BYREF pszName AS WSTRINGZ _                        ' __in LPCWSTR pszName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ConfirmEncryptionLoss ( _                     ' VTable offset = 24
     BYVAL psiSource AS IShellItem _                    ' __in IShellItem *psiSource
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD FileFailure ( _                               ' VTable offset = 28
     BYVAL psi AS IShellItem _                          ' __in IShellItem *psi
   , BYREF pszItem AS WSTRINGZ _                        ' __in LPCWSTR pszItem
   , BYVAL hrError AS LONG _                            ' __in HRESULT hrError
   , BYREF pszRename AS WSTRINGZ _                      ' __out LPWSTR pszRename
   , BYVAL cchRename AS LONG _                          ' __in ULONG cchRename
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SubStreamFailure ( _                          ' VTable offset = 32
     BYVAL psi AS IShellItem _                          ' __in IShellItem *psi
   , BYREF pszStreamName AS WSTRINGZ _                  ' __in LPCWSTR pszStreamName
   , BYVAL hrError AS LONG _                            ' __in HRESULT hrError
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD PropertyFailure ( _                           ' VTable offset = 36
     BYVAL psi AS IShellItem _                          ' __in IShellItem *psi
   , BYREF pkey AS PROPERTYKEY _                        ' __in const PROPERTYKEY *pkey
   , BYVAL hrError AS LONG _                            ' __in HRESULT hrError
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITransferAdviseSink_INTERFACE_DEFINED__ */

'#endif  // (_WIN32_IE >= _WIN32_IE_IE70)

'#if (NTDDI_VERSION >= NTDDI_VISTA)

' ########################################################################################
' ITransferSource interface
' IID = 00ADB003-BDE9-45C6-8E29-D09F9353E108
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ITransferSource_INTERFACE_DEFINED)
    %ITransferSource_INTERFACE_DEFINED = 1

$IID_ITransferSource = GUID$("{00ADB003-BDE9-45C6-8E29-D09F9353E108}")

INTERFACE ITransferSource $IID_ITransferSource

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Advise ( _                                    ' VTable offset = 12
     BYVAL psink AS ITransferAdviseSink _               ' __in ITransferAdviseSink *psink
   , BYREF pdwCookie AS DWORD _                         ' __out DWORD *pdwCookie
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Unadvise ( _                                  ' VTable offset = 16
     BYVAL dwCookie AS DWORD _                          ' __in DWORD dwCookie
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetProperties ( _                             ' VTable offset = 20
     BYVAL pproparray AS IPropertyChangeArray _         ' __in IPropertyChangeArray *pproparray
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OpenItem ( _                                  ' VTable offset = 24
     BYVAL psi AS IShellItem _                          ' __in IShellItem *psi
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppv AS IUnknown _                            ' __out void **ppv
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD MoveItem ( _                                  ' VTable offset = 28
     BYVAL psi AS IShellItem _                          ' __in IShellItem *psi
   , BYVAL psiParentDst AS IUnknown _                   ' __in IShellItem *psiParentDst
   , BYREF pszNameDst AS WSTRINGZ _                     ' __in LPCWSTR pszNameDst
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYVAL ppsiNew AS IShellItem _                      ' __out IShellItem **ppsiNew
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RecycleItem ( _                               ' VTable offset = 32
     BYVAL psiSource AS IShellItem _                    ' __in IShellItem *psiSource
   , BYVAL psiParentDest AS IShellItem _                ' __in IShellItem *psiParentDest
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF ppsiNewDest AS IShellItem _                  ' __out IShellItem **ppsiNewDest
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RemoveItem ( _                                ' VTable offset = 36
     BYVAL psiSource AS IShellItem _                    ' __in IShellItem *psiSource
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RenameItem ( _                                ' VTable offset = 40
     BYVAL psiSource AS IShellItem _                    ' __in IShellItem *psiSource
   , BYREF pszNewName AS WSTRINGZ _                     ' __in LPCWSTR pszNewName
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF ppsiNewDest AS IShellItem _                  ' __out IShellItem **ppsiNewDest
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD LinkItem ( _                                  ' VTable offset = 44
     BYVAL psiSource AS IShellItem _                    ' __in IShellItem *psiSource
   , BYVAL psiParentDest AS IShellItem _                ' __in IShellItem *psiParentDest
   , BYREF pszNewName AS WSTRINGZ _                        ' __in LPCWSTR pszNewName
   , BYVAL dwLinkFlags AS DWORD _                       ' __in DWORD dwLinkFlags
   , BYREF ppsiNewDest AS IShellItem _                  ' __out IShellItem **ppsiNewDest
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ApplyPropertiesToItem ( _                     ' VTable offset = 48
     BYVAL psiSource AS IShellItem _                    ' __in IShellItem *psiSource
   , BYREF ppsiNew AS IUnknown _                        ' __out IShellItem **ppsiNew
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDefaultDestinationName ( _                 ' VTable offset = 52
     BYVAL psiSource AS IShellItem _                    ' __in IShellItem *psiSource
   , BYVAL psiParentDest AS IShellItem _                ' __in IShellItem *psiParentDest
   , BYREF ppszDestinationName AS DWORD _               ' __out LPWSTR *ppszDestinationName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnterFolder ( _                               ' VTable offset = 56
     BYVAL psiChildFolderDest AS IShellItem _           ' __in IShellItem *psiChildFolderDest
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD LeaveFolder ( _                               ' VTable offset = 60
     BYVAL psiChildFolderDest AS IShellItem _           ' __in IShellItem *psiChildFolderDest
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITransferSource_INTERFACE_DEFINED__ */

'#endif  // NTDDI_VISTA

' // size = 536 bytes
TYPE SHELL_ITEM_RESOURCE DWORD
   guidType AS GUID             ' GUID
   szName   AS WSTRINGZ * 260   ' WCHAR
END TYPE


' ########################################################################################
' IEnumResources interface
' IID = 2DD81FE3-A83C-4DA9-A330-47249D345BA1
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IEnumResources_INTERFACE_DEFINED)
    %IEnumResources_INTERFACE_DEFINED = 1

$IID_IEnumResources = GUID$("{2DD81FE3-A83C-4DA9-A330-47249D345BA1}")

INTERFACE IEnumResources $IID_IEnumResources

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Next ( _                                      ' VTable offset = 12
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   , BYREF psir AS SHELL_ITEM_RESOURCE _                ' __out SHELL_ITEM_RESOURCE *psir
   , BYREF pceltFetched AS DWORD _                      ' __out ULONG *pceltFetched
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Skip ( _                                      ' VTable offset = 16
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reset ( _                                     ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 24
     BYREF ppenumr AS IEnumResources _                  ' __out IEnumResources **ppenumr
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEnumResources_INTERFACE_DEFINED__ */


' ########################################################################################
' IShellItemResources interface
' IID = FF5693BE-2CE0-4D48-B5C5-40817D1ACDB9
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IShellItemResources_INTERFACE_DEFINED)
    %IShellItemResources_INTERFACE_DEFINED = 1

$IID_IShellItemResources = GUID$("{FF5693BE-2CE0-4D48-B5C5-40817D1ACDB9}")

INTERFACE IShellItemResources $IID_IShellItemResources

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetAttributes ( _                             ' VTable offset = 12
     BYREF pdwAttributes AS DWORD _                     ' __out DWORD *pdwAttributes
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSize ( _                                   ' VTable offset = 16
     BYREF pullSize AS QUAD _                           ' __out ULONGLONG *pullSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTimes ( _                                  ' VTable offset = 20
     BYREF pftCreation AS FILETIME _                    ' __out FILETIME *pftCreation
   , BYREF pftWrite AS FILETIME _                       ' __out FILETIME *pftWrite
   , BYREF pftAccess AS FILETIME _                      ' __out FILETIME *pftAccess
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetTimes ( _                                  ' VTable offset = 24
     BYREF pftCreation AS FILETIME _                    ' __in const FILETIME *pftCreation
   , BYREF pftWrite AS FILETIME _                       ' __in const FILETIME *pftWrite
   , BYREF pftAccess AS FILETIME _                      ' __in const FILETIME *pftAccess
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetResourceDescription ( _                    ' VTable offset = 28
     BYREF pcsir AS SHELL_ITEM_RESOURCE _               ' __in const SHELL_ITEM_RESOURCE *pcsir
   , BYREF ppszDescription AS DWORD _                   ' __out LPWSTR *ppszDescription
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumResources ( _                             ' VTable offset = 32
     BYREF ppenumr AS IEnumResources _                  ' __out IEnumResources **ppenumr
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SupportsResource ( _                          ' VTable offset = 36
     BYREF pcsir AS SHELL_ITEM_RESOURCE _               ' __in const SHELL_ITEM_RESOURCE *pcsir
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OpenResource ( _                              ' VTable offset = 40
     BYREF pcsir AS SHELL_ITEM_RESOURCE _               ' __in const SHELL_ITEM_RESOURCE *pcsir
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppv AS IUnknown _                            ' __out void **ppv
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateResource ( _                            ' VTable offset = 44
     BYREF pcsir AS SHELL_ITEM_RESOURCE _               ' __in const SHELL_ITEM_RESOURCE *pcsir
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppv AS IUnknown _                            ' __out void **ppv
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD MarkForDelete ( _                             ' VTable offset = 48
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IShellItemResources_INTERFACE_DEFINED__ */


' ########################################################################################
' ITransferDestination interface
' IID = 48ADDD32-3CA5-4124-ABE3-B5A72531B207
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ITransferDestination_INTERFACE_DEFINED)
    %ITransferDestination_INTERFACE_DEFINED = 1

$IID_ITransferDestination = GUID$("{48ADDD32-3CA5-4124-ABE3-B5A72531B207}")

INTERFACE ITransferDestination $IID_ITransferDestination

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Advise ( _                                    ' VTable offset = 12
     BYVAL psink AS ITransferAdviseSink _               ' __in ITransferAdviseSink *psink
   , BYREF pdwCookie AS DWORD _                         ' __out DWORD *pdwCookie
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Unadvise ( _                                  ' VTable offset = 16
     BYVAL dwCookie AS DWORD _                          ' __in DWORD dwCookie
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateItem ( _                                ' VTable offset = 20
     BYREF pszName AS WSTRINGZ _                        ' __in LPCWSTR pszName
   , BYVAL dwAttributes AS DWORD _                      ' __in DWORD dwAttributes
   , BYVAL ullSize AS QUAD _                            ' __in ULONGLONG ullSize
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF riidItem AS GUID _                           ' __in REFIID riidItem
   , BYREF ppvItem AS IUnknown _                        ' __out void **ppvItem
   , BYREF riidResources AS GUID _                      ' __in REFIID riidResources
   , BYREF ppvResources AS IUnknown _                   ' __out void **ppvResources
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITransferDestination_INTERFACE_DEFINED__ */


' ########################################################################################
' IStreamAsync interface
' IID = FE0B6665-E0CA-49B9-A178-2B5CB48D92A5
' Inherited interface = IStream
' ########################################################################################

#IF NOT %DEF(%IStreamAsync_INTERFACE_DEFINED)
    %IStreamAsync_INTERFACE_DEFINED = 1

$IID_IStreamAsync = GUID$("{FE0B6665-E0CA-49B9-A178-2B5CB48D92A5}")

INTERFACE IStreamAsync $IID_IStreamAsync

   INHERIT IUnknown

   ' =====================================================================================
   ' ISequentialStream Methods
   ' =====================================================================================
   METHOD Read ( _                                      ' VTable offset = 12
     BYVAL pv AS DWORD _                                ' __out void* pv
   , BYVAL cb AS DWORD _                                ' __in ULONG cb
   , BYREF pcbRead AS DWORD _                           ' __out ULONG *pcbRead
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Write ( _                                     ' VTable offset = 16
     BYVAL pv AS DWORD _                                ' __in void const* pv
   , BYVAL cb AS DWORD _                                ' __in ULONG cb
   , BYREF pcbWritten AS DWORD _                        ' __out ULONG *pcbWritten
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IStream Methods
   ' =====================================================================================
   METHOD Seek ( _                                      ' VTable offset = 20
     BYVAL dlibMove AS QUAD _                           ' __in LARGE_INTEGER dlibMove
   , BYVAL dwOrigin AS DWORD _                          ' __in DWORD dwOrigin
   , BYREF plibNewPosition AS QUAD _                    ' __out ULARGE_INTEGER* plibNewPosition
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetSize ( _                                   ' VTable offset = 24
     BYVAL libNewSize AS QUAD _                         ' __in ULARGE_INTEGER libNewSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CopyTo ( _                                    ' VTable offset = 28
     BYVAL pstm AS IStream _                            ' __in IStream* pstm
   , BYVAL cb AS QUAD _                                 ' __in ULARGE_INTEGER cb
   , BYREF pcbRead AS QUAD _                            ' __out ULARGE_INTEGER* pcbRead
   , BYREF pcbWritten AS QUAD _                         ' __out ULARGE_INTEGER* pcbWritten
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Commit ( _                                    ' VTable offset = 32
     BYVAL grfCommitFlags AS DWORD _                    ' __in DWORD grfCommitFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Revert ( _                                    ' VTable offset = 36
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD LockRegion ( _                                ' VTable offset = 40
     BYVAL libOffset AS QUAD _                          ' __in ULARGE_INTEGER libOffset
   , BYVAL cb AS QUAD _                                 ' __in ULARGE_INTEGER cb
   , BYVAL dwLockType AS DWORD _                        ' __in DWORD dwLockType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UnlockRegion ( _                              ' VTable offset = 44
     BYVAL libOffset AS QUAD _                          ' __in ULARGE_INTEGER libOffset
   , BYVAL cb AS QUAD _                                 ' __in ULARGE_INTEGER cb
   , BYVAL dwLockType AS DWORD _                        ' __in DWORD dwLockType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Stat ( _                                      ' VTable offset = 48
     BYREF pstatstg AS STATSTG _                        ' __out STATSTG* pstatstg
   , BYVAL grfStatFlag AS DWORD _                       ' __in DWORD grfStatFlag
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 52
     BYREF ppstm AS IStream _                           ' __out IStream** ppstm
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IStreamAsync Methods
   ' =====================================================================================
   METHOD ReadAsync ( _                                 ' VTable offset = 56
     BYVAL pv AS DWORD _                                ' __out void *pv
   , BYVAL cb AS DWORD _                                ' __in DWORD cb
   , BYREF pcbRead AS DWORD _                           ' __out LPDWORD pcbRead
   , BYREF lpOverlapped AS OVERLAPPED _                 ' __in LPOVERLAPPED lpOverlapped
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD WriteAsync ( _                                ' VTable offset = 60
     BYVAL lpBuffer AS DWORD _                          ' __in const void *lpBuffer
   , BYVAL cb AS DWORD _                                ' __in DWORD cb
   , BYREF pcbWritten AS DWORD _                        ' __out LPDWORD pcbWritten
   , BYREF lpOverlapped AS OVERLAPPED _                 ' __in LPOVERLAPPED lpOverlapped
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OverlappedResult ( _                          ' VTable offset = 64
     BYREF lpOverlapped AS OVERLAPPED _                 ' __in LPOVERLAPPED lpOverlapped
   , BYREF lpNumberOfBytesTransferred AS DWORD _        ' __out LPDWORD lpNumberOfBytesTransferred
   , BYVAL bWait AS LONG _                              ' __in BOOL bWait
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CancelIo ( _                                  ' VTable offset = 68
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IStreamAsync_INTERFACE_DEFINED__ */


' ########################################################################################
' IStreamUnbufferedInfo interface
' IID = 8A68FDDA-1FDC-4C20-8CEB-416643B5A625
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IStreamUnbufferedInfo_INTERFACE_DEFINED)
    %IStreamUnbufferedInfo_INTERFACE_DEFINED = 1

$IID_IStreamUnbufferedInfo = GUID$("{8A68FDDA-1FDC-4C20-8CEB-416643B5A625}")

INTERFACE IStreamUnbufferedInfo $IID_IStreamUnbufferedInfo

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetSectorSize ( _                             ' VTable offset = 12
     BYREF pcbSectorSize AS DWORD _                     ' __out ULONG *pcbSectorSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IStreamUnbufferedInfo_INTERFACE_DEFINED__ */


'#if (_WIN32_IE >= _WIN32_IE_IE70)

' ########################################################################################
' IFileOperationProgressSink interface
' IID = 04B0F1A7-9490-44BC-96E1-4296A31252E2
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IFileOperationProgressSink_INTERFACE_DEFINED)
    %IStreamUnbufferedInfo_INTERFACE_DEFINED = 1

$IID_IFileOperationProgressSink = GUID$("{04B0F1A7-9490-44BC-96E1-4296A31252E2}")

INTERFACE IFileOperationProgressSink $IID_IFileOperationProgressSink

   INHERIT IUnknown

   ' =====================================================================================
   METHOD StartOperations ( _                           ' VTable offset = 12
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD FinishOperations ( _                          ' VTable offset = 12
     BYVAL hrResult AS LONG _                           ' __in HRESULT hrResult
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD PreRenameItem ( _                             ' VTable offset = 16
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYVAL psiItem AS IShellItem _                      ' __in IShellItem *psiItem
   , BYREF pszNewName AS WSTRINGZ _                     ' __in LPCWSTR pszNewName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD PostRenameItem ( _                            ' VTable offset = 20
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYVAL psiItem AS IShellItem _                      ' __in IShellItem *psiItem
   , BYREF pszNewName AS WSTRINGZ _                     ' __in LPCWSTR pszNewName
   , BYVAL hrRename AS LONG _                           ' __in HRESULT hrRename
   , BYVAL psiNewlyCreated AS IShellItem _              ' __in IShellItem *psiNewlyCreated
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD PreMoveItem ( _                               ' VTable offset = 24
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYVAL psiItem AS IShellItem _                      ' __in IShellItem *psiItem
   , BYVAL psiDestinationFolder AS IShellItem _         ' __in IShellItem *psiDestinationFolder
   , BYREF pszNewName AS WSTRINGZ _                     ' __in LPCWSTR pszNewName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD PostMoveItem ( _                              ' VTable offset = 28
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYVAL psiItem AS IShellItem _                      ' __in IShellItem *psiItem
   , BYVAL psiDestinationFolder AS IShellItem _         ' __in IShellItem *psiDestinationFolder
   , BYREF pszNewName AS WSTRINGZ _                     ' __in LPCWSTR pszNewName
   , BYVAL hrMove AS LONG _                             ' __in HRESULT hrMove
   , BYVAL psiNewlyCreated AS IShellItem _              ' __in IShellItem *psiNewlyCreated
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD PreCopyItem ( _                               ' VTable offset = 32
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYVAL psiItem AS IShellItem _                      ' __in IShellItem *psiItem
   , BYVAL psiDestinationFolder AS IShellItem _         ' __in IShellItem *psiDestinationFolder
   , BYREF pszNewName AS WSTRINGZ _                     ' __in LPCWSTR pszNewName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD PostCopyItem ( _                              ' VTable offset = 36
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYVAL psiItem AS IShellItem _                      ' __in IShellItem *psiItem
   , BYVAL psiDestinationFolder AS IShellItem _         ' __in IShellItem *psiDestinationFolder
   , BYREF pszNewName AS WSTRINGZ _                     ' __in LPCWSTR pszNewName
   , BYVAL hrCopy AS LONG _                             ' __in HRESULT hrCopy
   , BYVAL psiNewlyCreated AS IShellItem _              ' __in IShellItem *psiNewlyCreated
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD PreDeleteItem ( _                             ' VTable offset = 40
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYVAL psiItem AS IShellItem _                      ' __in IShellItem *psiItem
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD PostDeleteItem ( _                            ' VTable offset = 44
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYVAL psiItem AS IShellItem _                      ' __in IShellItem *psiItem
   , BYVAL hrDelete AS LONG _                           ' __in HRESULT hrDelete
   , BYVAL psiNewlyCreated AS IShellItem _              ' __in IShellItem *psiNewlyCreated
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD PreNewItem ( _                                ' VTable offset = 48
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYVAL psiDestinationFolder AS IShellItem _         ' __in IShellItem *psiDestinationFolder
   , BYREF pszNewName AS WSTRINGZ _                     ' __in LPCWSTR pszNewName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD PostNewItem ( _                               ' VTable offset = 52
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYVAL psiDestinationFolder AS IShellItem _         ' __in IShellItem *psiDestinationFolder
   , BYREF pszNewName AS WSTRINGZ _                     ' __in LPCWSTR pszNewName
   , BYREF pszTemplateName AS WSTRINGZ _                ' __in LPCWSTR pszTemplateName
   , BYREF dwFileAttributes AS DWORD _                  ' __in DWORD dwFileAttributes
   , BYVAL hrNew AS LONG _                              ' __in HRESULT hrNew
   , BYVAL psiNewItem AS IShellItem _                   ' __in IShellItem *psiNewItem
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UpdateProgress ( _                            ' VTable offset = 56
     BYVAL iWorkTotal AS DWORD _                        ' __in UINT iWorkTotal
   , BYVAL iWorkSoFar AS DWORD _                        ' __in UINT iWorkSoFar
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ResetTimer ( _                                ' VTable offset = 60
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD PauseTimer ( _                                ' VTable offset = 64
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ResumeTimer ( _                               ' VTable offset = 68
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IFileOperationProgressSink_INTERFACE_DEFINED__ */

'#endif  // (_WIN32_IE >= _WIN32_IE_IE70)


' ########################################################################################
' IShellItemArray interface
' IID = B63EA76D-1F85-456F-A19C-48159EFA858B
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IShellItemArray_INTERFACE_DEFINED)
    %IShellItemArray_INTERFACE_DEFINED = 1

' enum SIATTRIBFLAGS
%SIATTRIBFLAGS_AND       = &H1???
%SIATTRIBFLAGS_OR        = &H2???
%SIATTRIBFLAGS_APPCOMPAT = &H3???
%SIATTRIBFLAGS_MASK      = &H3???
%SIATTRIBFLAGS_ALLITEMS  = &H4000???

$IID_IShellItemArray = GUID$("{B63EA76D-1F85-456F-A19C-48159EFA858B}")

INTERFACE IShellItemArray $IID_IShellItemArray

   INHERIT IUnknown

   ' =====================================================================================
   METHOD BindToHandler ( _                             ' VTable offset = 12
     BYVAL pbc AS IBindCtx _                            ' __in IBindCtx *pbc
   , BYREF rbhid AS GUID _                              ' __in REFGUID rbhid
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppvOut AS IUnknown _                         ' __out void **ppvOut
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPropertyStore ( _                          ' VTable offset = 16
     BYVAL flags AS DWORD _                             ' __in GETPROPERTYSTOREFLAGS flags
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppv AS IUnknown _                            ' __out void **ppv
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPropertyDescriptionList ( _                ' VTable offset = 20
     BYREF keyType AS PROPERTYKEY _                     ' __in REFPROPERTYKEY keyType
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppv AS IUnknown _                            ' __out void **ppv
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAttributes ( _                             ' VTable offset = 24
     BYVAL dwAttribFlags AS DWORD _                     ' __in SIATTRIBFLAGS dwAttribFlags
   , BYVAL sfgaoMask AS DWORD _                         ' __in SFGAOF sfgaoMask
   , BYREF psfgaoAttribs AS DWORD _                     ' __out SFGAOF *psfgaoAttribs
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCount ( _                                  ' VTable offset = 28
     BYREF pdwNumItems AS DWORD _                       ' __out DWORD *pdwNumItems
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetItemAt ( _                                 ' VTable offset = 32
     BYVAL dwIndex AS DWORD _                           ' __in DWORD dwIndex
   , BYREF ppsi AS IShellItem _                         ' __out IShellItem **ppsi
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumItems ( _                                 ' VTable offset = 36
     BYREF ppenumShellItems AS DWORD _                  ' __out IEnumShellItems **ppenumShellItems
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IShellItemArray_INTERFACE_DEFINED__ */

'#if (_WIN32_IE >= _WIN32_IE_IE70)
DECLARE FUNCTION SHCreateShellItemArray IMPORT "SHELL32.DLL" ALIAS "SHCreateShellItemArray" ( _
   BYVAL pidlParent AS DWORD _                          ' __in_opt PCIDLIST_ABSOLUTE pidlParent
 , BYVAL psf AS IShellFolder _                          ' __in_opt IShellFolder *psf
 , BYVAL cidl AS DWORD _                                ' __in UINT cidl
 , BYREF ppidl AS DWORD _                               ' __in PCUITEMID_CHILD_ARRAY ppidl
 , BYREF ppsiItemArray AS IShellItemArray _             ' __out IShellItemArray **ppsiItemArray
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION SHCreateShellItemArrayFromDataObject IMPORT "SHELL32.DLL" ALIAS "SHCreateShellItemArrayFromDataObject" ( _
   BYVAL pdo AS IDataObject _                           ' __in IDataObject *pdo
 , BYREF riid AS GUID _                                 ' __in REFIID riid
 , BYREF ppv AS IUnknown _                              ' __out void **ppv
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION SHCreateShellItemArrayFromIDLists IMPORT "SHELL32.DLL" ALIAS "SHCreateShellItemArrayFromIDLists" ( _
   BYVAL cidl AS DWORD _                                ' __in UINT cidl
 , BYREF rgpidl AS DWORD _                              ' __in PCIDLIST_ABSOLUTE_ARRAY rgpidl
 , BYREF ppsiItemArray AS IShellItemArray _             ' __out IShellItemArray **ppsiItemArray
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION SHCreateShellItemArrayFromShellItem IMPORT "SHELL32.DLL" ALIAS "SHCreateShellItemArrayFromShellItem" ( _
   BYVAL psi AS IShellItem _                            ' __in IShellItem *psi
 , BYREF riid AS GUID _                                 ' __in REFIID riid
 , BYREF ppv AS IUnknown _                              ' __out void **ppv
 ) AS LONG                                              ' HRESULT
'#endif  // (_WIN32_IE >= _WIN32_IE_IE70)

' ########################################################################################
' IInitializeWithItem interface
' IID = 7F73BE3F-FB79-493C-A6C7-7EE14E245841
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IInitializeWithItem_INTERFACE_DEFINED)
    %IInitializeWithItem_INTERFACE_DEFINED = 1

$IID_IInitializeWithItem = GUID$("{7F73BE3F-FB79-493C-A6C7-7EE14E245841}")

INTERFACE IInitializeWithItem $IID_IInitializeWithItem

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Initialize ( _                                ' VTable offset = 12
     BYVAL psi AS IShellItem _                          ' __in IShellItem *psi
   , BYVAL grfMode AS DWORD _                           ' __in DWORD grfMode
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IInitializeWithItem_INTERFACE_DEFINED__ */

' ########################################################################################
' IObjectWithSelection interface
' IID = 1C9CD5BB-98E9-4491-A60F-31AACC72B83C
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IObjectWithSelection_INTERFACE_DEFINED)
    %IObjectWithSelection_INTERFACE_DEFINED = 1

$IID_IObjectWithSelection = GUID$("{1C9CD5BB-98E9-4491-A60F-31AACC72B83C}")

INTERFACE IObjectWithSelection $IID_IObjectWithSelection

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetSelection ( _                              ' VTable offset = 12
     BYVAL psia AS IShellItemArray _                    ' __in_opt IShellItemArray *psia
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSelection ( _                              ' VTable offset = 16
     BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppv AS IUnknown _                            ' __out_opt void **ppv
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IObjectWithSelection_INTERFACE_DEFINED__ */


' ########################################################################################
' IObjectWithBackReferences interface
' IID = 321A6A6A-D61F-4BF3-97AE-14BE2986BB36
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IObjectWithBackReferences_INTERFACE_DEFINED)
    %IObjectWithBackReferences_INTERFACE_DEFINED = 1

$IID_IObjectWithBackReferences = GUID$("{321A6A6A-D61F-4BF3-97AE-14BE2986BB36}")

INTERFACE IObjectWithBackReferences $IID_IObjectWithBackReferences

   INHERIT IUnknown

   ' =====================================================================================
   METHOD RemoveBackReferences ( _                      ' VTable offset = 12
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IObjectWithBackReferences_INTERFACE_DEFINED__ */


' PROPERTYUI_NAME_FLAGS enum
%PUIFNF_DEFAULT  = 0???
%PUIFNF_MNEMONIC = &H1???
'typedef DWORD PROPERTYUI_NAME_FLAGS;

' PROPERTYUI_FLAGS enum
%PUIF_DEFAULT          = 0???
%PUIF_RIGHTALIGN       = &H1???
%PUIF_NOLABELININFOTIP = &H2???
'typedef DWORD PROPERTYUI_FLAGS;

' PROPERTYUI_FORMAT_FLAGS enum
%PUIFFDF_DEFAULT      = 0???
%PUIFFDF_RIGHTTOLEFT  = &H1???
%PUIFFDF_SHORTFORMAT  = &H2???
%PUIFFDF_NOTIME       = &H4???
%PUIFFDF_FRIENDLYDATE = &H8???
'%PUIFFDF_NOUNITS      = &H10???   '  Removed from the Vista SDK
'typedef DWORD PROPERTYUI_FORMAT_FLAGS;


' ########################################################################################
' IPropertyUI interface
' IID = 757A7D9F-919A-4118-99D7-DBB208C8CC66
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IPropertyUI_INTERFACE_DEFINED)
    %IPropertyUI_INTERFACE_DEFINED = 1

$IID_IPropertyUI = GUID$("{757A7D9F-919A-4118-99D7-DBB208C8CC66}")

INTERFACE IPropertyUI $IID_IPropertyUI

   INHERIT IUnknown

   ' =====================================================================================
   METHOD ParsePropertyName ( _                         ' VTable offset = 12
     BYREF pszName AS WSTRINGZ _                        ' __in LPCWSTR pszName
   , BYREF pfmtid AS GUID _                             ' __out FMTID *pfmtid
   , BYREF ppid AS DWORD _                              ' __out PROPID *ppid
   , BYREF pchEaten AS DWORD _                          ' __inout ULONG *pchEaten
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCannonicalName ( _                         ' VTable offset = 16
     BYREF fmtid AS GUID _                              ' __in REFFMTID fmtid
   , BYVAL pid AS DWORD _                               ' __in PROPID pid
   , BYREF pwszText AS WSTRINGZ _                       ' __out LPWSTR pwszText
   , BYVAL cchText AS DWORD _                           ' __in DWORD cchText
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDisplayName ( _                            ' VTable offset = 20
     BYREF fmtid AS GUID _                              ' __in REFFMTID fmtid
   , BYVAL pid AS DWORD _                               ' __in PROPID pid
   , BYVAL flags AS DWORD _                             ' __in PROPERTYUI_NAME_FLAGS flags
   , BYREF pwszText AS WSTRINGZ _                       ' __out LPWSTR pwszText
   , BYVAL cchText AS DWORD _                           ' __in DWORD cchText
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPropertyDescription ( _                    ' VTable offset = 24
     BYREF fmtid AS GUID _                              ' __in REFFMTID fmtid
   , BYVAL pid AS DWORD _                               ' __in PROPID pid
   , BYREF pwszText AS WSTRINGZ _                       ' __out LPWSTR pwszText
   , BYVAL cchText AS DWORD _                           ' __in DWORD cchText
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDefaultWidth ( _                           ' VTable offset = 28
     BYREF fmtid AS GUID _                              ' __in REFFMTID fmtid
   , BYVAL pid AS DWORD _                               ' __in PROPID pid
   , BYREF pcxChars AS DWORD _                          ' __out ULONG *pcxChars
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFlags ( _                                  ' VTable offset = 32
     BYREF fmtid AS GUID _                              ' __in REFFMTID fmtid
   , BYVAL pid AS DWORD _                               ' __in PROPID pid
   , BYVAL pFlags AS DWORD _                            ' __out PROPERTYUI_FLAGS *pFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD FormatForDisplay ( _                          ' VTable offset = 36
     BYREF fmtid AS GUID _                              ' __in REFFMTID fmtid
   , BYVAL pid AS DWORD _                               ' __in PROPID pid
   , BYREF pvar AS PROPVARIANT _                        ' __in const PROPVARIANT *pvar
   , BYVAL flags AS DWORD _                             ' __in PROPERTYUI_FORMAT_FLAGS flags
   , BYREF pwszText AS WSTRINGZ _                       ' __out LPWSTR pwszText
   , BYVAL cchText AS DWORD _                           ' __in DWORD cchText
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetHelpInfo ( _                               ' VTable offset = 40
     BYREF fmtid AS GUID _                              ' __in REFFMTID fmtid
   , BYVAL pid AS DWORD _                               ' __in PROPID pid
   , BYREF pwszHelpFile AS WSTRINGZ _                   ' __out LPWSTR pwszHelpFile
   , BYVAL cch AS DWORD _                               ' __in DWORD cch
   , BYREF puHelpID AS DWORD _                          ' __out UINT *puHelpID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IPropertyUI_INTERFACE_DEFINED__ */

'#if (_WIN32_IE >= _WIN32_IE_IE70)
DECLARE FUNCTION SHRemovePersonalPropertyValues IMPORT "SHELL32.DLL" ALIAS "SHRemovePersonalPropertyValues" ( _
   BYVAL psia AS IShellItemArray _                      ' __in IShellItemArray *psia
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION SHAddDefaultPropertiesByExt IMPORT "SHELL32.DLL" ALIAS "SHAddDefaultPropertiesByExt" ( _
   BYREF pszExt AS WSTRINGZ _                           ' __in PCWSTR pszExt
 , BYVAL pPropStore AS IPropertyStore _                 ' __in IPropertyStore *pPropStore
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION SHCreateDefaultPropertiesOp IMPORT "SHELL32.DLL" ALIAS "SHCreateDefaultPropertiesOp" ( _
   BYVAL psi AS IShellItem _                            ' __in IShellItem *psi
 , BYREF ppFileOp AS IFileOperation _                   ' __out IFileOperation **ppFileOp
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION SHSetDefaultProperties IMPORT "SHELL32.DLL" ALIAS "SHSetDefaultProperties" ( _
   BYVAL hwndParent AS DWORD _                          ' __in_opt HWND hwndParent
 , BYVAL psi AS IShellItem _                            ' __in IShellItem *psi
 , BYVAL dwFileOpFlags AS DWORD _                       ' __in DWORD dwFileOpFlags
 , BYVAL pfops AS IFileOperationProgressSink _          ' __in_opt IFileOperationProgressSink *pfops
 ) AS LONG                                              ' HRESULT

'#endif  // (_WIN32_IE >= _WIN32_IE_IE70)

'#if (_WIN32_IE >= 0x0500)

' ########################################################################################
' ICategoryProvider interface
' IID = 9AF64809-5864-4C26-A720-C1F78C086EE3
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ICategoryProvider_INTERFACE_DEFINED)
    %ICategoryProvider_INTERFACE_DEFINED = 1

$IID_ICategoryProvider = GUID$("{9AF64809-5864-4C26-A720-C1F78C086EE3}")

INTERFACE ICategoryProvider $IID_ICategoryProvider

   INHERIT IUnknown

   ' =====================================================================================
   METHOD CanCategorizeOnSCID ( _                       ' VTable offset = 12
     BYREF pscid AS SHCOLUMNID _                        ' __in SHCOLUMNID *pscid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDefaultCategory ( _                        ' VTable offset = 16
     BYREF pguid AS GUID _                              ' __in GUID *pguid
   , BYREF pscid AS SHCOLUMNID _                        ' __in SHCOLUMNID *pscid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCategoryForSCID ( _                        ' VTable offset = 20
     BYREF pscid AS SHCOLUMNID _                        ' __in SHCOLUMNID *pscid
   , BYREF pguid AS GUID _                              ' __in GUID *pguid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumCategories ( _                            ' VTable offset = 24
     BYREF penum AS IEnumGUID _                         ' __out IEnumGUID **penum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCategoryName ( _                           ' VTable offset = 28
     BYREF pguid AS GUID _                              ' __in GUID *pguid
   , BYREF pszName AS WSTRINGZ _                        ' __out LPWSTR pszName
   , BYREF cch AS DWORD _                               ' __out UINT cch
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateCategory ( _                            ' VTable offset = 32
     BYREF pguid AS GUID _                              ' __in GUID *pguid
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppv AS IUnknown _                            ' __out void **ppv
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICategoryProvider_INTERFACE_DEFINED__ */

' CATEGORYINFO_FLAGS enum
%CATINFO_NORMAL         = 0???
%CATINFO_COLLAPSED      = &H1???
%CATINFO_HIDDEN         = &H2???
%CATINFO_EXPANDED       = &H4???
%CATINFO_NOHEADER       = &H8???
%CATINFO_NOTCOLLAPSIBLE = &H10???
%CATINFO_NOHEADERCOUNT  = &H20???
%CATINFO_SUBSETTED      = &H40???

' CATSORT_FLAGS enum
%CATSORT_DEFAULT = 0???
%CATSORT_NAME    = &H1???

' // Size = 524 bytes
TYPE CATEGORY_INFO DWORD
   cif     AS LONG             ' CATEGORYINFO_FLAGS cif
   wszName AS WSTRINGZ * 260   ' WCHAR wszName[ 260 ]
END TYPE

' ########################################################################################
' ICategorizer interface
' IID = A3B14589-9174-49A8-89A3-06A1AE2B9BA7
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ICategorizer_INTERFACE_DEFINED)
    %ICategorizer_INTERFACE_DEFINED = 1

$IID_ICategorizer = GUID$("{A3B14589-9174-49A8-89A3-06A1AE2B9BA7}")

INTERFACE ICategorizer $IID_ICategorizer

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetDescription ( _                            ' VTable offset = 12
     BYREF pszDesc AS WSTRINGZ _                        ' __in LPWSTR pszDesc
   , BYVAL cch AS DWORD _                               ' __in UINT cch
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCategory ( _                               ' VTable offset = 16
     BYVAL cidl AS DWORD _                              ' __in UINT cidl
   , BYVAL apidl AS DWORD _                             ' __in LPCITEMIDLIST *apidl
   , BYREF rgCategoryIds AS DWORD _                     ' __inout DWORD *rgCategoryIds
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCategoryInfo ( _                           ' VTable offset = 20
     BYVAL dwCategoryId AS DWORD _                      ' __in DWORD dwCategoryId
   , BYREF pci AS CATEGORY_INFO _                       ' __out CATEGORY_INFO *pci
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CompareCategory ( _                           ' VTable offset = 24
     BYVAL csfFlags AS DWORD _                          ' __in CATSORT_FLAGS csfFlags
   , BYVAL dwCategoryId1 AS DWORD _                     ' __in DWORD dwCategoryId1
   , BYVAL dwCategoryId2 AS DWORD _                     ' __in DWORD dwCategoryId2
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICategorizer_INTERFACE_DEFINED__ */

'#endif // (_WIN32_IE >= 0x0500)

'#if (NTDDI_VERSION >= NTDDI_WIN2K)
'#include <pshpack8.h>

' // Size = 24 bytes
TYPE SHDRAGIMAGE DWORD
   sizeDragImage AS SIZEL   ' SIZE     sizeDragImage  // OUT - The length and Width of the rendered image
   ptOffset      AS POINT   ' POINT    ptOffset       // OUT - The Offset from the mouse cursor to the upper left corner of the image
   hbmpDragImage AS DWORD   ' HBITMAP  hbmpDragImage  // OUT - The Bitmap containing the rendered drag images
   crColorKey    AS DWORD   ' COLORREF crColorKey     // OUT - The COLORREF that has been blitted to the background of the images
END TYPE

'#include <poppack.h> // Return to byte packing
'#define DI_GETDRAGIMAGE     TEXT("ShellGetDragImage")
$DI_GETDRAGIMAGE = "ShellGetDragImage"

' ########################################################################################
' IDropTargetHelper interface
' IID = 4657278B-411B-11D2-839A-00C04FD918D0
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDropTargetHelper_INTERFACE_DEFINED)
    %IDropTargetHelper_INTERFACE_DEFINED = 1

$IID_IDropTargetHelper = GUID$("{4657278B-411B-11D2-839A-00C04FD918D0}")

INTERFACE IDropTargetHelper $IID_IDropTargetHelper

   INHERIT IUnknown

   ' =====================================================================================
   METHOD DragEnter ( _                                 ' VTable offset = 12
     BYVAL hwndTarget AS DWORD _                        ' __in HWND hwndTarget
   , BYVAL pDataObject AS IDataObject _                 ' __in IDataObject* pDataObject
   , BYREF pt AS POINT _                                ' __in POINT* ppt
   , BYVAL dwEffect AS DWORD _                          ' __in DWORD dwEffect
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DragLeave ( _                                 ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DragOver ( _                                  ' VTable offset = 20
     BYREF ppt AS POINT _                               ' __in POINT* ppt
   , BYVAL dwEffect AS DWORD _                          ' __in DWORD dwEffect
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Drop ( _                                      ' VTable offset = 24
     BYVAL pDataObject AS IDataObject _                 ' __in IDataObject* pDataObject
   , BYREF ppt AS POINT _                               ' __in POINT* ppt
   , BYVAL dwEffect AS DWORD _                          ' __in DWORD dwEffect
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Show ( _                                      ' VTable offset = 28
     BYVAL fShow AS LONG _                              ' __in BOOL fShow
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDropTargetHelper_INTERFACE_DEFINED__ */


' ########################################################################################
' IDragSourceHelper interface
' IID = DE5BF786-477A-11D2-839D-00C04FD918D0
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDragSourceHelper_INTERFACE_DEFINED)
    %IDragSourceHelper_INTERFACE_DEFINED = 1

$IID_IDragSourceHelper = GUID$("{DE5BF786-477A-11D2-839D-00C04FD918D0}")

INTERFACE IDragSourceHelper $IID_IDragSourceHelper

   INHERIT IUnknown

   ' =====================================================================================
   METHOD InitializeFromBitmap ( _                      ' VTable offset = 12
     BYREF pshdi AS SHDRAGIMAGE _                       ' __in LPSHDRAGIMAGE pshdi
   , BYVAL pDataObject AS IDataObject _                 ' __in IDataObject* pDataObject
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD InitializeFromWindow ( _                      ' VTable offset = 16
     BYVAL hwnd AS DWORD _                              ' __in HWND hwnd
   , BYREF ppt AS POINT _                               ' __in POINT* ppt
   , BYVAL pDataObject AS IDataObject _                 ' __in IDataObject* pDataObject
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDragSourceHelper_INTERFACE_DEFINED__ */

'#if (NTDDI_VERSION >= NTDDI_VISTA)

' enum DSH_FLAGS
%DSH_ALLOWDROPDESCRIPTIONTEXT = &H1???


' ########################################################################################
' IDragSourceHelper2 interface
' IID = 83E07D0D-0C5F-4163-BF1A-60B274051E40
' Inherited interface = IDragSourceHelper
' ########################################################################################

#IF NOT %DEF(%IDragSourceHelper2_INTERFACE_DEFINED)
    %IDragSourceHelper_INTERFACE_DEFINED = 1

$IID_IDragSourceHelper2 = GUID$("{83E07D0D-0C5F-4163-BF1A-60B274051E40}")

INTERFACE IDragSourceHelper2 $IID_IDragSourceHelper2

   INHERIT IUnknown

   ' =====================================================================================
   ' IDragSourceHelper Methods
   ' =====================================================================================
   METHOD InitializeFromBitmap ( _                      ' VTable offset = 12
     BYREF pshdi AS SHDRAGIMAGE _                       ' __in LPSHDRAGIMAGE pshdi
   , BYVAL pDataObject AS IDataObject _                 ' __in IDataObject* pDataObject
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD InitializeFromWindow ( _                      ' VTable offset = 16
     BYVAL hwnd AS DWORD _                              ' __in HWND hwnd
   , BYREF ppt AS POINT _                               ' __in POINT* ppt
   , BYVAL pDataObject AS IDataObject _                 ' __in IDataObject* pDataObject
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IDragSourceHelper2 Methods
   ' =====================================================================================
   METHOD SetFlags ( _                                  ' VTable offset = 20
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDragSourceHelper2_INTERFACE_DEFINED__ */

'#endif  // NTDDI_VISTA
'#endif  // NTDDI_WIN2K

' SLR_FLAGS enum
%SLR_NO_UI                     = &H1???
%SLR_ANY_MATCH                 = &H2???
%SLR_UPDATE                    = &H4???
%SLR_NOUPDATE                  = &H8???
%SLR_NOSEARCH                  = &H10???
%SLR_NOTRACK                   = &H20???
%SLR_NOLINKINFO                = &H40???
%SLR_INVOKE_MSI                = &H80???
%SLR_NO_UI_WITH_MSG_PUMP       = &H101???
%SLR_OFFER_DELETE_WITHOUT_FILE = &H200???
%SLR_KNOWNFOLDER               = &H400???
%SLR_MACHINE_IN_LOCAL_TARGET   = &H800???
%SLR_UPDATE_MACHINE_AND_SID    = &H1000???

' SLGP_FLAGS enum
%SLGP_SHORTPATH          = &H1???
%SLGP_UNCPRIORITY        = &H2???
%SLGP_RAWPATH            = &H4???
%SLGP_RELATIVEPRIORITY   = &H8???


' ########################################################################################
' IShellLink interface
' IID = 000214EE-0000-0000-C000-000000000046
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IShellLinkA_INTERFACE_DEFINED)
    %IShellLinkA_INTERFACE_DEFINED = 1

$IID_IShellLinkA = GUID$("{000214EE-0000-0000-C000-000000000046}")
$IID_IShellLink  = GUID$("{000214EE-0000-0000-C000-000000000046}")

INTERFACE IShellLink $IID_IShellLink

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetPath ( _                                   ' VTable offset = 12
     BYREF pszFile AS ASCIIZ _                          ' __out LPSTR pszFile
   , BYVAL cch AS LONG _                                ' __in int cch
   , BYREF pfd AS WIN32_FIND_DATAA _                    ' __inout WIN32_FIND_DATAA *pfd
   , BYVAL fFlags AS DWORD _                            ' __in DWORD fFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetIDList ( _                                 ' VTable offset = 16
     BYREF ppidl AS DWORD _                             ' __out LPITEMIDLIST *ppidl
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetIDList ( _                                 ' VTable offset = 20
     BYVAL pidl AS DWORD _                              ' __in LPCITEMIDLIST pidl
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDescription ( _                            ' VTable offset = 24
     BYREF pszName AS ASCIIZ _                          ' __out LPSTR pszName
   , BYVAL cch AS LONG _                                ' __in int cch
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetDescription ( _                            ' VTable offset = 28
     BYREF pszName AS ASCIIZ _                          ' __in LPCSTR pszName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetWorkingDirectory ( _                       ' VTable offset = 32
     BYREF pszDir AS ASCIIZ _                           ' __out LPSTR pszDir
   , BYVAL cch AS LONG _                                ' __in int cch
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetWorkingDirectory ( _                       ' VTable offset = 36
     BYREF pszDir AS ASCIIZ _                           ' __in LPCSTR pszDir
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetArguments ( _                              ' VTable offset = 40
     BYREF pszArgs AS ASCIIZ _                          ' __out LPSTR pszArgs
   , BYVAL cch AS LONG _                                ' __in int cch
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetArguments ( _                              ' VTable offset = 44
     BYREF pszArgs AS ASCIIZ _                          ' __in LPCSTR pszArgs
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetHotkey ( _                                 ' VTable offset = 48
     BYREF pwHotkey AS WORD _                           ' __out WORD *pwHotkey
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetHotkey ( _                                 ' VTable offset = 52
     BYVAL wHotkey AS WORD _                            ' __in WORD wHotkey
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetShowCmd ( _                                ' VTable offset = 56
     BYREF piShowCmd AS LONG _                          ' __out int *piShowCmd
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetShowCmd ( _                                ' VTable offset = 60
     BYVAL iShowCmd AS LONG _                           ' __in int iShowCmd
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetIconLocation ( _                           ' VTable offset = 64
     BYREF pszIconPath AS ASCIIZ _                      ' __out LPSTR pszIconPath
   , BYVAL cch AS LONG _                                ' __in int cch
   , BYREF piIcon AS LONG _                             ' __out int *piIcon
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetIconLocation ( _                           ' VTable offset = 68
     BYREF pszIconPath AS ASCIIZ _                      ' __in LPCSTR pszIconPath
   , BYVAL iIcon AS LONG _                              ' __in int iIcon
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetRelativePath ( _                           ' VTable offset = 72
     BYREF pszPathRel AS ASCIIZ _                       ' __in LPCSTR pszPathRel
   , BYVAL dwReserved AS DWORD _                        ' __in DWORD dwReserved
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Resolve ( _                                   ' VTable offset = 76
     BYVAL hwnd AS DWORD _                              ' __in HWND hwnd
   , BYVAL fFlags AS DWORD _                            ' __in DWORD fFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPath ( _                                   ' VTable offset = 80
     BYREF pszFile AS ASCIIZ _                          ' __in LPCSTR pszFile
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IShellLinkA_INTERFACE_DEFINED__ */


' ########################################################################################
' IShellLinkW interface
' IID = 000214F9-0000-0000-C000-000000000046
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IShellLinkW_INTERFACE_DEFINED)
    %IShellLinkW_INTERFACE_DEFINED = 1

$IID_IShellLinkW = GUID$("{000214F9-0000-0000-C000-000000000046}")

INTERFACE IShellLinkW $IID_IShellLinkW

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetPath ( _                                   ' VTable offset = 12
     BYREF pszFile AS WSTRINGZ _                        ' __out LPWSTR pszFile
   , BYVAL cch AS LONG _                                ' __in int cch
   , BYREF pfd AS WIN32_FIND_DATAW _                    ' __inout WIN32_FIND_DATAA *pfd
   , BYVAL fFlags AS DWORD _                            ' __in DWORD fFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetIDList ( _                                 ' VTable offset = 16
     BYREF ppidl AS DWORD _                             ' __out LPITEMIDLIST *ppidl
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetIDList ( _                                 ' VTable offset = 20
     BYVAL pidl AS DWORD _                              ' __in LPCITEMIDLIST pidl
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDescription ( _                            ' VTable offset = 24
     BYREF pszName AS WSTRINGZ _                        ' __out LPWSTR pszName
   , BYVAL cch AS LONG _                                ' __in int cch
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetDescription ( _                            ' VTable offset = 28
     BYREF pszName AS WSTRINGZ _                        ' __in LPCWSTR pszName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetWorkingDirectory ( _                       ' VTable offset = 32
     BYREF pszDir AS WSTRINGZ _                         ' __out LPWSTR pszDir
   , BYVAL cch AS LONG _                                ' __in int cch
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetWorkingDirectory ( _                       ' VTable offset = 36
     BYREF pszDir AS WSTRINGZ _                         ' __in LPCWSTR pszDir
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetArguments ( _                              ' VTable offset = 40
     BYREF pszArgs AS WSTRINGZ _                        ' __out LPWSTR pszArgs
   , BYVAL cch AS LONG _                                ' __in int cch
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetArguments ( _                              ' VTable offset = 44
     BYREF pszArgs AS WSTRINGZ _                        ' __in LPCWSTR pszArgs
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetHotkey ( _                                 ' VTable offset = 48
     BYREF pwHotkey AS WORD _                           ' __out WORD *pwHotkey
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetHotkey ( _                                 ' VTable offset = 52
     BYVAL wHotkey AS WORD _                            ' __in WORD wHotkey
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetShowCmd ( _                                ' VTable offset = 56
     BYREF piShowCmd AS LONG _                          ' __out int *piShowCmd
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetShowCmd ( _                                ' VTable offset = 60
     BYVAL iShowCmd AS LONG _                           ' __in int iShowCmd
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetIconLocation ( _                           ' VTable offset = 64
     BYREF pszIconPath AS WSTRINGZ _                    ' __out LPWSTR pszIconPath
   , BYVAL cch AS LONG _                                ' __in int cch
   , BYREF piIcon AS LONG _                             ' __out int *piIcon
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetIconLocation ( _                           ' VTable offset = 68
     BYREF pszIconPath AS WSTRINGZ _                    ' __in LPCWSTR pszIconPath
   , BYVAL iIcon AS LONG _                              ' __in int iIcon
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetRelativePath ( _                           ' VTable offset = 72
     BYREF pszPathRel AS WSTRINGZ _                     ' __in LPCWSTR pszPathRel
   , BYVAL dwReserved AS DWORD _                        ' __in DWORD dwReserved
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Resolve ( _                                   ' VTable offset = 76
     BYVAL hwnd AS DWORD _                              ' __in HWND hwnd
   , BYVAL fFlags AS DWORD _                            ' __in DWORD fFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPath ( _                                   ' VTable offset = 80
     BYREF pszFile AS WSTRINGZ _                        ' __in LPCWSTR pszFile
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IShellLinkW_INTERFACE_DEFINED__ */


' ########################################################################################
' IShellLinkDataList interface
' IID = 45E2B4AE-B1C3-11D0-B92F-00A0C90312E1
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IShellLinkDataList_INTERFACE_DEFINED)
    %IShellLinkDataList_INTERFACE_DEFINED = 1

$IID_IShellLinkDataList = GUID$("{45E2B4AE-B1C3-11D0-B92F-00A0C90312E1}")

INTERFACE IShellLinkDataList $IID_IShellLinkDataList

   INHERIT IUnknown

   ' =====================================================================================
   METHOD AddDataBlock ( _                              ' VTable offset = 12
     BYVAL pDataBlock AS DWORD _                        ' __in void * pDataBlock
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CopyDataBlock ( _                             ' VTable offset = 16
     BYVAL dwSig AS DWORD _                             ' __in DWORD dwSig
   , BYREF ppDataBlock AS DWORD _                       ' __out void **ppDataBlock
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RemoveDataBlock ( _                           ' VTable offset = 20
     BYVAL dwSig AS DWORD _                             ' __in DWORD dwSig
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFlags ( _                                  ' VTable offset = 24
     BYREF pdwFlags AS DWORD _                          ' __out DWORD *pdwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetFlags ( _                                  ' VTable offset = 28
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IShellLinkDataList_INTERFACE_DEFINED__ */

'#if (NTDDI_VERSION >= NTDDI_WIN2K)

' ########################################################################################
' IResolveShellLink interface
' IID = 5CD52983-9449-11D2-963A-00C04F79ADF0
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IResolveShellLink_INTERFACE_DEFINED)
    %IResolveShellLink_INTERFACE_DEFINED = 1

$IID_IResolveShellLink = GUID$("{5CD52983-9449-11D2-963A-00C04F79ADF0}")

INTERFACE IResolveShellLink $IID_IResolveShellLink

   INHERIT IUnknown

   ' =====================================================================================
   METHOD ResolveShellLink ( _                          ' VTable offset = 12
     BYVAL punk AS IUnknown _                           ' __in IUnknown* punk
   , BYVAL hwnd AS DWORD _                              ' __in HWND hwnd
   , BYVAL fFlags AS DWORD _                            ' __in DWORD fFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IResolveShellLink_INTERFACE_DEFINED__ */

'#endif  // NTDDI_WIN2K

' ########################################################################################
' IActionProgressDialog interface
' IID = 49FF1172-EADC-446D-9285-156453A6431C
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IActionProgressDialog_INTERFACE_DEFINED)
    %IActionProgressDialog_INTERFACE_DEFINED = 1

' SPINITF enum
%SPINITF_NORMAL     = 0???
%SPINITF_MODAL      = &H1???
%SPINITF_NOMINIMIZE = &H8???
'typedef DWORD SPINITF;

$IID_IActionProgressDialog = GUID$("{49FF1172-EADC-446D-9285-156453A6431C}")

INTERFACE IActionProgressDialog $IID_IActionProgressDialog

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Initialize ( _                                ' VTable offset = 12
     BYVAL flags AS DWORD _                             ' __in SPINITF flags
   , BYREF pszTitle AS WSTRINGZ _                       ' __in LPCWSTR pszTitle
   , BYREF pszCancel AS WSTRINGZ _                      ' __in LPCWSTR pszCancel
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Stop ( _                                      ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IActionProgressDialog_INTERFACE_DEFINED__ */


' ########################################################################################
' IHWEventHandler interface
' IID = C1FB73D0-EC3A-4BA2-B512-8CDB9187B6D1
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IHWEventHandler_INTERFACE_DEFINED)
    %IHWEventHandler_INTERFACE_DEFINED = 1

$IID_IHWEventHandler = GUID$("{C1FB73D0-EC3A-4BA2-B512-8CDB9187B6D1}")

INTERFACE IHWEventHandler $IID_IHWEventHandler

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Initialize ( _                                ' VTable offset = 12
     BYREF pszParams AS WSTRINGZ _                      ' __in LPCWSTR pszParams
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD HandleEvent ( _                               ' VTable offset = 16
     BYREF pszDeviceID AS WSTRINGZ _                    ' __in LPCWSTR pszDeviceID
   , BYREF pszAltDeviceID AS WSTRINGZ _                 ' __in LPCWSTR pszAltDeviceID
   , BYREF pszEventType AS WSTRINGZ _                   ' __in LPCWSTR pszEventType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD HandleEventWithContent ( _                    ' VTable offset = 20
     BYREF pszDeviceID AS WSTRINGZ _                    ' __in LPCWSTR pszDeviceID
   , BYREF pszAltDeviceID AS WSTRINGZ _                 ' __in LPCWSTR pszAltDeviceID
   , BYREF pszEventType AS WSTRINGZ _                   ' __in LPCWSTR pszEventType
   , BYREF pszContentTypeHandler AS WSTRINGZ _          ' __in LPCWSTR pszContentTypeHandler
   , BYREF pdataobject AS IDataObject _                 ' __in IDataObject *pdataobject
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IHWEventHandler_INTERFACE_DEFINED__ */


' ########################################################################################
' IHWEventHandler2 interface
' IID = CFCC809F-295D-42E8-9FFC-424B33C487E6
' Inherited interface = IHWEventHandler
' ########################################################################################

#IF NOT %DEF(%IHWEventHandler2_INTERFACE_DEFINED)
    %IHWEventHandler2_INTERFACE_DEFINED = 1

$IID_IHWEventHandler2 = GUID$("{CFCC809F-295D-42E8-9FFC-424B33C487E6}")

INTERFACE IHWEventHandler2 $IID_IHWEventHandler2

   INHERIT IUnknown

   ' =====================================================================================
   ' IHWEventHandler Methods
   ' =====================================================================================
   METHOD Initialize ( _                                ' VTable offset = 12
     BYREF pszParams AS WSTRINGZ _                      ' __in LPCWSTR pszParams
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD HandleEvent ( _                               ' VTable offset = 16
     BYREF pszDeviceID AS WSTRINGZ _                    ' __in LPCWSTR pszDeviceID
   , BYREF pszAltDeviceID AS WSTRINGZ _                 ' __in LPCWSTR pszAltDeviceID
   , BYREF pszEventType AS WSTRINGZ _                   ' __in LPCWSTR pszEventType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD HandleEventWithContent ( _                    ' VTable offset = 20
     BYREF pszDeviceID AS WSTRINGZ _                    ' __in LPCWSTR pszDeviceID
   , BYREF pszAltDeviceID AS WSTRINGZ _                 ' __in LPCWSTR pszAltDeviceID
   , BYREF pszEventType AS WSTRINGZ _                   ' __in LPCWSTR pszEventType
   , BYREF pszContentTypeHandler AS WSTRINGZ _          ' __in LPCWSTR pszContentTypeHandler
   , BYREF pdataobject AS IDataObject _                 ' __in IDataObject *pdataobject
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IHWEventHandler2 Methods
   ' =====================================================================================
   METHOD HandleEventWithHWND ( _                       ' VTable offset = 24
     BYREF pszDeviceID AS WSTRINGZ _                    ' __in LPCWSTR pszDeviceID
   , BYREF pszAltDeviceID AS WSTRINGZ _                 ' __in LPCWSTR pszAltDeviceID
   , BYREF pszEventType AS WSTRINGZ _                   ' __in LPCWSTR pszEventType
   , BYVAL hwndOwner AS DWORD _                         ' __in HWND hwndOwner
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IHWEventHandler2_INTERFACE_DEFINED__ */

%ARCONTENT_AUTORUNINF     = &H00000002???
%ARCONTENT_AUDIOCD        = &H00000004???
%ARCONTENT_DVDMOVIE       = &H00000008???
%ARCONTENT_BLANKCD        = &H00000010???
%ARCONTENT_BLANKDVD       = &H00000020???
%ARCONTENT_UNKNOWNCONTENT = &H00000040???
%ARCONTENT_AUTOPLAYPIX    = &H00000080???
%ARCONTENT_AUTOPLAYMUSIC  = &H00000100???
%ARCONTENT_AUTOPLAYVIDEO  = &H00000200???
'#if (NTDDI_VERSION >= NTDDI_VISTA)
%ARCONTENT_VCD            = &H00000400???   ' // VCD format
%ARCONTENT_SVCD           = &H00000800???   ' // Super-VCD format
%ARCONTENT_DVDAUDIO       = &H00001000???   ' // DVD-Audio
%ARCONTENT_HDDVD          = &H00002000???   ' // HD DVD
%ARCONTENT_BLURAY         = &H00004000???   ' // Blu-ray Disc
%ARCONTENT_NONE           = &H00000000???   ' // Empty (but formatted)
%ARCONTENT_MASK           = &H00007FFE???   ' // Bits that denote valid content types
%ARCONTENT_PHASE_UNKNOWN  = &H00000000???   ' // We can be in any phase.  This is XP behavior.
%ARCONTENT_PHASE_PRESNIFF = &H10000000???   ' // These are contents we know w/o scanning the media for complete data (e.g. Audio track, DVD Movie).
%ARCONTENT_PHASE_SNIFFING = &H20000000???   ' // We are in the middle of searching the media.  There could be more contents to be found than currently reported.
%ARCONTENT_PHASE_FINAL    = &H40000000???   ' // We have finished searching; contents we report are final.
%ARCONTENT_PHASE_MASK     = &H70000000???   ' // Bits that denote what phase we are in the Autoplay process.
'#endif  // NTDDI_VISTA

' ########################################################################################
' IQueryCancelAutoPlay interface
' IID = DDEFE873-6997-4E68-BE26-39B633ADBE12
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IQueryCancelAutoPlay_INTERFACE_DEFINED)
    %IQueryCancelAutoPlay_INTERFACE_DEFINED = 1

$IID_IQueryCancelAutoPlay = GUID$("{DDEFE873-6997-4E68-BE26-39B633ADBE12}")

INTERFACE IQueryCancelAutoPlay $IID_IQueryCancelAutoPlay

   INHERIT IUnknown

   ' =====================================================================================
   METHOD AllowAutoPlay ( _                             ' VTable offset = 12
     BYREF pszPath AS WSTRINGZ _                        ' __in LPCWSTR pszPath
   , BYVAL dwContentType AS DWORD _                     ' __in DWORD dwContentType
   , BYREF pszLabel AS WSTRINGZ _                       ' __in LPCWSTR pszLabel
   , BYVAL dwSerialNumber AS DWORD _                    ' __in DWORD dwSerialNumber
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IQueryCancelAutoPlay_INTERFACE_DEFINED__ */


'#if (NTDDI_VERSION >= NTDDI_VISTA)

' ########################################################################################
' IDynamicHWHandler interface
' IID = DC2601D7-059E-42FC-A09D-2AFD21B6D5F7
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDynamicHWHandler_INTERFACE_DEFINED)
    %IDynamicHWHandler_INTERFACE_DEFINED = 1

$IID_IDynamicHWHandler = GUID$("{DC2601D7-059E-42FC-A09D-2AFD21B6D5F7}")

INTERFACE IDynamicHWHandler $IID_IDynamicHWHandler

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetDynamicInfo ( _                            ' VTable offset = 12
     BYREF pszDeviceID AS WSTRINGZ _                    ' __in LPCWSTR pszDeviceID
   , BYVAL dwContentType AS DWORD _                     ' __in DWORD dwContentType
   , BYREF ppszAction AS DWORD _                        ' __out LPWSTR *ppszAction
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDynamicHWHandler_INTERFACE_DEFINED__ */

'#endif  // NTDDI_VISTA


' ########################################################################################
' IActionProgress interface
' IID = 49ff1173-eadc-446d-9285-156453a6431c
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IActionProgress_INTERFACE_DEFINED)
    %IActionProgress_INTERFACE_DEFINED = 1

' enum SPBEGINF
%SPBEGINF_NORMAL          = 0???
%SPBEGINF_AUTOTIME        = &H2???
%SPBEGINF_NOPROGRESSBAR   = &H10???
%SPBEGINF_MARQUEEPROGRESS = &H20???
%SPBEGINF_NOCANCELBUTTON  = &H40???
'typedef DWORD SPBEGINF;

' SPACTION enum
%SPACTION_NONE               = 0
%SPACTION_MOVING             = %SPACTION_NONE + 1
%SPACTION_COPYING            = %SPACTION_MOVING + 1
%SPACTION_RECYCLING          = %SPACTION_COPYING + 1
%SPACTION_APPLYINGATTRIBS    = %SPACTION_RECYCLING + 1
%SPACTION_DOWNLOADING        = %SPACTION_APPLYINGATTRIBS + 1
%SPACTION_SEARCHING_INTERNET = %SPACTION_DOWNLOADING + 1
%SPACTION_CALCULATING        = %SPACTION_SEARCHING_INTERNET + 1
%SPACTION_UPLOADING          = %SPACTION_CALCULATING + 1
%SPACTION_SEARCHING_FILES    = %SPACTION_UPLOADING + 1
%SPACTION_DELETING           = %SPACTION_SEARCHING_FILES + 1
%SPACTION_RENAMING           = %SPACTION_DELETING + 1
%SPACTION_FORMATTING         = %SPACTION_RENAMING + 1
%SPACTION_COPY_MOVING        = %SPACTION_FORMATTING + 1

' SPTEXT enum
%SPTEXT_ACTIONDESCRIPTION = 1
%SPTEXT_ACTIONDETAIL      = %SPTEXT_ACTIONDESCRIPTION + 1

$IID_IActionProgress = GUID$("{49FF1173-EADC-446D-9285-156453A6431C}")

INTERFACE IActionProgress $IID_IActionProgress

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Begin ( _                                     ' VTable offset = 12
     BYVAL action AS LONG _                             ' __in SPACTION action
   , BYVAL flags AS LONG _                              ' __in SPBEGINF flags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UpdateProgress ( _                            ' VTable offset = 16
     BYVAL ulCompleted AS QUAD _                        ' __in ULONGLONG ulCompleted
   , BYVAL ulTotal AS QUAD _                            ' __in ULONGLONG ulTotal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UpdateText ( _                                ' VTable offset = 20
     BYVAL sptext AS LONG _                             ' __in SPTEXT sptext
   , BYREF pszText AS WSTRINGZ _                        ' __in LPCWSTR pszText
   , BYVAL fMayCompact AS LONG _                        ' __in BOOL fMayCompact
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD QueryCancel ( _                               ' VTable offset = 24
     BYREF pfCancelled AS LONG _                        ' __out BOOL *pfCancelled
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ResetCancel ( _                               ' VTable offset = 28
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD End ( _                                       ' VTable offset = 32
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IActionProgress_INTERFACE_DEFINED__ */


' ########################################################################################
' IShellExtInit interface
' IID = 000214E8-0000-0000-C000-000000000046
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IShellExtInit_INTERFACE_DEFINED)
    %IShellExtInit_INTERFACE_DEFINED = 1

$IID_IShellExtInit = GUID$("{000214E8-0000-0000-C000-000000000046}")

INTERFACE IShellExtInit $IID_IShellExtInit

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Initialize ( _                                ' VTable offset = 12
     BYVAL pidlFolder AS DWORD _                        ' __in LPCITEMIDLIST pidlFolder
   , BYVAL pdtobj AS IDataObject _                      ' __in IDataObject *pdtobj
   , BYVAL hkeyProgID AS DWORD _                        ' __in HKEY hkeyProgID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IShellExtInit_INTERFACE_DEFINED__ */


' ########################################################################################
' IShellPropSheetExt interface
' IID = 000214E9-0000-0000-C000-000000000046
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IShellPropSheetExt_INTERFACE_DEFINED)
    %IShellPropSheetExt_INTERFACE_DEFINED = 1

' __MIDL_IShellPropSheetExt_0001 enum
%EXPPS_FILETYPES = &H1
'typedef UINT EXPPS;

$IID_IShellPropSheetExt = GUID$("{000214E9-0000-0000-C000-000000000046}")

INTERFACE IShellPropSheetExt $IID_IShellPropSheetExt

   INHERIT IUnknown

   ' =====================================================================================
   METHOD AddPages ( _                                  ' VTable offset = 12
     BYVAL pfnAddPage AS DWORD _                        ' __in LPFNSVADDPROPSHEETPAGE pfnAddPage
   , BYVAL lParam AS LONG _                             ' __in LPARAM lParam
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ReplacePage ( _                               ' VTable offset = 16
     BYVAL uPageID AS DWORD _                           ' __in EXPPS uPageID
   , BYVAL pfnReplaceWith AS DWORD _                    ' __in LPFNSVADDPROPSHEETPAGE pfnReplaceWith
   , BYVAL lParam AS LONG _                             ' __in LPARAM lParam
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IShellPropSheetExt_INTERFACE_DEFINED__ */


' ########################################################################################
' IRemoteComputer interface
' IID = 000214FE-0000-0000-C000-000000000046
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IRemoteComputer_INTERFACE_DEFINED)
    %IRemoteComputer_INTERFACE_DEFINED = 1

$IID_IRemoteComputer = GUID$("{000214FE-0000-0000-C000-000000000046}")

INTERFACE IRemoteComputer $IID_IRemoteComputer

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Initialize ( _                                ' VTable offset = 12
     BYREF pszMachine AS WSTRINGZ _                     ' __in LPCWSTR pszMachine
   , BYVAL bEnumerating AS LONG _                       ' __in BOOL bEnumerating
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IRemoteComputer_INTERFACE_DEFINED__ */


' ########################################################################################
' IQueryContinue interface
' IID = 7307055C-B24A-486B-9F25-163E597A28A9
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IQueryContinue_INTERFACE_DEFINED)
    %IQueryContinue_INTERFACE_DEFINED = 1

$IID_IQueryContinue = GUID$("{7307055C-B24A-486B-9F25-163E597A28A9}")

INTERFACE IQueryContinue $IID_IQueryContinue

   INHERIT IUnknown

   ' =====================================================================================
   METHOD QueryContinue ( _                             ' VTable offset = 12
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IQueryContinue_INTERFACE_DEFINED__ */

' ########################################################################################
' IObjectWithCancelEvent interface
' IID = F279B885-0AE9-4B85-AC06-DDECF9408941
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IObjectWithCancelEvent_INTERFACE_DEFINED)
    %IObjectWithCancelEvent_INTERFACE_DEFINED = 1

$IID_IObjectWithCancelEvent = GUID$("{F279B885-0AE9-4B85-AC06-DDECF9408941}")

INTERFACE IObjectWithCancelEvent $IID_IObjectWithCancelEvent

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetCancelEvent ( _                            ' VTable offset = 12
     BYREF phEvent AS DWORD _                           ' __out  HANDLE *phEvent
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IObjectWithCancelEvent_INTERFACE_DEFINED__ */


' ########################################################################################
' IUserNotification interface
' IID = BA9711BA-5893-4787-A7E1-41277151550B
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IUserNotification_INTERFACE_DEFINED)
    %IUserNotification_INTERFACE_DEFINED = 1

$IID_IUserNotification = GUID$("{BA9711BA-5893-4787-A7E1-41277151550B}")

INTERFACE IUserNotification $IID_IUserNotification

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetBalloonInfo ( _                            ' VTable offset = 12
     BYREF pszTitle AS WSTRINGZ _                       ' __in LPCWSTR pszTitle
   , BYREF pszText AS WSTRINGZ _                        ' __in LPCWSTR pszText
   , BYVAL dwInfoFlags AS DWORD _                       ' __in DWORD dwInfoFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetBalloonRetry ( _                           ' VTable offset = 16
     BYVAL dwShowTime AS DWORD _                        ' __in DWORD dwShowTime
   , BYVAL dwInterval AS DWORD _                        ' __in DWORD dwInterval
   , BYVAL cRetryCount AS DWORD _                       ' __in UINT cRetryCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetIconInfo ( _                               ' VTable offset = 20
     BYVAL hIcon AS DWORD _                             ' __in HICON hIcon
   , BYREF pszToolTip AS WSTRINGZ _                     ' __in LPCWSTR pszToolTip
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Show ( _                                      ' VTable offset = 24
     BYVAL pqc AS IQueryContinue _                      ' __in IQueryContinue *pqc
   , BYVAL dwContinuePollInterval AS DWORD _            ' __in DWORD dwContinuePollInterval
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD PlaySound ( _                                 ' VTable offset = 28
     BYREF pszSoundName AS WSTRINGZ _                   ' __in LPCWSTR pszSoundName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IUserNotification_INTERFACE_DEFINED__ */


' ########################################################################################
' IUserNotificationCallback interface
' IID = 19108294-0441-4AFF-8013-FA0A730B0BEA
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IUserNotificationCallback_INTERFACE_DEFINED)
    %IUserNotificationCallback_INTERFACE_DEFINED = 1

$IID_IUserNotificationCallback = GUID$("{19108294-0441-4AFF-8013-FA0A730B0BEA}")

INTERFACE IUserNotificationCallback $IID_IUserNotificationCallback

   INHERIT IUnknown

   ' =====================================================================================
   METHOD OnBalloonUserClick ( _                        ' VTable offset = 12
     BYREF pt AS POINT _                                ' __in POINT *pt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnLeftClick ( _                               ' VTable offset = 16
     BYREF pt AS POINT _                                ' __in POINT *pt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnContextMenu ( _                             ' VTable offset = 20
     BYREF pt AS POINT _                                ' __in POINT *pt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IUserNotificationCallback_INTERFACE_DEFINED__ */


' ########################################################################################
' IUserNotification2 interface
' IID = 215913CC-57EB-4FAB-AB5A-E5FA7BEA2A6C
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IUserNotification2_INTERFACE_DEFINED)
    %IUserNotification2_INTERFACE_DEFINED = 1

$IID_IUserNotification2 = GUID$("{215913CC-57EB-4FAB-AB5A-E5FA7BEA2A6C}")

INTERFACE IUserNotification2 $IID_IUserNotification2

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetBalloonInfo ( _                            ' VTable offset = 12
     BYREF pszTitle AS WSTRINGZ _                       ' __in LPCWSTR pszTitle
   , BYREF pszText AS WSTRINGZ _                        ' __in LPCWSTR pszText
   , BYVAL dwInfoFlags AS DWORD _                       ' __in DWORD dwInfoFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetBalloonRetry ( _                           ' VTable offset = 16
     BYVAL dwShowTime AS DWORD _                        ' __in DWORD dwShowTime
   , BYVAL dwInterval AS DWORD _                        ' __in DWORD dwInterval
   , BYVAL cRetryCount AS DWORD _                       ' __in UINT cRetryCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetIconInfo ( _                               ' VTable offset = 20
     BYVAL hIcon AS DWORD _                             ' __in HICON hIcon
   , BYREF pszToolTip AS WSTRINGZ _                     ' __in LPCWSTR pszToolTip
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Show ( _                                      ' VTable offset = 24
     BYVAL pqc AS IQueryContinue _                      ' __in IQueryContinue *pqc
   , BYVAL dwContinuePollInterval AS DWORD _            ' __in DWORD dwContinuePollInterval
   , BYVAL pSink AS IUserNotificationCallback _         ' __in IUserNotificationCallback *pSink
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD PlaySound ( _                                 ' VTable offset = 28
     BYREF pszSoundName AS WSTRINGZ _                   ' __in LPCWSTR pszSoundName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IUserNotification2_INTERFACE_DEFINED__ */


' ########################################################################################
' IItemNameLimits interface
' IID = 1DF0D7F1-B267-4D28-8B10-12E23202A5C4
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IItemNameLimits_INTERFACE_DEFINED)
    %IItemNameLimits_INTERFACE_DEFINED = 1

$IID_IItemNameLimits = GUID$("{1DF0D7F1-B267-4D28-8B10-12E23202A5C4}")

INTERFACE IItemNameLimits $IID_IItemNameLimits

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetValidCharacters ( _                        ' VTable offset = 12
     BYREF ppwszValidChars AS DWORD _                   ' __out LPWSTR *ppwszValidChars
   , BYREF ppwszInvalidChars AS DWORD _                 ' __out LPWSTR *ppwszInvalidChars
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMaxLength ( _                              ' VTable offset = 16
     BYREF pszName AS WSTRINGZ _                        ' __in LPCWSTR pszName
   , BYREF piMaxNameLen AS LONG _                       ' __out int *piMaxNameLen
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IItemNameLimits_INTERFACE_DEFINED__ */

'#if (NTDDI_VERSION >= NTDDI_VISTA)

' ########################################################################################
' ISearchFolderItemFactory interface
' IID = A0FFBC28-5482-4366-BE27-3E81E78E06C2
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ISearchFolderItemFactory_INTERFACE_DEFINED)
    %ISearchFolderItemFactory_INTERFACE_DEFINED = 1

$IID_ISearchFolderItemFactory = GUID$("{A0FFBC28-5482-4366-BE27-3E81E78E06C2}")

INTERFACE ISearchFolderItemFactory $IID_ISearchFolderItemFactory

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetDisplayName ( _                            ' VTable offset = 12
     BYREF pszDisplayName AS WSTRINGZ _                 ' __in LPCWSTR pszDisplayName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetFolderTypeID ( _                           ' VTable offset = 16
     BYREF ftid AS GUID _                               ' __in FOLDERTYPEID ftid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetFolderLogicalViewMode ( _                  ' VTable offset = 20
     BYVAL flvm AS LONG _                               ' __in FOLDERLOGICALVIEWMODE flvm
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetIconSize ( _                               ' VTable offset = 24
     BYVAL iIconSize AS LONG _                          ' __in int iIconSize
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetVisibleColumns ( _                         ' VTable offset = 28
     BYVAL cVisibleColumns AS DWORD _                   ' __in UINT cVisibleColumns
   , BYREF rgKey AS PROPERTYKEY _                       ' __in PROPERTYKEY *rgKey
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetSortColumns ( _                            ' VTable offset = 32
     BYVAL cSortColumns AS DWORD _                      ' __in UINT cSortColumns
   , BYREF rgSortColumns AS SORTCOLUMN _                ' __in SORTCOLUMN *rgSortColumns
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetGroupColumn ( _                            ' VTable offset = 36
     BYREF keyGroup AS PROPERTYKEY _                    ' __in REFPROPERTYKEY keyGroup
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetStacks ( _                                 ' VTable offset = 40
     BYVAL cStackKeys AS DWORD _                        ' __in UINT cStackKeys
   , BYREF rgStackKeys AS PROPERTYKEY _                 ' __in PROPERTYKEY *rgStackKeys
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetScope ( _                                  ' VTable offset = 44
     BYVAL psiaScope AS IShellItemArray _               ' __in IShellItemArray *psiaScope
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetCondition ( _                              ' VTable offset = 48
     BYVAL pCondition AS ICondition _                   ' __in ICondition *pCondition
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetShellItem ( _                              ' VTable offset = 52
     BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppv AS IUnknown _                            ' __out void **ppv
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetIDList ( _                                 ' VTable offset = 56
     BYREF ppidl AS DWORD _                             ' __out PIDLIST_ABSOLUTE *ppidl
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISearchFolderItemFactory_INTERFACE_DEFINED__ */

'#endif  // NTDDI_VISTA

'#if (_WIN32_IE >= 0x0400)
%ITSAT_MAX_PRIORITY     = &H7FFFFFFF???
%ITSAT_MIN_PRIORITY     = &H00000000???
%ITSAT_DEFAULT_PRIORITY = &H10000000???
%IEI_PRIORITY_MAX       = %ITSAT_MAX_PRIORITY
%IEI_PRIORITY_MIN       = %ITSAT_MIN_PRIORITY
%IEIT_PRIORITY_NORMAL   = %ITSAT_DEFAULT_PRIORITY
%IEIFLAG_ASYNC          = &H0001???   ' // ask the extractor if it supports ASYNC extract (free threaded)
%IEIFLAG_CACHE          = &H0002???   ' // returned from the extractor if it does NOT cache the thumbnail
%IEIFLAG_ASPECT         = &H0004???   ' // passed to the extractor to beg it to render to the aspect ratio of the supplied rect
%IEIFLAG_OFFLINE        = &H0008???   ' // if the extractor shouldn't hit the net to get any content neede for the rendering
%IEIFLAG_GLEAM          = &H0010???   ' // does the image have a gleam ? this will be returned if it does
%IEIFLAG_SCREEN         = &H0020???   ' // render as if for the screen  (this is exlusive with IEIFLAG_ASPECT )
%IEIFLAG_ORIGSIZE       = &H0040???   ' // render to the approx size passed, but crop if neccessary
%IEIFLAG_NOSTAMP        = &H0080???   ' // returned from the extractor if it does NOT want an icon stamp on the thumbnail
%IEIFLAG_NOBORDER       = &H0100???   ' // returned from the extractor if it does NOT want an a border around the thumbnail
%IEIFLAG_QUALITY        = &H0200???   ' // passed to the Extract method to indicate that a slower, higher quality image is desired, re-compute the thumbnail
%IEIFLAG_REFRESH        = &H0400???   ' // returned from the extractor if it would like to have Refresh Thumbnail available

' ########################################################################################
' IExtractImage interface
' IID = BB2E617C-0920-11D1-9A0B-00C04FC2D6C1
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IExtractImage_INTERFACE_DEFINED)
    %IExtractImage_INTERFACE_DEFINED = 1

$IID_IExtractImage = GUID$("{BB2E617C-0920-11D1-9A0B-00C04FC2D6C1}")

INTERFACE IExtractImage $IID_IExtractImage

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetLocation ( _                               ' VTable offset = 12
     BYREF pszPathBuffer AS WSTRINGZ _                  ' __out LPWSTR pszPathBuffer
   , BYVAL cch AS DWORD _                               ' __in DWORD cch
   , BYREF pdwPriority AS DWORD _                       ' __inout DWORD *pdwPriority
   , BYREF prgSize AS SIZE _                            ' __in const SIZE *prgSize
   , BYVAL dwRecClrDepth AS DWORD _                     ' __in DWORD dwRecClrDepth
   , BYREF pdwFlags AS DWORD _                          ' __inout DWORD *pdwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Extract ( _                                   ' VTable offset = 16
     BYREF phBmpThumbnail AS DWORD _                    ' __out HBITMAP *phBmpThumbnail
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IExtractImage_INTERFACE_DEFINED__ */

'#endif

'#if (_WIN32_IE >= 0x0500)

' ########################################################################################
' IExtractImage2 interface
' IID = 953BB1EE-93B4-11D1-98A3-00C04FB687DA
' Inherited interface = IExtractImage
' ########################################################################################

#IF NOT %DEF(%IExtractImage2_INTERFACE_DEFINED)
    %IExtractImage2_INTERFACE_DEFINED = 1

$IID_IExtractImage2 = GUID$("{953BB1EE-93B4-11D1-98A3-00C04FB687DA}")

INTERFACE IExtractImage2 $IID_IExtractImage2

   INHERIT IUnknown

   ' =====================================================================================
   ' IExtractImage Methods
   ' =====================================================================================
   METHOD GetLocation ( _                               ' VTable offset = 12
     BYREF pszPathBuffer AS WSTRINGZ _                  ' __out LPWSTR pszPathBuffer
   , BYVAL cch AS DWORD _                               ' __in DWORD cch
   , BYREF pdwPriority AS DWORD _                       ' __inout DWORD *pdwPriority
   , BYREF prgSize AS SIZE _                            ' __in const SIZE *prgSize
   , BYVAL dwRecClrDepth AS DWORD _                     ' __in DWORD dwRecClrDepth
   , BYREF pdwFlags AS DWORD _                          ' __inout DWORD *pdwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Extract ( _                                   ' VTable offset = 16
     BYREF phBmpThumbnail AS DWORD _                    ' __out HBITMAP *phBmpThumbnail
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IExtractImage2 Methods
   ' =====================================================================================
   METHOD GetDateStamp ( _                              ' VTable offset = 20
     BYREF pDateStamp AS FILETIME _                     ' __out FILETIME *pDateStamp
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IExtractImage2_INTERFACE_DEFINED__ */

'#endif

' ########################################################################################
' IThumbnailHandlerFactory interface
' IID = E35B4B2E-00DA-4BC1-9F13-38BC11F5D417
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IThumbnailHandlerFactory_INTERFACE_DEFINED)
    %IThumbnailHandlerFactory_INTERFACE_DEFINED = 1

$IID_IThumbnailHandlerFactory = GUID$("{E35B4B2E-00DA-4BC1-9F13-38BC11F5D417}")

INTERFACE IThumbnailHandlerFactory $IID_IThumbnailHandlerFactory

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetThumbnailHandler ( _                       ' VTable offset = 12
     BYVAL pidlChild AS DWORD _                         ' __in PCUITEMID_CHILD pidlChild
   , BYVAL pbc AS IBindCtx _                            ' __in IBindCtx *pbc
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppv AS IUnknown _                            ' __out void **ppv
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IThumbnailHandlerFactory_INTERFACE_DEFINED__ */


' ########################################################################################
' IParentAndItem interface
' IID = B3A4B685-B685-4805-99D9-5DEAD2873236
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IParentAndItem_INTERFACE_DEFINED)
    %IParentAndItem_INTERFACE_DEFINED = 1

$IID_IParentAndItem = GUID$("{B3A4B685-B685-4805-99D9-5DEAD2873236}")

INTERFACE IParentAndItem $IID_IParentAndItem

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetParentAndItem ( _                          ' VTable offset = 12
     BYVAL pidlParent AS DWORD _                        ' __in PCIDLIST_ABSOLUTE pidlParent
   , BYVAL psf AS IShellFolder _                        ' __in IShellFolder *psf
   , BYVAL pidlChild AS DWORD _                         ' __in PCUITEMID_CHILD pidlChild
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetParentAndItem ( _                          ' VTable offset = 16
     BYREF ppidlParent AS DWORD _                       ' __out PIDLIST_ABSOLUTE *ppidlParent
   , BYREF ppsf AS IShellFolder _                       ' __out IShellFolder **ppsf
   , BYREF ppidlChild AS DWORD _                        ' __out PITEMID_CHILD *ppidlChild
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IParentAndItem_INTERFACE_DEFINED__ */


' ########################################################################################
' IDockingWindow interface
' IID = 012DD920-7B26-11D0-8CA9-00A0C92DBFE8
' Inherited interface = IOleWindow
' ########################################################################################

#IF NOT %DEF(%IDockingWindow_INTERFACE_DEFINED)
    %IDockingWindow_INTERFACE_DEFINED = 1

$IID_IDockingWindow = GUID$("{012DD920-7B26-11D0-8CA9-00A0C92DBFE8}")

INTERFACE IDockingWindow $IID_IDockingWindow

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
   ' IDockingWindow methods
   ' =====================================================================================
   METHOD ShowDW ( _                                    ' VTable offset = 20
     BYVAL fShow AS LONG _                              ' __in BOOL fShow
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CloseDW ( _                                   ' VTable offset = 24
     BYVAL dwReserved AS DWORD _                        ' __in DWORD dwReserved
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ResizeBorderDW ( _                            ' VTable offset = 28
     BYREF prcBorder AS RECT _                          ' __in LPCRECT prcBorder
   , BYVAL punkToolbarSite AS IUnknown _                ' __in IUnknown *punkToolbarSite
   , BYVAL fReserved AS LONG _                          ' __in BOOL fReserved
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDockingWindow_INTERFACE_DEFINED__ */

%DBIM_MINSIZE              = &H0001???
%DBIM_MAXSIZE              = &H0002???
%DBIM_INTEGRAL             = &H0004???
%DBIM_ACTUAL               = &H0008???
%DBIM_TITLE                = &H0010???
%DBIM_MODEFLAGS            = &H0020???
%DBIM_BKCOLOR              = &H0040???

'#include <pshpack8.h>

' // Size = 556 bytes
TYPE DESKBANDINFO DWORD
   dwMask      AS DWORD
   ptMinSize   AS POINTL
   ptMaxSixe   AS POINTL
   ptIntegral  AS POINTL
   ptActual    AS POINTL
   wszTitle    AS WSTRINGZ * 256
   dwModeFlags AS DWORD
   crBkgnd     AS DWORD
END TYPE

'#include <poppack.h>

%DBIMF_NORMAL              = &H0000???
%DBIMF_FIXED               = &H0001???
%DBIMF_FIXEDBMP            = &H0004???   ' // a fixed background bitmap (if supported)
%DBIMF_VARIABLEHEIGHT      = &H0008???
%DBIMF_UNDELETEABLE        = &H0010???
%DBIMF_DEBOSSED            = &H0020???
%DBIMF_BKCOLOR             = &H0040???
%DBIMF_USECHEVRON          = &H0080???
%DBIMF_BREAK               = &H0100???
%DBIMF_ADDTOFRONT          = &H0200???
%DBIMF_TOPALIGN            = &H0400???
'#if (NTDDI_VERSION >= NTDDI_VISTA)
%DBIMF_NOGRIPPER           = &H0800???
%DBIMF_ALWAYSGRIPPER       = &H1000???
%DBIMF_NOMARGINS           = &H2000???
'#endif  // NTDDI_VISTA
%DBIF_VIEWMODE_NORMAL      = &H0000???
%DBIF_VIEWMODE_VERTICAL    = &H0001???
%DBIF_VIEWMODE_FLOATING    = &H0002???
%DBIF_VIEWMODE_TRANSPARENT = &H0004???

' enum DESKBANDCID
%DBID_BANDINFOCHANGED = 0
%DBID_SHOWONLY        = 1
%DBID_MAXIMIZEBAND    = 2
%DBID_PUSHCHEVRON     = 3
%DBID_DELAYINIT       = 4
%DBID_FINISHINIT      = 5
%DBID_SETWINDOWTHEME  = 6
%DBID_PERMITAUTOHIDE  = 7

%DBPC_SELECTFIRST          = &HFFFFFFFF???  ' (DWORD) - 1
%DBPC_SELECTLAST           = &HFFFFFFFE???  ' (DWORD) - 2

' ########################################################################################
' IDeskBand interface
' IID = EB0FE172-1A3A-11D0-89B3-00A0C90A90AC
' Inherited interface = IDockingWindow
' ########################################################################################

#IF NOT %DEF(%IDeskBand_INTERFACE_DEFINED)
    %IDeskBand_INTERFACE_DEFINED = 1

$IID_IDeskBand  = GUID$("{EB0FE172-1A3A-11D0-89B3-00A0C90A90AC}")
$CGID_IDeskBand = GUID$("{EB0FE172-1A3A-11D0-89B3-00A0C90A90AC}")

INTERFACE IDeskBand $IID_IDeskBand

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
   ' IDockingWindow methods
   ' =====================================================================================
   METHOD ShowDW ( _                                    ' VTable offset = 20
     BYVAL fShow AS LONG _                              ' __in BOOL fShow
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CloseDW ( _                                   ' VTable offset = 24
     BYVAL dwReserved AS DWORD _                        ' __in DWORD dwReserved
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ResizeBorderDW ( _                            ' VTable offset = 28
     BYREF prcBorder AS RECT _                          ' __in LPCRECT prcBorder
   , BYVAL punkToolbarSite AS IUnknown _                ' __in IUnknown *punkToolbarSite
   , BYVAL fReserved AS LONG _                          ' __in BOOL fReserved
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IDeskBand method
   ' =====================================================================================
   METHOD GetBandInfo ( _                               ' VTable offset = 32
     BYVAL dwBandID AS DWORD _                          ' __in DWORD dwBandID
   , BYVAL dwViewMode AS DWORD _                        ' __in DWORD dwViewMode
   , BYREF pdbi AS DESKBANDINFO _                       ' __inout DESKBANDINFO *pdbi
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDeskBand_INTERFACE_DEFINED__ */

'#if (NTDDI_VERSION >= NTDDI_VISTA)

' ########################################################################################
' IDeskBandInfo interface
' IID = 77E425FC-CBF9-4307-BA6A-BB5727745661
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDeskBandInfo_INTERFACE_DEFINED)
    %IDeskBandInfo_INTERFACE_DEFINED = 1

$IID_IDeskBandInfo = GUID$("{77E425FC-CBF9-4307-BA6A-BB5727745661}")

INTERFACE IDeskBandInfo $IID_IDeskBandInfo

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetDefaultBandWidth ( _                       ' VTable offset = 12
     BYVAL dwBandID AS DWORD _                          ' __in DWORD dwBandID
   , BYVAL dwViewMode AS DWORD _                        ' __in DWORD dwViewMode
   , BYREF pnWidth AS LONG _                            ' __out int *pnWidth
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDeskBandInfo_INTERFACE_DEFINED__ */


' ########################################################################################
' IDeskBand2 interface
' IID = 79D16DE4-ABEE-4021-8D9D-9169B261D657
' Inherited interface = IDeskBand
' ########################################################################################

#IF NOT %DEF(%IDeskBand2_INTERFACE_DEFINED)
    %IDeskBand2_INTERFACE_DEFINED = 1

$IID_IDeskBand2  = GUID$("{79D16DE4-ABEE-4021-8D9D-9169B261D657}")

INTERFACE IDeskBand2 $IID_IDeskBand2

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
   ' IDockingWindow methods
   ' =====================================================================================
   METHOD ShowDW ( _                                    ' VTable offset = 20
     BYVAL fShow AS LONG _                              ' __in BOOL fShow
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CloseDW ( _                                   ' VTable offset = 24
     BYVAL dwReserved AS DWORD _                        ' __in DWORD dwReserved
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ResizeBorderDW ( _                            ' VTable offset = 28
     BYREF prcBorder AS RECT _                          ' __in LPCRECT prcBorder
   , BYVAL punkToolbarSite AS IUnknown _                ' __in IUnknown *punkToolbarSite
   , BYVAL fReserved AS LONG _                          ' __in BOOL fReserved
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IDeskBand method
   ' =====================================================================================
   METHOD GetBandInfo ( _                               ' VTable offset = 32
     BYVAL dwBandID AS DWORD _                          ' __in DWORD dwBandID
   , BYVAL dwViewMode AS DWORD _                        ' __in DWORD dwViewMode
   , BYREF pdbi AS DESKBANDINFO _                       ' __inout DESKBANDINFO *pdbi
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IDeskBand2 methods
   ' =====================================================================================
   METHOD CanRenderComposited ( _                       ' VTable offset = 36
     BYREF pfCanRenderComposited AS LONG _              ' __out BOOL *pfCanRenderComposited
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetCompositionState ( _                       ' VTable offset = 40
     BYVAL fCompositionEnabled AS LONG _                ' __in BOOL fCompositionEnabled
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCompositionState ( _                       ' VTable offset = 44
     BYREF pfCompositionEnabled AS LONG _               ' __out BOOL *pfCompositionEnabled
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDeskBand2_INTERFACE_DEFINED__ */

'#endif  // NTDDI_VISTA


' ########################################################################################
' ITaskbarList interface
' IID = 56FDF342-FD6D-11D0-958A-006097C9A090
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ITaskbarList_INTERFACE_DEFINED)
    %ITaskbarList_INTERFACE_DEFINED = 1

$IID_ITaskbarList = GUID$("{56FDF342-FD6D-11D0-958A-006097C9A090}")

INTERFACE ITaskbarList $IID_ITaskbarList

   INHERIT IUnknown

   ' =====================================================================================
   METHOD HrInit ( _                                    ' VTable offset = 12
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddTab ( _                                    ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DeleteTab ( _                                 ' VTable offset = 20
     BYVAL hwnd AS DWORD _                              ' __in HWND hwnd
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ActivateTab ( _                               ' VTable offset = 24
     BYVAL hwnd AS DWORD _                              ' __in HWND hwnd
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetActiveAlt ( _                              ' VTable offset = 28
     BYVAL hwnd AS DWORD _                              ' __in HWND hwnd
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITaskbarList_INTERFACE_DEFINED__ */


' ########################################################################################
' ITaskbarList2 interface
' IID = 602D4995-B13A-429B-A66E-1935E44F4317
' Inherited interface = ITaskbarList
' ########################################################################################

#IF NOT %DEF(%ITaskbarList2_INTERFACE_DEFINED)
    %ITaskbarList2_INTERFACE_DEFINED = 1

$IID_ITaskbarList2 = GUID$("{602D4995-B13A-429B-A66E-1935E44F4317}")

INTERFACE ITaskbarList2 $IID_ITaskbarList2

   INHERIT IUnknown

   ' =====================================================================================
   ' ITaskbarList methods
   ' =====================================================================================
   METHOD HrInit ( _                                    ' VTable offset = 12
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddTab ( _                                    ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DeleteTab ( _                                 ' VTable offset = 20
     BYVAL hwnd AS DWORD _                              ' __in HWND hwnd
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ActivateTab ( _                               ' VTable offset = 24
     BYVAL hwnd AS DWORD _                              ' __in HWND hwnd
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetActiveAlt ( _                              ' VTable offset = 28
     BYVAL hwnd AS DWORD _                              ' __in HWND hwnd
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' ITaskbarList2 methods
   ' =====================================================================================
   METHOD MarkFullscreenWindow ( _                      ' VTable offset = 32
     BYVAL hwnd AS DWORD _                              ' __in HWND hwnd
   , BYVAL fFullscreen AS LONG _                        ' __in BOOL fFullscreen
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITaskbarList2_INTERFACE_DEFINED__ */

' enum THUMBBUTTONFLAGS
%THBF_ENABLED        = 0???
%THBF_DISABLED       = &H1???
%THBF_DISMISSONCLICK = &H2???
%THBF_NOBACKGROUND   = &H4???
%THBF_HIDDEN         = &H8???
%THBF_NONINTERACTIVE = &H10???

' enum THUMBBUTTONMASK
%THB_BITMAP  = &H1???
%THB_ICON    = &H2???
%THB_TOOLTIP = &H4???
%THB_FLAGS   = &H8???

'#include <pshpack8.h>
' // Size = 540 bytes
TYPE THUMBBUTTON DWORD
   dwMask  AS DWORD            ' THUMBBUTTONMASK
   iId     AS DWORD            ' UINT
   iBitmap AS DWORD            ' UINT
   hIcon   AS DWORD            ' HICON
   szTip   AS WSTRINGZ * 260   ' WCHAR
   dwFlags AS DWORD            ' THUMBBUTTONFLAGS
END TYPE

'#include <poppack.h>

%THBN_CLICKED = &H1800???

' ########################################################################################
' ITaskbarList3 interface
' IID = EA1AFB91-9E28-4B86-90E9-9E9F8A5EEFAF
' Inherited interface = ITaskbarList2
' ########################################################################################

#IF NOT %DEF(%ITaskbarList3_INTERFACE_DEFINED)
    %ITaskbarList3_INTERFACE_DEFINED = 1

' enum TBPFLAG
%TBPF_NOPROGRESS    = 0???
%TBPF_INDETERMINATE = &H1???
%TBPF_NORMAL        = &H2???
%TBPF_ERROR         = &H4???
%TBPF_PAUSED        = &H8???

$IID_ITaskbarList3 = GUID$("{EA1AFB91-9E28-4B86-90E9-9E9F8A5EEFAF}")

INTERFACE ITaskbarList3 $IID_ITaskbarList3

   INHERIT IUnknown

   ' =====================================================================================
   ' ITaskbarList methods
   ' =====================================================================================
   METHOD HrInit ( _                                    ' VTable offset = 12
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddTab ( _                                    ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DeleteTab ( _                                 ' VTable offset = 20
     BYVAL hwnd AS DWORD _                              ' __in HWND hwnd
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ActivateTab ( _                               ' VTable offset = 24
     BYVAL hwnd AS DWORD _                              ' __in HWND hwnd
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetActiveAlt ( _                              ' VTable offset = 28
     BYVAL hwnd AS DWORD _                              ' __in HWND hwnd
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' ITaskbarList2 methods
   ' =====================================================================================
   METHOD MarkFullscreenWindow ( _                      ' VTable offset = 32
     BYVAL hwnd AS DWORD _                              ' __in HWND hwnd
   , BYVAL fFullscreen AS LONG _                        ' __in BOOL fFullscreen
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' ITaskbarList3 methods
   ' =====================================================================================
   METHOD SetProgressValue ( _                          ' VTable offset = 36
     BYVAL hwnd AS DWORD _                              ' __in HWND hwnd
   , BYVAL ullCompleted AS QUAD _                       ' __in ULONGLONG ullCompleted
   , BYVAL ullTotal AS QUAD _                           ' __in ULONGLONG ullTotal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetProgressState ( _                          ' VTable offset = 40
     BYVAL hwnd AS DWORD _                              ' __in HWND hwnd
   , BYVAL tbpFlags AS DWORD _                          ' __in TBPFLAG tbpFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RegisterTab ( _                               ' VTable offset = 44
     BYVAL hwndTab AS DWORD _                           ' __in HWND hwndTab
   , BYVAL hwndMDI AS DWORD _                           ' __in HWND hwndMDI
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UnregisterTab ( _                             ' VTable offset = 48
     BYVAL hwndTab AS DWORD _                           ' __in HWND hwndTab
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetTabOrder ( _                               ' VTable offset = 52
     BYVAL hwndTab AS DWORD _                           ' __in HWND hwndTab
   , BYVAL hwndInsertBefore AS DWORD _                  ' __in HWND hwndInsertBefore
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetTabActive ( _                              ' VTable offset = 56
     BYVAL hwndTab AS DWORD _                           ' __in HWND hwndTab
   , BYVAL hwndMDI AS DWORD _                           ' __in HWND hwndMDI
   , BYVAL dwReserved AS DWORD _                        ' __in DWORD dwReserved
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ThumbBarAddButtons ( _                        ' VTable offset = 60
     BYVAL hwnd AS DWORD _                              ' __in HWND hwnd
   , BYVAL cButtons AS DWORD _                          ' __in UINT cButtons
   , BYREF pButton AS THUMBBUTTON _                     ' __in LPTHUMBBUTTON pButton
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ThumbBarUpdateButtons ( _                     ' VTable offset = 64
     BYVAL hwnd AS DWORD _                              ' __in HWND hwnd
   , BYVAL cButtons AS DWORD _                          ' __in UINT cButtons
   , BYREF pButton AS THUMBBUTTON _                     ' __in LPTHUMBBUTTON pButton
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ThumbBarSetImageList ( _                      ' VTable offset = 68
     BYVAL hwnd AS DWORD _                              ' __in HWND hwnd
   , BYVAL himl AS DWORD _                              ' __in_opt HIMAGELIST himl
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetOverlayIcon ( _                            ' VTable offset = 72
     BYVAL hwnd AS DWORD _                              ' __in HWND hwnd
   , BYVAL hIcon AS DWORD _                             ' __in HICON hIcon
   , BYREF pszDescription AS WSTRINGZ _                 ' __in_opt LPCWSTR pszDescription
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetThumbnailTooltip ( _                       ' VTable offset = 76
     BYVAL hwnd AS DWORD _                              ' __in HWND hwnd
   , BYREF pszTip AS WSTRINGZ _                         ' __in_opt LPCWSTR pszTip
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetThumbnailClip ( _                          ' VTable offset = 80
     BYVAL hwnd AS DWORD _                              ' __in HWND hwnd
   , BYREF prcClip AS RECT _                            ' __in RECT *prcClip
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITaskbarList3_INTERFACE_DEFINED__ */

' ########################################################################################
' ITaskbarList4 interface
' IID = C43DC798-95D1-4BEA-9030-BB99E2983A1A
' Inherited interface = ITaskbarList3
' ########################################################################################

#IF NOT %DEF(%ITaskbarList4_INTERFACE_DEFINED)
    %ITaskbarList4_INTERFACE_DEFINED = 1

' enum STPFLAG
%STPF_NONE                      = 0???
%STPF_USEAPPTHUMBNAILALWAYS     = &H1???
%STPF_USEAPPTHUMBNAILWHENACTIVE = &H2???
%STPF_USEAPPPEEKALWAYS          = &H4???
%STPF_USEAPPPEEKWHENACTIVE      = &H8???

$IID_ITaskbarList4 = GUID$("{C43DC798-95D1-4BEA-9030-BB99E2983A1A}")

INTERFACE ITaskbarList4 $IID_ITaskbarList4

   INHERIT IUnknown

   ' =====================================================================================
   ' ITaskbarList methods
   ' =====================================================================================
   METHOD HrInit ( _                                    ' VTable offset = 12
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddTab ( _                                    ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DeleteTab ( _                                 ' VTable offset = 20
     BYVAL hwnd AS DWORD _                              ' __in HWND hwnd
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ActivateTab ( _                               ' VTable offset = 24
     BYVAL hwnd AS DWORD _                              ' __in HWND hwnd
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetActiveAlt ( _                              ' VTable offset = 28
     BYVAL hwnd AS DWORD _                              ' __in HWND hwnd
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' ITaskbarList2 methods
   ' =====================================================================================
   METHOD MarkFullscreenWindow ( _                      ' VTable offset = 32
     BYVAL hwnd AS DWORD _                              ' __in HWND hwnd
   , BYVAL fFullscreen AS LONG _                        ' __in BOOL fFullscreen
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' ITaskbarList3 methods
   ' =====================================================================================
   METHOD SetProgressValue ( _                          ' VTable offset = 36
     BYVAL hwnd AS DWORD _                              ' __in HWND hwnd
   , BYVAL ullCompleted AS QUAD _                       ' __in ULONGLONG ullCompleted
   , BYVAL ullTotal AS QUAD _                           ' __in ULONGLONG ullTotal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetProgressState ( _                          ' VTable offset = 40
     BYVAL hwnd AS DWORD _                              ' __in HWND hwnd
   , BYVAL tbpFlags AS DWORD _                          ' __in TBPFLAG tbpFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RegisterTab ( _                               ' VTable offset = 44
     BYVAL hwndTab AS DWORD _                           ' __in HWND hwndTab
   , BYVAL hwndMDI AS DWORD _                           ' __in HWND hwndMDI
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UnregisterTab ( _                             ' VTable offset = 48
     BYVAL hwndTab AS DWORD _                           ' __in HWND hwndTab
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetTabOrder ( _                               ' VTable offset = 52
     BYVAL hwndTab AS DWORD _                           ' __in HWND hwndTab
   , BYVAL hwndInsertBefore AS DWORD _                  ' __in HWND hwndInsertBefore
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetTabActive ( _                              ' VTable offset = 56
     BYVAL hwndTab AS DWORD _                           ' __in HWND hwndTab
   , BYVAL hwndMDI AS DWORD _                           ' __in HWND hwndMDI
   , BYVAL dwReserved AS DWORD _                        ' __in DWORD dwReserved
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ThumbBarAddButtons ( _                        ' VTable offset = 60
     BYVAL hwnd AS DWORD _                              ' __in HWND hwnd
   , BYVAL cButtons AS DWORD _                          ' __in UINT cButtons
   , BYREF pButton AS THUMBBUTTON _                     ' __in LPTHUMBBUTTON pButton
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ThumbBarUpdateButtons ( _                     ' VTable offset = 64
     BYVAL hwnd AS DWORD _                              ' __in HWND hwnd
   , BYVAL cButtons AS DWORD _                          ' __in UINT cButtons
   , BYREF pButton AS THUMBBUTTON _                     ' __in LPTHUMBBUTTON pButton
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ThumbBarSetImageList ( _                      ' VTable offset = 68
     BYVAL hwnd AS DWORD _                              ' __in HWND hwnd
   , BYVAL himl AS DWORD _                              ' __in_opt HIMAGELIST himl
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetOverlayIcon ( _                            ' VTable offset = 72
     BYVAL hwnd AS DWORD _                              ' __in HWND hwnd
   , BYVAL hIcon AS DWORD _                             ' __in HICON hIcon
   , BYREF pszDescription AS WSTRINGZ _                 ' __in_opt LPCWSTR pszDescription
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetThumbnailTooltip ( _                       ' VTable offset = 76
     BYVAL hwnd AS DWORD _                              ' __in HWND hwnd
   , BYREF pszTip AS WSTRINGZ _                         ' __in_opt LPCWSTR pszTip
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetThumbnailClip ( _                          ' VTable offset = 80
     BYVAL hwnd AS DWORD _                              ' __in HWND hwnd
   , BYREF prcClip AS RECT _                            ' __in RECT *prcClip
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' ITaskbarList4 methods
   ' =====================================================================================
   METHOD SetTabProperties ( _                          ' VTable offset = 84
     BYVAL hwndTab AS DWORD _                           ' __in HWND hwndTab
   , BYVAL stpFlags AS DWORD _                          ' __in STPFLAG stpFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITaskbarList4_INTERFACE_DEFINED__ */


' ########################################################################################
' IStartMenuPinnedList interface
' IID = 4CD19ADA-25A5-4A32-B3B7-347BEE5BE36B
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IStartMenuPinnedList_INTERFACE_DEFINED)
    %IStartMenuPinnedList_INTERFACE_DEFINED = 1

$IID_IStartMenuPinnedList = GUID$("{4CD19ADA-25A5-4A32-B3B7-347BEE5BE36B}")

INTERFACE IStartMenuPinnedList $IID_IStartMenuPinnedList

   INHERIT IUnknown

   ' =====================================================================================
   METHOD RemoveFromList ( _                            ' VTable offset = 12
     BYVAL pitem AS IShellItem _                        ' __in IShellItem *pitem
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IStartMenuPinnedList_INTERFACE_DEFINED__ */


' ########################################################################################
' ICDBurn interface
' IID = 3D73A659-E5D0-4D42-AFC0-5121BA425C8D
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ICDBurn_INTERFACE_DEFINED)
    %ICDBurn_INTERFACE_DEFINED = 1

$IID_ICDBurn = GUID$("{3D73A659-E5D0-4D42-AFC0-5121BA425C8D}")

INTERFACE ICDBurn $IID_ICDBurn

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetRecorderDriveLetter ( _                    ' VTable offset = 12
     BYREF pszDrive AS WSTRINGZ _                       ' __out LPWSTR pszDrive
   , BYVAL cch AS DWORD _                               ' __in UINT cch
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Burn ( _                                      ' VTable offset = 16
     BYVAL hwnd AS DWORD _                              ' __in HWND hwnd
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD HasRecordableDrive ( _                        ' VTable offset = 20
     BYREF pfHasRecorder AS LONG _                      ' __out BOOL *pfHasRecorder
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICDBurn_INTERFACE_DEFINED__ */


%IDD_WIZEXTN_FIRST = &H5000???
%IDD_WIZEXTN_LAST  = &H5100???


' ########################################################################################
' IWizardSite interface
' IID = 88960F5B-422F-4E7B-8013-73415381C3C3
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IWizardSite_INTERFACE_DEFINED)
    %IWizardSite_INTERFACE_DEFINED = 1

$IID_IWizardSite = GUID$("{88960F5B-422F-4E7B-8013-73415381C3C3}")
$SID_WizardSite = $IID_IWizardSite

INTERFACE IWizardSite $IID_IWizardSite

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetPreviousPage ( _                           ' VTable offset = 12
     BYREF phpage AS DWORD _                            ' __out HPROPSHEETPAGE *phpage
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetNextPage ( _                               ' VTable offset = 16
     BYREF phpage AS DWORD _                            ' __out HPROPSHEETPAGE *phpage
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCancelledPage ( _                          ' VTable offset = 20
     BYREF phpage AS DWORD _                            ' __out HPROPSHEETPAGE *phpage
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWizardSite_INTERFACE_DEFINED__ */


' ########################################################################################
' IWizardExtension interface
' IID = C02EA696-86CC-491E-9B23-74394A0444A8
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IWizardExtension_INTERFACE_DEFINED)
    %IWizardExtension_INTERFACE_DEFINED = 1

$IID_IWizardExtension = GUID$("{C02EA696-86CC-491E-9B23-74394A0444A8}")

INTERFACE IWizardExtension $IID_IWizardExtension

   INHERIT IUnknown

   ' =====================================================================================
   METHOD AddPages ( _                                  ' VTable offset = 12
     BYREF aPages AS DWORD _                            ' __inout HPROPSHEETPAGE *aPages
   , BYVAL cPages AS DWORD _                            ' __in UINT cPages
   , BYREF pnPagesAdded AS DWORD _                      ' __out UINT *pnPagesAdded
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFirstPage ( _                              ' VTable offset = 16
     BYREF phpage AS DWORD _                            ' __out HPROPSHEETPAGE *phpage
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetLastPage ( _                               ' VTable offset = 20
     BYREF phpage AS DWORD _                            ' __out HPROPSHEETPAGE *phpage
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWizardExtension_INTERFACE_DEFINED__ */


' ########################################################################################
' IWebWizardExtension interface
' IID = 0E6B3F66-98D1-48C0-A222-FBDE74E2FBC5
' Inherited interface = IWizardExtension
' ########################################################################################

#IF NOT %DEF(%IWebWizardExtension_INTERFACE_DEFINED)
    %IWebWizardExtension_INTERFACE_DEFINED = 1

$IID_IWebWizardExtension = GUID$("{0E6B3F66-98D1-48C0-A222-FBDE74E2FBC5}")
$SID_IWebWizardExtension = GUID$("{0E6B3F66-98D1-48C0-A222-FBDE74E2FBC5}")
$SID_WebWizardHost       = GUID$("{0E6B3F66-98D1-48C0-A222-FBDE74E2FBC5}")

INTERFACE IWebWizardExtension $IID_IWebWizardExtension

   INHERIT IUnknown

   ' =====================================================================================
   ' IWizardExtension Methods
   ' =====================================================================================
   METHOD AddPages ( _                                  ' VTable offset = 12
     BYREF aPages AS DWORD _                            ' __inout HPROPSHEETPAGE *aPages
   , BYVAL cPages AS DWORD _                            ' __in UINT cPages
   , BYREF pnPagesAdded AS DWORD _                      ' __out UINT *pnPagesAdded
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFirstPage ( _                              ' VTable offset = 16
     BYREF phpage AS DWORD _                            ' __out HPROPSHEETPAGE *phpage
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetLastPage ( _                               ' VTable offset = 20
     BYREF phpage AS DWORD _                            ' __out HPROPSHEETPAGE *phpage
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IWizardExtension2 Methods
   ' =====================================================================================
   METHOD SetInitialURL ( _                             ' VTable offset = 12
     BYREF pszURL AS WSTRINGZ _                         ' __in LPCWSTR pszURL
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetErrorURL ( _                               ' VTable offset = 16
     BYREF pszErrorURL AS WSTRINGZ _                    ' __in LPCWSTR pszErrorURL
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IWebWizardExtension_INTERFACE_DEFINED__ */


%SHPWHF_NORECOMPRESS          = &H00000001???  ' // don't allow/prompt for recompress of streams
%SHPWHF_NONETPLACECREATE      = &H00000002???  ' // don't create a network place when transfer is complete
%SHPWHF_NOFILESELECTOR        = &H00000004???  ' // don't show the file selector
%SHPWHF_USEMRU                = &H00000008???  ' // For OPW.  Use the Most-Recently-Used Print Provider
'#if (NTDDI_VERSION >= NTDDI_VISTA)
%SHPWHF_ANYLOCATION           = &H00000100???  ' // allow publishing to any location
'#endif  // NTDDI_VISTA
%SHPWHF_VALIDATEVIAWEBFOLDERS = &H00010000???  ' // enable web folders to validate network places (ANP support)


' ########################################################################################
' IPublishingWizard interface
' IID = AA9198BB-CCEC-472D-BEED-19A4F6733F7A
' Inherited interface = IWizardExtension
' ########################################################################################

#IF NOT %DEF(%IPublishingWizard_INTERFACE_DEFINED)
    %IPublishingWizard_INTERFACE_DEFINED = 1

$IID_IPublishingWizard = GUID$("{AA9198BB-CCEC-472D-BEED-19A4F6733F7A}")

INTERFACE IPublishingWizard $IID_IPublishingWizard

   INHERIT IUnknown

   ' =====================================================================================
   ' IWizardExtension Methods
   ' =====================================================================================
   METHOD AddPages ( _                                  ' VTable offset = 12
     BYREF aPages AS DWORD _                            ' __inout HPROPSHEETPAGE *aPages
   , BYVAL cPages AS DWORD _                            ' __in UINT cPages
   , BYREF pnPagesAdded AS DWORD _                      ' __out UINT *pnPagesAdded
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFirstPage ( _                              ' VTable offset = 16
     BYREF phpage AS DWORD _                            ' __out HPROPSHEETPAGE *phpage
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetLastPage ( _                               ' VTable offset = 20
     BYREF phpage AS DWORD _                            ' __out HPROPSHEETPAGE *phpage
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IPublishingWizard Methods
   ' =====================================================================================
   METHOD Initialize ( _                                ' VTable offset = 20
     BYVAL pdo AS IDataObject _                         ' __in IDataObject *pdo
   , BYVAL dwOptions AS DWORD _                         ' __in DWORD dwOptions
   , BYREF pszServiceProvider AS WSTRINGZ _             ' __in LPCWSTR pszServiceProvider
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetTransferManifest ( _                       ' VTable offset = 24
     BYREF phrFromTransfer AS LONG _                    ' __out HRESULT *phrFromTransfer
   , BYREF pdocManifest AS IXMLDOMDocument _            ' __out IXMLDOMDocument **pdocManifest
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IPublishingWizard_INTERFACE_DEFINED__ */


'#if (NTDDI_VERSION >= NTDDI_WINXP) || (_WIN32_IE >= _WIN32_IE_IE70)

' ########################################################################################
' IFolderViewHost interface
' IID = 1EA58F02-D55A-411D-B09E-9E65AC21605B
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IFolderViewHost_INTERFACE_DEFINED)
    %IFolderViewHost_INTERFACE_DEFINED = 1

$IID_IFolderViewHost = GUID$("{1EA58F02-D55A-411D-B09E-9E65AC21605B}")

INTERFACE IFolderViewHost $IID_IFolderViewHost

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Initialize ( _                                ' VTable offset = 12
     BYVAL hwndParent AS DWORD _                        ' __in HWND hwndParent
   , BYVAL pdo AS IDataObject _                         ' __in IDataObject *pdo
   , BYREF prc AS RECT _                                ' __in RECT *prc
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IFolderViewHost_INTERFACE_DEFINED__ */

'#if (_WIN32_IE >= _WIN32_IE_IE70)

' ########################################################################################
' IExplorerBrowserEvents interface
' IID = 361BBDC7-E6EE-4E13-BE58-58E2240C810F
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IExplorerBrowserEvents_INTERFACE_DEFINED)
    %IExplorerBrowserEvents_INTERFACE_DEFINED = 1

$IID_IExplorerBrowserEvents = GUID$("{361BBDC7-E6EE-4E13-BE58-58E2240C810F}")

INTERFACE IExplorerBrowserEvents $IID_IExplorerBrowserEvents

   INHERIT IUnknown

   ' =====================================================================================
   METHOD OnNavigationPending ( _                       ' VTable offset = 12
     BYVAL pidlFolder AS DWORD _                        ' __in PCIDLIST_ABSOLUTE pidlFolder
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnViewCreated ( _                             ' VTable offset = 16
     BYVAL psv AS IShellView _                          ' __in IShellView *psv
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnNavigationComplete ( _                      ' VTable offset = 20
     BYVAL pidlFolder AS DWORD _                        ' __in PCIDLIST_ABSOLUTE pidlFolder
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnNavigationFailed ( _                        ' VTable offset = 24
     BYVAL pidlFolder AS DWORD _                        ' __in PCIDLIST_ABSOLUTE pidlFolder
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IExplorerBrowserEvents_INTERFACE_DEFINED__ */

' enum EXPLORER_BROWSER_OPTIONS
%EBO_NONE                 = 0???
%EBO_NAVIGATEONCE         = &H1???
%EBO_SHOWFRAMES           = &H2???
%EBO_ALWAYSNAVIGATE       = &H4???
%EBO_NOTRAVELLOG          = &H8???
%EBO_NOWRAPPERWINDOW      = &H10???
%EBO_HTMLSHAREPOINTVIEW   = &H20???
'typedef DWORD EXPLORER_BROWSER_OPTIONS;

' enum EXPLORER_BROWSER_FILL_FLAGS
%EBF_NONE                 = 0???
%EBF_SELECTFROMDATAOBJECT = &H100???
%EBF_NODROPTARGET         = &H200???
'typedef DWORD EXPLORER_BROWSER_FILL_FLAGS;


' ########################################################################################
' IExplorerBrowser interface
' IID = DFD3B6B5-C10C-4BE9-85F6-A66969F402F6
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IExplorerBrowser_INTERFACE_DEFINED)
    %IExplorerBrowser_INTERFACE_DEFINED = 1

$IID_IExplorerBrowser = GUID$("{DFD3B6B5-C10C-4BE9-85F6-A66969F402F6}")

INTERFACE IExplorerBrowser $IID_IExplorerBrowser

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Initialize ( _                                ' VTable offset = 12
     BYVAL hwndParent AS DWORD _                        ' __in HWND hwndParent
   , BYREF prc AS RECT _                                ' __in const RECT *prc
   , BYREF pfs AS FOLDERSETTINGS _                      ' __in const FOLDERSETTINGS *pfs
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Destroy ( _                                   ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetRect ( _                                   ' VTable offset = 20
     BYREF phdwp AS DWORD _                             ' __inout HDWP *phdwp
   , BYVAL rcBrowser AS RECT _                          ' __in RECT rcBrowser
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPropertyBag ( _                            ' VTable offset = 24
     BYREF pszPropertyBag AS WSTRINGZ _                 ' __in LPCWSTR pszPropertyBag
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetEmptyText ( _                              ' VTable offset = 28
     BYREF pszEmptyText AS WSTRINGZ _                   ' __in LPCWSTR pszEmptyText
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetFolderSettings ( _                         ' VTable offset = 32
     BYREF pfs AS FOLDERSETTINGS _                      ' __in const FOLDERSETTINGS *pfs
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Advise ( _                                    ' VTable offset = 36
     BYVAL psbe AS IExplorerBrowserEvents _             ' __in IExplorerBrowserEvents *psbe
   , BYREF pdwCookie AS DWORD _                         ' __out DWORD *pdwCookie
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Unadvise ( _                                  ' VTable offset = 40
     BYVAL dwCookie AS DWORD _                          ' __in DWORD dwCookie
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetOptions ( _                                ' VTable offset = 44
     BYVAL dwFlag AS DWORD _                            ' __in EXPLORER_BROWSER_OPTIONS dwFlag
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetOptions ( _                                ' VTable offset = 48
     BYREF pdwFlag AS DWORD _                           ' __out EXPLORER_BROWSER_OPTIONS *pdwFlag
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD BrowseToIDList ( _                            ' VTable offset = 52
     BYVAL pidl AS DWORD _                              ' __in PCUIDLIST_RELATIVE pidl
   , BYVAL uFlags AS DWORD _                            ' __in UINT uFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD BrowseToObject ( _                            ' VTable offset = 56
     BYVAL punk AS IUnknown _                           ' __in IUnknown *punk
   , BYVAL uFlags AS DWORD _                            ' __in UINT uFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD FillFromObject ( _                            ' VTable offset = 60
     BYVAL punk AS IUnknown _                           ' __in IUnknown *punk
   , BYVAL dwFlags AS DWORD _                           ' __in EXPLORER_BROWSER_FILL_FLAGS dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RemoveAll ( _                                 ' VTable offset = 64
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCurrentView ( _                            ' VTable offset = 68
     BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppv AS IUnknown _                            ' __out void **ppv
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IExplorerBrowser_INTERFACE_DEFINED__ */

' ########################################################################################
' IAccessibleObject interface
' IID = 95A391C5-9ED4-4C28-8401-AB9E06719E11
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IAccessibleObject_INTERFACE_DEFINED)
    %IAccessibleObject_INTERFACE_DEFINED = 1

$IID_IAccessibleObject = GUID$("{95A391C5-9ED4-4C28-8401-AB9E06719E11}")

INTERFACE IAccessibleObject $IID_IAccessibleObject

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetAccessibleName ( _                         ' VTable offset = 12
     BYREF pszName AS WSTRINGZ _                        ' __in LPCWSTR pszName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAccessibleObject_INTERFACE_DEFINED__ */

'#endif  // (_WIN32_IE >= _WIN32_IE_IE70)

' ########################################################################################
' IResultsFolder interface
' IID = 96E5AE6D-6AE1-4B1C-900C-C6480EAA8828
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IResultsFolder_INTERFACE_DEFINED)
    %IResultsFolder_INTERFACE_DEFINED = 1

$IID_IResultsFolder = GUID$("{96E5AE6D-6AE1-4B1C-900C-C6480EAA8828}")

INTERFACE IResultsFolder $IID_IResultsFolder

   INHERIT IUnknown

   ' =====================================================================================
   METHOD AddItem ( _                                   ' VTable offset = 12
     BYVAL psi AS IShellItem _                          ' __in IShellItem *psi
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddIDList ( _                                 ' VTable offset = 16
     BYVAL pidl AS DWORD _                              ' __in PCIDLIST_ABSOLUTE pidl
   , BYREF ppidlAdded AS DWORD _                        ' __out PITEMID_CHILD *ppidlAdded
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RemoveItem ( _                                ' VTable offset = 20
     BYVAL psi AS IShellItem _                          ' __in IShellItem *psi
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RemoveIDList ( _                              ' VTable offset = 24
     BYVAL pidl AS DWORD _                              ' __in PCIDLIST_ABSOLUTE pidl
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RemoveAll ( _                                 ' VTable offset = 28
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IResultsFolder_INTERFACE_DEFINED__ */

'#if (_WIN32_IE >= _WIN32_IE_IE70)

' ########################################################################################
' IEnumObjects interface
' IID = 2C1C7E2E-2D0E-4059-831E-1E6F82335C2E
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IEnumObjects_INTERFACE_DEFINED)
    %IEnumObjects_INTERFACE_DEFINED = 1

$IID_IEnumObjects = GUID$("{2C1C7E2E-2D0E-4059-831E-1E6F82335C2E}")

INTERFACE IEnumObjects $IID_IEnumObjects

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Next ( _                                      ' VTable offset = 12
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF rgelt AS IUnknown _                          ' __out void **rgelt
   , BYREF pceltFetched AS DWORD _                      ' __out ULONG *pceltFetched
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Skip ( _                                      ' VTable offset = 16
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reset ( _                                     ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 24
     BYREF ppenum AS IEnumObjects _                     ' __out IEnumObjects **ppenum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEnumObjects_INTERFACE_DEFINED__ */

%OPPROGDLG_ENABLEPAUSE           = &H80???    ' // Add a pause button (operation can be paused)
%OPPROGDLG_ALLOWUNDO             = &H100???   ' // The operation can be undone in the dialog.  (The Stop button becomes Undo)
%OPPROGDLG_DONTDISPLAYSOURCEPATH = &H200???   ' // Don't display the path of source file in progress dialog
%OPPROGDLG_DONTDISPLAYDESTPATH   = &H400???   ' // Don't display the path of destination file in progress dialog
%OPPROGDLG_NOMULTIDAYESTIMATES   = &H800???
%OPPROGDLG_DONTDISPLAYLOCATIONS  = &H1000???


' ########################################################################################
' IOperationsProgressDialog interface
' IID = 0C9FB851-E5C9-43EB-A370-F0677B13874C
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IOperationsProgressDialog_INTERFACE_DEFINED)
    %IOperationsProgressDialog_INTERFACE_DEFINED = 1

$IID_IOperationsProgressDialog = GUID$("{0C9FB851-E5C9-43EB-A370-F0677B13874C}")

' enum PDMODE
%PDM_RUN            = &H1???
%PDM_PREFLIGHT      = &H2???
%PDM_UNDOING        = &H4???
%PDM_ERRORSBLOCKING = &H8???
%PDM_INDETERMINATE  = &H10???
'typedef DWORD PDMODE;

' enum PDOPSTATUS
%PDOPS_RUNNING      = 1
%PDOPS_PAUSED       = 2
%PDOPS_CANCELLED    = 3
%PDOPS_STOPPED      = 4
%PDOPS_ERRORS       = 5

INTERFACE IOperationsProgressDialog $IID_IOperationsProgressDialog

   INHERIT IUnknown

   ' =====================================================================================
   METHOD StartProgressDialog ( _                       ' VTable offset = 12
     BYVAL hwndParent AS DWORD _                        ' __in HWND hwndParent
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD StopProgressDialog ( _                        ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetOperation ( _                              ' VTable offset = 20
     BYVAL action AS LONG _                             ' __in SPACTION action
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetMode ( _                                   ' VTable offset = 24
     BYVAL mode AS DWORD _                              ' __in PDMODE mode
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UpdateProgress ( _                            ' VTable offset = 28
     BYVAL ullPointsCurrent AS QUAD _                   ' __in ULONGLONG ullPointsCurrent
   , BYVAL ullPointsTotal AS QUAD _                     ' __in ULONGLONG ullPointsTotal
   , BYVAL ullSizeCurrent AS QUAD _                     ' __in ULONGLONG ullSizeCurrent
   , BYVAL ullSizeTotal AS QUAD _                       ' __in ULONGLONG ullSizeTotal
   , BYVAL ullItemsCurrent AS QUAD _                    ' __in ULONGLONG ullItemsCurrent
   , BYVAL ullItemsTotal AS QUAD _                      ' __in ULONGLONG ullItemsTotal
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UpdateLocations ( _                           ' VTable offset = 32
     BYVAL psiSource AS IShellItem _                    ' __in IShellItem *psiSource
   , BYVAL psiTarget AS IShellItem _                    ' __in IShellItem *psiTarget
   , BYVAL psiItem AS IShellItem _                      ' __in IShellItem *psiItem
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ResetTimer ( _                                ' VTable offset = 36
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD PauseTimer ( _                                ' VTable offset = 40
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ResumeTimer ( _                               ' VTable offset = 44
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMilliseconds ( _                           ' VTable offset = 48
     BYREF pullElapsed AS QUAD _                        ' __out ULONGLONG *pullElapsed
   , BYREF pullRemaining AS QUAD _                      ' __out ULONGLONG *pullRemaining
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetOperationStatus ( _                        ' VTable offset = 52
     BYREF popstatus AS DWORD _                         ' __out PDOPSTATUS *popstatus
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IOperationsProgressDialog_INTERFACE_DEFINED__ */


' ########################################################################################
' IOperationsUpdateProgress interface
' IID = B5256C5C-F918-49E6-BBB7-A3C254C09FDF
' Inherited interface = IUnknown
' Removed in the Windows 7 SDK
' ########################################################################################

'#IF NOT %DEF(%IOperationsUpdateProgress_INTERFACE_DEFINED)
'    %IOperationsUpdateProgress_INTERFACE_DEFINED = 1

'$IID_IOperationsUpdateProgress = GUID$("{B5256C5C-F918-49E6-BBB7-A3C254C09FDF}")

'INTERFACE IOperationsUpdateProgress $IID_IOperationsUpdateProgress

'   INHERIT IUnknown

'   ' =====================================================================================
'   METHOD AddTreeDone ( _                               ' VTable offset = 12
'     BYVAL iFiles AS LONG _                             ' __in int iFiles
'   , BYVAL iFolders AS LONG _                           ' __in int iFolders
'   , BYVAL llSize AS QUAD _                             ' __in LONGLONG llSize
'   , BYVAL iPoints AS LONG _                            ' __in int iPoints
'   ) AS LONG                                            ' HRESULT
'   ' =====================================================================================
'   METHOD AddTreeTotal ( _                              ' VTable offset = 16
'     BYVAL iFiles AS LONG _                             ' __in int iFiles
'   , BYVAL iFolders AS LONG _                           ' __in int iFolders
'   , BYVAL llSize AS QUAD _                             ' __in LONGLONG llSize
'   , BYVAL iPoints AS LONG _                            ' __in int iPoints
'   ) AS LONG                                            ' HRESULT
'   ' =====================================================================================

'END INTERFACE

'#ENDIF   ' /* __IOperationsUpdateProgress_INTERFACE_DEFINED__ */


' ########################################################################################
' IIOCancelInformation interface
' IID = F5B0BF81-8CB5-4B1B-9449-1A159E0C733C
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IIOCancelInformation_INTERFACE_DEFINED)
    %IIOCancelInformation_INTERFACE_DEFINED = 1

$IID_IIOCancelInformation = GUID$("{F5B0BF81-8CB5-4B1B-9449-1A159E0C733C}")

INTERFACE IIOCancelInformation $IID_IIOCancelInformation

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetCancelInformation ( _                      ' VTable offset = 12
     BYVAL dwThreadID AS DWORD _                        ' __in DWORD dwThreadID
   , BYVAL uMsgCancel AS DWORD _                        ' __in UINT uMsgCancel
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCancelInformation ( _                      ' VTable offset = 16
     BYREF pdwThreadID AS DWORD _                       ' __out DWORD *pdwThreadID
   , BYREF puMsgCancel AS DWORD _                       ' __out UINT *puMsgCancel
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IIOCancelInformation_INTERFACE_DEFINED__ */

%FOFX_NOSKIPJUNCTIONS         = &H00010000???  ' // Don't avoid binding to junctions (like Task folder, Recycle-Bin)
%FOFX_PREFERHARDLINK          = &H00020000???  ' // Create hard link if possible
%FOFX_SHOWELEVATIONPROMPT     = &H00040000???  ' // Show elevation prompts when error UI is disabled (use with FOF_NOERRORUI)
%FOFX_EARLYFAILURE            = &H00100000???  ' // Fail operation as soon as a single error occurs rather than trying to process other items (applies only when using FOF_NOERRORUI)
%FOFX_PRESERVEFILEEXTENSIONS  = &H00200000???  ' // Rename collisions preserve file extns (use with FOF_RENAMEONCOLLISION)
%FOFX_KEEPNEWERFILE           = &H00400000???  ' // Keep newer file on naming conflicts
%FOFX_NOCOPYHOOKS             = &H00800000???  ' // Don't use copy hooks
%FOFX_NOMINIMIZEBOX           = &H01000000???  ' // Don't allow minimizing the progress dialog
%FOFX_MOVEACLSACROSSVOLUMES   = &H02000000???  ' // Copy security information when performing a cross-volume move operation
%FOFX_DONTDISPLAYSOURCEPATH   = &H04000000???  ' // Don't display the path of source file in progress dialog
%FOFX_DONTDISPLAYDESTPATH     = &H08000000???  ' // Don't display the path of destination file in progress dialog
%FOFX_REQUIREELEVATION        = &H10000000???  ' // User expects the elevation; don't show a dialog to confirm
%FOFX_COPYASDOWNLOAD          = &H40000000???  ' // Show Downloading instead of Copying
%FOFX_DONTDISPLAYLOCATIONS    = &H80000000???  ' // Hides the locations line in the progress dialog

' ########################################################################################
' IFileOperation interface
' IID = 947AAB5F-0A5C-4C13-B4D6-4BF7836FC9F8
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IFileOperation_INTERFACE_DEFINED)
    %IFileOperation_INTERFACE_DEFINED = 1

$IID_IFileOperation = GUID$("{947AAB5F-0A5C-4C13-B4D6-4BF7836FC9F8}")

INTERFACE IFileOperation $IID_IFileOperation

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Advise ( _                                    ' VTable offset = 12
     BYVAL pfops AS IFileOperationProgressSink _        ' __in IFileOperationProgressSink *pfops
   , BYREF pdwCookie AS DWORD _                         ' __out DWORD *pdwCookie
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Unadvise ( _                                  ' VTable offset = 16
     BYVAL dwCookie AS DWORD _                          ' __in DWORD dwCookie
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetOperationFlags ( _                         ' VTable offset = 20
     BYVAL dwOperationFlags AS DWORD _                  ' __in DWORD dwOperationFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetProgressMessage ( _                        ' VTable offset = 24
     BYREF pszMessage AS WSTRINGZ _                     ' __in LPCWSTR pszMessage
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetProgressDialog ( _                         ' VTable offset = 28
     BYVAL popd AS IOperationsProgressDialog _          ' __in IOperationsProgressDialog *popd
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetProperties ( _                             ' VTable offset = 32
     BYVAL pproparray AS IPropertyChangeArray _         ' __in IPropertyChangeArray *pproparray
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetOwnerWindow ( _                            ' VTable offset = 36
     BYVAL hwndParent AS DWORD _                        ' __in HWND hwndParent
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ApplyPropertiesToItem ( _                     ' VTable offset = 40
     BYVAL psiItem AS IShellItem _                      ' __in IShellItem *psiItem
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ApplyPropertiesToItems ( _                    ' VTable offset = 44
     BYVAL punkItems AS IUnknown _                      ' __in IUnknown *punkItems
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RenameItem ( _                                ' VTable offset = 48
     BYVAL psiItem AS IShellItem _                      ' __in IShellItem *psiItem
   , BYREF pszNewName AS WSTRINGZ _                     ' __in LPCWSTR pszNewName
   , BYVAL pfopsItem AS IUnknown _                      ' __in IFileOperationProgressSink *pfopsItem
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RenameItems ( _                               ' VTable offset = 52
     BYVAL pUnkItems AS IUnknown _                      ' __in IUnknown *pUnkItems
   , BYREF pszNewName AS WSTRINGZ _                     ' __in LPCWSTR pszNewName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD MoveItem ( _                                  ' VTable offset = 56
     BYVAL psiItem AS IShellItem _                      ' __in IShellItem *psiItem
   , BYVAL psiDestinationFolder AS IShellItem _         ' __in IShellItem *psiDestinationFolder
   , BYREF pszNewName AS WSTRINGZ _                     ' __in LPCWSTR pszNewName
   , BYVAL pfopsItem AS IFileOperationProgressSink _    ' __in IFileOperationProgressSink *pfopsItem
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD MoveItems ( _                                 ' VTable offset = 60
     BYVAL punkItems AS IUnknown _                      ' __in IUnknown *punkItems
   , BYVAL psiDestinationFolder AS IShellItem _         ' __in IShellItem *psiDestinationFolder
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CopyItem ( _                                  ' VTable offset = 64
     BYVAL psiItem AS IShellItem _                      ' __in IShellItem *psiItem
   , BYVAL psiDestinationFolder AS IShellItem _         ' __in IShellItem *psiDestinationFolder
   , BYREF pszCopyName AS WSTRINGZ _                    ' __in LPCWSTR pszCopyName
   , BYVAL pfopsItem AS IFileOperationProgressSink _    ' __in IFileOperationProgressSink *pfopsItem
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CopyItems ( _                                 ' VTable offset = 68
     BYVAL punkItems AS IUnknown _                      ' __in IUnknown *punkItems
   , BYVAL psiDestinationFolder AS IShellItem _         ' __in IShellItem *psiDestinationFolder
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DeleteItem ( _                                ' VTable offset = 72
     BYVAL psiItem AS IShellItem _                      ' __in IShellItem *psiItem
   , BYVAL pfopsItem AS IFileOperationProgressSink _    ' __in IFileOperationProgressSink *pfopsItem
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DeleteItems ( _                               ' VTable offset = 76
     BYVAL punkItems AS IUnknown _                      ' __in IUnknown *punkItems
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD NewItem ( _                                   ' VTable offset = 80
     BYVAL psiDestinationFolder AS IShellItem _         ' __in IShellItem *psiDestinationFolder
   , BYVAL dwFileAttributes AS DWORD _                  ' __in DWORD dwFileAttributes
   , BYREF pszName AS WSTRINGZ _                        ' __in LPCWSTR pszName
   , BYREF pszTemplateName AS WSTRINGZ _                ' __in LPCWSTR pszTemplateName
   , BYVAL pfopsItem AS IFileOperationProgressSink _    ' __in IFileOperationProgressSink *pfopsItem
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD PerformOperations ( _                         ' VTable offset = 84
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAnyOperationsAborted ( _                   ' VTable offset = 88
     BYREF pfAnyOperationsAborted AS LONG _             ' __out BOOL *pfAnyOperationsAborted
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IFileOperation_INTERFACE_DEFINED__ */


' ########################################################################################
' IObjectProvider interface
' IID = A6087428-3BE3-4D73-B308-7C04A540BF1A
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IObjectProvider_INTERFACE_DEFINED)
    %IObjectProvider_INTERFACE_DEFINED = 1

$IID_IObjectProvider = GUID$("{A6087428-3BE3-4D73-B308-7C04A540BF1A}")

INTERFACE IObjectProvider $IID_IObjectProvider

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetCancelInformation ( _                      ' VTable offset = 12
     BYREF guidObject AS GUID _                         ' __in REFGUID guidObject
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppvOut AS IUnknown _                         ' __out void **ppvOut
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IObjectProvider_INTERFACE_DEFINED__ */

'#endif  // (_WIN32_IE >= _WIN32_IE_IE70)

' ########################################################################################
' INamespaceWalkCB interface
' IID = D92995F8-CF5E-4A76-BF59-EAD39EA2B97E
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%INamespaceWalkCB_INTERFACE_DEFINED)
    %INamespaceWalkCB_INTERFACE_DEFINED = 1

$IID_INamespaceWalkCB = GUID$("{D92995F8-CF5E-4A76-BF59-EAD39EA2B97E}")

INTERFACE INamespaceWalkCB $IID_INamespaceWalkCB

   INHERIT IUnknown

   ' =====================================================================================
   METHOD FoundItem ( _                                 ' VTable offset = 12
     BYVAL psf AS IShellFolder _                        ' __in IShellFolder *psf
   , BYVAL pidl AS DWORD _                              ' __in PCUITEMID_CHILD pidl
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnterFolder ( _                               ' VTable offset = 16
     BYVAL psf AS IShellFolder _                        ' __in IShellFolder *psf
   , BYVAL pidl AS DWORD _                              ' __in PCUITEMID_CHILD pidl
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD LeaveFolder ( _                               ' VTable offset = 20
     BYVAL psf AS IShellFolder _                        ' __in IShellFolder *psf
   , BYVAL pidl AS DWORD _                              ' __in PCUITEMID_CHILD pidl
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD InitializeProgressDialog ( _                  ' VTable offset = 24
     BYREF ppszTitle AS DWORD _                         ' __out LPWSTR *ppszTitle
   , BYREF ppszCancel AS DWORD _                        ' __out LPWSTR *ppszCancel
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __INamespaceWalkCB_INTERFACE_DEFINED__ */

'#if (_WIN32_IE >= _WIN32_IE_IE70)

' ########################################################################################
' INamespaceWalkCB2 interface
' IID = 7AC7492B-C38E-438A-87DB-68737844FF70
' Inherited interface = INamespaceWalkCB
' ########################################################################################

#IF NOT %DEF(%INamespaceWalkCB2_INTERFACE_DEFINED)
    %INamespaceWalkCB2_INTERFACE_DEFINED = 1

$IID_INamespaceWalkCB2 = GUID$("{7AC7492B-C38E-438A-87DB-68737844FF70}")

INTERFACE INamespaceWalkCB2 $IID_INamespaceWalkCB2

   INHERIT IUnknown

   ' =====================================================================================
   ' INamespaceWalkCB Methods
   ' =====================================================================================
   METHOD FoundItem ( _                                 ' VTable offset = 12
     BYVAL psf AS IShellFolder _                        ' __in IShellFolder *psf
   , BYVAL pidl AS DWORD _                              ' __in PCUITEMID_CHILD pidl
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnterFolder ( _                               ' VTable offset = 16
     BYVAL psf AS IShellFolder _                        ' __in IShellFolder *psf
   , BYVAL pidl AS DWORD _                              ' __in PCUITEMID_CHILD pidl
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD LeaveFolder ( _                               ' VTable offset = 20
     BYVAL psf AS IShellFolder _                        ' __in IShellFolder *psf
   , BYVAL pidl AS DWORD _                              ' __in PCUITEMID_CHILD pidl
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD InitializeProgressDialog ( _                  ' VTable offset = 24
     BYREF ppszTitle AS DWORD _                         ' __out LPWSTR *ppszTitle
   , BYREF ppszCancel AS DWORD _                        ' __out LPWSTR *ppszCancel
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' INamespaceWalkCB2 Method
   ' =====================================================================================
   METHOD WalkComplete ( _                              ' VTable offset = 28
     BYVAL hr AS LONG _                                 ' __in HRESULT hr
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __INamespaceWalkCB2_INTERFACE_DEFINED__ */

'#endif  // (_WIN32_IE >= _WIN32_IE_IE70)

' ########################################################################################
' INamespaceWalk interface
' IID = 57CED8A7-3F4A-432C-9350-30F24483F74F
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%INamespaceWalk_INTERFACE_DEFINED)
    %INamespaceWalk_INTERFACE_DEFINED = 1

$IID_INamespaceWalk = GUID$("{57CED8A7-3F4A-432C-9350-30F24483F74F}")

' enum NAMESPACEWALKFLAG
%NSWF_NONE_IMPLIES_ALL               = &H1???
%NSWF_ONE_IMPLIES_ALL                = &H2???
%NSWF_DONT_TRAVERSE_LINKS            = &H4???
%NSWF_DONT_ACCUMULATE_RESULT         = &H8???
%NSWF_TRAVERSE_STREAM_JUNCTIONS      = &H10???
%NSWF_FILESYSTEM_ONLY                = &H20???
%NSWF_SHOW_PROGRESS                  = &H40???
%NSWF_FLAG_VIEWORDER                 = &H80???
%NSWF_IGNORE_AUTOPLAY_HIDA           = &H100???
%NSWF_ASYNC                          = &H200???
%NSWF_DONT_RESOLVE_LINKS             = &H400???
%NSWF_ACCUMULATE_FOLDERS             = &H800???
%NSWF_DONT_SORT                      = &H1000???
%NSWF_USE_TRANSFER_MEDIUM            = &H2000???
%NSWF_DONT_TRAVERSE_STREAM_JUNCTIONS = &H4000???

INTERFACE INamespaceWalk $IID_INamespaceWalk

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Walk ( _                                      ' VTable offset = 12
     BYVAL punkToWalk AS IUnknown _                     ' __in IUnknown *punkToWalk
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYVAL cDepth AS LONG _                             ' __in int cDepth
   , BYVAL pnswcb AS INamespaceWalkCB _                 ' __in INamespaceWalkCB *pnswcb
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetIDArrayResult ( _                          ' VTable offset = 16
     BYVAL pcItems AS DWORD _                           ' __out UINT *pcItems
   , BYREF prgpidl AS DWORD _                           ' __out PIDLIST_ABSOLUTE **prgpidl
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __INamespaceWalk_INTERFACE_DEFINED__ */

'#endif  // NTDDI_WINXP || (_WIN32_IE >= _WIN32_IE_IE70)

'__inline void FreeIDListArray(__in_ecount(cItems) PIDLIST_RELATIVE *ppidls, UINT cItems)
'{
'     UINT i;
'     for (i = 0; i < cItems; i++)
'     {
'         CoTaskMemFree(ppidls[i]);
'     }
'     CoTaskMemFree(ppidls);
'}

'#if defined(STRICT_TYPED_ITEMIDS) && defined(__cplusplus)
'__inline void FreeIDListArrayFull(__in_ecount(cItems) PIDLIST_ABSOLUTE *ppidls, UINT cItems)
'{
'     for (UINT i = 0; i < cItems; i++)
'     {
'         CoTaskMemFree(ppidls[i]);
'     }
'     CoTaskMemFree(ppidls);
'}

'__inline void FreeIDListArrayChild(__in_ecount(cItems) PITEMID_CHILD *ppidls, UINT cItems)
'{
'     for (UINT i = 0; i < cItems; i++)
'     {
'         CoTaskMemFree(ppidls[i]);
'     }
'     CoTaskMemFree(ppidls);
'}
'#else //  defined(STRICT_TYPED_ITEMIDS) && defined(__cplusplus)
'#define FreeIDListArrayFull FreeIDListArray
'#define FreeIDListArrayChild FreeIDListArray
'#endif //  defined(STRICT_TYPED_ITEMIDS) && defined(__cplusplus)


%ACDD_VISIBLE        = &H0001

' ########################################################################################
' IAutoCompleteDropDown interface
' IID = 3CD141F4-3C6A-11D2-BCAA-00C04FD929DB
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IAutoCompleteDropDown_INTERFACE_DEFINED)
    %IAutoCompleteDropDown_INTERFACE_DEFINED = 1

$IID_IAutoCompleteDropDown = GUID$("{3CD141F4-3C6A-11D2-BCAA-00C04FD929DB}")

INTERFACE IAutoCompleteDropDown $IID_IAutoCompleteDropDown

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetDropDownStatus ( _                         ' VTable offset = 12
     BYREF pdwFlags AS DWORD _                          ' __out DWORD *pdwFlags
   , BYREF ppwszString AS DWORD _                       ' __out LPWSTR *ppwszString
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ResetEnumerator ( _                           ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAutoCompleteDropDown_INTERFACE_DEFINED__ */


'#if _WIN32_IE >= 0x0400
'#include <pshpack8.h>
' // Size = 12 bytes
TYPE BANDSITEINFO DWORD
   dwMask  AS DWORD   ' DWORD dwMask
   dwState AS DWORD   ' DWORD dwState
   dwStyle AS DWORD   ' DWORD dwStyle
END TYPE
'#include <poppack.h>

' enum BANDSITECID
%BSID_BANDADDED                 = 0
%BSID_BANDREMOVED               = %BSID_BANDADDED + 1

%BSIM_STATE                     = &H00000001???
%BSIM_STYLE                     = &H00000002???
%BSSF_VISIBLE                   = &H00000001???
%BSSF_NOTITLE                   = &H00000002???
%BSSF_UNDELETEABLE              = &H00001000???
%BSIS_AUTOGRIPPER               = &H00000000???
%BSIS_NOGRIPPER                 = &H00000001???
%BSIS_ALWAYSGRIPPER             = &H00000002???
%BSIS_LEFTALIGN                 = &H00000004???
%BSIS_SINGLECLICK               = &H00000008???
%BSIS_NOCONTEXTMENU             = &H00000010???
%BSIS_NODROPTARGET              = &H00000020???
%BSIS_NOCAPTION                 = &H00000040???
%BSIS_PREFERNOLINEBREAK         = &H00000080???
%BSIS_LOCKED                    = &H00000100???
'#if (_WIN32_IE >= _WIN32_IE_IE70)
%BSIS_PRESERVEORDERDURINGLAYOUT = &H00000200???
%BSIS_FIXEDORDER                = &H00000400???
'#endif  // _WIN32_IE_IE70

' ########################################################################################
' IBandSite interface
' IID = 4CF504B0-DE96-11D0-8B3F-00A0C911E8E5
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IBandSite_INTERFACE_DEFINED)
    %IBandSite_INTERFACE_DEFINED = 1

$IID_IBandSite  = GUID$("{4CF504B0-DE96-11D0-8B3F-00A0C911E8E5}")
$SID_IBandSite  = GUID$("{4CF504B0-DE96-11D0-8B3F-00A0C911E8E5}")
$CGID_IBandSite = GUID$("{4CF504B0-DE96-11D0-8B3F-00A0C911E8E5}")

INTERFACE IBandSite $IID_IBandSite

   INHERIT IUnknown

   ' =====================================================================================
   METHOD AddBand ( _                                   ' VTable offset = 12
     BYVAL punk AS IUnknown _                           ' __in IUnknown *punk
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumBands ( _                                 ' VTable offset = 16
     BYVAL uBand AS DWORD _                             ' __in UINT uBand
   , BYREF pdwBandID AS DWORD _                         ' __out DWORD *pdwBandID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD QueryBand ( _                                 ' VTable offset = 20
     BYVAL dwBandID AS DWORD _                          ' __in DWORD dwBandID
   , BYREF ppstb AS IDeskBand _                         ' __out IDeskBand **ppstb
   , BYREF pdwState AS DWORD _                          ' __out DWORD *pdwState
   , BYREF pszName AS WSTRINGZ _                        ' __out LPWSTR pszName
   , BYVAL cchName AS LONG _                            ' __in int cchName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetBandState ( _                              ' VTable offset = 24
     BYVAL dwBandID AS DWORD _                          ' __in DWORD dwBandID
   , BYVAL dwMask AS DWORD _                            ' __in DWORD dwMask
   , BYVAL dwState AS DWORD _                           ' __in DWORD dwState
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RemoveBand ( _                                ' VTable offset = 28
     BYVAL dwBandID AS DWORD _                          ' __in DWORD dwBandID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetBandObject ( _                             ' VTable offset = 32
     BYVAL dwBandID AS DWORD _                          ' __in DWORD dwBandID
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppv AS IUnknown _                            ' __out void **ppv
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetBandSiteInfo ( _                           ' VTable offset = 36
     BYREF pbsinfo AS BANDSITEINFO _                    ' __in const BANDSITEINFO *pbsinfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetBandSiteInfo ( _                           ' VTable offset = 36
     BYREF pbsinfo AS BANDSITEINFO _                    ' __inout BANDSITEINFO *pbsinfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IBandSite_INTERFACE_DEFINED__ */

'#endif // _WIN32_IE >= 0x0400

'#if (NTDDI_VERSION >= NTDDI_WINXP)

' ########################################################################################
' IModalWindow interface
' IID = B4DB1657-70D7-485E-8E3E-6FCB5A5C1802
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IModalWindow_INTERFACE_DEFINED)
    %IModalWindow_INTERFACE_DEFINED = 1

$IID_IModalWindow = GUID$("{B4DB1657-70D7-485E-8E3E-6FCB5A5C1802}")

INTERFACE IModalWindow $IID_IModalWindow

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Show ( _                                      ' VTable offset = 12
     BYVAL hwndParent AS DWORD _                        ' __in HWND hwndParent
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IModalWindow_INTERFACE_DEFINED__ */

' Must be Unicode
$PROPSTR_EXTENSIONCOMPLETIONSTATE = "ExtensionCompletionState"

' enum CDBURNINGEXTENSIONRET
%CDBE_RET_DEFAULT          = 0
%CDBE_RET_DONTRUNOTHEREXTS = &H1
%CDBE_RET_STOPWIZARD       = &H2

' ########################################################################################
' ICDBurnExt interface
' IID = 2271DCCA-74FC-4414-8FB7-C56B05ACE2D7
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ICDBurnExt_INTERFACE_DEFINED)
    %ICDBurnExt_INTERFACE_DEFINED = 1

%CDBE_TYPE_MUSIC = &H1???
%CDBE_TYPE_DATA  = &H2???
%CDBE_TYPE_ALL   = &HFFFFFFFF&   ' ( int  )0xffffffff
'typedef DWORD CDBE_ACTIONS;

$IID_ICDBurnExt   = GUID$("{2271DCCA-74FC-4414-8FB7-C56B05ACE2D7}")
$SID_CDWizardHost = GUID$("{2271DCCA-74FC-4414-8FB7-C56B05ACE2D7}")

INTERFACE ICDBurnExt $IID_ICDBurnExt

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetSupportedActionTypes ( _                   ' VTable offset = 12
     BYREF pdwActions AS DWORD _                        ' __out DWORD *pdwActions
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICDBurnExt_INTERFACE_DEFINED__ */

'#endif  // NTDDI_WINXP


' ########################################################################################
' IContextMenuSite interface
' IID = 0811AEBE-0B87-4C54-9E72-548CF649016B
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IContextMenuSite_INTERFACE_DEFINED)
   %IContextMenuSite_INTERFACE_DEFINED = 1

$IID_IContextMenuSite = GUID$("{0811AEBE-0B87-4C54-9E72-548CF649016B}")

INTERFACE IContextMenuSite $IID_IContextMenuSite

   INHERIT IUnknown

   ' =====================================================================================
   METHOD DoContextMenuPopup ( _                        ' VTable offset = 12
     BYVAL punkContextMenu AS IUnknown _                ' __in IUnknown *punkContextMenu
   , BYVAL fFlags AS DWORD _                            ' __in UINT fFlags
   , BYVAL pt AS POINT _                                ' __in POINT pt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IContextMenuSite_INTERFACE_DEFINED__ */


' ########################################################################################
' IEnumReadyCallback interface
' IID = 61E00D45-8FFF-4E60-924E-6537B61612DD
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IEnumReadyCallback_INTERFACE_DEFINED)
   %IEnumReadyCallback_INTERFACE_DEFINED = 1

$IID_IEnumReadyCallback = GUID$("{61E00D45-8FFF-4E60-924E-6537B61612DD}")

INTERFACE IEnumReadyCallback $IID_IEnumReadyCallback

   INHERIT IUnknown

   ' =====================================================================================
   METHOD EnumReady ( _                                 ' VTable offset = 12
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEnumReadyCallback_INTERFACE_DEFINED__ */


' ########################################################################################
' IEnumerableView interface
' IID = 8C8BF236-1AEC-495F-9894-91D57C3C686F
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IEnumerableView_INTERFACE_DEFINED)
   %IEnumerableView_INTERFACE_DEFINED = 1

$IID_IEnumerableView = GUID$("{8C8BF236-1AEC-495F-9894-91D57C3C686F}")
$SID_EnumerableView = $IID_IEnumerableView

INTERFACE IEnumerableView $IID_IEnumerableView

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetEnumReadyCallback ( _                      ' VTable offset = 12
     BYVAL percb AS IEnumReadyCallback _                ' __in IEnumReadyCallback *percb
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateEnumIDListFromContents ( _              ' VTable offset = 16
     BYVAL pidlFolder AS DWORD _                        ' __in PCIDLIST_ABSOLUTE pidlFolder
   , BYVAL dwEnumFlags AS DWORD _                       ' __in DWORD dwEnumFlags
   , BYREF ppEnumIDList AS IEnumIDList _                ' __out IEnumIDList **ppEnumIDList
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEnumerableView_INTERFACE_DEFINED__ */

'#if (NTDDI_VERSION >= NTDDI_WINXP) || (_WIN32_IE >= _WIN32_IE_IE70)

' ########################################################################################
' IInsertItem interface
' IID = D2B57227-3D23-4B95-93C0-492BD454C356
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IInsertItem_INTERFACE_DEFINED)
    %IInsertItem_INTERFACE_DEFINED = 1

$IID_IInsertItem = GUID$("{D2B57227-3D23-4B95-93C0-492BD454C356}")

INTERFACE IInsertItem $IID_IInsertItem

   INHERIT IUnknown

   ' =====================================================================================
   METHOD InsertItem ( _                                ' VTable offset = 12
     BYVAL pidl AS DWORD _                              ' __in LPCITEMIDLIST pidl
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IInsertItem_INTERFACE_DEFINED__ */

'#if (NTDDI_VERSION >= NTDDI_WINXP)

' ########################################################################################
' IMenuBand interface
' IID = 568804CD-CBD7-11D0-9816-00C04FD91972
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMenuBand_INTERFACE_DEFINED)
    %IMenuBand_INTERFACE_DEFINED = 1

' __MIDL_IMenuBand_0001 enum
%MBHANDCID_PIDLSELECT = 0

$IID_IMenuBand = GUID$("{568804CD-CBD7-11D0-9816-00C04FD91972}")

INTERFACE IMenuBand $IID_IMenuBand

   INHERIT IUnknown

   ' =====================================================================================
   METHOD IsMenuMessage ( _                             ' VTable offset = 12
     BYREF pmsg AS tagMSG _                             ' __in MSG *pmsg
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD TranslateMenuMessage ( _                      ' VTable offset = 16
     BYREF pmsg AS tagMSG _                             ' __inout MSG *pmsg
   , BYREF plRet AS LONG _                              ' __out LRESULT *plRet
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMenuBand_INTERFACE_DEFINED__ */


' ########################################################################################
' IFolderBandPriv interface
' IID = 47C01F95-E185-412C-B5C5-4F27DF965AEA
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IFolderBandPriv_INTERFACE_DEFINED)
    %IFolderBandPriv_INTERFACE_DEFINED = 1

$IID_IFolderBandPriv = GUID$("{47C01F95-E185-412C-B5C5-4F27DF965AEA}")

INTERFACE IFolderBandPriv $IID_IFolderBandPriv

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetCascade ( _                                ' VTable offset = 12
     BYVAL f AS LONG _                                  ' __in BOOL f
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetAccelerators ( _                           ' VTable offset = 16
     BYVAL f AS LONG _                                  ' __in BOOL f
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetNoIcons ( _                                ' VTable offset = 20
     BYVAL f AS LONG _                                  ' __in BOOL f
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetNoText ( _                                 ' VTable offset = 24
     BYVAL f AS LONG _                                  ' __in BOOL f
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IFolderBandPriv_INTERFACE_DEFINED__ */


' ########################################################################################
' IRegTreeItem interface
' IID = A9521922-0812-4D44-9EC3-7FD38C726F3D
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IRegTreeItem_INTERFACE_DEFINED)
    %IRegTreeItem_INTERFACE_DEFINED = 1

$IID_IRegTreeItem = GUID$("{A9521922-0812-4D44-9EC3-7FD38C726F3D}")

INTERFACE IRegTreeItem $IID_IRegTreeItem

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetCheckState ( _                             ' VTable offset = 12
     BYREF pbCheck AS LONG _                            ' __out BOOL *pbCheck
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetCheckState ( _                             ' VTable offset = 16
     BYVAL bCheck AS LONG _                             ' __in BOOL bCheck
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IRegTreeItem_INTERFACE_DEFINED__ */


' ########################################################################################
' IImageRecompress interface
' IID = 505F1513-6B3E-4892-A272-59F8889A4D3E
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IImageRecompress_INTERFACE_DEFINED)
    %IImageRecompress_INTERFACE_DEFINED = 1

$IID_IImageRecompress = GUID$("{505F1513-6B3E-4892-A272-59F8889A4D3E}")

INTERFACE IImageRecompress $IID_IImageRecompress

   INHERIT IUnknown

   ' =====================================================================================
   METHOD RecompressImage ( _                           ' VTable offset = 12
     BYVAL psi AS IShellItem _                          ' __in IShellItem *psi
   , BYVAL cx AS LONG _                                 ' __in int cx
   , BYVAL cy AS LONG _                                 ' __in int cy
   , BYVAL iQuality AS LONG _                           ' __in int iQuality
   , BYVAL pstg AS IStorage _                           ' __in IStorage *pstg
   , BYREF ppstrmOut AS IStream _                       ' __inout IStream **ppstrmOut
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IImageRecompress_INTERFACE_DEFINED__ */

'#endif  // NTDDI_WINXP
'#endif  // NTDDI_WINXP) || (_WIN32_IE >= _WIN32_IE_IE70)

'#if (_WIN32_IE >= _WIN32_IE_IE60)

' ########################################################################################
' IDeskBar interface
' IID = EB0FE173-1A3A-11D0-89B3-00A0C90A90AC
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDeskBar_INTERFACE_DEFINED)
    %IDeskBar_INTERFACE_DEFINED = 1

$IID_IDeskBar = GUID$("{EB0FE173-1A3A-11D0-89B3-00A0C90A90AC}")

INTERFACE IDeskBar $IID_IDeskBar

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
   ' IDeskBar methods
   ' =====================================================================================
   METHOD SetClient ( _                                 ' VTable offset = 20
     BYVAL punkClient AS IUnknown _                     ' __in IUnknown *punkClient
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetClient ( _                                 ' VTable offset = 24
     BYREF ppunkClient AS IUnknown _                    ' __out IUnknown **ppunkClient
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnPosRectChangeDB ( _                         ' VTable offset = 28
     BYREF prc AS RECT _                                ' __in LPRECT prc
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDeskBar_INTERFACE_DEFINED__ */


' ########################################################################################
' IMenuPopup interface
' IID = D1E7AFEB-6A2E-11D0-8C78-00C04FD918B4
' Inherited interface = IDeskBar
' ########################################################################################

#IF NOT %DEF(%IMenuPopup_INTERFACE_DEFINED)
    %IMenuPopup_INTERFACE_DEFINED = 1

$IID_IMenupopup = GUID$("{D1E7AFEB-6A2E-11D0-8C78-00C04FD918B4}")

' enum MENUPOPUPSELECT
%MPOS_EXECUTE       = 0
%MPOS_FULLCANCEL    = %MPOS_EXECUTE     + 1
%MPOS_CANCELLEVEL   = %MPOS_FULLCANCEL  + 1
%MPOS_SELECTLEFT    = %MPOS_CANCELLEVEL + 1
%MPOS_SELECTRIGHT   = %MPOS_SELECTLEFT  + 1
%MPOS_CHILDTRACKING = %MPOS_SELECTRIGHT + 1

' enum MENUPOPUPPOPUPFLAGS
%MPPF_SETFOCUS      = &H1???
%MPPF_INITIALSELECT = &H2???
%MPPF_NOANIMATE     = &H4???
%MPPF_KEYBOARD      = &H10???
%MPPF_REPOSITION    = &H20???
%MPPF_FORCEZORDER   = &H40???
%MPPF_FINALSELECT   = &H80???
%MPPF_TOP           = &H20000000???
%MPPF_LEFT          = &H40000000???
%MPPF_RIGHT         = &H60000000???
%MPPF_BOTTOM        = &H80000000&   ' ( int  )0x80000000
%MPPF_POS_MASK      = &HE0000000&   ' ( int  )0xe0000000
%MPPF_ALIGN_LEFT    = &H2000000???
%MPPF_ALIGN_RIGHT   = &H4000000???
'typedef int MP_POPUPFLAGS;

INTERFACE IMenuPopup $IID_IMenuPopup

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
   ' IDeskBar methods
   ' =====================================================================================
   METHOD SetClient ( _                                 ' VTable offset = 20
     BYVAL punkClient AS IUnknown _                     ' __in IUnknown *punkClient
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetClient ( _                                 ' VTable offset = 24
     BYREF ppunkClient AS IUnknown _                    ' __out IUnknown **ppunkClient
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnPosRectChangeDB ( _                         ' VTable offset = 28
     BYREF prc AS RECT _                                ' __in LPRECT prc
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IMenuPopup methods
   ' =====================================================================================
   METHOD Popup ( _                                     ' VTable offset = 32
     BYREF ppt AS POINTL _                              ' __in POINTL *ppt
   , BYREF prcExclude AS RECTL _                        ' __in RECTL *prcExclude
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnSelect ( _                                  ' VTable offset = 36
     BYVAL dwSelectType AS DWORD _                      '__in DWORD dwSelectType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetSubMenu ( _                                ' VTable offset = 40
     BYVAL pmp AS IMenuPopup _                          ' __in IMenuPopup *pmp
   , BYVAL fSet AS LONG _                               ' __in BOOL fSet
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMenuPopup_INTERFACE_DEFINED__ */

'#endif  // _WIN32_IE_IE60

'#if (NTDDI_VERSION >= NTDDI_VISTA)

' enum FILE_USAGE_TYPE
%FUT_PLAYING = 0
%FUT_EDITING = %FUT_PLAYING + 1
%FUT_GENERIC = %FUT_EDITING + 1

%OF_CAP_CANSWITCHTO = &H0001???
%OF_CAP_CANCLOSE    = &H0002???

' ########################################################################################
' IFileIsInUse interface
' IID = 64A1CBF0-3A1A-4461-9158-376969693950
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IFileIsInUse_INTERFACE_DEFINED)
    %IFileIsInUse_INTERFACE_DEFINED = 1

$IID_IFileIsInUse = GUID$("{64A1CBF0-3A1A-4461-9158-376969693950}")

INTERFACE IFileIsInUse $IID_IFileIsInUse

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetAppName ( _                                ' VTable offset = 12
     BYREF ppszName AS DWORD _                          ' __out LPWSTR *ppszName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetUsage ( _                                  ' VTable offset = 16
     BYREF pfut AS LONG _                               ' __out FILE_USAGE_TYPE *pfut
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCapabilities ( _                           ' VTable offset = 20
     BYREF pdwCapFlags AS DWORD _                       ' __out DWORD *pdwCapFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSwitchToHWND ( _                           ' VTable offset = 24
     BYREF phwnd AS DWORD _                             ' __out HWND *phwnd
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CloseFile ( _                                 ' VTable offset = 28
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IFileIsInUse_INTERFACE_DEFINED__ */

' enum FDE_OVERWRITE_RESPONSE
%FDEOR_DEFAULT  = 0
%FDEOR_ACCEPT   = 1
%FDEOR_REFUSE   = 2

' enum FDE_SHAREVIOLATION_RESPONSE
%FDESVR_DEFAULT = 0
%FDESVR_ACCEPT  = 1
%FDESVR_REFUSE  = 2

' enum FDAP
%FDAP_BOTTOM    = 0
%FDAP_TOP       = 1

' ########################################################################################
' IFileDialogEvents interface
' IID = 973510DB-7D7F-452B-8975-74A85828d354
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IFileDialogEvents_INTERFACE_DEFINED)
    %IFileDialogEvents_INTERFACE_DEFINED = 1

$IID_IFileDialogEvents = GUID$("{973510DB-7D7F-452B-8975-74A85828d354}")

INTERFACE IFileDialogEvents $IID_IFileDialogEvents

   INHERIT IUnknown

   ' =====================================================================================
   METHOD OnFileOk ( _                                  ' VTable offset = 12
     BYVAL pfd AS IFileDialog _                         ' __in IFileDialog *pfd
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnFolderChanging ( _                          ' VTable offset = 16
     BYVAL pfd AS IFileDialog _                         ' __in IFileDialog *pfd
   , BYVAL psiFolder AS IShellItem _                    ' __in IShellItem *psiFolder
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnFolderChange ( _                            ' VTable offset = 20
     BYVAL pfd AS IFileDialog _                         ' __in IFileDialog *pfd
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnSelectionChange ( _                         ' VTable offset = 24
     BYVAL pfd AS IFileDialog _                         ' __in IFileDialog *pfd
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnShareViolation ( _                          ' VTable offset = 28
     BYVAL pfd AS IFileDialog _                         ' __in IFileDialog *pfd
   , BYVAL psi AS IShellItem _                          ' __in IShellItem *psi
   , BYREF pResponse AS LONG _                          ' __out FDE_SHAREVIOLATION_RESPONSE *pResponse
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnTypeChange ( _                              ' VTable offset = 32
     BYVAL pfd AS IFileDialog _                         ' __in IFileDialog *pfd
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnOverwrite ( _                               ' VTable offset = 36
     BYVAL pfd AS IFileDialog _                         ' __in IFileDialog *pfd
   , BYVAL psi AS IShellItem _                          ' __in IShellItem *psi
   , BYREF pResponse AS LONG _                          ' __out FDE_OVERWRITE_RESPONSE *pResponse
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IFileDialogEvents_INTERFACE_DEFINED__ */


' ########################################################################################
' IFileDialog interface
' IID = 42F85136-DB7E-439C-85F1-E4075D135FC8
' Inherited interface = IModalWindow
' ########################################################################################

#IF NOT %DEF(%IFileDialog_INTERFACE_DEFINED)
    %IFileDialog_INTERFACE_DEFINED = 1

$IID_IFileDialog = GUID$("{42F85136-DB7E-439C-85F1-E4075D135FC8}")

' enum FILEOPENDIALOGOPTIONS
%FOS_OVERWRITEPROMPT    = &H2???
%FOS_STRICTFILETYPES    = &H4???
%FOS_NOCHANGEDIR        = &H8???
%FOS_PICKFOLDERS        = &H20???
%FOS_FORCEFILESYSTEM    = &H40???
%FOS_ALLNONSTORAGEITEMS = &H80???
%FOS_NOVALIDATE         = &H100???
%FOS_ALLOWMULTISELECT   = &H200???
%FOS_PATHMUSTEXIST      = &H800???
%FOS_FILEMUSTEXIST      = &H1000???
%FOS_CREATEPROMPT       = &H2000???
%FOS_SHAREAWARE         = &H4000???
%FOS_NOREADONLYRETURN   = &H8000???
%FOS_NOTESTFILECREATE   = &H10000???
%FOS_HIDEMRUPLACES      = &H20000???
%FOS_HIDEPINNEDPLACES   = &H40000???
%FOS_NODEREFERENCELINKS = &H100000???
%FOS_DONTADDTORECENT    = &H2000000???
%FOS_FORCESHOWHIDDEN    = &H10000000???
%FOS_DEFAULTNOMINIMODE  = &H20000000???
%FOS_FORCEPREVIEWPANEON = &H40000000???

INTERFACE IFileDialog $IID_IFileDialog

   INHERIT IUnknown

   ' =====================================================================================
   ' IModalWindow Method
   ' =====================================================================================
   METHOD Show ( _                                      ' VTable offset = 12
     BYVAL hwndParent AS DWORD _                        ' __in HWND hwndParent
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IFileDialog Methods
   ' =====================================================================================
   METHOD SetFileTypes ( _                              ' VTable offset = 16
     BYVAL cFileTypes AS DWORD _                        ' __in UINT cFileTypes
   , BYREF rgFilterSpec AS COMDLG_FILTERSPEC _          ' __in const COMDLG_FILTERSPEC *rgFilterSpec
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetFileTypeIndex ( _                          ' VTable offset = 20
     BYVAL iFileType AS DWORD _                         ' __in UINT iFileType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFileTypeIndex ( _                          ' VTable offset = 24
     BYREF piFileType AS DWORD _                        ' __out UINT *piFileType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Advise ( _                                    ' VTable offset = 28
     BYVAL pfde AS IFileDialogEvents _                  ' __in IFileDialogEvents *pfde
   , BYREF pdwCookie AS DWORD _                         ' __out DWORD *pdwCookie
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Unadvise ( _                                  ' VTable offset = 32
     BYVAL dwCookie AS DWORD _                          ' __in DWORD dwCookie
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetOptions ( _                                ' VTable offset = 36
     BYVAL fos AS DWORD _                               ' __in DWORD fos
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetOptions ( _                                ' VTable offset = 40
     BYREF pfos AS DWORD _                              ' __out DWORD *pfos
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetDefaultFolder ( _                          ' VTable offset = 44
     BYVAL psi AS IShellItem _                          ' __in IShellItem *psi
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetFolder ( _                                 ' VTable offset = 48
     BYVAL psi AS IShellItem _                          ' __in IShellItem *psi
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFolder ( _                                 ' VTable offset = 52
     BYREF ppsi AS IShellItem _                         ' __out IShellItem **ppsi
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCurrentSelection ( _                       ' VTable offset = 56
     BYREF ppsi AS IShellItem _                         ' __out IShellItem **ppsi
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetFileName ( _                               ' VTable offset = 60
     BYREF pszName AS WSTRINGZ _                        ' __in LPCWSTR pszName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFileName ( _                               ' VTable offset = 64
     BYREF pszName AS DWORD _                           ' __out LPWSTR *pszName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetTitle ( _                                  ' VTable offset = 68
     BYREF pszTitle AS WSTRINGZ _                       ' __in LPCWSTR pszTitle
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetOkButtonLabel ( _                          ' VTable offset = 72
     BYREF pszText AS WSTRINGZ _                        ' __in LPCWSTR pszText
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetFileNameLabel ( _                          ' VTable offset = 76
     BYREF pszLabel AS WSTRINGZ _                       ' __in LPCWSTR pszLabel
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetResult ( _                                 ' VTable offset = 80
     BYREF ppsi AS IShellItem _                         ' __out IShellItem **ppsi
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddPlace ( _                                  ' VTable offset = 84
     BYVAL psi AS IShellItem _                          ' __in IShellItem *psi
   , BYVAL fdap AS LONG _                               ' __in FDAP fdap
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetDefaultExtension ( _                       ' VTable offset = 88
     BYREF pszDefaultExtension AS WSTRINGZ _            ' __in LPCWSTR pszDefaultExtension
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Close ( _                                     ' VTable offset = 92
     BYVAL hr AS LONG _                                 ' __in HRESULT hr
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetClientGuid ( _                             ' VTable offset = 96
     BYREF guid AS GUID _                               ' __in REFGUID guid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ClearClientData ( _                           ' VTable offset = 100
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetFilter ( _                                 ' VTable offset = 104
     BYVAL pFilter AS IShellItemFilter _                ' __in IShellItemFilter *pFilter
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IFileDialog_INTERFACE_DEFINED__ */


' ########################################################################################
' IFileSaveDialog interface
' IID = 84BCCD23-5FDE-4CDB-AEA4-AF64B83D78AB
' Inherited interface = IFileDialog
' ########################################################################################

#IF NOT %DEF(%IFileSaveDialog_INTERFACE_DEFINED)
    %IFileSaveDialog_INTERFACE_DEFINED = 1

$IID_IFileSaveDialog = GUID$("{84BCCD23-5FDE-4CDB-AEA4-AF64B83D78AB}")

INTERFACE IFileSaveDialog $IID_IFileSaveDialog

   INHERIT IUnknown

   ' =====================================================================================
   ' IModalWindow Method
   ' =====================================================================================
   METHOD Show ( _                                      ' VTable offset = 12
     BYVAL hwndParent AS DWORD _                        ' __in HWND hwndParent
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IFileDialog Methods
   ' =====================================================================================
   METHOD SetFileTypes ( _                              ' VTable offset = 16
     BYVAL cFileTypes AS DWORD _                        ' __in UINT cFileTypes
   , BYREF rgFilterSpec AS COMDLG_FILTERSPEC _          ' __in const COMDLG_FILTERSPEC *rgFilterSpec
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetFileTypeIndex ( _                          ' VTable offset = 20
     BYVAL iFileType AS DWORD _                         ' __in UINT iFileType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFileTypeIndex ( _                          ' VTable offset = 24
     BYREF piFileType AS DWORD _                        ' __out UINT *piFileType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Advise ( _                                    ' VTable offset = 28
     BYVAL pfde AS IFileDialogEvents _                  ' __in IFileDialogEvents *pfde
   , BYREF pdwCookie AS DWORD _                         ' __out DWORD *pdwCookie
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Unadvise ( _                                  ' VTable offset = 32
     BYVAL dwCookie AS DWORD _                          ' __in DWORD dwCookie
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetOptions ( _                                ' VTable offset = 36
     BYVAL fos AS DWORD _                               ' __in DWORD fos
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetOptions ( _                                ' VTable offset = 40
     BYREF pfos AS DWORD _                              ' __out DWORD *pfos
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetDefaultFolder ( _                          ' VTable offset = 44
     BYVAL psi AS IShellItem _                          ' __in IShellItem *psi
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetFolder ( _                                 ' VTable offset = 48
     BYVAL psi AS IShellItem _                          ' __in IShellItem *psi
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFolder ( _                                 ' VTable offset = 52
     BYREF ppsi AS IShellItem _                         ' __out IShellItem **ppsi
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCurrentSelection ( _                       ' VTable offset = 56
     BYREF ppsi AS IShellItem _                         ' __out IShellItem **ppsi
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetFileName ( _                               ' VTable offset = 60
     BYREF pszName AS WSTRINGZ _                        ' __in LPCWSTR pszName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFileName ( _                               ' VTable offset = 64
     BYREF pszName AS DWORD _                           ' __out LPWSTR *pszName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetTitle ( _                                  ' VTable offset = 68
     BYREF pszTitle AS WSTRINGZ _                       ' __in LPCWSTR pszTitle
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetOkButtonLabel ( _                          ' VTable offset = 72
     BYREF pszText AS WSTRINGZ _                        ' __in LPCWSTR pszText
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetFileNameLabel ( _                          ' VTable offset = 76
     BYREF pszLabel AS WSTRINGZ _                       ' __in LPCWSTR pszLabel
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetResult ( _                                 ' VTable offset = 80
     BYREF ppsi AS IShellItem _                         ' __out IShellItem **ppsi
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddPlace ( _                                  ' VTable offset = 84
     BYVAL psi AS IShellItem _                          ' __in IShellItem *psi
   , BYVAL fdap AS LONG _                               ' __in FDAP fdap
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetDefaultExtension ( _                       ' VTable offset = 88
     BYREF pszDefaultExtension AS WSTRINGZ _            ' __in LPCWSTR pszDefaultExtension
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Close ( _                                     ' VTable offset = 92
     BYVAL hr AS LONG _                                 ' __in HRESULT hr
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetClientGuid ( _                             ' VTable offset = 96
     BYREF guid AS GUID _                               ' __in REFGUID guid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ClearClientData ( _                           ' VTable offset = 100
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetFilter ( _                                 ' VTable offset = 104
     BYVAL pFilter AS IShellItemFilter _                ' __in IShellItemFilter *pFilter
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IFileSaveDialog Methods
   ' =====================================================================================
   METHOD SetSaveAsItem ( _                             ' VTable offset = 108
     BYVAL psi AS IShellItem _                          ' __in IShellItem *psi
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetProperties ( _                             ' VTable offset = 112
     BYVAL pStore AS IPropertyStore _                   ' __in IPropertyStore *pStore
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetCollectedProperties ( _                    ' VTable offset = 116
     BYVAL pList AS IPropertyDescriptionList _          ' __in IPropertyDescriptionList *pList
   , BYVAL fAppendDefault AS LONG _                     ' __in BOOL fAppendDefault
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetProperties ( _                             ' VTable offset = 120
     BYREF ppStore AS IPropertyStore _                  ' __out IPropertyStore **ppStore
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ApplyProperties ( _                           ' VTable offset = 124
     BYVAL psi AS IShellItem _                          ' __in IShellItem *psi
   , BYVAL pStore AS IPropertyStore _                   ' __in IPropertyStore *pStore
   , BYVAL hwnd AS DWORD _                              ' __in HWND hwnd
   , BYVAL pSink AS IFileOperationProgressSink _        ' __in IFileOperationProgressSink *pSink
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IFileSaveDialog_INTERFACE_DEFINED__ */


' ########################################################################################
' IFileOpenDialog interface
' IID = D57C7288-D4AD-4768-BE02-9D969532d960
' Inherited interface = IFileDialog
' ########################################################################################

#IF NOT %DEF(%IFileOpenDialog_INTERFACE_DEFINED)
    %IFileOpenDialog_INTERFACE_DEFINED = 1

$IID_IFileOpenDialog = GUID$("{D57C7288-D4AD-4768-BE02-9D969532d960}")

INTERFACE IFileOpenDialog $IID_IFileOpenDialog

   INHERIT IUnknown

   ' =====================================================================================
   ' IModalWindow Method
   ' =====================================================================================
   METHOD Show ( _                                      ' VTable offset = 12
     BYVAL hwndParent AS DWORD _                        ' __in HWND hwndParent
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IFileDialog Methods
   ' =====================================================================================
   METHOD SetFileTypes ( _                              ' VTable offset = 16
     BYVAL cFileTypes AS DWORD _                        ' __in UINT cFileTypes
   , BYREF rgFilterSpec AS COMDLG_FILTERSPEC _          ' __in const COMDLG_FILTERSPEC *rgFilterSpec
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetFileTypeIndex ( _                          ' VTable offset = 20
     BYVAL iFileType AS DWORD _                         ' __in UINT iFileType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFileTypeIndex ( _                          ' VTable offset = 24
     BYREF piFileType AS DWORD _                        ' __out UINT *piFileType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Advise ( _                                    ' VTable offset = 28
     BYVAL pfde AS IFileDialogEvents _                  ' __in IFileDialogEvents *pfde
   , BYREF pdwCookie AS DWORD _                         ' __out DWORD *pdwCookie
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Unadvise ( _                                  ' VTable offset = 32
     BYVAL dwCookie AS DWORD _                          ' __in DWORD dwCookie
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetOptions ( _                                ' VTable offset = 36
     BYVAL fos AS DWORD _                               ' __in DWORD fos
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetOptions ( _                                ' VTable offset = 40
     BYREF pfos AS DWORD _                              ' __out DWORD *pfos
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetDefaultFolder ( _                          ' VTable offset = 44
     BYVAL psi AS IShellItem _                          ' __in IShellItem *psi
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetFolder ( _                                 ' VTable offset = 48
     BYVAL psi AS IShellItem _                          ' __in IShellItem *psi
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFolder ( _                                 ' VTable offset = 52
     BYREF ppsi AS IShellItem _                         ' __out IShellItem **ppsi
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCurrentSelection ( _                       ' VTable offset = 56
     BYREF ppsi AS IShellItem _                         ' __out IShellItem **ppsi
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetFileName ( _                               ' VTable offset = 60
     BYREF pszName AS WSTRINGZ _                        ' __in LPCWSTR pszName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFileName ( _                               ' VTable offset = 64
     BYREF pszName AS DWORD _                           ' __out LPWSTR *pszName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetTitle ( _                                  ' VTable offset = 68
     BYREF pszTitle AS WSTRINGZ _                       ' __in LPCWSTR pszTitle
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetOkButtonLabel ( _                          ' VTable offset = 72
     BYREF pszText AS WSTRINGZ _                        ' __in LPCWSTR pszText
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetFileNameLabel ( _                          ' VTable offset = 76
     BYREF pszLabel AS WSTRINGZ _                       ' __in LPCWSTR pszLabel
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetResult ( _                                 ' VTable offset = 80
     BYREF ppsi AS IShellItem _                         ' __out IShellItem **ppsi
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddPlace ( _                                  ' VTable offset = 84
     BYVAL psi AS IShellItem _                          ' __in IShellItem *psi
   , BYVAL fdap AS LONG _                               ' __in FDAP fdap
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetDefaultExtension ( _                       ' VTable offset = 88
     BYREF pszDefaultExtension AS WSTRINGZ _            ' __in LPCWSTR pszDefaultExtension
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Close ( _                                     ' VTable offset = 92
     BYVAL hr AS LONG _                                 ' __in HRESULT hr
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetClientGuid ( _                             ' VTable offset = 96
     BYREF guid AS GUID _                               ' __in REFGUID guid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ClearClientData ( _                           ' VTable offset = 100
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetFilter ( _                                 ' VTable offset = 104
     BYVAL pFilter AS IShellItemFilter _                ' __in IShellItemFilter *pFilter
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IFileOpenDialog Methods
   ' =====================================================================================
   METHOD GetResults ( _                                ' VTable offset = 108
     BYREF ppenum AS IShellItemArray _                  ' __out IShellItemArray **ppenum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSelectedItems ( _                          ' VTable offset = 112
     BYREF ppsai AS IShellItemArray _                   ' __out IShellItemArray **ppsai
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IFileOpenDialog_INTERFACE_DEFINED__ */

' enum tagCDCONTROLSTATE
%CDCS_INACTIVE       = 0???
%CDCS_ENABLED        = &H1???
%CDCS_VISIBLE        = &H2???
%CDCS_ENABLEDVISIBLE = &H3???
'typedef DWORD CDCONTROLSTATEF;


' ########################################################################################
' IFileDialogCustomize interface
' IID = E6FDD21A-163F-4975-9C8C-A69F1BA37034
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IFileDialogCustomize_INTERFACE_DEFINED)
    %IFileDialogCustomize_INTERFACE_DEFINED = 1

$IID_IFileDialogCustomize = GUID$("{E6FDD21A-163F-4975-9C8C-A69F1BA37034}")

INTERFACE IFileDialogCustomize $IID_IFileDialogCustomize

   INHERIT IUnknown

   ' =====================================================================================
   METHOD EnableOpenDropDown ( _                        ' VTable offset = 12
     BYVAL dwIDCtl AS DWORD _                           ' __in DWORD dwIDCtl
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddMenu ( _                                   ' VTable offset = 16
     BYVAL dwIDCtl AS DWORD _                           ' __in DWORD dwIDCtl
   , BYREF pszLabel AS WSTRINGZ _                       ' __in LPCWSTR pszLabel
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddPushButton ( _                             ' VTable offset = 20
     BYVAL dwIDCtl AS DWORD _                           ' __in DWORD dwIDCtl
   , BYREF pszLabel AS WSTRINGZ _                       ' __in LPCWSTR pszLabel
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddComboBox ( _                               ' VTable offset = 24
     BYVAL dwIDCtl AS DWORD _                           ' __in DWORD dwIDCtl
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddRadioButtonList ( _                        ' VTable offset = 28
     BYVAL dwIDCtl AS DWORD _                           ' __in DWORD dwIDCtl
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddCheckButton ( _                            ' VTable offset = 32
     BYVAL dwIDCtl AS DWORD _                           ' __in DWORD dwIDCtl
   , BYREF pszLabel AS WSTRINGZ _                       ' __in LPCWSTR pszLabel
   , BYVAL bChecked AS LONG _                           ' __in BOOL bChecked
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddEditBox ( _                                ' VTable offset = 36
     BYVAL dwIDCtl AS DWORD _                           ' __in DWORD dwIDCtl
   , BYREF pszText AS WSTRINGZ _                        ' __in LPCWSTR pszText
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddSeparator ( _                              ' VTable offset = 40
     BYVAL dwIDCtl AS DWORD _                           ' __in DWORD dwIDCtl
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddText ( _                                   ' VTable offset = 44
     BYVAL dwIDCtl AS DWORD _                           ' __in DWORD dwIDCtl
   , BYREF pszText AS WSTRINGZ _                        ' __in LPCWSTR pszText
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetControlLabel ( _                           ' VTable offset = 48
     BYVAL dwIDCtl AS DWORD _                           ' __in DWORD dwIDCtl
   , BYREF pszLabel AS WSTRINGZ _                       ' __in LPCWSTR pszLabel
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetControlState ( _                           ' VTable offset = 52
     BYVAL dwIDCtl AS DWORD _                           ' __in DWORD dwIDCtl
   , BYREF pdwState AS DWORD _                          ' __out CDCONTROLSTATEF *pdwState
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetControlState ( _                           ' VTable offset = 56
     BYVAL dwIDCtl AS DWORD _                           ' __in DWORD dwIDCtl
   , BYVAL dwState AS DWORD _                           ' __in CDCONTROLSTATEF dwState
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetEditBoxText ( _                            ' VTable offset = 60
     BYVAL dwIDCtl AS DWORD _                           ' __in DWORD dwIDCtl
   , BYREF ppszText AS WSTRINGZ _                       ' __out WCHAR **ppszText
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetEditBoxText ( _                            ' VTable offset = 64
     BYVAL dwIDCtl AS DWORD _                           ' __in DWORD dwIDCtl
   , BYREF pszText AS WSTRINGZ _                        ' __in LPCWSTR pszText
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCheckButtonState ( _                       ' VTable offset = 68
     BYVAL dwIDCtl AS DWORD _                           ' __in DWORD dwIDCtl
   , BYREF pbChecked AS LONG _                          ' __out BOOL *pbChecked
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetCheckButtonState ( _                       ' VTable offset = 72
     BYVAL dwIDCtl AS DWORD _                           ' __in DWORD dwIDCtl
   , BYVAL bChecked AS LONG _                           ' __in BOOL bChecked
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddControlItem ( _                            ' VTable offset = 76
     BYVAL dwIDCtl AS DWORD _                           ' __in DWORD dwIDCtl
   , BYVAL dwIDItem AS DWORD _                          ' __in DWORD dwIDItem
   , BYREF pszLabel AS WSTRINGZ _                       ' __in LPCWSTR pszLabel
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RemoveControlItem ( _                         ' VTable offset = 80
     BYVAL dwIDCtl AS DWORD _                           ' __in DWORD dwIDCtl
   , BYVAL dwIDItem AS DWORD _                          ' __in DWORD dwIDItem
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RemoveAllControlItems ( _                     ' VTable offset = 84
     BYVAL dwIDCtl AS DWORD _                           ' __in DWORD dwIDCtl
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetControlItemState ( _                       ' VTable offset = 88
     BYVAL dwIDCtl AS DWORD _                           ' __in DWORD dwIDCtl
   , BYVAL dwIDItem AS DWORD _                          ' __in DWORD dwIDItem
   , BYREF pdwState AS DWORD _                          ' __out CDCONTROLSTATEF *pdwState
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetControlItemState ( _                       ' VTable offset = 92
     BYVAL dwIDCtl AS DWORD _                           ' __in DWORD dwIDCtl
   , BYVAL dwIDItem AS DWORD _                          ' __in DWORD dwIDItem
   , BYVAL dwState AS DWORD _                           ' __in CDCONTROLSTATEF dwState
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSelectedControlItem ( _                    ' VTable offset = 96
     BYVAL dwIDCtl AS DWORD _                           ' __in DWORD dwIDCtl
   , BYREF pdwIDItem AS DWORD _                         ' __out DWORD *pdwIDItem
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetSelectedControlItem ( _                    ' VTable offset = 100
     BYVAL dwIDCtl AS DWORD _                           ' __in DWORD dwIDCtl
   , BYVAL dwIDItem AS DWORD _                          ' __in DWORD dwIDItem
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD StartVisualGroup ( _                          ' VTable offset = 104
     BYVAL dwIDCtl AS DWORD _                           ' __in DWORD dwIDCtl
   , BYREF pszLabel AS WSTRINGZ _                       ' __in LPCWSTR pszLabel
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EndVisualGroup ( _                            ' VTable offset = 108
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD MakeProminent ( _                             ' VTable offset = 112
     BYVAL dwIDCtl AS DWORD _                           ' __in DWORD dwIDCtl
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetControlItemText ( _                        ' VTable offset = 116
     BYVAL dwIDCtl AS DWORD _                           ' __in DWORD dwIDCtl
   , BYVAL dwIDItem AS DWORD _                          ' __in DWORD dwIDItem
   , BYREF pszLabel AS WSTRINGZ _                       ' __in LPCWSTR pszLabel
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IFileDialogCustomize_INTERFACE_DEFINED__ */


' ########################################################################################
' IFileDialogControlEvents interface
' IID = 36116642-D713-4B97-9B83-7484A9D00433
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IFileDialogControlEvents_INTERFACE_DEFINED)
    %IFileDialogControlEvents_INTERFACE_DEFINED = 1

$IID_IFileDialogControlEvents = GUID$("{36116642-D713-4B97-9B83-7484A9D00433}")

INTERFACE IFileDialogControlEvents $IID_IFileDialogControlEvents

   INHERIT IUnknown

   ' =====================================================================================
   METHOD OnItemSelected ( _                            ' VTable offset = 12
     BYVAL pfdc AS IFileDialogCustomize _               ' __in IFileDialogCustomize *pfdc
   , BYVAL dwIDCtl AS DWORD _                           ' __in DWORD dwIDCtl
   , BYVAL dwIDItem AS DWORD _                          ' __in DWORD dwIDItem
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnButtonClicked ( _                           ' VTable offset = 16
     BYVAL pfdc AS IFileDialogCustomize _               ' __in IFileDialogCustomize *pfdc
   , BYVAL dwIDCtl AS DWORD _                           ' __in DWORD dwIDCtl
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnCheckButtonToggled ( _                      ' VTable offset = 20
     BYVAL pfdc AS IFileDialogCustomize _               ' __in IFileDialogCustomize *pfdc
   , BYVAL dwIDCtl AS DWORD _                           ' __in DWORD dwIDCtl
   , BYVAL bChecked AS LONG _                           ' __in BOOL bChecked
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnControlActivating ( _                       ' VTable offset = 24
     BYVAL pfdc AS IFileDialogCustomize _               ' __in IFileDialogCustomize *pfdc
   , BYVAL dwIDCtl AS DWORD _                           ' __in DWORD dwIDCtl
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IFileDialogControlEvents_INTERFACE_DEFINED__ */

' ########################################################################################
' IFileDialog2 interface
' IID = 61744FC7-85B5-4791-A9B0-272276309B13
' Inherited interface = IFileDialog
' ########################################################################################

#IF NOT %DEF(%IFileDialog2_INTERFACE_DEFINED)
    %IFileDialog2_INTERFACE_DEFINED = 1

$IID_IFileDialog2 = GUID$("{61744FC7-85B5-4791-A9B0-272276309B13}")

INTERFACE IFileDialog2 $IID_IFileDialog2

   INHERIT IUnknown

   ' =====================================================================================
   ' IModalWindow Method
   ' =====================================================================================
   METHOD Show ( _                                      ' VTable offset = 12
     BYVAL hwndParent AS DWORD _                        ' __in HWND hwndParent
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IFileDialog Methods
   ' =====================================================================================
   METHOD SetFileTypes ( _                              ' VTable offset = 16
     BYVAL cFileTypes AS DWORD _                        ' __in UINT cFileTypes
   , BYREF rgFilterSpec AS COMDLG_FILTERSPEC _          ' __in const COMDLG_FILTERSPEC *rgFilterSpec
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetFileTypeIndex ( _                          ' VTable offset = 20
     BYVAL iFileType AS DWORD _                         ' __in UINT iFileType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFileTypeIndex ( _                          ' VTable offset = 24
     BYREF piFileType AS DWORD _                        ' __out UINT *piFileType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Advise ( _                                    ' VTable offset = 28
     BYVAL pfde AS IFileDialogEvents _                  ' __in IFileDialogEvents *pfde
   , BYREF pdwCookie AS DWORD _                         ' __out DWORD *pdwCookie
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Unadvise ( _                                  ' VTable offset = 32
     BYVAL dwCookie AS DWORD _                          ' __in DWORD dwCookie
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetOptions ( _                                ' VTable offset = 36
     BYVAL fos AS DWORD _                               ' __in DWORD fos
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetOptions ( _                                ' VTable offset = 40
     BYREF pfos AS DWORD _                              ' __out DWORD *pfos
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetDefaultFolder ( _                          ' VTable offset = 44
     BYVAL psi AS IShellItem _                          ' __in IShellItem *psi
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetFolder ( _                                 ' VTable offset = 48
     BYVAL psi AS IShellItem _                          ' __in IShellItem *psi
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFolder ( _                                 ' VTable offset = 52
     BYREF ppsi AS IShellItem _                         ' __out IShellItem **ppsi
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCurrentSelection ( _                       ' VTable offset = 56
     BYREF ppsi AS IShellItem _                         ' __out IShellItem **ppsi
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetFileName ( _                               ' VTable offset = 60
     BYREF pszName AS WSTRINGZ _                        ' __in LPCWSTR pszName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFileName ( _                               ' VTable offset = 64
     BYREF pszName AS DWORD _                           ' __out LPWSTR *pszName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetTitle ( _                                  ' VTable offset = 68
     BYREF pszTitle AS WSTRINGZ _                       ' __in LPCWSTR pszTitle
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetOkButtonLabel ( _                          ' VTable offset = 72
     BYREF pszText AS WSTRINGZ _                        ' __in LPCWSTR pszText
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetFileNameLabel ( _                          ' VTable offset = 76
     BYREF pszLabel AS WSTRINGZ _                       ' __in LPCWSTR pszLabel
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetResult ( _                                 ' VTable offset = 80
     BYREF ppsi AS IShellItem _                         ' __out IShellItem **ppsi
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddPlace ( _                                  ' VTable offset = 84
     BYVAL psi AS IShellItem _                          ' __in IShellItem *psi
   , BYVAL fdap AS LONG _                               ' __in FDAP fdap
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetDefaultExtension ( _                       ' VTable offset = 88
     BYREF pszDefaultExtension AS WSTRINGZ _            ' __in LPCWSTR pszDefaultExtension
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Close ( _                                     ' VTable offset = 92
     BYVAL hr AS LONG _                                 ' __in HRESULT hr
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetClientGuid ( _                             ' VTable offset = 96
     BYREF guid AS GUID _                               ' __in REFGUID guid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ClearClientData ( _                           ' VTable offset = 100
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetFilter ( _                                 ' VTable offset = 104
     BYVAL pFilter AS IShellItemFilter _                ' __in IShellItemFilter *pFilter
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IFileDialog2 Methods
   ' =====================================================================================
   METHOD SetCancelButtonLabel ( _                      ' VTable offset = 108
     BYREF pszLabel AS WSTRINGZ _                       ' __in LPCWSTR pszLabel
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetNavigationRoot ( _                         ' VTable offset = 112
     BYVAL psi AS IShellItem _                          ' __in_opt IShellItem *psi
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IFileDialog2_INTERFACE_DEFINED__ */


' enum ASSOCIATIONLEVEL
%AL_MACHINE         = 0
%AL_EFFECTIVE       = %AL_MACHINE         + 1
%AL_USER            = %AL_EFFECTIVE       + 1

' enum ASSOCIATIONTYPE
%AT_FILEEXTENSION   = 0
%AT_URLPROTOCOL     = %AT_FILEEXTENSION   + 1
%AT_STARTMENUCLIENT = %AT_URLPROTOCOL     + 1
%AT_MIMETYPE        = %AT_STARTMENUCLIENT + 1


' ########################################################################################
' IApplicationAssociationRegistration interface
' IID = 4E530B0A-E611-4C77-A3AC-9031D022281B
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IApplicationAssociationRegistration_INTERFACE_DEFINED)
   %IApplicationAssociationRegistration_INTERFACE_DEFINED = 1

$IID_IApplicationAssociationRegistration = GUID$("{4E530B0A-E611-4C77-A3AC-9031D022281B}")

INTERFACE IApplicationAssociationRegistration $IID_IApplicationAssociationRegistration

   INHERIT IUnknown

   ' =====================================================================================
   METHOD QueryCurrentDefault ( _                       ' VTable offset = 12
     BYREF pszQuery AS WSTRINGZ _                       ' __in LPCWSTR pszQuery
   , BYVAL atQueryType AS LONG _                        ' __in ASSOCIATIONTYPE atQueryType
   , BYVAL alQueryLevel AS LONG _                       ' __in ASSOCIATIONLEVEL alQueryLevel
   , BYREF ppszAssociation AS DWORD _                   ' __out LPWSTR *ppszAssociation
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD QueryAppIsDefault ( _                         ' VTable offset = 16
     BYREF pszQuery AS WSTRINGZ _                       ' __in LPCWSTR pszQuery
   , BYVAL atQueryType AS LONG _                        ' __in ASSOCIATIONTYPE atQueryType
   , BYVAL alQueryLevel AS LONG _                       ' __in ASSOCIATIONLEVEL alQueryLevel
   , BYREF pszAppRegistryName AS WSTRINGZ _             ' __in LPCWSTR pszAppRegistryName
   , BYREF pfDefault AS LONG _                          ' __out BOOL *pfDefault
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD QueryAppIsDefaultAll ( _                      ' VTable offset = 20
     BYVAL alQueryLevel AS LONG _                       ' __in ASSOCIATIONLEVEL alQueryLevel
   , BYREF pszAppRegistryName AS WSTRINGZ _             ' __in LPCWSTR pszAppRegistryName
   , BYREF pfDefault AS LONG _                          ' __out BOOL *pfDefault
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetAppAsDefault ( _                           ' VTable offset = 24
     BYREF pszAppRegistryName AS WSTRINGZ _             ' __in LPCWSTR pszAppRegistryName
   , BYREF pszSet AS WSTRINGZ _                         ' __in LPCWSTR pszSet
   , BYVAL atSetType AS LONG _                          ' __in ASSOCIATIONTYPE atSetType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetAppAsDefaultAll ( _                        ' VTable offset = 28
     BYREF pszAppRegistryName AS WSTRINGZ _             ' __in LPCWSTR pszAppRegistryName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ClearUserAssociations ( _                     ' VTable offset = 32
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IApplicationAssociationRegistration_INTERFACE_DEFINED__ */

DECLARE FUNCTION SHCreateAssociationRegistration IMPORT "SHELL32.DLL" ALIAS "SHCreateAssociationRegistration" ( _
   BYREF riid AS GUID _                                 ' __in REFIID riid
 , BYREF ppv AS IUnknown _                              ' __out void **ppv
 ) AS LONG                                              ' HRESULT


' ########################################################################################
' IApplicationAssociationRegistrationUI interface
' IID = 1F76A169-F994-40AC-8FC8-0959E8874710
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IApplicationAssociationRegistrationUI_INTERFACE_DEFINED)
   %IApplicationAssociationRegistrationUI_INTERFACE_DEFINED = 1

$IID_IApplicationAssociationRegistrationUI = GUID$("{1F76A169-F994-40AC-8FC8-0959E8874710}")

INTERFACE IApplicationAssociationRegistrationUI $IID_IApplicationAssociationRegistrationUI

   INHERIT IUnknown

   ' =====================================================================================
   METHOD LaunchAdvancedAssociationUI ( _               ' VTable offset = 12
     BYREF pszAppRegistryName AS WSTRINGZ _             ' __in LPCWSTR pszAppRegistryName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IApplicationAssociationRegistrationUI_INTERFACE_DEFINED__ */

'#endif  // NTDDI_VISTA

'#include <pshpack1.h>
' // Size = 7 bytes
TYPE DELEGATEITEMID BYTE
   cbSize  AS WORD   ' WORD cbSize
   wOuter  AS WORD   ' WORD wOuter
   cbInner AS WORD   ' WORD cbInner
   rgb(0)  AS BYTE   ' BYTE rgb[ 1 ]
END TYPE
'#include <poppack.h>

' ########################################################################################
' IDelegateFolder interface
' IID = ADD8BA80-002B-11D0-8F0F-00C04FD7D062
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDelegateFolder_INTERFACE_DEFINED)
   %IDelegateFolder_INTERFACE_DEFINED = 1

$IID_IDelegateFolder = GUID$("{ADD8BA80-002B-11D0-8F0F-00C04FD7D062}")

INTERFACE IDelegateFolder $IID_IDelegateFolder

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetItemAlloc ( _                              ' VTable offset = 12
     BYVAL pmalloc AS IMalloc _                         ' __in IMalloc *pmalloc
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDelegateFolder_INTERFACE_DEFINED__ */


'#if (_WIN32_IE >= _WIN32_IE_IE60)
'// INTERFACE: IBrowserFrameOptions
'//
'// This interface was implemented so a browser or host can ask a ShellView/ShelNameSpace what
'// kind of 'Behavior' is appropriate for that view.
'//
'//    IBrowserFrameOptions::GetBrowserOptions()
'//       dwMask is the logical OR of bits to look for.  pdwOptions is not optional and
'//       it's return value will always equal or will be a subset of dwMask.
'//       If the function succeeds, the return value must be S_OK and pdwOptions needs to be filled in.
'//       If the function fails, pdwOptions needs to be filled in with BFO_NONE.
'//

' ########################################################################################
' IBrowserFrameOptions interface
' IID = 10DF43C8-1DBE-11D3-8B34-006097DF5BD4
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IBrowserFrameOptions_INTERFACE_DEFINED)
    %IBrowserFrameOptions_INTERFACE_DEFINED = 1

' enum BROWSERFRAMEOPTIONS
%BFO_NONE                             = 0???
%BFO_BROWSER_PERSIST_SETTINGS         = &H1???
%BFO_RENAME_FOLDER_OPTIONS_TOINTERNET = &H2???
%BFO_BOTH_OPTIONS                     = &H4???
%BIF_PREFER_INTERNET_SHORTCUT         = &H8???
%BFO_BROWSE_NO_IN_NEW_PROCESS         = &H10???
%BFO_ENABLE_HYPERLINK_TRACKING        = &H20???
%BFO_USE_IE_OFFLINE_SUPPORT           = &H40???
%BFO_SUBSTITUE_INTERNET_START_PAGE    = &H80???
%BFO_USE_IE_LOGOBANDING               = &H100???
%BFO_ADD_IE_TOCAPTIONBAR              = &H200???
%BFO_USE_DIALUP_REF                   = &H400???
%BFO_USE_IE_TOOLBAR                   = &H800???
%BFO_NO_PARENT_FOLDER_SUPPORT         = &H1000???
%BFO_NO_REOPEN_NEXT_RESTART           = &H2000???
%BFO_GO_HOME_PAGE                     = &H4000???
%BFO_PREFER_IEPROCESS                 = &H8000???
%BFO_SHOW_NAVIGATION_CANCELLED        = &H10000???
%BFO_USE_IE_STATUSBAR                 = &H20000???
%BFO_QUERY_ALL                        = &HFFFFFFFF&   ' ( int  )0xffffffff

'typedef DWORD BROWSERFRAMEOPTIONS;

$IID_IBrowserFrameOptions = GUID$("{10DF43C8-1DBE-11D3-8B34-006097DF5BD4}")

INTERFACE IBrowserFrameOptions $IID_IBrowserFrameOptions

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetFrameOptions ( _                           ' VTable offset = 12
     BYVAL dwMask AS DWORD _                            ' __in BROWSERFRAMEOPTIONS dwMask
   , BYREF pdwOptions AS DWORD _                        ' __out BROWSERFRAMEOPTIONS *pdwOptions
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IBrowserFrameOptions_INTERFACE_DEFINED__ */

'#endif  // _WIN32_IE_IE60

'#if (_WIN32_IE >= _WIN32_IE_IE60SP2)

' NWMF enum
%NWMF_UNLOADING        = &H0001
%NWMF_USERINITED       = &H0002
%NWMF_FIRST_USERINITED = &H0004
%NWMF_OVERRIDEKEY      = &H0008
%NWMF_SHOWHELP         = &H0010
%NWMF_HTMLDIALOG       = &H0020
'%NWMF_FROMPROXY        = &H0040   ' XP SDK
%NWMF_FROMDIALOGCHILD  = &H40
%NWMF_USERREQUESTED    = &H80
%NWMF_USERALLOWED      = &H100
%NWMF_FORCEWINDOW      = &H10000
%NWMF_FORCETAB         = &H20000
%NWMF_SUGGESTWINDOW    = &H40000
%NWMF_SUGGESTTAB       = &H80000
%NWMF_INACTIVETAB      = &H100000

' ########################################################################################
' INewWindowManager interface
' IID = D2BC4C84-3F72-4A52-A604-7BCBF3982CBB
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%INewWindowManager_INTERFACE_DEFINED)
    %INewWindowManager_INTERFACE_DEFINED = 1

$IID_INewWindowManager = GUID$("{D2BC4C84-3F72-4A52-A604-7BCBF3982CBB}")
$SID_INewWindowManager = GUID$("{D2BC4C84-3F72-4A52-A604-7BCBF3982CBB}")

INTERFACE INewWindowManager $IID_INewWindowManager

   INHERIT IUnknown

   ' =====================================================================================
   METHOD EvaluateNewWindow ( _                         ' VTable offset = 12
     BYREF pszUrl AS WSTRINGZ _                         ' __in LPCWSTR pszUrl
   , BYREF pszName AS WSTRINGZ _                        ' __in LPCWSTR pszName
   , BYREF pszUrlContext AS WSTRINGZ _                  ' __in LPCWSTR pszUrlContext
   , BYREF pszFeatures AS WSTRINGZ _                    ' __in LPCWSTR pszFeatures
   , BYVAL fReplace AS LONG _                           ' __in BOOL fReplace
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYVAL dwUserActionTime AS DWORD _                  ' __in DWORD dwUserActionTime
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __INewWindowManager_INTERFACE_DEFINED__ */


' ########################################################################################
' IAttachmentExecute interface
' IID = 73DB1241-1E85-4581-8E4F-A81E1D0F8C57
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IAttachmentExecute_INTERFACE_DEFINED)
    %IAttachmentExecute_INTERFACE_DEFINED = 1

$IID_IAttachmentExecute = GUID$("{73DB1241-1E85-4581-8E4F-A81E1D0F8C57}")

' enum ATTACHMENT_PROMPT
%ATTACHMENT_PROMPT_NONE         = 0
%ATTACHMENT_PROMPT_SAVE         = &H1
%ATTACHMENT_PROMPT_EXEC         = &H2
%ATTACHMENT_PROMPT_EXEC_OR_SAVE = &H3

' enum ATTACHMENT_ACTION
%ATTACHMENT_ACTION_CANCEL       = 0
%ATTACHMENT_ACTION_SAVE         = &H1
%ATTACHMENT_ACTION_EXEC         = &H2

INTERFACE IAttachmentExecute $IID_IAttachmentExecute

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetClientTitle ( _                            ' VTable offset = 12
     BYREF pszTitle AS WSTRINGZ _                       ' __in LPCWSTR pszTitle
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetClientGuid ( _                             ' VTable offset = 16
     BYREF guid AS GUID _                               ' __in REFGUID guid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetLocalPath ( _                              ' VTable offset = 20
     BYREF pszLocalPath AS WSTRINGZ _                   ' __in LPCWSTR pszLocalPath
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetFileName ( _                               ' VTable offset = 24
     BYREF pszFileName AS WSTRINGZ _                    ' __in LPCWSTR pszFileName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetSource ( _                                 ' VTable offset = 28
     BYREF pszSource AS WSTRINGZ _                      ' __in LPCWSTR pszSource
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetReferrer ( _                               ' VTable offset = 32
     BYREF pszReferrer AS WSTRINGZ _                    ' __in LPCWSTR pszReferrer
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CheckPolicy ( _                               ' VTable offset = 36
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Prompt ( _                                    ' VTable offset = 40
     BYVAL hwnd AS DWORD _                              ' __in HWND hwnd
   , BYVAL prompt AS LONG _                             ' __in ATTACHMENT_PROMPT prompt
   , BYVAL paction AS LONG _                            ' __out ATTACHMENT_ACTION *paction
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Save ( _                                      ' VTable offset = 44
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Execute ( _                                   ' VTable offset = 48
     BYVAL hwnd AS DWORD _                              ' __in HWND hwnd
   , BYREF pszVerb AS WSTRINGZ _                        ' __in LPCWSTR pszVerb
   , BYREF phProcess AS DWORD _                         ' __out HANDLE *phProcess
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SaveWithUI ( _                                ' VTable offset = 52
     BYVAL hwnd AS DWORD _                              ' __in HWND hwnd
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ClearClientState ( _                          ' VTable offset = 56
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAttachmentExecute_INTERFACE_DEFINED__ */

'#endif  // _WIN32_IE_IE60SP2

'#if (_WIN32_IE >= _WIN32_IE_IE60)
'#include <pshpack8.h>
' // Size = 48 bytes
TYPE SMDATA DWORD
   dwMask      AS DWORD            ' DWORD dwMask
   dwFlags     AS DWORD            ' DWORD dwFlags
   hmenu       AS DWORD            ' HMENU hmenu
   hwnd        AS DWORD            ' HWND hwnd
   uId         AS DWORD            ' UINT uId
   UIDParent   AS DWORD            ' UINT uIdParent
   uIdAncestor AS DWORD            ' UINT uIdAncestor
   punk        AS DWORD PTR        ' IUnknown *punk
   pidlFolder  AS ITEMIDLIST PTR   ' LPITEMIDLIST pidlFolder
   pidlItem    AS ITEMIDLIST PTR   ' LPITEMIDLIST pidlItem
   psf         AS DWORD PTR        ' IShellFolder *psf
   pvUserData  AS DWORD            ' void *pvUserData
END TYPE

'// Mask
%SMDM_SHELLFOLDER      = &H00000001???   ' // This is for an item in the band
%SMDM_HMENU            = &H00000002???   ' // This is for the Band itself
%SMDM_TOOLBAR          = &H00000004???   ' // Plain toolbar, not associated with a shell folder or hmenu
'// Flags (bitmask)

' // Size = 16 bytes
TYPE SMINFO DWORD
   dwMask  AS DWORD   ' DWORD dwMask
   dwType  AS DWORD   ' DWORD dwType
   dwFlags AS DWORD   ' DWORD dwFlags
   iIcon   AS LONG    ' int iIcon
END TYPE

' // Size = 12 bytes
TYPE SMCSHCHANGENOTIFYSTRUCT DWORD
   lEvent AS LONG             ' LONG lEvent
   pidl1  AS ITEMIDLIST PTR   ' PCIDLIST_ABSOLUTE pidl1
   pidl2  AS ITEMIDLIST PTR   ' PCIDLIST_ABSOLUTE pidl2
END TYPE

'#include <poppack.h>

' enum SMINFOMASK
%SMIM_TYPE             = &H1???
%SMIM_FLAGS            = &H2???
%SMIM_ICON             = &H4???

' enum SMINFOTYPE
%SMIT_SEPARATOR        = &H1???
%SMIT_STRING           = &H2???

' enum SMINFOFLAGS
%SMIF_ICON             = &H1???
%SMIF_ACCELERATOR      = &H2???
%SMIF_DROPTARGET       = &H4???
%SMIF_SUBMENU          = &H8???
%SMIF_CHECKED          = &H20???
%SMIF_DROPCASCADE      = &H40???
%SMIF_HIDDEN           = &H80???
%SMIF_DISABLED         = &H100???
%SMIF_TRACKPOPUP       = &H200???
%SMIF_DEMOTED          = &H400???
%SMIF_ALTSTATE         = &H800???
%SMIF_DRAGNDROP        = &H1000???
%SMIF_NEW              = &H2000???

%SMC_INITMENU               = &H00000001???   ' // The callback is called to init a menuband
%SMC_CREATE                 = &H00000002???
%SMC_EXITMENU               = &H00000003???   ' // The callback is called when menu is collapsing
%SMC_GETINFO                = &H00000005???   ' // The callback is called to return DWORD values
%SMC_GETSFINFO              = &H00000006???   ' // The callback is called to return DWORD values
%SMC_GETOBJECT              = &H00000007???   ' // The callback is called to get some object
%SMC_GETSFOBJECT            = &H00000008???   ' // The callback is called to get some object
%SMC_SFEXEC                 = &H00000009???   ' // The callback is called to execute an shell folder item
%SMC_SFSELECTITEM           = &H0000000A???   ' // The callback is called when an item is selected
%SMC_REFRESH                = &H00000010???   ' // Menus have completely refreshed. Reset your state.
%SMC_DEMOTE                 = &H00000011???   ' // Demote an item
%SMC_PROMOTE                = &H00000012???   ' // Promote an item, wParam = SMINV_* flag
%SMC_DEFAULTICON            = &H00000016???   ' // Returns Default icon location in wParam, index in lParam
%SMC_NEWITEM                = &H00000017???   ' // Notifies item is not in the order stream.
%SMC_CHEVRONEXPAND          = &H00000019???   ' // Notifies of a expansion via the chevron
%SMC_DISPLAYCHEVRONTIP      = &H0000002A???   ' // S_OK display, S_FALSE not.
%SMC_SETSFOBJECT            = &H0000002D???   ' // Called to save the passed object
%SMC_SHCHANGENOTIFY         = &H0000002E???   ' // Called when a Change notify is received. lParam points to SMCSHCHANGENOTIFYSTRUCT
%SMC_CHEVRONGETTIP          = &H0000002F???   ' // Called to get the chevron tip text. wParam = Tip title, Lparam = TipText Both MAX_PATH
%SMC_SFDDRESTRICTED         = &H00000030???   ' // Called requesting if it's ok to drop. wParam = IDropTarget.
'#if (_WIN32_IE >= _WIN32_IE_IE70)
%SMC_SFEXEC_MIDDLE          = &H00000031???   ' // Same as SFEXEC, but the middle mouse button caused the exec.
%SMC_GETAUTOEXPANDSTATE     = &H00000041???   ' // callback returns the default autoexpand state lParam = LPDWORD to recieve flags
%SMC_AUTOEXPANDCHANGE       = &H00000042???   ' // Notify that the menu is expanding/contracting
%SMC_GETCONTEXTMENUMODIFIER = &H00000043???   ' // Used to add items to a context menu
%SMC_GETBKCONTEXTMENU       = &H00000044???   ' // used to get a context menu to display when user right clicks on the background
%SMC_OPEN                   = &H00000045???   ' // allows client to overwrite open/explore verb action on an item
' // Flags for return value from SMC_GETAUTOEXPANDSTATE and SMC_AUTOEXPANDCHANGE:
%SMAE_EXPANDED              = &H00000001???   ' // The menu is or should start expanded
%SMAE_CONTRACTED            = &H00000002???   ' // The menu is or should start contracted
                                              ' // SMAE_EXPANDED and SMAE_CONTRACTED are mutually exclusive
%SMAE_USER                  = &H00000004???   ' // Indicates that the menu expansion/contraction is a reflection
                                              ' // of user choice
%SMAE_VALID                 = &H00000007???
'#endif  // _WIN32_IE_IE70

' ########################################################################################
' IShellMenuCallback interface
' IID = 4CA300A1-9B8D-11D1-8B22-00C04FD918D0
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IShellMenuCallback_INTERFACE_DEFINED)
    %IShellMenuCallback_INTERFACE_DEFINED = 1

$IID_IShellMenuCallback = GUID$("{4CA300A1-9B8D-11D1-8B22-00C04FD918D0}")

INTERFACE IShellMenuCallback $IID_IShellMenuCallback

   INHERIT IUnknown

   ' =====================================================================================
   METHOD CallbackSM ( _                                ' VTable offset = 12
     BYREF psmd AS SMDATA _                             ' __inout LPSMDATA psmd
   , BYVAL uMsg AS DWORD _                              ' __in UINT uMsg
   , BYVAL wParam AS DWORD _                            ' __in WPARAM wParam
   , BYVAL lParam AS LONG _                             ' __in LPARAM lParam
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IShellMenuCallback_INTERFACE_DEFINED__ */

%SMINIT_DEFAULT           = &H00000000???  ' // No Options
%SMINIT_RESTRICT_DRAGDROP = &H00000002???  ' // Don't allow Drag and Drop
%SMINIT_TOPLEVEL          = &H00000004???  ' // This is the top band.
%SMINIT_CACHED            = &H00000010???
'#if (_WIN32_IE >= _WIN32_IE_IE70)
%SMINIT_AUTOEXPAND        = &H00000100???  ' // automatically expand/contract menu band
%SMINIT_AUTOTOOLTIP       = &H00000200???  ' // regular tooltip support
%SMINIT_DROPONCONTAINER   = &H00000400???  ' // allow drop on a container
'#endif  // _WIN32_IE_IE70
%SMINIT_VERTICAL          = &H10000000???  ' // This is a vertical menu
%SMINIT_HORIZONTAL        = &H20000000???  ' // This is a horizontal menu    (does not inherit)
%ANCESTORDEFAULT          = &HFFFFFFFF???  ' (UINT)-1
%SMSET_TOP                = &H10000000???  ' // Bias this namespace to the top of the menu
%SMSET_BOTTOM             = &H20000000???  ' // Bias this namespace to the bottom of the menu
%SMSET_DONTOWN            = &H00000001???  ' // The Menuband doesn't own the non-ref counted object
%SMINV_REFRESH            = &H00000001???
%SMINV_ID                 = &H00000008???

' ########################################################################################
' IShellMenu interface
' IID = EE1F7637-E138-11D1-8379-00C04FD918D0
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IShellMenu_INTERFACE_DEFINED)
    %IShellMenu_INTERFACE_DEFINED = 1

$IID_IShellMenu = GUID$("{EE1F7637-E138-11D1-8379-00C04FD918D0}")

INTERFACE IShellMenu $IID_IShellMenu

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Initialize ( _                                ' VTable offset = 12
     BYVAL psmc AS IShellMenuCallback _                 ' __in IShellMenuCallback *psmc
   , BYVAL uId AS DWORD _                               ' __in UINT uId
   , BYVAL uIdAncestor AS DWORD _                       ' __in UINT uIdAncestor
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMenuInfo ( _                               ' VTable offset = 16
     BYREF ppsmc AS IShellMenuCallback _                ' __out IShellMenuCallback **ppsmc
   , BYREF puId AS DWORD _                              ' __out UINT *puId
   , BYREF puIdAncestor AS DWORD _                      ' __out UINT *puIdAncestor
   , BYREF pdwFlags AS DWORD _                          ' __out DWORD *pdwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetShellFolder ( _                            ' VTable offset = 20
     BYVAL psf AS IShellFolder _                        ' __in IShellFolder *psf
   , BYVAL pidlFolder AS DWORD _                        ' __in LPCITEMIDLIST pidlFolder
   , BYVAL hKey AS DWORD _                              ' __in HKEY hKey
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetShellFolder ( _                            ' VTable offset = 24
     BYREF pdwFlags AS DWORD _                          ' __out DWORD *pdwFlags
   , BYREF ppidl AS DWORD _                             ' __out LPITEMIDLIST *ppidl
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppv AS IUnknown _                            ' __out void **ppv
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetMenu ( _                                   ' VTable offset = 28
     BYVAL hmenu AS DWORD _                             ' __in HMENU hmenu
   , BYVAL hwnd AS DWORD _                              ' __in HWND hwnd
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetMenu ( _                                   ' VTable offset = 32
     BYREF phmenu AS DWORD _                            ' __out HMENU *phmenu
   , BYREF phwnd AS DWORD _                             ' __out HWND *phwnd
   , BYREF pdwFlags AS DWORD _                          ' __out DWORD *pdwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD InvalidateItem ( _                            ' VTable offset = 36
     BYREF psmd AS SMDATA _                             ' __in LPSMDATA psmd
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetState ( _                                  ' VTable offset = 40
     BYREF psmd AS SMDATA _                             ' __out LPSMDATA psmd
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetMenuToolbar ( _                            ' VTable offset = 44
     BYVAL punk AS IUnknown _                           ' __in IUnknown *punk
   , BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IShellMenu_INTERFACE_DEFINED__ */

'#endif  // _WIN32_IE_IE60


' ########################################################################################
' IShellRunDll interface
' IID = FCE4BDE0-4B68-4B80-8E9C-7426315A7388
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IShellRunDll_INTERFACE_DEFINED)
    %IShellRunDll_INTERFACE_DEFINED = 1

$IID_IShellRunDll = GUID$("{FCE4BDE0-4B68-4B80-8E9C-7426315A7388}")

INTERFACE IShellRunDll $IID_IShellRunDll

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Run ( _                                       ' VTable offset = 12
     BYREF pszArgs AS WSTRINGZ _                        ' __in LPCWSTR pszArgs
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IShellRunDll_INTERFACE_DEFINED__ */


'#if (NTDDI_VERSION >= NTDDI_VISTA)

' enum KF_CATEGORY
%KF_CATEGORY_VIRTUAL = &H1???
%KF_CATEGORY_FIXED   = &H2???
%KF_CATEGORY_COMMON  = &H3???
%KF_CATEGORY_PERUSER = &H4???
'typedef enum tagKF_CATEGORY KF_CATEGORY;

' enum KF_DEFINITION_FLAGS
%KFDF_LOCAL_REDIRECT_ONLY = &H2???
%KFDF_ROAMABLE            = &H4???
%KFDF_PRECREATE           = &H8???
%KFDF_STREAM              = &H10???
%KFDF_PUBLISHEXPANDEDPATH = &H20???
'typedef DWORD KF_DEFINITION_FLAGS;

' enum KF_REDIRECT_FLAGS
%KF_REDIRECT_USER_EXCLUSIVE               = &H1???
%KF_REDIRECT_COPY_SOURCE_DACL             = &H2???
%KF_REDIRECT_OWNER_USER                   = &H4???
%KF_REDIRECT_SET_OWNER_EXPLICIT           = &H8???
%KF_REDIRECT_CHECK_ONLY                   = &H10???
%KF_REDIRECT_WITH_UI                      = &H20???
%KF_REDIRECT_UNPIN                        = &H40???
%KF_REDIRECT_PIN                          = &H80???
%KF_REDIRECT_COPY_CONTENTS                = &H200???
%KF_REDIRECT_DEL_SOURCE_CONTENTS          = &H400???
%KF_REDIRECT_EXCLUDE_ALL_KNOWN_SUBFOLDERS = &H800???
'typedef DWORD KF_REDIRECT_FLAGS;

' enum KF_REDIRECTION_CAPABILITIES
%KF_REDIRECTION_CAPABILITIES_ALLOW_ALL              = &Hff???
%KF_REDIRECTION_CAPABILITIES_REDIRECTABLE           = &H1???
%KF_REDIRECTION_CAPABILITIES_DENY_ALL               = &Hfff00???
%KF_REDIRECTION_CAPABILITIES_DENY_POLICY_REDIRECTED = &H100???
%KF_REDIRECTION_CAPABILITIES_DENY_POLICY            = &H200???
%KF_REDIRECTION_CAPABILITIES_DENY_PERMISSIONS       = &H400???
'typedef DWORD KF_REDIRECTION_CAPABILITIES;

' // Size = 76 bytes
TYPE KNOWNFOLDER_DEFINITION DWORD
   category         AS DWORD          ' KF_CATEGORY
   pszName          AS WSTRINGZ PTR   ' LPWSTR
   pszDescription   AS WSTRINGZ PTR   ' LPWSTR
   fidParent        AS GUID           ' KNOWNFOLDERID
   pszRelativePath  AS WSTRINGZ PTR   ' LPWSTR
   pszParsingName   AS WSTRINGZ PTR   ' LPWSTR
   pszTooltip       AS WSTRINGZ PTR   ' LPWSTR
   pszLocalizedName AS WSTRINGZ PTR   ' LPWSTR
   pszIcon          AS WSTRINGZ PTR   ' LPWSTR
   pszSecurity      AS WSTRINGZ PTR   ' LPWSTR
   dwAttributes     AS DWORD          ' DWORD
   kfdFlags         AS DWORD          ' KF_DEFINITION_FLAGS
   ftidType         AS GUID           ' FOLDERTYPEID
END TYPE


' ########################################################################################
' IKnownFolder interface
' IID = 3AA7AF7E-9B36-420C-A8E3-F77D4674A488
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IKnownFolder_INTERFACE_DEFINED)
    %IKnownFolder_INTERFACE_DEFINED = 1

$IID_IKnownFolder = GUID$("{3AA7AF7E-9B36-420C-A8E3-F77D4674A488}")

INTERFACE IKnownFolder $IID_IKnownFolder

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetId ( _                                     ' VTable offset = 12
     BYREF pkfid AS GUID _                              ' __out KNOWNFOLDERID *pkfid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCategory ( _                               ' VTable offset = 16
     BYREF pCategory AS DWORD _                         ' __out KF_CATEGORY *pCategory
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetShellItem ( _                              ' VTable offset = 20
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppv AS IUnknown _                            ' __out void **ppv
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPath ( _                                   ' VTable offset = 24
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF ppszPath AS DWORD _                          ' __out LPWSTR *ppszPath
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetPath ( _                                   ' VTable offset = 28
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF pszPath AS WSTRINGZ _                        ' __in LPCWSTR pszPath
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetIDList ( _                                 ' VTable offset = 32
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   , BYREF ppidl AS DWORD _                             ' __out PIDLIST_ABSOLUTE *ppidl
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFolderType ( _                             ' VTable offset = 36
     BYREF pftid AS GUID _                              ' __out FOLDERTYPEID *pftid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRedirectionCapabilities ( _                ' VTable offset = 40
     BYREF pCapabilities AS DWORD _                     ' __out KF_REDIRECTION_CAPABILITIES *pCapabilities
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFolderDefinition ( _                       ' VTable offset = 44
     BYREF pKFD AS KNOWNFOLDER_DEFINITION _             ' __out KNOWNFOLDER_DEFINITION *pKFD
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IKnownFolder_INTERFACE_DEFINED__ */


' ########################################################################################
' IKnownFolderManager interface
' IID = 8BE2D872-86AA-4D47-B776-32CCA40C7018
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IKnownFolderManager_INTERFACE_DEFINED)
    %IKnownFolderManager_INTERFACE_DEFINED = 1

$IID_IKnownFolderManager = GUID$("{8BE2D872-86AA-4D47-B776-32CCA40C7018}")

' enum FFFP_MODE
%FFFP_EXACTMATCH         = 0
%FFFP_NEARESTPARENTMATCH = %FFFP_EXACTMATCH + 1

INTERFACE IKnownFolderManager $IID_IKnownFolderManager

   INHERIT IUnknown

   ' =====================================================================================
   METHOD FolderIdFromCsidl ( _                         ' VTable offset = 12
     BYVAL nCsidl AS LONG _                             ' __in int nCsidl
   , BYREF pfid AS GUID _                               ' __out KNOWNFOLDERID *pfid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD FolderIdToCsidl ( _                           ' VTable offset = 16
     BYREF rfid AS GUID _                               ' __in REFKNOWNFOLDERID rfid
   , BYREF pnCsidl AS LONG _                            ' __out int *pnCsidl
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFolderIds ( _                              ' VTable offset = 16
     BYREF ppKFId AS GUID _                             ' __out KNOWNFOLDERID **ppKFId
   , BYREF pCount AS DWORD _                            ' __inout UINT *pCount
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFolder ( _                                 ' VTable offset = 20
     BYREF rfid AS GUID _                               ' __in REFKNOWNFOLDERID rfid
   , BYREF ppkf AS IKnownFolder _                       ' __out IKnownFolder **ppkf
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFolderByName ( _                           ' VTable offset = 24
     BYREF pszCanonicalName AS WSTRINGZ _               ' __in LPCWSTR pszCanonicalName
   , BYREF ppkf AS IKnownFolder _                       ' __out IKnownFolder **ppkf
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RegisterFolder ( _                            ' VTable offset = 28
     BYREF rfid AS GUID _                               ' __in REFKNOWNFOLDERID rfid
   , BYREF pKFD AS KNOWNFOLDER_DEFINITION _             ' __in const KNOWNFOLDER_DEFINITION *pKFD
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD UnregisterFolder ( _                          ' VTable offset = 32
     BYREF rfid AS GUID _                               ' __in REFKNOWNFOLDERID rfid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD FindFolderFromPath ( _                        ' VTable offset = 36
     BYREF pszPath AS WSTRINGZ _                        ' __in LPCWSTR pszPath
   , BYVAL mode AS LONG _                               ' __in FFFP_MODE mode
   , BYREF ppkf AS IKnownFolder _                       ' __out IKnownFolder **ppkf
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD FindFolderFromIDList ( _                      ' VTable offset = 40
     BYVAL pidl AS DWORD _                              ' __in PCIDLIST_ABSOLUTE pidl
   , BYREF ppkf AS IKnownFolder _                       ' __out IKnownFolder **ppkf
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Redirect ( _                                  ' VTable offset = 44
     BYREF rfid AS GUID _                               ' __in REFKNOWNFOLDERID rfid
   , BYVAL hwnd AS DWORD _                              ' __in HWND hwnd
   , BYVAL flags AS DWORD _                             ' __in KF_REDIRECT_FLAGS flags
   , BYREF pszTargetPath AS WSTRINGZ _                  ' __in LPCWSTR pszTargetPath
   , BYVAL cFolders AS DWORD _                          ' __in UINT cFolders
   , BYREF pExclusion AS GUID _                         ' __in const KNOWNFOLDERID *pExclusion
   , BYREF ppszError AS DWORD _                         ' __out LPWSTR *ppszError
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IKnownFolderManager_INTERFACE_DEFINED__ */

SUB FreeKnownFolderDefinitionFields(BYREF pKFD AS KNOWNFOLDER_DEFINITION)
   CoTaskMemFree(BYVAL pKFD.pszName)
   CoTaskMemFree(BYVAL pKFD.pszDescription)
   CoTaskMemFree(BYVAL pKFD.pszRelativePath)
   CoTaskMemFree(BYVAL pKFD.pszParsingName)
   CoTaskMemFree(BYVAL pKFD.pszTooltip)
   CoTaskMemFree(BYVAL pKFD.pszLocalizedName)
   CoTaskMemFree(BYVAL pKFD.pszIcon)
   CoTaskMemFree(BYVAL pKFD.pszSecurity)
END SUB

' enum SHARE_ROLE
%SHARE_ROLE_INVALID     = -1
%SHARE_ROLE_READER      = 0
%SHARE_ROLE_CONTRIBUTOR = 1
%SHARE_ROLE_CO_OWNER    = 2
%SHARE_ROLE_OWNER       = 3
%SHARE_ROLE_CUSTOM      = 4
%SHARE_ROLE_MIXED       = 5

' enum DEF_SHARE_ID
%DEFSHAREID_USERS       = 1
%DEFSHAREID_PUBLIC      = 2

' ########################################################################################
' ISharingConfigurationManager interface
' IID = B4CD448A-9C86-4466-9201-2E62105B87AE
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ISharingConfigurationManager_INTERFACE_DEFINED)
    %ISharingConfigurationManager_INTERFACE_DEFINED = 1

$IID_ISharingConfigurationManager = GUID$("{B4CD448A-9C86-4466-9201-2E62105B87AE}")

INTERFACE ISharingConfigurationManager $IID_ISharingConfigurationManager

   INHERIT IUnknown

   ' =====================================================================================
   METHOD CreateShare ( _                               ' VTable offset = 12
     BYVAL dsid AS LONG _                               ' __in DEF_SHARE_ID dsid
   , BYVAL role AS LONG _                               ' __in SHARE_ROLE role
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DeleteShare ( _                               ' VTable offset = 16
     BYVAL dsid AS LONG _                               ' __in DEF_SHARE_ID dsid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ShareExists ( _                               ' VTable offset = 20
     BYVAL dsid AS LONG _                               ' __in DEF_SHARE_ID dsid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSharePermissions ( _                       ' VTable offset = 24
     BYVAL dsid AS LONG _                               ' __in DEF_SHARE_ID dsid
   , BYREF pRole AS LONG _                              ' __out SHARE_ROLE *pRole
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SharePrinters ( _                             ' VTable offset = 28
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD StopSharingPrinters ( _                       ' VTable offset = 32
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ArePrintersShared ( _                         ' VTable offset = 36
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ISharingConfigurationManager_INTERFACE_DEFINED__ */

'#endif  // NTDDI_VISTA


' ########################################################################################
' IPreviousVersionsInfo interface
' IID = 76E54780-AD74-48E3-A695-3BA9A0AFF10D
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IPreviousVersionsInfo_INTERFACE_DEFINED)
    %IPreviousVersionsInfo_INTERFACE_DEFINED = 1

$IID_IPreviousVersionsInfo = GUID$("{76E54780-AD74-48E3-A695-3BA9A0AFF10D}")

INTERFACE IPreviousVersionsInfo $IID_IPreviousVersionsInfo

   INHERIT IUnknown

   ' =====================================================================================
   METHOD AreSnapshotsAvailable ( _                     ' VTable offset = 12
     BYREF pszPath AS WSTRINGZ _                        ' __in LPCWSTR pszPath
   , BYVAL fOkToBeSlow AS LONG _                        ' __in BOOL fOkToBeSlow
   , BYREF pfAvailable AS LONG _                        ' __out BOOL *pfAvailable
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IPreviousVersionsInfo_INTERFACE_DEFINED__ */

'#if (NTDDI_VERSION >= NTDDI_VISTA)

' ########################################################################################
' IRelatedItem interface
' IID = A73CE67A-8AB1-44F1-8D43-D2FCBF6B1CD0
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IRelatedItem_INTERFACE_DEFINED)
    %IRelatedItem_INTERFACE_DEFINED = 1

$IID_IRelatedItem = GUID$("{A73CE67A-8AB1-44F1-8D43-D2FCBF6B1CD0}")

INTERFACE IRelatedItem $IID_IRelatedItem

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetItemIDList ( _                             ' VTable offset = 12
     BYREF ppidl AS DWORD _                             ' __out PIDLIST_ABSOLUTE *ppidl
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetItem ( _                                   ' VTable offset = 16
     BYREF ppsi AS IShellItem _                         ' __out IShellItem **ppsi
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IRelatedItem_INTERFACE_DEFINED__ */


' ########################################################################################
' IIdentityName interface
' IID = 7D903FCA-D6F9-4810-8332-946C0177E247
' Inherited interface = IRelatedItem
' ########################################################################################

#IF NOT %DEF(%IIdentityName_INTERFACE_DEFINED)
    %IIdentityName_INTERFACE_DEFINED = 1

$IID_IIdentityName = GUID$("{7D903FCA-D6F9-4810-8332-946C0177E247}")

INTERFACE IIdentityName $IID_IIdentityName

   INHERIT IUnknown

   ' =====================================================================================
   ' IRelatedItem Methods
   ' =====================================================================================
   METHOD GetItemIDList ( _                             ' VTable offset = 12
     BYREF ppidl AS DWORD _                             ' __out PIDLIST_ABSOLUTE *ppidl
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetItem ( _                                   ' VTable offset = 16
     BYREF ppsi AS IShellItem _                         ' __out IShellItem **ppsi
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IIdentityName Methods
   ' =====================================================================================
   ' No additional methods

END INTERFACE

#ENDIF   ' /* __IIdentityName_INTERFACE_DEFINED__ */


' ########################################################################################
' IDelegateItem interface
' IID = 7D903FCA-D6F9-4810-8332-946C0177E247
' Inherited interface = IRelatedItem
' ########################################################################################

#IF NOT %DEF(%IDelegateItem_INTERFACE_DEFINED)
    %IDelegateItem_INTERFACE_DEFINED = 1

$IID_IDelegateItem = GUID$("{7D903FCA-D6F9-4810-8332-946C0177E247}")

INTERFACE IDelegateItem $IID_IDelegateItem

   INHERIT IUnknown

   ' =====================================================================================
   ' IRelatedItem Methods
   ' =====================================================================================
   METHOD GetItemIDList ( _                             ' VTable offset = 12
     BYREF ppidl AS DWORD _                             ' __out PIDLIST_ABSOLUTE *ppidl
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetItem ( _                                   ' VTable offset = 16
     BYREF ppsi AS IShellItem _                         ' __out IShellItem **ppsi
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IDelegateItem Methods
   ' =====================================================================================
   ' No additional methods

END INTERFACE

#ENDIF   ' /* __IDelegateItem_INTERFACE_DEFINED__ */


' ########################################################################################
' ICurrentItem interface
' IID = 240A7174-D653-4A1D-A6D3-D4943CFBFE3D
' Inherited interface = IRelatedItem
' ########################################################################################

#IF NOT %DEF(%ICurrentItem_INTERFACE_DEFINED)
    %ICurrentItem_INTERFACE_DEFINED = 1

$IID_ICurrentItem = GUID$("{240A7174-D653-4A1D-A6D3-D4943CFBFE3D}")

INTERFACE ICurrentItem $IID_ICurrentItem

   INHERIT IUnknown

   ' =====================================================================================
   ' IRelatedItem Methods
   ' =====================================================================================
   METHOD GetItemIDList ( _                             ' VTable offset = 12
     BYREF ppidl AS DWORD _                             ' __out PIDLIST_ABSOLUTE *ppidl
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetItem ( _                                   ' VTable offset = 16
     BYREF ppsi AS IShellItem _                         ' __out IShellItem **ppsi
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' ICurrentItem Methods
   ' =====================================================================================
   ' No additional methods

END INTERFACE

#ENDIF   ' /* __ICurrentItem_INTERFACE_DEFINED__ */


' ########################################################################################
' ITransferMediumItem interface
' IID = 77F295D5-2D6F-4E19-B8AE-322F3E721AB5
' Inherited interface = IRelatedItem
' ########################################################################################

#IF NOT %DEF(%ITransferMediumItem_INTERFACE_DEFINED)
    %ITransferMediumItem_INTERFACE_DEFINED = 1

$IID_ITransferMediumItem = GUID$("{77F295D5-2D6F-4E19-B8AE-322F3E721AB5}")

INTERFACE ITransferMediumItem $IID_ITransferMediumItem

   INHERIT IUnknown

   ' =====================================================================================
   ' IRelatedItem Methods
   ' =====================================================================================
   METHOD GetItemIDList ( _                             ' VTable offset = 12
     BYREF ppidl AS DWORD _                             ' __out PIDLIST_ABSOLUTE *ppidl
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetItem ( _                                   ' VTable offset = 16
     BYREF ppsi AS IShellItem _                         ' __out IShellItem **ppsi
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITransferMediumItem_INTERFACE_DEFINED__ */


' ########################################################################################
' IUseToBrowseItem interface
' IID = 05EDDA5C-98A3-4717-8ADB-C5E7DA991EB1
' Inherited interface = IRelatedItem
' ########################################################################################

#IF NOT %DEF(%IUseToBrowseItem_INTERFACE_DEFINED)
    %IUseToBrowseItem_INTERFACE_DEFINED = 1

$IID_IUseToBrowseItem = GUID$("{05EDDA5C-98A3-4717-8ADB-C5E7DA991EB1}")

INTERFACE IUseToBrowseItem $IID_IUseToBrowseItem

   INHERIT IUnknown

   ' =====================================================================================
   ' IRelatedItem Methods
   ' =====================================================================================
   METHOD GetItemIDList ( _                             ' VTable offset = 12
     BYREF ppidl AS DWORD _                             ' __out PIDLIST_ABSOLUTE *ppidl
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetItem ( _                                   ' VTable offset = 16
     BYREF ppsi AS IShellItem _                         ' __out IShellItem **ppsi
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IUseToBrowseItem_INTERFACE_DEFINED__ */


' ########################################################################################
' IDisplayItem interface
' IID = C6FD5997-9F6B-4888-8703-94E80E8CDE3F
' Inherited interface = IRelatedItem
' ########################################################################################

#IF NOT %DEF(%IDisplayItem_INTERFACE_DEFINED)
    %IDisplayItem_INTERFACE_DEFINED = 1

$IID_IDisplayItem = GUID$("{C6FD5997-9F6B-4888-8703-94E80E8CDE3F}")

INTERFACE IDisplayItem $IID_IDisplayItem

   INHERIT IUnknown

   ' =====================================================================================
   ' IRelatedItem Methods
   ' =====================================================================================
   METHOD GetItemIDList ( _                             ' VTable offset = 12
     BYREF ppidl AS DWORD _                             ' __out PIDLIST_ABSOLUTE *ppidl
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetItem ( _                                   ' VTable offset = 16
     BYREF ppsi AS IShellItem _                         ' __out IShellItem **ppsi
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IDisplayItem Methods
   ' =====================================================================================
   ' No additional methods

END INTERFACE

#ENDIF   ' /* __IDisplayItem_INTERFACE_DEFINED__ */


' ########################################################################################
' IViewStateIdentityItem interface
' IID = 9D264146-A94F-4195-9F9F-3BB12CE0C955
' Inherited interface = IRelatedItem
' ########################################################################################

#IF NOT %DEF(%IViewStateIdentityItem_INTERFACE_DEFINED)
    %IViewStateIdentityItem_INTERFACE_DEFINED = 1

$IID_IViewStateIdentityItem = GUID$("{9D264146-A94F-4195-9F9F-3BB12CE0C955}")

INTERFACE IViewStateIdentityItem $IID_IViewStateIdentityItem

   INHERIT IUnknown

   ' =====================================================================================
   ' IRelatedItem Methods
   ' =====================================================================================
   METHOD GetItemIDList ( _                             ' VTable offset = 12
     BYREF ppidl AS DWORD _                             ' __out PIDLIST_ABSOLUTE *ppidl
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetItem ( _                                   ' VTable offset = 16
     BYREF ppsi AS IShellItem _                         ' __out IShellItem **ppsi
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IViewStateIdentityItem Methods
   ' =====================================================================================
   ' No additional methods

END INTERFACE

#ENDIF   ' /* __IViewStateIdentityItem_INTERFACE_DEFINED__ */


' ########################################################################################
' IPreviewItem interface
' IID = 9D264146-A94F-4195-9F9F-3BB12CE0C955
' Inherited interface = IRelatedItem
' ########################################################################################

#IF NOT %DEF(%IPreviewItem_INTERFACE_DEFINED)
    %IPreviewItem_INTERFACE_DEFINED = 1

$IID_IPreviewItem = GUID$("{9D264146-A94F-4195-9F9F-3BB12CE0C955}")

INTERFACE IPreviewItem $IID_IPreviewItem

   INHERIT IUnknown

   ' =====================================================================================
   ' IRelatedItem Methods
   ' =====================================================================================
   METHOD GetItemIDList ( _                             ' VTable offset = 12
     BYREF ppidl AS DWORD _                             ' __out PIDLIST_ABSOLUTE *ppidl
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetItem ( _                                   ' VTable offset = 16
     BYREF ppsi AS IShellItem _                         ' __out IShellItem **ppsi
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IPreviewItem Methods
   ' =====================================================================================
   ' No additional methods

END INTERFACE

#ENDIF   ' /* __IPreviewItem_INTERFACE_DEFINED__ */

'#endif  // NTDDI_VISTA


' ########################################################################################
' IDestinationStreamFactory interface
' IID = 8A87781B-39A7-4A1F-AAB3-A39B9C34A7D9
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDestinationStreamFactory_INTERFACE_DEFINED)
    %IDestinationStreamFactory_INTERFACE_DEFINED = 1

$IID_IDestinationStreamFactory = GUID$("{8A87781B-39A7-4A1F-AAB3-A39B9C34A7D9}")

INTERFACE IDestinationStreamFactory $IID_IDestinationStreamFactory

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetDestinationStream ( _                      ' VTable offset = 12
     BYREF ppstm AS IStream _                           ' __out IStream **ppstm
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDestinationStreamFactory_INTERFACE_DEFINED__ */

' enum NMCII_FLAGS
%NMCII_ITEMS   = &H1&
%NMCII_FOLDERS = &H2&
'typedef int NMCII_FLAGS;

' enum _NMCSAEI_FLAGS
%NMCSAEI_SELECT = 0&
%NMCSAEI_EDIT   = &H1&
'typedef int NMCSAEI_FLAGS;

' ########################################################################################
' INewMenuClient interface
' IID = DCB07FDC-3BB5-451C-90BE-966644FED7B0
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%INewMenuClient_INTERFACE_DEFINED)
    %INewMenuClient_INTERFACE_DEFINED = 1

$IID_INewMenuClient = GUID$("{DCB07FDC-3BB5-451C-90BE-966644FED7B0}")
$SID_SNewMenuClient = $IID_INewMenuClient

INTERFACE INewMenuClient $IID_INewMenuClient

   INHERIT IUnknown

   ' =====================================================================================
   METHOD IncludeItems ( _                              ' VTable offset = 12
     BYREF pflags AS LONG _                             ' __out NMCII_FLAGS *pflags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SelectAndEditItem ( _                         ' VTable offset = 16
     BYVAL pidlItem AS DWORD _                          ' __in PCIDLIST_ABSOLUTE pidlItem
   , BYVAL flags AS LONG _                              ' __in NMCSAEI_FLAGS flags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __INewMenuClient_INTERFACE_DEFINED__ */

$SID_SCommandBarState = GUID$("{B99EAA5C-3850-4400-BC33-2CE534048BF8}")

'#if (_WIN32_IE >= _WIN32_IE_IE70)

' ########################################################################################
' IInitializeWithBindCtx interface
' IID = 71C0D2BC-726D-45CC-A6C0-2E31C1DB2159
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IInitializeWithBindCtx_INTERFACE_DEFINED)
    %IInitializeWithBindCtx_INTERFACE_DEFINED = 1

$IID_IInitializeWithBindCtx = GUID$("{71C0D2BC-726D-45CC-A6C0-2E31C1DB2159}")

INTERFACE IInitializeWithBindCtx $IID_IInitializeWithBindCtx

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Initialize ( _                                ' VTable offset = 12
     BYVAL pbc AS IBindCtx _                            ' __in_opt IBindCtx *pbc
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IInitializeWithBindCtx_INTERFACE_DEFINED__ */


' ########################################################################################
' IShellItemFilter interface
' IID = 2659B475-EEB8-48B7-8F07-B378810F48CF
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IShellItemFilter_INTERFACE_DEFINED)
    %IShellItemFilter_INTERFACE_DEFINED = 1

$IID_IShellItemFilter = GUID$("{2659B475-EEB8-48B7-8F07-B378810F48CF}")

INTERFACE IShellItemFilter $IID_IShellItemFilter

   INHERIT IUnknown

   ' =====================================================================================
   METHOD IncludeItem ( _                               ' VTable offset = 12
     BYVAL psi AS IShellItem _                          ' __in IShellItem *psi
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetEnumFlagsForItem ( _                       ' VTable offset = 16
     BYVAL psi AS IShellItem _                          ' __in IShellItem *psi
   , BYREF pgrfFlags AS DWORD _                         ' __out SHCONTF *pgrfFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IShellItemFilter_INTERFACE_DEFINED__ */

'#endif  // (_WIN32_IE >= _WIN32_IE_IE70)

' ########################################################################################
' INameSpaceTreeControl interface
' IID = 028212A3-B627-47E9-8856-C14265554E4F
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%INameSpaceTreeControl_INTERFACE_DEFINED)
    %INameSpaceTreeControl_INTERFACE_DEFINED = 1

$IID_INameSpaceTreeControl = GUID$("{028212A3-B627-47E9-8856-C14265554E4F}")
$SID_SNavigationPane = $IID_INameSpaceTreeControl   ' // nearest service that you can proffer to

'typedef DWORD NSTCSTYLE;

' enum tagNSTCSTYLE
%NSTCS_HASEXPANDOS         = &H1???
%NSTCS_HASLINES            = &H2???
%NSTCS_SINGLECLICKEXPAND   = &H4???
%NSTCS_FULLROWSELECT       = &H8???
%NSTCS_SPRINGEXPAND        = &H10???
%NSTCS_HORIZONTALSCROLL    = &H20???
%NSTCS_ROOTHASEXPANDO      = &H40???
%NSTCS_SHOWSELECTIONALWAYS = &H80???
%NSTCS_NOINFOTIP           = &H200???
%NSTCS_EVENHEIGHT          = &H400???
%NSTCS_NOREPLACEOPEN       = &H800???
%NSTCS_DISABLEDRAGDROP     = &H1000???
%NSTCS_NOORDERSTREAM       = &H2000???
%NSTCS_RICHTOOLTIP         = &H4000???
%NSTCS_BORDER              = &H8000???
%NSTCS_NOEDITLABELS        = &H10000???
%NSTCS_TABSTOP             = &H20000???
%NSTCS_FAVORITESMODE       = &H80000???
%NSTCS_AUTOHSCROLL         = &H100000???
%NSTCS_FADEINOUTEXPANDOS   = &H200000???
%NSTCS_EMPTYTEXT           = &H400000???
%NSTCS_CHECKBOXES          = &H800000???
%NSTCS_PARTIALCHECKBOXES   = &H1000000???
%NSTCS_EXCLUSIONCHECKBOXES = &H2000000???
%NSTCS_DIMMEDCHECKBOXES    = &H4000000???
%NSTCS_NOINDENTCHECKS      = &H8000000???
%NSTCS_ALLOWJUNCTIONS      = &H10000000???
%NSTCS_SHOWTABSBUTTON      = &H20000000???
%NSTCS_SHOWDELETEBUTTON    = &H40000000???
%NSTCS_SHOWREFRESHBUTTON   = &H80000000&   ' ( int  )0x80000000
'typedef DWORD NSTCROOTSTYLE;

' enum tagNSTCROOTSTYLE
%NSTCRS_VISIBLE  = 0???
%NSTCRS_HIDDEN   = &H1???
%NSTCRS_EXPANDED = &H2???
'typedef DWORD NSTCITEMSTATE;

' enum tagNSTCITEMSTATE
%NSTCIS_NONE             = 0???
%NSTCIS_SELECTED         = &H1???
%NSTCIS_EXPANDED         = &H2???
%NSTCIS_BOLD             = &H4???
%NSTCIS_DISABLED         = &H8???
%NSTCIS_SELECTEDNOEXPAND = &H10???
'typedef DWORD NSTCITEMSTATE;

' enum tagNSTCGNI
%NSTCGNI_NEXT         = 0
%NSTCGNI_NEXTVISIBLE  = 1
%NSTCGNI_PREV         = 2
%NSTCGNI_PREVVISIBLE  = 3
%NSTCGNI_PARENT       = 4
%NSTCGNI_CHILD        = 5
%NSTCGNI_FIRSTVISIBLE = 6
%NSTCGNI_LASTVISIBLE  = 7

INTERFACE INameSpaceTreeControl $IID_INameSpaceTreeControl

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Initialize ( _                                ' VTable offset = 12
     BYVAL hwndParent AS DWORD _                        ' __in HWND hwndParent
   , BYREF prc AS RECT _                                ' __in RECT *prc
   , BYVAL nsctsFlags AS DWORD _                        ' __in NSTCSTYLE nsctsFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD TreeAdvise ( _                                ' VTable offset = 16
     BYVAL punk AS IUnknown _                           ' __in IUnknown *punk
   , BYREF pdwCookie AS DWORD _                         ' __out DWORD *pdwCookie
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD TreeUnadvise ( _                              ' VTable offset = 20
     BYVAL dwCookie AS DWORD _                          ' __in DWORD dwCookie
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AppendRoot ( _                                ' VTable offset = 24
     BYVAL psiRoot AS IShellItem _                      ' __in IShellItem *psiRoot
   , BYVAL grfEnumFlags AS DWORD _                      ' __in SHCONTF grfEnumFlags
   , BYVAL grfRootStyle AS DWORD _                      ' __in NSTCROOTSTYLE grfRootStyle
   , BYVAL pif AS IShellItemFilter _                    ' __in IShellItemFilter *pif
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD InsertRoot ( _                                ' VTable offset = 28
     BYVAL iIndex AS LONG _                             ' __in int iIndex
   , BYVAL psiRoot AS IShellItem _                      ' __in IShellItem *psiRoot
   , BYVAL grfEnumFlags AS DWORD _                      ' __in SHCONTF grfEnumFlags
   , BYVAL grfRootStyle AS DWORD _                      ' __in NSTCROOTSTYLE grfRootStyle
   , BYVAL pif AS IShellItemFilter _                    ' __in IShellItemFilter *pif
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RemoveRoot ( _                                ' VTable offset = 32
     BYVAL psiRoot AS IShellItem _                      ' __in IShellItem *psiRoot
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RemoveAllRoots ( _                            ' VTable offset = 36
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRootItems ( _                              ' VTable offset = 40
     BYREF ppsiaRootItems AS IShellItemArray _          ' __out IShellItemArray **ppsiaRootItems
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetItemState ( _                              ' VTable offset = 44
     BYVAL psi AS IShellItem _                          ' __in IShellItem *psi
   , BYVAL nstcisMask AS DWORD _                        ' __in NSTCITEMSTATE nstcisMask
   , BYVAL nstcisFlags AS DWORD _                       ' __in NSTCITEMSTATE nstcisFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetItemState ( _                              ' VTable offset = 48
     BYVAL psi AS IShellItem _                          ' __in IShellItem *psi
   , BYVAL nstcisMask AS DWORD _                        ' __in NSTCITEMSTATE nstcisMask
   , BYREF nstcisFlags AS DWORD _                       ' __out NSTCITEMSTATE *pnstcisFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSelectedItems ( _                          ' VTable offset = 52
     BYREF psiaItems AS IShellItemArray _               ' __out IShellItemArray **psiaItems
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetItemCustomState ( _                        ' VTable offset = 56
     BYVAL psi AS IShellItem _                          ' __in IShellItem *psi
   , BYREF piStateNumber AS LONG _                      ' __out int *piStateNumber
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetItemCustomState ( _                        ' VTable offset = 60
     BYVAL psi AS IShellItem _                          ' __in IShellItem *psi
   , BYVAL iStateNumber AS LONG _                       ' __in int iStateNumber
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnsureItemVisible ( _                         ' VTable offset = 64
     BYVAL psi AS IShellItem _                          ' __in IShellItem *psi
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetTheme ( _                                  ' VTable offset = 68
     BYREF pszTheme AS WSTRINGZ _                       ' __in LPCWSTR pszTheme
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetNextItem ( _                               ' VTable offset = 72
     BYVAL psi AS IShellItem _                          ' __in IShellItem *psi
   , BYVAL nstcgi AS DWORD _                            ' __in NSTCGNI nstcgi
   , BYREF ppsiNext AS IShellItem _                     ' __out IShellItem **ppsiNext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD HitTest ( _                                   ' VTable offset = 76
     BYREF ppt AS POINT _                               ' __in POINT *ppt
   , BYREF ppsiOut AS IShellItem _                      ' __out IShellItem **ppsiOut
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetItemRect ( _                               ' VTable offset = 80
     BYVAL psi AS IShellItem _                          ' __in IShellItem *psi
   , BYREF prect AS RECT _                              ' __out RECT *prect
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CollapseAll ( _                               ' VTable offset = 84
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __INameSpaceTreeControl_INTERFACE_DEFINED__ */

' ########################################################################################
' INameSpaceTreeControl2 interface
' IID = 7CC7AED8-290E-49BC-8945-C1401CC9306C
' Inherited interface = INameSpaceTreeControl
' ########################################################################################

#IF NOT %DEF(%INameSpaceTreeControl2_INTERFACE_DEFINED)
    %INameSpaceTreeControl2_INTERFACE_DEFINED = 1

$IID_INameSpaceTreeControl2 = GUID$("{7CC7AED8-290E-49BC-8945-C1401CC9306C}")
$SID_SNavigationPane = $IID_INameSpaceTreeControl   ' // nearest service that you can proffer to

' enum NSTCSTYLE2
%NSTCS2_DEFAULT                  = 0???
%NSTCS2_INTERRUPTNOTIFICATIONS   = &H1???
%NSTCS2_SHOWNULLSPACEMENU        = &H2???
%NSTCS2_DISPLAYPADDING           = &H4???
%NSTCS2_DISPLAYPINNEDONLY        = &H8???
%NTSCS2_NOSINGLETONAUTOEXPAND    = &H10???
%NTSCS2_NEVERINSERTNONENUMERATED = &H20???

INTERFACE INameSpaceTreeControl2 $IID_INameSpaceTreeControl2

   INHERIT IUnknown

   ' =====================================================================================
   ' INameSpaceTreeControl methods
   ' =====================================================================================
   METHOD Initialize ( _                                ' VTable offset = 12
     BYVAL hwndParent AS DWORD _                        ' __in HWND hwndParent
   , BYREF prc AS RECT _                                ' __in RECT *prc
   , BYVAL nsctsFlags AS DWORD _                        ' __in NSTCSTYLE nsctsFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD TreeAdvise ( _                                ' VTable offset = 16
     BYVAL punk AS IUnknown _                           ' __in IUnknown *punk
   , BYREF pdwCookie AS DWORD _                         ' __out DWORD *pdwCookie
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD TreeUnadvise ( _                              ' VTable offset = 20
     BYVAL dwCookie AS DWORD _                          ' __in DWORD dwCookie
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AppendRoot ( _                                ' VTable offset = 24
     BYVAL psiRoot AS IShellItem _                      ' __in IShellItem *psiRoot
   , BYVAL grfEnumFlags AS DWORD _                      ' __in SHCONTF grfEnumFlags
   , BYVAL grfRootStyle AS DWORD _                      ' __in NSTCROOTSTYLE grfRootStyle
   , BYVAL pif AS IShellItemFilter _                    ' __in IShellItemFilter *pif
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD InsertRoot ( _                                ' VTable offset = 28
     BYVAL iIndex AS LONG _                             ' __in int iIndex
   , BYVAL psiRoot AS IShellItem _                      ' __in IShellItem *psiRoot
   , BYVAL grfEnumFlags AS DWORD _                      ' __in SHCONTF grfEnumFlags
   , BYVAL grfRootStyle AS DWORD _                      ' __in NSTCROOTSTYLE grfRootStyle
   , BYVAL pif AS IShellItemFilter _                    ' __in IShellItemFilter *pif
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RemoveRoot ( _                                ' VTable offset = 32
     BYVAL psiRoot AS IShellItem _                      ' __in IShellItem *psiRoot
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RemoveAllRoots ( _                            ' VTable offset = 36
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRootItems ( _                              ' VTable offset = 40
     BYREF ppsiaRootItems AS IShellItemArray _          ' __out IShellItemArray **ppsiaRootItems
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetItemState ( _                              ' VTable offset = 44
     BYVAL psi AS IShellItem _                          ' __in IShellItem *psi
   , BYVAL nstcisMask AS DWORD _                        ' __in NSTCITEMSTATE nstcisMask
   , BYVAL nstcisFlags AS DWORD _                       ' __in NSTCITEMSTATE nstcisFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetItemState ( _                              ' VTable offset = 48
     BYVAL psi AS IShellItem _                          ' __in IShellItem *psi
   , BYVAL nstcisMask AS DWORD _                        ' __in NSTCITEMSTATE nstcisMask
   , BYREF nstcisFlags AS DWORD _                       ' __out NSTCITEMSTATE *pnstcisFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetSelectedItems ( _                          ' VTable offset = 52
     BYREF psiaItems AS IShellItemArray _               ' __out IShellItemArray **psiaItems
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetItemCustomState ( _                        ' VTable offset = 56
     BYVAL psi AS IShellItem _                          ' __in IShellItem *psi
   , BYREF piStateNumber AS LONG _                      ' __out int *piStateNumber
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetItemCustomState ( _                        ' VTable offset = 60
     BYVAL psi AS IShellItem _                          ' __in IShellItem *psi
   , BYVAL iStateNumber AS LONG _                       ' __in int iStateNumber
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnsureItemVisible ( _                         ' VTable offset = 64
     BYVAL psi AS IShellItem _                          ' __in IShellItem *psi
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetTheme ( _                                  ' VTable offset = 68
     BYREF pszTheme AS WSTRINGZ _                       ' __in LPCWSTR pszTheme
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetNextItem ( _                               ' VTable offset = 72
     BYVAL psi AS IShellItem _                          ' __in IShellItem *psi
   , BYVAL nstcgi AS DWORD _                            ' __in NSTCGNI nstcgi
   , BYREF ppsiNext AS IShellItem _                     ' __out IShellItem **ppsiNext
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD HitTest ( _                                   ' VTable offset = 76
     BYREF ppt AS POINT _                               ' __in POINT *ppt
   , BYREF ppsiOut AS IShellItem _                      ' __out IShellItem **ppsiOut
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetItemRect ( _                               ' VTable offset = 80
     BYVAL psi AS IShellItem _                          ' __in IShellItem *psi
   , BYREF prect AS RECT _                              ' __out RECT *prect
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CollapseAll ( _                               ' VTable offset = 84
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' INameSpaceTreeControl2 methods
   ' =====================================================================================
   METHOD SetControlStyle ( _                           ' VTable offset = 88
     BYVAL nstcsMask AS DWORD _                         ' __in NSTCSTYLE nstcsMask
   , BYVAL nstcsStyle AS DWORD _                        ' __in NSTCSTYLE nstcsStyle
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetControlStyle ( _                           ' VTable offset = 92
     BYVAL nstcsMask AS DWORD _                         ' __in NSTCSTYLE nstcsMask
   , BYREF pnstcsStyle AS DWORD _                       ' __out NSTCSTYLE *pnstcsStyle
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetControlStyle2 ( _                          ' VTable offset = 96
     BYVAL nstcsMask AS DWORD _                         ' __in NSTCSTYLE2 nstcsMask
   , BYVAL nstcsStyle AS DWORD _                        ' __in NSTCSTYLE2 nstcsStyle
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetControlStyle2 ( _                          ' VTable offset = 100
     BYVAL nstcsMask AS DWORD _                         ' __in NSTCSTYLE2 nstcsMask
   , BYREF pnstcsStyle AS DWORD _                       ' __out NSTCSTYLE2 *pnstcsStyle
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __INameSpaceTreeControl2_INTERFACE_DEFINED__ */

%NSTCS2_ALLMASK = %NSTCS2_INTERRUPTNOTIFICATIONS OR %NSTCS2_SHOWNULLSPACEMENU OR %NSTCS2_DISPLAYPADDING

'#define ISLBUTTON(x) (NSTCECT_LBUTTON == ((x) & NSTCECT_BUTTON))
'#define ISMBUTTON(x) (NSTCECT_MBUTTON == ((x) & NSTCECT_BUTTON))
'#define ISRBUTTON(x) (NSTCECT_RBUTTON == ((x) & NSTCECT_BUTTON))
'#define ISDBLCLICK(x) (NSTCECT_DBLCLICK == ((x) & NSTCECT_DBLCLICK))

MACRO ISLBUTTON(x)  = NSTCECT_LBUTTON  = (x AND %NSTCECT_BUTTON)
MACRO ISMBUTTON(x)  = NSTCECT_MBUTTON  = (x AND %NSTCECT_BUTTON)
MACRO ISRBUTTON(x)  = NSTCECT_RBUTTON  = (x AND %NSTCECT_BUTTON)
MACRO ISDBLCLICK(x) = NSTCECT_DBLCLICK = (x AND %NSTCECT_DBLCLICK)


' ########################################################################################
' INameSpaceTreeControlEvents interface
' IID = 93D77985-B3D8-4484-8318-672CDDA002CE
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%INameSpaceTreeControlEvents_INTERFACE_DEFINED)
    %INameSpaceTreeControlEvents_INTERFACE_DEFINED = 1

$IID_INameSpaceTreeControlEvents = GUID$("{93D77985-B3D8-4484-8318-672CDDA002CE}")

'typedef DWORD NSTCEHITTEST;

' enum tagNSTCEHITTEST
%NSTCEHT_NOWHERE         = &H1???
%NSTCEHT_ONITEMICON      = &H2???
%NSTCEHT_ONITEMLABEL     = &H4???
%NSTCEHT_ONITEMINDENT    = &H8???
%NSTCEHT_ONITEMBUTTON    = &H10???
%NSTCEHT_ONITEMRIGHT     = &H20???
%NSTCEHT_ONITEMSTATEICON = &H40???
%NSTCEHT_ONITEM          = &H46???
%NSTCEHT_ONITEMTABBUTTON = &H1000???
'typedef DWORD NSTCECLICKTYPE;

' enum tagNSTCECLICKTYPE
%NSTCECT_LBUTTON         = &H1???
%NSTCECT_MBUTTON         = &H2???
%NSTCECT_RBUTTON         = &H3???
%NSTCECT_BUTTON          = &H3???
%NSTCECT_DBLCLICK        = &H4???

INTERFACE INameSpaceTreeControlEvents $IID_INameSpaceTreeControlEvents

   INHERIT IUnknown

   ' =====================================================================================
   METHOD OnItemClick ( _                               ' VTable offset = 12
     BYVAL psi AS IShellItem _                          ' __inIShellItem *psi
   , BYVAL nstceHitTest AS DWORD _                      ' __in NSTCEHITTEST nstceHitTest
   , BYVAL nstceClickType AS DWORD _                    ' __in NSTCECLICKTYPE nstceClickType
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnPropertyItemCommit ( _                      ' VTable offset = 16
     BYVAL psi AS IShellItem _                          ' __in IShellItem *psi
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnItemStateChanging ( _                       ' VTable offset = 20
     BYVAL psi AS IShellItem _                          ' __in IShellItem *psi
   , BYVAL nstcisMask AS DWORD _                        ' __in NSTCITEMSTATE nstcisMask
   , BYVAL nstcisState AS DWORD _                       ' __in NSTCITEMSTATE nstcisState
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnItemStateChanged ( _                        ' VTable offset = 24
     BYVAL psi AS IShellItem _                          ' __in IShellItem *psi
   , BYVAL nstcisMask AS DWORD _                        ' __in NSTCITEMSTATE nstcisMask
   , BYVAL nstcisState AS DWORD _                       ' __in NSTCITEMSTATE nstcisState
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnSelectionChanged ( _                        ' VTable offset = 28
     BYVAL psiaSelection AS IShellItemArray _           ' __in IShellItemArray *psiaSelection
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnKeyboardInput ( _                           ' VTable offset = 32
     BYVAL uMsg AS DWORD _                              ' __in UINT uMsg
   , BYVAL wParam AS DWORD _                            ' __in WPARAM wParam
   , BYVAL lParam AS LONG _                             ' __in LPARAM lParam
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnBeforeExpand ( _                            ' VTable offset = 36
     BYVAL psi AS IShellItem _                          ' __in IShellItem *psi
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnAfterExpand ( _                             ' VTable offset = 40
     BYVAL psi AS IShellItem _                          ' __in IShellItem *psi
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnBeginLabelEdit ( _                          ' VTable offset = 44
     BYVAL psi AS IShellItem _                          ' __in IShellItem *psi
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnEndLabelEdit ( _                            ' VTable offset = 48
     BYVAL psi AS IShellItem _                          ' __in IShellItem *psi
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnGetToolTip ( _                              ' VTable offset = 52
     BYVAL psi AS IShellItem _                          ' __in IShellItem *psi
   , BYREF pszTip AS WSTRINGZ _                         ' __out LPWSTR pszTip
   , BYVAL cchTip AS LONG _                             ' __in int cchTip
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnBeforeItemDelete ( _                        ' VTable offset = 56
     BYVAL psi AS IShellItem _                          ' __in IShellItem *psi
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnItemAdded ( _                               ' VTable offset = 60
     BYVAL psi AS IShellItem _                          ' __in IShellItem *psi
   , BYVAL fIsRoot AS LONG _                            ' __in BOOL fIsRoot
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnItemDeleted ( _                             ' VTable offset = 64
     BYVAL psi AS IShellItem _                          ' __in IShellItem *psi
   , BYVAL fIsRoot AS LONG _                            ' __in BOOL fIsRoot
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnBeforeContextMenu ( _                       ' VTable offset = 68
     BYVAL psi AS IShellItem _                          ' __in IShellItem *psi
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppv AS IUnknown _                            ' __out void **ppv
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnAfterContextMenu ( _                        ' VTable offset = 72
     BYVAL psi AS IShellItem _                          ' __in IShellItem *psi
   , BYVAL pcmIn AS IContextMenu _                      ' __in IContextMenu *pcmIn
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppv AS IUnknown _                            ' __out void **ppv
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnBeforeStateImageChange ( _                  ' VTable offset = 76
     BYVAL psi AS IShellItem _                          ' __in IShellItem *psi
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnGetDefaultIconIndex ( _                     ' VTable offset = 80
     BYVAL psi AS IShellItem _                          ' __in IShellItem *psi
   , BYREF piDefaultIcon AS LONG _                      ' __out int *piDefaultIcon
   , BYREF piOpenIcon AS LONG _                         ' __out int *piOpenIcon
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   '  /* __INameSpaceTreeControlEvents_INTERFACE_DEFINED__ */

%NSTCDHPOS_ONTOP = -1

' ########################################################################################
' INameSpaceTreeControlDropHandler interface
' IID = F9C665D6-C2F2-4C19-BF33-8322D7352F51
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%INameSpaceTreeControlDropHandler_INTERFACE_DEFINED)
    %INameSpaceTreeControlDropHandler_INTERFACE_DEFINED = 1

$IID_INameSpaceTreeControlDropHandler = GUID$("{F9C665D6-C2F2-4C19-BF33-8322D7352F51}")

INTERFACE INameSpaceTreeControlDropHandler $IID_INameSpaceTreeControlDropHandler

   INHERIT IUnknown

   ' =====================================================================================
   METHOD OnDragEnter ( _                               ' VTable offset = 12
     BYVAL psiOver AS IShellItem _                      ' __in IShellItem *psiOver
   , BYVAL psiaData AS IShellItemArray _                ' __in IShellItemArray *psiaData
   , BYVAL fOutsideSource AS LONG _                     ' __in BOOL fOutsideSource
   , BYVAL grfKeyState AS DWORD _                       ' __in DWORD grfKeyState
   , BYREF pdwEffect AS DWORD _                         ' __inout DWORD *pdwEffect
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnDragOver ( _                                ' VTable offset = 16
     BYVAL psiOver AS IShellItem _                      ' __in IShellItem *psiOver
   , BYVAL psiaData AS IShellItemArray _                ' __in IShellItemArray *psiaData
   , BYVAL grfKeyState AS DWORD _                       ' __in DWORD grfKeyState
   , BYREF pdwEffect AS DWORD _                         ' __inout DWORD *pdwEffect
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnDragPosition ( _                            ' VTable offset = 20
     BYVAL psiOver AS IShellItem _                      ' __in IShellItem *psiOver
   , BYVAL psiaData AS IShellItemArray _                ' __in IShellItemArray *psiaData
   , BYVAL iNewPosition AS LONG _                       ' __in int iNewPosition
   , BYVAL iOldPosition AS LONG _                       ' __in int iOldPosition
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnDrop ( _                                    ' VTable offset = 24
     BYVAL psiOver AS IShellItem _                      ' __in IShellItem *psiOver
   , BYVAL psiaData AS IShellItemArray _                ' __in IShellItemArray *psiaData
   , BYVAL iPosition AS LONG _                          ' __in int iPosition
   , BYVAL grfKeyState AS DWORD _                       ' __in DWORD grfKeyState
   , BYREF pdwEffect AS DWORD _                         ' __inout DWORD *pdwEffect
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnDropPosition ( _                            ' VTable offset = 28
     BYVAL psiOver AS IShellItem _                      ' __in IShellItem *psiOver
   , BYVAL psiaData AS IShellItemArray _                ' __in IShellItemArray *psiaData
   , BYVAL iNewPosition AS LONG _                       ' __in int iNewPosition
   , BYVAL iOldPosition AS LONG _                       ' __in int iOldPosition
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnDragLeave ( _                               ' VTable offset = 32
     BYVAL psiOver AS IShellItem _                      ' __in IShellItem *psiOver
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __INameSpaceTreeControlDropHandler_INTERFACE_DEFINED__ */


' ########################################################################################
' INameSpaceTreeAccessible interface
' IID = 71F312DE-43ED-4190-8477-E9536B82350B
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%INameSpaceTreeAccessible_INTERFACE_DEFINED)
    %INameSpaceTreeAccessible_INTERFACE_DEFINED = 1

$IID_INameSpaceTreeAccessible = GUID$("{71F312DE-43ED-4190-8477-E9536B82350B}")

INTERFACE INameSpaceTreeAccessible $IID_INameSpaceTreeAccessible

   INHERIT IUnknown

   ' =====================================================================================
   METHOD OnGetDefaultAccessibilityAction ( _           ' VTable offset = 12
     BYVAL psi AS IShellItem _                          ' __in IShellItem *psi
   , BYREF pbstrDefaultAction AS WSTRING _              ' __out BSTR *pbstrDefaultAction
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnDoDefaultAccessibilityAction ( _            ' VTable offset = 16
     BYVAL psi AS IShellItem _                          ' __in IShellItem *psi
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnGetAccessibilityRole ( _                    ' VTable offset = 20
     BYVAL psi AS IShellItem _                          ' __in IShellItem *psi
   , BYREF pvarRole AS VARIANT _                        ' __out VARIANT *pvarRole
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __INameSpaceTreeAccessible_INTERFACE_DEFINED__ */

' ########################################################################################
' INameSpaceTreeControlCustomDraw interface
' IID = 2D3BA758-33EE-42D5-BB7B-5F3431D86C78
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%INameSpaceTreeControlCustomDraw_INTERFACE_DEFINED)
    %INameSpaceTreeControlCustomDraw_INTERFACE_DEFINED = 1

$IID_INameSpaceTreeControlCustomDraw = GUID$("{2D3BA758-33EE-42D5-BB7B-5F3431D86C78}")

' // Size = 32 bytes
TYPE NSTCCUSTOMDRAW DWORD
   psi        AS DWORD PTR      ' IShellItem *
   uItemState AS DWORD          ' UINT
   nstcis     AS DWORD          ' NSTCITEMSTATE
   pszText    AS WSTRINGZ PTR   ' LPCWSTR
   iImage     AS LONG           ' int
   himl       AS DWORD          ' HIMAGELIST
   iLevel     AS LONG           ' int
   iIndent    AS LONG           ' int
END TYPE

INTERFACE INameSpaceTreeControlCustomDraw $IID_INameSpaceTreeControlCustomDraw

   INHERIT IUnknown

   ' =====================================================================================
   METHOD PrePaint ( _                                  ' VTable offset = 12
     BYVAL hdc AS DWORD _                               ' __in HDC hdc
   , BYREF prc AS RECT _                                ' __in RECT *prc
   , BYREF plres AS LONG _                              ' __out LRESULT *plres
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD PostPaint ( _                                 ' VTable offset = 16
     BYVAL hdc AS DWORD _                               ' __in HDC hdc
   , BYREF prc AS RECT _                                ' __in RECT *prc
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ItemPrePaint ( _                              ' VTable offset = 20
     BYVAL hdc AS DWORD _                               ' __in HDC hdc
   , BYREF prc AS RECT _                                ' __in RECT *prc
   , BYREF pnstccdItem AS NSTCCUSTOMDRAW _              ' __in NSTCCUSTOMDRAW *pnstccdItem
   , BYREF pnstccdItem AS DWORD _                       ' __inout COLORREF *pclrText
   , BYREF pclrTextBk AS DWORD _                        ' __inout COLORREF *pclrTextBk
   , BYREF plres AS LONG _                              ' __out LRESULT *plres
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ItemPostPaint ( _                             ' VTable offset = 24
     BYVAL hdc AS DWORD _                               ' __in HDC hdc
   , BYREF prc AS RECT _                                ' __in RECT *prc
   , BYREF pnstccdItem AS NSTCCUSTOMDRAW _              ' __in NSTCCUSTOMDRAW *pnstccdItem
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __INameSpaceTreeControlCustomDraw_INTERFACE_DEFINED__ */


'#if (NTDDI_VERSION >= NTDDI_VISTA)

' ########################################################################################
' INameSpaceTreeControlFolderCapabilities interface
' IID = 8895B1C6-B41F-4C1C-A562-0D564250836F
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%INameSpaceTreeControlFolderCapabilities_INTERFACE_DEFINED)
    %INameSpaceTreeControlFolderCapabilities_INTERFACE_DEFINED = 1

' enum NSTCFOLDERCAPABILITIES
%NSTCFC_NONE                  = 0
%NSTCFC_PINNEDITEMFILTERING   = &H1
%NSTCFC_DELAY_REGISTER_NOTIFY = &H2

$IID_INameSpaceTreeControlFolderCapabilities = GUID$("{8895B1C6-B41F-4C1C-A562-0D564250836F}")

INTERFACE INameSpaceTreeControlFolderCapabilities $IID_INameSpaceTreeControlFolderCapabilities

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetFolderCapabilities ( _                     ' VTable offset = 12
     BYVAL nfcMask AS LONG _                            ' __in NSTCFOLDERCAPABILITIES nfcMask
   , BYREF pnfcValue AS LONG _                          ' __out NSTCFOLDERCAPABILITIES *pnfcValue
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __INameSpaceTreeControlFolderCapabilities_INTERFACE_DEFINED__ */

'#endif  // NTDDI_VISTA

%E_PREVIEWHANDLER_DRM_FAIL = &H86420001&
%E_PREVIEWHANDLER_NOAUTH   = &H86420002&
%E_PREVIEWHANDLER_NOTFOUND = &H86420003&
%E_PREVIEWHANDLER_CORRUPT  = &H86420004&

' ########################################################################################
' IPreviewHandler interface
' IID = 8895B1C6-B41F-4C1C-A562-0D564250836F
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IPreviewHandler_INTERFACE_DEFINED)
    %IPreviewHandler_INTERFACE_DEFINED = 1

$IID_IPreviewHandler = GUID$("{8895B1C6-B41F-4C1C-A562-0D564250836F}")

INTERFACE IPreviewHandler $IID_IPreviewHandler

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetWindow ( _                                 ' VTable offset = 12
     BYVAL hwnd AS DWORD _                              ' __in HWND hwnd
   , BYREF prc AS RECT _                                ' __in const RECT *prc
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetRect ( _                                   ' VTable offset = 16
     BYREF prc AS RECT _                                ' __in const RECT *prc
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DoPreview ( _                                 ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Unload ( _                                    ' VTable offset = 24
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetFocus ( _                                  ' VTable offset = 28
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD QueryFocus ( _                                ' VTable offset = 32
     BYREF phwnd AS DWORD _                             ' __out HWND *phwnd
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD TranslateAccelerator ( _                      ' VTable offset = 36
     BYVAL pmsg AS DWORD _                              ' __in MSG *pmsg
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IPreviewHandler_INTERFACE_DEFINED__ */


' ########################################################################################
' IPreviewHandlerFrame interface
' IID = FEC87AAF-35F9-447A-ADB7-20234491401A
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IPreviewHandlerFrame_INTERFACE_DEFINED)
    %IPreviewHandlerFrame_INTERFACE_DEFINED = 1

$IID_IPreviewHandlerFrame = GUID$("{FEC87AAF-35F9-447A-ADB7-20234491401A}")

' // Size = 8 bytes
TYPE PREVIEWHANDLERFRAMEINFO DWORD
   haccel        AS DWORD   ' HACCEL
   cAccelEntries AS DWORD   ' UINT
END TYPE

INTERFACE IPreviewHandlerFrame $IID_IPreviewHandlerFrame

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetWindowContext ( _                          ' VTable offset = 12
     BYREF pinfo AS PREVIEWHANDLERFRAMEINFO _           ' __out PREVIEWHANDLERFRAMEINFO *pinfo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD TranslateAccelerator ( _                      ' VTable offset = 16
     BYVAL pmsg AS DWORD _                              ' __in MSG *pmsg
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IPreviewHandlerFrame_INTERFACE_DEFINED__ */

'#if (NTDDI_VERSION >= NTDDI_VISTA)

' ########################################################################################
' ITrayDeskBand interface
' IID = 6D67E846-5B9C-4DB8-9CBC-DDE12F4254F1
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ITrayDeskBand_INTERFACE_DEFINED)
    %ITrayDeskBand_INTERFACE_DEFINED = 1

$IID_ITrayDeskBand = GUID$("{6D67E846-5B9C-4DB8-9CBC-DDE12F4254F1}")

INTERFACE ITrayDeskBand $IID_ITrayDeskBand

   INHERIT IUnknown

   ' =====================================================================================
   METHOD ShowDeskBand ( _                              ' VTable offset = 12
     BYREF clsid AS GUID _                              ' __in REFCLSID clsid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD HideDeskBand ( _                              ' VTable offset = 16
     BYREF clsid AS GUID _                              ' __in REFCLSID clsid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsDeskBandShown ( _                           ' VTable offset = 20
     BYREF clsid AS GUID _                              ' __in REFCLSID clsid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DeskBandRegistrationChanged ( _               ' VTable offset = 24
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ITrayDeskBand_INTERFACE_DEFINED__ */


' ########################################################################################
' IBandHost interface
' IID = B9075C7C-D48E-403F-AB99-D6C77A1084AC
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IBandHost_INTERFACE_DEFINED)
    %IBandHost_INTERFACE_DEFINED = 1

$IID_IBandHost = GUID$("{B9075C7C-D48E-403F-AB99-D6C77A1084AC}")
$SID_IBandHost = $IID_IBandHost

INTERFACE IBandHost $IID_IBandHost

   INHERIT IUnknown

   ' =====================================================================================
   METHOD CreateBand ( _                                ' VTable offset = 12
     BYREF rclsidBand AS GUID _                         ' __in REFCLSID rclsidBand
   , BYVAL fAvailable AS LONG _                         ' __in BOOL fAvailable
   , BYVAL fVisible AS LONG _                           ' __in BOOL fVisible
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppv AS IUnknown _                            ' __out void **ppv
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetBandAvailability ( _                       ' VTable offset = 16
     BYREF rclsidBand AS GUID _                         ' __in REFCLSID rclsidBand
   , BYVAL fAvailable AS LONG _                         ' __in BOOL fAvailable
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DestroyBand ( _                               ' VTable offset = 20
     BYREF rclsidBand AS GUID _                         ' __in REFCLSID rclsidBand
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IBandHost_INTERFACE_DEFINED__ */

'typedef GUID EXPLORERPANE;

'#if 0
'typedef EXPLORERPANE *REFEXPLORERPANE;
'#endif // 0
'#ifdef __cplusplus
'#define REFEXPLORERPANE const EXPLORERPANE &
'#else // !__cplusplus
'#define REFEXPLORERPANE const EXPLORERPANE * __MIDL_CONST
'#endif // __cplusplus


' ########################################################################################
' IExplorerPaneVisibility interface
' IID = E07010EC-BC17-44C0-97B0-46C7C95B9EDC
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IExplorerPaneVisibility_INTERFACE_DEFINED)
    %IExplorerPaneVisibility_INTERFACE_DEFINED = 1

$IID_IExplorerPaneVisibility = GUID$("{E07010EC-BC17-44C0-97B0-46C7C95B9EDC}")
$SID_ExplorerPaneVisibility = $IID_IExplorerPaneVisibility

' enum EXPLORERPANESTATE
%EPS_DONTCARE     = 0???
%EPS_DEFAULT_ON   = &H1???
%EPS_DEFAULT_OFF  = &H2???
%EPS_STATEMASK    = &Hffff???
%EPS_INITIALSTATE = &H10000???
%EPS_FORCE        = &H20000???
'typedef DWORD EXPLORERPANESTATE;

INTERFACE IExplorerPaneVisibility $IID_IExplorerPaneVisibility

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetPaneState ( _                              ' VTable offset = 12
     BYVAL ep AS DWORD _                                ' __in REFEXPLORERPANE ep
   , BYREF peps AS DWORD _                              ' __out EXPLORERPANESTATE *peps
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IExplorerPaneVisibility_INTERFACE_DEFINED__ */


' ########################################################################################
' IContextMenuCB interface
' IID = 3409E930-5A39-11D1-83FA-00A0C90DC849
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IContextMenuCB_INTERFACE_DEFINED)
    %IContextMenuCB_INTERFACE_DEFINED = 1

$IID_IContextMenuCB = GUID$("{3409E930-5A39-11D1-83FA-00A0C90DC849}")

INTERFACE IContextMenuCB $IID_IContextMenuCB

   INHERIT IUnknown

   ' =====================================================================================
   METHOD CallBack ( _                                  ' VTable offset = 12
     BYVAL psf AS IShellFolder _                        ' __in IShellFolder *psf
   , BYVAL hwndOwner AS DWORD _                         ' __in HWND hwndOwner
   , BYVAL pdtobj AS IDataObject _                      ' __in IDataObject *pdtobj
   , BYVAL uMsg AS DWORD _                              ' __in UINT uMsg
   , BYVAL wParam AS DWORD _                            ' __in WPARAM wParam
   , BYVAL lParam AS LONG _                             ' __in LPARAM lParam
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IContextMenuCB_INTERFACE_DEFINED__ */

'#endif  // NTDDI_VISTA


' ########################################################################################
' IDefaultExtractIconInit interface
' IID = 41DED17D-D6B3-4261-997D-88C60E4B1D58
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDefaultExtractIconInit_INTERFACE_DEFINED)
    %IDefaultExtractIconInit_INTERFACE_DEFINED = 1

$IID_IDefaultExtractIconInit = GUID$("{41DED17D-D6B3-4261-997D-88C60E4B1D58}")

INTERFACE IDefaultExtractIconInit $IID_IDefaultExtractIconInit

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetFlags ( _                                  ' VTable offset = 12
     BYVAL uFlags AS DWORD _                            ' __in UINT uFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetKey ( _                                    ' VTable offset = 16
     BYVAL hkey AS DWORD _                              ' __in HKEY hkey
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetNormalIcon ( _                             ' VTable offset = 20
     BYREF pszFile AS WSTRINGZ _                        ' __in LPCWSTR pszFile
   , BYVAL iIcon AS LONG _                              ' __in int iIcon
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetOpenIcon ( _                               ' VTable offset = 24
     BYREF pszFile AS WSTRINGZ _                        ' __in LPCWSTR pszFile
   , BYVAL iIcon AS LONG _                              ' __in int iIcon
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetShortcutIcon ( _                           ' VTable offset = 28
     BYREF pszFile AS WSTRINGZ _                        ' __in LPCWSTR pszFile
   , BYVAL iIcon AS LONG _                              ' __in int iIcon
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetDefaultIcon ( _                            ' VTable offset = 32
     BYREF pszFile AS WSTRINGZ _                        ' __in LPCWSTR pszFile
   , BYVAL iIcon AS LONG _                              ' __in int iIcon
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDefaultExtractIconInit_INTERFACE_DEFINED__ */

DECLARE FUNCTION SHCreateDefaultExtractIcon IMPORT "SHELL32.DLL" ALIAS "SHCreateDefaultExtractIcon" ( _
   BYREF riid AS GUID _                                 ' __in REFIID riid
 , BYREF ppv AS IUnknown _                              ' __out void **ppv
 ) AS LONG                                              ' HRESULT


' ########################################################################################
' IExplorerCommand interface
' IID = A08CE4D0-FA25-44AB-B57C-C7B1C323E0B9
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IExplorerCommand_INTERFACE_DEFINED)
    %IExplorerCommand_INTERFACE_DEFINED = 1

$IID_IExplorerCommand = GUID$("{A08CE4D0-FA25-44AB-B57C-C7B1C323E0B9}")

' enum EXPCMDSTATE
%ECS_ENABLED         = 0???
%ECS_DISABLED        = &H1???
%ECS_HIDDEN          = &H2???
%ECS_CHECKBOX        = &H4???
%ECS_CHECKED         = &H8???
%ECS_RADIOCHECK      = &H10???
'typedef DWORD EXPCMDSTATE;

' enum EXPCMDFLAGS
%ECF_HASSUBCOMMANDS  = &H1???
%ECF_HASSPLITBUTTON  = &H2???
%ECF_HIDELABEL       = &H4???
%ECF_ISSEPARATOR     = &H8???
%ECF_HASLUASHIELD    = &H10???
%ECF_SEPARATORBEFORE = &H20???
%ECF_SEPARATORAFTER  = &H40???
%ECF_ISDROPDOWN      = &H80???
'typedef DWORD EXPCMDFLAGS;

INTERFACE IExplorerCommand $IID_IExplorerCommand

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetTitle ( _                                  ' VTable offset = 12
     BYVAL psiItemArray AS IShellItemArray _            ' __in IShellItemArray *psiItemArray
   , BYREF ppszName AS DWORD _                          ' __out LPWSTR *ppszName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetIcon ( _                                   ' VTable offset = 16
     BYVAL psiItemArray AS IShellItemArray _            ' __in IShellItemArray *psiItemArray
   , BYREF ppszIcon AS DWORD _                          ' __out LPWSTR *ppszIcon
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetToolTip ( _                                ' VTable offset = 20
     BYVAL psiItemArray AS IShellItemArray _            ' __in IShellItemArray *psiItemArray
   , BYREF ppszInfotip AS DWORD _                       ' __out LPWSTR *ppszInfotip
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCanonicalName ( _                          ' VTable offset = 24
     BYREF pguidCommandName AS GUID _                   ' __out GUID *pguidCommandName
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetState ( _                                  ' VTable offset = 28
     BYVAL psiItemArray AS IShellItemArray _            ' __in IShellItemArray *psiItemArray
   , BYVAL fOkToBeSlow AS LONG _                        ' __in BOOL fOkToBeSlow
   , BYREF pCmdState AS DWORD _                         ' __out EXPCMDSTATE *pCmdState
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Invoke ( _                                    ' VTable offset = 32
     BYVAL psiItemArray AS IShellItemArray _            ' __in IShellItemArray *psiItemArray
   , BYVAL pbc AS IBindCtx _                            ' __in IBindCtx *pbc
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFlags ( _                                  ' VTable offset = 36
     BYREF pFlags AS DWORD _                            ' __out EXPCMDFLAGS *pFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD EnumSubCommands ( _                           ' VTable offset = 40
     BYREF ppEnum AS IEnumExplorerCommand _             ' __out IEnumExplorerCommand **ppEnum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IExplorerCommand_INTERFACE_DEFINED__ */


' ########################################################################################
' IExplorerCommandState interface
' IID = BDDACB60-7657-47AE-8445-D23E1ACF82AE
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IExplorerCommandState_INTERFACE_DEFINED)
    %IExplorerCommandState_INTERFACE_DEFINED = 1

$IID_IExplorerCommandState = GUID$("{BDDACB60-7657-47AE-8445-D23E1ACF82AE}")

INTERFACE IExplorerCommandState $IID_IExplorerCommandState

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetState ( _                                  ' VTable offset = 12
     BYVAL psiItemArray AS IShellItemArray _            ' __in_opt IShellItemArray *psiItemArray
   , BYVAL fOkToBeSlow AS LONG _                        ' __in BOOL fOkToBeSlow
   , BYREF pCmdState AS DWORD _                         ' __out EXPCMDSTATE *pCmdState
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   '  /* __IExplorerCommandState_INTERFACE_DEFINED__ */


' ########################################################################################
' IInitializeCommand interface
' IID = 85075ACF-231F-40EA-9610-D26B7B58F638
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IInitializeCommand_INTERFACE_DEFINED)
    %IInitializeCommand_INTERFACE_DEFINED = 1

$IID_IInitializeCommand = GUID$("{85075ACF-231F-40EA-9610-D26B7B58F638}")

INTERFACE IInitializeCommand $IID_IInitializeCommand

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Initialize ( _                                ' VTable offset = 12
     BYREF pszCommandName AS WSTRINGZ _                 ' __in LPCWSTR pszCommandName
   , BYVAL ppb AS IPropertyBag _                        ' __in_opt IPropertyBag *ppb
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   '  /* __IInitializeCommand_INTERFACE_DEFINED__ */


' ########################################################################################
' IEnumExplorerCommand interface
' IID = A88826F8-186F-4987-AADE-EA0CEF8FBFE8
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IEnumExplorerCommand_INTERFACE_DEFINED)
    %IEnumExplorerCommand_INTERFACE_DEFINED = 1

$IID_IEnumExplorerCommand = GUID$("{A88826F8-186F-4987-AADE-EA0CEF8FBFE8}")

INTERFACE IEnumExplorerCommand $IID_IEnumExplorerCommand

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Next ( _                                      ' VTable offset = 12
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   , BYREF pUICommand AS IExplorerCommand _             ' __out IExplorerCommand **pUICommand
   , BYREF pceltFetched AS DWORD _                      ' __out ULONG *pceltFetched
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Skip ( _                                      ' VTable offset = 16
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Reset ( _                                     ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Clone ( _                                     ' VTable offset = 24
     BYREF ppenum AS IEnumExplorerCommand _             ' __out IEnumExplorerCommand **ppenum
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEnumExplorerCommand_INTERFACE_DEFINED__ */


' ########################################################################################
' IExplorerCommandProvider interface
' IID = 64961751-0835-43C0-8FFE-D57686530E64
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IExplorerCommandProvider_INTERFACE_DEFINED)
    %IExplorerCommandProvider_INTERFACE_DEFINED = 1

$IID_IExplorerCommandProvider = GUID$("{64961751-0835-43C0-8FFE-D57686530E64}")

INTERFACE IExplorerCommandProvider $IID_IExplorerCommandProvider

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetCommands ( _                               ' VTable offset = 12
     BYVAL punkSite AS IUnknown _                       ' __in IUnknown *punkSite
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppv AS IUnknown _                            ' __out void **ppv
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCommand ( _                                ' VTable offset = 16
     BYREF rguidCommandId AS GUID _                     ' __in REFGUID rguidCommandId
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppv AS IUnknown _                            ' __out void **ppv
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IExplorerCommandProvider_INTERFACE_DEFINED__ */


' ########################################################################################
' IMarkupCallback interface
' IID = 4440306E-D79A-48D0-88E6-A42692279BFB
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IMarkupCallback_INTERFACE_DEFINED)
    %IMarkupCallback_INTERFACE_DEFINED = 1

$IID_IMarkupCallback = GUID$("{4440306E-D79A-48D0-88E6-A42692279BFB}")

INTERFACE IMarkupCallback $IID_IMarkupCallback

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetState ( _                                  ' VTable offset = 12
     BYVAL dwId AS DWORD _                              ' __in DWORD dwId
   , BYVAL uState AS DWORD _                            ' __in UINT uState
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD InvalidateRect ( _                            ' VTable offset = 16
     BYVAL dwId AS DWORD _                              ' __in DWORD dwId
   , BYREF prc AS RECT _                                ' __in const RECT *prc
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnCustomDraw ( _                              ' VTable offset = 20
     BYVAL dwDrawStage AS DWORD _                       ' __in DWORD dwDrawStage
   , BYVAL hdc AS DWORD _                               ' __in HDC hdc
   , BYREF prc AS RECT _                                ' __in const RECT *prc
   , BYVAL dwId AS DWORD _                              ' __in DWORD dwId
   , BYVAL iLink AS LONG _                              ' __in int iLink
   , BYVAL uItemState AS DWORD _                        ' __in UINT uItemState
   , BYREF pdwResult AS LONG _                          ' __out LRESULT *pdwResult
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CustomDrawText ( _                            ' VTable offset = 24
     BYVAL hdc AS DWORD _                               ' __in HDC hDC
   , BYREF lpString AS WSTRINGZ _                       ' __in LPCWSTR lpString
   , BYVAL nCount AS LONG _                             ' __in int nCount
   , BYREF pRect AS RECT _                              ' __in RECT *pRect
   , BYVAL uFormat AS DWORD _                           ' __in UINT uFormat
   , BYVAL fLink AS LONG _                              ' __in BOOL fLink
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IMarkupCallback_INTERFACE_DEFINED__ */

'typedef HANDLE HTHEME;

' ########################################################################################
' IControlMarkup interface
' IID = D6D2FBAE-F116-458C-8C34-03569877A2D2
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IControlMarkup_INTERFACE_DEFINED)
    %IControlMarkup_INTERFACE_DEFINED = 1

$IID_IControlMarkup = GUID$("{D6D2FBAE-F116-458C-8C34-03569877A2D2}")

' enum MARKUPSIZE
%MARKUPSIZE_CALCWIDTH  = 0
%MARKUPSIZE_CALCHEIGHT = %MARKUPSIZE_CALCWIDTH + 1

' enum MARKUPLINKTEXT
%MARKUPLINKTEXT_URL  = 0
%MARKUPLINKTEXT_ID   = %MARKUPLINKTEXT_URL + 1
%MARKUPLINKTEXT_TEXT = %MARKUPLINKTEXT_ID + 1

' enum MARKUPSTATE
%MARKUPSTATE_FOCUSED       = &H1???
%MARKUPSTATE_ENABLED       = &H2???
%MARKUPSTATE_VISITED       = &H4???
%MARKUPSTATE_HOT           = &H8???
%MARKUPSTATE_DEFAULTCOLORS = &H10???
%MARKUPSTATE_ALLOWMARKUP   = &H40000000???
'typedef DWORD MARKUPSTATE;

' enum MARKUPMESSAGE
%MARKUPMESSAGE_KEYEXECUTE   = 0
%MARKUPMESSAGE_CLICKEXECUTE = %MARKUPMESSAGE_KEYEXECUTE   + 1
%MARKUPMESSAGE_WANTFOCUS    = %MARKUPMESSAGE_CLICKEXECUTE + 1

INTERFACE IControlMarkup $IID_IControlMarkup

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetCallback ( _                               ' VTable offset = 12
     BYVAL punk AS IUnknown _                           ' __in IUnknown *punk
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCallback ( _                               ' VTable offset = 16
     BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppvUnk AS IUnknown _                         ' __out void **ppvUnk
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetId ( _                                     ' VTable offset = 20
     BYVAL dwId AS DWORD _                              ' __in DWORD dwId
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetId ( _                                     ' VTable offset = 24
     BYREF pdwId AS DWORD _                             ' __out DWORD *pdwId
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetFonts ( _                                  ' VTable offset = 28
     BYVAL hFont AS DWORD _                             ' __in HFONT hFont
   , BYVAL hFontUnderline AS DWORD _                    ' __in HFONT hFontUnderline
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFonts ( _                                  ' VTable offset = 32
     BYREF phFont AS DWORD _                            ' __out HFONT *phFont
   , BYREF phFontUnderline AS DWORD _                   ' __out HFONT *phFontUnderline
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetText ( _                                   ' VTable offset = 36
     BYREF pwszText AS WSTRINGZ _                       ' __in LPCWSTR pwszText
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetText ( _                                   ' VTable offset = 40
     BYVAL bRaw AS LONG _                               ' __in BOOL bRaw
   , BYREF pwszText AS WSTRINGZ _                       ' __out LPWSTR pwszText
   , BYREF pdwCch AS DWORD _                            ' __inout DWORD *pdwCch
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetLinkText ( _                               ' VTable offset = 44
     BYVAL iLink AS LONG _                              ' __in int iLink
   , BYVAL uMarkupLinkText AS DWORD _                   ' __in UINT uMarkupLinkText
   , BYREF pwszText AS WSTRINGZ _                       ' __in LPCWSTR pwszText
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetLinkText ( _                               ' VTable offset = 48
     BYVAL iLink AS LONG _                              ' __in int iLink
   , BYVAL uMarkupLinkText AS DWORD _                   ' __in UINT uMarkupLinkText
   , BYREF pwszText AS WSTRINGZ _                       ' __out LPWSTR pwszText
   , BYREF pdwCch AS DWORD _                            ' __inout DWORD *pdwCch
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetRenderFlags ( _                            ' VTable offset = 52
     BYVAL uDT AS DWORD _                               ' __in UINT uDT
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRenderFlags ( _                            ' VTable offset = 56
     BYREF puDT AS DWORD _                              ' __out UINT *puDT
   , BYREF phTheme AS DWORD _                           ' __out HTHEME *phTheme
   , BYREF piPartId AS LONG _                           ' __out int *piPartId
   , BYREF piStateIdNormal AS LONG _                    ' __out int *piStateIdNormal
   , BYREF piStateIdLink AS LONG _                      ' __out int *piStateIdLink
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetThemeRenderFlags ( _                       ' VTable offset = 60
     BYVAL uDT AS DWORD _                               ' __in UINT uDT
   , BYVAL hTheme AS DWORD _                            ' __in HTHEME hTheme
   , BYVAL iPartId AS LONG _                            ' __in int iPartId
   , BYVAL iStateIdNormal AS LONG _                     ' __in int iStateIdNormal
   , BYVAL iStateIdLink AS LONG _                       ' __in int iStateIdLink
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetState ( _                                  ' VTable offset = 64
     BYVAL iLink AS LONG _                              ' __in int iLink
   , BYVAL uStateMask AS DWORD _                        ' __in UINT uStateMask
   , BYREF puState AS DWORD _                           ' __out UINT *puState
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetState ( _                                  ' VTable offset = 68
     BYVAL iLink AS LONG _                              ' __in int iLink
   , BYVAL uStateMask AS DWORD _                        ' __in UINT uStateMask
   , BYVAL uState AS DWORD _                            ' __in UINT uState
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DrawText ( _                                  ' VTable offset = 72
     BYVAL hdcClient AS DWORD _                         ' __in HDC hdcClient
   , BYREF prcClient AS RECT _                          ' __in LPCRECT prcClient
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetLinkCursor ( _                             ' VTable offset = 76
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CalcIdealSize ( _                             ' VTable offset = 76
     BYVAL hdc AS DWORD _                               ' __in HDC hdc
   , BYVAL uMarkUpCalc AS DWORD _                       ' __in UINT uMarkUpCalc
   , BYREF prc AS RECT _                                ' __inout RECT *prc
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetFocus ( _                                  ' VTable offset = 80
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD KillFocus ( _                                 ' VTable offset = 84
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsTabbable ( _                                ' VTable offset = 88
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnButtonDown ( _                              ' VTable offset = 92
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnButtonUp ( _                                ' VTable offset = 96
     BYVAL pt AS POINT _                                ' __in POINT pt
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD OnKeyDown ( _                                 ' VTable offset = 100
     BYVAL uVirtKey AS DWORD _                          ' __in UINT uVirtKey
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD HitTest ( _                                   ' VTable offset = 104
     BYVAL pt AS POINT _                                ' __in POINT pt
   , BYREF piLink AS LONG _                             ' __out int *piLink
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetLinkRect ( _                               ' VTable offset = 108
     BYVAL iLink AS LONG _                              ' __in int iLink
   , BYREF prc AS RECT _                                ' __out RECT *prc
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetControlRect ( _                            ' VTable offset = 112
     BYREF prcControl AS RECT _                         ' __out RECT *prcControl
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetLinkCount ( _                              ' VTable offset = 116
     BYREF pcLinks AS DWORD _                           ' __out UINT *pcLinks
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IControlMarkup_INTERFACE_DEFINED__ */


' ########################################################################################
' IInitializeNetworkFolder interface
' IID = 6E0F9881-42A8-4F2A-97F8-8AF4E026D92D
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IInitializeNetworkFolder_INTERFACE_DEFINED)
    %IInitializeNetworkFolder_INTERFACE_DEFINED = 1

$IID_IInitializeNetworkFolder = GUID$("{6E0F9881-42A8-4F2A-97F8-8AF4E026D92D}")

INTERFACE IInitializeNetworkFolder $IID_IInitializeNetworkFolder

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Initialize ( _                                ' VTable offset = 12
     BYVAL pidl AS DWORD _                              ' __in PCIDLIST_ABSOLUTE pidl
   , BYVAL pidlTarget AS DWORD _                        ' __in PCIDLIST_ABSOLUTE pidlTarget
   , BYVAL uDisplayType AS DWORD _                      ' __in UINT uDisplayType
   , BYREF pszResName AS WSTRINGZ _                     ' __in LPCWSTR pszResName
   , BYREF pszProvider AS WSTRINGZ _                    ' __in LPCWSTR pszProvider
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IInitializeNetworkFolder_INTERFACE_DEFINED__ */

' enum CPVIEW
%CPVIEW_CLASSIC  = 0
%CPVIEW_CATEGORY = 1
%CPVIEW_HOME     = %CPVIEW_CATEGORY

' ########################################################################################
' IOpenControlPanel interface
' IID = D11AD862-66DE-4DF4-BF6C-1F5621996AF1
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IOpenControlPanel_INTERFACE_DEFINED)
    %IOpenControlPanel_INTERFACE_DEFINED = 1

$IID_IOpenControlPanel = GUID$("{D11AD862-66DE-4DF4-BF6C-1F5621996AF1}")

INTERFACE IOpenControlPanel $IID_IOpenControlPanel

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Open ( _                                      ' VTable offset = 12
     BYREF pszName AS WSTRINGZ _                        ' __in LPCWSTR pszName
   , BYREF pszPage AS WSTRINGZ _                        ' __in LPCWSTR pszPage
   , BYVAL punkSite AS IUnknown _                       ' __in IUnknown *punkSite
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetPath ( _                                   ' VTable offset = 16
     BYREF pszName AS WSTRINGZ _                        ' __in LPCWSTR pszName
   , BYREF pszPath AS WSTRINGZ _                        ' __out LPWSTR pszPath
   , BYVAL cchPath AS DWORD _                           ' __in UINT cchPath
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetCurrentView ( _                            ' VTable offset = 20
     BYREF pView AS LONG _                              ' __out CPVIEW *pView
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IOpenControlPanel_INTERFACE_DEFINED__ */


' ########################################################################################
' ISystemCPLUpdate interface
' IID = A8A71374-80C2-49E0-8805-8524EBC45B07
' Inherited interface = IUnknown
' Removed in the Windows 7 SDK
' ########################################################################################

'#IF NOT %DEF(%ISystemCPLUpdate_INTERFACE_DEFINED)
'    %ISystemCPLUpdate_INTERFACE_DEFINED = 1

'$IID_ISystemCPLUpdate = GUID$("{A8A71374-80C2-49E0-8805-8524EBC45B07}")

'INTERFACE ISystemCPLUpdate $IID_ISystemCPLUpdate

'   INHERIT IUnknown

'   ' =====================================================================================
'   METHOD UpdateSystemInfo ( _                          ' VTable offset = 12
'     BYREF pszDescription AS WSTRINGZ _                 ' __in LPCWSTR pszDescription
'   , BYREF pszSpeed AS WSTRINGZ _                       ' __in LPCWSTR pszSpeed
'   , BYREF pszMemory AS WSTRINGZ _                      ' __in LPCWSTR pszMemory
'   , BYVAL dwNumProcessors AS DWORD _                   ' __in DWORD dwNumProcessors
'   ) AS LONG                                            ' HRESULT
'   ' =====================================================================================
'   METHOD UpdateLicensingInfo ( _                       ' VTable offset = 16
'     BYVAL dwNumProcessors AS DWORD _                   ' __in DWORD dwLicensingStatus
'   , BYVAL dwGraceTimeRemainingMinutes AS DWORD _       ' __in DWORD dwGraceTimeRemainingMinutes
'   , BYVAL dwTotalGraceTimeDays AS DWORD _              ' __in DWORD dwTotalGraceTimeDays
'   , BYVAL fIsGenuine AS LONG _                         ' __in BOOL fIsGenuine
'   ) AS LONG                                            ' HRESULT
'   ' =====================================================================================
'   METHOD UpdateRatingsInfo ( _                         ' VTable offset = 20
'     BYREF pszRatingsLink AS WSTRINGZ _                 ' __in LPCWSTR pszRatingsLink
'   , BYREF pszRatingsText AS WSTRINGZ _                 ' __in LPCWSTR pszRatingsText
'   , BYVAL hRatingsImage AS DWORD _                     ' __in HBITMAP hRatingsImage
'   , BYVAL uWinCRSLevel AS DWORD _                      ' __in USHORT uWinCRSLevel
'   ) AS LONG                                            ' HRESULT
'   ' =====================================================================================
'   METHOD UpdateComputerInfo ( _                        ' VTable offset = 24
'   ) AS LONG                                            ' HRESULT
'   ' =====================================================================================

'END INTERFACE

'#ENDIF   ' /* __ISystemCPLUpdate_INTERFACE_DEFINED__ */


' ########################################################################################
' IComputerInfoAdvise interface
' IID = 4623BD61-5603-444f-824A-AAEBCEED93FA
' Inherited interface = IUnknown
' Removed in the Windows 7 SDK
' ########################################################################################

'#IF NOT %DEF(%IComputerInfoAdvise_INTERFACE_DEFINED)
'    %IComputerInfoAdvise_INTERFACE_DEFINED = 1

'$IID_IComputerInfoAdvise = GUID$("{4623BD61-5603-444f-824A-AAEBCEED93FA}")

'INTERFACE IComputerInfoAdvise $IID_IComputerInfoAdvise

'   INHERIT IUnknown

'   ' =====================================================================================
'   METHOD Advise ( _                                    ' VTable offset = 12
'     BYVAL pUpdate AS ISystemCPLUpdate _                ' __in ISystemCPLUpdate *pUpdate
'   , BYREF pdwCookie AS DWORD _                         ' __out DWORD *pdwCookie
'   ) AS LONG                                            ' HRESULT
'   ' =====================================================================================
'   METHOD Unadvise ( _                                  ' VTable offset = 16
'     BYVAL dwCookie AS DWORD _                          ' __in DWORD dwCookie
'   ) AS LONG                                            ' HRESULT
'   ' =====================================================================================

'END INTERFACE

'#ENDIF   ' /* __IComputerInfoAdvise_INTERFACE_DEFINED__ */


' ########################################################################################
' IComputerInfoChangeNotify interface
' IID = 0DF60D92-6818-46D6-B358-D66170DDE466
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IComputerInfoChangeNotify_INTERFACE_DEFINED)
    %IComputerInfoChangeNotify_INTERFACE_DEFINED = 1

$IID_IComputerInfoChangeNotify = GUID$("{0DF60D92-6818-46D6-B358-D66170DDE466}")

INTERFACE IComputerInfoChangeNotify $IID_IComputerInfoChangeNotify

   INHERIT IUnknown

   ' =====================================================================================
   METHOD ComputerInfoChanged ( _                       ' VTable offset = 12
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IComputerInfoChangeNotify_INTERFACE_DEFINED__ */

' Must be in unicode format
$STR_FILE_SYS_BIND_DATA      = "File System Bind Data"


' ########################################################################################
' IFileSystemBindData interface
' IID = 01E18D10-4D8B-11D2-855D-006008059367
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IFileSystemBindData_INTERFACE_DEFINED)
    %IFileSystemBindData_INTERFACE_DEFINED = 1

$IID_IFileSystemBindData = GUID$("{01E18D10-4D8B-11D2-855D-006008059367}")

INTERFACE IFileSystemBindData $IID_IFileSystemBindData

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetFindData ( _                               ' VTable offset = 12
     BYREF pfd AS WIN32_FIND_DATAW _                    ' __in const WIN32_FIND_DATAW *pfd
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFindData ( _                               ' VTable offset = 16
     BYREF pfd AS WIN32_FIND_DATAW _                    ' __out WIN32_FIND_DATAW *pfd
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IFileSystemBindData_INTERFACE_DEFINED__ */


' ########################################################################################
' IFileSystemBindData2 interface
' IID = 3ACF075F-71DB-4AFA-81F0-3FC4FDF2A5B8
' Inherited interface = IFileSystemBindData
' ########################################################################################

#IF NOT %DEF(%IFileSystemBindData2_INTERFACE_DEFINED)
    %IFileSystemBindData2_INTERFACE_DEFINED = 1

$IID_IFileSystemBindData2 = GUID$("{3ACF075F-71DB-4AFA-81F0-3FC4FDF2A5B8}")

INTERFACE IFileSystemBindData2 $IID_IFileSystemBindData2

   INHERIT IUnknown

   ' =====================================================================================
   ' IFileSystemBindData Methods
   ' =====================================================================================
   METHOD SetFindData ( _                               ' VTable offset = 12
     BYREF pfd AS WIN32_FIND_DATAW _                    ' __in const WIN32_FIND_DATAW *pfd
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFindData ( _                               ' VTable offset = 16
     BYREF pfd AS WIN32_FIND_DATAW _                    ' __out WIN32_FIND_DATAW *pfd
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

   ' =====================================================================================
   ' IFileSystemBindData2 Methods
   ' =====================================================================================
   METHOD SetFileID ( _                                 ' VTable offset = 20
     BYVAL liFileID AS QUAD _                           ' __in LARGE_INTEGER liFileID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFileID ( _                                 ' VTable offset = 24
     BYREF pliFileID AS QUAD _                          ' __out LARGE_INTEGER *pliFileID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetJunctionCLSID ( _                          ' VTable offset = 28
     BYREF clsid AS GUID _                              ' __in REFCLSID clsid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetJunctionCLSID ( _                          ' VTable offset = 32
     BYREF pclsid AS GUID _                             ' __out CLSID *pclsid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IFileSystemBindData2_INTERFACE_DEFINED__ */


' ########################################################################################
' ICustomDestinationList interface
' IID = 6332DEBF-87B5-4670-90C0-5E57B408A49E
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%ICustomDestinationList_INTERFACE_DEFINED)
    %ICustomDestinationList_INTERFACE_DEFINED = 1

' enum KNOWNDESTCATEGORY
%KDC_FREQUENT = 1
%KDC_RECENT   = %KDC_FREQUENT + 1

$IID_ICustomDestinationList = GUID$("{6332DEBF-87B5-4670-90C0-5E57B408A49E}")

INTERFACE ICustomDestinationList $IID_ICustomDestinationList

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetAppID ( _                                  ' VTable offset = 12
     BYREF pszAppID AS WSTRINGZ _                       ' __in LPCWSTR pszAppID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD BeginList ( _                                 ' VTable offset = 16
     BYREF pcMinSlots AS DWORD _                        ' __out UINT *pcMinSlots
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppv AS IUnknown _                            ' __out_opt void **ppv
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AppendCategory ( _                            ' VTable offset = 20
     BYREF pszCategory AS WSTRINGZ _                    ' __in LPCWSTR pszCategory
   , BYREF poa AS IObjectArray _                        ' __in_opt IObjectArray *poa
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AppendKnownCategory ( _                       ' VTable offset = 24
     BYVAL category AS LONG _                           ' __in KNOWNDESTCATEGORY category
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddUserTasks ( _                              ' VTable offset = 28
     BYVAL poa AS IObjectArray _                        ' __in_opt IObjectArray *poa
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CommitList ( _                                ' VTable offset = 32
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetRemovedDestinations ( _                    ' VTable offset = 36
     BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppv AS IUnknown _                            ' __out_opt void **ppv
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD DeleteList ( _                                ' VTable offset = 40
     BYREF pszAppID AS WSTRINGZ _                       ' __in_opt LPCWSTR pszAppID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AbortList ( _                                 ' VTable offset = 44
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __ICustomDestinationList_INTERFACE_DEFINED__ */


' ########################################################################################
' IApplicationDestinations interface
' IID = 12337D35-94C6-48A0-BCE7-6A9C69D4D600
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IApplicationDestinations_INTERFACE_DEFINED)
    %IApplicationDestinations_INTERFACE_DEFINED = 1

$IID_IApplicationDestinations = GUID$("{12337D35-94C6-48A0-BCE7-6A9C69D4D600}")

INTERFACE IApplicationDestinations $IID_IApplicationDestinations

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetAppID ( _                                  ' VTable offset = 12
     BYREF pszAppID AS WSTRINGZ _                       ' __in LPCWSTR pszAppID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RemoveDestination ( _                         ' VTable offset = 16
     BYVAL punk AS IUnknown _                           ' __in_opt IUnknown *punk
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RemoveAllDestinations ( _                     ' VTable offset = 20
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IApplicationDestinations_INTERFACE_DEFINED__ */


' ########################################################################################
' IApplicationDocumentLists interface
' IID = 3C594F9F-9F30-47A1-979A-C9E83D3D0A06
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IApplicationDocumentLists_INTERFACE_DEFINED)
    %IApplicationDocumentLists_INTERFACE_DEFINED = 1

' enum APPDOCLISTTYPE
%ADLT_RECENT   = 0
%ADLT_FREQUENT = %ADLT_RECENT + 1

$IID_IApplicationDocumentLists = GUID$("{3C594F9F-9F30-47A1-979A-C9E83D3D0A06}")

INTERFACE IApplicationDocumentLists $IID_IApplicationDocumentLists

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetAppID ( _                                  ' VTable offset = 12
     BYREF pszAppID AS WSTRINGZ _                       ' __in LPCWSTR pszAppID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetList ( _                                   ' VTable offset = 16
     BYVAL listtype AS LONG _                           ' __in APPDOCLISTTYPE listtype
   , BYVAL cItemsDesired AS DWORD _                     ' __in UINT cItemsDesired
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppv AS IUnknown _                            ' __out_opt void **ppv
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IApplicationDocumentLists_INTERFACE_DEFINED__ */


' ########################################################################################
' IObjectWithAppUserModelID interface
' IID = 36DB0196-9665-46D1-9BA7-D3709EECF9ED
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IObjectWithAppUserModelID_INTERFACE_DEFINED)
    %IObjectWithAppUserModelID_INTERFACE_DEFINED = 1

$IID_IObjectWithAppUserModelID = GUID$("{36DB0196-9665-46D1-9BA7-D3709EECF9ED}")

INTERFACE IObjectWithAppUserModelID $IID_IObjectWithAppUserModelID

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetAppID ( _                                  ' VTable offset = 12
     BYREF pszAppID AS WSTRINGZ _                       ' __in LPCWSTR pszAppID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetAppID ( _                                  ' VTable offset = 16
     BYREF ppszAppID AS DWORD _                         ' __out LPWSTR *ppszAppID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IObjectWithAppUserModelID_INTERFACE_DEFINED__ */


' ########################################################################################
' IObjectWithProgID interface
' IID = 36DB0196-9665-46D1-9BA7-D3709EECF9ED
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IObjectWithProgID_INTERFACE_DEFINED)
    %IObjectWithProgID_INTERFACE_DEFINED = 1

$IID_IObjectWithProgID = GUID$("{36DB0196-9665-46D1-9BA7-D3709EECF9ED}")

INTERFACE IObjectWithProgID $IID_IObjectWithProgID

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SetProgID ( _                                 ' VTable offset = 12
     BYREF pszProgID AS WSTRINGZ _                      ' __in LPCWSTR pszProgID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetProgID ( _                                 ' VTable offset = 16
     BYREF ppszProgID AS DWORD _                        ' __out LPWSTR *ppszProgID
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IObjectWithProgID_INTERFACE_DEFINED__ */


' ########################################################################################
' IUpdateIDList interface
' IID = 6589B6D2-5F8D-4B9E-B7E0-23CDD9717D8C
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IObjectWithProgID_INTERFACE_DEFINED)
    %IObjectWithProgID_INTERFACE_DEFINED = 1

$IID_IUpdateIDList = GUID$("{6589B6D2-5F8D-4B9E-B7E0-23CDD9717D8C}")

INTERFACE IUpdateIDList $IID_IUpdateIDList

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Update ( _                                    ' VTable offset = 12
     BYVAL pbc AS IBindCtx _                            ' __in_opt IBindCtx *pbc
   , BYVAL IBindCtx AS DWORD _                          ' __in PCUITEMID_CHILD pidlIn
   , BYREF ppidlOut AS DWORD _                          ' __out PITEMID_CHILD *ppidlOut
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IObjectWithProgID_INTERFACE_DEFINED__ */

DECLARE FUNCTION SetCurrentProcessExplicitAppUserModelID IMPORT "SHELL32.DLL" ALIAS "SetCurrentProcessExplicitAppUserModelID" ( _
   BYREF AppID AS WSTRINGZ _                            ' __in PCWSTR AppID
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION GetCurrentProcessExplicitAppUserModelID IMPORT "SHELL32.DLL" ALIAS "GetCurrentProcessExplicitAppUserModelID" ( _
   BYREF AppID AS DWORD _                               ' __out PWSTR *AppID
 ) AS LONG                                              ' HRESULT

'#endif // NTDDI_WIN7

' ########################################################################################
' IDesktopGadget interface
' IID = C1646BC4-F298-4F91-A204-EB2DD1709D1A
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IDesktopGadget_INTERFACE_DEFINED)
    %IDesktopGadget_INTERFACE_DEFINED = 1

$IID_IDesktopGadget = GUID$("{C1646BC4-F298-4F91-A204-EB2DD1709D1A}")

INTERFACE IDesktopGadget $IID_IDesktopGadget

   INHERIT IUnknown

   ' =====================================================================================
   METHOD RunGadget ( _                                 ' VTable offset = 12
     BYREF gadgetPath AS WSTRINGZ _                     ' __in LPCWSTR gadgetPath
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IDesktopGadget_INTERFACE_DEFINED__ */

'#define HOMEGROUP_SECURITY_GROUP L"HomeUsers"
$HOMEGROUP_SECURITY_GROUP = "HomeUsers"


' ########################################################################################
' IHomeGroup interface
' IID = 7A3BD1D9-35A9-4FB3-A467-F48CAC35E2D0
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IHomeGroup_INTERFACE_DEFINED)
    %IHomeGroup_INTERFACE_DEFINED = 1

' enum HOMEGROUPSHARINGCHOICES
%HGSC_NONE             = 0???
%HGSC_MUSICLIBRARY     = &H1???
%HGSC_PICTURESLIBRARY  = &H2???
%HGSC_VIDEOSLIBRARY    = &H4???
%HGSC_DOCUMENTSLIBRARY = &H8???
%HGSC_PRINTERS         = &H10???

$IID_IHomeGroup = GUID$("{7A3BD1D9-35A9-4FB3-A467-F48CAC35E2D0}")

INTERFACE IHomeGroup $IID_IHomeGroup

   INHERIT IUnknown

   ' =====================================================================================
   METHOD IsMember ( _                                  ' VTable offset = 12
     BYREF member AS LONG _                             ' __out BOOL *member
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ShowSharingWizard ( _                         ' VTable offset = 16
     BYVAL owner AS DWORD _                             ' __in HWND owner
   , BYREF sharingchoices AS DWORD _                    ' __out HOMEGROUPSHARINGCHOICES *sharingchoices
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IHomeGroup_INTERFACE_DEFINED__ */


' ########################################################################################
' IInitializeWithPropertyStore interface
' IID = C3E12EB5-7D8D-44F8-B6DD-0E77B34D6DE4
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IInitializeWithPropertyStore_INTERFACE_DEFINED)
    %IInitializeWithPropertyStore_INTERFACE_DEFINED = 1

$IID_IInitializeWithPropertyStore = GUID$("{C3E12EB5-7D8D-44F8-B6DD-0E77B34D6DE4}")

INTERFACE IInitializeWithPropertyStore $IID_IInitializeWithPropertyStore

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Initialize ( _                                ' VTable offset = 12
     BYVAL pps AS IPropertyStore _                      ' __in_opt IPropertyStore *pps
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IInitializeWithPropertyStore_INTERFACE_DEFINED__ */


' ########################################################################################
' IOpenSearchSource interface
' IID = F0EE7333-E6FC-479b-9F25-A860C234A38E
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IOpenSearchSource_INTERFACE_DEFINED)
    %IOpenSearchSource_INTERFACE_DEFINED = 1

$IID_IOpenSearchSource = GUID$("{F0EE7333-E6FC-479b-9F25-A860C234A38E}")

INTERFACE IOpenSearchSource $IID_IOpenSearchSource

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetResults ( _                                ' VTable offset = 12
     BYVAL hwnd AS DWORD _                              ' __in HWND hwnd
   , BYREF pszQuery AS WSTRINGZ _                       ' __in LPCWSTR pszQuery
   , BYVAL dwStartIndex AS DWORD _                      ' __in DWORD dwStartIndex
   , BYVAL dwCount AS DWORD _                           ' __in DWORD dwCount
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppv AS IUnknown _                            ' __out_opt void **ppv
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IOpenSearchSource_INTERFACE_DEFINED__ */


' ########################################################################################
' IShellLibrary interface
' IID = 11A66EFA-382E-451A-9234-1E0E12EF3085
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IShellLibrary_INTERFACE_DEFINED)
    %IShellLibrary_INTERFACE_DEFINED = 1

' enum LIBRARYFOLDERFILTER
%LFF_FORCEFILESYSTEM = 1
%LFF_STORAGEITEMS    = 2
%LFF_ALLITEMS        = 3

' enum LIBRARYOPTIONFLAGS
%LOF_DEFAULT         = 0???
%LOF_PINNEDTONAVPANE = &H1???
%LOF_MASK_ALL        = &H1???

' enum DEFAULTSAVEFOLDERTYPE
%DSFT_DETECT  = 1
%DSFT_PRIVATE = %DSFT_DETECT  + 1
%DSFT_PUBLIC  = %DSFT_PRIVATE + 1

' enum LIBRARYSAVEFLAGS
%LSF_FAILIFTHERE      = 0???
%LSF_OVERRIDEEXISTING = &H1???
%LSF_MAKEUNIQUENAME   = &H2???

$IID_IShellLibrary = GUID$("{11A66EFA-382E-451A-9234-1E0E12EF3085}")

INTERFACE IShellLibrary $IID_IShellLibrary

   INHERIT IUnknown

   ' =====================================================================================
   METHOD LoadLibraryFromItem ( _                       ' VTable offset = 12
     BYVAL psiLibrary AS IShellItem _                   ' __in_opt IShellItem *psiLibrary
   , BYVAL grfMode AS DWORD _                           ' __in DWORD grfMode
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD LoadLibraryFromKnownFolder ( _                ' VTable offset = 16
     BYREF kfidLibrary AS GUID _                        ' __in REFKNOWNFOLDERID kfidLibrary
   , BYVAL grfMode AS DWORD _                           ' __in DWORD grfMode
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD AddFolder ( _                                 ' VTable offset = 20
     BYVAL psiLocation AS IShellItem _                  ' __in_opt IShellItem *psiLocation
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD RemoveFolder ( _                              ' VTable offset = 24
     BYVAL psiLocation AS IShellItem _                  ' __in_opt IShellItem *psiLocation
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFolders ( _                                ' VTable offset = 28
     BYVAL lff AS LONG _                                ' __in LIBRARYFOLDERFILTER lff
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppv AS IUnknown _                            ' __out_opt void **ppv
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD ResolveFolder ( _                             ' VTable offset = 32
     BYVAL psiFolderToResolve AS IShellItem _           ' __in_opt IShellItem *psiFolderToResolve
   , BYVAL dwTimeout AS DWORD _                         ' __in DWORD dwTimeout
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppv As IUnknown _                            ' __out_opt void **ppv
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetDefaultSaveFolder ( _                      ' VTable offset = 36
     BYVAL dsft AS LONG _                               ' __in DEFAULTSAVEFOLDERTYPE dsft
   , BYREF riid AS GUID _                               ' __in REFIID riid
   , BYREF ppv AS IUnknown _                            ' __out_opt void **ppv
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetDefaultSaveFolder ( _                      ' VTable offset = 40
     BYVAL dsft AS LONG _                               ' __in DEFAULTSAVEFOLDERTYPE dsft
   , BYVAL psi AS IShellItem _                          ' __in_opt IShellItem *psi
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetOptions ( _                                ' VTable offset = 44
     BYREF plofOptions AS DWORD _                       ' __out LIBRARYOPTIONFLAGS *plofOptions
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetOptions ( _                                ' VTable offset = 48
     BYVAL lofMask AS DWORD _                           ' __in LIBRARYOPTIONFLAGS lofMask
   , BYVAL lofOptions AS DWORD _                        ' __in LIBRARYOPTIONFLAGS lofOptions
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetFolderType ( _                             ' VTable offset = 52
     BYREF pftid AS GUID _                              ' __out FOLDERTYPEID *pftid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetFolderType ( _                             ' VTable offset = 56
     BYREF ftid AS GUID _                               ' __in REFFOLDERTYPEID ftid
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetIcon ( _                                   ' VTable offset = 60
     BYREF ppszIcon AS DWORD _                          ' __out LPWSTR *ppszIcon
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SetIcon ( _                                   ' VTable offset = 64
     BYREF ppszIcon AS WSTRINGZ _                       ' __in LPCWSTR pszIcon
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Commit ( _                                    ' VTable offset = 68
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Save ( _                                      ' VTable offset = 72
     BYVAL psiFolderToSaveIn AS IShellItem _            ' __in_opt IShellItem *psiFolderToSaveIn
   , BYREF pszLibraryName AS WSTRINGZ _                 ' __in LPCWSTR pszLibraryName
   , BYVAL lsf AS DWORD _                               ' __in LIBRARYSAVEFLAGS lsf
   , BYREF ppsiSavedTo AS IShellItem _                  ' __out_opt IShellItem **ppsiSavedTo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD SaveInKnownFolder ( _                         ' VTable offset = 76
     BYREF kfidToSaveIn AS GUID _                       ' __in REFKNOWNFOLDERID kfidToSaveIn
   , BYREF pszLibraryName AS WSTRINGZ _                 ' __in LPCWSTR pszLibraryName
   , BYVAL lsf AS DWORD _                               ' __in LIBRARYSAVEFLAGS lsf
   , BYREF ppsiSavedTo AS IShellItem _                  ' __out_opt IShellItem **ppsiSavedTo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IShellLibrary_INTERFACE_DEFINED__ */

#IF NOT %DEF(%ShellObjects_LIBRARY_DEFINED)
    %ShellObjects_LIBRARY_DEFINED = 1

'EXTERN_C const IID LIBID_ShellObjects;

$CLSID_ShellDesktop                         = GUID$("{00021400-0000-0000-C000-000000000046}")
$CLSID_ShellFSFolder                        = GUID$("{F3364BA0-65B9-11CE-A9BA-00AA004AE837}")
$CLSID_NetworkPlaces                        = GUID$("{208D2C60-3AEA-1069-A2D7-08002B30309D}")
$CLSID_ShellLink                            = GUID$("{00021401-0000-0000-C000-000000000046}")
$CLSID_QueryCancelAutoPlay                  = GUID$("{331F1768-05A9-4DDD-B86E-DAE34DDC998A}")
$CLSID_DriveSizeCategorizer                 = GUID$("{94357B53-CA29-4B78-83AE-E8FE7409134F}")
$CLSID_DriveTypeCategorizer                 = GUID$("{B0A8F3CF-4333-4BAB-8873-1CCB1CADA48B}")
$CLSID_FreeSpaceCategorizer                 = GUID$("{B5607793-24AC-44C7-82E2-831726AA6CB7}")
$CLSID_TimeCategorizer                      = GUID$("{3BB4118F-DDFD-4D30-A348-9FB5D6BF1AFE}")
$CLSID_SizeCategorizer                      = GUID$("{55D7B852-F6D1-42F2-AA75-8728A1B2D264}")
$CLSID_AlphabeticalCategorizer              = GUID$("{3C2654C6-7372-4F6B-B310-55D6128F49D2}")
$CLSID_MergedCategorizer                    = GUID$("{8E827C11-33E7-4BC1-B242-8CD9A1C2B304}")
$CLSID_ImageProperties                      = GUID$("{7AB770C7-0E23-4D7A-8AA2-19BFAD479829}")
$CLSID_PropertiesUI                         = GUID$("{D912F8CF-0396-4915-884E-FB425D32943B}")
$CLSID_UserNotification                     = GUID$("{0010890E-8789-413C-ADBC-48F5B511B3AF}")
$CLSID_CDBurn                               = GUID$("{FBEB8A05-BEEE-4442-804E-409D6C4515E9}")
$CLSID_TaskbarList                          = GUID$("{56FDF344-FD6D-11D0-958A-006097C9A090}")
$CLSID_StartMenuPin                         = GUID$("{A2A9545D-A0C2-42B4-9708-A0B2BADD77C8}")
$CLSID_WebWizardHost                        = GUID$("{C827F149-55C1-4D28-935E-57E47CAED973}")
$CLSID_PublishDropTarget                    = GUID$("{CC6EEFFB-43F6-46C5-9619-51D571967F7D}")
$CLSID_PublishingWizard                     = GUID$("{6B33163C-76A5-4B6C-BF21-45DE9CD503A1}")
$SID_PublishingWizard                       = GUID$("{6B33163C-76A5-4B6C-BF21-45DE9CD503A1}")
$CLSID_InternetPrintOrdering                = GUID$("{ADD36AA8-751A-4579-A266-D66F5202CCBB}")
$CLSID_FolderViewHost                       = GUID$("{20B1CB23-6968-4EB9-B7D4-A66D00D07CEE}")
$CLSID_ExplorerBrowser                      = GUID$("{71F96385-DDD6-48D3-A0C1-AE06E8B055FB}")
$CLSID_ImageRecompress                      = GUID$("{6E33091C-D2F8-4740-B55E-2E11D1477A2C}")
$CLSID_TrayBandSiteService                  = GUID$("{F60AD0A0-E5E1-45CB-B51A-E15B9F8B2934}")
$CLSID_TrayDeskBand                         = GUID$("{E6442437-6C68-4F52-94DD-2CFED267EFB9}")
$CLSID_AttachmentServices                   = GUID$("{4125DD96-E03A-4103-8F70-E0597D803B9C}")
$CLSID_DocPropShellExtension                = GUID$("{883373C3-BF89-11D1-BE35-080036B11A03}")
$CLSID_ShellItem                            = GUID$("{9AC9FBE1-E0A2-4AD6-B4EE-E212013EA917}")
$CLSID_NamespaceWalker                      = GUID$("{72EB61E0-8672-4303-9175-F2E4C68B2E7C}")
$CLSID_FileOperation                        = GUID$("{3AD05575-8857-4850-9277-11B85BDB8E09}")
$CLSID_FileOpenDialog                       = GUID$("{DC1C5A9C-E88A-4DDE-A5A1-60F82A20AEF7}")
$CLSID_FileSaveDialog                       = GUID$("{C0B4E2F3-BA21-4773-8DBA-335EC946EB8B}")
$CLSID_KnownFolderManager                   = GUID$("{4DF0C730-DF9D-4AE3-9153-AA6B82E9795A}")
$CLSID_FSCopyHandler                        = GUID$("{D197380A-0A79-4DC8-A033-ED882C2FA14B}")
$CLSID_SharingConfigurationManager          = GUID$("{49F371E1-8C5C-4D9C-9A3B-54A6827F513C}")
$CLSID_PreviousVersions                     = GUID$("{596AB062-B4D2-4215-9F74-E9109B0A8153}")
$CLSID_NetworkConnections                   = GUID$("{7007ACC7-3202-11D1-AAD2-00805FC1270E}")
$CLSID_NamespaceTreeControl                 = GUID$("{AE054212-3535-4430-83ED-D501AA6680E6}")
$CLSID_IENamespaceTreeControl               = GUID$("{ACE52D03-E5CD-4b20-82FF-E71B11BEAE1D}")
$CLSID_ScheduledTasks                       = GUID$("{D6277990-4C6A-11CF-8D87-00AA0060F5BF}")
$CLSID_ApplicationAssociationRegistration   = GUID$("{591209C7-767B-42B2-9FBA-44EE4615F2C7}")
$CLSID_ApplicationAssociationRegistrationUI = GUID$("{1968106D-F3B5-44CF-890E-116FCB9ECEF1}")
$CLSID_SearchFolderItemFactory              = GUID$("{14010E02-BBBD-41F0-88E3-EDA371216584}")
$CLSID_OpenControlPanel                     = GUID$("{06622D85-6856-4460-8DE1-A81921B41C4B}")
$CLSID_MailRecipient                        = GUID$("{9E56BE60-C50F-11CF-9A2C-00A0C90A90CE}")
$CLSID_NetworkExplorerFolder                = GUID$("{F02C1A0D-BE21-4350-88B0-7367FC96EF3C}")
$CLSID_DestinationList                      = GUID$("{77F10CF0-3DB5-4966-B520-B7C54FD35ED6}")
$CLSID_ApplicationDestinations              = GUID$("{86C14003-4D6B-4EF3-A7B4-0506663B2E68}")
$CLSID_ApplicationDocumentLists             = GUID$("{86BEC222-30F2-47E0-9F25-60D11CD75C28}")
$CLSID_HomeGroup                            = GUID$("{DE77BA04-3C92-4D11-A1A5-42352A53E0E3}")
$CLSID_ShellLibrary                         = GUID$("{D9B3211D-E57F-4426-AAEF-30A806ADD397}")
$CLSID_AppStartupLink                       = GUID$("{273EB5E7-88B0-4843-BFEF-E2C81D43AAE5}")
$CLSID_EnumerableObjectCollection           = GUID$("{2D3468C1-36A7-43B6-AC24-D3F02FD9607A}")
$CLSID_DesktopGadget                        = GUID$("{924CCC1B-6562-4C85-8657-D177925222B6}")

' Removed in the Vista SDK
'$CLSID_NetCrawler                           = GUID$("{601AC3DC-786A-4EB0-BF40-EE3521E70BFB}")
'$CLSID_PassportWizard                       = GUID$("{58F1F272-9240-4F51-B6D4-FD63D1618591}")
'$CLSID_ShellTaskScheduler                   = GUID$("{603D3800-BD81-11D0-A3A5-00C04FD706EC}")
'$CLSID_UserEventTimerCallback               = GUID$("{15FFFD13-5140-41B8-B89A-C8D5759CD2B2}")   ' // Removed in the Vista SDK
'$CLSID_UserEventTimer                       = GUID$("{864A1288-354C-4D19-9D68-C2742BB14997}")   ' // Removed in the Vista SDK

' Removed in the Windows 7 SDK
'$CLSID_ComputerInfoAdvise                   = GUID$("{00A77FF7-A514-493E-B721-CDF8CB0F5B59}")   ' // Removed in the Vista SDK

#ENDIF   ' /* __ShellObjects_LIBRARY_DEFINED__ */

'#if (NTDDI_VERSION >= NTDDI_VISTA)
DECLARE FUNCTION SHGetTemporaryPropertyForItem IMPORT "SHELL32.DLL" ALIAS "SHGetTemporaryPropertyForItem" ( _
   BYVAL psi AS IShellItem _                            ' __in IShellItem *psi
 , BYREF propkey AS PROPERTYKEY _                       ' __in REFPROPERTYKEY propkey
 , BYREF ppropvar AS ANY _                              ' __out PROPVARIANT *ppropvar
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION SHSetTemporaryPropertyForItem IMPORT "SHELL32.DLL" ALIAS "SHSetTemporaryPropertyForItem" ( _
   BYVAL psi AS IShellItem _                            ' __in IShellItem *psi
 , BYREF propkey AS PROPERTYKEY _                       ' __in REFPROPERTYKEY propkey
 , BYREF ppropvar AS ANY _                              ' __out PROPVARIANT *ppropvar
 ) AS LONG                                              ' HRESULT
'#endif  // NTDDI_VISTA

'#if (NTDDI_VERSION >= NTDDI_WIN7)
'#if (_WIN32_IE >= _WIN32_IE_IE70)

' enum LIBRARYMANAGEDIALOGOPTIONS
%LMD_DEFAULT = 0
%LMD_ALLOWUNINDEXABLENETWORKLOCATIONS = &H1

DECLARE FUNCTION SHShowManageLibraryUI IMPORT "SHELL32.DLL" ALIAS "SHShowManageLibraryUI" ( _
   BYVAL psiLibrary AS IShellItem _                     ' __in IShellItem *psiLibrary
 , BYVAL hwndOwner AS DWORD _                           ' __in HWND hwndOwner
 , BYREF pszTitle AS WSTRINGZ _                         ' __in_opt LPCWSTR pszTitle
 , BYREF pszInstruction AS WSTRINGZ _                   ' __in_opt LPCWSTR pszInstruction
 , BYVAL lmdOptions AS LONG _                           ' __in LIBRARYMANAGEDIALOGOPTIONS lmdOptions
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION SHResolveLibrary IMPORT "SHELL32.DLL" ALIAS "SHResolveLibrary" ( _
   BYVAL psiLibrary AS IShellItem _                     ' __in IShellItem *psiLibrary
 ) AS LONG                                              ' HRESULT

'#ifdef __cplusplus

'__inline HRESULT SHCreateLibrary(__in REFIID riid, __deref_out void **ppv)
'{
'    return CoCreateInstance(CLSID_ShellLibrary, NULL, CLSCTX_INPROC_SERVER, riid, ppv);
'}

FUNCTION SHCreateLibrary (BYREF riid AS GUID, BYREF ppv AS IUnknown) AS LONG
   FUNCTION = CoCreateInstance($CLSID_ShellLibrary, NOTHING, %CLSCTX_INPROC_SERVER, riid, ppv)
END FUNCTION

'__inline HRESULT SHLoadLibraryFromItem(__in IShellItem *psiLibrary, __in DWORD grfMode, __in REFIID riid, __deref_out void **ppv)
'{
'    *ppv = NULL;
'    IShellLibrary *plib;
'    HRESULT hr = CoCreateInstance(CLSID_ShellLibrary, NULL, CLSCTX_INPROC_SERVER, IID_PPV_ARGS(&plib));
'    if (SUCCEEDED(hr))
'    {
'        hr = plib->LoadLibraryFromItem(psiLibrary, grfMode);
'        if (SUCCEEDED(hr))
'        {
'            hr = plib->QueryInterface(riid, ppv);
'        }
'        plib->Release();
'    }
'    return hr;
'}

FUNCTION SHLoadLibraryFromItem (BYVAL psiLibrary AS IShellItem, BYVAL grfMode AS DWORD, BYREF riid AS GUID, BYREF ppv AS IUnknown) AS LONG

   LOCAL hr AS LONG
   LOCAL plib AS IShellLibrary

   hr = CoCreateInstance($CLSID_ShellLibrary, NOTHING, %CLSCTX_INPROC_SERVER, $IID_IShellLibrary, plib)
   IF SUCCEEDED(hr) THEN
      hr = plib.LoadLibraryFromItem(psiLibrary, grfMode)
      IF SUCCEEDED(hr) THEN
         hr = plib.QueryInterface(riid, BYVAL VARPTR(ppv))
      END IF
      plib = NOTHING
   END IF
   FUNCTION = hr

END FUNCTION

'__inline HRESULT SHLoadLibraryFromKnownFolder(__in REFKNOWNFOLDERID kfidLibrary, __in DWORD grfMode, __in REFIID riid, __deref_out void **ppv)
'{
'    *ppv = NULL;
'    IShellLibrary *plib;
'    HRESULT hr = CoCreateInstance(CLSID_ShellLibrary, NULL, CLSCTX_INPROC_SERVER, IID_PPV_ARGS(&plib));
'    if (SUCCEEDED(hr))
'    {
'        hr = plib->LoadLibraryFromKnownFolder(kfidLibrary, grfMode);
'        if (SUCCEEDED(hr))
'        {
'            hr = plib->QueryInterface(riid, ppv);
'        }
'        plib->Release();
'    }
'    return hr;
'}

FUNCTION SHLoadLibraryFromKnownFolder (BYREF kfidLibrary AS GUID, BYVAL grfMode AS DWORD, BYREF riid AS GUID, BYREF ppv AS IUnknown) AS LONG

   LOCAL hr AS LONG
   LOCAL plib AS IShellLibrary

   hr = CoCreateInstance($CLSID_ShellLibrary, NOTHING, %CLSCTX_INPROC_SERVER, $IID_IShellLibrary, plib)
   IF SUCCEEDED(hr) THEN
      hr = plib.LoadLibraryFromKnownFolder(kfidLibrary, grfMode)
      IF SUCCEEDED(hr) THEN
         hr = plib.QueryInterface(riid, BYVAL VARPTR(ppv))
      END IF
      plib = NOTHING
   END IF
   FUNCTION = hr

END FUNCTION

'__inline HRESULT SHLoadLibraryFromParsingName(__in PCWSTR pszParsingName, __in DWORD grfMode, __in REFIID riid, __deref_out void **ppv)
'{
'    *ppv = NULL;
'    IShellItem *psiLibrary;
'    HRESULT hr = SHCreateItemFromParsingName(pszParsingName, NULL, IID_PPV_ARGS(&psiLibrary));
'    if (SUCCEEDED(hr))
'    {
'        hr = SHLoadLibraryFromItem(psiLibrary, grfMode, riid, ppv);
'        psiLibrary->Release();
'    }
'    return hr;
'}

' Not a function because SHCreateItemFromParsingName and SHLoadLibraryFromItem
' are not available in Windows prior to Vista.

'FUNCTION SHLoadLibraryFromParsingName (BYVAL pszParsingName AS DWORD, BYVAL grfMode AS DWORD, BYREF riid AS GUID, BYREF ppv AS IUnknown) AS LONG

'   LOCAL hr AS LONG
'   LOCAL psiLibrary AS IShellItem

'   hr = SHCreateItemFromParsingName(pszParsingName, NOTHING, $IID_IShellItem, psiLibrary)
'   IF SUCCEEDED(hr) THEN
'      hr = SHLoadLibraryFromItem(psiLibrary, grfMode, riid, ppv)
'      psiLibrary = NOTHING
'   END IF
'   FUNCTION = hr

'END FUNCTION

MACRO FUNCTION SHLoadLibraryFromParsingName (pszParsingName, grfMode, riid, ppv)

   MACROTEMP hr, psiLibrary
   LOCAL hr AS LONG
   LOCAL psiLibrary AS IShellItem

   hr = SHCreateItemFromParsingName(pszParsingName, NOTHING, $IID_IShellItem, psiLibrary)
   IF SUCCEEDED(hr) THEN
      hr = SHLoadLibraryFromItem(psiLibrary, grfMode, riid, ppv)
      psiLibrary = NOTHING
   END IF

END MACRO = hr

'__inline HRESULT SHAddFolderPathToLibrary(__in IShellLibrary *plib, __in PCWSTR pszFolderPath)
'{
'    IShellItem *psiFolder;
'    HRESULT hr = SHCreateItemFromParsingName(pszFolderPath, NULL, IID_PPV_ARGS(&psiFolder));
'    if (SUCCEEDED(hr))
'    {
'        hr = plib->AddFolder(psiFolder);
'        psiFolder->Release();
'    }
'    return hr;
'}

' Not a function because SHCreateItemFromParsingName is not available in Windows prior to Vista.

'FUNCTION SHAddFolderPathToLibrary (BYVAL plib AS IShellLibrary, BYVAL pszFolderPath AS DWORD) AS LONG

'   LOCAL hr AS LONG
'   LOCAL psiFolder AS IShellItem

'   hr = SHCreateItemFromParsingName(pszFolderPath, NOTHING, $IID_IShellItem, psiFolder)
'   IF SUCCEEDED(hr) THEN
'      hr = plib.AddFolder(psiFolder)
'      psiFolder = NOTHING
'   END IF
'   FUNCTION = hr

'END FUNCTION

MACRO FUNCTION SHAddFolderPathToLibrary (plib, pszFolderPath)

   MACROTEMP hr, psiFolder
   LOCAL hr AS LONG
   LOCAL psiFolder AS IShellItem

   hr = SHCreateItemFromParsingName(pszFolderPath, NOTHING, $IID_IShellItem, psiFolder)
   IF SUCCEEDED(hr) THEN
      hr = plib.AddFolder(psiFolder)
      psiFolder = NOTHING
   END IF

END MACRO = hr

'__inline HRESULT SHRemoveFolderPathFromLibrary(__in IShellLibrary *plib, __in PCWSTR pszFolderPath)
'{
'    PIDLIST_ABSOLUTE pidlFolder = SHSimpleIDListFromPath(pszFolderPath);
'    HRESULT hr = pidlFolder ? S_OK : E_INVALIDARG;
'    if (SUCCEEDED(hr))
'    {
'        IShellItem *psiFolder;
'        hr = SHCreateItemFromIDList(pidlFolder, IID_PPV_ARGS(&psiFolder));
'        if (SUCCEEDED(hr))
'        {
'            hr = plib->RemoveFolder(psiFolder);
'            psiFolder->Release();
'        }
'        CoTaskMemFree(pidlFolder);
'    }
'    return hr;
'}

' Not a function because SHSimpleIDListFromPath and SHCreateItemFromIDList
' are not available in Windows prior to Vista.

'FUNCTION SHRemoveFolderPathFromLibrary (BYVAL plib AS IShellLibrary, BYVAL pszFolderPath AS DWORD) AS LONG

'   LOCAL hr AS LONG
'   LOCAL pidlFolder AS DWORD
'   LOCAL psiFolder AS IShellItem

'   pidlFolder = SHSimpleIDListFromPath(pszFolderPath)
'   hr = IIF&(pidlFolder <> $NULL, %S_OK, %E_INVALIDARG)
'   IF SUCCEEDED(hr) THEN
'      psiFolder = SHCreateItemFromIDList(pidlFolder, $IID_IShellItem, psiFolder)
'      IF SUCCEEDED(hr) THEN
'         hr = plib.RemoveFolder(psiFolder)
'         psiFolder = NOTHING
'      END IF
'      CoTaskMemFree(pidlFolder)
'   END IF
'   FUNCTION = hr

'END FUNCTION

MACRO FUNCTION SHRemoveFolderPathFromLibrary (plib, pszFolderPath)

   MACROTEMP hr, pidlFolder, psiFolder
   LOCAL hr AS LONG
   LOCAL pidlFolder AS DWORD
   LOCAL psiFolder AS IShellItem

   pidlFolder = SHSimpleIDListFromPath(pszFolderPath)
   hr = IIF&(pidlFolder <> $NULL, %S_OK, %E_INVALIDARG)
   IF SUCCEEDED(hr) THEN
      psiFolder = SHCreateItemFromIDList(pidlFolder, $IID_IShellItem, psiFolder)
      IF SUCCEEDED(hr) THEN
         hr = plib.RemoveFolder(psiFolder)
         psiFolder = NOTHING
      END IF
      CoTaskMemFree(BYVAL pidlFolder)
   END IF

END MACRO = hr

'__inline HRESULT SHResolveFolderPathInLibrary(__in IShellLibrary *plib, __in PCWSTR pszFolderPath, __in DWORD dwTimeout, __deref_out PWSTR *ppszResolvedPath)
'{
'    *ppszResolvedPath = NULL;
'    PIDLIST_ABSOLUTE pidlFolder = SHSimpleIDListFromPath(pszFolderPath);
'    HRESULT hr = pidlFolder ? S_OK : E_INVALIDARG;
'    if (SUCCEEDED(hr))
'    {
'        IShellItem *psiFolder;
'        hr = SHCreateItemFromIDList(pidlFolder, IID_PPV_ARGS(&psiFolder));
'        if (SUCCEEDED(hr))
'        {
'            IShellItem *psiResolved;
'            hr = plib->ResolveFolder(psiFolder, dwTimeout, IID_PPV_ARGS(&psiResolved));
'            if (SUCCEEDED(hr))
'            {
'                hr = psiResolved->GetDisplayName(SIGDN_DESKTOPABSOLUTEPARSING, ppszResolvedPath);
'                psiResolved->Release();
'            }
'            psiFolder->Release();
'        }
'        CoTaskMemFree(pidlFolder);
'    }
'    return hr;
'}

' Not a function because SHSimpleIDListFromPath and SHCreateItemFromIDList
' are not available in Windows prior to Vista.

'FUNCTION SHResolveFolderPathInLibrary (BYVAL plib AS IShellLibrary, BYVAL pszFolderPath AS DWORD, BYVAL dwTimeout AS DWORD, BYREF ppszResolvedPath AS DWORD) AS LONG

'   LOCAL hr AS LONG
'   LOCAL psiFolder AS IShellItem
'   LOCAL psiResolved AS IShellItem

'   pidlFolder = SHSimpleIDListFromPath(pszFolderPath)
'   hr = IIF&(pidlFolder <> $NULL, %S_OK, %E_INVALIDARG)
'   IF SUCCEEDED(hr) THEN
'      hr = SHCreateItemFromIDList(pidlFolder, $IID_IShellItem, psiFolder)
'      IF SUCCEEDED(hr) THEN
'         hr = plib.ResolveFolder(psiFolder, dwTimeout, %IID_IShellItem, psiResolved)
'         IF SUCCEEDED(hr) THEN
'            hr = psiResolved.GetDisplayName(%SIGDN_DESKTOPABSOLUTEPARSING, ppszResolvedPath)
'            psiResolved = NOTHING
'         END IF
'         psiFolder = NOTHING
'      END IF
'      CoTaskMemFree(pidlFolder)
'   END IF
'   FUNCTION = hr

'END FUNCTION

MACRO FUNCTION SHResolveFolderPathInLibrary (plib, pszFolderPath, dwTimeout, ppszResolvedPath)

   MACROTEMP hr, psiFolder, psiResolved
   LOCAL hr AS LONG
   LOCAL psiFolder AS IShellItem
   LOCAL psiResolved AS IShellItem

   pidlFolder = SHSimpleIDListFromPath(pszFolderPath)
   hr = IIF&(pidlFolder <> $NULL, %S_OK, %E_INVALIDARG)
   IF SUCCEEDED(hr) THEN
      hr = SHCreateItemFromIDList(pidlFolder, $IID_IShellItem, psiFolder)
      IF SUCCEEDED(hr) THEN
         hr = plib.ResolveFolder(psiFolder, dwTimeout, %IID_IShellItem, psiResolved)
         IF SUCCEEDED(hr) THEN
            hr = psiResolved.GetDisplayName(%SIGDN_DESKTOPABSOLUTEPARSING, ppszResolvedPath)
            psiResolved = NOTHING
         END IF
         psiFolder = NOTHING
      END IF
      CoTaskMemFree(BYVAL pidlFolder)
   END IF

END MACRO = hr

'__inline HRESULT SHSaveLibraryInFolderPath(__in IShellLibrary *plib, __in PCWSTR pszFolderPath, __in PCWSTR pszLibraryName, __in LIBRARYSAVEFLAGS lsf, __deref_opt_out PWSTR *ppszSavedToPath)
'{
'    if (ppszSavedToPath)
'    {
'        *ppszSavedToPath = NULL;
'    }

'    IShellItem *psiFolder;
'    HRESULT hr = SHCreateItemFromParsingName(pszFolderPath, NULL, IID_PPV_ARGS(&psiFolder));
'    if (SUCCEEDED(hr))
'    {
'        IShellItem *psiSavedTo;
'        hr = plib->Save(psiFolder, pszLibraryName, lsf, &psiSavedTo);
'        if (SUCCEEDED(hr))
'        {
'            if (ppszSavedToPath)
'            {
'                hr = psiSavedTo->GetDisplayName(SIGDN_DESKTOPABSOLUTEPARSING, ppszSavedToPath);
'            }
'            psiSavedTo->Release();
'        }
'        psiFolder->Release();
'    }
'    return hr;
'}

' Not a function because SHCreateItemFromParsingName is not available in Windows prior to Vista.

'FUNCTION SHSaveLibraryInFolderPath (BYVAL plib AS IShellLibrary, BYVAL pszFolderPath AS DWORD, BYVAL pszLibraryName AS DWORD, BYVAL lsf AS DWORD, BYREF ppszSavedToPath AS DWORD) AS LONG

'   LOCAL hr AS LONG
'   LOCAL psiFolder AS IShellItem
'   LOCAL psiSavedTo AS IShellItem

'   IF ppszSavedToPath THEN
'      ppszSavedToPath = %NULL
'   END IF

'   hr = SHCreateItemFromParsingName(pszFolderPath, NOTHING, $IID_IShellItem, psiFolder)
'   IF SUCCEEDED(hr) THEN
'      hr = plib.Save(psiFolder, pszLibraryName, lsf, psiSavedTo)
'      IF SUCCEEDED(hr) THEN
'         IF ppszSavedToPath THEN
'            hr = psiSavedTo.GetDisplayName(%SIGDN_DESKTOPABSOLUTEPARSING, ppszSavedToPath)
'         END IF
'         psiSavedTo = NOTHING
'      END IF
'      psiFolder = NOTHING
'   END IF
'   FUNCTION = hr

'END FUNCTION


MACRO FUNCTION SHSaveLibraryInFolderPath (plib, pszFolderPath, pszLibraryName, lsf, ppszSavedToPath)

   MACROTEMP hr, psiFolder, psiSavedTo
   LOCAL hr AS LONG
   LOCAL psiFolder AS IShellItem
   LOCAL psiSavedTo AS IShellItem

   IF ppszSavedToPath THEN
      ppszSavedToPath = %NULL
   END IF

   hr = SHCreateItemFromParsingName(pszFolderPath, NOTHING, $IID_IShellItem, psiFolder)
   IF SUCCEEDED(hr) THEN
      hr = plib.Save(psiFolder, pszLibraryName, lsf, psiSavedTo)
      IF SUCCEEDED(hr) THEN
         IF ppszSavedToPath THEN
            hr = psiSavedTo.GetDisplayName(%SIGDN_DESKTOPABSOLUTEPARSING, ppszSavedToPath)
         END IF
         psiSavedTo = NOTHING
      END IF
      psiFolder = NOTHING
   END IF

END MACRO = hr

'#endif  // __cplusplus
'#endif  // _WIN32_IE >= _WIN32_IE_IE70
'#endif  // NTDDI_WIN7

'#if (NTDDI_VERSION >= NTDDI_VISTA)

' ########################################################################################
' IAssocHandlerInvoker interface
' IID = 92218CAB-ECAA-4335-8133-807FD234C2EE
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IAssocHandlerInvoker_INTERFACE_DEFINED)
    %IAssocHandlerInvoker_INTERFACE_DEFINED = 1

$IID_IAssocHandlerInvoker = GUID$("{92218CAB-ECAA-4335-8133-807FD234C2EE}")

INTERFACE IAssocHandlerInvoker $IID_IAssocHandlerInvoker

   INHERIT IUnknown

   ' =====================================================================================
   METHOD SupportsSelection ( _                         ' VTable offset = 12
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Invoke ( _                                    ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAssocHandlerInvoker_INTERFACE_DEFINED__ */


' ########################################################################################
' IAssocHandler interface
' IID = F04061AC-1659-4A3F-A954-775AA57FC083
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IAssocHandler_INTERFACE_DEFINED)
    %IAssocHandler_INTERFACE_DEFINED = 1

$IID_IAssocHandler = GUID$("{F04061AC-1659-4A3F-A954-775AA57FC083}")

INTERFACE IAssocHandler $IID_IAssocHandler

   INHERIT IUnknown

   ' =====================================================================================
   METHOD GetName ( _                                   ' VTable offset = 12
     BYREF ppsz AS DWORD _                              ' __out LPWSTR *ppsz
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetUIName ( _                                 ' VTable offset = 16
     BYREF ppsz AS DWORD _                              ' __out LPWSTR *ppsz
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD GetIconLocation ( _                           ' VTable offset = 20
     BYREF ppszPath AS DWORD _                          ' __out LPWSTR *ppszPath
   , BYREF pIndex AS LONG _                             ' __out int *pIndex
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD IsRecommended ( _                             ' VTable offset = 24
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD MakeDefault ( _                               ' VTable offset = 28
     BYREF pszDescription AS WSTRINGZ _                 ' __in LPCWSTR pszDescription
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD Invoke ( _                                    ' VTable offset = 32
     BYVAL pdo AS IDataObject _                         ' __in IDataObject *pdo
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================
   METHOD CreateInvoker ( _                             ' VTable offset = 36
     BYVAL pdo AS IDataObject _                         ' __in IDataObject *pdo
   , BYREF ppInvoker AS IAssocHandlerInvoker _          ' __out IAssocHandlerInvoker **ppInvoker
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IAssocHandler_INTERFACE_DEFINED__ */


' ########################################################################################
' IEnumAssocHandlers interface
' IID = 973810AE-9599-4B88-9E4D-6EE98C9552DA
' Inherited interface = IUnknown
' ########################################################################################

#IF NOT %DEF(%IEnumAssocHandlers_INTERFACE_DEFINED)
    %IEnumAssocHandlers_INTERFACE_DEFINED = 1

$IID_IEnumAssocHandlers = GUID$("{973810AE-9599-4B88-9E4D-6EE98C9552DA}")

INTERFACE IEnumAssocHandlers $IID_IEnumAssocHandlers

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Next ( _                                      ' VTable offset = 12
     BYVAL celt AS DWORD _                              ' __in ULONG celt
   , BYREF rgelt AS IAssocHandler _                     ' __out IAssocHandler **rgelt
   , BYREF pceltFetched AS DWORD _                      ' __out ULONG *pceltFetched
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __IEnumAssocHandlers_INTERFACE_DEFINED__ */

' enum tagASSOC_FILTER
%ASSOC_FILTER_NONE        = 0
%ASSOC_FILTER_RECOMMENDED = &H1
'typedef int ASSOC_FILTER;

DECLARE FUNCTION SHAssocEnumHandlers IMPORT "SHELL32.DLL" ALIAS "SHAssocEnumHandlers" ( _
   BYREF pszExtra AS WSTRINGZ _                         ' __in LPCWSTR pszExtra
 , BYVAL afFilter AS LONG _                             ' __in ASSOC_FILTER afFilter
 , BYREF ppEnumHandler AS IEnumAssocHandlers _          ' __out IEnumAssocHandlers **ppEnumHandler
 ) AS LONG                                              ' HRESULT

'#endif  // NTDDI_VISTA

'#if (NTDDI_VERSION >= NTDDI_WIN7)
DECLARE FUNCTION SHAssocEnumHandlersForProtocolByApplication IMPORT "SHELL32.DLL" ALIAS "SHAssocEnumHandlersForProtocolByApplication" ( _
   BYREF protocol AS WSTRINGZ _                         ' __in PCWSTR protocol
 , BYREF riid AS GUID _                                 ' __in REFIID riid
 , BYREF enumHandlers AS IUnknown _                     ' __out void **enumHandlers
 ) AS LONG                                              ' HRESULT
'#endif  // NTDDI_WIN7


' ########################################################################################
' ########################################################################################
' The following interfaces, taken from the XP SDK, have been removed from the Vista SDK.
' ########################################################################################
' ########################################################################################

' Removed from the Vista SDK
%SNCF_REFRESHLIST = &H00000001  ' // refresh the list (eg. from F5 or opening a folder)

' ########################################################################################
' INetCrawler interface
' IID = 49C929EE-A1B7-4C58-B539-E63BE392B6F3
' Inherited interface = IUnknown
' Removed from the Vista SDK.
' ########################################################################################

#IF NOT %DEF(%INetCrawler_INTERFACE_DEFINED)
    %INetCrawler_INTERFACE_DEFINED = 1

$IID_INetCrawler = GUID$("{49C929EE-A1B7-4C58-B539-E63BE392B6F3}")

INTERFACE INetCrawler $IID_INetCrawler

   INHERIT IUnknown

   ' =====================================================================================
   METHOD Update ( _                                    ' VTable offset = 12
     BYVAL dwFlags AS DWORD _                           ' __in DWORD dwFlags
   ) AS LONG                                            ' HRESULT
   ' =====================================================================================

END INTERFACE

#ENDIF   ' /* __INetCrawler_INTERFACE_DEFINED__ */


' ########################################################################################
' IUserEventTimerCallback interface
' IID = E9EAD8E6-2A25-410E-9B58-A9FBEF1DD1A2
' Inherited interface = Iunknown
' Removed in the Vista SDK.
' ########################################################################################

'#IF NOT %DEF(%IUserEventTimerCallback_INTERFACE_DEFINED)
'    %IUserEventTimerCallback_INTERFACE_DEFINED = 1

'$IID_IUserEventTimerCallback = GUID$("{E9EAD8E6-2A25-410E-9B58-A9FBEF1DD1A2}")

'INTERFACE IUserEventTimerCallback $IID_IUserEventTimerCallback

'   INHERIT IUnknown

'   ' =====================================================================================
'   METHOD UserEventTimerProc ( _                        ' VTable offset = 12
'     BYVAL uUserEventTimerID AS DWORD _                 ' __in ULONG uUserEventTimerID
'   , BYVAL uTimerElapse AS DWORD _                      ' __in UINT uTimerElapse
'   ) AS LONG                                            ' HRESULT
'   ' =====================================================================================

'END INTERFACE

'#ENDIF   ' /* __IUserEventTimerCallback_INTERFACE_DEFINED__ */


' ########################################################################################
' IUserEventTimer interface
' IID = "0F504B94-6E42-42E6-99E0-E20FAFE52AB4
' Inherited interface = Iunknown
' Removed in the Vista SDK.
' ########################################################################################

'#IF NOT %DEF(%IUserEventTimer_INTERFACE_DEFINED)
'    %IUserEventTimer_INTERFACE_DEFINED = 1

'$IID_IUserEventTimer = GUID$("{0F504B94-6E42-42E6-99E0-E20FAFE52AB4}")

'INTERFACE IID_IUserEventTimer $IID_IUserEventTimer

'   INHERIT IUnknown

'   ' =====================================================================================
'   METHOD SetUserEventTimer ( _                         ' VTable offset = 12
'     BYVAL hWnd AS DWORD _                              ' __in HWND hWnd
'   , BYVAL uCallbackMessage AS DWORD _                  ' __in UINT uCallbackMessage
'   , BYVAL uTimerElapse AS DWORD _                      ' __in UINT uTimerElapse
'   , BYVAL pUserEventTimerCallback AS IUserEventTimerCallback _ ' __in IUserEventTimerCallback *pUserEventTimerCallback
'   , BYREF puUserEventTimerID AS DWORD _                ' __inout ULONG *puUserEventTimerID
'   ) AS LONG                                            ' HRESULT
'   ' =====================================================================================
'   METHOD KillUserEventTimer ( _                        ' VTable offset = 16
'     BYVAL hWnd AS DWORD _                              ' __in HWND hWnd
'   , BYVAL uUserEventTimerID AS DWORD _                 ' __in ULONG uUserEventTimerID
'   ) AS LONG                                            ' HRESULT
'   ' =====================================================================================
'   METHOD GetUserEventTimerElapsed ( _                  ' VTable offset = 20
'     BYVAL hWnd AS DWORD _                              ' __in HWND hWnd
'   , BYVAL uUserEventTimerID AS DWORD _                 ' __in ULONG uUserEventTimerID
'   , BYREF puTimerElapsed AS DWORD _                    ' __out UINT *puTimerElapsed
'   ) AS LONG                                            ' HRESULT
'   ' =====================================================================================
'   METHOD InitTimerTickInterval ( _                     ' VTable offset = 24
'     BYVAL uTimerTickIntervalMs AS DWORD _              ' __in UINT uTimerTickIntervalMs
'   ) AS LONG                                            ' HRESULT
'   ' =====================================================================================

'END INTERFACE

'#ENDIF   ' /* __IUserEventTimer_INTERFACE_DEFINED__ */


' ########################################################################################
' IPassportWizard interface
' IID = A09DB586-9180-41AC-9114-460A7F362B76
' Inherited interface = IModalWindow
' Removed in the Vista SDK.
' ########################################################################################

'%PPW_LAUNCHEDBYUSER = &H00000001???     ' // The wizard was launch explicitly by the user, not on demand by the key manager

'#IF NOT %DEF(%IPassportWizard_INTERFACE_DEFINED)
'    %IPassportWizard_INTERFACE_DEFINED = 1

'$IID_IPassportWizard = GUID$("{A09DB586-9180-41AC-9114-460A7F362B76}")

'INTERFACE IPassportWizard $IID_IPassportWizard

'   INHERIT IUnknown

'   ' =====================================================================================
'   METHOD Show ( _                                      ' VTable offset = 12
'     BYVAL hwndParent AS DWORD _                        ' __in HWND hwndParent
'   ) AS LONG                                            ' HRESULT
'   ' =====================================================================================
'   METHOD SetOptions ( _                                ' VTable offset = 16
'     BYVAL dwOptions AS DWORD _                         ' __in DWORD dwOptions
'   ) AS LONG                                            ' HRESULT
'   ' =====================================================================================

'END INTERFACE

'#ENDIF   ' /* __IPassportWizard_INTERFACE_DEFINED__ */


'typedef void ( *PFDVENUMREADYBALLBACK )(
'    LPVOID pvData);

' ########################################################################################
' IDVGetEnum interface
' IID = 70F55181-5FEA-4900-B6B8-7343CB0A348C
' Inherited interface = IUnknown
' Removed in the Vista SDK.
' ########################################################################################

'#IF NOT %DEF(%IDVGetEnum_INTERFACE_DEFINED)
'    %IDVGetEnum_INTERFACE_DEFINED = 1

'$IID_IDVGetEnum = GUID$("{70F55181-5FEA-4900-B6B8-7343CB0A348C}")

'INTERFACE IDVGetEnum $IID_IDVGetEnum

'   INHERIT IUnknown

'   ' =====================================================================================
'   METHOD SetEnumReadyCallback ( _                      ' VTable offset = 12
'     BYVAL pfn AS DWORD _                               ' __in PFDVENUMREADYBALLBACK pfn
'   , BYVAL pvData AS DWORD _                            ' __in LPVOID pvData
'   ) AS LONG                                            ' HRESULT
'   ' =====================================================================================
'   METHOD CreateEnumIDListFromContents ( _              ' VTable offset = 16
'     BYVAL pidlFolder AS DWORD _                        ' __in LPCITEMIDLIST pidlFolder
'   , BYVAL dwEnumFlags AS DWORD _                       ' __in DWORD dwEnumFlags
'   , BYREF ppEnumIDList AS IEnumIDList _                ' __out IEnumIDList **ppEnumIDList
'   ) AS LONG                                            ' HRESULT
'   ' =====================================================================================

'END INTERFACE

'#ENDIF   ' /* __IDVGetEnum_INTERFACE_DEFINED__ */

' ########################################################################################
' IDefViewSafety interface
' IID = 9A93B3FB-4E75-4C74-871A-2CDA667F39A5
' Inherited interface = IUnknown
' Removed in the Vista SDK.
' ########################################################################################

'#IF NOT %DEF(%IDefViewSafety_INTERFACE_DEFINED)
'    %IDefViewSafety_INTERFACE_DEFINED = 1

'$IID_IDefViewSafety = GUID$("{9A93B3FB-4E75-4C74-871A-2CDA667F39A5}")

'INTERFACE IDefViewSafety $IID_IDefViewSafety

'   INHERIT IUnknown

'   ' =====================================================================================
'   METHOD IsSafePage ( _                                ' VTable offset = 12
'   ) AS LONG                                            ' HRESULT
'   ' =====================================================================================

'END INTERFACE

'#ENDIF   ' /* __IDefViewSafety_INTERFACE_DEFINED__ */
