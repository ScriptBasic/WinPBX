' ########################################################################################
' Microsoft Windows
' File: WinDef.inc
' Contents: Basic Windows Type Definitions
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

' Note: windows.inc must be included before this file, but can't be done here.
' You must do it in your application.

#INCLUDE THIS ONCE
%WINDEF_INC = 1

'#ifndef NO_STRICT
'#ifndef STRICT
'#define STRICT 1
'#endif
'#endif /* NO_STRICT */

'// Win32 defines _WIN32 automatically,
'// but Macintosh doesn't, so if we are using
'// Win32 Functions, we must do it here

'#ifdef _MAC
'#ifndef _WIN32
'#define _WIN32
'#endif
'#endif //_MAC

'#ifndef WIN32
'#define WIN32
'#endif

'#ifndef WINVER
'#define WINVER 0x0500
'#endif /* WINVER */

'/*
' * BASETYPES is defined in ntdef.h if these types are already defined
' */

'#ifndef BASETYPES
'#define BASETYPES
'typedef unsigned long ULONG;
'typedef ULONG *PULONG;
'typedef unsigned short USHORT;
'typedef USHORT *PUSHORT;
'typedef unsigned char UCHAR;
'typedef UCHAR *PUCHAR;
'typedef char *PSZ;
'#endif  /* !BASETYPES */

'#define MAX_PATH          260
%MAX_PATH = 260

'#ifndef NULL
'#ifdef __cplusplus
'#define NULL    0
'#else
'#define NULL    ((void *)0)
'#endif
'#endif

%NULL = 0

'#ifndef FALSE
'#define FALSE               0
'#endif

%FALSE = 0

'#ifndef TRUE
'#define TRUE                1
'#endif

%TRUE = 1

'#ifndef IN
'#define IN
'#endif

'#ifndef OUT
'#define OUT
'#endif

'#ifndef OPTIONAL
'#define OPTIONAL
'#endif

'#undef far
'#undef near
'#undef pascal

'#define far
'#define near
'#if (!defined(_MAC)) && ((_MSC_VER >= 800) || defined(_STDCALL_SUPPORTED))
'#define pascal __stdcall
'#else
'#define pascal
'#endif

'#if defined(DOSWIN32) || defined(_MAC)
'#define cdecl _cdecl
'#ifndef CDECL
'#define CDECL _cdecl
'#endif
'#else
'#define cdecl
'#ifndef CDECL
'#define CDECL
'#endif
'#endif

'#ifdef _MAC
'#define CALLBACK    PASCAL
'#define WINAPI      CDECL
'#define WINAPIV     CDECL
'#define APIENTRY    WINAPI
'#define APIPRIVATE  CDECL
'#ifdef _68K_
'#define PASCAL      __pascal
'#else
'#define PASCAL
'#endif
'#elif (_MSC_VER >= 800) || defined(_STDCALL_SUPPORTED)
'#define CALLBACK    __stdcall
'#define WINAPI      __stdcall
'#define WINAPIV     __cdecl
'#define APIENTRY    WINAPI
'#define APIPRIVATE  __stdcall
'#define PASCAL      __stdcall
'#else
'#define CALLBACK
'#define WINAPI
'#define WINAPIV
'#define APIENTRY    WINAPI
'#define APIPRIVATE
'#define PASCAL      pascal
'#endif

'#ifdef _M_CEE_PURE
'#define WINAPI_INLINE  __clrcall
'#else
'#define WINAPI_INLINE  WINAPI
'#endif

'#undef FAR
'#undef  NEAR
'#define FAR                 far
'#define NEAR                near
'#ifndef CONST
'#define CONST               const
'#endif

'typedef unsigned long       DWORD;
'typedef int                 BOOL;
'typedef unsigned char       BYTE;
'typedef unsigned short      WORD;
'typedef float               FLOAT;
'typedef FLOAT               *PFLOAT;
'typedef BOOL near           *PBOOL;
'typedef BOOL far            *LPBOOL;
'typedef BYTE near           *PBYTE;
'typedef BYTE far            *LPBYTE;
'typedef int near            *PINT;
'typedef int far             *LPINT;
'typedef WORD near           *PWORD;
'typedef WORD far            *LPWORD;
'typedef long far            *LPLONG;
'typedef DWORD near          *PDWORD;
'typedef DWORD far           *LPDWORD;
'typedef void far            *LPVOID;
'typedef %void far           *LPCVOID;

'//
'//  File System time stamps are represented with the following structure:
'//

#IF NOT %DEF(%FILETIME_DEFINED)
%FILETIME_DEFINED = 1
' // Size = 8 bytes
TYPE FILETIME_STRUCT DWORD
   dwLowDateTime  AS DWORD   ' DWORD
   dwHighDateTime AS DWORD   ' DWORD
END TYPE

' // To allow to use both DWORD's and a QUAD
' // Size = 8 bytes
UNION FILETIME DWORD
   FILETIME_STRUCT
   qDateTime AS QUAD
END UNION
#ENDIF

'#ifndef NT_INCLUDED
'#include <winnt.h>
'#endif /* NT_INCLUDED */

#INCLUDE ONCE "WINNT.INC"

'#include <specstrings.h>

'/* Types use for passing & returning polymorphic values */
'typedef UINT_PTR            WPARAM;
'typedef LONG_PTR            LPARAM;
'typedef LONG_PTR            LRESULT;

'#ifndef NOMINMAX

'#ifndef max
'#define max(a,b)            (((a) > (b)) ? (a) : (b))
'#endif

'#ifndef min
'#define min(a,b)            (((a) < (b)) ? (a) : (b))
'#endif

'#endif  /* NOMINMAX */

'#define MAKEWORD(a, b)      ((WORD)(((BYTE)((DWORD_PTR)(a) & 0xff)) | ((WORD)((BYTE)((DWORD_PTR)(b) & 0xff))) << 8))
'#define MAKELONG(a, b)      ((LONG)(((WORD)((DWORD_PTR)(a) & 0xffff)) | ((DWORD)((WORD)((DWORD_PTR)(b) & 0xffff))) << 16))
'#define LOWORD(l)           ((WORD)((DWORD_PTR)(l) & 0xffff))
'#define HIWORD(l)           ((WORD)((DWORD_PTR)(l) >> 16))
'#define LOBYTE(w)           ((BYTE)((DWORD_PTR)(w) & 0xff))
'#define HIBYTE(w)           ((BYTE)((DWORD_PTR)(w) >> 8))

MACRO MAKEWORD(a, b) = MAK(WORD, a, b)
MACRO MAKELONG(a, b) = MAK(LONG, a, b)
MACRO LOWORD(l) = LO(WORD, l)
MACRO HIWORD(l) = HI(WORD, l)
MACRO LOBYTE(w) = LO(BYTE, w)
MACRO HIBYTE(w) = HI(BYTE, w)

'#ifndef WIN_INTERNAL
'DECLARE_HANDLE            (HWND);
'DECLARE_HANDLE            (HHOOK);
'#ifdef WINABLE
'DECLARE_HANDLE            (HEVENT);
'#endif
'#endif

'typedef WORD                ATOM;

'typedef HANDLE NEAR         *SPHANDLE;
'typedef HANDLE FAR          *LPHANDLE;
'typedef HANDLE              HGLOBAL;
'typedef HANDLE              HLOCAL;
'typedef HANDLE              GLOBALHANDLE;
'typedef HANDLE              LOCALHANDLE;

'#ifndef _MAC
'#ifdef _WIN64
'typedef INT_PTR (FAR WINAPI *FARPROC)();
'typedef INT_PTR (NEAR WINAPI *NEARPROC)();
'typedef INT_PTR (WINAPI *PROC)();
'#else
'typedef int (FAR WINAPI *FARPROC)();
'typedef int (NEAR WINAPI *NEARPROC)();
'typedef int (WINAPI *PROC)();
'#endif  // _WIN64
'#else
'typedef int (CALLBACK *FARPROC)();
'typedef int (CALLBACK *NEARPROC)();
'typedef int (CALLBACK *PROC)();
'#endif

'#if !defined(_MAC) || !defined(GDI_INTERNAL)
'#ifdef STRICT
'typedef void NEAR* HGDIOBJ;
'#else
'DECLARE_HANDLE(HGDIOBJ);
'#endif
'#endif

'DECLARE_HANDLE(HKEY);
'typedef HKEY *PHKEY;

'#if !defined(_MAC) || !defined(WIN_INTERNAL)
'DECLARE_HANDLE(HACCEL);
'#endif
'#if !defined(_MAC) || !defined(GDI_INTERNAL)
'DECLARE_HANDLE(HBITMAP);
'DECLARE_HANDLE(HBRUSH);
'#endif
'#if(WINVER >= 0x0400)
'DECLARE_HANDLE(HCOLORSPACE);
'#endif /* WINVER >= 0x0400 */
'#if !defined(_MAC) || !defined(GDI_INTERNAL)
'DECLARE_HANDLE(HDC);
'#endif
'DECLARE_HANDLE(HGLRC);          // OpenGL
'DECLARE_HANDLE(HDESK);
'DECLARE_HANDLE(HENHMETAFILE);
'#if !defined(_MAC) || !defined(GDI_INTERNAL)
'DECLARE_HANDLE(HFONT);
'#endif
'DECLARE_HANDLE(HICON);
'#if !defined(_MAC) || !defined(WIN_INTERNAL)
'DECLARE_HANDLE(HMENU);
'#endif
'DECLARE_HANDLE(HMETAFILE);
'DECLARE_HANDLE(HINSTANCE);
'typedef HINSTANCE HMODULE;      /* HMODULEs can be used in place of HINSTANCEs */
'#if !defined(_MAC) || !defined(GDI_INTERNAL)
'DECLARE_HANDLE(HPALETTE);
'DECLARE_HANDLE(HPEN);
'#endif
'DECLARE_HANDLE(HRGN);
'DECLARE_HANDLE(HRSRC);
'DECLARE_HANDLE(HSPRITE);
'DECLARE_HANDLE(HLSURF);
'DECLARE_HANDLE(HSTR);
'DECLARE_HANDLE(HTASK);
'DECLARE_HANDLE(HWINSTA);
'DECLARE_HANDLE(HKL);

'#if(WINVER >= 0x0500)
'#ifndef _MAC
'DECLARE_HANDLE(HMONITOR);
'DECLARE_HANDLE(HWINEVENTHOOK);
'#endif
'DECLARE_HANDLE(HUMPD);
'#endif /* WINVER >= 0x0500 */

'#ifndef _MAC
'typedef int HFILE;
'typedef HICON HCURSOR;      /* HICONs & HCURSORs are polymorphic */
'#else
'typedef short HFILE;
'DECLARE_HANDLE(HCURSOR);    /* HICONs & HCURSORs are not polymorphic */
'#endif

'typedef DWORD   COLORREF;
'typedef DWORD   *LPCOLORREF;

'#define HFILE_ERROR ((HFILE)-1)

%HFILE_ERROR = &HFFFFFFFF???

#IF NOT %DEF(%RECT_DEFINED)
%RECT_DEFINED = 1
' // Size = 16 bytes
TYPE OLD_RECT_STRUCT DWORD   ' Old PB definition
   nLeft   AS LONG   ' LONG left
   nTop    AS LONG   ' LONG top
   nRight  AS LONG   ' LONG right
   nBottom AS LONG   ' LONG bottom
END TYPE

' // Size = 16 bytes
TYPE tagRECT DWORD
   left   AS LONG   ' LONG left
   top    AS LONG   ' LONG top
   right  AS LONG   ' LONG right
   bottom AS LONG   ' LONG bottom
END TYPE

' // GDI+ uses x, y, Width and Height as members instead of Left, Right, Top and Bottom
TYPE GDIP_RECT_STRUCT DWORD
   x      AS LONG   ' LONG x
   y      AS LONG   ' LONG y
   Width  AS LONG   ' LONG Width
   Height AS LONG   ' LONG Height
END TYPE

' // To allow the use of both nLeft, etc, and Left, etc.
' // Size = 16 bytes
UNION RECT
   OLD_RECT_STRUCT
   tagRECT
   GDIP_RECT_STRUCT
END UNION
#ENDIF

#IF NOT %DEF(%RECTL_DEFINED)
%RECTL_DEFINED = 1
' // Size = 16 bytes
TYPE OLD_RECTL_STRUCT DWORD   ' Old definition
   nLeft   AS LONG   ' LONG left
   nTop    AS LONG   ' LONG top
   nRight  AS LONG   ' LONG right
   nBottom AS LONG   ' LONG bottom
END TYPE

' // Size = 16 bytes
TYPE tagRECTL DWORD
   Left   AS LONG   ' LONG left
   Top    AS LONG   ' LONG top
   Right  AS LONG   ' LONG right
   Bottom AS LONG   ' LONG bottom
END TYPE

' // To allow the use of both nLeft, etc., and Left, etc.
' // Size = 16 bytes
UNION RECTL
   OLD_RECTL_STRUCT
   tagRECTL
END UNION
#ENDIF

' // POINT and POINTAPI are pre-defined in the PB compilers
'#IF NOT %DEF(%POINT_DEFINED)
'%POINT_DEFINED = 1
'' // Size = 8 bytes
'TYPE POINTAPI ' DWORD
'   x AS LONG   ' LONG
'   y AS LONG   ' LONG
'END TYPE
'MACRO tagPOINT = POINTAPI
'#ENDIF

#IF NOT %DEF(%POINTL_DEFINED)
%POINTL_DEFINED = 1
' // Size = 8 bytes
TYPE POINTL DWORD
   x AS LONG   ' LONG
   y AS LONG   ' LONG
END TYPE
#ENDIF

#IF NOT %DEF(%SIZE_DEFINED)
%SIZE_DEFINED = 1
' // Size = 8 bytes
TYPE SIZE DWORD
   cx AS LONG   ' LONG cx
   cy AS LONG   ' LONG cy
END TYPE
' // Size = 8 bytes
TYPE APISIZE DWORD
   cx AS LONG   ' LONG cx
   cy AS LONG   ' LONG cy
END TYPE
MACRO tagSIZE = APISIZE
#ENDIF

#IF NOT %DEF(%SIZEL_DEFINED)
%SIZEL_DEFINED = 1
' // Size = 8 bytes
TYPE SIZEL DWORD
   cx AS LONG   ' LONG
   cy AS LONG   ' LONG
END TYPE
#ENDIF

'typedef SIZE               SIZEL;
'typedef SIZE               *PSIZEL, *LPSIZEL;

' // Size = 4 bytes
TYPE POINTS WORD
   x AS INTEGER   ' SHORT
   y AS INTEGER   ' SHORT
END TYPE

'/* mode selections for the device mode function */
%DM_UPDATE      = 1
%DM_COPY        = 2
%DM_PROMPT      = 4
%DM_MODIFY      = 8

%DM_IN_BUFFER   = %DM_MODIFY
%DM_IN_PROMPT   = %DM_PROMPT
%DM_OUT_BUFFER  = %DM_COPY
%DM_OUT_DEFAULT = %DM_UPDATE

'/* device capabilities indices */
%DC_FIELDS            = 1
%DC_PAPERS            = 2
%DC_PAPERSIZE         = 3
%DC_MINEXTENT         = 4
%DC_MAXEXTENT         = 5
%DC_BINS              = 6
%DC_DUPLEX            = 7
%DC_SIZE              = 8
%DC_EXTRA             = 9
%DC_VERSION           = 10
%DC_DRIVER            = 11
%DC_BINNAMES          = 12
%DC_ENUMRESOLUTIONS   = 13
%DC_FILEDEPENDENCIES  = 14
%DC_TRUETYPE          = 15
%DC_PAPERNAMES        = 16
%DC_ORIENTATION       = 17
%DC_COPIES            = 18
