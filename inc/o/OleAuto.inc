' ########################################################################################
' Microsoft Windows
' File: OleAuto.inc
' Contents: Defines Ole Automation support function prototypes, constants
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%OLEAUTO_INC = 1

#INCLUDE ONCE "ole2.inc"

'// Set packing to 8 for ISV, and Win95 support
'#ifndef RC_INVOKED
'#include <pshpack8.h>
'#endif // RC_INVOKED

'EXTERN_C const IID IID_StdOle;
$IID_StdOle = GUID$("{00020430-0000-0000-C000-000000000046}")

%STDOLE_MAJORVERNUM  = &H1
%STDOLE_MINORVERNUM  = &H0
%STDOLE_LCID         = &H0000

'// Version # of stdole2.tlb
%STDOLE2_MAJORVERNUM = &H2
%STDOLE2_MINORVERNUM = &H0
%STDOLE2_LCID        = &H0000

'/* if not already picked up from olenls.h */
'#ifndef _LCID_DEFINED
''typedef DWORD LCID;
'# define _LCID_DEFINED
'#endif

'/* pull in the MIDL generated header */
#INCLUDE ONCE "oaidl.inc"


'/*---------------------------------------------------------------------*/
'/*                            BSTR API                                 */
'/*---------------------------------------------------------------------*/

' ========================================================================================
' Note: The return type has been declared as DWORD instead of as WSTRING for compatibility
' with old code and because sometimes we need to pass a pointer to a BSTR that will be
' freed by the called function or method. Also because, otherwise, it will be useless since
' it will produce the same result that declaring DIM bstr AS WSTRING.
' ========================================================================================
DECLARE FUNCTION SysAllocString IMPORT "OLEAUT32.DLL" ALIAS "SysAllocString" ( _
   BYREF sz AS WSTRINGZ _                               ' __in const OLECHAR * sz
 ) AS DWORD                                             ' BSTR

' ========================================================================================
' Note: The pbstr parameter has been declared as DWORD instead of WSTRING to allow his use
' with the strings allocated using SysAllocString. What this function does is to free the
' old BSTR with SysFreeStrin, allocate a new string with SysAllocateString, and copy the
' new handle in the passed parameter. Therefore, you have to pass the handle to the string
' to reallocate by reference with VARPTR.
' ========================================================================================
DECLARE FUNCTION SysReAllocString IMPORT "OLEAUT32.DLL" ALIAS "SysReAllocString" ( _
   BYVAL pbstr AS DWORD _                               ' __in BSTR FAR* pbstr
 , BYREF psz AS WSTRINGZ _                              ' __in const OLECHAR FAR* psz
 ) AS LONG                                              ' int

' ========================================================================================
' Note: The return type has been declared as DWORD instead of as WSTRING for the reasons
' explained in the comments to the SysAllocString function.
' ========================================================================================
DECLARE FUNCTION SysAllocStringLen IMPORT "OLEAUT32.DLL" ALIAS "SysAllocStringLen" ( _
   BYREF pch AS WSTRINGZ _                              ' __in const OLECHAR * pch
 , BYVAL cch AS DWORD _                                 ' __in unsigned int cch
 ) AS DWORD                                             ' BSTR

' ========================================================================================
' Note: The pbstr parameter has been declared as DWORD instead of WSTRING to allow his use
' with the strings allocated with SysAllocStringLen.
' ========================================================================================
DECLARE FUNCTION SysReAllocStringLen IMPORT "OLEAUT32.DLL" ALIAS "SysReAllocStringLen" ( _
   BYVAL pbstr AS DWORD _                               ' __in BSTR FAR* pbstr
 , BYREF psz AS WSTRINGZ _                              ' __in const OLECHAR FAR* psz
 , BYVAL cch AS DWORD _                                 ' __in unsigned int cch
 ) AS LONG                                              ' int

' ========================================================================================
' Note: The bstr parameter has been declared as DWORD instead of WSTRING to allow to be
' used with strings allocated with SysAllocString or SysAllocStringLen. Also because.
' otherwise, it will be useless since strings allocated by PowerBASIC are freed automatically.
' ========================================================================================
DECLARE SUB SysFreeString IMPORT "OLEAUT32.DLL" ALIAS "SysFreeString" ( _
   BYVAL bstr AS DWORD _                                ' __in BSTR bstr
 )                                                      ' void

' ========================================================================================
' Note: The bstr parameter has been declared as DWORD instead of WSTRING to allow his use
' with the strings allocated with SysAllocStringLen.
' ========================================================================================
DECLARE FUNCTION SysStringLen IMPORT "OLEAUT32.DLL" ALIAS "SysStringLen" ( _
   BYVAL bstr AS DWORD _                                ' __in BSTR bstr
 ) AS DWORD                                             ' UINT

'#if (defined (_WIN32) || defined (_WIN64))

' ========================================================================================
' Note: The bstr parameter has been declared as DWORD instead of WSTRING to allow his use
' with the strings allocated with SysAllocStringByteLen.
' ========================================================================================
DECLARE FUNCTION SysStringByteLen IMPORT "OLEAUT32.DLL" ALIAS "SysStringByteLen" ( _
   BYVAL bstr AS DWORD _                                ' __in BSTR bstr
 ) AS DWORD                                             ' UINT

' ========================================================================================
' Note: The return type has been declared as DWORD instead of as WSTRING for the reasons
' explained in the comments to the SysAllocString function.
' ========================================================================================
DECLARE FUNCTION SysAllocStringByteLen IMPORT "OLEAUT32.DLL" ALIAS "SysAllocStringByteLen" ( _
   BYREF psz AS ASCIIZ _                                ' __in LPCSTR  psz
 , BYVAL len AS DWORD _                                 ' __in unsigned int len
 ) AS DWORD                                             ' BSTR

'#endif

'/*---------------------------------------------------------------------*/
'/*                            Time API                                 */
'/*---------------------------------------------------------------------*/

DECLARE FUNCTION DosDateTimeToVariantTime IMPORT "OLEAUT32.DLL" ALIAS "DosDateTimeToVariantTime" ( _
   BYVAL wDosDate AS WORD _                             ' __in  unsigned short wDosDate
 , BYVAL wDosTime AS WORD _                             ' __in  unsigned short  wDosTime
 , BYREF pvtime AS DOUBLE _                             ' __out double * pvtime
 ) AS LONG                                              ' int

DECLARE FUNCTION VariantTimeToDosDateTime IMPORT "OLEAUT32.DLL" ALIAS "VariantTimeToDosDateTime" ( _
   BYVAL vtime AS DOUBLE _                              ' __in  double vtime
 , BYREF pwDosDate AS WORD _                            ' __in  unsigned short * pwDosDate
 , BYREF pwDosTime AS WORD _                            ' __out unsigned short * pwDosTime
 ) AS LONG                                              ' int

'#if (defined (_WIN32) || defined (_WIN64))

DECLARE FUNCTION SystemTimeToVariantTime IMPORT "OLEAUT32.DLL" ALIAS "SystemTimeToVariantTime" ( _
   BYREF lpSystemTime AS SYSTEMTIME _                   ' __in  LPSYSTEMTIME lpSystemTime
 , BYREF pvtime AS DOUBLE _                             ' __out double *pvtime
 ) AS LONG                                              ' int

DECLARE FUNCTION VariantTimeToSystemTime IMPORT "OLEAUT32.DLL" ALIAS "VariantTimeToSystemTime" ( _
   BYVAL vtime AS DOUBLE _                              ' __in  double vtime
 , BYREF lpSystemTime AS SYSTEMTIME _                   ' __out LPSYSTEMTIME lpSystemTime
 ) AS LONG                                              ' int

'#endif


'/*---------------------------------------------------------------------*/
'/*                          SafeArray API                              */
'/*---------------------------------------------------------------------*/

DECLARE FUNCTION SafeArrayAllocDescriptor IMPORT "OLEAUT32.DLL" ALIAS "SafeArrayAllocDescriptor" ( _
   BYVAL cDims AS WORD _                                ' __in  unsigned int cDims
 , BYREF ppsaOut AS ANY _                               ' __out SAFEARRAY ** ppsaOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION SafeArrayAllocDescriptorEx IMPORT "OLEAUT32.DLL" ALIAS "SafeArrayAllocDescriptorEx" ( _
   BYVAL vt AS WORD _                                   ' __in  VARTYPE vt
 , BYVAL cDims AS WORD _                                ' __in  unsigned int cDims
 , BYREF ppsaOut AS ANY _                               ' __out SAFEARRAY** ppsaOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION SafeArrayAllocData IMPORT "OLEAUT32.DLL" ALIAS "SafeArrayAllocData" ( _
   BYVAL psa AS DWORD _                                 ' __in SAFEARRAY * psa
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION SafeArrayCreate IMPORT "OLEAUT32.DLL" ALIAS "SafeArrayCreate" ( _
   BYVAL vt AS WORD _                                   ' __in VARTYPE vt
 , BYVAL cDims AS DWORD _                               ' __in unsigned int cDims
 , BYREF rgsabound AS SAFEARRAYBOUND _                  ' __in SAFEARRAYBOUND * rgsabound [array]
 ) AS DWORD                                             ' SAFEARRAY*

DECLARE FUNCTION SafeArrayCreateEx IMPORT "OLEAUT32.DLL" ALIAS "SafeArrayCreateEx" ( _
   BYVAL vt AS WORD _                                   ' __in VARTYPE vt
 , BYVAL cDims AS WORD _                                ' __in unsigned int cDims
 , BYREF rgsabound AS SAFEARRAYBOUND _                  ' __in SAFEARRAYBOUND * rgsabound [array]
 , BYREF pvExtra AS ANY _                               ' __in PVOID pvExtra
 ) AS DWORD                                             ' SAFEARRAY*

DECLARE FUNCTION SafeArrayCopyData IMPORT "OLEAUT32.DLL" ALIAS "SafeArrayCopyData" ( _
   BYVAL psaSource AS DWORD _                           ' __in SAFEARRAY FAR* psaSource
 , BYVAL psaTarget AS DWORD _                           ' __in SAFEARRAY FAR* psaTarget
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION SafeArrayDestroyDescriptor IMPORT "OLEAUT32.DLL" ALIAS "SafeArrayDestroyDescriptor" ( _
   BYVAL psa AS DWORD _                                 ' __in SAFEARRAY * psa
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION SafeArrayDestroyData IMPORT "OLEAUT32.DLL" ALIAS "SafeArrayDestroyData" ( _
   BYVAL psa AS DWORD _                                 ' __in SAFEARRAY * psa
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION SafeArrayDestroy IMPORT "OLEAUT32.DLL" ALIAS "SafeArrayDestroy" ( _
   BYVAL psa AS DWORD _                                 ' __in SAFEARRAY * psa
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION SafeArrayRedim IMPORT "OLEAUT32.DLL" ALIAS "SafeArrayRedim" ( _
   BYVAL psa AS DWORD _                                 ' __in SAFEARRAY * psa
 , BYREF psaboundNew AS SAFEARRAYBOUND _                ' __in SAFEARRAYBOUND * psaboundNew
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION SafeArrayGetDim IMPORT "OLEAUT32.DLL" ALIAS "SafeArrayGetDim" ( _
   BYVAL psa AS DWORD _                                 ' __in SAFEARRAY * psa
 ) AS DWORD                                             ' UINT

DECLARE FUNCTION SafeArrayGetElemsize IMPORT "OLEAUT32.DLL" ALIAS "SafeArrayGetElemsize" ( _
   BYVAL psa AS DWORD _                                 ' __in SAFEARRAY * psa
 ) AS DWORD                                             ' UINT

DECLARE FUNCTION SafeArrayGetUBound IMPORT "OLEAUT32.DLL" ALIAS "SafeArrayGetUBound" ( _
   BYVAL psa AS DWORD _                                 ' __in  SAFEARRAY * psa
 , BYVAL nDim AS WORD _                                 ' __in  unsigned int nDim
 , BYREF plUbound AS LONG _                             ' __out long * plUbound
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION SafeArrayGetLBound IMPORT "OLEAUT32.DLL" ALIAS "SafeArrayGetLBound" ( _
   BYVAL psa AS DWORD _                                 ' __in  SAFEARRAY * psa
 , BYVAL nDim AS WORD _                                 ' __in  unsigned int nDim
 , BYREF plLbound AS LONG _                             ' __out long * plLbound
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION SafeArrayLock IMPORT "OLEAUT32.DLL" ALIAS "SafeArrayLock" ( _
   BYVAL psa AS DWORD _                                 ' __in SAFEARRAY * psa
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION SafeArrayUnlock IMPORT "OLEAUT32.DLL" ALIAS "SafeArrayUnlock" ( _
   BYVAL psa AS DWORD _                                 ' __in SAFEARRAY * psa
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION SafeArrayAccessData IMPORT "OLEAUT32.DLL" ALIAS "SafeArrayAccessData" ( _
   BYVAL psa AS DWORD _                                 ' __in SAFEARRAY * psa
 , BYREF ppvData AS ANY _                               ' __in void HUGEP ** ppvData
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION SafeArrayUnaccessData IMPORT "OLEAUT32.DLL" ALIAS "SafeArrayUnaccessData" ( _
   BYVAL psa AS DWORD _                                 ' __in SAFEARRAY * psa
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION SafeArrayGetElement IMPORT "OLEAUT32.DLL" ALIAS "SafeArrayGetElement" ( _
   BYVAL psa AS DWORD _                                 ' __in SAFEARRAY * psa
 , BYREF rgIndices AS LONG _                            ' __in long * rgIndices [array]
 , BYREF pv AS ANY _                                    ' __out void * pv
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION SafeArrayPutElement IMPORT "OLEAUT32.DLL" ALIAS "SafeArrayPutElement" ( _
   BYVAL psa AS DWORD _                                 ' __in SAFEARRAY * psa
 , BYREF rgIndices AS LONG _                            ' __in long * rgIndices [array]
 , BYREF pv AS ANY _                                    ' __in void * pv
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION SafeArrayCopy IMPORT "OLEAUT32.DLL" ALIAS "SafeArrayCopy" ( _
   BYVAL psa AS DWORD _                                 ' __in  SAFEARRAY * psa
 , BYREF ppsaOut AS ANY _                               ' __out SAFEARRAY ** ppsaOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION SafeArrayPtrOfIndex IMPORT "OLEAUT32.DLL" ALIAS "SafeArrayPtrOfIndex" ( _
   BYVAL psa AS DWORD _                                 ' __in  SAFEARRAY * psa
 , BYREF rgIndices AS LONG _                            ' __in  long * rgIndices [array]
 , BYREF ppvData AS ANY _                               ' __out void HUGEP** ppvData
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION SafeArraySetRecordInfo IMPORT "OLEAUT32.DLL" ALIAS "SafeArraySetRecordInfo" ( _
   BYVAL psa AS DWORD _                                 ' __in SAFEARRAY * psa
 , BYVAL psaboundNew AS IRecordInfo _                   ' __in IRecordInfo * psaboundNew
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION SafeArrayGetRecordInfo IMPORT "OLEAUT32.DLL" ALIAS "SafeArrayGetRecordInfo" ( _
   BYVAL psa AS DWORD _                                 ' __in  SAFEARRAY * psa
 , BYREF prinfo AS IRecordInfo _                        ' __out IRecordInfo ** prinfo
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION SafeArraySetIID IMPORT "OLEAUT32.DLL" ALIAS "SafeArraySetIID" ( _
   BYVAL psa AS DWORD _                                 ' __in SAFEARRAY * psa
 , BYREF pguid AS GUID _                                ' __in REFGUID pguid
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION SafeArrayGetIID IMPORT "OLEAUT32.DLL" ALIAS "SafeArrayGetIID" ( _
   BYVAL psa AS DWORD _                                 ' __in  SAFEARRAY * psa
 , BYREF pguid AS GUID _                                ' __out GUID * pguid
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION SafeArrayGetVartype IMPORT "OLEAUT32.DLL" ALIAS "SafeArrayGetVartype" ( _
   BYVAL psa AS DWORD _                                 ' __in  SAFEARRAY * psa
 , BYREF pvt AS WORD _                                  ' __out VARTYPE * pvt
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION SafeArrayCreateVector IMPORT "OLEAUT32.DLL" ALIAS "SafeArrayCreateVector" ( _
   BYVAL vt AS WORD _                                   ' __in VARTYPE  vt
 , BYVAL lLbound AS LONG _                              ' __in long lLbound
 , BYVAL cElements AS WORD _                            ' __in unsigned int cElements
 ) AS DWORD                                             ' SAFEARRAY*

DECLARE FUNCTION SafeArrayCreateVectorEx IMPORT "OLEAUT32.DLL" ALIAS "SafeArrayCreateVectorEx" ( _
   BYVAL vt AS WORD _                                   ' __in VARTYPE  vt
 , BYVAL lLbound AS LONG _                              ' __in long lLbound
 , BYVAL cElements AS WORD _                            ' __in unsigned int cElements
 , BYREF pvExtra AS ANY _                               ' __in LPVOID  pvExtra
 ) AS DWORD                                             ' SAFEARRAY*

'/*---------------------------------------------------------------------*/
'/*                           VARIANT API                               */
'/*---------------------------------------------------------------------*/

' Note: Using AS ANY disables type checking, so you can pass variants declared with PB and
' variants declared as VARIANTAPI or tagVARIANT.
' * Example:
'   DIM v1 as VARIANTAPI, v2 AS VARIANT
'   VariantInit v1
'   v2 = 12345 AS DWORD
'   VariantCopy v1, v2

DECLARE SUB VariantInit IMPORT "OLEAUT32.DLL" ALIAS "VariantInit" ( _
   BYREF pvarg AS ANY _                                 ' __in VARIANTARG *  pvarg
 )                                                      ' void

DECLARE FUNCTION VariantClear IMPORT "OLEAUT32.DLL" ALIAS "VariantClear" ( _
   BYREF pvarg AS ANY _                                 ' __in VARIANTARG * pvarg
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VariantCopy IMPORT "OLEAUT32.DLL" ALIAS "VariantCopy" ( _
   BYREF pvargDest AS ANY _                             ' __in_out VARIANTARG * pvargDest
 , BYREF pvarSrc AS ANY _                               ' __in VARIANTARG * pvarSrc
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VariantCopyInd IMPORT "OLEAUT32.DLL" ALIAS "VariantCopyInd" ( _
   BYREF pvarg AS ANY _                                 ' __in  VARIANTARG * pvarg
 , BYREF pvarSrc AS ANY _                               ' __out VARIANTARG * pvarSrc
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VariantChangeType IMPORT "OLEAUT32.DLL" ALIAS "VariantChangeType" ( _
   BYREF pvargDest AS ANY _                             ' __in_out VARIANTARG * pvargDest
 , BYREF pvarSrc AS ANY _                               ' __in VARIANTARG * pvarSrc
 , BYVAL wFlags AS WORD _                               ' __in unsigned short wFlags
 , BYVAL vt AS WORD _                                   ' __in VARTYPE vt
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VariantChangeTypeEx IMPORT "OLEAUT32.DLL" ALIAS "VariantChangeTypeEx" ( _
   BYREF pvargDest AS ANY _                             ' __in_out VARIANTARG * pvargDest
 , BYREF pvarSrc AS ANY _                               ' __in VARIANTARG * pvarSrc
 , BYVAL lcid AS DWORD _                                ' __in LCID lcid
 , BYVAL wFlags AS WORD _                               ' __in unsigned short wFlags
 , BYVAL vt AS WORD _                                   ' __in VARTYPE vt
 ) AS LONG                                              ' HRESULT

'// Flags for VariantChangeType/VariantChangeTypeEx
'#define VARIANT_NOVALUEPROP      0x01
'#define VARIANT_ALPHABOOL        0x02 // For VT_BOOL to VT_BSTR conversions,
'                                      // convert to "True"/"False" instead of
'                                      // "-1"/"0"
'#define VARIANT_NOUSEROVERRIDE   0x04 // For conversions to/from VT_BSTR,
'                  // passes LOCALE_NOUSEROVERRIDE
'                  // to core coercion routines
'#define VARIANT_CALENDAR_HIJRI   0x08
'#define VARIANT_LOCALBOOL        0x10 // For VT_BOOL to VT_BSTR and back,
'                                      // convert to local language rather than
'                                      // English
'#define VARIANT_CALENDAR_THAI      0x20  // SOUTHASIA calendar support
'#define VARIANT_CALENDAR_GREGORIAN 0x40  // SOUTHASIA calendar support
'#define VARIANT_USE_NLS            0x80  // NLS function call support

%VARIANT_NOVALUEPROP        = &H01??
%VARIANT_ALPHABOOL          = &H02??
%VARIANT_NOUSEROVERRIDE     = &H04??
%VARIANT_CALENDAR_HIJRI     = &H08??
%VARIANT_LOCALBOOL          = &H10??
%VARIANT_CALENDAR_THAI      = &H20??  ' // SOUTHASIA calendar support
%VARIANT_CALENDAR_GREGORIAN = &H40??  ' // SOUTHASIA calendar support
%VARIANT_USE_NLS            = &H80??  ' // NLS function call support

'/*---------------------------------------------------------------------*/
'/*                Vector <-> Bstr conversion APIs                      */
'/*---------------------------------------------------------------------*/

DECLARE FUNCTION BstrFromVector IMPORT "OLEAUT32.DLL" ALIAS "BstrFromVector" ( _
   BYVAL psa AS DWORD _                                 ' __in  SAFEARRAY * psa
 , BYREF pbstr AS WSTRING _                             ' __out BSTR * pbstr
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VectorFromBstr IMPORT "OLEAUT32.DLL" ALIAS "VectorFromBstr" ( _
   BYVAL bstr AS WSTRING _                              ' __in  BSTR bstr
 , BYREF ppsa AS ANY _                                  ' __out SAFEARRAY ** ppsa
 ) AS LONG                                              ' HRESULT

'/*---------------------------------------------------------------------*/
'/*                     Variant API Flags                               */
'/*---------------------------------------------------------------------*/

'/* Any of the coersion functions that converts either from or to a string
' * takes an additional lcid and dwFlags arguments. The lcid argument allows
' * locale specific parsing to occur.  The dwFlags allow additional function
' * specific condition to occur.  All function that accept the dwFlags argument
' * can include either 0 or LOCALE_NOUSEROVERRIDE flag.
' */

'/* The VarDateFromStr and VarBstrFromDate functions also accept the
' * VAR_TIMEVALUEONLY and VAR_DATEVALUEONLY flags
' */
'#define VAR_TIMEVALUEONLY       ((DWORD)0x00000001)    /* return time value */
'#define VAR_DATEVALUEONLY       ((DWORD)0x00000002)    /* return date value */
%VAR_TIMEVALUEONLY = &H00000001???   ' /* return time value */
%VAR_DATEVALUEONLY = &H00000002???   ' /* return date value */

'/* VarDateFromUdate() only */
'#define VAR_VALIDDATE           ((DWORD)0x00000004)
%VAR_VALIDDATE = &H00000004???

'/* Accepted by all date & format APIs */
'#define VAR_CALENDAR_HIJRI      ((DWORD)0x00000008)    /* use Hijri calender */
%VAR_CALENDAR_HIJRI =&H00000008???   ' /* use Hijri calender */

'/* Booleans can optionally be accepted in localized form. Pass VAR_LOCALBOOL
' * into VarBoolFromStr and VarBstrFromBool to use localized boolean names
' */
'#define VAR_LOCALBOOL           ((DWORD)0x00000010)
%VAR_LOCALBOOL = &H00000010???

'/* When passed into VarFormat and VarFormatFromTokens, prevents substitution
' * of formats in the case where a string is passed in that can not be
' * coverted into the desired type. (for ex, 'Format("Hello", "General Number")')
' */
'#define VAR_FORMAT_NOSUBSTITUTE ((DWORD)0x00000020)
%VAR_FORMAT_NOSUBSTITUTE = &H00000020???

'/*
' * For VarBstrFromDate only - forces years to be 4 digits rather than shortening
' * to 2-digits when the years is in the date window.
' */
'#define VAR_FOURDIGITYEARS   ((DWORD)0x00000040)
%VAR_FOURDIGITYEARS = &H00000040???

'/*
' * Use NLS functions to format date, currency, time, and number.
' */
#IF NOT %DEF(%LOCALE_USE_NLS)
%LOCALE_USE_NLS = &H10000000
#ENDIF

'// SOUTHASIA START
'/* SOUTHASIA
' * For VarBstrFromDate only - forces years to be 4 digits rather than shortening
' * to 2-digits when the years is in the date window.
' */
'#define VAR_CALENDAR_THAI      ((DWORD)0x00000080)
'#define   VAR_CALENDAR_GREGORIAN ((DWORD)0x00000100)
%VAR_CALENDAR_THAI      = &H00000080???
%VAR_CALENDAR_GREGORIAN = &H00000100???
'//SOUTHASIA END

%VTDATEGRE_MAX = 2958465  ' /* Dec 31, 9999, 0:0:0 in Gregorain Calendar */
%VTDATEGRE_MIN = -657434  ' /* Jan  1,  100, 0:0:0 in Gregorain Calendar */


'/*---------------------------------------------------------------------*/
'/*                     VARTYPE Coercion API                            */
'/*---------------------------------------------------------------------*/

'/* Note: The routines that convert *from* a string are defined
' * to take a OLECHAR* rather than a BSTR because no allocation is
' * required, and this makes the routines a bit more generic.
' * They may of course still be passed a BSTR as the strIn param.
' */

DECLARE FUNCTION VarUI1FromI2 IMPORT "OLEAUT32.DLL" ALIAS "VarUI1FromI2" ( _
   BYVAL sIn AS INTEGER _                               ' __in  SHORT sIn
 , BYREF pbOut AS BYTE _                                ' __out BYTE * pbOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarUI1FromI4 IMPORT "OLEAUT32.DLL" ALIAS "VarUI1FromI4" ( _
   BYVAL lIn AS LONG _                                  ' __in  LONG lIn
 , BYREF pbOut AS BYTE _                                ' __out BYTE * pbOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarUI1FromI8 IMPORT "OLEAUT32.DLL" ALIAS "VarUI1FromI8" ( _
   BYVAL i64In AS QUAD _                                ' __in  LONG64 i64In
 , BYREF pbOut AS BYTE _                                ' __out BYTE * pbOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarUI1FromR4 IMPORT "OLEAUT32.DLL" ALIAS "VarUI1FromR4" ( _
   BYVAL fltIn AS SINGLE _                              ' __in  FLOAT fltIn
 , BYREF pbOut AS BYTE _                                ' __out BYTE * pbOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarUI1FromR8 IMPORT "OLEAUT32.DLL" ALIAS "VarUI1FromR8" ( _
   BYVAL dblIn AS DOUBLE _                              ' __in  DOUBLE dblIn
 , BYREF pbOut AS BYTE _                                ' __out BYTE * pbOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarUI1FromCy IMPORT "OLEAUT32.DLL" ALIAS "VarUI1FromCy" ( _
   BYVAL cyIn AS CUR _                                  ' __in  CY cyIn
 , BYREF pbOut AS BYTE _                                ' __out BYTE * pbOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarUI1FromDate IMPORT "OLEAUT32.DLL" ALIAS "VarUI1FromDate" ( _
   BYVAL dateIn AS DOUBLE _                             ' __in  DATE dateIn
 , BYREF pbOut AS BYTE _                                ' __out BYTE * pbOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarUI1FromStr IMPORT "OLEAUT32.DLL" ALIAS "VarUI1FromStr" ( _
   BYREF strIn AS WSTRINGZ _                            ' __in  OLECHAR * strIn
 , BYVAL lcid AS DWORD _                                ' __in  LCID lcid
 , BYVAL dwFlags AS DWORD _                             ' __in  ULONG dwFlags
 , BYREF pbOut AS BYTE _                                ' __out BYTE * pbOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarUI1FromDisp IMPORT "OLEAUT32.DLL" ALIAS "VarUI1FromDisp" ( _
   BYVAL pdispIn AS IDispatch _                         ' __in  IDispatch * pdispIn
 , BYVAL lcid AS DWORD _                                ' __in  LCID lcid
 , BYREF pbOut AS BYTE _                                ' __out BYTE * pbOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarUI1FromBool IMPORT "OLEAUT32.DLL" ALIAS "VarUI1FromBool" ( _
   BYVAL boolIn AS INTEGER _                            ' __in  VARIANT_BOOL boolIn
 , BYREF pbOut AS BYTE _                                ' __out BYTE * pbOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarUI1FromI1 IMPORT "OLEAUT32.DLL" ALIAS "VarUI1FromI1" ( _
   BYVAL cIn AS BYTE _                                  ' __in  CHAR cIn
 , BYREF pbOut AS BYTE _                                ' __out BYTE * pbOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarUI1FromUI2 IMPORT "OLEAUT32.DLL" ALIAS "VarUI1FromUI2" ( _
   BYVAL uiIn AS WORD _                                 ' __in  USHORT uiIn
 , BYREF pbOut AS BYTE _                                ' __out BYTE * pbOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarUI1FromUI4 IMPORT "OLEAUT32.DLL" ALIAS "VarUI1FromUI4" ( _
   BYVAL ulIn AS DWORD _                                ' __in  ULONG ulIn
 , BYREF pbOut AS BYTE _                                ' __out BYTE * pbOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarUI1FromUI8 IMPORT "OLEAUT32.DLL" ALIAS "VarUI1FromUI8" ( _
   BYVAL ui64In AS QUAD _                               ' __in  ULONG64 ui64In
 , BYREF pbOut AS BYTE _                                ' __out BYTE * pbOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarUI1FromDec IMPORT "OLEAUT32.DLL" ALIAS "VarUI1FromDec" ( _
   BYREF pdecIn AS ANY _                                ' __in  DECIMAL *pdecIn
 , BYREF pbOut AS BYTE _                                ' __out BYTE * pbOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarI2FromUI1 IMPORT "OLEAUT32.DLL" ALIAS "VarI2FromUI1" ( _
   BYVAL bIn AS BYTE _                                  ' __in  BYTE bIn
 , BYREF psOut AS INTEGER _                             ' __out SHORT * psOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarI2FromI4 IMPORT "OLEAUT32.DLL" ALIAS "VarI2FromI4" ( _
   BYVAL lIn AS LONG _                                  ' __in  LONG lIn
 , BYREF psOut AS INTEGER _                             ' __out SHORT * psOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarI2FromI8 IMPORT "OLEAUT32.DLL" ALIAS "VarI2FromI8" ( _
   BYVAL i64In AS QUAD _                                ' __in  LONG64 i64In
 , BYREF psOut AS INTEGER _                             ' __out SHORT * psOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarI2FromR4 IMPORT "OLEAUT32.DLL" ALIAS "VarI2FromR4" ( _
   BYVAL fltIn AS SINGLE _                              ' __in  FLOAT fltIn
 , BYREF psOut AS INTEGER _                             ' __out SHORT * psOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarI2FromR8 IMPORT "OLEAUT32.DLL" ALIAS "VarI2FromR8" ( _
   BYVAL dblIn AS DOUBLE _                              ' __in  DOUBLE dblIn
 , BYREF psOut AS INTEGER _                             ' __out SHORT * psOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarI2FromCy IMPORT "OLEAUT32.DLL" ALIAS "VarI2FromCy" ( _
   BYVAL cyIn AS CUR _                                  ' __in  CY cyIn
 , BYREF psOut AS INTEGER _                             ' __out SHORT * psOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarI2FromDate IMPORT "OLEAUT32.DLL" ALIAS "VarI2FromDate" ( _
   BYVAL dateIn AS DOUBLE _                             ' __in  DATE dateIn
 , BYREF psOut AS INTEGER _                             ' __out SHORT * psOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarI2FromStr IMPORT "OLEAUT32.DLL" ALIAS "VarI2FromStr" ( _
   BYREF strIn AS WSTRINGZ _                            ' __in  OLECHAR * strIn
 , BYVAL lcid AS DWORD _                                ' __in  LCID lcid
 , BYVAL dwFlags AS DWORD _                             ' __in  ULONG dwFlags
 , BYREF psOut AS INTEGER _                             ' __out SHORT * psOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarI2FromDisp IMPORT "OLEAUT32.DLL" ALIAS "VarI2FromDisp" ( _
   BYVAL pdispIn AS IDispatch _                         ' __in  IDispatch * pdispIn
 , BYVAL lcid AS DWORD _                                ' __in  LCID lcid
 , BYREF psOut AS INTEGER _                             ' __out SHORT * psOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarI2FromBool IMPORT "OLEAUT32.DLL" ALIAS "VarI2FromBool" ( _
   BYVAL boolIn AS INTEGER _                            ' __in  VARIANT_BOOL boolIn
 , BYREF psOut AS INTEGER _                             ' __out SHORT * psOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarI2FromI1 IMPORT "OLEAUT32.DLL" ALIAS "VarI2FromI1" ( _
   BYVAL cIn AS BYTE _                                  ' __in  CHAR cIn
 , BYREF psOut AS INTEGER _                             ' __out SHORT * psOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarI2FromUI2 IMPORT "OLEAUT32.DLL" ALIAS "VarI2FromUI2" ( _
   BYVAL uiIn AS WORD _                                 ' __in  USHORT uiIn
 , BYREF psOut AS INTEGER _                             ' __out SHORT * psOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarI2FromUI4 IMPORT "OLEAUT32.DLL" ALIAS "VarI2FromUI4" ( _
   BYVAL ulIn AS DWORD _                                ' __in  ULONG ulIn
 , BYREF psOut AS INTEGER _                             ' __out SHORT * psOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarI2FromUI8 IMPORT "OLEAUT32.DLL" ALIAS "VarI2FromUI8" ( _
   BYVAL ui64In AS QUAD _                               ' __in  ULONG64 ui64In
 , BYREF psOut AS INTEGER _                             ' __out SHORT * psOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarI2FromDec IMPORT "OLEAUT32.DLL" ALIAS "VarI2FromDec" ( _
   BYREF pdecIn AS ANY _                                ' __in  DECIMAL *pdecIn
 , BYREF psOut AS INTEGER _                             ' __out SHORT * psOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarI4FromUI1 IMPORT "OLEAUT32.DLL" ALIAS "VarI4FromUI1" ( _
   BYVAL bIn AS BYTE _                                  ' __in  BYTE bIn
 , BYREF plOut AS LONG _                                ' __out LONG * plOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarI4FromI2 IMPORT "OLEAUT32.DLL" ALIAS "VarI4FromI2" ( _
   BYVAL sIn AS INTEGER _                               ' __in  SHORT sIn
 , BYREF plOut AS LONG _                                ' __out LONG * plOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarI4FromI8 IMPORT "OLEAUT32.DLL" ALIAS "VarI4FromI8" ( _
   BYVAL i64In AS QUAD _                                ' __in  LONG64 i64In
 , BYREF plOut AS LONG _                                ' __out LONG * plOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarI4FromR4 IMPORT "OLEAUT32.DLL" ALIAS "VarI4FromR4" ( _
   BYVAL fltIn AS SINGLE _                              ' __in  FLOAT fltIn
 , BYREF plOut AS LONG _                                ' __out LONG * plOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarI4FromR8 IMPORT "OLEAUT32.DLL" ALIAS "VarI4FromR8" ( _
   BYVAL dblIn AS DOUBLE _                              ' __in  DOUBLE dblIn
 , BYREFplOut AS  LONG _                                ' __out LONG * plOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarI4FromCy IMPORT "OLEAUT32.DLL" ALIAS "VarI4FromCy" ( _
   BYVAL cyIn AS CUR _                                  ' __in  CY cyIn
 , BYREF plOut AS LONG _                                ' __out LONG * plOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarI4FromDate IMPORT "OLEAUT32.DLL" ALIAS "VarI4FromDate" ( _
   BYVAL dateIn AS DOUBLE _                             ' __in  DATE dateIn
 , BYREF plOut AS LONG _                                ' __out LONG * plOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarI4FromStr IMPORT "OLEAUT32.DLL" ALIAS "VarI4FromStr" ( _
   BYREF strIn AS WSTRINGZ _                            ' __in  OLECHAR * strIn
 , BYVAL lcid AS DWORD _                                ' __in  LCID lcid
 , BYVAL dwFlags AS DWORD _                             ' __in  ULONG dwFlags
 , BYREF plOut AS LONG _                                ' __out LONG * plOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarI4FromDisp IMPORT "OLEAUT32.DLL" ALIAS "VarI4FromDisp" ( _
   BYVAL pdispIn AS IDispatch _                         ' __in  IDispatch * pdispIn
 , BYVAL lcid AS DWORD _                                ' __in  LCID lcid
 , BYREF plOut AS LONG _                                ' __out LONG * plOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarI4FromBool IMPORT "OLEAUT32.DLL" ALIAS "VarI4FromBool" ( _
   BYVAL boolIn AS INTEGER _                            ' __in  VARIANT_BOOL boolIn
 , BYREF plOut AS LONG _                                ' __out LONG * plOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarI4FromI1 IMPORT "OLEAUT32.DLL" ALIAS "VarI4FromI1" ( _
   BYVAL cIn AS BYTE _                                  ' __in  CHAR cIn
 , BYREF plOut AS LONG _                                ' __out LONG * plOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarI4FromUI2 IMPORT "OLEAUT32.DLL" ALIAS "VarI4FromUI2" ( _
   BYVAL uiIn AS WORD _                                 ' __in  USHORT uiIn
 , BYREF plOut AS LONG _                                ' __out LONG * plOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarI4FromUI4 IMPORT "OLEAUT32.DLL" ALIAS "VarI4FromUI4" ( _
   BYVAL ulIn AS DWORD _                                ' __in  ULONG ulIn
 , BYREF plOut AS LONG _                                ' __out LONG * plOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarI4FromUI8 IMPORT "OLEAUT32.DLL" ALIAS "VarI4FromUI8" ( _
   BYVAL ui64In AS QUAD _                               ' __in  ULONG64 ui64In
 , BYREF plOut AS LONG _                                ' __out LONG * plOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarI4FromDec IMPORT "OLEAUT32.DLL" ALIAS "VarI4FromDec" ( _
   BYREF pdecIn AS ANY _                                ' __in  DECIMAL *pdecIn
 , BYREF plOut AS LONG _                                ' __out LONG * plOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarI4FromInt IMPORT "OLEAUT32.DLL" ALIAS "VarI4FromInt" ( _
   BYVAL intIn AS LONG _                                ' __in  INT intIn
 , BYREF plOut AS LONG _                                ' __out LONG * plOut
 ) AS LONG                                              ' HRESULT

'/******************************************/

DECLARE FUNCTION VarI8FromUI1 IMPORT "OLEAUT32.DLL" ALIAS "VarI8FromUI1" ( _
   BYVAL bIn AS BYTE _                                  ' __in  BYTE bIn
 , BYREF pi64Out AS QUAD _                              ' __out LONG64 FAR* pi64Out
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarI8FromI2 IMPORT "OLEAUT32.DLL" ALIAS "VarI8FromI2" ( _
   BYVAL sIn AS INTEGER _                               ' __in  SHORT sIn
 , BYREF pi64Out AS QUAD _                              ' __out LONG64 FAR* pi64Out
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarI8FromI4 IMPORT "OLEAUT32.DLL" ALIAS "VarI8FromI4" ( _
   BYVAL lIn AS LONG _                                  ' __in  LONG lIn
 , BYREF pi64Out AS QUAD _                              ' __out LONG64 FAR* pi64Out
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarI8FromR4 IMPORT "OLEAUT32.DLL" ALIAS "VarI8FromR4" ( _
   BYVAL fltIn AS SINGLE _                              ' __in  FLOAT fltIn
 , BYREF pi64Out AS QUAD _                              ' __out LONG64 FAR* pi64Out
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarI8FromR8 IMPORT "OLEAUT32.DLL" ALIAS "VarI8FromR8" ( _
   BYVAL dblIn AS DOUBLE _                              ' __in  DOUBLE dblIn
 , BYREF pi64Out AS QUAD _                              ' __out LONG64 FAR* pi64Out
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarI8FromCy IMPORT "OLEAUT32.DLL" ALIAS "VarI8FromCy" ( _
   BYVAL cyIn AS CUR _                                  ' __in  CY cyIn
 , BYREF pi64Out AS QUAD _                              ' __out LONG64 FAR* pi64Out
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarI8FromDate IMPORT "OLEAUT32.DLL" ALIAS "VarI8FromDate" ( _
   BYVAL dateIn AS DOUBLE _                             ' __in  DATE dateIn
 , BYREF pi64Out AS QUAD _                              ' __out LONG64 FAR* pi64Out
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarI8FromStr IMPORT "OLEAUT32.DLL" ALIAS "VarI8FromStr" ( _
   BYREF strIn AS WSTRINGZ _                            ' __in  OLECHAR FAR* strIn
 , BYVAL lcid AS DWORD _                                ' __in  LCID lcid
 , BYVAL dwFlags AS DWORD _                             ' __in  unsigned long dwFlags
 , BYREF pi64Out AS QUAD _                              ' __out LONG64 FAR* pi64Out
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarI8FromDisp IMPORT "OLEAUT32.DLL" ALIAS "VarI8FromDisp" ( _
   BYVAL pdispIn AS IDispatch _                         ' __in  IDispatch FAR* pdispIn
 , BYVAL lcid AS DWORD _                                ' __in  LCID lcid
 , BYREF pi64Out AS QUAD _                              ' __out LONG64 FAR* pi64Out
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarI8FromBool IMPORT "OLEAUT32.DLL" ALIAS "VarI8FromBool" ( _
   BYVAL boolIn AS INTEGER _                            ' __in  VARIANT_BOOL boolIn
 , BYREF pi64Out AS QUAD _                              ' __out LONG64 FAR* pi64Out
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarI8FromI1 IMPORT "OLEAUT32.DLL" ALIAS "VarI8FromI1" ( _
   BYVAL cIn AS BYTE _                                  ' __in  CHAR cIn
 , BYREF pi64Out AS QUAD _                              ' __out LONG64 FAR* pi64Out
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarI8FromUI2 IMPORT "OLEAUT32.DLL" ALIAS "VarI8FromUI2" ( _
   BYVAL uiIn AS WORD _                                 ' __in  USHORT uiIn
 , BYREF pi64Out AS QUAD _                              ' __out LONG64 FAR* pi64Out
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarI8FromUI4 IMPORT "OLEAUT32.DLL" ALIAS "VarI8FromUI4" ( _
   BYVAL ulIn AS DWORD _                                ' __in  ULONG ulIn
 , BYREF pi64Out AS QUAD _                              ' __out LONG64 FAR* pi64Out
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarI8FromUI8 IMPORT "OLEAUT32.DLL" ALIAS "VarI8FromUI8" ( _
   BYVAL ui64In AS QUAD _                               ' __in  ULONG64 ui64In
 , BYREF pi64Out AS QUAD _                              ' __out LONG64 FAR* pi64Out
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarI8FromDec IMPORT "OLEAUT32.DLL" ALIAS "VarI8FromDec" ( _
   BYREF pdecIn AS ANY _                                ' __in  DECIMAL *pdecIn
 , BYREF pi64Out AS QUAD _                              ' __out LONG64 FAR* pi64Out
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarI8FromInt IMPORT "OLEAUT32.DLL" ALIAS "VarI8FromInt" ( _
   BYVAL intIn AS LONG _                                ' __in  INT intIn
 , BYREF pi64Out AS QUAD _                              ' __out LONG64 FAR* pi64Out
 ) AS LONG                                              ' HRESULT

'/*********************/


DECLARE FUNCTION VarR4FromUI1 IMPORT "OLEAUT32.DLL" ALIAS "VarR4FromUI1" ( _
   BYVAL bIn AS BYTE _                                  ' __in  BYTE bIn
 , BYREF pfltOut AS SINGLE _                            ' __out FLOAT *pfltOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarR4FromI2 IMPORT "OLEAUT32.DLL" ALIAS "VarR4FromI2" ( _
   BYVAL sIn AS INTEGER _                               ' __in  SHORT sIn
 , BYREF pfltOut AS SINGLE _                            ' __out FLOAT *pfltOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarR4FromI4 IMPORT "OLEAUT32.DLL" ALIAS "VarR4FromI4" ( _
   BYVAL lIn AS LONG _                                  ' __in  LONG lIn
 , BYREF pfltOut AS SINGLE _                            ' __out FLOAT *pfltOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarR4FromI8 IMPORT "OLEAUT32.DLL" ALIAS "VarR4FromI8" ( _
   BYVAL i64In AS QUAD _                                ' __in  LONG64 i64In
 , BYREF pfltOut AS SINGLE _                            ' __out FLOAT *pfltOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarR4FromR8 IMPORT "OLEAUT32.DLL" ALIAS "VarR4FromR8" ( _
   BYVAL dblIn AS DOUBLE _                              ' __in  DOUBLE dblIn
 , BYREF pfltOut AS SINGLE _                            ' __out FLOAT *pfltOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarR4FromCy IMPORT "OLEAUT32.DLL" ALIAS "VarR4FromCy" ( _
   BYVAL cyIn AS CUR _                                  ' __in  CY cyIn
 , BYREF pfltOut AS SINGLE _                            ' __out FLOAT *pfltOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarR4FromDate IMPORT "OLEAUT32.DLL" ALIAS "VarR4FromDate" ( _
   BYVAL dateIn AS DOUBLE _                             ' __in  DATE dateIn
 , BYREF pfltOut AS SINGLE _                            ' __out FLOAT *pfltOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarR4FromStr IMPORT "OLEAUT32.DLL" ALIAS "VarR4FromStr" ( _
   BYREF strIn AS WSTRINGZ _                            ' __in  OLECHAR * strIn
 , BYVAL lcid AS DWORD _                                ' __in  LCID lcid
 , BYVAL dwFlags AS DWORD _                             ' __in  ULONG dwFlags
 , BYREF pfltOut AS SINGLE _                            ' __out FLOAT *pfltOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarR4FromDisp IMPORT "OLEAUT32.DLL" ALIAS "VarR4FromDisp" ( _
   BYVAL pdispIn AS IDispatch _                         ' __in  IDispatch * pdispIn
 , BYVAL lcid AS DWORD _                                ' __in  LCID lcid
 , BYREF pfltOut AS SINGLE _                            ' __out FLOAT *pfltOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarR4FromBool IMPORT "OLEAUT32.DLL" ALIAS "VarR4FromBool" ( _
   BYVAL boolIn AS INTEGER _                            ' __in  VARIANT_BOOL boolIn
 , BYREF pfltOut AS SINGLE _                            ' __out FLOAT *pfltOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarR4FromI1 IMPORT "OLEAUT32.DLL" ALIAS "VarR4FromI1" ( _
   BYVAL cIn AS BYTE _                                  ' __in  CHAR cIn
 , BYREF pfltOut AS SINGLE _                            ' __out FLOAT *pfltOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarR4FromUI2 IMPORT "OLEAUT32.DLL" ALIAS "VarR4FromUI2" ( _
   BYVAL uiIn AS WORD _                                 ' __in  USHORT uiIn
 , BYREF pfltOut AS SINGLE _                            ' __out FLOAT *pfltOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarR4FromUI4 IMPORT "OLEAUT32.DLL" ALIAS "VarR4FromUI4" ( _
   BYVAL ulIn AS DWORD _                                ' __in  ULONG ulIn
 , BYREF pfltOut AS SINGLE _                            ' __out FLOAT *pfltOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarR4FromUI8 IMPORT "OLEAUT32.DLL" ALIAS "VarR4FromUI8" ( _
   BYVAL ui64In AS QUAD _                               ' __in  ULONG64 ui64In
 , BYREF pfltOut AS SINGLE _                            ' __out FLOAT *pfltOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarR4FromDec IMPORT "OLEAUT32.DLL" ALIAS "VarR4FromDec" ( _
   BYREF pdecIn AS ANY _                                ' __in  DECIMAL *pdecIn
 , BYREF pfltOut AS SINGLE _                            ' __out FLOAT *pfltOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarR8FromUI1 IMPORT "OLEAUT32.DLL" ALIAS "VarR8FromUI1" ( _
   BYVAL bIn AS BYTE _                                  ' __in  BYTE bIn
 , BYREF pdblOut AS DOUBLE _                            ' __out double pdblOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarR8FromI2 IMPORT "OLEAUT32.DLL" ALIAS "VarR8FromI2" ( _
   BYVAL sIn AS INTEGER _                               ' __in  SHORT sIn
 , BYREF pdblOut AS DOUBLE _                            ' __out double pdblOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarR8FromI4 IMPORT "OLEAUT32.DLL" ALIAS "VarR8FromI4" ( _
   BYVAL lIn AS LONG _                                  ' __in  LONG lIn
 , BYREF pdblOut AS DOUBLE _                            ' __out double pdblOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarR8FromI8 IMPORT "OLEAUT32.DLL" ALIAS "VarR8FromI8" ( _
   BYVAL i64In AS QUAD _                                ' __in  LONG64 i64In
 , BYREF pdblOut AS DOUBLE _                            ' __out double pdblOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarR8FromR4 IMPORT "OLEAUT32.DLL" ALIAS "VarR8FromR4" ( _
   BYVAL fltIn AS SINGLE _                              ' __in  FLOAT fltIn
 , BYREF pdblOut AS DOUBLE _                            ' __out double pdblOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarR8FromCy IMPORT "OLEAUT32.DLL" ALIAS "VarR8FromCy" ( _
   BYVAL cyIn AS CUR _                                  ' __in  CY cyIn
 , BYREF pdblOut AS DOUBLE _                            ' __out double pdblOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarR8FromDate IMPORT "OLEAUT32.DLL" ALIAS "VarR8FromDate" ( _
   BYVAL dateIn AS DOUBLE _                             ' __in  DATE dateIn
 , BYREF pdblOut AS DOUBLE _                            ' __out double pdblOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarR8FromStr IMPORT "OLEAUT32.DLL" ALIAS "VarR8FromStr" ( _
   BYREF strIn AS WSTRINGZ _                            ' __in  OLECHAR *strIn
 , BYVAL lcid AS DWORD _                                ' __in  LCID lcid
 , BYVAL dwFlags AS DWORD _                             ' __in  ULONG dwFlags
 , BYREF pdblOut AS DOUBLE _                            ' __out double pdblOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarR8FromDisp IMPORT "OLEAUT32.DLL" ALIAS "VarR8FromDisp" ( _
   BYVAL pdispIn AS IDispatch _                         ' __in  IDispatch * pdispIn
 , BYVAL lcid AS DWORD _                                ' __in  LCID lcid
 , BYREF pdblOut AS DOUBLE _                            ' __out double pdblOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarR8FromBool IMPORT "OLEAUT32.DLL" ALIAS "VarR8FromBool" ( _
   BYVAL boolIn AS INTEGER _                            ' __in  VARIANT_BOOL boolIn
 , BYREF pdblOut AS DOUBLE _                            ' __out double pdblOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarR8FromI1 IMPORT "OLEAUT32.DLL" ALIAS "VarR8FromI1" ( _
   BYVAL cIn AS BYTE _                                  ' __in  CHAR cIn
 , BYREF pdblOut AS DOUBLE _                            ' __out double pdblOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarR8FromUI2 IMPORT "OLEAUT32.DLL" ALIAS "VarR8FromUI2" ( _
   BYVAL uiIn AS WORD _                                 ' __in USHORT uiIn
 , BYREF pdblOut AS DOUBLE _                            ' __out double pdblOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarR8FromUI4 IMPORT "OLEAUT32.DLL" ALIAS "VarR8FromUI4" ( _
   BYVAL ulIn AS DWORD _                                ' __in  ULONG ulIn
 , BYREF pdblOut AS DOUBLE _                            ' __out double pdblOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarR8FromUI8 IMPORT "OLEAUT32.DLL" ALIAS "VarR8FromUI8" ( _
   BYVAL ui64In AS QUAD _                               ' __in  ULONG64 ui64In
 , BYREF pdblOut AS DOUBLE _                            ' __out double pdblOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarR8FromDec IMPORT "OLEAUT32.DLL" ALIAS "VarR8FromDec" ( _
   BYREF pdecIn AS ANY _                                ' __in  DECIMAL pdecIn
 , BYREF pdblOut AS DOUBLE _                            ' __out double pdblOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarDateFromUI1 IMPORT "OLEAUT32.DLL" ALIAS "VarDateFromUI1" ( _
   BYVAL bIn AS BYTE _                                  ' __in  BYTE bIn
 , BYREF pdateOut AS DOUBLE _                           ' __out DATE *pdateOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarDateFromI2 IMPORT "OLEAUT32.DLL" ALIAS "VarDateFromI2" ( _
   BYVAL sIn AS INTEGER _                               ' __in  SHORT sIn
 , BYREF pdateOut AS DOUBLE _                           ' __out DATE *pdateOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarDateFromI4 IMPORT "OLEAUT32.DLL" ALIAS "VarDateFromI4" ( _
   BYVAL lIn AS LONG _                                  ' __in  LONG lIn
 , BYREF pdateOut AS DOUBLE _                           ' __out DATE *pdateOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarDateFromI8 IMPORT "OLEAUT32.DLL" ALIAS "VarDateFromI8" ( _
   BYVAL i64In AS QUAD _                                ' __in  LONG64 i64In
 , BYREF pdateOut AS DOUBLE _                           ' __out DATE *pdateOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarDateFromR4 IMPORT "OLEAUT32.DLL" ALIAS "VarDateFromR4" ( _
   BYVAL fltIn AS SINGLE _                              ' __in  FLOAT fltIn
 , BYREF pdateOut AS DOUBLE _                           ' __out DATE *pdateOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarDateFromR8 IMPORT "OLEAUT32.DLL" ALIAS "VarDateFromR8" ( _
   BYVAL dblIn AS DOUBLE _                              ' __in  DOUBLE dblIn
 , BYREF pdateOut AS DOUBLE _                           ' __out DATE *pdateOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarDateFromCy IMPORT "OLEAUT32.DLL" ALIAS "VarDateFromCy" ( _
   BYVAL cyIn AS CUR _                                  ' __in  CY cyIn
 , BYREF pdateOut AS DOUBLE _                           ' __out DATE *pdateOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarDateFromStr IMPORT "OLEAUT32.DLL" ALIAS "VarDateFromStr" ( _
   BYREF strIn AS WSTRINGZ _                            ' __in  OLECHAR *strIn
 , BYVAL lcid AS DWORD _                                ' __in  LCID lcid
 , BYVAL dwFlags AS DWORD _                             ' __in  ULONG dwFlags
 , BYREF pdateOut AS DOUBLE _                           ' __out DATE *pdateOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarDateFromDisp IMPORT "OLEAUT32.DLL" ALIAS "VarDateFromDisp" ( _
   BYVAL pdispIn AS IDispatch _                         ' __in  IDispatch * pdispIn
 , BYVAL lcid AS DWORD _                                ' __in  LCID lcid
 , BYREF pdateOut AS DOUBLE _                           ' __out DATE *pdateOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarDateFromBool IMPORT "OLEAUT32.DLL" ALIAS "VarDateFromBool" ( _
   BYVAL boolIn AS INTEGER _                            ' __in  VARIANT_BOOL boolIn
 , BYREF pdateOut AS DOUBLE _                           ' __out DATE *pdateOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarDateFromI1 IMPORT "OLEAUT32.DLL" ALIAS "VarDateFromI1" ( _
   BYVAL cIn AS BYTE _                                  ' __in  CHAR cIn
 , BYREF pdateOut AS DOUBLE _                           ' __out DATE *pdateOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarDateFromUI2 IMPORT "OLEAUT32.DLL" ALIAS "VarDateFromUI2" ( _
   BYVAL uiIn AS WORD _                                 ' __in  USHORT uiIn
 , BYREF pdateOut AS DOUBLE _                           ' __out DATE *pdateOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarDateFromUI4 IMPORT "OLEAUT32.DLL" ALIAS "VarDateFromUI4" ( _
   BYVAL ulIn AS DWORD _                                ' __in  ULONG ulIn
 , BYREF pdateOut AS DOUBLE _                           ' __out DATE *pdateOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarDateFromUI8 IMPORT "OLEAUT32.DLL" ALIAS "VarDateFromUI8" ( _
   BYVAL ui64In AS QUAD _                               ' __in  ULONG64 ui64In
 , BYREF pdateOut AS DOUBLE _                           ' __out DATE *pdateOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarDateFromDec IMPORT "OLEAUT32.DLL" ALIAS "VarDateFromDec" ( _
   BYREF pdecIn AS ANY _                                ' __in  DECIMAL *pdecIn
 , BYREF pdateOut AS DOUBLE _                           ' __out DATE *pdateOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarCyFromUI1 IMPORT "OLEAUT32.DLL" ALIAS "VarCyFromUI1" ( _
   BYVAL bIn AS BYTE _                                  ' __in  BYTE bIn
 , BYREF pcyOut AS CUR _                                ' __out CY * pcyOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarCyFromI2 IMPORT "OLEAUT32.DLL" ALIAS "VarCyFromI2" ( _
   BYVAL sIn AS INTEGER _                               ' __in  SHORT sIn
 , BYREF pcyOut AS CUR _                                ' __out CY * pcyOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarCyFromI4 IMPORT "OLEAUT32.DLL" ALIAS "VarCyFromI4" ( _
   BYVAL lIn AS LONG _                                  ' __in  LONG lIn
 , BYREF pcyOut AS CUR _                                ' __out CY * pcyOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarCyFromI8 IMPORT "OLEAUT32.DLL" ALIAS "VarCyFromI8" ( _
   BYVAL i64In AS QUAD _                                ' __in  LONG64 i64In
 , BYREF pcyOut AS CUR _                                ' __out CY * pcyOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarCyFromR4 IMPORT "OLEAUT32.DLL" ALIAS "VarCyFromR4" ( _
   BYVAL fltIn AS SINGLE _                              ' __in  FLOAT fltIn
 , BYREF pcyOut AS CUR _                                ' __out CY * pcyOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarCyFromR8 IMPORT "OLEAUT32.DLL" ALIAS "VarCyFromR8" ( _
   BYVAL dblIn AS DOUBLE _                              ' __in  DOUBLE dblIn
 , BYREF pcyOut AS CUR _                                ' __out CY * pcyOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarCyFromDate IMPORT "OLEAUT32.DLL" ALIAS "VarCyFromDate" ( _
   BYVAL dateIn AS DOUBLE _                             ' __in  DATE dateIn
 , BYREF pcyOut AS CUR _                                ' __out CY * pcyOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarCyFromStr IMPORT "OLEAUT32.DLL" ALIAS "VarCyFromStr" ( _
   BYREF strIn AS WSTRINGZ _                            ' __in  OLECHAR *strIn
 , BYVAL lcid AS DWORD _                                ' __in  LCID lcid
 , BYVAL dwFlags AS DWORD _                             ' __in  ULONG dwFlags
 , BYREF pcyOut AS CUR _                                ' __out CY * pcyOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarCyFromDisp IMPORT "OLEAUT32.DLL" ALIAS "VarCyFromDisp" ( _
   BYVAL pdispIn AS IDispatch _                         ' __in  IDispatch * pdispIn
 , BYVAL lcid AS DWORD _                                ' __in  LCID lcid
 , BYREF pcyOut AS CUR _                                ' __out CY * pcyOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarCyFromBool IMPORT "OLEAUT32.DLL" ALIAS "VarCyFromBool" ( _
   BYVAL boolIn AS INTEGER _                            ' __in  VARIANT_BOOL boolIn
 , BYREF pcyOut AS CUR _                                ' __out CY * pcyOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarCyFromI1 IMPORT "OLEAUT32.DLL" ALIAS "VarCyFromI1" ( _
   BYVAL cIn AS BYTE _                                  ' __in  CHAR cIn
 , BYREF pcyOut AS CUR _                                ' __out CY * pcyOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarCyFromUI2 IMPORT "OLEAUT32.DLL" ALIAS "VarCyFromUI2" ( _
   BYVAL uiIn AS DWORD _                                ' __in  USHORT uiIn
 , BYREF pcyOut AS CUR _                                ' __out CY * pcyOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarCyFromUI4 IMPORT "OLEAUT32.DLL" ALIAS "VarCyFromUI4" ( _
   BYVAL ulIn AS DWORD _                                ' __in  ULONG ulIn
 , BYREF pcyOut AS CUR _                                ' __out CY * pcyOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarCyFromUI8 IMPORT "OLEAUT32.DLL" ALIAS "VarCyFromUI8" ( _
   BYVAL ui64In AS QUAD _                               ' __in  ULONG64 ui64In
 , BYREF pcyOut AS CUR _                                ' __out CY * pcyOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarCyFromDec IMPORT "OLEAUT32.DLL" ALIAS "VarCyFromDec" ( _
   BYREF pdecIn AS ANY _                                ' __in  DECIMAL pdecIn
 , BYREF pcyOut AS CUR _                                ' __out CY * pcyOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarBstrFromUI1 IMPORT "OLEAUT32.DLL" ALIAS "VarBstrFromUI1" ( _
   BYVAL bVal AS BYTE _                                 ' __in  BYTE bVal
 , BYVAL lcid AS DWORD _                                ' __in  LCID lcid
 , BYVAL dwFlags AS DWORD _                             ' __in  ULONG dwFlags
 , BYREF pbstrOut AS WSTRING _                          ' __out BSTR * pbstrOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarBstrFromI2 IMPORT "OLEAUT32.DLL" ALIAS "VarBstrFromI2" ( _
   BYVAL iVal AS INTEGER _                              ' __in  SHORT iVal
 , BYVAL lcid AS DWORD _                                ' __in  LCID lcid
 , BYVAL dwFlags AS DWORD _                             ' __in  ULONG dwFlags
 , BYREF pbstrOut AS WSTRING _                          ' __out BSTR * pbstrOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarBstrFromI4 IMPORT "OLEAUT32.DLL" ALIAS "VarBstrFromI4" ( _
   BYVAL lIn AS LONG _                                  ' __in  LONG lIn
 , BYVAL lcid AS DWORD _                                ' __in  LCID lcid
 , BYVAL dwFlags AS DWORD _                             ' __in  ULONG dwFlags
 , BYREF pbstrOut AS WSTRING _                          ' __out BSTR * pbstrOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarBstrFromI8 IMPORT "OLEAUT32.DLL" ALIAS "VarBstrFromI8" ( _
   BYVAL i64In AS QUAD _                                ' __in  LONG64 i64In
 , BYVAL lcid AS DWORD _                                ' __in  LCID lcid
 , BYVAL dwFlags AS DWORD _                             ' __in  ULONG dwFlags
 , BYREF pbstrOut AS WSTRING _                          ' __out BSTR * pbstrOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarBstrFromR4 IMPORT "OLEAUT32.DLL" ALIAS "VarBstrFromR4" ( _
   BYVAL fltIn AS SINGLE _                              ' __in  FLOAT fltIn
 , BYVAL lcid AS DWORD _                                ' __in  LCID lcid
 , BYVAL dwFlags AS DWORD _                             ' __in  ULONG dwFlags
 , BYREF pbstrOut AS WSTRING _                          ' __out BSTR * pbstrOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarBstrFromR8 IMPORT "OLEAUT32.DLL" ALIAS "VarBstrFromR8" ( _
   BYVAL dblIn AS DOUBLE _                              ' __in  DOUBLE dblIn
 , BYVAL lcid AS DWORD _                                ' __in  LCID lcid
 , BYVAL dwFlags AS DWORD _                             ' __in  ULONG dwFlags
 , BYREF pbstrOut AS WSTRING _                          ' __out BSTR * pbstrOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarBstrFromCy IMPORT "OLEAUT32.DLL" ALIAS "VarBstrFromCy" ( _
   BYVAL cyIn AS CUR _                                  ' __in  CY cyIn
 , BYVAL lcid AS DWORD _                                ' __in  LCID lcid
 , BYVAL dwFlags AS DWORD _                             ' __in  ULONG dwFlags
 , BYREF pbstrOut AS WSTRING _                          ' __out BSTR * pbstrOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarBstrFromDate IMPORT "OLEAUT32.DLL" ALIAS "VarBstrFromDate" ( _
   BYVAL dateIn AS DOUBLE _                             ' __in  DATE dateIn
 , BYVAL lcid AS DWORD _                                ' __in  LCID lcid
 , BYVAL dwFlags AS DWORD _                             ' __in  ULONG dwFlags
 , BYREF pbstrOut AS WSTRING _                          ' __out BSTR * pbstrOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarBstrFromDisp IMPORT "OLEAUT32.DLL" ALIAS "VarBstrFromDisp" ( _
   BYVAL pdispIn AS IDispatch _                         ' __in  IDispatch * pdispIn
 , BYVAL lcid AS DWORD _                                ' __in  LCID lcid
 , BYVAL dwFlags AS DWORD _                             ' __in  ULONG dwFlags
 , BYREF pbstrOut AS WSTRING _                          ' __out BSTR * pbstrOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarBstrFromBool IMPORT "OLEAUT32.DLL" ALIAS "VarBstrFromBool" ( _
   BYVAL boolIn AS INTEGER _                            ' __in  VARIANT_BOOL boolIn
 , BYVAL lcid AS DWORD _                                ' __in  LCID lcid
 , BYVAL dwFlags AS DWORD _                             ' __in  ULONG dwFlags
 , BYREF pbstrOut AS WSTRING _                          ' __out BSTR * pbstrOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarBstrFromI1 IMPORT "OLEAUT32.DLL" ALIAS "VarBstrFromI1" ( _
   BYVAL cIn AS BYTE _                                  ' __in  CHAR cIn
 , BYVAL lcid AS DWORD _                                ' __in  LCID lcid
 , BYVAL dwFlags AS DWORD _                             ' __in  ULONG dwFlags
 , BYREF pbstrOut AS WSTRING _                          ' __out BSTR * pbstrOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarBstrFromUI2 IMPORT "OLEAUT32.DLL" ALIAS "VarBstrFromUI2" ( _
   BYVAL uiIn AS WORD _                                 ' __in  USHORT uiIn
 , BYVAL lcid AS DWORD _                                ' __in  LCID lcid
 , BYVAL dwFlags AS DWORD _                             ' __in  ULONG dwFlags
 , BYREF pbstrOut AS WSTRING _                          ' __out BSTR * pbstrOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarBstrFromUI4 IMPORT "OLEAUT32.DLL" ALIAS "VarBstrFromUI4" ( _
   BYVAL ulIn AS DWORD _                                ' __in  ULONG ulIn
 , BYVAL lcid AS DWORD _                                ' __in  LCID lcid
 , BYVAL dwFlags AS DWORD _                             ' __in  ULONG dwFlags
 , BYREF pbstrOut AS WSTRING _                          ' __out BSTR * pbstrOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarBstrFromUI8 IMPORT "OLEAUT32.DLL" ALIAS "VarBstrFromUI8" ( _
   BYVAL ui64In AS QUAD _                               ' __in  ULONG64 ui64In
 , BYVAL lcid AS DWORD _                                ' __in  LCID lcid
 , BYVAL dwFlags AS DWORD _                             ' __in  ULONG dwFlags
 , BYREF pbstrOut AS WSTRING _                          ' __out BSTR * pbstrOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarBstrFromDec IMPORT "OLEAUT32.DLL" ALIAS "VarBstrFromDec" ( _
   BYREF pdecIn AS ANY _                                ' __in  DECIMAL *pdecIn
 , BYVAL lcid AS DWORD _                                ' __in  LCID lcid
 , BYVAL dwFlags AS DWORD _                             ' __in  ULONG dwFlags
 , BYREF pbstrOut AS WSTRING _                          ' __out BSTR *pbstrOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarBoolFromUI1 IMPORT "OLEAUT32.DLL" ALIAS "VarBoolFromUI1" ( _
   BYVAL bIn AS BYTE _                                  ' __in  BYTE bIn
 , BYREF pboolOut AS INTEGER _                          ' __out VARIANT_BOOL * pboolOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarBoolFromI2 IMPORT "OLEAUT32.DLL" ALIAS "VarBoolFromI2" ( _
   BYVAL sIn AS WORD _                                  ' __in  SHORT sIn
 , BYREF pboolOut AS INTEGER _                          ' __out VARIANT_BOOL * pboolOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarBoolFromI4 IMPORT "OLEAUT32.DLL" ALIAS "VarBoolFromI4" ( _
   BYVAL lIn AS LONG _                                  ' __in  LONG lIn
 , BYREF pboolOut AS INTEGER _                          ' __out VARIANT_BOOL * pboolOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarBoolFromI8 IMPORT "OLEAUT32.DLL" ALIAS "VarBoolFromI8" ( _
   BYVAL i64In AS QUAD _                                ' __in  LONG64 i64In
 , BYREF pboolOut AS INTEGER _                          ' __out VARIANT_BOOL * pboolOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarBoolFromR4 IMPORT "OLEAUT32.DLL" ALIAS "VarBoolFromR4" ( _
   BYVAL fltIn AS SINGLE _                              ' __in  FLOAT fltIn
 , BYREF pboolOut AS INTEGER _                          ' __out VARIANT_BOOL * pboolOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarBoolFromR8 IMPORT "OLEAUT32.DLL" ALIAS "VarBoolFromR8" ( _
   BYVAL dblIn AS DOUBLE _                              ' __in  DOUBLE dblIn
 , BYREF pboolOut AS INTEGER _                          ' __out VARIANT_BOOL * pboolOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarBoolFromDate IMPORT "OLEAUT32.DLL" ALIAS "VarBoolFromDate" ( _
   BYVAL dateIn AS DOUBLE _                             ' __in  DATE dateIn
 , BYREF pboolOut AS INTEGER _                          ' __out VARIANT_BOOL * pboolOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarBoolFromCy IMPORT "OLEAUT32.DLL" ALIAS "VarBoolFromCy" ( _
   BYVAL cyIn AS CUR _                                  ' __in  CY cyIn
 , BYREF pboolOut AS INTEGER _                          ' __out VARIANT_BOOL * pboolOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarBoolFromStr IMPORT "OLEAUT32.DLL" ALIAS "VarBoolFromStr" ( _
   BYREF strIn AS WSTRINGZ _                            ' __in  OLECHAR *strIn
 , BYVAL lcid AS DWORD _                                ' __in  LCID lcid
 , BYVAL dwFlags AS DWORD _                             ' __in  ULONG dwFlags
 , BYREF pboolOut AS INTEGER _                          ' __out VARIANT_BOOL * pboolOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarBoolFromDisp IMPORT "OLEAUT32.DLL" ALIAS "VarBoolFromDisp" ( _
   BYVAL pdispIn AS IDispatch _                         ' __in  IDispatch * pdispIn
 , BYVAL lcid AS DWORD _                                ' __in  LCID lcid
 , BYREF pboolOut AS INTEGER _                          ' __out VARIANT_BOOL * pboolOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarBoolFromI1 IMPORT "OLEAUT32.DLL" ALIAS "VarBoolFromI1" ( _
   BYVAL cIn AS BYTE _                                  ' __in  CHAR cIn
 , BYREF pboolOut AS INTEGER _                          ' __out VARIANT_BOOL * pboolOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarBoolFromUI2 IMPORT "OLEAUT32.DLL" ALIAS "VarBoolFromUI2" ( _
   BYVAL uiIn AS WORD _                                 ' __in  USHORT uiIn
 , BYREF pboolOut AS INTEGER _                          ' __out VARIANT_BOOL * pboolOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarBoolFromUI4 IMPORT "OLEAUT32.DLL" ALIAS "VarBoolFromUI4" ( _
   BYVAL ulIn AS DWORD _                                ' __in  ULONG ulIn
 , BYREF pboolOut AS INTEGER _                          ' __out VARIANT_BOOL * pboolOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarBoolFromUI8 IMPORT "OLEAUT32.DLL" ALIAS "VarBoolFromUI8" ( _
   BYVAL i64In AS QUAD _                                ' __in  ULONG64 i64In
 , BYREF pboolOut AS INTEGER _                          ' __out VARIANT_BOOL * pboolOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarBoolFromDec IMPORT "OLEAUT32.DLL" ALIAS "VarBoolFromDec" ( _
   BYREF pdecIn AS ANY _                                ' __in  DECIMAL *pdecIn
 , BYREF pboolOut AS INTEGER _                          ' __out VARIANT_BOOL * pboolOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarI1FromUI1 IMPORT "OLEAUT32.DLL" ALIAS "VarI1FromUI1" ( _
   BYVAL bIn AS BYTE _                                  ' __in  BYTE bIn
 , BYREF pcOut AS BYTE _                                ' __out CHAR *pcOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarI1FromI2 IMPORT "OLEAUT32.DLL" ALIAS "VarI1FromI2" ( _
   BYVAL uiIn AS INTEGER _                              ' __in  SHORT uiIn
 , BYREF pcOut AS BYTE _                                ' __out CHAR *pcOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarI1FromI4 IMPORT "OLEAUT32.DLL" ALIAS "VarI1FromI4" ( _
   BYVAL lIn AS LONG _                                  ' __in  LONG lIn
 , BYREF pcOut AS BYTE _                                ' __out CHAR *pcOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarI1FromI8 IMPORT "OLEAUT32.DLL" ALIAS "VarI1FromI8" ( _
   BYVAL i64In AS QUAD _                                ' __in  LONG64 i64In
 , BYREF pcOut AS BYTE _                                ' __out CHAR *pcOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarI1FromR4 IMPORT "OLEAUT32.DLL" ALIAS "VarI1FromR4" ( _
   BYVAL fltIn AS SINGLE _                              ' __in  FLOAT fltIn
 , BYREF pcOut AS BYTE _                                ' __out CHAR *pcOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarI1FromR8 IMPORT "OLEAUT32.DLL" ALIAS "VarI1FromR8" ( _
   BYVAL dblIn AS DOUBLE _                              ' __in  DOUBLE dblIn
 , BYREF pcOut AS BYTE _                                ' __out CHAR *pcOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarI1FromDate IMPORT "OLEAUT32.DLL" ALIAS "VarI1FromDate" ( _
   BYVAL dateIn AS DOUBLE _                             ' __in  DATE dateIn
 , BYREF pcOut AS BYTE _                                ' __out CHAR *pcOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarI1FromCy IMPORT "OLEAUT32.DLL" ALIAS "VarI1FromCy" ( _
   BYVAL cyIn AS CUR _                                  ' __in  CY cyIn
 , BYREF pcOut AS BYTE _                                ' __out CHAR *pcOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarI1FromStr IMPORT "OLEAUT32.DLL" ALIAS "VarI1FromStr" ( _
   BYREF strIn AS WSTRINGZ _                            ' __in  OLECHAR *strIn
 , BYVAL lcid AS DWORD _                                ' __in  LCID lcid
 , BYVAL dwFlags AS DWORD _                             ' __in  ULONG dwFlags
 , BYREF pcOut AS BYTE _                                ' __out CHAR *pcOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarI1FromDisp IMPORT "OLEAUT32.DLL" ALIAS "VarI1FromDisp" ( _
   BYVAL pdispIn AS IDispatch _                         ' __in  IDispatch *pdispIn
 , BYVAL lcid AS DWORD _                                ' __in  LCID lcid
 , BYREF pcOut AS BYTE _                                ' __out CHAR *pcOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarI1FromBool IMPORT "OLEAUT32.DLL" ALIAS "VarI1FromBool" ( _
   BYVAL boolIn AS INTEGER _                            ' __in  VARIANT_BOOL boolIn
 , BYREF pcOut AS BYTE _                                ' __out CHAR *pcOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarI1FromUI2 IMPORT "OLEAUT32.DLL" ALIAS "VarI1FromUI2" ( _
   BYVAL uiIn AS WORD _                                 ' __in  USHORT uiIn
 , BYREF pcOut AS BYTE _                                ' __out CHAR *pcOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarI1FromUI4 IMPORT "OLEAUT32.DLL" ALIAS "VarI1FromUI4" ( _
   BYVAL ulIn AS DWORD _                                ' __in  ULONG ulIn
 , BYREF pcOut AS BYTE _                                ' __out CHAR *pcOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarI1FromUI8 IMPORT "OLEAUT32.DLL" ALIAS "VarI1FromUI8" ( _
   BYVAL i64In AS QUAD _                                ' __in  ULONG64 i64In
 , BYREF pcOut AS BYTE _                                ' __out CHAR *pcOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarI1FromDec IMPORT "OLEAUT32.DLL" ALIAS "VarI1FromDec" ( _
   BYREF pdecIn AS ANY _                                ' __in  DECIMAL *pdecIn
 , BYREF pcOut AS BYTE _                                ' __out CHAR *pcOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarUI2FromUI1 IMPORT "OLEAUT32.DLL" ALIAS "VarUI2FromUI1" ( _
   BYVAL bIn AS BYTE _                                  ' __in  BYTE bIn
 , BYREF puiOut AS WORD _                               ' __out USHORT *puiOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarUI2FromI2 IMPORT "OLEAUT32.DLL" ALIAS "VarUI2FromI2" ( _
   BYVAL uiIn AS INTEGER _                              ' __in  SHORT uiIn
 , BYREF puiOut AS WORD _                               ' __out USHORT *puiOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarUI2FromI4 IMPORT "OLEAUT32.DLL" ALIAS "VarUI2FromI4" ( _
   BYVAL lIn AS LONG _                                  ' __in  LONG lIn
 , BYREF puiOut AS WORD _                               ' __out USHORT *puiOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarUI2FromI8 IMPORT "OLEAUT32.DLL" ALIAS "VarUI2FromI8" ( _
   BYVAL i64In AS QUAD _                                ' __in  LONG64 i64In
 , BYREF puiOut AS WORD _                               ' __out USHORT *puiOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarUI2FromR4 IMPORT "OLEAUT32.DLL" ALIAS "VarUI2FromR4" ( _
   BYVAL fltIn AS SINGLE _                              ' __in  FLOAT fltIn
 , BYREF puiOut AS WORD _                               ' __out USHORT *puiOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarUI2FromR8 IMPORT "OLEAUT32.DLL" ALIAS "VarUI2FromR8" ( _
   BYVAL dblIn AS DOUBLE _                              ' __in  DOUBLE dblIn
 , BYREF puiOut AS WORD _                               ' __out USHORT *puiOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarUI2FromDate IMPORT "OLEAUT32.DLL" ALIAS "VarUI2FromDate" ( _
   BYVAL dateIn AS DOUBLE _                             ' __in  DATE dateIn
 , BYREF puiOut AS WORD _                               ' __out USHORT *puiOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarUI2FromCy IMPORT "OLEAUT32.DLL" ALIAS "VarUI2FromCy" ( _
   BYVAL cyIn AS CUR _                                  ' __in  CY cyIn
 , BYREF puiOut AS WORD _                               ' __out USHORT *puiOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarUI2FromStr IMPORT "OLEAUT32.DLL" ALIAS "VarUI2FromStr" ( _
   BYREF strIn AS WSTRINGZ _                            ' __in  OLECHAR *strIn
 , BYVAL lcid AS DWORD _                                ' __in  LCID lcid
 , BYVAL dwFlags AS DWORD _                             ' __in  ULONG dwFlags
 , BYREF puiOut AS WORD _                               ' __out USHORT *puiOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarUI2FromDisp IMPORT "OLEAUT32.DLL" ALIAS "VarUI2FromDisp" ( _
   BYVAL pdispIn AS IDispatch _                         ' __in  IDispatch *pdispIn
 , BYVAL lcid AS DWORD _                                ' __in  LCID lcid
 , BYREF puiOut AS WORD _                               ' __out USHORT *puiOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarUI2FromBool IMPORT "OLEAUT32.DLL" ALIAS "VarUI2FromBool" ( _
   BYVAL boolIn AS INTEGER _                            ' __in  VARIANT_BOOL boolIn
 , BYREF puiOut AS WORD _                               ' __out USHORT *puiOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarUI2FromI1 IMPORT "OLEAUT32.DLL" ALIAS "VarUI2FromI1" ( _
   BYVAL cIn AS BYTE _                                  ' __in  CHAR cIn
 , BYREF puiOut AS WORD _                               ' __out USHORT *puiOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarUI2FromUI4 IMPORT "OLEAUT32.DLL" ALIAS "VarUI2FromUI4" ( _
   BYVAL ulIn AS DWORD _                                ' __in  ULONG ulIn
 , BYREF puiOut AS WORD _                               ' __out USHORT *puiOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarUI2FromUI8 IMPORT "OLEAUT32.DLL" ALIAS "VarUI2FromUI8" ( _
   BYVAL i64In AS QUAD _                                ' __in  ULONG64 i64In
 , BYREF puiOut AS WORD _                               ' __out USHORT *puiOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarUI2FromDec IMPORT "OLEAUT32.DLL" ALIAS "VarUI2FromDec" ( _
   BYREF pdecIn AS ANY _                                ' __in  DECIMAL *pdecIn
 , BYREF puiOut AS WORD _                               ' __out USHORT *puiOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarUI4FromUI1 IMPORT "OLEAUT32.DLL" ALIAS "VarUI4FromUI1" ( _
   BYVAL bIn AS BYTE _                                  ' __in  BYTE bIn
 , BYREF pulOut AS DWORD _                              ' __out ULONG *pulOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarUI4FromI2 IMPORT "OLEAUT32.DLL" ALIAS "VarUI4FromI2" ( _
   BYVAL uiIn AS INTEGER _                              ' __in  SHORT uiIn
 , BYREF pulOut AS DWORD _                              ' __out ULONG *pulOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarUI4FromI4 IMPORT "OLEAUT32.DLL" ALIAS "VarUI4FromI4" ( _
   BYVAL lIn AS LONG _                                  ' __in  LONG lIn
 , BYREF pulOut AS DWORD _                              ' __out ULONG *pulOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarUI4FromI8 IMPORT "OLEAUT32.DLL" ALIAS "VarUI4FromI8" ( _
   BYVAL i64In AS QUAD _                                ' __in  LONG64 i64In
 , BYREF pulOut AS DWORD _                              ' __out ULONG *pulOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarUI4FromR4 IMPORT "OLEAUT32.DLL" ALIAS "VarUI4FromR4" ( _
   BYVAL fltIn AS SINGLE _                              ' __in  FLOAT fltIn
 , BYREF pulOut AS DWORD _                              ' __out ULONG *pulOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarUI4FromR8 IMPORT "OLEAUT32.DLL" ALIAS "VarUI4FromR8" ( _
   BYVAL dblIn AS DOUBLE _                              ' __in  DOUBLE dblIn
 , BYREF pulOut AS DWORD _                              ' __out ULONG *pulOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarUI4FromDate IMPORT "OLEAUT32.DLL" ALIAS "VarUI4FromDate" ( _
   BYVAL dateIn AS DOUBLE _                             ' __in  DATE dateIn
 , BYREF pulOut AS DWORD _                              ' __out ULONG *pulOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarUI4FromCy IMPORT "OLEAUT32.DLL" ALIAS "VarUI4FromCy" ( _
   BYVAL cyIn AS CUR _                                  ' __in  CY cyIn
 , BYREF pulOut AS DWORD _                              ' __out ULONG *pulOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarUI4FromStr IMPORT "OLEAUT32.DLL" ALIAS "VarUI4FromStr" ( _
   BYREF strIn AS WSTRINGZ _                            ' __in  OLECHAR *strIn
 , BYVAL lcid AS DWORD _                                ' __in  LCID lcid
 , BYVAL dwFlags AS DWORD _                             ' __in  ULONG dwFlags
 , BYREF pulOut AS DWORD _                              ' __out ULONG *pulOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarUI4FromDisp IMPORT "OLEAUT32.DLL" ALIAS "VarUI4FromDisp" ( _
   BYVAL pdispIn AS IDispatch _                         ' __in  IDispatch *pdispIn
 , BYVAL lcid AS DWORD _                                ' __in  LCID lcid
 , BYREF pulOut AS DWORD _                              ' __out ULONG *pulOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarUI4FromBool IMPORT "OLEAUT32.DLL" ALIAS "VarUI4FromBool" ( _
   BYVAL boolIn AS INTEGER _                            ' __in  VARIANT_BOOL boolIn
 , BYREF pulOut AS DWORD _                              ' __out ULONG *pulOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarUI4FromI1 IMPORT "OLEAUT32.DLL" ALIAS "VarUI4FromI1" ( _
   BYVAL cIn AS BYTE _                                  ' __in  CHAR cIn
 , BYREF pulOut AS DWORD _                              ' __out ULONG *pulOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarUI4FromUI2 IMPORT "OLEAUT32.DLL" ALIAS "VarUI4FromUI2" ( _
   BYVAL uiIn AS WORD _                                 ' __in  USHORT uiIn
 , BYREF pulOut AS DWORD _                              ' __out ULONG *pulOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarUI4FromUI8 IMPORT "OLEAUT32.DLL" ALIAS "VarUI4FromUI8" ( _
   BYVAL ui64In AS QUAD _                               ' __in  ULONG64 ui64In
 , BYREF pulOut AS DWORD _                              ' __out ULONG *pulOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarUI4FromDec IMPORT "OLEAUT32.DLL" ALIAS "VarUI4FromDec" ( _
   BYREF pdecIn AS ANY _                                ' __in  DECIMAL *pdecIn
 , BYREF pulOut AS DWORD _                              ' __out ULONG *pulOut
 ) AS LONG                                              ' HRESULT

'/******************************************/

DECLARE FUNCTION VarUI8FromUI1 IMPORT "OLEAUT32.DLL" ALIAS "VarUI8FromUI1" ( _
   BYVAL bIn AS BYTE _                                  ' __in  BYTE bIn
 , BYREF pi64Out AS QUAD _                              ' __out ULONG64 FAR* pi64Out
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarUI8FromI2 IMPORT "OLEAUT32.DLL" ALIAS "VarUI8FromI2" ( _
   BYVAL sIn AS INTEGER _                               ' __in  SHORT sIn
 , BYREF pi64Out AS QUAD _                              ' __out ULONG64 FAR* pi64Out
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarUI8FromI4 IMPORT "OLEAUT32.DLL" ALIAS "VarUI8FromI4" ( _
   BYVAL lIn AS LONG _                                  ' __in  LONG lIn
 , BYREF pi64Out AS QUAD _                              ' __out ULONG64 FAR* pi64Out
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarUI8FromI8 IMPORT "OLEAUT32.DLL" ALIAS "VarUI8FromI8" ( _
   BYVAL ui64In AS QUAD _                               ' __in  LONG64 ui64In
 , BYREF pi64Out AS QUAD _                              ' __out ULONG64 FAR* pi64Out
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarUI8FromR4 IMPORT "OLEAUT32.DLL" ALIAS "VarUI8FromR4" ( _
   BYVAL fltIn AS SINGLE _                              ' __in  FLOAT fltIn
 , BYREF pi64Out AS QUAD _                              ' __out ULONG64 FAR* pi64Out
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarUI8FromR8 IMPORT "OLEAUT32.DLL" ALIAS "VarUI8FromR8" ( _
   BYVAL dblIn AS DOUBLE _                              ' __in  DOUBLE dblIn
 , BYREF pi64Out AS QUAD _                              ' __out ULONG64 FAR* pi64Out
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarUI8FromCy IMPORT "OLEAUT32.DLL" ALIAS "VarUI8FromCy" ( _
   BYVAL cyIn AS CUR _                                  ' __in  CY cyIn
 , BYREF pi64Out AS QUAD _                              ' __out ULONG64 FAR* pi64Out
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarUI8FromDate IMPORT "OLEAUT32.DLL" ALIAS "VarUI8FromDate" ( _
   BYVAL dateIn AS DOUBLE _                             ' __in  DATE dateIn
 , BYREF pi64Out AS QUAD _                              ' __out ULONG64 FAR* pi64Out
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarUI8FromStr IMPORT "OLEAUT32.DLL" ALIAS "VarUI8FromStr" ( _
   BYREF strIn AS WSTRINGZ _                            ' __in  OLECHAR *strIn
 , BYVAL lcid AS DWORD _                                ' __in  LCID lcid
 , BYVAL dwFlags AS DWORD _                             ' __in  unsigned long dwFlags
 , BYREF pi64Out AS QUAD _                              ' __out ULONG64 FAR* pi64Out
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarUI8FromDisp IMPORT "OLEAUT32.DLL" ALIAS "VarUI8FromDisp" ( _
   BYVAL pdispIn AS IDispatch _                         ' __in  IDispatch FAR* pdispIn
 , BYVAL lcid AS DWORD _                                ' __in  LCID lcid
 , BYREF pi64Out AS QUAD _                              ' __out ULONG64 FAR* pi64Out
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarUI8FromBool IMPORT "OLEAUT32.DLL" ALIAS "VarUI8FromBool" ( _
   BYVAL boolIn AS INTEGER _                            ' __in  VARIANT_BOOL boolIn
 , BYREF pi64Out AS QUAD _                              ' __out ULONG64 FAR* pi64Out
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarUI8FromI1 IMPORT "OLEAUT32.DLL" ALIAS "VarUI8FromI1" ( _
   BYVAL cIn AS BYTE _                                  ' __in  CHAR cIn
 , BYREF pi64Out AS QUAD _                              ' __out ULONG64 FAR* pi64Out
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarUI8FromUI2 IMPORT "OLEAUT32.DLL" ALIAS "VarUI8FromUI2" ( _
   BYVAL uiIn AS WORD _                                 ' __in  USHORT uiIn
 , BYREF pi64Out AS QUAD _                              ' __out ULONG64 FAR* pi64Out
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarUI8FromUI4 IMPORT "OLEAUT32.DLL" ALIAS "VarUI8FromUI4" ( _
   BYVAL ulIn AS DWORD _                                ' __in  ULONG ulIn
 , BYREF pi64Out AS QUAD _                              ' __out ULONG64 FAR* pi64Out
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarUI8FromDec IMPORT "OLEAUT32.DLL" ALIAS "VarUI8FromDec" ( _
   BYREF pdecIn AS ANY _                                ' __in DECIMAL *pdecIn
 , BYREF pi64Out AS QUAD _                              ' __out ULONG64 FAR* pi64Out
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarUI8FromInt IMPORT "OLEAUT32.DLL" ALIAS "VarUI8FromInt" ( _
   BYVAL intIn AS LONG _                                ' __in  INT intIn
 , BYREF pi64Out AS QUAD _                              ' __out ULONG64 FAR* pi64Out
 ) AS LONG                                              ' HRESULT

'/*********************/

DECLARE FUNCTION VarDecFromUI1 IMPORT "OLEAUT32.DLL" ALIAS "VarDecFromUI1" ( _
   BYVAL bIn AS BYTE _                                  ' __in  BYTE bIn
 , BYREF pdecOut AS ANY _                               ' __out DECIMAL * pdecOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarDecFromI2 IMPORT "OLEAUT32.DLL" ALIAS "VarDecFromI2" ( _
   BYVAL uiIn AS INTEGER _                              ' __in  SHORT uiIn
 , BYREF pdecOut AS ANY _                               ' __out DECIMAL * pdecOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarDecFromI4 IMPORT "OLEAUT32.DLL" ALIAS "VarDecFromI4" ( _
   BYVAL lIn AS LONG _                                  ' __in  LONG lIn
 , BYREF pdecOut AS ANY _                               ' __out DECIMAL * pdecOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarDecFromI8 IMPORT "OLEAUT32.DLL" ALIAS "VarDecFromI8" ( _
   BYVAL i64In AS QUAD _                                ' __in  i64In
 , BYREF pdecOut AS ANY _                               ' __out DECIMAL * pdecOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarDecFromR4 IMPORT "OLEAUT32.DLL" ALIAS "VarDecFromR4" ( _
   BYVAL fltIn AS SINGLE _                              ' __in  FLOAT fltIn
 , BYREF pdecOut AS ANY _                               ' __out DECIMAL * pdecOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarDecFromR8 IMPORT "OLEAUT32.DLL" ALIAS "VarDecFromR8" ( _
   BYVAL dblIn AS DOUBLE _                              ' __in  DOUBLE dblIn
 , BYREF pdecOut AS ANY _                               ' __out DECIMAL * pdecOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarDecFromDate IMPORT "OLEAUT32.DLL" ALIAS "VarDecFromDate" ( _
   BYVAL dateIn AS DOUBLE _                             ' __in  DATE dateIn
 , BYREF pdecOut AS ANY _                               ' __out DECIMAL * pdecOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarDecFromCy IMPORT "OLEAUT32.DLL" ALIAS "VarDecFromCy" ( _
   BYVAL cyIn AS CUR _                                  ' __in  CURRENCY cyIn
 , BYREF pdecOut AS ANY _                               ' __out DECIMAL pdecOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarDecFromStr IMPORT "OLEAUT32.DLL" ALIAS "VarDecFromStr" ( _
   BYREF strIn AS WSTRINGZ _                            ' __in  OLECHAR *strIn
 , BYVAL lcid AS DWORD _                                ' __in  LCID lcid
 , BYVAL dwFlags AS DWORD _                             ' __in  ULONG dwFlags
 , BYREF pdecOut AS ANY _                               ' __out DECIMAL *pdecOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarDecFromDisp IMPORT "OLEAUT32.DLL" ALIAS "VarDecFromDisp" ( _
   BYVAL pdispIn AS IDispatch _                         ' __in  IDispatch *pdispIn
 , BYVAL lcid AS DWORD _                                ' __in  LCID lcid
 , BYREF pdecOut AS ANY _                               ' __out DECIMAL *pdecOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarDecFromBool IMPORT "OLEAUT32.DLL" ALIAS "VarDecFromBool" ( _
   BYVAL boolIn AS INTEGER _                            ' __in  VARIANT_BOOL boolIn
 , BYREF pdecOut AS ANY _                               ' __out DECIMAL *pdecOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarDecFromI1 IMPORT "OLEAUT32.DLL" ALIAS "VarDecFromI1" ( _
   BYVAL cIn AS BYTE _                                  ' __in  CHAR cIn
 , BYREF pdecOut AS ANY _                               ' __out DECIMAL *pdecOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarDecFromUI2 IMPORT "OLEAUT32.DLL" ALIAS "VarDecFromUI2" ( _
   BYVAL uiIn AS WORD _                                 ' __in  USHORT uiIn
 , BYREF pdecOut AS ANY _                               ' __out DECIMAL *pdecOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarDecFromUI4 IMPORT "OLEAUT32.DLL" ALIAS "VarDecFromUI4" ( _
   BYVAL ulIn AS DWORD _                                ' __in  ULONG ulIn
 , BYREF pdecOut AS ANY _                               ' __out DECIMAL *pdecOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarDecFromUI8 IMPORT "OLEAUT32.DLL" ALIAS "VarDecFromUI8" ( _
   BYVAL ui64In AS QUAD _                               ' __in  ULONG64 ui64In
 , BYREF pdecOut AS ANY _                               ' __out DECIMAL *pdecOut
 ) AS LONG                                              ' HRESULT

'#define VarUI4FromUI4(in, pOut) (*(pOut) = (in))
'#define VarI4FromI4(in, pOut)   (*(pOut) = (in))

DECLARE FUNCTION VarI4FromI8 IMPORT "OLEAUT32.DLL" ALIAS "VarI4FromI8" ( _
   BYVAL i64In AS QUAD _                                ' __in  LONG64 i64In
 , BYREF plOut AS LONG _                                ' __out LONG *plOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarI4FromUI8 IMPORT "OLEAUT32.DLL" ALIAS "VarI4FromUI8" ( _
   BYVAL i64In AS QUAD _                                ' __in  LONG64 i64In
 , BYREF plOut AS LONG _                                ' __out LONG *plOut
 ) AS LONG                                              ' HRESULT

'#define VarUI8FromUI8(in, pOut) (*(pOut) = (in))
'#define VarI8FromI8(in, pOut)   (*(pOut) = (in))


'#define VarUI1FromInt       VarUI1FromI4
'#define VarUI1FromUint      VarUI1FromUI4
'#define VarI2FromInt        VarI2FromI4
'#define VarI2FromUint       VarI2FromUI4
'#define VarI4FromInt        VarI4FromI4
'#define VarI4FromUint       VarI4FromUI4
'#define VarI8FromInt        VarI8FromI4
'#define VarI8FromUint       VarI8FromUI4
'#define VarR4FromInt        VarR4FromI4
'#define VarR4FromUint       VarR4FromUI4
'#define VarR8FromInt        VarR8FromI4
'#define VarR8FromUint       VarR8FromUI4
'#define VarDateFromInt      VarDateFromI4
'#define VarDateFromUint     VarDateFromUI4
'#define VarCyFromInt        VarCyFromI4
'#define VarCyFromUint       VarCyFromUI4
'#define VarBstrFromInt      VarBstrFromI4
'#define VarBstrFromUint     VarBstrFromUI4
'#define VarBoolFromInt      VarBoolFromI4
'#define VarBoolFromUint     VarBoolFromUI4
'#define VarI1FromInt        VarI1FromI4
'#define VarI1FromUint       VarI1FromUI4
'#define VarUI2FromInt       VarUI2FromI4
'#define VarUI2FromUint      VarUI2FromUI4
'#define VarUI4FromInt       VarUI4FromI4
'#define VarUI4FromUint      VarUI4FromUI4
'#define VarDecFromInt       VarDecFromI4
'#define VarDecFromUint      VarDecFromUI4
'#define VarIntFromUI1       VarI4FromUI1
'#define VarIntFromI2        VarI4FromI2
'#define VarIntFromI4        VarI4FromI4
'#define VarIntFromI8        VarI4FromI8
'#define VarIntFromR4        VarI4FromR4
'#define VarIntFromR8        VarI4FromR8
'#define VarIntFromDate      VarI4FromDate
'#define VarIntFromCy        VarI4FromCy
'#define VarIntFromStr       VarI4FromStr
'#define VarIntFromDisp      VarI4FromDisp
'#define VarIntFromBool      VarI4FromBool
'#define VarIntFromI1        VarI4FromI1
'#define VarIntFromUI2       VarI4FromUI2
'#define VarIntFromUI4       VarI4FromUI4
'#define VarIntFromUI8       VarI4FromUI8
'#define VarIntFromDec       VarI4FromDec
'#define VarIntFromUint      VarI4FromUI4
'#define VarUintFromUI1      VarUI4FromUI1
'#define VarUintFromI2       VarUI4FromI2
'#define VarUintFromI4       VarUI4FromI4
'#define VarUintFromI8       VarUI4FromI8
'#define VarUintFromR4       VarUI4FromR4
'#define VarUintFromR8       VarUI4FromR8
'#define VarUintFromDate     VarUI4FromDate
'#define VarUintFromCy       VarUI4FromCy
'#define VarUintFromStr      VarUI4FromStr
'#define VarUintFromDisp     VarUI4FromDisp
'#define VarUintFromBool     VarUI4FromBool
'#define VarUintFromI1       VarUI4FromI1
'#define VarUintFromUI2      VarUI4FromUI2
'#define VarUintFromUI4      VarUI4FromUI4
'#define VarUintFromUI8      VarUI4FromUI8
'#define VarUintFromDec      VarUI4FromDec
'#define VarUintFromInt      VarUI4FromI4

'/* Mac Note: On the Mac, the coersion functions support the
' * Symantec C++ calling convention for float/double. To support
' * float/double arguments compiled with the MPW C compiler,
' * use the following APIs to move MPW float/double values into
' * a VARIANT.
' */

'/*---------------------------------------------------------------------*/
'/*            New VARIANT <-> string parsing functions                 */
'/*---------------------------------------------------------------------*/

' // Size = 24 bytes
TYPE NUMPARSE DWORD
   cDig       AS LONG    ' INT
   dwInFlags  AS DWORD   ' ULONG
   dwOutFlags AS DWORD   ' ULONG
   cchUsed    AS LONG    ' INT
   nBaseShift AS LONG    ' INT
   nPwr10     AS LONG    ' INT
END TYPE

'/* flags used by both dwInFlags and dwOutFlags:
' */
%NUMPRS_LEADING_WHITE  = &H0001???
%NUMPRS_TRAILING_WHITE = &H0002???
%NUMPRS_LEADING_PLUS   = &H0004???
%NUMPRS_TRAILING_PLUS  = &H0008???
%NUMPRS_LEADING_MINUS  = &H0010???
%NUMPRS_TRAILING_MINUS = &H0020???
%NUMPRS_HEX_OCT        = &H0040???
%NUMPRS_PARENS         = &H0080???
%NUMPRS_DECIMAL        = &H0100???
%NUMPRS_THOUSANDS      = &H0200???
%NUMPRS_CURRENCY       = &H0400???
%NUMPRS_EXPONENT       = &H0800???
%NUMPRS_USE_ALL        = &H1000???
%NUMPRS_STD            = &H1FFF???

'/* flags used by dwOutFlags only:
' */
%NUMPRS_NEG            = &H10000???
%NUMPRS_INEXACT        = &H20000???

'/* flags used by VarNumFromParseNum to indicate acceptable result types:
' */
%VTBIT_I1      = &H10000???  ' (1 << VT_I1)
%VTBIT_UI1     = &H20000???  ' (1 << VT_UI1)
%VTBIT_I2      = &H4???      ' (1 << VT_I2)
%VTBIT_UI2     = &H40000???  ' (1 << VT_UI2)
%VTBIT_I4      = &H8???      ' (1 << VT_I4)
%VTBIT_UI4     = &H80000???  ' (1 << VT_UI4)
%VTBIT_I8      = &H100000??? ' (1 << VT_I8)
%VTBIT_UI8     = &H200000??? ' (1 << VT_UI8)
%VTBIT_R4      = &H10???     ' (1 << VT_R4)
%VTBIT_R8      = &H20???     ' (1 << VT_R8)
%VTBIT_CY      = &H40???     ' (1 << VT_CY)
%VTBIT_DECIMAL = &H4000???   ' (1 << VT_DECIMAL)


DECLARE FUNCTION VarParseNumFromStr IMPORT "OLEAUT32.DLL" ALIAS "VarParseNumFromStr" ( _
   BYREF strIn AS WSTRINGZ _                            ' __in  OLECHAR *strIn
 , BYVAL lcid AS DWORD _                                ' __in  LCID lcid
 , BYVAL dwFlags AS DWORD _                             ' __in  unsigned long dwFlags
 , BYREF pnumprs AS NUMPARSE _                          ' __in  NUMPARSE* pnumprs
 , BYREF rgbDig AS BYTE _                               ' __out unsigned char* rgbDig [array]
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarNumFromParseNum IMPORT "OLEAUT32.DLL" ALIAS "VarNumFromParseNum" ( _
   BYREF pnumprs AS NUMPARSE _                          ' __in  NUMPARSE* pnumprs
 , BYREF rgbDig AS BYTE _                               ' __in  unsigned char* rgbDig [array]
 , BYVAL dwVtBits AS DWORD _                            ' __in  unsigned long dwVtBits
 , BYREF pvar AS ANY _                                  ' __out VARIANT* pvar
 ) AS LONG                                              ' HRESULT

'/*---------------------------------------------------------------------*/
'/*                     VARTYPE Math API                                */
'/*---------------------------------------------------------------------*/

DECLARE FUNCTION VarAdd IMPORT "OLEAUT32.DLL" ALIAS "VarAdd" ( _
   BYREF pvarLeft AS ANY _                              ' __in  LPVARIANT pvarLeft
 , BYREF pvarRight AS ANY _                             ' __in  LPVARIANT pvarRight
 , BYREF pvarResult AS ANY _                            ' __out LPVARIANT pvarResult
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarAnd IMPORT "OLEAUT32.DLL" ALIAS "VarAnd" ( _
   BYREF pvarLeft AS ANY _                              ' __in  LPVARIANT pvarLeft
 , BYREF pvarRight AS ANY _                             ' __in  LPVARIANT pvarRight
 , BYREF pvarResult AS ANY _                            ' __out LPVARIANT pvarResult
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarCat IMPORT "OLEAUT32.DLL" ALIAS "VarCat" ( _
   BYREF pvarLeft AS ANY _                              ' __in  LPVARIANT pvarLeft
 , BYREF pvarRight AS ANY _                             ' __in  LPVARIANT pvarRight
 , BYREF pvarResult AS ANY _                            ' __out LPVARIANT pvarResult
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarDiv IMPORT "OLEAUT32.DLL" ALIAS "VarDiv" ( _
   BYREF pvarLeft AS ANY _                              ' __in  LPVARIANT pvarLeft
 , BYREF pvarRight AS ANY _                             ' __in  LPVARIANT pvarRight
 , BYREF pvarResult AS ANY _                            ' __out LPVARIANT pvarResult
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarEqv IMPORT "OLEAUT32.DLL" ALIAS "VarEqv" ( _
   BYREF pvarLeft AS ANY _                              ' __in  LPVARIANT pvarLeft
 , BYREF pvarRight AS ANY _                             ' __in  LPVARIANT pvarRight
 , BYREF pvarResult AS ANY _                            ' __out LPVARIANT pvarResult
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarIdiv IMPORT "OLEAUT32.DLL" ALIAS "VarIdiv" ( _
   BYREF pvarLeft AS ANY _                              ' __in  LPVARIANT pvarLeft
 , BYREF pvarRight AS ANY _                             ' __in  LPVARIANT pvarRight
 , BYREF pvarResult AS ANY _                            ' __out LPVARIANT pvarResult
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarImp IMPORT "OLEAUT32.DLL" ALIAS "VarImp" ( _
   BYREF pvarLeft AS ANY _                              ' __in  LPVARIANT pvarLeft
 , BYREF pvarRight AS ANY _                             ' __in  LPVARIANT pvarRight
 , BYREF pvarResult AS ANY _                            ' __out LPVARIANT pvarResult
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarMod IMPORT "OLEAUT32.DLL" ALIAS "VarMod" ( _
   BYREF pvarLeft AS ANY _                              ' __in  LPVARIANT pvarLeft
 , BYREF pvarRight AS ANY _                             ' __in  LPVARIANT pvarRight
 , BYREF pvarResult AS ANY _                            ' __out LPVARIANT pvarResult
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarMul IMPORT "OLEAUT32.DLL" ALIAS "VarMul" ( _
   BYREF pvarLeft AS ANY _                              ' __in  LPVARIANT pvarLeft
 , BYREF pvarRight AS ANY _                             ' __in  LPVARIANT pvarRight
 , BYREF pvarResult AS ANY _                            ' __out LPVARIANT pvarResult
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarOr IMPORT "OLEAUT32.DLL" ALIAS "VarOr" ( _
   BYREF pvarLeft AS ANY _                              ' __in  LPVARIANT pvarLeft
 , BYREF pvarRight AS ANY _                             ' __in  LPVARIANT pvarRight
 , BYREF pvarResult AS ANY _                            ' __out LPVARIANT pvarResult
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarPow IMPORT "OLEAUT32.DLL" ALIAS "VarPow" ( _
   BYREF pvarLeft AS ANY _                              ' __in  LPVARIANT pvarLeft
 , BYREF pvarRight AS ANY _                             ' __in  LPVARIANT pvarRight
 , BYREF pvarResult AS ANY _                            ' __out LPVARIANT pvarResult
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarSub IMPORT "OLEAUT32.DLL" ALIAS "VarSub" ( _
   BYREF pvarLeft AS ANY _                              ' __in  LPVARIANT pvarLeft
 , BYREF pvarRight AS ANY _                             ' __in  LPVARIANT pvarRight
 , BYREF pvarResult AS ANY _                            ' __out LPVARIANT pvarResult
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarXor IMPORT "OLEAUT32.DLL" ALIAS "VarXor" ( _
   BYREF pvarLeft AS ANY _                              ' __in  LPVARIANT pvarLeft
 , BYREF pvarRight AS ANY _                             ' __in  LPVARIANT pvarRight
 , BYREF pvarResult AS ANY _                            ' __out LPVARIANT pvarResult
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarAbs IMPORT "OLEAUT32.DLL" ALIAS "VarAbs" ( _
   BYREF pvarIn AS ANY _                                ' __in  LPVARIANT pvarIn
 , BYREF pvarResult AS ANY _                            ' __out LPVARIANT pvarResult
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarFix IMPORT "OLEAUT32.DLL" ALIAS "VarFix" ( _
   BYREF pvarIn AS ANY _                                ' __in  LPVARIANT pvarIn
 , BYREF pvarResult AS ANY _                            ' __out LPVARIANT pvarResult
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarInt IMPORT "OLEAUT32.DLL" ALIAS "VarInt" ( _
   BYREF pvarIn AS ANY _                                ' __in  LPVARIANT pvarIn
 , BYREF pvarResult AS ANY _                            ' __out LPVARIANT pvarResult
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarNeg IMPORT "OLEAUT32.DLL" ALIAS "VarNeg" ( _
   BYREF pvarIn AS ANY _                                ' __in  LPVARIANT pvarIn
 , BYREF pvarResult AS ANY _                            ' __out LPVARIANT pvarResult
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarNot IMPORT "OLEAUT32.DLL" ALIAS "VarNot" ( _
   BYREF pvarIn AS ANY _                                ' __in  LPVARIANT pvarIn
 , BYREF pvarResult AS ANY _                            ' __out LPVARIANT pvarResult
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarRound IMPORT "OLEAUT32.DLL" ALIAS "VarRound" ( _
   BYREF pvarIn AS ANY _                                ' __in  LPVARIANT pvarIn
 , BYVAL cDecimals AS LONG _                            ' __in  int cDecimals
 , BYREF pvarResult AS ANY _                            ' __out LPVARIANT pvarResult
 ) AS LONG                                              ' HRESULT

'// dwFlags passed to CompareString if a string compare
DECLARE FUNCTION VarCmp IMPORT "OLEAUT32.DLL" ALIAS "VarCmp" ( _
   BYREF pvarLeft AS ANY _                              ' __in LPVARIANT pvarLeft
 , BYREF pvarRight AS ANY _                             ' __in LPVARIANT pvarRight
 , BYVAL lcid AS DWORD _                                ' __in LCID lcid
 , BYVAL dwFlags AS DWORD _                             ' __in DWORD dwFlags
 ) AS LONG                                              ' HRESULT

'#ifdef __cplusplus
'extern "C++" {
'// Add wrapper for old ATL headers to call
'__inline
'HRESULT
'#if !defined(_M_CEE_PURE)
'STDAPICALLTYPE
'#endif
'VarCmp(LPVARIANT pvarLeft, LPVARIANT pvarRight, LCID lcid) {
'    return VarCmp(pvarLeft, pvarRight, lcid, 0);
'}
'} // extern "C++"
'#endif


'// Decimal math
'//
DECLARE FUNCTION VarDecAdd IMPORT "OLEAUT32.DLL" ALIAS "VarDecAdd" ( _
   BYREF pdecLeft AS ANY _                              ' __in  LPDECIMAL pdecLeft
 , BYREF pdecRight AS ANY _                             ' __in  LPDECIMAL pdecRight
 , BYREF pdecResult AS ANY _                            ' __out LPDECIMAL pdecResult
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarDecDiv IMPORT "OLEAUT32.DLL" ALIAS "VarDecDiv" ( _
   BYREF pdecLeft AS ANY _                              ' __in  LPDECIMAL pdecLeft
 , BYREF pdecRight AS ANY _                             ' __in  LPDECIMAL pdecRight
 , BYREF pdecResult AS ANY _                            ' __out LPDECIMAL pdecResult
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarDecMul IMPORT "OLEAUT32.DLL" ALIAS "VarDecMul" ( _
   BYREF pdecLeft AS ANY _                              ' __in  LPDECIMAL pdecLeft
 , BYREF pdecRight AS ANY _                             ' __in  LPDECIMAL pdecRight
 , BYREF pdecResult AS ANY _                            ' __out LPDECIMAL pdecResult
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarDecSub IMPORT "OLEAUT32.DLL" ALIAS "VarDecSub" ( _
   BYREF pdecLeft AS ANY _                              ' __in  LPDECIMAL pdecLeft
 , BYREF pdecRight AS ANY _                             ' __in  LPDECIMAL pdecRight
 , BYREF pdecResult AS ANY _                            ' __out LPDECIMAL pdecResult
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarDecAbs IMPORT "OLEAUT32.DLL" ALIAS "VarDecAbs" ( _
   BYREF pdecIn AS ANY _                                ' __in  LPDECIMAL pdecIn
 , BYREF pdecResult AS ANY _                            ' __out LPDECIMAL pdecResult
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarDecFix IMPORT "OLEAUT32.DLL" ALIAS "VarDecFix" ( _
   BYREF pdecIn AS ANY _                                ' __in  LPDECIMAL pdecIn
 , BYREF pdecResult AS ANY _                            ' __out LPDECIMAL pdecResult
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarDecInt IMPORT "OLEAUT32.DLL" ALIAS "VarDecInt" ( _
   BYREF pdecIn AS ANY _                                ' __in  LPDECIMAL pdecIn
 , BYREF pdecResult AS ANY _                            ' __out LPDECIMAL pdecResult
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarDecNeg IMPORT "OLEAUT32.DLL" ALIAS "VarDecNeg" ( _
   BYREF pdecIn AS ANY _                                ' __in  LPDECIMAL pdecIn
 , BYREF pdecResult AS ANY _                            ' __out LPDECIMAL pdecResult
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarDecRound IMPORT "OLEAUT32.DLL" ALIAS "VarDecRound" ( _
   BYREF pdecIn AS ANY _                                ' __in  LPDECIMAL pdecIn
 , BYVAL cDecimals AS LONG _                            ' __in  int cDecimals
 , BYREF pdecResult AS ANY _                            ' __out LPDECIMAL pdecResult
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarDecCmp IMPORT "OLEAUT32.DLL" ALIAS "VarDecCmp" ( _
   BYREF pdecLeft AS ANY _                              ' __in LPDECIMAL pdecLeft
 , BYREF pdecRight AS ANY _                             ' __in LPDECIMAL pdecRight
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarDecCmpR8 IMPORT "OLEAUT32.DLL" ALIAS "VarDecCmpR8" ( _
   BYREF pdecIn AS ANY _                                ' __in LPDECIMAL pdecIn
 , BYVAL dblRight AS DOUBLE _                           ' __in double dblRight
 ) AS LONG                                              ' HRESULT


'// Currency math
'//
DECLARE FUNCTION VarCyAdd IMPORT "OLEAUT32.DLL" ALIAS "VarCyAdd" ( _
   BYVAL cyLeft AS CUR _                                ' __in  CY cyLeft
 , BYVAL cyRight AS CUR _                               ' __in  CY cyRight
 , BYREF pcyResult AS CUR _                             ' __out LPCY pcyResult
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarCyMul IMPORT "OLEAUT32.DLL" ALIAS "VarCyMul" ( _
   BYVAL cyLeft AS CUR _                                ' __in  CY cyLeft
 , BYVAL cyRight AS CUR _                               ' __in  CY cyRight
 , BYREF pcyResult AS CUR _                             ' __out LPCY pcyResult
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarCyMulI4 IMPORT "OLEAUT32.DLL" ALIAS "VarCyMulI4" ( _
   BYVAL cyLeft AS CUR _                                ' __in  CY cyLeft
 , BYVAL lRight AS LONG _                               ' __in  long lRight
 , BYREF pcyResult AS CUR _                             ' __out LPCY pcyResult
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarCyMulI8 IMPORT "OLEAUT32.DLL" ALIAS "VarCyMulI8" ( _
   BYVAL cyLeft AS CUR _                                ' __in  CY cyLeft
 , BYVAL lRight AS QUAD _                               ' __in  LONG64 lRight
 , BYREF pcyResult AS CUR _                             ' __out LPCY pcyResult
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarCySub IMPORT "OLEAUT32.DLL" ALIAS "VarCySub" ( _
   BYVAL cyLeft AS CUR _                                ' __in  CY cyLeft
 , BYVAL cyRight AS CUR _                               ' __in  CY cyRight
 , BYREF pcyResult AS CUR _                             ' __out LPCY pcyResult
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarCyAbs IMPORT "OLEAUT32.DLL" ALIAS "VarCyAbs" ( _
   BYVAL cyIn AS CUR _                                  ' __in  CY cyIn
 , BYREF pcyResult AS CUR _                             ' __out LPCY pcyResult
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarCyFix IMPORT "OLEAUT32.DLL" ALIAS "VarCyFix" ( _
   BYVAL cyIn AS CUR _                                  ' __in  CY cyIn
 , BYREF pcyResult AS CUR _                             ' __out LPCY pcyResult
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarCyInt IMPORT "OLEAUT32.DLL" ALIAS "VarCyInt" ( _
   BYVAL cyIn AS CUR _                                  ' __in  CY cyIn
 , BYREF pcyResult AS CUR _                             ' __out LPCY pcyResult
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarCyNeg IMPORT "OLEAUT32.DLL" ALIAS "VarCyNeg" ( _
   BYVAL cyIn AS CUR _                                  ' __in  CY cyIn
 , BYREF pcyResult AS CUR _                             ' __out LPCY pcyResult
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarCyRound IMPORT "OLEAUT32.DLL" ALIAS "VarCyRound" ( _
   BYVAL cyIn AS CUR _                                  ' __in  CY cyIn
 , BYVAL cDecimals AS LONG _                            ' __in  int cDecimals
 , BYREF pcyResult AS CUR _                             ' __out LPCY pcyResult
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarCyCmp IMPORT "OLEAUT32.DLL" ALIAS "VarCyCmp" ( _
   BYVAL cyLeft AS CUR _                                ' __in CY cyLeft
 , BYREF cyRight AS CUR _                               ' __in CY cyRight
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarCyCmpR8 IMPORT "OLEAUT32.DLL" ALIAS "VarCyCmpR8" ( _
   BYVAL cyLeft AS CUR _                                ' __in CY cyLeft
 , BYVAL dblRight AS DOUBLE _                           ' __in double dblRight
 ) AS LONG                                              ' HRESULT


'// Misc support functions
'//
DECLARE FUNCTION VarBstrCat IMPORT "OLEAUT32.DLL" ALIAS "VarBstrCat" ( _
   BYREF bstrLeft AS WSTRING _                          ' __in  BSTR bstrLeft
 , BYREF bstrRight AS WSTRING _                         ' __in  BSTR bstrRight
 , BYREF pbstrResult AS WSTRING _                       ' __out LPBSTR pbstrResult
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarBstrCmp IMPORT "OLEAUT32.DLL" ALIAS "VarBstrCmp" ( _
   BYREF bstr AS WSTRING _                              ' __in BSTR bstrLeft
 , BYREF bstrRight AS WSTRING _                         ' __in BSTR bstrRight
 , BYVAL lcid AS DWORD _                                ' __in LCID lcid
 , BYVAL dwFLags AS DWORD _                             ' __in ULONG dwFLags
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarR8Pow IMPORT "OLEAUT32.DLL" ALIAS "VarR8Pow" ( _
   BYVAL dblLeft AS DOUBLE _                            ' __in  double dblLeft
 , BYVAL dblRight AS DOUBLE _                           ' __in  double dblRight
 , BYREF pdblResult AS WSTRING _                        ' __out LPBSTR * pdblResult
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarR4CmpR8 IMPORT "OLEAUT32.DLL" ALIAS "VarR4CmpR8" ( _
   BYVAL fltLeft AS SINGLE _                            ' __in float fltLeft
 , BYVAL dblRight AS DOUBLE _                           ' __in double dblRight
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarR8Round IMPORT "OLEAUT32.DLL" ALIAS "VarR8Round" ( _
   BYVAL dblIn AS DOUBLE _                              ' __in  double dblIn
 , BYVAL cDecimals AS LONG _                            ' __in  int cDecimals
 , BYREF pdblResult AS DOUBLE _                         ' __out double * pdblResult
 ) AS LONG                                              ' HRESULT


'// Compare results.  These are returned as a SUCCESS HResult.  Subtracting
'// one gives the usual values of -1 for Less Than, 0 for Equal To, +1 for
'// Greater Than.
'//
%VARCMP_LT   = 0
%VARCMP_EQ   = 1
%VARCMP_GT   = 2
%VARCMP_NULL = 3

'// VT_HARDTYPE tells the compare routine that the argument is a literal or
'// otherwise declared of that specific type.  It causes comparison rules to
'// change. For example, if a hard-type string is compared to a variant (not hard
'// -type) number, the number is converted to string.  If a hard-type number is
'// compared to a variant string, the string is converted to number.  If they're
'// both variant, then number < string.
%VT_HARDTYPE = %VT_RESERVED

'/*---------------------------------------------------------------------*/
'/*                   New date functions                                */
'/*---------------------------------------------------------------------*/

'/* The UDATE structure is used with VarDateFromUdate() and VarUdateFromDate().
' * It represents an "unpacked date".
' */

' // Size = 18 bytes
TYPE UDATE WORD
   st         AS SYSTEMTIME   ' SYSTEMTIME
   wDayOfYear AS WORD         ' USHORT
END TYPE

'/* APIs to "pack" and "unpack" dates.
' * NOTE: Ex version of VarDateFromUdate obeys 2 digit year setting in
' * control panel.
' */
DECLARE FUNCTION VarDateFromUdate IMPORT "OLEAUT32.DLL" ALIAS "VarDateFromUdate" ( _
   BYREF pudateIn AS UDATE _                            ' __in  UDATE *pudateIn
 , BYVAL dwFlags AS DWORD _                             ' __in  unsigned long dwFlags
 , BYREF pdateOut AS DOUBLE _                           ' __out DATE *pdateOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarDateFromUdateEx IMPORT "OLEAUT32.DLL" ALIAS "VarDateFromUdateEx" ( _
   BYREF pudateIn AS UDATE _                            ' __in  UDATE *pudateIn
 , BYVAL lcid AS DWORD _                                ' __in  LCID lcid
 , BYVAL dwFlags AS DWORD _                             ' __in  unsigned long dwFlags
 , BYREF pdateOut AS DOUBLE _                           ' __out DATE *pdateOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarUdateFromDate IMPORT "OLEAUT32.DLL" ALIAS "VarUdateFromDate" ( _
   BYVAL dateIns AS DOUBLE _                            ' __in  DATE dateIns
 , BYVAL dwFlags AS DWORD _                             ' __in  unsigned long dwFlags
 , BYREF pudateOut AS UDATE _                           ' __out UDATE *pudateOut
 ) AS LONG                                              ' HRESULT

'/* API to retrieve the secondary(altername) month names
'   Useful for Hijri, Polish and Russian alternate month names
'*/
DECLARE FUNCTION GetAltMonthNames IMPORT "OLEAUT32.DLL" ALIAS "GetAltMonthNames" ( _
   BYVAL lcid AS DWORD _                                ' __in  LCID lcid
 , BYREF prgp AS DWORD _                                ' __out LPOLESTR** prgp
 ) AS LONG                                              ' HRESULT

'/*---------------------------------------------------------------------*/
'/*                 Format                                              */
'/*---------------------------------------------------------------------*/

DECLARE FUNCTION VarFormat IMPORT "OLEAUT32.DLL" ALIAS "VarFormat" ( _
   BYREF pvarIn AS ANY _                                ' __in  LPVARIANT pvarIn
 , BYREF pbstrFormat AS WSTRINGZ _                      ' __in  LPOLESTR pbstrFormat
 , BYVAL iFirstDay AS LONG _                            ' __in  int iFirstDay
 , BYVAL iFirstWeek AS LONG _                           ' __in  int iFirstWeek
 , BYVAL dwFlags AS DWORD _                             ' __in  ULONG dwFlags
 , BYREF pbstrOut AS WSTRING _                          ' __out BSTR *pbstrOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarFormatDateTime IMPORT "OLEAUT32.DLL" ALIAS "VarFormatDateTime" ( _
   BYREF pvarIn AS ANY _                                ' __in  LPVARIANT pvarIn
 , BYVAL iNamedFormat AS LONG _                         ' __in  int iNamedFormat
 , BYVAL dwFlags AS DWORD _                             ' __in  ULONG dwFlags
 , BYREF pbstrOut AS WSTRING _                          ' __out BSTR *pbstrOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarFormatNumber IMPORT "OLEAUT32.DLL" ALIAS "VarFormatNumber" ( _
   BYREF pvarIn AS ANY _                                ' __in  LPVARIANT pvarIn
 , BYVAL iNumDig AS LONG _                              ' __in  int iNumDig
 , BYVAL ilncLead AS LONG _                             ' __in  int ilncLead
 , BYVAL iUseParens AS LONG _                           ' __in  int iUseParens
 , BYVAL iGroup AS LONG _                               ' __in  int iGroup
 , BYVAL dwFlags AS DWORD _                             ' __in  ULONG dwFlags
 , BYREF pbstrOut AS WSTRING _                          ' __out BSTR *pbstrOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarFormatPercent IMPORT "OLEAUT32.DLL" ALIAS "VarFormatPercent" ( _
   BYREF pvarIn AS ANY _                                ' __in  LPVARIANT pvarIn
 , BYVAL iNumDig AS LONG _                              ' __in  int iNumDig
 , BYVAL ilncLead AS LONG _                             ' __in  int ilncLead
 , BYVAL iUseParens AS LONG _                           ' __in  int iUseParens
 , BYVAL iGroup AS LONG _                               ' __in  int iGroup
 , BYVAL dwFlags AS DWORD _                             ' __in  ULONG dwFlags
 , BYREF pbstrOut AS WSTRING _                          ' __out BSTR *pbstrOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarFormatCurrency IMPORT "OLEAUT32.DLL" ALIAS "VarFormatCurrency" ( _
   BYREF pvarIn AS ANY _                                ' __in  LPVARIANT pvarIn
 , BYVAL iNumDig AS LONG _                              ' __in  int iNumDig
 , BYVAL ilncLead AS LONG _                             ' __in  int ilncLead
 , BYVAL iUseParens AS LONG _                           ' __in  int iUseParens
 , BYVAL iGroup AS LONG _                               ' __in  int iGroup
 , BYVAL dwFlags AS DWORD _                             ' __in  ULONG dwFlags
 , BYREF pbstrOut AS WSTRING _                          ' __out BSTR *pbstrOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarWeekdayName IMPORT "OLEAUT32.DLL" ALIAS "VarWeekdayName" ( _
   BYVAL iWeekday AS LONG _                             ' __in  int iWeekday
 , BYVAL fAbbrey AS LONG _                              ' __in  int fAbbrey
 , BYVAL iFirstDay AS LONG _                            ' __in  int iFirstDay
 , BYVAL dwFlags AS DWORD _                             ' __in  ULONG dwFlags
 , BYREF pbstrOut AS WSTRING _                          ' __out BSTR *pbstrOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarMonthName IMPORT "OLEAUT32.DLL" ALIAS "VarMonthName" ( _
   BYVAL iMonth AS LONG _                               ' __in  int iMonth
 , BYVAL fAbbrey AS LONG _                              ' __in  int fAbbrey
 , BYVAL dwFlags AS DWORD _                             ' __in  ULONG dwFlags
 , BYREF pbstrOut AS WSTRING _                          ' __out BSTR *pbstrOut
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarFormatFromTokens IMPORT "OLEAUT32.DLL" ALIAS "VarFormatFromTokens" ( _
   BYREF pvarIn AS ANY _                                ' __in  LPVARIANT pvarIn
 , BYREF pstrFormat AS WSTRINGZ _                       ' __in  LPOLESTR pstrFormat
 , BYVAL pbTokCur AS BYTE PTR _                         ' __in  LBYTE pbTokCur
 , BYVAL dwFlags AS DWORD _                             ' __in  ULONG dwFlags
 , BYREF pbstrOut AS WSTRING _                          ' __out BSTR *pbstrOut
 , BYVAL lcid AS DWORD _                                ' __in  LCID lcid
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION VarTokenizeFormatString IMPORT "OLEAUT32.DLL" ALIAS "VarTokenizeFormatString" ( _
   BYREF pstrFormat AS WSTRINGZ _                       ' __in  LPOLESTR pstrFormat
 , BYVAL rgbTok AS BYTE PTR _                           ' __in  LPBYTE rgbTok
 , BYVAL cbTok AS LONG _                                ' __in  int cbTok
 , BYVAL iFirstDay AS LONG _                            ' __in  int iFirstDay
 , BYVAL iFirstWeek AS LONG _                           ' __in  int iFirstWeek
 , BYVAL lcid AS DWORD _                                ' __in  LCID lcid
 , BYREF pcbActual AS LONG _                            ' __out *pcbActual
 ) AS LONG                                              ' HRESULT

'/*---------------------------------------------------------------------*/
'/*                 ITypeLib                                            */
'/*---------------------------------------------------------------------*/

'typedef /* [unique] */  __RPC_unique_pointer ITypeLib *LPTYPELIB;


'/*---------------------------------------------------------------------*/
'/*                ITypeInfo                                            */
'/*---------------------------------------------------------------------*/


'typedef LONG DISPID;
'typedef DISPID MEMBERID;

%MEMBERID_NIL   = %DISPID_UNKNOWN
%ID_DEFAULTINST = -2


'/* Flags for IDispatch::Invoke */
%DISPATCH_METHOD         = &H1
%DISPATCH_PROPERTYGET    = &H2
%DISPATCH_PROPERTYPUT    = &H4
%DISPATCH_PROPERTYPUTREF = &H8

' Note: For VBer's that are used to vbxxx constants.
%vbMethod          = 1     ' &H1
%vbCall            = 1     ' &H1
%vbGet             = 2     ' &H2
%vbLet             = 4     ' &H4
%vbPut             = 4     ' &H4
%vbSet             = 8     ' &H8
%vbPutRef          = 8     ' &H8

'typedef /* [unique] */  __RPC_unique_pointer ITypeInfo *LPTYPEINFO;

'/*---------------------------------------------------------------------*/
'/*                ITypeComp                                            */
'/*---------------------------------------------------------------------*/

'typedef /* [unique] */  __RPC_unique_pointer ITypeComp *LPTYPECOMP;


'/*---------------------------------------------------------------------*/
'/*             ICreateTypeLib                                          */
'/*---------------------------------------------------------------------*/

'typedef ICreateTypeLib * LPCREATETYPELIB;

'typedef ICreateTypeInfo * LPCREATETYPEINFO;

'/*---------------------------------------------------------------------*/
'/*             TypeInfo API                                            */
'/*---------------------------------------------------------------------*/

'/* compute a 16bit hash value for the given name
' */
'#if (defined (_WIN32) || defined (_WIN64))
DECLARE FUNCTION LHashValOfNameSysA IMPORT "OLEAUT32.DLL" ALIAS "LHashValOfNameSysA" ( _
   BYVAL syskind AS LONG _                              ' __in SYSKIND syskind
 , BYVAL lcid AS DWORD _                                ' __in LCID lcid
 , BYREF szName AS ASCIIZ _                             ' __in LPCSTR szName
 ) AS DWORD                                             ' ULONG
'#endif

DECLARE FUNCTION LHashValOfNameSys IMPORT "OLEAUT32.DLL" ALIAS "LHashValOfNameSys" ( _
   BYVAL syskind AS LONG _                              ' __in SYSKIND syskind
 , BYVAL lcid AS DWORD _                                ' __in LCID lcid
 , BYREF szName AS WSTRINGZ _                           ' __in const OLECHAR * szName
 ) AS DWORD                                             ' ULONG

'#define LHashValOfName(lcid, szName) \
'            LHashValOfNameSys(SYS_WIN32, lcid, szName)

FUNCTION LHashValOfName (BYVAL lcid AS DWORD, BYREF szName AS WSTRINGZ) AS DWORD
   FUNCTION = LHashValOfNameSys(%SYS_WIN32, lcid, szName)
END FUNCTION

'#define WHashValOfLHashVal(lhashval) \
'            ((USHORT) (0x0000ffff & (lhashval)))

FUNCTION WHashValOfLHashVal (BYVAL lhashval AS DWORD) AS DWORD
   FUNCTION = (&H0000ffff AND lhashval)
END FUNCTION

'#define IsHashValCompatible(lhashval1, lhashval2) \
'            ((BOOL) ((0x00ff0000 & (lhashval1)) == (0x00ff0000 & (lhashval2))))

FUNCTION IsHashValCompatible (BYVAL lhashval1 AS DWORD, BYVAL lhashval2 AS DWORD) AS LONG
   FUNCTION = ((&H00ff0000 AND lhashval1) = (&H00ff0000 AND lhashval2))
END FUNCTION

'/* load the typelib from the file with the given filename
' */
DECLARE FUNCTION LoadTypeLib IMPORT "OLEAUT32.DLL" ALIAS "LoadTypeLib" ( _
   BYREF szFile AS WSTRINGZ _                           ' __in  const OLECHAR FAR* szFile
 , BYREF pptlib AS ITypeLib _                           ' __out ITypeLib FAR* FAR* pptlib
 ) AS LONG                                              ' HRESULT

'/* Control how a type library is registered
' */
' REGKIND enum
%REGKIND_DEFAULT  = 0   ' Use default register behavior.
%REGKIND_REGISTER = 1   ' Register this type library.
%REGKIND_NONE     = 2   ' Do not register this type library.

'// Constants for specifying format in which TLB should be loaded
'// (the default format is 32-bit on WIN32 and 64-bit on WIN64)
%LOAD_TLB_AS_32BIT      = &H20
%LOAD_TLB_AS_64BIT      = &H40
%MASK_TO_RESET_TLB_BITS =  NOT (%LOAD_TLB_AS_32BIT OR %LOAD_TLB_AS_64BIT)

DECLARE FUNCTION LoadTypeLibEx IMPORT "OLEAUT32.DLL" ALIAS "LoadTypeLibEx" ( _
   BYREF szFile AS WSTRINGZ _                           ' __in  LPCOLESTR szFile
 , BYVAL regkind AS LONG _                              ' __in  REGKIND regkind
 , BYREF pptlib AS ITypeLib _                           ' __out ITypeLib** pptlib
 ) AS LONG                                              ' HRESULT

'/* load registered typelib
' */
DECLARE FUNCTION LoadRegTypeLib IMPORT "OLEAUT32.DLL" ALIAS "LoadRegTypeLib" ( _
   BYREF rguid AS GUID _                                ' __in  REFGUID rguid
 , BYVAL wVerMajor AS WORD _                            ' __in  unsigned short wVerMajor
 , BYVAL wVerMinor AS WORD _                            ' __in  unsigned short wVerMinor
 , BYVAL lcid AS DWORD _                                ' __in  LCID lcid
 , BYREF pptlib AS ITypeLib _                           ' __out ITypeLib FAR* FAR* pptlib
 ) AS LONG                                              ' HRESULT

'/* get path to registered typelib
' */
DECLARE FUNCTION QueryPathOfRegTypeLib IMPORT "OLEAUT32.DLL" ALIAS "QueryPathOfRegTypeLib" ( _
   BYREF guid AS GUID _                                 ' __in  REFGUID guid
 , BYVAL wVerMajor AS WORD _                            ' __in  unsigned short wVerMajor
 , BYVAL wVerMinor AS WORD _                            ' __in  unsigned short wVerMinor
 , BYVAL lcid AS DWORD _                                ' __in  LCID lcid
 , BYREF lpbstrPathName AS WSTRING _                    ' __out LPBSTR lpbstrPathName
 ) AS LONG                                              ' HRESULT

'/* add typelib to registry
' */
DECLARE FUNCTION RegisterTypeLib IMPORT "OLEAUT32.DLL" ALIAS "RegisterTypeLib" ( _
   BYVAL ptlib AS ITypeLib _                            ' __in ITypeLib FAR* ptlib
 , BYREF szFullPath AS WSTRINGZ _                       ' __in OLECHAR FAR* szFullPath
 , BYREF szHelpDir AS WSTRINGZ _                        ' __in OLECHAR FAR* szHelpDir
 ) AS LONG                                              ' HRESULT

'/* remove typelib from registry
' */

DECLARE FUNCTION UnRegisterTypeLib IMPORT "OLEAUT32.DLL" ALIAS "UnRegisterTypeLib" ( _
   BYREF libID AS GUID _                                ' __in REFGUID libID
 , BYVAL wVerMajor AS WORD _                            ' __in unsigned short wVerMajor
 , BYVAL wVerMinor AS WORD _                            ' __in unsigned short wVerMinor
 , BYVAL lcid AS LONG _                                 ' __in LCID lcid
 , BYVAL syskind AS LONG _                              ' __in SYSKIND syskind
 ) AS LONG                                              ' HRESULT

'/* Registers a type library for use by the calling user.
'*/
DECLARE FUNCTION RegisterTypeLibForUser IMPORT "OLEAUT32.DLL" ALIAS "RegisterTypeLibForUser" ( _
   BYREF libID AS GUID _                                ' __in REFGUID libID
 , BYVAL wVerMajor AS WORD _                            ' __in unsigned short wVerMajor
 , BYVAL wVerMinor AS WORD _                            ' __in unsigned short wVerMinor
 , BYVAL lcid AS LONG _                                 ' __in LCID lcid
 , BYVAL syskind AS LONG _                              ' __in SYSKIND syskind
 ) AS LONG                                              ' HRESULT


'/* Removes type library information that was registered by using RegisterTypeLibForUser.
'*/
DECLARE FUNCTION UnRegisterTypeLibForUser IMPORT "OLEAUT32.DLL" ALIAS "UnRegisterTypeLibForUser" ( _
   BYREF libID AS GUID _                                ' __in REFGUID libID
 , BYVAL wVerMajor AS WORD _                            ' __in unsigned short wVerMajor
 , BYVAL wVerMinor AS WORD _                            ' __in unsigned short wVerMinor
 , BYVAL lcid AS LONG _                                 ' __in LCID lcid
 , BYVAL syskind AS LONG _                              ' __in SYSKIND syskind
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION CreateTypeLib IMPORT "OLEAUT32.DLL" ALIAS "CreateTypeLib" ( _
   BYVAL syskind AS LONG _                              ' __in  SYSKIND syskind
 , BYREF szFile AS WSTRINGZ _                           ' __in  const OLECHAR FAR* szFile
 , BYREF ppctlib AS ICreateTypeLib _                    ' __out ICreateTypeLib FAR* FAR* ppctlib
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION CreateTypeLib2 IMPORT "OLEAUT32.DLL" ALIAS "CreateTypeLib2" ( _
   BYVAL syskind AS LONG _                              ' __in  SYSKIND syskind
 , BYREF szFile AS WSTRINGZ _                           ' __in  LPOLESTR  szFile
 , BYREF ppctlib AS ICreateTypeLib2 _                   ' __out ICreateTypeLib2**  ppctlib
 ) AS LONG                                              ' HRESULT

'/*---------------------------------------------------------------------*/
'/*           IDispatch implementation support                          */
'/*---------------------------------------------------------------------*/

'typedef /* [unique] */  __RPC_unique_pointer IDispatch *LPDISPATCH;

' // Size = 8 bytes
TYPE PARAMDATA DWORD
   szName AS WSTRINGZ PTR   ' OLECHAR * szName;   /* parameter name */
   vt     AS WORD           ' VARTYPE vt;         /* parameter type */
END TYPE

' // Size = 28 bytes
TYPE METHODDATA WORD
   szName   AS WSTRINGZ PTR    ' OLECHAR * szName;   /* method name */
   ppdata   AS PARAMDATA PTR   ' PARAMDATA * ppdata; /* pointer to an array of PARAMDATAs */
   dispid   AS LONG            ' DISPID dispid;      /* method ID */
   iMeth    AS DWORD           ' UINT iMeth;         /* method index */
   cc       AS DWORD           ' CALLCONV cc;        /* calling convention */
   cArgs    AS DWORD           ' UINT cArgs;         /* count of arguments */
   wFlags   AS WORD            ' WORD wFlags;        /* same wFlags as on IDispatch::Invoke() */
   vtReturn AS WORD            ' VARTYPE vtReturn;
END TYPE

' // Size = 8 bytes
TYPE INTERFACEDATA DWORD
   pmethdata AS METHODDATA PTR   ' METHODDATA * pmethdata;  /* pointer to an array of METHODDATAs */
   cMembers  AS LONG             ' UINT cMembers;      /* count of members */
END TYPE

'/* Locate the parameter indicated by the given position, and
' * return it coerced to the given target VARTYPE (vtTarg).
' */
DECLARE FUNCTION DispGetParam IMPORT "OLEAUT32.DLL" ALIAS "DispGetParam" ( _
   BYREF pdispparams AS DISPPARAMS _                    ' __in  DISPPARAMS FAR* pdispparams
 , BYVAL position AS DWORD _                            ' __in  unsigned int position
 , BYVAL vtTarg AS WORD _                               ' __in  VARTYPE vtTarg
 , BYREF pvarResult AS ANY _                            ' __out VARIANT FAR* pvarResult
 , BYREF puArgErr AS DWORD _                            ' __out unsigned int FAR* puArgErr
 ) AS LONG                                              ' HRESULT

'/* Automatic TypeInfo driven implementation of IDispatch::GetIDsOfNames()
' */
DECLARE FUNCTION DispGetIDsOfNames IMPORT "OLEAUT32.DLL" ALIAS "DispGetIDsOfNames" ( _
   BYVAL ptinfo AS ITypeInfo _                          ' __in  ITypeInfo* ptinfo
 , BYREF rgszNames AS ANY _                             ' __in  OLECHAR FAR* FAR* rgszNames [array]
 , BYVAL cNames AS DWORD _                              ' __in  unsigned int cNames
 , BYREF rgdispid AS LONG _                             ' __out DISPID FAR* rgdispid [array]
 ) AS LONG                                              ' HRESULT

'/* Automatic TypeInfo driven implementation of IDispatch::Invoke()
' */
DECLARE FUNCTION DispInvoke IMPORT "OLEAUT32.DLL" ALIAS "DispInvoke" ( _
   BYVAL this AS IDispatch _                            ' __in  void FAR*  _this
 , BYVAL ptinfo AS ITypeInfo _                          ' __in  ITypeInfo FAR* ptinfo
 , BYVAL dispidMember AS LONG _                         ' __in  DISPID dispidMember
 , BYVAL wFlags AS WORD _                               ' __in  unsigned short wFlags
 , BYREF pparams AS DISPPARAMS _                        ' __in  DISPPARAMS FAR* pparams
 , BYREF pvarResult AS ANY _                            ' __out VARIANT FAR* pvarResult
 , BYREF pexcepinfo AS EXCEPINFO _                      ' __out EXCEPINFO pexcepinfo
 , BYREF puArgErr AS DWORD _                            ' __out unsigned int FAR* puArgErr
 ) AS LONG                                              ' HRESULT

'/* Construct a TypeInfo from an interface data description
' */
DECLARE FUNCTION CreateDispTypeInfo IMPORT "OLEAUT32.DLL" ALIAS "CreateDispTypeInfo" ( _
   BYREF pidata AS INTERFACEDATA _                      ' __in  INTERFACEDATA pidata
 , BYVAL lcid AS DWORD _                                ' __in  LCID lcid
 , BYREF pptinfo AS ITypeInfo _                         ' __out ITypeInfo FAR* FAR* pptinfo
 ) AS LONG                                              ' HRESULT

'/* Create an instance of the standard TypeInfo driven IDispatch
' * implementation.
' */
DECLARE FUNCTION CreateStdDispatch IMPORT "OLEAUT32.DLL" ALIAS "CreateStdDispatch" ( _
   BYVAL punkOuter AS IUnknown _                        ' __in  IUnknown FAR* punkOuter
 , BYVAL pvThis AS IDispatch _                          ' __in  void FAR*  pvThis
 , BYVAL ptinfo AS ITypeInfo _                          ' __in  ITypeInfo FAR* ptinfo
 , BYREF ppunkStdDisp AS IUnknown _                     ' __out IUnknown FAR* FAR* ppunkStdDisp
 ) AS LONG                                              ' HRESULT

'/* Low-level helper for IDispatch::Invoke() provides machine independence
' * for customized Invoke().
' */
DECLARE FUNCTION DispCallFunc IMPORT "OLEAUT32.DLL" ALIAS "DispCallFunc" ( _
   BYVAL pvInstance AS IDispatch _                      ' __in  void * pvInstance
 , BYVAL oVft AS DWORD _                                ' __in  ULONG_PTR oVft
 , BYVAL cc AS DWORD _                                  ' __in  CALLCONV cc
 , BYVAL vtReturn AS WORD _                             ' __in  VARTYPE vtReturn
 , BYVAL cActuals AS DWORD _                            ' __in  UINT cActuals
 , BYREF prgvt AS WORD _                                ' __in  VARTYPE * prgvt [array]
 , BYREF prgpvarg AS ANY _                              ' __in  VARIANTARG ** prgpvarg [array]
 , BYREF pvargResult AS ANY _                           ' __out VARIANT * pvargResult
 ) AS LONG                                              ' HRESULT

'/*---------------------------------------------------------------------*/
'/*            Active Object Registration API                           */
'/*---------------------------------------------------------------------*/

'/* flags for RegisterActiveObject */
%ACTIVEOBJECT_STRONG = &H0???
%ACTIVEOBJECT_WEAK   = &H1???

DECLARE FUNCTION RegisterActiveObject IMPORT "OLEAUT32.DLL" ALIAS "RegisterActiveObject" ( _
   BYVAL punk AS IUnknown _                             ' __in  IUnknown FAR* punk
 , BYREF rclsid AS GUID _                               ' __in  REFCLSID rclsid
 , BYVAL dwFlags AS DWORD _                             ' __in  DWORD dwFlags
 , BYREF pdwRegister AS DWORD _                         ' __out unsigned long FAR* pdwRegister
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION RevokeactiveObject IMPORT "OLEAUT32.DLL" ALIAS "RevokeactiveObject" ( _
   BYVAL dwRegister AS DWORD _                          ' __in unsigned long dwRegister
 , BYVAL pvReserved AS DWORD _                          ' __in void FAR* pvReserved
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION GetActiveObject IMPORT "OLEAUT32.DLL" ALIAS "GetActiveObject" ( _
   BYREF rclsid AS GUID _                               ' __in  REFCLSID rclsid
 , BYVAL pvReserved AS DWORD _                          ' __in  void FAR* pvReserved
 , BYREF ppunk AS IUnknown _                            ' __out IUnknown FAR* FAR*  ppunk
 ) AS LONG                                              ' HRESULT

'/*---------------------------------------------------------------------*/
'/*                           ErrorInfo API                             */
'/*---------------------------------------------------------------------*/

DECLARE FUNCTION SetErrorInfo IMPORT "OLEAUT32.DLL" ALIAS "SetErrorInfo" ( _
   BYVAL dwReserved AS DWORD _                          ' __in DWORD dwReserved
 , BYVAL perrinfo AS IErrorInfo _                       ' __in_opt IErrorInfo *perrinfo
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION GetErrorInfo IMPORT "OLEAUT32.DLL" ALIAS "GetErrorInfo" ( _
   BYVAL dwReserved AS DWORD _                          ' __in  DWORD dwReserved
 , BYREF IErrorInfo _                                   ' __out IErrorInfo **pperrinfo
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION CreateErrorInfo IMPORT "OLEAUT32.DLL" ALIAS "CreateErrorInfo" ( _
   BYREF pperrinfo AS ICreateErrorInfo _                ' __out ICreateErrorInfo **pperrinfo
 ) AS LONG                                              ' HRESULT

' ========================================================================================
' The ERRORINFO structure returns most of the basic information associated with an error.
' ========================================================================================
' // Size = 44 bytes
TYPE ERRORINFO DWORD
   hrError AS DWORD       ' // The code returned by the method.
   dwMinor AS DWORD       ' // A provider-specific error code.
   clsid   AS GUID        ' // The class ID of the object that returned the error.
   iid     AS GUID        ' // The interface ID of the interface that generated the error.
   dispid  AS LONG        ' // Optional and provider-specific. Could be used, for example, to indicate the method that returned the error.
END TYPE

'/*---------------------------------------------------------------------*/
'/*           User Defined Data types support                           */
'/*---------------------------------------------------------------------*/

DECLARE FUNCTION GetRecordInfoFromTypeInfo IMPORT "OLEAUT32.DLL" ALIAS "GetRecordInfoFromTypeInfo" ( _
   BYVAL pTypeInfo AS ITypeInfo _                       ' __in  ITypeInfo  pTypeInfo
 , BYREF ppRecInfo AS IRecordInfo _                     ' __out IRecordInfo** ppRecInfo
 ) AS LONG                                              ' HRESULT

DECLARE FUNCTION GetRecordInfoFromGuids IMPORT "OLEAUT32.DLL" ALIAS "GetRecordInfoFromGuids" ( _
   BYREF rGuidTypeLib AS GUID _                         ' __in  REFGUID rGuidTypeLib
 , BYVAL uVerMajor AS DWORD _                           ' __in  ULONG uVerMajor
 , BYVAL uVerMinor AS DWORD _                           ' __in  ULONG uVerMinor
 , BYVAL lcid AS DWORD _                                ' __in  LCID lcid
 , BYREF rGuidTypeInfo AS GUID _                        ' __in  REFGUID rGuidTypeInfo
 , BYREF ppRecInfo AS IRecordInfo _                     ' __out IRecordInfo** ppRecInfo
 ) AS LONG                                              ' HRESULT

'/*---------------------------------------------------------------------*/
'/*                           MISC API                                  */
'/*---------------------------------------------------------------------*/

DECLARE FUNCTION OaBuildVersion IMPORT "OLEAUT32.DLL" ALIAS "OaBuildVersion" ( _
 ) AS DWORD                                             ' ULONG

DECLARE FUNCTION ClearCustData IMPORT "OLEAUT32.DLL" ALIAS "ClearCustData" ( _
   BYREF pCustData AS CUSTDATA _                        ' __in LPCUSTDATA pCustData
 ) AS DWORD                                             ' ULONG

'#if (NTDDI_VERSION >= NTDDI_VISTASP1)
DECLARE SUB OaEnablePerUserTLibRegistration IMPORT "OLEAUT32.DLL" ALIAS "OaEnablePerUserTLibRegistration" ()
'#endif

'// Declare variant access functions.

'#if __STDC__ || defined(NONAMELESSUNION)
'#define V_UNION(X, Y)   ((X)->n1.n2.n3.Y)
'#define V_VT(X)         ((X)->n1.n2.vt)
'#define V_RECORDINFO(X) ((X)->n1.n2.n3.brecVal.pRecInfo)
'#define V_RECORD(X)     ((X)->n1.n2.n3.brecVal.pvRecord)
'#else
'#define V_UNION(X, Y)   ((X)->Y)
'#define V_VT(X)         ((X)->vt)
'#define V_RECORDINFO(X) ((X)->pRecInfo)
'#define V_RECORD(X)     ((X)->pvRecord)
'#endif

'/* Variant access macros
' */
'#define V_ISBYREF(X)     (V_VT(X)&VT_BYREF)
'#define V_ISARRAY(X)     (V_VT(X)&VT_ARRAY)
'#define V_ISVECTOR(X)    (V_VT(X)&VT_VECTOR)
'#define V_NONE(X)        V_I2(X)

'#define V_UI1(X)         V_UNION(X, bVal)
'#define V_UI1REF(X)      V_UNION(X, pbVal)
'#define V_I2(X)          V_UNION(X, iVal)
'#define V_I2REF(X)       V_UNION(X, piVal)
'#define V_I4(X)          V_UNION(X, lVal)
'#define V_I4REF(X)       V_UNION(X, plVal)
'#define V_I8(X)          V_UNION(X, llVal)
'#define V_I8REF(X)       V_UNION(X, pllVal)
'#define V_R4(X)          V_UNION(X, fltVal)
'#define V_R4REF(X)       V_UNION(X, pfltVal)
'#define V_R8(X)          V_UNION(X, dblVal)
'#define V_R8REF(X)       V_UNION(X, pdblVal)
'#define V_I1(X)          V_UNION(X, cVal)
'#define V_I1REF(X)       V_UNION(X, pcVal)
'#define V_UI2(X)         V_UNION(X, uiVal)
'#define V_UI2REF(X)      V_UNION(X, puiVal)
'#define V_UI4(X)         V_UNION(X, ulVal)
'#define V_UI4REF(X)      V_UNION(X, pulVal)
'#define V_UI8(X)         V_UNION(X, ullVal)
'#define V_UI8REF(X)      V_UNION(X, pullVal)
'#define V_INT(X)         V_UNION(X, intVal)
'#define V_INTREF(X)      V_UNION(X, pintVal)
'#define V_UINT(X)        V_UNION(X, uintVal)
'#define V_UINTREF(X)     V_UNION(X, puintVal)

'#ifdef _WIN64
'#define V_INT_PTR(X)        V_UNION(X, llVal)
'#define V_UINT_PTR(X)       V_UNION(X, ullVal)
'#define V_INT_PTRREF(X)     V_UNION(X, pllVal)
'#define V_UINT_PTRREF(X)    V_UNION(X, pullVal)
'#else
'#define V_INT_PTR(X)        V_UNION(X, lVal)
'#define V_UINT_PTR(X)       V_UNION(X, ulVal)
'#define V_INT_PTRREF(X)     V_UNION(X, plVal)
'#define V_UINT_PTRREF(X)    V_UNION(X, pulVal)
'#endif

'#define V_CY(X)          V_UNION(X, cyVal)
'#define V_CYREF(X)       V_UNION(X, pcyVal)
'#define V_DATE(X)        V_UNION(X, date)
'#define V_DATEREF(X)     V_UNION(X, pdate)
'#define V_BSTR(X)        V_UNION(X, bstrVal)
'#define V_BSTRREF(X)     V_UNION(X, pbstrVal)
'#define V_DISPATCH(X)    V_UNION(X, pdispVal)
'#define V_DISPATCHREF(X) V_UNION(X, ppdispVal)
'#define V_ERROR(X)       V_UNION(X, scode)
'#define V_ERRORREF(X)    V_UNION(X, pscode)
'#define V_BOOL(X)        V_UNION(X, boolVal)
'#define V_BOOLREF(X)     V_UNION(X, pboolVal)
'#define V_UNKNOWN(X)     V_UNION(X, punkVal)
'#define V_UNKNOWNREF(X)  V_UNION(X, ppunkVal)
'#define V_VARIANTREF(X)  V_UNION(X, pvarVal)
'#define V_ARRAY(X)       V_UNION(X, parray)
'#define V_ARRAYREF(X)    V_UNION(X, pparray)
'#define V_BYREF(X)       V_UNION(X, byref)

'#define V_DECIMAL(X)     V_UNION(X, decVal)
'#define V_DECIMALREF(X)  V_UNION(X, pdecVal)
