' ########################################################################################
' Microsoft Windows
' File: guiddef.inc
' Contents: GUID definition
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%GUIDDEF_INC = 1

'#ifndef GUID_DEFINED
'#define GUID_DEFINED
'#if defined(__midl)
'typedef struct {
'    unsigned long  Data1;
'    unsigned short Data2;
'    unsigned short Data3;
'    byte           Data4[ 8 ];
'} GUID;
'#else
'typedef struct _GUID {
'    unsigned long  Data1;
'    unsigned short Data2;
'    unsigned short Data3;
'    unsigned char  Data4[ 8 ];
'} GUID;
'#endif
'#endif

#IF NOT %DEF(%GUID_DEFINED)
' // Size = 16 bytes
TYPE GUIDAPI BYTE
  Data1 AS DWORD
  Data2 AS WORD
  Data3 AS WORD
  Data4 AS STRING * 8
END TYPE
%GUID_DEFINED = 1
#ENDIF

'#ifdef INITGUID
'#define DEFINE_GUID(name, l, w1, w2, b1, b2, b3, b4, b5, b6, b7, b8) \
'        EXTERN_C const GUID DECLSPEC_SELECTANY name \
'                = { l, w1, w2, { b1, b2,  b3,  b4,  b5,  b6,  b7,  b8 } }
'#else
'#define DEFINE_GUID(name, l, w1, w2, b1, b2, b3, b4, b5, b6, b7, b8) \
'    EXTERN_C const GUID FAR name
'#endif // INITGUID

#IF NOT %DEF(%DEFINE_GUID) '--------------------------------------------------
%DEFINE_GUID = 1
MACRO DEFINE_GUID(guidName, l, w1, w2, b1, b2, b3, b4, b5, b6, b7, b8)
   guidName.Data1    = l
   guidName.Data2    = w1
   guidName.Data3    = w2
   guidName.Data4(0) = b1
   guidName.Data4(1) = b2
   guidName.Data4(2) = b3
   guidName.Data4(3) = b4
   guidName.Data4(4) = b5
   guidName.Data4(5) = b6
   guidName.Data4(6) = b7
   guidName.Data4(7) = b8
END MACRO

'#define DEFINE_OLEGUID(name, l, w1, w2) DEFINE_GUID(name, l, w1, w2, 0xC0,0,0,0,0,0,0,0x46)

MACRO DEFINE_OLEGUID(guidName, l, w1, w2)
   DEFINE_GUID(guidName, l, w1, w2, &HC0, 0, 0, 0, 0, 0, 0, &H46)
END MACRO
#ENDIF ' #IF NOT %DEF(%DEFINE_GUID) ------------------------------------------

'#ifndef _GUIDDEF_H_
'#define _GUIDDEF_H_

#IF NOT %DEF(%IID_DEFINED) '--------------------------------------------------

'typedef GUID IID;
'typedef IID *LPIID;
'#define IID_NULL            GUID_NULL
'#define IsEqualIID(riid1, riid2) IsEqualGUID(riid1, riid2)
'typedef GUID CLSID;
'typedef CLSID *LPCLSID;
'#define CLSID_NULL          GUID_NULL
'#define IsEqualCLSID(rclsid1, rclsid2) IsEqualGUID(rclsid1, rclsid2)
'typedef GUID FMTID;
'typedef FMTID *LPFMTID;
'#define FMTID_NULL          GUID_NULL
'#define IsEqualFMTID(rfmtid1, rfmtid2) IsEqualGUID(rfmtid1, rfmtid2)

$GUID_NULL = GUID$("{00000000-0000-0000-0000-000000000000}")

$IID_NULL = $GUID_NULL
$CLSID_NULL = $GUID_NULL
$FMTID_NULL = $GUID_NULL

#ENDIF ' #IF NOT %DEF(%IID_DEFINED) ------------------------------------------

'#if !defined (__midl)
'#if !defined (_SYS_GUID_OPERATORS_)
'#define _SYS_GUID_OPERATORS_
'#include <string.h>

'// Faster (but makes code fatter) inline version...use sparingly
'#ifdef __cplusplus
'__inline int InlineIsEqualGUID(REFGUID rguid1, REFGUID rguid2)
'{
'   return (
'      ((unsigned long *) &rguid1)[0] == ((unsigned long *) &rguid2)[0] &&
'      ((unsigned long *) &rguid1)[1] == ((unsigned long *) &rguid2)[1] &&
'      ((unsigned long *) &rguid1)[2] == ((unsigned long *) &rguid2)[2] &&
'      ((unsigned long *) &rguid1)[3] == ((unsigned long *) &rguid2)[3]);
'}

'__inline int IsEqualGUID(REFGUID rguid1, REFGUID rguid2)
'{
'    return !memcmp(&rguid1, &rguid2, sizeof(GUID));
'}

'#else   // ! __cplusplus

'#define InlineIsEqualGUID(rguid1, rguid2)  \
'        (((unsigned long *) rguid1)[0] == ((unsigned long *) rguid2)[0] &&   \
'        ((unsigned long *) rguid1)[1] == ((unsigned long *) rguid2)[1] &&    \
'        ((unsigned long *) rguid1)[2] == ((unsigned long *) rguid2)[2] &&    \
'        ((unsigned long *) rguid1)[3] == ((unsigned long *) rguid2)[3])

'#define IsEqualGUID(rguid1, rguid2) (!memcmp(rguid1, rguid2, sizeof(GUID)))

'#endif  // __cplusplus

'#ifdef __INLINE_ISEQUAL_GUID
'#undef IsEqualGUID
'#define IsEqualGUID(rguid1, rguid2) InlineIsEqualGUID(rguid1, rguid2)
'#endif

'// Same type, different name

'#define IsEqualIID(riid1, riid2) IsEqualGUID(riid1, riid2)
'#define IsEqualCLSID(rclsid1, rclsid2) IsEqualGUID(rclsid1, rclsid2)


'#if !defined _SYS_GUID_OPERATOR_EQ_ && !defined _NO_SYS_GUID_OPERATOR_EQ_
'#define _SYS_GUID_OPERATOR_EQ_
'// A couple of C++ helpers

'#ifdef __cplusplus
'__inline int operator==(REFGUID guidOne, REFGUID guidOther)
'{
'    return IsEqualGUID(guidOne,guidOther);
'}

'__inline int operator!=(REFGUID guidOne, REFGUID guidOther)
'{
'    return !(guidOne == guidOther);
'}
'#endif
'#endif  // _SYS_GUID_OPERATOR_EQ_
'#endif  // _SYS_GUID_OPERATORS_
'#endif  // __midl
