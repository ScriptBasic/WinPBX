' ########################################################################################
' Microsoft Windows
' File: CommDlg.inc
' Contents: 32-Bit Common Dialog APIs
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

' NOTE: In the functions that have an OPENFILENAME structure as a parameter,
' this has been declared as ANY to allow to pass either an OPENFILENAME or
' an OPENFILENAME5 structure.

#INCLUDE THIS ONCE
%COMMDLG_INC = 1

#INCLUDE ONCE "windows.inc"
#INCLUDE ONCE "cderr.inc"

'#IF %WINVER >= &H0500

'#IF %DEF(%DEFINE_GUID)
'#ifdef DEFINE_GUID

'//
'//  IPrintDialogCallback interface id used by PrintDlgEx.
'//
'//  {5852A2C3-6530-11D1-B6A3-0000F8757BF9}
'//
'DEFINE_GUID(IID_IPrintDialogCallback, 0x5852a2c3, 0x6530, 0x11d1, 0xb6, 0xa3, 0x0, 0x0, 0xf8, 0x75, 0x7b, 0xf9);
$IID_IPrintDialogCallback = GUID$("{5852A2C3-6530-11D1-B6A3-0000F8757BF9}")

'//
'//  IPrintDialogServices interface id used by PrintDlgEx.
'//
'//  {509AAEDA-5639-11D1-B6A1-0000F8757BF9}
'//
'DEFINE_GUID(IID_IPrintDialogServices, 0x509aaeda, 0x5639, 0x11d1, 0xb6, 0xa1, 0x0, 0x0, 0xf8, 0x75, 0x7b, 0xf9);
$IID_IPrintDialogServices = GUID$("{509AAEDA-5639-11D1-B6A1-0000F8757BF9}")

'#endif
'#ENDIF

'#ENDIF   ' /* WINVER >= 0x0500 */


'#ifndef GUID_DEFS_ONLY

'#include <prsht.h>
'#IF NOT %DEF(%NOPROPSHEET)
'    #INCLUDE ONCE "prsht.inc"
'#ENDIF

'#if !defined(_WIN64)
'#include <pshpack1.h>         /* Assume byte packing throughout */
'#endif

'typedef UINT_PTR (CALLBACK *LPOFNHOOKPROC) (hwnd, UINT, WPARAM, LPARAM);
'FUNCTION OFNHOOKPROC (BYVAL DWORD, BYVAL DWORD, BYVAL DWORD, BYVAL LONG) AS DWORD

'#ifndef CDSIZEOF_STRUCT
'#define CDSIZEOF_STRUCT(structname, member)  (((int)((LPBYTE)(&((structname*)0)->member) - ((LPBYTE)((structname*)0)))) + sizeof(((structname*)0)->member))
'#endif

' // Size = 76 bytes
TYPE OPENFILENAME_NT4A BYTE
   lStructSize       AS DWORD          ' DWORD         lStructSize
   hwndOwner         AS DWORD          ' hwnd          hwndOwner
   hInstance         AS DWORD          ' HINSTANCE     hInstance
   lpstrFilter       AS ASCIIZ PTR     ' LPCSTR        lpstrFilter
   lpstrCustomFilter AS ASCIIZ PTR     ' LPSTR         lpstrCustomFilter
   nMaxCustFilter    AS DWORD          ' DWORD         nMaxCustFilter
   nFilterIndex      AS DWORD          ' DWORD         nFilterIndex
   lpstrFile         AS ASCIIZ PTR     ' LPSTR         lpstrFile
   nMaxFile          AS DWORD          ' DWORD         nMaxFile
   lpstrFileTitle    AS ASCIIZ PTR     ' LPSTR         lpstrFileTitle
   nMaxFileTitle     AS DWORD          ' DWORD         nMaxFileTitle
   lpstrInitialDir   AS ASCIIZ PTR     ' LPCSTR        lpstrInitialDir
   lpstrTitle        AS ASCIIZ PTR     ' LPCSTR        lpstrTitle
   Flags             AS DWORD          ' DWORD         Flags
   nFileOffset       AS WORD           ' WORD          nFileOffset
   nFileExtension    AS WORD           ' WORD          nFileExtension
   lpstrDefExt       AS ASCIIZ PTR     ' LPCSTR        lpstrDefExt
   lCustData         AS LONG           ' LPARAM        lCustData
   lpfnHook          AS DWORD          ' LPOFNHOOKPROC lpfnHook
   lpTemplateName    AS ASCIIZ PTR     ' LPCSTR        lpTemplateName
END TYPE

TYPE OPENFILENAME_NT4W
   lStructSize       AS DWORD          ' DWORD         lStructSize
   hwndOwner         AS DWORD          ' hwnd          hwndOwner
   hInstance         AS DWORD          ' HINSTANCE     hInstance
   lpstrFilter       AS WSTRINGZ PTR   ' LPCWSTR       lpstrFilter
   lpstrCustomFilter AS WSTRINGZ PTR   ' LPSWTR        lpstrCustomFilter
   nMaxCustFilter    AS DWORD          ' DWORD         nMaxCustFilter
   nFilterIndex      AS DWORD          ' DWORD         nFilterIndex
   lpstrFile         AS WSTRINGZ PTR   ' LPWSTR        lpstrFile
   nMaxFile          AS DWORD          ' DWORD         nMaxFile
   lpstrFileTitle    AS WSTRINGZ PTR   ' LPWSTR        lpstrFileTitle
   nMaxFileTitle     AS DWORD          ' DWORD         nMaxFileTitle
   lpstrInitialDir   AS WSTRINGZ PTR   ' LPCWSTR       lpstrInitialDir
   lpstrTitle        AS WSTRINGZ PTR   ' LPCWSTR       lpstrTitle
   Flags             AS DWORD          ' DWORD         Flags
   nFileOffset       AS WORD           ' WORD          nFileOffset
   nFileExtension    AS WORD           ' WORD          nFileExtension
   lpstrDefExt       AS WSTRINGZ PTR   ' LPCWSTR        lpstrDefExt
   lCustData         AS LONG           ' LPARAM        lCustData
   lpfnHook          AS DWORD          ' LPOFNHOOKPROC lpfnHook
   lpTemplateName    AS WSTRINGZ PTR   ' LPCWSTR       lpTemplateName
END TYPE

' // Size = 88 bytes (76 bytes in Windows 95/98/NT4)
TYPE OPENFILENAMEA BYTE
   lStructSize       AS DWORD          ' DWORD         lStructSize
   hwndOwner         AS DWORD          ' hwnd          hwndOwner
   hInstance         AS DWORD          ' HINSTANCE     hInstance
   lpstrFilter       AS ASCIIZ PTR     ' LPCSTR        lpstrFilter
   lpstrCustomFilter AS ASCIIZ PTR     ' LPSTR         lpstrCustomFilter
   nMaxCustFilter    AS DWORD          ' DWORD         nMaxCustFilter
   nFilterIndex      AS DWORD          ' DWORD         nFilterIndex
   lpstrFile         AS ASCIIZ PTR     ' LPSTR         lpstrFile
   nMaxFile          AS DWORD          ' DWORD         nMaxFile
   lpstrFileTitle    AS ASCIIZ PTR     ' LPSTR         lpstrFileTitle
   nMaxFileTitle     AS DWORD          ' DWORD         nMaxFileTitle
   lpstrInitialDir   AS ASCIIZ PTR     ' LPCSTR        lpstrInitialDir
   lpstrTitle        AS ASCIIZ PTR     ' LPCSTR        lpstrTitle
   Flags             AS DWORD          ' DWORD         Flags
   nFileOffset       AS WORD           ' WORD          nFileOffset
   nFileExtension    AS WORD           ' WORD          nFileExtension
   lpstrDefExt       AS ASCIIZ PTR     ' LPCSTR        lpstrDefExt
   lCustData         AS LONG           ' LPARAM        lCustData
   lpfnHook          AS DWORD          ' LPOFNHOOKPROC lpfnHook
   lpTemplateName    AS ASCIIZ PTR     ' LPCSTR        lpTemplateName
#IF %WINVER >= &H0500
   pvReserved        AS DWORD          ' void *        pvReserved
   dwReserved        AS DWORD          ' DWORD         dwReserved
   FlagsEx           AS DWORD          ' DWORD         FlagsEx
#ENDIF
END TYPE

' // Size = 88 bytes (76 bytes in Windows 95/98/NT4)
TYPE OPENFILENAMEW BYTE
   lStructSize       AS DWORD          ' DWORD         lStructSize
   hwndOwner         AS DWORD          ' hwnd          hwndOwner
   hInstance         AS DWORD          ' HINSTANCE     hInstance
   lpstrFilter       AS WSTRINGZ PTR   ' LPCWSTR       lpstrFilter
   lpstrCustomFilter AS WSTRINGZ PTR   ' LPSWTR        lpstrCustomFilter
   nMaxCustFilter    AS DWORD          ' DWORD         nMaxCustFilter
   nFilterIndex      AS DWORD          ' DWORD         nFilterIndex
   lpstrFile         AS WSTRINGZ PTR   ' LPWSTR        lpstrFile
   nMaxFile          AS DWORD          ' DWORD         nMaxFile
   lpstrFileTitle    AS WSTRINGZ PTR   ' LPWSTR        lpstrFileTitle
   nMaxFileTitle     AS DWORD          ' DWORD         nMaxFileTitle
   lpstrInitialDir   AS WSTRINGZ PTR   ' LPCWSTR       lpstrInitialDir
   lpstrTitle        AS WSTRINGZ PTR   ' LPCWSTR       lpstrTitle
   Flags             AS DWORD          ' DWORD         Flags
   nFileOffset       AS WORD           ' WORD          nFileOffset
   nFileExtension    AS WORD           ' WORD          nFileExtension
   lpstrDefExt       AS WSTRINGZ PTR   ' LPCWSTR        lpstrDefExt
   lCustData         AS LONG           ' LPARAM        lCustData
   lpfnHook          AS DWORD          ' LPOFNHOOKPROC lpfnHook
   lpTemplateName    AS WSTRINGZ PTR   ' LPCWSTR       lpTemplateName
#IF %WINVER >= &H0500
   pvReserved        AS DWORD          ' void *        pvReserved
   dwReserved        AS DWORD          ' DWORD         dwReserved
   FlagsEx           AS DWORD          ' DWORD         FlagsEx
#ENDIF
END TYPE

#IF %DEF(%UNICODE)
MACRO OPENFILENAME_NT4 = OPENFILENAME_NT4W
MACRO OPENFILENAME     = OPENFILENAMEW
MACRO OPENFILENAME5    = OPENFILENAMEW
#ELSE
MACRO OPENFILENAME_NT4 = OPENFILENAME_NT4A
MACRO OPENFILENAME     = OPENFILENAMEA
MACRO OPENFILENAME5    = OPENFILENAMEA
#ENDIF

'#IF (%WIN32_WINNT >= &H0500)
#IF %WINVER >= &H0500
%OPENFILENAME_SIZE_VERSION_400A = 76   ' CDSIZEOF_STRUCT(OPENFILENAMEA,lpTemplateName)
%OPENFILENAME_SIZE_VERSION_400W = 76   ' CDSIZEOF_STRUCT(OPENFILENAMEW,lpTemplateName)
#IF %DEF(%UNICODE)
%OPENFILENAME_SIZE_VERSION_400 = %OPENFILENAME_SIZE_VERSION_400W
#ELSE
%OPENFILENAME_SIZE_VERSION_400 = %OPENFILENAME_SIZE_VERSION_400A
#ENDIF ' NOT %UNICODE
#ENDIF ' (%WIN32_WINNT >= &H0500)

'#if (_WIN32_WINNT >= 0x0500)

DECLARE FUNCTION GetOpenFileNameA IMPORT "COMDLG32.DLL" ALIAS "GetOpenFileNameA" ( _
   BYREF lpofn AS ANY _                                 ' __inout LPOPENFILENAMEA lpofn
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetOpenFileNameW IMPORT "COMDLG32.DLL" ALIAS "GetOpenFileNameW" ( _
   BYREF lpofn AS ANY _                                 ' __inout LPOPENFILENAMEW lpofn
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
MACRO GetOpenFileName = GetOpenFileNameW
#ELSE
MACRO GetOpenFileName = GetOpenFileNameA
#ENDIF

DECLARE FUNCTION GetSaveFileNameA IMPORT "COMDLG32.DLL" ALIAS "GetSaveFileNameA" ( _
   BYREF lpofn AS ANY _                                 ' __inout LPOPENFILENAMEA lpofn
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION GetSaveFileNameW IMPORT "COMDLG32.DLL" ALIAS "GetSaveFileNameW" ( _
   BYREF lpofn AS ANY _                                 ' __inout LPOPENFILENAMEW lpofn
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
MACRO GetSaveFileName = GetSaveFileNameW
#ELSE
MACRO GetSaveFileName = GetSaveFileNameA
#ENDIF

DECLARE FUNCTION GetFileTitleA IMPORT "COMDLG32.DLL" ALIAS "GetFileTitleA" ( _
   BYREF lpszFile AS ASCIIZ _                           ' __in  LPCSTR lpszFile
 , BYREF lpszTitle AS ASCIIZ _                          ' __out LPSTR lpszTitle
 , BYVAL cbBuf AS WORD _                                ' __in  WORD cbBuf
 ) AS INTEGER                                           ' short

DECLARE FUNCTION GetFileTitleW IMPORT "COMDLG32.DLL" ALIAS "GetFileTitleW" ( _
   BYREF lpszFile AS WSTRINGZ _                         ' __in  LPCWSTR lpszFile
 , BYREF lpszTitle AS WSTRINGZ _                        ' __out LPWSTR lpszTitle
 , BYVAL cbBuf AS WORD _                                ' __in  WORD cbBuf
 ) AS INTEGER                                           ' short

#IF %DEF(%UNICODE)
MACRO GetFileTitle = GetFileTitleW
#ELSE
MACRO GetFileTitle = GetFileTitleA
#ENDIF

'%OFN_READONLY             = &H00000001???
'%OFN_OVERWRITEPROMPT      = &H00000002???
'%OFN_HIDEREADONLY         = &H00000004???
'%OFN_NOCHANGEDIR          = &H00000008???
'%OFN_SHOWHELP             = &H00000010???
%OFN_ENABLEHOOK           = &H00000020???
%OFN_ENABLETEMPLATE       = &H00000040???
%OFN_ENABLETEMPLATEHANDLE = &H00000080???
'%OFN_NOVALIDATE           = &H00000100???
'%OFN_ALLOWMULTISELECT     = &H00000200???
'%OFN_EXTENSIONDIFFERENT   = &H00000400???
'%OFN_PATHMUSTEXIST        = &H00000800???
'%OFN_FILEMUSTEXIST        = &H00001000???
'%OFN_CREATEPROMPT         = &H00002000???
'%OFN_SHAREAWARE           = &H00004000???
'%OFN_NOREADONLYRETURN     = &H00008000???
'%OFN_NOTESTFILECREATE     = &H00010000???
'%OFN_NONETWORKBUTTON      = &H00020000???
'%OFN_NOLONGNAMES          = &H00040000???  ' // force no long names for 4.x modules
'#if(WINVER >= 0x0400)
'%OFN_EXPLORER             = &H00080000???  ' // new look commdlg
'%OFN_NODEREFERENCELINKS   = &H00100000???
'%OFN_LONGNAMES            = &H00200000???  ' // force long names for 3.x modules
%OFN_ENABLEINCLUDENOTIFY  = &H00400000???  ' // send include message to callback
'%OFN_ENABLESIZING         = &H00800000???
'#endif /* WINVER >= 0x0400 */
'#if (_WIN32_WINNT >= 0x0500)
'%OFN_DONTADDTORECENT      = &H02000000???
'%OFN_FORCESHOWHIDDEN      = &H10000000???  ' // Show All files including System and hidden files
'#endif // (_WIN32_WINNT >= 0x0500)

'//FlagsEx Values
'#if (_WIN32_WINNT >= 0x0500)
%OFN_EX_NOPLACESBAR       = &H00000001???
'#endif // (_WIN32_WINNT >= 0x0500)

'// Return values for the registered message sent to the hook function
'// when a sharing violation occurs.  OFN_SHAREFALLTHROUGH allows the
'// filename to be accepted, OFN_SHARENOWARN rejects the name but puts
'// up no warning (returned when the app has already put up a warning
'// message), and OFN_SHAREWARN puts up the default warning message
'// for sharing violations.
'//
'// Note:  Undefined return values map to OFN_SHAREWARN, but are
'//        reserved for future use.

%OFN_SHAREFALLTHROUGH     = 2
%OFN_SHARENOWARN          = 1
%OFN_SHAREWARN            = 0

'typedef UINT_PTR (CALLBACK *LPCCHOOKPROC) (hwnd, UINT, WPARAM, LPARAM);
'FUNCTION CCHOOKPROC (BYVAL DWORD, BYVAL DWORD, BYVAL DWORD, BYVAL LONG) AS DWORD

'#if(WINVER >= 0x0400)
'// Structure used for all file based OpenFileName notifications
TYPE OFNOTIFYA
   hdr     AS NMHDR                    ' NMHDR           hdr;
   lpOFN   AS OPENFILENAMEA PTR        ' LPOPENFILENAMEA lpOFN;
   pszFile AS ASCIIZ PTR               ' LPSTR           pszFile; // May be NULL
END TYPE

TYPE OFNOTIFYW
   hdr     AS NMHDR                    ' NMHDR           hdr;
   lpOFN   AS OPENFILENAMEW PTR        ' LPOPENFILENAMEW lpOFN;
   pszFile AS WSTRINGZ PTR             ' LPWSTR          pszFile; // May be NULL
END TYPE

#IF %DEF(%UNICODE)
MACRO OFNOTIFY = OFNOTIFYW
#ELSE
MACRO OFNOTIFY = OFNOTIFYA
#ENDIF

'// Structure used for all object based OpenFileName notifications
TYPE OFNOTIFYEXA
   hdr   AS NMHDR                      ' NMHDR           hdr;
   lpOFN AS OPENFILENAMEA PTR          ' LPOPENFILENAMEA lpOFN;
   psf   AS DWORD                      ' LPVOID          psf;
   pidl  AS DWORD                      ' LPVOID          pidl; // May be NULL
END TYPE

'// Structure used for all object based OpenFileName notifications
TYPE OFNOTIFYEXW
   hdr   AS NMHDR                      ' NMHDR           hdr;
   lpOFN AS OPENFILENAMEW PTR          ' LPOPENFILENAMEW lpOFN;
   psf   AS DWORD                      ' LPVOID          psf;
   pidl  AS DWORD                      ' LPVOID          pidl; // May be NULL
END TYPE

#IF %DEF(%UNICODE)
MACRO OFNOTIFYEX = OFNOTIFYEXW
#ELSE
MACRO OFNOTIFYEX = OFNOTIFYEXA
#ENDIF

#IF NOT %DEF(%CDN_FIRST)
%CDN_FIRST               = 0-601       ' common dialog new
#ENDIF

#IF NOT %DEF(%CDN_LAST)
%CDN_LAST                = 0-699
#ENDIF

'// Notifications from Open or Save dialog
%CDN_INITDONE         = %CDN_FIRST - &H0000
%CDN_SELCHANGE        = %CDN_FIRST - &H0001
%CDN_FOLDERCHANGE     = %CDN_FIRST - &H0002
%CDN_SHAREVIOLATION   = %CDN_FIRST - &H0003
%CDN_HELP             = %CDN_FIRST - &H0004
%CDN_FILEOK           = %CDN_FIRST - &H0005
%CDN_TYPECHANGE       = %CDN_FIRST - &H0006
'#if (NTDDI_VERSION >= NTDDI_WIN2K)
%CDN_INCLUDEITEM      = %CDN_FIRST - &H0007
'#endif // (NTDDI_VERSION >= NTDDI_WIN2K)

%CDM_FIRST            = %WM_USER + 100
%CDM_LAST             = %WM_USER + 200

'// Messages to query information from the Open or Save dialogs

'// lParam = pointer to text buffer that gets filled in
'// wParam = max number of characters of the text buffer (including NULL)
'// return = < 0 if error; number of characters needed (including NULL)
%CDM_GETSPEC             = %CDM_FIRST + &H0000

FUNCTION CommDlg_OpenSave_GetSpecA (BYVAL hDlg AS DWORD, BYREF psz AS ASCIIZ, BYVAL cbmax AS DWORD) AS LONG
   FUNCTION = SendMessage(hDlg, %CDM_GETSPEC, cbmax, VARPTR(psz))
END FUNCTION

FUNCTION CommDlg_OpenSave_GetSpecW (BYVAL hDlg AS DWORD, BYREF psz AS WSTRINGZ, BYVAL cbmax AS DWORD) AS LONG
   FUNCTION = SendMessage(hDlg, %CDM_GETSPEC, cbmax, VARPTR(psz))
END FUNCTION

#IF %DEF(%UNICODE)
MACRO CommDlg_OpenSave_GetSpec = CommDlg_OpenSave_GetSpecW
#ELSE
MACRO CommDlg_OpenSave_GetSpec = CommDlg_OpenSave_GetSpecA
#ENDIF

'// lParam = pointer to text buffer that gets filled in
'// wParam = max number of characters of the text buffer (including NULL)
'// return = < 0 if error; number of characters needed (including NULL)
%CDM_GETFILEPATH         = %CDM_FIRST + &H0001

FUNCTION CommDlg_OpenSave_GetFilePathA (BYVAL hDlg AS DWORD, BYREF psz AS ASCIIZ, BYVAL cbmax AS DWORD) AS LONG
   FUNCTION = SendMessage(hDlg, %CDM_GETFILEPATH, cbmax, VARPTR(psz))
END FUNCTION

FUNCTION CommDlg_OpenSave_GetFilePathW (BYVAL hDlg AS DWORD, BYREF psz AS WSTRINGZ, BYVAL cbmax AS DWORD) AS LONG
   FUNCTION = SendMessage(hDlg, %CDM_GETFILEPATH, cbmax, VARPTR(psz))
END FUNCTION

#IF %DEF(%UNICODE)
MACRO CommDlg_OpenSave_GetFilePath = CommDlg_OpenSave_GetFilePathW
#ELSE
MACRO CommDlg_OpenSave_GetFilePath = CommDlg_OpenSave_GetFilePathA
#ENDIF

'// lParam = pointer to text buffer that gets filled in
'// wParam = max number of characters of the text buffer (including NULL)
'// return = < 0 if error; number of characters needed (including NULL)
%CDM_GETFOLDERPATH       = %CDM_FIRST + &H0002

FUNCTION CommDlg_OpenSave_GetFolderPathA (BYVAL hDlg AS DWORD, BYREF psz AS ASCIIZ, BYVAL cbmax AS DWORD) AS LONG
   FUNCTION = SendMessage(hDlg, %CDM_GETFOLDERPATH, cbmax, VARPTR(psz))
END FUNCTION

FUNCTION CommDlg_OpenSave_GetFolderPathW (BYVAL hDlg AS DWORD, BYREF psz AS WSTRINGZ, BYVAL cbmax AS DWORD) AS LONG
   FUNCTION = SendMessage(hDlg, %CDM_GETFOLDERPATH, cbmax, VARPTR(psz))
END FUNCTION

#IF %DEF(%UNICODE)
MACRO CommDlg_OpenSave_GetFolderPath = CommDlg_OpenSave_GetFolderPathW
#ELSE
MACRO CommDlg_OpenSave_GetFolderPath = CommDlg_OpenSave_GetFolderPathA
#ENDIF

'// lParam = pointer to ITEMIDLIST buffer that gets filled in
'// wParam = size of the ITEMIDLIST buffer
'// return = < 0 if error; length of buffer needed
%CDM_GETFOLDERIDLIST     = %CDM_FIRST + &H0003

FUNCTION CommDlg_OpenSave_GetFolderIDList (BYVAL hDlg AS DWORD, BYVAL pidl AS DWORD, BYVAL cbmax AS DWORD) AS LONG
   FUNCTION = SendMessage(hDlg, %CDM_GETFOLDERIDLIST, cbmax, pidl)
END FUNCTION

'// lParam = pointer to a string
'// wParam = ID of control to change
'// return = not used
%CDM_SETCONTROLTEXT      = %CDM_FIRST + &H0004

SUB CommDlg_OpenSave_SetControlText (BYVAL hDlg AS DWORD, BYVAL id AS LONG, BYREF szText AS ASCIIZ)
   SendMessage(hDlg, %CDM_SETCONTROLTEXT, id, VARPTR(szText))
END SUB

'// lParam = not used
'// wParam = ID of control to change
'// return = not used
%CDM_HIDECONTROL         = %CDM_FIRST + &H0005

SUB CommDlg_OpenSave_HideControl (BYVAL hDlg AS DWORD, BYVAL id AS LONG)
   SendMessage(hDlg, %CDM_HIDECONTROL, id, 0)
END SUB

'// lParam = pointer to default extension (no dot)
'// wParam = not used
'// return = not used
%CDM_SETDEFEXT           = %CDM_FIRST + &H0006

SUB CommDlg_OpenSave_SetDefExt (BYVAL hDlg AS DWORD, BYREF szText AS ASCIIZ)
   SendMessage(hDlg, %CDM_SETDEFEXT, 0, VARPTR(szText))
END SUB

'#endif /* WINVER >= 0x0400 */

TYPE CHOOSECOLORAPIA
   lStructSize    AS DWORD             ' DWORD        lStructSize;
   hwndOwner      AS DWORD             ' hwnd         hwndOwner;
   hInstance      AS DWORD             ' hwnd         hInstance;
   rgbResult      AS DWORD             ' COLORREF     rgbResult;
   lpCustColors   AS DWORD PTR         ' COLORREF*    lpCustColors;
   Flags          AS DWORD             ' DWORD        Flags;
   lCustData      AS LONG              ' LPARAM       lCustData;
   lpfnHook       AS DWORD             ' LPCCHOOKPROC lpfnHook;
   lpTemplateName AS ASCIIZ PTR        ' LPCSTR       lpTemplateName;
END TYPE

TYPE CHOOSECOLORAPIW
   lStructSize    AS DWORD             ' DWORD        lStructSize;
   hwndOwner      AS DWORD             ' hwnd         hwndOwner;
   hInstance      AS DWORD             ' hwnd         hInstance;
   rgbResult      AS DWORD             ' COLORREF     rgbResult;
   lpCustColors   AS DWORD PTR         ' COLORREF*    lpCustColors;
   Flags          AS DWORD             ' DWORD        Flags;
   lCustData      AS LONG              ' LPARAM       lCustData;
   lpfnHook       AS DWORD             ' LPCCHOOKPROC lpfnHook;
   lpTemplateName AS WSTRINGZ PTR      ' LPCWSTR      lpTemplateName;
END TYPE

MACRO tagCHOOSECOLORA = CHOOSECOLORAPIA
MACRO tagCHOOSECOLORW = CHOOSECOLORAPIW

#IF %DEF(%UNICODE)
   MACRO CHOOSECOLORAPI = CHOOSECOLORAPIW
   MACRO tagCHOOSECOLOR = CHOOSECOLORAPIW
#ELSE
   MACRO CHOOSECOLORAPI = CHOOSECOLORAPIA
   MACRO tagCHOOSECOLOR = CHOOSECOLORAPIA
#ENDIF

DECLARE FUNCTION ChooseColorA IMPORT "COMDLG32.DLL" ALIAS "ChooseColorA" ( _
   BYREF lpcc AS CHOOSECOLORAPIA _                      ' __inout LPCHOOSECOLORA lpcc
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION ChooseColorW IMPORT "COMDLG32.DLL" ALIAS "ChooseColorW" ( _
   BYREF lpcc AS CHOOSECOLORAPIW _                      ' __inout LPCHOOSECOLORW lpcc
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO ChooseColor = ChooseColorW
#ELSE
   MACRO ChooseColor = ChooseColorA
#ENDIF

' // Note: The remed equates are predefined in the compiler.
%CC_RGBINIT                     = &H00000001???
'%CC_FULLOPEN                    = &H00000002???
'%CC_PREVENTFULLOPEN             = &H00000004???
'%CC_SHOWHELP                    = &H00000008???
%CC_ENABLEHOOK                  = &H00000010???
%CC_ENABLETEMPLATE              = &H00000020???
%CC_ENABLETEMPLATEHANDLE        = &H00000040???
'#if(WINVER >= 0x0400)
%CC_SOLIDCOLOR                  = &H00000080???
%CC_ANYCOLOR                    = &H00000100???
'#endif /* WINVER >= 0x0400 */

'typedef UINT_PTR (CALLBACK *LPFRHOOKPROC) (hwnd, UINT, WPARAM, LPARAM);
'FUNCTION FRHOOKPROC (BYVAL DWORD, BYVAL DWORD, BYVAL DWORD, BYVAL LONG) AS DWORD

TYPE FINDREPLACEA
   lStructSize      AS DWORD        ' DWORD        lStructSize;        // size of this struct 0x20
   hwndOwner        AS DWORD        ' hwnd         hwndOwner;          // handle to owner's window
   hInstance        AS DWORD        ' HINSTANCE    hInstance;          // instance handle of.EXE that contains cust. dlg. template
   Flags            AS DWORD        ' DWORD        Flags;              // one or more of the FR_??
   lpstrFindWhat    AS ASCIIZ PTR   ' LPSTR        lpstrFindWhat;      // ptr. to search string
   lpstrReplaceWith AS ASCIIZ PTR   ' LPSTR        lpstrReplaceWith;   // ptr. to replace string
   wFindWhatLen     AS WORD         ' WORD         wFindWhatLen;       // size of find buffer
   wReplaceWithLen  AS WORD         ' WORD         wReplaceWithLen;    // size of replace buffer
   lCustData        AS LONG         ' LPARAM       lCustData;          // data passed to hook fn.
   lpfnHook         AS DWORD        ' LPFRHOOKPROC lpfnHook;           // ptr. to hook fn. or NULL
   lpTemplateName   AS ASCIIZ PTR   ' LPCSTR       lpTemplateName;     // custom template name
END TYPE

TYPE FINDREPLACEW
   lStructSize      AS DWORD        ' DWORD        lStructSize;        // size of this struct 0x20
   hwndOwner        AS DWORD        ' hwnd         hwndOwner;          // handle to owner's window
   hInstance        AS DWORD        ' HINSTANCE    hInstance;          // instance handle of.EXE that contains cust. dlg. template
   Flags            AS DWORD        ' DWORD        Flags;              // one or more of the FR_??
   lpstrFindWhat    AS WSTRINGZ PTR ' LPWSTR       lpstrFindWhat;      // ptr. to search string
   lpstrReplaceWith AS WSTRINGZ PTR ' LPWSTR       lpstrReplaceWith;   // ptr. to replace string
   wFindWhatLen     AS WORD         ' WORD         wFindWhatLen;       // size of find buffer
   wReplaceWithLen  AS WORD         ' WORD         wReplaceWithLen;    // size of replace buffer
   lCustData        AS LONG         ' LPARAM       lCustData;          // data passed to hook fn.
   lpfnHook         AS DWORD        ' LPFRHOOKPROC lpfnHook;           // ptr. to hook fn. or NULL
   lpTemplateName   AS WSTRINGZ PTR ' LPCWSTR      lpTemplateName;     // custom template name
END TYPE

#IF %DEF(%UNICODE)
   MACRO FINDREPLACE = FINDREPLACEW
#ELSE
   MACRO FINDREPLACE = FINDREPLACEA
#ENDIF

%FR_DOWN                        = &H00000001???
%FR_WHOLEWORD                   = &H00000002???
%FR_MATCHCASE                   = &H00000004???
%FR_FINDNEXT                    = &H00000008???
%FR_REPLACE                     = &H00000010???
%FR_REPLACEALL                  = &H00000020???
%FR_DIALOGTERM                  = &H00000040???
%FR_SHOWHELP                    = &H00000080???
%FR_ENABLEHOOK                  = &H00000100???
%FR_ENABLETEMPLATE              = &H00000200???
%FR_NOUPDOWN                    = &H00000400???
%FR_NOMATCHCASE                 = &H00000800???
%FR_NOWHOLEWORD                 = &H00001000???
%FR_ENABLETEMPLATEHANDLE        = &H00002000???
%FR_HIDEUPDOWN                  = &H00004000???
%FR_HIDEMATCHCASE               = &H00008000???
%FR_HIDEWHOLEWORD               = &H00010000???
%FR_RAW                         = &H00020000???
%FR_MATCHDIAC                   = &H20000000???
%FR_MATCHKASHIDA                = &H40000000???
%FR_MATCHALEFHAMZA              = &H80000000???

DECLARE FUNCTION FindTextA IMPORT "COMDLG32.DLL" ALIAS "FindTextA" ( _
   BYREF lpfr AS FINDREPLACEA _                         ' __in LPFINDREPLACEA lpfr
 ) AS DWORD                                             ' hwnd

DECLARE FUNCTION FindTextW IMPORT "COMDLG32.DLL" ALIAS "FindTextW" ( _
   BYREF lpfr AS FINDREPLACEW _                         ' __in LPFINDREPLACEW lpfr
 ) AS DWORD                                             ' hwnd

#IF %DEF(%UNICODE)
   MACRO FindText = FindTextW
#ELSE
   MACRO FindText = FindTextA
#ENDIF

DECLARE FUNCTION ReplaceTextA IMPORT "COMDLG32.DLL" ALIAS "ReplaceTextA" ( _
   BYREF lpfr AS FINDREPLACEA _                         ' __inout LPFINDREPLACEA lpfr
 ) AS DWORD                                             ' hwnd

DECLARE FUNCTION ReplaceTextW IMPORT "COMDLG32.DLL" ALIAS "ReplaceTextW" ( _
   BYREF lpfr AS FINDREPLACEW _                         ' __inout LPFINDREPLACEW lpfr
 ) AS DWORD                                             ' hwnd

#IF %DEF(%UNICODE)
   MACRO ReplaceText = ReplaceTextW
#ELSE
   MACRO ReplaceText = ReplaceTextA
#ENDIF

'typedef UINT_PTR (CALLBACK *LPCFHOOKPROC) (hwnd, UINT, WPARAM, LPARAM);
'FUNCTION CFHOOKPROC (BYVAL DWORD, BYVAL DWORD, BYVAL DWORD, BYVAL LONG) AS DWORD

TYPE CHOOSEFONTAPIA
   lStructSize    AS DWORD          ' DWORD           lStructSize;
   hwndOwner      AS DWORD          ' hwnd            hwndOwner;          // caller's window handle
   hDC            AS DWORD          ' HDC             hDC;                // printer DC/IC or NULL
   lpLogFont      AS LOGFONTA PTR   ' LPLOGFONTA      lpLogFont;          // ptr. to a LOGFONT struct
   iPointSize     AS LONG           ' INT             iPointSize;         // 10 * size in points of selected font
   Flags          AS DWORD          ' DWORD           Flags;              // enum. type flags
   rgbColors      AS DWORD          ' COLORREF        rgbColors;          // returned text color
   lCustData      AS LONG           ' LPARAM          lCustData;          // data passed to hook fn.
   lpfnHook       AS DWORD          ' LPCFHOOKPROC    lpfnHook;           // ptr. to hook function
   lpTemplateName AS ASCIIZ PTR     ' LPCSTR          lpTemplateName;     // custom template name
   hInstance      AS DWORD          ' HINSTANCE       hInstance;          // instance handle of.EXE that contains cust. dlg. template
   lpszStyle      AS ASCIIZ PTR     ' LPSTR           lpszStyle;          // return the style field here must be LF_FACESIZE or bigger
   nFontType      AS WORD           ' WORD            nFontType;          // same value reported to the EnumFonts call back with the extra FONTTYPE_ bits added
   Alignment      AS WORD           ' WORD            ___MISSING_ALIGNMENT__;
   nSizeMin       AS LONG           ' INT             nSizeMin;           // minimum pt size allowed &
   nSizeMax       AS LONG           ' INT             nSizeMax;           // max pt size allowed if CF_LIMITSIZE is used
END TYPE

TYPE CHOOSEFONTAPIW
   lStructSize    AS DWORD          ' DWORD           lStructSize;
   hwndOwner      AS DWORD          ' hwnd            hwndOwner;          // caller's window handle
   hDC            AS DWORD          ' HDC             hDC;                // printer DC/IC or NULL
   lpLogFont      AS LOGFONTW PTR   ' LPLOGFONTW      lpLogFont;          // ptr. to a LOGFONT struct
   iPointSize     AS LONG           ' INT             iPointSize;         // 10 * size in points of selected font
   Flags          AS DWORD          ' DWORD           Flags;              // enum. type flags
   rgbColors      AS DWORD          ' COLORREF        rgbColors;          // returned text color
   lCustData      AS LONG           ' LPARAM          lCustData;          // data passed to hook fn.
   lpfnHook       AS DWORD          ' LPCFHOOKPROC    lpfnHook;           // ptr. to hook function
   lpTemplateName AS WSTRINGZ PTR   ' LPCWSTR         lpTemplateName;     // custom template name
   hInstance      AS DWORD          ' HINSTANCE       hInstance;          // instance handle of.EXE that contains cust. dlg. template
   lpszStyle      AS WSTRINGZ PTR   ' LPWSTR          lpszStyle;          // return the style field here must be LF_FACESIZE or bigger
   nFontType      AS WORD           ' WORD            nFontType;          // same value reported to the EnumFonts call back with the extra FONTTYPE_ bits added
   Alignment      AS WORD           ' WORD            ___MISSING_ALIGNMENT__;
   nSizeMin       AS LONG           ' INT             nSizeMin;           // minimum pt size allowed &
   nSizeMax       AS LONG           ' INT             nSizeMax;           // max pt size allowed if CF_LIMITSIZE is used
END TYPE

MACRO tagCHOOSEFONTA = CHOOSEFONTAPIA
MACRO tagCHOOSEFONTW = CHOOSEFONTAPIW
' // For compatibility with the PB includes
MACRO CHOOSEFONTA_TYPE = CHOOSEFONTAPIA
MACRO CHOOSEFONTW_TYPE = CHOOSEFONTAPIW

#IF %DEF(%UNICODE)
   MACRO CHOOSEFONTAPI = CHOOSEFONTAPIW
   MACRO tagCHOOSEFONT = CHOOSEFONTAPIW
   ' // For compatibility with the PB includes
   MACRO CHOOSEFONT_TYPE = CHOOSEFONTAPIW
#ELSE
   MACRO CHOOSEFONTAPI = CHOOSEFONTAPIA
   MACRO tagCHOOSEFONT = CHOOSEFONTAPIA
   ' // For compatibility with the PB includes
   MACRO CHOOSEFONT_TYPE = CHOOSEFONTAPIA
#ENDIF

DECLARE FUNCTION ChooseFontA IMPORT "COMDLG32.DLL" ALIAS "ChooseFontA" ( _
   BYREF lpcf AS CHOOSEFONTAPIA _                       ' __inout LPCHOOSEFONTA lpcf
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION ChooseFontW IMPORT "COMDLG32.DLL" ALIAS "ChooseFontW" ( _
   BYREF lpcf AS CHOOSEFONTAPIW _                       ' __inout LPCHOOSEFONTW lpcf
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO ChooseFont = ChooseFontW
#ELSE
   MACRO ChooseFont = ChooseFontA
#ENDIF

' // Note: The remed equates are predefined in the compiler.
'%CF_SCREENFONTS                 = &H00000001???
'%CF_PRINTERFONTS                = &H00000002???
'%CF_BOTH                        = %CF_SCREENFONTS OR %CF_PRINTERFONTS
'%CF_SHOWHELP                    = &H00000004???
%CF_ENABLEHOOK                  = &H00000008???
%CF_ENABLETEMPLATE              = &H00000010???
%CF_ENABLETEMPLATEHANDLE        = &H00000020???
'%CF_INITTOLOGFONTSTRUCT         = &H00000040???
'%CF_USESTYLE                    = &H00000080???
'%CF_EFFECTS                     = &H00000100???
'%CF_APPLY                       = &H00000200???
'%CF_ANSIONLY                    = &H00000400???
'#if(WINVER >= 0x0400)
'%CF_SCRIPTSONLY                 = %CF_ANSIONLY
'#endif /* WINVER >= 0x0400 */
'%CF_NOVECTORFONTS               = &H00000800???
%CF_NOOEMFONTS                  = %CF_NOVECTORFONTS
'%CF_NOSIMULATIONS               = &H00001000???
'%CF_LIMITSIZE                   = &H00002000???
'%CF_FIXEDPITCHONLY              = &H00004000???
'%CF_WYSIWYG                     = &H00008000??? ' must also have CF_SCREENFONTS & CF_PRINTERFONTS
'%CF_FORCEFONTEXIST              = &H00010000???
'%CF_SCALABLEONLY                = &H00020000???
'%CF_TTONLY                      = &H00040000???
'%CF_NOFACESEL                   = &H00080000???
'%CF_NOSTYLESEL                  = &H00100000???
'%CF_NOSIZESEL                   = &H00200000???
'#if(WINVER >= 0x0400)
'%CF_SELECTSCRIPT                = &H00400000???
'%CF_NOSCRIPTSEL                 = &H00800000???
'%CF_NOVERTFONTS                 = &H01000000???
'#endif /* WINVER >= 0x0400 */
'#if(WINVER >= 0x0601)
%CF_INACTIVEFONTS               = &H02000000???
'#endif /* WINVER >= 0x0601 */

'// these are extra nFontType bits that are added to what is returned to the
'// EnumFonts callback routine

%SIMULATED_FONTTYPE             = &H8000??
%PRINTER_FONTTYPE               = &H4000
%SCREEN_FONTTYPE                = &H2000
%BOLD_FONTTYPE                  = &H0100
%ITALIC_FONTTYPE                = &H0200
%REGULAR_FONTTYPE               = &H0400

'// EnumFonts callback routine only uses these bits, so we can use the rest

'// #define RASTER_FONTTYPE     0x001
'// #define DEVICE_FONTTYPE     0x002
'// #define TRUETYPE_FONTTYPE   0x004

'#if (NTDDI_VERSION >= NTDDI_WIN2K)
%PS_OPENTYPE_FONTTYPE           = &H10000
%TT_OPENTYPE_FONTTYPE           = &H20000
%TYPE1_FONTTYPE                 = &H40000
'#endif // (NTDDI_VERSION >= NTDDI_WIN2K)
'#if(WINVER >= 0x0601)
%SYMBOL_FONTTYPE                = &H80000
'#endif /* WINVER >= 0x0601 */

%WM_CHOOSEFONT_GETLOGFONT       = %WM_USER + 1
%WM_CHOOSEFONT_SETLOGFONT       = %WM_USER + 101
%WM_CHOOSEFONT_SETFLAGS         = %WM_USER + 102


'// strings used to obtain unique window message for communication
'// between dialog and caller

$LBSELCHSTRING  = "commdlg_LBSelChangedNotify"
$SHAREVISTRING  = "commdlg_ShareViolation"
$FILEOKSTRING   = "commdlg_FileNameOK"
$COLOROKSTRING  = "commdlg_ColorOK"
$SETRGBSTRING   = "commdlg_SetRGBColor"
$HELPMSGSTRING  = "commdlg_help"
$FINDMSGSTRING  = "commdlg_FindReplace"

$LBSELCHSTRINGA = $LBSELCHSTRING
$SHAREVISTRINGA = $SHAREVISTRING
$FILEOKSTRINGA  = $FILEOKSTRING
$COLOROKSTRINGA = $COLOROKSTRING
$SETRGBSTRINGA  = $SETRGBSTRING
$HELPMSGSTRINGA = $HELPMSGSTRING
$FINDMSGSTRINGA = $FINDMSGSTRING

$$LBSELCHSTRING = "commdlg_LBSelChangedNotify"$$
$$SHAREVISTRING = "commdlg_ShareViolation"$$
$$FILEOKSTRING  = "commdlg_FileNameOK"$$
$$COLOROKSTRING = "commdlg_ColorOK"$$
$$SETRGBSTRING  = "commdlg_SetRGBColor"$$
$$HELPMSGSTRING = "commdlg_help"$$
$$FINDMSGSTRING = "commdlg_FindReplace"$$

$$LBSELCHSTRINGW = $$LBSELCHSTRING
$$SHAREVISTRINGW = $$SHAREVISTRING
$$FILEOKSTRINGW  = $$FILEOKSTRING
$$COLOROKSTRINGW = $$COLOROKSTRING
$$SETRGBSTRINGW  = $$SETRGBSTRING
$$HELPMSGSTRINGW = $$HELPMSGSTRING
$$FINDMSGSTRINGW = $$FINDMSGSTRING

#IF %DEF(%UNICODE)
MACRO LBSELCHSTRING = $$LBSELCHSTRING
MACRO SHAREVISTRING = $$SHAREVISTRING
MACRO FILEOKSTRING  = $$FILEOKSTRING
MACRO COLOROKSTRING = $$COLOROKSTRING
MACRO SETRGBSTRING  = $$SETRGBSTRING
MACRO HELPMSGSTRING = $$HELPMSGSTRING
MACRO FINDMSGSTRING = $$FINDMSGSTRING
#ELSE
MACRO LBSELCHSTRING = $LBSELCHSTRING
MACRO SHAREVISTRING = $SHAREVISTRING
MACRO FILEOKSTRING  = $FILEOKSTRING
MACRO COLOROKSTRING = $COLOROKSTRING
MACRO SETRGBSTRING  = $SETRGBSTRING
MACRO HELPMSGSTRING = $HELPMSGSTRING
MACRO FINDMSGSTRING = $FINDMSGSTRING
#ENDIF

$CFSEPCHAR           = "+"  ' compound file name separator char.
'$FILEOKSTRING        = "commdlg_FileNameOK"
'$FINDMSGSTRING       = "commdlg_FindReplace"
'$HELPMSGSTRING       = "commdlg_help"
'$LBSELCHSTRING       = "commdlg_LBSelChangedNotify"
'$SETRGBSTRING        = "commdlg_SetRGBColor"
'$SHAREVISTRING       = "commdlg_ShareViolation"
$SZDDE_ITEM_ITEMLIST = "TopicItemList"


'// HIWORD values for lParam of commdlg_LBSelChangeNotify message
%CD_LBSELNOITEMS                = &HFFFF??   ' -1
%CD_LBSELCHANGE                 = 0??
%CD_LBSELSUB                    = 1??
%CD_LBSELADD                    = 2??

'typedef UINT_PTR (CALLBACK *LPPRINTHOOKPROC) (hwnd, UINT, WPARAM, LPARAM);
'FUNCTION PRINTHOOKPROC (BYVAL DWORD, BYVAL DWORD, BYVAL DWORD, BYVAL LONG) AS DWORD
'typedef UINT_PTR (CALLBACK *LPSETUPHOOKPROC) (hwnd, UINT, WPARAM, LPARAM);
'FUNCTION SETUPHOOKPROC (BYVAL DWORD, BYVAL DWORD, BYVAL DWORD, BYVAL LONG) AS DWORD

TYPE PRINTDLGAPIA
   lStructSize              AS DWORD        ' DWORD            lStructSize;
   hwndOwner                AS DWORD        ' hwnd             hwndOwner;
   hDevMode                 AS DWORD        ' HGLOBAL          hDevMode;
   hDevNames                AS DWORD        ' HGLOBAL          hDevNames;
   hDC                      AS DWORD        ' HDC              hDC;
   Flags                    AS DWORD        ' DWORD            Flags;
   nFromPage                AS WORD         ' WORD             nFromPage;
   nToPage                  AS WORD         ' WORD             nToPage;
   nMinPage                 AS WORD         ' WORD             nMinPage;
   nMaxPage                 AS WORD         ' WORD             nMaxPage;
   nCopies                  AS WORD         ' WORD             nCopies;
   hInstance                AS DWORD        ' HINSTANCE        hInstance;
   lCustData                AS LONG         ' LPARAM           lCustData;
   lpfnPrintHook            AS DWORD        ' LPPRINTHOOKPROC  lpfnPrintHook;
   lpfnSetupHook            AS DWORD        ' LPSETUPHOOKPROC  lpfnSetupHook;
   lpPrintTemplateName      AS ASCIIZ PTR   ' LPCSTR           lpPrintTemplateName;
   lpPrintSetupTemplateName AS ASCIIZ PTR   ' LPCSTR           lpSetupTemplateName;
   hPrintTemplate           AS DWORD        ' HGLOBAL          hPrintTemplate;
   hSetupTemplate           AS DWORD        ' HGLOBAL          hSetupTemplate;
END TYPE

TYPE PRINTDLGAPIW
   lStructSize              AS DWORD        ' DWORD            lStructSize;
   hwndOwner                AS DWORD        ' hwnd             hwndOwner;
   hDevMode                 AS DWORD        ' HGLOBAL          hDevMode;
   hDevNames                AS DWORD        ' HGLOBAL          hDevNames;
   hDC                      AS DWORD        ' HDC              hDC;
   Flags                    AS DWORD        ' DWORD            Flags;
   nFromPage                AS WORD         ' WORD             nFromPage;
   nToPage                  AS WORD         ' WORD             nToPage;
   nMinPage                 AS WORD         ' WORD             nMinPage;
   nMaxPage                 AS WORD         ' WORD             nMaxPage;
   nCopies                  AS WORD         ' WORD             nCopies;
   hInstance                AS DWORD        ' HINSTANCE        hInstance;
   lCustData                AS LONG         ' LPARAM           lCustData;
   lpfnPrintHook            AS DWORD        ' LPPRINTHOOKPROC  lpfnPrintHook;
   lpfnSetupHook            AS DWORD        ' LPSETUPHOOKPROC  lpfnSetupHook;
   lpPrintTemplateName      AS WSTRINGZ PTR ' LPCWSTR          lpPrintTemplateName;
   lpPrintSetupTemplateName AS WSTRINGZ PTR ' LPCWSTR          lpSetupTemplateName;
   hPrintTemplate           AS DWORD        ' HGLOBAL          hPrintTemplate;
   hSetupTemplate           AS DWORD        ' HGLOBAL          hSetupTemplate;
END TYPE

MACRO tagPRINTDLGA   = PRINTDLGAPIA
MACRO tagPRINTDLGW   = PRINTDLGAPIW
MACRO tagPDA         = PRINTDLGAPIA
MACRO tagPDW         = PRINTDLGAPIW
' // For compatibility with the PB includes
MACRO PRINTDLGA_TYPE = PRINTDLGAPIA
MACRO PRINTDLGW_TYPE = PRINTDLGAPIW

#IF %DEF(%UNICODE)
   MACRO PRINTDLGAPI   = PRINTDLGAPIW
   MACRO tagPRINTDLG   = PRINTDLGAPIW
   MACRO tagPD         = PRINTDLGAPIW
   ' // For compatibility with the PB includes
   MACRO PRINTDLG_TYPE = PRINTDLGAPIW
#ELSE
   MACRO PRINTDLGAPI   = PRINTDLGAPIA
   MACRO tagPRINTDLG   = PRINTDLGAPIA
   MACRO tagPD         = PRINTDLGAPIA
   ' // For compatibility with the PB includes
   MACRO PRINTDLG_TYPE = PRINTDLGAPIA
#ENDIF

DECLARE FUNCTION PrintDlgA IMPORT "COMDLG32.DLL" ALIAS "PrintDlgA" ( _
   BYREF lpPd AS ANY _                                  ' __inout LPPRINTDLGA lpPd
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION PrintDlgW IMPORT "COMDLG32.DLL" ALIAS "PrintDlgW" ( _
   BYREF lpPd AS ANY _                                  ' __inout LPPRINTDLGW lpPd
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO PrintDlg = PrintDlgW
#ELSE
   MACRO PrintDlg = PrintDlgA
#ENDIF

'#if(WINVER >= 0x0500)

'#ifdef STDMETHOD

'//-------------------------------------------------------------------------
'//
'//  IPrintDialogCallback Interface
'//
'//  IPrintDialogCallback::InitDone()
'//    This function is called by PrintDlgEx when the system has finished
'//    initializing the main page of the print dialog.  This function
'//    should return S_OK if it has processed the action or S_FALSE to let
'//    PrintDlgEx perform the default action.
'//
'//  IPrintDialogCallback::SelectionChange()
'//    This function is called by PrintDlgEx when a selection change occurs
'//    in the list view that displays the currently installed printers.
'//    This function should return S_OK if it has processed the action or
'//    S_FALSE to let PrintDlgEx perform the default action.
'//
'//  IPrintDialogCallback::HandleMessage(hDlg, uMsg, wParam, lParam, pResult)
'//    This function is called by PrintDlgEx when a message is sent to the
'//    child window of the main page of the print dialog.  This function
'//    should return S_OK if it has processed the action or S_FALSE to let
'//    PrintDlgEx perform the default action.
'//
'//  IObjectWithSite::SetSite(punkSite)
'//    IPrintDialogCallback usually paired with IObjectWithSite.
'//    Provides the IUnknown pointer of the site to QI for the
'//    IPrintDialogServices interface.
'//
'//-------------------------------------------------------------------------

'#undef  INTERFACE
'#define INTERFACE   IPrintDialogCallback

'DECLARE_INTERFACE_(IPrintDialogCallback, IUnknown)
'{
'    // *** IUnknown methods ***
'    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
'    STDMETHOD_(ULONG, AddRef) (THIS) PURE;
'    STDMETHOD_(ULONG, Release) (THIS) PURE;

'    // *** IPrintDialogCallback methods ***
'    STDMETHOD(InitDone) (THIS) PURE;
'    STDMETHOD(SelectionChange) (THIS) PURE;
'    STDMETHOD(HandleMessage) (THIS_ hwnd hDlg, UINT uMsg, WPARAM wParam, LPARAM lParam, LRESULT *pResult) PURE;
'};

' ########################################################################################
' Interface name = IPrintDialogCallback
' IID = {5852A2C3-6530-11D1-B6A3-0000F8757BF9}
' Inherited interface = IUnknown
' ########################################################################################

INTERFACE IPrintDialogCallback $IID_IPrintDialogCallback

   INHERIT IUnknown

   ' ========================================================================================
   METHOD InitDone ( _                                  ' VTable offset = 12
   ) AS LONG                                            ' HRESULT
   ' ========================================================================================
   METHOD SelectionChange ( _                           ' VTable offset = 16
   ) AS LONG                                            ' HRESULT
   ' ========================================================================================
   METHOD HandleMessage ( _                             ' VTable offset = 20
     BYVAL hDlg AS DWORD _                              ' __in  hwnd hDlg
   , BYVAL uMsg AS DWORD _                              ' __in  UINT uMsg
   , BYVAL wParam AS DWORD _                            ' __in  WPARAM wParam
   , BYVAL lParam AS LONG _                             ' __in  LPARAM lParam
   , BYREF pResult AS LONG _                            ' __out LRESULT *pResult
   ) AS LONG                                            ' HRESULT
   ' ========================================================================================

END INTERFACE

'//-------------------------------------------------------------------------
'//
'//  IPrintDialogServices Interface
'//
'//  IPrintDialogServices::GetCurrentDevMode(pDevMode, pcbSize)
'//    Returns the DEVMODE structure for the currently selected printer.
'//
'//  IPrintDialogServices::GetCurrentPrinterName(pPrinterName, pcchSize)
'//    Returns the printer name for the currently selected printer.
'//
'//  IPrintDialogServices::GetCurrentPortName(pPortName, pcchSize)
'//    Returns the port name for the currently selected printer.
'//
'//-------------------------------------------------------------------------

'#undef  INTERFACE
'#define INTERFACE   IPrintDialogServices

'DECLARE_INTERFACE_(IPrintDialogServices, IUnknown)
'{
'    // *** IUnknown methods ***
'    STDMETHOD(QueryInterface) (THIS_ REFIID riid, LPVOID *ppvObj) PURE;
'    STDMETHOD_(ULONG, AddRef) (THIS) PURE;
'    STDMETHOD_(ULONG, Release) (THIS) PURE;

'    // *** IPrintDialogServices methods ***
'    STDMETHOD(GetCurrentDevMode) (THIS_ LPDEVMODE pDevMode, UINT *pcbSize) PURE;
'    STDMETHOD(GetCurrentPrinterName) (THIS_ LPTSTR pPrinterName, UINT *pcchSize) PURE;
'    STDMETHOD(GetCurrentPortName) (THIS_ LPTSTR pPortName, UINT *pcchSize) PURE;
'};

' ########################################################################################
' Interface name = IPrintDialogServices
' IID = {509AAEDA-5639-11D1-B6A1-0000F8757BF9}
' Inherited interface = IUnknown
' ########################################################################################

INTERFACE IPrintDialogServices $IID_IPrintDialogServices

   INHERIT IUnknown

   ' ========================================================================================
   ' Note: We have to use pointers to byte buffers because the same methods are used for
   ' ansi and unicode.
   ' ========================================================================================

   ' ========================================================================================
   ' pDevMode = A pointer to a buffer that receives a DEVMODE structure containing information
   ' about the currently selected printer.
   ' pcbSize = On input, the variable specifies the size, in bytes, of the buffer pointed to
   ' by the lpDevMode parameter. On output, the variable contains the number of bytes written
   ' to lpDevMode.
   ' If the size is zero on input, the function returns the required buffer size (in bytes)
   ' in pcbSize and does not use the lpDevMode buffer.
   ' ========================================================================================
   METHOD GetCurrentDevMode ( _                         ' VTable offset = 12
     BYVAL pDevMode AS BYTE PTR _                       ' __out LPDEVMODE pDevMode
   , BYREF pcbSize AS DWORD _                           ' __out UINT *pcbSize
   ) AS LONG                                            ' HRESULT
   ' ========================================================================================

   ' ========================================================================================
   ' pPrinterName = A pointer to a buffer that receives the name of the current port.
   ' pcchSize = On input, the variable specifies the size, in characters, of the buffer pointed
   ' to by the lpPortName parameter. On output, the variable contains the number of bytes (ANSI)
   ' or characters (Unicode), including the terminating null character, written to the buffer.
   ' If the size is zero on input, the function returns the required buffer size (in bytes or
   ' characters) in pcchSize and does not use the lpPortName buffer.
   ' ========================================================================================
   METHOD GetCurrentPrinterName ( _                     ' VTable offset = 16
     BYVAL pPrinterName AS BYTE PTR _                   ' __out LPTSTR pPrinterName
   , BYREF pcchSize AS DWORD _                          ' __out UINT *pcchSize
   ) AS LONG                                            ' HRESULT
   ' ========================================================================================

   ' ========================================================================================
   ' pPortName = A pointer to a buffer that receives the name of the currently selected printer.
   ' pcchSize = On input, the variable specifies the size, in characters, of the buffer
   ' pointed to by the lpPrinterName parameter. On output, the variable contains the number
   ' of bytes (ANSI) or characters (Unicode), including the terminating null character,
   ' written to the buffer.
   ' pcchSize = If the size is zero on input, the function returns the required buffer size
   ' (in bytes or characters) in pcchSize and does not use the lpPrinterName buffer.
   ' ========================================================================================
   METHOD GetCurrentPortName ( _                        ' VTable offset = 20
     BYVAL pPortName AS BYTE PTR _                      ' __out LPTSTR pPortName
   , BYREF pcchSize AS DWORD _                          ' __out UINT *pcchSize
   ) AS LONG                                            ' HRESULT
   ' ========================================================================================

END INTERFACE

'//
'//  Page Range structure for PrintDlgEx.
'//

TYPE PRINTPAGERANGE
   nFromPage AS DWORD                  ' DWORD  nFromPage;
   nToPage   AS DWORD                  ' DWORD  nToPage;
END TYPE

'//
'//  PrintDlgEx structure.
'//

TYPE PRINTDLGEXAPIA
   lStructSize         AS DWORD               ' DWORD                 lStructSize;          // size of structure in bytes
   hwndOwner           AS DWORD               ' hwnd                  hwndOwner;            // caller's window handle
   hDevMode            AS DWORD               ' HGLOBAL               hDevMode;             // handle to DevMode
   hDevNames           AS DWORD               ' HGLOBAL               hDevNames;            // handle to DevNames
   hDC                 AS DWORD               ' HDC                   hDC;                  // printer DC/IC or NULL
   Flags               AS DWORD               ' DWORD                 Flags;                // PD_ flags
   Flags2              AS DWORD               ' DWORD                 Flags2;               // reserved
   ExclusionFlags      AS DWORD               ' DWORD                 ExclusionFlags;       // items to exclude from driver pages
   nPageRanges         AS DWORD               ' DWORD                 nPageRanges;          // number of page ranges
   nMaxPageRanges      AS DWORD               ' DWORD                 nMaxPageRanges;       // max number of page ranges
   lpPageRanges        AS PRINTPAGERANGE PTR  ' LPPRINTPAGERANGE      lpPageRanges;         // array of page ranges
   nMinPage            AS DWORD               ' DWORD                 nMinPage;             // min page number
   nMaxPage            AS DWORD               ' DWORD                 nMaxPage;             // max page number
   nCopies             AS DWORD               ' DWORD                 nCopies;              // number of copies
   hInstance           AS DWORD               ' HINSTANCE             hInstance;            // instance handle
   lpPrintTemplateName AS ASCIIZ PTR          ' LPCSTR                lpPrintTemplateName;  // template name for app specific area
   lpCallback          AS DWORD               ' LPUNKNOWN             lpCallback;           // app callback interface
   nPropertyPages      AS DWORD               ' DWORD                 nPropertyPages;       // number of app property pages in lphPropertyPages
   lphPropertyPages    AS DWORD PTR           ' HPROPSHEETPAGE       *lphPropertyPages;     // array of app property page handles
   nStartPage          AS DWORD               ' DWORD                 nStartPage;           // start page id
   dwResultAction      AS DWORD               ' DWORD                 dwResultAction;       // result action if S_OK is returned
END TYPE

TYPE PRINTDLGEXAPIW
   lStructSize         AS DWORD               ' DWORD                 lStructSize;          // size of structure in bytes
   hwndOwner           AS DWORD               ' hwnd                  hwndOwner;            // caller's window handle
   hDevMode            AS DWORD               ' HGLOBAL               hDevMode;             // handle to DevMode
   hDevNames           AS DWORD               ' HGLOBAL               hDevNames;            // handle to DevNames
   hDC                 AS DWORD               ' HDC                   hDC;                  // printer DC/IC or NULL
   Flags               AS DWORD               ' DWORD                 Flags;                // PD_ flags
   Flags2              AS DWORD               ' DWORD                 Flags2;               // reserved
   ExclusionFlags      AS DWORD               ' DWORD                 ExclusionFlags;       // items to exclude from driver pages
   nPageRanges         AS DWORD               ' DWORD                 nPageRanges;          // number of page ranges
   nMaxPageRanges      AS DWORD               ' DWORD                 nMaxPageRanges;       // max number of page ranges
   lpPageRanges        AS PRINTPAGERANGE PTR  ' LPPRINTPAGERANGE      lpPageRanges;         // array of page ranges
   nMinPage            AS DWORD               ' DWORD                 nMinPage;             // min page number
   nMaxPage            AS DWORD               ' DWORD                 nMaxPage;             // max page number
   nCopies             AS DWORD               ' DWORD                 nCopies;              // number of copies
   hInstance           AS DWORD               ' HINSTANCE             hInstance;            // instance handle
   lpPrintTemplateName AS WSTRINGZ PTR        ' LPCWSTR               lpPrintTemplateName;  // template name for app specific area
   lpCallback          AS DWORD               ' LPUNKNOWN             lpCallback;           // app callback interface
   nPropertyPages      AS DWORD               ' DWORD                 nPropertyPages;       // number of app property pages in lphPropertyPages
   lphPropertyPages    AS DWORD PTR           ' HPROPSHEETPAGE       *lphPropertyPages;     // array of app property page handles
   nStartPage          AS DWORD               ' DWORD                 nStartPage;           // start page id
   dwResultAction      AS DWORD               ' DWORD                 dwResultAction;       // result action if S_OK is returned
END TYPE

MACRO tagPRINTDLGEXA = PRINTDLGEXAPIA
MACRO tagPRINTDLGEXW = PRINTDLGEXAPIW
MACRO tagPDEXA = PRINTDLGEXAPIA
MACRO tagPDEXW = PRINTDLGEXAPIW
' // For compatibility with the PB includes
MACRO PRINTDLGEXA_TYPE = PRINTDLGEXAPIA
MACRO PRINTDLGEXW_TYPE = PRINTDLGEXAPIW

#IF %DEF(%UNICODE)
   MACRO PRINTDLGEXAPI   = PRINTDLGEXAPIW
   MACRO tagPRINTDLGEX   = PRINTDLGEXAPIW
   MACRO tagPDEX         = PRINTDLGEXAPIW
   ' // For compatibility with the PB includes
   MACRO PRINTDLGEX_TYPE = PRINTDLGEXAPIA
#ELSE
   MACRO PRINTDLGEXAPI   = PRINTDLGEXAPIA
   MACRO tagPRINTDLGEX   = PRINTDLGEXAPIA
   MACRO tagPDEX         = PRINTDLGEXAPIA
   ' // For compatibility with the PB includes
   MACRO PRINTDLGEX_TYPE = PRINTDLGEXAPIW
#ENDIF

DECLARE FUNCTION PrintDlgExA IMPORT "COMDLG32.DLL" ALIAS "PrintDlgExA" ( _
   BYREF lpPde AS ANY _                                 ' __inout LPPRINTDLGEXA lpPde
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION PrintDlgExW IMPORT "COMDLG32.DLL" ALIAS "PrintDlgExW" ( _
   BYREF lpPde AS ANY _                                 ' __inout LPPRINTDLGEXW lpPde
 ) AS LONG                                              ' HRESULT

#IF %DEF(%UNICODE)
   MACRO PrintDlgEx = PrintDlgExW
#ELSE
   MACRO PrintDlgEx = PrintDlgExA
#ENDIF

'#endif

'#endif /* WINVER >= 0x0500 */

'//
'//  Flags for PrintDlg and PrintDlgEx.
'//
'%PD_ALLPAGES                    = &H00000000???
'%PD_SELECTION                   = &H00000001???
'%PD_PAGENUMS                    = &H00000002???
'%PD_NOSELECTION                 = &H00000004???
'%PD_NOPAGENUMS                  = &H00000008???
'%PD_COLLATE                     = &H00000010???
'%PD_PRINTTOFILE                 = &H00000020???
'%PD_PRINTSETUP                  = &H00000040???
'%PD_NOWARNING                   = &H00000080???
'%PD_RETURNDC                    = &H00000100???
'%PD_RETURNIC                    = &H00000200???
'%PD_RETURNDEFAULT               = &H00000400???
'%PD_SHOWHELP                    = &H00000800???
'%PD_ENABLEPRINTHOOK             = &H00001000???
'%PD_ENABLESETUPHOOK             = &H00002000???
'%PD_ENABLEPRINTTEMPLATE         = &H00004000???
'%PD_ENABLESETUPTEMPLATE         = &H00008000???
'%PD_ENABLEPRINTTEMPLATEHANDLE   = &H00010000???
'%PD_ENABLESETUPTEMPLATEHANDLE   = &H00020000???
'%PD_USEDEVMODECOPIES            = &H00040000???
'%PD_USEDEVMODECOPIESANDCOLLATE  = &H00040000???
'%PD_DISABLEPRINTTOFILE          = &H00080000???
'%PD_HIDEPRINTTOFILE             = &H00100000???
'%PD_NONETWORKBUTTON             = &H00200000???
'#if(WINVER >= 0x0500)
'%PD_CURRENTPAGE                 = &H00400000???
'%PD_NOCURRENTPAGE               = &H00800000???
'%PD_EXCLUSIONFLAGS              = &H01000000???
'%PD_USELARGETEMPLATE            = &H10000000???
'#endif /* WINVER >= 0x0500 */

'#if(WINVER >= 0x0500)

'//
'//  Exclusion flags for PrintDlgEx.
'//
%PD_EXCL_COPIESANDCOLLATE = %DM_COPIES OR %DM_COLLATE

'//
'//  Define the start page for the print dialog when using PrintDlgEx.
'//
%START_PAGE_GENERAL           = &HFFFFFFFF???

'//
'//  Result action ids for PrintDlgEx.
'//
'%PD_RESULT_CANCEL   = 0
'%PD_RESULT_PRINT    = 1
'%PD_RESULT_APPLY    = 2

'#endif /* WINVER >= 0x0500 */

'//
'//  Device Names structure for PrintDlg and PrintDlgEx.
'//

TYPE DEVNAMES
   wDriverOffset AS WORD               ' WORD wDriverOffset;
   wDeviceOffset AS WORD               ' WORD wDeviceOffset;
   wOutputOffset AS WORD               ' WORD wOutputOffset;
   wDefault      AS WORD               ' WORD wDefault;
END TYPE

%DN_DEFAULTPRN           = &H0001

'WINCOMMDLGAPI DWORD APIENTRY CommDlgExtendedError(VOID);
DECLARE FUNCTION CommDlgExtendedError IMPORT "COMDLG32.DLL" ALIAS "CommDlgExtendedError" ( _
 ) AS DWORD                                             ' DWORD

'#if(WINVER >= 0x0400)
%WM_PSD_PAGESETUPDLG     = %WM_USER
%WM_PSD_FULLPAGERECT     = %WM_USER+1
%WM_PSD_MINMARGINRECT    = %WM_USER+2
%WM_PSD_MARGINRECT       = %WM_USER+3
%WM_PSD_GREEKTEXTRECT    = %WM_USER+4
%WM_PSD_ENVSTAMPRECT     = %WM_USER+5
%WM_PSD_YAFULLPAGERECT   = %WM_USER+6

'typedef UINT_PTR (CALLBACK* LPPAGEPAINTHOOK)( hwnd, UINT, WPARAM, LPARAM );
'FUNCTION PAGEPAINTHOOK (BYVAL DWORD, BYVAL DWORD, BYVAL DWORD, BYVAL LONG) AS DWORD
'typedef UINT_PTR (CALLBACK* LPPAGESETUPHOOK)( hwnd, UINT, WPARAM, LPARAM );
'FUNCTION PAGESETUPHOOK (BYVAL DWORD, BYVAL DWORD, BYVAL DWORD, BYVAL LONG) AS DWORD

TYPE PAGESETUPDLGAPIA
   lStructSize             AS DWORD        ' DWORD           lStructSize;
   hwndOwner               AS DWORD        ' hwnd            hwndOwner;
   hDevMode                AS DWORD        ' HGLOBAL         hDevMode;
   hDevNames               AS DWORD        ' HGLOBAL         hDevNames;
   Flags                   AS DWORD        ' DWORD           Flags;
   ptPaperSize             AS POINT        ' POINT           ptPaperSize;
   rtMinMargin             AS RECT         ' RECT            rtMinMargin;
   rtMargin                AS RECT         ' RECT            rtMargin;
   hInstance               AS DWORD        ' HINSTANCE       hInstance;
   lCustData               AS LONG         ' LPARAM          lCustData;
   lpfnPageSetupHook       AS DWORD        ' LPPAGESETUPHOOK lpfnPageSetupHook;
   lpfnPagePaintHook       AS DWORD        ' LPPAGEPAINTHOOK lpfnPagePaintHook;
   lpPageSetupTemplateName AS ASCIIZ PTR   ' LPCSTR          lpPageSetupTemplateName;
   hPageSetupTemplate      AS DWORD        ' HGLOBAL         hPageSetupTemplate;
END TYPE

TYPE PAGESETUPDLGAPIW
   lStructSize             AS DWORD        ' DWORD           lStructSize;
   hwndOwner               AS DWORD        ' hwnd            hwndOwner;
   hDevMode                AS DWORD        ' HGLOBAL         hDevMode;
   hDevNames               AS DWORD        ' HGLOBAL         hDevNames;
   Flags                   AS DWORD        ' DWORD           Flags;
   ptPaperSize             AS POINT        ' POINT           ptPaperSize;
   rtMinMargin             AS RECT         ' RECT            rtMinMargin;
   rtMargin                AS RECT         ' RECT            rtMargin;
   hInstance               AS DWORD        ' HINSTANCE       hInstance;
   lCustData               AS LONG         ' LPARAM          lCustData;
   lpfnPageSetupHook       AS DWORD        ' LPPAGESETUPHOOK lpfnPageSetupHook;
   lpfnPagePaintHook       AS DWORD        ' LPPAGEPAINTHOOK lpfnPagePaintHook;
   lpPageSetupTemplateName AS WSTRINGZ PTR ' LPCWSTR         lpPageSetupTemplateName;
   hPageSetupTemplate      AS DWORD        ' HGLOBAL         hPageSetupTemplate;
END TYPE

MACRO tagPAGESETUPDLGA = PAGESETUPDLGAPIA
MACRO tagPAGESETUPDLGW = PAGESETUPDLGAPIW
MACRO tagPSDA          = PAGESETUPDLGAPIA
MACRO tagPSDW          = PAGESETUPDLGAPIW
' // For compatibility with the PB includes
MACRO PAGESETUPDLGA_TYPE = PRINTDLGEXAPIA
MACRO PAGESETUPDLGW_TYPE = PRINTDLGEXAPIW

#IF %DEF(%UNICODE)
   MACRO PAGESETUPDLGAPI   = PAGESETUPDLGAPIW
   MACRO tagPAGESETUPDLG   = PAGESETUPDLGAPIW
   MACRO tagPSD            = PAGESETUPDLGAPIW
   ' // For compatibility with the PB includes
   MACRO PAGESETUPDLG_TYPE = PAGESETUPDLGAPIW
#ELSE
   MACRO PAGESETUPDLGAPI   = PAGESETUPDLGAPIA
   MACRO tagPAGESETUPDLG   = PAGESETUPDLGAPIA
   MACRO tagPSD            = PAGESETUPDLGAPIA
   ' // For compatibility with the PB includes
   MACRO PAGESETUPDLG_TYPE = PAGESETUPDLGAPIA
#ENDIF

DECLARE FUNCTION PageSetupDlgA IMPORT "COMDLG32.DLL" ALIAS "PageSetupDlgA" ( _
   BYREF lpPageSetupDlg AS ANY _                        ' __inout LPPAGESETUPDLGA lpPageSetupDlg
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION PageSetupDlgW IMPORT "COMDLG32.DLL" ALIAS "PageSetupDlgW" ( _
   BYREF lpPageSetupDlg AS ANY _                        ' __inout LPPAGESETUPDLGW lpPageSetupDlg
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO PageSetupDlg = PageSetupDlgW
#ELSE
   MACRO PageSetupDlg = PageSetupDlgA
#ENDIF

%PSD_DEFAULTMINMARGINS             = &H00000000??? ' default (printer's)
%PSD_INWININIINTLMEASURE           = &H00000000??? ' 1st of 4 possible

%PSD_MINMARGINS                    = &H00000001??? ' use caller's
%PSD_MARGINS                       = &H00000002??? ' use caller's
%PSD_INTHOUSANDTHSOFINCHES         = &H00000004??? ' 2nd of 4 possible
%PSD_INHUNDREDTHSOFMILLIMETERS     = &H00000008??? ' 3rd of 4 possible
%PSD_DISABLEMARGINS                = &H00000010???
%PSD_DISABLEPRINTER                = &H00000020???
%PSD_NOWARNING                     = &H00000080??? ' must be same as PD_*
%PSD_DISABLEORIENTATION            = &H00000100???
%PSD_RETURNDEFAULT                 = &H00000400??? ' must be same as PD_*
%PSD_DISABLEPAPER                  = &H00000200???
%PSD_SHOWHELP                      = &H00000800??? ' must be same as PD_*
%PSD_ENABLEPAGESETUPHOOK           = &H00002000??? ' must be same as PD_*
%PSD_ENABLEPAGESETUPTEMPLATE       = &H00008000??? ' must be same as PD_*
%PSD_ENABLEPAGESETUPTEMPLATEHANDLE = &H00020000??? ' must be same as PD_*
%PSD_ENABLEPAGEPAINTHOOK           = &H00040000???
%PSD_DISABLEPAGEPAINTING           = &H00080000???
%PSD_NONETWORKBUTTON               = &H00200000??? ' must be same as PD_*

'#IF NOT %DEF(%NORUNFILEDLG)

' ========================================================================================
' Helper procedure to activate the run file dialog.
' * hwndOwner identifies the window that owns the dialog box.
' * hIcon is the handle of the icon that will be displayed in the dialog. If it is NULL,
'   the default icon will be used.
' * lpstrDirectory points to a string that specifies the working directory.
' * lpstrTitle points to a string to be placed in the title bar of the dialog box. If it
'   is NULL, the default title is used.
' * lpstrDescription points to a string that is displayed in the dialog, briefly informing
'   the user what to do. If it is NULL, the default description is used.
' * uFlags is a set of bit flags that specify other properties of the dialog.
'     - RFF_NOBROWSE       &H01    Removes the browse button.
'     - RFF_NODEFAULT      &H02    No default item selected.
'     - RFF_CALCDIRECTORY  &H04    Calculates the working directory from the file name.
'     - RFF_NOLABEL        &H08    Removes the edit box label.
'     - RFF_NOSEPARATEMEM  &H20    Removes the Separate Memory Space check box (Windows NT only).
' A nice feature of this dialog is that it allows you to control which applications the
' user may run. When the user selects the OK button, your parent window is sent a
' notification with details of the program that is about to be started. The notification is
' in the form of a WM_NOTIFY message with the notification code set to RFN_VALIDATE (-510)
' and the lParam pointing to an NM_RUNFILEDLG structure.
' Note: The three string parameters, lpstrDirectory, lpstrTitle and lpstrDescription must
' be ansi in Win95/98 and unicode in NT Platforms.
' ========================================================================================

%RFF_NOBROWSE      = &H01   ' Remove the browse button.
%RFF_NODEFAULT     = &H02   ' No default item selected.
%RFF_CALCDIRECTORY = &H04   ' Calculate the working directory from the file name.
%RFF_NOLABEL       = &H08   ' Remove the edit box label.
%RFF_NOSEPARATEMEM = &H20   ' Remove the Separate Memory Space check box, NT only.

%RFN_VALIDATE      = -510

TYPE NM_RUNFILEDLG
  hdr         AS NMHDR          ' NMHDR structure
  lpFile      AS WSTRINGZ PTR   ' LPTSTR (ansi in Win95/98, unicode in NT platforms)
  lpDirectory AS WSTRINGZ PTR   ' LPTSTR (ansi in Win95/98, unicode in NT platforms)
  nShow       AS LONG           ' int
END TYPE

%RF_OK            = &H00    ' Allow the application to run.
%RF_CANCEL        = &H01    ' Cancel the operation and close the dialog.
%RF_RETRY         = &H02    ' Cancel the operation, but leave the dialog open.

' ========================================================================================

'#ENDIF   ' IF NOT %DEF(%NORUNFILEDLG)

'#endif  /* GUID_DEFS_ONLY */

#IF NOT %DEF(%AFXDLG_INC)
#INCLUDE ONCE "AfxDlg.inc"   ' // Wrapper functions
#ENDIF
