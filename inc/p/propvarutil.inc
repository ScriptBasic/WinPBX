' ########################################################################################
' Microsoft Windows
' File: propvarutil.inc
' Contents: Variant and PropVariant helpers
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%PROPVARUTIL_INC = 1

'#pragma once

' Note: Use the SUCCEEDED function instead.
'typedef __success(return >= 0) LONG NTSTATUS;
'MACRO success_ (nStatus) = (-(BITS(LONG, nStatus) > = 0))

#INCLUDE ONCE "propapi.inc"
#INCLUDE ONCE "shtypes.inc"
#INCLUDE ONCE "shlwapi.inc"

' enum PSTIME_FLAGS
%PSTF_UTC   = &H00000000&
%PSTF_LOCAL = &H00000001&
'typedef int PSTIME_FLAGS;

'//====================
'//
'// PropVariant Helpers
'//
'//====================

'// Initialize a propvariant
' ========================================================================================
' PSSTDAPI InitPropVariantFromResource(__in HINSTANCE hinst, __in UINT id, __out PROPVARIANT *ppropvar);
' ========================================================================================
DECLARE FUNCTION InitPropVariantFromResource IMPORT "PROPSYS.DLL" ALIAS "InitPropVariantFromResource" ( _
   BYVAL hinst AS DWORD _                               ' __in  HINSTANCE hinst
 , BYVAL id AS DWORD _                                  ' __in  UINT id
 , BYREF ppropvar AS ANY _                              ' __out PROPVARIANT *ppropvar
 ) AS LONG                                              ' HRESULT

' ========================================================================================
' PSSTDAPI InitPropVariantFromBuffer(__in_bcount(cb) const void *pv, __in UINT cb, __out PROPVARIANT *ppropvar);
' ========================================================================================
DECLARE FUNCTION InitPropVariantFromBuffer IMPORT "PROPSYS.DLL" ALIAS "InitPropVariantFromBuffer" ( _
   BYREF pv AS ANY _                                    ' __in  const void *pv
 , BYVAL cb AS DWORD _                                  ' __in  UINT cb
 , BYREF ppropvar AS ANY _                              ' __out PROPVARIANT *ppropvar
 ) AS LONG                                              ' HRESULT

' ========================================================================================
' PSSTDAPI InitPropVariantFromCLSID(__in REFCLSID clsid, __out PROPVARIANT *ppropvar);
' ========================================================================================
DECLARE FUNCTION InitPropVariantFromCLSID IMPORT "PROPSYS.DLL" ALIAS "InitPropVariantFromCLSID" ( _
   BYREF clsid AS GUID _                                ' __in  REFCLSID clsid
 , BYREF ppropvar AS ANY _                              ' __out PROPVARIANT *ppropvar
 ) AS LONG                                              ' HRESULT

' ========================================================================================
' PSSTDAPI InitPropVariantFromGUIDAsString(__in REFGUID guid, __out PROPVARIANT *ppropvar);
' ========================================================================================
DECLARE FUNCTION InitPropVariantFromGUIDAsString IMPORT "PROPSYS.DLL" ALIAS "InitPropVariantFromGUIDAsString" ( _
   BYREF guid AS GUID _                                 ' __in  REFGUID guid
 , BYREF ppropvar AS ANY _                              ' __out PROPVARIANT *ppropvar
 ) AS LONG                                              ' HRESULT

' ========================================================================================
' PSSTDAPI InitPropVariantFromFileTime(__in const FILETIME *pftIn, __out PROPVARIANT *ppropvar);
' ========================================================================================
DECLARE FUNCTION InitPropVariantFromFileTime IMPORT "PROPSYS.DLL" ALIAS "InitPropVariantFromFileTime" ( _
   BYREF pft AS FILETIME _                              ' __in  const FILETIME *pft
 , BYREF ppropvar AS ANY _                              ' __out PROPVARIANT *ppropvar
 ) AS LONG                                              ' HRESULT

' ========================================================================================
' PSSTDAPI InitPropVariantFromPropVariantVectorElem(__in REFPROPVARIANT propvarIn, __in ULONG iElem, __out PROPVARIANT *ppropvar);
' ========================================================================================
DECLARE FUNCTION InitPropVariantFromPropVariantVectorElem IMPORT "PROPSYS.DLL" ALIAS "InitPropVariantFromPropVariantVectorElem" ( _
   BYREF propvarIn AS ANY _                             ' __in  REFPROPVARIANT propvarIn
 , BYVAL iElem AS DWORD _                               ' __in  ULONG iElem
 , BYREF ppropvar AS ANY _                              ' __out PROPVARIANT *ppropvar
 ) AS LONG                                              ' HRESULT

' ========================================================================================
' PSSTDAPI InitPropVariantVectorFromPropVariant(__in REFPROPVARIANT propvarSingle, __out PROPVARIANT *ppropvarVector);
' ========================================================================================
DECLARE FUNCTION InitPropVariantVectorFromPropVariant IMPORT "PROPSYS.DLL" ALIAS "InitPropVariantVectorFromPropVariant" ( _
   BYREF propvarSingle AS ANY _                         ' __in  REFPROPVARIANT propvarSingle
 , BYREF ppropvarVector AS ANY _                        ' __out PROPVARIANT *ppropvarVector
 ) AS LONG                                              ' HRESULT

' ========================================================================================
' PSSTDAPI InitPropVariantFromStrRet(__inout STRRET *pstrret, __in_opt PCUITEMID_CHILD pidl, __out PROPVARIANT *ppropvar);
' ========================================================================================
DECLARE FUNCTION InitPropVariantFromStrRet IMPORT "PROPSYS.DLL" ALIAS "InitPropVariantFromStrRet" ( _
   BYREF pstrret AS STRRET _                            ' __in  STRRET *pstrret
 , BYVAL pidl AS DWORD _                                ' __in_opt  PCUITEMID_CHILD pidl
 , BYREF ppropvar AS ANY _                              ' __out PROPVARIANT *ppropvar
 ) AS LONG                                              ' HRESULT

' ========================================================================================
' PSSTDAPI InitPropVariantFromBooleanVector(__in_ecount_opt(cElems) const BOOL *prgf, __in ULONG cElems, __out PROPVARIANT *ppropvar);
' ========================================================================================
DECLARE FUNCTION InitPropVariantFromBooleanVector IMPORT "PROPSYS.DLL" ALIAS "InitPropVariantFromBooleanVector" ( _
   BYREF prgf AS LONG _                                 ' __in _ecount_opt(cElems) const BOOL *prgf
 , BYVAL cElems AS DWORD _                              ' __in  ULONG cElems
 , BYREF ppropvar AS ANY _                              ' __out PROPVARIANT *ppropvar
 ) AS LONG                                              ' HRESULT

' ========================================================================================
' PSSTDAPI InitPropVariantFromInt16Vector(__in_ecount_opt(cElems) const SHORT *prgn, __in ULONG cElems, __out PROPVARIANT *ppropvar);
' ========================================================================================
DECLARE FUNCTION InitPropVariantFromInt16Vector IMPORT "PROPSYS.DLL" ALIAS "InitPropVariantFromInt16Vector" ( _
   BYREF prgn AS INTEGER _                              ' __in_ ecount_opt(cElems) const SHORT *prgn
 , BYVAL cElems AS DWORD _                              ' __in  ULONG cElems
 , BYREF ppropvar AS ANY _                              ' __out PROPVARIANT *ppropvar
 ) AS LONG                                              ' HRESULT

' ========================================================================================
' PSSTDAPI InitPropVariantFromUInt16Vector(__in_ecount_opt(cElems) const USHORT *prgn, __in ULONG cElems, __out PROPVARIANT *ppropvar);
' ========================================================================================
DECLARE FUNCTION InitPropVariantFromUInt16Vector IMPORT "PROPSYS.DLL" ALIAS "InitPropVariantFromUInt16Vector" ( _
   BYREF prgn AS WORD _                                 ' __in_ecount_opt(cElems) const USHORT *prgn
 , BYVAL cElems AS DWORD _                              ' __in  ULONG cElems
 , BYREF ppropvar AS ANY _                              ' __out PROPVARIANT *ppropvar
 ) AS LONG                                              ' HRESULT

' ========================================================================================
' PSSTDAPI InitPropVariantFromInt32Vector(__in_ecount_opt(cElems) const LONG *prgn, __in ULONG cElems, __out PROPVARIANT *ppropvar);
' ========================================================================================
DECLARE FUNCTION InitPropVariantFromInt32Vector IMPORT "PROPSYS.DLL" ALIAS "InitPropVariantFromInt32Vector" ( _
   BYREF prgn AS LONG _                                 ' __in_ ecount_opt(cElems) const LONG *prgn
 , BYVAL cElems AS DWORD _                              ' __in  ULONG cElems
 , BYREF ppropvar AS ANY _                              ' __out PROPVARIANT *ppropvar
 ) AS LONG                                              ' HRESULT

' ========================================================================================
' PSSTDAPI InitPropVariantFromUInt32Vector(__in_ecount_opt(cElems) const ULONG *prgn, __in ULONG cElems, __out PROPVARIANT *ppropvar);
' ========================================================================================
DECLARE FUNCTION InitPropVariantFromUInt32Vector IMPORT "PROPSYS.DLL" ALIAS "InitPropVariantFromUInt32Vector" ( _
   BYREF prgn AS DWORD _                                ' __in_ecount_opt(cElems) const ULONG *prgn
 , BYVAL cElems AS DWORD _                              ' __in  ULONG cElems
 , BYREF ppropvar AS ANY _                              ' __out PROPVARIANT *ppropvar
 ) AS LONG                                              ' HRESULT

' ========================================================================================
' PSSTDAPI InitPropVariantFromInt64Vector(__in_ecount_opt(cElems) const LONGLONG *prgn, __in ULONG cElems, __out PROPVARIANT *ppropvar);
' ========================================================================================
DECLARE FUNCTION InitPropVariantFromInt64Vector IMPORT "PROPSYS.DLL" ALIAS "InitPropVariantFromInt64Vector" ( _
   BYREF prgn AS QUAD _                                 ' __in_ecount_opt(cElems) const LONGLONG *prgn
 , BYVAL cElems AS DWORD _                              ' __in  ULONG cElems
 , BYREF ppropvar AS ANY _                              ' __out PROPVARIANT *ppropvar
 ) AS LONG                                              ' HRESULT

' PB doesn't currently support unsigned quads.
' PSSTDAPI InitPropVariantFromUInt64Vector(__in_ecount_opt(cElems) const ULONGLONG *prgn, __in ULONG cElems, __out PROPVARIANT *ppropvar);

' ========================================================================================
' PSSTDAPI InitPropVariantFromDoubleVector(__in_ecount_opt(cElems) const DOUBLE *prgn, __in ULONG cElems, __out PROPVARIANT *ppropvar);
' ========================================================================================
DECLARE FUNCTION InitPropVariantFromDoubleVector IMPORT "PROPSYS.DLL" ALIAS "InitPropVariantFromDoubleVector" ( _
   BYREF prgn AS DOUBLE _                               ' __in_ecount_opt(cElems) const DOUBLE *prgn
 , BYVAL cElems AS DWORD _                              ' __in  ULONG cElems
 , BYREF ppropvar AS ANY _                              ' __out PROPVARIANT *ppropvar
 ) AS LONG                                              ' HRESULT

' ========================================================================================
' PSSTDAPI InitPropVariantFromFileTimeVector(__in_ecount_opt(cElems) const FILETIME *prgft, __in ULONG cElems, __out PROPVARIANT *ppropvar);
' ========================================================================================
DECLARE FUNCTION InitPropVariantFromFileTimeVector IMPORT "PROPSYS.DLL" ALIAS "InitPropVariantFromFileTimeVector" ( _
   BYREF prgft AS FILETIME _                            ' __in_ecount_opt(cElems) const FILETIME *prgft
 , BYVAL cElems AS DWORD _                              ' __in  ULONG cElems
 , BYREF ppropvar AS ANY _                              ' __out PROPVARIANT *ppropvar
 ) AS LONG                                              ' HRESULT

' ========================================================================================
' PSSTDAPI InitPropVariantFromStringVector(__in_ecount_opt(cElems) PCWSTR *prgsz, __in ULONG cElems, __out PROPVARIANT *ppropvar);
' ========================================================================================
DECLARE FUNCTION InitPropVariantFromStringVector IMPORT "PROPSYS.DLL" ALIAS "InitPropVariantFromStringVector" ( _
   BYREF prgsz AS ANY _                                 ' __in_ecount_opt(cElems) PCWSTR *prgsz
 , BYVAL cElems AS DWORD _                              ' __in  ULONG cElems
 , BYREF ppropvar AS ANY _                              ' __out PROPVARIANT *ppropvar
 ) AS LONG                                              ' HRESULT

' ========================================================================================
' PSSTDAPI InitPropVariantFromStringAsVector(__in_opt PCWSTR psz, __out PROPVARIANT *ppropvar);
' ========================================================================================
DECLARE FUNCTION InitPropVariantFromStringAsVector IMPORT "PROPSYS.DLL" ALIAS "InitPropVariantFromStringAsVector" ( _
   BYREF psz AS WSTRINGZ _                              ' __in_opt PCWSTR psz
 , BYREF ppropvar AS ANY _                              ' __out PROPVARIANT *ppropvar
 ) AS LONG                                              ' HRESULT

'#ifdef __cplusplus
'HRESULT  InitPropVariantFromBoolean(__in BOOL fVal, __out PROPVARIANT *ppropvar);
'HRESULT  InitPropVariantFromInt16(__in SHORT nVal, __out PROPVARIANT *ppropvar);
'HRESULT  InitPropVariantFromUInt16(__in USHORT uiVal, __out PROPVARIANT *ppropvar);
'HRESULT  InitPropVariantFromInt32(__in LONG lVal, __out PROPVARIANT *ppropvar);
'HRESULT  InitPropVariantFromUInt32(__in ULONG ulVal, __out PROPVARIANT *ppropvar);
'HRESULT  InitPropVariantFromInt64(__in LONGLONG llVal, __out PROPVARIANT *ppropvar);
'HRESULT  InitPropVariantFromUInt64(__in ULONGLONG ullVal, __out PROPVARIANT *ppropvar);
'HRESULT  InitPropVariantFromDouble(__in DOUBLE dblVal, __out PROPVARIANT *ppropvar);
'HRESULT  InitPropVariantFromString(__in PCWSTR psz, __out PROPVARIANT *ppropvar);
'HRESULT  InitPropVariantFromGUIDAsBuffer(__in REFGUID guid, __out PROPVARIANT *ppropvar);
'BOOL     IsPropVariantVector(__in REFPROPVARIANT propvar);
'BOOL     IsPropVariantString(__in REFPROPVARIANT propvar);
'#endif

'// Extract data from a propvariant

' ========================================================================================
' PSSTDAPI_(BOOL)      PropVariantToBooleanWithDefault(__in REFPROPVARIANT propvarIn, __in BOOL fDefault);
' ========================================================================================
DECLARE FUNCTION PropVariantToBooleanWithDefault IMPORT "PROPSYS.DLL" ALIAS "PropVariantToBooleanWithDefault" ( _
   BYREF propvarIn AS ANY _                             ' __in REFPROPVARIANT propvarIn
 , BYVAL fDefault AS LONG _                             ' __in BOOL fDefault
 ) AS LONG                                              ' BOOL

' ========================================================================================
' PSSTDAPI_(SHORT)     PropVariantToInt16WithDefault(__in REFPROPVARIANT propvarIn, __in SHORT iDefault);
' ========================================================================================
DECLARE FUNCTION PropVariantToInt16WithDefault IMPORT "PROPSYS.DLL" ALIAS "PropVariantToInt16WithDefault" ( _
   BYREF propvarIn AS ANY _                             ' __in REFPROPVARIANT propvarIn
 , BYVAL iDefault AS INTEGER _                          ' __in SHORT iDefault
 ) AS INTEGER                                           ' SHORT

' ========================================================================================
' PSSTDAPI_(USHORT)    PropVariantToUInt16WithDefault(__in REFPROPVARIANT propvarIn, __in USHORT uiDefault);
' ========================================================================================
DECLARE FUNCTION PropVariantToUInt16WithDefault IMPORT "PROPSYS.DLL" ALIAS "PropVariantToUInt16WithDefault" ( _
   BYREF propvarIn AS ANY _                             ' __in REFPROPVARIANT propvarIn
 , BYVAL uiDefault AS WORD _                            ' __in USHORT uiDefault
 ) AS WORD                                              ' USHORT

' ========================================================================================
' PSSTDAPI_(LONG)      PropVariantToInt32WithDefault(__in REFPROPVARIANT propvarIn, __in LONG lDefault);
' ========================================================================================
DECLARE FUNCTION PropVariantToInt32WithDefault IMPORT "PROPSYS.DLL" ALIAS "PropVariantToInt32WithDefault" ( _
   BYREF propvarIn AS ANY _                             ' __in REFPROPVARIANT propvarIn
 , BYVAL lDefault AS LONG _                             ' __in LONG lDefault
 ) AS LONG                                              ' LONG

' ========================================================================================
' PSSTDAPI_(ULONG)     PropVariantToUInt32WithDefault(__in REFPROPVARIANT propvarIn, __in ULONG ulDefault);
' ========================================================================================
DECLARE FUNCTION PropVariantToUInt32WithDefault IMPORT "PROPSYS.DLL" ALIAS "PropVariantToUInt32WithDefault" ( _
   BYREF propvarIn AS ANY _                             ' __in REFPROPVARIANT propvarIn
 , BYVAL ulDefault AS DWORD _                           ' __in ULONG ulDefault
 ) AS DWORD                                             ' ULONG

' ========================================================================================
' PSSTDAPI_(LONGLONG)  PropVariantToInt64WithDefault(__in REFPROPVARIANT propvarIn, __in LONGLONG llDefault);
' ========================================================================================
DECLARE FUNCTION PropVariantToInt64WithDefault IMPORT "PROPSYS.DLL" ALIAS "PropVariantToInt64WithDefault" ( _
   BYREF propvarIn AS ANY _                             ' __in REFPROPVARIANT propvarIn
 , BYVAL llDefault AS QUAD _                            ' __in LONGLONG llDefault
 ) AS QUAD                                              ' LONGLONG

' PB doesn't currently support unsigned quads.
' PSSTDAPI_(ULONGLONG) PropVariantToUInt64WithDefault(__in REFPROPVARIANT propvarIn, __in ULONGLONG ullDefault);

' ========================================================================================
' PSSTDAPI_(DOUBLE)    PropVariantToDoubleWithDefault(__in REFPROPVARIANT propvarIn, __in DOUBLE dblDefault);
' ========================================================================================
DECLARE FUNCTION PropVariantToDoubleWithDefault IMPORT "PROPSYS.DLL" ALIAS "PropVariantToDoubleWithDefault" ( _
   BYREF propvarIn AS ANY _                             ' __in REFPROPVARIANT propvarIn
 , BYVAL dblDefault AS DOUBLE _                         ' __in DOUBLE dblDefault
 ) AS DOUBLE                                            ' DOUBLE

' ========================================================================================
' PSSTDAPI_(PCWSTR)    PropVariantToStringWithDefault(__in REFPROPVARIANT propvarIn, __in_opt LPCWSTR pszDefault);
' ========================================================================================
DECLARE FUNCTION PropVariantToStringWithDefault IMPORT "PROPSYS.DLL" ALIAS "PropVariantToStringWithDefault" ( _
   BYREF propvarIn AS ANY _                             ' __in REFPROPVARIANT propvarIn
 , OPTIONAL BYREF pszDefault AS WSTRINGZ _              ' __in_opt LPCWSTR pszDefault
 ) AS DWORD                                             ' PCWSTR

' ========================================================================================
' PSSTDAPI             PropVariantToBoolean(__in REFPROPVARIANT propvarIn, __out BOOL *pfRet);
' ========================================================================================
DECLARE FUNCTION PropVariantToBoolean IMPORT "PROPSYS.DLL" ALIAS "PropVariantToBoolean" ( _
   BYREF propvarIn AS ANY _                             ' __in  REFPROPVARIANT propvarIn
 , BYREF pfRet AS LONG _                                ' __out BOOL *pfRet
 ) AS LONG                                              ' HRESULT

' ========================================================================================
' PSSTDAPI             PropVariantToInt16(__in REFPROPVARIANT propvarIn, __out SHORT *piRet);
' ========================================================================================
DECLARE FUNCTION PropVariantToInt16 IMPORT "PROPSYS.DLL" ALIAS "PropVariantToInt16" ( _
   BYREF propvarIn AS ANY _                             ' __in  REFPROPVARIANT propvarIn
 , BYREF piRet AS INTEGER _                             ' __out SHORT *piRet
 ) AS LONG                                              ' HRESULT

' ========================================================================================
' PSSTDAPI             PropVariantToUInt16(__in REFPROPVARIANT propvarIn, __out USHORT *puiRet);
' ========================================================================================
DECLARE FUNCTION PropVariantToUInt16 IMPORT "PROPSYS.DLL" ALIAS "PropVariantToUInt16" ( _
   BYREF propvarIn AS ANY _                             ' __in  REFPROPVARIANT propvarIn
 , BYREF puiRet AS WORD _                               ' __out USHORT *puiRet
 ) AS LONG                                              ' HRESULT

' ========================================================================================
' PSSTDAPI             PropVariantToInt32(__in REFPROPVARIANT propvarIn, __out LONG *plRet);
' ========================================================================================
DECLARE FUNCTION PropVariantToInt32 IMPORT "PROPSYS.DLL" ALIAS "PropVariantToInt32" ( _
   BYREF propvarIn AS ANY _                             ' __in  REFPROPVARIANT propvarIn
 , BYREF plRet AS LONG _                                ' __out LONG *plRet
 ) AS LONG                                              ' HRESULT

' ========================================================================================
' PSSTDAPI             PropVariantToUInt32(__in REFPROPVARIANT propvarIn, __out ULONG *pulRet);
' ========================================================================================
DECLARE FUNCTION PropVariantToUInt32 IMPORT "PROPSYS.DLL" ALIAS "PropVariantToUInt32" ( _
   BYREF propvarIn AS ANY _                             ' __in  REFPROPVARIANT propvarIn
 , BYREF pulRet AS DWORD _                              ' __out ULONG *pulRet
 ) AS LONG                                              ' HRESULT

' ========================================================================================
' PSSTDAPI             PropVariantToInt64(__in REFPROPVARIANT propvarIn, __out LONGLONG *pllRet);
' ========================================================================================
DECLARE FUNCTION PropVariantToInt64 IMPORT "PROPSYS.DLL" ALIAS "PropVariantToInt64" ( _
   BYREF propvarIn AS ANY _                             ' __in  REFPROPVARIANT propvarIn
 , BYREF pllRet AS QUAD _                               ' __out LONGLONG *pllRet
 ) AS LONG                                              ' HRESULT

' PB doesn't currently support unsigned quads.
' PSSTDAPI             PropVariantToUInt64(__in REFPROPVARIANT propvarIn, __out ULONGLONG *pullRet);

' ========================================================================================
' PSSTDAPI             PropVariantToDouble(__in REFPROPVARIANT propvarIn, __out DOUBLE *pdblRet);
' ========================================================================================
DECLARE FUNCTION PropVariantToDouble IMPORT "PROPSYS.DLL" ALIAS "PropVariantToDouble" ( _
   BYREF propvarIn AS ANY _                             ' __in  REFPROPVARIANT propvarIn
 , BYREF pdblRet AS DOUBLE _                            ' __out DOUBLE *pdblRet
 ) AS LONG                                              ' HRESULT

' ========================================================================================
' PSSTDAPI             PropVariantToBuffer(__in REFPROPVARIANT propvar, __out_bcount(cb) void *pv, __in UINT cb);
' ========================================================================================
DECLARE FUNCTION PropVariantToBuffer IMPORT "PROPSYS.DLL" ALIAS "PropVariantToBuffer" ( _
   BYREF propvar AS ANY _                               ' __in  REFPROPVARIANT propvar
 , BYREF pv AS ANY _                                    ' __out void *pv
 , BYVAL cb AS DWORD _                                  ' __in  UINT cb
 ) AS LONG                                              ' HRESULT

' ========================================================================================
' PSSTDAPI             PropVariantToString(__in REFPROPVARIANT propvar, __out_ecount(cch) PWSTR psz, __in UINT cch);
' ========================================================================================
DECLARE FUNCTION PropVariantToString IMPORT "PROPSYS.DLL" ALIAS "PropVariantToString" ( _
   BYREF propvar AS ANY _                               ' __in  REFPROPVARIANT propvar
 , BYREF pszBuf AS WSTRINGZ _                           ' __out PWSTR pszBuf
 , BYVAL cchBuf AS DWORD _                              ' __in  UINT cchBuf
 ) AS LONG                                              ' HRESULT

' ========================================================================================
' PSSTDAPI             PropVariantToGUID(__in REFPROPVARIANT propvar, __out GUID *pguid);
' ========================================================================================
DECLARE FUNCTION PropVariantToGUID IMPORT "PROPSYS.DLL" ALIAS "PropVariantToGUID" ( _
   BYREF propvar AS ANY _                               ' __in  REFPROPVARIANT propvar
 , BYREF pguid AS GUID _                                ' __out GUID *pguid
 ) AS LONG                                              ' HRESULT

' ========================================================================================
' __checkReturn PSSTDAPI PropVariantToStringAlloc(__in REFPROPVARIANT propvar, __deref_out PWSTR *ppszOut);
' ========================================================================================
DECLARE FUNCTION PropVariantToStringAlloc IMPORT "PROPSYS.DLL" ALIAS "PropVariantToStringAlloc" ( _
   BYREF propvar AS ANY _                               ' __in  REFPROPVARIANT propvar
 , BYREF ppszBuf AS DWORD _                             ' __out PWSTR *ppszBuf
 ) AS LONG                                              ' HRESULT

' ========================================================================================
' __checkReturn PSSTDAPI PropVariantToBSTR(__in REFPROPVARIANT propvar, __deref_out BSTR *pbstrOut);
' ========================================================================================
DECLARE FUNCTION PropVariantToBSTR IMPORT "PROPSYS.DLL" ALIAS "PropVariantToBSTR" ( _
   BYREF propvar AS ANY _                               ' __in  REFPROPVARIANT propvar
 , BYREF pbstrOut AS WSTRING _                          ' __out BSTR *pbstrOut
 ) AS LONG                                              ' HRESULT

' ========================================================================================
' __checkReturn PSSTDAPI PropVariantToStrRet(__in REFPROPVARIANT propvar, __out STRRET *pstrret);
' ========================================================================================
DECLARE FUNCTION PropVariantToStrRet IMPORT "PROPSYS.DLL" ALIAS "PropVariantToStrRet" ( _
   BYREF propvar AS ANY _                               ' __in  REFPROPVARIANT propvar
 , BYREF pstrret AS STRRET _                            ' __out STRRET *pstrret
 ) AS LONG                                              ' HRESULT

' ========================================================================================
' PSSTDAPI             PropVariantToFileTime(__in REFPROPVARIANT propvar, __in PSTIME_FLAGS pstfOut, __out FILETIME* pftOut);
' ========================================================================================
DECLARE FUNCTION PropVariantToFileTime IMPORT "PROPSYS.DLL" ALIAS "PropVariantToFileTime" ( _
   BYREF propvar AS ANY _                               ' __in  REFPROPVARIANT propvar
 , BYVAL pstfOut AS DWORD _                             ' __in  PSTIME_FLAGS pstfOut
 , BYREF pftOut AS FILETIME _                           ' __out FILETIME* pftOut
 ) AS LONG                                              ' HRESULT

'#ifdef __cplusplus
'HRESULT              PropVariantToCLSID(__in REFPROPVARIANT propvar, __out CLSID *pclsid);
'#endif


' ========================================================================================
' Returns element count of a VT_VECTOR or VT_ARRAY value; or 1 otherwise
' PSSTDAPI_(ULONG) PropVariantGetElementCount(__in REFPROPVARIANT propvar);
' ========================================================================================
DECLARE FUNCTION PropVariantGetElementCount IMPORT "PROPSYS.DLL" ALIAS "PropVariantGetElementCount" ( _
   BYREF propvar AS ANY _                               ' __in REFPROPVARIANT propvar
 ) AS DWORD                                             ' ULONG

'// Extract data from a propvariant into a vector

' ========================================================================================
' PSSTDAPI PropVariantToBooleanVector(__in REFPROPVARIANT propvar, __out_ecount_part(crgf, *pcElem) BOOL *prgf, __in ULONG crgf, __out ULONG *pcElem);
' ========================================================================================
DECLARE FUNCTION PropVariantToBooleanVector IMPORT "PROPSYS.DLL" ALIAS "PropVariantToBooleanVector" ( _
   BYREF propvar AS ANY _                               ' __in  REFPROPVARIANT propvar
 , BYREF prgf AS LONG _                                 ' __out BOOL *prgf
 , BYVAL crgf AS DWORD _                                ' __in  ULONG crgf
 , BYREF pcElem AS DWORD _                              ' __out ULONG *pcElem
 ) AS LONG                                              ' HRESULT

' ========================================================================================
' PSSTDAPI PropVariantToInt16Vector(__in REFPROPVARIANT propvar, __out_ecount_part(crgn, *pcElem) SHORT *prgn, __in ULONG crgn, __out ULONG *pcElem);
' ========================================================================================
DECLARE FUNCTION PropVariantToInt16Vector IMPORT "PROPSYS.DLL" ALIAS "PropVariantToInt16Vector" ( _
   BYREF propvar AS ANY _                               ' __in  REFPROPVARIANT propvar
 , BYREF prgn AS INTEGER _                              ' __out SHORT *prgn
 , BYVAL crgn AS DWORD _                                ' __in  ULONG crgn
 , BYREF pcElem AS DWORD _                              ' __out ULONG *pcElem
 ) AS LONG                                              ' HRESULT

' ========================================================================================
' PSSTDAPI PropVariantToUInt16Vector(__in REFPROPVARIANT propvar, __out_ecount_part(crgn, *pcElem) USHORT *prgn, __in ULONG crgn, __out ULONG *pcElem);
' ========================================================================================
DECLARE FUNCTION PropVariantToUInt16Vector IMPORT "PROPSYS.DLL" ALIAS "PropVariantToUInt16Vector" ( _
   BYREF propvar AS ANY _                               ' __in  REFPROPVARIANT propvar
 , BYREF prgn AS WORD _                                 ' __out USHORT *prgn
 , BYVAL crgn AS DWORD _                                ' __in  ULONG crgn
 , BYREF pcElem AS DWORD _                              ' __out ULONG *pcElem
 ) AS LONG                                              ' HRESULT

' ========================================================================================
' PSSTDAPI PropVariantToInt32Vector(__in REFPROPVARIANT propvar, __out_ecount_part(crgn, *pcElem) LONG *prgn, __in ULONG crgn, __out ULONG *pcElem);
' ========================================================================================
DECLARE FUNCTION PropVariantToInt32Vector IMPORT "PROPSYS.DLL" ALIAS "PropVariantToInt32Vector" ( _
   BYREF propvar AS ANY _                               ' __in  REFPROPVARIANT propvar
 , BYREF prgn AS LONG _                                 ' __out LONG *prgn
 , BYVAL crgn AS DWORD _                                ' __in  ULONG crgn
 , BYREF pcElem AS DWORD _                              ' __out ULONG *pcElem
 ) AS LONG                                              ' HRESULT

' ========================================================================================
' PSSTDAPI PropVariantToUInt32Vector(__in REFPROPVARIANT propvar, __out_ecount_part(crgn, *pcElem) ULONG *prgn, __in ULONG crgn, __out ULONG *pcElem);
' ========================================================================================
DECLARE FUNCTION PropVariantToUInt32Vector IMPORT "PROPSYS.DLL" ALIAS "PropVariantToUInt32Vector" ( _
   BYREF propvar AS ANY _                               ' __in  REFPROPVARIANT propvar
 , BYREF prgn AS DWORD _                                ' __out ULONG *prgn
 , BYVAL crgn AS DWORD _                                ' __in  ULONG crgn
 , BYREF pcElem AS DWORD _                              ' __out ULONG *pcElem
 ) AS LONG                                              ' HRESULT

' ========================================================================================
' PSSTDAPI PropVariantToInt64Vector(__in REFPROPVARIANT propvar, __out_ecount_part(crgn, *pcElem) LONGLONG *prgn, __in ULONG crgn, __out ULONG *pcElem);
' ========================================================================================
DECLARE FUNCTION PropVariantToInt64Vector IMPORT "PROPSYS.DLL" ALIAS "PropVariantToInt64Vector" ( _
   BYREF propvar AS ANY _                               ' __in  REFPROPVARIANT propvar
 , BYREF prgn AS QUAD _                                 ' __out LONGLONG *prgn
 , BYVAL crgn AS DWORD _                                ' __in  ULONG crgn
 , BYREF pcElem AS DWORD _                              ' __out ULONG *pcElem
 ) AS LONG                                              ' HRESULT

' PB doesn't currently support unsigned quads.
' PSSTDAPI PropVariantToUInt64Vector(__in REFPROPVARIANT propvar, __out_ecount_part(crgn, *pcElem) ULONGLONG *prgn, __in ULONG crgn, __out ULONG *pcElem);

' ========================================================================================
' PSSTDAPI PropVariantToDoubleVector(__in REFPROPVARIANT propvar, __out_ecount_part(crgn, *pcElem) DOUBLE *prgn, __in ULONG crgn, __out ULONG *pcElem);
' ========================================================================================
DECLARE FUNCTION PropVariantToDoubleVector IMPORT "PROPSYS.DLL" ALIAS "PropVariantToDoubleVector" ( _
   BYREF propvar AS ANY _                               ' __in  REFPROPVARIANT propvar
 , BYREF prgn AS DOUBLE _                               ' __out DOUBLE *prgn
 , BYVAL crgn AS DWORD _                                ' __in  ULONG crgn
 , BYREF pcElem AS DWORD _                              ' __out ULONG *pcElem
 ) AS LONG                                              ' HRESULT

' ========================================================================================
' PSSTDAPI PropVariantToFileTimeVector(__in REFPROPVARIANT propvar, __out_ecount_part(crgft, *pcElem) FILETIME *prgft, __in ULONG crgft, __out ULONG *pcElem);
' ========================================================================================
DECLARE FUNCTION PropVariantToFileTimeVector IMPORT "PROPSYS.DLL" ALIAS "PropVariantToFileTimeVector" ( _
   BYREF propvar AS ANY _                               ' __in  REFPROPVARIANT propvar
 , BYREF prgn AS FILETIME _                             ' __out FILETIME *prgn
 , BYVAL crgn AS DWORD _                                ' __in  ULONG crgn
 , BYREF pcElem AS DWORD _                              ' __out ULONG *pcElem
 ) AS LONG                                              ' HRESULT

' ========================================================================================
' __checkReturn PSSTDAPI PropVariantToStringVector(__in REFPROPVARIANT propvar, __out_ecount_part(crgsz, *pcElem) PWSTR *prgsz, __in ULONG crgsz, __out ULONG *pcElem);
' ========================================================================================
DECLARE FUNCTION PropVariantToStringVector IMPORT "PROPSYS.DLL" ALIAS "PropVariantToStringVector" ( _
   BYREF propvar AS ANY _                               ' __in  REFPROPVARIANT propvar
 , BYREF prgsz AS ANY _                                 ' __out PWSTR *prgsz
 , BYVAL crgsz AS DWORD _                               ' __in  ULONG crgsz
 , BYREF pcElem AS DWORD _                              ' __out ULONG *pcElem
 ) AS LONG                                              ' HRESULT

'// Extract data from a propvariant and return an newly allocated vector (free with CoTaskMemFree)

' ========================================================================================
' __checkReturn PSSTDAPI PropVariantToBooleanVectorAlloc(__in REFPROPVARIANT propvar, __deref_out_ecount(*pcElem) BOOL **pprgf, __out ULONG *pcElem);
' ========================================================================================
DECLARE FUNCTION PropVariantToBooleanVectorAlloc IMPORT "PROPSYS.DLL" ALIAS "PropVariantToBooleanVectorAlloc" ( _
   BYREF propvar AS ANY _                               ' __in  REFPROPVARIANT propvar
 , BYREF pprgf AS ANY _                                 ' __out BOOL **pprgf
 , BYREF pcElem AS DWORD _                              ' __out ULONG *pcElem
 ) AS LONG                                              ' HRESULT

' ========================================================================================
' __checkReturn PSSTDAPI PropVariantToInt16VectorAlloc(__in REFPROPVARIANT propvar, __deref_out_ecount(*pcElem) SHORT **pprgn, __out ULONG *pcElem);
' ========================================================================================
DECLARE FUNCTION PropVariantToInt16VectorAlloc IMPORT "PROPSYS.DLL" ALIAS "PropVariantToInt16VectorAlloc" ( _
   BYREF propvar AS ANY _                               ' __in  REFPROPVARIANT propvar
 , BYREF pprgn AS ANY _                                 ' __out SHORT **pprgn
 , BYREF pcElem AS DWORD _                              ' __out ULONG *pcElem
 ) AS LONG                                              ' HRESULT

' ========================================================================================
' __checkReturn PSSTDAPI PropVariantToUInt16VectorAlloc(__in REFPROPVARIANT propvar, __deref_out_ecount(*pcElem) USHORT **pprgn, __out ULONG *pcElem);
' ========================================================================================
DECLARE FUNCTION PropVariantToUInt16VectorAlloc IMPORT "PROPSYS.DLL" ALIAS "PropVariantToUInt16VectorAlloc" ( _
   BYREF propvar AS ANY _                               ' __in  REFPROPVARIANT propvar
 , BYREF pprgn AS ANY _                                 ' __out USHORT **pprgn
 , BYREF pcElem AS DWORD _                              ' __out ULONG *pcElem
 ) AS LONG                                              ' HRESULT

' ========================================================================================
' __checkReturn PSSTDAPI PropVariantToInt32VectorAlloc(__in REFPROPVARIANT propvar, __deref_out_ecount(*pcElem) LONG **pprgn, __out ULONG *pcElem);
' ========================================================================================
DECLARE FUNCTION PropVariantToInt32VectorAlloc IMPORT "PROPSYS.DLL" ALIAS "PropVariantToInt32VectorAlloc" ( _
   BYREF propvar AS ANY _                               ' __in  REFPROPVARIANT propvar
 , BYREF pprgn AS ANY _                                 ' __out LONG **pprgn
 , BYREF pcElem AS DWORD _                              ' __out ULONG *pcElem
 ) AS LONG                                              ' HRESULT

' ========================================================================================
' __checkReturn PSSTDAPI PropVariantToUInt32VectorAlloc(__in REFPROPVARIANT propvar, __deref_out_ecount(*pcElem) ULONG **pprgn, __out ULONG *pcElem);
' ========================================================================================
DECLARE FUNCTION PropVariantToUInt32VectorAlloc IMPORT "PROPSYS.DLL" ALIAS "PropVariantToUInt32VectorAlloc" ( _
   BYREF propvar AS ANY _                               ' __in  REFPROPVARIANT propvar
 , BYREF pprgn AS ANY _                                 ' __out ULONG **pprgn
 , BYREF pcElem AS DWORD _                              ' __out ULONG *pcElem
 ) AS LONG                                              ' HRESULT

' ========================================================================================
' __checkReturn PSSTDAPI PropVariantToInt64VectorAlloc(__in REFPROPVARIANT propvar, __deref_out_ecount(*pcElem) LONGLONG **pprgn, __out ULONG *pcElem);
' ========================================================================================
DECLARE FUNCTION PropVariantToInt64VectorAlloc IMPORT "PROPSYS.DLL" ALIAS "PropVariantToInt64VectorAlloc" ( _
   BYREF propvar AS ANY _                               ' __in  REFPROPVARIANT propvar
 , BYREF pprgn AS ANY _                                 ' __out LONGLONG **pprgn
 , BYREF pcElem AS DWORD _                              ' __out ULONG *pcElem
 ) AS LONG                                              ' HRESULT

' ========================================================================================
' __checkReturn PSSTDAPI PropVariantToUInt64VectorAlloc(__in REFPROPVARIANT propvar, __deref_out_ecount(*pcElem) ULONGLONG **pprgn, __out ULONG *pcElem);
' ========================================================================================
DECLARE FUNCTION PropVariantToUInt64VectorAlloc IMPORT "PROPSYS.DLL" ALIAS "PropVariantToUInt64VectorAlloc" ( _
   BYREF propvar AS ANY _                               ' __in  REFPROPVARIANT propvar
 , BYREF pprgn AS ANY _                                 ' __out ULONGLONG **pprgn
 , BYREF pcElem AS DWORD _                              ' __out ULONG *pcElem
 ) AS LONG                                              ' HRESULT

' ========================================================================================
' __checkReturn PSSTDAPI PropVariantToDoubleVectorAlloc(__in REFPROPVARIANT propvar, __deref_out_ecount(*pcElem) DOUBLE **pprgn, __out ULONG *pcElem);
' ========================================================================================
DECLARE FUNCTION PropVariantToDoubleVectorAlloc IMPORT "PROPSYS.DLL" ALIAS "PropVariantToDoubleVectorAlloc" ( _
   BYREF propvar AS ANY _                               ' __in  REFPROPVARIANT propvar
 , BYREF pprgn AS ANY _                                 ' __out DOUBLE **pprgn
 , BYREF pcElem AS DWORD _                              ' __out ULONG *pcElem
 ) AS LONG                                              ' HRESULT

' ========================================================================================
' __checkReturn PSSTDAPI PropVariantToFileTimeVectorAlloc(__in REFPROPVARIANT propvar, __deref_out_ecount(*pcElem) FILETIME **pprgft, __out ULONG *pcElem);
' ========================================================================================
DECLARE FUNCTION PropVariantToFileTimeVectorAlloc IMPORT "PROPSYS.DLL" ALIAS "PropVariantToFileTimeVectorAlloc" ( _
   BYREF propvar AS ANY _                               ' __in  REFPROPVARIANT propvar
 , BYREF pprgft AS ANY _                                ' __out FILETIME **pprgft
 , BYREF pcElem AS DWORD _                              ' __out ULONG *pcElem
 ) AS LONG                                              ' HRESULT

' ========================================================================================
' __checkReturn PSSTDAPI PropVariantToStringVectorAlloc(__in REFPROPVARIANT propvar, __deref_out_ecount(*pcElem) PWSTR **pprgsz, __out ULONG *pcElem);
' ========================================================================================
DECLARE FUNCTION PropVariantToStringVectorAlloc IMPORT "PROPSYS.DLL" ALIAS "PropVariantToStringVectorAlloc" ( _
   BYREF propvar AS ANY _                               ' __in  REFPROPVARIANT propvar
 , BYREF pprgsz AS DWORD _                              ' __out PWSTR **pprgsz
 , BYREF pcElem AS DWORD _                              ' __out ULONG *pcElem
 ) AS LONG                                              ' HRESULT

'// Extract a single element from a propvariant.  If it is a VT_VECTOR or VT_ARRAY, returns the element you request.
'// Otherwise iElem must equal 0 and the function will return the value.

' ========================================================================================
' PSSTDAPI PropVariantGetBooleanElem(__in REFPROPVARIANT propvar, __in ULONG iElem, __out BOOL *pfVal);
' ========================================================================================
DECLARE FUNCTION PropVariantGetBooleanElem IMPORT "PROPSYS.DLL" ALIAS "PropVariantGetBooleanElem" ( _
   BYREF propvar AS ANY _                               ' __in  REFPROPVARIANT propvar
 , BYVAL iElem AS DWORD _                               ' __in  ULONG iElem
 , BYREF pfVal AS LONG _                                ' __out BOOL *pfVal
 ) AS LONG                                              ' HRESULT

' ========================================================================================
' PSSTDAPI PropVariantGetInt16Elem(__in REFPROPVARIANT propvar, __in ULONG iElem, __out SHORT *pnVal);
' ========================================================================================
DECLARE FUNCTION PropVariantGetInt16Elem IMPORT "PROPSYS.DLL" ALIAS "PropVariantGetInt16Elem" ( _
   BYREF propvar AS ANY _                               ' __in  REFPROPVARIANT propvar
 , BYVAL iElem AS DWORD _                               ' __in  ULONG iElem
 , BYREF pnVal AS INTEGER _                             ' __out SHORT *pnVal
 ) AS LONG                                              ' HRESULT

' ========================================================================================
' PSSTDAPI PropVariantGetUInt16Elem(__in REFPROPVARIANT propvar, __in ULONG iElem, __out USHORT *pnVal);
' ========================================================================================
DECLARE FUNCTION PropVariantGetUInt16Elem IMPORT "PROPSYS.DLL" ALIAS "PropVariantGetUInt16Elem" ( _
   BYREF propvar AS ANY _                               ' __in  REFPROPVARIANT propvar
 , BYVAL iElem AS DWORD _                               ' __in  ULONG iElem
 , BYREF pnVal AS WORD _                                ' __out USHORT *pnVal
 ) AS LONG                                              ' HRESULT

' ========================================================================================
' PSSTDAPI PropVariantGetInt32Elem(__in REFPROPVARIANT propvar, __in ULONG iElem, __out LONG *pnVal);
' ========================================================================================
DECLARE FUNCTION PropVariantGetInt32Elem IMPORT "PROPSYS.DLL" ALIAS "PropVariantGetInt32Elem" ( _
   BYREF propvar AS ANY _                               ' __in  REFPROPVARIANT propvar
 , BYVAL iElem AS DWORD _                               ' __in  ULONG iElem
 , BYREF pnVal AS LONG _                                ' __out LONG *pnVal
 ) AS LONG                                              ' HRESULT

' ========================================================================================
' PSSTDAPI PropVariantGetUInt32Elem(__in REFPROPVARIANT propvar, __in ULONG iElem, __out ULONG *pnVal);
' ========================================================================================
DECLARE FUNCTION PropVariantGetUInt32Elem IMPORT "PROPSYS.DLL" ALIAS "PropVariantGetUInt32Elem" ( _
   BYREF propvar AS ANY _                               ' __in  REFPROPVARIANT propvar
 , BYVAL iElem AS DWORD _                               ' __in  ULONG iElem
 , BYREF pnVal AS DWORD _                               ' __out ULONG *pnVal
 ) AS LONG                                              ' HRESULT


' ========================================================================================
' PSSTDAPI PropVariantGetInt64Elem(__in REFPROPVARIANT propvar, __in ULONG iElem, __out LONGLONG *pnVal);
' ========================================================================================
DECLARE FUNCTION PropVariantGetInt64Elem IMPORT "PROPSYS.DLL" ALIAS "PropVariantGetInt64Elem" ( _
   BYREF propvar AS ANY _                               ' __in  REFPROPVARIANT propvar
 , BYVAL iElem AS DWORD _                               ' __in  ULONG iElem
 , BYREF pnVal AS QUAD _                                ' __out LONGLONG *pnVal
 ) AS LONG                                              ' HRESULT

' PB doesn't currently support unsigned quads.
' PSSTDAPI PropVariantGetUInt64Elem(__in REFPROPVARIANT propvar, __in ULONG iElem, __out ULONGLONG *pnVal);

' ========================================================================================
' PSSTDAPI PropVariantGetDoubleElem(__in REFPROPVARIANT propvar, __in ULONG iElem, __out DOUBLE *pnVal);
' ========================================================================================
DECLARE FUNCTION PropVariantGetDoubleElem IMPORT "PROPSYS.DLL" ALIAS "PropVariantGetDoubleElem" ( _
   BYREF propvar AS ANY _                               ' __in  REFPROPVARIANT propvar
 , BYVAL iElem AS DWORD _                               ' __in  ULONG iElem
 , BYREF pnVal AS DOUBLE _                              ' __out DOUBLE *pnVal
 ) AS LONG                                              ' HRESULT

' ========================================================================================
' PSSTDAPI PropVariantGetFileTimeElem(__in REFPROPVARIANT propvar, __in ULONG iElem, __out FILETIME *pftVal);
' ========================================================================================
DECLARE FUNCTION PropVariantGetFileTimeElem IMPORT "PROPSYS.DLL" ALIAS "PropVariantGetFileTimeElem" ( _
   BYREF propvar AS ANY _                               ' __in  REFPROPVARIANT propvar
 , BYVAL iElem AS DWORD _                               ' __in  ULONG iElem
 , BYREF pftVal AS FILETIME _                           ' __out FILETIME *pftVal
 ) AS LONG                                              ' HRESULT

' ========================================================================================
' __checkReturn PSSTDAPI PropVariantGetStringElem(__in REFPROPVARIANT propvar, __in ULONG iElem, __deref_out PWSTR *ppszVal);
' ========================================================================================
DECLARE FUNCTION PropVariantGetStringElem IMPORT "PROPSYS.DLL" ALIAS "PropVariantGetStringElem" ( _
   BYREF propvar AS ANY _                               ' __in  REFPROPVARIANT propvar
 , BYVAL iElem AS DWORD _                               ' __in  ULONG iElem
 , BYREF ppszVal AS DWORD _                             ' __out PWSTR *ppszVal
 ) AS LONG                                              ' HRESULT

'#ifdef __cplusplus
'HRESULT  PropVariantGetElem(__in REFPROPVARIANT propvarIn, __in ULONG iElem, __out PROPVARIANT *ppropvar);
'#endif

'// Helpers
' ========================================================================================
' PSSTDAPI_(void) ClearPropVariantArray(__inout_ecount(cVars) PROPVARIANT *rgPropVar, __in UINT cVars);
' ========================================================================================
DECLARE SUB ClearPropVariantArray IMPORT "PROPSYS.DLL" ALIAS "ClearPropVariantArray" ( _
   BYREF rgPropVar AS ANY _                             ' __inout PROPVARIANT *rgPropVar
 , BYVAL cvars AS DWORD _                               ' __in    UINT cvars
 )                                                      ' void

' enum PROPVAR_COMPARE_UNIT
%PVCU_DEFAULT = 0
%PVCU_SECOND  = 1
%PVCU_MINUTE  = 2
%PVCU_HOUR    = 3
%PVCU_DAY     = 4
%PVCU_MONTH   = 5
%PVCU_YEAR    = 6

' enum PROPVAR_COMPARE_FLAGS
%PVCF_DEFAULT                 = &H00000000&  ' // When comparing strings, use StrCmpLogical
%PVCF_TREATEMPTYASGREATERTHAN = &H00000001&  ' // Empty/null values are greater-than non-empty values
%PVCF_USESTRCMP               = &H00000002&  ' // When comparing strings, use StrCmp
%PVCF_USESTRCMPC              = &H00000004&  ' // When comparing strings, use StrCmpC
%PVCF_USESTRCMPI              = &H00000008&  ' // When comparing strings, use StrCmpI
%PVCF_USESTRCMPIC             = &H00000010&  ' // When comparing strings, use StrCmpIC
'typedef int PROPVAR_COMPARE_FLAGS;

'// Comparisons
' ========================================================================================
' PSSTDAPI_(int) PropVariantCompareEx(__in REFPROPVARIANT propvar1, __in REFPROPVARIANT propvar2, __in PROPVAR_COMPARE_UNIT unit, __in PROPVAR_COMPARE_FLAGS flags);
' ========================================================================================
DECLARE FUNCTION PropVariantCompareEx IMPORT "PROPSYS.DLL" ALIAS "PropVariantCompareEx" ( _
   BYREF propvar1 AS ANY _                              ' __in REFPROPVARIANT propvar1
 , BYREF propvar2 AS ANY _                              ' __in REFPROPVARIANT propvar2
 , BYVAL unit AS LONG _                                 ' __in PROPVAR_COMPARE_UNIT unit
 , BYVAL flags AS DWORD _                               ' __in PROPVAR_COMPARE_FLAGS flags
 ) AS LONG                                              ' int

'#ifdef __cplusplus
'int PropVariantCompare(__in REFPROPVARIANT propvar1, __in REFPROPVARIANT propvar2);
'#endif

' enum PROPVAR_CHANGE_FLAGS
%PVCHF_DEFAULT           = &H00000000&
%PVCHF_NOVALUEPROP       = &H00000001&      ' // Maps to VARIANT_NOVALUEPROP for VariantChangeType
%PVCHF_ALPHABOOL         = &H00000002&      ' // Maps to VARIANT_ALPHABOOL for VariantChangeType
%PVCHF_NOUSEROVERRIDE    = &H00000004&      ' // Maps to VARIANT_NOUSEROVERRIDE for VariantChangeType
%PVCHF_LOCALBOOL         = &H00000008&      ' // Maps to VARIANT_LOCALBOOL for VariantChangeType
%PVCHF_NOHEXSTRING       = &H00000010&      ' // Don't convert a string that looks like hexadecimal (= &HABCD) to the numerical equivalent
'typedef int PROPVAR_CHANGE_FLAGS;

'// Coersions
' ========================================================================================
' PSSTDAPI PropVariantChangeType(__out PROPVARIANT *ppropvarDest, __in REFPROPVARIANT propvarSrc, __in PROPVAR_CHANGE_FLAGS flags, __in VARTYPE vt);
' ========================================================================================
DECLARE FUNCTION PropVariantChangeType IMPORT "PROPSYS.DLL" ALIAS "PropVariantChangeType" ( _
   BYREF ppropvarDest AS ANY _                          ' __out PROPVARIANT *ppropvarDest
 , BYREF propvarSrc AS ANY _                            ' __in  REFPROPVARIANT propvarSrc
 , BYVAL flags AS LONG _                                ' __in  PROPVAR_CHANGE_FLAGS flags
 , BYVAL vt AS WORD _                                   ' __in  VARTYPE vt
 ) AS LONG                                              ' HRESULT

'// Conversions
' ========================================================================================
' PSSTDAPI PropVariantToVariant(__in const PROPVARIANT *pPropVar, __out VARIANT *pVar);
' ========================================================================================
DECLARE FUNCTION PropVariantToVariant IMPORT "PROPSYS.DLL" ALIAS "PropVariantToVariant" ( _
   BYREF pPropVar AS ANY _                              ' __in  const PROPVARIANT *pPropVar
 , BYREF pVar AS ANY _                                  ' __out VARIANT *pVar
 ) AS LONG                                              ' HRESULT

' ========================================================================================
' PSSTDAPI VariantToPropVariant(__in const VARIANT* pVar, __out PROPVARIANT* pPropVar);
' ========================================================================================
DECLARE FUNCTION VariantToPropVariant IMPORT "PROPSYS.DLL" ALIAS "VariantToPropVariant" ( _
   BYREF pVar AS ANY _                                  ' __in  const VARIANT* pVar
 , BYREF pPropVar AS ANY _                              ' __out PROPVARIANT* pPropVar
 ) AS LONG                                              ' HRESULT

'// Stg functions
' ========================================================================================
' Serializes a specified PROPVARIANT structure, creating a SERIALIZEDPROPERTYVALUE structure.
' __checkReturn PSSTDAPI StgSerializePropVariant(
'             __in const PROPVARIANT* ppropvar,
'             __deref_out_bcount(*pcb) SERIALIZEDPROPERTYVALUE** ppProp,
'             __out ULONG* pcb);
' ========================================================================================
DECLARE FUNCTION StgSerializePropVariant IMPORT "PROPSYS.DLL" ALIAS "StgSerializePropVariant" ( _
   BYREF ppropvar AS ANY _                              ' __in  const PROPVARIANT* ppropvar
 , BYREF ppProp AS ANY _                                ' __out SERIALIZEDPROPERTYVALUE** ppProp
 , BYREF pcb AS DWORD _                                 ' __out ULONG* pcb
 ) AS LONG                                              ' HRESULT

' ========================================================================================
' Deserializes a specified SERIALIZEDPROPERTYVALUE structure, creating a PROPVARIANT structure.
' PSSTDAPI StgDeserializePropVariant(
'             __in const SERIALIZEDPROPERTYVALUE* pprop,
'             __in ULONG cbMax,
'             __out PROPVARIANT* ppropvar);
' ========================================================================================
DECLARE FUNCTION StgDeserializePropVariant IMPORT "PROPSYS.DLL" ALIAS "StgDeserializePropVariant" ( _
   BYREF pprop AS ANY _                                 ' __in  const SERIALIZEDPROPERTYVALUE* pprop
 , BYVAL cbMax AS DWORD _                               ' __in  ULONG cbMax
 , BYREF ppropvar AS ANY _                              ' __out PROPVARIANT* ppropvar
 ) AS LONG                                              ' HRESULT


'//================
'//
'// Variant Helpers
'//
'//================

'#ifdef __cplusplus
'BOOL IsVarTypeFloat(__in VARTYPE vt);
'BOOL IsVariantArray(__in REFVARIANT var);
'BOOL IsVariantString(__in REFVARIANT var);
'BOOL IsVarTypeNumber(__in VARTYPE vt);
'BOOL IsVarTypeInteger(__in VARTYPE vt);
'#endif

'// Initialize a VARIANT

' ========================================================================================
' Initializes a VARIANT structure based on a string resource imbedded in an executable file.
' PSSTDAPI InitVariantFromResource(__in HINSTANCE hinst, __in UINT id, __out VARIANT *pvar);
' ========================================================================================
DECLARE FUNCTION InitVariantFromResource IMPORT "PROPSYS.DLL" ALIAS "InitVariantFromResource" ( _
   BYVAL hinst AS DWORD _                               ' __in  HINSTANCE hinst
 , BYVAL id AS DWORD _                                  ' __in  UINT id
 , BYREF pvar AS ANY _                                  ' __out VARIANT *pvar
 ) AS LONG                                              ' HRESULT

' ========================================================================================
' Initializes a VARIANT structure with the contents of a buffer.
' PSSTDAPI InitVariantFromBuffer(__in_bcount(cb) const void *pv, __in UINT cb, __out VARIANT *pvar);
' ========================================================================================
DECLARE FUNCTION InitVariantFromBuffer IMPORT "PROPSYS.DLL" ALIAS "InitVariantFromBuffer" ( _
   BYREF pv AS ANY _                                    ' __in  const void *pv
 , BYVAL cb AS DWORD _                                  ' __in  UINT cb
 , BYREF pvar AS ANY _                                  ' __out VARIANT *pvar
 ) AS LONG                                              ' HRESULT

' ========================================================================================
' Initializes a VARIANT structure based on a GUID. The structure is initialized as VT_BSTR.
' PSSTDAPI InitVariantFromGUIDAsString(__in REFGUID guid, __out VARIANT *pvar);
' ========================================================================================
DECLARE FUNCTION InitVariantFromGUIDAsString IMPORT "PROPSYS.DLL" ALIAS "InitVariantFromGUIDAsString" ( _
   BYREF guid AS GUID _                                 ' __in  REFGUID guid
 , BYREF pvar AS ANY _                                  ' __out VARIANT *pvar
 ) AS LONG                                              ' HRESULT

' ========================================================================================
' Initializes a VARIANT structure with the contents of a FILETIME structure.
' Creates a VT_DATE variant.
' PSSTDAPI InitVariantFromFileTime(__in const FILETIME *pft, __out VARIANT *pvar);
' ========================================================================================
DECLARE FUNCTION InitVariantFromFileTime IMPORT "PROPSYS.DLL" ALIAS "InitVariantFromFileTime" ( _
   BYREF pft AS FILETIME _                              ' __in  const FILETIME *pft
 , BYREF pvar AS ANY _                                  ' __out VARIANT *pvar
 ) AS LONG                                              ' HRESULT

' ========================================================================================
' Initializes a VARIANT structure with an array of FILETIME structures.
 'Creates a VT_ARRAY | VT_DATE variant.
' PSSTDAPI InitVariantFromFileTimeArray(__in_ecount_opt(cElems) const FILETIME *prgft, __in ULONG cElems, __out VARIANT *pvar);
' ========================================================================================
DECLARE FUNCTION InitVariantFromFileTimeArray IMPORT "PROPSYS.DLL" ALIAS "InitVariantFromFileTimeArray" ( _
   BYREF prgft AS FILETIME _                            ' __in_ecount_opt(cElems) const FILETIME *prgft
 , BYVAL cElems AS DWORD _                              ' __in  ULONG cElems
 , BYREF pvar AS ANY _                                  ' __out VARIANT *pvar
 ) AS LONG                                              ' HRESULT

' ========================================================================================
' Initializes a VARIANT structure with a string stored in a STRRET structure.
' PSSTDAPI InitVariantFromStrRet(__in STRRET *pstrret, __in PCUITEMID_CHILD pidl, __out VARIANT *pvar);
' ========================================================================================
DECLARE FUNCTION InitVariantFromStrRet IMPORT "PROPSYS.DLL" ALIAS "InitVariantFromStrRet" ( _
   BYREF pstrret AS STRRET _                            ' __in  STRRET *pstrret
 , BYVAL pidl AS DWORD _                                ' __in  PCUITEMID_CHILD pidl
 , BYREF pvar AS ANY _                                  ' __out VARIANT *pvar
 ) AS LONG                                              ' HRESULT

' ========================================================================================
' Initializes a VARIANT structure with a value stored in another VARIANT structure.
' PSSTDAPI InitVariantFromVariantArrayElem(__in REFVARIANT varIn, __in ULONG iElem, __out VARIANT *pvar);
' ========================================================================================
DECLARE FUNCTION InitVariantFromVariantArrayElem IMPORT "PROPSYS.DLL" ALIAS "InitVariantFromVariantArrayElem" ( _
   BYREF varIn AS ANY _                                 ' __in  REFVARIANT varIn
 , BYVAL iElem AS DWORD _                               ' __in  ULONG iElem
 , BYREF pvar AS ANY _                                  ' __out VARIANT *pvar
 ) AS LONG                                              ' HRESULT

' ========================================================================================
' Initializes a VARIANT structure from an array of Boolean values.
' PSSTDAPI InitVariantFromBooleanArray(__in_ecount(cElems) const BOOL *prgf, __in ULONG cElems, __out VARIANT *pvar);
' ========================================================================================
DECLARE FUNCTION InitVariantFromBooleanArray IMPORT "PROPSYS.DLL" ALIAS "InitVariantFromBooleanArray" ( _
   BYREF prgf AS LONG _                                 ' __in  const BOOL *prgf
 , BYVAL cElems AS DWORD _                              ' __in  ULONG cElems
 , BYREF pvar AS ANY _                                  ' __out VARIANT *pvar
 ) AS LONG                                              ' HRESULT

' ========================================================================================
' Initializes a VARIANT structure with an array of 16-bit integer values.
' PSSTDAPI InitVariantFromInt16Array(__in_ecount(cElems) const SHORT *prgn, __in ULONG cElems, __out VARIANT *pvar);
' ========================================================================================
DECLARE FUNCTION InitVariantFromInt16Array IMPORT "PROPSYS.DLL" ALIAS "InitVariantFromInt16Array" ( _
   BYREF prgn AS INTEGER _                              ' __in  const SHORT *prgn
 , BYVAL cElems AS DWORD _                              ' __in  ULONG cElems
 , BYREF pvar AS ANY _                                  ' __out VARIANT *pvar
 ) AS LONG                                              ' HRESULT

' ========================================================================================
' Initializes a VARIANT structure with an array of unsigned 16-bit integer values.
' PSSTDAPI InitVariantFromUInt16Array(__in_ecount(cElems) const USHORT *prgn, __in ULONG cElems, __out VARIANT *pvar);
' ========================================================================================
DECLARE FUNCTION InitVariantFromUInt16Array IMPORT "PROPSYS.DLL" ALIAS "InitVariantFromUInt16Array" ( _
   BYREF prgn AS WORD _                                 ' __in  const USHORT *prgn
 , BYVAL cElems AS DWORD _                              ' __in  ULONG cElems
 , BYREF pvar AS ANY _                                  ' __out VARIANT *pvar
 ) AS LONG                                              ' HRESULT

' ========================================================================================
' Initializes a VARIANT structure with an array of 32-bit integer values.
' PSSTDAPI InitVariantFromInt32Array(__in_ecount(cElems) const LONG *prgn, __in ULONG cElems, __out VARIANT *pvar);
' ========================================================================================
DECLARE FUNCTION InitVariantFromInt32Array IMPORT "PROPSYS.DLL" ALIAS "InitVariantFromInt32Array" ( _
   BYREF prgn AS LONG _                                 ' __in  const LONG *prgn
 , BYVAL cElems AS DWORD _                              ' __in  ULONG cElems
 , BYREF pvar AS ANY _                                  ' __out VARIANT *pvar
 ) AS LONG                                              ' HRESULT

' ========================================================================================
' Initializes a VARIANT structure with an array of unsigned 32-bit integer values.
' PSSTDAPI InitVariantFromUInt32Array(__in_ecount(cElems) const ULONG *prgn, __in ULONG cElems, __out VARIANT *pvar);
' ========================================================================================
DECLARE FUNCTION InitVariantFromUInt32Array IMPORT "PROPSYS.DLL" ALIAS "InitVariantFromUInt32Array" ( _
   BYREF prgn AS DWORD _                                ' __in  const ULONG *prgn
 , BYVAL cElems AS DWORD _                              ' __in  ULONG cElems
 , BYREF pvar AS ANY _                                  ' __out VARIANT *pvar
 ) AS LONG                                              ' HRESULT

' ========================================================================================
' Initializes a VARIANT structure with an array of 64-bit integer values.
' PSSTDAPI InitVariantFromInt64Array(__in_ecount(cElems) const LONGLONG *prgn, __in ULONG cElems, __out VARIANT *pvar);
' ========================================================================================
DECLARE FUNCTION InitVariantFromInt64Array IMPORT "PROPSYS.DLL" ALIAS "InitVariantFromInt64Array" ( _
   BYREF prgn AS QUAD _                                 ' __in  const LONGLONG *prgn
 , BYVAL cElems AS DWORD _                              ' __in  ULONG cElems
 , BYREF pvar AS ANY _                                  ' __out VARIANT *pvar
 ) AS LONG                                              ' HRESULT

' PB doesn't currently support unsigned quads.
' PSSTDAPI InitVariantFromUInt64Array(__in_ecount(cElems) const ULONGLONG *prgn, __in ULONG cElems, __out VARIANT *pvar);

' ========================================================================================
' Initializes a VARIANT structure with an array of values of type DOUBLE.
' PSSTDAPI InitVariantFromDoubleArray(__in_ecount(cElems) const DOUBLE *prgn, __in ULONG cElems, __out VARIANT *pvar);
' ========================================================================================
DECLARE FUNCTION InitVariantFromDoubleArray IMPORT "PROPSYS.DLL" ALIAS "InitVariantFromDoubleArray" ( _
   BYREF prgn AS DOUBLE _                               ' __in  const DOUBLE *prgn
 , BYVAL cElems AS DWORD _                              ' __in  ULONG cElems
 , BYREF pvar AS ANY _                                  ' __out VARIANT *pvar
 ) AS LONG                                              ' HRESULT

' ========================================================================================
' Initializes a VARIANT structure with an array of strings.
' PSSTDAPI InitVariantFromStringArray(__in_ecount(cElems) PCWSTR *prgsz, __in ULONG cElems, __out VARIANT *pvar);
' Note: prgb must be an array of wide string pointers allocated with CoTaskMemFree.
' ========================================================================================
DECLARE FUNCTION InitVariantFromStringArray IMPORT "PROPSYS.DLL" ALIAS "InitVariantFromStringArray" ( _
   BYREF prgn AS ANY _                                  ' __in  const PCWSTR *prgn
 , BYVAL cElems AS DWORD _                              ' __in  ULONG cElems
 , BYREF pvar AS ANY _                                  ' __out VARIANT *pvar
 ) AS LONG                                              ' HRESULT

'#ifdef __cplusplus
'HRESULT  InitVariantFromBoolean(__in BOOL fVal, __out VARIANT *pvar);
'HRESULT  InitVariantFromInt16(__in SHORT iVal, __out VARIANT *pvar);
'HRESULT  InitVariantFromUInt16(__in USHORT uiVal, __out VARIANT *pvar);
'HRESULT  InitVariantFromInt32(__in LONG lVal, __out VARIANT *pvar);
'HRESULT  InitVariantFromUInt32(__in ULONG ulVal, __out VARIANT *pvar);
'HRESULT  InitVariantFromInt64(__in LONGLONG llVal, __out VARIANT *pvar);
'HRESULT  InitVariantFromUInt64(__in ULONGLONG ullVal, __out VARIANT *pvar);
'HRESULT  InitVariantFromDouble(__in DOUBLE dblVal, __out VARIANT *pvar);
'HRESULT  InitVariantFromString(__in PCWSTR psz, __out VARIANT *pvar);
'HRESULT  InitVariantFromDispatch(__in_opt IDispatch* pdisp, __out VARIANT *pvar);
'HRESULT  InitVariantFromDosDateTime(__in WORD wDate, __in WORD wTime, __out VARIANT *pvar);
'HRESULT  InitVariantFromGUIDAsBuffer(__in REFGUID guid, __out VARIANT *pvar);
'#endif

'// Extract data from a VARIANT

' ========================================================================================
' Extracts a BOOL value from a VARIANT structure. If no value exists, then the specified
' default value is returned.
' PSSTDAPI_(BOOL)       VariantToBooleanWithDefault(__in REFVARIANT varIn, __in BOOL fDefault);
' ========================================================================================
DECLARE FUNCTION VariantToBooleanWithDefault IMPORT "PROPSYS.DLL" ALIAS "VariantToBooleanWithDefault" ( _
   BYREF varIn AS ANY _                                 ' __in REFVARIANT varIn
 , BYVAL fDefault AS LONG _                             ' __in BOOL fDefault
 ) AS LONG                                              ' BOOL

' ========================================================================================
' Extracts an Int16 property value of a variant structure. If no value exists, then the
' specified default value is returned.
' PSSTDAPI_(SHORT)      VariantToInt16WithDefault(__in REFVARIANT varIn, __in SHORT iDefault);
' ========================================================================================
DECLARE FUNCTION VariantToInt16WithDefault IMPORT "PROPSYS.DLL" ALIAS "VariantToInt16WithDefault" ( _
   BYREF varIn AS ANY _                                 ' __in REFVARIANT varIn
 , BYVAL iDefault AS INTEGER _                          ' __in SHORT iDefault
 ) AS INTEGER                                           ' SHORT

' ========================================================================================
' Extracts an unsigned Int16 property value of a variant structure. If no value exists,
' then the specified default value is returned.
' PSSTDAPI_(USHORT)     VariantToUInt16WithDefault(__in REFVARIANT varIn, __in USHORT uiDefault);
' ========================================================================================
DECLARE FUNCTION VariantToUInt16WithDefault IMPORT "PROPSYS.DLL" ALIAS "VariantToUInt16WithDefault" ( _
   BYREF varIn AS ANY _                                 ' __in REFVARIANT varIn
 , BYVAL uiDefault AS WORD _                            ' __in USHORT uiDefault
 ) AS WORD                                              ' USHORT

' ========================================================================================
' Extracts an Int32 property value of a variant structure. If no value exists, then the
' specified default value is returned.
' PSSTDAPI_(LONG)       VariantToInt32WithDefault(__in REFVARIANT varIn, __in LONG lDefault);
' ========================================================================================
DECLARE FUNCTION VariantToInt32WithDefault IMPORT "PROPSYS.DLL" ALIAS "VariantToInt32WithDefault" ( _
   BYREF varIn AS ANY _                                 ' __in REFVARIANT varIn
 , BYVAL lDefault AS LONG _                             ' __in LONG lDefault
 ) AS LONG                                              ' LONG

' ========================================================================================
' Extracts unsigned Int32 property value of a variant structure. If no value can be
' extracted, then a default value is assigned.
' PSSTDAPI_(ULONG)      VariantToUInt32WithDefault(__in REFVARIANT varIn, __in ULONG ulDefault);
' ========================================================================================
DECLARE FUNCTION VariantToUInt32WithDefault IMPORT "PROPSYS.DLL" ALIAS "VariantToUInt32WithDefault" ( _
   BYREF varIn AS ANY _                                 ' __in REFVARIANT varIn
 , BYVAL ulDefault AS DWORD _                           ' __in ULONG ulDefault
 ) AS DWORD                                             ' ULONG

' ========================================================================================
' Extracts an Int64 property value of a variant structure. If no value exists, then the
' specified default value is returned.
' PSSTDAPI_(LONGLONG)   VariantToInt64WithDefault(__in REFVARIANT varIn, __in LONGLONG llDefault);
' ========================================================================================
DECLARE FUNCTION VariantToInt64WithDefault IMPORT "PROPSYS.DLL" ALIAS "VariantToInt64WithDefault" ( _
   BYREF varIn AS ANY _                                 ' __in REFVARIANT varIn
 , BYVAL llDefault AS QUAD _                            ' __in LONGLONG llDefault
 ) AS QUAD                                              ' LONGLONG

' PB doesn't currently support unsigned quads.
' PSSTDAPI_(ULONGLONG)  VariantToUInt64WithDefault(__in REFVARIANT varIn, __in ULONGLONG ullDefault);

' ========================================================================================
' Extracts a DOUBLE value from a VARIANT structure. If no value exists, then the
' specified default value is returned.
' PSSTDAPI_(DOUBLE)     VariantToDoubleWithDefault(__in REFVARIANT varIn, __in DOUBLE dblDefault);
' ========================================================================================
DECLARE FUNCTION VariantToDoubleWithDefault IMPORT "PROPSYS.DLL" ALIAS "VariantToDoubleWithDefault" ( _
   BYREF varIn AS ANY _                                 ' __in REFVARIANT varIn
 , BYVAL dblDefault AS DOUBLE _                         ' __in DOUBLE dblDefault
 ) AS DOUBLE                                            ' DOUBLE

' ========================================================================================
' Extracts the string property value of a variant structure. If no value exists, then the
' specified default value is returned.
' PSSTDAPI_(PCWSTR)     VariantToStringWithDefault(__in REFVARIANT varIn, __in_opt LPCWSTR pszDefault);
' ========================================================================================
DECLARE FUNCTION VariantToStringWithDefault IMPORT "PROPSYS.DLL" ALIAS "VariantToStringWithDefault" ( _
   BYREF varIn AS ANY _                                 ' __in     REFVARIANT varIn
 , OPTIONAL BYREF pszDefault AS WSTRINGZ _              ' __in_opt LPCWSTR pszDefault
 ) AS DWORD                                             ' PCWSTR

' ========================================================================================
' Extracts the value of a Boolean property from a VARIANT structure.
' PSSTDAPI              VariantToBoolean(__in REFVARIANT varIn, __out BOOL *pfRet);
' ========================================================================================
DECLARE FUNCTION VariantToBoolean IMPORT "PROPSYS.DLL" ALIAS "VariantToBoolean" ( _
   BYREF varIn AS ANY _                                 ' __in  REFVARIANT varIn
 , BYREF pfRet AS LONG _                                ' __out BOOL *pfRet
 ) AS LONG                                              ' HRESULT

' ========================================================================================
' Extracts the Int16 property value of a variant structure.
' PSSTDAPI              VariantToInt16(__in REFVARIANT varIn, __out SHORT *piRet);
' ========================================================================================
DECLARE FUNCTION VariantToInt16 IMPORT "PROPSYS.DLL" ALIAS "VariantToInt16" ( _
   BYREF varIn AS ANY _                                 ' __in  REFVARIANT varIn
 , BYREF piRet AS INTEGER _                             ' __out SHORT *piRet
 ) AS LONG                                              ' HRESULT

' ========================================================================================
' Extracts an unsigned Int16 property value of a variant structure.
' PSSTDAPI              VariantToUInt16(__in REFVARIANT varIn, __out USHORT *puiRet);
' ========================================================================================
DECLARE FUNCTION VariantToUInt16 IMPORT "PROPSYS.DLL" ALIAS "VariantToUInt16" ( _
   BYREF varIn AS ANY _                                 ' __in  REFVARIANT varIn
 , BYREF puiRet AS WORD _                               ' __out USHORT *puiRet
 ) AS LONG                                              ' HRESULT

' ========================================================================================
' Extracts an Int32 property value of a variant structure.
' PSSTDAPI              VariantToInt32(__in REFVARIANT varIn, __out LONG *plRet);
' ========================================================================================
DECLARE FUNCTION VariantToInt32 IMPORT "PROPSYS.DLL" ALIAS "VariantToInt32" ( _
   BYREF varIn AS ANY _                                 ' __in  REFVARIANT varIn
 , BYREF plRet AS LONG _                                ' __out LONG *plRet
 ) AS LONG                                              ' HRESULT

' ========================================================================================
' Extracts unsigned Int32 property value of a variant structure.
' PSSTDAPI              VariantToUInt32(__in REFVARIANT varIn, __out ULONG *pulRet);
' ========================================================================================
DECLARE FUNCTION VariantToUInt32 IMPORT "PROPSYS.DLL" ALIAS "VariantToUInt32" ( _
   BYREF varIn AS ANY _                                 ' __in  REFVARIANT varIn
 , BYREF pulRet AS DWORD _                              ' __out ULONG *pulRet
 ) AS LONG                                              ' HRESULT

' ========================================================================================
' Extracts an Int64 property value of a variant structure.
' PSSTDAPI              VariantToInt64(__in REFVARIANT varIn, __out LONGLONG *pllRet);
' ========================================================================================
DECLARE FUNCTION VariantToInt64 IMPORT "PROPSYS.DLL" ALIAS "VariantToInt64" ( _
   BYREF varIn AS ANY _                                 ' __in  REFVARIANT varIn
 , BYREF pllRet AS QUAD _                               ' __out LONGLONG *pllRet
 ) AS LONG                                              ' HRESULT

' PB doesn't currently support unsigned quads.
' PSSTDAPI              VariantToUInt64(__in REFVARIANT varIn, __out ULONGLONG *pullRet);

' ========================================================================================
' Extracts a DOUBLE value from a VARIANT structure.
' PSSTDAPI              VariantToDouble(__in REFVARIANT varIn, __out DOUBLE *pdblRet);
' ========================================================================================
DECLARE FUNCTION VariantToDouble IMPORT "PROPSYS.DLL" ALIAS "VariantToDouble" ( _
   BYREF varIn AS ANY _                                 ' __in  REFVARIANT varIn
 , BYREF pdblRet AS DOUBLE _                            ' __out DOUBLE *pdblRet
 ) AS LONG                                              ' HRESULT

' ========================================================================================
' Extracts the contents of a buffer stored in a VARIANT structure of type VT_ARRRAY | VT_UI1.
' PSSTDAPI              VariantToBuffer(__in REFVARIANT varIn, __out_bcount(cb) void *pv, __in UINT cb);
' ========================================================================================
DECLARE FUNCTION VariantToBuffer IMPORT "PROPSYS.DLL" ALIAS "VariantToBuffer" ( _
   BYREF varIn AS ANY _                                 ' __in  REFVARIANT varIn
 , BYREF pv AS ANY _                                    ' __out void *pv
 , BYVAL cb AS DWORD _                                  ' UINT cb
 ) AS LONG                                              ' HRESULT

' ========================================================================================
' Extracts a GUID property value of a variant structure.
' PSSTDAPI              VariantToGUID(__in REFVARIANT varIn, __out GUID *pguid);
' ========================================================================================
DECLARE FUNCTION VariantToGUID IMPORT "PROPSYS.DLL" ALIAS "VariantToGUID" ( _
   BYREF varIn AS ANY _                                 ' __in  REFVARIANT varIn
 , BYREF pguid AS GUID _                                ' __out GUID *pguid
 ) AS LONG                                              ' HRESULT

' ========================================================================================
' Extracts the variant value of a variant structure to a string.
' PSSTDAPI              VariantToString(__in REFVARIANT varIn, __out_ecount(cchBuf) PWSTR pszBuf, __in UINT cchBuf);
' ========================================================================================
DECLARE FUNCTION VariantToString IMPORT "PROPSYS.DLL" ALIAS "VariantToString" ( _
   BYREF varIn AS ANY _                                 ' __in  REFVARIANT varIn
 , BYREF pszBuf AS WSTRINGZ _                           ' __out PWSTR pszBuf
 , BYVAL cchBuf AS DWORD _                              ' __in UINT cchBuf
 ) AS LONG                                              ' HRESULT

' ========================================================================================
' Extracts the variant value of a variant structure to a newly-allocated string.
' __checkReturn PSSTDAPI VariantToStringAlloc(__in REFVARIANT varIn, __deref_out PWSTR *ppszBuf);
' ========================================================================================
DECLARE FUNCTION VariantToStringAlloc IMPORT "PROPSYS.DLL" ALIAS "VariantToStringAlloc" ( _
   BYREF varIn AS ANY _                                 ' __in  REFVARIANT varIn
 , BYREF ppszBuf AS DWORD _                             ' __out PWSTR *ppszBuf
 ) AS LONG                                              ' HRESULT

' ========================================================================================
' Extracts a date and time value in Microsoft MS-DOS format from a VARIANT structure.
' PSSTDAPI              VariantToDosDateTime(__in REFVARIANT varIn, __out WORD *pwDate, __out WORD *pwTime);
' ========================================================================================
DECLARE FUNCTION VariantToDosDateTime IMPORT "PROPSYS.DLL" ALIAS "VariantToDosDateTime" ( _
   BYREF varIn AS ANY _                                 ' __in  REFVARIANT varIn
 , BYREF pwDate AS WORD _                               ' __out WORD *pwDate
 , BYREF pwTime AS WORD _                               ' __out WORD *pwTime
 ) AS LONG                                              ' HRESULT

' ========================================================================================
' If the source variant is a VT_BSTR, extracts string and places it into a STRRET structure.
' __checkReturn PSSTDAPI VariantToStrRet(__in REFVARIANT varIn, __out STRRET *pstrret);
' ========================================================================================
DECLARE FUNCTION VariantToStrRet IMPORT "PROPSYS.DLL" ALIAS "VariantToStrRet" ( _
   BYREF varIn AS ANY _                                 ' __in  REFVARIANT varIn
 , BYREF pstrret AS STRRET _                            ' __out STRRET *pstrret
 ) AS LONG                                              ' HRESULT

' ========================================================================================
' Extracts a FILETIME structure from a variant structure.
' PSSTDAPI VariantToFileTime(__in REFVARIANT varIn, __in PSTIME_FLAGS stfOut, __out FILETIME* pftOut);
' ========================================================================================
DECLARE FUNCTION VariantToFileTime IMPORT "PROPSYS.DLL" ALIAS "VariantToFileTime" ( _
   BYREF varIn AS ANY _                                 ' __in  REFVARIANT varIn
 , BYVAL stfOut AS DWORD _                              ' __in  PSTIME_FLAGS stfOut
 , BYREF pftOut AS FILETIME _                           ' __out FILETIME* pftOut
 ) AS LONG                                              ' HRESULT

' ========================================================================================
' Get the element count.  Returns number of elements for values of type VT_ARRAY; returns 1 otherwise.
' PSSTDAPI_(ULONG) VariantGetElementCount(__in REFVARIANT varIn);
' ========================================================================================
DECLARE FUNCTION VariantGetElementCount IMPORT "PROPSYS.DLL" ALIAS "VariantGetElementCount" ( _
   BYREF varIn AS ANY _                                 ' __in REFVARIANT varIn
 ) AS DWORD                                             ' ULONG

'// Extract data from a VARIANT into a vector

' ========================================================================================
' Extracts an array of Boolean values from a VARIANT structure.
' PSSTDAPI VariantToBooleanArray(__in REFVARIANT var, __out_ecount_part(crgn, *pcElem) BOOL *prgf, __in ULONG crgn, __out ULONG *pcElem);
' ========================================================================================
DECLARE FUNCTION VariantToBooleanArray IMPORT "PROPSYS.DLL" ALIAS "VariantToBooleanArray" ( _
   BYREF var AS ANY _                                   ' __in  REFVARIANT var
 , BYREF prgf AS LONG _                                 ' __out BOOL *prgf
 , BYVAL crgn AS DWORD _                                ' __in  ULONG crgn
 , BYREF pcElem AS DWORD _                              ' __out ULONG *pcElem
 ) AS LONG                                              ' HRESULT

' ========================================================================================
' Extracts data from a vector structure into an Int16 array.
' PSSTDAPI VariantToInt16Array(__in REFVARIANT var, __out_ecount_part(crgn, *pcElem) SHORT *prgn, __in ULONG crgn, __out ULONG *pcElem);
' ========================================================================================
DECLARE FUNCTION VariantToInt16Array IMPORT "PROPSYS.DLL" ALIAS "VariantToInt16Array" ( _
   BYREF var AS ANY _                                   ' __in  REFVARIANT var
 , BYREF prgn AS INTEGER _                              ' __out SHORT *prgn
 , BYVAL crgn AS DWORD _                                ' __in  ULONG crgn
 , BYREF pcElem AS DWORD _                              ' __out ULONG *pcElem
 ) AS LONG                                              ' HRESULT

' ========================================================================================
' Extracts data from a vector structure into a newly-allocated unsigned Int16 array.
' PSSTDAPI VariantToUInt16Array(__in REFVARIANT var, __out_ecount_part(crgn, *pcElem) USHORT *prgn, __in ULONG crgn, __out ULONG *pcElem);
' ========================================================================================
DECLARE FUNCTION VariantToUInt16Array IMPORT "PROPSYS.DLL" ALIAS "VariantToUInt16Array" ( _
   BYREF var AS ANY _                                   ' __in  REFVARIANT var
 , BYREF prgn AS WORD _                                 ' __out USHORT *prgn
 , BYVAL crgn AS DWORD _                                ' __in  ULONG crgn
 , BYREF pcElem AS DWORD _                              ' __out ULONG *pcElem
 ) AS LONG                                              ' HRESULT

' ========================================================================================
' Extracts data from a vector structure into an Int32 array.
' PSSTDAPI VariantToInt32Array(__in REFVARIANT var, __out_ecount_part(crgn, *pcElem) LONG *prgn, __in ULONG crgn, __out ULONG *pcElem);
' ========================================================================================
DECLARE FUNCTION VariantToInt32Array IMPORT "PROPSYS.DLL" ALIAS "VariantToInt32Array" ( _
   BYREF var AS ANY _                                   ' __in  REFVARIANT var
 , BYREF prgn AS LONG _                                 ' __out LONG *prgn
 , BYVAL crgn AS DWORD _                                ' __in  ULONG crgn
 , BYREF pcElem AS DWORD _                              ' __out ULONG *pcElem
 ) AS LONG                                              ' HRESULT

' ========================================================================================
' Extracts data from a vector structure into an unsigned Int32 array.
' PSSTDAPI VariantToUInt32Array(__in REFVARIANT var, __out_ecount_part(crgn, *pcElem) ULONG *prgn, __in ULONG crgn, __out ULONG *pcElem);
' ========================================================================================
DECLARE FUNCTION VariantToUInt32Array IMPORT "PROPSYS.DLL" ALIAS "VariantToUInt32Array" ( _
   BYREF var AS ANY _                                   ' __in  REFVARIANT var
 , BYREF prgn AS DWORD _                                ' __out ULONG *prgn
 , BYVAL crgn AS DWORD _                                ' __in  ULONG crgn
 , BYREF pcElem AS DWORD _                              ' __out ULONG *pcElem
 ) AS LONG                                              ' HRESULT

' ========================================================================================
' Extracts data from a vector structure into an unsigned Int64 array.
' PSSTDAPI VariantToInt64Array(__in REFVARIANT var, __out_ecount_part(crgn, *pcElem) LONGLONG *prgn, __in ULONG crgn, __out ULONG *pcElem);
' ========================================================================================
DECLARE FUNCTION VariantToInt64Array IMPORT "PROPSYS.DLL" ALIAS "VariantToInt64Array" ( _
   BYREF var AS ANY _                                   ' __in  REFVARIANT var
 , BYREF prgn AS QUAD _                                 ' __out LONGLONG *prgn
 , BYVAL crgn AS DWORD _                                ' __in  ULONG crgn
 , BYREF pcElem AS DWORD _                              ' __out ULONG *pcElem
 ) AS LONG                                              ' HRESULT

' PB doesn't currently support unsigned quads.
' PSSTDAPI VariantToUInt64Array(__in REFVARIANT var, __out_ecount_part(crgn, *pcElem) ULONGLONG *prgn, __in ULONG crgn, __out ULONG *pcElem);

' ========================================================================================
' Extracts an array of DOUBLE values from a VARIANT structure.
' PSSTDAPI VariantToDoubleArray(__in REFVARIANT var, __out_ecount_part(crgn, *pcElem) DOUBLE *prgn, __in ULONG crgn, __out ULONG *pcElem);
' ========================================================================================
DECLARE FUNCTION VariantToDoubleArray IMPORT "PROPSYS.DLL" ALIAS "VariantToDoubleArray" ( _
   BYREF var AS ANY _                                   ' __in  REFVARIANT var
 , BYREF prgn AS DOUBLE _                               ' __out DOUBLE *prgn
 , BYVAL crgn AS DWORD _                                ' __in  ULONG crgn
 , BYREF pcElem AS DWORD _                              ' __out ULONG *pcElem
 ) AS LONG                                              ' HRESULT

' ========================================================================================
' Extracts data from a vector structure into a String array.
' __checkReturn PSSTDAPI VariantToStringArray(__in REFVARIANT var, __out_ecount_part(crgsz, *pcElem) PWSTR *prgsz, __in ULONG crgsz, __out ULONG *pcElem);
' ========================================================================================
DECLARE FUNCTION VariantToStringArray IMPORT "PROPSYS.DLL" ALIAS "VariantToStringArray" ( _
   BYREF var AS ANY _                                   ' __in  REFVARIANT var
 , BYREF prgsz AS ANY _                                 ' __out PWSTR *prgsz
 , BYVAL crgsz AS DWORD _                               ' __in  ULONG crgsz
 , BYREF pcElem AS DWORD _                              ' __out ULONG *pcElem
 ) AS LONG                                              ' HRESULT

'// Extract data from a VARIANT into a newly allocated vector (free with CoTaskMemFree)
' ========================================================================================
' Allocates an array of BOOL values then extracts data from a VARIANT structure into that array.
' __checkReturn PSSTDAPI VariantToBooleanArrayAlloc(__in REFVARIANT var, __deref_out_ecount(*pcElem) BOOL **pprgf, __out ULONG *pcElem);
' ========================================================================================
DECLARE FUNCTION VariantToBooleanArrayAlloc IMPORT "PROPSYS.DLL" ALIAS "VariantToBooleanArrayAlloc" ( _
   BYREF var AS ANY _                                   ' __in  REFVARIANT var
 , BYREF pprgf AS ANY _                                 ' __out BOOL **pprgf
 , BYREF pcElem AS DWORD _                              ' __out ULONG *pcElem
 ) AS LONG                                              ' HRESULT

' ========================================================================================
' Extracts data from a vector structure into a newly-allocated Int16 array.
' __checkReturn PSSTDAPI VariantToInt16ArrayAlloc(__in REFVARIANT var, __deref_out_ecount(*pcElem) SHORT **pprgn, __out ULONG *pcElem);
' ========================================================================================
DECLARE FUNCTION VariantToInt16ArrayAlloc IMPORT "PROPSYS.DLL" ALIAS "VariantToInt16ArrayAlloc" ( _
   BYREF var AS ANY _                                   ' __in  REFVARIANT var
 , BYREF pprgn AS ANY _                                 ' __out SHORT **pprgn
 , BYREF pcElem AS DWORD _                              ' __out ULONG *pcElem
 ) AS LONG                                              ' HRESULT

' ========================================================================================
' Extracts data from a vector structure into a newly-allocated unsigned Int16 array.
' __checkReturn PSSTDAPI VariantToUInt16ArrayAlloc(__in REFVARIANT var, __deref_out_ecount(*pcElem) USHORT **pprgn, __out ULONG *pcElem);
' ========================================================================================
DECLARE FUNCTION VariantToUInt16ArrayAlloc IMPORT "PROPSYS.DLL" ALIAS "VariantToUInt16ArrayAlloc" ( _
   BYREF var AS ANY _                                   ' __in  REFVARIANT var
 , BYREF pprgn AS ANY _                                 ' __out USHORT **pprgn
 , BYREF pcElem AS DWORD _                              ' __out ULONG *pcElem
 ) AS LONG                                              ' HRESULT

' ========================================================================================
' Extracts data from a vector structure into a newly-allocated Int32 array.
' __checkReturn PSSTDAPI VariantToInt32ArrayAlloc(__in REFVARIANT var, __deref_out_ecount(*pcElem) LONG **pprgn, __out ULONG *pcElem);
' ========================================================================================
DECLARE FUNCTION VariantToInt32ArrayAlloc IMPORT "PROPSYS.DLL" ALIAS "VariantToInt32ArrayAlloc" ( _
   BYREF var AS ANY _                                   ' __in  REFVARIANT var
 , BYREF pprgn AS ANY _                                 ' __out LONG **pprgn
 , BYREF pcElem AS DWORD _                              ' __out ULONG *pcElem
 ) AS LONG                                              ' HRESULT

' ========================================================================================
' Extracts data from a vector structure into a newly-allocated unsigned Int32 array.
' __checkReturn PSSTDAPI VariantToUInt32ArrayAlloc(__in REFVARIANT var, __deref_out_ecount(*pcElem) ULONG **pprgn, __out ULONG *pcElem);
' ========================================================================================
DECLARE FUNCTION VariantToUInt32ArrayAlloc IMPORT "PROPSYS.DLL" ALIAS "VariantToUInt32ArrayAlloc" ( _
   BYREF var AS ANY _                                   ' __in  REFVARIANT var
 , BYREF pprgn AS ANY _                                 ' __out ULONG **pprgn
 , BYREF pcElem AS DWORD _                              ' __out ULONG *pcElem
 ) AS LONG                                              ' HRESULT

' ========================================================================================
' Extracts data from a vector structure into a newly-allocated Int64 array.
' __checkReturn PSSTDAPI VariantToInt64ArrayAlloc(__in REFVARIANT var, __deref_out_ecount(*pcElem) LONGLONG **pprgn, __out ULONG *pcElem);
' ========================================================================================
DECLARE FUNCTION VariantToInt64ArrayAlloc IMPORT "PROPSYS.DLL" ALIAS "VariantToInt64ArrayAlloc" ( _
   BYREF var AS ANY _                                   ' __in  REFVARIANT var
 , BYREF pprgn AS ANY _                                 ' __out LONGLONG **pprgn
 , BYREF pcElem AS DWORD _                              ' __out ULONG *pcElem
 ) AS LONG                                              ' HRESULT

' ========================================================================================
' Extracts data from a vector structure into a newly-allocated unsigned Int64 array.
' __checkReturn PSSTDAPI VariantToUInt64ArrayAlloc(__in REFVARIANT var, __deref_out_ecount(*pcElem) ULONGLONG **pprgn, __out ULONG *pcElem);
' ========================================================================================
DECLARE FUNCTION VariantToUInt64ArrayAlloc IMPORT "PROPSYS.DLL" ALIAS "VariantToUInt64ArrayAlloc" ( _
   BYREF var AS ANY _                                   ' __in  REFVARIANT var
 , BYREF pprgn AS ANY _                                 ' __out ULONGLONG **pprgn
 , BYREF pcElem AS DWORD _                              ' __out ULONG *pcElem
 ) AS LONG                                              ' HRESULT

' ========================================================================================
' Allocates an array of DOUBLE values then extracts data from a VARIANT structure into that array.
' __checkReturn PSSTDAPI VariantToDoubleArrayAlloc(__in REFVARIANT var, __deref_out_ecount(*pcElem) DOUBLE **pprgn, __out ULONG *pcElem);
' ========================================================================================
DECLARE FUNCTION VariantToDoubleArrayAlloc IMPORT "PROPSYS.DLL" ALIAS "VariantToDoubleArrayAlloc" ( _
   BYREF var AS ANY _                                   ' __in  REFVARIANT var
 , BYREF pprgn AS ANY _                                 ' __out DOUBLE **pprgn
 , BYREF pcElem AS DWORD _                              ' __out ULONG *pcElem
 ) AS LONG                                              ' HRESULT

' ========================================================================================
' Extracts data from a vector structure into a newly-allocated String array.
' __checkReturn PSSTDAPI VariantToStringArrayAlloc(__in REFVARIANT var, __deref_out_ecount(*pcElem) PWSTR **pprgsz, __out ULONG *pcElem);
' ========================================================================================
DECLARE FUNCTION VariantToStringArrayAlloc IMPORT "PROPSYS.DLL" ALIAS "VariantToStringArrayAlloc" ( _
   BYREF var AS ANY _                                   ' __in  REFVARIANT var
 , BYREF pprgsz AS ANY _                                ' __out PWSTR **pprgsz
 , BYREF pcElem AS DWORD _                              ' __out ULONG *pcElem
 ) AS LONG                                              ' HRESULT

'// Get a single element of a VARIANT.  If it is type VT_ARRAY, returns a the requested element.  Otherwise
'// iElem must equal 0 and the function returns the value.

' ========================================================================================
' Extracts a single Boolean element from a variant structure.
' PSSTDAPI VariantGetBooleanElem(__in REFVARIANT var, __in ULONG iElem, __out BOOL *pfVal);
' ========================================================================================
DECLARE FUNCTION VariantGetBooleanElem IMPORT "PROPSYS.DLL" ALIAS "VariantGetBooleanElem" ( _
   BYREF var AS ANY _                                   ' __in  REFVARIANT var
 , BYVAL iElem AS DWORD _                               ' __in  ULONG iElem
 , BYREF pfVal AS LONG _                                ' __out BOOL *pfVal
 ) AS LONG                                              ' HRESULT

' ========================================================================================
' Extracts a single Int16 element from a variant structure.
' PSSTDAPI VariantGetInt16Elem(__in REFVARIANT var, __in ULONG iElem, __out SHORT *pnVal);
' ========================================================================================
DECLARE FUNCTION VariantGetInt16Elem IMPORT "PROPSYS.DLL" ALIAS "VariantGetInt16Elem" ( _
   BYREF var AS ANY _                                   ' __in  REFVARIANT var
 , BYVAL iElem AS DWORD _                               ' __in  ULONG iElem
 , BYREF pnVal AS INTEGER _                             ' __out SHORT *pnVal
 ) AS LONG                                              ' HRESULT

' ========================================================================================
' Extracts a single unsigned Int16 element from a variant structure.
' PSSTDAPI VariantGetUInt16Elem(__in REFVARIANT var, __in ULONG iElem, __out USHORT *pnVal);
' ========================================================================================
DECLARE FUNCTION VariantGetUInt16Elem IMPORT "PROPSYS.DLL" ALIAS "VariantGetUInt16Elem" ( _
   BYREF var AS ANY _                                   ' __in  REFVARIANT var
 , BYVAL iElem AS DWORD _                               ' __in  ULONG iElem
 , BYREF pnVal AS WORD _                                ' __out USHORT *pnVal
 ) AS LONG                                              ' HRESULT

' ========================================================================================
' Extracts a single Int32 element from a variant structure.
' PSSTDAPI VariantGetInt32Elem(__in REFVARIANT var, __in ULONG iElem, __out LONG *pnVal);
' ========================================================================================
DECLARE FUNCTION VariantGetInt32Elem IMPORT "PROPSYS.DLL" ALIAS "VariantGetInt32Elem" ( _
   BYREF var AS ANY _                                   ' __in  REFVARIANT var
 , BYVAL iElem AS DWORD _                               ' __in  ULONG iElem
 , BYREF pnVal AS LONG _                                ' __out LONG *pnVal
 ) AS LONG                                              ' HRESULT

' ========================================================================================
' Extracts a single unsigned Int32 element from a variant structure.
' PSSTDAPI VariantGetUInt32Elem(__in REFVARIANT var, __in ULONG iElem, __out ULONG *pnVal);
' ========================================================================================
DECLARE FUNCTION VariantGetUInt32Elem IMPORT "PROPSYS.DLL" ALIAS "VariantGetUInt32Elem" ( _
   BYREF var AS ANY _                                   ' __in  REFVARIANT var
 , BYVAL iElem AS DWORD _                               ' __in  ULONG iElem
 , BYREF pnVal AS DWORD _                               ' __out ULONG *pnVal
 ) AS LONG                                              ' HRESULT

' ========================================================================================
' Extracts a single Int64 element from a variant structure.
' PSSTDAPI VariantGetInt64Elem(__in REFVARIANT var, __in ULONG iElem, __out LONGLONG *pnVal);
' ========================================================================================
DECLARE FUNCTION VariantGetInt64Elem IMPORT "PROPSYS.DLL" ALIAS "VariantGetInt64Elem" ( _
   BYREF var AS ANY _                                   ' __in  REFVARIANT var
 , BYVAL iElem AS DWORD _                               ' __in  ULONG iElem
 , BYREF pnVal AS QUAD _                                ' __out LONGLONG *pnVal
 ) AS LONG                                              ' HRESULT

' PB doesn't currently support unsigned quads.
' PSSTDAPI VariantGetUInt64Elem(__in REFVARIANT var, __in ULONG iElem, __out ULONGLONG *pnVal);

' ========================================================================================
' Extracts one double element from a variant structure.
' PSSTDAPI VariantGetDoubleElem(__in REFVARIANT var, __in ULONG iElem, __out DOUBLE *pnVal);
' ========================================================================================
DECLARE FUNCTION VariantGetDoubleElem IMPORT "PROPSYS.DLL" ALIAS "VariantGetDoubleElem" ( _
   BYREF var AS ANY _                                   ' __in  REFVARIANT var
 , BYVAL iElem AS DWORD _                               ' __in  ULONG iElem
 , BYREF pnVal AS DOUBLE _                              ' __out DOUBLE *pnVal
 ) AS LONG                                              ' HRESULT

' ========================================================================================
' Extracts a single wide string element from a variant structure.
' __checkReturn PSSTDAPI VariantGetStringElem(__in REFVARIANT var, __in ULONG iElem, __deref_out PWSTR *ppszVal);
' ========================================================================================
DECLARE FUNCTION VariantGetStringElem IMPORT "PROPSYS.DLL" ALIAS "VariantGetStringElem" ( _
   BYREF var AS ANY _                                   ' __in  REFVARIANT var
 , BYVAL iElem AS DWORD _                               ' __in  ULONG iElem
 , BYREF ppszVal AS DWORD _                             ' __out PWSTR *ppszVal
 ) AS LONG                                              ' HRESULT

'#ifdef __cplusplus
'HRESULT  VariantGetElem(__in REFVARIANT varIn, __in ULONG iElem, __out VARIANT *pvar);
'#endif

'// Helpers

' ========================================================================================
' Frees the memory and references used by an array of VARIANT structures stored in an array.
' PSSTDAPI_(void) ClearVariantArray(__inout_ecount(cvars) VARIANT *pvars, __in UINT cvars);
' ========================================================================================
DECLARE SUB ClearVariantArray IMPORT "PROPSYS.DLL" ALIAS "ClearVariantArray" ( _
   BYREF pvars AS ANY _                                 ' __in_out VARIANT *pvars
 , BYVAL cvars AS DWORD _                               ' __in     UINT cvars
 )                                                      ' void

' ========================================================================================
' Compares two variant structures, based on default comparison rules.
' PSSTDAPI_(int) VariantCompare(__in REFVARIANT var1, __in REFVARIANT var2);
' ========================================================================================
DECLARE FUNCTION VariantCompare IMPORT "PROPSYS.DLL" ALIAS "VariantCompare" ( _
   BYREF var1 AS ANY _                                  ' __in REFVARIANT var1
 , BYREF var2 AS ANY _                                  ' __in REFVARIANT var2
 ) AS LONG                                              ' int

'//===========================
'//
'// Property-specific notions
'//
'//===========================


'// The progress bar property control uses a specially formatted PROPVARIANT to convey the look of the progress bar
'// propvar.vt = VT_UI4
'// propvar.caul.pElems[0] = current progress
'// propvar.caul.pElems[1] = total progress
'// propvar.caul.pElems[2] = DRAWPROGRESSFLAGS (see below);
' enum DRAWPROGRESSFLAGS
%DPF_NONE                = &H0   ' // No progress flags.
%DPF_MARQUEE             = &H1   ' // The progress bar should draw in marquee mode.
%DPF_MARQUEE_COMPLETE    = &H2   ' // The marquee format progress bar has completed.
%DPF_ERROR               = &H4   ' // The progress bar should be drawn in the error state.
%DPF_WARNING             = &H8   ' // The progress bar should be drawn in the warning state.
%DPF_STOPPED             = &H10  ' // The progress bar is stopped.

'//================
'//
'// Inline Helpers
'//
'//================

'#if defined(__cplusplus) && !defined(NO_PROPVAR_INLINES)

' ========================================================================================
' Initializes a given PROPVARIANT structure as a VT_BOOL using a specified Boolean vlaue.
' ========================================================================================
'inline HRESULT InitPropVariantFromBoolean(__in BOOL fVal, __out PROPVARIANT *ppropvar)
'{
'    ppropvar->vt = VT_BOOL;
'    ppropvar->boolVal = fVal ? VARIANT_TRUE : VARIANT_FALSE;
'    return S_OK;
'}
' ========================================================================================
FUNCTION InitPropVariantFromBoolean (BYVAL fVal AS LONG, BYREF ppropvar AS PROPVARIANT) AS LONG
   ppropvar.vt = %VT_BOOL
   ppropvar.boolVal = IIF&(fVal <> 0, %VARIANT_TRUE, %VARIANT_FALSE)
   FUNCTION = %S_OK
END FUNCTION
' ========================================================================================

' ========================================================================================
' Initializes a PROPVARIANT structure with a 16-bit integer value.
' ========================================================================================
'inline HRESULT InitPropVariantFromInt16(__in SHORT nVal, __out PROPVARIANT *ppropvar)
'{
'    ppropvar->vt = VT_I2;
'    ppropvar->iVal = nVal;
'    return S_OK;
'}
' ========================================================================================
FUNCTION InitPropVariantFromInt16 (BYVAL nVal AS INTEGER, BYREF ppropvar AS PROPVARIANT) AS LONG
   ppropvar.vt = %VT_I2
   ppropvar.iVal = nVal
   FUNCTION = %S_OK
END FUNCTION
' ========================================================================================

' ========================================================================================
' Initializes a PROPVARIANT structure with an unsigned 16-bit integer value.
' ========================================================================================
'inline HRESULT InitPropVariantFromUInt16(__in USHORT uiVal, __out PROPVARIANT *ppropvar)
'{
'    ppropvar->vt = VT_UI2;
'    ppropvar->uiVal = uiVal;
'    return S_OK;
'}
' ========================================================================================
FUNCTION InitPropVariantFromUInt16 (BYVAL uiVal AS WORD, BYREF ppropvar AS PROPVARIANT) AS LONG
   ppropvar.vt = %VT_UI2
   ppropvar.uiVal = uiVal
   FUNCTION = %S_OK
END FUNCTION
' ========================================================================================

' ========================================================================================
' Initializes a PROPVARIANT structure with a 32-bit integer value.
' ========================================================================================
'inline HRESULT InitPropVariantFromInt32(__in LONG lVal, __out PROPVARIANT *ppropvar)
'{
'    ppropvar->vt = VT_I4;
'    ppropvar->lVal = lVal;
'    return S_OK;
'}
' ========================================================================================
FUNCTION InitPropVariantFromInt32 (BYVAL lVal AS LONG, BYREF ppropvar AS PROPVARIANT) AS LONG
   ppropvar.vt = %VT_I4
   ppropvar.lVal = lVal
   FUNCTION = %S_OK
END FUNCTION
' ========================================================================================

' ========================================================================================
' Initializes a PROPVARIANT structure with a 32-bit integer value.
' ========================================================================================
'inline HRESULT InitPropVariantFromUInt32(__in ULONG ulVal, __out PROPVARIANT *ppropvar)
'{
'    ppropvar->vt = VT_UI4;
'    ppropvar->ulVal = ulVal;
'    return S_OK;
'}
' ========================================================================================
FUNCTION InitPropVariantFromUInt32 (BYVAL ulVal AS DWORD, BYREF ppropvar AS PROPVARIANT) AS LONG
   ppropvar.vt = %VT_UI4
   ppropvar.ulVal = ulVal
   FUNCTION = %S_OK
END FUNCTION
' ========================================================================================

' ========================================================================================
' Initializes a PROPVARIANT structure with a 64-bit integer value.
' ========================================================================================
'inline HRESULT InitPropVariantFromInt64(__in LONGLONG llVal, __out PROPVARIANT *ppropvar)
'{
'    ppropvar->vt = VT_I8;
'    ppropvar->hVal.QuadPart = llVal;
'    return S_OK;
'}
' ========================================================================================
FUNCTION InitPropVariantFromInt64 (BYVAL llVal AS QUAD, BYREF ppropvar AS PROPVARIANT) AS LONG
   ppropvar.vt = %VT_I8
   ppropvar.hVal = llVal
   FUNCTION = %S_OK
END FUNCTION
' ========================================================================================

' PB doesn't currently support unsigned quads.
'inline HRESULT InitPropVariantFromUInt64(__in ULONGLONG ullVal, __out PROPVARIANT *ppropvar)
'{
'    ppropvar->vt = VT_UI8;
'    ppropvar->uhVal.QuadPart = ullVal;
'    return S_OK;
'}

' ========================================================================================
' Initializes a PROPVARIANT structure with a value of type DOUBLE.
' ========================================================================================
'inline HRESULT InitPropVariantFromDouble(__in DOUBLE dblVal, __out PROPVARIANT *ppropvar)
'{
'    ppropvar->vt = VT_R8;
'    ppropvar->dblVal = dblVal;
'    return S_OK;
'}
' ========================================================================================
FUNCTION InitPropVariantFromDouble (BYVAL dblVal AS DOUBLE, BYREF ppropvar AS PROPVARIANT) AS LONG
   ppropvar.vt = %VT_R8
   ppropvar.dblVal = dblVal
   FUNCTION = %S_OK
END FUNCTION
' ========================================================================================

' ========================================================================================
' Initializes a PROPVARIANT structure based on a specified string.
' ========================================================================================
'inline HRESULT InitPropVariantFromString(__in PCWSTR psz, __out PROPVARIANT *ppropvar)
'{
'    ppropvar->vt = VT_LPWSTR;
'    HRESULT hr = SHStrDupW(psz, &ppropvar->pwszVal);
'    if (FAILED(hr))
'    {
'        PropVariantInit(ppropvar);
'    }
'    return hr;
'}
' ========================================================================================
FUNCTION InitPropVariantFromString (BYREF psz AS WSTRINGZ, BYREF ppropvar AS PROPVARIANT) AS LONG
   LOCAL hr AS LONG
   ppropvar.vt = %VT_LPWSTR
   hr = SHStrDupW(psz, ppropvar.pwszVal)
   IF FAILED(hr) THEN PropVariantInit(ppropvar)
   FUNCTION = hr
END FUNCTION
' ========================================================================================

' ========================================================================================
' Initializes a PROPVARIANT structure based on a GUID. The structure is initialized as
' VT_ARRAY | VT_UI1.
' ========================================================================================
'inline HRESULT InitPropVariantFromGUIDAsBuffer(__in REFGUID guid, __out PROPVARIANT *ppropvar)
'{
'    return InitPropVariantFromBuffer(&guid, sizeof(GUID), ppropvar);
'}
' ========================================================================================
FUNCTION InitPropVariantFromGUIDAsBuffer (BYREF rguid AS GUID, BYREF ppropvar AS PROPVARIANT) AS LONG
   FUNCTION = InitPropVariantFromBuffer(rguid, 16, ppropvar)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Specifies whether a PROPVARIANT structure has a vector type.
' ========================================================================================
'inline BOOL IsPropVariantVector(__in REFPROPVARIANT propvar)
'{
'    return (propvar.vt & (VT_ARRAY | VT_VECTOR));
'}
' ========================================================================================
FUNCTION IsPropVariantVector (BYREF propvar AS PROPVARIANT) AS LONG
   FUNCTION = propvar.vt AND (%VT_ARRAY OR %VT_VECTOR)
END FUNCTION
' ========================================================================================

' ========================================================================================
' If TRUE, propvar contains a unicode string.
' Use PropVariantToStringWithDefault(propvar, NULL) to retrieve it.
' ========================================================================================
'inline BOOL IsPropVariantString(__in REFPROPVARIANT propvar)
'{
'    return (PropVariantToStringWithDefault(propvar, NULL) != NULL);
'}
' ========================================================================================
FUNCTION IsPropVariantString (BYREF propvar AS PROPVARIANT) AS LONG
   FUNCTION = PropVariantToStringWithDefault(propvar, BYVAL %NULL) <> %NULL
END FUNCTION
' ========================================================================================

'// Handles int instead of LONG
'inline HRESULT PropVariantToInt32(__in REFPROPVARIANT propvarIn, __out int *piRet)
'{
'    return PropVariantToInt32(propvarIn, (LONG*)piRet);
'}

'// Handles UINT instead of ULONG
'inline HRESULT PropVariantToUInt32(__in REFPROPVARIANT propvarIn, __out UINT *piRet)
'{
'    return PropVariantToUInt32(propvarIn, (ULONG*)piRet);
'}

' ========================================================================================
' Extracts class identifier (CLSID) property value of a PROPVARIANT structure.
' ========================================================================================
'inline HRESULT PropVariantToCLSID(__in REFPROPVARIANT propvarIn, __out CLSID *pclsid)
'{
'    return PropVariantToGUID(propvarIn, (GUID*)pclsid);
'}
' ========================================================================================
FUNCTION PropVariantToCLSID (BYREF propvarIn AS PROPVARIANT, BYREF pclsid AS GUID) AS LONG
   FUNCTION = PropVariantToGUID(propvarIn, pclsid)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Compares two PROPVARIANT structures, based on default comparison units and settings.
' ========================================================================================
'inline int PropVariantCompare(__in REFPROPVARIANT propvar1, __in REFPROPVARIANT propvar2)
'{
'    return PropVariantCompareEx(propvar1, propvar2, PVCU_DEFAULT, PVCF_DEFAULT);
'}
' ========================================================================================
FUNCTION PropVariantCompare (BYREF propvar1 AS PROPVARIANT, BYREF propvar2 AS PROPVARIANT) AS LONG
   FUNCTION = PropVariantCompareEx(propvar1, propvar2, %PVCU_DEFAULT, %PVCF_DEFAULT)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Initializes a PROPVARIANT structure based on a specified element in another PROPVARIANT structure.
' ========================================================================================
'inline HRESULT PropVariantGetElem(__in REFPROPVARIANT propvarIn, __in ULONG iElem, __out PROPVARIANT *ppropvar)
'{
'    return InitPropVariantFromPropVariantVectorElem(propvarIn, iElem, ppropvar);
'}
' ========================================================================================
FUNCTION PropVariantGetElem (BYREF propvarIn AS PROPVARIANT, BYVAL iElem AS DWORD, BYREF ppropvar AS PROPVARIANT) AS LONG
   FUNCTION = InitPropVariantFromPropVariantVectorElem(propvarIn, iElem, ppropvar)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Initializes a VARIANT structure with a Boolean value.
' ========================================================================================
'inline HRESULT InitVariantFromBoolean(__in BOOL fVal, __out VARIANT *pvar)
'{
'    pvar->vt = VT_BOOL;
'    pvar->boolVal = fVal ? VARIANT_TRUE : VARIANT_FALSE;
'    return S_OK;
'}
' ========================================================================================
FUNCTION InitVariantFromBoolean (BYVAL fVal AS LONG, BYREF pvar AS tagVARIANT) AS LONG
   pvar.vt = %VT_BOOL
   pvar.boolVal = IIF&(fVal <> 0, %VARIANT_TRUE, %VARIANT_FALSE)
   FUNCTION = %S_OK
END FUNCTION
' ========================================================================================

' ========================================================================================
' Initializes a VARIANT structure with a 16-bit integer value.
' ========================================================================================
'inline HRESULT InitVariantFromInt16(__in short iVal, __out VARIANT *pvar)
'{
'    pvar->vt = VT_I2;
'    pvar->iVal = iVal;
'    return S_OK;
'}
' ========================================================================================
FUNCTION InitVariantFromInt16 (BYVAL iVal AS INTEGER, BYREF pvar AS tagVARIANT) AS LONG
   pvar.vt = %VT_I2
   pvar.iVal = iVal
   FUNCTION = %S_OK
END FUNCTION
' ========================================================================================

' ========================================================================================
' Initializes a VARIANT structure with an unsigned 16-bit integer value.
' ========================================================================================
'inline HRESULT InitVariantFromUInt16(__in USHORT uiVal, __out VARIANT *pvar)
'{
'    pvar->vt = VT_UI2;
'    pvar->uiVal = uiVal;
'    return S_OK;
'}
' ========================================================================================
FUNCTION InitVariantFromUInt16 (BYVAL uiVal AS WORD, BYREF pvar AS tagVARIANT) AS LONG
   pvar.vt = %VT_UI2
   pvar.uiVal = uiVal
   FUNCTION = %S_OK
END FUNCTION
' ========================================================================================

' ========================================================================================
' Initializes a VARIANT structure with a 32-bit integer value.
' ========================================================================================
'inline HRESULT InitVariantFromInt32(__in LONG lVal, __out VARIANT *pvar)
'{
'    pvar->vt = VT_I4;
'    pvar->lVal = lVal;
'    return S_OK;
'}
' ========================================================================================
FUNCTION InitVariantFromInt32 (BYVAL lVal AS LONG, BYREF pvar AS tagVARIANT) AS LONG
   pvar.vt = %VT_I4
   pvar.lVal = lVal
   FUNCTION = %S_OK
END FUNCTION
' ========================================================================================

' ========================================================================================
' Initializes a VARIANT structure with an unsigned 32-bit integer value.
' ========================================================================================
'inline HRESULT InitVariantFromUInt32(__in ULONG ulVal, __out VARIANT *pvar)
'{
'    pvar->vt = VT_UI4;
'    pvar->ulVal = ulVal;
'    return S_OK;
'}
' ========================================================================================
FUNCTION InitVariantFromUInt32 (BYVAL ulVal AS DWORD, BYREF pvar AS tagVARIANT) AS LONG
   pvar.vt = %VT_UI4
   pvar.ulVal = ulVal
   FUNCTION = %S_OK
END FUNCTION
' ========================================================================================

' ========================================================================================
' Initializes a VARIANT structure with a 64-bit integer value.
' ========================================================================================
'inline HRESULT InitVariantFromInt64(__in LONGLONG llVal, __out VARIANT *pvar)
'{
'    pvar->vt = VT_I8;
'    pvar->llVal = llVal;
'    return S_OK;
'}
' ========================================================================================
FUNCTION InitVariantFromInt64 (BYVAL llVal AS QUAD, BYREF pvar AS tagVARIANT) AS LONG
   pvar.vt = %VT_I8
   pvar.llVal = llVal
   FUNCTION = %S_OK
END FUNCTION
' ========================================================================================

' PB doesn't currently support unsigned quads.
'inline HRESULT InitVariantFromUInt64(__in ULONGLONG ullVal, __out VARIANT *pvar)
'{
'    pvar->vt = VT_UI8;
'    pvar->ullVal = ullVal;
'    return S_OK;
'}

' ========================================================================================
' Initializes a VARIANT structure with a value of type DOUBLE.
' ========================================================================================
'inline HRESULT InitVariantFromDouble(__in DOUBLE dblVal, __out VARIANT *pvar)
'{
'    pvar->vt = VT_R8;
'    pvar->dblVal = dblVal;
'    return S_OK;
'}
' ========================================================================================
FUNCTION InitVariantFromDouble (BYVAL dblVal AS DOUBLE, BYREF pvar AS tagVARIANT) AS LONG
   pvar.vt = %VT_R8
   pvar.dblVal = dblVal
   FUNCTION = %S_OK
END FUNCTION
' ========================================================================================

' ========================================================================================
' Initializes a VARIANT structure with a string.
' ========================================================================================
'inline HRESULT InitVariantFromString(__in PCWSTR psz, __out VARIANT *pvar)
'{
'    pvar->vt = VT_BSTR;
'    pvar->bstrVal = SysAllocString(psz);
'    HRESULT hr =  pvar->bstrVal ? S_OK : (psz ? S_OK : E_OUTOFMEMORY);
'    if (FAILED(hr))
'    {
'        VariantInit(pvar);
'    }
'    return hr;
'}
' ========================================================================================
FUNCTION InitVariantFromString (BYREF psz AS WSTRINGZ, BYREF pvar AS tagVARIANT) AS LONG
   LOCAL hr AS LONG
   pvar.vt = %VT_BSTR
   pvar.bstrVal = SysAllocString(psz)
   hr = IIF&(pvar.bstrVal <> 0, %S_OK, %E_OUTOFMEMORY)
   IF FAILED(hr) THEN VariantInit(pvar)
   FUNCTION = hr
END FUNCTION
' ========================================================================================

' ========================================================================================
' Initializes a VARIANT structure based on an instance of an IDispatch object.
' ========================================================================================
'inline HRESULT InitVariantFromDispatch(__in_opt IDispatch* pdisp, __out VARIANT *pvar)
'{
'    pvar->vt = VT_DISPATCH;
'    pvar->pdispVal = pdisp;
'    if (pvar->pdispVal)
'    {
'        (pvar->pdispVal)->AddRef();
'    }
'    return S_OK;
'}
' ========================================================================================
FUNCTION InitVariantFromDispatch (BYVAL pDisp AS IDispatch, BYREF pvar AS tagVARIANT) AS LONG
   LOCAL hr AS LONG
   pvar.vt = %VT_DISPATCH
   pvar.pdispVal = OBJPTR(pDisp)
   IF pvar.pdispVal THEN pDisp.AddRef
   FUNCTION = %S_OK
END FUNCTION
' ========================================================================================

' ========================================================================================
' Initializes a VARIANT structure with a date and time given in the format used by
' Microsoft MS-DOS. The date and time values are converted to the format used to store
' date and time in a VARIANT.
' ========================================================================================
'inline HRESULT InitVariantFromDosDateTime(__in WORD wDate, __in WORD wTime, __out VARIANT *pvar)
'{
'    pvar->vt = VT_DATE;
'    return DosDateTimeToVariantTime(wDate, wTime, &pvar->date) ? S_OK : S_FALSE;
'}
' ========================================================================================
FUNCTION InitVariantFromDosDateTime(BYVAL wDate AS WORD, BYVAL wTime AS WORD, BYREF pvar AS tagVARIANT) AS LONG
   pvar.vt = %VT_DATE
   FUNCTION = IIF&(DosDateTimeToVariantTime(wDate, wTime, pvar.date) = %TRUE, %S_OK, %S_FALSE)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns whether a VARTYPE is a float.
' ========================================================================================
'inline BOOL IsVarTypeFloat(__in VARTYPE vt)
'{
'    return (vt == VT_R4 || vt == VT_R8);
'}
' ========================================================================================
FUNCTION IsVarTypeFloat (BYVAL vt AS WORD) AS LONG
   FUNCTION = (vt = %VT_R4 OR vt = %VT_R8)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Specifies whether a variant is an array.
' ========================================================================================
'inline BOOL IsVariantArray(__in REFVARIANT var)
'{
'    return (var.vt & VT_ARRAY);
'}
' ========================================================================================
FUNCTION IsVariantArray (BYREF var AS tagVARIANT) AS LONG
   FUNCTION = (var.vt AND %VT_ARRAY)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Specifies whether a variant is a string.
' If TRUE, you can use VariantToStringCast to obtain the string pointer
' ========================================================================================
'inline BOOL IsVariantString(__in REFVARIANT var)
'{
'    return (VariantToStringWithDefault(var, NULL) != NULL);
'}
' ========================================================================================
FUNCTION IsVariantString (BYREF var AS tagVARIANT) AS LONG
   FUNCTION = VariantToStringWithDefault(var, BYVAL %NULL) <> %NULL
END FUNCTION
' ========================================================================================

' ========================================================================================
' Specifies whether VARTYPE is a number.
' ========================================================================================
'inline BOOL IsVarTypeNumber(__in VARTYPE vt)
'{
'    return IsVarTypeInteger(vt) || IsVarTypeFloat(vt);
'}
' ========================================================================================
FUNCTION IsVarTypeNumber (BYVAL vt AS WORD) AS LONG
   FUNCTION = IsVarTypeInteger(vt) OR IsVarTypeFloat(vt)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns whether a VARTYPE is a signed integer.
' ========================================================================================
'inline BOOL IsVarTypeSignedInteger(__in VARTYPE vt)
'{
'    BOOL fRet = FALSE;
'    switch (vt)
'    {
'        case VT_I1:
'        case VT_I2:
'        case VT_I4:
'        case VT_I8:
'        fRet = TRUE;
'    }
'    return fRet;
'}
' ========================================================================================
FUNCTION IsVarTypeSignedInteger (BYVAL vt AS WORD) AS LONG
   LOCAL fRet AS LONG
   fRet = %FALSE
   SELECT CASE vt
      CASE %VT_I1, %VT_I2, %VT_I4, %VT_I8
         fRet = %TRUE
   END SELECT
   FUNCTION = fRet
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns whether a VARTYPE is an unsigned integer.
' ========================================================================================
'inline BOOL IsVarTypeUnsignedInteger(__in VARTYPE vt)
'{
'    BOOL fRet = FALSE;
'    switch (vt)
'    {
'        case VT_UI1:
'        case VT_UI2:
'        case VT_UI4:
'        case VT_UI8:
'        fRet = TRUE;
'    }
'    return fRet;
'}
' ========================================================================================
FUNCTION IsVarTypeUnsignedInteger (BYVAL vt AS WORD) AS LONG
   LOCAL fRet AS LONG
   fRet = %FALSE
   SELECT CASE vt
      CASE %VT_UI1, %VT_UI2, %VT_UI4, %VT_UI8
         fRet = %TRUE
   END SELECT
   FUNCTION = fRet
END FUNCTION
' ========================================================================================

' ========================================================================================
' Returns whether a VARTYPE is an integer.
' ========================================================================================
'inline BOOL IsVarTypeInteger(__in VARTYPE vt)
'{
'    return IsVarTypeSignedInteger(vt) || IsVarTypeUnsignedInteger(vt);
'}
' ========================================================================================
FUNCTION IsVarTypeInteger (BYVAL vt AS WORD) AS LONG
   FUNCTION = IsVarTypeSignedInteger(vt) OR IsVarTypeUnsignedInteger(vt)
END FUNCTION
' ========================================================================================

' ========================================================================================
' Initializes a VARIANT structure based on a GUID. The structure is initialized as
' VT_ARRAY | VT_UI1.
' ========================================================================================
'inline HRESULT InitVariantFromGUIDAsBuffer(__in REFGUID guid, __out VARIANT *pvar)
'{
'    return InitVariantFromBuffer(&guid, sizeof(GUID), pvar);
'}
' ========================================================================================
FUNCTION InitVariantFromGUIDAsBuffer (BYREF rguid AS GUID, BYREF pvar AS tagVARIANT) AS LONG
   FUNCTION = InitVariantFromBuffer(rguid, 16, pvar)
END FUNCTION
' ========================================================================================

'// Handles int instead of LONG
'inline HRESULT VariantToInt32(__in REFVARIANT varIn, __out int *piRet)
'{
'    return VariantToInt32(varIn, (LONG*)piRet);
'}

'// Handles UINT instead of ULONG
'inline HRESULT VariantToUInt32(__in REFVARIANT varIn, __out UINT *piRet)
'{
'    return VariantToUInt32(varIn, (ULONG*)piRet);
'}

' ========================================================================================
' Initializes a VARIANT structure from a specified variant element.
' ========================================================================================
'inline HRESULT VariantGetElem(__in REFVARIANT varIn, __in ULONG iElem, __out VARIANT *pvar)
'{
'    return InitVariantFromVariantArrayElem(varIn, iElem, pvar);
'}
' ========================================================================================
FUNCTION VariantGetElem (BYREF varIn AS tagVARIANT, BYVAL iElem AS DWORD, BYREF pvar AS tagVARIANT) AS LONG
   FUNCTION = InitVariantFromVariantArrayElem(varIn, iElem, pvar)
END FUNCTION
' ========================================================================================

'#endif // __cplusplus
