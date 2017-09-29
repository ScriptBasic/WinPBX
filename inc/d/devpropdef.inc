' ########################################################################################
' Microsoft Windows
' File: devpropdef.inc
' Contents: Property types and keys for the Plug and Play Device Property API.
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%DEVPROPDEF_INC = 2

'//
'// Type definition for property data types.  Valid DEVPROPTYPE values are
'// constructed from base DEVPROP_TYPE_ values, which may be modified by a
'// logical OR with DEVPROP_TYPEMOD_ values, as appropriate.
'//
'typedef ULONG DEVPROPTYPE, *PDEVPROPTYPE;

'//
'// Property type modifiers.  Used to modify base DEVPROP_TYPE_ values, as
'// appropriate.  Not valid as standalone DEVPROPTYPE values.
'//
%DEVPROP_TYPEMOD_ARRAY                   = &H00001000???  ' // array of fixed-sized data elements
%DEVPROP_TYPEMOD_LIST                    = &H00002000???  ' // list of variable-sized data elements

' //
' // Property data types.
' //
%DEVPROP_TYPE_EMPTY                      = &H00000000???  ' // nothing, no property data
%DEVPROP_TYPE_NULL                       = &H00000001???  ' // null property data
%DEVPROP_TYPE_SBYTE                      = &H00000002???  ' // 8-bit signed int (SBYTE)
%DEVPROP_TYPE_BYTE                       = &H00000003???  ' // 8-bit unsigned int (BYTE)
%DEVPROP_TYPE_INT16                      = &H00000004???  ' // 16-bit signed int (SHORT)
%DEVPROP_TYPE_UINT16                     = &H00000005???  ' // 16-bit unsigned int (USHORT)
%DEVPROP_TYPE_INT32                      = &H00000006???  ' // 32-bit signed int (LONG)
%DEVPROP_TYPE_UINT32                     = &H00000007???  ' // 32-bit unsigned int (ULONG)
%DEVPROP_TYPE_INT64                      = &H00000008???  ' // 64-bit signed int (LONG64)
%DEVPROP_TYPE_UINT64                     = &H00000009???  ' // 64-bit unsigned int (ULONG64)
%DEVPROP_TYPE_FLOAT                      = &H0000000A???  ' // 32-bit floating-point (FLOAT)
%DEVPROP_TYPE_DOUBLE                     = &H0000000B???  ' // 64-bit floating-point (DOUBLE)
%DEVPROP_TYPE_DECIMAL                    = &H0000000C???  ' // 128-bit data (DECIMAL)
%DEVPROP_TYPE_GUID                       = &H0000000D???  ' // 128-bit unique identifier (GUID)
%DEVPROP_TYPE_CURRENCY                   = &H0000000E???  ' // 64 bit signed int currency value (CURRENCY)
%DEVPROP_TYPE_DATE                       = &H0000000F???  ' // date (DATE)
%DEVPROP_TYPE_FILETIME                   = &H00000010???  ' // file time (FILETIME)
%DEVPROP_TYPE_BOOLEAN                    = &H00000011???  ' // 8-bit boolean (DEVPROP_BOOLEAN)
%DEVPROP_TYPE_STRING                     = &H00000012???  ' // null-terminated string
%DEVPROP_TYPE_STRING_LIST                = (%DEVPROP_TYPE_STRING OR %DEVPROP_TYPEMOD_LIST) ' // multi-sz string list
%DEVPROP_TYPE_SECURITY_DESCRIPTOR        = &H00000013???  ' // self-relative binary SECURITY_DESCRIPTOR
%DEVPROP_TYPE_SECURITY_DESCRIPTOR_STRING = &H00000014???  ' // security descriptor string (SDDL format)
%DEVPROP_TYPE_DEVPROPKEY                 = &H00000015???  ' // device property key (DEVPROPKEY)
%DEVPROP_TYPE_DEVPROPTYPE                = &H00000016???  ' // device property type (DEVPROPTYPE)
%DEVPROP_TYPE_BINARY                     = (%DEVPROP_TYPE_BYTE OR %DEVPROP_TYPEMOD_ARRAY)  ' // custom binary data
%DEVPROP_TYPE_ERROR                      = &H00000017???  ' // 32-bit Win32 system error code
%DEVPROP_TYPE_NTSTATUS                   = &H00000018???  ' // 32-bit NTSTATUS code
%DEVPROP_TYPE_STRING_INDIRECT            = &H00000019???  ' // string resource (@[path\]<dllname>,-<strId>)

' //
' // Max base DEVPROP_TYPE_ and DEVPROP_TYPEMOD_ values.
' //
%MAX_DEVPROP_TYPE                        = &H00000019???  ' // max valid DEVPROP_TYPE_ value
%MAX_DEVPROP_TYPEMOD                     = &H00002000???  ' // max valid DEVPROP_TYPEMOD_ value

' //
' // Bitmasks for extracting DEVPROP_TYPE_ and DEVPROP_TYPEMOD_ values.
' //
%DEVPROP_MASK_TYPE                       = &H00000FFF???  ' // range for base DEVPROP_TYPE_ values
%DEVPROP_MASK_TYPEMOD                    = &H0000F000???  ' // mask for DEVPROP_TYPEMOD_ type modifiers


'//
'// Property type specific data types.
'//

'// 8-bit boolean type definition for DEVPROP_TYPE_BOOLEAN (True=-1, False=0)
'typedef CHAR DEVPROP_BOOLEAN, *PDEVPROP_BOOLEAN;
#IF %DEF(%USEPBDECL)
%DEVPROP_TRUE  = &H00FF  ' ((DEVPROP_BOOLEAN)-1)   ' // This is clearly wrong, but...
#ELSE
%DEVPROP_TRUE  = -1 ' ((DEVPROP_BOOLEAN)-1)
#ENDIF
%DEVPROP_FALSE = 0  ' ((DEVPROP_BOOLEAN) 0)


'//
'// DEVPROPKEY structure
'//

'typedef GUID  DEVPROPGUID, *PDEVPROPGUID;
'typedef ULONG DEVPROPID,   *PDEVPROPID;

#IF NOT %DEF(%DEVPROPKEY_DEFINED)
%DEVPROPKEY_DEFINED = 1
' // Size = 20 bytes
TYPE DEVPROPKEY DWORD
   fmtid AS GUID    ' DEVPROPGUID
   pid   AS DWORD   ' DEVPROPID
END TYPE
#ENDIF   ' // DEVPROPKEY_DEFINED

'//
'// All valid DEVPROPKEY definitions must use a PROPID that is equal to or greater
'// than DEVPROPID_FIRST_USABLE.
'//
%DEVPROPID_FIRST_USABLE = 2

'#ifdef DEFINE_DEVPROPKEY
'#undef DEFINE_DEVPROPKEY
'#endif
'#ifdef INITGUID
'#define DEFINE_DEVPROPKEY(name, l, w1, w2, b1, b2, b3, b4, b5, b6, b7, b8, pid) EXTERN_C const DEVPROPKEY DECLSPEC_SELECTANY name = { { l, w1, w2, { b1, b2,  b3,  b4,  b5,  b6,  b7,  b8 } }, pid }
'#else
'#define DEFINE_DEVPROPKEY(name, l, w1, w2, b1, b2, b3, b4, b5, b6, b7, b8, pid) EXTERN_C const DEVPROPKEY name
'#endif // INITGUID

#IF NOT %DEF(%DEFINE_DEVPROPKEY)
%DEFINE_DEVPROPKEY = 1
MACRO DEFINE_DEVPROPKEY(propName, l, w1, w2, b1, b2, b3, b4, b5, b6, b7, b8, pid)
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


'#ifndef IsEqualDevPropKey
'#ifdef __cplusplus
'#define IsEqualDevPropKey(a, b)   (((a).pid == (b).pid) && IsEqualIID((a).fmtid, (b).fmtid) )
'#else // !__cplusplus
'#define IsEqualDevPropKey(a, b)   (((a).pid == (b).pid) && IsEqualIID(&(a).fmtid, &(b).fmtid) )
'#endif // __cplusplus
'#endif // !IsEqualDevPropKey

#IF NOT %DEF(%IsEqualDevPropKey)
%IsEqualDevPropKey = 1
MACRO IsEqualDevPropKey(a, b) = (a.pid = b.pid) AND (a.fmtid = b.fmtid)
#ENDIF  ' // IsEqualDevPropKey
