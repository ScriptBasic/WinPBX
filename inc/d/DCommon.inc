' ########################################################################################
' Microsoft Windows
' File: DCommon.inc
' Contents: Public API definitions for DWrite and D2D
' Copyright (c) 2011 Jos� Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%DCOMMON_INC = 1

'//
'//These macros are defined in the Windows 7 SDK, however to enable development using the technical preview,
'//they are included here temporarily.
'//
'#ifndef DEFINE_ENUM_FLAG_OPERATORS
'#define DEFINE_ENUM_FLAG_OPERATORS(ENUMTYPE) \
'extern "C++" { \
'inline ENUMTYPE operator | (ENUMTYPE a, ENUMTYPE b) { return ENUMTYPE(((int)a) | ((int)b)); } \
'inline ENUMTYPE &operator |= (ENUMTYPE &a, ENUMTYPE b) { return (ENUMTYPE &)(((int &)a) |= ((int)b)); } \
'inline ENUMTYPE operator & (ENUMTYPE a, ENUMTYPE b) { return ENUMTYPE(((int)a) & ((int)b)); } \
'inline ENUMTYPE &operator &= (ENUMTYPE &a, ENUMTYPE b) { return (ENUMTYPE &)(((int &)a) &= ((int)b)); } \
'inline ENUMTYPE operator ~ (ENUMTYPE a) { return ENUMTYPE(~((int)a)); } \
'inline ENUMTYPE operator ^ (ENUMTYPE a, ENUMTYPE b) { return ENUMTYPE(((int)a) ^ ((int)b)); } \
'inline ENUMTYPE &operator ^= (ENUMTYPE &a, ENUMTYPE b) { return (ENUMTYPE &)(((int &)a) ^= ((int)b)); } \
'}
'#endif

'#ifndef __field_ecount_opt
'#define __field_ecount_opt(x)
'#endif

'#ifndef __range
'#define __range(x,y)
'#endif

'#ifndef __field_ecount
'#define __field_ecount(x)
'#endif

'/// <summary>
'/// The measuring method used for text layout.
'/// </summary>
'typedef enum DWRITE_MEASURING_MODE
'{
'    /// <summary>
'    /// Text is measured using glyph ideal metrics whose values are independent to the current display resolution.
'    /// </summary>
'    DWRITE_MEASURING_MODE_NATURAL,

'    /// <summary>
'    /// Text is measured using glyph display compatible metrics whose values tuned for the current display resolution.
'    /// </summary>
'    DWRITE_MEASURING_MODE_GDI_CLASSIC,

'    /// <summary>
'    /// Text is measured using the same glyph display metrics as text measured by GDI using a font
'    /// created with CLEARTYPE_NATURAL_QUALITY.
'    /// </summary>
'    DWRITE_MEASURING_MODE_GDI_NATURAL

'} DWRITE_MEASURING_MODE;

' enum DWRITE_MEASURING_MODE
%DWRITE_MEASURING_MODE_NATURAL = 0
%DWRITE_MEASURING_MODE_GDI_CLASSIC = 1
%DWRITE_MEASURING_MODE_GDI_NATURAL = 2
