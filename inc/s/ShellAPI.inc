' ########################################################################################
' Microsoft Windows
' File: ShellApi.inc
' Contents: SHELL.DLL functions, types, and definitions
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%SHELLAPI_INC = 1

#INCLUDE ONCE "windows.inc"

'#if !defined(_WIN64)
'#include <pshpack1.h>
'#endif

'DECLARE_HANDLE(HDROP);

DECLARE FUNCTION DragQueryFileA IMPORT "SHELL32.DLL" ALIAS "DragQueryFileA" ( _
   BYVAL hDrop AS DWORD _                               ' __in HDROP hDrop
 , BYVAL uiFile AS DWORD _                              ' __in UINT uiFile
 , BYREF lpszFile AS ASCIIZ _                           ' __out LPSTR lpszFile
 , BYVAL cch AS DWORD _                                 ' __in UINT cch
 ) AS DWORD                                             ' UINT

DECLARE FUNCTION DragQueryFileW IMPORT "SHELL32.DLL" ALIAS "DragQueryFileW" ( _
   BYVAL hDrop AS DWORD _                               ' __in HDROP hDrop
 , BYVAL uiFile AS DWORD _                              ' __in UINT uiFile
 , BYREF lpszFile AS WSTRINGZ _                         ' __out LPWSTR lpszFile
 , BYVAL cch AS DWORD _                                 ' __in UINT cch
 ) AS DWORD                                             ' UINT

#IF %DEF(%UNICODE)
   MACRO DragQueryFile = DragQueryFileW
#ELSE
   MACRO DragQueryFile = DragQueryFileA
#ENDIF

DECLARE FUNCTION DragQueryPoint IMPORT "SHELL32.DLL" ALIAS "DragQueryPoint" ( _
   BYVAL hDrop AS DWORD _                               ' __in HDROP hDrop
 , BYREF lppt AS POINT _                                ' __out LPPOINT lppt
 ) AS LONG                                              ' BOOL

DECLARE SUB DragFinish IMPORT "SHELL32.DLL" ALIAS "DragFinish" ( _
   BYVAL hDrop AS DWORD _                               ' __in HDROP hDrop
 )                                                      ' void

DECLARE SUB DragAcceptFiles IMPORT "SHELL32.DLL" ALIAS "DragAcceptFiles" ( _
   BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 , BYVAL fAccept AS LONG _                              ' __in BOOL fAccept
 )                                                      ' void

DECLARE FUNCTION ShellExecuteA IMPORT "SHELL32.DLL" ALIAS "ShellExecuteA" ( _
   BYVAL hWnd AS DWORD _                                ' __in_opt HWND hWnd
 , BYREF lpOperation AS ASCIIZ _                        ' __in_opt LPCSTR lpOperation
 , BYREF lpFile AS ASCIIZ _                             ' __in LPCSTR lpFile
 , BYREF lpParameters AS ASCIIZ _                       ' __in_opt LPCSTR lpParameters
 , BYREF lpDirectory AS ASCIIZ _                        ' __in_opt LPCSTR lpDirectory
 , BYVAL nShowCmd AS LONG _                             ' __in INT nShowCmd
 ) AS DWORD                                             ' HINSTANCE

DECLARE FUNCTION ShellExecuteW IMPORT "SHELL32.DLL" ALIAS "ShellExecuteW" ( _
   BYVAL hWnd AS DWORD _                                ' __in_opt HWND hWnd
 , BYREF lpOperation AS WSTRINGZ _                      ' __in_opt LPCWSTR lpOperation
 , BYREF lpFile AS WSTRINGZ _                           ' __in LPCWSTR lpFile
 , BYREF lpParameters AS WSTRINGZ _                     ' __in_opt LPCWSTR lpParameters
 , BYREF lpDirectory AS WSTRINGZ _                      ' __in LPCWSTR lpDirectory
 , BYVAL nShowCmd AS LONG _                             ' __in INT nShowCmd
 ) AS DWORD                                             ' HINSTANCE

#IF %DEF(%UNICODE)
   MACRO ShellExecute = ShellExecuteW
#ELSE
   MACRO ShellExecute = ShellExecuteA
#ENDIF

DECLARE FUNCTION FindExecutableA IMPORT "SHELL32.DLL" ALIAS "FindExecutableA" ( _
   BYREF lpFile AS ASCIIZ _                             ' __in LPCSTR lpFile
 , BYREF lpDirectory AS ASCIIZ _                        ' __in_opt LPCSTR lpDirectory
 , BYREF lpResult AS ASCIIZ _                           ' __out LPSTR lpResult
 ) AS DWORD                                             ' HINSTANCE

DECLARE FUNCTION FindExecutableW IMPORT "SHELL32.DLL" ALIAS "FindExecutableW" ( _
   BYREF lpFile AS WSTRINGZ _                           ' __in LPCWSTR lpFile
 , BYREF lpDirectory AS WSTRINGZ _                      ' __in_opt LPCWSTR lpDirectory
 , BYREF lpResult AS WSTRINGZ _                         ' __out LPWSTR lpResult
 ) AS DWORD                                             ' HINSTANCE

#IF %DEF(%UNICODE)
   MACRO FindExecutable = FindExecutableW
#ELSE
   MACRO FindExecutable = FindExecutableA
#ENDIF

DECLARE FUNCTION CommandLineToArgvW IMPORT "SHELL32.DLL" ALIAS "CommandLineToArgvW" ( _
   BYREF lpCmdLine AS WSTRINGZ _                        ' __in LPCWSTR lpCmdLine
 , BYREF pNumArgs AS LONG _                             ' __out int *pNumArgs
 ) AS DWORD                                             ' LPWSTR

MACRO CommandLineToArgv = CommandLineToArgvW

DECLARE FUNCTION ShellAboutA IMPORT "SHELL32.DLL" ALIAS "ShellAboutA" ( _
   BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 , BYREF szApp AS ASCIIZ _                              ' __in LPCSTR szApp
 , BYREF szOtherStuff AS ASCIIZ _                       ' __in_opt LPCSTR szOtherStuff
 , OPTIONAL BYVAL hIcon AS DWORD _                      ' __in_opt HICON hIcon
 ) AS LONG                                              ' int

DECLARE FUNCTION ShellAboutW IMPORT "SHELL32.DLL" ALIAS "ShellAboutW" ( _
   BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 , BYREF szApp AS WSTRINGZ _                            ' __in LPCWSTR szApp
 , BYREF szOtherStuff AS WSTRINGZ _                     ' __in_opt LPCWSTR szOtherStuff
 , OPTIONAL BYVAL hIcon AS DWORD _                      ' __in_opt HICON hIcon
 ) AS LONG                                              ' int

#IF %DEF(%UNICODE)
   MACRO ShellAbout = ShellAboutW
#ELSE
   MACRO ShellAbout = ShellAboutA
#ENDIF

DECLARE FUNCTION DuplicateIcon IMPORT "SHELL32.DLL" ALIAS "DuplicateIcon" ( _
   BYVAL hInst AS DWORD _                               ' __in HINSTANCE hInst
 , BYVAL hIcon AS DWORD _                               ' __in HICON hIcon
 ) AS DWORD                                             ' HICON

DECLARE FUNCTION ExtractAssociatedIconA IMPORT "SHELL32.DLL" ALIAS "ExtractAssociatedIconA" ( _
   BYVAL hInst AS DWORD _                               ' __in HINSTANCE hInst
 , BYREF lpIconPath AS ASCIIZ _                         ' __inout LPSTR lpIconPath
 , BYREF lpiIcon AS WORD _                              ' __inout LPWORD lpiIcon
 ) AS DWORD                                             ' HICON

DECLARE FUNCTION ExtractAssociatedIconW IMPORT "SHELL32.DLL" ALIAS "ExtractAssociatedIconW" ( _
   BYVAL hInst AS DWORD _                               ' __in HINSTANCE hInst
 , BYREF lpIconPath AS WSTRINGZ _                       ' __inout LPWSTR lpIconPath
 , BYREF lpiIcon AS WORD _                              ' __inout LPWORD lpiIcon
 ) AS DWORD                                             ' HICON

#IF %DEF(%UNICODE)
   MACRO ExtractAssociatedIcon = ExtractAssociatedIconW
#ELSE
   MACRO ExtractAssociatedIcon = ExtractAssociatedIconA
#ENDIF

DECLARE FUNCTION ExtractAssociatedIconExA IMPORT "SHELL32.DLL" ALIAS "ExtractAssociatedIconExA" ( _
   BYVAL hInst AS DWORD _                               ' __in HINSTANCE hInst
 , BYREF lpIconPath AS ASCIIZ _                         ' __inout LPSTR lpIconPath
 , BYREF lpiIconIndex AS WORD _                         ' __inout LPWORD lpiIconIndex
 , BYREF lpiIconId AS WORD _                            ' __out LPWORD lpiIconId
 ) AS DWORD                                             ' HICON

DECLARE FUNCTION ExtractAssociatedIconExW IMPORT "SHELL32.DLL" ALIAS "ExtractAssociatedIconExW" ( _
   BYVAL hInst AS DWORD _                               ' __in HINSTANCE hInst
 , BYREF lpIconPath AS WSTRINGZ _                       ' __inout LPWSTR lpIconPath
 , BYREF lpiIconIndex AS WORD _                         ' __inout LPWORD lpiIconIndex
 , BYREF lpiIconId AS WORD _                            ' __out LPWORD lpiIconId
 ) AS DWORD                                             ' HICON

#IF %DEF(%UNICODE)
   MACRO ExtractAssociatedIconEx = ExtractAssociatedIconExW
#ELSE
   MACRO ExtractAssociatedIconEx = ExtractAssociatedIconExA
#ENDIF

DECLARE FUNCTION ExtractIconA IMPORT "SHELL32.DLL" ALIAS "ExtractIconA" ( _
   BYVAL hInst AS DWORD _                               ' __in HINSTANCE hInst
 , BYREF lpszExeFileName AS ASCIIZ _                    ' __in LPCSTR lpszExeFileName
 , BYVAL nIconIndex AS DWORD _                          ' __in UINT nIconIndex
 ) AS DWORD                                             ' HICON

DECLARE FUNCTION ExtractIconW IMPORT "SHELL32.DLL" ALIAS "ExtractIconW" ( _
   BYVAL hInst AS DWORD _                               ' __in HINSTANCE hInst
 , BYREF lpszExeFileName AS WSTRINGZ _                  ' __in LPCWSTR lpszExeFileName
 , BYVAL nIconIndex AS DWORD _                          ' __in UINT nIconIndex
 ) AS DWORD                                             ' HICON

#IF %DEF(%UNICODE)
   MACRO ExtractIcon = ExtractIconW
#ELSE
   MACRO ExtractIcon = ExtractIconA
#ENDIF

'#if(WINVER >= 0x0400)
' // Size = 24 bytes
TYPE DRAGINFOA BYTE
   uSize       AS DWORD        ' UINT  uSize /* init with sizeof(DRAGINFO) */
   pt          AS POINT        ' POINT pt
   fNC         AS LONG         ' BOOL  fNC
   lpFileList  AS ASCIIZ PTR   ' LPSTR lpFileList
   grfKeyState AS DWORD        ' DWORD grfKeyState
END TYPE

' // Size = 24 bytes
TYPE DRAGINFOW BYTE
   uSize       AS DWORD          ' UINT   uSize /* init with sizeof(DRAGINFO) */
   pt          AS POINT          ' POINT  pt
   fNC         AS LONG           ' BOOL   fNC
   lpFileList  AS WSTRINGZ PTR   ' LPWSTR lpFileList
   grfKeyState AS DWORD          ' DWORD  grfKeyState
END TYPE

#IF %DEF(%UNICODE)
   MACRO DRAGINFO = DRAGINFOW
#ELSE
   MACRO DRAGINFO = DRAGINFOA
#ENDIF

'////
'//// AppBar stuff
'////
%ABM_NEW              = &H00000000???
%ABM_REMOVE           = &H00000001???
%ABM_QUERYPOS         = &H00000002???
%ABM_SETPOS           = &H00000003???
%ABM_GETSTATE         = &H00000004???
%ABM_GETTASKBARPOS    = &H00000005???
%ABM_ACTIVATE         = &H00000006???  ' // lParam == TRUE/FALSE means activate/deactivate
%ABM_GETAUTOHIDEBAR   = &H00000007???
%ABM_SETAUTOHIDEBAR   = &H00000008???  ' // this can fail at any time.  MUST check the result
                                    ' // lParam = TRUE/FALSE  Set/Unset
                                    ' // uEdge = what edge
%ABM_WINDOWPOSCHANGED = &H00000009???
'#if (NTDDI_VERSION >= NTDDI_WINXP)
%ABM_SETSTATE         = &H0000000A???
'#endif // (NTDDI_VERSION >= NTDDI_WINXP)

'// these are put in the wparam of callback messages
%ABN_STATECHANGE      = &H00000000???
%ABN_POSCHANGED       = &H00000001???
%ABN_FULLSCREENAPP    = &H00000002???
%ABN_WINDOWARRANGE    = &H00000003???  ' // lParam == TRUE means hide

'// flags for get state
%ABS_AUTOHIDE         = &H00000001???
%ABS_ALWAYSONTOP      = &H00000002???

%ABE_LEFT       = 0
%ABE_TOP        = 1
%ABE_RIGHT      = 2
%ABE_BOTTOM     = 3

' // Size = 36 bytes
TYPE APPBARDATA BYTE
   cbSize           AS DWORD
   hWnd             AS DWORD
   uCallbackMessage AS DWORD
   uEdge            AS DWORD
   rc               AS RECT
   lParam           AS LONG    ' // message specific
END TYPE


DECLARE FUNCTION SHAppBarMessage IMPORT "SHELL32.DLL" ALIAS "SHAppBarMessage" ( _
   BYVAL dwMessage AS DWORD _                           ' __in DWORD dwMessage
 , BYREF pData AS APPBARDATA _                          ' __inout PAPPBARDATA pData
 ) AS DWORD                                             ' UINT_PTR

'////
'////  EndAppBar
'////

DECLARE FUNCTION DoEnvironmentSubstA IMPORT "SHELL32.DLL" ALIAS "DoEnvironmentSubstA" ( _
   BYREF pszString AS ASCIIZ _                          ' __in LPSTR pszString
 , BYVAL cchString AS DWORD _                           ' __in UINT cchString
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION DoEnvironmentSubstW IMPORT "SHELL32.DLL" ALIAS "DoEnvironmentSubstW" ( _
   BYREF pszString AS WSTRINGZ _                        ' __in LPWSTR pszString
 , BYVAL cchString AS DWORD _                           ' __in UINT cchString
 ) AS DWORD                                             ' DWORD

#IF %DEF(%UNICODE)
   MACRO DoEnvironmentSubst = DoEnvironmentSubstW
#ELSE
   MACRO DoEnvironmentSubst = DoEnvironmentSubstA
#ENDIF

'#define EIRESID(x) (-1 * (int)(x))
MACRO EIRESID(x) = (-1 * CLNG(x))

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION ExtractIconExA LIB "Shell32.dll" ALIAS "ExtractIconExA" ( _
    lpszFile AS ASCIIZ, BYVAL nIconIndex AS LONG, _
    BYVAL phiconLarge AS DWORD PTR, BYVAL phiconSmall AS DWORD PTR, _
    BYVAL nIcons AS DWORD) AS DWORD
#ELSE
DECLARE FUNCTION ExtractIconExA IMPORT "SHELL32.DLL" ALIAS "ExtractIconExA" ( _
   BYREF lpszFile AS ASCIIZ _                           ' __in LPCSTR lpszFile
 , BYVAL nIconIndex AS LONG _                           ' __in int nIconIndex
 , BYREF phiconLarge AS DWORD _                         ' __out HICON *phiconLarge
 , BYREF phiconSmall AS DWORD _                         ' __out HICON *phiconSmall
 , BYVAL nIcons AS DWORD _                              ' __in UINT nIcons
 ) AS DWORD                                             ' UINT
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION ExtractIconExW LIB "Shell32.dll" ALIAS "ExtractIconExW" ( _
    lpszFile AS WSTRINGZ, BYVAL nIconIndex AS LONG, _
    BYVAL phiconLarge AS DWORD PTR, BYVAL phiconSmall AS DWORD PTR, _
    BYVAL nIcons AS DWORD) AS DWORD
#ELSE
DECLARE FUNCTION ExtractIconExW IMPORT "SHELL32.DLL" ALIAS "ExtractIconExW" ( _
   BYREF lpszFile AS WSTRINGZ _                         ' __in LPCWSTR lpszFile
 , BYVAL nIconIndex AS LONG _                           ' __in int nIconIndex
 , BYREF phiconLarge AS DWORD _                         ' __out HICON *phiconLarge
 , BYREF phiconSmall AS DWORD _                         ' __out HICON *phiconSmall
 , BYVAL nIcons AS DWORD _                              ' __in UINT nIcons
 ) AS DWORD                                             ' UINT
#ENDIF

#IF %DEF(%UNICODE)
   MACRO ExtractIconEx = ExtractIconExW
#ELSE
   MACRO ExtractIconEx = ExtractIconExA
#ENDIF

'////
'//// Shell File Operations
'////
#IF NOT %DEF(%FO_MOVE)   ' //these need to be kept in sync with the ones in shlobj.h

%FO_MOVE                    = &H0001???
%FO_COPY                    = &H0002???
%FO_DELETE                  = &H0003???
%FO_RENAME                  = &H0004???

%FOF_MULTIDESTFILES         = &H0001???
%FOF_CONFIRMMOUSE           = &H0002???
%FOF_SILENT                 = &H0004???  ' // don't create progress/report
%FOF_RENAMEONCOLLISION      = &H0008???
%FOF_NOCONFIRMATION         = &H0010???  ' // Don't prompt the user.
%FOF_WANTMAPPINGHANDLE      = &H0020???  ' // Fill in SHFILEOPSTRUCT.hNameMappings
                                         ' // Must be freed using SHFreeNameMappings
%FOF_ALLOWUNDO              = &H0040???
%FOF_FILESONLY              = &H0080???  ' // on *.*, do only files
%FOF_SIMPLEPROGRESS         = &H0100???  ' // means don't show names of files
%FOF_NOCONFIRMMKDIR         = &H0200???  ' // don't confirm making any needed dirs
%FOF_NOERRORUI              = &H0400???  ' // don't put up error UI
%FOF_NOCOPYSECURITYATTRIBS  = &H0800???  ' // dont copy NT file Security Attributes
%FOF_NORECURSION            = &H1000???  ' // don't recurse into directories.
'#if (_WIN32_IE >= &H0500)
%FOF_NO_CONNECTED_ELEMENTS  = &H2000???  ' // don't operate on connected elements.
%FOF_WANTNUKEWARNING        = &H4000???  ' // during delete operation, warn if nuking instead of recycling (partially overrides FOF_NOCONFIRMATION)
'#endif ' // (_WIN32_IE >= &H500)
'#if (_WIN32_WINNT >= &H0501)
%FOF_NORECURSEREPARSE       = &H8000???  ' // treat reparse points as objects, not containers
'#endif ' // (_WIN32_WINNT >= &H501)
%FOF_NO_UI                  = %FOF_SILENT OR %FOF_NOCONFIRMATION OR %FOF_NOERRORUI OR %FOF_NOCONFIRMMKDIR  ' // don't display any UI at all

'typedef WORD FILEOP_FLAGS;

%PO_DELETE       = &H0013??  ' // printer is being deleted
%PO_RENAME       = &H0014??  ' // printer is being renamed
%PO_PORTCHANGE   = &H0020??  ' // port this printer connected to is being changed
                             ' // if this id is set, the strings received by
                             ' // the copyhook are a doubly-null terminated
                             ' // list of strings.  The first is the printer
                             ' // name and the second is the printer port.
%PO_REN_PORT     = &H0034??  ' // PO_RENAME and PO_PORTCHANGE at same time.

'// no POF_ flags currently defined

'typedef WORD PRINTEROP_FLAGS;

#ENDIF   ' // FO_MOVE

'// implicit parameters are:
'//      if pFrom or pTo are unqualified names the current directories are
'//      taken from the global current drive/directory settings managed
'//      by Get/SetCurrentDrive/Directory
'//
'//      the global confirmation settings

' // Size = 30 bytes
TYPE SHFILEOPSTRUCTA BYTE   ' Must not be DWORD aligned
   hwnd                  AS DWORD        ' HWND            hwnd
   wFunc                 AS DWORD        ' UINT            wFunc
   pFrom                 AS ASCIIZ PTR   ' LPCSTR          pFrom
   pTo                   AS ASCIIZ PTR   ' LPCSTR          pTo
   fFlags                AS WORD         ' FILEOP_FLAGS    fFlags
   fAnyOperationsAborted AS LONG         ' BOOL            fAnyOperationsAborted
   hNameMappings         AS DWORD        ' LPVOID          hNameMappings
   lpszProgressTitle     AS ASCIIZ PTR   ' LPCSTR          lpszProgressTitle // only used if FOF_SIMPLEPROGRESS
END TYPE

' // Size = 30 bytes
TYPE SHFILEOPSTRUCTW BYTE  ' Must not be DWORD aligned
   hwnd                  AS DWORD          ' HWND            hwnd
   wFunc                 AS DWORD          ' UINT            wFunc
   pFrom                 AS WSTRINGZ PTR   ' LPCWSTR         pFrom
   pTo                   AS WSTRINGZ PTR   ' LPCWSTR         pTo
   fFlags                AS WORD           ' FILEOP_FLAGS    fFlags
   fAnyOperationsAborted AS LONG           ' BOOL            fAnyOperationsAborted
   hNameMappings         AS DWORD          ' LPVOID          hNameMappings
   lpszProgressTitle     AS WSTRINGZ PTR   ' LPCWSTR         lpszProgressTitle // only used if FOF_SIMPLEPROGRESS
END TYPE

#IF %DEF(%UNICODE)
   MACRO SHFILEOPSTRUCT = SHFILEOPSTRUCTW
#ELSE
   MACRO SHFILEOPSTRUCT = SHFILEOPSTRUCTA
#ENDIF

DECLARE FUNCTION SHFileOperationA IMPORT "SHELL32.DLL" ALIAS "SHFileOperationA" ( _
   BYREF lpFileOp AS SHFILEOPSTRUCTA _                  ' __in LPSHFILEOPSTRUCT lpFileOp
 ) AS LONG                                              ' int

DECLARE FUNCTION SHFileOperationW IMPORT "SHELL32.DLL" ALIAS "SHFileOperationW" ( _
   BYREF lpFileOp AS SHFILEOPSTRUCTW _                  ' __in LPSHFILEOPSTRUCTW lpFileOp
 ) AS LONG                                              ' int

#IF %DEF(%UNICODE)
   MACRO SHFileOperation = SHFileOperationW
#ELSE
   MACRO SHFileOperation = SHFileOperationA
#ENDIF

DECLARE SUB SHFreeNameMappings IMPORT "SHELL32.DLL" ALIAS "SHFreeNameMappings" ( _
   BYVAL hNameMappings AS DWORD _                       ' HANDLE hNameMappings
 )                                                      ' void

' // Size = 16 bytes
TYPE SHNAMEMAPPINGA BYTE
   pszOldPath AS ASCIIZ PTR   ' LPSTR   pszOldPath
   pszNewPath AS ASCIIZ PTR   ' LPSTR   pszNewPath
   cchOldPath AS LONG         ' int     cchOldPath
   cchNewPath AS LONG         ' int     cchNewPath
END TYPE

' // Size = 16 bytes
TYPE SHNAMEMAPPINGW BYTE
   pszOldPath AS WSTRINGZ PTR   ' LPWSTR  pszOldPath
   pszNewPath AS WSTRINGZ PTR   ' LPWSTR  pszNewPath
   cchOldPath AS LONG           ' int     cchOldPath
   cchNewPath AS LONG           ' int     cchNewPath
END TYPE

#IF %DEF(%UNICODE)
   MACRO SHNAMEMAPPING = SHNAMEMAPPINGW
#ELSE
   MACRO SHNAMEMAPPING = SHNAMEMAPPINGA
#ENDIF

'////
'//// End Shell File Operations
'////

'////
'////  Begin ShellExecuteEx and family
'////

'/* ShellExecute() and ShellExecuteEx() error codes */

'/* regular WinExec() codes */
%SE_ERR_FNF             = 2      ' // file not found
%SE_ERR_PNF             = 3      ' // path not found
%SE_ERR_ACCESSDENIED    = 5      ' // access denied
%SE_ERR_OOM             = 8      ' // out of memory
%SE_ERR_DLLNOTFOUND     = 32

'#endif /* WINVER >= 0x0400 */

'/* error values for ShellExecute() beyond the regular WinExec() codes */
%SE_ERR_SHARE           = 26
%SE_ERR_ASSOCINCOMPLETE = 27
%SE_ERR_DDETIMEOUT      = 28
%SE_ERR_DDEFAIL         = 29
%SE_ERR_DDEBUSY         = 30
%SE_ERR_NOASSOC         = 31

'#if(WINVER >= 0x0400)

'// Note CLASSKEY overrides CLASSNAME
%SEE_MASK_DEFAULT           = &H00000000???
%SEE_MASK_CLASSNAME         = &H00000001???   ' // SHELLEXECUTEINFO.lpClass is valid
%SEE_MASK_CLASSKEY          = &H00000003???   ' // SHELLEXECUTEINFO.hkeyClass is valid
'// Note SEE_MASK_INVOKEIDLIST(0xC) implies SEE_MASK_IDLIST(0x04)
%SEE_MASK_IDLIST            = &H00000004???   ' // SHELLEXECUTEINFO.lpIDList is valid
%SEE_MASK_INVOKEIDLIST      = &H0000000c???   ' // enable IContextMenu based verbs
'#if (NTDDI_VERSION < NTDDI_VISTA)
%SEE_MASK_ICON              = &H00000010???   ' // not used
'#endif // (NTDDI_VERSION < NTDDI_VISTA)
%SEE_MASK_HOTKEY            = &H00000020???   ' // SHELLEXECUTEINFO.dwHotKey is valid
%SEE_MASK_NOCLOSEPROCESS    = &H00000040???   ' // SHELLEXECUTEINFO.hProcess
%SEE_MASK_CONNECTNETDRV     = &H00000080???   ' // enables re-connecting disconnected network drives
%SEE_MASK_NOASYNC           = &H00000100???   ' // block on the call until the invoke has completed, use for callers that exit after calling ShellExecuteEx()
%SEE_MASK_FLAG_DDEWAIT      = %SEE_MASK_NOASYNC   ' // Use SEE_MASK_NOASYNC instead of SEE_MASK_FLAG_DDEWAIT as it more accuratly describes the behavior
%SEE_MASK_DOENVSUBST        = &H00000200???   ' // indicates that SHELLEXECUTEINFO.lpFile contains env vars that should be expanded
%SEE_MASK_FLAG_NO_UI        = &H00000400???   ' // disable UI including error messages
%SEE_MASK_UNICODE           = &H00004000???
%SEE_MASK_NO_CONSOLE        = &H00008000???
%SEE_MASK_ASYNCOK           = &H00100000???
'#if (NTDDI_VERSION >= NTDDI_WIN2K)
%SEE_MASK_HMONITOR          = &H00200000???   ' // SHELLEXECUTEINFO.hMonitor
'#endif // (NTDDI_VERSION >= NTDDI_WIN2K)
'#if (NTDDI_VERSION >= NTDDI_WINXPSP1)
%SEE_MASK_NOZONECHECKS      = &H00800000???
'#endif // (NTDDI_VERSION >= NTDDI_WINXPSP1)
'#if (NTDDI_VERSION >= NTDDI_WIN2K)
%SEE_MASK_NOQUERYCLASSSTORE = &H01000000???
%SEE_MASK_WAITFORINPUTIDLE  = &H02000000???
'#endif // (NTDDI_VERSION >= NTDDI_WIN2K)
'#if (NTDDI_VERSION >= NTDDI_WINXP)
%SEE_MASK_FLAG_LOG_USAGE    = &H04000000???
'#endif // (NTDDI_VERSION >= NTDDI_WINXP)

' // Size = 4 bytes
UNION SHELLEXECUTEINFO_UNION BYTE
   hIcon    AS DWORD   ' HANDLE hIcon
'#if (NTDDI_VERSION >= NTDDI_WIN2K)
   hMonitor AS DWORD   ' HANDLE hMonitor
'#endif // (NTDDI_VERSION >= NTDDI_WIN2K)
END UNION

' // Size = 60 bytes
TYPE SHELLEXECUTEINFOA BYTE
   cbSize       AS DWORD        ' DWORD  // in, required, sizeof of this structure
   fMask        AS DWORD        ' ULONG  // in, SEE_MASK_XXX values
   hwnd         AS DWORD        ' HWND   // in, optional
   lpVerb       AS ASCIIZ PTR   ' LPCSTR // in, optional when unspecified the default verb is choosen
   lpFile       AS ASCIIZ PTR   ' LPCSTR // in, either this value or lpIDList must be specified
   lpParameters AS ASCIIZ PTR   ' LPCSTR // in, optional
   lpDirectory  AS ASCIIZ PTR   ' LPCSTR // in, optional
   nShow        AS LONG         ' int    // in, required
   hInstApp     AS DWORD        ' HINSTANCE // out when SEE_MASK_NOCLOSEPROCESS is specified
   lpIDList     AS DWORD        ' LPVOID // in, valid when SEE_MASK_IDLIST is specified, PCIDLIST_ABSOLUTE, for use with SEE_MASK_IDLIST & SEE_MASK_INVOKEIDLIST
   lpClass      AS ASCIIZ PTR   ' LPCSTR // in, valid when SEE_MASK_CLASSNAME is specified
   hkeyClass    AS DWORD        ' HKEY   // in, valid when SEE_MASK_CLASSKEY is specified
   dwHotKey     AS DWORD        ' DWORD  // in, valid when SEE_MASK_HOTKEY is specified
   SHELLEXECUTEINFO_UNION
   hProcess     AS DWORD        ' HANDLE // out, valid when SEE_MASK_NOCLOSEPROCESS specified
END TYPE

' // Size = 60 bytes
TYPE SHELLEXECUTEINFOW BYTE
   cbSize       AS DWORD          ' DWORD   // in, required, sizeof of this structure
   fMask        AS DWORD          ' ULONG   // in, SEE_MASK_XXX values
   hwnd         AS DWORD          ' HWND    // in, optional
   lpVerb       AS WSTRINGZ PTR   ' LPCWSTR // in, optional when unspecified the default verb is choosen
   lpFile       AS WSTRINGZ PTR   ' LPCWSTR // in, either this value or lpIDList must be specified
   lpParameters AS WSTRINGZ PTR   ' LPCWSTR // in, optional
   lpDirectory  AS WSTRINGZ PTR   ' LPCWSTR // in, optional
   nShow        AS LONG           ' int     // in, required
   hInstApp     AS DWORD          ' HINSTANCE // out when SEE_MASK_NOCLOSEPROCESS is specified
   lpIDList     AS DWORD          ' LPVOID  // in, valid when SEE_MASK_IDLIST is specified, PCIDLIST_ABSOLUTE, for use with SEE_MASK_IDLIST & SEE_MASK_INVOKEIDLIST
   lpClass      AS WSTRINGZ PTR   ' LPCWSTR // in, valid when SEE_MASK_CLASSNAME is specified
   hkeyClass    AS DWORD          ' HKEY    // in, valid when SEE_MASK_CLASSKEY is specified
   dwHotKey     AS DWORD          ' DWORD   // in, valid when SEE_MASK_HOTKEY is specified
   SHELLEXECUTEINFO_UNION
   hProcess     AS DWORD          ' HANDLE  // out, valid when SEE_MASK_NOCLOSEPROCESS specified
END TYPE

#IF %DEF(%UNICODE)
   MACRO SHELLEXECUTEINFO = SHELLEXECUTEINFOW
#ELSE
   MACRO SHELLEXECUTEINFO = SHELLEXECUTEINFOA
#ENDIF

DECLARE FUNCTION ShellExecuteExA IMPORT "SHELL32.DLL" ALIAS "ShellExecuteExA" ( _
   BYREF lpExecInfo AS SHELLEXECUTEINFOA _              ' __inout LPSHELLEXECUTEINFO lpExecInfo
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION ShellExecuteExW IMPORT "SHELL32.DLL" ALIAS "ShellExecuteExW" ( _
   BYREF lpExecInfo AS SHELLEXECUTEINFOW _              ' __inout LPSHELLEXECUTEINFOW lpExecInfo
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO ShellExecuteEx = ShellExecuteExW
#ELSE
   MACRO ShellExecuteEx = ShellExecuteExA
#ENDIF

' Not implemented
'DECLARE SUB WinExecError IMPORT "SHELL32.DLL" ALIAS "WinExecErrorA" ( _
'   BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
' , BYVAL error AS LONG _                                ' __in int error
' , BYREF lpstrFileName AS ASCIIZ _                      ' __in LPCSTR lpstrFileName
' , BYREF lpstrTitle AS ASCIIZ _                         ' __in LPCSTR lpstrTitle
' )                                                      ' void

' Not implemented
'DECLARE SUB WinExecErrorW IMPORT "SHELL32.DLL" ALIAS "WinExecErrorW" ( _
'   BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
' , BYVAL error AS LONG _                                ' __in int error
' , BYREF lpstrFileName AS WSTRINGZ _                    ' __in LPCWSTR lpstrFileName
' , BYREF lpstrTitle AS WSTRINGZ _                       ' __in LPCWSTR lpstrTitle
' )                                                      ' void

'#if (NTDDI_VERSION >= NTDDI_WIN2K)
'// deprecated, no longer implemented
'//  SHCreateProcessAsUser()
' // Size = 52 bytes
TYPE SHCREATEPROCESSINFOW BYTE
   cbSize               AS DWORD                     ' DWORD cbSize
   fMask                AS DWORD                     ' ULONG fMask
   hwnd                 AS DWORD                     ' HWND hwnd
   pszFile              AS WSTRINGZ PTR              ' LPCWSTR  pszFile
   pszParameters        AS WSTRINGZ PTR              ' LPCWSTR  pszParameters
   pszCurrentDirectory  AS WSTRINGZ PTR              ' LPCWSTR  pszCurrentDirectory
   hUserToken           AS DWORD                     ' IN HANDLE hUserToken
   lpProcessAttributes  AS SECURITY_ATTRIBUTES PTR   ' IN LPSECURITY_ATTRIBUTES lpProcessAttributes
   lpThreadAttributes   AS SECURITY_ATTRIBUTES PTR   ' IN LPSECURITY_ATTRIBUTES lpThreadAttributes
   bInheritHandles      AS LONG                      ' IN BOOL bInheritHandles
   dwCreationFlags      AS DWORD                     ' IN DWORD dwCreationFlags
   lpStartupInfo        AS STARTUPINFOW        PTR   ' IN LPSTARTUPINFOW lpStartupInfo
   lpProcessInformation AS PROCESS_INFORMATION PTR   ' OUT LPPROCESS_INFORMATION lpProcessInformation
END TYPE

MACRO SHCREATEPROCESSINFO = SHCREATEPROCESSINFOW

DECLARE FUNCTION SHCreateProcessAsUserW IMPORT "SHELL32.DLL" ALIAS "SHCreateProcessAsUserW" ( _
   BYREF pscpi AS SHCREATEPROCESSINFOW _                ' __in PSHCREATEPROCESSINFOW pscpi
 ) AS LONG                                              ' BOOL

MACRO SHCreateProcessAsUser = SHCreateProcessAsUserW
'#endif // (NTDDI_VERSION >= NTDDI_WIN2K)

'#if (NTDDI_VERSION >= NTDDI_VISTA)

DECLARE FUNCTION SHEvaluateSystemCommandTemplate IMPORT "SHELL32.DLL" ALIAS "SHEvaluateSystemCommandTemplate" ( _
   BYREF pszCmdTemplate AS WSTRINGZ _                   ' __in PCWSTR pszCmdTemplate
 , BYREF ppszApplication AS ANY _                       ' __out PWSTR *ppszApplication
 , OPTIONAL BYREF ppszCommandLine AS ANY _              ' __out_opt PWSTR *ppszCommandLine
 , OPTIONAL BYREF ppszParameters AS ANY _               ' __out_opt PWSTR *ppszParameters
 ) AS LONG                                              ' HRESULT

'//  used for implementing IShellFolder::GetUIObject(IID_IQueryAssociations)
'//  designed for namespace extensions with registered extensible types
'//  SHCreateDefaultContextMenu() and others use IQueryAssociations to build up data sets

' enum ASSOCCLASS
%ASSOCCLASS_SHELL_KEY  = 0   ' //  hkeyClass
%ASSOCCLASS_PROGID_KEY = 1   ' //  hkeyClass
%ASSOCCLASS_PROGID_STR = 2   ' //  pszClass (HKCR\pszClass)
%ASSOCCLASS_CLSID_KEY  = 3   ' //  hkeyClass
%ASSOCCLASS_CLSID_STR  = 4   ' //  pszClass (HKCR\CLSID\pszClass)
%ASSOCCLASS_APP_KEY    = 5   ' //  hkeyClass
%ASSOCCLASS_APP_STR    = 6   ' //  pszClass (HKCR\Applications\PathFindFileName(pszClass))
%ASSOCCLASS_SYSTEM_STR = 7   ' //  pszClass
%ASSOCCLASS_FOLDER     = 8   ' //  none
%ASSOCCLASS_STAR       = 9   ' //  none

' // Size = 12 bytes
TYPE ASSOCIATIONELEMENT BYTE
   ac       AS LONG           ' ASSOCCLASS // required
   hkClass  AS DWORD          ' HKEY // may be NULL
   pszClass AS WSTRINGZ PTR   ' PCWSTR // may be NULL
END TYPE

'// the object returned from this API implements IQueryAssociations

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION AssocCreateForClasses LIB "Shell32.dll" _
    ALIAS "AssocCreateForClasses" (BYVAL rgClasses AS ASSOCIATIONELEMENT PTR, _
    BYVAL cClasses AS DWORD, riid AS GUID, ppv AS DWORD) AS LONG  ' HRESULT
#ELSE
DECLARE FUNCTION AssocCreateForClasses IMPORT "SHELL32.DLL" ALIAS "AssocCreateForClasses" ( _
   BYREF rgClasses AS ASSOCIATIONELEMENT _              ' __in const ASSOCIATIONELEMENT *rgClasses
 , BYVAL cClasses AS DWORD _                            ' __in ULONG cClasses
 , BYREF riid AS GUID _                                 ' __in REFIID riid
 , BYREF ppv AS ANY _                                   ' __out void **ppv
 ) AS LONG                                              ' HRESULT
#ENDIF

'#endif // (NTDDI_VERSION >= NTDDI_VISTA)

'////
'////  End ShellExecuteEx and family
'////

'#if (NTDDI_VERSION >= NTDDI_WIN2K)
'//
'// RecycleBin
'//

'// struct for query recycle bin info
'typedef struct _SHQUERYRBINFO {
'    DWORD   cbSize;
'#if !defined(_MAC) || defined(_MAC_INT_64)
'    __int64 i64Size;
'    __int64 i64NumItems;
'#else
'    DWORDLONG i64Size;
'    DWORDLONG i64NumItems;
'#endif
'} SHQUERYRBINFO, *LPSHQUERYRBINFO;

' // Size = 20 bytes
TYPE SHQUERYRBINFO BYTE
   cbSize      AS DWORD   ' DWORD   cbSize
   i64Size     AS QUAD    ' __int64 i64Size
   i64NumItems AS QUAD    ' __int64 i64NumItems
END TYPE

'// flags for SHEmptyRecycleBin
'//
%SHERB_NOCONFIRMATION    = &H00000001???
%SHERB_NOPROGRESSUI      = &H00000002???
%SHERB_NOSOUND           = &H00000004???


DECLARE FUNCTION SHQueryRecycleBinA IMPORT "SHELL32.DLL" ALIAS "SHQueryRecycleBinA" ( _
   BYREF pszRootPath AS ASCIIZ _                        ' __in LPCSTR pszRootPath
 , BYREF pSHQueryRBInfo AS SHQUERYRBINFO _              ' __in LPSHQUERYRBINFO pSHQueryRBInfo
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION SHQueryRecycleBinW IMPORT "SHELL32.DLL" ALIAS "SHQueryRecycleBinW" ( _
   BYREF pszRootPath AS WSTRINGZ _                      ' __in LPCWSTR pszRootPath
 , BYREF pSHQueryRBInfo AS SHQUERYRBINFO _              ' __in LPSHQUERYRBINFO pSHQueryRBInfo
 ) AS LONG                                              ' HRESULT

#IF %DEF(%UNICODE)
   MACRO SHQueryRecycleBin = SHQueryRecycleBinW
#ELSE
   MACRO SHQueryRecycleBin = SHQueryRecycleBinA
#ENDIF

DECLARE FUNCTION SHEmptyRecycleBinA IMPORT "SHELL32.DLL" ALIAS "SHEmptyRecycleBinA" ( _
   BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 , BYREF pszRootPath AS ASCIIZ _                        ' __in LPCSTR pszRootPath
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION SHEmptyRecycleBinW IMPORT "SHELL32.DLL" ALIAS "SHEmptyRecycleBinW" ( _
   BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 , BYREF pszRootPath AS WSTRINGZ _                      ' __in LPCWSTR pszRootPath
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 ) AS LONG                                              ' HRESULT

#IF %DEF(%UNICODE)
   MACRO SHEmptyRecycleBin = SHEmptyRecycleBinW
#ELSE
   MACRO SHEmptyRecycleBin = SHEmptyRecycleBinA
#ENDIF

'////
'//// end of RecycleBin
'#endif // (NTDDI_VERSION >= NTDDI_WIN2K)


'////
'//// Taskbar notification definitions
'////

'#if (NTDDI_VERSION >= NTDDI_VISTA)
' enum QUERY_USER_NOTIFICATION_STATE
%QUNS_NOT_PRESENT               = 1  ' // The user is not present.  Heuristic check for modes like: screen saver, locked machine, non-active FUS session
%QUNS_BUSY                      = 2  ' // The user is busy.  Heuristic check for modes like: full-screen app
%QUNS_RUNNING_D3D_FULL_SCREEN   = 3  ' // full-screen (exlusive-mode) D3D app
%QUNS_PRESENTATION_MODE         = 4  ' // Windows presentation mode (laptop feature) is turned on
%QUNS_ACCEPTS_NOTIFICATIONS     = 5  ' // none of the above
'#if (NTDDI_VERSION >= NTDDI_WIN7)
%QUNS_QUIET_TIME                = 6  ' // We are in OOBE quiet period
'#endif

DECLARE FUNCTION SHQueryUserNotificationState IMPORT "SHELL32.DLL" ALIAS "SHQueryUserNotificationState" ( _
   BYREF pquns AS LONG _                                ' __out QUERY_USER_NOTIFICATION_STATE *pquns
 ) AS LONG                                              ' HRESULT
'#endif // (NTDDI_VERSION >= NTDDI_VISTA)

'#if (NTDDI_VERSION >= NTDDI_WIN7)
'// This api retrieves an IPropertyStore that stores the window's properties.
DECLARE FUNCTION SHGetPropertyStoreForWindow IMPORT "SHELL32.DLL" ALIAS "SHGetPropertyStoreForWindow" ( _
   BYVAL hwnd AS DWORD _                                ' __in HWND hwnd
 , BYREF riid AS GUID _                                 ' __in REFIID riid
 , BYREF ppv AS ANY _                                   ' __out void** ppv
 ) AS LONG                                              ' HRESULT
'#endif

' // Size = 4 bytes
UNION NOTIFYICONDATA5_UNION BYTE
   uTimeout AS DWORD   ' UINT  uTimeout
   uVersion AS DWORD   ' UINT  uVersion // used with NIM_SETVERSION, values 0, 3 and 4
END UNION

' // Size = 508 bytes
TYPE NOTIFYICONDATAA BYTE
   cbSize           AS DWORD          ' DWORD cbSize
   hwnd             AS DWORD          ' HWND hWnd
   uID              AS DWORD          ' UINT uID
   uFlags           AS DWORD          ' UINT uFlags
   uCallbackMessage AS DWORD          ' UINT uCallbackMessage
   hIcon            AS DWORD          ' HICON hIcon
'#if (NTDDI_VERSION < NTDDI_WIN2K)
#IF %WINVER < &H0500
   szTip            AS ASCIIZ * 64    ' CHAR   szTip[64]
#ENDIF
'#endif
'#if (NTDDI_VERSION >= NTDDI_WIN2K)
#IF %WINVER >= &H0500
   szTip            AS ASCIIZ * 128   ' CHAR   szTip[128]
   dwState          AS DWORD          ' DWORD dwState
   dwStateMask      AS DWORD          ' DWORD dwStateMask
   szInfo           AS ASCIIZ * 256   ' CHAR   szInfo[256]
   NOTIFYICONDATA5_UNION
   szInfoTitle      AS ASCIIZ * 64    ' CHAR   szInfoTitle[64]
   dwInfoFlags      AS DWORD          ' DWORD dwInfoFlags
#ENDIF
'#endif
'#if (NTDDI_VERSION >= NTDDI_WINXP)
#IF %WINVER >= &H0501
   guidItem AS GUID                   ' GUID guidItem
#ENDIF
'#endif
'#if (NTDDI_VERSION >= NTDDI_VISTA)
#IF %WINVER >= &H0600
   hBalloonIcon AS DWORD              ' HICON
#ENDIF
'#endif
END TYPE

' // Size = 956 bytes
TYPE NOTIFYICONDATAW BYTE
   cbSize           AS DWORD              ' DWORD cbSize
   hwnd             AS DWORD              ' HWND hWnd
   uID              AS DWORD              ' UINT uID
   uFlags           AS DWORD              ' UINT uFlags
   uCallbackMessage AS DWORD              ' UINT uCallbackMessage
   hIcon            AS DWORD              ' HICON hIcon
'#if (NTDDI_VERSION < NTDDI_WIN2K)
#IF %WINVER < &H0500
   szTip            AS WSTRINGZ * 64      ' WCHAR szTip[64]
#ENDIF
'#endif
'#if (NTDDI_VERSION >= NTDDI_WIN2K)
#IF %WINVER >= &H0500
   szTip            AS WSTRINGZ * 128     ' WCHAR szTip[128]
   dwState          AS DWORD              ' DWORD dwState
   dwStateMask      AS DWORD              ' DWORD dwStateMask
   szInfo           AS WSTRINGZ * 256     ' WCHAR szInfo[256]
   NOTIFYICONDATA5_UNION
   szInfoTitle      AS WSTRINGZ * 64      ' WCHAR szInfoTitle[64]
   dwInfoFlags      AS DWORD              ' DWORD dwInfoFlags
#ENDIF
'#endif
'#if (NTDDI_VERSION >= NTDDI_WINXP)
#IF %WINVER >= &H0501
   guidItem AS GUID                   ' GUID guidItem
#ENDIF
'#endif
'#if (NTDDI_VERSION >= NTDDI_VISTA)
#IF %WINVER >= &H0600
   hBalloonIcon AS DWORD              ' HICON
#ENDIF
'#endif
END TYPE

#IF %DEF(%UNICODE)
   MACRO NOTIFYICONDATA = NOTIFYICONDATAW
#ELSE
   MACRO NOTIFYICONDATA = NOTIFYICONDATAA
#ENDIF

%NOTIFYICONDATAA_V1_SIZE = 88
%NOTIFYICONDATAW_V1_SIZE = 152
#IF %DEF(%UNICODE)
%NOTIFYICONDATA_V1_SIZE = %NOTIFYICONDATAW_V1_SIZE
#ELSE
%NOTIFYICONDATA_V1_SIZE = %NOTIFYICONDATAA_V1_SIZE
#ENDIF

%NOTIFYICONDATAA_V2_SIZE = 488
%NOTIFYICONDATAW_V2_SIZE = 936
#IF %DEF(%UNICODE)
%NOTIFYICONDATA_V2_SIZE = %NOTIFYICONDATAW_V2_SIZE
#ELSE
%NOTIFYICONDATA_V2_SIZE = %NOTIFYICONDATAA_V2_SIZE
#ENDIF

%NOTIFYICONDATAA_V3_SIZE = 504
%NOTIFYICONDATAW_V3_SIZE = 952
#IF %DEF(%UNICODE)
%NOTIFYICONDATA_V3_SIZE = %NOTIFYICONDATAW_V3_SIZE
#ELSE
%NOTIFYICONDATA_V3_SIZE = %NOTIFYICONDATAA_V3_SIZE
#ENDIF

'#if (_WIN32_IE >= 0x0500)
%NIN_SELECT          = %WM_USER + 0
%NINF_KEY            = &H1
%NIN_KEYSELECT       = %NIN_SELECT OR %NINF_KEY
'#endif

'#if (_WIN32_IE >= 0x0501)
%NIN_BALLOONSHOW      = %WM_USER + 2
%NIN_BALLOONHIDE      = %WM_USER + 3
%NIN_BALLOONTIMEOUT   = %WM_USER + 4
%NIN_BALLOONUSERCLICK = %WM_USER + 5
'#endif
'#if (NTDDI_VERSION >= NTDDI_VISTA)
%NIN_POPUPOPEN        = %WM_USER + 6
%NIN_POPUPCLOSE       = %WM_USER + 7
'#endif // (NTDDI_VERSION >= NTDDI_VISTA)
'#if (NTDDI_VERSION >= NTDDI_WIN7)
'#endif // (NTDDI_VERSION >= NTDDI_WIN7)

%NIM_ADD            = &H00000000???
%NIM_MODIFY         = &H00000001???
%NIM_DELETE         = &H00000002???
'#if (_WIN32_IE >= &H0500)
%NIM_SETFOCUS       = &H00000003???
%NIM_SETVERSION     = &H00000004???
'// set NOTIFYICONDATA.uVersion with 0, 3 or 4
'// please read the documentation on the behavior difference that the different versions imply
%NOTIFYICON_VERSION = 3
'#if (NTDDI_VERSION >= NTDDI_VISTA)
%NOTIFYICON_VERSION_4 = 4
'#endif // (NTDDI_VERSION >= NTDDI_VISTA)
'#endif

%NIF_MESSAGE        = &H00000001???
%NIF_ICON           = &H00000002???
%NIF_TIP            = &H00000004???
'#if (_WIN32_IE >= &H0500)
%NIF_STATE          = &H00000008???
%NIF_INFO           = &H00000010???
'#endif
'#if (_WIN32_IE >= &H600)
%NIF_GUID           = &H00000020???
'#endif
'#if (NTDDI_VERSION >= NTDDI_VISTA)
%NIF_REALTIME       = &H00000040???
%NIF_SHOWTIP        = &H00000080???
'#endif // (NTDDI_VERSION >= NTDDI_VISTA)

'#if (_WIN32_IE >= 0x0500)
%NIS_HIDDEN         = &H00000001???
%NIS_SHAREDICON     = &H00000002???

'// says this is the source of a shared icon

'// Notify Icon Infotip flags
%NIIF_NONE       = &H00000000???
'// icon flags are mutually exclusive
'// and take only the lowest 2 bits
%NIIF_INFO       = &H00000001???
%NIIF_WARNING    = &H00000002???
%NIIF_ERROR      = &H00000003???
'#if (NTDDI_VERSION >= NTDDI_XPSP2) // also available in NTDDI_WS03SP1
%NIIF_USER       = &H00000004???
'#endif // (NTDDI_VERSION >= NTDDI_XPSP2)
%NIIF_ICON_MASK  = &H0000000F???
'#if (_WIN32_IE >= &H0501)
%NIIF_NOSOUND    = &H00000010???
'#endif
'#endif
'#if (NTDDI_VERSION >= NTDDI_VISTA)
%NIIF_LARGE_ICON = &H00000020???
'#endif // (NTDDI_VERSION >= NTDDI_VISTA)

'#if (NTDDI_VERSION >= NTDDI_WIN7)
%NIIF_RESPECT_QUIET_TIME = &H00000080???
'#endif // (NTDDI_VERSION >= NTDDI_WIN7)

' // Size = 28 bytes
TYPE NOTIFYICONIDENTIFIER BYTE
   cbSize   AS DWORD   ' DWORD
   hWnd     AS DWORD   ' HWND
   uID      AS DWORD   ' UINT
   guidItem AS GUID    ' GUID
END TYPE

DECLARE FUNCTION Shell_NotifyIconA IMPORT "SHELL32.DLL" ALIAS "Shell_NotifyIconA" ( _
   BYVAL dwMessage AS DWORD _                           ' __in DWORD dwMessage
 , BYREF lpdata AS NOTIFYICONDATAA _                    ' __in PNOTIFYICONDATAA lpdata
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION Shell_NotifyIconW IMPORT "SHELL32.DLL" ALIAS "Shell_NotifyIconW" ( _
   BYVAL dwMessage AS DWORD _                           ' __in DWORD dwMessage
 , BYREF lpdata AS NOTIFYICONDATAW _                    ' __in PNOTIFYICONDATAW lpdata
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO Shell_NotifyIcon = Shell_NotifyIconW
#ELSE
   MACRO Shell_NotifyIcon = Shell_NotifyIconA
#ENDIF

DECLARE FUNCTION Shell_NotifyIconGetRect IMPORT "SHELL32.DLL" ALIAS "Shell_NotifyIconGetRect" ( _
   BYREF identifier AS NOTIFYICONIDENTIFIER _           ' __in const NOTIFYICONIDENTIFIER* identifier
 , BYREF iconLocation AS RECT _                         ' __out RECT* iconLocation
 ) AS LONG                                              ' BOOL

'////
'//// End Taskbar Notification Icons
'////


#IF NOT %DEF(%SHFILEINFO_DEFINED)
    %SHFILEINFO_DEFINED = 1
'////
'//// Begin SHGetFileInfo
'////

'/*
' * The SHGetFileInfo API provides an easy way to get attributes
' * for a file given a pathname.
' *
' *   PARAMETERS
' *
' *     pszPath              file name to get info about
' *     dwFileAttributes     file attribs, only used with SHGFI_USEFILEATTRIBUTES
' *     psfi                 place to return file info
' *     cbFileInfo           size of structure
' *     uFlags               flags
' *
' *   RETURN
' *     TRUE if things worked
' */

' // Size = 352 bytes
TYPE SHFILEINFOA BYTE
   hIcon         AS DWORD                   ' HICON hIcon                    // out: icon
   iIcon         AS LONG                    ' int   iIcon                    // out: icon index
   dwAttributes  AS DWORD                   ' DWORD dwAttributes             // out: SFGAO_ flags
   szDisplayName AS ASCIIZ * %MAX_PATH      ' CHAR  szDisplayName[MAX_PATH]  // out: display name (or path)
   szTypeName    AS ASCIIZ * 80             ' CHAR  szTypeName[80]           // out: type name
END TYPE

' // Size = 692 bytes
TYPE SHFILEINFOW BYTE
   hIcon         AS DWORD                   ' HICON hIcon                    // out: icon
   iIcon         AS LONG                    ' int   iIcon                    // out: icon index
   dwAttributes  AS DWORD                   ' DWORD dwAttributes             // out: SFGAO_ flags
   szDisplayName AS WSTRINGZ * %MAX_PATH    ' WCHAR szDisplayName[MAX_PATH]  // out: display name (or path)
   szTypeName    AS WSTRINGZ * 80           ' WCHAR szTypeName[80]           // out: type name
END TYPE

#IF %DEF(%UNICODE)
   MACRO SHFILEINFO = SHFILEINFOW
#ELSE
   MACRO SHFILEINFO = SHFILEINFOA
#ENDIF

'// NOTE: This is also in shlwapi.h.  Please keep in synch.
#ENDIF   ' // !SHFILEINFO_DEFINED

%SHGFI_ICON              = &H000000100???     ' // get icon
%SHGFI_DISPLAYNAME       = &H000000200???     ' // get display name
%SHGFI_TYPENAME          = &H000000400???     ' // get type name
%SHGFI_ATTRIBUTES        = &H000000800???     ' // get attributes
%SHGFI_ICONLOCATION      = &H000001000???     ' // get icon location
%SHGFI_EXETYPE           = &H000002000???     ' // return exe type
%SHGFI_SYSICONINDEX      = &H000004000???     ' // get system icon index
%SHGFI_LINKOVERLAY       = &H000008000???     ' // put a link overlay on icon
%SHGFI_SELECTED          = &H000010000???     ' // show icon in selected state
'#if (NTDDI_VERSION >= NTDDI_WIN2K)
%SHGFI_ATTR_SPECIFIED    = &H000020000???     ' // get only specified attributes
'#endif // (NTDDI_VERSION >= NTDDI_WIN2K)
%SHGFI_LARGEICON         = &H000000000???     ' // get large icon
%SHGFI_SMALLICON         = &H000000001???     ' // get small icon
%SHGFI_OPENICON          = &H000000002???     ' // get open icon
%SHGFI_SHELLICONSIZE     = &H000000004???     ' // get shell size icon
%SHGFI_PIDL              = &H000000008???     ' // pszPath is a pidl
%SHGFI_USEFILEATTRIBUTES = &H000000010???     ' // use passed dwFileAttribute

'#if (_WIN32_IE >= &H0500)
%SHGFI_ADDOVERLAYS       = &H000000020???     ' // apply the appropriate overlays
%SHGFI_OVERLAYINDEX      = &H000000040???     ' // Get the index of the overlay
                                           ' // in the upper 8 bits of the iIcon
'#endif

DECLARE FUNCTION SHGetFileInfoA IMPORT "SHELL32.DLL" ALIAS "SHGetFileInfoA" ( _
   BYREF pszPath AS ASCIIZ _                            ' __in LPCSTR pszPath
 , BYVAL dwFileAttributes AS DWORD _                    ' __in DWORD dwFileAttributes
 , BYREF psfi AS SHFILEINFOA _                          ' __out SHFILEINFOA *psfi
 , BYVAL cbFileInfo AS DWORD _                          ' __in UINT cbFileInfo
 , BYVAL uFlags AS DWORD _                              ' __in UINT uFlags
 ) AS DWORD                                             ' DWORD_PTR

DECLARE FUNCTION SHGetFileInfoW IMPORT "SHELL32.DLL" ALIAS "SHGetFileInfoW" ( _
   BYREF pszPath AS WSTRINGZ _                          ' __in LPCWSTR pszPath
 , BYVAL dwFileAttributes AS DWORD _                    ' __in DWORD dwFileAttributes
 , BYREF psfi AS SHFILEINFOW _                          ' __out SHFILEINFOW *psfi
 , BYVAL cbFileInfo AS DWORD _                          ' __in UINT cbFileInfo
 , BYVAL uFlags AS DWORD _                              ' __in UINT uFlags
 ) AS DWORD                                             ' DWORD_PTR

#IF %DEF(%UNICODE)
   MACRO SHGetFileInfo = SHGetFileInfoW
#ELSE
   MACRO SHGetFileInfo = SHGetFileInfoA
#ENDIF

'#if (NTDDI_VERSION >= NTDDI_VISTA)
' // Size = 536 bytes
TYPE SHSTOCKICONINFO BYTE
   cbSize         AS DWORD                  ' DWORD
   hIcon          AS DWORD                  ' HICON
   iSysImageIndex AS LONG                   ' int
   iIcon          AS LONG                   ' int
   szPath         AS WSTRINGZ * %MAX_PATH   ' WCHAR
END TYPE

%SHGSI_ICONLOCATION      = 0   ' // you always get the icon location
%SHGSI_ICON              = %SHGFI_ICON
%SHGSI_SYSICONINDEX      = %SHGFI_SYSICONINDEX
%SHGSI_LINKOVERLAY       = %SHGFI_LINKOVERLAY
%SHGSI_SELECTED          = %SHGFI_SELECTED
%SHGSI_LARGEICON         = %SHGFI_LARGEICON
%SHGSI_SMALLICON         = %SHGFI_SMALLICON
%SHGSI_SHELLICONSIZE     = %SHGFI_SHELLICONSIZE

'//  Shell icons


' enum SHSTOCKICONID
%SIID_DOCNOASSOC        = 0     ' // document (blank page) no associated program
%SIID_DOCASSOC          = 1     ' // document with an associated program
%SIID_APPLICATION       = 2     ' // generic application with no custom icon
%SIID_FOLDER            = 3     ' // folder (closed)
%SIID_FOLDEROPEN        = 4     ' // folder (open)
%SIID_DRIVE525          = 5     ' // 5.25" floppy disk drive
%SIID_DRIVE35           = 6     ' // 3.5" floppy disk drive
%SIID_DRIVEREMOVE       = 7     ' // removable drive
%SIID_DRIVEFIXED        = 8     ' // fixed (hard disk) drive
%SIID_DRIVENET          = 9     ' // network drive
%SIID_DRIVENETDISABLED  = 10    ' // disconnected network drive
%SIID_DRIVECD           = 11    ' // CD drive
%SIID_DRIVERAM          = 12    ' // RAM disk drive
%SIID_WORLD             = 13    ' // entire network
%SIID_SERVER            = 15    ' // a computer on the network
%SIID_PRINTER           = 16    ' // printer
%SIID_MYNETWORK         = 17    ' // My network places
%SIID_FIND              = 22    ' // Find
%SIID_HELP              = 23    ' // Help
%SIID_SHARE             = 28    ' // overlay for shared items
%SIID_LINK              = 29    ' // overlay for shortcuts to items
%SIID_SLOWFILE          = 30    ' // overlay for slow items
%SIID_RECYCLER          = 31    ' // empty recycle bin
%SIID_RECYCLERFULL      = 32    ' // full recycle bin
%SIID_MEDIACDAUDIO      = 40    ' // Audio CD Media
%SIID_LOCK              = 47    ' // Security lock
%SIID_AUTOLIST          = 49    ' // AutoList
%SIID_PRINTERNET        = 50    ' // Network printer
%SIID_SERVERSHARE       = 51    ' // Server share
%SIID_PRINTERFAX        = 52    ' // Fax printer
%SIID_PRINTERFAXNET     = 53    ' // Networked Fax Printer
%SIID_PRINTERFILE       = 54    ' // Print to File
%SIID_STACK             = 55    ' // Stack
%SIID_MEDIASVCD         = 56    ' // SVCD Media
%SIID_STUFFEDFOLDER     = 57    ' // Folder containing other items
%SIID_DRIVEUNKNOWN      = 58    ' // Unknown drive
%SIID_DRIVEDVD          = 59    ' // DVD Drive
%SIID_MEDIADVD          = 60    ' // DVD Media
%SIID_MEDIADVDRAM       = 61    ' // DVD-RAM Media
%SIID_MEDIADVDRW        = 62    ' // DVD-RW Media
%SIID_MEDIADVDR         = 63    ' // DVD-R Media
%SIID_MEDIADVDROM       = 64    ' // DVD-ROM Media
%SIID_MEDIACDAUDIOPLUS  = 65    ' // CD+ (Enhanced CD) Media
%SIID_MEDIACDRW         = 66    ' // CD-RW Media
%SIID_MEDIACDR          = 67    ' // CD-R Media
%SIID_MEDIACDBURN       = 68    ' // Burning CD
%SIID_MEDIABLANKCD      = 69    ' // Blank CD Media
%SIID_MEDIACDROM        = 70    ' // CD-ROM Media
%SIID_AUDIOFILES        = 71    ' // Audio files
%SIID_IMAGEFILES        = 72    ' // Image files
%SIID_VIDEOFILES        = 73    ' // Video files
%SIID_MIXEDFILES        = 74    ' // Mixed files
%SIID_FOLDERBACK        = 75    ' // Folder back
%SIID_FOLDERFRONT       = 76    ' // Folder front
%SIID_SHIELD            = 77    ' // Security shield. Use for UAC prompts only.
%SIID_WARNING           = 78    ' // Warning
%SIID_INFO              = 79    ' // Informational
%SIID_ERROR             = 80    ' // Error
%SIID_KEY               = 81    ' // Key / Secure
%SIID_SOFTWARE          = 82    ' // Software
%SIID_RENAME            = 83    ' // Rename
%SIID_DELETE            = 84    ' // Delete
%SIID_MEDIAAUDIODVD     = 85    ' // Audio DVD Media
%SIID_MEDIAMOVIEDVD     = 86    ' // Movie DVD Media
%SIID_MEDIAENHANCEDCD   = 87    ' // Enhanced CD Media
%SIID_MEDIAENHANCEDDVD  = 88    ' // Enhanced DVD Media
%SIID_MEDIAHDDVD        = 89    ' // HD-DVD Media
%SIID_MEDIABLURAY       = 90    ' // BluRay Media
%SIID_MEDIAVCD          = 91    ' // VCD Media
%SIID_MEDIADVDPLUSR     = 92    ' // DVD+R Media
%SIID_MEDIADVDPLUSRW    = 93    ' // DVD+RW Media
%SIID_DESKTOPPC         = 94    ' // desktop computer
%SIID_MOBILEPC          = 95    ' // mobile computer (laptop/notebook)
%SIID_USERS             = 96    ' // users
%SIID_MEDIASMARTMEDIA   = 97    ' // Smart Media
%SIID_MEDIACOMPACTFLASH = 98    ' // Compact Flash
%SIID_DEVICECELLPHONE   = 99    ' // Cell phone
%SIID_DEVICECAMERA      = 100   ' // Camera
%SIID_DEVICEVIDEOCAMERA = 101   ' // Video camera
%SIID_DEVICEAUDIOPLAYER = 102   ' // Audio player
%SIID_NETWORKCONNECT    = 103   ' // Connect to network
%SIID_INTERNET          = 104   ' // Internet
%SIID_ZIPFILE           = 105   ' // ZIP file
%SIID_SETTINGS          = 106   ' // Settings
'// 107-131 are internal Vista RTM icons
'// 132-159 for SP1 icons
%SIID_DRIVEHDDVD        = 132   ' // HDDVD Drive (all types)
%SIID_DRIVEBD           = 133   ' // BluRay Drive (all types)
%SIID_MEDIAHDDVDROM     = 134   ' // HDDVD-ROM Media
%SIID_MEDIAHDDVDR       = 135   ' // HDDVD-R Media
%SIID_MEDIAHDDVDRAM     = 136   ' // HDDVD-RAM Media
%SIID_MEDIABDROM        = 137   ' // BluRay ROM Media
%SIID_MEDIABDR          = 138   ' // BluRay R Media
%SIID_MEDIABDRE         = 139   ' // BluRay RE Media (Rewriable and RAM)
%SIID_CLUSTEREDDRIVE    = 140   ' // Clustered disk
'// 160+ are for Windows 7 icons
%SIID_MAX_ICONS         = 174

%SIID_INVALID = -1   ' ((SHSTOCKICONID)-1)

DECLARE FUNCTION SHGetStockIconInfo IMPORT "SHELL32.DLL" ALIAS "SHGetStockIconInfo" ( _
   BYVAL siid AS LONG _                                 ' __in SHSTOCKICONID siid
 , BYVAL uFlags AS DWORD _                              ' __in UINT uFlags
 , BYREF psii AS SHSTOCKICONINFO _                      ' __inout SHSTOCKICONINFO *psii
 ) AS LONG                                              ' HRESULT

'#endif // (NTDDI_VERSION >= NTDDI_VISTA)

'#if (NTDDI_VERSION >= NTDDI_WIN2K)
'#define SHGetDiskFreeSpace SHGetDiskFreeSpaceEx

DECLARE FUNCTION SHGetDiskFreeSpaceExA IMPORT "SHELL32.DLL" ALIAS "SHGetDiskFreeSpaceExA" ( _
   BYREF pszVolume AS ASCIIZ _                          ' __in LPCSTR pszVolume
 , BYREF pqwFreeCaller AS QUAD _                        ' __out ULARGE_INTEGER *pqwFreeCaller
 , BYREF pqwTot AS QUAD _                               ' __out ULARGE_INTEGER *pqwTot
 , BYREF pqwFree AS QUAD _                              ' __out ULARGE_INTEGER *pqwFree
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SHGetDiskFreeSpaceExW IMPORT "SHELL32.DLL" ALIAS "SHGetDiskFreeSpaceExW" ( _
   BYREF pszVolume AS WSTRINGZ _                        ' __in LPCWSTR pszVolume
 , BYREF pqwFreeCaller AS QUAD _                        ' __out ULARGE_INTEGER *pqwFreeCaller
 , BYREF pqwTot AS QUAD _                               ' __out ULARGE_INTEGER *pqwTot
 , BYREF pqwFree AS QUAD _                              ' __out ULARGE_INTEGER *pqwFree
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO SHGetDiskFreeSpaceEx = SHGetDiskFreeSpaceExW
   MACRO SHGetDiskFreeSpace = SHGetDiskFreeSpaceExW
#ELSE
   MACRO SHGetDiskFreeSpaceEx = SHGetDiskFreeSpaceExA
   MACRO SHGetDiskFreeSpace = SHGetDiskFreeSpaceExW
#ENDIF

DECLARE FUNCTION SHGetNewLinkInfoA IMPORT "SHELL32.DLL" ALIAS "SHGetNewLinkInfoA" ( _
   BYREF pszLinkTo AS ASCIIZ _                          ' __in LPCSTR pszLinkTo
 , BYREF pszDir AS ASCIIZ _                             ' __in LPCSTR pszDir
 , BYREF pszName AS ASCIIZ _                            ' __in LPSTR pszName
 , BYREF pfMustCopy AS LONG _                           ' __out BOOL *pfMustCopy
 , BYVAL uFlags AS DWORD _                              ' __in UINT uFlags
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SHGetNewLinkInfoW IMPORT "SHELL32.DLL" ALIAS "SHGetNewLinkInfoW" ( _
   BYREF pszLinkTo AS WSTRINGZ _                        ' __in LPCWSTR pszLinkTo
 , BYREF pszDir AS WSTRINGZ _                           ' __in LPCWSTR pszDir
 , BYREF pszName AS WSTRINGZ _                          ' __in LPWSTR pszName
 , BYREF pfMustCopy AS LONG _                           ' __out BOOL *pfMustCopy
 , BYVAL uFlags AS DWORD _                              ' __in UINT uFlags
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO SHGetNewLinkInfo = SHGetNewLinkInfoW
#ELSE
   MACRO SHGetNewLinkInfo = SHGetNewLinkInfoA
#ENDIF

%SHGNLI_PIDL             = &H000000001???    ' // pszLinkTo is a pidl
%SHGNLI_PREFIXNAME       = &H000000002???    ' // Make name "Shortcut to xxx"
%SHGNLI_NOUNIQUE         = &H000000004???    ' // don't do the unique name generation
'#if (_WIN32_IE >= &H0501)
%SHGNLI_NOLNK            = &H000000008???    ' // don't add ".lnk" extension
'#endif // _WIN2_IE >= &H0501
'#if (_WIN32_IE >= 0x0600)
%SHGNLI_NOLOCNAME        = &H000000010???    ' // use non localized (parsing) name from the target
'#endif
'#if (NTDDI_VERSION >= NTDDI_WIN7)
%SHGNLI_USEURLEXT        = &H000000020???    ' // use ".url" extension instead of ".lnk"
'#endif
'#endif // (NTDDI_VERSION >= NTDDI_WIN2K)


'////
'//// End SHGetFileInfo
'////

'#if (NTDDI_VERSION >= NTDDI_WIN2K)
'// Printer stuff
%PRINTACTION_OPEN             = 0   ' // pszBuf1:<PrinterName>
%PRINTACTION_PROPERTIES       = 1   ' // pszBuf1:<PrinterName>, pszBuf2:optional <PageName>
%PRINTACTION_NETINSTALL       = 2   ' // pszBuf1:<NetPrinterName>
%PRINTACTION_NETINSTALLLINK   = 3   ' // pszBuf1:<NetPrinterName>, pszBuf2:<path to store link>
%PRINTACTION_TESTPAGE         = 4   ' // pszBuf1:<PrinterName>
%PRINTACTION_OPENNETPRN       = 5   ' // pszBuf1:<NetPrinterName>
'#ifdef WINNT
%PRINTACTION_DOCUMENTDEFAULTS = 6   ' // pszBuf1:<PrinterName>
%PRINTACTION_SERVERPROPERTIES = 7   ' // pszBuf1:<Server> or <NetPrinterName>
'#endif

DECLARE FUNCTION SHInvokePrinterCommandA IMPORT "SHELL32.DLL" ALIAS "SHInvokePrinterCommandA" ( _
   BYVAL hwnd AS DWORD _                                ' __in HWND hwnd
 , BYVAL uAction AS DWORD _                             ' __in UINT uAction
 , BYREF lpBuf1 AS ASCIIZ _                             ' __in LPCSTR lpBuf1
 , BYREF lpBuf2 AS ASCIIZ _                             ' __in LPCSTR lpBuf2
 , BYVAL fModal AS LONG _                               ' __in BOOL fModal
 ) AS LONG                                              ' BOOL

'FUNCTION SHInvokePrinterCommandA ( _
'   BYVAL hWnd AS DWORD _                                ' __in HWND hwnd
' , BYVAL uAction AS DWORD _                             ' __in UINT uAction
' , BYREF lpBuf1 AS ASCIIZ _                             ' __in LPCSTR lpBuf1
' , BYREF lpBuf2 AS ASCIIZ _                             ' __in LPCSTR lpBuf2
' , BYVAL fModal AS LONG _                               ' __in BOOL fModal
' ) AS LONG                                              ' BOOL

'   LOCAL hLib    AS DWORD
'   LOCAL pAddr   AS DWORD
'   LOCAL bRes AS LONG

'   hLib = LoadLibrary("SHELL32.DLL")
'   IF hLib  = %NULL THEN EXIT FUNCTION
'   pAddr = GetProcAddress(hLib, "SHInvokePrinterCommandA")
'   IF pAddr THEN CALL DWORD pAddr USING SHInvokePrinterCommandA(hWnd, uAction, lpBuf1, lpBuf2, fModal) TO bRes
'   FreeLibrary hLib
'   FUNCTION = bRes

'END FUNCTION

DECLARE FUNCTION SHInvokePrinterCommandW IMPORT "SHELL32.DLL" ALIAS "SHInvokePrinterCommandW" ( _
   BYVAL hwnd AS DWORD _                                ' __in HWND hwnd
 , BYVAL uAction AS DWORD _                             ' __in UINT uAction
 , BYREF lpBuf1 AS WSTRINGZ _                           ' __in LPCWSTR lpBuf1
 , BYREF lpBuf2 AS WSTRINGZ _                           ' __in LPCWSTR lpBuf2
 , BYVAL fModal AS LONG _                               ' __in BOOL fModal
 ) AS LONG                                              ' BOOL

'FUNCTION SHInvokePrinterCommandW ( _
'   BYVAL hWnd AS DWORD _                                ' __in HWND hwnd
' , BYVAL uAction AS DWORD _                             ' __in UINT uAction
' , BYREF lpBuf1 AS WSTRINGZ _                           ' __in LPCWSTR lpBuf1
' , BYREF lpBuf2 AS WSTRINGZ _                           ' __in LPCWSTR lpBuf2
' , BYVAL fModal AS LONG _                               ' __in BOOL fModal
' ) AS LONG                                              ' BOOL

'   LOCAL hLib    AS DWORD
'   LOCAL pAddr   AS DWORD
'   LOCAL bRes AS LONG

'   hLib = LoadLibrary("SHELL32.DLL")
'   IF hLib  = %NULL THEN EXIT FUNCTION
'   pAddr = GetProcAddress(hLib, "SHInvokePrinterCommandW")
'   IF pAddr THEN CALL DWORD pAddr USING SHInvokePrinterCommandW(hWnd, uAction, lpBuf1, lpBuf2, fModal) TO bRes
'   FreeLibrary hLib
'   FUNCTION = bRes

'END FUNCTION

#IF %DEF(%UNICODE)
   MACRO SHInvokePrinterCommand(hWnd, uAction, lpBuf1, lpBuf2, fModal) = SHInvokePrinterCommandW(hWnd, uAction, lpBuf1, lpBuf2, fModal)
#ELSE
   MACRO SHInvokePrinterCommand(hWnd, uAction, lpBuf1, lpBuf2, fModal) = SHInvokePrinterCommandA(hWnd, uAction, lpBuf1, lpBuf2, fModal)
#ENDIF

'#endif // (NTDDI_VERSION >= NTDDI_WIN2K)

'#if (NTDDI_VERSION >= NTDDI_VISTA)
' // Size = 20 bytes
TYPE OPEN_PRINTER_PROPS_INFOA BYTE
   dwSize       AS DWORD        ' DWORD
   pszSheetName AS ASCIIZ PTR   ' LPSTR
   uSheetIndex  AS DWORD        ' UINT
   dwFlags      AS DWORD        ' DWORD
   bModal       AS LONG         ' BOOL
END TYPE

' // Size = 20 bytes
TYPE OPEN_PRINTER_PROPS_INFOW BYTE
   dwSize       AS DWORD          ' DWORD
   pszSheetName AS WSTRINGZ PTR   ' LPWSTR
   uSheetIndex  AS DWORD          ' UINT
   dwFlags      AS DWORD          ' DWORD
   bModal       AS LONG           ' BOOL
END TYPE

#IF %DEF(%UNICODE)
   MACRO OPEN_PRINTER_PROPS_INFO = OPEN_PRINTER_PROPS_INFOW
#ELSE
   MACRO OPEN_PRINTER_PROPS_INFO = OPEN_PRINTER_PROPS_INFOA
#ENDIF

%PRINT_PROP_FORCE_NAME   = &H01
'#endif // (NTDDI_VERSION >= NTDDI_WIN2K)

'#endif /* WINVER >= 0x0400 */

'#if (_WIN32_WINNT >= 0x0500) || (_WIN32_WINDOWS >= 0x0500)

'//
'// The SHLoadNonloadedIconOverlayIdentifiers API causes the shell's
'// icon overlay manager to load any registered icon overlay
'// identifers that are not currently loaded.  This is useful if an
'// overlay identifier did not load at shell startup but is needed
'// and can be loaded at a later time.  Identifiers already loaded
'// are not affected.  Overlay identifiers implement the
'// IShellIconOverlayIdentifier interface.
'//
'// Returns:
'//      S_OK
'//

DECLARE FUNCTION SHLoadNonloadedIconOverlayIdentifiers IMPORT "SHELL32.DLL" ALIAS "SHLoadNonloadedIconOverlayIdentifiers" ( _
 ) AS LONG                                              ' HRESULT

'//
'// The SHIsFileAvailableOffline API determines whether a file
'// or folder is available for offline use.
'//
'// Parameters:
'//     pwszPath             file name to get info about
'//     pdwStatus            (optional) OFFLINE_STATUS_* flags returned here
'//
'// Returns:
'//     S_OK                 File/directory is available offline, unless
'//                            OFFLINE_STATUS_INCOMPLETE is returned.
'//     E_INVALIDARG         Path is invalid, or not a net path
'//     E_FAIL               File/directory is not available offline
'//
'// Notes:
'//     OFFLINE_STATUS_INCOMPLETE is never returned for directories.
'//     Both OFFLINE_STATUS_LOCAL and OFFLINE_STATUS_REMOTE may be returned,
'//     indicating "open in both places." This is common when the server is online.
'//

DECLARE FUNCTION SHIsFileAvailableOffline IMPORT "SHELL32.DLL" ALIAS "SHIsFileAvailableOffline" ( _
   BYREF pszPath AS WSTRINGZ _                          ' __in LPCWSTR pszPath
 , BYREF pdwStatus AS DWORD _                           ' __out LPDWORD pdwStatus
 ) AS LONG                                              ' HRESULT

%OFFLINE_STATUS_LOCAL        = &H0001???  ' // If open, it's open locally
%OFFLINE_STATUS_REMOTE       = &H0002???  ' // If open, it's open remotely
%OFFLINE_STATUS_INCOMPLETE   = &H0004???  ' // The local copy is currently imcomplete.
                                          ' // The file will not be available offline
                                          ' // until it has been synchronized.

'#endif

'#if (NTDDI_VERSION >= NTDDI_WINXP)
'//  sets the specified path to use the string resource
'//  as the UI instead of the file system name

DECLARE FUNCTION SHSetLocalizedName IMPORT "SHELL32.DLL" ALIAS "SHSetLocalizedName" ( _
   BYREF pszPath AS WSTRINGZ _                          ' __in LPCWSTR pszPath
 , BYREF pszResModule AS WSTRINGZ _                     ' __in LPCWSTR pszResModule
 , BYVAL idsRes AS LONG _                               ' __in int idsRes
 ) AS LONG                                              ' HRESULT

'#endif // (NTDDI_VERSION >= NTDDI_WINXP)

'#if (NTDDI_VERSION >= NTDDI_VISTA)
'//  sets the specified path to use the string resource
'//  as the UI instead of the file system name

DECLARE FUNCTION SHRemoveLocalizedName IMPORT "SHELL32.DLL" ALIAS "SHRemoveLocalizedName" ( _
   BYREF pszPath AS WSTRINGZ _                          ' __in LPCWSTR pszPath
 ) AS LONG                                              ' HRESULT

'//  gets the string resource for the specified path

DECLARE FUNCTION SHGetLocalizedName IMPORT "SHELL32.DLL" ALIAS "SHGetLocalizedName" ( _
   BYREF pszPath AS WSTRINGZ _                          ' __in LPCWSTR pszPath
 , BYREF pszResModule AS WSTRINGZ _                     ' __out LPWSTR pszResModule
 , BYVAL cch AS DWORD _                                 ' __in UINT cch
 , BYREF pidsRes AS DWORD _                             ' __out int *pidsRes
 ) AS LONG                                              ' HRESULT

'#endif // (NTDDI_VERSION >= NTDDI_VISTA)

'//====== ShellMessageBox ================================================

'// If lpcTitle is NULL, the title is taken from hWnd
'// If lpcText is NULL, this is assumed to be an Out Of Memory message
'// If the selector of lpcTitle or lpcText is NULL, the offset should be a
'//     string resource ID
'// The variable arguments must all be 32-bit values (even if fewer bits
'//     are actually used)
'// lpcText (or whatever string resource it causes to be loaded) should
'//     be a formatting string similar to wsprintf except that only the
'//     following formats are available:
'//         %%              formats to a single '%'
'//         %nn%s           the nn-th arg is a string which is inserted
'//         %nn%ld          the nn-th arg is a DWORD, and formatted decimal
'//         %nn%lx          the nn-th arg is a DWORD, and formatted hex
'//     note that lengths are allowed on the %s, %ld, and %lx, just
'//                         like wsprintf
'//

'int _cdecl ShellMessageBoxA(
'    HINSTANCE hAppInst,
'    HWND hWnd,
'    LPCSTR lpcText,
'    LPCSTR lpcTitle,
'    UINT fuStyle,
'    ...);

DECLARE FUNCTION ShellMessageBoxA CDECL IMPORT "SHELL32.DLL" ALIAS "ShellMessageBoxA" ( _
   BYVAL hInst AS DWORD _                               ' __in HINSTANCE hInst
 , BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 , BYREF pszMsg AS ASCIIZ _                             ' __in LPCSTR pszMsg
 , BYREF pszTitle AS ASCIIZ _                           ' __in LPCSTR pszTitle
 , BYVAL fuStyle AS DWORD _                             ' __in UINT fuStyle
 , OPTIONAL BYREF ANY _                                 ' optional parameters
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 ) AS LONG                                              ' int

'int _cdecl ShellMessageBoxW(
'    HINSTANCE hAppInst,
'    HWND hWnd,
'    LPCWSTR lpcText,
'    LPCWSTR lpcTitle,
'    UINT fuStyle,
'    ...);

DECLARE FUNCTION ShellMessageBoxW CDECL IMPORT "SHELL32.DLL" ALIAS "ShellMessageBoxW" ( _
   BYVAL hInst AS DWORD _                               ' __in HINSTANCE hInst
 , BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 , BYVAL pszMsg AS DWORD _                              ' __in LPCSTR pszMsg
 , BYVAL pszTitle AS DWORD _                            ' __in LPCSTR pszTitle
 , BYVAL fuStyle AS DWORD _                             ' __in UINT fuStyle
 , OPTIONAL BYREF ANY _                                 ' optional parameters
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 , OPTIONAL BYREF ANY _
 ) AS LONG                                              ' int

#IF %DEF(%UNICODE)
   MACRO ShellMessageBox = ShellMessageBoxW
#ELSE
   MACRO ShellMessageBox = ShellMessageBoxA
#ENDIF

'#if (NTDDI_VERSION >= NTDDI_WIN2K)

DECLARE FUNCTION IsLFNDriveA IMPORT "SHELL32.DLL" ALIAS "IsLFNDriveA" ( _
   OPTIONAL BYREF pszPath AS ASCIIZ _                   ' __in_opt LPCSTR pszPath
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION IsLFNDriveW IMPORT "SHELL32.DLL" ALIAS "IsLFNDriveW" ( _
   OPTIONAL BYREF pszPath AS WSTRINGZ _                 ' __in_opt LPCWSTR pszPath
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO IsLFNDrive = IsLFNDriveW
#ELSE
   MACRO IsLFNDrive = IsLFNDriveA
#ENDIF

'#endif // (NTDDI_VERSION >= NTDDI_WIN2K)

'#if         _WIN32_IE >= 0x0600

' Note: This function is exported from Shell32.dll in Unicode; there is no ANSI version.
'STDAPI          SHEnumerateUnreadMailAccountsA(HKEY hKeyUser, DWORD dwIndex, LPSTR pszMailAddress, int cchMailAddress);
'STDAPI          SHEnumerateUnreadMailAccountsW(HKEY hKeyUser, DWORD dwIndex, LPWSTR pszMailAddress, int cchMailAddress);
DECLARE FUNCTION SHEnumerateUnreadMailAccountsW IMPORT "SHELL32.DLL" ALIAS "SHEnumerateUnreadMailAccountsW" ( _
   BYVAL hKeyUser AS DWORD _                            ' __in HKEY hKeyUser
 , BYVAL dwIndex AS DWORD _                             ' __in DWORD dwIndex
 , BYREF pszMailAddress AS WSTRINGZ _                   ' __in LPWSTR pszMailAddress
 , BYVAL cchMailAddress AS LONG _                       ' __in int cchMailAddress
 ) AS LONG                                              ' HRESULT

MACRO SHEnumerateUnreadMailAccounts = SHEnumerateUnreadMailAccountsW

' Note: This function is exported from Shell32.dll in Unicode; there is no ANSI version.
'STDAPI          SHGetUnreadMailCountA(HKEY hKeyUser, LPCSTR pszMailAddress, DWORD *pdwCount, FILETIME *pFileTime, LPSTR pszShellExecuteCommand, int cchShellExecuteCommand);
'STDAPI          SHGetUnreadMailCountW(HKEY hKeyUser, LPCWSTR pszMailAddress, DWORD *pdwCount, FILETIME *pFileTime, LPWSTR pszShellExecuteCommand, int cchShellExecuteCommand);
DECLARE FUNCTION SHGetUnreadMailCountW IMPORT "SHELL32.DLL" ALIAS "SHGetUnreadMailCountW" ( _
   BYVAL hKeyUser AS DWORD _                            ' __in HKEY hKeyUser
 , BYREF pszMailAddress AS WSTRINGZ _                   ' __in LPCWSTR pszMailAddress
 , BYREF pdwCount AS DWORD _                            ' __out DWORD *pdwCount
 , BYREF pFileTime AS FILETIME _                        ' __inout FILETIME *pFileTime
 , BYREF pszShellExecuteCommand AS WSTRINGZ _           ' __in LPCWSTR pszShellExecuteCommand
 , BYVAL cchShellExecuteCommand AS LONG _               ' __in int cchShellExecuteCommand
 ) AS LONG                                              ' HRESULT

MACRO SHGetUnreadMailCount = SHGetUnreadMailCountW

' NOTE: This function is exported from Shell32.dll in Unicode; there is no ANSI version.
'STDAPI          SHSetUnreadMailCountA(LPCSTR pszMailAddress, DWORD dwCount, LPCSTR pszShellExecuteCommand);
'STDAPI          SHSetUnreadMailCountW(LPCWSTR pszMailAddress, DWORD dwCount, LPCWSTR pszShellExecuteCommand);
DECLARE FUNCTION SHSetUnreadMailCountW IMPORT "SHELL32.DLL" ALIAS "SHSetUnreadMailCountW" ( _
   BYREF pszMailAddress AS WSTRINGZ _                   ' __in LPCWSTR pszMailAddress
 , BYVAL dwCount AS DWORD _                             ' __in DWORD dwCount
 , BYREF pszShellExecuteCommand AS WSTRINGZ _           ' __in LPCWSTR pszShellExecuteCommand
 ) AS LONG                                              ' HRESULT

MACRO SHSetUnreadMailCount = SHSetUnreadMailCountW

'#endif  /*  _WIN32_IE >= 0x0600     */

'#if (_WIN32_IE >= 0x0601)
DECLARE FUNCTION SHTestTokenMembership IMPORT "SHELL32.DLL" ALIAS "SHTestTokenMembership" ( _
   BYVAL hToken AS DWORD _                              ' __in HANDLE hToken
 , BYVAL ulRID AS DWORD _                               ' __in ULONG ulRID
 ) AS LONG                                              ' BOOL

'#endif // (_WIN32_IE >= 0x0601)

'#if         _WIN32_IE >= 0x0600

'#if (NTDDI_VERSION >= NTDDI_WINXP)
DECLARE FUNCTION SHGetImageList IMPORT "SHELL32.DLL" ALIAS "SHGetImageList" ( _
   BYVAL iImageList AS LONG _                           ' __in int iImageList
 , BYREF riid AS GUID _                                 ' __in REFIID riid
 , BYREF ppv AS ANY _                                   ' __out void **ppv
 ) AS LONG                                              ' HRESULT
'#endif // (NTDDI_VERSION >= NTDDI_WINXP)

'#if (NTDDI_VERSION >= NTDDI_WINXP)
%SHIL_LARGE         = 0   ' // normally 32x32
%SHIL_SMALL         = 1   ' // normally 16x16
%SHIL_EXTRALARGE    = 2
%SHIL_SYSSMALL      = 3   ' // like SHIL_SMALL, but tracks system small icon metric correctly
'#if (NTDDI_VERSION >= NTDDI_VISTA)
%SHIL_JUMBO         = 4   ' // normally 256x256
'%SHIL_LAST          = %SHIL_JUMBO
'#else
'%SHIL_LAST          = %SHIL_SYSSMALL
'#endif // (NTDDI_VERSION >= NTDDI_VISTA)
'#endif // (NTDDI_VERSION >= NTDDI_WINXP)


' // Function call types for ntshrui folder sharing helpers
'typedef HRESULT (STDMETHODCALLTYPE *PFNCANSHAREFOLDERW)(LPCWSTR pszPath);
'typedef HRESULT (STDMETHODCALLTYPE *PFNSHOWSHAREFOLDERUIW)(HWND hwndParent, LPCWSTR pszPath);

' This function has no associated .lib file. You must use LoadLibrary and GetProcAddress
' to use it.
' This function is available through Microsoft Windows XP Service Pack 2 (SP2) and Windows
' Server 2003. It might be altered or unavailable in subsequent versions of Windows.
' Minimum operating system: Windows XP.
' Implemented as Unicode version only.

FUNCTION CanShareFolderW ( _
   BYREF pszPath AS WSTRINGZ _                   ' __in LPCWSTR pszPath
   ) AS LONG                                     ' HRESULT

   LOCAL hLib  AS DWORD
   LOCAL pAddr AS DWORD
   LOCAL hr    AS LONG

   hLib = LoadLibrary("NTSHRUI.DLL")
   IF hLib = %NULL THEN
      FUNCTION = GetLastError
      EXIT FUNCTION
   END IF
   pAddr = GetProcAddress(hLib, "CanShareFolderW")
   IF pAddr = %NULL THEN
      hr = GetLastError
   ELSE
      CALL DWORD pAddr USING CanShareFolderW(pszPath) TO hr
   END IF
   FreeLibrary hLib
   FUNCTION = hr

END FUNCTION

MACRO CanShareFolder(pszPath) = CanShareFolderW(pszPath)

' typedef HRESULT (STDMETHODCALLTYPE *PFNSHOWSHAREFOLDERUIW)(IN HWND hwndParent, IN LPCWSTR pszPath);
' Note: Implemented as Unicode version only.
' Minimum operating system: Windows XP.
' This function has no associated .lib file. You must use LoadLibrary and GetProcAddress
' to use it.

FUNCTION ShowShareFolderUI ( _
   BYVAL hwndParent AS DWORD _                   ' __in HWND hwndParent
 , BYREF pszPath AS WSTRINGZ _                   ' __in LPCWSTR pszPath
   ) AS LONG                                     ' HRESULT

   LOCAL hLib  AS DWORD
   LOCAL pAddr AS DWORD
   LOCAL hr    AS LONG

   hLib = LoadLibrary("NTSHRUI.DLL")
   IF hLib = %NULL THEN
      FUNCTION = GetLastError
      EXIT FUNCTION
   END IF
   pAddr = GetProcAddress(hLib, "ShowShareFolderUI")
   IF pAddr = %NULL THEN
      hr = GetLastError
   ELSE
      CALL DWORD pAddr USING ShowShareFolderUI(hWndParent, pszPath) TO hr
   END IF
   FreeLibrary hLib
   FUNCTION = hr

END FUNCTION

'#endif  /*  _WIN32_IE >= 0x0600     */

'#if !defined(_WIN64)
'#include <poppack.h>
'#endif

'#if (NTDDI_VERSION >= NTDDI_VISTA)
'// API for new Network Address Control

'// Instantiation
'#define WC_NETADDRESS L"msctls_netaddress"
$$WC_NETADDRESS = "msctls_netaddress"$$

DECLARE FUNCTION InitNetworkAddressControl IMPORT "SHELL32.DLL" ALIAS "InitNetworkAddressControl" ( _
 ) AS LONG                                              ' BOOL

'// Address Control Messages

'// NCM_GETADDRESS returns the type of address that is present in the
'// control (based on TBD Net Address flags).  If the input string has
'// not been validated using this message will force the validation of
'// the input string.  The WPARAM is a BOOL to determine to show the
'// balloon tip.  The LPARAM is a pointer to the structure to fill in
'// with the address type and address string.

%NCM_GETADDRESS = (%WM_USER+1)

'#define NetAddr_GetAddress(hwnd,pv) \
'    (HRESULT)SNDMSG(hwnd,NCM_GETADDRESS,0,(LPARAM)pv)

' // Size = 8 bytes
TYPE NC_ADDRESS WORD       ' Must be WORD aligned
   pAddrInfo    AS DWORD   ' struct NET_ADDRESS_INFO_ * // defined in iphlpapi.h
   PortNumber   AS WORD    ' USHORT
   PrefixLength AS BYTE    ' BYTE
END TYPE

FUNCTION NetAddr_GetAddress(BYVAL hwnd AS DWORD, BYREF pv AS NC_ADDRESS) AS LONG
   FUNCTION = SendMessage(hwnd, %NCM_GETADDRESS, 0, VARPTR(pv))
END FUNCTION

'// NCM_SETALLOWTYPE sets the type of addresses that the control will allow.
'// The address flags are defined in iphlpapi.h

%NCM_SETALLOWTYPE = (%WM_USER+2)

FUNCTION NetAddr_SetAllowType(BYVAL hwnd AS DWORD, BYVAL addrMask AS LONG) AS LONG
   FUNCTION = SendMessage(hwnd, %NCM_SETALLOWTYPE, addrMask, 0)
END FUNCTION

'// NCM_GETALLOWTYPE returns the currently allowed type mask.

%NCM_GETALLOWTYPE = (%WM_USER+3)

FUNCTION NetAddr_GetAllowType(BYVAL hwnd AS DWORD) AS DWORD
   FUNCTION = SendMessage(hwnd, %NCM_GETALLOWTYPE, 0, 0)
END FUNCTION

'// NCM_DISPLAYERRORTIP displays the error balloon tip with the correct
'// error string (based on the last failure from the NCM_GETADDRESS call
%NCM_DISPLAYERRORTIP = (%WM_USER+4)

FUNCTION NetAddr_DisplayErrorTip(BYVAL hwnd AS DWORD) AS LONG
   FUNCTION = SendMessage(hwnd, %NCM_DISPLAYERRORTIP, 0, 0)
END FUNCTION

'#endif // (NTDDI_VERSION >= NTDDI_VISTA)

'#if (NTDDI_VERSION >= NTDDI_VISTA)
'// Returns the type of media (CD, DVD, Blank, etc) that is in the drive.
'// dwMediaContent is set to a combination of ARCONTENT flags.

DECLARE FUNCTION SHGetDriveMedia IMPORT "SHELL32.DLL" ALIAS "SHGetDriveMedia" ( _
   BYREF pszDrive AS WSTRINGZ _                         ' __in LPCWSTR pszDrive
 , BYREF pdwMediaContent AS DWORD _                     ' __out DWORD *pdwMediaContent
 ) AS LONG                                              ' BOOL

'#endif // (NTDDI_VERSION >= NTDDI_VISTA)

'// Windows Parental Controls (WPC) query apis
'#if (NTDDI_VERSION >= NTDDI_VISTA)
'#endif // (NTDDI_VERSION >= NTDDI_VISTA)

'// Undocumented.
'// Updates the Recycle Bin icon on the desktop to reflect the state of the systemwide Recycle Bin.
'// If an error occued, the function returns a non-zero error code. If successful, the function returns 0.
DECLARE FUNCTION SHUpdateRecycleBinIcon IMPORT "SHELL32.DLL" ALIAS "SHUpdateRecycleBinIcon" () AS LONG
