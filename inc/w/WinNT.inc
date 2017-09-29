' ########################################################################################
' Microsoft Windows
' File: WinNT.inc
' Contents: This module defines the 32-Bit Windows types and constants that are defined by
' NT, but exposed through the Win32 API.
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
%WINNT_INC = 1

'#INCLUDE ONCE "ctype.inc"

'#define ANYSIZE_ARRAY 1
%ANYSIZE_ARRAY = 1

'#include <specstrings.h>
'#include <kernelspecs.h>

'#if defined(_WIN64) || defined(_M_ALPHA)
'#define MAX_NATURAL_ALIGNMENT sizeof(ULONGLONG)
'#define MEMORY_ALLOCATION_ALIGNMENT 16
'#else
'#define MAX_NATURAL_ALIGNMENT sizeof(DWORD)
'#define MEMORY_ALLOCATION_ALIGNMENT 8
'#endif

%MAX_NATURAL_ALIGNMENT = 4   ' SIZEOF(DWORD)

#INCLUDE ONCE "basetsd.inc"

'//
'// Void
'//

'typedef void *PVOID;
'typedef void * POINTER_64 PVOID64;

'//
'// Basics
'//

'#ifndef VOID
'#define VOID void
'typedef char CHAR;
'typedef short SHORT;
'typedef long LONG;
'#endif

'//
'// UNICODE (Wide Character) types
'//

'#ifndef _MAC
'typedef wchar_t WCHAR;    // wc,   16-bit UNICODE character
'#else
'// some Macintosh compilers don't define wchar_t in a convenient location, or define it as a char
'typedef unsigned short WCHAR;    // wc,   16-bit UNICODE character
'#endif

'typedef WCHAR *PWCHAR, *LPWCH, *PWCH;
'typedef CONST WCHAR *LPCWCH, *PCWCH;

'typedef __nullterminated WCHAR *NWPSTR, *LPWSTR, *PWSTR;
'typedef __nullterminated PWSTR *PZPWSTR;
'typedef __nullterminated CONST PWSTR *PCZPWSTR;
'typedef __nullterminated WCHAR UNALIGNED *LPUWSTR, *PUWSTR;
'typedef __nullterminated CONST WCHAR *LPCWSTR, *PCWSTR;
'typedef __nullterminated PCWSTR *PZPCWSTR;
'typedef __nullterminated CONST WCHAR UNALIGNED *LPCUWSTR, *PCUWSTR;

'typedef __nullnullterminated WCHAR *PZZWSTR;
'typedef __nullnullterminated CONST WCHAR *PCZZWSTR;
'typedef __nullnullterminated WCHAR UNALIGNED *PUZZWSTR;
'typedef __nullnullterminated CONST WCHAR UNALIGNED *PCUZZWSTR;

'typedef __possibly_notnullterminated WCHAR *PNZWCH;
'typedef __possibly_notnullterminated CONST WCHAR *PCNZWCH;
'typedef __possibly_notnullterminated WCHAR UNALIGNED *PUNZWCH;
'typedef __possibly_notnullterminated CONST WCHAR UNALIGNED *PCUNZWCH;

'#if _WIN32_WINNT >= 0x0600 || (defined(__cplusplus) && defined(WINDOWS_ENABLE_CPLUSPLUS))

'typedef CONST WCHAR *LPCWCHAR, *PCWCHAR;
'typedef CONST WCHAR UNALIGNED *LPCUWCHAR, *PCUWCHAR;

'typedef CONST WCHAR *LPCWCHAR, *PCWCHAR;
'typedef CONST WCHAR UNALIGNED *LPCUWCHAR, *PCUWCHAR;

'//
'//  UCS (Universal Character Set) types
'//

'typedef unsigned long UCSCHAR;

'//
'//  Even pre-Unicode agreement, UCS values are always in the
'//  range U+00000000 to U+7FFFFFFF, so we'll pick an obvious
'//  value.

'#define UCSCHAR_INVALID_CHARACTER (0xffffffff)

'#define MIN_UCSCHAR (0)

'//
'//  We'll assume here that the ISO-10646 / Unicode agreement
'//  not to assign code points after U+0010FFFF holds so that
'//  we do not have to have separate "UCSCHAR" and "UNICODECHAR"
'//  types.
'//

'#define MAX_UCSCHAR (0x0010FFFF)

'typedef UCSCHAR *PUCSCHAR;
'typedef const UCSCHAR *PCUCSCHAR;

'typedef UCSCHAR *PUCSSTR;
'typedef UCSCHAR UNALIGNED *PUUCSSTR;

'typedef const UCSCHAR *PCUCSSTR;
'typedef const UCSCHAR UNALIGNED *PCUUCSSTR;

'typedef UCSCHAR UNALIGNED *PUUCSCHAR;
'typedef const UCSCHAR UNALIGNED *PCUUCSCHAR;

'#endif // _WIN32_WINNT >= 0x0600

'//
'// ANSI (Multi-byte Character) types
'//
'typedef CHAR *PCHAR, *LPCH, *PCH;
'typedef CONST CHAR *LPCCH, *PCCH;

'typedef __nullterminated CHAR *NPSTR, *LPSTR, *PSTR;
'typedef __nullterminated PSTR *PZPSTR;
'typedef __nullterminated CONST PSTR *PCZPSTR;
'typedef __nullterminated CONST CHAR *LPCSTR, *PCSTR;
'typedef __nullterminated PCSTR *PZPCSTR;

'typedef __nullnullterminated CHAR *PZZSTR;
'typedef __nullnullterminated CONST CHAR *PCZZSTR;

'typedef __possibly_notnullterminated CHAR *PNZCH;
'typedef __possibly_notnullterminated CONST CHAR *PCNZCH;

'//
'// Neutral ANSI/UNICODE types and macros
'//
'#ifdef  UNICODE                     // r_winnt

'#ifndef _TCHAR_DEFINED
'typedef WCHAR TCHAR, *PTCHAR;
'typedef WCHAR TBYTE , *PTBYTE ;
'#define _TCHAR_DEFINED
'#endif /* !_TCHAR_DEFINED */

'typedef LPWCH LPTCH, PTCH;
'typedef LPCWCH LPCTCH, PCTCH;
'typedef LPWSTR PTSTR, LPTSTR;
'typedef LPCWSTR PCTSTR, LPCTSTR;
'typedef LPUWSTR PUTSTR, LPUTSTR;
'typedef LPCUWSTR PCUTSTR, LPCUTSTR;
'typedef LPWSTR LP;
'typedef PZZWSTR PZZTSTR;
'typedef PCZZWSTR PCZZTSTR;
'typedef PUZZWSTR PUZZTSTR;
'typedef PCUZZWSTR PCUZZTSTR;
'typedef PNZWCH PNZTCH;
'typedef PCNZWCH PCNZTCH;
'typedef PUNZWCH PUNZTCH;
'typedef PCUNZWCH PCUNZTCH;
'#define __TEXT(quote) L##quote      // r_winnt

'#else   /* UNICODE */               // r_winnt

'#ifndef _TCHAR_DEFINED
'typedef char TCHAR, *PTCHAR;
'typedef unsigned char TBYTE , *PTBYTE ;
'#define _TCHAR_DEFINED
'#endif /* !_TCHAR_DEFINED */

'typedef LPCH LPTCH, PTCH;
'typedef LPCCH LPCTCH, PCTCH;
'typedef LPSTR PTSTR, LPTSTR, PUTSTR, LPUTSTR;
'typedef LPCSTR PCTSTR, LPCTSTR, PCUTSTR, LPCUTSTR;
'typedef PZZSTR PZZTSTR, PUZZTSTR;
'typedef PCZZSTR PCZZTSTR, PCUZZTSTR;
'typedef PNZCH PNZTCH, PUNZTCH;
'typedef PCNZCH PCNZTCH, PCUNZTCH;
'#define __TEXT(quote) quote         // r_winnt

'#endif /* UNICODE */                // r_winnt
'#define TEXT(quote) __TEXT(quote)   // r_winnt


'typedef SHORT *PSHORT;
'typedef LONG *PLONG;

%ALL_PROCESSOR_GROUPS        = &Hffff??

'//
'// Structure to represent a system wide processor number. It contains a
'// group number and relative processor number within the group.
'//

' // Size = 4 bytes
TYPE PROCESSOR_NUMBER BYTE
   Group    AS WORD   ' WORD
   Number   AS BYTE   ' BYTE
   Reserved AS BYTE   ' BYTE
END TYPE

'//
'// Structure to represent a group-specific affinity, such as that of a
'// thread.  Specifies the group number and the affinity within that group.
'//

' // Size = 12 bytes
TYPE GROUP_AFFINITY WORD
   Mask        AS DWORD   ' KAFFINITY [DWORD_PTR]
   Group       AS WORD    ' WORD
   Reserved(2) AS WORD    ' WORD
END TYPE

'//
'// Handle to an Object
'//

'#ifdef STRICT
'typedef void *HANDLE;
'#if 0 && (_MSC_VER > 1000)
'#define DECLARE_HANDLE(name) struct name##__; typedef struct name##__ *name
'#else
'#define DECLARE_HANDLE(name) struct name##__{int unused;}; typedef struct name##__ *name
'#endif
'#else
'typedef PVOID HANDLE;
'#define DECLARE_HANDLE(name) typedef HANDLE name
'#endif
'typedef HANDLE *PHANDLE;

'//
'// Flag (bit) fields
'//

'typedef BYTE   FCHAR;
'typedef WORD   FSHORT;
'typedef DWORD  FLONG;

'// Component Object Model defines, and macros

'#ifndef _HRESULT_DEFINED
'#define _HRESULT_DEFINED
'#ifdef __midl
'typedef LONG HRESULT;
'#else
'typedef __success(return >= 0) long HRESULT;
'#endif // __midl
'#endif // !_HRESULT_DEFINED

'#ifdef __cplusplus
'    #define EXTERN_C    extern "C"
'#else
'    #define EXTERN_C    extern
'#endif

'#if defined(_WIN32) || defined(_MPPC_)

'// Win32 doesn't support __export

'#ifdef _68K_
'#define STDMETHODCALLTYPE       __cdecl
'#else
'#define STDMETHODCALLTYPE       __stdcall
'#endif
'#define STDMETHODVCALLTYPE      __cdecl

'#define STDAPICALLTYPE          __stdcall
'#define STDAPIVCALLTYPE         __cdecl

'#else

'#define STDMETHODCALLTYPE       __export __stdcall
'#define STDMETHODVCALLTYPE      __export __cdecl

'#define STDAPICALLTYPE          __export __stdcall
'#define STDAPIVCALLTYPE         __export __cdecl

'#endif


'#define STDAPI                  EXTERN_C HRESULT STDAPICALLTYPE
'#define STDAPI_(type)           EXTERN_C type STDAPICALLTYPE

'#define STDMETHODIMP            HRESULT STDMETHODCALLTYPE
'#define STDMETHODIMP_(type)     type STDMETHODCALLTYPE

'#define STDOVERRIDEMETHODIMP        __override STDMETHODIMP
'#define STDOVERRIDEMETHODIMP_(type) __override STDMETHODIMP_(type)

'#define IFACEMETHODIMP          __override STDMETHODIMP
'#define IFACEMETHODIMP_(type)   __override STDMETHODIMP_(type)

'// The 'V' versions allow Variable Argument lists.

'#define STDAPIV                 EXTERN_C HRESULT STDAPIVCALLTYPE
'#define STDAPIV_(type)          EXTERN_C type STDAPIVCALLTYPE

'#define STDMETHODIMPV           HRESULT STDMETHODVCALLTYPE
'#define STDMETHODIMPV_(type)    type STDMETHODVCALLTYPE

'#define STDOVERRIDEMETHODIMPV        __override STDMETHODIMPV
'#define STDOVERRIDEMETHODIMPV_(type) __override STDMETHODIMPV_(type)

'#define IFACEMETHODIMPV          __override STDMETHODIMPV
'#define IFACEMETHODIMPV_(type)   __override STDMETHODIMPV_(type)

'typedef char CCHAR;
'typedef DWORD LCID;
'typedef PDWORD PLCID;
'typedef WORD   LANGID;

%APPLICATION_ERROR_MASK       = &H20000000???
%ERROR_SEVERITY_SUCCESS       = &H00000000???
%ERROR_SEVERITY_INFORMATIONAL = &H40000000???
%ERROR_SEVERITY_WARNING       = &H80000000???
%ERROR_SEVERITY_ERROR         = &HC0000000???

'//
'// _M_IX86 included so that EM CONTEXT structure compiles with
'// x86 programs. *** TBD should this be for all architectures?
'//

'//
'// 16 byte aligned type for 128 bit floats
'//

'//
'// For we define a 128 bit structure and use __declspec(align(16)) pragma to
'// align to 128 bits.
'//

'#if defined(_M_IA64) && !defined(MIDL_PASS)
'__declspec(align(16))
'#endif
'typedef struct _FLOAT128 {
'    __int64 LowPart;
'    __int64 HighPart;
'} FLOAT128;

'typedef FLOAT128 *PFLOAT128;

' // Size = 16 bytes
TYPE FLOAT128 QWORD
  LowPart  AS QUAD   ' __int64 LowPart
  HighPart AS QUAD   ' __int64 HighPart
END TYPE


'//
'// __int64 is only supported by 2.0 and later midl.
'// __midl is set by the 2.0 midl and not by 1.0 midl.
'//

%MAXLONGLONG                     = &H7fffffffffffffff&&

'typedef LONGLONG *PLONGLONG;
'typedef ULONGLONG *PULONGLONG;

'// Update Sequence Number

'typedef LONGLONG USN;

'#if defined(MIDL_PASS)
'typedef struct _LARGE_INTEGER {
'#else // MIDL_PASS
'typedef union _LARGE_INTEGER {
'    struct {
'        DWORD LowPart;
'        LONG HighPart;
'    };
'    struct {
'        DWORD LowPart;
'        LONG HighPart;
'    } u;
'#endif //MIDL_PASS
'    LONGLONG QuadPart;
'} LARGE_INTEGER;

'typedef LARGE_INTEGER *PLARGE_INTEGER;

'#if defined(MIDL_PASS)
'typedef struct _ULARGE_INTEGER {
'#else // MIDL_PASS
'typedef union _ULARGE_INTEGER {
'    struct {
'        DWORD LowPart;
'        DWORD HighPart;
'    } DUMMYSTRUCTNAME;
'    struct {
'        DWORD LowPart;
'        DWORD HighPart;
'    } u;
'#endif //MIDL_PASS
'    ULONGLONG QuadPart;
'} ULARGE_INTEGER;

'typedef ULARGE_INTEGER *PULARGE_INTEGER;

#IF NOT %DEF(%LARGE_INTEGER_DEFINED)
%LARGE_INTEGER_DEFINED = 1
' // Size = 8 bytes
TYPE LARGE_INTEGER_STRUCT DWORD
   LowPart  AS DWORD   ' DWORD
   HighPart AS LONG    ' LONG
END TYPE
UNION LARGE_INTEGER QWORD
   LARGE_INTEGER_STRUCT
   QuadPart AS QUAD
END UNION
#ENDIF

#IF NOT %DEF(%ULARGE_INTEGER_DEFINED)
%ULARGE_INTEGER_DEFINED = 1
' // Size = 8 bytes
TYPE ULARGE_INTEGER_STRUCT DWORD
   LowPart  AS DWORD   ' DWORD
   HighPart AS DWORD   ' DWORD
END TYPE
UNION ULARGE_INTEGER QWORD
   ULARGE_INTEGER_STRUCT
   QuadPart AS QUAD
END UNION
#ENDIF


'//
'// Locally Unique Identifier
'//

'typedef struct _LUID {
'    DWORD LowPart;
'    LONG HighPart;
'} LUID, *PLUID;

#IF NOT %DEF(%LUID_DEFINED)
%LUID_DEFINED = 1
' // Size = 8 bytes
TYPE LUID_STRUCT DWORD
  LowPart  AS DWORD
  HighPart AS LONG
END TYPE
UNION LUID
   LUID_STRUCT
   QuadPart AS QUAD
END UNION
#ENDIF

'#define Int32x32To64(a, b)  (((__int64)((long)(a))) * ((__int64)((long)(b))))
FUNCTION Int32x32To64 (BYVAL a AS LONG, BYVAL b AS LONG) AS QUAD
   FUNCTION = CQUD(a) * CQUD(b)
END FUNCTION

'#define UInt32x32To64(a, b) (((unsigned __int64)((unsigned int)(a))) * ((unsigned __int64)((unsigned int)(b))))
FUNCTION UInt32x32To64 (BYVAL a AS DWORD, BYVAL b AS DWORD) AS QUAD
   FUNCTION = CQUD(a) * CQUD(b)
END FUNCTION

'#define Int64ShllMod32(a, b) (((unsigned __int64)(a)) << (b))
FUNCTION Int64ShllMod32 (BYVAL Value AS QUAD, BYVAL ShiftCount AS DWORD) AS QUAD
   SHIFT LEFT Value, ShiftCount
   FUNCTION = value
END FUNCTION

'#define Int64ShraMod32(a, b) (((__int64)(a)) >> (b))
FUNCTION Int64ShraMod32 (BYVAL Value AS QUAD, BYVAL ShiftCount AS DWORD) AS QUAD
   SHIFT RIGHT Value, ShiftCount
   FUNCTION = value
END FUNCTION

'#define Int64ShrlMod32(a, b) (((unsigned __int64)(a)) >> (b))
' Note: Same as Int64ShraMod32 because PB doesn't support unsigned QUADs
FUNCTION Int64ShrlMod32 (BYVAL Value AS QUAD, BYVAL ShiftCount AS DWORD) AS QUAD
   SHIFT RIGHT Value, ShiftCount
   FUNCTION = value
END FUNCTION

'#define _DWORDLONG_
'typedef ULONGLONG  DWORDLONG;
'typedef DWORDLONG *PDWORDLONG;

'#define ANSI_NULL ((CHAR)0)
'#define UNICODE_NULL ((WCHAR)0)
'#define UNICODE_STRING_MAX_BYTES ((WORD  ) 65534)
'#define UNICODE_STRING_MAX_CHARS (32767)
'typedef BYTE  BOOLEAN;
'typedef BOOLEAN *PBOOLEAN;

$ANSI_NULL = $NUL
$$UNICODE_NULL = $$NUL
%UNICODE_STRING_MAX_BYTES = 65534??
%UNICODE_STRING_MAX_CHARS = 32767??

'//
'//  Doubly linked list structure.  Can be used as either a list head, or
'//  as link words.
'//

' // Size = 8 bytes
TYPE LIST_ENTRY DWORD
   Flink AS LIST_ENTRY PTR   ' struct _LIST_ENTRY *Flink
   Blink AS LIST_ENTRY PTR   ' struct _LIST_ENTRY *Blink
END TYPE

'//
'//  Singly linked list structure. Can be used as either a list head, or
'//  as link words.
'//

#IF %DEF(%USEPBDECL)
TYPE SINGLE_LIST_ENTRY DWORD
   sNext AS SINGLE_LIST_ENTRY PTR   ' struct _SINGLE_LIST_ENTRY *Next
END TYPE
#ELSE
' // Size = 4 bytes
TYPE SINGLE_LIST_ENTRY DWORD
   Next AS SINGLE_LIST_ENTRY PTR   ' struct _SINGLE_LIST_ENTRY *Next
END TYPE
#ENDIF

'//
'// These are needed for portable debugger support.
'//

'typedef struct LIST_ENTRY32 {
'    DWORD Flink;
'    DWORD Blink;
'} LIST_ENTRY32;
'typedef LIST_ENTRY32 *PLIST_ENTRY32;

'typedef struct LIST_ENTRY64 {
'    ULONGLONG Flink;
'    ULONGLONG Blink;
'} LIST_ENTRY64;
'typedef LIST_ENTRY64 *PLIST_ENTRY64;

#INCLUDE ONCE "guiddef.inc"

#IF NOT %DEF(%OBJECTID_DEFINED) '----------------------------------------------
' // Size = 20 bytes
TYPE OBJECTID DWORD
   Lineage    AS GUID
   Uniquifier AS DWORD
END TYPE
%OBJECTID_DEFINED = 1
#ENDIF ' #IF NOT %DEF(%OBJECTID_DEFINED) --------------------------------------

%MINCHAR  = &H80?
%MAXCHAR  = &H7F?
%MINSHORT = &H8000%
%MAXSHORT = &H7FFF%
%MINLONG  = &H80000000&
%MAXLONG  = &H7FFFFFFF&
%MAXBYTE  = &HFF?
%MAXWORD  = &HFFFF??
%MAXDWORD = &HFFFFFFFF???

%VER_SERVER_NT                      = &H80000000???
%VER_WORKSTATION_NT                 = &H40000000???
%VER_SUITE_SMALLBUSINESS            = &H00000001???
%VER_SUITE_ENTERPRISE               = &H00000002???
%VER_SUITE_BACKOFFICE               = &H00000004???
%VER_SUITE_COMMUNICATIONS           = &H00000008???
%VER_SUITE_TERMINAL                 = &H00000010???
%VER_SUITE_SMALLBUSINESS_RESTRICTED = &H00000020???
%VER_SUITE_EMBEDDEDNT               = &H00000040???
%VER_SUITE_DATACENTER               = &H00000080???
%VER_SUITE_SINGLEUSERTS             = &H00000100???
%VER_SUITE_PERSONAL                 = &H00000200???
%VER_SUITE_BLADE                    = &H00000400???
%VER_SUITE_EMBEDDED_RESTRICTED      = &H00000800???
%VER_SUITE_SECURITY_APPLIANCE       = &H00001000???
%VER_SUITE_STORAGE_SERVER           = &H00002000???
%VER_SUITE_COMPUTE_SERVER           = &H00004000???
%VER_SUITE_WH_SERVER                = &H00008000???

'//
'// Product types
'// This list grows with each OS release.
'//
'// There is no ordering of values to ensure callers
'// do an equality test i.e. greater-than and less-than
'// comparisons are not useful.
'//
'// NOTE: Values in this list should never be deleted.
'//       When a product-type 'X' gets dropped from a
'//       OS release onwards, the value of 'X' continues
'//       to be used in the mapping table of GetProductInfo.
'//

%PRODUCT_UNDEFINED                           = &H00000000???

%PRODUCT_ULTIMATE                            = &H00000001???
%PRODUCT_HOME_BASIC                          = &H00000002???
%PRODUCT_HOME_PREMIUM                        = &H00000003???
%PRODUCT_ENTERPRISE                          = &H00000004???
%PRODUCT_HOME_BASIC_N                        = &H00000005???
%PRODUCT_BUSINESS                            = &H00000006???
%PRODUCT_STANDARD_SERVER                     = &H00000007???
%PRODUCT_DATACENTER_SERVER                   = &H00000008???
%PRODUCT_SMALLBUSINESS_SERVER                = &H00000009???
%PRODUCT_ENTERPRISE_SERVER                   = &H0000000A???
%PRODUCT_STARTER                             = &H0000000B???
%PRODUCT_DATACENTER_SERVER_CORE              = &H0000000C???
%PRODUCT_STANDARD_SERVER_CORE                = &H0000000D???
%PRODUCT_ENTERPRISE_SERVER_CORE              = &H0000000E???
%PRODUCT_ENTERPRISE_SERVER_IA64              = &H0000000F???
%PRODUCT_BUSINESS_N                          = &H00000010???
%PRODUCT_WEB_SERVER                          = &H00000011???
%PRODUCT_CLUSTER_SERVER                      = &H00000012???
%PRODUCT_HOME_SERVER                         = &H00000013???
%PRODUCT_STORAGE_EXPRESS_SERVER              = &H00000014???
%PRODUCT_STORAGE_STANDARD_SERVER             = &H00000015???
%PRODUCT_STORAGE_WORKGROUP_SERVER            = &H00000016???
%PRODUCT_STORAGE_ENTERPRISE_SERVER           = &H00000017???
%PRODUCT_SERVER_FOR_SMALLBUSINESS            = &H00000018???
%PRODUCT_SMALLBUSINESS_SERVER_PREMIUM        = &H00000019???
%PRODUCT_HOME_PREMIUM_N                      = &H0000001A???
%PRODUCT_ENTERPRISE_N                        = &H0000001B???
%PRODUCT_ULTIMATE_N                          = &H0000001C???
%PRODUCT_WEB_SERVER_CORE                     = &H0000001D???
%PRODUCT_MEDIUMBUSINESS_SERVER_MANAGEMENT    = &H0000001E???
%PRODUCT_MEDIUMBUSINESS_SERVER_SECURITY      = &H0000001F???
%PRODUCT_MEDIUMBUSINESS_SERVER_MESSAGING     = &H00000020???
%PRODUCT_SERVER_FOUNDATION                   = &H00000021???
%PRODUCT_HOME_PREMIUM_SERVER                 = &H00000022???
%PRODUCT_SERVER_FOR_SMALLBUSINESS_V          = &H00000023???
%PRODUCT_STANDARD_SERVER_V                   = &H00000024???
%PRODUCT_DATACENTER_SERVER_V                 = &H00000025???
%PRODUCT_ENTERPRISE_SERVER_V                 = &H00000026???
%PRODUCT_DATACENTER_SERVER_CORE_V            = &H00000027???
%PRODUCT_STANDARD_SERVER_CORE_V              = &H00000028???
%PRODUCT_ENTERPRISE_SERVER_CORE_V            = &H00000029???
%PRODUCT_HYPERV                              = &H0000002A???
%PRODUCT_STORAGE_EXPRESS_SERVER_CORE         = &H0000002B???
%PRODUCT_STORAGE_STANDARD_SERVER_CORE        = &H0000002C???
%PRODUCT_STORAGE_WORKGROUP_SERVER_CORE       = &H0000002D???
%PRODUCT_STORAGE_ENTERPRISE_SERVER_CORE      = &H0000002E???
%PRODUCT_STARTER_N                           = &H0000002F???
%PRODUCT_PROFESSIONAL                        = &H00000030???
%PRODUCT_PROFESSIONAL_N                      = &H00000031???
%PRODUCT_SB_SOLUTION_SERVER                  = &H00000032???
%PRODUCT_SERVER_FOR_SB_SOLUTIONS             = &H00000033???
%PRODUCT_STANDARD_SERVER_SOLUTIONS           = &H00000034???
%PRODUCT_STANDARD_SERVER_SOLUTIONS_CORE      = &H00000035???
%PRODUCT_SB_SOLUTION_SERVER_EM               = &H00000036???
%PRODUCT_SERVER_FOR_SB_SOLUTIONS_EM          = &H00000037???
%PRODUCT_SOLUTION_EMBEDDEDSERVER             = &H00000038???
%PRODUCT_SOLUTION_EMBEDDEDSERVER_CORE        = &H00000039???
%PRODUCT_SMALLBUSINESS_SERVER_PREMIUM_CORE   = &H0000003F???
%PRODUCT_ESSENTIALBUSINESS_SERVER_MGMT       = &H0000003B???
%PRODUCT_ESSENTIALBUSINESS_SERVER_ADDL       = &H0000003C???
%PRODUCT_ESSENTIALBUSINESS_SERVER_MGMTSVC    = &H0000003D???
%PRODUCT_ESSENTIALBUSINESS_SERVER_ADDLSVC    = &H0000003E???
%PRODUCT_CLUSTER_SERVER_V                    = &H00000040???
%PRODUCT_EMBEDDED                            = &H00000041???
%PRODUCT_STARTER_E                           = &H00000042???
%PRODUCT_HOME_BASIC_E                        = &H00000043???
%PRODUCT_HOME_PREMIUM_E                      = &H00000044???
%PRODUCT_PROFESSIONAL_E                      = &H00000045???
%PRODUCT_ENTERPRISE_E                        = &H00000046???
%PRODUCT_ULTIMATE_E                          = &H00000047???

%PRODUCT_UNLICENSED                          = &HABCDABCD???

'#include <sdkddkver.h
#INCLUDE ONCE "sdkddkver.inc"

'//
'//  Language IDs.
'//
'//  Note that the named locale APIs (eg GetLocaleInfoEx) are preferred.
'//
'//  Not all locales have unique Language IDs
'//
'//  The following two combinations of primary language ID and
'//  sublanguage ID have special semantics:
'//
'//    Primary Language ID   Sublanguage ID      Result
'//    -------------------   ---------------     ------------------------
'//    LANG_NEUTRAL          SUBLANG_NEUTRAL     Language neutral
'//    LANG_NEUTRAL          SUBLANG_DEFAULT     User default language
'//    LANG_NEUTRAL          SUBLANG_SYS_DEFAULT System default language
'//    LANG_INVARIANT        SUBLANG_NEUTRAL     Invariant locale
'//
'//  It is recommended that applications test for locale names instead of
'//  Language IDs / LCIDs.

'//
'//  Primary language IDs.
'//
'//  WARNING: These aren't always unique.  Bosnian, Serbian & Croation for example.
'//
'//  It is recommended that applications test for locale names or actual LCIDs.
'//
'//  Note that the LANG, SUBLANG construction is not always consistent.
'//  The named locale APIs (eg GetLocaleInfoEx) are recommended.
'//

%LANG_NEUTRAL                     = &H00??
%LANG_INVARIANT                   = &H7f??

%LANG_AFRIKAANS                   = &H36??
%LANG_ALBANIAN                    = &H1c??
%LANG_ALSATIAN                    = &H84??
%LANG_AMHARIC                     = &H5e??
%LANG_ARABIC                      = &H01??
%LANG_ARMENIAN                    = &H2b??
%LANG_ASSAMESE                    = &H4d??
%LANG_AZERI                       = &H2c??
%LANG_BASHKIR                     = &H6d??
%LANG_BASQUE                      = &H2d??
%LANG_BELARUSIAN                  = &H23??
%LANG_BENGALI                     = &H45??
%LANG_BRETON                      = &H7e??
%LANG_BOSNIAN                     = &H1a??   ' // Use with SUBLANG_BOSNIAN_* Sublanguage IDs
%LANG_BOSNIAN_NEUTRAL             = &H781a?? '  // Use with the ConvertDefaultLocale function
%LANG_BULGARIAN                   = &H02??
%LANG_CATALAN                     = &H03??
%LANG_CHINESE                     = &H04??
%LANG_CHINESE_SIMPLIFIED          = &H04??   ' // Use with the ConvertDefaultLocale function
%LANG_CHINESE_TRADITIONAL         = &H7c04?? ' // Use with the ConvertDefaultLocale function
%LANG_CORSICAN                    = &H83??
%LANG_CROATIAN                    = &H1a??
%LANG_CZECH                       = &H05??
%LANG_DANISH                      = &H06??
%LANG_DARI                        = &H8c??
%LANG_DIVEHI                      = &H65??
%LANG_DUTCH                       = &H13??
%LANG_ENGLISH                     = &H09??
%LANG_ESTONIAN                    = &H25??
%LANG_FAEROESE                    = &H38??
%LANG_FARSI                       = &H29??   ' // Deprecated: use LANG_PERSIAN instead
%LANG_FILIPINO                    = &H64??
%LANG_FINNISH                     = &H0b??
%LANG_FRENCH                      = &H0c??
%LANG_FRISIAN                     = &H62??
%LANG_GALICIAN                    = &H56??
%LANG_GEORGIAN                    = &H37??
%LANG_GERMAN                      = &H07??
%LANG_GREEK                       = &H08??
%LANG_GREENLANDIC                 = &H6f??
%LANG_GUJARATI                    = &H47??
%LANG_HAUSA                       = &H68??
%LANG_HEBREW                      = &H0d??
%LANG_HINDI                       = &H39??
%LANG_HUNGARIAN                   = &H0e??
%LANG_ICELANDIC                   = &H0f??
%LANG_IGBO                        = &H70??
%LANG_INDONESIAN                  = &H21??
%LANG_INUKTITUT                   = &H5d??
%LANG_IRISH                       = &H3c??  ' // Use with the SUBLANG_IRISH_IRELAND Sublanguage ID
%LANG_ITALIAN                     = &H10??
%LANG_JAPANESE                    = &H11??
%LANG_KANNADA                     = &H4b??
%LANG_KASHMIRI                    = &H60??
%LANG_KAZAK                       = &H3f??
%LANG_KHMER                       = &H53??
%LANG_KICHE                       = &H86??
%LANG_KINYARWANDA                 = &H87??
%LANG_KONKANI                     = &H57??
%LANG_KOREAN                      = &H12??
%LANG_KYRGYZ                      = &H40??
%LANG_LAO                         = &H54??
%LANG_LATVIAN                     = &H26??
%LANG_LITHUANIAN                  = &H27??
%LANG_LOWER_SORBIAN               = &H2e??
%LANG_LUXEMBOURGISH               = &H6e??
%LANG_MACEDONIAN                  = &H2f??   ' the Former Yugoslav Republic of Macedonia
%LANG_MALAY                       = &H3e??
%LANG_MALAYALAM                   = &H4c??
%LANG_MANIPURI                    = &H58??
%LANG_MAORI                       = &H81??
%LANG_MAPUDUNGUN                  = &H7a??
%LANG_MARATHI                     = &H4e??
%LANG_MOHAWK                      = &H7c??
%LANG_MONGOLIAN                   = &H50??
%LANG_NEPALI                      = &H61??
%LANG_NORWEGIAN                   = &H14??
%LANG_OCCITAN                     = &H82??
%LANG_ORIYA                       = &H48??
%LANG_PASHTO                      = &H63??
%LANG_PERSIAN                     = &H29??
%LANG_POLISH                      = &H15??
%LANG_PORTUGUESE                  = &H16??
%LANG_PUNJABI                     = &H46??
%LANG_QUECHUA                     = &H6b??
%LANG_ROMANIAN                    = &H18??
%LANG_ROMANSH                     = &H17??
%LANG_RUSSIAN                     = &H19??
%LANG_SAMI                        = &H3b??
%LANG_SANSKRIT                    = &H4f??
%LANG_SCOTTISH_GAELIC             = &H91??
%LANG_SERBIAN                     = &H1a??
%LANG_SERBIAN_NEUTRAL             = &H7c1a??   ' // Use with the ConvertDefaultLocale function
%LANG_SINDHI                      = &H59??
%LANG_SINHALESE                   = &H5b??
%LANG_SLOVAK                      = &H1b??
%LANG_SLOVENIAN                   = &H24??
%LANG_SOTHO                       = &H6c??
%LANG_SPANISH                     = &H0a??
%LANG_SWAHILI                     = &H41??
%LANG_SWEDISH                     = &H1d??
%LANG_SYRIAC                      = &H5a??
%LANG_TAJIK                       = &H28??
%LANG_TAMAZIGHT                   = &H5f??
%LANG_TAMIL                       = &H49??
%LANG_TATAR                       = &H44??
%LANG_TELUGU                      = &H4a??
%LANG_THAI                        = &H1e??
%LANG_TIBETAN                     = &H51??
%LANG_TIGRIGNA                    = &H73??
%LANG_TSWANA                      = &H32??
%LANG_TURKISH                     = &H1f??
%LANG_TURKMEN                     = &H42??
%LANG_UIGHUR                      = &H80??
%LANG_UKRAINIAN                   = &H22??
%LANG_UPPER_SORBIAN               = &H2e??
%LANG_URDU                        = &H20??
%LANG_UZBEK                       = &H43??
%LANG_VIETNAMESE                  = &H2a??
%LANG_WELSH                       = &H52??
%LANG_WOLOF                       = &H88??
%LANG_XHOSA                       = &H34??
%LANG_YAKUT                       = &H85??
%LANG_YI                          = &H78??
%LANG_YORUBA                      = &H6a??
%LANG_ZULU                        = &H35??

'//
'//  Sublanguage IDs.
'//
'//  The name immediately following SUBLANG_ dictates which primary
'//  language ID that sublanguage ID can be combined with to form a
'//  valid language ID.
'//
'//  Note that the LANG, SUBLANG construction is not always consistent.
'//  The named locale APIs (eg GetLocaleInfoEx) are recommended.
'//

%SUBLANG_NEUTRAL                             = &H00??  ' // language neutral
%SUBLANG_DEFAULT                             = &H01??  ' // user default
%SUBLANG_SYS_DEFAULT                         = &H02??  ' // system default
%SUBLANG_CUSTOM_DEFAULT                      = &H03??  ' // default custom language/locale
%SUBLANG_CUSTOM_UNSPECIFIED                  = &H04??  ' // custom language/locale
%SUBLANG_UI_CUSTOM_DEFAULT                   = &H05??  ' // Default custom MUI language/locale

%SUBLANG_AFRIKAANS_SOUTH_AFRICA              = &H01??   ' // Afrikaans (South Africa) = &H0436 af-ZA
%SUBLANG_ALBANIAN_ALBANIA                    = &H01??   ' // Albanian (Albania) = &H041c sq-AL
%SUBLANG_ALSATIAN_FRANCE                     = &H01??   ' // Alsatian (France) = &H0484
%SUBLANG_AMHARIC_ETHIOPIA                    = &H01??   ' // Amharic (Ethiopia) = &H045e
%SUBLANG_ARABIC_SAUDI_ARABIA                 = &H01??   ' // Arabic (Saudi Arabia)
%SUBLANG_ARABIC_IRAQ                         = &H02??   ' // Arabic (Iraq)
%SUBLANG_ARABIC_EGYPT                        = &H03??   ' // Arabic (Egypt)
%SUBLANG_ARABIC_LIBYA                        = &H04??   ' // Arabic (Libya)
%SUBLANG_ARABIC_ALGERIA                      = &H05??   ' // Arabic (Algeria)
%SUBLANG_ARABIC_MOROCCO                      = &H06??   ' // Arabic (Morocco)
%SUBLANG_ARABIC_TUNISIA                      = &H07??   ' // Arabic (Tunisia)
%SUBLANG_ARABIC_OMAN                         = &H08??   ' // Arabic (Oman)
%SUBLANG_ARABIC_YEMEN                        = &H09??   ' // Arabic (Yemen)
%SUBLANG_ARABIC_SYRIA                        = &H0a??   ' // Arabic (Syria)
%SUBLANG_ARABIC_JORDAN                       = &H0b??   ' // Arabic (Jordan)
%SUBLANG_ARABIC_LEBANON                      = &H0c??   ' // Arabic (Lebanon)
%SUBLANG_ARABIC_KUWAIT                       = &H0d??   ' // Arabic (Kuwait)
%SUBLANG_ARABIC_UAE                          = &H0e??   ' // Arabic (U.A.E)
%SUBLANG_ARABIC_BAHRAIN                      = &H0f??   ' // Arabic (Bahrain)
%SUBLANG_ARABIC_QATAR                        = &H10??   ' // Arabic (Qatar)
%SUBLANG_ARMENIAN_ARMENIA                    = &H01??   ' // Armenian (Armenia) = &H042b hy-AM
%SUBLANG_ASSAMESE_INDIA                      = &H01??   ' // Assamese (India) = &H044d
%SUBLANG_AZERI_LATIN                         = &H01??   ' // Azeri (Latin)
%SUBLANG_AZERI_CYRILLIC                      = &H02??   ' // Azeri (Cyrillic)
%SUBLANG_BASHKIR_RUSSIA                      = &H01??   ' // Bashkir (Russia) = &H046d ba-RU
%SUBLANG_BASQUE_BASQUE                       = &H01??   ' // Basque (Basque) = &H042d eu-ES
%SUBLANG_BELARUSIAN_BELARUS                  = &H01??   ' // Belarusian (Belarus) = &H0423 be-BY
%SUBLANG_BENGALI_INDIA                       = &H01??   ' // Bengali (India)
%SUBLANG_BENGALI_BANGLADESH                  = &H02??   ' // Bengali (Bangladesh)
%SUBLANG_BOSNIAN_BOSNIA_HERZEGOVINA_LATIN    = &H05??   ' // Bosnian (Bosnia and Herzegovina - Latin) = &H141a bs-BA-Latn
%SUBLANG_BOSNIAN_BOSNIA_HERZEGOVINA_CYRILLIC = &H08??   ' // Bosnian (Bosnia and Herzegovina - Cyrillic) = &H201a bs-BA-Cyrl
%SUBLANG_BRETON_FRANCE                       = &H01??   ' // Breton (France) = &H047e
%SUBLANG_BULGARIAN_BULGARIA                  = &H01??   ' // Bulgarian (Bulgaria) = &H0402
%SUBLANG_CATALAN_CATALAN                     = &H01??   ' // Catalan (Catalan) = &H0403
%SUBLANG_CHINESE_TRADITIONAL                 = &H01??   ' // Chinese (Taiwan Region)
%SUBLANG_CHINESE_SIMPLIFIED                  = &H02??   ' // Chinese (PR China)
%SUBLANG_CHINESE_HONGKONG                    = &H03??   ' // Chinese (Hong Kong)
%SUBLANG_CHINESE_SINGAPORE                   = &H04??   ' // Chinese (Singapore)
%SUBLANG_CHINESE_MACAU                       = &H05??   ' // Chinese (Macau)
%SUBLANG_CORSICAN_FRANCE                     = &H01??   ' // Corsican (France) = &H0483
%SUBLANG_CZECH_CZECH_REPUBLIC                = &H01??   ' // Czech (Czech Republic) = &H0405
%SUBLANG_CROATIAN_CROATIA                    = &H01??   ' // Croatian (Croatia)
%SUBLANG_CROATIAN_BOSNIA_HERZEGOVINA_LATIN   = &H04??   ' // Croatian (Bosnia and Herzegovina - Latin) = &H101a hr-BA
%SUBLANG_DANISH_DENMARK                      = &H01??   ' // Danish (Denmark) = &H0406
%SUBLANG_DARI_AFGHANISTAN                    = &H01??   ' // Dari (Afghanistan)
%SUBLANG_DIVEHI_MALDIVES                     = &H01??   ' // Divehi (Maldives) = &H0465 div-MV
%SUBLANG_DUTCH                               = &H01??   ' // Dutch
%SUBLANG_DUTCH_BELGIAN                       = &H02??   ' // Dutch (Belgian)
%SUBLANG_ENGLISH_US                          = &H01??   ' // English (USA)
%SUBLANG_ENGLISH_UK                          = &H02??   ' // English (UK)
%SUBLANG_ENGLISH_AUS                         = &H03??   ' // English (Australian)
%SUBLANG_ENGLISH_CAN                         = &H04??   ' // English (Canadian)
%SUBLANG_ENGLISH_NZ                          = &H05??   ' // English (New Zealand)
%SUBLANG_ENGLISH_EIRE                        = &H06??   ' // English (Irish)
%SUBLANG_ENGLISH_SOUTH_AFRICA                = &H07??   ' // English (South Africa)
%SUBLANG_ENGLISH_JAMAICA                     = &H08??   ' // English (Jamaica)
%SUBLANG_ENGLISH_CARIBBEAN                   = &H09??   ' // English (Caribbean)
%SUBLANG_ENGLISH_BELIZE                      = &H0a??   ' // English (Belize)
%SUBLANG_ENGLISH_TRINIDAD                    = &H0b??   ' // English (Trinidad)
%SUBLANG_ENGLISH_ZIMBABWE                    = &H0c??   ' // English (Zimbabwe)
%SUBLANG_ENGLISH_PHILIPPINES                 = &H0d??   ' // English (Philippines)
%SUBLANG_ENGLISH_INDIA                       = &H10??   ' // English (India)
%SUBLANG_ENGLISH_MALAYSIA                    = &H11??   ' // English (Malaysia)
%SUBLANG_ENGLISH_SINGAPORE                   = &H12??   ' // English (Singapore)
%SUBLANG_ESTONIAN_ESTONIA                    = &H01??   ' // Estonian (Estonia) = &H0425 et-EE
%SUBLANG_FAEROESE_FAROE_ISLANDS              = &H01??   ' // Faroese (Faroe Islands) = &H0438 fo-FO
%SUBLANG_FILIPINO_PHILIPPINES                = &H01??   ' // Filipino (Philippines) = &H0464 fil-PH
%SUBLANG_FINNISH_FINLAND                     = &H01??   ' // Finnish (Finland) = &H040b
%SUBLANG_FRENCH                              = &H01??   ' // French
%SUBLANG_FRENCH_BELGIAN                      = &H02??   ' // French (Belgian)
%SUBLANG_FRENCH_CANADIAN                     = &H03??   ' // French (Canadian)
%SUBLANG_FRENCH_SWISS                        = &H04??   ' // French (Swiss)
%SUBLANG_FRENCH_LUXEMBOURG                   = &H05??   ' // French (Luxembourg)
%SUBLANG_FRENCH_MONACO                       = &H06??   ' // French (Monaco)
%SUBLANG_FRISIAN_NETHERLANDS                 = &H01??   ' // Frisian (Netherlands) = &H0462 fy-NL
%SUBLANG_GALICIAN_GALICIAN                   = &H01??   ' // Galician (Galician) = &H0456 gl-ES
%SUBLANG_GEORGIAN_GEORGIA                    = &H01??   ' // Georgian (Georgia) = &H0437 ka-GE
%SUBLANG_GERMAN                              = &H01??   ' // German
%SUBLANG_GERMAN_SWISS                        = &H02??   ' // German (Swiss)
%SUBLANG_GERMAN_AUSTRIAN                     = &H03??   ' // German (Austrian)
%SUBLANG_GERMAN_LUXEMBOURG                   = &H04??   ' // German (Luxembourg)
%SUBLANG_GERMAN_LIECHTENSTEIN                = &H05??   ' // German (Liechtenstein)
%SUBLANG_GREEK_GREECE                        = &H01??   ' // Greek (Greece)
%SUBLANG_GREENLANDIC_GREENLAND               = &H01??   ' // Greenlandic (Greenland) = &H046f kl-GL
%SUBLANG_GUJARATI_INDIA                      = &H01??   ' // Gujarati (India (Gujarati Script)) = &H0447 gu-IN
%SUBLANG_HAUSA_NIGERIA_LATIN                 = &H01??   ' // Hausa (Latin, Nigeria) = &H0468 ha-NG-Latn
%SUBLANG_HEBREW_ISRAEL                       = &H01??   ' // Hebrew (Israel) = &H040d
%SUBLANG_HINDI_INDIA                         = &H01??   ' // Hindi (India) = &H0439 hi-IN
%SUBLANG_HUNGARIAN_HUNGARY                   = &H01??   ' // Hungarian (Hungary) = &H040e
%SUBLANG_ICELANDIC_ICELAND                   = &H01??   ' // Icelandic (Iceland) = &H040f
%SUBLANG_IGBO_NIGERIA                        = &H01??   ' // Igbo (Nigeria) = &H0470 ig-NG
%SUBLANG_INDONESIAN_INDONESIA                = &H01??   ' // Indonesian (Indonesia) = &H0421 id-ID
%SUBLANG_INUKTITUT_CANADA                    = &H01??   ' // Inuktitut (Syllabics) (Canada) = &H045d iu-CA-Cans
%SUBLANG_INUKTITUT_CANADA_LATIN              = &H02??   ' // Inuktitut (Canada - Latin)
%SUBLANG_IRISH_IRELAND                       = &H02??   ' // Irish (Ireland)
%SUBLANG_ITALIAN                             = &H01??   ' // Italian
%SUBLANG_ITALIAN_SWISS                       = &H02??   ' // Italian (Swiss)
%SUBLANG_JAPANESE_JAPAN                      = &H01??   ' // Japanese (Japan) = &H0411
%SUBLANG_KANNADA_INDIA                       = &H01??   ' // Kannada (India (Kannada Script)) = &H044b kn-IN
%SUBLANG_KASHMIRI_SASIA                      = &H02??   ' // Kashmiri (South Asia)
%SUBLANG_KASHMIRI_INDIA                      = &H02??   ' // Kashmiri (India)
%SUBLANG_KASHMIRI_SASIA                      = &H02??   ' // Kashmiri (South Asia)
%SUBLANG_KASHMIRI_INDIA                      = &H02??   ' // For app compatibility only
%SUBLANG_KAZAK_KAZAKHSTAN                    = &H01??   ' // Kazakh (Kazakhstan) = &H043f kk-KZ
%SUBLANG_KHMER_CAMBODIA                      = &H01??   ' // Khmer (Cambodia) = &H0453 kh-KH
%SUBLANG_KICHE_GUATEMALA                     = &H01??   ' // K' //iche (Guatemala)
%SUBLANG_KINYARWANDA_RWANDA                  = &H01??   ' // Kinyarwanda (Rwanda) = &H0487 rw-RW
%SUBLANG_KONKANI_INDIA                       = &H01??   ' // Konkani (India) = &H0457 kok-IN
%SUBLANG_KOREAN                              = &H01??   ' // Korean (Extended Wansung)
%SUBLANG_KYRGYZ_KYRGYZSTAN                   = &H01??   ' // Kyrgyz (Kyrgyzstan) = &H0440 ky-KG
%SUBLANG_LAO_LAO                             = &H01??   ' // Lao (Lao PDR) = &H0454 lo-LA
%SUBLANG_LATVIAN_LATVIA                      = &H01??   ' // Latvian (Latvia) = &H0426 lv-LV
%SUBLANG_LITHUANIAN                          = &H01??   ' // Lithuanian
' //%SUBLANG_LITHUANIAN_CLASSIC       = &H02??  ' // Lithuanian (Classic)  Not in Windows 7 SDK
%SUBLANG_LOWER_SORBIAN_GERMANY               = &H02??   ' // Lower Sorbian (Germany) = &H082e wee-DE
%SUBLANG_LUXEMBOURGISH_LUXEMBOURG            = &H01??   ' // Luxembourgish (Luxembourg) = &H046e lb-LU
%SUBLANG_MACEDONIAN_MACEDONIA                = &H01??   ' // Macedonian (Macedonia (FYROM)) = &H042f mk-MK
%SUBLANG_MALAY_MALAYSIA                      = &H01??   ' // Malay (Malaysia)
%SUBLANG_MALAY_BRUNEI_DARUSSALAM             = &H02??   ' // Malay (Brunei Darussalam)
%SUBLANG_MALAYALAM_INDIA                     = &H01??   ' // Malayalam (India (Malayalam Script) ) = &H044c ml-IN
%SUBLANG_MALTESE_MALTA                       = &H01??   ' // Maltese (Malta) = &H043a mt-MT
%SUBLANG_MAORI_NEW_ZEALAND                   = &H01??   ' // Maori (New Zealand) = &H0481 mi-NZ
%SUBLANG_MAPUDUNGUN_CHILE                    = &H01??   ' // Mapudungun (Chile) = &H047a arn-CL
%SUBLANG_MARATHI_INDIA                       = &H01??   ' // Marathi (India) = &H044e mr-IN
%SUBLANG_MOHAWK_MOHAWK                       = &H01??   ' // Mohawk (Mohawk) = &H047c moh-CA
%SUBLANG_MONGOLIAN_CYRILLIC_MONGOLIA         = &H01??   ' // Mongolian (Cyrillic, Mongolia)
%SUBLANG_MONGOLIAN_PRC                       = &H02??   ' // Mongolian (PRC)
%SUBLANG_NEPALI_INDIA                        = &H02??   ' // Nepali (India)
%SUBLANG_NEPALI_NEPAL                        = &H01??   ' // Nepali (Nepal) = &H0461 ne-NP
%SUBLANG_NORWEGIAN_BOKMAL                    = &H01??   ' // Norwegian (Bokmal)
%SUBLANG_NORWEGIAN_NYNORSK                   = &H02??   ' // Norwegian (Nynorsk)
%SUBLANG_OCCITAN_FRANCE                      = &H01??   ' // Occitan (France) = &H0482 oc-FR
%SUBLANG_ORIYA_INDIA                         = &H01??   ' // Oriya (India (Oriya Script)) = &H0448 or-IN
%SUBLANG_PASHTO_AFGHANISTAN                  = &H01??   ' // Pashto (Afghanistan)
%SUBLANG_PERSIAN_IRAN                        = &H01??   ' // Persian (Iran) = &H0429 fa-IR
%SUBLANG_POLISH_POLAND                       = &H01??   ' // Polish (Poland) = &H0415
%SUBLANG_PORTUGUESE                          = &H02??   ' // Portuguese
%SUBLANG_PORTUGUESE_BRAZILIAN                = &H01??   ' // Portuguese (Brazilian)
%SUBLANG_PUNJABI_INDIA                       = &H01??   ' // Punjabi (India (Gurmukhi Script)) = &H0446 pa-IN
%SUBLANG_QUECHUA_BOLIVIA                     = &H01??   ' // Quechua (Bolivia)
%SUBLANG_QUECHUA_ECUADOR                     = &H02??   ' // Quechua (Ecuador)
%SUBLANG_QUECHUA_PERU                        = &H03??   ' // Quechua (Peru)
%SUBLANG_ROMANIAN_ROMANIA                    = &H01??   ' // Romanian (Romania) = &H0418
%SUBLANG_ROMANSH_SWITZERLAND                 = &H01??   ' // Romansh (Switzerland) = &H0417 rm-CH
%SUBLANG_RUSSIAN_RUSSIA                      = &H01??   ' // Russian (Russia) = &H0419
%SUBLANG_SAMI_NORTHERN_NORWAY                = &H01??   ' // Northern Sami (Norway)
%SUBLANG_SAMI_NORTHERN_SWEDEN                = &H02??   ' // Northern Sami (Sweden)
%SUBLANG_SAMI_NORTHERN_FINLAND               = &H03??   ' // Northern Sami (Finland)
%SUBLANG_SAMI_LULE_NORWAY                    = &H04??   ' // Lule Sami (Norway)
%SUBLANG_SAMI_LULE_SWEDEN                    = &H05??   ' // Lule Sami (Sweden)
%SUBLANG_SAMI_SOUTHERN_NORWAY                = &H06??   ' // Southern Sami (Norway)
%SUBLANG_SAMI_SOUTHERN_SWEDEN                = &H07??   ' // Southern Sami (Sweden)
%SUBLANG_SAMI_SKOLT_FINLAND                  = &H08??   ' // Skolt Sami (Finland)
%SUBLANG_SAMI_INARI_FINLAND                  = &H09??   ' // Inari Sami (Finland)
%SUBLANG_SANSKRIT_INDIA                      = &H01??   ' // Sanskrit (India) = &H044f sa-IN
%SUBLANG_SCOTTISH_GAELIC                     = &H01??   ' // Scottish Gaelic (United Kingdom) 0x0491 gd-GB
%SUBLANG_SERBIAN_BOSNIA_HERZEGOVINA_LATIN    = &H06??   ' // Serbian (Bosnia and Herzegovina - Latin)
%SUBLANG_SERBIAN_BOSNIA_HERZEGOVINA_CYRILLIC = &H07??   ' // Serbian (Bosnia and Herzegovina - Cyrillic)
%SUBLANG_SERBIAN_MONTENEGRO_LATIN            = &H0b??   ' // Serbian (Montenegro - Latn)
%SUBLANG_SERBIAN_MONTENEGRO_CYRILLIC         = &H0c??   ' // Serbian (Montenegro - Cyrillic)
%SUBLANG_SERBIAN_SERBIA_LATIN                = &H09??   ' // Serbian (Serbia - Latin)
%SUBLANG_SERBIAN_SERBIA_CYRILLIC             = &H0a??   ' // Serbian (Serbia - Cyrillic)
%SUBLANG_SERBIAN_CROATIA                     = &H01??   ' // Croatian (Croatia) = &H041a hr-HR
%SUBLANG_SERBIAN_LATIN                       = &H02??   ' // Serbian (Latin)
%SUBLANG_SERBIAN_CYRILLIC                    = &H03??   ' // Serbian (Cyrillic)
%SUBLANG_SINDHI_INDIA                        = &H01??   ' // Sindhi (India) reserved = &H0459
%SUBLANG_SINDHI_PAKISTAN                     = &H02??   ' // Sindhi (Pakistan) reserved = &H0859
%SUBLANG_SINDHI_AFGHANISTAN                  = &H02??   ' // For app compatibility only
%SUBLANG_SINHALESE_SRI_LANKA                 = &H01??   ' // Sinhalese (Sri Lanka)
%SUBLANG_SOTHO_NORTHERN_SOUTH_AFRICA         = &H01??   ' // Northern Sotho (South Africa)
%SUBLANG_SLOVAK_SLOVAKIA                     = &H01??   ' // Slovak (Slovakia) = &H041b sk-SK
%SUBLANG_SLOVENIAN_SLOVENIA                  = &H01??   ' // Slovenian (Slovenia) = &H0424 sl-SI
%SUBLANG_SPANISH                             = &H01??   ' // Spanish (Castilian)
%SUBLANG_SPANISH_MEXICAN                     = &H02??   ' // Spanish (Mexican)
%SUBLANG_SPANISH_MODERN                      = &H03??   ' // Spanish (Modern)
%SUBLANG_SPANISH_GUATEMALA                   = &H04??   ' // Spanish (Guatemala)
%SUBLANG_SPANISH_COSTA_RICA                  = &H05??   ' // Spanish (Costa Rica)
%SUBLANG_SPANISH_PANAMA                      = &H06??   ' // Spanish (Panama)
%SUBLANG_SPANISH_DOMINICAN_REPUBLIC          = &H07??   ' // Spanish (Dominican Republic)
%SUBLANG_SPANISH_VENEZUELA                   = &H08??   ' // Spanish (Venezuela)
%SUBLANG_SPANISH_COLOMBIA                    = &H09??   ' // Spanish (Colombia)
%SUBLANG_SPANISH_PERU                        = &H0a??   ' // Spanish (Peru)
%SUBLANG_SPANISH_ARGENTINA                   = &H0b??   ' // Spanish (Argentina)
%SUBLANG_SPANISH_ECUADOR                     = &H0c??   ' // Spanish (Ecuador)
%SUBLANG_SPANISH_CHILE                       = &H0d??   ' // Spanish (Chile)
%SUBLANG_SPANISH_URUGUAY                     = &H0e??   ' // Spanish (Uruguay)
%SUBLANG_SPANISH_PARAGUAY                    = &H0f??   ' // Spanish (Paraguay)
%SUBLANG_SPANISH_BOLIVIA                     = &H10??   ' // Spanish (Bolivia)
%SUBLANG_SPANISH_EL_SALVADOR                 = &H11??   ' // Spanish (El Salvador)
%SUBLANG_SPANISH_HONDURAS                    = &H12??   ' // Spanish (Honduras)
%SUBLANG_SPANISH_NICARAGUA                   = &H13??   ' // Spanish (Nicaragua)
%SUBLANG_SPANISH_PUERTO_RICO                 = &H14??   ' // Spanish (Puerto Rico)
%SUBLANG_SPANISH_US                          = &H15??   ' // Spanish (United States)
%SUBLANG_SWAHILI_KENYA                       = &H01??   ' // Swahili (Kenya) = &H0441 sw-KE
%SUBLANG_SWEDISH                             = &H01??   ' // Swedish
%SUBLANG_SWEDISH_FINLAND                     = &H02??   ' // Swedish (Finland)
%SUBLANG_SYRIAC_SYRIA                        = &H01??   ' // Syriac (Syria) = &H045a syr-SY
%SUBLANG_TAJIK_TAJIKISTAN                    = &H01??   ' // Tajik (Tajikistan) = &H0428 tg-TJ-Cyrl
%SUBLANG_TAMAZIGHT_ALGERIA_LATIN             = &H02??   ' // Tamazight (Latin, Algeria) = &H085f tmz-DZ-Latn
%SUBLANG_TAMIL_INDIA                         = &H01??   ' // Tamil (India)
%SUBLANG_TATAR_RUSSIA                        = &H01??   ' // Tatar (Russia) = &H0444 tt-RU
%SUBLANG_TELUGU_INDIA                        = &H01??   ' // Telugu (India (Telugu Script)) = &H044a te-IN
%SUBLANG_THAI_THAILAND                       = &H01??   ' // Thai (Thailand) = &H041e th-TH
%SUBLANG_TIBETAN_PRC                         = &H01??   ' // Tibetan (PRC)
%SUBLANG_TIGRIGNA_ERITREA                    = &H02??   ' // Tigrigna (Eritrea)
%SUBLANG_TSWANA_SOUTH_AFRICA                 = &H01??   ' // Setswana / Tswana (South Africa) = &H0432 tn-ZA
%SUBLANG_TURKISH_TURKEY                      = &H01??   ' // Turkish (Turkey) = &H041f tr-TR
%SUBLANG_TURKMEN_TURKMENISTAN                = &H01??   ' // Turkmen (Turkmenistan) = &H0442 tk-TM
%SUBLANG_UIGHUR_PRC                          = &H01??   ' // Uighur (PRC) = &H0480 ug-CN
%SUBLANG_UKRAINIAN_UKRAINE                   = &H01??   ' // Ukrainian (Ukraine) = &H0422 uk-UA
%SUBLANG_UPPER_SORBIAN_GERMANY               = &H01??   ' // Upper Sorbian (Germany) = &H042e wen-DE
%SUBLANG_URDU_PAKISTAN                       = &H01??   ' // Urdu (Pakistan)
%SUBLANG_URDU_INDIA                          = &H02??   ' // Urdu (India)
%SUBLANG_UZBEK_LATIN                         = &H01??   ' // Uzbek (Latin)
%SUBLANG_UZBEK_CYRILLIC                      = &H02??   ' // Uzbek (Cyrillic)
%SUBLANG_VIETNAMESE_VIETNAM                  = &H01??   ' // Vietnamese (Vietnam) = &H042a vi-VN
%SUBLANG_WELSH_UNITED_KINGDOM                = &H01??   ' // Welsh (United Kingdom) = &H0452 cy-GB
%SUBLANG_WOLOF_SENEGAL                       = &H01??   ' // Wolof (Senegal)
%SUBLANG_XHOSA_SOUTH_AFRICA                  = &H01??   ' // isiXhosa / Xhosa (South Africa) = &H0434 xh-ZA
%SUBLANG_YAKUT_RUSSIA                        = &H01??   ' // Yakut (Russia) = &H0485 sah-RU
%SUBLANG_YI_PRC                              = &H01??   ' // Yi (PRC)) = &H0478
%SUBLANG_YORUBA_NIGERIA                      = &H01??   ' // Yoruba (Nigeria) 046a yo-NG
%SUBLANG_ZULU_SOUTH_AFRICA                   = &H01??   ' // isiZulu / Zulu (South Africa) = &H0435 zu-ZA

'//
'//  Sorting IDs.
'//
'//  Note that the named locale APIs (eg CompareStringExEx) are recommended.
'//

%SORT_DEFAULT                     = &H0??     ' // sorting default

%SORT_INVARIANT_MATH              = &H1??     ' // Invariant (Mathematical Symbols)

%SORT_JAPANESE_XJIS               = &H0??     ' // Japanese XJIS order
%SORT_JAPANESE_UNICODE            = &H1??     ' // Japanese Unicode order
%SORT_JAPANESE_RADICALSTROKE      = &H4??     ' // Japanese radical/stroke order

%SORT_CHINESE_BIG5                = &H0??     ' // Chinese BIG5 order
%SORT_CHINESE_PRCP                = &H0??     ' // PRC Chinese Phonetic order
%SORT_CHINESE_UNICODE             = &H1??     ' // Chinese Unicode order
%SORT_CHINESE_PRC                 = &H2??     ' // PRC Chinese Stroke Count order
%SORT_CHINESE_BOPOMOFO            = &H3??     ' // Traditional Chinese Bopomofo order
%SORT_CHINESE_RADICALSTROKE       = &H4??     ' // Traditional Chinese radical/stroke order.

%SORT_KOREAN_KSC                  = &H0??     ' // Korean KSC order
%SORT_KOREAN_UNICODE              = &H1??     ' // Korean Unicode order

%SORT_GERMAN_PHONE_BOOK           = &H1??     ' // German Phone Book order

%SORT_HUNGARIAN_DEFAULT           = &H0??     ' // Hungarian Default order
%SORT_HUNGARIAN_TECHNICAL         = &H1??     ' // Hungarian Technical order

%SORT_GEORGIAN_TRADITIONAL        = &H0??     ' // Georgian Traditional order
%SORT_GEORGIAN_MODERN             = &H1??     ' // Georgian Modern order

'//
'//  A language ID is a 16 bit value which is the combination of a
'//  primary language ID and a secondary language ID.  The bits are
'//  allocated as follows:
'//
'//       +-----------------------+-------------------------+
'//       |     Sublanguage ID    |   Primary Language ID   |
'//       +-----------------------+-------------------------+
'//        15                   10 9                       0   bit
'//
'//  WARNING:  This pattern isn't always follows, Serbina, Bosnian & Croation
'//            for example.
'//
'//  It is recommended that applications test for locale names or actual LCIDs.
'//
'//  Language ID creation/extraction macros:
'//
'//    MAKELANGID    - construct language id from a primary language id and
'//                    a sublanguage id.
'//    PRIMARYLANGID - extract primary language id from a language id.
'//    SUBLANGID     - extract sublanguage id from a language id.
'//
'//  Note that the LANG, SUBLANG construction is not always consistent.
'//  The named locale APIs (eg GetLocaleInfoEx) are recommended.
'//
'//  Language IDs do not exist for all locales
'//

'#define MAKELANGID(p, s)       ((((WORD  )(s)) << 10) | (WORD  )(p))
'#define PRIMARYLANGID(lgid)    ((WORD  )(lgid) & 0x3ff)
'#define SUBLANGID(lgid)        ((WORD  )(lgid) >> 10)

FUNCTION MAKELANGID (BYVAL p AS WORD, BYVAL s AS WORD) AS WORD
   SHIFT LEFT s, 10
   FUNCTION = s OR p
END FUNCTION

FUNCTION PRIMARYLANGID (BYVAL lgid AS WORD) AS WORD
  FUNCTION = lgid AND &H3FF
END FUNCTION

FUNCTION SUBLANGID (BYVAL lgid AS WORD) AS WORD
   SHIFT RIGHT lgid, 10
   FUNCTION = lgid
END FUNCTION

'//
'//  A locale ID is a 32 bit value which is the combination of a
'//  language ID, a sort ID, and a reserved area.  The bits are
'//  allocated as follows:
'//
'//       +-------------+---------+-------------------------+
'//       |   Reserved  | Sort ID |      Language ID        |
'//       +-------------+---------+-------------------------+
'//        31         20 19     16 15                      0   bit
'//
'//  WARNING: This pattern isn't always followed (es-ES_tradnl vs es-ES for example)
'//
'//  It is recommended that applications test for locale names or actual LCIDs.
'//
'//  Locale ID creation/extraction macros:
'//
'//    MAKELCID            - construct the locale id from a language id and a sort id.
'//    MAKESORTLCID        - construct the locale id from a language id, sort id, and sort version.
'//    LANGIDFROMLCID      - extract the language id from a locale id.
'//    SORTIDFROMLCID      - extract the sort id from a locale id.
'//    SORTVERSIONFROMLCID - extract the sort version from a locale id.
'//
'//  Note that the LANG, SUBLANG construction is not always consistent.
'//  The named locale APIs (eg GetLocaleInfoEx) are recommended.
'//
'//  LCIDs do not exist for all locales.
'//

%NLS_VALID_LOCALE_MASK = &H000fffff

'#define MAKELCID(lgid, srtid)  ((DWORD)((((DWORD)((WORD  )(srtid))) << 16) |  \
'                                         ((DWORD)((WORD  )(lgid)))))

FUNCTION MAKELCID (BYVAL wLanguageID AS WORD, BYVAL wSortID AS WORD) AS DWORD
   FUNCTION = MAK(DWORD, wLanguageID, wSortID AND &H000F)
END FUNCTION

'#define MAKESORTLCID(lgid, srtid, ver)                                            \
'                               ((DWORD)((MAKELCID(lgid, srtid)) |             \
'                                    (((DWORD)((WORD  )(ver))) << 20)))
'#define LANGIDFROMLCID(lcid)   ((WORD  )(lcid))
'#define SORTIDFROMLCID(lcid)   ((WORD  )((((DWORD)(lcid)) >> 16) & 0xf))
'#define SORTVERSIONFROMLCID(lcid)  ((WORD  )((((DWORD)(lcid)) >> 20) & 0xf))

FUNCTION MAKESORTLCID (BYVAL lgid AS WORD, BYVAL srtid AS WORD, BYVAL ver AS WORD) AS DWORD
   SHIFT LEFT ver, 20
   FUNCTION = MAKELCID(lgid, srtid) OR ver
END FUNCTION

FUNCTION LANGIDFROMLCID (BYVAL lcid AS DWORD) AS WORD
   FUNCTION = CWRD(lcid)
END FUNCTION

FUNCTION SORTIDFROMLCID (BYVAL lcid AS DWORD) AS WORD
   SHIFT RIGHT lcid, 16
   FUNCTION = CWRD(lcid) AND &HF
END FUNCTION

FUNCTION SORTVERSIONFROMLCID (BYVAL lcid AS DWORD) AS WORD
   SHIFT RIGHT lcid, 20
   FUNCTION = CWRD(lcid) AND &HF
END FUNCTION

'// 8 characters for language
'// 8 characters for region
'// 64 characters for suffix (script)
'// 2 characters for '-' separators
'// 2 characters for prefix like "i-" or "x-"
'// 1 null termination
%LOCALE_NAME_MAX_LENGTH   = 85

'//
'//  Default System and User IDs for language and locale.
'//  Locale names such as LOCALE_NAME_SYSTEM_DEFAULT, LOCALE_NAME_USER_DEFAULT,
'//  and LOCALE_NAME_INVARIANT are preferred.
'//

'#define LANG_SYSTEM_DEFAULT    (MAKELANGID(LANG_NEUTRAL, SUBLANG_SYS_DEFAULT))
'#define LANG_USER_DEFAULT      (MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT))

%LANG_SYSTEM_DEFAULT = &H0800???
%LANG_USER_DEFAULT   = &H0400???

'#define LOCALE_SYSTEM_DEFAULT  (MAKELCID(LANG_SYSTEM_DEFAULT, SORT_DEFAULT))
'#define LOCALE_USER_DEFAULT    (MAKELCID(LANG_USER_DEFAULT, SORT_DEFAULT))

%LOCALE_USER_DEFAULT     = &H0400???
%LOCALE_SYSTEM_DEFAULT   = &H0800???

'//
'//  Other special IDs for language and locale.
'//

'#define LOCALE_CUSTOM_DEFAULT                                                 \
'          (MAKELCID(MAKELANGID(LANG_NEUTRAL, SUBLANG_CUSTOM_DEFAULT), SORT_DEFAULT))
%LOCALE_CUSTOM_DEFAULT     = &H0C00???

'#define LOCALE_CUSTOM_UNSPECIFIED                                             \
'          (MAKELCID(MAKELANGID(LANG_NEUTRAL, SUBLANG_CUSTOM_UNSPECIFIED), SORT_DEFAULT))
%LOCALE_CUSTOM_UNSPECIFIED = &H1000???

'#define LOCALE_CUSTOM_UI_DEFAULT                                              \
'          (MAKELCID(MAKELANGID(LANG_NEUTRAL, SUBLANG_UI_CUSTOM_DEFAULT), SORT_DEFAULT))
%LOCALE_CUSTOM_UI_DEFAULT  = &H1400???

'#define LOCALE_NEUTRAL                                                        \
'          (MAKELCID(MAKELANGID(LANG_NEUTRAL, SUBLANG_NEUTRAL), SORT_DEFAULT))
%LOCALE_NEUTRAL = 0

'#define LOCALE_INVARIANT                                                      \
'          (MAKELCID(MAKELANGID(LANG_INVARIANT, SUBLANG_NEUTRAL), SORT_DEFAULT))
%LOCALE_INVARIANT = &H007F&

#IF NOT %DEF(%WIN32_NO_STATUS) '-----------------------------------------------

' // Wrongly defined as DWORD in Windows 7 SDK, conflicts with the same constants
' // defines in nstatus.h. Therefore, it's simpler to just include ntstatus.inc.

#INCLUDE ONCE "ntstatus.inc"

'%STATUS_WAIT_0                     = &H00000000&
'%STATUS_ABANDONED_WAIT_0           = &H00000080&
'%STATUS_USER_APC                   = &H000000C0&
'%STATUS_TIMEOUT                    = &H00000102&
'%STATUS_PENDING                    = &H00000103&
'%DBG_EXCEPTION_HANDLED             = &H00010001&
'%DBG_CONTINUE                      = &H00010002&
'%STATUS_SEGMENT_NOTIFICATION       = &H40000005&
'%DBG_TERMINATE_THREAD              = &H40010003&
'%DBG_TERMINATE_PROCESS             = &H40010004&
'%DBG_CONTROL_C                     = &H40010005&
'%DBG_PRINTEXCEPTION_C              = &H40010006&
'%DBG_RIPEXCEPTION                  = &H40010007&
'%DBG_CONTROL_BREAK                 = &H40010008&
'%DBG_COMMAND_EXCEPTION             = &H40010009&
'%STATUS_GUARD_PAGE_VIOLATION       = &H80000001&
'%STATUS_DATATYPE_MISALIGNMENT      = &H80000002&
'%STATUS_BREAKPOINT                 = &H80000003&
'%STATUS_SINGLE_STEP                = &H80000004&
'%STATUS_LONGJUMP                   = &H80000026&
'%STATUS_UNWIND_CONSOLIDATE         = &H80000029&
'%DBG_EXCEPTION_NOT_HANDLED         = &H80010001&
'%STATUS_ACCESS_VIOLATION           = &HC0000005&
'%STATUS_IN_PAGE_ERROR              = &HC0000006&
'%STATUS_INVALID_HANDLE             = &HC0000008&
'%STATUS_INVALID_PARAMETER          = &HC000000D&
'%STATUS_NO_MEMORY                  = &HC0000017&
'%STATUS_ILLEGAL_INSTRUCTION        = &HC000001D&
'%STATUS_NONCONTINUABLE_EXCEPTION   = &HC0000025&
'%STATUS_INVALID_DISPOSITION        = &HC0000026&
'%STATUS_ARRAY_BOUNDS_EXCEEDED      = &HC000008C&
'%STATUS_FLOAT_DENORMAL_OPERAND     = &HC000008D&
'%STATUS_FLOAT_DIVIDE_BY_ZERO       = &HC000008E&
'%STATUS_FLOAT_INEXACT_RESULT       = &HC000008F&
'%STATUS_FLOAT_INVALID_OPERATION    = &HC0000090&
'%STATUS_FLOAT_OVERFLOW             = &HC0000091&
'%STATUS_FLOAT_STACK_CHECK          = &HC0000092&
'%STATUS_FLOAT_UNDERFLOW            = &HC0000093&
'%STATUS_INTEGER_DIVIDE_BY_ZERO     = &HC0000094&
'%STATUS_INTEGER_OVERFLOW           = &HC0000095&
'%STATUS_PRIVILEGED_INSTRUCTION     = &HC0000096&
'%STATUS_STACK_OVERFLOW             = &HC00000FD&
'%STATUS_DLL_NOT_FOUND              = &HC0000135&
'%STATUS_ORDINAL_NOT_FOUND          = &HC0000138&
'%STATUS_ENTRYPOINT_NOT_FOUND       = &HC0000139&
'%STATUS_CONTROL_C_EXIT             = &HC000013A&
'%STATUS_DLL_INIT_FAILED            = &HC0000142&
'%STATUS_FLOAT_MULTIPLE_FAULTS      = &HC00002B4&
'%STATUS_FLOAT_MULTIPLE_TRAPS       = &HC00002B5&
''%STATUS_ILLEGAL_VLM_REFERENCE      = &HC00002C0&   ' Not in Windows 7 SDK
'%STATUS_REG_NAT_CONSUMPTION        = &HC00002C9&
'%STATUS_STACK_BUFFER_OVERRUN       = &HC0000409&
'%STATUS_INVALID_CRUNTIME_PARAMETER = &HC0000417&
'%STATUS_ASSERTION_FAILURE          = &HC0000420&
''#if defined(STATUS_SUCCESS) || (_WIN32_WINNT > 0x0500) || (_WIN32_FUSION >= 0x0100)
'%STATUS_SXS_EARLY_DEACTIVATION     = &HC015000F&
'%STATUS_SXS_INVALID_DEACTIVATION   = &HC0150010&
''#endif

#ENDIF ' #IF NOT %DEF(%WIN32_NO_STATUS) ---------------------------------------

%MAXIMUM_WAIT_OBJECTS = 64  ' // Maximum number of wait objects
%MAXIMUM_SUSPEND_COUNT = %MAXCHAR  ' // Maximum times thread can be suspended

'typedef ULONG_PTR KSPIN_LOCK;
'typedef KSPIN_LOCK *PKSPIN_LOCK;

'//
'// Define 128-bit 16-byte aligned xmm register type.
'//

'typedef struct DECLSPEC_ALIGN(16) _M128A {
'    ULONGLONG Low;
'    LONGLONG High;
'} M128A, *PM128A;

'//
'// Format of data for (F)XSAVE/(F)XRSTOR instruction
'//

'typedef struct DECLSPEC_ALIGN(16) _XSAVE_FORMAT {
'    WORD   ControlWord;
'    WORD   StatusWord;
'    BYTE   TagWord;
'    BYTE   Reserved1;
'    WORD   ErrorOpcode;
'    DWORD  ErrorOffset;
'    WORD   ErrorSelector;
'    WORD   Reserved2;
'    DWORD  DataOffset;
'    WORD   DataSelector;
'    WORD   Reserved3;
'    DWORD  MxCsr;
'    DWORD  MxCsr_Mask;
'    M128A  FloatRegisters[8];

'#if defined(_WIN64)

'    M128A XmmRegisters[16];
'    BYTE  Reserved4[96];

'#else

'    M128A XmmRegisters[8];
'    BYTE  Reserved4[192];

'    //
'    // The fields below are not part of XSAVE/XRSTOR format.
'    // They are written by the OS which is relying on a fact that
'    // neither (FX)SAVE nor (F)XSTOR used this area.
'    //

'    DWORD   StackControl[7];    // KERNEL_STACK_CONTROL structure actualy
'    DWORD   Cr0NpxState;

'#endif

'} XSAVE_FORMAT, *PXSAVE_FORMAT;

'typedef struct DECLSPEC_ALIGN(8) _XSAVE_AREA_HEADER {
'    DWORD64 Mask;
'    DWORD64 Reserved[7];
'} XSAVE_AREA_HEADER, *PXSAVE_AREA_HEADER;

'typedef struct DECLSPEC_ALIGN(16) _XSAVE_AREA {
'    XSAVE_FORMAT LegacyState;
'    XSAVE_AREA_HEADER Header;
'} XSAVE_AREA, *PXSAVE_AREA;

'typedef struct _XSTATE_CONTEXT {
'    DWORD64 Mask;
'    DWORD Length;
'    DWORD Reserved1;
'    __field_bcount_opt(Length) PXSAVE_AREA Area;

'#if defined(_X86_)
'    DWORD Reserved2;
'#endif

'    PVOID Buffer;

'#if defined(_X86_)
'    DWORD Reserved3;
'#endif

'} XSTATE_CONTEXT, *PXSTATE_CONTEXT;


'#define XSAVE_ALIGN                 64
'#define MINIMAL_XSTATE_AREA_LENGTH  sizeof(XSAVE_AREA)

'//
'// This structure specifies an offset (from the beginning of CONTEXT_EX
'// structure) and size of a single chunk of an extended context structure.
'//
'// N.B. Offset may be negative.
'//

' // Size = 8 bytes
TYPE CONTEXT_CHUNK DWORD
   Offset AS LONG    ' LONG
   Length AS DWORD   ' DWORD
END TYPE

'//
'// CONTEXT_EX structure is an extension to CONTEXT structure. It defines
'// a context record as a set of disjoint variable-sized buffers (chunks)
'// each containing a portion of processor state. Currently there are only
'// two buffers (chunks) are defined:
'//
'//   - Legacy, that stores traditional CONTEXT structure;
'//   - XState, that stores XSAVE save area buffer starting from
'//     XSAVE_AREA_HEADER, i.e. without the first 512 bytes.
'//
'// There a few assumptions exists that simplify conversion of PCONTEXT
'// pointer to PCONTEXT_EX pointer.
'//
'// 1. APIs that work with PCONTEXT pointers assume that CONTEXT_EX is
'//    stored right after the CONTEXT structure. It is also assumed that
'//    CONTEXT_EX is present if and only if corresponding CONTEXT_XXX
'//    flags are set in CONTEXT.ContextFlags.
'//
'// 2. CONTEXT_EX.Legacy is always present if CONTEXT_EX structure is
'//    present. All other chunks are optional.
'//
'// 3. CONTEXT.ContextFlags unambigiously define which chunks are
'//    present. I.e. if CONTEXT_XSTATE is set CONTEXT_EX.XState is valid.
'//

' // Size = 24 bytes
TYPE CONTEXT_EX DWORD

'    //
'    // The total length of the structure starting from the chunk with
'    // the smallest offset. N.B. that the offset may be negative.
'    //

   All AS CONTEXT_CHUNK

'    //
'    // Wrapper for the traditional CONTEXT structure. N.B. the size of
'    // the chunk may be less than sizeof(CONTEXT) is some cases (when
'    // CONTEXT_EXTENDED_REGISTERS is not set on x86 for instance).
'    //

   Legacy AS CONTEXT_CHUNK

'    //
'    // CONTEXT_XSTATE: Extended processor state chunk. The state is
'    // stored in the same format XSAVE operation strores it with
'    // exception of the first 512 bytes, i.e. staring from
'    // XSAVE_AREA_HEADER. The lower two bits corresponding FP and
'    // SSE state must be zero.
'    //

   XState AS CONTEXT_CHUNK

END TYPE

'#define CONTEXT_EX_LENGTH   ALIGN_UP_BY(sizeof(CONTEXT_EX), STACK_ALIGN)

'//
'// These macros make context chunks manupulations easier.
'//

'#define RTL_CONTEXT_EX_OFFSET(ContextEx, Chunk)         \
'    ((ContextEx)->Chunk.Offset)

'#define RTL_CONTEXT_EX_LENGTH(ContextEx, Chunk)         \
'    ((ContextEx)->Chunk.Length)

'#define RTL_CONTEXT_EX_CHUNK(Base, Layout, Chunk)       \
'    ((PVOID)((PCHAR)(Base) + RTL_CONTEXT_EX_OFFSET(Layout, Chunk)))

'#define RTL_CONTEXT_OFFSET(Context, Chunk)              \
'    RTL_CONTEXT_EX_OFFSET((PCONTEXT_EX)(Context + 1), Chunk)

'#define RTL_CONTEXT_LENGTH(Context, Chunk)              \
'    RTL_CONTEXT_EX_LENGTH((PCONTEXT_EX)(Context + 1), Chunk)

'#define RTL_CONTEXT_CHUNK(Context, Chunk)               \
'    RTL_CONTEXT_EX_CHUNK((PCONTEXT_EX)(Context + 1),    \
'                         (PCONTEXT_EX)(Context + 1),    \
'                         Chunk)

'//
'// The following values specify the type of failing access when the status is
'// STATUS_ACCESS_VIOLATION and the first parameter in the execpetion record.
'//

%EXCEPTION_READ_FAULT         = 0   ' // Access violation was caused by a read
%EXCEPTION_WRITE_FAULT        = 1   ' // Access violation was caused by a write
%EXCEPTION_EXECUTE_FAULT      = 8   ' // Access violation was caused by an instruction fetch

'// begin_wx86

'//
'//  Define the size of the 80387 save area, which is in the context frame.
'//

%SIZE_OF_80387_REGISTERS = 80

'//
'// The following flags control the contents of the CONTEXT structure.
'//

'#if !defined(RC_INVOKED)

%CONTEXT_i386            = &H00010000???    ' this assumes that i386 and
%CONTEXT_i486            = &H00010000???    ' i486 have identical context records

'// end_wx86

%CONTEXT_CONTROL         = %CONTEXT_i386 OR &H00000001??? ' SS:SP, CS:IP, FLAGS, BP
%CONTEXT_INTEGER         = %CONTEXT_i386 OR &H00000002??? ' AX, BX, CX, DX, SI, DI
%CONTEXT_SEGMENTS        = %CONTEXT_i386 OR &H00000004??? ' DS, ES, FS, GS
%CONTEXT_FLOATING_POINT  = %CONTEXT_i386 OR &H00000008??? ' 387 state
%CONTEXT_DEBUG_REGISTERS = %CONTEXT_i386 OR &H00000010??? ' DB 0-3,6,7
%CONTEXT_EXTENDED_REGISTERS = %CONTEXT_i386 OR &H00000020???  ' // cpu specific extensions

%CONTEXT_FULL            = %CONTEXT_CONTROL OR %CONTEXT_INTEGER OR %CONTEXT_SEGMENTS

%CONTEXT_ALL = %CONTEXT_CONTROL OR %CONTEXT_INTEGER OR %CONTEXT_SEGMENTS OR %CONTEXT_FLOATING_POINT OR %CONTEXT_DEBUG_REGISTERS OR %CONTEXT_EXTENDED_REGISTERS

%CONTEXT_XSTATE          = %CONTEXT_i386 OR &H00000040???

'// begin_wx86

'#endif

' // Size = 112 bytes
TYPE FLOATING_SAVE_AREA DWORD FILL
   ControlWord   AS DWORD
   StatusWord    AS DWORD
   TagWord       AS DWORD
   ErrorOffset   AS DWORD
   ErrorSelector AS DWORD
   DataOffset    AS DWORD
   DataSelector  AS DWORD
   RegisterArea(%SIZE_OF_80387_REGISTERS - 1) AS BYTE
   Cr0NpxState   AS DWORD
END TYPE

%MAXIMUM_SUPPORTED_EXTENSION = 512

'#include "pshpack4.h"

'//
'// Context Frame
'//
'//  This frame has a several purposes: 1) it is used as an argument to
'//  NtContinue, 2) is is used to constuct a call frame for APC delivery,
'//  and 3) it is used in the user level thread creation routines.
'//
'//  The layout of the record conforms to a standard call frame.
'//

' // Size = 716 bytes
TYPE CONTEXT DWORD
   ContextFlags AS DWORD
   Dr0          AS DWORD
   Dr1          AS DWORD
   Dr2          AS DWORD
   Dr3          AS DWORD
   Dr6          AS DWORD
   Dr7          AS DWORD
   FloatSave    AS FLOATING_SAVE_AREA
   SegGs        AS DWORD
   SegFs        AS DWORD
   SegEs        AS DWORD
   SegDs        AS DWORD
   Edi          AS DWORD
   Esi          AS DWORD
   Ebx          AS DWORD
   Edx          AS DWORD
   Ecx          AS DWORD
   Eax          AS DWORD
   Ebp          AS DWORD
   Eip          AS DWORD
   SegCs        AS DWORD                ' MUST BE SANITIZED
   EFlags       AS DWORD                ' MUST BE SANITIZED
   Esp          AS DWORD
   segSs        AS DWORD
   ' //
   ' // This section is specified/returned if the ContextFlags word
   ' // contains the flag CONTEXT_EXTENDED_REGISTERS.
   ' // The format and contexts are processor specific
   ' //
   ExtendedRegisters(%MAXIMUM_SUPPORTED_EXTENSION - 1) AS BYTE
END TYPE

'#include "poppack.h"

'// begin_ntminiport
'#endif //_X86_


'#ifndef _LDT_ENTRY_DEFINED
'#define _LDT_ENTRY_DEFINED

'typedef struct _LDT_ENTRY {
'    WORD    LimitLow;
'    WORD    BaseLow;
'    union {
'        struct {
'            BYTE    BaseMid;
'            BYTE    Flags1;     // Declare as bytes to avoid alignment
'            BYTE    Flags2;     // Problems.
'            BYTE    BaseHi;
'        } Bytes;
'        struct {
'            DWORD   BaseMid : 8;
'            DWORD   Type : 5;
'            DWORD   Dpl : 2;
'            DWORD   Pres : 1;
'            DWORD   LimitHi : 4;
'            DWORD   Sys : 1;
'            DWORD   Reserved_0 : 1;
'            DWORD   Default_Big : 1;
'            DWORD   Granularity : 1;
'            DWORD   BaseHi : 8;
'        } Bits;
'    } HighWord;
'} LDT_ENTRY, *PLDT_ENTRY;

'#endif

#IF NOT %DEF(%LDT_ENTRY_DEFINED) '---------------------------------------------
' // Size = 4 bytes
TYPE LDT_BYTES BYTE
   BaseMid AS BYTE
   Flags1  AS BYTE    ' // Declare as bytes to avoid alignment
   Flags2  AS BYTE    ' // Problems.
   BaseHi  AS BYTE
END TYPE

' // Size = 4 bytes
TYPE LDT_BITS DWORD
   BaseMid     AS BIT * 8 IN DWORD
   Type        AS BIT * 5
   Dpl         AS BIT * 2
   Pres        AS BIT * 1
   LimitHi     AS BIT * 4
   Sys         AS BIT * 1
   Reserved_0  AS BIT * 1
   Default_Big AS BIT * 1
   Granularity AS BIT * 1
   BaseHi      AS BIT * 8
END TYPE

' // For compatibility with the PB declares
TYPE PB_LDT_BITS DWORD
   BaseMid     AS BIT * 8 IN DWORD
   nType       AS BIT * 5
   Dpl         AS BIT * 2
   Pres        AS BIT * 1
   LimitHi     AS BIT * 4
   Sys         AS BIT * 1
   Reserved_0  AS BIT * 1
   Default_Big AS BIT * 1
   Granularity AS BIT * 1
   BaseHi      AS BIT * 8
END TYPE

' // Size = 4 bytes
UNION LDT_ENTRY_BYTES_BITS_UNION DWORD
   Bytes AS LDT_BYTES
   Bits  AS LDT_BITS
   ' // For compatibility with the PB declares
   Bitss AS PB_LDT_BITS
END UNION

UNION LDT_ENTRY_UNION DWORD
   HighWord AS LDT_ENTRY_BYTES_BITS_UNION
   LDT_ENTRY_BYTES_BITS_UNION
END UNION

' // Size = 8 bytes
TYPE LDT_ENTRY DWORD FILL
   LimitLow AS WORD
   BaseLow  AS WORD
   LDT_ENTRY_UNION
END TYPE
#ENDIF ' #IF NOT %DEF(%LDT_ENTRY_DEFINED) -------------------------------------

%WOW64_CONTEXT_i386      = &H00010000???   ' // this assumes that i386 and
%WOW64_CONTEXT_i486      = &H00010000???   ' // i486 have identical context records

%WOW64_CONTEXT_CONTROL            = %WOW64_CONTEXT_i386 OR &H00000001??? ' // SS:SP, CS:IP, FLAGS, BP
%WOW64_CONTEXT_INTEGER            = %WOW64_CONTEXT_i386 OR &H00000002??? ' // AX, BX, CX, DX, SI, DI
%WOW64_CONTEXT_SEGMENTS           = %WOW64_CONTEXT_i386 OR &H00000004??? ' // DS, ES, FS, GS
%WOW64_CONTEXT_FLOATING_POINT     = %WOW64_CONTEXT_i386 OR &H00000008??? ' // 387 state
%WOW64_CONTEXT_DEBUG_REGISTERS    = %WOW64_CONTEXT_i386 OR &H00000010??? ' // DB 0-3,6,7
%WOW64_CONTEXT_EXTENDED_REGISTERS = %WOW64_CONTEXT_i386 OR &H00000020??? ' // cpu specific extensions

%WOW64_CONTEXT_FULL = %WOW64_CONTEXT_CONTROL OR %WOW64_CONTEXT_INTEGER OR %WOW64_CONTEXT_SEGMENTS

%WOW64_CONTEXT_ALL  = %WOW64_CONTEXT_CONTROL OR %WOW64_CONTEXT_INTEGER OR %WOW64_CONTEXT_SEGMENTS OR _
                      %WOW64_CONTEXT_FLOATING_POINT OR %WOW64_CONTEXT_DEBUG_REGISTERS OR _
                      %WOW64_CONTEXT_EXTENDED_REGISTERS

%WOW64_CONTEXT_XSTATE             = %WOW64_CONTEXT_i386 OR &H00000040???

'//
'//  Define the size of the 80387 save area, which is in the context frame.
'//

%WOW64_SIZE_OF_80387_REGISTERS     = 80

%WOW64_MAXIMUM_SUPPORTED_EXTENSION = 512

' // Size = 112 bytes
TYPE WOW64_FLOATING_SAVE_AREA DWORD FILL
   ControlWord   AS DWORD   ' DWORD
   StatusWord    AS DWORD   ' DWORD
   TagWord       AS DWORD   ' DWORD
   ErrorOffset   AS DWORD   ' DWORD
   ErrorSelector AS DWORD   ' DWORD
   DataOffset    AS DWORD   ' DWORD
   DataSelector  AS DWORD   ' DWORD
   RegisterArea(%WOW64_SIZE_OF_80387_REGISTERS - 1) AS BYTE   ' BYTE
   Cr0NpxState   AS DWORD   ' DWORD
END TYPE

'#include "pshpack4.h"

'//
'// Context Frame
'//
'//  This frame has a several purposes: 1) it is used as an argument to
'//  NtContinue, 2) is is used to constuct a call frame for APC delivery,
'//  and 3) it is used in the user level thread creation routines.
'//
'//  The layout of the record conforms to a standard call frame.
'//

' // Size = 716 bytes
TYPE WOW64_CONTEXT DWORD
   ContextFlags AS DWORD   ' DWORD
   Dr0          AS DWORD   ' DWORD
   Dr1          AS DWORD   ' DWORD
   Dr2          AS DWORD   ' DWORD
   Dr3          AS DWORD   ' DWORD
   Dr6          AS DWORD   ' DWORD
   Dr7          AS DWORD   ' DWORD
   FloatSave    AS WOW64_FLOATING_SAVE_AREA
   SegGs        AS DWORD   ' DWORD
   SegFs        AS DWORD   ' DWORD
   SegEs        AS DWORD   ' DWORD
   SegDs        AS DWORD   ' DWORD
   Edi          AS DWORD   ' DWORD
   Esi          AS DWORD   ' DWORD
   Ebx          AS DWORD   ' DWORD
   Edx          AS DWORD   ' DWORD
   Ecx          AS DWORD   ' DWORD
   Eax          AS DWORD   ' DWORD
   Ebp          AS DWORD   ' DWORD
   Eip          AS DWORD   ' DWORD
   SegCs        AS DWORD   ' DWORD             ' // MUST BE SANITIZED
   EFlags       AS DWORD   ' DWORD             ' // MUST BE SANITIZED
   Esp          AS DWORD   ' DWORD
   SegSs        AS DWORD   ' DWORD
   ExtendedRegisters(%WOW64_MAXIMUM_SUPPORTED_EXTENSION - 1) AS BYTE   ' BYTE
END TYPE

'#include "poppack.h"

' // Size = 4 bytes
TYPE WOW64_LDT_BYTES BYTE
   BaseMid AS BYTE
   Flags1  AS BYTE    ' // Declare as bytes to avoid alignment
   Flags2  AS BYTE    ' // Problems.
   BaseHi  AS BYTE
END TYPE

' // Size = 4 bytes
TYPE WOW64_LDT_BITS DWORD
   BaseMid     AS BIT * 8 IN DWORD
   Type        AS BIT * 5
   Dpl         AS BIT * 2
   Pres        AS BIT * 1
   LimitHi     AS BIT * 4
   Sys         AS BIT * 1
   Reserved_0  AS BIT * 1
   Default_Big AS BIT * 1
   Granularity AS BIT * 1
   BaseHi      AS BIT * 8
END TYPE

' // Size = 4 bytes
UNION WOW64_LDT_ENTRY_UNION DWORD
   Bytes AS LDT_BYTES
   Bits  AS LDT_BITS
END UNION

' // Size = 8 bytes
TYPE WOW64_LDT_ENTRY DWORD FILL
   LimitLow AS INTEGER
   BaseLow  AS INTEGER
   LDT_ENTRY_UNION
END TYPE

' // Size = 12 bytes
TYPE WOW64_DESCRIPTOR_TABLE_ENTRY DWORD
   Selector   AS DWORD   ' DWORD
   Descriptor AS WOW64_LDT_ENTRY
END TYPE

%EXCEPTION_NONCONTINUABLE     = &H1  ' Noncontinuable exception
%EXCEPTION_MAXIMUM_PARAMETERS = 15   ' maximum number of exception parameters

'//
'// Exception record definition.
'//

' // Size = 80 bytes
TYPE EXCEPTION_RECORD DWORD
   ExceptionCode    AS DWORD
   ExceptionFlags   AS DWORD
   pExceptionRecord AS EXCEPTION_RECORD PTR
   ExceptionAddress AS DWORD
   NumberParameters AS DWORD
   ExceptionInformation(%EXCEPTION_MAXIMUM_PARAMETERS - 1) AS DWORD
END TYPE

' // Size = 80 bytes
TYPE EXCEPTION_RECORD32 DWORD
   ExceptionCode    AS DWORD
   ExceptionFlags   AS DWORD
   pExceptionRecord AS DWORD
   ExceptionAddress AS DWORD
   NumberParameters AS DWORD
   ExceptionInformation(%EXCEPTION_MAXIMUM_PARAMETERS - 1) AS DWORD
END TYPE

' // Size = 152 bytes
TYPE EXCEPTION_RECORD64 QWORD FILL
   ExceptionCode    AS DWORD
   ExceptionFlags   AS DWORD
   pExceptionRecord AS QUAD
   ExceptionAddress AS QUAD
   NumberParameters AS DWORD
   ExceptionInformation(%EXCEPTION_MAXIMUM_PARAMETERS - 1) AS QUAD
END TYPE

'//
'// Typedef for pointer returned by exception_info()
'//

'typedef struct _EXCEPTION_POINTERS {
'    PEXCEPTION_RECORD ExceptionRecord;
'    PCONTEXT ContextRecord;
'} EXCEPTION_POINTERS, *PEXCEPTION_POINTERS;
'typedef PVOID PACCESS_TOKEN;
'typedef PVOID PSECURITY_DESCRIPTOR;
'typedef PVOID PSID;

' // Size = 8 bytes
TYPE EXCEPTION_POINTERS DWORD
   ExceptionRecord AS EXCEPTION_RECORD PTR
   ContextRecord   AS CONTEXT PTR
END TYPE

DECLARE SUB RtlUnwind IMPORT "KERNEL32.DLL" ALIAS "RtlUnwind" ( _
   BYVAL TargetFrame AS DWORD _                         ' __in_opt PVOID TargetFrame
 , BYVAL TargetIp AS DWORD _                            ' __in_opt PVOID TargetIp
 , BYREF ExceptionRecord AS EXCEPTION_RECORD _          ' __in_opt PEXCEPTION_RECORD ExceptionRecord
 , BYVAL ReturnValue AS DWORD _                         ' __in PVOID ReturnValue
 )                                                      ' VOID

'typedef PVOID PACCESS_TOKEN;
'typedef PVOID PSECURITY_DESCRIPTOR;
'typedef PVOID PSID;


'////////////////////////////////////////////////////////////////////////
'//                                                                    //
'//                             ACCESS MASK                            //
'//                                                                    //
'////////////////////////////////////////////////////////////////////////

'//
'//  Define the access mask as a longword sized structure divided up as
'//  follows:
'//
'//       3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1 1 1
'//       1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0
'//      +---------------+---------------+-------------------------------+
'//      |G|G|G|G|Res'd|A| StandardRights|         SpecificRights        |
'//      |R|W|E|A|     |S|               |                               |
'//      +-+-------------+---------------+-------------------------------+
'//
'//      typedef struct _ACCESS_MASK {
'//          WORD  SpecificRights;
'//          BYTE  StandardRights;
'//          BYTE  AccessSystemAcl : 1;
'//          BYTE  Reserved : 3;
'//          BYTE  GenericAll : 1;
'//          BYTE  GenericExecute : 1;
'//          BYTE  GenericWrite : 1;
'//          BYTE  GenericRead : 1;
'//      } ACCESS_MASK;
'//      typedef ACCESS_MASK *PACCESS_MASK;
'//
'//  but to make life simple for programmer's we'll allow them to specify
'//  a desired access mask by simply OR'ing together mulitple single rights
'//  and treat an access mask as a DWORD.  For example
'//
'//      DesiredAccess = DELETE | READ_CONTROL
'//
'//  So we'll declare ACCESS_MASK as DWORD
'//

'typedef DWORD ACCESS_MASK;
'typedef ACCESS_MASK *PACCESS_MASK;

MACRO ACCESS_MASK = DWORD

'////////////////////////////////////////////////////////////////////////
'//                                                                    //
'//                             ACCESS TYPES                           //
'//                                                                    //
'////////////////////////////////////////////////////////////////////////


'//
'//  The following are masks for the predefined standard access types
'//

%DELETE                   = &H00010000???
%READ_CONTROL             = &H00020000???
%WRITE_DAC                = &H00040000???
%WRITE_OWNER              = &H00080000???
%SYNCHRONIZE              = &H00100000???

%STANDARD_RIGHTS_REQUIRED = &H000F0000???

%STANDARD_RIGHTS_READ     = %READ_CONTROL
%STANDARD_RIGHTS_WRITE    = %READ_CONTROL
%STANDARD_RIGHTS_EXECUTE  = %READ_CONTROL

%STANDARD_RIGHTS_ALL      = &H001F0000???

%SPECIFIC_RIGHTS_ALL      = &H0000FFFF???

'//
'// AccessSystemAcl access type
'//

%ACCESS_SYSTEM_SECURITY   = &H01000000???

'//
'// MaximumAllowed access type
'//

%MAXIMUM_ALLOWED          = &H02000000???

'//
'//  These are the generic rights.
'//

%GENERIC_READ             = &H80000000???
%GENERIC_WRITE            = &H40000000???
%GENERIC_EXECUTE          = &H20000000???
%GENERIC_ALL              = &H10000000???

'//
'//  Define the generic mapping array.  This is used to denote the
'//  mapping of each generic access right to a specific access mask.
'//

' // Size = 16 bytes
TYPE GENERIC_MAPPING DWORD
   GenericRead    AS ACCESS_MASK   ' ACCESS_MASK
   GenericWrite   AS ACCESS_MASK   ' ACCESS_MASK
   GenericExecute AS ACCESS_MASK   ' ACCESS_MASK
   GenericAll     AS ACCESS_MASK   ' ACCESS_MASK
END TYPE


'////////////////////////////////////////////////////////////////////////
'//                                                                    //
'//                        LUID_AND_ATTRIBUTES                         //
'//                                                                    //
'////////////////////////////////////////////////////////////////////////
'//
'//


'#include <pshpack4.h>

'typedef struct _LUID_AND_ATTRIBUTES {
'    LUID Luid;
'    DWORD Attributes;
'    } LUID_AND_ATTRIBUTES, * PLUID_AND_ATTRIBUTES;
'typedef LUID_AND_ATTRIBUTES LUID_AND_ATTRIBUTES_ARRAY[ANYSIZE_ARRAY];
'typedef LUID_AND_ATTRIBUTES_ARRAY *PLUID_AND_ATTRIBUTES_ARRAY;

' // Size = 12 bytes
TYPE LUID_AND_ATTRIBUTES DWORD
   Luid       AS QUAD
   Attributes AS DWORD
END TYPE

'#include <poppack.h>

'////////////////////////////////////////////////////////////////////////
'//                                                                    //
'//              Security Id     (SID)                                 //
'//                                                                    //
'////////////////////////////////////////////////////////////////////////
'//
'//
'// Pictorially the structure of an SID is as follows:
'//
'//         1   1   1   1   1   1
'//         5   4   3   2   1   0   9   8   7   6   5   4   3   2   1   0
'//      +---------------------------------------------------------------+
'//      |      SubAuthorityCount        |Reserved1 (SBZ)|   Revision    |
'//      +---------------------------------------------------------------+
'//      |                   IdentifierAuthority[0]                      |
'//      +---------------------------------------------------------------+
'//      |                   IdentifierAuthority[1]                      |
'//      +---------------------------------------------------------------+
'//      |                   IdentifierAuthority[2]                      |
'//      +---------------------------------------------------------------+
'//      |                                                               |
'//      +- -  -  -  -  -  -  -  SubAuthority[]  -  -  -  -  -  -  -  - -+
'//      |                                                               |
'//      +---------------------------------------------------------------+
'//
'//

'#ifndef SID_IDENTIFIER_AUTHORITY_DEFINED
'#define SID_IDENTIFIER_AUTHORITY_DEFINED
'typedef struct _SID_IDENTIFIER_AUTHORITY {
'    BYTE  Value[6];
'} SID_IDENTIFIER_AUTHORITY, *PSID_IDENTIFIER_AUTHORITY;
'#endif

' Note: Value is declared as Value(0 TO 5) in PB's WIN32API.INC,
' but declaring it as STRING * 6 allows to use CHR$(x, x, x, x, x, x)
' and also to assign to it predefined constants.
#IF NOT %DEF(%SID_IDENTIFIER_AUTHORITY_DEFINED)
%SID_IDENTIFIER_AUTHORITY_DEFINED = 1
UNION SID_IDENTIFIER_AUTHORITY_UNION
   Value(5) AS BYTE
   Value AS STRING * 6
END UNION
' // Size = 6 bytes
TYPE SID_IDENTIFIER_AUTHORITY BYTE
   SID_IDENTIFIER_AUTHORITY_UNION
END TYPE
#ENDIF

'#ifndef SID_DEFINED
'#define SID_DEFINED
'typedef struct _SID {
'   BYTE  Revision;
'   BYTE  SubAuthorityCount;
'   SID_IDENTIFIER_AUTHORITY IdentifierAuthority;
'#ifdef MIDL_PASS
'   [size_is(SubAuthorityCount)] DWORD SubAuthority[*];
'#else // MIDL_PASS
'   DWORD SubAuthority[ANYSIZE_ARRAY];
'#endif // MIDL_PASS
'} SID, *PISID;
'#endif

#IF NOT %DEF(%SID_DEFINED)
%SID_DEFINED = 1
' // Size = 12 bytes
TYPE SID BYTE
   Revision             AS BYTE   ' BYTE Revision
   SubAuthorityCount    AS BYTE   ' BYTE SubAuthorityCount
   IdentifierAuthority  AS SID_IDENTIFIER_AUTHORITY   ' SID_IDENTIFIER_AUTHORITY IdentifierAuthority
   SubAuthority(0)      AS DWORD  ' /* [size_is] */ ULONG SubAuthority[ 1 ]
END TYPE
#ENDIF

%SID_REVISION                    = 1     ' Current revision level
%SID_MAX_SUB_AUTHORITIES         = 15
%SID_RECOMMENDED_SUB_AUTHORITIES = 1     ' Will change to around 6 in a future release.

'#ifndef MIDL_PASS
'#define SECURITY_MAX_SID_SIZE  \
'      (sizeof(SID) - sizeof(DWORD) + (SID_MAX_SUB_AUTHORITIES * sizeof(DWORD)))
'#endif // MIDL_PASS

' SID_NAME_USE enum
%SidTypeUser           = 1
%SidTypeGroup          = 2
%SidTypeDomain         = 3
%SidTypeAlias          = 4
%SidTypeWellKnownGroup = 5
%SidTypeDeletedaccount = 6
%SidTypeInvalid        = 7
%SidTypeUnknown        = 8
%SidTypeComputer       = 9
%SidTypeLabel          = 10

'typedef struct _SID_AND_ATTRIBUTES {
'    PSID Sid;
'    DWORD Attributes;
'    } SID_AND_ATTRIBUTES, * PSID_AND_ATTRIBUTES;

'typedef SID_AND_ATTRIBUTES SID_AND_ATTRIBUTES_ARRAY[ANYSIZE_ARRAY];
'typedef SID_AND_ATTRIBUTES_ARRAY *PSID_AND_ATTRIBUTES_ARRAY;

#IF NOT %DEF(%SID_AND_ATTRIBUTES_DEFINED)
%SID_AND_ATTRIBUTES_DEFINED = 1
' // For compatibility with the OB declares
UNION SID_AND_ATTRIBUTES_SID_UNION
   Sid        AS SID PTR
   pSid       AS SID PTR
END UNION
' // Size = 8 bytes
TYPE SID_AND_ATTRIBUTES DWORD
   SID_AND_ATTRIBUTES_SID_UNION
   Attributes AS DWORD
END TYPE
#ENDIF

%SID_HASH_SIZE = 32
'typedef ULONG_PTR SID_HASH_ENTRY, *PSID_HASH_ENTRY;

' // Size = 136 bytes
TYPE SID_AND_ATTRIBUTES_HASH DWORD
   SidCount AS DWORD   ' DWORD
   SidAttr  AS SID_AND_ATTRIBUTES PTR   ' PSID_AND_ATTRIBUTES
   Hash(%SID_HASH_SIZE - 1) AS DWORD    ' SID_HASH_ENTRY
END TYPE

'/////////////////////////////////////////////////////////////////////////////
'//                                                                         //
'// Universal well-known SIDs                                               //
'//                                                                         //
'//     Null SID                     S-1-0-0                                //
'//     World                        S-1-1-0                                //
'//     Local                        S-1-2-0                                //
'//     Creator Owner ID             S-1-3-0                                //
'//     Creator Group ID             S-1-3-1                                //
'//     Creator Owner Server ID      S-1-3-2                                //
'//     Creator Group Server ID      S-1-3-3                                //
'//                                                                         //
'//     (Non-unique IDs)             S-1-4                                  //
'//                                                                         //
'/////////////////////////////////////////////////////////////////////////////

'#define SECURITY_NULL_SID_AUTHORITY         {0,0,0,0,0,0}
'#define SECURITY_WORLD_SID_AUTHORITY        {0,0,0,0,0,1}
'#define SECURITY_LOCAL_SID_AUTHORITY        {0,0,0,0,0,2}
'#define SECURITY_CREATOR_SID_AUTHORITY      {0,0,0,0,0,3}
'#define SECURITY_NON_UNIQUE_AUTHORITY       {0,0,0,0,0,4}
'#define SECURITY_RESOURCE_MANAGER_AUTHORITY {0,0,0,0,0,9}

$SECURITY_NULL_SID_AUTHORITY         = CHR$(0,0,0,0,0,0)
$SECURITY_WORLD_SID_AUTHORITY        = CHR$(0,0,0,0,0,1)
$SECURITY_LOCAL_SID_AUTHORITY        = CHR$(0,0,0,0,0,2)
$SECURITY_CREATOR_SID_AUTHORITY      = CHR$(0,0,0,0,0,3)
$SECURITY_NON_UNIQUE_AUTHORITY       = CHR$(0,0,0,0,0,4)
$SECURITY_RESOURCE_MANAGER_AUTHORITY = CHR$(0,0,0,0,0,9)

%SECURITY_NULL_RID                 = &H00000000???
%SECURITY_WORLD_RID                = &H00000000???
%SECURITY_LOCAL_RID                = &H00000000???
%SECURITY_LOCAL_LOGON_RID          = &H00000001???

%SECURITY_CREATOR_OWNER_RID        = &H00000000???
%SECURITY_CREATOR_GROUP_RID        = &H00000001???

%SECURITY_CREATOR_OWNER_SERVER_RID = &H00000002???
%SECURITY_CREATOR_GROUP_SERVER_RID = &H00000003???

%SECURITY_CREATOR_OWNER_RIGHTS_RID = &H00000004???


'///////////////////////////////////////////////////////////////////////////////
'//                                                                           //
'// NT well-known SIDs                                                        //
'//                                                                           //
'//     NT Authority            S-1-5                                         //
'//     Dialup                  S-1-5-1                                       //
'//                                                                           //
'//     Network                 S-1-5-2                                       //
'//     Batch                   S-1-5-3                                       //
'//     Interactive             S-1-5-4                                       //
'//     (Logon IDs)             S-1-5-5-X-Y                                   //
'//     Service                 S-1-5-6                                       //
'//     AnonymousLogon          S-1-5-7       (aka null logon session)        //
'//     Proxy                   S-1-5-8                                       //
'//     Enterprise DC (EDC)     S-1-5-9       (aka domain controller account) //
'//     Self                    S-1-5-10      (self RID)                      //
'//     Authenticated User      S-1-5-11      (Authenticated user somewhere)  //
'//     Restricted Code         S-1-5-12      (Running restricted code)       //
'//     Terminal Server         S-1-5-13      (Running on Terminal Server)    //
'//     Remote Logon            S-1-5-14      (Remote Interactive Logon)      //
'//     This Organization       S-1-5-15                                      //
'//                                                                           //
'//     Local System            S-1-5-18                                      //
'//     Local Service           S-1-5-19                                      //
'//     Network Service         S-1-5-20                                      //
'//                                                                           //
'//     (NT non-unique IDs)     S-1-5-0x15-... (NT Domain Sids)               //
'//                                                                           //
'//     (Built-in domain)       S-1-5-0x20                                    //
'//                                                                           //
'//     (Security Package IDs)  S-1-5-0x40                                    //
'//     NTLM Authentication     S-1-5-0x40-10                                 //
'//     SChannel Authentication S-1-5-0x40-14                                 //
'//     Digest Authentication   S-1-5-0x40-21                                 //
'//                                                                           //
'//     Other Organization      S-1-5-1000    (>=1000 can not be filtered)    //
'//                                                                           //
'//                                                                           //
'// NOTE: the relative identifier values (RIDs) determine which security      //
'//       boundaries the SID is allowed to cross.  Before adding new RIDs,    //
'//       a determination needs to be made regarding which range they should  //
'//       be added to in order to ensure proper "SID filtering"               //
'//                                                                           //
'///////////////////////////////////////////////////////////////////////////////


'#define SECURITY_NT_AUTHORITY           {0,0,0,0,0,5}   // ntifs
$SECURITY_NT_AUTHORITY                        = CHR$(0,0,0,0,0,5)

%SECURITY_DIALUP_RID                          = &H00000001???
%SECURITY_NETWORK_RID                         = &H00000002???
%SECURITY_BATCH_RID                           = &H00000003???
%SECURITY_INTERACTIVE_RID                     = &H00000004???
%SECURITY_LOGON_IDS_RID                       = &H00000005???
%SECURITY_LOGON_IDS_RID_COUNT                 = 3???
%SECURITY_SERVICE_RID                         = &H00000006???
%SECURITY_ANONYMOUS_LOGON_RID                 = &H00000007???
%SECURITY_PROXY_RID                           = &H00000008???
%SECURITY_ENTERPRISE_CONTROLLERS_RID          = &H00000009???
%SECURITY_SERVER_LOGON_RID                    = %SECURITY_ENTERPRISE_CONTROLLERS_RID
%SECURITY_PRINCIPAL_SELF_RID                  = &H0000000A???
%SECURITY_AUTHENTICATED_USER_RID              = &H0000000B???
%SECURITY_RESTRICTED_CODE_RID                 = &H0000000C???
%SECURITY_TERMINAL_SERVER_RID                 = &H0000000D???
%SECURITY_REMOTE_LOGON_RID                    = &H0000000E???
%SECURITY_THIS_ORGANIZATION_RID               = &H0000000F???
%SECURITY_IUSER_RID                           = &H00000011???
%SECURITY_LOCAL_SYSTEM_RID                    = &H00000012???
%SECURITY_LOCAL_SERVICE_RID                   = &H00000013???
%SECURITY_NETWORK_SERVICE_RID                 = &H00000014???

%SECURITY_NT_NON_UNIQUE                       = &H00000015???
%SECURITY_NT_NON_UNIQUE_SUB_AUTH_COUNT        = 3???

%SECURITY_ENTERPRISE_READONLY_CONTROLLERS_RID = &H00000016???

%SECURITY_BUILTIN_DOMAIN_RID                  = &H00000020???
%SECURITY_WRITE_RESTRICTED_CODE_RID           = &H00000021???


%SECURITY_PACKAGE_BASE_RID                    = &H00000040???
%SECURITY_PACKAGE_RID_COUNT                   = 2???
%SECURITY_PACKAGE_NTLM_RID                    = &H0000000A???
%SECURITY_PACKAGE_SCHANNEL_RID                = &H0000000E???
%SECURITY_PACKAGE_DIGEST_RID                  = &H00000015???

%SECURITY_CRED_TYPE_BASE_RID                  = &H00000041???
%SECURITY_CRED_TYPE_RID_COUNT                 = &H2???
%SECURITY_CRED_TYPE_THIS_ORG_CERT_RID         = &H00000001???

%SECURITY_MIN_BASE_RID		                   = &H00000050???

%SECURITY_SERVICE_ID_BASE_RID                 = &H00000050???
%SECURITY_SERVICE_ID_RID_COUNT                = 6???

%SECURITY_RESERVED_ID_BASE_RID                = &H00000051???

%SECURITY_APPPOOL_ID_BASE_RID                 = &H00000052???
%SECURITY_APPPOOL_ID_RID_COUNT                = 6???

%SECURITY_VIRTUALSERVER_ID_BASE_RID           = &H00000053???
%SECURITY_VIRTUALSERVER_ID_RID_COUNT          = 6???

%SECURITY_USERMODEDRIVERHOST_ID_BASE_RID      = &H00000054???
%SECURITY_USERMODEDRIVERHOST_ID_RID_COUNT     = 6???

%SECURITY_CLOUD_INFRASTRUCTURE_SERVICES_ID_BASE_RID  = &H00000055???
%SECURITY_CLOUD_INFRASTRUCTURE_SERVICES_ID_RID_COUNT = 6???

%SECURITY_WMIHOST_ID_BASE_RID                 = &H00000056???
%SECURITY_WMIHOST_ID_RID_COUNT                = 6???

%SECURITY_TASK_ID_BASE_RID                    = &H00000057???

%SECURITY_NFS_ID_BASE_RID                     = &H00000058???

%SECURITY_COM_ID_BASE_RID                     = &H00000059???

%SECURITY_VIRTUALACCOUNT_ID_RID_COUNT         = 6???

%SECURITY_MAX_BASE_RID		                   = &H0000006F???

%SECURITY_MAX_ALWAYS_FILTERED                 = &H000003E7???
%SECURITY_MIN_NEVER_FILTERED                  = &H000003E8???

%SECURITY_OTHER_ORGANIZATION_RID              = &H000003E8???

'//
'//Service SID type RIDs are in the range 0x50- 0x6F.  Therefore, we are giving  the next available RID to Windows Mobile team.
'//
%SECURITY_WINDOWSMOBILE_ID_BASE_RID           = &H00000070???

'/////////////////////////////////////////////////////////////////////////////
'//                                                                         //
'// well-known domain relative sub-authority values (RIDs)...               //
'//                                                                         //
'/////////////////////////////////////////////////////////////////////////////

%DOMAIN_GROUP_RID_ENTERPRISE_READONLY_DOMAIN_CONTROLLERS = &H000001F2???

%FOREST_USER_RID_MAX                             = &H000001F3???

'// Well-known users ...

%DOMAIN_USER_RID_ADMIN                           = &H000001F4???
%DOMAIN_USER_RID_GUEST                           = &H000001F5???
%DOMAIN_USER_RID_KRBTGT                          = &H000001F6???

%DOMAIN_USER_RID_MAX                             = &H000003E7???


'// well-known groups ...

%DOMAIN_GROUP_RID_ADMINS                         = &H00000200???
%DOMAIN_GROUP_RID_USERS                          = &H00000201???
%DOMAIN_GROUP_RID_GUESTS                         = &H00000202???
%DOMAIN_GROUP_RID_COMPUTERS                      = &H00000203???
%DOMAIN_GROUP_RID_CONTROLLERS                    = &H00000204???
%DOMAIN_GROUP_RID_CERT_ADMINS                    = &H00000205???
%DOMAIN_GROUP_RID_SCHEMA_ADMINS                  = &H00000206???
%DOMAIN_GROUP_RID_ENTERPRISE_ADMINS              = &H00000207???
%DOMAIN_GROUP_RID_POLICY_ADMINS                  = &H00000208???
%DOMAIN_GROUP_RID_READONLY_CONTROLLERS           = &H00000209???

'// well-known aliases ...

%DOMAIN_ALIAS_RID_ADMINS                         = &H00000220???
%DOMAIN_ALIAS_RID_USERS                          = &H00000221???
%DOMAIN_ALIAS_RID_GUESTS                         = &H00000222???
%DOMAIN_ALIAS_RID_POWER_USERS                    = &H00000223???

%DOMAIN_ALIAS_RID_ACCOUNT_OPS                    = &H00000224???
%DOMAIN_ALIAS_RID_SYSTEM_OPS                     = &H00000225???
%DOMAIN_ALIAS_RID_PRINT_OPS                      = &H00000226???
%DOMAIN_ALIAS_RID_BACKUP_OPS                     = &H00000227???

%DOMAIN_ALIAS_RID_REPLICATOR                     = &H00000228???
%DOMAIN_ALIAS_RID_RAS_SERVERS                    = &H00000229???
%DOMAIN_ALIAS_RID_PREW2KCOMPACCESS               = &H0000022A???
%DOMAIN_ALIAS_RID_REMOTE_DESKTOP_USERS           = &H0000022B???
%DOMAIN_ALIAS_RID_NETWORK_CONFIGURATION_OPS      = &H0000022C???
%DOMAIN_ALIAS_RID_INCOMING_FOREST_TRUST_BUILDERS = &H0000022D???

%DOMAIN_ALIAS_RID_MONITORING_USERS               = &H0000022E???
%DOMAIN_ALIAS_RID_LOGGING_USERS                  = &H0000022F???
%DOMAIN_ALIAS_RID_AUTHORIZATIONACCESS            = &H00000230???
%DOMAIN_ALIAS_RID_TS_LICENSE_SERVERS             = &H00000231???
%DOMAIN_ALIAS_RID_DCOM_USERS                     = &H00000232???
%DOMAIN_ALIAS_RID_IUSERS                         = &H00000238???
%DOMAIN_ALIAS_RID_CRYPTO_OPERATORS               = &H00000239???
%DOMAIN_ALIAS_RID_CACHEABLE_PRINCIPALS_GROUP     = &H0000023B???
%DOMAIN_ALIAS_RID_NON_CACHEABLE_PRINCIPALS_GROUP = &H0000023C???
%DOMAIN_ALIAS_RID_EVENT_LOG_READERS_GROUP        = &H0000023D???
%DOMAIN_ALIAS_RID_CERTSVC_DCOM_ACCESS_GROUP      = &H0000023E???

'#define SECURITY_MANDATORY_LABEL_AUTHORITY          {0,0,0,0,0,16}
$SECURITY_MANDATORY_LABEL_AUTHORITY          = CHR$(0,0,0,0,0,16)

%SECURITY_MANDATORY_UNTRUSTED_RID            = &H00000000???
%SECURITY_MANDATORY_LOW_RID                  = &H00001000???
%SECURITY_MANDATORY_MEDIUM_RID               = &H00002000???
%SECURITY_MANDATORY_MEDIUM_PLUS_RID          = %SECURITY_MANDATORY_MEDIUM_RID + &H100
%SECURITY_MANDATORY_HIGH_RID                 = &H00003000???
%SECURITY_MANDATORY_SYSTEM_RID               = &H00004000???
%SECURITY_MANDATORY_PROTECTED_PROCESS_RID    = &H00005000???

'//
'// SECURITY_MANDATORY_MAXIMUM_USER_RID is the highest RID that
'// can be set by a usermode caller.
'//

%SECURITY_MANDATORY_MAXIMUM_USER_RID   = %SECURITY_MANDATORY_SYSTEM_RID

'#define MANDATORY_LEVEL_TO_MANDATORY_RID(IL) (IL * 0x1000)
MACRO MANDATORY_LEVEL_TO_MANDATORY_RID(IL) = (IL * &H1000)

' WELL_KNOWN_SID_TYPE enum
%WinNullSid                                  = 0
%WinWorldSid                                 = 1
%WinLocalSid                                 = 2
%WinCreatorOwnerSid                          = 3
%WinCreatorGroupSid                          = 4
%WinCreatorOwnerServerSid                    = 5
%WinCreatorGroupServerSid                    = 6
%WinNtAuthoritySid                           = 7
%WinDialupSid                                = 8
%WinNetworkSid                               = 9
%WinBatchSid                                 = 10
%WinInteractiveSid                           = 11
%WinServiceSid                               = 12
%WinAnonymousSid                             = 13
%WinProxySid                                 = 14
%WinEnterpriseControllersSid                 = 15
%WinSelfSid                                  = 16
%WinAuthenticatedUserSid                     = 17
%WinRestrictedCodeSid                        = 18
%WinTerminalServerSid                        = 19
%WinRemoteLogonIdSid                         = 20
%WinLogonIdsSid                              = 21
%WinLocalSystemSid                           = 22
%WinLocalServiceSid                          = 23
%WinNetworkServiceSid                        = 24
%WinBuiltinDomainSid                         = 25
%WinBuiltinAdministratorsSid                 = 26
%WinBuiltinUsersSid                          = 27
%WinBuiltinGuestsSid                         = 28
%WinBuiltinPowerUsersSid                     = 29
%WinBuiltinAccountOperatorsSid               = 30
%WinBuiltinSystemOperatorsSid                = 31
%WinBuiltinPrintOperatorsSid                 = 32
%WinBuiltinBackupOperatorsSid                = 33
%WinBuiltinReplicatorSid                     = 34
%WinBuiltinPreWindows2000CompatibleAccessSid = 35
%WinBuiltinRemoteDesktopUsersSid             = 36
%WinBuiltinNetworkConfigurationOperatorsSid  = 37
%WinAccountAdministratorSid                  = 38
%WinAccountGuestSid                          = 39
%WinAccountKrbtgtSid                         = 40
%WinAccountDomainAdminsSid                   = 41
%WinAccountDomainUsersSid                    = 42
%WinAccountDomainGuestsSid                   = 43
%WinAccountComputersSid                      = 44
%WinAccountControllersSid                    = 45
%WinAccountCertAdminsSid                     = 46
%WinAccountSchemaAdminsSid                   = 47
%WinAccountEnterpriseAdminsSid               = 48
%WinAccountPolicyAdminsSid                   = 49
%WinAccountRasAndIasServersSid               = 50
%WinNTLMAuthenticationSid                    = 51
%WinDigestAuthenticationSid                  = 52
%WinSChannelAuthenticationSid                = 53
%WinThisOrganizationSid                      = 54
%WinOtherOrganizationSid                     = 55
%WinBuiltinIncomingForestTrustBuildersSid    = 56
%WinBuiltinPerfMonitoringUsersSid            = 57
%WinBuiltinPerfLoggingUsersSid               = 58
%WinBuiltinAuthorizationAccessSid            = 59
%WinBuiltinTerminalServerLicenseServersSid   = 60
%WinBuiltinDCOMUsersSid                      = 61
%WinBuiltinIUsersSid                         = 62
%WinIUserSid                                 = 63
%WinBuiltinCryptoOperatorsSid                = 64
%WinUntrustedLabelSid                        = 65
%WinLowLabelSid                              = 66
%WinMediumLabelSid                           = 67
%WinHighLabelSid                             = 68
%WinSystemLabelSid                           = 69
%WinWriteRestrictedCodeSid                   = 70
%WinCreatorOwnerRightsSid                    = 71
%WinCacheablePrincipalsGroupSid              = 72
%WinNonCacheablePrincipalsGroupSid           = 73
%WinEnterpriseReadonlyControllersSid         = 74
%WinAccountReadonlyControllersSid            = 75
%WinBuiltinEventLogReadersGroup              = 76
%WinNewEnterpriseReadonlyControllersSid      = 77
%WinBuiltinCertSvcDComAccessGroup            = 78
%WinMediumPlusLabelSid                       = 79
%WinLocalLogonSid                            = 80
%WinConsoleLogonSid                          = 81
%WinThisOrganizationCertificateSid           = 82

'//
'// Allocate the System Luid.  The first 1000 LUIDs are reserved.
'// Use #999 here (0x3E7 = 999)
'//

'#define SYSTEM_LUID                     { 0x3E7, 0x0 }
'#define ANONYMOUS_LOGON_LUID            { 0x3e6, 0x0 }
'#define LOCALSERVICE_LUID               { 0x3e5, 0x0 }
'#define NETWORKSERVICE_LUID             { 0x3e4, 0x0 }

' // To assign the values, dim a variable as LUID and use TYPE SET,
' // e.g. DIM v AS LUID : TYPE SET v = SYSTEM_LUID
'MACRO SYSTEM_LUID                     = MKDWD$(&H3E7) & MKL$(&H0)
'MACRO ANONYMOUS_LOGON_LUID            = MKDWD$(&H3e6) & MKL$(&H0)
'MACRO LOCALSERVICE_LUID               = MKDWD$(&H3e5) & MKL$(&H0)
'MACRO NETWORKSERVICE_LUID             = MKDWD$(&H3e4) & MKL$(&H0)

' // The LUID type has been changed by QUADS. Therefore, you can now assign the values directly.
%SYSTEM_LUID            = &H3e7  '{ &H3e7, &H0 }
%ANONYMOUS_LOGON_LUID   = &H3e6  '{ &H3e6, &H0 }
%LOCALSERVICE_LUID      = &H3e5  '{ &H3e5, &H0 }
%NETWORKSERVICE_LUID    = &H3e4  '{ &H3e4, &H0 }
%IUSER_LUID             = &H3e3  '{ &H3e3, &H0 }

'////////////////////////////////////////////////////////////////////////
'//                                                                    //
'//                          User and Group related SID attributes     //
'//                                                                    //
'////////////////////////////////////////////////////////////////////////

'//
'// Group attributes
'//

%SE_GROUP_MANDATORY          = &H00000001???
%SE_GROUP_ENABLED_BY_DEFAULT = &H00000002???
%SE_GROUP_ENABLED            = &H00000004???
%SE_GROUP_OWNER              = &H00000008???
%SE_GROUP_USE_FOR_DENY_ONLY  = &H00000010???
%SE_GROUP_INTEGRITY          = &H00000020???
%SE_GROUP_INTEGRITY_ENABLED  = &H00000040???
%SE_GROUP_LOGON_ID           = &HC0000000???
%SE_GROUP_RESOURCE           = &H20000000???

%SE_GROUP_VALID_ATTRIBUTES   = %SE_GROUP_MANDATORY          OR _
                               %SE_GROUP_ENABLED_BY_DEFAULT OR _
                               %SE_GROUP_ENABLED            OR _
                               %SE_GROUP_OWNER              OR _
                               %SE_GROUP_USE_FOR_DENY_ONLY  OR _
                               %SE_GROUP_LOGON_ID           OR _
                               %SE_GROUP_RESOURCE           OR _
                               %SE_GROUP_INTEGRITY          OR _
                               %SE_GROUP_INTEGRITY_ENABLED

'//
'// User attributes
'//

'// (None yet defined.)

'////////////////////////////////////////////////////////////////////////
'//                                                                    //
'//                         ACL  and  ACE                              //
'//                                                                    //
'////////////////////////////////////////////////////////////////////////

'//
'//  Define an ACL and the ACE format.  The structure of an ACL header
'//  followed by one or more ACEs.  Pictorally the structure of an ACL header
'//  is as follows:
'//
'//       3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1 1 1
'//       1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0
'//      +-------------------------------+---------------+---------------+
'//      |            AclSize            |      Sbz1     |  AclRevision  |
'//      +-------------------------------+---------------+---------------+
'//      |              Sbz2             |           AceCount            |
'//      +-------------------------------+-------------------------------+
'//
'//  The current AclRevision is defined to be ACL_REVISION.
'//
'//  AclSize is the size, in bytes, allocated for the ACL.  This includes
'//  the ACL header, ACES, and remaining free space in the buffer.
'//
'//  AceCount is the number of ACES in the ACL.
'//

'// This is the *current* ACL revision

%ACL_REVISION     = 2
%ACL_REVISION_DS  = 4

'// This is the history of ACL revisions.  Add a new one whenever
'// ACL_REVISION is updated

%ACL_REVISION1    = 1
%ACL_REVISION2    = 2
%MIN_ACL_REVISION = %ACL_REVISION2
%ACL_REVISION3    = 3
%ACL_REVISION4    = 4
%MAX_ACL_REVISION = %ACL_REVISION4

#IF NOT %DEF(%ACL_DEFINED)
%ACL_DEFINED = 1
' // Size = 8 bytes
TYPE ACL BYTE
   AclRevision AS BYTE
   Sbz1        AS BYTE
   AclSize     AS WORD
   AceCount    AS WORD
   Sbz2        AS WORD
END TYPE
#ENDIF

'//
'//  The structure of an ACE is a common ace header followed by ace type
'//  specific data.  Pictorally the structure of the common ace header is
'//  as follows:
'//
'//       3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1 1 1
'//       1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0
'//      +---------------+-------+-------+---------------+---------------+
'//      |            AceSize            |    AceFlags   |     AceType   |
'//      +---------------+-------+-------+---------------+---------------+
'//
'//  AceType denotes the type of the ace, there are some predefined ace
'//  types
'//
'//  AceSize is the size, in bytes, of ace.
'//
'//  AceFlags are the Ace flags for audit and inheritance, defined shortly.

' // Size = 4 bytes
TYPE ACE_HEADER BYTE
   AceType  AS BYTE
   AceFlags AS BYTE
   AceSize  AS WORD
END TYPE


'//
'//  The following are the predefined ace types that go into the AceType
'//  field of an Ace header.
'//

%ACCESS_MIN_MS_ACE_TYPE                  = &H0?
%ACCESS_ALLOWED_ACE_TYPE                 = &H0?
%ACCESS_DENIED_ACE_TYPE                  = &H1?
%SYSTEM_AUDIT_ACE_TYPE                   = &H2?
%SYSTEM_ALARM_ACE_TYPE                   = &H3?
%ACCESS_MAX_MS_V2_ACE_TYPE               = &H3?

%ACCESS_ALLOWED_COMPOUND_ACE_TYPE        = &H4?
%ACCESS_MAX_MS_V3_ACE_TYPE               = &H4?

%ACCESS_MIN_MS_OBJECT_ACE_TYPE           = &H5?
%ACCESS_ALLOWED_OBJECT_ACE_TYPE          = &H5?
%ACCESS_DENIED_OBJECT_ACE_TYPE           = &H6?
%SYSTEM_AUDIT_OBJECT_ACE_TYPE            = &H7?
%SYSTEM_ALARM_OBJECT_ACE_TYPE            = &H8?
%ACCESS_MAX_MS_OBJECT_ACE_TYPE           = &H8?

%ACCESS_MAX_MS_V4_ACE_TYPE               = &H8?
%ACCESS_MAX_MS_ACE_TYPE                  = &H8?

%ACCESS_ALLOWED_CALLBACK_ACE_TYPE        = &H9?
%ACCESS_DENIED_CALLBACK_ACE_TYPE         = &HA?
%ACCESS_ALLOWED_CALLBACK_OBJECT_ACE_TYPE = &HB?
%ACCESS_DENIED_CALLBACK_OBJECT_ACE_TYPE  = &HC?
%SYSTEM_AUDIT_CALLBACK_ACE_TYPE          = &HD?
%SYSTEM_ALARM_CALLBACK_ACE_TYPE          = &HE?
%SYSTEM_AUDIT_CALLBACK_OBJECT_ACE_TYPE   = &HF?
%SYSTEM_ALARM_CALLBACK_OBJECT_ACE_TYPE   = &H10?

%SYSTEM_MANDATORY_LABEL_ACE_TYPE         = &H11?
%ACCESS_MAX_MS_V5_ACE_TYPE               = &H11?

'//
'//  The following are the inherit flags that go into the AceFlags field
'//  of an Ace header.
'//

%OBJECT_INHERIT_ACE       = &H1???
%CONTAINER_INHERIT_ACE    = &H2???
%NO_PROPAGATE_INHERIT_ACE = &H4???
%INHERIT_ONLY_ACE         = &H8???
%INHERITED_ACE            = &H10???
%VALID_INHERIT_FLAGS      = &H1F???

'//  The following are the currently defined ACE flags that go into the
'//  AceFlags field of an ACE header.  Each ACE type has its own set of
'//  AceFlags.
'//
'//  SUCCESSFUL_ACCESS_ACE_FLAG - used only with system audit and alarm ACE
'//  types to indicate that a message is generated for successful accesses.
'//
'//  FAILED_ACCESS_ACE_FLAG - used only with system audit and alarm ACE types
'//  to indicate that a message is generated for failed accesses.
'//

'//
'//  SYSTEM_AUDIT and SYSTEM_ALARM AceFlags
'//
'//  These control the signaling of audit and alarms for success or failure.
'//

%SUCCESSFUL_ACCESS_ACE_FLAG = &H40???
%FAILED_ACCESS_ACE_FLAG     = &H80???

'//
'//  We'll define the structure of the predefined ACE types.  Pictorally
'//  the structure of the predefined ACE's is as follows:
'//
'//       3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1 1 1
'//       1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0
'//      +---------------+-------+-------+---------------+---------------+
'//      |    AceFlags   | Resd  |Inherit|    AceSize    |     AceType   |
'//      +---------------+-------+-------+---------------+---------------+
'//      |                              Mask                             |
'//      +---------------------------------------------------------------+
'//      |                                                               |
'//      +                                                               +
'//      |                                                               |
'//      +                              Sid                              +
'//      |                                                               |
'//      +                                                               +
'//      |                                                               |
'//      +---------------------------------------------------------------+
'//
'//  Mask is the access mask associated with the ACE.  This is either the
'//  access allowed, access denied, audit, or alarm mask.
'//
'//  Sid is the Sid associated with the ACE.
'//

'//  The following are the four predefined ACE types.

'//  Examine the AceType field in the Header to determine
'//  which structure is appropriate to use for casting.


' // Size = 12 bytes
TYPE ACCESS_ALLOWED_ACE BYTE
   Header   AS ACE_HEADER    ' ACE_HEADER
   Mask     AS ACCESS_MASK   ' ACCESS_MASK
   SidStart AS DWORD         ' DWORD
END TYPE

' // Size = 12 bytes
TYPE ACCESS_DENIED_ACE BYTE
   Header   AS ACE_HEADER    ' ACE_HEADER
   Mask     AS ACCESS_MASK   ' ACCESS_MASK
   SidStart AS DWORD         ' DWORD
END TYPE

' // Size = 12 bytes
TYPE SYSTEM_AUDIT_ACE BYTE
   Header   AS ACE_HEADER    ' ACE_HEADER
   Mask     AS ACCESS_MASK   ' ACCESS_MASK
   SidStart AS DWORD         ' DWORD
END TYPE

' // Size = 12 bytes
TYPE SYSTEM_ALARM_ACE BYTE
   Header   AS ACE_HEADER    ' ACE_HEADER
   Mask     AS ACCESS_MASK   ' ACCESS_MASK
   SidStart AS DWORD         ' DWORD
END TYPE

' // Size = 12 bytes
TYPE SYSTEM_MANDATORY_LABEL_ACE BYTE
   Header   AS ACE_HEADER    ' ACE_HEADER
   Mask     AS ACCESS_MASK   ' ACCESS_MASK
   SidStart AS DWORD         ' DWORD
END TYPE

%SYSTEM_MANDATORY_LABEL_NO_WRITE_UP         = &H1
%SYSTEM_MANDATORY_LABEL_NO_READ_UP          = &H2
%SYSTEM_MANDATORY_LABEL_NO_EXECUTE_UP       = &H4

%SYSTEM_MANDATORY_LABEL_VALID_MASK = %SYSTEM_MANDATORY_LABEL_NO_WRITE_UP   OR _
                                     %SYSTEM_MANDATORY_LABEL_NO_READ_UP    OR _
                                     %SYSTEM_MANDATORY_LABEL_NO_EXECUTE_UP

' // Size = 48 bytes
TYPE ACCESS_ALLOWED_OBJECT_ACE BYTE
   Header              AS ACE_HEADER    ' ACE_HEADER
   Mask                AS ACCESS_MASK   ' ACCESS_MASK
   Flags               AS DWORD         ' DWORD
   ObjectType          AS GUID          ' GUID
   InheritedObjectType AS GUID          ' GUID
   SidStart            AS DWORD         ' DWORD
END TYPE

' // Size = 48 bytes
TYPE ACCESS_DENIED_OBJECT_ACE BYTE
   Header              AS ACE_HEADER    ' ACE_HEADER
   Mask                AS ACCESS_MASK   ' ACCESS_MASK
   Flags               AS DWORD         ' DWORD
   ObjectType          AS GUID          ' GUID
   InheritedObjectType AS GUID          ' GUID
   SidStart            AS DWORD         ' DWORD
END TYPE

' // Size = 48 bytes
TYPE SYSTEM_AUDIT_OBJECT_ACE BYTE
   Header              AS ACE_HEADER    ' ACE_HEADER
   Mask                AS ACCESS_MASK   ' ACCESS_MASK
   Flags               AS DWORD         ' DWORD
   ObjectType          AS GUID          ' GUID
   InheritedObjectType AS GUID          ' GUID
   SidStart            AS DWORD         ' DWORD
END TYPE

' // Size = 48 bytes
TYPE SYSTEM_ALARM_OBJECT_ACE BYTE
   Header              AS ACE_HEADER    ' ACE_HEADER
   Mask                AS ACCESS_MASK   ' ACCESS_MASK
   Flags               AS DWORD         ' DWORD
   ObjectType          AS GUID          ' GUID
   InheritedObjectType AS GUID          ' GUID
   SidStart            AS DWORD         ' DWORD
END TYPE

'//
'// Callback ace support in post Win2000.
'// Resource managers can put their own data after Sidstart + Length of the sid
'//

' // Size = 12 bytes
TYPE ACCESS_ALLOWED_CALLBACK_ACE BYTE
   Header   AS ACE_HEADER    ' ACE_HEADER
   Mask     AS ACCESS_MASK   ' ACCESS_MASK
   SidStart AS DWORD         ' DWORD
   ' // Opaque resouce manager specific data
END TYPE

' // Size = 12 bytes
TYPE ACCESS_DENIED_CALLBACK_ACE BYTE
   Header   AS ACE_HEADER    ' ACE_HEADER
   Mask     AS ACCESS_MASK   ' ACCESS_MASK
   SidStart AS DWORD         ' DWORD
   ' // Opaque resouce manager specific data
END TYPE

' // Size = 12 bytes
TYPE SYSTEM_AUDIT_CALLBACK_ACE BYTE
   Header   AS ACE_HEADER    ' ACE_HEADER
   Mask     AS ACCESS_MASK   ' ACCESS_MASK
   SidStart AS DWORD         ' DWORD
   ' // Opaque resouce manager specific data
END TYPE

' // Size = 12 bytes
TYPE SYSTEM_ALARM_CALLBACK_ACE BYTE
   Header   AS ACE_HEADER    ' ACE_HEADER
   Mask     AS ACCESS_MASK   ' ACCESS_MASK
   SidStart AS DWORD         ' DWORD
   ' // Opaque resouce manager specific data
END TYPE

' // Size = 48 bytes
TYPE ACCESS_ALLOWED_CALLBACK_OBJECT_ACE BYTE
   Header              AS ACE_HEADER    ' ACE_HEADER
   Mask                AS ACCESS_MASK   ' ACCESS_MASK
   Flags               AS DWORD         ' DWORD
   ObjectType          AS GUID          ' GUID
   InheritedObjectType AS GUID          ' GUID
   SidStart            AS DWORD         ' DWORD
   ' // Opaque resouce manager specific data
END TYPE

' // Size = 48 bytes
TYPE ACCESS_DENIED_CALLBACK_OBJECT_ACE BYTE
   Header              AS ACE_HEADER    ' ACE_HEADER
   Mask                AS ACCESS_MASK   ' ACCESS_MASK
   Flags               AS DWORD         ' DWORD
   ObjectType          AS GUID          ' GUID
   InheritedObjectType AS GUID          ' GUID
   SidStart            AS DWORD         ' DWORD
   ' // Opaque resouce manager specific data
END TYPE

' // Size = 48 bytes
TYPE SYSTEM_AUDIT_CALLBACK_OBJECT_ACE BYTE
   Header              AS ACE_HEADER    ' ACE_HEADER
   Mask                AS ACCESS_MASK   ' ACCESS_MASK
   Flags               AS DWORD         ' DWORD
   ObjectType          AS GUID          ' GUID
   InheritedObjectType AS GUID          ' GUID
   SidStart            AS DWORD         ' DWORD
   ' // Opaque resouce manager specific data
END TYPE

' // Size = 48 bytes
TYPE SYSTEM_ALARM_CALLBACK_OBJECT_ACE BYTE
   Header              AS ACE_HEADER    ' ACE_HEADER
   Mask                AS ACCESS_MASK   ' ACCESS_MASK
   Flags               AS DWORD         ' DWORD
   ObjectType          AS GUID          ' GUID
   InheritedObjectType AS GUID          ' GUID
   SidStart            AS DWORD         ' DWORD
   ' // Opaque resouce manager specific data
END TYPE

'//
'// Currently define Flags for "OBJECT" ACE types.
'//

%ACE_OBJECT_TYPE_PRESENT           = &H1???
%ACE_INHERITED_OBJECT_TYPE_PRESENT = &H2???

'//
'//  The following declarations are used for setting and querying information
'//  about and ACL.  First are the various information classes available to
'//  the user.
'//

' ACL_INFORMATION_CLASS enum
%AclRevisionInformation = 1
%AclSizeInformation     = 2

'//
'//  This record is returned/sent if the user is requesting/setting the
'//  AclRevisionInformation
'//

' // Size = 4 bytes
TYPE ACL_REVISION_INFORMATION DWORD
   AclRevision AS DWORD
END TYPE

'//
'//  This record is returned if the user is requesting AclSizeInformation
'//

' // Size = 12 bytes
TYPE ACL_SIZE_INFORMATION DWORD
   AceCount      AS DWORD
   AclBytesInUse AS DWORD
   AclBytesFree  AS DWORD
END TYPE

'////////////////////////////////////////////////////////////////////////
'//                                                                    //
'//                             SECURITY_DESCRIPTOR                    //
'//                                                                    //
'////////////////////////////////////////////////////////////////////////
'//
'//  Define the Security Descriptor and related data types.
'//  This is an opaque data structure.
'//

'//
'// Current security descriptor revision value
'//

%SECURITY_DESCRIPTOR_REVISION   = 1
%SECURITY_DESCRIPTOR_REVISION1  = 1

'#define SECURITY_DESCRIPTOR_MIN_LENGTH   (sizeof(SECURITY_DESCRIPTOR))

%SECURITY_DESCRIPTOR_MIN_LENGTH = 20  ' SIZEOF(SECURITY_DESCRIPTOR)

'typedef WORD   SECURITY_DESCRIPTOR_CONTROL, *PSECURITY_DESCRIPTOR_CONTROL;

%SE_OWNER_DEFAULTED       = &H0001???
%SE_GROUP_DEFAULTED       = &H0002???
%SE_DACL_PRESENT          = &H0004???
%SE_DACL_DEFAULTED        = &H0008???
%SE_SACL_PRESENT          = &H0010???
%SE_SACL_DEFAULTED        = &H0020???
%SE_DACL_AUTO_INHERIT_REQ = &H0100???
%SE_SACL_AUTO_INHERIT_REQ = &H0200???
%SE_DACL_AUTO_INHERITED   = &H0400???
%SE_SACL_AUTO_INHERITED   = &H0800???
%SE_DACL_PROTECTED        = &H1000???
%SE_SACL_PROTECTED        = &H2000???
%SE_RM_CONTROL_VALID      = &H4000???
%SE_SELF_RELATIVE         = &H8000???

'//
'//  Where:
'//
'//      SE_OWNER_DEFAULTED - This boolean flag, when set, indicates that the
'//          SID pointed to by the Owner field was provided by a
'//          defaulting mechanism rather than explicitly provided by the
'//          original provider of the security descriptor.  This may
'//          affect the treatment of the SID with respect to inheritence
'//          of an owner.
'//
'//      SE_GROUP_DEFAULTED - This boolean flag, when set, indicates that the
'//          SID in the Group field was provided by a defaulting mechanism
'//          rather than explicitly provided by the original provider of
'//          the security descriptor.  This may affect the treatment of
'//          the SID with respect to inheritence of a primary group.
'//
'//      SE_DACL_PRESENT - This boolean flag, when set, indicates that the
'//          security descriptor contains a discretionary ACL.  If this
'//          flag is set and the Dacl field of the SECURITY_DESCRIPTOR is
'//          null, then a null ACL is explicitly being specified.
'//
'//      SE_DACL_DEFAULTED - This boolean flag, when set, indicates that the
'//          ACL pointed to by the Dacl field was provided by a defaulting
'//          mechanism rather than explicitly provided by the original
'//          provider of the security descriptor.  This may affect the
'//          treatment of the ACL with respect to inheritence of an ACL.
'//          This flag is ignored if the DaclPresent flag is not set.
'//
'//      SE_SACL_PRESENT - This boolean flag, when set,  indicates that the
'//          security descriptor contains a system ACL pointed to by the
'//          Sacl field.  If this flag is set and the Sacl field of the
'//          SECURITY_DESCRIPTOR is null, then an empty (but present)
'//          ACL is being specified.
'//
'//      SE_SACL_DEFAULTED - This boolean flag, when set, indicates that the
'//          ACL pointed to by the Sacl field was provided by a defaulting
'//          mechanism rather than explicitly provided by the original
'//          provider of the security descriptor.  This may affect the
'//          treatment of the ACL with respect to inheritence of an ACL.
'//          This flag is ignored if the SaclPresent flag is not set.
'//
'//      SE_SELF_RELATIVE - This boolean flag, when set, indicates that the
'//          security descriptor is in self-relative form.  In this form,
'//          all fields of the security descriptor are contiguous in memory
'//          and all pointer fields are expressed as offsets from the
'//          beginning of the security descriptor.  This form is useful
'//          for treating security descriptors as opaque data structures
'//          for transmission in communication protocol or for storage on
'//          secondary media.
'//
'//
'//
'// Pictorially the structure of a security descriptor is as follows:
'//
'//       3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1 1 1
'//       1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0
'//      +---------------------------------------------------------------+
'//      |            Control            |Reserved1 (SBZ)|   Revision    |
'//      +---------------------------------------------------------------+
'//      |                            Owner                              |
'//      +---------------------------------------------------------------+
'//      |                            Group                              |
'//      +---------------------------------------------------------------+
'//      |                            Sacl                               |
'//      +---------------------------------------------------------------+
'//      |                            Dacl                               |
'//      +---------------------------------------------------------------+
'//
'// In general, this data structure should be treated opaquely to ensure future
'// compatibility.
'//
'//

' // Size = 20 bytes
TYPE SECURITY_DESCRIPTOR_RELATIVE BYTE
   Revision AS BYTE    ' BYTE
   Sbz1     AS BYTE    ' BYTE
   Control  AS WORD    ' SECURITY_DESCRIPTOR_CONTROL
   Owner    AS DWORD   ' DWORD
   Group    AS DWORD   ' DWORD
   Sacl     AS DWORD   ' DWORD
   Dacl     AS DWORD   ' DWORD
END TYPE

#IF NOT %DEF(%SECURITY_DESCRIPTOR_DEFINED)
%SECURITY_DESCRIPTOR_DEFINED = 1
UNION SECURITY_DESCRIPTOR_CONTROL_UNION
   Control  AS WORD       ' SECURITY_DESCRIPTOR_CONTROL
   ' // For compatibility with the PB includes
   wControl AS WORD       ' SECURITY_DESCRIPTOR_CONTROL
END UNION
' // Size = 20 bytes
TYPE SECURITY_DESCRIPTOR BYTE
   Revision AS BYTE       ' BYTE
   Sbz1     AS BYTE       ' BYTE
   SECURITY_DESCRIPTOR_CONTROL_UNION
   Owner    AS SID PTR    ' PSID
   Group    AS SID PTR    ' PSID
   Sacl     AS ACL PTR    ' PACL
   Dacl     AS ACL PTR    ' PACL
END TYPE
#ENDIF

'// Where:
'//
'//     Revision - Contains the revision level of the security
'//         descriptor.  This allows this structure to be passed between
'//         systems or stored on disk even though it is expected to
'//         change in the future.
'//
'//     Control - A set of flags which qualify the meaning of the
'//         security descriptor or individual fields of the security
'//         descriptor.
'//
'//     Owner - is a pointer to an SID representing an object's owner.
'//         If this field is null, then no owner SID is present in the
'//         security descriptor.  If the security descriptor is in
'//         self-relative form, then this field contains an offset to
'//         the SID, rather than a pointer.
'//
'//     Group - is a pointer to an SID representing an object's primary
'//         group.  If this field is null, then no primary group SID is
'//         present in the security descriptor.  If the security descriptor
'//         is in self-relative form, then this field contains an offset to
'//         the SID, rather than a pointer.
'//
'//     Sacl - is a pointer to a system ACL.  This field value is only
'//         valid if the DaclPresent control flag is set.  If the
'//         SaclPresent flag is set and this field is null, then a null
'//         ACL  is specified.  If the security descriptor is in
'//         self-relative form, then this field contains an offset to
'//         the ACL, rather than a pointer.
'//
'//     Dacl - is a pointer to a discretionary ACL.  This field value is
'//         only valid if the DaclPresent control flag is set.  If the
'//         DaclPresent flag is set and this field is null, then a null
'//         ACL (unconditionally granting access) is specified.  If the
'//         security descriptor is in self-relative form, then this field
'//         contains an offset to the ACL, rather than a pointer.
'//

'////////////////////////////////////////////////////////////////////////
'//                                                                    //
'//               Object Type list for AccessCheckByType               //
'//                                                                    //
'////////////////////////////////////////////////////////////////////////

' // Size = 8 bytes
TYPE OBJECT_TYPE_LIST BYTE
   Level      AS WORD
   Sbz        AS WORD
   ObjectType AS GUID PTR
END TYPE

'//
'// DS values for Level
'//

%ACCESS_OBJECT_GUID       = 0
%ACCESS_PROPERTY_SET_GUID = 1
%ACCESS_PROPERTY_GUID     = 2
%ACCESS_MAX_LEVEL         = 4

'//
'// Parameters to NtAccessCheckByTypeAndAditAlarm
'//

' AUDIT_EVENT_TYPE enum
%AuditEventObjectAccess           = 0
%AuditEventDirectoryServiceAccess = 1

%AUDIT_ALLOW_NO_PRIVILEGE = &H1

'//
'// DS values for Source and ObjectTypeName
'//

'#define ACCESS_DS_SOURCE_A "DS"
'#define ACCESS_DS_SOURCE_W L"DS"
'#define ACCESS_DS_OBJECT_TYPE_NAME_A "Directory Service Object"
'#define ACCESS_DS_OBJECT_TYPE_NAME_W L"Directory Service Object"

$ACCESS_DS_SOURCE_A = "DS"
$$ACCESS_DS_SOURCE_W = "DS"$$
$ACCESS_DS_OBJECT_TYPE_NAME_A = "Directory Service Object"
$$ACCESS_DS_OBJECT_TYPE_NAME_W = "Directory Service Object"$$

'////////////////////////////////////////////////////////////////////////
'//                                                                    //
'//               Privilege Related Data Structures                    //
'//                                                                    //
'////////////////////////////////////////////////////////////////////////


'//
'// Privilege attributes
'//

%SE_PRIVILEGE_ENABLED_BY_DEFAULT = &H00000001???
%SE_PRIVILEGE_ENABLED            = &H00000002???
%SE_PRIVILEGE_REMOVED            = &H00000004???
%SE_PRIVILEGE_USED_FOR_ACCESS    = &H80000000???

%SE_PRIVILEGE_VALID_ATTRIBUTES   = %SE_PRIVILEGE_ENABLED_BY_DEFAULT OR _
                                   %SE_PRIVILEGE_ENABLED            OR _
                                   %SE_PRIVILEGE_REMOVED            OR _
                                   %SE_PRIVILEGE_USED_FOR_ACCESS

'//
'// Privilege Set Control flags
'//

%PRIVILEGE_SET_ALL_NECESSARY = 1

'//
'//  Privilege Set - This is defined for a privilege set of one.
'//                  If more than one privilege is needed, then this structure
'//                  will need to be allocated with more space.
'//
'//  Note: don't change this structure without fixing the INITIAL_PRIVILEGE_SET
'//  structure (defined in se.h)
'//

' // Size = 20 bytes
TYPE PRIVILEGE_SET DWORD
   PrivilegeCount AS DWORD                ' DWORD
   Control        AS DWORD                ' DWORD
   Privilege(0)   AS LUID_AND_ATTRIBUTES  ' LUID_AND_ATTRIBUTES Privilege[ANYSIZE_ARRAY]
END TYPE

'//
'// Values for different access granted\denied reasons:
'// AccessReasonAceN = AccessReasonAce + N.
'// AccessReasonPrivilegeN = AccessReasonPrivilege + N.
'//

%ACCESS_REASON_TYPE_MASK = &Hffff0000???
%ACCESS_REASON_DATA_MASK = &H0000ffff???

' enum ACCESS_REASON_TYPE
%AccessReasonNone             = &H00000000???   ' // Indicate no reason for the bit. The bit may not be checked, or just no known reason.
'//
'// The lowest 2 bytes store the index of the ACE that grant/deny this bit.
'// If the corresponding access maskt is zero, then it is deny ACE; otherwise,
'// it is allow ACE.
'//
%AccessReasonAllowedAce       = &H00010000???   ' // Granted a permission.
%AccessReasonDeniedAce        = &H00020000???   ' // Denied a permission.

%AccessReasonAllowedParentAce = &H00030000???   ' // Granted a permission from parent ACE
%AccessReasonDeniedParentAce  = &H00040000???   ' // Denied a permission from parent ACE

%AccessReasonMissingPrivilege = &H00100000???
%AccessReasonFromPrivilege    = &H00200000???

%AccessReasonIntegrityLevel   = &H00300000???

%AccessReasonOwnership        = &H00400000???

%AccessReasonNullDacl         = &H00500000???
%AccessReasonEmptyDacl        = &H00600000???

%AccessReasonNoSD             = &H00700000???
%AccessReasonNoGrant          = &H00800000???   ' // this access bit is not granted by any ACE.

'//
'// Structure to hold access denied\granted reason for every bit of ACCESS_MASK.
'// There are 32-bits in ACCESS_MASK and only 27-bits are actually valid on
'// return from AccessCheck because MAXIMUM_ALLOWED, GENERIC_READ,
'// GENERIC_WRITE, GENERIC_EXECUTE, and GENERIC_ALL are never returned.
'//
'// The content in Data fields depends on the Access Reason, for example,
'// if the reason is AccessReasonAce, the Data will be the ACE ID.
'// If there are more than one reason (more than one bit is set), the array size
'// of the Data is equal to the number of bits set (or number of reasons).
'// The Data could be null for a particular reason.
'//

'typedef DWORD ACCESS_REASON;

' // Size = 128 bytes
TYPE ACCESS_REASONS
   Data(31) AS DWORD   ' ACCESS_REASON[32]
END TYPE


'/*
'The following data structures are defined to consolidate various falvors of
'access check functions. In particular for Windows 7, the new access check
'function will enable security attribute check, plus returning the reason
'for a access check result.

'The new access check function based on these data structures will
'form the foundation to reimplement other flavors of access check
'functions.

'*/

'//
'// Structure to hold pointer to security descriptor and its unique id, which
'// can be used for caching access check results.
'// (NOTE NOTE) The cache key can be constructed by SecurityDescriptorId, Token and
'// PrincipalSelfSid. Watch how GenericMapping affects the cache results.
'//
%SE_SECURITY_DESCRIPTOR_FLAG_NO_OWNER_ACE    = &H00000001???
%SE_SECURITY_DESCRIPTOR_FLAG_NO_LABEL_ACE    = &H00000002???
%SE_SECURITY_DESCRIPTOR_VALID_FLAGS          = &H00000003???

' // Size = 12 bytes
TYPE SE_SECURITY_DESCRIPTOR DWORD
   Size               AS DWORD                     ' DWORD
   Flags              AS DWORD                     ' DWORD
   SecurityDescriptor AS SECURITY_DESCRIPTOR PTR   ' PSECURITY_DESCRIPTOR
END TYPE

' // Size = 32 bytes
TYPE SE_ACCESS_REQUEST DWORD
   Size                    AS DWORD                        ' DWORD
   SeSecurityDescriptor    AS SE_SECURITY_DESCRIPTOR PTR   ' PSE_SECURITY_DESCRIPTOR
   DesiredAccess           AS ACCESS_MASK                  ' ACCESS_MASK
   PreviouslyGrantedAccess AS ACCESS_MASK                  ' ACCESS_MASK
   PrincipalSelfSid        AS SID PTR                      ' // Need to watch how this field affects the cache.
   GenericMapping          AS GENERIC_MAPPING PTR          ' PGENERIC_MAPPING
   ObjectTypeListCount     AS DWORD                        ' DWORD
   ObjectTypeList          AS OBJECT_TYPE_LIST PTR         ' POBJECT_TYPE_LIST
END TYPE

' // Size = 24 bytes
TYPE SE_ACCESS_REPLY DWORD
   Size            AS DWORD                ' DWORD
   ResultListCount AS DWORD                ' DWORD // Indicate the array size of GrantedAccess and AccessStatus, it only can be either 1 or ObjectTypeListCount.
   GrantedAccess   AS ACCESS_MASK PTR      ' PACCESS_MASK
   AccessStatus    AS DWORD PTR            ' PDWORD
   AccessReason    AS ACCESS_REASONS PTR   ' PACCESS_REASONS
   Privileges      AS PRIVILEGE_SET PTR    ' PPRIVILEGE_SET*
END TYPE


'////////////////////////////////////////////////////////////////////////
'//                                                                    //
'//               NT Defined Privileges                                //
'//                                                                    //
'////////////////////////////////////////////////////////////////////////

'#define SE_CREATE_TOKEN_NAME              TEXT("SeCreateTokenPrivilege")
'#define SE_ASSIGNPRIMARYTOKEN_NAME        TEXT("SeAssignPrimaryTokenPrivilege")
'#define SE_LOCK_MEMORY_NAME               TEXT("SeLockMemoryPrivilege")
'#define SE_INCREASE_QUOTA_NAME            TEXT("SeIncreaseQuotaPrivilege")
'#define SE_UNSOLICITED_INPUT_NAME         TEXT("SeUnsolicitedInputPrivilege")
'#define SE_MACHINE_ACCOUNT_NAME           TEXT("SeMachineAccountPrivilege")
'#define SE_TCB_NAME                       TEXT("SeTcbPrivilege")
'#define SE_SECURITY_NAME                  TEXT("SeSecurityPrivilege")
'#define SE_TAKE_OWNERSHIP_NAME            TEXT("SeTakeOwnershipPrivilege")
'#define SE_LOAD_DRIVER_NAME               TEXT("SeLoadDriverPrivilege")
'#define SE_SYSTEM_PROFILE_NAME            TEXT("SeSystemProfilePrivilege")
'#define SE_SYSTEMTIME_NAME                TEXT("SeSystemtimePrivilege")
'#define SE_PROF_SINGLE_PROCESS_NAME       TEXT("SeProfileSingleProcessPrivilege")
'#define SE_INC_BASE_PRIORITY_NAME         TEXT("SeIncreaseBasePriorityPrivilege")
'#define SE_CREATE_PAGEFILE_NAME           TEXT("SeCreatePagefilePrivilege")
'#define SE_CREATE_PERMANENT_NAME          TEXT("SeCreatePermanentPrivilege")
'#define SE_BACKUP_NAME                    TEXT("SeBackupPrivilege")
'#define SE_RESTORE_NAME                   TEXT("SeRestorePrivilege")
'#define SE_SHUTDOWN_NAME                  TEXT("SeShutdownPrivilege")
'#define SE_DEBUG_NAME                     TEXT("SeDebugPrivilege")
'#define SE_AUDIT_NAME                     TEXT("SeAuditPrivilege")
'#define SE_SYSTEM_ENVIRONMENT_NAME        TEXT("SeSystemEnvironmentPrivilege")
'#define SE_CHANGE_NOTIFY_NAME             TEXT("SeChangeNotifyPrivilege")
'#define SE_REMOTE_SHUTDOWN_NAME           TEXT("SeRemoteShutdownPrivilege")
'#define SE_UNDOCK_NAME                    TEXT("SeUndockPrivilege")
'#define SE_SYNC_AGENT_NAME                TEXT("SeSyncAgentPrivilege")
'#define SE_ENABLE_DELEGATION_NAME         TEXT("SeEnableDelegationPrivilege")
'#define SE_MANAGE_VOLUME_NAME             TEXT("SeManageVolumePrivilege")
'#define SE_IMPERSONATE_NAME               TEXT("SeImpersonatePrivilege")
'#define SE_CREATE_GLOBAL_NAME             TEXT("SeCreateGlobalPrivilege")
'#define SE_TRUSTED_CREDMAN_ACCESS_NAME    TEXT("SeTrustedCredManAccessPrivilege")
'#define SE_RELABEL_NAME                   TEXT("SeRelabelPrivilege")
'#define SE_INC_WORKING_SET_NAME           TEXT("SeIncreaseWorkingSetPrivilege")
'#define SE_TIME_ZONE_NAME                 TEXT("SeTimeZonePrivilege")
'#define SE_CREATE_SYMBOLIC_LINK_NAME      TEXT("SeCreateSymbolicLinkPrivilege")

$SE_CREATE_TOKEN_NAME           = "SeCreateTokenPrivilege"
$SE_ASSIGNPRIMARYTOKEN_NAME     = "SeAssignPrimaryTokenPrivilege"
$SE_LOCK_MEMORY_NAME            = "SeLockMemoryPrivilege"
$SE_INCREASE_QUOTA_NAME         = "SeIncreaseQuotaPrivilege"
$SE_UNSOLICITED_INPUT_NAME      = "SeUnsolicitedInputPrivilege"
$SE_MACHINE_ACCOUNT_NAME        = "SeMachineAccountPrivilege"
$SE_TCB_NAME                    = "SeTcbPrivilege"
$SE_SECURITY_NAME               = "SeSecurityPrivilege"
$SE_TAKE_OWNERSHIP_NAME         = "SeTakeOwnershipPrivilege"
$SE_LOAD_DRIVER_NAME            = "SeLoadDriverPrivilege"
$SE_SYSTEM_PROFILE_NAME         = "SeSystemProfilePrivilege"
$SE_SYSTEMTIME_NAME             = "SeSystemtimePrivilege"
$SE_PROF_SINGLE_PROCESS_NAME    = "SeProfileSingleProcessPrivilege"
$SE_INC_BASE_PRIORITY_NAME      = "SeIncreaseBasePriorityPrivilege"
$SE_CREATE_PAGEFILE_NAME        = "SeCreatePagefilePrivilege"
$SE_CREATE_PERMANENT_NAME       = "SeCreatePermanentPrivilege"
$SE_BACKUP_NAME                 = "SeBackupPrivilege"
$SE_RESTORE_NAME                = "SeRestorePrivilege"
$SE_SHUTDOWN_NAME               = "SeShutdownPrivilege"
$SE_DEBUG_NAME                  = "SeDebugPrivilege"
$SE_AUDIT_NAME                  = "SeAuditPrivilege"
$SE_SYSTEM_ENVIRONMENT_NAME     = "SeSystemEnvironmentPrivilege"
$SE_CHANGE_NOTIFY_NAME          = "SeChangeNotifyPrivilege"
$SE_REMOTE_SHUTDOWN_NAME        = "SeRemoteShutdownPrivilege"
$SE_UNDOCK_NAME                 = "SeUndockPrivilege"
$SE_SYNC_AGENT_NAME             = "SeSyncAgentPrivilege"
$SE_ENABLE_DELEGATION_NAME      = "SeEnableDelegationPrivilege"
$SE_MANAGE_VOLUME_NAME          = "SeManageVolumePrivilege"
$SE_IMPERSONATE_NAME            = "SeImpersonatePrivilege"
$SE_CREATE_GLOBAL_NAME          = "SeCreateGlobalPrivilege"
$SE_TRUSTED_CREDMAN_ACCESS_NAME = "SeTrustedCredManAccessPrivilege"
$SE_RELABEL_NAME                = "SeRelabelPrivilege"
$SE_INC_WORKING_SET_NAME        = "SeIncreaseWorkingSetPrivilege"
$SE_TIME_ZONE_NAME              = "SeTimeZonePrivilege"
$SE_CREATE_SYMBOLIC_LINK_NAME   = "SeCreateSymbolicLinkPrivilege"

'////////////////////////////////////////////////////////////////////
'//                                                                //
'//           Security Quality Of Service                          //
'//                                                                //
'//                                                                //
'////////////////////////////////////////////////////////////////////

'//
'// Impersonation Level
'//
'// Impersonation level is represented by a pair of bits in Windows.
'// If a new impersonation level is added or lowest value is changed from
'// 0 to something else, fix the Windows CreateFile call.
'//

' SECURITY_IMPERSONATION_LEVEL enum
%SecurityAnonymous      = 0
%SecurityIdentification = 1
%SecurityImpersonation  = 2
%SecurityDelegation     = 3


'#define SECURITY_MAX_IMPERSONATION_LEVEL SecurityDelegation
'#define SECURITY_MIN_IMPERSONATION_LEVEL SecurityAnonymous
'#define DEFAULT_IMPERSONATION_LEVEL SecurityImpersonation
'#define VALID_IMPERSONATION_LEVEL(L) (((L) >= SECURITY_MIN_IMPERSONATION_LEVEL) && ((L) <= SECURITY_MAX_IMPERSONATION_LEVEL))

%SECURITY_MAX_IMPERSONATION_LEVEL = %SecurityDelegation
%DEFAULT_IMPERSONATION_LEVEL      = %SecurityImpersonation
%SECURITY_MIN_IMPERSONATION_LEVEL = %SecurityAnonymous

MACRO VALID_IMPERSONATION_LEVEL(L) = (L >= %SECURITY_MIN_IMPERSONATION_LEVEL) AND (L <= %SECURITY_MAX_IMPERSONATION_LEVEL)

'////////////////////////////////////////////////////////////////////
'//                                                                //
'//           Token Object Definitions                             //
'//                                                                //
'//                                                                //
'////////////////////////////////////////////////////////////////////


'//
'// Token Specific Access Rights.
'//

%TOKEN_ASSIGN_PRIMARY    = &H0001
%TOKEN_DUPLICATE         = &H0002
%TOKEN_IMPERSONATE       = &H0004
%TOKEN_QUERY             = &H0008
%TOKEN_QUERY_SOURCE      = &H0010
%TOKEN_ADJUST_PRIVILEGES = &H0020
%TOKEN_ADJUST_GROUPS     = &H0040
%TOKEN_ADJUST_DEFAULT    = &H0080
%TOKEN_ADJUST_SESSIONID  = &H0100

%TOKEN_ALL_ACCESS = %STANDARD_RIGHTS_REQUIRED  OR _
                    %TOKEN_ASSIGN_PRIMARY      OR _
                    %TOKEN_DUPLICATE           OR _
                    %TOKEN_IMPERSONATE         OR _
                    %TOKEN_QUERY               OR _
                    %TOKEN_QUERY_SOURCE        OR _
                    %TOKEN_ADJUST_PRIVILEGES   OR _
                    %TOKEN_ADJUST_GROUPS       OR _
                    %TOKEN_ADJUST_SESSIONID    OR _
                    %TOKEN_ADJUST_DEFAULT

'#if ((defined(_WIN32_WINNT) && (_WIN32_WINNT > 0x0400)) || (!defined(_WIN32_WINNT)))
'#define TOKEN_ALL_ACCESS  (TOKEN_ALL_ACCESS_P |\
'                          TOKEN_ADJUST_SESSIONID )
'#else
'#define TOKEN_ALL_ACCESS  (TOKEN_ALL_ACCESS_P)
'#endif

%TOKEN_READ       = %STANDARD_RIGHTS_READ OR %TOKEN_QUERY

%TOKEN_WRITE      = %STANDARD_RIGHTS_WRITE    OR _
                    %TOKEN_ADJUST_PRIVILEGES  OR _
                    %TOKEN_ADJUST_GROUPS      OR _
                    %TOKEN_ADJUST_DEFAULT

%TOKEN_EXECUTE    = %STANDARD_RIGHTS_EXECUTE

'//
'//
'// Token Types
'//

' TOKEN_TYPE enum
%TokenPrimary       = 1
%TokenImpersonation = 2

'//
'// Token elevation values describe the relative strength of a given token.
'// A full token is a token with all groups and privileges to which the principal
'// is authorized.  A limited token is one with some groups or privileges removed.
'//

' enum TOKEN_ELEVATION_TYPE
%TokenElevationTypeDefault = 1
%TokenElevationTypeFull    = 2
%TokenElevationTypeLimited = 3

'//
'// Token Information Classes.
'//

' TOKEN_INFORMATION_CLASS enum
%TokenUser                  = 1
%TokenGroups                = 2
%TokenPrivileges            = 3
%TokenOwner                 = 4
%TokenPrimaryGroup          = 5
%TokenDefaultDacl           = 6
%TokenSource                = 7
%TokenType                  = 8
%TokenImpersonationLevel    = 9
%TokenStatistics            = 10
%TokenRestrictedSids        = 11
%TokenSessionId             = 12
%TokenGroupsAndPrivileges   = 13
%TokenSessionReference      = 14
%TokenSandBoxInert          = 15
%TokenAuditPolicy           = 16
%TokenOrigin                = 17
%TokenElevationType         = 18
%TokenLinkedToken           = 19
%TokenElevation             = 20
%TokenHasRestrictions       = 21
%TokenAccessInformation     = 22
%TokenVirtualizationAllowed = 23
%TokenVirtualizationEnabled = 24
%TokenIntegrityLevel        = 25
%TokenUIAccess              = 26
%TokenMandatoryPolicy       = 27
%TokenLogonSid              = 28
%MaxTokenInfoClass          = 29   ' // MaxTokenInfoClass should always be the last enum

'//
'// Token information class structures
'//

' // Size = 8 bytes
TYPE TOKEN_USER DWORD
   User AS SID_AND_ATTRIBUTES
END TYPE

' // Size = 12 bytes
TYPE TOKEN_GROUPS DWORD
   GroupCount AS DWORD
   Groups(0)  AS SID_AND_ATTRIBUTES   ' array size may vary
END TYPE

' // Size = 16 bytes
TYPE TOKEN_PRIVILEGES DWORD
   PrivilegeCount AS DWORD
   Privileges(0)  AS LUID_AND_ATTRIBUTES  ' array size may vary
END TYPE

' // Size = 4 bytes
TYPE TOKEN_OWNER DWORD
   Owner AS SID PTR
END TYPE

' // Size = 4 bytes
TYPE TOKEN_PRIMARY_GROUP DWORD
   PrimaryGroup AS SID PTR
END TYPE

' // Size = 4 bytes
TYPE TOKEN_DEFAULT_DACL DWORD
   DefaultDacl AS ACL PTR
END TYPE

' // Size = 44 bytes
TYPE TOKEN_GROUPS_AND_PRIVILEGES DWORD
   SidCount            AS DWORD
   SidLength           AS DWORD
   Sids                AS SID_AND_ATTRIBUTES  PTR
   RestrictedSidCount  AS DWORD
   RestrictedSidLength AS DWORD
   RestrictedSids      AS SID_AND_ATTRIBUTES  PTR
   PrivilegeCount      AS DWORD
   PrivilegeLength     AS DWORD
   Privileges          AS LUID_AND_ATTRIBUTES PTR
   AuthenticationId    AS QUAD   ' LUID
END TYPE

' // Size = 4 bytes
TYPE TOKEN_LINKED_TOKEN DWORD
   LinkedToken AS DWORD   ' HANDLE
END TYPE

' // Size = 4 bytes
TYPE TOKEN_ELEVATION DWORD
   TokenIsElevated AS DWORD   ' DWORD
END TYPE

' // Size = 8 bytes
TYPE TOKEN_MANDATORY_LABEL DWORD
   Label AS SID_AND_ATTRIBUTES
END TYPE

%TOKEN_MANDATORY_POLICY_OFF             = &H0
%TOKEN_MANDATORY_POLICY_NO_WRITE_UP     = &H1
%TOKEN_MANDATORY_POLICY_NEW_PROCESS_MIN = &H2

%TOKEN_MANDATORY_POLICY_VALID_MASK      = %TOKEN_MANDATORY_POLICY_NO_WRITE_UP OR _
                                          %TOKEN_MANDATORY_POLICY_NEW_PROCESS_MIN

' // Size = 4 bytes
TYPE TOKEN_MANDATORY_POLICY DWORD
   Policy AS DWORD   ' DWORD
END TYPE

' // Size = 36 bytes
TYPE TOKEN_ACCESS_INFORMATION DWORD
   SidHash            AS SID_AND_ATTRIBUTES_HASH PTR   ' PSID_AND_ATTRIBUTES_HASH
   RestrictedSidHash  AS SID_AND_ATTRIBUTES_HASH PTR   ' PSID_AND_ATTRIBUTES_HASH
   Privileges         AS TOKEN_PRIVILEGES PTR          ' PTOKEN_PRIVILEGES
   AuthenticationId   AS QUAD                          ' LUID
   TokenType          AS LONG                          ' TOKEN_TYPE
   ImpersonationLevel AS LONG                          ' SECURITY_IMPERSONATION_LEVEL
   MandatoryPolicy    AS TOKEN_MANDATORY_POLICY
   Flags              AS DWORD                         ' DWORD
END TYPE

'//
'// Valid bits for each TOKEN_AUDIT_POLICY policy mask field.
'//

%POLICY_AUDIT_SUBCATEGORY_COUNT = 53

'typedef struct _TOKEN_AUDIT_POLICY {
'    BYTE  PerUserPolicy[((POLICY_AUDIT_SUBCATEGORY_COUNT) >> 1) + 1];
'} TOKEN_AUDIT_POLICY, *PTOKEN_AUDIT_POLICY;

' // Size = 27 bytes
TYPE TOKEN_AUDIT_POLICY BYTE
   PerUserPolicy(26) AS BYTE
END TYPE

%TOKEN_SOURCE_LENGTH = 8

UNION TOKEN_SOURCE_SOURCENAME_UNION BYTE
   SourceName AS STRING * %TOKEN_SOURCE_LENGTH
   ' // For compatibility with the PB declares
   SourceName(%TOKEN_SOURCE_LENGTH - 1) AS BYTE
END UNION

' // Size = 16 bytes
TYPE TOKEN_SOURCE BYTE
   TOKEN_SOURCE_SOURCENAME_UNION
   SourceIdentifier AS QUAD   ' LUID
END TYPE

' // Size = 56 bytes
TYPE TOKEN_STATISTICS QWORD FILL
   TokenId            AS QUAD    ' LUID
   AuthenticationId   AS QUAD    ' LUID
   ExpirationTime     AS QUAD    ' LARGE_INTEGER
   TokenType          AS LONG    ' TOKEN_TYPE
   ImpersonationLevel AS LONG    ' SECURITY_IMPERSONATION_LEVEL
   DynamicCharged     AS DWORD   ' DWORD
   DynamicAvailable   AS DWORD   ' DWORD
   GroupCount         AS DWORD   ' DWORD
   PrivilegeCount     AS DWORD   ' DWORD
   ModifiedId         AS QUAD    ' LUID
END TYPE

' // Size = 40 bytes
TYPE TOKEN_CONTROL DWORD
   TokenId          AS QUAD   ' LUID
   AuthenticationId AS QUAD   ' LUID
   ModifiedId       AS QUAD   ' LUID
   TokenSource      AS TOKEN_SOURCE
END TYPE

' // Size = 8 bytes
TYPE TOKEN_ORIGIN DWORD
   OriginatingLogonSession AS QUAD   ' LUID
END TYPE

' enum _MANDATORY_LEVEL
%MandatoryLevelUntrusted     = 0
%MandatoryLevelLow           = 1
%MandatoryLevelMedium        = 2
%MandatoryLevelHigh          = 3
%MandatoryLevelSystem        = 4
%MandatoryLevelSecureProcess = 5
%MandatoryLevelCount         = 6

'//
'// Security Tracking Mode
'//

%SECURITY_DYNAMIC_TRACKING = 1?   ' %TRUE
%SECURITY_STATIC_TRACKING  = 0?   ' %FALSE

'typedef BOOLEAN SECURITY_CONTEXT_TRACKING_MODE,
'                    * PSECURITY_CONTEXT_TRACKING_MODE;


'//
'// Quality Of Service
'//

' // Size = 12 bytes
TYPE SECURITY_QUALITY_OF_SERVICE
   Length              AS DWORD   ' DWORD
   Impersonationlevel  AS LONG    ' SECURITY_IMPERSONATION_LEVEL
   ContextTrackingMode AS BYTE    ' SECURITY_CONTEXT_TRACKING_MODE
   EffectiveOnly       AS BYTE    ' BOOLEAN
   alignment__         AS WORD    ' // To keep DWORD alignment
END TYPE

'//
'// Used to represent information related to a thread impersonation
'//

' // Size = 12 bytes
TYPE SE_IMPERSONATION_STATE DWORD FILL
   Token         AS DWORD   ' PACCESS_TOKEN
   CopyOnOpen    AS BYTE    ' BOOLEAN
   EffectiveOnly AS BYTE    ' BOOLEAN
   Level         AS LONG    ' SECURITY_IMPERSONATION_LEVEL
END TYPE

%DISABLE_MAX_PRIVILEGE = &H1???
%SANDBOX_INERT         = &H2???
%LUA_TOKEN             = &H4???
%WRITE_RESTRICTED      = &H8???

'typedef DWORD SECURITY_INFORMATION, *PSECURITY_INFORMATION;
MACRO SECURITY_INFORMATION = DWORD

%OWNER_SECURITY_INFORMATION = &H00000001???
%GROUP_SECURITY_INFORMATION = &H00000002???
%DACL_SECURITY_INFORMATION  = &H00000004???
%SACL_SECURITY_INFORMATION  = &H00000008???
%LABEL_SECURITY_INFORMATION = &H00000010???

%PROTECTED_DACL_SECURITY_INFORMATION   = &H80000000???
%PROTECTED_SACL_SECURITY_INFORMATION   = &H40000000???
%UNPROTECTED_DACL_SECURITY_INFORMATION = &H20000000???
%UNPROTECTED_SACL_SECURITY_INFORMATION = &H10000000???

%PROCESS_TERMINATE                 = &H0001???
%PROCESS_CREATE_THREAD             = &H0002???
%PROCESS_SET_SESSIONID             = &H0004???
%PROCESS_VM_OPERATION              = &H0008???
%PROCESS_VM_READ                   = &H0010???
%PROCESS_VM_WRITE                  = &H0020???
%PROCESS_DUP_HANDLE                = &H0040???
%PROCESS_CREATE_PROCESS            = &H0080???
%PROCESS_SET_QUOTA                 = &H0100???
%PROCESS_SET_INFORMATION           = &H0200???
%PROCESS_QUERY_INFORMATION         = &H0400???
%PROCESS_SUSPEND_RESUME            = &H0800???
%PROCESS_QUERY_LIMITED_INFORMATION = &H1000???
'#if (NTDDI_VERSION >= NTDDI_VISTA)
#IF %WINVER >= &H0600
%PROCESS_ALL_ACCESS = %STANDARD_RIGHTS_REQUIRED OR %SYNCHRONIZE OR &HFFFF???
#ELSE
%PROCESS_ALL_ACCESS = %STANDARD_RIGHTS_REQUIRED OR %SYNCHRONIZE OR &HFFF???
#ENDIF

'#if defined(_WIN64)

'#define MAXIMUM_PROC_PER_GROUP 64

'#else

'#define MAXIMUM_PROC_PER_GROUP 32

'#endif

'#define MAXIMUM_PROCESSORS          MAXIMUM_PROC_PER_GROUP
%MAXIMUM_PROCESSORS = 32

%THREAD_TERMINATE            = &H0001???
%THREAD_SUSPEND_RESUME       = &H0002???
%THREAD_GET_CONTEXT          = &H0008???
%THREAD_SET_CONTEXT          = &H0010???
%THREAD_SET_INFORMATION      = &H0020???
%THREAD_QUERY_INFORMATION    = &H0040???
%THREAD_SET_THREAD_TOKEN     = &H0080???
%THREAD_IMPERSONATE          = &H0100???
%THREAD_DIRECT_IMPERSONATION = &H0200???

%THREAD_SET_LIMITED_INFORMATION   = &H0400???  ' // winnt
%THREAD_QUERY_LIMITED_INFORMATION = &H0800??? ' // winnt
'#if (NTDDI_VERSION >= NTDDI_VISTA)
#IF %WINVER >= &H0600
%THREAD_ALL_ACCESS = %STANDARD_RIGHTS_REQUIRED OR %SYNCHRONIZE OR &HFFFF???
#ELSE
%THREAD_ALL_ACCESS = %STANDARD_RIGHTS_REQUIRED OR %SYNCHRONIZE OR &H3FF???
#ENDIF

%JOB_OBJECT_ASSIGN_PROCESS           = &H0001???
%JOB_OBJECT_SET_ATTRIBUTES           = &H0002???
%JOB_OBJECT_QUERY                    = &H0004???
%JOB_OBJECT_TERMINATE                = &H0008???
%JOB_OBJECT_SET_SECURITY_ATTRIBUTES  = &H0010???
%JOB_OBJECT_ALL_ACCESS = %STANDARD_RIGHTS_REQUIRED OR %SYNCHRONIZE OR &H1F???

' // Size = 12 bytes
TYPE JOB_SET_ARRAY DWORD
   JobHandle   AS DWORD   ' HANDLE // Handle to job object to insert
   MemberLevel AS DWORD   ' DWORD  // Level of this job in the set. Must be > 0. Can be sparse.
   Flags       AS DWORD   ' DWORD  // Unused. Must be zero
END TYPE

%FLS_MAXIMUM_AVAILABLE = 128
%TLS_MINIMUM_AVAILABLE = 64

'typedef struct _NT_TIB {
'    struct _EXCEPTION_REGISTRATION_RECORD *ExceptionList;
'    PVOID StackBase;
'    PVOID StackLimit;
'    PVOID SubSystemTib;
'#if defined(_MSC_EXTENSIONS)
'    union {
'        PVOID FiberData;
'        DWORD Version;
'    };
'#else
'    PVOID FiberData;
'#endif
'    PVOID ArbitraryUserPointer;
'    struct _NT_TIB *Self;
'} NT_TIB;
'typedef NT_TIB *PNT_TIB;

' // Size = 4 bytes
UNION NT_TIB_UNION DWORD
   FiberData AS DWORD
   Version   AS DWORD
END UNION

' // Size = 28 bytes
TYPE NT_TIB DWORD
   ExceptionList        AS DWORD
   StackBase            AS DWORD
   StackLimit           AS DWORD
   SubSystemTib         AS DWORD
   NT_TIB_UNION
   ArbitraryUserPointer AS DWORD
   Self                 AS NT_TIB PTR
END TYPE
'typedef NT_TIB *PNT_TIB;

'//
'// 32 and 64 bit specific version for wow64 and the debugger
'//
'typedef struct _NT_TIB32 {
'    DWORD ExceptionList;
'    DWORD StackBase;
'    DWORD StackLimit;
'    DWORD SubSystemTib;
'#if defined(_MSC_EXTENSIONS)
'    union {
'        DWORD FiberData;
'        DWORD Version;
'    };
'#else
'    DWORD FiberData;
'#endif
'    DWORD ArbitraryUserPointer;
'    DWORD Self;
'} NT_TIB32, *PNT_TIB32;

' // Size = 4 bytes
UNION NT_TIB32_UNION DWORD
   FiberData AS DWORD
   Version   AS DWORD
END UNION

' // Size = 28 bytes
TYPE NT_TIB32 DWORD
   ExceptionList        AS DWORD
   StackBase            AS DWORD
   StackLimit           AS DWORD
   SubSystemTib         AS DWORD
   NT_TIB_UNION
   ArbitraryUserPointer AS DWORD
   Self                 AS DWORD
END TYPE

'typedef struct _NT_TIB64 {
'    DWORD64 ExceptionList;
'    DWORD64 StackBase;
'    DWORD64 StackLimit;
'    DWORD64 SubSystemTib;
'#if defined(_MSC_EXTENSIONS)
'    union {
'        DWORD64 FiberData;
'        DWORD Version;
'    };
'#else
'    DWORD64 FiberData;
'#endif
'    DWORD64 ArbitraryUserPointer;
'    DWORD64 Self;
'} NT_TIB64, *PNT_TIB64;

' // Size = 8 bytes
UNION NT_TIB64_UNION QWORD
   FiberData AS QUAD
   Version   AS DWORD
END UNION

' // Size = 56 bytes
TYPE NT_TIB64 QWORD
   ExceptionList        AS QUAD
   StackBase            AS QUAD
   StackLimit           AS QUAD
   SubSystemTib         AS QUAD
   NT_TIB64_UNION
   ArbitraryUserPointer AS QUAD
   Self                 AS QUAD
END TYPE

'#if !defined(_X86_) && !defined(_IA64_) && !defined(_AMD64_)
'#define WX86
'#endif

%THREAD_BASE_PRIORITY_LOWRT = 15  ' // value that gets a thread to LowRealtime-1
%THREAD_BASE_PRIORITY_MAX   = 2   ' // maximum thread base priority boost
%THREAD_BASE_PRIORITY_MIN   = -2  ' // minimum thread base priority boost
%THREAD_BASE_PRIORITY_IDLE  = -15 ' // value that gets a thread to idle

' // Size = 12 bytes
TYPE UMS_CREATE_THREAD_ATTRIBUTES DWORD
   UmsVersion        AS DWORD   ' DWORD
   UmsContext        AS DWORD   ' PVOID
   UmsCompletionList AS DWORD   ' PVOID
END TYPE

' // Size = 32 bytes
TYPE QUOTA_LIMITS QWORD FILL
   PagedPoolLimit        AS DWORD   ' SIZE_T
   NonPagedPoolLimit     AS DWORD   ' SIZE_T
   MinimumWorkingSetSize AS DWORD   ' SIZE_T
   MaximumWorkingSetSize AS DWORD   ' SIZE_T
   PagefileLimit         AS DWORD   ' SIZE_T
   TimeLimit             AS QUAD    ' LARGE_INTEGER
END TYPE

%QUOTA_LIMITS_HARDWS_MIN_ENABLE  = &H00000001???
%QUOTA_LIMITS_HARDWS_MIN_DISABLE = &H00000002???
%QUOTA_LIMITS_HARDWS_MAX_ENABLE  = &H00000004???
%QUOTA_LIMITS_HARDWS_MAX_DISABLE = &H00000008???
%QUOTA_LIMITS_USE_DEFAULT_LIMITS = &H00000010???

' // Size = 4 bytes
TYPE RATE_QUOTA_LIMIT_STRUCT DWORD
   RatePhase   AS BIT * 7 IN DWORD
   RatePercent AS BIT * 25
END TYPE

' // Size = 4 bytes
UNION RATE_QUOTA_LIMIT DWORD
   RateData AS DWORD
   RATE_QUOTA_LIMIT_STRUCT
END UNION

' // Size = 56 bytes
TYPE QUOTA_LIMITS_EX QWORD FILL
   PagedPoolLimit        AS DWORD   ' SIZE_T
   NonPagedPoolLimit     AS DWORD   ' SIZE_T
   MinimumWorkingSetSize AS DWORD   ' SIZE_T
   MaximumWorkingSetSize AS DWORD   ' SIZE_T
   PagefileLimit         AS DWORD   ' SIZE_T
   TimeLimit             AS QUAD    ' LARGE_INTEGER
   WorkingSetLimit       AS DWORD   ' SIZE_T
   Reserved2             AS DWORD   ' SIZE_T
   Reserved3             AS DWORD   ' SIZE_T
   Reserved4             AS DWORD   ' SIZE_T
   Flags                 AS DWORD   ' DWORD
   CpuRateLimit          AS RATE_QUOTA_LIMIT
END TYPE

' // Size = 48 bytes
TYPE IO_COUNTERS QWORD
   ReadOperationCount  AS QUAD   ' ULONGLONG
   WriteOperationCount AS QUAD   ' ULONGLONG
   OtherOperationCount AS QUAD   ' ULONGLONG
   ReadTransferCount   AS QUAD   ' ULONGLONG
   WriteTransferCount  AS QUAD   ' ULONGLONG
   OtherTransferCount  AS QUAD   ' ULONGLONG
END TYPE

%MAX_HW_COUNTERS = 16
%THREAD_PROFILING_FLAG_DISPATCH = &H00000001???

' enum _HARDWARE_COUNTER_TYPE
%PMCCounter = 0
%MaxHardwareCounterType = 1

' // Size = 48 bytes
TYPE JOBOBJECT_BASIC_ACCOUNTING_INFORMATION QWORD FILL
   TotalUserTime             AS QUAD    ' LARGE_INTEGER
   TotalKernelTime           AS QUAD    ' LARGE_INTEGER
   ThisPeriodTotalUserTime   AS QUAD    ' LARGE_INTEGER
   ThisPeriodTotalKernelTime AS QUAD    ' LARGE_INTEGER
   TotalPageFaultCount       AS DWORD   ' DWORD
   TotalProcesses            AS DWORD   ' DWORD
   ActiveProcesses           AS DWORD   ' DWORD
   TotalTerminatedProcesses  AS DWORD   ' DWORD
END TYPE

' // Size = 48 bytes
TYPE JOBOBJECT_BASIC_LIMIT_INFORMATION   ' Must be 8 byte aligned
   PerProcessUserTimeLimit AS QUAD        ' LARGE_INTEGER
   PerJobUserTimeLimit     AS QUAD        ' LARGE_INTEGER
   LimitFlags              AS DWORD       ' DWORD
   MinimumWorkingSetSize   AS DWORD       ' SIZE_T
   MaximumWorkingSetSize   AS DWORD       ' SIZE_T
   ActiveProcessLimit      AS DWORD       ' DWORD
   Affinity                AS DWORD PTR   ' ULONG_PTR
   PriorityClass           AS DWORD       ' DWORD
   SchedulingClass         AS DWORD       ' DWORD
   alignment__             AS DWORD       ' // To keep 8 byte alignment
END TYPE

' // Size = 112 bytes
TYPE JOBOBJECT_EXTENDED_LIMIT_INFORMATION QWORD FILL
   BasicLimitInformation AS JOBOBJECT_BASIC_LIMIT_INFORMATION
   IoInfo                AS IO_COUNTERS
   ProcessMemoryLimit    AS DWORD   ' SIZE_T
   JobMemoryLimit        AS DWORD   ' SIZE_T
   PeakProcessMemoryUsed AS DWORD   ' SIZE_T
   PeakJobMemoryUsed     AS DWORD   ' SIZE_T
END TYPE

' // Size = 12 bytes
TYPE JOBOBJECT_BASIC_PROCESS_ID_LIST DWORD
   NumberOfAssignedProcesses AS DWORD       ' DWORD
   NumberOfProcessIdsInList  AS DWORD       ' DWORD
   ProcessIdList(0)          AS DWORD PTR   ' ULONG_PTR ProcessIdList[1]
END TYPE

' // Size = 4 bytes
TYPE JOBOBJECT_BASIC_UI_RESTRICTIONS DWORD
   UIRestrictionsClass AS DWORD
END TYPE

'//
'// N.B. The JOBOBJECT_SECURITY_LIMIT_INFORMATION information class is no longer supported.
'//

' // Size = 20 bytes
TYPE JOBOBJECT_SECURITY_LIMIT_INFORMATION DWORD
   SecurityLimitFlags AS DWORD                  ' DWORD
   JobToken           AS DWORD                  ' HANDLE
   SidsToDisable      AS TOKEN_GROUPS PTR       ' PTOKEN_GROUPS
   PrivilegesToDelete AS TOKEN_PRIVILEGES PTR   ' PTOKEN_PRIVILEGES
   RestrictedSids     AS TOKEN_GROUPS PTR       ' PTOKEN_GROUPS
END TYPE

' // Size = 4 bytes
TYPE JOBOBJECT_END_OF_JOB_TIME_INFORMATION DWORD
   EndOfJobTimeAction AS DWORD
END TYPE

' // Size = 8 bytes
TYPE JOBOBJECT_ASSOCIATE_COMPLETION_PORT DWORD
   CompletionKey  AS DWORD   ' PVOID
   CompletionPort AS DWORD   ' HANDLE
END TYPE

' // Size = 96 bytes
TYPE JOBOBJECT_BASIC_AND_IO_ACCOUNTING_INFORMATION QWORD FILL
   BasicInfo AS JOBOBJECT_BASIC_ACCOUNTING_INFORMATION
   IoInfo    AS IO_COUNTERS
END TYPE

' // Size = 4 bytes
TYPE JOBOBJECT_JOBSET_INFORMATION DWORD
   MemberLevel AS DWORD
END TYPE

%JOB_OBJECT_TERMINATE_AT_END_OF_JOB = 0
%JOB_OBJECT_POST_AT_END_OF_JOB      = 1

'//
'// Completion Port Messages for job objects
'//
'// These values are returned via the lpNumberOfBytesTransferred parameter
'//

%JOB_OBJECT_MSG_END_OF_JOB_TIME       = 1???
%JOB_OBJECT_MSG_END_OF_PROCESS_TIME   = 2???
%JOB_OBJECT_MSG_ACTIVE_PROCESS_LIMIT  = 3???
%JOB_OBJECT_MSG_ACTIVE_PROCESS_ZERO   = 4???
%JOB_OBJECT_MSG_NEW_PROCESS           = 6???
%JOB_OBJECT_MSG_EXIT_PROCESS          = 7???
%JOB_OBJECT_MSG_ABNORMAL_EXIT_PROCESS = 8???
%JOB_OBJECT_MSG_PROCESS_MEMORY_LIMIT  = 9???
%JOB_OBJECT_MSG_JOB_MEMORY_LIMIT      = 10???

'//
'// Basic Limits
'//
%JOB_OBJECT_LIMIT_WORKINGSET        = &H00000001???
%JOB_OBJECT_LIMIT_PROCESS_TIME      = &H00000002???
%JOB_OBJECT_LIMIT_JOB_TIME          = &H00000004???
%JOB_OBJECT_LIMIT_ACTIVE_PROCESS    = &H00000008???
%JOB_OBJECT_LIMIT_AFFINITY          = &H00000010???
%JOB_OBJECT_LIMIT_PRIORITY_CLASS    = &H00000020???
%JOB_OBJECT_LIMIT_PRESERVE_JOB_TIME = &H00000040???
%JOB_OBJECT_LIMIT_SCHEDULING_CLASS  = &H00000080???

'//
'// Extended Limits
'//
%JOB_OBJECT_LIMIT_PROCESS_MEMORY             = &H00000100???
%JOB_OBJECT_LIMIT_JOB_MEMORY                 = &H00000200???
%JOB_OBJECT_LIMIT_DIE_ON_UNHANDLED_EXCEPTION = &H00000400???
%JOB_OBJECT_LIMIT_BREAKAWAY_OK               = &H00000800???
%JOB_OBJECT_LIMIT_SILENT_BREAKAWAY_OK        = &H00001000???
%JOB_OBJECT_LIMIT_KILL_ON_JOB_CLOSE          = &H00002000???

%JOB_OBJECT_LIMIT_SUBSET_AFFINITY            = &H00004000???
%JOB_OBJECT_LIMIT_RESERVED3                  = &H00008000???
%JOB_OBJECT_LIMIT_RESERVED4                  = &H00010000???
%JOB_OBJECT_LIMIT_RESERVED5                  = &H00020000???
%JOB_OBJECT_LIMIT_RESERVED6                  = &H00040000???

%JOB_OBJECT_LIMIT_VALID_FLAGS          = &H0007ffff???

%JOB_OBJECT_BASIC_LIMIT_VALID_FLAGS    = &H000000ff???
%JOB_OBJECT_EXTENDED_LIMIT_VALID_FLAGS = &H00007fff???
%JOB_OBJECT_RESERVED_LIMIT_VALID_FLAGS = &H0007ffff???

'//
'// UI restrictions for jobs
'//

%JOB_OBJECT_UILIMIT_NONE              = &H00000000???

%JOB_OBJECT_UILIMIT_HANDLES           = &H00000001???
%JOB_OBJECT_UILIMIT_READCLIPBOARD     = &H00000002???
%JOB_OBJECT_UILIMIT_WRITECLIPBOARD    = &H00000004???
%JOB_OBJECT_UILIMIT_SYSTEMPARAMETERS  = &H00000008???
%JOB_OBJECT_UILIMIT_DISPLAYSETTINGS   = &H00000010???
%JOB_OBJECT_UILIMIT_GLOBALATOMS       = &H00000020???
%JOB_OBJECT_UILIMIT_DESKTOP           = &H00000040???
%JOB_OBJECT_UILIMIT_EXITWINDOWS       = &H00000080???

%JOB_OBJECT_UILIMIT_ALL               = &H000000FF???

%JOB_OBJECT_UI_VALID_FLAGS            = &H000000FF???

%JOB_OBJECT_SECURITY_NO_ADMIN         = &H00000001???
%JOB_OBJECT_SECURITY_RESTRICTED_TOKEN = &H00000002???
%JOB_OBJECT_SECURITY_ONLY_TOKEN       = &H00000004???
%JOB_OBJECT_SECURITY_FILTER_TOKENS    = &H00000008???

%JOB_OBJECT_SECURITY_VALID_FLAGS      = &H0000000f???

' JOBOBJECTINFOCLASS enum
%JobObjectBasicAccountingInformation         = 1
%JobObjectBasicLimitInformation              = 2
%JobObjectBasicProcessIdList                 = 3
%JobObjectBasicUIRestrictions                = 4
%JobObjectSecurityLimitInformation           = 5   ' // deprecated
%JobObjectEndOfJobTimeInformation            = 6
%JobObjectAssociateCompletionPortInformation = 7
%JobObjectBasicAndIoAccountingInformation    = 8
%JobObjectExtendedLimitInformation           = 9
%JobObjectJobSetInformation                  = 10
%JobObjectGroupInformation                   = 11
%MaxJobObjectInfoClass                       = 12

'//
%EVENT_MODIFY_STATE      = &H0002
%EVENT_ALL_ACCESS = %STANDARD_RIGHTS_REQUIRED OR %SYNCHRONIZE OR &H3
%MUTANT_QUERY_STATE      = &H0001

%MUTANT_ALL_ACCESS = %STANDARD_RIGHTS_REQUIRED OR %SYNCHRONIZE OR %MUTANT_QUERY_STATE

%SEMAPHORE_MODIFY_STATE = &H0002
%SEMAPHORE_ALL_ACCESS = %STANDARD_RIGHTS_REQUIRED OR %SYNCHRONIZE OR &H3

'//
'// Timer Specific Access Rights.
'//

%TIMER_QUERY_STATE       = &H0001
%TIMER_MODIFY_STATE      = &H0002

%TIMER_ALL_ACCESS = %STANDARD_RIGHTS_REQUIRED OR %SYNCHRONIZE OR _
                          %TIMER_QUERY_STATE OR %TIMER_MODIFY_STATE

%TIME_ZONE_ID_UNKNOWN  = 0
%TIME_ZONE_ID_STANDARD = 1
%TIME_ZONE_ID_DAYLIGHT = 2

' LOGICAL_PROCESSOR_RELATIONSHIP enum
%RelationProcessorCore    = 0
%RelationNumaNode         = 1
%RelationCache            = 2
%RelationProcessorPackage = 3
%RelationGroup            = 4
%RelationAll              = &Hffff

%LTP_PC_SMT = &H1

' PROCESSOR_CACHE_TYPE enum
%CacheUnified = 0
%CacheInstruction = 1
%CacheData = 2
%CacheTrace = 3

%CACHE_FULLY_ASSOCIATIVE = &HFF

UNION CACHE_DESCRIPTOR_SIZE_UNION BYTE
   Size          AS DWORD   ' DWORD
   ' // For compatibility with the PB declares
   nSize         AS DWORD   ' DWORD
END UNION

UNION CACHE_DESCRIPTOR_TYPE_UNION BYTE
   Type          AS LONG    ' PROCESSOR_CACHE_TYPE
   ' // For compatibility with the PB declares
   nType         AS LONG    ' PROCESSOR_CACHE_TYPE
END UNION

' // Size = 12 bytes
TYPE CACHE_DESCRIPTOR BYTE
   Level         AS BYTE    ' BYTE
   Associativity AS BYTE    ' BYTE
   LineSize      AS WORD    ' WORD
   CACHE_DESCRIPTOR_SIZE_UNION
   CACHE_DESCRIPTOR_TYPE_UNION
END TYPE

'typedef struct _SYSTEM_LOGICAL_PROCESSOR_INFORMATION {
'    ULONG_PTR   ProcessorMask;
'    LOGICAL_PROCESSOR_RELATIONSHIP Relationship;
'    union {
'        struct {
'            BYTE  Flags;
'        } ProcessorCore;
'        struct {
'            DWORD NodeNumber;
'        } NumaNode;
'        CACHE_DESCRIPTOR Cache;
'        ULONGLONG  Reserved[2];
'    } DUMMYUNIONNAME;
'} SYSTEM_LOGICAL_PROCESSOR_INFORMATION, *PSYSTEM_LOGICAL_PROCESSOR_INFORMATION;

' // Size = 1 byte
TYPE SYSTEM_LOGICAL_PROCESSOR_INFORMATION_ProcessorCore BYTE
   Flags AS BYTE
END TYPE

' // Size = 4 bytes
TYPE SYSTEM_LOGICAL_PROCESSOR_INFORMATION_NumaMode DWORD
   NodeNumber AS DWORD
END TYPE

' // Size = 16 bytes
UNION SYSTEM_LOGICAL_PROCESSOR_INFORMATION_UNION
   SYSTEM_LOGICAL_PROCESSOR_INFORMATION_ProcessorCore
   SYSTEM_LOGICAL_PROCESSOR_INFORMATION_NumaMode
   Cache       AS CACHE_DESCRIPTOR
   Reserved(1) AS QUAD
END UNION

' // Size = 24 bytes
TYPE SYSTEM_LOGICAL_PROCESSOR_INFORMATION   ' Must be 8 byte aligned
   ProcessorMask AS DWORD
   Relationship  AS LONG
   SYSTEM_LOGICAL_PROCESSOR_INFORMATION_UNION
END TYPE

' // Size = 36 bytes
TYPE PROCESSOR_RELATIONSHIP BYTE
   Flags        AS BYTE   ' BYTE
   Reserved(20) AS BYTE   ' BYTE[21]
   GroupCount   AS WORD   ' WORD
   GroupMask(0) AS GROUP_AFFINITY   ' Variable-length array
END TYPE

' // Size = 36 bytes
TYPE NUMA_NODE_RELATIONSHIP BYTE
   NodeNumber   AS DWORD   ' DWORD
   Reserved(19) AS BYTE    ' BYTE[20]
   GroupMask    AS GROUP_AFFINITY
END TYPE

' // Size = 44 bytes
TYPE CACHE_RELATIONSHIP BYTE
   Level         AS BYTE    ' BYTE
   Associativity AS BYTE    ' BYTE
   LineSize      AS WORD    ' WORD
   CacheSize     AS DWORD   ' DWORD
   Type          AS LONG    ' PROCESSOR_CACHE_TYPE
   Reserved(19)  AS BYTE    ' BYTE[20]
   GroupMask     AS GROUP_AFFINITY
END TYPE

' // Size = 44 bytes
TYPE PROCESSOR_GROUP_INFO BYTE
   MaximumProcessorCount AS BYTE    ' BYTE
   ActiveProcessorCount  AS BYTE    ' BYTE
   Reserved(37)          AS BYTE    ' BYTE[38]
   ActiveProcessorMask   AS DWORD   ' KAFFINITY [DWORD_PTR]
END TYPE

' // Size = 68 bytes
TYPE GROUP_RELATIONSHIP BYTE
   MaximumGroupCount AS WORD                   ' WORD
   ActiveGroupCount  AS WORD                   ' WORD
   Reserved(19)      AS BYTE                   ' BYTE[20]
   GroupInfo(0)      AS PROCESSOR_GROUP_INFO   ' Variable-length array
END TYPE

' // Size = 68 bytes
UNION SYSTEM_LOGICAL_PROCESSOR_INFORMATION_EX_UNION
   Processor AS PROCESSOR_RELATIONSHIP
   NumaNode  AS NUMA_NODE_RELATIONSHIP
   Cache     AS CACHE_RELATIONSHIP
   Group     AS GROUP_RELATIONSHIP
END UNION

' // Size = 76 bytes
TYPE SYSTEM_LOGICAL_PROCESSOR_INFORMATION_EX BYTE
   Relationship AS LONG    ' LOGICAL_PROCESSOR_RELATIONSHIP
   Size         AS DWORD   ' DWORD
   SYSTEM_LOGICAL_PROCESSOR_INFORMATION_EX_UNION
END TYPE

'// end_wdm end_ntminiport

' // Size = 8 bytes
TYPE SYSTEM_PROCESSOR_CYCLE_TIME_INFORMATION QWORD
   CycleTime AS QUAD   ' DWORD64
END TYPE

%PROCESSOR_INTEL_386     = 386
%PROCESSOR_INTEL_486     = 486
%PROCESSOR_INTEL_PENTIUM = 586
%PROCESSOR_INTEL_IA64    = 2200
%PROCESSOR_AMD_X8664     = 8664
%PROCESSOR_MIPS_R4000    = 4000    ' incl R4101 & R3910 for Windows CE
%PROCESSOR_ALPHA_21064   = 21064
%PROCESSOR_PPC_601       = 601
%PROCESSOR_PPC_603       = 603
%PROCESSOR_PPC_604       = 604
%PROCESSOR_PPC_620       = 620
%PROCESSOR_HITACHI_SH3   = 10003   ' Windows CE
%PROCESSOR_HITACHI_SH3E  = 10004   ' Windows CE
%PROCESSOR_HITACHI_SH4   = 10005   ' Windows CE
%PROCESSOR_MOTOROLA_821  = 821     ' Windows CE
%PROCESSOR_SHx_SH3       = 103     ' Windows CE
%PROCESSOR_SHx_SH4       = 104     ' Windows CE
%PROCESSOR_STRONGARM     = 2577    ' Windows CE - = &HA11
%PROCESSOR_ARM720        = 1824    ' Windows CE - = &H720
%PROCESSOR_ARM820        = 2080    ' Windows CE - = &H820
%PROCESSOR_ARM920        = 2336    ' Windows CE - = &H920
%PROCESSOR_ARM_7TDMI     = 70001   ' Windows CE
%PROCESSOR_OPTIL         = &H494f  ' MSIL

%PROCESSOR_ARCHITECTURE_INTEL   = 0
%PROCESSOR_ARCHITECTURE_MIPS    = 1
%PROCESSOR_ARCHITECTURE_ALPHA   = 2
%PROCESSOR_ARCHITECTURE_PPC     = 3
%PROCESSOR_ARCHITECTURE_SHX     = 4
%PROCESSOR_ARCHITECTURE_ARM     = 5
%PROCESSOR_ARCHITECTURE_IA64    = 6
%PROCESSOR_ARCHITECTURE_ALPHA64 = 7
%PROCESSOR_ARCHITECTURE_MSIL    = 8
%PROCESSOR_ARCHITECTURE_AMD64           = 9
%PROCESSOR_ARCHITECTURE_IA32_ON_WIN64   = 10

%PROCESSOR_ARCHITECTURE_UNKNOWN = &HFFFF??

%PF_FLOATING_POINT_PRECISION_ERRATA = 0
%PF_FLOATING_POINT_EMULATED         = 1
%PF_COMPARE_EXCHANGE_DOUBLE         = 2
%PF_MMX_INSTRUCTIONS_AVAILABLE      = 3
%PF_PPC_MOVEMEM_64BIT_OK            = 4
%PF_ALPHA_BYTE_INSTRUCTIONS         = 5
%PF_XMMI_INSTRUCTIONS_AVAILABLE     = 6
%PF_3DNOW_INSTRUCTIONS_AVAILABLE    = 7
%PF_RDTSC_INSTRUCTION_AVAILABLE     = 8
%PF_PAE_ENABLED                     = 9
%PF_XMMI64_INSTRUCTIONS_AVAILABLE   = 10
%PF_SSE_DAZ_MODE_AVAILABLE          = 11
%PF_NX_ENABLED                      = 12
%PF_SSE3_INSTRUCTIONS_AVAILABLE     = 13
%PF_COMPARE_EXCHANGE128             = 14
%PF_COMPARE64_EXCHANGE128           = 15
%PF_CHANNELS_ENABLED                = 16
%PF_XSAVE_ENABLED                   = 17

'//
'// Known extended CPU state feature IDs
'//

%XSTATE_LEGACY_FLOATING_POINT       = 0
%XSTATE_LEGACY_SSE                  = 1
%XSTATE_GSSE                        = 2

%XSTATE_MASK_LEGACY_FLOATING_POINT  = 1   ' (1i64 << (XSTATE_LEGACY_FLOATING_POINT))
%XSTATE_MASK_LEGACY_SSE             = 2   ' (1i64 << (XSTATE_LEGACY_SSE))
%XSTATE_MASK_LEGACY                 = %XSTATE_MASK_LEGACY_FLOATING_POINT OR %XSTATE_MASK_LEGACY_SSE
%XSTATE_MASK_GSSE                   = 4   ' (1i64 << (XSTATE_GSSE))

%MAXIMUM_XSTATE_FEATURES            = 64

'//
'// Extended processor state configuration
'//

' // Size = 8 bytes
TYPE XSTATE_FEATURE DWORD
   Offset AS DWORD   ' DWORD
   Size   AS DWORD   ' DWORD
END TYPE

' // Size = 528 bytes
TYPE XSTATE_CONFIGURATION   ' Must be 8 byte aligned
   ' // Mask of enabled features
   EnabledFeatures AS QUAD   ' DWORD64
   ' // Total size of the save area
   Size            AS DWORD   ' DWORD
   OptimizedSave   AS BIT * 1 IN DWORD
   ' // List of features (
   Features(%MAXIMUM_XSTATE_FEATURES - 1) AS XSTATE_FEATURE
END TYPE

UNION MEMORY_BASIC_INFORMATION_STATE_UNION
   State             AS DWORD   ' DWORD
   ' // For compatibility with the PB declares
   nState            AS DWORD   ' DWORD
END UNION

UNION MEMORY_BASIC_INFORMATION_TYPE_UNION
   Type              AS DWORD   ' DWORD
   ' // For compatibility with the PB declares
   nType             AS DWORD   ' DWORD
END UNION

' // Size = 28 bytes
TYPE MEMORY_BASIC_INFORMATION DWORD
   BaseAddress       AS DWORD   ' PVOID
   AllocationBase    AS DWORD   ' PVOID
   AllocationProtect AS DWORD   ' DWORD
   RegionSize        AS DWORD   ' SIZE_T
   MEMORY_BASIC_INFORMATION_STATE_UNION
   Protect           AS DWORD   ' DWORD
   MEMORY_BASIC_INFORMATION_TYPE_UNION
END TYPE

' // Size = 28 bytes
TYPE MEMORY_BASIC_INFORMATION32 DWORD
   MEMORY_BASIC_INFORMATION
END TYPE

' // Size = 48 bytes
TYPE MEMORY_BASIC_INFORMATION64   ' 16 byte alignment
   BaseAddress       AS QUAD    ' ULONGLONG
   AllocationBase    AS QUAD    ' ULONGLONG
   AllocationProtect AS DWORD   ' DWORD
   alignment1        AS DWORD   ' DWORD
   RegionSize        AS QUAD    ' ULONGLONG
   State             AS DWORD   ' DWORD
   Protect           AS DWORD   ' DWORD
   Type              AS DWORD   ' DWORD
   alignment2        AS DWORD   ' DWORD
END TYPE

%SECTION_QUERY                = &H0001???
%SECTION_MAP_WRITE            = &H0002???
%SECTION_MAP_READ             = &H0004???
%SECTION_MAP_EXECUTE          = &H0008???
%SECTION_EXTEND_SIZE          = &H0010???
%SECTION_MAP_EXECUTE_EXPLICIT = &H0020???   ' // not included in SECTION_ALL_ACCESS

%SECTION_ALL_ACCESS  = %STANDARD_RIGHTS_REQUIRED OR %SECTION_QUERY _
                       OR %SECTION_MAP_WRITE _
                       OR %SECTION_MAP_READ _
                       OR %SECTION_MAP_EXECUTE _
                       OR %SECTION_EXTEND_SIZE

%SESSION_QUERY_ACCESS  = &H0001???
%SESSION_MODIFY_ACCESS = &H0002???

%SESSION_ALL_ACCESS    = %STANDARD_RIGHTS_REQUIRED OR _
                         %SESSION_QUERY_ACCESS     OR _
                         %SESSION_MODIFY_ACCESS

%PAGE_NOACCESS          = &H01???
%PAGE_READONLY          = &H02???
%PAGE_READWRITE         = &H04???
%PAGE_WRITECOPY         = &H08???
%PAGE_EXECUTE           = &H10???
%PAGE_EXECUTE_READ      = &H20???
%PAGE_EXECUTE_READWRITE = &H40???
%PAGE_EXECUTE_WRITECOPY = &H80???
%PAGE_GUARD             = &H100???
%PAGE_NOCACHE           = &H200???
%PAGE_WRITECOMBINE      = &H400???
%MEM_COMMIT             = &H1000???
%MEM_RESERVE            = &H2000???
%MEM_DECOMMIT           = &H4000???
%MEM_RELEASE            = &H8000???
%MEM_FREE               = &H10000???
%MEM_PRIVATE            = &H20000???
%MEM_MAPPED             = &H40000???
%MEM_RESET              = &H80000???
%MEM_TOP_DOWN           = &H100000???
%MEM_WRITE_WATCH        = &H200000???
%MEM_PHYSICAL           = &H400000???
%MEM_ROTATE             = &H800000???
%MEM_LARGE_PAGES        = &H20000000???
%MEM_4MB_PAGES          = &H80000000???
%SEC_FILE               = &H800000???
%SEC_IMAGE              = &H01000000???
'%SEC_VLM                = &H02000000???
%SEC_PROTECTED_IMAGE    = &H2000000???
%SEC_RESERVE            = &H04000000???
%SEC_COMMIT             = &H08000000???
%SEC_NOCACHE            = &H10000000???
%SEC_WRITECOMBINE       = &H40000000???
%SEC_LARGE_PAGES        = &H80000000???
%MEM_IMAGE              = %SEC_IMAGE
%WRITE_WATCH_FLAG_RESET = &H01???

'//
'// Define access rights to files and directories
'//

'//
'// The FILE_READ_DATA and FILE_WRITE_DATA constants are also defined in
'// devioctl.h as FILE_READ_ACCESS and FILE_WRITE_ACCESS. The values for these
'// constants *MUST* always be in sync.
'// The values are redefined in devioctl.h because they must be available to
'// both DOS and NT.
'//

%FILE_READ_DATA            = &H0001???    ' file & pipe
%FILE_LIST_DIRECTORY       = &H0001???    ' directory

%FILE_WRITE_DATA           = &H0002???    ' file & pipe
%FILE_ADD_FILE             = &H0002???    ' directory

%FILE_APPEND_DATA          = &H0004???    ' file
%FILE_ADD_SUBDIRECTORY     = &H0004???    ' directory
%FILE_CREATE_PIPE_INSTANCE = &H0004???    ' named pipe

%FILE_READ_EA              = &H0008???    ' file & directory

%FILE_WRITE_EA             = &H0010???    ' file & directory

%FILE_EXECUTE              = &H0020???    ' file
%FILE_TRAVERSE             = &H0020???    ' directory

%FILE_DELETE_CHILD         = &H0040???    ' directory

%FILE_READ_ATTRIBUTES      = &H0080???    ' all

%FILE_WRITE_ATTRIBUTES     = &H0100???    ' all

%FILE_ALL_ACCESS = %STANDARD_RIGHTS_REQUIRED OR %SYNCHRONIZE OR &H1FF

%FILE_GENERIC_READ =   %STANDARD_RIGHTS_READ OR _
                       %FILE_READ_DATA       OR _
                       %FILE_READ_ATTRIBUTES OR _
                       %FILE_READ_EA         OR _
                       %SYNCHRONIZE

%FILE_GENERIC_WRITE =  %STANDARD_RIGHTS_WRITE OR _
                       %FILE_WRITE_DATA       OR _
                       %FILE_WRITE_ATTRIBUTES OR _
                       %FILE_WRITE_EA         OR _
                       %FILE_APPEND_DATA      OR _
                       %SYNCHRONIZE

%FILE_GENERIC_EXECUTE = %STANDARD_RIGHTS_EXECUTE OR _
                        %FILE_READ_ATTRIBUTES    OR _
                        %FILE_EXECUTE            OR _
                        %SYNCHRONIZE

%FILE_SHARE_READ                    = &H00000001???
%FILE_SHARE_WRITE                   = &H00000002???
%FILE_SHARE_DELETE                  = &H00000004???
%FILE_ATTRIBUTE_READONLY            = &H00000001???
%FILE_ATTRIBUTE_HIDDEN              = &H00000002???
%FILE_ATTRIBUTE_SYSTEM              = &H00000004???
%FILE_ATTRIBUTE_DIRECTORY           = &H00000010???
%FILE_ATTRIBUTE_ARCHIVE             = &H00000020???
%FILE_ATTRIBUTE_DEVICE              = &H00000040???
%FILE_ATTRIBUTE_NORMAL              = &H00000080???
%FILE_ATTRIBUTE_TEMPORARY           = &H00000100???
%FILE_ATTRIBUTE_SPARSE_FILE         = &H00000200???
%FILE_ATTRIBUTE_REPARSE_POINT       = &H00000400???
%FILE_ATTRIBUTE_COMPRESSED          = &H00000800???
%FILE_ATTRIBUTE_OFFLINE             = &H00001000???
%FILE_ATTRIBUTE_NOT_CONTENT_INDEXED = &H00002000???
%FILE_ATTRIBUTE_ENCRYPTED           = &H00004000???
%FILE_ATTRIBUTE_VIRTUAL             = &H00010000???
%FILE_NOTIFY_CHANGE_FILE_NAME       = &H00000001???
%FILE_NOTIFY_CHANGE_DIR_NAME        = &H00000002???
%FILE_NOTIFY_CHANGE_ATTRIBUTES      = &H00000004???
%FILE_NOTIFY_CHANGE_SIZE            = &H00000008???
%FILE_NOTIFY_CHANGE_LAST_WRITE      = &H00000010???
%FILE_NOTIFY_CHANGE_LAST_ACCESS     = &H00000020???
%FILE_NOTIFY_CHANGE_CREATION        = &H00000040???
%FILE_NOTIFY_CHANGE_SECURITY        = &H00000100???
%FILE_ACTION_ADDED                  = &H00000001???
%FILE_ACTION_REMOVED                = &H00000002???
%FILE_ACTION_MODIFIED               = &H00000003???
%FILE_ACTION_RENAMED_OLD_NAME       = &H00000004???
%FILE_ACTION_RENAMED_NEW_NAME       = &H00000005???
%MAILSLOT_NO_MESSAGE                = &HFFFFFFFF???
%MAILSLOT_WAIT_FOREVER              = &HFFFFFFFF???
%FILE_CASE_SENSITIVE_SEARCH         = &H00000001???
%FILE_CASE_PRESERVED_NAMES          = &H00000002???
%FILE_UNICODE_ON_DISK               = &H00000004???
%FILE_PERSISTENT_ACLS               = &H00000008???
%FILE_FILE_COMPRESSION              = &H00000010???
%FILE_VOLUME_QUOTAS                 = &H00000020???
%FILE_SUPPORTS_SPARSE_FILES         = &H00000040???
%FILE_SUPPORTS_REPARSE_POINTS       = &H00000080???
%FILE_SUPPORTS_REMOTE_STORAGE       = &H00000100???
%FILE_VOLUME_IS_COMPRESSED          = &H00008000???
%FILE_SUPPORTS_OBJECT_IDS           = &H00010000???
%FILE_SUPPORTS_ENCRYPTION           = &H00020000???
%FILE_NAMED_STREAMS                 = &H00040000???
%FILE_READ_ONLY_VOLUME              = &H00080000???
%FILE_SEQUENTIAL_WRITE_ONCE         = &H00100000???
%FILE_SUPPORTS_TRANSACTIONS         = &H00200000???
%FILE_SUPPORTS_HARD_LINKS           = &H00400000???
%FILE_SUPPORTS_EXTENDED_ATTRIBUTES  = &H00800000???
%FILE_SUPPORTS_OPEN_BY_FILE_ID      = &H01000000???
%FILE_SUPPORTS_USN_JOURNAL          = &H02000000???

'//
'// Define the file notification information structure
'//

UNION FILE_NOTIFY_INFORMATION_FILENAME_UNION DWORD
   FileName(0)     AS WORD    ' WCHAR FileName[1]
   ' // For compatibility with the PB declares
   FileName        AS WSTRINGZ * 1
END UNION

' // Size = 16 bytes
TYPE FILE_NOTIFY_INFORMATION DWORD
   NextEntryOffset AS DWORD   ' DWORD
   Action          AS DWORD   ' DWORD
   FileNameLength  AS DWORD   ' DWORD
   FILE_NOTIFY_INFORMATION_FILENAME_UNION
END TYPE

'//
'// Define segement buffer structure for scatter/gather read/write.
'//

' // Size = 8 bytes
UNION FILE_SEGMENT_ELEMENT QWORD
   Buffer    AS QUAD   ' PVOID64
   Alignment AS QUAD   ' ULONGLONG
END UNION

'//
'// The reparse GUID structure is used by all 3rd party layered drivers to
'// store data in a reparse point. For non-Microsoft tags, The GUID field
'// cannot be GUID_NULL.
'// The constraints on reparse tags are defined below.
'// Microsoft tags can also be used with this format of the reparse point buffer.
'//

'typedef struct _REPARSE_GUID_DATA_BUFFER {
'    DWORD  ReparseTag;
'    WORD   ReparseDataLength;
'    WORD   Reserved;
'    GUID   ReparseGuid;
'    struct {
'        BYTE   DataBuffer[1];
'    } GenericReparseBuffer;
'} REPARSE_GUID_DATA_BUFFER, *PREPARSE_GUID_DATA_BUFFER;

' // Size = 28 bytes
TYPE REPARSE_GUID_DATA_BUFFER
   ReparseTag        AS DWORD
   ReparseDataLength AS WORD
   Reserved          AS WORD
   ReparseGuid       AS GUID
   DataBuffer(3)     AS BYTE   ' BYTE   DataBuffer[1]
   ' Note: We are using DataBuffer(3) instead of DataBuffer(0) to keep DWORD alignment
END TYPE

'#define REPARSE_GUID_DATA_BUFFER_HEADER_SIZE   FIELD_OFFSET(REPARSE_GUID_DATA_BUFFER, GenericReparseBuffer)
%REPARSE_GUID_DATA_BUFFER_HEADER_SIZE = 24

'//
'// Maximum allowed size of the reparse data.
'//

'#define MAXIMUM_REPARSE_DATA_BUFFER_SIZE      ( 16 * 1024 )
%MAXIMUM_REPARSE_DATA_BUFFER_SIZE = 16 * 1024

'//
'// Predefined reparse tags.
'// These tags need to avoid conflicting with IO_REMOUNT defined in ntos\inc\io.h
'//

%IO_REPARSE_TAG_RESERVED_ZERO = 0
%IO_REPARSE_TAG_RESERVED_ONE  = 1

'//
'// The value of the following constant needs to satisfy the following conditions:
'//  (1) Be at least as large as the largest of the reserved tags.
'//  (2) Be strictly smaller than all the tags in use.
'//

%IO_REPARSE_TAG_RESERVED_RANGE = %IO_REPARSE_TAG_RESERVED_ONE

'//
'// The reparse tags are a DWORD. The 32 bits are laid out as follows:
'//
'//   3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1 1 1
'//   1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0
'//  +-+-+-+-+-----------------------+-------------------------------+
'//  |M|R|N|R|     Reserved bits     |       Reparse Tag Value       |
'//  +-+-+-+-+-----------------------+-------------------------------+
'//
'// M is the Microsoft bit. When set to 1, it denotes a tag owned by Microsoft.
'//   All ISVs must use a tag with a 0 in this position.
'//   Note: If a Microsoft tag is used by non-Microsoft software, the
'//   behavior is not defined.
'//
'// R is reserved.  Must be zero for non-Microsoft tags.
'//
'// N is name surrogate. When set to 1, the file represents another named
'//   entity in the system.
'//
'// The M and N bits are OR-able.
'// The following macros check for the M and N bit values:
'//

'//
'// Macro to determine whether a reparse point tag corresponds to a tag
'// owned by Microsoft.
'//

MACRO IsReparseTagMicrosoft(tag) = (tag AND &H80000000???)

'//
'// Macro to determine whether a reparse point tag is a name surrogate
'//

MACRO IsReparseTagNameSurrogate(tag) = (tag AND &H20000000???)

%IO_REPARSE_TAG_MOUNT_POINT    = &HA0000003???
%IO_REPARSE_TAG_HSM            = &HC0000004???
%IO_REPARSE_TAG_HSM2           = &H80000006???
%IO_REPARSE_TAG_SIS            = &H80000007???
%IO_REPARSE_TAG_WIM            = &H80000008???
%IO_REPARSE_TAG_CSV            = &H80000009???
%IO_REPARSE_TAG_DFS            = &H8000000A???
%IO_REPARSE_TAG_SYMLINK        = &HA000000C???
%IO_REPARSE_TAG_DFSR           = &H80000012???

'//
'// I/O Completion Specific Access Rights.
'//

%IO_COMPLETION_MODIFY_STATE    = &H0002???
%IO_COMPLETION_ALL_ACCESS      = %STANDARD_RIGHTS_REQUIRED OR %SYNCHRONIZE OR &H3

'//
'// Object Manager Symbolic Link Specific Access Rights.
'//

%DUPLICATE_CLOSE_SOURCE        = &H00000001???
%DUPLICATE_SAME_ACCESS         = &H00000002???

'//
'// =========================================
'// Define GUIDs which represent well-known power schemes
'// =========================================
'//

'//
'// Maximum Power Savings - indicates that very aggressive power savings measures will be used to help
'//                         stretch battery life.
'//
'// {a1841308-3541-4fab-bc81-f71556f20b4a}
'//
$GUID_MAX_POWER_SAVINGS = GUID$("{a1841308-3541-4fab-bc81-f71556f20b4a}")

'//
'// No Power Savings - indicates that almost no power savings measures will be used.
'//
'// {8c5e7fda-e8bf-4a96-9a85-a6e23a8c635c}
'//
$GUID_MIN_POWER_SAVINGS = GUID$("{8c5e7fda-e8bf-4a96-9a85-a6e23a8c635c}")

'//
'// Typical Power Savings - indicates that fairly aggressive power savings measures will be used.
'//
'// {381b4222-f694-41f0-9685-ff5bb260df2e}
'//
$GUID_TYPICAL_POWER_SAVINGS = GUID$("{381b4222-f694-41f0-9685-ff5bb260df2e}")

'//
'// This is a special GUID that represents "no subgroup" of settings.  That is, it indicates
'// that settings that are in the root of the power policy hierarchy as opposed to settings
'// that are buried under a subgroup of settings.  This should be used when querying for
'// power settings that may not fall into a subgroup.
'//
$NO_SUBGROUP_GUID = GUID$("{FEA3413E-7E05-4911-9A71-700331F1C294}")

'//
'// This is a special GUID that represents "every power scheme".  That is, it indicates
'// that any write to this power scheme should be reflected to every scheme present.
'// This allows users to write a single setting once and have it apply to all schemes.  They
'// can then apply custom settings to specific power schemes that they care about.
'//
$ALL_POWERSCHEMES_GUID = GUID$("{68A1E95E-13EA-41E1-8011-0C496CA490B0}")

'//
'// This is a special GUID that represents a 'personality' that each power scheme will have.
'// In other words, each power scheme will have this key indicating "I'm most like *this* base
'// power scheme."  This individual setting will have one of three settings:
'// GUID_MAX_POWER_SAVINGS
'// GUID_MIN_POWER_SAVINGS
'// GUID_TYPICAL_POWER_SAVINGS
'//
'// This allows several features:
'// 1. Drivers and applications can register for notification of this GUID.  So when this power
'//    scheme is activiated, this GUID's setting will be sent across the system and drivers/applications
'//    can see "GUID_MAX_POWER_SAVINGS" which will tell them in a generic fashion "get real aggressive
'//    about conserving power".
'// 2. UserB may install a driver or application which creates power settings, and UserB may modify
'//    those power settings.  Now UserA logs in.  How does he see those settings?  They simply don't
'//    exist in his private power key.  Well they do exist over in the system power key.  When we
'//    enumerate all the power settings in this system power key and don't find a corresponding entry
'//    in the user's private power key, then we can go look at this "personality" key in the users
'//    power scheme.  We can then go get a default value for the power setting, depending on which
'//    "personality" power scheme is being operated on.  Here's an example:
'//    A. UserB installs an application that creates a power setting Seetting1
'//    B. UserB changes Setting1 to have a value of 50 because that's one of the possible settings
'//       available for setting1.
'//    C. UserB logs out
'//    D. UserA logs in and his active power scheme is some custom scheme that was derived from
'//       the GUID_TYPICAL_POWER_SAVINGS.  But remember that UserA has no setting1 in his
'//       private power key.
'//    E. When activating UserA's selected power scheme, all power settings in the system power key will
'//       be enumerated (including Setting1).
'//    F. The power manager will see that UserA has no Setting1 power setting in his private power scheme.
'//    G. The power manager will query UserA's power scheme for its personality and retrieve
'//       GUID_TYPICAL_POWER_SAVINGS.
'//    H. The power manager then looks in Setting1 in the system power key and looks in its set of default
'//       values for the corresponding value for GUID_TYPICAL_POWER_SAVINGS power schemes.
'//    I. This derived power setting is applied.
$GUID_POWERSCHEME_PERSONALITY = GUID$("{245D8541-3943-4422-B025-13A784F679B7}")

'//
'// Define a special GUID which will be used to define the active power scheme.
'// User will register for this power setting GUID, and when the active power
'// scheme changes, they'll get a callback where the payload is the GUID
'// representing the active powerscheme.
'// ( 31F9F286-5084-42FE-B720-2B0264993763 }
'//
$GUID_ACTIVE_POWERSCHEME = GUID$("{31F9F286-5084-42FE-B720-2B0264993763}")

'//
'// =========================================
'// Define GUIDs which represent well-known power settings
'// =========================================
'//

'// Video settings
'// --------------
'//
'// Specifies the subgroup which will contain all of the video
'// settings for a single policy.
'//
$GUID_VIDEO_SUBGROUP = GUID$("{7516B95F-F776-4464-8C53-06167F40CC99}")

'//
'// Specifies (in seconds) how long we wait after the last user input has been
'// recieved before we power off the video.
'//
$GUID_VIDEO_POWERDOWN_TIMEOUT = GUID$("{3C0BC021-C8A8-4E07-A973-6B14CBCB2B7E}")

'//
'// Specifies whether adaptive display dimming is turned on or off.
'// 82DBCF2D-CD67-40C5-BFDC-9F1A5CCD4663
'//
$GUID_VIDEO_ANNOYANCE_TIMEOUT = GUID$("{82DBCF2D-CD67-40C5-BFDC-9F1A5CCD4663}")

'//
'// Specifies how much adaptive dim time out will be increased by.
'// EED904DF-B142-4183-B10B-5A1197A37864
'//
$GUID_VIDEO_ADAPTIVE_PERCENT_INCREASE = GUID$("{EED904DF-B142-4183-B10B-5A1197A37864}")

'//
'// Specifies (in seconds) how long we wait after the last user input has been
'// recieved before we dim the video.
'//
$GUID_VIDEO_DIM_TIMEOUT = GUID$("{17AAA29B-8B43-4B94-AAFE-35F64DAAF1EE}")

'//
'// Specifies if the operating system should use adaptive timers (based on
'// previous behavior) to power down the video,
'//
$GUID_VIDEO_ADAPTIVE_POWERDOWN = GUID$("{90959D22-D6A1-49B9-AF93-BCE885AD335B}")

'//
'// Specifies if the monitor is currently being powered or not.
'// 02731015-4510-4526-99E6-E5A17EBD1AEA
'//
$GUID_MONITOR_POWER_ON = GUID$("{02731015-4510-4526-99E6-E5A17EBD1AEA}")

'//
'// Monitor brightness policy when in normal state
'// {aded5e82-b909-4619-9949-f5d71dac0bcb}
$GUID_DEVICE_POWER_POLICY_VIDEO_BRIGHTNESS = GUID$("{aded5e82-b909-4619-9949-f5d71dac0bcb}")

'//
'//
'// Monitor brightness policy when in dim state
'// {f1fbfde2-a960-4165-9f88-50667911ce96}
$GUID_DEVICE_POWER_POLICY_VIDEO_DIM_BRIGHTNESS = GUID$("{f1fbfde2-a960-4165-9f88-50667911ce96}")

'//
'// Current Monitor brightness
'// {8ffee2c6-2d01-46be-adb9-398addc5b4ff}
$GUID_VIDEO_CURRENT_MONITOR_BRIGHTNESS = GUID$("{8ffee2c6-2d01-46be-adb9-398addc5b4ff}")

'//
'// Specifies if the operating system should use ambient light sensor to change
'// disply brightness adatively.
'// {FBD9AA66-9553-4097-BA44-ED6E9D65EAB8}
$GUID_VIDEO_ADAPTIVE_DISPLAY_BRIGHTNESS = GUID$("{FBD9AA66-9553-4097-BA44-ED6E9D65EAB8}")

'//
'// Specifies a change in the session's display state.
'// 73A5E93A-5BB1-4F93-895B-DBD0DA855967
'//
'// N.B. This is a session-specific notification, sent only to interactive
'//      session registrants. Session 0 and kernel mode consumers do not receive
'//      this notification.
$GUID_SESSION_DISPLAY_STATE = GUID$("{73A5E93A-5BB1-4F93-895B-DBD0DA855967}")

'//
'// Specifies a change in the current monitor's display state.
'// 6fe69556-704a-47a0-8f24-c28d936fda47
'//
$GUID_CONSOLE_DISPLAY_STATE = GUID$("{6fe69556-704a-47a0-8f24-c28d936fda47}")

'//
'// Defines a guid for enabling/disabling the ability to create display required
'// power requests.
'//
'// {A9CEB8DA-CD46-44FB-A98B-02AF69DE4623}
'//
$GUID_ALLOW_DISPLAY_REQUIRED = GUID$("{A9CEB8DA-CD46-44FB-A98B-02AF69DE4623}")


'// Harddisk settings
'// -----------------
'//
'// Specifies the subgroup which will contain all of the harddisk
'// settings for a single policy.
'//
$GUID_DISK_SUBGROUP = GUID$("{0012EE47-9041-4B5D-9B77-535FBA8B1442}")

'//
'// Specifies (in seconds) how long we wait after the last disk access
'// before we power off the disk.
'//
$GUID_DISK_POWERDOWN_TIMEOUT = GUID$("{6738E2C4-E8A5-4A42-B16A-E040E769756E}")

'//
'// Specifies the amount of contiguous disk activity time to ignore when
'// calculating disk idleness.
'//
'// 80e3c60e-bb94-4ad8-bbe0-0d3195efc663
'//
$GUID_DISK_BURST_IGNORE_THRESHOLD = GUID$("{80E3C60E-BB94-4AD8-BBE0-0D3195EFC663}")

'//
'// Specifies if the operating system should use adaptive timers (based on
'// previous behavior) to power down the disk,
'//
$GUID_DISK_ADAPTIVE_POWERDOWN = GUID$("{396A32E1-499A-40B2-9124-A96AFE707667}")

'// System sleep settings
'// ---------------------
'//
'// Specifies the subgroup which will contain all of the sleep
'// settings for a single policy.
'// { 238C9FA8-0AAD-41ED-83F4-97BE242C8F20 }
'//
$GUID_SLEEP_SUBGROUP = GUID$("{238C9FA8-0AAD-41ED-83F4-97BE242C8F20}")

'//
'// Specifies an idle treshold percentage (0-100). The system must be this idle
'// over a period of time in order to idle to sleep.
'//
'// N.B. DEPRECATED IN WINDOWS 6.1
'//
$GUID_SLEEP_IDLE_THRESHOLD = GUID$("{81cd32e0-7833-44f3-8737-7081f38d1f70}")

'//
'// Specifies (in seconds) how long we wait after the system is deemed
'// "idle" before moving to standby (S1, S2 or S3).
'//
$GUID_STANDBY_TIMEOUT = GUID$("{29F6C1DB-86DA-48C5-9FDB-F2B67B1F44DA}")

'//
'// Specifies (in seconds) how long the system should go back to sleep after
'// waking unattended. 0 indicates that the standard standby/hibernate idle
'// policy should be used instead.
'//
'// {7bc4a2f9-d8fc-4469-b07b-33eb785aaca0}
'//
$GUID_UNATTEND_SLEEP_TIMEOUT = GUID$("{7BC4A2F9-D8FC-4469-B07B-33EB785AACA0}")

'//
'// Specifies (in seconds) how long we wait after the system is deemed
'// "idle" before moving to hibernate (S4).
'//
$GUID_HIBERNATE_TIMEOUT = GUID$("{9D7815A6-7EE4-497E-8888-515A05F02364}")

'//
'// Specifies whether or not Fast S4 should be enabled if the system supports it
'// 94AC6D29-73CE-41A6-809F-6363BA21B47E
'//
$GUID_HIBERNATE_FASTS4_POLICY = GUID$("{94AC6D29-73CE-41A6-809F-6363BA21B47E}")

'//
'// Define a GUID for controlling the criticality of sleep state transitions.
'// Critical sleep transitions do not query applications, services or drivers
'// before transitioning the platform to a sleep state.
'//
'// {B7A27025-E569-46c2-A504-2B96CAD225A1}
'//
$GUID_CRITICAL_POWER_TRANSITION = GUID$("{B7A27025-E569-46c2-A504-2B96CAD225A1}")

'//
'// Specifies if the system is entering or exiting 'away mode'.
'// 98A7F580-01F7-48AA-9C0F-44352C29E5C0
'//
$GUID_SYSTEM_AWAYMODE = GUID$("{98A7F580-01F7-48AA-9C0F-44352C29E5C0}")

'// Specify whether away mode is allowed
'//
'// {25DFA149-5DD1-4736-B5AB-E8A37B5B8187}
'//
$GUID_ALLOW_AWAYMODE = GUID$("{25DFA149-5DD1-4736-B5AB-E8A37B5B8187}")

'//
'// Defines a guid for enabling/disabling standby (S1-S3) states. This does not
'// affect hibernation (S4).
'//
'// {abfc2519-3608-4c2a-94ea-171b0ed546ab}
'//
$GUID_ALLOW_STANDBY_STATES = GUID$("{abfc2519-3608-4c2a-94ea-171b0ed546ab}")

'//
'// Defines a guid for enabling/disabling the ability to wake via RTC.
'//
'// {BD3B718A-0680-4D9D-8AB2-E1D2B4AC806D}
'//
$GUID_ALLOW_RTC_WAKE = GUID$("{BD3B718A-0680-4D9D-8AB2-E1D2B4AC806D}")

'//
'// Defines a guid for enabling/disabling the ability to create system required
'// power requests.
'//
'// {A4B195F5-8225-47D8-8012-9D41369786E2}
'//
$GUID_ALLOW_SYSTEM_REQUIRED = GUID$("{A4B195F5-8225-47D8-8012-9D41369786E2}")

'// System button actions
'// ---------------------
'//
'//
'// Specifies the subgroup which will contain all of the system button
'// settings for a single policy.
'//
$GUID_SYSTEM_BUTTON_SUBGROUP = GUID$("{4F971E89-EEBD-4455-A8DE-9E59040E7347}")

'// Specifies (in a POWER_ACTION_POLICY structure) the appropriate action to
'// take when the system power button is pressed.
'//
$GUID_POWERBUTTON_ACTION = GUID$("{7648EFA3-DD9C-4E3E-B566-50F929386280}")
$GUID_POWERBUTTON_ACTION_FLAGS = GUID$("{857E7FAC-034B-4704-ABB1-BCA54AA31478}")

'//
'// Specifies (in a POWER_ACTION_POLICY structure) the appropriate action to
'// take when the system sleep button is pressed.
'//
$GUID_SLEEPBUTTON_ACTION = GUID$("{96996BC0-AD50-47EC-923B-6F41874DD9EB}")
$GUID_SLEEPBUTTON_ACTION_FLAGS = GUID$("{2A160AB1-B69D-4743-B718-BF1441D5E493}")

'//
'// Specifies (in a POWER_ACTION_POLICY structure) the appropriate action to
'// take when the system sleep button is pressed.
'// { A7066653-8D6C-40A8-910E-A1F54B84C7E5 }
'//
$GUID_USERINTERFACEBUTTON_ACTION = GUID$("{A7066653-8D6C-40A8-910E-A1F54B84C7E5}")

'//
'// Specifies (in a POWER_ACTION_POLICY structure) the appropriate action to
'// take when the system lid is closed.
'//
$GUID_LIDCLOSE_ACTION = GUID$("{5CA83367-6E45-459F-A27B-476B1D01C936}")
$GUID_LIDCLOSE_ACTION_FLAGS = GUID$("{97E969AC-0D6C-4D08-927C-D7BD7AD7857B}")
$GUID_LIDOPEN_POWERSTATE = GUID$("{99FF10E7-23B1-4C07-A9D1-5C3206D741B4}")

'// Battery Discharge Settings
'// --------------------------
'//
'// Specifies the subgroup which will contain all of the battery discharge
'// settings for a single policy.
'//
$GUID_BATTERY_SUBGROUP = GUID$("{E73A048D-BF27-4F12-9731-8B2076E8891F}")

'//
'// 4 battery discharge alarm settings.
'//
'// GUID_BATTERY_DISCHARGE_ACTION_x - This is the action to take.  It is a value
'//                                   of type POWER_ACTION
'// GUID_BATTERY_DISCHARGE_LEVEL_x  - This is the battery level (%)
'// GUID_BATTERY_DISCHARGE_FLAGS_x  - Flags defined below:
'//                                   POWER_ACTION_POLICY->EventCode flags
'//                                   BATTERY_DISCHARGE_FLAGS_EVENTCODE_MASK
'//                                   BATTERY_DISCHARGE_FLAGS_ENABLE
$GUID_BATTERY_DISCHARGE_ACTION_0 = GUID$("{637EA02F-BBCB-4015-8E2C-A1C7B9C0B546}")
$GUID_BATTERY_DISCHARGE_LEVEL_0 = GUID$("{9A66D8D7-4FF7-4EF9-B5A2-5A326CA2A469}")
$GUID_BATTERY_DISCHARGE_FLAGS_0 = GUID$("{5dbb7c9f-38e9-40d2-9749-4f8a0e9f640f}")

$GUID_BATTERY_DISCHARGE_ACTION_1 = GUID$("{D8742DCB-3E6A-4B3C-B3FE-374623CDCF06}")
$GUID_BATTERY_DISCHARGE_LEVEL_1 = GUID$("{8183BA9A-E910-48DA-8769-14AE6DC1170A}")
$GUID_BATTERY_DISCHARGE_FLAGS_1 = GUID$("{bcded951-187b-4d05-bccc-f7e51960c258}")

$GUID_BATTERY_DISCHARGE_ACTION_2 = GUID$("{421CBA38-1A8E-4881-AC89-E33A8B04ECE4}")
$GUID_BATTERY_DISCHARGE_LEVEL_2 = GUID$("{07A07CA2-ADAF-40D7-B077-533AADED1BFA}")
$GUID_BATTERY_DISCHARGE_FLAGS_2 = GUID$("{7fd2f0c4-feb7-4da3-8117-e3fbedc46582}")

$GUID_BATTERY_DISCHARGE_ACTION_3 = GUID$("{80472613-9780-455E-B308-72D3003CF2F8}")
$GUID_BATTERY_DISCHARGE_LEVEL_3 = GUID$("{58AFD5A6-C2DD-47D2-9FBF-EF70CC5C5965}")
$GUID_BATTERY_DISCHARGE_FLAGS_3 = GUID$("{73613ccf-dbfa-4279-8356-4935f6bf62f3}")

'// Processor power settings
'// ------------------------
'//

'// Specifies the subgroup which will contain all of the processor
'// settings for a single policy.
'//
$GUID_PROCESSOR_SETTINGS_SUBGROUP = GUID$("{54533251-82BE-4824-96C1-47B60B740D00}")

'//
'// Specifies various attributes that control processor performance/throttle
'// states.
'//
$GUID_PROCESSOR_THROTTLE_POLICY = GUID$("{57027304-4AF6-4104-9260-E3D95248FC36}")

%PERFSTATE_POLICY_CHANGE_IDEAL  = 0
%PERFSTATE_POLICY_CHANGE_SINGLE = 1
%PERFSTATE_POLICY_CHANGE_ROCKET = 2
%PERFSTATE_POLICY_CHANGE_MAX = %PERFSTATE_POLICY_CHANGE_ROCKET

'//
'// Specifies a percentage (between 0 and 100) that the processor frequency
'// should never go above.  For example, if this value is set to 80, then
'// the processor frequency will never be throttled above 80 percent of its
'// maximum frequency by the system.
'//
$GUID_PROCESSOR_THROTTLE_MAXIMUM = GUID$("{BC5038F7-23E0-4960-96DA-33ABAF5935EC}")

'//
'// Specifies a percentage (between 0 and 100) that the processor frequency
'// should not drop below.  For example, if this value is set to 50, then the
'// processor frequency will never be throttled below 50 percent of its
'// maximum frequency by the system.
'//
$GUID_PROCESSOR_THROTTLE_MINIMUM = GUID$("{893DEE8E-2BEF-41E0-89C6-B55D0929964C}")

'//
'// Specifies whether throttle states are allowed to be used even when
'// performance states are available.
'//
'// {3b04d4fd-1cc7-4f23-ab1c-d1337819c4bb}
'//
$GUID_PROCESSOR_ALLOW_THROTTLING = GUID$("{3B04D4FD-1CC7-4F23-AB1C-D1337819C4BB}")

'//
'// Specifies processor power settings for CState policy data
'// {68F262A7-F621-4069-B9A5-4874169BE23C}
'//
$GUID_PROCESSOR_IDLESTATE_POLICY = GUID$("{68F262A7-F621-4069-B9A5-4874169BE23C}")

'//
'// Specifies processor power settings for PerfState policy data
'// {BBDC3814-18E9-4463-8A55-D197327C45C0}
'//
$GUID_PROCESSOR_PERFSTATE_POLICY = GUID$("{BBDC3814-18E9-4463-8A55-D197327C45C0}")

'//
'// Specifies the increase busy percentage threshold that must be met before
'// increasing the processor performance state.
'//
'// {06cadf0e-64ed-448a-8927-ce7bf90eb35d}
'//
$GUID_PROCESSOR_PERF_INCREASE_THRESHOLD = GUID$("{06cadf0e-64ed-448a-8927-ce7bf90eb35d}")

'//
'// Specifies the decrease busy percentage threshold that must be met before
'// decreasing the processor performance state.
'//
'// {12a0ab44-fe28-4fa9-b3bd-4b64f44960a6}
'//
$GUID_PROCESSOR_PERF_DECREASE_THRESHOLD = GUID$("{12a0ab44-fe28-4fa9-b3bd-4b64f44960a6}")

'//
'// Specifies, either as ideal, single or rocket, how aggressive performance
'// states should be selected when increasing the processor performance state.
'//
'// {465E1F50-B610-473a-AB58-00D1077DC418}
'//
$GUID_PROCESSOR_PERF_INCREASE_POLICY = GUID$("{465E1F50-B610-473a-AB58-00D1077DC418}")

'//
'// Specifies, either as ideal, single or rocket, how aggressive performance
'// states should be selected when decreasing the processor performance state.
'//
'// {40FBEFC7-2E9D-4d25-A185-0CFD8574BAC6}
'//
$GUID_PROCESSOR_PERF_DECREASE_POLICY = GUID$("{40FBEFC7-2E9D-4d25-A185-0CFD8574BAC6}")

'//
'// Specifies, in milliseconds, the minimum amount of time that must elapse after
'// the last processor performance state change before increasing the processor
'// performance state.
'//
'// {984CF492-3BED-4488-A8F9-4286C97BF5AA}
'//
$GUID_PROCESSOR_PERF_INCREASE_TIME = GUID$("{984CF492-3BED-4488-A8F9-4286C97BF5AA}")

'//
'// Specifies, in milliseconds, the minimum amount of time that must elapse after
'// the last processor performance state change before increasing the processor
'// performance state.
'//
'// {D8EDEB9B-95CF-4f95-A73C-B061973693C8}
'//
$GUID_PROCESSOR_PERF_DECREASE_TIME = GUID$("{D8EDEB9B-95CF-4f95-A73C-B061973693C8}")

'//
'// Specifies the time, in milliseconds, that must expire before considering
'// a change in the processor performance states or parked core set.
'//
'// {4D2B0152-7D5C-498b-88E2-34345392A2C5}
'//
$GUID_PROCESSOR_PERF_TIME_CHECK = GUID$("{4D2B0152-7D5C-498b-88E2-34345392A2C5}")

'//
'// Specifies whether a processor may opportunistically increase frequency above
'// the maximum when operating contitions allow it to do so safely.
'//
'// {45BCC044-D885-43e2-8605-EE0EC6E96B59}
'//
$GUID_PROCESSOR_PERF_BOOST_POLICY = GUID$("{45BCC044-D885-43e2-8605-EE0EC6E96B59}")

%PROCESSOR_PERF_BOOST_POLICY_DISABLED = 0
%PROCESSOR_PERF_BOOST_POLICY_MAX = 100

'//
'// Specifies if idle state promotion and demotion values should be scaled based
'// on the current peformance state.
'//
'// {6C2993B0-8F48-481f-BCC6-00DD2742AA06}
'//
$GUID_PROCESSOR_IDLE_ALLOW_SCALING = GUID$("{6C2993B0-8F48-481f-BCC6-00DD2742AA06}")

'//
'// Specifies if idle states should be disabled.
'//
'// {5D76A2CA-E8C0-402f-A133-2158492D58AD}
'//
$GUID_PROCESSOR_IDLE_DISABLE = GUID$("{5D76A2CA-E8C0-402f-A133-2158492D58AD}")

'//
'// Specifies the time that elapsed since the last idle state promotion or
'// demotion before idle states may be promoted or demoted again (in
'// microseconds).
'//
'// {C4581C31-89AB-4597-8E2B-9C9CAB440E6B}
'//
$GUID_PROCESSOR_IDLE_TIME_CHECK = GUID$("{C4581C31-89AB-4597-8E2B-9C9CAB440E6B}")

'//
'// Specifies the upper busy threshold that must be met before demoting the
'// processor to a lighter idle state (in percentage).
'//
'// {4B92D758-5A24-4851-A470-815D78AEE119}
'//
$GUID_PROCESSOR_IDLE_DEMOTE_THRESHOLD = GUID$("{4B92D758-5A24-4851-A470-815D78AEE119}")

'//
'// Specifies the lower busy threshold that must be met before promoting the
'// processor to a deeper idle state (in percentage).
'//
'// {7B224883-B3CC-4d79-819F-8374152CBE7C}
'//
$GUID_PROCESSOR_IDLE_PROMOTE_THRESHOLD = GUID$("{7B224883-B3CC-4d79-819F-8374152CBE7C}")

'//
'// Specifies the utilization threshold in percent that must be crossed in order to un-park cores.
'//
'// {df142941-20f3-4edf-9a4a-9c83d3d717d1}
'//
$GUID_PROCESSOR_CORE_PARKING_INCREASE_THRESHOLD = GUID$("{df142941-20f3-4edf-9a4a-9c83d3d717d1}")

'//
'// Specifies the utilization threshold in percent that must be crossed in order to park cores.
'//
'// {68dd2f27-a4ce-4e11-8487-3794e4135dfa}
'//
$GUID_PROCESSOR_CORE_PARKING_DECREASE_THRESHOLD = GUID$("{68dd2f27-a4ce-4e11-8487-3794e4135dfa}")

'//
'// Specifies, either as ideal, single or rocket, how aggressive core parking is when cores must be unparked.
'//
'// {c7be0679-2817-4d69-9d02-519a537ed0c6}
'//
$GUID_PROCESSOR_CORE_PARKING_INCREASE_POLICY = GUID$("{c7be0679-2817-4d69-9d02-519a537ed0c6}")

%CORE_PARKING_POLICY_CHANGE_IDEAL  = 0
%CORE_PARKING_POLICY_CHANGE_SINGLE = 1
%CORE_PARKING_POLICY_CHANGE_ROCKET = 2
%CORE_PARKING_POLICY_CHANGE_MAX = %CORE_PARKING_POLICY_CHANGE_ROCKET

'//
'// Specifies, either as ideal, single or rocket, how aggressive core parking is when cores must be parked.
'//
'// {71021b41-c749-4d21-be74-a00f335d582b}
'//
$GUID_PROCESSOR_CORE_PARKING_DECREASE_POLICY = GUID$("{71021b41-c749-4d21-be74-a00f335d582b}")

'//
'// Specifies, on a per processor group basis, the maximum number of cores that can be kept unparked.
'//
'// {ea062031-0e34-4ff1-9b6d-eb1059334028}
'//
$GUID_PROCESSOR_CORE_PARKING_MAX_CORES = GUID$("{ea062031-0e34-4ff1-9b6d-eb1059334028}")

'//
'// Specifies, on a per processor group basis, the minimum number of cores that must be kept unparked.
'//
'// {0cc5b647-c1df-4637-891a-dec35c318583}
'//
$GUID_PROCESSOR_CORE_PARKING_MIN_CORES = GUID$("{0cc5b647-c1df-4637-891a-dec35c318583}")

'//
'// Specifies, in milliseconds, the minimum amount of time a core must be parked before it can be unparked.
'//
'// {2ddd5a84-5a71-437e-912a-db0b8c788732}
'//
$GUID_PROCESSOR_CORE_PARKING_INCREASE_TIME = GUID$("{2ddd5a84-5a71-437e-912a-db0b8c788732}")

'//
'// Specifies, in milliseconds, the minimum amount of time a core must be unparked before it can be parked.
'//
'// {dfd10d17-d5eb-45dd-877a-9a34ddd15c82}
'//
$GUID_PROCESSOR_CORE_PARKING_DECREASE_TIME = GUID$("{dfd10d17-d5eb-45dd-877a-9a34ddd15c82}")

'//
'// Specifies the factor by which to decrease affinity history on each core after each check.
'//
'// {8f7b45e3-c393-480a-878c-f67ac3d07082}
'//
$GUID_PROCESSOR_CORE_PARKING_AFFINITY_HISTORY_DECREASE_FACTOR = GUID$("{8f7b45e3-c393-480a-878c-f67ac3d07082}")

'//
'// Specifies the threshold above which a core is considered to have had significant affinitized work scheduled to it while parked.
'//
'// {5b33697b-e89d-4d38-aa46-9e7dfb7cd2f9}
'//
$GUID_PROCESSOR_CORE_PARKING_AFFINITY_HISTORY_THRESHOLD = GUID$("{5b33697b-e89d-4d38-aa46-9e7dfb7cd2f9}")

'//
'// Specifies the weighting given to each occurence where affinitized work was scheduled to a parked core.
'//
'// {e70867f1-fa2f-4f4e-aea1-4d8a0ba23b20}
'//
$GUID_PROCESSOR_CORE_PARKING_AFFINITY_WEIGHTING = GUID$("{e70867f1-fa2f-4f4e-aea1-4d8a0ba23b20}")

'//
'// Specifies the factor by which to decrease the over utilization history on each core after the current performance check.
'//
'// {1299023c-bc28-4f0a-81ec-d3295a8d815d}
'//
$GUID_PROCESSOR_CORE_PARKING_OVER_UTILIZATION_HISTORY_DECREASE_FACTOR = GUID$("{1299023c-bc28-4f0a-81ec-d3295a8d815d}")

'//
'// Specifies the threshold above which a core is considered to have been recently over utilized while parked.
'//
'// {9ac18e92-aa3c-4e27-b307-01ae37307129}
'//
$GUID_PROCESSOR_CORE_PARKING_OVER_UTILIZATION_HISTORY_THRESHOLD = GUID$("{9ac18e92-aa3c-4e27-b307-01ae37307129}")

'//
'// Specifies the weighting given to each occurence where a parked core is found to be over utilized.
'//
'// {8809c2d8-b155-42d4-bcda-0d345651b1db}
'//
$GUID_PROCESSOR_CORE_PARKING_OVER_UTILIZATION_WEIGHTING = GUID$("{8809c2d8-b155-42d4-bcda-0d345651b1db}")

'//
'// Specifies, in percentage, the busy threshold that must be met before a parked core is considered over utilized.
'//
'// {943c8cb6-6f93-4227-ad87-e9a3feec08d1}
'//
$GUID_PROCESSOR_CORE_PARKING_OVER_UTILIZATION_THRESHOLD = GUID$("{943c8cb6-6f93-4227-ad87-e9a3feec08d1}")

'//
'// Specifies if at least one processor per core should always remain unparked.
'//
'// {a55612aa-f624-42c6-a443-7397d064c04f}
'//
$GUID_PROCESSOR_PARKING_CORE_OVERRIDE = GUID$("{a55612aa-f624-42c6-a443-7397d064c04f}")

'//
'// Specifies what performance state a processor should enter when first parked.
'//
'// {447235c7-6a8d-4cc0-8e24-9eaf70b96e2b}
'//
$GUID_PROCESSOR_PARKING_PERF_STATE = GUID$("{447235c7-6a8d-4cc0-8e24-9eaf70b96e2b}")

'//
'// Specifies the number of perf time check intervals to average utility over.
'//
'// {7d24baa7-0b84-480f-840c-1b0743c00f5f}
'//
$GUID_PROCESSOR_PERF_HISTORY = GUID$("{7d24baa7-0b84-480f-840c-1b0743c00f5f}")

'//
'// Specifies active vs passive cooling.  Although not directly related to
'// processor settings, it is the processor that gets throttled if we're doing
'// passive cooling, so it is fairly strongly related.
'// {94D3A615-A899-4AC5-AE2B-E4D8F634367F}
'//
$GUID_SYSTEM_COOLING_POLICY = GUID$("{94D3A615-A899-4AC5-AE2B-E4D8F634367F}")

'// Lock Console on Wake
'// --------------------
'//

'// Specifies the behavior of the system when we wake from standby or
'// hibernate.  If this is set, then we will cause the console to lock
'// after we resume.
'//
$GUID_LOCK_CONSOLE_ON_WAKE = GUID$("{0E796BDB-100D-47D6-A2D5-F7D2DAA51F51}")

'// Device idle characteristics
'// ---------------------------
'//
'// Specifies whether to use the "performance" or "conservative" timeouts for
'// device idle management.
'//
'// 4faab71a-92e5-4726-b531-224559672d19
'//
$GUID_DEVICE_IDLE_POLICY = GUID$("{4FAAB71A-92E5-4726-B531-224559672D19}")

%POWER_DEVICE_IDLE_POLICY_PERFORMANCE  = 0
%POWER_DEVICE_IDLE_POLICY_CONSERVATIVE = 1

'// AC/DC power source
'// ------------------
'//

'// Specifies the power source for the system.  consumers may register for
'// notification when the power source changes and will be notified with
'// one of 3 values:
'// 0 - Indicates the system is being powered by an AC power source.
'// 1 - Indicates the system is being powered by a DC power source.
'// 2 - Indicates the system is being powered by a short-term DC power
'//     source.  For example, this would be the case if the system is
'//     being powed by a short-term battery supply in a backing UPS
'//     system.  When this value is recieved, the consumer should make
'//     preparations for either a system hibernate or system shutdown.
'//
'// { 5D3E9A59-E9D5-4B00-A6BD-FF34FF516548 }
$GUID_ACDC_POWER_SOURCE = GUID$("{5D3E9A59-E9D5-4B00-A6BD-FF34FF516548}")

'// Lid state changes
'// -----------------
'//
'// Specifies the current state of the lid (open or closed). The callback won't
'// be called at all until a lid device is found and its current state is known.
'//
'// Values:
'//
'// 0 - closed
'// 1 - opened
'//
'// { BA3E0F4D-B817-4094-A2D1-D56379E6A0F3 }
'//
$GUID_LIDSWITCH_STATE_CHANGE = GUID$("{BA3E0F4D-B817-4094-A2D1-D56379E6A0F3}")

'// Battery life remaining
'// ----------------------
'//

'// Specifies the percentage of battery life remaining.  The consumer
'// may register for notification in order to track battery life in
'// a fine-grained manner.
'//
'// Once registered, the consumer can expect to be notified as the battery
'// life percentage changes.
'//
'// The consumer will recieve a value between 0 and 100 (inclusive) which
'// indicates percent battery life remaining.
'//
'// { A7AD8041-B45A-4CAE-87A3-EECBB468A9E1 }
$GUID_BATTERY_PERCENTAGE_REMAINING = GUID$("{A7AD8041-B45A-4CAE-87A3-EECBB468A9E1}")

'// Notification to listeners that the system is fairly busy and won't be moving
'// into an idle state any time soon.  This can be used as a hint to listeners
'// that now might be a good time to do background tasks.
'//
$GUID_IDLE_BACKGROUND_TASK = GUID$("{515C31D8-F734-163D-A0FD-11A08C91E8F1}")

'// Notification to listeners that the system is fairly busy and won't be moving
'// into an idle state any time soon.  This can be used as a hint to listeners
'// that now might be a good time to do background tasks.
'//
'// { CF23F240-2A54-48D8-B114-DE1518FF052E }
$GUID_BACKGROUND_TASK_NOTIFICATION = GUID$("{CF23F240-2A54-48D8-B114-DE1518FF052E}")

'// Define a GUID that will represent the action of a direct experience button
'// on the platform.  Users will register for this DPPE setting and recieve
'// notification when the h/w button is pressed.
'//
'// { 1A689231-7399-4E9A-8F99-B71F999DB3FA }
'//
$GUID_APPLAUNCH_BUTTON = GUID$("{1A689231-7399-4E9A-8F99-B71F999DB3FA}")

'// PCI Express power settings
'// ------------------------
'//

'// Specifies the subgroup which will contain all of the PCI Express
'// settings for a single policy.
'//
'// {501a4d13-42af-4429-9fd1-a8218c268e20}
'//
$GUID_PCIEXPRESS_SETTINGS_SUBGROUP = GUID$("{501a4d13-42af-4429-9fd1-a8218c268e20}")

'// Specifies the PCI Express ASPM power policy.
'//
'// {ee12f906-d277-404b-b6da-e5fa1a576df5}
'//
$GUID_PCIEXPRESS_ASPM_POLICY = GUID$("{ee12f906-d277-404b-b6da-e5fa1a576df5}")

'// POWER Shutdown settings
'// ------------------------
'//

'// Specifies if forced shutdown should be used for all button and lid initiated
'// shutdown actions.
'//
'// {833a6b62-dfa4-46d1-82f8-e09e34d029d6}
'//
$GUID_ENABLE_SWITCH_FORCED_SHUTDOWN = GUID$("{833a6b62-dfa4-46d1-82f8-e09e34d029d6}")

' SYSTEM_POWER_STATE enum
%PowerSystemUnspecified = 0
%PowerSystemWorking     = 1
%PowerSystemSleeping1   = 2
%PowerSystemSleeping2   = 3
%PowerSystemSleeping3   = 4
%PowerSystemHibernate   = 5
%PowerSystemShutdown    = 6
%PowerSystemMaximum     = 7

%POWER_SYSTEM_MAXIMUM   = 7

' POWER_ACTION enum
%PowerActionNone          = 0
%PowerActionReserved      = 1
%PowerActionSleep         = 2
%PowerActionHibernate     = 3
%PowerActionShutdown      = 4
%PowerActionShutdownReset = 5
%PowerActionShutdownOff   = 6
%PowerActionWarmEject     = 7

' DEVICE_POWER_STATE enum
%PowerDeviceUnspecified = 0
%PowerDeviceD0          = 1
%PowerDeviceD1          = 2
%PowerDeviceD2          = 3
%PowerDeviceD3          = 4
%PowerDeviceMaximum     = 5

' enum _MONITOR_DISPLAY_STATE
%PowerMonitorOff = 0
%PowerMonitorOn  = 1
%PowerMonitorDim = 2

%ES_SYSTEM_REQUIRED   = &H00000001???
%ES_DISPLAY_REQUIRED  = &H00000002???
%ES_USER_PRESENT      = &H00000004???
%ES_AWAYMODE_REQUIRED = &H00000040???
%ES_CONTINUOUS        = &H80000000???

'typedef DWORD EXECUTION_STATE, *PEXECUTION_STATE;

' LATENCY_TIME enum
%LT_DONT_CARE      = 0
%LT_LOWEST_LATENCY = 1

'#if (_WIN32_WINNT >= _WIN32_WINNT_WIN7)

%DIAGNOSTIC_REASON_VERSION             = 0

%DIAGNOSTIC_REASON_SIMPLE_STRING       = &H00000001???
%DIAGNOSTIC_REASON_DETAILED_STRING     = &H00000002???
%DIAGNOSTIC_REASON_NOT_SPECIFIED       = &H80000000???
%DIAGNOSTIC_REASON_INVALID_FLAGS       = NOT &H80000003???   ' (~0x80000003)

'#endif // (_WIN32_WINNT >= _WIN32_WINNT_WIN7)

'//
'// Defines for power request APIs
'//

%POWER_REQUEST_CONTEXT_VERSION          = 0

%POWER_REQUEST_CONTEXT_SIMPLE_STRING    = &H00000001???
%POWER_REQUEST_CONTEXT_DETAILED_STRING  = &H00000002???

'//
'// N.B. The maximum is a macro (rather than part of enum) for cgen to be able
'// to parse power.h correctly. When a new power request type is added, the
'// PowerRequestMaximum should be manually incremented.
'//

' enum POWER_REQUEST_TYPE
%PowerRequestDisplayRequired  = 0
%PowerRequestSystemRequired   = 1
%PowerRequestAwayModeRequired = 2

%PowerRequestMaximum = 3

'// end_ntminiport

'#if (NTDDI_VERSION >= NTDDI_WINXP)

'//-----------------------------------------------------------------------------
'// Device Power Information
'// Accessable via CM_Get_DevInst_Registry_Property_Ex(CM_DRP_DEVICE_POWER_DATA)
'//-----------------------------------------------------------------------------

%PDCAP_D0_SUPPORTED              = &H00000001???
%PDCAP_D1_SUPPORTED              = &H00000002???
%PDCAP_D2_SUPPORTED              = &H00000004???
%PDCAP_D3_SUPPORTED              = &H00000008???
%PDCAP_WAKE_FROM_D0_SUPPORTED    = &H00000010???
%PDCAP_WAKE_FROM_D1_SUPPORTED    = &H00000020???
%PDCAP_WAKE_FROM_D2_SUPPORTED    = &H00000040???
%PDCAP_WAKE_FROM_D3_SUPPORTED    = &H00000080???
%PDCAP_WARM_EJECT_SUPPORTED      = &H00000100???

' // Size = 56 bytes
TYPE CM_POWER_DATA DWORD
   PD_Size                 AS DWORD   ' DWORD
   PD_MostRecentPowerState AS LONG    ' DEVICE_POWER_STATE
   PD_Capabilities         AS DWORD   ' DWORD
   PD_D1Latency            AS DWORD   ' DWORD
   PD_D2Latency            AS DWORD   ' DWORD
   PD_D3Latency            AS DWORD   ' DWORD
   PD_PowerStateMapping(%POWER_SYSTEM_MAXIMUM - 1) AS LONG   ' DEVICE_POWER_STATE
   PD_DeepestSystemWake    AS LONG    ' SYSTEM_POWER_STATE
END TYPE

'#endif // (NTDDI_VERSION >= NTDDI_WINXP)

' POWER_INFORMATION_LEVEL enum
%SystemPowerPolicyAc             = 0
%SystemPowerPolicyDc             = 1
%VerifySystemPolicyAc            = 2
%VerifySystemPolicyDc            = 3
%SystemPowerCapabilities         = 4
%SystemBatteryState              = 5
%SystemPowerStateHandler         = 6
%ProcessorStateHandler           = 7
%SystemPowerPolicyCurrent        = 8
%AdministratorPowerPolicy        = 9
%SystemReserveHiberFile          = 10
%ProcessorInformation            = 11
%SystemPowerInformation          = 12
%ProcessorStateHandler2          = 13
%LastWakeTime                    = 14   ' Compare with KeQueryInterruptTime()
%LastSleepTime                   = 15   ' Compare with KeQueryInterruptTime()
%SystemExecutionState            = 16
%SystemPowerStateNotifyHandler   = 17
%ProcessorPowerPolicyAc          = 18
%ProcessorPowerPolicyDc          = 19
%VerifyProcessorPowerPolicyAc    = 20
%VerifyProcessorPowerPolicyDc    = 21
%ProcessorPowerPolicyCurrent     = 22
%SystemPowerStateLogging         = 23
%SystemPowerLoggingEntry         = 24
%SetPowerSettingValue            = 25
%NotifyUserPowerSetting          = 26
%PowerInformationLevelUnused0    = 27
%PowerInformationLevelUnused1    = 28
%SystemVideoState                = 29
%TraceApplicationPowerMessage    = 30
%TraceApplicationPowerMessageEnd = 31
%ProcessorPerfStates             = 32
%ProcessorCap                    = 33
%ProcessorThrottleStates         = 34
%SystemWakeSource                = 35
%SystemHiberFileInformation      = 36
%TraceServicePowerMessage        = 37
%ProcessorLoad                   = 38
%PowerShutdownNotification       = 39
%MonitorCapabilities             = 40
%SessionPowerInit                = 41
%SessionDisplayState             = 42
%PowerRequestCreate              = 43
%PowerRequestAction              = 44
%GetPowerRequestList             = 45
%ProcessorInformationEx          = 46
%NotifyUserModeLegacyPowerEvent  = 47
%GroupPark                       = 48
%ProcessorIdleDomains            = 49
%WakeTimerList                   = 50
%SystemHiberFileSize             = 51
%PowerInformationLevelMaximum    = 52

'//
'// Power Setting definitions
'//

' enum SYSTEM_POWER_CONDITION
%PoAc               = 0
%PoDc               = 1
%PoHot              = 2
%PoConditionMaximum = 3

UNION SET_POWER_SETTING_VALUE_GUID_UNION DWORD
   Guid           AS GUID    ' GUID
   ' // For compatibility with the PB declares
   nGuid          AS GUID    ' GUID
END UNION

UNION SET_POWER_SETTING_VALUE_DATA_UNION DWORD
   Data(0)        AS BYTE    ' BYTE[ANYSIZE_ARRAY]
   ' // For compatibility with the PB declares
   nData(0)       AS BYTE    ' BYTE[ANYSIZE_ARRAY]
END UNION

' // Size = 32 bytes
TYPE SET_POWER_SETTING_VALUE DWORD
   Version        AS DWORD   ' DWORD
   SET_POWER_SETTING_VALUE_GUID_UNION
   PowerCondition AS DWORD   ' SYSTEM_POWER_CONDITION
   DataLength     AS DWORD   ' DWORD
   SET_POWER_SETTING_VALUE_DATA_UNION
END TYPE

%POWER_SETTING_VALUE_VERSION = &H1

UNION NOTIFY_USER_POWER_SETTING_GUID_UNION DWORD
   Guid AS GUID   ' GUID
   ' // For compatibility with the PB declares
   nGuid AS GUID   ' GUID
END UNION

' // Size = 16 bytes
TYPE NOTIFY_USER_POWER_SETTING DWORD
   NOTIFY_USER_POWER_SETTING_GUID_UNION
END TYPE

'//
'// Package definition for an experience button device notification.  When
'// someone registers for GUID_EXPERIENCE_BUTTON, this is the definition of
'// the setting data they'll get.
'//
' // Size = 16 bytes
TYPE APPLICATIONLAUNCH_SETTING_VALUE   ' Must be 8 byte aligned
   ActivationTime   AS QUAD    ' LARGE_INTEGER
   Flags            AS DWORD   ' DWORD
   ButtonInstanceID AS DWORD   ' DWORD
END TYPE

'//
'// define platform roles
'//

' enum POWER_PLATFORM_ROLE
%PlatformRoleUnspecified       = 0
%PlatformRoleDesktop           = 1
%PlatformRoleMobile            = 2
%PlatformRoleWorkstation       = 3
%PlatformRoleEnterpriseServer  = 4
%PlatformRoleSOHOServer        = 5
%PlatformRoleAppliancePC       = 6
%PlatformRolePerformanceServer = 7
%PlatformRoleMaximum           = 8

'//
'// System power manager capabilities
'//

'#if (NTDDI_VERSION >= NTDDI_WINXP) || !defined(_BATCLASS_)
' // Size = 8 bytes
TYPE BATTERY_REPORTING_SCALE DWORD
   Granularity AS DWORD
   Capacity    AS DWORD
END TYPE
'#endif // (NTDDI_VERSION >= NTDDI_WINXP) || !defined(_BATCLASS_)

' // Size = 12 bytes
TYPE PPM_WMI_LEGACY_PERFSTATE DWORD
   Frequency        AS DWORD   ' DWORD
   Flags            AS DWORD   ' DWORD
   PercentFrequency AS DWORD   ' DWORD
END TYPE

' // Size = 32 bytes
TYPE PPM_WMI_IDLE_STATE DWORD FILL
   Latency        AS DWORD   ' DWORD
   Power          AS DWORD   ' DWORD
   TimeCheck      AS DWORD   ' DWORD
   PromotePercent AS BYTE    ' BYTE
   DemotePercent  AS BYTE    ' BYTE
   StateType      AS BYTE    ' BYTE
   Reserved       AS BYTE    ' BYTE
   StateFlags     AS DWORD   ' DWORD
   Context        AS DWORD   ' DWORD
   IdleHandler    AS DWORD   ' DWORD
   Reserved1      AS DWORD   ' DWORD // reserved for future use
END TYPE

UNION PPM_WMI_IDLE_STATES_TYPE_UNION
   Type             AS DWORD   ' DWORD
   ' // For compatibility with the PB declares
   nType            AS DWORD   ' DWORD
END UNION

' // Size = 56 bytes
TYPE PPM_WMI_IDLE_STATES   ' Must be 8 byte aligned
   PPM_WMI_IDLE_STATES_TYPE_UNION
   Count            AS DWORD   ' DWORD
   TargetState      AS DWORD   ' DWORD // current idle state
   OldState         AS DWORD   ' DWORD // previous idle state
   TargetProcessors AS QUAD    ' DWORD64
   State(0)         AS PPM_WMI_IDLE_STATE   ' PPM_WMI_IDLE_STATE[ANYSIZE_ARRAY]
END TYPE

' // Size = 52 bytes
TYPE PPM_WMI_IDLE_STATES_EX DWORD
   Type             AS DWORD   ' DWORD
   Count            AS DWORD   ' DWORD
   TargetState      AS DWORD   ' DWORD // current idle state
   OldState         AS DWORD   ' DWORD // previous idle state
   TargetProcessors AS DWORD   ' PVOID
   State(0)         AS PPM_WMI_IDLE_STATE   ' PPM_WMI_IDLE_STATE[ANYSIZE_ARRAY]
END TYPE

UNION PPM_WMI_PERF_STATE_TYPE_UNION
   Type             AS BYTE    ' BYTE // performance or throttle
   ' // For compatibility with the PB declares
   nType            AS BYTE    ' BYTE // performance or throttle
END UNION

' // Size = 64 bytes
TYPE PPM_WMI_PERF_STATE QWORD FILL  ' Must be 8 byte aligned
   Frequency        AS DWORD   ' DWORD // in Mhz
   Power            AS DWORD   ' DWORD// in milliwatts
   PercentFrequency AS BYTE    ' BYTE
   IncreaseLevel    AS BYTE    ' BYTE // goto higher state
   DecreaseLevel    AS BYTE    ' BYTE // goto lower state
   PPM_WMI_PERF_STATE_TYPE_UNION
   IncreaseTime     AS DWORD   ' DWORD // in tick counts
   DecreaseTime     AS DWORD   ' DWORD // in tick counts
   Control          AS QUAD    ' DWORD64 // control value
   Status           AS QUAD    ' DWORD64 // control value
   HitCount         AS DWORD   ' DWORD
   Reserved1        AS DWORD   ' DWORD // reserved for future use
   Reserved2        AS QUAD    ' DWORD64
   Reserved3        AS QUAD    ' DWORD64
END TYPE

UNION PPM_WMI_PERF_STATES_TYPE_UNION
   Type              AS BYTE    ' BYTE
   ' // For compatibility with the PB declares
   nType             AS BYTE    ' BYTE
END UNION

' // Size = 144 bytes
TYPE PPM_WMI_PERF_STATES QWORD FILL
   Count             AS DWORD   ' DWORD
   MaxFrequency      AS DWORD   ' DWORD
   CurrentState      AS DWORD   ' DWORD // current state
   MaxPerfState      AS DWORD   ' DWORD // fastest state considering policy restrictions
   MinPerfState      AS DWORD   ' DWORD // slowest state considering policy restrictions
   LowestPerfState   AS DWORD   ' DWORD // slowest perf state, fixed, aka the "knee"
   ThermalConstraint AS DWORD   ' DWORD
   BusyAdjThreshold  AS BYTE    ' BYTE
   PolicyType        AS BYTE    ' BYTE // domain coordination
   PPM_WMI_PERF_STATES_TYPE_UNION
   Reserved          AS BYTE    ' BYTE
   TimerInterval     AS DWORD   ' DWORD
   TargetProcessors  AS QUAD    ' DWORD64 // domain affinity
   PStateHandler     AS DWORD   ' DWORD
   PStateContext     AS DWORD   ' DWORD
   TStateHandler     AS DWORD   ' DWORD
   TStateContext     AS DWORD   ' DWORD
   FeedbackHandler   AS DWORD   ' DWORD
   Reserved1         AS DWORD   ' DWORD
   Reserved2         AS QUAD    ' DWORD64
   State(0)          AS PPM_WMI_PERF_STATE   ' PPM_WMI_PERF_STATE[ANYSIZE_ARRAY]
END TYPE

' // Size = 136 bytes
TYPE PPM_WMI_PERF_STATES_EX QWORD FILL
   Count             AS DWORD   ' DWORD
   MaxFrequency      AS DWORD   ' DWORD
   CurrentState      AS DWORD   ' DWORD // current state
   MaxPerfState      AS DWORD   ' DWORD // fastest state considering policy restrictions
   MinPerfState      AS DWORD   ' DWORD // slowest state considering policy restrictions
   LowestPerfState   AS DWORD   ' DWORD // slowest perf state, fixed, aka the "knee"
   ThermalConstraint AS DWORD   ' DWORD
   BusyAdjThreshold  AS BYTE    ' BYTE
   PolicyType        AS BYTE    ' BYTE  // domain coordination
   Type              AS BYTE    ' BYTE
   Reserved          AS BYTE    ' BYTE
   TimerInterval     AS DWORD   ' DWORD
   TargetProcessors  AS DWORD   ' PVOID // domain affinity
   PStateHandler     AS DWORD   ' DWORD
   PStateContext     AS DWORD   ' DWORD
   TStateHandler     AS DWORD   ' DWORD
   TStateContext     AS DWORD   ' DWORD
   FeedbackHandler   AS DWORD   ' DWORD
   Reserved1         AS DWORD   ' DWORD
   Reserved2         AS QUAD    ' DWORD64
   State(0)          AS PPM_WMI_PERF_STATE   ' PPM_WMI_PERF_STATE[ANYSIZE_ARRAY]
END TYPE

'//
'// Legacy processor idle accounting.
'//

%PROC_IDLE_BUCKET_COUNT = 6

' // Size = 48 bytes
TYPE PPM_IDLE_STATE_ACCOUNTING QWORD FILL
   IdleTransitions    AS DWORD   ' DWORD
   FailedTransitions  AS DWORD   ' DWORD
   InvalidBucketIndex AS DWORD   ' DWORD
   TotalTime          AS QUAD    ' DWORD64
   IdleTimeBuckets(%PROC_IDLE_BUCKET_COUNT - 1) AS DWORD   ' DWORD
END TYPE

' // Size = 72 bytes
TYPE PPM_IDLE_ACCOUNTING QWORD FILL
   StateCount       AS DWORD   ' DWORD
   TotalTransitions AS DWORD   ' DWORD
   ResetCount       AS DWORD   ' DWORD
   StartTime        AS QUAD    ' DWPRD64
   State(0)         AS PPM_IDLE_STATE_ACCOUNTING   ' PPM_IDLE_STATE_ACCOUNTING[ANYSIZE_ARRAY]
END TYPE

'//
'// Processor idle accounting.
'//

%PROC_IDLE_BUCKET_COUNT_EX = 16

' // Size = 24 bytes
TYPE PPM_IDLE_STATE_BUCKET_EX   ' Must be 8 byte aligned
   TotalTimeUs AS QUAD    ' DWORD64
   MinTimeUs   AS DWORD   ' DWORD
   MaxTimeUs   AS DWORD   ' DWORD
   Count       AS DWORD   ' DWORD
   alignment__ AS DWORD   ' // To keep 8 byte alignment
END TYPE

' // Size = 416 bytes
TYPE PPM_IDLE_STATE_ACCOUNTING_EX QWORD FILL
   TotalTime          AS QUAD    ' DWORD64
   IdleTransitions    AS DWORD   ' DWORD
   FailedTransitions  AS DWORD   ' DWORD
   InvalidBucketIndex AS DWORD   ' DWORD
   MinTimeUs          AS DWORD   ' DWORD
   MaxTimeUs          AS DWORD   ' DWORD
   IdleTimeBuckets(%PROC_IDLE_BUCKET_COUNT_EX - 1) AS PPM_IDLE_STATE_BUCKET_EX
END TYPE

' // Size = 440 bytes
TYPE PPM_IDLE_ACCOUNTING_EX QWORD FILL
   StateCount       AS DWORD   ' DWORD
   TotalTransitions AS DWORD   ' DWORD
   ResetCount       AS DWORD   ' DWORD
   StartTime        AS QUAD    ' DWORD64
   State(0)         AS PPM_IDLE_STATE_ACCOUNTING_EX   ' PPM_IDLE_STATE_ACCOUNTING_EX[ANYSIZE_ARRAY]
END TYPE

'//
'// Definitions of coordination types for _PSD, _TSD, and _CSD BIOS objects from
'// the Acpi 3.0 specification
'//

%ACPI_PPM_SOFTWARE_ALL     = &HFC
%ACPI_PPM_SOFTWARE_ANY     = &HFD
%ACPI_PPM_HARDWARE_ALL     = &HFE

'//
'// Definition of Microsoft PPM coordination types.
'//

%MS_PPM_SOFTWARE_ALL       = &H1

'//
'// Processor firmware rundown feature bit definitions.
'//

%PPM_FIRMWARE_ACPI1C2      = &H00000001???
%PPM_FIRMWARE_ACPI1C3      = &H00000002???
%PPM_FIRMWARE_ACPI1TSTATES = &H00000004???
%PPM_FIRMWARE_CST          = &H00000008???
%PPM_FIRMWARE_CSD          = &H00000010???
%PPM_FIRMWARE_PCT          = &H00000020???
%PPM_FIRMWARE_PSS          = &H00000040???
%PPM_FIRMWARE_XPSS         = &H00000080???
%PPM_FIRMWARE_PPC          = &H00000100???
%PPM_FIRMWARE_PSD          = &H00000200???
%PPM_FIRMWARE_PTC          = &H00000400???
%PPM_FIRMWARE_TSS          = &H00000800???
%PPM_FIRMWARE_TPC          = &H00001000???
%PPM_FIRMWARE_TSD          = &H00002000???
%PPM_FIRMWARE_PCCH         = &H00004000???
%PPM_FIRMWARE_PCCP         = &H00008000???

'//
'// Processor Power Management WMI interface.
'//

$PPM_PERFSTATE_CHANGE_GUID = GUID$("{A5B32DDD-7F39-4abc-B892-900E43B59EBB}")
$PPM_PERFSTATE_DOMAIN_CHANGE_GUID = GUID$("{995e6b7f-d653-497a-b978-36a30c29bf01}")
$PPM_IDLESTATE_CHANGE_GUID = GUID$("{4838fe4f-f71c-4e51-9ecc-8430a7ac4c6c}")
$PPM_PERFSTATES_DATA_GUID = GUID$("{5708cc20-7d40-4bf4-b4aa-2b01338d0126}")
$PPM_IDLESTATES_DATA_GUID = GUID$("{ba138e10-e250-4ad7-8616-cf1a7ad410e7}")
$PPM_IDLE_ACCOUNTING_GUID = GUID$("{e2a26f78-ae07-4ee0-a30f-ce354f5a94cd}")
$PPM_IDLE_ACCOUNTING_EX_GUID = GUID$("{d67abd39-81f8-4a5e-8152-72e31ec912ee}")
$PPM_THERMALCONSTRAINT_GUID = GUID$("{a852c2c8-1a4c-423b-8c2c-f30d82931a88}")
$PPM_PERFMON_PERFSTATE_GUID = GUID$("{7fd18652-0cfe-40d2-b0a1-0b066a87759e}")
$PPM_THERMAL_POLICY_CHANGE_GUID = GUID$("{48f377b8-6880-4c7b-8bdc-380176c6654d}")

' // Size = 20 bytes
TYPE PPM_PERFSTATE_EVENT DWORD
   State     AS DWORD   ' DWORD
   Status    AS DWORD   ' DWORD
   Latency   AS DWORD   ' DWORD
   Speed     AS DWORD   ' DWORD
   Processor AS DWORD   ' DWORD
END TYPE

' // Size = 24 bytes
TYPE PPM_PERFSTATE_DOMAIN_EVENT QWORD FILL
   State      AS DWORD   ' DWORD
   Latency    AS DWORD   ' DWORD
   Speed      AS DWORD   ' DWORD
   Processors AS QUAD    ' DWORD64
END TYPE

' // Size = 16 bytes
TYPE PPM_IDLESTATE_EVENT QWORD FILL
   NewState   AS DWORD   ' DWORD
   OldState   AS DWORD   ' DWORD
   Processors AS QUAD    ' DWORD64
END TYPE

' // Size = 16 bytes
TYPE PPM_THERMALCHANGE_EVENT QWORD FILL
   ThermalConstraint AS DWORD   ' DWORD
   Processors        AS QUAD   ' DWORD64
END TYPE

'#pragma warning(push)
'#pragma warning(disable:4121)

' // Size = 16 bytes
TYPE PPM_THERMAL_POLICY_EVENT QWORD FILL
   Mode       AS BYTE   ' BYTE
   Processors AS QUAD   ' DWORD64
END TYPE

'#pragma warning(pop)

'//
'// Power Policy Management interfaces
'//

' // Size = 12 bytes
TYPE POWER_ACTION_POLICY DWORD
   Action    AS LONG    ' POWER_ACTION
   Flags     AS DWORD   ' DWORD
   EventCode AS DWORD   ' DWORD
END TYPE

'// POWER_ACTION_POLICY->Flags:
%POWER_ACTION_QUERY_ALLOWED         = &H00000001???
%POWER_ACTION_UI_ALLOWED            = &H00000002???
%POWER_ACTION_OVERRIDE_APPS         = &H00000004???
%POWER_ACTION_PSEUDO_TRANSITION     = &H08000000???
%POWER_ACTION_LIGHTEST_FIRST        = &H10000000???
%POWER_ACTION_LOCK_CONSOLE          = &H20000000???
%POWER_ACTION_DISABLE_WAKES         = &H40000000???
%POWER_ACTION_CRITICAL              = &H80000000???

'// POWER_ACTION_POLICY->EventCode flags
%POWER_LEVEL_USER_NOTIFY_TEXT      = &H00000001???
%POWER_LEVEL_USER_NOTIFY_SOUND     = &H00000002???
%POWER_LEVEL_USER_NOTIFY_EXEC      = &H00000004???
%POWER_USER_NOTIFY_BUTTON          = &H00000008???
%POWER_USER_NOTIFY_SHUTDOWN        = &H00000010???
%POWER_USER_NOTIFY_FORCED_SHUTDOWN = &H00000020???
%POWER_FORCE_TRIGGER_RESET         = &H80000000???

'// Note: for battery alarm EventCodes, the ID of the battery alarm << 16 is ORed
'// into the flags.  For example: DISCHARGE_POLICY_LOW << 16

'//
'// The GUID_BATTERY_DISCHARGE_FLAGS_x power settings use a subset of EventCode
'// flags.  The POWER_FORCE_TRIGGER_RESET flag doesn't make sense for a battery
'// alarm so it is overloaded for other purposes (gerneral enable/disable).
%BATTERY_DISCHARGE_FLAGS_EVENTCODE_MASK = &H00000007???
%BATTERY_DISCHARGE_FLAGS_ENABLE         = &H80000000???

'// system battery drain policies
' // Size = 24 bytes
TYPE SYSTEM_POWER_LEVEL DWORD FILL
   Enable         AS BYTE                  ' BOOLEAN
   Spare(2)       AS BYTE                  ' BYTE
   BatteryLevel   AS DWORD                 ' DWORD
   PowerPolicy    AS POWER_ACTION_POLICY   ' POWER_ACTION_POLICY
   MinSystemState AS LONG                  ' SYSTEM_POWER_STATE
END TYPE

'// Discharge policy constants
%NUM_DISCHARGE_POLICIES    = 4
%DISCHARGE_POLICY_CRITICAL = 0
%DISCHARGE_POLICY_LOW      = 1

'// system power policies
'typedef struct _SYSTEM_POWER_POLICY {
'    DWORD                   Revision;       // 1

'    // events
'    POWER_ACTION_POLICY     PowerButton;
'    POWER_ACTION_POLICY     SleepButton;
'    POWER_ACTION_POLICY     LidClose;
'    SYSTEM_POWER_STATE      LidOpenWake;
'    DWORD                   Reserved;

'    // "system idle" detection
'    POWER_ACTION_POLICY     Idle;
'    DWORD                   IdleTimeout;
'    BYTE                    IdleSensitivity;

'    // dynamic throttling policy
'    //      PO_THROTTLE_NONE, PO_THROTTLE_CONSTANT, PO_THROTTLE_DEGRADE, or PO_THROTTLE_ADAPTIVE
'    BYTE                    DynamicThrottle;

'    BYTE                    Spare2[2];

'    // meaning of power action "sleep"
'    SYSTEM_POWER_STATE      MinSleep;
'    SYSTEM_POWER_STATE      MaxSleep;
'    SYSTEM_POWER_STATE      ReducedLatencySleep;
'    DWORD                   WinLogonFlags;

'    // parameters for dozing
'    DWORD                   Spare3;
'    DWORD                   DozeS4Timeout;

'    // battery policies
'    DWORD                   BroadcastCapacityResolution;
'    SYSTEM_POWER_LEVEL      DischargePolicy[NUM_DISCHARGE_POLICIES];

'    // video policies
'    DWORD                   VideoTimeout;
'    BOOLEAN                 VideoDimDisplay;
'    DWORD                   VideoReserved[3];

'    // hard disk policies
'    DWORD                   SpindownTimeout;

'    // processor policies
'    BOOLEAN                 OptimizeForPower;
'    BYTE                    FanThrottleTolerance;
'    BYTE                    ForcedThrottle;
'    BYTE                    MinThrottle;
'    POWER_ACTION_POLICY     OverThrottled;

'} SYSTEM_POWER_POLICY, *PSYSTEM_POWER_POLICY;

' // Size = 232 bytes
TYPE SYSTEM_POWER_POLICY DWORD FILL
   Revision                    AS DWORD                 ' DWORD
   ' events
   PowerButton                 AS POWER_ACTION_POLICY   ' POWER_ACTION_POLICY
   SleepButton                 AS POWER_ACTION_POLICY   ' POWER_ACTION_POLICY
   LidClose                    AS POWER_ACTION_POLICY   ' POWER_ACTION_POLICY
   LidOpenWake                 AS LONG                  ' SYSTEM_POWER_STATE
   Reserved                    AS DWORD                 ' DWORD
   ' "system idle" detection
   Idle                        AS POWER_ACTION_POLICY   ' POWER_ACTION_POLICY
   IdleTimeout                 AS DWORD                 ' DWORD
   IdleSensitivity             AS BYTE                  ' BYTE
   ' dynamic throttling policy
   '      PO_THROTTLE_NONE, PO_THROTTLE_CONSTANT, PO_THROTTLE_DEGRADE, or PO_THROTTLE_ADAPTIVE
   DynamicThrottle             AS BYTE                  ' BYTE
   Spare2(1)                   AS BYTE                  ' BYTE
   ' meaning of power action "sleep"
   MinSleep                    AS LONG                  ' SYSTEM_POWER_STATE
   MaxSleep                    AS LONG                  ' SYSTEM_POWER_STATE
   ReducedLatencySleep         AS LONG                  ' SYSTEM_POWER_STATE
   WinLogonFlags               AS DWORD                 ' DWORD
   ' parameters for dozing
   Spare3                      AS DWORD                 ' DWORD
   DozeS4Timeout               AS DWORD                 ' DWORD
   ' battery policies
   BroadcastCapacityResolution AS DWORD                 ' DWORD
   DischargePolicy(%NUM_DISCHARGE_POLICIES - 1) AS SYSTEM_POWER_LEVEL
   ' video policies
   VideoTimeout                AS DWORD                 ' DWORD
   VideoDimDisplay             AS BYTE                  ' BOOLEAN
   VideoReserved(2)            AS DWORD                 ' DWORD
   ' hard disk policies
   SpindownTimeout             AS DWORD                 ' DWORD
   ' processor policies
   OptimizeForPower            AS BYTE                  ' BOOLEAN
   FanThrottleTolerance        AS BYTE                  ' BYTE
   ForcedThrottle              AS BYTE                  ' BYTE
   MinThrottle                 AS BYTE                  ' BYTE
   OverThrottled               AS POWER_ACTION_POLICY   ' POWER_ACTION_POLICY
END TYPE

'// processor power policy state

'//
'// Processor Idle State Policy.
'//

%PROCESSOR_IDLESTATE_POLICY_COUNT = &H3

' // Size = 8 bytes
TYPE PROCESSOR_IDLESTATE_INFO BYTE
   TimeCheck      AS DWORD   ' DWORD
   DemotePercent  AS BYTE    ' BYTE
   PromotePercent AS BYTE    ' BYTE
   Spare(1)       AS BYTE    ' BYTE
END TYPE

' // Size = 2 bytes
TYPE PROCESSOR_IDLESTATE_POLICY_UNNAMED_STRUCT WORD
   AllowScaling AS BIT * 1 IN WORD
   Disabled     AS BIT * 1
   Reserved     AS BIT * 14
END TYPE

' // Size = 2 bytes
UNION PROCESSOR_IDLESTATE_POLICY_UNNAMED_UNION WORD
   AsWORD  AS WORD   ' WORD
   PROCESSOR_IDLESTATE_POLICY_UNNAMED_STRUCT
END UNION

' // Size = 32 bytes
TYPE PROCESSOR_IDLESTATE_POLICY DWORD FILL
   Revision    AS WORD    ' WORD
   Flags       AS PROCESSOR_IDLESTATE_POLICY_UNNAMED_UNION
   PolicyCount AS DWORD   ' DWORD
   Policy(%PROCESSOR_IDLESTATE_POLICY_COUNT - 1) AS PROCESSOR_IDLESTATE_INFO
END TYPE

'//
'// Legacy Processor Policy.  This is only provided to allow legacy
'// applications to compile.  New applications must use
'// PROCESSOR_IDLESTATE_POLICY.
'//

%PO_THROTTLE_NONE     = 0
%PO_THROTTLE_CONSTANT = 1
%PO_THROTTLE_DEGRADE  = 2
%PO_THROTTLE_ADAPTIVE = 3
%PO_THROTTLE_MAXIMUM  = 4   ' not a policy, just a limit

'typedef struct _PROCESSOR_POWER_POLICY_INFO {

'    // Time based information (will be converted to kernel units)
'    DWORD                   TimeCheck;                      // in US
'    DWORD                   DemoteLimit;                    // in US
'    DWORD                   PromoteLimit;                   // in US

'    // Percentage based information
'    BYTE                    DemotePercent;
'    BYTE                    PromotePercent;
'    BYTE                    Spare[2];

'    // Flags
'    DWORD                   AllowDemotion:1;
'    DWORD                   AllowPromotion:1;
'    DWORD                   Reserved:30;

'} PROCESSOR_POWER_POLICY_INFO, *PPROCESSOR_POWER_POLICY_INFO;

' // Size = 20 bytes
TYPE PROCESSOR_POWER_POLICY_INFO DWORD FILL
   ' Time based information (will be converted to kernel units)
   TimeCheck      AS DWORD       ' DWORD // in US
   DemoteLimit    AS DWORD       ' DWORD // in US
   PromoteLimit   AS DWORD       ' DWORD // in US
   ' Percentage based information
   DemotePercent  AS BYTE        ' BYTE
   PromotePercent AS BYTE        ' BYTE
   Spare(1)       AS BYTE        ' BYTE[2]
   ' Flags
   AllowDemotion  AS BIT * 1 IN DWORD
   AllowPromotion AS BIT * 1
   Reserved       AS BIT * 30
END TYPE

'// processor power policy
'typedef struct _PROCESSOR_POWER_POLICY {
'    DWORD                       Revision;       // 1

'    // Dynamic Throttling Policy
'    BYTE                        DynamicThrottle;
'    BYTE                        Spare[3];

'    // Flags
'    DWORD                       DisableCStates:1;
'    DWORD                       Reserved:31;

'    // System policy information
'    // The Array is last, in case it needs to be grown and the structure
'    // revision incremented.
'    DWORD                       PolicyCount;
'    PROCESSOR_POWER_POLICY_INFO Policy[3];

'} PROCESSOR_POWER_POLICY, *PPROCESSOR_POWER_POLICY;

' // Size = 76 bytes
TYPE PROCESSOR_POWER_POLICY DWORD FILL
   Revision        AS DWORD
   ' Dynamic Throttling Policy
   DynamicThrottle AS BYTE
   Spare(2)        AS BYTE
   ' Flags
   DisableCStates  AS BIT * 1 IN DWORD
   Reserved        AS BIT * 31
   ' System policy information
   ' The Array is last, in case it needs to be grown and the structure
   ' revision incremented.
   PolicyCount     AS DWORD
   Policy(2)       AS PROCESSOR_POWER_POLICY_INFO
END TYPE

'// processor power policy
' // Size = 1 byte
TYPE PROCESSOR_PERFSTATE_POLICY_UNNAMED_STRUCT BYTE
   NoDomainAccounting AS BIT * 1 IN BYTE
   IncreasePolicy     AS BIT * 2
   DecreasePolicy     AS BIT * 2
   Reserved           AS BIT * 3
END TYPE

' // Size = 1 byte
UNION PROCESSOR_PERFSTATE_POLICY_UNNAMED_UNION BYTE
   AsBYTE AS BYTE   ' BYTE
   PROCESSOR_PERFSTATE_POLICY_UNNAMED_STRUCT
END UNION

' // Size = 28 bytes
TYPE PROCESSOR_PERFSTATE_POLICY DWORD FILL
   Revision         AS DWORD   ' DWORD
   MaxThrottle      AS BYTE    ' BYTE
   MinThrottle      AS BYTE    ' BYTE
   BusyAdjThreshold AS BYTE    ' BYTE
   Flags            AS PROCESSOR_PERFSTATE_POLICY_UNNAMED_UNION
   TimeCheck        AS DWORD   ' DWORD
   IncreaseTime     AS DWORD   ' DWORD
   DecreaseTime     AS DWORD   ' DWORD
   IncreasePercent  AS DWORD   ' DWORD
   DecreasePercent  AS DWORD   ' DWORD
END TYPE

'// administrator power policy overrides
' // Size = 24 bytes
TYPE ADMINISTRATOR_POWER_POLICY DWORD
   ' meaning of power action "sleep"
   MinSleep           AS LONG    ' SYSTEM_POWER_STATE
   MaxSleep           AS LONG    ' SYSTEM_POWER_STATE
   ' video policies
   MinVideoTimeout    AS DWORD   ' DWORD
   MaxVideoTimeout    AS DWORD   ' DWORD
   ' disk policies
   MinSpindownTimeout AS DWORD   ' DWORD
   MaxSpindownTimeout AS DWORD   ' DWORD
END TYPE

' // Size = 76 bytes
TYPE SYSTEM_POWER_CAPABILITIES BYTE
   ' Misc supported system features
   PowerButtonPresent     AS BYTE   ' BOOLEAN
   SleepButtonPresent     AS BYTE   ' BOOLEAN
   LidPresent             AS BYTE   ' BOOLEAN
   SystemS1               AS BYTE   ' BOOLEAN
   SystemS2               AS BYTE   ' BOOLEAN
   SystemS3               AS BYTE   ' BOOLEAN
   SystemS4               AS BYTE   ' BOOLEAN  // hibernate
   SystemS5               AS BYTE   ' BOOLEAN  // off
   HiberFilePresent       AS BYTE   ' BOOLEAN
   FullWake               AS BYTE   ' BOOLEAN
   VideoDimPresent        AS BYTE   ' BOOLEAN
   ApmPresent             AS BYTE   ' BOOLEAN
   UpsPresent             AS BYTE   ' BOOLEAN

   ' Processors
   ThermalControl         AS BYTE   ' BOOLEAN
   ProcessorThrottle      AS BYTE   ' BOOLEAN
   ProcessorMinThrottle   AS BYTE   ' BYTE
'#if (NTDDI_VERSION < NTDDI_WINXP)
#IF %WINVER < &H0501
   ProcessorThrottleScale AS BYTE   ' BYTE
   spare2(3)              AS BYTE   ' BYTE[4]
#ELSE
   ProcessorMaxThrottle   AS BYTE   ' BYTE
   FastSystemS4           AS BYTE   ' BOOLEAN
   spare2(2)              AS BYTE   ' BYTE[3]
#ENDIF   ' // (NTDDI_VERSION < NTDDI_WINXP)

   ' Disk
   DiskSpinDown           AS BYTE   ' BOOLEAN
   spare3(7)              AS BYTE   ' BYTE[8]

   ' System Battery
   SystemBatteriesPresent AS BYTE   ' BOOLEAN
   BatteriesAreShortTerm  AS BYTE   ' BOOLEAN
   BatteryScale(2)        AS BATTERY_REPORTING_SCALE   ' BATTERY_REPORTING_SCALE[3]

   ' Wake
   AcOnLineWake           AS LONG   ' SYSTEM_POWER_STATE
   SoftLidWake            AS LONG   ' SYSTEM_POWER_STATE
   RtcWake                AS LONG   ' SYSTEM_POWER_STATE
   MinDeviceWakeState     AS LONG   ' SYSTEM_POWER_STATE ' note this may change on driver load
   DefaultLowLatencyWake  AS LONG   ' SYSTEM_POWER_STATE
END TYPE

' // Size = 32 bytes
TYPE SYSTEM_BATTERY_STATE BYTE
   AcOnLine          AS BYTE    ' BOOLEAN
   BatteryPresent    AS BYTE    ' BOOLEAN
   Charging          AS BYTE    ' BOOLEAN
   Discharging       AS BYTE    ' BOOLEAN
   Spare1(3)         AS BYTE    ' BOOLEAN[4]

   MaxCapacity       AS DWORD   ' DWORD
   RemainingCapacity AS DWORD   ' DWORD
   Rate              AS DWORD   ' DWORD
   EstimatedTime     AS DWORD   ' DWORD

   DefaultAlert1     AS DWORD   ' DWORD
   DefaultAlert2     AS DWORD   ' DWORD
END TYPE

'//
'// Image Format
'//

'#ifndef _MAC

'#include "pshpack4.h"                   // 4 byte packing is the default

'#define IMAGE_DOS_SIGNATURE                 0x5A4D      // MZ
'#define IMAGE_OS2_SIGNATURE                 0x454E      // NE
'#define IMAGE_OS2_SIGNATURE_LE              0x454C      // LE
'#define IMAGE_VXD_SIGNATURE                 0x454C      // LE
'#define IMAGE_NT_SIGNATURE                  0x00004550  // PE00

'#include "pshpack2.h"                   // 16 bit headers are 2 byte packed

'#else

'#include "pshpack1.h"

%IMAGE_DOS_SIGNATURE    = &H5A4D      ' MZ
%IMAGE_OS2_SIGNATURE    = &H454E      ' NE
%IMAGE_OS2_SIGNATURE_LE = &H454C      ' LE
%IMAGE_VXD_SIGNATURE    = &H454C      ' LE
%IMAGE_NT_SIGNATURE     = &H00004550  ' PE00

' // Size = 64 bytes
TYPE IMAGE_DOS_HEADER BYTE
   e_magic    AS WORD   ' WORD // Magic number
   e_cblp     AS WORD   ' WORD // Bytes on last page of file
   e_cp       AS WORD   ' WORD // Pages in file
   e_crlc     AS WORD   ' WORD // Relocations
   e_cparhdr  AS WORD   ' WORD // Size of header in paragraphs
   e_minalloc AS WORD   ' WORD // Minimum extra paragraphs needed
   e_maxalloc AS WORD   ' WORD // Maximum extra paragraphs needed
   e_ss       AS WORD   ' WORD // Initial (relative) SS value
   e_sp       AS WORD   ' WORD // Initial SP value
   e_csum     AS WORD   ' WORD // Checksum
   e_ip       AS WORD   ' WORD // Initial IP value
   e_cs       AS WORD   ' WORD // Initial (relative) CS value
   e_lfarlc   AS WORD   ' WORD // File address of relocation table
   e_ovno     AS WORD   ' WORD // Overlay number
   e_res(3)   AS WORD   ' WORD[4] // Reserved words
   e_oemid    AS WORD   ' WORD // OEM identifier (for e_oeminfo)
   e_oeminfo  AS WORD   ' WORD // OEM information; e_oemid specific
   e_res2(9)  AS WORD   ' WORD[10] // Reserved words
   e_lfanew   AS LONG   ' LONG // File address of new exe header
END TYPE

' // Size = 64 bytes
TYPE IMAGE_OS2_HEADER BYTE   ' OS/2 .EXE header
   ne_magic        AS WORD   ' WORD // Magic number
   ne_ver          AS BYTE   ' CHAR // Version number
   ne_rev          AS BYTE   ' CHAR // Revision number
   ne_enttab       AS WORD   ' WORD // Offset of Entry Table
   ne_cbenttab     AS WORD   ' WORD // Number of bytes in Entry Table
   ne_crc          AS LONG   ' LONG // Checksum of whole file
   ne_flags        AS WORD   ' WORD // Flag word
   ne_autodata     AS WORD   ' WORD // Automatic data segment number
   ne_heap         AS WORD   ' WORD // Initial heap allocation
   ne_stack        AS WORD   ' WORD // Initial stack allocation
   ne_csip         AS LONG   ' LONG // Initial CS:IP setting
   ne_sssp         AS LONG   ' LONG // Initial SS:SP setting
   ne_cseg         AS WORD   ' WORD // Count of file segments
   ne_cmod         AS WORD   ' WORD // Entries in Module Reference Table
   ne_cbnrestab    AS WORD   ' WORD // Size of non-resident name table
   ne_segtab       AS WORD   ' WORD // Offset of Segment Table
   ne_rsrctab      AS WORD   ' WORD // Offset of Resource Table
   ne_restab       AS WORD   ' WORD // Offset of resident name table
   ne_modtab       AS WORD   ' WORD // Offset of Module Reference Table
   ne_imptab       AS WORD   ' WORD // Offset of Imported Names Table
   ne_nrestab      AS LONG   ' LONG // Offset of Non-resident Names Table
   ne_cmovent      AS WORD   ' WORD // Count of movable entries
   ne_align        AS WORD   ' WORD // Segment alignment shift count
   ne_cres         AS WORD   ' WORD // Count of resource segments
   ne_exetyp       AS BYTE   ' BYTE // Target Operating system
   ne_flagsothers  AS BYTE   ' BYTE // Other .EXE flags
   ne_pretthunks   AS WORD   ' WORD // offset to return thunks
   ne_psegrefbytes AS WORD   ' WORD // offset to segment ref. bytes
   ne_swaparea     AS WORD   ' WORD // Minimum code swap area size
   ne_expver       AS WORD   ' WORD // Expected Windows version number
END TYPE

' // Size = 196 bytes
TYPE IMAGE_VXD_HEADER BYTE           ' Windows VXD header
   e32_magic        AS WORD          ' WORD  // Magic number
   e32_border       AS BYTE          ' BYTE  // The byte ordering for the VXD
   e32_worder       AS BYTE          ' BYTE  // The word ordering for the VXD
   e32_level        AS DWORD         ' DWORD // The EXE format level for now = 0
   e32_cpu          AS WORD          ' WORD  // The CPU type
   e32_os           AS WORD          ' WORD  // The OS type
   e32_ver          AS DWORD         ' DWORD // Module version
   e32_mflags       AS DWORD         ' DWORD // Module flags
   e32_mpages       AS DWORD         ' DWORD // Module # pages
   e32_startobj     AS DWORD         ' DWORD // Object # for instruction pointer
   e32_eip          AS DWORD         ' DWORD // Extended instruction pointer
   e32_stackobj     AS DWORD         ' DWORD // Object # for stack pointer
   e32_esp          AS DWORD         ' DWORD // Extended stack pointer
   e32_pagesize     AS DWORD         ' DWORD // VXD page size
   e32_lastpagesize AS DWORD         ' DWORD // Last page size in VXD
   e32_fixupsize    AS DWORD         ' DWORD // Fixup section size
   e32_fixupsum     AS DWORD         ' DWORD // Fixup section checksum
   e32_ldrsize      AS DWORD         ' DWORD // Loader section size
   e32_ldrsum       AS DWORD         ' DWORD // Loader section checksum
   e32_objtab       AS DWORD         ' DWORD // Object table offset
   e32_objcnt       AS DWORD         ' DWORD // Number of objects in module
   e32_objmap       AS DWORD         ' DWORD // Object page map offset
   e32_itermap      AS DWORD         ' DWORD // Object iterated data map offset
   e32_rsrctab      AS DWORD         ' DWORD // Offset of Resource Table
   e32_rsrccnt      AS DWORD         ' DWORD // Number of resource entries
   e32_restab       AS DWORD         ' DWORD // Offset of resident name table
   e32_enttab       AS DWORD         ' DWORD // Offset of Entry Table
   e32_dirtab       AS DWORD         ' DWORD // Offset of Module Directive Table
   e32_dircnt       AS DWORD         ' DWORD // Number of module directives
   e32_fpagetab     AS DWORD         ' DWORD // Offset of Fixup Page Table
   e32_frectab      AS DWORD         ' DWORD // Offset of Fixup Record Table
   e32_impmod       AS DWORD         ' DWORD // Offset of Import Module Name Table
   e32_impmodcnt    AS DWORD         ' DWORD // Number of entries in Import Module Name Table
   e32_impproc      AS DWORD         ' DWORD // Offset of Import Procedure Name Table
   e32_pagesum      AS DWORD         ' DWORD // Offset of Per-Page Checksum Table
   e32_datapage     AS DWORD         ' DWORD // Offset of Enumerated Data Pages
   e32_preload      AS DWORD         ' DWORD // Number of preload pages
   e32_nrestab      AS DWORD         ' DWORD // Offset of Non-resident Names Table
   e32_cbnrestab    AS DWORD         ' DWORD // Size of Non-resident Name Table
   e32_nressum      AS DWORD         ' DWORD // Non-resident Name Table Checksum
   e32_autodata     AS DWORD         ' DWORD // Object # for automatic data object
   e32_debuginfo    AS DWORD         ' DWORD // Offset of the debugging information
   e32_debuglen     AS DWORD         ' DWORD // The length of the debugging info. in bytes
   e32_instpreload  AS DWORD         ' DWORD // Number of instance pages in preload section of VXD file
   e32_instdemand   AS DWORD         ' DWORD // Number of instance pages in demand load section of VXD file
   e32_heapsize     AS DWORD         ' DWORD // Size of heap - for 16-bit apps
   e32_res3(11)     AS BYTE          ' BYTE  //Reserved words
   e32_winresoff    AS DWORD         ' DWORD
   e32_winreslen    AS DWORD         ' DWORD
   e32_devid        AS WORD          ' WORD  // Device ID for VxD
   e32_ddkver       AS WORD          ' WORD  // DDK version for VxD
END TYPE

'#ifndef _MAC
'#include "poppack.h"                    // Back to 4 byte packing
'#endif

'//
'// File header format.
'//

' // Size = 20 bytes
TYPE IMAGE_FILE_HEADER DWORD FILL
   Machine              AS WORD
   NumberOfSections     AS WORD
   TimeDateStamp        AS DWORD
   PointerToSymbolTable AS DWORD
   NumberOfSymbols      AS DWORD
   SizeOfOptionalHeader AS WORD
   Characteristics      AS WORD
END TYPE

%IMAGE_SIZEOF_FILE_HEADER = 20

%IMAGE_FILE_RELOCS_STRIPPED         = &H00000001???  ' Relocation info stripped from file.
%IMAGE_FILE_EXECUTABLE_IMAGE        = &H00000002???  ' File is executable  (i.e. no unresolved externel references).
%IMAGE_FILE_LINE_NUMS_STRIPPED      = &H00000004???  ' Line nunbers stripped from file.
%IMAGE_FILE_LOCAL_SYMS_STRIPPED     = &H00000008???  ' Local symbols stripped from file.
%IMAGE_FILE_AGGRESIVE_WS_TRIM       = &H00000010???  ' Agressively trim working set
%IMAGE_FILE_LARGE_ADDRESS_AWARE     = &H00000020???  ' App can handle >2gb addresses
%IMAGE_FILE_BYTES_REVERSED_LO       = &H00000080???  ' Bytes of machine word are reversed.
%IMAGE_FILE_32BIT_MACHINE           = &H00000100???  ' 32 bit word machine.
%IMAGE_FILE_DEBUG_STRIPPED          = &H00000200???  ' Debugging info stripped from file in .DBG file
%IMAGE_FILE_REMOVABLE_RUN_FROM_SWAP = &H00000400???  ' If Image is on removable media, copy and run from the swap file.
%IMAGE_FILE_NET_RUN_FROM_SWAP       = &H00000800???  ' If Image is on Net, copy and run from the swap file.
%IMAGE_FILE_SYSTEM                  = &H00001000???  ' System File.
%IMAGE_FILE_DLL                     = &H00002000???  ' File is a DLL.
%IMAGE_FILE_UP_SYSTEM_ONLY          = &H00004000???  ' File should only be run on a UP machine
%IMAGE_FILE_BYTES_REVERSED_HI       = &H00008000???  ' Bytes of machine word are reversed.

%IMAGE_FILE_MACHINE_UNKNOWN         = 0???
%IMAGE_FILE_MACHINE_I386            = &H014c???  ' Intel 386.
%IMAGE_FILE_MACHINE_R3000           = &H0162???  ' MIPS little-endian, = &H160 big-endian
%IMAGE_FILE_MACHINE_R4000           = &H0166???  ' MIPS little-endian
%IMAGE_FILE_MACHINE_R10000          = &H0168???  ' MIPS little-endian
%IMAGE_FILE_MACHINE_WCEMIPSV2       = &H0169???  ' MIPS little-endian WCE v2
%IMAGE_FILE_MACHINE_ALPHA           = &H0184???  ' Alpha_AXP
%IMAGE_FILE_MACHINE_SH3             = &H01a2???  ' SH3 little-endian
%IMAGE_FILE_MACHINE_SH3DSP          = &H01a3???
%IMAGE_FILE_MACHINE_SH3E            = &H01a4???  ' SH3E little-endian
%IMAGE_FILE_MACHINE_SH4             = &H01a6???  ' SH4 little-endian
%IMAGE_FILE_MACHINE_SH5             = &H01a8???  ' SH5
%IMAGE_FILE_MACHINE_ARM             = &H01c0???  ' ARM Little-Endian
%IMAGE_FILE_MACHINE_THUMB           = &H01c2???
%IMAGE_FILE_MACHINE_AM33            = &H01d3???
%IMAGE_FILE_MACHINE_POWERPC         = &H01F0???  ' IBM PowerPC Little-Endian
%IMAGE_FILE_MACHINE_POWERPCFP       = &H01f1???
%IMAGE_FILE_MACHINE_IA64            = &H0200???  ' Intel 64
%IMAGE_FILE_MACHINE_MIPS16          = &H0266???  ' MIPS
%IMAGE_FILE_MACHINE_ALPHA64         = &H0284???  ' ALPHA64
%IMAGE_FILE_MACHINE_MIPSFPU         = &H0366???  ' MIPS
%IMAGE_FILE_MACHINE_MIPSFPU16       = &H0466???  ' MIPS
%IMAGE_FILE_MACHINE_AXP64           = %IMAGE_FILE_MACHINE_ALPHA64
%IMAGE_FILE_MACHINE_TRICORE         = &H0520???  ' // Infineon
%IMAGE_FILE_MACHINE_CEF             = &H0CEF???
%IMAGE_FILE_MACHINE_EBC             = &H0EBC???  ' // EFI Byte Code
%IMAGE_FILE_MACHINE_AMD64           = &H8664???  ' // AMD64 (K8)
%IMAGE_FILE_MACHINE_M32R            = &H9041???  ' // M32R little-endian
%IMAGE_FILE_MACHINE_CEE             = &HC0EE???

'//
'// Directory format.
'//

' // Size = 8 bytes
TYPE IMAGE_DATA_DIRECTORY DWORD
   VirtualAddress AS DWORD
   nSize          AS DWORD
END TYPE

%IMAGE_NUMBEROF_DIRECTORY_ENTRIES   = 16

'//
'// Optional header format.
'//

' // Size = 224 bytes
TYPE IMAGE_OPTIONAL_HEADER DWORD FILL
   ' Standard fields.
   Magic                       AS WORD
   MajorLinkerVersion          AS BYTE
   MinorLinkerVersion          AS BYTE
   SizeOfCode                  AS DWORD
   SizeOfInitializedData       AS DWORD
   SizeOfUninitializedData     AS DWORD
   AddressOfEntryPoint         AS DWORD
   BaseOfCode                  AS DWORD
   BaseOfData                  AS DWORD
   ' NT additional fields.
   ImageBase                   AS DWORD
   SectionAlignment            AS DWORD
   FileAlignment               AS DWORD
   MajorOperatingSystemVersion AS WORD
   MinorOperatingSystemVersion AS WORD
   MajorImageVersion           AS WORD
   MinorImageVersion           AS WORD
   MajorSubsystemVersion       AS WORD
   MinorSubsystemVersion       AS WORD
   Win32VersionValue           AS DWORD
   SizeOfImage                 AS DWORD
   SizeOfHeaders               AS DWORD
   CheckSum                    AS DWORD
   Subsystem                   AS WORD
   DllCharacteristics          AS WORD
   SizeOfStackReserve          AS DWORD
   SizeOfStackCommit           AS DWORD
   SizeOfHeapReserve           AS DWORD
   SizeOfHeapCommit            AS DWORD
   LoaderFlags                 AS DWORD
   NumberOfRvaAndSizes         AS DWORD
   DataDirectory(%IMAGE_NUMBEROF_DIRECTORY_ENTRIES - 1) AS IMAGE_DATA_DIRECTORY
END TYPE

MACRO IMAGE_OPTIONAL_HEADER32 = IMAGE_OPTIONAL_HEADER

' // Size = 56 bytes
TYPE IMAGE_ROM_OPTIONAL_HEADER DWORD FILL
   Magic                   AS WORD
   MajorLinkerVersion      AS BYTE
   MinorLinkerVersion      AS BYTE
   SizeOfCode              AS DWORD
   SizeOfInitializedData   AS DWORD
   SizeOfUninitializedData AS DWORD
   AddressOfEntryPoint     AS DWORD
   BaseOfCode              AS DWORD
   BaseOfData              AS DWORD
   BaseOfBss               AS DWORD
   GprMask                 AS DWORD
   CprMask(3)              AS DWORD
   GpValue                 AS DWORD
END TYPE

' // Size = 240 bytes
TYPE IMAGE_OPTIONAL_HEADER64   ' Must be 8 byte aligned
   Magic                       AS WORD
   MajorLinkerVersion          AS BYTE
   MinorLinkerVersion          AS BYTE
   SizeOfCode                  AS DWORD
   SizeOfInitializedData       AS DWORD
   SizeOfUninitializedData     AS DWORD
   AddressOfEntryPoint         AS DWORD
   BaseOfCode                  AS DWORD
   ImageBase                   AS QUAD    ' ULONGLONG
   SectionAlignment            AS DWORD
   FileAlignment               AS DWORD
   MajorOperatingSystemVersion AS WORD
   MinorOperatingSystemVersion AS WORD
   MajorImageVersion           AS WORD
   MinorImageVersion           AS WORD
   MajorSubsystemVersion       AS WORD
   MinorSubsystemVersion       AS WORD
   Win32VersionValue           AS DWORD
   SizeOfImage                 AS DWORD
   SizeOfHeaders               AS DWORD
   CheckSum                    AS DWORD
   Subsystem                   AS WORD
   DllCharacteristics          AS WORD
   SizeOfStackReserve          AS QUAD    ' ULONGLONG
   SizeOfStackCommit           AS QUAD    ' ULONGLONG
   SizeOfHeapReserve           AS QUAD    ' ULONGLONG
   SizeOfHeapCommit            AS QUAD    ' ULONGLONG
   LoaderFlags                 AS DWORD
   NumberOfRvaAndSizes         AS DWORD
   DataDirectory(%IMAGE_NUMBEROF_DIRECTORY_ENTRIES - 1) AS IMAGE_DATA_DIRECTORY
END TYPE

'%IMAGE_SIZEOF_ROM_OPTIONAL_HEADER  =  56
'%IMAGE_SIZEOF_STD_OPTIONAL_HEADER  =  28
'%IMAGE_SIZEOF_NT_OPTIONAL32_HEADER = 224
'%IMAGE_SIZEOF_NT_OPTIONAL64_HEADER = 240

%IMAGE_NT_OPTIONAL_HDR32_MAGIC     = &H10b
%IMAGE_NT_OPTIONAL_HDR64_MAGIC     = &H20b
%IMAGE_ROM_OPTIONAL_HDR_MAGIC      = &H107

' // Size = 264 bytes
TYPE IMAGE_NT_HEADERS64 DWORD
   Signature      AS DWORD
   FileHeader     AS IMAGE_FILE_HEADER
   OptionalHeader AS IMAGE_OPTIONAL_HEADER64
END TYPE

' // Size = 248 bytes
TYPE IMAGE_NT_HEADERS DWORD
   Signature      AS DWORD
   FileHeader     AS IMAGE_FILE_HEADER
   OptionalHeader AS IMAGE_OPTIONAL_HEADER
END TYPE

MACRO IMAGE_NT_HEADERS32 = IMAGE_NT_HEADERS

' // Size = 76 bytes
TYPE IMAGE_ROM_HEADERS DWORD
   FileHeader     AS IMAGE_FILE_HEADER
   OptionalHeader AS IMAGE_ROM_OPTIONAL_HEADER
END TYPE

'// IMAGE_FIRST_SECTION doesn't need 32/64 versions since the file header is the same either way.

'#define IMAGE_FIRST_SECTION( ntheader ) ((PIMAGE_SECTION_HEADER)        \
'    ((ULONG_PTR)(ntheader) +                                            \
'     FIELD_OFFSET( IMAGE_NT_HEADERS, OptionalHeader ) +                 \
'     ((ntheader))->FileHeader.SizeOfOptionalHeader   \
'    ))

'// Subsystem Values

%IMAGE_SUBSYSTEM_UNKNOWN                  = 0    ' // Unknown subsystem.
%IMAGE_SUBSYSTEM_NATIVE                   = 1    ' // Image doesn't require a subsystem.
%IMAGE_SUBSYSTEM_WINDOWS_GUI              = 2    ' // Image runs in the Windows GUI subsystem.
%IMAGE_SUBSYSTEM_WINDOWS_CUI              = 3    ' // Image runs in the Windows character subsystem.
%IMAGE_SUBSYSTEM_OS2_CUI                  = 5    ' // image runs in the OS/2 character subsystem.
%IMAGE_SUBSYSTEM_POSIX_CUI                = 7    ' // image runs in the Posix character subsystem.
%IMAGE_SUBSYSTEM_NATIVE_WINDOWS           = 8    ' // image is a native Win9x driver.
%IMAGE_SUBSYSTEM_WINDOWS_CE_GUI           = 9    ' // Image runs in the Windows CE subsystem.
%IMAGE_SUBSYSTEM_EFI_APPLICATION          = 10   '
%IMAGE_SUBSYSTEM_EFI_BOOT_SERVICE_DRIVER  = 11
%IMAGE_SUBSYSTEM_EFI_RUNTIME_DRIVER       = 12
%IMAGE_SUBSYSTEM_EFI_ROM                  = 13
%IMAGE_SUBSYSTEM_XBOX                     = 14
%IMAGE_SUBSYSTEM_WINDOWS_BOOT_APPLICATION = 16

'// DllCharacteristics Entries

'//      IMAGE_LIBRARY_PROCESS_INIT             0x0001     // Reserved.
'//      IMAGE_LIBRARY_PROCESS_TERM             0x0002     // Reserved.
'//      IMAGE_LIBRARY_THREAD_INIT              0x0004     // Reserved.
'//      IMAGE_LIBRARY_THREAD_TERM              0x0008     // Reserved.
%IMAGE_DLLCHARACTERISTICS_DYNAMIC_BASE          = &H0040   ' // DLL can move.
%IMAGE_DLLCHARACTERISTICS_FORCE_INTEGRITY       = &H0080   ' // Code Integrity Image
%IMAGE_DLLCHARACTERISTICS_NX_COMPAT             = &H0100   ' // Image is NX compatible
%IMAGE_DLLCHARACTERISTICS_NO_ISOLATION          = &H0200   ' // Image understands isolation and doesn't want it
%IMAGE_DLLCHARACTERISTICS_NO_SEH                = &H0400   ' // Image does not use SEH.  No SE handler may reside in this image
%IMAGE_DLLCHARACTERISTICS_NO_BIND               = &H0800   ' Do not bind this image.
'//                                             0x1000     // Reserved.
%IMAGE_DLLCHARACTERISTICS_WDM_DRIVER            = &H2000   ' Driver uses WDM model
'//                                             0x4000     // Reserved.
%IMAGE_DLLCHARACTERISTICS_TERMINAL_SERVER_AWARE = &H00008000

'// Directory Entries

%IMAGE_DIRECTORY_ENTRY_EXPORT         = 0  ' // Export Directory
%IMAGE_DIRECTORY_ENTRY_IMPORT         = 1  ' // Import Directory
%IMAGE_DIRECTORY_ENTRY_RESOURCE       = 2  ' // Resource Directory
%IMAGE_DIRECTORY_ENTRY_EXCEPTION      = 3  ' // Exception Directory
%IMAGE_DIRECTORY_ENTRY_SECURITY       = 4  ' // Security Directory
%IMAGE_DIRECTORY_ENTRY_BASERELOC      = 5  ' // Base Relocation Table
%IMAGE_DIRECTORY_ENTRY_DEBUG          = 6  ' // Debug Directory
'// IMAGE_DIRECTORY_ENTRY_COPYRIGHT     =  7   // (X86 usage)
%IMAGE_DIRECTORY_ENTRY_COPYRIGHT     =  7  ' // (X86 usage)
%IMAGE_DIRECTORY_ENTRY_ARCHITECTURE   = 7  ' // Architecture Specific Data
%IMAGE_DIRECTORY_ENTRY_GLOBALPTR      = 8  ' // RVA of GP
%IMAGE_DIRECTORY_ENTRY_TLS            = 9  ' // TLS Directory
%IMAGE_DIRECTORY_ENTRY_LOAD_CONFIG    = 10  ' // Load Configuration Directory
%IMAGE_DIRECTORY_ENTRY_BOUND_IMPORT   = 11  ' // Bound Import Directory in headers
%IMAGE_DIRECTORY_ENTRY_IAT            = 12  ' // Import Address Table
%IMAGE_DIRECTORY_ENTRY_DELAY_IMPORT   = 13  ' // Delay Load Import Descriptors
%IMAGE_DIRECTORY_ENTRY_COM_DESCRIPTOR = 14  ' // COM Runtime descriptor

'//
'// Non-COFF Object file header
'//

' // Size = 32 bytes
TYPE ANON_OBJECT_HEADER DWORD FILL
   Sig1          AS WORD    ' WORD  // Must be %IMAGE_FILE_MACHINE_UNKNOWN
   Sig2          AS WORD    ' WORD  // Must be &HFFFF??
   Version       AS WORD    ' WORD  //  >= 1 (implies the ClassID field is present)
   Machine       AS WORD    ' WORD
   TimeDateStamp AS DWORD   ' DWORD
   ClassID       AS GUID    ' CLSID // Used to invoke CoCreateInstance
   SizeOfData    AS DWORD   ' DWORD // Size of data that follows the header
END TYPE

' // Size = 44 bytes
TYPE ANON_OBJECT_HEADER_V2 DWORD FILL
   Sig1           AS WORD    ' WORD  // Must be %IMAGE_FILE_MACHINE_UNKNOWN
   Sig2           AS WORD    ' WORD  // Must be &HFFFF??
   Version        AS WORD    ' WORD  //  >= 1 (implies the ClassID field is present)
   Machine        AS WORD    ' WORD
   TimeDateStamp  AS DWORD   ' DWORD
   ClassID        AS GUID    ' CLSID // Used to invoke CoCreateInstance
   SizeOfData     AS DWORD   ' DWORD // Size of data that follows the header
   Flags          AS DWORD   ' DWORD // 0x1 -> contains metadata
   MetaDataSize   AS DWORD   ' DWORD // Size of CLR metadata
   MetaDataOffset AS DWORD   ' DWORD // Offset of CLR metadata
END TYPE

' // Size = 56 bytes
TYPE ANON_OBJECT_HEADER_BIGOBJ DWORD FILL
   ' /* same as ANON_OBJECT_HEADER_V2 */
   Sig1                 AS WORD    ' WORD  // Must be IMAGE_FILE_MACHINE_UNKNOWN
   Sig2                 AS WORD    ' WORD  // Must be 0xffff
   Version              AS WORD    ' WORD  // >= 2 (implies the Flags field is present)
   Machine              AS WORD    ' WORD  // Actual machine - IMAGE_FILE_MACHINE_xxx
   TimeDateStamp        AS DWORD   ' DWORD
   ClassID              AS GUID    ' CLSID // {D1BAA1C7-BAEE-4ba9-AF20-FAF66AA4DCB8}
   SizeOfData           AS DWORD   ' DWORD // Size of data that follows the header
   Flags                AS DWORD   ' DWORD // 0x1 -> contains metadata
   MetaDataSize         AS DWORD   ' DWORD // Size of CLR metadata
   MetaDataOffset       AS DWORD   ' DWORD // Offset of CLR metadata
   ' /* bigobj specifics */
   NumberOfSections     AS DWORD   ' DWORD // extended from WORD
   PointerToSymbolTable AS DWORD   ' DWORD
   NumberOfSymbols      AS DWORD   ' DWORD
END TYPE

'//
'// Section header format.
'//

%IMAGE_SIZEOF_SHORT_NAME = 8

' // Size = 8 bytes
UNION MiscUnionISH DWORD
   PhysicalAddress AS DWORD   ' DWORD
   VirtualSize     AS DWORD   ' DWORD
END UNION

UNION IMAGE_SECTION_HEADER_NAME_UNION
   Name                 AS STRING * %IMAGE_SIZEOF_SHORT_NAME   ' BYTE
   ' // For compatibility wirh the PB headers
   bName(%IMAGE_SIZEOF_SHORT_NAME - 1) AS BYTE
END UNION

' // Size = 40 bytes
TYPE IMAGE_SECTION_HEADER DWORD FILL
   IMAGE_SECTION_HEADER_NAME_UNION
   Misc                 AS MiscUnionISH
   VirtualAddress       AS DWORD                               ' DWORD
   SizeOfRawData        AS DWORD                               ' DWORD
   PointerToRawData     AS DWORD                               ' DWORD
   PointerToRelocations AS DWORD                               ' DWORD
   PointerToLinenumbers AS DWORD                               ' DWORD
   NumberOfRelocations  AS WORD                                ' WORD
   NumberOfLinenumbers  AS WORD                                ' WORD
   Characteristics      AS DWORD                               ' DWORD
END TYPE

%IMAGE_SIZEOF_SECTION_HEADER = 40

'//
'// Section characteristics.
'//
'//      IMAGE_SCN_TYPE_REG                   0x00000000  // Reserved.
'//      IMAGE_SCN_TYPE_DSECT                 0x00000001  // Reserved.
'//      IMAGE_SCN_TYPE_NOLOAD                0x00000002  // Reserved.
'//      IMAGE_SCN_TYPE_GROUP                 0x00000004  // Reserved.
'#define IMAGE_SCN_TYPE_NO_PAD                0x00000008  // Reserved.
%IMAGE_SCN_TYPE_NO_PAD               = &H00000008???  ' Reserved.
'//      IMAGE_SCN_TYPE_COPY                  0x00000010  // Reserved.

%IMAGE_SCN_CNT_CODE                  = &H00000020???  ' Section contains code.
%IMAGE_SCN_CNT_INITIALIZED_DATA      = &H00000040???  ' Section contains initialized data.
%IMAGE_SCN_CNT_UNINITIALIZED_DATA    = &H00000080???  ' Section contains uninitialized data.

%IMAGE_SCN_LNK_OTHER                 = &H00000100???  ' Reserved.
%IMAGE_SCN_LNK_INFO                  = &H00000200???  ' Section contains comments or some other type of information.
'     IMAGE_SCN_TYPE_OVER                 = &H00000400  ' Reserved.
%IMAGE_SCN_LNK_REMOVE                = &H00000800???  ' Section contents will not become part of image.
%IMAGE_SCN_LNK_COMDAT                = &H00001000???  ' Section contents comdat.

'//                                           0x00002000  // Reserved.
'//      IMAGE_SCN_MEM_PROTECTED - Obsolete   0x00004000
%IMAGE_SCN_NO_DEFER_SPEC_EXC         = &H00004000???  ' Reset speculative exceptions handling bits in the TLB entries for this section.
%IMAGE_SCN_GPREL                     = &H00008000???  ' Section content can be accessed relative to GP
%IMAGE_SCN_MEM_FARDATA               = &H00008000???
'     IMAGE_SCN_MEM_SYSHEAP  - Obsolete   = &H00010000
%IMAGE_SCN_MEM_PURGEABLE             = &H00020000???
%IMAGE_SCN_MEM_16BIT                 = &H00020000???
%IMAGE_SCN_MEM_LOCKED                = &H00040000???
%IMAGE_SCN_MEM_PRELOAD               = &H00080000???

%IMAGE_SCN_ALIGN_1BYTES              = &H00100000???
%IMAGE_SCN_ALIGN_2BYTES              = &H00200000???
%IMAGE_SCN_ALIGN_4BYTES              = &H00300000???
%IMAGE_SCN_ALIGN_8BYTES              = &H00400000???
%IMAGE_SCN_ALIGN_16BYTES             = &H00500000???  ' Default alignment if no others are specified.
%IMAGE_SCN_ALIGN_32BYTES             = &H00600000???
%IMAGE_SCN_ALIGN_64BYTES             = &H00700000???
%IMAGE_SCN_ALIGN_128BYTES            = &H00800000???
%IMAGE_SCN_ALIGN_256BYTES            = &H00900000???
%IMAGE_SCN_ALIGN_512BYTES            = &H00A00000???
%IMAGE_SCN_ALIGN_1024BYTES           = &H00B00000???
%IMAGE_SCN_ALIGN_2048BYTES           = &H00C00000???
%IMAGE_SCN_ALIGN_4096BYTES           = &H00D00000???
%IMAGE_SCN_ALIGN_8192BYTES           = &H00E00000???
' Unused                                   = &H00F00000
%IMAGE_SCN_ALIGN_MASK                = &H00F00000???

%IMAGE_SCN_LNK_NRELOC_OVFL           = &H01000000???  ' Section contains extended relocations.
%IMAGE_SCN_MEM_DISCARDABLE           = &H02000000???  ' Section can be discarded.
%IMAGE_SCN_MEM_NOT_CACHED            = &H04000000???  ' Section is not cachable.
%IMAGE_SCN_MEM_NOT_PAGED             = &H08000000???  ' Section is not pageable.
%IMAGE_SCN_MEM_SHARED                = &H10000000???  ' Section is shareable.
%IMAGE_SCN_MEM_EXECUTE               = &H20000000???  ' Section is executable.
%IMAGE_SCN_MEM_READ                  = &H40000000???  ' Section is readable.
%IMAGE_SCN_MEM_WRITE                 = &H80000000???  ' Section is writeable.

'//
'// TLS Chaacteristic Flags
'//
%IMAGE_SCN_SCALE_INDEX               = &H00000001???  ' Tls index is scaled

'#ifndef _MAC
'#include "pshpack2.h"                       // Symbols, relocs, and linenumbers are 2 byte packed
'#endif

'//
'// Symbol format.
'//

' // Size = 8 bytes
TYPE IMAGE_SYMBOL_NAME_STRUCT WORD
   Short AS DWORD    ' DWORD // if 0, use LongName
   Long  AS DWORD    ' DWORD // offset into string table
END TYPE

'// For compatibility with the PB declares
TYPE IMAGE_SYMBOL_NAME_PB_STRUCT WORD
   dShort AS DWORD    ' DWORD // if 0, use LongName
   dLong  AS DWORD    ' DWORD // offset into string table
END TYPE

' // Size = 8 bytes
UNION IMAGE_SYMBOL_N_UNION WORD
   ShortName   AS STRING * 8   ' BYTE[8]
   Name        AS IMAGE_SYMBOL_NAME_STRUCT
   LongName(1) AS DWORD        ' PBYTE[2]
END UNION

'// For compatibility with the PB declares
UNION IMAGE_SYMBOL_N_PB_UNION WORD
   ShortName   AS STRING * 8   ' BYTE[8]
   nName       AS IMAGE_SYMBOL_NAME_PB_STRUCT
   LongName(1) AS DWORD        ' PBYTE[2]
END UNION

UNION IMAGE_SYMBOL_UNION WORD
   IMAGE_SYMBOL_N_UNION
   '// For compatibility with the PB declares
   N AS IMAGE_SYMBOL_N_PB_UNION
END UNION

' // Size = 18 bytes
TYPE IMAGE_SYMBOL WORD FILL
   IMAGE_SYMBOL_UNION
   Value              AS DWORD     ' DWORD
   SectionNumber      AS INTEGER   ' SHORT
   Type               AS WORD      ' WORD
   StorageClass       AS BYTE      ' BYTE
   NumberOfAuxSymbols AS BYTE      ' BYTE
END TYPE

%IMAGE_SIZEOF_SYMBOL = 18

' // Size = 8 bytes
TYPE IMAGE_SYMBOL_EX_NAME_STRUCT WORD
   Short AS DWORD    ' DWORD // if 0, use LongName
   Long  AS DWORD    ' DWORD // offset into string table
END TYPE

' // Size = 8 bytes
UNION IMAGE_SYMBOL_EX_N_UNION WORD
   ShortName   AS STRING * 8   ' BYTE[8]
   Name        AS IMAGE_SYMBOL_EX_NAME_STRUCT
   LongName(1) AS DWORD        ' PBYTE[2]
END UNION

' // Size = 20 bytes
TYPE IMAGE_SYMBOL_EX WORD FILL
   IMAGE_SYMBOL_EX_N_UNION
   Value              AS DWORD   ' DWORD
   SectionNumber      AS LONG    ' LONG
   Type               AS WORD    ' WORD
   StorageClass       AS BYTE    ' BYTE
   NumberOfAuxSymbols AS BYTE    ' BYTE
END TYPE

%IMAGE_SIZEOF_SYMBOL_EX = 20

'//
'// Section values.
'//
'// Symbols have a section number of the section in which they are
'// defined. Otherwise, section numbers have the following meanings:
'//

%IMAGE_SYM_UNDEFINED      = 0%      ' (SHORT)0  // Symbol is undefined or is common.
%IMAGE_SYM_ABSOLUTE       = -1%     ' (SHORT)-1 // Symbol is an absolute value.
%IMAGE_SYM_DEBUG          = -2%     ' (SHORT)-2 // Symbol is a special debug item.
%IMAGE_SYM_SECTION_MAX    = &HFEFF  ' // Values 0xFF00-0xFFFF are special
%IMAGE_SYM_SECTION_MAX_EX = %MAXLONG

'//
'// Type (fundamental) values.
'//

%IMAGE_SYM_TYPE_NULL   = &H00000000???  ' no type.
%IMAGE_SYM_TYPE_VOID   = &H00000001???
%IMAGE_SYM_TYPE_CHAR   = &H00000002???  ' type character.
%IMAGE_SYM_TYPE_SHORT  = &H00000003???  ' type short integer.
%IMAGE_SYM_TYPE_INT    = &H00000004???
%IMAGE_SYM_TYPE_LONG   = &H00000005???
%IMAGE_SYM_TYPE_FLOAT  = &H00000006???
%IMAGE_SYM_TYPE_DOUBLE = &H00000007???
%IMAGE_SYM_TYPE_STRUCT = &H00000008???
%IMAGE_SYM_TYPE_UNION  = &H00000009???
%IMAGE_SYM_TYPE_ENUM   = &H0000000A???  ' enumeration.
%IMAGE_SYM_TYPE_MOE    = &H0000000B???  ' member of enumeration.
%IMAGE_SYM_TYPE_BYTE   = &H0000000C???
%IMAGE_SYM_TYPE_WORD   = &H0000000D???
%IMAGE_SYM_TYPE_UINT   = &H0000000E???
%IMAGE_SYM_TYPE_DWORD  = &H0000000F???
%IMAGE_SYM_TYPE_PCODE  = &H00008000???

'//
'// Type (derived) values.
'//

%IMAGE_SYM_DTYPE_NULL     = 0       ' no derived type.
%IMAGE_SYM_DTYPE_POINTER  = 1       ' pointer.
%IMAGE_SYM_DTYPE_FUNCTION = 2       ' function.
%IMAGE_SYM_DTYPE_ARRAY    = 3       ' array.

'//
'// Storage classes.
'//
%IMAGE_SYM_CLASS_END_OF_FUNCTION  = &HFF?   ' (BYTE )-1
%IMAGE_SYM_CLASS_NULL             = &H0000?
%IMAGE_SYM_CLASS_AUTOMATIC        = &H0001?
%IMAGE_SYM_CLASS_EXTERNAL         = &H0002?
%IMAGE_SYM_CLASS_STATIC           = &H0003?
%IMAGE_SYM_CLASS_REGISTER         = &H0004?
%IMAGE_SYM_CLASS_EXTERNAL_DEF     = &H0005?
%IMAGE_SYM_CLASS_LABEL            = &H0006?
%IMAGE_SYM_CLASS_UNDEFINED_LABEL  = &H0007?
%IMAGE_SYM_CLASS_MEMBER_OF_STRUCT = &H0008?
%IMAGE_SYM_CLASS_ARGUMENT         = &H0009?
%IMAGE_SYM_CLASS_STRUCT_TAG       = &H000A?
%IMAGE_SYM_CLASS_MEMBER_OF_UNION  = &H000B?
%IMAGE_SYM_CLASS_UNION_TAG        = &H000C?
%IMAGE_SYM_CLASS_TYPE_DEFINITION  = &H000D?
%IMAGE_SYM_CLASS_UNDEFINED_STATIC = &H000E?
%IMAGE_SYM_CLASS_ENUM_TAG         = &H000F?
%IMAGE_SYM_CLASS_MEMBER_OF_ENUM   = &H0010?
%IMAGE_SYM_CLASS_REGISTER_PARAM   = &H0011?
%IMAGE_SYM_CLASS_BIT_FIELD        = &H0012?

%IMAGE_SYM_CLASS_FAR_EXTERNAL     = &H0044?

%IMAGE_SYM_CLASS_BLOCK            = &H0064?
%IMAGE_SYM_CLASS_FUNCTION         = &H0065?
%IMAGE_SYM_CLASS_END_OF_STRUCT    = &H0066?
%IMAGE_SYM_CLASS_FILE             = &H0067?
' new
%IMAGE_SYM_CLASS_SECTION          = &H0068?
%IMAGE_SYM_CLASS_WEAK_EXTERNAL    = &H0069?

%IMAGE_SYM_CLASS_CLR_TOKEN        = &H006B?

'// type packing constants

%N_BTMASK = &H000F?
%N_TMASK  = &H0030?
%N_TMASK1 = &H00C0?
%N_TMASK2 = &H00F0?
%N_BTSHFT = 4?
%N_TSHIFT = 2?

'// MACROS

'// Basic Type of  x
'#define BTYPE(x) ((x) & N_BTMASK)

MACRO BTTYPE(x) = (x AND N_BTMASK)

'// Is x a pointer?
'#ifndef ISPTR
'#define ISPTR(x) (((x) & N_TMASK) == (IMAGE_SYM_DTYPE_POINTER << N_BTSHFT))
'#endif

#IF NOT %DEF(%ISPTR)
%ISPTR = 1
FUNCTION ISPTR (BYVAL x AS DWORD) AS LONG
   LOCAL value AS DWORD
   value = %IMAGE_SYM_DTYPE_POINTER
   SHIFT LEFT value, %N_BTSHFT
   FUNCTION = (x AND %N_TMASK) = value
END FUNCTION
#ENDIF

'// Is x a function?
'#ifndef ISFCN
'#define ISFCN(x) (((x) & N_TMASK) == (IMAGE_SYM_DTYPE_FUNCTION << N_BTSHFT))
'#endif

#IF NOT %DEF(%ISFCN)
%ISFCN = 1
FUNCTION ISFCN (BYVAL x AS DWORD) AS LONG
   LOCAL value AS DWORD
   value = %IMAGE_SYM_DTYPE_FUNCTION
   SHIFT LEFT value, %N_BTSHFT
   FUNCTION = (x AND %N_TMASK) = value
END FUNCTION
#ENDIF

'// Is x an array?

'#ifndef ISARY
'#define ISARY(x) (((x) & N_TMASK) == (IMAGE_SYM_DTYPE_ARRAY << N_BTSHFT))
'#endif

#IF NOT %DEF(%ISARY)
%ISARY = 1
FUNCTION ISARY (BYVAL x AS DWORD) AS LONG
   LOCAL value AS DWORD
   value = %IMAGE_SYM_DTYPE_ARRAY
   SHIFT LEFT value, %N_BTSHFT
   FUNCTION = (x AND %N_TMASK) = value
END FUNCTION
#ENDIF

'// Is x a structure, union, or enumeration TAG?
'#ifndef ISTAG
'#define ISTAG(x) ((x)==IMAGE_SYM_CLASS_STRUCT_TAG || (x)==IMAGE_SYM_CLASS_UNION_TAG || (x)==IMAGE_SYM_CLASS_ENUM_TAG)
'#endif

#IF NOT %DEF(%ISTAG)
%ISTAG = 1
FUNCTION ISTAG (BYVAL x AS DWORD) AS LONG
   IF x = %IMAGE_SYM_CLASS_STRUCT_TAG OR x = %IMAGE_SYM_CLASS_UNION_TAG OR x = %IMAGE_SYM_CLASS_ENUM_TAG THEN FUNCTION = 1 ' %TRUE
END FUNCTION
#ENDIF

'#ifndef INCREF
'#define INCREF(x) ((((x)&~N_BTMASK)<<N_TSHIFT)|(IMAGE_SYM_DTYPE_POINTER<<N_BTSHFT)|((x)&N_BTMASK))
'#endif
#IF NOT %DEF(%INCREF)
%INCREF = 1
FUNCTION INCREF (BYVAL value AS DWORD) AS DWORD
   LOCAL x AS DWORD
   x = value AND NOT %N_BTMASK
   SHIFT LEFT x, %N_TSHIFT
   LOCAL xx AS DWORD
   xx = %IMAGE_SYM_DTYPE_POINTER
   SHIFT LEFT xx, %N_BTSHFT
   LOCAL xxx AS DWORD
   xxx = value AND %N_BTMASK
   FUNCTION = x OR xx OR xxx
END FUNCTION
#ENDIF

'#ifndef DECREF
'#define DECREF(x) ((((x)>>N_TSHIFT)&~N_BTMASK)|((x)&N_BTMASK))
'#endif
#IF NOT %DEF(%DECREF)
%DECREF = 1
FUNCTION DECREF (BYVAL value AS DWORD) AS DWORD
   LOCAL x AS DWORD
   x = value
   SHIFT RIGHT x, %N_TSHIFT
   x = x AND NOT %N_BTMASK
   LOCAL xx AS DWORD
   xx = value AND %N_BTMASK
   FUNCTION = x OR xx
END FUNCTION
#ENDIF

'#include <pshpack2.h>

' // Size = 18 bytes
TYPE IMAGE_AUX_SYMBOL_TOKEN_DEF WORD FILL
   bAuxType         AS BYTE    ' BYTE // IMAGE_AUX_SYMBOL_TYPE
   bReserved        AS BYTE    ' BYTE // Must be 0
   SymbolTableIndex AS DWORD   ' DWORD
   rgbReserved(11)  AS BYTE    ' // Must be 0
END TYPE

'typedef IMAGE_AUX_SYMBOL_TOKEN_DEF UNALIGNED *PIMAGE_AUX_SYMBOL_TOKEN_DEF;

'#include <poppack.h>

'//
'// Auxiliary entry format.
'//

'typedef union _IMAGE_AUX_SYMBOL {
'    struct {
'        DWORD    TagIndex;                      // struct, union, or enum tag index
'        union {
'            struct {
'                WORD    Linenumber;             // declaration line number
'                WORD    Size;                   // size of struct, union, or enum
'            } LnSz;
'           DWORD    TotalSize;
'        } Misc;
'        union {
'            struct {                            // if ISFCN, tag, or .bb
'                DWORD    PointerToLinenumber;
'                DWORD    PointerToNextFunction;
'            } Function;
'            struct {                            // if ISARY, up to 4 dimen.
'                WORD     Dimension[4];
'            } Array;
'        } FcnAry;
'        WORD    TvIndex;                        // tv index
'    } Sym;
'    struct {
'        BYTE    Name[IMAGE_SIZEOF_SYMBOL];
'    } File;
'    struct {
'        DWORD   Length;                         // section length
'        WORD    NumberOfRelocations;            // number of relocation entries
'        WORD    NumberOfLinenumbers;            // number of line numbers
'        DWORD   CheckSum;                       // checksum for communal
'        SHORT   Number;                         // section number to associate with
'        BYTE    Selection;                      // communal selection type
'        BYTE    bReserved;
'        SHORT   HighNumber;                     // high bits of the section number
'    } Section;
'    IMAGE_AUX_SYMBOL_TOKEN_DEF TokenDef;
'    struct {
'        DWORD crc;
'        BYTE  rgbReserved[14];
'    } CRC;
'} IMAGE_AUX_SYMBOL;
'typedef IMAGE_AUX_SYMBOL UNALIGNED *PIMAGE_AUX_SYMBOL;

UNION  IMAGE_AUX_SYMBOL_LnSz_SIZE_UNION BYTE
   Size       AS WORD   ' WORD // size of struct, union, or enum
   ' // For compatibility with the PB includes
   nSize      AS WORD   ' WORD // size of struct, union, or enum
END UNION

' // Size = 4 bytes
TYPE IMAGE_AUX_SYMBOL_LnSz_STRUCT BYTE
   Linenumber AS WORD   ' WORD // declaration line number
   IMAGE_AUX_SYMBOL_LnSz_SIZE_UNION
END TYPE

' // Size = 4 bytes
UNION IMAGE_AUX_SYMBOL_Misc_UNION BYTE
   LnSz      AS IMAGE_AUX_SYMBOL_LnSz_STRUCT
   TotalSize AS DWORD
END UNION

' // Size = 8 bytes
TYPE IMAGE_AUX_SYMBOL_Function_STRUCT BYTE
   PointerToLinenumber   AS DWORD
   PointerToNextFunction AS DWORD
END TYPE

' // Size = 8 bytes
TYPE IMAGE_AUX_SYMBOL_Array_STRUCT BYTE
   Dimension(3) AS WORD
END TYPE

' // Size = 8 bytes
UNION IMAGE_AUX_SYMBOL_FcnAry_UNION BYTE
   Function AS IMAGE_AUX_SYMBOL_Function_STRUCT
   Array    AS IMAGE_AUX_SYMBOL_Array_STRUCT
   ' // For compatibility with the PB declares
   tFunction AS IMAGE_AUX_SYMBOL_Function_STRUCT
   tArray    AS IMAGE_AUX_SYMBOL_Array_STRUCT
END UNION

' // Size = 18 bytes
TYPE IMAGE_AUX_SYMBOL_Sym_STRUCT BYTE
   TagIndex AS DWORD
   Misc     AS IMAGE_AUX_SYMBOL_Misc_UNION
   FcnAry   AS IMAGE_AUX_SYMBOL_FcnAry_UNION
   TvIndex  AS WORD
END TYPE

' // Size = 18 bytes
TYPE IMAGE_AUX_SYMBOL_File_STRUCT BYTE
   Name AS STRING * %IMAGE_SIZEOF_SYMBOL
END TYPE
' // For compatibility with the PB declares
TYPE IMAGE_AUX_SYMBOL_File_PB_STRUCT BYTE
   bName(%IMAGE_SIZEOF_SYMBOL-1) AS BYTE
END TYPE
UNION IMAGE_AUX_SYMBOL_File_UNION
   IMAGE_AUX_SYMBOL_File_STRUCT
   IMAGE_AUX_SYMBOL_File_PB_STRUCT
END UNION

' // Size = 18 bytes
TYPE IMAGE_AUX_SYMBOL_Section_STRUCT BYTE
   Length              AS DWORD     ' // section length
   NumberOfRelocations AS WORD      ' // number of relocation entries
   NumberOfLinenumbers AS WORD      ' // number of line numbers
   CheckSum            AS DWORD     ' // checksum for communal
   Number              AS INTEGER   ' // section number to associate with
   Selection           AS BYTE      ' // communal selection type
   bReserved           AS BYTE
   HighNumber          AS INTEGER   ' // high bits of the section number
END TYPE

' // Size = 18 bytes
TYPE IMAGE_AUX_SYMBOL_CRC_STRUCT BYTE
   crc            AS DWORD
   gbReserved(13) AS BYTE
END TYPE

' // Size = 18 bytes
UNION IMAGE_AUX_SYMBOL BYTE
   Sym     AS IMAGE_AUX_SYMBOL_Sym_STRUCT
   File    AS IMAGE_AUX_SYMBOL_File_UNION
   Section AS IMAGE_AUX_SYMBOL_Section_STRUCT
   CRC     AS IMAGE_AUX_SYMBOL_CRC_STRUCT
END UNION

%IMAGE_SIZEOF_AUX_SYMBOL           = 18

'typedef union _IMAGE_AUX_SYMBOL_EX {
'    struct {
'        DWORD   WeakDefaultSymIndex;                       // the weak extern default symbol index
'        DWORD   WeakSearchType;
'        BYTE    rgbReserved[12];
'    } Sym;
'    struct {
'        BYTE    Name[sizeof(IMAGE_SYMBOL_EX)];
'    } File;
'    struct {
'        DWORD   Length;                         // section length
'        WORD    NumberOfRelocations;            // number of relocation entries
'        WORD    NumberOfLinenumbers;            // number of line numbers
'        DWORD   CheckSum;                       // checksum for communal
'        SHORT   Number;                         // section number to associate with
'        BYTE    Selection;                      // communal selection type
'        BYTE    bReserved;
'        SHORT   HighNumber;                     // high bits of the section number
'        BYTE    rgbReserved[2];
'    } Section;
'    struct{
'        IMAGE_AUX_SYMBOL_TOKEN_DEF TokenDef;
'        BYTE  rgbReserved[2];
'    };
'    struct {
'        DWORD crc;
'        BYTE  rgbReserved[16];
'    } CRC;
'} IMAGE_AUX_SYMBOL_EX;
'typedef IMAGE_AUX_SYMBOL_EX UNALIGNED *PIMAGE_AUX_SYMBOL_EX;

' // Size = 20 bytes
TYPE IMAGE_AUX_SYMBOL_EX_Sym_STRUCT BYTE
   WeakDefaultSymIndex AS DWORD   ' // the weak extern default symbol index
   WeakSearchType      AS DWORD
   rgbReserved(11)     AS BYTE
END TYPE

' // Size = 20 bytes
TYPE IMAGE_AUX_SYMBOL_EX_File_STRUCT BYTE
   Name AS STRING * %IMAGE_SIZEOF_SYMBOL_EX
END TYPE

' // Size = 20 bytes
TYPE IMAGE_AUX_SYMBOL_EX_Section_STRUCT BYTE
   Length              AS DWORD     ' // section length
   NumberOfRelocations AS WORD      ' // number of relocation entries
   NumberOfLinenumbers AS WORD      ' // number of line numbers
   CheckSum            AS DWORD     ' // checksum for communal
   Number              AS INTEGER   ' // section number to associate with
   Selection           AS BYTE      ' // communal selection type
   bReserved           AS BYTE
   HighNumber          AS INTEGER   ' // high bits of the section number
   rgbReserved(1)      AS BYTE
END TYPE

' // Size = 6 bytes
TYPE IMAGE_AUX_SYMBOL_EX_ANONYMOUS_STRUCT BYTE
   TokenDef       AS LONG   ' IMAGE_AUX_SYMBOL_TOKEN_DEF
   rgbReserved(1) AS BYTE
END TYPE

' // Size = 20 bytes
TYPE IMAGE_AUX_SYMBOL_EX_CRC_STRUCT BYTE
   crc            AS DWORD
   gbReserved(15) AS BYTE
END TYPE

' // Size = 20 bytes
UNION IMAGE_AUX_SYMBOL_EX BYTE
   Sym     AS IMAGE_AUX_SYMBOL_EX_Sym_STRUCT
   File    AS IMAGE_AUX_SYMBOL_EX_File_STRUCT
   Section AS IMAGE_AUX_SYMBOL_EX_Section_STRUCT
   IMAGE_AUX_SYMBOL_EX_ANONYMOUS_STRUCT
   CRC     AS IMAGE_AUX_SYMBOL_EX_CRC_STRUCT
END UNION

' IMAGE_AUX_SYMBOL_TYPE enum
%IMAGE_AUX_SYMBOL_TYPE_TOKEN_DEF = 1

'//
'// Communal selection types.
'//

%IMAGE_COMDAT_SELECT_NODUPLICATES   = 1
%IMAGE_COMDAT_SELECT_ANY            = 2
%IMAGE_COMDAT_SELECT_SAME_SIZE      = 3
%IMAGE_COMDAT_SELECT_EXACT_MATCH    = 4
%IMAGE_COMDAT_SELECT_ASSOCIATIVE    = 5
%IMAGE_COMDAT_SELECT_LARGEST        = 6
%IMAGE_COMDAT_SELECT_NEWEST         = 7

%IMAGE_WEAK_EXTERN_SEARCH_NOLIBRARY = 1
%IMAGE_WEAK_EXTERN_SEARCH_LIBRARY   = 2
%IMAGE_WEAK_EXTERN_SEARCH_ALIAS     = 3

'//
'// Relocation format.
'//

'typedef struct _IMAGE_RELOCATION {
'    union {
'        DWORD   VirtualAddress;
'        DWORD   RelocCount;             // Set to the real count when IMAGE_SCN_LNK_NRELOC_OVFL is set
'    };
'    DWORD   SymbolTableIndex;
'    WORD    Type;
'} IMAGE_RELOCATION;
'typedef IMAGE_RELOCATION UNALIGNED *PIMAGE_RELOCATION;

' // Size = 4 bytes
UNION IMAGE_RELOCATION_UNION BYTE
   VirtualAddress AS DWORD
   RelocCount     AS DWORD  ' Set to the real count when IMAGE_SCN_LNK_NRELOC_OVFL is set
END UNION

UNION IMAGE_RELOCATION_TYPE_UNION BYTE
   Type AS WORD
   ' // For compatibility with the PB declares
   nType AS WORD
END UNION

' // Size = 10 bytes
TYPE IMAGE_RELOCATION BYTE
   IMAGE_RELOCATION_UNION
   SymbolTableIndex AS DWORD
   IMAGE_RELOCATION_TYPE_UNION
END TYPE

%IMAGE_SIZEOF_RELOCATION = 10

'//
'// I386 relocation types.
'//
%IMAGE_REL_I386_ABSOLUTE = &H0000???  ' Reference is absolute, no relocation is necessary
%IMAGE_REL_I386_DIR16    = &H0001???  ' Direct 16-bit reference to the symbols virtual address
%IMAGE_REL_I386_REL16    = &H0002???  ' PC-relative 16-bit reference to the symbols virtual address
%IMAGE_REL_I386_DIR32    = &H0006???  ' Direct 32-bit reference to the symbols virtual address
%IMAGE_REL_I386_DIR32NB  = &H0007???  ' Direct 32-bit reference to the symbols virtual address, base not included
%IMAGE_REL_I386_SEG12    = &H0009???  ' Direct 16-bit reference to the segment-selector bits of a 32-bit virtual address
%IMAGE_REL_I386_SECTION  = &H000A???
%IMAGE_REL_I386_SECREL   = &H000B???
%IMAGE_REL_I386_TOKEN    = &H000C???  ' clr token
%IMAGE_REL_I386_SECREL7  = &H000D???  ' 7 bit offset from base of section containing target
%IMAGE_REL_I386_REL32    = &H0014???  ' PC-relative 32-bit reference to the symbols virtual address

'//
'// MIPS relocation types.
'//
%IMAGE_REL_MIPS_ABSOLUTE  = &H0000???  ' Reference is absolute, no relocation is necessary
%IMAGE_REL_MIPS_REFHALF   = &H0001???
%IMAGE_REL_MIPS_REFWORD   = &H0002???
%IMAGE_REL_MIPS_JMPADDR   = &H0003???
%IMAGE_REL_MIPS_REFHI     = &H0004???
%IMAGE_REL_MIPS_REFLO     = &H0005???
%IMAGE_REL_MIPS_GPREL     = &H0006???
%IMAGE_REL_MIPS_LITERAL   = &H0007???
%IMAGE_REL_MIPS_SECTION   = &H000A???
%IMAGE_REL_MIPS_SECREL    = &H000B???
%IMAGE_REL_MIPS_SECRELLO  = &H000C???  ' Low 16-bit section relative referemce (used for >32k TLS)
%IMAGE_REL_MIPS_SECRELHI  = &H000D???  ' High 16-bit section relative reference (used for >32k TLS)
%IMAGE_REL_MIPS_JMPADDR16 = &H0010???
%IMAGE_REL_MIPS_REFWORDNB = &H0022???
%IMAGE_REL_MIPS_PAIR      = &H0025???

'//
'// Alpha Relocation types.
'//
%IMAGE_REL_ALPHA_ABSOLUTE       = &H0000???
%IMAGE_REL_ALPHA_REFLONG        = &H0001???
%IMAGE_REL_ALPHA_REFQUAD        = &H0002???
%IMAGE_REL_ALPHA_GPREL32        = &H0003???
%IMAGE_REL_ALPHA_LITERAL        = &H0004???
%IMAGE_REL_ALPHA_LITUSE         = &H0005???
%IMAGE_REL_ALPHA_GPDISP         = &H0006???
%IMAGE_REL_ALPHA_BRADDR         = &H0007???
%IMAGE_REL_ALPHA_HINT           = &H0008???
%IMAGE_REL_ALPHA_INLINE_REFLONG = &H0009???
%IMAGE_REL_ALPHA_REFHI          = &H000A???
%IMAGE_REL_ALPHA_REFLO          = &H000B???
%IMAGE_REL_ALPHA_PAIR           = &H000C???
%IMAGE_REL_ALPHA_MATCH          = &H000D???
%IMAGE_REL_ALPHA_SECTION        = &H000E???
%IMAGE_REL_ALPHA_SECREL         = &H000F???
%IMAGE_REL_ALPHA_REFLONGNB      = &H0010???
%IMAGE_REL_ALPHA_SECRELLO       = &H0011???  ' Low 16-bit section relative reference
%IMAGE_REL_ALPHA_SECRELHI       = &H0012???  ' High 16-bit section relative reference
%IMAGE_REL_ALPHA_REFQ3          = &H0013???  ' High 16 bits of 48 bit reference
%IMAGE_REL_ALPHA_REFQ2          = &H0014???  ' Middle 16 bits of 48 bit reference
%IMAGE_REL_ALPHA_REFQ1          = &H0015???  ' Low 16 bits of 48 bit reference
%IMAGE_REL_ALPHA_GPRELLO        = &H0016???  ' Low 16-bit GP relative reference
%IMAGE_REL_ALPHA_GPRELHI        = &H0017???  ' High 16-bit GP relative reference

'//
'// IBM PowerPC relocation types.
'//
%IMAGE_REL_PPC_ABSOLUTE = &H0000???  ' NOP
%IMAGE_REL_PPC_ADDR64   = &H0001???  ' 64-bit address
%IMAGE_REL_PPC_ADDR32   = &H0002???  ' 32-bit address
%IMAGE_REL_PPC_ADDR24   = &H0003???  ' 26-bit address, shifted left 2 (branch absolute)
%IMAGE_REL_PPC_ADDR16   = &H0004???  ' 16-bit address
%IMAGE_REL_PPC_ADDR14   = &H0005???  ' 16-bit address, shifted left 2 (load doubleword)
%IMAGE_REL_PPC_REL24    = &H0006???  ' 26-bit PC-relative offset, shifted left 2 (branch relative)
%IMAGE_REL_PPC_REL14    = &H0007???  ' 16-bit PC-relative offset, shifted left 2 (br cond relative)
%IMAGE_REL_PPC_TOCREL16 = &H0008???  ' 16-bit offset from TOC base
%IMAGE_REL_PPC_TOCREL14 = &H0009???  ' 16-bit offset from TOC base, shifted left 2 (load doubleword)

%IMAGE_REL_PPC_ADDR32NB = &H000A???  ' 32-bit addr w/o image base
%IMAGE_REL_PPC_SECREL   = &H000B???  ' va of containing section (as in an image sectionhdr)
%IMAGE_REL_PPC_SECTION  = &H000C???  ' sectionheader number
%IMAGE_REL_PPC_IFGLUE   = &H000D???  ' substitute TOC restore instruction iff symbol is glue code
%IMAGE_REL_PPC_IMGLUE   = &H000E???  ' symbol is glue code; virtual address is TOC restore instruction
%IMAGE_REL_PPC_SECREL16 = &H000F???  ' va of containing section (limited to 16 bits)
%IMAGE_REL_PPC_REFHI    = &H0010???
%IMAGE_REL_PPC_REFLO    = &H0011???
%IMAGE_REL_PPC_PAIR     = &H0012???
%IMAGE_REL_PPC_SECRELLO = &H0013???  ' Low 16-bit section relative reference (used for >32k TLS)
%IMAGE_REL_PPC_SECRELHI = &H0014???  ' High 16-bit section relative reference (used for >32k TLS)
%IMAGE_REL_PPC_GPREL    = &H0015???
%IMAGE_REL_PPC_TOKEN    = &H0016???  ' clr token

%IMAGE_REL_PPC_TYPEMASK = &H00FF???  ' mask to isolate above values in IMAGE_RELOCATION.Type

'// Flag bits in IMAGE_RELOCATION.TYPE

%IMAGE_REL_PPC_NEG      = &H0100???  ' subtract reloc value rather than adding it
%IMAGE_REL_PPC_BRTAKEN  = &H0200???  ' fix branch prediction bit to predict branch taken
%IMAGE_REL_PPC_BRNTAKEN = &H0400???  ' fix branch prediction bit to predict branch not taken
%IMAGE_REL_PPC_TOCDEFN  = &H0800???  ' toc slot defined in file (or, data in toc)

'//
'// Hitachi SH3 relocation types.
'//
%IMAGE_REL_SH3_ABSOLUTE          = &H0000???  ' No relocation
%IMAGE_REL_SH3_DIRECT16          = &H0001???  ' 16 bit direct
%IMAGE_REL_SH3_DIRECT32          = &H0002???  ' 32 bit direct
%IMAGE_REL_SH3_DIRECT8           = &H0003???  ' 8 bit direct, -128..255
%IMAGE_REL_SH3_DIRECT8_WORD      = &H0004???  ' 8 bit direct .W (0 ext.)
%IMAGE_REL_SH3_DIRECT8_LONG      = &H0005???  ' 8 bit direct .L (0 ext.)
%IMAGE_REL_SH3_DIRECT4           = &H0006???  ' 4 bit direct (0 ext.)
%IMAGE_REL_SH3_DIRECT4_WORD      = &H0007???  ' 4 bit direct .W (0 ext.)
%IMAGE_REL_SH3_DIRECT4_LONG      = &H0008???  ' 4 bit direct .L (0 ext.)
%IMAGE_REL_SH3_PCREL8_WORD       = &H0009???  ' 8 bit PC relative .W
%IMAGE_REL_SH3_PCREL8_LONG       = &H000A???  ' 8 bit PC relative .L
%IMAGE_REL_SH3_PCREL12_WORD      = &H000B???  ' 12 LSB PC relative .W
%IMAGE_REL_SH3_STARTOF_SECTION   = &H000C???  ' Start of EXE section
%IMAGE_REL_SH3_SIZEOF_SECTION    = &H000D???  ' Size of EXE section
%IMAGE_REL_SH3_SECTION           = &H000E???  ' Section table index
%IMAGE_REL_SH3_SECREL            = &H000F???  ' Offset within section
%IMAGE_REL_SH3_DIRECT32_NB       = &H0010???  ' 32 bit direct not based
%IMAGE_REL_SH3_GPREL4_LONG       = &H0011???  ' // GP-relative addressing
%IMAGE_REL_SH3_TOKEN             = &H0012???  ' // clr token
%IMAGE_REL_SHM_PCRELPT           = &H0013???  ' // Offset from current
                                              ' //  instruction in longwords
                                              ' //  if not NOMODE, insert the
                                              ' //  inverse of the low bit at
                                              ' //  bit 32 to select PTA/PTB
%IMAGE_REL_SHM_REFLO             = &H0014???  ' // Low bits of 32-bit address
%IMAGE_REL_SHM_REFHALF           = &H0015???  ' // High bits of 32-bit address
%IMAGE_REL_SHM_RELLO             = &H0016???  ' // Low bits of relative reference
%IMAGE_REL_SHM_RELHALF           = &H0017???  ' // High bits of relative reference
%IMAGE_REL_SHM_PAIR              = &H0018???  ' // offset operand for relocation

%IMAGE_REL_SH_NOMODE             = &H8000???  ' // relocation ignores section mode

%IMAGE_REL_ARM_ABSOLUTE          = &H0000???  ' No relocation required
%IMAGE_REL_ARM_ADDR32            = &H0001???  ' 32 bit address
%IMAGE_REL_ARM_ADDR32NB          = &H0002???  ' 32 bit address w/o image base
%IMAGE_REL_ARM_BRANCH24          = &H0003???  ' 24 bit offset << 2 & sign ext.
%IMAGE_REL_ARM_BRANCH11          = &H0004???  ' Thumb: 2 11 bit offsets
%IMAGE_REL_ARM_TOKEN             = &H0005???  ' clr token
%IMAGE_REL_ARM_GPREL12           = &H0006???  ' GP-relative addressing (ARM)
%IMAGE_REL_ARM_GPREL7            = &H0007???  ' GP-relative addressing (Thumb)
%IMAGE_REL_ARM_BLX24             = &H0008???
%IMAGE_REL_ARM_BLX11             = &H0009???
%IMAGE_REL_ARM_SECTION           = &H000E???  ' Section table index
%IMAGE_REL_ARM_SECREL            = &H000F???  ' Offset within section

%IMAGE_REL_AM_ABSOLUTE           = &H0000???
%IMAGE_REL_AM_ADDR32             = &H0001???
%IMAGE_REL_AM_ADDR32NB           = &H0002???
%IMAGE_REL_AM_CALL32             = &H0003???
%IMAGE_REL_AM_FUNCINFO           = &H0004???
%IMAGE_REL_AM_REL32_1            = &H0005???
%IMAGE_REL_AM_REL32_2            = &H0006???
%IMAGE_REL_AM_SECREL             = &H0007???
%IMAGE_REL_AM_SECTION            = &H0008???
%IMAGE_REL_AM_TOKEN              = &H0009???

'//
'// x64 relocations
'//
%IMAGE_REL_AMD64_ABSOLUTE        = &H0000???  ' // Reference is absolute, no relocation is necessary
%IMAGE_REL_AMD64_ADDR64          = &H0001???  ' // 64-bit address (VA).
%IMAGE_REL_AMD64_ADDR32          = &H0002???  ' // 32-bit address (VA).
%IMAGE_REL_AMD64_ADDR32NB        = &H0003???  ' // 32-bit address w/o image base (RVA).
%IMAGE_REL_AMD64_REL32           = &H0004???  ' // 32-bit relative address from byte following reloc
%IMAGE_REL_AMD64_REL32_1         = &H0005???  ' // 32-bit relative address from byte distance 1 from reloc
%IMAGE_REL_AMD64_REL32_2         = &H0006???  ' // 32-bit relative address from byte distance 2 from reloc
%IMAGE_REL_AMD64_REL32_3         = &H0007???  ' // 32-bit relative address from byte distance 3 from reloc
%IMAGE_REL_AMD64_REL32_4         = &H0008???  ' // 32-bit relative address from byte distance 4 from reloc
%IMAGE_REL_AMD64_REL32_5         = &H0009???  ' // 32-bit relative address from byte distance 5 from reloc
%IMAGE_REL_AMD64_SECTION         = &H000A???  ' // Section index
%IMAGE_REL_AMD64_SECREL          = &H000B???  ' // 32 bit offset from base of section containing target
%IMAGE_REL_AMD64_SECREL7         = &H000C???  ' // 7 bit unsigned offset from base of section containing target
%IMAGE_REL_AMD64_TOKEN           = &H000D???  ' // 32 bit metadata token
%IMAGE_REL_AMD64_SREL32          = &H000E???  ' // 32 bit signed span-dependent value emitted into object
%IMAGE_REL_AMD64_PAIR            = &H000F???
%IMAGE_REL_AMD64_SSPAN32         = &H0010???  ' // 32 bit signed span-dependent value applied at link time

'//
'// IA64 relocation types.
'//
%IMAGE_REL_IA64_ABSOLUTE   = &H0000???
%IMAGE_REL_IA64_IMM14      = &H0001???
%IMAGE_REL_IA64_IMM22      = &H0002???
%IMAGE_REL_IA64_IMM64      = &H0003???
%IMAGE_REL_IA64_DIR32      = &H0004???
%IMAGE_REL_IA64_DIR64      = &H0005???
%IMAGE_REL_IA64_PCREL21B   = &H0006???
%IMAGE_REL_IA64_PCREL21M   = &H0007???
%IMAGE_REL_IA64_PCREL21F   = &H0008???
%IMAGE_REL_IA64_GPREL22    = &H0009???
%IMAGE_REL_IA64_LTOFF22    = &H000A???
%IMAGE_REL_IA64_SECTION    = &H000B???
%IMAGE_REL_IA64_SECREL22   = &H000C???
%IMAGE_REL_IA64_SECREL64I  = &H000D???
%IMAGE_REL_IA64_SECREL32   = &H000E???
'//%IMAGE_REL_IA64_LTOFF64   = &H000F???   ' Not in Windows 7 SDK
%IMAGE_REL_IA64_DIR32NB    = &H0010???
%IMAGE_REL_IA64_SREL14     = &H0011???
%IMAGE_REL_IA64_SREL22     = &H0012???
%IMAGE_REL_IA64_SREL32     = &H0013???
%IMAGE_REL_IA64_UREL32     = &H0014???
%IMAGE_REL_IA64_PCREL60X   = &H0015???   ' // This is always a BRL and never converted
%IMAGE_REL_IA64_PCREL60B   = &H0016???   ' // If possible, convert to MBB bundle with NOP.B in slot 1
%IMAGE_REL_IA64_PCREL60F   = &H0017???   ' // If possible, convert to MFB bundle with NOP.F in slot 1
%IMAGE_REL_IA64_PCREL60I   = &H0018???   ' // If possible, convert to MIB bundle with NOP.I in slot 1
%IMAGE_REL_IA64_PCREL60M   = &H0019???   ' // If possible, convert to MMB bundle with NOP.M in slot 1
%IMAGE_REL_IA64_IMMGPREL64 = &H001A???
%IMAGE_REL_IA64_TOKEN      = &H001B???   ' // clr token
%IMAGE_REL_IA64_GPREL32    = &H001C???
%IMAGE_REL_IA64_ADDEND     = &H001F???

'//
'// CEF relocation types.
'//
%IMAGE_REL_CEF_ABSOLUTE          = &H0000???  ' // Reference is absolute, no relocation is necessary
%IMAGE_REL_CEF_ADDR32            = &H0001???  ' // 32-bit address (VA).
%IMAGE_REL_CEF_ADDR64            = &H0002???  ' // 64-bit address (VA).
%IMAGE_REL_CEF_ADDR32NB          = &H0003???  ' // 32-bit address w/o image base (RVA).
%IMAGE_REL_CEF_SECTION           = &H0004???  ' // Section index
%IMAGE_REL_CEF_SECREL            = &H0005???  ' // 32 bit offset from base of section containing target
%IMAGE_REL_CEF_TOKEN             = &H0006???  ' // 32 bit metadata token

'//
'// clr relocation types.
'//
%IMAGE_REL_CEE_ABSOLUTE          = &H0000???  ' // Reference is absolute, no relocation is necessary
%IMAGE_REL_CEE_ADDR32            = &H0001???  ' // 32-bit address (VA).
%IMAGE_REL_CEE_ADDR64            = &H0002???  ' // 64-bit address (VA).
%IMAGE_REL_CEE_ADDR32NB          = &H0003???  ' // 32-bit address w/o image base (RVA).
%IMAGE_REL_CEE_SECTION           = &H0004???  ' // Section index
%IMAGE_REL_CEE_SECREL            = &H0005???  ' // 32 bit offset from base of section containing target
%IMAGE_REL_CEE_TOKEN             = &H0006???  ' // 32 bit metadata token

%IMAGE_REL_M32R_ABSOLUTE       = &H0000???   ' // No relocation required
%IMAGE_REL_M32R_ADDR32         = &H0001???   ' // 32 bit address
%IMAGE_REL_M32R_ADDR32NB       = &H0002???   ' // 32 bit address w/o image base
%IMAGE_REL_M32R_ADDR24         = &H0003???   ' // 24 bit address
%IMAGE_REL_M32R_GPREL16        = &H0004???   ' // GP relative addressing
%IMAGE_REL_M32R_PCREL24        = &H0005???   ' // 24 bit offset << 2 & sign ext.
%IMAGE_REL_M32R_PCREL16        = &H0006???   ' // 16 bit offset << 2 & sign ext.
%IMAGE_REL_M32R_PCREL8         = &H0007???   ' // 8 bit offset << 2 & sign ext.
%IMAGE_REL_M32R_REFHALF        = &H0008???   ' // 16 MSBs
%IMAGE_REL_M32R_REFHI          = &H0009???   ' // 16 MSBs; adj for LSB sign ext.
%IMAGE_REL_M32R_REFLO          = &H000A???   ' // 16 LSBs
%IMAGE_REL_M32R_PAIR           = &H000B???   ' // Link HI and LO
%IMAGE_REL_M32R_SECTION        = &H000C???   ' // Section table index
%IMAGE_REL_M32R_SECREL32       = &H000D???   ' // 32 bit section relative reference
%IMAGE_REL_M32R_TOKEN          = &H000E???   ' // clr token

%IMAGE_REL_EBC_ABSOLUTE        = &H0000???   ' // No relocation required
%IMAGE_REL_EBC_ADDR32NB        = &H0001???   ' // 32 bit address w/o image base
%IMAGE_REL_EBC_REL32           = &H0002???   ' // 32-bit relative address from byte following reloc
%IMAGE_REL_EBC_SECTION         = &H0003???   ' // Section table index
%IMAGE_REL_EBC_SECREL          = &H0004???   ' // Offset within section

'#define EXT_IMM64(Value, Address, Size, InstPos, ValPos)  /* Intel-IA64-Filler */           \
'    Value |= (((ULONGLONG)((*(Address) >> InstPos) & (((ULONGLONG)1 << Size) - 1))) << ValPos)  // Intel-IA64-Filler

'#define INS_IMM64(Value, Address, Size, InstPos, ValPos)  /* Intel-IA64-Filler */\
'    *(PDWORD)Address = (*(PDWORD)Address & ~(((1 << Size) - 1) << InstPos)) | /* Intel-IA64-Filler */\
'          ((DWORD)((((ULONGLONG)Value >> ValPos) & (((ULONGLONG)1 << Size) - 1))) << InstPos)  // Intel-IA64-Filler

%EMARCH_ENC_I17_IMM7B_INST_WORD_X        = 3  ' // Intel-IA64-Filler
%EMARCH_ENC_I17_IMM7B_SIZE_X             = 7  ' // Intel-IA64-Filler
%EMARCH_ENC_I17_IMM7B_INST_WORD_POS_X    = 4  ' // Intel-IA64-Filler
%EMARCH_ENC_I17_IMM7B_VAL_POS_X          = 0  ' // Intel-IA64-Filler

%EMARCH_ENC_I17_IMM9D_INST_WORD_X        = 3  ' // Intel-IA64-Filler
%EMARCH_ENC_I17_IMM9D_SIZE_X             = 9  ' // Intel-IA64-Filler
%EMARCH_ENC_I17_IMM9D_INST_WORD_POS_X    = 18 ' // Intel-IA64-Filler
%EMARCH_ENC_I17_IMM9D_VAL_POS_X          = 7  ' // Intel-IA64-Filler

%EMARCH_ENC_I17_IMM5C_INST_WORD_X        = 3  ' // Intel-IA64-Filler
%EMARCH_ENC_I17_IMM5C_SIZE_X             = 5  ' // Intel-IA64-Filler
%EMARCH_ENC_I17_IMM5C_INST_WORD_POS_X    = 13 ' // Intel-IA64-Filler
%EMARCH_ENC_I17_IMM5C_VAL_POS_X          = 16 ' // Intel-IA64-Filler

%EMARCH_ENC_I17_IC_INST_WORD_X           = 3  ' // Intel-IA64-Filler
%EMARCH_ENC_I17_IC_SIZE_X                = 1  ' // Intel-IA64-Filler
%EMARCH_ENC_I17_IC_INST_WORD_POS_X       = 12 ' // Intel-IA64-Filler
%EMARCH_ENC_I17_IC_VAL_POS_X             = 21 ' // Intel-IA64-Filler

%EMARCH_ENC_I17_IMM41a_INST_WORD_X       = 1  ' // Intel-IA64-Filler
%EMARCH_ENC_I17_IMM41a_SIZE_X            = 10 ' // Intel-IA64-Filler
%EMARCH_ENC_I17_IMM41a_INST_WORD_POS_X   = 14 ' // Intel-IA64-Filler
%EMARCH_ENC_I17_IMM41a_VAL_POS_X         = 22 ' // Intel-IA64-Filler

%EMARCH_ENC_I17_IMM41b_INST_WORD_X       = 1  ' // Intel-IA64-Filler
%EMARCH_ENC_I17_IMM41b_SIZE_X            = 8  ' // Intel-IA64-Filler
%EMARCH_ENC_I17_IMM41b_INST_WORD_POS_X   = 24 ' // Intel-IA64-Filler
%EMARCH_ENC_I17_IMM41b_VAL_POS_X         = 32 ' // Intel-IA64-Filler

%EMARCH_ENC_I17_IMM41c_INST_WORD_X       = 2  ' // Intel-IA64-Filler
%EMARCH_ENC_I17_IMM41c_SIZE_X            = 23 ' // Intel-IA64-Filler
%EMARCH_ENC_I17_IMM41c_INST_WORD_POS_X   = 0  ' // Intel-IA64-Filler
%EMARCH_ENC_I17_IMM41c_VAL_POS_X         = 40 ' // Intel-IA64-Filler

%EMARCH_ENC_I17_SIGN_INST_WORD_X         = 3  ' // Intel-IA64-Filler
%EMARCH_ENC_I17_SIGN_SIZE_X              = 1  ' // Intel-IA64-Filler
%EMARCH_ENC_I17_SIGN_INST_WORD_POS_X     = 27 ' // Intel-IA64-Filler
%EMARCH_ENC_I17_SIGN_VAL_POS_X           = 63 ' // Intel-IA64-Filler

%X3_OPCODE_INST_WORD_X                   = 3  ' // Intel-IA64-Filler
%X3_OPCODE_SIZE_X                        = 4  ' // Intel-IA64-Filler
%X3_OPCODE_INST_WORD_POS_X               = 28 ' // Intel-IA64-Filler
%X3_OPCODE_SIGN_VAL_POS_X                = 0  ' // Intel-IA64-Filler

%X3_I_INST_WORD_X                        = 3  ' // Intel-IA64-Filler
%X3_I_SIZE_X                             = 1  ' // Intel-IA64-Filler
%X3_I_INST_WORD_POS_X                    = 27 ' // Intel-IA64-Filler
%X3_I_SIGN_VAL_POS_X                     = 59 ' // Intel-IA64-Filler

%X3_D_WH_INST_WORD_X                     = 3  ' // Intel-IA64-Filler
%X3_D_WH_SIZE_X                          = 3  ' // Intel-IA64-Filler
%X3_D_WH_INST_WORD_POS_X                 = 24 ' // Intel-IA64-Filler
%X3_D_WH_SIGN_VAL_POS_X                  = 0  ' // Intel-IA64-Filler

%X3_IMM20_INST_WORD_X                    = 3  ' // Intel-IA64-Filler
%X3_IMM20_SIZE_X                         = 20 ' // Intel-IA64-Filler
%X3_IMM20_INST_WORD_POS_X                = 4  ' // Intel-IA64-Filler
%X3_IMM20_SIGN_VAL_POS_X                 = 0  ' // Intel-IA64-Filler

%X3_IMM39_1_INST_WORD_X                  = 2  ' // Intel-IA64-Filler
%X3_IMM39_1_SIZE_X                       = 23 ' // Intel-IA64-Filler
%X3_IMM39_1_INST_WORD_POS_X              = 0  ' // Intel-IA64-Filler
%X3_IMM39_1_SIGN_VAL_POS_X               = 36 ' // Intel-IA64-Filler

%X3_IMM39_2_INST_WORD_X                  = 1  ' // Intel-IA64-Filler
%X3_IMM39_2_SIZE_X                       = 16 ' // Intel-IA64-Filler
%X3_IMM39_2_INST_WORD_POS_X              = 16 ' // Intel-IA64-Filler
%X3_IMM39_2_SIGN_VAL_POS_X               = 20 ' // Intel-IA64-Filler

%X3_P_INST_WORD_X                        = 3 ' // Intel-IA64-Filler
%X3_P_SIZE_X                             = 4 ' // Intel-IA64-Filler
%X3_P_INST_WORD_POS_X                    = 0 ' // Intel-IA64-Filler
%X3_P_SIGN_VAL_POS_X                     = 0 ' // Intel-IA64-Filler

%X3_TMPLT_INST_WORD_X                    = 0 ' // Intel-IA64-Filler
%X3_TMPLT_SIZE_X                         = 4 ' // Intel-IA64-Filler
%X3_TMPLT_INST_WORD_POS_X                = 0 ' // Intel-IA64-Filler
%X3_TMPLT_SIGN_VAL_POS_X                 = 0 ' // Intel-IA64-Filler

%X3_BTYPE_QP_INST_WORD_X                 = 2  ' // Intel-IA64-Filler
%X3_BTYPE_QP_SIZE_X                      = 9  ' // Intel-IA64-Filler
%X3_BTYPE_QP_INST_WORD_POS_X             = 23 ' // Intel-IA64-Filler
%X3_BTYPE_QP_INST_VAL_POS_X              = 0  ' // Intel-IA64-Filler

%X3_EMPTY_INST_WORD_X                    = 1  ' // Intel-IA64-Filler
%X3_EMPTY_SIZE_X                         = 2  ' // Intel-IA64-Filler
%X3_EMPTY_INST_WORD_POS_X                = 14 ' // Intel-IA64-Filler
%X3_EMPTY_INST_VAL_POS_X                 = 0  ' // Intel-IA64-Filler

'//
'// Line number format.
'//

'typedef struct _IMAGE_LINENUMBER {
'    union {
'        DWORD   SymbolTableIndex;               // Symbol table index of function name if Linenumber is 0.
'        DWORD   VirtualAddress;                 // Virtual address of line number.
'    } Type;
'    WORD    Linenumber;                         // Line number.
'} IMAGE_LINENUMBER;
'typedef IMAGE_LINENUMBER UNALIGNED *PIMAGE_LINENUMBER;

' // Size = 4 bytes
UNION IMAGE_LINENUMBER_UNION BYTE
   SymbolTableIndex AS DWORD              ' // Symbol table index of function name if Linenumber is 0.
   VirtualAddress   AS DWORD              ' // Virtual address of line number.
END UNION
' // For compatibility with the PB headers
UNION IMAGE_LINENUMBER_TYPE_UNION BYTE
   Type       AS IMAGE_LINENUMBER_UNION
   xType      AS IMAGE_LINENUMBER_UNION
END UNION

' // Size = 6 bytes
TYPE IMAGE_LINENUMBER BYTE
   IMAGE_LINENUMBER_TYPE_UNION
   Linenumber AS WORD             ' // Line number.
END TYPE
'typedef IMAGE_LINENUMBER UNALIGNED *PIMAGE_LINENUMBER;

%IMAGE_SIZEOF_LINENUMBER             = 6

'#ifndef _MAC
'#include "poppack.h"                        // Back to 4 byte packing
'#endif

'//
'// Based relocation format.
'//

' // Size = 8 bytes
TYPE IMAGE_BASE_RELOCATION DWORD
   VirtualAddress AS DWORD
   SizeOfBlock    AS DWORD
'//  WORD    TypeOffset[1];
END TYPE


%IMAGE_SIZEOF_BASE_RELOCATION        = 8

'//
'// Based relocation types.
'//

%IMAGE_REL_BASED_ABSOLUTE             = 0
%IMAGE_REL_BASED_HIGH                 = 1
%IMAGE_REL_BASED_LOW                  = 2
%IMAGE_REL_BASED_HIGHLOW              = 3
%IMAGE_REL_BASED_HIGHADJ              = 4
%IMAGE_REL_BASED_MIPS_JMPADDR         = 5
%IMAGE_REL_BASED_MIPS_JMPADDR16       = 9
%IMAGE_REL_BASED_IA64_IMM64           = 9
%IMAGE_REL_BASED_DIR64                = 10

'//
'// Archive format.
'//

'#define IMAGE_ARCHIVE_START_SIZE             8
'#define IMAGE_ARCHIVE_START                  "!<arch>\n"
'#define IMAGE_ARCHIVE_END                    "`\n"
'#define IMAGE_ARCHIVE_PAD                    "\n"
'#define IMAGE_ARCHIVE_LINKER_MEMBER          "/               "
'#define IMAGE_ARCHIVE_LONGNAMES_MEMBER       "//              "

%IMAGE_ARCHIVE_START_SIZE            = 8
$IMAGE_ARCHIVE_START                 = "!<arch>\n"
$IMAGE_ARCHIVE_END                   = "`\n"
$IMAGE_ARCHIVE_PAD                   = "\n"
$IMAGE_ARCHIVE_LINKER_MEMBER         = "/               "
$IMAGE_ARCHIVE_LONGNAMES_MEMBER      = "//              "

UNION IMAGE_ARCHIVE_MEMBER_HEADER_NAME_UNION
   Name(15)     AS BYTE                   ' BYTE[16] // File member name - `/' terminated.
   ' // For compatibility with the PB hedets
   bName(15)    AS BYTE                   ' BYTE[16] // File member name - `/' terminated.
END UNION
UNION IMAGE_ARCHIVE_MEMBER_HEADER_MODE_UNION
   Mode(7)      AS BYTE                   ' BYTE[8]  // File member mode - octal.
   ' // For compatibility with the PB hedets
   bMode(7)     AS BYTE                   ' BYTE[8]  // File member mode - octal.
END UNION
UNION IMAGE_ARCHIVE_MEMBER_HEADER_SIZE_UNION
   Size(9)      AS BYTE                   ' BYTE[10] // File member size - decimal.
   ' // For compatibility with the PB hedets
   bSize(9)     AS BYTE                   ' BYTE[10] // File member size - decimal.
END UNION

' // Size = 60 bytes
TYPE IMAGE_ARCHIVE_MEMBER_HEADER BYTE
   IMAGE_ARCHIVE_MEMBER_HEADER_NAME_UNION
   Date(11)     AS BYTE                   ' BYTE[12] // File member date - decimal.
   UserID(5)    AS BYTE                   ' BYTE[6]  // File member user id - decimal.
   GroupID(5)   AS BYTE                   ' BYTE[6]  // File member group id - decimal.
   IMAGE_ARCHIVE_MEMBER_HEADER_MODE_UNION
   IMAGE_ARCHIVE_MEMBER_HEADER_SIZE_UNION
   EndHeader(1) AS BYTE                   ' BYTE[2]  // String to end header.
END TYPE

%IMAGE_SIZEOF_ARCHIVE_MEMBER_HDR     = 60

'//
'// DLL support.
'//

'//
'// Export Format
'//

' // Size = 40 bytes
TYPE IMAGE_EXPORT_DIRECTORY DWORD FILL
   Characteristics       AS DWORD
   TimeDateStamp         AS DWORD
   MajorVersion          AS WORD
   MinorVersion          AS WORD
   nName                 AS DWORD
   nBase                 AS DWORD
   NumberOfFunctions     AS DWORD
   NumberOfNames         AS DWORD
   AddressOfFunctions    AS DWORD   ' // RVA from base of image
   AddressOfNames        AS DWORD   ' // RVA from base of image
   AddressOfNameOrdinals AS DWORD   ' // RVA from base of image
END TYPE

'//
'// Import Format
'//

UNION IMAGE_IMPORT_BY_NAME_NAME_UNION
   Name(0) AS BYTE   ' BYTE    Name[1]
   ' // For compatibility with the PB headers
   bName(0) AS BYTE  ' BYTE    Name[1]
END UNION

' // Size = 4 bytes
TYPE IMAGE_IMPORT_BY_NAME WORD
   Hint    AS WORD   ' WORD
   IMAGE_IMPORT_BY_NAME_NAME_UNION
END TYPE

'#include "pshpack8.h"                       // Use align 8 for the 64-bit IAT.

'typedef struct _IMAGE_THUNK_DATA64 {
'    union {
'        ULONGLONG ForwarderString;  // PBYTE
'        ULONGLONG Function;         // PDWORD
'        ULONGLONG Ordinal;
'        ULONGLONG AddressOfData;    // PIMAGE_IMPORT_BY_NAME
'    } u1;
'} IMAGE_THUNK_DATA64;
'typedef IMAGE_THUNK_DATA64 * PIMAGE_THUNK_DATA64;

UNION IMAGE_THUNK_DATA64_FUNCTION_UNION QWORD
   Function        AS QUAD     ' ULONGLONG // PDWORD
   ' // For compatibility with the PB headers
   nFunction       AS QUAD     ' ULONGLONG // PDWORD
END UNION

' // Size = 8 bytes
UNION IMAGE_THUNK_DATA64_UNION QWORD
   ForwarderString AS QUAD     ' ULONGLONG // PBYTE
   IMAGE_THUNK_DATA64_FUNCTION_UNION
   Ordinal         AS QUAD     ' ULONGLONG
   AddressOfData   AS QUAD     ' ULONGLONG // PIMAGE_IMPORT_BY_NAME
END UNION

' // Size = 8 bytes
TYPE IMAGE_THUNK_DATA64 QWORD
   IMAGE_THUNK_DATA64_UNION
END TYPE

'#include "poppack.h"                        // Back to 4 byte packing

'typedef struct _IMAGE_THUNK_DATA32 {
'    union {
'        DWORD ForwarderString;      // PBYTE
'        DWORD Function;             // PDWORD
'        DWORD Ordinal;
'        DWORD AddressOfData;        // PIMAGE_IMPORT_BY_NAME
'    } u1;
'} IMAGE_THUNK_DATA32;
'typedef IMAGE_THUNK_DATA32 * PIMAGE_THUNK_DATA32;

UNION IMAGE_THUNK_DATA32_FUNCTION_UNION QWORD
   Function        AS QUAD     ' ULONGLONG // PDWORD
   ' // For compatibility with the PB headers
   nFunction       AS QUAD     ' ULONGLONG // PDWORD
END UNION

' // Size = 4 bytes
UNION IMAGE_THUNK_DATA32_UNION DWORD
   ForwarderString AS DWORD     ' // PBYTE
   IMAGE_THUNK_DATA32_FUNCTION_UNION
   Ordinal         AS DWORD
   AddressOfData   AS DWORD     ' // PIMAGE_IMPORT_BY_NAME
END UNION

' // Size = 4 bytes
TYPE IMAGE_THUNK_DATA32 DWORD
   IMAGE_THUNK_DATA32_UNION
END TYPE

'#define IMAGE_ORDINAL_FLAG64 0x8000000000000000
'#define IMAGE_ORDINAL_FLAG32 0x80000000
'#define IMAGE_ORDINAL64(Ordinal) (Ordinal & 0xffff)
'#define IMAGE_ORDINAL32(Ordinal) (Ordinal & 0xffff)
'#define IMAGE_SNAP_BY_ORDINAL64(Ordinal) ((Ordinal & IMAGE_ORDINAL_FLAG64) != 0)
'#define IMAGE_SNAP_BY_ORDINAL32(Ordinal) ((Ordinal & IMAGE_ORDINAL_FLAG32) != 0)

%IMAGE_ORDINAL_FLAG64 = &H8000000000000000&&
%IMAGE_ORDINAL_FLAG32 = &H80000000
MACRO IMAGE_ORDINAL64(Ordinal) = (Ordinal AND &Hffff)
MACRO IMAGE_ORDINAL32(Ordinal) = (Ordinal AND &Hffff)
MACRO IMAGE_SNAP_BY_ORDINAL64(Ordinal) = ((Ordinal AND IMAGE_ORDINAL_FLAG64) <> 0)
MACRO IMAGE_SNAP_BY_ORDINAL32(Ordinal) = ((Ordinal AND IMAGE_ORDINAL_FLAG32) <> 0)

'//
'// Thread Local Storage
'//

'typedef VOID
'(NTAPI *PIMAGE_TLS_CALLBACK) (
'    PVOID DllHandle,
'    DWORD Reason,
'    PVOID Reserved
'    );

'typedef struct _IMAGE_TLS_DIRECTORY64 {
'    ULONGLONG   StartAddressOfRawData;
'    ULONGLONG   EndAddressOfRawData;
'    ULONGLONG   AddressOfIndex;         // PDWORD
'    ULONGLONG   AddressOfCallBacks;     // PIMAGE_TLS_CALLBACK *;
'    DWORD   SizeOfZeroFill;
'    DWORD   Characteristics;
'} IMAGE_TLS_DIRECTORY64;
'typedef IMAGE_TLS_DIRECTORY64 * PIMAGE_TLS_DIRECTORY64;

'typedef struct _IMAGE_TLS_DIRECTORY32 {
'    DWORD   StartAddressOfRawData;
'    DWORD   EndAddressOfRawData;
'    DWORD   AddressOfIndex;             // PDWORD
'    DWORD   AddressOfCallBacks;         // PIMAGE_TLS_CALLBACK *
'    DWORD   SizeOfZeroFill;
'    DWORD   Characteristics;
'} IMAGE_TLS_DIRECTORY32;
'typedef IMAGE_TLS_DIRECTORY32 * PIMAGE_TLS_DIRECTORY32;

'typedef struct _IMAGE_IMPORT_DESCRIPTOR {
'    union {
'        DWORD   Characteristics;            // 0 for terminating null import descriptor
'        DWORD   OriginalFirstThunk;         // RVA to original unbound IAT (PIMAGE_THUNK_DATA)
'    };
'    DWORD   TimeDateStamp;                  // 0 if not bound,
'                                            // -1 if bound, and real date\time stamp
'                                            //     in IMAGE_DIRECTORY_ENTRY_BOUND_IMPORT (new BIND)
'                                            // O.W. date/time stamp of DLL bound to (Old BIND)

'    DWORD   ForwarderChain;                 // -1 if no forwarders
'    DWORD   Name;
'    DWORD   FirstThunk;                     // RVA to IAT (if bound this IAT has actual addresses)
'} IMAGE_IMPORT_DESCRIPTOR;
'typedef IMAGE_IMPORT_DESCRIPTOR UNALIGNED *PIMAGE_IMPORT_DESCRIPTOR;

' // Size = 4 bytes
UNION IMAGE_IMPORT_DESCRIPTOR_UNION DWORD
   Characteristics    AS DWORD           ' // 0 for terminating null import descriptor
   OriginalFirstThunk AS DWORD        ' // RVA to original unbound IAT (PIMAGE_THUNK_DATA)
END UNION

'#ifdef _WIN64
'#define IMAGE_ORDINAL_FLAG              IMAGE_ORDINAL_FLAG64
'#define IMAGE_ORDINAL(Ordinal)          IMAGE_ORDINAL64(Ordinal)
'typedef IMAGE_THUNK_DATA64              IMAGE_THUNK_DATA;
'typedef PIMAGE_THUNK_DATA64             PIMAGE_THUNK_DATA;
'#define IMAGE_SNAP_BY_ORDINAL(Ordinal)  IMAGE_SNAP_BY_ORDINAL64(Ordinal)
'typedef IMAGE_TLS_DIRECTORY64           IMAGE_TLS_DIRECTORY;
'typedef PIMAGE_TLS_DIRECTORY64          PIMAGE_TLS_DIRECTORY;
'#else
'#define IMAGE_ORDINAL_FLAG              IMAGE_ORDINAL_FLAG32
'#define IMAGE_ORDINAL(Ordinal)          IMAGE_ORDINAL32(Ordinal)
'typedef IMAGE_THUNK_DATA32              IMAGE_THUNK_DATA;
'typedef PIMAGE_THUNK_DATA32             PIMAGE_THUNK_DATA;
'#define IMAGE_SNAP_BY_ORDINAL(Ordinal)  IMAGE_SNAP_BY_ORDINAL32(Ordinal)
'typedef IMAGE_TLS_DIRECTORY32           IMAGE_TLS_DIRECTORY;
'typedef PIMAGE_TLS_DIRECTORY32          PIMAGE_TLS_DIRECTORY;
'#endif

UNION IMAGE_IMPORT_DESCRIPTOR_NAME_UNION DWORD
   Name           AS DWORD
   ' // For compatibility with the PB headers
   nName          AS DWORD
END UNION

' // Size = 20 bytes
TYPE IMAGE_IMPORT_DESCRIPTOR DWORD
   IMAGE_IMPORT_DESCRIPTOR_UNION
   TimeDateStamp  AS DWORD   ' // 0 if not bound,
                             ' // -1 if bound, and real date\time stamp
                             ' //     in IMAGE_DIRECTORY_ENTRY_BOUND_IMPORT (new BIND)
                             ' // O.W. date/time stamp of DLL bound to (Old BIND)
   ForwarderChain AS DWORD   ' // -1 if no forwarders
   IMAGE_IMPORT_DESCRIPTOR_NAME_UNION
   FirstThunk     AS DWORD   ' // RVA to IAT (if bound this IAT has actual addresses)
END TYPE

'//
'// New format import descriptors pointed to by DataDirectory[ IMAGE_DIRECTORY_ENTRY_BOUND_IMPORT ]
'//

' // Size = 8 bytes
TYPE IMAGE_BOUND_IMPORT_DESCRIPTOR WORD
   TimeDateStamp               AS DWORD
   OffsetModuleName            AS WORD
   NumberOfModuleForwarderRefs AS WORD
   '// Array of zero or more IMAGE_BOUND_FORWARDER_REF follows
END TYPE

' // Size = 8 bytes
TYPE IMAGE_BOUND_FORWARDER_REF WORD
   TimeDateStamp    AS DWORD
   OffsetModuleName AS WORD
   Reserved         AS WORD
END TYPE

'//
'// Resource Format.
'//

'//
'// Resource directory consists of two counts, following by a variable length
'// array of directory entries.  The first count is the number of entries at
'// beginning of the array that have actual names associated with each entry.
'// The entries are in ascending order, case insensitive strings.  The second
'// count is the number of entries that immediately follow the named entries.
'// This second count identifies the number of entries that have 16-bit integer
'// Ids as their name.  These entries are also sorted in ascending order.
'//
'// This structure allows fast lookup by either name or number, but for any
'// given resource entry only one form of lookup is supported, not both.
'// This is consistant with the syntax of the .RC file and the .RES file.
'//

' // Size = 16 bytes
TYPE IMAGE_RESOURCE_DIRECTORY WORD
   Characteristics      AS DWORD
   TimeDateStamp        AS DWORD
   MajorVersion         AS WORD
   MinorVersion         AS WORD
   NumberOfNamedEntries AS WORD
   NumberOfIdEntries    AS WORD
   '//  IMAGE_RESOURCE_DIRECTORY_ENTRY DirectoryEntries[];
END TYPE

%IMAGE_RESOURCE_NAME_IS_STRING       = &H80000000???
%IMAGE_RESOURCE_DATA_IS_DIRECTORY    = &H80000000???

'//
'// Each directory contains the 32-bit Name of the entry and an offset,
'// relative to the beginning of the resource directory of the data associated
'// with this directory entry.  If the name of the entry is an actual text
'// string instead of an integer Id, then the high order bit of the name field
'// is set to one and the low order 31-bits are an offset, relative to the
'// beginning of the resource directory of the string, which is of type
'// IMAGE_RESOURCE_DIRECTORY_STRING.  Otherwise the high bit is clear and the
'// low-order 16-bits are the integer Id that identify this resource directory
'// entry. If the directory entry is yet another resource directory (i.e. a
'// subdirectory), then the high order bit of the offset field will be
'// set to indicate this.  Otherwise the high bit is clear and the offset
'// field points to a resource data entry.
'//

'typedef struct _IMAGE_RESOURCE_DIRECTORY_ENTRY {
'    union {
'        struct {
'            DWORD NameOffset:31;
'            DWORD NameIsString:1;
'        };
'        DWORD   Name;
'        WORD    Id;
'    };
'    union {
'        DWORD   OffsetToData;
'        struct {
'            DWORD   OffsetToDirectory:31;
'            DWORD   DataIsDirectory:1;
'        };
'    };
'} IMAGE_RESOURCE_DIRECTORY_ENTRY, *PIMAGE_RESOURCE_DIRECTORY_ENTRY;

' // Size = 4 bytes
TYPE IMAGE_RESOURCE_DIRECTORY_ENTRY_UNION_STRUCT_1 DWORD
   NameOffset   AS BIT * 31 IN DWORD
   NameIsString AS BIT * 1
END TYPE

UNION IMAGE_RESOURCE_DIRECTORY_ENTRY_UNION_1_NAME
   Name AS DWORD
   ' // For compatibility with the PB declares
   nName AS DWORD
END UNION

UNION IMAGE_RESOURCE_DIRECTORY_ENTRY_UNION_1_ID
   Id   AS WORD
   ' // For compatibility with the PB declares
   nId  AS WORD
END UNION

' // Size = 4 bytes
UNION IMAGE_RESOURCE_DIRECTORY_ENTRY_UNION_1 DWORD
   IMAGE_RESOURCE_DIRECTORY_ENTRY_UNION_STRUCT_1
   IMAGE_RESOURCE_DIRECTORY_ENTRY_UNION_1_NAME
   IMAGE_RESOURCE_DIRECTORY_ENTRY_UNION_1_ID
END UNION

' // Size = 4 bytes
TYPE IMAGE_RESOURCE_DIRECTORY_ENTRY_UNION_STRUCT_2 DWORD
   OffsetToDirectory AS BIT * 31 IN DWORD
   DataIsDirectory   AS BIT * 1
END TYPE

' // Size = 4 bytes
UNION IMAGE_RESOURCE_DIRECTORY_ENTRY_UNION_2 DWORD
   OffsetToData AS DWORD
   IMAGE_RESOURCE_DIRECTORY_ENTRY_UNION_STRUCT_2
END UNION

' // Size = 8 bytes
TYPE IMAGE_RESOURCE_DIRECTORY_ENTRY DWORD
   IMAGE_RESOURCE_DIRECTORY_ENTRY_UNION_1
   IMAGE_RESOURCE_DIRECTORY_ENTRY_UNION_2
END TYPE

'//
'// For resource directory entries that have actual string names, the Name
'// field of the directory entry points to an object of the following type.
'// All of these string objects are stored together after the last resource
'// directory entry and before the first resource data object.  This minimizes
'// the impact of these variable length objects on the alignment of the fixed
'// size directory entry objects.
'//

' // Size = 4 bytes
TYPE IMAGE_RESOURCE_DIRECTORY_STRING WORD
   Length     AS WORD         ' WORD
   NameString AS ASCIIZ * 1   ' CHAR    NameString[ 1 ]
END TYPE

' // Size = 4 bytes
TYPE IMAGE_RESOURCE_DIR_STRING_U WORD
   Length     AS WORD           ' WORD
   NameString AS WSTRINGZ * 1   ' WCHAR   NameString[ 1 ]
END TYPE


'//
'// Each resource data entry describes a leaf node in the resource directory
'// tree.  It contains an offset, relative to the beginning of the resource
'// directory of the data for the resource, a size field that gives the number
'// of bytes of data at that offset, a CodePage that should be used when
'// decoding code point values within the resource data.  Typically for new
'// applications the code page would be the unicode code page.
'//

UNION IMAGE_RESOURCE_DATA_ENTRY_SIZE_UNION DWORD
   Size         AS DWORD
   ' // For compatibility with the PB declares
   dSize        AS DWORD
END UNION

' // Size = 16 bytes
TYPE IMAGE_RESOURCE_DATA_ENTRY DWORD
   OffsetToData AS DWORD
   IMAGE_RESOURCE_DATA_ENTRY_SIZE_UNION
   CodePage     AS DWORD
   Reserved     AS DWORD
END TYPE

'//
'// Load Configuration Directory Entry
'//

UNION IMAGE_LOAD_CONFIG_DIRECTORY32_SIZE_UNION
   Size                          AS DWORD
   ' // For compatibility with the PB declares
   nSize                         AS DWORD
END UNION

' // Size = 72 bytes
TYPE IMAGE_LOAD_CONFIG_DIRECTORY32 DWORD FILL
   IMAGE_LOAD_CONFIG_DIRECTORY32_SIZE_UNION
   TimeDateStamp                 AS DWORD
   MajorVersion                  AS WORD
   MinorVersion                  AS WORD
   GlobalFlagsClear              AS DWORD
   GlobalFlagsSet                AS DWORD
   CriticalSectionDefaultTimeout AS DWORD
   DeCommitFreeBlockThreshold    AS DWORD
   DeCommitTotalFreeThreshold    AS DWORD
   LockPrefixTable               AS DWORD   ' // VA
   MaximumAllocationSize         AS DWORD
   VirtualMemoryThreshold        AS DWORD
   ProcessHeapFlags              AS DWORD
   ProcessAffinityMask           AS DWORD
   CSDVersion                    AS WORD
   Reserved1                     AS WORD
   EditList                      AS DWORD   ' // VA
   SecurityCookie                AS DWORD   ' // VA
   SEHandlerTable                AS DWORD   ' // VA
   SEHandlerCount                AS DWORD
END TYPE

UNION IMAGE_LOAD_CONFIG_DIRECTORY64_SIZE_UNION
   Size                          AS DWORD
   ' // For compatibility with the PB declares
   nSize                         AS DWORD
END UNION

' // Size = 112 bytes
TYPE IMAGE_LOAD_CONFIG_DIRECTORY64   ' Must be 8 byte aligned
   IMAGE_LOAD_CONFIG_DIRECTORY64_SIZE_UNION
   TimeDateStamp                 AS DWORD
   MajorVersion                  AS WORD
   MinorVersion                  AS WORD
   GlobalFlagsClear              AS DWORD
   GlobalFlagsSet                AS DWORD
   CriticalSectionDefaultTimeout AS DWORD
   DeCommitFreeBlockThreshold    AS QUAD
   DeCommitTotalFreeThreshold    AS QUAD    ' ULONGLONG
   LockPrefixTable               AS QUAD    ' ULONGLONG // VA
   MaximumAllocationSize         AS QUAD    ' ULONGLONG
   VirtualMemoryThreshold        AS QUAD    ' ULONGLONG
   ProcessAffinityMask           AS QUAD    ' ULONGLONG
   ProcessHeapFlags              AS DWORD
   CSDVersion                    AS WORD
   Reserved1                     AS WORD
   EditList                      AS QUAD    ' ULONGLONG // VA
   SecurityCookie                AS QUAD    ' ULONGLONG // VA
   SEHandlerTable                AS QUAD    ' ULONGLONG // VA
   SEHandlerCount                AS QUAD
END TYPE

MACRO IMAGE_LOAD_CONFIG_DIRECTORY = IMAGE_LOAD_CONFIG_DIRECTORY32

'//
'// WIN CE Exception table format
'//

'//
'// Function table entry format.  Function table is pointed to by the
'// IMAGE_DIRECTORY_ENTRY_EXCEPTION directory entry.
'//

' // Size = 8 bytes
TYPE IMAGE_CE_RUNTIME_FUNCTION_ENTRY DWORD
   FuncStart     AS DWORD
   PrologLen     AS BIT   * 8  IN DWORD
   FuncLen       AS BIT   * 22
   ThirtyTwoBit  AS BIT   * 1
   ExceptionFlag AS BIT   * 1
END TYPE

' // Size = 40 bytes
TYPE IMAGE_ALPHA64_RUNTIME_FUNCTION_ENTRY QWORD
   BeginAddress     AS QUAD   ' ULONGLONG
   EndAddress       AS QUAD   ' ULONGLONG
   ExceptionHandler AS QUAD   ' ULONGLONG
   HandlerData      AS QUAD   ' ULONGLONG
   PrologEndAddress AS QUAD   ' ULONGLONG
END TYPE

' // Size = 20 bytes
TYPE IMAGE_ALPHA_RUNTIME_FUNCTION_ENTRY DWORD
   BeginAddress     AS DWORD
   EndAddress       AS DWORD
   ExceptionHandler AS DWORD
   HandlerData      AS DWORD
   PrologEndAddress AS DWORD
END TYPE

' // Size = 12 bytes
TYPE IMAGE_RUNTIME_FUNCTION_ENTRY DWORD
   BeginAddress      AS DWORD
   EndAddress        AS DWORD
   UnwindInfoAddress AS DWORD
END TYPE

'//
'// Debug Format
'//

UNION IMAGE_DEBUG_DIRECTORY_TYPE_UNION
   Type             AS DWORD
   ' // For compatibility with the PB headers
   nType            AS DWORD
END UNION

' // Size = 28 bytes
TYPE IMAGE_DEBUG_DIRECTORY DWORD FILL
   Characteristics  AS DWORD
   TimeDateStamp    AS DWORD
   MajorVersion     AS WORD
   MinorVersion     AS WORD
   IMAGE_DEBUG_DIRECTORY_TYPE_UNION
   SizeOfData       AS DWORD
   AddressOfRawData AS DWORD
   PointerToRawData AS DWORD
END TYPE

%IMAGE_DEBUG_TYPE_UNKNOWN         = 0
%IMAGE_DEBUG_TYPE_COFF            = 1
%IMAGE_DEBUG_TYPE_CODEVIEW        = 2
%IMAGE_DEBUG_TYPE_FPO             = 3
%IMAGE_DEBUG_TYPE_MISC            = 4
%IMAGE_DEBUG_TYPE_EXCEPTION       = 5
%IMAGE_DEBUG_TYPE_FIXUP           = 6
%IMAGE_DEBUG_TYPE_OMAP_TO_SRC     = 7
%IMAGE_DEBUG_TYPE_OMAP_FROM_SRC   = 8
%IMAGE_DEBUG_TYPE_BORLAND         = 9
%IMAGE_DEBUG_TYPE_RESERVED10      = 10
%IMAGE_DEBUG_TYPE_CLSID           = 11

' // Size = 32 bytes
TYPE IMAGE_COFF_SYMBOLS_HEADER DWORD
   NumberOfSymbols      AS DWORD
   LvaToFirstSymbol     AS DWORD
   NumberOfLinenumbers  AS DWORD
   LvaToFirstLinenumber AS DWORD
   RvaToFirstByteOfCode AS DWORD
   RvaToLastByteOfCode  AS DWORD
   RvaToFirstByteOfData AS DWORD
   RvaToLastByteOfData  AS DWORD
END TYPE

%FRAME_FPO      = 0
%FRAME_TRAP     = 1
%FRAME_TSS      = 2
%FRAME_NONFPO   = 3

' // Size = 16 bytes
TYPE FPO_DATA DWORD FILL
   ulOffStart AS DWORD               ' // offset 1st byte of function code
   cbProcSize AS DWORD               ' // # bytes in function
   cdwLocals  AS DWORD               ' // # bytes in locals/4
   cdwParams  AS WORD                ' // # bytes in params/4
   cbProlog   AS BIT   * 8 IN WORD   ' // # bytes in prolog
   cbRegs     AS BIT   * 3           ' // # regs saved
   fHasSEH    AS BIT   * 1           ' // TRUE if SEH in func
   fUseBP     AS BIT   * 1           ' // TRUE if EBP has been allocated
   reserved   AS BIT   * 1           ' // reserved for future use
   cbFrame    AS BIT   * 2           ' // frame type
END TYPE

%SIZEOF_RFPO_DATA = 16

%IMAGE_DEBUG_MISC_EXENAME = 1

' // Size = 16 bytes
TYPE IMAGE_DEBUG_MISC BYTE
   DataType    AS DWORD          ' DWORD    // type of misc data, see defines
   Length      AS DWORD          ' DWORD    // total length of record, rounded to four
                                 '          // byte multiple.
   Unicode     AS BYTE           ' BOOLLEAN // TRUE if data is unicode string
   Reserved(2) AS BYTE           ' BYTE     // Reserved[ 3 ]
   Data(3)     AS BYTE           ' BYTE Data[ 1 ]  // Actual data
   ' Note: We are using Data(3) instead of Data(0) to keep DWORD alignment
END TYPE

'//
'// Function table extracted from MIPS/ALPHA/IA64 images.  Does not contain
'// information needed only for runtime support.  Just those fields for
'// each entry needed by a debugger.
'//

' // Size = 12 bytes
TYPE IMAGE_FUNCTION_ENTRY DWORD
   StartingAddress AS DWORD
   EndingAddress   AS DWORD
   EndOfPrologue   AS DWORD
END TYPE

'typedef struct _IMAGE_FUNCTION_ENTRY64 {
'    ULONGLONG   StartingAddress;
'    ULONGLONG   EndingAddress;
'    union {
'        ULONGLONG   EndOfPrologue;
'        ULONGLONG   UnwindInfoAddress;
'    };
'} IMAGE_FUNCTION_ENTRY64, *PIMAGE_FUNCTION_ENTRY64;

' // Size = 8 bytes
UNION IMAGE_FUNCTION_ENTRY64_UNION QWORD
   EndOfPrologue     AS QUAD   ' ULONGLONG
   UnwindInfoAddress AS QUAD   ' ULONGLONG
END UNION

' // Size = 24 bytes
TYPE IMAGE_FUNCTION_ENTRY64 QWORD
   StartingAddress AS QUAD   ' ULONGLONG
   EndingAddress   AS QUAD   ' ULONGLONG
   IMAGE_FUNCTION_ENTRY64_UNION
END TYPE

'//
'// Debugging information can be stripped from an image file and placed
'// in a separate .DBG file, whose file name part is the same as the
'// image file name part (e.g. symbols for CMD.EXE could be stripped
'// and placed in CMD.DBG).  This is indicated by the IMAGE_FILE_DEBUG_STRIPPED
'// flag in the Characteristics field of the file header.  The beginning of
'// the .DBG file contains the following structure which captures certain
'// information from the image file.  This allows a debug to proceed even if
'// the original image file is not accessable.  This header is followed by
'// zero of more IMAGE_SECTION_HEADER structures, followed by zero or more
'// IMAGE_DEBUG_DIRECTORY structures.  The latter structures and those in
'// the image file contain file offsets relative to the beginning of the
'// .DBG file.
'//
'// If symbols have been stripped from an image, the IMAGE_DEBUG_MISC structure
'// is left in the image file, but not mapped.  This allows a debugger to
'// compute the name of the .DBG file, from the name of the image in the
'// IMAGE_DEBUG_MISC structure.
'//

' // Size = 48 bytes
TYPE IMAGE_SEPARATE_DEBUG_HEADER DWORD FILL
   Signature          AS WORD
   Flags              AS WORD
   Machine            AS WORD
   Characteristics    AS WORD
   TimeDateStamp      AS DWORD
   CheckSum           AS DWORD
   ImageBase          AS DWORD
   SizeOfImage        AS DWORD
   NumberOfSections   AS DWORD
   ExportedNamesSize  AS DWORD
   DebugDirectorySize AS DWORD
   SectionAlignment   AS DWORD
   Reserved(1)        AS DWORD
END TYPE

UNION NON_PAGED_DEBUG_INFO_SIZE_UNION
   Size            AS DWORD
   ' // For compatibility with the PB headers
   nSize           AS DWORD
END UNION

' // Size = 32 bytes
TYPE NON_PAGED_DEBUG_INFO DWORD FILL
   Signature       AS WORD
   Flags           AS WORD
   NON_PAGED_DEBUG_INFO_SIZE_UNION
   Machine         AS WORD
   Characteristics AS WORD
   TimeDateStamp   AS DWORD
   CheckSum        AS DWORD
   SizeOfImage     AS DWORD
   ImageBase       AS QUAD    ' ULONGLONG
   ' //DebugDirectorySize
   ' //IMAGE_DEBUG_DIRECTORY
END TYPE

%IMAGE_SEPARATE_DEBUG_SIGNATURE  = &H4944??
%NON_PAGED_DEBUG_SIGNATURE       = &H494E??

%IMAGE_SEPARATE_DEBUG_FLAGS_MASK = &H8000??
%IMAGE_SEPARATE_DEBUG_MISMATCH   = &H8000??  ' // when DBG was updated, the
                                             ' // old checksum didn't match.

'//
'//  The .arch section is made up of headers, each describing an amask position/value
'//  pointing to an array of IMAGE_ARCHITECTURE_ENTRY's.  Each "array" (both the header
'//  and entry arrays) are terminiated by a quadword of 0xffffffffL.
'//
'//  NOTE: There may be quadwords of 0 sprinkled around and must be skipped.
'//

' // Size = 8 bytes
TYPE IMAGE_ARCHITECTURE_HEADER DWORD
   AmaskValue    AS BIT   * 1  IN DWORD   ' // 1 -> code section depends on mask bit
                                                 ' // 0 -> new instruction depends on mask bit
   MBZ1          AS BIT   * 7             ' // MBZ
   AmaskShift    AS BIT   * 8             ' // Amask bit in question for this fixup
   MBZ2          AS BIT   * 16            ' // MBZ
   FirstEntryRVA AS DWORD                 ' // RVA into .arch section to array of ARCHITECTURE_ENTRY's
END TYPE

' // Size = 8 bytes
TYPE IMAGE_ARCHITECTURE_ENTRY DWORD
   FixupInstRVA AS DWORD   ' // RVA of instruction to fixup
   NewInst      AS DWORD   ' // fixup instruction (see alphaops.h)
END TYPE

'#include "poppack.h"                // Back to the initial value

'// The following structure defines the new import object.  Note the values of the first two fields,
'// which must be set as stated in order to differentiate old and new import members.
'// Following this structure, the linker emits two null-terminated strings used to recreate the
'// import at the time of use.  The first string is the import's name, the second is the dll's name.

%IMPORT_OBJECT_HDR_SIG2 = &Hffff??

'typedef struct IMPORT_OBJECT_HEADER {
'    WORD    Sig1;                       // Must be IMAGE_FILE_MACHINE_UNKNOWN
'    WORD    Sig2;                       // Must be IMPORT_OBJECT_HDR_SIG2.
'    WORD    Version;
'    WORD    Machine;
'    DWORD   TimeDateStamp;              // Time/date stamp
'    DWORD   SizeOfData;                 // particularly useful for incremental links

'    union {
'        WORD    Ordinal;                // if grf & IMPORT_OBJECT_ORDINAL
'        WORD    Hint;
'    };

'    WORD    Type : 2;                   // IMPORT_TYPE
'    WORD    NameType : 3;               // IMPORT_NAME_TYPE
'    WORD    Reserved : 11;              // Reserved. Must be zero.
'} IMPORT_OBJECT_HEADER;

' // Size = 2 bytes
UNION IMPORT_OBJECT_HEADER_UNION WORD
   Ordinal AS WORD                   ' // if grf & IMPORT_OBJECT_ORDINAL
   Hint    AS WORD
END UNION

#IF %DEF(%USEPBDECL)
TYPE IMPORT_OBJECT_HEADER WORD
   Sig1          AS WORD    ' // Must be IMAGE_FILE_MACHINE_UNKNOWN
   Sig2          AS WORD    ' // Must be IMPORT_OBJECT_HDR_SIG2.
   Version       AS WORD
   Machine       AS WORD
   TimeDateStamp AS DWORD   ' // Time/date stamp
   SizeOfData    AS DWORD   ' // particularly useful for incremental links
   IMPORT_OBJECT_HEADER_UNION
   nType         AS BIT * 2  IN WORD   ' // IMPORT_TYPE
   NameType      AS BIT * 3            ' // IMPORT_NAME_TYPE
   Reserved      AS BIT * 11           ' // Reserved. Must be zero.
END TYPE
#ELSE
' // Size = 20 bytes
TYPE IMPORT_OBJECT_HEADER WORD
   Sig1          AS WORD    ' // Must be IMAGE_FILE_MACHINE_UNKNOWN
   Sig2          AS WORD    ' // Must be IMPORT_OBJECT_HDR_SIG2.
   Version       AS WORD
   Machine       AS WORD
   TimeDateStamp AS DWORD   ' // Time/date stamp
   SizeOfData    AS DWORD   ' // particularly useful for incremental links
   IMPORT_OBJECT_HEADER_UNION
   Type          AS BIT * 2  IN WORD   ' // IMPORT_TYPE
   NameType      AS BIT * 3            ' // IMPORT_NAME_TYPE
   Reserved      AS BIT * 11           ' // Reserved. Must be zero.
END TYPE
#ENDIF

' IMPORT_OBJECT_TYPE enum
%IMPORT_OBJECT_CODE  = 0
%IMPORT_OBJECT_DATA  = 1
%IMPORT_OBJECT_CONST = 2

' IMPORT_OBJECT_NAME_TYPE enum
%IMPORT_OBJECT_ORDINAL = 0         ' // Import by ordinal
%IMPORT_OBJECT_NAME = 1            ' // Import name == public symbol name.
%IMPORT_OBJECT_NAME_NO_PREFIX = 2  ' // Import name == public symbol name skipping leading ?, @, or optionally _.
%IMPORT_OBJECT_NAME_UNDECORATE = 3 ' // Import name == public symbol name skipping leading ?, @, or optionally _
                                   ' // and truncating at first @

#IF NOT %DEF(%IMAGE_COR20_HEADER_DEFINED)  ' ----------------------------------
    %IMAGE_COR20_HEADER_DEFINED = 1
'#ifndef __IMAGE_COR20_HEADER_DEFINED__
'#define __IMAGE_COR20_HEADER_DEFINED__

'typedef enum ReplacesCorHdrNumericDefines
'{
'// COM+ Header entry point flags.
'    COMIMAGE_FLAGS_ILONLY               =0x00000001,
'    COMIMAGE_FLAGS_32BITREQUIRED        =0x00000002,
'    COMIMAGE_FLAGS_IL_LIBRARY           =0x00000004,
'    COMIMAGE_FLAGS_STRONGNAMESIGNED     =0x00000008,
'    COMIMAGE_FLAGS_NATIVE_ENTRYPOINT    =0x00000010,
'    COMIMAGE_FLAGS_TRACKDEBUGDATA       =0x00010000,

'// Version flags for image.
'    COR_VERSION_MAJOR_V2                =2,
'    COR_VERSION_MAJOR                   =COR_VERSION_MAJOR_V2,
'    COR_VERSION_MINOR                   =0,
'    COR_DELETED_NAME_LENGTH             =8,
'    COR_VTABLEGAP_NAME_LENGTH           =8,

'// Maximum size of a NativeType descriptor.
'    NATIVE_TYPE_MAX_CB                  =1,
'    COR_ILMETHOD_SECT_SMALL_MAX_DATASIZE=0xFF,

'// #defines for the MIH FLAGS
'    IMAGE_COR_MIH_METHODRVA             =0x01,
'    IMAGE_COR_MIH_EHRVA                 =0x02,
'    IMAGE_COR_MIH_BASICBLOCK            =0x08,

'// V-table constants
'    COR_VTABLE_32BIT                    =0x01,          // V-table slots are 32-bits in size.
'    COR_VTABLE_64BIT                    =0x02,          // V-table slots are 64-bits in size.
'    COR_VTABLE_FROM_UNMANAGED           =0x04,          // If set, transition from unmanaged.
'    COR_VTABLE_CALL_MOST_DERIVED        =0x10,          // Call most derived method described by

'// EATJ constants
'    IMAGE_COR_EATJ_THUNK_SIZE           =32,            // Size of a jump thunk reserved range.

'// Max name lengths
'    //@todo: Change to unlimited name lengths.
'    MAX_CLASS_NAME                      =1024,
'    MAX_PACKAGE_NAME                    =1024,
'} ReplacesCorHdrNumericDefines;

'// COM+ Header entry point flags.
%COMIMAGE_FLAGS_ILONLY               = &H00000001???
%COMIMAGE_FLAGS_32BITREQUIRED        = &H00000002???
%COMIMAGE_FLAGS_IL_LIBRARY           = &H00000004???
%COMIMAGE_FLAGS_STRONGNAMESIGNED     = &H00000008???
%COMIMAGE_FLAGS_TRACKDEBUGDATA       = &H00010000???

'// Version flags for image.
%COR_VERSION_MAJOR_V2                = 2
%COR_VERSION_MAJOR                   = %COR_VERSION_MAJOR_V2
%COR_VERSION_MINOR                   = 0
%COR_DELETED_NAME_LENGTH             = 8
%COR_VTABLEGAP_NAME_LENGTH           = 8

'// Maximum size of a NativeType descriptor.
%NATIVE_TYPE_MAX_CB                   = 1
%COR_ILMETHOD_SECT_SMALL_MAX_DATASIZE = &HFF

'// #defines for the MIH FLAGS
%IMAGE_COR_MIH_METHODRVA             = &H01
%IMAGE_COR_MIH_EHRVA                 = &H02
%IMAGE_COR_MIH_BASICBLOCK            = &H08

'// V-table constants
%COR_VTABLE_32BIT                    = &H01         ' // V-table slots are 32-bits in size.
%COR_VTABLE_64BIT                    = &H02         ' // V-table slots are 64-bits in size.
%COR_VTABLE_FROM_UNMANAGED           = &H04         ' // If set, transition from unmanaged.
%COR_VTABLE_CALL_MOST_DERIVED        = &H10         ' // Call most derived method described by

'// EATJ constants
%IMAGE_COR_EATJ_THUNK_SIZE           = 32           ' // Size of a jump thunk reserved range.

'// Max name lengths
'//@todo: Change to unlimited name lengths.
%MAX_CLASS_NAME                      = 1024
%MAX_PACKAGE_NAME                    = 1024

'// CLR 2.0 header structure.
'typedef struct IMAGE_COR20_HEADER
'{
'    // Header versioning
'    DWORD                   cb;
'    WORD                    MajorRuntimeVersion;
'    WORD                    MinorRuntimeVersion;

'    // Symbol table and startup information
'    IMAGE_DATA_DIRECTORY    MetaData;
'    DWORD                   Flags;

'    // If COMIMAGE_FLAGS_NATIVE_ENTRYPOINT is not set, EntryPointToken represents a managed entrypoint.
'    // If COMIMAGE_FLAGS_NATIVE_ENTRYPOINT is set, EntryPointRVA represents an RVA to a native entrypoint.
'    union {
'        DWORD               EntryPointToken;
'        DWORD               EntryPointRVA;
'    } DUMMYUNIONNAME;

'    // Binding information
'    IMAGE_DATA_DIRECTORY    Resources;
'    IMAGE_DATA_DIRECTORY    StrongNameSignature;

'    // Regular fixup and binding information
'    IMAGE_DATA_DIRECTORY    CodeManagerTable;
'    IMAGE_DATA_DIRECTORY    VTableFixups;
'    IMAGE_DATA_DIRECTORY    ExportAddressTableJumps;

'    // Precompiled image info (internal use only - set to zero)
'    IMAGE_DATA_DIRECTORY    ManagedNativeHeader;

'} IMAGE_COR20_HEADER, *PIMAGE_COR20_HEADER;

UNION IMAGE_COR20_HEADER_UNION
   EntryPointToken AS DWORD   ' DWORD
   EntryPointRVA   AS DWORD   ' DWORD
END UNION

'// COM+ 2.0 header structure.
' // Size = 72 bytes
TYPE IMAGE_COR20_HEADER WORD
   ' // Header versioning
   cb AS DWORD
   MajorRuntimeVersion AS WORD
   MinorRuntimeVersion AS WORD

   ' // Symbol table and startup information
   MetaData AS IMAGE_DATA_DIRECTORY
   Flags AS DWORD
   IMAGE_COR20_HEADER_UNION

   ' // Binding information
   Resources AS IMAGE_DATA_DIRECTORY
   StrongNameSignature AS IMAGE_DATA_DIRECTORY

   ' // Regular fixup and binding information
   CodeManagerTable AS IMAGE_DATA_DIRECTORY
   VTableFixups AS IMAGE_DATA_DIRECTORY
   ExportAddressTableJumps AS IMAGE_DATA_DIRECTORY

   ' // Precompiled image info (internal use only - set to zero)
   ManagedNativeHeader AS IMAGE_DATA_DIRECTORY
END TYPE

'#endif // __IMAGE_COR20_HEADER_DEFINED__
#ENDIF   ' #IF NOT %DEF(%IMAGE_COR20_HEADER_DEFINED)  -------------------------

'//
'// End Image Format
'//

'//
'// for move macros
'//
'#ifdef _MAC
'#ifndef _INC_STRING
'#include <string.h>
'#endif /* _INC_STRING */
'#else
'#include <string.h>
'#endif // _MAC


#IF NOT %DEF(%SLIST_HEADER)  ' ------------------------------------------------
    %SLIST_HEADER = 1
'#ifndef _SLIST_HEADER_
'#define _SLIST_HEADER_

'#if defined(_WIN64)

'//
'// The type SINGLE_LIST_ENTRY is not suitable for use with SLISTs.  For
'// WIN64, an entry on an SLIST is required to be 16-byte aligned, while a
'// SINGLE_LIST_ENTRY structure has only 8 byte alignment.
'//
'// Therefore, all SLIST code should use the SLIST_ENTRY type instead of the
'// SINGLE_LIST_ENTRY type.
'//

'#pragma warning(push)
'#pragma warning(disable:4324)   // structure padded due to align()
'typedef struct DECLSPEC_ALIGN(16) _SLIST_ENTRY *PSLIST_ENTRY;
'typedef struct DECLSPEC_ALIGN(16) _SLIST_ENTRY {
'    PSLIST_ENTRY Next;
'} SLIST_ENTRY;
'#pragma warning(pop)

'typedef struct _SLIST_ENTRY32 {
'    DWORD Next;
'} SLIST_ENTRY32, *PSLIST_ENTRY32;

'#else

'#define SLIST_ENTRY SINGLE_LIST_ENTRY
'#define _SLIST_ENTRY _SINGLE_LIST_ENTRY
'#define PSLIST_ENTRY PSINGLE_LIST_ENTRY

'#endif // _WIN64

' // Size = 4 bytes
TYPE SLIST_ENTRY32 DWORD
   Next AS DWORD   ' DWORD
END TYPE

' Assume 32 bits for now...
MACRO SLIST_ENTRY = SLIST_ENTRY32

'#if defined(_WIN64)

'typedef union DECLSPEC_ALIGN(16) _SLIST_HEADER {
'    struct {  // original struct
'        ULONGLONG Alignment;
'        ULONGLONG Region;
'    } DUMMYSTRUCTNAME;
'    struct {  // 8-byte header
'        ULONGLONG Depth:16;
'        ULONGLONG Sequence:9;
'        ULONGLONG NextEntry:39;
'        ULONGLONG HeaderType:1; // 0: 8-byte; 1: 16-byte
'        ULONGLONG Init:1;       // 0: uninitialized; 1: initialized
'        ULONGLONG Reserved:59;
'        ULONGLONG Region:3;
'    } Header8;
'    struct {  // ia64 16-byte header
'        ULONGLONG Depth:16;
'        ULONGLONG Sequence:48;
'        ULONGLONG HeaderType:1; // 0: 8-byte; 1: 16-byte
'        ULONGLONG Init:1;       // 0: uninitialized; 1: initialized
'        ULONGLONG Reserved:2;
'        ULONGLONG NextEntry:60; // last 4 bits are always 0's
'    } Header16;
'} SLIST_HEADER, *PSLIST_HEADER;

'#else

'typedef union _SLIST_HEADER32 {
'    ULONGLONG Alignment;
'    struct {
'        SLIST_ENTRY32 Next;
'        WORD   Depth;
'        WORD   Sequence;
'    } DUMMYSTRUCTNAME;
'} SLIST_HEADER32, *PSLIST_HEADER;

'#endif // _WIN64

'#endif // _SLIST_HEADER_

' // Size = 8 bytes
TYPE SLIST_HEADER32_STRUCT WORD
   Next      AS SLIST_ENTRY PTR
   Depth     AS WORD
   Sequence  AS WORD
END TYPE

' // Size = 8 bytes
UNION SLIST_HEADER32
   Alignment AS QUAD
   SLIST_HEADER32_STRUCT
END UNION

' Assume 32 bits for now...
MACRO SLIST_HEADER = SLIST_HEADER32

#ENDIF   ' #IF NOT %DEF(%SLIST_HEADER) ----------------------------------------

DECLARE SUB RtlInitializeSListHead IMPORT "NTDLL.DLL" ALIAS "RtlInitializeSListHead" ( _
   BYREF ListHead AS SLIST_HEADER _                     ' __in PSLIST_HEADER ListHead
 )                                                      ' VOID

DECLARE FUNCTION RtlFirstEntrySList IMPORT "NTDLL.DLL" ALIAS "RtlFirstEntrySList" ( _
   BYREF ListHead AS SLIST_HEADER _                     ' __in const SLIST_HEADER *ListHead
 ) AS DWORD                                             ' PSLIST_ENTRY

DECLARE FUNCTION RtlInterlockedPopEntrySList IMPORT "NTDLL.DLL" ALIAS "RtlInterlockedPopEntrySList" ( _
   BYREF ListHead AS SLIST_HEADER _                     ' __in PSLIST_HEADER ListHead
 ) AS DWORD                                             ' PSLIST_ENTRY

DECLARE FUNCTION RtlInterlockedPushEntrySList IMPORT "NTDLL.DLL" ALIAS "RtlInterlockedPushEntrySList" ( _
   BYREF ListHead AS SLIST_HEADER _                     ' __in PSLIST_HEADER ListHead
 , BYREF ListEntry AS SLIST_ENTRY _                     ' __in PSLIST_ENTRY ListEntry
 ) AS DWORD                                             ' PSLIST_ENTRY

DECLARE FUNCTION RtlInterlockedFlushSList IMPORT "NTDLL.DLL" ALIAS "RtlInterlockedFlushSList" ( _
   BYREF ListHead AS SLIST_HEADER _                     ' __in PSLIST_HEADER ListHead
 ) AS DWORD                                             ' PSLIST_ENTRY

DECLARE FUNCTION RtlQueryDepthSList IMPORT "NTDLL.DLL" ALIAS "RtlQueryDepthSList" ( _
   BYREF ListHead AS SLIST_HEADER _                     ' __in PSLIST_HEADER ListHead
 ) AS WORD                                              ' WORD

'#ifndef _RTL_RUN_ONCE_DEF
'#define _RTL_RUN_ONCE_DEF

'//
'// Run once
'//

%RTL_RUN_ONCE_INIT = 0   ' // Static initializer

'//
'// Run once flags
'//

%RTL_RUN_ONCE_CHECK_ONLY     = &H00000001???
%RTL_RUN_ONCE_ASYNC          = &H00000002???
%RTL_RUN_ONCE_INIT_FAILED    = &H00000004???

'//
'// The context stored in the run once structure must leave the following number
'// of low order bits unused.
'//

%RTL_RUN_ONCE_CTX_RESERVED_BITS = 2

UNION RTL_RUN_ONCE_UNION
   Ptr AS DWORD   ' PVOID
   ' // For compatibility with the PB declares
   pPtr AS DWORD   ' PVOID
END UNION

UNION RTL_RUN_ONCE
   RTL_RUN_ONCE_UNION
END UNION

'typedef
'__drv_functionClass(RTL_RUN_ONCE_INIT_FN)
'__drv_sameIRQL
'DWORD /* LOGICAL */
'NTAPI
'RTL_RUN_ONCE_INIT_FN (
'    __inout PRTL_RUN_ONCE RunOnce,
'    __inout_opt PVOID Parameter,
'    __opt_inout_opt PVOID *Context
'    );
'typedef RTL_RUN_ONCE_INIT_FN *PRTL_RUN_ONCE_INIT_FN;

'#endif // _RTL_RUN_ONCE_DEF

'#if (NTDDI_VERSION >= NTDDI_LONGHORN)

DECLARE SUB RtlRunOnceInitialize IMPORT "KERNEL32.DLL" ALIAS "RtlRunOnceInitialize" ( _
   BYREF RunOnce AS RTL_RUN_ONCE _                      ' __out PRTL_RUN_ONCE RunOnce
 )                                                      ' VOID

DECLARE FUNCTION RtlRunOnceExecuteOnce IMPORT "KERNEL32.DLL" ALIAS "RtlRunOnceExecuteOnce" ( _
   BYREF RunOnce AS RTL_RUN_ONCE _                      ' __inout PRTL_RUN_ONCE RunOnce
 , BYVAL InitFn AS DWORD _                              ' __in __callback PRTL_RUN_ONCE_INIT_FN InitFn
 , OPTIONAL BYREF Parameter AS ANY _                    ' __inout_opt PVOID Parameter
 , OPTIONAL BYREF Context AS ANY _                      ' __opt_out_opt PVOID *Context
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION RtlRunOnceBeginInitialize IMPORT "KERNEL32.DLL" ALIAS "RtlRunOnceBeginInitialize" ( _
   BYREF RunOnce AS RTL_RUN_ONCE _                      ' __inout PRTL_RUN_ONCE RunOnce
 , BYVAL Flags AS DWORD _                               ' __in DWORD Flags
 , OPTIONAL BYREF Context AS ANY _                      ' __opt_out_opt PVOID *Context
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION RtlRunOnceComplete IMPORT "KERNEL32.DLL" ALIAS "RtlRunOnceComplete" ( _
   BYREF RunOnce AS RTL_RUN_ONCE _                      ' __inout PRTL_RUN_ONCE RunOnce
 , BYVAL Flags AS DWORD _                               ' __in DWORD Flags
 , OPTIONAL BYVAL Context AS DWORD _                    ' __in_opt PVOID Context
 ) AS DWORD                                             ' DWORD

'#endif // NTDDI_VERSION >= NTDDI_LONGHORN

%HEAP_NO_SERIALIZE             = &H00000001???
%HEAP_GROWABLE                 = &H00000002???
%HEAP_GENERATE_EXCEPTIONS      = &H00000004???
%HEAP_ZERO_MEMORY              = &H00000008???
%HEAP_REALLOC_IN_PLACE_ONLY    = &H00000010???
%HEAP_TAIL_CHECKING_ENABLED    = &H00000020???
%HEAP_FREE_CHECKING_ENABLED    = &H00000040???
%HEAP_DISABLE_COALESCE_ON_FREE = &H00000080???
%HEAP_CREATE_ALIGN_16          = &H00010000???
%HEAP_CREATE_ENABLE_TRACING    = &H00020000???
%HEAP_MAXIMUM_TAG              = &H00000FFF???
%HEAP_PSEUDO_TAG_FLAG          = &H00008000???
%HEAP_TAG_SHIFT                = 18???

'#if !defined(MIDL_PASS)
'FORCEINLINE
'DWORD
'HEAP_MAKE_TAG_FLAGS (
'    __in DWORD TagBase,
'    __in DWORD Tag
'    )

'{
'    __assume_bound(TagBase);
'    return ((DWORD)((TagBase) + ((Tag) << HEAP_TAG_SHIFT)));
'}
'#endif

'#define HEAP_MAKE_TAG_FLAGS( b, o ) ((DWORD)((b) + ((o) << 18)))

FUNCTION HEAP_MAKE_TAG_FLAGS (BYVAL b AS DWORD, BYVAL o AS DWORD) AS DWORD
   SHIFT LEFT o, 18
   FUNCTION = b + o
END FUNCTION

'#if (NTDDI_VERSION > NTDDI_WINXP)
#IF %DEF(%USEPBDECL)
DECLARE FUNCTION RtlCaptureStackBackTrace LIB "Kernel32.dll" _
    ALIAS "RtlCaptureStackBackTrace" ( _
    BYVAL FramesToSkip           AS DWORD, _
    BYVAL FramesToCapture        AS DWORD, _
    BYVAL BackTrace              AS DWORD, _   ' PVOID *
    OPTIONAL BYVAL BackTraceHash AS DWORD _    ' DWORD PTR
    ) AS WORD
#ELSE
DECLARE FUNCTION RtlCaptureStackBackTrace IMPORT "KERNEL32.DLL" ALIAS "RtlCaptureStackBackTrace" ( _
   BYVAL FramesToSkip AS DWORD _                        ' __in DWORD FramesToSkip
 , BYVAL FramesToCapture AS DWORD _                     ' __in DWORD FramesToCapture
 , BYREF BackTrace AS ANY _                             ' __out_ecount(FramesToCapture) PVOID *BackTrace
 , OPTIONAL BYREF BackTraceHash AS DWORD _              ' __out_opt PDWORD BackTraceHash
 ) AS WORD                                              ' WORD
#ENDIF
'#endif

'#if (NTDDI_VERSION > NTDDI_WIN2K)
DECLARE SUB RtlCaptureContext IMPORT "KERNEL32.DLL" ALIAS "RtlCaptureContext" ( _
   BYREF ContextRecord AS CONTEXT _                     ' __out PCONTEXT ContextRecord
 )                                                      ' void
'#endif

%IS_TEXT_UNICODE_ASCII16            = &H0001???
%IS_TEXT_UNICODE_REVERSE_ASCII16    = &H0010???

%IS_TEXT_UNICODE_STATISTICS         = &H0002???
%IS_TEXT_UNICODE_REVERSE_STATISTICS = &H0020???

%IS_TEXT_UNICODE_CONTROLS           = &H0004???
%IS_TEXT_UNICODE_REVERSE_CONTROLS   = &H0040???

%IS_TEXT_UNICODE_SIGNATURE          = &H0008???
%IS_TEXT_UNICODE_REVERSE_SIGNATURE  = &H0080???

%IS_TEXT_UNICODE_ILLEGAL_CHARS      = &H0100???
%IS_TEXT_UNICODE_ODD_LENGTH         = &H0200???
%IS_TEXT_UNICODE_DBCS_LEADBYTE      = &H0400???
%IS_TEXT_UNICODE_NULL_BYTES         = &H1000???

%IS_TEXT_UNICODE_UNICODE_MASK       = &H000F???
%IS_TEXT_UNICODE_REVERSE_MASK       = &H00F0???
%IS_TEXT_UNICODE_NOT_UNICODE_MASK   = &H0F00???
%IS_TEXT_UNICODE_NOT_ASCII_MASK     = &HF000???

%COMPRESSION_FORMAT_NONE            = &H0000??
%COMPRESSION_FORMAT_DEFAULT         = &H0001??
%COMPRESSION_FORMAT_LZNT1           = &H0002??
%COMPRESSION_ENGINE_STANDARD        = &H0000??
%COMPRESSION_ENGINE_MAXIMUM         = &H0100??
%COMPRESSION_ENGINE_HIBER           = &H0200??

'#if _DBG_MEMCPY_INLINE_ && !defined(MIDL_PASS) && !defined(_MEMCPY_INLINE_) && !defined(_CRTBLD)
'#define _MEMCPY_INLINE_
'FORCEINLINE
'PVOID
'__cdecl
'memcpy_inline (
'    __out_bcount_full(size) void *dst,
'    __in_bcount(size) const void *src,
'    __in size_t size
'    )
'{
'    //
'    // Make sure the source and destination do not overlap such that the
'    // move destroys the destination.
'    //
'    if (((char *)dst > (char *)src) &&
'        ((char *)dst < ((char *)src + size))) {
'        __debugbreak();
'    }
'    return memcpy(dst, src, size);
'}
'#define memcpy memcpy_inline
'#endif

DECLARE FUNCTION RtlCompareMemory IMPORT "NTDLL.DLL" ALIAS "RtlCompareMemory" ( _
   BYREF Source1 AS ANY _                               ' __in const VOID *Source1
 , BYREF Source2 AS ANY _                               ' __in const VOID *Source2
 , BYVAL Length AS DWORD _                              ' __in SIZE_T Length
 ) AS DWORD                                             ' SIZE_T

DECLARE FUNCTION CompareMemory IMPORT "NTDLL.DLL" ALIAS "RtlCompareMemory" ( _
   BYVAL Source1 AS DWORD _                             ' __in const VOID *Source1
 , BYVAL Source2 AS DWORD _                             ' __in const VOID *Source2
 , BYVAL Length AS DWORD _                              ' __in SIZE_T Length
 ) AS DWORD                                             ' SIZE_T

'#define RtlEqualMemory(Destination,Source,Length) (!memcmp((Destination),(Source),(Length)))
'#define RtlMoveMemory(Destination,Source,Length) memmove((Destination),(Source),(Length))
'#define RtlCopyMemory(Destination,Source,Length) memcpy((Destination),(Source),(Length))
'#define RtlFillMemory(Destination,Length,Fill) memset((Destination),(Fill),(Length))
'#define RtlZeroMemory(Destination,Length) memset((Destination),0,(Length))

#IF %DEF(%USEPBDECL)
SUB RtlMoveMemory (BYVAL pDest AS DWORD, BYVAL pSrc AS DWORD, BYVAL ncBytes AS LONG)
    MEMORY COPY pSrc, pDest, ncBytes
END SUB
#ELSE
DECLARE SUB RtlMoveMemory IMPORT "KERNEL32.DLL" ALIAS "RtlMoveMemory" ( _
   BYREF Destination AS ANY _                           ' __in PVOID Destination
 , BYREF Source AS ANY _                                ' __in const VOID* Source
 , BYVAL Length AS DWORD _                              ' __in SIZE_T Length
 )                                                      ' void
#ENDIF

DECLARE SUB MoveMemory IMPORT "KERNEL32.DLL" ALIAS "RtlMoveMemory" ( _
   BYVAL Destination AS DWORD _                         ' __in PVOID Destination
 , BYVAL Source AS DWORD _                              ' __in const VOID* Source
 , BYVAL Length AS DWORD _                              ' __in SIZE_T Length
 )                                                      ' void

#IF %DEF(%USEPBDECL)
SUB RtlCopyMemory (BYVAL pDest AS DWORD, BYVAL pSrc AS DWORD, BYVAL ncBytes AS LONG)
    MEMORY COPY pSrc, pDest, ncBytes
END SUB
#ELSE
DECLARE SUB RtlCopyMemory IMPORT "KERNEL32.DLL" ALIAS "RtlMoveMemory" ( _
   BYREF Destination AS ANY _                           ' __in PVOID Destination
 , BYREF Source AS ANY _                                ' __in const VOID* Source
 , BYVAL Length AS DWORD _                              ' __in SIZE_T Length
 )                                                      ' void
#ENDIF

DECLARE SUB CopyMemory IMPORT "KERNEL32.DLL" ALIAS "RtlMoveMemory" ( _
   BYVAL Destination AS DWORD _                         ' __in PVOID Destination
 , BYVAL Source AS DWORD _                              ' __in const VOID* Source
 , BYVAL Length AS DWORD _                              ' __in SIZE_T Length
 )                                                      ' void

' RtlFillMemory is not supported on Windows 98 or Windows Me.
#IF %DEF(%USEPBDECL)
SUB RtlFillMemory (BYVAL pDest AS DWORD, BYVAL ncBytes AS DWORD, BYVAL nValue AS BYTE)
    MEMORY FILL pDest, ncBytes, BYTE nValue
END SUB
#ELSE
DECLARE SUB RtlFillMemory IMPORT "KERNEL32.DLL" ALIAS "RtlFillMemory" ( _
   BYREF Destination AS ANY _                           ' __in PVOID Destination
 , BYVAL Length AS DWORD _                              ' __in SIZE_T Length
 , BYVAL Fill AS BYTE _                                 ' __in BYTE Fill
 )                                                      ' void
#ENDIF

DECLARE SUB FillMemory IMPORT "KERNEL32.DLL" ALIAS "RtlFillMemory" ( _
   BYVAL Destination AS DWORD _                         ' __in PVOID Destination
 , BYVAL Length AS DWORD _                              ' __in SIZE_T Length
 , BYVAL Fill AS BYTE _                                 ' __in BYTE Fill
 )                                                      ' void

#IF %DEF(%USEPBDECL)
SUB RtlZeroMemory (BYVAL pDest AS DWORD, BYVAL ncBytes AS LONG)
    MEMORY FILL pDest, ncBytes, BYTE 0
END SUB
#ELSE
DECLARE SUB RtlZeroMemory IMPORT "KERNEL32.DLL" ALIAS "RtlZeroMemory" ( _
   BYREF Destination AS ANY _                           ' __in PVOID Destination
 , BYVAL Length AS DWORD _                              ' __in SIZE_T Length
 )                                                      ' void
#ENDIF

DECLARE SUB ZeroMemory IMPORT "KERNEL32.DLL" ALIAS "RtlZeroMemory" ( _
   BYVAL Destination AS DWORD _                         ' __in PVOID Destination
 , BYVAL Length AS DWORD _                              ' __in SIZE_T Length
 )                                                      ' void

SUB RtlSecureZeroMemory (BYVAL pDest AS DWORD, BYVAL ncBytes AS LONG)
    MEMORY FILL pDest, ncBytes, BYTE 0
END SUB

%SEF_DACL_AUTO_INHERIT             = &H01???
%SEF_SACL_AUTO_INHERIT             = &H02???
%SEF_DEFAULT_DESCRIPTOR_FOR_OBJECT = &H04???
%SEF_AVOID_PRIVILEGE_CHECK         = &H08???
%SEF_AVOID_OWNER_CHECK             = &H10???
%SEF_DEFAULT_OWNER_FROM_PARENT     = &H20???
%SEF_DEFAULT_GROUP_FROM_PARENT     = &H40???
%SEF_MACL_NO_WRITE_UP              = &H100???
%SEF_MACL_NO_READ_UP               = &H200???
%SEF_MACL_NO_EXECUTE_UP            = &H400???
%SEF_AVOID_OWNER_RESTRICTION       = &H1000???

%SEF_MACL_VALID_FLAGS              = %SEF_MACL_NO_WRITE_UP   OR _
                                     %SEF_MACL_NO_READ_UP    OR _
                                     %SEF_MACL_NO_EXECUTE_UP

' // Size = 6 bytes
TYPE MESSAGE_RESOURCE_ENTRY WORD
   Length  AS WORD   ' WORD
   Flags   AS WORD   ' WORD
   Text(0) AS BYTE   ' BYTE  Text[ 1 ]
END TYPE

%MESSAGE_RESOURCE_UNICODE = &H0001

' // Size = 12 bytes
TYPE MESSAGE_RESOURCE_BLOCK DWORD
   LowId           AS DWORD
   HighId          AS DWORD
   OffsetToEntries AS DWORD
END TYPE

' // Size = 16 bytes
TYPE MESSAGE_RESOURCE_DATA DWORD
   NumberOfBlocks AS DWORD                    ' DWORD
   Blocks(0)      AS MESSAGE_RESOURCE_BLOCK   ' MESSAGE_RESOURCE_BLOCK Blocks[ 1 ]
END TYPE

DECLARE FUNCTION RtlPcToFileHeader IMPORT "NTDLL.DLL" ALIAS "RtlPcToFileHeader" ( _
   BYVAL PcValue AS DWORD _                             ' __in PVOID PcValue
 , BYREF BaseOfImage AS DWORD _                         ' __out PVOID *BaseOfImage
 ) AS DWORD                                             ' PVOID

' // Size = 148 bytes
TYPE OSVERSIONINFOA DWORD
   dwOSVersionInfoSize AS DWORD
   dwMajorVersion      AS DWORD
   dwMinorVersion      AS DWORD
   dwBuildNumber       AS DWORD
   dwPlatformId        AS DWORD
   szCSDVersion        AS ASCIIZ * 128  ' CHAR   szCSDVersion[ 128 ];     // Maintenance string for PSS usage
END TYPE

' // Size = 276 bytes
TYPE OSVERSIONINFOW DWORD
   dwOSVersionInfoSize AS DWORD
   dwMajorVersion      AS DWORD
   dwMinorVersion      AS DWORD
   dwBuildNumber       AS DWORD
   dwPlatformId        AS DWORD
   szCSDVersion        AS WSTRINGZ * 128   ' WCHAR  szCSDVersion[ 128 ];     // Maintenance string for PSS usage
END TYPE

#IF %DEF(%UNICODE)
   MACRO OSVERSIONINFO = OSVERSIONINFOW
#ELSE
   MACRO OSVERSIONINFO = OSVERSIONINFOA
#ENDIF

' // Size = 156 bytes
TYPE OSVERSIONINFOEXA BYTE
   dwOSVersionInfoSize AS DWORD
   dwMajorVersion      AS DWORD
   dwMinorVersion      AS DWORD
   dwBuildNumber       AS DWORD
   dwPlatformId        AS DWORD
   szCSDVersion        AS ASCIIZ * 128   ' CHAR   szCSDVersion[ 128 ];     // Maintenance string for PSS usage
   wServicePackMajor   AS WORD
   wServicePackMinor   AS WORD
   wSuiteMask          AS WORD
   wProductType        AS BYTE
   wReserved           AS BYTE
END TYPE

' // Size = 284 bytes
TYPE OSVERSIONINFOEXW BYTE
   dwOSVersionInfoSize AS DWORD
   dwMajorVersion      AS DWORD
   dwMinorVersion      AS DWORD
   dwBuildNumber       AS DWORD
   dwPlatformId        AS DWORD
   szCSDVersion        AS WSTRINGZ * 128   ' WCHAR  szCSDVersion[ 128 ];     // Maintenance string for PSS usage
   wServicePackMajor   AS WORD
   wServicePackMinor   AS WORD
   wSuiteMask          AS WORD
   wProductType        AS BYTE
   wReserved           AS BYTE
END TYPE

#IF %DEF(%UNICODE)
   MACRO OSVERSIONINFOEX = OSVERSIONINFOEXW
#ELSE
   MACRO OSVERSIONINFOEX = OSVERSIONINFOEXA
#ENDIF

'//
'// RtlVerifyVersionInfo() conditions
'//

%VER_EQUAL                       = 1
%VER_GREATER                     = 2
%VER_GREATER_EQUAL               = 3
%VER_LESS                        = 4
%VER_LESS_EQUAL                  = 5
%VER_AND                         = 6
%VER_OR                          = 7

%VER_CONDITION_MASK              = 7
%VER_NUM_BITS_PER_CONDITION_MASK = 3

'//
'// RtlVerifyVersionInfo() type mask bits
'//

%VER_MINORVERSION                = &H0000001???
%VER_MAJORVERSION                = &H0000002???
%VER_BUILDNUMBER                 = &H0000004???
%VER_PLATFORMID                  = &H0000008???
%VER_SERVICEPACKMINOR            = &H0000010???
%VER_SERVICEPACKMAJOR            = &H0000020???
%VER_SUITENAME                   = &H0000040???
%VER_PRODUCT_TYPE                = &H0000080???

'//
'// RtlVerifyVersionInfo() os product type values
'//

%VER_NT_WORKSTATION              = &H0000001???
%VER_NT_DOMAIN_CONTROLLER        = &H0000002???
%VER_NT_SERVER                   = &H0000003???

'//
'// dwPlatformId defines:
'//

%VER_PLATFORM_WIN32s            = 0
%VER_PLATFORM_WIN32_WINDOWS     = 1
%VER_PLATFORM_WIN32_NT          = 2


'//
'//
'// VerifyVersionInfo() macro to set the condition mask
'//
'// For documentation sakes here's the old version of the macro that got
'// changed to call an API
'// #define VER_SET_CONDITION(_m_,_t_,_c_)  _m_=(_m_|(_c_<<(1<<_t_)))
'//

'#define VER_SET_CONDITION(_m_,_t_,_c_)  \
'        ((_m_)=VerSetConditionMask((_m_),(_t_),(_c_)))

'#if (NTDDI_VERSION >= NTDDI_WIN2K)
DECLARE FUNCTION VerSetConditionMask IMPORT "KERNEL32.DLL" ALIAS "VerSetConditionMask" ( _
   BYVAL ConditionMask AS QUAD _                        ' __in  ULONGLONG ConditionMask
 , BYVAL TypeMask AS DWORD _                            ' __in  DWORD     TypeMask
 , BYVAL Condition AS BYTE _                            ' __in  BYTE      Condition
 ) AS QUAD                                              ' ULONGLONG

MACRO VER_SET_CONDITION(m, t, c) = VerSetConditionMask(m, t, c)
'#endif

'#if (NTDDI_VERSION >= NTDDI_VISTA)
#IF %WINVER >= &H0600

DECLARE FUNCTION RtlGetProductInfo IMPORT "KERNEL32.DLL" ALIAS "RtlGetProductInfo" ( _
   BYVAL OSMajorVersion AS DWORD _                      ' __in  DWORD  OSMajorVersion
 , BYVAL OSMinorVersion AS DWORD _                      ' __in  DWORD  OSMinorVersion
 , BYVAL SpMajorVersion AS DWORD _                      ' __in  DWORD  SpMajorVersion
 , BYVAL SpMinorVersion AS DWORD _                      ' __in  DWORD  SpMinorVersion
 , BYREF ReturnedProductType AS DWORD _                 ' __out PDWORD ReturnedProductType
 ) AS BYTE                                              ' BOOLEAN

#ENDIF

%RTL_UMS_VERSION = &H0100

' enum RTL_UMS_THREAD_INFO_CLASS
%UmsThreadInvalidInfoClass = 0
%UmsThreadUserContext      = 1
%UmsThreadPriority         = 2
%UmsThreadAffinity         = 3
%UmsThreadTeb              = 4
%UmsThreadIsSuspended      = 5
%UmsThreadIsTerminated     = 6
%UmsThreadMaxInfoClass     = 7

' enum RTL_UMS_SCHEDULER_REASON
%UmsSchedulerStartup       = 0
%UmsSchedulerThreadBlocked = 1
%UmsSchedulerThreadYield   = 2

'typedef
'__drv_functionClass(RTL_UMS_SCHEDULER_ENTRY_POINT)
'VOID
'NTAPI
'RTL_UMS_SCHEDULER_ENTRY_POINT(
'    __in RTL_UMS_SCHEDULER_REASON Reason,
'    __in ULONG_PTR ActivationPayload,
'    __in PVOID SchedulerParam
'    );

'typedef RTL_UMS_SCHEDULER_ENTRY_POINT *PRTL_UMS_SCHEDULER_ENTRY_POINT;


#IF %WINVER >= &H0601
'#if (NTDDI_VERSION >= NTDDI_WIN7)

DECLARE FUNCTION RtlCopyExtendedContext IMPORT "KERNEL32.DLL" ALIAS "RtlCopyExtendedContext" ( _
   BYREF Destination AS CONTEXT_EX _                    ' __out PCONTEXT_EX Destination
 , BYVAL ContextFlags AS DWORD _                        ' __in DWORD ContextFlags
 , BYREF Source AS CONTEXT_EX _                         ' __in PCONTEXT_EX Source
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION RtlInitializeExtendedContext IMPORT "KERNEL32.DLL" ALIAS "RtlInitializeExtendedContext" ( _
   BYREF Context AS ANY _                               ' __out PVOID Context
 , BYVAL ContextFlags AS DWORD _                        ' __in DWORD ContextFlags
 , BYREF ContextEx AS CONTEXT_EX _                      ' __out PCONTEXT_EX* ContextEx
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION RtlGetEnabledExtendedFeatures IMPORT "KERNEL32.DLL" ALIAS "RtlGetEnabledExtendedFeatures" ( _
   BYVAL FeatureMask AS QUAD _                          ' __in DWORD64 FeatureMask
 ) AS QUAD                                              ' DWORD64

DECLARE FUNCTION RtlGetExtendedContextLength IMPORT "KERNEL32.DLL" ALIAS "RtlGetExtendedContextLength" ( _
   BYVAL ContextFlags AS DWORD _                        ' __in DWORD ContextFlags
 , BYREF ContextLength AS DWORD _                       ' __out PDWORD ContextLength
 ) AS DWORD                                             ' DWORD

DECLARE FUNCTION RtlGetExtendedFeaturesMask IMPORT "KERNEL32.DLL" ALIAS "RtlGetExtendedFeaturesMask" ( _
   BYREF ContextEx AS CONTEXT_EX _                      ' __in PCONTEXT_EX ContextEx
 ) AS QUAD                                              ' DWORD64

DECLARE FUNCTION RtlLocateExtendedFeature IMPORT "KERNEL32.DLL" ALIAS "RtlLocateExtendedFeature" ( _
   BYREF ContextEx AS CONTEXT_EX _                      ' __in PCONTEXT_EX ContextEx
 , BYVAL FeatureId AS DWORD _                           ' __in DWORD FeatureId
 , OPTIONAL BYREF Length AS DWORD _                     ' __out_opt PDWORD Length
 ) AS DWORD                                             ' PVOID

DECLARE FUNCTION RtlLocateLegacyContext IMPORT "KERNEL32.DLL" ALIAS "RtlLocateLegacyContext" ( _
   BYREF ContextEx AS CONTEXT_EX _                      ' __in PCONTEXT_EX ContextEx
 , OPTIONAL BYREF Length AS DWORD _                     ' __out_opt PDWORD Length
 ) AS DWORD                                             ' PCONTEXT

DECLARE SUB RtlSetExtendedFeaturesMask IMPORT "KERNEL32.DLL" ALIAS "RtlSetExtendedFeaturesMask" ( _
   BYREF ContextEx AS CONTEXT_EX _                      ' __in PCONTEXT_EX ContextEx
 , BYVAL FeatureMask AS QUAD _                          ' __in DWORD64 FeatureMask
 )                                                      ' VOID

#ENDIF

'typedef struct _RTL_CRITICAL_SECTION_DEBUG {
'    WORD   Type;
'    WORD   CreatorBackTraceIndex;
'    struct _RTL_CRITICAL_SECTION *CriticalSection;
'    LIST_ENTRY ProcessLocksList;
'    DWORD EntryCount;
'    DWORD ContentionCount;
'    DWORD Spare[ 2 ];
'} RTL_CRITICAL_SECTION_DEBUG, *PRTL_CRITICAL_SECTION_DEBUG, RTL_RESOURCE_DEBUG, *PRTL_RESOURCE_DEBUG;

UNION RTL_CRITICAL_SECTION_DEBUG_UNION WORD
   Type                  AS WORD
   ' // For compatibility with the PB declares
   nType                 AS WORD
END UNION

' // Size = 32 bytes
TYPE RTL_CRITICAL_SECTION_DEBUG DWORD FILL
   RTL_CRITICAL_SECTION_DEBUG_UNION
   CreatorBackTraceIndex     AS WORD
   CriticalSection           AS RTL_CRITICAL_SECTION_DEBUG PTR
   ProcessLocksList          AS LIST_ENTRY
   EntryCount                AS DWORD
   ContentionCount           AS DWORD
   Flags                     AS DWORD
   CreatorBackTraceIndexHigh AS WORD
   SpareWORD                 AS WORD
END TYPE

%RTL_CRITSECT_TYPE = 0
%RTL_RESOURCE_TYPE = 1

'//
'// These flags define the upper byte of the critical section SpinCount field
'//
%RTL_CRITICAL_SECTION_FLAG_NO_DEBUG_INFO         = &H01000000???
%RTL_CRITICAL_SECTION_FLAG_DYNAMIC_SPIN          = &H02000000???
%RTL_CRITICAL_SECTION_FLAG_STATIC_INIT           = &H04000000???
%RTL_CRITICAL_SECTION_ALL_FLAG_BITS              = &HFF000000???
%RTL_CRITICAL_SECTION_FLAG_RESERVED              = (%RTL_CRITICAL_SECTION_ALL_FLAG_BITS AND (NOT(%RTL_CRITICAL_SECTION_FLAG_NO_DEBUG_INFO OR %RTL_CRITICAL_SECTION_FLAG_DYNAMIC_SPIN OR %RTL_CRITICAL_SECTION_FLAG_STATIC_INIT)))

'//
'// These flags define possible values stored in the Flags field of a critsec debuginfo.
'//
%RTL_CRITICAL_SECTION_DEBUG_FLAG_STATIC_INIT     = &H00000001???

'#pragma pack(push, 8)

'typedef struct _RTL_CRITICAL_SECTION {
'    PRTL_CRITICAL_SECTION_DEBUG DebugInfo;

'    //
'    //  The following three fields control entering and exiting the critical
'    //  section for the resource
'    //

'    LONG LockCount;
'    LONG RecursionCount;
'    HANDLE OwningThread;        // from the thread's ClientId->UniqueThread
'    HANDLE LockSemaphore;
'    ULONG_PTR SpinCount;        // force size on 64-bit systems when packed
'} RTL_CRITICAL_SECTION, *PRTL_CRITICAL_SECTION;

' // Size = 24 bytes
TYPE RTL_CRITICAL_SECTION DWORD
   DebugInfo      AS RTL_CRITICAL_SECTION_DEBUG PTR
   LockCount      AS LONG
   RecursionCount AS LONG
   OwningThread   AS DWORD   ' // from the thread's ClientId->UniqueThread
   LockSemaphore  AS DWORD
   SpinCount      AS DWORD   ' // force size on 64-bit systems when packed
END TYPE

MACRO CRITICAL_SECTION = RTL_CRITICAL_SECTION

'#pragma pack(pop)

' Not in Windows 7 SDK
'typedef VOID (NTAPI * RTL_VERIFIER_DLL_LOAD_CALLBACK) (
'    PWSTR DllName,
'    PVOID DllBase,
'    SIZE_T DllSize,
'    PVOID Reserved
'    );

' Not in Windows 7 SDK
'typedef VOID (NTAPI * RTL_VERIFIER_DLL_UNLOAD_CALLBACK) (
'    PWSTR DllName,
'    PVOID DllBase,
'    SIZE_T DllSize,
'    PVOID Reserved
'    );

' Not in Windows 7 SDK
'typedef VOID (NTAPI * RTL_VERIFIER_NTDLLHEAPFREE_CALLBACK) (
'    PVOID AllocationBase,
'    SIZE_T AllocationSize
'    );

' *** Not in Windows 7 SDK ***
' // Size = 12 bytes
TYPE RTL_VERIFIER_THUNK_DESCRIPTOR DWORD
   ThunkName       AS BYTE PTR   ' PCHAR
   ThunkOldAddress AS DWORD      ' PVOID
   ThunkNewAddress AS DWORD      ' PVOID
END TYPE

' *** Not in Windows 7 SDK ***
' // Size = 16 bytes
TYPE RTL_VERIFIER_DLL_DESCRIPTOR DWORD
   DllName    AS WSTRINGZ PTR   ' PWCHAR
   DllFlags   AS DWORD          ' DWORD
   DllAddress AS DWORD          ' PVOID
   DllThunks  AS RTL_VERIFIER_THUNK_DESCRIPTOR PTR   ' PRTL_VERIFIER_THUNK_DESCRIPTOR
END TYPE

'typedef struct _RTL_VERIFIER_PROVIDER_DESCRIPTOR {

'    //
'    // Filled by verifier provider DLL
'    //

'    DWORD Length;
'    PRTL_VERIFIER_DLL_DESCRIPTOR ProviderDlls;
'    RTL_VERIFIER_DLL_LOAD_CALLBACK ProviderDllLoadCallback;
'    RTL_VERIFIER_DLL_UNLOAD_CALLBACK ProviderDllUnloadCallback;

'    //
'    // Filled by verifier engine
'    //

'    PWSTR VerifierImage;
'    DWORD VerifierFlags;
'    DWORD VerifierDebug;

'    PVOID RtlpGetStackTraceAddress;
'    PVOID RtlpDebugPageHeapCreate;
'    PVOID RtlpDebugPageHeapDestroy;

'    //
'    // Filled by verifier provider DLL
'    //

'    RTL_VERIFIER_NTDLLHEAPFREE_CALLBACK ProviderNtdllHeapFreeCallback;

'} RTL_VERIFIER_PROVIDER_DESCRIPTOR, *PRTL_VERIFIER_PROVIDER_DESCRIPTOR;

' *** Not in Windows 7 SDK ***
' // Size = 44 bytes
TYPE RTL_VERIFIER_PROVIDER_DESCRIPTOR DWORD
   Length                        AS DWORD
   ProviderDlls                  AS RTL_VERIFIER_DLL_DESCRIPTOR PTR
   ProviderDllLoadCallback       AS DWORD
   ProviderDllUnloadCallback     AS DWORD
   VerifierImage                 AS DWORD
   VerifierFlags                 AS DWORD
   VerifierDebug                 AS DWORD
   RtlpGetStackTraceAddress      AS DWORD
   RtlpDebugPageHeapCreate       AS DWORD
   RtlpDebugPageHeapDestroy      AS DWORD
   ProviderNtdllHeapFreeCallback AS DWORD
END TYPE

'//
'// Application verifier standard flags
'//
' *** Not in Windows 7 SDK ***

%RTL_VRF_FLG_FULL_PAGE_HEAP                   = &H00000001???
%RTL_VRF_FLG_RESERVED_DONOTUSE                = &H00000002??? ' // old RTL_VRF_FLG_LOCK_CHECKS
%RTL_VRF_FLG_HANDLE_CHECKS                    = &H00000004???
%RTL_VRF_FLG_STACK_CHECKS                     = &H00000008???
%RTL_VRF_FLG_APPCOMPAT_CHECKS                 = &H00000010???
%RTL_VRF_FLG_TLS_CHECKS                       = &H00000020???
%RTL_VRF_FLG_DIRTY_STACKS                     = &H00000040???
%RTL_VRF_FLG_RPC_CHECKS                       = &H00000080???
%RTL_VRF_FLG_COM_CHECKS                       = &H00000100???
%RTL_VRF_FLG_DANGEROUS_APIS                   = &H00000200???
%RTL_VRF_FLG_RACE_CHECKS                      = &H00000400???
%RTL_VRF_FLG_DEADLOCK_CHECKS                  = &H00000800???
%RTL_VRF_FLG_FIRST_CHANCE_EXCEPTION_CHECKS    = &H00001000???
%RTL_VRF_FLG_VIRTUAL_MEM_CHECKS               = &H00002000???
%RTL_VRF_FLG_ENABLE_LOGGING                   = &H00004000???
%RTL_VRF_FLG_FAST_FILL_HEAP                   = &H00008000???
%RTL_VRF_FLG_VIRTUAL_SPACE_TRACKING           = &H00010000???
%RTL_VRF_FLG_ENABLED_SYSTEM_WIDE              = &H00020000???
%RTL_VRF_FLG_MISCELLANEOUS_CHECKS             = &H00020000???
%RTL_VRF_FLG_LOCK_CHECKS                      = &H00040000???

'//
'// Application verifier standard stop codes
'//
' *** Not in Windows 7 SDK ***

%APPLICATION_VERIFIER_INTERNAL_ERROR               = &H80000000???
%APPLICATION_VERIFIER_INTERNAL_WARNING             = &H40000000???
%APPLICATION_VERIFIER_NO_BREAK                     = &H20000000???
%APPLICATION_VERIFIER_CONTINUABLE_BREAK            = &H10000000???

%APPLICATION_VERIFIER_UNKNOWN_ERROR                    = &H0001???
%APPLICATION_VERIFIER_ACCESS_VIOLATION                 = &H0002???
%APPLICATION_VERIFIER_UNSYNCHRONIZED_ACCESS            = &H0003???
%APPLICATION_VERIFIER_EXTREME_SIZE_REQUEST             = &H0004???
%APPLICATION_VERIFIER_BAD_HEAP_HANDLE                  = &H0005???
%APPLICATION_VERIFIER_SWITCHED_HEAP_HANDLE             = &H0006???
%APPLICATION_VERIFIER_DOUBLE_FREE                      = &H0007???
%APPLICATION_VERIFIER_CORRUPTED_HEAP_BLOCK             = &H0008???
%APPLICATION_VERIFIER_DESTROY_PROCESS_HEAP             = &H0009???
%APPLICATION_VERIFIER_UNEXPECTED_EXCEPTION             = &H000A???
%APPLICATION_VERIFIER_CORRUPTED_HEAP_BLOCK_EXCEPTION_RAISED_FOR_HEADER = &H000B???
%APPLICATION_VERIFIER_CORRUPTED_HEAP_BLOCK_EXCEPTION_RAISED_FOR_PROBING = &H000C???
%APPLICATION_VERIFIER_CORRUPTED_HEAP_BLOCK_HEADER      = &H000D???
%APPLICATION_VERIFIER_CORRUPTED_FREED_HEAP_BLOCK       = &H000E???
%APPLICATION_VERIFIER_CORRUPTED_HEAP_BLOCK_SUFFIX      = &H000F???
%APPLICATION_VERIFIER_CORRUPTED_HEAP_BLOCK_START_STAMP = &H0010???
%APPLICATION_VERIFIER_CORRUPTED_HEAP_BLOCK_END_STAMP   = &H0011???
%APPLICATION_VERIFIER_CORRUPTED_HEAP_BLOCK_PREFIX      = &H0012???
%APPLICATION_VERIFIER_FIRST_CHANCE_ACCESS_VIOLATION    = &H0013???
%APPLICATION_VERIFIER_CORRUPTED_HEAP_LIST              = &H0014???

%APPLICATION_VERIFIER_TERMINATE_THREAD_CALL        = &H0100???
%APPLICATION_VERIFIER_STACK_OVERFLOW               = &H0101???
%APPLICATION_VERIFIER_INVALID_EXIT_PROCESS_CALL    = &H0102???

%APPLICATION_VERIFIER_EXIT_THREAD_OWNS_LOCK        = &H0200???
%APPLICATION_VERIFIER_LOCK_IN_UNLOADED_DLL         = &H0201???
%APPLICATION_VERIFIER_LOCK_IN_FREED_HEAP           = &H0202???
%APPLICATION_VERIFIER_LOCK_DOUBLE_INITIALIZE       = &H0203???
%APPLICATION_VERIFIER_LOCK_IN_FREED_MEMORY         = &H0204???
%APPLICATION_VERIFIER_LOCK_CORRUPTED               = &H0205???
%APPLICATION_VERIFIER_LOCK_INVALID_OWNER           = &H0206???
%APPLICATION_VERIFIER_LOCK_INVALID_RECURSION_COUNT = &H0207???
%APPLICATION_VERIFIER_LOCK_INVALID_LOCK_COUNT      = &H0208???
%APPLICATION_VERIFIER_LOCK_OVER_RELEASED           = &H0209???
%APPLICATION_VERIFIER_LOCK_NOT_INITIALIZED         = &H0210???
%APPLICATION_VERIFIER_LOCK_ALREADY_INITIALIZED     = &H0211???
%APPLICATION_VERIFIER_LOCK_IN_FREED_VMEM           = &H0212???
%APPLICATION_VERIFIER_LOCK_IN_UNMAPPED_MEM         = &H0213???
%APPLICATION_VERIFIER_THREAD_NOT_LOCK_OWNER        = &H0214???

%APPLICATION_VERIFIER_INVALID_HANDLE               = &H0300???
%APPLICATION_VERIFIER_INVALID_TLS_VALUE            = &H0301???
%APPLICATION_VERIFIER_INCORRECT_WAIT_CALL          = &H0302???
%APPLICATION_VERIFIER_NULL_HANDLE                  = &H0303???
%APPLICATION_VERIFIER_WAIT_IN_DLLMAIN              = &H0304???

%APPLICATION_VERIFIER_COM_ERROR                    = &H0400???
%APPLICATION_VERIFIER_COM_API_IN_DLLMAIN           = &H0401???
%APPLICATION_VERIFIER_COM_UNHANDLED_EXCEPTION      = &H0402???
%APPLICATION_VERIFIER_COM_UNBALANCED_COINIT        = &H0403???
%APPLICATION_VERIFIER_COM_UNBALANCED_OLEINIT       = &H0404???
%APPLICATION_VERIFIER_COM_UNBALANCED_SWC           = &H0405???
%APPLICATION_VERIFIER_COM_NULL_DACL                = &H0406???
%APPLICATION_VERIFIER_COM_UNSAFE_IMPERSONATION     = &H0407???
%APPLICATION_VERIFIER_COM_SMUGGLED_WRAPPER         = &H0408???
%APPLICATION_VERIFIER_COM_SMUGGLED_PROXY           = &H0409???
%APPLICATION_VERIFIER_COM_CF_SUCCESS_WITH_NULL     = &H040A???
%APPLICATION_VERIFIER_COM_GCO_SUCCESS_WITH_NULL    = &H040B???
%APPLICATION_VERIFIER_COM_OBJECT_IN_FREED_MEMORY   = &H040C???
%APPLICATION_VERIFIER_COM_OBJECT_IN_UNLOADED_DLL   = &H040D???
%APPLICATION_VERIFIER_COM_VTBL_IN_FREED_MEMORY     = &H040E???
%APPLICATION_VERIFIER_COM_VTBL_IN_UNLOADED_DLL     = &H040F???
%APPLICATION_VERIFIER_COM_HOLDING_LOCKS_ON_CALL    = &H0410???

%APPLICATION_VERIFIER_RPC_ERROR                    = &H0500???

%APPLICATION_VERIFIER_INVALID_FREEMEM              = &H0600???
%APPLICATION_VERIFIER_INVALID_ALLOCMEM             = &H0601???
%APPLICATION_VERIFIER_INVALID_MAPVIEW              = &H0602???
%APPLICATION_VERIFIER_PROBE_INVALID_ADDRESS        = &H0603???
%APPLICATION_VERIFIER_PROBE_FREE_MEM               = &H0604???
%APPLICATION_VERIFIER_PROBE_GUARD_PAGE             = &H0605???
%APPLICATION_VERIFIER_PROBE_NULL                   = &H0606???
%APPLICATION_VERIFIER_PROBE_INVALID_START_OR_SIZE  = &H0607???
%APPLICATION_VERIFIER_SIZE_HEAP_UNEXPECTED_EXCEPTION = &H0618???


'#define VERIFIER_STOP(Code, Msg, P1, S1, P2, S2, P3, S3, P4, S4) {  \
'        RtlApplicationVerifierStop ((Code),                         \
'                                    (Msg),                          \
'                                    (ULONG_PTR)(P1),(S1),           \
'                                    (ULONG_PTR)(P2),(S2),           \
'                                    (ULONG_PTR)(P3),(S3),           \
'                                    (ULONG_PTR)(P4),(S4));          \
'  }

' *** Not in Windows 7 SDK ***
DECLARE SUB RtlApplicationVerifierStop IMPORT "NTDLL.DLL" ALIAS "RtlApplicationVerifierStop" ( _
   BYVAL Code AS DWORD _                                ' __in ULONG_PTR Code
 , BYREF Message AS ASCIIZ _                            ' __in PSTR Message
 , BYVAL Param1 AS DWORD _                              ' __in ULONG_PTR Param1
 , BYREF Description1 AS ASCIIZ _                       ' __in PSTR Description1
 , BYVAL Param2 AS DWORD _                              ' __in ULONG_PTR Param2
 , BYREF Description2 AS ASCIIZ _                       ' __in PSTR Description2
 , BYVAL Param3 AS DWORD _                              ' __in ULONG_PTR Param3
 , BYREF Description3 AS ASCIIZ _                       ' __in PSTR Description3
 , BYVAL Param4 AS DWORD _                              ' __in ULONG_PTR Param4
 , BYREF Description4 AS ASCIIZ _                       ' __in PSTR Description4
 )                                                      ' void

'typedef LONG (NTAPI *PVECTORED_EXCEPTION_HANDLER)(
'    struct _EXCEPTION_POINTERS *ExceptionInfo
'    );

UNION RTL_SRWLOCK_UNION DWORD
   Ptr AS DWORD   ' PVOID
   ' // For compatibility with the PB declares
   pPtr AS DWORD   ' PVOID
END UNION

' // Size = 4 bytes
TYPE RTL_SRWLOCK DWORD
   RTL_SRWLOCK_UNION
END TYPE
%RTL_SRWLOCK_INIT = 0

UNION RTL_CONDITION_VARIABLE_UNION DWORD
   Ptr AS DWORD   ' PVOID
   ' // For compatibility with the PB declares
   pPtr AS DWORD   ' PVOID
END UNION

' // Size = 4 bytes
TYPE RTL_CONDITION_VARIABLE DWORD
   RTL_CONDITION_VARIABLE_UNION
END TYPE

%RTL_CONDITION_VARIABLE_INIT = 0
%RTL_CONDITION_VARIABLE_LOCKMODE_SHARED = &H1

'typedef
'VOID
'(NTAPI *PAPCFUNC)(
'    __in ULONG_PTR Parameter
'    );

'typedef LONG (NTAPI *PVECTORED_EXCEPTION_HANDLER)(
'    struct _EXCEPTION_POINTERS *ExceptionInfo
'    );

' HEAP_INFORMATION_CLASS enum
%HeapCompatibilityInformation      = 0
%HeapEnableTerminationOnCorruption = 1

' Not in Windows 7 SDK
DECLARE FUNCTION RtlSetHeapInformation IMPORT "NTDLL.DLL" ALIAS "RtlSetHeapInformation" ( _
   BYVAL HeapHandle AS DWORD _                          ' __in PVOID HeapHandle
 , BYVAL HeapInformationClass AS DWORD _                ' __in HEAP_INFORMATION_CLASS HeapInformationClass
 , BYVAL HeapInformation AS DWORD _                     ' __in PVOID HeapInformation OPTIONAL
 , BYVAL HeapInformationLength AS DWORD _               ' __in SIZE_T HeapInformationLength OPTIONAL
 ) AS DWORD                                             ' DWORD

' Not in Windows 7 SDK
DECLARE FUNCTION RtlQueryHeapInformation IMPORT "NTDLL.DLL" ALIAS "RtlQueryHeapInformation" ( _
   BYVAL HeapHandle AS DWORD _                          ' __in PVOID HeapHandle
 , BYVAL HeapInformationClass AS DWORD _                ' __in HEAP_INFORMATION_CLASS HeapInformationClass
 , BYREF HeapInformation AS ANY _                       ' __out PVOID HeapInformation OPTIONAL
 , BYVAL HeapInformationLength AS DWORD _               ' __in SIZE_T HeapInformationLength OPTIONAL
 , BYREF ReturnLength AS DWORD _                        ' __out PSIZE_T ReturnLength OPTIONAL
 ) AS DWORD                                             ' DWORD

'//
'//  Multiple alloc-free APIS
'//
' Not in Windows 7 SDK

'DWORD
'NTAPI
'RtlMultipleAllocateHeap (
'    IN PVOID HeapHandle,
'    IN DWORD Flags,
'    IN SIZE_T Size,
'    IN DWORD Count,
'    OUT PVOID * Array
'    );

'DWORD
'NTAPI
'RtlMultipleFreeHeap (
'    IN PVOID HeapHandle,
'    IN DWORD Flags,
'    IN DWORD Count,
'    OUT PVOID * Array
'    );

%WT_EXECUTEDEFAULT              = &H00000000???
%WT_EXECUTEINIOTHREAD           = &H00000001???
%WT_EXECUTEINUITHREAD           = &H00000002???
%WT_EXECUTEINWAITTHREAD         = &H00000004???
%WT_EXECUTEONLYONCE             = &H00000008???
%WT_EXECUTEINTIMERTHREAD        = &H00000020???
%WT_EXECUTELONGFUNCTION         = &H00000010???
%WT_EXECUTEINPERSISTENTIOTHREAD = &H00000040???
%WT_EXECUTEINPERSISTENTTHREAD   = &H00000080???
%WT_TRANSFER_IMPERSONATION      = &H00000100???

'#define WT_SET_MAX_THREADPOOL_THREADS(Flags, Limit)  ((Flags) |= (Limit)<<16)
FUNCTION WT_SET_MAX_THREADPOOL_THREADS (BYVAL Flags AS DWORD, BYVAL Limit AS DWORD) AS DWORD
   SHIFT LEFT Limit, 16
   FUNCTION = Flags OR Limit
END FUNCTION

'typedef VOID (NTAPI * WAITORTIMERCALLBACKFUNC) (PVOID, BOOLEAN );
'typedef VOID (NTAPI * WORKERCALLBACKFUNC) (PVOID );
'typedef VOID (NTAPI * APC_CALLBACK_FUNCTION) (DWORD   , PVOID, PVOID);
'typedef
'VOID
'(NTAPI *PFLS_CALLBACK_FUNCTION) (
'    IN PVOID lpFlsData
'    );

'typedef
'BOOLEAN
'(NTAPI *PSECURE_MEMORY_CACHE_CALLBACK) (
'    __in_bcount(Range) PVOID Addr,
'    __in SIZE_T Range
'    );

%WT_EXECUTEINLONGTHREAD         = &H00000010???
%WT_EXECUTEDELETEWAIT           = &H00000008???

'ACTIVATION_CONTEXT_INFO_CLASS enum
%ActivationContextBasicInformation                       = 1
%ActivationContextDetailedInformation                    = 2
%AssemblyDetailedInformationInActivationContext          = 3
%FileInformationInAssemblyOfAssemblyInActivationContext  = 4
%RunlevelInformationInActivationContext                  = 5
%CompatibilityInformationInActivationContext             = 6
%ActivationContextManifestResourceName                   = 7
%MaxActivationContextInfoClass                           = 8

'//
'// compatibility with old names
'//
%AssemblyDetailedInformationInActivationContxt           = 3
%FileInformationInAssemblyOfAssemblyInActivationContxt   = 4

'#define ACTIVATIONCONTEXTINFOCLASS ACTIVATION_CONTEXT_INFO_CLASS

' // Size = 8 bytes
TYPE ACTIVATION_CONTEXT_QUERY_INDEX DWORD
   ulAssemblyIndex       AS DWORD
   ulFileIndexInAssembly AS DWORD
END TYPE

%ACTIVATION_CONTEXT_PATH_TYPE_NONE        = 1
%ACTIVATION_CONTEXT_PATH_TYPE_WIN32_FILE  = 2
%ACTIVATION_CONTEXT_PATH_TYPE_URL         = 3
%ACTIVATION_CONTEXT_PATH_TYPE_ASSEMBLYREF = 4

' // Size = 20 bytes
TYPE ASSEMBLY_FILE_DETAILED_INFORMATION DWORD
   ulFlags          AS DWORD          ' DWORD
   ulFilenameLength AS DWORD          ' DWORD
   ulPathLength     AS DWORD          ' DWORD
   lpFileName       AS WSTRINGZ PTR   ' PCWSTR
   lpFilePath       AS WSTRINGZ PTR   ' PCWSTR
END TYPE

'//
'// compatibility with old names
'// The new names use "file" consistently.
'//
'#define  _ASSEMBLY_DLL_REDIRECTION_DETAILED_INFORMATION  _ASSEMBLY_FILE_DETAILED_INFORMATION
'#define   ASSEMBLY_DLL_REDIRECTION_DETAILED_INFORMATION   ASSEMBLY_FILE_DETAILED_INFORMATION
'#define  PASSEMBLY_DLL_REDIRECTION_DETAILED_INFORMATION  PASSEMBLY_FILE_DETAILED_INFORMATION
'#define PCASSEMBLY_DLL_REDIRECTION_DETAILED_INFORMATION PCASSEMBLY_FILE_DETAILED_INFORMATION

'typedef struct _ACTIVATION_CONTEXT_ASSEMBLY_DETAILED_INFORMATION {
'    DWORD ulFlags;
'    DWORD ulEncodedAssemblyIdentityLength;      // in bytes
'    DWORD ulManifestPathType;                   // ACTIVATION_CONTEXT_PATH_TYPE_*
'    DWORD ulManifestPathLength;                 // in bytes
'    LARGE_INTEGER liManifestLastWriteTime;      // FILETIME
'    DWORD ulPolicyPathType;                     // ACTIVATION_CONTEXT_PATH_TYPE_*
'    DWORD ulPolicyPathLength;                   // in bytes
'    LARGE_INTEGER liPolicyLastWriteTime;        // FILETIME
'    DWORD ulMetadataSatelliteRosterIndex;

'    DWORD ulManifestVersionMajor;               // 1
'    DWORD ulManifestVersionMinor;               // 0
'    DWORD ulPolicyVersionMajor;                 // 0
'    DWORD ulPolicyVersionMinor;                 // 0
'    DWORD ulAssemblyDirectoryNameLength;        // in bytes

'    PCWSTR lpAssemblyEncodedAssemblyIdentity;
'    PCWSTR lpAssemblyManifestPath;
'    PCWSTR lpAssemblyPolicyPath;
'    PCWSTR lpAssemblyDirectoryName;

'    DWORD  ulFileCount;
'} ACTIVATION_CONTEXT_ASSEMBLY_DETAILED_INFORMATION, * PACTIVATION_CONTEXT_ASSEMBLY_DETAILED_INFORMATION;

'typedef %struct _ACTIVATION_CONTEXT_ASSEMBLY_DETAILED_INFORMATION * PCACTIVATION_CONTEXT_ASSEMBLY_DETAILED_INFORMATION ;

' // Size = 88 bytes
TYPE ACTIVATION_CONTEXT_ASSEMBLY_DETAILED_INFORMATION   ' Must be 8 byte aligned
   ulFlags                           AS DWORD           ' DWORD
   ulEncodedAssemblyIdentityLength   AS DWORD           ' DWORD // in bytes
   ulManifestPathType                AS DWORD           ' DWORD // ACTIVATION_CONTEXT_PATH_TYPE_*
   ulManifestPathLength              AS DWORD           ' DWORD // in bytes
   liManifestLastWriteTime           AS QUAD            ' LARGE_INTEGER // FILETIME
   ulPolicyPathType                  AS DWORD           ' DWORD // ACTIVATION_CONTEXT_PATH_TYPE_*
   ulPolicyPathLength                AS DWORD           ' DWORD // in bytes
   liPolicyLastWriteTime             AS QUAD            ' LARGE_INTEGER // FILETIME
   ulMetadataSatelliteRosterIndex    AS DWORD           ' DWORD
   ulManifestVersionMajor            AS DWORD           ' DWORD // 1
   ulManifestVersionMinor            AS DWORD           ' DWORD // 0
   ulPolicyVersionMajor              AS DWORD           ' DWORD // 0
   ulPolicyVersionMinor              AS DWORD           ' DWORD // 0
   ulAssemblyDirectoryNameLength     AS DWORD           ' DWORD // in bytes
   lpAssemblyEncodedAssemblyIdentity AS WSTRINGZ PTR    ' PCWSTR
   lpAssemblyManifestPath            AS WSTRINGZ PTR    ' PCWSTR
   lpAssemblyPolicyPath              AS WSTRINGZ PTR    ' PCWSTR
   lpAssemblyDirectoryName           AS WSTRINGZ PTR    ' PCWSTR
   ulFileCount                       AS DWORD           ' DWORD
   alignment__                       AS DWORD           ' // To keep 8 byte alignment
END TYPE

' enum ACTCTX_REQUESTED_RUN_LEVEL
%ACTCTX_RUN_LEVEL_UNSPECIFIED       = 0
%ACTCTX_RUN_LEVEL_AS_INVOKER        = 1
%ACTCTX_RUN_LEVEL_HIGHEST_AVAILABLE = 2
%ACTCTX_RUN_LEVEL_REQUIRE_ADMIN     = 3
%ACTCTX_RUN_LEVEL_NUMBERS           = 4

' // Size = 12 bytes
TYPE ACTIVATION_CONTEXT_RUN_LEVEL_INFORMATION DWORD
   ulFlags  AS DWORD   ' DWORD
   RunLevel AS DWORD   ' ACTCTX_REQUESTED_RUN_LEVEL
   UiAccess AS DWORD   ' DWORD
END TYPE

' enum ACTCTX_COMPATIBILITY_ELEMENT_TYPE
%ACTCTX_COMPATIBILITY_ELEMENT_TYPE_UNKNOWN    = 0
%ACTCTX_COMPATIBILITY_ELEMENT_TYPE_OS         = 1
%ACTCTX_COMPATIBILITY_ELEMENT_TYPE_MITIGATION = 2

' // Size = 20 bytes
TYPE COMPATIBILITY_CONTEXT_ELEMENT DWORD
   Id   AS GUID
   Type AS LONG   ' ACTCTX_COMPATIBILITY_ELEMENT_TYPE
END TYPE

'#pragma warning(push)
'#pragma warning(disable:4200)

' // Size = 4 bytes
TYPE ACTIVATION_CONTEXT_COMPATIBILITY_INFORMATION DWORD
   ElementCount AS DWORD
   'Elements()  AS COMPATIBILITY_CONTEXT_ELEMENT
END TYPE

'#pragma warning(pop)

%MAX_SUPPORTED_OS_NUM = 4
%INVALID_OS_COUNT     = &Hffff??

' // Size = 12 bytes
TYPE SUPPORTED_OS_INFO WORD
   OsCount                           AS WORD
   MitigationExist                   AS WORD
   OsList(%MAX_SUPPORTED_OS_NUM - 1) AS WORD
END TYPE

' // Size = 48 bytes
TYPE ACTIVATION_CONTEXT_DETAILED_INFORMATION DWORD
   dwFlags                      AS DWORD          ' DWORD
   ulFormatVersion              AS DWORD          ' DWORD
   ulAssemblyCount              AS DWORD          ' DWORD
   ulRootManifestPathType       AS DWORD          ' DWORD
   ulRootManifestPathChars      AS DWORD          ' DWORD
   ulRootConfigurationPathType  AS DWORD          ' DWORD
   ulRootConfigurationPathChars AS DWORD          ' DWORD
   ulAppDirPathType             AS DWORD          ' DWORD
   ulAppDirPathChars            AS DWORD          ' DWORD
   lpRootManifestPath           AS WSTRINGZ PTR   ' PCWSTR
   lpRootConfigurationPath      AS WSTRINGZ PTR   ' PCWSTR
   lpAppDirPath                 AS WSTRINGZ PTR   ' PCWSTR
END TYPE

' // Size = 16 bytes
TYPE HARDWARE_COUNTER_DATA   ' Must be 8 byte aligned
   Type     AS LONG    ' HARDWARE_COUNTER_TYPE
   Reserved AS DWORD   ' DWORD
   Value    AS QUAD    ' DWORD64
END TYPE

%PERFORMANCE_DATA_VERSION = 1

' // Size = 288 bytes
TYPE PERFORMANCE_DATA   ' Must be 8 byte aligned
   Size               AS WORD    ' WORD
   Version            AS BYTE    ' BYTE
   HwCountersCount    AS BYTE    ' BYTE
   ContextSwitchCount AS DWORD   ' DWORD
   WaitReasonBitMap   AS QUAD    ' DWORD64
   CycleTime          AS QUAD    ' DWORD64
   RetryCount         AS DWORD   ' DWORD
   Reserved           AS DWORD   ' DWORD
   HwCounters(%MAX_HW_COUNTERS - 1) AS HARDWARE_COUNTER_DATA
END TYPE

%READ_THREAD_PROFILING_FLAG_DISPATCHING        = &H00000001???
%READ_THREAD_PROFILING_FLAG_HARDWARE_COUNTERS  = &H00000002???

%DLL_PROCESS_ATTACH   = 1
%DLL_THREAD_ATTACH    = 2
%DLL_THREAD_DETACH    = 3
%DLL_PROCESS_DETACH   = 0
%DLL_PROCESS_VERIFIER = 4

'//
'// Defines for the READ flags for Eventlogging
'//
%EVENTLOG_SEQUENTIAL_READ = &H0001???
%EVENTLOG_SEEK_READ       = &H0002???
%EVENTLOG_FORWARDS_READ   = &H0004???
%EVENTLOG_BACKWARDS_READ  = &H0008???

'//
'// The types of events that can be logged.
'//
%EVENTLOG_SUCCESS               = &H0000???
%EVENTLOG_ERROR_TYPE            = &H0001???
%EVENTLOG_WARNING_TYPE          = &H0002???
%EVENTLOG_INFORMATION_TYPE      = &H0004???
%EVENTLOG_AUDIT_SUCCESS         = &H0008???
%EVENTLOG_AUDIT_FAILURE         = &H0010???

'//
'// Defines for the WRITE flags used by Auditing for paired events
'// These are not implemented in Product 1
'//

%EVENTLOG_START_PAIRED_EVENT    = &H0001???
%EVENTLOG_END_PAIRED_EVENT      = &H0002???
%EVENTLOG_END_ALL_PAIRED_EVENTS = &H0004???
%EVENTLOG_PAIRED_EVENT_ACTIVE   = &H0008???
%EVENTLOG_PAIRED_EVENT_INACTIVE = &H0010???

'//
'// Structure that defines the header of the Eventlog record. This is the
'// fixed-sized portion before all the variable-length strings, binary
'// data and pad bytes.
'//
'// TimeGenerated is the time it was generated at the client.
'// TimeWritten is the time it was put into the log at the server end.
'//

'typedef struct _EVENTLOGRECORD {
'    DWORD  Length;        // Length of full record
'    DWORD  Reserved;      // Used by the service
'    DWORD  RecordNumber;  // Absolute record number
'    DWORD  TimeGenerated; // Seconds since 1-1-1970
'    DWORD  TimeWritten;   // Seconds since 1-1-1970
'    DWORD  EventID;
'    WORD   EventType;
'    WORD   NumStrings;
'    WORD   EventCategory;
'    WORD   ReservedFlags; // For use with paired events (auditing)
'    DWORD  ClosingRecordNumber; // For use with paired events (auditing)
'    DWORD  StringOffset;  // Offset from beginning of record
'    DWORD  UserSidLength;
'    DWORD  UserSidOffset;
'    DWORD  DataLength;
'    DWORD  DataOffset;    // Offset from beginning of record
'    //
'    // Then follow:
'    //
'    // WCHAR SourceName[]
'    // WCHAR Computername[]
'    // SID   UserSid
'    // WCHAR Strings[]
'    // BYTE  Data[]
'    // CHAR  Pad[]
'    // DWORD Length;
'    //
'} EVENTLOGRECORD, *PEVENTLOGRECORD;

' // Size = 56 bytes
TYPE EVENTLOGRECORD DWORD FILL
   Length              AS DWORD   ' Length of full record
   Reserved            AS DWORD   ' Used by the service
   RecordNumber        AS DWORD   ' Absolute record number
   TimeGenerated       AS DWORD   ' Seconds since 1-1-1970
   TimeWritten         AS DWORD   ' Seconds since 1-1-1970
   EventID             AS DWORD
   EventType           AS WORD
   NumStrings          AS WORD
   EventCategory       AS WORD
   ReservedFlags       AS WORD    ' For use with paired events (auditing)
   ClosingRecordNumber AS DWORD   ' For use with paired events (auditing)
   StringOffset        AS DWORD   ' Offset from beginning of record
   UserSidLength       AS DWORD
   UserSidOffset       AS DWORD
   DataLength          AS DWORD
   DataOffset          AS DWORD   ' Offset from beginning of record
   '
   ' Then follow:
   '
   ' WCHAR SourceName[]
   ' WCHAR Computername[]
   ' SID   UserSid
   ' WCHAR Strings[]
   ' BYTE  Data[]
   ' CHAR  Pad[]
   ' DWORD Length;
END TYPE

'//SS: start of changes to support clustering
'//SS: ideally the
%MAXLOGICALLOGNAMESIZE = 256

'#if _MSC_VER >= 1200
'#pragma warning(push)
'#endif
'#pragma warning(disable : 4200) /* nonstandard extension used : zero-sized array in struct/union */

'struct _EVENTSFORLOGFILE;
'typedef struct _EVENTSFORLOGFILE EVENTSFORLOGFILE, *PEVENTSFORLOGFILE;

'struct _PACKEDEVENTINFO;
'typedef struct _PACKEDEVENTINFO PACKEDEVENTINFO, *PPACKEDEVENTINFO;

'#if defined(_MSC_EXTENSIONS)

'struct _EVENTSFORLOGFILE
'{
'    DWORD           ulSize;
'    WCHAR           szLogicalLogFile[MAXLOGICALLOGNAMESIZE];        //name of the logical file-security/application/system
'    DWORD           ulNumRecords;
'    EVENTLOGRECORD  pEventLogRecords[];
'};

' // Size = 520 bytes
TYPE EVENTSFORLOGFILE
   ulSize AS DWORD
   szLogicalLogFile AS WSTRINGZ * %MAXLOGICALLOGNAMESIZE  ' //name of the logical file-security/application/system
   ulNumRecords AS DWORD
   'pEventLogRecords() AS EVENTLOGRECORD
END TYPE

'struct _PACKEDEVENTINFO
'{
'    DWORD               ulSize;  //total size of the structure
'    DWORD               ulNumEventsForLogFile; //number of EventsForLogFile structure that follow
'    DWORD               ulOffsets[];           //the offsets from the start of this structure to the EVENTSFORLOGFILE structure
'};

' // Size = 8 bytes
TYPE PACKEDEVENTINFO DWORD
   ulSize                AS DWORD   ' //total size of the structure
   ulNumEventsForLogFile AS DWORD   ' //number of EventsForLogFile structure that follow
   'ulOffsets()           AS DWORD   ' //the offsets from the start of this structure to the EVENTSFORLOGFILE structure
END TYPE

'#if _MSC_VER >= 1200
'#pragma warning(pop)
'#else
'#pragma warning(default : 4200) /* nonstandard extension used : zero-sized array in struct/union */
'#endif
'//SS: end of changes to support clustering
'//

'//
'// Registry Specific Access Rights.
'//

%KEY_QUERY_VALUE         = &H0001???
%KEY_SET_VALUE           = &H0002???
%KEY_CREATE_SUB_KEY      = &H0004???
%KEY_ENUMERATE_SUB_KEYS  = &H0008???
%KEY_NOTIFY              = &H0010???
%KEY_CREATE_LINK         = &H0020???
%KEY_WOW64_32KEY         = &H0200???
%KEY_WOW64_64KEY         = &H0100???
%KEY_WOW64_RES           = &H0300???

%KEY_READ               = %STANDARD_RIGHTS_READ OR %KEY_QUERY_VALUE OR %KEY_ENUMERATE_SUB_KEYS OR %KEY_NOTIFY AND (NOT %SYNCHRONIZE)
%KEY_WRITE              = %STANDARD_RIGHTS_WRITE OR %KEY_SET_VALUE OR %KEY_CREATE_SUB_KEY AND (NOT %SYNCHRONIZE)
%KEY_EXECUTE            = %KEY_READ
%KEY_ALL_ACCESS         = %STANDARD_RIGHTS_ALL OR %KEY_QUERY_VALUE OR %KEY_SET_VALUE OR %KEY_CREATE_SUB_KEY OR %KEY_ENUMERATE_SUB_KEYS OR %KEY_NOTIFY OR %KEY_CREATE_LINK AND (NOT %SYNCHRONIZE)

'//
'// Open/Create Options
'//

%REG_OPTION_RESERVED             = &H00000000???     ' Parameter is reserved
%REG_OPTION_NON_VOLATILE         = &H00000000???     ' Key is preserved when system is rebooted
%REG_OPTION_VOLATILE             = &H00000001???     ' Key is not preserved when system is rebooted
%REG_OPTION_CREATE_LINK          = &H00000002???     ' Created key is a symbolic link
%REG_OPTION_BACKUP_RESTORE       = &H00000004???     ' open for backup or restore
%REG_OPTION_OPEN_LINK            = &H00000008???     ' Open symbolic link

%REG_LEGAL_OPTION                = %REG_OPTION_RESERVED OR %REG_OPTION_NON_VOLATILE OR %REG_OPTION_VOLATILE OR %REG_OPTION_CREATE_LINK OR %REG_OPTION_BACKUP_RESTORE OR %REG_OPTION_OPEN_LINK

%REG_OPEN_LEGAL_OPTION           = %REG_OPTION_RESERVED OR %REG_OPTION_BACKUP_RESTORE OR %REG_OPTION_OPEN_LINK


'//
'// Key creation/open disposition
'//

%REG_CREATED_NEW_KEY          = &H00000001???     ' New Registry Key created
%REG_OPENED_EXISTING_KEY      = &H00000002???     ' Existing Key opened

'//
'// hive format to be used by Reg(Nt)SaveKeyEx
'//
%REG_STANDARD_FORMAT    = 1
%REG_LATEST_FORMAT      = 2
%REG_NO_COMPRESSION     = 4

'//
'// Key restore flags
'//

%REG_WHOLE_HIVE_VOLATILE      = &H00000001???   ' // Restore whole hive volatile
%REG_REFRESH_HIVE             = &H00000002???   ' // Unwind changes to last flush
%REG_NO_LAZY_FLUSH            = &H00000004???   ' // Never lazy flush this hive
%REG_FORCE_RESTORE            = &H00000008???   ' // Force the restore process even when we have open handles on subkeys
%REG_APP_HIVE                 = &H00000010???   ' // Loads the hive visible to the calling process
%REG_PROCESS_PRIVATE          = &H00000020???   ' // Hive cannot be mounted by any other process while in use
%REG_START_JOURNAL            = &H00000040???   ' // Starts Hive Journal
%REG_HIVE_EXACT_FILE_GROWTH   = &H00000080???   ' // Grow hive file in exact 4k increments
%REG_HIVE_NO_RM               = &H00000100???   ' // No RM is started for this hive (no transactions)
%REG_HIVE_SINGLE_LOG          = &H00000200???   ' // Legacy single logging is used for this hive
%REG_BOOT_HIVE                = &H00000400???   ' // This hive might be used by the OS loader

'//
'// Unload Flags
'//
%REG_FORCE_UNLOAD             = 1

'//
'// Notify filter values
'//
%REG_NOTIFY_CHANGE_NAME          = &H00000001???     ' Create or delete (child)
%REG_NOTIFY_CHANGE_ATTRIBUTES    = &H00000002???
%REG_NOTIFY_CHANGE_LAST_SET      = &H00000004???     ' Time stamp
%REG_NOTIFY_CHANGE_SECURITY      = &H00000008???

%REG_LEGAL_CHANGE_FILTER         = %REG_NOTIFY_CHANGE_NAME OR %REG_NOTIFY_CHANGE_ATTRIBUTES OR %REG_NOTIFY_CHANGE_LAST_SET OR %REG_NOTIFY_CHANGE_SECURITY

'//
'//
'// Predefined Value Types.
'//

%REG_NONE                        = 0     ' No value type
%REG_SZ                          = 1     ' Unicode nul terminated string
%REG_EXPAND_SZ                   = 2     ' Unicode nul terminated string
%REG_BINARY                      = 3     ' Free form binary
%REG_DWORD                       = 4     ' 32-bit number
%REG_DWORD_LITTLE_ENDIAN         = 4     ' 32-bit number (same as MACRO REG_DWORD)
%REG_DWORD_BIG_ENDIAN            = 5     ' 32-bit number
%REG_LINK                        = 6     ' Symbolic Link (unicode)
%REG_MULTI_SZ                    = 7     ' Multiple Unicode strings
%REG_RESOURCE_LIST               = 8     ' Resource list in the resource map
%REG_FULL_RESOURCE_DESCRIPTOR    = 9     ' Resource list in the hardware description
%REG_RESOURCE_REQUIREMENTS_LIST  = 10
%REG_QWORD                       = 11    ' 64-bit number
%REG_QWORD_LITTLE_ENDIAN         = 11    ' 64-bit number (same as MACRO REG_QWORD)

'//
'// Service Types (Bit Mask)
'//
%SERVICE_KERNEL_DRIVER        = &H00000001???
%SERVICE_FILE_SYSTEM_DRIVER   = &H00000002???
%SERVICE_ADAPTER              = &H00000004???
%SERVICE_RECOGNIZER_DRIVER    = &H00000008???

%SERVICE_DRIVER = %SERVICE_KERNEL_DRIVER OR %SERVICE_FILE_SYSTEM_DRIVER OR %SERVICE_RECOGNIZER_DRIVER

%SERVICE_WIN32_OWN_PROCESS    = &H00000010???
%SERVICE_WIN32_SHARE_PROCESS  = &H00000020???
%SERVICE_WIN32 = %SERVICE_WIN32_OWN_PROCESS OR %SERVICE_WIN32_SHARE_PROCESS

%SERVICE_INTERACTIVE_PROCESS  = &H00000100???

%SERVICE_TYPE_ALL = %SERVICE_WIN32 OR %SERVICE_ADAPTER OR %SERVICE_DRIVER OR %SERVICE_INTERACTIVE_PROCESS

'//
'// Start Type
'//

%SERVICE_BOOT_START     = &H00000000???
%SERVICE_SYSTEM_START   = &H00000001???
%SERVICE_AUTO_START     = &H00000002???
%SERVICE_DEMAND_START   = &H00000003???
%SERVICE_DISABLED       = &H00000004???

'//
'// Error control type
'//
%SERVICE_ERROR_IGNORE   = &H00000000???
%SERVICE_ERROR_NORMAL   = &H00000001???
%SERVICE_ERROR_SEVERE   = &H00000002???
%SERVICE_ERROR_CRITICAL = &H00000003???

'//
'//
'// Define the registry driver node enumerations
'//

' SERVICE_NODE_TYPE enum
%DriverType               = %SERVICE_KERNEL_DRIVER
%FileSystemType           = %SERVICE_FILE_SYSTEM_DRIVER
%Win32ServiceOwnProcess   = %SERVICE_WIN32_OWN_PROCESS
%Win32ServiceShareProcess = %SERVICE_WIN32_SHARE_PROCESS
%AdapterType              = %SERVICE_ADAPTER
%RecognizerType           = %SERVICE_RECOGNIZER_DRIVER

' SERVICE_LOAD_TYPE enum
%BootLoad    = %SERVICE_BOOT_START
%SystemLoad  = %SERVICE_SYSTEM_START
%AutoLoad    = %SERVICE_AUTO_START
%DemandLoad  = %SERVICE_DEMAND_START
%DisableLoad = %SERVICE_DISABLED

' SERVICE_ERROR_TYPE enum
%IgnoreError   = %SERVICE_ERROR_IGNORE
%NormalError   = %SERVICE_ERROR_NORMAL
%SevereError   = %SERVICE_ERROR_SEVERE
%CriticalError = %SERVICE_ERROR_CRITICAL

'//
'// Service node Flags. These flags are used by the OS loader to promote
'// a driver's start type to boot start if the system is booting using
'// the specified mechanism. The flags should be set in the driver's
'// registry configuration.
'//
'// CM_SERVICE_NETWORK_BOOT_LOAD - Specified if a driver should be
'// promoted on network boot.
'//
'// CM_SERVICE_VIRTUAL_DISK_BOOT_LOAD - Specified if a driver should be
'// promoted on booting from a VHD.
'//
'// CM_SERVICE_USB_DISK_BOOT_LOAD - Specified if a driver should be promoted
'// while booting from a USB disk.
'//

%CM_SERVICE_NETWORK_BOOT_LOAD      = &H00000001???
%CM_SERVICE_VIRTUAL_DISK_BOOT_LOAD = &H00000002???
%CM_SERVICE_USB_DISK_BOOT_LOAD     = &H00000004???

'//
'// Mask defining the legal promotion flag values.
'//

%CM_SERVICE_VALID_PROMOTION_MASK = %CM_SERVICE_NETWORK_BOOT_LOAD OR _
                                   %CM_SERVICE_VIRTUAL_DISK_BOOT_LOAD OR _
                                   %CM_SERVICE_USB_DISK_BOOT_LOAD

'//
'// IOCTL_TAPE_ERASE definitions
'//

%TAPE_ERASE_SHORT           = 0???
%TAPE_ERASE_LONG            = 1???

UNION TAPE_ERASE_TYPE_UNION DWORD
   Type      AS DWORD   ' DWORD
   ' // For compatibility with the PB declares
   dType     AS DWORD   ' DWORD
END UNION

' // Size = 8 bytes
TYPE TAPE_ERASE DWORD
   TAPE_ERASE_TYPE_UNION
   Immediate AS BYTE    ' BOOLEAN
END TYPE

'//
'// IOCTL_TAPE_PREPARE definitions
'//

%TAPE_LOAD                  = 0???
%TAPE_UNLOAD                = 1???
%TAPE_TENSION               = 2???
%TAPE_LOCK                  = 3???
%TAPE_UNLOCK                = 4???
%TAPE_FORMAT                = 5???

' // Size = 8 bytes
TYPE TAPE_PREPARE DWORD
   Operation AS DWORD   ' DWORD
   Immediate AS BYTE    ' BOOLEAN
END TYPE

'//
'// IOCTL_TAPE_WRITE_MARKS definitions
'//

%TAPE_SETMARKS              = 0???
%TAPE_FILEMARKS             = 1???
%TAPE_SHORT_FILEMARKS       = 2???
%TAPE_LONG_FILEMARKS        = 3???

UNION TAPE_WRITE_MARKS_UNION DWORD
   Type      AS DWORD   ' DWORD
   ' // For compatibility with the PB declares
   dType     AS DWORD   ' DWORD
END UNION

' // Size = 12 bytes
TYPE TAPE_WRITE_MARKS DWORD
   TAPE_WRITE_MARKS_UNION
   Count     AS DWORD   ' DWORD
   Immediate AS BYTE    ' BOOLEAN
END TYPE

'//
'// IOCTL_TAPE_GET_POSITION definitions
'//

%TAPE_ABSOLUTE_POSITION       = 0???
%TAPE_LOGICAL_POSITION        = 1???
%TAPE_PSEUDO_LOGICAL_POSITION = 2???

UNION TAPE_GET_POSITION_UNION DWORD
   Type      AS DWORD   ' DWORD
   ' // For compatibility with the PB declares
   dType     AS DWORD   ' DWORD
END UNION

' // Size = 16 bytes
TYPE TAPE_GET_POSITION   ' Must be 8 byte aligned
   TAPE_GET_POSITION_UNION
   Partition AS DWORD   ' DWORD
   Offset    AS QUAD    ' LARGE_INTEGER
END TYPE

'//
'// IOCTL_TAPE_SET_POSITION definitions
'//

%TAPE_REWIND                 = 0???
%TAPE_ABSOLUTE_BLOCK         = 1???
%TAPE_LOGICAL_BLOCK          = 2???
%TAPE_PSEUDO_LOGICAL_BLOCK   = 3???
%TAPE_SPACE_END_OF_DATA      = 4???
%TAPE_SPACE_RELATIVE_BLOCKS  = 5???
%TAPE_SPACE_FILEMARKS        = 6???
%TAPE_SPACE_SEQUENTIAL_FMKS  = 7???
%TAPE_SPACE_SETMARKS         = 8???
%TAPE_SPACE_SEQUENTIAL_SMKS  = 9???

UNION TAPE_SET_POSITION_METHOD_UNION DWORD
   Method         AS DWORD   ' DWORD
   dMethod        AS DWORD   ' DWORD
END UNION

' // Size = 24 bytes
TYPE TAPE_SET_POSITION   ' Must be 8 byte aligned
   TAPE_SET_POSITION_METHOD_UNION
   Partition      AS DWORD   ' DWORD
   Offset         AS QUAD    ' LARGE_INTEGER
   Immediate      AS BYTE    ' BOOLEAN
   alignment__(6) AS BYTE    ' // To keep 8 byte alignment
END TYPE

'//
'// IOCTL_TAPE_GET_DRIVE_PARAMS definitions
'//

'//
'// Definitions for FeaturesLow parameter
'//

%TAPE_DRIVE_FIXED            = &H00000001???
%TAPE_DRIVE_SELECT           = &H00000002???
%TAPE_DRIVE_INITIATOR        = &H00000004???

%TAPE_DRIVE_ERASE_SHORT      = &H00000010???
%TAPE_DRIVE_ERASE_LONG       = &H00000020???
%TAPE_DRIVE_ERASE_BOP_ONLY   = &H00000040???
%TAPE_DRIVE_ERASE_IMMEDIATE  = &H00000080???

%TAPE_DRIVE_TAPE_CAPACITY    = &H00000100???
%TAPE_DRIVE_TAPE_REMAINING   = &H00000200???
%TAPE_DRIVE_FIXED_BLOCK      = &H00000400???
%TAPE_DRIVE_VARIABLE_BLOCK   = &H00000800???

%TAPE_DRIVE_WRITE_PROTECT    = &H00001000???
%TAPE_DRIVE_EOT_WZ_SIZE      = &H00002000???

%TAPE_DRIVE_ECC              = &H00010000???
%TAPE_DRIVE_COMPRESSION      = &H00020000???
%TAPE_DRIVE_PADDING          = &H00040000???
%TAPE_DRIVE_REPORT_SMKS      = &H00080000???

%TAPE_DRIVE_GET_ABSOLUTE_BLK = &H00100000???
%TAPE_DRIVE_GET_LOGICAL_BLK  = &H00200000???
%TAPE_DRIVE_SET_EOT_WZ_SIZE  = &H00400000???

%TAPE_DRIVE_EJECT_MEDIA      = &H01000000???
%TAPE_DRIVE_CLEAN_REQUESTS   = &H02000000???
%TAPE_DRIVE_SET_CMP_BOP_ONLY = &H04000000???

%TAPE_DRIVE_RESERVED_BIT     = &H80000000???   ' //don't use this bit!
'//                                              //can't be a low features bit!
'//                                              //reserved; high features only


'//
'// Definitions for FeaturesHigh parameter
'//

%TAPE_DRIVE_LOAD_UNLOAD      = &H80000001???
%TAPE_DRIVE_TENSION          = &H80000002???
%TAPE_DRIVE_LOCK_UNLOCK      = &H80000004???
%TAPE_DRIVE_REWIND_IMMEDIATE = &H80000008???

%TAPE_DRIVE_SET_BLOCK_SIZE   = &H80000010???
%TAPE_DRIVE_LOAD_UNLD_IMMED  = &H80000020???
%TAPE_DRIVE_TENSION_IMMED    = &H80000040???
%TAPE_DRIVE_LOCK_UNLK_IMMED  = &H80000080???

%TAPE_DRIVE_SET_ECC          = &H80000100???
%TAPE_DRIVE_SET_COMPRESSION  = &H80000200???
%TAPE_DRIVE_SET_PADDING      = &H80000400???
%TAPE_DRIVE_SET_REPORT_SMKS  = &H80000800???

%TAPE_DRIVE_ABSOLUTE_BLK     = &H80001000???
%TAPE_DRIVE_ABS_BLK_IMMED    = &H80002000???
%TAPE_DRIVE_LOGICAL_BLK      = &H80004000???
%TAPE_DRIVE_LOG_BLK_IMMED    = &H80008000???

%TAPE_DRIVE_END_OF_DATA      = &H80010000???
%TAPE_DRIVE_RELATIVE_BLKS    = &H80020000???
%TAPE_DRIVE_FILEMARKS        = &H80040000???
%TAPE_DRIVE_SEQUENTIAL_FMKS  = &H80080000???

%TAPE_DRIVE_SETMARKS         = &H80100000???
%TAPE_DRIVE_SEQUENTIAL_SMKS  = &H80200000???
%TAPE_DRIVE_REVERSE_POSITION = &H80400000???
%TAPE_DRIVE_SPACE_IMMEDIATE  = &H80800000???

%TAPE_DRIVE_WRITE_SETMARKS   = &H81000000???
%TAPE_DRIVE_WRITE_FILEMARKS  = &H82000000???
%TAPE_DRIVE_WRITE_SHORT_FMKS = &H84000000???
%TAPE_DRIVE_WRITE_LONG_FMKS  = &H88000000???

%TAPE_DRIVE_WRITE_MARK_IMMED = &H90000000???
%TAPE_DRIVE_FORMAT           = &HA0000000???
%TAPE_DRIVE_FORMAT_IMMEDIATE = &HC0000000???
%TAPE_DRIVE_HIGH_FEATURES    = &H80000000???  ' //mask for high features flag

' // Size = 32 bytes
TYPE TAPE_GET_DRIVE_PARAMETERS DWORD FILL
   ECC                   AS BYTE    ' BOOLEAN
   Compression           AS BYTE    ' BOOLEAN
   DataPadding           AS BYTE    ' BOOLEAN
   ReportSetmarks        AS BYTE    ' BOOLEAN
   DefaultBlockSize      AS DWORD   ' DWORD
   MaximumBlockSize      AS DWORD   ' DWORD
   MinimumBlockSize      AS DWORD   ' DWORD
   MaximumPartitionCount AS DWORD   ' DWORD
   FeaturesLow           AS DWORD   ' DWORD
   FeaturesHigh          AS DWORD   ' DWORD
   EOTWarningZoneSize    AS DWORD   ' DWORD
END TYPE

'//
'// IOCTL_TAPE_SET_DRIVE_PARAMETERS definitions
'//

' // Size = 8 bytes
TYPE TAPE_SET_DRIVE_PARAMETERS DWORD FILL
   ECC                AS BYTE    ' BOOLEAN
   Compression        AS BYTE    ' BOOLEAN
   DataPadding        AS BYTE    ' BOOLEAN
   ReportSetmarks     AS BYTE    ' BOOLEAN
   EOTWarningZoneSize AS DWORD   ' DWORD
END TYPE

'//
'// IOCTL_TAPE_GET_MEDIA_PARAMETERS definitions
'//

' // Size = 32 bytes
TYPE TAPE_GET_MEDIA_PARAMETERS   ' Must be 8 byte aligned
   Capacity       AS QUAD    ' LARGE_INTEGER
   Remaining      AS QUAD    ' LARGE_INTEGER
   BlockSize      AS DWORD   ' DWORD
   PartitionCount AS DWORD   ' DWORD
   WriteProtected AS BYTE    ' BOOLEAN
   alignment__(6) AS BYTE    ' // To keep 8 byte alignment
END TYPE

'//
'// IOCTL_TAPE_SET_MEDIA_PARAMETERS definitions
'//

' // Size = 4 bytes
TYPE TAPE_SET_MEDIA_PARAMETERS DWORD
   BlockSize AS DWORD   ' DWORD
END TYPE

'//
'// IOCTL_TAPE_CREATE_PARTITION definitions
'//

%TAPE_FIXED_PARTITIONS      = 0???
%TAPE_SELECT_PARTITIONS     = 1???
%TAPE_INITIATOR_PARTITIONS  = 2???

' // Size = 12 bytes
TYPE TAPE_CREATE_PARTITION DWORD
   Method AS DWORD   ' DWORD
   Count  AS DWORD   ' DWORD
   Size   AS DWORD   ' DWORD
END TYPE

'//
'// WMI Methods
'//
%TAPE_QUERY_DRIVE_PARAMETERS      = 0???
%TAPE_QUERY_MEDIA_CAPACITY        = 1???
%TAPE_CHECK_FOR_DRIVE_PROBLEM     = 2???
%TAPE_QUERY_IO_ERROR_DATA         = 3???
%TAPE_QUERY_DEVICE_ERROR_DATA     = 4???

' // Size = 12 bytes
TYPE TAPE_WMI_OPERATIONS DWORD
   Method         AS DWORD   ' DWORD
   DataBufferSize AS DWORD   ' DWORD
   DataBuffer     AS DWORD   ' PVOID
END TYPE

'//
'// Type of drive errors
'//
' TAPE_DRIVE_PROBLEM_TYPE enum
%TapeDriveProblemNone         = 0
%TapeDriveReadWriteWarning    = 1
%TapeDriveReadWriteError      = 2
%TapeDriveReadWarning         = 3
%TapeDriveWriteWarning        = 4
%TapeDriveReadError           = 5
%TapeDriveWriteError          = 6
%TapeDriveHardwareError       = 7
%TapeDriveUnsupportedMedia    = 8
%TapeDriveScsiConnectionError = 9
%TapeDriveTimetoClean         = 10
%TapeDriveCleanDriveNow       = 11
%TapeDriveMediaLifeExpired    = 12
%TapeDriveSnappedTape         = 13

#IF NOT %DEF(%NTTMAPI)
    %NTTMAPI = 1

#INCLUDE ONCE "ktmtypes.inc"

'//
'// Types for Nt level TM calls
'//

'//
'// KTM Tm object rights
'//
%TRANSACTIONMANAGER_QUERY_INFORMATION     = &H0001???
%TRANSACTIONMANAGER_SET_INFORMATION       = &H0002???
%TRANSACTIONMANAGER_RECOVER               = &H0004???
%TRANSACTIONMANAGER_RENAME                = &H0008???
%TRANSACTIONMANAGER_CREATE_RM             = &H0010???

'// The following right is intended for DTC's use only; it will be
'// deprecated, and no one else should take a dependency on it.
%TRANSACTIONMANAGER_BIND_TRANSACTION      = &H0020???

'//
'// Generic mappings for transaction manager rights.
'//

%TRANSACTIONMANAGER_GENERIC_READ          = %STANDARD_RIGHTS_READ OR _
                                            %TRANSACTIONMANAGER_QUERY_INFORMATION

%TRANSACTIONMANAGER_GENERIC_WRITE         = %STANDARD_RIGHTS_WRITE               OR _
                                            %TRANSACTIONMANAGER_SET_INFORMATION  OR _
                                            %TRANSACTIONMANAGER_RECOVER          OR _
                                            %TRANSACTIONMANAGER_RENAME           OR _
                                            %TRANSACTIONMANAGER_CREATE_RM

%TRANSACTIONMANAGER_GENERIC_EXECUTE       = %STANDARD_RIGHTS_EXECUTE

%TRANSACTIONMANAGER_ALL_ACCESS            = %STANDARD_RIGHTS_REQUIRED            OR _
                                            %TRANSACTIONMANAGER_GENERIC_READ     OR _
                                            %TRANSACTIONMANAGER_GENERIC_WRITE    OR _
                                            %TRANSACTIONMANAGER_GENERIC_EXECUTE  OR _
                                            %TRANSACTIONMANAGER_BIND_TRANSACTION

'//
'// KTM transaction object rights.
'//
%TRANSACTION_QUERY_INFORMATION     = &H0001???
%TRANSACTION_SET_INFORMATION       = &H0002???
%TRANSACTION_ENLIST                = &H0004???
%TRANSACTION_COMMIT                = &H0008???
%TRANSACTION_ROLLBACK              = &H0010???
%TRANSACTION_PROPAGATE             = &H0020???
%TRANSACTION_RIGHT_RESERVED1       = &H0040???

'//
'// Generic mappings for transaction rights.
'// Resource managers, when enlisting, should generally use the macro
'// TRANSACTION_RESOURCE_MANAGER_RIGHTS when opening a transaction.
'// It's the same as generic read and write except that it does not allow
'// a commit decision to be made.
'//

%TRANSACTION_GENERIC_READ            = %STANDARD_RIGHTS_READ          OR _
                                       %TRANSACTION_QUERY_INFORMATION OR _
                                       %SYNCHRONIZE

%TRANSACTION_GENERIC_WRITE           = %STANDARD_RIGHTS_WRITE         OR _
                                       %TRANSACTION_SET_INFORMATION   OR _
                                       %TRANSACTION_COMMIT            OR _
                                       %TRANSACTION_ENLIST            OR _
                                       %TRANSACTION_ROLLBACK          OR _
                                       %TRANSACTION_PROPAGATE         OR _
                                       %SYNCHRONIZE

%TRANSACTION_GENERIC_EXECUTE         = %STANDARD_RIGHTS_EXECUTE       OR _
                                       %TRANSACTION_COMMIT            OR _
                                       %TRANSACTION_ROLLBACK          OR _
                                       %SYNCHRONIZE

%TRANSACTION_ALL_ACCESS              = %STANDARD_RIGHTS_REQUIRED      OR _
                                       %TRANSACTION_GENERIC_READ      OR _
                                       %TRANSACTION_GENERIC_WRITE     OR _
                                       %TRANSACTION_GENERIC_EXECUTE

%TRANSACTION_RESOURCE_MANAGER_RIGHTS = %TRANSACTION_GENERIC_READ      OR _
                                       %STANDARD_RIGHTS_WRITE         OR _
                                       %TRANSACTION_SET_INFORMATION   OR _
                                       %TRANSACTION_ENLIST            OR _
                                       %TRANSACTION_ROLLBACK          OR _
                                       %TRANSACTION_PROPAGATE         OR _
                                       %SYNCHRONIZE

'//
'// KTM resource manager object rights.
'//
%RESOURCEMANAGER_QUERY_INFORMATION     = &H0001???
%RESOURCEMANAGER_SET_INFORMATION       = &H0002???
%RESOURCEMANAGER_RECOVER               = &H0004???
%RESOURCEMANAGER_ENLIST                = &H0008???
%RESOURCEMANAGER_GET_NOTIFICATION      = &H0010???
%RESOURCEMANAGER_REGISTER_PROTOCOL     = &H0020???
%RESOURCEMANAGER_COMPLETE_PROPAGATION  = &H0040???

'//
'// Generic mappings for resource manager rights.
'//
%RESOURCEMANAGER_GENERIC_READ        = %STANDARD_RIGHTS_READ                 OR _
                                       %RESOURCEMANAGER_QUERY_INFORMATION    OR _
                                       %SYNCHRONIZE

%RESOURCEMANAGER_GENERIC_WRITE       = %STANDARD_RIGHTS_WRITE                OR _
                                       %RESOURCEMANAGER_SET_INFORMATION      OR _
                                       %RESOURCEMANAGER_RECOVER              OR _
                                       %RESOURCEMANAGER_ENLIST               OR _
                                       %RESOURCEMANAGER_GET_NOTIFICATION     OR _
                                       %RESOURCEMANAGER_REGISTER_PROTOCOL    OR _
                                       %RESOURCEMANAGER_COMPLETE_PROPAGATION OR _
                                       %SYNCHRONIZE

%RESOURCEMANAGER_GENERIC_EXECUTE     = %STANDARD_RIGHTS_EXECUTE              OR _
                                       %RESOURCEMANAGER_RECOVER              OR _
                                       %RESOURCEMANAGER_ENLIST               OR _
                                       %RESOURCEMANAGER_GET_NOTIFICATION     OR _
                                       %RESOURCEMANAGER_COMPLETE_PROPAGATION OR _
                                       %SYNCHRONIZE

%RESOURCEMANAGER_ALL_ACCESS          = %STANDARD_RIGHTS_REQUIRED             OR _
                                       %RESOURCEMANAGER_GENERIC_READ         OR _
                                       %RESOURCEMANAGER_GENERIC_WRITE        OR _
                                       %RESOURCEMANAGER_GENERIC_EXECUTE


'//
'// KTM enlistment object rights.
'//
%ENLISTMENT_QUERY_INFORMATION     = &H0001???
%ENLISTMENT_SET_INFORMATION       = &H0002???
%ENLISTMENT_RECOVER               = &H0004???
%ENLISTMENT_SUBORDINATE_RIGHTS    = &H0008???
%ENLISTMENT_SUPERIOR_RIGHTS       = &H0010???

'//
'// Generic mappings for enlistment rights.
'//
%ENLISTMENT_GENERIC_READ        = %STANDARD_RIGHTS_READ           OR _
                                  %ENLISTMENT_QUERY_INFORMATION

%ENLISTMENT_GENERIC_WRITE       = %STANDARD_RIGHTS_WRITE          OR _
                                  %ENLISTMENT_SET_INFORMATION     OR _
                                  %ENLISTMENT_RECOVER             OR _
                                  %ENLISTMENT_SUBORDINATE_RIGHTS  OR _
                                  %ENLISTMENT_SUPERIOR_RIGHTS

%ENLISTMENT_GENERIC_EXECUTE     = %STANDARD_RIGHTS_EXECUTE        OR _
                                  %ENLISTMENT_RECOVER             OR _
                                  %ENLISTMENT_SUBORDINATE_RIGHTS  OR _
                                  %ENLISTMENT_SUPERIOR_RIGHTS

%ENLISTMENT_ALL_ACCESS          = %STANDARD_RIGHTS_REQUIRED       OR _
                                  %ENLISTMENT_GENERIC_READ        OR _
                                  %ENLISTMENT_GENERIC_WRITE       OR _
                                  %ENLISTMENT_GENERIC_EXECUTE


'//
'// Transaction outcomes.
'//

' enum TRANSACTION_OUTCOME
%TransactionOutcomeUndetermined  = 1
%TransactionOutcomeCommitted     = 2
%TransactionOutcomeAborted       = 3

' enum TRANSACTION_STATE
%TransactionStateNormal          = 1
%TransactionStateIndoubt         = 2
%TransactionStateCommittedNotify = 3

' // Size = 24 bytes
TYPE TRANSACTION_BASIC_INFORMATION DWORD
   TransactionId AS GUID    ' GUID
   State         AS DWORD   ' DWORD
   Outcome       AS DWORD   ' DWORD
END TYPE

' // Size = 24 bytes
TYPE TRANSACTIONMANAGER_BASIC_INFORMATION   ' Must be 8 byte alignment
   TmIdentity   AS GUID   ' GUID
   VirtualClock AS QUAD   ' LARGE_INTEGER
END TYPE

' // Size = 16 bytes
TYPE TRANSACTIONMANAGER_LOG_INFORMATION BYTE
   LogIdentity AS GUID   ' GUID
END TYPE

' // Size = 8 bytes
TYPE TRANSACTIONMANAGER_LOGPATH_INFORMATION DWORD
   LogPathLength AS DWORD   ' DWORD
   LogPathAS     AS WSTRINGZ * 1   ' __field_ecount(LogPathLength) WCHAR // Variable size
'//  Data[1];                       // Variable size data not declared
END TYPE

' // Size = 8 bytes
TYPE TRANSACTIONMANAGER_RECOVERY_INFORMATION QWORD
   LastRecoveredLsn AS QUAD   ' ULONGLONG
END TYPE

' // Size = 16 bytes
TYPE TRANSACTIONMANAGER_OLDEST_INFORMATION BYTE
   OldestTransactionGuid AS GUID   ' GUID
END TYPE

' // Size = 32 bytes
TYPE TRANSACTION_PROPERTIES_INFORMATION   ' Must be 8 byte aligned
   IsolationLevel    AS DWORD   ' DWORD
   IsolationFlags    AS DWORD   ' DWORD
   Timeout           AS QUAD    ' LARGE_INTEGER
   Outcome           AS DWORD   ' DWORD
   DescriptionLength AS DWORD   ' DWORD
   Description       AS WSTRINGZ * 4   ' WCHAR // Variable size
   ' Note: We are using STRING * 4 instead of * 1 to keep 8 byte alignment
'//          Data[1];            // Variable size data not declared
END TYPE

'// The following info-class is intended for DTC's use only; it will be
'// deprecated, and no one else should take a dependency on it.
' // Size = 4 bytes
TYPE TRANSACTION_BIND_INFORMATION DWORD
   TmHandle AS DWORD   ' HANDLE
END TYPE

' // Size = 32 bytes
TYPE TRANSACTION_ENLISTMENT_PAIR DWORD
   EnlistmentId      AS GUID   ' GUID
   ResourceManagerId AS GUID   ' GUID
END TYPE

' // Size = 36 bytes
TYPE TRANSACTION_ENLISTMENTS_INFORMATION DWORD
   NumberOfEnlistments AS DWORD   ' DWORD
   EnlistmentPair(0)   AS TRANSACTION_ENLISTMENT_PAIR   ' // Variable size
END TYPE

' // Size = 32 bytes
TYPE TRANSACTION_SUPERIOR_ENLISTMENT_INFORMATION DWORD
   SuperiorEnlistmentPair AS TRANSACTION_ENLISTMENT_PAIR
END TYPE

' // Size = 24 bytes
TYPE RESOURCEMANAGER_BASIC_INFORMATION DWORD
   ResourceManagerId AS GUID   ' GUID
   DescriptionLength AS DWORD   ' DWORD
   Description       AS WSTRINGZ * 1   ' WCHAR // Variable size
END TYPE

' // Size = 8 bytes
TYPE RESOURCEMANAGER_COMPLETION_INFORMATION DWORD
   IoCompletionPortHandle AS DWORD   ' HANDLE
   CompletionKey          AS DWORD   ' ULONG_PTR
END TYPE

' enum _TRANSACTION_INFORMATION_CLASS
%TransactionBasicInformation              = 0
%TransactionPropertiesInformation         = 1
%TransactionEnlistmentInformation         = 2
%TransactionSuperiorEnlistmentInformation = 3
'// The following info-class is intended for DTC's use only; it will be
'// deprecated, and no one else should take a dependency on it.
%TransactionBindInformation               = 4   ' // private and deprecated
%TransactionDTCPrivateInformation         = 5   ' // private and deprecated

' enum _TRANSACTIONMANAGER_INFORMATION_CLASS
%TransactionManagerBasicInformation             = 0
%TransactionManagerLogInformation               = 1
%TransactionManagerLogPathInformation           = 2
%TransactionManagerRecoveryInformation          = 4
'// The following info-classes are intended for internal use only; they
'// are considered deprecated, and no one else should take a dependency
'// on them.
%TransactionManagerOnlineProbeInformation       = 3
%TransactionManagerOldestTransactionInformation = 5

' enum _RESOURCEMANAGER_INFORMATION_CLASS
%ResourceManagerBasicInformation      = 0
%ResourceManagerCompletionInformation = 1

' // Size = 48 bytes
TYPE ENLISTMENT_BASIC_INFORMATION DWORD
   EnlistmentId      AS GUID   ' GUID
   TransactionId     AS GUID   ' GUID
   ResourceManagerId AS GUID   ' GUID
END TYPE

' // Size = 48 bytes
TYPE ENLISTMENT_CRM_INFORMATION DWORD
   CrmTransactionManagerId AS GUID
   CrmResourceManagerId    AS GUID
   CrmEnlistmentId         AS GUID
END TYPE

' enum _ENLISTMENT_INFORMATION_CLASS
%EnlistmentBasicInformation    = 0
%EnlistmentRecoveryInformation = 1
%EnlistmentCrmInformation      = 2

' // Size = 16 bytes
TYPE TRANSACTION_LIST_ENTRY DWORD
   UOW AS GUID   ' UOW
END TYPE

' // Size = 20 bytes
TYPE TRANSACTION_LIST_INFORMATION DWORD
   NumberOfTransactions      AS DWORD   ' DWORD
   TransactionInformation(0) AS TRANSACTION_LIST_ENTRY   ' // Var size
END TYPE

'//
'// Types of objects known to the kernel transaction manager.
'//

' enum KTMOBJECT_TYPE
%KTMOBJECT_TRANSACTION         = 0
%KTMOBJECT_TRANSACTION_MANAGER = 1
%KTMOBJECT_RESOURCE_MANAGER    = 2
%KTMOBJECT_ENLISTMENT          = 3
%KTMOBJECT_INVALID             = 4

'//
'// KTMOBJECT_CURSOR
'//
'// Used by NtEnumerateTransactionObject to enumerate a transaction
'// object namespace (e.g. enlistments in a resource manager).
'//

' // Size = 36 bytes
TYPE KTMOBJECT_CURSOR DWORD
   LastQuery     AS GUID   ' GUID
   ObjectIdCount AS DWORD   ' DWORD
   ObjectIds(0)  AS GUID   ' GUID
END TYPE

#ENDIF ' // _NTTMAPI_


'typedef DWORD TP_VERSION, *PTP_VERSION;

'typedef struct _TP_CALLBACK_INSTANCE TP_CALLBACK_INSTANCE, *PTP_CALLBACK_INSTANCE;

'typedef VOID (NTAPI *PTP_SIMPLE_CALLBACK)(
'    __inout     PTP_CALLBACK_INSTANCE Instance,
'    __inout_opt PVOID                 Context
'    );

'typedef struct _TP_POOL TP_POOL, *PTP_POOL;

' enum TP_CALLBACK_PRIORITY
%TP_CALLBACK_PRIORITY_HIGH = 0
%TP_CALLBACK_PRIORITY_NORMAL = 1
%TP_CALLBACK_PRIORITY_LOW = 2
%TP_CALLBACK_PRIORITY_INVALID = 3

' // Size = 8 bytes
TYPE TP_POOL_STACK_INFORMATION DWORD
   StackReserve AS DWORD   ' SIZE_T
   StackCommit  AS DWORD   ' SIZE_T
END TYPE

'typedef struct _TP_CLEANUP_GROUP TP_CLEANUP_GROUP, *PTP_CLEANUP_GROUP;

'typedef VOID (NTAPI *PTP_CLEANUP_GROUP_CANCEL_CALLBACK)(
'    __inout_opt PVOID ObjectContext,
'    __inout_opt PVOID CleanupContext
'    );

'#if (_WIN32_WINNT >= _WIN32_WINNT_WIN7)

'typedef struct _TP_CALLBACK_ENVIRON_V3 {
'    TP_VERSION                         Version;
'    PTP_POOL                           Pool;
'    PTP_CLEANUP_GROUP                  CleanupGroup;
'    PTP_CLEANUP_GROUP_CANCEL_CALLBACK  CleanupGroupCancelCallback;
'    PVOID                              RaceDll;
'    struct _ACTIVATION_CONTEXT        *ActivationContext;
'    PTP_SIMPLE_CALLBACK                FinalizationCallback;
'    union {
'        DWORD                          Flags;
'        struct {
'            DWORD                      LongFunction :  1;
'            DWORD                      Persistent   :  1;
'            DWORD                      Private      : 30;
'        } s;
'    } u;
'    TP_CALLBACK_PRIORITY               CallbackPriority;
'    DWORD                              Size;
'} TP_CALLBACK_ENVIRON_V3;

'typedef TP_CALLBACK_ENVIRON_V3 TP_CALLBACK_ENVIRON, *PTP_CALLBACK_ENVIRON;

'#else

'typedef struct _TP_CALLBACK_ENVIRON_V1 {
'    TP_VERSION                         Version;
'    PTP_POOL                           Pool;
'    PTP_CLEANUP_GROUP                  CleanupGroup;
'    PTP_CLEANUP_GROUP_CANCEL_CALLBACK  CleanupGroupCancelCallback;
'    PVOID                              RaceDll;
'    struct _ACTIVATION_CONTEXT        *ActivationContext;
'    PTP_SIMPLE_CALLBACK                FinalizationCallback;
'    union {
'        DWORD                          Flags;
'        struct {
'            DWORD                      LongFunction :  1;
'            DWORD                      Persistent   :  1;
'            DWORD                      Private      : 30;
'        } s;
'    } u;
'} TP_CALLBACK_ENVIRON_V1;

'typedef TP_CALLBACK_ENVIRON_V1 TP_CALLBACK_ENVIRON, *PTP_CALLBACK_ENVIRON;

'#endif

#IF %WINVER >= &H0601    ' Windows 7

' // Size = 4 bytes
TYPE TP_CALLBACK_ENVIRON_V3_UNION_STRUCT DWORD
   LongFunction AS BIT * 1 IN DWORD
   Persistent   AS BIT * 1
   Private      AS BIT * 30
END TYPE

' // Size = 4 bytes
UNION TP_CALLBACK_ENVIRON_V3_UNION DWORD
   Flags AS DWORD   ' DWORD
   TP_CALLBACK_ENVIRON_V3_UNION_STRUCT
END UNION

' // Size = 40 bytes
TYPE TP_CALLBACK_ENVIRON_V3 DWORD
   Version                    AS DWORD   ' TP_VERSION
   Pool                       AS DWORD   ' PTP_POOL
   CleanupGroup               AS DWORD   ' PTP_CLEANUP_GROUP
   CleanupGroupCancelCallback AS DWORD   ' PTP_CLEANUP_GROUP_CANCEL_CALLBACK
   RaceDll                    AS DWORD   ' PVOID
   ActivationContext          AS DWORD   ' struct _ACTIVATION_CONTEXT *
   FinalizationCallback       AS DWORD   ' PTP_SIMPLE_CALLBACK
   TP_CALLBACK_ENVIRON_V3_UNION
   CallbackPriority           AS LONG   ' TP_CALLBACK_PRIORITY
   Size                       AS DWORD   ' DWORD
END TYPE

MACRO TP_CALLBACK_ENVIRON = TP_CALLBACK_ENVIRON_V3

#ELSE

' // Size = 4 bytes
TYPE TP_CALLBACK_ENVIRON_V1_UNION_STRUCT DWORD
   LongFunction AS BIT * 1 IN DWORD
   Persistent   AS BIT * 1
   Private      AS BIT * 30
END TYPE

' // Size = 4 bytes
UNION TP_CALLBACK_ENVIRON_V1_UNION DWORD
   Flags AS DWORD   ' DWORD
   TP_CALLBACK_ENVIRON_V1_UNION_STRUCT
END UNION

' // Size = 32 bytes
TYPE TP_CALLBACK_ENVIRON_V1 DWORD
   Version                    AS DWORD   ' TP_VERSION
   Pool                       AS DWORD   ' PTP_POOL
   CleanupGroup               AS DWORD   ' PTP_CLEANUP_GROUP
   CleanupGroupCancelCallback AS DWORD   ' PTP_CLEANUP_GROUP_CANCEL_CALLBACK
   RaceDll                    AS DWORD   ' PVOID
   ActivationContext          AS DWORD   ' struct _ACTIVATION_CONTEXT *
   FinalizationCallback       AS DWORD   ' PTP_SIMPLE_CALLBACK
   TP_CALLBACK_ENVIRON_V1_UNION
END TYPE

MACRO TP_CALLBACK_ENVIRON = TP_CALLBACK_ENVIRON_V1

#ENDIF

'#if !defined(MIDL_PASS)

'FORCEINLINE
'VOID
'TpInitializeCallbackEnviron(
'    __out PTP_CALLBACK_ENVIRON CallbackEnviron
'    )
'{

'#if (_WIN32_WINNT >= _WIN32_WINNT_WIN7)

'    CallbackEnviron->Version = 3;

'#else

'    CallbackEnviron->Version = 1;

'#endif

'    CallbackEnviron->Pool = NULL;
'    CallbackEnviron->CleanupGroup = NULL;
'    CallbackEnviron->CleanupGroupCancelCallback = NULL;
'    CallbackEnviron->RaceDll = NULL;
'    CallbackEnviron->ActivationContext = NULL;
'    CallbackEnviron->FinalizationCallback = NULL;
'    CallbackEnviron->u.Flags = 0;
'}

MACRO TpInitializeCallbackEnviron (CallbackEnviron)
#IF %WINVER >= &H0601    ' Windows 7
   CallbackEnviron.Version = 3
#ELSE
   CallbackEnviron.Version = 1
#ENDIF
   CallbackEnviron.Pool = %NULL
   CallbackEnviron.CleanupGroup = %NULL
   CallbackEnviron.CleanupGroupCancelCallback = %NULL
   CallbackEnviron.RaceDll = %NULL
   CallbackEnviron.ActivationContext = %NULL
   CallbackEnviron.FinalizationCallback = %NULL
   CallbackEnviron.Flags = 0
#IF %WINVER >= &H0601    ' Windows 7
   CallbackEnviron.CallbackPriority = %TP_CALLBACK_PRIORITY_NORMAL
   CallbackEnviron.Size = SIZEOF(TP_CALLBACK_ENVIRON)
#ENDIF
END MACRO

'FORCEINLINE
'VOID
'TpSetCallbackThreadpool(
'    __inout PTP_CALLBACK_ENVIRON CallbackEnviron,
'    __in    PTP_POOL             Pool
'    )
'{
'    CallbackEnviron->Pool = Pool;
'}

MACRO TpSetCallbackThreadpool (CallbackEnviron, Pool)
   CallbackEnviron.Pool = Pool
END MACRO

'FORCEINLINE
'VOID
'TpSetCallbackCleanupGroup(
'    __inout  PTP_CALLBACK_ENVIRON              CallbackEnviron,
'    __in     PTP_CLEANUP_GROUP                 CleanupGroup,
'    __in_opt PTP_CLEANUP_GROUP_CANCEL_CALLBACK CleanupGroupCancelCallback
'    )
'{
'    CallbackEnviron->CleanupGroup = CleanupGroup;
'    CallbackEnviron->CleanupGroupCancelCallback = CleanupGroupCancelCallback;
'}

MACRO TpSetCallbackCleanupGroup (CallbackEnviron, CleanupGroup, CleanupGroupCancelCallback)
   CallbackEnviron.CleanupGroup = CleanupGroup
   CallbackEnviron.CleanupGroupCancelCallback = CleanupGroupCancelCallback
END MACRO

'FORCEINLINE
'VOID
'TpSetCallbackActivationContext(
'    __inout  PTP_CALLBACK_ENVIRON CallbackEnviron,
'    __in_opt struct _ACTIVATION_CONTEXT *ActivationContext
'    )
'{
'    CallbackEnviron->ActivationContext = ActivationContext;
'}

MACRO TpSetCallbackActivationContext (CallbackEnviron, ActivationContext)
   CallbackEnviron.ActivationContext = ActivationContext
END MACRO

'FORCEINLINE
'VOID
'TpSetCallbackNoActivationContext(
'    __inout PTP_CALLBACK_ENVIRON CallbackEnviron
'    )
'{
'    CallbackEnviron->ActivationContext = (struct _ACTIVATION_CONTEXT *)(LONG_PTR) -1; // INVALID_ACTIVATION_CONTEXT
'}

MACRO TpSetCallbackNoActivationContext (CallbackEnviron)
   CallbackEnviron.ActivationContext = -1   ' // INVALID_ACTIVATION_CONTEXT
END MACRO

'FORCEINLINE
'VOID
'TpSetCallbackLongFunction(
'    __inout PTP_CALLBACK_ENVIRON CallbackEnviron
'    )
'{
'    CallbackEnviron->u.s.LongFunction = 1;
'}

MACRO TpSetCallbackLongFunction (CallbackEnviron)
   CallbackEnviron.LongFunction = 1
END MACRO

'FORCEINLINE
'VOID
'TpSetCallbackRaceWithDll(
'    __inout PTP_CALLBACK_ENVIRON CallbackEnviron,
'    __in    PVOID                DllHandle
'    )
'{
'    CallbackEnviron->RaceDll = DllHandle;
'}

MACRO TpSetCallbackRaceWithDll (CallbackEnviron, DllHandle)
   CallbackEnviron.RaceDll = DllHandle
END MACRO

'FORCEINLINE
'VOID
'TpSetCallbackFinalizationCallback(
'    __inout PTP_CALLBACK_ENVIRON CallbackEnviron,
'    __in    PTP_SIMPLE_CALLBACK  FinalizationCallback
'    )
'{
'    CallbackEnviron->FinalizationCallback = FinalizationCallback;
'}

MACRO TpSetCallbackFinalizationCallback (CallbackEnviron, FinalizationCallback)
   CallbackEnviron.FinalizationCallback = FinalizationCallback
END MACRO

'#if (_WIN32_WINNT >= _WIN32_WINNT_WIN7)
#IF %WINVER >= &H0601    ' Windows 7

'FORCEINLINE
'VOID
'TpSetCallbackPriority(
'    __inout PTP_CALLBACK_ENVIRON CallbackEnviron,
'    __in    TP_CALLBACK_PRIORITY Priority
'    )
'{
'    CallbackEnviron->CallbackPriority = Priority;
'}

MACRO TpSetCallbackPriority (CallbackEnviron, Priority)
   CallbackEnviron.CallbackPriority = Priority
END MACRO

#ENDIF

'FORCEINLINE
'VOID
'TpSetCallbackPersistent(
'    __inout PTP_CALLBACK_ENVIRON CallbackEnviron
'    )
'{
'    CallbackEnviron->u.s.Persistent = 1;
'}

MACRO TpSetCallbackPersistent (CallbackEnviron)
   CallbackEnviron.Persistent = 1
END MACRO

'FORCEINLINE
'VOID
'TpDestroyCallbackEnviron(
'    __in PTP_CALLBACK_ENVIRON CallbackEnviron
'    )
'{
'    //
'    // For the current version of the callback environment, no actions
'    // need to be taken to tear down an initialized structure.  This
'    // may change in a future release.
'    //

'    UNREFERENCED_PARAMETER(CallbackEnviron);
'}

'#endif // !defined(MIDL_PASS)


'typedef struct _TP_WORK TP_WORK, *PTP_WORK;

'typedef VOID (NTAPI *PTP_WORK_CALLBACK)(
'    __inout     PTP_CALLBACK_INSTANCE Instance,
'    __inout_opt PVOID                 Context,
'    __inout     PTP_WORK              Work
'    );

'typedef struct _TP_TIMER TP_TIMER, *PTP_TIMER;

'typedef VOID (NTAPI *PTP_TIMER_CALLBACK)(
'    __inout     PTP_CALLBACK_INSTANCE Instance,
'    __inout_opt PVOID                 Context,
'    __inout     PTP_TIMER             Timer
'    );

'typedef DWORD    TP_WAIT_RESULT;

'typedef struct _TP_WAIT TP_WAIT, *PTP_WAIT;

'typedef VOID (NTAPI *PTP_WAIT_CALLBACK)(
'    __inout     PTP_CALLBACK_INSTANCE Instance,
'    __inout_opt PVOID                 Context,
'    __inout     PTP_WAIT              Wait,
'    __in        TP_WAIT_RESULT        WaitResult
'    );

'typedef struct _TP_IO TP_IO, *PTP_IO;


'#if (_WIN32_WINNT > 0x0500) || (_WIN32_FUSION >= 0x0100) || ISOLATION_AWARE_ENABLED // winnt_only
%ACTIVATION_CONTEXT_SECTION_ASSEMBLY_INFORMATION         = 1
%ACTIVATION_CONTEXT_SECTION_DLL_REDIRECTION              = 2
%ACTIVATION_CONTEXT_SECTION_WINDOW_CLASS_REDIRECTION     = 3
%ACTIVATION_CONTEXT_SECTION_COM_SERVER_REDIRECTION       = 4
%ACTIVATION_CONTEXT_SECTION_COM_INTERFACE_REDIRECTION    = 5
%ACTIVATION_CONTEXT_SECTION_COM_TYPE_LIBRARY_REDIRECTION = 6
%ACTIVATION_CONTEXT_SECTION_COM_PROGID_REDIRECTION       = 7
%ACTIVATION_CONTEXT_SECTION_GLOBAL_OBJECT_RENAME_TABLE   = 8
%ACTIVATION_CONTEXT_SECTION_CLR_SURROGATES               = 9
%ACTIVATION_CONTEXT_SECTION_APPLICATION_SETTINGS         = 10
%ACTIVATION_CONTEXT_SECTION_COMPATIBILITY_INFO           = 11
'#endif // winnt_only

' Note that this structure definition was accidentally omitted from WinNT.h.
' This error will be corrected in the future. In the meantime, to compile
' your application, include the structure definition contained in this
' topic in your source code.
' http://msdn.microsoft.com/en-us/library/windows/desktop/aa373217%28v=vs.85%29.aspx

'typedef struct _SYSTEM_POWER_INFORMATION {
'  ULONG MaxIdlenessAllowed;
'  ULONG Idleness;
'  ULONG TimeRemaining;
'  UCHAR CoolingMode;
'} SYSTEM_POWER_INFORMATION, *PSYSTEM_POWER_INFORMATION;

TYPE SYSTEM_POWER_INFORMATION DWORD
   MaxIdlenessAllowed AS DWORD   ' ULONG
   Idleness           AS DWORD   ' ULONG
   TimeRemaining      AS DWORD   ' ULONG
   oolingMode         AS BYTE    ' UCHAR
END TYPE
