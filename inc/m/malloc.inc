' ########################################################################################
' Microsoft C Runtime
' File: malloc.inc
' Contents: Contains the function declarations for memory allocation functions; also
' defines manifest constants and types used by the heap routines.
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%MALLOC_INC = 1

#INCLUDE ONCE "crtdefs.inc"

'/* Maximum heap request the heap manager will attempt */

%HEAP_MAXREQ    = &HFFFFFFE0???

'/* Constants for _heapchk/_heapset/_heapwalk routines */

%HEAPEMPTY      = -1
%HEAPOK         = -2
%HEAPBADBEGIN   = -3
%HEAPBADNODE    = -4
%HEAPEND        = -5
%HEAPBADPTR     = -6
%FREEENTRY      = 0
%USEDENTRY      = 1

#IF NOT %DEF(%HEAPINFO_DEFINED)
%HEAPINFO_DEFINED = 1
' // Size = 12 bytes
TYPE HEAPINFO DWORD
   pentry  AS LONG PTR   ' int * _pentry
   size    AS DWORD      ' size_t _size
   useflag AS LONG       ' int _useflag
END TYPE
#ENDIF

'/* External variable declarations */

'#if !defined(_M_CEE_PURE)
'extern _CRT_INSECURE_DEPRECATE_GLOBALS(_get_amblksiz) unsigned int _amblksiz;
'#else
'_CRT_INSECURE_DEPRECATE_GLOBALS(_get_amblksiz) _CRTIMP unsigned int * __cdecl __p__amblksiz(void);
'#define _amblksiz (*__p__amblksiz())
'#endif /* !defined(_M_CEE_PURE) */

FUNCTION getamblksiz CDECL () AS LONG
   LOCAL hLib AS DWORD
   LOCAL pblocksize AS LONG PTR
   hLib = LoadLibrary($CRT_DLLNAME)
   IF hLib THEN
      pblocksize = GetProcAddress(hLib, "_amblksiz")
      IF pblocksize THEN FUNCTION = @pblocksize
      FreeLibrary hLib
   END IF
END FUNCTION

SUB setamblksiz (BYVAL blksiz AS LONG)
   LOCAL hLib AS DWORD
   LOCAL pblocksize AS LONG PTR
   hLib = LoadLibrary($CRT_DLLNAME)
   IF hLib THEN
      pblocksize = GetProcAddress(hLib, "_amblksiz")
      IF pblocksize THEN @pblocksize = blksiz
      FreeLibrary hLib
   END IF
END SUB

'#define _mm_free(a)      _aligned_free(a)
'#define _mm_malloc(a, b)    _aligned_malloc(a, b)

'/* Function prototypes */

#IF NOT %DEF(%CRT_ALLOCATION_DEFINED)
    %CRT_ALLOCATION_DEFINED = 1

' ========================================================================================
' *** All versions ***
' _Check_return_ _Ret_opt_bytecap_x_(_Count*_Size) _CRTIMP _CRT_JIT_INTRINSIC _CRTNOALIAS _CRTRESTRICT
' void * __cdecl calloc(_In_ size_t _Count, _In_ size_t _Size);
' ========================================================================================
DECLARE FUNCTION calloc CDECL IMPORT $CRT_DLLNAME ALIAS "calloc" ( _
   BYVAL num AS DWORD _                                 ' __in size_t num
 , BYVAL size AS DWORD _                                ' __in size_t size
 ) AS DWORD                                             ' void *
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _CRTIMP _CRTNOALIAS void __cdecl free(_Inout_opt_ void * _Memory);
' ========================================================================================
DECLARE SUB free CDECL IMPORT $CRT_DLLNAME ALIAS "free" ( _
   BYVAL memblock AS DWORD _                            ' __inout void *memblock
 )                                                      ' void
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _Ret_opt_bytecap_(_Size) _CRTIMP _CRT_JIT_INTRINSIC _CRTNOALIAS _CRTRESTRICT
' void * __cdecl malloc(_In_ size_t _Size);
' ========================================================================================
DECLARE FUNCTION malloc CDECL IMPORT $CRT_DLLNAME ALIAS "malloc" ( _
   BYVAL size AS DWORD _                                ' __in size_t size
 ) AS DWORD                                             ' void *
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _Ret_opt_bytecap_(_NewSize) _CRTIMP _CRTNOALIAS _CRTRESTRICT
' void * __cdecl realloc(_In_opt_ void * _Memory, _In_ size_t _NewSize);
' ========================================================================================
DECLARE FUNCTION realloc CDECL IMPORT $CRT_DLLNAME ALIAS "realloc" ( _
   BYVAL memblock AS DWORD _                            ' __in void *memblock
 , BYVAL size AS DWORD _                                ' __in size_t size
 ) AS DWORD                                             ' void *
' ========================================================================================

' ========================================================================================
' _Check_return_ _Ret_opt_bytecap_x_(_Count*_Size) _CRTIMP _CRTNOALIAS _CRTRESTRICT
' void * __cdecl _recalloc(_In_opt_ void * _Memory, _In_ size_t _Count, _In_ size_t _Size);
' ========================================================================================
DECLARE FUNCTION recalloc_ CDECL IMPORT $CRT_DLLNAME ALIAS "_recalloc" ( _
   BYVAL memblock AS DWORD _                            ' __in void *memblock
 , BYVAL num AS DWORD _                                 ' __in size_t num
 , BYVAL size AS DWORD _                                ' __in size_t size
 ) AS DWORD                                             ' void *
' ========================================================================================

' ========================================================================================
' _CRTIMP _CRTNOALIAS void __cdecl _aligned_free(_Inout_opt_ void * _Memory);
' ========================================================================================
DECLARE SUB aligned_free CDECL IMPORT $CRT_DLLNAME ALIAS "_aligned_free" ( _
   BYVAL memblock AS DWORD _                            ' __inout void *memblock
 )                                                      ' void
' ========================================================================================

' ========================================================================================
' _Check_return_ _Ret_opt_bytecap_(_Size) _CRTIMP _CRTNOALIAS _CRTRESTRICT
' void * __cdecl _aligned_malloc(_In_ size_t _Size, _In_ size_t _Alignment);
' ========================================================================================
DECLARE FUNCTION aligned_malloc CDECL IMPORT $CRT_DLLNAME ALIAS "_aligned_malloc" ( _
   BYVAL size AS DWORD _                                ' __in size_t size
 , BYVAL aligment AS DWORD _                            ' __in size_t aligment
 ) AS DWORD                                             ' void *
' ========================================================================================

' ========================================================================================
' _Check_return_ _Ret_opt_bytecap_(_Size) _CRTIMP _CRTNOALIAS _CRTRESTRICT
' void * __cdecl _aligned_offset_malloc(_In_ size_t _Size, _In_ size_t _Alignment, _In_ size_t _Offset);
' ========================================================================================
DECLARE FUNCTION aligned_offset_malloc CDECL IMPORT $CRT_DLLNAME ALIAS "_aligned_offset_malloc" ( _
   BYVAL size AS DWORD _                                ' __in size_t size
 , BYVAL aligment AS DWORD _                            ' __in size_t aligment
 , BYVAL offset AS DWORD _                              ' __in size_t offset
 ) AS DWORD                                             ' void *
' ========================================================================================

' ========================================================================================
' _Check_return_ _Ret_opt_bytecap_(_NewSize) _CRTIMP _CRTNOALIAS _CRTRESTRICT
' void * __cdecl _aligned_realloc(_In_opt_ void * _Memory, _In_ size_t _NewSize, _In_ size_t _Alignment);
' ========================================================================================
DECLARE FUNCTION aligned_realloc CDECL IMPORT $CRT_DLLNAME ALIAS "_aligned_realloc" ( _
   BYVAL memblock AS DWORD _                            ' __in void *memblock
 , BYVAL size AS DWORD _                                ' __in size_t size
 , BYVAL aligment AS DWORD _                            ' __in size_t aligment
 , BYVAL offset AS DWORD _                              ' __in size_t offset
 ) AS DWORD                                             ' void *
' ========================================================================================

' ========================================================================================
' _Check_return_ _Ret_opt_bytecap_x_(_Count*_Size) _CRTIMP _CRTNOALIAS _CRTRESTRICT
' void * __cdecl _aligned_recalloc(_In_opt_ void * _Memory, _In_ size_t _Count, _In_ size_t _Size, _In_ size_t _Alignment);
' ========================================================================================
DECLARE FUNCTION aligned_recalloc CDECL IMPORT $CRT_DLLNAME ALIAS "_aligned_recalloc" ( _
   BYVAL memblock AS DWORD _                            ' __in void *memblock
 , BYVAL num AS DWORD _                                 ' __in size_t num
 , BYVAL size AS DWORD _                                ' __in size_t size
 , BYVAL aligment AS DWORD _                            ' __in size_t aligment
 , BYVAL offset AS DWORD _                              ' __in size_t offset
 ) AS DWORD                                             ' void *
' ========================================================================================

' ========================================================================================
' _Check_return_ _Ret_opt_bytecap_(_NewSize) _CRTIMP _CRTNOALIAS _CRTRESTRICT
' void * __cdecl _aligned_offset_realloc(_In_opt_ void * _Memory, _In_ size_t _NewSize, _In_ size_t _Alignment, _In_ size_t _Offset);
' ========================================================================================
DECLARE FUNCTION aligned_offset_realloc CDECL IMPORT $CRT_DLLNAME ALIAS "_aligned_offset_realloc" ( _
   BYVAL memblock AS DWORD _                            ' __in void *memblock
 , BYVAL size AS DWORD _                                ' __in size_t size
 , BYVAL aligment AS DWORD _                            ' __in size_t aligment
 , BYVAL offset AS DWORD _                              ' __in size_t offset
 ) AS DWORD                                             ' void *
' ========================================================================================

' ========================================================================================
' _Check_return_ _Ret_opt_bytecap_x_(_Count*_Size) _CRTIMP _CRTNOALIAS _CRTRESTRICT
' void * __cdecl _aligned_offset_recalloc(_In_opt_ void * _Memory, _In_ size_t _Count, _In_ size_t _Size, _In_ size_t _Alignment, _In_ size_t _Offset);
' ========================================================================================
DECLARE FUNCTION aligned_offset_recalloc CDECL IMPORT $CRT_DLLNAME ALIAS "_aligned_offset_recalloc" ( _
   BYVAL memblock AS DWORD _                            ' __in void *memblock
 , BYVAL num AS DWORD _                                 ' __in size_t num
 , BYVAL size AS DWORD _                                ' __in size_t size
 , BYVAL aligment AS DWORD _                            ' __in size_t aligment
 , BYVAL offset AS DWORD _                              ' __in size_t offset
 ) AS DWORD                                             ' void *
' ========================================================================================

' ========================================================================================
' _Check_return_ _CRTIMP size_t __cdecl _aligned_msize(_In_ void * _Memory, _In_ size_t _Alignment, _In_ size_t _Offset);
' ========================================================================================
DECLARE FUNCTION aligned_msize CDECL IMPORT $CRT_DLLNAME ALIAS "_aligned_msize" ( _
   BYVAL memblock AS DWORD _                            ' __in void *memblock
 , BYVAL aligment AS DWORD _                            ' __in size_t aligment
 , BYVAL offset AS DWORD _                              ' __in size_t offset
 ) AS DWORD                                             ' void *
' ========================================================================================

#ENDIF   ' CRT_ALLOCATION_DEFINED

' ========================================================================================
' _CRTIMP int __cdecl _resetstkoflw (void);
' ========================================================================================
DECLARE FUNCTION resetstkoflw_ CDECL IMPORT $CRT_DLLNAME ALIAS "_resetstkoflw" ( _
 ) AS LONG                                              ' int
' ========================================================================================

%MAX_WAIT_MALLOC_CRT = 60000

' ========================================================================================
' _CRTIMP unsigned long __cdecl _set_malloc_crt_max_wait(_In_ unsigned long _NewValue);
' ========================================================================================
DECLARE FUNCTION set_malloc_crt_max_wait CDECL IMPORT $CRT_DLLNAME ALIAS "_set_malloc_crt_max_wait" ( _
   BYVAL NewValue AS DWORD _                            ' __in unsigned long _NewValue
 ) AS LONG                                              ' long
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _Ret_opt_bytecap_(_NewSize) _CRTIMP void *  __cdecl _expand(
'_In_opt_ void * _Memory, _In_ size_t _NewSize);
' ========================================================================================
DECLARE FUNCTION expand_ CDECL IMPORT $CRT_DLLNAME ALIAS "_expand" ( _
   BYVAL memblock AS DWORD _                            ' __in void *memblock
 , BYVAL size AS DWORD _                                ' __in size_t size
 ) AS DWORD                                             ' void *
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRTIMP size_t  __cdecl _msize(_In_ void * _Memory);
' ========================================================================================
DECLARE FUNCTION msize_ CDECL IMPORT $CRT_DLLNAME ALIAS "_msize" ( _
   BYVAL memblock AS DWORD _                            ' __in void *memblock
 ) AS DWORD                                             ' void *
' ========================================================================================

' ========================================================================================
' _Check_return_ _Ret_bytecap_(_Size) void * __cdecl _alloca(_In_ size_t _Size);
' Intrinsic function. Not exported.
' ========================================================================================
'DECLARE FUNCTION alloca_ CDECL IMPORT $CRT_DLLNAME ALIAS "_alloca" ( _
'   BYVAL size AS DWORD _                                ' __in size_t size
' ) AS DWORD                                             ' void *
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRTIMP size_t __cdecl _get_sbh_threshold(void);
' ========================================================================================
DECLARE FUNCTION get_sbh_threshold CDECL IMPORT $CRT_DLLNAME ALIAS "_get_sbh_threshold" ( _
 ) AS DWORD                                             ' size_t
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _CRTIMP int __cdecl _set_sbh_threshold(_In_ size_t _NewValue);
' ========================================================================================
DECLARE FUNCTION set_sbh_threshold CDECL IMPORT $CRT_DLLNAME ALIAS "_set_sbh_threshold" ( _
   BYVAL NewValue AS DWORD _                            ' __in size_t _NewValue
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _CRTIMP errno_t __cdecl _set_amblksiz(_In_ size_t _Value);
' ========================================================================================
DECLARE FUNCTION set_amblksiz CDECL IMPORT $CRT_DLLNAME ALIAS "_set_amblksiz" ( _
   BYVAL Value AS DWORD _                               ' __in size_t _Value
 ) AS LONG                                              ' errno_t
' ========================================================================================

' ========================================================================================
' _CRTIMP errno_t __cdecl _get_amblksiz(_Out_ size_t * _Value);
' ========================================================================================
DECLARE FUNCTION get_amblksiz CDECL IMPORT $CRT_DLLNAME ALIAS "_get_amblksiz" ( _
   BYREF blockSize AS DWORD _                           ' __in size_t * blockSize
 ) AS LONG                                              ' errno_t
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRTIMP int __cdecl _heapadd(_In_ void * _Memory, _In_ size_t _Size);
' ========================================================================================
DECLARE FUNCTION heapadd_ CDECL IMPORT $CRT_DLLNAME ALIAS "_heapadd" ( _
   BYVAL memblock AS DWORD _                            ' __in void *memblock
 , BYVAL size AS DWORD _                                ' __in size_t size
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRTIMP int __cdecl _heapchk(void);
' ========================================================================================
DECLARE FUNCTION heapchk_ CDECL IMPORT $CRT_DLLNAME ALIAS "_heapchk" ( _
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRTIMP int __cdecl _heapmin(void);
' ========================================================================================
DECLARE FUNCTION heapmin_ CDECL IMPORT $CRT_DLLNAME ALIAS "_heapmin" ( _
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _CRTIMP int __cdecl _heapset(_In_ unsigned int _Fill);
' ========================================================================================
DECLARE FUNCTION heapset_ CDECL IMPORT $CRT_DLLNAME ALIAS "_heapset" ( _
   BYVAL fill AS DWORD _                                ' __in unsigned int fill
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _CRTIMP _CRT_MANAGED_HEAP_DEPRECATE int __cdecl _heapwalk(_Inout_ _HEAPINFO * _EntryInfo);
' ========================================================================================
DECLARE FUNCTION heapwalk_ CDECL IMPORT $CRT_DLLNAME ALIAS "_heapwalk" ( _
   BYREF entryinfo AS HEAPINFO _                        ' __inout _HEAPINFO *entryinfo
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _CRTIMP size_t  __cdecl _heapused(size_t * _Used, size_t * _Commit);
' ========================================================================================
DECLARE FUNCTION heapused_ CDECL IMPORT $CRT_DLLNAME ALIAS "_heapused" ( _
   BYREF pUsed AS DWORD _                               ' __in size_t pUsed
 , BYREF pCommit AS DWORD _                             ' __in size_t pCommit
 ) AS LONG                                              ' int
' ========================================================================================

' ========================================================================================
' _CRTIMP intptr_t __cdecl _get_heap_handle(void);
' ========================================================================================
DECLARE FUNCTION get_heap_handle CDECL IMPORT $CRT_DLLNAME ALIAS "_get_heap_handle" ( _
 ) AS DWORD                                             ' intptr_t
' ========================================================================================

%ALLOCA_S_THRESHOLD     = 1024
%ALLOCA_S_STACK_MARKER  = &HCCCC
%ALLOCA_S_HEAP_MARKER   = &HDDDD

#IF %DEF(%HEAPHOOK)

'#ifdef  HEAPHOOK
'#ifndef _HEAPHOOK_DEFINED
'/* hook function type */
'typedef int (__cdecl * _HEAPHOOK)(int, size_t, void *, void **);
'#define _HEAPHOOK_DEFINED
'#endif  /* _HEAPHOOK_DEFINED */

'/* set hook function */
'_CRTIMP _HEAPHOOK __cdecl _setheaphook(_In_opt_ _HEAPHOOK _NewHook);

'/* hook function must handle these types */
%HEAP_MALLOC   = 1
%HEAP_CALLOC   = 2
%HEAP_FREE     = 3
%HEAP_REALLOC  = 4
%HEAP_MSIZE    = 5
%HEAP_EXPAND   = 6

#ENDIF   ' /* HEAPHOOK */
