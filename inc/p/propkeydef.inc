' ########################################################################################
' Microsoft Windows
' File: propkeydef.inc
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%PROPKEYDEF_INC = 1

'#ifndef PID_FIRST_USABLE
'#define PID_FIRST_USABLE 2
'#endif

#IF NOT %DEF(%PID_FIRST_USABLE)
%PID_FIRST_USABLE = 2
#ENDIF

'#ifndef REFPROPERTYKEY
'#ifdef __cplusplus
'#define REFPROPERTYKEY const PROPERTYKEY &
'#else // !__cplusplus
'#define REFPROPERTYKEY const PROPERTYKEY * __MIDL_CONST
'#endif // __cplusplus
'#endif //REFPROPERTYKEY

'#ifdef DEFINE_PROPERTYKEY
'#undef DEFINE_PROPERTYKEY
'#endif

'#ifdef INITGUID
'#define DEFINE_PROPERTYKEY(name, l, w1, w2, b1, b2, b3, b4, b5, b6, b7, b8, pid) EXTERN_C const PROPERTYKEY DECLSPEC_SELECTANY name = { { l, w1, w2, { b1, b2,  b3,  b4,  b5,  b6,  b7,  b8 } }, pid }
'#else
'#define DEFINE_PROPERTYKEY(name, l, w1, w2, b1, b2, b3, b4, b5, b6, b7, b8, pid) EXTERN_C const PROPERTYKEY name
'#endif // INITGUID

#IF NOT %DEF(%DEFINE_PROPERTYKEY)
%DEFINE_PROPERTYKEY = 1
MACRO DEFINE_PROPERTYKEY(propName, l, w1, w2, b1, b2, b3, b4, b5, b6, b7, b8, pid)
   propName.Data1    = l
   propName.Data2    = w1
   propName.Data3    = w2
   propName.Data4(0) = b1
   propName.Data4(1) = b2
   propName.Data4(2) = b3
   propName.Data4(3) = b4
   propName.Data4(4) = b5
   propName.Data4(5) = b6
   propName.Data4(6) = b7
   propName.Data4(7) = b8
   propName.pid      = pid
END MACRO
#ENDIF

'#ifndef IsEqualPropertyKey
'#define IsEqualPropertyKey(a, b)   (((a).pid == (b).pid) && IsEqualIID((a).fmtid, (b).fmtid) )
'#endif  // IsEqualPropertyKey

#IF NOT %DEF(%IsEqualPropertyKey)
%IsEqualPropertyKey = 1
'#define IsEqualPropertyKey(a, b)   (((a).pid == (b).pid) && IsEqualIID((a).fmtid, (b).fmtid) )
MACRO IsEqualPropertyKey(a, b) = (a.pid = b.pid) AND (a.fmtid = b.fmtid)
#ENDIF  ' // IsEqualPropertyKey

'#ifndef _PROPERTYKEY_EQUALITY_OPERATORS_
'#define _PROPERTYKEY_EQUALITY_OPERATORS_
'#ifdef __cplusplus
'extern "C++"
'{
'__inline int operator == (REFPROPERTYKEY pkeyOne, REFPROPERTYKEY pkeyOther) { return IsEqualPropertyKey(pkeyOne, pkeyOther); }
'__inline int operator != (REFPROPERTYKEY pkeyOne, REFPROPERTYKEY pkeyOther) { return !(pkeyOne == pkeyOther); }
'}
'#endif // __cplusplus
