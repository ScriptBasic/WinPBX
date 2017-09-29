' ########################################################################################
' Microsoft Windows
' File: Windows.inc
' Contents: Master include file for Windows applications.
' Copyright (c) 2011-2014 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%WINDOWS_INC = 1

$JRS_HEADERS_VERSION = "3.1.07"

' // Windows version
#INCLUDE ONCE "sdkddkver.inc"

'/*  If defined, the following flags inhibit definition
' *     of the indicated items.
' *
' *  NOGDICAPMASKS     - CC_*, LC_*, PC_*, CP_*, TC_*, RC_
' *  NOVIRTUALKEYCODES - VK_*
' *  NOWINMESSAGES     - WM_*, EM_*, LB_*, CB_*
' *  NOWINSTYLES       - WS_*, CS_*, ES_*, LBS_*, SBS_*, CBS_*
' *  NOSYSMETRICS      - SM_*
' *  NOMENUS           - MF_*
' *  NOICONS           - IDI_*
' *  NOKEYSTATES       - MK_*
' *  NOSYSCOMMANDS     - SC_*
' *  NORASTEROPS       - Binary and Tertiary raster ops
' *  NOSHOWWINDOW      - SW_*
' *  OEMRESOURCE       - OEM Resource values
' *  NOATOM            - Atom Manager routines
' *  NOCLIPBOARD       - Clipboard routines
' *  NOCOLOR           - Screen colors
' *  NOCTLMGR          - Control and Dialog routines
' *  NODRAWTEXT        - DrawText() and DT_*
' *  NOGDI             - All GDI defines and routines
' *  NOKERNEL          - All KERNEL defines and routines
' *  NOUSER            - All USER defines and routines
' *  NONLS             - All NLS defines and routines
' *  NOMB              - MB_* and MessageBox()
' *  NOMEMMGR          - GMEM_*, LMEM_*, GHND, LHND, associated routines
' *  NOMETAFILE        - typedef METAFILEPICT
' *  NOMINMAX          - Macros min(a,b) and max(a,b)
' *  NOMSG             - typedef MSG and associated routines
' *  NOOPENFILE        - OpenFile(), OemToAnsi, AnsiToOem, and OF_*
' *  NOSCROLL          - SB_* and scrolling routines
' *  NOSERVICE         - All Service Controller routines, SERVICE_ equates, etc.
' *  NOSOUND           - Sound driver routines
' *  NOTEXTMETRIC      - typedef TEXTMETRIC and associated routines
' *  NOWH              - SetWindowsHook and WH_*
' *  NOWINOFFSETS      - GWL_*, GCL_*, associated routines
' *  NOCOMM            - COMM driver routines
' *  NOKANJI           - Kanji support stuff.
' *  NOHELP            - Help engine interface.
' *  NOPROFILER        - Profiler interface.
' *  NODEFERWINDOWPOS  - DeferWindowPos routines
' *  NOMCX             - Modem Configuration Extensions
' */

' =============================================================================
'' Include files
' =============================================================================

#INCLUDE ONCE "windef.inc"
#INCLUDE ONCE "winerror.inc"
#INCLUDE ONCE "winbase.inc"
#INCLUDE ONCE "wingdi.inc"
#INCLUDE ONCE "winuser.inc"
#INCLUDE ONCE "winnls.inc"
#INCLUDE ONCE "wincon.inc"
#INCLUDE ONCE "winver.inc"
#INCLUDE ONCE "winreg.inc"
#INCLUDE ONCE "winnetwk.inc"

#IF NOT %DEF(%WIN32_LEAN_AND_MEAN)

#INCLUDE ONCE "cderr.inc"
#INCLUDE ONCE "dde.inc"
#INCLUDE ONCE "ddeml.inc"
#INCLUDE ONCE "dlgs.inc"
#INCLUDE ONCE "lzexpand.inc"
#INCLUDE ONCE "mmsystem.inc"
#INCLUDE ONCE "nb30.inc"

#INCLUDE ONCE "rpc.inc"
#INCLUDE ONCE "shellapi.inc"

#INCLUDE ONCE "winperf.inc"

#IF NOT %DEF(%WINSOCK2API)
#INCLUDE ONCE "winsock2.inc"
#ENDIF

#IF NOT %DEF(%NOCRYPT)
#INCLUDE ONCE "wincrypt.inc"
#INCLUDE ONCE "winefs.inc"
#INCLUDE ONCE "winscard.inc"
#ENDIF

#IF NOT %DEF(%NOGDI)
#INCLUDE ONCE "winspool.inc"
#ENDIF

#ENDIF   ' #IF NOT %DEF(%WIN32_LEAN_AND_MEAN)

#IF %DEF(%INC_OLE2)
#INCLUDE ONCE "ole2.inc"
#ENDIF

#IF NOT %DEF(%NOSERVICE)
#INCLUDE ONCE "winsvc.inc"
#ENDIF

#IF NOT %DEF(%NOMCX)
#INCLUDE ONCE "mcx.inc"
#ENDIF

#IF NOT %DEF(%NOIME)
#INCLUDE ONCE "imm.inc"
#ENDIF

' File attributes (the remed ones are predefined in the compiler)
'%Normal   = &B000000
%ReadOnly = &B000001
'%Hidden   = &B000010
'%System   = &B000100
'%vLabel   = &B001000
'%SubDir   = &B010000
%Archive  = &B100000

' // For compatibility with the PB includes
TYPE DIOC_REGISTERS
   regEBX   AS DWORD
   regEDX   AS DWORD
   regECX   AS DWORD
   regEAX   AS DWORD
   regEDI   AS DWORD
   regESI   AS DWORD
   regFlags AS DWORD
END TYPE

' =============================================================================
' Windows code pages
' =============================================================================
%EncodingThai                   = 874    ' &H36A
%EncodingJapaneseShiftJIS       = 932    ' &H3A4
%EncodingSimplifiedChineseGBK   = 936    ' &H3A8
%EncodingKorean                 = 949    ' &H3B5
%EncodingTraditionalChineseBig5 = 950    ' &H3B6
%EncodingUnicodeLittleEndian    = 1200   ' &H4B0
%EncodingUnicodeBigEndian       = 1201   ' &H4B1
%EncodingCentralEuropean        = 1250   ' &H4E2
%EncodingCyrillic               = 1251   ' &H4E3
%EncodingWestern                = 1252   ' &H4E4
%EncodingGreek                  = 1253   ' &H4E5
%EncodingTurkish                = 1254   ' &H4E6
%EncodingHebrew                 = 1255   ' &H4E7
%EncodingArabic                 = 1256   ' &H4E8
%EncodingBaltic                 = 1257   ' &H4E9
%EncodingVietnamese             = 1258   ' &H4EA

' =============================================================================
' These structures are not defined in any standard header file. The structures
' definitions are provided here to explain the format of an extended template
' for a dialog box.
' =============================================================================

'TYPE DLGTEMPLATEEX
'   dlgVer      AS WORD
'   signature   AS WORD
'   helpID      AS DWORD
'   exStyle     AS DWORD
'   style       AS DWORD
'   cDlgItems   AS WORD
'   x           AS INTEGER
'   y           AS INTEGER
'   cx          AS INTEGER
'   cy          AS INTEGER
'   menu        AS WSTRINGZ   ' *** customize length for your dialog
'   windowClass AS WSTRINGZ   ' *** customize length for your dialog
'   title       AS WSTRINGZ   ' *** customize length for your dialog
'   pointsize   AS WORD       ' *** member only present if %DS_SETFONT or %DS_SHELLFONT
'   weight      AS WORD       ' *** member only present if %DS_SETFONT or %DS_SHELLFONT
'   italic      AS BYTE       ' *** member only present if %DS_SETFONT or %DS_SHELLFONT
'   charset     AS BYTE       ' *** member only present if %DS_SETFONT or %DS_SHELLFONT
'   typeface    AS WSTRINGZ   ' *** customize length for your dialog - member only present if %DS_SETFONT or %DS_SHELLFONT
'END TYPE

'TYPE DLGITEMTEMPLATEEX
'   helpID      AS DWORD
'   exStyle     AS DWORD
'   style       AS DWORD
'   x           AS INTEGER
'   y           AS INTEGER
'   cx          AS INTEGER
'   cy          AS INTEGER
'   id          AS WORD
'   windowClass AS WSTRINGZ   ' *** customize length for your dialog
'   title       AS WSTRINGZ   ' *** customize length for your dialog
'   extraCount  AS WORD
'END TYPE

' =============================================================================

' The ICO File
' Note: The MEMICONDIR, ICONDIR, MEMICONDIRENTRY and ICONENTRY structures aren't
' included in the SDK headers, but in the following article:
' http://msdn.microsoft.com/en-us/library/ms997538.aspx

'// These first two structs represent how the icon information is stored
'// when it is bound into a EXE or DLL file. Structure members are WORD
'// aligned and the last member of the structure is the ID instead of
'// the imageoffset.

' // Size = 14 bytes bytes
TYPE MEMICONDIRENTRY WORD FILL
   bWidth        AS BYTE    ' // Width, In Pixels, of the Image
   bHeight       AS BYTE    ' // Height, In Pixels, of the Image
   bColorCount   AS BYTE    ' // Number of colors In Image (0 If >=8bpp)
   bReserved     AS BYTE    ' // Reserved ( must be 0)
   wPlanes       AS WORD    ' // Color Planes
   wBitCount     AS WORD    ' // Bits per pixel
   dwBytesInRes  AS DWORD   ' // How many bytes In this resource?
   nID           AS WORD    ' // The ID
END TYPE

' // Size = 20 bytes
TYPE MEMICONDIR WORD FILL
   idReserved   AS WORD   ' // Reserved (must be 0)
   idType       AS WORD   ' // Resource Type (1 For icons)
   idCount      AS WORD   ' // How many images?
   idEntries(0) AS MEMICONDIRENTRY   ' // MEMICONDIRENTRY idEntries[1]; // An entry for each image (idCount of 'em)
END TYPE

' An Icon file, which usually has the ICO extension, contains one icon resource.
' Given that an icon resource can contain multiple images, it is no surprise that
' the file begins with an icon directory (see ICONDIR structure below)

' The idCount member indicates how many images are present in the icon resource.
' The size of the idEntries array is determined by idCount. There exists one ICONDIRENTRY
' for each icon image in the file, providing details about its location in the file,
' size and color depth. The ICONDIRENTRY structure is defined as:

' // Size = 16 bytes bytes
TYPE ICONDIRENTRY BYTE
   bWidth        AS BYTE    ' // Width, In Pixels, of the Image
   bHeight       AS BYTE    ' // Height, In Pixels, of the Image
   bColorCount   AS BYTE    ' // Number of colors In Image (0 If >=8bpp)
   bReserved     AS BYTE    ' // Reserved ( must be 0)
   wPlanes       AS WORD    ' // Color Planes
   wBitCount     AS WORD    ' // Bits per pixel
   dwBytesInRes  AS DWORD   ' // How many bytes In this resource?
   dwImageOffset AS DWORD   ' // Where In the file is this image?
END TYPE

' // Size = 22 bytes
TYPE ICONDIR BYTE
   idReserved   AS WORD   ' // Reserved (must be 0)
   idType       AS WORD   ' // Resource Type (1 For icons)
   idCount      AS WORD   ' // How many images?
   idEntries(0) AS ICONDIRENTRY   ' // ICONDIRENTRY idEntries[1]; // An entry for each image (idCount of 'em)
END TYPE

' ========================================================================================
' DebugView or other debugging utility that intercepts OutputDebuigString must be running.
' You can download the freeware SysInternal's DebugView application at:
' http://technet.microsoft.com/en-us/sysinternals/bb896647
' ========================================================================================
' Enable debugging
#IF NOT %DEF(%ENABLE_DEBUG)
    %ENABLE_DEBUG = 0                 ' 0 to disable debugging, 1 to enable
#ENDIF
MACRO DP_(st)
  #IF %ENABLE_DEBUG = 1
      OutputDebugString BYCOPY st
  #ENDIF
END MACRO
' ========================================================================================

' ========================================================================================
' This function allows to make an object variable from an interface pointer.
' An alternative is to use POKE or MoveMemory, e.g.
' POKE DWORD, VARPTR(pUnk), pObj
' IF ISOBJECT pUnk THEN pUnk.AddRef
' ========================================================================================
FUNCTION Ptr2Obj (BYVAL pObj AS DWORD) AS IUnknown
   LOCAL pUnk AS IUnknown
   LOCAL pv AS DWORD PTR
   IF pObj = %NULL THEN EXIT FUNCTION
   pv = VARPTR(pUnk)
   @pv = pObj
   IF ISOBJECT(pUnk) THEN
      pUnk.AddRef
      FUNCTION = pUnk
   END IF
END FUNCTION
' ========================================================================================

' ========================================================================================
' Compiler-independent helper function to display feedback and errors
' ========================================================================================
SUB AfxShowMsg (BYVAL bstrText AS WSTRING, OPTIONAL BYVAL NoWait AS LONG)
   #IF %DEF(%PB_CC32)
      STDOUT bstrText
      IF ISFALSE NoWait THEN
         PRINT "Press a key..."
         WAITKEY$
         LOCATE ,1
      END IF
   #ELSE
      MSGBOX bstrText, &H00001000& ' %MB_SYSTEMMODAL
   #ENDIF
END SUB
' ========================================================================================

' ========================================================================================
' Returns the Windows version
' Platform 1:
'   4.00 Windows 95
'   4.10 Windows 98
'   4.90 Windows ME
' Platform 2:
'   4.00 Windows NT
'   5.00 Windows 2000
'   5.01 Windows XP
'   5.02 Windows Server 2003
'   6.00 Windows Vista and Windows Server 2008
'   6.01 Windows 7
'   6.02 Windows 8
'   6.03 Windows 8.1
' Note: As Windows 95 and Windows NT return the same version number, we also need to call
' GetWindowsPlatform to differentiate them.
' ========================================================================================
FUNCTION AfxGetWindowsVersion () AS CURRENCY
   LOCAL dwVersion AS DWORD
   LOCAL nMajorVer, nMinorVer AS LONG
   dwVersion = GetVersion
   nMajorVer = LO(BYTE,LO(WORD,dwVersion))
   nMinorVer = HI(BYTE,LO(WORD,dwVersion))
   FUNCTION = nMajorVer + nMinorVer / 100
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the Windows platform
'   1 Windows 95/98/ME
'   2 Windows NT/2000/XP/Server/Vista/Windows 7
' ========================================================================================
FUNCTION AfxGetWindowsPlatform () AS LONG
   LOCAL dwVersion AS DWORD
   dwVersion = GetVersion
   FUNCTION = IIF&(dwVersion < &H80000000??, 2, 1)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the Windows build
' ========================================================================================
FUNCTION AfxGetWindowsBuild () AS LONG
   LOCAL dwVersion AS DWORD
   dwVersion = GetVersion
   IF dwVersion < &H80000000?? THEN FUNCTION = HI(WORD,dwVersion)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Retruns TRUE if the Windows Platform is NT; FALSE, otherwise.
' ========================================================================================
FUNCTION AfxIsPlatformNT () AS LONG
   LOCAL osvi AS OSVERSIONINFOW
   osvi.dwOSVersionInfoSize = SIZEOF(osvi)
   GetVersionExW(osvi)
   FUNCTION = (%VER_PLATFORM_WIN32_NT = osvi.dwPlatformId)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns the version of CommCtl32.dll
' ========================================================================================
FUNCTION AfxGetComCtlVersion () AS CURRENCY

   LOCAL pvsffi AS VS_FIXEDFILEINFO PTR
   LOCAL pVerInfo AS DWORD
   LOCAL dwHandle AS DWORD
   LOCAL dwVersion AS DWORD
   LOCAL cbLen AS DWORD
   LOCAL wMajor AS WORD
   LOCAL wMinor AS WORD
   cbLen = GetFileVersionInfoSize("COMCTL32.DLL", dwHandle)
   IF cbLen THEN
      pVerInfo = HeapAlloc(GetProcessHeap, %HEAP_ZERO_MEMORY, cbLen)
      IF pVerInfo THEN
         IF GetFileVersionInfo("COMCTL32.DLL", dwHandle, cbLen, BYVAL pVerInfo) THEN
            IF VerQueryValue(BYVAL pVerInfo, "\", BYVAL VARPTR(pvsffi), cbLen) THEN
               wMajor = HI(WORD, @pvsffi.dwFileVersionMS)
               wMinor = LO(WORD, @pvsffi.dwFileVersionMS)
            END IF
         END IF
         HeapFree GetProcessHeap, 0, pVerInfo
      END IF
   END IF
   FUNCTION = wMajor + wMinor / 100

END FUNCTION
' ========================================================================================

' ========================================================================================
' Retrieve the value of the UseDpiScaling setting (Vista/Windows 7).
' ========================================================================================
FUNCTION AfxGetUseDpiScaling () AS LONG

   LOCAL hr AS LONG
   LOCAL hKey AS DWORD
   LOCAL wszBuff AS WSTRINGZ * 256
   LOCAL dwType AS DWORD
   LOCAL cbData AS DWORD

   IF RegOpenKeyExW(%HKEY_CURRENT_USER, "Software\Microsoft\Windows\DWM", 0, %KEY_QUERY_VALUE, hKey) = %ERROR_SUCCESS THEN
      IF hKey THEN
         cbData = SIZEOF(wszBuff)
         hr = RegQueryValueExW(hKey, "UseDpiScaling", 0, dwType, wszBuff, cbData)
         RegCloseKey hKey
         IF hr = %ERROR_SUCCESS THEN
            wszBuff = EXTRACT$(wszBuff, CHR$(0))
            ' // Extracts DWORD from string
            FUNCTION = CVDWD(wszBuff)
         END IF
      END IF
   END IF

END FUNCTION
' ========================================================================================

' ========================================================================================
' Converts a numeric system error number into a string description.
' ========================================================================================
#IF %DEF(%UNICODE)
FUNCTION AfxWinErrMsg (BYVAL dwError AS DWORD) AS WSTRING
#ELSE
FUNCTION AfxWinErrMsg (BYVAL dwError AS DWORD) AS STRING
#ENDIF

   LOCAL hLib      AS DWORD
   LOCAL dwFlags   AS DWORD
   LOCAL os        AS OSVERSIONINFO
   LOCAL pBuffer   AS DWORD
   LOCAL cbBuffer  AS DWORD

   SELECT CASE AS LONG dwError
      ' Undocumented errors %NETWORK_ERROR_FIRST to %NETWORK_ERROR_LAST
      CASE 2100 TO 2999
         os.dwOSVersionInfoSize = SIZEOF(os)
         GetVersionEx os
         IF os.dwPlatformId = %VER_PLATFORM_WIN32_NT THEN
            hLib = LoadLibraryEx("NETMSG.DLL", BYVAL %NULL, %LOAD_LIBRARY_AS_DATAFILE)
         END IF
      ' Undocumented errors %INTERNET_ERROR_FIRST to %NTERNET_ERROR_LAST
      CASE 12000 TO 12171
         hLib = LoadLibraryEx("WININET.DLL", BYVAL %NULL, %LOAD_LIBRARY_AS_DATAFILE)
   END SELECT

   dwFlags = %FORMAT_MESSAGE_ALLOCATE_BUFFER OR %FORMAT_MESSAGE_FROM_SYSTEM OR _
             %FORMAT_MESSAGE_IGNORE_INSERTS OR %FORMAT_MESSAGE_MAX_WIDTH_MASK
   IF hLib THEN dwFlags = dwFlags OR %FORMAT_MESSAGE_FROM_HMODULE

   cbBuffer = FormatMessage(dwFlags, BYVAL hLib, dwError, MAKELANGID(%LANG_NEUTRAL, %SUBLANG_DEFAULT), _
                            BYVAL VARPTR(pBuffer), 0, BYVAL %NULL)
   IF cbBuffer THEN
#IF %DEF(%UNICODE)
      FUNCTION = PEEK$$(pBuffer, cbBuffer)
#ELSE
      FUNCTION = PEEK$(pBuffer, cbBuffer)
#ENDIF
      LocalFree pBuffer
   ELSE
      FUNCTION = "Error &H" + HEX$(dwError, 8)
   END IF
   IF hLib THEN FreeLibrary hLib

END FUNCTION
' ========================================================================================
