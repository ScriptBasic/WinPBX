' ########################################################################################
' Microsoft C Runtime
' File: search.inc
' Contents: Declarations for the sorting and searching routines.
' Copyright (c) 2010 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%SEARCH_INC = 1

#INCLUDE ONCE "crtdefs.inc"

#IF NOT %DEF(%CRT_ALGO_DEFINED)
    %CRT_ALGO_DEFINED = 1

'#if __STDC_WANT_SECURE_LIB__
' ========================================================================================
' _Check_return_ _CRTIMP void * __cdecl bsearch_s(_In_ const void * _Key,
' _In_bytecount_x_(_NumOfElements * _SizeOfElements) const void * _Base,
' _In_ rsize_t _NumOfElements, _In_ rsize_t _SizeOfElements,
' _In_ int (__cdecl * _PtFuncCompare)(void *, const void *, const void *), void * _Context);
' ========================================================================================
DECLARE FUNCTION bsearch_s CDECL IMPORT $CRT_DLLNAME ALIAS "bsearch_s" ( _
   BYREF key AS ANY _                                   ' __in const void *key
 , BYREF base AS ANY _                                  ' __in const void *base
 , BYVAL num AS DWORD _                                 ' __in size_t num
 , BYVAL width AS DWORD _                               ' __in size_t width
 , BYVAL compare AS DWORD _                             ' __in int ( __cdecl *compare ) ( const void *, const void *)
 , BYVAL context AS DWORD _                             ' __in void * context
 ) AS DWORD                                             ' void *
' ========================================================================================
'#endif

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRTIMP void * __cdecl bsearch(_In_ const void * _Key,
' _In_bytecount_x_(_NumOfElements * _SizeOfElements) const void * _Base,
' _In_ size_t _NumOfElements, _In_ size_t _SizeOfElements,
' _In_ int (__cdecl * _PtFuncCompare)(const void *, const void *));
' ========================================================================================
DECLARE FUNCTION bsearch CDECL IMPORT $CRT_DLLNAME ALIAS "bsearch" ( _
   BYREF key AS ANY _                                   ' __in const void *key
 , BYREF base AS ANY _                                  ' __in const void *base
 , BYVAL num AS DWORD _                                 ' __in size_t num
 , BYVAL width AS DWORD _                               ' __in size_t width
 , BYVAL compare AS DWORD _                             ' __in int ( __cdecl *compare ) ( const void *, const void *)
 ) AS DWORD                                             ' void *
' ========================================================================================

'#if __STDC_WANT_SECURE_LIB__
' ========================================================================================
' _CRTIMP void __cdecl qsort_s(_Inout_bytecap_x_(_NumOfElements* _SizeOfElements) void * _Base,
' _In_ rsize_t _NumOfElements, _In_ rsize_t _SizeOfElements,
' _In_ int (__cdecl * _PtFuncCompare)(void *, const void *, const void *), void *_Context);
' ========================================================================================
DECLARE SUB qsort_s CDECL IMPORT $CRT_DLLNAME ALIAS "qsort_s" ( _
   BYREF base AS ANY _                                  ' __in void *base
 , BYVAL num AS DWORD _                                 ' __in size_t num
 , BYVAL width AS DWORD _                               ' __in size_t width
 , BYVAL compare AS DWORD _                             ' __in int (__cdecl *compare )(const void *, const void *)
 , BYVAL context AS DWORD _                             ' __in void * context
 )                                                      ' void
' ========================================================================================
'#endif

' ========================================================================================
' *** All versions ***
' _CRTIMP void __cdecl qsort(_Inout_bytecap_x_(_NumOfElements * _SizeOfElements) void * _Base,
' _In_ size_t _NumOfElements, _In_ size_t _SizeOfElements,
' _In_ int (__cdecl * _PtFuncCompare)(const void *, const void *));
' ========================================================================================
DECLARE SUB qsort CDECL IMPORT $CRT_DLLNAME ALIAS "qsort" ( _
   BYREF base AS ANY _                                  ' __in void *base
 , BYVAL num AS DWORD _                                 ' __in size_t num
 , BYVAL size AS DWORD _                                ' __in size_t width
 , BYVAL compare AS DWORD _                             ' __in int (__cdecl *compare )(const void *, const void *)
 )                                                      ' void
' ========================================================================================

#ENDIF   ' CRT_ALGO_DEFINED

' ========================================================================================
' _Check_return_ _CRTIMP void * __cdecl _lfind_s(_In_ const void * _Key,
' _In_bytecount_x_((*_NumOfElements) * _SizeOfElements) const void * _Base,
' _Inout_ unsigned int * _NumOfElements, _In_ size_t _SizeOfElements,
' _In_ int (__cdecl * _PtFuncCompare)(void *, const void *, const void *), void * _Context);
' ========================================================================================
DECLARE FUNCTION lfind_s CDECL IMPORT $CRT_DLLNAME ALIAS "_lfind_s" ( _
   BYREF key AS ANY _                                   ' __in const void *key
 , BYREF base AS ANY _                                  ' __in const void *base
 , BYREF num AS DWORD _                                 ' __inout unsigned int *num
 , BYVAL width AS DWORD _                               ' __in unsigned int width
 , BYVAL compare AS DWORD _                             ' __in int (__cdecl *compare)(const void *, const void *)
 , BYVAL context AS DWORD _                             ' __in void * context
 ) AS DWORD                                             ' void *
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRTIMP void * __cdecl _lfind(_In_ const void * _Key,
' _In_bytecount_x_((*_NumOfElements) * _SizeOfElements) const void * _Base,
' _Inout_ unsigned int * _NumOfElements, _In_ unsigned int _SizeOfElements,
' _In_ int (__cdecl * _PtFuncCompare)(const void *, const void *));
' ========================================================================================
DECLARE FUNCTION lfind_ CDECL IMPORT $CRT_DLLNAME ALIAS "_lfind" ( _
   BYREF key AS ANY _                                   ' __in const void *key
 , BYREF base AS ANY _                                  ' __in const void *base
 , BYREF num AS DWORD _                                 ' __inout unsigned int *num
 , BYVAL width AS DWORD _                               ' __in unsigned int width
 , BYVAL compare AS DWORD _                             ' __in int (__cdecl *compare)(const void *, const void *)
 ) AS DWORD                                             ' void *
' ========================================================================================

' ========================================================================================
' _Check_return_ _CRTIMP void * __cdecl _lsearch_s(_In_ const void * _Key,
' _Inout_bytecap_x_((*_NumOfElements ) * _SizeOfElements) void  * _Base,
' _Inout_ unsigned int * _NumOfElements, _In_ size_t _SizeOfElements,
' _In_ int (__cdecl * _PtFuncCompare)(void *, const void *, const void *), void * _Context);
' ========================================================================================
DECLARE FUNCTION lsearch_s CDECL IMPORT $CRT_DLLNAME ALIAS "_lsearch_s" ( _
   BYREF key AS ANY _                                   ' __in const void *key
 , BYREF base AS ANY _                                  ' __inout const void *base
 , BYREF num AS DWORD _                                 ' __inout unsigned int *num
 , BYVAL size AS DWORD _                                ' __in size_t int _lsearch_s
 , BYVAL compare AS DWORD _                             ' __in int (__cdecl *compare)(const void *, const void *)
 , BYVAL context AS DWORD _                             ' __in void * context
 ) AS DWORD                                             ' void *
' ========================================================================================

' ========================================================================================
' *** All versions ***
' _Check_return_ _CRTIMP void * __cdecl _lsearch(_In_ const void * _Key,
' _Inout_bytecap_x_((*_NumOfElements ) * _SizeOfElements) void  * _Base,
' _Inout_ unsigned int * _NumOfElements, _In_ unsigned int _SizeOfElements,
' _In_ int (__cdecl * _PtFuncCompare)(const void *, const void *));
' ========================================================================================
DECLARE FUNCTION lsearch_ CDECL IMPORT $CRT_DLLNAME ALIAS "_lsearch" ( _
   BYREF key AS ANY _                                   ' __in const void *key
 , BYREF base AS ANY _                                  ' __inout const void *base
 , BYREF num AS DWORD _                                 ' __inout unsigned int *num
 , BYVAL size AS DWORD _                                ' __in size_t int _lsearch_s
 , BYVAL compare AS DWORD _                             ' __in int (__cdecl *compare)(const void *, const void *)
 ) AS DWORD                                             ' void *
' ========================================================================================
