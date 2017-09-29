' ########################################################################################
' Microsoft Windows
' File: UIRibbonKeyDef.inc
' Contents: Windows Ribbon Framework Property Key Definition Macros
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%UIRIBBONKEYDEF_INC = 1

'#pragma once

#INCLUDE ONCE "propkeydef.inc"

'#ifdef __cplusplus

'extern "C++"
'{

'#ifndef TUIPROPERTYKEYDEFINED
'// A version of PROPERTYKEY whose VARTYPE can be tested at compile time.
'#include <pshpack8.h>
'template<VARTYPE T>
'struct TUIPROPERTYKEY
'{
'  GUID fmtid;
'  DWORD pid;
'  inline operator const PROPERTYKEY&() const { return reinterpret_cast<const PROPERTYKEY&>(*this); }
'  inline const PROPERTYKEY* operator&() const { return reinterpret_cast<const PROPERTYKEY*>(this); }
'};
'#include <poppack.h>

'C_ASSERT(sizeof(TUIPROPERTYKEY<VT_BOOL>) == sizeof(PROPERTYKEY));

'#define TUIPROPERTYKEYDEFINED
'#endif // TUIPROPERTYKEYDEFINED

'#define DEFINE_UIPROPERTYKEY(name, type, index) \
'    extern const TUIPROPERTYKEY<type> DECLSPEC_SELECTANY name = { { 0x00000000 + index, 0x7363, 0x696e, { 0x84, 0x41, 0x79, 0x8a, 0xcf, 0x5a, 0xeb, 0xb7 } }, type };

'} // extern "C++"

'#else // __cplusplus

'#define DEFINE_UIPROPERTYKEY(name, type, index) EXTERN_C const PROPERTYKEY DECLSPEC_SELECTANY name = { { 0x00000000 + index, 0x7363, 0x696e, { 0x84, 0x41, 0x79, 0x8a, 0xcf, 0x5a, 0xeb, 0xb7 } }, type }

'#endif // __cplusplus
