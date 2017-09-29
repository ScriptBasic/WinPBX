' ########################################################################################
' Microsoft Windows
' File: SetupAPI.inc
' Contents: Public header file for Windows NT Setup and Device Installer services Dll.
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%SETUPAPI_INC = 1

#INCLUDE ONCE "windows.inc"
#INCLUDE ONCE "prsht.inc"

' //
' // determine version of setupapi based on _WIN32_WINDOWS and _WIN32_WINNT
' //
' // NT4 version of setupapi   (0x0400) is earliest, and installed onto Win95 by IE.
' // Win2k version of setupapi (0x0500) also shipped in WinME
' // we'll use "0x0410" to indicate version of setupapi shipped with Win98
' //
'#ifndef _SETUPAPI_VER
'#if defined(_WIN32_WINNT) && (!defined(_WIN32_WINDOWS) || (_WIN32_WINNT < _WIN32_WINDOWS))
'#define _SETUPAPI_VER _WIN32_WINNT  // SetupAPI version follows Windows NT version
'#elif defined(_WIN32_WINDOWS)
'#if _WIN32_WINDOWS >= 0x0490
'#define _SETUPAPI_VER _WIN32_WINNT_WIN2K        // WinME uses same version of SetupAPI as Win2k
'#elif _WIN32_WINDOWS >= 0x0410
'#define _SETUPAPI_VER 0x0410        // Indicates version of SetupAPI shipped with Win98
'#else
'#define _SETUPAPI_VER _WIN32_WINNT_NT4        // Earliest SetupAPI version
'#endif // _WIN32_WINDOWS
'#else // _WIN32_WINNT/_WIN32_WINDOWS
'#define _SETUPAPI_VER _WIN32_WINNT_WINXP
'#endif // _WIN32_WINNT/_WIN32_WINDOWS
'#endif // !_SETUPAPI_VER

#IF NOT %DEF(%WIN32_WINDOWS)
%WIN32_WINDOWS = %WINVER
#ENDIF

#IF NOT %DEF(%SETUPAPI_VER)
'#IF %DEF(%WIN32_WINNT) AND (NOT %DEF(%WIN32_WINDOWS) OR (%WIN32_WINNT < %WIN32_WINDOWS))
#IF %DEF(%WIN32_WINNT) AND (NOT %DEF(%WIN32_WINDOWS) OR (%WIN32_WINNT < %WIN32_WINDOWS))
%SETUPAPI_VER = %WIN32_WINNT         ' // SetupAPI version follows Windows NT version
#ELSEIF %DEF(%WIN32_WINDOWS)
'#IF %WIN32_WINDOWS >= &H0490
#IF %WIN32_WINDOWS >= &H0490 AND %WIN32_WINDOWS < %WIN32_WINNT_WINXP
%SETUPAPI_VER = %WIN32_WINNT_WIN2K   ' // WinME uses same version of SetupAPI as Win2k
'#ELSEIF %WIN32_WINDOWS >= &H0410
#ELSEIF %WIN32_WINDOWS >= &H0410 AND %WIN32_WINDOWS < %WIN32_WINNT_WINXP
%SETUPAPI_VER = &H0410               ' // Indicates version of SetupAPI shipped with Win98
#ELSEIF %WIN32_WINDOWS >= %WIN32_WINNT_WINXP
%SETUPAPI_VER = %WIN32_WINNT_WINXP
#ELSE
%SETUPAPI_VER = %WIN32_WINNT_NT4     ' // Earliest SetupAPI version
#ENDIF ' %WIN32_WINDOWS
#ELSE ' %WIN32_WINNT/%WIN32_WINDOWS
%SETUPAPI_VER = %WIN32_WINNT_WINXP
#ENDIF ' %WIN32_WINNT/%WIN32_WINDOWS
#ENDIF ' not %SETUPAPI_VER

'#ifndef __LPGUID_DEFINED__
'#define __LPGUID_DEFINED__
'typedef GUID *LPGUID;
'#endif

'//
'// Include spapidef.h for basic definitions and flags
'//
#INCLUDE ONCE "spapidef.inc"

' //
' // Include commctrl.h for our use of HIMAGELIST and wizard support.
' //
#INCLUDE ONCE "commctrl.inc"

'//
'// Include devpropdef.h for our use of DEVPROPERTYKEY and DEVPROPTYPE.
'//
#INCLUDE ONCE "devpropdef.inc"

'#ifdef _WIN64
'#include <pshpack8.h>   ' // Assume 8-byte (64-bit) packing throughout
'#else
'#include <pshpack1.h>   ' // Assume byte packing throughout (32-bit processor)
'#endif

' //
' // Define maximum string length constants
' //
%LINE_LEN                    = 256  ' // Windows 9x-compatible maximum for
                                    ' // displayable strings coming from a
                                    ' // device INF.
%MAX_INF_STRING_LENGTH       = 4096 ' // Actual maximum size of an INF string
                                    ' // (including string substitutions).
%MAX_INF_SECTION_NAME_LENGTH = 255  ' // For Windows 9x compatibility, INF
                                    ' // section names should be constrained
                                    ' // to 32 characters.

%MAX_TITLE_LEN               = 60
%MAX_INSTRUCTION_LEN         = 256
%MAX_LABEL_LEN               = 30
%MAX_SERVICE_NAME_LEN        = 256
%MAX_SUBTITLE_LEN            = 256

' //
' // Define maximum length of a machine name in the format expected by ConfigMgr32
' // CM_Connect_Machine (i.e., "\\\\MachineName\0").
' //
%SP_MAX_MACHINENAME_LENGTH   = (%MAX_PATH + 3)

' //
' // Define type for reference to loaded inf file
' //
'typedef PVOID HINF;

' //
' // Inf context structure. Applications must not interpret or
' // overwrite values in these structures.
' //
' // Size = 16 bytes
TYPE INFCONTEXT DWORD
   Inf        AS DWORD   ' PVOID
   CurrentInf AS DWORD   ' PVOID
   Section    AS DWORD   ' UINT
   Line       AS DWORD   ' UINT
END TYPE

' //
' // Inf file information structure.
' //
' // Size = 9 bytes
TYPE SP_INF_INFORMATION BYTE
   InfStyle       AS DWORD   ' DWORD
   InfCount       AS DWORD   ' DWORD
   VersionData(0) AS BYTE    ' [ANYSIZE_ARRAY]
END TYPE

' //
' // Define structure for passing alternate platform info into
' // SetupSetFileQueueAlternatePlatform and SetupQueryInfOriginalFileInformation.
' //
'typedef struct _SP_ALTPLATFORM_INFO_V2 {
'    DWORD cbSize;
'    ' //
'    ' // platform to use (VER_PLATFORM_WIN32_WINDOWS or VER_PLATFORM_WIN32_NT)
'    ' //
'    DWORD Platform;
'    ' //
'    ' // major and minor version numbers to use
'    ' //
'    DWORD MajorVersion;
'    DWORD MinorVersion;
'    ' //
'    ' // processor architecture to use (PROCESSOR_ARCHITECTURE_INTEL,
'    ' // PROCESSOR_ARCHITECTURE_AMD64, or PROCESSOR_ARCHITECTURE_IA64.
'    ' //
'    WORD  ProcessorArchitecture;

'    union {
'        WORD  Reserved; ' // for compatibility with V1 structure
'        WORD  Flags;    ' // indicates validity of non V1 fields
'    } DUMMYUNIONNAME;

'    ' //
'    ' // specify SP_ALTPLATFORM_FLAGS_VERSION_RANGE in Flags
'    ' // to use FirstValidatedMajorVersion and FirstValidatedMinorVersion
'    ' //
'    ' // Major and minor versions of the oldest previous OS for which this
'    ' // package's digital signature may be considered valid.  For example, say
'    ' // the alternate platform is VER_PLATFORM_WIN32_NT, version 5.1.  However,
'    ' // it is wished that driver packages signed with a 5.0 osattr also be
'    ' // considered valid.  In this case, you'd have a  MajorVersion/MinorVersion
'    ' // of 5.1, and a FirstValidatedMajorVersion/FirstValidatedMinorVersion of
'    ' // 5.0.  To validate packages signed for any previous OS release, specify
'    ' // 0 for these fields.  To only validate against the target alternate
'    ' // platform, specify the same values as those in the MajorVersion and
'    ' // MinorVersion fields.
'    ' //
'    DWORD FirstValidatedMajorVersion;
'    DWORD FirstValidatedMinorVersion;

'} SP_ALTPLATFORM_INFO_V2, *PSP_ALTPLATFORM_INFO_V2;

' // Size = 2 bytes
UNION SP_ALTPLATFORM_INFO_V2_UNION
   Reserved AS WORD   ' // for compatibility with V1 structure
   Flags    AS WORD   ' // indicates validity of non V1 fields
END UNION

' // Size = 28 bytes
TYPE SP_ALTPLATFORM_INFO_V2 DWORD FILL
   cbSize                       AS DWORD
   Platform                     AS DWORD
   MajorVersion                 AS DWORD
   MinorVersion                 AS DWORD
   ProcessorArchitecture        AS WORD
   SP_ALTPLATFORM_INFO_V2_UNION
   FirstValidatedMajorVersion   AS DWORD
   FirstValidatedMinorVersion   AS DWORD
END TYPE

'typedef struct _SP_ALTPLATFORM_INFO_V1 {
'    DWORD cbSize;
'    ' //
'    ' // platform to use (VER_PLATFORM_WIN32_WINDOWS or VER_PLATFORM_WIN32_NT)
'    ' //
'    DWORD Platform;
'    ' //
'    ' // major and minor version numbers to use
'    ' //
'    DWORD MajorVersion;
'    DWORD MinorVersion;
'    ' //
'    ' // processor architecture to use (PROCESSOR_ARCHITECTURE_INTEL,
'    ' // PROCESSOR_ARCHITECTURE_AMD64, or PROCESSOR_ARCHITECTURE_IA64.
'    ' //
'    WORD  ProcessorArchitecture;

'    WORD  Reserved; ' // must be zero.
'} SP_ALTPLATFORM_INFO_V1, *PSP_ALTPLATFORM_INFO_V1;

' // Size = 20 bytes
TYPE SP_ALTPLATFORM_INFO_V1 DWORD FILL
   cbSize                AS DWORD
   Platform              AS DWORD
   MajorVersion          AS DWORD
   MinorVersion          AS DWORD
   ProcessorArchitecture AS WORD
   Reserved              AS WORD
END TYPE

'#if USE_SP_ALTPLATFORM_INFO_V1 || (_SETUPAPI_VER < _WIN32_WINNT_WINXP) // use version 1 altplatform info data structure
#IF %DEF(%USE_SP_ALTPLATFORM_INFO_V1) OR (%SETUPAPI_VER < %WIN32_WINNT_WINXP)   ' // use version 1 altplatform info data structure

'typedef SP_ALTPLATFORM_INFO_V1 SP_ALTPLATFORM_INFO;
'typedef PSP_ALTPLATFORM_INFO_V1 PSP_ALTPLATFORM_INFO;
MACRO SP_ALTPLATFORM_INFO = SP_ALTPLATFORM_INFO_V1

'#else                          ' // use version 2 altplatform info data structure
#ELSE

'typedef SP_ALTPLATFORM_INFO_V2 SP_ALTPLATFORM_INFO;
'typedef PSP_ALTPLATFORM_INFO_V2 PSP_ALTPLATFORM_INFO;
MACRO SP_ALTPLATFORM_INFO = SP_ALTPLATFORM_INFO_V2

' //
' // the following flags are available to SP_ALTPLATFORM_INFO_V2
' //
%SP_ALTPLATFORM_FLAGS_VERSION_RANGE = &H0001???     ' // FirstValidatedMajor/MinorVersion

'#endif  ' // use current version of altplatform info data structure
#ENDIF


' //
' // Define structure that is filled in by SetupQueryInfOriginalFileInformation
' // to indicate the INF's original name and the original name of the (potentially
' // platform-specific) catalog file specified by that INF.
' //
' // Size = 524 bytes
TYPE SP_ORIGINAL_FILE_INFO_A BYTE
   cbSize              AS DWORD                ' DWORD
   OriginalInfName     AS ASCIIZ * %MAX_PATH   ' CHAR
   OriginalCatalogName AS ASCIIZ * %MAX_PATH   ' CHAR
END TYPE

' // Size = 1044 bytes
TYPE SP_ORIGINAL_FILE_INFO_W BYTE
   cbSize              AS DWORD                  ' DWORD
   OriginalInfName     AS WSTRINGZ * %MAX_PATH   ' WCHAR
   OriginalCatalogName AS WSTRINGZ * %MAX_PATH   ' WCHAR
END TYPE

#IF %DEF(%UNICODE)
   MACRO SP_ORIGINAL_FILE_INFO = SP_ORIGINAL_FILE_INFO_W
#ELSE
   MACRO SP_ORIGINAL_FILE_INFO = SP_ORIGINAL_FILE_INFO_A
#ENDIF

' //
' // SP_INF_INFORMATION.InfStyle values
' //
%INF_STYLE_NONE           = &H00000000???       ' // unrecognized or non-existent
%INF_STYLE_OLDNT          = &H00000001???       ' // winnt 3.x
%INF_STYLE_WIN4           = &H00000002???       ' // Win95

' //
' // Additional InfStyle flags that may be specified when calling SetupOpenInfFile.
' //
' //
%INF_STYLE_CACHE_ENABLE   = &H00000010???   ' // always cache INF, even outside of %windir%\Inf
%INF_STYLE_CACHE_DISABLE  = &H00000020???   ' // delete cached INF information
#IF %SETUPAPI_VER >= %WIN32_WINNT_WS03
%INF_STYLE_CACHE_IGNORE   = &H00000040???   ' // ignore any cached INF information
#ENDIF


' //
' // Target directory specs.
' //
%DIRID_ABSOLUTE          = -1              ' // real 32-bit -1
%DIRID_ABSOLUTE_16BIT    = &Hffff%         ' // 16-bit -1 for compat w/setupx
%DIRID_NULL              = 0
%DIRID_SRCPATH           = 1
%DIRID_WINDOWS           = 10
%DIRID_SYSTEM            = 11              ' // system32
%DIRID_DRIVERS           = 12
%DIRID_IOSUBSYS          = %DIRID_DRIVERS
%DIRID_INF               = 17
%DIRID_HELP              = 18
%DIRID_FONTS             = 20
%DIRID_VIEWERS           = 21
%DIRID_COLOR             = 23
%DIRID_APPS              = 24
%DIRID_SHARED            = 25
%DIRID_BOOT              = 30

%DIRID_SYSTEM16          = 50
%DIRID_SPOOL             = 51
%DIRID_SPOOLDRIVERS      = 52
%DIRID_USERPROFILE       = 53
%DIRID_LOADER            = 54
%DIRID_PRINTPROCESSOR    = 55

%DIRID_DEFAULT           = %DIRID_SYSTEM

' //
' // The following DIRIDs are for commonly-used shell "special folders".  The
' // complete list of such folders is contained in shlobj.h.  In that headerfile,
' // each folder is assigned a CSIDL_* value.  The DIRID values below are created
' // by taking the CSIDL value in shlobj.h and OR'ing it with 0x4000.  Thus, if
' // an INF needs to reference other special folders not defined below, it may
' // generate one using the above mechanism, and setupapi will automatically deal
' // with it and use the corresponding shell's path where appropriate.  (Remember
' // that DIRIDs must be specified in decimal, not hex, in an INF when used for
' // string substitution.)
' //
%DIRID_COMMON_STARTMENU        = 16406  ' // All Users\Start Menu
%DIRID_COMMON_PROGRAMS         = 16407  ' // All Users\Start Menu\Programs
%DIRID_COMMON_STARTUP          = 16408  ' // All Users\Start Menu\Programs\Startup
%DIRID_COMMON_DESKTOPDIRECTORY = 16409  ' // All Users\Desktop
%DIRID_COMMON_FAVORITES        = 16415  ' // All Users\Favorites
%DIRID_COMMON_APPDATA          = 16419  ' // All Users\Application Data

%DIRID_PROGRAM_FILES           = 16422  ' // Program Files
%DIRID_SYSTEM_X86              = 16425  ' // system32 on RISC
%DIRID_PROGRAM_FILES_X86       = 16426  ' // Program Files on RISC
%DIRID_PROGRAM_FILES_COMMON    = 16427  ' // Program Files\Common
%DIRID_PROGRAM_FILES_COMMONX86 = 16428  ' // x86 Program Files\Common on RISC

%DIRID_COMMON_TEMPLATES        = 16429  ' // All Users\Templates
%DIRID_COMMON_DOCUMENTS        = 16430  ' // All Users\Documents


' //
' // First user-definable dirid. See SetupSetDirectoryId().
' //
%DIRID_USER                    = &H8000???

' //
' // Setup callback notification routine type
' //
'typedef UINT (CALLBACK* PSP_FILE_CALLBACK_A)(
'    IN PVOID Context,
'    IN UINT Notification,
'    IN UINT_PTR Param1,
'    IN UINT_PTR Param2
'    );

'FUNCTION PSP_FILE_CALLBACK_A ( _
'   BYVAL DWORD _                              ' IN PVOID Context
' , BYVAL DWORD _                              ' IN UINT Notification
' , BYVAL DWORD _                              ' IN UINT_PTR Param1
' , BYVAL DWORD _                              ' IN UINT_PTR Param2
' ) AS DWORD                                             ' UINT

'typedef UINT (CALLBACK* PSP_FILE_CALLBACK_W)(
'    IN PVOID Context,
'    IN UINT Notification,
'    IN UINT_PTR Param1,
'    IN UINT_PTR Param2
'    );

'FUNCTION PSP_FILE_CALLBACK_W ( _
'   BYVAL DWORD _                              ' IN PVOID Context
' , BYVAL DWORD _                              ' IN UINT Notification
' , BYVAL DWORD _                              ' IN UINT_PTR Param1
' , BYVAL DWORD _                              ' IN UINT_PTR Param2
' ) AS DWORD                                             ' UINT


' //
' // Operation/queue start/end notification. These are ordinal values.
' //
%SPFILENOTIFY_STARTQUEUE         = &H00000001???
%SPFILENOTIFY_ENDQUEUE           = &H00000002???
%SPFILENOTIFY_STARTSUBQUEUE      = &H00000003???
%SPFILENOTIFY_ENDSUBQUEUE        = &H00000004???
%SPFILENOTIFY_STARTDELETE        = &H00000005???
%SPFILENOTIFY_ENDDELETE          = &H00000006???
%SPFILENOTIFY_DELETEERROR        = &H00000007???
%SPFILENOTIFY_STARTRENAME        = &H00000008???
%SPFILENOTIFY_ENDRENAME          = &H00000009???
%SPFILENOTIFY_RENAMEERROR        = &H0000000a???
%SPFILENOTIFY_STARTCOPY          = &H0000000b???
%SPFILENOTIFY_ENDCOPY            = &H0000000c???
%SPFILENOTIFY_COPYERROR          = &H0000000d???
%SPFILENOTIFY_NEEDMEDIA          = &H0000000e???
%SPFILENOTIFY_QUEUESCAN          = &H0000000f???
' //
' // These are used with SetupIterateCabinet().
' //
%SPFILENOTIFY_CABINETINFO        = &H00000010???
%SPFILENOTIFY_FILEINCABINET      = &H00000011???
%SPFILENOTIFY_NEEDNEWCABINET     = &H00000012???
%SPFILENOTIFY_FILEEXTRACTED      = &H00000013???
%SPFILENOTIFY_FILEOPDELAYED      = &H00000014???
' //
' // These are used for backup operations
' //
%SPFILENOTIFY_STARTBACKUP        = &H00000015???
%SPFILENOTIFY_BACKUPERROR        = &H00000016???
%SPFILENOTIFY_ENDBACKUP          = &H00000017???
' //
' // Extended notification for SetupScanFileQueue(Flags=SPQ_SCAN_USE_CALLBACKEX)
' //
%SPFILENOTIFY_QUEUESCAN_EX       = &H00000018???

%SPFILENOTIFY_STARTREGISTRATION  = &H00000019???
%SPFILENOTIFY_ENDREGISTRATION    = &H00000020???

'#if _SETUPAPI_VER >= _WIN32_WINNT_WINXP
#IF %SETUPAPI_VER >= %WIN32_WINNT_WINXP

' //
' // Extended notification for SetupScanFileQueue(Flags=SPQ_SCAN_USE_CALLBACK_SIGNERINFO)
' //
%SPFILENOTIFY_QUEUESCAN_SIGNERINFO = &H00000040???

#ENDIF
'#endif

' //
' // Copy notification. These are bit flags that may be combined.
' //
%SPFILENOTIFY_LANGMISMATCH       = &H00010000???
%SPFILENOTIFY_TARGETEXISTS       = &H00020000???
%SPFILENOTIFY_TARGETNEWER        = &H00040000???

' //
' // File operation codes and callback outcomes.
' //
%FILEOP_COPY                     = 0
%FILEOP_RENAME                   = 1
%FILEOP_DELETE                   = 2
%FILEOP_BACKUP                   = 3

%FILEOP_ABORT                    = 0
%FILEOP_DOIT                     = 1
%FILEOP_SKIP                     = 2
%FILEOP_RETRY                    = %FILEOP_DOIT
%FILEOP_NEWPATH                  = 4

' //
' // Flags in inf copy sections
' //
%COPYFLG_WARN_IF_SKIP            = &H00000001???  ' // warn if user tries to skip file
%COPYFLG_NOSKIP                  = &H00000002???  ' // disallow skipping this file
%COPYFLG_NOVERSIONCHECK          = &H00000004???  ' // ignore versions and overwrite target
%COPYFLG_FORCE_FILE_IN_USE       = &H00000008???  ' // force file-in-use behavior
%COPYFLG_NO_OVERWRITE            = &H00000010???  ' // do not copy if file exists on target
%COPYFLG_NO_VERSION_DIALOG       = &H00000020???  ' // do not copy if target is newer
%COPYFLG_OVERWRITE_OLDER_ONLY    = &H00000040???  ' // leave target alone if version same as source
%COPYFLG_PROTECTED_WINDOWS_DRIVER_FILE = &H00000100???   ' // a Windows driver file to be
                                                         ' // protected as other Windows system files
%COPYFLG_REPLACEONLY             = &H00000400???  ' // copy only if file exists on target
%COPYFLG_NODECOMP                = &H00000800???  ' // don't attempt to decompress file; copy as-is
%COPYFLG_REPLACE_BOOT_FILE       = &H00001000???  ' // file must be present upon reboot (i.e., it's
                                                  ' // needed by the loader); this flag implies a reboot
%COPYFLG_NOPRUNE                 = &H00002000???  ' // never prune this file
%COPYFLG_IN_USE_TRY_RENAME       = &H00004000???  ' // If file in use, try to rename the target first

' //
' // Flags in inf delete sections
' // New flags go in high word
' //
%DELFLG_IN_USE                   = &H00000001???  ' // queue in-use file for delete
%DELFLG_IN_USE1                  = &H00010000???  ' // high-word version of DELFLG_IN_USE

' //
' // Source and file paths. Used when notifying queue callback
' // of SPFILENOTIFY_STARTxxx, SPFILENOTIFY_ENDxxx, and SPFILENOTIFY_xxxERROR.
' //
' // Size = 16 bytes
TYPE FILEPATHS_A DWORD
   Target     AS ASCIIZ PTR   ' PCSTR
   Source     AS ASCIIZ PTR   ' PCSTR // not used for delete operations
   Win32Error AS DWORD        ' UINT
   Flags      AS DWORD        ' DWORD // such as SP_COPY_NOSKIP for copy errors
END TYPE

' // Size = 16 bytes
TYPE FILEPATHS_W DWORD
   Target     AS WSTRINGZ PTR   ' PCWSTR
   Source     AS WSTRINGZ PTR   ' PCWSTR // not used for delete operations
   Win32Error AS DWORD          ' UINT
   Flags      AS DWORD          ' DWORD  // such as SP_COPY_NOSKIP for copy errors
END TYPE

#IF %DEF(%UNICODE)
   MACRO FILEPATHS = FILEPATHS_W
#ELSE
   MACRO FILEPATHS = FILEPATHS_A
#ENDIF

'#if _SETUPAPI_VER >= _WIN32_WINNT_WINXP
#IF %SETUPAPI_VER >= %WIN32_WINNT_WINXP

' // Size = 28 bytes
TYPE FILEPATHS_SIGNERINFO_A DWORD
   Target        AS ASCIIZ PTR   ' PCSTR
   Source        AS ASCIIZ PTR   ' PCSTR // not used for delete operations
   Win32Error    AS DWORD        ' UINT
   Flags         AS DWORD        ' DWORD // such as SP_COPY_NOSKIP for copy errors
   DigitalSigner AS ASCIIZ PTR   ' PCSTR
   Version       AS ASCIIZ PTR   ' PCSTR
   CatalogFile   AS ASCIIZ PTR   ' PCSTR
END TYPE

' // Size = 28 bytes
TYPE FILEPATHS_SIGNERINFO_W DWORD
   Target        AS WSTRINGZ PTR   ' PCWSTR
   Source        AS WSTRINGZ PTR   ' PCWSTR // not used for delete operations
   Win32Error    AS DWORD          ' UINT
   Flags         AS DWORD          ' DWORD  // such as SP_COPY_NOSKIP for copy errors
   DigitalSigner AS WSTRINGZ PTR   ' PCWSTR
   Version       AS WSTRINGZ PTR   ' PCWSTR
   CatalogFile   AS WSTRINGZ PTR   ' PCWSTR
END TYPE

#IF %DEF(%UNICODE)
   MACRO FILEPATHS_SIGNERINFO = FILEPATHS_SIGNERINFO_W
#ELSE
   MACRO FILEPATHS_SIGNERINFO = FILEPATHS_SIGNERINFO_A
#ENDIF

'#endif // _SETUPAPI_VER >= _WIN32_WINNT_WINXP
#ENDIF   ' // _SETUPAPI_VER >= 0x0501

' //
' // Structure used with SPFILENOTIFY_NEEDMEDIA
' //
' // Size = 24 bytes
TYPE SOURCE_MEDIA_A DWORD
   Reserved    AS ASCIIZ PTR   ' PCSTR
   Tagfile     AS ASCIIZ PTR   ' PCSTR // may be NULL
   Description AS ASCIIZ PTR   ' PCSTR
   ' //
   ' // Pathname part and filename part of source file
   ' // that caused us to need the media.
   ' //
   SourcePath  AS ASCIIZ PTR   ' PCSTR
   SourceFile  AS ASCIIZ PTR   ' PCSTR
   Flags       AS DWORD        ' DWORD // subset of SP_COPY_xxx
END TYPE

' // Size = 24 bytes
TYPE SOURCE_MEDIA_W DWORD
   Reserved    AS WSTRINGZ PTR   ' PCWSTR
   Tagfile     AS WSTRINGZ PTR   ' PCWSTR // may be NULL
   Description AS WSTRINGZ PTR   ' PCWSTR
   ' //
   ' // Pathname part and filename part of source file
   ' // that caused us to need the media.
   ' //
   SourcePath  AS WSTRINGZ PTR   ' PCWSTR
   SourceFile  AS WSTRINGZ PTR   ' PCWSTR
   Flags       AS DWORD          ' DWORD  // subset of SP_COPY_xxx
END TYPE

#IF %DEF(%UNICODE)
   MACRO SOURCE_MEDIA = SOURCE_MEDIA_W
#ELSE
   MACRO SOURCE_MEDIA = SOURCE_MEDIA_A
#ENDIF

' //
' // Structure used with SPFILENOTIFY_CABINETINFO and
' // SPFILENOTIFY_NEEDNEWCABINET
' //
' // Size = 16 bytes
TYPE CABINET_INFO_A DWORD FILL
   CabinetPath   AS ASCIIZ PTR   ' PCSTR
   CabinetFile   AS ASCIIZ PTR   ' PCSTR
   DiskName      AS ASCIIZ PTR   ' PCSTR
   SetId         AS WORD         ' USHORT
   CabinetNumber AS WORD         ' USHORT
END TYPE

' // Size = 16 bytes
TYPE CABINET_INFO_W DWORD FILL
   CabinetPath   AS WSTRINGZ PTR   ' PCWSTR
   CabinetFile   AS WSTRINGZ PTR   ' PCWSTR
   DiskName      AS WSTRINGZ PTR   ' PCWSTR
   SetId         AS WORD           ' USHORT
   CabinetNumber AS WORD           ' USHORT
END TYPE

#IF %DEF(%UNICODE)
   MACRO CABINET_INFO = CABINET_INFO_W
#ELSE
   MACRO CABINET_INFO = CABINET_INFO_A
#ENDIF

' //
' // Structure used with SPFILENOTIFY_FILEINCABINET
' //
' // Size = 278 bytes
TYPE FILE_IN_CABINET_INFO_A DWORD FILL
   NameInCabinet  AS ASCIIZ PTR           ' PCSTR
   FileSize       AS DWORD                ' DWORD
   Win32Error     AS DWORD                ' DWORD
   DosDate        AS WORD                 ' WORD
   DosTime        AS WORD                 ' WORD
   DosAttribs     AS WORD                 ' WORD
   FullTargetName AS ASCIIZ * %MAX_PATH   ' CHAR
END TYPE

' // Size = 538 bytes
TYPE FILE_IN_CABINET_INFO_W DWORD FILL
   NameInCabinet  AS WSTRINGZ PTR           ' PCWSTR
   FileSize       AS DWORD                  ' DWORD
   Win32Error     AS DWORD                  ' DWORD
   DosDate        AS WORD                   ' WORD
   DosTime        AS WORD                   ' WORD
   DosAttribs     AS WORD                   ' WORD
   FullTargetName AS WSTRINGZ * %MAX_PATH   ' WCHAR
END TYPE

#IF %DEF(%UNICODE)
   MACRO FILE_IN_CABINET_INFO = FILE_IN_CABINET_INFO_W
#ELSE
   MACRO FILE_IN_CABINET_INFO = FILE_IN_CABINET_INFO_A
#ENDIF

' //
' // Structure used for SPFILENOTIFY_***REGISTRATION
' // callback
' //

' // Size = 16 bytes
TYPE SP_REGISTER_CONTROL_STATUSA DWORD
   cbSize      AS DWORD        ' DWORD
   FileName    AS ASCIIZ PTR   ' PCSTR
   Win32Error  AS DWORD        ' DWORD
   FailureCode AS DWORD        ' DWORD
END TYPE

' // Size = 16 bytes
TYPE SP_REGISTER_CONTROL_STATUSW DWORD
   cbSize      AS DWORD          ' DWORD
   FileName    AS WSTRINGZ PTR   ' PCWSTR
   Win32Error  AS DWORD          ' DWORD
   FailureCode AS DWORD          ' DWORD
END TYPE

' //
' // valid values for SP_REGISTER_CONTROL_STATUS.FailureCode field
' //

%SPREG_SUCCESS     = &H00000000???
%SPREG_LOADLIBRARY = &H00000001???
%SPREG_GETPROCADDR = &H00000002???
%SPREG_REGSVR      = &H00000003???
%SPREG_DLLINSTALL  = &H00000004???
%SPREG_TIMEOUT     = &H00000005???
%SPREG_UNKNOWN     = &HFFFFFFFF???

' //
' // Define type for setup file queue
' //
'typedef PVOID HSPFILEQ;

' //
' // Structure used with SetupQueueCopyIndirect
' //
' // Size = 48 bytes
TYPE SP_FILE_COPY_PARAMS_A DWORD
   cbSize             AS DWORD        ' DWORD
   QueueHandle        AS DWORD        ' HSPFILEQ
   SourceRootPath     AS ASCIIZ PTR   ' PCSTR     OPTIONAL
   SourcePath         AS ASCIIZ PTR   ' PCSTR     OPTIONAL
   SourceFilename     AS ASCIIZ PTR   ' PCSTR
   SourceDescription  AS ASCIIZ PTR   ' PCSTR     OPTIONAL
   SourceTagfile      AS ASCIIZ PTR   ' PCSTR     OPTIONAL
   TargetDirectory    AS ASCIIZ PTR   ' PCSTR
   TargetFilename     AS ASCIIZ PTR   ' PCSTR     OPTIONAL
   CopyStyle          AS DWORD        ' DWORD
   LayoutInf          AS DWORD        ' HINF      OPTIONAL
   SecurityDescriptor AS ASCIIZ PTR   ' PCSTR     OPTIONAL
END TYPE

' // Size = 48 bytes
TYPE SP_FILE_COPY_PARAMS_W DWORD
   cbSize             AS DWORD          ' DWORD
   QueueHandle        AS DWORD          ' HSPFILEQ
   SourceRootPath     AS WSTRINGZ PTR   ' PCWSTR     OPTIONAL
   SourcePath         AS WSTRINGZ PTR   ' PCWSTR     OPTIONAL
   SourceFilename     AS WSTRINGZ PTR   ' PCWSTR
   SourceDescription  AS WSTRINGZ PTR   ' PCWSTR     OPTIONAL
   SourceTagfile      AS WSTRINGZ PTR   ' PCWSTR     OPTIONAL
   TargetDirectory    AS WSTRINGZ PTR   ' PCWSTR
   TargetFilename     AS WSTRINGZ PTR   ' PCWSTR     OPTIONAL
   CopyStyle          AS DWORD          ' DWORD
   LayoutInf          AS DWORD          ' HINF      OPTIONAL
   SecurityDescriptor AS WSTRINGZ PTR   ' PCSTR     OPTIONAL
END TYPE

#IF %DEF(%UNICODE)
   MACRO SP_FILE_COPY_PARAMS = SP_FILE_COPY_PARAMS_W
#ELSE
   MACRO SP_FILE_COPY_PARAMS = SP_FILE_COPY_PARAMS_A
#ENDIF

' //
' // Define type for setup disk space list
' //
'typedef PVOID HDSKSPC;

' //
' // Define type for reference to device information set
' //
'typedef PVOID HDEVINFO;

' //
' // Device information structure (references a device instance
' // that is a member of a device information set)
' //
' // Size = 28 bytes
TYPE SP_DEVINFO_DATA DWORD
   cbSize    AS DWORD   ' DWORD
   ClassGuid AS GUID    ' GUID
   DevInst   AS DWORD   ' DWORD // DEVINST handle
   Reserved  AS DWORD   ' ULONG_PTR
END TYPE

' //
' // Device interface information structure (references a device
' // interface that is associated with the device information
' // element that owns it).
' //
' // Size = 28 bytes
TYPE SP_DEVICE_INTERFACE_DATA DWORD
   cbSize             AS DWORD   ' DWORD
   InterfaceClassGuid AS GUID    ' GUID
   Flags              AS DWORD   ' DWORD
   Reserved           AS DWORD   ' ULONG_PTR
END TYPE

' //
' // Flags for SP_DEVICE_INTERFACE_DATA.Flags field.
' //
%SPINT_ACTIVE  = &H00000001???
%SPINT_DEFAULT = &H00000002???
%SPINT_REMOVED = &H00000004???

' //
' // Backward compatibility--do not use.
' //
'typedef SP_DEVICE_INTERFACE_DATA  SP_INTERFACE_DEVICE_DATA;
'typedef PSP_DEVICE_INTERFACE_DATA PSP_INTERFACE_DEVICE_DATA;
'#define SPID_ACTIVE               SPINT_ACTIVE
'#define SPID_DEFAULT              SPINT_DEFAULT
'#define SPID_REMOVED              SPINT_REMOVED


' // Size = 5 bytes
TYPE SP_DEVICE_INTERFACE_DETAIL_DATA_A BYTE
   cbSize        AS DWORD   ' DWORD
   DevicePath(0) AS BYTE    ' [ANYSIZE_ARRAY] CHAR
END TYPE

' // Size = 6 bytes
TYPE SP_DEVICE_INTERFACE_DETAIL_DATA_W WORD
   cbSize        AS DWORD   ' DWORD
   DevicePath(0) AS WORD    ' [ANYSIZE_ARRAY] WCHAR
END TYPE

#IF %DEF(%UNICODE)
   MACRO SP_DEVICE_INTERFACE_DETAIL_DATA = SP_DEVICE_INTERFACE_DETAIL_DATA_W
#ELSE
   MACRO SP_DEVICE_INTERFACE_DETAIL_DATA = SP_DEVICE_INTERFACE_DETAIL_DATA_A
#ENDIF

' //
' // Backward compatibility--do not use.
' //
'typedef SP_DEVICE_INTERFACE_DETAIL_DATA_W SP_INTERFACE_DEVICE_DETAIL_DATA_W;
'typedef PSP_DEVICE_INTERFACE_DETAIL_DATA_W PSP_INTERFACE_DEVICE_DETAIL_DATA_W;
'typedef SP_DEVICE_INTERFACE_DETAIL_DATA_A SP_INTERFACE_DEVICE_DETAIL_DATA_A;
'typedef PSP_DEVICE_INTERFACE_DETAIL_DATA_A PSP_INTERFACE_DEVICE_DETAIL_DATA_A;

' //
' // Structure for detailed information on a device information set (used for
' // SetupDiGetDeviceInfoListDetail which supercedes the functionality of
' // SetupDiGetDeviceInfoListClass).
' //
' // Size = 287 bytes
TYPE SP_DEVINFO_LIST_DETAIL_DATA_A BYTE
   cbSize              AS DWORD   ' DWORD
   ClassGuid           AS GUID    ' GUID
   RemoteMachineHandle AS DWORD   ' HANDLE
   RemoteMachineName   AS ASCIIZ * %SP_MAX_MACHINENAME_LENGTH   ' CHAR
END TYPE

' // Size = 550 bytes
TYPE SP_DEVINFO_LIST_DETAIL_DATA_W BYTE
   cbSize              AS DWORD   ' DWORD
   ClassGuid           AS GUID    ' GUID
   RemoteMachineHandle AS DWORD   ' HANDLE
   RemoteMachineName   AS WSTRINGZ * %SP_MAX_MACHINENAME_LENGTH  ' WCHAR
END TYPE

#IF %DEF(%UNICODE)
   MACRO SP_DEVINFO_LIST_DETAIL_DATA = SP_DEVINFO_LIST_DETAIL_DATA_W
#ELSE
   MACRO SP_DEVINFO_LIST_DETAIL_DATA = SP_DEVINFO_LIST_DETAIL_DATA_A
#ENDIF

' //
' // Class installer function codes
' //
%DIF_SELECTDEVICE                    = &H00000001???
%DIF_INSTALLDEVICE                   = &H00000002???
%DIF_ASSIGNRESOURCES                 = &H00000003???
%DIF_PROPERTIES                      = &H00000004???
%DIF_REMOVE                          = &H00000005???
%DIF_FIRSTTIMESETUP                  = &H00000006???
%DIF_FOUNDDEVICE                     = &H00000007???
%DIF_SELECTCLASSDRIVERS              = &H00000008???
%DIF_VALIDATECLASSDRIVERS            = &H00000009???
%DIF_INSTALLCLASSDRIVERS             = &H0000000A???
%DIF_CALCDISKSPACE                   = &H0000000B???
%DIF_DESTROYPRIVATEDATA              = &H0000000C???
%DIF_VALIDATEDRIVER                  = &H0000000D???
%DIF_DETECT                          = &H0000000F???
%DIF_INSTALLWIZARD                   = &H00000010???
%DIF_DESTROYWIZARDDATA               = &H00000011???
%DIF_PROPERTYCHANGE                  = &H00000012???
%DIF_ENABLECLASS                     = &H00000013???
%DIF_DETECTVERIFY                    = &H00000014???
%DIF_INSTALLDEVICEFILES              = &H00000015???
%DIF_UNREMOVE                        = &H00000016???
%DIF_SELECTBESTCOMPATDRV             = &H00000017???
%DIF_ALLOW_INSTALL                   = &H00000018???
%DIF_REGISTERDEVICE                  = &H00000019???
%DIF_NEWDEVICEWIZARD_PRESELECT       = &H0000001A???
%DIF_NEWDEVICEWIZARD_SELECT          = &H0000001B???
%DIF_NEWDEVICEWIZARD_PREANALYZE      = &H0000001C???
%DIF_NEWDEVICEWIZARD_POSTANALYZE     = &H0000001D???
%DIF_NEWDEVICEWIZARD_FINISHINSTALL   = &H0000001E???
%DIF_UNUSED1                         = &H0000001F???
%DIF_INSTALLINTERFACES               = &H00000020???
%DIF_DETECTCANCEL                    = &H00000021???
%DIF_REGISTER_COINSTALLERS           = &H00000022???
%DIF_ADDPROPERTYPAGE_ADVANCED        = &H00000023???
%DIF_ADDPROPERTYPAGE_BASIC           = &H00000024???
%DIF_RESERVED1                       = &H00000025???
%DIF_TROUBLESHOOTER                  = &H00000026???
%DIF_POWERMESSAGEWAKE                = &H00000027???
%DIF_ADDREMOTEPROPERTYPAGE_ADVANCED  = &H00000028???
%DIF_UPDATEDRIVER_UI                 = &H00000029???
%DIF_FINISHINSTALL_ACTION            = &H0000002A???
%DIF_RESERVED2                       = &H00000030???

' //
' // Obsoleted DIF codes (do not use)
' //
%DIF_MOVEDEVICE                      = &H0000000E???


'typedef UINT        DI_FUNCTION;    ' // Function type for device installer


' //
' // Device installation parameters structure (associated with a
' // particular device information element, or globally with a device
' // information set)
' //
' // Size = 296 bytes
TYPE SP_DEVINSTALL_PARAMS_A DWORD
   cbSize                   AS DWORD                ' DWORD
   Flags                    AS DWORD                ' DWORD
   FlagsEx                  AS DWORD                ' DWORD
   hwndParent               AS DWORD                ' HWND
   InstallMsgHandler        AS DWORD                ' PSP_FILE_CALLBACK
   InstallMsgHandlerContext AS DWORD                ' PVOID
   FileQueue                AS DWORD                ' HSPFILEQ
   ClassInstallReserved     AS DWORD                ' ULONG_PTR
   Reserved                 AS DWORD                ' DWORD
   DriverPath               AS ASCIIZ * %MAX_PATH   ' CHAR
END TYPE

' // Size = 556 bytes
TYPE SP_DEVINSTALL_PARAMS_W DWORD
   cbSize                   AS DWORD                  ' DWORD
   Flags                    AS DWORD                  ' DWORD
   FlagsEx                  AS DWORD                  ' DWORD
   hwndParent               AS DWORD                  ' HWND
   InstallMsgHandler        AS DWORD                  ' PSP_FILE_CALLBACK
   InstallMsgHandlerContext AS DWORD                  ' PVOID
   FileQueue                AS DWORD                  ' HSPFILEQ
   ClassInstallReserved     AS DWORD                  ' ULONG_PTR
   Reserved                 AS DWORD                  ' DWORD
   DriverPath               AS WSTRINGZ * %MAX_PATH   ' WCHAR
END TYPE

#IF %DEF(%UNICODE)
   MACRO SP_DEVINSTALL_PARAMS = SP_DEVINSTALL_PARAMS_W
#ELSE
   MACRO SP_DEVINSTALL_PARAMS = SP_DEVINSTALL_PARAMS_A
#ENDIF

' //
' // SP_DEVINSTALL_PARAMS.Flags values
' //
' // Flags for choosing a device
' //
%DI_SHOWOEM                  = &H00000001???     ' // support Other... button
%DI_SHOWCOMPAT               = &H00000002???     ' // show compatibility list
%DI_SHOWCLASS                = &H00000004???     ' // show class list
%DI_SHOWALL                  = &H00000007???     ' // both class & compat list shown
%DI_NOVCP                    = &H00000008???     ' // don't create a new copy queue--use
                                                 ' // caller-supplied FileQueue
%DI_DIDCOMPAT                = &H00000010???     ' // Searched for compatible devices
%DI_DIDCLASS                 = &H00000020???     ' // Searched for class devices
%DI_AUTOASSIGNRES            = &H00000040???     ' // No UI for resources if possible

' // flags returned by DiInstallDevice to indicate need to reboot/restart
%DI_NEEDRESTART              = &H00000080???     ' // Reboot required to take effect
%DI_NEEDREBOOT               = &H00000100???     ' // ""

' // flags for device installation
%DI_NOBROWSE                 = &H00000200???     ' // no Browse... in InsertDisk

' // Flags set by DiBuildDriverInfoList
%DI_MULTMFGS                 = &H00000400???     ' // Set if multiple manufacturers in
                                                 ' // class driver list

' // Flag indicates that device is disabled
%DI_DISABLED                 = &H00000800???     ' // Set if device disabled

' // Flags for Device/Class Properties
%DI_GENERALPAGE_ADDED        = &H00001000???
%DI_RESOURCEPAGE_ADDED       = &H00002000???

' // Flag to indicate the setting properties for this Device (or class) caused a change
' // so the Dev Mgr UI probably needs to be updatd.
%DI_PROPERTIES_CHANGE        = &H00004000???

' // Flag to indicate that the sorting from the INF file should be used.
%DI_INF_IS_SORTED            = &H00008000???

' // Flag to indicate that only the the INF specified by SP_DEVINSTALL_PARAMS.DriverPath
' // should be searched.
%DI_ENUMSINGLEINF            = &H00010000???

' // Flag that prevents ConfigMgr from removing/re-enumerating devices during device
' // registration, installation, and deletion.
%DI_DONOTCALLCONFIGMG        = &H00020000???

' // The following flag can be used to install a device disabled
%DI_INSTALLDISABLED          = &H00040000???

' // Flag that causes SetupDiBuildDriverInfoList to build a device's compatible driver
' // list from its existing class driver list, instead of the normal INF search.
%DI_COMPAT_FROM_CLASS        = &H00080000???

' // This flag is set if the Class Install params should be used.
%DI_CLASSINSTALLPARAMS       = &H00100000???

' // This flag is set if the caller of DiCallClassInstaller does NOT
' // want the internal default action performed if the Class installer
' // returns ERROR_DI_DO_DEFAULT.
%DI_NODI_DEFAULTACTION       = &H00200000???

' // The setupx flag, DI_NOSYNCPROCESSING (0x00400000L) is not support in the Setup APIs.

' // flags for device installation
%DI_QUIETINSTALL             = &H00800000???     ' // don't confuse the user with
                                                 ' // questions or excess info
%DI_NOFILECOPY               = &H01000000???     ' // No file Copy necessary
%DI_FORCECOPY                = &H02000000???     ' // Force files to be copied from install path
%DI_DRIVERPAGE_ADDED         = &H04000000???     ' // Prop provider added Driver page.
%DI_USECI_SELECTSTRINGS      = &H08000000???     ' // Use Class Installer Provided strings in the Select Device Dlg
%DI_OVERRIDE_INFFLAGS        = &H10000000???     ' // Override INF flags
%DI_PROPS_NOCHANGEUSAGE      = &H20000000???     ' // No Enable/Disable in General Props

%DI_NOSELECTICONS            = &H40000000???     ' // No small icons in select device dialogs

%DI_NOWRITE_IDS              = &H80000000???     ' // Don't write HW & Compat IDs on install


' //
' // SP_DEVINSTALL_PARAMS.FlagsEx values
' //
'%DI_FLAGSEX_USEOLDINFSEARCH          = &H00000001???   ' Windows XP // Inf Search functions should not use Index Search
'%DI_FLAGSEX_RESERVED2                = &H00000002???   ' Windows XP // DI_FLAGSEX_AUTOSELECTRANK0 is obsolete
%DI_FLAGSEX_RESERVED2                = &H00000001???   ' Windows Vista // DI_FLAGSEX_USEOLDINFSEARCH is obsolete
%DI_FLAGSEX_RESERVED3                = &H00000002???   ' Windows Vista // DI_FLAGSEX_AUTOSELECTRANK0 is obsolete
%DI_FLAGSEX_CI_FAILED                = &H00000004???   ' // Failed to Load/Call class installer

'#if _SETUPAPI_VER >= _WIN32_WINNT_LONGHORN //
#IF %SETUPAPI_VER >= %WIN32_WINNT_LONGHORN
%DI_FLAGSEX_FINISHINSTALL_ACTION     = &H00000008???   ' // Class/co-installer wants to get a DIF_FINISH_INSTALL action in client context.
#ENDIF
'#endif // _SETUPAPI_VER >= _WIN32_WINNT_LONGHORN //

%DI_FLAGSEX_DIDINFOLIST              = &H00000010???   ' // Did the Class Info List
%DI_FLAGSEX_DIDCOMPATINFO            = &H00000020???   ' // Did the Compat Info List

%DI_FLAGSEX_FILTERCLASSES            = &H00000040???
%DI_FLAGSEX_SETFAILEDINSTALL         = &H00000080???
%DI_FLAGSEX_DEVICECHANGE             = &H00000100???
%DI_FLAGSEX_ALWAYSWRITEIDS           = &H00000200???
%DI_FLAGSEX_PROPCHANGE_PENDING       = &H00000400???   ' // One or more device property sheets have had changes made
                                                       ' // to them, and need to have a DIF_PROPERTYCHANGE occur.
%DI_FLAGSEX_ALLOWEXCLUDEDDRVS        = &H00000800???
%DI_FLAGSEX_NOUIONQUERYREMOVE        = &H00001000???
%DI_FLAGSEX_USECLASSFORCOMPAT        = &H00002000???   ' // Use the device's class when building compat drv list.
                                                       ' // (Ignored if DI_COMPAT_FROM_CLASS flag is specified.)
%DI_FLAGSEX_RESERVED4                = &H00004000???   ' // DI_FLAGSEX_OLDINF_IN_CLASSLIST is obsolete
%DI_FLAGSEX_NO_DRVREG_MODIFY         = &H00008000???   ' // Don't run AddReg and DelReg for device's software (driver) key.
%DI_FLAGSEX_IN_SYSTEM_SETUP          = &H00010000???   ' // Installation is occurring during initial system setup.
%DI_FLAGSEX_INET_DRIVER              = &H00020000???   ' // Driver came from Windows Update
%DI_FLAGSEX_APPENDDRIVERLIST         = &H00040000???   ' // Cause SetupDiBuildDriverInfoList to append
                                                         ' // a new driver list to an existing list.
%DI_FLAGSEX_PREINSTALLBACKUP         = &H00080000???   ' // backup all files required by old inf before install
%DI_FLAGSEX_BACKUPONREPLACE          = &H00100000???   ' // backup files required by old inf as they are replaced
%DI_FLAGSEX_DRIVERLIST_FROM_URL      = &H00200000???   ' // build driver list from INF(s) retrieved from URL specified
                                                         ' // in SP_DEVINSTALL_PARAMS.DriverPath (empty string means
                                                         ' // Windows Update website)
%DI_FLAGSEX_RESERVED1                = &H00400000???
%DI_FLAGSEX_EXCLUDE_OLD_INET_DRIVERS = &H00800000???   ' // Don't include old Internet drivers when building
                                                         ' // a driver list.
%DI_FLAGSEX_POWERPAGE_ADDED          = &H01000000???   ' // class installer added their own power page

'#if _SETUPAPI_VER >= _WIN32_WINNT_WINXP
#IF %SETUPAPI_VER >= %WIN32_WINNT_WINXP

%DI_FLAGSEX_FILTERSIMILARDRIVERS     = &H02000000???   ' // only include similar drivers in class list
%DI_FLAGSEX_INSTALLEDDRIVER          = &H04000000???   ' // only add the installed driver to the class or compat
                                                       ' // driver list.  Used in calls to SetupDiBuildDriverInfoList
%DI_FLAGSEX_NO_CLASSLIST_NODE_MERGE  = &H08000000???   ' // Don't remove identical driver nodes from the class list
%DI_FLAGSEX_ALTPLATFORM_DRVSEARCH    = &H10000000???   ' // Build driver list based on alternate platform information
                                                       ' // specified in associated file queue
%DI_FLAGSEX_RESTART_DEVICE_ONLY      = &H20000000???   ' // only restart the device drivers are being installed on as
                                                       ' // opposed to restarting all devices using those drivers.

#ENDIF
'#endif // _SETUPAPI_VER >= _WIN32_WINNT_WINXP

'#if _SETUPAPI_VER >= _WIN32_WINNT_LONGHORN
#IF %SETUPAPI_VER >= %WIN32_WINNT_LONGHORN
%DI_FLAGSEX_RECURSIVESEARCH          = &H40000000???   ' // Tell SetupDiBuildDriverInfoList to do a recursive search
%DI_FLAGSEX_SEARCH_PUBLISHED_INFS    = &H80000000???   ' // Tell SetupDiBuildDriverInfoList to do a "published INF" search
#ENDIF
'#endif // _SETUPAPI_VER >= _WIN32_WINNT_LONGHORN

' //
' // Class installation parameters header.  This must be the first field of any
' // class install parameter structure.  The InstallFunction field must be set to
' // the function code corresponding to the structure, and the cbSize field must
' // be set to the size of the header structure.  E.g.,
' //
' // SP_ENABLECLASS_PARAMS EnableClassParams;
' //
' // EnableClassParams.ClassInstallHeader.cbSize = sizeof(SP_CLASSINSTALL_HEADER);
' // EnableClassParams.ClassInstallHeader.InstallFunction = DIF_ENABLECLASS;
' //
' // Size = 8 bytes
TYPE SP_CLASSINSTALL_HEADER DWORD
   cbSize          AS DWORD   ' DWORD
   InstallFunction AS DWORD   ' DI_FUNCTION
END TYPE

' //
' // Structure corresponding to a DIF_ENABLECLASS install function.
' //
' // Size = 28 bytes
TYPE SP_ENABLECLASS_PARAMS DWORD
   ClassInstallHeader AS SP_CLASSINSTALL_HEADER
   ClassGuid          AS GUID
   EnableMessage      AS DWORD
END TYPE

%ENABLECLASS_QUERY   = 0
%ENABLECLASS_SUCCESS = 1
%ENABLECLASS_FAILURE = 2


' //
' // Values indicating a change in a device's state
' //
%DICS_ENABLE      = &H00000001???
%DICS_DISABLE     = &H00000002???
%DICS_PROPCHANGE  = &H00000003???
%DICS_START       = &H00000004???
%DICS_STOP        = &H00000005???
' //
' // Values specifying the scope of a device property change
' //
%DICS_FLAG_GLOBAL         = &H00000001???  ' // make change in all hardware profiles
%DICS_FLAG_CONFIGSPECIFIC = &H00000002???  ' // make change in specified profile only
%DICS_FLAG_CONFIGGENERAL  = &H00000004???  ' // 1 or more hardware profile-specific
                                           ' // changes to follow.
' //
' // Structure corresponding to a DIF_PROPERTYCHANGE install function.
' //
' // Size = 20 bytes
TYPE SP_PROPCHANGE_PARAMS DWORD
   ClassInstallHeader AS SP_CLASSINSTALL_HEADER
   StateChange        AS DWORD
   Scope              AS DWORD
   HwProfile          AS DWORD
END TYPE


' //
' // Structure corresponding to a DIF_REMOVE install function.
' //
' // Size = 16 bytes
TYPE SP_REMOVEDEVICE_PARAMS DWORD
   ClassInstallHeader AS SP_CLASSINSTALL_HEADER
   Scope              AS DWORD
   HwProfile          AS DWORD
END TYPE

%DI_REMOVEDEVICE_GLOBAL                  = &H00000001???
%DI_REMOVEDEVICE_CONFIGSPECIFIC          = &H00000002???


' //
' // Structure corresponding to a DIF_UNREMOVE install function.
' //
' // Size = 16 bytes
TYPE SP_UNREMOVEDEVICE_PARAMS DWORD
   ClassInstallHeader AS SP_CLASSINSTALL_HEADER
   Scope              AS DWORD
   HwProfile          AS DWORD
END TYPE

%DI_UNREMOVEDEVICE_CONFIGSPECIFIC        = &H00000002???


' //
' // Structure corresponding to a DIF_SELECTDEVICE install function.
' //
' // Size = 612 bytes
TYPE SP_SELECTDEVICE_PARAMS_A BYTE
   ClassInstallHeader AS SP_CLASSINSTALL_HEADER
   Title              AS ASCIIZ * %MAX_TITLE_LEN         ' CHAR
   Instructions       AS ASCIIZ * %MAX_INSTRUCTION_LEN   ' CHAR
   ListLabel          AS ASCIIZ * %MAX_LABEL_LEN         ' CHAR
   SubTitle           AS ASCIIZ * %MAX_SUBTITLE_LEN      ' CHAR
   Reserved(1)        AS BYTE                            ' // DWORD size alignment
END TYPE

' // Size = 1212 bytes
TYPE SP_SELECTDEVICE_PARAMS_W BYTE
   ClassInstallHeader AS SP_CLASSINSTALL_HEADER
   Title              AS WSTRINGZ * %MAX_TITLE_LEN        ' WCHAR
   Instructions       AS WSTRINGZ * %MAX_INSTRUCTION_LEN  ' WCHAR
   ListLabel          AS WSTRINGZ * %MAX_LABEL_LEN        ' WCHAR
   SubTitle           AS WSTRINGZ * %MAX_SUBTITLE_LEN     ' WCHAR
END TYPE

#IF %DEF(%UNICODE)
   MACRO SP_SELECTDEVICE_PARAMS = SP_SELECTDEVICE_PARAMS_W
#ELSE
   MACRO SP_SELECTDEVICE_PARAMS = SP_SELECTDEVICE_PARAMS_A
#ENDIF

' //
' // Callback routine for giving progress notification during detection
' //
'typedef BOOL (CALLBACK* PDETECT_PROGRESS_NOTIFY)(
'     IN PVOID ProgressNotifyParam,
'     IN DWORD DetectComplete
'     );

'FUNCTION DETECT_PROGRESS_NOTIFY ( _
'   BYVAL DWORD _                              ' IN PVOID ProgressNotifyParam
' , BYVAL DWORD _                              ' IN DWORD DetectComplete
' ) AS LONG                                              ' BOOL

' // where:
' //     ProgressNotifyParam - value supplied by caller requesting detection.
' //     DetectComplete - Percent completion, to be incremented by class
' //                      installer, as it steps thru its detection.
' //
' // Return Value - If TRUE, then detection is cancelled.  Allows caller
' //                requesting detection to stop detection asap.
' //

' //
' // Structure corresponding to a DIF_DETECT install function.
' //
' // Size = 16 bytes
TYPE SP_DETECTDEVICE_PARAMS DWORD
   ClassInstallHeader   AS SP_CLASSINSTALL_HEADER
   DetectProgressNotify AS DWORD   ' PDETECT_PROGRESS_NOTIFY
   ProgressNotifyParam  AS DWORD   ' PVOID
END TYPE

' //
' // 'Add New Device' installation wizard structure (backward-compatibility
' // only--respond to DIF_NEWDEVICEWIZARD_* requests instead).
' //
' // Structure corresponding to a DIF_INSTALLWIZARD install function.
' // (NOTE: This structure is also applicable for DIF_DESTROYWIZARDDATA,
' // but DIF_INSTALLWIZARD is the associated function code in the class
' // installation parameter structure in both cases.)
' //
' // Define maximum number of dynamic wizard pages that can be added to
' // hardware install wizard.
' //
%MAX_INSTALLWIZARD_DYNAPAGES            = 20

' // Size = 112 bytes
TYPE SP_INSTALLWIZARD_DATA DWORD
   ClassInstallHeader AS SP_CLASSINSTALL_HEADER
   Flags              AS DWORD   ' DWORD
   DynamicPages(%MAX_INSTALLWIZARD_DYNAPAGES - 1) AS DWORD   ' HPROPSHEETPAGE
   NumDynamicPages    AS DWORD   ' DWORD
   DynamicPageFlags   AS DWORD   ' DWORD
   PrivateFlags       AS DWORD   ' DWORD
   PrivateData        AS LONG    ' LPARAM
   hwndWizardDlg      AS DWORD   ' HWND
END TYPE

' //
' // SP_INSTALLWIZARD_DATA.Flags values
' //
%NDW_INSTALLFLAG_DIDFACTDEFS         = &H00000001???
%NDW_INSTALLFLAG_HARDWAREALLREADYIN  = &H00000002???
%NDW_INSTALLFLAG_NEEDRESTART         = %DI_NEEDRESTART
%NDW_INSTALLFLAG_NEEDREBOOT          = %DI_NEEDREBOOT
%NDW_INSTALLFLAG_NEEDSHUTDOWN        = &H00000200???
%NDW_INSTALLFLAG_EXPRESSINTRO        = &H00000400???
%NDW_INSTALLFLAG_SKIPISDEVINSTALLED  = &H00000800???
%NDW_INSTALLFLAG_NODETECTEDDEVS      = &H00001000???
%NDW_INSTALLFLAG_INSTALLSPECIFIC     = &H00002000???
%NDW_INSTALLFLAG_SKIPCLASSLIST       = &H00004000???
%NDW_INSTALLFLAG_CI_PICKED_OEM       = &H00008000???
%NDW_INSTALLFLAG_PCMCIAMODE          = &H00010000???
%NDW_INSTALLFLAG_PCMCIADEVICE        = &H00020000???
%NDW_INSTALLFLAG_USERCANCEL          = &H00040000???
%NDW_INSTALLFLAG_KNOWNCLASS          = &H00080000???


' //
' // SP_INSTALLWIZARD_DATA.DynamicPageFlags values
' //
' // This flag is set if a Class installer has added pages to the install wizard.
' //
%DYNAWIZ_FLAG_PAGESADDED             = &H00000001???

' //
' // Set this flag if you jump to the analyze page, and want it to
' // handle conflicts for you.  NOTE.  You will not get control back
' // in the event of a conflict if you set this flag.
' //
%DYNAWIZ_FLAG_ANALYZE_HANDLECONFLICT = &H00000008???

' //
' // The following flags are not used by the Windows NT hardware wizard.
' //
%DYNAWIZ_FLAG_INSTALLDET_NEXT        = &H00000002???
%DYNAWIZ_FLAG_INSTALLDET_PREV        = &H00000004???


' //
' // Reserve a range of wizard page resource IDs for internal use.  Some of
' // these IDs are for use by class installers that respond to the obsolete
' // DIF_INSTALLWIZARD/DIF_DESTROYWIZARDDATA messages.  These IDs are listed
' // below.
' //
%MIN_IDD_DYNAWIZ_RESOURCE_ID            = 10000
%MAX_IDD_DYNAWIZ_RESOURCE_ID            = 11000

' //
' // Define wizard page resource IDs to be used when adding custom pages to the
' // hardware install wizard via DIF_INSTALLWIZARD.  Pages marked with
' // (CLASS INSTALLER PROVIDED) _must_ be supplied by the class installer if it
' // responds to the DIF_INSTALLWIZARD request.
' //

' //
' // Resource ID for the first page that the install wizard will go to after
' // adding the class installer pages.  (CLASS INSTALLER PROVIDED)
' //
%IDD_DYNAWIZ_FIRSTPAGE                  = 10000

' //
' // Resource ID for the page that the Select Device page will go back to.
' // (CLASS INSTALLER PROVIDED)
' //
%IDD_DYNAWIZ_SELECT_PREVPAGE            = 10001

' //
' // Resource ID for the page that the Select Device page will go forward to.
' // (CLASS INSTALLER PROVIDED)
' //
%IDD_DYNAWIZ_SELECT_NEXTPAGE            = 10002

' //
' // Resource ID for the page that the Analyze dialog should go back to
' // This will only be used in the event that there is a problem, and the user
' // selects Back from the analyze proc. (CLASS INSTALLER PROVIDED)
' //
%IDD_DYNAWIZ_ANALYZE_PREVPAGE           = 10003

' //
' // Resource ID for the page that the Analyze dialog should go to if it
' // continues from the analyze proc. (CLASS INSTALLER PROVIDED)
' //
%IDD_DYNAWIZ_ANALYZE_NEXTPAGE           = 10004

' //
' // Resource ID of the hardware install wizard's select device page.
' // This ID can be used to go directly to the hardware install wizard's select
' // device page.  (This is the resource ID of the Select Device wizard page
' // retrieved via SetupDiGetWizardPage when SPWPT_SELECTDEVICE is the requested
' // PageType.)
' //
%IDD_DYNAWIZ_SELECTDEV_PAGE             = 10009

' //
' // Resource ID of the hardware install wizard's device analysis page.
' // This ID can be use to go directly to the hardware install wizard's analysis
' // page.
' //
%IDD_DYNAWIZ_ANALYZEDEV_PAGE            = 10010

' //
' // Resource ID of the hardware install wizard's install detected devices page.
' // This ID can be use to go directly to the hardware install wizard's install
' // detected devices page.
' //
%IDD_DYNAWIZ_INSTALLDETECTEDDEVS_PAGE   = 10011

' //
' // Resource ID of the hardware install wizard's select class page.
' // This ID can be use to go directly to the hardware install wizard's select
' // class page.
' //
%IDD_DYNAWIZ_SELECTCLASS_PAGE           = 10012

' //
' // The following class installer-provided wizard page resource IDs are not used
' // by the Windows NT hardware wizard.
' //
%IDD_DYNAWIZ_INSTALLDETECTED_PREVPAGE   = 10006
%IDD_DYNAWIZ_INSTALLDETECTED_NEXTPAGE   = 10007
%IDD_DYNAWIZ_INSTALLDETECTED_NODEVS     = 10008


' //
' // Structure corresponding to the following DIF_NEWDEVICEWIZARD_* install
' // functions:
' //
' //     DIF_NEWDEVICEWIZARD_PRESELECT
' //     DIF_NEWDEVICEWIZARD_SELECT
' //     DIF_NEWDEVICEWIZARD_PREANALYZE
' //     DIF_NEWDEVICEWIZARD_POSTANALYZE
' //     DIF_NEWDEVICEWIZARD_FINISHINSTALL
' //
' // Size = 100 bytes
TYPE SP_NEWDEVICEWIZARD_DATA DWORD
   ClassInstallHeader AS SP_CLASSINSTALL_HEADER
   Flags              AS DWORD   ' DWORD // presently unused--must be zero.
   DynamicPages(%MAX_INSTALLWIZARD_DYNAPAGES - 1) AS DWORD   ' HPROPSHEETPAGE
   NumDynamicPages    AS DWORD   ' DWORD
   hwndWizardDlg      AS DWORD   ' HWND
END TYPE

' //
' // The same structure is also used for retrieval of property pages via the
' // following install functions:
' //
' //     DIF_ADDPROPERTYPAGE_ADVANCED
' //     DIF_ADDPROPERTYPAGE_BASIC
' //     DIF_ADDREMOTEPROPERTYPAGE_ADVANCED
' //
'typedef SP_NEWDEVICEWIZARD_DATA SP_ADDPROPERTYPAGE_DATA;
'typedef PSP_NEWDEVICEWIZARD_DATA PSP_ADDPROPERTYPAGE_DATA;


' //
' // Structure corresponding to the DIF_TROUBLESHOOTER install function
' //
' // Size = 528 bytes
TYPE SP_TROUBLESHOOTER_PARAMS_A DWORD
   ClassInstallHeader AS SP_CLASSINSTALL_HEADER
   ChmFile            AS ASCIIZ * %MAX_PATH   ' CHAR
   HtmlTroubleShooter AS ASCIIZ * %MAX_PATH   ' CHAR
END TYPE

' // Size = 1048 bytes
TYPE SP_TROUBLESHOOTER_PARAMS_W DWORD
   ClassInstallHeader AS SP_CLASSINSTALL_HEADER
   ChmFile            AS WSTRINGZ * %MAX_PATH  ' WCHAR
   HtmlTroubleShooter AS WSTRINGZ * %MAX_PATH  ' WCHAR
END TYPE

#IF %DEF(%UNICODE)
   MACRO SP_TROUBLESHOOTER_PARAMS = SP_TROUBLESHOOTER_PARAMS_W
#ELSE
   MACRO SP_TROUBLESHOOTER_PARAMS = SP_TROUBLESHOOTER_PARAMS_A
#ENDIF

' //
' // Structure corresponding to the DIF_POWERMESSAGEWAKE install function
' //
' // Size = 520 bytes
TYPE SP_POWERMESSAGEWAKE_PARAMS_A DWORD
   ClassInstallHeader AS SP_CLASSINSTALL_HEADER
   PowerMessageWake   AS ASCIIZ * %LINE_LEN * 2   ' CHAR
END TYPE

' // Size = 1032 bytes
TYPE SP_POWERMESSAGEWAKE_PARAMS_W DWORD
   ClassInstallHeader AS SP_CLASSINSTALL_HEADER
   PowerMessageWake   AS WSTRINGZ * %LINE_LEN * 2   ' WCHAR
END TYPE

#IF %DEF(%UNICODE)
   MACRO SP_POWERMESSAGEWAKE_PARAMS = SP_POWERMESSAGEWAKE_PARAMS_W
#ELSE
   MACRO SP_POWERMESSAGEWAKE_PARAMS = SP_POWERMESSAGEWAKE_PARAMS_A
#ENDIF

' //
' // Driver information structure (member of a driver info list that may be associated
' // with a particular device instance, or (globally) with a device information set)
' //
' // Size = 796 bytes
TYPE SP_DRVINFO_DATA_V2_A BYTE
   cbSize        AS DWORD                ' DWORD
   DriverType    AS DWORD                ' DWORD
   Reserved      AS DWORD                ' ULONG_PTR
   Description   AS ASCIIZ * %LINE_LEN   ' CHAR
   MfgName       AS ASCIIZ * %LINE_LEN   ' CHAR
   ProviderName  AS ASCIIZ * %LINE_LEN   ' CHAR
   DriverDate    AS FILETIME             ' FILETIME
   DriverVersion AS QUAD                 ' DWORDLONG
END TYPE

' // Size = 1564 bytes
TYPE SP_DRVINFO_DATA_V2_W BYTE
   cbSize        AS DWORD                  ' DWORD
   DriverType    AS DWORD                  ' DWORD
   Reserved      AS DWORD                  ' ULONG_PTR
   Description   AS WSTRINGZ * %LINE_LEN   ' WCHAR
   MfgName       AS WSTRINGZ * %LINE_LEN   ' WCHAR
   ProviderName  AS WSTRINGZ * %LINE_LEN   ' WCHAR
   DriverDate    AS FILETIME               ' FILETIME
   DriverVersion AS QUAD                   ' DWORDLONG
END TYPE

#IF %DEF(%UNICODE)
   MACRO SP_DRVINFO_DATA_V2 = SP_DRVINFO_DATA_V2_W
#ELSE
   MACRO SP_DRVINFO_DATA_V2 = SP_DRVINFO_DATA_V2_A
#ENDIF

' //
' // Version 1 of the SP_DRVINFO_DATA structures, used only for compatibility
' // with Windows NT 4.0/Windows 95/98 SETUPAPI.DLL
' //
' // Size = 780 bytes
TYPE SP_DRVINFO_DATA_V1_A BYTE
   cbSize       AS DWORD                ' DWORD
   DriverType   AS DWORD                ' DWORD
   Reserved     AS DWORD                ' ULONG_PTR
   Description  AS ASCIIZ * %LINE_LEN   ' CHAR
   MfgName      AS ASCIIZ * %LINE_LEN   ' CHAR
   ProviderName AS ASCIIZ * %LINE_LEN   ' CHAR
END TYPE

' // Size = 1548 bytes
TYPE SP_DRVINFO_DATA_V1_W BYTE
   cbSize       AS DWORD                  ' DWORD
   DriverType   AS DWORD                  ' DWORD
   Reserved     AS DWORD                  ' ULONG_PTR
   Description  AS WSTRINGZ * %LINE_LEN   ' WCHAR
   MfgName      AS WSTRINGZ * %LINE_LEN   ' WCHAR
   ProviderName AS WSTRINGZ * %LINE_LEN   ' WCHAR
END TYPE

#IF %DEF(%UNICODE)
   MACRO SP_DRVINFO_DATA_V1 = SP_DRVINFO_DATA_V1_W
#ELSE
   MACRO SP_DRVINFO_DATA_V1 = SP_DRVINFO_DATA_V1_A
#ENDIF

#IF %DEF(%USE_SP_DRVINFO_DATA_V1) OR (%SETUPAPI_VER < %WIN32_WINNT_WIN2K)  ' // use version 1 driver info data structure

'typedef SP_DRVINFO_DATA_V1_A SP_DRVINFO_DATA_A;
'typedef PSP_DRVINFO_DATA_V1_A PSP_DRVINFO_DATA_A;
'typedef SP_DRVINFO_DATA_V1_W SP_DRVINFO_DATA_W;
'typedef PSP_DRVINFO_DATA_V1_W PSP_DRVINFO_DATA_W;
'typedef SP_DRVINFO_DATA_V1 SP_DRVINFO_DATA;
'typedef PSP_DRVINFO_DATA_V1 PSP_DRVINFO_DATA;

MACRO SP_DRVINFO_DATA_A = SP_DRVINFO_DATA_V1_A
MACRO SP_DRVINFO_DATA_W = SP_DRVINFO_DATA_V1_W
#IF %DEF(%UNICODE)
   MACRO SP_DRVINFO_DATA = SP_DRVINFO_DATA_V1_W
#ELSE
   MACRO SP_DRVINFO_DATA = SP_DRVINFO_DATA_V1_A
#ENDIF

#ELSE                       ' // use version 2 driver info data structure

'typedef SP_DRVINFO_DATA_V2_A SP_DRVINFO_DATA_A;
'typedef PSP_DRVINFO_DATA_V2_A PSP_DRVINFO_DATA_A;
'typedef SP_DRVINFO_DATA_V2_W SP_DRVINFO_DATA_W;
'typedef PSP_DRVINFO_DATA_V2_W PSP_DRVINFO_DATA_W;
'typedef SP_DRVINFO_DATA_V2 SP_DRVINFO_DATA;
'typedef PSP_DRVINFO_DATA_V2 PSP_DRVINFO_DATA;

MACRO SP_DRVINFO_DATA_A = SP_DRVINFO_DATA_V2_A
MACRO SP_DRVINFO_DATA_W = SP_DRVINFO_DATA_V2_W
#IF %DEF(%UNICODE)
   MACRO SP_DRVINFO_DATA = SP_DRVINFO_DATA_V2_W
#ELSE
   MACRO SP_DRVINFO_DATA = SP_DRVINFO_DATA_V2_A
#ENDIF

#ENDIF  ' // use current version of driver info data structure

' //
' // Driver information details structure (provides detailed information about a
' // particular driver information structure)
' //
' // Size = 797 bytes
TYPE SP_DRVINFO_DETAIL_DATA_A BYTE
   cbSize          AS DWORD                ' DWORD
   InfDate         AS FILETIME             ' FILETIME
   CompatIDsOffset AS DWORD                ' DWORD
   CompatIDsLength AS DWORD                ' DWORD
   Reserved        AS DWORD                ' ULONG_PTR
   SectionName     AS ASCIIZ * %LINE_LEN   ' CHAR
   InfFileName     AS ASCIIZ * %MAX_PATH   ' CHAR
   DrvDescription  AS ASCIIZ * %LINE_LEN   ' CHAR
   HardwareID(0)   AS BYTE                 ' [ANYSIZE_ARRAY] CHAR
END TYPE

' // Size = 1570 bytes
TYPE SP_DRVINFO_DETAIL_DATA_W BYTE
   cbSize          AS DWORD                  ' DWORD
   InfDate         AS FILETIME               ' FILETIME
   CompatIDsOffset AS DWORD                  ' DWORD
   CompatIDsLength AS DWORD                  ' DWORD
   Reserved        AS DWORD                  ' ULONG_PTR
   SectionName     AS WSTRINGZ * %LINE_LEN   ' WCHAR
   InfFileName     AS WSTRINGZ * %MAX_PATH   ' WCHAR
   DrvDescription  AS WSTRINGZ * %LINE_LEN   ' WCHAR
   HardwareID(0)   AS WORD                   ' [ANYSIZE_ARRAY] WCHAR
END TYPE

' //
' // Driver installation parameters (associated with a particular driver
' // information element)
' //
' // Size = 20 bytes
TYPE SP_DRVINSTALL_PARAMS DWORD
   cbSize      AS DWORD   ' DWORD
   Rank        AS DWORD   ' DWORD
   Flags       AS DWORD   ' DWORD
   PrivateData AS DWORD   ' DWORD_PTR
   Reserved    AS DWORD   ' DWORD
END TYPE

' //
' // SP_DRVINSTALL_PARAMS.Flags values
' //
%DNF_DUPDESC             = &H00000001???  ' // Multiple providers have same desc
%DNF_OLDDRIVER           = &H00000002???  ' // Driver node specifies old/current driver
%DNF_EXCLUDEFROMLIST     = &H00000004???  ' // If set, this driver node will not be
                                          ' // displayed in any driver select dialogs.
%DNF_NODRIVER            = &H00000008???  ' // if we want to install no driver
                                          ' // (e.g no mouse drv)
%DNF_LEGACYINF           = &H00000010???  ' // Driver node came from an old-style INF (obsolete)
%DNF_CLASS_DRIVER        = &H00000020???  ' // Driver node represents a class driver
%DNF_COMPATIBLE_DRIVER   = &H00000040???  ' // Driver node represents a compatible driver
%DNF_INET_DRIVER         = &H00000080???  ' // Driver comes from an internet source
%DNF_UNUSED1             = &H00000100???
%DNF_INDEXED_DRIVER      = &H00000200???  ' // Driver is contained in the Windows Driver Index
%DNF_OLD_INET_DRIVER     = &H00000400???  ' // Driver came from the Internet, but we don't currently
                                          ' // have access to it's source files.  Never attempt to
                                          ' // install a driver with this flag!
%DNF_BAD_DRIVER          = &H00000800???  ' // Driver node should not be used at all
%DNF_DUPPROVIDER         = &H00001000???  ' // Multiple drivers have the same provider and desc

'#if _SETUPAPI_VER >= _WIN32_WINNT_WINXP
#IF %SETUPAPI_VER >= %WIN32_WINNT_WINXP
%DNF_INF_IS_SIGNED       = &H00002000???  ' // If file is digitally signed
%DNF_OEM_F6_INF          = &H00004000???  ' // INF specified from F6 during textmode setup.
%DNF_DUPDRIVERVER        = &H00008000???  ' // Multipe drivers have the same desc, provider, and DriverVer values
%DNF_BASIC_DRIVER        = &H00010000???  ' // Driver provides basic functionality, but should
                                          ' // not be chosen if other signed drivers exist.
#ENDIF
'#endif // _SETUPAPI_VER >= _WIN32_WINNT_WINXP

'#if _SETUPAPI_VER >= _WIN32_WINNT_WS03
#IF %SETUPAPI_VER >= %WIN32_WINNT_WS03
%DNF_AUTHENTICODE_SIGNED = &H00020000???  ' // Inf file is signed by an Authenticode(tm) catalog.
#ENDIF
'#endif // _SETUPAPI_VER >= _WIN32_WINNT_WS03

'#if _SETUPAPI_VER >= _WIN32_WINNT_LONGHORN
#IF %SETUPAPI_VER >= %WIN32_WINNT_LONGHORN
%DNF_INSTALLEDDRIVER       = &H00040000???  ' // This driver node is currently installed on the device.
%DNF_ALWAYSEXCLUDEFROMLIST = &H00080000???  ' // If set, this driver is not even displayed in
                                            ' // alternative platform either.
%DNF_INBOX_DRIVER          = &H00100000???  ' // This driver node came from an INF that shipped with Windows.
#ENDIF
'#endif // _SETUPAPI_VER >= _WIN32_WINNT_LONGHORN

'#if _SETUPAPI_VER >= _WIN32_WINNT_WIN7
#IF %SETUPAPI_VER >= %WIN32_WINNT_WIN7
%DNF_REQUESTADDITIONALSOFTWARE = &H00200000???   ' // This driver is only part of a software solution needed
                                                 ' // by this device
#ENDIF
'#endif // _SETUPAPI_VER >= _WIN32_WINNT_WIN7

%DNF_UNUSED_22             = &H00400000???
%DNF_UNUSED_23             = &H00800000???
%DNF_UNUSED_24             = &H01000000???
%DNF_UNUSED_25             = &H02000000???
%DNF_UNUSED_26             = &H04000000???
%DNF_UNUSED_27             = &H08000000???
%DNF_UNUSED_28             = &H10000000???
%DNF_UNUSED_29             = &H20000000???
%DNF_UNUSED_30             = &H40000000???
%DNF_UNUSED_31             = &H80000000???

' //
' // Rank values (the lower the Rank number, the better the Rank)
' //
'#if _SETUPAPI_VER >= _WIN32_WINNT_LONGHORN
#IF %SETUPAPI_VER >= %WIN32_WINNT_LONGHORN
%DRIVER_HARDWAREID_RANK  = &H00000FFF???  ' // Any rank less than or equal to
                                          ' // this value is a trusted
                                          ' // HardwareID match

%DRIVER_HARDWAREID_MASK  = &H80000FFF???  ' // If you mask these bits off (AND)
                                          ' // from the Rank and the result is 0
                                          ' // then the Rank is a trusted HardwareID match

%DRIVER_UNTRUSTED_RANK   = &H00008000???  ' // Any rank with this bit set is an
                                          ' // "untrusted" rank, meaning that
                                          ' // the INF was unsigned.

%DRIVER_W9X_SUSPECT_RANK = &H0000C000???  ' // Any rank that is greater than
                                          ' // or equal to this value, and lesser
                                          ' // than or equal to = &HFFFF is suspected
                                          ' // to be a Win9x-only driver, because
                                          ' // (a) it isn't signed, and (b) there
                                          ' // is no NT-specific decoration to
                                          ' // explicitly indicate that the INF
                                          ' // supports Windows NT/2000/XP

#ELSE

%DRIVER_HARDWAREID_RANK  = &H00000FFF???  ' // Any rank less than or equal to
                                          ' // this value is a trusted
                                          ' // HardwareID match

%DRIVER_COMPATID_RANK    = &H00003FFF???    ' // Any rank less than or equal to
                                            ' // this (and greater than
                                            ' // DRIVER_HARDWAREID_RANK) is a
                                            ' // trusted CompatibleID match

%DRIVER_UNTRUSTED_RANK   = &H00008000???    ' // Any rank with this bit set is an
                                            ' // "untrusted" rank, meaning that
                                            ' // the INF was unsigned.

%DRIVER_UNTRUSTED_HARDWAREID_RANK  = &H00008FFF???    ' // Any rank less than or equal to
                                                      ' // this value (and greater than
                                                      ' // or equal to DRIVER_UNTRUSTED_RANK)
                                                      ' // is an untrusted HardwareID match

%DRIVER_UNTRUSTED_COMPATID_RANK    = &H0000BFFF???    ' // Any rank less than or equal to
                                                      ' // this value (and greater than
                                                      ' // DRIVER_UNTRUSTED_HARDWAREID_RANK)
                                                      ' // is an untrusted CompatibleID match

%DRIVER_W9X_SUSPECT_RANK            = &H0000C000???   ' // Any rank that is greater than
                                                      ' // or equal to this value, and lesser
                                                      ' // than or equal to = &HFFFF is suspected
                                                      ' // to be a Win9x-only driver, because
                                                      ' // (a) it isn't signed, and (b) there
                                                      ' // is no NT-specific decoration to
                                                      ' // explicitly indicate that the INF
                                                      ' // supports Windows NT/2000/XP

%DRIVER_W9X_SUSPECT_HARDWAREID_RANK = &H0000CFFF???   ' // Any rank less than or equal to this
                                                      ' // (and greater than or equal to
                                                      ' // DRIVER_W9X_SUSPECT_RANK) is a
                                                      ' // hardware ID match suspected of being
                                                      ' // only for Windows 9x platforms.

%DRIVER_W9X_SUSPECT_COMPATID_RANK   = &H0000FFFF???   ' // Any rank less than or equal to
                                                      ' // this (and greater than
                                                      ' // DRIVER_W9X_SUSPECT_HARDWAREID_RANK)
                                                      ' // is a compatible ID match suspected
                                                      ' // of being only for Windows 9x
                                                      ' // platforms.

#ENDIF
'#endif // _SETUPAPI_VER < _WIN32_WINNT_LONGHORN

' //
' // Setup callback routine for comparing detection signatures
' //
'typedef DWORD (CALLBACK* PSP_DETSIG_CMPPROC)(
'    IN HDEVINFO         DeviceInfoSet,
'    IN PSP_DEVINFO_DATA NewDeviceData,
'    IN PSP_DEVINFO_DATA ExistingDeviceData,
'    IN PVOID            CompareContext      OPTIONAL
'    );

'FUNCTION SP_DETSIG_CMPPROC ( _
'   BYVAL DWORD _                              ' IN HDEVINFO         DeviceInfoSet
' , BYREF SP_DEVINFO_DATA _                    ' IN PSP_DEVINFO_DATA NewDeviceData
' , BYREF SP_DEVINFO_DATA _                    ' IN PSP_DEVINFO_DATA ExistingDeviceData
' , BYVAL DWORD _                              ' IN PVOID            CompareContext      OPTIONAL
' ) AS DWORD                                             ' DWORD

' //
' // Define context structure handed to co-installers
' //
' // Size = 12 bytes
TYPE COINSTALLER_CONTEXT_DATA DWORD
   PostProcessing AS LONG    ' BOOL
   InstallResult  AS DWORD   ' DWORD
   PrivateData    AS DWORD   ' PVOID
END TYPE


' //
' // Structure containing class image list information.
' //
' // Size = 12 bytes
TYPE SP_CLASSIMAGELIST_DATA DWORD
   cbSize    AS DWORD   ' DWORD
   ImageList AS DWORD   ' HIMAGELIST
   Reserved  AS DWORD   ' ULONG_PTR
END TYPE


' //
' // Structure to be passed as first parameter (LPVOID lpv) to ExtensionPropSheetPageProc
' // entry point in setupapi.dll or to "EnumPropPages32" or "BasicProperties32" entry
' // points provided by class/device property page providers.  Used to retrieve a handle
' // (or, potentially, multiple handles) to property pages for a specified property page type.
' //
' // Size = 16 bytes
TYPE SP_PROPSHEETPAGE_REQUEST DWORD
   cbSize         AS DWORD                 ' DWORD
   PageRequested  AS DWORD                 ' DWORD
   DeviceInfoSet  AS DWORD                 ' HDEVINFO
   DeviceInfoData AS SP_DEVINFO_DATA PTR   ' PSP_DEVINFO_DATA
END TYPE

' //
' // Property sheet codes used in SP_PROPSHEETPAGE_REQUEST.PageRequested
' //
%SPPSR_SELECT_DEVICE_RESOURCES      = 1    ' // supplied by setupapi.dll
%SPPSR_ENUM_BASIC_DEVICE_PROPERTIES = 2    ' // supplied by device's BasicProperties32 provider
%SPPSR_ENUM_ADV_DEVICE_PROPERTIES   = 3    ' // supplied by class and/or device's EnumPropPages32 provider


' //
' // Structure used with SetupGetBackupInformation/SetupSetBackupInformation
' //
' // Size = 528 bytes
TYPE SP_BACKUP_QUEUE_PARAMS_V2_A BYTE
   cbSize            AS DWORD                ' DWORD // size of structure
   FullInfPath       AS ASCIIZ * %MAX_PATH   ' CHAR  // buffer to hold ANSI pathname of INF file
   FilenameOffset    AS LONG                 ' INT   // offset in CHAR's of filename part (after '\')
   ReinstallInstance AS ASCIIZ * %MAX_PATH   ' CHAR  // Instance ID (if present)
END TYPE

' // Size = 1048 bytes
TYPE SP_BACKUP_QUEUE_PARAMS_V2_W BYTE
   cbSize            AS DWORD                  ' DWORD // size of structure
   FullInfPath       AS WSTRINGZ * %MAX_PATH   ' WCHAR // buffer to hold ANSI pathname of INF file
   FilenameOffset    AS LONG                   ' INT   // offset in CHAR's of filename part (after '\')
   ReinstallInstance AS WSTRINGZ * %MAX_PATH   ' WCHAR // Instance ID (if present)
END TYPE

' //
' // Version 1 of the SP_BACKUP_QUEUE_PARAMS structures, used only for compatibility
' // with Windows 2000/Windows 95/98/ME SETUPAPI.DLL
' //
' // Size = 268 bytes
TYPE SP_BACKUP_QUEUE_PARAMS_V1_A BYTE
   cbSize         AS DWORD                ' DWORD // size of structure
   FullInfPath    AS ASCIIZ * %MAX_PATH   ' CHAR  // buffer to hold ANSI pathname of INF file
   FilenameOffset AS LONG                 ' INT   // offset in CHAR's of filename part (after '\')
END TYPE

' // Size = 528 bytes
TYPE SP_BACKUP_QUEUE_PARAMS_V1_W BYTE
   cbSize         AS DWORD                 ' DWORD // size of structure
   FullInfPath    AS WSTRINGZ * %MAX_PATH  ' WCHAR // buffer to hold ANSI pathname of INF file
   FilenameOffset AS LONG                  ' INT   // offset in CHAR's of filename part (after '\')
END TYPE

#IF %DEF(%UNICODE)
   MACRO SP_BACKUP_QUEUE_PARAMS_V1 = SP_BACKUP_QUEUE_PARAMS_V1_W
#ELSE
   MACRO SP_BACKUP_QUEUE_PARAMS_V1 = SP_BACKUP_QUEUE_PARAMS_V1_A
#ENDIF

#IF %DEF(%USE_SP_BACKUP_QUEUE_PARAMS_V1) OR (%SETUPAPI_VER < &H0501)  ' // use version 1 driver info data structure

'typedef SP_BACKUP_QUEUE_PARAMS_V1_A SP_BACKUP_QUEUE_PARAMS_A;
'typedef PSP_BACKUP_QUEUE_PARAMS_V1_A PSP_BACKUP_QUEUE_PARAMS_A;
'typedef SP_BACKUP_QUEUE_PARAMS_V1_W SP_BACKUP_QUEUE_PARAMS_W;
'typedef PSP_BACKUP_QUEUE_PARAMS_V1_W PSP_BACKUP_QUEUE_PARAMS_W;
'typedef SP_BACKUP_QUEUE_PARAMS_V1 SP_BACKUP_QUEUE_PARAMS;
'typedef PSP_BACKUP_QUEUE_PARAMS_V1 PSP_BACKUP_QUEUE_PARAMS;

MACRO SP_BACKUP_QUEUE_PARAMS_A = SP_BACKUP_QUEUE_PARAMS_V1_A
MACRO SP_BACKUP_QUEUE_PARAMS_W = SP_BACKUP_QUEUE_PARAMS_V1_W
#IF %DEF(%UNICODE)
   MACRO SP_BACKUP_QUEUE_PARAMS = SP_BACKUP_QUEUE_PARAMS_V1_W
#ELSE
   MACRO SP_BACKUP_QUEUE_PARAMS = SP_BACKUP_QUEUE_PARAMS_V1_A
#ENDIF

#ELSE                       ' // use version 2 driver info data structure

'typedef SP_BACKUP_QUEUE_PARAMS_V2_A SP_BACKUP_QUEUE_PARAMS_A;
'typedef PSP_BACKUP_QUEUE_PARAMS_V2_A PSP_BACKUP_QUEUE_PARAMS_A;
'typedef SP_BACKUP_QUEUE_PARAMS_V2_W SP_BACKUP_QUEUE_PARAMS_W;
'typedef PSP_BACKUP_QUEUE_PARAMS_V2_W PSP_BACKUP_QUEUE_PARAMS_W;
'typedef SP_BACKUP_QUEUE_PARAMS_V2 SP_BACKUP_QUEUE_PARAMS;
'typedef PSP_BACKUP_QUEUE_PARAMS_V2 PSP_BACKUP_QUEUE_PARAMS;

MACRO SP_BACKUP_QUEUE_PARAMS_A = SP_BACKUP_QUEUE_PARAMS_V2_A
MACRO SP_BACKUP_QUEUE_PARAMS_W = SP_BACKUP_QUEUE_PARAMS_V2_W
#IF %DEF(%UNICODE)
   MACRO SP_BACKUP_QUEUE_PARAMS = SP_BACKUP_QUEUE_PARAMS_V2_W
#ELSE
   MACRO SP_BACKUP_QUEUE_PARAMS = SP_BACKUP_QUEUE_PARAMS_V2_A
#ENDIF

#ENDIF  ' // use current version of driver info data structure

' //
' // Setupapi-specific error codes
' //
' // Inf parse outcomes
' //
%ERROR_EXPECTED_SECTION_NAME  = (%APPLICATION_ERROR_MASK OR %ERROR_SEVERITY_ERROR OR 0)
%ERROR_BAD_SECTION_NAME_LINE  = (%APPLICATION_ERROR_MASK OR %ERROR_SEVERITY_ERROR OR 1)
%ERROR_SECTION_NAME_TOO_LONG  = (%APPLICATION_ERROR_MASK OR %ERROR_SEVERITY_ERROR OR 2)
%ERROR_GENERAL_SYNTAX         = (%APPLICATION_ERROR_MASK OR %ERROR_SEVERITY_ERROR OR 3)
' //
' // Inf runtime errors
' //
%ERROR_WRONG_INF_STYLE        = (%APPLICATION_ERROR_MASK OR %ERROR_SEVERITY_ERROR OR &H100)
%ERROR_SECTION_NOT_FOUND      = (%APPLICATION_ERROR_MASK OR %ERROR_SEVERITY_ERROR OR &H101)
%ERROR_LINE_NOT_FOUND         = (%APPLICATION_ERROR_MASK OR %ERROR_SEVERITY_ERROR OR &H102)
%ERROR_NO_BACKUP              = (%APPLICATION_ERROR_MASK OR %ERROR_SEVERITY_ERROR OR &H103)
' //
' // Device Installer/other errors
' //
%ERROR_NO_ASSOCIATED_CLASS                = (%APPLICATION_ERROR_MASK OR %ERROR_SEVERITY_ERROR OR &H200)
%ERROR_CLASS_MISMATCH                     = (%APPLICATION_ERROR_MASK OR %ERROR_SEVERITY_ERROR OR &H201)
%ERROR_DUPLICATE_FOUND                    = (%APPLICATION_ERROR_MASK OR %ERROR_SEVERITY_ERROR OR &H202)
%ERROR_NO_DRIVER_SELECTED                 = (%APPLICATION_ERROR_MASK OR %ERROR_SEVERITY_ERROR OR &H203)
%ERROR_KEY_DOES_NOT_EXIST                 = (%APPLICATION_ERROR_MASK OR %ERROR_SEVERITY_ERROR OR &H204)
%ERROR_INVALID_DEVINST_NAME               = (%APPLICATION_ERROR_MASK OR %ERROR_SEVERITY_ERROR OR &H205)
%ERROR_INVALID_CLASS                      = (%APPLICATION_ERROR_MASK OR %ERROR_SEVERITY_ERROR OR &H206)
%ERROR_DEVINST_ALREADY_EXISTS             = (%APPLICATION_ERROR_MASK OR %ERROR_SEVERITY_ERROR OR &H207)
%ERROR_DEVINFO_NOT_REGISTERED             = (%APPLICATION_ERROR_MASK OR %ERROR_SEVERITY_ERROR OR &H208)
%ERROR_INVALID_REG_PROPERTY               = (%APPLICATION_ERROR_MASK OR %ERROR_SEVERITY_ERROR OR &H209)
%ERROR_NO_INF                             = (%APPLICATION_ERROR_MASK OR %ERROR_SEVERITY_ERROR OR &H20A)
%ERROR_NO_SUCH_DEVINST                    = (%APPLICATION_ERROR_MASK OR %ERROR_SEVERITY_ERROR OR &H20B)
%ERROR_CANT_LOAD_CLASS_ICON               = (%APPLICATION_ERROR_MASK OR %ERROR_SEVERITY_ERROR OR &H20C)
%ERROR_INVALID_CLASS_INSTALLER            = (%APPLICATION_ERROR_MASK OR %ERROR_SEVERITY_ERROR OR &H20D)
%ERROR_DI_DO_DEFAULT                      = (%APPLICATION_ERROR_MASK OR %ERROR_SEVERITY_ERROR OR &H20E)
%ERROR_DI_NOFILECOPY                      = (%APPLICATION_ERROR_MASK OR %ERROR_SEVERITY_ERROR OR &H20F)
%ERROR_INVALID_HWPROFILE                  = (%APPLICATION_ERROR_MASK OR %ERROR_SEVERITY_ERROR OR &H210)
%ERROR_NO_DEVICE_SELECTED                 = (%APPLICATION_ERROR_MASK OR %ERROR_SEVERITY_ERROR OR &H211)
%ERROR_DEVINFO_LIST_LOCKED                = (%APPLICATION_ERROR_MASK OR %ERROR_SEVERITY_ERROR OR &H212)
%ERROR_DEVINFO_DATA_LOCKED                = (%APPLICATION_ERROR_MASK OR %ERROR_SEVERITY_ERROR OR &H213)
%ERROR_DI_BAD_PATH                        = (%APPLICATION_ERROR_MASK OR %ERROR_SEVERITY_ERROR OR &H214)
%ERROR_NO_CLASSINSTALL_PARAMS             = (%APPLICATION_ERROR_MASK OR %ERROR_SEVERITY_ERROR OR &H215)
%ERROR_FILEQUEUE_LOCKED                   = (%APPLICATION_ERROR_MASK OR %ERROR_SEVERITY_ERROR OR &H216)
%ERROR_BAD_SERVICE_INSTALLSECT            = (%APPLICATION_ERROR_MASK OR %ERROR_SEVERITY_ERROR OR &H217)
%ERROR_NO_CLASS_DRIVER_LIST               = (%APPLICATION_ERROR_MASK OR %ERROR_SEVERITY_ERROR OR &H218)
%ERROR_NO_ASSOCIATED_SERVICE              = (%APPLICATION_ERROR_MASK OR %ERROR_SEVERITY_ERROR OR &H219)
%ERROR_NO_DEFAULT_DEVICE_INTERFACE        = (%APPLICATION_ERROR_MASK OR %ERROR_SEVERITY_ERROR OR &H21A)
%ERROR_DEVICE_INTERFACE_ACTIVE            = (%APPLICATION_ERROR_MASK OR %ERROR_SEVERITY_ERROR OR &H21B)
%ERROR_DEVICE_INTERFACE_REMOVED           = (%APPLICATION_ERROR_MASK OR %ERROR_SEVERITY_ERROR OR &H21C)
%ERROR_BAD_INTERFACE_INSTALLSECT          = (%APPLICATION_ERROR_MASK OR %ERROR_SEVERITY_ERROR OR &H21D)
%ERROR_NO_SUCH_INTERFACE_CLASS            = (%APPLICATION_ERROR_MASK OR %ERROR_SEVERITY_ERROR OR &H21E)
%ERROR_INVALID_REFERENCE_STRING           = (%APPLICATION_ERROR_MASK OR %ERROR_SEVERITY_ERROR OR &H21F)
%ERROR_INVALID_MACHINENAME                = (%APPLICATION_ERROR_MASK OR %ERROR_SEVERITY_ERROR OR &H220)
%ERROR_REMOTE_COMM_FAILURE                = (%APPLICATION_ERROR_MASK OR %ERROR_SEVERITY_ERROR OR &H221)
%ERROR_MACHINE_UNAVAILABLE                = (%APPLICATION_ERROR_MASK OR %ERROR_SEVERITY_ERROR OR &H222)
%ERROR_NO_CONFIGMGR_SERVICES              = (%APPLICATION_ERROR_MASK OR %ERROR_SEVERITY_ERROR OR &H223)
%ERROR_INVALID_PROPPAGE_PROVIDER          = (%APPLICATION_ERROR_MASK OR %ERROR_SEVERITY_ERROR OR &H224)
%ERROR_NO_SUCH_DEVICE_INTERFACE           = (%APPLICATION_ERROR_MASK OR %ERROR_SEVERITY_ERROR OR &H225)
%ERROR_DI_POSTPROCESSING_REQUIRED         = (%APPLICATION_ERROR_MASK OR %ERROR_SEVERITY_ERROR OR &H226)
%ERROR_INVALID_COINSTALLER                = (%APPLICATION_ERROR_MASK OR %ERROR_SEVERITY_ERROR OR &H227)
%ERROR_NO_COMPAT_DRIVERS                  = (%APPLICATION_ERROR_MASK OR %ERROR_SEVERITY_ERROR OR &H228)
%ERROR_NO_DEVICE_ICON                     = (%APPLICATION_ERROR_MASK OR %ERROR_SEVERITY_ERROR OR &H229)
%ERROR_INVALID_INF_LOGCONFIG              = (%APPLICATION_ERROR_MASK OR %ERROR_SEVERITY_ERROR OR &H22A)
%ERROR_DI_DONT_INSTALL                    = (%APPLICATION_ERROR_MASK OR %ERROR_SEVERITY_ERROR OR &H22B)
%ERROR_INVALID_FILTER_DRIVER              = (%APPLICATION_ERROR_MASK OR %ERROR_SEVERITY_ERROR OR &H22C)
%ERROR_NON_WINDOWS_NT_DRIVER              = (%APPLICATION_ERROR_MASK OR %ERROR_SEVERITY_ERROR OR &H22D)
%ERROR_NON_WINDOWS_DRIVER                 = (%APPLICATION_ERROR_MASK OR %ERROR_SEVERITY_ERROR OR &H22E)
%ERROR_NO_CATALOG_FOR_OEM_INF             = (%APPLICATION_ERROR_MASK OR %ERROR_SEVERITY_ERROR OR &H22F)
%ERROR_DEVINSTALL_QUEUE_NONNATIVE         = (%APPLICATION_ERROR_MASK OR %ERROR_SEVERITY_ERROR OR &H230)
%ERROR_NOT_DISABLEABLE                    = (%APPLICATION_ERROR_MASK OR %ERROR_SEVERITY_ERROR OR &H231)
%ERROR_CANT_REMOVE_DEVINST                = (%APPLICATION_ERROR_MASK OR %ERROR_SEVERITY_ERROR OR &H232)
%ERROR_INVALID_TARGET                     = (%APPLICATION_ERROR_MASK OR %ERROR_SEVERITY_ERROR OR &H233)
%ERROR_DRIVER_NONNATIVE                   = (%APPLICATION_ERROR_MASK OR %ERROR_SEVERITY_ERROR OR &H234)
%ERROR_IN_WOW64                           = (%APPLICATION_ERROR_MASK OR %ERROR_SEVERITY_ERROR OR &H235)
%ERROR_SET_SYSTEM_RESTORE_POINT           = (%APPLICATION_ERROR_MASK OR %ERROR_SEVERITY_ERROR OR &H236)
%ERROR_INCORRECTLY_COPIED_INF             = (%APPLICATION_ERROR_MASK OR %ERROR_SEVERITY_ERROR OR &H237)    ' Removed in Windows Vista
%ERROR_SCE_DISABLED                       = (%APPLICATION_ERROR_MASK OR %ERROR_SEVERITY_ERROR OR &H238)
%ERROR_UNKNOWN_EXCEPTION                  = (%APPLICATION_ERROR_MASK OR %ERROR_SEVERITY_ERROR OR &H239)
%ERROR_PNP_REGISTRY_ERROR                 = (%APPLICATION_ERROR_MASK OR %ERROR_SEVERITY_ERROR OR &H23A)
%ERROR_REMOTE_REQUEST_UNSUPPORTED         = (%APPLICATION_ERROR_MASK OR %ERROR_SEVERITY_ERROR OR &H23B)
%ERROR_NOT_AN_INSTALLED_OEM_INF           = (%APPLICATION_ERROR_MASK OR %ERROR_SEVERITY_ERROR OR &H23C)
%ERROR_INF_IN_USE_BY_DEVICES              = (%APPLICATION_ERROR_MASK OR %ERROR_SEVERITY_ERROR OR &H23D)
%ERROR_DI_FUNCTION_OBSOLETE               = (%APPLICATION_ERROR_MASK OR %ERROR_SEVERITY_ERROR OR &H23E)
%ERROR_NO_AUTHENTICODE_CATALOG            = (%APPLICATION_ERROR_MASK OR %ERROR_SEVERITY_ERROR OR &H23F)
%ERROR_AUTHENTICODE_DISALLOWED            = (%APPLICATION_ERROR_MASK OR %ERROR_SEVERITY_ERROR OR &H240)
%ERROR_AUTHENTICODE_TRUSTED_PUBLISHER     = (%APPLICATION_ERROR_MASK OR %ERROR_SEVERITY_ERROR OR &H241)
%ERROR_AUTHENTICODE_TRUST_NOT_ESTABLISHED = (%APPLICATION_ERROR_MASK OR %ERROR_SEVERITY_ERROR OR &H242)
%ERROR_AUTHENTICODE_PUBLISHER_NOT_TRUSTED = (%APPLICATION_ERROR_MASK OR %ERROR_SEVERITY_ERROR OR &H243)
%ERROR_SIGNATURE_OSATTRIBUTE_MISMATCH     = (%APPLICATION_ERROR_MASK OR %ERROR_SEVERITY_ERROR OR &H244)
%ERROR_ONLY_VALIDATE_VIA_AUTHENTICODE     = (%APPLICATION_ERROR_MASK OR %ERROR_SEVERITY_ERROR OR &H245)
%ERROR_DEVICE_INSTALLER_NOT_READY         = (%APPLICATION_ERROR_MASK OR %ERROR_SEVERITY_ERROR OR &H246)
%ERROR_DRIVER_STORE_ADD_FAILED            = (%APPLICATION_ERROR_MASK OR %ERROR_SEVERITY_ERROR OR &H247)
%ERROR_DEVICE_INSTALL_BLOCKED             = (%APPLICATION_ERROR_MASK OR %ERROR_SEVERITY_ERROR OR &H248)
%ERROR_DRIVER_INSTALL_BLOCKED             = (%APPLICATION_ERROR_MASK OR %ERROR_SEVERITY_ERROR OR &H249)
%ERROR_WRONG_INF_TYPE                     = (%APPLICATION_ERROR_MASK OR %ERROR_SEVERITY_ERROR OR &H24A)
%ERROR_FILE_HASH_NOT_IN_CATALOG           = (%APPLICATION_ERROR_MASK OR %ERROR_SEVERITY_ERROR OR &H24B)
%ERROR_DRIVER_STORE_DELETE_FAILED         = (%APPLICATION_ERROR_MASK OR %ERROR_SEVERITY_ERROR OR &H24C)

' //
' // Setupapi exception codes
' //
%ERROR_UNRECOVERABLE_STACK_OVERFLOW = (%APPLICATION_ERROR_MASK OR %ERROR_SEVERITY_ERROR OR &H300)
%EXCEPTION_SPAPI_UNRECOVERABLE_STACK_OVERFLOW = %ERROR_UNRECOVERABLE_STACK_OVERFLOW

' //
' // Backward compatibility--do not use.
' //
%ERROR_NO_DEFAULT_INTERFACE_DEVICE = %ERROR_NO_DEFAULT_DEVICE_INTERFACE
%ERROR_INTERFACE_DEVICE_ACTIVE     = %ERROR_DEVICE_INTERFACE_ACTIVE
%ERROR_INTERFACE_DEVICE_REMOVED    = %ERROR_DEVICE_INTERFACE_REMOVED
%ERROR_NO_SUCH_INTERFACE_DEVICE    = %ERROR_NO_SUCH_DEVICE_INTERFACE


' //
' // Win9x migration DLL error code
' //
%ERROR_NOT_INSTALLED = (%APPLICATION_ERROR_MASK OR %ERROR_SEVERITY_ERROR OR &H1000)


DECLARE FUNCTION SetupGetInfInformationA IMPORT "SETUPAPI.DLL" ALIAS "SetupGetInfInformationA" ( _
   BYREF InfSpec AS ANY _                               ' __in LPCVOID InfSpec
 , BYVAL SearchControl AS DWORD _                       ' __in DWORD SearchControl
 , BYVAL ReturnBuffer AS SP_INF_INFORMATION PTR _       ' __out PSP_INF_INFORMATION ReturnBuffer
 , BYVAL ReturnBufferSize AS DWORD _                    ' __in DWORD ReturnBufferSize
 , OPTIONAL BYREF RequiredSize AS DWORD _               ' __out_opt PDWORD RequiredSize
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SetupGetInfInformationW IMPORT "SETUPAPI.DLL" ALIAS "SetupGetInfInformationW" ( _
   BYREF InfSpec AS ANY _                               ' __in LPCVOID InfSpec
 , BYVAL SearchControl AS DWORD _                       ' __in DWORD SearchControl
 , BYVAL ReturnBuffer AS SP_INF_INFORMATION PTR _       ' __out PSP_INF_INFORMATION ReturnBuffer
 , BYVAL ReturnBufferSize AS DWORD _                    ' __in DWORD ReturnBufferSize
 , OPTIONAL BYREF RequiredSize AS DWORD _               ' __out_opt PDWORD RequiredSize
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO SetupGetInfInformation = SetupGetInfInformationW
#ELSE
   MACRO SetupGetInfInformation = SetupGetInfInformationA
#ENDIF

' //
' // SearchControl flags for SetupGetInfInformation
' //
%INFINFO_INF_SPEC_IS_HINF       = 1
%INFINFO_INF_NAME_IS_ABSOLUTE   = 2
%INFINFO_DEFAULT_SEARCH         = 3
%INFINFO_REVERSE_DEFAULT_SEARCH = 4
%INFINFO_INF_PATH_LIST_SEARCH   = 5

DECLARE FUNCTION SetupQueryInfFileInformationA IMPORT "SETUPAPI.DLL" ALIAS "SetupQueryInfFileInformationA" ( _
   BYVAL InfInformation AS SP_INF_INFORMATION PTR _     ' __in PSP_INF_INFORMATION InfInformation
 , BYVAL InfIndex AS DWORD _                            ' __in UINT InfIndex
 , BYREF ReturnBuffer AS ASCIIZ _                       ' __out PSTR ReturnBuffer
 , BYVAL ReturnBufferSize AS DWORD _                    ' __in DWORD ReturnBufferSize
 , OPTIONAL BYREF RequiredSize AS DWORD _               ' __out_opt PDWORD RequiredSize
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SetupQueryInfFileInformationW IMPORT "SETUPAPI.DLL" ALIAS "SetupQueryInfFileInformationW" ( _
   BYVAL InfInformation AS SP_INF_INFORMATION PTR _     ' __in PSP_INF_INFORMATION InfInformation
 , BYVAL InfIndex AS DWORD _                            ' __in UINT InfIndex
 , BYREF ReturnBuffer AS WSTRINGZ _                     ' __out PWSTR ReturnBuffer
 , BYVAL ReturnBufferSize AS DWORD _                    ' __in DWORD ReturnBufferSize
 , OPTIONAL BYREF RequiredSize AS DWORD _               ' __out_opt PDWORD RequiredSize
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO SetupQueryInfFileInformation = SetupQueryInfFileInformationW
#ELSE
   MACRO SetupQueryInfFileInformation = SetupQueryInfFileInformationA
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SetupQueryInfOriginalFileInformationA LIB "SetupApi.dll" _
    ALIAS "SetupQueryInfOriginalFileInformationA" ( _
    BYVAL InfInformation        AS SP_INF_INFORMATION PTR, _
    BYVAL InfIndex              AS DWORD, _
    BYVAL AlternatePlatformInfo AS SP_ALTPLATFORM_INFO PTR, _
    BYVAL OriginalFileInfo      AS SP_ORIGINAL_FILE_INFO_A PTR _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupQueryInfOriginalFileInformationA IMPORT "SETUPAPI.DLL" ALIAS "SetupQueryInfOriginalFileInformationA" ( _
   BYVAL InfInformation AS SP_INF_INFORMATION PTR _     ' __in PSP_INF_INFORMATION InfInformation
 , BYVAL InfIndex AS DWORD _                            ' __in UINT InfIndex
 , BYREF AlternatePlatformInfo AS SP_ALTPLATFORM_INFO _ ' __in_opt PSP_ALTPLATFORM_INFO AlternatePlatformInfo
 , BYREF OriginalFileInfo AS SP_ORIGINAL_FILE_INFO_A _  ' __out PSP_ORIGINAL_FILE_INFO_A OriginalFileInfo
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SetupQueryInfOriginalFileInformationW LIB "SetupApi.dll" _
    ALIAS "SetupQueryInfOriginalFileInformationW" ( _
    BYVAL InfInformation        AS SP_INF_INFORMATION PTR, _
    BYVAL InfIndex              AS DWORD, _
    BYVAL AlternatePlatformInfo AS SP_ALTPLATFORM_INFO PTR, _
    BYVAL OriginalFileInfo      AS SP_ORIGINAL_FILE_INFO_W PTR _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupQueryInfOriginalFileInformationW IMPORT "SETUPAPI.DLL" ALIAS "SetupQueryInfOriginalFileInformationW" ( _
   BYVAL InfInformation AS SP_INF_INFORMATION PTR _     ' __in PSP_INF_INFORMATION InfInformation
 , BYVAL InfIndex AS DWORD _                            ' __in UINT InfIndex
 , BYREF AlternatePlatformInfo AS SP_ALTPLATFORM_INFO _ ' __in_opt PSP_ALTPLATFORM_INFO AlternatePlatformInfo
 , BYREF OriginalFileInfo AS SP_ORIGINAL_FILE_INFO_W _  ' __out PSP_ORIGINAL_FILE_INFO_W OriginalFileInfo
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%UNICODE)
   MACRO SetupQueryInfOriginalFileInformation = SetupQueryInfOriginalFileInformationW
#ELSE
   MACRO SetupQueryInfOriginalFileInformation = SetupQueryInfOriginalFileInformationA
#ENDIF

DECLARE FUNCTION SetupQueryInfVersionInformationA IMPORT "SETUPAPI.DLL" ALIAS "SetupQueryInfVersionInformationA" ( _
   BYVAL InfInformation AS SP_INF_INFORMATION PTR _     ' __in PSP_INF_INFORMATION InfInformation
 , BYVAL InfIndex AS DWORD _                            ' __in UINT InfIndex
 , BYREF Key AS ASCIIZ _                                ' __in_opt PCSTR Key
 , BYREF ReturnBuffer AS ASCIIZ _                       ' __out PSTR ReturnBuffer
 , BYVAL ReturnBufferSize AS DWORD _                    ' __in DWORD ReturnBufferSize
 , OPTIONAL BYREF RequiredSize AS DWORD _               ' __out_opt PDWORD RequiredSize
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SetupQueryInfVersionInformationW IMPORT "SETUPAPI.DLL" ALIAS "SetupQueryInfVersionInformationW" ( _
   BYVAL InfInformation AS SP_INF_INFORMATION PTR _     ' __in PSP_INF_INFORMATION InfInformation
 , BYVAL InfIndex AS DWORD _                            ' __in UINT InfIndex
 , BYREF Key AS WSTRINGZ _                              ' __in_opt PCWSTR Key
 , BYREF ReturnBuffer AS WSTRINGZ _                     ' __out PWSTR ReturnBuffer
 , BYVAL ReturnBufferSize AS DWORD _                    ' __in DWORD ReturnBufferSize
 , OPTIONAL BYREF RequiredSize AS DWORD _               ' __out_opt PDWORD RequiredSize
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO SetupQueryInfVersionInformation = SetupQueryInfVersionInformationW
#ELSE
   MACRO SetupQueryInfVersionInformation = SetupQueryInfVersionInformationA
#ENDIF

'#if _SETUPAPI_VER >= _WIN32_WINNT_LONGHORN
#IF %SETUPAPI_VER >= %WIN32_WINNT_LONGHORN

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SetupGetInfDriverStoreLocationA LIB "SetupApi.dll" _
    ALIAS "SetupGetInfDriverStoreLocationA" ( _
    FileName                    AS ASCIIZ, _
    BYVAL AlternatePlatformInfo AS SP_ALTPLATFORM_INFO PTR, _
    LocaleName                  AS ASCIIZ, _
    ReturnBuffer                AS ASCIIZ, _
    BYVAL ReturnBufferSize      AS DWORD, _
    RequiredSize                AS DWORD _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupGetInfDriverStoreLocationA IMPORT "SETUPAPI.DLL" ALIAS "SetupGetInfDriverStoreLocationA" ( _
   BYREF FileName AS ASCIIZ _                           ' __in PCSTR FileName
 , BYREF AlternatePlatformInfo AS SP_ALTPLATFORM_INFO _ ' __in_opt PSP_ALTPLATFORM_INFO AlternatePlatformInfo
 , BYREF LocaleName AS ASCIIZ _                         ' __in_opt PCSTR LocaleName
 , BYREF ReturnBuffer AS ASCIIZ _                       ' __out PSTR ReturnBuffer
 , BYVAL ReturnBufferSize AS DWORD _                    ' __in DWORD ReturnBufferSize
 , OPTIONAL BYREF RequiredSize AS DWORD _               ' __out_opt PDWORD RequiredSize
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SetupGetInfDriverStoreLocationW LIB "SetupApi.dll" _
    ALIAS "SetupGetInfDriverStoreLocationW" ( _
    FileName                    AS WSTRINGZ, _
    BYVAL AlternatePlatformInfo AS SP_ALTPLATFORM_INFO PTR, _
    LocaleName                  AS WSTRINGZ, _
    ReturnBuffer                AS WSTRINGZ, _
    BYVAL ReturnBufferSize      AS DWORD, _
    RequiredSize                AS DWORD _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupGetInfDriverStoreLocationW IMPORT "SETUPAPI.DLL" ALIAS "SetupGetInfDriverStoreLocationW" ( _
   BYREF FileName AS WSTRINGZ _                         ' __in PCWSTR FileName
 , BYREF AlternatePlatformInfo AS SP_ALTPLATFORM_INFO _ ' __in_opt PSP_ALTPLATFORM_INFO AlternatePlatformInfo
 , BYREF LocaleName AS WSTRINGZ _                       ' __in_opt PCWSTR LocaleName
 , BYREF ReturnBuffer AS WSTRINGZ _                     ' __out PWSTR ReturnBuffer
 , BYVAL ReturnBufferSize AS DWORD _                    ' __in DWORD ReturnBufferSize
 , OPTIONAL BYREF RequiredSize AS DWORD _               ' __out_opt PDWORD RequiredSize
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%UNICODE)
   MACRO SetupGetInfDriverStoreLocation = SetupGetInfDriverStoreLocationW
#ELSE
   MACRO SetupGetInfDriverStoreLocation = SetupGetInfDriverStoreLocationA
#ENDIF

DECLARE FUNCTION SetupGetInfPublishedNameA IMPORT "SETUPAPI.DLL" ALIAS "SetupGetInfPublishedNameA" ( _
   BYREF DriverStoreLocation AS ASCIIZ _                ' __in PCSTR DriverStoreLocation
 , BYREF ReturnBuffer AS ASCIIZ _                       ' __out PSTR ReturnBuffer
 , BYVAL ReturnBufferSize AS DWORD _                    ' __in DWORD ReturnBufferSize
 , OPTIONAL BYREF RequiredSize AS DWORD _               ' __out_opt PDWORD RequiredSize
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SetupGetInfPublishedNameW IMPORT "SETUPAPI.DLL" ALIAS "SetupGetInfPublishedNameW" ( _
   BYREF DriverStoreLocation AS WSTRINGZ _              ' __in PCWSTR DriverStoreLocation
 , BYREF ReturnBuffer AS WSTRINGZ _                     ' __out PWSTR ReturnBuffer
 , BYVAL ReturnBufferSize AS DWORD _                    ' __in DWORD ReturnBufferSize
 , OPTIONAL BYREF RequiredSize AS DWORD _               ' __out_opt PDWORD RequiredSize
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO SetupGetInfPublishedName = SetupGetInfPublishedNameW
#ELSE
   MACRO SetupGetInfPublishedName = SetupGetInfPublishedNameA
#ENDIF

#ENDIF ' %SETUPAPI_VER >= %WIN32_WINNT_LONGHORN


DECLARE FUNCTION SetupGetInfFileListA IMPORT "SETUPAPI.DLL" ALIAS "SetupGetInfFileListA" ( _
   BYREF DirectoryPath AS ASCIIZ _                      ' __in_opt PCSTR DirectoryPath
 , BYVAL InfStyle AS DWORD _                            ' __in DWORD InfStyle
 , BYREF ReturnBuffer AS ASCIIZ _                       ' __out PSTR ReturnBuffer
 , BYVAL ReturnBufferSize AS DWORD _                    ' __in DWORD ReturnBufferSize
 , OPTIONAL BYREF RequiredSize AS DWORD _               ' __out_opt PDWORD RequiredSize
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SetupGetInfFileListW IMPORT "SETUPAPI.DLL" ALIAS "SetupGetInfFileListW" ( _
   BYREF DirectoryPath AS WSTRINGZ _                    ' __in_opt PCWSTR DirectoryPath
 , BYVAL InfStyle AS DWORD _                            ' __in DWORD InfStyle
 , BYREF ReturnBuffer AS WSTRINGZ _                     ' __out PWSTR ReturnBuffer
 , BYVAL ReturnBufferSize AS DWORD _                    ' __in DWORD ReturnBufferSize
 , OPTIONAL BYREF RequiredSize AS DWORD _               ' __out_opt PDWORD RequiredSize
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO SetupGetInfFileList = SetupGetInfFileListW
#ELSE
   MACRO SetupGetInfFileList = SetupGetInfFileListA
#ENDIF

DECLARE FUNCTION SetupOpenInfFileA IMPORT "SETUPAPI.DLL" ALIAS "SetupOpenInfFileA" ( _
   BYREF FileName AS ASCIIZ _                           ' __in PCSTR FileName
 , BYREF InfClass AS ASCIIZ _                           ' __in_opt PCSTR InfClass
 , BYVAL InfStyle AS DWORD _                            ' __in DWORD InfStyle
 , OPTIONAL BYREF ErrorLine AS DWORD _                  ' __out_opt PUINT ErrorLine
 ) AS DWORD                                             ' HINF

DECLARE FUNCTION SetupOpenInfFileW IMPORT "SETUPAPI.DLL" ALIAS "SetupOpenInfFileW" ( _
   BYREF FileName AS WSTRINGZ _                         ' __in PCWSTR FileName
 , BYREF InfClass AS WSTRINGZ _                         ' __in_opt PCWSTR InfClass
 , BYVAL InfStyle AS DWORD _                            ' __in DWORD InfStyle
 , OPTIONAL BYREF ErrorLine AS DWORD _                  ' __out_opt PUINT ErrorLine
 ) AS DWORD                                             ' HINF

#IF %DEF(%UNICODE)
   MACRO SetupOpenInfFile = SetupOpenInfFileW
#ELSE
   MACRO SetupOpenInfFile = SetupOpenInfFileA
#ENDIF

DECLARE FUNCTION SetupOpenMasterInf IMPORT "SETUPAPI.DLL" ALIAS "SetupOpenMasterInf" ( _
 ) AS DWORD                                             ' HINF

DECLARE FUNCTION SetupOpenAppendInfFileA IMPORT "SETUPAPI.DLL" ALIAS "SetupOpenAppendInfFileA" ( _
   BYREF FileName AS ASCIIZ _                           ' __in_opt PCSTR FileName
 , BYVAL InfHandle AS DWORD _                           ' __in HINF InfHandle
 , OPTIONAL BYREF ErrorLine AS DWORD _                  ' __out_opt PUINT ErrorLine
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SetupOpenAppendInfFileW IMPORT "SETUPAPI.DLL" ALIAS "SetupOpenAppendInfFileW" ( _
   BYREF FileName AS WSTRINGZ _                         ' __in_opt PCWSTR FileName
 , BYVAL InfHandle AS DWORD _                           ' __in HINF InfHandle
 , OPTIONAL BYREF ErrorLine AS DWORD _                  ' __out_opt PUINT ErrorLine
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO SetupOpenAppendInfFile = SetupOpenAppendInfFileW
#ELSE
   MACRO SetupOpenAppendInfFile = SetupOpenAppendInfFileA
#ENDIF

DECLARE SUB SetupCloseInfFile IMPORT "SETUPAPI.DLL" ALIAS "SetupCloseInfFile" ( _
   BYVAL InfHandle AS DWORD _                           ' __in HINF InfHandle
 )                                                      ' void

DECLARE FUNCTION SetupFindFirstLineA IMPORT "SETUPAPI.DLL" ALIAS "SetupFindFirstLineA" ( _
   BYVAL InfHandle AS DWORD _                           ' __in HINF InfHandle
 , BYREF Section AS ASCIIZ _                            ' __in PCSTR Section
 , BYREF Key AS ASCIIZ _                                ' __in_opt PCSTR Key
 , BYREF Context AS INFCONTEXT _                        ' __out PINFCONTEXT Context
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SetupFindFirstLineW IMPORT "SETUPAPI.DLL" ALIAS "SetupFindFirstLineW" ( _
   BYVAL InfHandle AS DWORD _                           ' __in HINF InfHandle
 , BYREF Section AS WSTRINGZ _                          ' __in PCWSTR Section
 , BYREF Key AS WSTRINGZ _                              ' __in_opt PCWSTR Key
 , BYREF Context AS INFCONTEXT _                        ' __out PINFCONTEXT Context
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO SetupFindFirstLine = SetupFindFirstLineW
#ELSE
   MACRO SetupFindFirstLine = SetupFindFirstLineA
#ENDIF

DECLARE FUNCTION SetupFindNextLine IMPORT "SETUPAPI.DLL" ALIAS "SetupFindNextLine" ( _
   BYREF ContextIn AS INFCONTEXT _                      ' __in PINFCONTEXT ContextIn
 , BYREF Context AS INFCONTEXT _                        ' __out PINFCONTEXT Context
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SetupFindNextMatchLineA IMPORT "SETUPAPI.DLL" ALIAS "SetupFindNextMatchLineA" ( _
   BYREF ContextIn AS INFCONTEXT _                      ' __in PINFCONTEXT ContextIn
 , BYREF Key AS ASCIIZ _                                ' __in_opt PCSTR Key
 , BYREF Context AS INFCONTEXT _                        ' __out PINFCONTEXT Context
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SetupFindNextMatchLineW IMPORT "SETUPAPI.DLL" ALIAS "SetupFindNextMatchLineW" ( _
   BYREF ContextIn AS INFCONTEXT _                      ' __in PINFCONTEXT ContextIn
 , BYREF Key AS WSTRINGZ _                              ' __in_opt PCWSTR Key
 , BYREF Context AS INFCONTEXT _                        ' __out PINFCONTEXT Context
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO SetupFindNextMatchLine = SetupFindNextMatchLineW
#ELSE
   MACRO SetupFindNextMatchLine = SetupFindNextMatchLineA
#ENDIF

DECLARE FUNCTION SetupGetLineByIndexA IMPORT "SETUPAPI.DLL" ALIAS "SetupGetLineByIndexA" ( _
   BYVAL InfHandle AS DWORD _                           ' __in HINF InfHandle
 , BYREF Section AS ASCIIZ _                            ' __in PCSTR Section
 , BYVAL Index AS DWORD _                               ' __in DWORD Index
 , BYREF Context AS INFCONTEXT _                        ' __out PINFCONTEXT Context
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SetupGetLineByIndexW IMPORT "SETUPAPI.DLL" ALIAS "SetupGetLineByIndexW" ( _
   BYVAL InfHandle AS DWORD _                           ' __in HINF InfHandle
 , BYREF Section AS WSTRINGZ _                          ' __in PCWSTR Section
 , BYVAL Index AS DWORD _                               ' __in DWORD Index
 , BYREF Context AS INFCONTEXT _                        ' __out PINFCONTEXT Context
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO SetupGetLineByIndex = SetupGetLineByIndexW
#ELSE
   MACRO SetupGetLineByIndex = SetupGetLineByIndexA
#ENDIF

DECLARE FUNCTION SetupGetLineCountA IMPORT "SETUPAPI.DLL" ALIAS "SetupGetLineCountA" ( _
   BYVAL InfHandle AS DWORD _                           ' __in HINF InfHandle
 , BYREF Section AS ASCIIZ _                            ' __in PCSTR Section
 ) AS LONG                                              ' LONG

DECLARE FUNCTION SetupGetLineCountW IMPORT "SETUPAPI.DLL" ALIAS "SetupGetLineCountW" ( _
   BYVAL InfHandle AS DWORD _                           ' __in HINF InfHandle
 , BYREF Section AS WSTRINGZ _                          ' __in PCWSTR Section
 ) AS LONG                                              ' LONG

#IF %DEF(%UNICODE)
   MACRO SetupGetLineCount = SetupGetLineCountW
#ELSE
   MACRO SetupGetLineCount = SetupGetLineCountA
#ENDIF

DECLARE FUNCTION SetupGetLineTextA IMPORT "SETUPAPI.DLL" ALIAS "SetupGetLineTextA" ( _
   BYREF Context AS INFCONTEXT _                        ' __in_opt PINFCONTEXT Context
 , BYVAL InfHandle AS DWORD _                           ' __in_opt HINF InfHandle
 , BYREF Section AS ASCIIZ _                            ' __in_opt PCSTR Section
 , BYREF Key AS ASCIIZ _                                ' __in_opt PCSTR Key
 , BYREF ReturnBuffer AS ASCIIZ _                       ' __out PSTR ReturnBuffer
 , BYVAL ReturnBufferSize AS DWORD _                    ' __in DWORD ReturnBufferSize
 , OPTIONAL BYREF RequiredSize AS DWORD _               ' __out_opt PDWORD RequiredSize
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SetupGetLineTextW IMPORT "SETUPAPI.DLL" ALIAS "SetupGetLineTextW" ( _
   BYREF Context AS INFCONTEXT _                        ' __in_opt PINFCONTEXT Context
 , BYVAL InfHandle AS DWORD _                           ' __in_opt HINF InfHandle
 , BYREF Section AS WSTRINGZ _                          ' __in_opt PCWSTR Section
 , BYREF Key AS WSTRINGZ _                              ' __in_opt PCWSTR Key
 , BYREF ReturnBuffer AS WSTRINGZ _                     ' __out PWSTR ReturnBuffer
 , BYVAL ReturnBufferSize AS DWORD _                    ' __in DWORD ReturnBufferSize
 , OPTIONAL BYREF RequiredSize AS DWORD _               ' __out_opt PDWORD RequiredSize
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO SetupGetLineText = SetupGetLineTextW
#ELSE
   MACRO SetupGetLineText = SetupGetLineTextA
#ENDIF

DECLARE FUNCTION SetupGetFieldCount IMPORT "SETUPAPI.DLL" ALIAS "SetupGetFieldCount" ( _
   BYREF Context AS INFCONTEXT _                        ' __in PINFCONTEXT Context
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION SetupGetStringFieldA IMPORT "SETUPAPI.DLL" ALIAS "SetupGetStringFieldA" ( _
   BYREF Context AS INFCONTEXT _                        ' __in PINFCONTEXT Context
 , BYVAL FieldIndex AS DWORD _                          ' __in DWORD FieldIndex
 , BYREF ReturnBuffer AS ASCIIZ _                       ' __out PSTR ReturnBuffer
 , BYVAL ReturnBufferSize AS DWORD _                    ' __in DWORD ReturnBufferSize
 , OPTIONAL BYREF RequiredSize AS DWORD _               ' __out_opt PDWORD RequiredSize
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SetupGetStringFieldW IMPORT "SETUPAPI.DLL" ALIAS "SetupGetStringFieldW" ( _
   BYREF Context AS INFCONTEXT _                        ' __in PINFCONTEXT Context
 , BYVAL FieldIndex AS DWORD _                          ' __in DWORD FieldIndex
 , BYREF ReturnBuffer AS WSTRINGZ _                     ' __out PWSTR ReturnBuffer
 , BYVAL ReturnBufferSize AS DWORD _                    ' __in DWORD ReturnBufferSize
 , OPTIONAL BYREF RequiredSize AS DWORD _               ' __out_opt PDWORD RequiredSize
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO SetupGetStringField = SetupGetStringFieldW
#ELSE
   MACRO SetupGetStringField = SetupGetStringFieldA
#ENDIF

DECLARE FUNCTION SetupGetIntField IMPORT "SETUPAPI.DLL" ALIAS "SetupGetIntField" ( _
   BYREF Context AS INFCONTEXT _                        ' __in PINFCONTEXT Context
 , BYVAL FieldIndex AS DWORD _                          ' __in DWORD FieldIndex
 , BYREF IntegerValue AS LONG _                         ' __out PINT IntegerValue
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SetupGetMultiSzFieldA IMPORT "SETUPAPI.DLL" ALIAS "SetupGetMultiSzFieldA" ( _
   BYREF Context AS INFCONTEXT _                        ' __in PINFCONTEXT Context
 , BYVAL FieldIndex AS DWORD _                          ' __in DWORD FieldIndex
 , BYREF ReturnBuffer AS ASCIIZ _                       ' __out PSTR ReturnBuffer
 , BYVAL ReturnBufferSize AS DWORD _                    ' __in DWORD ReturnBufferSize
 , OPTIONAL BYREF RequiredSize AS DWORD _               ' __out_opt LPDWORD RequiredSize
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SetupGetMultiSzFieldW IMPORT "SETUPAPI.DLL" ALIAS "SetupGetMultiSzFieldW" ( _
   BYREF Context AS INFCONTEXT _                        ' __in PINFCONTEXT Context
 , BYVAL FieldIndex AS DWORD _                          ' __in DWORD FieldIndex
 , BYREF ReturnBuffer AS WSTRINGZ _                     ' __out PWSTR ReturnBuffer
 , BYVAL ReturnBufferSize AS DWORD _                    ' __in DWORD ReturnBufferSize
 , OPTIONAL BYREF RequiredSize AS DWORD _               ' __out_opt LPDWORD RequiredSize
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO SetupGetMultiSzField = SetupGetMultiSzFieldW
#ELSE
   MACRO SetupGetMultiSzField = SetupGetMultiSzFieldA
#ENDIF

DECLARE FUNCTION SetupGetBinaryField IMPORT "SETUPAPI.DLL" ALIAS "SetupGetBinaryField" ( _
   BYREF Context AS INFCONTEXT _                        ' __in PINFCONTEXT Context
 , BYVAL FieldIndex AS DWORD _                          ' __in DWORD FieldIndex
 , BYVAL ReturnBuffer AS BYTE PTR _                     ' __out PBYTE ReturnBuffer
 , BYVAL ReturnBufferSize AS DWORD _                    ' __in DWORD ReturnBufferSize
 , OPTIONAL BYREF RequiredSize AS DWORD _               ' __out_opt LPDWORD RequiredSize
 ) AS LONG                                              ' BOOL

' //
' // SetupGetFileCompressionInfo is depreciated
' // use SetupGetFileCompressionInfoEx instead
' //
' // ActualSourceFileName returned by SetupGetFileCompressionInfo
' // must be freed by the export setupapi!MyFree (NT4+ Win95+)
' // or LocalFree (Win2k+)
' //

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SetupGetFileCompressionInfoA LIB "SetupApi.dll" _
    ALIAS "SetupGetFileCompressionInfoA" ( _
    SourceFileName AS ASCIIZ, _
    BYVAL ActualSourceFileName AS DWORD, _  ' PSTR *
    SourceFileSize AS DWORD, _
    TargetFileSize AS DWORD, _
    CompressionType AS DWORD _
    ) AS DWORD
#ELSE
DECLARE FUNCTION SetupGetFileCompressionInfoA IMPORT "SETUPAPI.DLL" ALIAS "SetupGetFileCompressionInfoA" ( _
   BYREF SourceFileName AS ASCIIZ _                     ' __in PCSTR SourceFileName
 , BYREF ActualSourceFileName AS DWORD _                ' __out PSTR *ActualSourceFileName
 , BYREF SourceFileSize AS DWORD _                      ' __out PDWORD SourceFileSize
 , BYREF TargetFileSize AS DWORD _                      ' __out PDWORD TargetFileSize
 , BYREF CompressionType AS DWORD _                     ' __out PUINT CompressionType
 ) AS DWORD                                             ' DWORD
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SetupGetFileCompressionInfoW LIB "SetupApi.dll" _
    ALIAS "SetupGetFileCompressionInfoW" ( _
    SourceFileName AS WSTRINGZ, _
    BYVAL ActualSourceFileName AS DWORD, _  ' PWSTR *
    SourceFileSize AS DWORD, _
    TargetFileSize AS DWORD, _
    CompressionType AS DWORD _
    ) AS DWORD
#ELSE
DECLARE FUNCTION SetupGetFileCompressionInfoW IMPORT "SETUPAPI.DLL" ALIAS "SetupGetFileCompressionInfoW" ( _
   BYREF SourceFileName AS WSTRINGZ _                   ' __in PCWSTR SourceFileName
 , BYREF ActualSourceFileName AS DWORD _                ' __out PWSTR *ActualSourceFileName
 , BYREF SourceFileSize AS DWORD _                      ' __out PDWORD SourceFileSize
 , BYREF TargetFileSize AS DWORD _                      ' __out PDWORD TargetFileSize
 , BYREF CompressionType AS DWORD _                     ' __out PUINT CompressionType
 ) AS DWORD                                             ' DWORD
#ENDIF

#IF %DEF(%UNICODE)
   MACRO SetupGetFileCompressionInfo = SetupGetFileCompressionInfoW
#ELSE
   MACRO SetupGetFileCompressionInfo = SetupGetFileCompressionInfoA
#ENDIF

'#if _SETUPAPI_VER >= _WIN32_WINNT_WINXP
#IF %SETUPAPI_VER >= %WIN32_WINNT_WINXP

' //
' // SetupGetFileCompressionInfoEx is the preferred API over
' // SetupGetFileCompressionInfo. It follows the normal
' // conventions of returning BOOL and writing to user-supplied
' // buffer.
' //

DECLARE FUNCTION SetupGetFileCompressionInfoExA IMPORT "SETUPAPI.DLL" ALIAS "SetupGetFileCompressionInfoExA" ( _
   BYREF SourceFileName AS ASCIIZ _                     ' __in PCSTR SourceFileName
 , BYREF ActualSourceFileNameBuffer AS ASCIIZ _         ' __in PSTR ActualSourceFileNameBuffer
 , BYVAL ActualSourceFileNameBufferLen AS DWORD _       ' __in DWORD ActualSourceFileNameBufferLen
 , BYREF RequiredBufferLen AS DWORD _                   ' __out_opt PDWORD RequiredBufferLen
 , BYREF SourceFileSize AS DWORD _                      ' __out PDWORD SourceFileSize
 , BYREF TargetFileSize AS DWORD _                      ' __out PDWORD TargetFileSize
 , BYREF CompressionType AS DWORD _                     ' __out PUINT CompressionType
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SetupGetFileCompressionInfoExW IMPORT "SETUPAPI.DLL" ALIAS "SetupGetFileCompressionInfoExW" ( _
   BYREF SourceFileName AS WSTRINGZ _                   ' __in PCWSTR SourceFileName
 , BYREF ActualSourceFileNameBuffer AS WSTRINGZ _       ' __in PWSTR ActualSourceFileNameBuffer
 , BYVAL ActualSourceFileNameBufferLen AS DWORD _       ' __in DWORD ActualSourceFileNameBufferLen
 , BYREF RequiredBufferLen AS DWORD _                   ' __out_opt PDWORD RequiredBufferLen
 , BYREF SourceFileSize AS DWORD _                      ' __out PDWORD SourceFileSize
 , BYREF TargetFileSize AS DWORD _                      ' __out PDWORD TargetFileSize
 , BYREF CompressionType AS DWORD _                     ' __out PUINT CompressionType
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO SetupGetFileCompressionInfoEx = SetupGetFileCompressionInfoExW
#ELSE
   MACRO SetupGetFileCompressionInfoEx = SetupGetFileCompressionInfoExA
#ENDIF

#ENDIF ' %SETUPAPI_VER >= %WIN32_WINNT_WINXP
'#endif // _SETUPAPI_VER >= _WIN32_WINNT_WINXP

' //
' // Compression types
' //
%FILE_COMPRESSION_NONE      = 0
%FILE_COMPRESSION_WINLZA    = 1
%FILE_COMPRESSION_MSZIP     = 2
%FILE_COMPRESSION_NTCAB     = 3

DECLARE FUNCTION SetupDecompressOrCopyFileA IMPORT "SETUPAPI.DLL" ALIAS "SetupDecompressOrCopyFileA" ( _
   BYREF SourceFileName AS ASCIIZ _                     ' __in PCSTR SourceFileName
 , BYREF TargetFileName AS ASCIIZ _                     ' __in PCSTR TargetFileName
 , OPTIONAL BYREF CompressionType AS DWORD _            ' __in_opt PUINT CompressionType
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION SetupDecompressOrCopyFileW IMPORT "SETUPAPI.DLL" ALIAS "SetupDecompressOrCopyFileW" ( _
   BYREF SourceFileName AS WSTRINGZ _                   ' __in PCWSTR SourceFileName
 , BYREF TargetFileName AS WSTRINGZ _                   ' __in PCWSTR TargetFileName
 , OPTIONAL BYREF CompressionType AS DWORD _            ' __in_opt PUINT CompressionType
 ) AS DWORD                                             ' DWORD

#IF %DEF(%UNICODE)
   MACRO SetupDecompressOrCopyFile = SetupDecompressOrCopyFileW
#ELSE
   MACRO SetupDecompressOrCopyFile = SetupDecompressOrCopyFileA
#ENDIF

DECLARE FUNCTION SetupGetSourceFileLocationA IMPORT "SETUPAPI.DLL" ALIAS "SetupGetSourceFileLocationA" ( _
   BYVAL InfHandle AS DWORD _                           ' __in HINF InfHandle
 , BYREF InfContext AS INFCONTEXT _                     ' __in_opt PINFCONTEXT InfContext
 , BYREF FileName AS ASCIIZ _                           ' __in_opt PCSTR FileName
 , BYREF SourceId AS DWORD _                            ' __out PUINT SourceId
 , BYREF ReturnBuffer AS ASCIIZ _                       ' __out PSTR ReturnBuffer
 , BYVAL ReturnBufferSize AS DWORD _                    ' __in DWORD ReturnBufferSize
 , OPTIONAL BYREF RequiredSize AS DWORD _               ' __out_opt PDWORD RequiredSize
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SetupGetSourceFileLocationW IMPORT "SETUPAPI.DLL" ALIAS "SetupGetSourceFileLocationW" ( _
   BYVAL InfHandle AS DWORD _                           ' __in HINF InfHandle
 , BYREF InfContext AS INFCONTEXT _                     ' __in_opt PINFCONTEXT InfContext
 , BYREF FileName AS WSTRINGZ _                         ' __in_opt PCWSTR FileName
 , BYREF SourceId AS DWORD _                            ' __out PUINT SourceId
 , BYREF ReturnBuffer AS WSTRINGZ _                      ' __out PWSTR ReturnBuffer
 , BYVAL ReturnBufferSize AS DWORD _                    ' __in DWORD ReturnBufferSize
 , OPTIONAL BYREF RequiredSize AS DWORD _               ' __out_opt PDWORD RequiredSize
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO SetupGetSourceFileLocation = SetupGetSourceFileLocationW
#ELSE
   MACRO SetupGetSourceFileLocation = SetupGetSourceFileLocationA
#ENDIF

DECLARE FUNCTION SetupGetSourceFileSizeA IMPORT "SETUPAPI.DLL" ALIAS "SetupGetSourceFileSizeA" ( _
   BYVAL InfHandle AS DWORD _                           ' __in HINF InfHandle
 , BYREF InfContext AS INFCONTEXT _                     ' __in_opt PINFCONTEXT InfContext
 , BYREF FileName AS ASCIIZ _                           ' __in_opt PCSTR FileName
 , BYREF Section AS ASCIIZ _                            ' __in_opt PCSTR Section
 , BYREF FileSize AS DWORD _                            ' __out PDWORD FileSize
 , BYVAL RoundingFactor AS DWORD _                      ' __in UINT RoundingFactor
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SetupGetSourceFileSizeW IMPORT "SETUPAPI.DLL" ALIAS "SetupGetSourceFileSizeW" ( _
   BYVAL InfHandle AS DWORD _                           ' __in HINF InfHandle
 , BYREF InfContext AS INFCONTEXT _                     ' __in_opt PINFCONTEXT InfContext
 , BYREF FileName AS WSTRINGZ _                         ' __in_opt PCWSTR FileName
 , BYREF Section AS WSTRINGZ _                          ' __in_opt PCWSTR Section
 , BYREF FileSize AS DWORD _                            ' __out PDWORD FileSize
 , BYVAL RoundingFactor AS DWORD _                      ' __in UINT RoundingFactor
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO SetupGetSourceFileSize = SetupGetSourceFileSizeW
#ELSE
   MACRO SetupGetSourceFileSize = SetupGetSourceFileSizeA
#ENDIF

DECLARE FUNCTION SetupGetTargetPathA IMPORT "SETUPAPI.DLL" ALIAS "SetupGetTargetPathA" ( _
   BYVAL InfHandle AS DWORD _                           ' __in HINF InfHandle
 , BYREF InfContext AS INFCONTEXT _                     ' __in_opt PINFCONTEXT InfContext
 , BYREF Section AS ASCIIZ _                            ' __in_opt PCSTR Section
 , BYREF ReturnBuffer AS ASCIIZ _                       ' __out PSTR ReturnBuffer
 , BYVAL ReturnBufferSize AS DWORD _                    ' __in DWORD ReturnBufferSize
 , OPTIONAL BYREF RequiredSize AS DWORD _               ' __out_opt PDWORD RequiredSize
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SetupGetTargetPathW IMPORT "SETUPAPI.DLL" ALIAS "SetupGetTargetPathW" ( _
   BYVAL InfHandle AS DWORD _                           ' __in HINF InfHandle
 , BYREF InfContext AS INFCONTEXT _                     ' __in_opt PINFCONTEXT InfContext
 , BYREF Section AS WSTRINGZ _                          ' __in_opt PCWSTR Section
 , BYREF ReturnBuffer AS WSTRINGZ _                     ' __out PWSTR ReturnBuffer
 , BYVAL ReturnBufferSize AS DWORD _                    ' __in DWORD ReturnBufferSize
 , OPTIONAL BYREF RequiredSize AS DWORD _               ' __out_opt PDWORD RequiredSize
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO SetupGetTargetPath = SetupGetTargetPathW
#ELSE
   MACRO SetupGetTargetPath = SetupGetTargetPathA
#ENDIF

' //
' // Define flags for SourceList APIs.
' //
%SRCLIST_TEMPORARY       = &H00000001???
%SRCLIST_NOBROWSE        = &H00000002???
%SRCLIST_SYSTEM          = &H00000010???
%SRCLIST_USER            = &H00000020???
%SRCLIST_SYSIFADMIN      = &H00000040???
%SRCLIST_SUBDIRS         = &H00000100???
%SRCLIST_APPEND          = &H00000200???
%SRCLIST_NOSTRIPPLATFORM = &H00000400???

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SetupSetSourceListA LIB "SetupApi.dll" _
    ALIAS "SetupSetSourceListA" ( _
    BYVAL Flags AS DWORD, _
    BYVAL SourceList AS DWORD, _  ' PCSTR *
    BYVAL SourceCount AS DWORD _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupSetSourceListA IMPORT "SETUPAPI.DLL" ALIAS "SetupSetSourceListA" ( _
   BYVAL Flags AS DWORD _                               ' __in DWORD Flags
 , BYREF SourceList AS ASCIIZ _                         ' __in PCSTR *SourceList
 , BYVAL SourceCount AS DWORD _                         ' __in UINT SourceCount
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SetupSetSourceListW LIB "SetupApi.dll" _
    ALIAS "SetupSetSourceListW" ( _
    BYVAL Flags AS DWORD, _
    BYVAL SourceList AS DWORD, _  ' PCWSTR *
    BYVAL SourceCount AS DWORD _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupSetSourceListW IMPORT "SETUPAPI.DLL" ALIAS "SetupSetSourceListW" ( _
   BYVAL Flags AS DWORD _                               ' __in DWORD Flags
 , BYREF SourceList AS WSTRINGZ _                       ' __in PCWSTR *SourceList
 , BYVAL SourceCount AS DWORD _                         ' __in UINT SourceCount
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%UNICODE)
   MACRO SetupSetSourceList = SetupSetSourceListW
#ELSE
   MACRO SetupSetSourceList = SetupSetSourceListA
#ENDIF

DECLARE FUNCTION SetupCancelTemporarySourceList IMPORT "SETUPAPI.DLL" ALIAS "SetupCancelTemporarySourceList" ( _
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SetupAddToSourceListA IMPORT "SETUPAPI.DLL" ALIAS "SetupAddToSourceListA" ( _
   BYVAL Flags AS DWORD _                               ' __in DWORD Flags
 , BYREF Source AS ASCIIZ _                             ' __in PCSTR Source
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SetupAddToSourceListW IMPORT "SETUPAPI.DLL" ALIAS "SetupAddToSourceListW" ( _
   BYVAL Flags AS DWORD _                               ' __in DWORD Flags
 , BYREF Source AS WSTRINGZ _                           ' __in PCWSTR Source
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO SetupAddToSourceList = SetupAddToSourceListW
#ELSE
   MACRO SetupAddToSourceList = SetupAddToSourceListA
#ENDIF

DECLARE FUNCTION SetupRemoveFromSourceListA IMPORT "SETUPAPI.DLL" ALIAS "SetupRemoveFromSourceListA" ( _
   BYVAL Flags AS DWORD _                               ' __in DWORD Flags
 , BYREF Source AS ASCIIZ _                             ' __in PCSTR Source
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SetupRemoveFromSourceListW IMPORT "SETUPAPI.DLL" ALIAS "SetupRemoveFromSourceListW" ( _
   BYVAL Flags AS DWORD _                               ' __in DWORD Flags
 , BYREF Source AS WSTRINGZ _                           ' __in PCWSTR Source
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO SetupRemoveFromSourceList = SetupRemoveFromSourceListW
#ELSE
   MACRO SetupRemoveFromSourceList = SetupRemoveFromSourceListA
#ENDIF

DECLARE FUNCTION SetupQuerySourceListA IMPORT "SETUPAPI.DLL" ALIAS "SetupQuerySourceListA" ( _
   BYVAL Flags AS DWORD _                               ' __in DWORD Flags
 , BYREF List AS DWORD _                                ' __out PCSTR **List
 , BYREF Count AS DWORD _                               ' __out PUINT Count
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SetupQuerySourceListW IMPORT "SETUPAPI.DLL" ALIAS "SetupQuerySourceListW" ( _
   BYVAL Flags AS DWORD _                               ' __in DWORD Flags
 , BYREF List AS DWORD _                                ' __out PCWSTR **List
 , BYREF Count AS DWORD _                               ' __out PUINT Count
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO SetupQuerySourceList = SetupQuerySourceListW
#ELSE
   MACRO SetupQuerySourceList = SetupQuerySourceListA
#ENDIF

DECLARE FUNCTION SetupFreeSourceListA IMPORT "SETUPAPI.DLL" ALIAS "SetupFreeSourceListA" ( _
   BYREF List AS DWORD _                                ' __out PCSTR **List
 , BYVAL Count AS DWORD _                               ' __in PUINT Count
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SetupFreeSourceListW IMPORT "SETUPAPI.DLL" ALIAS "SetupFreeSourceListW" ( _
   BYREF List AS DWORD _                                ' __out PCWSTR **List
 , BYVAL Count AS DWORD _                               ' __in PUINT Count
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO SetupFreeSourceList = SetupFreeSourceListW
#ELSE
   MACRO SetupFreeSourceList = SetupFreeSourceListA
#ENDIF

DECLARE FUNCTION SetupPromptForDiskA IMPORT "SETUPAPI.DLL" ALIAS "SetupPromptForDiskA" ( _
   BYVAL hwndParent AS DWORD _                          ' __in HWND hwndParent
 , BYREF DialogTitle AS ASCIIZ _                        ' __in_opt PCSTR DialogTitle
 , BYREF DiskName AS ASCIIZ _                           ' __in_opt PCSTR DiskName
 , BYREF PathToSource AS ASCIIZ _                       ' __in_opt PCSTR PathToSource
 , BYREF FileSought AS ASCIIZ _                         ' __in PCSTR FileSought
 , BYREF TagFile AS ASCIIZ _                            ' __in_opt PCSTR TagFile
 , BYVAL DiskPromptStyle AS DWORD _                     ' __in DWORD DiskPromptStyle
 , BYREF PathBuffer AS ASCIIZ _                         ' __out PSTR PathBuffer
 , BYVAL PathBufferSize AS DWORD _                      ' __in DWORD PathBufferSize
 , OPTIONAL BYREF PathRequiredSize AS DWORD _           ' __out_opt PDWORD PathRequiredSize
 ) AS DWORD                                             ' UINT

DECLARE FUNCTION SetupPromptForDiskW IMPORT "SETUPAPI.DLL" ALIAS "SetupPromptForDiskW" ( _
   BYVAL hwndParent AS DWORD _                          ' __in HWND hwndParent
 , BYREF DialogTitle AS WSTRINGZ _                      ' __in_opt PCWSTR DialogTitle
 , BYREF DiskName AS WSTRINGZ _                         ' __in_opt PCWSTR DiskName
 , BYREF PathToSource AS WSTRINGZ _                     ' __in_opt PCWSTR PathToSource
 , BYREF FileSought AS WSTRINGZ _                       ' __in PCWSTR FileSought
 , BYREF TagFile AS WSTRINGZ _                          ' __in_opt PCWSTR TagFile
 , BYVAL DiskPromptStyle AS DWORD _                     ' __in DWORD DiskPromptStyle
 , BYREF PathBuffer AS WSTRINGZ _                       ' __out PWSTR PathBuffer
 , BYVAL PathBufferSize AS DWORD _                      ' __in DWORD PathBufferSize
 , OPTIONAL BYREF PathRequiredSize AS DWORD _           ' __out_opt PDWORD PathRequiredSize
 ) AS DWORD                                             ' UINT

#IF %DEF(%UNICODE)
   MACRO SetupPromptForDisk = SetupPromptForDiskW
#ELSE
   MACRO SetupPromptForDisk = SetupPromptForDiskA
#ENDIF

DECLARE FUNCTION SetupCopyErrorA IMPORT "SETUPAPI.DLL" ALIAS "SetupCopyErrorA" ( _
   BYVAL hwndParent AS DWORD _                          ' __in HWND hwndParent
 , BYREF DialogTitle AS ASCIIZ _                        ' __in_opt PCSTR DialogTitle
 , BYREF DiskName AS ASCIIZ _                           ' __in_opt PCSTR DiskName
 , BYREF PathToSource AS ASCIIZ _                       ' __in PCSTR PathToSource
 , BYREF SourceFile AS ASCIIZ _                         ' __in PCSTR SourceFile
 , BYREF TargetPathFile AS ASCIIZ _                     ' __in_opt PCSTR TargetPathFile
 , BYVAL Win32ErrorCode AS DWORD _                      ' __in UINT Win32ErrorCode
 , BYVAL Style AS DWORD _                               ' __in DWORD Style
 , BYREF PathBuffer AS ASCIIZ _                         ' __out PSTR PathBuffer
 , BYVAL PathBufferSize AS DWORD _                      ' __in DWORD PathBufferSize
 , OPTIONAL BYREF PathRequiredSize AS DWORD _           ' __out_opt PDWORD PathRequiredSize
 ) AS DWORD                                             ' UINT

DECLARE FUNCTION SetupCopyErrorW IMPORT "SETUPAPI.DLL" ALIAS "SetupCopyErrorW" ( _
   BYVAL hwndParent AS DWORD _                          ' __in HWND hwndParent
 , BYREF DialogTitle AS WSTRINGZ _                      ' __in_opt PCWSTR DialogTitle
 , BYREF DiskName AS WSTRINGZ _                         ' __in_opt PCWSTR DiskName
 , BYREF PathToSource AS WSTRINGZ _                     ' __in PCWSTR PathToSource
 , BYREF SourceFile AS WSTRINGZ _                       ' __in PCWSTR SourceFile
 , BYREF TargetPathFile AS WSTRINGZ _                   ' __in_opt PCWSTR TargetPathFile
 , BYVAL Win32ErrorCode AS DWORD _                      ' __in UINT Win32ErrorCode
 , BYVAL Style AS DWORD _                               ' __in DWORD Style
 , BYREF PathBuffer AS WSTRINGZ _                       ' __out PWSTR PathBuffer
 , BYVAL PathBufferSize AS DWORD _                      ' __in DWORD PathBufferSize
 , OPTIONAL BYREF PathRequiredSize AS DWORD _           ' __out_opt PDWORD PathRequiredSize
 ) AS DWORD                                             ' UINT

#IF %DEF(%UNICODE)
   MACRO SetupCopyError = SetupCopyErrorW
#ELSE
   MACRO SetupCopyError = SetupCopyErrorA
#ENDIF

DECLARE FUNCTION SetupRenameErrorA IMPORT "SETUPAPI.DLL" ALIAS "SetupRenameErrorA" ( _
   BYVAL hwndParent AS DWORD _                          ' __in HWND hwndParent
 , BYREF DialogTitle AS ASCIIZ _                        ' __in_opt PCSTR DialogTitle
 , BYREF SourceFile AS ASCIIZ _                         ' __in PCSTR SourceFile
 , BYREF TargetFile AS ASCIIZ _                         ' __in PCSTR TargetFile
 , BYVAL Win32ErrorCode AS DWORD _                      ' __in UINT Win32ErrorCode
 , BYVAL Style AS DWORD _                               ' __in DWORD Style
 ) AS DWORD                                             ' UINT

DECLARE FUNCTION SetupRenameErrorW IMPORT "SETUPAPI.DLL" ALIAS "SetupRenameErrorW" ( _
   BYVAL hwndParent AS DWORD _                          ' __in HWND hwndParent
 , BYREF DialogTitle AS WSTRINGZ _                      ' __in_opt PCWSTR DialogTitle
 , BYREF SourceFile AS WSTRINGZ _                       ' __in PCWSTR SourceFile
 , BYREF TargetFile AS WSTRINGZ _                       ' __in PCWSTR TargetFile
 , BYVAL Win32ErrorCode AS DWORD _                      ' __in UINT Win32ErrorCode
 , BYVAL Style AS DWORD _                               ' __in DWORD Style
 ) AS DWORD                                             ' UINT

#IF %DEF(%UNICODE)
   MACRO SetupRenameError = SetupRenameErrorW
#ELSE
   MACRO SetupRenameError = SetupRenameErrorA
#ENDIF

DECLARE FUNCTION SetupDeleteErrorA IMPORT "SETUPAPI.DLL" ALIAS "SetupDeleteErrorA" ( _
   BYVAL hwndParent AS DWORD _                          ' __in HWND hwndParent
 , BYREF DialogTitle AS ASCIIZ _                        ' __in_opt PCSTR DialogTitle
 , BYREF File AS ASCIIZ _                               ' __in PCSTR File
 , BYVAL Win32ErrorCode AS DWORD _                      ' __in UINT Win32ErrorCode
 , BYVAL Style AS DWORD _                               ' __in DWORD Style
 ) AS DWORD                                             ' UINT

DECLARE FUNCTION SetupDeleteErrorW IMPORT "SETUPAPI.DLL" ALIAS "SetupDeleteErrorW" ( _
   BYVAL hwndParent AS DWORD _                          ' __in HWND hwndParent
 , BYREF DialogTitle AS WSTRINGZ _                      ' __in_opt PCWSTR DialogTitle
 , BYREF File AS WSTRINGZ _                             ' __in PCWSTR File
 , BYVAL Win32ErrorCode AS DWORD _                      ' __in UINT Win32ErrorCode
 , BYVAL Style AS DWORD _                               ' __in DWORD Style
 ) AS DWORD                                             ' UINT

#IF %DEF(%UNICODE)
   MACRO SetupDeleteError = SetupDeleteErrorW
#ELSE
   MACRO SetupDeleteError = SetupDeleteErrorA
#ENDIF

DECLARE FUNCTION SetupBackupErrorA IMPORT "SETUPAPI.DLL" ALIAS "SetupBackupErrorA" ( _
   BYVAL hwndParent AS DWORD _                          ' __in HWND hwndParent
 , BYREF DialogTitle AS ASCIIZ _                        ' __in_opt PCSTR DialogTitle
 , BYREF SourceFile AS ASCIIZ _                         ' __in PCSTR SourceFile
 , BYREF TargetFile AS ASCIIZ _                         ' __in PCSTR TargetFile
 , BYVAL Win32ErrorCode AS DWORD _                      ' __in UINT Win32ErrorCode
 , BYVAL Style AS DWORD _                               ' __in DWORD Style
 ) AS DWORD                                             ' UINT

DECLARE FUNCTION SetupBackupErrorW IMPORT "SETUPAPI.DLL" ALIAS "SetupBackupErrorW" ( _
   BYVAL hwndParent AS DWORD _                          ' __in HWND hwndParent
 , BYREF DialogTitle AS WSTRINGZ _                      ' __in_opt PCWSTR DialogTitle
 , BYREF SourceFile AS WSTRINGZ _                       ' __in PCWSTR SourceFile
 , BYREF TargetFile AS WSTRINGZ _                       ' __in PCWSTR TargetFile
 , BYVAL Win32ErrorCode AS DWORD _                      ' __in UINT Win32ErrorCode
 , BYVAL Style AS DWORD _                               ' __in DWORD Style
 ) AS DWORD                                             ' UINT

#IF %DEF(%UNICODE)
   MACRO SetupBackupError = SetupBackupErrorW
#ELSE
   MACRO SetupBackupError = SetupBackupErrorA
#ENDIF

' //
' // Styles for SetupPromptForDisk, SetupCopyError,
' // SetupRenameError, SetupDeleteError
' //
%IDF_NOBROWSE                    = &H00000001???
%IDF_NOSKIP                      = &H00000002???
%IDF_NODETAILS                   = &H00000004???
%IDF_NOCOMPRESSED                = &H00000008???
%IDF_CHECKFIRST                  = &H00000100???
%IDF_NOBEEP                      = &H00000200???
%IDF_NOFOREGROUND                = &H00000400???
%IDF_WARNIFSKIP                  = &H00000800???

'#if _SETUPAPI_VER >= _WIN32_WINNT_WINXP
#IF %SETUPAPI_VER >= %WIN32_WINNT_WINXP

%IDF_NOREMOVABLEMEDIAPROMPT      = &H00001000???
%IDF_USEDISKNAMEASPROMPT         = &H00002000???
%IDF_OEMDISK                     = &H80000000???

#ENDIF ' %SETUPAPI_VER >= %WIN32_WINNT_WINXP
'#endif // _SETUPAPI_VER >= _WIN32_WINNT_WINXP

' //
' // Return values for SetupPromptForDisk, SetupCopyError,
' // SetupRenameError, SetupDeleteError, SetupBackupError
' //
%DPROMPT_SUCCESS        = 0
%DPROMPT_CANCEL         = 1
%DPROMPT_SKIPFILE       = 2
%DPROMPT_BUFFERTOOSMALL = 3
%DPROMPT_OUTOFMEMORY    = 4

DECLARE FUNCTION SetupSetDirectoryIdA IMPORT "SETUPAPI.DLL" ALIAS "SetupSetDirectoryIdA" ( _
   BYVAL InfHandle AS DWORD _                           ' __in HINF InfHandle
 , BYVAL Id AS DWORD _                                  ' __in DWORD Id
 , OPTIONAL BYREF Directory AS ASCIIZ _                 ' __in_opt PCSTR Directory
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SetupSetDirectoryIdW IMPORT "SETUPAPI.DLL" ALIAS "SetupSetDirectoryIdW" ( _
   BYVAL InfHandle AS DWORD _                           ' __in HINF InfHandle
 , BYVAL Id AS DWORD _                                  ' __in DWORD Id
 , OPTIONAL BYREF Directory AS WSTRINGZ _               ' __in_opt PCWSTR Directory
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO SetupSetDirectoryId = SetupSetDirectoryIdW
#ELSE
   MACRO SetupSetDirectoryId = SetupSetDirectoryIdA
#ENDIF

DECLARE FUNCTION SetupSetDirectoryIdExA IMPORT "SETUPAPI.DLL" ALIAS "SetupSetDirectoryIdExA" ( _
   BYVAL InfHandle AS DWORD _                           ' __in HINF InfHandle
 , BYVAL Id AS DWORD _                                  ' __in DWORD Id
 , BYREF Directory AS ASCIIZ _                          ' __in_opt PCSTR Directory
 , BYVAL Flags AS DWORD _                               ' __in DWORD Flags
 , BYVAL Reserved1 AS DWORD _                           ' __reserved DWORD Reserved1
 , BYVAL Reserved2 AS DWORD _                           ' __reserved PVOID Reserved2
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SetupSetDirectoryIdExW IMPORT "SETUPAPI.DLL" ALIAS "SetupSetDirectoryIdExW" ( _
   BYVAL InfHandle AS DWORD _                           ' __in HINF InfHandle
 , BYVAL Id AS DWORD _                                  ' __in DWORD Id
 , BYREF Directory AS WSTRINGZ _                        ' __in_opt PCWSTR Directory
 , BYVAL Flags AS DWORD _                               ' __in DWORD Flags
 , BYVAL Reserved1 AS DWORD _                           ' __reserved DWORD Reserved1
 , BYVAL Reserved2 AS DWORD _                           ' __reserved PVOID Reserved2
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO SetupSetDirectoryIdEx = SetupSetDirectoryIdExW
#ELSE
   MACRO SetupSetDirectoryIdEx = SetupSetDirectoryIdExA
#ENDIF

' //
' // Flags for SetupSetDirectoryIdEx
' //
%SETDIRID_NOT_FULL_PATH      = &H00000001???

DECLARE FUNCTION SetupGetSourceInfoA IMPORT "SETUPAPI.DLL" ALIAS "SetupGetSourceInfoA" ( _
   BYVAL InfHandle AS DWORD _                           ' __in HINF InfHandle
 , BYVAL SourceId AS DWORD _                            ' __in UINT SourceId
 , BYVAL InfoDesired AS DWORD _                         ' __in UINT InfoDesired
 , BYREF ReturnBuffer AS ASCIIZ _                       ' __out PSTR ReturnBuffer
 , BYVAL ReturnBufferSize AS DWORD _                    ' __in DWORD ReturnBufferSize
 , OPTIONAL BYREF RequiredSize AS DWORD _               ' __out_opt PDWORD RequiredSize
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SetupGetSourceInfoW IMPORT "SETUPAPI.DLL" ALIAS "SetupGetSourceInfoW" ( _
   BYVAL InfHandle AS DWORD _                           ' __in HINF InfHandle
 , BYVAL SourceId AS DWORD _                            ' __in UINT SourceId
 , BYVAL InfoDesired AS DWORD _                         ' __in UINT InfoDesired
 , BYREF ReturnBuffer AS WSTRINGZ _                     ' __out PWSTR ReturnBuffer
 , BYVAL ReturnBufferSize AS DWORD _                    ' __in DWORD ReturnBufferSize
 , OPTIONAL BYREF RequiredSize AS DWORD _               ' __out_opt PDWORD RequiredSize
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO SetupGetSourceInfo = SetupGetSourceInfoW
#ELSE
   MACRO SetupGetSourceInfo = SetupGetSourceInfoA
#ENDIF

' //
' // InfoDesired values for SetupGetSourceInfo
' //

%SRCINFO_PATH           = 1
%SRCINFO_TAGFILE        = 2
%SRCINFO_DESCRIPTION    = 3
%SRCINFO_FLAGS          = 4

'#if _SETUPAPI_VER >= _WIN32_WINNT_WINXP
#IF %SETUPAPI_VER >= %WIN32_WINNT_WINXP
' //
' // SRC_FLAGS allow special treatment of source
' // lower 4 bits are reserved for OS use
' // the flags may determine what other parameters exist
' //
%SRCINFO_TAGFILE2       = 5  ' // alternate tagfile, when SRCINFO_TAGFILE is a cabfile

%SRC_FLAGS_CABFILE      = &H0010 ' // if set, treat SRCINFO_TAGFILE as a cabfile and specify alternate tagfile

'#endif // _SETUPAPI_VER >= _WIN32_WINNT_WINXP
#ENDIF ' %SETUPAPI_VER >= %WIN32_WINNT_WINXP

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SetupInstallFileA LIB "SetupApi.dll" _
    ALIAS "SetupInstallFileA" ( _
    BYVAL InfHandle AS DWORD, _
    InfContext AS INFCONTEXT, _
    SourceFile AS ASCIIZ, _
    SourcePathRoot AS ASCIIZ, _
    DestinationName AS ASCIIZ, _
    BYVAL CopyStyle AS DWORD, _
    BYVAL CopyMsgHandler AS DWORD, _  ' PSP_FILE_CALLBACK_A
    Context AS ANY _
    ) AS LONG  ' BOOOL
#ELSE
DECLARE FUNCTION SetupInstallFileA IMPORT "SETUPAPI.DLL" ALIAS "SetupInstallFileA" ( _
   BYVAL InfHandle AS DWORD _                           ' __in_opt HINF InfHandle
 , BYREF InfContext AS INFCONTEXT _                     ' __in_opt PINFCONTEXT InfContext
 , BYREF SourceFile AS ASCIIZ _                         ' __in_opt PCSTR SourceFile
 , BYREF SourcePathRoot AS ASCIIZ _                     ' __in_opt PCSTR SourcePathRoot
 , BYREF DestinationName AS ASCIIZ _                    ' __in_opt PCSTR DestinationName
 , BYVAL CopyStyle AS DWORD _                           ' __in DWORD CopyStyle
 , OPTIONAL BYVAL CopyMsgHandler AS DWORD _             ' __in_opt PSP_FILE_CALLBACK_A CopyMsgHandler
 , OPTIONAL BYVAL Context AS DWORD _                    ' __in_opt PVOID Context
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SetupInstallFileW LIB "SetupApi.dll" _
    ALIAS "SetupInstallFileW" ( _
    BYVAL InfHandle AS DWORD, _
    InfContext AS INFCONTEXT, _
    SourceFile AS WSTRINGZ, _
    SourcePathRoot AS WSTRINGZ, _
    DestinationName AS WSTRINGZ, _
    BYVAL CopyStyle AS DWORD, _
    BYVAL CopyMsgHandler AS DWORD, _  ' PSP_FILE_CALLBACK_W
    Context AS ANY _
    ) AS LONG   ' BOOL
#ELSE
DECLARE FUNCTION SetupInstallFileW IMPORT "SETUPAPI.DLL" ALIAS "SetupInstallFileW" ( _
   BYVAL InfHandle AS DWORD _                           ' __in_opt HINF InfHandle
 , BYREF InfContext AS INFCONTEXT _                     ' __in_opt PINFCONTEXT InfContext
 , BYREF SourceFile AS WSTRINGZ _                       ' __in_opt PCWSTR SourceFile
 , BYREF SourcePathRoot AS WSTRINGZ _                   ' __in_opt PCWSTR SourcePathRoot
 , BYREF DestinationName AS WSTRINGZ _                  ' __in_opt PCWSTR DestinationName
 , BYVAL CopyStyle AS DWORD _                           ' __in DWORD CopyStyle
 , OPTIONAL BYVAL CopyMsgHandler AS DWORD _             ' __in_opt PSP_FILE_CALLBACK_W CopyMsgHandler
 , OPTIONAL BYVAL Context AS DWORD _                    ' __in_opt PVOID Context
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%UNICODE)
   MACRO SetupInstallFile = SetupInstallFileW
#ELSE
   MACRO SetupInstallFile = SetupInstallFileA
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SetupInstallFileExA LIB "SetupApi.dll" _
    ALIAS "SetupInstallFileExA" ( _
    BYVAL InfHandle AS DWORD, _
    InfContext AS INFCONTEXT, _
    SourceFile AS ASCIIZ, _
    SourcePathRoot AS ASCIIZ, _
    DestinationName AS ASCIIZ, _
    BYVAL CopyStyle AS DWORD, _
    BYVAL CopyMsgHandler AS DWORD, _  ' PSP_FILE_CALLBACK_A
    Context AS ANY, _
    FileWasInUse AS LONG _  ' PBOOL
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupInstallFileExA IMPORT "SETUPAPI.DLL" ALIAS "SetupInstallFileExA" ( _
   BYVAL InfHandle AS DWORD _                           ' __in_opt HINF InfHandle
 , BYREF InfContext AS INFCONTEXT _                     ' __in_opt PINFCONTEXT InfContext
 , BYREF SourceFile AS ASCIIZ _                         ' __in_opt PCSTR SourceFile
 , BYREF SourcePathRoot AS ASCIIZ _                     ' __in_opt PCSTR SourcePathRoot
 , BYREF DestinationName AS ASCIIZ _                    ' __in_opt PCSTR DestinationName
 , BYVAL CopyStyle AS DWORD _                           ' __in DWORD CopyStyle
 , BYVAL CopyMsgHandler AS DWORD _                      ' __in_opt PSP_FILE_CALLBACK_A CopyMsgHandler
 , BYVAL Context AS DWORD _                             ' __in_opt PVOID Context
 , BYREF FileWasInUse AS LONG _                         ' __out PBOOL FileWasInUse
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SetupInstallFileExW LIB "SetupApi.dll" _
    ALIAS "SetupInstallFileExW" ( _
    BYVAL InfHandle AS DWORD, _
    InfContext AS INFCONTEXT, _
    SourceFile AS WSTRINGZ, _
    SourcePathRoot AS WSTRINGZ, _
    DestinationName AS WSTRINGZ, _
    BYVAL CopyStyle AS DWORD, _
    BYVAL CopyMsgHandler AS DWORD, _   ' PSP_FILE_CALLBACK_W
    Context AS ANY, _
    FileWasInUse AS LONG _  ' PBOOL
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupInstallFileExW IMPORT "SETUPAPI.DLL" ALIAS "SetupInstallFileExW" ( _
   BYVAL InfHandle AS DWORD _                           ' __in_opt HINF InfHandle
 , BYREF InfContext AS INFCONTEXT _                     ' __in_opt PINFCONTEXT InfContext
 , BYREF SourceFile AS WSTRINGZ _                       ' __in_opt PCWSTR SourceFile
 , BYREF SourcePathRoot AS WSTRINGZ _                   ' __in_opt PCWSTR SourcePathRoot
 , BYREF DestinationName AS WSTRINGZ _                  ' __in_opt PCWSTR DestinationName
 , BYVAL CopyStyle AS DWORD _                           ' __in DWORD CopyStyle
 , BYVAL CopyMsgHandler AS DWORD _                      ' __in_opt PSP_FILE_CALLBACK_W CopyMsgHandler
 , BYVAL Context AS DWORD _                             ' __in_opt PVOID Context
 , BYREF FileWasInUse AS LONG _                         ' __out PBOOL FileWasInUse
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%UNICODE)
   MACRO SetupInstallFileEx = SetupInstallFileExW
#ELSE
   MACRO SetupInstallFileEx = SetupInstallFileExA
#ENDIF

' //
' // CopyStyle values for copy and queue-related APIs
' //
%SP_COPY_DELETESOURCE        = &H0000001???   ' // delete source file on successful copy
%SP_COPY_REPLACEONLY         = &H0000002???   ' // copy only if target file already present
%SP_COPY_NEWER               = &H0000004???   ' // copy only if source newer than or same as target
%SP_COPY_NEWER_OR_SAME       = %SP_COPY_NEWER
%SP_COPY_NOOVERWRITE         = &H0000008???   ' // copy only if target doesn't exist
%SP_COPY_NODECOMP            = &H0000010???   ' // don't decompress source file while copying
%SP_COPY_LANGUAGEAWARE       = &H0000020???   ' // don't overwrite file of different language
%SP_COPY_SOURCE_ABSOLUTE     = &H0000040???   ' // SourceFile is a full source path
%SP_COPY_SOURCEPATH_ABSOLUTE = &H0000080???   ' // SourcePathRoot is the full path
%SP_COPY_IN_USE_NEEDS_REBOOT = &H0000100???   ' // System needs reboot if file in use
%SP_COPY_FORCE_IN_USE        = &H0000200???   ' // Force target-in-use behavior
%SP_COPY_NOSKIP              = &H0000400???   ' // Skip is disallowed for this file or section
%SP_FLAG_CABINETCONTINUATION = &H0000800???   ' // Used with need media notification
%SP_COPY_FORCE_NOOVERWRITE   = &H0001000???   ' // like NOOVERWRITE but no callback nofitication
%SP_COPY_FORCE_NEWER         = &H0002000???   ' // like NEWER but no callback nofitication
%SP_COPY_WARNIFSKIP          = &H0004000???   ' // system critical file: warn if user tries to skip
%SP_COPY_NOBROWSE            = &H0008000???   ' // Browsing is disallowed for this file or section
%SP_COPY_NEWER_ONLY          = &H0010000???   ' // copy only if source file newer than target
'%SP_COPY_SOURCE_SIS_MASTER   = &H0020000???   ' // source is single-instance store master
%SP_COPY_RESERVED            = &H0020000???   ' // was: SP_COPY_SOURCE_SIS_MASTER (deprecated)
%SP_COPY_OEMINF_CATALOG_ONLY = &H0040000???   ' // (SetupCopyOEMInf only) don't copy INF--just catalog
%SP_COPY_REPLACE_BOOT_FILE   = &H0080000???   ' // file must be present upon reboot (i.e., it's
                                              ' // needed by the loader); this flag implies a reboot
%SP_COPY_NOPRUNE             = &H0100000???   ' // never prune this file

'#if _SETUPAPI_VER >= _WIN32_WINNT_WINXP
#IF %SETUPAPI_VER >= %WIN32_WINNT_WINXP
%SP_COPY_OEM_F6_INF          = &H0200000???   ' // Used when calling SetupCopyOemInf
#ENDIF
'#endif //_SETUPAPI_VER >= _WIN32_WINNT_WINXP

'#if _SETUPAPI_VER >= _WIN32_WINNT_WINXP
#IF %SETUPAPI_VER >= %WIN32_WINNT_WINXP
%SP_COPY_ALREADYDECOMP       = &H0400000???   ' // similar to SP_COPY_NODECOMP
#ENDIF
'#endif //_SETUPAPI_VER >= _WIN32_WINNT_WINXP

'#if _SETUPAPI_VER >= _WIN32_WINNT_LONGHORN
#IF %SETUPAPI_VER >= %WIN32_WINNT_LONGHORN
%SP_COPY_WINDOWS_SIGNED      = &H1000000???   ' // BuildLab or WinSE signed
%SP_COPY_PNPLOCKED           = &H2000000???   ' // Used with the signature flag
%SP_COPY_IN_USE_TRY_RENAME   = &H4000000???   ' // If file in use, try to rename the target first
%SP_COPY_INBOX_INF           = &H8000000???   ' // Referred by CopyFiles of inbox inf
#ENDIF '%SETUPAPI_VER >= %WIN32_WINNT_LONGHORN
'#endif //_SETUPAPI_VER >= _WIN32_WINNT_LONGHORN

'#if _SETUPAPI_VER >= _WIN32_WINNT_WIN7
#IF %SETUPAPI_VER >= %WIN32_WINNT_WIN7
%SP_COPY_HARDLINK            = &H10000000???  ' // Copy using hardlink, if possible
#ENDIF
'#endif

'#if _SETUPAPI_VER >= _WIN32_WINNT_WINXP
#IF %SETUPAPI_VER >= %WIN32_WINNT_WINXP

' //
' // Flags passed to Backup notification
' //
%SP_BACKUP_BACKUPPASS        = &H00000001???  ' // file backed up during backup pass
%SP_BACKUP_DEMANDPASS        = &H00000002???  ' // file backed up on demand
%SP_BACKUP_SPECIAL           = &H00000004???  ' // if set, special type of backup
%SP_BACKUP_BOOTFILE          = &H00000008???  ' // file marked with COPYFLG_REPLACE_BOOT_FILE

#ENDIF
'#endif //_SETUPAPI_VER >= _WIN32_WINNT_WINXP

DECLARE FUNCTION SetupOpenFileQueue IMPORT "SETUPAPI.DLL" ALIAS "SetupOpenFileQueue" ( _
 ) AS DWORD                                             ' HSPFILEQ

DECLARE FUNCTION SetupCloseFileQueue IMPORT "SETUPAPI.DLL" ALIAS "SetupCloseFileQueue" ( _
   BYVAL QueueHandle AS DWORD _                         ' __in HSPFILEQ QueueHandle
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SetupSetFileQueueAlternatePlatformA IMPORT "SETUPAPI.DLL" ALIAS "SetupSetFileQueueAlternatePlatformA" ( _
   BYVAL QueueHandle AS DWORD _                         ' __in HSPFILEQ QueueHandle
 , OPTIONAL BYREF AlternatePlatformInfo AS SP_ALTPLATFORM_INFO _ ' __in_opt PSP_ALTPLATFORM_INFO AlternatePlatformInfo
 , OPTIONAL BYREF AlternateDefaultCatalogFile AS ASCIIZ _        ' __in_opt PCSTR AlternateDefaultCatalogFile
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SetupSetFileQueueAlternatePlatformW IMPORT "SETUPAPI.DLL" ALIAS "SetupSetFileQueueAlternatePlatformW" ( _
   BYVAL QueueHandle AS DWORD _                         ' __in HSPFILEQ QueueHandle
 , OPTIONAL BYREF AlternatePlatformInfo AS SP_ALTPLATFORM_INFO _ ' __in_opt PSP_ALTPLATFORM_INFO AlternatePlatformInfo
 , OPTIONAL BYREF AlternateDefaultCatalogFile AS WSTRINGZ _      ' __in_opt PCWSTR AlternateDefaultCatalogFile
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO SetupSetFileQueueAlternatePlatform = SetupSetFileQueueAlternatePlatformW
#ELSE
   MACRO SetupSetFileQueueAlternatePlatform = SetupSetFileQueueAlternatePlatformA
#ENDIF

DECLARE FUNCTION SetupSetPlatformPathOverrideA IMPORT "SETUPAPI.DLL" ALIAS "SetupSetPlatformPathOverrideA" ( _
   OPTIONAL BYREF Override AS ASCIIZ _                  ' __in_opt PCSTR Override
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SetupSetPlatformPathOverrideW IMPORT "SETUPAPI.DLL" ALIAS "SetupSetPlatformPathOverrideW" ( _
   OPTIONAL BYREF Override AS WSTRINGZ _                ' __in_opt PCWSTR Override
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO SetupSetPlatformPathOverride = SetupSetPlatformPathOverrideW
#ELSE
   MACRO SetupSetPlatformPathOverride = SetupSetPlatformPathOverrideA
#ENDIF

DECLARE FUNCTION SetupQueueCopyA IMPORT "SETUPAPI.DLL" ALIAS "SetupQueueCopyA" ( _
   BYVAL QueueHandle AS DWORD _                         ' __in HSPFILEQ QueueHandle
 , BYREF SourceRootPath AS ASCIIZ _                     ' __in_opt PCSTR SourceRootPath
 , BYREF SourcePath AS ASCIIZ _                         ' __in_opt PCSTR SourcePath
 , BYREF SourceFilename AS ASCIIZ _                     ' __in PCSTR SourceFilename
 , BYREF SourceDescription AS ASCIIZ _                  ' __in_opt PCSTR SourceDescription
 , BYREF SourceTagfile AS ASCIIZ _                      ' __in_opt PCSTR SourceTagfile
 , BYREF TargetDirectory AS ASCIIZ _                    ' __in PCSTR TargetDirectory
 , BYREF TargetFilename AS ASCIIZ _                     ' __in_opt PCSTR TargetFilename
 , BYVAL CopyStyle AS DWORD _                           ' __in DWORD CopyStyle
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SetupQueueCopyW IMPORT "SETUPAPI.DLL" ALIAS "SetupQueueCopyW" ( _
   BYVAL QueueHandle AS DWORD _                         ' __in HSPFILEQ QueueHandle
 , BYREF SourceRootPath AS WSTRINGZ _                   ' __in_opt PCWSTR SourceRootPath
 , BYREF SourcePath AS WSTRINGZ _                       ' __in_opt PCWSTR SourcePath
 , BYREF SourceFilename AS WSTRINGZ _                   ' __in PCWSTR SourceFilename
 , BYREF SourceDescription AS WSTRINGZ _                ' __in_opt PCWSTR SourceDescription
 , BYREF SourceTagfile AS WSTRINGZ _                    ' __in_opt PCWSTR SourceTagfile
 , BYREF TargetDirectory AS WSTRINGZ _                  ' __in PCWSTR TargetDirectory
 , BYREF TargetFilename AS WSTRINGZ _                   ' __in_opt PCWSTR TargetFilename
 , BYVAL CopyStyle AS DWORD _                           ' __in DWORD CopyStyle
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO SetupQueueCopy = SetupQueueCopyW
#ELSE
   MACRO SetupQueueCopy = SetupQueueCopyA
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SetupQueueCopyIndirectA LIB "SetupApi.dll" _
    ALIAS "SetupQueueCopyIndirectA" ( _
    BYVAL CopyParams AS SP_FILE_COPY_PARAMS_A PTR _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupQueueCopyIndirectA IMPORT "SETUPAPI.DLL" ALIAS "SetupQueueCopyIndirectA" ( _
   BYREF CopyParams AS SP_FILE_COPY_PARAMS_A _          ' __in PSP_FILE_COPY_PARAMS_A CopyParams
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SetupQueueCopyIndirectW LIB "SetupApi.dll" _
    ALIAS "SetupQueueCopyIndirectW" ( _
    BYVAL CopyParams AS SP_FILE_COPY_PARAMS_W PTR _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupQueueCopyIndirectW IMPORT "SETUPAPI.DLL" ALIAS "SetupQueueCopyIndirectW" ( _
   BYREF CopyParams AS SP_FILE_COPY_PARAMS_W _          ' __in PSP_FILE_COPY_PARAMS_W CopyParams
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%UNICODE)
   MACRO SetupQueueCopyIndirect = SetupQueueCopyIndirectW
#ELSE
   MACRO SetupQueueCopyIndirect = SetupQueueCopyIndirectA
#ENDIF

DECLARE FUNCTION SetupQueueDefaultCopyA IMPORT "SETUPAPI.DLL" ALIAS "SetupQueueDefaultCopyA" ( _
   BYVAL QueueHandle AS DWORD _                         ' __in HSPFILEQ QueueHandle
 , BYVAL InfHandle AS DWORD _                           ' __in HINF InfHandle
 , BYREF SourceRootPath AS ASCIIZ _                     ' __in PCSTR SourceRootPath
 , BYREF SourceFilename AS ASCIIZ _                     ' __in PCSTR SourceFilename
 , BYREF TargetFilename AS ASCIIZ _                     ' __in PCSTR TargetFilename
 , BYVAL CopyStyle AS DWORD _                           ' __in DWORD CopyStyle
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SetupQueueDefaultCopyW IMPORT "SETUPAPI.DLL" ALIAS "SetupQueueDefaultCopyW" ( _
   BYVAL QueueHandle AS DWORD _                         ' __in HSPFILEQ QueueHandle
 , BYVAL InfHandle AS DWORD _                           ' __in HINF InfHandle
 , BYREF SourceRootPath AS WSTRINGZ _                   ' __in PCWSTR SourceRootPath
 , BYREF SourceFilename AS WSTRINGZ _                   ' __in PCWSTR SourceFilename
 , BYREF TargetFilename AS WSTRINGZ _                   ' __in PCWSTR TargetFilename
 , BYVAL CopyStyle AS DWORD _                           ' __in DWORD CopyStyle
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO SetupQueueDefaultCopy = SetupQueueDefaultCopyW
#ELSE
   MACRO SetupQueueDefaultCopy = SetupQueueDefaultCopyA
#ENDIF

DECLARE FUNCTION SetupQueueCopySectionA IMPORT "SETUPAPI.DLL" ALIAS "SetupQueueCopySectionA" ( _
   BYVAL QueueHandle AS DWORD _                         ' __in HSPFILEQ QueueHandle
 , BYREF SourceRootPath AS ASCIIZ _                     ' __in PCSTR SourceRootPath
 , BYVAL InfHandle AS DWORD _                           ' __in HINF InfHandle
 , BYVAL ListInfHandle AS DWORD _                       ' __in_opt HINF ListInfHandle
 , BYREF Section AS ASCIIZ _                            ' __in PCSTR Section
 , BYVAL CopyStyle AS DWORD _                           ' __in DWORD CopyStyle
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SetupQueueCopySectionW IMPORT "SETUPAPI.DLL" ALIAS "SetupQueueCopySectionW" ( _
   BYVAL QueueHandle AS DWORD _                         ' __in HSPFILEQ QueueHandle
 , BYREF SourceRootPath AS WSTRINGZ _                   ' __in PCWSTR SourceRootPath
 , BYVAL InfHandle AS DWORD _                           ' __in HINF InfHandle
 , BYVAL ListInfHandle AS DWORD _                       ' __in_opt HINF ListInfHandle
 , BYREF Section AS WSTRINGZ _                          ' __in PCWSTR Section
 , BYVAL CopyStyle AS DWORD _                           ' __in DWORD CopyStyle
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO SetupQueueCopySection = SetupQueueCopySectionW
#ELSE
   MACRO SetupQueueCopySection = SetupQueueCopySectionA
#ENDIF

DECLARE FUNCTION SetupQueueDeleteA IMPORT "SETUPAPI.DLL" ALIAS "SetupQueueDeleteA" ( _
   BYVAL QueueHandle AS DWORD _                         ' __in HSPFILEQ QueueHandle
 , BYREF PathPart1 AS ASCIIZ _                          ' __in PCSTR PathPart1
 , OPTIONAL BYREF PathPart2 AS ASCIIZ _                          ' __in_opt PCSTR PathPart2
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SetupQueueDeleteW IMPORT "SETUPAPI.DLL" ALIAS "SetupQueueDeleteW" ( _
   BYVAL QueueHandle AS DWORD _                         ' __in HSPFILEQ QueueHandle
 , BYREF PathPart1 AS WSTRINGZ _                        ' __in PCWSTR PathPart1
 , OPTIONAL BYREF PathPart2 AS WSTRINGZ _               ' __in_opt PCWSTR PathPart2
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO SetupQueueDelete = SetupQueueDeleteW
#ELSE
   MACRO SetupQueueDelete = SetupQueueDeleteA
#ENDIF

DECLARE FUNCTION SetupQueueDeleteSectionA IMPORT "SETUPAPI.DLL" ALIAS "SetupQueueDeleteSectionA" ( _
   BYVAL QueueHandle AS DWORD _                         ' __in HSPFILEQ QueueHandle
 , BYVAL InfHandle AS DWORD _                           ' __in HINF InfHandle
 , BYVAL ListInfHandle AS DWORD _                       ' __in_opt HINF ListInfHandle
 , BYREF Section AS ASCIIZ _                            ' __in PCSTR Section
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SetupQueueDeleteSectionW IMPORT "SETUPAPI.DLL" ALIAS "SetupQueueDeleteSectionW" ( _
   BYVAL QueueHandle AS DWORD _                         ' __in HSPFILEQ QueueHandle
 , BYVAL InfHandle AS DWORD _                           ' __in HINF InfHandle
 , BYVAL ListInfHandle AS DWORD _                       ' __in_opt HINF ListInfHandle
 , BYREF Section AS WSTRINGZ _                             ' __in PCWSTR Section
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO SetupQueueDeleteSection = SetupQueueDeleteSectionW
#ELSE
   MACRO SetupQueueDeleteSection = SetupQueueDeleteSectionA
#ENDIF

DECLARE FUNCTION SetupQueueRenameA IMPORT "SETUPAPI.DLL" ALIAS "SetupQueueRenameA" ( _
   BYVAL QueueHandle AS DWORD _                         ' __in HSPFILEQ QueueHandle
 , BYREF SourcePath AS ASCIIZ _                         ' __in PCSTR SourcePath
 , BYREF SourceFilename AS ASCIIZ _                     ' __in_opt PCSTR SourceFilename
 , BYREF TargetPath AS ASCIIZ _                         ' __in_opt PCSTR TargetPath
 , BYREF TargetFilename AS ASCIIZ _                     ' __in PCSTR TargetFilename
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SetupQueueRenameW IMPORT "SETUPAPI.DLL" ALIAS "SetupQueueRenameW" ( _
   BYVAL QueueHandle AS DWORD _                         ' __in HSPFILEQ QueueHandle
 , BYREF SourcePath AS WSTRINGZ _                       ' __in PCWSTR SourcePath
 , BYREF SourceFilename AS WSTRINGZ _                   ' __in_opt PCWSTR SourceFilename
 , BYREF TargetPath AS WSTRINGZ _                       ' __in_opt PCWSTR TargetPath
 , BYREF TargetFilename AS WSTRINGZ _                   ' __in PCWSTR TargetFilename
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO SetupQueueRename = SetupQueueRenameW
#ELSE
   MACRO SetupQueueRename = SetupQueueRenameA
#ENDIF

DECLARE FUNCTION SetupQueueRenameSectionA IMPORT "SETUPAPI.DLL" ALIAS "SetupQueueRenameSectionA" ( _
   BYVAL QueueHandle AS DWORD _                         ' __in HSPFILEQ QueueHandle
 , BYVAL InfHandle AS DWORD _                           ' __in HINF InfHandle
 , BYVAL ListInfHandle AS DWORD _                       ' __in_opt HINF ListInfHandle
 , BYREF Section AS ASCIIZ _                            ' __in PCSTR Section
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SetupQueueRenameSectionW IMPORT "SETUPAPI.DLL" ALIAS "SetupQueueRenameSectionW" ( _
   BYVAL QueueHandle AS DWORD _                         ' __in HSPFILEQ QueueHandle
 , BYVAL InfHandle AS DWORD _                           ' __in HINF InfHandle
 , BYVAL ListInfHandle AS DWORD _                       ' __in_opt HINF ListInfHandle
 , BYREF Section AS WSTRINGZ _                          ' __in PCWSTR Section
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO SetupQueueRenameSection = SetupQueueRenameSectionW
#ELSE
   MACRO SetupQueueRenameSection = SetupQueueRenameSectionA
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SetupCommitFileQueueA LIB "SetupApi.dll" _
    ALIAS "SetupCommitFileQueueA" ( _
    BYVAL Owner AS DWORD, _  ' HWND
    BYVAL QueueHandle AS DWORD, _
    BYVAL MsgHandler AS DWORD, _   ' PSP_FILE_CALLBACK_A
    Context AS ANY _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupCommitFileQueueA IMPORT "SETUPAPI.DLL" ALIAS "SetupCommitFileQueueA" ( _
   BYVAL Owner AS DWORD _                               ' __in_opt HWND Owner
 , BYVAL QueueHandle AS DWORD _                         ' __in HSPFILEQ QueueHandle
 , BYVAL MsgHandler AS DWORD _                          ' __in PSP_FILE_CALLBACK_A MsgHandler
 , BYVAL Context AS DWORD _                             ' __in PVOID Context
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SetupCommitFileQueueW LIB "SetupApi.dll" _
    ALIAS "SetupCommitFileQueueW" ( _
    BYVAL Owner AS DWORD, _  ' HWND
    BYVAL QueueHandle AS DWORD, _
    BYVAL MsgHandler AS DWORD, _   ' PSP_FILE_CALLBACK_W
    Context AS ANY _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupCommitFileQueueW IMPORT "SETUPAPI.DLL" ALIAS "SetupCommitFileQueueW" ( _
   BYVAL Owner AS DWORD _                               ' __in_opt HWND Owner
 , BYVAL QueueHandle AS DWORD _                         ' __in HSPFILEQ QueueHandle
 , BYVAL MsgHandler AS DWORD _                          ' __in PSP_FILE_CALLBACK_W MsgHandler
 , BYVAL Context AS DWORD _                             ' __in PVOID Context
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%UNICODE)
   MACRO SetupCommitFileQueue = SetupCommitFileQueueW
#ELSE
   MACRO SetupCommitFileQueue = SetupCommitFileQueueA
#ENDIF

DECLARE FUNCTION SetupScanFileQueueA IMPORT "SETUPAPI.DLL" ALIAS "SetupScanFileQueueA" ( _
   BYVAL FileQueue AS DWORD _                           ' __in HSPFILEQ FileQueue
 , BYVAL Flags AS DWORD _                               ' __in DWORD Flags
 , BYVAL Window AS DWORD _                              ' __in_opt HWND Window
 , BYVAL CallbackRoutine AS DWORD _                     ' __in_opt PSP_FILE_CALLBACK_A CallbackRoutine
 , BYVAL CallbackContext AS DWORD _                     ' __in_opt PVOID CallbackContext
 , BYREF Result AS DWORD _                              ' __out PDWORD Result
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SetupScanFileQueueW IMPORT "SETUPAPI.DLL" ALIAS "SetupScanFileQueueW" ( _
   BYVAL FileQueue AS DWORD _                           ' __in HSPFILEQ FileQueue
 , BYVAL Flags AS DWORD _                               ' __in DWORD Flags
 , BYVAL Window AS DWORD _                              ' __in_opt HWND Window
 , BYVAL CallbackRoutine AS DWORD _                     ' __in_opt PSP_FILE_CALLBACK_W CallbackRoutine
 , BYVAL CallbackContext AS DWORD _                     ' __in_opt PVOID CallbackContext
 , BYREF Result AS DWORD _                              ' __out PDWORD Result
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO SetupScanFileQueue = SetupScanFileQueueW
#ELSE
   MACRO SetupScanFileQueue = SetupScanFileQueueA
#ENDIF

' //
' // Define flags for SetupScanFileQueue.
' //
%SPQ_SCAN_FILE_PRESENCE                  = &H00000001???
%SPQ_SCAN_FILE_VALIDITY                  = &H00000002???
%SPQ_SCAN_USE_CALLBACK                   = &H00000004???
%SPQ_SCAN_USE_CALLBACKEX                 = &H00000008???
%SPQ_SCAN_INFORM_USER                    = &H00000010???
%SPQ_SCAN_PRUNE_COPY_QUEUE               = &H00000020???

'#if _SETUPAPI_VER >= _WIN32_WINNT_WINXP
#IF %SETUPAPI_VER >= %WIN32_WINNT_WINXP
%SPQ_SCAN_USE_CALLBACK_SIGNERINFO        = &H00000040???
%SPQ_SCAN_PRUNE_DELREN                   = &H00000080??? ' // remote Delete/Rename queue
#ENDIF
'#endif // _SETUPAPI_VER >= _WIN32_WINNT_WINXP

'#if _SETUPAPI_VER >= _WIN32_WINNT_LONGHORN
#IF %SETUPAPI_VER >= %WIN32_WINNT_LONGHORN
%SPQ_SCAN_FILE_PRESENCE_WITHOUT_SOURCE   = &H00000100???
%SPQ_SCAN_FILE_COMPARISON                = &H00000200???
%SPQ_SCAN_ACTIVATE_DRP                   = &H00000400???
#ENDIF
'#endif // _SETUPAPI_VER >= _WIN32_WINNT_LONGHORN

' //
' // Define flags used with Param2 for SPFILENOTIFY_QUEUESCAN
' //
%SPQ_DELAYED_COPY                        = &H00000001???  ' // file was in use; registered for delayed copy

'#if _SETUPAPI_VER >= _WIN32_WINNT_WINXP
#IF %SETUPAPI_VER >= %WIN32_WINNT_WINXP

DECLARE FUNCTION SetupGetFileQueueCount IMPORT "SETUPAPI.DLL" ALIAS "SetupGetFileQueueCount" ( _
   BYVAL FileQueue AS DWORD _                           ' __in HSPFILEQ FileQueue
 , BYVAL SubQueueFileOp AS DWORD _                      ' __in UINT SubQueueFileOp
 , BYREF NumOperations AS DWORD _                       ' __out PUINT NumOperations
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SetupGetFileQueueFlags IMPORT "SETUPAPI.DLL" ALIAS "SetupGetFileQueueFlags" ( _
   BYVAL FileQueue AS DWORD _                           ' __in HSPFILEQ FileQueue
 , BYREF Flags AS DWORD _                               ' __out PDWORD Flags
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SetupSetFileQueueFlags IMPORT "SETUPAPI.DLL" ALIAS "SetupSetFileQueueFlags" ( _
   BYVAL FileQueue AS DWORD _                           ' __in HSPFILEQ FileQueue
 , BYVAL FlagMask AS DWORD _                            ' __in DWORD FlagMask
 , BYVAL Flags AS DWORD _                               ' __in DWORD Flags
 ) AS LONG                                              ' BOOL

' //
' // Flags/FlagMask for use with SetupSetFileQueueFlags and returned by SetupGetFileQueueFlags
' //
%SPQ_FLAG_BACKUP_AWARE      = &H00000001???  ' // If set, SetupCommitFileQueue will
                                             ' // issue backup notifications.

%SPQ_FLAG_ABORT_IF_UNSIGNED = &H00000002???  ' // If set, SetupCommitFileQueue will
                                             ' // fail with ERROR_SET_SYSTEM_RESTORE_POINT
                                             ' // if the user elects to proceed with an
                                             ' // unsigned queue committal.  This allows
                                             ' // the caller to set a system restore point,
                                             ' // then re-commit the file queue.

%SPQ_FLAG_FILES_MODIFIED    = &H00000004???  ' // If set, at least one file was
                                             ' // replaced by a different version

%SPQ_FLAG_DO_SHUFFLEMOVE    = &H00000008???  ' // If set then always do a shuffle move. A shuffle
                                             ' // move will first try to copy the source over the
                                             ' // destination file, but if the destination file is
                                             ' // in use it will rename the destination file to a
                                             ' // temp name and queue the temp name for deletion.
                                             ' // It will then be free to copy the source to the
                                             ' // destination name.  It is considered an error if
                                             ' // the destination file can't be renamed for some
                                             ' // reason.

'%SPQ_FLAG_VALID             = &H00000007???  ' Windows XP SDK // mask of valid flags (can be passed as FlagMask)
%SPQ_FLAG_VALID             = &H0000000F???  ' Windows Vista SDK // mask of valid flags (can be passed as FlagMask)

#ENDIF
'#endif  // _SETUPAPI_VER >= _WIN32_WINNT_WINXP

' //
' // Define OEM Source Type values for use in SetupCopyOEMInf.
' //
%SPOST_NONE = 0
%SPOST_PATH = 1
%SPOST_URL  = 2
%SPOST_MAX  = 3

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SetupCopyOEMInfA LIB "SetupApi.dll" _
    ALIAS "SetupCopyOEMInfA" ( _
    SourceInfFileName AS ASCIIZ, _
    OEMSourceMediaLocation AS ASCIIZ, _
    BYVAL OEMSourceMediaType AS DWORD, _
    BYVAL CopyStyle AS DWORD, _
    DestinationInfFileName AS ASCIIZ, _
    BYVAL DestinationInfFileNameSize AS DWORD, _
    RequiredSize AS DWORD, _
    BYVAL DestinationInfFileNameComponent AS DWORD _  ' PSTR *
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupCopyOEMInfA IMPORT "SETUPAPI.DLL" ALIAS "SetupCopyOEMInfA" ( _
   BYREF SourceInfFileName AS ASCIIZ _                  ' __in PCSTR SourceInfFileName
 , BYREF OEMSourceMediaLocation AS ASCIIZ _             ' __in_opt PCSTR OEMSourceMediaLocation
 , BYVAL OEMSourceMediaType AS DWORD _                  ' __in DWORD OEMSourceMediaType
 , BYVAL CopyStyle AS DWORD _                           ' __in DWORD CopyStyle
 , BYREF DestinationInfFileName AS ASCIIZ _             ' __out PSTR DestinationInfFileName
 , BYVAL DestinationInfFileNameSize AS DWORD _          ' __in DWORD DestinationInfFileNameSize
 , OPTIONAL BYREF RequiredSize AS DWORD _               ' __out_opt PDWORD RequiredSize
 , OPTIONAL BYREF DestinationInfFileNameComponent AS DWORD _ ' __out_opt PSTR *DestinationInfFileNameComponent
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SetupCopyOEMInfW LIB "SetupApi.dll" _
    ALIAS "SetupCopyOEMInfW" ( _
    SourceInfFileName AS WSTRINGZ, _
    OEMSourceMediaLocation AS WSTRINGZ, _
    BYVAL OEMSourceMediaType AS DWORD, _
    BYVAL CopyStyle AS DWORD, _
    DestinationInfFileName AS WSTRINGZ, _
    BYVAL DestinationInfFileNameSize AS DWORD, _
    RequiredSize AS DWORD, _
    BYVAL DestinationInfFileNameComponent AS DWORD _  ' PWSTR *
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupCopyOEMInfW IMPORT "SETUPAPI.DLL" ALIAS "SetupCopyOEMInfW" ( _
   BYREF SourceInfFileName AS WSTRINGZ _                ' __in PCWSTR SourceInfFileName
 , BYREF OEMSourceMediaLocation AS WSTRINGZ _           ' __in_opt PCWSTR OEMSourceMediaLocation
 , BYVAL OEMSourceMediaType AS DWORD _                  ' __in DWORD OEMSourceMediaType
 , BYVAL CopyStyle AS DWORD _                           ' __in DWORD CopyStyle
 , BYREF DestinationInfFileName AS WSTRINGZ _           ' __out PWSTR DestinationInfFileName
 , BYVAL DestinationInfFileNameSize AS DWORD _          ' __in DWORD DestinationInfFileNameSize
 , OPTIONAL BYREF RequiredSize AS DWORD _               ' __out_opt PDWORD RequiredSize
 , OPTIONAL BYREF DestinationInfFileNameComponent AS DWORD _ ' __out_opt PWSTR *DestinationInfFileNameComponent
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%UNICODE)
   MACRO SetupCopyOEMInf = SetupCopyOEMInfW
#ELSE
   MACRO SetupCopyOEMInf = SetupCopyOEMInfA
#ENDIF

'#if _SETUPAPI_VER >= _WIN32_WINNT_WINXP
#IF %SETUPAPI_VER >= %WIN32_WINNT_WINXP

' //
' // Flags used by SetupUninstallOEMInf
' //
%SUOI_FORCEDELETE   = &H00000001???

#ENDIF
'#endif // _SETUPAPI_VER >= _WIN32_WINNT_WINXP

'#if _SETUPAPI_VER >= _WIN32_WINNT_LONGHORN
#IF %SETUPAPI_VER >= %WIN32_WINNT_LONGHORN
%SUOI_INTERNAL1     = &H00000002???
#ENDIF
'#endif // _SETUPAPI_VER >= _WIN32_WINNT_LONGHORN

'#if _SETUPAPI_VER >= _WIN32_WINNT_WINXP
#IF %SETUPAPI_VER >= %WIN32_WINNT_WINXP

DECLARE FUNCTION SetupUninstallOEMInfA IMPORT "SETUPAPI.DLL" ALIAS "SetupUninstallOEMInfA" ( _
   BYREF InfFileName AS ASCIIZ _                        ' __in PCSTR InfFileName
 , BYVAL Flags AS DWORD _                               ' __in DWORD Flags
 , BYVAL Reserved AS DWORD _                            ' __reserved PVOID Reserved
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SetupUninstallOEMInfW IMPORT "SETUPAPI.DLL" ALIAS "SetupUninstallOEMInfW" ( _
   BYREF InfFileName AS WSTRINGZ _                      ' __in PCWSTR InfFileName
 , BYVAL Flags AS DWORD _                               ' __in DWORD Flags
 , BYVAL Reserved AS DWORD _                            ' __reserved PVOID Reserved
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO SetupUninstallOEMInf = SetupUninstallOEMInfW
#ELSE
   MACRO SetupUninstallOEMInf = SetupUninstallOEMInfA
#ENDIF

DECLARE FUNCTION SetupUninstallNewlyCopiedInfs IMPORT "SETUPAPI.DLL" ALIAS "SetupUninstallNewlyCopiedInfs" ( _
   BYVAL FileQueue AS DWORD _                           ' __in HSPFILEQ FileQueue
 , BYVAL Flags AS DWORD _                               ' __in DWORD Flags
 , BYVAL Reserved AS DWORD _                            ' __reserved PVOID Reserved
 ) AS LONG                                              ' BOOL

#ENDIF
'#endif // _SETUPAPI_VER >= _WIN32_WINNT_WINXP


' //
' // Disk space list APIs
' //

DECLARE FUNCTION SetupCreateDiskSpaceListA IMPORT "SETUPAPI.DLL" ALIAS "SetupCreateDiskSpaceListA" ( _
   BYVAL Reserved1 AS DWORD _                           ' __reserved PVOID Reserved1
 , BYVAL Reserved2 AS DWORD _                           ' __reserved DWORD Reserved2
 , BYVAL Flags AS DWORD _                               ' __in UINT Flags
 ) AS DWORD                                             ' HDSKSPC

DECLARE FUNCTION SetupCreateDiskSpaceListW IMPORT "SETUPAPI.DLL" ALIAS "SetupCreateDiskSpaceListW" ( _
   BYVAL Reserved1 AS DWORD _                           ' __reserved PVOID Reserved1
 , BYVAL Reserved2 AS DWORD _                           ' __reserved DWORD Reserved2
 , BYVAL Flags AS DWORD _                               ' __in UINT Flags
 ) AS DWORD                                             ' HDSKSPC

#IF %DEF(%UNICODE)
   MACRO SetupCreateDiskSpaceList = SetupCreateDiskSpaceListW
#ELSE
   MACRO SetupCreateDiskSpaceList = SetupCreateDiskSpaceListA
#ENDIF

' //
' // Flags for SetupCreateDiskSpaceList
' //
%SPDSL_IGNORE_DISK              = &H00000001???  ' // ignore deletes and on-disk files in copies
%SPDSL_DISALLOW_NEGATIVE_ADJUST = &H00000002???

DECLARE FUNCTION SetupDuplicateDiskSpaceListA IMPORT "SETUPAPI.DLL" ALIAS "SetupDuplicateDiskSpaceListA" ( _
   BYVAL DiskSpace AS DWORD _                           ' __in HDSKSPC DiskSpace
 , BYVAL Reserved1 AS DWORD _                           ' __reserved PVOID Reserved1
 , BYVAL Reserved2 AS DWORD _                           ' __reserved DWORD Reserved2
 , BYVAL Flags AS DWORD _                               ' __in UINT Flags
 ) AS DWORD                                             ' HDSKSPC

DECLARE FUNCTION SetupDuplicateDiskSpaceListW IMPORT "SETUPAPI.DLL" ALIAS "SetupDuplicateDiskSpaceListW" ( _
   BYVAL DiskSpace AS DWORD _                           ' __in HDSKSPC DiskSpace
 , BYVAL Reserved1 AS DWORD _                           ' __reserved PVOID Reserved1
 , BYVAL Reserved2 AS DWORD _                           ' __reserved DWORD Reserved2
 , BYVAL Flags AS DWORD _                               ' __in UINT Flags
 ) AS DWORD                                             ' HDSKSPC

#IF %DEF(%UNICODE)
   MACRO SetupDuplicateDiskSpaceList = SetupDuplicateDiskSpaceListW
#ELSE
   MACRO SetupDuplicateDiskSpaceList = SetupDuplicateDiskSpaceListA
#ENDIF

DECLARE FUNCTION SetupDestroyDiskSpaceList IMPORT "SETUPAPI.DLL" ALIAS "SetupDestroyDiskSpaceList" ( _
   BYVAL DiskSpace AS DWORD _                           ' __in HDSKSPC DiskSpace
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SetupQueryDrivesInDiskSpaceListA IMPORT "SETUPAPI.DLL" ALIAS "SetupQueryDrivesInDiskSpaceListA" ( _
   BYVAL DiskSpace AS DWORD _                           ' __in HDSKSPC DiskSpace
 , BYREF ReturnBuffer AS ASCIIZ _                       ' __out PSTR ReturnBuffer
 , BYVAL ReturnBufferSize AS DWORD _                    ' __in DWORD ReturnBufferSize
 , OPTIONAL BYREF RequiredSize AS DWORD _               ' __out_opt PDWORD RequiredSize
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SetupQueryDrivesInDiskSpaceListW IMPORT "SETUPAPI.DLL" ALIAS "SetupQueryDrivesInDiskSpaceListW" ( _
   BYVAL DiskSpace AS DWORD _                           ' __in HDSKSPC DiskSpace
 , BYREF ReturnBuffer AS WSTRINGZ _                     ' __out PWSTR ReturnBuffer
 , BYVAL ReturnBufferSize AS DWORD _                    ' __in DWORD ReturnBufferSize
 , OPTIONAL BYREF RequiredSize AS DWORD _               ' __out_opt PDWORD RequiredSize
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO SetupQueryDrivesInDiskSpaceList = SetupQueryDrivesInDiskSpaceListW
#ELSE
   MACRO SetupQueryDrivesInDiskSpaceList = SetupQueryDrivesInDiskSpaceListA
#ENDIF

DECLARE FUNCTION SetupQuerySpaceRequiredOnDriveA IMPORT "SETUPAPI.DLL" ALIAS "SetupQuerySpaceRequiredOnDriveA" ( _
   BYVAL DiskSpace AS DWORD _                           ' __in HDSKSPC DiskSpace
 , BYREF DriveSpec AS ASCIIZ _                          ' __in PCSTR DriveSpec
 , BYREF SpaceRequired AS QUAD _                        ' __out LONGLONG *SpaceRequired
 , BYVAL Reserved1 AS DWORD _                           ' __reserved PVOID Reserved1
 , BYVAL Reserved2 AS DWORD _                           ' __reserved UINT Reserved2
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SetupQuerySpaceRequiredOnDriveW IMPORT "SETUPAPI.DLL" ALIAS "SetupQuerySpaceRequiredOnDriveW" ( _
   BYVAL DiskSpace AS DWORD _                           ' __in HDSKSPC DiskSpace
 , BYREF DriveSpec AS WSTRINGZ _                        ' __in PCWSTR DriveSpec
 , BYREF SpaceRequired AS QUAD _                        ' __out LONGLONG *SpaceRequired
 , BYVAL Reserved1 AS DWORD _                           ' __reserved PVOID Reserved1
 , BYVAL Reserved2 AS DWORD _                           ' __reserved UINT Reserved2
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO SetupQuerySpaceRequiredOnDrive = SetupQuerySpaceRequiredOnDriveW
#ELSE
   MACRO SetupQuerySpaceRequiredOnDrive = SetupQuerySpaceRequiredOnDriveA
#ENDIF

DECLARE FUNCTION SetupAdjustDiskSpaceListA IMPORT "SETUPAPI.DLL" ALIAS "SetupAdjustDiskSpaceListA" ( _
   BYVAL DiskSpace AS DWORD _                           ' __in HDSKSPC DiskSpace
 , BYREF DriveRoot AS ASCIIZ _                          ' __in LPCSTR DriveRoot
 , BYVAL Amount AS QUAD _                               ' __in LONGLONG Amount
 , BYVAL Reserved1 AS DWORD _                           ' __reserved PVOID Reserved1
 , BYVAL Reserved2 AS DWORD _                           ' __reserved UINT Reserved2
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SetupAdjustDiskSpaceListW IMPORT "SETUPAPI.DLL" ALIAS "SetupAdjustDiskSpaceListW" ( _
   BYVAL DiskSpace AS DWORD _                           ' __in HDSKSPC DiskSpace
 , BYREF DriveRoot AS WSTRINGZ _                        ' __in LPCWSTR DriveRoot
 , BYVAL Amount AS QUAD _                               ' __in LONGLONG Amount
 , BYVAL Reserved1 AS DWORD _                           ' __reserved PVOID Reserved1
 , BYVAL Reserved2 AS DWORD _                           ' __reserved UINT Reserved2
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO SetupAdjustDiskSpaceList = SetupAdjustDiskSpaceListW
#ELSE
   MACRO SetupAdjustDiskSpaceList = SetupAdjustDiskSpaceListA
#ENDIF

DECLARE FUNCTION SetupAddToDiskSpaceListA IMPORT "SETUPAPI.DLL" ALIAS "SetupAddToDiskSpaceListA" ( _
   BYVAL DiskSpace AS DWORD _                           ' __in HDSKSPC DiskSpace
 , BYREF TargetFilespec AS ASCIIZ _                     ' __in PCSTR TargetFilespec
 , BYVAL FileSize AS QUAD _                             ' __in LONGLONG FileSize
 , BYVAL Operation AS DWORD _                           ' __in UINT Operation
 , BYVAL Reserved1 AS DWORD _                           ' __reserved PVOID Reserved1
 , BYVAL Reserved2 AS DWORD _                           ' __reserved UINT Reserved2
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SetupAddToDiskSpaceListW IMPORT "SETUPAPI.DLL" ALIAS "SetupAddToDiskSpaceListW" ( _
   BYVAL DiskSpace AS DWORD _                           ' __in HDSKSPC DiskSpace
 , BYREF TargetFilespec AS WSTRINGZ _                   ' __in PCWSTR TargetFilespec
 , BYVAL FileSize AS QUAD _                             ' __in LONGLONG FileSize
 , BYVAL Operation AS DWORD _                           ' __in UINT Operation
 , BYVAL Reserved1 AS DWORD _                           ' __reserved PVOID Reserved1
 , BYVAL Reserved2 AS DWORD _                           ' __reserved UINT Reserved2
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO SetupAddToDiskSpaceList = SetupAddToDiskSpaceListW
#ELSE
   MACRO SetupAddToDiskSpaceList = SetupAddToDiskSpaceListA
#ENDIF

DECLARE FUNCTION SetupAddSectionToDiskSpaceListA IMPORT "SETUPAPI.DLL" ALIAS "SetupAddSectionToDiskSpaceListA" ( _
   BYVAL DiskSpace AS DWORD _                           ' __in HDSKSPC DiskSpace
 , BYVAL InfHandle AS DWORD _                           ' __in HINF InfHandle
 , BYVAL ListInfHandle AS DWORD _                       ' __in_opt HINF ListInfHandle
 , BYREF SectionName AS ASCIIZ _                        ' __in PCSTR SectionName
 , BYVAL Operation AS DWORD _                           ' __in UINT Operation
 , BYVAL Reserved1 AS DWORD _                           ' __reserved PVOID Reserved1
 , BYVAL Reserved2 AS DWORD _                           ' __reserved UINT Reserved2
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SetupAddSectionToDiskSpaceListW IMPORT "SETUPAPI.DLL" ALIAS "SetupAddSectionToDiskSpaceListW" ( _
   BYVAL DiskSpace AS DWORD _                           ' __in HDSKSPC DiskSpace
 , BYVAL InfHandle AS DWORD _                           ' __in HINF InfHandle
 , BYVAL ListInfHandle AS DWORD _                       ' __in_opt HINF ListInfHandle
 , BYREF SectionName AS WSTRINGZ  _                     ' __in PCWSTR SectionName
 , BYVAL Operation AS DWORD _                           ' __in UINT Operation
 , BYVAL Reserved1 AS DWORD _                           ' __reserved PVOID Reserved1
 , BYVAL Reserved2 AS DWORD _                           ' __reserved UINT Reserved2
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO SetupAddSectionToDiskSpaceList = SetupAddSectionToDiskSpaceListW
#ELSE
   MACRO SetupAddSectionToDiskSpaceList = SetupAddSectionToDiskSpaceListA
#ENDIF

DECLARE FUNCTION SetupAddInstallSectionToDiskSpaceListA IMPORT "SETUPAPI.DLL" ALIAS "SetupAddInstallSectionToDiskSpaceListA" ( _
   BYVAL DiskSpace AS DWORD _                           ' __in HDSKSPC DiskSpace
 , BYVAL InfHandle AS DWORD _                           ' __in HINF InfHandle
 , BYVAL LayoutInfHandle AS DWORD _                     ' __in_opt HINF LayoutInfHandle
 , BYREF SectionName AS ASCIIZ _                        ' __in PCSTR SectionName
 , BYVAL Reserved1 AS DWORD _                           ' __reserved PVOID Reserved1
 , BYVAL Reserved2 AS DWORD _                           ' __reserved UINT Reserved2
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SetupAddInstallSectionToDiskSpaceListW IMPORT "SETUPAPI.DLL" ALIAS "SetupAddInstallSectionToDiskSpaceListW" ( _
   BYVAL DiskSpace AS DWORD _                           ' __in HDSKSPC DiskSpace
 , BYVAL InfHandle AS DWORD _                           ' __in HINF InfHandle
 , BYVAL LayoutInfHandle AS DWORD _                     ' __in_opt HINF LayoutInfHandle
 , BYREF SectionName AS WSTRINGZ _                      ' __in PCWSTR SectionName
 , BYVAL Reserved1 AS DWORD _                           ' __reserved PVOID Reserved1
 , BYVAL Reserved2 AS DWORD _                           ' __reserved UINT Reserved2
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO SetupAddInstallSectionToDiskSpaceList = SetupAddInstallSectionToDiskSpaceListW
#ELSE
   MACRO SetupAddInstallSectionToDiskSpaceList = SetupAddInstallSectionToDiskSpaceListA
#ENDIF

DECLARE FUNCTION SetupRemoveFromDiskSpaceListA IMPORT "SETUPAPI.DLL" ALIAS "SetupRemoveFromDiskSpaceListA" ( _
   BYVAL DiskSpace AS DWORD _                           ' __in HDSKSPC DiskSpace
 , BYREF TargetFilespec AS ASCIIZ _                     ' __in PCSTR TargetFilespec
 , BYVAL Operation AS DWORD _                           ' __in UINT Operation
 , BYVAL Reserved1 AS DWORD _                           ' __reserved PVOID Reserved1
 , BYVAL Reserved2 AS DWORD _                           ' __reserved UINT Reserved2
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SetupRemoveFromDiskSpaceListW IMPORT "SETUPAPI.DLL" ALIAS "SetupRemoveFromDiskSpaceListW" ( _
   BYVAL DiskSpace AS DWORD _                           ' __in HDSKSPC DiskSpace
 , BYREF TargetFilespec AS WSTRINGZ _                   ' __in PCWSTR TargetFilespec
 , BYVAL Operation AS DWORD _                           ' __in UINT Operation
 , BYVAL Reserved1 AS DWORD _                           ' __reserved PVOID Reserved1
 , BYVAL Reserved2 AS DWORD _                           ' __reserved UINT Reserved2
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO SetupRemoveFromDiskSpaceList = SetupRemoveFromDiskSpaceListW
#ELSE
   MACRO SetupRemoveFromDiskSpaceList = SetupRemoveFromDiskSpaceListA
#ENDIF

DECLARE FUNCTION SetupRemoveSectionFromDiskSpaceListA IMPORT "SETUPAPI.DLL" ALIAS "SetupRemoveSectionFromDiskSpaceListA" ( _
   BYVAL DiskSpace AS DWORD _                           ' __in HDSKSPC DiskSpace
 , BYVAL InfHandle AS DWORD _                           ' __in HINF InfHandle
 , BYVAL ListInfHandle AS DWORD _                       ' __in_opt HINF ListInfHandle
 , BYREF SectionName AS ASCIIZ _                        ' __in PCSTR SectionName
 , BYVAL Operation AS DWORD _                           ' __in UINT Operation
 , BYVAL Reserved1 AS DWORD _                           ' __reserved PVOID Reserved1
 , BYVAL Reserved2 AS DWORD _                           ' __reserved UINT Reserved2
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SetupRemoveSectionFromDiskSpaceListW IMPORT "SETUPAPI.DLL" ALIAS "SetupRemoveSectionFromDiskSpaceListW" ( _
   BYVAL DiskSpace AS DWORD _                           ' __in HDSKSPC DiskSpace
 , BYVAL InfHandle AS DWORD _                           ' __in HINF InfHandle
 , BYVAL ListInfHandle AS DWORD _                       ' __in_opt HINF ListInfHandle
 , BYREF SectionName AS WSTRINGZ _                      ' __in PCWSTR SectionName
 , BYVAL Operation AS DWORD _                           ' __in UINT Operation
 , BYVAL Reserved1 AS DWORD _                           ' __reserved PVOID Reserved1
 , BYVAL Reserved2 AS DWORD _                           ' __reserved UINT Reserved2
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO SetupRemoveSectionFromDiskSpaceList = SetupRemoveSectionFromDiskSpaceListW
#ELSE
   MACRO SetupRemoveSectionFromDiskSpaceList = SetupRemoveSectionFromDiskSpaceListA
#ENDIF

DECLARE FUNCTION SetupRemoveInstallSectionFromDiskSpaceListA IMPORT "SETUPAPI.DLL" ALIAS "SetupRemoveInstallSectionFromDiskSpaceListA" ( _
   BYVAL DiskSpace AS DWORD _                           ' __in HDSKSPC DiskSpace
 , BYVAL InfHandle AS DWORD _                           ' __in HINF InfHandle
 , BYVAL LayoutInfHandle AS DWORD _                     ' __in_opt HINF LayoutInfHandle
 , BYREF SectionName AS ASCIIZ _                        ' __in PCSTR SectionName
 , BYVAL Reserved1 AS DWORD _                           ' __reserved PVOID Reserved1
 , BYVAL Reserved2 AS DWORD _                           ' __reserved UINT Reserved2
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SetupRemoveInstallSectionFromDiskSpaceListW IMPORT "SETUPAPI.DLL" ALIAS "SetupRemoveInstallSectionFromDiskSpaceListW" ( _
   BYVAL DiskSpace AS DWORD _                           ' __in HDSKSPC DiskSpace
 , BYVAL InfHandle AS DWORD _                           ' __in HINF InfHandle
 , BYVAL LayoutInfHandle AS DWORD _                     ' __in_opt HINF LayoutInfHandle
 , BYREF SectionName AS WSTRINGZ _                      ' __in PCWSTR SectionName
 , BYVAL Reserved1 AS DWORD _                           ' __reserved PVOID Reserved1
 , BYVAL Reserved2 AS DWORD _                           ' __reserved UINT Reserved2
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO SetupRemoveInstallSectionFromDiskSpaceList = SetupRemoveInstallSectionFromDiskSpaceListW
#ELSE
   MACRO SetupRemoveInstallSectionFromDiskSpaceList = SetupRemoveInstallSectionFromDiskSpaceListA
#ENDIF

' //
' // Cabinet APIs
' //

#IF %DEF(%USEOBDECL)
DECLARE FUNCTION SetupIterateCabinetA LIB "SetupApi.dll" _
    ALIAS "SetupIterateCabinetA" ( _
    CabinetFile      AS ASCIIZ, _
    BYVAL Reserved   AS DWORD, _
    BYVAL MsgHandler AS DWORD, _   ' PSP_FILE_CALLBACK_A
    Context          AS ANY _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupIterateCabinetA IMPORT "SETUPAPI.DLL" ALIAS "SetupIterateCabinetA" ( _
   BYREF CabinetFile AS ASCIIZ _                        ' __in PCSTR CabinetFile
 , BYVAL Reserved AS DWORD _                            ' __reserved DWORD Reserved
 , BYVAL MsgHandler AS DWORD _                          ' __in PSP_FILE_CALLBACK_A MsgHandler
 , BYVAL Context AS DWORD _                             ' __in PVOID Context
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%USEOBDECL)
DECLARE FUNCTION SetupIterateCabinetW LIB "SetupApi.dll" _
    ALIAS "SetupIterateCabinetW" ( _
    CabinetFile      AS WSTRINGZ, _
    BYVAL Reserved   AS DWORD, _
    BYVAL MsgHandler AS DWORD, _   ' PSP_FILE_CALLBACK_W
    Context          AS ANY _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupIterateCabinetW IMPORT "SETUPAPI.DLL" ALIAS "SetupIterateCabinetW" ( _
   BYREF CabinetFile AS WSTRINGZ _                      ' __in PCWSTR CabinetFile
 , BYVAL Reserved AS DWORD _                            ' __reserved DWORD Reserved
 , BYVAL MsgHandler AS DWORD _                          ' __in PSP_FILE_CALLBACK_W MsgHandler
 , BYVAL Context AS DWORD _                             ' __in PVOID Context
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%UNICODE)
   MACRO SetupIterateCabinet = SetupIterateCabinetW
#ELSE
   MACRO SetupIterateCabinet = SetupIterateCabinetA
#ENDIF

DECLARE FUNCTION SetupPromptReboot IMPORT "SETUPAPI.DLL" ALIAS "SetupPromptReboot" ( _
   BYVAL FileQueue AS DWORD _                           ' __in_opt HSPFILEQ FileQueue
 , BYVAL Owner AS DWORD _                               ' __in HWND Owner
 , BYVAL ScanOnly AS LONG _                             ' __in BOOL ScanOnly
 ) AS LONG                                              ' INT

' //
' // Define flags that are returned by SetupPromptReboot
' //
%SPFILEQ_FILE_IN_USE         = &H00000001???
%SPFILEQ_REBOOT_RECOMMENDED  = &H00000002???
%SPFILEQ_REBOOT_IN_PROGRESS  = &H00000004???

DECLARE FUNCTION SetupInitDefaultQueueCallback IMPORT "SETUPAPI.DLL" ALIAS "SetupInitDefaultQueueCallback" ( _
   BYVAL OwnerWindow AS DWORD _                         ' __in HWND OwnerWindow
 ) AS DWORD                                             ' PVOID

DECLARE FUNCTION SetupInitDefaultQueueCallbackEx IMPORT "SETUPAPI.DLL" ALIAS "SetupInitDefaultQueueCallbackEx" ( _
   BYVAL OwnerWindow AS DWORD _                         ' __in HWND OwnerWindow
 , BYVAL AlternateProgressWindow AS DWORD _             ' __in_opt HWND AlternateProgressWindow
 , BYVAL ProgressMessage AS DWORD _                     ' __in UINT ProgressMessage
 , BYVAL Reserved1 AS DWORD _                           ' __reserved DWORD Reserved1
 , BYVAL Reserved2 AS DWORD _                           ' __reserved PVOID Reserved2
 ) AS DWORD                                             ' PVOID

#IF %DEF(%USEPBDECL)
DECLARE SUB SetupTermDefaultQueueCallback LIB "SetupApi.dll" _
    ALIAS "SetupTermDefaultQueueCallback" (Context AS ANY)
#ELSE
DECLARE SUB SetupTermDefaultQueueCallback IMPORT "SETUPAPI.DLL" ALIAS "SetupTermDefaultQueueCallback" ( _
   BYVAL Context AS DWORD _                             ' __in PVOID Context
 )                                                      ' void
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SetupDefaultQueueCallbackA LIB "SetupApi.dll" _
    ALIAS "SetupDefaultQueueCallbackA" ( _
    Context            AS ANY, _
    BYVAL Notification AS DWORD, _
    BYVAL Param1       AS DWORD, _  ' UINT_PTR, _
    BYVAL Param2       AS DWORD _   ' UINT_PTR, _
    ) AS DWORD
#ELSE
DECLARE FUNCTION SetupDefaultQueueCallbackA IMPORT "SETUPAPI.DLL" ALIAS "SetupDefaultQueueCallbackA" ( _
   BYVAL Context AS DWORD _                             ' __in PVOID Context
 , BYVAL Notification AS DWORD _                        ' __in UINT Notification
 , BYVAL Param1 AS DWORD _                              ' __in UINT_PTR Param1
 , BYVAL Param2 AS DWORD _                              ' __in UINT_PTR Param2
 ) AS DWORD                                             ' UINT
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SetupDefaultQueueCallbackW LIB "SetupApi.dll" _
    ALIAS "SetupDefaultQueueCallbackW" ( _
    Context            AS ANY, _
    BYVAL Notification AS DWORD, _
    BYVAL Param1       AS DWORD, _  ' UINT_PTR, _
    BYVAL Param2       AS DWORD _   ' UINT_PTR, _
    ) AS DWORD
#ELSE
DECLARE FUNCTION SetupDefaultQueueCallbackW IMPORT "SETUPAPI.DLL" ALIAS "SetupDefaultQueueCallbackW" ( _
   BYVAL Context AS DWORD _                             ' __in PVOID Context
 , BYVAL Notification AS DWORD _                        ' __in UINT Notification
 , BYVAL Param1 AS DWORD _                              ' __in UINT_PTR Param1
 , BYVAL Param2 AS DWORD _                              ' __in UINT_PTR Param2
 ) AS DWORD                                             ' UINT
#ENDIF

#IF %DEF(%UNICODE)
   MACRO SetupDefaultQueueCallback = SetupDefaultQueueCallbackW
#ELSE
   MACRO SetupDefaultQueueCallback = SetupDefaultQueueCallbackA
#ENDIF

' //
' // Flags for AddReg section lines in INF.  The corresponding value
' // is <ValueType> in the AddReg line format given below:
' //
' // <RegRootString>,<SubKey>,<ValueName>,<ValueType>,<Value>...
' //
' // The low word contains basic flags concerning the general data type
' // and AddReg action. The high word contains values that more specifically
' // identify the data type of the registry value.  The high word is ignored
' // by the 16-bit Windows 95 SETUPX APIs.
' //
' // If <ValueType> has FLG_ADDREG_DELREG_BIT set, it will be ignored by AddReg
' // (not supported by SetupX).
' //

'#if _SETUPAPI_VER >= _WIN32_WINNT_WINXP
#IF %SETUPAPI_VER >= %WIN32_WINNT_WINXP
%FLG_ADDREG_DELREG_BIT       = &H00008000???   ' // if set, interpret as DELREG, see below
#ENDIF
'#endif // _SETUPAPI_VER >= _WIN32_WINNT_WINXP

%FLG_ADDREG_BINVALUETYPE     = &H00000001???
%FLG_ADDREG_NOCLOBBER        = &H00000002???
%FLG_ADDREG_DELVAL           = &H00000004???
%FLG_ADDREG_APPEND           = &H00000008???   ' // Currently supported only
                                               ' // for REG_MULTI_SZ values.
%FLG_ADDREG_KEYONLY          = &H00000010???   ' // Just create the key, ignore value
%FLG_ADDREG_OVERWRITEONLY    = &H00000020???   ' // Set only if value already exists

'#if _SETUPAPI_VER >= _WIN32_WINNT_WINXP
#IF %SETUPAPI_VER >= %WIN32_WINNT_WINXP
%FLG_ADDREG_64BITKEY         = &H00001000???   ' // make this change in the 64 bit registry.
%FLG_ADDREG_KEYONLY_COMMON   = &H00002000???   ' // same as FLG_ADDREG_KEYONLY but also works for DELREG
%FLG_ADDREG_32BITKEY         = &H00004000???   ' // make this change in the 32 bit registry.
#ENDIF
'#endif // _SETUPAPI_VER >= _WIN32_WINNT_WINXP

' //
' // The INF may supply any arbitrary data type ordinal in the highword except
' // for the following: REG_NONE, REG_SZ, REG_EXPAND_SZ, REG_MULTI_SZ.  If this
' // technique is used, then the data is given in binary format, one byte per
' // field.
' //
%FLG_ADDREG_TYPE_MASK        = &HFFFF0000??? OR %FLG_ADDREG_BINVALUETYPE
%FLG_ADDREG_TYPE_SZ          = &H00000000???
%FLG_ADDREG_TYPE_MULTI_SZ    = &H00010000???
%FLG_ADDREG_TYPE_EXPAND_SZ   = &H00020000???
%FLG_ADDREG_TYPE_BINARY      = &H00000000??? OR %FLG_ADDREG_BINVALUETYPE
%FLG_ADDREG_TYPE_DWORD       = &H00010000??? OR %FLG_ADDREG_BINVALUETYPE
%FLG_ADDREG_TYPE_NONE        = &H00020000??? OR %FLG_ADDREG_BINVALUETYPE

' //
' // Flags for DelReg section lines in INF.  The corresponding value
' // is <Operation> in the extended DelReg line format given below:
' //
' // <RegRootString>,<SubKey>,<ValueName>,<Operation>[,...]
' //
' // In SetupX and some versions of SetupAPI, <Operation> will be ignored and <ValueName> will
' // be deleted. Use with care.
' //
' // The bits determined by mask FLG_DELREG_TYPE_MASK indicates type of data expected.
' // <Operation> must have FLG_ADDREG_DELREG_BIT set, otherwise it is ignored and specified
' // value will be deleted (allowing an AddReg section to also be used as a DelReg section)
' // if <Operation> is not specified, <ValueName> will be deleted (if specified) otherwise
' // <SubKey> will be deleted.
' //
' // the compatability flag
' //
%FLG_DELREG_VALUE            = &H00000000???

'#if _SETUPAPI_VER >= _WIN32_WINNT_WINXP
#IF %SETUPAPI_VER >= %WIN32_WINNT_WINXP

%FLG_DELREG_TYPE_MASK        = %FLG_ADDREG_TYPE_MASK        ' // 0xFFFF0001
%FLG_DELREG_TYPE_SZ          = %FLG_ADDREG_TYPE_SZ          ' // 0x00000000
%FLG_DELREG_TYPE_MULTI_SZ    = %FLG_ADDREG_TYPE_MULTI_SZ    ' // 0x00010000
%FLG_DELREG_TYPE_EXPAND_SZ   = %FLG_ADDREG_TYPE_EXPAND_SZ   ' // 0x00020000
%FLG_DELREG_TYPE_BINARY      = %FLG_ADDREG_TYPE_BINARY      ' // 0x00000001
%FLG_DELREG_TYPE_DWORD       = %FLG_ADDREG_TYPE_DWORD       ' // 0x00010001
%FLG_DELREG_TYPE_NONE        = %FLG_ADDREG_TYPE_NONE        ' // 0x00020001
%FLG_DELREG_64BITKEY         = %FLG_ADDREG_64BITKEY         ' // 0x00001000
%FLG_DELREG_KEYONLY_COMMON   = %FLG_ADDREG_KEYONLY_COMMON   ' // 0x00002000
%FLG_DELREG_32BITKEY         = %FLG_ADDREG_32BITKEY         ' // 0x00004000

' //
' // <Operation> = FLG_DELREG_MULTI_SZ_DELSTRING
' //               <RegRootString>,<SubKey>,<ValueName>,0x00018002,<String>
' //               removes all entries matching <String> (case ignored) from multi-sz registry value
' //

%FLG_DELREG_OPERATION_MASK   = &H000000FE???
%FLG_DELREG_MULTI_SZ_DELSTRING = %FLG_DELREG_TYPE_MULTI_SZ OR %FLG_ADDREG_DELREG_BIT OR &H00000002   ' // 0x00018002

#ENDIF
'#endif // _SETUPAPI_VER >= _WIN32_WINNT_WINXP

' //
' // Flags for BitReg section lines in INF.
' //
%FLG_BITREG_CLEARBITS        = &H00000000???
%FLG_BITREG_SETBITS          = &H00000001???

'#if _SETUPAPI_VER >= _WIN32_WINNT_WINXP
#IF %SETUPAPI_VER >= %WIN32_WINNT_WINXP
%FLG_BITREG_64BITKEY         = &H00001000???
%FLG_BITREG_32BITKEY         = &H00004000???
#ENDIF
'#endif // _SETUPAPI_VER >= _WIN32_WINNT_WINXP

' //
' // Flags for Ini2Reg section lines in INF.
' //
'#if _SETUPAPI_VER >= _WIN32_WINNT_WINXP
#IF %SETUPAPI_VER >= %WIN32_WINNT_WINXP
%FLG_INI2REG_64BITKEY        = &H00001000???
%FLG_INI2REG_32BITKEY        = &H00004000???
#ENDIF
'#endif // _SETUPAPI_VER >= _WIN32_WINNT_WINXP

' //
' // Flags for RegSvr section lines in INF
' //
%FLG_REGSVR_DLLREGISTER      = &H00000001???
%FLG_REGSVR_DLLINSTALL       = &H00000002???

' // Flags for RegSvr section lines in INF
' //

%FLG_PROFITEM_CURRENTUSER    = &H00000001???
%FLG_PROFITEM_DELETE         = &H00000002???
%FLG_PROFITEM_GROUP          = &H00000004???
%FLG_PROFITEM_CSIDL          = &H00000008???

'//
'// Flags for AddProperty section lines in the INF
'//

%FLG_ADDPROPERTY_NOCLOBBER       = &H00000001???
%FLG_ADDPROPERTY_OVERWRITEONLY   = &H00000002???
%FLG_ADDPROPERTY_APPEND          = &H00000004???
%FLG_ADDPROPERTY_OR              = &H00000008???
%FLG_ADDPROPERTY_AND             = &H00000010???

'//
'// Flags for DelProperty section lines in the INF
'//

%FLG_DELPROPERTY_MULTI_SZ_DELSTRING  = &H00000001???


#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SetupInstallFromInfSectionA LIB "SetupApi.dll" _
    ALIAS "SetupInstallFromInfSectionA" ( _
    BYVAL Owner AS DWORD, _  ' HWND
    BYVAL InfHandle AS DWORD, _
    SectionName AS ASCIIZ, _
    BYVAL Flags AS DWORD, _
    BYVAL RelativeKeyRoot AS DWORD, _  ' HKEY
    SourceRootPath AS ASCIIZ, _
    BYVAL CopyFlags AS DWORD, _
    BYVAL MsgHandler AS DWORD, _   ' PSP_FILE_CALLBACK_A
    Context AS ANY, _
    BYVAL DeviceInfoSet AS DWORD, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupInstallFromInfSectionA IMPORT "SETUPAPI.DLL" ALIAS "SetupInstallFromInfSectionA" ( _
   BYVAL Owner AS DWORD _                               ' __in_opt HWND Owner
 , BYVAL InfHandle AS DWORD _                           ' __in HINF InfHandle
 , BYREF SectionName AS ASCIIZ _                        ' __in PCSTR SectionName
 , BYVAL Flags AS DWORD _                               ' __in UINT Flags
 , BYVAL RelativeKeyRoot AS DWORD _                     ' __in_opt HKEY RelativeKeyRoot
 , BYREF SourceRootPath AS ASCIIZ _                     ' __in_opt PCSTR SourceRootPath
 , BYVAL CopyFlags AS DWORD _                           ' __in UINT CopyFlags
 , OPTIONAL BYVAL MsgHandler AS DWORD _                 ' __in_opt PSP_FILE_CALLBACK_A MsgHandler
 , OPTIONAL BYVAL Context AS DWORD _                    ' __in_opt PVOID Context
 , OPTIONAL BYVAL DeviceInfoSet AS DWORD _              ' __in_opt HDEVINFO DeviceInfoSet
 , OPTIONAL BYREF DeviceInfoData AS SP_DEVINFO_DATA _   ' __in_opt PSP_DEVINFO_DATA DeviceInfoData
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SetupInstallFromInfSectionW LIB "SetupApi.dll" _
    ALIAS "SetupInstallFromInfSectionW" ( _
    BYVAL Owner AS DWORD, _   ' HWND
    BYVAL InfHandle AS DWORD, _
    SectionName AS WSTRINGZ, _
    BYVAL Flags AS DWORD, _
    BYVAL RelativeKeyRoot AS DWORD, _  ' HKEY
    SourceRootPath AS WSTRINGZ, _
    BYVAL CopyFlags AS DWORD, _
    BYVAL MsgHandler AS DWORD, _   ' PSP_FILE_CALLBACK_W
    Context AS ANY, _
    BYVAL DeviceInfoSet AS DWORD, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupInstallFromInfSectionW IMPORT "SETUPAPI.DLL" ALIAS "SetupInstallFromInfSectionW" ( _
   BYVAL Owner AS DWORD _                               ' __in_opt HWND Owner
 , BYVAL InfHandle AS DWORD _                           ' __in HINF InfHandle
 , BYREF SectionName AS WSTRINGZ _                      ' __in PCWSTR SectionName
 , BYVAL Flags AS DWORD _                               ' __in UINT Flags
 , BYVAL RelativeKeyRoot AS DWORD _                     ' __in_opt HKEY RelativeKeyRoot
 , BYREF SourceRootPath AS WSTRINGZ _                   ' __in_opt PCWSTR SourceRootPath
 , BYVAL CopyFlags AS DWORD _                           ' __in UINT CopyFlags
 , OPTIONAL BYVAL MsgHandler AS DWORD _                 ' __in_opt PSP_FILE_CALLBACK_W MsgHandler
 , OPTIONAL BYVAL Context AS DWORD _                    ' __in_opt PVOID Context
 , OPTIONAL BYVAL DeviceInfoSet AS DWORD _              ' __in_opt HDEVINFO DeviceInfoSet
 , OPTIONAL BYREF DeviceInfoData AS SP_DEVINFO_DATA _   ' __in_opt PSP_DEVINFO_DATA DeviceInfoData
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%UNICODE)
   MACRO SetupInstallFromInfSection = SetupInstallFromInfSectionW
#ELSE
   MACRO SetupInstallFromInfSection = SetupInstallFromInfSectionA
#ENDIF

' //
' // Flags for SetupInstallFromInfSection
' //
%SPINST_LOGCONFIG                = &H00000001???
%SPINST_INIFILES                 = &H00000002???
%SPINST_REGISTRY                 = &H00000004???
%SPINST_INI2REG                  = &H00000008???
%SPINST_FILES                    = &H00000010???
%SPINST_BITREG                   = &H00000020???
%SPINST_REGSVR                   = &H00000040???
%SPINST_UNREGSVR                 = &H00000080???
%SPINST_PROFILEITEMS             = &H00000100???

'#if _SETUPAPI_VER >= _WIN32_WINNT_WINXP
#IF %SETUPAPI_VER >= %WIN32_WINNT_WINXP

%SPINST_COPYINF                  = &H00000200???

'#if _SETUPAPI_VER >= _WIN32_WINNT_LONGHORN
#IF %SETUPAPI_VER >= %WIN32_WINNT_LONGHORN

%SPINST_PROPERTIES               = &H00000400???
%SPINST_ALL                      = &H000007ff???

#ELSE

%SPINST_ALL                      = &H000003ff???

#ENDIF
'#endif // _SETUPAPI_VER >= _WIN32_WINNT_LONGHORN

#ELSE

%SPINST_ALL                      = &H000001ff???

#ENDIF   ' // _SETUPAPI_VER >= WIN32_WINNT_WINXP

%SPINST_SINGLESECTION            = &H00010000???
%SPINST_LOGCONFIG_IS_FORCED      = &H00020000???
%SPINST_LOGCONFIGS_ARE_OVERRIDES = &H00040000???

'#if _SETUPAPI_VER >= _WIN32_WINNT_WINXP
#IF %SETUPAPI_VER >= %WIN32_WINNT_WINXP
%SPINST_REGISTERCALLBACKAWARE    = &H00080000???
#ENDIF
'#endif // _SETUPAPI_VER >= _WIN32_WINNT_WINXP

'#if _SETUPAPI_VER >= _WIN32_WINNT_LONGHORN
#IF %SETUPAPI_VER >= %WIN32_WINNT_LONGHORN
%SPINST_DEVICEINSTALL            = &H00100000???
#ENDIF
'#endif // _SETUPAPI_VER >= _WIN32_WINNT_LONGHORN

DECLARE FUNCTION SetupInstallFilesFromInfSectionA IMPORT "SETUPAPI.DLL" ALIAS "SetupInstallFilesFromInfSectionA" ( _
   BYVAL InfHandle AS DWORD _                           ' __in HINF InfHandle
 , BYVAL LayoutInfHandle AS DWORD _                     ' __in_opt HINF LayoutInfHandle
 , BYVAL FileQueue AS DWORD _                           ' __in HSPFILEQ FileQueue
 , BYREF SectionName AS ASCIIZ _                        ' __in PCSTR SectionName
 , BYREF SourceRootPath AS ASCIIZ _                     ' __in_opt PCSTR SourceRootPath
 , BYVAL CopyFlags AS DWORD _                           ' __in UINT CopyFlags
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SetupInstallFilesFromInfSectionW IMPORT "SETUPAPI.DLL" ALIAS "SetupInstallFilesFromInfSectionW" ( _
   BYVAL InfHandle AS DWORD _                           ' __in HINF InfHandle
 , BYVAL LayoutInfHandle AS DWORD _                     ' __in_opt HINF LayoutInfHandle
 , BYVAL FileQueue AS DWORD _                           ' __in HSPFILEQ FileQueue
 , BYREF SectionName AS WSTRINGZ _                      ' __in PCWSTR SectionName
 , BYREF SourceRootPath AS WSTRINGZ _                   ' __in_opt PCWSTR SourceRootPath
 , BYVAL CopyFlags AS DWORD _                           ' __in UINT CopyFlags
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO SetupInstallFilesFromInfSection = SetupInstallFilesFromInfSectionW
#ELSE
   MACRO SetupInstallFilesFromInfSection = SetupInstallFilesFromInfSectionA
#ENDIF

' //
' // Flags for SetupInstallServicesFromInfSection(Ex).  These flags are also used
' // in the flags field of AddService or DelService lines in a device INF.  Some
' // of these flags are not permitted in the non-Ex API.  These flags are marked
' // as such below.
' //

' //
' // (AddService) move service's tag to front of its group order list
' //
%SPSVCINST_TAGTOFRONT               = &H00000001???

' //
' // (AddService) **Ex API only** mark this service as the function driver for the
' // device being installed
' //
%SPSVCINST_ASSOCSERVICE             = &H00000002???

' //
' // (DelService) delete the associated event log entry for a service specified in
' // a DelService entry
' //
%SPSVCINST_DELETEEVENTLOGENTRY      = &H00000004???

' //
' // (AddService) don't overwrite display name if it already exists
' //
%SPSVCINST_NOCLOBBER_DISPLAYNAME    = &H00000008???

' //
' // (AddService) don't overwrite start type value if service already exists
' //
%SPSVCINST_NOCLOBBER_STARTTYPE      = &H00000010???

' //
' // (AddService) don't overwrite error control value if service already exists
' //
%SPSVCINST_NOCLOBBER_ERRORCONTROL   = &H00000020???

' //
' // (AddService) don't overwrite load order group if it already exists
' //
%SPSVCINST_NOCLOBBER_LOADORDERGROUP = &H00000040???

' //
' // (AddService) don't overwrite dependencies list if it already exists
' //
%SPSVCINST_NOCLOBBER_DEPENDENCIES   = &H00000080???

' //
' // (AddService) don't overwrite description if it already exists
' //
%SPSVCINST_NOCLOBBER_DESCRIPTION    = &H00000100???
' //
' // (DelService) stop the associated service specified in
' // a DelService entry before deleting the service
' //
%SPSVCINST_STOPSERVICE              = &H00000200???

'#if _SETUPAPI_VER >= _WIN32_WINNT_WINXP
#IF %SETUPAPI_VER >= %WIN32_WINNT_WINXP
' //
' // (AddService) force overwrite of security settings
' //
%SPSVCINST_CLOBBER_SECURITY         = &H00000400???

#ENDIF
'#endif // _SETUPAPI_VER >= _WIN32_WINNT_WINXP

'#if _SETUPAPI_VER >= _WIN32_WINNT_LONGHORN
#IF %SETUPAPI_VER >= %WIN32_WINNT_LONGHORN
'//
'// (Start Service) start a service manually after install
'//
%SPSVCINST_STARTSERVICE             = &H00000800???

#ENDIF
'#endif // _SETUPAPI_VER >= _WIN32_WINNT_LONGHORN

'#if _SETUPAPI_VER >= _WIN32_WINNT_WIN7
#IF %SETUPAPI_VER >= %WIN32_WINNT_WIN7
'//
'// (AddService) don't overwrite required privileges list if it already exists
'//
%SPSVCINST_NOCLOBBER_REQUIREDPRIVILEGES = &H00001000???
#ENDIF
'#endif // _SETUPAPI_VER >= _WIN32_WINNT_WIN7

DECLARE FUNCTION SetupInstallServicesFromInfSectionA IMPORT "SETUPAPI.DLL" ALIAS "SetupInstallServicesFromInfSectionA" ( _
   BYVAL InfHandle AS DWORD _                           ' __in HINF InfHandle
 , BYREF SectionName AS ASCIIZ _                        ' __in PCSTR SectionName
 , BYVAL Flags AS DWORD _                               ' __in DWORD Flags
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SetupInstallServicesFromInfSectionW IMPORT "SETUPAPI.DLL" ALIAS "SetupInstallServicesFromInfSectionW" ( _
   BYVAL InfHandle AS DWORD _                           ' __in HINF InfHandle
 , BYREF SectionName AS WSTRINGZ _                      ' __in PCWSTR SectionName
 , BYVAL Flags AS DWORD _                               ' __in DWORD Flags
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO SetupInstallServicesFromInfSection = SetupInstallServicesFromInfSectionW
#ELSE
   MACRO SetupInstallServicesFromInfSection = SetupInstallServicesFromInfSectionA
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SetupInstallServicesFromInfSectionExA LIB "SetupApi.dll" _
    ALIAS "SetupInstallServicesFromInfSectionExA" ( _
    BYVAL InfHandle AS DWORD, _
    SectionName AS ASCIIZ, _
    BYVAL Flags AS DWORD, _
    BYVAL DeviceInfoSet AS DWORD, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR, _
    BYVAL Reserved1 AS DWORD, _  ' PVOID
    BYVAL Reserved2 AS DWORD _  ' PVOID
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupInstallServicesFromInfSectionExA IMPORT "SETUPAPI.DLL" ALIAS "SetupInstallServicesFromInfSectionExA" ( _
   BYVAL InfHandle AS DWORD _                           ' __in HINF InfHandle
 , BYREF SectionName AS ASCIIZ _                        ' __in PCSTR SectionName
 , BYVAL Flags AS DWORD _                               ' __in DWORD Flags
 , BYVAL DeviceInfoSet AS DWORD _                       ' __in_opt HDEVINFO DeviceInfoSet
 , BYREF DeviceInfoData AS SP_DEVINFO_DATA _            ' __in_opt PSP_DEVINFO_DATA DeviceInfoData
 , BYVAL Reserved1 AS DWORD _                           ' __reserved PVOID Reserved1
 , BYVAL Reserved2 AS DWORD _                           ' __reserved PVOID Reserved2
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SetupInstallServicesFromInfSectionExW LIB "SetupApi.dll" _
    ALIAS "SetupInstallServicesFromInfSectionExW" ( _
    BYVAL InfHandle AS DWORD, _
    SectionName AS WSTRINGZ, _
    BYVAL Flags AS DWORD, _
    BYVAL DeviceInfoSet AS DWORD, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR, _
    BYVAL Reserved1 AS DWORD, _  ' PVOID
    BYVAL Reserved2 AS DWORD _  ' PVOID
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupInstallServicesFromInfSectionExW IMPORT "SETUPAPI.DLL" ALIAS "SetupInstallServicesFromInfSectionExW" ( _
   BYVAL InfHandle AS DWORD _                           ' __in HINF InfHandle
 , BYREF SectionName AS WSTRINGZ _                      ' __in PCWSTR SectionName
 , BYVAL Flags AS DWORD _                               ' __in DWORD Flags
 , BYVAL DeviceInfoSet AS DWORD _                       ' __in_opt HDEVINFO DeviceInfoSet
 , BYREF DeviceInfoData AS SP_DEVINFO_DATA _            ' __in_opt PSP_DEVINFO_DATA DeviceInfoData
 , BYVAL Reserved1 AS DWORD _                           ' __reserved PVOID Reserved1
 , BYVAL Reserved2 AS DWORD _                           ' __reserved PVOID Reserved2
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%UNICODE)
   MACRO SetupInstallServicesFromInfSectionEx = SetupInstallServicesFromInfSectionExW
#ELSE
   MACRO SetupInstallServicesFromInfSectionEx = SetupInstallServicesFromInfSectionExA
#ENDIF

' //
' // High level routine, usually used via rundll32.dll
' // to perform right-click install action on INFs
' // May be called directly:
' //
' // wsprintf(CmdLineBuffer,TEXT("DefaultInstall 132 %s"),InfPath);
' // InstallHinfSection(NULL,NULL,CmdLineBuffer,0);
' //

DECLARE SUB InstallHinfSectionA IMPORT "SETUPAPI.DLL" ALIAS "InstallHinfSectionA" ( _
   BYVAL Window AS DWORD _                              ' __in HWND Window
 , BYVAL ModuleHandle AS DWORD _                        ' __in HINSTANCE ModuleHandle
 , BYREF CommandLine AS ASCIIZ _                        ' __in PCSTR CommandLine
 , BYVAL ShowCommand AS LONG _                          ' __in INT ShowCommand
 )                                                      ' void

DECLARE SUB InstallHinfSectionW IMPORT "SETUPAPI.DLL" ALIAS "InstallHinfSectionW" ( _
   BYVAL Window AS DWORD _                              ' __in HWND Window
 , BYVAL ModuleHandle AS DWORD _                        ' __in HINSTANCE ModuleHandle
 , BYREF CommandLine AS WSTRINGZ _                      ' __in PCWSTR CommandLine
 , BYVAL ShowCommand AS LONG _                          ' __in INT ShowCommand
 )                                                      ' void

#IF %DEF(%UNICODE)
   MACRO InstallHinfSection = InstallHinfSectionW
#ELSE
   MACRO InstallHinfSection = InstallHinfSectionA
#ENDIF

' //
' // Define handle type for Setup file log.
' //
'typedef PVOID HSPFILELOG;

DECLARE FUNCTION SetupInitializeFileLogA IMPORT "SETUPAPI.DLL" ALIAS "SetupInitializeFileLogA" ( _
   BYREF LogFileName AS ASCIIZ _                        ' __in_opt PCSTR LogFileName
 , BYVAL Flags AS DWORD _                               ' __in DWORD Flags
 ) AS DWORD                                             ' HSPFILELOG

DECLARE FUNCTION SetupInitializeFileLogW IMPORT "SETUPAPI.DLL" ALIAS "SetupInitializeFileLogW" ( _
   BYREF LogFileName AS WSTRINGZ _                      ' __in_opt PCWSTR LogFileName
 , BYVAL Flags AS DWORD _                               ' __in DWORD Flags
 ) AS DWORD                                             ' HSPFILELOG

#IF %DEF(%UNICODE)
   MACRO SetupInitializeFileLog = SetupInitializeFileLogW
#ELSE
   MACRO SetupInitializeFileLog = SetupInitializeFileLogA
#ENDIF

' //
' // Flags for SetupInitializeFileLog
' //
%SPFILELOG_SYSTEMLOG     = &H00000001???   ' // use system log -- must be Administrator
%SPFILELOG_FORCENEW      = &H00000002???   ' // not valid with SPFILELOG_SYSTEMLOG
%SPFILELOG_QUERYONLY     = &H00000004???   ' // allows non-administrators to read system log

DECLARE FUNCTION SetupTerminateFileLog IMPORT "SETUPAPI.DLL" ALIAS "SetupTerminateFileLog" ( _
   BYVAL FileLogHandle AS DWORD _                       ' __in HSPFILELOG FileLogHandle
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SetupLogFileA IMPORT "SETUPAPI.DLL" ALIAS "SetupLogFileA" ( _
   BYVAL FileLogHandle AS DWORD _                       ' __in HSPFILELOG FileLogHandle
 , BYREF LogSectionName AS ASCIIZ _                     ' __in_opt PCSTR LogSectionName
 , BYREF SourceFilename AS ASCIIZ _                     ' __in PCSTR SourceFilename
 , BYREF TargetFilename AS ASCIIZ _                     ' __in PCSTR TargetFilename
 , BYVAL Checksum AS DWORD _                            ' __in DWORD Checksum
 , BYREF DiskTagfile AS ASCIIZ _                        ' __in_opt PCSTR DiskTagfile
 , BYREF DiskDescription AS ASCIIZ _                    ' __in_opt PCSTR DiskDescription
 , BYREF OtherInfo AS ASCIIZ _                          ' __in_opt PCSTR OtherInfo
 , BYVAL Flags AS DWORD _                               ' __in DWORD Flags
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SetupLogFileW IMPORT "SETUPAPI.DLL" ALIAS "SetupLogFileW" ( _
   BYVAL FileLogHandle AS DWORD _                       ' __in HSPFILELOG FileLogHandle
 , BYREF LogSectionName AS WSTRINGZ _                   ' __in_opt PCWSTR LogSectionName
 , BYREF SourceFilename AS WSTRINGZ _                   ' __in PCWSTR SourceFilename
 , BYREF TargetFilename AS WSTRINGZ _                   ' __in PCWSTR TargetFilename
 , BYVAL Checksum AS DWORD _                            ' __in DWORD Checksum
 , BYREF DiskTagfile AS WSTRINGZ _                      ' __in_opt PCWSTR DiskTagfile
 , BYREF DiskDescription AS WSTRINGZ _                  ' __in_opt PCWSTR DiskDescription
 , BYREF OtherInfo AS WSTRINGZ _                        ' __in_opt PCWSTR OtherInfo
 , BYVAL Flags AS DWORD _                               ' __in DWORD Flags
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO SetupLogFile = SetupLogFileW
#ELSE
   MACRO SetupLogFile = SetupLogFileA
#ENDIF

' //
' // Flags for SetupLogFile
' //
%SPFILELOG_OEMFILE   = &H00000001???

DECLARE FUNCTION SetupRemoveFileLogEntryA IMPORT "SETUPAPI.DLL" ALIAS "SetupRemoveFileLogEntryA" ( _
   BYVAL FileLogHandle AS DWORD _                       ' __in HSPFILELOG FileLogHandle
 , OPTIONAL BYREF LogSectionName AS ASCIIZ _            ' __in_opt PCSTR LogSectionName
 , OPTIONAL BYREF TargetFilename AS ASCIIZ _            ' __in_opt PCSTR TargetFilename
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SetupRemoveFileLogEntryW IMPORT "SETUPAPI.DLL" ALIAS "SetupRemoveFileLogEntryW" ( _
   BYVAL FileLogHandle AS DWORD _                       ' __in HSPFILELOG FileLogHandle
 , OPTIONAL BYREF LogSectionName AS WSTRINGZ _          ' __in_opt PCWSTR LogSectionName
 , OPTIONAL BYREF TargetFilename AS WSTRINGZ _          ' __in_opt PCWSTR TargetFilename
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO SetupRemoveFileLogEntry = SetupRemoveFileLogEntryW
#ELSE
   MACRO SetupRemoveFileLogEntry = SetupRemoveFileLogEntryA
#ENDIF

' //
' // Items retrievable from SetupQueryFileLog()
' //
' enum SetupFileLogInfo
%SetupFileLogSourceFilename  = 0
%SetupFileLogChecksum        = 1
%SetupFileLogDiskTagfile     = 2
%SetupFileLogDiskDescription = 3
%SetupFileLogOtherInfo       = 4
%SetupFileLogMax             = 5

DECLARE FUNCTION SetupQueryFileLogA IMPORT "SETUPAPI.DLL" ALIAS "SetupQueryFileLogA" ( _
   BYVAL FileLogHandle AS DWORD _                       ' __in HSPFILELOG FileLogHandle
 , BYREF LogSectionName AS ASCIIZ _                     ' __in_opt PCSTR LogSectionName
 , BYREF TargetFilename AS ASCIIZ _                     ' __in PCSTR TargetFilename
 , BYVAL DesiredInfo AS LONG _                          ' __in SetupFileLogInfo DesiredInfo
 , BYREF DataOut AS ASCIIZ _                            ' __out PSTR DataOut
 , BYVAL ReturnBufferSize AS DWORD _                    ' __in DWORD ReturnBufferSize
 , OPTIONAL BYREF RequiredSize AS DWORD _               ' __out_opt PDWORD RequiredSize
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SetupQueryFileLogW IMPORT "SETUPAPI.DLL" ALIAS "SetupQueryFileLogW" ( _
   BYVAL FileLogHandle AS DWORD _                       ' __in HSPFILELOG FileLogHandle
 , BYREF LogSectionName AS WSTRINGZ _                   ' __in_opt PCWSTR LogSectionName
 , BYREF TargetFilename AS WSTRINGZ _                   ' __in PCWSTR TargetFilename
 , BYVAL DesiredInfo AS LONG _                          ' __in SetupFileLogInfo DesiredInfo
 , BYREF DataOut AS WSTRINGZ _                          ' __out PWSTR DataOut
 , BYVAL ReturnBufferSize AS DWORD _                    ' __in DWORD ReturnBufferSize
 , OPTIONAL BYREF RequiredSize AS DWORD _               ' __out_opt PDWORD RequiredSize
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO SetupQueryFileLog = SetupQueryFileLogW
#ELSE
   MACRO SetupQueryFileLog = SetupQueryFileLogA
#ENDIF

' //
' // Text logging APIs
' //
'#define LogSeverity                 DWORD
%LogSevInformation           = &H00000000???
%LogSevWarning               = &H00000001???
%LogSevError                 = &H00000002???
%LogSevFatalError            = &H00000003???
%LogSevMaximum               = &H00000004???

DECLARE FUNCTION SetupOpenLog IMPORT "SETUPAPI.DLL" ALIAS "SetupOpenLog" ( _
   BYVAL Erase AS LONG _                                ' __in BOOL Erase
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SetupLogErrorA IMPORT "SETUPAPI.DLL" ALIAS "SetupLogErrorA" ( _
   BYREF MessageString AS ASCIIZ _                      ' __in LPCSTR MessageString
 , BYVAL Severity AS LONG _                             ' __in LogSeverity Severity
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SetupLogErrorW IMPORT "SETUPAPI.DLL" ALIAS "SetupLogErrorW" ( _
   BYREF MessageString AS WSTRINGZ _                    ' __in LPCWSTR MessageString
 , BYVAL Severity AS LONG _                             ' __in LogSeverity Severity
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO SetupLogError = SetupLogErrorW
#ELSE
   MACRO SetupLogError = SetupLogErrorA
#ENDIF

DECLARE SUB SetupCloseLog IMPORT "SETUPAPI.DLL" ALIAS "SetupCloseLog" ( _
 )                                                      ' void

'//
'// Text log for INF debugging
'//

'#if _SETUPAPI_VER >= _WIN32_WINNT_LONGHORN
#IF %SETUPAPI_VER >= %WIN32_WINNT_LONGHORN

DECLARE FUNCTION SetupGetThreadLogToken IMPORT "SETUPAPI.DLL" ALIAS "SetupGetThreadLogToken" ( _
 ) AS QUAD                                              ' SP_LOG_TOKEN

DECLARE SUB SetupSetThreadLogToken IMPORT "SETUPAPI.DLL" ALIAS "SetupSetThreadLogToken" ( _
   BYVAL LogToken AS QUAD _                             ' __in SP_LOG_TOKEN LogToken
 )                                                      ' void

DECLARE SUB SetupWriteTextLog CDECL IMPORT "SETUPAPI.DLL" ALIAS "SetupWriteTextLog" ( _
   BYVAL LogToken AS QUAD _                             ' __in SP_LOG_TOKEN LogToken
 , BYVAL Category AS DWORD _                            ' __in DWORD Category
 , BYVAL Flags AS DWORD _                               ' __in DWORD Flags
 , BYREF MessageStr AS ASCIIZ _                         ' __in PCSTR MessageStr
 , OPTIONAL BYREF ANY _                                 ' Optional parameters
 , BYREF ANY _
 , BYREF ANY _
 , BYREF ANY _
 , BYREF ANY _
 , BYREF ANY _
 , BYREF ANY _
 , BYREF ANY _
 , BYREF ANY _
 , BYREF ANY _
 , BYREF ANY _
 , BYREF ANY _
 )                                                      ' void

DECLARE SUB SetupWriteTextLogError CDECL IMPORT "SETUPAPI.DLL" ALIAS "SetupWriteTextLogError" ( _
   BYVAL LogToken AS QUAD _                             ' __in SP_LOG_TOKEN LogToken
 , BYVAL Category AS DWORD _                            ' __in DWORD Category
 , BYVAL LogFlags AS DWORD _                            ' __in DWORD LogFlags
 , BYVAL Error AS DWORD _                               ' __in DWORD Error
 , BYREF MessageStr AS ASCIIZ _                         ' __in PCSTR MessageStr
 , OPTIONAL BYREF ANY _                                 ' Optional parameters
 , BYREF ANY _
 , BYREF ANY _
 , BYREF ANY _
 , BYREF ANY _
 , BYREF ANY _
 , BYREF ANY _
 , BYREF ANY _
 , BYREF ANY _
 , BYREF ANY _
 , BYREF ANY _
 , BYREF ANY _
 )                                                      ' void

DECLARE SUB SetupWriteTextLogInfLine IMPORT "SETUPAPI.DLL" ALIAS "SetupWriteTextLogInfLine" ( _
   BYVAL LogToken AS QUAD _                             ' __in SP_LOG_TOKEN LogToken
 , BYVAL Flags AS DWORD _                               ' __in DWORD Flags
 , BYVAL InfHandle AS DWORD _                           ' __in HINF InfHandle
 , BYREF Context AS INFCONTEXT _                        ' __in PINFCONTEXT Context
 )                                                      ' void

#ENDIF
'#endif // _SETUPAPI_VER >= _WIN32_WINNT_LONGHORN

' //
' // Backup Information API's
' //

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SetupGetBackupInformationA LIB "SetupApi.dll" _
    ALIAS "SetupGetBackupInformationA" ( _
    BYVAL QueueHandle AS DWORD, _
    BYVAL BackupParams AS SP_BACKUP_QUEUE_PARAMS_A PTR _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupGetBackupInformationA IMPORT "SETUPAPI.DLL" ALIAS "SetupGetBackupInformationA" ( _
   BYVAL QueueHandle AS DWORD _                         ' __in HSPFILEQ QueueHandle
 , BYREF BackupParams AS SP_BACKUP_QUEUE_PARAMS_A _     ' __out PSP_BACKUP_QUEUE_PARAMS_A BackupParams
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SetupGetBackupInformationW LIB "SetupApi.dll" _
    ALIAS "SetupGetBackupInformationW" ( _
    BYVAL QueueHandle AS DWORD, _
    BYVAL BackupParams AS SP_BACKUP_QUEUE_PARAMS_W PTR _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupGetBackupInformationW IMPORT "SETUPAPI.DLL" ALIAS "SetupGetBackupInformationW" ( _
   BYVAL QueueHandle AS DWORD _                         ' __in HSPFILEQ QueueHandle
 , BYREF BackupParams AS SP_BACKUP_QUEUE_PARAMS_W _     ' __out PSP_BACKUP_QUEUE_PARAMS_W BackupParams
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%UNICODE)
   MACRO SetupGetBackupInformation = SetupGetBackupInformationW
#ELSE
   MACRO SetupGetBackupInformation = SetupGetBackupInformationA
#ENDIF

'#if _SETUPAPI_VER >= _WIN32_WINNT_WINXP
#IF %SETUPAPI_VER >= %WIN32_WINNT_WINXP

DECLARE FUNCTION SetupPrepareQueueForRestoreA IMPORT "SETUPAPI.DLL" ALIAS "SetupPrepareQueueForRestoreA" ( _
   BYVAL QueueHandle AS DWORD _                         ' __in HSPFILEQ QueueHandle
 , BYREF BackupPath AS ASCIIZ _                         ' __in PCSTR BackupPath
 , BYVAL RestoreFlags AS DWORD _                        ' __in DWORD RestoreFlags
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SetupPrepareQueueForRestoreW IMPORT "SETUPAPI.DLL" ALIAS "SetupPrepareQueueForRestoreW" ( _
   BYVAL QueueHandle AS DWORD _                         ' __in HSPFILEQ QueueHandle
 , BYREF BackupPath AS WSTRINGZ _                       ' __in PCWSTR BackupPath
 , BYVAL RestoreFlags AS DWORD _                        ' __in DWORD RestoreFlags
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO SetupPrepareQueueForRestore = SetupPrepareQueueForRestoreW
#ELSE
   MACRO SetupPrepareQueueForRestore = SetupPrepareQueueForRestoreA
#ENDIF

#ENDIF
'#endif // _SETUPAPI_VER >= _WIN32_WINNT_WINXP

'#if _SETUPAPI_VER >= _WIN32_WINNT_WINXP
#IF %SETUPAPI_VER >= %WIN32_WINNT_WINXP

' //
' // Control forcing of Non-Interactive Mode
' // Overriden if SetupAPI is run in non-interactive window session
' //

DECLARE FUNCTION SetupSetNonInteractiveMode IMPORT "SETUPAPI.DLL" ALIAS "SetupSetNonInteractiveMode" ( _
   BYVAL NonInteractiveFlag AS LONG _                   ' __in BOOL NonInteractiveFlag
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SetupGetNonInteractiveMode IMPORT "SETUPAPI.DLL" ALIAS "SetupGetNonInteractiveMode" ( _
 ) AS LONG                                              ' BOOL

#ENDIF
'#endif // _SETUPAPI_VER >= _WIN32_WINNT_WINXP

' //
' // Device Installer APIs
' //

DECLARE FUNCTION SetupDiCreateDeviceInfoList IMPORT "SETUPAPI.DLL" ALIAS "SetupDiCreateDeviceInfoList" ( _
   OPTIONAL BYREF ClassGuid AS GUID _                   ' __in_opt CONST GUID *ClassGuid
 , OPTIONAL BYVAL hwndParent AS DWORD _                 ' __in_opt HWND hwndParent
 ) AS DWORD                                             ' HDEVINFO

DECLARE FUNCTION SetupDiCreateDeviceInfoListExA IMPORT "SETUPAPI.DLL" ALIAS "SetupDiCreateDeviceInfoListExA" ( _
   OPTIONAL BYREF ClassGuid AS GUID _                   ' __in_opt CONST GUID *ClassGuid
 , OPTIONAL BYVAL hwndParent AS DWORD _                 ' __in_opt HWND hwndParent
 , OPTIONAL BYREF MachineName AS ASCIIZ _               ' __in_opt PCSTR MachineName
 , OPTIONAL BYVAL Reserved AS DWORD _                   ' __reserved PVOID Reserved
 ) AS DWORD                                             ' HDEVINFO

DECLARE FUNCTION SetupDiCreateDeviceInfoListExW IMPORT "SETUPAPI.DLL" ALIAS "SetupDiCreateDeviceInfoListExW" ( _
   OPTIONAL BYREF ClassGuid AS GUID _                   ' __in_opt CONST GUID *ClassGuid
 , OPTIONAL BYVAL hwndParent AS DWORD _                 ' __in_opt HWND hwndParent
 , OPTIONAL BYREF MachineName AS WSTRINGZ _             ' __in_opt PCWSTR MachineName
 , OPTIONAL BYVAL Reserved AS DWORD _                   ' __reserved PVOID Reserved
 ) AS DWORD                                             ' HDEVINFO

#IF %DEF(%UNICODE)
   MACRO SetupDiCreateDeviceInfoListEx = SetupDiCreateDeviceInfoListExW
#ELSE
   MACRO SetupDiCreateDeviceInfoListEx = SetupDiCreateDeviceInfoListExA
#ENDIF

DECLARE FUNCTION SetupDiGetDeviceInfoListClass IMPORT "SETUPAPI.DLL" ALIAS "SetupDiGetDeviceInfoListClass" ( _
   BYVAL DeviceInfoSet AS DWORD _                       ' __in HDEVINFO DeviceInfoSet
 , BYREF ClassGuid AS GUID _                            ' __out LPGUID ClassGuid
 ) AS LONG                                              ' BOOL

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SetupDiGetDeviceInfoListDetailA LIB "SetupApi.dll" _
    ALIAS "SetupDiGetDeviceInfoListDetailA" ( _
    BYVAL DeviceInfoSet AS DWORD, _
    BYVAL DeviceInfoSetDetailData AS SP_DEVINFO_LIST_DETAIL_DATA_A PTR _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupDiGetDeviceInfoListDetailA IMPORT "SETUPAPI.DLL" ALIAS "SetupDiGetDeviceInfoListDetailA" ( _
   BYVAL DeviceInfoSet AS DWORD _                       '  __in HDEVINFO DeviceInfoSet
 , BYREF DeviceInfoSetDetailData AS SP_DEVINFO_LIST_DETAIL_DATA_A _ ' __out PSP_DEVINFO_LIST_DETAIL_DATA_A DeviceInfoSetDetailData
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SetupDiGetDeviceInfoListDetailW LIB "SetupApi.dll" _
    ALIAS "SetupDiGetDeviceInfoListDetailW" ( _
    BYVAL DeviceInfoSet AS DWORD, _
    BYVAL DeviceInfoSetDetailData AS SP_DEVINFO_LIST_DETAIL_DATA_W PTR _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupDiGetDeviceInfoListDetailW IMPORT "SETUPAPI.DLL" ALIAS "SetupDiGetDeviceInfoListDetailW" ( _
   BYVAL DeviceInfoSet AS DWORD _                       '  __in HDEVINFO DeviceInfoSet
 , BYREF DeviceInfoSetDetailData AS SP_DEVINFO_LIST_DETAIL_DATA_W _ ' __out PSP_DEVINFO_LIST_DETAIL_DATA_W DeviceInfoSetDetailData
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%UNICODE)
   MACRO SetupDiGetDeviceInfoListDetail = SetupDiGetDeviceInfoListDetailW
#ELSE
   MACRO SetupDiGetDeviceInfoListDetail = SetupDiGetDeviceInfoListDetailA
#ENDIF

' //
' // Flags for SetupDiCreateDeviceInfo
' //
%DICD_GENERATE_ID        = &H00000001???
%DICD_INHERIT_CLASSDRVS  = &H00000002???

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SetupDiCreateDeviceInfoA LIB "SetupApi.dll" _
    ALIAS "SetupDiCreateDeviceInfoA" ( _
    BYVAL DeviceInfoSet AS DWORD, _
    DeviceName AS ASCIIZ, _
    ClassGuid AS GUID, _
    DeviceDescription AS ASCIIZ, _
    BYVAL hwndParent AS DWORD, _   ' HWND
    BYVAL CreationFlags AS DWORD, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupDiCreateDeviceInfoA IMPORT "SETUPAPI.DLL" ALIAS "SetupDiCreateDeviceInfoA" ( _
   BYVAL DeviceInfoSet AS DWORD _                       ' __in HDEVINFO DeviceInfoSet
 , BYREF DeviceName AS ASCIIZ _                         ' __in PCSTR DeviceName
 , BYREF ClassGuid AS GUID _                            ' __in CONST GUID *ClassGuid
 , BYREF DeviceDescription AS ASCIIZ _                  ' __in_opt PCSTR DeviceDescription
 , BYVAL hwndParent AS DWORD _                          ' __in_opt HWND hwndParent
 , BYVAL CreationFlags AS DWORD _                       ' __in DWORD CreationFlags
 , OPTIONAL BYREF DeviceInfoData AS SP_DEVINFO_DATA _   ' __out_opt PSP_DEVINFO_DATA DeviceInfoData
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SetupDiCreateDeviceInfoW LIB "SetupApi.dll" _
    ALIAS "SetupDiCreateDeviceInfoW" ( _
    BYVAL DeviceInfoSet AS DWORD, _
    DeviceName AS WSTRINGZ, _
    ClassGuid AS GUID, _
    DeviceDescription AS WSTRINGZ, _
    BYVAL hwndParent AS DWORD, _   ' HWND
    BYVAL CreationFlags AS DWORD, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupDiCreateDeviceInfoW IMPORT "SETUPAPI.DLL" ALIAS "SetupDiCreateDeviceInfoW" ( _
   BYVAL DeviceInfoSet AS DWORD _                       ' __in HDEVINFO DeviceInfoSet
 , BYREF DeviceName AS WSTRINGZ _                       ' __in PCWSTR DeviceName
 , BYREF ClassGuid AS GUID _                            ' __in CONST GUID *ClassGuid
 , BYREF DeviceDescription AS WSTRINGZ _                ' __in_opt PCWSTR DeviceDescription
 , BYVAL hwndParent AS DWORD _                          ' __in_opt HWND hwndParent
 , BYVAL CreationFlags AS DWORD _                       ' __in DWORD CreationFlags
 , OPTIONAL BYREF DeviceInfoData AS SP_DEVINFO_DATA _   ' __out_opt PSP_DEVINFO_DATA DeviceInfoData
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%UNICODE)
   MACRO SetupDiCreateDeviceInfo = SetupDiCreateDeviceInfoW
#ELSE
   MACRO SetupDiCreateDeviceInfo = SetupDiCreateDeviceInfoA
#ENDIF

' //
' // Flags for SetupDiOpenDeviceInfo
' //
%DIOD_INHERIT_CLASSDRVS  = &H00000002???
%DIOD_CANCEL_REMOVE      = &H00000004???

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SetupDiOpenDeviceInfoA LIB "SetupApi.dll" _
    ALIAS "SetupDiOpenDeviceInfoA" ( _
    BYVAL DeviceInfoSet AS DWORD, _
    DeviceInstanceId AS ASCIIZ, _
    BYVAL hwndParent AS DWORD, _   ' HWND
    BYVAL OpenFlags AS DWORD, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupDiOpenDeviceInfoA IMPORT "SETUPAPI.DLL" ALIAS "SetupDiOpenDeviceInfoA" ( _
   BYVAL DeviceInfoSet AS DWORD _                       ' __in HDEVINFO DeviceInfoSet
 , BYREF DeviceInstanceId AS ASCIIZ _                   ' __in PCSTR DeviceInstanceId
 , BYVAL hwndParent AS DWORD _                          ' __in_opt HWND hwndParent
 , BYVAL OpenFlags AS DWORD _                           ' __in DWORD OpenFlags
 , OPTIONAL BYREF DeviceInfoData AS SP_DEVINFO_DATA _   ' __out_opt PSP_DEVINFO_DATA DeviceInfoData
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SetupDiOpenDeviceInfoW LIB "SetupApi.dll" _
    ALIAS "SetupDiOpenDeviceInfoW" ( _
    BYVAL DeviceInfoSet AS DWORD, _
    DeviceInstanceId AS WSTRINGZ, _
    BYVAL hwndParent AS DWORD, _   ' HWND
    BYVAL OpenFlags AS DWORD, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupDiOpenDeviceInfoW IMPORT "SETUPAPI.DLL" ALIAS "SetupDiOpenDeviceInfoW" ( _
   BYVAL DeviceInfoSet AS DWORD _                       ' __in HDEVINFO DeviceInfoSet
 , BYREF DeviceInstanceId AS WSTRINGZ _                 ' __in PCWSTR DeviceInstanceId
 , BYVAL hwndParent AS DWORD _                          ' __in_opt HWND hwndParent
 , BYVAL OpenFlags AS DWORD _                           ' __in DWORD OpenFlags
 , OPTIONAL BYREF DeviceInfoData AS SP_DEVINFO_DATA _   ' __out_opt PSP_DEVINFO_DATA DeviceInfoData
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%UNICODE)
   MACRO SetupDiOpenDeviceInfo = SetupDiOpenDeviceInfoW
#ELSE
   MACRO SetupDiOpenDeviceInfo = SetupDiOpenDeviceInfoA
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SetupDiGetDeviceInstanceIdA LIB "SetupApi.dll" _
    ALIAS "SetupDiGetDeviceInstanceIdA" ( _
    BYVAL DeviceInfoSet AS DWORD, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR, _
    DeviceInstanceId AS ASCIIZ, _
    BYVAL DeviceInstanceIdSize AS DWORD, _
    RequiredSize AS DWORD _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupDiGetDeviceInstanceIdA IMPORT "SETUPAPI.DLL" ALIAS "SetupDiGetDeviceInstanceIdA" ( _
   BYVAL DeviceInfoSet AS DWORD _                       ' __in HDEVINFO DeviceInfoSet
 , BYREF DeviceInfoData AS SP_DEVINFO_DATA _            ' __in PSP_DEVINFO_DATA DeviceInfoData
 , BYREF DeviceInstanceId AS ASCIIZ _                   ' __out PSTR DeviceInstanceId
 , BYVAL DeviceInstanceIdSize AS DWORD _                ' __in DWORD DeviceInstanceIdSize
 , OPTIONAL BYREF RequiredSize AS DWORD _               ' __out_opt PDWORD RequiredSize
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SetupDiGetDeviceInstanceIdW LIB "SetupApi.dll" _
    ALIAS "SetupDiGetDeviceInstanceIdW" ( _
    BYVAL DeviceInfoSet AS DWORD, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR, _
    DeviceInstanceId AS WSTRINGZ, _
    BYVAL DeviceInstanceIdSize AS DWORD, _
    RequiredSize AS DWORD _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupDiGetDeviceInstanceIdW IMPORT "SETUPAPI.DLL" ALIAS "SetupDiGetDeviceInstanceIdW" ( _
   BYVAL DeviceInfoSet AS DWORD _                       ' __in HDEVINFO DeviceInfoSet
 , BYREF DeviceInfoData AS SP_DEVINFO_DATA _            ' __in PSP_DEVINFO_DATA DeviceInfoData
 , BYREF DeviceInstanceId AS WSTRINGZ _                 ' __out PWSTR DeviceInstanceId
 , BYVAL DeviceInstanceIdSize AS DWORD _                ' __in DWORD DeviceInstanceIdSize
 , OPTIONAL BYREF RequiredSize AS DWORD _               ' __out_opt PDWORD RequiredSize
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%UNICODE)
   MACRO SetupDiGetDeviceInstanceId = SetupDiGetDeviceInstanceIdW
#ELSE
   MACRO SetupDiGetDeviceInstanceId = SetupDiGetDeviceInstanceIdA
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SetupDiDeleteDeviceInfo LIB "SetupApi.dll" _
    ALIAS "SetupDiDeleteDeviceInfo" ( _
    BYVAL DeviceInfoSet AS DWORD, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupDiDeleteDeviceInfo IMPORT "SETUPAPI.DLL" ALIAS "SetupDiDeleteDeviceInfo" ( _
   BYVAL DeviceInfoSet AS DWORD _                       ' __in HDEVINFO DeviceInfoSet
 , BYREF DeviceInfoData AS SP_DEVINFO_DATA _            ' __in PSP_DEVINFO_DATA DeviceInfoData
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SetupDiEnumDeviceInfo LIB "SetupApi.dll" _
    ALIAS "SetupDiEnumDeviceInfo" ( _
    BYVAL DeviceInfoSet AS DWORD, _
    BYVAL MemberIndex AS DWORD, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupDiEnumDeviceInfo IMPORT "SETUPAPI.DLL" ALIAS "SetupDiEnumDeviceInfo" ( _
   BYVAL DeviceInfoSet AS DWORD _                       ' __in HDEVINFO DeviceInfoSet
 , BYVAL MemberIndex AS DWORD _                         ' __in DWORD MemberIndex
 , BYREF DeviceInfoData AS SP_DEVINFO_DATA _            ' __out PSP_DEVINFO_DATA DeviceInfoData
 ) AS LONG                                              ' BOOL
#ENDIF

DECLARE FUNCTION SetupDiDestroyDeviceInfoList IMPORT "SETUPAPI.DLL" ALIAS "SetupDiDestroyDeviceInfoList" ( _
   BYVAL DeviceInfoSet AS DWORD _                       ' __in HDEVINFO DeviceInfoSet
 ) AS LONG                                              ' BOOL

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SetupDiEnumDeviceInterfaces LIB "SetupApi.dll" _
    ALIAS "SetupDiEnumDeviceInterfaces" ( _
    BYVAL DeviceInfoSet AS DWORD, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR, _
    InterfaceClassGuid AS GUID, _
    BYVAL MemberIndex AS DWORD, _
    BYVAL DeviceInterfaceData AS SP_DEVICE_INTERFACE_DATA PTR _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupDiEnumDeviceInterfaces IMPORT "SETUPAPI.DLL" ALIAS "SetupDiEnumDeviceInterfaces" ( _
   BYVAL DeviceInfoSet AS DWORD _                       ' __in HDEVINFO DeviceInfoSet
 , BYREF DeviceInfoData AS SP_DEVINFO_DATA _            ' __in_opt PSP_DEVINFO_DATA DeviceInfoData
 , BYREF InterfaceClassGuid AS GUID _                   ' __in CONST GUID *InterfaceClassGuid
 , BYVAL MemberIndex AS DWORD _                         ' __in DWORD MemberIndex
 , BYREF DeviceInterfaceData AS SP_DEVICE_INTERFACE_DATA _ ' __out PSP_DEVICE_INTERFACE_DATA DeviceInterfaceData
 ) AS LONG                                              ' BOOL
#ENDIF

' //
' // Backward compatibility--do not use
' //
'#define SetupDiEnumInterfaceDevice SetupDiEnumDeviceInterfaces

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SetupDiCreateDeviceInterfaceA LIB "SetupApi.dll" _
    ALIAS "SetupDiCreateDeviceInterfaceA" ( _
    BYVAL DeviceInfoSet AS DWORD, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR, _
    InterfaceClassGuid AS GUID, _
    ReferenceString AS ASCIIZ, _
    BYVAL CreationFlags AS DWORD, _
    BYVAL DeviceInterfaceData AS SP_DEVICE_INTERFACE_DATA PTR _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupDiCreateDeviceInterfaceA IMPORT "SETUPAPI.DLL" ALIAS "SetupDiCreateDeviceInterfaceA" ( _
   BYVAL DeviceInfoSet AS DWORD _                       ' __in HDEVINFO DeviceInfoSet
 , BYREF DeviceInfoData AS SP_DEVINFO_DATA _            ' __in PSP_DEVINFO_DATA DeviceInfoData
 , BYREF InterfaceClassGuid AS GUID _                   ' __in CONST GUID *InterfaceClassGuid
 , BYREF ReferenceString AS ASCIIZ _                    ' __in_opt PCSTR ReferenceString
 , BYVAL CreationFlags AS DWORD _                       ' __in DWORD CreationFlags
 , OPTIONAL BYREF DeviceInterfaceData AS SP_DEVICE_INTERFACE_DATA _ ' __out_opt PSP_DEVICE_INTERFACE_DATA DeviceInterfaceData
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SetupDiCreateDeviceInterfaceW LIB "SetupApi.dll" _
    ALIAS "SetupDiCreateDeviceInterfaceW" ( _
    BYVAL DeviceInfoSet AS DWORD, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR, _
    InterfaceClassGuid AS GUID, _
    ReferenceString AS WSTRINGZ, _
    BYVAL CreationFlags AS DWORD, _
    BYVAL DeviceInterfaceData AS SP_DEVICE_INTERFACE_DATA PTR _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupDiCreateDeviceInterfaceW IMPORT "SETUPAPI.DLL" ALIAS "SetupDiCreateDeviceInterfaceW" ( _
   BYVAL DeviceInfoSet AS DWORD _                       ' __in HDEVINFO DeviceInfoSet
 , BYREF DeviceInfoData AS SP_DEVINFO_DATA _            ' __in PSP_DEVINFO_DATA DeviceInfoData
 , BYREF InterfaceClassGuid AS GUID _                   ' __in CONST GUID *InterfaceClassGuid
 , BYREF ReferenceString AS WSTRINGZ _                  ' __in_opt PCWSTR ReferenceString
 , BYVAL CreationFlags AS DWORD _                       ' __in DWORD CreationFlags
 , OPTIONAL BYREF DeviceInterfaceData AS SP_DEVICE_INTERFACE_DATA _ ' __out_opt PSP_DEVICE_INTERFACE_DATA DeviceInterfaceData
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%UNICODE)
   MACRO SetupDiCreateDeviceInterface = SetupDiCreateDeviceInterfaceW
#ELSE
   MACRO SetupDiCreateDeviceInterface = SetupDiCreateDeviceInterfaceA
#ENDIF

' //
' // Backward compatibility--do not use.
' //
'#define SetupDiCreateInterfaceDeviceW SetupDiCreateDeviceInterfaceW
'#define SetupDiCreateInterfaceDeviceA SetupDiCreateDeviceInterfaceA


' //
' // Flags for SetupDiOpenDeviceInterface
' //
%DIODI_NO_ADD    = &H00000001???

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SetupDiOpenDeviceInterfaceA LIB "SetupApi.dll" _
    ALIAS "SetupDiOpenDeviceInterfaceA" ( _
    BYVAL DeviceInfoSet AS DWORD, _
    DevicePath AS ASCIIZ, _
    BYVAL OpenFlags AS DWORD, _
    BYVAL DeviceInterfaceData AS SP_DEVICE_INTERFACE_DATA PTR _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupDiOpenDeviceInterfaceA IMPORT "SETUPAPI.DLL" ALIAS "SetupDiOpenDeviceInterfaceA" ( _
   BYVAL DeviceInfoSet AS DWORD _                          ' __in HDEVINFO DeviceInfoSet
 , BYREF DevicePath AS ASCIIZ _                            ' __in PCSTR DevicePath
 , BYVAL OpenFlags AS DWORD _                              ' __in DWORD OpenFlags
 , OPTIONAL BYREF DeviceInterfaceData AS SP_DEVICE_INTERFACE_DATA _ ' __out_opt PSP_DEVICE_INTERFACE_DATA DeviceInterfaceData
 ) AS LONG                                                 ' BOOL
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SetupDiOpenDeviceInterfaceW LIB "SetupApi.dll" _
    ALIAS "SetupDiOpenDeviceInterfaceW" ( _
    BYVAL DeviceInfoSet AS DWORD, _
    DevicePath AS WSTRINGZ, _
    BYVAL OpenFlags AS DWORD, _
    BYVAL DeviceInterfaceData AS SP_DEVICE_INTERFACE_DATA PTR _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupDiOpenDeviceInterfaceW IMPORT "SETUPAPI.DLL" ALIAS "SetupDiOpenDeviceInterfaceW" ( _
   BYVAL DeviceInfoSet AS DWORD _                          ' __in HDEVINFO DeviceInfoSet
 , BYREF DevicePath AS WSTRINGZ _                          ' __in PCWSTR DevicePath
 , BYVAL OpenFlags AS DWORD _                              ' __in DWORD OpenFlags
 , OPTIONAL BYREF DeviceInterfaceData AS SP_DEVICE_INTERFACE_DATA _ ' __out_opt PSP_DEVICE_INTERFACE_DATA DeviceInterfaceData
 ) AS LONG                                                 ' BOOL
#ENDIF

#IF %DEF(%UNICODE)
   MACRO SetupDiOpenDeviceInterface = SetupDiOpenDeviceInterfaceW
#ELSE
   MACRO SetupDiOpenDeviceInterface = SetupDiOpenDeviceInterfaceA
#ENDIF

' //
' // Backward compatibility--do not use
' //
'#define SetupDiOpenInterfaceDeviceW SetupDiOpenDeviceInterfaceW
'#define SetupDiOpenInterfaceDeviceA SetupDiOpenDeviceInterfaceA

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SetupDiGetDeviceInterfaceAlias LIB "SetupApi.dll" _
    ALIAS "SetupDiGetDeviceInterfaceAlias" ( _
    BYVAL DeviceInfoSet AS DWORD, _
    BYVAL DeviceInterfaceData AS SP_DEVICE_INTERFACE_DATA PTR, _
    AliasInterfaceClassGuid AS GUID, _
    BYVAL AliasDeviceInterfaceData AS SP_DEVICE_INTERFACE_DATA PTR _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupDiGetDeviceInterfaceAlias IMPORT "SETUPAPI.DLL" ALIAS "SetupDiGetDeviceInterfaceAlias" ( _
   BYVAL DeviceInfoSet AS DWORD _                               ' __in HDEVINFO DeviceInfoSet
 , BYREF DeviceInterfaceData AS SP_DEVICE_INTERFACE_DATA _      ' __in PSP_DEVICE_INTERFACE_DATA DeviceInterfaceData
 , BYREF AliasInterfaceClassGuid AS GUID _                      ' __in CONST GUID *AliasInterfaceClassGuid
 , BYREF AliasDeviceInterfaceData AS SP_DEVICE_INTERFACE_DATA _ ' __out PSP_DEVICE_INTERFACE_DATA AliasDeviceInterfaceData
 ) AS LONG                                                      ' BOOL
#ENDIF

' //
' // Backward compatibility--do not use.
' //
'#define SetupDiGetInterfaceDeviceAlias SetupDiGetDeviceInterfaceAlias

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SetupDiDeleteDeviceInterfaceData LIB "SetupApi.dll" _
    ALIAS "SetupDiDeleteDeviceInterfaceData" ( _
    BYVAL DeviceInfoSet AS DWORD, _
    BYVAL DeviceInterfaceData AS SP_DEVICE_INTERFACE_DATA PTR _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupDiDeleteDeviceInterfaceData IMPORT "SETUPAPI.DLL" ALIAS "SetupDiDeleteDeviceInterfaceData" ( _
   BYVAL DeviceInfoSet AS DWORD _                          ' __in HDEVINFO DeviceInfoSet
 , BYREF DeviceInterfaceData AS SP_DEVICE_INTERFACE_DATA _ ' __in PSP_DEVICE_INTERFACE_DATA DeviceInterfaceData
 ) AS LONG                                                 ' BOOL
#ENDIF

' //
' // Backward compatibility--do not use.
' //
'#define SetupDiDeleteInterfaceDeviceData SetupDiDeleteDeviceInterfaceData

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SetupDiRemoveDeviceInterface LIB "SetupApi.dll" _
    ALIAS "SetupDiRemoveDeviceInterface" ( _
    BYVAL DeviceInfoSet AS DWORD, _
    BYVAL DeviceInterfaceData AS SP_DEVICE_INTERFACE_DATA PTR _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupDiRemoveDeviceInterface IMPORT "SETUPAPI.DLL" ALIAS "SetupDiRemoveDeviceInterface" ( _
   BYVAL DeviceInfoSet AS DWORD _                          ' __in HDEVINFO DeviceInfoSet
 , BYREF DeviceInterfaceData AS SP_DEVICE_INTERFACE_DATA _ ' __inout PSP_DEVICE_INTERFACE_DATA DeviceInterfaceData
 ) AS LONG                                                 ' BOOL
#ENDIF

' //
' // Backward compatibility--do not use.
' //
'#define SetupDiRemoveInterfaceDevice SetupDiRemoveDeviceInterface

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SetupDiGetDeviceInterfaceDetailA LIB "SetupApi.dll" _
    ALIAS "SetupDiGetDeviceInterfaceDetailA" ( _
    BYVAL DeviceInfoSet AS DWORD, _
    BYVAL DeviceInterfaceData AS SP_DEVICE_INTERFACE_DATA PTR, _
    BYVAL DeviceInterfaceDetailData AS SP_DEVICE_INTERFACE_DETAIL_DATA_A PTR, _
    BYVAL DeviceInterfaceDetailDataSize AS DWORD, _
    RequiredSize AS DWORD, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupDiGetDeviceInterfaceDetailA IMPORT "SETUPAPI.DLL" ALIAS "SetupDiGetDeviceInterfaceDetailA" ( _
   BYVAL DeviceInfoSet AS DWORD _                          ' __in HDEVINFO DeviceInfoSet
 , BYREF DeviceInterfaceData AS SP_DEVICE_INTERFACE_DATA _ ' __in PSP_DEVICE_INTERFACE_DATA DeviceInterfaceData
 , BYREF DeviceInterfaceDetailData AS ANY _                ' __out PSP_DEVICE_INTERFACE_DETAIL_DATA_A DeviceInterfaceDetailData
 , BYVAL DeviceInterfaceDetailDataSize AS DWORD _          ' __in DWORD DeviceInterfaceDetailDataSize
 , OPTIONAL BYREF RequiredSize AS DWORD _                  ' __out_opt PDWORD RequiredSize
 , OPTIONAL BYREF DeviceInfoData AS SP_DEVINFO_DATA _      ' __out_opt PSP_DEVINFO_DATA DeviceInfoData
 ) AS LONG                                                 ' BOOL
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SetupDiGetDeviceInterfaceDetailW LIB "SetupApi.dll" _
    ALIAS "SetupDiGetDeviceInterfaceDetailW" ( _
    BYVAL DeviceInfoSet AS DWORD, _
    BYVAL DeviceInterfaceData AS SP_DEVICE_INTERFACE_DATA PTR, _
    BYVAL DeviceInterfaceDetailData AS SP_DEVICE_INTERFACE_DETAIL_DATA_W PTR, _
    BYVAL DeviceInterfaceDetailDataSize AS DWORD, _
    RequiredSize AS DWORD, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupDiGetDeviceInterfaceDetailW IMPORT "SETUPAPI.DLL" ALIAS "SetupDiGetDeviceInterfaceDetailW" ( _
   BYVAL DeviceInfoSet AS DWORD _                          ' __in HDEVINFO DeviceInfoSet
 , BYREF DeviceInterfaceData AS SP_DEVICE_INTERFACE_DATA _ ' __in PSP_DEVICE_INTERFACE_DATA DeviceInterfaceData
 , BYREF DeviceInterfaceDetailData AS ANY _                ' __out PSP_DEVICE_INTERFACE_DETAIL_DATA_W DeviceInterfaceDetailData
 , BYVAL DeviceInterfaceDetailDataSize AS DWORD _          ' __in DWORD DeviceInterfaceDetailDataSize
 , OPTIONAL BYREF RequiredSize AS DWORD _                  ' __out_opt PDWORD RequiredSize
 , OPTIONAL BYREF DeviceInfoData AS SP_DEVINFO_DATA _      ' __out_opt PSP_DEVINFO_DATA DeviceInfoData
 ) AS LONG                                                 ' BOOL
#ENDIF

#IF %DEF(%UNICODE)
   MACRO SetupDiGetDeviceInterfaceDetail = SetupDiGetDeviceInterfaceDetailW
#ELSE
   MACRO SetupDiGetDeviceInterfaceDetail = SetupDiGetDeviceInterfaceDetailA
#ENDIF

' //
' // Backward compatibility--do not use.
' //
'#define SetupDiGetInterfaceDeviceDetailW SetupDiGetDeviceInterfaceDetailW
'#define SetupDiGetInterfaceDeviceDetailA SetupDiGetDeviceInterfaceDetailA

' //
' // Default install handler for DIF_INSTALLINTERFACES.
' //

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SetupDiInstallDeviceInterfaces LIB "SetupApi.dll" _
    ALIAS "SetupDiInstallDeviceInterfaces" ( _
    BYVAL DeviceInfoSet AS DWORD, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupDiInstallDeviceInterfaces IMPORT "SETUPAPI.DLL" ALIAS "SetupDiInstallDeviceInterfaces" ( _
   BYVAL DeviceInfoSet AS DWORD _                       ' __in HDEVINFO DeviceInfoSet
 , BYREF DeviceInfoData AS SP_DEVINFO_DATA _            ' __in PSP_DEVINFO_DATA DeviceInfoData
 ) AS LONG                                              ' BOOL
#ENDIF

' //
' // Backward compatibility--do not use.
' //
'#define SetupDiInstallInterfaceDevices SetupDiInstallDeviceInterfaces


'#if _SETUPAPI_VER >= _WIN32_WINNT_WINXP
#IF %SETUPAPI_VER >= %WIN32_WINNT_WINXP

DECLARE FUNCTION SetupDiSetDeviceInterfaceDefault IMPORT "SETUPAPI.DLL" ALIAS "SetupDiSetDeviceInterfaceDefault" ( _
   BYVAL DeviceInfoSet AS DWORD _                          ' __in HDEVINFO DeviceInfoSet
 , BYREF DeviceInterfaceData AS SP_DEVICE_INTERFACE_DATA _ ' __inout PSP_DEVICE_INTERFACE_DATA DeviceInterfaceData
 , BYVAL Flags AS DWORD _                                  ' __in DWORD Flags
 , BYVAL Reserved AS DWORD _                               ' __reserved PVOID Reserved
 ) AS LONG                                                 ' BOOL

#ENDIF
'#endif // _SETUPAPI_VER >= _WIN32_WINNT_WINXP


' //
' // Default install handler for DIF_REGISTERDEVICE
' //

' //
' // Flags for SetupDiRegisterDeviceInfo
' //
%SPRDI_FIND_DUPS        = &H00000001???

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SetupDiRegisterDeviceInfo LIB "SetupApi.dll" _
    ALIAS "SetupDiRegisterDeviceInfo" ( _
    BYVAL DeviceInfoSet AS DWORD, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR, _
    BYVAL Flags AS DWORD, _
    BYVAL CompareProc AS DWORD, _  ' PSP_DETSIG_CMPPROC callback
    BYVAL CompareContext AS DWORD, _   ' PVOID
    BYVAL DupDeviceInfoData AS SP_DEVINFO_DATA PTR _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupDiRegisterDeviceInfo IMPORT "SETUPAPI.DLL" ALIAS "SetupDiRegisterDeviceInfo" ( _
   BYVAL DeviceInfoSet AS DWORD _                       ' __in HDEVINFO DeviceInfoSet
 , BYREF DeviceInfoData AS SP_DEVINFO_DATA _            ' __inout PSP_DEVINFO_DATA DeviceInfoData
 , BYVAL Flags AS DWORD _                               ' __in DWORD Flags
 , OPTIONAL BYVAL CompareProc AS DWORD _                ' __in_opt PSP_DETSIG_CMPPROC CompareProc
 , OPTIONAL BYVAL CompareContext AS DWORD _             ' __in_opt PVOID CompareContext
 , OPTIONAL BYREF DupDeviceInfoData AS SP_DEVINFO_DATA _ ' __out_opt PSP_DEVINFO_DATA DupDeviceInfoData
 ) AS LONG                                              ' BOOL
#ENDIF

' //
' // Ordinal values distinguishing between class drivers and
' // device drivers.
' // (Passed in 'DriverType' parameter of driver information list APIs)
' //
%SPDIT_NODRIVER           = &H00000000???
%SPDIT_CLASSDRIVER        = &H00000001???
%SPDIT_COMPATDRIVER       = &H00000002???

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SetupDiBuildDriverInfoList LIB "SetupApi.dll" _
    ALIAS "SetupDiBuildDriverInfoList" ( _
    BYVAL DeviceInfoSet AS DWORD, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR, _
    BYVAL DriverType AS DWORD _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupDiBuildDriverInfoList IMPORT "SETUPAPI.DLL" ALIAS "SetupDiBuildDriverInfoList" ( _
   BYVAL DeviceInfoSet AS DWORD _                       ' __in HDEVINFO DeviceInfoSet
 , BYREF DeviceInfoData AS SP_DEVINFO_DATA _            ' __inout_opt PSP_DEVINFO_DATA DeviceInfoData
 , BYVAL DriverType AS DWORD _                          ' __in DWORD DriverType
 ) AS LONG                                              ' BOOL
#ENDIF

DECLARE FUNCTION SetupDiCancelDriverInfoSearch IMPORT "SETUPAPI.DLL" ALIAS "SetupDiCancelDriverInfoSearch" ( _
   BYVAL DeviceInfoSet AS DWORD _                       ' __in HDEVINFO DeviceInfoSet
 ) AS LONG                                              ' BOOL

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SetupDiEnumDriverInfoA LIB "SetupApi.dll" _
    ALIAS "SetupDiEnumDriverInfoA" ( _
    BYVAL DeviceInfoSet AS DWORD, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR, _
    BYVAL DriverType AS DWORD, _
    BYVAL MemberIndex AS DWORD, _
    BYVAL DriverInfoData AS SP_DRVINFO_DATA_A PTR _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupDiEnumDriverInfoA IMPORT "SETUPAPI.DLL" ALIAS "SetupDiEnumDriverInfoA" ( _
   BYVAL DeviceInfoSet AS DWORD _                       ' __in HDEVINFO DeviceInfoSet
 , BYREF DeviceInfoData AS SP_DEVINFO_DATA _            ' __in_opt PSP_DEVINFO_DATA DeviceInfoData
 , BYVAL DriverType AS DWORD _                          ' __in DWORD DriverType
 , BYVAL MemberIndex AS DWORD _                         ' __in DWORD MemberIndex
 , BYREF DriverInfoData AS SP_DRVINFO_DATA_A _          ' __out PSP_DRVINFO_DATA_A DriverInfoData
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SetupDiEnumDriverInfoW LIB "SetupApi.dll" _
    ALIAS "SetupDiEnumDriverInfoW" ( _
    BYVAL DeviceInfoSet AS DWORD, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR, _
    BYVAL DriverType AS DWORD, _
    BYVAL MemberIndex AS DWORD, _
    BYVAL DriverInfoData AS SP_DRVINFO_DATA_W PTR _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupDiEnumDriverInfoW IMPORT "SETUPAPI.DLL" ALIAS "SetupDiEnumDriverInfoW" ( _
   BYVAL DeviceInfoSet AS DWORD _                       ' __in HDEVINFO DeviceInfoSet
 , BYREF DeviceInfoData AS SP_DEVINFO_DATA _            ' __in_opt PSP_DEVINFO_DATA DeviceInfoData
 , BYVAL DriverType AS DWORD _                          ' __in DWORD DriverType
 , BYVAL MemberIndex AS DWORD _                         ' __in DWORD MemberIndex
 , BYREF DriverInfoData AS SP_DRVINFO_DATA_W _          ' __out PSP_DRVINFO_DATA_W DriverInfoData
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%UNICODE)
   MACRO SetupDiEnumDriverInfo = SetupDiEnumDriverInfoW
#ELSE
   MACRO SetupDiEnumDriverInfo = SetupDiEnumDriverInfoA
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SetupDiGetSelectedDriverA LIB "SetupApi.dll" _
    ALIAS "SetupDiGetSelectedDriverA" ( _
    BYVAL DeviceInfoSet AS DWORD, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR, _
    BYVAL DriverInfoData AS SP_DRVINFO_DATA_A PTR _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupDiGetSelectedDriverA IMPORT "SETUPAPI.DLL" ALIAS "SetupDiGetSelectedDriverA" ( _
   BYVAL DeviceInfoSet AS DWORD _                       ' __in HDEVINFO DeviceInfoSet
 , BYREF DeviceInfoData AS SP_DEVINFO_DATA _            ' __in_opt PSP_DEVINFO_DATA DeviceInfoData
 , BYREF DriverInfoData AS SP_DRVINFO_DATA_A _          ' __out PSP_DRVINFO_DATA_A DriverInfoData
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SetupDiGetSelectedDriverW LIB "SetupApi.dll" _
    ALIAS "SetupDiGetSelectedDriverW" ( _
    BYVAL DeviceInfoSet AS DWORD, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR, _
    BYVAL DriverInfoData AS SP_DRVINFO_DATA_W PTR _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupDiGetSelectedDriverW IMPORT "SETUPAPI.DLL" ALIAS "SetupDiGetSelectedDriverW" ( _
   BYVAL DeviceInfoSet AS DWORD _                       ' __in HDEVINFO DeviceInfoSet
 , BYREF DeviceInfoData AS SP_DEVINFO_DATA _            ' __in_opt PSP_DEVINFO_DATA DeviceInfoData
 , BYREF DriverInfoData AS SP_DRVINFO_DATA_W _          ' __out PSP_DRVINFO_DATA_W DriverInfoData
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%UNICODE)
   MACRO SetupDiGetSelectedDriver = SetupDiGetSelectedDriverW
#ELSE
   MACRO SetupDiGetSelectedDriver = SetupDiGetSelectedDriverA
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SetupDiSetSelectedDriverA LIB "SetupApi.dll" _
    ALIAS "SetupDiSetSelectedDriverA" ( _
    BYVAL DeviceInfoSet AS DWORD, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR, _
    BYVAL DriverInfoData AS SP_DRVINFO_DATA_A PTR _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupDiSetSelectedDriverA IMPORT "SETUPAPI.DLL" ALIAS "SetupDiSetSelectedDriverA" ( _
   BYVAL DeviceInfoSet AS DWORD _                       ' __in HDEVINFO DeviceInfoSet
 , OPTIONAL BYREF DeviceInfoData AS SP_DEVINFO_DATA _   ' __inout_opt PSP_DEVINFO_DATA DeviceInfoData
 , OPTIONAL BYREF DriverInfoData AS SP_DRVINFO_DATA_A _ ' __inout_opt PSP_DRVINFO_DATA_A DriverInfoData
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SetupDiSetSelectedDriverW LIB "SetupApi.dll" _
    ALIAS "SetupDiSetSelectedDriverW" ( _
    BYVAL DeviceInfoSet AS DWORD, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR, _
    BYVAL DriverInfoData AS SP_DRVINFO_DATA_W PTR _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupDiSetSelectedDriverW IMPORT "SETUPAPI.DLL" ALIAS "SetupDiSetSelectedDriverW" ( _
   BYVAL DeviceInfoSet AS DWORD _                       ' __in HDEVINFO DeviceInfoSet
 , OPTIONAL BYREF DeviceInfoData AS SP_DEVINFO_DATA _   ' __inout_opt PSP_DEVINFO_DATA DeviceInfoData
 , OPTIONAL BYREF DriverInfoData AS SP_DRVINFO_DATA_W _ ' __inout_opt PSP_DRVINFO_DATA_W DriverInfoData
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%UNICODE)
   MACRO SetupDiSetSelectedDriver = SetupDiSetSelectedDriverW
#ELSE
   MACRO SetupDiSetSelectedDriver = SetupDiSetSelectedDriverA
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SetupDiGetDriverInfoDetailA LIB "SetupApi.dll" _
    ALIAS "SetupDiGetDriverInfoDetailA" ( _
    BYVAL DeviceInfoSet AS DWORD, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR, _
    BYVAL DriverInfoData AS SP_DRVINFO_DATA_A PTR, _
    BYVAL DriverInfoDetailData AS SP_DRVINFO_DETAIL_DATA_A PTR, _
    BYVAL DriverInfoDetailDataSize AS DWORD, _
    RequiredSize AS DWORD _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupDiGetDriverInfoDetailA IMPORT "SETUPAPI.DLL" ALIAS "SetupDiGetDriverInfoDetailA" ( _
   BYVAL DeviceInfoSet AS DWORD _                       ' __in HDEVINFO DeviceInfoSet
 , BYREF DeviceInfoData AS SP_DEVINFO_DATA _            ' __in_opt PSP_DEVINFO_DATA DeviceInfoData
 , BYREF DriverInfoData AS SP_DRVINFO_DATA_A _          ' __in PSP_DRVINFO_DATA_A DriverInfoData
 , BYREF DriverInfoDetailData AS ANY _                  ' __inout PSP_DRVINFO_DETAIL_DATA_A DriverInfoDetailData
 , BYVAL DriverInfoDetailDataSize AS DWORD _            ' __in DWORD DriverInfoDetailDataSize
 , OPTIONAL BYREF RequiredSize AS DWORD _               ' __out_opt PDWORD RequiredSize
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SetupDiGetDriverInfoDetailW LIB "SetupApi.dll" _
    ALIAS "SetupDiGetDriverInfoDetailW" ( _
    BYVAL DeviceInfoSet AS DWORD, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR, _
    BYVAL DriverInfoData AS SP_DRVINFO_DATA_W PTR, _
    BYVAL DriverInfoDetailData AS SP_DRVINFO_DETAIL_DATA_W PTR, _
    BYVAL DriverInfoDetailDataSize AS DWORD, _
    RequiredSize AS DWORD _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupDiGetDriverInfoDetailW IMPORT "SETUPAPI.DLL" ALIAS "SetupDiGetDriverInfoDetailW" ( _
   BYVAL DeviceInfoSet AS DWORD _                       ' __in HDEVINFO DeviceInfoSet
 , BYREF DeviceInfoData AS SP_DEVINFO_DATA _            ' __in_opt PSP_DEVINFO_DATA DeviceInfoData
 , BYREF DriverInfoData AS SP_DRVINFO_DATA_W _          ' __in PSP_DRVINFO_DATA_W DriverInfoData
 , BYREF DriverInfoDetailData AS ANY _                  ' __inout PSP_DRVINFO_DETAIL_DATA_W DriverInfoDetailData
 , BYVAL DriverInfoDetailDataSize AS DWORD _            ' __in DWORD DriverInfoDetailDataSize
 , OPTIONAL BYREF RequiredSize AS DWORD _               ' __out_opt PDWORD RequiredSize
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%UNICODE)
   MACRO SetupDiGetDriverInfoDetail = SetupDiGetDriverInfoDetailW
#ELSE
   MACRO SetupDiGetDriverInfoDetail = SetupDiGetDriverInfoDetailA
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SetupDiDestroyDriverInfoList LIB "SetupApi.dll" _
    ALIAS "SetupDiDestroyDriverInfoList" ( _
    BYVAL DeviceInfoSet AS DWORD, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR, _
    BYVAL DriverType AS DWORD _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupDiDestroyDriverInfoList IMPORT "SETUPAPI.DLL" ALIAS "SetupDiDestroyDriverInfoList" ( _
   BYVAL DeviceInfoSet AS DWORD _                       ' __in HDEVINFO DeviceInfoSet
 , BYREF DeviceInfoData AS SP_DEVINFO_DATA _            ' __in_opt PSP_DEVINFO_DATA DeviceInfoData
 , BYVAL DriverType AS DWORD _                          ' __in DWORD DriverType
 ) AS LONG                                              ' BOOL
#ENDIF

' //
' // Flags controlling what is included in the device information set built
' // by SetupDiGetClassDevs
' //
%DIGCF_DEFAULT           = &H00000001???    ' // only valid with DIGCF_DEVICEINTERFACE
%DIGCF_PRESENT           = &H00000002???
%DIGCF_ALLCLASSES        = &H00000004???
%DIGCF_PROFILE           = &H00000008???
%DIGCF_DEVICEINTERFACE   = &H00000010???

' //
' // Backward compatibility--do not use.
' //
%DIGCF_INTERFACEDEVICE = %DIGCF_DEVICEINTERFACE


DECLARE FUNCTION SetupDiGetClassDevsA IMPORT "SETUPAPI.DLL" ALIAS "SetupDiGetClassDevsA" ( _
   BYREF ClassGuid AS GUID _                            ' __in_opt CONST GUID *ClassGuid
 , BYREF Enumerator AS ASCIIZ _                         ' __in_opt PCSTR Enumerator
 , BYVAL hwndParent AS DWORD _                          ' __in_opt HWND hwndParent
 , BYVAL Flags AS DWORD _                               ' __in DWORD Flags
 ) AS DWORD                                             ' HDEVINFO

DECLARE FUNCTION SetupDiGetClassDevsW IMPORT "SETUPAPI.DLL" ALIAS "SetupDiGetClassDevsW" ( _
   BYREF ClassGuid AS GUID _                            ' __in_opt CONST GUID *ClassGuid
 , BYREF Enumerator AS WSTRINGZ _                       ' __in_opt PCWSTR Enumerator
 , BYVAL hwndParent AS DWORD _                          ' __in_opt HWND hwndParent
 , BYVAL Flags AS DWORD _                               ' __in DWORD Flags
 ) AS DWORD                                             ' HDEVINFO

#IF %DEF(%UNICODE)
   MACRO SetupDiGetClassDevs = SetupDiGetClassDevsW
#ELSE
   MACRO SetupDiGetClassDevs = SetupDiGetClassDevsA
#ENDIF

DECLARE FUNCTION SetupDiGetClassDevsExA IMPORT "SETUPAPI.DLL" ALIAS "SetupDiGetClassDevsExA" ( _
   BYREF ClassGuid AS GUID _                            ' __in_opt CONST GUID *ClassGuid
 , BYREF Enumerator AS ASCIIZ _                         ' __in_opt PCSTR Enumerator
 , BYVAL hwndParent AS DWORD _                          ' __in_opt HWND hwndParent
 , BYVAL Flags AS DWORD _                               ' __in DWORD Flags
 , OPTIONAL BYVAL DeviceInfoSet AS DWORD _              ' __in_opt HDEVINFO DeviceInfoSet
 , OPTIONAL BYREF MachineName AS ASCIIZ _               ' __in_opt PCSTR MachineName
 , OPTIONAL BYVAL Reserved AS DWORD _                   ' __reserved PVOID Reserved
 ) AS DWORD                                             ' HDEVINFO

DECLARE FUNCTION SetupDiGetClassDevsExW IMPORT "SETUPAPI.DLL" ALIAS "SetupDiGetClassDevsExW" ( _
   BYREF ClassGuid AS GUID _                            ' __in_opt CONST GUID *ClassGuid
 , BYREF Enumerator AS WSTRINGZ _                       ' __in_opt PCWSTR Enumerator
 , BYVAL hwndParent AS DWORD _                          ' __in_opt HWND hwndParent
 , BYVAL Flags AS DWORD _                               ' __in DWORD Flags
 , OPTIONAL BYVAL DeviceInfoSet AS DWORD _              ' __in_opt HDEVINFO DeviceInfoSet
 , OPTIONAL BYREF MachineName AS WSTRINGZ _             ' __in_opt PCWSTR MachineName
 , OPTIONAL BYVAL Reserved AS DWORD _                   ' __reserved PVOID Reserved
 ) AS DWORD                                             ' HDEVINFO

#IF %DEF(%UNICODE)
   MACRO SetupDiGetClassDevsEx = SetupDiGetClassDevsExW
#ELSE
   MACRO SetupDiGetClassDevsEx = SetupDiGetClassDevsExA
#ENDIF

DECLARE FUNCTION SetupDiGetINFClassA IMPORT "SETUPAPI.DLL" ALIAS "SetupDiGetINFClassA" ( _
   BYREF InfName AS ASCIIZ _                            ' __in PCSTR InfName
 , BYREF ClassGuid AS GUID _                            ' __out LPGUID ClassGuid
 , BYREF ClassName AS ASCIIZ _                          ' __out PSTR ClassName
 , BYVAL ClassNameSize AS DWORD _                       ' __in DWORD ClassNameSize
 , OPTIONAL BYREF RequiredSize AS DWORD _               ' __out_opt PDWORD RequiredSize
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SetupDiGetINFClassW IMPORT "SETUPAPI.DLL" ALIAS "SetupDiGetINFClassW" ( _
   BYREF InfName AS WSTRINGZ _                          ' __in PCWSTR InfName
 , BYREF ClassGuid AS GUID _                            ' __out LPGUID ClassGuid
 , BYREF ClassName AS WSTRINGZ _                        ' __out PWSTR ClassName
 , BYVAL ClassNameSize AS DWORD _                       ' __in DWORD ClassNameSize
 , OPTIONAL BYREF RequiredSize AS DWORD _               ' __out_opt PDWORD RequiredSize
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO SetupDiGetINFClass = SetupDiGetINFClassW
#ELSE
   MACRO SetupDiGetINFClass = SetupDiGetINFClassA
#ENDIF

' //
' // Flags controlling exclusion from the class information list built
' // by SetupDiBuildClassInfoList(Ex)
' //
%DIBCI_NOINSTALLCLASS   = &H00000001???
%DIBCI_NODISPLAYCLASS   = &H00000002???

DECLARE FUNCTION SetupDiBuildClassInfoList IMPORT "SETUPAPI.DLL" ALIAS "SetupDiBuildClassInfoList" ( _
   BYVAL Flags AS DWORD _                               ' __in DWORD Flags
 , BYREF ClassGuidList AS GUID _                        ' __out LPGUID ClassGuidList
 , BYVAL ClassGuidListSize AS DWORD _                   ' __in DWORD ClassGuidListSize
 , BYREF RequiredSize AS DWORD _                        ' __out PDWORD RequiredSize
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SetupDiBuildClassInfoListExA IMPORT "SETUPAPI.DLL" ALIAS "SetupDiBuildClassInfoListExA" ( _
   BYVAL Flags AS DWORD _                               ' __in DWORD Flags
 , BYREF ClassGuidList AS GUID _                        ' __out LPGUID ClassGuidList
 , BYVAL ClassGuidListSize AS DWORD _                   ' __in DWORD ClassGuidListSize
 , BYREF RequiredSize AS DWORD _                        ' __out PDWORD RequiredSize
 , OPTIONAL BYREF MachineName AS ASCIIZ _               ' __in_opt PCSTR MachineName
 , OPTIONAL BYVAL Reserved AS DWORD _                   ' __reserved PVOID Reserved
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SetupDiBuildClassInfoListExW IMPORT "SETUPAPI.DLL" ALIAS "SetupDiBuildClassInfoListExW" ( _
   BYVAL Flags AS DWORD _                               ' __in DWORD Flags
 , BYREF ClassGuidList AS GUID _                        ' __out LPGUID ClassGuidList
 , BYVAL ClassGuidListSize AS DWORD _                   ' __in DWORD ClassGuidListSize
 , BYREF RequiredSize AS DWORD _                        ' __out PDWORD RequiredSize
 , OPTIONAL BYREF MachineName AS WSTRINGZ _             ' __in_opt PCWSTR MachineName
 , OPTIONAL BYVAL Reserved AS DWORD _                   ' __reserved PVOID Reserved
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO SetupDiBuildClassInfoListEx = SetupDiBuildClassInfoListExW
#ELSE
   MACRO SetupDiBuildClassInfoListEx = SetupDiBuildClassInfoListExA
#ENDIF

DECLARE FUNCTION SetupDiGetClassDescriptionA IMPORT "SETUPAPI.DLL" ALIAS "SetupDiGetClassDescriptionA" ( _
   BYREF ClassGuid AS GUID _                            ' __in CONST GUID *ClassGuid
 , BYREF ClassDescription AS ASCIIZ _                   ' __out PSTR ClassDescription
 , BYVAL ClassDescriptionSize AS DWORD _                ' __in DWORD ClassDescriptionSize
 , OPTIONAL BYREF RequiredSize AS DWORD _               ' __out_opt PDWORD RequiredSize
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SetupDiGetClassDescriptionW IMPORT "SETUPAPI.DLL" ALIAS "SetupDiGetClassDescriptionW" ( _
   BYREF ClassGuid AS GUID _                            ' __in CONST GUID *ClassGuid
 , BYREF ClassDescription AS WSTRINGZ _                 ' __out PWSTR ClassDescription
 , BYVAL ClassDescriptionSize AS DWORD _                ' __in DWORD ClassDescriptionSize
 , OPTIONAL BYREF RequiredSize AS DWORD _               ' __out_opt PDWORD RequiredSize
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO SetupDiGetClassDescription = SetupDiGetClassDescriptionW
#ELSE
   MACRO SetupDiGetClassDescription = SetupDiGetClassDescriptionA
#ENDIF

DECLARE FUNCTION SetupDiGetClassDescriptionExA IMPORT "SETUPAPI.DLL" ALIAS "SetupDiGetClassDescriptionExA" ( _
   BYREF ClassGuid AS GUID _                            ' __in CONST GUID *ClassGuid
 , BYREF ClassDescription AS ASCIIZ _                   ' __out PSTR ClassDescription
 , BYVAL ClassDescriptionSize AS DWORD _                ' __in DWORD ClassDescriptionSize
 , OPTIONAL BYREF RequiredSize AS DWORD _               ' __out_opt PDWORD RequiredSize
 , OPTIONAL BYREF MachineName AS ASCIIZ _               ' __in_opt PCSTR MachineName
 , OPTIONAL BYVAL Reserved AS DWORD _                   ' __reserved PVOID Reserved
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SetupDiGetClassDescriptionExW IMPORT "SETUPAPI.DLL" ALIAS "SetupDiGetClassDescriptionExW" ( _
   BYREF ClassGuid AS GUID _                            ' __in CONST GUID *ClassGuid
 , BYREF ClassDescription AS WSTRINGZ _                 ' __out PWSTR ClassDescription
 , BYVAL ClassDescriptionSize AS DWORD _                ' __in DWORD ClassDescriptionSize
 , OPTIONAL BYREF RequiredSize AS DWORD _               ' __out_opt PDWORD RequiredSize
 , OPTIONAL BYREF MachineName AS WSTRINGZ  _            ' __in_opt PCWSTR MachineName
 , OPTIONAL BYVAL Reserved AS DWORD _                   ' __reserved PVOID Reserved
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO SetupDiGetClassDescriptionEx = SetupDiGetClassDescriptionExW
#ELSE
   MACRO SetupDiGetClassDescriptionEx = SetupDiGetClassDescriptionExA
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SetupDiCallClassInstaller LIB "SetupApi.dll" _
    ALIAS "SetupDiCallClassInstaller" ( _
    BYVAL InstallFunction AS DWORD, _
    BYVAL DeviceInfoSet AS DWORD, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupDiCallClassInstaller IMPORT "SETUPAPI.DLL" ALIAS "SetupDiCallClassInstaller" ( _
   BYVAL InstallFunction AS DWORD _                     ' __in DI_FUNCTION InstallFunction
 , BYVAL DeviceInfoSet AS DWORD _                       ' __in HDEVINFO DeviceInfoSet
 , OPTIONAL BYREF DeviceInfoData AS SP_DEVINFO_DATA _   ' __in_opt PSP_DEVINFO_DATA DeviceInfoData
 ) AS LONG                                              ' BOOL
#ENDIF

' //
' // Default install handler for DIF_SELECTDEVICE
' //

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SetupDiSelectDevice LIB "SetupApi.dll" _
    ALIAS "SetupDiSelectDevice" ( _
    BYVAL DeviceInfoSet AS DWORD, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupDiSelectDevice IMPORT "SETUPAPI.DLL" ALIAS "SetupDiSelectDevice" ( _
   BYVAL DeviceInfoSet AS DWORD _                       ' __in HDEVINFO DeviceInfoSet
 , OPTIONAL BYREF DeviceInfoData AS SP_DEVINFO_DATA _   ' __inout_opt PSP_DEVINFO_DATA DeviceInfoData
 ) AS LONG                                              ' BOOL
#ENDIF

' //
' // Default install handler for DIF_SELECTBESTCOMPATDRV
' //

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SetupDiSelectBestCompatDrv LIB "SetupApi.dll" _
    ALIAS "SetupDiSelectBestCompatDrv" ( _
    BYVAL DeviceInfoSet AS DWORD, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupDiSelectBestCompatDrv IMPORT "SETUPAPI.DLL" ALIAS "SetupDiSelectBestCompatDrv" ( _
   BYVAL DeviceInfoSet AS DWORD _                       ' __in HDEVINFO DeviceInfoSet
 , OPTIONAL BYREF DeviceInfoData AS SP_DEVINFO_DATA _   ' __inout_opt PSP_DEVINFO_DATA DeviceInfoData
 ) AS LONG                                              ' BOOL
#ENDIF

' //
' // Default install handler for DIF_INSTALLDEVICE
' //

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SetupDiInstallDevice LIB "SetupApi.dll" _
    ALIAS "SetupDiInstallDevice" ( _
    BYVAL DeviceInfoSet AS DWORD, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupDiInstallDevice IMPORT "SETUPAPI.DLL" ALIAS "SetupDiInstallDevice" ( _
   BYVAL DeviceInfoSet AS DWORD _                       ' __in HDEVINFO DeviceInfoSet
 , OPTIONAL BYREF DeviceInfoData AS SP_DEVINFO_DATA _   ' __inout_opt PSP_DEVINFO_DATA DeviceInfoData
 ) AS LONG                                              ' BOOL
#ENDIF

' //
' // Default install handler for DIF_INSTALLDEVICEFILES
' //

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SetupDiInstallDriverFiles LIB "SetupApi.dll" _
    ALIAS "SetupDiInstallDriverFiles" ( _
    BYVAL DeviceInfoSet AS DWORD, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupDiInstallDriverFiles IMPORT "SETUPAPI.DLL" ALIAS "SetupDiInstallDriverFiles" ( _
   BYVAL DeviceInfoSet AS DWORD _                       ' __in HDEVINFO DeviceInfoSet
 , BYREF DeviceInfoData AS SP_DEVINFO_DATA _            ' __in PSP_DEVINFO_DATA DeviceInfoData
 ) AS LONG                                              ' BOOL
#ENDIF

' //
' // Default install handler for DIF_REGISTER_COINSTALLERS
' //

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SetupDiRegisterCoDeviceInstallers LIB "SetupApi.dll" _
    ALIAS "SetupDiRegisterCoDeviceInstallers" ( _
    BYVAL DeviceInfoSet AS DWORD, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupDiRegisterCoDeviceInstallers IMPORT "SETUPAPI.DLL" ALIAS "SetupDiRegisterCoDeviceInstallers" ( _
   BYVAL DeviceInfoSet AS DWORD _                       ' __in HDEVINFO DeviceInfoSet
 , BYREF DeviceInfoData AS SP_DEVINFO_DATA _            ' __in PSP_DEVINFO_DATA DeviceInfoData
 ) AS LONG                                              ' BOOL
#ENDIF

' //
' // Default install handler for DIF_REMOVE
' //

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SetupDiRemoveDevice LIB "SetupApi.dll" _
    ALIAS "SetupDiRemoveDevice" ( _
    BYVAL DeviceInfoSet AS DWORD, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupDiRemoveDevice IMPORT "SETUPAPI.DLL" ALIAS "SetupDiRemoveDevice" ( _
   BYVAL DeviceInfoSet AS DWORD _                       ' __in HDEVINFO DeviceInfoSet
 , BYREF DeviceInfoData AS SP_DEVINFO_DATA _            ' __inout PSP_DEVINFO_DATA DeviceInfoData
 ) AS LONG                                              ' BOOL
#ENDIF

' //
' // Default install handler for DIF_UNREMOVE
' //

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SetupDiUnremoveDevice LIB "SetupApi.dll" _
    ALIAS "SetupDiUnremoveDevice" ( _
    BYVAL DeviceInfoSet AS DWORD, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupDiUnremoveDevice IMPORT "SETUPAPI.DLL" ALIAS "SetupDiUnremoveDevice" ( _
   BYVAL DeviceInfoSet AS DWORD _                       ' __in HDEVINFO DeviceInfoSet
 , BYREF DeviceInfoData AS SP_DEVINFO_DATA _            ' __inout PSP_DEVINFO_DATA DeviceInfoData
 ) AS LONG                                              ' BOOL
#ENDIF

'#if _SETUPAPI_VER >= _WIN32_WINNT_WS03
#IF %SETUPAPI_VER >= %WIN32_WINNT_WS03

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SetupDiRestartDevices LIB "SetupApi.dll" _
    ALIAS "SetupDiRestartDevices" ( _
    BYVAL DeviceInfoSet AS DWORD, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupDiRestartDevices IMPORT "SETUPAPI.DLL" ALIAS "SetupDiRestartDevices" ( _
   BYVAL DeviceInfoSet AS DWORD _                       ' __in HDEVINFO DeviceInfoSet
 , BYREF DeviceInfoData AS SP_DEVINFO_DATA _            ' __inout PSP_DEVINFO_DATA DeviceInfoData
 ) AS LONG                                              ' BOOL
#ENDIF

#ENDIF
'#endif // _SETUPAPI_VER >= _WIN32_WINNT_WS03

' //
' // Default install handler for DIF_PROPERTYCHANGE
' //

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SetupDiChangeState LIB "SetupApi.dll" _
    ALIAS "SetupDiChangeState" ( _
    BYVAL DeviceInfoSet AS DWORD, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupDiChangeState IMPORT "SETUPAPI.DLL" ALIAS "SetupDiChangeState" ( _
   BYVAL DeviceInfoSet AS DWORD _                       ' __in HDEVINFO DeviceInfoSet
 , BYREF DeviceInfoData AS SP_DEVINFO_DATA _            ' __inout PSP_DEVINFO_DATA DeviceInfoData
 ) AS LONG                                              ' BOOL
#ENDIF


'#if _SETUPAPI_VER >= _WIN32_WINNT_LONGHORN
#IF %SETUPAPI_VER >= %WIN32_WINNT_LONGHORN

'//
'// Default install handler for DIF_FINISHINSTALL_ACTION
'//
#IF %DEF(%USEPBDECL)
' [does not appear to be exported]
'DECLARE FUNCTION SetupDiFinishInstallAction LIB "SetupApi.dll" _
'    ALIAS "SetupDiFinishInstallAction" ( _
'    BYVAL DeviceInfoSet AS DWORD, _
'    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR _
'    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupDiFinishInstallAction IMPORT "SETUPAPI.DLL" ALIAS "SetupDiFinishInstallAction" ( _
   BYVAL DeviceInfoSet AS DWORD _                       ' __in HDEVINFO DeviceInfoSet
 , BYREF DeviceInfoData AS SP_DEVINFO_DATA _            ' __in PSP_DEVINFO_DATA DeviceInfoData
 ) AS LONG                                              ' BOOL
#ENDIF

#ENDIF
'#endif // _SETUPAPI_VER >= _WIN32_WINNT_LONGHORN

DECLARE FUNCTION SetupDiInstallClassA IMPORT "SETUPAPI.DLL" ALIAS "SetupDiInstallClassA" ( _
   BYVAL hwndParent AS DWORD _                          ' __in_opt HWND hwndParent
 , BYREF InfFileName AS ASCIIZ _                        ' __in PCSTR InfFileName
 , BYVAL Flags AS DWORD _                               ' __in DWORD Flags
 , OPTIONAL BYVAL FileQueue AS DWORD _                  ' __in_opt HSPFILEQ FileQueue
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SetupDiInstallClassW IMPORT "SETUPAPI.DLL" ALIAS "SetupDiInstallClassW" ( _
   BYVAL hwndParent AS DWORD _                          ' __in_opt HWND hwndParent
 , BYREF InfFileName AS WSTRINGZ _                      ' __in PCWSTR InfFileName
 , BYVAL Flags AS DWORD _                               ' __in DWORD Flags
 , OPTIONAL BYVAL FileQueue AS DWORD _                  ' __in_opt HSPFILEQ FileQueue
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO SetupDiInstallClass = SetupDiInstallClassW
#ELSE
   MACRO SetupDiInstallClass = SetupDiInstallClassA
#ENDIF

DECLARE FUNCTION SetupDiInstallClassExA IMPORT "SETUPAPI.DLL" ALIAS "SetupDiInstallClassExA" ( _
   BYVAL hwndParent AS DWORD _                          ' __in_opt HWND hwndParent
 , BYREF InfFileName AS ASCIIZ _                        ' __in_opt PCSTR InfFileName
 , BYVAL Flags AS DWORD _                               ' __in DWORD Flags
 , OPTIONAL BYVAL FileQueue AS DWORD _                  ' __in_opt HSPFILEQ FileQueue
 , OPTIONAL BYREF InterfaceClassGuid AS GUID _          ' __in_opt CONST GUID *InterfaceClassGuid
 , OPTIONAL BYVAL Reserved1 AS DWORD _                  ' __reserved PVOID Reserved1
 , OPTIONAL BYVAL Reserved2 AS DWORD _                  ' __reserved PVOID Reserved2
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SetupDiInstallClassExW IMPORT "SETUPAPI.DLL" ALIAS "SetupDiInstallClassExW" ( _
   BYVAL hwndParent AS DWORD _                          ' __in_opt HWND hwndParent
 , BYREF InfFileName AS WSTRINGZ _                      ' __in_opt PCWSTR InfFileName
 , BYVAL Flags AS DWORD _                               ' __in DWORD Flags
 , OPTIONAL BYVAL FileQueue AS DWORD _                  ' __in_opt HSPFILEQ FileQueue
 , OPTIONAL BYREF InterfaceClassGuid AS GUID _          ' __in_opt CONST GUID *InterfaceClassGuid
 , OPTIONAL BYVAL Reserved1 AS DWORD _                  ' __reserved PVOID Reserved1
 , OPTIONAL BYVAL Reserved2 AS DWORD _                  ' __reserved PVOID Reserved2
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO SetupDiInstallClassEx = SetupDiInstallClassExW
#ELSE
   MACRO SetupDiInstallClassEx = SetupDiInstallClassExA
#ENDIF

DECLARE FUNCTION SetupDiOpenClassRegKey IMPORT "SETUPAPI.DLL" ALIAS "SetupDiOpenClassRegKey" ( _
   BYREF ClassGuid AS GUID _                            ' __in_opt CONST GUID *ClassGuid
 , BYVAL samDesired AS REGSAM _                         ' __in REGSAM samDesired
 ) AS DWORD                                             ' HKEY

' //
' // Flags for SetupDiOpenClassRegKeyEx
' //
%DIOCR_INSTALLER   = &H00000001???    ' // class installer registry branch
%DIOCR_INTERFACE   = &H00000002???    ' // interface class registry branch

DECLARE FUNCTION SetupDiOpenClassRegKeyExA IMPORT "SETUPAPI.DLL" ALIAS "SetupDiOpenClassRegKeyExA" ( _
   BYREF ClassGuid AS GUID _                            ' __in_opt CONST GUID *ClassGuid
 , BYVAL samDesired AS REGSAM _                         ' __in REGSAM samDesired
 , BYVAL Flags AS DWORD _                               ' __in DWORD Flags
 , OPTIONAL BYREF MachineName AS ASCIIZ _               ' __in_opt PCSTR MachineName
 , OPTIONAL BYVAL Reserved AS DWORD _                   ' __reserved PVOID Reserved
 ) AS DWORD                                             ' HKEY

DECLARE FUNCTION SetupDiOpenClassRegKeyExW IMPORT "SETUPAPI.DLL" ALIAS "SetupDiOpenClassRegKeyExW" ( _
   BYREF ClassGuid AS GUID _                            ' __in_opt CONST GUID *ClassGuid
 , BYVAL samDesired AS REGSAM _                         ' __in REGSAM samDesired
 , BYVAL Flags AS DWORD _                               ' __in DWORD Flags
 , OPTIONAL BYREF MachineName AS WSTRINGZ _             ' __in_opt PCWSTR MachineName
 , OPTIONAL BYVAL Reserved AS DWORD _                   ' __reserved PVOID Reserved
 ) AS DWORD                                             ' HKEY

#IF %DEF(%UNICODE)
   MACRO SetupDiOpenClassRegKeyEx = SetupDiOpenClassRegKeyExW
#ELSE
   MACRO SetupDiOpenClassRegKeyEx = SetupDiOpenClassRegKeyExA
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SetupDiCreateDeviceInterfaceRegKeyA LIB "SetupApi.dll" _
    ALIAS "SetupDiCreateDeviceInterfaceRegKeyA" ( _
    BYVAL DeviceInfoSet AS DWORD, _
    BYVAL DeviceInterfaceData AS SP_DEVICE_INTERFACE_DATA PTR, _
    BYVAL Reserved AS DWORD, _
    BYVAL samDesired AS REGSAM, _
    BYVAL InfHandle AS DWORD, _
    InfSectionName AS ASCIIZ _
    ) AS DWORD  ' HKEY
#ELSE
DECLARE FUNCTION SetupDiCreateDeviceInterfaceRegKeyA IMPORT "SETUPAPI.DLL" ALIAS "SetupDiCreateDeviceInterfaceRegKeyA" ( _
   BYVAL DeviceInfoSet AS DWORD _                       ' __in HDEVINFO DeviceInfoSet
 , BYREF DeviceInterfaceData AS SP_DEVICE_INTERFACE_DATA _ ' __in PSP_DEVICE_INTERFACE_DATA DeviceInterfaceData
 , BYVAL Reserved AS DWORD _                            ' __reserved DWORD Reserved
 , BYVAL samDesired AS REGSAM _                         ' __in REGSAM samDesired
 , OPTIONAL BYVAL InfHandle AS DWORD _                  ' __in_opt HINF InfHandle
 , OPTIONAL BYREF InfSectionName AS ASCIIZ _            ' __in_opt PCSTR InfSectionName
 ) AS DWORD                                             ' HKEY
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SetupDiCreateDeviceInterfaceRegKeyW LIB "SetupApi.dll" _
    ALIAS "SetupDiCreateDeviceInterfaceRegKeyW" ( _
    BYVAL DeviceInfoSet AS DWORD, _
    BYVAL DeviceInterfaceData AS SP_DEVICE_INTERFACE_DATA PTR, _
    BYVAL Reserved AS DWORD, _
    BYVAL samDesired AS REGSAM, _
    BYVAL InfHandle AS DWORD, _
    InfSectionName AS WSTRINGZ _
    ) AS DWORD  ' HKEY
#ELSE
DECLARE FUNCTION SetupDiCreateDeviceInterfaceRegKeyW IMPORT "SETUPAPI.DLL" ALIAS "SetupDiCreateDeviceInterfaceRegKeyW" ( _
   BYVAL DeviceInfoSet AS DWORD _                       ' __in HDEVINFO DeviceInfoSet
 , BYREF DeviceInterfaceData AS SP_DEVICE_INTERFACE_DATA _ ' __in PSP_DEVICE_INTERFACE_DATA DeviceInterfaceData
 , BYVAL Reserved AS DWORD _                            ' __reserved DWORD Reserved
 , BYVAL samDesired AS REGSAM _                         ' __in REGSAM samDesired
 , OPTIONAL BYVAL InfHandle AS DWORD _                  ' __in_opt HINF InfHandle
 , OPTIONAL BYREF InfSectionName AS WSTRINGZ _          ' __in_opt PCWSTR InfSectionName
 ) AS DWORD                                             ' HKEY
#ENDIF

#IF %DEF(%UNICODE)
   MACRO SetupDiCreateDeviceInterfaceRegKey = SetupDiCreateDeviceInterfaceRegKeyW
#ELSE
   MACRO SetupDiCreateDeviceInterfaceRegKey = SetupDiCreateDeviceInterfaceRegKeyA
#ENDIF

' //
' // Backward compatibility--do not use.
' //
'#define SetupDiCreateInterfaceDeviceRegKeyW SetupDiCreateDeviceInterfaceRegKeyW
'#define SetupDiCreateInterfaceDeviceRegKeyA SetupDiCreateDeviceInterfaceRegKeyA

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SetupDiOpenDeviceInterfaceRegKey LIB "SetupApi.dll" _
    ALIAS "SetupDiOpenDeviceInterfaceRegKey" ( _
    BYVAL DeviceInfoSet AS DWORD, _
    BYVAL DeviceInterfaceData AS SP_DEVICE_INTERFACE_DATA PTR, _
    BYVAL Reserved AS DWORD, _
    BYVAL samDesired AS REGSAM _
    ) AS DWORD  ' HKEY
#ELSE
DECLARE FUNCTION SetupDiOpenDeviceInterfaceRegKey IMPORT "SETUPAPI.DLL" ALIAS "SetupDiOpenDeviceInterfaceRegKey" ( _
   BYVAL DeviceInfoSet AS DWORD _                       ' __in HDEVINFO DeviceInfoSet
 , BYREF DeviceInterfaceData AS SP_DEVICE_INTERFACE_DATA _ ' __in PSP_DEVICE_INTERFACE_DATA DeviceInterfaceData
 , BYVAL Reserved AS DWORD _                            ' __reserved DWORD Reserved
 , BYVAL samDesired AS REGSAM _                         ' __in REGSAM samDesired
 ) AS DWORD                                             ' HKEY
#ENDIF

' //
' // Backward compatibility--do not use.
' //
'#define SetupDiOpenInterfaceDeviceRegKey SetupDiOpenDeviceInterfaceRegKey

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SetupDiDeleteDeviceInterfaceRegKey LIB "SetupApi.dll" _
    ALIAS "SetupDiDeleteDeviceInterfaceRegKey" ( _
    BYVAL DeviceInfoSet AS DWORD, _
    BYVAL DeviceInterfaceData AS SP_DEVICE_INTERFACE_DATA PTR, _
    BYVAL Reserved AS DWORD _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupDiDeleteDeviceInterfaceRegKey IMPORT "SETUPAPI.DLL" ALIAS "SetupDiDeleteDeviceInterfaceRegKey" ( _
   BYVAL DeviceInfoSet AS DWORD _                       ' __in HDEVINFO DeviceInfoSet
 , BYREF DeviceInterfaceData AS SP_DEVICE_INTERFACE_DATA _ ' __in PSP_DEVICE_INTERFACE_DATA DeviceInterfaceData
 , BYVAL Reserved AS DWORD _                            ' __reserved DWORD Reserved
 ) AS LONG                                              ' BOOL
#ENDIF

' //
' // Backward compatibility--do not use.
' //
'#define SetupDiDeleteInterfaceDeviceRegKey SetupDiDeleteDeviceInterfaceRegKey


' //
' // KeyType values for SetupDiCreateDevRegKey, SetupDiOpenDevRegKey, and
' // SetupDiDeleteDevRegKey.
' //
%DIREG_DEV       = &H00000001???          ' // Open/Create/Delete device key
%DIREG_DRV       = &H00000002???          ' // Open/Create/Delete driver key
%DIREG_BOTH      = &H00000004???          ' // Delete both driver and Device key

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SetupDiCreateDevRegKeyA LIB "SetupApi.dll" _
    ALIAS "SetupDiCreateDevRegKeyA" ( _
    BYVAL DeviceInfoSet AS DWORD, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR, _
    BYVAL Scope AS DWORD, _
    BYVAL HwProfile AS DWORD, _
    BYVAL KeyType AS DWORD, _
    BYVAL InfHandle AS DWORD, _
    InfSectionName AS ASCIIZ _
    ) AS DWORD  ' HKEY
#ELSE
DECLARE FUNCTION SetupDiCreateDevRegKeyA IMPORT "SETUPAPI.DLL" ALIAS "SetupDiCreateDevRegKeyA" ( _
   BYVAL DeviceInfoSet AS DWORD _                       ' __in HDEVINFO DeviceInfoSet
 , BYREF DeviceInfoData AS SP_DEVINFO_DATA _            ' __in PSP_DEVINFO_DATA DeviceInfoData
 , BYVAL Scope AS DWORD _                               ' __in DWORD Scope
 , BYVAL HwProfile AS DWORD _                           ' __in DWORD HwProfile
 , BYVAL KeyType AS DWORD _                             ' __in DWORD KeyType
 , OPTIONAL BYVAL InfHandle AS DWORD _                  ' __in_opt HINF InfHandle
 , OPTIONAL BYREF InfSectionName AS ASCIIZ _            ' __in_opt PCSTR InfSectionName
 ) AS DWORD                                             ' HKEY
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SetupDiCreateDevRegKeyW LIB "SetupApi.dll" _
    ALIAS "SetupDiCreateDevRegKeyW" ( _
    BYVAL DeviceInfoSet AS DWORD, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR, _
    BYVAL Scope AS DWORD, _
    BYVAL HwProfile AS DWORD, _
    BYVAL KeyType AS DWORD, _
    BYVAL InfHandle AS DWORD, _
    InfSectionName AS WSTRINGZ _
    ) AS DWORD  ' HKEY
#ELSE
DECLARE FUNCTION SetupDiCreateDevRegKeyW IMPORT "SETUPAPI.DLL" ALIAS "SetupDiCreateDevRegKeyW" ( _
   BYVAL DeviceInfoSet AS DWORD _                       ' __in HDEVINFO DeviceInfoSet
 , BYREF DeviceInfoData AS SP_DEVINFO_DATA _            ' __in PSP_DEVINFO_DATA DeviceInfoData
 , BYVAL Scope AS DWORD _                               ' __in DWORD Scope
 , BYVAL HwProfile AS DWORD _                           ' __in DWORD HwProfile
 , BYVAL KeyType AS DWORD _                             ' __in DWORD KeyType
 , OPTIONAL BYVAL InfHandle AS DWORD _                  ' __in_opt HINF InfHandle
 , OPTIONAL BYREF InfSectionName AS WSTRINGZ _          ' __in_opt PCWSTR InfSectionName
 ) AS DWORD                                             ' HKEY
#ENDIF

#IF %DEF(%UNICODE)
   MACRO SetupDiCreateDevRegKey = SetupDiCreateDevRegKeyW
#ELSE
   MACRO SetupDiCreateDevRegKey = SetupDiCreateDevRegKeyA
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SetupDiOpenDevRegKey LIB "SetupApi.dll" _
    ALIAS "SetupDiOpenDevRegKey" ( _
    BYVAL DeviceInfoSet AS DWORD, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR, _
    BYVAL Scope AS DWORD, _
    BYVAL HwProfile AS DWORD, _
    BYVAL KeyType AS DWORD, _
    BYVAL samDesired AS REGSAM _
    ) AS DWORD  ' HKEY
#ELSE
DECLARE FUNCTION SetupDiOpenDevRegKey IMPORT "SETUPAPI.DLL" ALIAS "SetupDiOpenDevRegKey" ( _
   BYVAL DeviceInfoSet AS DWORD _                       ' __in HDEVINFO DeviceInfoSet
 , BYREF DeviceInfoData AS SP_DEVINFO_DATA _            ' __in PSP_DEVINFO_DATA DeviceInfoData
 , BYVAL Scope AS DWORD _                               ' __in DWORD Scope
 , BYVAL HwProfile AS DWORD _                           ' __in DWORD HwProfile
 , BYVAL KeyType AS DWORD _                             ' __in DWORD KeyType
 , BYVAL samDesired AS REGSAM _                         ' __in REGSAM samDesired
 ) AS DWORD                                             ' HKEY
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SetupDiDeleteDevRegKey LIB "SetupApi.dll" _
    ALIAS "SetupDiDeleteDevRegKey" ( _
    BYVAL DeviceInfoSet AS DWORD, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR, _
    BYVAL Scope AS DWORD, _
    BYVAL HwProfile AS DWORD, _
    BYVAL KeyType AS DWORD _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupDiDeleteDevRegKey IMPORT "SETUPAPI.DLL" ALIAS "SetupDiDeleteDevRegKey" ( _
   BYVAL DeviceInfoSet AS DWORD _                       ' __in HDEVINFO DeviceInfoSet
 , BYREF DeviceInfoData AS SP_DEVINFO_DATA _            ' __in PSP_DEVINFO_DATA DeviceInfoData
 , BYVAL Scope AS DWORD _                               ' __in DWORD Scope
 , BYVAL HwProfile AS DWORD _                           ' __in DWORD HwProfile
 , BYVAL KeyType AS DWORD _                             ' __in DWORD KeyType
 ) AS LONG                                              ' BOOL
#ENDIF

DECLARE FUNCTION SetupDiGetHwProfileList IMPORT "SETUPAPI.DLL" ALIAS "SetupDiGetHwProfileList" ( _
   BYREF HwProfileList AS DWORD _                       ' __out PDWORD HwProfileList
 , BYVAL HwProfile AS DWORD _                           ' __in DWORD HwProfileListSize
 , BYREF RequiredSize AS DWORD _                        ' __out PDWORD RequiredSize
 , OPTIONAL BYREF CurrentlyActiveIndex AS DWORD _       ' __out_opt PDWORD CurrentlyActiveIndex
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SetupDiGetHwProfileListExA IMPORT "SETUPAPI.DLL" ALIAS "SetupDiGetHwProfileListExA" ( _
   BYREF HwProfileList AS DWORD _                       ' __out PDWORD HwProfileList
 , BYVAL HwProfile AS DWORD _                           ' __in DWORD HwProfileListSize
 , BYREF RequiredSize AS DWORD _                        ' __out PDWORD RequiredSize
 , OPTIONAL BYREF CurrentlyActiveIndex AS DWORD _       ' __out_opt PDWORD CurrentlyActiveIndex
 , OPTIONAL BYREF MachineName AS ASCIIZ _               ' __in_opt PCSTR MachineName
 , OPTIONAL BYVAL Reserved AS DWORD _                   ' __reserved PVOID Reserved
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SetupDiGetHwProfileListExW IMPORT "SETUPAPI.DLL" ALIAS "SetupDiGetHwProfileListExW" ( _
   BYREF HwProfileList AS DWORD _                       ' __out PDWORD HwProfileList
 , BYVAL HwProfile AS DWORD _                           ' __in DWORD HwProfileListSize
 , BYREF RequiredSize AS DWORD _                        ' __out PDWORD RequiredSize
 , OPTIONAL BYREF CurrentlyActiveIndex AS DWORD _       ' __out_opt PDWORD CurrentlyActiveIndex
 , OPTIONAL BYREF MachineName AS WSTRINGZ _             ' __in_opt PCWSTR MachineName
 , OPTIONAL BYVAL Reserved AS DWORD _                   ' __reserved PVOID Reserved
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO SetupDiGetHwProfileListEx = SetupDiGetHwProfileListExW
#ELSE
   MACRO SetupDiGetHwProfileListEx = SetupDiGetHwProfileListExA
#ENDIF

'#if _SETUPAPI_VER >= _WIN32_WINNT_LONGHORN
#IF %SETUPAPI_VER >= %WIN32_WINNT_LONGHORN

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SetupDiGetDevicePropertyKeys LIB "SetupApi.dll" _
    ALIAS "SetupDiGetDevicePropertyKeys" ( _
    BYVAL DeviceInfoSet AS DWORD, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR, _
    BYVAL PropertyKeyArray AS DEVPROPKEY PTR, _
    BYVAL PropertyKeyCount AS DWORD, _
    RequiredPropertyKeyCount AS DWORD, _
    BYVAL Flags AS DWORD _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupDiGetDevicePropertyKeys IMPORT "SETUPAPI.DLL" ALIAS "SetupDiGetDevicePropertyKeys" ( _
   BYVAL DeviceInfoSet AS DWORD _                       ' __in HDEVINFO DeviceInfoSet
 , BYREF DeviceInfoData AS SP_DEVINFO_DATA _            ' __in PSP_DEVINFO_DATA DeviceInfoData
 , BYREF PropertyKeyArray AS DEVPROPKEY _               ' __out DEVPROPKEY *PropertyKeyArray
 , BYVAL PropertyKeyCount AS DWORD _                    ' __in DWORD PropertyKeyCount
 , BYREF RequiredPropertyKeyCount AS DWORD _            ' __out_opt PDWORD RequiredPropertyKeyCount
 , BYVAL Flags AS DWORD _                               ' __in DWORD Flags
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SetupDiGetDevicePropertyW LIB "SetupApi.dll" _
    ALIAS "SetupDiGetDevicePropertyW" ( _
    BYVAL DeviceInfoSet AS DWORD, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR, _
    BYVAL PropertyKey AS DEVPROPKEY PTR, _
    BYVAL PropertyType AS DWORD PTR, _
    BYVAL PropertyBuffer AS BYTE PTR, _
    BYVAL PropertyBufferSize AS DWORD, _
    RequiredSize AS DWORD, _
    BYVAL Flags AS DWORD _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupDiGetDevicePropertyW IMPORT "SETUPAPI.DLL" ALIAS "SetupDiGetDevicePropertyW" ( _
   BYVAL DeviceInfoSet AS DWORD _                       ' __in HDEVINFO DeviceInfoSet
 , BYREF DeviceInfoData AS SP_DEVINFO_DATA _            ' __in PSP_DEVINFO_DATA DeviceInfoData
 , BYREF PropertyKey AS DEVPROPKEY _                    ' __in CONST DEVPROPKEY *PropertyKey
 , BYREF PropertyType AS DWORD _                        ' __out DEVPROPTYPE *PropertyType
 , BYREF PropertyBuffer AS ANY _                        ' __out PBYTE PropertyBuffer
 , BYVAL PropertyBufferSize AS DWORD _                  ' __in DWORD PropertyBufferSize
 , BYREF RequiredSize AS DWORD _                        ' __out_opt PDWORD RequiredSize
 , BYVAL Flags AS DWORD _                               ' __in DWORD Flags
 ) AS LONG                                              ' BOOL
#ENDIF

MACRO SetupDiGetDeviceProperty = SetupDiGetDevicePropertyW

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SetupDiSetDevicePropertyW LIB "SetupApi.dll" _
    ALIAS "SetupDiSetDevicePropertyW" ( _
    BYVAL DeviceInfoSet AS DWORD, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR, _
    BYVAL PropertyKey AS DEVPROPKEY PTR, _
    BYVAL PropertyType AS DWORD, _
    BYVAL PropertyBuffer AS BYTE PTR, _
    BYVAL PropertyBufferSize AS DWORD, _
    BYVAL Flags AS DWORD _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupDiSetDevicePropertyW IMPORT "SETUPAPI.DLL" ALIAS "SetupDiSetDevicePropertyW" ( _
   BYVAL DeviceInfoSet AS DWORD _                       ' __in HDEVINFO DeviceInfoSet
 , BYREF DeviceInfoData AS SP_DEVINFO_DATA _            ' __in PSP_DEVINFO_DATA DeviceInfoData
 , BYREF PropertyKey AS DEVPROPKEY _                    ' __in CONST DEVPROPKEY *PropertyKey
 , BYVAL PropertyType AS DWORD _                        ' __in DEVPROPTYPE PropertyType
 , BYVAL PropertyBuffer AS BYTE PTR _                   ' __in CONST PBYTE PropertyBuffer
 , BYVAL PropertyBufferSize AS DWORD _                  ' __in DWORD PropertyBufferSize
 , BYVAL Flags AS DWORD _                               ' __in DWORD Flags
 ) AS LONG                                              ' BOOL
#ENDIF

MACRO SetupDiSetDeviceProperty = SetupDiSetDevicePropertyW

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SetupDiGetDeviceInterfacePropertyKeys LIB "SetupApi.dll" _
    ALIAS "SetupDiGetDeviceInterfacePropertyKeys" ( _
    BYVAL DeviceInfoSet AS DWORD, _
    BYVAL DeviceInterfaceData AS SP_DEVICE_INTERFACE_DATA PTR, _
    BYVAL PropertyKeyArray AS DEVPROPKEY PTR, _
    BYVAL PropertyKeyCount AS DWORD, _
    RequiredPropertyKeyCount AS DWORD, _
    BYVAL Flags AS DWORD _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupDiGetDeviceInterfacePropertyKeys IMPORT "SETUPAPI.DLL" ALIAS "SetupDiGetDeviceInterfacePropertyKeys" ( _
   BYVAL DeviceInfoSet AS DWORD _                       ' __in HDEVINFO DeviceInfoSet
 , BYREF DeviceInterfaceData AS SP_DEVICE_INTERFACE_DATA _ ' __in PSP_DEVICE_INTERFACE_DATA DeviceInterfaceData
 , BYREF PropertyKeyArray AS DEVPROPKEY _               ' __out DEVPROPKEY *PropertyKeyArray
 , BYVAL PropertyKeyCount AS DWORD _                    ' __in DWORD PropertyKeyCount
 , BYREF RequiredPropertyKeyCount AS DWORD _            ' __out_opt PDWORD RequiredPropertyKeyCount
 , BYVAL Flags AS DWORD _                               ' __in DWORD Flags
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SetupDiGetDeviceInterfacePropertyW LIB "SetupApi.dll" _
    ALIAS "SetupDiGetDeviceInterfacePropertyW" ( _
    BYVAL DeviceInfoSet AS DWORD, _
    BYVAL DeviceInterfaceData AS SP_DEVICE_INTERFACE_DATA PTR, _
    BYVAL PropertyKey AS DEVPROPKEY PTR, _
    BYVAL PropertyType AS DWORD PTR, _
    BYVAL PropertyBuffer AS BYTE PTR, _
    BYVAL PropertyBufferSize AS DWORD, _
    RequiredSize AS DWORD, _
    BYVAL Flags AS DWORD _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupDiGetDeviceInterfacePropertyW IMPORT "SETUPAPI.DLL" ALIAS "SetupDiGetDeviceInterfacePropertyW" ( _
   BYVAL DeviceInfoSet AS DWORD _                       ' __in HDEVINFO DeviceInfoSet
 , BYREF DeviceInterfaceData AS SP_DEVICE_INTERFACE_DATA _ ' __in PSP_DEVICE_INTERFACE_DATA DeviceInterfaceData
 , BYREF PropertyKey AS DEVPROPKEY _                    ' __in CONST DEVPROPKEY *PropertyKey
 , BYREF PropertyType AS DWORD _                        ' __out DEVPROPTYPE *PropertyType
 , BYREF PropertyBuffer AS ANY _                        ' __out PBYTE PropertyBuffer
 , BYVAL PropertyBufferSize AS DWORD _                  ' __in DWORD PropertyBufferSize
 , BYREF RequiredSize AS DWORD _                        ' __out_opt PDWORD RequiredSize
 , BYVAL Flags AS DWORD _                               ' __in DWORD Flags
 ) AS LONG                                              ' BOOL
#ENDIF

MACRO SetupDiGetDeviceInterfaceProperty = SetupDiGetDeviceInterfacePropertyW

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SetupDiSetDeviceInterfacePropertyW LIB "SetupApi.dll" _
    ALIAS "SetupDiSetDeviceInterfacePropertyW" ( _
    BYVAL DeviceInfoSet AS DWORD, _
    BYVAL DeviceInterfaceData AS SP_DEVICE_INTERFACE_DATA PTR, _
    BYVAL PropertyKey AS DEVPROPKEY PTR, _
    BYVAL PropertyType AS DWORD, _
    BYVAL PropertyBuffer AS BYTE PTR, _
    BYVAL PropertyBufferSize AS DWORD, _
    BYVAL Flags AS DWORD _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupDiSetDeviceInterfacePropertyW IMPORT "SETUPAPI.DLL" ALIAS "SetupDiSetDeviceInterfacePropertyW" ( _
   BYVAL DeviceInfoSet AS DWORD _                       ' __in HDEVINFO DeviceInfoSet
 , BYREF DeviceInterfaceData AS SP_DEVICE_INTERFACE_DATA _ ' __in PSP_DEVICE_INTERFACE_DATA DeviceInterfaceData
 , BYREF PropertyKey AS DEVPROPKEY _                    ' __in CONST DEVPROPKEY *PropertyKey
 , BYVAL PropertyType AS DWORD _                        ' __in DEVPROPTYPE PropertyType
 , BYVAL PropertyBuffer AS BYTE PTR _                   ' __in CONST PBYTE PropertyBuffer
 , BYVAL PropertyBufferSize AS DWORD _                  ' __in DWORD PropertyBufferSize
 , BYVAL Flags AS DWORD _                               ' __in DWORD Flags
 ) AS LONG                                              ' BOOL
#ENDIF

MACRO SetupDiSetDeviceInterfaceProperty = SetupDiSetDeviceInterfacePropertyW

'//
'// Flags for SetupDiGetClassPropertyKeys, SetupDiGetClassProperty, and
'// SetupDiSetClassProperty.
'//
%DICLASSPROP_INSTALLER   = &H00000001???   ' // device setup class property
%DICLASSPROP_INTERFACE   = &H00000002???   ' // device interface class property

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SetupDiGetClassPropertyKeys LIB "SetupApi.dll" _
    ALIAS "SetupDiGetClassPropertyKeys" ( _
    ClassGuid AS GUID, _
    BYVAL PropertyKeyArray AS DEVPROPKEY PTR, _
    BYVAL PropertyKeyCount AS DWORD, _
    RequiredPropertyKeyCount AS DWORD, _
    BYVAL Flags AS DWORD _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupDiGetClassPropertyKeys IMPORT "SETUPAPI.DLL" ALIAS "SetupDiGetClassPropertyKeys" ( _
   BYREF ClassGuid AS GUID _                            ' __in CONST GUID *ClassGuid
 , BYREF PropertyKeyArray AS DEVPROPKEY _               ' __out DEVPROPKEY *PropertyKeyArray
 , BYVAL PropertyKeyCount AS DWORD _                    ' __in DWORD PropertyKeyCount
 , BYREF RequiredPropertyKeyCount AS DWORD _            ' __out_opt PDWORD RequiredPropertyKeyCount
 , BYVAL Flags AS DWORD _                               ' __in DWORD Flags
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SetupDiGetClassPropertyKeysExW LIB "SetupApi.dll" _
    ALIAS "SetupDiGetClassPropertyKeysExW" ( _
    ClassGuid AS GUID, _
    BYVAL PropertyKeyArray AS DEVPROPKEY PTR, _
    BYVAL PropertyKeyCount AS DWORD, _
    RequiredPropertyKeyCount AS DWORD, _
    BYVAL Flags AS DWORD, _
    MachineName AS WSTRINGZ, _
    BYVAL Reserved AS DWORD _   ' PVOID
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupDiGetClassPropertyKeysExW IMPORT "SETUPAPI.DLL" ALIAS "SetupDiGetClassPropertyKeysExW" ( _
   BYREF ClassGuid AS GUID _                            ' __in CONST GUID *ClassGuid
 , BYREF PropertyKeyArray AS DEVPROPKEY _               ' __out DEVPROPKEY *PropertyKeyArray
 , BYVAL PropertyKeyCount AS DWORD _                    ' __in DWORD PropertyKeyCount
 , BYREF RequiredPropertyKeyCount AS DWORD _            ' __out_opt PDWORD RequiredPropertyKeyCount
 , BYVAL Flags AS DWORD _                               ' __in DWORD Flags
 , OPTIONAL BYREF MachineName AS WSTRINGZ _             ' __in_opt PCWSTR MachineName
 , OPTIONAL BYVAL Reserved AS DWORD _                   ' __reserved PVOID Reserved
 ) AS LONG                                              ' BOOL
#ENDIF

MACRO SetupDiGetClassPropertyKeysEx = SetupDiGetClassPropertyKeysExW

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SetupDiGetClassPropertyW LIB "SetupApi.dll" _
    ALIAS "SetupDiGetClassPropertyW" ( _
    ClassGuid AS GUID, _
    BYVAL PropertyKey AS DEVPROPKEY PTR, _
    BYVAL PropertyType AS DWORD PTR, _
    BYVAL PropertyBuffer AS BYTE PTR, _
    BYVAL PropertyBufferSize AS DWORD, _
    RequiredSize AS DWORD, _
    BYVAL Flags AS DWORD _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupDiGetClassPropertyW IMPORT "SETUPAPI.DLL" ALIAS "SetupDiGetClassPropertyW" ( _
   BYREF ClassGuid AS GUID _                            ' __in CONST GUID *ClassGuid
 , BYREF PropertyKey AS DEVPROPKEY _                    ' __in CONST DEVPROPKEY *PropertyKey
 , BYREF PropertyType AS DWORD _                        ' __out DEVPROPTYPE *PropertyType
 , BYREF PropertyBuffer AS ANY _                        ' __out PBYTE PropertyBuffer
 , BYVAL PropertyBufferSize AS DWORD _                  ' __in DWORD PropertyBufferSize
 , BYREF RequiredSize AS DWORD _                        ' __out_opt PDWORD RequiredSize
 , BYVAL Flags AS DWORD _                               ' __in DWORD Flags
 ) AS LONG                                              ' BOOL
#ENDIF

MACRO SetupDiGetClassProperty = SetupDiGetClassPropertyW

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SetupDiGetClassPropertyExW LIB "SetupApi.dll" _
    ALIAS "SetupDiGetClassPropertyExW" ( _
    ClassGuid AS GUID, _
    BYVAL PropertyKey AS DEVPROPKEY PTR, _
    BYVAL PropertyType AS DWORD PTR, _
    BYVAL PropertyBuffer AS BYTE PTR, _
    BYVAL PropertyBufferSize AS DWORD, _
    RequiredSize AS DWORD, _
    BYVAL Flags AS DWORD, _
    MachineName AS WSTRINGZ, _
    BYVAL Reserved AS DWORD _   ' PVOID
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupDiGetClassPropertyExW IMPORT "SETUPAPI.DLL" ALIAS "SetupDiGetClassPropertyExW" ( _
   BYREF ClassGuid AS GUID _                            ' __in CONST GUID *ClassGuid
 , BYREF PropertyKey AS DEVPROPKEY _                    ' __in CONST DEVPROPKEY *PropertyKey
 , BYREF PropertyType AS DWORD _                        ' __out DEVPROPTYPE *PropertyType
 , BYREF PropertyBuffer AS ANY _                        ' __out PBYTE PropertyBuffer
 , BYVAL PropertyBufferSize AS DWORD _                  ' __in DWORD PropertyBufferSize
 , BYREF RequiredSize AS DWORD _                        ' __out_opt PDWORD RequiredSize
 , BYVAL Flags AS DWORD _                               ' __in DWORD Flags
 , OPTIONAL BYREF MachineName AS WSTRINGZ _             ' __in_opt PCWSTR MachineName
 , OPTIONAL BYVAL Reserved AS DWORD _                   ' __reserved PVOID Reserved
 ) AS LONG                                              ' BOOL
#ENDIF

MACRO SetupDiGetClassPropertyEx = SetupDiGetClassPropertyExW

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SetupDiSetClassPropertyW LIB "SetupApi.dll" _
    ALIAS "SetupDiSetClassPropertyW" ( _
    ClassGuid AS GUID, _
    BYVAL PropertyKey AS DEVPROPKEY PTR, _
    BYVAL PropertyType AS DWORD, _
    BYVAL PropertyBuffer AS BYTE PTR, _
    BYVAL PropertyBufferSize AS DWORD, _
    BYVAL Flags AS DWORD _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupDiSetClassPropertyW IMPORT "SETUPAPI.DLL" ALIAS "SetupDiSetClassPropertyW" ( _
   BYREF ClassGuid AS GUID _                            ' __in CONST GUID *ClassGuid
 , BYREF PropertyKey AS DEVPROPKEY _                    ' __in CONST DEVPROPKEY *PropertyKey
 , BYREF PropertyType AS DWORD _                        ' __out DEVPROPTYPE *PropertyType
 , BYVAL PropertyBuffer AS BYTE PTR _                   ' __in CONST PBYTE PropertyBuffer
 , BYVAL PropertyBufferSize AS DWORD _                  ' __in DWORD PropertyBufferSize
 , BYVAL Flags AS DWORD _                               ' __in DWORD Flags
 ) AS LONG                                              ' BOOL
#ENDIF

MACRO SetupDiSetClassProperty = SetupDiSetClassPropertyW

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SetupDiSetClassPropertyExW LIB "SetupApi.dll" _
    ALIAS "SetupDiSetClassPropertyExW" ( _
    ClassGuid AS GUID, _
    BYVAL PropertyKey AS DEVPROPKEY PTR, _
    BYVAL PropertyType AS DWORD, _
    BYVAL PropertyBuffer AS BYTE PTR, _
    BYVAL PropertyBufferSize AS DWORD, _
    BYVAL Flags AS DWORD, _
    MachineName AS WSTRINGZ, _
    BYVAL Reserved AS DWORD _   ' PVOID
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupDiSetClassPropertyExW IMPORT "SETUPAPI.DLL" ALIAS "SetupDiSetClassPropertyExW" ( _
   BYREF ClassGuid AS GUID _                            ' __in CONST GUID *ClassGuid
 , BYREF PropertyKey AS DEVPROPKEY _                    ' __in CONST DEVPROPKEY *PropertyKey
 , BYREF PropertyType AS DWORD _                        ' __out DEVPROPTYPE *PropertyType
 , BYVAL PropertyBuffer AS BYTE PTR _                   ' __in CONST PBYTE PropertyBuffer
 , BYVAL PropertyBufferSize AS DWORD _                  ' __in DWORD PropertyBufferSize
 , BYVAL Flags AS DWORD _                               ' __in DWORD Flags
 , OPTIONAL BYREF MachineName AS WSTRINGZ _             ' __in_opt PCWSTR MachineName
 , OPTIONAL BYVAL Reserved AS DWORD _                   ' __reserved PVOID Reserved
 ) AS LONG                                              ' BOOL
#ENDIF

MACRO SetupDiSetClassPropertyEx = SetupDiSetClassPropertyExW

#ENDIF
'#endif // _SETUPAPI_VER >= _WIN32_WINNT_LONGHORN


' //
' // Device registry property codes
' // (Codes marked as read-only (R) may only be used for
' // SetupDiGetDeviceRegistryProperty)
' //
' // These values should cover the same set of registry properties
' // as defined by the CM_DRP codes in cfgmgr32.h.
' //
' // Note that SPDRP codes are zero based while CM_DRP codes are one based!
' //
%SPDRP_DEVICEDESC                  = &H00000000???   ' // DeviceDesc R/W
%SPDRP_HARDWAREID                  = &H00000001???   ' // HardwareID R/W
%SPDRP_COMPATIBLEIDS               = &H00000002???   ' // CompatibleIDs R/W
%SPDRP_UNUSED0                     = &H00000003???   ' // unused
%SPDRP_SERVICE                     = &H00000004???   ' // Service R/W
%SPDRP_UNUSED1                     = &H00000005???   ' // unused
%SPDRP_UNUSED2                     = &H00000006???   ' // unused
%SPDRP_CLASS                       = &H00000007???   ' // Class R--tied to ClassGUID???
%SPDRP_CLASSGUID                   = &H00000008???   ' // ClassGUID R/W
%SPDRP_DRIVER                      = &H00000009???   ' // Driver R/W
%SPDRP_CONFIGFLAGS                 = &H0000000A???   ' // ConfigFlags R/W
%SPDRP_MFG                         = &H0000000B???   ' // Mfg R/W
%SPDRP_FRIENDLYNAME                = &H0000000C???   ' // FriendlyName R/W
%SPDRP_LOCATION_INFORMATION        = &H0000000D???   ' // LocationInformation R/W
%SPDRP_PHYSICAL_DEVICE_OBJECT_NAME = &H0000000E???   ' // PhysicalDeviceObjectName R
%SPDRP_CAPABILITIES                = &H0000000F???   ' // Capabilities R
%SPDRP_UI_NUMBER                   = &H00000010???   ' // UiNumber R
%SPDRP_UPPERFILTERS                = &H00000011???   ' // UpperFilters R/W
%SPDRP_LOWERFILTERS                = &H00000012???   ' // LowerFilters R/W
%SPDRP_BUSTYPEGUID                 = &H00000013???   ' // BusTypeGUID R
%SPDRP_LEGACYBUSTYPE               = &H00000014???   ' // LegacyBusType R
%SPDRP_BUSNUMBER                   = &H00000015???   ' // BusNumber R
%SPDRP_ENUMERATOR_NAME             = &H00000016???   ' // Enumerator Name R
%SPDRP_SECURITY                    = &H00000017???   ' // Security R/W, binary form???
%SPDRP_SECURITY_SDS                = &H00000018???   ' // Security W, SDS form???
%SPDRP_DEVTYPE                     = &H00000019???   ' // Device Type R/W
%SPDRP_EXCLUSIVE                   = &H0000001A???   ' // Device is exclusive-access R/W
%SPDRP_CHARACTERISTICS             = &H0000001B???   ' // Device Characteristics R/W
%SPDRP_ADDRESS                     = &H0000001C???   ' // Device Address R
%SPDRP_UI_NUMBER_DESC_FORMAT       = &H0000001D???   ' // UiNumberDescFormat R/W
%SPDRP_DEVICE_POWER_DATA           = &H0000001E???   ' // Device Power Data R
%SPDRP_REMOVAL_POLICY              = &H0000001F???   ' // Removal Policy R
%SPDRP_REMOVAL_POLICY_HW_DEFAULT   = &H00000020???   ' // Hardware Removal Policy R
%SPDRP_REMOVAL_POLICY_OVERRIDE     = &H00000021???   ' // Removal Policy Override RW???
%SPDRP_INSTALL_STATE               = &H00000022???   ' // Device Install State R
%SPDRP_LOCATION_PATHS              = &H00000023???   ' // Device Location Paths R
%SPDRP_BASE_CONTAINERID            = &H00000024???   ' // Base ContainerID R

%SPDRP_MAXIMUM_PROPERTY            = &H00000025???   ' // Upper bound on ordinals

' //
' // Class registry property codes
' // (Codes marked as read-only (R) may only be used for
' // SetupDiGetClassRegistryProperty)
' //
' // These values should cover the same set of registry properties
' // as defined by the CM_CRP codes in cfgmgr32.h.
' // they should also have a 1:1 correspondence with Device registers, where applicable
' // but no overlap otherwise
' //
%SPCRP_UPPERFILTERS                = (&H00000011???)  ' // UpperFilters (R/W)
%SPCRP_LOWERFILTERS                = (&H00000012???)  ' // LowerFilters (R/W)
%SPCRP_SECURITY                    = (&H00000017???)  ' // Security (R/W, binary form)
%SPCRP_SECURITY_SDS                = (&H00000018???)  ' // Security (W, SDS form)
%SPCRP_DEVTYPE                     = (&H00000019???)  ' // Device Type (R/W)
%SPCRP_EXCLUSIVE                   = (&H0000001A???)  ' // Device is exclusive-access (R/W)
%SPCRP_CHARACTERISTICS             = (&H0000001B???)  ' // Device Characteristics (R/W)
%SPCRP_MAXIMUM_PROPERTY            = (&H0000001C???)  ' // Upper bound on ordinals

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SetupDiGetDeviceRegistryPropertyA LIB "SetupApi.dll" _
    ALIAS "SetupDiGetDeviceRegistryPropertyA" ( _
    BYVAL DeviceInfoSet AS DWORD, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR, _
    BYVAL PROPERTY AS DWORD, _
    PropertyRegDataType AS DWORD, _
    BYVAL PropertyBuffer AS BYTE PTR, _
    BYVAL PropertyBufferSize AS DWORD, _
    RequiredSize AS DWORD _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupDiGetDeviceRegistryPropertyA IMPORT "SETUPAPI.DLL" ALIAS "SetupDiGetDeviceRegistryPropertyA" ( _
   BYVAL DeviceInfoSet AS DWORD _                       ' __in HDEVINFO DeviceInfoSet
 , BYREF DeviceInfoData AS SP_DEVINFO_DATA _            ' __in PSP_DEVINFO_DATA DeviceInfoData
 , BYVAL Property AS DWORD _                            ' __in DWORD Property
 , BYREF PropertyRegDataType AS DWORD _                 ' __out_opt PDWORD PropertyRegDataType
 , BYREF PropertyBuffer AS ANY _                        ' __out PBYTE PropertyBuffer
 , BYVAL PropertyBufferSize AS DWORD _                  ' __in DWORD PropertyBufferSize
 , OPTIONAL BYREF RequiredSize AS DWORD _               ' __out_opt PDWORD RequiredSize
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SetupDiGetDeviceRegistryPropertyW LIB "SetupApi.dll" _
    ALIAS "SetupDiGetDeviceRegistryPropertyW" ( _
    BYVAL DeviceInfoSet AS DWORD, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR, _
    BYVAL PROPERTY AS DWORD, _
    PropertyRegDataType AS DWORD, _
    BYVAL PropertyBuffer AS BYTE PTR, _
    BYVAL PropertyBufferSize AS DWORD, _
    RequiredSize AS DWORD _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupDiGetDeviceRegistryPropertyW IMPORT "SETUPAPI.DLL" ALIAS "SetupDiGetDeviceRegistryPropertyW" ( _
   BYVAL DeviceInfoSet AS DWORD _                       ' __in HDEVINFO DeviceInfoSet
 , BYREF DeviceInfoData AS SP_DEVINFO_DATA _            ' __in PSP_DEVINFO_DATA DeviceInfoData
 , BYVAL Property AS DWORD _                            ' __in DWORD Property
 , BYREF PropertyRegDataType AS DWORD _                 ' __out_opt PDWORD PropertyRegDataType
 , BYREF PropertyBuffer AS ANY _                        ' __out PBYTE PropertyBuffer
 , BYVAL PropertyBufferSize AS DWORD _                  ' __in DWORD PropertyBufferSize
 , OPTIONAL BYREF RequiredSize AS DWORD _               ' __out_opt PDWORD RequiredSize
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%UNICODE)
   MACRO SetupDiGetDeviceRegistryProperty = SetupDiGetDeviceRegistryPropertyW
#ELSE
   MACRO SetupDiGetDeviceRegistryProperty = SetupDiGetDeviceRegistryPropertyA
#ENDIF

'#if _SETUPAPI_VER >= _WIN32_WINNT_WINXP
#IF %SETUPAPI_VER >= %WIN32_WINNT_WINXP

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SetupDiGetClassRegistryPropertyA LIB "SetupApi.dll" _
    ALIAS "SetupDiGetClassRegistryPropertyA" ( _
    ClassGuid AS GUID, _
    BYVAL PROPERTY AS DWORD, _
    PropertyRegDataType AS DWORD, _
    BYVAL PropertyBuffer AS BYTE PTR, _
    BYVAL PropertyBufferSize AS DWORD, _
    RequiredSize AS DWORD, _
    MachineName AS ASCIIZ, _
    BYVAL Reserved AS DWORD _   ' PVOID
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupDiGetClassRegistryPropertyA IMPORT "SETUPAPI.DLL" ALIAS "SetupDiGetClassRegistryPropertyA" ( _
   BYREF ClassGuid AS GUID _                            ' __in CONST GUID *ClassGuid
 , BYVAL Property AS DWORD _                            ' __in DWORD Property
 , BYREF PropertyRegDataType AS DWORD _                 ' __out_opt PDWORD PropertyRegDataType
 , BYREF PropertyBuffer AS ANY _                        ' __out PBYTE PropertyBuffer
 , BYVAL PropertyBufferSize AS DWORD _                  ' __in DWORD PropertyBufferSize
 , OPTIONAL BYREF RequiredSize AS DWORD _               ' __out_opt PDWORD RequiredSize
 , OPTIONAL BYREF MachineName AS ASCIIZ _               ' __in_opt PCSTR MachineName
 , OPTIONAL BYVAL Reserved AS DWORD _                   ' __reserved PVOID Reserved
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SetupDiGetClassRegistryPropertyW LIB "SetupApi.dll" _
    ALIAS "SetupDiGetClassRegistryPropertyW" ( _
    ClassGuid AS GUID, _
    BYVAL PROPERTY AS DWORD, _
    PropertyRegDataType AS DWORD, _
    BYVAL PropertyBuffer AS BYTE PTR, _
    BYVAL PropertyBufferSize AS DWORD, _
    RequiredSize AS DWORD, _
    MachineName AS WSTRINGZ, _
    BYVAL Reserved AS DWORD _   ' PVOID
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupDiGetClassRegistryPropertyW IMPORT "SETUPAPI.DLL" ALIAS "SetupDiGetClassRegistryPropertyW" ( _
   BYREF ClassGuid AS GUID _                            ' __in CONST GUID *ClassGuid
 , BYVAL Property AS DWORD _                            ' __in DWORD Property
 , BYREF PropertyRegDataType AS DWORD _                 ' __out_opt PDWORD PropertyRegDataType
 , BYREF PropertyBuffer AS ANY _                        ' __out PBYTE PropertyBuffer
 , BYVAL PropertyBufferSize AS DWORD _                  ' __in DWORD PropertyBufferSize
 , OPTIONAL BYREF RequiredSize AS DWORD _               ' __out_opt PDWORD RequiredSize
 , OPTIONAL BYREF MachineName AS WSTRINGZ _             ' __in_opt PCWSTR MachineName
 , OPTIONAL BYVAL Reserved AS DWORD _                   ' __reserved PVOID Reserved
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%UNICODE)
   MACRO SetupDiGetClassRegistryProperty = SetupDiGetClassRegistryPropertyW
#ELSE
   MACRO SetupDiGetClassRegistryProperty = SetupDiGetClassRegistryPropertyA
#ENDIF

#ENDIF
'#endif // _SETUPAPI_VER >= _WIN32_WINNT_WINXP

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SetupDiSetDeviceRegistryPropertyA LIB "SetupApi.dll" _
    ALIAS "SetupDiSetDeviceRegistryPropertyA" ( _
    BYVAL DeviceInfoSet AS DWORD, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR, _
    BYVAL PROPERTY AS DWORD, _
    BYVAL PropertyBuffer AS BYTE PTR, _
    BYVAL PropertyBufferSize AS DWORD _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupDiSetDeviceRegistryPropertyA IMPORT "SETUPAPI.DLL" ALIAS "SetupDiSetDeviceRegistryPropertyA" ( _
   BYVAL DeviceInfoSet AS DWORD _                       ' __in HDEVINFO DeviceInfoSet
 , BYREF DeviceInfoData AS SP_DEVINFO_DATA _            ' __inout PSP_DEVINFO_DATA DeviceInfoData
 , BYVAL Property AS DWORD _                            ' __in DWORD Property
 , BYVAL PropertyBuffer AS BYTE PTR _                   ' __in CONST BYTE *PropertyBuffer
 , BYVAL PropertyBufferSize AS DWORD _                  ' __in DWORD PropertyBufferSize
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SetupDiSetDeviceRegistryPropertyW LIB "SetupApi.dll" _
    ALIAS "SetupDiSetDeviceRegistryPropertyW" ( _
    BYVAL DeviceInfoSet AS DWORD, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR, _
    BYVAL PROPERTY AS DWORD, _
    BYVAL PropertyBuffer AS BYTE PTR, _
    BYVAL PropertyBufferSize AS DWORD _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupDiSetDeviceRegistryPropertyW IMPORT "SETUPAPI.DLL" ALIAS "SetupDiSetDeviceRegistryPropertyW" ( _
   BYVAL DeviceInfoSet AS DWORD _                       ' __in HDEVINFO DeviceInfoSet
 , BYREF DeviceInfoData AS SP_DEVINFO_DATA _            ' __inout PSP_DEVINFO_DATA DeviceInfoData
 , BYVAL Property AS DWORD _                            ' __in DWORD Property
 , BYVAL PropertyBuffer AS BYTE PTR _                   ' __in CONST BYTE *PropertyBuffer
 , BYVAL PropertyBufferSize AS DWORD _                  ' __in DWORD PropertyBufferSize
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%UNICODE)
   MACRO SetupDiSetDeviceRegistryProperty = SetupDiSetDeviceRegistryPropertyW
#ELSE
   MACRO SetupDiSetDeviceRegistryProperty = SetupDiSetDeviceRegistryPropertyA
#ENDIF

'#if _SETUPAPI_VER >= _WIN32_WINNT_WINXP
#IF %SETUPAPI_VER >= %WIN32_WINNT_WINXP

DECLARE FUNCTION SetupDiSetClassRegistryPropertyA IMPORT "SETUPAPI.DLL" ALIAS "SetupDiSetClassRegistryPropertyA" ( _
   BYREF ClassGuid AS GUID _                            ' __in CONST GUID *ClassGuid
 , BYVAL Property AS DWORD _                            ' __in DWORD Property
 , BYVAL PropertyBuffer AS BYTE PTR _                   ' __in CONST BYTE *PropertyBuffer
 , BYVAL PropertyBufferSize AS DWORD _                  ' __in DWORD PropertyBufferSize
 , OPTIONAL BYREF MachineName AS ASCIIZ _               ' __in_opt PCSTR MachineName
 , OPTIONAL BYVAL Reserved AS DWORD _                   ' __reserved PVOID Reserved
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SetupDiSetClassRegistryPropertyW IMPORT "SETUPAPI.DLL" ALIAS "SetupDiSetClassRegistryPropertyW" ( _
   BYREF ClassGuid AS GUID _                            ' __in CONST GUID *ClassGuid
 , BYVAL Property AS DWORD _                            ' __in DWORD Property
 , BYVAL PropertyBuffer AS BYTE PTR _                   ' __in CONST BYTE *PropertyBuffer
 , BYVAL PropertyBufferSize AS DWORD _                  ' __in DWORD PropertyBufferSize
 , OPTIONAL BYREF MachineName AS WSTRINGZ _             ' __in_opt PCWSTR MachineName
 , OPTIONAL BYVAL Reserved AS DWORD _                   ' __reserved PVOID Reserved
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO SetupDiSetClassRegistryProperty = SetupDiSetClassRegistryPropertyW
#ELSE
   MACRO SetupDiSetClassRegistryProperty = SetupDiSetClassRegistryPropertyA
#ENDIF

#ENDIF
'#endif // _SETUPAPI_VER >= _WIN32_WINNT_WINXP

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SetupDiGetDeviceInstallParamsA LIB "SetupApi.dll" _
    ALIAS "SetupDiGetDeviceInstallParamsA" ( _
    BYVAL DeviceInfoSet AS DWORD, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR, _
    BYVAL DeviceInstallParams AS SP_DEVINSTALL_PARAMS_A PTR _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupDiGetDeviceInstallParamsA IMPORT "SETUPAPI.DLL" ALIAS "SetupDiGetDeviceInstallParamsA" ( _
   BYVAL DeviceInfoSet AS DWORD _                       ' __in HDEVINFO DeviceInfoSet
 , BYREF DeviceInfoData AS SP_DEVINFO_DATA _            ' __in_opt PSP_DEVINFO_DATA DeviceInfoData
 , BYREF DeviceInstallParams AS SP_DEVINSTALL_PARAMS_A _ ' __out PSP_DEVINSTALL_PARAMS_A DeviceInstallParams
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SetupDiGetDeviceInstallParamsW LIB "SetupApi.dll" _
    ALIAS "SetupDiGetDeviceInstallParamsW" ( _
    BYVAL DeviceInfoSet AS DWORD, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR, _
    BYVAL DeviceInstallParams AS SP_DEVINSTALL_PARAMS_W PTR _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupDiGetDeviceInstallParamsW IMPORT "SETUPAPI.DLL" ALIAS "SetupDiGetDeviceInstallParamsW" ( _
   BYVAL DeviceInfoSet AS DWORD _                       ' __in HDEVINFO DeviceInfoSet
 , BYREF DeviceInfoData AS SP_DEVINFO_DATA _            ' __in_opt PSP_DEVINFO_DATA DeviceInfoData
 , BYREF DeviceInstallParams AS SP_DEVINSTALL_PARAMS_W _ ' __out PSP_DEVINSTALL_PARAMS_W DeviceInstallParams
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%UNICODE)
   MACRO SetupDiGetDeviceInstallParams = SetupDiGetDeviceInstallParamsW
#ELSE
   MACRO SetupDiGetDeviceInstallParams = SetupDiGetDeviceInstallParamsA
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SetupDiGetClassInstallParamsA LIB "SetupApi.dll" _
    ALIAS "SetupDiGetClassInstallParamsA" ( _
    BYVAL DeviceInfoSet AS DWORD, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR, _
    BYVAL ClassInstallParams AS SP_CLASSINSTALL_HEADER PTR, _
    BYVAL ClassInstallParamsSize AS DWORD, _
    RequiredSize AS DWORD _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupDiGetClassInstallParamsA IMPORT "SETUPAPI.DLL" ALIAS "SetupDiGetClassInstallParamsA" ( _
   BYVAL DeviceInfoSet AS DWORD _                       ' __in HDEVINFO DeviceInfoSet
 , BYREF DeviceInfoData AS SP_DEVINFO_DATA _            ' __in_opt PSP_DEVINFO_DATA DeviceInfoData
 , BYREF ClassInstallParams AS SP_CLASSINSTALL_HEADER _ ' __out PSP_CLASSINSTALL_HEADER ClassInstallParams
 , BYVAL ClassInstallParamsSize AS DWORD _              ' __in DWORD ClassInstallParamsSize
 , OPTIONAL BYREF RequiredSize AS DWORD _               ' __out_opt PDWORD RequiredSize
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SetupDiGetClassInstallParamsW LIB "SetupApi.dll" _
    ALIAS "SetupDiGetClassInstallParamsW" ( _
    BYVAL DeviceInfoSet AS DWORD, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR, _
    BYVAL ClassInstallParams AS SP_CLASSINSTALL_HEADER PTR, _
    BYVAL ClassInstallParamsSize AS DWORD, _
    RequiredSize AS DWORD _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupDiGetClassInstallParamsW IMPORT "SETUPAPI.DLL" ALIAS "SetupDiGetClassInstallParamsW" ( _
   BYVAL DeviceInfoSet AS DWORD _                       ' __in HDEVINFO DeviceInfoSet
 , BYREF DeviceInfoData AS SP_DEVINFO_DATA _            ' __in_opt PSP_DEVINFO_DATA DeviceInfoData
 , BYREF ClassInstallParams AS SP_CLASSINSTALL_HEADER _ ' __out PSP_CLASSINSTALL_HEADER ClassInstallParams
 , BYVAL ClassInstallParamsSize AS DWORD _              ' __in DWORD ClassInstallParamsSize
 , OPTIONAL BYREF RequiredSize AS DWORD _               ' __out_opt PDWORD RequiredSize
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%UNICODE)
   MACRO SetupDiGetClassInstallParams = SetupDiGetClassInstallParamsW
#ELSE
   MACRO SetupDiGetClassInstallParams = SetupDiGetClassInstallParamsA
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SetupDiSetDeviceInstallParamsA LIB "SetupApi.dll" _
    ALIAS "SetupDiSetDeviceInstallParamsA" ( _
    BYVAL DeviceInfoSet AS DWORD, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR, _
    BYVAL DeviceInstallParams AS SP_DEVINSTALL_PARAMS_A PTR _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupDiSetDeviceInstallParamsA IMPORT "SETUPAPI.DLL" ALIAS "SetupDiSetDeviceInstallParamsA" ( _
   BYVAL DeviceInfoSet AS DWORD _                       ' __in HDEVINFO DeviceInfoSet
 , BYREF DeviceInfoData AS SP_DEVINFO_DATA _            ' __in_opt PSP_DEVINFO_DATA DeviceInfoData
 , BYREF DeviceInstallParams AS SP_DEVINSTALL_PARAMS_A _ ' __in PSP_DEVINSTALL_PARAMS_A DeviceInstallParams
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SetupDiSetDeviceInstallParamsW LIB "SetupApi.dll" _
    ALIAS "SetupDiSetDeviceInstallParamsW" ( _
    BYVAL DeviceInfoSet AS DWORD, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR, _
    BYVAL DeviceInstallParams AS SP_DEVINSTALL_PARAMS_W PTR _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupDiSetDeviceInstallParamsW IMPORT "SETUPAPI.DLL" ALIAS "SetupDiSetDeviceInstallParamsW" ( _
   BYVAL DeviceInfoSet AS DWORD _                       ' __in HDEVINFO DeviceInfoSet
 , BYREF DeviceInfoData AS SP_DEVINFO_DATA _            ' __in_opt PSP_DEVINFO_DATA DeviceInfoData
 , BYREF DeviceInstallParams AS SP_DEVINSTALL_PARAMS_W _ ' __in PSP_DEVINSTALL_PARAMS_W DeviceInstallParams
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%UNICODE)
   MACRO SetupDiSetDeviceInstallParams = SetupDiSetDeviceInstallParamsW
#ELSE
   MACRO SetupDiSetDeviceInstallParams = SetupDiSetDeviceInstallParamsA
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SetupDiSetClassInstallParamsA LIB "SetupApi.dll" _
    ALIAS "SetupDiSetClassInstallParamsA" ( _
    BYVAL DeviceInfoSet AS DWORD, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR, _
    BYVAL ClassInstallParams AS SP_CLASSINSTALL_HEADER PTR, _
    BYVAL ClassInstallParamsSize AS DWORD _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupDiSetClassInstallParamsA IMPORT "SETUPAPI.DLL" ALIAS "SetupDiSetClassInstallParamsA" ( _
   BYVAL DeviceInfoSet AS DWORD _                       ' __in HDEVINFO DeviceInfoSet
 , BYREF DeviceInfoData AS SP_DEVINFO_DATA _            ' __in_opt PSP_DEVINFO_DATA DeviceInfoData
 , BYREF ClassInstallParams AS SP_CLASSINSTALL_HEADER _ ' __in PSP_CLASSINSTALL_HEADER ClassInstallParams
 , BYVAL ClassInstallParamsSize AS DWORD _              ' __in DWORD ClassInstallParamsSize
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SetupDiSetClassInstallParamsW LIB "SetupApi.dll" _
    ALIAS "SetupDiSetClassInstallParamsW" ( _
    BYVAL DeviceInfoSet AS DWORD, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR, _
    BYVAL ClassInstallParams AS SP_CLASSINSTALL_HEADER PTR, _
    BYVAL ClassInstallParamsSize AS DWORD _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupDiSetClassInstallParamsW IMPORT "SETUPAPI.DLL" ALIAS "SetupDiSetClassInstallParamsW" ( _
   BYVAL DeviceInfoSet AS DWORD _                       ' __in HDEVINFO DeviceInfoSet
 , BYREF DeviceInfoData AS SP_DEVINFO_DATA _            ' __in_opt PSP_DEVINFO_DATA DeviceInfoData
 , BYREF ClassInstallParams AS SP_CLASSINSTALL_HEADER _ ' __in PSP_CLASSINSTALL_HEADER ClassInstallParams
 , BYVAL ClassInstallParamsSize AS DWORD _              ' __in DWORD ClassInstallParamsSize
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%UNICODE)
   MACRO SetupDiSetClassInstallParams = SetupDiSetClassInstallParamsW
#ELSE
   MACRO SetupDiSetClassInstallParams = SetupDiSetClassInstallParamsA
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SetupDiGetDriverInstallParamsA LIB "SetupApi.dll" _
    ALIAS "SetupDiGetDriverInstallParamsA" ( _
    BYVAL DeviceInfoSet AS DWORD, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR, _
    BYVAL DriverInfoData AS SP_DRVINFO_DATA_A PTR, _
    BYVAL DriverInstallParams AS SP_DRVINSTALL_PARAMS PTR _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupDiGetDriverInstallParamsA IMPORT "SETUPAPI.DLL" ALIAS "SetupDiGetDriverInstallParamsA" ( _
   BYVAL DeviceInfoSet AS DWORD _                       ' __in HDEVINFO DeviceInfoSet
 , BYREF DeviceInfoData AS SP_DEVINFO_DATA _            ' __in_opt PSP_DEVINFO_DATA DeviceInfoData
 , BYREF DriverInfoData AS SP_DRVINFO_DATA_A _          ' __in PSP_DRVINFO_DATA_A DriverInfoData
 , BYREF DriverInstallParams AS SP_DRVINSTALL_PARAMS _  ' __out PSP_DRVINSTALL_PARAMS DriverInstallParams
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SetupDiGetDriverInstallParamsW LIB "SetupApi.dll" _
    ALIAS "SetupDiGetDriverInstallParamsW" ( _
    BYVAL DeviceInfoSet AS DWORD, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR, _
    BYVAL DriverInfoData AS SP_DRVINFO_DATA_W PTR, _
    BYVAL DriverInstallParams AS SP_DRVINSTALL_PARAMS PTR _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupDiGetDriverInstallParamsW IMPORT "SETUPAPI.DLL" ALIAS "SetupDiGetDriverInstallParamsW" ( _
   BYVAL DeviceInfoSet AS DWORD _                       ' __in HDEVINFO DeviceInfoSet
 , BYREF DeviceInfoData AS SP_DEVINFO_DATA _            ' __in_opt PSP_DEVINFO_DATA DeviceInfoData
 , BYREF DriverInfoData AS SP_DRVINFO_DATA_W _          ' __in PSP_DRVINFO_DATA_W DriverInfoData
 , BYREF DriverInstallParams AS SP_DRVINSTALL_PARAMS _  ' __out PSP_DRVINSTALL_PARAMS DriverInstallParams
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%UNICODE)
   MACRO SetupDiGetDriverInstallParams = SetupDiGetDriverInstallParamsW
#ELSE
   MACRO SetupDiGetDriverInstallParams = SetupDiGetDriverInstallParamsA
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SetupDiSetDriverInstallParamsA LIB "SetupApi.dll" _
    ALIAS "SetupDiSetDriverInstallParamsA" ( _
    BYVAL DeviceInfoSet AS DWORD, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR, _
    BYVAL DriverInfoData AS SP_DRVINFO_DATA_A PTR, _
    BYVAL DriverInstallParams AS SP_DRVINSTALL_PARAMS PTR _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupDiSetDriverInstallParamsA IMPORT "SETUPAPI.DLL" ALIAS "SetupDiSetDriverInstallParamsA" ( _
   BYVAL DeviceInfoSet AS DWORD _                       ' __in HDEVINFO DeviceInfoSet
 , BYREF DeviceInfoData AS SP_DEVINFO_DATA _            ' __in_opt PSP_DEVINFO_DATA DeviceInfoData
 , BYREF DriverInfoData AS SP_DRVINFO_DATA_A _          ' __in PSP_DRVINFO_DATA_A DriverInfoData
 , BYREF DriverInstallParams AS SP_DRVINSTALL_PARAMS _  ' __in PSP_DRVINSTALL_PARAMS DriverInstallParams
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SetupDiSetDriverInstallParamsW LIB "SetupApi.dll" _
    ALIAS "SetupDiSetDriverInstallParamsW" ( _
    BYVAL DeviceInfoSet AS DWORD, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR, _
    BYVAL DriverInfoData AS SP_DRVINFO_DATA_W PTR, _
    BYVAL DriverInstallParams AS SP_DRVINSTALL_PARAMS PTR _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupDiSetDriverInstallParamsW IMPORT "SETUPAPI.DLL" ALIAS "SetupDiSetDriverInstallParamsW" ( _
   BYVAL DeviceInfoSet AS DWORD _                       ' __in HDEVINFO DeviceInfoSet
 , BYREF DeviceInfoData AS SP_DEVINFO_DATA _            ' __in_opt PSP_DEVINFO_DATA DeviceInfoData
 , BYREF DriverInfoData AS SP_DRVINFO_DATA_W _          ' __in PSP_DRVINFO_DATA_W DriverInfoData
 , BYREF DriverInstallParams AS SP_DRVINSTALL_PARAMS _  ' __in PSP_DRVINSTALL_PARAMS DriverInstallParams
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%UNICODE)
   MACRO SetupDiSetDriverInstallParams = SetupDiSetDriverInstallParamsW
#ELSE
   MACRO SetupDiSetDriverInstallParams = SetupDiSetDriverInstallParamsA
#ENDIF

DECLARE FUNCTION SetupDiLoadClassIcon IMPORT "SETUPAPI.DLL" ALIAS "SetupDiLoadClassIcon" ( _
   BYREF ClassGuid AS GUID _                            ' __in CONST GUID *ClassGuid
 , OPTIONAL BYREF LargeIcon AS DWORD _                  ' __out_opt HICON *LargeIcon
 , OPTIONAL BYREF MiniIconIndex AS LONG _               ' __out_opt PINT MiniIconIndex
 ) AS LONG                                              ' BOOL

'#if _SETUPAPI_VER >= _WIN32_WINNT_LONGHORN
#IF %SETUPAPI_VER >= %WIN32_WINNT_LONGHORN

DECLARE FUNCTION SetupDiLoadDeviceIcon IMPORT "SETUPAPI.DLL" ALIAS "SetupDiLoadDeviceIcon" ( _
   BYVAL DeviceInfoSet AS DWORD _                       ' __in HDEVINFO DeviceInfoSet
 , BYREF DeviceInfoData AS SP_DEVINFO_DATA _            ' __in PSP_DEVINFO_DATA DeviceInfoData
 , BYVAL cxIcon AS DWORD _                              ' __in UINT cxIcon
 , BYVAL cyIcon AS DWORD _                              ' __in UINT cyIcon
 , BYVAL Flags AS DWORD _                               ' __in DWORD Flags
 , BYREF hIcon AS DWORD _                               ' __out HICON *hIcon
 ) AS LONG                                              ' BOOL

#ENDIF
'#endif // _SETUPAPI_VER >= _WIN32_WINNT_LONGHORN

' //
' // Flags controlling the drawing of mini-icons
' //
%DMI_MASK      = &H00000001???
%DMI_BKCOLOR   = &H00000002???
%DMI_USERECT   = &H00000004???

DECLARE FUNCTION SetupDiDrawMiniIcon IMPORT "SETUPAPI.DLL" ALIAS "SetupDiDrawMiniIcon" ( _
   BYVAL hdc AS DWORD _                                 ' __in HDC hdc
 , BYVAL rc AS RECT _                                   ' __in RECT rc
 , BYVAL MiniIconIndex AS LONG _                        ' __in INT MiniIconIndex
 , BYVAL Flags AS DWORD _                               ' __in DWORD Flags
 ) AS LONG                                              ' INT

DECLARE FUNCTION SetupDiGetClassBitmapIndex IMPORT "SETUPAPI.DLL" ALIAS "SetupDiGetClassBitmapIndex" ( _
   BYREF ClassGuid AS GUID _                            ' __in_opt CONST GUID *ClassGuid
 , BYREF MiniIconIndex AS LONG _                        ' __out PINT MiniIconIndex
 ) AS LONG                                              ' BOOL

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SetupDiGetClassImageList LIB "SetupApi.dll" _
    ALIAS "SetupDiGetClassImageList" ( _
    BYVAL ClassImageListData AS SP_CLASSIMAGELIST_DATA PTR _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupDiGetClassImageList IMPORT "SETUPAPI.DLL" ALIAS "SetupDiGetClassImageList" ( _
   BYREF ClassImageListData AS SP_CLASSIMAGELIST_DATA _ ' __out PSP_CLASSIMAGELIST_DATA ClassImageListData
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SetupDiGetClassImageListExA LIB "SetupApi.dll" _
    ALIAS "SetupDiGetClassImageListExA" ( _
    BYVAL ClassImageListData AS SP_CLASSIMAGELIST_DATA PTR, _
    MachineName AS ASCIIZ, _
    BYVAL Reserved AS DWORD _   ' PVOID
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupDiGetClassImageListExA IMPORT "SETUPAPI.DLL" ALIAS "SetupDiGetClassImageListExA" ( _
   BYREF ClassImageListData AS SP_CLASSIMAGELIST_DATA _ ' __out PSP_CLASSIMAGELIST_DATA ClassImageListData
 , OPTIONAL BYREF MachineName AS ASCIIZ _               ' __in_opt PCSTR MachineName
 , OPTIONAL BYVAL Reserved AS DWORD _                   ' __reserved PVOID Reserved
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SetupDiGetClassImageListExW LIB "SetupApi.dll" _
    ALIAS "SetupDiGetClassImageListExW" ( _
    BYVAL ClassImageListData AS SP_CLASSIMAGELIST_DATA PTR, _
    MachineName AS WSTRINGZ, _
    BYVAL Reserved AS DWORD _   ' PVOID
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupDiGetClassImageListExW IMPORT "SETUPAPI.DLL" ALIAS "SetupDiGetClassImageListExW" ( _
   BYREF ClassImageListData AS SP_CLASSIMAGELIST_DATA _ ' __out PSP_CLASSIMAGELIST_DATA ClassImageListData
 , OPTIONAL BYREF MachineName AS WSTRINGZ _             ' __in_opt PCWSTR MachineName
 , OPTIONAL BYVAL Reserved AS DWORD _                   ' __reserved PVOID Reserved
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%UNICODE)
   MACRO SetupDiGetClassImageListEx = SetupDiGetClassImageListExW
#ELSE
   MACRO SetupDiGetClassImageListEx = SetupDiGetClassImageListExA
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SetupDiGetClassImageIndex LIB "SetupApi.dll" _
    ALIAS "SetupDiGetClassImageIndex" ( _
    BYVAL ClassImageListData AS SP_CLASSIMAGELIST_DATA PTR, _
    ClassGuid AS GUID, _
    ImageIndex AS LONG _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupDiGetClassImageIndex IMPORT "SETUPAPI.DLL" ALIAS "SetupDiGetClassImageIndex" ( _
   BYREF ClassImageListData AS SP_CLASSIMAGELIST_DATA _ ' __in PSP_CLASSIMAGELIST_DATA ClassImageListData
 , BYREF ClassGuid AS GUID _                            ' __in CONST GUID *ClassGuid
 , BYREF ImageIndex AS LONG _                           ' __out PINT ImageIndex
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SetupDiDestroyClassImageList LIB "SetupApi.dll" _
    ALIAS "SetupDiDestroyClassImageList" ( _
    BYVAL ClassImageListData AS SP_CLASSIMAGELIST_DATA PTR _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupDiDestroyClassImageList IMPORT "SETUPAPI.DLL" ALIAS "SetupDiDestroyClassImageList" ( _
   BYREF ClassImageListData AS SP_CLASSIMAGELIST_DATA _ ' __in PSP_CLASSIMAGELIST_DATA ClassImageListData
 ) AS LONG                                              ' BOOL
#ENDIF

' //
' // PropertySheetType values for the SetupDiGetClassDevPropertySheets API
' //
%DIGCDP_FLAG_BASIC           = &H00000001???
%DIGCDP_FLAG_ADVANCED        = &H00000002???

'#if _SETUPAPI_VER >= _WIN32_WINNT_WINXP
#IF %SETUPAPI_VER >= %WIN32_WINNT_WINXP

%DIGCDP_FLAG_REMOTE_BASIC    = &H00000003???  ' // not presently implemented
%DIGCDP_FLAG_REMOTE_ADVANCED = &H00000004???

#ENDIF
'#endif // _SETUPAPI_VER >= _WIN32_WINNT_WINXP

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SetupDiGetClassDevPropertySheetsA LIB "SetupApi.dll" _
    ALIAS "SetupDiGetClassDevPropertySheetsA" ( _
    BYVAL DeviceInfoSet AS DWORD, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR, _
    PropertySheetHeader AS PROPSHEETHEADERA, _
    BYVAL PropertySheetHeaderPageListSize AS DWORD, _
    RequiredSize AS DWORD, _
    BYVAL PropertySheetType AS DWORD _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupDiGetClassDevPropertySheetsA IMPORT "SETUPAPI.DLL" ALIAS "SetupDiGetClassDevPropertySheetsA" ( _
   BYVAL DeviceInfoSet AS DWORD _                       ' __in HDEVINFO DeviceInfoSet
 , BYREF DeviceInfoData AS SP_DEVINFO_DATA _            ' __in_opt PSP_DEVINFO_DATA DeviceInfoData
 , BYREF PropertySheetHeader AS PROPSHEETHEADERA _      ' __in LPPROPSHEETHEADERA PropertySheetHeader
 , BYVAL PropertySheetHeaderPageListSize AS DWORD _     ' __in DWORD PropertySheetHeaderPageListSize
 , BYREF RequiredSize AS DWORD _                        ' __out_opt PDWORD RequiredSize
 , BYVAL PropertySheetType AS DWORD _                   ' __in DWORD PropertySheetType
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SetupDiGetClassDevPropertySheetsW LIB "SetupApi.dll" _
    ALIAS "SetupDiGetClassDevPropertySheetsW" ( _
    BYVAL DeviceInfoSet AS DWORD, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR, _
    PropertySheetHeader AS PROPSHEETHEADERW, _
    BYVAL PropertySheetHeaderPageListSize AS DWORD, _
    RequiredSize AS DWORD, _
    BYVAL PropertySheetType AS DWORD _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupDiGetClassDevPropertySheetsW IMPORT "SETUPAPI.DLL" ALIAS "SetupDiGetClassDevPropertySheetsW" ( _
   BYVAL DeviceInfoSet AS DWORD _                       ' __in HDEVINFO DeviceInfoSet
 , BYREF DeviceInfoData AS SP_DEVINFO_DATA _            ' __in_opt PSP_DEVINFO_DATA DeviceInfoData
 , BYREF PropertySheetHeader AS PROPSHEETHEADERW _      ' __in LPPROPSHEETHEADERW PropertySheetHeader
 , BYVAL PropertySheetHeaderPageListSize AS DWORD _     ' __in DWORD PropertySheetHeaderPageListSize
 , BYREF RequiredSize AS DWORD _                        ' __out_opt PDWORD RequiredSize
 , BYVAL PropertySheetType AS DWORD _                   ' __in DWORD PropertySheetType
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%UNICODE)
   MACRO SetupDiGetClassDevPropertySheets = SetupDiGetClassDevPropertySheetsW
#ELSE
   MACRO SetupDiGetClassDevPropertySheets = SetupDiGetClassDevPropertySheetsA
#ENDIF

' //
' // Define ICON IDs publicly exposed from setupapi.
' //
%IDI_RESOURCEFIRST          = 159
%IDI_RESOURCE               = 159
%IDI_RESOURCELAST           = 161
%IDI_RESOURCEOVERLAYFIRST   = 161
%IDI_RESOURCEOVERLAYLAST    = 161
%IDI_CONFLICT               = 161

%IDI_CLASSICON_OVERLAYFIRST = 500
%IDI_CLASSICON_OVERLAYLAST  = 502
%IDI_PROBLEM_OVL            = 500
%IDI_DISABLED_OVL           = 501
%IDI_FORCED_OVL             = 502

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SetupDiAskForOEMDisk LIB "SetupApi.dll" _
    ALIAS "SetupDiAskForOEMDisk" ( _
    BYVAL DeviceInfoSet AS DWORD, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupDiAskForOEMDisk IMPORT "SETUPAPI.DLL" ALIAS "SetupDiAskForOEMDisk" ( _
   BYVAL DeviceInfoSet AS DWORD _                       ' __in HDEVINFO DeviceInfoSet
 , OPTIONAL BYREF DeviceInfoData AS SP_DEVINFO_DATA _   ' __in_opt PSP_DEVINFO_DATA DeviceInfoData
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SetupDiSelectOEMDrv LIB "SetupApi.dll" _
    ALIAS "SetupDiSelectOEMDrv" ( _
    BYVAL hwndParent AS DWORD, _  ' HWND
    BYVAL DeviceInfoSet AS DWORD, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupDiSelectOEMDrv IMPORT "SETUPAPI.DLL" ALIAS "SetupDiSelectOEMDrv" ( _
   BYVAL hwndParent AS DWORD _                          ' __in_opt HWND hwndParent
 , BYVAL DeviceInfoSet AS DWORD _                       ' __in HDEVINFO DeviceInfoSet
 , OPTIONAL BYREF DeviceInfoData AS SP_DEVINFO_DATA _   ' __inout_opt PSP_DEVINFO_DATA DeviceInfoData
 ) AS LONG                                              ' BOOL
#ENDIF

DECLARE FUNCTION SetupDiClassNameFromGuidA IMPORT "SETUPAPI.DLL" ALIAS "SetupDiClassNameFromGuidA" ( _
   BYREF ClassGuid AS GUID _                            ' __in CONST GUID *ClassGuid
 , BYREF ClassName AS ASCIIZ _                          ' __out PSTR ClassName
 , BYVAL ClassNameSize AS DWORD _                       ' __in DWORD ClassNameSize
 , OPTIONAL BYREF RequiredSize AS DWORD _               ' __out_opt PDWORD RequiredSize
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SetupDiClassNameFromGuidW IMPORT "SETUPAPI.DLL" ALIAS "SetupDiClassNameFromGuidW" ( _
   BYREF ClassGuid AS GUID _                            ' __in CONST GUID *ClassGuid
 , BYREF ClassName AS WSTRINGZ _                        ' __out PWSTR ClassName
 , BYVAL ClassNameSize AS DWORD _                       ' __in DWORD ClassNameSize
 , OPTIONAL BYREF RequiredSize AS DWORD _               ' __out_opt PDWORD RequiredSize
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO SetupDiClassNameFromGuid = SetupDiClassNameFromGuidW
#ELSE
   MACRO SetupDiClassNameFromGuid = SetupDiClassNameFromGuidA
#ENDIF

DECLARE FUNCTION SetupDiClassNameFromGuidExA IMPORT "SETUPAPI.DLL" ALIAS "SetupDiClassNameFromGuidExA" ( _
   BYREF ClassGuid AS GUID _                            ' __in CONST GUID *ClassGuid
 , BYREF ClassName AS ASCIIZ _                          ' __out PSTR ClassName
 , BYVAL ClassNameSize AS DWORD _                       ' __in DWORD ClassNameSize
 , OPTIONAL BYREF RequiredSize AS DWORD _               ' __out_opt PDWORD RequiredSize
 , OPTIONAL BYREF MachineName AS ASCIIZ _               ' __in_opt PCSTR MachineName
 , OPTIONAL BYVAL Reserved AS DWORD _                   ' __reserved PVOID Reserved
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SetupDiClassNameFromGuidExW IMPORT "SETUPAPI.DLL" ALIAS "SetupDiClassNameFromGuidExW" ( _
   BYREF ClassGuid AS GUID _                            ' __in CONST GUID *ClassGuid
 , BYREF ClassName AS WSTRINGZ _                        ' __out PWSTR ClassName
 , BYVAL ClassNameSize AS DWORD _                       ' __in DWORD ClassNameSize
 , OPTIONAL BYREF RequiredSize AS DWORD _               ' __out_opt PDWORD RequiredSize
 , OPTIONAL BYREF MachineName AS WSTRINGZ _             ' __in_opt PCWSTR MachineName
 , OPTIONAL BYVAL Reserved AS DWORD _                   ' __reserved PVOID Reserved
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO SetupDiClassNameFromGuidEx = SetupDiClassNameFromGuidExW
#ELSE
   MACRO SetupDiClassNameFromGuidEx = SetupDiClassNameFromGuidExA
#ENDIF

DECLARE FUNCTION SetupDiClassGuidsFromNameA IMPORT "SETUPAPI.DLL" ALIAS "SetupDiClassGuidsFromNameA" ( _
   BYREF ClassName AS ASCIIZ _                          ' __in PCSTR ClassName
 , BYREF ClassGuidList AS GUID _                        ' __out LPGUID ClassGuidList
 , BYVAL ClassGuidListSize AS DWORD _                   ' __in DWORD ClassGuidListSize
 , BYREF RequiredSize AS DWORD _                        ' __out PDWORD RequiredSize
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SetupDiClassGuidsFromNameW IMPORT "SETUPAPI.DLL" ALIAS "SetupDiClassGuidsFromNameW" ( _
   BYREF ClassName AS WSTRINGZ _                        ' __in PCWSTR ClassName
 , BYREF ClassGuidList AS GUID _                        ' __out LPGUID ClassGuidList
 , BYVAL ClassGuidListSize AS DWORD _                   ' __in DWORD ClassGuidListSize
 , BYREF RequiredSize AS DWORD _                        ' __out PDWORD RequiredSize
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO SetupDiClassGuidsFromName = SetupDiClassGuidsFromNameW
#ELSE
   MACRO SetupDiClassGuidsFromName = SetupDiClassGuidsFromNameA
#ENDIF

DECLARE FUNCTION SetupDiClassGuidsFromNameExA IMPORT "SETUPAPI.DLL" ALIAS "SetupDiClassGuidsFromNameExA" ( _
   BYREF ClassName AS ASCIIZ _                          ' __in PCSTR ClassName
 , BYREF ClassGuidList AS GUID _                        ' __out LPGUID ClassGuidList
 , BYVAL ClassGuidListSize AS DWORD _                   ' __in DWORD ClassGuidListSize
 , BYREF RequiredSize AS DWORD _                        ' __out PDWORD RequiredSize
 , OPTIONAL BYREF MachineName AS ASCIIZ _               ' __in_opt PCSTR MachineName
 , OPTIONAL BYVAL Reserved AS DWORD _                   ' __reserved PVOID Reserved
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SetupDiClassGuidsFromNameExW IMPORT "SETUPAPI.DLL" ALIAS "SetupDiClassGuidsFromNameExW" ( _
   BYREF ClassName AS WSTRINGZ _                        ' __in PCWSTR ClassName
 , BYREF ClassGuidList AS GUID _                        ' __out LPGUID ClassGuidList
 , BYVAL ClassGuidListSize AS DWORD _                   ' __in DWORD ClassGuidListSize
 , BYREF RequiredSize AS DWORD _                        ' __out PDWORD RequiredSize
 , OPTIONAL BYREF MachineName AS WSTRINGZ _             ' __in_opt PCWSTR MachineName
 , OPTIONAL BYVAL Reserved AS DWORD _                   ' __reserved PVOID Reserved
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO SetupDiClassGuidsFromNameEx = SetupDiClassGuidsFromNameExW
#ELSE
   MACRO SetupDiClassGuidsFromNameEx = SetupDiClassGuidsFromNameExA
#ENDIF

DECLARE FUNCTION SetupDiGetHwProfileFriendlyNameA IMPORT "SETUPAPI.DLL" ALIAS "SetupDiGetHwProfileFriendlyNameA" ( _
   BYVAL HwProfile AS DWORD _                           ' __in DWORD HwProfile
 , BYREF FriendlyName AS ASCIIZ _                       ' __out PSTR FriendlyName
 , BYVAL FriendlyNameSize AS DWORD _                    ' __in DWORD FriendlyNameSize
 , OPTIONAL BYREF RequiredSize AS DWORD _               ' __out_opt PDWORD RequiredSize
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SetupDiGetHwProfileFriendlyNameW IMPORT "SETUPAPI.DLL" ALIAS "SetupDiGetHwProfileFriendlyNameW" ( _
   BYVAL HwProfile AS DWORD _                           ' __in DWORD HwProfile
 , BYREF FriendlyName AS WSTRINGZ _                     ' __out PWSTR FriendlyName
 , BYVAL FriendlyNameSize AS DWORD _                    ' __in DWORD FriendlyNameSize
 , OPTIONAL BYREF RequiredSize AS DWORD _               ' __out_opt PDWORD RequiredSize
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO SetupDiGetHwProfileFriendlyName = SetupDiGetHwProfileFriendlyNameW
#ELSE
   MACRO SetupDiGetHwProfileFriendlyName = SetupDiGetHwProfileFriendlyNameA
#ENDIF

DECLARE FUNCTION SetupDiGetHwProfileFriendlyNameExA IMPORT "SETUPAPI.DLL" ALIAS "SetupDiGetHwProfileFriendlyNameExA" ( _
   BYVAL HwProfile AS DWORD _                           ' __in DWORD HwProfile
 , BYREF FriendlyName AS ASCIIZ _                       ' __out PSTR FriendlyName
 , BYVAL FriendlyNameSize AS DWORD _                    ' __in DWORD FriendlyNameSize
 , OPTIONAL BYREF RequiredSize AS DWORD _               ' __out_opt PDWORD RequiredSize
 , OPTIONAL BYREF MachineName AS ASCIIZ _               ' __in_opt PCSTR MachineName
 , OPTIONAL BYVAL Reserved AS DWORD _                   ' __reserved PVOID Reserved
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SetupDiGetHwProfileFriendlyNameExW IMPORT "SETUPAPI.DLL" ALIAS "SetupDiGetHwProfileFriendlyNameExW" ( _
   BYVAL HwProfile AS DWORD _                           ' __in DWORD HwProfile
 , BYREF FriendlyName AS WSTRINGZ _                     ' __out PWSTR FriendlyName
 , BYVAL FriendlyNameSize AS DWORD _                    ' __in DWORD FriendlyNameSize
 , OPTIONAL BYREF RequiredSize AS DWORD _               ' __out_opt PDWORD RequiredSize
 , OPTIONAL BYREF MachineName AS WSTRINGZ _             ' __in_opt PCWSTR MachineName
 , OPTIONAL BYVAL Reserved AS DWORD _                   ' __reserved PVOID Reserved
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO SetupDiGetHwProfileFriendlyNameEx = SetupDiGetHwProfileFriendlyNameExW
#ELSE
   MACRO SetupDiGetHwProfileFriendlyNameEx = SetupDiGetHwProfileFriendlyNameExA
#ENDIF

' //
' // PageType values for SetupDiGetWizardPage API
' //
%SPWPT_SELECTDEVICE      = &H00000001???

' //
' // Flags for SetupDiGetWizardPage API
' //
%SPWP_USE_DEVINFO_DATA   = &H00000001???

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SetupDiGetWizardPage LIB "SetupApi.dll" _
    ALIAS "SetupDiGetWizardPage" ( _
    BYVAL DeviceInfoSet AS DWORD, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR, _
    BYVAL InstallWizardData AS SP_INSTALLWIZARD_DATA PTR, _
    BYVAL PageType AS DWORD, _
    BYVAL Flags AS DWORD _
    ) AS DWORD  ' HPROPSHEETPAGE
#ELSE
DECLARE FUNCTION SetupDiGetWizardPage IMPORT "SETUPAPI.DLL" ALIAS "SetupDiGetWizardPage" ( _
   BYVAL DeviceInfoSet AS DWORD _                       ' __in HDEVINFO DeviceInfoSet
 , BYREF DeviceInfoData AS SP_DEVINFO_DATA _            ' __in_opt PSP_DEVINFO_DATA DeviceInfoData
 , BYREF InstallWizardData AS SP_INSTALLWIZARD_DATA _   ' __in PSP_INSTALLWIZARD_DATA InstallWizardData
 , BYVAL PageType AS DWORD _                            ' __in DWORD PageType
 , BYVAL Flags AS DWORD _                               ' __in DWORD Flags
 ) AS DWORD                                             ' HPROPSHEETPAGE
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SetupDiGetSelectedDevice LIB "SetupApi.dll" _
    ALIAS "SetupDiGetSelectedDevice" ( _
    BYVAL DeviceInfoSet AS DWORD, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupDiGetSelectedDevice IMPORT "SETUPAPI.DLL" ALIAS "SetupDiGetSelectedDevice" ( _
   BYVAL DeviceInfoSet AS DWORD _                       ' __in HDEVINFO DeviceInfoSet
 , BYREF DeviceInfoData AS SP_DEVINFO_DATA _            ' __out PSP_DEVINFO_DATA DeviceInfoData
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SetupDiSetSelectedDevice LIB "SetupApi.dll" _
    ALIAS "SetupDiSetSelectedDevice" ( _
    BYVAL DeviceInfoSet AS DWORD, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupDiSetSelectedDevice IMPORT "SETUPAPI.DLL" ALIAS "SetupDiSetSelectedDevice" ( _
   BYVAL DeviceInfoSet AS DWORD _                       ' __in HDEVINFO DeviceInfoSet
 , BYREF DeviceInfoData AS SP_DEVINFO_DATA _            ' __in PSP_DEVINFO_DATA DeviceInfoData
 ) AS LONG                                              ' BOOL
#ENDIF

'#if _SETUPAPI_VER >= _WIN32_WINNT_WS03
#IF %SETUPAPI_VER >= %WIN32_WINNT_WS03

DECLARE FUNCTION SetupDiGetActualModelsSectionA IMPORT "SETUPAPI.DLL" ALIAS "SetupDiGetActualModelsSectionA" ( _
   BYREF Context AS INFCONTEXT _                        ' __in PINFCONTEXT Context
 , BYREF AlternatePlatformInfo AS SP_ALTPLATFORM_INFO _ ' __in_opt PSP_ALTPLATFORM_INFO AlternatePlatformInfo
 , BYREF InfSectionWithExt AS ASCIIZ _                  ' __out PSTR InfSectionWithExt
 , BYVAL InfSectionWithExtSize AS DWORD _               ' __in DWORD InfSectionWithExtSize
 , OPTIONAL BYREF RequiredSize AS DWORD _               ' __out_opt PDWORD RequiredSize
 , OPTIONAL BYVAL Reserved AS DWORD _                   ' __reserved PVOID Reserved
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SetupDiGetActualModelsSectionW IMPORT "SETUPAPI.DLL" ALIAS "SetupDiGetActualModelsSectionW" ( _
   BYREF Context AS INFCONTEXT _                        ' __in PINFCONTEXT Context
 , BYREF AlternatePlatformInfo AS SP_ALTPLATFORM_INFO _ ' __in_opt PSP_ALTPLATFORM_INFO AlternatePlatformInfo
 , BYREF InfSectionWithExt AS WSTRINGZ _                ' __out PWSTR InfSectionWithExt
 , BYVAL InfSectionWithExtSize AS DWORD _               ' __in DWORD InfSectionWithExtSize
 , OPTIONAL BYREF RequiredSize AS DWORD _               ' __out_opt PDWORD RequiredSize
 , OPTIONAL BYVAL Reserved AS DWORD _                   ' __reserved PVOID Reserved
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO SetupDiGetActualModelsSection = SetupDiGetActualModelsSectionW
#ELSE
   MACRO SetupDiGetActualModelsSection = SetupDiGetActualModelsSectionA
#ENDIF

#ENDIF
'#endif // _SETUPAPI_VER >= _WIN32_WINNT_WS03

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SetupDiGetActualSectionToInstallA LIB "SetupApi.dll" _
    ALIAS "SetupDiGetActualSectionToInstallA" ( _
    BYVAL InfHandle AS DWORD, _
    InfSectionName AS ASCIIZ, _
    InfSectionWithExt AS ASCIIZ, _
    BYVAL InfSectionWithExtSize AS DWORD, _
    RequiredSize AS DWORD, _
    BYVAL Extension AS DWORD _   ' PSTR *
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupDiGetActualSectionToInstallA IMPORT "SETUPAPI.DLL" ALIAS "SetupDiGetActualSectionToInstallA" ( _
   BYVAL InfHandle AS DWORD _                           ' __in HINF InfHandle
 , BYREF InfSectionName AS ASCIIZ _                     ' __in PCSTR InfSectionName
 , BYREF InfSectionWithExt AS ASCIIZ _                  ' __out PSTR InfSectionWithExt
 , BYVAL InfSectionWithExtSize AS DWORD _               ' __in DWORD InfSectionWithExtSize
 , OPTIONAL BYREF RequiredSize AS DWORD _               ' __out_opt PDWORD RequiredSize
 , OPTIONAL BYREF Extension AS DWORD _                  ' __out_opt PSTR *Extension
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SetupDiGetActualSectionToInstallW LIB "SetupApi.dll" _
    ALIAS "SetupDiGetActualSectionToInstallW" ( _
    BYVAL InfHandle AS DWORD, _
    InfSectionName AS WSTRINGZ, _
    InfSectionWithExt AS WSTRINGZ, _
    BYVAL InfSectionWithExtSize AS DWORD, _
    RequiredSize AS DWORD, _
    BYVAL Extension AS DWORD _   ' PWSTR *
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupDiGetActualSectionToInstallW IMPORT "SETUPAPI.DLL" ALIAS "SetupDiGetActualSectionToInstallW" ( _
   BYVAL InfHandle AS DWORD _                           ' __in HINF InfHandle
 , BYREF InfSectionName AS WSTRINGZ  _                  ' __in PCWSTR InfSectionName
 , BYREF InfSectionWithExt AS WSTRINGZ _                ' __out PWSTR InfSectionWithExt
 , BYVAL InfSectionWithExtSize AS DWORD _               ' __in DWORD InfSectionWithExtSize
 , OPTIONAL BYREF RequiredSize AS DWORD _               ' __out_opt PDWORD RequiredSize
 , OPTIONAL BYREF Extension AS DWORD _                  ' __out_opt PWSTR *Extension
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%UNICODE)
   MACRO SetupDiGetActualSectionToInstall = SetupDiGetActualSectionToInstallW
#ELSE
   MACRO SetupDiGetActualSectionToInstall = SetupDiGetActualSectionToInstallA
#ENDIF

'#if _SETUPAPI_VER >= _WIN32_WINNT_WINXP
#IF %SETUPAPI_VER >= %WIN32_WINNT_WINXP

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SetupDiGetActualSectionToInstallExA LIB "SetupApi.dll" _
    ALIAS "SetupDiGetActualSectionToInstallExA" ( _
    BYVAL InfHandle AS DWORD, _
    InfSectionName AS ASCIIZ, _
    BYVAL AlternatePlatformInfo AS SP_ALTPLATFORM_INFO PTR, _
    InfSectionWithExt AS ASCIIZ, _
    BYVAL InfSectionWithExtSize AS DWORD, _
    RequiredSize AS DWORD, _
    BYVAL Extension AS DWORD, _  ' PSTR *
    BYVAL Reserved AS DWORD _    ' PVOID
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupDiGetActualSectionToInstallExA IMPORT "SETUPAPI.DLL" ALIAS "SetupDiGetActualSectionToInstallExA" ( _
   BYVAL InfHandle AS DWORD _                           ' __in HINF InfHandle
 , BYREF InfSectionName AS ASCIIZ _                     ' __in PCSTR InfSectionName
 , BYREF AlternatePlatformInfo AS SP_ALTPLATFORM_INFO _ ' __in_opt PSP_ALTPLATFORM_INFO AlternatePlatformInfo
 , BYREF InfSectionWithExt AS ASCIIZ _                  ' __out PSTR InfSectionWithExt
 , BYVAL InfSectionWithExtSize AS DWORD _               ' __in DWORD InfSectionWithExtSize
 , OPTIONAL BYREF RequiredSize AS DWORD _               ' __out_opt PDWORD RequiredSize
 , OPTIONAL BYREF Extension AS DWORD _                  ' __out_opt PSTR *Extension
 , OPTIONAL BYVAL Reserved AS DWORD _                   ' __reserved PVOID Reserved
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SetupDiGetActualSectionToInstallExW LIB "SetupApi.dll" _
    ALIAS "SetupDiGetActualSectionToInstallExW" ( _
    BYVAL InfHandle AS DWORD, _
    InfSectionName AS WSTRINGZ, _
    BYVAL AlternatePlatformInfo AS SP_ALTPLATFORM_INFO PTR, _
    InfSectionWithExt AS WSTRINGZ, _
    BYVAL InfSectionWithExtSize AS DWORD, _
    RequiredSize AS DWORD, _
    BYVAL Extension AS DWORD, _   ' PWSTR *
    BYVAL Reserved AS DWORD _     ' PVOID
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupDiGetActualSectionToInstallExW IMPORT "SETUPAPI.DLL" ALIAS "SetupDiGetActualSectionToInstallExW" ( _
   BYVAL InfHandle AS DWORD _                           ' __in HINF InfHandle
 , BYREF InfSectionName AS ASCIIZ _                     ' __in PCSTR InfSectionName
 , BYREF AlternatePlatformInfo AS SP_ALTPLATFORM_INFO _ ' __in_opt PSP_ALTPLATFORM_INFO AlternatePlatformInfo
 , BYREF InfSectionWithExt AS WSTRINGZ _                ' __out PWSTR InfSectionWithExt
 , BYVAL InfSectionWithExtSize AS DWORD _               ' __in DWORD InfSectionWithExtSize
 , OPTIONAL BYREF RequiredSize AS DWORD _               ' __out_opt PDWORD RequiredSize
 , OPTIONAL BYREF Extension AS DWORD _                  ' __out_opt PWSTR *Extension
 , OPTIONAL BYVAL Reserved AS DWORD _                   ' __reserved PVOID Reserved
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%UNICODE)
   MACRO SetupDiGetActualSectionToInstallEx = SetupDiGetActualSectionToInstallExW
#ELSE
   MACRO SetupDiGetActualSectionToInstallEx = SetupDiGetActualSectionToInstallExA
#ENDIF

#ENDIF
'#endif // _SETUPAPI_VER >= _WIN32_WINNT_WINXP


'#if _SETUPAPI_VER >= _WIN32_WINNT_WINXP
#IF %SETUPAPI_VER >= %WIN32_WINNT_WINXP

' //
' // SetupEnumInfSections is for low-level parsing of an INF
' //

DECLARE FUNCTION SetupEnumInfSectionsA IMPORT "SETUPAPI.DLL" ALIAS "SetupEnumInfSectionsA" ( _
   BYVAL InfHandle AS DWORD _                           ' __in HINF InfHandle
 , BYVAL Index AS DWORD _                               ' __in UINT Index
 , BYREF Buffer AS ASCIIZ _                             ' __out PSTR Buffer
 , BYVAL Size AS DWORD _                                ' __in UINT Size
 , OPTIONAL BYREF SizeNeeded AS DWORD _                 ' __out_opt UINT *SizeNeeded
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SetupEnumInfSectionsW IMPORT "SETUPAPI.DLL" ALIAS "SetupEnumInfSectionsW" ( _
   BYVAL InfHandle AS DWORD _                           ' __in HINF InfHandle
 , BYVAL Index AS DWORD _                               ' __in UINT Index
 , BYREF Buffer AS WSTRINGZ _                           ' __out PWSTR Buffer
 , BYVAL Size AS DWORD _                                ' __in UINT Size
 , OPTIONAL BYREF SizeNeeded AS DWORD _                 ' __out_opt UINT *SizeNeeded
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO SetupEnumInfSections = SetupEnumInfSectionsW
#ELSE
   MACRO SetupEnumInfSections = SetupEnumInfSectionsA
#ENDIF

#ENDIF
'#endif // _SETUPAPI_VER >= _WIN32_WINNT_WINXP

'#if _SETUPAPI_VER >= _WIN32_WINNT_WINXP
#IF %SETUPAPI_VER >= %WIN32_WINNT_WINXP

' // Size = 784 bytes
TYPE SP_INF_SIGNER_INFO_V1_A BYTE
   cbSize               AS DWORD                ' DWORD
   CatalogFile          AS ASCIIZ * %MAX_PATH   ' CHAR
   DigitalSigner        AS ASCIIZ * %MAX_PATH   ' CHAR
   DigitalSignerVersion AS ASCIIZ * %MAX_PATH   ' CHAR
END TYPE

' // Size = 1564 bytes
TYPE SP_INF_SIGNER_INFO_V1_W BYTE
   cbSize               AS DWORD                  ' DWORD
   CatalogFile          AS WSTRINGZ * %MAX_PATH   ' WCHAR
   DigitalSigner        AS WSTRINGZ * %MAX_PATH   ' WCHAR
   DigitalSignerVersion AS WSTRINGZ * %MAX_PATH   ' WCHAR
END TYPE

#IF %DEF(%UNICODE)
   MACRO SP_INF_SIGNER_INFO_V1 = SP_INF_SIGNER_INFO_V1_W
#ELSE
   MACRO SP_INF_SIGNER_INFO_V1 = SP_INF_SIGNER_INFO_V1_A
#ENDIF

'#if _SETUPAPI_VER >= _WIN32_WINNT_LONGHORN
#IF %SETUPAPI_VER >= %WIN32_WINNT_LONGHORN

' // Size = 788 bytes
TYPE SP_INF_SIGNER_INFO_V2_A BYTE
   cbSize               AS DWORD                ' DWORD
   CatalogFile          AS ASCIIZ * %MAX_PATH   ' CHAR
   DigitalSigner        AS ASCIIZ * %MAX_PATH   ' CHAR
   DigitalSignerVersion AS ASCIIZ * %MAX_PATH   ' CHAR
   SignerScore          AS DWORD                ' DWORD
END TYPE

' // Size = 1568 bytes
TYPE SP_INF_SIGNER_INFO_V2_W BYTE
   cbSize               AS DWORD                  ' DWORD
   CatalogFile          AS WSTRINGZ * %MAX_PATH   ' WCHAR
   DigitalSigner        AS WSTRINGZ * %MAX_PATH   ' WCHAR
   DigitalSignerVersion AS WSTRINGZ * %MAX_PATH   ' WCHAR
   SignerScore          AS DWORD                  ' DWORD
END TYPE

#IF %DEF(%UNICODE)
   MACRO SP_INF_SIGNER_INFO_V2 = SP_INF_SIGNER_INFO_V2_W
#ELSE
   MACRO SP_INF_SIGNER_INFO_V2 = SP_INF_SIGNER_INFO_V2_A
#ENDIF

'//
'// Driver signer scores (high order bit of the signing byte means unsigned)
'//
%SIGNERSCORE_UNKNOWN         = &HFF000000
%SIGNERSCORE_W9X_SUSPECT     = &HC0000000
%SIGNERSCORE_UNSIGNED        = &H80000000
%SIGNERSCORE_AUTHENTICODE    = &H0F000000
%SIGNERSCORE_WHQL            = &H0D000005  ' // base WHQL.
%SIGNERSCORE_UNCLASSIFIED    = &H0D000004  ' // UNCLASSIFIED == INBOX == STANDARD == PREMIUM when the SIGNERSCORE_MASK
%SIGNERSCORE_INBOX           = &H0D000003  ' // filter is applied.
%SIGNERSCORE_LOGO_STANDARD   = &H0D000002
%SIGNERSCORE_LOGO_PREMIUM    = &H0D000001

%SIGNERSCORE_MASK            = &HFF000000  ' // Mask out all but the upper BYTE which contains the ranking signer information
%SIGNERSCORE_SIGNED_MASK     = &HF0000000  ' // Mask out only the upper nibble, which tells us if the package is signed or not.

#ENDIF
'#endif // _SETUPAPI_VER >= _WIN32_WINNT_LONGHORN

'#if USE_SP_INF_SIGNER_INFO_V1 || (_SETUPAPI_VER < _WIN32_WINNT_LONGHORN)  // use version 1 signer info structure
#IF %DEF(%USE_SP_INF_SIGNER_INFO_V1) OR (%SETUPAPI_VER < %WIN32_WINNT_LONGHORN)  ' // use version 1 signer info structure

MACRO SP_INF_SIGNER_INFO_A = SP_INF_SIGNER_INFO_V1_A
MACRO SP_INF_SIGNER_INFO_W = SP_INF_SIGNER_INFO_V1_W
#IF %DEF(%UNICODE)
   MACRO SP_INF_SIGNER_INFO = SP_INF_SIGNER_INFO_V1_W
#ELSE
   MACRO SP_INF_SIGNER_INFO = SP_INF_SIGNER_INFO_V1_A
#ENDIF

#ELSE                      ' // use version 2 signer info structure

MACRO SP_INF_SIGNER_INFO_A = SP_INF_SIGNER_INFO_V2_A
MACRO SP_INF_SIGNER_INFO_W = SP_INF_SIGNER_INFO_V2_W
#IF %DEF(%UNICODE)
   MACRO SP_INF_SIGNER_INFO = SP_INF_SIGNER_INFO_V2_W
#ELSE
   MACRO SP_INF_SIGNER_INFO = SP_INF_SIGNER_INFO_V2_A
#ENDIF

#ENDIF   ' // use current version of signer info structure

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SetupVerifyInfFileA LIB "SetupApi.dll" _
    ALIAS "SetupVerifyInfFileA" ( _
    InfName AS ASCIIZ, _
    BYVAL AltPlatformInfo AS SP_ALTPLATFORM_INFO PTR, _
    BYVAL InfSignerInfo AS SP_INF_SIGNER_INFO_A PTR _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupVerifyInfFileA IMPORT "SETUPAPI.DLL" ALIAS "SetupVerifyInfFileA" ( _
   BYREF InfName AS ASCIIZ _                            ' __in PCSTR InfName
 , BYREF AltPlatformInfo AS SP_ALTPLATFORM_INFO _       ' __in_opt PSP_ALTPLATFORM_INFO AltPlatformInfo
 , BYREF InfSignerInfo AS SP_INF_SIGNER_INFO_A _        ' __out PSP_INF_SIGNER_INFO_A InfSignerInfo
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SetupVerifyInfFileW LIB "SetupApi.dll" _
    ALIAS "SetupVerifyInfFileW" ( _
    InfName AS WSTRINGZ, _
    BYVAL AltPlatformInfo AS SP_ALTPLATFORM_INFO PTR, _
    BYVAL InfSignerInfo AS SP_INF_SIGNER_INFO_W PTR _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupVerifyInfFileW IMPORT "SETUPAPI.DLL" ALIAS "SetupVerifyInfFileW" ( _
   BYREF InfName AS WSTRINGZ _                          ' __in PCWSTR InfName
 , BYREF AltPlatformInfo AS SP_ALTPLATFORM_INFO _       ' __in_opt PSP_ALTPLATFORM_INFO AltPlatformInfo
 , BYREF InfSignerInfo AS SP_INF_SIGNER_INFO_W _        ' __out PSP_INF_SIGNER_INFO_W InfSignerInfo
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%UNICODE)
   MACRO SetupVerifyInfFile = SetupVerifyInfFileW
#ELSE
   MACRO SetupVerifyInfFile = SetupVerifyInfFileA
#ENDIF

#ENDIF
'#endif // _SETUPAPI_VER >= _WIN32_WINNT_WINXP

'#if _SETUPAPI_VER >= _WIN32_WINNT_WINXP
#IF %SETUPAPI_VER >= %WIN32_WINNT_WINXP

' //
' // Flags for use by SetupDiGetCustomDeviceProperty
' //
%DICUSTOMDEVPROP_MERGE_MULTISZ    = &H00000001???

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SetupDiGetCustomDevicePropertyA LIB "SetupApi.dll" _
    ALIAS "SetupDiGetCustomDevicePropertyA" ( _
    BYVAL DeviceInfoSet AS DWORD, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR, _
    CustomPropertyName AS ASCIIZ, _
    BYVAL Flags AS DWORD, _
    PropertyRegDataType AS DWORD, _
    BYVAL PropertyBuffer AS BYTE PTR, _
    BYVAL PropertyBufferSize AS DWORD, _
    RequiredSize AS DWORD _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupDiGetCustomDevicePropertyA IMPORT "SETUPAPI.DLL" ALIAS "SetupDiGetCustomDevicePropertyA" ( _
   BYVAL DeviceInfoSet AS DWORD _                       ' __in HDEVINFO DeviceInfoSet
 , BYREF DeviceInfoData AS SP_DEVINFO_DATA _            ' __in PSP_DEVINFO_DATA DeviceInfoData
 , BYREF CustomPropertyName AS ASCIIZ _                 ' __in PCSTR CustomPropertyName
 , BYVAL Flags AS DWORD _                               ' __in DWORD Flags
 , BYREF PropertyRegDataType AS DWORD _                 ' __out_opt PDWORD PropertyRegDataType
 , BYREF PropertyBuffer AS ANY _                        ' __out PBYTE PropertyBuffer
 , BYVAL PropertyBufferSize AS DWORD _                  ' __in DWORD PropertyBufferSize
 , OPTIONAL BYREF RequiredSize AS DWORD _               ' __out_opt PDWORD RequiredSize
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%USEPBDECL)
DECLARE FUNCTION SetupDiGetCustomDevicePropertyW LIB "SetupApi.dll" _
    ALIAS "SetupDiGetCustomDevicePropertyW" ( _
    BYVAL DeviceInfoSet AS DWORD, _
    BYVAL DeviceInfoData AS SP_DEVINFO_DATA PTR, _
    CustomPropertyName AS WSTRINGZ, _
    BYVAL Flags AS DWORD, _
    PropertyRegDataType AS DWORD, _
    BYVAL PropertyBuffer AS BYTE PTR, _
    BYVAL PropertyBufferSize AS DWORD, _
    RequiredSize AS DWORD _
    ) AS LONG  ' BOOL
#ELSE
DECLARE FUNCTION SetupDiGetCustomDevicePropertyW IMPORT "SETUPAPI.DLL" ALIAS "SetupDiGetCustomDevicePropertyW" ( _
   BYVAL DeviceInfoSet AS DWORD _                       ' __in HDEVINFO DeviceInfoSet
 , BYREF DeviceInfoData AS SP_DEVINFO_DATA _            ' __in PSP_DEVINFO_DATA DeviceInfoData
 , BYREF CustomPropertyName AS ASCIIZ _                 ' __in PCSTR CustomPropertyName
 , BYVAL Flags AS DWORD _                               ' __in DWORD Flags
 , BYREF PropertyRegDataType AS DWORD _                 ' __out_opt PDWORD PropertyRegDataType
 , BYREF PropertyBuffer AS ANY _                        ' __out PBYTE PropertyBuffer
 , BYVAL PropertyBufferSize AS DWORD _                  ' __in DWORD PropertyBufferSize
 , OPTIONAL BYREF RequiredSize AS DWORD _               ' __out_opt PDWORD RequiredSize
 ) AS LONG                                              ' BOOL
#ENDIF

#IF %DEF(%UNICODE)
   MACRO SetupDiGetCustomDeviceProperty = SetupDiGetCustomDevicePropertyW
#ELSE
   MACRO SetupDiGetCustomDeviceProperty = SetupDiGetCustomDevicePropertyA
#ENDIF

#ENDIF
'#endif // _SETUPAPI_VER >= _WIN32_WINNT_WINXP


'#if _SETUPAPI_VER >= _WIN32_WINNT_WS03
#IF %SETUPAPI_VER >= %WIN32_WINNT_WS03

' //
' // To configure WMI security for downlevel platforms where the [DDInstall.WMI]
' // section isn't natively supported by setupapi, a redistributable co-installer
' // is supplied in the DDK for use on those platforms.
' //

' //
' // Flags for use by SetupConfigureWmiFromInfSection
' //
%SCWMI_CLOBBER_SECURITY  = &H00000001???

DECLARE FUNCTION SetupConfigureWmiFromInfSectionA IMPORT "SETUPAPI.DLL" ALIAS "SetupConfigureWmiFromInfSectionA" ( _
   BYVAL InfHandle AS DWORD _                           ' __in HINF InfHandle
 , BYREF SectionName AS ASCIIZ _                        ' __in PCSTR SectionName
 , BYVAL Flags AS DWORD _                               ' __in DWORD Flags
 ) AS LONG                                              ' BOOL

DECLARE FUNCTION SetupConfigureWmiFromInfSectionW IMPORT "SETUPAPI.DLL" ALIAS "SetupConfigureWmiFromInfSectionW" ( _
   BYVAL InfHandle AS DWORD _                           ' __in HINF InfHandle
 , BYREF SectionName AS WSTRINGZ _                      ' __in PCWSTR SectionName
 , BYVAL Flags AS DWORD _                               ' __in DWORD Flags
 ) AS LONG                                              ' BOOL

#IF %DEF(%UNICODE)
   MACRO SetupConfigureWmiFromInfSection = SetupConfigureWmiFromInfSectionW
#ELSE
   MACRO SetupConfigureWmiFromInfSection = SetupConfigureWmiFromInfSectionA
#ENDIF

#ENDIF
'#endif // _SETUPAPI_VER >= _WIN32_WINNT_WS03

'#include <poppack.h>
