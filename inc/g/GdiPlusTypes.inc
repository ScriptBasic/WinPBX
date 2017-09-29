' ########################################################################################
' Microsoft Windows
' File: GdiPlusTypes.inc
' Contents: GDI+ Types
' Copyright (c) 2011 José Roca
' Portions Copyright (c) Microsoft Corporation.
' All Rights Reserved.
' THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
' EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
' MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
' ########################################################################################

#INCLUDE THIS ONCE
%GDIPLUSTYPES_INC = 1

'//--------------------------------------------------------------------------
'// Callback functions
'//--------------------------------------------------------------------------

'extern "C" {
'typedef BOOL (CALLBACK * ImageAbort)(VOID *);
'typedef ImageAbort DrawImageAbort;
'typedef ImageAbort GetThumbnailImageAbort;
'}

'// Callback for EnumerateMetafile methods.  The parameters are:

'//      recordType      WMF, EMF, or EMF+ record type
'//      flags           (always 0 for WMF/EMF records)
'//      dataSize        size of the record data (in bytes), or 0 if no data
'//      data            pointer to the record data, or NULL if no data
'//      callbackData    pointer to callbackData, if any

'// This method can then call Metafile::PlayRecord to play the
'// record that was just enumerated.  If this method  returns
'// FALSE, the enumeration process is aborted.  Otherwise, it continues.

'#if (GDIPVER >= 0x0110)
'// This is the main GDI+ Abort interface

'struct __declspec(novtable) GdiplusAbort
'{
'    virtual HRESULT __stdcall Abort(void) = 0;
'};
'#endif //(GDIPVER >= 0x0110)

'extern "C" {
'typedef BOOL (CALLBACK * EnumerateMetafileProc)(EmfPlusRecordType,UINT,UINT,const BYTE*,VOID*);
'}

'//--------------------------------------------------------------------------
'// Primitive data types
'//
'// NOTE:
'//  Types already defined in standard header files:
'//      INT8
'//      UINT8
'//      INT16
'//      UINT16
'//      INT32
'//      UINT32
'//      INT64
'//      UINT64
'//
'//  Avoid using the following types:
'//      LONG - use INT
'//      ULONG - use UINT
'//      DWORD - use UINT32
'//--------------------------------------------------------------------------

'typedef float REAL;

'#define REAL_MAX            FLT_MAX
'#define REAL_MIN            FLT_MIN
'#define REAL_TOLERANCE     (FLT_MIN * 100)
'#define REAL_EPSILON        1.192092896e-07F        /* FLT_EPSILON */

MACRO REAL_MAX       = 3.402823466e+38
MACRO REAL_MIN       = 1.175494351e-38
MACRO REAL_TOLERANCE = (1.175494351e-38 * 100)
MACRO REAL_EPSILON   = 1.192092896e-07

'//--------------------------------------------------------------------------
'// Status return values from GDI+ methods
'//--------------------------------------------------------------------------

' enum Status

%StatusOk                        = 0
%StatusGenericError              = 1
%StatusInvalidParameter          = 2
%StatusOutOfMemory               = 3
%StatusObjectBusy                = 4
%StatusInsufficientBuffer        = 5
%StatusNotImplemented            = 6
%StatusWin32Error                = 7
%StatusWrongState                = 8
%StatusAborted                   = 9
%StatusFileNotFound              = 10
%StatusValueOverflow             = 11
%StatusAccessDenied              = 12
%StatusUnknownImageFormat        = 13
%StatusFontFamilyNotFound        = 14
%StatusFontStyleNotFound         = 15
%StatusNotTrueTypeFont           = 16
%StatusUnsupportedGdiplusVersion = 17
%StatusGdiplusNotInitialized     = 18
%StatusPropertyNotFound          = 19
%StatusPropertyNotSupported      = 20
#IF (%GDIPVER >= &H0110)
%StatusProfileNotFound           = 21
#ENDIF   ' //(%GDIPVER >= &H0110)

' // GDI+ uses x, y, Width and Heigth instead of Left, Right, Top and Bottom.
' // Changed RECT to a union to allow to use both x, y, etc., and Left, Right, etc.
MACRO GpRect = RECT

' // GDI+ and DirectX use Width and Height as members instead of cx, cy
#IF NOT %DEF(%SIZEF_DEFINED)
%SIZEF_DEFINED = 1
' // Size = 8 bytes
TYPE SIZEFLOAT_STRUCT_I DWORD
   cx  AS SINGLE
   cy AS SINGLE
END TYPE

' // Size = 8 bytes
TYPE SIZEFLOAT_STRUCT_II DWORD
   Width  AS SINGLE
   Height AS SINGLE
END TYPE

' // Size = 8 bytes
UNION SizeF DWORD
   SIZEFLOAT_STRUCT_I
   SIZEFLOAT_STRUCT_II
END UNION
#ENDIF
MACRO GpSizeF = SizeF

#IF NOT %DEF(%GPPOINT_DEFINED)
%GPPOINT_DEFINED = 1
MACRO GpPoint = POINT
#ENDIF

#IF NOT %DEF(%POINTF_DEFINED)
%POINTF_DEFINED = 1
' // Size = 8 bytes
TYPE PointF DWORD
   x AS SINGLE
   y AS SINGLE
END TYPE
#ENDIF
MACRO GpPointF = PointF

' // GDI+ and DirectX use x, y, Width and Height as members instead of Left, Right, Top and Bottom
#IF NOT %DEF(%RECTF_DEFINED)
%RECTF_DEFINED = 1
' // Size = 16 bytes
TYPE RECTFLOAT_STRUCT_0 DWORD
   nLeft   AS SINGLE   ' SINGLE left
   nTop    AS SINGLE   ' SINGLE top
   nRight  AS SINGLE   ' SINGLE right
   nBottom AS SINGLE   ' SINGLE bottom
END TYPE

TYPE RECTFLOAT_STRUCT_I DWORD
   Left   AS SINGLE   ' SINGLE left
   Top    AS SINGLE   ' SINGLE top
   Right  AS SINGLE   ' SINGLE right
   Bottom AS SINGLE   ' SINGLE bottom
END TYPE

' // Size = 16 bytes
TYPE RECTFLOAT_STRUCT_II DWORD
   x      AS SINGLE   ' SINGLE x
   y      AS SINGLE   ' SINGLE y
   Width  AS SINGLE   ' SINGLE Width
   Height AS SINGLE   ' SINGLE Height
END TYPE

UNION RectF DWORD
   RECTFLOAT_STRUCT_0
   RECTFLOAT_STRUCT_I
   RECTFLOAT_STRUCT_II
END UNION
#ENDIF
MACRO GpRectF = RectF

#IF NOT %DEF(%CHARACTERRANGE_DEFINED)
%CHARACTERRANGE_DEFINED = 1
' // Size = 8 bytes
TYPE CharacterRange DWORD
   First  AS DWORD
   Length AS DWORD
END TYPE
#ENDIF

' // Named GpPathData instead of PathData to avoid conflicts with
' // The PathData structure defined in Winddi.h
#IF NOT %DEF(%GPPATHDATA_DEFINED)
%GPPATHDATA_DEFINED = 1
' // Size = 12 bytes
TYPE GpPathData DWORD
   Count  AS LONG
   Points AS PointF PTR
   Types  AS BYTE PTR
END TYPE
#ENDIF
