' ########################################################################################
' Microsoft Windows
' File: advpub.inc
' Contents: Interfaces implemented by advpack.dll.
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%ADVPUB_INC = 1

#INCLUDE ONCE "windows.inc"

'/////////////////////////////////////////////////////////////////////////////
'// ENTRY POINT: RunSetupCommand
'//
'// SYNOPSIS:    Execute an install section in an INF file, or execute a
'//              program.  Advanced INF files are supported.
'//
'// RETURN CODES:
'//
'//      S_OK                                 Everything OK, no reboot needed.
'//                                           No EXE to wait for.
'//      S_ASYNCHRONOUS                       Please wait on phEXE.
'//      ERROR_SUCCESS_REBOOT_REQUIRED        Reboot required.
'//      E_INVALIDARG                         NULL specified in szCmdName or szDir
'//      HRESULT_FROM_WIN32(ERROR_OLD_WIN_VERSION) INF's not supported on this OS version
'//      E_UNEXPECTED                         Catastrophic failure(should never happen).
'//      HRESULT_FROM_WIN32(GetLastError())   Anything else
'/////////////////////////////////////////////////////////////////////////////

'#ifndef S_ASYNCHRONOUS
'#define S_ASYNCHRONOUS  _HRESULT_TYPEDEF_(0x401e8L)
'#endif

#IF NOT %DEF(%S_ASYNCHRONOUS)
%S_ASYNCHRONOUS = &H401E8&
#ENDIF

' // Note: In versions of Internet Explorer prior to 6.05, this function is exported
' // as RunSetupCommand.

'#if (_WIN32_IE >= 0x0605)
DECLARE FUNCTION RunSetupCommandA IMPORT "ADVPACK.DLL" ALIAS "RunSetupCommandA" ( _
   BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 , BYREF szCmdName AS ASCIIZ _                          ' __in LPCSTR szCmdName
 , BYREF szInfSection AS ASCIIZ _                       ' __in LPCSTR szInfSection
 , BYREF szDir AS STRINGZ _                             ' __in LPCSTR szDir
 , BYREF lpszTitle AS ASCIIZ _                          ' __in LPCSTR lpszTitle
 , BYREF phEXE AS DWORD _                               ' __out HANDLE *phEXE
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYVAL pvReserved AS DWORD _                          ' __in LPVOID pvReserved
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION RunSetupCommandW IMPORT "ADVPACK.DLL" ALIAS "RunSetupCommandW" ( _
   BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 , BYREF szCmdName AS WSTRINGZ _                        ' __in LPCWSTR szCmdName
 , BYREF szInfSection AS WSTRINGZ _                     ' __in LPCWSTR szInfSection
 , BYREF szDir AS WSTRINGZ _                            ' __in LPCWSTR szDir
 , BYREF lpszTitle AS WSTRINGZ _                        ' __in LPCWSTR lpszTitle
 , BYREF phEXE AS DWORD _                               ' __out HANDLE *phEXE
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYVAL pvReserved AS DWORD _                          ' __in LPVOID pvReserved
 ) AS LONG                                              ' HRESULT
'#endif  // (_WIN32_IE >= 0x0605)

#IF %DEF(%UNICODE)
MACRO RunSetupCommand = RunSetupCommandW
#ELSE
MACRO RunSetupCommand = RunSetupCommandA
#ENDIF

'// FLAGS:

%RSC_FLAG_INF                = 1      ' // exxcute INF install
%RSC_FLAG_SKIPDISKSPACECHECK = 2      ' // Currently does nothing
%RSC_FLAG_QUIET              = 4      ' // quiet mode, no UI
%RSC_FLAG_NGCONV             = 8      ' // don't run groupConv
%RSC_FLAG_UPDHLPDLLS         = 16     ' // force to self-updating on user's system
%RSC_FLAG_DELAYREGISTEROCX   = 512    ' // force delay of ocx registration
%RSC_FLAG_SETUPAPI           = 1024   ' // use setupapi.dll

'// please not adding flag after this.  See LaunchINFSectionEx() flags.

'/////////////////////////////////////////////////////////////////////////////
'// ENTRY POINT: NeedRebootInit
'//
'// SYNOPSIS:    Initializes state for reboot checking.  Call this function
'//              before calling RunSetupCommand.
'// RETURNS:     value required to be passed to NeedReboot()
'/////////////////////////////////////////////////////////////////////////////

DECLARE FUNCTION NeedRebootInit IMPORT "ADVPACK.DLL" ALIAS "NeedRebootInit" ( _
 ) AS DWORD                                             ' DWORD

'/////////////////////////////////////////////////////////////////////////////
'// ENTRY POINT: NeedReboot
'//
'// SYNOPSIS:    Compares stored state with current state to determine if a
'//              reboot is required.
'//      dwRebootCheck   the return value from NeedRebootInit
'//
'// RETURNS:
'//      TRUE            if a reboot is required;
'//      FALSE           otherwise.
'/////////////////////////////////////////////////////////////////////////////

DECLARE FUNCTION NeedReboot IMPORT "ADVPACK.DLL" ALIAS "NeedReboot" ( _
   BYVAL dwRebootCheck AS DWORD _                       ' __in DWORD dwRebootCheck
 ) AS LONG                                              ' BOOL

'/////////////////////////////////////////////////////////////////////////////
'// ENTRY POINT: RebootCheckOnInstall
'//
'// SYNOPSIS:    Check reboot condition if the given INF section is installed.
'//      hwnd    windows handle
'//      pszINF  INF filename with fully qualified path
'//      pszSec  INF section.  NULL is translated as DefaultInstall or DefaultInstall.NT.
'//      dwReserved Not used.
'// RETURN:
'//      S_OK    Reboot needed if INF section is installed.
'//      S_FALSE Reboot is not needed if INF section is installed.
'//      HRESULT of Win 32 errors
'//
'/////////////////////////////////////////////////////////////////////////////

' // Note: In versions of Internet Explorer prior to 6.05, this function is exported
' // as RebootCheckOnInstall.

'#if (_WIN32_IE >= 0x0605)

DECLARE FUNCTION RebootCheckOnInstallA IMPORT "ADVPACK.DLL" ALIAS "RebootCheckOnInstallA" ( _
   BYVAL hwnd AS DWORD _                                ' __in HWND hwnd
 , BYREF pszINF AS ASCIIZ _                             ' __in LPCSTR pszINF
 , BYREF pszSec AS ASCIIZ _                             ' __in LPCSTR pszSec
 , BYVAL dwReserved As DWORD _                          ' __in DWORD dwReserved
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION RebootCheckOnInstallW IMPORT "ADVPACK.DLL" ALIAS "RebootCheckOnInstallW" ( _
   BYVAL hwnd AS DWORD _                                ' __in HWND hwnd
 , BYREF pszINF AS WSTRINGZ _                           ' __in LPCWSTR pszINF
 , BYREF pszSec AS WSTRINGZ _                           ' __in LPCWSTR pszSec
 , BYVAL dwReserved As DWORD _                          ' __in DWORD dwReserved
 ) AS LONG                                              ' HRESULT

'#endif  // (_WIN32_IE >= 0x0605)

#IF %DEF(%UNICODE)
MACRO RebootCheckOnInstall = RebootCheckOnInstallW
#ELSE
MACRO RebootCheckOnInstall = RebootCheckOnInstallA
#ENDIF

'//////////////////////////////////////////////////////////////////////////
'// ENTRY POINT: TranslateInfString
'//
'// SYNOPSIS:    Translates a key value in an INF file, using advanced INF
'//              syntax.
'// RETURN CODES:
'//      S_OK                                 Everything OK.
'//      HRESULT_FROM_WIN32(ERROR_INSUFFICIENT_BUFFER)
'//                                      The buffer size is too small to hold the
'//                                      translated string.  Required size is in *pdwRequiredSize.
'//      E_INVALIDARG                         NULL specified in pszInfFilename, pszTranslateSection,
'//                                      pszTranslateKey, pdwRequiredSize.
'//      HRESULT_FROM_WIN32(ERROR_OLD_WIN_VERSION)
'//                                      OS not supported.
'//      E_UNEXPECTED                         Catastrophic failure -- should never happen.
'//      HRESULT_FROM_WIN32(ERROR_INVALID_PARAMETER)
'//                                      The section or key specified does not exist.
'//      HRESULT_FROM_WIN32(GetLastError())   Anything else
'//
'/////////////////////////////////////////////////////////////////////////////

' // Note: In versions of Internet Explorer prior to 6.05, this function is exported
' // as RebootCheckOnInstall.

'#if (_WIN32_IE >= 0x0605)

DECLARE FUNCTION TranslateInfStringA IMPORT "ADVPACK.DLL" ALIAS "TranslateInfStringA" ( _
   BYREF pszInfFilename AS ASCIIZ _                     ' __in LPCSTR pszInfFilename
 , BYREF pszInstallSection AS ASCIIZ _                  ' __in LPCSTR pszInstallSection
 , BYREF pszTranslateSection AS ASCIIZ _                ' __in LPCSTR pszTranslateSection
 , BYREF pszTranslateKey AS ASCIIZ _                    ' __in LPCSTR pszTranslateKey
 , BYREF pszBuffer AS ASCIIZ _                          ' __out_ecount_opt(cchBuffer) LPSTR pszBuffer
 , BYVAL cchBuffer AS DWORD _                           ' __in DWORD cchBuffer
 , BYREF pdwRequiredSize AS DWORD _                     ' __out PDWORD pdwRequiredSize
 , BYVAL pvReserved AS DWORD _                          ' __reserved PVOID pvReserved
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION TranslateInfStringW IMPORT "ADVPACK.DLL" ALIAS "TranslateInfStringW" ( _
   BYREF pszInfFilename AS WSTRINGZ _                   ' __in LPCWSTR pszInfFilename
 , BYREF pszInstallSection AS WSTRINGZ _                ' __in LPCWSTR pszInstallSection
 , BYREF pszTranslateSection AS WSTRINGZ _              ' __in LPCWSTR pszTranslateSection
 , BYREF pszTranslateKey AS WSTRINGZ _                  ' __in LPCWSTR pszTranslateKey
 , BYREF pszBuffer AS WSTRINGZ _                        ' __out_ecount_opt(cchBuffer) LPWSTR pszBuffer
 , BYVAL cchBuffer AS DWORD _                           ' __in DWORD cchBuffer
 , BYREF pdwRequiredSize AS DWORD _                     ' __out PDWORD pdwRequiredSize
 , BYVAL pvReserved AS DWORD _                          ' __reserved PVOID pvReserved
 ) AS LONG                                              ' HRESULT

'#endif  // (_WIN32_IE >= 0x0605)

#IF %DEF(%UNICODE)
MACRO TranslateInfString = TranslateInfStringW
#ELSE
MACRO TranslateInfString = TranslateInfStringA
#ENDIF


'/////////////////////////////////////////////////////////////////////////////
'// ENTRY POINT: RegInstall
'//
'// SYNOPSIS:    Loads an INF from a string resource, adds some entries to the
'//              INF string substitution table, and executes the INF.
'// RETURNS:
'//      S_OK    success.
'//      E_FAIL  failure,
'/////////////////////////////////////////////////////////////////////////////

' // Size = 8 bytes
TYPE STRENTRY DWORD
   pszName  AS ASCIIZ PTR    ' LPSTR // String to substitute
   pszValue AS ASCIIZ PTR    ' LPSTR // Replacement string or string resource
END TYPE

' // Size = 8 bytes
TYPE STRENTRYW DWORD
   pszName  AS WSTRINGZ PTR   ' LPWSTR // String to substitute
   pszValue AS WSTRINGZ PTR   ' LPWSTR // Replacement string or string resource
END TYPE

MACRO STRENTRYA = STRENTRY

' // Size = 8 bytes
TYPE STRTABLEA DWORD
   cEntries AS DWORD          ' DWORD      // Number of entries in the table
   pse      AS STRENTRY PTR   ' LPSTRENTRY // Array of entries
END TYPE

' // Size = 8 bytes
TYPE STRTABLEW DWORD
   cEntries AS DWORD          ' DWORD       // Number of entries in the table
   pse      AS STRENTRYW PTR  ' LPSTRENTRYW // Array of entries
END TYPE

#IF %DEF(%UNICODE)
MACRO STRTABLE  = STRTABLEW
#ELSE
MACRO STRTABLE  = STRTABLEA
#ENDIF
MACRO CSTRTABLE  = STRTABLE

' // Note: In versions of Internet Explorer prior to 6.05, this function is exported
' // as RegInstall.

'#if (_WIN32_IE >= 0x0605)

DECLARE FUNCTION RegInstallA IMPORT "ADVPACK.DLL" ALIAS "RegInstallA" ( _
   BYVAL hm AS DWORD _                                  ' __in HMODULE hm
 , BYREF pszSection AS ASCIIZ _                         ' __in LPCSTR pszSection
 , BYREF pstTable AS STRTABLEA _                        ' __in LPCSTRTABLEA pstTable
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION RegInstallW IMPORT "ADVPACK.DLL" ALIAS "RegInstallW" ( _
   BYVAL hm AS DWORD _                                  ' __in HMODULE hm
 , BYREF pszSection AS WSTRINGZ _                       ' __in LPCWSTR pszSection
 , BYREF pstTable AS STRTABLEW _                        ' __in LPCSTRTABLEW pstTable
 ) AS LONG                                              ' HRESULT

'#endif  // (_WIN32_IE >= 0x0605)

#IF %DEF(%UNICODE)
MACRO RegInstall  = RegInstallW
#ELSE
MACRO RegInstall  = RegInstallA
#ENDIF

'/////////////////////////////////////////////////////////////////////////////
'// ENTRY POINT: LaunchINFSectionEx
'//
'// SYNOPSIS:    Install INF section with BACKUP/ROLLBACK capabilities.
'//
'// RETURNS:     E_FAIL on failure, S_OK on success.
'/////////////////////////////////////////////////////////////////////////////

' // Note: In versions of Internet Explorer prior to 6.05, this function is exported
' // as LaunchINFSectionEx.

'#if (_WIN32_IE >= 0x0605)

DECLARE FUNCTION LaunchINFSectionExA IMPORT "ADVPACK.DLL" ALIAS "LaunchINFSectionExA" ( _
   BYVAL hwnd AS DWORD _                                ' __in_opt HWND hwnd
 , BYVAL hInstance AS DWORD _                           ' __in_opt HINSTANCE hInstance
 , BYREF pszParms AS ASCIIZ _                           ' __in LPSTR pszParms
 , BYVAL nShow AS LONG _                                ' __in INT nShow
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION LaunchINFSectionExW IMPORT "ADVPACK.DLL" ALIAS "LaunchINFSectionExW" ( _
   BYVAL hwnd AS DWORD _                                ' __in_opt HWND hwnd
 , BYVAL hInstance AS DWORD _                           ' __in_opt HINSTANCE hInstance
 , BYREF pszParms AS WSTRINGZ _                         ' __in LPWSTR pszParms
 , BYVAL nShow AS LONG _                                ' __in INT nShow
 ) AS LONG                                              ' HRESULT

'#endif  // (_WIN32_IE >= 0x0605)

#IF %DEF(%UNICODE)
MACRO LaunchINFSectionEx  = LaunchINFSectionExW
#ELSE
MACRO LaunchINFSectionEx  = LaunchINFSectionExA
#ENDIF

'// FLAGS:
'// FLAGS value this way is for compatibility. Don't change them.
'//
%ALINF_QUIET             = 4      ' // quiet mode, no UI
%ALINF_NGCONV            = 8      ' // don't run groupConv
%ALINF_UPDHLPDLLS        = 16     ' // force to self-updating on user's system
%ALINF_BKINSTALL         = 32     ' // backup data before install
%ALINF_ROLLBACK          = 64     ' // rollback to previous state
%ALINF_CHECKBKDATA       = 128    ' // validate the backup data
%ALINF_ROLLBKDOALL       = 256    ' // bypass building file list
%ALINF_DELAYREGISTEROCX  = 512    ' // force delay of ocx registration


'/////////////////////////////////////////////////////////////////////////////
'// ENTRY POINT: ExecuteCab
'//
'// SYNOPSIS:    Extract the an INF from the CAB file, and do INF install on it.
'/////////////////////////////////////////////////////////////////////////////

'// RETURNS: E_FAIL on failure, S_OK on success.

' // Note: In versions of Internet Explorer prior to 6.05, this function is exported
' // as ExecuteCab.

'#if (_WIN32_IE >= 0x0605)

' // Size = 276 bytes
TYPE CABINFOA DWORD
   pszCab     AS ASCIIZ PTR               ' LPSTR
   pszInf     AS ASCIIZ PTR               ' LPSTR
   pszSection AS ASCIIZ PTR               ' LPSTR
   szSrcPath  AS ASCIIZ * %MAX_PATH       ' CHAR
   dwFlags    AS DWORD                    ' DWORD
END TYPE

' // Size = 536 bytes
TYPE CABINFOW DWORD
   pszCab     AS WSTRINGZ PTR             ' LPWSTR
   pszInf     AS WSTRINGZ PTR             ' LPWSTR
   pszSection AS WSTRINGZ PTR             ' LPWSTR
   szSrcPath  AS WSTRINGZ * %MAX_PATH     ' WCHAR
   dwFlags    AS DWORD                    ' DWORD
END TYPE

#IF %DEF(%UNICODE)
MACRO CABINFO = CABINFOW
#ELSE
MACRO CABINFO = CABINFOA
#ENDIF

DECLARE FUNCTION ExecuteCabA IMPORT "ADVPACK.DLL" ALIAS "ExecuteCabA" ( _
   BYVAL hwnd AS DWORD _                                ' __in HWND hwnd
 , BYREF pCab AS CABINFOA _                             ' __in CABINFOA* pCab
 , BYVAL pReserved AS DWORD _                           ' __in LPVOID pReserved
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION ExecuteCabW IMPORT "ADVPACK.DLL" ALIAS "ExecuteCabW" ( _
   BYVAL hwnd AS DWORD _                                ' __in HWND hwnd
 , BYREF pCab AS CABINFOW _                             ' __in CABINFOW* pCab
 , BYVAL pReserved AS DWORD _                           ' __in PVOID pReserved
 ) AS LONG                                              ' HRESULT

#IF %DEF(%UNICODE)
MACRO ExecuteCab = ExecuteCabW
#ELSE
MACRO ExecuteCab = ExecuteCabA
#ENDIF

'#endif  // (_WIN32_IE >= 0x0605)

'// flag as LaunchINFSectionEx's flag defines

'/////////////////////////////////////////////////////////////////////////////
'// ENTRY POINT: AdvInstallFile
'//
'// SYNOPSIS:    To copy a file from the source to a destination
'//              Basicly a wrapper around the setupapi file copy engine
'/////////////////////////////////////////////////////////////////////////////

'// Flags which can be passed to AdvInstallFile
'// Here is a copy of the flags defined in setupapi.h for reference below.
'//#define COPYFLG_WARN_IF_SKIP            0x00000001   // warn if user tries to skip file
'//#define COPYFLG_NOSKIP                  0x00000002   // disallow skipping this file
'//#define COPYFLG_NOVERSIONCHECK          0x00000004   // ignore versions and overwrite target
'//#define COPYFLG_FORCE_FILE_IN_USE       0x00000008   // force file-in-use behavior
'//#define COPYFLG_NO_OVERWRITE            0x00000010   // do not copy if file exists on target
'//#define COPYFLG_NO_VERSION_DIALOG       0x00000020   // do not copy if target is newer
'//#define COPYFLG_REPLACEONLY             0x00000400   // copy only if file exists on target

%AIF_WARNIFSKIP          = &H00000001???           ' // system critical file: warn if user tries to skip
%AIF_NOSKIP              = &H00000002???           ' // Skip is disallowed for this file
%AIF_NOVERSIONCHECK      = &H00000004???           ' // don't check the version number of the file overwrite
%AIF_FORCE_FILE_IN_USE   = &H00000008???           ' // force file-in-use behavior
%AIF_NOOVERWRITE         = &H00000010???           ' // copy only if target doesn't exist
                                                   ' // if AIF_QUIET, the file is not copied and
                                                   ' // the user is not notified
%AIF_NO_VERSION_DIALOG   = &H00000020???           ' // do not copy if target is newer
%AIF_REPLACEONLY         = &H00000400???           ' // copy only if target file already present

'// Flags only known to AdvInstallFile
%AIF_NOLANGUAGECHECK     = &H10000000???           ' // don't check the language of the file
                                                   ' // if the flags is NOT specified and AIF_QUIET
                                                   ' // the file is not copied and the user is not notified
%AIF_QUIET               = &H20000000???           ' // No UI to the user

' // Note: In versions of Internet Explorer prior to 6.05, this function is exported
' // as AdvInstallFile.

'#if (_WIN32_IE >= 0x0605)

DECLARE FUNCTION AdvInstallFileA IMPORT "ADVPACK.DLL" ALIAS "AdvInstallFileA" ( _
   BYVAL hwnd AS DWORD _                                ' __in HWND hwnd
 , BYREF lpszSourceDir AS ASCIIZ _                      ' __in LPCSTR lpszSourceDir
 , BYREF lpszSourceFile AS ASCIIZ _                     ' __in LPCSTR lpszSourceFile
 , BYREF lpszDestDir AS ASCIIZ _                        ' __in LPCSTR lpszDestDir
 , BYREF lpszDestFile AS ASCIIZ _                       ' __in LPCSTR lpszDestFile
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYVAL dwReserved AS DWORD _                          ' __in DWORD dwReserved
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION AdvInstallFileW IMPORT "ADVPACK.DLL" ALIAS "AdvInstallFileW" ( _
   BYVAL hwnd AS DWORD _                                ' __in HWND hwnd
 , BYREF lpszSourceDir AS WSTRINGZ _                    ' __in LPCWSTR lpszSourceDir
 , BYREF lpszSourceFile AS WSTRINGZ _                   ' __in LPCWSTR lpszSourceFile
 , BYREF lpszDestDir AS WSTRINGZ _                      ' __in LPCWSTR lpszDestDir
 , BYREF lpszDestFile AS WSTRINGZ _                     ' __in LPCWSTR lpszDestFile
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYVAL dwReserved AS DWORD _                          ' __in DWORD dwReserved
 ) AS LONG                                              ' HRESULT

#IF %DEF(%UNICODE)
MACRO AdvInstallFile = AdvInstallFileW
#ELSE
MACRO AdvInstallFile = AdvInstallFileA
#ENDIF

'#endif  // (_WIN32_IE >= 0x0605)

'//////////////////////////////////////////////////////////////////
'//
'//////////////////////////////////////////////////////////////////
'// the following flags are for backwards compatiable.  No API user
'// should reference them directly now.
'//
%IE4_RESTORE        = &H00000001???      ' // if this bit is off, save the registries.
%IE4_BACKNEW        = &H00000002???      ' // backup all files which are not backed up before
%IE4_NODELETENEW    = &H00000004???      ' // don't delete files we don't backed up before
%IE4_NOMESSAGES     = &H00000008???      ' // No message display in any events.
%IE4_NOPROGRESS     = &H00000010???      ' // this bit on: No file backup progressbar
%IE4_NOENUMKEY      = &H00000020???      ' // this bit on: Don't Enum sub key even there is no given valuename
%IE4_NO_CRC_MAPPING = &H00000040???      ' // Normally you should not turn on this bit, advpack creates
                                         ' // internal mapping for all the entries backed up.
%IE4_REGSECTION     = &H00000080???      ' // INF AddReg/DelReg section
%IE4_FRDOALL        = &H00000100???      ' // FileRestore DoAll
%IE4_UPDREFCNT      = &H00000200???      ' // Update the ref count in .ini backup file list
%IE4_USEREFCNT      = &H00000400???      ' // use ref count to determin if the backup file should be put back
%IE4_EXTRAINCREFCNT = &H00000800???      ' // if increase the ref cnt if it has been updated before

%IE4_REMOVREGBKDATA = &H00001000???      ' // This bit should be used with restore bit

'/////////////////////////////////////////////////////////////////////////////
'// ENTRY POINT: RegSaveRestore
'//
'// SYNOPSIS:    Save or Restore the given register value or given INF reg section.
'//
'// RETURNS:     E_FAIL on failure, S_OK on success.
'/////////////////////////////////////////////////////////////////////////////

'// Save or Restore the given register value

' // Note: In versions of Internet Explorer prior to 6.05, this function is exported
' // as RegSaveRestore.

'#if (_WIN32_IE >= 0x0605)

DECLARE FUNCTION RegSaveRestoreA IMPORT "ADVPACK.DLL" ALIAS "RegSaveRestoreA" ( _
   BYVAL hwnd AS DWORD _                                ' __in HWND hwnd
 , BYREF pszTitleString AS ASCIIZ _                     ' __in LPCSTR pszTitleString
 , BYVAL hkBckupKey AS DWORD _                          ' __in HKEY hkBckupKey
 , BYREF pcszRootKey AS ASCIIZ _                        ' __in LPCSTR pcszRootKey
 , BYREF pcszSubKey AS ASCIIZ _                         ' __in LPCSTR pcszSubKey
 , BYREF pcszValueName AS ASCIIZ _                      ' __in LPCSTR pcszValueName
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION RegSaveRestoreW IMPORT "ADVPACK.DLL" ALIAS "RegSaveRestoreW" ( _
   BYVAL hwnd AS DWORD _                                ' __in HWND hwnd
 , BYREF pszTitleString AS WSTRINGZ _                   ' __in LPCWSTR pszTitleString
 , BYVAL hkBckupKey AS DWORD _                          ' __in HKEY hkBckupKey
 , BYREF pcszRootKey AS WSTRINGZ _                      ' __in LPCWSTR pcszRootKey
 , BYREF pcszSubKey AS WSTRINGZ _                       ' __in LPCWSTR pcszSubKey
 , BYREF pcszValueName AS WSTRINGZ _                    ' __in LPCWSTR pcszValueName
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 ) AS LONG                                              ' HRESULT

#IF %DEF(%UNICODE)
MACRO RegSaveRestore = RegSaveRestoreW
#ELSE
MACRO RegSaveRestore = RegSaveRestoreA
#ENDIF

'#endif  // (_WIN32_IE >= 0x0605)

'// Save or Restore the given INF Reg Section. At restore, if INF and Section pointers are NULL,
'// Restore all from the given backup key handle.

' // Note: In versions of Internet Explorer prior to 6.05, this function is exported
' // as RegSaveRestoreOnINFA.

'#if (_WIN32_IE >= 0x0605)

DECLARE FUNCTION RegSaveRestoreOnINFA IMPORT "ADVPACK.DLL" ALIAS "RegSaveRestoreOnINFA" ( _
   BYVAL hwnd AS DWORD _                                ' __in HWND hwnd
 , BYREF pszTitle AS ASCIIZ _                           ' __in LPCSTR pszTitle
 , BYREF pszINF AS ASCIIZ _                             ' __in LPCSTR pszINF
 , BYREF pszSection AS ASCIIZ _                         ' __in LPCSTR pszSection
 , BYVAL hHKLMBackKey AS DWORD _                        ' __in HKEY hHKLMBackKey
 , BYVAL hHKCUBackKey AS DWORD _                        ' __in HKEY hHKCUBackKey
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION RegSaveRestoreOnINFW IMPORT "ADVPACK.DLL" ALIAS "RegSaveRestoreOnINFW" ( _
   BYVAL hwnd AS DWORD _                                ' __in HWND hwnd
 , BYREF pszTitle AS WSTRINGZ _                         ' __in LPCWSTR pszTitle
 , BYREF pszINF AS WSTRINGZ _                           ' __in LPCWSTR pszINF
 , BYREF pszSection AS WSTRINGZ _                       ' __in LPCWSTR pszSection
 , BYVAL hHKLMBackKey AS DWORD _                        ' __in HKEY hHKLMBackKey
 , BYVAL hHKCUBackKey AS DWORD _                        ' __in HKEY hHKCUBackKey
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 ) AS LONG                                              ' HRESULT

#IF %DEF(%UNICODE)
MACRO RegSaveRestoreOnINF = RegSaveRestoreOnINFW
#ELSE
MACRO RegSaveRestoreOnINF = RegSaveRestoreOnINFA
#ENDIF

'#endif  // (_WIN32_IE >= 0x0605)

'// FLAG:
%RSR_RESTORE         = %IE4_RESTORE          ' // if this bit is off, means Save. Otherwise, restore.
%ARSR_NOMESSAGES     = %IE4_NOMESSAGES       ' // Quiet no messages in any event.
%ARSR_REGSECTION     = %IE4_REGSECTION       ' // if this bit is off, the given section is GenInstall Section
%ARSR_REMOVREGBKDATA = %IE4_REMOVREGBKDATA   ' // if both this bit and restore bit on, remove the backup reg data without restore it

'// Turn on the logging by add these RegVale in HKLM\software\microsoft\IE4
$REG_SAVE_LOG_KEY    = "RegSaveLogFile"
$REG_RESTORE_LOG_KEY = "RegRestoreLogFile"

' // Note: In versions of Internet Explorer prior to 6.05, this function is exported
' // as RegRestoreAll.

'#if (_WIN32_IE >= 0x0605)

DECLARE FUNCTION RegRestoreAllA IMPORT "ADVPACK.DLL" ALIAS "RegRestoreAllA" ( _
   BYVAL hWnd AS DWORD _                                ' __in_opt HWND hWnd
 , BYREF pszTitleString AS ASCIIZ _                     ' __in_opt LPCSTR pszTitleString
 , BYVAL hkBckupKey AS DWORD _                          ' __in HKEY hkBckupKey
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION RegRestoreAllW IMPORT "ADVPACK.DLL" ALIAS "RegRestoreAllW" ( _
   BYVAL hWnd AS DWORD _                                ' __in_opt HWND hWnd
 , BYREF pszTitleString AS WSTRINGZ _                   ' __in_opt LPCWSTR pszTitleString
 , BYVAL hkBckupKey AS DWORD _                          ' __in HKEY hkBckupKey
 ) AS LONG                                              ' HRESULT

#IF %DEF(%UNICODE)
MACRO RegRestoreAll = RegRestoreAllW
#ELSE
MACRO RegRestoreAll = RegRestoreAllA
#ENDIF

'#endif  // (_WIN32_IE >= 0x0605)

'/////////////////////////////////////////////////////////////////////////////
'// ENTRY POINT: FileSaveRestore
'//
'// SYNOPSIS:    Save or Restore the files on the list lpFileList.
'//              If lpFileList is NULL at restore time, the function will restore
'//              all based on INI index file.
'//
'// RETURNS:     E_FAIL on failure, S_OK on success.
'/////////////////////////////////////////////////////////////////////////////

' // Note: In versions of Internet Explorer prior to 6.05, this function is exported
' // as FileSaveRestore.

'#if (_WIN32_IE >= 0x0605)

DECLARE FUNCTION FileSaveRestoreA IMPORT "ADVPACK.DLL" ALIAS "FileSaveRestoreA" ( _
   BYVAL hDlg AS DWORD _                                ' __in HWND hDlg
 , BYREF lpFileList AS ASCIIZ _                         ' __in LPSTR lpFileList
 , BYREF lpDir AS ASCIIZ _                              ' __in LPSTR lpDir
 , BYREF lpBaseName AS ASCIIZ _                         ' __in LPSTR lpBaseName
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION FileSaveRestoreW IMPORT "ADVPACK.DLL" ALIAS "FileSaveRestoreW" ( _
   BYVAL hDlg AS DWORD _                                ' __in HWND hDlg
 , BYREF lpFileList AS WSTRINGZ _                       ' __in LPWSTR lpFileList
 , BYREF lpDir AS WSTRINGZ _                            ' __in LPWSTR lpDir
 , BYREF lpBaseName AS WSTRINGZ _                       ' __in LPWSTR lpBaseName
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 ) AS LONG                                              ' HRESULT

#IF %DEF(%UNICODE)
MACRO FileSaveRestore = FileSaveRestoreW
#ELSE
MACRO FileSaveRestore = FileSaveRestoreA
#ENDIF

'#endif  // (_WIN32_IE >= 0x0605)

'/////////////////////////////////////////////////////////////////////////////
'// ENTRY POINT: FileSaveRestoreOnINF
'//
'// SYNOPSIS:
'//
'// RETURNS:     E_FAIL on failure, S_OK on success.
'/////////////////////////////////////////////////////////////////////////////

' // Note: In versions of Internet Explorer prior to 6.05, this function is exported
' // as FileSaveRestoreOnINF.

'#if (_WIN32_IE >= 0x0605)

DECLARE FUNCTION FileSaveRestoreOnINFA IMPORT "ADVPACK.DLL" ALIAS "FileSaveRestoreOnINFA" ( _
   BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 , BYREF pszTitle AS ASCIIZ _                           ' __in LPCSTR pszTitle
 , BYREF pszINF AS ASCIIZ _                             ' __in LPCSTR pszINF
 , BYREF pszSection AS ASCIIZ _                         ' __in LPCSTR pszSection
 , BYREF pszBackupDir AS ASCIIZ _                       ' __in LPCSTR pszBackupDir
 , BYREF pszBaseBackupFile AS ASCIIZ _                  ' __in LPCSTR pszBaseBackupFile
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION FileSaveRestoreOnINFW IMPORT "ADVPACK.DLL" ALIAS "FileSaveRestoreOnINFW" ( _
   BYVAL hWnd AS DWORD _                                ' __in HWND hWnd
 , BYREF pszTitle AS WSTRINGZ _                         ' __in LPCWSTR pszTitle
 , BYREF pszINF AS WSTRINGZ _                           ' __in LPCWSTR pszINF
 , BYREF pszSection AS WSTRINGZ _                       ' __in LPCWSTR pszSection
 , BYREF pszBackupDir AS WSTRINGZ _                     ' __in LPCWSTR pszBackupDir
 , BYREF pszBaseBackupFile AS WSTRINGZ _                ' __in LPCWSTR pszBaseBackupFile
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 ) AS LONG                                              ' HRESULT

#IF %DEF(%UNICODE)
MACRO FileSaveRestoreOnINF = FileSaveRestoreOnINFW
#ELSE
MACRO FileSaveRestoreOnINF = FileSaveRestoreOnINFA
#ENDIF

'#endif  // (_WIN32_IE >= 0x0605)

'// FLAGS:
%AFSR_RESTORE        = %IE4_RESTORE      ' // if this bit is off, save the file.
%AFSR_BACKNEW        = %IE4_BACKNEW      ' // backup all files which are not backed up before
%AFSR_NODELETENEW    = %IE4_NODELETENEW  ' // don't delete files we don't backed up before
%AFSR_NOMESSAGES     = %IE4_NOMESSAGES   ' // No message display in any events.
%AFSR_NOPROGRESS     = %IE4_NOPROGRESS   ' // this bit on: No file backup progressbar
%AFSR_UPDREFCNT      = %IE4_UPDREFCNT    ' // update the reference count for the files
%AFSR_USEREFCNT      = %IE4_USEREFCNT    ' // use the ref count to guide the restore file
%AFSR_EXTRAINCREFCNT = %IE4_EXTRAINCREFCNT

'/////////////////////////////////////////////////////////////////////////////
'// ENTRY POINT: AddDelBackupEntry
'//
'// SYNOPSIS:    If AADBE_ADD_ENTRY is specified, mark the file in the File list as not existing
'//              during file save in the INI file.  This can be used to mark additional files that
'//              they did not exist during backup to avoid having them backup the next time the
'//              FileSaveRestore is called to save files.
'//              If AADBE_DEL_ENTRY is specified, delete the entry from the INI.  This mechanism can
'//              be used to leave files permanently on the system.
'//
'// RETURNS:
'//      S_OK    success
'//      E_FAIL  failure
'/////////////////////////////////////////////////////////////////////////////

' // Note: In versions of Internet Explorer prior to 6.05, this function is exported
' // as AddDelBackupEntry.

'#if (_WIN32_IE >= 0x0605)

DECLARE FUNCTION AddDelBackupEntryA IMPORT "ADVPACK.DLL" ALIAS "AddDelBackupEntryA" ( _
   BYREF lpcszFileList AS ASCIIZ _                      ' __in_opt LPCSTR lpcszFileList
 , BYREF lpcszBackupDir AS ASCIIZ _                     ' __in_opt LPCSTR lpcszBackupDir
 , BYREF lpcszBaseName AS ASCIIZ _                      ' __in_opt LPCSTR lpcszBaseName
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION AddDelBackupEntryW IMPORT "ADVPACK.DLL" ALIAS "AddDelBackupEntryW" ( _
   BYREF lpcszFileList AS WSTRINGZ _                    ' __in_opt LPCWSTR lpcszFileList
 , BYREF lpcszBackupDir AS WSTRINGZ _                   ' __in_opt LPCWSTR lpcszBackupDir
 , BYREF lpcszBaseName AS WSTRINGZ _                    ' __in_opt LPCWSTR lpcszBaseName
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 ) AS LONG                                              ' HRESULT

#IF %DEF(%UNICODE)
MACRO AddDelBackupEntry = AddDelBackupEntryW
#ELSE
MACRO AddDelBackupEntry = AddDelBackupEntryA
#ENDIF

'#endif  // (_WIN32_IE >= 0x0605)

%AADBE_ADD_ENTRY    = &H01           ' // add entries to the INI file
%AADBE_DEL_ENTRY    = &H02           ' // delete entries from the INI file

'/////////////////////////////////////////////////////////////////////////////
'// ENTRY POINT: FileSaveMarkNotExist
'//
'// SYNOPSIS:    Mark the file in the File list as not existing during file save in the INI file
'//              This can be used to mark additional files that they did not exist during backup
'//              to avoid having them backup the next time the FileSaveRestore is called to save
'//              files
'//
'// RETURNS:
'//      S_OK    success
'//      E_FAIL  failure
'/////////////////////////////////////////////////////////////////////////////

' // Note: In versions of Internet Explorer prior to 6.05, this function is exported
' // as FileSaveMarkNotExist.

'#if (_WIN32_IE >= 0x0605)

DECLARE FUNCTION FileSaveMarkNotExistA IMPORT "ADVPACK.DLL" ALIAS "FileSaveMarkNotExistA" ( _
   BYREF lpFileList AS ASCIIZ _                         ' __in LPSTR lpFileList
 , BYREF lpDir AS ASCIIZ _                              ' __in LPSTR lpDir
 , BYREF lpBaseName AS ASCIIZ _                         ' __in LPSTR lpBaseName
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION FileSaveMarkNotExistW IMPORT "ADVPACK.DLL" ALIAS "FileSaveMarkNotExistW" ( _
   BYREF lpFileList AS WSTRINGZ _                       ' __in LPWSTR lpFileList
 , BYREF lpDir AS WSTRINGZ _                            ' __in LPWSTR lpDir
 , BYREF lpBaseName AS WSTRINGZ _                       ' __in LPWSTR lpBaseName
 ) AS LONG                                              ' HRESULT

#IF %DEF(%UNICODE)
MACRO FileSaveMarkNotExist = FileSaveMarkNotExistW
#ELSE
MACRO FileSaveMarkNotExist = FileSaveMarkNotExistA
#ENDIF

'#endif  // (_WIN32_IE >= 0x0605)

'/////////////////////////////////////////////////////////////////////////////
'// ENTRY POINT: GetVersionFromFile
'//
'// SYNOPSIS:    Get the given file's version and lang information.
'//
'// RETURNS:     E_FAIL on failure, S_OK on success.
'/////////////////////////////////////////////////////////////////////////////

' // Note: In versions of Internet Explorer prior to 6.05, this function is exported
' // as GetVersionFromFile.

'#if (_WIN32_IE >= 0x0605)

DECLARE FUNCTION GetVersionFromFileA IMPORT "ADVPACK.DLL" ALIAS "GetVersionFromFileA" ( _
   BYREF lpszFilename AS ASCIIZ _                       ' __in LPSTR lpszFilename
 , BYREF pdwMSVer AS DWORD _                            ' __out LPDWORD pdwMSVer
 , BYREF pdwLSVer AS DWORD _                            ' __out LPDWORD pdwLSVer
 , BYVAL bVersion AS LONG _                             ' __in BOOL bVersion
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION GetVersionFromFileW IMPORT "ADVPACK.DLL" ALIAS "GetVersionFromFileW" ( _
   BYREF lpszFilename AS WSTRINGZ _                     ' __in LPWSTR lpszFilename
 , BYREF pdwMSVer AS DWORD _                            ' __out LPDWORD pdwMSVer
 , BYREF pdwLSVer AS DWORD _                            ' __out LPDWORD pdwLSVer
 , BYVAL bVersion AS LONG _                             ' __in BOOL bVersion
 ) AS LONG                                              ' HRESULT

#IF %DEF(%UNICODE)
MACRO GetVersionFromFile = GetVersionFromFileW
#ELSE
MACRO GetVersionFromFile = GetVersionFromFileA
#ENDIF

'#endif  // (_WIN32_IE >= 0x0605)

'/////////////////////////////////////////////////////////////////////////////
'// ENTRY POINT: GetVersionFromFileEx
'//
'// SYNOPSIS:    Get the given disk file's version and lang information.
'//
'// RETURNS:     E_FAIL on failure, S_OK on success.
'/////////////////////////////////////////////////////////////////////////////

' // Note: In versions of Internet Explorer prior to 6.05, this function is exported
' // as GetVersionFromFileEx.

'#if (_WIN32_IE >= 0x0605)

DECLARE FUNCTION GetVersionFromFileExA IMPORT "ADVPACK.DLL" ALIAS "GetVersionFromFileExA" ( _
   BYREF lpszFilename AS ASCIIZ _                       ' __in LPSTR lpszFilename
 , BYREF pdwMSVer AS DWORD _                            ' __out LPDWORD pdwMSVer
 , BYREF pdwLSVer AS DWORD _                            ' __out LPDWORD pdwLSVer
 , BYVAL bVersion AS LONG _                             ' __in BOOL bVersion
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION GetVersionFromFileExW IMPORT "ADVPACK.DLL" ALIAS "GetVersionFromFileExW" ( _
   BYREF lpszFilename AS WSTRINGZ _                     ' __in LPWSTR lpszFilename
 , BYREF pdwMSVer AS DWORD _                            ' __out LPDWORD pdwMSVer
 , BYREF pdwLSVer AS DWORD _                            ' __out LPDWORD pdwLSVer
 , BYVAL bVersion AS LONG _                             ' __in BOOL bVersion
 ) AS LONG                                              ' HRESULT

#IF %DEF(%UNICODE)
MACRO GetVersionFromFileEx = GetVersionFromFileExW
#ELSE
MACRO GetVersionFromFileEx = GetVersionFromFileExA
#ENDIF

'#endif  // (_WIN32_IE >= 0x0605)

'/////////////////////////////////////////////////////////////////////////////
'// ENTRY POINT: IsNTAdmin
'//
'// SYNOPSIS:    On NT, check if user has admin right.
'//
'// RETURNS:     TURE  has admin right; FLSE  no admin right.
'/////////////////////////////////////////////////////////////////////////////

DECLARE FUNCTION IsNTAdmin IMPORT "ADVPACK.DLL" ALIAS "IsNTAdmin" ( _
   BYVAL dwReserved AS DWORD _                          ' __in DWORD dwReserved
 , BYREF lpdwReserved AS DWORD _                        ' __out DWORD *lpdwReserved
 ) AS LONG                                              ' BOOL

'/////////////////////////////////////////////////////////////////////////////
'// ENTRY POINT: DelNode
'//
'// SYNOPSIS:    Deletes a file or directory
'//
'// RETURNS:
'//      S_OK    success
'//      E_FAIL  failure
'/////////////////////////////////////////////////////////////////////////////

'// FLAGS:
%ADN_DEL_IF_EMPTY        = &H00000001???  ' // delete the directory only if it's empty
%ADN_DONT_DEL_SUBDIRS    = &H00000002???  ' // don't delete any sub-dirs; delete only the files
%ADN_DONT_DEL_DIR        = &H00000004???  ' // don't delete the dir itself
%ADN_DEL_UNC_PATHS       = &H00000008???  ' // delete UNC paths

' // Note: In versions of Internet Explorer prior to 6.05, this function is exported
' // as DelNode.

'#if (_WIN32_IE >= 0x0605)

DECLARE FUNCTION DelNodeA IMPORT "ADVPACK.DLL" ALIAS "DelNodeA" ( _
   BYREF pszFileOrDirName AS ASCIIZ _                   ' __in LPCSTR pszFileOrDirName
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION DelNodeW IMPORT "ADVPACK.DLL" ALIAS "DelNodeW" ( _
   BYREF pszFileOrDirName AS WSTRINGZ _                 ' __in LPCWSTR pszFileOrDirName
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 ) AS LONG                                              ' HRESULT

#IF %DEF(%UNICODE)
MACRO DelNode = DelNodeW
#ELSE
MACRO DelNode = DelNodeA
#ENDIF

'#endif  // (_WIN32_IE >= 0x0605)

'/////////////////////////////////////////////////////////////////////////////
'// ENTRY POINT: DelNodeRunDLL32
'//
'// SYNOPSIS:    Deletes a file or directory; the parameters to this API are of
'//              WinMain type
'//
'// RETURNS:
'//      S_OK    success
'//      E_FAIL  failure
'/////////////////////////////////////////////////////////////////////////////

' // Note: In versions of Internet Explorer prior to 6.05, this function is exported
' // as DelNodeRunDLL32.

'#if (_WIN32_IE >= 0x0605)

DECLARE FUNCTION DelNodeRunDLL32A IMPORT "ADVPACK.DLL" ALIAS "DelNodeRunDLL32A" ( _
   BYVAL hwnd AS DWORD _                                ' __in HWND hwnd
 , BYVAL hInstance AS DWORD _                           ' __in HINSTANCE hInstance
 , BYREF pszParms AS ASCIIZ _                           ' __inout LPSTR pszParms
 , BYVAL nShow AS LONG _                                ' __in INT nShow
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION DelNodeRunDLL32W IMPORT "ADVPACK.DLL" ALIAS "DelNodeRunDLL32W" ( _
   BYVAL hwnd AS DWORD _                                ' __in HWND hwnd
 , BYVAL hInstance AS DWORD _                           ' __in HINSTANCE hInstance
 , BYREF pszParms AS WSTRINGZ _                         ' __inout LPWSTR pszParms
 , BYVAL nShow AS LONG _                                ' __in INT nShow
 ) AS LONG                                              ' HRESULT

#IF %DEF(%UNICODE)
MACRO DelNodeRunDLL32 = DelNodeRunDLL32W
#ELSE
MACRO DelNodeRunDLL32 = DelNodeRunDLL32A
#ENDIF

'#endif  // (_WIN32_IE >= 0x0605)

'/////////////////////////////////////////////////////////////////////////////
'// ENTRY POINT: OpenINFEngine, TranslateINFStringEx, CloseINFEngine
'//
'// SYNOPSIS:    Three APIs give the caller the option to be more efficient when need
'//              Advpack to translate INF file in a continue fashion.
'//
'// RETURNS:
'//      S_OK    success
'//      E_FAIL  failure
'/////////////////////////////////////////////////////////////////////////////

'#if !defined(UNIX) || !defined(_INC_SETUPAPI) // IEUNIX: Prevent re-def.
'//
'// Define type for reference to loaded inf file
'// (from setupapi.h)
'//
'typedef PVOID HINF;
'#endif

' // Note: In versions of Internet Explorer prior to 6.05, this function is exported
' // as OpenINFEngine.

'#if (_WIN32_IE >= 0x0605)

DECLARE FUNCTION OpenINFEngineA IMPORT "ADVPACK.DLL" ALIAS "OpenINFEngineA" ( _
   BYREF pszInfFilename AS ASCIIZ _                     ' __in LPCSTR pszInfFilename
 , BYREF pszInstallSection AS ASCIIZ _                  ' __in LPCSTR pszInstallSection
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYREF phInf AS DWORD _                               ' __out HINF *phInf
 , BYVAL pvReserved AS DWORD _                          ' __in PVOID pvReserved
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION OpenINFEngineW IMPORT "ADVPACK.DLL" ALIAS "OpenINFEngineW" ( _
   BYREF pszInfFilename AS WSTRINGZ _                   ' __in LPCWSTR pszInfFilename
 , BYREF pszInstallSection AS WSTRINGZ _                ' __in LPCWSTR pszInstallSection
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYREF phInf AS DWORD _                               ' __out HINF *phInf
 , BYVAL pvReserved AS DWORD _                          ' __in PVOID pvReserved
 ) AS LONG                                              ' HRESULT

#IF %DEF(%UNICODE)
MACRO OpenINFEngine = OpenINFEngineW
#ELSE
MACRO OpenINFEngine = OpenINFEngineA
#ENDIF

'#endif  // (_WIN32_IE >= 0x0605)

' // Note: In versions of Internet Explorer prior to 6.05, this function is exported
' // as TranslateInfStringEx.

'#if (_WIN32_IE >= 0x0605)

DECLARE FUNCTION TranslateInfStringExA IMPORT "ADVPACK.DLL" ALIAS "TranslateInfStringExA" ( _
   BYVAL hInf AS DWORD _                                ' __in HINF hInf
 , BYREF pszInfFilename AS ASCIIZ _                     ' __in LPCSTR pszInfFilename
 , BYREF pszTranslateSection AS ASCIIZ _                ' __in LPCSTR pszTranslateSection
 , BYREF pszTranslateKey AS ASCIIZ _                    ' __in LPCSTR pszTranslateKey
 , BYREF pszBuffer AS STRINGZ _                         ' __inout LPSTR pszBuffer
 , BYVAL dwBufferSize AS DWORD _                        ' __in DWORD dwBufferSize
 , BYREF pdwRequiredSize AS DWORD _                     ' __out PDWORD pdwRequiredSize
 , BYVAL pvReserved AS DWORD _                          ' __in PVOID pvReserved
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION TranslateInfStringExW IMPORT "ADVPACK.DLL" ALIAS "TranslateInfStringExW" ( _
   BYVAL hInf AS DWORD _                                ' __in HINF hInf
 , BYREF pszInfFilename AS WSTRINGZ _                   ' __in LPCWSTR pszInfFilename
 , BYREF pszTranslateSection AS WSTRINGZ _              ' __in LPCWSTR pszTranslateSection
 , BYREF pszTranslateKey AS WSTRINGZ _                  ' __in LPCWSTR pszTranslateKey
 , BYREF pszBuffer AS WSTRINGZ _                        ' __inout LPWSTR pszBuffer
 , BYVAL dwBufferSize AS DWORD _                        ' __in DWORD dwBufferSize
 , BYREF pdwRequiredSize AS DWORD _                     ' __out PDWORD pdwRequiredSize
 , BYVAL pvReserved AS DWORD _                          ' __in PVOID pvReserved
 ) AS LONG                                              ' HRESULT

#IF %DEF(%UNICODE)
MACRO TranslateInfStringEx = TranslateInfStringExW
#ELSE
MACRO TranslateInfStringEx = TranslateInfStringExA
#ENDIF

'#endif  // (_WIN32_IE >= 0x0605)

DECLARE FUNCTION CloseINFEngine IMPORT "ADVPACK.DLL" ALIAS "CloseINFEngine" ( _
   BYVAL hInf AS DWORD _                                ' __in HINF hInf
 ) AS LONG                                              ' HRESULT

' // Note: In versions of Internet Explorer prior to 6.05, this function is exported
' // as ExtractFiles.

'#if (_WIN32_IE >= 0x0605)

DECLARE FUNCTION ExtractFilesA IMPORT "ADVPACK.DLL" ALIAS "ExtractFilesA" ( _
   BYREF pszCabName AS ASCIIZ _                         ' __in LPCSTR pszCabName
 , BYREF pszExpandDir AS ASCIIZ _                       ' __in LPCSTR pszExpandDir
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYREF pszFileList AS ASCIIZ _                        ' __in LPCSTR pszFileList
 , BYVAL lpReserved AS DWORD _                          ' __in LPVOID lpReserved
 , BYVAL dwReserved AS DWORD _                          ' __in DWORD  dwReserved
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION ExtractFilesW IMPORT "ADVPACK.DLL" ALIAS "ExtractFilesW" ( _
   BYREF pszCabName AS WSTRINGZ _                       ' __in LPCWSTR pszCabName
 , BYREF pszExpandDir AS WSTRINGZ _                     ' __in LPCWSTR pszExpandDir
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 , BYREF pszFileList AS WSTRINGZ _                      ' __in LPCWSTR pszFileList
 , BYVAL lpReserved AS DWORD _                          ' __in LPVOID lpReserved
 , BYVAL dwReserved AS DWORD _                          ' __in DWORD dwReserved
 ) AS LONG                                              ' HRESULT

#IF %DEF(%UNICODE)
MACRO ExtractFiles = ExtractFilesW
#ELSE
MACRO ExtractFiles = ExtractFilesA
#ENDIF

'#endif  // (_WIN32_IE >= 0x0605)

'/////////////////////////////////////////////////////////////////////////////
'// ENTRY POINT: LaunchINFSection
'//
'// SYNOPSIS:    Install INF section WITHOUT BACKUP/ROLLBACK capabilities.
'//
'// RETURNS:     E_FAIL on failure, S_OK on success.
'/////////////////////////////////////////////////////////////////////////////

' // Note: In versions of Internet Explorer prior to 6.05, this function is exported
' // as LaunchINFSection.

'#if (_WIN32_IE >= 0x0605)

DECLARE FUNCTION LaunchINFSectionA IMPORT "ADVPACK.DLL" ALIAS "LaunchINFSectionA" ( _
   BYVAL hwnd AS DWORD _                                ' __in HWND hwnd
 , BYVAL hInst AS DWORD _                               ' __in HINSTANCE hInst
 , BYREF pszParams AS ASCIIZ _                          ' __inout LPSTR pszParams
 , BYVAL nShow AS LONG _                                ' __in INT nShow
 ) AS LONG                                              ' INT

DECLARE FUNCTION LaunchINFSectionW IMPORT "ADVPACK.DLL" ALIAS "LaunchINFSectionW" ( _
   BYVAL hwnd AS DWORD _                                ' __in HWND hwnd
 , BYVAL hInst AS DWORD _                               ' __in HINSTANCE hInst
 , BYREF pszParams AS WSTRINGZ _                        ' __inout LPWSTR pszParams
 , BYVAL nShow AS LONG _                                ' __in INT nShow
 ) AS LONG                                              ' INT

#IF %DEF(%UNICODE)
MACRO LaunchINFSection = LaunchINFSectionW
#ELSE
MACRO LaunchINFSection = LaunchINFSectionA
#ENDIF

'#endif  // (_WIN32_IE >= 0x0605)

'// LaunchINFSection flags
%LIS_QUIET               = &H0001     ' // Bit 0
%LIS_NOGRPCONV           = &H0002     ' // Bit 1

'// Flags in Advanced INF RunPreSetupCommands and RunPostSetupCommands of the Install section
'// Those flags can tell advpack how to run those commands, quiet or not quiet, wait or not wait.
'// The Default for runing those commands are:  Not Quiet and Wait for finish before return the caller.
'// I.E>  RunPostSetupCommands = MyCmdsSecA:1, MyCmdsSecB:2, MyCmdsSecC
'//
%RUNCMDS_QUIET        = &H00000001???
%RUNCMDS_NOWAIT       = &H00000002???
%RUNCMDS_DELAYPOSTCMD = &H00000004???


'/////////////////////////////////////////////////////////////////////////////
'// ENTRY POINT: UserStubWrapper
'//
'// SYNOPSIS:    The function wrapper around the real per-user restore stub to
'//              do some generic/intelligent function on behalf of every component.
'//
'// RETURNS:     E_FAIL on failure, S_OK on success.
'/////////////////////////////////////////////////////////////////////////////

' // Note: In versions of Internet Explorer prior to 6.05, this function is exported
' // as UserInstStubWrapper.

'#if (_WIN32_IE >= 0x0605)

DECLARE FUNCTION UserInstStubWrapperA IMPORT "ADVPACK.DLL" ALIAS "UserInstStubWrapperA" ( _
   BYVAL hwnd AS DWORD _                                ' __in HWND hwnd
 , BYVAL hInst AS DWORD _                               ' __in HINSTANCE hInst
 , BYREF pszParams AS ASCIIZ _                          ' __in LPCSTR pszParams
 , BYVAL nShow AS LONG _                                ' __in INT nShow
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION UserInstStubWrapperW IMPORT "ADVPACK.DLL" ALIAS "UserInstStubWrapperW" ( _
   BYVAL hwnd AS DWORD _                                ' __in HWND hwnd
 , BYVAL hInst AS DWORD _                               ' __in HINSTANCE hInst
 , BYREF pszParams AS WSTRINGZ _                        ' __in LPCWSTR pszParams
 , BYVAL nShow AS LONG _                                ' __in INT nShow
 ) AS LONG                                              ' HRESULT

#IF %DEF(%UNICODE)
MACRO UserInstStubWrapper = UserInstStubWrapperW
#ELSE
MACRO UserInstStubWrapper = UserInstStubWrapperA
#ENDIF

'#endif  // (_WIN32_IE >= 0x0605)

' // Note: In versions of Internet Explorer prior to 6.05, this function is exported
' // as UserUnInstStubWrapper.

'#if (_WIN32_IE >= 0x0605)

DECLARE FUNCTION UserUnInstStubWrapperA IMPORT "ADVPACK.DLL" ALIAS "UserUnInstStubWrapperA" ( _
   BYVAL hwnd AS DWORD _                                ' __in HWND hwnd
 , BYVAL hInst AS DWORD _                               ' __in HINSTANCE hInst
 , BYREF pszParams AS ASCIIZ _                          ' __in LPCSTR pszParams
 , BYVAL nShow AS LONG _                                ' __in INT nShow
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION UserUnInstStubWrapperW IMPORT "ADVPACK.DLL" ALIAS "UserUnInstStubWrapperW" ( _
   BYVAL hwnd AS DWORD _                                ' __in HWND hwnd
 , BYVAL hInst AS DWORD _                               ' __in HINSTANCE hInst
 , BYREF pszParams AS WSTRINGZ _                        ' __in LPCWSTR pszParams
 , BYVAL nShow AS LONG _                                ' __in INT nShow
 ) AS LONG                                              ' HRESULT

#IF %DEF(%UNICODE)
MACRO UserUnInstStubWrapper = UserUnInstStubWrapperW
#ELSE
MACRO UserUnInstStubWrapper = UserUnInstStubWrapperA
#ENDIF

'#endif  // (_WIN32_IE >= 0x0605)

'/////////////////////////////////////////////////////////////////////////////
'// ENTRY POINT: SetPerUserInstValues
'//
'// SYNOPSIS:    The function set the per-user stub reg values under IsInstalled\{GUID}
'//              related key to ensure the later per-user process correctly.
'//
'// RETURNS:     E_FAIL on failure, S_OK on success.
'/////////////////////////////////////////////////////////////////////////////

'// Args passed to the following API
'// MAX_GUID_STRING_LEN is 39 defined in cfgmgr32.h, here we just use it.
'//

' // Size = 1408 bytes
TYPE PERUSERSECTIONA DWORD
   szGUID        AS ASCIIZ * 39 + 20           ' CHAR
   szDispName    AS ASCIIZ * 128               ' CHAR
   szLocale      AS ASCIIZ * 10                ' CHAR
   szStub        AS ASCIIZ * %MAX_PATH * 4     ' CHAR
   szVersion     AS ASCIIZ * 32                ' CHAR
   szCompID      AS ASCIIZ * 128               ' CHAR
   dwIsInstalled AS DWORD                      ' DWORD
   bRollback     AS LONG                       ' BOOL
END TYPE

' // Size = 2804 bytes
TYPE PERUSERSECTIONW DWORD
   szGUID        AS WSTRINGZ * 39 + 20         ' WCHAR
   szDispName    AS WSTRINGZ * 128             ' WCHAR
   szLocale      AS WSTRINGZ * 10              ' WCHAR
   szStub        AS WSTRINGZ * %MAX_PATH * 4   ' WCHAR
   szVersion     AS WSTRINGZ * 32              ' WCHAR
   szCompID      AS WSTRINGZ * 128             ' WCHAR
   dwIsInstalled AS DWORD                      ' DWORD
   bRollback     AS LONG                       ' BOOL
END TYPE

#IF %DEF(%UNICODE)
MACRO PERUSERSECTION = PERUSERSECTIONW
#ELSE
MACRO PERUSERSECTION = PERUSERSECTIONA
#ENDIF

' // Note: In versions of Internet Explorer prior to 6.05, this function is exported
' // as SetPerUserSecValues.

'#if (_WIN32_IE >= 0x0605)

DECLARE FUNCTION SetPerUserSecValuesA IMPORT "ADVPACK.DLL" ALIAS "SetPerUserSecValuesA" ( _
   BYREF pPerUser AS PERUSERSECTIONA _                  ' __in PPERUSERSECTIONA pPerUser
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION SetPerUserSecValuesW IMPORT "ADVPACK.DLL" ALIAS "SetPerUserSecValuesW" ( _
   BYREF pPerUser AS PERUSERSECTIONW _                  ' __in PPERUSERSECTIONW pPerUser
 ) AS LONG                                              ' HRESULT

#IF %DEF(%UNICODE)
MACRO SetPerUserSecValues = SetPerUserSecValuesW
#ELSE
MACRO SetPerUserSecValues = SetPerUserSecValuesA
#ENDIF

'#endif  // (_WIN32_IE >= 0x0605)
