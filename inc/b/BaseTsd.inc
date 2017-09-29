' ########################################################################################
' Microsoft Windows
' File: BaseTsd.inc
' Contents: Type definitions for the basic sized types.
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%BASETSD_INC = 1

'typedef signed char         INT8, *PINT8;
'typedef signed short        INT16, *PINT16;
'typedef signed int          INT32, *PINT32;
'typedef signed __int64      INT64, *PINT64;
'typedef unsigned char       UINT8, *PUINT8;
'typedef unsigned short      UINT16, *PUINT16;
'typedef unsigned int        UINT32, *PUINT32;
'typedef unsigned __int64    UINT64, *PUINT64;

'//
'// The following types are guaranteed to be signed and 32 bits wide.
'//

'typedef signed int LONG32, *PLONG32;

'//
'// The following types are guaranteed to be unsigned and 32 bits wide.
'//

'typedef unsigned int ULONG32, *PULONG32;
'typedef unsigned int DWORD32, *PDWORD32;

%ADDRESS_TAG_BIT = &H80000000???

'typedef unsigned short UHALF_PTR, *PUHALF_PTR;
'typedef short HALF_PTR, *PHALF_PTR;
'typedef _W64 long SHANDLE_PTR;
'typedef _W64 unsigned long HANDLE_PTR;

%MAXUINT_PTR     = &HFFFFFFFF???   ' (~((UINT_PTR)0))
%MAXINT_PTR      = 2147483647&     ' ((INT_PTR)(MAXUINT_PTR >> 1))
%MININT_PTR      = -2147483648&    ' (~MAXINT_PTR)

%MAXULONG_PTR    = &HFFFFFFFF???   ' (~((ULONG_PTR)0))
%MAXLONG_PTR     = 2147483647&     ' ((LONG_PTR)(MAXULONG_PTR >> 1))
%MINLONG_PTR     = -2147483648&    ' (~MAXLONG_PTR)

%MAXUHALF_PTR    = &HFFFF??        ' ((UHALF_PTR)~0)
%MAXHALF_PTR     = 32767%          ' ((HALF_PTR)(MAXUHALF_PTR >> 1))
%MINHALF_PTR     = -32768%         ' (~MAXHALF_PTR)

'//
'// SIZE_T used for counts or ranges which need to span the range of
'// of a pointer.  SSIZE_T is the signed variation.
'//

'typedef ULONG_PTR SIZE_T, *PSIZE_T;
'typedef LONG_PTR SSIZE_T, *PSSIZE_T;

'#if _WIN32_WINNT >= 0x0600 || (defined(__cplusplus) && defined(WINDOWS_ENABLE_CPLUSPLUS))

'#define MAXUINT8    ((UINT8)~((UINT8)0))
'#define MAXINT8     ((INT8)(MAXUINT8 >> 1))
'#define MININT8     ((INT8)~MAXINT8)

'#define MAXUINT16   ((UINT16)~((UINT16)0))
'#define MAXINT16    ((INT16)(MAXUINT16 >> 1))
'#define MININT16    ((INT16)~MAXINT16)

'#define MAXUINT32   ((UINT32)~((UINT32)0))
'#define MAXINT32    ((INT32)(MAXUINT32 >> 1))
'#define MININT32    ((INT32)~MAXINT32)

'#define MAXUINT64   ((UINT64)~((UINT64)0))
'#define MAXINT64    ((INT64)(MAXUINT64 >> 1))
'#define MININT64    ((INT64)~MAXINT64)

'#define MAXULONG32  ((ULONG32)~((ULONG32)0))
'#define MAXLONG32   ((LONG32)(MAXULONG32 >> 1))
'#define MINLONG32   ((LONG32)~MAXLONG32)

'#define MAXULONG64  ((ULONG64)~((ULONG64)0))
'#define MAXLONG64   ((LONG64)(MAXULONG64 >> 1))
'#define MINLONG64   ((LONG64)~MAXLONG64)

'#define MAXULONGLONG ((ULONGLONG)~((ULONGLONG)0))
'#define MINLONGLONG ((LONGLONG)~MAXLONGLONG)

'#define MAXSIZE_T   ((SIZE_T)~((SIZE_T)0))
'#define MAXSSIZE_T  ((SSIZE_T)(MAXSIZE_T >> 1))
'#define MINSSIZE_T  ((SSIZE_T)~MAXSSIZE_T)

'#define MAXUINT     ((UINT)~((UINT)0))
'#define MAXINT      ((INT)(MAXUINT >> 1))
'#define MININT      ((INT)~MAXINT)

'#define MAXDWORD32  ((DWORD32)~((DWORD32)0))
'#define MAXDWORD64  ((DWORD64)~((DWORD64)0))

'#endif // _WIN32_WINNT >= 0x0600

'//
'// Add Windows flavor DWORD_PTR types
'//

'typedef ULONG_PTR DWORD_PTR, *PDWORD_PTR;

'//
'// The following types are guaranteed to be signed and 64 bits wide.
'//

'typedef __int64 LONG64, *PLONG64;


'//
'// The following types are guaranteed to be unsigned and 64 bits wide.
'//

'typedef unsigned __int64 ULONG64, *PULONG64;
'typedef unsigned __int64 DWORD64, *PDWORD64;

'//
'// Legacy thread affinity.
'//

'typedef ULONG_PTR KAFFINITY;
'typedef KAFFINITY *PKAFFINITY;
